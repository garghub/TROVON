int F_1 ( T_1 V_1 , const char * V_2 , void * V_3 ,
T_1 V_4 , T_1 V_5 )
{
char * V_6 ;
if ( ! V_3 ) {
F_2
( L_1 ) ;
return - 1 ;
}
if ( V_1 >= V_7 ) {
F_2 ( L_2 ) ;
return - 1 ;
}
if ( V_4 < V_8 ) {
F_2
( L_3 ) ;
return - 1 ;
}
if ( ( ( unsigned long ) V_3 & ( V_9 - 1 ) ) != 0 ) {
F_2
( L_4 ) ;
return - 1 ;
}
V_10 [ V_1 ] . V_2 = V_2 ;
V_10 [ V_1 ] . V_11 = V_4 ;
V_10 [ V_1 ] . V_12 = V_5 ;
V_10 [ V_1 ] . V_13 = V_3 ;
V_6 = ( char * ) V_3 ;
while ( V_5 -- ) {
F_3 ( V_6 , V_1 , 0 ) ;
V_6 += V_4 ;
}
return 0 ;
}
T_1 F_4 ( T_1 V_1 )
{
T_1 V_14 = 0 ;
T_1 V_15 = 0 ;
T_1 V_13 = F_5 ( V_10 [ V_1 ] . V_13 ) ;
T_1 V_16 =
V_13 +
V_10 [ V_1 ] . V_11 *
V_10 [ V_1 ] . V_12 ;
void * V_6 ;
T_1 V_17 ;
V_15 = 0 ;
do {
V_6 = F_6 ( V_1 ) ;
if ( V_6 )
V_17 = F_5 ( V_6 ) ;
else
V_17 = 0 ;
if ( V_17 ) {
if ( ( V_17 >= V_13 ) && ( V_17 < V_16 ) &&
( ( ( V_17 -
V_13 ) % V_10 [ V_1 ] . V_11 ) == 0 ) ) {
V_15 ++ ;
} else {
F_2
( L_5 ,
( unsigned long long ) V_17 ,
V_10 [ V_1 ] . V_2 , ( int ) V_1 ) ;
V_14 ++ ;
}
}
} while ( V_17 );
#ifdef F_7
if ( V_1 == 0 )
F_8 () ;
#endif
if ( V_14 ) {
F_2
( L_6 ,
V_10 [ V_1 ] . V_2 , ( int ) V_1 ,
( unsigned long long ) V_13 , ( unsigned long long ) V_16 ,
( unsigned long long ) V_10 [ V_1 ] . V_11 ) ;
return - V_14 ;
} else
return 0 ;
}
T_1 F_9 ( T_1 V_1 )
{
switch ( V_1 ) {
case 0 :
return V_18 ;
case 1 :
return V_19 ;
case 2 :
return V_20 ;
case 3 :
return V_21 ;
case 4 :
return V_22 ;
case 5 :
return V_23 ;
case 6 :
return V_24 ;
case 7 :
return V_25 ;
default:
return 0 ;
}
}
