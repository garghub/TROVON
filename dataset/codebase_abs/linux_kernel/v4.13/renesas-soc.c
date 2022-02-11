static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
void T_2 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned int V_14 ;
V_6 = F_2 ( V_15 , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
V_8 = V_6 -> V_18 ;
V_4 = V_8 -> V_4 ;
V_13 = F_3 ( NULL , NULL , L_1 ) ;
if ( V_13 ) {
V_9 = F_4 ( V_13 , 0 ) ;
F_5 ( V_13 ) ;
} else if ( V_8 -> V_19 ) {
V_9 = F_6 ( V_4 -> V_20 , 4 ) ;
}
if ( V_9 ) {
V_14 = F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
if ( V_8 -> V_19 && ( ( V_14 >> 8 ) & 0xff ) != V_8 -> V_19 ) {
F_9 ( L_2 , V_14 ) ;
return - V_17 ;
}
}
V_2 = F_10 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_22 ;
V_13 = F_11 ( L_3 ) ;
F_12 ( V_13 , L_4 , & V_2 -> V_23 ) ;
F_5 ( V_13 ) ;
V_2 -> V_4 = F_13 ( V_4 -> V_24 , V_21 ) ;
V_2 -> V_25 = F_13 ( strchr ( V_6 -> V_26 , ',' ) + 1 ,
V_21 ) ;
if ( V_9 )
V_2 -> V_27 = F_14 ( V_21 , L_5 ,
( ( V_14 >> 4 ) & 0x0f ) + 1 ,
V_14 & 0xf ) ;
F_15 ( L_6 , V_2 -> V_4 ,
V_2 -> V_25 , V_2 -> V_27 ? : L_7 ) ;
V_11 = F_16 ( V_2 ) ;
if ( F_17 ( V_11 ) ) {
F_18 ( V_2 -> V_27 ) ;
F_19 ( V_2 -> V_25 ) ;
F_19 ( V_2 -> V_4 ) ;
F_18 ( V_2 ) ;
return F_20 ( V_11 ) ;
}
return 0 ;
}
