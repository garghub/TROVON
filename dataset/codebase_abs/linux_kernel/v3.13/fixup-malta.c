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
static int V_10 [ V_11 ] = {
0 , 0 , 0 , 3 ,
4 , 5 , 6 , 7 ,
0 , 9 , 10 , 11 ,
12 , 0 , 14 , 15
} ;
int V_12 ;
for ( V_12 = 0 ; V_12 <= 3 ; V_12 ++ ) {
F_4 ( V_8 , V_13 + V_12 , & V_9 ) ;
if ( V_9 & V_14 )
V_7 [ V_15 + V_12 ] = 0 ;
else
V_7 [ V_15 + V_12 ] = V_10 [ V_9 &
V_16 ] ;
}
if ( F_5 ( V_8 -> V_17 ) == 10 ) {
F_4 ( V_8 , V_18 , & V_9 ) ;
F_6 ( V_8 , V_18 , V_9 |
V_19 ) ;
}
}
static void F_7 ( struct V_1 * V_8 )
{
unsigned char V_9 ;
if ( F_5 ( V_8 -> V_17 ) == 10 ) {
F_4 ( V_8 , V_20 ,
& V_9 ) ;
F_6 ( V_8 , V_20 ,
V_9 | V_21 ) ;
F_4 ( V_8 , V_22 ,
& V_9 ) ;
F_6 ( V_8 , V_22 ,
V_9 | V_23 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_24 , V_25 ;
( void ) F_4 ( V_2 , V_26 , & V_24 ) ;
V_25 = V_24 | V_27 |
V_28 |
V_29 ;
( void ) F_6 ( V_2 , V_26 , V_25 ) ;
}
