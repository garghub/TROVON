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
static int F_8 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
struct V_10 * * V_10 )
{
int V_11 ;
struct V_10 * V_12 ;
F_4 ( L_2 , V_6 , V_3 , V_9 ) ;
V_11 = F_9 () ;
if ( V_11 < 0 )
return V_11 ;
if ( V_9 -> V_13 != V_14 ) {
F_10 ( 1 ) ;
F_11 ( V_11 ) ;
return - V_8 ;
}
if ( V_9 -> V_15 . V_16 && V_9 -> V_15 . V_17 )
V_12 = F_12 ( & V_9 -> V_15 ,
V_3 -> V_18 . V_19 | V_20 ,
F_13 () ) ;
else
V_12 = F_6 ( - V_21 ) ;
if ( F_14 ( V_12 ) ) {
F_11 ( V_11 ) ;
V_11 = F_15 ( V_12 ) ;
} else {
* V_10 = V_12 ;
}
return V_11 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
struct V_1 * V_9 ,
struct V_10 * * V_10 )
{
int V_24 = 0 ;
F_4 ( L_3 , V_6 ,
V_3 , V_23 , V_9 ) ;
* V_10 = NULL ;
V_23 -> V_25 = V_7 ;
V_23 -> V_26 = V_7 ;
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = V_9 -> V_29 & V_30 ;
V_23 -> V_31 = F_17 ( V_9 -> V_32 ) ;
if ( F_18 ( V_9 -> V_29 & V_33 ) )
V_23 -> V_34 = V_35 ;
else {
V_23 -> V_34 = F_8 ( V_3 , V_9 , V_10 ) ;
if ( V_23 -> V_34 < 0 )
V_24 = V_23 -> V_34 ;
}
return V_24 ;
}
static struct V_36 * F_19 ( struct V_2 * V_3 ,
T_2 V_34 )
{
struct V_36 * V_37 , * V_38 = NULL ;
F_20 ( & V_3 -> V_18 . V_39 ) ;
F_21 (re, &group->fanotify_data.access_list, list) {
if ( V_37 -> V_34 != V_34 )
continue;
F_22 ( & V_37 -> V_40 ) ;
V_38 = V_37 ;
break;
}
F_23 ( & V_3 -> V_18 . V_39 ) ;
F_4 ( L_4 , V_6 , V_38 ) ;
return V_38 ;
}
static int F_24 ( struct V_2 * V_3 ,
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
V_37 = F_19 ( V_3 , V_34 ) ;
if ( ! V_37 )
return - V_46 ;
V_37 -> V_9 -> V_43 = V_43 ;
F_25 ( & V_3 -> V_18 . V_47 ) ;
F_26 ( V_48 , V_37 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_34 )
{
struct V_36 * V_37 ;
if ( ! ( V_9 -> V_29 & V_49 ) )
return 0 ;
V_37 = F_28 ( V_48 , V_50 ) ;
if ( ! V_37 )
return - V_51 ;
V_37 -> V_9 = V_9 ;
V_37 -> V_34 = V_34 ;
F_20 ( & V_3 -> V_18 . V_39 ) ;
if ( F_29 ( & V_3 -> V_18 . V_52 ) ) {
F_23 ( & V_3 -> V_18 . V_39 ) ;
F_26 ( V_48 , V_37 ) ;
V_9 -> V_43 = V_44 ;
return 0 ;
}
F_30 ( & V_37 -> V_40 , & V_3 -> V_18 . V_53 ) ;
F_23 ( & V_3 -> V_18 . V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_34 )
{
return 0 ;
}
static T_4 F_31 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
char T_5 * V_54 )
{
struct V_22 V_22 ;
struct V_10 * V_55 ;
int V_34 , V_24 ;
F_4 ( L_2 , V_6 , V_3 , V_9 ) ;
V_24 = F_16 ( V_3 , & V_22 , V_9 , & V_55 ) ;
if ( V_24 < 0 )
goto V_56;
V_34 = V_22 . V_34 ;
V_24 = - V_57 ;
if ( F_32 ( V_54 , & V_22 ,
V_22 . V_25 ) )
goto V_58;
V_24 = F_27 ( V_3 , V_9 , V_34 ) ;
if ( V_24 )
goto V_58;
if ( V_34 != V_35 )
F_33 ( V_34 , V_55 ) ;
return V_22 . V_25 ;
V_58:
if ( V_34 != V_35 ) {
F_11 ( V_34 ) ;
F_34 ( V_55 ) ;
}
V_56:
#ifdef F_35
if ( V_9 -> V_29 & V_49 ) {
V_9 -> V_43 = V_45 ;
F_25 ( & V_3 -> V_18 . V_47 ) ;
}
#endif
return V_24 ;
}
static unsigned int F_36 ( struct V_10 * V_10 , T_6 * V_59 )
{
struct V_2 * V_3 = V_10 -> V_60 ;
int V_24 = 0 ;
F_37 ( V_10 , & V_3 -> V_61 , V_59 ) ;
F_20 ( & V_3 -> V_5 ) ;
if ( ! F_5 ( V_3 ) )
V_24 = V_62 | V_63 ;
F_23 ( & V_3 -> V_5 ) ;
return V_24 ;
}
static T_4 F_38 ( struct V_10 * V_10 , char T_5 * V_54 ,
T_1 V_4 , T_7 * V_64 )
{
struct V_2 * V_3 ;
struct V_1 * V_65 ;
char T_5 * V_66 ;
int V_24 ;
F_39 ( V_59 ) ;
V_66 = V_54 ;
V_3 = V_10 -> V_60 ;
F_4 ( L_6 , V_6 , V_3 ) ;
while ( 1 ) {
F_40 ( & V_3 -> V_61 , & V_59 , V_67 ) ;
F_20 ( & V_3 -> V_5 ) ;
V_65 = F_1 ( V_3 , V_4 ) ;
F_23 ( & V_3 -> V_5 ) ;
if ( V_65 ) {
V_24 = F_15 ( V_65 ) ;
if ( F_14 ( V_65 ) )
break;
V_24 = F_31 ( V_3 , V_65 , V_54 ) ;
F_41 ( V_65 ) ;
if ( V_24 < 0 )
break;
V_54 += V_24 ;
V_4 -= V_24 ;
continue;
}
V_24 = - V_68 ;
if ( V_10 -> V_19 & V_69 )
break;
V_24 = - V_70 ;
if ( F_42 ( V_71 ) )
break;
if ( V_66 != V_54 )
break;
F_43 () ;
}
F_44 ( & V_3 -> V_61 , & V_59 ) ;
if ( V_66 != V_54 && V_24 != - V_57 )
V_24 = V_54 - V_66 ;
return V_24 ;
}
static T_4 F_45 ( struct V_10 * V_10 , const char T_5 * V_54 , T_1 V_4 , T_7 * V_64 )
{
#ifdef F_35
struct V_41 V_43 = { . V_34 = - 1 , . V_43 = - 1 } ;
struct V_2 * V_3 ;
int V_24 ;
V_3 = V_10 -> V_60 ;
if ( V_4 > sizeof( V_43 ) )
V_4 = sizeof( V_43 ) ;
F_4 ( L_7 , V_6 , V_3 , V_4 ) ;
if ( F_46 ( & V_43 , V_54 , V_4 ) )
return - V_57 ;
V_24 = F_24 ( V_3 , & V_43 ) ;
if ( V_24 < 0 )
V_4 = V_24 ;
return V_4 ;
#else
return - V_8 ;
#endif
}
static int F_47 ( struct V_72 * V_73 , struct V_10 * V_10 )
{
struct V_2 * V_3 = V_10 -> V_60 ;
#ifdef F_35
struct V_36 * V_37 , * V_74 ;
F_20 ( & V_3 -> V_18 . V_39 ) ;
F_48 ( & V_3 -> V_18 . V_52 ) ;
F_49 (re, lre, &group->fanotify_data.access_list, list) {
F_4 ( L_8 , V_6 , V_3 ,
V_37 , V_37 -> V_9 ) ;
F_22 ( & V_37 -> V_40 ) ;
V_37 -> V_9 -> V_43 = V_44 ;
F_26 ( V_48 , V_37 ) ;
}
F_23 ( & V_3 -> V_18 . V_39 ) ;
F_25 ( & V_3 -> V_18 . V_47 ) ;
#endif
F_50 ( V_3 ) ;
return 0 ;
}
static long F_51 ( struct V_10 * V_10 , unsigned int V_75 , unsigned long V_76 )
{
struct V_2 * V_3 ;
struct V_77 * V_78 ;
void T_5 * V_79 ;
int V_24 = - V_80 ;
T_1 V_81 = 0 ;
V_3 = V_10 -> V_60 ;
V_79 = ( void T_5 * ) V_76 ;
switch ( V_75 ) {
case V_82 :
F_20 ( & V_3 -> V_5 ) ;
F_21 (holder, &group->notification_list, event_list)
V_81 += V_7 ;
F_23 ( & V_3 -> V_5 ) ;
V_24 = F_52 ( V_81 , ( int T_5 * ) V_79 ) ;
break;
}
return V_24 ;
}
static void F_53 ( struct V_83 * V_84 )
{
F_26 ( V_85 , V_84 ) ;
}
static int F_54 ( int V_86 , const char T_5 * V_87 ,
struct V_15 * V_15 , unsigned int V_88 )
{
int V_24 ;
F_4 ( L_9 , V_6 ,
V_86 , V_87 , V_88 ) ;
if ( V_87 == NULL ) {
struct V_34 V_55 = F_55 ( V_86 ) ;
V_24 = - V_89 ;
if ( ! V_55 . V_10 )
goto V_56;
V_24 = - V_90 ;
if ( ( V_88 & V_91 ) &&
! ( F_56 ( V_55 . V_10 -> V_92 . V_16 -> V_93 -> V_94 ) ) ) {
F_57 ( V_55 ) ;
goto V_56;
}
* V_15 = V_55 . V_10 -> V_92 ;
F_58 ( V_15 ) ;
F_57 ( V_55 ) ;
} else {
unsigned int V_95 = 0 ;
if ( ! ( V_88 & V_96 ) )
V_95 |= V_97 ;
if ( V_88 & V_91 )
V_95 |= V_98 ;
V_24 = F_59 ( V_86 , V_87 , V_95 , V_15 ) ;
if ( V_24 )
goto V_56;
}
V_24 = F_60 ( V_15 -> V_16 -> V_93 , V_99 ) ;
if ( V_24 )
F_61 ( V_15 ) ;
V_56:
return V_24 ;
}
static T_3 F_62 ( struct V_83 * V_84 ,
T_3 V_29 ,
unsigned int V_88 )
{
T_3 V_100 ;
F_63 ( & V_84 -> V_101 ) ;
if ( ! ( V_88 & V_102 ) ) {
V_100 = V_84 -> V_29 ;
F_64 ( V_84 , ( V_100 & ~ V_29 ) ) ;
} else {
V_100 = V_84 -> V_103 ;
F_65 ( V_84 , ( V_100 & ~ V_29 ) ) ;
}
F_66 ( & V_84 -> V_101 ) ;
if ( ! ( V_100 & ~ V_29 ) )
F_67 ( V_84 ) ;
return V_29 & V_100 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_104 * V_17 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 = NULL ;
T_3 V_105 ;
V_84 = F_69 ( V_3 , V_17 ) ;
if ( ! V_84 )
return - V_46 ;
V_105 = F_62 ( V_84 , V_29 , V_88 ) ;
F_70 ( V_84 ) ;
if ( V_105 & F_71 ( V_17 ) -> V_106 )
F_72 ( V_17 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_72 * V_72 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 = NULL ;
T_3 V_105 ;
V_84 = F_74 ( V_3 , V_72 ) ;
if ( ! V_84 )
return - V_46 ;
V_105 = F_62 ( V_84 , V_29 , V_88 ) ;
F_70 ( V_84 ) ;
if ( V_105 & V_72 -> V_107 )
F_75 ( V_72 ) ;
return 0 ;
}
static T_3 F_76 ( struct V_83 * V_84 ,
T_3 V_29 ,
unsigned int V_88 )
{
T_3 V_100 = - 1 ;
F_63 ( & V_84 -> V_101 ) ;
if ( ! ( V_88 & V_102 ) ) {
V_100 = V_84 -> V_29 ;
F_64 ( V_84 , ( V_100 | V_29 ) ) ;
} else {
T_3 V_108 = V_84 -> V_103 | V_29 ;
F_65 ( V_84 , V_108 ) ;
if ( V_88 & V_109 )
V_84 -> V_88 |= V_110 ;
}
if ( ! ( V_88 & V_111 ) ) {
T_3 V_108 = V_84 -> V_103 | V_112 ;
F_65 ( V_84 , V_108 ) ;
}
F_66 ( & V_84 -> V_101 ) ;
return V_29 & ~ V_100 ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_104 * V_17 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 ;
T_3 V_113 ;
int V_24 = 0 ;
V_84 = F_69 ( V_3 , V_17 ) ;
if ( ! V_84 ) {
if ( F_29 ( & V_3 -> V_114 ) > V_3 -> V_18 . V_115 )
return - V_116 ;
V_84 = F_28 ( V_85 , V_50 ) ;
if ( ! V_84 )
return - V_51 ;
F_78 ( V_84 , F_53 ) ;
V_24 = F_79 ( V_84 , V_3 , NULL , V_17 , 0 ) ;
if ( V_24 )
goto V_117;
}
V_113 = F_76 ( V_84 , V_29 , V_88 ) ;
if ( V_113 & ~ F_71 ( V_17 ) -> V_106 )
F_72 ( V_17 ) ;
V_117:
F_70 ( V_84 ) ;
return V_24 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_72 * V_72 , T_3 V_29 ,
unsigned int V_88 )
{
struct V_83 * V_84 ;
T_3 V_113 ;
int V_24 = 0 ;
F_4 ( L_10 , V_6 , V_3 , V_72 ) ;
if ( ( V_88 & V_102 ) &&
! ( V_88 & V_109 ) &&
( F_29 ( & V_72 -> V_118 ) > 0 ) )
return 0 ;
V_84 = F_74 ( V_3 , V_72 ) ;
if ( ! V_84 ) {
if ( F_29 ( & V_3 -> V_114 ) > V_3 -> V_18 . V_115 )
return - V_116 ;
V_84 = F_28 ( V_85 , V_50 ) ;
if ( ! V_84 )
return - V_51 ;
F_78 ( V_84 , F_53 ) ;
V_24 = F_79 ( V_84 , V_3 , V_72 , NULL , 0 ) ;
if ( V_24 )
goto V_117;
}
V_113 = F_76 ( V_84 , V_29 , V_88 ) ;
if ( V_113 & ~ V_72 -> V_107 )
F_75 ( V_72 ) ;
V_117:
F_70 ( V_84 ) ;
return V_24 ;
}
T_8 (F_81)( int V_119 , unsigned int V_88 ,
T_9 V_29 , int V_86 ,
const char T_5 * V_120 )
{
struct V_72 * V_72 = NULL ;
struct V_104 * V_17 = NULL ;
struct V_2 * V_3 ;
struct V_34 V_55 ;
struct V_15 V_15 ;
int V_24 ;
F_4 ( L_11 ,
V_6 , V_119 , V_88 , V_86 , V_120 , V_29 ) ;
if ( V_29 & ( ( T_9 ) 0xffffffff << 32 ) )
return - V_8 ;
if ( V_88 & ~ V_121 )
return - V_8 ;
switch ( V_88 & ( V_122 | V_123 | V_124 ) ) {
case V_122 :
case V_123 :
if ( ! V_29 )
return - V_8 ;
case V_124 :
break;
default:
return - V_8 ;
}
if ( V_29 & V_112 ) {
V_88 |= V_111 ;
V_29 &= ~ V_112 ;
}
#ifdef F_35
if ( V_29 & ~ ( V_125 | V_49 | V_126 ) )
#else
if ( V_29 & ~ ( V_125 | V_126 ) )
#endif
return - V_8 ;
V_55 = F_55 ( V_119 ) ;
if ( F_18 ( ! V_55 . V_10 ) )
return - V_89 ;
V_24 = - V_8 ;
if ( F_18 ( V_55 . V_10 -> V_127 != & V_128 ) )
goto V_129;
V_3 = V_55 . V_10 -> V_60 ;
V_24 = - V_8 ;
if ( V_29 & V_49 &&
V_3 -> V_130 == V_131 )
goto V_129;
V_24 = F_54 ( V_86 , V_120 , & V_15 , V_88 ) ;
if ( V_24 )
goto V_129;
if ( ! ( V_88 & V_132 ) )
V_72 = V_15 . V_16 -> V_93 ;
else
V_17 = V_15 . V_17 ;
switch ( V_88 & ( V_122 | V_123 | V_124 ) ) {
case V_122 :
if ( V_88 & V_132 )
V_24 = F_77 ( V_3 , V_17 , V_29 , V_88 ) ;
else
V_24 = F_80 ( V_3 , V_72 , V_29 , V_88 ) ;
break;
case V_123 :
if ( V_88 & V_132 )
V_24 = F_68 ( V_3 , V_17 , V_29 , V_88 ) ;
else
V_24 = F_73 ( V_3 , V_72 , V_29 , V_88 ) ;
break;
case V_124 :
if ( V_88 & V_132 )
F_82 ( V_3 ) ;
else
F_83 ( V_3 ) ;
break;
default:
V_24 = - V_8 ;
}
F_61 ( & V_15 ) ;
V_129:
F_57 ( V_55 ) ;
return V_24 ;
}
T_10 long F_84 ( long V_119 , long V_88 , T_9 V_29 ,
long V_86 , long V_120 )
{
return F_85 ( ( int ) V_119 , ( unsigned int ) V_88 ,
V_29 , ( int ) V_86 ,
( const char T_5 * ) V_120 ) ;
}
static int T_11 F_86 ( void )
{
V_85 = F_87 ( V_83 , V_133 ) ;
V_48 = F_87 ( V_36 ,
V_133 ) ;
return 0 ;
}
