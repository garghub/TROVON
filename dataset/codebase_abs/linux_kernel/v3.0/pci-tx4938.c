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
V_1 = V_10 / 4 ; break;
case V_11 :
V_1 = V_10 * 2 / 9 ; break;
case V_12 :
V_1 = V_10 / 5 ; break;
case V_13 :
V_1 = V_10 * 2 / 11 ; break;
case V_14 :
V_1 = V_10 / 8 ; break;
case V_15 :
V_1 = V_10 / 9 ; break;
case V_16 :
V_1 = V_10 / 10 ; break;
case V_17 :
V_1 = V_10 / 11 ; break;
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
void T_1 F_4 ( void )
{
T_3 V_4 = F_3 ( & V_3 -> V_4 ) ;
unsigned int V_1 =
V_18 / ( ( V_4 & V_19 ) ? 4 : 2 ) ;
F_2 ( V_2 L_7 ,
( V_4 & V_20 ) ? L_8 : L_3 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
}
int T_1 F_5 ( void )
{
int V_1 ;
F_6 ( V_5 ) ;
if ( F_3 ( & V_3 -> V_6 ) & V_7 ) {
unsigned int V_21 = 0 ;
T_2 V_4 = F_3 ( & V_3 -> V_4 ) ;
V_21 = ( unsigned long ) V_4 &
V_8 ;
switch ( V_21 ) {
case V_14 :
case V_9 :
V_21 = V_9 ;
V_1 = V_10 / 4 ;
break;
case V_15 :
case V_11 :
V_21 = V_11 ;
V_1 = V_10 * 2 / 9 ;
break;
case V_16 :
case V_12 :
V_21 = V_12 ;
V_1 = V_10 / 5 ;
break;
case V_17 :
case V_13 :
default:
V_21 = V_13 ;
V_1 = V_10 * 2 / 11 ;
break;
}
F_7 ( V_8 ,
V_21 ) ;
F_2 ( V_22 L_9 ,
( unsigned long ) F_3 ( & V_3 -> V_4 ) ) ;
} else
V_1 = - 1 ;
return V_1 ;
}
int T_1 F_8 ( const struct V_23 * V_24 , T_4 V_25 )
{
if ( F_9 ( V_24 -> V_26 -> V_27 ) == V_28 ) {
switch ( V_25 ) {
case F_10 ( 31 ) :
if ( F_3 ( & V_3 -> V_6 ) &
V_29 )
return V_30 + V_31 ;
break;
case F_10 ( 30 ) :
if ( F_3 ( & V_3 -> V_6 ) &
V_32 )
return V_30 + V_33 ;
break;
}
return 0 ;
}
return - 1 ;
}
void T_1 F_11 ( void )
{
if ( F_12 ( V_30 + V_34 ,
V_35 ,
V_36 , L_10 ,
( void * ) V_37 ) )
F_2 ( V_38 L_11 ) ;
}
