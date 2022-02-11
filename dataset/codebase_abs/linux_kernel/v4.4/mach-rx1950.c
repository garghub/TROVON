static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( 2 ) , L_1 ) ;
}
static int F_4 ( void )
{
return ! F_5 ( F_3 ( 2 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( F_3 ( 2 ) ) ;
}
static int F_8 ( void )
{
int V_3 ;
V_3 = F_2 ( F_9 ( 2 ) , L_2 ) ;
if ( V_3 )
goto V_4;
V_3 = F_2 ( F_9 ( 3 ) , L_3 ) ;
if ( V_3 )
goto V_5;
return 0 ;
V_5:
F_7 ( F_9 ( 2 ) ) ;
V_4:
return V_3 ;
}
static void F_10 ( void )
{
F_7 ( F_9 ( 2 ) ) ;
F_7 ( F_9 ( 3 ) ) ;
}
static void F_11 ( void )
{
F_12 ( F_9 ( 2 ) , 1 ) ;
F_12 ( F_9 ( 3 ) , 1 ) ;
}
static void F_13 ( void )
{
F_12 ( F_9 ( 2 ) , 0 ) ;
F_12 ( F_9 ( 3 ) , 0 ) ;
}
static int F_14 ( struct V_6 * V_7 , int V_8 ,
unsigned long * V_9 , unsigned long * V_10 )
{
int V_11 = F_15 ( V_7 ) ;
int V_12 , V_13 ;
switch ( V_11 ) {
case F_16 ( 6 ) :
V_12 = F_16 ( 4 ) ;
V_13 = F_16 ( 3 ) ;
break;
case F_16 ( 7 ) :
V_12 = F_16 ( 3 ) ;
V_13 = F_16 ( 4 ) ;
break;
default:
return - V_14 ;
break;
}
if ( V_9 && V_10 && ! * V_9 && ! * V_10 )
* V_9 = * V_10 = 500 ;
F_17 ( & V_15 ) ;
switch ( V_8 ) {
case V_16 :
case V_17 :
if ( ! F_5 ( V_13 ) )
F_18 ( F_9 ( 6 ) , 0 ) ;
F_18 ( V_12 , 0 ) ;
F_18 ( V_11 , V_8 ) ;
break;
case V_18 :
F_18 ( V_11 , 0 ) ;
F_18 ( F_9 ( 6 ) , 1 ) ;
F_18 ( V_12 , 1 ) ;
break;
}
F_19 ( & V_15 ) ;
return 0 ;
}
static void F_20 ( int V_19 )
{
int V_20 ;
static int V_21 ;
if ( V_21 == V_19 )
return;
if ( ! V_19 ) {
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_12 ( F_21 ( V_20 ) , 1 ) ;
F_22 ( 100 ) ;
for ( V_20 = 2 ; V_20 < 8 ; V_20 ++ )
F_12 ( F_23 ( V_20 ) , 1 ) ;
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_12 ( F_23 ( V_20 ) , 1 ) ;
F_22 ( 100 ) ;
F_12 ( F_24 ( 0 ) , 0 ) ;
for ( V_20 = 1 ; V_20 < 5 ; V_20 ++ )
F_12 ( F_21 ( V_20 ) , 0 ) ;
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_12 ( F_21 ( V_20 ) , 0 ) ;
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_12 ( F_23 ( V_20 ) , 0 ) ;
for ( V_20 = 2 ; V_20 < 8 ; V_20 ++ )
F_12 ( F_23 ( V_20 ) , 0 ) ;
F_12 ( F_21 ( 6 ) , 0 ) ;
F_12 ( F_21 ( 7 ) , 0 ) ;
F_12 ( F_21 ( 5 ) , 0 ) ;
F_12 ( F_24 ( 1 ) , 0 ) ;
F_25 ( V_22 , 0 , V_23 ) ;
F_26 ( V_22 ) ;
F_12 ( F_21 ( 0 ) , 0 ) ;
F_12 ( F_21 ( 10 ) , 0 ) ;
} else {
F_25 ( V_22 , V_24 , V_23 ) ;
F_27 ( V_22 ) ;
F_12 ( F_21 ( 0 ) , 1 ) ;
F_12 ( F_21 ( 5 ) , 1 ) ;
F_28 ( F_24 ( 1 ) , V_25 ) ;
F_12 ( F_21 ( 7 ) , 1 ) ;
for ( V_20 = 1 ; V_20 < 5 ; V_20 ++ )
F_28 ( F_21 ( V_20 ) , F_29 ( 2 ) ) ;
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_28 ( F_21 ( V_20 ) , F_29 ( 2 ) ) ;
for ( V_20 = 2 ; V_20 < 8 ; V_20 ++ )
F_28 ( F_23 ( V_20 ) , F_29 ( 2 ) ) ;
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_28 ( F_23 ( V_20 ) , F_29 ( 2 ) ) ;
F_12 ( F_21 ( 10 ) , 1 ) ;
F_12 ( F_21 ( 6 ) , 1 ) ;
}
V_21 = V_19 ;
}
static void F_30 ( int V_19 )
{
static int V_21 ;
if ( V_21 == V_19 )
return;
if ( ! V_19 ) {
F_12 ( F_24 ( 0 ) , 0 ) ;
} else {
F_12 ( F_24 ( 0 ) , 1 ) ;
F_31 ( 48000 ) ;
F_28 ( F_24 ( 0 ) , V_26 ) ;
}
V_21 = V_19 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_33 ( F_2 ( F_24 ( 0 ) , L_4 ) ) ;
V_22 = F_34 ( 1 , L_5 ) ;
if ( F_35 ( V_22 ) ) {
F_36 ( V_2 , L_6 ) ;
return F_37 ( V_22 ) ;
}
F_20 ( 1 ) ;
F_30 ( 1 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_30 ( 0 ) ;
F_20 ( 0 ) ;
F_39 ( V_22 ) ;
F_7 ( F_24 ( 0 ) ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_27 )
{
if ( ! V_27 ) {
F_30 ( 0 ) ;
F_20 ( 0 ) ;
} else {
F_20 ( 1 ) ;
F_30 ( 1 ) ;
}
return V_27 ;
}
static void F_41 ( unsigned char V_28 , unsigned short V_29 )
{
switch ( V_28 ) {
case V_30 :
F_12 ( F_9 ( 1 ) , 0 ) ;
break;
case V_31 :
case V_32 :
F_12 ( F_9 ( 1 ) , 1 ) ;
break;
default:
break;
}
}
static void T_1 F_42 ( void )
{
F_43 ( V_33 , F_44 ( V_33 ) ) ;
F_45 ( V_34 , F_44 ( V_34 ) ) ;
F_46 ( V_35 , V_36 ) ;
#ifdef F_47
memcpy ( F_48 ( V_37 ) , V_38 , 8 ) ;
#endif
F_49 () ;
}
static void T_1 F_50 ( void )
{
F_51 ( 16934000 ) ;
F_52 () ;
}
static void T_1 F_53 ( void )
{
int V_20 ;
F_54 ( & V_39 ) ;
F_55 ( & V_40 ) ;
F_56 ( & V_41 ) ;
F_57 ( & V_42 ) ;
F_58 ( NULL ) ;
F_59 ( & V_43 ) ;
F_60 ( V_44 |
V_45 |
V_46 , 0x0 ) ;
F_33 ( F_2 ( F_9 ( 1 ) , L_7 ) ) ;
F_12 ( F_9 ( 1 ) , 0 ) ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
F_33 ( F_2 ( F_21 ( V_20 ) , L_8 ) ) ;
for ( V_20 = 10 ; V_20 < 16 ; V_20 ++ )
F_33 ( F_2 ( F_21 ( V_20 ) , L_8 ) ) ;
for ( V_20 = 2 ; V_20 < 8 ; V_20 ++ )
F_33 ( F_2 ( F_23 ( V_20 ) , L_8 ) ) ;
for ( V_20 = 11 ; V_20 < 16 ; V_20 ++ )
F_33 ( F_2 ( F_23 ( V_20 ) , L_8 ) ) ;
F_33 ( F_2 ( F_24 ( 1 ) , L_8 ) ) ;
F_33 ( F_2 ( F_16 ( 3 ) , L_9 ) ) ;
F_33 ( F_2 ( F_16 ( 4 ) , L_10 ) ) ;
F_33 ( F_2 ( F_9 ( 6 ) , L_11 ) ) ;
F_12 ( F_16 ( 3 ) , 0 ) ;
F_12 ( F_16 ( 4 ) , 0 ) ;
F_12 ( F_9 ( 6 ) , 0 ) ;
F_61 ( V_47 , F_44 ( V_47 ) ) ;
F_62 ( V_48 , F_44 ( V_48 ) ) ;
F_63 ( 0 , V_49 ,
F_44 ( V_49 ) ) ;
}
static void T_1 F_64 ( void )
{
F_65 ( 0x30003000 , 0x1000 ) ;
F_65 ( 0x30081000 , 0x1000 ) ;
}
