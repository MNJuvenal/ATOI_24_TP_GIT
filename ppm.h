#ifndef PPM_H
#define PPM_H

struct ppm_pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};

int ppm_image_init(struct ppm_image *im, int w, int h);
int ppm_image_release(struct ppm_image *im);

static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */
#ifndef PPM_H
#define PPM_H

struct ppm_pixel {   // cette Structure représentant un pixel avec des valeurs RGB.
  unsigned char r;  /**< Composante rouge */
  unsigned char g;  /**< Composante verte */
  unsigned char b;  /**< Composante bleuer */
};

static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}
/**
 * static inline void Définit les valeurs RGB d'un pixel et prends en parametres 
 *px Pointeur vers la structure du pixel.
 * r Valeur de la composante rouge.
 * g Valeur de la composante verte.
 * b Valeur de la composante bleue.
 **/


//Structure représentant une image PPM.
struct ppm_image {
  unsigned int width; //Largeur de l'image 
  unsigned int height; // Hauteur de l'image 
  struct ppm_pixel *px; // Tableau de pixels
};

int ppm_image_init(struct ppm_image *im, int w, int h);

/**
 * cette fonction  Initialise une image PPM avec la largeur et la hauteur spécifiées.
 * et avec parametres :
          * Pointeur vers la structure de l'image à initialiser.
        * w Largeur de l'image.
        * h Hauteur de l'image.
  * et retourne :
         0 en cas de succès, -1 en cas d'échec.
 **/

int ppm_image_release(struct ppm_image *im);

/**
 * cette fonction  Définit les valeurs RGB d'un pixel aux coordonnées spécifiées dans l'image.
 * 
 *  im Pointeur vers la structure de l'image.
 *  x Coordonnée X du pixel.
 *  y Coordonnée Y du pixel.
 *  r Valeur de la composante rouge.
 *  g Valeur de la composante verte.
 *  b Valeur de la composante bleue.
 */

static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}
/**
 * cette fonction  Écrit les données de l'image PPM dans un fichier.
 * 
 * im Pointeur vers la structure de l'image.
 * Chemin vers le fichier de sortie.
 * et return 0 en cas de succès, -1 en cas d'échec.
 */

int ppm_image_dump(struct ppm_image *im, char *path);
/**
 * cette fonction  Écrit les données de l'image PPM dans un fichier.
 * 
 *  im Pointeur vers la structure de l'image.
 *  path Chemin vers le fichier de sortie.
 * retourne  0 en cas de succès, -1 en cas d'échec.
 */

#endif 