static int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - 1 )
return V_5 ;
return - 1 ;
}
static int T_1 F_3 ( void )
{
if ( F_4 () && V_6 == V_7 )
F_5 ( & V_8 ) ;
return 0 ;
}
static int T_1 F_6 ( char V_9 )
{
if ( V_9 >= '0' && V_9 <= '9' )
return V_9 - '0' ;
if ( V_9 >= 'A' && V_9 <= 'F' )
return V_9 - 'A' + 10 ;
if ( V_9 >= 'a' && V_9 <= 'f' )
return V_9 - 'a' + 10 ;
return - 1 ;
}
static int T_1 F_7 ( const char * V_10 )
{
int V_11 ;
int V_12 ;
V_11 = F_6 ( V_10 [ 0 ] ) ;
V_12 = F_6 ( V_10 [ 1 ] ) ;
if ( V_11 < 0 || V_12 < 0 )
return - 1 ;
return ( V_11 << 4 ) | V_12 ;
}
static int T_1 F_8 ( void )
{
T_3 V_13 [ 6 ] ;
int V_14 ;
char * V_15 ;
V_15 = F_9 ( V_16 + 0x7d0000 + 196480 , 1024 ) ;
if ( ! V_15 )
return - V_17 ;
for ( V_14 = 0 ; V_14 < 5 ; V_14 ++ ) {
if ( * ( V_15 + ( V_14 * 3 ) + 2 ) != ':' ) {
goto V_18;
}
}
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
int V_19 ;
V_19 = F_7 ( V_15 + ( V_14 * 3 ) ) ;
if ( V_19 < 0 ) {
goto V_18;
}
V_13 [ V_14 ] = V_19 ;
}
F_10 ( V_15 ) ;
F_11 ( L_1 ) ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ )
F_11 ( L_2 , V_13 [ V_14 ] , ( V_14 < 5 ) ? L_3 : L_4 ) ;
memcpy ( V_20 . V_21 , V_13 , 6 ) ;
return 0 ;
V_18:
F_10 ( V_15 ) ;
return - V_22 ;
}
static void F_12 ( void )
{
F_13 ( L_5 ) ;
F_14 ( V_23 , 1 ) ;
}
static void F_15 ( void )
{
F_13 ( L_5 ) ;
F_14 ( V_23 , 1 ) ;
F_16 ( 100 ) ;
F_14 ( V_23 , 0 ) ;
}
static void F_17 ( void )
{
F_13 ( L_5 ) ;
F_14 ( V_24 , 1 ) ;
}
static int F_18 ( struct V_25 * V_26 )
{
V_26 -> V_27 |= V_28 ;
return 0 ;
}
static int T_1 F_19 ( void )
{
T_4 V_2 , V_29 , V_14 , V_30 ;
F_20 ( L_6 ) ;
F_21 ( & V_2 , & V_29 ) ;
if ( V_2 == V_31 ) {
F_20 ( L_7 ) ;
return V_7 ;
}
F_20 ( L_8 ) ;
#define F_22 (ORION5X_ETH_VIRT_BASE + 0x2000 + 0x004)
#define F_23 0x10000000
#define F_24 0x08000000
#define F_25 0x04000000
#define F_26 0x00000000
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
V_30 = F_27 ( F_22 ) ;
if ( ! ( V_30 & F_23 ) )
break;
}
if ( V_14 >= 1000 ) {
F_28 ( L_9 ) ;
return V_32 ;
}
F_29 ( ( 3 << 21 ) |
( 8 << 16 ) |
F_25 , F_22 ) ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
V_30 = F_27 ( F_22 ) ;
if ( V_30 & F_24 )
break;
}
if ( V_14 >= 1000 ) {
F_28 ( L_10 ) ;
return V_32 ;
}
F_20 ( L_11 , V_30 & 0xffff ) ;
switch( V_30 & 0xfff0 ) {
case 0x0cc0 :
return V_32 ;
case 0x0e10 :
return V_33 ;
default:
F_28 ( L_12 ,
V_30 & 0xffff ) ;
}
return V_32 ;
}
static void T_1 F_30 ( void )
{
F_31 () ;
V_6 = F_19 () ;
F_13 ( L_13 , 'A' + V_6 ) ;
switch( V_6 ) {
case V_7 :
F_32 ( V_34 ) ;
F_29 ( 0 , V_35 ) ;
break;
case V_32 :
F_32 ( V_36 ) ;
break;
case V_33 :
F_32 ( V_37 ) ;
break;
}
F_33 ( V_16 , V_38 ) ;
F_34 ( & V_39 ) ;
switch( V_6 ) {
case V_7 :
V_40 [ 0 ] . V_41 = 1 ;
F_35 ( V_42 , L_14 ) ;
F_36 ( V_42 , 0 ) ;
case V_32 :
F_37 ( 0 , V_43 ,
F_38 ( V_43 ) ) ;
break;
case V_33 :
V_44 . V_2 . V_45 = & V_46 ;
V_47 . V_2 . V_45 = & V_48 ;
F_37 ( 0 , V_49 ,
F_38 ( V_49 ) ) ;
F_39 ( L_15 , 0 , NULL , 0 ) ;
F_40 ( V_50 ,
V_51 ,
F_18 ) ;
}
F_34 ( & V_44 ) ;
F_34 ( & V_47 ) ;
if ( F_8 () < 0 )
F_11 ( L_16 ) ;
F_41 () ;
F_42 ( & V_20 ) ;
F_43 () ;
F_44 () ;
switch( V_6 ) {
case V_7 :
if ( F_35 ( V_23 , L_17 ) != 0 ||
F_36 ( V_23 , 0 ) != 0 )
F_45 ( L_18 ) ;
V_52 = F_12 ;
break;
case V_32 :
F_46 ( & V_53 ) ;
if ( F_35 ( V_54 , L_19 ) == 0 )
F_36 ( V_54 , 1 ) ;
if ( F_35 ( V_23 , L_17 ) != 0 ||
F_36 ( V_23 , 0 ) != 0 )
F_45 ( L_18 ) ;
V_52 = F_15 ;
break;
case V_33 :
F_46 ( & V_53 ) ;
if ( F_35 ( V_24 , L_17 ) != 0 ||
F_36 ( V_24 , 0 ) != 0 )
F_45 ( L_18 ) ;
V_52 = F_17 ;
F_29 ( 0x5 , V_55 + 0x2c ) ;
break;
}
}
