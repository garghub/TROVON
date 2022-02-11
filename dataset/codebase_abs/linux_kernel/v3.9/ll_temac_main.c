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
if ( ! V_2 -> V_39 ) {
F_30 ( & V_27 -> V_25 ,
L_2 ) ;
goto V_45;
}
V_2 -> V_34 = F_29 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_34 ) * V_31 ,
& V_2 -> V_38 , V_44 ) ;
if ( ! V_2 -> V_34 ) {
F_30 ( & V_27 -> V_25 ,
L_3 ) ;
goto V_45;
}
memset ( V_2 -> V_39 , 0 , sizeof( * V_2 -> V_39 ) * V_40 ) ;
for ( V_28 = 0 ; V_28 < V_40 ; V_28 ++ ) {
V_2 -> V_39 [ V_28 ] . V_46 = V_2 -> V_41 +
sizeof( * V_2 -> V_39 ) * ( ( V_28 + 1 ) % V_40 ) ;
}
memset ( V_2 -> V_34 , 0 , sizeof( * V_2 -> V_34 ) * V_31 ) ;
for ( V_28 = 0 ; V_28 < V_31 ; V_28 ++ ) {
V_2 -> V_34 [ V_28 ] . V_46 = V_2 -> V_38 +
sizeof( * V_2 -> V_34 ) * ( ( V_28 + 1 ) % V_31 ) ;
V_43 = F_31 ( V_27 ,
V_36 ) ;
if ( V_43 == 0 ) {
F_30 ( & V_27 -> V_25 , L_4 , V_28 ) ;
goto V_45;
}
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
return 0 ;
V_45:
F_21 ( V_27 ) ;
return - V_60 ;
}
static void F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_34 ( & V_2 -> V_61 ) ;
F_9 ( V_2 , V_62 ,
( V_27 -> V_63 [ 0 ] ) |
( V_27 -> V_63 [ 1 ] << 8 ) |
( V_27 -> V_63 [ 2 ] << 16 ) |
( V_27 -> V_63 [ 3 ] << 24 ) ) ;
F_9 ( V_2 , V_64 ,
( V_27 -> V_63 [ 4 ] & 0x000000ff ) |
( V_27 -> V_63 [ 5 ] << 8 ) ) ;
F_35 ( & V_2 -> V_61 ) ;
}
static int F_36 ( struct V_26 * V_27 , void * V_65 )
{
memcpy ( V_27 -> V_63 , V_65 , V_66 ) ;
if ( ! F_37 ( V_27 -> V_63 ) )
F_38 ( V_27 ) ;
F_33 ( V_27 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 , void * V_67 )
{
struct V_68 * V_69 = V_67 ;
if ( ! F_37 ( V_69 -> V_70 ) )
return - V_71 ;
memcpy ( V_27 -> V_63 , V_69 -> V_70 , V_66 ) ;
F_33 ( V_27 ) ;
return 0 ;
}
static void F_40 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_72 , V_73 , V_12 ;
int V_28 ;
F_34 ( & V_2 -> V_61 ) ;
if ( V_27 -> V_74 & ( V_75 | V_76 ) ||
F_41 ( V_27 ) > V_77 ) {
V_27 -> V_74 |= V_76 ;
F_9 ( V_2 , V_78 , V_79 ) ;
F_42 ( & V_27 -> V_25 , L_5 ) ;
} else if ( ! F_43 ( V_27 ) ) {
struct V_80 * V_81 ;
V_28 = 0 ;
F_44 (ha, ndev) {
if ( V_28 >= V_77 )
break;
V_72 = ( ( V_81 -> V_69 [ 3 ] << 24 ) |
( V_81 -> V_69 [ 2 ] << 16 ) |
( V_81 -> V_69 [ 1 ] << 8 ) |
( V_81 -> V_69 [ 0 ] ) ) ;
F_9 ( V_2 , V_82 ,
V_72 ) ;
V_73 = ( ( V_81 -> V_69 [ 5 ] << 8 ) |
( V_81 -> V_69 [ 4 ] ) | ( V_28 << 16 ) ) ;
F_9 ( V_2 , V_83 ,
V_73 ) ;
V_28 ++ ;
}
} else {
V_12 = F_8 ( V_2 , V_78 ) ;
F_9 ( V_2 , V_78 ,
V_12 & ~ V_79 ) ;
F_9 ( V_2 , V_82 , 0 ) ;
F_9 ( V_2 , V_83 , 0 ) ;
F_42 ( & V_27 -> V_25 , L_6 ) ;
}
F_35 ( & V_2 -> V_61 ) ;
}
static T_1 F_45 ( struct V_26 * V_27 , T_1 V_84 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_85 * V_86 = & V_87 [ 0 ] ;
int V_11 ;
F_34 ( & V_2 -> V_61 ) ;
while ( V_86 -> V_88 ) {
V_11 = F_8 ( V_2 , V_86 -> V_11 ) & ~ V_86 -> V_89 ;
if ( V_84 & V_86 -> V_88 )
V_11 |= V_86 -> V_89 ;
F_9 ( V_2 , V_86 -> V_11 , V_11 ) ;
V_86 ++ ;
}
V_2 -> V_84 |= V_84 ;
F_35 ( & V_2 -> V_61 ) ;
return 0 ;
}
static void F_46 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_90 ;
T_1 V_12 ;
F_20 ( & V_27 -> V_25 , L_7 , V_91 ) ;
F_34 ( & V_2 -> V_61 ) ;
F_9 ( V_2 , V_92 , V_93 ) ;
V_90 = 1000 ;
while ( F_8 ( V_2 , V_92 ) & V_93 ) {
F_47 ( 1 ) ;
if ( -- V_90 == 0 ) {
F_30 ( & V_27 -> V_25 ,
L_8 ) ;
break;
}
}
F_9 ( V_2 , V_94 , V_95 ) ;
V_90 = 1000 ;
while ( F_8 ( V_2 , V_94 ) & V_95 ) {
F_47 ( 1 ) ;
if ( -- V_90 == 0 ) {
F_30 ( & V_27 -> V_25 ,
L_9 ) ;
break;
}
}
V_12 = F_8 ( V_2 , V_92 ) ;
F_9 ( V_2 , V_92 , V_12 & ~ V_96 ) ;
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
V_90 = 1000 ;
while ( V_2 -> V_23 ( V_2 , V_29 ) & V_30 ) {
F_47 ( 1 ) ;
if ( -- V_90 == 0 ) {
F_30 ( & V_27 -> V_25 ,
L_10 ) ;
break;
}
}
V_2 -> V_24 ( V_2 , V_29 , V_97 ) ;
if ( F_27 ( V_27 ) ) {
F_30 ( & V_27 -> V_25 ,
L_11 ) ;
}
F_9 ( V_2 , V_98 , 0 ) ;
F_9 ( V_2 , V_92 , 0 ) ;
F_9 ( V_2 , V_94 , 0 ) ;
F_9 ( V_2 , V_99 , V_100 ) ;
F_35 ( & V_2 -> V_61 ) ;
F_45 ( V_27 ,
V_2 -> V_84 & ~ ( V_101 | V_102 ) ) ;
F_33 ( V_27 ) ;
F_40 ( V_27 ) ;
if ( F_45 ( V_27 , V_2 -> V_84 ) )
F_30 ( & V_27 -> V_25 , L_12 ) ;
V_27 -> V_103 = V_7 ;
}
void F_48 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_104 * V_105 = V_2 -> V_106 ;
T_1 V_107 ;
int V_108 ;
V_108 = V_105 -> V_109 | ( V_105 -> V_110 << 1 ) | V_105 -> V_111 ;
F_34 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_112 != V_108 ) {
V_107 = F_8 ( V_2 , V_113 ) ;
V_107 &= ~ V_114 ;
switch ( V_105 -> V_109 ) {
case V_115 : V_107 |= V_116 ; break;
case V_117 : V_107 |= V_118 ; break;
case V_119 : V_107 |= V_120 ; break;
}
F_9 ( V_2 , V_113 , V_107 ) ;
V_2 -> V_112 = V_108 ;
F_49 ( V_105 ) ;
}
F_35 ( & V_2 -> V_61 ) ;
}
static void F_50 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_121 * V_122 ;
unsigned int V_123 = 0 ;
V_122 = & V_2 -> V_39 [ V_2 -> V_124 ] ;
V_123 = V_122 -> V_49 ;
while ( V_123 & V_125 ) {
F_23 ( V_27 -> V_25 . V_33 , V_122 -> V_35 , V_122 -> V_48 ,
V_126 ) ;
if ( V_122 -> V_127 )
F_51 ( (struct V_42 * ) V_122 -> V_127 ) ;
V_122 -> V_49 = 0 ;
V_122 -> V_128 = 0 ;
V_122 -> V_129 = 0 ;
V_122 -> V_130 = 0 ;
V_122 -> V_127 = 0 ;
V_27 -> V_131 . V_132 ++ ;
V_27 -> V_131 . V_133 += V_122 -> V_48 ;
V_2 -> V_124 ++ ;
if ( V_2 -> V_124 >= V_40 )
V_2 -> V_124 = 0 ;
V_122 = & V_2 -> V_39 [ V_2 -> V_124 ] ;
V_123 = V_122 -> V_49 ;
}
F_52 ( V_27 ) ;
}
static inline int F_53 ( struct V_1 * V_2 , int V_134 )
{
struct V_121 * V_122 ;
int V_135 ;
V_135 = V_2 -> V_136 ;
V_122 = & V_2 -> V_39 [ V_135 ] ;
do {
if ( V_122 -> V_49 )
return V_137 ;
V_135 ++ ;
if ( V_135 >= V_40 )
V_135 = 0 ;
V_122 = & V_2 -> V_39 [ V_135 ] ;
V_134 -- ;
} while ( V_134 >= 0 );
return 0 ;
}
static int F_54 ( struct V_42 * V_43 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_121 * V_122 ;
T_2 V_138 , V_139 ;
int V_140 ;
unsigned long V_134 ;
T_3 * V_141 ;
V_134 = F_55 ( V_43 ) -> V_142 ;
V_141 = & F_55 ( V_43 ) -> V_143 [ 0 ] ;
V_138 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_136 ;
V_122 = & V_2 -> V_39 [ V_2 -> V_136 ] ;
if ( F_53 ( V_2 , V_134 ) ) {
if ( ! F_56 ( V_27 ) ) {
F_57 ( V_27 ) ;
return V_137 ;
}
return V_137 ;
}
V_122 -> V_49 = 0 ;
if ( V_43 -> V_144 == V_145 ) {
unsigned int V_146 = F_58 ( V_43 ) ;
unsigned int V_147 = V_146 + V_43 -> V_148 ;
V_122 -> V_49 |= 1 ;
V_122 -> V_128 = ( V_146 << 16 ) | V_147 ;
V_122 -> V_129 = 0 ;
}
V_122 -> V_49 |= V_149 ;
V_122 -> V_48 = F_59 ( V_43 ) ;
V_122 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_43 -> V_47 , V_43 -> V_48 ,
V_126 ) ;
V_122 -> V_127 = ( unsigned long ) V_43 ;
for ( V_140 = 0 ; V_140 < V_134 ; V_140 ++ ) {
V_2 -> V_136 ++ ;
if ( V_2 -> V_136 >= V_40 )
V_2 -> V_136 = 0 ;
V_122 = & V_2 -> V_39 [ V_2 -> V_136 ] ;
V_122 -> V_35 = F_32 ( V_27 -> V_25 . V_33 ,
F_60 ( V_141 ) ,
F_61 ( V_141 ) , V_126 ) ;
V_122 -> V_48 = F_61 ( V_141 ) ;
V_122 -> V_49 = 0 ;
V_141 ++ ;
}
V_122 -> V_49 |= V_150 ;
V_139 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_136 ;
V_2 -> V_136 ++ ;
if ( V_2 -> V_136 >= V_40 )
V_2 -> V_136 = 0 ;
F_62 ( V_43 ) ;
V_2 -> V_24 ( V_2 , V_151 , V_139 ) ;
return V_152 ;
}
static void F_63 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_42 * V_43 , * V_153 ;
unsigned int V_154 ;
struct V_121 * V_122 ;
T_2 V_139 ;
int V_155 ;
unsigned long V_74 ;
F_64 ( & V_2 -> V_156 , V_74 ) ;
V_139 = V_2 -> V_38 + sizeof( * V_2 -> V_34 ) * V_2 -> V_157 ;
V_122 = & V_2 -> V_34 [ V_2 -> V_157 ] ;
V_154 = V_122 -> V_49 ;
while ( ( V_154 & V_125 ) ) {
V_43 = V_2 -> V_32 [ V_2 -> V_157 ] ;
V_155 = V_122 -> V_127 & 0x3FFF ;
F_23 ( V_27 -> V_25 . V_33 , V_122 -> V_35 , V_155 ,
V_37 ) ;
F_65 ( V_43 , V_155 ) ;
V_43 -> V_158 = F_66 ( V_43 , V_27 ) ;
F_67 ( V_43 ) ;
if ( ( ( V_2 -> V_159 & V_160 ) != 0 ) &&
( V_43 -> V_158 == F_68 ( V_161 ) ) &&
( V_43 -> V_48 > 64 ) ) {
V_43 -> V_162 = V_122 -> V_130 & 0xFFFF ;
V_43 -> V_144 = V_163 ;
}
if ( ! F_69 ( V_43 ) )
F_70 ( V_43 ) ;
V_27 -> V_131 . V_164 ++ ;
V_27 -> V_131 . V_165 += V_155 ;
V_153 = F_31 ( V_27 ,
V_36 ) ;
if ( V_153 == 0 ) {
F_30 ( & V_27 -> V_25 , L_13 ) ;
F_71 ( & V_2 -> V_156 , V_74 ) ;
return;
}
V_122 -> V_49 = V_50 ;
V_122 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_153 -> V_47 ,
V_36 ,
V_37 ) ;
V_122 -> V_48 = V_36 ;
V_2 -> V_32 [ V_2 -> V_157 ] = V_153 ;
V_2 -> V_157 ++ ;
if ( V_2 -> V_157 >= V_31 )
V_2 -> V_157 = 0 ;
V_122 = & V_2 -> V_34 [ V_2 -> V_157 ] ;
V_154 = V_122 -> V_49 ;
}
V_2 -> V_24 ( V_2 , V_58 , V_139 ) ;
F_71 ( & V_2 -> V_156 , V_74 ) ;
}
static T_4 F_72 ( int V_166 , void * V_167 )
{
struct V_26 * V_27 = V_167 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_168 ;
V_168 = V_2 -> V_23 ( V_2 , V_169 ) ;
V_2 -> V_24 ( V_2 , V_169 , V_168 ) ;
if ( V_168 & ( V_170 | V_171 ) )
F_50 ( V_2 -> V_27 ) ;
if ( V_168 & 0x080 )
F_30 ( & V_27 -> V_25 , L_14 , V_168 ) ;
return V_172 ;
}
static T_4 F_73 ( int V_166 , void * V_167 )
{
struct V_26 * V_27 = V_167 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_168 ;
V_168 = V_2 -> V_23 ( V_2 , V_173 ) ;
V_2 -> V_24 ( V_2 , V_173 , V_168 ) ;
if ( V_168 & ( V_170 | V_171 ) )
F_63 ( V_2 -> V_27 ) ;
return V_172 ;
}
static int F_74 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_174 ;
F_20 ( & V_27 -> V_25 , L_15 ) ;
if ( V_2 -> V_175 ) {
V_2 -> V_106 = F_75 ( V_2 -> V_27 , V_2 -> V_175 ,
F_48 , 0 , 0 ) ;
if ( ! V_2 -> V_106 ) {
F_30 ( V_2 -> V_25 , L_16 ) ;
return - V_176 ;
}
F_76 ( V_2 -> V_106 ) ;
}
F_46 ( V_27 ) ;
V_174 = F_77 ( V_2 -> V_177 , F_72 , 0 , V_27 -> V_178 , V_27 ) ;
if ( V_174 )
goto V_179;
V_174 = F_77 ( V_2 -> V_180 , F_73 , 0 , V_27 -> V_178 , V_27 ) ;
if ( V_174 )
goto V_181;
return 0 ;
V_181:
F_78 ( V_2 -> V_177 , V_27 ) ;
V_179:
if ( V_2 -> V_106 )
F_79 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
F_30 ( V_2 -> V_25 , L_17 ) ;
return V_174 ;
}
static int F_80 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_20 ( & V_27 -> V_25 , L_18 ) ;
F_78 ( V_2 -> V_177 , V_27 ) ;
F_78 ( V_2 -> V_180 , V_27 ) ;
if ( V_2 -> V_106 )
F_79 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
F_21 ( V_27 ) ;
return 0 ;
}
static void
F_81 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_82 ( V_2 -> V_177 ) ;
F_82 ( V_2 -> V_180 ) ;
F_73 ( V_2 -> V_177 , V_27 ) ;
F_72 ( V_2 -> V_180 , V_27 ) ;
F_83 ( V_2 -> V_177 ) ;
F_83 ( V_2 -> V_180 ) ;
}
static int F_84 ( struct V_26 * V_27 , struct V_182 * V_183 , int V_184 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
if ( ! F_85 ( V_27 ) )
return - V_185 ;
if ( ! V_2 -> V_106 )
return - V_185 ;
return F_86 ( V_2 -> V_106 , V_183 , V_184 ) ;
}
static T_5 F_87 ( struct V_186 * V_25 ,
struct V_187 * V_188 , char * V_189 )
{
struct V_26 * V_27 = F_88 ( V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_28 , V_48 = 0 ;
for ( V_28 = 0 ; V_28 < 0x11 ; V_28 ++ )
V_48 += sprintf ( V_189 + V_48 , L_19 , V_2 -> V_23 ( V_2 , V_28 ) ,
( V_28 % 8 ) == 7 ? L_20 : L_21 ) ;
V_48 += sprintf ( V_189 + V_48 , L_20 ) ;
return V_48 ;
}
static int F_89 ( struct V_26 * V_27 , struct V_190 * V_184 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_90 ( V_2 -> V_106 , V_184 ) ;
}
static int F_91 ( struct V_26 * V_27 , struct V_190 * V_184 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_92 ( V_2 -> V_106 , V_184 ) ;
}
static int F_93 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_94 ( V_2 -> V_106 ) ;
}
static int F_95 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const void * V_69 ;
T_6 * V_67 ;
int V_191 , V_174 = 0 ;
V_27 = F_96 ( sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_60 ;
F_97 ( V_27 ) ;
F_98 ( & V_19 -> V_25 , V_27 ) ;
F_99 ( V_27 , & V_19 -> V_25 ) ;
V_27 -> V_74 &= ~ V_192 ;
V_27 -> V_193 = V_194 | V_195 ;
V_27 -> V_196 = & V_197 ;
V_27 -> V_198 = & V_199 ;
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
V_2 -> V_84 = V_200 ;
F_100 ( & V_2 -> V_156 ) ;
F_101 ( & V_2 -> V_61 ) ;
V_2 -> V_4 = F_102 ( V_19 -> V_25 . V_201 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_30 ( & V_19 -> V_25 , L_22 ) ;
goto V_202;
}
V_2 -> V_159 = 0 ;
V_67 = ( T_6 * ) F_103 ( V_19 -> V_25 . V_201 , L_23 , NULL ) ;
if ( V_67 && F_104 ( * V_67 ) ) {
V_2 -> V_159 |= V_203 ;
V_27 -> V_193 |= V_204 ;
}
V_67 = ( T_6 * ) F_103 ( V_19 -> V_25 . V_201 , L_24 , NULL ) ;
if ( V_67 && F_104 ( * V_67 ) )
V_2 -> V_159 |= V_160 ;
V_21 = F_105 ( V_19 -> V_25 . V_201 , L_25 , 0 ) ;
if ( ! V_21 ) {
F_30 ( & V_19 -> V_25 , L_26 ) ;
goto V_205;
}
if ( F_16 ( V_2 , V_19 , V_21 ) ) {
V_2 -> V_16 = F_102 ( V_21 , 0 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_23 = F_10 ;
V_2 -> V_24 = F_11 ;
F_20 ( & V_19 -> V_25 , L_27 , V_2 -> V_16 ) ;
} else {
F_30 ( & V_19 -> V_25 , L_28 ) ;
F_106 ( V_21 ) ;
goto V_205;
}
}
V_2 -> V_180 = F_107 ( V_21 , 0 ) ;
V_2 -> V_177 = F_107 ( V_21 , 1 ) ;
F_106 ( V_21 ) ;
if ( ! V_2 -> V_180 || ! V_2 -> V_177 ) {
F_30 ( & V_19 -> V_25 , L_29 ) ;
V_174 = - V_60 ;
goto V_206;
}
V_69 = F_103 ( V_19 -> V_25 . V_201 , L_30 , & V_191 ) ;
if ( ( ! V_69 ) || ( V_191 != 6 ) ) {
F_30 ( & V_19 -> V_25 , L_31 ) ;
V_174 = - V_176 ;
goto V_206;
}
F_36 ( V_27 , ( void * ) V_69 ) ;
V_174 = F_108 ( V_2 , V_19 -> V_25 . V_201 ) ;
if ( V_174 )
F_109 ( & V_19 -> V_25 , L_32 ) ;
V_2 -> V_175 = F_105 ( V_19 -> V_25 . V_201 , L_33 , 0 ) ;
if ( V_2 -> V_175 )
F_20 ( V_2 -> V_25 , L_34 , V_21 -> V_207 , V_21 ) ;
V_174 = F_110 ( & V_2 -> V_25 -> V_208 , & V_209 ) ;
if ( V_174 ) {
F_30 ( V_2 -> V_25 , L_35 ) ;
goto V_206;
}
V_174 = F_111 ( V_2 -> V_27 ) ;
if ( V_174 ) {
F_30 ( V_2 -> V_25 , L_36 , V_174 ) ;
goto V_210;
}
return 0 ;
V_210:
F_112 ( & V_2 -> V_25 -> V_208 , & V_209 ) ;
V_206:
if ( V_2 -> V_16 )
F_113 ( V_2 -> V_16 ) ;
V_205:
F_113 ( V_2 -> V_4 ) ;
V_202:
F_114 ( V_27 ) ;
V_27 = NULL ;
return V_174 ;
}
static int F_115 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_88 ( & V_19 -> V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_116 ( V_2 ) ;
F_117 ( V_27 ) ;
F_112 ( & V_2 -> V_25 -> V_208 , & V_209 ) ;
if ( V_2 -> V_175 )
F_106 ( V_2 -> V_175 ) ;
V_2 -> V_175 = NULL ;
F_98 ( & V_19 -> V_25 , NULL ) ;
F_113 ( V_2 -> V_4 ) ;
if ( V_2 -> V_16 )
F_113 ( V_2 -> V_16 ) ;
F_114 ( V_27 ) ;
return 0 ;
}
