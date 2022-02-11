static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_5 , T_1 V_6 ,
int V_7 , int V_8 )
{
struct V_9 * V_9 ;
struct V_10 V_11 ;
int V_12 ;
V_11 . V_2 = V_2 ;
F_2 ( & V_11 . V_13 ) ;
V_11 . error = 0 ;
if ( ( V_7 & V_14 ) && ! F_3 ( V_15 , & V_2 -> V_16 ) )
V_7 |= V_17 | V_18 ;
V_7 |= V_19 ;
V_9 = F_4 ( V_20 , 1 ) ;
V_9 -> V_21 = V_4 -> V_22 ;
V_9 -> V_23 = V_6 ;
V_12 = ( F_5 ( V_9 , V_5 , V_8 , 0 ) == V_8 ) ;
if ( ! V_12 )
goto V_24;
V_9 -> V_25 = & V_11 ;
V_9 -> V_26 = V_27 ;
V_9 -> V_28 = V_7 ;
if ( F_6 ( V_2 , ( V_7 & V_14 ) ? V_29 : V_30 ) )
F_7 ( V_9 , - V_31 ) ;
else
F_8 ( V_7 , V_9 ) ;
F_9 ( & V_11 . V_13 ) ;
V_12 = F_10 ( V_9 , V_32 ) && V_11 . error == 0 ;
V_24:
F_11 ( V_9 ) ;
return V_12 ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_6 , int V_7 )
{
int V_33 , V_34 , V_12 ;
int V_35 = 0 ;
struct V_5 * V_36 = V_2 -> V_37 ;
F_13 ( F_14 ( & V_2 -> V_38 ) ) ;
F_15 ( ! V_4 -> V_22 ) ;
V_33 = F_16 ( V_4 -> V_22 ) ;
if ( V_33 == 0 )
V_33 = V_39 ;
if ( V_33 != V_39 ) {
V_34 = ( V_33 / V_39 ) - 1 ;
F_13 ( V_34 == 1 || V_34 == 3 || V_34 == 7 ) ;
F_13 ( V_33 == ( V_34 + 1 ) * V_39 ) ;
V_35 = V_6 & V_34 ;
V_6 = V_6 & ~ V_34 ;
V_36 = V_2 -> V_40 ;
if ( V_7 & V_14 ) {
void * V_41 = F_17 ( V_2 -> V_37 ) ;
void * V_42 = F_17 ( V_2 -> V_40 ) ;
V_12 = F_1 ( V_2 , V_4 , V_36 , V_6 ,
V_43 , V_33 ) ;
if ( F_18 ( ! V_12 ) ) {
F_19 ( V_44 , L_1
L_2 ,
( unsigned long long ) V_6 ) ;
return 0 ;
}
memcpy ( V_42 + V_35 * V_39 , V_41 , V_39 ) ;
}
}
if ( V_6 < V_45 ( V_4 ) ||
V_6 > F_20 ( V_4 ) )
F_21 ( V_44 , L_3 ,
V_46 -> V_47 , V_46 -> V_48 , V_49 ,
( unsigned long long ) V_6 , ( V_7 & V_14 ) ? L_4 : L_5 ) ;
V_12 = F_1 ( V_2 , V_4 , V_36 , V_6 , V_7 , V_33 ) ;
if ( F_18 ( ! V_12 ) ) {
F_19 ( V_44 , L_6 ,
( unsigned long long ) V_6 , ( V_7 & V_14 ) ? L_4 : L_5 ) ;
return 0 ;
}
if ( V_33 != V_39 && ! ( V_7 & V_14 ) ) {
void * V_41 = F_17 ( V_2 -> V_37 ) ;
void * V_42 = F_17 ( V_2 -> V_40 ) ;
memcpy ( V_41 , V_42 + V_35 * V_39 , V_39 ) ;
}
return V_12 ;
}
static struct V_50 * F_22 ( struct V_1 * V_2 , unsigned int V_51 )
{
struct V_50 * V_52 ;
struct V_50 * V_53 ;
unsigned long V_54 = 0 ;
int V_55 ;
F_23 ( & V_2 -> V_56 ) ;
V_53 = F_24 ( V_2 -> V_57 , V_51 / V_58 ) ;
if ( F_18 ( V_53 != NULL ) ) {
struct V_59 * V_60 = F_25 ( V_53 , struct V_59 , V_61 ) ;
if ( F_3 ( V_62 , & V_60 -> V_16 ) ) {
V_55 = ! F_26 ( V_63 , & V_60 -> V_16 ) ;
F_27 ( & V_2 -> V_56 ) ;
if ( V_55 )
F_28 ( & V_2 -> V_64 ) ;
return NULL ;
}
}
V_52 = F_29 ( V_2 -> V_65 , V_51 ) ;
V_54 = V_2 -> V_65 -> V_16 ;
F_27 ( & V_2 -> V_56 ) ;
return V_52 ;
}
void F_30 ( struct V_1 * V_2 , T_1 V_6 )
{
unsigned int V_51 = ( V_6 >> ( V_66 - 9 ) ) ;
struct V_50 * V_52 ;
struct V_67 V_68 ;
F_13 ( F_31 ( & V_2 -> V_69 ) > 0 ) ;
F_32 ( V_2 -> V_64 , ( V_52 = F_22 ( V_2 , V_51 ) ) ) ;
if ( V_52 -> V_70 != V_51 ) {
F_2 ( & V_68 . V_13 ) ;
V_68 . V_52 = V_52 ;
V_68 . V_51 = V_51 ;
V_68 . V_71 = V_52 -> V_70 ;
V_68 . V_72 . V_73 = V_74 ;
F_33 ( & V_2 -> V_75 . V_76 , & V_68 . V_72 ) ;
F_9 ( & V_68 . V_13 ) ;
V_2 -> V_77 ++ ;
F_23 ( & V_2 -> V_56 ) ;
F_34 ( V_2 -> V_65 , V_52 ) ;
F_27 ( & V_2 -> V_56 ) ;
F_28 ( & V_2 -> V_64 ) ;
}
}
void F_35 ( struct V_1 * V_2 , T_1 V_6 )
{
unsigned int V_51 = ( V_6 >> ( V_66 - 9 ) ) ;
struct V_50 * V_78 ;
unsigned long V_16 ;
F_36 ( & V_2 -> V_56 , V_16 ) ;
V_78 = F_24 ( V_2 -> V_65 , V_51 ) ;
if ( ! V_78 ) {
F_37 ( & V_2 -> V_56 , V_16 ) ;
F_19 ( V_44 , L_7 , V_51 ) ;
return;
}
if ( F_38 ( V_2 -> V_65 , V_78 ) == 0 )
F_28 ( & V_2 -> V_64 ) ;
F_37 ( & V_2 -> V_56 , V_16 ) ;
}
static unsigned int F_39 ( unsigned int V_79 )
{
return V_79 >>
( ( V_80 + 3 ) -
( V_66 - V_81 ) ) ;
}
static unsigned int F_40 ( unsigned int V_82 )
{
return V_82 >>
( ( V_80 + 3 ) -
( V_83 - V_81 ) ) ;
}
int
V_74 ( struct V_1 * V_2 , struct V_84 * V_72 , int V_85 )
{
struct V_67 * V_86 = F_41 ( V_72 , struct V_67 , V_72 ) ;
struct V_50 * V_87 = V_86 -> V_52 ;
const unsigned int V_88 = V_86 -> V_51 ;
const unsigned int V_89 = V_86 -> V_71 ;
struct V_90 * V_91 ;
T_1 V_6 ;
int V_92 , V_93 , V_94 ;
unsigned int V_95 ;
T_2 V_96 = 0 ;
if ( ! F_42 ( V_2 ) ) {
F_19 ( V_44 ,
L_8 ,
F_43 ( V_2 -> V_97 . V_98 ) , V_89 , V_88 ) ;
F_44 ( & ( (struct V_67 * ) V_72 ) -> V_13 ) ;
return 1 ;
}
if ( V_2 -> V_97 . V_99 < V_100 && V_89 != V_101 )
F_45 ( V_2 , F_39 ( V_89 ) ) ;
if ( V_2 -> V_97 . V_98 < V_102 ) {
F_19 ( V_44 ,
L_9 ,
F_43 ( V_2 -> V_97 . V_98 ) , V_89 , V_88 ) ;
F_44 ( & ( (struct V_67 * ) V_72 ) -> V_13 ) ;
F_46 ( V_2 ) ;
return 1 ;
}
F_47 ( & V_2 -> V_38 ) ;
V_91 = (struct V_90 * ) F_17 ( V_2 -> V_37 ) ;
V_91 -> V_103 = F_48 ( V_104 ) ;
V_91 -> V_105 = F_49 ( V_2 -> V_106 ) ;
V_93 = F_50 ( V_2 -> V_65 , V_87 ) ;
V_91 -> V_107 [ 0 ] . V_108 = F_49 ( V_93 ) ;
V_91 -> V_107 [ 0 ] . V_78 = F_49 ( V_88 ) ;
V_96 ^= V_88 ;
V_94 = F_51 ( int , V_109 ,
V_2 -> V_65 -> V_110 - V_2 -> V_111 ) ;
for ( V_92 = 0 ; V_92 < V_94 ; V_92 ++ ) {
unsigned V_112 = V_2 -> V_111 + V_92 ;
V_95 = F_52 ( V_2 -> V_65 , V_112 ) -> V_70 ;
V_91 -> V_107 [ V_92 + 1 ] . V_108 = F_49 ( V_112 ) ;
V_91 -> V_107 [ V_92 + 1 ] . V_78 = F_49 ( V_95 ) ;
V_96 ^= V_95 ;
}
for (; V_92 < V_109 ; V_92 ++ ) {
V_91 -> V_107 [ V_92 + 1 ] . V_108 = F_48 ( - 1 ) ;
V_91 -> V_107 [ V_92 + 1 ] . V_78 = F_48 ( V_101 ) ;
V_96 ^= V_101 ;
}
V_2 -> V_111 += V_109 ;
if ( V_2 -> V_111 >= V_2 -> V_65 -> V_110 )
V_2 -> V_111 = 0 ;
V_91 -> V_96 = F_49 ( V_96 ) ;
V_6 = V_2 -> V_113 -> V_114 . V_115
+ V_2 -> V_113 -> V_114 . V_116 + V_2 -> V_117 ;
if ( ! F_12 ( V_2 , V_2 -> V_113 , V_6 , V_14 ) )
F_53 ( V_2 , 1 , true ) ;
if ( ++ V_2 -> V_117 >
F_54 ( V_2 -> V_65 -> V_110 , V_109 ) )
V_2 -> V_117 = 0 ;
F_13 ( V_2 -> V_117 < V_118 ) ;
V_2 -> V_106 ++ ;
F_55 ( & V_2 -> V_38 ) ;
F_44 ( & ( (struct V_67 * ) V_72 ) -> V_13 ) ;
F_46 ( V_2 ) ;
return 1 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_90 * V_119 ,
int V_120 )
{
T_1 V_6 ;
int V_121 , V_92 ;
T_2 V_96 = 0 ;
V_6 = V_4 -> V_114 . V_115 + V_4 -> V_114 . V_116 + V_120 ;
if ( ! F_12 ( V_2 , V_4 , V_6 , V_43 ) )
return - 1 ;
V_121 = ( F_57 ( V_119 -> V_103 ) == V_104 ) ;
for ( V_92 = 0 ; V_92 < V_109 + 1 ; V_92 ++ )
V_96 ^= F_57 ( V_119 -> V_107 [ V_92 ] . V_78 ) ;
V_121 &= ( V_96 == F_57 ( V_119 -> V_96 ) ) ;
return V_121 ;
}
int F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_90 * V_91 ;
int V_92 ;
int V_121 ;
int V_94 ;
int V_122 = 0 ;
int V_123 = 0 ;
int V_124 = 0 ;
int V_125 = 0 ;
int V_126 = 0 ;
T_2 V_127 = 0 ;
T_2 V_128 = 0 ;
T_2 V_129 ;
V_94 = F_54 ( V_2 -> V_65 -> V_110 , V_109 ) ;
F_47 ( & V_2 -> V_38 ) ;
V_91 = F_17 ( V_2 -> V_37 ) ;
for ( V_92 = 0 ; V_92 <= V_94 ; V_92 ++ ) {
V_121 = F_56 ( V_2 , V_4 , V_91 , V_92 ) ;
if ( V_121 == 0 )
continue;
if ( V_121 == - 1 ) {
F_55 ( & V_2 -> V_38 ) ;
return 0 ;
}
V_129 = F_57 ( V_91 -> V_105 ) ;
if ( ++ V_124 == 1 ) {
V_125 = V_92 ;
V_126 = V_92 ;
V_127 = V_129 ;
V_128 = V_129 ;
continue;
}
if ( ( int ) V_129 - ( int ) V_127 < 0 ) {
F_13 ( V_127 - V_129 + V_92 - V_125 == V_94 + 1 ) ;
V_125 = V_92 ;
V_127 = V_129 ;
}
if ( ( int ) V_129 - ( int ) V_128 > 0 ) {
F_13 ( V_129 - V_128 == V_92 - V_126 ) ;
V_126 = V_92 ;
V_128 = V_129 ;
}
}
if ( ! V_124 ) {
F_59 ( V_44 , L_10 ) ;
F_55 ( & V_2 -> V_38 ) ;
return 1 ;
}
V_92 = V_125 ;
while ( 1 ) {
int V_130 , V_108 ;
unsigned int V_95 ;
unsigned int V_131 ;
V_121 = F_56 ( V_2 , V_4 , V_91 , V_92 ) ;
F_60 (rv == 0 ) goto V_132;
if ( V_121 == - 1 ) {
F_55 ( & V_2 -> V_38 ) ;
return 0 ;
}
V_131 = F_57 ( V_91 -> V_105 ) ;
F_23 ( & V_2 -> V_56 ) ;
for ( V_130 = V_109 ; V_130 >= 0 ; V_130 -- ) {
V_108 = F_57 ( V_91 -> V_107 [ V_130 ] . V_108 ) ;
V_95 = F_57 ( V_91 -> V_107 [ V_130 ] . V_78 ) ;
if ( V_95 == V_101 )
continue;
F_61 ( V_2 -> V_65 , V_95 , V_108 ) ;
V_122 ++ ;
}
F_27 ( & V_2 -> V_56 ) ;
V_123 ++ ;
V_132:
if ( V_92 == V_126 )
break;
V_92 ++ ;
if ( V_92 > V_94 )
V_92 = 0 ;
}
V_2 -> V_106 = V_128 + 1 ;
V_2 -> V_117 = V_126 ;
if ( ++ V_2 -> V_117 >
F_54 ( V_2 -> V_65 -> V_110 , V_109 ) )
V_2 -> V_117 = 0 ;
F_55 ( & V_2 -> V_38 ) ;
F_62 ( V_44 , L_11 ,
V_123 , V_122 ) ;
return 1 ;
}
void F_63 ( struct V_1 * V_2 )
{
unsigned int V_51 ;
unsigned long V_133 = 0 ;
char V_134 [ 10 ] ;
int V_92 , V_53 ;
F_32 ( V_2 -> V_64 , F_64 ( V_2 -> V_65 ) ) ;
for ( V_92 = 0 ; V_92 < V_2 -> V_65 -> V_110 ; V_92 ++ ) {
V_51 = F_52 ( V_2 -> V_65 , V_92 ) -> V_70 ;
if ( V_51 == V_101 )
continue;
V_53 = F_65 ( V_2 , V_51 ) ;
F_66 ( V_44 , L_12 , V_53 , V_51 ) ;
V_133 += V_53 ;
}
F_67 ( V_2 -> V_65 ) ;
F_28 ( & V_2 -> V_64 ) ;
F_62 ( V_44 , L_13 ,
F_68 ( V_134 , F_69 ( V_133 ) ) ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_50 * V_52 )
{
int V_121 ;
F_23 ( & V_2 -> V_56 ) ;
V_121 = ( V_52 -> V_135 == 0 ) ;
if ( F_71 ( V_121 ) )
F_72 ( V_2 -> V_65 , V_52 ) ;
F_27 ( & V_2 -> V_56 ) ;
return V_121 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_50 * V_52 ;
int V_92 ;
F_13 ( F_3 ( V_136 , & V_2 -> V_65 -> V_16 ) ) ;
for ( V_92 = 0 ; V_92 < V_2 -> V_65 -> V_110 ; V_92 ++ ) {
V_52 = F_52 ( V_2 -> V_65 , V_92 ) ;
if ( V_52 -> V_70 == V_101 )
continue;
F_32 ( V_2 -> V_64 , F_70 ( V_2 , V_52 ) ) ;
}
F_28 ( & V_2 -> V_64 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_84 * V_72 , int V_85 )
{
struct V_137 * V_138 = F_41 ( V_72 , struct V_137 , V_72 ) ;
if ( ! F_42 ( V_2 ) ) {
if ( F_75 ( & V_139 ) )
F_59 ( V_44 , L_14 ) ;
F_76 ( V_138 ) ;
return 1 ;
}
F_45 ( V_2 , F_40 ( V_138 -> V_51 ) ) ;
F_46 ( V_2 ) ;
F_76 ( V_138 ) ;
if ( F_77 ( V_2 ) <= V_2 -> V_140 ) {
switch ( V_2 -> V_97 . V_99 ) {
case V_141 : case V_142 :
case V_143 : case V_144 :
F_78 ( V_2 ) ;
default:
break;
}
}
F_79 ( V_2 ) ;
return 1 ;
}
static void F_80 ( struct V_1 * V_2 , T_1 V_6 ,
int V_145 , int V_146 )
{
struct V_50 * V_147 ;
struct V_137 * V_138 ;
unsigned int V_51 ;
F_13 ( F_31 ( & V_2 -> V_69 ) ) ;
V_51 = F_81 ( V_6 ) ;
V_147 = F_29 ( V_2 -> V_57 , V_51 ) ;
if ( V_147 ) {
struct V_59 * V_148 = F_25 ( V_147 , struct V_59 , V_61 ) ;
if ( V_148 -> V_61 . V_70 == V_51 ) {
if ( V_146 )
V_148 -> V_149 -= V_145 ;
else
V_148 -> V_140 += V_145 ;
if ( V_148 -> V_149 < V_148 -> V_140 ) {
F_19 ( V_44 , L_15
L_16 ,
( unsigned long long ) V_6 ,
V_148 -> V_61 . V_70 , V_148 -> V_149 ,
V_148 -> V_140 , V_145 ) ;
F_82 () ;
F_38 ( V_2 -> V_57 , & V_148 -> V_61 ) ;
F_83 ( V_2 , F_84 ( V_99 , V_150 ) ) ;
return;
}
} else {
int V_149 = F_85 ( V_2 , V_51 ) ;
if ( V_148 -> V_16 != 0 ) {
F_59 ( V_44 , L_17
L_18 ,
V_148 -> V_61 . V_70 , V_148 -> V_149 ,
V_148 -> V_16 , V_51 , V_149 ) ;
V_148 -> V_16 = 0 ;
}
if ( V_148 -> V_140 ) {
F_59 ( V_44 , L_19
L_20 ,
V_148 -> V_61 . V_70 , V_148 -> V_140 ) ;
}
V_148 -> V_149 = V_149 ;
V_148 -> V_140 = V_146 ? 0 : V_145 ;
F_34 ( V_2 -> V_57 , & V_148 -> V_61 ) ;
}
F_38 ( V_2 -> V_57 , & V_148 -> V_61 ) ;
if ( V_148 -> V_149 == V_148 -> V_140 ) {
V_148 -> V_140 = 0 ;
V_138 = F_86 ( sizeof( * V_138 ) , V_151 ) ;
if ( V_138 ) {
V_138 -> V_51 = V_148 -> V_61 . V_70 ;
V_138 -> V_72 . V_73 = F_74 ;
F_33 ( & V_2 -> V_75 . V_76 , & V_138 -> V_72 ) ;
} else {
F_59 ( V_44 , L_21 ) ;
}
}
} else {
F_19 ( V_44 , L_22 ,
V_2 -> V_152 ,
V_2 -> V_57 -> V_110 ,
V_2 -> V_57 -> V_16 ) ;
}
}
void F_87 ( struct V_1 * V_2 , unsigned long V_153 )
{
unsigned long V_154 = V_155 ;
unsigned long V_156 = V_2 -> V_157 [ V_2 -> V_158 ] ;
int V_159 = ( V_2 -> V_158 + 1 ) % V_160 ;
if ( F_88 ( V_154 , V_156 + V_161 ) ) {
if ( V_2 -> V_162 [ V_2 -> V_158 ] != V_153 &&
V_2 -> V_97 . V_99 != V_144 &&
V_2 -> V_97 . V_99 != V_143 ) {
V_2 -> V_157 [ V_159 ] = V_154 ;
V_2 -> V_162 [ V_159 ] = V_153 ;
V_2 -> V_158 = V_159 ;
}
}
}
void F_89 ( struct V_1 * V_2 , T_1 V_6 , int V_8 ,
const char * V_163 , const unsigned int line )
{
unsigned long V_164 , V_165 , V_166 ;
unsigned long V_145 = 0 ;
T_1 V_167 , V_168 ;
int F_28 = 0 ;
unsigned long V_16 ;
if ( V_8 <= 0 || ( V_8 & 0x1ff ) != 0 || V_8 > V_169 ) {
F_19 ( V_44 , L_23 ,
( unsigned long long ) V_6 , V_8 ) ;
return;
}
V_168 = F_90 ( V_2 -> V_170 ) ;
V_167 = V_6 + ( V_8 >> 9 ) - 1 ;
F_60 (sector >= nr_sectors) return;
F_60 (esector >= nr_sectors) V_167 = ( V_168 - 1 ) ;
V_166 = F_91 ( V_168 - 1 ) ;
if ( F_18 ( V_167 < V_171 - 1 ) )
return;
if ( F_18 ( V_167 == ( V_168 - 1 ) ) )
V_165 = V_166 ;
else
V_165 = F_91 ( V_167 - ( V_171 - 1 ) ) ;
V_164 = F_91 ( V_6 + V_171 - 1 ) ;
if ( V_164 > V_165 )
return;
V_145 = F_92 ( V_2 , V_164 , V_165 ) ;
if ( V_145 && F_42 ( V_2 ) ) {
F_87 ( V_2 , F_77 ( V_2 ) ) ;
F_36 ( & V_2 -> V_56 , V_16 ) ;
F_80 ( V_2 , V_6 , V_145 , true ) ;
F_37 ( & V_2 -> V_56 , V_16 ) ;
F_28 = 1 ;
F_46 ( V_2 ) ;
}
if ( F_28 )
F_28 ( & V_2 -> V_64 ) ;
}
int F_93 ( struct V_1 * V_2 , T_1 V_6 , int V_8 ,
const char * V_163 , const unsigned int line )
{
unsigned long V_164 , V_165 , V_166 , V_16 ;
T_1 V_167 , V_168 ;
unsigned int V_51 , V_145 = 0 ;
struct V_50 * V_147 ;
if ( V_8 <= 0 || ( V_8 & 0x1ff ) != 0 || V_8 > V_169 ) {
F_19 ( V_44 , L_24 ,
( unsigned long long ) V_6 , V_8 ) ;
return 0 ;
}
if ( ! F_42 ( V_2 ) )
return 0 ;
V_168 = F_90 ( V_2 -> V_170 ) ;
V_167 = V_6 + ( V_8 >> 9 ) - 1 ;
F_60 (sector >= nr_sectors)
goto V_24;
F_60 (esector >= nr_sectors)
V_167 = ( V_168 - 1 ) ;
V_166 = F_91 ( V_168 - 1 ) ;
V_164 = F_91 ( V_6 ) ;
V_165 = F_91 ( V_167 ) ;
F_36 ( & V_2 -> V_56 , V_16 ) ;
V_145 = F_94 ( V_2 , V_164 , V_165 ) ;
V_51 = F_81 ( V_6 ) ;
V_147 = F_24 ( V_2 -> V_57 , V_51 ) ;
if ( V_147 )
F_25 ( V_147 , struct V_59 , V_61 ) -> V_149 += V_145 ;
F_37 ( & V_2 -> V_56 , V_16 ) ;
V_24:
F_46 ( V_2 ) ;
return V_145 ;
}
static
struct V_59 * F_95 ( struct V_1 * V_2 , unsigned int V_51 )
{
struct V_50 * V_147 ;
struct V_59 * V_60 ;
int V_172 = 0 ;
unsigned long V_173 ;
F_23 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_152 > V_2 -> V_57 -> V_110 / 2 ) {
F_27 ( & V_2 -> V_56 ) ;
return NULL ;
}
V_147 = F_29 ( V_2 -> V_57 , V_51 ) ;
V_60 = V_147 ? F_25 ( V_147 , struct V_59 , V_61 ) : NULL ;
if ( V_60 ) {
if ( V_60 -> V_61 . V_70 != V_51 ) {
V_60 -> V_149 = F_85 ( V_2 , V_51 ) ;
V_60 -> V_140 = 0 ;
F_34 ( V_2 -> V_57 , & V_60 -> V_61 ) ;
V_172 = 1 ;
}
if ( V_60 -> V_61 . V_135 == 1 )
V_2 -> V_152 ++ ;
F_96 ( V_62 , & V_60 -> V_16 ) ;
}
V_173 = V_2 -> V_57 -> V_16 ;
F_27 ( & V_2 -> V_56 ) ;
if ( V_172 )
F_28 ( & V_2 -> V_64 ) ;
if ( ! V_60 ) {
if ( V_173 & V_174 )
F_59 ( V_44 , L_25
L_26 ) ;
F_15 ( V_173 & V_175 ) ;
}
return V_60 ;
}
static int F_97 ( struct V_1 * V_2 , unsigned int V_51 )
{
struct V_50 * V_52 ;
int V_121 = 0 ;
F_23 ( & V_2 -> V_56 ) ;
if ( F_18 ( V_51 == V_2 -> V_65 -> V_176 ) )
V_121 = 1 ;
else {
V_52 = F_24 ( V_2 -> V_65 , V_51 ) ;
if ( V_52 ) {
if ( V_52 -> V_135 )
V_121 = 1 ;
}
}
F_27 ( & V_2 -> V_56 ) ;
return V_121 ;
}
int F_98 ( struct V_1 * V_2 , T_1 V_6 )
{
unsigned int V_51 = F_81 ( V_6 ) ;
struct V_59 * V_60 ;
int V_92 , V_177 ;
int V_178 = 200 ;
V_179:
V_177 = F_99 ( V_2 -> V_64 ,
( V_60 = F_95 ( V_2 , V_51 ) ) ) ;
if ( V_177 )
return - V_180 ;
if ( F_3 ( V_181 , & V_60 -> V_16 ) )
return 0 ;
for ( V_92 = 0 ; V_92 < V_58 ; V_92 ++ ) {
V_177 = F_99 ( V_2 -> V_64 ,
! F_97 ( V_2 , V_51 * V_58 + V_92 ) ||
F_3 ( V_63 , & V_60 -> V_16 ) ) ;
if ( V_177 || ( F_3 ( V_63 , & V_60 -> V_16 ) && V_178 ) ) {
F_23 ( & V_2 -> V_56 ) ;
if ( F_38 ( V_2 -> V_57 , & V_60 -> V_61 ) == 0 ) {
V_60 -> V_16 = 0 ;
V_2 -> V_152 -- ;
F_28 ( & V_2 -> V_64 ) ;
}
F_27 ( & V_2 -> V_56 ) ;
if ( V_177 )
return - V_180 ;
if ( F_100 ( V_182 / 10 ) )
return - V_180 ;
if ( V_178 && -- V_178 == 0 )
F_59 ( V_44 , L_27
L_28 ) ;
goto V_179;
}
}
F_96 ( V_181 , & V_60 -> V_16 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , T_1 V_6 )
{
unsigned int V_51 = F_81 ( V_6 ) ;
const unsigned int V_79 = V_51 * V_58 ;
struct V_50 * V_147 ;
struct V_59 * V_60 ;
int V_92 ;
F_23 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_183 != V_101 && V_2 -> V_183 != V_51 ) {
V_147 = F_24 ( V_2 -> V_57 , V_2 -> V_183 ) ;
V_60 = V_147 ? F_25 ( V_147 , struct V_59 , V_61 ) : NULL ;
if ( V_60 ) {
F_13 ( ! F_3 ( V_181 , & V_60 -> V_16 ) ) ;
F_13 ( F_3 ( V_62 , & V_60 -> V_16 ) ) ;
F_102 ( V_62 , & V_60 -> V_16 ) ;
V_2 -> V_183 = V_101 ;
if ( F_38 ( V_2 -> V_57 , & V_60 -> V_61 ) == 0 )
V_2 -> V_152 -- ;
F_28 ( & V_2 -> V_64 ) ;
} else {
F_21 ( V_44 , L_29 ) ;
}
}
V_147 = F_103 ( V_2 -> V_57 , V_51 ) ;
V_60 = V_147 ? F_25 ( V_147 , struct V_59 , V_61 ) : NULL ;
if ( V_60 ) {
if ( F_3 ( V_181 , & V_60 -> V_16 ) )
goto V_184;
if ( ! F_26 ( V_62 , & V_60 -> V_16 ) ) {
V_2 -> V_152 ++ ;
} else {
V_60 -> V_61 . V_135 -- ;
F_13 ( V_60 -> V_61 . V_135 > 0 ) ;
}
goto V_185;
} else {
if ( V_2 -> V_152 > V_2 -> V_57 -> V_110 - 3 )
goto V_186;
V_147 = F_29 ( V_2 -> V_57 , V_51 ) ;
V_60 = V_147 ? F_25 ( V_147 , struct V_59 , V_61 ) : NULL ;
if ( ! V_60 ) {
const unsigned long V_173 = V_2 -> V_57 -> V_16 ;
if ( V_173 & V_174 )
F_59 ( V_44 , L_25
L_26 ) ;
F_15 ( V_173 & V_175 ) ;
goto V_186;
}
if ( V_60 -> V_61 . V_70 != V_51 ) {
V_60 -> V_149 = F_85 ( V_2 , V_51 ) ;
V_60 -> V_140 = 0 ;
F_34 ( V_2 -> V_57 , & V_60 -> V_61 ) ;
F_28 ( & V_2 -> V_64 ) ;
F_13 ( F_3 ( V_181 , & V_60 -> V_16 ) == 0 ) ;
}
F_96 ( V_62 , & V_60 -> V_16 ) ;
F_13 ( V_60 -> V_61 . V_135 == 1 ) ;
V_2 -> V_152 ++ ;
goto V_185;
}
V_185:
for ( V_92 = 0 ; V_92 < V_58 ; V_92 ++ ) {
if ( F_18 ( V_79 + V_92 == V_2 -> V_65 -> V_176 ) )
goto V_186;
if ( F_104 ( V_2 -> V_65 , V_79 + V_92 ) )
goto V_186;
}
F_96 ( V_181 , & V_60 -> V_16 ) ;
V_184:
V_2 -> V_183 = V_101 ;
F_27 ( & V_2 -> V_56 ) ;
return 0 ;
V_186:
if ( V_60 )
V_2 -> V_183 = V_51 ;
F_27 ( & V_2 -> V_56 ) ;
return - V_187 ;
}
void F_105 ( struct V_1 * V_2 , T_1 V_6 )
{
unsigned int V_51 = F_81 ( V_6 ) ;
struct V_50 * V_147 ;
struct V_59 * V_60 ;
unsigned long V_16 ;
F_36 ( & V_2 -> V_56 , V_16 ) ;
V_147 = F_24 ( V_2 -> V_57 , V_51 ) ;
V_60 = V_147 ? F_25 ( V_147 , struct V_59 , V_61 ) : NULL ;
if ( ! V_60 ) {
F_37 ( & V_2 -> V_56 , V_16 ) ;
if ( F_75 ( & V_139 ) )
F_19 ( V_44 , L_30 ) ;
return;
}
if ( V_60 -> V_61 . V_135 == 0 ) {
F_37 ( & V_2 -> V_56 , V_16 ) ;
F_19 ( V_44 , L_31
L_32 ,
( unsigned long long ) V_6 , V_51 ) ;
return;
}
if ( F_38 ( V_2 -> V_57 , & V_60 -> V_61 ) == 0 ) {
V_60 -> V_16 = 0 ;
V_2 -> V_152 -- ;
F_28 ( & V_2 -> V_64 ) ;
}
F_37 ( & V_2 -> V_56 , V_16 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_56 ) ;
if ( F_107 ( V_2 , V_188 ) ) {
F_108 ( V_2 -> V_57 ) ;
F_46 ( V_2 ) ;
}
V_2 -> V_152 = 0 ;
V_2 -> V_183 = V_101 ;
F_27 ( & V_2 -> V_56 ) ;
F_28 ( & V_2 -> V_64 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_50 * V_147 ;
struct V_59 * V_60 ;
int V_92 ;
F_23 ( & V_2 -> V_56 ) ;
if ( F_107 ( V_2 , V_188 ) ) {
for ( V_92 = 0 ; V_92 < V_2 -> V_57 -> V_110 ; V_92 ++ ) {
V_147 = F_52 ( V_2 -> V_57 , V_92 ) ;
V_60 = F_25 ( V_147 , struct V_59 , V_61 ) ;
if ( V_60 -> V_61 . V_70 == V_101 )
continue;
if ( V_60 -> V_61 . V_70 == V_2 -> V_183 ) {
F_62 ( V_44 , L_33
L_34 ,
V_2 -> V_183 ) ;
F_13 ( ! F_3 ( V_181 , & V_60 -> V_16 ) ) ;
F_13 ( F_3 ( V_62 , & V_60 -> V_16 ) ) ;
F_102 ( V_62 , & V_60 -> V_16 ) ;
V_2 -> V_183 = V_101 ;
F_38 ( V_2 -> V_57 , & V_60 -> V_61 ) ;
}
if ( V_60 -> V_61 . V_135 != 0 ) {
F_62 ( V_44 , L_35
L_36 , V_60 -> V_61 . V_135 ) ;
F_46 ( V_2 ) ;
F_27 ( & V_2 -> V_56 ) ;
return - V_187 ;
}
F_13 ( ! F_3 ( V_181 , & V_60 -> V_16 ) ) ;
F_13 ( ! F_3 ( V_62 , & V_60 -> V_16 ) ) ;
F_72 ( V_2 -> V_57 , & V_60 -> V_61 ) ;
}
F_13 ( V_2 -> V_57 -> V_189 == 0 ) ;
F_46 ( V_2 ) ;
}
F_27 ( & V_2 -> V_56 ) ;
return 0 ;
}
void F_110 ( struct V_1 * V_2 , T_1 V_6 , int V_8 )
{
unsigned long V_164 , V_165 , V_166 ;
unsigned long V_145 ;
T_1 V_167 , V_168 ;
int F_28 = 0 ;
if ( V_8 <= 0 || ( V_8 & 0x1ff ) != 0 || V_8 > V_169 ) {
F_19 ( V_44 , L_37 ,
( unsigned long long ) V_6 , V_8 ) ;
return;
}
V_168 = F_90 ( V_2 -> V_170 ) ;
V_167 = V_6 + ( V_8 >> 9 ) - 1 ;
F_60 (sector >= nr_sectors) return;
F_60 (esector >= nr_sectors) V_167 = ( V_168 - 1 ) ;
V_166 = F_91 ( V_168 - 1 ) ;
if ( F_18 ( V_167 < V_171 - 1 ) )
return;
if ( F_18 ( V_167 == ( V_168 - 1 ) ) )
V_165 = V_166 ;
else
V_165 = F_91 ( V_167 - ( V_171 - 1 ) ) ;
V_164 = F_91 ( V_6 + V_171 - 1 ) ;
if ( V_164 > V_165 )
return;
F_23 ( & V_2 -> V_56 ) ;
V_145 = F_111 ( V_2 , V_164 , V_165 ) ;
if ( V_145 ) {
V_2 -> V_140 += V_145 ;
if ( F_42 ( V_2 ) ) {
F_80 ( V_2 , V_6 , V_145 , false ) ;
F_46 ( V_2 ) ;
}
F_28 = 1 ;
}
F_27 ( & V_2 -> V_56 ) ;
if ( F_28 )
F_28 ( & V_2 -> V_64 ) ;
}
