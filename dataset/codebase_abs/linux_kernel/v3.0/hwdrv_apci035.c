int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_10 = 0 ;
V_11 = 0 ;
V_12 -> V_13 = V_14 ;
V_12 -> V_15 = V_7 [ 0 ] ;
V_16 = V_7 [ 1 ] ;
if ( V_7 [ 0 ] == 0 ) {
V_10 = 2 ;
} else {
V_10 = 0 ;
}
V_9 = 0 ;
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = 0 ;
V_9 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
F_2 ( V_7 [ 3 ] , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 4 ) ;
F_2 ( V_7 [ 2 ] , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 8 ) ;
if ( V_7 [ 0 ] == V_18 ) {
V_9 =
( V_9 & 0xFFF719E2UL ) | V_10 << 13UL | 0x10UL ;
}
else {
if ( V_7 [ 0 ] == V_19 ) {
V_9 = V_9 & 0xFFF819E2UL ;
} else {
F_4 ( L_1 ) ;
return - V_20 ;
}
}
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = 0 ;
V_9 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = V_9 & 0xFFFFF89FUL ;
if ( V_7 [ 4 ] == V_21 ) {
V_9 = V_9 | ( V_7 [ 5 ] << 5 ) ;
}
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = 0 ;
V_9 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = V_9 & 0xFFFFF87FUL ;
if ( V_7 [ 6 ] == V_21 ) {
V_9 = V_9 | ( V_7 [ 7 ] << 7 ) ;
}
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = 0 ;
V_9 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = V_9 & 0xFFFFF9FBUL ;
V_9 = V_9 | ( V_7 [ 8 ] << 2 ) ;
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
if ( V_7 [ 9 ] == V_21 ) {
F_2 ( V_7 [ 11 ] ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 24 ) ;
F_2 ( V_7 [ 10 ] ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 28 ) ;
}
V_9 = 0 ;
V_9 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = V_9 & 0xFFFFF9F7UL ;
V_9 = V_9 | ( V_7 [ 12 ] << 3 ) ;
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = 0 ;
V_9 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_8 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 16 ) ;
V_9 = ( V_9 & 0xFFFFF9FDUL ) | ( V_7 [ 13 ] << 1 ) ;
F_2 ( V_9 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
return V_6 -> V_22 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_9 = 0 ;
int V_23 = 0 ;
if ( V_7 [ 0 ] == 1 ) {
V_9 =
F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = ( V_9 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_9 ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
}
if ( V_7 [ 0 ] == 2 ) {
V_9 =
F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
V_9 = ( V_9 & 0xFFFFF9FFUL ) | 0x200UL ;
F_2 ( V_9 ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
}
if ( V_7 [ 0 ] == 0 )
{
V_9 = 0 ;
F_2 ( V_9 ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 12 ) ;
}
if ( V_7 [ 0 ] == 3 )
{
V_9 = 0 ;
for ( V_23 = 1 ; V_23 <= 4 ; V_23 ++ ) {
if ( V_12 -> V_15 == V_19 ) {
V_9 = 0x2UL ;
} else {
V_9 = 0x10UL ;
}
V_16 = V_23 ;
F_2 ( V_9 ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) +
0 ) ;
}
}
if ( V_7 [ 0 ] == 4 )
{
V_9 = 0 ;
for ( V_23 = 1 ; V_23 <= 4 ; V_23 ++ ) {
if ( V_12 -> V_15 == V_19 ) {
V_9 = 0x1UL ;
} else {
V_9 = 0x8UL ;
}
V_16 = V_23 ;
F_2 ( V_9 ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) +
0 ) ;
}
}
if ( V_7 [ 0 ] == 5 )
{
V_9 = 0 ;
for ( V_23 = 1 ; V_23 <= 4 ; V_23 ++ ) {
if ( V_12 -> V_15 == V_19 ) {
V_9 = 0x4UL ;
} else {
V_9 = 0x20UL ;
}
V_16 = V_23 ;
F_2 ( V_9 ,
V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) +
0 ) ;
}
V_11 = 1 ;
}
return V_6 -> V_22 ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = 0 ;
V_16 = V_6 -> V_24 [ 0 ] ;
V_8 = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 16 ) ;
V_7 [ 0 ] = ( ( V_8 >> 1 ) & 1 ) ;
V_7 [ 1 ] = ( ( V_8 >> 2 ) & 1 ) ;
V_7 [ 2 ] = ( ( V_8 >> 3 ) & 1 ) ;
V_7 [ 3 ] = ( ( V_8 >> 0 ) & 1 ) ;
if ( V_12 -> V_15 == V_18 ) {
V_7 [ 4 ] = F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 0 ) ;
}
return V_6 -> V_22 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_12 -> V_13 = V_14 ;
F_2 ( 0x200 | 0 , V_12 -> V_17 + 128 + 0x4 ) ;
F_2 ( 0 , V_12 -> V_17 + 128 + 0 ) ;
F_2 ( 0x300 | 0 , V_12 -> V_17 + 128 + 0x4 ) ;
F_2 ( ( V_7 [ 0 ] << 8 ) , V_12 -> V_17 + 128 + 0 ) ;
F_2 ( 0x200000UL , V_12 -> V_17 + 128 + 12 ) ;
return V_6 -> V_22 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_25 = 0 ;
V_25 = 0x80000 ;
F_2 ( V_25 , V_12 -> V_17 + 128 + 8 ) ;
V_7 [ 0 ] = F_3 ( V_12 -> V_17 + 128 + 28 ) ;
return V_6 -> V_22 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
for ( V_23 = 1 ; V_23 <= 4 ; V_23 ++ ) {
V_16 = V_23 ;
F_2 ( 0x0 , V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 0 ) ;
}
F_2 ( 0x0 , V_12 -> V_17 + 128 + 12 ) ;
return 0 ;
}
static void F_10 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
unsigned int V_28 = 0 ;
unsigned int V_29 = 0 ;
unsigned int V_30 = 0 ;
unsigned int V_31 = 0 ;
unsigned int V_32 = 0 ;
if ( V_11 == 1 ) {
V_16 = V_33 ;
V_33 = V_33 + 1 ;
}
V_28 = F_3 ( V_12 -> V_17 + 128 + 16 ) ;
V_29 =
F_3 ( V_12 -> V_17 + ( ( V_16 - 1 ) * 32 ) + 20 ) ;
if ( ( ( ( V_28 ) & 0x8 ) == 0x8 ) )
{
V_30 = F_3 ( V_12 -> V_17 + 128 + 12 ) ;
V_30 = V_30 & 0xFFDF0000UL ;
F_2 ( V_30 , V_12 -> V_17 + 128 + 12 ) ;
V_31 = F_3 ( V_12 -> V_17 + 128 + 60 ) ;
V_32 = F_3 ( V_12 -> V_17 + 128 + 60 ) ;
F_11 ( V_34 , V_12 -> V_13 , 0 ) ;
}
else {
if ( ( V_29 & 0x1 ) == 0x1 ) {
F_11 ( V_34 , V_12 -> V_13 , 0 ) ;
}
}
return;
}
