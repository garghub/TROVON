int T_1 F_1 ( void )
{
int V_1 = 0 ;
F_2 ( L_1 ,
( F_3 ( & V_2 -> V_3 ) & V_4 ) ?
L_2 : L_3 ) ;
if ( F_3 ( & V_2 -> V_5 ) & V_6 ) {
T_2 V_3 = F_3 ( & V_2 -> V_3 ) ;
switch ( ( unsigned long ) V_3 &
V_7 ) {
case V_8 :
V_1 = V_9 * 2 / 5 ; break;
case V_10 :
V_1 = V_9 / 3 ; break;
case V_11 :
V_1 = V_9 / 5 ; break;
case V_12 :
V_1 = V_9 / 6 ; break;
}
F_4 ( L_4 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
} else {
F_4 ( L_5 ) ;
V_1 = - 1 ;
}
F_4 ( L_6 ) ;
return V_1 ;
}
int T_1 F_5 ( void )
{
int V_1 ;
F_6 ( V_4 ) ;
if ( F_3 ( & V_2 -> V_5 ) & V_6 ) {
unsigned int V_13 = 0 ;
T_2 V_3 = F_3 ( & V_2 -> V_3 ) ;
V_13 = ( unsigned long ) V_3 &
V_7 ;
switch ( V_13 ) {
case V_11 :
case V_8 :
V_13 = V_8 ;
V_1 = V_9 * 2 / 5 ;
break;
case V_12 :
case V_10 :
default:
V_13 = V_10 ;
V_1 = V_9 / 3 ;
}
F_7 ( V_7 ,
V_13 ) ;
F_8 ( L_7 ,
( unsigned long ) F_3 ( & V_2 -> V_3 ) ) ;
} else
V_1 = - 1 ;
return V_1 ;
}
void T_1 F_9 ( void )
{
if ( F_10 ( V_14 + V_15 ,
V_16 ,
0 , L_8 ,
( void * ) V_17 ) )
F_11 ( L_9 ) ;
}
