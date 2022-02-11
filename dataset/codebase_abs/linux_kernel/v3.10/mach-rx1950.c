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
static int F_14 ( unsigned V_6 , int V_7 ,
unsigned long * V_8 , unsigned long * V_9 )
{
int V_10 , V_11 ;
switch ( V_6 ) {
case F_15 ( 6 ) :
V_10 = F_15 ( 4 ) ;
V_11 = F_15 ( 3 ) ;
break;
case F_15 ( 7 ) :
V_10 = F_15 ( 3 ) ;
V_11 = F_15 ( 4 ) ;
break;
default:
return - V_12 ;
break;
}
if ( V_8 && V_9 && ! * V_8 && ! * V_9 )
* V_8 = * V_9 = 500 ;
F_16 ( & V_13 ) ;
switch ( V_7 ) {
case V_14 :
case V_15 :
if ( ! F_5 ( V_11 ) )
F_17 ( F_9 ( 6 ) , 0 ) ;
F_17 ( V_10 , 0 ) ;
F_17 ( V_6 , V_7 ) ;
break;
case V_16 :
F_17 ( V_6 , 0 ) ;
F_17 ( F_9 ( 6 ) , 1 ) ;
F_17 ( V_10 , 1 ) ;
break;
}
F_18 ( & V_13 ) ;
return 0 ;
}
static void F_19 ( int V_17 )
{
int V_18 ;
static int V_19 ;
if ( V_19 == V_17 )
return;
if ( ! V_17 ) {
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_12 ( F_20 ( V_18 ) , 1 ) ;
F_21 ( 100 ) ;
for ( V_18 = 2 ; V_18 < 8 ; V_18 ++ )
F_12 ( F_22 ( V_18 ) , 1 ) ;
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_12 ( F_22 ( V_18 ) , 1 ) ;
F_21 ( 100 ) ;
F_12 ( F_23 ( 0 ) , 0 ) ;
for ( V_18 = 1 ; V_18 < 5 ; V_18 ++ )
F_12 ( F_20 ( V_18 ) , 0 ) ;
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_12 ( F_20 ( V_18 ) , 0 ) ;
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_12 ( F_22 ( V_18 ) , 0 ) ;
for ( V_18 = 2 ; V_18 < 8 ; V_18 ++ )
F_12 ( F_22 ( V_18 ) , 0 ) ;
F_12 ( F_20 ( 6 ) , 0 ) ;
F_12 ( F_20 ( 7 ) , 0 ) ;
F_12 ( F_20 ( 5 ) , 0 ) ;
F_12 ( F_23 ( 1 ) , 0 ) ;
F_24 ( V_20 , 0 , V_21 ) ;
F_25 ( V_20 ) ;
F_12 ( F_20 ( 0 ) , 0 ) ;
F_12 ( F_20 ( 10 ) , 0 ) ;
} else {
F_24 ( V_20 , V_22 , V_21 ) ;
F_26 ( V_20 ) ;
F_12 ( F_20 ( 0 ) , 1 ) ;
F_12 ( F_20 ( 5 ) , 1 ) ;
F_27 ( F_23 ( 1 ) , V_23 ) ;
F_12 ( F_20 ( 7 ) , 1 ) ;
for ( V_18 = 1 ; V_18 < 5 ; V_18 ++ )
F_27 ( F_20 ( V_18 ) , F_28 ( 2 ) ) ;
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_27 ( F_20 ( V_18 ) , F_28 ( 2 ) ) ;
for ( V_18 = 2 ; V_18 < 8 ; V_18 ++ )
F_27 ( F_22 ( V_18 ) , F_28 ( 2 ) ) ;
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_27 ( F_22 ( V_18 ) , F_28 ( 2 ) ) ;
F_12 ( F_20 ( 10 ) , 1 ) ;
F_12 ( F_20 ( 6 ) , 1 ) ;
}
V_19 = V_17 ;
}
static void F_29 ( int V_17 )
{
static int V_19 ;
if ( V_19 == V_17 )
return;
if ( ! V_17 ) {
F_12 ( F_23 ( 0 ) , 0 ) ;
} else {
F_12 ( F_23 ( 0 ) , 1 ) ;
F_30 ( 48000 ) ;
F_27 ( F_23 ( 0 ) , V_24 ) ;
}
V_19 = V_17 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_32 ( F_2 ( F_23 ( 0 ) , L_4 ) ) ;
V_20 = F_33 ( 1 , L_5 ) ;
if ( F_34 ( V_20 ) ) {
F_35 ( V_2 , L_6 ) ;
return F_36 ( V_20 ) ;
}
F_19 ( 1 ) ;
F_29 ( 1 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_29 ( 0 ) ;
F_19 ( 0 ) ;
F_38 ( V_20 ) ;
F_7 ( F_23 ( 0 ) ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_25 )
{
if ( ! V_25 ) {
F_29 ( 0 ) ;
F_19 ( 0 ) ;
} else {
F_19 ( 1 ) ;
F_29 ( 1 ) ;
}
return V_25 ;
}
static void F_40 ( unsigned char V_26 , unsigned short V_27 )
{
switch ( V_26 ) {
case V_28 :
F_12 ( F_9 ( 1 ) , 0 ) ;
break;
case V_29 :
case V_30 :
F_12 ( F_9 ( 1 ) , 1 ) ;
break;
default:
break;
}
}
static void T_1 F_41 ( void )
{
V_31 . V_32 = & V_33 ;
V_34 . V_32 = & V_35 ;
F_42 ( V_36 , F_43 ( V_36 ) ) ;
F_44 ( V_37 , F_43 ( V_37 ) ) ;
F_45 ( 16934000 ) ;
F_46 ( V_38 , F_43 ( V_38 ) ) ;
F_47 ( V_39 , V_40 ) ;
#ifdef F_48
memcpy ( F_49 ( V_41 ) , V_42 , 8 ) ;
#endif
F_50 () ;
}
static void T_1 F_51 ( void )
{
int V_18 ;
F_52 ( & V_43 ) ;
F_53 ( & V_44 ) ;
F_54 ( & V_45 ) ;
F_55 ( & V_46 ) ;
F_56 ( NULL ) ;
F_57 ( & V_47 ) ;
F_58 ( V_48 |
V_49 |
V_50 , 0x0 ) ;
F_32 ( F_2 ( F_9 ( 1 ) , L_7 ) ) ;
F_12 ( F_9 ( 1 ) , 0 ) ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ )
F_32 ( F_2 ( F_20 ( V_18 ) , L_8 ) ) ;
for ( V_18 = 10 ; V_18 < 16 ; V_18 ++ )
F_32 ( F_2 ( F_20 ( V_18 ) , L_8 ) ) ;
for ( V_18 = 2 ; V_18 < 8 ; V_18 ++ )
F_32 ( F_2 ( F_22 ( V_18 ) , L_8 ) ) ;
for ( V_18 = 11 ; V_18 < 16 ; V_18 ++ )
F_32 ( F_2 ( F_22 ( V_18 ) , L_8 ) ) ;
F_32 ( F_2 ( F_23 ( 1 ) , L_8 ) ) ;
F_32 ( F_2 ( F_15 ( 3 ) , L_9 ) ) ;
F_32 ( F_2 ( F_15 ( 4 ) , L_10 ) ) ;
F_32 ( F_2 ( F_9 ( 6 ) , L_11 ) ) ;
F_12 ( F_15 ( 3 ) , 0 ) ;
F_12 ( F_15 ( 4 ) , 0 ) ;
F_12 ( F_9 ( 6 ) , 0 ) ;
F_59 ( V_51 , F_43 ( V_51 ) ) ;
F_60 ( 0 , V_52 ,
F_43 ( V_52 ) ) ;
}
static void T_1 F_61 ( void )
{
F_62 ( 0x30003000 , 0x1000 ) ;
F_62 ( 0x30081000 , 0x1000 ) ;
}
