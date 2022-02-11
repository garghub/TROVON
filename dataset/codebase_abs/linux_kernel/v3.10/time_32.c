unsigned long F_1 ( struct V_1 * V_2 )
{
extern char V_3 [] , V_4 [] ;
extern char V_5 [] , V_6 [] ;
unsigned long V_7 = V_2 -> V_7 ;
if ( F_2 ( V_7 ) ||
( V_7 >= ( unsigned long ) V_3 &&
V_7 < ( unsigned long ) V_4 ) ||
( V_7 >= ( unsigned long ) V_5 &&
V_7 < ( unsigned long ) V_6 ) )
V_7 = V_2 -> V_8 [ V_9 ] ;
return V_7 ;
}
int F_3 ( struct V_10 V_11 )
{
return F_4 ( V_11 . V_12 ) ;
}
T_1 T_2 F_5 ( int V_13 , void * V_14 )
{
if ( V_15 ) {
F_6 ( & V_16 ) ;
V_17 ++ ;
V_18 . V_19 () ;
F_7 ( & V_16 ) ;
} else {
V_18 . V_19 () ;
}
if ( V_20 )
V_21 . V_22 ( & V_21 ) ;
return V_23 ;
}
static void F_8 ( enum V_24 V_25 ,
struct V_26 * V_27 )
{
switch ( V_25 ) {
case V_28 :
case V_29 :
V_20 = 1 ;
break;
case V_30 :
V_20 = 0 ;
break;
default:
break;
}
F_9 () ;
}
static T_3 void F_10 ( void )
{
struct V_26 * V_31 = & V_21 ;
F_11 ( F_12 () != V_32 ) ;
V_31 -> V_33 = L_1 ;
V_31 -> V_34 = 100 ;
V_31 -> V_35 = V_36 ;
V_31 -> V_37 = F_8 ;
V_31 -> V_38 = V_39 ;
V_31 -> V_40 = 32 ;
V_31 -> V_41 = F_13 ( V_18 . V_42 , V_43 ,
V_31 -> V_40 ) ;
F_14 ( V_31 ) ;
}
static unsigned int F_15 ( void )
{
unsigned int V_44 , V_45 ;
V_44 = * V_46 ;
V_45 = ( V_44 >> V_47 ) & V_48 ;
if ( V_44 & V_49 )
V_45 += V_18 . V_50 ;
return V_45 ;
}
static T_4 F_16 ( struct V_51 * V_52 )
{
unsigned int V_53 , V_45 ;
T_5 V_54 ;
do {
V_53 = F_17 ( & V_16 ) ;
V_54 = V_17 ;
V_45 = V_18 . V_55 () ;
} while ( F_18 ( & V_16 , V_53 ) );
V_54 *= V_18 . V_50 ;
V_54 += V_45 ;
return V_54 ;
}
static T_3 int F_19 ( void )
{
V_15 = 1 ;
V_56 . V_41 = F_20 ( V_18 . V_42 ,
V_56 . V_40 ) ;
return F_21 ( & V_56 ) ;
}
static void F_22 ( enum V_24 V_25 ,
struct V_26 * V_27 )
{
int V_57 = F_23 ( V_27 -> V_38 ) ;
switch ( V_25 ) {
case V_28 :
V_18 . V_58 ( V_57 ,
V_59 / V_60 ) ;
break;
case V_61 :
case V_30 :
case V_62 :
V_18 . V_58 ( V_57 , 0 ) ;
break;
default:
break;
}
}
static int F_24 ( unsigned long V_63 ,
struct V_26 * V_27 )
{
int V_57 = F_23 ( V_27 -> V_38 ) ;
unsigned int V_64 = ( unsigned int ) V_63 ;
V_18 . V_58 ( V_57 , V_64 ) ;
return 0 ;
}
void F_25 ( int V_57 )
{
struct V_26 * V_31 = & F_26 ( V_65 , V_57 ) ;
unsigned int V_35 = V_36 ;
if ( V_18 . V_35 & V_66 )
V_35 |= V_67 ;
V_31 -> V_33 = L_2 ;
V_31 -> V_34 = 200 ;
V_31 -> V_35 = V_35 ;
V_31 -> V_37 = F_22 ;
V_31 -> V_68 = F_24 ;
V_31 -> V_38 = F_27 ( V_57 ) ;
V_31 -> V_40 = 32 ;
V_31 -> V_41 = F_13 ( V_18 . V_42 , V_43 ,
V_31 -> V_40 ) ;
V_31 -> V_69 = F_28 ( V_18 . V_42 , V_31 ) ;
V_31 -> V_70 = F_28 ( 100 , V_31 ) ;
F_14 ( V_31 ) ;
}
static unsigned char F_29 ( struct V_71 * V_72 , T_6 V_73 )
{
struct V_74 * V_75 = F_30 ( V_72 ) ;
struct V_76 * V_77 = V_75 -> V_72 . V_78 ;
return F_31 ( V_77 -> V_79 + V_73 ) ;
}
static void F_32 ( struct V_71 * V_72 , T_6 V_73 , T_7 V_44 )
{
struct V_74 * V_75 = F_30 ( V_72 ) ;
struct V_76 * V_77 = V_75 -> V_72 . V_78 ;
F_33 ( V_44 , V_77 -> V_79 + V_73 ) ;
}
static int F_34 ( struct V_74 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_72 . V_83 ;
const char * V_84 = F_35 ( V_82 , L_3 , NULL ) ;
if ( ! V_84 )
return - V_85 ;
if ( ! F_36 ( V_82 , L_4 , NULL ) )
return - V_85 ;
V_86 . V_87 = & V_80 -> V_87 [ 0 ] ;
if ( ! strcmp ( V_84 , L_5 ) ) {
V_88 . V_79 = F_37 ( & V_80 -> V_87 [ 0 ] , 0 ,
2048 , L_6 ) ;
V_88 . type = V_89 ;
} else if ( ! strcmp ( V_84 , L_7 ) ) {
V_88 . V_79 = F_37 ( & V_80 -> V_87 [ 0 ] , 0 ,
8192 , L_6 ) ;
V_88 . type = V_90 ;
} else
return - V_85 ;
if ( F_38 ( & V_86 ) < 0 )
F_39 ( V_91 L_8 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_92 ) ;
}
static void T_3 F_42 ( void )
{
if ( V_18 . V_35 & V_93 )
F_10 () ;
if ( V_18 . V_35 & V_94 )
F_19 () ;
#ifdef F_43
F_25 ( F_12 () ) ;
#endif
}
static void T_3 F_44 ( void )
{
V_18 . V_55 = F_15 ;
V_18 . V_95 () ;
}
void T_3 F_45 ( void )
{
V_18 . V_35 = 0 ;
V_96 = F_42 ;
if ( F_46 () )
F_47 () ;
else
F_44 () ;
}
static int F_4 ( unsigned long V_97 )
{
struct V_98 * V_99 = F_48 ( L_9 ) ;
int V_100 = - 1 ;
if ( V_99 ) {
V_100 = F_49 ( V_99 , V_97 ) ;
F_50 ( V_99 ) ;
}
return V_100 ;
}
