static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_14 . V_15 ;
struct V_16 * V_17 = & V_10 -> V_14 . V_18 ;
int V_19 = V_4 - V_10 -> V_4 . V_20 , V_21 ;
unsigned long V_22 ;
F_2 ( & V_4 -> V_23 ) ;
if ( V_4 -> V_7 )
V_17 -> V_24 ( V_2 , V_19 ) ;
if ( V_7 )
V_17 -> V_25 ( V_2 , V_19 , V_5 , V_6 , V_7 , V_8 ) ;
F_3 ( & V_10 -> V_26 , V_22 ) ;
V_13 -> V_27 ( V_2 , false ) ;
V_13 -> V_28 ( V_2 , false ) ;
F_4 ( V_2 ) ;
V_17 -> V_29 ( V_2 , V_19 ) ;
for ( V_21 = 0 ; V_21 < V_30 ; V_21 ++ ) {
if ( V_10 -> V_31 [ V_21 ] && V_10 -> V_31 [ V_21 ] -> V_29 )
V_10 -> V_31 [ V_21 ] -> V_29 ( V_2 , V_19 ) ;
}
V_13 -> V_28 ( V_2 , true ) ;
V_13 -> V_27 ( V_2 , true ) ;
F_5 ( & V_10 -> V_26 , V_22 ) ;
}
static struct V_3 *
F_6 ( struct V_1 * V_2 , int V_19 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_3 * V_4 = & V_10 -> V_4 . V_20 [ V_19 ] ;
F_7 ( & V_10 -> V_4 . V_32 ) ;
if ( ! V_4 -> V_33 &&
( ! V_4 -> V_23 || F_8 ( V_4 -> V_23 ) ) )
V_4 -> V_33 = true ;
else
V_4 = NULL ;
F_9 ( & V_10 -> V_4 . V_32 ) ;
return V_4 ;
}
void
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_34 * V_23 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_4 ) {
F_7 ( & V_10 -> V_4 . V_32 ) ;
if ( V_23 ) {
V_4 -> V_23 = V_23 ;
F_11 ( V_23 ) ;
}
V_4 -> V_33 = false ;
F_9 ( & V_10 -> V_4 . V_32 ) ;
}
}
struct V_3 *
F_12 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_16 * V_17 = & V_10 -> V_14 . V_18 ;
struct V_3 * V_4 , * V_35 = NULL ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_36 ; V_19 ++ ) {
V_4 = F_6 ( V_2 , V_19 ) ;
if ( V_7 && ! V_35 ) {
V_35 = V_4 ;
continue;
} else if ( V_4 && V_4 -> V_7 ) {
F_1 ( V_2 , V_4 , 0 , 0 , 0 , 0 ) ;
}
F_10 ( V_2 , V_4 , NULL ) ;
}
if ( V_35 )
F_1 ( V_2 , V_35 , V_5 , V_6 ,
V_7 , V_8 ) ;
return V_35 ;
}
void
F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_14 ( & V_10 -> V_37 . V_38 ) ;
F_15 ( V_10 ) ;
if ( V_10 -> V_39 >= 0 ) {
F_16 ( V_10 -> V_39 ,
F_17 ( V_2 -> V_40 , 1 ) ,
F_18 ( V_2 -> V_40 , 1 ) , V_41 ) ;
V_10 -> V_39 = - 1 ;
}
}
void
F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
if ( F_21 ( V_2 ) && V_2 -> V_42 ) {
struct V_43 * V_44 , * V_45 ;
F_22 (entry, tempe, &dev->agp->memory, head) {
if ( V_44 -> V_46 )
F_23 ( V_44 -> V_47 ) ;
F_24 ( V_44 -> V_47 , V_44 -> V_48 ) ;
F_25 ( V_44 ) ;
}
F_26 ( & V_2 -> V_42 -> V_47 ) ;
if ( V_2 -> V_42 -> V_49 )
F_27 ( V_2 ) ;
V_2 -> V_42 -> V_49 = 0 ;
V_2 -> V_42 -> V_50 = 0 ;
}
}
static T_1
F_28 ( struct V_1 * V_2 )
{
T_1 V_51 = F_29 ( V_2 , V_52 ) ;
if ( V_51 & 0x00000100 )
return ( ( ( V_51 >> 12 ) & 0xf ) * 2 + 2 ) * 1024 * 1024 ;
switch ( V_51 & V_53 ) {
case V_54 :
return 32 * 1024 * 1024 ;
case V_55 :
return 16 * 1024 * 1024 ;
case V_56 :
return 8 * 1024 * 1024 ;
case V_57 :
return 4 * 1024 * 1024 ;
}
return 0 ;
}
static T_1
F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_58 * V_59 ;
T_1 V_60 ;
V_59 = F_31 ( 0 , F_32 ( 0 , 1 ) ) ;
if ( ! V_59 ) {
F_33 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_10 -> V_8 & V_61 ) {
F_34 ( V_59 , 0x7C , & V_60 ) ;
return ( V_62 ) ( ( ( V_60 >> 6 ) & 31 ) + 1 ) * 1024 * 1024 ;
} else
if ( V_10 -> V_8 & V_63 ) {
F_34 ( V_59 , 0x84 , & V_60 ) ;
return ( V_62 ) ( ( ( V_60 >> 4 ) & 127 ) + 1 ) * 1024 * 1024 ;
}
F_33 ( V_2 , L_2 ) ;
return 0 ;
}
int
F_35 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_64 == V_65 ) {
V_10 -> V_66 = F_28 ( V_2 ) ;
} else
if ( V_10 -> V_8 & ( V_61 | V_63 ) ) {
V_10 -> V_66 = F_30 ( V_2 ) ;
} else
if ( V_10 -> V_64 < V_67 ) {
V_10 -> V_66 = F_29 ( V_2 , V_68 ) ;
V_10 -> V_66 &= V_69 ;
}
if ( V_10 -> V_66 )
return 0 ;
return - V_70 ;
}
bool
F_36 ( struct V_1 * V_2 , T_2 V_71 )
{
if ( ! ( V_71 & V_72 ) )
return true ;
return false ;
}
static unsigned long
F_37 ( struct V_1 * V_2 , unsigned long V_73 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_74 == 0x18 )
V_73 &= ~ V_75 ;
if ( V_76 > 0 ) {
bool V_77 = V_73 & 0x8 ;
int V_78 = V_77 ? V_76 / 4 : V_76 ;
V_73 = ( V_73 & ~ 0x7 ) | ( V_78 & 0x7 ) ;
}
return V_73 ;
}
int
F_38 ( struct V_1 * V_2 )
{
#if V_79
T_1 V_80 , V_81 ;
int V_82 ;
if ( ( F_29 ( V_2 , V_83 ) |
V_2 -> V_42 -> V_73 ) & V_75 ) {
struct V_84 V_85 ;
struct V_86 V_73 ;
V_82 = V_84 ( V_2 , & V_85 ) ;
if ( V_82 )
return V_82 ;
V_73 . V_73 = F_37 ( V_2 , V_85 . V_73 ) & ~ V_75 ;
V_82 = F_39 ( V_2 , V_73 ) ;
if ( V_82 )
return V_82 ;
}
V_80 = F_29 ( V_2 , V_87 ) ;
F_40 ( V_2 , V_87 , V_80 & ~ 0x4 ) ;
F_40 ( V_2 , V_83 , 0 ) ;
V_81 = F_29 ( V_2 , V_88 ) ;
if ( V_81 & V_89 ) {
F_40 ( V_2 , V_88 ,
V_81 & ~ V_89 ) ;
F_40 ( V_2 , V_88 , F_29 ( V_2 , V_88 ) |
V_89 ) ;
}
F_40 ( V_2 , V_87 , V_80 ) ;
#endif
return 0 ;
}
int
F_41 ( struct V_1 * V_2 )
{
#if V_79
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_84 V_85 ;
struct V_86 V_73 ;
int V_82 ;
if ( ! V_2 -> V_42 -> V_49 ) {
V_82 = F_42 ( V_2 ) ;
if ( V_82 ) {
F_33 ( V_2 , L_3 , V_82 ) ;
return V_82 ;
}
}
F_38 ( V_2 ) ;
V_82 = V_84 ( V_2 , & V_85 ) ;
if ( V_82 ) {
F_33 ( V_2 , L_4 , V_82 ) ;
return V_82 ;
}
V_73 . V_73 = F_37 ( V_2 , V_85 . V_73 ) ;
V_82 = F_39 ( V_2 , V_73 ) ;
if ( V_82 ) {
F_33 ( V_2 , L_5 , V_82 ) ;
return V_82 ;
}
V_10 -> V_90 . type = V_91 ;
V_10 -> V_90 . V_92 = V_85 . V_93 ;
V_10 -> V_90 . V_94 = V_85 . V_95 ;
#endif
return 0 ;
}
int
F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_96 * V_38 = & V_10 -> V_37 . V_38 ;
int V_82 , V_97 ;
V_97 = 32 ;
if ( V_10 -> V_64 >= V_67 ) {
if ( F_44 ( V_2 -> V_40 , F_45 ( 40 ) ) )
V_97 = 40 ;
} else
if ( 0 && F_46 ( V_2 ) &&
V_10 -> V_74 > 0x40 &&
V_10 -> V_74 != 0x45 ) {
if ( F_44 ( V_2 -> V_40 , F_45 ( 39 ) ) )
V_97 = 39 ;
}
V_82 = F_47 ( V_2 -> V_40 , F_45 ( V_97 ) ) ;
if ( V_82 )
return V_82 ;
V_10 -> V_98 = F_17 ( V_2 -> V_40 , 1 ) ;
V_82 = F_48 ( V_10 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_49 ( & V_10 -> V_37 . V_38 ,
V_10 -> V_37 . V_99 . V_100 . V_101 ,
& V_102 , V_103 ,
V_97 <= 32 ? true : false ) ;
if ( V_82 ) {
F_33 ( V_2 , L_6 , V_82 ) ;
return V_82 ;
}
if ( V_10 -> V_64 >= V_67 ) {
V_10 -> V_104 = 1 * 1024 * 1024 ;
} else
if ( V_10 -> V_64 >= V_105 ) {
T_2 V_106 = F_50 ( ( F_29 ( V_2 , 0x001540 ) & 0x0000ff00 ) >> 8 ) ;
T_2 V_107 ;
if ( V_10 -> V_74 == 0x40 ) V_107 = 0x6aa0 * V_106 ;
else if ( V_10 -> V_74 < 0x43 ) V_107 = 0x4f00 * V_106 ;
else if ( F_51 ( V_2 ) ) V_107 = 0x4980 * V_106 ;
else V_107 = 0x4a40 * V_106 ;
V_107 += 16 * 1024 ;
V_107 *= V_10 -> V_14 . V_15 . V_108 ;
if ( F_46 ( V_2 ) )
V_107 += 512 * 1024 ;
V_107 += 512 * 1024 ;
V_10 -> V_104 = F_52 ( V_107 , 4096 ) ;
} else {
V_10 -> V_104 = 512 * 1024 ;
}
V_82 = V_10 -> V_14 . V_109 . V_110 ( V_2 ) ;
if ( V_82 )
return V_82 ;
F_53 ( V_2 , L_7 , ( int ) ( V_10 -> V_66 >> 20 ) ) ;
if ( V_10 -> V_111 ) {
F_53 ( V_2 , L_8 ,
V_10 -> V_111 ) ;
}
V_10 -> V_112 = V_10 -> V_66 ;
V_10 -> V_113 = V_10 -> V_112 ;
if ( V_10 -> V_113 > F_18 ( V_2 -> V_40 , 1 ) )
V_10 -> V_113 = F_18 ( V_2 -> V_40 , 1 ) ;
V_10 -> V_113 >>= V_114 ;
V_10 -> V_112 -= V_10 -> V_104 ;
V_10 -> V_115 = V_10 -> V_112 ;
V_82 = F_54 ( V_38 , V_116 ,
V_10 -> V_112 >> V_114 ) ;
if ( V_82 ) {
F_33 ( V_2 , L_9 , V_82 ) ;
return V_82 ;
}
if ( V_10 -> V_64 < V_67 ) {
V_82 = F_55 ( V_2 , NULL , 256 * 1024 , 0 , V_117 ,
0 , 0 , & V_10 -> V_118 ) ;
if ( V_82 == 0 )
V_82 = F_56 ( V_10 -> V_118 ,
V_117 ) ;
if ( V_82 ) {
F_57 ( V_2 , L_10 ) ;
F_58 ( NULL , & V_10 -> V_118 ) ;
}
}
V_10 -> V_39 = F_59 ( F_17 ( V_2 -> V_40 , 1 ) ,
F_18 ( V_2 -> V_40 , 1 ) ,
V_41 ) ;
return 0 ;
}
int
F_60 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_96 * V_38 = & V_10 -> V_37 . V_38 ;
int V_82 ;
V_10 -> V_90 . type = V_119 ;
#if ! F_61 ( V_120 ) && ! F_61 ( V_121 )
if ( F_62 ( V_2 ) && V_2 -> V_42 && V_76 ) {
V_82 = F_41 ( V_2 ) ;
if ( V_82 )
F_33 ( V_2 , L_11 , V_82 ) ;
}
#endif
if ( V_10 -> V_90 . type == V_119 ) {
V_82 = F_63 ( V_2 ) ;
if ( V_82 ) {
F_33 ( V_2 , L_12 , V_82 ) ;
return V_82 ;
}
}
F_53 ( V_2 , L_13 ,
( int ) ( V_10 -> V_90 . V_94 >> 20 ) ) ;
V_10 -> V_90 . V_122 = V_10 -> V_90 . V_94 ;
V_82 = F_54 ( V_38 , V_123 ,
V_10 -> V_90 . V_94 >> V_114 ) ;
if ( V_82 ) {
F_33 ( V_2 , L_14 , V_82 ) ;
return V_82 ;
}
return 0 ;
}
void
F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_124 * V_125 = & V_10 -> V_14 . V_125 ;
struct V_126 * V_127 = & V_125 -> V_127 ;
struct V_128 * V_129 = & V_10 -> V_130 ;
struct V_131 V_132 ;
T_3 V_133 , V_134 , V_135 ;
T_3 V_136 ;
T_3 V_137 ;
T_3 V_138 ;
T_3 V_139 ;
T_3 V_140 , V_141 , V_142 , V_143 , V_144 ;
T_3 V_145 , V_146 , V_147 , V_148 ;
T_3 V_149 = 0 ;
T_3 * V_60 = NULL , * V_44 ;
int V_19 , V_150 , V_151 ;
if ( V_129 -> type == V_152 ) {
if ( F_65 ( V_2 , 'P' , & V_132 ) )
return;
if ( V_132 . V_153 == 1 )
V_60 = F_66 ( V_129 , V_132 . V_154 [ 4 ] ) ;
else
if ( V_132 . V_153 == 2 )
V_60 = F_66 ( V_129 , V_132 . V_154 [ 8 ] ) ;
else {
F_57 ( V_2 , L_15 , V_132 . V_153 ) ;
}
} else {
F_67 ( V_2 , L_16 ) ;
return;
}
if ( ! V_60 ) {
F_67 ( V_2 , L_17 ) ;
return;
}
if ( V_60 [ 0 ] != 0x10 ) {
F_57 ( V_2 , L_18 , V_60 [ 0 ] ) ;
return;
}
V_151 = V_60 [ 2 ] ;
V_150 = V_60 [ 3 ] ;
if ( V_150 < 15 ) {
F_33 ( V_2 , L_19 , V_60 [ 3 ] ) ;
return;
}
V_127 -> V_155 =
F_68 ( V_151 , sizeof( * V_127 -> V_155 ) , V_156 ) ;
if ( ! V_127 -> V_155 )
return;
if ( V_10 -> V_64 >= V_105 && V_10 -> V_74 < 0x98 ) {
V_149 = ( F_29 ( V_2 , 0x100228 ) & 0x0f000000 ) >> 24 ;
}
V_44 = V_60 + V_60 [ 1 ] ;
for ( V_19 = 0 ; V_19 < V_151 ; V_19 ++ , V_44 += V_150 ) {
struct V_157 * V_155 = & V_125 -> V_127 . V_155 [ V_19 ] ;
if ( V_44 [ 0 ] == 0 )
continue;
V_145 = 1 ;
V_146 = 1 ;
V_147 = 0 ;
V_148 = 0 ;
switch ( F_69 ( V_150 , 22 ) ) {
case 22 :
V_148 = V_44 [ 21 ] ;
case 21 :
V_147 = V_44 [ 20 ] ;
case 20 :
V_146 = V_44 [ 19 ] ;
case 19 :
V_145 = V_44 [ 18 ] ;
default:
V_133 = V_44 [ 0 ] ;
V_134 = V_44 [ 1 ] ;
V_135 = V_44 [ 2 ] ;
V_136 = V_44 [ 3 ] ;
V_137 = V_44 [ 5 ] ;
V_138 = V_44 [ 7 ] ;
V_139 = V_44 [ 9 ] ;
V_140 = V_44 [ 10 ] ;
V_141 = V_44 [ 11 ] ;
V_142 = V_44 [ 12 ] ;
V_143 = V_44 [ 13 ] ;
V_144 = V_44 [ 14 ] ;
break;
}
V_155 -> V_158 = ( V_139 << 24 | V_138 << 16 | V_137 << 8 | V_136 ) ;
V_155 -> V_159 = ( V_133 + V_146 + 1 + V_149 ) << 24 |
F_70 ( V_145 , ( T_3 ) 1 ) << 16 |
( V_134 + V_146 + 1 + V_149 ) << 8 ;
if ( V_10 -> V_74 == 0xa8 ) {
V_155 -> V_159 |= ( V_135 - 1 ) ;
} else {
V_155 -> V_159 |= ( V_135 + 2 - V_149 ) ;
}
V_155 -> V_160 = ( V_142 << 16 | V_141 << 8 | V_140 ) ;
if ( V_10 -> V_74 >= 0xa3 && V_10 -> V_74 < 0xaa )
V_155 -> V_160 |= ( V_146 - 1 ) << 24 ;
else
V_155 -> V_160 |= V_149 << 24 ;
if ( V_10 -> V_64 == V_105 ) {
V_155 -> V_160 |= 0x20200000 ;
} else if ( V_10 -> V_64 >= V_67 ) {
if ( V_10 -> V_74 < 0x98 ||
( V_10 -> V_74 == 0x98 &&
V_10 -> V_161 <= 0xa1 ) ) {
V_155 -> V_162 = ( 0x14 + V_135 ) << 24 |
0x16 << 16 |
( V_135 - 1 ) << 8 |
( V_135 - 1 ) ;
} else {
V_155 -> V_162 = V_135 - 1 ;
}
V_155 -> V_163 = ( V_147 << 24 | V_148 << 16 |
V_143 << 8 | V_143 ) ;
V_155 -> V_164 = ( V_137 << 24 | V_139 ) ;
V_155 -> V_164 += F_70 ( V_140 , V_141 ) << 16 ;
if ( V_10 -> V_74 < 0x98 ||
( V_10 -> V_74 == 0x98 &&
V_10 -> V_161 <= 0xa1 ) ) {
V_155 -> V_164 |= ( V_135 + 2 ) << 8 ;
} else {
V_155 -> V_164 |= ( V_146 + 6 ) << 8 ;
}
V_155 -> V_165 = 0x202 ;
if ( V_10 -> V_74 < 0x98 ||
( V_10 -> V_74 == 0x98 &&
V_10 -> V_161 <= 0xa1 ) ) {
V_155 -> V_165 |= 0x4000000 | ( V_135 - 1 ) << 16 ;
} else {
}
}
V_155 -> V_166 = V_19 ;
F_67 ( V_2 , L_20 , V_19 ,
V_155 -> V_158 , V_155 -> V_159 ,
V_155 -> V_160 , V_155 -> V_162 ) ;
F_67 ( V_2 , L_21 ,
V_155 -> V_163 , V_155 -> V_164 ,
V_155 -> V_167 , V_155 -> V_165 ) ;
F_67 ( V_2 , L_22 , V_155 -> V_168 ) ;
}
V_127 -> V_169 = V_151 ;
V_127 -> V_170 = ( V_10 -> V_74 <= 0x98 ) ;
}
void
F_71 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_126 * V_60 = & V_10 -> V_14 . V_125 . V_127 ;
F_25 ( V_60 -> V_155 ) ;
}
static int
F_72 ( struct V_171 * V_172 , unsigned long V_173 )
{
struct V_9 * V_10 = F_73 ( V_172 -> V_38 ) ;
struct V_174 * V_175 ;
T_4 V_6 , V_176 , V_107 ;
int V_82 ;
V_107 = ( 256 * 1024 ) ;
V_6 = ( V_173 << V_114 ) - V_107 ;
V_176 = V_10 -> V_177 ;
V_82 = F_74 ( & V_175 , V_107 >> 12 , V_6 >> 12 , V_176 >> 12 ) ;
if ( V_82 )
return V_82 ;
V_172 -> V_178 = V_175 ;
return 0 ;
}
static int
F_75 ( struct V_171 * V_172 )
{
struct V_174 * V_175 = V_172 -> V_178 ;
int V_82 ;
V_82 = F_76 ( & V_175 ) ;
if ( V_82 )
return V_82 ;
V_172 -> V_178 = NULL ;
return 0 ;
}
static void
F_77 ( struct V_171 * V_172 ,
struct V_179 * V_60 )
{
struct V_9 * V_10 = F_73 ( V_172 -> V_38 ) ;
struct V_180 * V_109 = & V_10 -> V_14 . V_109 ;
struct V_181 * V_182 = V_60 -> V_183 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_182 -> V_184 . V_182 ) {
F_78 ( & V_182 -> V_184 ) ;
F_79 ( & V_182 -> V_184 ) ;
}
V_109 -> V_185 ( V_2 , (struct V_181 * * ) & V_60 -> V_183 ) ;
}
static int
F_80 ( struct V_171 * V_172 ,
struct V_186 * V_187 ,
struct V_188 * V_189 ,
struct V_179 * V_60 )
{
struct V_9 * V_10 = F_73 ( V_172 -> V_38 ) ;
struct V_180 * V_109 = & V_10 -> V_14 . V_109 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_190 * V_191 = V_190 ( V_187 ) ;
struct V_181 * V_182 ;
T_2 V_192 = 0 ;
int V_82 ;
if ( V_191 -> V_71 & V_193 )
V_192 = 1 << V_191 -> V_194 . V_182 -> type ;
V_82 = V_109 -> V_195 ( V_2 , V_60 -> V_196 << V_114 ,
V_60 -> V_197 << V_114 , V_192 ,
( V_191 -> V_71 >> 8 ) & 0x3ff , & V_182 ) ;
if ( V_82 ) {
V_60 -> V_183 = NULL ;
return ( V_82 == - V_198 ) ? 0 : V_82 ;
}
V_182 -> V_199 = 12 ;
if ( V_191 -> V_194 . V_182 )
V_182 -> V_199 = V_191 -> V_194 . V_182 -> type ;
V_60 -> V_183 = V_182 ;
V_60 -> V_200 = V_182 -> V_201 >> V_114 ;
return 0 ;
}
void
F_81 ( struct V_171 * V_172 , const char * V_202 )
{
struct V_174 * V_175 = V_172 -> V_178 ;
struct V_203 * V_204 ;
T_2 V_205 = 0 , free = 0 ;
F_82 ( & V_175 -> V_206 ) ;
F_83 (r, &mm->nodes, nl_entry) {
F_84 ( V_207 L_23 ,
V_202 , V_204 -> type , ( ( T_4 ) V_204 -> V_201 << 12 ) ,
( ( ( T_4 ) V_204 -> V_201 + V_204 -> V_208 ) << 12 ) ) ;
V_205 += V_204 -> V_208 ;
if ( ! V_204 -> type )
free += V_204 -> V_208 ;
}
F_85 ( & V_175 -> V_206 ) ;
F_84 ( V_207 L_24 ,
V_202 , ( T_4 ) V_205 << 12 , ( T_4 ) free << 12 ) ;
F_84 ( V_207 L_25 ,
V_202 , V_175 -> V_209 << 12 ) ;
}
static int
F_86 ( struct V_171 * V_172 , unsigned long V_210 )
{
return 0 ;
}
static int
F_87 ( struct V_171 * V_172 )
{
return 0 ;
}
static void
F_88 ( struct V_171 * V_172 ,
struct V_179 * V_60 )
{
struct V_181 * V_182 = V_60 -> V_183 ;
if ( V_182 -> V_184 . V_182 ) {
F_78 ( & V_182 -> V_184 ) ;
F_79 ( & V_182 -> V_184 ) ;
}
V_60 -> V_183 = NULL ;
F_25 ( V_182 ) ;
}
static int
F_89 ( struct V_171 * V_172 ,
struct V_186 * V_187 ,
struct V_188 * V_189 ,
struct V_179 * V_60 )
{
struct V_9 * V_10 = F_73 ( V_187 -> V_38 ) ;
struct V_190 * V_191 = V_190 ( V_187 ) ;
struct V_211 * V_194 = & V_191 -> V_194 ;
struct V_212 * V_213 = V_194 -> V_213 ;
struct V_181 * V_182 ;
int V_82 ;
if ( F_90 ( ( V_60 -> V_196 << V_114 ) >=
V_10 -> V_90 . V_94 ) )
return - V_70 ;
V_182 = F_91 ( sizeof( * V_182 ) , V_156 ) ;
if ( ! V_182 )
return - V_70 ;
if ( V_194 -> V_182 -> type != V_213 -> V_214 ) {
V_82 = F_92 ( V_213 , ( T_4 ) V_194 -> V_182 -> V_208 << 12 ,
V_213 -> V_214 , V_215 ,
& V_182 -> V_184 ) ;
if ( V_82 ) {
F_25 ( V_182 ) ;
return V_82 ;
}
}
V_182 -> V_199 = V_191 -> V_194 . V_182 -> type ;
V_60 -> V_183 = V_182 ;
V_60 -> V_200 = 0 ;
return 0 ;
}
void
F_93 ( struct V_171 * V_172 , const char * V_202 )
{
}
