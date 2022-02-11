static inline void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 . V_4 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_3 . V_4 ( & V_2 -> V_3 , V_2 -> V_3 . V_6 ) ;
F_3 ( & V_2 -> V_5 ) ;
return;
}
static void F_4 ( struct V_7 * V_8 , void * V_9 ,
T_1 * V_10 , int V_11 )
{
T_1 type = F_5 ( V_12 , V_10 [ 2 ] ) ;
T_1 V_13 = V_10 [ 1 ] ;
switch ( type ) {
case 0x1 :
{
struct V_14 * V_15 = (struct V_14 * ) V_9 ;
if ( V_10 [ 6 ] == 0 )
return;
F_6 ( & V_8 -> V_16 ,
L_1 ,
V_15 -> V_17 . V_18 , V_13 ) ;
break;
}
case 0x4 :
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_6 ( & V_8 -> V_16 ,
L_2 ,
V_2 -> V_19 , V_13 ) ;
break;
}
default:
F_6 ( & V_8 -> V_16 ,
L_3 ,
type , V_8 -> V_16 . V_20 ) ;
break;
}
F_6 ( & V_8 -> V_16 , L_4 , V_13 ) ;
F_6 ( & V_8 -> V_16 , L_5
L_6 ) ;
F_7 ( V_10 , V_11 , L_7 , V_13 ) ;
F_6 ( & V_8 -> V_16 , L_8
L_9 ) ;
return;
}
int F_8 ( struct V_7 * V_8 , void * V_9 ,
T_1 V_13 )
{
unsigned long V_21 ;
T_1 * V_10 ;
unsigned long V_22 ;
V_10 = F_9 ( V_23 ) ;
if ( ! V_10 ) {
F_6 ( & V_8 -> V_16 , L_10 ) ;
V_21 = - V_24 ;
goto V_25;
}
V_21 = F_10 ( V_8 -> V_26 ,
V_13 ,
V_10 ,
& V_22 ) ;
if ( V_21 == V_27 )
F_6 ( & V_8 -> V_16 ,
L_11 , V_13 ) ;
else if ( V_21 == V_28 ) {
int V_11 ;
V_11 = F_5 ( V_29 , V_10 [ 0 ] ) ;
if ( V_11 > V_30 )
V_11 = V_30 ;
F_4 ( V_8 , V_9 , V_10 , V_11 ) ;
} else
F_6 ( & V_8 -> V_16 ,
L_12 , V_13 ) ;
F_11 ( V_10 ) ;
V_25:
return V_21 ;
}
static void F_12 ( struct V_7 * V_8 , struct V_14 * V_15 ,
enum V_31 V_32 )
{
struct V_33 V_34 ;
if ( V_32 == V_35 && ! V_15 -> V_36 )
return;
V_34 . V_37 = & V_8 -> V_16 ;
V_34 . V_34 = V_32 ;
if ( V_15 -> V_38 == V_39 ) {
if ( ! V_15 -> V_40 . V_41 )
return;
V_34 . V_42 . V_43 = & V_15 -> V_40 ;
V_15 -> V_40 . V_41 ( & V_34 , V_15 -> V_40 . V_44 ) ;
} else {
if ( ! V_15 -> V_17 . V_41 )
return;
V_34 . V_42 . V_15 = & V_15 -> V_17 ;
V_15 -> V_17 . V_41 ( & V_34 , V_15 -> V_17 . V_45 ) ;
}
}
static void F_13 ( struct V_7 * V_8 , T_1 V_46 ,
enum V_31 V_32 , int V_47 )
{
struct V_14 * V_15 ;
T_2 V_48 = F_5 ( V_49 , V_46 ) ;
F_14 ( & V_50 ) ;
V_15 = F_15 ( & V_51 , V_48 ) ;
if ( V_15 )
F_16 ( & V_15 -> V_52 ) ;
F_17 ( & V_50 ) ;
if ( ! V_15 )
return;
if ( V_47 )
F_8 ( V_8 , V_15 , V_15 -> V_53 . V_54 ) ;
F_12 ( V_8 , V_15 , V_47 && V_15 -> V_38 == V_39 ?
V_55 : V_32 ) ;
if ( V_47 && V_15 -> V_38 == V_56 )
F_12 ( V_8 , V_15 , V_57 ) ;
if ( F_18 ( & V_15 -> V_52 ) )
F_19 ( & V_15 -> V_58 ) ;
return;
}
static void F_20 ( struct V_7 * V_8 ,
T_1 V_46 )
{
struct V_1 * V_2 ;
T_2 V_48 = F_5 ( V_59 , V_46 ) ;
F_14 ( & V_60 ) ;
V_2 = F_15 ( & V_61 , V_48 ) ;
if ( V_2 )
F_16 ( & V_2 -> V_52 ) ;
F_17 ( & V_60 ) ;
if ( ! V_2 )
return;
F_8 ( V_8 , V_2 , V_2 -> V_62 . V_54 ) ;
if ( F_18 ( & V_2 -> V_52 ) )
F_19 ( & V_2 -> V_58 ) ;
return;
}
static void F_21 ( struct V_7 * V_8 , T_1 V_46 )
{
T_3 V_63 = F_5 ( V_64 , V_46 ) ;
switch ( V_63 ) {
case 0x02 :
F_13 ( V_8 , V_46 , V_35 , 0 ) ;
break;
case 0x03 :
F_13 ( V_8 , V_46 , V_65 , 0 ) ;
break;
case 0x04 :
F_13 ( V_8 , V_46 , V_66 , 0 ) ;
break;
case 0x05 :
case 0x06 :
F_13 ( V_8 , V_46 , V_67 , 1 ) ;
break;
case 0x07 :
case 0x08 :
F_20 ( V_8 , V_46 ) ;
break;
case 0x09 :
F_6 ( & V_8 -> V_16 , L_13 ) ;
break;
case 0x0A :
F_6 ( & V_8 -> V_16 , L_14 ) ;
break;
case 0x0B :
F_6 ( & V_8 -> V_16 , L_15 ) ;
break;
case 0x0C :
F_6 ( & V_8 -> V_16 , L_16 ) ;
break;
case 0x0D :
F_6 ( & V_8 -> V_16 , L_17 ) ;
break;
case 0x10 :
F_6 ( & V_8 -> V_16 , L_18 ) ;
break;
case 0x11 :
F_6 ( & V_8 -> V_16 , L_19 ) ;
break;
case 0x12 :
F_6 ( & V_8 -> V_16 , L_20 ) ;
break;
case 0x13 :
F_6 ( & V_8 -> V_16 , L_21 ) ;
break;
case 0x14 :
F_22 ( & V_8 -> V_16 , L_22 ) ;
break;
case 0x15 :
F_13 ( V_8 , V_46 , V_68 , 0 ) ;
break;
default:
F_6 ( & V_8 -> V_16 , L_23 ,
V_63 , V_8 -> V_16 . V_20 ) ;
break;
}
return;
}
static void F_23 ( struct V_7 * V_8 , int V_69 ,
enum V_31 type , const char * V_70 )
{
struct V_33 V_34 ;
F_22 ( & V_8 -> V_16 , L_24 , V_69 , V_70 ) ;
V_34 . V_37 = & V_8 -> V_16 ;
V_34 . V_34 = type ;
V_34 . V_42 . V_69 = V_69 ;
F_24 ( & V_34 ) ;
}
static void F_25 ( struct V_7 * V_8 , int V_69 )
{
struct V_71 V_72 ;
struct V_71 * V_73 = & V_8 -> V_74 [ V_69 - 1 ] . V_75 ;
F_26 ( V_8 , V_69 , & V_72 ) ;
if ( V_72 . V_76 != V_73 -> V_76 ||
V_72 . V_77 != V_73 -> V_77 )
F_23 ( V_8 , V_69 , V_78 ,
L_25 ) ;
if ( V_72 . V_79 != V_73 -> V_79 ||
V_72 . V_80 != V_73 -> V_80 )
F_23 ( V_8 , V_69 , V_81 ,
L_26 ) ;
if ( V_72 . V_82 != V_73 -> V_82 ||
memcmp ( V_72 . V_83 , V_73 -> V_83 ,
sizeof( V_84 ) * V_72 . V_82 ) )
F_23 ( V_8 , V_69 , V_85 ,
L_27 ) ;
* V_73 = V_72 ;
}
static int F_27 ( struct V_86 * V_74 )
{
int V_87 ;
unsigned long V_88 ;
F_28 ( & V_74 -> V_89 , V_88 ) ;
V_87 = ! V_74 -> V_90 [ V_91 ] ;
if ( V_74 -> V_90 [ V_92 ] )
F_29 ( V_74 -> V_90 [ V_92 ] ) ;
if ( ! V_87 )
F_29 ( V_74 -> V_90 [ V_91 ] ) ;
F_30 ( & V_74 -> V_89 , V_88 ) ;
return V_87 ;
}
static void F_31 ( struct V_7 * V_8 , T_1 V_46 )
{
T_3 V_93 = F_5 ( V_94 , V_46 ) ;
T_3 V_95 = F_5 ( V_96 , V_46 ) ;
T_3 V_97 ;
struct V_86 * V_74 = & V_8 -> V_74 [ V_95 - 1 ] ;
switch ( V_93 ) {
case 0x30 :
if ( F_5 ( V_98 , V_46 ) ) {
if ( V_99 < 0 )
if ( F_27 ( V_74 ) )
break;
V_74 -> V_100 = V_101 ;
F_23 ( V_8 , V_95 , V_102 ,
L_28 ) ;
F_26 ( V_8 , V_95 , & V_74 -> V_75 ) ;
} else {
V_74 -> V_100 = V_103 ;
F_23 ( V_8 , V_95 , V_104 ,
L_29 ) ;
}
break;
case 0x31 :
if ( F_5 ( V_105 , V_46 ) ) {
F_32 ( & V_8 -> V_16 , L_30
L_31 , V_95 ) ;
V_74 -> V_100 = V_103 ;
F_23 ( V_8 , V_95 , V_104 ,
L_29 ) ;
V_74 -> V_100 = V_101 ;
F_23 ( V_8 , V_95 , V_102 ,
L_28 ) ;
F_26 ( V_8 , V_95 ,
& V_74 -> V_75 ) ;
} else
F_25 ( V_8 , V_95 ) ;
break;
case 0x32 :
F_6 ( & V_8 -> V_16 , L_32 ) ;
break;
case 0x33 :
F_6 ( & V_8 -> V_16 , L_33 ) ;
break;
case 0x34 :
V_97 = F_5 ( V_106 , V_46 ) ;
if ( V_97 == 0x80 )
F_23 ( V_8 , V_95 ,
V_107 ,
L_34 ) ;
else
F_32 ( & V_8 -> V_16 , L_35
L_36 , V_97 , V_95 ) ;
break;
default:
F_6 ( & V_8 -> V_16 , L_37 ,
V_93 , V_8 -> V_16 . V_20 ) ;
break;
}
return;
}
static inline void F_33 ( struct V_1 * V_2 )
{
T_1 V_108 ;
struct V_109 V_110 = V_2 -> V_111 . V_112 ;
F_34 ( V_110 , V_113 , 0x0 ) ;
V_108 = F_35 ( V_110 , F_36 ( V_113 ) ) ;
return;
}
T_4 F_37 ( int V_114 , void * V_115 )
{
struct V_7 * V_8 = (struct V_7 * ) V_115 ;
F_38 ( & V_8 -> V_116 . V_117 ) ;
return V_118 ;
}
void F_39 ( unsigned long V_9 )
{
struct V_7 * V_8 = (struct V_7 * ) V_9 ;
struct V_119 * V_46 ;
T_1 V_21 ;
V_46 = F_40 ( V_8 , & V_8 -> V_116 ) ;
while ( V_46 ) {
if ( ! F_5 ( V_120 , V_46 -> V_121 ) )
F_31 ( V_8 , V_46 -> V_121 ) ;
V_46 = F_40 ( V_8 , & V_8 -> V_116 ) ;
}
V_21 = F_41 ( V_8 -> V_26 ,
V_8 -> V_116 . V_122 , 0xFFFFFFFFFFFFFFFFL ) ;
if ( V_21 != V_28 )
F_6 ( & V_8 -> V_16 , L_38 ) ;
return;
}
T_4 F_42 ( int V_114 , void * V_115 )
{
struct V_7 * V_8 = (struct V_7 * ) V_115 ;
F_38 ( & V_8 -> V_123 . V_117 ) ;
return V_118 ;
}
static inline void F_43 ( struct V_7 * V_8 , struct V_119 * V_46 )
{
T_1 V_124 ;
T_2 V_48 ;
struct V_1 * V_2 ;
V_124 = V_46 -> V_121 ;
F_44 ( & V_8 -> V_16 , L_39 , V_124 ) ;
if ( F_5 ( V_125 , V_124 ) ) {
F_44 ( & V_8 -> V_16 , L_40 ) ;
V_48 = F_5 ( V_59 , V_124 ) ;
F_14 ( & V_60 ) ;
V_2 = F_15 ( & V_61 , V_48 ) ;
if ( V_2 )
F_16 ( & V_2 -> V_52 ) ;
F_17 ( & V_60 ) ;
if ( V_2 == NULL ) {
F_6 ( & V_8 -> V_16 ,
L_41 ,
V_48 ) ;
return;
}
F_33 ( V_2 ) ;
if ( V_126 )
F_45 ( V_2 ) ;
else {
F_1 ( V_2 ) ;
if ( F_18 ( & V_2 -> V_52 ) )
F_19 ( & V_2 -> V_58 ) ;
}
} else {
F_44 ( & V_8 -> V_16 , L_42 ) ;
F_21 ( V_8 , V_124 ) ;
}
}
void F_46 ( struct V_7 * V_8 , int V_127 )
{
struct V_128 * V_123 = & V_8 -> V_123 ;
struct V_129 * V_130 = V_123 -> V_130 ;
T_1 V_124 , V_21 ;
int V_131 , V_132 ;
int V_133 = 0 ;
F_2 ( & V_123 -> V_134 ) ;
if ( V_127 ) {
const int V_135 = 100 ;
int V_136 = 0 ;
int V_137 = 1 ;
do {
V_137 = F_47 (
V_8 -> V_26 , V_123 -> V_138 ) ;
V_136 ++ ;
F_48 () ;
} while ( V_137 && V_136 < V_135 );
if ( F_49 ( ( V_136 == V_135 ) ) )
F_44 ( & V_8 -> V_16 , L_43 ,
V_137 , V_136 ) ;
}
V_131 = 0 ;
do {
T_2 V_48 ;
V_130 [ V_131 ] . V_46 = F_40 ( V_8 , V_123 ) ;
if ( ! V_130 [ V_131 ] . V_46 )
break;
V_124 = V_130 [ V_131 ] . V_46 -> V_121 ;
if ( F_5 ( V_125 , V_124 ) ) {
V_48 = F_5 ( V_59 , V_124 ) ;
F_14 ( & V_60 ) ;
V_130 [ V_131 ] . V_2 = F_15 ( & V_61 , V_48 ) ;
if ( V_130 [ V_131 ] . V_2 )
F_16 ( & V_130 [ V_131 ] . V_2 -> V_52 ) ;
F_17 ( & V_60 ) ;
if ( ! V_130 [ V_131 ] . V_2 ) {
F_6 ( & V_8 -> V_16 ,
L_44
L_45 , V_48 ) ;
continue;
}
} else
V_130 [ V_131 ] . V_2 = NULL ;
V_131 ++ ;
} while ( V_131 < V_139 );
if ( ! V_131 ) {
if ( V_127 )
F_44 ( & V_8 -> V_16 ,
L_46 ) ;
goto V_140;
} else if ( ! V_127 ) {
V_21 = F_50 ( V_123 -> V_138 ) ;
if ( V_21 != V_28 )
F_6 ( & V_8 -> V_16 ,
L_47 , V_21 ) ;
F_44 ( & V_8 -> V_16 , L_48 , V_131 ) ;
}
if ( F_49 ( V_131 == V_139 ) )
F_44 ( & V_8 -> V_16 , L_49 ) ;
for ( V_132 = 0 ; V_132 < V_131 ; V_132 ++ ) {
if ( V_123 -> V_130 [ V_132 ] . V_2 )
F_33 ( V_123 -> V_130 [ V_132 ] . V_2 ) ;
}
F_2 ( & V_123 -> V_141 ) ;
V_133 = ( ! F_51 ( & V_8 -> V_123 . V_142 ) ) ;
F_3 ( & V_123 -> V_141 ) ;
for ( V_132 = 0 ; V_132 < V_131 ; V_132 ++ )
if ( V_123 -> V_130 [ V_132 ] . V_2 ) {
if ( V_126 )
F_45 ( V_123 -> V_130 [ V_132 ] . V_2 ) ;
else {
struct V_1 * V_2 = V_123 -> V_130 [ V_132 ] . V_2 ;
F_1 ( V_2 ) ;
if ( F_18 ( & V_2 -> V_52 ) )
F_19 ( & V_2 -> V_58 ) ;
}
} else {
F_44 ( & V_8 -> V_16 , L_42 ) ;
F_21 ( V_8 , V_123 -> V_130 [ V_132 ] . V_46 -> V_121 ) ;
}
if ( V_133 )
goto V_140;
do {
struct V_119 * V_46 ;
V_46 = F_40 ( V_8 , & V_8 -> V_123 ) ;
if ( ! V_46 )
break;
F_43 ( V_8 , V_46 ) ;
} while ( 1 );
V_140:
F_3 ( & V_123 -> V_134 ) ;
}
void F_52 ( unsigned long V_9 )
{
F_46 ( (struct V_7 * ) V_9 , 1 ) ;
}
static inline int F_53 ( struct V_143 * V_144 )
{
int V_145 ;
unsigned long V_88 ;
F_54 ( ! F_55 () ) ;
if ( V_146 >= 3 )
F_7 ( V_147 , F_56 () , L_50 ) ;
F_28 ( & V_144 -> V_148 , V_88 ) ;
V_145 = F_57 ( V_144 -> V_149 , V_147 ) ;
if ( V_145 >= V_150 )
V_145 = F_58 ( V_147 ) ;
V_144 -> V_149 = V_145 ;
F_30 ( & V_144 -> V_148 , V_88 ) ;
return V_145 ;
}
static void F_59 ( struct V_1 * V_151 ,
struct V_152 * V_153 )
{
unsigned long V_88 ;
F_28 ( & V_153 -> V_154 , V_88 ) ;
F_2 ( & V_151 -> V_154 ) ;
if ( V_151 -> V_155 == 0 ) {
V_151 -> V_155 ++ ;
F_60 ( & V_151 -> V_121 , & V_153 -> V_156 ) ;
V_153 -> V_157 ++ ;
F_19 ( & V_153 -> V_158 ) ;
} else
V_151 -> V_155 ++ ;
F_3 ( & V_151 -> V_154 ) ;
F_30 ( & V_153 -> V_154 , V_88 ) ;
}
static void F_45 ( struct V_1 * V_151 )
{
int V_159 ;
struct V_152 * V_153 ;
int V_157 ;
unsigned long V_88 ;
V_159 = F_53 ( V_144 ) ;
F_61 ( ! F_62 ( V_159 ) ) ;
V_153 = F_63 ( V_144 -> V_160 , V_159 ) ;
F_61 ( ! V_153 ) ;
F_28 ( & V_153 -> V_154 , V_88 ) ;
V_157 = V_153 -> V_157 ;
F_30 ( & V_153 -> V_154 , V_88 ) ;
if ( V_157 > 0 ) {
V_159 = F_53 ( V_144 ) ;
V_153 = F_63 ( V_144 -> V_160 , V_159 ) ;
F_61 ( ! V_153 ) ;
}
F_59 ( V_151 , V_153 ) ;
}
static void F_64 ( struct V_152 * V_153 )
{
struct V_1 * V_2 ;
unsigned long V_88 ;
F_28 ( & V_153 -> V_154 , V_88 ) ;
while ( ! F_65 ( & V_153 -> V_156 ) ) {
V_2 = F_66 ( V_153 -> V_156 . V_161 , struct V_1 , V_121 ) ;
F_30 ( & V_153 -> V_154 , V_88 ) ;
F_1 ( V_2 ) ;
if ( F_18 ( & V_2 -> V_52 ) )
F_19 ( & V_2 -> V_58 ) ;
F_28 ( & V_153 -> V_154 , V_88 ) ;
F_2 ( & V_2 -> V_154 ) ;
V_2 -> V_155 -- ;
if ( ! V_2 -> V_155 ) {
F_67 ( V_153 -> V_156 . V_161 ) ;
V_153 -> V_157 -- ;
}
F_3 ( & V_2 -> V_154 ) ;
}
F_30 ( & V_153 -> V_154 , V_88 ) ;
}
static int F_68 ( void * V_162 )
{
struct V_152 * V_153 = V_162 ;
int V_163 ;
F_69 ( V_164 , V_165 ) ;
F_70 ( V_166 ) ;
while ( ! F_71 () ) {
F_72 ( & V_153 -> V_158 , & V_164 ) ;
F_73 ( & V_153 -> V_154 ) ;
V_163 = F_65 ( & V_153 -> V_156 ) ;
F_74 ( & V_153 -> V_154 ) ;
if ( V_163 )
F_75 () ;
else
F_76 ( V_167 ) ;
F_77 ( & V_153 -> V_158 , & V_164 ) ;
F_73 ( & V_153 -> V_154 ) ;
V_163 = F_65 ( & V_153 -> V_156 ) ;
F_74 ( & V_153 -> V_154 ) ;
if ( ! V_163 )
F_64 ( V_162 ) ;
F_70 ( V_166 ) ;
}
F_76 ( V_167 ) ;
return 0 ;
}
static struct V_168 * F_78 ( struct V_143 * V_144 ,
int V_145 )
{
struct V_152 * V_153 ;
V_153 = F_63 ( V_144 -> V_160 , V_145 ) ;
F_79 ( & V_153 -> V_154 ) ;
F_80 ( & V_153 -> V_156 ) ;
F_81 ( & V_153 -> V_158 ) ;
V_153 -> V_169 = F_82 ( F_68 , V_153 , F_83 ( V_145 ) ,
L_51 , V_145 ) ;
return V_153 -> V_169 ;
}
static void F_84 ( struct V_143 * V_144 ,
int V_145 )
{
struct V_152 * V_153 ;
struct V_168 * V_169 ;
unsigned long V_170 ;
V_153 = F_63 ( V_144 -> V_160 , V_145 ) ;
F_28 ( & V_153 -> V_154 , V_170 ) ;
V_169 = V_153 -> V_169 ;
V_153 -> V_169 = NULL ;
V_153 -> V_157 = 0 ;
F_30 ( & V_153 -> V_154 , V_170 ) ;
if ( V_169 )
F_85 ( V_169 ) ;
}
static void T_5 F_86 ( struct V_143 * V_144 , int V_145 )
{
struct V_152 * V_153 = F_63 ( V_144 -> V_160 , V_145 ) ;
F_87 ( V_171 ) ;
struct V_1 * V_2 ;
unsigned long V_170 ;
F_28 ( & V_153 -> V_154 , V_170 ) ;
F_88 ( & V_153 -> V_156 , & V_171 ) ;
while ( ! F_65 ( & V_171 ) ) {
V_2 = F_66 ( V_153 -> V_156 . V_161 , struct V_1 , V_121 ) ;
F_89 ( & V_2 -> V_121 ) ;
F_59 ( V_2 , F_90 ( V_144 -> V_160 ) ) ;
}
F_30 ( & V_153 -> V_154 , V_170 ) ;
}
static int T_5 F_91 ( struct V_172 * V_173 ,
unsigned long V_174 ,
void * V_175 )
{
unsigned int V_145 = ( unsigned long ) V_175 ;
struct V_152 * V_153 ;
switch ( V_174 ) {
case V_176 :
case V_177 :
F_92 ( L_52 , V_145 ) ;
if ( ! F_78 ( V_144 , V_145 ) ) {
F_93 ( L_53 , V_145 ) ;
return F_94 ( - V_24 ) ;
}
break;
case V_178 :
case V_179 :
F_92 ( L_54 , V_145 ) ;
V_153 = F_63 ( V_144 -> V_160 , V_145 ) ;
F_95 ( V_153 -> V_169 , F_96 ( V_147 ) ) ;
F_84 ( V_144 , V_145 ) ;
break;
case V_180 :
case V_181 :
F_92 ( L_55 , V_145 ) ;
V_153 = F_63 ( V_144 -> V_160 , V_145 ) ;
F_95 ( V_153 -> V_169 , V_145 ) ;
F_97 ( V_153 -> V_169 ) ;
break;
case V_182 :
case V_183 :
F_92 ( L_56 , V_145 ) ;
break;
case V_184 :
case V_185 :
F_92 ( L_57 , V_145 ) ;
break;
case V_186 :
case V_187 :
F_92 ( L_58 , V_145 ) ;
F_84 ( V_144 , V_145 ) ;
F_86 ( V_144 , V_145 ) ;
break;
}
return V_188 ;
}
int F_98 ( void )
{
int V_145 ;
struct V_168 * V_169 ;
if ( ! V_126 )
return 0 ;
V_144 = F_99 ( sizeof( struct V_143 ) , V_189 ) ;
if ( V_144 == NULL )
return - V_24 ;
F_79 ( & V_144 -> V_148 ) ;
V_144 -> V_149 = F_96 ( V_147 ) ;
V_144 -> V_160 = F_100 ( struct V_152 ) ;
if ( V_144 -> V_160 == NULL ) {
F_101 ( V_144 ) ;
return - V_190 ;
}
F_102 (cpu) {
V_169 = F_78 ( V_144 , V_145 ) ;
if ( V_169 ) {
F_95 ( V_169 , V_145 ) ;
F_97 ( V_169 ) ;
}
}
F_103 ( & V_191 ) ;
F_104 ( V_192 L_59 ) ;
return 0 ;
}
void F_105 ( void )
{
int V_132 ;
if ( ! V_126 )
return;
F_106 ( & V_191 ) ;
F_102 (i)
F_84 ( V_144 , V_132 ) ;
F_107 ( V_144 -> V_160 ) ;
F_101 ( V_144 ) ;
}
