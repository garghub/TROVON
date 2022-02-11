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
static struct V_38 * F_19 (
struct V_2 * V_3 , int V_36 )
{
struct V_38 * V_10 , * V_39 = NULL ;
F_20 ( & V_3 -> V_17 . V_40 ) ;
F_21 (event, &group->fanotify_data.access_list,
fae.fse.list) {
if ( V_10 -> V_36 != V_36 )
continue;
F_22 ( & V_10 -> V_41 . V_25 . V_42 ) ;
V_39 = V_10 ;
break;
}
F_23 ( & V_3 -> V_17 . V_40 ) ;
F_4 ( L_4 , V_6 , V_39 ) ;
return V_39 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_38 * V_10 ;
int V_36 = V_44 -> V_36 ;
int V_45 = V_44 -> V_45 ;
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
V_10 = F_19 ( V_3 , V_36 ) ;
if ( ! V_10 )
return - V_48 ;
V_10 -> V_45 = V_45 ;
F_25 ( & V_3 -> V_17 . V_49 ) ;
return 0 ;
}
static T_2 F_26 ( struct V_2 * V_3 ,
struct V_1 * V_10 ,
char T_3 * V_50 )
{
struct V_21 V_21 ;
struct V_11 * V_51 ;
int V_36 , V_24 ;
F_4 ( L_2 , V_6 , V_3 , V_10 ) ;
V_24 = F_15 ( V_3 , & V_21 , V_10 , & V_51 ) ;
if ( V_24 < 0 )
return V_24 ;
V_36 = V_21 . V_36 ;
V_24 = - V_52 ;
if ( F_27 ( V_50 , & V_21 ,
V_21 . V_26 ) )
goto V_53;
#ifdef F_28
if ( V_10 -> V_31 & V_54 )
F_29 ( V_10 ) -> V_36 = V_36 ;
#endif
if ( V_36 != V_37 )
F_30 ( V_36 , V_51 ) ;
return V_21 . V_26 ;
V_53:
if ( V_36 != V_37 ) {
F_13 ( V_36 ) ;
F_31 ( V_51 ) ;
}
return V_24 ;
}
static unsigned int F_32 ( struct V_11 * V_11 , T_4 * V_55 )
{
struct V_2 * V_3 = V_11 -> V_56 ;
int V_24 = 0 ;
F_33 ( V_11 , & V_3 -> V_57 , V_55 ) ;
F_34 ( & V_3 -> V_5 ) ;
if ( ! F_5 ( V_3 ) )
V_24 = V_58 | V_59 ;
F_35 ( & V_3 -> V_5 ) ;
return V_24 ;
}
static T_2 F_36 ( struct V_11 * V_11 , char T_3 * V_50 ,
T_1 V_4 , T_5 * V_60 )
{
struct V_2 * V_3 ;
struct V_1 * V_61 ;
char T_3 * V_62 ;
int V_24 ;
F_37 ( V_55 ) ;
V_62 = V_50 ;
V_3 = V_11 -> V_56 ;
F_4 ( L_6 , V_6 , V_3 ) ;
while ( 1 ) {
F_38 ( & V_3 -> V_57 , & V_55 , V_63 ) ;
F_34 ( & V_3 -> V_5 ) ;
V_61 = F_1 ( V_3 , V_4 ) ;
F_35 ( & V_3 -> V_5 ) ;
if ( F_12 ( V_61 ) ) {
V_24 = F_14 ( V_61 ) ;
break;
}
if ( ! V_61 ) {
V_24 = - V_64 ;
if ( V_11 -> V_18 & V_65 )
break;
V_24 = - V_66 ;
if ( F_39 ( V_67 ) )
break;
if ( V_62 != V_50 )
break;
F_40 () ;
continue;
}
V_24 = F_26 ( V_3 , V_61 , V_50 ) ;
if ( ! ( V_61 -> V_31 & V_54 ) ) {
F_41 ( V_3 , V_61 ) ;
if ( V_24 < 0 )
break;
} else {
#ifdef F_28
if ( V_24 < 0 ) {
F_29 ( V_61 ) -> V_45 = V_47 ;
F_25 ( & V_3 -> V_17 . V_49 ) ;
break;
}
F_20 ( & V_3 -> V_17 . V_40 ) ;
F_42 ( & V_61 -> V_42 ,
& V_3 -> V_17 . V_68 ) ;
F_23 ( & V_3 -> V_17 . V_40 ) ;
#endif
}
V_50 += V_24 ;
V_4 -= V_24 ;
}
F_43 ( & V_3 -> V_57 , & V_55 ) ;
if ( V_62 != V_50 && V_24 != - V_52 )
V_24 = V_50 - V_62 ;
return V_24 ;
}
static T_2 F_44 ( struct V_11 * V_11 , const char T_3 * V_50 , T_1 V_4 , T_5 * V_60 )
{
#ifdef F_28
struct V_43 V_45 = { . V_36 = - 1 , . V_45 = - 1 } ;
struct V_2 * V_3 ;
int V_24 ;
V_3 = V_11 -> V_56 ;
if ( V_4 > sizeof( V_45 ) )
V_4 = sizeof( V_45 ) ;
F_4 ( L_7 , V_6 , V_3 , V_4 ) ;
if ( F_45 ( & V_45 , V_50 , V_4 ) )
return - V_52 ;
V_24 = F_24 ( V_3 , & V_45 ) ;
if ( V_24 < 0 )
V_4 = V_24 ;
return V_4 ;
#else
return - V_8 ;
#endif
}
static int F_46 ( struct V_69 * V_70 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_56 ;
#ifdef F_28
struct V_38 * V_10 , * V_71 ;
F_20 ( & V_3 -> V_17 . V_40 ) ;
F_47 ( & V_3 -> V_17 . V_72 ) ;
F_48 (event, next, &group->fanotify_data.access_list,
fae.fse.list) {
F_4 ( L_8 , V_6 , V_3 ,
V_10 ) ;
F_22 ( & V_10 -> V_41 . V_25 . V_42 ) ;
V_10 -> V_45 = V_46 ;
}
F_23 ( & V_3 -> V_17 . V_40 ) ;
F_25 ( & V_3 -> V_17 . V_49 ) ;
#endif
F_49 ( V_3 ) ;
return 0 ;
}
static long F_50 ( struct V_11 * V_11 , unsigned int V_73 , unsigned long V_74 )
{
struct V_2 * V_3 ;
struct V_1 * V_23 ;
void T_3 * V_75 ;
int V_24 = - V_76 ;
T_1 V_77 = 0 ;
V_3 = V_11 -> V_56 ;
V_75 = ( void T_3 * ) V_74 ;
switch ( V_73 ) {
case V_78 :
F_34 ( & V_3 -> V_5 ) ;
F_21 (fsn_event, &group->notification_list, list)
V_77 += V_7 ;
F_35 ( & V_3 -> V_5 ) ;
V_24 = F_51 ( V_77 , ( int T_3 * ) V_75 ) ;
break;
}
return V_24 ;
}
static void F_52 ( struct V_79 * V_80 )
{
F_53 ( V_81 , V_80 ) ;
}
static int F_54 ( int V_82 , const char T_3 * V_83 ,
struct V_14 * V_14 , unsigned int V_84 )
{
int V_24 ;
F_4 ( L_9 , V_6 ,
V_82 , V_83 , V_84 ) ;
if ( V_83 == NULL ) {
struct V_36 V_51 = F_55 ( V_82 ) ;
V_24 = - V_85 ;
if ( ! V_51 . V_11 )
goto V_86;
V_24 = - V_87 ;
if ( ( V_84 & V_88 ) &&
! ( F_56 ( F_57 ( V_51 . V_11 ) -> V_89 ) ) ) {
F_58 ( V_51 ) ;
goto V_86;
}
* V_14 = V_51 . V_11 -> V_90 ;
F_59 ( V_14 ) ;
F_58 ( V_51 ) ;
} else {
unsigned int V_91 = 0 ;
if ( ! ( V_84 & V_92 ) )
V_91 |= V_93 ;
if ( V_84 & V_88 )
V_91 |= V_94 ;
V_24 = F_60 ( V_82 , V_83 , V_91 , V_14 ) ;
if ( V_24 )
goto V_86;
}
V_24 = F_61 ( V_14 -> V_15 -> V_95 , V_96 ) ;
if ( V_24 )
F_62 ( V_14 ) ;
V_86:
return V_24 ;
}
static T_6 F_63 ( struct V_79 * V_80 ,
T_6 V_31 ,
unsigned int V_84 ,
int * V_97 )
{
T_6 V_98 ;
F_20 ( & V_80 -> V_99 ) ;
if ( ! ( V_84 & V_100 ) ) {
V_98 = V_80 -> V_31 ;
F_64 ( V_80 , ( V_98 & ~ V_31 ) ) ;
} else {
V_98 = V_80 -> V_101 ;
F_65 ( V_80 , ( V_98 & ~ V_31 ) ) ;
}
F_23 ( & V_80 -> V_99 ) ;
* V_97 = ! ( V_98 & ~ V_31 ) ;
return V_31 & V_98 ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_102 * V_16 , T_6 V_31 ,
unsigned int V_84 )
{
struct V_79 * V_80 = NULL ;
T_6 V_103 ;
int V_104 ;
F_34 ( & V_3 -> V_105 ) ;
V_80 = F_67 ( V_3 , V_16 ) ;
if ( ! V_80 ) {
F_35 ( & V_3 -> V_105 ) ;
return - V_48 ;
}
V_103 = F_63 ( V_80 , V_31 , V_84 ,
& V_104 ) ;
if ( V_104 )
F_68 ( V_80 , V_3 ) ;
F_35 ( & V_3 -> V_105 ) ;
F_69 ( V_80 ) ;
if ( V_103 & F_70 ( V_16 ) -> V_106 )
F_71 ( V_16 ) ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_69 * V_69 , T_6 V_31 ,
unsigned int V_84 )
{
struct V_79 * V_80 = NULL ;
T_6 V_103 ;
int V_104 ;
F_34 ( & V_3 -> V_105 ) ;
V_80 = F_73 ( V_3 , V_69 ) ;
if ( ! V_80 ) {
F_35 ( & V_3 -> V_105 ) ;
return - V_48 ;
}
V_103 = F_63 ( V_80 , V_31 , V_84 ,
& V_104 ) ;
if ( V_104 )
F_68 ( V_80 , V_3 ) ;
F_35 ( & V_3 -> V_105 ) ;
F_69 ( V_80 ) ;
if ( V_103 & V_69 -> V_107 )
F_74 ( V_69 ) ;
return 0 ;
}
static T_6 F_75 ( struct V_79 * V_80 ,
T_6 V_31 ,
unsigned int V_84 )
{
T_6 V_98 = - 1 ;
F_20 ( & V_80 -> V_99 ) ;
if ( ! ( V_84 & V_100 ) ) {
V_98 = V_80 -> V_31 ;
F_64 ( V_80 , ( V_98 | V_31 ) ) ;
} else {
T_6 V_108 = V_80 -> V_101 | V_31 ;
F_65 ( V_80 , V_108 ) ;
if ( V_84 & V_109 )
V_80 -> V_84 |= V_110 ;
}
if ( ! ( V_84 & V_111 ) ) {
T_6 V_108 = V_80 -> V_101 | V_112 ;
F_65 ( V_80 , V_108 ) ;
}
F_23 ( & V_80 -> V_99 ) ;
return V_31 & ~ V_98 ;
}
static struct V_79 * F_76 ( struct V_2 * V_3 ,
struct V_69 * V_69 ,
struct V_102 * V_16 )
{
struct V_79 * V_113 ;
int V_24 ;
if ( F_77 ( & V_3 -> V_114 ) > V_3 -> V_17 . V_115 )
return F_6 ( - V_116 ) ;
V_113 = F_78 ( V_81 , V_117 ) ;
if ( ! V_113 )
return F_6 ( - V_118 ) ;
F_79 ( V_113 , F_52 ) ;
V_24 = F_80 ( V_113 , V_3 , V_69 , V_16 , 0 ) ;
if ( V_24 ) {
F_69 ( V_113 ) ;
return F_6 ( V_24 ) ;
}
return V_113 ;
}
static int F_81 ( struct V_2 * V_3 ,
struct V_102 * V_16 , T_6 V_31 ,
unsigned int V_84 )
{
struct V_79 * V_80 ;
T_6 V_119 ;
F_34 ( & V_3 -> V_105 ) ;
V_80 = F_67 ( V_3 , V_16 ) ;
if ( ! V_80 ) {
V_80 = F_76 ( V_3 , NULL , V_16 ) ;
if ( F_12 ( V_80 ) ) {
F_35 ( & V_3 -> V_105 ) ;
return F_14 ( V_80 ) ;
}
}
V_119 = F_75 ( V_80 , V_31 , V_84 ) ;
F_35 ( & V_3 -> V_105 ) ;
if ( V_119 & ~ F_70 ( V_16 ) -> V_106 )
F_71 ( V_16 ) ;
F_69 ( V_80 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_69 * V_69 , T_6 V_31 ,
unsigned int V_84 )
{
struct V_79 * V_80 ;
T_6 V_119 ;
F_4 ( L_10 , V_6 , V_3 , V_69 ) ;
if ( ( V_84 & V_100 ) &&
! ( V_84 & V_109 ) &&
( F_77 ( & V_69 -> V_120 ) > 0 ) )
return 0 ;
F_34 ( & V_3 -> V_105 ) ;
V_80 = F_73 ( V_3 , V_69 ) ;
if ( ! V_80 ) {
V_80 = F_76 ( V_3 , V_69 , NULL ) ;
if ( F_12 ( V_80 ) ) {
F_35 ( & V_3 -> V_105 ) ;
return F_14 ( V_80 ) ;
}
}
V_119 = F_75 ( V_80 , V_31 , V_84 ) ;
F_35 ( & V_3 -> V_105 ) ;
if ( V_119 & ~ V_69 -> V_107 )
F_74 ( V_69 ) ;
F_69 ( V_80 ) ;
return 0 ;
}
static int T_7 F_83 ( void )
{
V_81 = F_84 ( V_79 , V_121 ) ;
V_122 = F_84 ( V_9 , V_121 ) ;
#ifdef F_28
V_123 = F_84 ( V_38 ,
V_121 ) ;
#endif
return 0 ;
}
