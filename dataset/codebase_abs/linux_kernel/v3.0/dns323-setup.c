static int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
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
static int F_12 ( unsigned V_23 , int V_24 ,
unsigned long * V_25 , unsigned long * V_26 )
{
if ( V_25 && V_26 && ! * V_25 && ! * V_26 )
* V_25 = * V_26 = V_27 ;
switch( V_24 ) {
case V_28 :
case V_29 :
F_13 ( V_23 , 0 ) ;
F_14 ( V_23 , V_24 ) ;
break;
case V_30 :
F_13 ( V_23 , 1 ) ;
}
return 0 ;
}
static void F_15 ( void )
{
F_16 ( L_5 ) ;
F_14 ( V_31 , 1 ) ;
}
static void F_17 ( void )
{
F_16 ( L_5 ) ;
F_14 ( V_31 , 1 ) ;
F_18 ( 100 ) ;
F_14 ( V_31 , 0 ) ;
}
static void F_19 ( void )
{
F_16 ( L_5 ) ;
F_14 ( V_32 , 1 ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
V_34 -> V_35 |= V_36 ;
return 0 ;
}
static int T_1 F_21 ( void )
{
T_4 V_2 , V_37 , V_14 , V_38 ;
F_22 ( L_6 ) ;
F_23 ( & V_2 , & V_37 ) ;
if ( V_2 == V_39 ) {
F_22 ( L_7 ) ;
return V_7 ;
}
F_22 ( L_8 ) ;
#define F_24 (ORION5X_ETH_VIRT_BASE + 0x2000 + 0x004)
#define F_25 0x10000000
#define F_26 0x08000000
#define F_27 0x04000000
#define F_28 0x00000000
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
V_38 = F_29 ( F_24 ) ;
if ( ! ( V_38 & F_25 ) )
break;
}
if ( V_14 >= 1000 ) {
F_30 ( L_9 ) ;
return V_40 ;
}
F_31 ( ( 3 << 21 ) |
( 8 << 16 ) |
F_27 , F_24 ) ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
V_38 = F_29 ( F_24 ) ;
if ( V_38 & F_26 )
break;
}
if ( V_14 >= 1000 ) {
F_30 ( L_10 ) ;
return V_40 ;
}
F_22 ( L_11 , V_38 & 0xffff ) ;
switch( V_38 & 0xfff0 ) {
case 0x0cc0 :
return V_40 ;
case 0x0e10 :
return V_41 ;
default:
F_30 ( L_12 ,
V_38 & 0xffff ) ;
}
return V_40 ;
}
static void T_1 F_32 ( void )
{
F_33 () ;
V_6 = F_21 () ;
F_16 ( L_13 , 'A' + V_6 ) ;
switch( V_6 ) {
case V_7 :
F_34 ( V_42 ) ;
F_31 ( 0 , V_43 ) ;
break;
case V_40 :
F_34 ( V_44 ) ;
break;
case V_41 :
F_34 ( V_45 ) ;
break;
}
F_35 ( V_16 , V_46 ) ;
F_36 ( & V_47 ) ;
switch( V_6 ) {
case V_7 :
V_48 [ 0 ] . V_49 = 1 ;
F_37 ( V_50 , L_14 ) ;
F_38 ( V_50 , 0 ) ;
case V_40 :
F_39 ( 0 , V_51 ,
F_40 ( V_51 ) ) ;
break;
case V_41 :
V_52 . V_2 . V_53 = & V_54 ;
V_55 . V_2 . V_53 = & V_56 ;
F_39 ( 0 , V_57 ,
F_40 ( V_57 ) ) ;
F_41 ( L_15 , 0 , NULL , 0 ) ;
F_42 ( V_58 ,
V_59 ,
F_20 ) ;
}
F_36 ( & V_52 ) ;
F_36 ( & V_55 ) ;
if ( F_8 () < 0 )
F_11 ( L_16 ) ;
F_43 () ;
F_44 ( & V_20 ) ;
F_45 () ;
F_46 () ;
switch( V_6 ) {
case V_7 :
if ( F_37 ( V_31 , L_17 ) != 0 ||
F_38 ( V_31 , 0 ) != 0 )
F_47 ( L_18 ) ;
V_60 = F_15 ;
break;
case V_40 :
F_48 ( & V_61 ) ;
if ( F_37 ( V_62 , L_19 ) == 0 )
F_38 ( V_62 , 1 ) ;
if ( F_37 ( V_31 , L_17 ) != 0 ||
F_38 ( V_31 , 0 ) != 0 )
F_47 ( L_18 ) ;
V_60 = F_17 ;
break;
case V_41 :
F_48 ( & V_61 ) ;
if ( F_37 ( V_32 , L_17 ) != 0 ||
F_38 ( V_32 , 0 ) != 0 )
F_47 ( L_18 ) ;
V_60 = F_19 ;
F_31 ( 0x5 , V_63 | 0x2c ) ;
break;
}
}
