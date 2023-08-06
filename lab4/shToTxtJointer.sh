find . -type f name "*.sh" -exec sh -c 'cp "$1" "./$(basename "%1" .sh).txt"' sh {} \;
