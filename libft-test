#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Prototypes des fonctions libft (à adapter selon ton libft.h)
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Fonctions utilitaires pour les tests
void print_separator(const char *title) {
    printf("\n╔════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-62s ║\n", title);
    printf("╚════════════════════════════════════════════════════════════════╝\n");
}

void print_description(const char *desc) {
    printf("📖 %s\n", desc);
    printf("───────────────────────────────────────────────────────────────\n");
}

// Fonction exemple pour ft_strmapi
char example_toupper(unsigned int i, char c) {
    (void)i;
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

// Fonction exemple pour ft_striteri
void example_print_index(unsigned int i, char *c) {
    printf("  Index %u: '%c'\n", i, *c);
}

int main(void) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                ║\n");
    printf("║           TEST COMPLET DE LA LIBFT - 42 (Détaillé)            ║\n");
    printf("║                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");

    // ========== PARTIE 1: Fonctions de vérification ==========
    
    print_separator("ft_isalpha");
    print_description("Vérifie si le caractère est alphabétique (a-z ou A-Z).\n"
                     "BUT: Identifier les lettres de l'alphabet.\n"
                     "RETOUR: 1 si alphabétique, 0 sinon.");
    printf("\nTests:\n");
    printf("  ft_isalpha('a') = %d (attendu: 1 - c'est une lettre)\n", ft_isalpha('a'));
    printf("  ft_isalpha('Z') = %d (attendu: 1 - c'est une lettre)\n", ft_isalpha('Z'));
    printf("  ft_isalpha('5') = %d (attendu: 0 - c'est un chiffre)\n", ft_isalpha('5'));
    printf("  ft_isalpha('@') = %d (attendu: 0 - c'est un symbole)\n", ft_isalpha('@'));

    print_separator("ft_isdigit");
    print_description("Vérifie si le caractère est un chiffre (0-9).\n"
                     "BUT: Identifier les chiffres numériques.\n"
                     "RETOUR: 1 si chiffre, 0 sinon.");
    printf("\nTests:\n");
    printf("  ft_isdigit('0') = %d (attendu: 1)\n", ft_isdigit('0'));
    printf("  ft_isdigit('9') = %d (attendu: 1)\n", ft_isdigit('9'));
    printf("  ft_isdigit('a') = %d (attendu: 0 - c'est une lettre)\n", ft_isdigit('a'));
    printf("  ft_isdigit(' ') = %d (attendu: 0 - c'est un espace)\n", ft_isdigit(' '));

    print_separator("ft_isalnum");
    print_description("Vérifie si le caractère est alphanumérique (lettre OU chiffre).\n"
                     "BUT: Identifier les caractères alphanumériques.\n"
                     "RETOUR: 1 si alphanumérique, 0 sinon.");
    printf("\nTests:\n");
    printf("  ft_isalnum('a') = %d (attendu: 1 - lettre)\n", ft_isalnum('a'));
    printf("  ft_isalnum('5') = %d (attendu: 1 - chiffre)\n", ft_isalnum('5'));
    printf("  ft_isalnum('Z') = %d (attendu: 1 - lettre)\n", ft_isalnum('Z'));
    printf("  ft_isalnum('@') = %d (attendu: 0 - symbole)\n", ft_isalnum('@'));

    print_separator("ft_isascii");
    print_description("Vérifie si la valeur est dans la table ASCII (0-127).\n"
                     "BUT: Vérifier si un entier correspond à un caractère ASCII valide.\n"
                     "RETOUR: 1 si ASCII valide, 0 sinon.");
    printf("\nTests:\n");
    printf("  ft_isascii(0) = %d (attendu: 1 - début ASCII)\n", ft_isascii(0));
    printf("  ft_isascii(127) = %d (attendu: 1 - fin ASCII)\n", ft_isascii(127));
    printf("  ft_isascii(128) = %d (attendu: 0 - hors ASCII)\n", ft_isascii(128));
    printf("  ft_isascii('A') = %d (attendu: 1)\n", ft_isascii('A'));

    print_separator("ft_isprint");
    print_description("Vérifie si le caractère est imprimable (32-126).\n"
                     "BUT: Identifier les caractères visibles/affichables.\n"
                     "RETOUR: 1 si imprimable, 0 sinon.");
    printf("\nTests:\n");
    printf("  ft_isprint(' ') = %d (attendu: 1 - espace est imprimable)\n", ft_isprint(' '));
    printf("  ft_isprint('~') = %d (attendu: 1 - tilde est imprimable)\n", ft_isprint('~'));
    printf("  ft_isprint(31) = %d (attendu: 0 - caractère de contrôle)\n", ft_isprint(31));
    printf("  ft_isprint(127) = %d (attendu: 0 - DEL)\n", ft_isprint(127));

    // ========== Fonctions de manipulation de strings ==========
    
    print_separator("ft_strlen");
    print_description("Calcule la longueur d'une chaîne (sans compter '\\0').\n"
                     "BUT: Connaître le nombre de caractères dans une string.\n"
                     "RETOUR: Nombre de caractères avant '\\0'.");
    printf("\nTests:\n");
    printf("  ft_strlen(\"Hello\") = %zu (attendu: 5)\n", ft_strlen("Hello"));
    printf("  ft_strlen(\"\") = %zu (attendu: 0 - chaîne vide)\n", ft_strlen(""));
    printf("  ft_strlen(\"42\") = %zu (attendu: 2)\n", ft_strlen("42"));

    print_separator("ft_toupper");
    print_description("Convertit une lettre minuscule en majuscule.\n"
                     "BUT: Transformer 'a'-'z' en 'A'-'Z'.\n"
                     "RETOUR: Le caractère en majuscule, ou inchangé si ce n'est pas une minuscule.");
    printf("\nTests:\n");
    printf("  ft_toupper('a') = '%c' (attendu: 'A')\n", ft_toupper('a'));
    printf("  ft_toupper('Z') = '%c' (attendu: 'Z' - déjà majuscule)\n", ft_toupper('Z'));
    printf("  ft_toupper('5') = '%c' (attendu: '5' - pas une lettre)\n", ft_toupper('5'));

    print_separator("ft_tolower");
    print_description("Convertit une lettre majuscule en minuscule.\n"
                     "BUT: Transformer 'A'-'Z' en 'a'-'z'.\n"
                     "RETOUR: Le caractère en minuscule, ou inchangé si ce n'est pas une majuscule.");
    printf("\nTests:\n");
    printf("  ft_tolower('A') = '%c' (attendu: 'a')\n", ft_tolower('A'));
    printf("  ft_tolower('z') = '%c' (attendu: 'z' - déjà minuscule)\n", ft_tolower('z'));
    printf("  ft_tolower('5') = '%c' (attendu: '5' - pas une lettre)\n", ft_tolower('5'));

    // ========== Fonctions de mémoire ==========
    
    print_separator("ft_memset");
    print_description("Remplit une zone mémoire avec un octet donné.\n"
                     "BUT: Initialiser ou réinitialiser une zone mémoire.\n"
                     "RETOUR: Pointeur vers la zone mémoire modifiée.");
    printf("\nTest:\n");
    char buffer1[10];
    ft_memset(buffer1, 'A', 5);
    buffer1[5] = '\0';
    printf("  ft_memset(buffer, 'A', 5) = \"%s\" (attendu: \"AAAAA\")\n", buffer1);

    print_separator("ft_bzero");
    print_description("Met à zéro (\\0) une zone mémoire.\n"
                     "BUT: Effacer/réinitialiser une zone mémoire à 0.\n"
                     "RETOUR: Aucun (void).");
    printf("\nTest:\n");
    char buffer2[10] = "123456789";
    printf("  Avant: \"%s\"\n", buffer2);
    ft_bzero(buffer2, 5);
    printf("  Après ft_bzero(buffer, 5): premiers octets = ");
    for (int i = 0; i < 10; i++)
        printf("%d ", buffer2[i]);
    printf("\n");

    print_separator("ft_memcpy");
    print_description("Copie n octets de src vers dst (zones NON chevauchantes).\n"
                     "BUT: Copier rapidement des données en mémoire.\n"
                     "RETOUR: Pointeur vers dst.\n"
                     "⚠️  ATTENTION: Ne pas utiliser si src et dst se chevauchent!");
    printf("\nTest:\n");
    char src1[] = "Hello World";
    char dst1[20];
    ft_memcpy(dst1, src1, strlen(src1) + 1);
    printf("  Source: \"%s\"\n", src1);
    printf("  Destination après ft_memcpy: \"%s\"\n", dst1);

    print_separator("ft_memmove");
    print_description("Copie n octets de src vers dst (gère les chevauchements).\n"
                     "BUT: Copier des données même si src et dst se chevauchent.\n"
                     "RETOUR: Pointeur vers dst.\n"
                     "✓ Sécurisé pour les zones mémoire qui se chevauchent.");
    printf("\nTest:\n");
    char buffer3[] = "Hello World";
    printf("  Avant: \"%s\"\n", buffer3);
    ft_memmove(buffer3 + 6, buffer3, 5);
    printf("  Après ft_memmove(buffer+6, buffer, 5): \"%s\"\n", buffer3);
    printf("  (copie \"Hello\" à partir de la position 6)\n");

    // ========== Fonctions de strings avancées ==========
    
    print_separator("ft_strlcpy");
    print_description("Copie src dans dst avec protection de taille (size-bounded).\n"
                     "BUT: Copier une string de façon sécurisée (évite buffer overflow).\n"
                     "RETOUR: Longueur de src (pour détecter la troncature).\n"
                     "✓ Garantit toujours un '\\0' final si size > 0.");
    printf("\nTest:\n");
    char dst2[10];
    size_t ret1 = ft_strlcpy(dst2, "Hello World", 10);
    printf("  Source: \"Hello World\"\n");
    printf("  Destination (taille 10): \"%s\"\n", dst2);
    printf("  Retour: %zu (longueur de src = 11)\n", ret1);
    printf("  → La chaîne a été tronquée car source > destination\n");

    print_separator("ft_strlcat");
    print_description("Concatène src à la fin de dst avec protection de taille.\n"
                     "BUT: Ajouter une string à une autre de façon sécurisée.\n"
                     "RETOUR: Longueur totale qu'elle a essayé de créer.\n"
                     "✓ Garantit toujours un '\\0' final si size > 0.");
    printf("\nTest:\n");
    char dst3[20] = "Hello";
    printf("  Destination avant: \"%s\"\n", dst3);
    size_t ret2 = ft_strlcat(dst3, " World", 20);
    printf("  Après ft_strlcat(dst, \" World\", 20): \"%s\"\n", dst3);
    printf("  Retour: %zu (longueur totale = 11)\n", ret2);

    print_separator("ft_strchr");
    print_description("Cherche la première occurrence d'un caractère dans une string.\n"
                     "BUT: Trouver où se trouve un caractère dans une chaîne.\n"
                     "RETOUR: Pointeur vers la première occurrence, ou NULL si non trouvé.");
    printf("\nTest:\n");
    char *test_str = "Hello World";
    char *result1 = ft_strchr(test_str, 'W');
    printf("  ft_strchr(\"Hello World\", 'W') = \"%s\"\n", result1 ? result1 : "NULL");
    char *result2 = ft_strchr(test_str, 'x');
    printf("  ft_strchr(\"Hello World\", 'x') = %s (caractère non trouvé)\n", 
           result2 ? result2 : "NULL");

    print_separator("ft_strrchr");
    print_description("Cherche la dernière occurrence d'un caractère dans une string.\n"
                     "BUT: Trouver la dernière position d'un caractère.\n"
                     "RETOUR: Pointeur vers la dernière occurrence, ou NULL.");
    printf("\nTest:\n");
    char *test_str2 = "Hello World";
    char *result3 = ft_strrchr(test_str2, 'o');
    printf("  ft_strrchr(\"Hello World\", 'o') = \"%s\"\n", result3 ? result3 : "NULL");
    printf("  (trouve le 'o' de 'World', pas celui de 'Hello')\n");

    print_separator("ft_strncmp");
    print_description("Compare les n premiers caractères de deux strings.\n"
                     "BUT: Vérifier si deux chaînes sont identiques (partiellement).\n"
                     "RETOUR: 0 si égales, <0 si s1<s2, >0 si s1>s2.");
    printf("\nTests:\n");
    printf("  ft_strncmp(\"Hello\", \"Hello\", 5) = %d (attendu: 0 - identiques)\n", 
           ft_strncmp("Hello", "Hello", 5));
    printf("  ft_strncmp(\"Hello\", \"World\", 5) = %d (attendu: <0)\n", 
           ft_strncmp("Hello", "World", 5));
    printf("  ft_strncmp(\"World\", \"Hello\", 5) = %d (attendu: >0)\n", 
           ft_strncmp("World", "Hello", 5));

    print_separator("ft_memchr");
    print_description("Cherche un octet dans une zone mémoire.\n"
                     "BUT: Trouver une valeur spécifique dans une zone mémoire.\n"
                     "RETOUR: Pointeur vers la première occurrence, ou NULL.");
    printf("\nTest:\n");
    char *test_mem = "Hello World";
    char *result4 = ft_memchr(test_mem, 'W', strlen(test_mem));
    printf("  ft_memchr(\"Hello World\", 'W', len) = \"%s\"\n", 
           result4 ? result4 : "NULL");

    print_separator("ft_memcmp");
    print_description("Compare n octets de deux zones mémoire.\n"
                     "BUT: Comparer des blocs de mémoire byte par byte.\n"
                     "RETOUR: 0 si identiques, <0 si s1<s2, >0 si s1>s2.");
    printf("\nTests:\n");
    printf("  ft_memcmp(\"Hello\", \"Hello\", 5) = %d (attendu: 0)\n", 
           ft_memcmp("Hello", "Hello", 5));
    printf("  ft_memcmp(\"Hello\", \"World\", 5) = %d (attendu: != 0)\n", 
           ft_memcmp("Hello", "World", 5));

    print_separator("ft_strnstr");
    print_description("Cherche une sous-chaîne (needle) dans une chaîne (haystack).\n"
                     "BUT: Trouver si une string contient une autre string.\n"
                     "RETOUR: Pointeur vers le début de needle dans haystack, ou NULL.\n"
                     "Limite la recherche aux len premiers caractères.");
    printf("\nTests:\n");
    char *result5 = ft_strnstr("Hello World", "World", 11);
    printf("  ft_strnstr(\"Hello World\", \"World\", 11) = \"%s\"\n", 
           result5 ? result5 : "NULL");
    char *result6 = ft_strnstr("Hello World", "World", 6);
    printf("  ft_strnstr(\"Hello World\", \"World\", 6) = %s\n", 
           result6 ? result6 : "NULL");
    printf("  (recherche limitée aux 6 premiers caractères)\n");

    print_separator("ft_atoi");
    print_description("Convertit une string en entier (int).\n"
                     "BUT: Transformer \"42\" en 42, \"-123\" en -123, etc.\n"
                     "RETOUR: La valeur entière.\n"
                     "Gère: espaces initiaux, signe +/-, et ignore le reste après les chiffres.");
    printf("\nTests:\n");
    printf("  ft_atoi(\"42\") = %d\n", ft_atoi("42"));
    printf("  ft_atoi(\"-42\") = %d\n", ft_atoi("-42"));
    printf("  ft_atoi(\"   +123\") = %d (ignore les espaces)\n", ft_atoi("   +123"));
    printf("  ft_atoi(\"0\") = %d\n", ft_atoi("0"));

    // ========== PARTIE 2: Fonctions avec malloc ==========
    
    print_separator("ft_calloc");
    print_description("Alloue de la mémoire et initialise tout à zéro.\n"
                     "BUT: Créer un tableau/zone mémoire initialisée à 0.\n"
                     "RETOUR: Pointeur vers la mémoire allouée, ou NULL si échec.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTest:\n");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (arr) {
        printf("  ft_calloc(5, sizeof(int)) - Valeurs: ");
        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("(tous initialisés à 0)\n");
        free(arr);
    }

    print_separator("ft_strdup");
    print_description("Duplique une string (allocation + copie).\n"
                     "BUT: Créer une copie indépendante d'une chaîne.\n"
                     "RETOUR: Pointeur vers la nouvelle string, ou NULL si échec.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTest:\n");
    char *dup = ft_strdup("Hello 42");
    if (dup) {
        printf("  Original: \"Hello 42\"\n");
        printf("  ft_strdup: \"%s\"\n", dup);
        free(dup);
    }

    print_separator("ft_substr");
    print_description("Extrait une sous-chaîne d'une string.\n"
                     "BUT: Récupérer une portion d'une chaîne.\n"
                     "PARAMÈTRES: string source, index de départ, longueur max.\n"
                     "RETOUR: Nouvelle string allouée, ou NULL.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTest:\n");
    char *substr = ft_substr("Hello World", 6, 5);
    if (substr) {
        printf("  ft_substr(\"Hello World\", 6, 5) = \"%s\"\n", substr);
        printf("  (extrait 5 caractères à partir de l'index 6)\n");
        free(substr);
    }

    print_separator("ft_strjoin");
    print_description("Concatène deux strings dans une nouvelle string.\n"
                     "BUT: Fusionner deux chaînes en une seule.\n"
                     "RETOUR: Nouvelle string = s1 + s2, ou NULL.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTest:\n");
    char *joined = ft_strjoin("Hello ", "World");
    if (joined) {
        printf("  ft_strjoin(\"Hello \", \"World\") = \"%s\"\n", joined);
        free(joined);
    }

    print_separator("ft_strtrim");
    print_description("Supprime les caractères du 'set' au début ET à la fin de s1.\n"
                     "BUT: Nettoyer une string des caractères indésirables aux extrémités.\n"
                     "PARAMÈTRES: string à trimmer, set de caractères à supprimer.\n"
                     "RETOUR: Nouvelle string trimmée, ou NULL.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTest:\n");
    char *trimmed = ft_strtrim("  Hello World  ", " ");
    if (trimmed) {
        printf("  ft_strtrim(\"  Hello World  \", \" \") = \"%s\"\n", trimmed);
        printf("  (supprime les espaces au début et à la fin)\n");
        free(trimmed);
    }

    print_separator("ft_split");
    print_description("Divise une string en tableau de strings selon un délimiteur.\n"
                     "BUT: Découper \"Hello,World,42\" en [\"Hello\", \"World\", \"42\"].\n"
                     "PARAMÈTRES: string à découper, caractère délimiteur.\n"
                     "RETOUR: Tableau de strings terminé par NULL, ou NULL si échec.\n"
                     "⚠️  Penser à free() chaque string ET le tableau après usage!");
    printf("\nTest:\n");
    char **split_result = ft_split("Hello,World,42,School", ',');
    if (split_result) {
        printf("  ft_split(\"Hello,World,42,School\", ','):\n");
        for (int i = 0; split_result[i]; i++) {
            printf("    [%d]: \"%s\"\n", i, split_result[i]);
            free(split_result[i]);
        }
        free(split_result);
    }

    print_separator("ft_itoa");
    print_description("Convertit un entier en string.\n"
                     "BUT: Transformer 42 en \"42\", -123 en \"-123\", etc.\n"
                     "RETOUR: String représentant le nombre, ou NULL.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTests:\n");
    char *itoa1 = ft_itoa(42);
    char *itoa2 = ft_itoa(-42);
    char *itoa3 = ft_itoa(0);
    if (itoa1 && itoa2 && itoa3) {
        printf("  ft_itoa(42) = \"%s\"\n", itoa1);
        printf("  ft_itoa(-42) = \"%s\"\n", itoa2);
        printf("  ft_itoa(0) = \"%s\"\n", itoa3);
        free(itoa1);
        free(itoa2);
        free(itoa3);
    }

    print_separator("ft_strmapi");
    print_description("Applique une fonction f à chaque caractère de s.\n"
                     "BUT: Transformer chaque caractère selon une fonction.\n"
                     "PARAMÈTRES: string source, fonction f(index, char).\n"
                     "RETOUR: Nouvelle string avec les caractères transformés.\n"
                     "La fonction reçoit l'index ET le caractère.\n"
                     "⚠️  Penser à free() après usage!");
    printf("\nTest:\n");
    char *mapped = ft_strmapi("hello", example_toupper);
    if (mapped) {
        printf("  ft_strmapi(\"hello\", toupper_func) = \"%s\"\n", mapped);
        printf("  (applique toupper à chaque caractère)\n");
        free(mapped);
    }

    print_separator("ft_striteri");
    print_description("Applique une fonction f à chaque caractère de s (modification directe).\n"
                     "BUT: Modifier une string en place caractère par caractère.\n"
                     "PARAMÈTRES: string à modifier, fonction f(index, *char).\n"
                     "RETOUR: Aucun (void) - modifie directement la string.\n"
                     "La fonction reçoit l'index ET un pointeur vers le caractère.");
    printf("\nTest:\n");
    char test_iter[] = "Hello";
    printf("  ft_striteri(\"Hello\", print_index_func):\n");
    ft_striteri(test_iter, example_print_index);

    // ========== Fonctions de sortie ==========
    
    print_separator("ft_putchar_fd");
    print_description("Écrit un caractère sur un file descriptor.\n"
                     "BUT: Afficher un caractère (stdout=1, stderr=2, fichier, etc.).\n"
                     "PARAMÈTRES: caractère, file descriptor.\n"
                     "RETOUR: Aucun (void).");
    printf("\nTest:\n");
    printf("  ft_putchar_fd('A', 1): ");
    ft_putchar_fd('A', 1);
    printf(" ← affiche 'A' sur stdout\n");

    print_separator("ft_putstr_fd");
    print_description("Écrit une string sur un file descriptor.\n"
                     "BUT: Afficher une chaîne complète.\n"
                     "PARAMÈTRES: string, file descriptor.\n"
                     "RETOUR: Aucun (void).");
    printf("\nTest:\n");
    printf("  ft_putstr_fd(\"Hello 42\", 1): ");
    ft_putstr_fd("Hello 42", 1);
    printf(" ← affiche sur stdout\n");

    print_separator("ft_putendl_fd");
    print_description("Écrit une string suivie d'un retour à la ligne sur un fd.\n"
                     "BUT: Afficher une ligne complète (avec \\n automatique).\n"
                     "PARAMÈTRES: string, file descriptor.\n"
                     "RETOUR: Aucun (void).");
    printf("\nTest:\n");
    printf("  ft_putendl_fd(\"Hello with newline\", 1):\n  → ");
    ft_putendl_fd("Hello with newline", 1);
    printf("  (un \\n a été ajouté automatiquement)\n");

    print_separator("ft_putnbr_fd");
    print_description("Écrit un nombre entier sur un file descriptor.\n"
                     "BUT: Afficher un int (gère les négatifs).\n"
                     "PARAMÈTRES: nombre entier, file descriptor.\n"
                     "RETOUR: Aucun (void).");
    printf("\nTests:\n");
    printf("  ft_putnbr_fd(42, 1): ");
    ft_putnbr_fd(42, 1);
    printf("\n");
    printf("  ft_putnbr_fd(-42, 1): ");
    ft_putnbr_fd(-42, 1);
    printf("\n");

    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                ║\n");
    printf("║                   FIN DES TESTS LIBFT                          ║\n");
    printf("║                                                                ║\n");
    printf("║  Toutes les fonctions ont été testées avec explications !     ║\n");
    printf("║                                                                ║\n");
    printf("╚════════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    return (0);
}
