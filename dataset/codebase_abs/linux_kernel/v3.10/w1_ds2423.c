static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_2 V_10 [ V_11 * V_12 ] ;
T_2 V_13 [ 3 ] ;
int V_14 ;
int V_15 ;
int V_16 ;
T_1 V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
V_17 = V_21 ;
V_14 = ( 12 << 5 ) + 31 ;
V_13 [ 0 ] = 0xA5 ;
V_13 [ 1 ] = V_14 & 0xFF ;
V_13 [ 2 ] = V_14 >> 8 ;
F_3 ( & V_8 -> V_22 ) ;
if ( ! F_4 ( V_6 ) ) {
F_5 ( V_8 , V_13 , 3 ) ;
V_15 = 0 ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_15 += F_6 ( V_8 ,
V_10 + ( V_19 * V_12 ) , V_12 ) ;
for ( V_18 = 0 ; V_18 < V_12 ; ++ V_18 )
V_17 -= snprintf ( V_4 + V_21 - V_17 ,
V_17 , L_1 ,
V_10 [ ( V_19 * V_12 ) + V_18 ] ) ;
if ( V_15 != ( V_19 + 1 ) * V_12 ) {
F_7 ( V_1 ,
L_2
L_3 ,
V_15 ,
V_12 ) ;
V_17 -= snprintf ( V_4 + V_21 - V_17 ,
V_17 , L_4 ) ;
} else {
if ( V_19 == 0 ) {
V_20 = F_8 ( V_23 , V_13 , 3 ) ;
V_20 = F_8 ( V_20 , V_10 , 11 ) ;
} else {
V_20 = F_8 ( V_23 ,
( V_10 + 11 ) +
( ( V_19 - 1 ) * V_12 ) ,
V_12 ) ;
}
if ( V_20 == V_24 ) {
V_16 = 0 ;
for ( V_18 = 4 ; V_18 > 0 ; V_18 -- ) {
V_16 <<= 8 ;
V_16 |= V_10 [ ( V_19 *
V_12 ) + V_18 ] ;
}
V_17 -= snprintf ( V_4 + V_21 - V_17 ,
V_17 , L_5 , V_16 ) ;
} else {
V_17 -= snprintf ( V_4 + V_21 - V_17 ,
V_17 , L_4 ) ;
}
}
}
} else {
V_17 -= snprintf ( V_4 + V_21 - V_17 , V_17 , L_6 ) ;
}
F_9 ( & V_8 -> V_22 ) ;
return V_21 - V_17 ;
}
static int F_10 ( struct V_5 * V_6 )
{
return F_11 ( & V_6 -> V_8 , & V_25 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_8 , & V_25 ) ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_26 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_26 ) ;
}
