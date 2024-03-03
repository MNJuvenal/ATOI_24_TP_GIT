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
 */


//Structure représentant une image PPM.
struct ppm_image {
  unsigned int width; //Largeur de l'image 
  unsigned int height; // Hauteur de l'image 
  struct ppm_pixel *px; //Hauteur de l'image 
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