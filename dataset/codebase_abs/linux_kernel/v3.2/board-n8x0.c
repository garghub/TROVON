static int F_1 ( int V_1 )
{
int V_2 , V_3 = 0 ;
if ( V_1 ) {
F_2 ( V_4 , 1 ) ;
F_3 ( 1 ) ;
V_2 = 100 ;
while ( V_2 && F_4 ( V_5 ) ) {
F_3 ( 1 ) ;
V_2 -- ;
}
if ( ! V_2 ) {
F_5 ( V_6 L_1 ) ;
V_3 = - V_7 ;
}
} else {
F_2 ( V_4 , 0 ) ;
F_3 ( 10 ) ;
}
return V_3 ;
}
static void T_1 F_6 ( void )
{
int V_8 = 0 ;
static char V_9 [] V_10 = V_11 L_2 ;
V_8 = F_7 ( V_4 , V_12 ,
L_3 ) ;
if ( V_8 != 0 ) {
F_5 ( V_6 L_4 ,
V_4 ) ;
return;
}
F_1 ( 0 ) ;
V_8 = F_8 ( & V_13 , V_14 , 2 ,
V_15 , V_16 ,
V_5 , V_17 ) ;
if ( V_8 != 0 )
goto V_18;
F_5 ( V_9 ) ;
return;
V_18:
F_9 ( V_4 ) ;
}
static void T_1 F_6 ( void ) {}
static int F_10 ( struct V_19 * V_20 , int V_21 )
{
#ifdef F_11
F_12 ( V_20 , L_5 , V_21 + 1 ) ;
#endif
F_2 ( V_22 , V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_20 , int V_21 ,
int V_23 , int V_24 )
{
int V_25 ;
#ifdef F_11
F_12 ( V_20 , L_6 , V_21 + 1 ,
V_23 ? L_7 : L_8 , V_24 ) ;
#endif
if ( V_21 == 0 ) {
if ( ! V_23 )
return F_14 ( 0 ) ;
switch ( 1 << V_24 ) {
case V_26 :
case V_27 :
case V_28 :
V_25 = 3100 ;
break;
case V_29 :
V_25 = 3000 ;
break;
case V_30 :
V_25 = 2800 ;
break;
case V_31 :
V_25 = 1850 ;
break;
default:
F_15 () ;
}
return F_14 ( V_25 ) ;
} else {
if ( ! V_23 )
return F_16 ( 3 , 0 ) ;
switch ( 1 << V_24 ) {
case V_26 :
case V_27 :
V_25 = 3300 ;
break;
case V_29 :
case V_32 :
V_25 = 3000 ;
break;
case V_30 :
case V_33 :
V_25 = 2800 ;
break;
case V_34 :
case V_35 :
V_25 = 2400 ;
break;
case V_36 :
case V_37 :
V_25 = 2200 ;
break;
case V_38 :
V_25 = 2000 ;
break;
case V_31 :
V_25 = 1800 ;
break;
default:
F_15 () ;
}
return F_16 ( 3 , V_25 ) ;
}
return 0 ;
}
static void F_17 ( struct V_19 * V_20 ,
int V_23 )
{
F_12 ( V_20 , L_9 , V_23 ? L_7 : L_8 ) ;
if ( V_23 ) {
F_2 ( V_39 , 1 ) ;
F_3 ( 1 ) ;
F_2 ( V_40 , 1 ) ;
F_3 ( 1 ) ;
} else {
F_2 ( V_40 , 0 ) ;
F_3 ( 50 ) ;
F_2 ( V_39 , 0 ) ;
F_3 ( 50 ) ;
}
}
static int F_18 ( struct V_19 * V_20 , int V_21 , int V_23 ,
int V_24 )
{
if ( F_19 () || V_21 == 0 )
return F_13 ( V_20 , V_21 , V_23 , V_24 ) ;
F_17 ( V_20 , V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , int V_21 , int V_41 )
{
int V_42 ;
F_12 ( V_20 , L_10 , V_21 + 1 ,
V_41 == V_43 ? L_11 : L_12 ) ;
F_21 ( V_21 != 0 && V_21 != 1 ) ;
V_21 ++ ;
switch ( V_41 ) {
case V_43 :
V_42 = F_22 ( V_21 , 1 ) ;
break;
case V_44 :
V_42 = F_22 ( V_21 , 0 ) ;
break;
default:
F_15 () ;
}
if ( V_42 != 0 && F_23 () )
F_24 ( V_20 , L_13 ,
V_21 ) ;
return V_42 ;
}
static int F_25 ( struct V_19 * V_20 , int V_21 )
{
V_21 ++ ;
F_21 ( V_21 != 1 && V_21 != 2 ) ;
if ( V_21 == 1 )
return V_45 ;
else
return V_46 ;
}
static void F_26 ( void * V_47 , T_2 V_48 )
{
int V_49 , * V_50 , V_51 ;
if ( F_19 () ) {
V_49 = 1 << 1 ;
V_50 = & V_46 ;
V_51 = 1 ;
} else {
V_49 = 1 ;
V_50 = & V_45 ;
V_51 = 0 ;
}
if ( V_48 & V_49 )
* V_50 = 1 ;
else
* V_50 = 0 ;
F_27 ( V_52 , V_51 , * V_50 ) ;
}
static int F_28 ( struct V_19 * V_20 )
{
int V_42 , V_49 , * V_50 ;
int V_53 ;
V_52 = V_20 ;
V_42 = F_29 ( 1 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_19 () )
V_53 = 0 ;
else
V_53 = 2 ;
V_42 = F_30 ( 2 , 0 , V_53 , 1 ) ;
if ( V_42 < 0 )
return V_42 ;
F_18 ( V_20 , 0 , V_54 , 16 ) ;
F_18 ( V_20 , 1 , V_54 , 16 ) ;
V_42 = F_30 ( 1 , 1 , 0 , 1 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_30 ( 2 , 1 , V_53 , 1 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_31 () ;
if ( V_42 < 0 )
return V_42 ;
if ( F_19 () ) {
V_49 = 1 << 1 ;
V_50 = & V_46 ;
} else {
V_49 = 1 ;
V_50 = & V_45 ;
V_46 = 0 ;
}
if ( V_42 == 0xf || V_42 == ( 0xf & ~ V_49 ) )
V_42 = ~ V_42 ;
if ( V_42 & V_49 )
* V_50 = 1 ;
else
* V_50 = 0 ;
V_42 = F_32 ( F_26 , NULL ) ;
return V_42 ;
}
static void F_33 ( struct V_19 * V_20 )
{
int V_53 ;
if ( F_19 () )
V_53 = 0 ;
else
V_53 = 2 ;
F_30 ( 1 , 0 , 0 , 0 ) ;
F_30 ( 2 , 0 , V_53 , 0 ) ;
}
static void F_34 ( struct V_19 * V_20 )
{
F_35 () ;
F_9 ( V_22 ) ;
if ( F_36 () ) {
F_9 ( V_39 ) ;
F_9 ( V_40 ) ;
}
}
static void T_1 F_37 ( void )
{
int V_18 ;
if ( F_36 () ) {
V_55 . V_56 [ 0 ] . V_57 = L_14 ;
V_55 . V_56 [ 1 ] . V_57 = L_15 ;
V_55 . V_56 [ 1 ] . V_58 = 1 ;
}
V_18 = F_7 ( V_22 , V_12 ,
L_16 ) ;
if ( V_18 )
return;
if ( F_36 () ) {
V_18 = F_38 ( V_59 ,
F_39 ( V_59 ) ) ;
if ( V_18 ) {
F_9 ( V_22 ) ;
return;
}
}
V_60 [ 0 ] = & V_55 ;
F_40 ( V_60 ) ;
}
void T_1 F_37 ( void )
{
}
static int F_41 ( void )
{
T_3 V_61 ;
int V_8 ;
V_61 = V_62 | V_63 \
| V_64 | V_65 \
| V_66 | V_67 \
| V_68 | V_69 ;
V_8 = F_42 ( 1 , V_61 ) ;
if ( V_8 < 0 ) {
F_5 ( V_6 L_17
L_18 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_43 ( void )
{
int V_8 ;
V_8 = F_44 ( 1400 , 1050 ) ;
if ( V_8 < 0 ) {
F_5 ( V_6 L_19
L_18 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_45 ( struct V_19 * V_20 )
{
int V_8 ;
V_8 = F_43 () ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_41 () ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_45 ( struct V_19 * V_20 )
{
return 0 ;
}
static inline void F_46 ( void )
{
struct V_70 V_71 ;
V_71 . V_72 = 0 ;
V_71 . V_73 = NULL ;
V_71 . V_74 = 0 ;
V_71 . V_75 = 0 ;
F_47 ( & V_71 ) ;
V_71 . V_75 = 1 ;
F_47 ( & V_71 ) ;
V_71 . V_75 = 2 ;
V_71 . V_73 = V_76 ;
V_71 . V_74 = F_39 ( V_76 ) ;
F_47 ( & V_71 ) ;
}
static inline void F_46 ( void )
{
F_48 () ;
}
static void T_1 F_49 ( void )
{
F_50 ( V_77 , V_78 ) ;
F_51 ( V_79 ,
F_39 ( V_79 ) ) ;
F_52 ( 1 , 400 , V_80 ,
F_39 ( V_80 ) ) ;
F_52 ( 2 , 400 , NULL , 0 ) ;
if ( F_36 () )
F_53 ( 2 , V_81 ,
F_39 ( V_81 ) ) ;
F_46 () ;
F_54 ( NULL , NULL ) ;
F_55 ( V_82 ) ;
F_37 () ;
F_6 () ;
}
