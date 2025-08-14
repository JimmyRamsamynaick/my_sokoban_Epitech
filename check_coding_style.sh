#!/bin/bash

# Script de vérification du coding style Epitech
# Ce script aide à identifier les problèmes potentiels de coding style

echo "=== Vérification du Coding Style Epitech ==="
echo

# Vérification des fichiers .c et .h
echo "📁 Fichiers source trouvés:"
find . -name '*.c' -o -name '*.h' | grep -v './lib/' | sort
echo

# Vérification des lignes trop longues (>80 caractères)
echo "📏 Vérification des lignes trop longues (>80 caractères):"
find . -name '*.c' -o -name '*.h' | grep -v './lib/' | xargs grep -n '.\{81,\}' || echo "✅ Aucune ligne trop longue trouvée"
echo

# Vérification des espaces en fin de ligne
echo "🔍 Vérification des espaces en fin de ligne:"
find . -name '*.c' -o -name '*.h' | grep -v './lib/' | xargs grep -n '[[:space:]]$' || echo "✅ Aucun espace en fin de ligne trouvé"
echo

# Vérification des tabulations (doivent être des espaces)
echo "🔍 Vérification des tabulations:"
find . -name '*.c' -o -name '*.h' | grep -v './lib/' | xargs grep -P '\t' || echo "✅ Aucune tabulation trouvée"
echo

# Conseils généraux
echo "💡 Conseils pour le coding style Epitech:"
echo "   - Utilisez 4 espaces pour l'indentation (pas de tabulations)"
echo "   - Maximum 80 caractères par ligne"
echo "   - Pas d'espaces en fin de ligne"
echo "   - Noms de fonctions en snake_case"
echo "   - Noms de variables en snake_case"
echo "   - Accolades sur la même ligne pour les fonctions"
echo "   - Commentaires en anglais"
echo "   - Pas plus de 25 lignes par fonction"
echo "   - Pas plus de 5 fonctions par fichier"
echo
echo "🔧 Pour une vérification complète, utilisez l'outil officiel Epitech:"
echo "   coding-style . ."
echo