static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << V_5 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 + ( V_3 << V_5 ) ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
T_2 V_6 ;
V_6 = F_1 ( V_2 , V_3 ) << 8 ;
V_6 |= F_1 ( V_2 , V_3 + 1 ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_6 )
{
F_3 ( V_2 , V_3 , V_6 >> 8 ) ;
F_3 ( V_2 , V_3 + 1 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_7 , T_1 * V_8 , int V_9 )
{
T_2 V_3 = V_10 + ( V_7 & V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ , V_3 ++ ) {
if ( F_8 ( V_3 > V_13 ) )
V_3 = V_10 ;
* V_8 ++ = F_1 ( V_2 , V_3 ) ;
}
}
static void F_9 ( struct V_1 * V_2 ,
T_2 V_7 , T_1 * V_8 , int V_9 )
{
T_2 V_3 = V_14 + ( V_7 & V_15 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ , V_3 ++ ) {
if ( F_8 ( V_3 > V_16 ) )
V_3 = V_14 ;
F_3 ( V_2 , V_3 , * V_8 ++ ) ;
}
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned long V_17 ;
T_1 V_6 ;
F_11 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
V_6 = F_1 ( V_2 , V_20 ) ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
return V_6 ;
}
static void F_14 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_6 )
{
unsigned long V_17 ;
F_11 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
F_3 ( V_2 , V_20 , V_6 ) ;
F_12 () ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
}
static T_2 F_15 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned long V_17 ;
T_2 V_6 ;
F_11 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
V_6 = F_1 ( V_2 , V_20 ) << 8 ;
V_6 |= F_1 ( V_2 , V_20 ) ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
return V_6 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_6 )
{
unsigned long V_17 ;
F_11 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
F_3 ( V_2 , V_20 , V_6 >> 8 ) ;
F_3 ( V_2 , V_20 , V_6 ) ;
F_12 () ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_2 V_7 , T_1 * V_8 , int V_9 )
{
T_2 V_3 = V_10 + ( V_7 & V_11 ) ;
unsigned long V_17 ;
int V_12 ;
F_11 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ , V_3 ++ ) {
if ( F_8 ( V_3 > V_13 ) ) {
V_3 = V_10 ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
}
* V_8 ++ = F_1 ( V_2 , V_20 ) ;
}
F_12 () ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
T_2 V_7 , T_1 * V_8 , int V_9 )
{
T_2 V_3 = V_14 + ( V_7 & V_15 ) ;
unsigned long V_17 ;
int V_12 ;
F_11 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ , V_3 ++ ) {
if ( F_8 ( V_3 > V_16 ) ) {
V_3 = V_14 ;
F_6 ( V_2 , V_19 , V_3 ) ;
F_12 () ;
}
F_3 ( V_2 , V_20 , * V_8 ++ ) ;
}
F_12 () ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_21 )
{
unsigned long V_22 = V_23 + F_20 ( 100 ) ;
F_21 ( V_2 , V_24 , V_21 ) ;
F_12 () ;
while ( F_22 ( V_2 , V_24 ) != 0 ) {
if ( F_23 ( V_23 , V_22 ) )
return - V_25 ;
F_24 () ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ )
F_21 ( V_2 , V_29 + V_12 , V_27 -> V_30 [ V_12 ] ) ;
F_12 () ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_31 , V_32 ) ;
F_12 () ;
F_27 ( 5 ) ;
F_3 ( V_2 , V_31 , V_2 -> V_33 ?
V_34 | V_35 | V_36 :
V_34 ) ;
F_12 () ;
F_21 ( V_2 , V_37 , 0 ) ;
F_25 ( V_2 ) ;
F_21 ( V_2 , V_38 , 0x03 ) ;
F_21 ( V_2 , V_39 , 0x03 ) ;
F_12 () ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_40 , V_2 -> V_41 ?
V_42 : V_43 ) ;
F_12 () ;
F_19 ( V_2 , V_44 ) ;
F_21 ( V_2 , V_37 , V_45 ) ;
F_12 () ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_37 , 0 ) ;
F_12 () ;
F_19 ( V_2 , V_46 ) ;
}
static void F_30 ( struct V_26 * V_27 ,
struct V_47 * V_48 )
{
F_31 ( V_48 -> V_49 , V_50 , sizeof( V_48 -> V_49 ) ) ;
F_31 ( V_48 -> V_51 , V_52 , sizeof( V_48 -> V_51 ) ) ;
F_31 ( V_48 -> V_53 , F_32 ( V_27 -> V_54 . V_55 ) ,
sizeof( V_48 -> V_53 ) ) ;
}
static T_3 F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
if ( F_35 ( V_2 -> V_56 ) )
return ! ! F_36 ( V_2 -> V_56 ) ;
return 1 ;
}
static T_3 F_37 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
return V_2 -> V_57 ;
}
static void F_38 ( struct V_26 * V_27 , T_3 V_58 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
V_2 -> V_57 = V_58 ;
}
static int F_39 ( struct V_26 * V_27 )
{
return V_59 + V_60 ;
}
static void F_40 ( struct V_26 * V_27 ,
struct V_61 * V_62 , void * V_63 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
T_1 * V_8 = V_63 ;
T_2 V_12 ;
V_62 -> V_51 = 1 ;
for ( V_12 = 0 ; V_12 < V_59 ; V_12 ++ )
* V_8 ++ = F_22 ( V_2 , V_64 + V_12 ) ;
for ( V_12 = 0 ; V_12 < V_60 ; V_12 ++ )
* V_8 ++ = F_22 ( V_2 , V_65 + V_12 ) ;
}
static void F_41 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
F_42 ( V_27 ) ;
F_26 ( V_2 ) ;
F_28 ( V_2 ) ;
V_27 -> V_66 . V_67 ++ ;
V_27 -> V_68 = V_23 ;
F_43 ( V_27 ) ;
}
static int F_44 ( struct V_69 * V_70 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
T_2 V_7 ;
F_42 ( V_27 ) ;
V_7 = F_45 ( V_2 , V_71 ) ;
F_46 ( V_2 , V_7 , V_70 -> V_6 , V_70 -> V_9 ) ;
F_47 ( V_2 , V_71 , V_7 + V_70 -> V_9 ) ;
F_12 () ;
V_27 -> V_66 . V_72 += V_70 -> V_9 ;
V_27 -> V_66 . V_73 ++ ;
F_48 ( V_70 ) ;
F_19 ( V_2 , V_74 ) ;
return V_75 ;
}
static int F_49 ( struct V_76 * V_77 , int V_78 )
{
struct V_1 * V_2 = F_50 ( V_77 , struct V_1 , V_77 ) ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_69 * V_70 ;
int V_79 ;
T_2 V_80 ;
T_2 V_7 ;
T_1 V_81 [ 2 ] ;
for ( V_79 = 0 ; V_79 < V_78 ; V_79 ++ ) {
T_2 V_82 = F_45 ( V_2 , V_83 ) ;
if ( V_82 == 0 )
break;
V_7 = F_45 ( V_2 , V_84 ) ;
F_51 ( V_2 , V_7 , V_81 , 2 ) ;
V_80 = F_52 ( V_81 ) - 2 ;
V_70 = F_53 ( V_27 , V_80 ) ;
if ( F_8 ( ! V_70 ) ) {
F_47 ( V_2 , V_84 ,
V_7 + V_82 ) ;
F_19 ( V_2 , V_85 ) ;
V_27 -> V_66 . V_86 ++ ;
return - V_87 ;
}
F_54 ( V_70 , V_80 ) ;
F_51 ( V_2 , V_7 + 2 , V_70 -> V_6 , V_80 ) ;
F_47 ( V_2 , V_84 , V_7 + 2 + V_80 ) ;
F_12 () ;
F_19 ( V_2 , V_85 ) ;
V_70 -> V_88 = F_55 ( V_70 , V_27 ) ;
F_56 ( V_70 ) ;
V_27 -> V_66 . V_89 ++ ;
V_27 -> V_66 . V_90 += V_80 ;
}
if ( V_79 < V_78 ) {
F_21 ( V_2 , V_37 , V_45 ) ;
F_12 () ;
F_57 ( V_77 ) ;
}
return V_79 ;
}
static T_4 F_58 ( int V_91 , void * V_92 )
{
struct V_26 * V_27 = V_92 ;
struct V_1 * V_2 = F_34 ( V_27 ) ;
int V_93 = F_22 ( V_2 , V_94 ) ;
if ( ! V_93 )
return V_95 ;
F_21 ( V_2 , V_94 , V_93 ) ;
F_12 () ;
if ( V_93 & V_96 ) {
F_59 ( V_2 , V_97 , V_27 , L_1 ) ;
F_43 ( V_27 ) ;
}
if ( V_93 & V_98 ) {
if ( F_60 ( & V_2 -> V_77 ) ) {
F_21 ( V_2 , V_37 , 0 ) ;
F_12 () ;
F_61 ( & V_2 -> V_77 ) ;
}
}
return V_99 ;
}
static T_4 F_62 ( int V_91 , void * V_92 )
{
struct V_26 * V_27 = V_92 ;
struct V_1 * V_2 = F_34 ( V_27 ) ;
if ( F_63 ( V_27 ) ) {
if ( F_36 ( V_2 -> V_56 ) != 0 ) {
F_64 ( V_2 , V_100 , V_27 , L_2 ) ;
F_65 ( V_27 ) ;
} else {
F_64 ( V_2 , V_100 , V_27 , L_3 ) ;
F_66 ( V_27 ) ;
}
}
return V_99 ;
}
static void F_67 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
bool V_101 = ( V_27 -> V_17 & V_102 ) != 0 ;
if ( V_2 -> V_41 != V_101 ) {
V_2 -> V_41 = V_101 ;
F_28 ( V_2 ) ;
}
}
static int F_68 ( struct V_26 * V_27 , void * V_3 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
struct V_103 * V_104 = V_3 ;
if ( ! F_69 ( V_104 -> V_105 ) )
return - V_106 ;
memcpy ( V_27 -> V_30 , V_104 -> V_105 , V_28 ) ;
V_27 -> V_107 &= ~ V_108 ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
F_64 ( V_2 , V_109 , V_27 , L_4 ) ;
if ( ! F_69 ( V_27 -> V_30 ) )
return - V_110 ;
F_28 ( V_2 ) ;
F_71 ( & V_2 -> V_77 ) ;
F_72 ( V_27 ) ;
if ( ! F_35 ( V_2 -> V_56 ) ||
F_36 ( V_2 -> V_56 ) != 0 )
F_65 ( V_27 ) ;
return 0 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
F_64 ( V_2 , V_111 , V_27 , L_5 ) ;
F_29 ( V_2 ) ;
F_66 ( V_27 ) ;
F_42 ( V_27 ) ;
F_74 ( & V_2 -> V_77 ) ;
return 0 ;
}
static int T_5 F_75 ( struct V_112 * V_113 )
{
struct V_114 * V_6 = V_113 -> V_54 . V_115 ;
struct V_26 * V_27 = F_76 ( V_113 ) ;
struct V_1 * V_2 = F_34 ( V_27 ) ;
const char * V_116 = F_77 ( V_27 ) ;
struct V_117 * V_118 ;
int V_119 ;
int V_91 ;
int V_120 ;
if ( V_6 && F_69 ( V_6 -> V_121 ) ) {
memcpy ( V_27 -> V_30 , V_6 -> V_121 , V_28 ) ;
} else {
F_78 ( V_27 ) ;
}
V_118 = F_79 ( V_113 , V_122 , 0 ) ;
if ( ! V_118 )
return - V_123 ;
V_119 = F_80 ( V_118 ) ;
if ( ! F_81 ( & V_113 -> V_54 , V_118 -> V_124 , V_119 , V_116 ) )
return - V_125 ;
V_2 -> V_4 = F_82 ( & V_113 -> V_54 , V_118 -> V_124 , V_119 ) ;
if ( ! V_2 -> V_4 )
return - V_125 ;
F_83 ( & V_2 -> V_18 ) ;
V_2 -> V_33 = V_119 < V_126 ;
if ( V_2 -> V_33 ) {
V_2 -> V_127 = F_10 ;
V_2 -> V_128 = F_14 ;
V_2 -> V_129 = F_15 ;
V_2 -> V_130 = F_16 ;
V_2 -> V_131 = F_17 ;
V_2 -> V_132 = F_18 ;
} else {
V_2 -> V_127 = F_1 ;
V_2 -> V_128 = F_3 ;
V_2 -> V_129 = F_5 ;
V_2 -> V_130 = F_6 ;
V_2 -> V_131 = F_7 ;
V_2 -> V_132 = F_9 ;
}
F_26 ( V_2 ) ;
if ( F_45 ( V_2 , V_133 ) != V_134 )
return - V_135 ;
V_91 = F_84 ( V_113 , 0 ) ;
if ( V_91 < 0 )
return V_91 ;
V_120 = F_85 ( V_91 , F_58 ,
V_136 , V_116 , V_27 ) ;
if ( V_120 < 0 )
return V_120 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_56 = V_6 ? V_6 -> V_56 : - V_110 ;
if ( F_35 ( V_2 -> V_56 ) ) {
char * V_137 = F_86 ( & V_113 -> V_54 , 16 , V_138 ) ;
if ( ! V_137 )
return - V_87 ;
snprintf ( V_137 , 16 , L_6 , V_116 ) ;
V_2 -> V_139 = F_87 ( V_2 -> V_56 ) ;
if ( F_88 ( V_2 -> V_139 , F_62 ,
V_140 | V_141 ,
V_137 , V_2 -> V_27 ) < 0 )
V_2 -> V_56 = - V_110 ;
}
F_89 ( V_27 , L_7 , ( V_142 ) V_118 -> V_124 , V_91 ) ;
return 0 ;
}
static int T_5 F_90 ( struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_26 * V_27 ;
int V_143 ;
V_27 = F_91 ( sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_87 ;
F_92 ( V_27 , & V_113 -> V_54 ) ;
F_93 ( V_113 , V_27 ) ;
V_2 = F_34 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
F_94 ( V_27 ) ;
V_27 -> V_144 = & V_145 ;
V_27 -> V_146 = & V_147 ;
V_27 -> V_148 = V_149 ;
F_95 ( V_27 , & V_2 -> V_77 , F_49 , 16 ) ;
V_27 -> V_150 |= V_151 ;
V_143 = F_96 ( V_27 ) ;
if ( V_143 < 0 )
goto V_152;
V_143 = F_75 ( V_113 ) ;
if ( V_143 < 0 )
goto V_153;
return 0 ;
V_153:
F_97 ( V_27 ) ;
V_152:
F_98 ( V_27 ) ;
F_93 ( V_113 , NULL ) ;
return V_143 ;
}
static int T_6 F_99 ( struct V_112 * V_113 )
{
struct V_26 * V_27 = F_76 ( V_113 ) ;
struct V_1 * V_2 = F_34 ( V_27 ) ;
F_26 ( V_2 ) ;
F_100 ( V_2 -> V_91 , V_27 ) ;
if ( F_35 ( V_2 -> V_56 ) )
F_100 ( V_2 -> V_139 , V_27 ) ;
F_97 ( V_27 ) ;
F_98 ( V_27 ) ;
F_93 ( V_113 , NULL ) ;
return 0 ;
}
static int F_101 ( struct V_154 * V_54 )
{
struct V_112 * V_113 = F_102 ( V_54 ) ;
struct V_26 * V_27 = F_76 ( V_113 ) ;
struct V_1 * V_2 = F_34 ( V_27 ) ;
if ( F_63 ( V_27 ) ) {
F_66 ( V_27 ) ;
F_103 ( V_27 ) ;
F_29 ( V_2 ) ;
}
return 0 ;
}
static int F_104 ( struct V_154 * V_54 )
{
struct V_112 * V_113 = F_102 ( V_54 ) ;
struct V_26 * V_27 = F_76 ( V_113 ) ;
struct V_1 * V_2 = F_34 ( V_27 ) ;
if ( F_63 ( V_27 ) ) {
F_26 ( V_2 ) ;
F_28 ( V_2 ) ;
F_105 ( V_27 ) ;
if ( ! F_35 ( V_2 -> V_56 ) ||
F_36 ( V_2 -> V_56 ) != 0 )
F_65 ( V_27 ) ;
}
return 0 ;
}
