extern T_1 F_1 ( T_2 * T_3 V_1 ) {
return 0 ;
}
extern T_4 * F_2 ( T_2 * T_3 V_1 ) {
return NULL ;
}
extern T_5 * F_3 ( T_6 * V_2 ,
T_7 * V_3 ,
int V_4 ,
int V_5 ,
T_8 * V_6 ,
void * V_7 ) {
T_5 * V_8 = F_4 ( F_5 () , T_5 ) ;
V_8 -> V_7 = V_7 ;
V_8 -> V_9 = F_6 ( V_3 , V_4 , V_5 , V_8 , V_6 ) ;
V_8 -> V_10 = F_7 ( F_5 () ) ;
F_8 ( V_8 -> V_10 , V_2 ) ;
return V_8 ;
}
