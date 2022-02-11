static T_1 int F_1 ( void )
{
F_2 ( L_1 ) ;
V_1 = F_3 ( L_2 ,
F_4 ( 0 ) , F_5 ( 0 ) ,
F_6 () ,
( ( V_2 & ~ V_3 ) |
V_4 | V_5 ) ,
V_6 , NULL ) ;
if ( F_7 ( V_1 ) )
F_8 ( L_3 ) ;
return 0 ;
}
static T_1 int F_9 ( void )
{
T_2 V_7 ;
const T_3 * V_8 , * V_9 ;
T_4 V_10 ;
F_2 ( L_4 ) ;
V_9 = V_11 ;
V_8 = V_12 ;
while ( V_8 < V_9 ) {
if ( V_9 - V_8 < 4 )
goto V_13;
if ( V_8 [ 0 ] != 0x30 &&
V_8 [ 1 ] != 0x82 )
goto V_13;
V_10 = ( V_8 [ 2 ] << 8 ) | V_8 [ 3 ] ;
V_10 += 4 ;
if ( V_10 > V_9 - V_8 )
goto V_13;
V_7 = F_10 ( F_11 ( V_1 , 1 ) ,
L_5 ,
NULL ,
V_8 ,
V_10 ,
( V_2 & ~ V_3 ) |
V_4 ,
V_6 ) ;
if ( F_7 ( V_7 ) )
F_12 ( L_6 ,
F_13 ( V_7 ) ) ;
else
F_2 ( L_7 ,
F_14 ( V_7 ) -> V_14 ) ;
V_8 += V_10 ;
}
return 0 ;
V_13:
F_12 ( L_8 ) ;
return 0 ;
}
