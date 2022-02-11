static inline void
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_2 -> V_4 - 16 ) ;
F_4 ( & V_3 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( V_2 -> V_4 - 16 ) ;
F_4 ( & V_3 ) ;
}
void T_1
F_7 ( long V_5 , unsigned long V_6 )
{
long V_7 ;
if ( V_8 <= 16 )
return;
for ( V_7 = 16 ; V_7 < V_5 ; ++ V_7 ) {
if ( V_7 < 64 && ( ( V_6 >> V_7 ) & 1 ) )
continue;
F_8 ( V_7 , & V_9 , V_10 ) ;
F_9 ( V_7 , V_11 ) ;
}
}
void
F_10 ( unsigned long V_12 )
{
int V_4 = ( V_12 - 0x800 ) >> 4 ;
F_11 ( V_4 ) ;
}
