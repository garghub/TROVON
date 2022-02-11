int F_1 ( int V_1 )
{
#if V_2 > 0
if ( F_2 ( V_3 ) || F_2 ( V_4 ) )
return 4 ;
else if ( F_2 ( V_5 )
&& ! F_2 ( V_6 ) )
return 4 ;
else if ( F_2 ( V_7 )
&& ! F_2 ( V_8 ) )
return 4 ;
#if 0
else if (OCTEON_IS_MODEL(OCTEON_CN31XX)
|| OCTEON_IS_MODEL(OCTEON_CN50XX))
return 2;
else if (OCTEON_IS_MODEL(OCTEON_CN30XX))
return 1;
#endif
#endif
return 0 ;
}
int F_3 ( int V_1 )
{
if ( ! F_2 ( V_9 ) &&
! F_2 ( V_4 ) ) {
int V_10 = F_4 ( V_1 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
union V_12 V_13 ;
int V_14 =
F_5 ( V_1 , V_11 ) ;
V_13 . V_15 =
F_6 ( F_7 ( V_14 ) ) ;
V_13 . V_16 . V_17 = 0 ;
V_13 . V_16 . V_18 = 0 ;
F_8 ( F_7 ( V_14 ) ,
V_13 . V_15 ) ;
}
}
return 0 ;
}
