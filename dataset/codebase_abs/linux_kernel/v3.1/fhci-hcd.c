void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_1 , V_3 ) ;
F_3 ( & V_2 -> V_4 -> V_5 , 0 ) ;
F_3 ( & V_2 -> V_6 -> V_7 , 0 ) ;
F_4 ( & V_2 -> V_6 -> V_8 , V_9 ) ;
F_2 ( V_2 , L_2 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_1 , V_3 ) ;
F_6 ( & V_2 -> V_6 -> V_8 , V_9 ) ;
F_7 ( V_2 -> V_10 ) ;
F_2 ( V_2 , L_2 , V_3 ) ;
}
T_1 F_8 ( struct V_11 * V_12 )
{
return F_9 ( F_10 ( & V_12 -> V_2 -> V_6 -> V_7 ) / 12 ) ;
}
static T_2 F_11 ( struct V_11 * V_12 ,
enum V_13 V_14 ,
T_2 V_15 )
{
T_2 V_16 ;
V_16 = F_12 ( V_12 , V_14 , V_15 ) ;
if ( V_16 )
return V_16 ;
F_13 ( V_12 , V_12 -> V_17 , V_14 ) ;
return 0 ;
}
void F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_12 -> V_18 == 1 ) {
F_15 ( F_16 ( V_2 ) -> V_19 ) ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_20 , 0xffff ) ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_21 , V_12 -> V_22 ) ;
F_15 ( V_2 -> V_10 -> V_19 ) ;
} else if ( V_12 -> V_18 > 1 )
F_17 ( V_2 , L_3 ) ;
V_12 -> V_18 -- ;
}
void F_18 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_12 -> V_18 == 0 ) {
F_19 ( V_2 -> V_10 -> V_19 ) ;
F_19 ( F_16 ( V_2 ) -> V_19 ) ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_21 , 0 ) ;
}
V_12 -> V_18 ++ ;
}
static T_2 F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_20 , 0xffff ) ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_21 , V_12 -> V_22 ) ;
F_4 ( & V_12 -> V_2 -> V_6 -> V_8 , V_24 ) ;
F_21 ( 100 ) ;
return 0 ;
}
static T_2 F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_18 ( V_12 ) ;
F_23 ( V_2 ) ;
if ( V_12 -> V_25 == V_26 ||
V_12 -> V_25 == V_27 )
F_24 ( V_2 ) ;
F_6 ( & V_12 -> V_2 -> V_6 -> V_8 , V_24 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
T_3 V_28 = 0 ;
if ( ! F_26 ( V_2 -> V_29 [ V_30 ] ) )
return - 1 ;
if ( F_26 ( V_2 -> V_29 [ V_31 ] ) )
V_28 |= 0x2 ;
if ( F_26 ( V_2 -> V_29 [ V_32 ] ) )
V_28 |= 0x1 ;
return V_28 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_33 * V_33 ;
struct V_33 * V_34 ;
struct V_35 * V_35 ;
struct V_35 * V_36 ;
F_28 (ed, next_ed, &fhci->empty_eds, node) {
F_29 ( & V_33 -> V_37 ) ;
F_30 ( V_33 ) ;
}
F_28 (td, next_td, &fhci->empty_tds, node) {
F_29 ( & V_35 -> V_37 ) ;
F_30 ( V_35 ) ;
}
F_30 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
F_30 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_40 ;
V_2 -> V_39 = F_32 ( sizeof( * V_2 -> V_39 ) , V_41 ) ;
if ( ! V_2 -> V_39 )
goto V_42;
F_33 ( & V_2 -> V_39 -> V_43 ) ;
F_33 ( & V_2 -> V_39 -> V_44 ) ;
F_33 ( & V_2 -> V_39 -> V_45 ) ;
F_33 ( & V_2 -> V_39 -> V_46 ) ;
F_33 ( & V_2 -> V_39 -> V_47 ) ;
V_2 -> V_38 = F_32 ( sizeof( * V_2 -> V_38 ) , V_41 ) ;
if ( ! V_2 -> V_38 )
goto V_42;
F_33 ( & V_2 -> V_48 ) ;
F_33 ( & V_2 -> V_49 ) ;
V_50 . V_51 = ( unsigned long ) V_2 ;
V_2 -> V_52 = & V_50 ;
for ( V_40 = 0 ; V_40 < V_53 ; V_40 ++ ) {
struct V_35 * V_35 ;
V_35 = F_34 ( sizeof( * V_35 ) , V_41 ) ;
if ( ! V_35 )
goto V_42;
F_35 ( V_2 , V_35 ) ;
}
for ( V_40 = 0 ; V_40 < V_54 ; V_40 ++ ) {
struct V_33 * V_33 ;
V_33 = F_34 ( sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
goto V_42;
F_36 ( V_2 , V_33 ) ;
}
V_2 -> V_55 = 0 ;
return 0 ;
V_42:
F_27 ( V_2 ) ;
return - V_56 ;
}
static void F_37 ( void * V_57 )
{
struct V_11 * V_12 = V_57 ;
struct V_1 * V_2 ;
if ( V_12 ) {
V_2 = V_12 -> V_2 ;
F_38 ( V_2 , V_58 ) ;
F_39 ( V_12 ) ;
F_30 ( V_12 -> V_59 ) ;
F_30 ( V_12 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_23 ;
F_41 ( V_12 -> V_2 -> V_4 , 0 , V_60 ) ;
V_12 -> V_25 = V_61 ;
V_12 -> V_62 = V_63 ;
V_12 -> V_64 = V_65 ;
V_12 -> V_59 = F_32 ( sizeof( * V_12 -> V_59 ) , V_41 ) ;
if ( ! V_12 -> V_59 ) {
F_37 ( V_12 ) ;
return - V_56 ;
}
F_33 ( & V_12 -> V_59 -> V_66 ) ;
F_3 ( & V_2 -> V_4 -> V_5 , 0 ) ;
F_42 ( & V_2 -> V_4 -> V_67 , 0 ) ;
V_12 -> V_22 = ( V_68 |
V_69 |
V_70 |
V_71 | V_72 | V_73 ) ;
F_43 ( & V_12 -> V_2 -> V_6 -> V_8 , V_74 | V_24 ) ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_21 , 0 ) ;
F_3 ( & V_12 -> V_2 -> V_6 -> V_20 , 0xffff ) ;
if ( F_11 ( V_12 , V_75 , V_76 ) != 0 ) {
F_37 ( V_12 ) ;
return - V_77 ;
}
return 0 ;
}
static struct V_11 * F_44 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_32 ( sizeof( * V_12 ) , V_41 ) ;
if ( ! V_12 ) {
F_45 ( V_2 , L_4 ) ;
return NULL ;
}
V_12 -> V_2 = V_2 ;
V_12 -> V_39 = V_2 -> V_39 ;
V_12 -> V_38 = V_2 -> V_38 ;
V_12 -> V_78 = V_79 ;
return V_12 ;
}
static int F_46 ( struct V_80 * V_81 )
{
int V_82 ;
struct V_1 * V_2 = F_47 ( V_81 ) ;
V_82 = F_31 ( V_2 ) ;
if ( V_82 ) {
F_45 ( V_2 , L_5 ) ;
goto V_42;
}
V_2 -> V_23 = F_44 ( V_2 ) ;
if ( ! V_2 -> V_23 ) {
F_45 ( V_2 , L_6 ) ;
V_82 = - V_56 ;
goto V_42;
}
V_82 = F_40 ( V_2 ) ;
if ( V_82 ) {
F_45 ( V_2 , L_7 ) ;
goto V_42;
}
F_48 ( & V_2 -> V_83 ) ;
V_2 -> V_38 -> V_84 = 1 ;
V_2 -> V_38 -> V_85 . V_86 = 0 ;
V_2 -> V_38 -> V_85 . V_87 = 0 ;
V_2 -> V_38 -> V_88 . V_89 = 0 ;
V_2 -> V_38 -> V_88 . V_90 = 0 ;
V_81 -> V_91 = V_92 ;
F_20 ( V_2 ) ;
return 0 ;
V_42:
F_27 ( V_2 ) ;
return V_82 ;
}
static void F_49 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_47 ( V_81 ) ;
F_18 ( V_2 -> V_23 ) ;
F_22 ( V_2 ) ;
F_37 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
F_27 ( V_2 ) ;
}
static int F_50 ( struct V_80 * V_81 , struct V_93 * V_93 ,
T_4 V_94 )
{
struct V_1 * V_2 = F_47 ( V_81 ) ;
T_2 V_95 = V_93 -> V_95 ;
int V_82 ;
int V_40 ;
int V_96 = 0 ;
struct V_97 * V_97 ;
unsigned long V_98 ;
switch ( F_51 ( V_95 ) ) {
case V_99 :
V_96 = 2 ;
case V_100 :
V_96 += V_93 -> V_101 / 4096 ;
if ( ( V_93 -> V_101 % 4096 ) != 0 )
V_96 ++ ;
if ( V_96 == 0 )
V_96 ++ ;
else if ( ( V_93 -> V_102 & V_103 ) != 0
&& ( V_93 -> V_101
% F_52 ( V_93 -> V_104 , V_95 ,
F_53 ( V_95 ) ) ) != 0 )
V_96 ++ ;
break;
case V_105 :
V_96 = V_93 -> V_106 ;
if ( V_96 <= 0 )
return - V_77 ;
for ( V_40 = 0 ; V_40 < V_93 -> V_106 ; V_40 ++ ) {
V_93 -> V_107 [ V_40 ] . V_108 = 0 ;
V_93 -> V_107 [ V_40 ] . V_109 = ( T_2 ) ( - V_110 ) ;
}
break;
case V_111 :
V_96 = 1 ;
}
V_97 = F_32 ( sizeof( * V_97 ) , V_94 ) ;
if ( ! V_97 )
return - V_56 ;
V_97 -> V_112 = F_54 ( V_96 , sizeof( * V_97 -> V_112 ) , V_94 ) ;
if ( ! V_97 -> V_112 ) {
F_30 ( V_97 ) ;
return - V_56 ;
}
F_55 ( & V_2 -> V_83 , V_98 ) ;
V_82 = F_56 ( V_81 , V_93 ) ;
if ( V_82 )
goto V_42;
V_97 -> V_113 = V_96 ;
V_93 -> V_109 = - V_114 ;
V_93 -> V_108 = 0 ;
V_93 -> V_115 = 0 ;
V_93 -> V_116 = V_97 ;
F_57 ( V_2 , V_93 ) ;
V_42:
if ( V_82 ) {
F_30 ( V_97 -> V_112 ) ;
F_30 ( V_97 ) ;
}
F_58 ( & V_2 -> V_83 , V_98 ) ;
return V_82 ;
}
static int F_59 ( struct V_80 * V_81 , struct V_93 * V_93 , int V_109 )
{
struct V_1 * V_2 = F_47 ( V_81 ) ;
struct V_11 * V_12 = V_2 -> V_23 ;
int V_82 = - V_77 ;
unsigned long V_98 ;
if ( ! V_93 || ! V_93 -> V_104 || ! V_93 -> V_104 -> V_117 )
goto V_118;
F_55 ( & V_2 -> V_83 , V_98 ) ;
V_82 = F_60 ( V_81 , V_93 , V_109 ) ;
if ( V_82 )
goto V_119;
if ( V_12 -> V_25 != V_61 ) {
struct V_97 * V_97 ;
V_97 = V_93 -> V_116 ;
if ( ! V_97 || ( V_97 -> V_91 == V_120 ) )
goto V_119;
V_97 -> V_91 = V_120 ;
V_97 -> V_33 -> V_91 = V_121 ;
} else {
F_61 ( V_2 , V_93 ) ;
}
V_119:
F_58 ( & V_2 -> V_83 , V_98 ) ;
V_118:
return V_82 ;
}
static void F_62 ( struct V_80 * V_81 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 ;
struct V_33 * V_33 ;
unsigned long V_98 ;
V_2 = F_47 ( V_81 ) ;
F_55 ( & V_2 -> V_83 , V_98 ) ;
V_33 = V_123 -> V_116 ;
if ( V_33 ) {
while ( V_33 -> V_124 != NULL ) {
struct V_35 * V_35 = F_63 ( V_33 ) ;
F_61 ( V_2 , V_35 -> V_93 ) ;
}
F_36 ( V_2 , V_33 ) ;
V_123 -> V_116 = NULL ;
}
F_58 ( & V_2 -> V_83 , V_98 ) ;
}
static int F_64 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_47 ( V_81 ) ;
return F_65 ( V_2 ) ;
}
static int T_5 F_66 ( struct V_125 * V_126 )
{
struct V_127 * V_104 = & V_126 -> V_104 ;
struct V_128 * V_37 = V_104 -> V_129 ;
struct V_80 * V_81 ;
struct V_1 * V_2 ;
struct V_130 V_131 ;
unsigned long V_132 ;
unsigned int V_133 ;
const char * V_134 ;
const T_2 * V_135 ;
int V_96 ;
int V_82 ;
int V_40 ;
int V_136 ;
if ( F_67 () )
return - V_137 ;
V_134 = F_68 ( V_37 , L_8 , NULL ) ;
if ( V_134 && strcmp ( V_134 , L_9 ) )
return - V_137 ;
V_81 = F_69 ( & V_138 , V_104 , F_70 ( V_104 ) ) ;
if ( ! V_81 ) {
F_71 ( V_104 , L_10 ) ;
return - V_56 ;
}
V_2 = F_47 ( V_81 ) ;
V_81 -> V_139 . V_140 = V_104 ;
F_72 ( V_104 , V_81 ) ;
V_135 = F_68 ( V_37 , L_11 , & V_96 ) ;
if ( V_135 && V_96 == sizeof( * V_135 ) )
V_81 -> V_141 = * V_135 ;
V_82 = F_73 ( V_37 , 0 , & V_131 ) ;
if ( V_82 ) {
F_71 ( V_104 , L_12 ) ;
goto V_142;
}
V_81 -> V_6 = F_74 ( V_131 . V_143 , F_75 ( & V_131 ) ) ;
if ( ! V_81 -> V_6 ) {
F_71 ( V_104 , L_13 ) ;
V_82 = - V_56 ;
goto V_142;
}
V_2 -> V_6 = V_81 -> V_6 ;
V_135 = F_68 ( V_37 , L_14 , & V_96 ) ;
if ( ! V_135 || V_96 < sizeof( * V_135 ) * 4 ) {
F_71 ( V_104 , L_15 ) ;
V_82 = - V_77 ;
goto V_144;
}
V_132 = F_76 ( V_135 [ 2 ] , V_60 ) ;
if ( F_77 ( V_132 ) ) {
F_71 ( V_104 , L_16 ) ;
V_82 = - V_56 ;
goto V_144;
}
V_2 -> V_4 = F_78 ( V_132 ) ;
for ( V_40 = 0 ; V_40 < V_145 ; V_40 ++ ) {
int V_146 ;
enum V_147 V_98 ;
V_146 = F_79 ( V_37 , V_40 , & V_98 ) ;
V_2 -> V_29 [ V_40 ] = V_146 ;
V_2 -> V_148 [ V_40 ] = V_98 & V_149 ;
if ( ! F_80 ( V_146 ) ) {
if ( V_40 < V_150 ) {
F_71 ( V_104 , L_17 ,
V_40 , V_146 ) ;
goto V_151;
} else {
F_81 ( V_104 , L_18
L_19 , V_40 == V_150 ?
L_20 : L_21 ) ;
continue;
}
}
V_82 = F_82 ( V_146 , F_70 ( V_104 ) ) ;
if ( V_82 ) {
F_71 ( V_104 , L_22 , V_40 ) ;
goto V_151;
}
if ( V_40 >= V_150 ) {
V_82 = F_83 ( V_146 , 0 ) ;
if ( V_82 ) {
F_71 ( V_104 , L_23
L_24 , V_40 ) ;
V_40 ++ ;
goto V_151;
}
}
}
for ( V_136 = 0 ; V_136 < V_152 ; V_136 ++ ) {
V_2 -> V_153 [ V_136 ] = F_84 ( V_37 , V_136 ) ;
if ( F_85 ( V_2 -> V_153 [ V_136 ] ) ) {
V_82 = F_86 ( V_2 -> V_153 [ V_136 ] ) ;
F_71 ( V_104 , L_25 , V_136 , V_82 ) ;
goto V_154;
}
}
V_2 -> V_10 = F_87 () ;
if ( F_85 ( V_2 -> V_10 ) ) {
V_82 = F_86 ( V_2 -> V_10 ) ;
F_71 ( V_104 , L_26 , V_82 ) ;
goto V_155;
}
V_82 = F_88 ( V_2 -> V_10 -> V_19 , V_156 ,
V_157 , L_27 , V_81 ) ;
if ( V_82 ) {
F_71 ( V_104 , L_28 ) ;
goto V_158;
}
V_133 = F_89 ( V_37 , 0 ) ;
if ( V_133 == V_159 ) {
F_71 ( V_104 , L_29 ) ;
V_82 = - V_77 ;
goto V_160;
}
V_134 = F_68 ( V_37 , L_30 , NULL ) ;
if ( V_134 ) {
V_2 -> V_161 = F_90 ( V_134 ) ;
if ( V_2 -> V_161 == V_162 ) {
F_71 ( V_104 , L_31 ) ;
V_82 = - V_77 ;
goto V_163;
}
}
V_134 = F_68 ( V_37 , L_32 , NULL ) ;
if ( V_134 ) {
V_2 -> V_164 = F_90 ( V_134 ) ;
if ( V_2 -> V_164 == V_162 ) {
F_71 ( V_104 , L_33 ) ;
V_82 = - V_77 ;
goto V_163;
}
}
if ( V_2 -> V_161 == V_165 &&
V_2 -> V_164 == V_165 ) {
F_71 ( V_104 , L_34 ) ;
V_82 = - V_77 ;
goto V_163;
}
F_81 ( V_104 , L_35 , V_81 -> V_6 , V_133 ) ;
F_38 ( V_2 , V_58 ) ;
if ( V_2 -> V_161 != V_165 ) {
F_38 ( V_2 , V_26 ) ;
F_91 ( V_2 -> V_161 , V_166 ) ;
} else {
F_38 ( V_2 , V_27 ) ;
F_91 ( V_2 -> V_164 , V_166 >> 3 ) ;
}
F_3 ( & V_2 -> V_6 -> V_20 , 0xffff ) ;
F_3 ( & V_2 -> V_6 -> V_21 , 0 ) ;
V_82 = F_92 ( V_81 , V_133 , V_157 ) ;
if ( V_82 < 0 )
goto V_167;
F_93 ( V_2 ) ;
return 0 ;
V_167:
V_163:
F_94 ( V_133 ) ;
V_160:
F_95 ( V_2 -> V_10 -> V_19 , V_81 ) ;
V_158:
F_96 ( V_2 -> V_10 ) ;
V_155:
V_154:
while ( -- V_136 >= 0 )
F_97 ( V_2 -> V_153 [ V_136 ] ) ;
V_151:
while ( -- V_40 >= 0 ) {
if ( F_80 ( V_2 -> V_29 [ V_40 ] ) )
F_98 ( V_2 -> V_29 [ V_40 ] ) ;
}
F_99 ( V_132 ) ;
V_144:
F_100 ( V_81 -> V_6 ) ;
V_142:
F_101 ( V_81 ) ;
return V_82 ;
}
static int T_6 F_102 ( struct V_127 * V_104 )
{
struct V_80 * V_81 = F_103 ( V_104 ) ;
struct V_1 * V_2 = F_47 ( V_81 ) ;
int V_40 ;
int V_136 ;
F_104 ( V_81 ) ;
F_95 ( V_2 -> V_10 -> V_19 , V_81 ) ;
F_96 ( V_2 -> V_10 ) ;
F_99 ( F_105 ( V_2 -> V_4 ) ) ;
for ( V_40 = 0 ; V_40 < V_145 ; V_40 ++ ) {
if ( ! F_80 ( V_2 -> V_29 [ V_40 ] ) )
continue;
F_98 ( V_2 -> V_29 [ V_40 ] ) ;
}
for ( V_136 = 0 ; V_136 < V_152 ; V_136 ++ )
F_97 ( V_2 -> V_153 [ V_136 ] ) ;
F_106 ( V_2 ) ;
F_101 ( V_81 ) ;
return 0 ;
}
static int T_6 F_107 ( struct V_125 * V_126 )
{
return F_102 ( & V_126 -> V_104 ) ;
}
static int T_7 F_108 ( void )
{
return F_109 ( & V_168 ) ;
}
static void T_8 F_110 ( void )
{
F_111 ( & V_168 ) ;
}
