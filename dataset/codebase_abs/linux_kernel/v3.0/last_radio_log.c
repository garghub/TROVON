static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_4 V_5 = * V_4 ;
T_1 V_6 ;
if ( V_5 >= V_7 )
return 0 ;
V_6 = F_2 ( V_3 , ( T_3 ) ( V_7 - V_5 ) ) ;
if ( F_3 ( V_2 , V_8 + V_5 , V_6 ) ) {
F_4 ( L_1 , V_9 ) ;
return - V_10 ;
}
* V_4 += V_6 ;
return V_6 ;
}
void F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
if ( V_15 . V_12 ) {
F_4 ( L_2 , V_9 ) ;
return;
}
V_8 = F_6 ( V_16 , & V_7 ) ;
if ( ! V_8 ) {
F_4 ( L_3 , V_9 ) ;
return;
}
V_14 = F_7 ( L_4 , V_17 | V_18 , NULL ) ;
if ( ! V_14 ) {
F_4 ( L_5 ,
V_9 ) ;
return;
}
F_4 ( L_6 , V_9 ,
V_7 ) ;
V_15 . V_12 = V_12 ;
V_14 -> V_19 = & V_15 ;
V_14 -> V_20 = V_7 ;
}
