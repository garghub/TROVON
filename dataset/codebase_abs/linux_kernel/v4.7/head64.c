static void T_1 F_1 ( void )
{
memset ( V_1 , 0 , sizeof( V_2 ) * ( V_3 - 1 ) ) ;
V_4 = 0 ;
F_2 ( F_3 ( V_1 ) ) ;
}
int T_1 F_4 ( unsigned long V_5 )
{
unsigned long V_6 = V_5 - V_7 ;
T_2 V_8 , * V_9 ;
T_3 V_10 , * V_11 ;
T_4 V_12 , * V_13 ;
if ( V_6 >= V_14 || F_5 () != F_3 ( V_1 ) )
return - 1 ;
V_15:
V_9 = & V_1 [ F_6 ( V_5 ) ] . V_8 ;
V_8 = * V_9 ;
if ( V_8 )
V_11 = ( T_3 * ) ( ( V_8 & V_16 ) + V_17 - V_18 ) ;
else {
if ( V_4 >= V_19 ) {
F_1 () ;
goto V_15;
}
V_11 = ( T_3 * ) V_20 [ V_4 ++ ] ;
memset ( V_11 , 0 , sizeof( * V_11 ) * V_21 ) ;
* V_9 = ( T_2 ) V_11 - V_17 + V_18 + V_22 ;
}
V_11 += F_7 ( V_5 ) ;
V_10 = * V_11 ;
if ( V_10 )
V_13 = ( T_4 * ) ( ( V_10 & V_16 ) + V_17 - V_18 ) ;
else {
if ( V_4 >= V_19 ) {
F_1 () ;
goto V_15;
}
V_13 = ( T_4 * ) V_20 [ V_4 ++ ] ;
memset ( V_13 , 0 , sizeof( * V_13 ) * V_23 ) ;
* V_11 = ( T_3 ) V_13 - V_17 + V_18 + V_22 ;
}
V_12 = ( V_6 & V_24 ) + V_25 ;
V_13 [ F_8 ( V_5 ) ] = V_12 ;
return 0 ;
}
static void T_1 F_9 ( void )
{
memset ( V_26 , 0 ,
( unsigned long ) V_27 - ( unsigned long ) V_26 ) ;
}
static unsigned long F_10 ( void )
{
unsigned long V_28 = V_29 . V_30 . V_28 ;
V_28 |= ( V_31 ) V_29 . V_32 << 32 ;
return V_28 ;
}
static void T_1 F_11 ( char * V_33 )
{
char * V_34 ;
unsigned long V_28 ;
memcpy ( & V_29 , V_33 , sizeof V_29 ) ;
F_12 ( & V_29 ) ;
V_28 = F_10 () ;
if ( V_28 ) {
V_34 = F_13 ( V_28 ) ;
memcpy ( V_35 , V_34 , V_36 ) ;
}
}
T_5 T_6 void T_1 F_14 ( char * V_33 )
{
int V_37 ;
F_15 ( V_38 < V_17 ) ;
F_15 ( V_38 - V_17 < V_39 ) ;
F_15 ( V_40 + V_39 > 2 * V_41 ) ;
F_15 ( ( V_17 & ~ V_24 ) != 0 ) ;
F_15 ( ( V_38 & ~ V_24 ) != 0 ) ;
F_15 ( ! ( V_38 > V_42 ) ) ;
F_15 ( ! ( ( ( V_43 - 1 ) & V_44 ) ==
( V_42 & V_44 ) ) ) ;
F_15 ( F_16 ( V_45 ) <= V_43 ) ;
F_17 () ;
F_1 () ;
F_9 () ;
F_18 ( V_46 ) ;
F_19 () ;
for ( V_37 = 0 ; V_37 < V_47 ; V_37 ++ )
F_20 ( V_37 , V_48 [ V_37 ] ) ;
F_21 ( ( const struct V_49 * ) & V_50 ) ;
F_11 ( F_13 ( V_33 ) ) ;
F_22 () ;
V_46 [ 511 ] = V_1 [ 511 ] ;
F_23 ( V_33 ) ;
}
void T_1 F_23 ( char * V_33 )
{
if ( ! V_29 . V_30 . V_51 )
F_11 ( F_13 ( V_33 ) ) ;
F_24 () ;
F_25 () ;
switch ( V_29 . V_30 . V_52 ) {
case V_53 :
F_26 () ;
break;
default:
break;
}
F_27 () ;
}
