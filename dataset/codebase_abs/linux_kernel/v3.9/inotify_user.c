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
static struct V_23 * F_8 ( struct V_15 * V_16 ,
T_4 V_24 )
{
T_4 V_25 = sizeof( struct V_26 ) ;
struct V_23 * V_27 ;
if ( F_6 ( V_16 ) )
return NULL ;
V_27 = F_9 ( V_16 ) ;
F_10 ( L_1 , V_28 , V_16 , V_27 ) ;
if ( V_27 -> V_29 )
V_25 += F_11 ( V_27 -> V_29 + 1 , V_25 ) ;
if ( V_25 > V_24 )
return F_12 ( - V_30 ) ;
F_13 ( V_16 ) ;
return V_27 ;
}
static T_5 F_14 ( struct V_15 * V_16 ,
struct V_23 * V_27 ,
char T_6 * V_31 )
{
struct V_26 V_26 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_4 V_25 = sizeof( struct V_26 ) ;
T_4 V_29 = 0 ;
F_10 ( L_1 , V_28 , V_16 , V_27 ) ;
F_15 ( & V_27 -> V_36 ) ;
V_33 = F_16 ( V_16 , V_27 ) ;
F_17 ( & V_27 -> V_36 ) ;
if ( ! V_33 )
V_26 . V_37 = - 1 ;
else {
V_35 = F_18 ( V_33 , struct V_34 ,
V_38 ) ;
V_26 . V_37 = V_35 -> V_37 ;
F_19 ( V_33 ) ;
}
if ( V_27 -> V_29 )
V_29 = F_11 ( V_27 -> V_29 + 1 , V_25 ) ;
V_26 . V_39 = V_29 ;
V_26 . V_2 = F_2 ( V_27 -> V_2 ) ;
V_26 . V_40 = V_27 -> V_41 ;
if ( F_20 ( V_31 , & V_26 , V_25 ) )
return - V_42 ;
V_31 += V_25 ;
if ( V_29 ) {
unsigned int V_43 = V_29 - V_27 -> V_29 ;
if ( F_20 ( V_31 , V_27 -> V_44 , V_27 -> V_29 ) )
return - V_42 ;
V_31 += V_27 -> V_29 ;
if ( F_21 ( V_31 , V_43 ) )
return - V_42 ;
V_31 += V_43 ;
V_25 += V_29 ;
}
return V_25 ;
}
static T_5 F_22 ( struct V_13 * V_13 , char T_6 * V_31 ,
T_4 V_24 , T_7 * V_45 )
{
struct V_15 * V_16 ;
struct V_23 * V_46 ;
char T_6 * V_47 ;
int V_18 ;
F_23 ( V_14 ) ;
V_47 = V_31 ;
V_16 = V_13 -> V_17 ;
while ( 1 ) {
F_24 ( & V_16 -> V_19 , & V_14 , V_48 ) ;
F_5 ( & V_16 -> V_20 ) ;
V_46 = F_8 ( V_16 , V_24 ) ;
F_7 ( & V_16 -> V_20 ) ;
F_10 ( L_2 , V_28 , V_16 , V_46 ) ;
if ( V_46 ) {
V_18 = F_25 ( V_46 ) ;
if ( F_26 ( V_46 ) )
break;
V_18 = F_14 ( V_16 , V_46 , V_31 ) ;
F_27 ( V_46 ) ;
if ( V_18 < 0 )
break;
V_31 += V_18 ;
V_24 -= V_18 ;
continue;
}
V_18 = - V_49 ;
if ( V_13 -> V_50 & V_51 )
break;
V_18 = - V_52 ;
if ( F_28 ( V_53 ) )
break;
if ( V_47 != V_31 )
break;
F_29 () ;
}
F_30 ( & V_16 -> V_19 , & V_14 ) ;
if ( V_47 != V_31 && V_18 != - V_42 )
V_18 = V_31 - V_47 ;
return V_18 ;
}
static int F_31 ( struct V_54 * V_55 , struct V_13 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_10 ( L_3 , V_28 , V_16 ) ;
if ( V_13 -> V_50 & V_56 )
F_32 ( - 1 , V_13 , 0 ) ;
F_33 ( V_16 ) ;
return 0 ;
}
static long F_34 ( struct V_13 * V_13 , unsigned int V_57 ,
unsigned long V_1 )
{
struct V_15 * V_16 ;
struct V_58 * V_59 ;
struct V_23 * V_27 ;
void T_6 * V_60 ;
int V_18 = - V_61 ;
T_4 V_62 = 0 ;
V_16 = V_13 -> V_17 ;
V_60 = ( void T_6 * ) V_1 ;
F_10 ( L_4 , V_28 , V_16 , V_57 ) ;
switch ( V_57 ) {
case V_63 :
F_5 ( & V_16 -> V_20 ) ;
F_35 (holder, &group->notification_list, event_list) {
V_27 = V_59 -> V_27 ;
V_62 += sizeof( struct V_26 ) ;
if ( V_27 -> V_29 )
V_62 += F_11 ( V_27 -> V_29 + 1 ,
sizeof( struct V_26 ) ) ;
}
F_7 ( & V_16 -> V_20 ) ;
V_18 = F_36 ( V_62 , ( int T_6 * ) V_60 ) ;
break;
}
return V_18 ;
}
static int F_37 ( const char T_6 * V_64 , struct V_65 * V_65 , unsigned V_66 )
{
int error ;
error = F_38 ( V_67 , V_64 , V_66 , V_65 ) ;
if ( error )
return error ;
error = F_39 ( V_65 -> V_68 -> V_69 , V_70 ) ;
if ( error )
F_40 ( V_65 ) ;
return error ;
}
static int F_41 ( struct V_71 * V_71 , T_8 * V_72 ,
int * V_73 ,
struct V_74 * V_75 )
{
int V_18 ;
F_42 ( V_76 ) ;
F_15 ( V_72 ) ;
V_18 = F_43 ( V_71 , V_75 , * V_73 + 1 , 0 , V_77 ) ;
if ( V_18 >= 0 ) {
V_75 -> V_37 = V_18 ;
* V_73 = V_75 -> V_37 ;
F_44 ( & V_75 -> V_78 ) ;
}
F_17 ( V_72 ) ;
F_45 () ;
return V_18 < 0 ? V_18 : 0 ;
}
static struct V_74 * F_46 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_71 * V_71 = & V_16 -> V_79 . V_71 ;
T_8 * V_72 = & V_16 -> V_79 . V_72 ;
struct V_74 * V_75 ;
F_47 ( V_72 ) ;
V_75 = F_48 ( V_71 , V_37 ) ;
if ( V_75 ) {
struct V_80 * V_78 = & V_75 -> V_78 ;
F_44 ( V_78 ) ;
F_49 ( F_50 ( & V_78 -> V_81 ) < 2 ) ;
}
return V_75 ;
}
static struct V_74 * F_51 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_74 * V_75 ;
T_8 * V_72 = & V_16 -> V_79 . V_72 ;
F_15 ( V_72 ) ;
V_75 = F_46 ( V_16 , V_37 ) ;
F_17 ( V_72 ) ;
return V_75 ;
}
static void F_52 ( struct V_15 * V_16 ,
struct V_74 * V_75 )
{
struct V_71 * V_71 = & V_16 -> V_79 . V_71 ;
T_8 * V_72 = & V_16 -> V_79 . V_72 ;
int V_37 = V_75 -> V_37 ;
F_47 ( V_72 ) ;
F_53 ( V_71 , V_37 ) ;
F_54 ( & V_75 -> V_78 ) ;
}
static void F_55 ( struct V_15 * V_16 ,
struct V_74 * V_75 )
{
T_8 * V_72 = & V_16 -> V_79 . V_72 ;
struct V_74 * V_82 = NULL ;
int V_37 ;
F_15 ( V_72 ) ;
V_37 = V_75 -> V_37 ;
if ( V_37 == - 1 ) {
F_56 ( 1 , L_5
L_6 , V_28 , V_75 , V_75 -> V_37 ,
V_75 -> V_78 . V_16 , V_75 -> V_78 . V_83 . V_54 ) ;
goto V_84;
}
V_82 = F_46 ( V_16 , V_37 ) ;
if ( F_57 ( ! V_82 ) ) {
F_56 ( 1 , L_5
L_6 , V_28 , V_75 , V_75 -> V_37 ,
V_75 -> V_78 . V_16 , V_75 -> V_78 . V_83 . V_54 ) ;
goto V_84;
}
if ( F_57 ( V_82 != V_75 ) ) {
F_56 ( 1 , L_7
L_8
L_9 ,
V_28 , V_75 , V_75 -> V_37 , V_75 -> V_78 . V_16 ,
V_75 -> V_78 . V_83 . V_54 , V_82 , V_82 -> V_37 ,
V_82 -> V_78 . V_16 ,
V_82 -> V_78 . V_83 . V_54 ) ;
goto V_84;
}
if ( F_57 ( F_50 ( & V_75 -> V_78 . V_81 ) < 3 ) ) {
F_58 ( V_85 L_5
L_6 , V_28 , V_75 , V_75 -> V_37 ,
V_75 -> V_78 . V_16 , V_75 -> V_78 . V_83 . V_54 ) ;
F_59 () ;
}
F_52 ( V_16 , V_75 ) ;
V_84:
if ( V_82 )
F_54 ( & V_82 -> V_78 ) ;
V_75 -> V_37 = - 1 ;
F_17 ( V_72 ) ;
}
void F_60 ( struct V_80 * V_78 ,
struct V_15 * V_16 )
{
struct V_74 * V_75 ;
struct V_23 * V_86 , * V_87 ;
struct V_34 * V_88 ;
struct V_32 * V_89 ;
int V_18 ;
V_75 = F_18 ( V_78 , struct V_74 , V_78 ) ;
V_86 = F_61 ( NULL , V_3 , NULL ,
V_90 , NULL , 0 ,
V_91 ) ;
if ( ! V_86 )
goto V_92;
V_88 = F_62 ( V_93 , V_91 ) ;
if ( F_57 ( ! V_88 ) )
goto V_92;
V_89 = & V_88 -> V_38 ;
F_63 ( V_16 ) ;
V_89 -> V_16 = V_16 ;
V_88 -> V_37 = V_75 -> V_37 ;
V_87 = F_64 ( V_16 , V_86 , V_89 , NULL ) ;
if ( V_87 ) {
if ( F_26 ( V_87 ) )
V_18 = F_25 ( V_87 ) ;
else
F_27 ( V_87 ) ;
F_19 ( V_89 ) ;
}
V_92:
if ( V_86 )
F_27 ( V_86 ) ;
F_55 ( V_16 , V_75 ) ;
F_65 ( & V_16 -> V_79 . V_94 -> V_95 ) ;
}
static void F_66 ( struct V_80 * V_78 )
{
struct V_74 * V_75 ;
V_75 = F_18 ( V_78 , struct V_74 , V_78 ) ;
F_67 ( V_96 , V_75 ) ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_54 * V_54 ,
T_2 V_1 )
{
struct V_80 * V_78 ;
struct V_74 * V_75 ;
T_1 V_97 , V_98 ;
T_1 V_2 ;
int V_99 = ( V_1 & V_100 ) ;
int V_18 ;
V_2 = F_1 ( V_1 ) ;
V_78 = F_69 ( V_16 , V_54 ) ;
if ( ! V_78 )
return - V_101 ;
V_75 = F_18 ( V_78 , struct V_74 , V_78 ) ;
F_15 ( & V_78 -> V_36 ) ;
V_97 = V_78 -> V_2 ;
if ( V_99 )
F_70 ( V_78 , ( V_78 -> V_2 | V_2 ) ) ;
else
F_70 ( V_78 , V_2 ) ;
V_98 = V_78 -> V_2 ;
F_17 ( & V_78 -> V_36 ) ;
if ( V_97 != V_98 ) {
int V_102 = ( V_97 & ~ V_98 ) ;
int V_103 = ( V_98 & ~ V_54 -> V_104 ) ;
if ( V_102 || V_103 )
F_71 ( V_54 ) ;
}
V_18 = V_75 -> V_37 ;
F_54 ( V_78 ) ;
return V_18 ;
}
static int F_72 ( struct V_15 * V_16 ,
struct V_54 * V_54 ,
T_2 V_1 )
{
struct V_74 * V_105 ;
T_1 V_2 ;
int V_18 ;
struct V_71 * V_71 = & V_16 -> V_79 . V_71 ;
T_8 * V_72 = & V_16 -> V_79 . V_72 ;
V_2 = F_1 ( V_1 ) ;
V_105 = F_62 ( V_96 , V_76 ) ;
if ( F_57 ( ! V_105 ) )
return - V_106 ;
F_73 ( & V_105 -> V_78 , F_66 ) ;
V_105 -> V_78 . V_2 = V_2 ;
V_105 -> V_37 = - 1 ;
V_18 = - V_107 ;
if ( F_50 ( & V_16 -> V_79 . V_94 -> V_95 ) >= V_108 )
goto V_109;
V_18 = F_41 ( V_71 , V_72 , & V_16 -> V_79 . V_73 ,
V_105 ) ;
if ( V_18 )
goto V_109;
V_18 = F_74 ( & V_105 -> V_78 , V_16 , V_54 , NULL , 0 ) ;
if ( V_18 ) {
F_55 ( V_16 , V_105 ) ;
goto V_109;
}
F_75 ( & V_16 -> V_79 . V_94 -> V_95 ) ;
V_18 = V_105 -> V_37 ;
V_109:
F_54 ( & V_105 -> V_78 ) ;
return V_18 ;
}
static int F_76 ( struct V_15 * V_16 , struct V_54 * V_54 , T_2 V_1 )
{
int V_18 = 0 ;
V_110:
V_18 = F_68 ( V_16 , V_54 , V_1 ) ;
if ( V_18 == - V_101 )
V_18 = F_72 ( V_16 , V_54 , V_1 ) ;
if ( V_18 == - V_111 )
goto V_110;
return V_18 ;
}
static struct V_15 * F_77 ( unsigned int V_112 )
{
struct V_15 * V_16 ;
V_16 = F_78 ( & V_113 ) ;
if ( F_26 ( V_16 ) )
return V_16 ;
V_16 -> V_112 = V_112 ;
F_79 ( & V_16 -> V_79 . V_72 ) ;
F_80 ( & V_16 -> V_79 . V_71 ) ;
V_16 -> V_79 . V_73 = 0 ;
V_16 -> V_79 . V_94 = F_81 () ;
if ( F_82 ( & V_16 -> V_79 . V_94 -> V_114 ) >
V_115 ) {
F_33 ( V_16 ) ;
return F_12 ( - V_116 ) ;
}
return V_16 ;
}
static int T_9 F_83 ( void )
{
F_84 ( V_117 != V_118 ) ;
F_84 ( V_119 != V_120 ) ;
F_84 ( V_121 != V_122 ) ;
F_84 ( V_123 != V_124 ) ;
F_84 ( V_125 != V_126 ) ;
F_84 ( V_127 != V_128 ) ;
F_84 ( V_129 != V_130 ) ;
F_84 ( V_131 != V_132 ) ;
F_84 ( V_133 != V_134 ) ;
F_84 ( V_135 != V_136 ) ;
F_84 ( V_137 != V_138 ) ;
F_84 ( V_139 != V_140 ) ;
F_84 ( V_10 != V_5 ) ;
F_84 ( V_12 != V_141 ) ;
F_84 ( V_11 != V_3 ) ;
F_84 ( V_8 != V_142 ) ;
F_84 ( V_9 != V_143 ) ;
F_84 ( V_7 != V_144 ) ;
F_49 ( F_85 ( V_145 ) != 21 ) ;
V_96 = F_86 ( V_74 , V_146 ) ;
V_93 = F_86 ( V_34 , V_146 ) ;
V_147 = 16384 ;
V_115 = 128 ;
V_108 = 8192 ;
return 0 ;
}
