static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x1000 << ( V_2 -> V_3 - V_4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( 0x1000 << ( V_2 -> V_3 - V_4 ) ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
F_6 ( V_5 ) ;
F_1 ( V_2 ) ;
F_7 ( V_5 ) ;
}
static void F_8 ( void * args )
{
F_5 ( args ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
F_10 ( F_8 , V_2 , 1 ) ;
return 0 ;
}
static void F_11 ( void * args )
{
unsigned long V_5 ;
F_6 ( V_5 ) ;
F_3 ( args ) ;
F_7 ( V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_10 ( F_11 , V_2 , 1 ) ;
}
void T_1 F_13 ( void )
{
int V_6 = V_4 ;
int V_7 ;
F_4 ( 0x0000f000 ) ;
for ( V_7 = V_6 ; V_7 < V_6 + 4 ; V_7 ++ )
F_14 ( V_7 , & V_8 ,
V_9 ) ;
V_10 = V_6 + 1 ;
F_14 ( V_10 , & V_11 ,
V_12 ) ;
}
