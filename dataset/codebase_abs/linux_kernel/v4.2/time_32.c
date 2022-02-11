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
T_1 T_2 F_3 ( int V_10 , void * V_11 )
{
if ( V_12 ) {
F_4 ( & V_13 ) ;
V_14 ++ ;
V_15 . V_16 () ;
F_5 ( & V_13 ) ;
} else {
V_15 . V_16 () ;
}
if ( V_17 )
V_18 . V_19 ( & V_18 ) ;
return V_20 ;
}
static void F_6 ( enum V_21 V_22 ,
struct V_23 * V_24 )
{
switch ( V_22 ) {
case V_25 :
case V_26 :
V_17 = 1 ;
break;
case V_27 :
V_17 = 0 ;
break;
default:
break;
}
F_7 () ;
}
static T_3 void F_8 ( void )
{
struct V_23 * V_28 = & V_18 ;
F_9 ( F_10 () != V_29 ) ;
V_28 -> V_30 = L_1 ;
V_28 -> V_31 = 100 ;
V_28 -> V_32 = V_33 ;
V_28 -> V_34 = F_6 ;
V_28 -> V_35 = V_36 ;
V_28 -> V_37 = 32 ;
V_28 -> V_38 = F_11 ( V_15 . V_39 , V_40 ,
V_28 -> V_37 ) ;
F_12 ( V_28 ) ;
}
static unsigned int F_13 ( void )
{
T_4 V_41 , V_42 ;
V_41 = F_14 ( V_43 ) ;
V_42 = ( V_41 >> V_44 ) & V_45 ;
if ( V_41 & V_46 )
V_42 += V_15 . V_47 ;
return V_42 ;
}
static T_5 F_15 ( struct V_48 * V_49 )
{
unsigned int V_50 , V_42 ;
T_6 V_51 ;
do {
V_50 = F_16 ( & V_13 ) ;
V_51 = V_14 ;
V_42 = V_15 . V_52 () ;
} while ( F_17 ( & V_13 , V_50 ) );
V_51 *= V_15 . V_47 ;
V_51 += V_42 ;
return V_51 ;
}
static T_3 int F_18 ( void )
{
V_12 = 1 ;
return F_19 ( & V_53 , V_15 . V_39 ) ;
}
static void F_20 ( enum V_21 V_22 ,
struct V_23 * V_24 )
{
int V_54 = F_21 ( V_24 -> V_35 ) ;
switch ( V_22 ) {
case V_25 :
V_15 . V_55 ( V_54 ,
V_56 / V_57 ) ;
break;
case V_58 :
case V_27 :
case V_59 :
V_15 . V_55 ( V_54 , 0 ) ;
break;
default:
break;
}
}
static int F_22 ( unsigned long V_60 ,
struct V_23 * V_24 )
{
int V_54 = F_21 ( V_24 -> V_35 ) ;
unsigned int V_61 = ( unsigned int ) V_60 ;
V_15 . V_55 ( V_54 , V_61 ) ;
return 0 ;
}
void F_23 ( int V_54 )
{
struct V_23 * V_28 = & F_24 ( V_62 , V_54 ) ;
unsigned int V_32 = V_33 ;
if ( V_15 . V_32 & V_63 )
V_32 |= V_64 ;
V_28 -> V_30 = L_2 ;
V_28 -> V_31 = 200 ;
V_28 -> V_32 = V_32 ;
V_28 -> V_34 = F_20 ;
V_28 -> V_65 = F_22 ;
V_28 -> V_35 = F_25 ( V_54 ) ;
V_28 -> V_37 = 32 ;
V_28 -> V_38 = F_11 ( V_15 . V_39 , V_40 ,
V_28 -> V_37 ) ;
V_28 -> V_66 = F_26 ( V_15 . V_39 , V_28 ) ;
V_28 -> V_67 = F_26 ( 100 , V_28 ) ;
F_12 ( V_28 ) ;
}
static unsigned char F_27 ( struct V_68 * V_69 , T_4 V_70 )
{
struct V_71 * V_72 = F_28 ( V_69 ) ;
struct V_73 * V_74 = V_72 -> V_69 . V_75 ;
return F_29 ( V_74 -> V_76 + V_70 ) ;
}
static void F_30 ( struct V_68 * V_69 , T_4 V_70 , T_7 V_41 )
{
struct V_71 * V_72 = F_28 ( V_69 ) ;
struct V_73 * V_74 = V_72 -> V_69 . V_75 ;
F_31 ( V_41 , V_74 -> V_76 + V_70 ) ;
}
static int F_32 ( struct V_71 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_69 . V_80 ;
const char * V_81 = F_33 ( V_79 , L_3 , NULL ) ;
if ( ! V_81 )
return - V_82 ;
if ( ! F_34 ( V_79 , L_4 , NULL ) )
return - V_82 ;
V_83 . V_84 = & V_77 -> V_84 [ 0 ] ;
if ( ! strcmp ( V_81 , L_5 ) ) {
V_85 . V_76 = F_35 ( & V_77 -> V_84 [ 0 ] , 0 ,
2048 , L_6 ) ;
V_85 . type = V_86 ;
} else if ( ! strcmp ( V_81 , L_7 ) ) {
V_85 . V_76 = F_35 ( & V_77 -> V_84 [ 0 ] , 0 ,
8192 , L_6 ) ;
V_85 . type = V_87 ;
} else
return - V_82 ;
if ( F_36 ( & V_83 ) < 0 )
F_37 ( V_88 L_8 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_89 ) ;
}
static void T_3 F_40 ( void )
{
if ( V_15 . V_32 & V_90 )
F_8 () ;
if ( V_15 . V_32 & V_91 )
F_18 () ;
#ifdef F_41
F_23 ( F_10 () ) ;
#endif
}
static void T_3 F_42 ( void )
{
V_15 . V_52 = F_13 ;
V_15 . V_92 () ;
}
void T_3 F_43 ( void )
{
V_15 . V_32 = 0 ;
V_93 = F_40 ;
if ( F_44 () )
F_45 () ;
else
F_42 () ;
}
