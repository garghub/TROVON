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
V_1 = V_9 / 4 ; break;
case V_10 :
V_1 = V_9 * 2 / 9 ; break;
case V_11 :
V_1 = V_9 / 5 ; break;
case V_12 :
V_1 = V_9 * 2 / 11 ; break;
case V_13 :
V_1 = V_9 / 8 ; break;
case V_14 :
V_1 = V_9 / 9 ; break;
case V_15 :
V_1 = V_9 / 10 ; break;
case V_16 :
V_1 = V_9 / 11 ; break;
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
void T_1 F_5 ( void )
{
T_3 V_3 = F_3 ( & V_2 -> V_3 ) ;
unsigned int V_1 =
V_17 / ( ( V_3 & V_18 ) ? 4 : 2 ) ;
F_2 ( L_7 ,
( V_3 & V_19 ) ? L_8 : L_3 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
}
int T_1 F_6 ( void )
{
int V_1 ;
F_7 ( V_4 ) ;
if ( F_3 ( & V_2 -> V_5 ) & V_6 ) {
unsigned int V_20 = 0 ;
T_2 V_3 = F_3 ( & V_2 -> V_3 ) ;
V_20 = ( unsigned long ) V_3 &
V_7 ;
switch ( V_20 ) {
case V_13 :
case V_8 :
V_20 = V_8 ;
V_1 = V_9 / 4 ;
break;
case V_14 :
case V_10 :
V_20 = V_10 ;
V_1 = V_9 * 2 / 9 ;
break;
case V_15 :
case V_11 :
V_20 = V_11 ;
V_1 = V_9 / 5 ;
break;
case V_16 :
case V_12 :
default:
V_20 = V_12 ;
V_1 = V_9 * 2 / 11 ;
break;
}
F_8 ( V_7 ,
V_20 ) ;
F_9 ( L_9 ,
( unsigned long ) F_3 ( & V_2 -> V_3 ) ) ;
} else
V_1 = - 1 ;
return V_1 ;
}
int T_1 F_10 ( const struct V_21 * V_22 , T_4 V_23 )
{
if ( F_11 ( V_22 -> V_24 -> V_25 ) == V_26 ) {
switch ( V_23 ) {
case F_12 ( 31 ) :
if ( F_3 ( & V_2 -> V_5 ) &
V_27 )
return V_28 + V_29 ;
break;
case F_12 ( 30 ) :
if ( F_3 ( & V_2 -> V_5 ) &
V_30 )
return V_28 + V_31 ;
break;
}
return 0 ;
}
return - 1 ;
}
void T_1 F_13 ( void )
{
if ( F_14 ( V_28 + V_32 ,
V_33 ,
0 , L_10 ,
( void * ) V_34 ) )
F_15 ( L_11 ) ;
}
