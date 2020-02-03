# get_next_line
### Description
42 Projet get_next_line

- Une fonction qui retourne une ligne lue depuis un file descriptor, sans le retour à la ligne.
- Des appels successifs à get_next_line vous permet de
lire l’entièreté du texte disponible sur le file descriptor, une ligne à la fois, jusqu’au
EOF.

### Manuel
- Prototype int get_next_line(int fd, char **line);

- Paramètres:
  -#1. le file descriptor sur lequel lire
  -#2. La valeur de ce qui a été lu

- Valeur de retour:
  - 1 : Une ligne a été lue
  - 0 : La fin de fichier a été atteinte
  - -1 : Une erreur est survenue

- Compilation: 
```bash
gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
```

