void F_1 ( unsigned int V_1 )
{
T_1 * V_2 ;
unsigned long V_3 = 0 , V_4 = 0 , V_5 = 0 ,
V_6 = 0 , V_7 = 0 ;
F_2 ( L_1 ) ;
F_3 ( V_1 ) ;
F_4 (pgdat) {
unsigned long V_8 , V_9 ;
F_5 ( V_2 , & V_9 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_10 ; V_8 ++ ) {
struct V_11 * V_11 ;
unsigned long V_12 = V_2 -> V_13 + V_8 ;
if ( F_6 ( ! ( V_8 % V_14 ) ) )
F_7 () ;
if ( ! F_8 ( V_12 ) )
continue;
V_11 = F_9 ( V_12 ) ;
if ( F_10 ( V_11 ) )
V_7 ++ ;
if ( F_11 ( V_11 ) )
V_4 ++ ;
else if ( F_12 ( V_11 ) == 1 )
V_6 ++ ;
else if ( F_12 ( V_11 ) > 1 )
V_5 += F_12 ( V_11 ) - 1 ;
V_3 ++ ;
}
F_13 ( V_2 , & V_9 ) ;
}
F_2 ( L_2 , V_3 ) ;
#ifdef F_14
F_2 ( L_3 , V_7 ) ;
#endif
F_2 ( L_4 , V_4 ) ;
F_2 ( L_5 , V_5 ) ;
F_2 ( L_6 , V_6 ) ;
#ifdef F_15
F_2 ( L_7 ,
F_16 () ) ;
#endif
}
