static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned short V_8 ;
unsigned short V_9 ;
unsigned char V_10 ;
T_1 V_11 ;
if ( F_2 ( V_2 ) ) {
V_8 = F_3 ( V_2 ) ;
V_11 = V_2 -> V_12 ;
} else {
const struct V_13 * V_14 ;
struct V_13 V_15 ;
V_14 = F_4 ( V_2 , 0 , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return false ;
V_8 = F_5 ( V_14 -> V_16 ) ;
V_11 = V_14 -> V_17 ;
}
V_9 = V_8 & V_18 ;
V_10 = ( V_8 >> 13 ) & 0x7 ;
if ( F_6 ( V_19 ) )
F_7 ( V_9 , V_19 ) ;
if ( F_6 ( V_20 ) )
F_7 ( V_10 , V_20 ) ;
if ( F_6 ( V_21 ) )
F_7 ( V_11 , V_21 ) ;
return true ;
}
static int F_8 ( const struct V_22 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_23 * V_24 = V_4 -> V_25 ;
if ( V_24 -> V_26 != F_9 ( V_27 ) ) {
F_10 ( L_1 ,
F_5 ( V_24 -> V_26 ) ) ;
return - V_28 ;
}
if ( V_6 -> V_29 & ~ V_30 ) {
F_10 ( L_2 ,
V_6 -> V_29 , V_30 ) ;
return - V_28 ;
}
if ( V_6 -> V_31 & ~ V_30 ) {
F_10 ( L_3 ,
V_6 -> V_31 , V_30 ) ;
return - V_28 ;
}
if ( F_6 ( V_19 ) ) {
if ( ! ! V_6 -> V_9 ) {
if ( V_6 -> V_9 > V_32 ) {
F_10 ( L_4 ,
V_6 -> V_9 ) ;
return - V_28 ;
}
V_6 -> V_29 &= ~ V_20 ;
}
}
if ( F_6 ( V_20 ) ) {
if ( ( unsigned char ) V_6 -> V_10 > 7 ) {
F_10 ( L_5 ,
V_6 -> V_10 ) ;
return - V_28 ;
}
}
if ( F_6 ( V_21 ) ) {
if ( ( unsigned short ) F_5 ( V_6 -> V_11 ) < V_33 ) {
F_10 ( L_6
L_7 , F_5 ( V_6 -> V_11 ) ) ;
return - V_28 ;
}
}
return 0 ;
}
static int T_2 F_11 ( void )
{
F_10 ( L_8 V_34 L_9 ) ;
return F_12 ( & V_35 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_35 ) ;
}
