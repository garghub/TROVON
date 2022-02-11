bool F_1 ( void )
{
bool V_1 = false , V_2 ;
T_1 V_3 ;
V_2 = F_2 ( V_4 , V_5 , V_6 ) ;
V_1 |= ! V_2 ;
if ( ! V_2 )
F_3 ( L_1 ) ;
V_2 = F_4 ( V_7 , V_8 , V_9 ) ;
V_1 |= ! V_2 ;
if ( ! V_2 )
F_3 ( L_2 ) ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
T_2 V_11 ;
F_5 ( V_12 , V_3 , & V_11 ) ;
if ( V_11 . V_13 ) {
F_3 ( L_3 , V_3 ) ;
V_1 = true ;
}
}
return ! V_1 ;
}
enum V_14 F_6 ( void )
{
#if F_7 ( V_15 )
T_3 V_16 = V_17 ;
#else
T_3 V_16 = V_18 ;
#endif
while ( ! F_2 ( V_4 , V_5 , V_6 ) &&
( ( F_8 ( V_19 ,
V_20 ) &
( 1U << ( V_16 + V_21 ) ) ) == 0 ) ) {
F_9 () ;
}
return V_22 ;
}
