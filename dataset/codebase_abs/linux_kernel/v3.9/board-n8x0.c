static void T_1 F_1 ( void )
{
const int V_1 = 108 ;
if ( F_2 ( V_1 , V_2 , L_1 ) )
return;
F_3 ( F_4 ( V_1 ) , V_3 ) ;
V_4 [ 0 ] . V_5 = F_4 ( V_1 ) ;
F_5 ( 3 , V_4 ,
F_6 ( V_4 ) ) ;
F_7 ( & V_6 ) ;
}
static void T_1 F_1 ( void )
{
}
static int F_8 ( int V_7 )
{
int V_8 , V_9 = 0 ;
if ( V_7 ) {
F_9 ( V_10 , 1 ) ;
F_10 ( 1 ) ;
V_8 = 100 ;
while ( V_8 && F_11 ( V_11 ) ) {
F_10 ( 1 ) ;
V_8 -- ;
}
if ( ! V_8 ) {
F_12 ( V_12 L_2 ) ;
V_9 = - V_13 ;
}
} else {
F_9 ( V_10 , 0 ) ;
F_10 ( 10 ) ;
}
return V_9 ;
}
static void T_1 F_13 ( void )
{
int V_14 = 0 ;
static char V_15 [] V_16 = V_17 L_3 ;
V_14 = F_2 ( V_10 , V_18 ,
L_4 ) ;
if ( V_14 != 0 ) {
F_12 ( V_12 L_5 ,
V_10 ) ;
return;
}
F_8 ( 0 ) ;
V_14 = F_14 ( & V_19 , V_20 , 2 ,
V_21 , V_22 ,
V_11 , V_23 ) ;
if ( V_14 != 0 )
goto V_24;
F_12 ( V_15 ) ;
return;
V_24:
F_15 ( V_10 ) ;
}
static void T_1 F_13 ( void ) {}
static int F_16 ( struct V_25 * V_26 , int V_27 )
{
#ifdef F_17
F_18 ( V_26 , L_6 , V_27 + 1 ) ;
#endif
F_9 ( V_28 , V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 , int V_27 ,
int V_29 , int V_30 )
{
int V_31 ;
#ifdef F_17
F_18 ( V_26 , L_7 , V_27 + 1 ,
V_29 ? L_8 : L_9 , V_30 ) ;
#endif
if ( V_27 == 0 ) {
if ( ! V_29 )
return F_20 ( 0 ) ;
switch ( 1 << V_30 ) {
case V_32 :
case V_33 :
case V_34 :
V_31 = 3100 ;
break;
case V_35 :
V_31 = 3000 ;
break;
case V_36 :
V_31 = 2800 ;
break;
case V_37 :
V_31 = 1850 ;
break;
default:
F_21 () ;
}
return F_20 ( V_31 ) ;
} else {
if ( ! V_29 )
return F_22 ( 3 , 0 ) ;
switch ( 1 << V_30 ) {
case V_32 :
case V_33 :
V_31 = 3300 ;
break;
case V_35 :
case V_38 :
V_31 = 3000 ;
break;
case V_36 :
case V_39 :
V_31 = 2800 ;
break;
case V_40 :
case V_41 :
V_31 = 2400 ;
break;
case V_42 :
case V_43 :
V_31 = 2200 ;
break;
case V_44 :
V_31 = 2000 ;
break;
case V_37 :
V_31 = 1800 ;
break;
default:
F_21 () ;
}
return F_22 ( 3 , V_31 ) ;
}
return 0 ;
}
static void F_23 ( struct V_25 * V_26 ,
int V_29 )
{
F_18 ( V_26 , L_10 , V_29 ? L_8 : L_9 ) ;
if ( V_29 ) {
F_9 ( V_45 , 1 ) ;
F_10 ( 1 ) ;
F_9 ( V_46 , 1 ) ;
F_10 ( 1 ) ;
} else {
F_9 ( V_46 , 0 ) ;
F_10 ( 50 ) ;
F_9 ( V_45 , 0 ) ;
F_10 ( 50 ) ;
}
}
static int F_24 ( struct V_25 * V_26 , int V_27 , int V_29 ,
int V_30 )
{
if ( F_25 () || V_27 == 0 )
return F_19 ( V_26 , V_27 , V_29 , V_30 ) ;
F_23 ( V_26 , V_29 ) ;
return 0 ;
}
static int F_26 ( struct V_25 * V_26 , int V_27 , int V_47 )
{
int V_48 ;
F_18 ( V_26 , L_11 , V_27 + 1 ,
V_47 == V_49 ? L_12 : L_13 ) ;
F_27 ( V_27 != 0 && V_27 != 1 ) ;
V_27 ++ ;
switch ( V_47 ) {
case V_49 :
V_48 = F_28 ( V_27 , 1 ) ;
break;
case V_50 :
V_48 = F_28 ( V_27 , 0 ) ;
break;
default:
F_21 () ;
}
if ( V_48 != 0 && F_29 () )
F_30 ( V_26 , L_14 ,
V_27 ) ;
return V_48 ;
}
static int F_31 ( struct V_25 * V_26 , int V_27 )
{
V_27 ++ ;
F_27 ( V_27 != 1 && V_27 != 2 ) ;
if ( V_27 == 1 )
return V_51 ;
else
return V_52 ;
}
static void F_32 ( void * V_53 , T_2 V_54 )
{
int V_55 , * V_56 , V_57 ;
if ( F_25 () ) {
V_55 = 1 << 1 ;
V_56 = & V_52 ;
V_57 = 1 ;
} else {
V_55 = 1 ;
V_56 = & V_51 ;
V_57 = 0 ;
}
if ( V_54 & V_55 )
* V_56 = 1 ;
else
* V_56 = 0 ;
#ifdef F_33
F_34 ( V_58 , V_57 , * V_56 ) ;
#else
F_35 ( L_15 ) ;
#endif
}
static int F_36 ( struct V_25 * V_26 )
{
int V_48 , V_55 , * V_56 ;
int V_59 ;
V_58 = V_26 ;
V_48 = F_37 ( 1 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( F_25 () )
V_59 = 0 ;
else
V_59 = 2 ;
V_48 = F_38 ( 2 , 0 , V_59 , 1 ) ;
if ( V_48 < 0 )
return V_48 ;
F_24 ( V_26 , 0 , V_60 , 16 ) ;
F_24 ( V_26 , 1 , V_60 , 16 ) ;
V_48 = F_38 ( 1 , 1 , 0 , 1 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_38 ( 2 , 1 , V_59 , 1 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_39 () ;
if ( V_48 < 0 )
return V_48 ;
if ( F_25 () ) {
V_55 = 1 << 1 ;
V_56 = & V_52 ;
} else {
V_55 = 1 ;
V_56 = & V_51 ;
V_52 = 0 ;
}
if ( V_48 == 0xf || V_48 == ( 0xf & ~ V_55 ) )
V_48 = ~ V_48 ;
if ( V_48 & V_55 )
* V_56 = 1 ;
else
* V_56 = 0 ;
V_48 = F_40 ( F_32 , NULL ) ;
return V_48 ;
}
static void F_41 ( struct V_25 * V_26 )
{
int V_59 ;
if ( F_25 () )
V_59 = 0 ;
else
V_59 = 2 ;
F_38 ( 1 , 0 , 0 , 0 ) ;
F_38 ( 2 , 0 , V_59 , 0 ) ;
}
static void F_42 ( struct V_25 * V_26 )
{
F_43 () ;
F_15 ( V_28 ) ;
if ( F_44 () ) {
F_15 ( V_45 ) ;
F_15 ( V_46 ) ;
}
}
static void T_1 F_45 ( void )
{
int V_24 ;
if ( F_44 () ) {
V_61 . V_62 [ 0 ] . V_63 = L_16 ;
V_61 . V_62 [ 1 ] . V_63 = L_17 ;
V_61 . V_62 [ 1 ] . V_64 = 1 ;
}
V_24 = F_2 ( V_28 , V_18 ,
L_18 ) ;
if ( V_24 )
return;
if ( F_44 () ) {
V_24 = F_46 ( V_65 ,
F_6 ( V_65 ) ) ;
if ( V_24 ) {
F_15 ( V_28 ) ;
return;
}
}
V_66 [ 0 ] = & V_61 ;
F_47 ( V_66 ) ;
}
void T_1 F_45 ( void )
{
}
static int F_48 ( void )
{
T_3 V_67 ;
int V_14 ;
V_67 = V_68 | V_69 \
| V_70 | V_71 \
| V_72 | V_73 \
| V_74 | V_75 ;
V_14 = F_49 ( 1 , V_67 ) ;
if ( V_14 < 0 ) {
F_50 ( L_19 ,
V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_51 ( void )
{
int V_14 ;
V_14 = F_52 ( 1400 , 1050 ) ;
if ( V_14 < 0 ) {
F_50 ( L_20 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_53 ( struct V_25 * V_26 )
{
int V_14 ;
V_14 = F_51 () ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_48 () ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_53 ( struct V_25 * V_26 )
{
return 0 ;
}
static inline void F_54 ( void )
{
struct V_76 V_77 ;
V_77 . V_78 = 0 ;
V_77 . V_79 = NULL ;
V_77 . V_80 = 0 ;
V_77 . V_81 = 0 ;
F_55 ( & V_77 , NULL ) ;
V_77 . V_81 = 1 ;
F_55 ( & V_77 , NULL ) ;
V_77 . V_81 = 2 ;
V_77 . V_79 = V_82 ;
V_77 . V_80 = F_6 ( V_82 ) ;
F_55 ( & V_77 , NULL ) ;
}
static inline void F_54 ( void )
{
F_56 () ;
}
static void T_1 F_57 ( void )
{
F_58 ( V_83 , V_84 ) ;
F_59 ( V_85 ,
F_6 ( V_85 ) ) ;
F_60 ( 1 , 400 , V_86 ,
F_6 ( V_86 ) ) ;
F_60 ( 2 , 400 , NULL , 0 ) ;
if ( F_44 () )
F_5 ( 2 , V_87 ,
F_6 ( V_87 ) ) ;
F_54 () ;
F_61 ( NULL , NULL ) ;
F_62 ( V_88 ) ;
F_45 () ;
F_13 () ;
F_1 () ;
}
