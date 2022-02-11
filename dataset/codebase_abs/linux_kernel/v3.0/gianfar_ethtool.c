static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 & V_8 )
memcpy ( V_4 , V_9 , V_10 * V_11 ) ;
else
memcpy ( V_4 , V_9 ,
V_12 * V_11 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_13 * V_14 , T_3 * V_4 )
{
int V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_3 * V_19 = ( T_3 * ) & V_6 -> V_20 ;
if ( V_6 -> V_7 & V_8 ) {
T_1 T_4 * V_21 = ( T_1 T_4 * ) & V_17 -> V_21 ;
struct V_22 * V_23 = (struct V_22 * ) V_4 ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ )
V_23 -> V_21 [ V_15 ] = ( T_3 ) F_4 ( & V_21 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_23 -> V_19 [ V_15 ] = V_19 [ V_15 ] ;
} else
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_4 [ V_15 ] = V_19 [ V_15 ] ;
}
static int F_5 ( struct V_1 * V_2 , int V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_25 ) {
case V_26 :
if ( V_6 -> V_7 & V_8 )
return V_10 ;
else
return V_12 ;
default:
return - V_27 ;
}
}
static void F_6 ( struct V_1 * V_2 , struct
V_28 * V_29 )
{
strncpy ( V_29 -> V_30 , V_31 , V_32 ) ;
strncpy ( V_29 -> V_33 , V_34 , V_32 ) ;
strncpy ( V_29 -> V_35 , L_1 , V_32 ) ;
strncpy ( V_29 -> V_36 , L_1 , V_32 ) ;
V_29 -> V_37 = 0 ;
V_29 -> V_38 = 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_41 * V_42 = V_6 -> V_42 ;
if ( NULL == V_42 )
return - V_43 ;
return F_8 ( V_42 , V_40 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_41 * V_42 = V_6 -> V_42 ;
struct V_44 * V_45 = NULL ;
struct V_46 * V_47 = NULL ;
if ( NULL == V_42 )
return - V_43 ;
V_47 = V_6 -> V_47 [ 0 ] ;
V_45 = V_6 -> V_45 [ 0 ] ;
V_40 -> V_48 = F_10 ( V_47 -> V_49 ) ;
V_40 -> V_50 = F_10 ( V_45 -> V_51 ) ;
return F_11 ( V_42 , V_40 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return sizeof ( struct V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_52 * V_17 , void * V_53 )
{
int V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 T_4 * V_54 = ( T_1 T_4 * ) V_6 -> V_18 [ 0 ] . V_17 ;
T_1 * V_4 = ( T_1 * ) V_53 ;
for ( V_15 = 0 ; V_15 < sizeof ( struct V_16 ) / sizeof ( T_1 ) ; V_15 ++ )
V_4 [ V_15 ] = F_4 ( & V_54 [ V_15 ] ) ;
}
static unsigned int F_14 ( struct V_5 * V_6 , unsigned int V_55 )
{
unsigned int V_56 ;
switch ( V_6 -> V_42 -> V_57 ) {
case V_58 :
V_56 = V_59 ;
break;
case V_60 :
V_56 = V_61 ;
break;
case V_62 :
default:
V_56 = V_63 ;
break;
}
return ( V_55 * 1000 + V_56 - 1 ) / V_56 ;
}
static unsigned int F_15 ( struct V_5 * V_6 , unsigned int V_64 )
{
unsigned int V_56 ;
switch ( V_6 -> V_42 -> V_57 ) {
case V_58 :
V_56 = V_59 ;
break;
case V_60 :
V_56 = V_61 ;
break;
case V_62 :
default:
V_56 = V_63 ;
break;
}
return ( V_64 * V_56 ) / 1000 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_44 * V_45 = NULL ;
struct V_46 * V_47 = NULL ;
unsigned long V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
unsigned long V_70 ;
if ( ! ( V_6 -> V_7 & V_71 ) )
return - V_27 ;
if ( NULL == V_6 -> V_42 )
return - V_43 ;
V_45 = V_6 -> V_45 [ 0 ] ;
V_47 = V_6 -> V_47 [ 0 ] ;
V_67 = F_17 ( V_45 -> V_51 ) ;
V_68 = F_10 ( V_45 -> V_51 ) ;
V_69 = F_17 ( V_47 -> V_49 ) ;
V_70 = F_10 ( V_47 -> V_49 ) ;
V_66 -> V_72 = F_15 ( V_6 , V_67 ) ;
V_66 -> V_73 = V_68 ;
V_66 -> V_74 = F_15 ( V_6 , V_69 ) ;
V_66 -> V_75 = V_70 ;
V_66 -> V_76 = 0 ;
V_66 -> V_77 = 0 ;
V_66 -> V_78 = 0 ;
V_66 -> V_79 = 0 ;
V_66 -> V_80 = 0 ;
V_66 -> V_81 = 0 ;
V_66 -> V_82 = 0 ;
V_66 -> V_83 = 0 ;
V_66 -> V_84 = 0 ;
V_66 -> V_85 = 0 ;
V_66 -> V_86 = 0 ;
V_66 -> V_87 = 0 ;
V_66 -> V_88 = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 = 0 ;
if ( ! ( V_6 -> V_7 & V_71 ) )
return - V_27 ;
if ( ( V_66 -> V_72 == 0 ) ||
( V_66 -> V_73 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
V_6 -> V_45 [ V_15 ] -> V_90 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
V_6 -> V_45 [ V_15 ] -> V_90 = 1 ;
}
if ( NULL == V_6 -> V_42 )
return - V_43 ;
if ( V_66 -> V_72 > V_91 ) {
F_19 ( L_2 ,
V_91 ) ;
return - V_92 ;
}
if ( V_66 -> V_73 > V_93 ) {
F_19 ( L_3 ,
V_93 ) ;
return - V_92 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ ) {
V_6 -> V_45 [ V_15 ] -> V_51 = F_20 (
V_66 -> V_73 ,
F_14 ( V_6 , V_66 -> V_72 ) ) ;
}
if ( ( V_66 -> V_74 == 0 ) ||
( V_66 -> V_75 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_94 ; V_15 ++ )
V_6 -> V_47 [ V_15 ] -> V_95 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_94 ; V_15 ++ )
V_6 -> V_47 [ V_15 ] -> V_95 = 1 ;
}
if ( V_66 -> V_74 > V_91 ) {
F_19 ( L_2 ,
V_91 ) ;
return - V_92 ;
}
if ( V_66 -> V_75 > V_93 ) {
F_19 ( L_3 ,
V_93 ) ;
return - V_92 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_94 ; V_15 ++ ) {
V_6 -> V_47 [ V_15 ] -> V_49 = F_20 (
V_66 -> V_75 ,
F_14 ( V_6 , V_66 -> V_74 ) ) ;
}
F_21 ( V_6 , 0xFF , 0xFF ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_46 * V_47 = NULL ;
struct V_44 * V_45 = NULL ;
V_47 = V_6 -> V_47 [ 0 ] ;
V_45 = V_6 -> V_45 [ 0 ] ;
V_97 -> V_98 = V_99 ;
V_97 -> V_100 = V_99 ;
V_97 -> V_101 = V_99 ;
V_97 -> V_102 = V_103 ;
V_97 -> V_104 = V_45 -> V_105 ;
V_97 -> V_106 = V_45 -> V_105 ;
V_97 -> V_107 = V_45 -> V_105 ;
V_97 -> V_108 = V_47 -> V_109 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_110 = 0 , V_15 = 0 ;
if ( V_97 -> V_104 > V_99 )
return - V_92 ;
if ( ! F_24 ( V_97 -> V_104 ) ) {
F_25 ( L_4 ,
V_2 -> V_111 ) ;
return - V_92 ;
}
if ( V_97 -> V_108 > V_103 )
return - V_92 ;
if ( ! F_24 ( V_97 -> V_108 ) ) {
F_25 ( L_4 ,
V_2 -> V_111 ) ;
return - V_92 ;
}
if ( V_2 -> V_112 & V_113 ) {
unsigned long V_112 ;
F_26 ( V_112 ) ;
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
F_29 ( V_2 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_112 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
F_33 ( V_6 -> V_45 [ V_15 ] ,
V_6 -> V_45 [ V_15 ] -> V_105 ) ;
F_34 ( V_2 ) ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ ) {
V_6 -> V_45 [ V_15 ] -> V_105 = V_97 -> V_104 ;
V_6 -> V_47 [ V_15 ] -> V_109 = V_97 -> V_108 ;
V_6 -> V_47 [ V_15 ] -> V_114 = V_6 -> V_47 [ V_15 ] -> V_109 ;
}
if ( V_2 -> V_112 & V_113 ) {
V_110 = F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
return V_110 ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_112 ;
int V_110 = 0 , V_15 = 0 ;
T_1 V_116 = V_2 -> V_115 ^ V_115 ;
if ( ! ( V_116 & V_117 ) )
return 0 ;
if ( V_2 -> V_112 & V_113 ) {
F_26 ( V_112 ) ;
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
F_29 ( V_2 ) ;
F_31 ( V_6 ) ;
F_30 ( V_6 ) ;
F_32 ( V_112 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
F_33 ( V_6 -> V_45 [ V_15 ] ,
V_6 -> V_45 [ V_15 ] -> V_105 ) ;
F_34 ( V_2 ) ;
V_2 -> V_115 = V_115 ;
V_110 = F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
return V_110 ;
}
static T_5 F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_118 ;
}
static void F_39 ( struct V_1 * V_2 , T_5 V_119 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_118 = V_119 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 & V_122 ) {
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_6 -> V_126 ? V_124 : 0 ;
} else {
V_121 -> V_123 = V_121 -> V_125 = 0 ;
}
}
static int F_41 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_112 ;
if ( ! ( V_6 -> V_7 & V_122 ) &&
V_121 -> V_125 != 0 )
return - V_92 ;
if ( V_121 -> V_125 & ~ V_124 )
return - V_92 ;
F_42 ( & V_2 -> V_2 , V_121 -> V_125 & V_124 ) ;
F_43 ( & V_6 -> V_127 , V_112 ) ;
V_6 -> V_126 = ! ! F_44 ( & V_2 -> V_2 ) ;
F_45 ( & V_6 -> V_127 , V_112 ) ;
return 0 ;
}
static void F_46 ( struct V_5 * V_6 , T_3 V_128 )
{
T_1 V_129 = 0x0 , V_130 = V_131 ;
if ( V_128 & V_132 ) {
V_129 = V_133 | V_134 |
V_135 | V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
V_129 = V_141 | V_136 | V_134 |
V_135 | V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
if ( V_128 & V_142 ) {
V_129 = V_143 | V_134 | V_135 |
V_136 | V_137 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
if ( V_128 & V_144 ) {
V_129 = V_145 | V_134 | V_135 |
V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
if ( V_128 & ( V_146 ) ) {
V_129 = V_147 | V_134 | V_135 |
V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
if ( V_128 & V_148 ) {
V_129 = V_149 | V_134 | V_135 |
V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
if ( V_128 & V_150 ) {
V_129 = V_151 | V_134 | V_135 |
V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
if ( V_128 & V_152 ) {
V_129 = V_153 | V_134 | V_135 |
V_136 | V_137 ;
V_6 -> V_138 [ V_6 -> V_139 ] = V_130 ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_129 ;
F_47 ( V_6 , V_6 -> V_139 , V_129 , V_130 ) ;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
}
static int F_48 ( struct V_5 * V_6 , T_3 V_128 , T_3 V_154 )
{
unsigned int V_155 = V_6 -> V_139 ;
unsigned int V_156 ;
unsigned int V_157 [ V_158 + 1 ] ;
unsigned int V_159 [ V_158 + 1 ] ;
int V_15 = 0x0 , V_160 = 0x0 ;
int V_161 = V_158 , V_162 = 0x0 ;
switch ( V_154 ) {
case V_163 :
V_156 = V_164 | V_165 ;
break;
case V_166 :
V_156 = V_164 | V_167 ;
break;
case V_168 :
V_156 = V_169 | V_165 ;
break;
case V_170 :
V_156 = V_169 | V_167 ;
break;
default:
F_25 ( V_171 L_5 ) ;
return 0 ;
}
for ( V_15 = 0 ; V_15 < V_158 + 1 ; V_15 ++ ) {
V_157 [ V_161 ] = V_6 -> V_138 [ V_15 ] ;
V_159 [ V_161 ] = V_6 -> V_140 [ V_15 ] ;
V_161 -- ;
if ( ( V_6 -> V_140 [ V_15 ] == ( V_172 |
V_173 | V_136 ) ) &&
( V_6 -> V_138 [ V_15 ] == V_156 ) )
break;
}
if ( V_15 == V_158 + 1 ) {
F_25 ( V_171 L_6 ) ;
F_25 ( V_171 L_7 ) ;
return 0 ;
}
for ( V_162 = V_15 + 1 ; V_162 < V_158 ; V_162 ++ ) {
if ( ( V_6 -> V_140 [ V_162 ] & V_173 ) &&
! ( V_6 -> V_140 [ V_162 ] & V_136 ) ) {
V_6 -> V_140 [ V_162 ] = V_173 | V_174 |
V_137 | V_175 ;
V_6 -> V_138 [ V_162 ] = V_131 ;
F_47 ( V_6 , V_162 , V_6 -> V_140 [ V_162 ] ,
V_6 -> V_138 [ V_162 ] ) ;
break;
}
if ( ! ( V_6 -> V_140 [ V_162 ] & V_173 ) &&
( V_6 -> V_140 [ V_162 ] & V_136 ) )
continue;
else {
V_157 [ V_161 ] = V_6 -> V_138 [ V_162 ] ;
V_159 [ V_161 ] = V_6 -> V_140 [ V_162 ] ;
V_161 -- ;
}
}
V_6 -> V_139 = V_162 - 1 ;
V_155 = V_162 ;
F_46 ( V_6 , V_128 ) ;
for ( V_160 = V_161 + 1 ; V_160 < V_158 ; V_160 ++ ) {
V_6 -> V_138 [ V_6 -> V_139 ] = V_157 [ V_160 ] ;
V_6 -> V_140 [ V_6 -> V_139 ] = V_159 [ V_160 ] ;
F_47 ( V_6 , V_6 -> V_139 ,
V_159 [ V_160 ] , V_157 [ V_160 ] ) ;
if ( ! V_6 -> V_139 )
break;
V_6 -> V_139 = V_6 -> V_139 - 1 ;
}
return 1 ;
}
static int F_49 ( struct V_5 * V_6 , struct V_176 * V_40 )
{
if ( ! F_48 ( V_6 , V_40 -> V_119 , V_40 -> V_177 ) )
return - V_92 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_176 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_178 = 0 ;
switch( V_40 -> V_40 ) {
case V_179 :
V_178 = F_49 ( V_6 , V_40 ) ;
break;
default:
V_178 = - V_92 ;
}
return V_178 ;
}
