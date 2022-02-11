unsigned long F_1 ( void )
{
unsigned long V_1 = V_2 ;
while ( F_2 ( V_1 , V_3 ) ) {
V_1 = F_3 ( V_3 , V_4 + 1 , V_1 ) ;
if ( V_1 > V_4 )
V_1 = 0 ;
}
V_2 = ( V_1 + 1 ) & V_4 ;
return V_1 ;
}
int F_4 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
V_8 -> V_9 . V_10 = F_1 () ;
return 0 ;
}
void F_5 ( unsigned long V_1 )
{
F_6 ( V_1 , V_3 ) ;
}
void F_7 ( struct V_7 * V_8 )
{
F_8 () ;
if ( V_8 -> V_9 . V_10 != V_11 ) {
F_5 ( V_8 -> V_9 . V_10 ) ;
V_8 -> V_9 . V_10 = V_11 ;
}
F_9 () ;
}
void T_1 F_10 ( void )
{
V_3 [ 0 ] = ( 1 << V_12 ) - 1 ;
V_2 = V_12 ;
}
