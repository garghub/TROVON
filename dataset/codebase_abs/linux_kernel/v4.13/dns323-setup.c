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
static int T_1 F_6 ( void )
{
T_3 V_9 [ 6 ] ;
void T_4 * V_10 ;
V_10 = F_7 ( V_11 + 0x7d0000 + 196480 , 1024 ) ;
if ( ! V_10 )
return - V_12 ;
if ( ! F_8 ( ( V_13 const char * ) V_10 , V_9 ) )
goto V_14;
F_9 ( V_10 ) ;
F_10 ( L_1 , V_9 ) ;
memcpy ( V_15 . V_16 , V_9 , 6 ) ;
return 0 ;
V_14:
F_9 ( V_10 ) ;
return - V_17 ;
}
static void F_11 ( void )
{
F_12 ( L_2 ) ;
F_13 ( V_18 , 1 ) ;
}
static void F_14 ( void )
{
F_12 ( L_2 ) ;
F_13 ( V_18 , 1 ) ;
F_15 ( 100 ) ;
F_13 ( V_18 , 0 ) ;
}
static void F_16 ( void )
{
F_12 ( L_2 ) ;
F_13 ( V_19 , 1 ) ;
}
static int F_17 ( struct V_20 * V_21 )
{
V_21 -> V_22 |= V_23 ;
return 0 ;
}
static int T_1 F_18 ( void )
{
T_5 V_2 , V_24 , V_25 , V_26 ;
F_19 ( L_3 ) ;
F_20 ( & V_2 , & V_24 ) ;
if ( V_2 == V_27 ) {
F_19 ( L_4 ) ;
return V_7 ;
}
F_19 ( L_5 ) ;
#define F_21 (ORION5X_ETH_VIRT_BASE + 0x2000 + 0x004)
#define F_22 0x10000000
#define F_23 0x08000000
#define F_24 0x04000000
#define F_25 0x00000000
for ( V_25 = 0 ; V_25 < 1000 ; V_25 ++ ) {
V_26 = F_26 ( F_21 ) ;
if ( ! ( V_26 & F_22 ) )
break;
}
if ( V_25 >= 1000 ) {
F_27 ( L_6 ) ;
return V_28 ;
}
F_28 ( ( 3 << 21 ) |
( 8 << 16 ) |
F_24 , F_21 ) ;
for ( V_25 = 0 ; V_25 < 1000 ; V_25 ++ ) {
V_26 = F_26 ( F_21 ) ;
if ( V_26 & F_23 )
break;
}
if ( V_25 >= 1000 ) {
F_27 ( L_7 ) ;
return V_28 ;
}
F_19 ( L_8 , V_26 & 0xffff ) ;
switch( V_26 & 0xfff0 ) {
case 0x0cc0 :
return V_28 ;
case 0x0e10 :
return V_29 ;
default:
F_27 ( L_9 ,
V_26 & 0xffff ) ;
}
return V_28 ;
}
static void T_1 F_29 ( void )
{
F_30 () ;
V_6 = F_18 () ;
F_12 ( L_10 , 'A' + V_6 ) ;
switch( V_6 ) {
case V_7 :
F_31 ( V_30 ) ;
F_28 ( 0 , V_31 ) ;
break;
case V_28 :
F_31 ( V_32 ) ;
break;
case V_29 :
F_31 ( V_33 ) ;
break;
}
F_32 ( V_34 ,
V_35 ,
V_11 ,
V_36 ) ;
F_33 ( & V_37 ) ;
switch( V_6 ) {
case V_7 :
V_38 [ 0 ] . V_39 = 1 ;
F_34 ( V_40 , L_11 ) ;
F_35 ( V_40 , 0 ) ;
case V_28 :
F_36 ( 0 , V_41 ,
F_37 ( V_41 ) ) ;
break;
case V_29 :
V_42 . V_2 . V_43 = & V_44 ;
V_45 . V_2 . V_43 = & V_46 ;
F_36 ( 0 , V_47 ,
F_37 ( V_47 ) ) ;
F_38 ( L_12 , 0 , NULL , 0 ) ;
if ( ! F_39 ( V_48 ) )
break;
F_40 ( V_49 ,
V_50 ,
F_17 ) ;
}
F_33 ( & V_42 ) ;
F_33 ( & V_45 ) ;
if ( F_6 () < 0 )
F_10 ( L_13 ) ;
F_41 () ;
F_42 ( & V_15 ) ;
F_43 () ;
F_44 () ;
switch( V_6 ) {
case V_7 :
if ( F_34 ( V_18 , L_14 ) != 0 ||
F_35 ( V_18 , 0 ) != 0 )
F_45 ( L_15 ) ;
V_51 = F_11 ;
break;
case V_28 :
F_46 ( & V_52 ) ;
if ( F_34 ( V_53 , L_16 ) == 0 )
F_35 ( V_53 , 1 ) ;
if ( F_34 ( V_18 , L_14 ) != 0 ||
F_35 ( V_18 , 0 ) != 0 )
F_45 ( L_15 ) ;
V_51 = F_14 ;
break;
case V_29 :
F_46 ( & V_52 ) ;
if ( F_34 ( V_19 , L_14 ) != 0 ||
F_35 ( V_19 , 0 ) != 0 )
F_45 ( L_15 ) ;
V_51 = F_16 ;
F_28 ( 0x5 , V_54 + 0x2c ) ;
break;
}
}
