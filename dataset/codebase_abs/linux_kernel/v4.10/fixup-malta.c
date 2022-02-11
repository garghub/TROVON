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
T_4 V_14 ;
static int V_15 [ V_16 ] = {
0 , 0 , 0 , 3 ,
4 , 5 , 6 , 7 ,
0 , 9 , 10 , 11 ,
12 , 0 , 14 , 15
} ;
int V_17 ;
for ( V_17 = 0 ; V_17 <= 3 ; V_17 ++ ) {
F_7 ( V_11 , V_18 + V_17 , & V_12 ) ;
if ( V_12 & V_19 )
V_7 [ V_20 + V_17 ] = 0 ;
else
V_7 [ V_20 + V_17 ] = V_15 [ V_12 &
V_21 ] ;
}
if ( F_8 ( V_11 -> V_22 ) == 10 ) {
F_7 ( V_11 , V_23 , & V_12 ) ;
F_5 ( V_11 , V_23 , V_12 |
V_24 ) ;
}
F_9 ( V_11 , V_25 , & V_13 ) ;
F_10 ( V_11 , V_25 ,
V_13 | V_26 ) ;
F_7 ( V_11 , V_27 , & V_12 ) ;
V_12 |= V_28 | V_29 ;
F_5 ( V_11 , V_27 , V_12 ) ;
F_11 ( V_11 , V_30 , & V_14 ) ;
F_4 ( V_11 , V_30 ,
V_14 | V_31 ) ;
}
static void F_12 ( struct V_1 * V_11 )
{
unsigned char V_12 ;
if ( F_8 ( V_11 -> V_22 ) == 10 ) {
F_7 ( V_11 , V_32 ,
& V_12 ) ;
F_5 ( V_11 , V_32 ,
V_12 | V_33 ) ;
F_7 ( V_11 , V_34 ,
& V_12 ) ;
F_5 ( V_11 , V_34 ,
V_12 | V_35 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_36 , V_37 ;
( void ) F_7 ( V_2 , V_38 , & V_36 ) ;
V_37 = V_36 | V_39 |
V_40 |
V_41 ;
( void ) F_5 ( V_2 , V_38 , V_37 ) ;
}
