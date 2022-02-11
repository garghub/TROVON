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
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_8 , 0x1000 ) ;
F_5 ( V_2 , V_9 ,
V_10 ) ;
}
static void F_6 ( struct V_1 * V_11 )
{
unsigned char V_12 ;
T_3 V_13 ;
static int V_14 [ V_15 ] = {
0 , 0 , 0 , 3 ,
4 , 5 , 6 , 7 ,
0 , 9 , 10 , 11 ,
12 , 0 , 14 , 15
} ;
int V_16 ;
for ( V_16 = 0 ; V_16 <= 3 ; V_16 ++ ) {
F_7 ( V_11 , V_17 + V_16 , & V_12 ) ;
if ( V_12 & V_18 )
V_7 [ V_19 + V_16 ] = 0 ;
else
V_7 [ V_19 + V_16 ] = V_14 [ V_12 &
V_20 ] ;
}
if ( F_8 ( V_11 -> V_21 ) == 10 ) {
F_7 ( V_11 , V_22 , & V_12 ) ;
F_5 ( V_11 , V_22 , V_12 |
V_23 ) ;
}
F_9 ( V_11 , V_24 , & V_13 ) ;
F_10 ( V_11 , V_24 ,
V_13 | V_25 ) ;
F_7 ( V_11 , V_26 , & V_12 ) ;
V_12 |= V_27 | V_28 ;
F_5 ( V_11 , V_26 , V_12 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
unsigned char V_12 ;
if ( F_8 ( V_11 -> V_21 ) == 10 ) {
F_7 ( V_11 , V_29 ,
& V_12 ) ;
F_5 ( V_11 , V_29 ,
V_12 | V_30 ) ;
F_7 ( V_11 , V_31 ,
& V_12 ) ;
F_5 ( V_11 , V_31 ,
V_12 | V_32 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
T_2 V_33 , V_34 ;
( void ) F_7 ( V_2 , V_35 , & V_33 ) ;
V_34 = V_33 | V_36 |
V_37 |
V_38 ;
( void ) F_5 ( V_2 , V_35 , V_34 ) ;
}
