struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
int V_5 , V_6 = V_7 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_8 [ V_5 ] . V_9 == V_4 ) {
return V_8 + V_5 ;
}
}
F_2 ( L_1 , ( char * ) & V_4 ) ;
return NULL ;
}
int F_3 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_15 V_16 ;
int V_17 = 0 , V_18 = 0 ;
F_4 ( L_2 , V_3 , V_11 ) ;
if ( V_13 -> V_19 . V_11 == NULL ) {
F_2 ( L_3 ) ;
return - V_20 ;
}
if ( F_5 ( V_11 ) != 0 ) {
F_2 ( L_4 ) ;
return - V_21 ;
}
if ( F_6 ( V_11 ) != 0 ) {
if ( V_13 -> V_22 == V_11 ) {
F_2 ( L_5 ) ;
return 0 ;
}
F_2 ( L_6 ) ;
return - V_21 ;
}
if ( 0 == F_7 ( V_11 , V_23 | V_24 ) ) {
F_2 ( L_7 ) ;
return - V_21 ;
}
V_16 . V_16 . V_25 = V_13 -> V_19 . V_25 ;
V_18 = F_8 ( NULL , V_11 , & V_16 ) ;
if ( 0 != V_18 ) {
F_9 ( V_13 -> V_22 , V_23 | V_24 ) ;
return - V_21 ;
}
V_13 -> V_19 . V_25 = V_16 . V_16 . V_25 ;
F_2 ( L_8 ,
V_13 -> V_19 . V_25 . V_26 . V_27 , V_13 -> V_19 . V_25 . V_26 . V_28 ,
V_13 -> V_19 . V_25 . V_26 . V_29 , V_13 -> V_19 . V_25 . V_26 . V_30 ,
V_13 -> V_31 -> V_32 , V_33 [ V_13 -> V_19 . V_25 . V_34 ] ) ;
if ( 0 != ( V_17 = F_10 ( V_11 ) ) ) {
F_2 ( L_9 , V_17 ) ;
F_9 ( V_13 -> V_22 , V_23 | V_24 ) ;
return V_17 ;
}
V_13 -> V_35 = V_36 ;
V_13 -> V_22 = V_11 ;
return 0 ;
}
int F_11 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
F_4 ( L_2 , V_3 , V_11 ) ;
if ( F_5 ( V_11 ) != 0 ) {
F_2 ( L_4 ) ;
return - V_21 ;
}
if ( ( V_13 -> V_35 & V_36 ) == 0 ) {
F_2 ( L_10 ) ;
return 0 ;
}
if ( V_13 -> V_22 != V_11 ) {
F_2 ( L_11 ) ;
return - V_21 ;
}
V_13 -> V_35 = 0 ;
V_13 -> V_22 = NULL ;
F_12 ( V_11 ) ;
F_9 ( V_11 , V_23 | V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_37 * V_38 )
{
struct V_39 * V_40 = V_3 -> V_40 ;
struct V_41 * V_42 = F_14 ( & V_38 -> V_43 ) ;
struct V_44 * V_45 = V_42 -> V_46 ;
int V_47 = V_42 -> V_48 ;
struct V_1 * V_49 = F_1 ( V_3 , V_38 -> V_16 -> V_9 ) ;
F_4 ( L_12 , V_3 , V_38 , V_47 ) ;
if( 0 != F_15 ( V_49 -> V_50 ) ) {
struct V_51 * V_52 = & V_38 -> V_53 [ 0 ] ;
struct V_51 * V_54 = & V_38 -> V_53 [ 1 ] ;
struct V_51 * V_55 = & V_38 -> V_53 [ 2 ] ;
T_1 * V_56 , * V_57 , * V_58 ;
T_1 V_59 ;
int V_60 = V_38 -> V_16 -> V_27 * V_38 -> V_16 -> V_28 ;
int V_5 , V_61 , V_62 , V_63 , V_64 , V_65 , V_66 ;
switch( V_49 -> V_67 ) {
case 12 : {
V_62 = ( ( V_60 + V_68 ) / V_68 ) - 1 ;
V_63 = ( ( V_60 + ( V_60 / 4 ) + V_68 ) / V_68 ) - 1 ;
V_64 = ( ( V_60 + ( V_60 / 2 ) + V_68 ) / V_68 ) - 1 ;
V_65 = V_60 % V_68 ;
V_66 = ( V_60 + ( V_60 / 4 ) ) % V_68 ;
F_16 ( L_13 ,
V_60 , V_62 , V_63 , V_64 , V_65 , V_66 ) ;
break;
}
case 16 : {
V_62 = ( ( V_60 + V_68 ) / V_68 ) - 1 ;
V_63 = ( ( V_60 + ( V_60 / 2 ) + V_68 ) / V_68 ) - 1 ;
V_64 = ( ( 2 * V_60 + V_68 ) / V_68 ) - 1 ;
V_65 = V_60 % V_68 ;
V_66 = ( V_60 + ( V_60 / 2 ) ) % V_68 ;
F_16 ( L_13 ,
V_60 , V_62 , V_63 , V_64 , V_65 , V_66 ) ;
break;
}
default: {
return - 1 ;
}
}
V_56 = V_52 -> V_69 ;
V_57 = V_54 -> V_69 ;
V_58 = V_55 -> V_69 ;
for ( V_5 = 0 ; V_5 < V_47 ; V_5 ++ , V_45 ++ ) {
for ( V_61 = 0 ; V_61 * 4096 < V_45 -> V_47 ; V_61 ++ , V_56 ++ ) {
* V_56 = F_17 ( F_18 ( V_45 ) - V_45 -> V_70 ) ;
}
}
V_52 -> V_70 = V_42 -> V_46 -> V_70 ;
V_54 -> V_70 = V_52 -> V_70 + V_65 ;
V_55 -> V_70 = V_52 -> V_70 + V_66 ;
V_56 = V_52 -> V_69 ;
for( V_5 = V_62 ; V_5 <= V_63 ; V_5 ++ , V_57 ++ ) {
* V_57 = V_56 [ V_5 ] ;
}
V_59 = * ( V_57 - 1 ) ;
for(; V_5 < 1024 ; V_5 ++ , V_57 ++ ) {
* V_57 = V_59 ;
}
V_56 = V_52 -> V_69 ;
for( V_5 = V_63 ; V_5 <= V_64 ; V_5 ++ , V_58 ++ ) {
* V_58 = V_56 [ V_5 ] ;
}
V_59 = * ( V_58 - 1 ) ;
for(; V_5 < 1024 ; V_5 ++ , V_58 ++ ) {
* V_58 = V_59 ;
}
V_56 = V_52 -> V_69 + V_62 ;
V_59 = V_52 -> V_69 [ V_62 ] ;
for( V_5 = V_62 ; V_5 < 1024 ; V_5 ++ , V_56 ++ ) {
* V_56 = V_59 ;
}
} else {
struct V_51 * V_53 = & V_38 -> V_53 [ 0 ] ;
return F_19 ( V_40 , V_53 , V_45 , V_47 ) ;
}
return 0 ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 = NULL ;
unsigned int V_71 ;
int V_17 = 0 , V_18 = 0 ;
F_4 ( L_2 , V_3 , V_11 ) ;
if ( ( V_13 -> V_35 & V_72 ) != 0 ) {
if ( V_13 -> V_22 == V_11 ) {
F_21 ( L_14 ) ;
return 0 ;
}
F_21 ( L_15 ) ;
return - V_21 ;
}
if ( ( V_13 -> V_35 & V_36 ) != 0 ) {
F_21 ( L_16 ) ;
V_13 -> V_73 = V_13 -> V_22 ;
V_18 = F_11 ( V_13 -> V_22 ) ;
if ( 0 != V_18 ) {
F_2 ( L_17 ) ;
return V_18 ;
}
}
V_16 = F_1 ( V_3 , V_13 -> V_74 . V_9 ) ;
F_22 ( NULL == V_16 ) ;
if ( 0 != ( V_16 -> V_75 & V_76 ) ) {
V_71 = V_23 | V_24 | V_77 ;
} else {
V_71 = V_23 ;
}
V_17 = F_7 ( V_11 , V_71 ) ;
if ( 0 == V_17 ) {
F_21 ( L_18 , V_71 ) ;
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
return - V_21 ;
}
F_23 ( V_3 , V_78 , V_79 ) ;
F_24 ( V_3 , V_79 ) ;
V_13 -> V_22 = V_11 ;
V_13 -> V_35 = V_72 ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 , struct V_80 * V_80 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_81 * V_82 = & V_13 -> V_83 ;
struct V_1 * V_16 = NULL ;
unsigned long V_75 ;
unsigned int V_71 ;
T_2 V_84 = 0 ;
F_4 ( L_2 , V_3 , V_11 ) ;
if ( ( V_13 -> V_35 & V_72 ) != V_72 ) {
F_21 ( L_19 ) ;
return 0 ;
}
if ( V_13 -> V_22 != V_11 ) {
F_21 ( L_20 ) ;
return - V_21 ;
}
V_16 = F_1 ( V_3 , V_13 -> V_74 . V_9 ) ;
F_22 ( NULL == V_16 ) ;
if ( 0 != ( V_16 -> V_75 & V_76 ) ) {
V_71 = V_23 | V_24 | V_77 ;
V_84 = V_85 | V_86 | V_87 ;
} else {
V_71 = V_23 ;
V_84 = V_85 ;
}
F_26 ( & V_3 -> V_88 , V_75 ) ;
F_23 ( V_3 , V_89 , V_90 ) ;
F_27 ( V_3 , V_79 ) ;
F_23 ( V_3 , V_89 , V_84 ) ;
if ( V_82 -> V_91 )
F_28 ( V_3 , V_82 , V_92 ) ;
F_29 ( & V_3 -> V_88 , V_75 ) ;
V_13 -> V_22 = NULL ;
V_13 -> V_35 = 0 ;
F_9 ( V_11 , V_71 ) ;
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
return 0 ;
}
static int F_30 ( struct V_80 * V_80 , void * V_11 , struct V_93 * V_94 )
{
struct V_95 * V_96 = F_31 ( V_80 ) ;
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
strcpy ( ( char * ) V_94 -> V_97 , L_21 ) ;
F_32 ( ( char * ) V_94 -> V_98 , V_3 -> V_99 -> V_32 , sizeof( V_94 -> V_98 ) ) ;
sprintf ( ( char * ) V_94 -> V_100 , L_22 , F_33 ( V_3 -> V_40 ) ) ;
V_94 -> V_101 =
V_102 |
V_103 |
V_104 |
V_105 ;
V_94 -> V_101 |= V_3 -> V_106 -> V_107 ;
V_94 -> V_107 = V_94 -> V_101 | V_108 ;
if ( V_96 -> V_109 == V_110 )
V_94 -> V_101 &=
~ ( V_111 | V_112 ) ;
else
V_94 -> V_101 &=
~ ( V_102 | V_103 | V_113 ) ;
return 0 ;
}
static int F_34 ( struct V_80 * V_80 , void * V_11 , struct V_114 * V_115 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
* V_115 = V_13 -> V_116 ;
V_115 -> V_117 = V_118 ;
V_115 -> V_75 = V_119 ;
return 0 ;
}
static int F_35 ( struct V_80 * V_80 , void * V_11 , const struct V_114 * V_115 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 ;
F_4 ( L_23 ) ;
if ( ! F_36 ( V_120 ) && ! F_36 ( V_121 ) )
return - V_122 ;
V_16 = F_1 ( V_3 , V_115 -> V_16 . V_9 ) ;
if ( NULL == V_16 )
return - V_123 ;
if ( V_16 -> V_75 & V_76 )
F_21 ( L_24 ,
( char * ) & V_16 -> V_9 ) ;
if ( F_6 ( V_11 ) != 0 ) {
if ( V_13 -> V_22 != V_11 ) {
F_2 ( L_25 ) ;
return - V_21 ;
}
}
V_13 -> V_116 = * V_115 ;
V_13 -> V_31 = V_16 ;
if ( V_13 -> V_116 . V_16 . V_124 < V_13 -> V_116 . V_16 . V_27 ) {
V_13 -> V_116 . V_16 . V_124 = V_13 -> V_116 . V_16 . V_27 * V_16 -> V_67 / 8 ;
F_2 ( L_26 , V_13 -> V_116 . V_16 . V_124 ) ;
}
return 0 ;
}
static int F_37 ( struct V_80 * V_80 , void * V_11 , struct V_125 * V_126 )
{
if ( V_126 -> V_127 >= V_7 )
return - V_123 ;
F_32 ( ( char * ) V_126 -> V_128 , V_8 [ V_126 -> V_127 ] . V_32 ,
sizeof( V_126 -> V_128 ) ) ;
V_126 -> V_9 = V_8 [ V_126 -> V_127 ] . V_9 ;
return 0 ;
}
int F_38 ( struct V_129 * V_130 )
{
struct V_2 * V_3 = F_39 ( V_130 -> V_131 ,
struct V_2 , V_132 ) ;
struct V_12 * V_13 = V_3 -> V_14 ;
T_2 V_133 ;
switch ( V_130 -> V_134 ) {
case V_135 :
V_133 = F_40 ( V_3 , V_136 ) ;
V_133 &= 0x00ffffff ;
V_133 |= ( V_130 -> V_133 << 24 ) ;
F_23 ( V_3 , V_136 , V_133 ) ;
F_23 ( V_3 , V_78 , V_85 | V_137 ) ;
break;
case V_138 :
V_133 = F_40 ( V_3 , V_136 ) ;
V_133 &= 0xff00ffff ;
V_133 |= ( V_130 -> V_133 << 16 ) ;
F_23 ( V_3 , V_136 , V_133 ) ;
F_23 ( V_3 , V_78 , V_85 | V_137 ) ;
break;
case V_139 :
V_133 = F_40 ( V_3 , V_136 ) ;
V_133 &= 0xffffff00 ;
V_133 |= ( V_130 -> V_133 << 0 ) ;
F_23 ( V_3 , V_136 , V_133 ) ;
F_23 ( V_3 , V_78 , V_85 | V_137 ) ;
break;
case V_140 :
if ( ( V_13 -> V_35 & V_72 ) )
return - V_21 ;
V_13 -> V_141 = V_130 -> V_133 ;
break;
case V_142 :
if ( ( V_13 -> V_35 & V_72 ) )
return - V_21 ;
V_13 -> V_143 = V_130 -> V_133 ;
break;
default:
return - V_123 ;
}
if ( ( V_13 -> V_35 & V_36 ) != 0 ) {
struct V_10 * V_11 = V_13 -> V_22 ;
F_11 ( V_11 ) ;
F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_41 ( struct V_80 * V_80 , void * V_11 ,
struct V_144 * V_145 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
if ( V_145 -> type != V_146 )
return - V_123 ;
V_145 -> V_145 . V_147 . V_148 = 1 ;
F_42 ( V_13 -> V_149 -> V_134 ,
& V_145 -> V_145 . V_147 . V_150 ) ;
return 0 ;
}
static int F_43 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_126 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_126 -> V_16 . V_151 = V_13 -> V_74 ;
return 0 ;
}
static int F_44 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_126 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_126 -> V_16 . V_25 = V_13 -> V_19 . V_25 ;
return 0 ;
}
static int F_45 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_126 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_126 -> V_16 . V_152 = V_13 -> V_153 ;
return 0 ;
}
static int F_46 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_126 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 ;
enum V_154 V_34 ;
int V_155 , V_156 ;
int V_157 ;
F_4 ( L_27 , V_3 , V_11 ) ;
V_16 = F_1 ( V_3 , V_126 -> V_16 . V_151 . V_9 ) ;
if ( NULL == V_16 )
return - V_123 ;
V_34 = V_126 -> V_16 . V_151 . V_34 ;
V_155 = V_13 -> V_149 -> V_158 ;
V_156 = V_13 -> V_149 -> V_159 ;
if ( V_160 == V_34 ) {
V_34 = ( V_126 -> V_16 . V_151 . V_28 > V_156 / 2 )
? V_161
: V_162 ;
}
switch ( V_34 ) {
case V_163 :
V_13 -> V_164 = V_165 ;
V_156 = V_156 / 2 ;
break;
case V_165 :
case V_162 :
V_13 -> V_164 = V_161 ;
V_156 = V_156 / 2 ;
break;
case V_161 :
V_13 -> V_164 = V_161 ;
break;
default:
F_2 ( L_28 , V_34 ) ;
return - V_123 ;
}
V_126 -> V_16 . V_151 . V_34 = V_34 ;
V_126 -> V_16 . V_151 . V_166 = V_167 ;
if ( V_126 -> V_16 . V_151 . V_27 > V_155 )
V_126 -> V_16 . V_151 . V_27 = V_155 ;
if ( V_126 -> V_16 . V_151 . V_28 > V_156 )
V_126 -> V_16 . V_151 . V_28 = V_156 ;
V_157 = ( V_126 -> V_16 . V_151 . V_27 * V_16 -> V_67 ) / 8 ;
if ( V_126 -> V_16 . V_151 . V_124 < V_157 )
V_126 -> V_16 . V_151 . V_124 = V_157 ;
if ( V_126 -> V_16 . V_151 . V_124 > ( 2 * V_68 * V_16 -> V_67 ) / 8 )
V_126 -> V_16 . V_151 . V_124 = V_157 ;
V_126 -> V_16 . V_151 . V_168 = V_126 -> V_16 . V_151 . V_124 * V_126 -> V_16 . V_151 . V_28 ;
F_2 ( L_29 ,
V_126 -> V_16 . V_151 . V_27 , V_126 -> V_16 . V_151 . V_28 ,
V_126 -> V_16 . V_151 . V_124 , V_126 -> V_16 . V_151 . V_168 ) ;
return 0 ;
}
static int F_8 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_126 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_169 * V_25 = & V_126 -> V_16 . V_25 ;
enum V_154 V_34 ;
int V_155 , V_156 ;
F_4 ( L_30 , V_3 ) ;
if ( NULL == V_13 -> V_116 . V_170 ) {
F_2 ( L_31 ) ;
return - V_123 ;
}
if ( NULL == V_13 -> V_31 ) {
F_2 ( L_32 ) ;
return - V_123 ;
}
if ( V_25 -> V_26 . V_27 < 48 || V_25 -> V_26 . V_28 < 32 ) {
F_2 ( L_33 ,
V_25 -> V_26 . V_27 , V_25 -> V_26 . V_28 ) ;
return - V_123 ;
}
if ( V_25 -> V_171 > 16 ) {
F_2 ( L_34 ) ;
return - V_123 ;
}
V_34 = V_25 -> V_34 ;
V_155 = V_13 -> V_149 -> V_158 ;
V_156 = V_13 -> V_149 -> V_159 ;
if ( V_160 == V_34 ) {
V_34 = ( V_25 -> V_26 . V_28 > V_156 / 2 )
? V_161
: V_165 ;
}
switch ( V_34 ) {
case V_165 :
case V_162 :
case V_163 :
V_156 = V_156 / 2 ;
break;
case V_161 :
break;
default:
F_2 ( L_28 , V_34 ) ;
return - V_123 ;
}
V_25 -> V_34 = V_34 ;
if ( V_25 -> V_26 . V_27 > V_155 )
V_25 -> V_26 . V_27 = V_155 ;
if ( V_25 -> V_26 . V_28 > V_156 )
V_25 -> V_26 . V_28 = V_156 ;
return 0 ;
}
static int F_47 ( struct V_80 * V_80 , void * V_172 , struct V_15 * V_126 )
{
struct V_10 * V_11 = V_172 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_4 ( L_27 , V_3 , V_11 ) ;
if ( F_5 ( V_11 ) != 0 ) {
F_4 ( L_4 ) ;
return - V_21 ;
}
V_18 = F_46 ( V_80 , V_11 , V_126 ) ;
if ( 0 != V_18 )
return V_18 ;
V_13 -> V_74 = V_126 -> V_16 . V_151 ;
F_4 ( L_35 ,
( char * ) & V_13 -> V_74 . V_9 ) ;
return 0 ;
}
static int F_48 ( struct V_80 * V_80 , void * V_172 , struct V_15 * V_126 )
{
struct V_10 * V_11 = V_172 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_4 ( L_36 , V_3 , V_11 ) ;
V_18 = F_8 ( V_80 , V_11 , V_126 ) ;
if ( 0 != V_18 )
return V_18 ;
V_13 -> V_19 . V_25 = V_126 -> V_16 . V_25 ;
V_13 -> V_19 . V_173 = V_126 -> V_16 . V_25 . V_171 ;
if ( V_13 -> V_19 . V_173 > 16 )
V_13 -> V_19 . V_173 = 16 ;
if ( F_49 ( V_13 -> V_19 . V_174 , V_126 -> V_16 . V_25 . V_174 ,
sizeof( struct V_175 ) * V_13 -> V_19 . V_173 ) ) {
return - V_176 ;
}
V_13 -> V_19 . V_11 = V_11 ;
if ( F_6 ( V_11 ) != 0 ) {
F_11 ( V_11 ) ;
F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_50 ( struct V_80 * V_80 , void * V_11 , T_3 * V_177 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
* V_177 = V_13 -> V_149 -> V_134 ;
return 0 ;
}
static int F_51 ( struct V_80 * V_80 , void * V_11 , T_3 V_134 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_178 = 0 ;
int V_18 , V_5 ;
F_4 ( L_37 ) ;
if ( ( V_13 -> V_35 & V_72 ) == V_72 ) {
F_2 ( L_38 ) ;
return - V_21 ;
}
if ( ( V_13 -> V_35 & V_36 ) != 0 ) {
V_13 -> V_73 = V_13 -> V_22 ;
V_18 = F_11 ( V_13 -> V_22 ) ;
if ( 0 != V_18 ) {
F_2 ( L_17 ) ;
return V_18 ;
}
}
for ( V_5 = 0 ; V_5 < V_3 -> V_106 -> V_179 ; V_5 ++ )
if ( V_134 & V_3 -> V_106 -> V_180 [ V_5 ] . V_134 )
break;
if ( V_5 != V_3 -> V_106 -> V_179 ) {
V_13 -> V_149 = & V_3 -> V_106 -> V_180 [ V_5 ] ;
if ( NULL != V_3 -> V_106 -> V_181 )
V_3 -> V_106 -> V_181 ( V_3 , V_13 -> V_149 ) ;
V_178 = 1 ;
}
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
if ( ! V_178 ) {
F_4 ( L_39 ) ;
return - V_123 ;
}
F_4 ( L_40 , V_13 -> V_149 -> V_32 ) ;
return 0 ;
}
static int F_52 ( struct V_80 * V_80 , void * V_11 , unsigned int V_182 )
{
int V_18 ;
F_2 ( L_41 , V_182 ) ;
if ( V_182 )
V_18 = F_3 ( V_11 ) ;
else
V_18 = F_11 ( V_11 ) ;
return V_18 ;
}
static int F_53 ( struct V_80 * V_80 , void * V_172 , struct V_183 * V_184 )
{
struct V_10 * V_11 = V_172 ;
if ( V_184 -> type == V_146 )
return F_54 ( & V_11 -> V_185 , V_184 ) ;
if ( V_184 -> type == V_186 )
return F_54 ( & V_11 -> V_187 , V_184 ) ;
return - V_123 ;
}
static int F_55 ( struct V_80 * V_80 , void * V_172 , struct V_188 * V_38 )
{
struct V_10 * V_11 = V_172 ;
if ( V_38 -> type == V_146 )
return F_56 ( & V_11 -> V_185 , V_38 ) ;
if ( V_38 -> type == V_186 )
return F_56 ( & V_11 -> V_187 , V_38 ) ;
return - V_123 ;
}
static int F_57 ( struct V_80 * V_80 , void * V_172 , struct V_188 * V_38 )
{
struct V_10 * V_11 = V_172 ;
if ( V_38 -> type == V_146 )
return F_58 ( & V_11 -> V_185 , V_38 ) ;
if ( V_38 -> type == V_186 )
return F_58 ( & V_11 -> V_187 , V_38 ) ;
return - V_123 ;
}
static int F_59 ( struct V_80 * V_80 , void * V_172 , struct V_188 * V_38 )
{
struct V_10 * V_11 = V_172 ;
if ( V_38 -> type == V_146 )
return F_60 ( & V_11 -> V_185 , V_38 , V_80 -> V_189 & V_190 ) ;
if ( V_38 -> type == V_186 )
return F_60 ( & V_11 -> V_187 , V_38 , V_80 -> V_189 & V_190 ) ;
return - V_123 ;
}
static int F_61 ( struct V_80 * V_80 , void * V_172 , enum V_191 type )
{
struct V_10 * V_11 = V_172 ;
int V_18 ;
F_2 ( L_42 , type ) ;
V_18 = F_20 ( V_11 ) ;
if ( V_18 )
return V_18 ;
if ( type == V_146 )
return F_62 ( & V_11 -> V_185 ) ;
if ( type == V_186 )
return F_62 ( & V_11 -> V_187 ) ;
return - V_123 ;
}
static int F_63 ( struct V_80 * V_80 , void * V_172 , enum V_191 type )
{
struct V_10 * V_11 = V_172 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_2 ( L_43 , type ) ;
if ( ( V_13 -> V_35 & V_72 ) != V_72 ) {
F_21 ( L_19 ) ;
return 0 ;
}
if ( V_13 -> V_22 != V_11 ) {
F_21 ( L_20 ) ;
return - V_21 ;
}
V_18 = - V_123 ;
if ( type == V_146 )
V_18 = F_64 ( & V_11 -> V_185 ) ;
else if ( type == V_186 )
V_18 = F_64 ( & V_11 -> V_187 ) ;
if ( 0 != V_18 ) {
F_2 ( L_44 ) ;
F_25 ( V_11 , V_80 ) ;
} else {
V_18 = F_25 ( V_11 , V_80 ) ;
}
return V_18 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_37 * V_192 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
V_38 -> V_43 . V_193 = V_194 ;
F_66 ( V_3 , V_38 , V_192 ) ;
F_67 ( & V_13 -> V_83 . V_195 , V_196 + V_197 ) ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 , struct V_37 * V_38 )
{
F_69 ( V_3 -> V_40 , & V_38 -> V_53 [ 0 ] ) ;
F_69 ( V_3 -> V_40 , & V_38 -> V_53 [ 1 ] ) ;
F_69 ( V_3 -> V_40 , & V_38 -> V_53 [ 2 ] ) ;
}
static int F_70 ( struct V_198 * V_82 ,
struct V_199 * V_43 , enum V_154 V_34 )
{
struct V_80 * V_80 = V_82 -> V_200 ;
struct V_10 * V_11 = V_80 -> V_201 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_37 * V_38 = (struct V_37 * ) V_43 ;
int V_60 , V_18 = 0 ;
F_16 ( L_45 , V_43 ) ;
if ( V_13 -> V_74 . V_27 < 48 ||
V_13 -> V_74 . V_28 < 32 ||
V_13 -> V_74 . V_27 > V_13 -> V_149 -> V_158 ||
V_13 -> V_74 . V_28 > V_13 -> V_149 -> V_159 ) {
F_2 ( L_46 ,
V_13 -> V_74 . V_27 , V_13 -> V_74 . V_28 ) ;
return - V_123 ;
}
V_60 = V_13 -> V_74 . V_168 ;
if ( 0 != V_38 -> V_43 . V_202 && V_38 -> V_43 . V_203 < V_60 ) {
F_2 ( L_47 ) ;
return - V_123 ;
}
F_16 ( L_48 ,
V_13 -> V_74 . V_27 , V_13 -> V_74 . V_28 ,
V_60 , V_33 [ V_13 -> V_74 . V_34 ] ) ;
if ( V_38 -> V_43 . V_27 != V_13 -> V_74 . V_27 ||
V_38 -> V_43 . V_124 != V_13 -> V_74 . V_124 ||
V_38 -> V_43 . V_28 != V_13 -> V_74 . V_28 ||
V_38 -> V_43 . V_60 != V_60 ||
V_38 -> V_43 . V_34 != V_34 ||
V_38 -> V_43 . V_34 != V_13 -> V_74 . V_34 ||
V_38 -> V_16 != & V_13 -> V_74 ) {
F_71 ( V_3 , V_82 , V_38 ) ;
}
if ( V_204 == V_38 -> V_43 . V_193 ) {
struct V_1 * V_49 ;
V_38 -> V_43 . V_124 = V_13 -> V_74 . V_124 ;
V_38 -> V_43 . V_27 = V_13 -> V_74 . V_27 ;
V_38 -> V_43 . V_28 = V_13 -> V_74 . V_28 ;
V_38 -> V_43 . V_60 = V_60 ;
V_38 -> V_43 . V_34 = V_34 ;
V_38 -> V_16 = & V_13 -> V_74 ;
V_38 -> V_43 . V_34 = V_13 -> V_74 . V_34 ;
V_49 = F_1 ( V_3 , V_38 -> V_16 -> V_9 ) ;
F_68 ( V_3 , V_38 ) ;
if( 0 != F_15 ( V_49 -> V_50 ) ) {
F_72 ( V_3 -> V_40 , & V_38 -> V_53 [ 0 ] ) ;
F_72 ( V_3 -> V_40 , & V_38 -> V_53 [ 1 ] ) ;
F_72 ( V_3 -> V_40 , & V_38 -> V_53 [ 2 ] ) ;
} else {
F_72 ( V_3 -> V_40 , & V_38 -> V_53 [ 0 ] ) ;
}
V_18 = F_73 ( V_82 , & V_38 -> V_43 , & V_13 -> V_116 ) ;
if ( V_18 )
goto V_205;
V_18 = F_13 ( V_3 , V_38 ) ;
if ( V_18 )
goto V_205;
}
V_38 -> V_43 . V_193 = V_206 ;
V_38 -> V_207 = F_65 ;
return 0 ;
V_205:
F_2 ( L_49 ) ;
F_71 ( V_3 , V_82 , V_38 ) ;
return V_18 ;
}
static int F_74 ( struct V_198 * V_82 , unsigned int * V_208 , unsigned int * V_60 )
{
struct V_80 * V_80 = V_82 -> V_200 ;
struct V_10 * V_11 = V_80 -> V_201 ;
struct V_12 * V_13 = V_11 -> V_3 -> V_14 ;
if ( 0 == * V_208 || * V_208 > V_209 )
* V_208 = V_209 ;
* V_60 = V_13 -> V_74 . V_168 ;
if( ( * V_208 * * V_60 ) > ( V_210 * 1048576 ) ) {
* V_208 = ( V_210 * 1048576 ) / * V_60 ;
}
F_16 ( L_50 , * V_208 , * V_60 ) ;
return 0 ;
}
static void F_75 ( struct V_198 * V_82 , struct V_199 * V_43 )
{
struct V_80 * V_80 = V_82 -> V_200 ;
struct V_10 * V_11 = V_80 -> V_201 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_37 * V_38 = (struct V_37 * ) V_43 ;
F_16 ( L_45 , V_43 ) ;
F_76 ( V_11 -> V_3 , & V_13 -> V_83 , V_38 ) ;
}
static void F_77 ( struct V_198 * V_82 , struct V_199 * V_43 )
{
struct V_80 * V_80 = V_82 -> V_200 ;
struct V_10 * V_11 = V_80 -> V_201 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_37 * V_38 = (struct V_37 * ) V_43 ;
F_16 ( L_45 , V_43 ) ;
F_71 ( V_3 , V_82 , V_38 ) ;
F_68 ( V_3 , V_38 ) ;
}
static void F_78 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
F_79 ( & V_13 -> V_83 . V_211 ) ;
F_80 ( & V_13 -> V_83 . V_195 , V_212 ,
( unsigned long ) ( & V_13 -> V_83 ) ) ;
V_13 -> V_83 . V_3 = V_3 ;
V_13 -> V_149 = & V_3 -> V_106 -> V_180 [ 0 ] ;
V_13 -> V_213 = V_214 ;
V_13 -> V_215 = V_216 ;
}
static int F_81 ( struct V_2 * V_3 , struct V_80 * V_80 )
{
struct V_10 * V_11 = V_80 -> V_201 ;
F_82 ( & V_11 -> V_185 , & V_217 ,
& V_3 -> V_40 -> V_3 , & V_3 -> V_88 ,
V_146 ,
V_161 ,
sizeof( struct V_37 ) ,
V_80 , & V_3 -> V_218 ) ;
return 0 ;
}
static void F_83 ( struct V_2 * V_3 , struct V_80 * V_80 )
{
struct V_10 * V_11 = V_80 -> V_201 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_198 * V_82 = & V_11 -> V_185 ;
if ( F_5 ( V_11 ) != 0 )
F_25 ( V_11 , V_80 ) ;
else if ( F_6 ( V_11 ) != 0 )
F_11 ( V_11 ) ;
F_84 ( V_82 ) ;
}
static void F_85 ( struct V_2 * V_3 , unsigned long V_219 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_81 * V_82 = & V_13 -> V_83 ;
F_86 ( & V_3 -> V_88 ) ;
F_16 ( L_51 ) ;
if( NULL != V_82 -> V_91 ) {
F_28 ( V_3 , V_82 , V_92 ) ;
}
F_87 ( V_3 , V_82 , 0 ) ;
F_88 ( & V_3 -> V_88 ) ;
}
static T_4 F_89 ( struct V_80 * V_80 , char T_5 * V_220 , T_6 V_208 , T_7 * V_221 )
{
struct V_10 * V_11 = V_80 -> V_201 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
T_4 V_17 = 0 ;
F_4 ( L_51 ) ;
if ( ( V_13 -> V_35 & V_72 ) != 0 ) {
if ( V_13 -> V_22 == V_11 ) {
F_21 ( L_14 ) ;
return - V_21 ;
}
F_21 ( L_15 ) ;
return - V_21 ;
}
V_17 = F_20 ( V_11 ) ;
if( 0 != V_17 ) {
goto V_222;
}
V_17 = F_90 ( & V_11 -> V_185 , V_220 , V_208 , V_221 ,
V_80 -> V_189 & V_190 ) ;
if ( V_17 != 0 ) {
F_25 ( V_11 , V_80 ) ;
} else {
V_17 = F_25 ( V_11 , V_80 ) ;
}
V_222:
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
return V_17 ;
}
