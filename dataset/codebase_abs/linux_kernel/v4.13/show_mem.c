void F_1 ( unsigned int V_1 , T_1 * V_2 )
{
T_2 * V_3 ;
unsigned long V_4 = 0 , V_5 = 0 , V_6 = 0 ;
F_2 ( L_1 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 (pgdat) {
unsigned long V_7 ;
int V_8 ;
F_5 ( V_3 , & V_7 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
struct V_10 * V_10 = & V_3 -> V_11 [ V_8 ] ;
if ( ! F_6 ( V_10 ) )
continue;
V_4 += V_10 -> V_12 ;
V_5 += V_10 -> V_12 - V_10 -> V_13 ;
if ( F_7 ( V_8 ) )
V_6 += V_10 -> V_12 ;
}
F_8 ( V_3 , & V_7 ) ;
}
F_2 ( L_2 , V_4 ) ;
F_2 ( L_3 , V_6 ) ;
F_2 ( L_4 , V_5 ) ;
#ifdef F_9
F_2 ( L_5 , V_14 ) ;
#endif
#ifdef F_10
F_2 ( L_6 ,
F_11 () ) ;
#endif
#ifdef F_12
F_2 ( L_7 , F_13 ( & V_15 ) ) ;
#endif
}
