static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 = 0 , V_9 = 0 ;
V_6 -> V_10 = 1 ;
V_6 -> V_11 = 0 ;
for ( V_7 = 0 ; V_7 < 256 ; V_7 ++ )
V_6 -> V_12 [ V_7 ] = V_7 ;
for ( V_7 = 0 ; V_7 < 256 ; V_7 ++ ) {
T_2 V_13 = V_6 -> V_12 [ V_7 ] ;
V_8 = ( V_8 + V_3 [ V_9 ] + V_13 ) & 0xff ;
V_6 -> V_12 [ V_7 ] = V_6 -> V_12 [ V_8 ] ;
V_6 -> V_12 [ V_8 ] = V_13 ;
if ( ++ V_9 >= V_4 )
V_9 = 0 ;
}
return 0 ;
}
static void F_3 ( struct V_5 * V_6 , T_1 * V_14 , const T_1 * V_15 ,
unsigned int V_16 )
{
T_2 * const V_12 = V_6 -> V_12 ;
T_2 V_10 , V_11 , V_13 , V_17 ;
T_2 V_18 , V_19 , V_20 ;
if ( V_16 == 0 )
return;
V_10 = V_6 -> V_10 ;
V_11 = V_6 -> V_11 ;
V_13 = V_12 [ V_10 ] ;
V_11 = ( V_11 + V_13 ) & 0xff ;
V_17 = V_12 [ V_11 ] ;
do {
V_12 [ V_11 ] = V_13 ;
V_13 = ( V_13 + V_17 ) & 0xff ;
V_12 [ V_10 ] = V_17 ;
V_10 = ( V_10 + 1 ) & 0xff ;
V_19 = V_12 [ V_10 ] ;
V_18 = ( V_11 + V_19 ) & 0xff ;
V_20 = V_12 [ V_18 ] ;
* V_14 ++ = * V_15 ++ ^ V_12 [ V_13 ] ;
if ( -- V_16 == 0 )
break;
V_11 = V_18 ;
V_13 = V_19 ;
V_17 = V_20 ;
} while ( true );
V_6 -> V_10 = V_10 ;
V_6 -> V_11 = V_11 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_14 , const T_1 * V_15 )
{
F_3 ( F_2 ( V_2 ) , V_14 , V_15 , 1 ) ;
}
static int F_5 ( struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_23 * V_25 , unsigned int V_26 )
{
struct V_5 * V_6 = F_6 ( V_22 -> V_2 ) ;
struct V_27 V_28 ;
int V_29 ;
F_7 ( & V_28 , V_24 , V_25 , V_26 ) ;
V_29 = F_8 ( V_22 , & V_28 ) ;
while ( V_28 . V_26 > 0 ) {
T_1 * V_30 = V_28 . V_25 . V_31 . V_32 ;
T_1 * V_33 = V_28 . V_24 . V_31 . V_32 ;
F_3 ( V_6 , V_33 , V_30 , V_28 . V_26 ) ;
V_29 = F_9 ( V_22 , & V_28 , 0 ) ;
}
return V_29 ;
}
static int T_3 F_10 ( void )
{
return F_11 ( V_34 , F_12 ( V_34 ) ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( V_34 , F_12 ( V_34 ) ) ;
}
