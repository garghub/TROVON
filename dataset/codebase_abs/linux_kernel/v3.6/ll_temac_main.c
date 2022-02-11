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
if ( ! V_2 -> V_32 ) {
F_29 ( & V_27 -> V_25 ,
L_2 ) ;
goto V_45;
}
V_2 -> V_39 = F_30 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_39 ) * V_40 ,
& V_2 -> V_41 , V_44 ) ;
if ( ! V_2 -> V_39 ) {
F_29 ( & V_27 -> V_25 ,
L_3 ) ;
goto V_45;
}
V_2 -> V_34 = F_30 ( V_27 -> V_25 . V_33 ,
sizeof( * V_2 -> V_34 ) * V_31 ,
& V_2 -> V_38 , V_44 ) ;
if ( ! V_2 -> V_34 ) {
F_29 ( & V_27 -> V_25 ,
L_4 ) ;
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
F_29 ( & V_27 -> V_25 , L_5 , V_28 ) ;
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
static int F_33 ( struct V_26 * V_27 , void * V_61 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
if ( V_61 )
memcpy ( V_27 -> V_62 , V_61 , V_63 ) ;
if ( ! F_34 ( V_27 -> V_62 ) )
F_35 ( V_27 ) ;
else
V_27 -> V_64 &= ~ V_65 ;
F_36 ( & V_2 -> V_66 ) ;
F_9 ( V_2 , V_67 ,
( V_27 -> V_62 [ 0 ] ) |
( V_27 -> V_62 [ 1 ] << 8 ) |
( V_27 -> V_62 [ 2 ] << 16 ) |
( V_27 -> V_62 [ 3 ] << 24 ) ) ;
F_9 ( V_2 , V_68 ,
( V_27 -> V_62 [ 4 ] & 0x000000ff ) |
( V_27 -> V_62 [ 5 ] << 8 ) ) ;
F_37 ( & V_2 -> V_66 ) ;
return 0 ;
}
static int F_38 ( struct V_26 * V_27 , void * V_69 )
{
struct V_70 * V_71 = V_69 ;
return F_33 ( V_27 , V_71 -> V_72 ) ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_73 , V_74 , V_12 ;
int V_28 ;
F_36 ( & V_2 -> V_66 ) ;
if ( V_27 -> V_75 & ( V_76 | V_77 ) ||
F_40 ( V_27 ) > V_78 ) {
V_27 -> V_75 |= V_77 ;
F_9 ( V_2 , V_79 , V_80 ) ;
F_41 ( & V_27 -> V_25 , L_6 ) ;
} else if ( ! F_42 ( V_27 ) ) {
struct V_81 * V_82 ;
V_28 = 0 ;
F_43 (ha, ndev) {
if ( V_28 >= V_78 )
break;
V_73 = ( ( V_82 -> V_71 [ 3 ] << 24 ) |
( V_82 -> V_71 [ 2 ] << 16 ) |
( V_82 -> V_71 [ 1 ] << 8 ) |
( V_82 -> V_71 [ 0 ] ) ) ;
F_9 ( V_2 , V_83 ,
V_73 ) ;
V_74 = ( ( V_82 -> V_71 [ 5 ] << 8 ) |
( V_82 -> V_71 [ 4 ] ) | ( V_28 << 16 ) ) ;
F_9 ( V_2 , V_84 ,
V_74 ) ;
V_28 ++ ;
}
} else {
V_12 = F_8 ( V_2 , V_79 ) ;
F_9 ( V_2 , V_79 ,
V_12 & ~ V_80 ) ;
F_9 ( V_2 , V_83 , 0 ) ;
F_9 ( V_2 , V_84 , 0 ) ;
F_41 ( & V_27 -> V_25 , L_7 ) ;
}
F_37 ( & V_2 -> V_66 ) ;
}
static T_1 F_44 ( struct V_26 * V_27 , T_1 V_85 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_86 * V_87 = & V_88 [ 0 ] ;
int V_11 ;
F_36 ( & V_2 -> V_66 ) ;
while ( V_87 -> V_89 ) {
V_11 = F_8 ( V_2 , V_87 -> V_11 ) & ~ V_87 -> V_90 ;
if ( V_85 & V_87 -> V_89 )
V_11 |= V_87 -> V_90 ;
F_9 ( V_2 , V_87 -> V_11 , V_11 ) ;
V_87 ++ ;
}
V_2 -> V_85 |= V_85 ;
F_37 ( & V_2 -> V_66 ) ;
return 0 ;
}
static void F_45 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_91 ;
T_1 V_12 ;
F_20 ( & V_27 -> V_25 , L_8 , V_92 ) ;
F_36 ( & V_2 -> V_66 ) ;
F_9 ( V_2 , V_93 , V_94 ) ;
V_91 = 1000 ;
while ( F_8 ( V_2 , V_93 ) & V_94 ) {
F_46 ( 1 ) ;
if ( -- V_91 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_9 ) ;
break;
}
}
F_9 ( V_2 , V_95 , V_96 ) ;
V_91 = 1000 ;
while ( F_8 ( V_2 , V_95 ) & V_96 ) {
F_46 ( 1 ) ;
if ( -- V_91 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_10 ) ;
break;
}
}
V_12 = F_8 ( V_2 , V_93 ) ;
F_9 ( V_2 , V_93 , V_12 & ~ V_97 ) ;
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
V_91 = 1000 ;
while ( V_2 -> V_23 ( V_2 , V_29 ) & V_30 ) {
F_46 ( 1 ) ;
if ( -- V_91 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_11 ) ;
break;
}
}
V_2 -> V_24 ( V_2 , V_29 , V_98 ) ;
if ( F_27 ( V_27 ) ) {
F_29 ( & V_27 -> V_25 ,
L_12 ) ;
}
F_9 ( V_2 , V_99 , 0 ) ;
F_9 ( V_2 , V_93 , 0 ) ;
F_9 ( V_2 , V_95 , 0 ) ;
F_9 ( V_2 , V_100 , V_101 ) ;
F_37 ( & V_2 -> V_66 ) ;
F_44 ( V_27 ,
V_2 -> V_85 & ~ ( V_102 | V_103 ) ) ;
F_33 ( V_27 , NULL ) ;
F_39 ( V_27 ) ;
if ( F_44 ( V_27 , V_2 -> V_85 ) )
F_29 ( & V_27 -> V_25 , L_13 ) ;
V_27 -> V_104 = V_7 ;
}
void F_47 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_105 * V_106 = V_2 -> V_107 ;
T_1 V_108 ;
int V_109 ;
V_109 = V_106 -> V_110 | ( V_106 -> V_111 << 1 ) | V_106 -> V_112 ;
F_36 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_113 != V_109 ) {
V_108 = F_8 ( V_2 , V_114 ) ;
V_108 &= ~ V_115 ;
switch ( V_106 -> V_110 ) {
case V_116 : V_108 |= V_117 ; break;
case V_118 : V_108 |= V_119 ; break;
case V_120 : V_108 |= V_121 ; break;
}
F_9 ( V_2 , V_114 , V_108 ) ;
V_2 -> V_113 = V_109 ;
F_48 ( V_106 ) ;
}
F_37 ( & V_2 -> V_66 ) ;
}
static void F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_122 * V_123 ;
unsigned int V_124 = 0 ;
V_123 = & V_2 -> V_39 [ V_2 -> V_125 ] ;
V_124 = V_123 -> V_49 ;
while ( V_124 & V_126 ) {
F_23 ( V_27 -> V_25 . V_33 , V_123 -> V_35 , V_123 -> V_48 ,
V_127 ) ;
if ( V_123 -> V_128 )
F_50 ( (struct V_42 * ) V_123 -> V_128 ) ;
V_123 -> V_49 = 0 ;
V_123 -> V_129 = 0 ;
V_123 -> V_130 = 0 ;
V_123 -> V_131 = 0 ;
V_123 -> V_128 = 0 ;
V_27 -> V_132 . V_133 ++ ;
V_27 -> V_132 . V_134 += V_123 -> V_48 ;
V_2 -> V_125 ++ ;
if ( V_2 -> V_125 >= V_40 )
V_2 -> V_125 = 0 ;
V_123 = & V_2 -> V_39 [ V_2 -> V_125 ] ;
V_124 = V_123 -> V_49 ;
}
F_51 ( V_27 ) ;
}
static inline int F_52 ( struct V_1 * V_2 , int V_135 )
{
struct V_122 * V_123 ;
int V_136 ;
V_136 = V_2 -> V_137 ;
V_123 = & V_2 -> V_39 [ V_136 ] ;
do {
if ( V_123 -> V_49 )
return V_138 ;
V_136 ++ ;
if ( V_136 >= V_40 )
V_136 = 0 ;
V_123 = & V_2 -> V_39 [ V_136 ] ;
V_135 -- ;
} while ( V_135 >= 0 );
return 0 ;
}
static int F_53 ( struct V_42 * V_43 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_122 * V_123 ;
T_2 V_139 , V_140 ;
int V_141 ;
unsigned long V_135 ;
T_3 * V_142 ;
V_135 = F_54 ( V_43 ) -> V_143 ;
V_142 = & F_54 ( V_43 ) -> V_144 [ 0 ] ;
V_139 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_137 ;
V_123 = & V_2 -> V_39 [ V_2 -> V_137 ] ;
if ( F_52 ( V_2 , V_135 ) ) {
if ( ! F_55 ( V_27 ) ) {
F_56 ( V_27 ) ;
return V_138 ;
}
return V_138 ;
}
V_123 -> V_49 = 0 ;
if ( V_43 -> V_145 == V_146 ) {
unsigned int V_147 = F_57 ( V_43 ) ;
unsigned int V_148 = V_147 + V_43 -> V_149 ;
V_123 -> V_49 |= 1 ;
V_123 -> V_129 = ( V_147 << 16 ) | V_148 ;
V_123 -> V_130 = 0 ;
}
V_123 -> V_49 |= V_150 ;
V_123 -> V_48 = F_58 ( V_43 ) ;
V_123 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_43 -> V_47 , V_43 -> V_48 ,
V_127 ) ;
V_123 -> V_128 = ( unsigned long ) V_43 ;
for ( V_141 = 0 ; V_141 < V_135 ; V_141 ++ ) {
V_2 -> V_137 ++ ;
if ( V_2 -> V_137 >= V_40 )
V_2 -> V_137 = 0 ;
V_123 = & V_2 -> V_39 [ V_2 -> V_137 ] ;
V_123 -> V_35 = F_32 ( V_27 -> V_25 . V_33 ,
F_59 ( V_142 ) ,
F_60 ( V_142 ) , V_127 ) ;
V_123 -> V_48 = F_60 ( V_142 ) ;
V_123 -> V_49 = 0 ;
V_142 ++ ;
}
V_123 -> V_49 |= V_151 ;
V_140 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_137 ;
V_2 -> V_137 ++ ;
if ( V_2 -> V_137 >= V_40 )
V_2 -> V_137 = 0 ;
F_61 ( V_43 ) ;
V_2 -> V_24 ( V_2 , V_152 , V_140 ) ;
return V_153 ;
}
static void F_62 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_42 * V_43 , * V_154 ;
unsigned int V_155 ;
struct V_122 * V_123 ;
T_2 V_140 ;
int V_156 ;
unsigned long V_75 ;
F_63 ( & V_2 -> V_157 , V_75 ) ;
V_140 = V_2 -> V_38 + sizeof( * V_2 -> V_34 ) * V_2 -> V_158 ;
V_123 = & V_2 -> V_34 [ V_2 -> V_158 ] ;
V_155 = V_123 -> V_49 ;
while ( ( V_155 & V_126 ) ) {
V_43 = V_2 -> V_32 [ V_2 -> V_158 ] ;
V_156 = V_123 -> V_128 & 0x3FFF ;
F_23 ( V_27 -> V_25 . V_33 , V_123 -> V_35 , V_156 ,
V_37 ) ;
F_64 ( V_43 , V_156 ) ;
V_43 -> V_159 = F_65 ( V_43 , V_27 ) ;
F_66 ( V_43 ) ;
if ( ( ( V_2 -> V_160 & V_161 ) != 0 ) &&
( V_43 -> V_159 == F_67 ( V_162 ) ) &&
( V_43 -> V_48 > 64 ) ) {
V_43 -> V_163 = V_123 -> V_131 & 0xFFFF ;
V_43 -> V_145 = V_164 ;
}
if ( ! F_68 ( V_43 ) )
F_69 ( V_43 ) ;
V_27 -> V_132 . V_165 ++ ;
V_27 -> V_132 . V_166 += V_156 ;
V_154 = F_31 ( V_27 ,
V_36 ) ;
if ( V_154 == 0 ) {
F_29 ( & V_27 -> V_25 , L_14 ) ;
F_70 ( & V_2 -> V_157 , V_75 ) ;
return;
}
V_123 -> V_49 = V_50 ;
V_123 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_154 -> V_47 ,
V_36 ,
V_37 ) ;
V_123 -> V_48 = V_36 ;
V_2 -> V_32 [ V_2 -> V_158 ] = V_154 ;
V_2 -> V_158 ++ ;
if ( V_2 -> V_158 >= V_31 )
V_2 -> V_158 = 0 ;
V_123 = & V_2 -> V_34 [ V_2 -> V_158 ] ;
V_155 = V_123 -> V_49 ;
}
V_2 -> V_24 ( V_2 , V_58 , V_140 ) ;
F_70 ( & V_2 -> V_157 , V_75 ) ;
}
static T_4 F_71 ( int V_167 , void * V_168 )
{
struct V_26 * V_27 = V_168 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_169 ;
V_169 = V_2 -> V_23 ( V_2 , V_170 ) ;
V_2 -> V_24 ( V_2 , V_170 , V_169 ) ;
if ( V_169 & ( V_171 | V_172 ) )
F_49 ( V_2 -> V_27 ) ;
if ( V_169 & 0x080 )
F_29 ( & V_27 -> V_25 , L_15 , V_169 ) ;
return V_173 ;
}
static T_4 F_72 ( int V_167 , void * V_168 )
{
struct V_26 * V_27 = V_168 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_169 ;
V_169 = V_2 -> V_23 ( V_2 , V_174 ) ;
V_2 -> V_24 ( V_2 , V_174 , V_169 ) ;
if ( V_169 & ( V_171 | V_172 ) )
F_62 ( V_2 -> V_27 ) ;
return V_173 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_175 ;
F_20 ( & V_27 -> V_25 , L_16 ) ;
if ( V_2 -> V_176 ) {
V_2 -> V_107 = F_74 ( V_2 -> V_27 , V_2 -> V_176 ,
F_47 , 0 , 0 ) ;
if ( ! V_2 -> V_107 ) {
F_29 ( V_2 -> V_25 , L_17 ) ;
return - V_177 ;
}
F_75 ( V_2 -> V_107 ) ;
}
F_45 ( V_27 ) ;
V_175 = F_76 ( V_2 -> V_178 , F_71 , 0 , V_27 -> V_179 , V_27 ) ;
if ( V_175 )
goto V_180;
V_175 = F_76 ( V_2 -> V_181 , F_72 , 0 , V_27 -> V_179 , V_27 ) ;
if ( V_175 )
goto V_182;
return 0 ;
V_182:
F_77 ( V_2 -> V_178 , V_27 ) ;
V_180:
if ( V_2 -> V_107 )
F_78 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
F_29 ( V_2 -> V_25 , L_18 ) ;
return V_175 ;
}
static int F_79 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_20 ( & V_27 -> V_25 , L_19 ) ;
F_77 ( V_2 -> V_178 , V_27 ) ;
F_77 ( V_2 -> V_181 , V_27 ) ;
if ( V_2 -> V_107 )
F_78 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
F_21 ( V_27 ) ;
return 0 ;
}
static void
F_80 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_81 ( V_2 -> V_178 ) ;
F_81 ( V_2 -> V_181 ) ;
F_72 ( V_2 -> V_178 , V_27 ) ;
F_71 ( V_2 -> V_181 , V_27 ) ;
F_82 ( V_2 -> V_178 ) ;
F_82 ( V_2 -> V_181 ) ;
}
static int F_83 ( struct V_26 * V_27 , struct V_183 * V_184 , int V_185 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
if ( ! F_84 ( V_27 ) )
return - V_186 ;
if ( ! V_2 -> V_107 )
return - V_186 ;
return F_85 ( V_2 -> V_107 , V_184 , V_185 ) ;
}
static T_5 F_86 ( struct V_187 * V_25 ,
struct V_188 * V_189 , char * V_190 )
{
struct V_26 * V_27 = F_87 ( V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_28 , V_48 = 0 ;
for ( V_28 = 0 ; V_28 < 0x11 ; V_28 ++ )
V_48 += sprintf ( V_190 + V_48 , L_20 , V_2 -> V_23 ( V_2 , V_28 ) ,
( V_28 % 8 ) == 7 ? L_21 : L_22 ) ;
V_48 += sprintf ( V_190 + V_48 , L_21 ) ;
return V_48 ;
}
static int F_88 ( struct V_26 * V_27 , struct V_191 * V_185 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_89 ( V_2 -> V_107 , V_185 ) ;
}
static int F_90 ( struct V_26 * V_27 , struct V_191 * V_185 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_91 ( V_2 -> V_107 , V_185 ) ;
}
static int F_92 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_93 ( V_2 -> V_107 ) ;
}
static int T_6 F_94 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const void * V_71 ;
T_7 * V_69 ;
int V_192 , V_175 = 0 ;
V_27 = F_95 ( sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_60 ;
F_96 ( V_27 ) ;
F_97 ( & V_19 -> V_25 , V_27 ) ;
F_98 ( V_27 , & V_19 -> V_25 ) ;
V_27 -> V_75 &= ~ V_193 ;
V_27 -> V_194 = V_195 | V_196 ;
V_27 -> V_197 = & V_198 ;
V_27 -> V_199 = & V_200 ;
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
V_2 -> V_85 = V_201 ;
F_99 ( & V_2 -> V_157 ) ;
F_100 ( & V_2 -> V_66 ) ;
V_2 -> V_4 = F_101 ( V_19 -> V_25 . V_202 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( & V_19 -> V_25 , L_23 ) ;
goto V_203;
}
V_2 -> V_160 = 0 ;
V_69 = ( T_7 * ) F_102 ( V_19 -> V_25 . V_202 , L_24 , NULL ) ;
if ( V_69 && F_103 ( * V_69 ) ) {
V_2 -> V_160 |= V_204 ;
V_27 -> V_194 |= V_205 ;
}
V_69 = ( T_7 * ) F_102 ( V_19 -> V_25 . V_202 , L_25 , NULL ) ;
if ( V_69 && F_103 ( * V_69 ) )
V_2 -> V_160 |= V_161 ;
V_21 = F_104 ( V_19 -> V_25 . V_202 , L_26 , 0 ) ;
if ( ! V_21 ) {
F_29 ( & V_19 -> V_25 , L_27 ) ;
goto V_206;
}
if ( F_16 ( V_2 , V_19 , V_21 ) ) {
V_2 -> V_16 = F_101 ( V_21 , 0 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_23 = F_10 ;
V_2 -> V_24 = F_11 ;
F_20 ( & V_19 -> V_25 , L_28 , V_2 -> V_16 ) ;
} else {
F_29 ( & V_19 -> V_25 , L_29 ) ;
F_105 ( V_21 ) ;
goto V_206;
}
}
V_2 -> V_181 = F_106 ( V_21 , 0 ) ;
V_2 -> V_178 = F_106 ( V_21 , 1 ) ;
F_105 ( V_21 ) ;
if ( ! V_2 -> V_181 || ! V_2 -> V_178 ) {
F_29 ( & V_19 -> V_25 , L_30 ) ;
V_175 = - V_60 ;
goto V_207;
}
V_71 = F_102 ( V_19 -> V_25 . V_202 , L_31 , & V_192 ) ;
if ( ( ! V_71 ) || ( V_192 != 6 ) ) {
F_29 ( & V_19 -> V_25 , L_32 ) ;
V_175 = - V_177 ;
goto V_207;
}
F_33 ( V_27 , ( void * ) V_71 ) ;
V_175 = F_107 ( V_2 , V_19 -> V_25 . V_202 ) ;
if ( V_175 )
F_108 ( & V_19 -> V_25 , L_33 ) ;
V_2 -> V_176 = F_104 ( V_19 -> V_25 . V_202 , L_34 , 0 ) ;
if ( V_2 -> V_176 )
F_20 ( V_2 -> V_25 , L_35 , V_21 -> V_208 , V_21 ) ;
V_175 = F_109 ( & V_2 -> V_25 -> V_209 , & V_210 ) ;
if ( V_175 ) {
F_29 ( V_2 -> V_25 , L_36 ) ;
goto V_207;
}
V_175 = F_110 ( V_2 -> V_27 ) ;
if ( V_175 ) {
F_29 ( V_2 -> V_25 , L_37 , V_175 ) ;
goto V_211;
}
return 0 ;
V_211:
F_111 ( & V_2 -> V_25 -> V_209 , & V_210 ) ;
V_207:
if ( V_2 -> V_16 )
F_112 ( V_2 -> V_16 ) ;
V_206:
F_112 ( V_2 -> V_4 ) ;
V_203:
F_113 ( V_27 ) ;
V_27 = NULL ;
return V_175 ;
}
static int T_8 F_114 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_87 ( & V_19 -> V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_115 ( V_2 ) ;
F_116 ( V_27 ) ;
F_111 ( & V_2 -> V_25 -> V_209 , & V_210 ) ;
if ( V_2 -> V_176 )
F_105 ( V_2 -> V_176 ) ;
V_2 -> V_176 = NULL ;
F_97 ( & V_19 -> V_25 , NULL ) ;
F_112 ( V_2 -> V_4 ) ;
if ( V_2 -> V_16 )
F_112 ( V_2 -> V_16 ) ;
F_113 ( V_27 ) ;
return 0 ;
}
