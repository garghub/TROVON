static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_3 () ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_6 () ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_8 () ;
F_9 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_10 ( V_5 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_8 () ;
F_9 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_10 ( V_5 ) ;
F_4 ( V_2 ) ;
}
void T_1 F_12 ( void )
{
int V_6 = V_4 ;
int V_7 ;
F_5 ( V_8 ) ;
F_9 ( V_9 ) ;
if ( V_10 )
for ( V_7 = V_6 ; V_7 < V_6 + 2 ; V_7 ++ )
F_13 ( V_7 , & V_11 ,
V_12 ) ;
for ( V_7 = V_6 + 2 ; V_7 < V_6 + 8 ; V_7 ++ )
F_13 ( V_7 , & V_13 ,
V_12 ) ;
}
