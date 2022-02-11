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
struct V_9 * V_10 ,
struct V_11 * * V_11 )
{
int V_12 ;
struct V_11 * V_13 ;
F_4 ( L_2 , V_6 , V_3 , V_10 ) ;
V_12 = F_9 () ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 -> V_14 . V_15 && V_10 -> V_14 . V_16 )
V_13 = F_10 ( & V_10 -> V_14 ,
V_3 -> V_17 . V_18 | V_19 ,
F_11 () ) ;
else
V_13 = F_6 ( - V_20 ) ;
if ( F_12 ( V_13 ) ) {
F_13 ( V_12 ) ;
V_12 = F_14 ( V_13 ) ;
} else {
* V_11 = V_13 ;
}
return V_12 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_1 * V_23 ,
struct V_11 * * V_11 )
{
int V_24 = 0 ;
struct V_9 * V_10 ;
F_4 ( L_3 , V_6 ,
V_3 , V_22 , V_23 ) ;
* V_11 = NULL ;
V_10 = F_16 ( V_23 , struct V_9 , V_25 ) ;
V_22 -> V_26 = V_7 ;
V_22 -> V_27 = V_7 ;
V_22 -> V_28 = V_29 ;
V_22 -> V_30 = 0 ;
V_22 -> V_31 = V_23 -> V_31 & V_32 ;
V_22 -> V_33 = F_17 ( V_10 -> V_34 ) ;
if ( F_18 ( V_23 -> V_31 & V_35 ) )
V_22 -> V_36 = V_37 ;
else {
V_22 -> V_36 = F_8 ( V_3 , V_10 , V_11 ) ;
if ( V_22 -> V_36 < 0 )
V_24 = V_22 -> V_36 ;
}
return V_24 ;
}
static struct V_38 * F_19 ( struct V_2 * V_3 ,
T_2 V_36 )
{
struct V_38 * V_39 , * V_40 = NULL ;
F_20 ( & V_3 -> V_17 . V_41 ) ;
F_21 (re, &group->fanotify_data.access_list, list) {
if ( V_39 -> V_36 != V_36 )
continue;
F_22 ( & V_39 -> V_42 ) ;
V_40 = V_39 ;
break;
}
F_23 ( & V_3 -> V_17 . V_41 ) ;
F_4 ( L_4 , V_6 , V_40 ) ;
return V_40 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_38 * V_39 ;
T_2 V_36 = V_44 -> V_36 ;
T_3 V_45 = V_44 -> V_45 ;
F_4 ( L_5 , V_6 , V_3 ,
V_36 , V_45 ) ;
switch ( V_45 ) {
case V_46 :
case V_47 :
break;
default:
return - V_8 ;
}
if ( V_36 < 0 )
return - V_8 ;
V_39 = F_19 ( V_3 , V_36 ) ;
if ( ! V_39 )
return - V_48 ;
V_39 -> V_10 -> V_45 = V_45 ;
F_25 ( & V_3 -> V_17 . V_49 ) ;
F_26 ( V_50 , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_10 ,
T_2 V_36 )
{
struct V_38 * V_39 ;
if ( ! ( V_10 -> V_31 & V_51 ) )
return 0 ;
V_39 = F_28 ( V_50 , V_52 ) ;
if ( ! V_39 )
return - V_53 ;
V_39 -> V_10 = F_29 ( V_10 ) ;
V_39 -> V_36 = V_36 ;
F_20 ( & V_3 -> V_17 . V_41 ) ;
if ( F_30 ( & V_3 -> V_17 . V_54 ) ) {
F_23 ( & V_3 -> V_17 . V_41 ) ;
F_26 ( V_50 , V_39 ) ;
F_29 ( V_10 ) -> V_45 = V_46 ;
return 0 ;
}
F_31 ( & V_39 -> V_42 , & V_3 -> V_17 . V_55 ) ;
F_23 ( & V_3 -> V_17 . V_41 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_10 ,
T_2 V_36 )
{
return 0 ;
}
static T_4 F_32 ( struct V_2 * V_3 ,
struct V_1 * V_10 ,
char T_5 * V_56 )
{
struct V_21 V_21 ;
struct V_11 * V_57 ;
int V_36 , V_24 ;
F_4 ( L_2 , V_6 , V_3 , V_10 ) ;
V_24 = F_15 ( V_3 , & V_21 , V_10 , & V_57 ) ;
if ( V_24 < 0 )
goto V_58;
V_36 = V_21 . V_36 ;
V_24 = - V_59 ;
if ( F_33 ( V_56 , & V_21 ,
V_21 . V_26 ) )
goto V_60;
V_24 = F_27 ( V_3 , V_10 , V_36 ) ;
if ( V_24 )
goto V_60;
if ( V_36 != V_37 )
F_34 ( V_36 , V_57 ) ;
return V_21 . V_26 ;
V_60:
if ( V_36 != V_37 ) {
F_13 ( V_36 ) ;
F_35 ( V_57 ) ;
}
V_58:
#ifdef F_36
if ( V_10 -> V_31 & V_51 ) {
F_29 ( V_10 ) -> V_45 = V_47 ;
F_25 ( & V_3 -> V_17 . V_49 ) ;
}
#endif
return V_24 ;
}
static unsigned int F_37 ( struct V_11 * V_11 , T_6 * V_61 )
{
struct V_2 * V_3 = V_11 -> V_62 ;
int V_24 = 0 ;
F_38 ( V_11 , & V_3 -> V_63 , V_61 ) ;
F_20 ( & V_3 -> V_5 ) ;
if ( ! F_5 ( V_3 ) )
V_24 = V_64 | V_65 ;
F_23 ( & V_3 -> V_5 ) ;
return V_24 ;
}
static T_4 F_39 ( struct V_11 * V_11 , char T_5 * V_56 ,
T_1 V_4 , T_7 * V_66 )
{
struct V_2 * V_3 ;
struct V_1 * V_67 ;
char T_5 * V_68 ;
int V_24 ;
F_40 ( V_61 ) ;
V_68 = V_56 ;
V_3 = V_11 -> V_62 ;
F_4 ( L_6 , V_6 , V_3 ) ;
while ( 1 ) {
F_41 ( & V_3 -> V_63 , & V_61 , V_69 ) ;
F_20 ( & V_3 -> V_5 ) ;
V_67 = F_1 ( V_3 , V_4 ) ;
F_23 ( & V_3 -> V_5 ) ;
if ( V_67 ) {
V_24 = F_14 ( V_67 ) ;
if ( F_12 ( V_67 ) )
break;
V_24 = F_32 ( V_3 , V_67 , V_56 ) ;
if ( ! ( V_67 -> V_31 & V_51 ) )
F_42 ( V_3 , V_67 ) ;
if ( V_24 < 0 )
break;
V_56 += V_24 ;
V_4 -= V_24 ;
continue;
}
V_24 = - V_70 ;
if ( V_11 -> V_18 & V_71 )
break;
V_24 = - V_72 ;
if ( F_43 ( V_73 ) )
break;
if ( V_68 != V_56 )
break;
F_44 () ;
}
F_45 ( & V_3 -> V_63 , & V_61 ) ;
if ( V_68 != V_56 && V_24 != - V_59 )
V_24 = V_56 - V_68 ;
return V_24 ;
}
static T_4 F_46 ( struct V_11 * V_11 , const char T_5 * V_56 , T_1 V_4 , T_7 * V_66 )
{
#ifdef F_36
struct V_43 V_45 = { . V_36 = - 1 , . V_45 = - 1 } ;
struct V_2 * V_3 ;
int V_24 ;
V_3 = V_11 -> V_62 ;
if ( V_4 > sizeof( V_45 ) )
V_4 = sizeof( V_45 ) ;
F_4 ( L_7 , V_6 , V_3 , V_4 ) ;
if ( F_47 ( & V_45 , V_56 , V_4 ) )
return - V_59 ;
V_24 = F_24 ( V_3 , & V_45 ) ;
if ( V_24 < 0 )
V_4 = V_24 ;
return V_4 ;
#else
return - V_8 ;
#endif
}
static int F_48 ( struct V_74 * V_75 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_62 ;
#ifdef F_36
struct V_38 * V_39 , * V_76 ;
F_20 ( & V_3 -> V_17 . V_41 ) ;
F_49 ( & V_3 -> V_17 . V_54 ) ;
F_50 (re, lre, &group->fanotify_data.access_list, list) {
F_4 ( L_8 , V_6 , V_3 ,
V_39 , V_39 -> V_10 ) ;
F_22 ( & V_39 -> V_42 ) ;
V_39 -> V_10 -> V_45 = V_46 ;
F_26 ( V_50 , V_39 ) ;
}
F_23 ( & V_3 -> V_17 . V_41 ) ;
F_25 ( & V_3 -> V_17 . V_49 ) ;
#endif
F_51 ( V_3 ) ;
return 0 ;
}
static long F_52 ( struct V_11 * V_11 , unsigned int V_77 , unsigned long V_78 )
{
struct V_2 * V_3 ;
struct V_1 * V_23 ;
void T_5 * V_79 ;
int V_24 = - V_80 ;
T_1 V_81 = 0 ;
V_3 = V_11 -> V_62 ;
V_79 = ( void T_5 * ) V_78 ;
switch ( V_77 ) {
case V_82 :
F_20 ( & V_3 -> V_5 ) ;
F_21 (fsn_event, &group->notification_list, list)
V_81 += V_7 ;
F_23 ( & V_3 -> V_5 ) ;
V_24 = F_53 ( V_81 , ( int T_5 * ) V_79 ) ;
break;
}
return V_24 ;
}
static void F_54 ( struct V_83 * V_84 )
{
F_26 ( V_85 , V_84 ) ;
}
static int F_55 ( int V_86 , const char T_5 * V_87 ,
struct V_14 * V_14 , unsigned int V_88 )
{
int V_24 ;
F_4 ( L_9 , V_6 ,
V_86 , V_87 , V_88 ) ;
if ( V_87 == NULL ) {
struct V_36 V_57 = F_56 ( V_86 ) ;
V_24 = - V_89 ;
if ( ! V_57 . V_11 )
goto V_58;
V_24 = - V_90 ;
if ( ( V_88 & V_91 ) &&
! ( F_57 ( F_58 ( V_57 . V_11 ) -> V_92 ) ) ) {
F_59 ( V_57 ) ;
goto V_58;
}
* V_14 = V_57 . V_11 -> V_93 ;
F_60 ( V_14 ) ;
F_59 ( V_57 ) ;
} else {
unsigned int V_94 = 0 ;
if ( ! ( V_88 & V_95 ) )
V_94 |= V_96 ;
if ( V_88 & V_91 )
V_94 |= V_97 ;
V_24 = F_61 ( V_86 , V_87 , V_94 , V_14 ) ;
if ( V_24 )
goto V_58;
}
V_24 = F_62 ( V_14 -> V_15 -> V_98 , V_99 ) ;
if ( V_24 )
F_63 ( V_14 ) ;
V_58:
return V_24 ;
}
static T_3 F_64 ( struct V_83 * V_84 ,
T_3 V_31 ,
unsigned int V_88 ,
int * V_100 )
{
T_3 V_101 ;
F_65 ( & V_84 -> V_102 ) ;
if ( ! ( V_88 & V_103 ) ) {
V_101 = V_84 -> V_31 ;
F_66 ( V_84 , ( V_101 & ~ V_31 ) ) ;
} else {
V_101 = V_84 -> V_104 ;
F_67 ( V_84 , ( V_101 & ~ V_31 ) ) ;
}
F_68 ( & V_84 -> V_102 ) ;
* V_100 = ! ( V_101 & ~ V_31 ) ;
return V_31 & V_101 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_105 * V_16 , T_3 V_31 ,
unsigned int V_88 )
{
struct V_83 * V_84 = NULL ;
T_3 V_106 ;
int V_107 ;
F_20 ( & V_3 -> V_108 ) ;
V_84 = F_70 ( V_3 , V_16 ) ;
if ( ! V_84 ) {
F_23 ( & V_3 -> V_108 ) ;
return - V_48 ;
}
V_106 = F_64 ( V_84 , V_31 , V_88 ,
& V_107 ) ;
if ( V_107 )
F_71 ( V_84 , V_3 ) ;
F_23 ( & V_3 -> V_108 ) ;
F_72 ( V_84 ) ;
if ( V_106 & F_73 ( V_16 ) -> V_109 )
F_74 ( V_16 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_74 * V_74 , T_3 V_31 ,
unsigned int V_88 )
{
struct V_83 * V_84 = NULL ;
T_3 V_106 ;
int V_107 ;
F_20 ( & V_3 -> V_108 ) ;
V_84 = F_76 ( V_3 , V_74 ) ;
if ( ! V_84 ) {
F_23 ( & V_3 -> V_108 ) ;
return - V_48 ;
}
V_106 = F_64 ( V_84 , V_31 , V_88 ,
& V_107 ) ;
if ( V_107 )
F_71 ( V_84 , V_3 ) ;
F_23 ( & V_3 -> V_108 ) ;
F_72 ( V_84 ) ;
if ( V_106 & V_74 -> V_110 )
F_77 ( V_74 ) ;
return 0 ;
}
static T_3 F_78 ( struct V_83 * V_84 ,
T_3 V_31 ,
unsigned int V_88 )
{
T_3 V_101 = - 1 ;
F_65 ( & V_84 -> V_102 ) ;
if ( ! ( V_88 & V_103 ) ) {
V_101 = V_84 -> V_31 ;
F_66 ( V_84 , ( V_101 | V_31 ) ) ;
} else {
T_3 V_111 = V_84 -> V_104 | V_31 ;
F_67 ( V_84 , V_111 ) ;
if ( V_88 & V_112 )
V_84 -> V_88 |= V_113 ;
}
if ( ! ( V_88 & V_114 ) ) {
T_3 V_111 = V_84 -> V_104 | V_115 ;
F_67 ( V_84 , V_111 ) ;
}
F_68 ( & V_84 -> V_102 ) ;
return V_31 & ~ V_101 ;
}
static struct V_83 * F_79 ( struct V_2 * V_3 ,
struct V_74 * V_74 ,
struct V_105 * V_16 )
{
struct V_83 * V_116 ;
int V_24 ;
if ( F_30 ( & V_3 -> V_117 ) > V_3 -> V_17 . V_118 )
return F_6 ( - V_119 ) ;
V_116 = F_28 ( V_85 , V_52 ) ;
if ( ! V_116 )
return F_6 ( - V_53 ) ;
F_80 ( V_116 , F_54 ) ;
V_24 = F_81 ( V_116 , V_3 , V_74 , V_16 , 0 ) ;
if ( V_24 ) {
F_72 ( V_116 ) ;
return F_6 ( V_24 ) ;
}
return V_116 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_105 * V_16 , T_3 V_31 ,
unsigned int V_88 )
{
struct V_83 * V_84 ;
T_3 V_120 ;
F_20 ( & V_3 -> V_108 ) ;
V_84 = F_70 ( V_3 , V_16 ) ;
if ( ! V_84 ) {
V_84 = F_79 ( V_3 , NULL , V_16 ) ;
if ( F_12 ( V_84 ) ) {
F_23 ( & V_3 -> V_108 ) ;
return F_14 ( V_84 ) ;
}
}
V_120 = F_78 ( V_84 , V_31 , V_88 ) ;
F_23 ( & V_3 -> V_108 ) ;
if ( V_120 & ~ F_73 ( V_16 ) -> V_109 )
F_74 ( V_16 ) ;
F_72 ( V_84 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_74 * V_74 , T_3 V_31 ,
unsigned int V_88 )
{
struct V_83 * V_84 ;
T_3 V_120 ;
F_4 ( L_10 , V_6 , V_3 , V_74 ) ;
if ( ( V_88 & V_103 ) &&
! ( V_88 & V_112 ) &&
( F_30 ( & V_74 -> V_121 ) > 0 ) )
return 0 ;
F_20 ( & V_3 -> V_108 ) ;
V_84 = F_76 ( V_3 , V_74 ) ;
if ( ! V_84 ) {
V_84 = F_79 ( V_3 , V_74 , NULL ) ;
if ( F_12 ( V_84 ) ) {
F_23 ( & V_3 -> V_108 ) ;
return F_14 ( V_84 ) ;
}
}
V_120 = F_78 ( V_84 , V_31 , V_88 ) ;
F_23 ( & V_3 -> V_108 ) ;
if ( V_120 & ~ V_74 -> V_110 )
F_77 ( V_74 ) ;
F_72 ( V_84 ) ;
return 0 ;
}
static int T_8 F_84 ( void )
{
V_85 = F_85 ( V_83 , V_122 ) ;
V_50 = F_85 ( V_38 ,
V_122 ) ;
V_123 = F_85 ( V_9 , V_122 ) ;
return 0 ;
}
