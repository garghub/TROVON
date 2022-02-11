static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
return V_2 -> V_3 == V_3 && V_2 -> V_4 == V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_5 ;
F_3 ( ! V_2 -> V_3 ) ;
F_4 ( & V_6 . V_7 ) ;
if ( F_1 ( V_2 , 1 , 1 ) ) {
V_6 . V_8 ++ ;
if ( V_6 . V_8 > 1 ) {
V_5 = 0 ;
goto V_9;
}
}
if ( F_1 ( V_2 , 1 , 2 ) ) {
V_6 . V_10 ++ ;
if ( V_6 . V_10 > 1 ) {
V_5 = 0 ;
goto V_9;
}
}
V_5 = F_5 ( V_2 -> V_3 , V_2 -> V_4 , 0 ) ;
if ( V_5 ) {
F_6 ( L_1 , V_11 ,
__LINE__ , F_7 ( V_5 ) ) ;
V_5 = - V_12 ;
}
V_9:
F_8 ( & V_6 . V_7 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
F_3 ( ! V_2 -> V_3 ) ;
F_4 ( & V_6 . V_7 ) ;
if ( F_1 ( V_2 , 1 , 1 ) ) {
V_6 . V_8 -- ;
if ( V_6 . V_8 ) {
V_5 = 0 ;
goto V_9;
}
}
if ( F_1 ( V_2 , 1 , 2 ) ) {
V_6 . V_10 -- ;
if ( V_6 . V_10 ) {
V_5 = 0 ;
goto V_9;
}
}
V_5 = F_10 ( V_2 -> V_3 , V_2 -> V_4 ) ;
F_3 ( V_5 ) ;
V_9:
F_8 ( & V_6 . V_7 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 ;
F_4 ( & V_6 . V_7 ) ;
V_6 . V_13 ++ ;
if ( V_6 . V_13 > 1 ) {
V_5 = 0 ;
goto V_9;
}
V_5 = F_12 ( 0 ) ;
if ( V_5 ) {
F_6 ( L_2 , V_11 ,
__LINE__ , F_7 ( V_5 ) ) ;
V_5 = - V_12 ;
}
V_9:
F_8 ( & V_6 . V_7 ) ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_5 ;
F_4 ( & V_6 . V_7 ) ;
V_6 . V_13 -- ;
if ( V_6 . V_13 ) {
V_5 = 0 ;
goto V_9;
}
V_5 = F_14 () ;
F_3 ( V_5 ) ;
V_9:
F_8 ( & V_6 . V_7 ) ;
return V_5 ;
}
int F_15 ( struct V_1 * V_2 )
{
F_3 ( ! V_2 ) ;
F_6 ( L_3 , V_11 , __LINE__ , V_2 -> V_14 ) ;
switch ( V_2 -> V_14 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
return F_2 ( V_2 ) ;
case V_21 :
case V_22 :
return F_11 ( V_2 ) ;
case V_23 :
case V_24 :
F_6 ( L_4 , V_11 ,
__LINE__ , V_2 -> V_14 ) ;
F_6 ( L_5 , V_11 , __LINE__ ,
V_2 -> V_3 ) ;
F_16 () ;
return - V_25 ;
default:
break;
}
F_6 ( L_6 , V_11 , __LINE__ ,
V_2 -> V_14 ) ;
F_16 () ;
return - V_26 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_3 ( ! V_2 ) ;
F_6 ( L_3 , V_11 , __LINE__ , V_2 -> V_14 ) ;
switch ( V_2 -> V_14 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
return F_9 ( V_2 ) ;
case V_21 :
case V_22 :
return F_13 ( V_2 ) ;
case V_23 :
case V_24 :
F_6 ( L_4 , V_11 ,
__LINE__ , V_2 -> V_14 ) ;
F_6 ( L_5 , V_11 , __LINE__ ,
V_2 -> V_3 ) ;
F_16 () ;
return - V_25 ;
default:
break;
}
F_6 ( L_6 , V_11 , __LINE__ ,
V_2 -> V_14 ) ;
F_16 () ;
return - V_26 ;
}
static void F_18 ( const struct V_27 * V_28 ,
const char * V_29 , int line )
{
F_6 ( L_7 , V_29 , line , V_28 -> V_2 -> V_3 ,
V_28 -> V_2 -> V_4 ) ;
F_6 ( L_8 , V_29 , line , V_28 -> V_30 ) ;
F_6 ( L_9 , V_29 , line , V_28 -> V_31 ) ;
F_6 ( L_10 , V_29 , line , V_28 -> V_32 ) ;
}
static int F_19 ( struct V_27 * V_28 )
{
int V_5 ;
T_1 V_32 ;
V_5 = F_20 ( V_28 -> V_2 -> V_3 , V_28 -> V_2 -> V_4 ,
V_28 -> V_30 , V_28 -> V_31 , V_28 -> V_33 , & V_32 ) ;
V_28 -> V_32 = V_32 ;
if ( V_5 ) {
F_6 ( L_11 ,
V_11 , __LINE__ , F_7 ( V_5 ) ) ;
V_28 -> V_32 = 0 ;
}
F_21 ( V_28 ) ;
return V_5 ;
}
static int F_22 ( struct V_27 * V_28 )
{
return 0 ;
}
int F_23 ( struct V_27 * V_28 )
{
return V_28 -> V_34 -> V_35 ( V_28 ) ;
}
static int F_24 ( struct V_27 * V_28 )
{
int V_5 ;
F_21 ( V_28 ) ;
V_5 = F_25 ( V_28 -> V_2 -> V_3 , V_28 -> V_2 -> V_4 ,
V_28 -> V_32 ) ;
if ( V_5 )
F_6 ( L_12 ,
V_11 , __LINE__ , F_7 ( V_5 ) ) ;
V_28 -> V_32 = 0 ;
return V_5 ;
}
static int F_26 ( struct V_27 * V_28 )
{
return 0 ;
}
int F_27 ( struct V_27 * V_28 )
{
return V_28 -> V_34 -> free ( V_28 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_27 * V_28 , unsigned long V_30 , unsigned long V_31 ,
enum V_36 V_33 )
{
V_28 -> V_2 = V_2 ;
V_28 -> V_30 = V_30 ;
V_28 -> V_31 = V_31 ;
V_28 -> V_33 = V_33 ;
switch ( V_2 -> V_37 ) {
case V_38 :
V_28 -> V_34 = & V_39 ;
break;
case V_40 :
V_28 -> V_34 = & V_41 ;
break;
default:
F_16 () ;
return - V_25 ;
}
return 0 ;
}
static int F_29 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_5 ;
struct V_46 * V_47 = F_30 ( V_45 ) ;
struct V_1 * V_2 = F_31 ( V_43 ) ;
if ( ! V_2 -> V_48 )
V_5 = V_2 -> V_14 == V_47 -> V_14 ;
else
V_5 = V_2 -> V_48 == V_47 -> V_48 &&
V_2 -> V_14 == V_47 -> V_14 ;
if ( V_5 )
F_32 ( L_13 ,
V_11 , __LINE__ ,
V_2 -> V_14 , V_2 -> V_48 , F_33 ( & V_2 -> V_49 ) ,
V_47 -> V_14 , V_47 -> V_48 , V_47 -> V_49 . V_50 ) ;
else
F_6 ( L_14 ,
V_11 , __LINE__ ,
V_2 -> V_14 , V_2 -> V_48 , F_33 ( & V_2 -> V_49 ) ,
V_47 -> V_14 , V_47 -> V_48 , V_47 -> V_49 . V_50 ) ;
return V_5 ;
}
static int F_34 ( struct V_42 * V_43 )
{
int V_5 = 0 ;
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_46 * V_47 ;
F_3 ( ! V_2 ) ;
F_35 ( V_43 , L_15 , V_11 , __LINE__ ) ;
V_47 = F_36 ( V_2 ) ;
F_3 ( ! V_47 ) ;
if ( V_47 -> V_51 )
V_5 = V_47 -> V_51 ( V_2 ) ;
else
F_6 ( L_16 , V_11 , __LINE__ ,
F_33 ( & V_2 -> V_49 ) ) ;
F_6 ( L_17 , V_11 , __LINE__ , F_33 ( & V_2 -> V_49 ) ) ;
return V_5 ;
}
static int F_37 ( struct V_42 * V_43 )
{
int V_5 = 0 ;
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_46 * V_47 ;
F_3 ( ! V_2 ) ;
F_35 ( V_43 , L_15 , V_11 , __LINE__ ) ;
V_47 = F_36 ( V_2 ) ;
F_3 ( ! V_47 ) ;
if ( V_47 -> remove )
V_5 = V_47 -> remove ( V_2 ) ;
else
F_35 ( & V_2 -> V_49 , L_18 ,
V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
F_6 ( L_17 , V_11 , __LINE__ , F_33 ( & V_2 -> V_49 ) ) ;
return V_5 ;
}
static void F_38 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_46 * V_47 ;
F_3 ( ! V_2 ) ;
F_35 ( & V_2 -> V_49 , L_19 , V_11 , __LINE__ ,
V_2 -> V_14 ) ;
if ( ! V_2 -> V_49 . V_52 ) {
F_35 ( & V_2 -> V_49 , L_20 , V_11 ,
__LINE__ ) ;
return;
}
V_47 = F_36 ( V_2 ) ;
F_3 ( ! V_47 ) ;
F_35 ( & V_2 -> V_49 , L_21 , V_11 , __LINE__ ,
F_33 ( & V_2 -> V_49 ) , V_47 -> V_49 . V_50 ) ;
if ( V_47 -> V_53 )
V_47 -> V_53 ( V_2 ) ;
else if ( V_47 -> remove ) {
F_35 ( & V_2 -> V_49 , L_22 ,
V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
V_47 -> remove ( V_2 ) ;
} else {
F_35 ( & V_2 -> V_49 , L_23 ,
V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
F_16 () ;
}
F_35 ( & V_2 -> V_49 , L_24 , V_11 , __LINE__ ) ;
}
static int F_39 ( struct V_42 * V_43 , struct V_54 * V_55 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
if ( F_40 ( V_55 , L_25 , V_2 -> V_14 ,
V_2 -> V_48 ) )
return - V_56 ;
return 0 ;
}
static T_2 F_41 ( struct V_42 * V_43 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
int V_31 = snprintf ( V_59 , V_60 , L_26 , V_2 -> V_14 ,
V_2 -> V_48 ) ;
return ( V_31 >= V_60 ) ? ( V_60 - 1 ) : V_31 ;
}
static int T_3 F_42 ( void )
{
int V_5 ;
if ( ! F_43 ( V_61 ) )
return - V_26 ;
F_6 ( L_27 , V_11 , __LINE__ ) ;
F_44 ( & V_6 . V_7 ) ;
V_5 = F_45 ( & V_62 ) ;
F_3 ( V_5 ) ;
V_5 = F_46 ( & V_63 ) ;
F_3 ( V_5 ) ;
F_6 ( L_24 , V_11 , __LINE__ ) ;
return V_5 ;
}
static void * F_47 ( struct V_42 * V_43 , T_4 V_64 ,
T_5 * V_65 , T_6 V_66 ,
struct V_67 * V_68 )
{
int V_5 ;
struct V_1 * V_2 = F_31 ( V_43 ) ;
unsigned long V_69 ;
V_66 &= ~ ( V_70 | V_71 ) ;
V_66 |= V_72 ;
V_69 = F_48 ( V_66 , F_49 ( V_64 ) ) ;
if ( ! V_69 ) {
F_6 ( L_28 , V_11 , __LINE__ ) ;
goto V_73;
}
V_5 = F_50 ( V_2 -> V_74 , V_69 , V_64 , V_65 ,
V_75 | V_76 |
V_77 | V_78 ) ;
if ( V_5 ) {
F_6 ( L_29 ,
V_11 , __LINE__ , V_5 ) ;
F_3 ( L_30 ) ;
goto V_79;
}
return ( void * ) V_69 ;
V_79:
F_51 ( V_69 , F_49 ( V_64 ) ) ;
V_73:
V_65 = NULL ;
return NULL ;
}
static void F_52 ( struct V_42 * V_43 , T_4 V_64 , void * V_80 ,
T_5 V_65 , struct V_67 * V_68 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
F_53 ( V_2 -> V_74 , V_65 , V_64 ) ;
F_51 ( ( unsigned long ) V_80 , F_49 ( V_64 ) ) ;
}
static T_5 F_54 ( struct V_42 * V_43 , struct V_81 * V_81 ,
unsigned long V_82 , T_4 V_64 , enum V_83 V_84 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
int V_5 ;
T_5 V_30 ;
void * V_85 = F_55 ( V_81 ) + V_82 ;
V_5 = F_50 ( V_2 -> V_74 , ( unsigned long ) V_85 , V_64 ,
& V_30 ,
V_76 | V_75 |
V_77 | V_78 ) ;
if ( V_5 ) {
F_6 ( L_29 ,
V_11 , __LINE__ , V_5 ) ;
}
return V_30 ;
}
static T_5 F_56 ( struct V_42 * V_43 , struct V_81 * V_81 ,
unsigned long V_82 , T_4 V_64 ,
enum V_83 V_84 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
int V_5 ;
T_5 V_30 ;
T_1 V_86 ;
void * V_85 = F_55 ( V_81 ) + V_82 ;
V_86 = V_78 ;
switch ( V_84 ) {
case V_87 :
V_86 |= V_76 | V_75 | V_77 ;
break;
case V_88 :
V_86 |= V_76 | V_89 ;
break;
case V_90 :
V_86 |= V_75 | V_77 ;
break;
default:
F_16 () ;
} ;
V_5 = F_50 ( V_2 -> V_74 , ( unsigned long ) V_85 , V_64 ,
& V_30 , V_86 ) ;
if ( V_5 ) {
F_6 ( L_29 ,
V_11 , __LINE__ , V_5 ) ;
}
return V_30 ;
}
static void F_57 ( struct V_42 * V_43 , T_5 V_91 ,
T_4 V_64 , enum V_83 V_84 , struct V_67 * V_68 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
int V_5 ;
V_5 = F_53 ( V_2 -> V_74 , V_91 , V_64 ) ;
if ( V_5 ) {
F_6 ( L_31 ,
V_11 , __LINE__ , V_5 ) ;
}
}
static int F_58 ( struct V_42 * V_43 , struct V_92 * V_93 ,
int V_94 , enum V_83 V_84 , struct V_67 * V_68 )
{
#if F_59 ( V_95 )
F_3 ( L_32 ) ;
return - V_12 ;
#else
struct V_1 * V_2 = F_31 ( V_43 ) ;
struct V_92 * V_96 ;
int V_97 ;
F_60 (sgl, sg, nents, i) {
int V_5 = F_50 ( V_2 -> V_74 , F_61 ( V_96 ) ,
V_96 -> V_98 , & V_96 -> V_99 , 0 ) ;
if ( V_5 ) {
F_6 ( L_29 ,
V_11 , __LINE__ , V_5 ) ;
return - V_25 ;
}
V_96 -> V_100 = V_96 -> V_98 ;
}
return V_94 ;
#endif
}
static int F_62 ( struct V_42 * V_43 , struct V_92 * V_96 ,
int V_94 ,
enum V_83 V_84 ,
struct V_67 * V_68 )
{
F_16 () ;
return 0 ;
}
static void F_63 ( struct V_42 * V_43 , struct V_92 * V_96 ,
int V_94 , enum V_83 V_84 , struct V_67 * V_68 )
{
#if F_59 ( V_95 )
F_3 ( L_32 ) ;
#endif
}
static void F_64 ( struct V_42 * V_43 , struct V_92 * V_96 ,
int V_94 , enum V_83 V_84 ,
struct V_67 * V_68 )
{
F_16 () ;
}
static int F_65 ( struct V_42 * V_43 , T_1 V_101 )
{
return V_101 >= F_66 ( 32 ) ;
}
static T_1 F_67 ( struct V_42 * V_43 )
{
return F_66 ( 32 ) ;
}
static void F_68 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_31 ( V_43 ) ;
F_69 ( V_2 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_5 ;
static unsigned int V_102 ;
static unsigned int V_103 ;
static unsigned int V_104 ;
static unsigned int V_105 ;
if ( ! V_2 -> V_49 . V_106 )
V_2 -> V_49 . V_106 = & V_62 ;
V_2 -> V_49 . V_107 = & V_63 ;
V_2 -> V_49 . V_108 = F_68 ;
switch ( V_2 -> V_37 ) {
case V_40 :
V_2 -> V_49 . V_109 . V_110 = & V_111 ;
F_71 ( & V_2 -> V_49 , L_33 , ++ V_102 ) ;
break;
case V_38 :
V_2 -> V_49 . V_109 . V_110 = & V_112 ;
F_71 ( & V_2 -> V_49 , L_34 , ++ V_103 ) ;
break;
case V_113 :
F_71 ( & V_2 -> V_49 , L_35 , ++ V_104 ) ;
break;
case V_114 :
F_71 ( & V_2 -> V_49 , L_36 , ++ V_105 ) ;
break;
default:
F_16 () ;
} ;
V_2 -> V_49 . V_115 = NULL ;
F_72 ( & V_2 -> V_49 , 0 ) ;
F_6 ( L_37 , V_11 , __LINE__ , F_33 ( & V_2 -> V_49 ) ) ;
V_5 = F_45 ( & V_2 -> V_49 ) ;
return V_5 ;
}
int F_73 ( struct V_46 * V_47 )
{
int V_5 ;
F_6 ( L_38 , V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
if ( ! F_43 ( V_61 ) )
return - V_26 ;
V_47 -> V_49 . V_107 = & V_63 ;
V_5 = F_74 ( & V_47 -> V_49 ) ;
F_6 ( L_17 , V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
return V_5 ;
}
void F_75 ( struct V_46 * V_47 )
{
F_6 ( L_38 , V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
F_76 ( & V_47 -> V_49 ) ;
F_6 ( L_17 , V_11 , __LINE__ , V_47 -> V_49 . V_50 ) ;
}
