static int F_1 ( int V_1 )
{
unsigned long V_2 ;
int V_3 ;
F_2 ( V_2 ) ;
F_3 ( V_4 , 0 ) ;
F_3 ( V_4 , V_5 | 0 ) ;
F_3 ( V_4 , V_5 |
V_6 [ V_1 ] ) ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
unsigned long V_7 = F_4 ( V_8 ) ;
if ( ( V_7 & V_9 ) == 0 &&
( ( ( V_7 >> V_10 ) ^
( V_6 [ V_1 ] >> V_11 ) ) & 0x3 )
== 0 )
break;
if ( V_7 & V_12 )
break;
F_5 ( 100 ) ;
}
F_6 ( V_2 ) ;
V_13 = V_1 ;
V_14 = V_15 [ V_1 ] . V_16 * 1000ul ;
return 0 ;
}
static int F_7 ( void )
{
unsigned long V_7 = F_4 ( V_8 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 <= V_18 ; V_17 ++ )
if ( ( ( ( V_7 >> V_10 ) ^
( V_6 [ V_17 ] >> V_11 ) ) & 0x3 ) == 0 )
break;
return V_17 ;
}
static int F_8 ( struct V_19 * V_20 ,
unsigned int V_21 )
{
return F_1 ( V_21 ) ;
}
static unsigned int F_9 ( unsigned int V_22 )
{
return V_15 [ V_13 ] . V_16 ;
}
static int F_10 ( struct V_19 * V_20 )
{
return F_11 ( V_20 , V_15 , 12000 ) ;
}
static int T_1 F_12 ( void )
{
struct V_23 * V_24 ;
unsigned int V_25 ;
unsigned long V_26 ;
const T_2 * V_27 ;
T_2 V_28 ;
int V_29 = - V_30 ;
if ( ! F_13 ( L_1 ) &&
! F_13 ( L_2 ) )
return 0 ;
V_24 = F_14 ( 0 ) ;
if ( V_24 == NULL ) {
F_15 ( V_31 L_3 ) ;
goto V_32;
}
V_28 = F_16 ( F_17 ( V_33 ) ) ;
if ( V_28 != 0x3c && V_28 != 0x44 ) {
F_15 ( V_31 L_4 ,
V_28 ) ;
goto V_32;
}
V_6 = F_18 ( V_24 , L_5 , & V_25 ) ;
if ( ! V_6 ) {
F_19 ( L_6 ) ;
goto V_32;
}
V_18 = V_25 / sizeof( T_2 ) - 1 ;
V_27 = F_18 ( V_24 , L_7 , NULL ) ;
if ( ! V_27 )
return - V_30 ;
V_26 = ( * V_27 ) / 1000 ;
V_15 [ 0 ] . V_16 = V_26 ;
V_15 [ 1 ] . V_16 = V_26 / 2 ;
F_20 ( 10 ) ;
V_13 = - 1 ;
F_1 ( F_7 () ) ;
F_15 ( V_34 L_8 ) ;
F_15 ( V_34 L_9 ,
V_15 [ 1 ] . V_16 / 1000 ,
V_15 [ 0 ] . V_16 / 1000 ,
V_15 [ V_13 ] . V_16 / 1000 ) ;
V_29 = F_21 ( & V_35 ) ;
F_22 ( V_24 ) ;
return V_29 ;
V_32:
F_22 ( V_24 ) ;
return V_29 ;
}
