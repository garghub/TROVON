static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
}
void T_1 F_5 ( void )
{
int V_5 = V_4 ;
int V_6 ;
F_4 ( 0x00000f00 ) ;
for ( V_6 = V_5 ; V_6 < V_5 + 4 ; V_6 ++ )
F_6 ( V_6 , & V_7 ,
V_8 ) ;
}
