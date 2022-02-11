static int F_1 ( T_1 V_1 , T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( ( V_1 == V_4 [ V_3 ] . V_5 ) &&
( V_2 == V_4 [ V_3 ] . V_6 ) )
return V_3 ;
}
return - 1 ;
}
unsigned long F_3 ( void )
{
T_2 V_7 , V_8 , V_9 , V_10 , V_11 ;
unsigned long V_12 ;
int V_13 ;
V_13 = F_1 ( V_14 . V_15 , V_14 . V_6 ) ;
if ( V_13 < 0 )
return 0 ;
if ( V_4 [ V_13 ] . V_16 ) {
F_4 ( V_17 , V_7 , V_8 ) ;
V_9 = ( V_7 >> 8 ) & 0x1f ;
} else {
F_4 ( V_18 , V_7 , V_8 ) ;
V_9 = ( V_8 >> 8 ) & 0x1f ;
}
F_5 ( L_1 , V_9 ) ;
if ( ! V_9 )
goto V_19;
F_4 ( V_20 , V_7 , V_8 ) ;
V_10 = V_7 & 0x7 ;
V_11 = F_6 ( V_13 , V_10 ) ;
F_5 ( L_2 ,
V_10 , V_11 ) ;
if ( ! V_11 )
goto V_19;
V_12 = V_11 * V_9 ;
F_5 ( L_3 , V_12 ) ;
#ifdef F_7
V_21 = ( V_11 * 1000 ) / V_22 ;
F_5 ( L_4 , V_21 ) ;
#endif
return V_12 ;
V_19:
F_8 ( L_5 ) ;
return 0 ;
}
