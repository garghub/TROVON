T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( ( T_1 * ) ( V_2 -> V_4 + V_3 ) ) ;
}
void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( ( T_1 * ) ( V_2 -> V_4 + V_3 ) , V_5 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
long V_6 = V_7 + 2 ;
while ( ! ( F_1 ( V_2 , V_8 ) & V_9 ) ) {
if ( V_6 - V_7 <= 0 ) {
F_6 ( 1 ) ;
return - V_10 ;
}
F_7 ( 1 ) ;
}
return 0 ;
}
T_1 F_8 ( struct V_1 * V_2 , int V_11 )
{
T_1 V_12 ;
if ( F_5 ( V_2 ) )
return - V_10 ;
F_3 ( V_2 , V_13 , V_11 ) ;
if ( F_5 ( V_2 ) )
return - V_10 ;
V_12 = F_1 ( V_2 , V_14 ) ;
return V_12 ;
}
void F_9 ( struct V_1 * V_2 , int V_11 , T_1 V_5 )
{
if ( F_5 ( V_2 ) )
return;
F_3 ( V_2 , V_14 , V_5 ) ;
F_3 ( V_2 , V_13 , V_15 | V_11 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , int V_11 )
{
return F_2 ( ( T_1 * ) ( V_2 -> V_16 + ( V_11 << 2 ) ) ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_11 , T_1 V_5 )
{
F_4 ( ( T_1 * ) ( V_2 -> V_16 + ( V_11 << 2 ) ) , V_5 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , int V_11 )
{
return F_13 ( V_2 -> V_17 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_11 , T_1 V_5 )
{
F_15 ( V_2 -> V_17 , V_11 , V_5 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned int V_22 ;
V_22 = F_17 ( V_21 , 0 ) ;
if ( V_22 != 0 ) {
V_2 -> V_17 = F_18 ( V_21 , V_22 , F_19 ( V_21 , 0 ) ) ;
V_2 -> V_23 = F_12 ;
V_2 -> V_24 = F_14 ;
F_20 ( & V_19 -> V_25 , L_1 , V_22 ) ;
return 0 ;
}
return - 1 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
return - 1 ;
}
static void F_21 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( ! V_2 -> V_30 [ V_28 ] )
break;
else {
F_23 ( V_27 -> V_25 . V_31 , V_2 -> V_32 [ V_28 ] . V_33 ,
V_34 , V_35 ) ;
F_24 ( V_2 -> V_30 [ V_28 ] ) ;
}
}
if ( V_2 -> V_32 )
F_25 ( V_27 -> V_25 . V_31 ,
sizeof( * V_2 -> V_32 ) * V_29 ,
V_2 -> V_32 , V_2 -> V_36 ) ;
if ( V_2 -> V_37 )
F_25 ( V_27 -> V_25 . V_31 ,
sizeof( * V_2 -> V_37 ) * V_38 ,
V_2 -> V_37 , V_2 -> V_39 ) ;
if ( V_2 -> V_30 )
F_26 ( V_2 -> V_30 ) ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_40 * V_41 ;
int V_28 ;
V_2 -> V_30 = F_28 ( sizeof( * V_2 -> V_30 ) * V_29 , V_42 ) ;
if ( ! V_2 -> V_30 ) {
F_29 ( & V_27 -> V_25 ,
L_2 ) ;
goto V_43;
}
V_2 -> V_37 = F_30 ( V_27 -> V_25 . V_31 ,
sizeof( * V_2 -> V_37 ) * V_38 ,
& V_2 -> V_39 , V_42 ) ;
if ( ! V_2 -> V_37 ) {
F_29 ( & V_27 -> V_25 ,
L_3 ) ;
goto V_43;
}
V_2 -> V_32 = F_30 ( V_27 -> V_25 . V_31 ,
sizeof( * V_2 -> V_32 ) * V_29 ,
& V_2 -> V_36 , V_42 ) ;
if ( ! V_2 -> V_32 ) {
F_29 ( & V_27 -> V_25 ,
L_4 ) ;
goto V_43;
}
memset ( V_2 -> V_37 , 0 , sizeof( * V_2 -> V_37 ) * V_38 ) ;
for ( V_28 = 0 ; V_28 < V_38 ; V_28 ++ ) {
V_2 -> V_37 [ V_28 ] . V_44 = V_2 -> V_39 +
sizeof( * V_2 -> V_37 ) * ( ( V_28 + 1 ) % V_38 ) ;
}
memset ( V_2 -> V_32 , 0 , sizeof( * V_2 -> V_32 ) * V_29 ) ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_2 -> V_32 [ V_28 ] . V_44 = V_2 -> V_36 +
sizeof( * V_2 -> V_32 ) * ( ( V_28 + 1 ) % V_29 ) ;
V_41 = F_31 ( V_27 ,
V_34 ) ;
if ( V_41 == 0 ) {
F_29 ( & V_27 -> V_25 , L_5 , V_28 ) ;
goto V_43;
}
V_2 -> V_30 [ V_28 ] = V_41 ;
V_2 -> V_32 [ V_28 ] . V_33 = F_32 ( V_27 -> V_25 . V_31 ,
V_41 -> V_45 ,
V_34 ,
V_35 ) ;
V_2 -> V_32 [ V_28 ] . V_46 = V_34 ;
V_2 -> V_32 [ V_28 ] . V_47 = V_48 ;
}
V_2 -> V_24 ( V_2 , V_49 , 0x10220400 |
V_50 |
V_51 |
V_52 ) ;
V_2 -> V_24 ( V_2 , V_53 , 0xff070000 |
V_50 |
V_51 |
V_52 |
V_54 ) ;
V_2 -> V_24 ( V_2 , V_55 , V_2 -> V_36 ) ;
V_2 -> V_24 ( V_2 , V_56 ,
V_2 -> V_36 + ( sizeof( * V_2 -> V_32 ) * ( V_29 - 1 ) ) ) ;
V_2 -> V_24 ( V_2 , V_57 , V_2 -> V_39 ) ;
return 0 ;
V_43:
F_21 ( V_27 ) ;
return - V_58 ;
}
static int F_33 ( struct V_26 * V_27 , void * V_59 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
if ( V_59 )
memcpy ( V_27 -> V_60 , V_59 , V_61 ) ;
if ( ! F_34 ( V_27 -> V_60 ) )
F_35 ( V_27 -> V_60 ) ;
F_36 ( & V_2 -> V_62 ) ;
F_9 ( V_2 , V_63 ,
( V_27 -> V_60 [ 0 ] ) |
( V_27 -> V_60 [ 1 ] << 8 ) |
( V_27 -> V_60 [ 2 ] << 16 ) |
( V_27 -> V_60 [ 3 ] << 24 ) ) ;
F_9 ( V_2 , V_64 ,
( V_27 -> V_60 [ 4 ] & 0x000000ff ) |
( V_27 -> V_60 [ 5 ] << 8 ) ) ;
F_37 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_38 ( struct V_26 * V_27 , void * V_65 )
{
struct V_66 * V_67 = V_65 ;
return F_33 ( V_27 , V_67 -> V_68 ) ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_69 , V_70 , V_12 ;
int V_28 ;
F_36 ( & V_2 -> V_62 ) ;
if ( V_27 -> V_71 & ( V_72 | V_73 ) ||
F_40 ( V_27 ) > V_74 ) {
V_27 -> V_71 |= V_73 ;
F_9 ( V_2 , V_75 , V_76 ) ;
F_41 ( & V_27 -> V_25 , L_6 ) ;
} else if ( ! F_42 ( V_27 ) ) {
struct V_77 * V_78 ;
V_28 = 0 ;
F_43 (ha, ndev) {
if ( V_28 >= V_74 )
break;
V_69 = ( ( V_78 -> V_67 [ 3 ] << 24 ) |
( V_78 -> V_67 [ 2 ] << 16 ) |
( V_78 -> V_67 [ 1 ] << 8 ) |
( V_78 -> V_67 [ 0 ] ) ) ;
F_9 ( V_2 , V_79 ,
V_69 ) ;
V_70 = ( ( V_78 -> V_67 [ 5 ] << 8 ) |
( V_78 -> V_67 [ 4 ] ) | ( V_28 << 16 ) ) ;
F_9 ( V_2 , V_80 ,
V_70 ) ;
V_28 ++ ;
}
} else {
V_12 = F_8 ( V_2 , V_75 ) ;
F_9 ( V_2 , V_75 ,
V_12 & ~ V_76 ) ;
F_9 ( V_2 , V_79 , 0 ) ;
F_9 ( V_2 , V_80 , 0 ) ;
F_41 ( & V_27 -> V_25 , L_7 ) ;
}
F_37 ( & V_2 -> V_62 ) ;
}
static T_1 F_44 ( struct V_26 * V_27 , T_1 V_81 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_82 * V_83 = & V_84 [ 0 ] ;
int V_11 ;
F_36 ( & V_2 -> V_62 ) ;
while ( V_83 -> V_85 ) {
V_11 = F_8 ( V_2 , V_83 -> V_11 ) & ~ V_83 -> V_86 ;
if ( V_81 & V_83 -> V_85 )
V_11 |= V_83 -> V_86 ;
F_9 ( V_2 , V_83 -> V_11 , V_11 ) ;
V_83 ++ ;
}
V_2 -> V_81 |= V_81 ;
F_37 ( & V_2 -> V_62 ) ;
return 0 ;
}
static void F_45 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_87 ;
T_1 V_12 ;
F_20 ( & V_27 -> V_25 , L_8 , V_88 ) ;
F_36 ( & V_2 -> V_62 ) ;
F_9 ( V_2 , V_89 , V_90 ) ;
V_87 = 1000 ;
while ( F_8 ( V_2 , V_89 ) & V_90 ) {
F_46 ( 1 ) ;
if ( -- V_87 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_9 ) ;
break;
}
}
F_9 ( V_2 , V_91 , V_92 ) ;
V_87 = 1000 ;
while ( F_8 ( V_2 , V_91 ) & V_92 ) {
F_46 ( 1 ) ;
if ( -- V_87 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_10 ) ;
break;
}
}
V_12 = F_8 ( V_2 , V_89 ) ;
F_9 ( V_2 , V_89 , V_12 & ~ V_93 ) ;
V_2 -> V_24 ( V_2 , V_94 , V_95 ) ;
V_87 = 1000 ;
while ( V_2 -> V_23 ( V_2 , V_94 ) & V_95 ) {
F_46 ( 1 ) ;
if ( -- V_87 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_11 ) ;
break;
}
}
V_2 -> V_24 ( V_2 , V_94 , V_96 ) ;
if ( F_27 ( V_27 ) ) {
F_29 ( & V_27 -> V_25 ,
L_12 ) ;
}
F_9 ( V_2 , V_97 , 0 ) ;
F_9 ( V_2 , V_89 , 0 ) ;
F_9 ( V_2 , V_91 , 0 ) ;
F_9 ( V_2 , V_98 , V_99 ) ;
F_37 ( & V_2 -> V_62 ) ;
F_44 ( V_27 ,
V_2 -> V_81 & ~ ( V_100 | V_101 ) ) ;
F_33 ( V_27 , NULL ) ;
F_39 ( V_27 ) ;
if ( F_44 ( V_27 , V_2 -> V_81 ) )
F_29 ( & V_27 -> V_25 , L_13 ) ;
V_27 -> V_102 = V_7 ;
}
void F_47 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_103 * V_104 = V_2 -> V_105 ;
T_1 V_106 ;
int V_107 ;
V_107 = V_104 -> V_108 | ( V_104 -> V_109 << 1 ) | V_104 -> V_110 ;
F_36 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_111 != V_107 ) {
V_106 = F_8 ( V_2 , V_112 ) ;
V_106 &= ~ V_113 ;
switch ( V_104 -> V_108 ) {
case V_114 : V_106 |= V_115 ; break;
case V_116 : V_106 |= V_117 ; break;
case V_118 : V_106 |= V_119 ; break;
}
F_9 ( V_2 , V_112 , V_106 ) ;
V_2 -> V_111 = V_107 ;
F_48 ( V_104 ) ;
}
F_37 ( & V_2 -> V_62 ) ;
}
static void F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_120 * V_121 ;
unsigned int V_122 = 0 ;
V_121 = & V_2 -> V_37 [ V_2 -> V_123 ] ;
V_122 = V_121 -> V_47 ;
while ( V_122 & V_124 ) {
F_23 ( V_27 -> V_25 . V_31 , V_121 -> V_33 , V_121 -> V_46 ,
V_125 ) ;
if ( V_121 -> V_126 )
F_50 ( (struct V_40 * ) V_121 -> V_126 ) ;
V_121 -> V_47 = 0 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_121 -> V_129 = 0 ;
V_121 -> V_126 = 0 ;
V_27 -> V_130 . V_131 ++ ;
V_27 -> V_130 . V_132 += V_121 -> V_46 ;
V_2 -> V_123 ++ ;
if ( V_2 -> V_123 >= V_38 )
V_2 -> V_123 = 0 ;
V_121 = & V_2 -> V_37 [ V_2 -> V_123 ] ;
V_122 = V_121 -> V_47 ;
}
F_51 ( V_27 ) ;
}
static inline int F_52 ( struct V_1 * V_2 , int V_133 )
{
struct V_120 * V_121 ;
int V_134 ;
V_134 = V_2 -> V_135 ;
V_121 = & V_2 -> V_37 [ V_134 ] ;
do {
if ( V_121 -> V_47 )
return V_136 ;
V_134 ++ ;
if ( V_134 >= V_38 )
V_134 = 0 ;
V_121 = & V_2 -> V_37 [ V_134 ] ;
V_133 -- ;
} while ( V_133 >= 0 );
return 0 ;
}
static int F_53 ( struct V_40 * V_41 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_120 * V_121 ;
T_2 V_137 , V_138 ;
int V_139 ;
unsigned long V_133 ;
T_3 * V_140 ;
V_133 = F_54 ( V_41 ) -> V_141 ;
V_140 = & F_54 ( V_41 ) -> V_142 [ 0 ] ;
V_137 = V_2 -> V_39 + sizeof( * V_2 -> V_37 ) * V_2 -> V_135 ;
V_121 = & V_2 -> V_37 [ V_2 -> V_135 ] ;
if ( F_52 ( V_2 , V_133 ) ) {
if ( ! F_55 ( V_27 ) ) {
F_56 ( V_27 ) ;
return V_136 ;
}
return V_136 ;
}
V_121 -> V_47 = 0 ;
if ( V_41 -> V_143 == V_144 ) {
unsigned int V_145 = F_57 ( V_41 ) ;
unsigned int V_146 = V_145 + V_41 -> V_147 ;
V_121 -> V_47 |= 1 ;
V_121 -> V_127 = ( V_145 << 16 ) | V_146 ;
V_121 -> V_128 = 0 ;
}
V_121 -> V_47 |= V_148 ;
V_121 -> V_46 = F_58 ( V_41 ) ;
V_121 -> V_33 = F_32 ( V_27 -> V_25 . V_31 , V_41 -> V_45 , V_41 -> V_46 ,
V_125 ) ;
V_121 -> V_126 = ( unsigned long ) V_41 ;
for ( V_139 = 0 ; V_139 < V_133 ; V_139 ++ ) {
V_2 -> V_135 ++ ;
if ( V_2 -> V_135 >= V_38 )
V_2 -> V_135 = 0 ;
V_121 = & V_2 -> V_37 [ V_2 -> V_135 ] ;
V_121 -> V_33 = F_32 ( V_27 -> V_25 . V_31 ,
( void * ) F_59 ( V_140 -> V_149 ) +
V_140 -> V_150 ,
V_140 -> V_151 , V_125 ) ;
V_121 -> V_46 = V_140 -> V_151 ;
V_121 -> V_47 = 0 ;
V_140 ++ ;
}
V_121 -> V_47 |= V_152 ;
V_138 = V_2 -> V_39 + sizeof( * V_2 -> V_37 ) * V_2 -> V_135 ;
V_2 -> V_135 ++ ;
if ( V_2 -> V_135 >= V_38 )
V_2 -> V_135 = 0 ;
V_2 -> V_24 ( V_2 , V_153 , V_138 ) ;
return V_154 ;
}
static void F_60 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_40 * V_41 , * V_155 ;
unsigned int V_156 ;
struct V_120 * V_121 ;
T_2 V_138 ;
int V_157 ;
unsigned long V_71 ;
F_61 ( & V_2 -> V_158 , V_71 ) ;
V_138 = V_2 -> V_36 + sizeof( * V_2 -> V_32 ) * V_2 -> V_159 ;
V_121 = & V_2 -> V_32 [ V_2 -> V_159 ] ;
V_156 = V_121 -> V_47 ;
while ( ( V_156 & V_124 ) ) {
V_41 = V_2 -> V_30 [ V_2 -> V_159 ] ;
V_157 = V_121 -> V_126 & 0x3FFF ;
F_23 ( V_27 -> V_25 . V_31 , V_121 -> V_33 , V_157 ,
V_35 ) ;
F_62 ( V_41 , V_157 ) ;
V_41 -> V_25 = V_27 ;
V_41 -> V_160 = F_63 ( V_41 , V_27 ) ;
F_64 ( V_41 ) ;
if ( ( ( V_2 -> V_161 & V_162 ) != 0 ) &&
( V_41 -> V_160 == F_65 ( V_163 ) ) &&
( V_41 -> V_46 > 64 ) ) {
V_41 -> V_164 = V_121 -> V_129 & 0xFFFF ;
V_41 -> V_143 = V_165 ;
}
F_66 ( V_41 ) ;
V_27 -> V_130 . V_166 ++ ;
V_27 -> V_130 . V_167 += V_157 ;
V_155 = F_31 ( V_27 ,
V_34 ) ;
if ( V_155 == 0 ) {
F_29 ( & V_27 -> V_25 , L_14 ) ;
F_67 ( & V_2 -> V_158 , V_71 ) ;
return;
}
V_121 -> V_47 = V_48 ;
V_121 -> V_33 = F_32 ( V_27 -> V_25 . V_31 , V_155 -> V_45 ,
V_34 ,
V_35 ) ;
V_121 -> V_46 = V_34 ;
V_2 -> V_30 [ V_2 -> V_159 ] = V_155 ;
V_2 -> V_159 ++ ;
if ( V_2 -> V_159 >= V_29 )
V_2 -> V_159 = 0 ;
V_121 = & V_2 -> V_32 [ V_2 -> V_159 ] ;
V_156 = V_121 -> V_47 ;
}
V_2 -> V_24 ( V_2 , V_56 , V_138 ) ;
F_67 ( & V_2 -> V_158 , V_71 ) ;
}
static T_4 F_68 ( int V_168 , void * V_169 )
{
struct V_26 * V_27 = V_169 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_170 ;
V_170 = V_2 -> V_23 ( V_2 , V_171 ) ;
V_2 -> V_24 ( V_2 , V_171 , V_170 ) ;
if ( V_170 & ( V_172 | V_173 ) )
F_49 ( V_2 -> V_27 ) ;
if ( V_170 & 0x080 )
F_29 ( & V_27 -> V_25 , L_15 , V_170 ) ;
return V_174 ;
}
static T_4 F_69 ( int V_168 , void * V_169 )
{
struct V_26 * V_27 = V_169 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_170 ;
V_170 = V_2 -> V_23 ( V_2 , V_175 ) ;
V_2 -> V_24 ( V_2 , V_175 , V_170 ) ;
if ( V_170 & ( V_172 | V_173 ) )
F_60 ( V_2 -> V_27 ) ;
return V_174 ;
}
static int F_70 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_176 ;
F_20 ( & V_27 -> V_25 , L_16 ) ;
if ( V_2 -> V_177 ) {
V_2 -> V_105 = F_71 ( V_2 -> V_27 , V_2 -> V_177 ,
F_47 , 0 , 0 ) ;
if ( ! V_2 -> V_105 ) {
F_29 ( V_2 -> V_25 , L_17 ) ;
return - V_178 ;
}
F_72 ( V_2 -> V_105 ) ;
}
V_176 = F_73 ( V_2 -> V_179 , F_68 , 0 , V_27 -> V_180 , V_27 ) ;
if ( V_176 )
goto V_181;
V_176 = F_73 ( V_2 -> V_182 , F_69 , 0 , V_27 -> V_180 , V_27 ) ;
if ( V_176 )
goto V_183;
F_45 ( V_27 ) ;
return 0 ;
V_183:
F_74 ( V_2 -> V_179 , V_27 ) ;
V_181:
if ( V_2 -> V_105 )
F_75 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
F_29 ( V_2 -> V_25 , L_18 ) ;
return V_176 ;
}
static int F_76 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_20 ( & V_27 -> V_25 , L_19 ) ;
F_74 ( V_2 -> V_179 , V_27 ) ;
F_74 ( V_2 -> V_182 , V_27 ) ;
if ( V_2 -> V_105 )
F_75 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
F_21 ( V_27 ) ;
return 0 ;
}
static void
F_77 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_78 ( V_2 -> V_179 ) ;
F_78 ( V_2 -> V_182 ) ;
F_69 ( V_2 -> V_179 , V_27 ) ;
F_68 ( V_2 -> V_182 , V_27 ) ;
F_79 ( V_2 -> V_179 ) ;
F_79 ( V_2 -> V_182 ) ;
}
static T_5 F_80 ( struct V_184 * V_25 ,
struct V_185 * V_186 , char * V_187 )
{
struct V_26 * V_27 = F_81 ( V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_28 , V_46 = 0 ;
for ( V_28 = 0 ; V_28 < 0x11 ; V_28 ++ )
V_46 += sprintf ( V_187 + V_46 , L_20 , V_2 -> V_23 ( V_2 , V_28 ) ,
( V_28 % 8 ) == 7 ? L_21 : L_22 ) ;
V_46 += sprintf ( V_187 + V_46 , L_21 ) ;
return V_46 ;
}
static int T_6 F_82 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const void * V_67 ;
T_7 * V_65 ;
int V_151 , V_176 = 0 ;
V_27 = F_83 ( sizeof( * V_2 ) ) ;
if ( ! V_27 ) {
F_29 ( & V_19 -> V_25 , L_23 ) ;
return - V_58 ;
}
F_84 ( V_27 ) ;
F_85 ( & V_19 -> V_25 , V_27 ) ;
F_86 ( V_27 , & V_19 -> V_25 ) ;
V_27 -> V_71 &= ~ V_188 ;
V_27 -> V_189 = V_190 | V_191 ;
V_27 -> V_192 = & V_193 ;
#if 0
ndev->features |= NETIF_F_IP_CSUM;
ndev->features |= NETIF_F_HW_CSUM;
ndev->features |= NETIF_F_IPV6_CSUM;
ndev->features |= NETIF_F_HIGHDMA;
ndev->features |= NETIF_F_HW_VLAN_TX;
ndev->features |= NETIF_F_HW_VLAN_RX;
ndev->features |= NETIF_F_HW_VLAN_FILTER;
ndev->features |= NETIF_F_VLAN_CHALLENGED;
ndev->features |= NETIF_F_GSO;
ndev->features |= NETIF_F_MULTI_QUEUE;
ndev->features |= NETIF_F_LRO;
#endif
V_2 = F_22 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_25 = & V_19 -> V_25 ;
V_2 -> V_81 = V_194 ;
F_87 ( & V_2 -> V_158 ) ;
F_88 ( & V_2 -> V_62 ) ;
V_2 -> V_4 = F_89 ( V_19 -> V_25 . V_195 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( & V_19 -> V_25 , L_24 ) ;
goto V_196;
}
V_2 -> V_161 = 0 ;
V_65 = ( T_7 * ) F_90 ( V_19 -> V_25 . V_195 , L_25 , NULL ) ;
if ( V_65 && F_91 ( * V_65 ) ) {
V_2 -> V_161 |= V_197 ;
V_27 -> V_189 |= V_198 ;
}
V_65 = ( T_7 * ) F_90 ( V_19 -> V_25 . V_195 , L_26 , NULL ) ;
if ( V_65 && F_91 ( * V_65 ) )
V_2 -> V_161 |= V_162 ;
V_21 = F_92 ( V_19 -> V_25 . V_195 , L_27 , 0 ) ;
if ( ! V_21 ) {
F_29 ( & V_19 -> V_25 , L_28 ) ;
goto V_199;
}
if ( F_16 ( V_2 , V_19 , V_21 ) ) {
V_2 -> V_16 = F_89 ( V_21 , 0 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_23 = F_10 ;
V_2 -> V_24 = F_11 ;
F_20 ( & V_19 -> V_25 , L_29 , V_2 -> V_16 ) ;
} else {
F_29 ( & V_19 -> V_25 , L_30 ) ;
F_93 ( V_21 ) ;
goto V_199;
}
}
V_2 -> V_182 = F_94 ( V_21 , 0 ) ;
V_2 -> V_179 = F_94 ( V_21 , 1 ) ;
F_93 ( V_21 ) ;
if ( ( V_2 -> V_182 == V_200 ) || ( V_2 -> V_179 == V_200 ) ) {
F_29 ( & V_19 -> V_25 , L_31 ) ;
V_176 = - V_58 ;
goto V_201;
}
V_67 = F_90 ( V_19 -> V_25 . V_195 , L_32 , & V_151 ) ;
if ( ( ! V_67 ) || ( V_151 != 6 ) ) {
F_29 ( & V_19 -> V_25 , L_33 ) ;
V_176 = - V_178 ;
goto V_201;
}
F_33 ( V_27 , ( void * ) V_67 ) ;
V_176 = F_95 ( V_2 , V_19 -> V_25 . V_195 ) ;
if ( V_176 )
F_96 ( & V_19 -> V_25 , L_34 ) ;
V_2 -> V_177 = F_92 ( V_19 -> V_25 . V_195 , L_35 , 0 ) ;
if ( V_2 -> V_177 )
F_20 ( V_2 -> V_25 , L_36 , V_21 -> V_202 , V_21 ) ;
V_176 = F_97 ( & V_2 -> V_25 -> V_203 , & V_204 ) ;
if ( V_176 ) {
F_29 ( V_2 -> V_25 , L_37 ) ;
goto V_201;
}
V_176 = F_98 ( V_2 -> V_27 ) ;
if ( V_176 ) {
F_29 ( V_2 -> V_25 , L_38 , V_176 ) ;
goto V_205;
}
return 0 ;
V_205:
F_99 ( & V_2 -> V_25 -> V_203 , & V_204 ) ;
V_201:
if ( V_2 -> V_16 )
F_100 ( V_2 -> V_16 ) ;
V_199:
F_100 ( V_2 -> V_4 ) ;
V_196:
F_101 ( V_27 ) ;
V_27 = NULL ;
return V_176 ;
}
static int T_8 F_102 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_81 ( & V_19 -> V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_103 ( V_2 ) ;
F_104 ( V_27 ) ;
F_99 ( & V_2 -> V_25 -> V_203 , & V_204 ) ;
if ( V_2 -> V_177 )
F_93 ( V_2 -> V_177 ) ;
V_2 -> V_177 = NULL ;
F_85 ( & V_19 -> V_25 , NULL ) ;
F_100 ( V_2 -> V_4 ) ;
if ( V_2 -> V_16 )
F_100 ( V_2 -> V_16 ) ;
F_101 ( V_27 ) ;
return 0 ;
}
static int T_9 F_105 ( void )
{
return F_106 ( & V_206 ) ;
}
static void T_10 F_107 ( void )
{
F_108 ( & V_206 ) ;
}
