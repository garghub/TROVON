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
unsigned int V_1 = V_7 * 20 / 6 ;
F_2 ( L_7 ,
( V_1 + 50000 ) / 1000000 ,
( ( V_1 + 50000 ) / 100000 ) % 10 ) ;
}
int F_6 ( const struct V_8 * V_9 , T_2 V_10 )
{
if ( F_7 ( V_9 -> V_11 -> V_12 ) == V_13 ) {
switch ( V_10 ) {
case F_8 ( 31 ) :
if ( F_3 ( & V_2 -> V_5 ) &
V_14 )
return V_15 + F_9 ( 0 ) ;
break;
case F_8 ( 30 ) :
if ( F_3 ( & V_2 -> V_5 ) &
V_16 )
return V_15 + F_9 ( 1 ) ;
break;
}
return 0 ;
}
return - 1 ;
}
int F_10 ( const struct V_8 * V_9 , T_2 V_10 , T_2 V_17 )
{
int V_18 = F_6 ( V_9 , V_10 ) ;
if ( V_18 >= 0 )
return V_18 ;
V_18 = V_17 ;
V_18 -- ;
V_18 = ( V_18 + 33 - V_10 ) % 4 ;
V_18 ++ ;
switch ( V_18 ) {
case 1 :
V_18 = V_15 + V_19 ;
break;
case 2 :
V_18 = V_15 + V_20 ;
break;
case 3 :
V_18 = V_15 + V_21 ;
break;
case 4 :
V_18 = V_15 + V_22 ;
break;
}
return V_18 ;
}
void T_1 F_11 ( void )
{
if ( F_12 ( V_15 + V_23 ,
V_24 ,
0 , L_8 ,
( void * ) V_25 ) )
F_13 ( L_9 ) ;
}
