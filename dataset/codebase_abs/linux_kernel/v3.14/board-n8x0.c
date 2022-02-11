static void F_1 ( void )
{
if ( F_2 () ) {
if ( F_3 ( L_1 ) )
V_1 = V_2 ;
else if ( F_3 ( L_2 ) )
V_1 = V_3 ;
else if ( F_3 ( L_3 ) )
V_1 = V_4 ;
}
if ( ! V_1 )
F_4 ( L_4 ) ;
}
static int F_5 ( int V_5 )
{
int V_6 , V_7 = 0 ;
if ( V_5 ) {
F_6 ( V_8 , 1 ) ;
F_7 ( 1 ) ;
V_6 = 100 ;
while ( V_6 && F_8 ( V_9 ) ) {
F_7 ( 1 ) ;
V_6 -- ;
}
if ( ! V_6 ) {
F_9 ( V_10 L_5 ) ;
V_7 = - V_11 ;
}
} else {
F_6 ( V_8 , 0 ) ;
F_7 ( 10 ) ;
}
return V_7 ;
}
static void T_1 F_10 ( void )
{
int V_12 = 0 ;
static char V_13 [] V_14 = V_15 L_6 ;
V_12 = F_11 ( V_8 , V_16 ,
L_7 ) ;
if ( V_12 != 0 ) {
F_9 ( V_10 L_8 ,
V_8 ) ;
return;
}
F_5 ( 0 ) ;
V_12 = F_12 ( & V_17 , V_18 , 2 ,
V_19 , V_20 ,
V_9 , V_21 ) ;
if ( V_12 != 0 )
goto V_22;
F_9 ( V_13 ) ;
return;
V_22:
F_13 ( V_8 ) ;
}
static void T_1 F_10 ( void ) {}
static int F_14 ( struct V_23 * V_24 , int V_25 )
{
#ifdef F_15
F_16 ( V_24 , L_9 , V_25 + 1 ) ;
#endif
F_6 ( V_26 , V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_23 * V_24 , int V_25 ,
int V_27 , int V_28 )
{
int V_29 ;
#ifdef F_15
F_16 ( V_24 , L_10 , V_25 + 1 ,
V_27 ? L_11 : L_12 , V_28 ) ;
#endif
if ( V_25 == 0 ) {
if ( ! V_27 )
return F_18 ( 0 ) ;
switch ( 1 << V_28 ) {
case V_30 :
case V_31 :
case V_32 :
V_29 = 3100 ;
break;
case V_33 :
V_29 = 3000 ;
break;
case V_34 :
V_29 = 2800 ;
break;
case V_35 :
V_29 = 1850 ;
break;
default:
F_19 () ;
}
return F_18 ( V_29 ) ;
} else {
if ( ! V_27 )
return F_20 ( 3 , 0 ) ;
switch ( 1 << V_28 ) {
case V_30 :
case V_31 :
V_29 = 3300 ;
break;
case V_33 :
case V_36 :
V_29 = 3000 ;
break;
case V_34 :
case V_37 :
V_29 = 2800 ;
break;
case V_38 :
case V_39 :
V_29 = 2400 ;
break;
case V_40 :
case V_41 :
V_29 = 2200 ;
break;
case V_42 :
V_29 = 2000 ;
break;
case V_35 :
V_29 = 1800 ;
break;
default:
F_19 () ;
}
return F_20 ( 3 , V_29 ) ;
}
return 0 ;
}
static void F_21 ( struct V_23 * V_24 ,
int V_27 )
{
F_16 ( V_24 , L_13 , V_27 ? L_11 : L_12 ) ;
if ( V_27 ) {
F_6 ( V_43 , 1 ) ;
F_7 ( 1 ) ;
F_6 ( V_44 , 1 ) ;
F_7 ( 1 ) ;
} else {
F_6 ( V_44 , 0 ) ;
F_7 ( 50 ) ;
F_6 ( V_43 , 0 ) ;
F_7 ( 50 ) ;
}
}
static int F_22 ( struct V_23 * V_24 , int V_25 , int V_27 ,
int V_28 )
{
if ( F_23 () || V_25 == 0 )
return F_17 ( V_24 , V_25 , V_27 , V_28 ) ;
F_21 ( V_24 , V_27 ) ;
return 0 ;
}
static int F_24 ( struct V_23 * V_24 , int V_25 , int V_45 )
{
int V_46 ;
F_16 ( V_24 , L_14 , V_25 + 1 ,
V_45 == V_47 ? L_15 : L_16 ) ;
F_25 ( V_25 != 0 && V_25 != 1 ) ;
V_25 ++ ;
switch ( V_45 ) {
case V_47 :
V_46 = F_26 ( V_25 , 1 ) ;
break;
case V_48 :
V_46 = F_26 ( V_25 , 0 ) ;
break;
default:
F_19 () ;
}
if ( V_46 != 0 && F_27 () )
F_28 ( V_24 , L_17 ,
V_25 ) ;
return V_46 ;
}
static int F_29 ( struct V_23 * V_24 , int V_25 )
{
V_25 ++ ;
F_25 ( V_25 != 1 && V_25 != 2 ) ;
if ( V_25 == 1 )
return V_49 ;
else
return V_50 ;
}
static void F_30 ( void * V_51 , T_2 V_52 )
{
int V_53 , * V_54 , V_55 ;
if ( F_23 () ) {
V_53 = 1 << 1 ;
V_54 = & V_50 ;
V_55 = 1 ;
} else {
V_53 = 1 ;
V_54 = & V_49 ;
V_55 = 0 ;
}
if ( V_52 & V_53 )
* V_54 = 1 ;
else
* V_54 = 0 ;
#ifdef F_31
F_32 ( V_56 , V_55 , * V_54 ) ;
#else
F_33 ( L_18 ) ;
#endif
}
static int F_34 ( struct V_23 * V_24 )
{
int V_46 , V_53 , * V_54 ;
int V_57 ;
V_56 = V_24 ;
V_46 = F_35 ( 1 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( F_23 () )
V_57 = 0 ;
else
V_57 = 2 ;
V_46 = F_36 ( 2 , 0 , V_57 , 1 ) ;
if ( V_46 < 0 )
return V_46 ;
F_22 ( V_24 , 0 , V_58 , 16 ) ;
F_22 ( V_24 , 1 , V_58 , 16 ) ;
V_46 = F_36 ( 1 , 1 , 0 , 1 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_36 ( 2 , 1 , V_57 , 1 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_37 () ;
if ( V_46 < 0 )
return V_46 ;
if ( F_23 () ) {
V_53 = 1 << 1 ;
V_54 = & V_50 ;
} else {
V_53 = 1 ;
V_54 = & V_49 ;
V_50 = 0 ;
}
if ( V_46 == 0xf || V_46 == ( 0xf & ~ V_53 ) )
V_46 = ~ V_46 ;
if ( V_46 & V_53 )
* V_54 = 1 ;
else
* V_54 = 0 ;
V_46 = F_38 ( F_30 , NULL ) ;
return V_46 ;
}
static void F_39 ( struct V_23 * V_24 )
{
int V_57 ;
if ( F_23 () )
V_57 = 0 ;
else
V_57 = 2 ;
F_36 ( 1 , 0 , 0 , 0 ) ;
F_36 ( 2 , 0 , V_57 , 0 ) ;
}
static void F_40 ( struct V_23 * V_24 )
{
F_41 () ;
F_13 ( V_26 ) ;
if ( F_42 () ) {
F_13 ( V_43 ) ;
F_13 ( V_44 ) ;
}
}
static void T_1 F_43 ( void )
{
int V_22 ;
if ( F_42 () ) {
V_59 . V_60 [ 0 ] . V_61 = L_19 ;
V_59 . V_60 [ 1 ] . V_61 = L_20 ;
V_59 . V_60 [ 1 ] . V_62 = 1 ;
}
V_22 = F_11 ( V_26 , V_16 ,
L_21 ) ;
if ( V_22 )
return;
if ( F_42 () ) {
V_22 = F_44 ( V_63 ,
F_45 ( V_63 ) ) ;
if ( V_22 ) {
F_13 ( V_26 ) ;
return;
}
}
V_59 . V_64 = 2 ;
V_65 [ 0 ] = & V_59 ;
}
void T_1 F_43 ( void )
{
}
static int F_46 ( void )
{
T_3 V_66 ;
int V_12 ;
V_66 = V_67 | V_68 \
| V_69 | V_70 \
| V_71 | V_72 \
| V_73 | V_74 ;
V_12 = F_47 ( 1 , V_66 ) ;
if ( V_12 < 0 ) {
F_4 ( L_22 ,
V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_48 ( void )
{
int V_12 ;
V_12 = F_49 ( 1400 , 1050 ) ;
if ( V_12 < 0 ) {
F_4 ( L_23 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_50 ( struct V_23 * V_24 )
{
int V_12 ;
V_12 = F_48 () ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_46 () ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_50 ( struct V_23 * V_24 )
{
return 0 ;
}
static int T_1 F_51 ( void )
{
if ( ! V_1 )
return - V_11 ;
F_43 () ;
F_10 () ;
return 0 ;
}
void * T_1 F_52 ( void )
{
F_1 () ;
F_53 ( V_75 ,
F_45 ( V_75 ) ) ;
F_54 ( 0 , V_76 ,
F_45 ( V_76 ) ) ;
if ( F_42 () )
F_54 ( 1 , V_77 ,
F_45 ( V_77 ) ) ;
return & V_59 ;
}
