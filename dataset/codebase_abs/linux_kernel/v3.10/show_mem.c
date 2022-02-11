void F_1 ( unsigned int V_1 )
{
T_1 * V_2 ;
unsigned long V_3 = 0 , V_4 = 0 , V_5 = 0 ,
V_6 = 0 , V_7 = 0 ;
F_2 ( L_1 ) ;
F_3 ( V_1 ) ;
if ( V_1 & V_8 )
return;
F_4 (pgdat) {
unsigned long V_9 , V_10 ;
F_5 ( V_2 , & V_10 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_11 ; V_9 ++ ) {
struct V_12 * V_12 ;
unsigned long V_13 = V_2 -> V_14 + V_9 ;
if ( F_6 ( ! ( V_9 % V_15 ) ) )
F_7 () ;
if ( ! F_8 ( V_13 ) )
continue;
V_12 = F_9 ( V_13 ) ;
if ( F_10 ( V_12 ) )
V_7 ++ ;
if ( F_11 ( V_12 ) )
V_4 ++ ;
else if ( F_12 ( V_12 ) == 1 )
V_6 ++ ;
else if ( F_12 ( V_12 ) > 1 )
V_5 += F_12 ( V_12 ) - 1 ;
V_3 ++ ;
}
F_13 ( V_2 , & V_10 ) ;
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
