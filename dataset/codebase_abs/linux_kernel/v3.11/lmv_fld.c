int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 * V_5 )
{
int V_6 ;
V_7 ;
F_2 ( ( F_3 ( F_4 ( V_4 ) ) ||
F_5 ( F_4 ( V_4 ) ) ) &&
F_6 ( V_4 ) , V_8 L_1 , F_7 ( V_4 ) ) ;
V_6 = F_8 ( & V_2 -> V_9 , F_4 ( V_4 ) , V_5 ,
V_10 , NULL ) ;
if ( V_6 ) {
F_9 ( L_2 V_11
L_3 , F_4 ( V_4 ) , V_6 ) ;
RETURN ( V_6 ) ;
}
F_10 ( V_12 , L_4 V_8 L_5 ,
* V_5 , F_7 ( V_4 ) ) ;
if ( * V_5 >= V_2 -> V_13 . V_14 ) {
F_9 ( L_6
L_7 V_8 L_5 , * V_5 , V_2 -> V_13 . V_14 ,
F_7 ( V_4 ) ) ;
V_6 = - V_15 ;
}
RETURN ( V_6 ) ;
}
