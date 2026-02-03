#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure de la liste chaînée (à adapter selon ton libft.h)
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Prototypes des fonctions bonus
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ========== Fonctions utilitaires pour les tests ==========

void print_separator(const char *title) {
    printf("\n╔════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-62s ║\n", title);
    printf("╚════════════════════════════════════════════════════════════════╝\n");
}

void print_description(const char *desc) {
    printf("📖 %s\n", desc);
    printf("───────────────────────────────────────────────────────────────\n");
}

// Fonction pour afficher le contenu d'une liste
void print_list(t_list *lst, const char *list_name) {
    printf("\n%s: ", list_name);
    if (!lst) {
        printf("(vide)\n");
        return;
    }
    
    int count = 0;
    while (lst) {
        printf("[%d:\"%s\"] -> ", count++, (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer le contenu (pour ft_lstdelone et ft_lstclear)
void del_content(void *content) {
    free(content);
}

// Fonction pour ft_lstiter (affiche chaque élément)
void print_content(void *content) {
    printf("  - Contenu: \"%s\"\n", (char *)content);
}

// Fonction pour ft_lstiter (modifie chaque élément)
void uppercase_content(void *content) {
    char *str = (char *)content;
    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            *str = *str - 32;
        str++;
    }
}

// Fonction pour ft_lstmap (duplique et met en majuscule)
void *duplicate_uppercase(void *content) {
    char *str = (char *)content;
    char *new_str = strdup(str);
    if (!new_str)
        return NULL;
    
    char *temp = new_str;
    while (*temp) {
        if (*temp >= 'a' && *temp <= 'z')
            *temp = *temp - 32;
        temp++;
    }
    return new_str;
}

// Fonction pour créer un nœud avec strdup (pour éviter les problèmes)
t_list *create_node(const char *str) {
    char *content = strdup(str);
    if (!content)
        return NULL;
    return ft_lstnew(content);
}

// ========== MAIN - TESTS DES FONCTIONS BONUS ==========

int main(void) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                ║\n");
    printf("║         TEST COMPLET DES FONCTIONS BONUS - LIBFT              ║\n");
    printf("║              (Listes Chaînées - t_list)                        ║\n");
    printf("║                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");

    printf("\n┌────────────────────────────────────────────────────────────────┐\n");
    printf("│ RAPPEL: Structure t_list                                       │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│  typedef struct s_list {                                       │\n");
    printf("│      void          *content;  // Données du nœud              │\n");
    printf("│      struct s_list *next;     // Pointeur vers le suivant     │\n");
    printf("│  } t_list;                                                     │\n");
    printf("└────────────────────────────────────────────────────────────────┘\n");

    // ==================== ft_lstnew ====================
    print_separator("TEST 1: ft_lstnew");
    print_description("Crée un nouveau nœud de liste chaînée.\n"
                     "BUT: Allouer et initialiser un maillon de liste.\n"
                     "PARAMÈTRES: content (données à stocker dans le nœud).\n"
                     "RETOUR: Nouveau nœud avec content initialisé et next = NULL.\n"
                     "⚠️  Le contenu n'est PAS copié, juste le pointeur est stocké.");
    
    printf("\nTest: Création d'un nœud avec \"Hello\"\n");
    t_list *node1 = create_node("Hello");
    if (node1) {
        printf("✓ Nœud créé avec succès\n");
        printf("  • content = \"%s\"\n", (char *)node1->content);
        printf("  • next = %s\n", node1->next ? "NON NULL ✗" : "NULL ✓");
        printf("\nVisuellement: [\"Hello\"] -> NULL\n");
    } else {
        printf("✗ Échec de la création\n");
    }

    // ==================== ft_lstadd_front ====================
    print_separator("TEST 2: ft_lstadd_front");
    print_description("Ajoute un nœud au DÉBUT de la liste.\n"
                     "BUT: Insérer un élément en tête de liste (LIFO - Last In First Out).\n"
                     "PARAMÈTRES: **lst (adresse du pointeur de tête), *new (nœud à ajouter).\n"
                     "RETOUR: Aucun (void) - modifie directement la liste.\n"
                     "FONCTIONNEMENT: new->next = *lst; *lst = new;");
    
    printf("\nConstruction progressive:\n");
    t_list *list = NULL;
    print_list(list, "  1. Liste initiale");
    
    t_list *node2 = create_node("World");
    ft_lstadd_front(&list, node2);
    print_list(list, "  2. Après ajout \"World\"");
    
    t_list *node3 = create_node("42");
    ft_lstadd_front(&list, node3);
    print_list(list, "  3. Après ajout \"42\"");
    
    t_list *node4 = create_node("School");
    ft_lstadd_front(&list, node4);
    print_list(list, "  4. Après ajout \"School\"");
    
    printf("\n💡 Remarque: Les éléments ajoutés en premier sont à la fin!\n");

    // ==================== ft_lstsize ====================
    print_separator("TEST 3: ft_lstsize");
    print_description("Compte le nombre d'éléments dans la liste.\n"
                     "BUT: Connaître la taille/longueur de la liste.\n"
                     "PARAMÈTRES: *lst (pointeur de tête).\n"
                     "RETOUR: Nombre de nœuds dans la liste (int).\n"
                     "FONCTIONNEMENT: Parcourt la liste en comptant jusqu'à NULL.");
    
    print_list(list, "Liste actuelle");
    int size = ft_lstsize(list);
    printf("\n  Taille calculée: %d (attendu: 3)\n", size);
    
    t_list *empty_list = NULL;
    int size_empty = ft_lstsize(empty_list);
    printf("  Taille liste vide: %d (attendu: 0)\n", size_empty);

    // ==================== ft_lstlast ====================
    print_separator("TEST 4: ft_lstlast");
    print_description("Retourne le dernier nœud de la liste.\n"
                     "BUT: Accéder au dernier élément (celui dont next = NULL).\n"
                     "PARAMÈTRES: *lst (pointeur de tête).\n"
                     "RETOUR: Pointeur vers le dernier nœud, ou NULL si liste vide.\n"
                     "FONCTIONNEMENT: Parcourt jusqu'à trouver un nœud avec next = NULL.");
    
    print_list(list, "Liste actuelle");
    t_list *last = ft_lstlast(list);
    if (last) {
        printf("\n  ✓ Dernier élément trouvé: \"%s\" (attendu: \"World\")\n", 
               (char *)last->content);
        printf("  Son pointeur next = %s\n", last->next ? "NON NULL ✗" : "NULL ✓");
    } else {
        printf("\n  ✗ Aucun dernier élément\n");
    }
    
    t_list *last_empty = ft_lstlast(NULL);
    printf("\n  Liste vide: dernier = %s ✓\n", last_empty ? "NON NULL" : "NULL");

    // ==================== ft_lstadd_back ====================
    print_separator("TEST 5: ft_lstadd_back");
    print_description("Ajoute un nœud à la FIN de la liste.\n"
                     "BUT: Insérer un élément en queue de liste (FIFO - First In First Out).\n"
                     "PARAMÈTRES: **lst (adresse du pointeur de tête), *new (nœud à ajouter).\n"
                     "RETOUR: Aucun (void) - modifie directement la liste.\n"
                     "FONCTIONNEMENT: Trouve le dernier nœud, puis last->next = new;");
    
    print_list(list, "Liste avant ajouts");
    
    printf("\n  Ajout de \"Paris\" à la fin:\n");
    t_list *node5 = create_node("Paris");
    ft_lstadd_back(&list, node5);
    print_list(list, "  Résultat");
    
    printf("\n  Ajout de \"Tokyo\" à la fin:\n");
    t_list *node6 = create_node("Tokyo");
    ft_lstadd_back(&list, node6);
    print_list(list, "  Résultat");
    
    printf("\n  Nouvelle taille: %d (attendu: 5)\n", ft_lstsize(list));

    // Test d'ajout dans une liste vide
    printf("\n  ── Test spécial: Ajout dans une liste vide ──\n");
    t_list *list2 = NULL;
    t_list *node7 = create_node("First");
    ft_lstadd_back(&list2, node7);
    print_list(list2, "  Liste vide après ajout");
    printf("  💡 Fonctionne aussi sur une liste vide!\n");

    // ==================== ft_lstiter ====================
    print_separator("TEST 6: ft_lstiter");
    print_description("Applique une fonction f à chaque élément de la liste.\n"
                     "BUT: Parcourir la liste et faire une action sur chaque contenu.\n"
                     "PARAMÈTRES: *lst (tête), fonction f(content).\n"
                     "RETOUR: Aucun (void) - peut modifier les contenus en place.\n"
                     "UTILISATIONS: Afficher, modifier, traiter chaque élément.");
    
    print_list(list, "Liste actuelle");
    
    printf("\n  Test 1: Affichage avec print_content:\n");
    ft_lstiter(list, print_content);
    
    printf("\n  Test 2: Modification avec uppercase_content:\n");
    print_list(list2, "    Avant");
    ft_lstiter(list2, uppercase_content);
    print_list(list2, "    Après");
    printf("  💡 Le contenu de list2 a été modifié directement!\n");

    // ==================== ft_lstmap ====================
    print_separator("TEST 7: ft_lstmap");
    print_description("Crée une NOUVELLE liste en appliquant une fonction à chaque élément.\n"
                     "BUT: Transformer une liste sans modifier l'originale (mapping fonctionnel).\n"
                     "PARAMÈTRES:\n"
                     "  • *lst: liste source\n"
                     "  • *f(content): fonction de transformation\n"
                     "  • *del(content): fonction pour libérer en cas d'erreur\n"
                     "RETOUR: Nouvelle liste transformée, ou NULL si échec.\n"
                     "⚠️  Crée de NOUVEAUX nœuds avec de NOUVEAUX contenus.\n"
                     "⚠️  Penser à libérer la nouvelle liste avec ft_lstclear!");
    
    print_list(list, "Liste originale");
    
    printf("\n  Application de duplicate_uppercase (crée copie en majuscules):\n");
    t_list *mapped_list = ft_lstmap(list, duplicate_uppercase, del_content);
    
    if (mapped_list) {
        print_list(mapped_list, "  Nouvelle liste mappée");
        printf("  Taille: %d\n", ft_lstsize(mapped_list));
        
        print_list(list, "  Liste originale (INCHANGÉE)");
        printf("\n  💡 Deux listes distinctes et indépendantes!\n");
        
        // Libération de la liste mappée
        ft_lstclear(&mapped_list, del_content);
        printf("\n  ✓ Liste mappée libérée proprement\n");
    } else {
        printf("  ✗ Échec de ft_lstmap\n");
    }

    // ==================== ft_lstdelone ====================
    print_separator("TEST 8: ft_lstdelone");
    print_description("Supprime et libère UN SEUL nœud.\n"
                     "BUT: Détruire un maillon (libère content puis le nœud lui-même).\n"
                     "PARAMÈTRES: *lst (nœud à supprimer), fonction del(content).\n"
                     "RETOUR: Aucun (void).\n"
                     "⚠️  ATTENTION:\n"
                     "  • Ne modifie PAS les pointeurs de la liste!\n"
                     "  • À utiliser pour un nœud ISOLÉ ou après l'avoir retiré de la liste.\n"
                     "  • Pour supprimer toute une liste, utiliser ft_lstclear!");
    
    printf("\nTest: Suppression d'un nœud isolé\n");
    t_list *node_to_delete = create_node("ToDelete");
    printf("  1. Création: [\"ToDelete\"] -> NULL\n");
    printf("  2. Appel de ft_lstdelone...\n");
    ft_lstdelone(node_to_delete, del_content);
    printf("  3. ✓ Nœud supprimé et libéré\n");
    
    printf("\n💡 Exemple d'utilisation typique:\n");
    printf("   Pour retirer le 2e élément d'une liste:\n");
    printf("   1. Sauvegarder: temp = list->next;\n");
    printf("   2. Relier: list->next = temp->next;\n");
    printf("   3. Libérer: ft_lstdelone(temp, del);\n");

    // ==================== ft_lstclear ====================
    print_separator("TEST 9: ft_lstclear");
    print_description("Supprime et libère TOUTE la liste.\n"
                     "BUT: Détruire complètement une liste chaînée.\n"
                     "PARAMÈTRES: **lst (adresse du pointeur de tête), fonction del(content).\n"
                     "RETOUR: Aucun (void) - met *lst à NULL après.\n"
                     "FONCTIONNEMENT:\n"
                     "  • Parcourt chaque nœud\n"
                     "  • Libère le content avec del()\n"
                     "  • Libère le nœud lui-même\n"
                     "  • Met le pointeur de tête à NULL\n"
                     "⚠️  Après ft_lstclear, la liste n'existe plus!");
    
    print_list(list, "Liste avant ft_lstclear");
    printf("  Taille: %d nœuds\n", ft_lstsize(list));
    
    printf("\n  Appel de ft_lstclear(&list, del_content)...\n");
    ft_lstclear(&list, del_content);
    
    print_list(list, "  Liste après ft_lstclear");
    printf("  Pointeur de tête = %s ✓\n", list ? "NON NULL ✗" : "NULL");
    printf("\n  💡 Toute la liste a été détruite et libérée!\n");
    
    // Nettoyage de list2
    ft_lstclear(&list2, del_content);

    // ==================== TESTS SUPPLÉMENTAIRES ====================
    print_separator("TEST 10: Scénario complet d'utilisation");
    print_description("Cas d'usage réel: Construction, manipulation, affichage, transformation.\n"
                     "Démonstration d'un workflow typique avec les listes chaînées.");
    
    printf("\n┌─ Étape 1: Construction mixte (front + back) ─────────────────┐\n");
    t_list *complex_list = NULL;
    
    ft_lstadd_front(&complex_list, create_node("Middle"));
    print_list(complex_list, "  Après ajout front \"Middle\"");
    
    ft_lstadd_front(&complex_list, create_node("First"));
    print_list(complex_list, "  Après ajout front \"First\"");
    
    ft_lstadd_back(&complex_list, create_node("Last"));
    print_list(complex_list, "  Après ajout back \"Last\"");
    
    printf("\n  Statistiques:\n");
    printf("    • Taille: %d\n", ft_lstsize(complex_list));
    printf("    • Premier: \"%s\"\n", (char *)complex_list->content);
    printf("    • Dernier: \"%s\"\n", (char *)ft_lstlast(complex_list)->content);
    
    printf("\n┌─ Étape 2: Itération et affichage ───────────────────────────┐\n");
    ft_lstiter(complex_list, print_content);
    
    printf("\n┌─ Étape 3: Création d'une version transformée ────────────────┐\n");
    t_list *upper_list = ft_lstmap(complex_list, duplicate_uppercase, del_content);
    if (upper_list) {
        print_list(upper_list, "  Version en majuscules");
        print_list(complex_list, "  Version originale (préservée)");
        ft_lstclear(&upper_list, del_content);
        printf("  ✓ Version transformée libérée\n");
    }
    
    printf("\n┌─ Étape 4: Nettoyage final ───────────────────────────────────┐\n");
    ft_lstclear(&complex_list, del_content);
    printf("  ✓ Toutes les listes ont été libérées proprement\n");

    // ==================== RÉSUMÉ ====================
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                ║\n");
    printf("║                  RÉSUMÉ DES FONCTIONS BONUS                    ║\n");
    printf("║                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("┌────────────────────────────────────────────────────────────────┐\n");
    printf("│ CRÉATION & AJOUT                                               │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ ✓ ft_lstnew        Crée un nouveau nœud                        │\n");
    printf("│ ✓ ft_lstadd_front  Ajoute au DÉBUT (LIFO)                      │\n");
    printf("│ ✓ ft_lstadd_back   Ajoute à la FIN (FIFO)                      │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ INFORMATION                                                    │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ ✓ ft_lstsize       Compte les éléments                         │\n");
    printf("│ ✓ ft_lstlast       Retourne le dernier nœud                    │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ ITÉRATION & TRANSFORMATION                                     │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ ✓ ft_lstiter       Applique f() à chaque élément (in-place)    │\n");
    printf("│ ✓ ft_lstmap        Crée nouvelle liste transformée             │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ SUPPRESSION                                                    │\n");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    printf("│ ✓ ft_lstdelone     Supprime UN nœud                            │\n");
    printf("│ ✓ ft_lstclear      Supprime TOUTE la liste                     │\n");
    printf("└────────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║               FIN DES TESTS BONUS - LIBFT                     ║\n");
    printf("║                                                                ║\n");
    printf("║  Toutes les fonctions de listes chaînées ont été testées !    ║\n");
    printf("║                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    return (0);
}
