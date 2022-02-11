static inline T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
V_2 = ( V_3 | V_4 | V_5 ) ;
V_2 |= ( V_1 & ( V_6 | V_7 | V_8 ) ) ;
return V_2 ;
}
static inline T_2 F_2 ( T_1 V_2 )
{
return V_2 & ( V_6 | V_9 | V_10 | V_11 |
V_12 ) ;
}
static unsigned int F_3 ( struct V_13 * V_13 , T_3 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_18 = 0 ;
F_4 ( V_13 , & V_16 -> V_19 , V_14 ) ;
F_5 ( & V_16 -> V_20 ) ;
if ( ! F_6 ( V_16 ) )
V_18 = V_21 | V_22 ;
F_7 ( & V_16 -> V_20 ) ;
return V_18 ;
}
static int F_8 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
V_26 = F_9 ( V_24 ) ;
if ( ! V_26 -> V_27 )
return 0 ;
return F_10 ( V_26 -> V_27 + 1 , sizeof( struct V_28 ) ) ;
}
static struct V_23 * F_11 ( struct V_15 * V_16 ,
T_4 V_29 )
{
T_4 V_30 = sizeof( struct V_28 ) ;
struct V_23 * V_26 ;
if ( F_6 ( V_16 ) )
return NULL ;
V_26 = F_12 ( V_16 ) ;
F_13 ( L_1 , V_31 , V_16 , V_26 ) ;
V_30 += F_8 ( V_26 ) ;
if ( V_30 > V_29 )
return F_14 ( - V_32 ) ;
F_15 ( V_16 ) ;
return V_26 ;
}
static T_5 F_16 ( struct V_15 * V_16 ,
struct V_23 * V_24 ,
char T_6 * V_33 )
{
struct V_28 V_28 ;
struct V_25 * V_26 ;
T_4 V_30 = sizeof( struct V_28 ) ;
T_4 V_27 ;
T_4 V_34 ;
F_13 ( L_1 , V_31 , V_16 , V_24 ) ;
V_26 = F_9 ( V_24 ) ;
V_27 = V_26 -> V_27 ;
V_34 = F_8 ( V_24 ) ;
V_28 . V_35 = V_34 ;
V_28 . V_2 = F_2 ( V_24 -> V_2 ) ;
V_28 . V_36 = V_26 -> V_36 ;
V_28 . V_37 = V_26 -> V_38 ;
if ( F_17 ( V_33 , & V_28 , V_30 ) )
return - V_39 ;
V_33 += V_30 ;
if ( V_34 ) {
if ( F_17 ( V_33 , V_26 -> V_40 , V_27 ) )
return - V_39 ;
V_33 += V_27 ;
if ( F_18 ( V_33 , V_34 - V_27 ) )
return - V_39 ;
V_30 += V_34 ;
}
return V_30 ;
}
static T_5 F_19 ( struct V_13 * V_13 , char T_6 * V_33 ,
T_4 V_29 , T_7 * V_41 )
{
struct V_15 * V_16 ;
struct V_23 * V_42 ;
char T_6 * V_43 ;
int V_18 ;
F_20 ( V_14 ) ;
V_43 = V_33 ;
V_16 = V_13 -> V_17 ;
while ( 1 ) {
F_21 ( & V_16 -> V_19 , & V_14 , V_44 ) ;
F_5 ( & V_16 -> V_20 ) ;
V_42 = F_11 ( V_16 , V_29 ) ;
F_7 ( & V_16 -> V_20 ) ;
F_13 ( L_2 , V_31 , V_16 , V_42 ) ;
if ( V_42 ) {
V_18 = F_22 ( V_42 ) ;
if ( F_23 ( V_42 ) )
break;
V_18 = F_16 ( V_16 , V_42 , V_33 ) ;
F_24 ( V_16 , V_42 ) ;
if ( V_18 < 0 )
break;
V_33 += V_18 ;
V_29 -= V_18 ;
continue;
}
V_18 = - V_45 ;
if ( V_13 -> V_46 & V_47 )
break;
V_18 = - V_48 ;
if ( F_25 ( V_49 ) )
break;
if ( V_43 != V_33 )
break;
F_26 () ;
}
F_27 ( & V_16 -> V_19 , & V_14 ) ;
if ( V_43 != V_33 && V_18 != - V_39 )
V_18 = V_33 - V_43 ;
return V_18 ;
}
static int F_28 ( struct V_50 * V_51 , struct V_13 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_13 ( L_3 , V_31 , V_16 ) ;
F_29 ( V_16 ) ;
return 0 ;
}
static long F_30 ( struct V_13 * V_13 , unsigned int V_52 ,
unsigned long V_1 )
{
struct V_15 * V_16 ;
struct V_23 * V_24 ;
void T_6 * V_53 ;
int V_18 = - V_54 ;
T_4 V_55 = 0 ;
V_16 = V_13 -> V_17 ;
V_53 = ( void T_6 * ) V_1 ;
F_13 ( L_4 , V_31 , V_16 , V_52 ) ;
switch ( V_52 ) {
case V_56 :
F_5 ( & V_16 -> V_20 ) ;
F_31 (fsn_event, &group->notification_list,
list) {
V_55 += sizeof( struct V_28 ) ;
V_55 += F_8 ( V_24 ) ;
}
F_7 ( & V_16 -> V_20 ) ;
V_18 = F_32 ( V_55 , ( int T_6 * ) V_53 ) ;
break;
}
return V_18 ;
}
static int F_33 ( const char T_6 * V_57 , struct V_58 * V_58 , unsigned V_59 )
{
int error ;
error = F_34 ( V_60 , V_57 , V_59 , V_58 ) ;
if ( error )
return error ;
error = F_35 ( V_58 -> V_61 -> V_62 , V_63 ) ;
if ( error )
F_36 ( V_58 ) ;
return error ;
}
static int F_37 ( struct V_64 * V_64 , T_8 * V_65 ,
struct V_66 * V_67 )
{
int V_18 ;
F_38 ( V_68 ) ;
F_39 ( V_65 ) ;
V_18 = F_40 ( V_64 , V_67 , 1 , 0 , V_69 ) ;
if ( V_18 >= 0 ) {
V_67 -> V_36 = V_18 ;
F_41 ( & V_67 -> V_70 ) ;
}
F_42 ( V_65 ) ;
F_43 () ;
return V_18 < 0 ? V_18 : 0 ;
}
static struct V_66 * F_44 ( struct V_15 * V_16 ,
int V_36 )
{
struct V_64 * V_64 = & V_16 -> V_71 . V_64 ;
T_8 * V_65 = & V_16 -> V_71 . V_65 ;
struct V_66 * V_67 ;
F_45 ( V_65 ) ;
V_67 = F_46 ( V_64 , V_36 ) ;
if ( V_67 ) {
struct V_72 * V_70 = & V_67 -> V_70 ;
F_41 ( V_70 ) ;
F_47 ( F_48 ( & V_70 -> V_73 ) < 2 ) ;
}
return V_67 ;
}
static struct V_66 * F_49 ( struct V_15 * V_16 ,
int V_36 )
{
struct V_66 * V_67 ;
T_8 * V_65 = & V_16 -> V_71 . V_65 ;
F_39 ( V_65 ) ;
V_67 = F_44 ( V_16 , V_36 ) ;
F_42 ( V_65 ) ;
return V_67 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_66 * V_67 )
{
struct V_64 * V_64 = & V_16 -> V_71 . V_64 ;
T_8 * V_65 = & V_16 -> V_71 . V_65 ;
int V_36 = V_67 -> V_36 ;
F_45 ( V_65 ) ;
F_51 ( V_64 , V_36 ) ;
F_52 ( & V_67 -> V_70 ) ;
}
static void F_53 ( struct V_15 * V_16 ,
struct V_66 * V_67 )
{
T_8 * V_65 = & V_16 -> V_71 . V_65 ;
struct V_66 * V_74 = NULL ;
int V_36 ;
F_39 ( V_65 ) ;
V_36 = V_67 -> V_36 ;
if ( V_36 == - 1 ) {
F_54 ( 1 , L_5
L_6 , V_31 , V_67 , V_67 -> V_36 ,
V_67 -> V_70 . V_16 , V_67 -> V_70 . V_75 . V_50 ) ;
goto V_76;
}
V_74 = F_44 ( V_16 , V_36 ) ;
if ( F_55 ( ! V_74 ) ) {
F_54 ( 1 , L_5
L_6 , V_31 , V_67 , V_67 -> V_36 ,
V_67 -> V_70 . V_16 , V_67 -> V_70 . V_75 . V_50 ) ;
goto V_76;
}
if ( F_55 ( V_74 != V_67 ) ) {
F_54 ( 1 , L_7
L_8
L_9 ,
V_31 , V_67 , V_67 -> V_36 , V_67 -> V_70 . V_16 ,
V_67 -> V_70 . V_75 . V_50 , V_74 , V_74 -> V_36 ,
V_74 -> V_70 . V_16 ,
V_74 -> V_70 . V_75 . V_50 ) ;
goto V_76;
}
if ( F_55 ( F_48 ( & V_67 -> V_70 . V_73 ) < 3 ) ) {
F_56 ( V_77 L_5
L_6 , V_31 , V_67 , V_67 -> V_36 ,
V_67 -> V_70 . V_16 , V_67 -> V_70 . V_75 . V_50 ) ;
F_57 () ;
}
F_50 ( V_16 , V_67 ) ;
V_76:
if ( V_74 )
F_52 ( & V_74 -> V_70 ) ;
V_67 -> V_36 = - 1 ;
F_42 ( V_65 ) ;
}
void F_58 ( struct V_72 * V_70 ,
struct V_15 * V_16 )
{
struct V_66 * V_67 ;
F_59 ( V_16 , NULL , V_70 , NULL , V_3 ,
NULL , V_78 , NULL , 0 ) ;
V_67 = F_60 ( V_70 , struct V_66 , V_70 ) ;
F_53 ( V_16 , V_67 ) ;
F_61 ( & V_16 -> V_71 . V_79 -> V_80 ) ;
}
static void F_62 ( struct V_72 * V_70 )
{
struct V_66 * V_67 ;
V_67 = F_60 ( V_70 , struct V_66 , V_70 ) ;
F_63 ( V_81 , V_67 ) ;
}
static int F_64 ( struct V_15 * V_16 ,
struct V_50 * V_50 ,
T_2 V_1 )
{
struct V_72 * V_70 ;
struct V_66 * V_67 ;
T_1 V_82 , V_83 ;
T_1 V_2 ;
int V_84 = ( V_1 & V_85 ) ;
int V_18 ;
V_2 = F_1 ( V_1 ) ;
V_70 = F_65 ( V_16 , V_50 ) ;
if ( ! V_70 )
return - V_86 ;
V_67 = F_60 ( V_70 , struct V_66 , V_70 ) ;
F_39 ( & V_70 -> V_87 ) ;
V_82 = V_70 -> V_2 ;
if ( V_84 )
F_66 ( V_70 , ( V_70 -> V_2 | V_2 ) ) ;
else
F_66 ( V_70 , V_2 ) ;
V_83 = V_70 -> V_2 ;
F_42 ( & V_70 -> V_87 ) ;
if ( V_82 != V_83 ) {
int V_88 = ( V_82 & ~ V_83 ) ;
int V_89 = ( V_83 & ~ V_50 -> V_90 ) ;
if ( V_88 || V_89 )
F_67 ( V_50 ) ;
}
V_18 = V_67 -> V_36 ;
F_52 ( V_70 ) ;
return V_18 ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_50 * V_50 ,
T_2 V_1 )
{
struct V_66 * V_91 ;
T_1 V_2 ;
int V_18 ;
struct V_64 * V_64 = & V_16 -> V_71 . V_64 ;
T_8 * V_65 = & V_16 -> V_71 . V_65 ;
V_2 = F_1 ( V_1 ) ;
V_91 = F_69 ( V_81 , V_68 ) ;
if ( F_55 ( ! V_91 ) )
return - V_92 ;
F_70 ( & V_91 -> V_70 , F_62 ) ;
V_91 -> V_70 . V_2 = V_2 ;
V_91 -> V_36 = - 1 ;
V_18 = - V_93 ;
if ( F_48 ( & V_16 -> V_71 . V_79 -> V_80 ) >= V_94 )
goto V_95;
V_18 = F_37 ( V_64 , V_65 , V_91 ) ;
if ( V_18 )
goto V_95;
V_18 = F_71 ( & V_91 -> V_70 , V_16 , V_50 ,
NULL , 0 ) ;
if ( V_18 ) {
F_53 ( V_16 , V_91 ) ;
goto V_95;
}
F_72 ( & V_16 -> V_71 . V_79 -> V_80 ) ;
V_18 = V_91 -> V_36 ;
V_95:
F_52 ( & V_91 -> V_70 ) ;
return V_18 ;
}
static int F_73 ( struct V_15 * V_16 , struct V_50 * V_50 , T_2 V_1 )
{
int V_18 = 0 ;
F_5 ( & V_16 -> V_96 ) ;
V_18 = F_64 ( V_16 , V_50 , V_1 ) ;
if ( V_18 == - V_86 )
V_18 = F_68 ( V_16 , V_50 , V_1 ) ;
F_7 ( & V_16 -> V_96 ) ;
return V_18 ;
}
static struct V_15 * F_74 ( unsigned int V_97 )
{
struct V_15 * V_16 ;
struct V_25 * V_98 ;
V_16 = F_75 ( & V_99 ) ;
if ( F_23 ( V_16 ) )
return V_16 ;
V_98 = F_76 ( sizeof( struct V_25 ) , V_68 ) ;
if ( F_55 ( ! V_98 ) ) {
F_29 ( V_16 ) ;
return F_14 ( - V_92 ) ;
}
V_16 -> V_100 = & V_98 -> V_101 ;
F_77 ( V_16 -> V_100 , NULL , V_102 ) ;
V_98 -> V_36 = - 1 ;
V_98 -> V_38 = 0 ;
V_98 -> V_27 = 0 ;
V_16 -> V_97 = V_97 ;
F_78 ( & V_16 -> V_71 . V_65 ) ;
F_79 ( & V_16 -> V_71 . V_64 ) ;
V_16 -> V_71 . V_79 = F_80 () ;
if ( F_81 ( & V_16 -> V_71 . V_79 -> V_103 ) >
V_104 ) {
F_29 ( V_16 ) ;
return F_14 ( - V_105 ) ;
}
return V_16 ;
}
static int T_9 F_82 ( void )
{
F_83 ( V_106 != V_107 ) ;
F_83 ( V_108 != V_109 ) ;
F_83 ( V_110 != V_111 ) ;
F_83 ( V_112 != V_113 ) ;
F_83 ( V_114 != V_115 ) ;
F_83 ( V_116 != V_117 ) ;
F_83 ( V_118 != V_119 ) ;
F_83 ( V_120 != V_121 ) ;
F_83 ( V_122 != V_123 ) ;
F_83 ( V_124 != V_125 ) ;
F_83 ( V_126 != V_127 ) ;
F_83 ( V_128 != V_129 ) ;
F_83 ( V_10 != V_5 ) ;
F_83 ( V_12 != V_102 ) ;
F_83 ( V_11 != V_3 ) ;
F_83 ( V_8 != V_130 ) ;
F_83 ( V_9 != V_131 ) ;
F_83 ( V_7 != V_132 ) ;
F_47 ( F_84 ( V_133 ) != 21 ) ;
V_81 = F_85 ( V_66 , V_134 ) ;
V_135 = 16384 ;
V_104 = 128 ;
V_94 = 8192 ;
return 0 ;
}
