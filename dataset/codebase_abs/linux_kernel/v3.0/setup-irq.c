static void T_1
F_1 ( struct V_1 * V_2 ,
T_2 (* F_2)( struct V_1 * , T_2 * ) ,
int (* F_3)( struct V_1 * , T_2 , T_2 ) )
{
T_2 V_3 , V_4 ;
int V_5 = 0 ;
F_4 ( V_2 , V_6 , & V_3 ) ;
if ( V_3 > 4 )
V_3 = 1 ;
if ( V_3 != 0 ) {
V_4 = (* F_2)( V_2 , & V_3 ) ;
V_5 = (* F_3)( V_2 , V_4 , V_3 ) ;
if ( V_5 == - 1 )
V_5 = 0 ;
}
V_2 -> V_5 = V_5 ;
F_5 ( & V_2 -> V_2 , L_1 , V_2 -> V_5 ) ;
F_6 ( V_2 , V_5 ) ;
}
void T_1
F_7 ( T_2 (* F_2)( struct V_1 * , T_2 * ) ,
int (* F_3)( struct V_1 * , T_2 , T_2 ) )
{
struct V_1 * V_2 = NULL ;
F_8 (dev)
F_1 ( V_2 , F_2 , F_3 ) ;
}
