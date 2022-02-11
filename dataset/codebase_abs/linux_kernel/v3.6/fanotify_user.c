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
struct V_11 * V_12 ;
F_4 ( L_2 , V_6 , V_3 , V_9 ) ;
V_10 = F_9 () ;
if ( V_10 < 0 )
return V_10 ;
if ( V_9 -> V_13 != V_14 ) {
F_10 ( 1 ) ;
F_11 ( V_10 ) ;
return - V_8 ;
}
if ( V_9 -> V_15 . V_16 && V_9 -> V_15 . V_17 )
V_12 = F_12 ( & V_9 -> V_15 ,
V_3 -> V_18 . V_19 | V_20 ,
F_13 () ) ;
else
V_12 = F_6 ( - V_21 ) ;
if ( F_14 ( V_12 ) ) {
F_11 ( V_10 ) ;
V_10 = F_15 ( V_12 ) ;
} else {
F_16 ( V_10 , V_12 ) ;
}
return V_10 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
struct V_1 * V_9 )
{
int V_24 = 0 ;
F_4 ( L_3 , V_6 ,
V_3 , V_23 , V_9 ) ;
V_23 -> V_25 = V_7 ;
V_23 -> V_26 = V_7 ;
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = V_9 -> V_29 & V_30 ;
V_23 -> V_31 = F_18 ( V_9 -> V_32 ) ;
if ( F_19 ( V_9 -> V_29 & V_33 ) )
V_23 -> V_34 = V_35 ;
else {
V_23 -> V_34 = F_8 ( V_3 , V_9 ) ;
if ( V_23 -> V_34 < 0 )
V_24 = V_23 -> V_34 ;
}
return V_24 ;
}
static struct V_36 * F_20 ( struct V_2 * V_3 ,
T_2 V_34 )
{
struct V_36 * V_37 , * V_38 = NULL ;
F_21 ( & V_3 -> V_18 . V_39 ) ;
F_22 (re, &group->fanotify_data.access_list, list) {
if ( V_37 -> V_34 != V_34 )
continue;
F_23 ( & V_37 -> V_40 ) ;
V_38 = V_37 ;
break;
}
F_24 ( & V_3 -> V_18 . V_39 ) ;
F_4 ( L_4 , V_6 , V_38 ) ;
return V_38 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_36 * V_37 ;
T_2 V_34 = V_42 -> V_34 ;
T_3 V_43 = V_42 -> V_43 ;
F_4 ( L_5 , V_6 , V_3 ,
V_34 , V_43 ) ;
switch ( V_43 ) {
case V_44 :
case V_45 :
break;
default:
return - V_8 ;
}
if ( V_34 < 0 )
return - V_8 ;
V_37 = F_20 ( V_3 , V_34 ) ;
if ( ! V_37 )
return - V_46 ;
V_37 -> V_9 -> V_43 = V_43 ;
F_26 ( & V_3 -> V_18 . V_47 ) ;
F_27 ( V_48 , V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_34 )
{
struct V_36 * V_37 ;
if ( ! ( V_9 -> V_29 & V_49 ) )
return 0 ;
V_37 = F_29 ( V_48 , V_50 ) ;
if ( ! V_37 )
return - V_51 ;
V_37 -> V_9 = V_9 ;
V_37 -> V_34 = V_34 ;
F_21 ( & V_3 -> V_18 . V_39 ) ;
if ( F_30 ( & V_3 -> V_18 . V_52 ) ) {
F_24 ( & V_3 -> V_18 . V_39 ) ;
F_27 ( V_48 , V_37 ) ;
V_9 -> V_43 = V_44 ;
return 0 ;
}
F_31 ( & V_37 -> V_40 , & V_3 -> V_18 . V_53 ) ;
F_24 ( & V_3 -> V_18 . V_39 ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_34 )
{
struct V_36 * V_37 ;
if ( ! ( V_9 -> V_29 & V_49 ) )
return;
V_37 = F_20 ( V_3 , V_34 ) ;
if ( ! V_37 )
return;
F_2 ( V_37 -> V_9 != V_9 ) ;
F_27 ( V_48 , V_37 ) ;
return;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_34 )
{
return 0 ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_34 )
{
return;
}
static T_4 F_33 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
char T_5 * V_54 )
{
struct V_22 V_22 ;
int V_34 , V_24 ;
F_4 ( L_2 , V_6 , V_3 , V_9 ) ;
V_24 = F_17 ( V_3 , & V_22 , V_9 ) ;
if ( V_24 < 0 )
goto V_55;
V_34 = V_22 . V_34 ;
V_24 = F_28 ( V_3 , V_9 , V_34 ) ;
if ( V_24 )
goto V_56;
V_24 = - V_57 ;
if ( F_34 ( V_54 , & V_22 ,
V_22 . V_25 ) )
goto V_58;
return V_22 . V_25 ;
V_58:
F_32 ( V_3 , V_9 , V_34 ) ;
V_56:
if ( V_34 != V_35 )
F_35 ( V_34 ) ;
V_55:
#ifdef F_36
if ( V_9 -> V_29 & V_49 ) {
V_9 -> V_43 = V_45 ;
F_26 ( & V_3 -> V_18 . V_47 ) ;
}
#endif
return V_24 ;
}
static unsigned int F_37 ( struct V_11 * V_11 , T_6 * V_59 )
{
struct V_2 * V_3 = V_11 -> V_60 ;
int V_24 = 0 ;
F_38 ( V_11 , & V_3 -> V_61 , V_59 ) ;
F_21 ( & V_3 -> V_5 ) ;
if ( ! F_5 ( V_3 ) )
V_24 = V_62 | V_63 ;
F_24 ( & V_3 -> V_5 ) ;
return V_24 ;
}
static T_4 F_39 ( struct V_11 * V_11 , char T_5 * V_54 ,
T_1 V_4 , T_7 * V_64 )
{
struct V_2 * V_3 ;
struct V_1 * V_65 ;
char T_5 * V_66 ;
int V_24 ;
F_40 ( V_59 ) ;
V_66 = V_54 ;
V_3 = V_11 -> V_60 ;
F_4 ( L_6 , V_6 , V_3 ) ;
while ( 1 ) {
F_41 ( & V_3 -> V_61 , & V_59 , V_67 ) ;
F_21 ( & V_3 -> V_5 ) ;
V_65 = F_1 ( V_3 , V_4 ) ;
F_24 ( & V_3 -> V_5 ) ;
if ( V_65 ) {
V_24 = F_15 ( V_65 ) ;
if ( F_14 ( V_65 ) )
break;
V_24 = F_33 ( V_3 , V_65 , V_54 ) ;
F_42 ( V_65 ) ;
if ( V_24 < 0 )
break;
V_54 += V_24 ;
V_4 -= V_24 ;
continue;
}
V_24 = - V_68 ;
if ( V_11 -> V_19 & V_69 )
break;
V_24 = - V_70 ;
if ( F_43 ( V_71 ) )
break;
if ( V_66 != V_54 )
break;
F_44 () ;
}
F_45 ( & V_3 -> V_61 , & V_59 ) ;
if ( V_66 != V_54 && V_24 != - V_57 )
V_24 = V_54 - V_66 ;
return V_24 ;
}
static T_4 F_46 ( struct V_11 * V_11 , const char T_5 * V_54 , T_1 V_4 , T_7 * V_64 )
{
#ifdef F_36
struct V_41 V_43 = { . V_34 = - 1 , . V_43 = - 1 } ;
struct V_2 * V_3 ;
int V_24 ;
V_3 = V_11 -> V_60 ;
if ( V_4 > sizeof( V_43 ) )
V_4 = sizeof( V_43 ) ;
F_4 ( L_7 , V_6 , V_3 , V_4 ) ;
if ( F_47 ( & V_43 , V_54 , V_4 ) )
return - V_57 ;
V_24 = F_25 ( V_3 , & V_43 ) ;
if ( V_24 < 0 )
V_4 = V_24 ;
return V_4 ;
#else
return - V_8 ;
#endif
}
static int F_48 ( struct V_72 * V_73 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_60 ;
#ifdef F_36
struct V_36 * V_37 , * V_74 ;
F_21 ( & V_3 -> V_18 . V_39 ) ;
F_49 ( & V_3 -> V_18 . V_52 ) ;
F_50 (re, lre, &group->fanotify_data.access_list, list) {
F_4 ( L_8 , V_6 , V_3 ,
V_37 , V_37 -> V_9 ) ;
F_23 ( & V_37 -> V_40 ) ;
V_37 -> V_9 -> V_43 = V_44 ;
F_27 ( V_48 , V_37 ) ;
}
F_24 ( & V_3 -> V_18 . V_39 ) ;
F_26 ( & V_3 -> V_18 . V_47 ) ;
#endif
F_51 ( V_3 ) ;
return 0 ;
}
static long F_52 ( struct V_11 * V_11 , unsigned int V_75 , unsigned long V_76 )
{
struct V_2 * V_3 ;
struct V_77 * V_78 ;
void T_5 * V_79 ;
int V_24 = - V_80 ;
T_1 V_81 = 0 ;
V_3 = V_11 -> V_60 ;
V_79 = ( void T_5 * ) V_76 ;
switch ( V_75 ) {
case V_82 :
F_21 ( & V_3 -> V_5 ) ;
F_22 (holder, &group->notification_list, event_list)
V_81 += V_7 ;
F_24 ( & V_3 -> V_5 ) ;
V_24 = F_53 ( V_81 , ( int T_5 * ) V_79 ) ;
break;
}
return V_24 ;
}
static void F_54 ( struct V_83 * V_84 )
{
F_27 ( V_85 , V_84 ) ;
}
static int F_55 ( int V_86 , const char T_5 * V_87 ,
struct V_15 * V_15 , unsigned int V_88 )
{
int V_24 ;
F_4 ( L_9 , V_6 ,
V_86 , V_87 , V_88 ) ;
if ( V_87 == NULL ) {
struct V_11 * V_11 ;
int V_89 ;
V_24 = - V_90 ;
V_11 = F_56 ( V_86 , & V_89 ) ;
if ( ! V_11 )
goto V_55;
V_24 = - V_91 ;
if ( ( V_88 & V_92 ) &&
! ( F_57 ( V_11 -> V_93 . V_16 -> V_94 -> V_95 ) ) ) {
F_58 ( V_11 , V_89 ) ;
goto V_55;
}
* V_15 = V_11 -> V_93 ;
F_59 ( V_15 ) ;
F_58 ( V_11 , V_89 ) ;
} else {
unsigned int V_96 = 0 ;
if ( ! ( V_88 & V_97 ) )
V_96 |= V_98 ;
if ( V_88 & V_92 )
V_96 |= V_99 ;
V_24 = F_60 ( V_86 , V_87 , V_96 , V_15 ) ;
if ( V_24 )
goto V_55;
}
V_24 = F_61 ( V_15 -> V_16 -> V_94 , V_100 ) ;
if ( V_24 )
F_62 ( V_15 ) ;
V_55:
return V_24 ;
}
static T_3 F_63 ( struct V_83 * V_84 ,
T_3 V_29 ,
unsigned int V_88 )
{
T_3 V_101 ;
F_64 ( & V_84 -> V_102 ) ;
if ( ! ( V_88 & V_103 ) ) {
V_101 = V_84 -> V_29 ;
F_65 ( V_84 , ( V_101 & ~ V_29 ) ) ;
} else {
V_101 = V_84 -> V_104 ;
F_66 ( V_84 , ( V_101 & ~ V_29 ) ) ;
}
F_67 ( & V_84 -> V_102 ) ;
if ( ! ( V_101 & ~ V_29 ) )
F_68 ( V_84 ) ;
return V_29 & V_101 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_105 * V_17 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 = NULL ;
T_3 V_106 ;
V_84 = F_70 ( V_3 , V_17 ) ;
if ( ! V_84 )
return - V_46 ;
V_106 = F_63 ( V_84 , V_29 , V_88 ) ;
F_71 ( V_84 ) ;
if ( V_106 & F_72 ( V_17 ) -> V_107 )
F_73 ( V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_72 * V_72 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 = NULL ;
T_3 V_106 ;
V_84 = F_75 ( V_3 , V_72 ) ;
if ( ! V_84 )
return - V_46 ;
V_106 = F_63 ( V_84 , V_29 , V_88 ) ;
F_71 ( V_84 ) ;
if ( V_106 & V_72 -> V_108 )
F_76 ( V_72 ) ;
return 0 ;
}
static T_3 F_77 ( struct V_83 * V_84 ,
T_3 V_29 ,
unsigned int V_88 )
{
T_3 V_101 = - 1 ;
F_64 ( & V_84 -> V_102 ) ;
if ( ! ( V_88 & V_103 ) ) {
V_101 = V_84 -> V_29 ;
F_65 ( V_84 , ( V_101 | V_29 ) ) ;
} else {
T_3 V_109 = V_84 -> V_104 | V_29 ;
F_66 ( V_84 , V_109 ) ;
if ( V_88 & V_110 )
V_84 -> V_88 |= V_111 ;
}
if ( ! ( V_88 & V_112 ) ) {
T_3 V_109 = V_84 -> V_104 | V_113 ;
F_66 ( V_84 , V_109 ) ;
}
F_67 ( & V_84 -> V_102 ) ;
return V_29 & ~ V_101 ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_105 * V_17 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 ;
T_3 V_114 ;
int V_24 = 0 ;
V_84 = F_70 ( V_3 , V_17 ) ;
if ( ! V_84 ) {
if ( F_30 ( & V_3 -> V_115 ) > V_3 -> V_18 . V_116 )
return - V_117 ;
V_84 = F_29 ( V_85 , V_50 ) ;
if ( ! V_84 )
return - V_51 ;
F_79 ( V_84 , F_54 ) ;
V_24 = F_80 ( V_84 , V_3 , NULL , V_17 , 0 ) ;
if ( V_24 )
goto V_118;
}
V_114 = F_77 ( V_84 , V_29 , V_88 ) ;
if ( V_114 & ~ F_72 ( V_17 ) -> V_107 )
F_73 ( V_17 ) ;
V_118:
F_71 ( V_84 ) ;
return V_24 ;
}
static int F_81 ( struct V_2 * V_3 ,
struct V_72 * V_72 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 ;
T_3 V_114 ;
int V_24 = 0 ;
F_4 ( L_10 , V_6 , V_3 , V_72 ) ;
if ( ( V_88 & V_103 ) &&
! ( V_88 & V_110 ) &&
( F_30 ( & V_72 -> V_119 ) > 0 ) )
return 0 ;
V_84 = F_75 ( V_3 , V_72 ) ;
if ( ! V_84 ) {
if ( F_30 ( & V_3 -> V_115 ) > V_3 -> V_18 . V_116 )
return - V_117 ;
V_84 = F_29 ( V_85 , V_50 ) ;
if ( ! V_84 )
return - V_51 ;
F_79 ( V_84 , F_54 ) ;
V_24 = F_80 ( V_84 , V_3 , V_72 , NULL , 0 ) ;
if ( V_24 )
goto V_118;
}
V_114 = F_77 ( V_84 , V_29 , V_88 ) ;
if ( V_114 & ~ V_72 -> V_108 )
F_76 ( V_72 ) ;
V_118:
F_71 ( V_84 ) ;
return V_24 ;
}
T_8 (F_82)( int V_120 , unsigned int V_88 ,
T_9 V_29 , int V_86 ,
const char T_5 * V_121 )
{
struct V_72 * V_72 = NULL ;
struct V_105 * V_17 = NULL ;
struct V_2 * V_3 ;
struct V_11 * V_122 ;
struct V_15 V_15 ;
int V_24 , V_89 ;
F_4 ( L_11 ,
V_6 , V_120 , V_88 , V_86 , V_121 , V_29 ) ;
if ( V_29 & ( ( T_9 ) 0xffffffff << 32 ) )
return - V_8 ;
if ( V_88 & ~ V_123 )
return - V_8 ;
switch ( V_88 & ( V_124 | V_125 | V_126 ) ) {
case V_124 :
case V_125 :
if ( ! V_29 )
return - V_8 ;
case V_126 :
break;
default:
return - V_8 ;
}
if ( V_29 & V_113 ) {
V_88 |= V_112 ;
V_29 &= ~ V_113 ;
}
#ifdef F_36
if ( V_29 & ~ ( V_127 | V_49 | V_128 ) )
#else
if ( V_29 & ~ ( V_127 | V_128 ) )
#endif
return - V_8 ;
V_122 = F_56 ( V_120 , & V_89 ) ;
if ( F_19 ( ! V_122 ) )
return - V_90 ;
V_24 = - V_8 ;
if ( F_19 ( V_122 -> V_129 != & V_130 ) )
goto V_131;
V_3 = V_122 -> V_60 ;
V_24 = - V_8 ;
if ( V_29 & V_49 &&
V_3 -> V_132 == V_133 )
goto V_131;
V_24 = F_55 ( V_86 , V_121 , & V_15 , V_88 ) ;
if ( V_24 )
goto V_131;
if ( ! ( V_88 & V_134 ) )
V_72 = V_15 . V_16 -> V_94 ;
else
V_17 = V_15 . V_17 ;
switch ( V_88 & ( V_124 | V_125 | V_126 ) ) {
case V_124 :
if ( V_88 & V_134 )
V_24 = F_78 ( V_3 , V_17 , V_29 , V_88 ) ;
else
V_24 = F_81 ( V_3 , V_72 , V_29 , V_88 ) ;
break;
case V_125 :
if ( V_88 & V_134 )
V_24 = F_69 ( V_3 , V_17 , V_29 , V_88 ) ;
else
V_24 = F_74 ( V_3 , V_72 , V_29 , V_88 ) ;
break;
case V_126 :
if ( V_88 & V_134 )
F_83 ( V_3 ) ;
else
F_84 ( V_3 ) ;
break;
default:
V_24 = - V_8 ;
}
F_62 ( & V_15 ) ;
V_131:
F_58 ( V_122 , V_89 ) ;
return V_24 ;
}
T_10 long F_85 ( long V_120 , long V_88 , T_9 V_29 ,
long V_86 , long V_121 )
{
return F_86 ( ( int ) V_120 , ( unsigned int ) V_88 ,
V_29 , ( int ) V_86 ,
( const char T_5 * ) V_121 ) ;
}
static int T_11 F_87 ( void )
{
V_85 = F_88 ( V_83 , V_135 ) ;
V_48 = F_88 ( V_36 ,
V_135 ) ;
return 0 ;
}
