static void F_1 ( void )
{
const unsigned V_1 = ( ( V_2 + ( 8 * 19200 ) ) / ( 16 * 19200 ) ) ;
F_2 ( L_1 , V_3 ) ;
F_3 ( 0x83 , F_4 ( V_4 ) ) ;
F_3 ( V_1 & 0xff , F_4 ( V_5 ) ) ;
F_3 ( ( V_1 >> 8 ) & 0xff , F_4 ( V_6 ) ) ;
F_3 ( 0x03 , F_4 ( V_4 ) ) ;
F_3 ( 0x00 , F_4 ( V_7 ) ) ;
F_3 ( 0x00 , F_4 ( V_8 ) ) ;
F_3 ( 0x00 , F_4 ( V_9 ) ) ;
F_3 ( 'A' , F_4 ( V_10 ) ) ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_15 ;
char V_16 [ V_17 ] ;
V_14 = F_6 ( V_12 , V_18 , 0 ) ;
if ( ! V_14 ) {
F_7 ( & V_12 -> V_19 , L_2 ) ;
return - V_20 ;
}
V_21 = F_8 ( & V_12 -> V_19 , V_14 -> V_22 , F_9 ( V_14 ) ) ;
if ( ! V_21 ) {
F_7 ( & V_12 -> V_19 , L_3 ) ;
return - V_20 ;
}
V_15 = F_10 ( & V_12 -> V_19 , NULL ) ;
if ( F_11 ( V_15 ) ) {
F_7 ( & V_12 -> V_19 , L_4 ) ;
return F_12 ( V_15 ) ;
}
V_2 = F_13 ( V_15 ) ;
if ( V_23 ) {
F_14 ( ( V_24 ) V_23 , V_16 ) ;
F_7 ( & V_12 -> V_19 ,
L_5 ,
V_23 , V_16 ) ;
return - V_25 ;
}
V_23 = F_1 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
V_23 = NULL ;
return 0 ;
}
