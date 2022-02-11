static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
F_2 ( ! F_3 ( & V_3 -> V_5 ) ) ;
F_4 ( L_1 , V_6 , V_3 , V_4 ) ;
if ( F_5 ( V_3 ) )
return NULL ;
if ( V_7 > V_4 )
return F_6 ( - V_8 ) ;
return F_7 ( V_3 ) ;
}
static int F_8 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
int V_10 ;
struct V_11 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_4 ( L_2 , V_6 , V_3 , V_9 ) ;
V_10 = F_9 () ;
if ( V_10 < 0 )
return V_10 ;
if ( V_9 -> V_16 != V_17 ) {
F_10 ( 1 ) ;
F_11 ( V_10 ) ;
return - V_8 ;
}
V_11 = F_12 ( V_9 -> V_18 . V_11 ) ;
V_13 = F_13 ( V_9 -> V_18 . V_13 ) ;
if ( V_11 && V_13 )
V_15 = F_14 ( V_11 , V_13 ,
V_3 -> V_19 . V_20 | V_21 ,
F_15 () ) ;
else
V_15 = F_6 ( - V_22 ) ;
if ( F_16 ( V_15 ) ) {
F_11 ( V_10 ) ;
V_10 = F_17 ( V_15 ) ;
} else {
F_18 ( V_10 , V_15 ) ;
}
return V_10 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
struct V_1 * V_9 )
{
int V_25 = 0 ;
F_4 ( L_3 , V_6 ,
V_3 , V_24 , V_9 ) ;
V_24 -> V_26 = V_7 ;
V_24 -> V_27 = V_7 ;
V_24 -> V_28 = V_29 ;
V_24 -> V_30 = V_9 -> V_30 & V_31 ;
V_24 -> V_32 = F_20 ( V_9 -> V_33 ) ;
if ( F_21 ( V_9 -> V_30 & V_34 ) )
V_24 -> V_35 = V_36 ;
else {
V_24 -> V_35 = F_8 ( V_3 , V_9 ) ;
if ( V_24 -> V_35 < 0 )
V_25 = V_24 -> V_35 ;
}
return V_25 ;
}
static struct V_37 * F_22 ( struct V_2 * V_3 ,
T_2 V_35 )
{
struct V_37 * V_38 , * V_39 = NULL ;
F_23 ( & V_3 -> V_19 . V_40 ) ;
F_24 (re, &group->fanotify_data.access_list, list) {
if ( V_38 -> V_35 != V_35 )
continue;
F_25 ( & V_38 -> V_41 ) ;
V_39 = V_38 ;
break;
}
F_26 ( & V_3 -> V_19 . V_40 ) ;
F_4 ( L_4 , V_6 , V_39 ) ;
return V_39 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_37 * V_38 ;
T_2 V_35 = V_43 -> V_35 ;
T_3 V_44 = V_43 -> V_44 ;
F_4 ( L_5 , V_6 , V_3 ,
V_35 , V_44 ) ;
switch ( V_44 ) {
case V_45 :
case V_46 :
break;
default:
return - V_8 ;
}
if ( V_35 < 0 )
return - V_8 ;
V_38 = F_22 ( V_3 , V_35 ) ;
if ( ! V_38 )
return - V_47 ;
V_38 -> V_9 -> V_44 = V_44 ;
F_28 ( & V_3 -> V_19 . V_48 ) ;
F_29 ( V_49 , V_38 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_35 )
{
struct V_37 * V_38 ;
if ( ! ( V_9 -> V_30 & V_50 ) )
return 0 ;
V_38 = F_31 ( V_49 , V_51 ) ;
if ( ! V_38 )
return - V_52 ;
V_38 -> V_9 = V_9 ;
V_38 -> V_35 = V_35 ;
F_23 ( & V_3 -> V_19 . V_40 ) ;
if ( F_32 ( & V_3 -> V_19 . V_53 ) ) {
F_26 ( & V_3 -> V_19 . V_40 ) ;
F_29 ( V_49 , V_38 ) ;
V_9 -> V_44 = V_45 ;
return 0 ;
}
F_33 ( & V_38 -> V_41 , & V_3 -> V_19 . V_54 ) ;
F_26 ( & V_3 -> V_19 . V_40 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_35 )
{
struct V_37 * V_38 ;
if ( ! ( V_9 -> V_30 & V_50 ) )
return;
V_38 = F_22 ( V_3 , V_35 ) ;
if ( ! V_38 )
return;
F_2 ( V_38 -> V_9 != V_9 ) ;
F_29 ( V_49 , V_38 ) ;
return;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_35 )
{
return 0 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_35 )
{
return;
}
static T_4 F_35 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
char T_5 * V_55 )
{
struct V_23 V_23 ;
int V_35 , V_25 ;
F_4 ( L_2 , V_6 , V_3 , V_9 ) ;
V_25 = F_19 ( V_3 , & V_23 , V_9 ) ;
if ( V_25 < 0 )
goto V_56;
V_35 = V_23 . V_35 ;
V_25 = F_30 ( V_3 , V_9 , V_35 ) ;
if ( V_25 )
goto V_57;
V_25 = - V_58 ;
if ( F_36 ( V_55 , & V_23 ,
V_23 . V_26 ) )
goto V_59;
return V_23 . V_26 ;
V_59:
F_34 ( V_3 , V_9 , V_35 ) ;
V_57:
if ( V_35 != V_36 )
F_37 ( V_35 ) ;
V_56:
#ifdef F_38
if ( V_9 -> V_30 & V_50 ) {
V_9 -> V_44 = V_46 ;
F_28 ( & V_3 -> V_19 . V_48 ) ;
}
#endif
return V_25 ;
}
static unsigned int F_39 ( struct V_14 * V_14 , T_6 * V_60 )
{
struct V_2 * V_3 = V_14 -> V_61 ;
int V_25 = 0 ;
F_40 ( V_14 , & V_3 -> V_62 , V_60 ) ;
F_23 ( & V_3 -> V_5 ) ;
if ( ! F_5 ( V_3 ) )
V_25 = V_63 | V_64 ;
F_26 ( & V_3 -> V_5 ) ;
return V_25 ;
}
static T_4 F_41 ( struct V_14 * V_14 , char T_5 * V_55 ,
T_1 V_4 , T_7 * V_65 )
{
struct V_2 * V_3 ;
struct V_1 * V_66 ;
char T_5 * V_67 ;
int V_25 ;
F_42 ( V_60 ) ;
V_67 = V_55 ;
V_3 = V_14 -> V_61 ;
F_4 ( L_6 , V_6 , V_3 ) ;
while ( 1 ) {
F_43 ( & V_3 -> V_62 , & V_60 , V_68 ) ;
F_23 ( & V_3 -> V_5 ) ;
V_66 = F_1 ( V_3 , V_4 ) ;
F_26 ( & V_3 -> V_5 ) ;
if ( V_66 ) {
V_25 = F_17 ( V_66 ) ;
if ( F_16 ( V_66 ) )
break;
V_25 = F_35 ( V_3 , V_66 , V_55 ) ;
F_44 ( V_66 ) ;
if ( V_25 < 0 )
break;
V_55 += V_25 ;
V_4 -= V_25 ;
continue;
}
V_25 = - V_69 ;
if ( V_14 -> V_20 & V_70 )
break;
V_25 = - V_71 ;
if ( F_45 ( V_72 ) )
break;
if ( V_67 != V_55 )
break;
F_46 () ;
}
F_47 ( & V_3 -> V_62 , & V_60 ) ;
if ( V_67 != V_55 && V_25 != - V_58 )
V_25 = V_55 - V_67 ;
return V_25 ;
}
static T_4 F_48 ( struct V_14 * V_14 , const char T_5 * V_55 , T_1 V_4 , T_7 * V_65 )
{
#ifdef F_38
struct V_42 V_44 = { . V_35 = - 1 , . V_44 = - 1 } ;
struct V_2 * V_3 ;
int V_25 ;
V_3 = V_14 -> V_61 ;
if ( V_4 > sizeof( V_44 ) )
V_4 = sizeof( V_44 ) ;
F_4 ( L_7 , V_6 , V_3 , V_4 ) ;
if ( F_49 ( & V_44 , V_55 , V_4 ) )
return - V_58 ;
V_25 = F_27 ( V_3 , & V_44 ) ;
if ( V_25 < 0 )
V_4 = V_25 ;
return V_4 ;
#else
return - V_8 ;
#endif
}
static int F_50 ( struct V_73 * V_74 , struct V_14 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_61 ;
#ifdef F_38
struct V_37 * V_38 , * V_75 ;
F_23 ( & V_3 -> V_19 . V_40 ) ;
F_51 ( & V_3 -> V_19 . V_53 ) ;
F_52 (re, lre, &group->fanotify_data.access_list, list) {
F_4 ( L_8 , V_6 , V_3 ,
V_38 , V_38 -> V_9 ) ;
F_25 ( & V_38 -> V_41 ) ;
V_38 -> V_9 -> V_44 = V_45 ;
F_29 ( V_49 , V_38 ) ;
}
F_26 ( & V_3 -> V_19 . V_40 ) ;
F_28 ( & V_3 -> V_19 . V_48 ) ;
#endif
F_53 ( V_3 ) ;
return 0 ;
}
static long F_54 ( struct V_14 * V_14 , unsigned int V_76 , unsigned long V_77 )
{
struct V_2 * V_3 ;
struct V_78 * V_79 ;
void T_5 * V_80 ;
int V_25 = - V_81 ;
T_1 V_82 = 0 ;
V_3 = V_14 -> V_61 ;
V_80 = ( void T_5 * ) V_77 ;
switch ( V_76 ) {
case V_83 :
F_23 ( & V_3 -> V_5 ) ;
F_24 (holder, &group->notification_list, event_list)
V_82 += V_7 ;
F_26 ( & V_3 -> V_5 ) ;
V_25 = F_55 ( V_82 , ( int T_5 * ) V_80 ) ;
break;
}
return V_25 ;
}
static void F_56 ( struct V_84 * V_85 )
{
F_29 ( V_86 , V_85 ) ;
}
static int F_57 ( int V_87 , const char T_5 * V_88 ,
struct V_18 * V_18 , unsigned int V_89 )
{
int V_25 ;
F_4 ( L_9 , V_6 ,
V_87 , V_88 , V_89 ) ;
if ( V_88 == NULL ) {
struct V_14 * V_14 ;
int V_90 ;
V_25 = - V_91 ;
V_14 = F_58 ( V_87 , & V_90 ) ;
if ( ! V_14 )
goto V_56;
V_25 = - V_92 ;
if ( ( V_89 & V_93 ) &&
! ( F_59 ( V_14 -> V_94 . V_11 -> V_95 -> V_96 ) ) ) {
F_60 ( V_14 , V_90 ) ;
goto V_56;
}
* V_18 = V_14 -> V_94 ;
F_61 ( V_18 ) ;
F_60 ( V_14 , V_90 ) ;
} else {
unsigned int V_97 = 0 ;
if ( ! ( V_89 & V_98 ) )
V_97 |= V_99 ;
if ( V_89 & V_93 )
V_97 |= V_100 ;
V_25 = F_62 ( V_87 , V_88 , V_97 , V_18 ) ;
if ( V_25 )
goto V_56;
}
V_25 = F_63 ( V_18 -> V_11 -> V_95 , V_101 ) ;
if ( V_25 )
F_64 ( V_18 ) ;
V_56:
return V_25 ;
}
static T_3 F_65 ( struct V_84 * V_85 ,
T_3 V_30 ,
unsigned int V_89 )
{
T_3 V_102 ;
F_66 ( & V_85 -> V_103 ) ;
if ( ! ( V_89 & V_104 ) ) {
V_102 = V_85 -> V_30 ;
F_67 ( V_85 , ( V_102 & ~ V_30 ) ) ;
} else {
V_102 = V_85 -> V_105 ;
F_68 ( V_85 , ( V_102 & ~ V_30 ) ) ;
}
F_69 ( & V_85 -> V_103 ) ;
if ( ! ( V_102 & ~ V_30 ) )
F_70 ( V_85 ) ;
return V_30 & V_102 ;
}
static int F_71 ( struct V_2 * V_3 ,
struct V_12 * V_13 , T_3 V_30 ,
unsigned int V_89 )
{
struct V_84 * V_85 = NULL ;
T_3 V_106 ;
V_85 = F_72 ( V_3 , V_13 ) ;
if ( ! V_85 )
return - V_47 ;
V_106 = F_65 ( V_85 , V_30 , V_89 ) ;
F_73 ( V_85 ) ;
if ( V_106 & V_13 -> V_107 )
F_74 ( V_13 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_73 * V_73 , T_3 V_30 ,
unsigned int V_89 )
{
struct V_84 * V_85 = NULL ;
T_3 V_106 ;
V_85 = F_76 ( V_3 , V_73 ) ;
if ( ! V_85 )
return - V_47 ;
V_106 = F_65 ( V_85 , V_30 , V_89 ) ;
F_73 ( V_85 ) ;
if ( V_106 & V_73 -> V_108 )
F_77 ( V_73 ) ;
return 0 ;
}
static T_3 F_78 ( struct V_84 * V_85 ,
T_3 V_30 ,
unsigned int V_89 )
{
T_3 V_102 = - 1 ;
F_66 ( & V_85 -> V_103 ) ;
if ( ! ( V_89 & V_104 ) ) {
V_102 = V_85 -> V_30 ;
F_67 ( V_85 , ( V_102 | V_30 ) ) ;
} else {
T_3 V_109 = V_85 -> V_105 | V_30 ;
F_68 ( V_85 , V_109 ) ;
if ( V_89 & V_110 )
V_85 -> V_89 |= V_111 ;
}
if ( ! ( V_89 & V_112 ) ) {
T_3 V_109 = V_85 -> V_105 | V_113 ;
F_68 ( V_85 , V_109 ) ;
}
F_69 ( & V_85 -> V_103 ) ;
return V_30 & ~ V_102 ;
}
static int F_79 ( struct V_2 * V_3 ,
struct V_12 * V_13 , T_3 V_30 ,
unsigned int V_89 )
{
struct V_84 * V_85 ;
T_3 V_114 ;
int V_25 = 0 ;
V_85 = F_72 ( V_3 , V_13 ) ;
if ( ! V_85 ) {
if ( F_32 ( & V_3 -> V_115 ) > V_3 -> V_19 . V_116 )
return - V_117 ;
V_85 = F_31 ( V_86 , V_51 ) ;
if ( ! V_85 )
return - V_52 ;
F_80 ( V_85 , F_56 ) ;
V_25 = F_81 ( V_85 , V_3 , NULL , V_13 , 0 ) ;
if ( V_25 )
goto V_118;
}
V_114 = F_78 ( V_85 , V_30 , V_89 ) ;
if ( V_114 & ~ V_13 -> V_107 )
F_74 ( V_13 ) ;
V_118:
F_73 ( V_85 ) ;
return V_25 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_73 * V_73 , T_3 V_30 ,
unsigned int V_89 )
{
struct V_84 * V_85 ;
T_3 V_114 ;
int V_25 = 0 ;
F_4 ( L_10 , V_6 , V_3 , V_73 ) ;
if ( ( V_89 & V_104 ) &&
! ( V_89 & V_110 ) &&
( F_32 ( & V_73 -> V_119 ) > 0 ) )
return 0 ;
V_85 = F_76 ( V_3 , V_73 ) ;
if ( ! V_85 ) {
if ( F_32 ( & V_3 -> V_115 ) > V_3 -> V_19 . V_116 )
return - V_117 ;
V_85 = F_31 ( V_86 , V_51 ) ;
if ( ! V_85 )
return - V_52 ;
F_80 ( V_85 , F_56 ) ;
V_25 = F_81 ( V_85 , V_3 , V_73 , NULL , 0 ) ;
if ( V_25 )
goto V_118;
}
V_114 = F_78 ( V_85 , V_30 , V_89 ) ;
if ( V_114 & ~ V_73 -> V_108 )
F_77 ( V_73 ) ;
V_118:
F_73 ( V_85 ) ;
return V_25 ;
}
T_8 (F_83)( int V_120 , unsigned int V_89 ,
T_9 V_30 , int V_87 ,
const char T_5 * V_121 )
{
struct V_73 * V_73 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_2 * V_3 ;
struct V_14 * V_122 ;
struct V_18 V_18 ;
int V_25 , V_90 ;
F_4 ( L_11 ,
V_6 , V_120 , V_89 , V_87 , V_121 , V_30 ) ;
if ( V_30 & ( ( T_9 ) 0xffffffff << 32 ) )
return - V_8 ;
if ( V_89 & ~ V_123 )
return - V_8 ;
switch ( V_89 & ( V_124 | V_125 | V_126 ) ) {
case V_124 :
case V_125 :
if ( ! V_30 )
return - V_8 ;
case V_126 :
break;
default:
return - V_8 ;
}
if ( V_30 & V_113 ) {
V_89 |= V_112 ;
V_30 &= ~ V_113 ;
}
#ifdef F_38
if ( V_30 & ~ ( V_127 | V_50 | V_128 ) )
#else
if ( V_30 & ~ ( V_127 | V_128 ) )
#endif
return - V_8 ;
V_122 = F_58 ( V_120 , & V_90 ) ;
if ( F_21 ( ! V_122 ) )
return - V_91 ;
V_25 = - V_8 ;
if ( F_21 ( V_122 -> V_129 != & V_130 ) )
goto V_131;
V_3 = V_122 -> V_61 ;
V_25 = - V_8 ;
if ( V_30 & V_50 &&
V_3 -> V_132 == V_133 )
goto V_131;
V_25 = F_57 ( V_87 , V_121 , & V_18 , V_89 ) ;
if ( V_25 )
goto V_131;
if ( ! ( V_89 & V_134 ) )
V_73 = V_18 . V_11 -> V_95 ;
else
V_13 = V_18 . V_13 ;
switch ( V_89 & ( V_124 | V_125 | V_126 ) ) {
case V_124 :
if ( V_89 & V_134 )
V_25 = F_79 ( V_3 , V_13 , V_30 , V_89 ) ;
else
V_25 = F_82 ( V_3 , V_73 , V_30 , V_89 ) ;
break;
case V_125 :
if ( V_89 & V_134 )
V_25 = F_71 ( V_3 , V_13 , V_30 , V_89 ) ;
else
V_25 = F_75 ( V_3 , V_73 , V_30 , V_89 ) ;
break;
case V_126 :
if ( V_89 & V_134 )
F_84 ( V_3 ) ;
else
F_85 ( V_3 ) ;
break;
default:
V_25 = - V_8 ;
}
F_64 ( & V_18 ) ;
V_131:
F_60 ( V_122 , V_90 ) ;
return V_25 ;
}
T_10 long F_86 ( long V_120 , long V_89 , T_9 V_30 ,
long V_87 , long V_121 )
{
return F_87 ( ( int ) V_120 , ( unsigned int ) V_89 ,
V_30 , ( int ) V_87 ,
( const char T_5 * ) V_121 ) ;
}
static int T_11 F_88 ( void )
{
V_86 = F_89 ( V_84 , V_135 ) ;
V_49 = F_89 ( V_37 ,
V_135 ) ;
return 0 ;
}
