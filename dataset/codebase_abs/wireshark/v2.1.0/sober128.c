static inline unsigned long F_1 ( unsigned long V_1 , int V_2 )
{
__asm__("roll %%cl,%0"
:"=r" (word)
:"0" (word),"c" (i));
return V_1 ;
}
static inline unsigned long F_2 ( unsigned long V_1 , int V_2 )
{
__asm__("rorl %%cl,%0"
:"=r" (word)
:"0" (word),"c" (i));
return V_1 ;
}
static T_1 F_3 ( const unsigned char * V_3 )
{
T_1 V_4 ;
F_4 ( V_4 , V_3 ) ;
return V_4 ;
}
static void F_5 ( T_1 V_5 , unsigned char * V_3 )
{
T_1 V_4 ;
F_4 ( V_4 , V_3 ) ;
V_4 ^= V_5 ;
F_6 ( V_4 , V_3 ) ;
}
static void F_7 ( T_1 * V_6 )
{
T_1 V_4 ;
int V_2 ;
F_8 ( V_6 , 0 ) ;
V_4 = V_6 [ 0 ] ;
for ( V_2 = 1 ; V_2 < V_7 ; ++ V_2 ) {
V_6 [ V_2 - 1 ] = V_6 [ V_2 ] ;
}
V_6 [ V_7 - 1 ] = V_4 ;
}
static T_1 F_9 ( T_2 * V_8 )
{
T_1 V_4 ;
F_10 ( V_8 , 0 ) ;
return V_4 ;
}
int F_11 ( T_2 * V_8 )
{
int V_2 ;
V_8 -> V_6 [ 0 ] = 1 ;
V_8 -> V_6 [ 1 ] = 1 ;
for ( V_2 = 2 ; V_2 < V_7 ; ++ V_2 ) {
V_8 -> V_6 [ V_2 ] = V_8 -> V_6 [ V_2 - 1 ] + V_8 -> V_6 [ V_2 - 2 ] ;
}
V_8 -> V_9 = V_10 ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = 0 ;
return 0 ;
}
static void F_12 ( T_2 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_7 ; ++ V_2 ) {
V_8 -> V_13 [ V_2 ] = V_8 -> V_6 [ V_2 ] ;
}
}
static void F_13 ( T_2 * V_8 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_7 ; ++ V_2 ) {
V_8 -> V_6 [ V_2 ] = V_8 -> V_13 [ V_2 ] ;
}
}
static void F_14 ( T_2 * V_8 )
{
T_1 V_14 ;
do {
F_7 ( V_8 -> V_6 ) ;
V_14 = F_9 ( V_8 ) ;
} while ( ( V_14 & 0xFF000000 ) == 0 );
V_8 -> V_9 = V_14 ;
}
static void F_15 ( T_2 * V_8 )
{
T_1 V_4 ;
F_16 ( 0 ) ;
F_16 ( 1 ) ;
F_16 ( 2 ) ;
F_16 ( 3 ) ;
F_16 ( 4 ) ;
F_16 ( 5 ) ;
F_16 ( 6 ) ;
F_16 ( 7 ) ;
F_16 ( 8 ) ;
F_16 ( 9 ) ;
F_16 ( 10 ) ;
F_16 ( 11 ) ;
F_16 ( 12 ) ;
F_16 ( 13 ) ;
F_16 ( 14 ) ;
F_16 ( 15 ) ;
F_16 ( 16 ) ;
}
int F_17 ( const unsigned char * V_15 , unsigned long V_16 , T_2 * V_8 )
{
T_1 V_2 , V_17 ;
if ( V_8 -> V_11 == 1 ) {
for ( V_2 = 0 ; V_2 < V_16 / 4 ; V_2 ++ ) {
V_17 = F_3 ( & V_15 [ V_2 * 4 ] ) ;
F_18 ( V_17 ) ;
F_7 ( V_8 -> V_6 ) ;
F_19 ( F_9 ( V_8 ) ) ;
}
F_18 ( V_16 ) ;
F_15 ( V_8 ) ;
F_14 ( V_8 ) ;
F_12 ( V_8 ) ;
V_8 -> V_18 = 0 ;
V_8 -> V_11 = 0 ;
V_8 -> V_12 = 1 ;
} else {
F_13 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < V_16 / 4 ; V_2 ++ ) {
V_17 = F_3 ( & V_15 [ V_2 * 4 ] ) ;
F_18 ( V_17 ) ;
F_7 ( V_8 -> V_6 ) ;
F_19 ( F_9 ( V_8 ) ) ;
}
F_18 ( V_16 ) ;
F_15 ( V_8 ) ;
V_8 -> V_18 = 0 ;
}
return 0 ;
}
unsigned long F_20 ( unsigned char * V_15 , unsigned long V_19 , T_2 * V_8 )
{
T_1 V_4 , V_20 ;
V_20 = V_19 ;
while ( V_8 -> V_18 != 0 && V_19 != 0 ) {
* V_15 ++ ^= V_8 -> V_21 & 0xFF ;
V_8 -> V_21 >>= 8 ;
V_8 -> V_18 -= 8 ;
-- V_19 ;
}
#ifndef F_21
while ( V_19 >= V_7 * 4 ) {
F_22 ( 0 ) ;
F_22 ( 1 ) ;
F_22 ( 2 ) ;
F_22 ( 3 ) ;
F_22 ( 4 ) ;
F_22 ( 5 ) ;
F_22 ( 6 ) ;
F_22 ( 7 ) ;
F_22 ( 8 ) ;
F_22 ( 9 ) ;
F_22 ( 10 ) ;
F_22 ( 11 ) ;
F_22 ( 12 ) ;
F_22 ( 13 ) ;
F_22 ( 14 ) ;
F_22 ( 15 ) ;
F_22 ( 16 ) ;
V_15 += 4 * V_7 ;
V_19 -= 4 * V_7 ;
}
#endif
while ( 4 <= V_19 ) {
F_7 ( V_8 -> V_6 ) ;
V_4 = F_9 ( V_8 ) ;
F_5 ( V_4 , V_15 ) ;
V_15 += 4 ;
V_19 -= 4 ;
}
if ( V_19 != 0 ) {
F_7 ( V_8 -> V_6 ) ;
V_8 -> V_21 = F_9 ( V_8 ) ;
V_8 -> V_18 = 32 ;
while ( V_8 -> V_18 != 0 && V_19 != 0 ) {
* V_15 ++ ^= V_8 -> V_21 & 0xFF ;
V_8 -> V_21 >>= 8 ;
V_8 -> V_18 -= 8 ;
-- V_19 ;
}
}
return V_20 ;
}
