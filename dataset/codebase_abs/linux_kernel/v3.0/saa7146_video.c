struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
int V_5 , V_6 = V_7 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_8 [ V_5 ] . V_9 == V_4 ) {
return V_8 + V_5 ;
}
}
F_2 ( ( L_1 , ( char * ) & V_4 ) ) ;
return NULL ;
}
int F_3 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_15 V_16 ;
int V_17 = 0 , V_18 = 0 ;
F_4 ( ( L_2 , V_3 , V_11 ) ) ;
if( NULL == V_11 -> V_19 . V_11 ) {
F_2 ( ( L_3 ) ) ;
return - V_20 ;
}
if ( F_5 ( V_11 ) != 0 ) {
F_2 ( ( L_4 ) ) ;
return - V_21 ;
}
if ( F_6 ( V_11 ) != 0 ) {
if ( V_13 -> V_22 == V_11 ) {
F_2 ( ( L_5 ) ) ;
return 0 ;
}
F_2 ( ( L_6 ) ) ;
return - V_21 ;
}
if ( 0 == F_7 ( V_11 , V_23 | V_24 ) ) {
F_2 ( ( L_7 ) ) ;
return - V_21 ;
}
V_16 . V_16 . V_25 = V_11 -> V_19 . V_25 ;
V_18 = F_8 ( NULL , V_11 , & V_16 ) ;
if ( 0 != V_18 ) {
F_9 ( V_13 -> V_22 , V_23 | V_24 ) ;
return - V_21 ;
}
V_11 -> V_19 . V_25 = V_16 . V_16 . V_25 ;
V_13 -> V_26 = & V_11 -> V_19 ;
F_2 ( ( L_8 ,
V_11 -> V_19 . V_25 . V_27 . V_28 , V_11 -> V_19 . V_25 . V_27 . V_29 ,
V_11 -> V_19 . V_25 . V_27 . V_30 , V_11 -> V_19 . V_25 . V_27 . V_31 ,
V_13 -> V_32 -> V_33 , V_34 [ V_11 -> V_19 . V_25 . V_35 ] ) ) ;
if ( 0 != ( V_17 = F_10 ( V_11 ) ) ) {
F_2 ( ( L_9 , V_17 ) ) ;
F_9 ( V_13 -> V_22 , V_23 | V_24 ) ;
return V_17 ;
}
V_13 -> V_36 = V_37 ;
V_13 -> V_22 = V_11 ;
return 0 ;
}
int F_11 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
F_4 ( ( L_2 , V_3 , V_11 ) ) ;
if ( F_5 ( V_11 ) != 0 ) {
F_2 ( ( L_4 ) ) ;
return - V_21 ;
}
if ( ( V_13 -> V_36 & V_37 ) == 0 ) {
F_2 ( ( L_10 ) ) ;
return 0 ;
}
if ( V_13 -> V_22 != V_11 ) {
F_2 ( ( L_11 ) ) ;
return - V_21 ;
}
V_13 -> V_36 = 0 ;
V_13 -> V_22 = NULL ;
F_12 ( V_11 ) ;
F_9 ( V_11 , V_23 | V_24 ) ;
return 0 ;
}
static struct V_38 * F_13 ( int V_39 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ )
if ( V_41 [ V_5 ] . V_39 == V_39 )
return V_41 + V_5 ;
return NULL ;
}
static int F_14 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
struct V_44 * V_45 = V_3 -> V_45 ;
struct V_46 * V_47 = F_15 ( & V_43 -> V_48 ) ;
struct V_49 * V_50 = V_47 -> V_51 ;
int V_52 = V_47 -> V_53 ;
struct V_1 * V_54 = F_1 ( V_3 , V_43 -> V_16 -> V_9 ) ;
F_4 ( ( L_12 , V_3 , V_43 , V_52 ) ) ;
if( 0 != F_16 ( V_54 -> V_55 ) ) {
struct V_56 * V_57 = & V_43 -> V_58 [ 0 ] ;
struct V_56 * V_59 = & V_43 -> V_58 [ 1 ] ;
struct V_56 * V_60 = & V_43 -> V_58 [ 2 ] ;
T_1 * V_61 , * V_62 , * V_63 ;
T_1 V_64 ;
int V_65 = V_43 -> V_16 -> V_28 * V_43 -> V_16 -> V_29 ;
int V_5 , V_66 , V_67 , V_68 , V_69 , V_70 , V_71 ;
switch( V_54 -> V_72 ) {
case 12 : {
V_67 = ( ( V_65 + V_73 ) / V_73 ) - 1 ;
V_68 = ( ( V_65 + ( V_65 / 4 ) + V_73 ) / V_73 ) - 1 ;
V_69 = ( ( V_65 + ( V_65 / 2 ) + V_73 ) / V_73 ) - 1 ;
V_70 = V_65 % V_73 ;
V_71 = ( V_65 + ( V_65 / 4 ) ) % V_73 ;
F_17 ( ( L_13 , V_65 , V_67 , V_68 , V_69 , V_70 , V_71 ) ) ;
break;
}
case 16 : {
V_67 = ( ( V_65 + V_73 ) / V_73 ) - 1 ;
V_68 = ( ( V_65 + ( V_65 / 2 ) + V_73 ) / V_73 ) - 1 ;
V_69 = ( ( 2 * V_65 + V_73 ) / V_73 ) - 1 ;
V_70 = V_65 % V_73 ;
V_71 = ( V_65 + ( V_65 / 2 ) ) % V_73 ;
F_17 ( ( L_13 , V_65 , V_67 , V_68 , V_69 , V_70 , V_71 ) ) ;
break;
}
default: {
return - 1 ;
}
}
V_61 = V_57 -> V_74 ;
V_62 = V_59 -> V_74 ;
V_63 = V_60 -> V_74 ;
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ , V_50 ++ ) {
for ( V_66 = 0 ; V_66 * 4096 < V_50 -> V_52 ; V_66 ++ , V_61 ++ ) {
* V_61 = F_18 ( F_19 ( V_50 ) - V_50 -> V_75 ) ;
}
}
V_57 -> V_75 = V_47 -> V_51 -> V_75 ;
V_59 -> V_75 = V_57 -> V_75 + V_70 ;
V_60 -> V_75 = V_57 -> V_75 + V_71 ;
V_61 = V_57 -> V_74 ;
for( V_5 = V_67 ; V_5 <= V_68 ; V_5 ++ , V_62 ++ ) {
* V_62 = V_61 [ V_5 ] ;
}
V_64 = * ( V_62 - 1 ) ;
for(; V_5 < 1024 ; V_5 ++ , V_62 ++ ) {
* V_62 = V_64 ;
}
V_61 = V_57 -> V_74 ;
for( V_5 = V_68 ; V_5 <= V_69 ; V_5 ++ , V_63 ++ ) {
* V_63 = V_61 [ V_5 ] ;
}
V_64 = * ( V_63 - 1 ) ;
for(; V_5 < 1024 ; V_5 ++ , V_63 ++ ) {
* V_63 = V_64 ;
}
V_61 = V_57 -> V_74 + V_67 ;
V_64 = V_57 -> V_74 [ V_67 ] ;
for( V_5 = V_67 ; V_5 < 1024 ; V_5 ++ , V_61 ++ ) {
* V_61 = V_64 ;
}
} else {
struct V_56 * V_58 = & V_43 -> V_58 [ 0 ] ;
return F_20 ( V_45 , V_58 , V_50 , V_52 ) ;
}
return 0 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 = NULL ;
unsigned int V_76 ;
int V_17 = 0 , V_18 = 0 ;
F_4 ( ( L_2 , V_3 , V_11 ) ) ;
if ( ( V_13 -> V_36 & V_77 ) != 0 ) {
if ( V_13 -> V_22 == V_11 ) {
F_22 ( ( L_14 ) ) ;
return 0 ;
}
F_22 ( ( L_15 ) ) ;
return - V_21 ;
}
if ( ( V_13 -> V_36 & V_37 ) != 0 ) {
F_22 ( ( L_16 ) ) ;
V_13 -> V_78 = V_13 -> V_22 ;
V_18 = F_11 ( V_13 -> V_22 ) ;
if ( 0 != V_18 ) {
F_2 ( ( L_17 ) ) ;
return V_18 ;
}
}
V_16 = F_1 ( V_3 , V_11 -> V_79 . V_9 ) ;
F_23 ( NULL == V_16 ) ;
if ( 0 != ( V_16 -> V_80 & V_81 ) ) {
V_76 = V_23 | V_24 | V_82 ;
} else {
V_76 = V_23 ;
}
V_17 = F_7 ( V_11 , V_76 ) ;
if ( 0 == V_17 ) {
F_22 ( ( L_18 , V_76 ) ) ;
if ( V_13 -> V_78 != NULL ) {
F_3 ( V_13 -> V_78 ) ;
V_13 -> V_78 = NULL ;
}
return - V_21 ;
}
F_24 ( V_3 , V_83 , V_84 ) ;
F_25 ( V_3 , V_84 ) ;
V_13 -> V_22 = V_11 ;
V_13 -> V_36 = V_77 ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 , struct V_85 * V_85 )
{
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 = NULL ;
unsigned long V_80 ;
unsigned int V_76 ;
T_2 V_86 = 0 ;
F_4 ( ( L_2 , V_3 , V_11 ) ) ;
if ( ( V_13 -> V_36 & V_77 ) != V_77 ) {
F_22 ( ( L_19 ) ) ;
return 0 ;
}
if ( V_13 -> V_22 != V_11 ) {
F_22 ( ( L_20 ) ) ;
return - V_21 ;
}
V_16 = F_1 ( V_3 , V_11 -> V_79 . V_9 ) ;
F_23 ( NULL == V_16 ) ;
if ( 0 != ( V_16 -> V_80 & V_81 ) ) {
V_76 = V_23 | V_24 | V_82 ;
V_86 = V_87 | V_88 | V_89 ;
} else {
V_76 = V_23 ;
V_86 = V_87 ;
}
F_27 ( & V_3 -> V_90 , V_80 ) ;
F_24 ( V_3 , V_91 , V_92 ) ;
F_28 ( V_3 , V_84 ) ;
F_24 ( V_3 , V_91 , V_86 ) ;
F_29 ( & V_3 -> V_90 , V_80 ) ;
V_13 -> V_22 = NULL ;
V_13 -> V_36 = 0 ;
F_9 ( V_11 , V_76 ) ;
if ( V_13 -> V_78 != NULL ) {
F_3 ( V_13 -> V_78 ) ;
V_13 -> V_78 = NULL ;
}
return 0 ;
}
static int F_30 ( struct V_85 * V_85 , void * V_11 , struct V_93 * V_94 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
strcpy ( ( char * ) V_94 -> V_95 , L_21 ) ;
F_31 ( ( char * ) V_94 -> V_96 , V_3 -> V_97 -> V_33 , sizeof( V_94 -> V_96 ) ) ;
sprintf ( ( char * ) V_94 -> V_98 , L_22 , F_32 ( V_3 -> V_45 ) ) ;
V_94 -> V_99 = V_100 ;
V_94 -> V_101 =
V_102 |
V_103 |
V_104 |
V_105 ;
V_94 -> V_101 |= V_3 -> V_106 -> V_101 ;
return 0 ;
}
static int F_33 ( struct V_85 * V_85 , void * V_11 , struct V_107 * V_108 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
* V_108 = V_13 -> V_109 ;
V_108 -> V_110 = V_111 ;
return 0 ;
}
static int F_34 ( struct V_85 * V_85 , void * V_11 , struct V_107 * V_108 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 ;
F_4 ( ( L_23 ) ) ;
if ( ! F_35 ( V_112 ) && ! F_35 ( V_113 ) )
return - V_114 ;
V_16 = F_1 ( V_3 , V_108 -> V_16 . V_9 ) ;
if ( NULL == V_16 )
return - V_115 ;
if ( V_16 -> V_80 & V_81 )
F_22 ( ( L_24 ,
( char * ) & V_16 -> V_9 ) ) ;
if ( F_6 ( V_11 ) != 0 ) {
if ( V_13 -> V_22 != V_11 ) {
F_2 ( ( L_25 ) ) ;
return - V_21 ;
}
}
V_13 -> V_109 = * V_108 ;
V_13 -> V_32 = V_16 ;
if ( V_13 -> V_109 . V_16 . V_116 < V_13 -> V_109 . V_16 . V_28 ) {
V_13 -> V_109 . V_16 . V_116 = V_13 -> V_109 . V_16 . V_28 * V_16 -> V_72 / 8 ;
F_2 ( ( L_26 , V_13 -> V_109 . V_16 . V_116 ) ) ;
}
return 0 ;
}
static int F_36 ( struct V_85 * V_85 , void * V_11 , struct V_117 * V_118 )
{
if ( V_118 -> V_119 >= V_7 )
return - V_115 ;
F_31 ( ( char * ) V_118 -> V_120 , V_8 [ V_118 -> V_119 ] . V_33 ,
sizeof( V_118 -> V_120 ) ) ;
V_118 -> V_9 = V_8 [ V_118 -> V_119 ] . V_9 ;
return 0 ;
}
static int F_37 ( struct V_85 * V_85 , void * V_11 , struct V_38 * V_121 )
{
const struct V_38 * V_122 ;
if ( ( V_121 -> V_39 < V_123 ||
V_121 -> V_39 >= V_124 ) &&
( V_121 -> V_39 < V_125 ||
V_121 -> V_39 >= V_126 ) )
return - V_115 ;
V_122 = F_13 ( V_121 -> V_39 ) ;
if ( V_122 == NULL )
return - V_115 ;
F_4 ( ( L_27 , V_121 -> V_39 ) ) ;
* V_121 = * V_122 ;
return 0 ;
}
static int F_38 ( struct V_85 * V_85 , void * V_11 , struct V_127 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
const struct V_38 * V_122 ;
T_2 V_128 = 0 ;
V_122 = F_13 ( V_121 -> V_39 ) ;
if ( NULL == V_122 )
return - V_115 ;
switch ( V_121 -> V_39 ) {
case V_129 :
V_128 = F_39 ( V_3 , V_130 ) ;
V_121 -> V_128 = 0xff & ( V_128 >> 24 ) ;
F_2 ( ( L_28 , V_121 -> V_128 ) ) ;
break;
case V_131 :
V_128 = F_39 ( V_3 , V_130 ) ;
V_121 -> V_128 = 0x7f & ( V_128 >> 16 ) ;
F_2 ( ( L_29 , V_121 -> V_128 ) ) ;
break;
case V_132 :
V_128 = F_39 ( V_3 , V_130 ) ;
V_121 -> V_128 = 0x7f & ( V_128 >> 0 ) ;
F_2 ( ( L_30 , V_121 -> V_128 ) ) ;
break;
case V_133 :
V_121 -> V_128 = V_13 -> V_134 ;
F_2 ( ( L_31 , V_121 -> V_128 ) ) ;
break;
case V_135 :
V_121 -> V_128 = V_13 -> V_136 ;
F_2 ( ( L_32 , V_121 -> V_128 ) ) ;
break;
default:
return - V_115 ;
}
return 0 ;
}
static int F_40 ( struct V_85 * V_85 , void * V_11 , struct V_127 * V_121 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
const struct V_38 * V_122 ;
V_122 = F_13 ( V_121 -> V_39 ) ;
if ( NULL == V_122 ) {
F_2 ( ( L_33 , V_121 -> V_39 ) ) ;
return - V_115 ;
}
switch ( V_122 -> type ) {
case V_137 :
case V_138 :
case V_139 :
if ( V_121 -> V_128 < V_122 -> V_140 )
V_121 -> V_128 = V_122 -> V_140 ;
if ( V_121 -> V_128 > V_122 -> V_141 )
V_121 -> V_128 = V_122 -> V_141 ;
break;
default:
;
}
switch ( V_121 -> V_39 ) {
case V_129 : {
T_2 V_128 = F_39 ( V_3 , V_130 ) ;
V_128 &= 0x00ffffff ;
V_128 |= ( V_121 -> V_128 << 24 ) ;
F_24 ( V_3 , V_130 , V_128 ) ;
F_24 ( V_3 , V_83 , V_87 | V_142 ) ;
break;
}
case V_131 : {
T_2 V_128 = F_39 ( V_3 , V_130 ) ;
V_128 &= 0xff00ffff ;
V_128 |= ( V_121 -> V_128 << 16 ) ;
F_24 ( V_3 , V_130 , V_128 ) ;
F_24 ( V_3 , V_83 , V_87 | V_142 ) ;
break;
}
case V_132 : {
T_2 V_128 = F_39 ( V_3 , V_130 ) ;
V_128 &= 0xffffff00 ;
V_128 |= ( V_121 -> V_128 << 0 ) ;
F_24 ( V_3 , V_130 , V_128 ) ;
F_24 ( V_3 , V_83 , V_87 | V_142 ) ;
break;
}
case V_135 :
if ( F_5 ( V_11 ) != 0 ) {
F_2 ( ( L_34 ) ) ;
return - V_21 ;
}
V_13 -> V_136 = V_121 -> V_128 ;
break;
case V_133 :
if ( F_5 ( V_11 ) != 0 ) {
F_2 ( ( L_35 ) ) ;
return - V_21 ;
}
V_13 -> V_134 = V_121 -> V_128 ;
break;
default:
return - V_115 ;
}
if ( F_6 ( V_11 ) != 0 ) {
F_11 ( V_11 ) ;
F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_41 ( struct V_85 * V_85 , void * V_11 ,
struct V_143 * V_144 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
V_144 -> V_144 . V_145 . V_146 = 1 ;
F_42 ( V_13 -> V_147 -> V_39 ,
& V_144 -> V_144 . V_145 . V_148 ) ;
return 0 ;
}
static int F_43 ( struct V_85 * V_85 , void * V_11 , struct V_15 * V_118 )
{
V_118 -> V_16 . V_149 = ( (struct V_10 * ) V_11 ) -> V_79 ;
return 0 ;
}
static int F_44 ( struct V_85 * V_85 , void * V_11 , struct V_15 * V_118 )
{
V_118 -> V_16 . V_25 = ( (struct V_10 * ) V_11 ) -> V_19 . V_25 ;
return 0 ;
}
static int F_45 ( struct V_85 * V_85 , void * V_11 , struct V_15 * V_118 )
{
V_118 -> V_16 . V_150 = ( (struct V_10 * ) V_11 ) -> V_151 ;
return 0 ;
}
static int F_46 ( struct V_85 * V_85 , void * V_11 , struct V_15 * V_118 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_16 ;
enum V_152 V_35 ;
int V_153 , V_154 ;
int V_155 ;
F_4 ( ( L_36 , V_3 , V_11 ) ) ;
V_16 = F_1 ( V_3 , V_118 -> V_16 . V_149 . V_9 ) ;
if ( NULL == V_16 )
return - V_115 ;
V_35 = V_118 -> V_16 . V_149 . V_35 ;
V_153 = V_13 -> V_147 -> V_156 ;
V_154 = V_13 -> V_147 -> V_157 ;
if ( V_158 == V_35 ) {
V_35 = ( V_118 -> V_16 . V_149 . V_29 > V_154 / 2 )
? V_159
: V_160 ;
}
switch ( V_35 ) {
case V_161 :
V_13 -> V_162 = V_163 ;
V_154 = V_154 / 2 ;
break;
case V_163 :
case V_160 :
V_13 -> V_162 = V_159 ;
V_154 = V_154 / 2 ;
break;
case V_159 :
V_13 -> V_162 = V_159 ;
break;
default:
F_2 ( ( L_37 , V_35 ) ) ;
return - V_115 ;
}
V_118 -> V_16 . V_149 . V_35 = V_35 ;
if ( V_118 -> V_16 . V_149 . V_28 > V_153 )
V_118 -> V_16 . V_149 . V_28 = V_153 ;
if ( V_118 -> V_16 . V_149 . V_29 > V_154 )
V_118 -> V_16 . V_149 . V_29 = V_154 ;
V_155 = ( V_118 -> V_16 . V_149 . V_28 * V_16 -> V_72 ) / 8 ;
if ( V_118 -> V_16 . V_149 . V_116 < V_155 )
V_118 -> V_16 . V_149 . V_116 = V_155 ;
if ( V_118 -> V_16 . V_149 . V_116 > ( 2 * V_73 * V_16 -> V_72 ) / 8 )
V_118 -> V_16 . V_149 . V_116 = V_155 ;
V_118 -> V_16 . V_149 . V_164 = V_118 -> V_16 . V_149 . V_116 * V_118 -> V_16 . V_149 . V_29 ;
F_2 ( ( L_38 , V_118 -> V_16 . V_149 . V_28 ,
V_118 -> V_16 . V_149 . V_29 , V_118 -> V_16 . V_149 . V_116 , V_118 -> V_16 . V_149 . V_164 ) ) ;
return 0 ;
}
static int F_8 ( struct V_85 * V_85 , void * V_11 , struct V_15 * V_118 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_165 * V_25 = & V_118 -> V_16 . V_25 ;
enum V_152 V_35 ;
int V_153 , V_154 ;
F_4 ( ( L_39 , V_3 ) ) ;
if ( NULL == V_13 -> V_109 . V_166 ) {
F_2 ( ( L_40 ) ) ;
return - V_115 ;
}
if ( NULL == V_13 -> V_32 ) {
F_2 ( ( L_41 ) ) ;
return - V_115 ;
}
if ( V_25 -> V_27 . V_28 < 48 || V_25 -> V_27 . V_29 < 32 ) {
F_2 ( ( L_42 , V_25 -> V_27 . V_28 , V_25 -> V_27 . V_29 ) ) ;
return - V_115 ;
}
if ( V_25 -> V_167 > 16 ) {
F_2 ( ( L_43 ) ) ;
return - V_115 ;
}
V_35 = V_25 -> V_35 ;
V_153 = V_13 -> V_147 -> V_156 ;
V_154 = V_13 -> V_147 -> V_157 ;
if ( V_158 == V_35 ) {
V_35 = ( V_25 -> V_27 . V_29 > V_154 / 2 )
? V_159
: V_163 ;
}
switch ( V_35 ) {
case V_163 :
case V_160 :
case V_161 :
V_154 = V_154 / 2 ;
break;
case V_159 :
break;
default:
F_2 ( ( L_37 , V_35 ) ) ;
return - V_115 ;
}
V_25 -> V_35 = V_35 ;
if ( V_25 -> V_27 . V_28 > V_153 )
V_25 -> V_27 . V_28 = V_153 ;
if ( V_25 -> V_27 . V_29 > V_154 )
V_25 -> V_27 . V_29 = V_154 ;
return 0 ;
}
static int F_47 ( struct V_85 * V_85 , void * V_168 , struct V_15 * V_118 )
{
struct V_10 * V_11 = V_168 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_4 ( ( L_36 , V_3 , V_11 ) ) ;
if ( F_5 ( V_11 ) != 0 ) {
F_4 ( ( L_44 ) ) ;
return - V_21 ;
}
V_18 = F_46 ( V_85 , V_11 , V_118 ) ;
if ( 0 != V_18 )
return V_18 ;
V_11 -> V_79 = V_118 -> V_16 . V_149 ;
F_4 ( ( L_45 , ( char * ) & V_11 -> V_79 . V_9 ) ) ;
return 0 ;
}
static int F_48 ( struct V_85 * V_85 , void * V_168 , struct V_15 * V_118 )
{
struct V_10 * V_11 = V_168 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_4 ( ( L_46 , V_3 , V_11 ) ) ;
V_18 = F_8 ( V_85 , V_11 , V_118 ) ;
if ( 0 != V_18 )
return V_18 ;
V_11 -> V_19 . V_25 = V_118 -> V_16 . V_25 ;
V_11 -> V_19 . V_169 = V_118 -> V_16 . V_25 . V_167 ;
if ( V_11 -> V_19 . V_169 > 16 )
V_11 -> V_19 . V_169 = 16 ;
if ( F_49 ( V_11 -> V_19 . V_170 , V_118 -> V_16 . V_25 . V_170 ,
sizeof( struct V_171 ) * V_11 -> V_19 . V_169 ) ) {
return - V_172 ;
}
V_11 -> V_19 . V_11 = V_11 ;
if ( F_6 ( V_11 ) != 0 ) {
F_11 ( V_11 ) ;
F_3 ( V_11 ) ;
}
return 0 ;
}
static int F_50 ( struct V_85 * V_85 , void * V_11 , T_3 * V_173 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
* V_173 = V_13 -> V_147 -> V_39 ;
return 0 ;
}
static int F_51 ( struct V_85 * V_85 , void * V_11 , T_3 * V_39 )
{
struct V_2 * V_3 = ( (struct V_10 * ) V_11 ) -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_174 = 0 ;
int V_18 , V_5 ;
F_4 ( ( L_47 ) ) ;
if ( ( V_13 -> V_36 & V_77 ) == V_77 ) {
F_2 ( ( L_48 ) ) ;
return - V_21 ;
}
if ( ( V_13 -> V_36 & V_37 ) != 0 ) {
V_13 -> V_78 = V_13 -> V_22 ;
V_18 = F_11 ( V_13 -> V_22 ) ;
if ( 0 != V_18 ) {
F_2 ( ( L_17 ) ) ;
return V_18 ;
}
}
for ( V_5 = 0 ; V_5 < V_3 -> V_106 -> V_175 ; V_5 ++ )
if ( * V_39 & V_3 -> V_106 -> V_176 [ V_5 ] . V_39 )
break;
if ( V_5 != V_3 -> V_106 -> V_175 ) {
V_13 -> V_147 = & V_3 -> V_106 -> V_176 [ V_5 ] ;
if ( NULL != V_3 -> V_106 -> V_177 )
V_3 -> V_106 -> V_177 ( V_3 , V_13 -> V_147 ) ;
V_174 = 1 ;
}
if ( V_13 -> V_78 != NULL ) {
F_3 ( V_13 -> V_78 ) ;
V_13 -> V_78 = NULL ;
}
if ( ! V_174 ) {
F_4 ( ( L_49 ) ) ;
return - V_115 ;
}
F_4 ( ( L_50 , V_13 -> V_147 -> V_33 ) ) ;
return 0 ;
}
static int F_52 ( struct V_85 * V_85 , void * V_11 , unsigned int V_178 )
{
int V_18 ;
F_2 ( ( L_51 , V_178 ) ) ;
if ( V_178 )
V_18 = F_3 ( V_11 ) ;
else
V_18 = F_11 ( V_11 ) ;
return V_18 ;
}
static int F_53 ( struct V_85 * V_85 , void * V_168 , struct V_179 * V_180 )
{
struct V_10 * V_11 = V_168 ;
if ( V_180 -> type == V_181 )
return F_54 ( & V_11 -> V_182 , V_180 ) ;
if ( V_180 -> type == V_183 )
return F_54 ( & V_11 -> V_184 , V_180 ) ;
return - V_115 ;
}
static int F_55 ( struct V_85 * V_85 , void * V_168 , struct V_185 * V_43 )
{
struct V_10 * V_11 = V_168 ;
if ( V_43 -> type == V_181 )
return F_56 ( & V_11 -> V_182 , V_43 ) ;
if ( V_43 -> type == V_183 )
return F_56 ( & V_11 -> V_184 , V_43 ) ;
return - V_115 ;
}
static int F_57 ( struct V_85 * V_85 , void * V_168 , struct V_185 * V_43 )
{
struct V_10 * V_11 = V_168 ;
if ( V_43 -> type == V_181 )
return F_58 ( & V_11 -> V_182 , V_43 ) ;
if ( V_43 -> type == V_183 )
return F_58 ( & V_11 -> V_184 , V_43 ) ;
return - V_115 ;
}
static int F_59 ( struct V_85 * V_85 , void * V_168 , struct V_185 * V_43 )
{
struct V_10 * V_11 = V_168 ;
if ( V_43 -> type == V_181 )
return F_60 ( & V_11 -> V_182 , V_43 , V_85 -> V_186 & V_187 ) ;
if ( V_43 -> type == V_183 )
return F_60 ( & V_11 -> V_184 , V_43 , V_85 -> V_186 & V_187 ) ;
return - V_115 ;
}
static int F_61 ( struct V_85 * V_85 , void * V_168 , enum V_188 type )
{
struct V_10 * V_11 = V_168 ;
int V_18 ;
F_2 ( ( L_52 , type ) ) ;
V_18 = F_21 ( V_11 ) ;
if ( V_18 )
return V_18 ;
if ( type == V_181 )
return F_62 ( & V_11 -> V_182 ) ;
if ( type == V_183 )
return F_62 ( & V_11 -> V_184 ) ;
return - V_115 ;
}
static int F_63 ( struct V_85 * V_85 , void * V_168 , enum V_188 type )
{
struct V_10 * V_11 = V_168 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
int V_18 ;
F_2 ( ( L_53 , type ) ) ;
if ( ( V_13 -> V_36 & V_77 ) != V_77 ) {
F_22 ( ( L_19 ) ) ;
return 0 ;
}
if ( V_13 -> V_22 != V_11 ) {
F_22 ( ( L_20 ) ) ;
return - V_21 ;
}
V_18 = - V_115 ;
if ( type == V_181 )
V_18 = F_64 ( & V_11 -> V_182 ) ;
else if ( type == V_183 )
V_18 = F_64 ( & V_11 -> V_184 ) ;
if ( 0 != V_18 ) {
F_2 ( ( L_54 ) ) ;
F_26 ( V_11 , V_85 ) ;
} else {
V_18 = F_26 ( V_11 , V_85 ) ;
}
return V_18 ;
}
static int F_65 ( struct V_85 * V_85 , void * V_168 ,
struct V_189 * V_190 )
{
struct V_10 * V_11 = V_168 ;
struct V_2 * V_3 = V_11 -> V_3 ;
V_190 -> V_191 = V_192 ;
V_190 -> V_193 = 0 ;
if ( V_190 -> V_194 . type == V_195 && ! V_190 -> V_194 . V_196 ) {
V_190 -> V_191 = V_197 ;
return 0 ;
}
return F_66 ( & V_3 -> V_198 , 0 ,
V_199 , V_200 , V_190 ) ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
struct V_42 * V_201 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
V_43 -> V_48 . V_202 = V_203 ;
F_68 ( V_3 , V_43 , V_201 ) ;
F_69 ( & V_13 -> V_182 . V_204 , V_205 + V_206 ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
F_71 ( V_3 -> V_45 , & V_43 -> V_58 [ 0 ] ) ;
F_71 ( V_3 -> V_45 , & V_43 -> V_58 [ 1 ] ) ;
F_71 ( V_3 -> V_45 , & V_43 -> V_58 [ 2 ] ) ;
}
static int F_72 ( struct V_207 * V_208 ,
struct V_209 * V_48 , enum V_152 V_35 )
{
struct V_85 * V_85 = V_208 -> V_210 ;
struct V_10 * V_11 = V_85 -> V_211 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_42 * V_43 = (struct V_42 * ) V_48 ;
int V_65 , V_18 = 0 ;
F_17 ( ( L_55 , V_48 ) ) ;
if ( V_11 -> V_79 . V_28 < 48 ||
V_11 -> V_79 . V_29 < 32 ||
V_11 -> V_79 . V_28 > V_13 -> V_147 -> V_156 ||
V_11 -> V_79 . V_29 > V_13 -> V_147 -> V_157 ) {
F_2 ( ( L_56 , V_11 -> V_79 . V_28 , V_11 -> V_79 . V_29 ) ) ;
return - V_115 ;
}
V_65 = V_11 -> V_79 . V_164 ;
if ( 0 != V_43 -> V_48 . V_212 && V_43 -> V_48 . V_213 < V_65 ) {
F_2 ( ( L_57 ) ) ;
return - V_115 ;
}
F_17 ( ( L_58 ,
V_11 -> V_79 . V_28 , V_11 -> V_79 . V_29 , V_65 , V_34 [ V_11 -> V_79 . V_35 ] ) ) ;
if ( V_43 -> V_48 . V_28 != V_11 -> V_79 . V_28 ||
V_43 -> V_48 . V_116 != V_11 -> V_79 . V_116 ||
V_43 -> V_48 . V_29 != V_11 -> V_79 . V_29 ||
V_43 -> V_48 . V_65 != V_65 ||
V_43 -> V_48 . V_35 != V_35 ||
V_43 -> V_48 . V_35 != V_11 -> V_79 . V_35 ||
V_43 -> V_16 != & V_11 -> V_79 ) {
F_73 ( V_3 , V_208 , V_43 ) ;
}
if ( V_214 == V_43 -> V_48 . V_202 ) {
struct V_1 * V_54 ;
V_43 -> V_48 . V_116 = V_11 -> V_79 . V_116 ;
V_43 -> V_48 . V_28 = V_11 -> V_79 . V_28 ;
V_43 -> V_48 . V_29 = V_11 -> V_79 . V_29 ;
V_43 -> V_48 . V_65 = V_65 ;
V_43 -> V_48 . V_35 = V_35 ;
V_43 -> V_16 = & V_11 -> V_79 ;
V_43 -> V_48 . V_35 = V_11 -> V_79 . V_35 ;
V_54 = F_1 ( V_3 , V_43 -> V_16 -> V_9 ) ;
F_70 ( V_3 , V_43 ) ;
if( 0 != F_16 ( V_54 -> V_55 ) ) {
F_74 ( V_3 -> V_45 , & V_43 -> V_58 [ 0 ] ) ;
F_74 ( V_3 -> V_45 , & V_43 -> V_58 [ 1 ] ) ;
F_74 ( V_3 -> V_45 , & V_43 -> V_58 [ 2 ] ) ;
} else {
F_74 ( V_3 -> V_45 , & V_43 -> V_58 [ 0 ] ) ;
}
V_18 = F_75 ( V_208 , & V_43 -> V_48 , & V_13 -> V_109 ) ;
if ( V_18 )
goto V_215;
V_18 = F_14 ( V_3 , V_43 ) ;
if ( V_18 )
goto V_215;
}
V_43 -> V_48 . V_202 = V_216 ;
V_43 -> V_217 = F_67 ;
return 0 ;
V_215:
F_2 ( ( L_59 ) ) ;
F_73 ( V_3 , V_208 , V_43 ) ;
return V_18 ;
}
static int F_76 ( struct V_207 * V_208 , unsigned int * V_218 , unsigned int * V_65 )
{
struct V_85 * V_85 = V_208 -> V_210 ;
struct V_10 * V_11 = V_85 -> V_211 ;
if ( 0 == * V_218 || * V_218 > V_219 )
* V_218 = V_219 ;
* V_65 = V_11 -> V_79 . V_164 ;
if( ( * V_218 * * V_65 ) > ( V_220 * 1048576 ) ) {
* V_218 = ( V_220 * 1048576 ) / * V_65 ;
}
F_17 ( ( L_60 , * V_218 , * V_65 ) ) ;
return 0 ;
}
static void F_77 ( struct V_207 * V_208 , struct V_209 * V_48 )
{
struct V_85 * V_85 = V_208 -> V_210 ;
struct V_10 * V_11 = V_85 -> V_211 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_42 * V_43 = (struct V_42 * ) V_48 ;
F_17 ( ( L_55 , V_48 ) ) ;
F_78 ( V_11 -> V_3 , & V_13 -> V_182 , V_43 ) ;
}
static void F_79 ( struct V_207 * V_208 , struct V_209 * V_48 )
{
struct V_85 * V_85 = V_208 -> V_210 ;
struct V_10 * V_11 = V_85 -> V_211 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_42 * V_43 = (struct V_42 * ) V_48 ;
F_17 ( ( L_55 , V_48 ) ) ;
F_73 ( V_3 , V_208 , V_43 ) ;
F_70 ( V_3 , V_43 ) ;
}
static void F_80 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
F_81 ( & V_13 -> V_182 . V_221 ) ;
F_82 ( & V_13 -> V_182 . V_204 ) ;
V_13 -> V_182 . V_204 . V_222 = V_223 ;
V_13 -> V_182 . V_204 . V_224 = ( unsigned long ) ( & V_13 -> V_182 ) ;
V_13 -> V_182 . V_3 = V_3 ;
V_13 -> V_147 = & V_3 -> V_106 -> V_176 [ 0 ] ;
V_13 -> V_225 = V_226 ;
V_13 -> V_227 = V_228 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_85 * V_85 )
{
struct V_10 * V_11 = V_85 -> V_211 ;
struct V_1 * V_54 ;
V_11 -> V_79 . V_28 = 384 ;
V_11 -> V_79 . V_29 = 288 ;
V_11 -> V_79 . V_9 = V_229 ;
V_11 -> V_79 . V_116 = 0 ;
V_11 -> V_79 . V_35 = V_158 ;
V_54 = F_1 ( V_3 , V_11 -> V_79 . V_9 ) ;
V_11 -> V_79 . V_164 = ( V_11 -> V_79 . V_28 * V_11 -> V_79 . V_29 * V_54 -> V_72 ) / 8 ;
F_84 ( & V_11 -> V_182 , & V_230 ,
& V_3 -> V_45 -> V_3 , & V_3 -> V_90 ,
V_181 ,
V_159 ,
sizeof( struct V_42 ) ,
V_85 , & V_3 -> V_231 ) ;
return 0 ;
}
static void F_85 ( struct V_2 * V_3 , struct V_85 * V_85 )
{
struct V_10 * V_11 = V_85 -> V_211 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_207 * V_208 = & V_11 -> V_182 ;
int V_18 ;
if ( F_5 ( V_11 ) != 0 ) {
V_18 = F_26 ( V_11 , V_85 ) ;
} else if ( F_6 ( V_11 ) != 0 ) {
V_18 = F_11 ( V_11 ) ;
}
F_86 ( V_208 ) ;
}
static void F_87 ( struct V_2 * V_3 , unsigned long V_232 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_233 * V_208 = & V_13 -> V_182 ;
F_88 ( & V_3 -> V_90 ) ;
F_17 ( ( L_61 ) ) ;
if( NULL != V_208 -> V_234 ) {
F_89 ( V_3 , V_208 , V_235 ) ;
}
F_90 ( V_3 , V_208 , 0 ) ;
F_91 ( & V_3 -> V_90 ) ;
}
static T_4 F_92 ( struct V_85 * V_85 , char T_5 * V_224 , T_6 V_218 , T_7 * V_236 )
{
struct V_10 * V_11 = V_85 -> V_211 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
T_4 V_17 = 0 ;
F_4 ( ( L_61 ) ) ;
if ( ( V_13 -> V_36 & V_77 ) != 0 ) {
if ( V_13 -> V_22 == V_11 ) {
F_22 ( ( L_14 ) ) ;
return - V_21 ;
}
F_22 ( ( L_15 ) ) ;
return - V_21 ;
}
V_17 = F_21 ( V_11 ) ;
if( 0 != V_17 ) {
goto V_237;
}
V_17 = F_93 ( & V_11 -> V_182 , V_224 , V_218 , V_236 ,
V_85 -> V_186 & V_187 ) ;
if ( V_17 != 0 ) {
F_26 ( V_11 , V_85 ) ;
} else {
V_17 = F_26 ( V_11 , V_85 ) ;
}
V_237:
if ( V_13 -> V_78 != NULL ) {
F_3 ( V_13 -> V_78 ) ;
V_13 -> V_78 = NULL ;
}
return V_17 ;
}
