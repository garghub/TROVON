static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_6 ;
while( V_5 -> V_7 ) {
V_5 = V_5 -> V_7 ;
}
if( V_5 -> V_8 ) {
V_5 -> V_7 = F_2 ( sizeof( struct V_4 ) , V_9 ) ;
if( ! V_5 -> V_7 ) {
F_3 ( V_10 L_1 ) ;
return 1 ;
}
V_5 = V_5 -> V_7 ;
}
F_3 ( V_11 L_2 ,
( unsigned long long ) V_2 -> V_8 . V_12 ) ;
V_5 -> V_8 = V_2 -> V_8 . V_12 ;
V_5 -> V_13 . V_14 = L_3 ;
V_5 -> V_13 . V_15 = V_16 ;
V_5 -> V_13 . V_12 = F_4 ( V_2 -> V_8 . V_12 + V_17 ) ;
V_5 -> V_13 . V_18 = F_4 ( V_2 -> V_8 . V_12 + V_19 ) - 1 ;
V_3 = F_5 ( V_2 , & V_5 -> V_13 ) ;
if( V_3 < 0 ) {
F_3 ( V_10 L_4 ,
__FILE__ , & V_5 -> V_13 ) ;
}
return 0 ;
}
void T_1 F_6 ( void )
{
F_7 ( & V_20 ) ;
}
