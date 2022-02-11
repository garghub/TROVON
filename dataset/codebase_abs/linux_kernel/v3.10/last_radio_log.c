static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
void F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( V_11 . V_8 ) {
F_4 ( L_1 , V_12 ) ;
return;
}
V_5 = F_5 ( V_13 , & V_6 ) ;
if ( ! V_5 ) {
F_4 ( L_2 , V_12 ) ;
return;
}
V_10 = F_6 ( L_3 , V_14 , NULL ,
& V_11 ) ;
if ( ! V_10 ) {
F_4 ( L_4 ,
V_12 ) ;
return;
}
F_4 ( L_5 , V_12 ,
V_6 ) ;
V_11 . V_8 = V_8 ;
F_7 ( V_10 , V_6 ) ;
}
