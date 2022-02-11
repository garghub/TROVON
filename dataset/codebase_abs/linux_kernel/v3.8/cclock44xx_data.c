int T_1 F_1 ( void )
{
T_2 V_1 ;
struct V_2 * V_3 ;
int V_4 ;
if ( F_2 () ) {
V_5 = V_6 ;
V_1 = V_7 ;
} else if ( F_3 () || F_4 () ) {
V_5 = V_8 | V_6 ;
V_1 = V_9 | V_7 ;
if ( F_4 () )
F_5 ( L_1 ) ;
} else {
return 0 ;
}
for ( V_3 = V_10 ; V_3 < V_10 + F_6 ( V_10 ) ;
V_3 ++ ) {
if ( V_3 -> V_11 & V_1 ) {
F_7 ( & V_3 -> V_12 ) ;
if ( ! F_8 ( NULL , V_3 -> V_12 . V_13 ) )
F_9 ( V_3 -> V_12 . V_13 ) ;
}
}
F_10 () ;
F_11 ( V_14 ,
F_6 ( V_14 ) ) ;
V_4 = F_12 ( & V_15 , & V_16 ) ;
if ( ! V_4 )
V_4 = F_13 ( & V_17 , V_18 ) ;
if ( V_4 )
F_14 ( L_2 , V_19 ) ;
return 0 ;
}
