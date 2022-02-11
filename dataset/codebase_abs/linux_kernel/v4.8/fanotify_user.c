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
V_12 = F_9 ( V_3 -> V_14 . V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 -> V_16 . V_17 && V_10 -> V_16 . V_18 )
V_13 = F_10 ( & V_10 -> V_16 ,
V_3 -> V_14 . V_15 | V_19 ,
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
F_20 ( & V_3 -> V_14 . V_40 ) ;
F_21 (event, &group->fanotify_data.access_list,
fae.fse.list) {
if ( V_10 -> V_36 != V_36 )
continue;
F_22 ( & V_10 -> V_41 . V_25 . V_42 ) ;
V_39 = V_10 ;
break;
}
F_23 ( & V_3 -> V_14 . V_40 ) ;
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
F_25 ( & V_3 -> V_14 . V_49 ) ;
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
F_37 ( V_55 , V_63 ) ;
V_62 = V_50 ;
V_3 = V_11 -> V_56 ;
F_4 ( L_6 , V_6 , V_3 ) ;
F_38 ( & V_3 -> V_57 , & V_55 ) ;
while ( 1 ) {
F_34 ( & V_3 -> V_5 ) ;
V_61 = F_1 ( V_3 , V_4 ) ;
F_35 ( & V_3 -> V_5 ) ;
if ( F_12 ( V_61 ) ) {
V_24 = F_14 ( V_61 ) ;
break;
}
if ( ! V_61 ) {
V_24 = - V_64 ;
if ( V_11 -> V_15 & V_65 )
break;
V_24 = - V_66 ;
if ( F_39 ( V_67 ) )
break;
if ( V_62 != V_50 )
break;
F_40 ( & V_55 , V_68 , V_69 ) ;
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
F_25 ( & V_3 -> V_14 . V_49 ) ;
break;
}
F_20 ( & V_3 -> V_14 . V_40 ) ;
F_42 ( & V_61 -> V_42 ,
& V_3 -> V_14 . V_70 ) ;
F_23 ( & V_3 -> V_14 . V_40 ) ;
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
static int F_46 ( struct V_71 * V_72 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_56 ;
#ifdef F_28
struct V_38 * V_10 , * V_73 ;
struct V_1 * V_23 ;
F_47 ( V_3 ) ;
F_20 ( & V_3 -> V_14 . V_40 ) ;
F_48 (event, next, &group->fanotify_data.access_list,
fae.fse.list) {
F_4 ( L_8 , V_6 , V_3 ,
V_10 ) ;
F_22 ( & V_10 -> V_41 . V_25 . V_42 ) ;
V_10 -> V_45 = V_46 ;
}
F_23 ( & V_3 -> V_14 . V_40 ) ;
F_34 ( & V_3 -> V_5 ) ;
while ( ! F_5 ( V_3 ) ) {
V_23 = F_7 ( V_3 ) ;
if ( ! ( V_23 -> V_31 & V_54 ) )
F_41 ( V_3 , V_23 ) ;
else
F_29 ( V_23 ) -> V_45 = V_46 ;
}
F_35 ( & V_3 -> V_5 ) ;
F_25 ( & V_3 -> V_14 . V_49 ) ;
#endif
F_49 ( V_3 ) ;
return 0 ;
}
static long F_50 ( struct V_11 * V_11 , unsigned int V_74 , unsigned long V_75 )
{
struct V_2 * V_3 ;
struct V_1 * V_23 ;
void T_3 * V_76 ;
int V_24 = - V_77 ;
T_1 V_78 = 0 ;
V_3 = V_11 -> V_56 ;
V_76 = ( void T_3 * ) V_75 ;
switch ( V_74 ) {
case V_79 :
F_34 ( & V_3 -> V_5 ) ;
F_21 (fsn_event, &group->notification_list, list)
V_78 += V_7 ;
F_35 ( & V_3 -> V_5 ) ;
V_24 = F_51 ( V_78 , ( int T_3 * ) V_76 ) ;
break;
}
return V_24 ;
}
static void F_52 ( struct V_80 * V_81 )
{
F_53 ( V_82 , V_81 ) ;
}
static int F_54 ( int V_83 , const char T_3 * V_84 ,
struct V_16 * V_16 , unsigned int V_85 )
{
int V_24 ;
F_4 ( L_9 , V_6 ,
V_83 , V_84 , V_85 ) ;
if ( V_84 == NULL ) {
struct V_36 V_51 = F_55 ( V_83 ) ;
V_24 = - V_86 ;
if ( ! V_51 . V_11 )
goto V_87;
V_24 = - V_88 ;
if ( ( V_85 & V_89 ) &&
! ( F_56 ( F_57 ( V_51 . V_11 ) -> V_90 ) ) ) {
F_58 ( V_51 ) ;
goto V_87;
}
* V_16 = V_51 . V_11 -> V_91 ;
F_59 ( V_16 ) ;
F_58 ( V_51 ) ;
} else {
unsigned int V_92 = 0 ;
if ( ! ( V_85 & V_93 ) )
V_92 |= V_94 ;
if ( V_85 & V_89 )
V_92 |= V_95 ;
V_24 = F_60 ( V_83 , V_84 , V_92 , V_16 ) ;
if ( V_24 )
goto V_87;
}
V_24 = F_61 ( V_16 -> V_17 -> V_96 , V_97 ) ;
if ( V_24 )
F_62 ( V_16 ) ;
V_87:
return V_24 ;
}
static T_6 F_63 ( struct V_80 * V_81 ,
T_6 V_31 ,
unsigned int V_85 ,
int * V_98 )
{
T_6 V_99 = 0 ;
F_20 ( & V_81 -> V_100 ) ;
if ( ! ( V_85 & V_101 ) ) {
T_6 V_102 = V_81 -> V_31 & ~ V_31 ;
if ( V_85 & V_103 )
V_102 &= ~ V_104 ;
V_99 = V_81 -> V_31 ;
F_64 ( V_81 , V_102 ) ;
} else {
T_6 V_102 = V_81 -> V_105 & ~ V_31 ;
if ( V_85 & V_103 )
V_102 &= ~ V_104 ;
F_65 ( V_81 , V_102 ) ;
}
* V_98 = ! ( V_81 -> V_31 | V_81 -> V_105 ) ;
F_23 ( & V_81 -> V_100 ) ;
return V_31 & V_99 ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_106 * V_18 , T_6 V_31 ,
unsigned int V_85 )
{
struct V_80 * V_81 = NULL ;
T_6 V_107 ;
int V_108 ;
F_34 ( & V_3 -> V_109 ) ;
V_81 = F_67 ( V_3 , V_18 ) ;
if ( ! V_81 ) {
F_35 ( & V_3 -> V_109 ) ;
return - V_48 ;
}
V_107 = F_63 ( V_81 , V_31 , V_85 ,
& V_108 ) ;
if ( V_108 )
F_68 ( V_81 ) ;
F_35 ( & V_3 -> V_109 ) ;
if ( V_108 )
F_69 ( V_81 ) ;
F_70 ( V_81 ) ;
if ( V_107 & F_71 ( V_18 ) -> V_110 )
F_72 ( V_18 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_71 * V_71 , T_6 V_31 ,
unsigned int V_85 )
{
struct V_80 * V_81 = NULL ;
T_6 V_107 ;
int V_108 ;
F_34 ( & V_3 -> V_109 ) ;
V_81 = F_74 ( V_3 , V_71 ) ;
if ( ! V_81 ) {
F_35 ( & V_3 -> V_109 ) ;
return - V_48 ;
}
V_107 = F_63 ( V_81 , V_31 , V_85 ,
& V_108 ) ;
if ( V_108 )
F_68 ( V_81 ) ;
F_35 ( & V_3 -> V_109 ) ;
if ( V_108 )
F_69 ( V_81 ) ;
F_70 ( V_81 ) ;
if ( V_107 & V_71 -> V_111 )
F_75 ( V_71 ) ;
return 0 ;
}
static T_6 F_76 ( struct V_80 * V_81 ,
T_6 V_31 ,
unsigned int V_85 )
{
T_6 V_99 = - 1 ;
F_20 ( & V_81 -> V_100 ) ;
if ( ! ( V_85 & V_101 ) ) {
T_6 V_102 = V_81 -> V_31 | V_31 ;
if ( V_85 & V_103 )
V_102 |= V_104 ;
V_99 = V_81 -> V_31 ;
F_64 ( V_81 , V_102 ) ;
} else {
T_6 V_102 = V_81 -> V_105 | V_31 ;
if ( V_85 & V_103 )
V_102 |= V_104 ;
F_65 ( V_81 , V_102 ) ;
if ( V_85 & V_112 )
V_81 -> V_85 |= V_113 ;
}
F_23 ( & V_81 -> V_100 ) ;
return V_31 & ~ V_99 ;
}
static struct V_80 * F_77 ( struct V_2 * V_3 ,
struct V_71 * V_71 ,
struct V_106 * V_18 )
{
struct V_80 * V_114 ;
int V_24 ;
if ( F_78 ( & V_3 -> V_115 ) > V_3 -> V_14 . V_116 )
return F_6 ( - V_117 ) ;
V_114 = F_79 ( V_82 , V_118 ) ;
if ( ! V_114 )
return F_6 ( - V_119 ) ;
F_80 ( V_114 , F_52 ) ;
V_24 = F_81 ( V_114 , V_3 , V_71 , V_18 , 0 ) ;
if ( V_24 ) {
F_70 ( V_114 ) ;
return F_6 ( V_24 ) ;
}
return V_114 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_106 * V_18 , T_6 V_31 ,
unsigned int V_85 )
{
struct V_80 * V_81 ;
T_6 V_120 ;
F_34 ( & V_3 -> V_109 ) ;
V_81 = F_67 ( V_3 , V_18 ) ;
if ( ! V_81 ) {
V_81 = F_77 ( V_3 , NULL , V_18 ) ;
if ( F_12 ( V_81 ) ) {
F_35 ( & V_3 -> V_109 ) ;
return F_14 ( V_81 ) ;
}
}
V_120 = F_76 ( V_81 , V_31 , V_85 ) ;
F_35 ( & V_3 -> V_109 ) ;
if ( V_120 & ~ F_71 ( V_18 ) -> V_110 )
F_72 ( V_18 ) ;
F_70 ( V_81 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_71 * V_71 , T_6 V_31 ,
unsigned int V_85 )
{
struct V_80 * V_81 ;
T_6 V_120 ;
F_4 ( L_10 , V_6 , V_3 , V_71 ) ;
if ( ( V_85 & V_101 ) &&
! ( V_85 & V_112 ) &&
( F_78 ( & V_71 -> V_121 ) > 0 ) )
return 0 ;
F_34 ( & V_3 -> V_109 ) ;
V_81 = F_74 ( V_3 , V_71 ) ;
if ( ! V_81 ) {
V_81 = F_77 ( V_3 , V_71 , NULL ) ;
if ( F_12 ( V_81 ) ) {
F_35 ( & V_3 -> V_109 ) ;
return F_14 ( V_81 ) ;
}
}
V_120 = F_76 ( V_81 , V_31 , V_85 ) ;
F_35 ( & V_3 -> V_109 ) ;
if ( V_120 & ~ V_71 -> V_111 )
F_75 ( V_71 ) ;
F_70 ( V_81 ) ;
return 0 ;
}
static int T_7 F_84 ( void )
{
V_82 = F_85 ( V_80 , V_122 ) ;
V_123 = F_85 ( V_9 , V_122 ) ;
#ifdef F_28
V_124 = F_85 ( V_38 ,
V_122 ) ;
#endif
return 0 ;
}
