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
static int F_31 ( int V_54 , struct V_13 * V_13 , int V_55 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
return F_32 ( V_54 , V_13 , V_55 , & V_16 -> V_56 . V_57 ) >= 0 ? 0 : - V_58 ;
}
static int F_33 ( struct V_59 * V_60 , struct V_13 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_10 ( L_3 , V_28 , V_16 ) ;
F_34 ( V_16 ) ;
F_35 ( V_16 ) ;
return 0 ;
}
static long F_36 ( struct V_13 * V_13 , unsigned int V_61 ,
unsigned long V_1 )
{
struct V_15 * V_16 ;
struct V_62 * V_63 ;
struct V_23 * V_27 ;
void T_6 * V_64 ;
int V_18 = - V_65 ;
T_4 V_66 = 0 ;
V_16 = V_13 -> V_17 ;
V_64 = ( void T_6 * ) V_1 ;
F_10 ( L_4 , V_28 , V_16 , V_61 ) ;
switch ( V_61 ) {
case V_67 :
F_5 ( & V_16 -> V_20 ) ;
F_37 (holder, &group->notification_list, event_list) {
V_27 = V_63 -> V_27 ;
V_66 += sizeof( struct V_26 ) ;
if ( V_27 -> V_29 )
V_66 += F_11 ( V_27 -> V_29 + 1 ,
sizeof( struct V_26 ) ) ;
}
F_7 ( & V_16 -> V_20 ) ;
V_18 = F_38 ( V_66 , ( int T_6 * ) V_64 ) ;
break;
}
return V_18 ;
}
static int F_39 ( const char T_6 * V_68 , struct V_69 * V_69 , unsigned V_70 )
{
int error ;
error = F_40 ( V_71 , V_68 , V_70 , V_69 ) ;
if ( error )
return error ;
error = F_41 ( V_69 -> V_72 -> V_73 , V_74 ) ;
if ( error )
F_42 ( V_69 ) ;
return error ;
}
static int F_43 ( struct V_75 * V_75 , T_8 * V_76 ,
int * V_77 ,
struct V_78 * V_79 )
{
int V_18 ;
do {
if ( F_44 ( ! F_45 ( V_75 , V_80 ) ) )
return - V_81 ;
F_15 ( V_76 ) ;
V_18 = F_46 ( V_75 , V_79 , * V_77 + 1 ,
& V_79 -> V_37 ) ;
if ( ! V_18 ) {
* V_77 = V_79 -> V_37 ;
F_47 ( & V_79 -> V_82 ) ;
}
F_17 ( V_76 ) ;
} while ( V_18 == - V_49 );
return V_18 ;
}
static struct V_78 * F_48 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_75 * V_75 = & V_16 -> V_56 . V_75 ;
T_8 * V_76 = & V_16 -> V_56 . V_76 ;
struct V_78 * V_79 ;
F_49 ( V_76 ) ;
V_79 = F_50 ( V_75 , V_37 ) ;
if ( V_79 ) {
struct V_83 * V_82 = & V_79 -> V_82 ;
F_47 ( V_82 ) ;
F_51 ( F_52 ( & V_82 -> V_84 ) < 2 ) ;
}
return V_79 ;
}
static struct V_78 * F_53 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_78 * V_79 ;
T_8 * V_76 = & V_16 -> V_56 . V_76 ;
F_15 ( V_76 ) ;
V_79 = F_48 ( V_16 , V_37 ) ;
F_17 ( V_76 ) ;
return V_79 ;
}
static void F_54 ( struct V_15 * V_16 ,
struct V_78 * V_79 )
{
struct V_75 * V_75 = & V_16 -> V_56 . V_75 ;
T_8 * V_76 = & V_16 -> V_56 . V_76 ;
int V_37 = V_79 -> V_37 ;
F_49 ( V_76 ) ;
F_55 ( V_75 , V_37 ) ;
F_56 ( & V_79 -> V_82 ) ;
}
static void F_57 ( struct V_15 * V_16 ,
struct V_78 * V_79 )
{
T_8 * V_76 = & V_16 -> V_56 . V_76 ;
struct V_78 * V_85 = NULL ;
int V_37 ;
F_15 ( V_76 ) ;
V_37 = V_79 -> V_37 ;
if ( V_37 == - 1 ) {
F_58 ( 1 , L_5
L_6 , V_28 , V_79 , V_79 -> V_37 ,
V_79 -> V_82 . V_16 , V_79 -> V_82 . V_86 . V_59 ) ;
goto V_87;
}
V_85 = F_48 ( V_16 , V_37 ) ;
if ( F_44 ( ! V_85 ) ) {
F_58 ( 1 , L_5
L_6 , V_28 , V_79 , V_79 -> V_37 ,
V_79 -> V_82 . V_16 , V_79 -> V_82 . V_86 . V_59 ) ;
goto V_87;
}
if ( F_44 ( V_85 != V_79 ) ) {
F_58 ( 1 , L_7
L_8
L_9 ,
V_28 , V_79 , V_79 -> V_37 , V_79 -> V_82 . V_16 ,
V_79 -> V_82 . V_86 . V_59 , V_85 , V_85 -> V_37 ,
V_85 -> V_82 . V_16 ,
V_85 -> V_82 . V_86 . V_59 ) ;
goto V_87;
}
if ( F_44 ( F_52 ( & V_79 -> V_82 . V_84 ) < 3 ) ) {
F_59 ( V_88 L_5
L_6 , V_28 , V_79 , V_79 -> V_37 ,
V_79 -> V_82 . V_16 , V_79 -> V_82 . V_86 . V_59 ) ;
F_60 () ;
}
F_54 ( V_16 , V_79 ) ;
V_87:
if ( V_85 )
F_56 ( & V_85 -> V_82 ) ;
V_79 -> V_37 = - 1 ;
F_17 ( V_76 ) ;
}
void F_61 ( struct V_83 * V_82 ,
struct V_15 * V_16 )
{
struct V_78 * V_79 ;
struct V_23 * V_89 , * V_90 ;
struct V_34 * V_91 ;
struct V_32 * V_92 ;
int V_18 ;
V_89 = F_62 ( NULL , V_3 , NULL ,
V_93 , NULL , 0 ,
V_94 ) ;
if ( ! V_89 )
return;
V_79 = F_18 ( V_82 , struct V_78 , V_82 ) ;
V_91 = F_63 ( V_95 , V_94 ) ;
if ( F_44 ( ! V_91 ) )
goto V_96;
V_92 = & V_91 -> V_38 ;
V_92 -> V_16 = V_16 ;
V_91 -> V_37 = V_79 -> V_37 ;
V_90 = F_64 ( V_16 , V_89 , V_92 , NULL ) ;
if ( V_90 ) {
if ( F_26 ( V_90 ) )
V_18 = F_25 ( V_90 ) ;
else
F_27 ( V_90 ) ;
F_19 ( V_92 ) ;
}
V_96:
F_27 ( V_89 ) ;
F_57 ( V_16 , V_79 ) ;
F_65 ( & V_16 -> V_56 . V_97 -> V_98 ) ;
}
static void F_66 ( struct V_83 * V_82 )
{
struct V_78 * V_79 ;
V_79 = F_18 ( V_82 , struct V_78 , V_82 ) ;
F_67 ( V_99 , V_79 ) ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_59 * V_59 ,
T_2 V_1 )
{
struct V_83 * V_82 ;
struct V_78 * V_79 ;
T_1 V_100 , V_101 ;
T_1 V_2 ;
int V_102 = ( V_1 & V_103 ) ;
int V_18 ;
V_2 = F_1 ( V_1 ) ;
if ( F_44 ( ! ( V_2 & V_6 ) ) )
return - V_30 ;
V_82 = F_69 ( V_16 , V_59 ) ;
if ( ! V_82 )
return - V_104 ;
V_79 = F_18 ( V_82 , struct V_78 , V_82 ) ;
F_15 ( & V_82 -> V_36 ) ;
V_100 = V_82 -> V_2 ;
if ( V_102 )
F_70 ( V_82 , ( V_82 -> V_2 | V_2 ) ) ;
else
F_70 ( V_82 , V_2 ) ;
V_101 = V_82 -> V_2 ;
F_17 ( & V_82 -> V_36 ) ;
if ( V_100 != V_101 ) {
int V_105 = ( V_100 & ~ V_101 ) ;
int V_106 = ( V_101 & ~ V_59 -> V_107 ) ;
if ( V_105 || V_106 )
F_71 ( V_59 ) ;
}
V_18 = V_79 -> V_37 ;
F_56 ( V_82 ) ;
return V_18 ;
}
static int F_72 ( struct V_15 * V_16 ,
struct V_59 * V_59 ,
T_2 V_1 )
{
struct V_78 * V_108 ;
T_1 V_2 ;
int V_18 ;
struct V_75 * V_75 = & V_16 -> V_56 . V_75 ;
T_8 * V_76 = & V_16 -> V_56 . V_76 ;
V_2 = F_1 ( V_1 ) ;
if ( F_44 ( ! ( V_2 & V_6 ) ) )
return - V_30 ;
V_108 = F_63 ( V_99 , V_80 ) ;
if ( F_44 ( ! V_108 ) )
return - V_81 ;
F_73 ( & V_108 -> V_82 , F_66 ) ;
V_108 -> V_82 . V_2 = V_2 ;
V_108 -> V_37 = - 1 ;
V_18 = - V_109 ;
if ( F_52 ( & V_16 -> V_56 . V_97 -> V_98 ) >= V_110 )
goto V_111;
V_18 = F_43 ( V_75 , V_76 , & V_16 -> V_56 . V_77 ,
V_108 ) ;
if ( V_18 )
goto V_111;
V_18 = F_74 ( & V_108 -> V_82 , V_16 , V_59 , NULL , 0 ) ;
if ( V_18 ) {
F_57 ( V_16 , V_108 ) ;
goto V_111;
}
F_75 ( & V_16 -> V_56 . V_97 -> V_98 ) ;
V_18 = V_108 -> V_37 ;
V_111:
F_56 ( & V_108 -> V_82 ) ;
return V_18 ;
}
static int F_76 ( struct V_15 * V_16 , struct V_59 * V_59 , T_2 V_1 )
{
int V_18 = 0 ;
V_112:
V_18 = F_68 ( V_16 , V_59 , V_1 ) ;
if ( V_18 == - V_104 )
V_18 = F_72 ( V_16 , V_59 , V_1 ) ;
if ( V_18 == - V_113 )
goto V_112;
return V_18 ;
}
static struct V_15 * F_77 ( unsigned int V_114 )
{
struct V_15 * V_16 ;
V_16 = F_78 ( & V_115 ) ;
if ( F_26 ( V_16 ) )
return V_16 ;
V_16 -> V_114 = V_114 ;
F_79 ( & V_16 -> V_56 . V_76 ) ;
F_80 ( & V_16 -> V_56 . V_75 ) ;
V_16 -> V_56 . V_77 = 0 ;
V_16 -> V_56 . V_57 = NULL ;
V_16 -> V_56 . V_97 = F_81 () ;
if ( F_82 ( & V_16 -> V_56 . V_97 -> V_116 ) >
V_117 ) {
F_35 ( V_16 ) ;
return F_12 ( - V_118 ) ;
}
return V_16 ;
}
static int T_9 F_83 ( void )
{
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
F_84 ( V_141 != V_142 ) ;
F_84 ( V_10 != V_5 ) ;
F_84 ( V_12 != V_143 ) ;
F_84 ( V_11 != V_3 ) ;
F_84 ( V_8 != V_144 ) ;
F_84 ( V_9 != V_145 ) ;
F_84 ( V_7 != V_146 ) ;
F_51 ( F_85 ( V_147 ) != 21 ) ;
V_99 = F_86 ( V_78 , V_148 ) ;
V_95 = F_86 ( V_34 , V_148 ) ;
V_149 = 16384 ;
V_117 = 128 ;
V_110 = 8192 ;
return 0 ;
}
