int T_1 F_1 ( void )
{
int V_1 = 0 ;
F_2 ( V_2 L_1 ,
( F_3 ( & V_3 -> V_4 ) & V_5 ) ?
L_2 : L_3 ) ;
if ( F_3 ( & V_3 -> V_6 ) & V_7 ) {
T_2 V_4 = F_3 ( & V_3 -> V_4 ) ;
switch ( ( unsigned long ) V_4 &
V_8 ) {
case V_9 :
V_1 = V_10 * 2 / 5 ; break;
case V_11 :
V_1 = V_10 / 3 ; break;
case V_12 :
V_1 = V_10 / 5 ; break;
case V_13 :
V_1 = V_10 / 6 ; break;
}
F_2 ( L_4 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
} else {
F_2 ( L_5 ) ;
V_1 = - 1 ;
}
F_2 ( L_6 ) ;
return V_1 ;
}
int T_1 F_4 ( void )
{
int V_1 ;
F_5 ( V_5 ) ;
if ( F_3 ( & V_3 -> V_6 ) & V_7 ) {
unsigned int V_14 = 0 ;
T_2 V_4 = F_3 ( & V_3 -> V_4 ) ;
V_14 = ( unsigned long ) V_4 &
V_8 ;
switch ( V_14 ) {
case V_12 :
case V_9 :
V_14 = V_9 ;
V_1 = V_10 * 2 / 5 ;
break;
case V_13 :
case V_11 :
default:
V_14 = V_11 ;
V_1 = V_10 / 3 ;
}
F_6 ( V_8 ,
V_14 ) ;
F_2 ( V_15 L_7 ,
( unsigned long ) F_3 ( & V_3 -> V_4 ) ) ;
} else
V_1 = - 1 ;
return V_1 ;
}
void T_1 F_7 ( void )
{
if ( F_8 ( V_16 + V_17 ,
V_18 ,
0 , L_8 ,
( void * ) V_19 ) )
F_2 ( V_20 L_9 ) ;
}
