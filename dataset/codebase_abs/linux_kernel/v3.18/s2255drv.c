static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 & V_7 ) ?
V_8 : V_9 ;
}
static int F_4 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 & V_7 ) ?
( V_10 * 2 ) : ( V_11 * 2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 & V_7 ) ?
V_12 : V_13 ;
}
static int F_6 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 & V_7 ) ?
( V_10 ) : ( V_11 ) ;
}
static void F_7 ( const unsigned char * V_14 ,
unsigned char * V_15 ,
int V_16 , int V_17 ,
int V_18 )
{
unsigned char * V_19 ;
unsigned char * V_20 ;
unsigned char * V_21 ;
unsigned long V_22 = V_17 * V_16 ;
unsigned int V_23 ;
V_19 = ( unsigned char * ) V_14 ;
V_21 = ( unsigned char * ) V_14 + V_17 * V_16 ;
V_20 = ( unsigned char * ) V_14 + V_17 * V_16 + ( V_17 * V_16 / 2 ) ;
for ( V_23 = 0 ; V_23 < V_22 * 2 ; V_23 += 4 ) {
V_15 [ V_23 ] = ( V_18 == V_24 ) ? * V_19 ++ : * V_21 ++ ;
V_15 [ V_23 + 1 ] = ( V_18 == V_24 ) ? * V_21 ++ : * V_19 ++ ;
V_15 [ V_23 + 2 ] = ( V_18 == V_24 ) ? * V_19 ++ : * V_20 ++ ;
V_15 [ V_23 + 3 ] = ( V_18 == V_24 ) ? * V_20 ++ : * V_19 ++ ;
}
return;
}
static void F_8 ( struct V_1 * V_25 )
{
F_9 ( V_25 , 0x40 , 0x0000 , 0x0001 , NULL , 0 , 1 ) ;
F_10 ( 20 ) ;
F_9 ( V_25 , 0x50 , 0x0000 , 0x0000 , NULL , 0 , 1 ) ;
F_10 ( 600 ) ;
F_9 ( V_25 , 0x10 , 0x0000 , 0x0000 , NULL , 0 , 1 ) ;
return;
}
static void F_11 ( unsigned long V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_26 ;
if ( F_12 ( V_28 -> V_29 , V_30 ) < 0 ) {
F_13 ( L_1 ) ;
F_14 ( & V_28 -> V_31 , V_32 ) ;
F_15 ( & V_28 -> V_33 ) ;
return;
}
}
static void F_16 ( struct V_34 * V_34 )
{
struct V_27 * V_28 = V_34 -> V_35 ;
struct V_36 * V_37 = V_34 -> V_25 ;
int V_38 ;
if ( V_34 -> V_39 ) {
F_17 ( & V_37 -> V_25 , L_2 , V_34 -> V_39 ) ;
F_14 ( & V_28 -> V_31 , V_32 ) ;
F_15 ( & V_28 -> V_33 ) ;
return;
}
if ( V_28 -> V_29 == NULL ) {
F_18 ( & V_37 -> V_25 , L_3 ) ;
F_14 ( & V_28 -> V_31 , V_32 ) ;
F_15 ( & V_28 -> V_33 ) ;
return;
}
#define F_19 512
if ( V_28 -> V_40 < V_28 -> V_41 ) {
V_38 = ( V_28 -> V_40 + F_19 ) > V_28 -> V_41 ?
V_28 -> V_41 % F_19 : F_19 ;
if ( V_38 < F_19 )
memset ( V_28 -> V_42 , 0 , F_19 ) ;
memcpy ( V_28 -> V_42 ,
( char * ) V_28 -> V_43 -> V_28 + V_28 -> V_40 , V_38 ) ;
F_20 ( V_28 -> V_29 , V_37 , F_21 ( V_37 , 2 ) ,
V_28 -> V_42 , F_19 ,
F_16 , V_28 ) ;
if ( F_12 ( V_28 -> V_29 , V_30 ) < 0 ) {
F_17 ( & V_37 -> V_25 , L_4 ) ;
F_14 ( & V_28 -> V_31 , V_32 ) ;
F_15 ( & V_28 -> V_33 ) ;
return;
}
V_28 -> V_40 += V_38 ;
} else
F_14 ( & V_28 -> V_31 , V_44 ) ;
return;
}
static int F_22 ( struct V_4 * V_5 , int V_45 )
{
struct V_46 * V_47 ;
struct V_1 * V_25 = F_1 ( V_5 -> V_48 . V_3 ) ;
unsigned long V_49 = 0 ;
int V_50 = 0 ;
F_23 ( & V_5 -> V_51 , V_49 ) ;
if ( F_24 ( & V_5 -> V_52 ) ) {
F_25 ( V_25 , 1 , L_5 ) ;
V_50 = - 1 ;
goto V_53;
}
V_47 = F_26 ( V_5 -> V_52 . V_54 ,
struct V_46 , V_55 ) ;
F_27 ( & V_47 -> V_55 ) ;
F_28 ( & V_47 -> V_56 . V_57 . V_58 ) ;
F_29 ( V_5 , V_47 , V_45 ) ;
F_25 ( V_25 , 2 , L_6 , V_59 , V_47 ) ;
V_53:
F_30 ( & V_5 -> V_51 , V_49 ) ;
return V_50 ;
}
static const struct V_60 * F_31 ( int V_61 )
{
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_32 ( V_62 ) ; V_23 ++ ) {
if ( - 1 == V_62 [ V_23 ] . V_61 )
continue;
if ( ! V_63 && ( ( V_62 [ V_23 ] . V_61 == V_64 ) ||
( V_62 [ V_23 ] . V_61 == V_65 ) ) )
continue;
if ( V_62 [ V_23 ] . V_61 == V_61 )
return V_62 + V_23 ;
}
return NULL ;
}
static void F_29 ( struct V_4 * V_5 ,
struct V_46 * V_47 , int V_45 )
{
int V_66 = 0 ;
const char * V_67 ;
char * V_68 = F_33 ( & V_47 -> V_56 , 0 ) ;
unsigned long V_69 ;
struct V_1 * V_25 = V_5 -> V_25 ;
if ( ! V_68 )
return;
V_69 = V_5 -> V_69 ;
if ( V_69 != - 1 ) {
V_67 =
( const char * ) V_5 -> V_70 . V_71 [ V_69 ] . V_72 ;
switch ( V_5 -> V_18 -> V_61 ) {
case V_24 :
case V_73 :
F_7 ( ( const unsigned char * ) V_67 ,
V_68 , V_5 -> V_16 ,
V_5 -> V_17 ,
V_5 -> V_18 -> V_61 ) ;
break;
case V_74 :
memcpy ( V_68 , V_67 , V_5 -> V_16 * V_5 -> V_17 ) ;
break;
case V_64 :
case V_65 :
F_34 ( & V_47 -> V_56 , 0 , V_45 ) ;
memcpy ( V_68 , V_67 , V_45 ) ;
break;
case V_75 :
memcpy ( V_68 , V_67 ,
V_5 -> V_16 * V_5 -> V_17 * 2 ) ;
break;
default:
F_35 ( L_7 ) ;
}
V_5 -> V_69 = - 1 ;
} else {
F_13 ( L_8 ) ;
return;
}
F_25 ( V_25 , 2 , L_9 ,
( unsigned long ) V_68 , V_66 ) ;
V_47 -> V_56 . V_57 . V_76 = V_5 -> V_76 ;
V_47 -> V_56 . V_57 . V_77 = V_5 -> V_78 ;
F_28 ( & V_47 -> V_56 . V_57 . V_58 ) ;
F_36 ( & V_47 -> V_56 , V_79 ) ;
}
static int F_37 ( struct V_80 * V_81 , const struct V_82 * V_18 ,
unsigned int * V_83 , unsigned int * V_84 ,
unsigned int V_85 [] , void * V_86 [] )
{
struct V_4 * V_5 = F_38 ( V_81 ) ;
if ( * V_83 < V_87 )
* V_83 = V_87 ;
* V_84 = 1 ;
V_85 [ 0 ] = V_5 -> V_16 * V_5 -> V_17 * ( V_5 -> V_18 -> V_88 >> 3 ) ;
return 0 ;
}
static int F_39 ( struct V_89 * V_56 )
{
struct V_4 * V_5 = F_38 ( V_56 -> V_80 ) ;
struct V_46 * V_47 = F_2 ( V_56 , struct V_46 , V_56 ) ;
int V_90 = V_5 -> V_16 ;
int V_91 = V_5 -> V_17 ;
unsigned long V_22 ;
F_25 ( V_5 -> V_25 , 4 , L_10 , V_59 ) ;
if ( V_5 -> V_18 == NULL )
return - V_92 ;
if ( ( V_90 < F_5 ( V_5 ) ) ||
( V_90 > F_3 ( V_5 ) ) ||
( V_91 < F_6 ( V_5 ) ) ||
( V_91 > F_4 ( V_5 ) ) ) {
F_25 ( V_5 -> V_25 , 4 , L_11 ) ;
return - V_92 ;
}
V_22 = V_90 * V_91 * ( V_5 -> V_18 -> V_88 >> 3 ) ;
if ( F_40 ( V_56 , 0 ) < V_22 ) {
F_25 ( V_5 -> V_25 , 4 , L_11 ) ;
return - V_92 ;
}
F_34 ( & V_47 -> V_56 , 0 , V_22 ) ;
return 0 ;
}
static void F_41 ( struct V_89 * V_56 )
{
struct V_46 * V_47 = F_2 ( V_56 , struct V_46 , V_56 ) ;
struct V_4 * V_5 = F_38 ( V_56 -> V_80 ) ;
unsigned long V_49 = 0 ;
F_25 ( V_5 -> V_25 , 1 , L_10 , V_59 ) ;
F_23 ( & V_5 -> V_51 , V_49 ) ;
F_42 ( & V_47 -> V_55 , & V_5 -> V_52 ) ;
F_30 ( & V_5 -> V_51 , V_49 ) ;
}
static int F_43 ( struct V_93 * V_93 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
struct V_1 * V_25 = V_5 -> V_25 ;
F_45 ( V_96 -> V_97 , L_12 , sizeof( V_96 -> V_97 ) ) ;
F_45 ( V_96 -> V_98 , L_12 , sizeof( V_96 -> V_98 ) ) ;
F_46 ( V_25 -> V_37 , V_96 -> V_99 , sizeof( V_96 -> V_99 ) ) ;
V_96 -> V_100 = V_101 | V_102 |
V_103 ;
V_96 -> V_104 = V_96 -> V_100 | V_105 ;
return 0 ;
}
static int F_47 ( struct V_93 * V_93 , void * V_94 ,
struct V_106 * V_107 )
{
int V_108 = V_107 -> V_108 ;
if ( V_108 >= F_32 ( V_62 ) )
return - V_92 ;
if ( ! V_63 && ( ( V_62 [ V_108 ] . V_61 == V_64 ) ||
( V_62 [ V_108 ] . V_61 == V_65 ) ) )
return - V_92 ;
F_45 ( V_107 -> V_109 , V_62 [ V_108 ] . V_110 , sizeof( V_107 -> V_109 ) ) ;
V_107 -> V_111 = V_62 [ V_108 ] . V_61 ;
return 0 ;
}
static int F_48 ( struct V_93 * V_93 , void * V_94 ,
struct V_82 * V_107 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
int V_112 = V_5 -> V_6 & V_7 ;
V_107 -> V_18 . V_113 . V_16 = V_5 -> V_16 ;
V_107 -> V_18 . V_113 . V_17 = V_5 -> V_17 ;
if ( V_107 -> V_18 . V_113 . V_17 >=
( V_112 ? V_10 : V_11 ) * 2 )
V_107 -> V_18 . V_113 . V_76 = V_114 ;
else
V_107 -> V_18 . V_113 . V_76 = V_115 ;
V_107 -> V_18 . V_113 . V_111 = V_5 -> V_18 -> V_61 ;
V_107 -> V_18 . V_113 . V_116 = V_107 -> V_18 . V_113 . V_16 * ( V_5 -> V_18 -> V_88 >> 3 ) ;
V_107 -> V_18 . V_113 . V_117 = V_107 -> V_18 . V_113 . V_17 * V_107 -> V_18 . V_113 . V_116 ;
V_107 -> V_18 . V_113 . V_118 = V_119 ;
V_107 -> V_18 . V_113 . V_94 = 0 ;
return 0 ;
}
static int F_49 ( struct V_93 * V_93 , void * V_94 ,
struct V_82 * V_107 )
{
const struct V_60 * V_18 ;
enum V_120 V_76 ;
struct V_4 * V_5 = F_44 ( V_93 ) ;
int V_112 = V_5 -> V_6 & V_7 ;
V_18 = F_31 ( V_107 -> V_18 . V_113 . V_111 ) ;
if ( V_18 == NULL )
return - V_92 ;
V_76 = V_107 -> V_18 . V_113 . V_76 ;
F_25 ( V_5 -> V_25 , 50 , L_13 ,
V_59 , V_112 , V_107 -> V_18 . V_113 . V_16 , V_107 -> V_18 . V_113 . V_17 ) ;
if ( V_112 ) {
if ( V_107 -> V_18 . V_113 . V_17 >= V_10 * 2 ) {
V_107 -> V_18 . V_113 . V_17 = V_10 * 2 ;
V_76 = V_114 ;
} else {
V_107 -> V_18 . V_113 . V_17 = V_10 ;
V_76 = V_115 ;
}
if ( V_107 -> V_18 . V_113 . V_16 >= V_8 )
V_107 -> V_18 . V_113 . V_16 = V_8 ;
else if ( V_107 -> V_18 . V_113 . V_16 >= V_121 )
V_107 -> V_18 . V_113 . V_16 = V_121 ;
else if ( V_107 -> V_18 . V_113 . V_16 >= V_12 )
V_107 -> V_18 . V_113 . V_16 = V_12 ;
else
V_107 -> V_18 . V_113 . V_16 = V_12 ;
} else {
if ( V_107 -> V_18 . V_113 . V_17 >= V_11 * 2 ) {
V_107 -> V_18 . V_113 . V_17 = V_11 * 2 ;
V_76 = V_114 ;
} else {
V_107 -> V_18 . V_113 . V_17 = V_11 ;
V_76 = V_115 ;
}
if ( V_107 -> V_18 . V_113 . V_16 >= V_9 )
V_107 -> V_18 . V_113 . V_16 = V_9 ;
else if ( V_107 -> V_18 . V_113 . V_16 >= V_122 )
V_107 -> V_18 . V_113 . V_16 = V_122 ;
else if ( V_107 -> V_18 . V_113 . V_16 >= V_13 )
V_107 -> V_18 . V_113 . V_16 = V_13 ;
else
V_107 -> V_18 . V_113 . V_16 = V_13 ;
}
V_107 -> V_18 . V_113 . V_76 = V_76 ;
V_107 -> V_18 . V_113 . V_116 = ( V_107 -> V_18 . V_113 . V_16 * V_18 -> V_88 ) >> 3 ;
V_107 -> V_18 . V_113 . V_117 = V_107 -> V_18 . V_113 . V_17 * V_107 -> V_18 . V_113 . V_116 ;
V_107 -> V_18 . V_113 . V_118 = V_119 ;
V_107 -> V_18 . V_113 . V_94 = 0 ;
F_25 ( V_5 -> V_25 , 50 , L_14 , V_59 ,
V_107 -> V_18 . V_113 . V_16 , V_107 -> V_18 . V_113 . V_17 , V_107 -> V_18 . V_113 . V_76 ) ;
return 0 ;
}
static int F_50 ( struct V_93 * V_93 , void * V_94 ,
struct V_82 * V_107 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
const struct V_60 * V_18 ;
struct V_80 * V_123 = & V_5 -> V_124 ;
struct V_125 V_126 ;
int V_127 ;
V_127 = F_49 ( V_93 , V_5 , V_107 ) ;
if ( V_127 < 0 )
return V_127 ;
V_18 = F_31 ( V_107 -> V_18 . V_113 . V_111 ) ;
if ( V_18 == NULL )
return - V_92 ;
if ( F_51 ( V_123 ) ) {
F_25 ( V_5 -> V_25 , 1 , L_15 ) ;
return - V_128 ;
}
V_126 = V_5 -> V_126 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_16 = V_107 -> V_18 . V_113 . V_16 ;
V_5 -> V_17 = V_107 -> V_18 . V_113 . V_17 ;
V_5 -> V_76 = V_107 -> V_18 . V_113 . V_76 ;
if ( V_5 -> V_16 > F_5 ( V_5 ) ) {
if ( V_5 -> V_17 > F_6 ( V_5 ) ) {
if ( V_5 -> V_129 . V_130 &
V_131 )
V_126 . V_132 = V_133 ;
else
V_126 . V_132 = V_134 ;
} else
V_126 . V_132 = V_135 ;
} else {
V_126 . V_132 = V_136 ;
}
switch ( V_5 -> V_18 -> V_61 ) {
case V_74 :
V_126 . V_137 &= ~ V_138 ;
V_126 . V_137 |= V_139 ;
break;
case V_64 :
case V_65 :
V_126 . V_137 &= ~ V_138 ;
V_126 . V_137 |= V_140 ;
V_126 . V_137 |= ( V_5 -> V_141 << 8 ) ;
break;
case V_75 :
V_126 . V_137 &= ~ V_138 ;
V_126 . V_137 |= V_142 ;
break;
case V_24 :
case V_73 :
default:
V_126 . V_137 &= ~ V_138 ;
V_126 . V_137 |= V_143 ;
break;
}
if ( ( V_126 . V_137 & V_138 ) != ( V_5 -> V_126 . V_137 & V_138 ) )
V_126 . V_144 = 1 ;
else if ( V_126 . V_132 != V_5 -> V_126 . V_132 )
V_126 . V_144 = 1 ;
else if ( V_126 . V_145 != V_5 -> V_126 . V_145 )
V_126 . V_144 = 1 ;
V_5 -> V_126 = V_126 ;
( void ) F_52 ( V_5 , & V_126 ) ;
return 0 ;
}
static int F_53 ( struct V_36 * V_37 , unsigned char * V_146 ,
int V_22 )
{
int V_147 ;
int V_148 ;
long V_149 = - 1 ;
if ( V_37 ) {
V_147 = F_21 ( V_37 , V_150 ) ;
V_149 = F_54 ( V_37 , V_147 , V_146 , V_22 , & V_148 , 500 ) ;
}
return V_149 ;
}
static T_1 F_55 ( struct V_125 * V_126 )
{
int V_151 = V_152 ;
int V_153 = V_154 ;
T_1 V_155 ;
T_1 V_156 ;
unsigned int V_157 ;
if ( V_126 == NULL )
return 0 ;
if ( V_126 -> V_145 == V_158 ) {
switch ( V_126 -> V_132 ) {
case V_134 :
case V_133 :
V_151 = V_159 * 2 ;
V_153 = V_8 ;
break;
case V_135 :
V_151 = V_160 ;
V_153 = V_121 ;
break;
case V_136 :
V_151 = V_10 ;
V_153 = V_12 ;
break;
default:
break;
}
} else if ( V_126 -> V_145 == V_161 ) {
switch ( V_126 -> V_132 ) {
case V_134 :
case V_133 :
V_151 = V_162 * 2 ;
V_153 = V_9 ;
break;
case V_135 :
V_151 = V_163 ;
V_153 = V_122 ;
break;
case V_136 :
V_151 = V_11 ;
V_153 = V_13 ;
break;
default:
break;
}
}
V_155 = V_151 * V_153 ;
if ( ( V_126 -> V_137 & V_138 ) != V_139 ) {
V_155 *= 2 ;
}
V_156 = V_155 + V_164 ;
V_157 = 0xffffffffUL - V_165 + 1 ;
if ( V_156 & ~ V_157 )
V_156 = ( V_156 & V_157 ) + ( V_165 ) ;
return V_156 ;
}
static void F_56 ( struct V_1 * V_166 , struct V_125 * V_126 )
{
struct V_167 * V_25 = & V_166 -> V_37 -> V_25 ;
F_57 ( V_25 , L_16 ) ;
F_57 ( V_25 , L_17 , V_126 -> V_145 , V_126 -> V_132 ) ;
F_57 ( V_25 , L_18 , V_126 -> V_168 , V_126 -> V_137 ) ;
F_57 ( V_25 , L_19 , V_126 -> V_169 ) ;
F_57 ( V_25 , L_16 ) ;
}
static int F_52 ( struct V_4 * V_5 ,
struct V_125 * V_126 )
{
int V_170 ;
unsigned long V_171 ;
struct V_1 * V_25 = F_1 ( V_5 -> V_48 . V_3 ) ;
int V_23 ;
T_2 * V_70 = V_25 -> V_172 ;
F_58 ( & V_25 -> V_173 ) ;
V_171 = V_174 [ V_5 -> V_175 ] ;
F_25 ( V_25 , 3 , L_20 , V_59 , V_5 -> V_175 ) ;
if ( ( V_126 -> V_137 & V_138 ) == V_140 ) {
V_126 -> V_137 &= ~ V_138 ;
V_126 -> V_137 |= V_140 ;
V_126 -> V_137 &= ~ V_176 ;
V_126 -> V_137 |= ( V_5 -> V_141 << 8 ) ;
}
V_5 -> V_126 = * V_126 ;
V_5 -> V_177 = F_55 ( V_126 ) ;
F_25 ( V_25 , 1 , L_21 , V_59 , V_5 -> V_177 ) ;
V_70 [ 0 ] = V_178 ;
V_70 [ 1 ] = ( T_2 ) F_59 ( V_171 ) ;
V_70 [ 2 ] = V_179 ;
for ( V_23 = 0 ; V_23 < sizeof( struct V_125 ) / sizeof( T_1 ) ; V_23 ++ )
V_70 [ 3 + V_23 ] = F_59 ( ( ( T_1 * ) & V_5 -> V_126 ) [ V_23 ] ) ;
V_5 -> V_180 = 0 ;
V_170 = F_53 ( V_25 -> V_37 , ( unsigned char * ) V_70 , 512 ) ;
if ( V_181 )
F_56 ( V_25 , V_126 ) ;
if ( V_126 -> V_144 ) {
F_60 ( V_5 -> V_182 ,
( V_5 -> V_180 != 0 ) ,
F_61 ( V_183 ) ) ;
if ( V_5 -> V_180 != 1 ) {
F_25 ( V_25 , 0 , L_22 ) ;
V_170 = - V_184 ;
}
}
V_5 -> V_126 . V_144 = 0 ;
F_25 ( V_25 , 1 , L_23 , V_59 , V_5 -> V_175 , V_170 ) ;
F_62 ( & V_25 -> V_173 ) ;
return V_170 ;
}
static int F_63 ( struct V_4 * V_5 , T_1 * V_185 )
{
int V_170 ;
T_1 V_171 ;
struct V_1 * V_25 = F_1 ( V_5 -> V_48 . V_3 ) ;
T_2 * V_70 = V_25 -> V_172 ;
F_58 ( & V_25 -> V_173 ) ;
V_171 = V_174 [ V_5 -> V_175 ] ;
F_25 ( V_25 , 4 , L_24 , V_59 , V_5 -> V_175 ) ;
V_70 [ 0 ] = V_178 ;
V_70 [ 1 ] = ( T_2 ) F_59 ( V_171 ) ;
V_70 [ 2 ] = V_186 ;
* V_185 = 0 ;
V_5 -> V_187 = 0 ;
V_170 = F_53 ( V_25 -> V_37 , ( unsigned char * ) V_70 , 512 ) ;
F_60 ( V_5 -> V_188 ,
( V_5 -> V_187 != 0 ) ,
F_61 ( V_189 ) ) ;
if ( V_5 -> V_187 != 1 ) {
F_25 ( V_25 , 0 , L_25 ) ;
V_170 = - V_184 ;
}
* V_185 = V_5 -> V_190 ;
F_25 ( V_25 , 4 , L_26 , V_59 , * V_185 ) ;
F_62 ( & V_25 -> V_173 ) ;
return V_170 ;
}
static int F_64 ( struct V_80 * V_81 , unsigned int V_191 )
{
struct V_4 * V_5 = F_38 ( V_81 ) ;
int V_192 ;
V_5 -> V_69 = - 1 ;
V_5 -> V_193 = 0 ;
V_5 -> V_194 = 0 ;
V_5 -> V_78 = 0 ;
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
V_5 -> V_70 . V_71 [ V_192 ] . V_196 = V_197 ;
V_5 -> V_70 . V_71 [ V_192 ] . V_198 = 0 ;
}
return F_65 ( V_5 ) ;
}
static void F_66 ( struct V_80 * V_81 )
{
struct V_4 * V_5 = F_38 ( V_81 ) ;
struct V_46 * V_47 , * V_199 ;
unsigned long V_49 ;
( void ) F_67 ( V_5 ) ;
F_23 ( & V_5 -> V_51 , V_49 ) ;
F_68 (buf, node, &vc->buf_list, list) {
F_27 ( & V_47 -> V_55 ) ;
F_36 ( & V_47 -> V_56 , V_200 ) ;
F_25 ( V_5 -> V_25 , 2 , L_27 ,
V_47 , V_47 -> V_56 . V_57 . V_108 ) ;
}
F_30 ( & V_5 -> V_51 , V_49 ) ;
}
static int F_69 ( struct V_93 * V_93 , void * V_94 , T_3 V_23 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
struct V_125 V_126 ;
struct V_80 * V_123 = & V_5 -> V_124 ;
if ( F_51 ( V_123 ) )
return - V_128 ;
V_126 = V_5 -> V_126 ;
if ( V_23 & V_7 ) {
F_25 ( V_5 -> V_25 , 4 , L_28 , V_59 ) ;
if ( V_126 . V_145 != V_158 ) {
V_126 . V_144 = 1 ;
V_126 . V_145 = V_158 ;
V_126 . V_168 = V_201 ;
V_5 -> V_16 = V_8 ;
V_5 -> V_17 = V_159 * 2 ;
}
} else if ( V_23 & V_202 ) {
F_25 ( V_5 -> V_25 , 4 , L_29 , V_59 ) ;
if ( V_126 . V_145 != V_161 ) {
V_126 . V_144 = 1 ;
V_126 . V_145 = V_161 ;
V_126 . V_168 = V_201 ;
V_5 -> V_16 = V_9 ;
V_5 -> V_17 = V_162 * 2 ;
}
} else
return - V_92 ;
V_5 -> V_6 = V_23 ;
if ( V_126 . V_144 )
F_52 ( V_5 , & V_126 ) ;
return 0 ;
}
static int F_70 ( struct V_93 * V_93 , void * V_94 , T_3 * V_23 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
* V_23 = V_5 -> V_6 ;
return 0 ;
}
static int F_71 ( struct V_93 * V_93 , void * V_94 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
struct V_1 * V_25 = V_5 -> V_25 ;
T_1 V_39 = 0 ;
if ( V_204 -> V_108 != 0 )
return - V_92 ;
V_204 -> type = V_205 ;
V_204 -> V_6 = V_206 ;
V_204 -> V_39 = 0 ;
if ( V_25 -> V_207 >= V_208 ) {
int V_50 ;
V_50 = F_63 ( V_5 , & V_39 ) ;
F_25 ( V_25 , 4 , L_30 ,
V_50 , V_39 ) ;
if ( V_50 == 0 )
V_204 -> V_39 = ( V_39 & 0x01 ) ? 0
: V_209 ;
}
switch ( V_25 -> V_210 ) {
case 0x2255 :
default:
F_45 ( V_204 -> V_110 , L_31 , sizeof( V_204 -> V_110 ) ) ;
break;
case 0x2257 :
F_45 ( V_204 -> V_110 , ( V_5 -> V_175 < 2 ) ? L_31 : L_32 ,
sizeof( V_204 -> V_110 ) ) ;
break;
}
return 0 ;
}
static int F_72 ( struct V_93 * V_93 , void * V_94 , unsigned int * V_23 )
{
* V_23 = 0 ;
return 0 ;
}
static int F_73 ( struct V_93 * V_93 , void * V_94 , unsigned int V_23 )
{
if ( V_23 > 0 )
return - V_92 ;
return 0 ;
}
static int F_74 ( struct V_211 * V_212 )
{
struct V_4 * V_5 =
F_2 ( V_212 -> V_213 , struct V_4 , V_214 ) ;
struct V_125 V_126 ;
V_126 = V_5 -> V_126 ;
switch ( V_212 -> V_215 ) {
case V_216 :
V_126 . V_169 = V_212 -> V_217 ;
break;
case V_218 :
V_126 . V_219 = V_212 -> V_217 ;
break;
case V_220 :
V_126 . V_221 = V_212 -> V_217 ;
break;
case V_222 :
V_126 . V_223 = V_212 -> V_217 ;
break;
case V_224 :
V_126 . V_137 &= ~ V_225 ;
V_126 . V_137 |= ! V_212 -> V_217 << 16 ;
break;
case V_226 :
V_5 -> V_141 = V_212 -> V_217 ;
return 0 ;
default:
return - V_92 ;
}
V_126 . V_144 = 0 ;
F_52 ( V_5 , & V_126 ) ;
return 0 ;
}
static int F_75 ( struct V_93 * V_93 , void * V_94 ,
struct V_227 * V_228 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_229 = V_5 -> V_141 ;
F_25 ( V_5 -> V_25 , 2 , L_33 , V_59 , V_228 -> V_229 ) ;
return 0 ;
}
static int F_76 ( struct V_93 * V_93 , void * V_94 ,
const struct V_227 * V_228 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
if ( V_228 -> V_229 < 0 || V_228 -> V_229 > 100 )
return - V_92 ;
F_77 ( V_5 -> V_230 , V_228 -> V_229 ) ;
F_25 ( V_5 -> V_25 , 2 , L_33 , V_59 , V_228 -> V_229 ) ;
return 0 ;
}
static int F_78 ( struct V_93 * V_93 , void * V_94 ,
struct V_231 * V_232 )
{
T_4 V_233 , V_234 ;
struct V_4 * V_5 = F_44 ( V_93 ) ;
if ( V_232 -> type != V_235 )
return - V_92 ;
V_232 -> V_236 . V_237 . V_238 = V_239 ;
V_232 -> V_236 . V_237 . V_130 = V_5 -> V_129 . V_130 ;
V_232 -> V_236 . V_237 . V_240 = V_87 ;
V_233 = ( V_5 -> V_126 . V_145 == V_158 ) ? 1001 : 1000 ;
V_234 = ( V_5 -> V_126 . V_145 == V_158 ) ? 30000 : 25000 ;
V_232 -> V_236 . V_237 . V_241 . V_242 = V_234 ;
switch ( V_5 -> V_126 . V_168 ) {
default:
case V_201 :
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 ;
break;
case V_244 :
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 * 2 ;
break;
case V_245 :
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 * 3 ;
break;
case V_246 :
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 * 5 ;
break;
}
F_25 ( V_5 -> V_25 , 4 , L_34 ,
V_59 ,
V_232 -> V_236 . V_237 . V_130 ,
V_232 -> V_236 . V_237 . V_241 . V_243 ,
V_232 -> V_236 . V_237 . V_241 . V_242 ) ;
return 0 ;
}
static int F_79 ( struct V_93 * V_93 , void * V_94 ,
struct V_231 * V_232 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
struct V_125 V_126 ;
int V_168 = V_201 ;
T_4 V_233 , V_234 ;
if ( V_232 -> type != V_235 )
return - V_92 ;
V_126 = V_5 -> V_126 ;
if ( ( V_5 -> V_129 . V_130 != V_232 -> V_236 . V_237 . V_130 )
&& F_80 ( & V_5 -> V_124 ) )
return - V_128 ;
V_233 = ( V_126 . V_145 == V_158 ) ? 1001 : 1000 ;
V_234 = ( V_126 . V_145 == V_158 ) ? 30000 : 25000 ;
if ( V_234 != V_232 -> V_236 . V_237 . V_241 . V_242 )
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 ;
else if ( V_232 -> V_236 . V_237 . V_241 . V_243 <= V_233 )
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 ;
else if ( V_232 -> V_236 . V_237 . V_241 . V_243 <= ( V_233 * 2 ) ) {
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 * 2 ;
V_168 = V_244 ;
} else if ( V_232 -> V_236 . V_237 . V_241 . V_243 <= ( V_233 * 3 ) ) {
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 * 3 ;
V_168 = V_245 ;
} else {
V_232 -> V_236 . V_237 . V_241 . V_243 = V_233 * 5 ;
V_168 = V_246 ;
}
V_126 . V_168 = V_168 ;
V_232 -> V_236 . V_237 . V_241 . V_242 = V_234 ;
V_232 -> V_236 . V_237 . V_240 = V_87 ;
F_52 ( V_5 , & V_126 ) ;
F_25 ( V_5 -> V_25 , 4 , L_35 ,
V_59 ,
V_232 -> V_236 . V_237 . V_130 ,
V_232 -> V_236 . V_237 . V_241 . V_243 ,
V_232 -> V_236 . V_237 . V_241 . V_242 , V_168 ) ;
return 0 ;
}
static int F_81 ( struct V_93 * V_93 , void * V_94 ,
struct V_247 * V_248 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
int V_112 = V_5 -> V_6 & V_7 ;
const struct V_60 * V_18 ;
if ( V_248 -> V_108 >= V_249 )
return - V_92 ;
V_18 = F_31 ( V_248 -> V_250 ) ;
if ( V_18 == NULL )
return - V_92 ;
V_248 -> type = V_251 ;
V_248 -> V_252 = V_112 ? V_253 [ V_248 -> V_108 ] : V_254 [ V_248 -> V_108 ] ;
return 0 ;
}
static int F_82 ( struct V_93 * V_93 , void * V_94 ,
struct V_255 * V_248 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
const struct V_60 * V_18 ;
const struct V_256 * V_85 ;
int V_112 = V_5 -> V_6 & V_7 ;
#define F_83 4
int V_257 [ F_83 ] = { 1 , 2 , 3 , 5 } ;
int V_23 ;
if ( V_248 -> V_108 >= F_83 )
return - V_92 ;
V_18 = F_31 ( V_248 -> V_250 ) ;
if ( V_18 == NULL )
return - V_92 ;
V_85 = V_112 ? V_253 : V_254 ;
for ( V_23 = 0 ; V_23 < V_249 ; V_23 ++ , V_85 ++ )
if ( V_248 -> V_16 == V_85 -> V_16 &&
V_248 -> V_17 == V_85 -> V_17 )
break;
if ( V_23 == V_249 )
return - V_92 ;
V_248 -> type = V_258 ;
V_248 -> V_252 . V_242 = V_112 ? 30000 : 25000 ;
V_248 -> V_252 . V_243 = ( V_112 ? 1001 : 1000 ) * V_257 [ V_248 -> V_108 ] ;
F_25 ( V_5 -> V_25 , 4 , L_36 , V_59 ,
V_248 -> V_252 . V_243 ,
V_248 -> V_252 . V_242 ) ;
return 0 ;
}
static int F_84 ( struct V_93 * V_93 )
{
struct V_4 * V_5 = F_44 ( V_93 ) ;
struct V_1 * V_25 = V_5 -> V_25 ;
int V_259 ;
int V_50 = 0 ;
V_50 = F_85 ( V_93 ) ;
if ( V_50 != 0 )
return V_50 ;
F_25 ( V_25 , 1 , L_37 , V_59 ) ;
V_259 = F_86 ( & V_25 -> V_260 -> V_31 ) ;
switch ( V_259 ) {
case V_261 :
return - V_262 ;
case V_32 :
F_18 ( & V_25 -> V_37 -> V_25 ,
L_38 ) ;
F_87 ( V_25 , 1 ) ;
F_60 ( V_25 -> V_260 -> V_33 ,
( ( F_86 ( & V_25 -> V_260 -> V_31 )
== V_263 ) ||
( F_86 ( & V_25 -> V_260 -> V_31 )
== V_261 ) ) ,
F_61 ( V_264 ) ) ;
V_259 = F_86 ( & V_25 -> V_260 -> V_31 ) ;
break;
case V_265 :
case V_44 :
F_35 ( L_39 , V_59 ) ;
F_60 ( V_25 -> V_260 -> V_33 ,
( ( F_86 ( & V_25 -> V_260 -> V_31 )
== V_263 ) ||
( F_86 ( & V_25 -> V_260 -> V_31 )
== V_261 ) ) ,
F_61 ( V_264 ) ) ;
V_259 = F_86 ( & V_25 -> V_260 -> V_31 ) ;
break;
case V_263 :
default:
break;
}
switch ( V_259 ) {
case V_263 :
break;
case V_32 :
F_35 ( L_40 ) ;
return - V_262 ;
case V_261 :
F_35 ( L_41 , V_59 ) ;
return - V_262 ;
case V_44 :
case V_265 :
F_35 ( L_42 ,
V_59 ) ;
F_14 ( & V_25 -> V_260 -> V_31 ,
V_32 ) ;
return - V_266 ;
default:
F_35 ( L_43 , V_59 ) ;
return - V_184 ;
}
if ( ! V_5 -> V_267 ) {
V_5 -> V_18 = & V_62 [ 0 ] ;
F_52 ( V_5 , & V_5 -> V_126 ) ;
V_5 -> V_267 = 1 ;
}
return 0 ;
}
static void F_88 ( struct V_1 * V_25 )
{
F_25 ( V_25 , 1 , L_44 , V_59 ) ;
F_89 ( V_25 ) ;
F_90 ( & V_25 -> V_268 ) ;
if ( V_25 -> V_260 -> V_29 ) {
F_91 ( V_25 -> V_260 -> V_29 ) ;
F_92 ( V_25 -> V_260 -> V_29 ) ;
V_25 -> V_260 -> V_29 = NULL ;
}
F_93 ( V_25 -> V_260 -> V_43 ) ;
F_94 ( V_25 -> V_260 -> V_42 ) ;
F_94 ( V_25 -> V_260 ) ;
F_8 ( V_25 ) ;
F_95 ( & V_25 -> V_269 ) ;
F_96 ( V_25 -> V_37 ) ;
F_97 ( & V_25 -> V_3 ) ;
F_94 ( V_25 -> V_172 ) ;
F_94 ( V_25 ) ;
}
static void F_98 ( struct V_270 * V_48 )
{
struct V_1 * V_25 = F_1 ( V_48 -> V_3 ) ;
struct V_4 * V_5 =
F_2 ( V_48 , struct V_4 , V_48 ) ;
F_25 ( V_25 , 4 , L_45 , V_59 ,
F_86 ( & V_25 -> V_271 ) ) ;
F_99 ( & V_5 -> V_214 ) ;
if ( F_100 ( & V_25 -> V_271 ) )
F_88 ( V_25 ) ;
return;
}
static int F_101 ( struct V_1 * V_25 )
{
int V_127 ;
int V_23 ;
int V_272 = V_273 ;
struct V_4 * V_5 ;
struct V_80 * V_123 ;
V_127 = F_102 ( & V_25 -> V_274 -> V_25 , & V_25 -> V_3 ) ;
if ( V_127 )
return V_127 ;
for ( V_23 = 0 ; V_23 < V_275 ; V_23 ++ ) {
V_5 = & V_25 -> V_5 [ V_23 ] ;
F_103 ( & V_5 -> V_52 ) ;
F_104 ( & V_5 -> V_214 , 6 ) ;
F_105 ( & V_5 -> V_214 , & V_276 ,
V_216 , - 127 , 127 , 1 , V_277 ) ;
F_105 ( & V_5 -> V_214 , & V_276 ,
V_218 , 0 , 255 , 1 , V_278 ) ;
F_105 ( & V_5 -> V_214 , & V_276 ,
V_222 , 0 , 255 , 1 , V_279 ) ;
F_105 ( & V_5 -> V_214 , & V_276 ,
V_220 , 0 , 255 , 1 , V_280 ) ;
V_5 -> V_230 = F_105 ( & V_5 -> V_214 ,
& V_276 ,
V_226 ,
0 , 100 , 1 , V_281 ) ;
if ( V_25 -> V_207 >= V_282 &&
( V_25 -> V_210 != 0x2257 || V_5 -> V_175 <= 1 ) )
F_106 ( & V_5 -> V_214 , & V_283 ,
NULL ) ;
if ( V_5 -> V_214 . error ) {
V_127 = V_5 -> V_214 . error ;
F_99 ( & V_5 -> V_214 ) ;
F_17 ( & V_25 -> V_37 -> V_25 , L_46 ) ;
break;
}
V_123 = & V_5 -> V_124 ;
V_123 -> type = V_235 ;
V_123 -> V_284 = V_285 | V_286 | V_287 ;
V_123 -> V_288 = V_5 ;
V_123 -> V_269 = & V_5 -> V_289 ;
V_123 -> V_290 = sizeof( struct V_46 ) ;
V_123 -> V_291 = & V_292 ;
V_123 -> V_293 = & V_294 ;
V_123 -> V_295 = V_296 ;
V_127 = F_107 ( V_123 ) ;
if ( V_127 != 0 ) {
F_17 ( & V_25 -> V_37 -> V_25 ,
L_47 , V_59 , V_127 ) ;
break;
}
V_5 -> V_48 = V_297 ;
V_5 -> V_48 . V_298 = V_123 ;
V_5 -> V_48 . V_299 = & V_5 -> V_214 ;
V_5 -> V_48 . V_269 = & V_25 -> V_269 ;
V_5 -> V_48 . V_3 = & V_25 -> V_3 ;
F_108 ( & V_5 -> V_48 , V_5 ) ;
if ( V_273 == - 1 )
V_127 = F_109 ( & V_5 -> V_48 ,
V_300 ,
V_273 ) ;
else
V_127 = F_109 ( & V_5 -> V_48 ,
V_300 ,
V_272 + V_23 ) ;
if ( V_127 ) {
F_17 ( & V_25 -> V_37 -> V_25 ,
L_48 ) ;
break;
}
F_110 ( & V_25 -> V_271 ) ;
F_111 ( & V_25 -> V_3 , L_49 ,
F_112 ( & V_5 -> V_48 ) ) ;
}
F_35 ( L_50 ,
V_301 ) ;
if ( F_86 ( & V_25 -> V_271 ) == 0 ) {
F_97 ( & V_25 -> V_3 ) ;
return V_127 ;
}
if ( F_86 ( & V_25 -> V_271 ) != V_275 )
F_113 ( L_51 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_25 , struct V_302 * V_303 )
{
char * V_304 ;
T_1 V_305 = 0 ;
int V_306 = 0 ;
char * V_307 ;
unsigned long V_308 ;
unsigned long V_22 ;
T_5 V_175 = - 1 ;
struct V_309 * V_310 ;
unsigned char * V_311 ;
struct V_4 * V_5 ;
F_25 ( V_25 , 100 , L_52 ) ;
V_5 = & V_25 -> V_5 [ V_25 -> V_312 ] ;
V_175 = V_5 -> V_194 ;
V_310 = & V_5 -> V_70 . V_71 [ V_175 ] ;
if ( V_310 -> V_196 == V_197 ) {
int V_313 ;
unsigned int V_312 ;
T_2 * V_314 ;
int V_315 ;
V_311 = ( unsigned char * ) V_303 -> V_316 ;
V_314 = ( T_2 * ) V_311 ;
for ( V_313 = 0 ; V_313 < ( V_303 -> V_317 - 12 ) ; V_313 ++ ) {
switch ( * V_314 ) {
case V_318 :
F_25 ( V_25 , 4 , L_53 ,
V_313 , V_311 [ 0 ] , V_311 [ 1 ] ) ;
V_305 = V_313 + V_164 ;
V_306 = 1 ;
V_312 = F_115 ( V_314 [ 1 ] ) ;
if ( V_312 >= V_275 ) {
F_25 ( V_25 , 0 ,
L_54 ) ;
return - V_92 ;
}
V_25 -> V_312 = V_174 [ V_312 ] ;
V_5 = & V_25 -> V_5 [ V_25 -> V_312 ] ;
V_315 = F_115 ( V_314 [ 3 ] ) ;
if ( V_315 > V_5 -> V_177 ) {
V_5 -> V_193 ++ ;
return - V_92 ;
}
V_5 -> V_319 = V_315 ;
V_5 -> V_320 = F_115 ( V_314 [ 4 ] ) ;
break;
case V_321 :
V_311 += V_165 ;
V_313 += V_165 ;
if ( F_115 ( V_314 [ 1 ] ) >= V_275 )
break;
V_312 = V_174 [ F_115 ( V_314 [ 1 ] ) ] ;
if ( V_312 >= V_275 )
break;
V_5 = & V_25 -> V_5 [ V_312 ] ;
switch ( V_314 [ 2 ] ) {
case V_322 :
V_5 -> V_180 = 1 ;
F_15 ( & V_5 -> V_182 ) ;
F_25 ( V_25 , 5 , L_55 , V_312 ) ;
break;
case V_323 :
V_25 -> V_324 |= ( 1 << V_312 ) ;
if ( ( V_25 -> V_324 & 0x0f ) != 0x0f )
break;
F_35 ( L_56 ) ;
F_14 ( & V_25 -> V_260 -> V_31 ,
V_263 ) ;
F_15 ( & V_25 -> V_260 -> V_33 ) ;
break;
case V_325 :
V_5 -> V_190 = F_115 ( V_314 [ 3 ] ) ;
V_5 -> V_187 = 1 ;
F_15 ( & V_5 -> V_188 ) ;
F_25 ( V_25 , 5 , L_57 ,
F_115 ( V_314 [ 3 ] ) , V_312 ) ;
break;
default:
F_35 ( L_58 ) ;
}
default:
V_311 ++ ;
break;
}
if ( V_306 )
break;
}
if ( ! V_306 )
return - V_92 ;
}
V_5 = & V_25 -> V_5 [ V_25 -> V_312 ] ;
V_175 = V_5 -> V_194 ;
V_310 = & V_5 -> V_70 . V_71 [ V_175 ] ;
if ( ! F_80 ( & V_5 -> V_124 ) ) {
V_310 -> V_196 = V_197 ;
return - V_92 ;
}
if ( V_310 -> V_196 == V_197 ) {
V_310 -> V_196 = V_326 ;
V_310 -> V_198 = 0 ;
}
V_307 = ( V_327 * ) V_303 -> V_316 + V_305 ;
if ( V_310 -> V_72 == NULL ) {
F_25 ( V_25 , 1 , L_59 ,
V_310 , V_25 , V_25 -> V_312 , V_175 ) ;
return - V_328 ;
}
V_304 = V_310 -> V_72 + V_310 -> V_198 ;
V_308 = ( V_303 -> V_317 - V_305 ) ;
V_22 = V_5 -> V_319 - V_164 ;
if ( ( V_308 + V_310 -> V_198 ) < V_5 -> V_177 )
memcpy ( V_304 , V_307 , V_308 ) ;
V_310 -> V_198 += V_308 ;
F_25 ( V_25 , 4 , L_60 , V_310 -> V_198 , V_22 ) ;
if ( V_310 -> V_198 >= V_22 ) {
F_25 ( V_25 , 2 , L_61 ,
V_25 -> V_312 , V_175 ) ;
V_5 -> V_69 = V_5 -> V_194 ;
V_5 -> V_194 ++ ;
if ( ( V_5 -> V_194 == V_195 ) ||
( V_5 -> V_194 == V_5 -> V_70 . V_329 ) )
V_5 -> V_194 = 0 ;
if ( F_80 ( & V_5 -> V_124 ) )
F_22 ( V_5 , V_5 -> V_320 ) ;
V_5 -> V_78 ++ ;
V_310 -> V_196 = V_197 ;
V_310 -> V_198 = 0 ;
}
return 0 ;
}
static void F_116 ( struct V_1 * V_25 ,
struct V_302 * V_303 )
{
int V_170 ;
F_25 ( V_25 , 50 , L_62 ) ;
if ( V_25 -> V_312 >= V_275 ) {
V_25 -> V_312 = 0 ;
F_17 ( & V_25 -> V_37 -> V_25 , L_63 ) ;
return;
}
V_170 = F_114 ( V_25 , V_303 ) ;
if ( V_170 != 0 )
F_25 ( V_25 , 4 , L_64 ) ;
F_25 ( V_25 , 50 , L_65 ) ;
return;
}
static long F_9 ( struct V_1 * V_25 , unsigned char V_330 ,
T_6 V_331 , T_6 V_332 , void * V_333 ,
T_5 V_334 , int V_335 )
{
int V_336 ;
if ( ! V_335 ) {
V_336 = F_117 ( V_25 -> V_37 , F_118 ( V_25 -> V_37 , 0 ) ,
V_330 ,
V_337 | V_338 |
V_339 ,
V_332 , V_331 , V_333 ,
V_334 , V_340 * 5 ) ;
} else {
V_336 = F_117 ( V_25 -> V_37 , F_119 ( V_25 -> V_37 , 0 ) ,
V_330 , V_337 | V_338 ,
V_332 , V_331 , V_333 ,
V_334 , V_340 * 5 ) ;
}
return V_336 ;
}
static int F_120 ( struct V_1 * V_25 )
{
int V_43 ;
int V_127 ;
unsigned char V_341 [ 64 ] ;
V_127 = F_9 ( V_25 , V_342 , 0 , 0 , V_341 , 2 ,
V_343 ) ;
if ( V_127 < 0 )
F_25 ( V_25 , 2 , L_66 , V_127 ) ;
V_43 = V_341 [ 0 ] + ( V_341 [ 1 ] << 8 ) ;
F_25 ( V_25 , 2 , L_67 , V_341 [ 0 ] , V_341 [ 1 ] ) ;
return V_43 ;
}
static int F_121 ( struct V_4 * V_5 )
{
unsigned long V_23 ;
unsigned long V_344 ;
V_5 -> V_70 . V_329 = V_195 ;
V_344 = V_345 ;
if ( V_344 > V_345 )
V_344 = V_345 ;
for ( V_23 = 0 ; V_23 < V_195 ; V_23 ++ ) {
V_5 -> V_70 . V_71 [ V_23 ] . V_72 = F_122 ( V_344 ) ;
V_5 -> V_70 . V_71 [ V_23 ] . V_22 = V_344 ;
if ( V_5 -> V_70 . V_71 [ V_23 ] . V_72 == NULL ) {
F_35 ( L_68 ) ;
V_5 -> V_70 . V_329 = V_23 ;
break;
}
}
for ( V_23 = 0 ; V_23 < V_195 ; V_23 ++ ) {
V_5 -> V_70 . V_71 [ V_23 ] . V_196 = 0 ;
V_5 -> V_70 . V_71 [ V_23 ] . V_198 = 0 ;
}
V_5 -> V_194 = 0 ;
V_5 -> V_69 = - 1 ;
return 0 ;
}
static int F_123 ( struct V_4 * V_5 )
{
unsigned long V_23 ;
for ( V_23 = 0 ; V_23 < V_195 ; V_23 ++ ) {
if ( V_5 -> V_70 . V_71 [ V_23 ] . V_72 )
F_124 ( V_5 -> V_70 . V_71 [ V_23 ] . V_72 ) ;
V_5 -> V_70 . V_71 [ V_23 ] . V_72 = NULL ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_25 )
{
struct V_125 V_346 = V_347 ;
int V_348 ;
int V_192 ;
struct V_302 * V_147 = & V_25 -> V_147 ;
F_25 ( V_25 , 4 , L_69 , V_25 ) ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
V_147 -> V_25 = V_25 ;
V_147 -> V_317 = V_349 ;
V_147 -> V_350 = V_349 ;
V_147 -> V_316 = F_126 ( V_147 -> V_350 ,
V_351 ) ;
if ( V_147 -> V_316 == NULL ) {
F_25 ( V_25 , 1 , L_70 ) ;
return - V_328 ;
}
V_348 = F_120 ( V_25 ) ;
F_35 ( L_71 ,
( V_348 >> 8 ) & 0xff ,
V_348 & 0xff ) ;
if ( V_348 < V_352 )
F_35 ( L_72 ) ;
for ( V_192 = 0 ; V_192 < V_275 ; V_192 ++ ) {
struct V_4 * V_5 = & V_25 -> V_5 [ V_192 ] ;
V_5 -> V_126 = V_346 ;
if ( V_25 -> V_210 == 0x2257 && V_192 > 1 )
V_5 -> V_126 . V_137 |= ( 1 << 16 ) ;
V_5 -> V_141 = V_281 ;
V_5 -> V_16 = V_8 ;
V_5 -> V_17 = V_159 * 2 ;
V_5 -> V_6 = V_353 ;
V_5 -> V_18 = & V_62 [ 0 ] ;
V_5 -> V_126 . V_144 = 1 ;
V_5 -> V_177 = F_55 ( & V_346 ) ;
V_5 -> V_78 = 0 ;
F_121 ( V_5 ) ;
}
F_127 ( V_25 ) ;
F_25 ( V_25 , 1 , L_73 , V_59 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_25 )
{
T_1 V_23 ;
F_25 ( V_25 , 1 , L_74 , V_59 , V_25 ) ;
for ( V_23 = 0 ; V_23 < V_275 ; V_23 ++ ) {
if ( F_80 ( & V_25 -> V_5 [ V_23 ] . V_124 ) )
F_67 ( & V_25 -> V_5 [ V_23 ] ) ;
}
F_128 ( V_25 ) ;
for ( V_23 = 0 ; V_23 < V_275 ; V_23 ++ )
F_123 ( & V_25 -> V_5 [ V_23 ] ) ;
F_94 ( V_25 -> V_147 . V_316 ) ;
return 0 ;
}
static void F_129 ( struct V_34 * V_354 )
{
struct V_302 * V_303 ;
struct V_1 * V_25 ;
int V_39 ;
int V_147 ;
V_303 = V_354 -> V_35 ;
if ( V_303 == NULL ) {
F_17 ( & V_354 -> V_25 -> V_25 , L_75 ) ;
return;
}
V_25 = V_303 -> V_25 ;
if ( V_25 == NULL ) {
F_17 ( & V_354 -> V_25 -> V_25 , L_75 ) ;
return;
}
V_39 = V_354 -> V_39 ;
if ( V_39 == - V_355 ) {
F_25 ( V_25 , 2 , L_76 , V_59 ) ;
V_303 -> V_356 ++ ;
return;
}
if ( V_303 -> V_259 == 0 ) {
F_25 ( V_25 , 2 , L_77 , V_59 ) ;
return;
}
if ( V_39 == 0 )
F_116 ( V_25 , V_303 ) ;
else {
V_303 -> V_356 ++ ;
F_25 ( V_25 , 1 , L_78 , V_59 , V_39 ) ;
}
V_147 = F_130 ( V_25 -> V_37 , V_25 -> V_357 ) ;
F_20 ( V_303 -> V_358 , V_25 -> V_37 ,
V_147 ,
V_303 -> V_316 ,
V_303 -> V_317 ,
F_129 , V_303 ) ;
if ( V_303 -> V_259 != 0 ) {
if ( F_12 ( V_303 -> V_358 , V_30 ) )
F_17 ( & V_25 -> V_37 -> V_25 , L_79 ) ;
} else {
F_25 ( V_25 , 2 , L_80 , V_59 ) ;
}
return;
}
static int F_127 ( struct V_1 * V_25 )
{
int V_147 ;
int V_149 ;
struct V_302 * V_303 = & V_25 -> V_147 ;
V_147 = F_130 ( V_25 -> V_37 , V_25 -> V_357 ) ;
F_25 ( V_25 , 2 , L_81 , V_59 , V_25 -> V_357 ) ;
V_303 -> V_259 = 1 ;
V_303 -> V_356 = 0 ;
V_303 -> V_358 = F_131 ( 0 , V_351 ) ;
if ( ! V_303 -> V_358 ) {
F_17 ( & V_25 -> V_37 -> V_25 ,
L_82 ) ;
return - V_328 ;
}
F_20 ( V_303 -> V_358 , V_25 -> V_37 ,
V_147 ,
V_303 -> V_316 ,
V_303 -> V_317 ,
F_129 , V_303 ) ;
V_149 = F_12 ( V_303 -> V_358 , V_351 ) ;
if ( V_149 ) {
F_13 ( L_83 ) ;
return V_149 ;
}
return 0 ;
}
static int F_65 ( struct V_4 * V_5 )
{
int V_170 ;
unsigned long V_171 ;
int V_192 ;
struct V_1 * V_25 = F_1 ( V_5 -> V_48 . V_3 ) ;
T_2 * V_70 = V_25 -> V_172 ;
F_58 ( & V_25 -> V_173 ) ;
V_171 = V_174 [ V_5 -> V_175 ] ;
V_5 -> V_69 = - 1 ;
V_5 -> V_193 = 0 ;
V_5 -> V_194 = 0 ;
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
V_5 -> V_70 . V_71 [ V_192 ] . V_196 = 0 ;
V_5 -> V_70 . V_71 [ V_192 ] . V_198 = 0 ;
}
V_70 [ 0 ] = V_178 ;
V_70 [ 1 ] = ( T_2 ) F_59 ( V_171 ) ;
V_70 [ 2 ] = V_359 ;
V_170 = F_53 ( V_25 -> V_37 , ( unsigned char * ) V_70 , 512 ) ;
if ( V_170 != 0 )
F_17 ( & V_25 -> V_37 -> V_25 , L_84 ) ;
F_25 ( V_25 , 2 , L_85 , V_5 -> V_175 , V_170 ) ;
F_62 ( & V_25 -> V_173 ) ;
return V_170 ;
}
static int F_67 ( struct V_4 * V_5 )
{
int V_170 ;
unsigned long V_171 ;
struct V_1 * V_25 = F_1 ( V_5 -> V_48 . V_3 ) ;
T_2 * V_70 = V_25 -> V_172 ;
F_58 ( & V_25 -> V_173 ) ;
V_171 = V_174 [ V_5 -> V_175 ] ;
V_70 [ 0 ] = V_178 ;
V_70 [ 1 ] = ( T_2 ) F_59 ( V_171 ) ;
V_70 [ 2 ] = V_360 ;
V_170 = F_53 ( V_25 -> V_37 , ( unsigned char * ) V_70 , 512 ) ;
if ( V_170 != 0 )
F_17 ( & V_25 -> V_37 -> V_25 , L_86 ) ;
F_25 ( V_25 , 4 , L_87 , V_59 , V_5 -> V_175 , V_170 ) ;
F_62 ( & V_25 -> V_173 ) ;
return V_170 ;
}
static void F_128 ( struct V_1 * V_25 )
{
struct V_302 * V_147 = & V_25 -> V_147 ;
V_147 -> V_259 = 0 ;
if ( V_147 -> V_358 ) {
F_91 ( V_147 -> V_358 ) ;
F_92 ( V_147 -> V_358 ) ;
V_147 -> V_358 = NULL ;
}
F_25 ( V_25 , 4 , L_44 , V_59 ) ;
return;
}
static void F_87 ( struct V_1 * V_25 , int V_361 )
{
if ( V_361 )
F_8 ( V_25 ) ;
V_25 -> V_260 -> V_41 = V_25 -> V_260 -> V_43 -> V_22 ;
F_14 ( & V_25 -> V_260 -> V_31 , V_265 ) ;
memcpy ( V_25 -> V_260 -> V_42 ,
V_25 -> V_260 -> V_43 -> V_28 , F_19 ) ;
V_25 -> V_260 -> V_40 = F_19 ;
F_20 ( V_25 -> V_260 -> V_29 , V_25 -> V_37 ,
F_21 ( V_25 -> V_37 , 2 ) ,
V_25 -> V_260 -> V_42 ,
F_19 , F_16 ,
V_25 -> V_260 ) ;
F_132 ( & V_25 -> V_268 , V_362 + V_340 ) ;
}
static int F_133 ( struct V_363 * V_274 ,
const struct V_364 * V_215 )
{
struct V_1 * V_25 = NULL ;
struct V_365 * V_366 ;
struct V_367 * V_368 ;
int V_23 ;
int V_149 = - V_328 ;
T_2 * V_311 ;
int V_41 ;
V_25 = F_126 ( sizeof( struct V_1 ) , V_351 ) ;
if ( V_25 == NULL ) {
F_18 ( & V_274 -> V_25 , L_88 ) ;
return - V_328 ;
}
V_25 -> V_172 = F_126 ( V_369 , V_351 ) ;
if ( V_25 -> V_172 == NULL ) {
F_18 ( & V_274 -> V_25 , L_88 ) ;
goto V_370;
}
F_14 ( & V_25 -> V_271 , 0 ) ;
V_25 -> V_210 = V_215 -> V_371 ;
V_25 -> V_260 = F_126 ( sizeof( struct V_27 ) , V_351 ) ;
if ( ! V_25 -> V_260 )
goto V_370;
F_134 ( & V_25 -> V_269 ) ;
F_134 ( & V_25 -> V_173 ) ;
V_25 -> V_37 = F_135 ( F_136 ( V_274 ) ) ;
if ( V_25 -> V_37 == NULL ) {
F_17 ( & V_274 -> V_25 , L_89 ) ;
V_149 = - V_262 ;
goto V_372;
}
F_137 ( & V_274 -> V_25 , L_90 ,
V_25 , V_25 -> V_37 , V_274 ) ;
V_25 -> V_274 = V_274 ;
V_366 = V_274 -> V_373 ;
F_137 ( & V_274 -> V_25 , L_91 ,
V_366 -> V_374 . V_375 ) ;
for ( V_23 = 0 ; V_23 < V_366 -> V_374 . V_375 ; ++ V_23 ) {
V_368 = & V_366 -> V_368 [ V_23 ] . V_374 ;
if ( ! V_25 -> V_357 && F_138 ( V_368 ) ) {
V_25 -> V_357 = V_368 -> V_376 ;
}
}
if ( ! V_25 -> V_357 ) {
F_17 ( & V_274 -> V_25 , L_92 ) ;
goto V_377;
}
F_139 ( & V_25 -> V_268 ) ;
V_25 -> V_268 . V_378 = F_11 ;
V_25 -> V_268 . V_28 = ( unsigned long ) V_25 -> V_260 ;
F_140 ( & V_25 -> V_260 -> V_33 ) ;
for ( V_23 = 0 ; V_23 < V_275 ; V_23 ++ ) {
struct V_4 * V_5 = & V_25 -> V_5 [ V_23 ] ;
V_5 -> V_175 = V_23 ;
V_5 -> V_25 = V_25 ;
F_140 ( & V_5 -> V_182 ) ;
F_140 ( & V_5 -> V_188 ) ;
F_141 ( & V_5 -> V_51 ) ;
F_134 ( & V_5 -> V_289 ) ;
}
V_25 -> V_260 -> V_29 = F_131 ( 0 , V_351 ) ;
if ( ! V_25 -> V_260 -> V_29 ) {
F_17 ( & V_274 -> V_25 , L_70 ) ;
goto V_379;
}
V_25 -> V_260 -> V_42 = F_126 ( F_19 , V_351 ) ;
if ( ! V_25 -> V_260 -> V_42 ) {
F_17 ( & V_274 -> V_25 , L_70 ) ;
goto V_380;
}
if ( F_142 ( & V_25 -> V_260 -> V_43 ,
V_381 , & V_25 -> V_37 -> V_25 ) ) {
F_17 ( & V_274 -> V_25 , L_93 ) ;
goto V_382;
}
V_41 = V_25 -> V_260 -> V_43 -> V_22 ;
V_311 = ( T_2 * ) & V_25 -> V_260 -> V_43 -> V_28 [ V_41 - 8 ] ;
if ( * V_311 != V_383 ) {
F_17 ( & V_274 -> V_25 , L_94 ) ;
V_149 = - V_262 ;
goto V_384;
} else {
T_2 * V_385 ;
V_385 = ( T_2 * ) & V_25 -> V_260 -> V_43 -> V_28 [ V_41 - 4 ] ;
F_35 ( L_95 , F_115 ( * V_385 ) ) ;
V_25 -> V_207 = F_115 ( * V_385 ) ;
if ( V_25 -> V_207 < V_386 )
F_35 ( L_96 ) ;
if ( V_25 -> V_210 == 0x2257 &&
V_25 -> V_207 < V_282 )
F_113 ( L_97 ,
V_282 ) ;
}
F_143 ( V_25 -> V_37 ) ;
V_149 = F_125 ( V_25 ) ;
if ( V_149 )
goto V_387;
F_87 ( V_25 , 0 ) ;
V_149 = F_101 ( V_25 ) ;
if ( V_149 )
goto V_387;
F_57 ( & V_274 -> V_25 , L_98 ) ;
return 0 ;
V_387:
F_89 ( V_25 ) ;
V_384:
F_93 ( V_25 -> V_260 -> V_43 ) ;
V_382:
F_94 ( V_25 -> V_260 -> V_42 ) ;
V_380:
F_92 ( V_25 -> V_260 -> V_29 ) ;
V_379:
F_90 ( & V_25 -> V_268 ) ;
V_377:
F_96 ( V_25 -> V_37 ) ;
V_372:
F_94 ( V_25 -> V_260 ) ;
F_95 ( & V_25 -> V_269 ) ;
V_370:
F_94 ( V_25 -> V_172 ) ;
F_94 ( V_25 ) ;
F_113 ( L_99 , V_149 ) ;
return V_149 ;
}
static void F_144 ( struct V_363 * V_274 )
{
struct V_1 * V_25 = F_1 ( F_145 ( V_274 ) ) ;
int V_23 ;
int V_388 = F_86 ( & V_25 -> V_271 ) ;
F_58 ( & V_25 -> V_269 ) ;
F_146 ( & V_25 -> V_3 ) ;
F_62 ( & V_25 -> V_269 ) ;
F_110 ( & V_25 -> V_271 ) ;
for ( V_23 = 0 ; V_23 < V_388 ; V_23 ++ )
F_147 ( & V_25 -> V_5 [ V_23 ] . V_48 ) ;
F_14 ( & V_25 -> V_260 -> V_31 , V_261 ) ;
F_15 ( & V_25 -> V_260 -> V_33 ) ;
for ( V_23 = 0 ; V_23 < V_275 ; V_23 ++ ) {
V_25 -> V_5 [ V_23 ] . V_180 = 1 ;
F_15 ( & V_25 -> V_5 [ V_23 ] . V_182 ) ;
V_25 -> V_5 [ V_23 ] . V_187 = 1 ;
F_15 ( & V_25 -> V_5 [ V_23 ] . V_188 ) ;
}
if ( F_100 ( & V_25 -> V_271 ) )
F_88 ( V_25 ) ;
F_57 ( & V_274 -> V_25 , L_10 , V_59 ) ;
}
