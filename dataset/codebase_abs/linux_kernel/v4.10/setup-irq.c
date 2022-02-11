void __weak F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_2 , L_1 , V_3 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 (* F_5)( struct V_1 * , T_1 * ) ,
int (* F_6)( const struct V_1 * , T_1 , T_1 ) )
{
T_1 V_5 , V_6 ;
int V_3 = 0 ;
F_7 ( V_2 , V_7 , & V_5 ) ;
if ( V_5 > 4 )
V_5 = 1 ;
if ( V_5 != 0 ) {
V_6 = (* F_5)( V_2 , & V_5 ) ;
V_3 = (* F_6)( V_2 , V_6 , V_5 ) ;
if ( V_3 == - 1 )
V_3 = 0 ;
}
V_2 -> V_3 = V_3 ;
F_2 ( & V_2 -> V_2 , L_2 , V_2 -> V_3 ) ;
F_1 ( V_2 , V_3 ) ;
}
void F_8 ( T_1 (* F_5)( struct V_1 * , T_1 * ) ,
int (* F_6)( const struct V_1 * , T_1 , T_1 ) )
{
struct V_1 * V_2 = NULL ;
F_9 (dev)
F_4 ( V_2 , F_5 , F_6 ) ;
}
