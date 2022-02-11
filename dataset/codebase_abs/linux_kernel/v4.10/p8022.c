static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char * V_5 )
{
F_2 ( V_2 -> V_6 , V_4 , V_5 , V_2 -> V_6 -> V_7 . V_8 ) ;
return 0 ;
}
struct V_1 * F_3 ( unsigned char type ,
int (* F_4)( struct V_3 * V_4 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_9 * V_13 ) )
{
struct V_1 * V_14 ;
V_14 = F_5 ( sizeof( * V_14 ) , V_15 ) ;
if ( V_14 ) {
V_14 -> type [ 0 ] = type ;
V_14 -> V_16 = 3 ;
V_14 -> V_17 = F_1 ;
V_14 -> V_6 = F_6 ( type , F_4 ) ;
if ( ! V_14 -> V_6 ) {
F_7 ( V_14 ) ;
V_14 = NULL ;
}
}
return V_14 ;
}
void F_8 ( struct V_1 * V_14 )
{
F_9 ( V_14 -> V_6 ) ;
F_7 ( V_14 ) ;
}
