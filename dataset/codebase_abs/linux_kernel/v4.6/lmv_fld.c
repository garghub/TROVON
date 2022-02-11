int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 * V_5 )
{
int V_6 ;
F_2 ( ( F_3 ( F_4 ( V_4 ) ) ||
F_5 ( F_4 ( V_4 ) ) ) &&
F_6 ( V_4 ) , V_7 L_1 , F_7 ( V_4 ) ) ;
V_6 = F_8 ( & V_2 -> V_8 , F_4 ( V_4 ) , V_5 ,
V_9 , NULL ) ;
if ( V_6 ) {
F_9 ( L_2 ,
F_4 ( V_4 ) , V_6 ) ;
return V_6 ;
}
F_10 ( V_10 , L_3 V_7 L_4 ,
* V_5 , F_7 ( V_4 ) ) ;
if ( * V_5 >= V_2 -> V_11 . V_12 ) {
F_9 ( L_5 V_7 L_4 , * V_5 , V_2 -> V_11 . V_12 ,
F_7 ( V_4 ) ) ;
V_6 = - V_13 ;
}
return V_6 ;
}
