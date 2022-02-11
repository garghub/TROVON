int T_1 F_1 ( void )
{
int V_1 = 0 ;
F_2 ( L_1 ,
( F_3 ( & V_2 -> V_3 ) & V_4 ) ?
L_2 : L_3 ) ;
if ( F_3 ( & V_2 -> V_5 ) & V_6 ) {
V_1 = V_7 * 20 / 6 ;
if ( ! ( F_3 ( & V_2 -> V_3 ) & V_4 ) )
V_1 /= 2 ;
F_4 ( V_8 L_4 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
} else {
F_4 ( V_8 L_5 ) ;
V_1 = - 1 ;
}
F_4 ( V_8 L_6 ) ;
return V_1 ;
}
void T_1 F_5 ( void )
{
unsigned int V_1 = V_7 * 20 / 6 ;
F_2 ( L_7 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
}
int T_1 F_6 ( const struct V_9 * V_10 , T_2 V_11 )
{
if ( F_7 ( V_10 -> V_12 -> V_13 ) == V_14 ) {
switch ( V_11 ) {
case F_8 ( 31 ) :
if ( F_3 ( & V_2 -> V_5 ) &
V_15 )
return V_16 + F_9 ( 0 ) ;
break;
case F_8 ( 30 ) :
if ( F_3 ( & V_2 -> V_5 ) &
V_17 )
return V_16 + F_9 ( 1 ) ;
break;
}
return 0 ;
}
return - 1 ;
}
int T_1 F_10 ( const struct V_9 * V_10 , T_2 V_11 , T_2 V_18 )
{
int V_19 = F_6 ( V_10 , V_11 ) ;
if ( V_19 >= 0 )
return V_19 ;
V_19 = V_18 ;
V_19 -- ;
V_19 = ( V_19 + 33 - V_11 ) % 4 ;
V_19 ++ ;
switch ( V_19 ) {
case 1 :
V_19 = V_16 + V_20 ;
break;
case 2 :
V_19 = V_16 + V_21 ;
break;
case 3 :
V_19 = V_16 + V_22 ;
break;
case 4 :
V_19 = V_16 + V_23 ;
break;
}
return V_19 ;
}
void T_1 F_11 ( void )
{
if ( F_12 ( V_16 + V_24 ,
V_25 ,
V_26 , L_8 ,
( void * ) V_27 ) )
F_13 ( L_9 ) ;
}
