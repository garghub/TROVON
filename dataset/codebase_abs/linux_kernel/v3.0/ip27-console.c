static inline struct V_1 * F_1 ( void )
{
struct V_2 * V_2 ;
T_1 V_3 ;
V_3 = ( V_4 == V_5 ) ? F_2 () : V_4 ;
V_2 = (struct V_2 * ) F_3 ( V_3 ) -> V_6 ;
return & V_2 -> V_7 . V_8 ;
}
void T_2 F_4 ( char V_9 )
{
struct V_1 * V_10 = F_1 () ;
while ( ( V_10 -> V_11 & 0x20 ) == 0 ) ;
V_10 -> V_12 = V_9 ;
}
