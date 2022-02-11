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
F_32 ( V_16 ) ;
return 0 ;
}
static long F_33 ( struct V_13 * V_13 , unsigned int V_56 ,
unsigned long V_1 )
{
struct V_15 * V_16 ;
struct V_57 * V_58 ;
struct V_23 * V_27 ;
void T_6 * V_59 ;
int V_18 = - V_60 ;
T_4 V_61 = 0 ;
V_16 = V_13 -> V_17 ;
V_59 = ( void T_6 * ) V_1 ;
F_10 ( L_4 , V_28 , V_16 , V_56 ) ;
switch ( V_56 ) {
case V_62 :
F_5 ( & V_16 -> V_20 ) ;
F_34 (holder, &group->notification_list, event_list) {
V_27 = V_58 -> V_27 ;
V_61 += sizeof( struct V_26 ) ;
if ( V_27 -> V_29 )
V_61 += F_11 ( V_27 -> V_29 + 1 ,
sizeof( struct V_26 ) ) ;
}
F_7 ( & V_16 -> V_20 ) ;
V_18 = F_35 ( V_61 , ( int T_6 * ) V_59 ) ;
break;
}
return V_18 ;
}
static int F_36 ( const char T_6 * V_63 , struct V_64 * V_64 , unsigned V_65 )
{
int error ;
error = F_37 ( V_66 , V_63 , V_65 , V_64 ) ;
if ( error )
return error ;
error = F_38 ( V_64 -> V_67 -> V_68 , V_69 ) ;
if ( error )
F_39 ( V_64 ) ;
return error ;
}
static int F_40 ( struct V_70 * V_70 , T_8 * V_71 ,
struct V_72 * V_73 )
{
int V_18 ;
F_41 ( V_74 ) ;
F_15 ( V_71 ) ;
V_18 = F_42 ( V_70 , V_73 , 1 , 0 , V_75 ) ;
if ( V_18 >= 0 ) {
V_73 -> V_37 = V_18 ;
F_43 ( & V_73 -> V_76 ) ;
}
F_17 ( V_71 ) ;
F_44 () ;
return V_18 < 0 ? V_18 : 0 ;
}
static struct V_72 * F_45 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_70 * V_70 = & V_16 -> V_77 . V_70 ;
T_8 * V_71 = & V_16 -> V_77 . V_71 ;
struct V_72 * V_73 ;
F_46 ( V_71 ) ;
V_73 = F_47 ( V_70 , V_37 ) ;
if ( V_73 ) {
struct V_78 * V_76 = & V_73 -> V_76 ;
F_43 ( V_76 ) ;
F_48 ( F_49 ( & V_76 -> V_79 ) < 2 ) ;
}
return V_73 ;
}
static struct V_72 * F_50 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_72 * V_73 ;
T_8 * V_71 = & V_16 -> V_77 . V_71 ;
F_15 ( V_71 ) ;
V_73 = F_45 ( V_16 , V_37 ) ;
F_17 ( V_71 ) ;
return V_73 ;
}
static void F_51 ( struct V_15 * V_16 ,
struct V_72 * V_73 )
{
struct V_70 * V_70 = & V_16 -> V_77 . V_70 ;
T_8 * V_71 = & V_16 -> V_77 . V_71 ;
int V_37 = V_73 -> V_37 ;
F_46 ( V_71 ) ;
F_52 ( V_70 , V_37 ) ;
F_53 ( & V_73 -> V_76 ) ;
}
static void F_54 ( struct V_15 * V_16 ,
struct V_72 * V_73 )
{
T_8 * V_71 = & V_16 -> V_77 . V_71 ;
struct V_72 * V_80 = NULL ;
int V_37 ;
F_15 ( V_71 ) ;
V_37 = V_73 -> V_37 ;
if ( V_37 == - 1 ) {
F_55 ( 1 , L_5
L_6 , V_28 , V_73 , V_73 -> V_37 ,
V_73 -> V_76 . V_16 , V_73 -> V_76 . V_81 . V_54 ) ;
goto V_82;
}
V_80 = F_45 ( V_16 , V_37 ) ;
if ( F_56 ( ! V_80 ) ) {
F_55 ( 1 , L_5
L_6 , V_28 , V_73 , V_73 -> V_37 ,
V_73 -> V_76 . V_16 , V_73 -> V_76 . V_81 . V_54 ) ;
goto V_82;
}
if ( F_56 ( V_80 != V_73 ) ) {
F_55 ( 1 , L_7
L_8
L_9 ,
V_28 , V_73 , V_73 -> V_37 , V_73 -> V_76 . V_16 ,
V_73 -> V_76 . V_81 . V_54 , V_80 , V_80 -> V_37 ,
V_80 -> V_76 . V_16 ,
V_80 -> V_76 . V_81 . V_54 ) ;
goto V_82;
}
if ( F_56 ( F_49 ( & V_73 -> V_76 . V_79 ) < 3 ) ) {
F_57 ( V_83 L_5
L_6 , V_28 , V_73 , V_73 -> V_37 ,
V_73 -> V_76 . V_16 , V_73 -> V_76 . V_81 . V_54 ) ;
F_58 () ;
}
F_51 ( V_16 , V_73 ) ;
V_82:
if ( V_80 )
F_53 ( & V_80 -> V_76 ) ;
V_73 -> V_37 = - 1 ;
F_17 ( V_71 ) ;
}
void F_59 ( struct V_78 * V_76 ,
struct V_15 * V_16 )
{
struct V_72 * V_73 ;
struct V_23 * V_84 , * V_85 ;
struct V_34 * V_86 ;
struct V_32 * V_87 ;
int V_18 ;
V_73 = F_18 ( V_76 , struct V_72 , V_76 ) ;
V_84 = F_60 ( NULL , V_3 , NULL ,
V_88 , NULL , 0 ,
V_89 ) ;
if ( ! V_84 )
goto V_90;
V_86 = F_61 ( V_91 , V_89 ) ;
if ( F_56 ( ! V_86 ) )
goto V_90;
V_87 = & V_86 -> V_38 ;
F_62 ( V_16 ) ;
V_87 -> V_16 = V_16 ;
V_86 -> V_37 = V_73 -> V_37 ;
V_85 = F_63 ( V_16 , V_84 , V_87 , NULL ) ;
if ( V_85 ) {
if ( F_26 ( V_85 ) )
V_18 = F_25 ( V_85 ) ;
else
F_27 ( V_85 ) ;
F_19 ( V_87 ) ;
}
V_90:
if ( V_84 )
F_27 ( V_84 ) ;
F_54 ( V_16 , V_73 ) ;
F_64 ( & V_16 -> V_77 . V_92 -> V_93 ) ;
}
static void F_65 ( struct V_78 * V_76 )
{
struct V_72 * V_73 ;
V_73 = F_18 ( V_76 , struct V_72 , V_76 ) ;
F_66 ( V_94 , V_73 ) ;
}
static int F_67 ( struct V_15 * V_16 ,
struct V_54 * V_54 ,
T_2 V_1 )
{
struct V_78 * V_76 ;
struct V_72 * V_73 ;
T_1 V_95 , V_96 ;
T_1 V_2 ;
int V_97 = ( V_1 & V_98 ) ;
int V_18 ;
V_2 = F_1 ( V_1 ) ;
V_76 = F_68 ( V_16 , V_54 ) ;
if ( ! V_76 )
return - V_99 ;
V_73 = F_18 ( V_76 , struct V_72 , V_76 ) ;
F_15 ( & V_76 -> V_36 ) ;
V_95 = V_76 -> V_2 ;
if ( V_97 )
F_69 ( V_76 , ( V_76 -> V_2 | V_2 ) ) ;
else
F_69 ( V_76 , V_2 ) ;
V_96 = V_76 -> V_2 ;
F_17 ( & V_76 -> V_36 ) ;
if ( V_95 != V_96 ) {
int V_100 = ( V_95 & ~ V_96 ) ;
int V_101 = ( V_96 & ~ V_54 -> V_102 ) ;
if ( V_100 || V_101 )
F_70 ( V_54 ) ;
}
V_18 = V_73 -> V_37 ;
F_53 ( V_76 ) ;
return V_18 ;
}
static int F_71 ( struct V_15 * V_16 ,
struct V_54 * V_54 ,
T_2 V_1 )
{
struct V_72 * V_103 ;
T_1 V_2 ;
int V_18 ;
struct V_70 * V_70 = & V_16 -> V_77 . V_70 ;
T_8 * V_71 = & V_16 -> V_77 . V_71 ;
V_2 = F_1 ( V_1 ) ;
V_103 = F_61 ( V_94 , V_74 ) ;
if ( F_56 ( ! V_103 ) )
return - V_104 ;
F_72 ( & V_103 -> V_76 , F_65 ) ;
V_103 -> V_76 . V_2 = V_2 ;
V_103 -> V_37 = - 1 ;
V_18 = - V_105 ;
if ( F_49 ( & V_16 -> V_77 . V_92 -> V_93 ) >= V_106 )
goto V_107;
V_18 = F_40 ( V_70 , V_71 , V_103 ) ;
if ( V_18 )
goto V_107;
V_18 = F_73 ( & V_103 -> V_76 , V_16 , V_54 , NULL , 0 ) ;
if ( V_18 ) {
F_54 ( V_16 , V_103 ) ;
goto V_107;
}
F_74 ( & V_16 -> V_77 . V_92 -> V_93 ) ;
V_18 = V_103 -> V_37 ;
V_107:
F_53 ( & V_103 -> V_76 ) ;
return V_18 ;
}
static int F_75 ( struct V_15 * V_16 , struct V_54 * V_54 , T_2 V_1 )
{
int V_18 = 0 ;
V_108:
V_18 = F_67 ( V_16 , V_54 , V_1 ) ;
if ( V_18 == - V_99 )
V_18 = F_71 ( V_16 , V_54 , V_1 ) ;
if ( V_18 == - V_109 )
goto V_108;
return V_18 ;
}
static struct V_15 * F_76 ( unsigned int V_110 )
{
struct V_15 * V_16 ;
V_16 = F_77 ( & V_111 ) ;
if ( F_26 ( V_16 ) )
return V_16 ;
V_16 -> V_110 = V_110 ;
F_78 ( & V_16 -> V_77 . V_71 ) ;
F_79 ( & V_16 -> V_77 . V_70 ) ;
V_16 -> V_77 . V_92 = F_80 () ;
if ( F_81 ( & V_16 -> V_77 . V_92 -> V_112 ) >
V_113 ) {
F_32 ( V_16 ) ;
return F_12 ( - V_114 ) ;
}
return V_16 ;
}
static int T_9 F_82 ( void )
{
F_83 ( V_115 != V_116 ) ;
F_83 ( V_117 != V_118 ) ;
F_83 ( V_119 != V_120 ) ;
F_83 ( V_121 != V_122 ) ;
F_83 ( V_123 != V_124 ) ;
F_83 ( V_125 != V_126 ) ;
F_83 ( V_127 != V_128 ) ;
F_83 ( V_129 != V_130 ) ;
F_83 ( V_131 != V_132 ) ;
F_83 ( V_133 != V_134 ) ;
F_83 ( V_135 != V_136 ) ;
F_83 ( V_137 != V_138 ) ;
F_83 ( V_10 != V_5 ) ;
F_83 ( V_12 != V_139 ) ;
F_83 ( V_11 != V_3 ) ;
F_83 ( V_8 != V_140 ) ;
F_83 ( V_9 != V_141 ) ;
F_83 ( V_7 != V_142 ) ;
F_48 ( F_84 ( V_143 ) != 21 ) ;
V_94 = F_85 ( V_72 , V_144 ) ;
V_91 = F_85 ( V_34 , V_144 ) ;
V_145 = 16384 ;
V_113 = 128 ;
V_106 = 8192 ;
return 0 ;
}
