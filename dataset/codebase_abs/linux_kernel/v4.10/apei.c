int F_1 ( struct V_1 * V_2 , void * V_3 )
{
#ifdef F_2
int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = (struct V_5 * ) V_2 ;
if ( ! V_6 -> V_9 )
return 0 ;
if ( ! ( V_6 -> V_10 & V_11 ) ||
! V_6 -> V_12 )
return 1 ;
F_3 ( L_1 ) ;
V_8 = (struct V_7 * ) ( V_6 + 1 ) ;
for ( V_4 = 0 ; V_4 < V_6 -> V_12 ; V_4 ++ , V_8 ++ )
F_4 ( V_8 -> V_13 ) ;
#endif
return 1 ;
}
void F_5 ( int V_14 , struct V_15 * V_16 )
{
#ifdef F_2
F_6 ( V_14 , V_16 ) ;
#endif
}
void F_7 ( unsigned long V_17 )
{
F_8 ( V_17 ) ;
}
