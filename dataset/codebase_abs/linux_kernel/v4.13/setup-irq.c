void __weak F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_2 , L_1 , V_3 ) ;
F_3 ( V_2 , V_4 , V_3 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_1 V_6 = - 1 ;
int V_3 = 0 ;
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
if ( ! ( V_8 -> V_10 ) ) {
F_2 ( & V_2 -> V_2 , L_2 ) ;
return;
}
F_6 ( V_2 , V_11 , & V_5 ) ;
if ( V_5 > 4 )
V_5 = 1 ;
if ( V_5 ) {
if ( V_8 -> V_12 )
V_6 = ( * ( V_8 -> V_12 ) ) ( V_2 , & V_5 ) ;
V_3 = ( * ( V_8 -> V_10 ) ) ( V_2 , V_6 , V_5 ) ;
if ( V_3 == - 1 )
V_3 = 0 ;
}
V_2 -> V_3 = V_3 ;
F_2 ( & V_2 -> V_2 , L_3 , V_2 -> V_3 ) ;
F_1 ( V_2 , V_3 ) ;
}
void F_7 ( T_1 (* F_8)( struct V_1 * , T_1 * ) ,
int (* V_10)( const struct V_1 * , T_1 , T_1 ) )
{
struct V_1 * V_2 = NULL ;
struct V_7 * V_8 = NULL ;
F_9 (dev) {
V_8 = F_5 ( V_2 -> V_9 ) ;
V_8 -> V_12 = F_8 ;
V_8 -> V_10 = V_10 ;
F_4 ( V_2 ) ;
V_8 -> V_12 = NULL ;
V_8 -> V_10 = NULL ;
}
}
