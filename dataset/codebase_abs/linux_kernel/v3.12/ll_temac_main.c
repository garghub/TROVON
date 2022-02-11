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
F_5 ( V_2 ) ;
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
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
for ( V_28 = 0 ; V_28 < V_31 ; V_28 ++ ) {
if ( ! V_2 -> V_32 [ V_28 ] )
break;
else {
F_23 ( V_27 -> V_25 . V_33 , V_2 -> V_34 [ V_28 ] . V_35 ,
V_36 , V_37 ) ;
F_24 ( V_2 -> V_32 [ V_28 ] ) ;
}
}
if ( V_2 -> V_34 )
F_25 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_34 ) * V_31 ,
V_2 -> V_34 , V_2 -> V_38 ) ;
if ( V_2 -> V_39 )
F_25 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_39 ) * V_40 ,
V_2 -> V_39 , V_2 -> V_41 ) ;
if ( V_2 -> V_32 )
F_26 ( V_2 -> V_32 ) ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_42 * V_43 ;
int V_28 ;
V_2 -> V_32 = F_28 ( V_31 , sizeof( * V_2 -> V_32 ) , V_44 ) ;
if ( ! V_2 -> V_32 )
goto V_45;
V_2 -> V_39 = F_29 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_39 ) * V_40 ,
& V_2 -> V_41 , V_44 ) ;
if ( ! V_2 -> V_39 )
goto V_45;
V_2 -> V_34 = F_29 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_34 ) * V_31 ,
& V_2 -> V_38 , V_44 ) ;
if ( ! V_2 -> V_34 )
goto V_45;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
V_2 -> V_39 [ V_28 ] . V_46 = V_2 -> V_41 +
sizeof( * V_2 -> V_39 ) * ( ( V_28 + 1 ) % V_40 ) ;
}
for ( V_28 = 0 ; V_28 < V_31 ; V_28 ++ ) {
V_2 -> V_34 [ V_28 ] . V_46 = V_2 -> V_38 +
sizeof( * V_2 -> V_34 ) * ( ( V_28 + 1 ) % V_31 ) ;
V_43 = F_30 ( V_27 ,
V_36 ) ;
if ( ! V_43 )
goto V_45;
V_2 -> V_32 [ V_28 ] = V_43 ;
V_2 -> V_34 [ V_28 ] . V_35 = F_31 ( V_27 -> V_25 . V_33 ,
V_43 -> V_47 ,
V_36 ,
V_37 ) ;
V_2 -> V_34 [ V_28 ] . V_48 = V_36 ;
V_2 -> V_34 [ V_28 ] . V_49 = V_50 ;
}
V_2 -> V_24 ( V_2 , V_51 , 0x10220400 |
V_52 |
V_53 |
V_54 ) ;
V_2 -> V_24 ( V_2 , V_55 , 0xff070000 |
V_52 |
V_53 |
V_54 |
V_56 ) ;
V_2 -> V_24 ( V_2 , V_57 , V_2 -> V_38 ) ;
V_2 -> V_24 ( V_2 , V_58 ,
V_2 -> V_38 + ( sizeof( * V_2 -> V_34 ) * ( V_31 - 1 ) ) ) ;
V_2 -> V_24 ( V_2 , V_59 , V_2 -> V_41 ) ;
V_2 -> V_60 = 0 ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = 0 ;
return 0 ;
V_45:
F_21 ( V_27 ) ;
return - V_64 ;
}
static void F_32 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_33 ( & V_2 -> V_65 ) ;
F_9 ( V_2 , V_66 ,
( V_27 -> V_67 [ 0 ] ) |
( V_27 -> V_67 [ 1 ] << 8 ) |
( V_27 -> V_67 [ 2 ] << 16 ) |
( V_27 -> V_67 [ 3 ] << 24 ) ) ;
F_9 ( V_2 , V_68 ,
( V_27 -> V_67 [ 4 ] & 0x000000ff ) |
( V_27 -> V_67 [ 5 ] << 8 ) ) ;
F_34 ( & V_2 -> V_65 ) ;
}
static int F_35 ( struct V_26 * V_27 , void * V_69 )
{
memcpy ( V_27 -> V_67 , V_69 , V_70 ) ;
if ( ! F_36 ( V_27 -> V_67 ) )
F_37 ( V_27 ) ;
F_32 ( V_27 ) ;
return 0 ;
}
static int F_38 ( struct V_26 * V_27 , void * V_71 )
{
struct V_72 * V_73 = V_71 ;
if ( ! F_36 ( V_73 -> V_74 ) )
return - V_75 ;
memcpy ( V_27 -> V_67 , V_73 -> V_74 , V_70 ) ;
F_32 ( V_27 ) ;
return 0 ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_76 , V_77 , V_12 ;
int V_28 ;
F_33 ( & V_2 -> V_65 ) ;
if ( V_27 -> V_78 & ( V_79 | V_80 ) ||
F_40 ( V_27 ) > V_81 ) {
V_27 -> V_78 |= V_80 ;
F_9 ( V_2 , V_82 , V_83 ) ;
F_41 ( & V_27 -> V_25 , L_2 ) ;
} else if ( ! F_42 ( V_27 ) ) {
struct V_84 * V_85 ;
V_28 = 0 ;
F_43 (ha, ndev) {
if ( V_28 >= V_81 )
break;
V_76 = ( ( V_85 -> V_73 [ 3 ] << 24 ) |
( V_85 -> V_73 [ 2 ] << 16 ) |
( V_85 -> V_73 [ 1 ] << 8 ) |
( V_85 -> V_73 [ 0 ] ) ) ;
F_9 ( V_2 , V_86 ,
V_76 ) ;
V_77 = ( ( V_85 -> V_73 [ 5 ] << 8 ) |
( V_85 -> V_73 [ 4 ] ) | ( V_28 << 16 ) ) ;
F_9 ( V_2 , V_87 ,
V_77 ) ;
V_28 ++ ;
}
} else {
V_12 = F_8 ( V_2 , V_82 ) ;
F_9 ( V_2 , V_82 ,
V_12 & ~ V_83 ) ;
F_9 ( V_2 , V_86 , 0 ) ;
F_9 ( V_2 , V_87 , 0 ) ;
F_41 ( & V_27 -> V_25 , L_3 ) ;
}
F_34 ( & V_2 -> V_65 ) ;
}
static T_1 F_44 ( struct V_26 * V_27 , T_1 V_88 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_89 * V_90 = & V_91 [ 0 ] ;
int V_11 ;
F_33 ( & V_2 -> V_65 ) ;
while ( V_90 -> V_92 ) {
V_11 = F_8 ( V_2 , V_90 -> V_11 ) & ~ V_90 -> V_93 ;
if ( V_88 & V_90 -> V_92 )
V_11 |= V_90 -> V_93 ;
F_9 ( V_2 , V_90 -> V_11 , V_11 ) ;
V_90 ++ ;
}
V_2 -> V_88 |= V_88 ;
F_34 ( & V_2 -> V_65 ) ;
return 0 ;
}
static void F_45 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_94 ;
T_1 V_12 ;
F_20 ( & V_27 -> V_25 , L_4 , V_95 ) ;
F_33 ( & V_2 -> V_65 ) ;
F_9 ( V_2 , V_96 , V_97 ) ;
V_94 = 1000 ;
while ( F_8 ( V_2 , V_96 ) & V_97 ) {
F_46 ( 1 ) ;
if ( -- V_94 == 0 ) {
F_47 ( & V_27 -> V_25 ,
L_5 ) ;
break;
}
}
F_9 ( V_2 , V_98 , V_99 ) ;
V_94 = 1000 ;
while ( F_8 ( V_2 , V_98 ) & V_99 ) {
F_46 ( 1 ) ;
if ( -- V_94 == 0 ) {
F_47 ( & V_27 -> V_25 ,
L_6 ) ;
break;
}
}
V_12 = F_8 ( V_2 , V_96 ) ;
F_9 ( V_2 , V_96 , V_12 & ~ V_100 ) ;
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
V_94 = 1000 ;
while ( V_2 -> V_23 ( V_2 , V_29 ) & V_30 ) {
F_46 ( 1 ) ;
if ( -- V_94 == 0 ) {
F_47 ( & V_27 -> V_25 ,
L_7 ) ;
break;
}
}
V_2 -> V_24 ( V_2 , V_29 , V_101 ) ;
if ( F_27 ( V_27 ) ) {
F_47 ( & V_27 -> V_25 ,
L_8 ) ;
}
F_9 ( V_2 , V_102 , 0 ) ;
F_9 ( V_2 , V_96 , 0 ) ;
F_9 ( V_2 , V_98 , 0 ) ;
F_9 ( V_2 , V_103 , V_104 ) ;
F_34 ( & V_2 -> V_65 ) ;
F_44 ( V_27 ,
V_2 -> V_88 & ~ ( V_105 | V_106 ) ) ;
F_32 ( V_27 ) ;
F_39 ( V_27 ) ;
if ( F_44 ( V_27 , V_2 -> V_88 ) )
F_47 ( & V_27 -> V_25 , L_9 ) ;
V_27 -> V_107 = V_7 ;
}
void F_48 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_108 * V_109 = V_2 -> V_110 ;
T_1 V_111 ;
int V_112 ;
V_112 = V_109 -> V_113 | ( V_109 -> V_114 << 1 ) | V_109 -> V_115 ;
F_33 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_116 != V_112 ) {
V_111 = F_8 ( V_2 , V_117 ) ;
V_111 &= ~ V_118 ;
switch ( V_109 -> V_113 ) {
case V_119 : V_111 |= V_120 ; break;
case V_121 : V_111 |= V_122 ; break;
case V_123 : V_111 |= V_124 ; break;
}
F_9 ( V_2 , V_117 , V_111 ) ;
V_2 -> V_116 = V_112 ;
F_49 ( V_109 ) ;
}
F_34 ( & V_2 -> V_65 ) ;
}
static void F_50 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_125 * V_126 ;
unsigned int V_127 = 0 ;
V_126 = & V_2 -> V_39 [ V_2 -> V_60 ] ;
V_127 = V_126 -> V_49 ;
while ( V_127 & V_128 ) {
F_23 ( V_27 -> V_25 . V_33 , V_126 -> V_35 , V_126 -> V_48 ,
V_129 ) ;
if ( V_126 -> V_130 )
F_51 ( (struct V_42 * ) V_126 -> V_130 ) ;
V_126 -> V_49 = 0 ;
V_126 -> V_131 = 0 ;
V_126 -> V_132 = 0 ;
V_126 -> V_133 = 0 ;
V_126 -> V_130 = 0 ;
V_27 -> V_134 . V_135 ++ ;
V_27 -> V_134 . V_136 += V_126 -> V_48 ;
V_2 -> V_60 ++ ;
if ( V_2 -> V_60 >= V_40 )
V_2 -> V_60 = 0 ;
V_126 = & V_2 -> V_39 [ V_2 -> V_60 ] ;
V_127 = V_126 -> V_49 ;
}
F_52 ( V_27 ) ;
}
static inline int F_53 ( struct V_1 * V_2 , int V_137 )
{
struct V_125 * V_126 ;
int V_138 ;
V_138 = V_2 -> V_62 ;
V_126 = & V_2 -> V_39 [ V_138 ] ;
do {
if ( V_126 -> V_49 )
return V_139 ;
V_138 ++ ;
if ( V_138 >= V_40 )
V_138 = 0 ;
V_126 = & V_2 -> V_39 [ V_138 ] ;
V_137 -- ;
} while ( V_137 >= 0 );
return 0 ;
}
static int F_54 ( struct V_42 * V_43 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_125 * V_126 ;
T_2 V_140 , V_141 ;
int V_142 ;
unsigned long V_137 ;
T_3 * V_143 ;
V_137 = F_55 ( V_43 ) -> V_144 ;
V_143 = & F_55 ( V_43 ) -> V_145 [ 0 ] ;
V_140 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_62 ;
V_126 = & V_2 -> V_39 [ V_2 -> V_62 ] ;
if ( F_53 ( V_2 , V_137 ) ) {
if ( ! F_56 ( V_27 ) ) {
F_57 ( V_27 ) ;
return V_139 ;
}
return V_139 ;
}
V_126 -> V_49 = 0 ;
if ( V_43 -> V_146 == V_147 ) {
unsigned int V_148 = F_58 ( V_43 ) ;
unsigned int V_149 = V_148 + V_43 -> V_150 ;
V_126 -> V_49 |= 1 ;
V_126 -> V_131 = ( V_148 << 16 ) | V_149 ;
V_126 -> V_132 = 0 ;
}
V_126 -> V_49 |= V_151 ;
V_126 -> V_48 = F_59 ( V_43 ) ;
V_126 -> V_35 = F_31 ( V_27 -> V_25 . V_33 , V_43 -> V_47 , V_43 -> V_48 ,
V_129 ) ;
V_126 -> V_130 = ( unsigned long ) V_43 ;
for ( V_142 = 0 ; V_142 < V_137 ; V_142 ++ ) {
V_2 -> V_62 ++ ;
if ( V_2 -> V_62 >= V_40 )
V_2 -> V_62 = 0 ;
V_126 = & V_2 -> V_39 [ V_2 -> V_62 ] ;
V_126 -> V_35 = F_31 ( V_27 -> V_25 . V_33 ,
F_60 ( V_143 ) ,
F_61 ( V_143 ) , V_129 ) ;
V_126 -> V_48 = F_61 ( V_143 ) ;
V_126 -> V_49 = 0 ;
V_143 ++ ;
}
V_126 -> V_49 |= V_152 ;
V_141 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_62 ;
V_2 -> V_62 ++ ;
if ( V_2 -> V_62 >= V_40 )
V_2 -> V_62 = 0 ;
F_62 ( V_43 ) ;
V_2 -> V_24 ( V_2 , V_153 , V_141 ) ;
return V_154 ;
}
static void F_63 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_42 * V_43 , * V_155 ;
unsigned int V_156 ;
struct V_125 * V_126 ;
T_2 V_141 ;
int V_157 ;
unsigned long V_78 ;
F_64 ( & V_2 -> V_158 , V_78 ) ;
V_141 = V_2 -> V_38 + sizeof( * V_2 -> V_34 ) * V_2 -> V_63 ;
V_126 = & V_2 -> V_34 [ V_2 -> V_63 ] ;
V_156 = V_126 -> V_49 ;
while ( ( V_156 & V_128 ) ) {
V_43 = V_2 -> V_32 [ V_2 -> V_63 ] ;
V_157 = V_126 -> V_130 & 0x3FFF ;
F_23 ( V_27 -> V_25 . V_33 , V_126 -> V_35 , V_157 ,
V_37 ) ;
F_65 ( V_43 , V_157 ) ;
V_43 -> V_159 = F_66 ( V_43 , V_27 ) ;
F_67 ( V_43 ) ;
if ( ( ( V_2 -> V_160 & V_161 ) != 0 ) &&
( V_43 -> V_159 == F_68 ( V_162 ) ) &&
( V_43 -> V_48 > 64 ) ) {
V_43 -> V_163 = V_126 -> V_133 & 0xFFFF ;
V_43 -> V_146 = V_164 ;
}
if ( ! F_69 ( V_43 ) )
F_70 ( V_43 ) ;
V_27 -> V_134 . V_165 ++ ;
V_27 -> V_134 . V_166 += V_157 ;
V_155 = F_30 ( V_27 ,
V_36 ) ;
if ( ! V_155 ) {
F_71 ( & V_2 -> V_158 , V_78 ) ;
return;
}
V_126 -> V_49 = V_50 ;
V_126 -> V_35 = F_31 ( V_27 -> V_25 . V_33 , V_155 -> V_47 ,
V_36 ,
V_37 ) ;
V_126 -> V_48 = V_36 ;
V_2 -> V_32 [ V_2 -> V_63 ] = V_155 ;
V_2 -> V_63 ++ ;
if ( V_2 -> V_63 >= V_31 )
V_2 -> V_63 = 0 ;
V_126 = & V_2 -> V_34 [ V_2 -> V_63 ] ;
V_156 = V_126 -> V_49 ;
}
V_2 -> V_24 ( V_2 , V_58 , V_141 ) ;
F_71 ( & V_2 -> V_158 , V_78 ) ;
}
static T_4 F_72 ( int V_167 , void * V_168 )
{
struct V_26 * V_27 = V_168 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_169 ;
V_169 = V_2 -> V_23 ( V_2 , V_170 ) ;
V_2 -> V_24 ( V_2 , V_170 , V_169 ) ;
if ( V_169 & ( V_171 | V_172 ) )
F_50 ( V_2 -> V_27 ) ;
if ( V_169 & 0x080 )
F_47 ( & V_27 -> V_25 , L_10 , V_169 ) ;
return V_173 ;
}
static T_4 F_73 ( int V_167 , void * V_168 )
{
struct V_26 * V_27 = V_168 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_169 ;
V_169 = V_2 -> V_23 ( V_2 , V_174 ) ;
V_2 -> V_24 ( V_2 , V_174 , V_169 ) ;
if ( V_169 & ( V_171 | V_172 ) )
F_63 ( V_2 -> V_27 ) ;
return V_173 ;
}
static int F_74 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_175 ;
F_20 ( & V_27 -> V_25 , L_11 ) ;
if ( V_2 -> V_176 ) {
V_2 -> V_110 = F_75 ( V_2 -> V_27 , V_2 -> V_176 ,
F_48 , 0 , 0 ) ;
if ( ! V_2 -> V_110 ) {
F_47 ( V_2 -> V_25 , L_12 ) ;
return - V_177 ;
}
F_76 ( V_2 -> V_110 ) ;
}
F_45 ( V_27 ) ;
V_175 = F_77 ( V_2 -> V_178 , F_72 , 0 , V_27 -> V_179 , V_27 ) ;
if ( V_175 )
goto V_180;
V_175 = F_77 ( V_2 -> V_181 , F_73 , 0 , V_27 -> V_179 , V_27 ) ;
if ( V_175 )
goto V_182;
return 0 ;
V_182:
F_78 ( V_2 -> V_178 , V_27 ) ;
V_180:
if ( V_2 -> V_110 )
F_79 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
F_47 ( V_2 -> V_25 , L_13 ) ;
return V_175 ;
}
static int F_80 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_20 ( & V_27 -> V_25 , L_14 ) ;
F_78 ( V_2 -> V_178 , V_27 ) ;
F_78 ( V_2 -> V_181 , V_27 ) ;
if ( V_2 -> V_110 )
F_79 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
F_21 ( V_27 ) ;
return 0 ;
}
static void
F_81 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_82 ( V_2 -> V_178 ) ;
F_82 ( V_2 -> V_181 ) ;
F_73 ( V_2 -> V_178 , V_27 ) ;
F_72 ( V_2 -> V_181 , V_27 ) ;
F_83 ( V_2 -> V_178 ) ;
F_83 ( V_2 -> V_181 ) ;
}
static int F_84 ( struct V_26 * V_27 , struct V_183 * V_184 , int V_185 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
if ( ! F_85 ( V_27 ) )
return - V_186 ;
if ( ! V_2 -> V_110 )
return - V_186 ;
return F_86 ( V_2 -> V_110 , V_184 , V_185 ) ;
}
static T_5 F_87 ( struct V_187 * V_25 ,
struct V_188 * V_189 , char * V_190 )
{
struct V_26 * V_27 = F_88 ( V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_28 , V_48 = 0 ;
for ( V_28 = 0 ; V_28 < 0x11 ; V_28 ++ )
V_48 += sprintf ( V_190 + V_48 , L_15 , V_2 -> V_23 ( V_2 , V_28 ) ,
( V_28 % 8 ) == 7 ? L_16 : L_17 ) ;
V_48 += sprintf ( V_190 + V_48 , L_16 ) ;
return V_48 ;
}
static int F_89 ( struct V_26 * V_27 , struct V_191 * V_185 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_90 ( V_2 -> V_110 , V_185 ) ;
}
static int F_91 ( struct V_26 * V_27 , struct V_191 * V_185 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_92 ( V_2 -> V_110 , V_185 ) ;
}
static int F_93 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_94 ( V_2 -> V_110 ) ;
}
static int F_95 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const void * V_73 ;
T_6 * V_71 ;
int V_192 , V_175 = 0 ;
V_27 = F_96 ( sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_64 ;
F_97 ( V_27 ) ;
F_98 ( V_19 , V_27 ) ;
F_99 ( V_27 , & V_19 -> V_25 ) ;
V_27 -> V_78 &= ~ V_193 ;
V_27 -> V_194 = V_195 | V_196 ;
V_27 -> V_197 = & V_198 ;
V_27 -> V_199 = & V_200 ;
#if 0
ndev->features |= NETIF_F_IP_CSUM;
ndev->features |= NETIF_F_HW_CSUM;
ndev->features |= NETIF_F_IPV6_CSUM;
ndev->features |= NETIF_F_HIGHDMA;
ndev->features |= NETIF_F_HW_VLAN_CTAG_TX;
ndev->features |= NETIF_F_HW_VLAN_CTAG_RX;
ndev->features |= NETIF_F_HW_VLAN_CTAG_FILTER;
ndev->features |= NETIF_F_VLAN_CHALLENGED;
ndev->features |= NETIF_F_GSO;
ndev->features |= NETIF_F_MULTI_QUEUE;
ndev->features |= NETIF_F_LRO;
#endif
V_2 = F_22 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_25 = & V_19 -> V_25 ;
V_2 -> V_88 = V_201 ;
F_100 ( & V_2 -> V_158 ) ;
F_101 ( & V_2 -> V_65 ) ;
V_2 -> V_4 = F_102 ( V_19 -> V_25 . V_202 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_47 ( & V_19 -> V_25 , L_18 ) ;
goto V_203;
}
V_2 -> V_160 = 0 ;
V_71 = ( T_6 * ) F_103 ( V_19 -> V_25 . V_202 , L_19 , NULL ) ;
if ( V_71 && F_104 ( * V_71 ) ) {
V_2 -> V_160 |= V_204 ;
V_27 -> V_194 |= V_205 ;
}
V_71 = ( T_6 * ) F_103 ( V_19 -> V_25 . V_202 , L_20 , NULL ) ;
if ( V_71 && F_104 ( * V_71 ) )
V_2 -> V_160 |= V_161 ;
V_21 = F_105 ( V_19 -> V_25 . V_202 , L_21 , 0 ) ;
if ( ! V_21 ) {
F_47 ( & V_19 -> V_25 , L_22 ) ;
goto V_206;
}
if ( F_16 ( V_2 , V_19 , V_21 ) ) {
V_2 -> V_16 = F_102 ( V_21 , 0 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_23 = F_10 ;
V_2 -> V_24 = F_11 ;
F_20 ( & V_19 -> V_25 , L_23 , V_2 -> V_16 ) ;
} else {
F_47 ( & V_19 -> V_25 , L_24 ) ;
F_106 ( V_21 ) ;
goto V_206;
}
}
V_2 -> V_181 = F_107 ( V_21 , 0 ) ;
V_2 -> V_178 = F_107 ( V_21 , 1 ) ;
F_106 ( V_21 ) ;
if ( ! V_2 -> V_181 || ! V_2 -> V_178 ) {
F_47 ( & V_19 -> V_25 , L_25 ) ;
V_175 = - V_64 ;
goto V_207;
}
V_73 = F_103 ( V_19 -> V_25 . V_202 , L_26 , & V_192 ) ;
if ( ( ! V_73 ) || ( V_192 != 6 ) ) {
F_47 ( & V_19 -> V_25 , L_27 ) ;
V_175 = - V_177 ;
goto V_207;
}
F_35 ( V_27 , ( void * ) V_73 ) ;
V_175 = F_108 ( V_2 , V_19 -> V_25 . V_202 ) ;
if ( V_175 )
F_109 ( & V_19 -> V_25 , L_28 ) ;
V_2 -> V_176 = F_105 ( V_19 -> V_25 . V_202 , L_29 , 0 ) ;
if ( V_2 -> V_176 )
F_20 ( V_2 -> V_25 , L_30 , V_21 -> V_208 , V_21 ) ;
V_175 = F_110 ( & V_2 -> V_25 -> V_209 , & V_210 ) ;
if ( V_175 ) {
F_47 ( V_2 -> V_25 , L_31 ) ;
goto V_207;
}
V_175 = F_111 ( V_2 -> V_27 ) ;
if ( V_175 ) {
F_47 ( V_2 -> V_25 , L_32 , V_175 ) ;
goto V_211;
}
return 0 ;
V_211:
F_112 ( & V_2 -> V_25 -> V_209 , & V_210 ) ;
V_207:
if ( V_2 -> V_16 )
F_113 ( V_2 -> V_16 ) ;
V_206:
F_113 ( V_2 -> V_4 ) ;
V_203:
F_114 ( V_27 ) ;
V_27 = NULL ;
return V_175 ;
}
static int F_115 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_116 ( V_19 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_117 ( V_2 ) ;
F_118 ( V_27 ) ;
F_112 ( & V_2 -> V_25 -> V_209 , & V_210 ) ;
if ( V_2 -> V_176 )
F_106 ( V_2 -> V_176 ) ;
V_2 -> V_176 = NULL ;
F_113 ( V_2 -> V_4 ) ;
if ( V_2 -> V_16 )
F_113 ( V_2 -> V_16 ) ;
F_114 ( V_27 ) ;
return 0 ;
}
