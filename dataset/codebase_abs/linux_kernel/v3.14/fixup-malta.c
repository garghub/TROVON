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
T_3 V_10 ;
static int V_11 [ V_12 ] = {
0 , 0 , 0 , 3 ,
4 , 5 , 6 , 7 ,
0 , 9 , 10 , 11 ,
12 , 0 , 14 , 15
} ;
int V_13 ;
for ( V_13 = 0 ; V_13 <= 3 ; V_13 ++ ) {
F_4 ( V_8 , V_14 + V_13 , & V_9 ) ;
if ( V_9 & V_15 )
V_7 [ V_16 + V_13 ] = 0 ;
else
V_7 [ V_16 + V_13 ] = V_11 [ V_9 &
V_17 ] ;
}
if ( F_5 ( V_8 -> V_18 ) == 10 ) {
F_4 ( V_8 , V_19 , & V_9 ) ;
F_6 ( V_8 , V_19 , V_9 |
V_20 ) ;
}
F_7 ( V_8 , V_21 , & V_10 ) ;
F_8 ( V_8 , V_21 ,
V_10 | V_22 ) ;
F_4 ( V_8 , V_23 , & V_9 ) ;
V_9 |= V_24 | V_25 ;
F_6 ( V_8 , V_23 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_8 )
{
unsigned char V_9 ;
if ( F_5 ( V_8 -> V_18 ) == 10 ) {
F_4 ( V_8 , V_26 ,
& V_9 ) ;
F_6 ( V_8 , V_26 ,
V_9 | V_27 ) ;
F_4 ( V_8 , V_28 ,
& V_9 ) ;
F_6 ( V_8 , V_28 ,
V_9 | V_29 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
T_2 V_30 , V_31 ;
( void ) F_4 ( V_2 , V_32 , & V_30 ) ;
V_31 = V_30 | V_33 |
V_34 |
V_35 ;
( void ) F_6 ( V_2 , V_32 , V_31 ) ;
}
