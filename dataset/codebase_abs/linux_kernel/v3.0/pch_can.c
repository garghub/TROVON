static inline void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( F_3 ( V_1 ) | V_2 , V_1 ) ;
}
static inline void F_4 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( F_3 ( V_1 ) & ~ V_2 , V_1 ) ;
}
static void F_5 ( struct V_3 * V_4 ,
enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
F_4 ( & V_4 -> V_8 -> V_9 , V_10 ) ;
break;
case V_11 :
F_1 ( & V_4 -> V_8 -> V_9 , V_10 ) ;
break;
default:
F_6 ( V_4 -> V_12 , L_1 , V_13 ) ;
break;
}
}
static void F_7 ( struct V_3 * V_4 )
{
T_2 V_14 = F_3 ( & V_4 -> V_8 -> V_15 ) ;
if ( V_4 -> V_16 . V_17 & V_18 )
V_14 |= V_19 ;
if ( V_4 -> V_16 . V_17 & V_20 )
V_14 |= V_21 ;
F_1 ( & V_4 -> V_8 -> V_9 , V_22 ) ;
F_2 ( V_14 , & V_4 -> V_8 -> V_15 ) ;
}
static void F_8 ( void T_1 * V_23 , T_2 V_24 )
{
int V_25 = V_26 ;
T_2 V_27 ;
F_2 ( V_24 , V_23 ) ;
while ( V_25 ) {
V_27 = F_3 ( V_23 ) & V_28 ;
if ( ! V_27 )
break;
V_25 -- ;
F_9 ( 1 ) ;
}
if ( ! V_25 )
F_10 ( L_2 , V_13 ) ;
}
static void F_11 ( struct V_3 * V_4 ,
enum V_5 V_29 )
{
switch ( V_29 ) {
case V_30 :
F_4 ( & V_4 -> V_8 -> V_9 , V_31 ) ;
break;
case V_32 :
F_1 ( & V_4 -> V_8 -> V_9 , V_33 ) ;
break;
case V_34 :
F_4 ( & V_4 -> V_8 -> V_9 , V_33 ) ;
break;
default:
F_6 ( V_4 -> V_12 , L_3 ) ;
break;
}
}
static void F_12 ( struct V_3 * V_4 , T_2 V_35 ,
int V_36 , enum V_37 V_38 )
{
T_2 V_39 ;
if ( V_38 )
V_39 = V_40 ;
else
V_39 = V_41 ;
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ V_38 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_45 , V_35 ) ;
F_2 ( V_46 | V_47 | V_48 ,
& V_4 -> V_8 -> V_43 [ V_38 ] . V_44 ) ;
if ( V_36 ) {
F_1 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_49 , V_39 ) ;
F_1 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_50 , V_51 ) ;
} else {
F_4 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_49 , V_39 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_50 , V_51 ) ;
}
F_8 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_45 , V_35 ) ;
}
static void F_13 ( struct V_3 * V_4 , int V_36 )
{
int V_52 ;
for ( V_52 = V_53 ; V_52 <= V_54 ; V_52 ++ )
F_12 ( V_4 , V_52 , V_36 , V_55 ) ;
}
static void F_14 ( struct V_3 * V_4 , int V_36 )
{
int V_52 ;
for ( V_52 = V_56 ; V_52 <= V_57 ; V_52 ++ )
F_12 ( V_4 , V_52 , V_36 , V_58 ) ;
}
static T_2 F_15 ( struct V_3 * V_4 )
{
return F_3 ( & V_4 -> V_8 -> V_59 ) & 0xffff ;
}
static void F_16 ( struct V_3 * V_4 )
{
int V_52 ;
for ( V_52 = V_53 ; V_52 <= V_57 ; V_52 ++ ) {
F_2 ( V_60 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_2 ( 0xffff , & V_4 -> V_8 -> V_43 [ 0 ] . V_61 ) ;
F_2 ( 0xffff , & V_4 -> V_8 -> V_43 [ 0 ] . V_62 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_63 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_50 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_64 [ 0 ] ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_64 [ 1 ] ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_64 [ 2 ] ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_64 [ 3 ] ) ;
F_2 ( V_46 | V_65 |
V_47 | V_48 ,
& V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_52 ) ;
}
}
static void F_17 ( struct V_3 * V_4 )
{
int V_52 ;
for ( V_52 = V_53 ; V_52 <= V_54 ; V_52 ++ ) {
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_52 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_63 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_50 ) ;
F_1 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_66 ) ;
if ( V_52 == V_54 )
F_1 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_67 ) ;
else
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_67 ) ;
F_2 ( 0 , & V_4 -> V_8 -> V_43 [ 0 ] . V_61 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_62 ,
0x1fff | V_68 ) ;
F_2 ( V_46 | V_65 | V_47 |
V_48 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_52 ) ;
}
for ( V_52 = V_56 ; V_52 <= V_57 ; V_52 ++ ) {
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ 1 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_45 , V_52 ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 1 ] . V_63 ) ;
F_2 ( V_69 , & V_4 -> V_8 -> V_43 [ 1 ] . V_50 ) ;
F_2 ( V_67 | V_66 ,
& V_4 -> V_8 -> V_43 [ 1 ] . V_49 ) ;
F_2 ( 0 , & V_4 -> V_8 -> V_43 [ 1 ] . V_61 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_62 , 0x1fff ) ;
F_2 ( V_46 | V_65 | V_47 |
V_48 , & V_4 -> V_8 -> V_43 [ 1 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_45 , V_52 ) ;
}
}
static void F_18 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_11 ) ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
F_11 ( V_4 , V_32 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
F_5 ( V_4 , V_11 ) ;
F_11 ( V_4 , V_34 ) ;
F_13 ( V_4 , 0 ) ;
F_14 ( V_4 , 0 ) ;
}
static void F_20 ( struct V_3 * V_4 , T_2 V_2 )
{
if ( ( V_2 >= V_53 ) && ( V_2 <= V_54 ) ) {
F_2 ( V_46 | V_48 | V_47 ,
& V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_50 , V_69 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_70 | V_71 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_2 ) ;
} else if ( ( V_2 >= V_56 ) && ( V_2 <= V_57 ) ) {
F_2 ( V_46 | V_48 | V_47 ,
& V_4 -> V_8 -> V_43 [ 1 ] . V_44 ) ;
F_1 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_50 ,
V_69 | ( 0x7ff << 2 ) ) ;
F_2 ( 0x0 , & V_4 -> V_8 -> V_43 [ 1 ] . V_63 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_49 ,
V_70 | V_71 |
V_72 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_45 , V_2 ) ;
}
}
static void F_21 ( struct V_3 * V_4 )
{
F_2 ( 1 , & V_4 -> V_8 -> V_73 ) ;
F_2 ( 0 , & V_4 -> V_8 -> V_73 ) ;
}
static void F_22 ( struct V_74 * V_12 , T_2 V_75 )
{
struct V_76 * V_77 ;
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_78 * V_79 ;
T_2 V_80 , V_81 ;
struct V_82 * V_83 = & ( V_4 -> V_12 -> V_83 ) ;
enum V_84 V_85 = V_4 -> V_16 . V_85 ;
V_77 = F_24 ( V_12 , & V_79 ) ;
if ( ! V_77 )
return;
if ( V_75 & V_86 ) {
F_14 ( V_4 , 0 ) ;
F_13 ( V_4 , 0 ) ;
V_85 = V_87 ;
V_79 -> V_88 |= V_89 ;
F_25 ( V_12 ) ;
}
V_80 = F_3 ( & V_4 -> V_8 -> V_80 ) ;
if ( V_75 & V_90 ) {
V_85 = V_91 ;
V_4 -> V_16 . V_92 . V_93 ++ ;
V_79 -> V_88 |= V_94 ;
if ( ( ( V_80 & V_95 ) >> 8 ) > 96 )
V_79 -> V_64 [ 1 ] |= V_96 ;
if ( ( V_80 & V_97 ) > 96 )
V_79 -> V_64 [ 1 ] |= V_98 ;
F_26 ( V_12 ,
L_4 , V_13 ) ;
}
if ( V_75 & V_99 ) {
V_4 -> V_16 . V_92 . V_100 ++ ;
V_85 = V_101 ;
V_79 -> V_88 |= V_94 ;
if ( ( ( V_80 & V_95 ) >> 8 ) > 127 )
V_79 -> V_64 [ 1 ] |= V_102 ;
if ( ( V_80 & V_97 ) > 127 )
V_79 -> V_64 [ 1 ] |= V_103 ;
F_26 ( V_12 ,
L_5 , V_13 ) ;
}
V_81 = V_75 & V_104 ;
switch ( V_81 ) {
case V_105 :
V_79 -> V_64 [ 2 ] |= V_106 ;
V_4 -> V_16 . V_92 . V_107 ++ ;
V_83 -> V_108 ++ ;
break;
case V_109 :
V_79 -> V_64 [ 2 ] |= V_110 ;
V_4 -> V_16 . V_92 . V_107 ++ ;
V_83 -> V_108 ++ ;
break;
case V_111 :
V_79 -> V_88 |= V_112 ;
V_4 -> V_16 . V_92 . V_107 ++ ;
V_83 -> V_108 ++ ;
break;
case V_113 :
case V_114 :
V_79 -> V_64 [ 2 ] |= V_115 ;
V_4 -> V_16 . V_92 . V_107 ++ ;
V_83 -> V_108 ++ ;
break;
case V_116 :
V_79 -> V_64 [ 2 ] |= V_117 |
V_118 ;
V_4 -> V_16 . V_92 . V_107 ++ ;
V_83 -> V_108 ++ ;
break;
case V_104 :
break;
}
V_79 -> V_64 [ 6 ] = V_80 & V_97 ;
V_79 -> V_64 [ 7 ] = ( V_80 & V_95 ) >> 8 ;
V_4 -> V_16 . V_85 = V_85 ;
F_27 ( V_77 ) ;
V_83 -> V_119 ++ ;
V_83 -> V_120 += V_79 -> V_121 ;
}
static T_3 F_28 ( int V_122 , void * V_123 )
{
struct V_74 * V_12 = (struct V_74 * ) V_123 ;
struct V_3 * V_4 = F_23 ( V_12 ) ;
if ( ! F_15 ( V_4 ) )
return V_124 ;
F_11 ( V_4 , V_34 ) ;
F_29 ( & V_4 -> V_125 ) ;
return V_126 ;
}
static void F_30 ( struct V_3 * V_4 , int V_127 )
{
if ( V_127 < V_128 ) {
F_2 ( V_46 | V_48 |
V_47 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_50 , V_69 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_71 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_127 ) ;
} else if ( V_127 > V_128 ) {
F_20 ( V_4 , V_127 ) ;
} else if ( V_127 == V_128 ) {
int V_129 ;
for ( V_129 = 0 ; V_129 < V_128 ; V_129 ++ )
F_20 ( V_4 , V_129 + 1 ) ;
}
}
static void F_31 ( struct V_74 * V_12 , int V_127 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_82 * V_83 = & ( V_4 -> V_12 -> V_83 ) ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
F_26 ( V_4 -> V_12 , L_6 ) ;
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_130 ) ;
F_2 ( V_46 | V_48 ,
& V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_127 ) ;
V_77 = F_24 ( V_12 , & V_79 ) ;
if ( ! V_77 )
return;
V_79 -> V_88 |= V_94 ;
V_79 -> V_64 [ 1 ] = V_131 ;
V_83 -> V_132 ++ ;
V_83 -> V_108 ++ ;
F_27 ( V_77 ) ;
}
static int F_32 ( struct V_74 * V_12 , T_2 V_133 , int V_134 )
{
T_2 V_135 ;
T_4 V_136 ;
int V_137 = 0 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_82 * V_83 = & ( V_4 -> V_12 -> V_83 ) ;
int V_52 ;
T_2 V_50 ;
T_5 V_138 ;
do {
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_133 ) ;
V_135 = F_3 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ) ;
if ( V_135 & V_67 )
break;
if ( V_135 & V_130 ) {
F_31 ( V_12 , V_133 ) ;
V_137 ++ ;
V_134 -- ;
V_133 ++ ;
continue;
} else if ( ! ( V_135 & V_70 ) ) {
V_133 ++ ;
continue;
}
V_77 = F_33 ( V_4 -> V_12 , & V_79 ) ;
if ( ! V_77 ) {
F_6 ( V_12 , L_7 ) ;
return V_137 ;
}
V_50 = F_3 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_50 ) ;
if ( V_50 & V_139 ) {
V_136 = ( F_3 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_63 ) & 0xffff ) ;
V_136 |= ( ( ( V_50 ) & 0x1fff ) << 16 ) ;
V_79 -> V_88 = V_136 | V_140 ;
} else {
V_136 = ( V_50 >> 2 ) & V_141 ;
V_79 -> V_88 = V_136 ;
}
if ( V_50 & V_69 )
V_79 -> V_88 |= V_142 ;
V_79 -> V_121 = F_34 ( ( F_3 ( & V_4 -> V_8 ->
V_43 [ 0 ] . V_49 ) ) & 0xF ) ;
for ( V_52 = 0 ; V_52 < V_79 -> V_121 ; V_52 += 2 ) {
V_138 = F_35 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_64 [ V_52 / 2 ] ) ;
V_79 -> V_64 [ V_52 ] = V_138 ;
V_79 -> V_64 [ V_52 + 1 ] = V_138 >> 8 ;
}
F_27 ( V_77 ) ;
V_137 ++ ;
V_83 -> V_119 ++ ;
V_134 -- ;
V_83 -> V_120 += V_79 -> V_121 ;
F_30 ( V_4 , V_133 ) ;
V_133 ++ ;
} while ( V_134 > 0 );
return V_137 ;
}
static void F_36 ( struct V_74 * V_12 , T_2 V_143 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_82 * V_83 = & ( V_4 -> V_12 -> V_83 ) ;
T_2 V_144 ;
F_37 ( V_12 , V_143 - V_54 - 1 ) ;
F_2 ( V_42 | V_145 ,
& V_4 -> V_8 -> V_43 [ 1 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_45 , V_143 ) ;
V_144 = F_34 ( F_3 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_49 ) &
V_146 ) ;
V_83 -> V_147 += V_144 ;
V_83 -> V_148 ++ ;
if ( V_143 == V_57 )
F_38 ( V_12 ) ;
}
static int F_39 ( struct V_149 * V_125 , int V_134 )
{
struct V_74 * V_12 = V_125 -> V_150 ;
struct V_3 * V_4 = F_23 ( V_12 ) ;
T_2 V_143 ;
T_2 V_151 ;
int V_152 = V_134 ;
V_143 = F_15 ( V_4 ) ;
if ( ! V_143 )
goto V_153;
if ( V_143 == V_154 ) {
V_151 = F_3 ( & V_4 -> V_8 -> V_155 ) ;
if ( ( V_151 & ( V_86 | V_104 ) ) &&
( ( V_151 & V_104 ) != V_104 ) ) {
F_22 ( V_12 , V_151 ) ;
V_134 -- ;
}
if ( V_151 & ( V_156 | V_157 ) )
F_4 ( & V_4 -> V_8 -> V_155 ,
V_151 & ( V_156 | V_157 ) ) ;
V_143 = F_15 ( V_4 ) ;
}
if ( V_134 == 0 )
goto V_153;
if ( ( V_143 >= V_53 ) && ( V_143 <= V_54 ) ) {
V_134 -= F_32 ( V_12 , V_143 , V_134 ) ;
} else if ( ( V_143 >= V_56 ) &&
( V_143 <= V_57 ) ) {
F_36 ( V_12 , V_143 ) ;
}
V_153:
F_40 ( V_125 ) ;
F_11 ( V_4 , V_32 ) ;
return V_152 - V_134 ;
}
static int F_41 ( struct V_74 * V_12 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
const struct V_158 * V_159 = & V_4 -> V_16 . V_160 ;
T_2 V_161 ;
T_2 V_162 ;
F_1 ( & V_4 -> V_8 -> V_9 , V_163 ) ;
V_161 = ( V_159 -> V_164 - 1 ) & V_165 ;
V_161 |= ( V_159 -> V_166 - 1 ) << V_167 ;
V_161 |= ( V_159 -> V_168 + V_159 -> V_169 - 1 ) << V_170 ;
V_161 |= ( V_159 -> V_171 - 1 ) << V_172 ;
V_162 = ( ( V_159 -> V_164 - 1 ) & V_173 ) >> V_174 ;
F_2 ( V_161 , & V_4 -> V_8 -> V_175 ) ;
F_2 ( V_162 , & V_4 -> V_8 -> V_176 ) ;
F_4 ( & V_4 -> V_8 -> V_9 , V_163 ) ;
return 0 ;
}
static void F_42 ( struct V_74 * V_12 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
if ( V_4 -> V_16 . V_85 != V_177 )
F_21 ( V_4 ) ;
F_41 ( V_12 ) ;
F_7 ( V_4 ) ;
F_14 ( V_4 , 1 ) ;
F_13 ( V_4 , 1 ) ;
F_5 ( V_4 , V_7 ) ;
V_4 -> V_16 . V_85 = V_178 ;
return;
}
static int F_43 ( struct V_74 * V_12 , enum V_179 V_6 )
{
int V_180 = 0 ;
switch ( V_6 ) {
case V_181 :
F_42 ( V_12 ) ;
F_38 ( V_12 ) ;
break;
default:
V_180 = - V_182 ;
break;
}
return V_180 ;
}
static int F_44 ( struct V_74 * V_12 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
int V_183 ;
V_183 = F_45 ( V_4 -> V_150 -> V_122 , F_28 , V_184 ,
V_12 -> V_185 , V_12 ) ;
if ( V_183 ) {
F_6 ( V_12 , L_8 ) ;
goto V_186;
}
V_183 = F_46 ( V_12 ) ;
if ( V_183 ) {
F_6 ( V_12 , L_9 , V_183 ) ;
goto V_187;
}
F_18 ( V_4 ) ;
F_42 ( V_12 ) ;
F_47 ( & V_4 -> V_125 ) ;
F_48 ( V_12 ) ;
return 0 ;
V_187:
F_49 ( V_4 -> V_150 -> V_122 , V_12 ) ;
V_186:
F_19 ( V_4 ) ;
return V_183 ;
}
static int F_50 ( struct V_74 * V_12 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
F_51 ( V_12 ) ;
F_52 ( & V_4 -> V_125 ) ;
F_19 ( V_4 ) ;
F_49 ( V_4 -> V_150 -> V_122 , V_12 ) ;
F_53 ( V_12 ) ;
V_4 -> V_16 . V_85 = V_177 ;
return 0 ;
}
static T_6 F_54 ( struct V_76 * V_77 , struct V_74 * V_12 )
{
struct V_3 * V_4 = F_23 ( V_12 ) ;
struct V_78 * V_79 = (struct V_78 * ) V_77 -> V_64 ;
int V_188 ;
int V_52 ;
T_2 V_50 ;
if ( F_55 ( V_12 , V_77 ) )
return V_189 ;
V_188 = V_4 -> V_190 ;
if ( V_4 -> V_190 == V_57 ) {
if ( F_3 ( & V_4 -> V_8 -> V_191 ) & V_192 )
F_51 ( V_12 ) ;
V_4 -> V_190 = V_56 ;
} else {
V_4 -> V_190 ++ ;
}
F_1 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_44 , V_193 ) ;
if ( V_79 -> V_88 & V_140 ) {
F_2 ( V_79 -> V_88 & 0xffff , & V_4 -> V_8 -> V_43 [ 1 ] . V_63 ) ;
V_50 = ( ( V_79 -> V_88 >> 16 ) & 0x1fff ) | V_139 ;
} else {
F_2 ( 0 , & V_4 -> V_8 -> V_43 [ 1 ] . V_63 ) ;
V_50 = ( V_79 -> V_88 & V_141 ) << 2 ;
}
V_50 |= V_51 ;
if ( ! ( V_79 -> V_88 & V_142 ) )
V_50 |= V_69 ;
F_2 ( V_50 , & V_4 -> V_8 -> V_43 [ 1 ] . V_50 ) ;
for ( V_52 = 0 ; V_52 < V_79 -> V_121 ; V_52 += 2 ) {
F_56 ( V_79 -> V_64 [ V_52 ] | ( V_79 -> V_64 [ V_52 + 1 ] << 8 ) ,
& V_4 -> V_8 -> V_43 [ 1 ] . V_64 [ V_52 / 2 ] ) ;
}
F_57 ( V_77 , V_12 , V_188 - V_54 - 1 ) ;
F_2 ( V_79 -> V_121 | V_70 | V_72 |
V_40 , & V_4 -> V_8 -> V_43 [ 1 ] . V_49 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 1 ] . V_45 , V_188 ) ;
return V_189 ;
}
static void T_7 F_58 ( struct V_194 * V_195 )
{
struct V_74 * V_12 = F_59 ( V_195 ) ;
struct V_3 * V_4 = F_23 ( V_12 ) ;
F_60 ( V_4 -> V_12 ) ;
if ( V_4 -> V_196 )
F_61 ( V_4 -> V_150 ) ;
F_62 ( V_195 ) ;
F_63 ( V_195 ) ;
F_64 ( V_195 , NULL ) ;
F_21 ( V_4 ) ;
F_65 ( V_195 , V_4 -> V_8 ) ;
F_66 ( V_4 -> V_12 ) ;
}
static void F_67 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_8 -> V_9 , V_33 ) ;
F_1 ( & V_4 -> V_8 -> V_9 ,
( ( V_4 -> V_197 & V_198 ) << 1 ) ) ;
}
static T_2 F_68 ( struct V_3 * V_4 )
{
return ( F_3 ( & V_4 -> V_8 -> V_9 ) & V_33 ) >> 1 ;
}
static T_2 F_69 ( struct V_3 * V_4 , T_2 V_35 ,
enum V_37 V_38 )
{
T_2 V_39 , V_199 ;
if ( V_38 )
V_39 = V_41 ;
else
V_39 = V_40 ;
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ V_38 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_45 , V_35 ) ;
if ( ( ( F_3 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_50 ) ) & V_51 ) &&
( ( F_3 ( & V_4 -> V_8 -> V_43 [ V_38 ] . V_49 ) ) & V_39 ) )
V_199 = 1 ;
else
V_199 = 0 ;
return V_199 ;
}
static void F_70 ( struct V_3 * V_4 ,
T_2 V_200 , int V_36 )
{
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_200 ) ;
F_2 ( V_46 | V_48 ,
& V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
if ( V_36 )
F_4 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ,
V_67 ) ;
else
F_1 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 , V_67 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_200 ) ;
}
static T_2 F_71 ( struct V_3 * V_4 , T_2 V_200 )
{
T_2 V_201 ;
F_2 ( V_42 , & V_4 -> V_8 -> V_43 [ 0 ] . V_44 ) ;
F_8 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_45 , V_200 ) ;
if ( F_3 ( & V_4 -> V_8 -> V_43 [ 0 ] . V_49 ) & V_67 )
V_201 = 0 ;
else
V_201 = 1 ;
return V_201 ;
}
static int F_72 ( struct V_3 * V_4 )
{
return ( F_3 ( & V_4 -> V_8 -> V_202 ) & 0xffff ) |
( F_3 ( & V_4 -> V_8 -> V_191 ) << 16 ) ;
}
static int F_73 ( struct V_194 * V_195 , T_8 V_85 )
{
int V_52 ;
int V_183 ;
T_2 V_203 ;
int V_25 = V_26 ;
struct V_74 * V_150 = F_59 ( V_195 ) ;
struct V_3 * V_4 = F_23 ( V_150 ) ;
F_5 ( V_4 , V_11 ) ;
V_4 -> V_16 . V_85 = V_177 ;
while ( V_25 ) {
V_203 = F_72 ( V_4 ) ;
if ( ! V_203 )
break;
V_25 -- ;
F_9 ( 1 ) ;
}
if ( ! V_25 )
F_74 ( & V_195 -> V_150 , L_10 , V_13 ) ;
V_4 -> V_197 = F_68 ( V_4 ) ;
F_11 ( V_4 , V_30 ) ;
for ( V_52 = V_56 ; V_52 <= V_57 ; V_52 ++ )
V_4 -> V_204 [ V_52 - 1 ] = F_69 ( V_4 , V_52 ,
V_58 ) ;
F_14 ( V_4 , 0 ) ;
for ( V_52 = V_53 ; V_52 <= V_54 ; V_52 ++ ) {
V_4 -> V_205 [ V_52 - 1 ] = F_69 ( V_4 , V_52 ,
V_55 ) ;
V_4 -> V_206 [ V_52 - 1 ] = F_71 ( V_4 , V_52 ) ;
}
F_13 ( V_4 , 0 ) ;
V_183 = F_75 ( V_195 ) ;
if ( V_183 ) {
F_74 ( & V_195 -> V_150 , L_11 ) ;
} else {
F_76 ( V_195 , V_207 , 0 ) ;
F_63 ( V_195 ) ;
F_77 ( V_195 , F_78 ( V_195 , V_85 ) ) ;
}
return V_183 ;
}
static int F_79 ( struct V_194 * V_195 )
{
int V_52 ;
int V_183 ;
struct V_74 * V_150 = F_59 ( V_195 ) ;
struct V_3 * V_4 = F_23 ( V_150 ) ;
F_77 ( V_195 , V_208 ) ;
F_80 ( V_195 ) ;
V_183 = F_81 ( V_195 ) ;
if ( V_183 ) {
F_74 ( & V_195 -> V_150 , L_12 ) ;
return V_183 ;
}
F_76 ( V_195 , V_207 , 0 ) ;
V_4 -> V_16 . V_85 = V_178 ;
F_11 ( V_4 , V_30 ) ;
F_5 ( V_4 , V_11 ) ;
F_17 ( V_4 ) ;
F_41 ( V_150 ) ;
F_7 ( V_4 ) ;
for ( V_52 = V_56 ; V_52 <= V_57 ; V_52 ++ )
F_12 ( V_4 , V_52 , V_4 -> V_204 [ V_52 - 1 ] , V_58 ) ;
for ( V_52 = V_53 ; V_52 <= V_54 ; V_52 ++ ) {
F_70 ( V_4 , V_52 , V_4 -> V_206 [ V_52 - 1 ] ) ;
F_12 ( V_4 , V_52 , V_4 -> V_205 [ V_52 - 1 ] , V_55 ) ;
}
F_67 ( V_4 ) ;
F_5 ( V_4 , V_7 ) ;
return V_183 ;
}
static int F_82 ( const struct V_74 * V_150 ,
struct V_209 * V_210 )
{
struct V_3 * V_4 = F_23 ( V_150 ) ;
T_2 V_80 = F_3 ( & V_4 -> V_8 -> V_80 ) ;
V_210 -> V_211 = V_80 & V_97 ;
V_210 -> V_212 = ( V_80 & V_95 ) >> 8 ;
return 0 ;
}
static int T_9 F_83 ( struct V_194 * V_195 ,
const struct V_213 * V_136 )
{
struct V_74 * V_12 ;
struct V_3 * V_4 ;
int V_214 ;
void T_1 * V_1 ;
V_214 = F_81 ( V_195 ) ;
if ( V_214 ) {
F_74 ( & V_195 -> V_150 , L_13 , V_214 ) ;
goto V_215;
}
V_214 = F_84 ( V_195 , V_216 ) ;
if ( V_214 ) {
F_74 ( & V_195 -> V_150 , L_14 , V_214 ) ;
goto V_217;
}
V_1 = F_85 ( V_195 , 1 , 0 ) ;
if ( ! V_1 ) {
V_214 = - V_218 ;
F_74 ( & V_195 -> V_150 , L_15 ) ;
goto V_219;
}
V_12 = F_86 ( sizeof( struct V_3 ) , V_57 ) ;
if ( ! V_12 ) {
V_214 = - V_220 ;
F_74 ( & V_195 -> V_150 , L_16 ) ;
goto V_221;
}
V_4 = F_23 ( V_12 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_8 = V_1 ;
V_4 -> V_150 = V_195 ;
V_4 -> V_16 . V_222 = & V_223 ;
V_4 -> V_16 . V_224 = F_43 ;
V_4 -> V_16 . V_225 = F_82 ;
V_4 -> V_16 . V_226 = V_18 |
V_20 ;
V_4 -> V_190 = V_56 ;
V_12 -> V_122 = V_195 -> V_122 ;
V_12 -> V_227 |= V_228 ;
F_64 ( V_195 , V_12 ) ;
F_87 ( V_12 , & V_195 -> V_150 ) ;
V_12 -> V_229 = & V_230 ;
V_4 -> V_16 . clock . V_231 = V_232 ;
F_88 ( V_12 , & V_4 -> V_125 , F_39 , V_54 ) ;
V_214 = F_89 ( V_4 -> V_150 ) ;
if ( V_214 ) {
F_6 ( V_12 , L_17 ) ;
V_4 -> V_196 = 0 ;
} else {
F_6 ( V_12 , L_18 ) ;
F_90 ( V_195 ) ;
V_4 -> V_196 = 1 ;
}
V_214 = F_91 ( V_12 ) ;
if ( V_214 ) {
F_74 ( & V_195 -> V_150 , L_19 , V_214 ) ;
goto V_233;
}
return 0 ;
V_233:
if ( V_4 -> V_196 )
F_61 ( V_4 -> V_150 ) ;
F_66 ( V_12 ) ;
V_221:
F_65 ( V_195 , V_1 ) ;
V_219:
F_62 ( V_195 ) ;
V_217:
F_63 ( V_195 ) ;
V_215:
return V_214 ;
}
static int T_10 F_92 ( void )
{
return F_93 ( & V_234 ) ;
}
static void T_11 F_94 ( void )
{
F_95 ( & V_234 ) ;
}
