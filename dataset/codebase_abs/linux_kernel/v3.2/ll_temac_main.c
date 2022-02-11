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
V_2 -> V_32 = F_28 ( sizeof( * V_2 -> V_32 ) * V_31 , V_44 ) ;
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
F_35 ( V_27 -> V_62 ) ;
F_36 ( & V_2 -> V_64 ) ;
F_9 ( V_2 , V_65 ,
( V_27 -> V_62 [ 0 ] ) |
( V_27 -> V_62 [ 1 ] << 8 ) |
( V_27 -> V_62 [ 2 ] << 16 ) |
( V_27 -> V_62 [ 3 ] << 24 ) ) ;
F_9 ( V_2 , V_66 ,
( V_27 -> V_62 [ 4 ] & 0x000000ff ) |
( V_27 -> V_62 [ 5 ] << 8 ) ) ;
F_37 ( & V_2 -> V_64 ) ;
return 0 ;
}
static int F_38 ( struct V_26 * V_27 , void * V_67 )
{
struct V_68 * V_69 = V_67 ;
return F_33 ( V_27 , V_69 -> V_70 ) ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_71 , V_72 , V_12 ;
int V_28 ;
F_36 ( & V_2 -> V_64 ) ;
if ( V_27 -> V_73 & ( V_74 | V_75 ) ||
F_40 ( V_27 ) > V_76 ) {
V_27 -> V_73 |= V_75 ;
F_9 ( V_2 , V_77 , V_78 ) ;
F_41 ( & V_27 -> V_25 , L_6 ) ;
} else if ( ! F_42 ( V_27 ) ) {
struct V_79 * V_80 ;
V_28 = 0 ;
F_43 (ha, ndev) {
if ( V_28 >= V_76 )
break;
V_71 = ( ( V_80 -> V_69 [ 3 ] << 24 ) |
( V_80 -> V_69 [ 2 ] << 16 ) |
( V_80 -> V_69 [ 1 ] << 8 ) |
( V_80 -> V_69 [ 0 ] ) ) ;
F_9 ( V_2 , V_81 ,
V_71 ) ;
V_72 = ( ( V_80 -> V_69 [ 5 ] << 8 ) |
( V_80 -> V_69 [ 4 ] ) | ( V_28 << 16 ) ) ;
F_9 ( V_2 , V_82 ,
V_72 ) ;
V_28 ++ ;
}
} else {
V_12 = F_8 ( V_2 , V_77 ) ;
F_9 ( V_2 , V_77 ,
V_12 & ~ V_78 ) ;
F_9 ( V_2 , V_81 , 0 ) ;
F_9 ( V_2 , V_82 , 0 ) ;
F_41 ( & V_27 -> V_25 , L_7 ) ;
}
F_37 ( & V_2 -> V_64 ) ;
}
static T_1 F_44 ( struct V_26 * V_27 , T_1 V_83 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_84 * V_85 = & V_86 [ 0 ] ;
int V_11 ;
F_36 ( & V_2 -> V_64 ) ;
while ( V_85 -> V_87 ) {
V_11 = F_8 ( V_2 , V_85 -> V_11 ) & ~ V_85 -> V_88 ;
if ( V_83 & V_85 -> V_87 )
V_11 |= V_85 -> V_88 ;
F_9 ( V_2 , V_85 -> V_11 , V_11 ) ;
V_85 ++ ;
}
V_2 -> V_83 |= V_83 ;
F_37 ( & V_2 -> V_64 ) ;
return 0 ;
}
static void F_45 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
T_1 V_89 ;
T_1 V_12 ;
F_20 ( & V_27 -> V_25 , L_8 , V_90 ) ;
F_36 ( & V_2 -> V_64 ) ;
F_9 ( V_2 , V_91 , V_92 ) ;
V_89 = 1000 ;
while ( F_8 ( V_2 , V_91 ) & V_92 ) {
F_46 ( 1 ) ;
if ( -- V_89 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_9 ) ;
break;
}
}
F_9 ( V_2 , V_93 , V_94 ) ;
V_89 = 1000 ;
while ( F_8 ( V_2 , V_93 ) & V_94 ) {
F_46 ( 1 ) ;
if ( -- V_89 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_10 ) ;
break;
}
}
V_12 = F_8 ( V_2 , V_91 ) ;
F_9 ( V_2 , V_91 , V_12 & ~ V_95 ) ;
V_2 -> V_24 ( V_2 , V_29 , V_30 ) ;
V_89 = 1000 ;
while ( V_2 -> V_23 ( V_2 , V_29 ) & V_30 ) {
F_46 ( 1 ) ;
if ( -- V_89 == 0 ) {
F_29 ( & V_27 -> V_25 ,
L_11 ) ;
break;
}
}
V_2 -> V_24 ( V_2 , V_29 , V_96 ) ;
if ( F_27 ( V_27 ) ) {
F_29 ( & V_27 -> V_25 ,
L_12 ) ;
}
F_9 ( V_2 , V_97 , 0 ) ;
F_9 ( V_2 , V_91 , 0 ) ;
F_9 ( V_2 , V_93 , 0 ) ;
F_9 ( V_2 , V_98 , V_99 ) ;
F_37 ( & V_2 -> V_64 ) ;
F_44 ( V_27 ,
V_2 -> V_83 & ~ ( V_100 | V_101 ) ) ;
F_33 ( V_27 , NULL ) ;
F_39 ( V_27 ) ;
if ( F_44 ( V_27 , V_2 -> V_83 ) )
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
F_36 ( & V_2 -> V_64 ) ;
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
F_37 ( & V_2 -> V_64 ) ;
}
static void F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_120 * V_121 ;
unsigned int V_122 = 0 ;
V_121 = & V_2 -> V_39 [ V_2 -> V_123 ] ;
V_122 = V_121 -> V_49 ;
while ( V_122 & V_124 ) {
F_23 ( V_27 -> V_25 . V_33 , V_121 -> V_35 , V_121 -> V_48 ,
V_125 ) ;
if ( V_121 -> V_126 )
F_50 ( (struct V_42 * ) V_121 -> V_126 ) ;
V_121 -> V_49 = 0 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_121 -> V_129 = 0 ;
V_121 -> V_126 = 0 ;
V_27 -> V_130 . V_131 ++ ;
V_27 -> V_130 . V_132 += V_121 -> V_48 ;
V_2 -> V_123 ++ ;
if ( V_2 -> V_123 >= V_40 )
V_2 -> V_123 = 0 ;
V_121 = & V_2 -> V_39 [ V_2 -> V_123 ] ;
V_122 = V_121 -> V_49 ;
}
F_51 ( V_27 ) ;
}
static inline int F_52 ( struct V_1 * V_2 , int V_133 )
{
struct V_120 * V_121 ;
int V_134 ;
V_134 = V_2 -> V_135 ;
V_121 = & V_2 -> V_39 [ V_134 ] ;
do {
if ( V_121 -> V_49 )
return V_136 ;
V_134 ++ ;
if ( V_134 >= V_40 )
V_134 = 0 ;
V_121 = & V_2 -> V_39 [ V_134 ] ;
V_133 -- ;
} while ( V_133 >= 0 );
return 0 ;
}
static int F_53 ( struct V_42 * V_43 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_120 * V_121 ;
T_2 V_137 , V_138 ;
int V_139 ;
unsigned long V_133 ;
T_3 * V_140 ;
V_133 = F_54 ( V_43 ) -> V_141 ;
V_140 = & F_54 ( V_43 ) -> V_142 [ 0 ] ;
V_137 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_135 ;
V_121 = & V_2 -> V_39 [ V_2 -> V_135 ] ;
if ( F_52 ( V_2 , V_133 ) ) {
if ( ! F_55 ( V_27 ) ) {
F_56 ( V_27 ) ;
return V_136 ;
}
return V_136 ;
}
V_121 -> V_49 = 0 ;
if ( V_43 -> V_143 == V_144 ) {
unsigned int V_145 = F_57 ( V_43 ) ;
unsigned int V_146 = V_145 + V_43 -> V_147 ;
V_121 -> V_49 |= 1 ;
V_121 -> V_127 = ( V_145 << 16 ) | V_146 ;
V_121 -> V_128 = 0 ;
}
V_121 -> V_49 |= V_148 ;
V_121 -> V_48 = F_58 ( V_43 ) ;
V_121 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_43 -> V_47 , V_43 -> V_48 ,
V_125 ) ;
V_121 -> V_126 = ( unsigned long ) V_43 ;
for ( V_139 = 0 ; V_139 < V_133 ; V_139 ++ ) {
V_2 -> V_135 ++ ;
if ( V_2 -> V_135 >= V_40 )
V_2 -> V_135 = 0 ;
V_121 = & V_2 -> V_39 [ V_2 -> V_135 ] ;
V_121 -> V_35 = F_32 ( V_27 -> V_25 . V_33 ,
F_59 ( V_140 ) ,
F_60 ( V_140 ) , V_125 ) ;
V_121 -> V_48 = F_60 ( V_140 ) ;
V_121 -> V_49 = 0 ;
V_140 ++ ;
}
V_121 -> V_49 |= V_149 ;
V_138 = V_2 -> V_41 + sizeof( * V_2 -> V_39 ) * V_2 -> V_135 ;
V_2 -> V_135 ++ ;
if ( V_2 -> V_135 >= V_40 )
V_2 -> V_135 = 0 ;
F_61 ( V_43 ) ;
V_2 -> V_24 ( V_2 , V_150 , V_138 ) ;
return V_151 ;
}
static void F_62 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
struct V_42 * V_43 , * V_152 ;
unsigned int V_153 ;
struct V_120 * V_121 ;
T_2 V_138 ;
int V_154 ;
unsigned long V_73 ;
F_63 ( & V_2 -> V_155 , V_73 ) ;
V_138 = V_2 -> V_38 + sizeof( * V_2 -> V_34 ) * V_2 -> V_156 ;
V_121 = & V_2 -> V_34 [ V_2 -> V_156 ] ;
V_153 = V_121 -> V_49 ;
while ( ( V_153 & V_124 ) ) {
V_43 = V_2 -> V_32 [ V_2 -> V_156 ] ;
V_154 = V_121 -> V_126 & 0x3FFF ;
F_23 ( V_27 -> V_25 . V_33 , V_121 -> V_35 , V_154 ,
V_37 ) ;
F_64 ( V_43 , V_154 ) ;
V_43 -> V_25 = V_27 ;
V_43 -> V_157 = F_65 ( V_43 , V_27 ) ;
F_66 ( V_43 ) ;
if ( ( ( V_2 -> V_158 & V_159 ) != 0 ) &&
( V_43 -> V_157 == F_67 ( V_160 ) ) &&
( V_43 -> V_48 > 64 ) ) {
V_43 -> V_161 = V_121 -> V_129 & 0xFFFF ;
V_43 -> V_143 = V_162 ;
}
if ( ! F_68 ( V_43 ) )
F_69 ( V_43 ) ;
V_27 -> V_130 . V_163 ++ ;
V_27 -> V_130 . V_164 += V_154 ;
V_152 = F_31 ( V_27 ,
V_36 ) ;
if ( V_152 == 0 ) {
F_29 ( & V_27 -> V_25 , L_14 ) ;
F_70 ( & V_2 -> V_155 , V_73 ) ;
return;
}
V_121 -> V_49 = V_50 ;
V_121 -> V_35 = F_32 ( V_27 -> V_25 . V_33 , V_152 -> V_47 ,
V_36 ,
V_37 ) ;
V_121 -> V_48 = V_36 ;
V_2 -> V_32 [ V_2 -> V_156 ] = V_152 ;
V_2 -> V_156 ++ ;
if ( V_2 -> V_156 >= V_31 )
V_2 -> V_156 = 0 ;
V_121 = & V_2 -> V_34 [ V_2 -> V_156 ] ;
V_153 = V_121 -> V_49 ;
}
V_2 -> V_24 ( V_2 , V_58 , V_138 ) ;
F_70 ( & V_2 -> V_155 , V_73 ) ;
}
static T_4 F_71 ( int V_165 , void * V_166 )
{
struct V_26 * V_27 = V_166 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_167 ;
V_167 = V_2 -> V_23 ( V_2 , V_168 ) ;
V_2 -> V_24 ( V_2 , V_168 , V_167 ) ;
if ( V_167 & ( V_169 | V_170 ) )
F_49 ( V_2 -> V_27 ) ;
if ( V_167 & 0x080 )
F_29 ( & V_27 -> V_25 , L_15 , V_167 ) ;
return V_171 ;
}
static T_4 F_72 ( int V_165 , void * V_166 )
{
struct V_26 * V_27 = V_166 ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
unsigned int V_167 ;
V_167 = V_2 -> V_23 ( V_2 , V_172 ) ;
V_2 -> V_24 ( V_2 , V_172 , V_167 ) ;
if ( V_167 & ( V_169 | V_170 ) )
F_62 ( V_2 -> V_27 ) ;
return V_171 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_173 ;
F_20 ( & V_27 -> V_25 , L_16 ) ;
if ( V_2 -> V_174 ) {
V_2 -> V_105 = F_74 ( V_2 -> V_27 , V_2 -> V_174 ,
F_47 , 0 , 0 ) ;
if ( ! V_2 -> V_105 ) {
F_29 ( V_2 -> V_25 , L_17 ) ;
return - V_175 ;
}
F_75 ( V_2 -> V_105 ) ;
}
F_45 ( V_27 ) ;
V_173 = F_76 ( V_2 -> V_176 , F_71 , 0 , V_27 -> V_177 , V_27 ) ;
if ( V_173 )
goto V_178;
V_173 = F_76 ( V_2 -> V_179 , F_72 , 0 , V_27 -> V_177 , V_27 ) ;
if ( V_173 )
goto V_180;
return 0 ;
V_180:
F_77 ( V_2 -> V_176 , V_27 ) ;
V_178:
if ( V_2 -> V_105 )
F_78 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
F_29 ( V_2 -> V_25 , L_18 ) ;
return V_173 ;
}
static int F_79 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_20 ( & V_27 -> V_25 , L_19 ) ;
F_77 ( V_2 -> V_176 , V_27 ) ;
F_77 ( V_2 -> V_179 , V_27 ) ;
if ( V_2 -> V_105 )
F_78 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
F_21 ( V_27 ) ;
return 0 ;
}
static void
F_80 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_81 ( V_2 -> V_176 ) ;
F_81 ( V_2 -> V_179 ) ;
F_72 ( V_2 -> V_176 , V_27 ) ;
F_71 ( V_2 -> V_179 , V_27 ) ;
F_82 ( V_2 -> V_176 ) ;
F_82 ( V_2 -> V_179 ) ;
}
static T_5 F_83 ( struct V_181 * V_25 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_26 * V_27 = F_84 ( V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
int V_28 , V_48 = 0 ;
for ( V_28 = 0 ; V_28 < 0x11 ; V_28 ++ )
V_48 += sprintf ( V_184 + V_48 , L_20 , V_2 -> V_23 ( V_2 , V_28 ) ,
( V_28 % 8 ) == 7 ? L_21 : L_22 ) ;
V_48 += sprintf ( V_184 + V_48 , L_21 ) ;
return V_48 ;
}
static int F_85 ( struct V_26 * V_27 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_86 ( V_2 -> V_105 , V_186 ) ;
}
static int F_87 ( struct V_26 * V_27 , struct V_185 * V_186 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_88 ( V_2 -> V_105 , V_186 ) ;
}
static int F_89 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_22 ( V_27 ) ;
return F_90 ( V_2 -> V_105 ) ;
}
static int T_6 F_91 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const void * V_69 ;
T_7 * V_67 ;
int V_187 , V_173 = 0 ;
V_27 = F_92 ( sizeof( * V_2 ) ) ;
if ( ! V_27 ) {
F_29 ( & V_19 -> V_25 , L_23 ) ;
return - V_60 ;
}
F_93 ( V_27 ) ;
F_94 ( & V_19 -> V_25 , V_27 ) ;
F_95 ( V_27 , & V_19 -> V_25 ) ;
V_27 -> V_73 &= ~ V_188 ;
V_27 -> V_189 = V_190 | V_191 ;
V_27 -> V_192 = & V_193 ;
V_27 -> V_194 = & V_195 ;
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
V_2 -> V_83 = V_196 ;
F_96 ( & V_2 -> V_155 ) ;
F_97 ( & V_2 -> V_64 ) ;
V_2 -> V_4 = F_98 ( V_19 -> V_25 . V_197 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( & V_19 -> V_25 , L_24 ) ;
goto V_198;
}
V_2 -> V_158 = 0 ;
V_67 = ( T_7 * ) F_99 ( V_19 -> V_25 . V_197 , L_25 , NULL ) ;
if ( V_67 && F_100 ( * V_67 ) ) {
V_2 -> V_158 |= V_199 ;
V_27 -> V_189 |= V_200 ;
}
V_67 = ( T_7 * ) F_99 ( V_19 -> V_25 . V_197 , L_26 , NULL ) ;
if ( V_67 && F_100 ( * V_67 ) )
V_2 -> V_158 |= V_159 ;
V_21 = F_101 ( V_19 -> V_25 . V_197 , L_27 , 0 ) ;
if ( ! V_21 ) {
F_29 ( & V_19 -> V_25 , L_28 ) ;
goto V_201;
}
if ( F_16 ( V_2 , V_19 , V_21 ) ) {
V_2 -> V_16 = F_98 ( V_21 , 0 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_23 = F_10 ;
V_2 -> V_24 = F_11 ;
F_20 ( & V_19 -> V_25 , L_29 , V_2 -> V_16 ) ;
} else {
F_29 ( & V_19 -> V_25 , L_30 ) ;
F_102 ( V_21 ) ;
goto V_201;
}
}
V_2 -> V_179 = F_103 ( V_21 , 0 ) ;
V_2 -> V_176 = F_103 ( V_21 , 1 ) ;
F_102 ( V_21 ) ;
if ( ( V_2 -> V_179 == V_202 ) || ( V_2 -> V_176 == V_202 ) ) {
F_29 ( & V_19 -> V_25 , L_31 ) ;
V_173 = - V_60 ;
goto V_203;
}
V_69 = F_99 ( V_19 -> V_25 . V_197 , L_32 , & V_187 ) ;
if ( ( ! V_69 ) || ( V_187 != 6 ) ) {
F_29 ( & V_19 -> V_25 , L_33 ) ;
V_173 = - V_175 ;
goto V_203;
}
F_33 ( V_27 , ( void * ) V_69 ) ;
V_173 = F_104 ( V_2 , V_19 -> V_25 . V_197 ) ;
if ( V_173 )
F_105 ( & V_19 -> V_25 , L_34 ) ;
V_2 -> V_174 = F_101 ( V_19 -> V_25 . V_197 , L_35 , 0 ) ;
if ( V_2 -> V_174 )
F_20 ( V_2 -> V_25 , L_36 , V_21 -> V_204 , V_21 ) ;
V_173 = F_106 ( & V_2 -> V_25 -> V_205 , & V_206 ) ;
if ( V_173 ) {
F_29 ( V_2 -> V_25 , L_37 ) ;
goto V_203;
}
V_173 = F_107 ( V_2 -> V_27 ) ;
if ( V_173 ) {
F_29 ( V_2 -> V_25 , L_38 , V_173 ) ;
goto V_207;
}
return 0 ;
V_207:
F_108 ( & V_2 -> V_25 -> V_205 , & V_206 ) ;
V_203:
if ( V_2 -> V_16 )
F_109 ( V_2 -> V_16 ) ;
V_201:
F_109 ( V_2 -> V_4 ) ;
V_198:
F_110 ( V_27 ) ;
V_27 = NULL ;
return V_173 ;
}
static int T_8 F_111 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_84 ( & V_19 -> V_25 ) ;
struct V_1 * V_2 = F_22 ( V_27 ) ;
F_112 ( V_2 ) ;
F_113 ( V_27 ) ;
F_108 ( & V_2 -> V_25 -> V_205 , & V_206 ) ;
if ( V_2 -> V_174 )
F_102 ( V_2 -> V_174 ) ;
V_2 -> V_174 = NULL ;
F_94 ( & V_19 -> V_25 , NULL ) ;
F_109 ( V_2 -> V_4 ) ;
if ( V_2 -> V_16 )
F_109 ( V_2 -> V_16 ) ;
F_110 ( V_27 ) ;
return 0 ;
}
static int T_9 F_114 ( void )
{
return F_115 ( & V_208 ) ;
}
static void T_10 F_116 ( void )
{
F_117 ( & V_208 ) ;
}
