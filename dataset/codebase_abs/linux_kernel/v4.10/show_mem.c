void F_1 ( unsigned int V_1 )
{
T_1 * V_2 ;
unsigned long V_3 = 0 , V_4 = 0 , V_5 = 0 ;
F_2 ( L_1 ) ;
F_3 ( V_1 ) ;
F_4 (pgdat) {
unsigned long V_6 ;
int V_7 ;
F_5 ( V_2 , & V_6 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_9 * V_9 = & V_2 -> V_10 [ V_7 ] ;
if ( ! F_6 ( V_9 ) )
continue;
V_3 += V_9 -> V_11 ;
V_4 += V_9 -> V_11 - V_9 -> V_12 ;
if ( F_7 ( V_7 ) )
V_5 += V_9 -> V_11 ;
}
F_8 ( V_2 , & V_6 ) ;
}
F_2 ( L_2 , V_3 ) ;
F_2 ( L_3 , V_5 ) ;
F_2 ( L_4 , V_4 ) ;
#ifdef F_9
F_2 ( L_5 , V_13 ) ;
#endif
#ifdef F_10
F_2 ( L_6 ,
F_11 () ) ;
#endif
#ifdef F_12
F_2 ( L_7 , F_13 ( & V_14 ) ) ;
#endif
}
