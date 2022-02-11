int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( ! F_3 ( V_4 ) || ! ( F_4 ( F_5 ( V_4 ) ) ||
F_6 ( F_5 ( V_4 ) ) ) ) {
F_7 ( L_1 V_9 L_2 , V_7 -> V_10 , F_8 ( V_4 ) ) ;
return - V_11 ;
}
V_8 = F_9 ( & V_2 -> V_12 , F_5 ( V_4 ) , V_5 ,
V_13 , NULL ) ;
if ( V_8 ) {
F_7 ( L_3 ,
F_5 ( V_4 ) , V_8 ) ;
return V_8 ;
}
F_10 ( V_14 , L_4 V_9 L_2 ,
* V_5 , F_8 ( V_4 ) ) ;
if ( * V_5 >= V_2 -> V_15 . V_16 ) {
F_7 ( L_5 V_9 L_2 , * V_5 , V_2 -> V_15 . V_16 ,
F_8 ( V_4 ) ) ;
V_8 = - V_11 ;
}
return V_8 ;
}
