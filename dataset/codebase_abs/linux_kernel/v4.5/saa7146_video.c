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
struct V_1 * V_16 = NULL ;
unsigned long V_75 ;
unsigned int V_71 ;
T_2 V_81 = 0 ;
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
V_81 = V_82 | V_83 | V_84 ;
} else {
V_71 = V_23 ;
V_81 = V_82 ;
}
F_26 ( & V_3 -> V_85 , V_75 ) ;
F_23 ( V_3 , V_86 , V_87 ) ;
F_27 ( V_3 , V_79 ) ;
F_23 ( V_3 , V_86 , V_81 ) ;
F_28 ( & V_3 -> V_85 , V_75 ) ;
V_13 -> V_22 = NULL ;
V_13 -> V_35 = 0 ;
F_9 ( V_11 , V_71 ) ;
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
return 0 ;
}
static int F_29 ( struct V_80 * V_80 , void * V_11 , struct V_88 * V_89 )
{
struct V_90 * V_91 = F_30 ( V_80 ) ;
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
strcpy ( ( char * ) V_89 -> V_92 , L_21 ) ;
F_31 ( ( char * ) V_89 -> V_93 , V_3 -> V_94 -> V_32 , sizeof( V_89 -> V_93 ) ) ;
sprintf ( ( char * ) V_89 -> V_95 , L_22 , F_32 ( V_3 -> V_40 ) ) ;
V_89 -> V_96 =
V_97 |
V_98 |
V_99 |
V_100 ;
V_89 -> V_96 |= V_3 -> V_101 -> V_102 ;
V_89 -> V_102 = V_89 -> V_96 | V_103 ;
if ( V_91 -> V_104 == V_105 )
V_89 -> V_96 &=
~ ( V_106 | V_107 ) ;
else
V_89 -> V_96 &=
~ ( V_97 | V_98 | V_108 ) ;
return 0 ;
}
static int F_33 ( struct V_80 * V_80 , void * V_11 , struct V_109 * V_110 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
* V_110 = V_13 -> V_111 ;
V_110 -> V_112 = V_113 ;
V_110 -> V_75 = V_114 ;
return 0 ;
}
static int F_34 ( struct V_80 * V_80 , void * V_11 , const struct V_109 * V_110 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 ;
F_4 ( L_23 ) ;
if ( ! F_35 ( V_115 ) && ! F_35 ( V_116 ) )
return - V_117 ;
V_16 = F_1 ( V_3 , V_110 -> V_16 . V_9 ) ;
if ( NULL == V_16 )
return - V_118 ;
if ( V_16 -> V_75 & V_76 )
F_21 ( L_24 ,
( char * ) & V_16 -> V_9 ) ;
if ( F_6 ( V_11 ) != 0 ) {
if ( V_13 -> V_22 != V_11 ) {
F_2 ( L_25 ) ;
return - V_21 ;
}
}
V_13 -> V_111 = * V_110 ;
V_13 -> V_31 = V_16 ;
if ( V_13 -> V_111 . V_16 . V_119 < V_13 -> V_111 . V_16 . V_27 ) {
V_13 -> V_111 . V_16 . V_119 = V_13 -> V_111 . V_16 . V_27 * V_16 -> V_67 / 8 ;
F_2 ( L_26 , V_13 -> V_111 . V_16 . V_119 ) ;
}
return 0 ;
}
static int F_36 ( struct V_80 * V_80 , void * V_11 , struct V_120 * V_121 )
{
if ( V_121 -> V_122 >= V_7 )
return - V_118 ;
F_31 ( ( char * ) V_121 -> V_123 , V_8 [ V_121 -> V_122 ] . V_32 ,
sizeof( V_121 -> V_123 ) ) ;
V_121 -> V_9 = V_8 [ V_121 -> V_122 ] . V_9 ;
return 0 ;
}
int F_37 ( struct V_124 * V_125 )
{
struct V_2 * V_3 = F_38 ( V_125 -> V_126 ,
struct V_2 , V_127 ) ;
struct V_12 * V_13 = V_3 -> V_14 ;
T_2 V_128 ;
switch ( V_125 -> V_129 ) {
case V_130 :
V_128 = F_39 ( V_3 , V_131 ) ;
V_128 &= 0x00ffffff ;
V_128 |= ( V_125 -> V_128 << 24 ) ;
F_23 ( V_3 , V_131 , V_128 ) ;
F_23 ( V_3 , V_78 , V_82 | V_132 ) ;
break;
case V_133 :
V_128 = F_39 ( V_3 , V_131 ) ;
V_128 &= 0xff00ffff ;
V_128 |= ( V_125 -> V_128 << 16 ) ;
F_23 ( V_3 , V_131 , V_128 ) ;
F_23 ( V_3 , V_78 , V_82 | V_132 ) ;
break;
case V_134 :
V_128 = F_39 ( V_3 , V_131 ) ;
V_128 &= 0xffffff00 ;
V_128 |= ( V_125 -> V_128 << 0 ) ;
F_23 ( V_3 , V_131 , V_128 ) ;
F_23 ( V_3 , V_78 , V_82 | V_132 ) ;
break;
case V_135 :
if ( ( V_13 -> V_35 & V_72 ) )
return - V_21 ;
V_13 -> V_136 = V_125 -> V_128 ;
break;
case V_137 :
if ( ( V_13 -> V_35 & V_72 ) )
return - V_21 ;
V_13 -> V_138 = V_125 -> V_128 ;
break;
default:
return - V_118 ;
}
if ( ( V_13 -> V_35 & V_36 ) != 0 ) {
struct V_10 * V_11 = V_13 -> V_22 ;
F_11 ( V_11 ) ;
F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_40 ( struct V_80 * V_80 , void * V_11 ,
struct V_139 * V_140 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
if ( V_140 -> type != V_141 )
return - V_118 ;
V_140 -> V_140 . V_142 . V_143 = 1 ;
F_41 ( V_13 -> V_144 -> V_129 ,
& V_140 -> V_140 . V_142 . V_145 ) ;
return 0 ;
}
static int F_42 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_121 -> V_16 . V_146 = V_13 -> V_74 ;
return 0 ;
}
static int F_43 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_121 -> V_16 . V_25 = V_13 -> V_19 . V_25 ;
return 0 ;
}
static int F_44 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_121 -> V_16 . V_147 = V_13 -> V_148 ;
return 0 ;
}
static int F_45 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 ;
enum V_149 V_34 ;
int V_150 , V_151 ;
int V_152 ;
F_4 ( L_27 , V_3 , V_11 ) ;
V_16 = F_1 ( V_3 , V_121 -> V_16 . V_146 . V_9 ) ;
if ( NULL == V_16 )
return - V_118 ;
V_34 = V_121 -> V_16 . V_146 . V_34 ;
V_150 = V_13 -> V_144 -> V_153 ;
V_151 = V_13 -> V_144 -> V_154 ;
if ( V_155 == V_34 ) {
V_34 = ( V_121 -> V_16 . V_146 . V_28 > V_151 / 2 )
? V_156
: V_157 ;
}
switch ( V_34 ) {
case V_158 :
V_13 -> V_159 = V_160 ;
V_151 = V_151 / 2 ;
break;
case V_160 :
case V_157 :
V_13 -> V_159 = V_156 ;
V_151 = V_151 / 2 ;
break;
case V_156 :
V_13 -> V_159 = V_156 ;
break;
default:
F_2 ( L_28 , V_34 ) ;
return - V_118 ;
}
V_121 -> V_16 . V_146 . V_34 = V_34 ;
V_121 -> V_16 . V_146 . V_161 = V_162 ;
if ( V_121 -> V_16 . V_146 . V_27 > V_150 )
V_121 -> V_16 . V_146 . V_27 = V_150 ;
if ( V_121 -> V_16 . V_146 . V_28 > V_151 )
V_121 -> V_16 . V_146 . V_28 = V_151 ;
V_152 = ( V_121 -> V_16 . V_146 . V_27 * V_16 -> V_67 ) / 8 ;
if ( V_121 -> V_16 . V_146 . V_119 < V_152 )
V_121 -> V_16 . V_146 . V_119 = V_152 ;
if ( V_121 -> V_16 . V_146 . V_119 > ( 2 * V_68 * V_16 -> V_67 ) / 8 )
V_121 -> V_16 . V_146 . V_119 = V_152 ;
V_121 -> V_16 . V_146 . V_163 = V_121 -> V_16 . V_146 . V_119 * V_121 -> V_16 . V_146 . V_28 ;
F_2 ( L_29 ,
V_121 -> V_16 . V_146 . V_27 , V_121 -> V_16 . V_146 . V_28 ,
V_121 -> V_16 . V_146 . V_119 , V_121 -> V_16 . V_146 . V_163 ) ;
return 0 ;
}
static int F_8 ( struct V_80 * V_80 , void * V_11 , struct V_15 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_164 * V_25 = & V_121 -> V_16 . V_25 ;
enum V_149 V_34 ;
int V_150 , V_151 ;
F_4 ( L_30 , V_3 ) ;
if ( NULL == V_13 -> V_111 . V_165 ) {
F_2 ( L_31 ) ;
return - V_118 ;
}
if ( NULL == V_13 -> V_31 ) {
F_2 ( L_32 ) ;
return - V_118 ;
}
if ( V_25 -> V_26 . V_27 < 48 || V_25 -> V_26 . V_28 < 32 ) {
F_2 ( L_33 ,
V_25 -> V_26 . V_27 , V_25 -> V_26 . V_28 ) ;
return - V_118 ;
}
if ( V_25 -> V_166 > 16 ) {
F_2 ( L_34 ) ;
return - V_118 ;
}
V_34 = V_25 -> V_34 ;
V_150 = V_13 -> V_144 -> V_153 ;
V_151 = V_13 -> V_144 -> V_154 ;
if ( V_155 == V_34 ) {
V_34 = ( V_25 -> V_26 . V_28 > V_151 / 2 )
? V_156
: V_160 ;
}
switch ( V_34 ) {
case V_160 :
case V_157 :
case V_158 :
V_151 = V_151 / 2 ;
break;
case V_156 :
break;
default:
F_2 ( L_28 , V_34 ) ;
return - V_118 ;
}
V_25 -> V_34 = V_34 ;
if ( V_25 -> V_26 . V_27 > V_150 )
V_25 -> V_26 . V_27 = V_150 ;
if ( V_25 -> V_26 . V_28 > V_151 )
V_25 -> V_26 . V_28 = V_151 ;
return 0 ;
}
static int F_46 ( struct V_80 * V_80 , void * V_167 , struct V_15 * V_121 )
{
struct V_10 * V_11 = V_167 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_4 ( L_27 , V_3 , V_11 ) ;
if ( F_5 ( V_11 ) != 0 ) {
F_4 ( L_4 ) ;
return - V_21 ;
}
V_18 = F_45 ( V_80 , V_11 , V_121 ) ;
if ( 0 != V_18 )
return V_18 ;
V_13 -> V_74 = V_121 -> V_16 . V_146 ;
F_4 ( L_35 ,
( char * ) & V_13 -> V_74 . V_9 ) ;
return 0 ;
}
static int F_47 ( struct V_80 * V_80 , void * V_167 , struct V_15 * V_121 )
{
struct V_10 * V_11 = V_167 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_4 ( L_36 , V_3 , V_11 ) ;
V_18 = F_8 ( V_80 , V_11 , V_121 ) ;
if ( 0 != V_18 )
return V_18 ;
V_13 -> V_19 . V_25 = V_121 -> V_16 . V_25 ;
V_13 -> V_19 . V_168 = V_121 -> V_16 . V_25 . V_166 ;
if ( V_13 -> V_19 . V_168 > 16 )
V_13 -> V_19 . V_168 = 16 ;
if ( F_48 ( V_13 -> V_19 . V_169 , V_121 -> V_16 . V_25 . V_169 ,
sizeof( struct V_170 ) * V_13 -> V_19 . V_168 ) ) {
return - V_171 ;
}
V_13 -> V_19 . V_11 = V_11 ;
if ( F_6 ( V_11 ) != 0 ) {
F_11 ( V_11 ) ;
F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_49 ( struct V_80 * V_80 , void * V_11 , T_3 * V_172 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
* V_172 = V_13 -> V_144 -> V_129 ;
return 0 ;
}
static int F_50 ( struct V_80 * V_80 , void * V_11 , T_3 V_129 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_173 = 0 ;
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
for ( V_5 = 0 ; V_5 < V_3 -> V_101 -> V_174 ; V_5 ++ )
if ( V_129 & V_3 -> V_101 -> V_175 [ V_5 ] . V_129 )
break;
if ( V_5 != V_3 -> V_101 -> V_174 ) {
V_13 -> V_144 = & V_3 -> V_101 -> V_175 [ V_5 ] ;
if ( NULL != V_3 -> V_101 -> V_176 )
V_3 -> V_101 -> V_176 ( V_3 , V_13 -> V_144 ) ;
V_173 = 1 ;
}
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
if ( ! V_173 ) {
F_4 ( L_39 ) ;
return - V_118 ;
}
F_4 ( L_40 , V_13 -> V_144 -> V_32 ) ;
return 0 ;
}
static int F_51 ( struct V_80 * V_80 , void * V_11 , unsigned int V_177 )
{
int V_18 ;
F_2 ( L_41 , V_177 ) ;
if ( V_177 )
V_18 = F_3 ( V_11 ) ;
else
V_18 = F_11 ( V_11 ) ;
return V_18 ;
}
static int F_52 ( struct V_80 * V_80 , void * V_167 , struct V_178 * V_179 )
{
struct V_10 * V_11 = V_167 ;
if ( V_179 -> type == V_141 )
return F_53 ( & V_11 -> V_180 , V_179 ) ;
if ( V_179 -> type == V_181 )
return F_53 ( & V_11 -> V_182 , V_179 ) ;
return - V_118 ;
}
static int F_54 ( struct V_80 * V_80 , void * V_167 , struct V_183 * V_38 )
{
struct V_10 * V_11 = V_167 ;
if ( V_38 -> type == V_141 )
return F_55 ( & V_11 -> V_180 , V_38 ) ;
if ( V_38 -> type == V_181 )
return F_55 ( & V_11 -> V_182 , V_38 ) ;
return - V_118 ;
}
static int F_56 ( struct V_80 * V_80 , void * V_167 , struct V_183 * V_38 )
{
struct V_10 * V_11 = V_167 ;
if ( V_38 -> type == V_141 )
return F_57 ( & V_11 -> V_180 , V_38 ) ;
if ( V_38 -> type == V_181 )
return F_57 ( & V_11 -> V_182 , V_38 ) ;
return - V_118 ;
}
static int F_58 ( struct V_80 * V_80 , void * V_167 , struct V_183 * V_38 )
{
struct V_10 * V_11 = V_167 ;
if ( V_38 -> type == V_141 )
return F_59 ( & V_11 -> V_180 , V_38 , V_80 -> V_184 & V_185 ) ;
if ( V_38 -> type == V_181 )
return F_59 ( & V_11 -> V_182 , V_38 , V_80 -> V_184 & V_185 ) ;
return - V_118 ;
}
static int F_60 ( struct V_80 * V_80 , void * V_167 , enum V_186 type )
{
struct V_10 * V_11 = V_167 ;
int V_18 ;
F_2 ( L_42 , type ) ;
V_18 = F_20 ( V_11 ) ;
if ( V_18 )
return V_18 ;
if ( type == V_141 )
return F_61 ( & V_11 -> V_180 ) ;
if ( type == V_181 )
return F_61 ( & V_11 -> V_182 ) ;
return - V_118 ;
}
static int F_62 ( struct V_80 * V_80 , void * V_167 , enum V_186 type )
{
struct V_10 * V_11 = V_167 ;
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
V_18 = - V_118 ;
if ( type == V_141 )
V_18 = F_63 ( & V_11 -> V_180 ) ;
else if ( type == V_181 )
V_18 = F_63 ( & V_11 -> V_182 ) ;
if ( 0 != V_18 ) {
F_2 ( L_44 ) ;
F_25 ( V_11 , V_80 ) ;
} else {
V_18 = F_25 ( V_11 , V_80 ) ;
}
return V_18 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_37 * V_187 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
V_38 -> V_43 . V_188 = V_189 ;
F_65 ( V_3 , V_38 , V_187 ) ;
F_66 ( & V_13 -> V_190 . V_191 , V_192 + V_193 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 , struct V_37 * V_38 )
{
F_68 ( V_3 -> V_40 , & V_38 -> V_53 [ 0 ] ) ;
F_68 ( V_3 -> V_40 , & V_38 -> V_53 [ 1 ] ) ;
F_68 ( V_3 -> V_40 , & V_38 -> V_53 [ 2 ] ) ;
}
static int F_69 ( struct V_194 * V_195 ,
struct V_196 * V_43 , enum V_149 V_34 )
{
struct V_80 * V_80 = V_195 -> V_197 ;
struct V_10 * V_11 = V_80 -> V_198 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_37 * V_38 = (struct V_37 * ) V_43 ;
int V_60 , V_18 = 0 ;
F_16 ( L_45 , V_43 ) ;
if ( V_13 -> V_74 . V_27 < 48 ||
V_13 -> V_74 . V_28 < 32 ||
V_13 -> V_74 . V_27 > V_13 -> V_144 -> V_153 ||
V_13 -> V_74 . V_28 > V_13 -> V_144 -> V_154 ) {
F_2 ( L_46 ,
V_13 -> V_74 . V_27 , V_13 -> V_74 . V_28 ) ;
return - V_118 ;
}
V_60 = V_13 -> V_74 . V_163 ;
if ( 0 != V_38 -> V_43 . V_199 && V_38 -> V_43 . V_200 < V_60 ) {
F_2 ( L_47 ) ;
return - V_118 ;
}
F_16 ( L_48 ,
V_13 -> V_74 . V_27 , V_13 -> V_74 . V_28 ,
V_60 , V_33 [ V_13 -> V_74 . V_34 ] ) ;
if ( V_38 -> V_43 . V_27 != V_13 -> V_74 . V_27 ||
V_38 -> V_43 . V_119 != V_13 -> V_74 . V_119 ||
V_38 -> V_43 . V_28 != V_13 -> V_74 . V_28 ||
V_38 -> V_43 . V_60 != V_60 ||
V_38 -> V_43 . V_34 != V_34 ||
V_38 -> V_43 . V_34 != V_13 -> V_74 . V_34 ||
V_38 -> V_16 != & V_13 -> V_74 ) {
F_70 ( V_3 , V_195 , V_38 ) ;
}
if ( V_201 == V_38 -> V_43 . V_188 ) {
struct V_1 * V_49 ;
V_38 -> V_43 . V_119 = V_13 -> V_74 . V_119 ;
V_38 -> V_43 . V_27 = V_13 -> V_74 . V_27 ;
V_38 -> V_43 . V_28 = V_13 -> V_74 . V_28 ;
V_38 -> V_43 . V_60 = V_60 ;
V_38 -> V_43 . V_34 = V_34 ;
V_38 -> V_16 = & V_13 -> V_74 ;
V_38 -> V_43 . V_34 = V_13 -> V_74 . V_34 ;
V_49 = F_1 ( V_3 , V_38 -> V_16 -> V_9 ) ;
F_67 ( V_3 , V_38 ) ;
if( 0 != F_15 ( V_49 -> V_50 ) ) {
F_71 ( V_3 -> V_40 , & V_38 -> V_53 [ 0 ] ) ;
F_71 ( V_3 -> V_40 , & V_38 -> V_53 [ 1 ] ) ;
F_71 ( V_3 -> V_40 , & V_38 -> V_53 [ 2 ] ) ;
} else {
F_71 ( V_3 -> V_40 , & V_38 -> V_53 [ 0 ] ) ;
}
V_18 = F_72 ( V_195 , & V_38 -> V_43 , & V_13 -> V_111 ) ;
if ( V_18 )
goto V_202;
V_18 = F_13 ( V_3 , V_38 ) ;
if ( V_18 )
goto V_202;
}
V_38 -> V_43 . V_188 = V_203 ;
V_38 -> V_204 = F_64 ;
return 0 ;
V_202:
F_2 ( L_49 ) ;
F_70 ( V_3 , V_195 , V_38 ) ;
return V_18 ;
}
static int F_73 ( struct V_194 * V_195 , unsigned int * V_205 , unsigned int * V_60 )
{
struct V_80 * V_80 = V_195 -> V_197 ;
struct V_10 * V_11 = V_80 -> V_198 ;
struct V_12 * V_13 = V_11 -> V_3 -> V_14 ;
if ( 0 == * V_205 || * V_205 > V_206 )
* V_205 = V_206 ;
* V_60 = V_13 -> V_74 . V_163 ;
if( ( * V_205 * * V_60 ) > ( V_207 * 1048576 ) ) {
* V_205 = ( V_207 * 1048576 ) / * V_60 ;
}
F_16 ( L_50 , * V_205 , * V_60 ) ;
return 0 ;
}
static void F_74 ( struct V_194 * V_195 , struct V_196 * V_43 )
{
struct V_80 * V_80 = V_195 -> V_197 ;
struct V_10 * V_11 = V_80 -> V_198 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_37 * V_38 = (struct V_37 * ) V_43 ;
F_16 ( L_45 , V_43 ) ;
F_75 ( V_11 -> V_3 , & V_13 -> V_190 , V_38 ) ;
}
static void F_76 ( struct V_194 * V_195 , struct V_196 * V_43 )
{
struct V_80 * V_80 = V_195 -> V_197 ;
struct V_10 * V_11 = V_80 -> V_198 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_37 * V_38 = (struct V_37 * ) V_43 ;
F_16 ( L_45 , V_43 ) ;
F_70 ( V_3 , V_195 , V_38 ) ;
F_67 ( V_3 , V_38 ) ;
}
static void F_77 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
F_78 ( & V_13 -> V_190 . V_208 ) ;
F_79 ( & V_13 -> V_190 . V_191 ) ;
V_13 -> V_190 . V_191 . V_209 = V_210 ;
V_13 -> V_190 . V_191 . V_211 = ( unsigned long ) ( & V_13 -> V_190 ) ;
V_13 -> V_190 . V_3 = V_3 ;
V_13 -> V_144 = & V_3 -> V_101 -> V_175 [ 0 ] ;
V_13 -> V_212 = V_213 ;
V_13 -> V_214 = V_215 ;
}
static int F_80 ( struct V_2 * V_3 , struct V_80 * V_80 )
{
struct V_10 * V_11 = V_80 -> V_198 ;
F_81 ( & V_11 -> V_180 , & V_216 ,
& V_3 -> V_40 -> V_3 , & V_3 -> V_85 ,
V_141 ,
V_156 ,
sizeof( struct V_37 ) ,
V_80 , & V_3 -> V_217 ) ;
return 0 ;
}
static void F_82 ( struct V_2 * V_3 , struct V_80 * V_80 )
{
struct V_10 * V_11 = V_80 -> V_198 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_194 * V_195 = & V_11 -> V_180 ;
if ( F_5 ( V_11 ) != 0 )
F_25 ( V_11 , V_80 ) ;
else if ( F_6 ( V_11 ) != 0 )
F_11 ( V_11 ) ;
F_83 ( V_195 ) ;
}
static void F_84 ( struct V_2 * V_3 , unsigned long V_218 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_219 * V_195 = & V_13 -> V_190 ;
F_85 ( & V_3 -> V_85 ) ;
F_16 ( L_51 ) ;
if( NULL != V_195 -> V_220 ) {
F_86 ( V_3 , V_195 , V_221 ) ;
}
F_87 ( V_3 , V_195 , 0 ) ;
F_88 ( & V_3 -> V_85 ) ;
}
static T_4 F_89 ( struct V_80 * V_80 , char T_5 * V_211 , T_6 V_205 , T_7 * V_222 )
{
struct V_10 * V_11 = V_80 -> V_198 ;
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
goto V_223;
}
V_17 = F_90 ( & V_11 -> V_180 , V_211 , V_205 , V_222 ,
V_80 -> V_184 & V_185 ) ;
if ( V_17 != 0 ) {
F_25 ( V_11 , V_80 ) ;
} else {
V_17 = F_25 ( V_11 , V_80 ) ;
}
V_223:
if ( V_13 -> V_73 != NULL ) {
F_3 ( V_13 -> V_73 ) ;
V_13 -> V_73 = NULL ;
}
return V_17 ;
}
