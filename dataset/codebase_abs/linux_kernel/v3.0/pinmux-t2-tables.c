static inline unsigned long F_1 ( unsigned long V_1 )
{
return F_2 ( F_3 ( V_2 + V_1 ) ) ;
}
static inline void F_4 ( unsigned long V_3 , unsigned long V_1 )
{
F_5 ( V_3 , F_3 ( V_2 + V_1 ) ) ;
}
void F_6 ( void )
{
unsigned int V_4 ;
T_1 * V_5 = V_6 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
* V_5 ++ = F_1 ( V_8 + V_4 * 4 ) ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ )
* V_5 ++ = F_1 ( V_10 + V_4 * 4 ) ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ )
* V_5 ++ = F_1 ( V_12 + V_4 * 4 ) ;
for ( V_4 = 0 ; V_4 < F_7 ( V_13 ) ; V_4 ++ )
* V_5 ++ = F_1 ( V_13 [ V_4 ] . V_14 ) ;
}
void F_8 ( void )
{
unsigned int V_4 ;
T_1 * V_5 = V_6 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
F_4 ( * V_5 ++ , V_8 + V_4 * 4 ) ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ )
F_4 ( * V_5 ++ , V_10 + V_4 * 4 ) ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ )
F_4 ( * V_5 ++ , V_12 + V_4 * 4 ) ;
for ( V_4 = 0 ; V_4 < F_7 ( V_13 ) ; V_4 ++ )
F_4 ( * V_5 ++ , V_13 [ V_4 ] . V_14 ) ;
}
