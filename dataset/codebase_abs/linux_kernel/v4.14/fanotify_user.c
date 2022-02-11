static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
F_2 ( & V_3 -> V_5 ) ;
F_3 ( L_1 , V_6 , V_3 , V_4 ) ;
if ( F_4 ( V_3 ) )
return NULL ;
if ( V_7 > V_4 )
return F_5 ( - V_8 ) ;
return F_6 ( V_3 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_11 * * V_11 )
{
int V_12 ;
struct V_11 * V_13 ;
F_3 ( L_2 , V_6 , V_3 , V_10 ) ;
V_12 = F_8 ( V_3 -> V_14 . V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 -> V_16 . V_17 && V_10 -> V_16 . V_18 )
V_13 = F_9 ( & V_10 -> V_16 ,
V_3 -> V_14 . V_15 | V_19 ,
F_10 () ) ;
else
V_13 = F_5 ( - V_20 ) ;
if ( F_11 ( V_13 ) ) {
F_12 ( V_12 ) ;
V_12 = F_13 ( V_13 ) ;
} else {
* V_11 = V_13 ;
}
return V_12 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_1 * V_23 ,
struct V_11 * * V_11 )
{
int V_24 = 0 ;
struct V_9 * V_10 ;
F_3 ( L_3 , V_6 ,
V_3 , V_22 , V_23 ) ;
* V_11 = NULL ;
V_10 = F_15 ( V_23 , struct V_9 , V_25 ) ;
V_22 -> V_26 = V_7 ;
V_22 -> V_27 = V_7 ;
V_22 -> V_28 = V_29 ;
V_22 -> V_30 = 0 ;
V_22 -> V_31 = V_23 -> V_31 & V_32 ;
V_22 -> V_33 = F_16 ( V_10 -> V_34 ) ;
if ( F_17 ( V_23 -> V_31 & V_35 ) )
V_22 -> V_36 = V_37 ;
else {
V_22 -> V_36 = F_7 ( V_3 , V_10 , V_11 ) ;
if ( V_22 -> V_36 < 0 )
V_24 = V_22 -> V_36 ;
}
return V_24 ;
}
static struct V_38 * F_18 (
struct V_2 * V_3 , int V_36 )
{
struct V_38 * V_10 , * V_39 = NULL ;
F_19 ( & V_3 -> V_5 ) ;
F_20 (event, &group->fanotify_data.access_list,
fae.fse.list) {
if ( V_10 -> V_36 != V_36 )
continue;
F_21 ( & V_10 -> V_40 . V_25 . V_41 ) ;
V_39 = V_10 ;
break;
}
F_22 ( & V_3 -> V_5 ) ;
F_3 ( L_4 , V_6 , V_39 ) ;
return V_39 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_38 * V_10 ;
int V_36 = V_43 -> V_36 ;
int V_44 = V_43 -> V_44 ;
F_3 ( L_5 , V_6 , V_3 ,
V_36 , V_44 ) ;
switch ( V_44 ) {
case V_45 :
case V_46 :
break;
default:
return - V_8 ;
}
if ( V_36 < 0 )
return - V_8 ;
V_10 = F_18 ( V_3 , V_36 ) ;
if ( ! V_10 )
return - V_47 ;
V_10 -> V_44 = V_44 ;
F_24 ( & V_3 -> V_14 . V_48 ) ;
return 0 ;
}
static T_2 F_25 ( struct V_2 * V_3 ,
struct V_1 * V_10 ,
char T_3 * V_49 )
{
struct V_21 V_21 ;
struct V_11 * V_50 ;
int V_36 , V_24 ;
F_3 ( L_2 , V_6 , V_3 , V_10 ) ;
V_24 = F_14 ( V_3 , & V_21 , V_10 , & V_50 ) ;
if ( V_24 < 0 )
return V_24 ;
V_36 = V_21 . V_36 ;
V_24 = - V_51 ;
if ( F_26 ( V_49 , & V_21 ,
V_21 . V_26 ) )
goto V_52;
#ifdef F_27
if ( V_10 -> V_31 & V_53 )
F_28 ( V_10 ) -> V_36 = V_36 ;
#endif
if ( V_36 != V_37 )
F_29 ( V_36 , V_50 ) ;
return V_21 . V_26 ;
V_52:
if ( V_36 != V_37 ) {
F_12 ( V_36 ) ;
F_30 ( V_50 ) ;
}
return V_24 ;
}
static unsigned int F_31 ( struct V_11 * V_11 , T_4 * V_54 )
{
struct V_2 * V_3 = V_11 -> V_55 ;
int V_24 = 0 ;
F_32 ( V_11 , & V_3 -> V_56 , V_54 ) ;
F_19 ( & V_3 -> V_5 ) ;
if ( ! F_4 ( V_3 ) )
V_24 = V_57 | V_58 ;
F_22 ( & V_3 -> V_5 ) ;
return V_24 ;
}
static T_2 F_33 ( struct V_11 * V_11 , char T_3 * V_49 ,
T_1 V_4 , T_5 * V_59 )
{
struct V_2 * V_3 ;
struct V_1 * V_60 ;
char T_3 * V_61 ;
int V_24 ;
F_34 ( V_54 , V_62 ) ;
V_61 = V_49 ;
V_3 = V_11 -> V_55 ;
F_3 ( L_6 , V_6 , V_3 ) ;
F_35 ( & V_3 -> V_56 , & V_54 ) ;
while ( 1 ) {
F_19 ( & V_3 -> V_5 ) ;
V_60 = F_1 ( V_3 , V_4 ) ;
F_22 ( & V_3 -> V_5 ) ;
if ( F_11 ( V_60 ) ) {
V_24 = F_13 ( V_60 ) ;
break;
}
if ( ! V_60 ) {
V_24 = - V_63 ;
if ( V_11 -> V_15 & V_64 )
break;
V_24 = - V_65 ;
if ( F_36 ( V_66 ) )
break;
if ( V_61 != V_49 )
break;
F_37 ( & V_54 , V_67 , V_68 ) ;
continue;
}
V_24 = F_25 ( V_3 , V_60 , V_49 ) ;
if ( F_17 ( V_24 == - V_69 ) ) {
V_24 = 0 ;
}
if ( ! ( V_60 -> V_31 & V_53 ) ) {
F_38 ( V_3 , V_60 ) ;
} else {
#ifdef F_27
if ( V_24 <= 0 ) {
F_28 ( V_60 ) -> V_44 = V_46 ;
F_24 ( & V_3 -> V_14 . V_48 ) ;
} else {
F_19 ( & V_3 -> V_5 ) ;
F_39 ( & V_60 -> V_41 ,
& V_3 -> V_14 . V_70 ) ;
F_22 ( & V_3 -> V_5 ) ;
}
#endif
}
if ( V_24 < 0 )
break;
V_49 += V_24 ;
V_4 -= V_24 ;
}
F_40 ( & V_3 -> V_56 , & V_54 ) ;
if ( V_61 != V_49 && V_24 != - V_51 )
V_24 = V_49 - V_61 ;
return V_24 ;
}
static T_2 F_41 ( struct V_11 * V_11 , const char T_3 * V_49 , T_1 V_4 , T_5 * V_59 )
{
#ifdef F_27
struct V_42 V_44 = { . V_36 = - 1 , . V_44 = - 1 } ;
struct V_2 * V_3 ;
int V_24 ;
V_3 = V_11 -> V_55 ;
if ( V_4 > sizeof( V_44 ) )
V_4 = sizeof( V_44 ) ;
F_3 ( L_7 , V_6 , V_3 , V_4 ) ;
if ( F_42 ( & V_44 , V_49 , V_4 ) )
return - V_51 ;
V_24 = F_23 ( V_3 , & V_44 ) ;
if ( V_24 < 0 )
V_4 = V_24 ;
return V_4 ;
#else
return - V_8 ;
#endif
}
static int F_43 ( struct V_71 * V_72 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_55 ;
#ifdef F_27
struct V_38 * V_10 , * V_73 ;
struct V_1 * V_23 ;
F_44 ( V_3 ) ;
F_19 ( & V_3 -> V_5 ) ;
F_45 (event, next, &group->fanotify_data.access_list,
fae.fse.list) {
F_3 ( L_8 , V_6 , V_3 ,
V_10 ) ;
F_21 ( & V_10 -> V_40 . V_25 . V_41 ) ;
V_10 -> V_44 = V_45 ;
}
while ( ! F_4 ( V_3 ) ) {
V_23 = F_6 ( V_3 ) ;
if ( ! ( V_23 -> V_31 & V_53 ) ) {
F_22 ( & V_3 -> V_5 ) ;
F_38 ( V_3 , V_23 ) ;
F_19 ( & V_3 -> V_5 ) ;
} else
F_28 ( V_23 ) -> V_44 = V_45 ;
}
F_22 ( & V_3 -> V_5 ) ;
F_24 ( & V_3 -> V_14 . V_48 ) ;
#endif
F_46 ( V_3 ) ;
return 0 ;
}
static long F_47 ( struct V_11 * V_11 , unsigned int V_74 , unsigned long V_75 )
{
struct V_2 * V_3 ;
struct V_1 * V_23 ;
void T_3 * V_76 ;
int V_24 = - V_77 ;
T_1 V_78 = 0 ;
V_3 = V_11 -> V_55 ;
V_76 = ( void T_3 * ) V_75 ;
switch ( V_74 ) {
case V_79 :
F_19 ( & V_3 -> V_5 ) ;
F_20 (fsn_event, &group->notification_list, list)
V_78 += V_7 ;
F_22 ( & V_3 -> V_5 ) ;
V_24 = F_48 ( V_78 , ( int T_3 * ) V_76 ) ;
break;
}
return V_24 ;
}
static int F_49 ( int V_80 , const char T_3 * V_81 ,
struct V_16 * V_16 , unsigned int V_82 )
{
int V_24 ;
F_3 ( L_9 , V_6 ,
V_80 , V_81 , V_82 ) ;
if ( V_81 == NULL ) {
struct V_36 V_50 = F_50 ( V_80 ) ;
V_24 = - V_83 ;
if ( ! V_50 . V_11 )
goto V_84;
V_24 = - V_85 ;
if ( ( V_82 & V_86 ) &&
! ( F_51 ( F_52 ( V_50 . V_11 ) -> V_87 ) ) ) {
F_53 ( V_50 ) ;
goto V_84;
}
* V_16 = V_50 . V_11 -> V_88 ;
F_54 ( V_16 ) ;
F_53 ( V_50 ) ;
} else {
unsigned int V_89 = 0 ;
if ( ! ( V_82 & V_90 ) )
V_89 |= V_91 ;
if ( V_82 & V_86 )
V_89 |= V_92 ;
V_24 = F_55 ( V_80 , V_81 , V_89 , V_16 ) ;
if ( V_24 )
goto V_84;
}
V_24 = F_56 ( V_16 -> V_17 -> V_93 , V_94 ) ;
if ( V_24 )
F_57 ( V_16 ) ;
V_84:
return V_24 ;
}
static T_6 F_58 ( struct V_95 * V_96 ,
T_6 V_31 ,
unsigned int V_82 ,
int * V_97 )
{
T_6 V_98 = 0 ;
F_19 ( & V_96 -> V_99 ) ;
if ( ! ( V_82 & V_100 ) ) {
T_6 V_101 = V_96 -> V_31 & ~ V_31 ;
if ( V_82 & V_102 )
V_101 &= ~ V_103 ;
V_98 = V_96 -> V_31 ;
V_96 -> V_31 = V_101 ;
} else {
T_6 V_101 = V_96 -> V_104 & ~ V_31 ;
if ( V_82 & V_102 )
V_101 &= ~ V_103 ;
V_96 -> V_104 = V_101 ;
}
* V_97 = ! ( V_96 -> V_31 | V_96 -> V_104 ) ;
F_22 ( & V_96 -> V_99 ) ;
return V_31 & V_98 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_105 * V_18 , T_6 V_31 ,
unsigned int V_82 )
{
struct V_95 * V_96 = NULL ;
T_6 V_106 ;
int V_107 ;
F_60 ( & V_3 -> V_108 ) ;
V_96 = F_61 ( & F_62 ( V_18 ) -> V_109 ,
V_3 ) ;
if ( ! V_96 ) {
F_63 ( & V_3 -> V_108 ) ;
return - V_47 ;
}
V_106 = F_58 ( V_96 , V_31 , V_82 ,
& V_107 ) ;
if ( V_106 & F_62 ( V_18 ) -> V_110 )
F_64 ( F_62 ( V_18 ) -> V_109 ) ;
if ( V_107 )
F_65 ( V_96 ) ;
F_63 ( & V_3 -> V_108 ) ;
if ( V_107 )
F_66 ( V_96 ) ;
F_67 ( V_96 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_71 * V_71 , T_6 V_31 ,
unsigned int V_82 )
{
struct V_95 * V_96 = NULL ;
T_6 V_106 ;
int V_107 ;
F_60 ( & V_3 -> V_108 ) ;
V_96 = F_61 ( & V_71 -> V_111 , V_3 ) ;
if ( ! V_96 ) {
F_63 ( & V_3 -> V_108 ) ;
return - V_47 ;
}
V_106 = F_58 ( V_96 , V_31 , V_82 ,
& V_107 ) ;
if ( V_106 & V_71 -> V_112 )
F_64 ( V_71 -> V_111 ) ;
if ( V_107 )
F_65 ( V_96 ) ;
F_63 ( & V_3 -> V_108 ) ;
if ( V_107 )
F_66 ( V_96 ) ;
F_67 ( V_96 ) ;
return 0 ;
}
static T_6 F_69 ( struct V_95 * V_96 ,
T_6 V_31 ,
unsigned int V_82 )
{
T_6 V_98 = - 1 ;
F_19 ( & V_96 -> V_99 ) ;
if ( ! ( V_82 & V_100 ) ) {
T_6 V_101 = V_96 -> V_31 | V_31 ;
if ( V_82 & V_102 )
V_101 |= V_103 ;
V_98 = V_96 -> V_31 ;
V_96 -> V_31 = V_101 ;
} else {
T_6 V_101 = V_96 -> V_104 | V_31 ;
if ( V_82 & V_102 )
V_101 |= V_103 ;
V_96 -> V_104 = V_101 ;
if ( V_82 & V_113 )
V_96 -> V_82 |= V_114 ;
}
F_22 ( & V_96 -> V_99 ) ;
return V_31 & ~ V_98 ;
}
static struct V_95 * F_70 ( struct V_2 * V_3 ,
struct V_71 * V_71 ,
struct V_105 * V_18 )
{
struct V_95 * V_115 ;
int V_24 ;
if ( F_71 ( & V_3 -> V_116 ) > V_3 -> V_14 . V_117 )
return F_5 ( - V_118 ) ;
V_115 = F_72 ( V_119 , V_120 ) ;
if ( ! V_115 )
return F_5 ( - V_121 ) ;
F_73 ( V_115 , V_3 ) ;
V_24 = F_74 ( V_115 , V_71 , V_18 , 0 ) ;
if ( V_24 ) {
F_67 ( V_115 ) ;
return F_5 ( V_24 ) ;
}
return V_115 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_105 * V_18 , T_6 V_31 ,
unsigned int V_82 )
{
struct V_95 * V_96 ;
T_6 V_122 ;
F_60 ( & V_3 -> V_108 ) ;
V_96 = F_61 ( & F_62 ( V_18 ) -> V_109 ,
V_3 ) ;
if ( ! V_96 ) {
V_96 = F_70 ( V_3 , NULL , V_18 ) ;
if ( F_11 ( V_96 ) ) {
F_63 ( & V_3 -> V_108 ) ;
return F_13 ( V_96 ) ;
}
}
V_122 = F_69 ( V_96 , V_31 , V_82 ) ;
if ( V_122 & ~ F_62 ( V_18 ) -> V_110 )
F_64 ( F_62 ( V_18 ) -> V_109 ) ;
F_63 ( & V_3 -> V_108 ) ;
F_67 ( V_96 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 ,
struct V_71 * V_71 , T_6 V_31 ,
unsigned int V_82 )
{
struct V_95 * V_96 ;
T_6 V_122 ;
F_3 ( L_10 , V_6 , V_3 , V_71 ) ;
if ( ( V_82 & V_100 ) &&
! ( V_82 & V_113 ) &&
( F_71 ( & V_71 -> V_123 ) > 0 ) )
return 0 ;
F_60 ( & V_3 -> V_108 ) ;
V_96 = F_61 ( & V_71 -> V_111 , V_3 ) ;
if ( ! V_96 ) {
V_96 = F_70 ( V_3 , V_71 , NULL ) ;
if ( F_11 ( V_96 ) ) {
F_63 ( & V_3 -> V_108 ) ;
return F_13 ( V_96 ) ;
}
}
V_122 = F_69 ( V_96 , V_31 , V_82 ) ;
if ( V_122 & ~ V_71 -> V_112 )
F_64 ( V_71 -> V_111 ) ;
F_63 ( & V_3 -> V_108 ) ;
F_67 ( V_96 ) ;
return 0 ;
}
static int T_7 F_77 ( void )
{
V_119 = F_78 ( V_95 , V_124 ) ;
V_125 = F_78 ( V_9 , V_124 ) ;
#ifdef F_27
V_126 = F_78 ( V_38 ,
V_124 ) ;
#endif
return 0 ;
}
