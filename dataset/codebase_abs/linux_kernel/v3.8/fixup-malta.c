int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = V_6 [ V_3 ] [ V_4 ] ;
return V_7 [ V_5 ] ;
}
int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_8 )
{
unsigned char V_9 ;
static int V_10 [ 16 ] = {
0 , 0 , 0 , 3 ,
4 , 5 , 6 , 7 ,
0 , 9 , 10 , 11 ,
12 , 0 , 14 , 15
} ;
int V_11 ;
for ( V_11 = 0 ; V_11 <= 3 ; V_11 ++ ) {
F_4 ( V_8 , 0x60 + V_11 , & V_9 ) ;
if ( V_9 & 0x80 )
V_7 [ V_12 + V_11 ] = 0 ;
else
V_7 [ V_12 + V_11 ] = V_10 [ V_9 & 15 ] ;
}
if ( F_5 ( V_8 -> V_13 ) == 10 ) {
F_4 ( V_8 , 0x69 , & V_9 ) ;
F_6 ( V_8 , 0x69 , V_9 | 0xf0 ) ;
}
}
static void F_7 ( struct V_1 * V_8 )
{
unsigned char V_9 ;
if ( F_5 ( V_8 -> V_13 ) == 10 ) {
F_4 ( V_8 , 0x41 , & V_9 ) ;
F_6 ( V_8 , 0x41 , V_9 | 0x80 ) ;
F_4 ( V_8 , 0x43 , & V_9 ) ;
F_6 ( V_8 , 0x43 , V_9 | 0x80 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_14 , V_15 ;
( void ) F_4 ( V_2 , 0x82 , & V_14 ) ;
V_15 = V_14 | 7 ;
( void ) F_6 ( V_2 , 0x82 , V_15 ) ;
}
