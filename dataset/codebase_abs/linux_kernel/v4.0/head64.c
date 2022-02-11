static void T_1 F_1 ( void )
{
unsigned long V_1 ;
for ( V_1 = 0 ; V_1 < V_2 - 1 ; V_1 ++ )
V_3 [ V_1 ] . V_4 = 0 ;
V_5 = 0 ;
F_2 ( F_3 ( V_3 ) ) ;
}
int T_1 F_4 ( unsigned long V_6 )
{
unsigned long V_7 = V_6 - V_8 ;
unsigned long V_1 ;
T_2 V_4 , * V_9 ;
T_3 V_10 , * V_11 ;
T_4 V_12 , * V_13 ;
if ( V_7 >= V_14 || F_5 () != F_3 ( V_3 ) )
return - 1 ;
V_15:
V_9 = & V_3 [ F_6 ( V_6 ) ] . V_4 ;
V_4 = * V_9 ;
if ( V_4 )
V_11 = ( T_3 * ) ( ( V_4 & V_16 ) + V_17 - V_18 ) ;
else {
if ( V_5 >= V_19 ) {
F_1 () ;
goto V_15;
}
V_11 = ( T_3 * ) V_20 [ V_5 ++ ] ;
for ( V_1 = 0 ; V_1 < V_21 ; V_1 ++ )
V_11 [ V_1 ] = 0 ;
* V_9 = ( T_2 ) V_11 - V_17 + V_18 + V_22 ;
}
V_11 += F_7 ( V_6 ) ;
V_10 = * V_11 ;
if ( V_10 )
V_13 = ( T_4 * ) ( ( V_10 & V_16 ) + V_17 - V_18 ) ;
else {
if ( V_5 >= V_19 ) {
F_1 () ;
goto V_15;
}
V_13 = ( T_4 * ) V_20 [ V_5 ++ ] ;
for ( V_1 = 0 ; V_1 < V_23 ; V_1 ++ )
V_13 [ V_1 ] = 0 ;
* V_11 = ( T_3 ) V_13 - V_17 + V_18 + V_22 ;
}
V_12 = ( V_7 & V_24 ) + V_25 ;
V_13 [ F_8 ( V_6 ) ] = V_12 ;
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
int V_1 ;
F_15 ( V_37 < V_17 ) ;
F_15 ( V_37 - V_17 < V_38 ) ;
F_15 ( V_39 + V_38 > 2 * V_40 ) ;
F_15 ( ( V_17 & ~ V_24 ) != 0 ) ;
F_15 ( ( V_37 & ~ V_24 ) != 0 ) ;
F_15 ( ! ( V_37 > V_41 ) ) ;
F_15 ( ! ( ( ( V_42 - 1 ) & V_43 ) ==
( V_41 & V_43 ) ) ) ;
F_15 ( F_16 ( V_44 ) <= V_42 ) ;
F_17 () ;
F_1 () ;
F_18 ( V_3 ) ;
F_9 () ;
for ( V_1 = 0 ; V_1 < V_45 ; V_1 ++ )
F_19 ( V_1 , V_46 [ V_1 ] ) ;
F_20 ( ( const struct V_47 * ) & V_48 ) ;
F_11 ( F_13 ( V_33 ) ) ;
F_21 () ;
if ( V_49 >= V_50 )
F_22 ( L_1 ) ;
F_23 ( V_51 ) ;
V_51 [ 511 ] = V_3 [ 511 ] ;
F_18 ( V_51 ) ;
F_24 ( V_33 ) ;
}
void T_1 F_24 ( char * V_33 )
{
if ( ! V_29 . V_30 . V_52 )
F_11 ( F_13 ( V_33 ) ) ;
F_25 () ;
F_26 () ;
}
