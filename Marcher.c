/*
 * This is the file where all of your implementation goes.
 * You will be submitting (only) this file to MarkUs. The 
 * documentation for the functions here is a bit long (sorry!)
 * but I hope it's precise enough to not leave room for 
 * ambiguity in any of the edge cases.
 * 
 * Driver.c gives you a way to run this code on a single image,
 * and TestMarcher.c runs a few test cases to verify your solution.
 * Look at the relevant files for more information regarding how to
 * use them.
 *
 * CSCB63 Winter 2020 - Assignment 2
 * (c) Mustafa Quraish
 */

#include "Marcher.h"

double findPath(struct image *mp, WeightFunc weight, int path[]) {
  /*
    Input: 
      im     - The image we are working on. For more information on what 
               this struct stores, look at ImgUtils.h
      
      weight - This is the weight **function**. You are supposed to use 
              this to find the energy required for each step by the Pixel 
              Marcher. The function takes in the 1-D coordinates of 2 pixels[*]
              and returns a double representing the cost to go from pixel a to 
              pixel b
                  usage: double cost = weight(im, a, b)

              [*] In memory, all the pixels are stored in a 1-D array (since 
                  memory is 1-D). Given a pixel with the coordinates (x,y), we
                  can compute it's 'pixel index' (an integer) as follows:
                      
                      int pixelIndex = x + y * (image width)
                                     = x + y * im->sx

                  For sake of not having to deal with tuples of (x,y) coordinates
                  (since this is hard in C), we will just deal with the index of 
                  a pixel from now on. If needed, you can extract the (x,y) coords
                  from the index as follows:
                          
                          x = pixelIndex % im->sx
                          y = pixelIndex / im->sx   (integer division)

                  In general, the energy needed to go from pixel a->b is not the same
                  as the energy needed to go from pixel b->a.

                  ** The cost must always be non-negative. **

    Requirements: 
        Your objective is to find the least-energy path from pixel (0,0) to pixel
        (sx-1, sy-1), along with the amount of energy required to traverse this path. 
        Here, sx and sy are the x and y dimensions of the image. (These are stored in 'im')

        From each pixel, it is possible to step to at most 4 other pixels, namely the ones 
        on it's top, right, bottom and left. All of these steps may require different amounts 
        of energy, and you have to use the given weight function to compute these.
        
                                                    (x, y-1)
                                                        ^
                                                        |
                                    (x-1, y) <------ (x, y) ------> (x+1, y)
                                                        |
                                                        v
                                                    (x, y+1)

        * You might want to figure out what the neighbours would be purely using the index 
        * of the pixel. This is not necessary but may help simplify your code.

        You should store the resulting least-energy path in the array `path`, such that
                - path[0] = start location = index of (0,0)        =  0 +  0 * sx = 0   from [*]
                - path[i] = the i-th node along the shortest path.
                - path[L-1] = end location = index of (sx-1, sy-1) = sx + sy * sx       from [*]
                - path[L] = -1   // To mark the end of the path
        where `L` is the number of nodes in your shortest path. Any valid shortest path is fine.
        You may assume there is already a valid amount of space allocated for the `path` array.
        
        The return value of the function is a double, which represents the total energy required
        to traverse along the shortest energy path. This value must be unique, even if there are
        multiple corresponding shortest paths.
            
      Each test case in the ones provided shouldn't take more than 1 second on the lab machines 
      in BV473. This will only really happen if your implementation is *really* inefficient, 
      which should not be the case for pretty much anyone (one of the benefits of using C! last
      year, some solutions took up to a few minutes for the bigmaze.ppm).
   */
  
  path[0] = -1;   // Terminate path 
  return 0;       // Replace with cost pf shortest path      
}

double allColourWeight(Image *im, int a, int b) {
  /*
     Input:
        im     - The image we are working on. For more information on what 
                 this struct stores, look at ImgUtils.h
        a, b   - Two (arbitrary, and valid) pixel 'indices' (look above, [*]),
                  where you want to return the weight from pixel a to pixel b

     Requirements:

        Define your own weight function here so that when "25colours.ppm" is run with 
        this function, the least-energy path in the image satisfies the following 
        constraints:

            (1) The least energy path must visit every one of the 25 colours in the image. 
                The order in which the path visits these colours does *not* matter, as 
                long as it visits them all. Be careful - missing even one colour will 
                result in 0 for this function.

            (2) The path can stay on one colour for as many steps as necessary, however 
                once the path leaves a colour, it can NEVER go through another pixel of 
                the same colour again. (Said in another way, it can only enter/exit each 
                coloured box once)

            (3) For any two given pixels, the energy required to step between them 
                 *must* be non-negative. If you have negative energies, this function 
                 may not work as intended.

        There is no restriction on path length, it can be as long or as short as needed - as 
        long as it satisfies the conditions above. Also, the amount of energy to step from 'a' 
        to 'b' does not have to be the same as the energy to step from 'b' to 'a'. This 
        is left up to you.

        Important Note: This weight function will NOT be tested with your solution to the first 
                        part of the question. This will be passed into my code and should still 
                        produce the results as above, so do not try to change your findPath() 
                        method to help with this.

                        This function will be tested ONLY on the specified image, so you do not 
                        have to worry about generalizing it. Just make sure that it does not 
                        depend on anything else in your code other than the arguments passed in.


        How to test:    Use the result of outputPath() to (visually) help you debug. Displaying
                        the path will be useful to start, as it will give you a general idea of 
                        what the least-energy path looks like.
   */
  
  return 0; // Default return value
}
