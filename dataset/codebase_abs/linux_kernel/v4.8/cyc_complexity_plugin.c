static unsigned int F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
V_1 = F_2 ( V_3 ) - F_3 ( V_3 ) + 2 ;
V_2 = F_4 ( F_5 ( V_4 ) ) ;
fprintf ( V_5 , L_1 , V_1 ,
V_2 . V_6 , F_6 ( V_4 ) ) ;
return 0 ;
}
int F_7 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
const char * const V_11 = V_8 -> V_12 ;
struct V_13 V_14 ;
V_14 . V_15 = F_8 () ;
V_14 . V_16 = L_2 ;
V_14 . V_17 = 1 ;
V_14 . V_18 = V_19 ;
if ( ! F_9 ( V_10 , & V_20 ) ) {
error ( F_10 ( L_3 ) ) ;
return 1 ;
}
F_11 ( V_11 , V_21 , NULL ,
& V_22 ) ;
F_11 ( V_11 , V_23 , NULL ,
& V_14 ) ;
return 0 ;
}
