T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_2 -> V_4 + V_3 , V_5 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 + 2 ;
while ( ! ( F_1 ( V_2 , V_8 ) & V_9 ) ) {
if ( F_6 ( V_6 , V_7 ) ) {
F_7 ( 1 ) ;
return - V_10 ;
}
F_8 ( 1 ) ;
}
return 0 ;
}
T_1 F_9 ( struct V_1 * V_2 , int V_11 )
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
void F_10 ( struct V_1 * V_2 , int V_11 , T_1 V_5 )
{
if ( F_5 ( V_2 ) )
return;
F_3 ( V_2 , V_14 , V_5 ) ;
F_3 ( V_2 , V_13 , V_15 | V_11 ) ;
F_5 ( V_2 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , int V_11 )
{
return F_2 ( V_2 -> V_16 + ( V_11 << 2 ) ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_11 , T_1 V_5 )
{
F_4 ( V_2 -> V_16 + ( V_11 << 2 ) , V_5 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , int V_11 )
{
return F_14 ( V_2 -> V_17 , V_11 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_11 , T_1 V_5 )
{
F_16 ( V_2 -> V_17 , V_11 , V_5 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned int V_22 ;
V_22 = F_18 ( V_21 , 0 ) ;
if ( V_22 != 0 ) {
V_2 -> V_17 = F_19 ( V_21 , V_22 , F_20 ( V_21 , 0 ) ) ;
V_2 -> V_23 = F_13 ;
V_2 -> V_24 = F_15 ;
F_21 ( & V_19 -> V_25 , L_1 , V_22 ) ;
return 0 ;
}
return - 1 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
return - 1 ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
int V_28 ;
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
for ( V_28 = 0 ; V_28 < V_31 ; V_28 ++ ) {
if ( ! V_2 -> V_32 [ V_28 ] )
break;
else {
F_24 ( V_27 -> V_25 . V_33 , V_2 -> V_34 [ V_28 ] . V_35 ,
V_36 , V_37 ) ;
F_25 ( V_2 -> V_32 [ V_28 ] ) ;
}
}
if ( V_2 -> V_34 )
F_26 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_34 ) * V_31 ,
V_2 -> V_34 , V_2 -> V_38 ) ;
if ( V_2 -> V_39 )
F_26 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_39 ) * V_40 ,
V_2 -> V_39 , V_2 -> V_41 ) ;
F_27 ( V_2 -> V_32 ) ;
}
static int F_28 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_42 * V_43 ;
int V_28 ;
V_2 -> V_32 = F_29 ( V_31 , sizeof( * V_2 -> V_32 ) , V_44 ) ;
if ( ! V_2 -> V_32 )
goto V_45;
V_2 -> V_39 = F_30 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_39 ) * V_40 ,
& V_2 -> V_41 , V_44 ) ;
if ( ! V_2 -> V_39 )
goto V_45;
V_2 -> V_34 = F_30 ( V_27 -> V_25 . V_33 ,
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
V_43 = F_31 ( V_27 ,
V_36 ) ;
if ( ! V_43 )
goto V_45;
V_2 -> V_32 [ V_28 ] = V_43 ;
V_2 -> V_34 [ V_28 ] . V_35 = F_32 ( V_27 -> V_25 . V_33 ,
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
F_22 ( V_27 ) ;
return - V_64 ;
}
static void F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
F_34 ( & V_2 -> V_65 ) ;
F_10 ( V_2 , V_66 ,
( V_27 -> V_67 [ 0 ] ) |
( V_27 -> V_67 [ 1 ] << 8 ) |
( V_27 -> V_67 [ 2 ] << 16 ) |
( V_27 -> V_67 [ 3 ] << 24 ) ) ;
F_10 ( V_2 , V_68 ,
( V_27 -> V_67 [ 4 ] & 0x000000ff ) |
( V_27 -> V_67 [ 5 ] << 8 ) ) ;
F_35 ( & V_2 -> V_65 ) ;
}
static int F_36 ( struct V_26 * V_27 , void * V_69 )
{
memcpy ( V_27 -> V_67 , V_69 , V_70 ) ;
if ( ! F_37 ( V_27 -> V_67 ) )
F_38 ( V_27 ) ;
F_33 ( V_27 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 , void * V_71 )
{
struct V_72 * V_73 = V_71 ;
if ( ! F_37 ( V_73 -> V_74 ) )
return - V_75 ;
memcpy ( V_27 -> V_67 , V_73 -> V_74 , V_70 ) ;
F_33 ( V_27 ) ;
return 0 ;
}
static void F_40 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
T_1 V_76 , V_77 , V_12 ;
int V_28 ;
F_34 ( & V_2 -> V_65 ) ;
if ( V_27 -> V_78 & ( V_79 | V_80 ) ||
F_41 ( V_27 ) > V_81 ) {
V_27 -> V_78 |= V_80 ;
F_10 ( V_2 , V_82 , V_83 ) ;
F_42 ( & V_27 -> V_25 , L_2 ) ;
} else if ( ! F_43 ( V_27 ) ) {
struct V_84 * V_85 ;
V_28 = 0 ;
F_44 (ha, ndev) {
if ( V_28 >= V_81 )
break;
V_76 = ( ( V_85 -> V_73 [ 3 ] << 24 ) |
( V_85 -> V_73 [ 2 ] << 16 ) |
( V_85 -> V_73 [ 1 ] << 8 ) |
( V_85 -> V_73 [ 0 ] ) ) ;
F_10 ( V_2 , V_86 ,
V_76 ) ;
V_77 = ( ( V_85 -> V_73 [ 5 ] << 8 ) |
( V_85 -> V_73 [ 4 ] ) | ( V_28 << 16 ) ) ;
F_10 ( V_2 , V_87 ,
V_77 ) ;
V_28 ++ ;
}
} else {
V_12 = F_9 ( V_2 , V_82 ) ;
F_10 ( V_2 , V_82 ,
V_12 & ~ V_83 ) ;
F_10 ( V_2 , V_86 , 0 ) ;
F_10 ( V_2 , V_87 , 0 ) ;
F_42 ( & V_27 -> V_25 , L_3 ) ;
}
F_35 ( & V_2 -> V_65 ) ;
}
static T_1 F_45 ( struct V_26 * V_27 , T_1 V_88 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_89 * V_90 = & V_91 [ 0 ] ;
int V_11 ;
F_34 ( & V_2 -> V_65 ) ;
while ( V_90 -> V_92 ) {
V_11 = F_9 ( V_2 , V_90 -> V_11 ) & ~ V_90 -> V_93 ;
if ( V_88 & V_90 -> V_92 )
V_11 |= V_90 -> V_93 ;
F_10 ( V_2 , V_90 -> V_11 , V_11 ) ;
V_90 ++ ;
}
V_2 -> V_88 |= V_88 ;
F_35 ( & V_2 -> V_65 ) ;
return 0 ;
}
static void F_46 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
T_1 V_94 ;
T_1 V_12 ;
F_21 ( & V_27 -> V_25 , L_4 , V_95 ) ;
F_34 ( & V_2 -> V_65 ) ;
F_10 ( V_2 , V_96 , V_97 ) ;
V_94 = 1000 ;
while ( F_9 ( V_2 , V_96 ) & V_97 ) {
F_47 ( 1 ) ;
if ( -- V_94 == 0 ) {
F_48 ( & V_27 -> V_25 ,
L_5 ) ;
break;
}
}
F_10 ( V_2 , V_98 , V_99 ) ;
V_94 = 1000 ;
while ( F_9 ( V_2 , V_98 ) & V_99 ) {
F_47 ( 1 ) ;
if ( -- V_94 == 0 ) {
F_48 ( & V_27 -> V_25 ,
L_6 ) ;
break;
}
}
V_12 = F_9 ( V_2 , V_96 ) ;
F_10 ( V_2 , V_96 , V_12 & ~ V_100 ) ;
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
V_94 = 1000 ;
while ( V_2 -> V_23 ( V_2 , V_29 ) & V_30 ) {
F_47 ( 1 ) ;
if ( -- V_94 == 0 ) {
F_48 ( & V_27 -> V_25 ,
L_7 ) ;
break;
}
}
V_2 -> V_24 ( V_2 , V_29 , V_101 ) ;
if ( F_28 ( V_27 ) ) {
F_48 ( & V_27 -> V_25 ,
L_8 ) ;
}
F_10 ( V_2 , V_102 , 0 ) ;
F_10 ( V_2 , V_96 , 0 ) ;
F_10 ( V_2 , V_98 , 0 ) ;
F_10 ( V_2 , V_103 , V_104 ) ;
F_35 ( & V_2 -> V_65 ) ;
F_45 ( V_27 ,
V_2 -> V_88 & ~ ( V_105 | V_106 ) ) ;
F_33 ( V_27 ) ;
F_40 ( V_27 ) ;
if ( F_45 ( V_27 , V_2 -> V_88 ) )
F_48 ( & V_27 -> V_25 , L_9 ) ;
F_49 ( V_27 ) ;
}
static void F_50 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_107 * V_108 = V_27 -> V_109 ;
T_1 V_110 ;
int V_111 ;
V_111 = V_108 -> V_112 | ( V_108 -> V_113 << 1 ) | V_108 -> V_114 ;
F_34 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_115 != V_111 ) {
V_110 = F_9 ( V_2 , V_116 ) ;
V_110 &= ~ V_117 ;
switch ( V_108 -> V_112 ) {
case V_118 : V_110 |= V_119 ; break;
case V_120 : V_110 |= V_121 ; break;
case V_122 : V_110 |= V_123 ; break;
}
F_10 ( V_2 , V_116 , V_110 ) ;
V_2 -> V_115 = V_111 ;
F_51 ( V_108 ) ;
}
F_35 ( & V_2 -> V_65 ) ;
}
static void F_52 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_124 * V_125 ;
unsigned int V_126 = 0 ;
V_125 = & V_2 -> V_39 [ V_2 -> V_60 ] ;
V_126 = V_125 -> V_49 ;
while ( V_126 & V_127 ) {
F_24 ( V_27 -> V_25 . V_33 , V_125 -> V_35 , V_125 -> V_48 ,
V_128 ) ;
if ( V_125 -> V_129 )
F_53 ( (struct V_42 * ) V_125 -> V_129 ) ;
V_125 -> V_49 = 0 ;
V_125 -> V_130 = 0 ;
V_125 -> V_131 = 0 ;
V_125 -> V_132 = 0 ;
V_125 -> V_129 = 0 ;
V_27 -> V_133 . V_134 ++ ;
V_27 -> V_133 . V_135 += V_125 -> V_48 ;
V_2 -> V_60 ++ ;
if ( V_2 -> V_60 >= V_40 )
V_2 -> V_60 = 0 ;
V_125 = & V_2 -> V_39 [ V_2 -> V_60 ] ;
V_126 = V_125 -> V_49 ;
}
F_54 ( V_27 ) ;
}
static inline int F_55 ( struct V_1 * V_2 , int V_136 )
{
struct V_124 * V_125 ;
int V_137 ;
V_137 = V_2 -> V_62 ;
V_125 = & V_2 -> V_39 [ V_137 ] ;
do {
if ( V_125 -> V_49 )
return V_138 ;
V_137 ++ ;
if ( V_137 >= V_40 )
V_137 = 0 ;
V_125 = & V_2 -> V_39 [ V_137 ] ;
V_136 -- ;
} while ( V_136 >= 0 );
return 0 ;
}
static int F_56 ( struct V_42 * V_43 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_124 * V_125 ;
T_2 V_139 , V_140 ;
int V_141 ;
unsigned long V_136 ;
T_3 * V_142 ;
V_136 = F_57 ( V_43 ) -> V_143 ;
V_142 = & F_57 ( V_43 ) -> V_144 [ 0 ] ;
V_139 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_62 ;
V_125 = & V_2 -> V_39 [ V_2 -> V_62 ] ;
if ( F_55 ( V_2 , V_136 ) ) {
if ( ! F_58 ( V_27 ) )
F_59 ( V_27 ) ;
return V_138 ;
}
V_125 -> V_49 = 0 ;
if ( V_43 -> V_145 == V_146 ) {
unsigned int V_147 = F_60 ( V_43 ) ;
unsigned int V_148 = V_147 + V_43 -> V_149 ;
V_125 -> V_49 |= 1 ;
V_125 -> V_130 = ( V_147 << 16 ) | V_148 ;
V_125 -> V_131 = 0 ;
}
V_125 -> V_49 |= V_150 ;
V_125 -> V_48 = F_61 ( V_43 ) ;
V_125 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_43 -> V_47 ,
F_61 ( V_43 ) , V_128 ) ;
V_125 -> V_129 = ( unsigned long ) V_43 ;
for ( V_141 = 0 ; V_141 < V_136 ; V_141 ++ ) {
V_2 -> V_62 ++ ;
if ( V_2 -> V_62 >= V_40 )
V_2 -> V_62 = 0 ;
V_125 = & V_2 -> V_39 [ V_2 -> V_62 ] ;
V_125 -> V_35 = F_32 ( V_27 -> V_25 . V_33 ,
F_62 ( V_142 ) ,
F_63 ( V_142 ) , V_128 ) ;
V_125 -> V_48 = F_63 ( V_142 ) ;
V_125 -> V_49 = 0 ;
V_142 ++ ;
}
V_125 -> V_49 |= V_151 ;
V_140 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_62 ;
V_2 -> V_62 ++ ;
if ( V_2 -> V_62 >= V_40 )
V_2 -> V_62 = 0 ;
F_64 ( V_43 ) ;
V_2 -> V_24 ( V_2 , V_152 , V_140 ) ;
return V_153 ;
}
static void F_65 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_42 * V_43 , * V_154 ;
unsigned int V_155 ;
struct V_124 * V_125 ;
T_2 V_140 ;
int V_156 ;
unsigned long V_78 ;
F_66 ( & V_2 -> V_157 , V_78 ) ;
V_140 = V_2 -> V_38 + sizeof( * V_2 -> V_34 ) * V_2 -> V_63 ;
V_125 = & V_2 -> V_34 [ V_2 -> V_63 ] ;
V_155 = V_125 -> V_49 ;
while ( ( V_155 & V_127 ) ) {
V_43 = V_2 -> V_32 [ V_2 -> V_63 ] ;
V_156 = V_125 -> V_129 & 0x3FFF ;
F_24 ( V_27 -> V_25 . V_33 , V_125 -> V_35 , V_156 ,
V_37 ) ;
F_67 ( V_43 , V_156 ) ;
V_43 -> V_158 = F_68 ( V_43 , V_27 ) ;
F_69 ( V_43 ) ;
if ( ( ( V_2 -> V_159 & V_160 ) != 0 ) &&
( V_43 -> V_158 == F_70 ( V_161 ) ) &&
( V_43 -> V_48 > 64 ) ) {
V_43 -> V_162 = V_125 -> V_132 & 0xFFFF ;
V_43 -> V_145 = V_163 ;
}
if ( ! F_71 ( V_43 ) )
F_72 ( V_43 ) ;
V_27 -> V_133 . V_164 ++ ;
V_27 -> V_133 . V_165 += V_156 ;
V_154 = F_31 ( V_27 ,
V_36 ) ;
if ( ! V_154 ) {
F_73 ( & V_2 -> V_157 , V_78 ) ;
return;
}
V_125 -> V_49 = V_50 ;
V_125 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_154 -> V_47 ,
V_36 ,
V_37 ) ;
V_125 -> V_48 = V_36 ;
V_2 -> V_32 [ V_2 -> V_63 ] = V_154 ;
V_2 -> V_63 ++ ;
if ( V_2 -> V_63 >= V_31 )
V_2 -> V_63 = 0 ;
V_125 = & V_2 -> V_34 [ V_2 -> V_63 ] ;
V_155 = V_125 -> V_49 ;
}
V_2 -> V_24 ( V_2 , V_58 , V_140 ) ;
F_73 ( & V_2 -> V_157 , V_78 ) ;
}
static T_4 F_74 ( int V_166 , void * V_167 )
{
struct V_26 * V_27 = V_167 ;
struct V_1 * V_2 = F_23 ( V_27 ) ;
unsigned int V_168 ;
V_168 = V_2 -> V_23 ( V_2 , V_169 ) ;
V_2 -> V_24 ( V_2 , V_169 , V_168 ) ;
if ( V_168 & ( V_170 | V_171 ) )
F_52 ( V_2 -> V_27 ) ;
if ( V_168 & 0x080 )
F_48 ( & V_27 -> V_25 , L_10 , V_168 ) ;
return V_172 ;
}
static T_4 F_75 ( int V_166 , void * V_167 )
{
struct V_26 * V_27 = V_167 ;
struct V_1 * V_2 = F_23 ( V_27 ) ;
unsigned int V_168 ;
V_168 = V_2 -> V_23 ( V_2 , V_173 ) ;
V_2 -> V_24 ( V_2 , V_173 , V_168 ) ;
if ( V_168 & ( V_170 | V_171 ) )
F_65 ( V_2 -> V_27 ) ;
return V_172 ;
}
static int F_76 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_107 * V_109 = NULL ;
int V_174 ;
F_21 ( & V_27 -> V_25 , L_11 ) ;
if ( V_2 -> V_175 ) {
V_109 = F_77 ( V_2 -> V_27 , V_2 -> V_175 ,
F_50 , 0 , 0 ) ;
if ( ! V_109 ) {
F_48 ( V_2 -> V_25 , L_12 ) ;
return - V_176 ;
}
F_78 ( V_109 ) ;
}
F_46 ( V_27 ) ;
V_174 = F_79 ( V_2 -> V_177 , F_74 , 0 , V_27 -> V_178 , V_27 ) ;
if ( V_174 )
goto V_179;
V_174 = F_79 ( V_2 -> V_180 , F_75 , 0 , V_27 -> V_178 , V_27 ) ;
if ( V_174 )
goto V_181;
return 0 ;
V_181:
F_80 ( V_2 -> V_177 , V_27 ) ;
V_179:
if ( V_109 )
F_81 ( V_109 ) ;
F_48 ( V_2 -> V_25 , L_13 ) ;
return V_174 ;
}
static int F_82 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
struct V_107 * V_109 = V_27 -> V_109 ;
F_21 ( & V_27 -> V_25 , L_14 ) ;
F_80 ( V_2 -> V_177 , V_27 ) ;
F_80 ( V_2 -> V_180 , V_27 ) ;
if ( V_109 )
F_81 ( V_109 ) ;
F_22 ( V_27 ) ;
return 0 ;
}
static void
F_83 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
F_84 ( V_2 -> V_177 ) ;
F_84 ( V_2 -> V_180 ) ;
F_75 ( V_2 -> V_177 , V_27 ) ;
F_74 ( V_2 -> V_180 , V_27 ) ;
F_85 ( V_2 -> V_177 ) ;
F_85 ( V_2 -> V_180 ) ;
}
static int F_86 ( struct V_26 * V_27 , struct V_182 * V_183 , int V_184 )
{
if ( ! F_87 ( V_27 ) )
return - V_185 ;
if ( ! V_27 -> V_109 )
return - V_185 ;
return F_88 ( V_27 -> V_109 , V_183 , V_184 ) ;
}
static T_5 F_89 ( struct V_186 * V_25 ,
struct V_187 * V_188 , char * V_189 )
{
struct V_26 * V_27 = F_90 ( V_25 ) ;
struct V_1 * V_2 = F_23 ( V_27 ) ;
int V_28 , V_48 = 0 ;
for ( V_28 = 0 ; V_28 < 0x11 ; V_28 ++ )
V_48 += sprintf ( V_189 + V_48 , L_15 , V_2 -> V_23 ( V_2 , V_28 ) ,
( V_28 % 8 ) == 7 ? L_16 : L_17 ) ;
V_48 += sprintf ( V_189 + V_48 , L_16 ) ;
return V_48 ;
}
static int F_91 ( struct V_26 * V_27 )
{
return F_92 ( V_27 -> V_109 ) ;
}
static int F_93 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const void * V_73 ;
T_6 * V_71 ;
int V_190 , V_174 = 0 ;
V_27 = F_94 ( sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_64 ;
F_95 ( V_19 , V_27 ) ;
F_96 ( V_27 , & V_19 -> V_25 ) ;
V_27 -> V_78 &= ~ V_191 ;
V_27 -> V_192 = V_193 ;
V_27 -> V_194 = & V_195 ;
V_27 -> V_196 = & V_197 ;
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
V_2 = F_23 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_25 = & V_19 -> V_25 ;
V_2 -> V_88 = V_198 ;
F_97 ( & V_2 -> V_157 ) ;
F_98 ( & V_2 -> V_65 ) ;
V_2 -> V_4 = F_99 ( V_19 -> V_25 . V_199 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_48 ( & V_19 -> V_25 , L_18 ) ;
V_174 = - V_64 ;
goto V_200;
}
V_2 -> V_159 = 0 ;
V_71 = ( T_6 * ) F_100 ( V_19 -> V_25 . V_199 , L_19 , NULL ) ;
if ( V_71 && F_101 ( * V_71 ) ) {
V_2 -> V_159 |= V_201 ;
V_27 -> V_192 |= V_202 ;
}
V_71 = ( T_6 * ) F_100 ( V_19 -> V_25 . V_199 , L_20 , NULL ) ;
if ( V_71 && F_101 ( * V_71 ) )
V_2 -> V_159 |= V_160 ;
V_21 = F_102 ( V_19 -> V_25 . V_199 , L_21 , 0 ) ;
if ( ! V_21 ) {
F_48 ( & V_19 -> V_25 , L_22 ) ;
V_174 = - V_176 ;
goto V_203;
}
if ( F_17 ( V_2 , V_19 , V_21 ) ) {
V_2 -> V_16 = F_99 ( V_21 , 0 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_23 = F_11 ;
V_2 -> V_24 = F_12 ;
F_21 ( & V_19 -> V_25 , L_23 , V_2 -> V_16 ) ;
} else {
F_48 ( & V_19 -> V_25 , L_24 ) ;
F_103 ( V_21 ) ;
goto V_203;
}
}
V_2 -> V_180 = F_104 ( V_21 , 0 ) ;
V_2 -> V_177 = F_104 ( V_21 , 1 ) ;
F_103 ( V_21 ) ;
if ( ! V_2 -> V_180 || ! V_2 -> V_177 ) {
F_48 ( & V_19 -> V_25 , L_25 ) ;
V_174 = - V_64 ;
goto V_204;
}
V_73 = F_100 ( V_19 -> V_25 . V_199 , L_26 , & V_190 ) ;
if ( ( ! V_73 ) || ( V_190 != 6 ) ) {
F_48 ( & V_19 -> V_25 , L_27 ) ;
V_174 = - V_176 ;
goto V_204;
}
F_36 ( V_27 , ( void * ) V_73 ) ;
V_174 = F_105 ( V_2 , V_19 -> V_25 . V_199 ) ;
if ( V_174 )
F_106 ( & V_19 -> V_25 , L_28 ) ;
V_2 -> V_175 = F_102 ( V_19 -> V_25 . V_199 , L_29 , 0 ) ;
if ( V_2 -> V_175 )
F_21 ( V_2 -> V_25 , L_30 , V_21 -> V_205 , V_21 ) ;
V_174 = F_107 ( & V_2 -> V_25 -> V_206 , & V_207 ) ;
if ( V_174 ) {
F_48 ( V_2 -> V_25 , L_31 ) ;
goto V_204;
}
V_174 = F_108 ( V_2 -> V_27 ) ;
if ( V_174 ) {
F_48 ( V_2 -> V_25 , L_32 , V_174 ) ;
goto V_208;
}
return 0 ;
V_208:
F_109 ( & V_2 -> V_25 -> V_206 , & V_207 ) ;
V_204:
if ( V_2 -> V_16 )
F_110 ( V_2 -> V_16 ) ;
V_203:
F_110 ( V_2 -> V_4 ) ;
V_200:
F_111 ( V_27 ) ;
V_27 = NULL ;
return V_174 ;
}
static int F_112 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_113 ( V_19 ) ;
struct V_1 * V_2 = F_23 ( V_27 ) ;
F_114 ( V_2 ) ;
F_115 ( V_27 ) ;
F_109 ( & V_2 -> V_25 -> V_206 , & V_207 ) ;
F_103 ( V_2 -> V_175 ) ;
V_2 -> V_175 = NULL ;
F_110 ( V_2 -> V_4 ) ;
if ( V_2 -> V_16 )
F_110 ( V_2 -> V_16 ) ;
F_111 ( V_27 ) ;
return 0 ;
}
