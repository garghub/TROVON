void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
void * V_7 = NULL ;
static struct V_8 T_2 V_9 = {
. V_10 = L_1 ,
. V_11 = V_12 ,
} ;
F_2 ( L_2 ,
V_2 -> V_10 , V_2 -> V_13 ) ;
if ( V_4 != NULL )
V_7 = V_4 -> V_14 ( V_2 ) ;
if ( F_3 () )
return;
V_6 = F_4 ( V_2 -> V_10 , 0 ) ;
if ( V_6 == NULL ) {
F_5 ( L_3 ,
V_2 -> V_10 ) ;
return;
}
T_2 . V_15 = V_2 -> V_13 ;
F_6 ( V_6 , & T_2 , 1 ) ;
V_6 -> V_4 . V_16 = V_7 ;
F_7 ( V_6 ) ;
}
