static T_1 int F_1 ( void )
{
F_2 ( L_1 ) ;
V_1 = F_3 ( & V_2 , L_2 ,
F_4 ( 0 ) , F_5 ( 0 ) ,
F_6 () ,
( V_3 & ~ V_4 ) |
V_5 | V_6 ,
V_7 ) ;
if ( F_7 ( V_1 ) )
F_8 ( L_3 ) ;
if ( F_9 ( V_1 , NULL , 0 , NULL , NULL ) < 0 )
F_8 ( L_4 ) ;
return 0 ;
}
static T_1 int F_10 ( void )
{
T_2 V_8 ;
const T_3 * V_9 , * V_10 ;
T_4 V_11 ;
F_2 ( L_5 ) ;
V_10 = V_12 ;
V_9 = V_13 ;
while ( V_9 < V_10 ) {
if ( V_10 - V_9 < 4 )
goto V_14;
if ( V_9 [ 0 ] != 0x30 &&
V_9 [ 1 ] != 0x82 )
goto V_14;
V_11 = ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ;
V_11 += 4 ;
if ( V_11 > V_10 - V_9 )
goto V_14;
V_8 = F_11 ( F_12 ( V_1 , 1 ) ,
L_6 ,
NULL ,
V_9 ,
V_11 ,
( V_3 & ~ V_4 ) |
V_5 ,
V_7 ) ;
if ( F_7 ( V_8 ) )
F_13 ( L_7 ,
F_14 ( V_8 ) ) ;
else
F_2 ( L_8 ,
F_15 ( V_8 ) -> V_15 ) ;
V_9 += V_11 ;
}
return 0 ;
V_14:
F_13 ( L_9 ) ;
return 0 ;
}
