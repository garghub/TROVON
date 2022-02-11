static void F_1 ( void )
{
const unsigned V_1 = ( ( V_2 + ( 8 * V_3 -> V_4 ) ) / ( 16 * V_3 -> V_4 ) ) ;
F_2 ( L_1 , V_5 ) ;
F_3 ( 0x83 , F_4 ( V_6 ) ) ;
F_3 ( V_1 & 0xff , F_4 ( V_7 ) ) ;
F_3 ( ( V_1 >> 8 ) & 0xff , F_4 ( V_8 ) ) ;
F_3 ( 0x03 , F_4 ( V_6 ) ) ;
F_3 ( 0x00 , F_4 ( V_9 ) ) ;
F_3 ( 0x00 , F_4 ( V_10 ) ) ;
F_3 ( 0x00 , F_4 ( V_11 ) ) ;
F_3 ( V_3 -> V_12 , F_4 ( V_13 ) ) ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
char V_23 [ V_24 ] ;
const struct V_25 * V_26 =
F_6 ( V_27 , V_17 ) ;
V_3 = V_26 -> V_28 ;
V_21 = F_7 ( V_15 , V_29 , 0 ) ;
if ( ! V_21 ) {
F_8 ( & V_15 -> V_18 , L_2 ) ;
return - V_30 ;
}
V_31 = F_9 ( & V_15 -> V_18 , V_21 -> V_32 , F_10 ( V_21 ) ) ;
if ( ! V_31 ) {
F_8 ( & V_15 -> V_18 , L_3 ) ;
return - V_30 ;
}
V_22 = F_11 ( & V_15 -> V_18 , NULL ) ;
if ( F_12 ( V_22 ) ) {
F_8 ( & V_15 -> V_18 , L_4 ) ;
return F_13 ( V_22 ) ;
}
V_2 = F_14 ( V_22 ) ;
if ( V_33 ) {
F_15 ( ( V_34 ) V_33 , V_23 ) ;
F_8 ( & V_15 -> V_18 ,
L_5 ,
V_33 , V_23 ) ;
return - V_35 ;
}
V_33 = F_1 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
V_33 = NULL ;
return 0 ;
}
