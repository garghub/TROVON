static T_1 int F_1 ( void )
{
F_2 ( L_1 ) ;
V_1 =
F_3 ( L_2 ,
F_4 ( 0 ) , F_5 ( 0 ) , F_6 () ,
( ( V_2 & ~ V_3 ) |
V_4 | V_5 | V_6 ) ,
V_7 , NULL ) ;
if ( F_7 ( V_1 ) )
F_8 ( L_3 ) ;
F_9 ( V_8 , & V_1 -> V_9 ) ;
return 0 ;
}
static T_1 int F_10 ( void )
{
T_2 V_10 ;
const T_3 * V_11 , * V_12 ;
T_4 V_13 ;
F_2 ( L_4 ) ;
V_11 = V_14 ;
V_12 = V_11 + V_15 ;
while ( V_11 < V_12 ) {
if ( V_12 - V_11 < 4 )
goto V_16;
if ( V_11 [ 0 ] != 0x30 &&
V_11 [ 1 ] != 0x82 )
goto V_16;
V_13 = ( V_11 [ 2 ] << 8 ) | V_11 [ 3 ] ;
V_13 += 4 ;
if ( V_13 > V_12 - V_11 )
goto V_16;
V_10 = F_11 ( F_12 ( V_1 , 1 ) ,
L_5 ,
NULL ,
V_11 ,
V_13 ,
( ( V_2 & ~ V_3 ) |
V_4 | V_5 ) ,
V_7 |
V_17 ) ;
if ( F_7 ( V_10 ) ) {
F_13 ( L_6 ,
F_14 ( V_10 ) ) ;
} else {
F_9 ( V_18 , & F_15 ( V_10 ) -> V_9 ) ;
F_2 ( L_7 ,
F_15 ( V_10 ) -> V_19 ) ;
F_16 ( V_10 ) ;
}
V_11 += V_13 ;
}
return 0 ;
V_16:
F_13 ( L_8 ) ;
return 0 ;
}
