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
F_10 ( 10 ) ;
F_9 ( V_25 , 0x50 , 0x0000 , 0x0000 , NULL , 0 , 1 ) ;
F_10 ( 600 ) ;
F_9 ( V_25 , 0x10 , 0x0000 , 0x0000 , NULL , 0 , 1 ) ;
return;
}
static void F_11 ( unsigned long V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_26 ;
F_12 ( 100 , L_1 , V_29 ) ;
if ( F_13 ( V_28 -> V_30 , V_31 ) < 0 ) {
F_14 ( V_32 L_2 ) ;
F_15 ( & V_28 -> V_33 , V_34 ) ;
F_16 ( & V_28 -> V_35 ) ;
return;
}
}
static void F_17 ( struct V_36 * V_36 )
{
struct V_27 * V_28 = V_36 -> V_37 ;
struct V_38 * V_39 = V_36 -> V_25 ;
int V_40 ;
F_12 ( 100 , L_3 , V_29 , V_39 , V_36 ) ;
if ( V_36 -> V_41 ) {
F_18 ( & V_39 -> V_25 , L_4 , V_36 -> V_41 ) ;
F_15 ( & V_28 -> V_33 , V_34 ) ;
F_16 ( & V_28 -> V_35 ) ;
return;
}
if ( V_28 -> V_30 == NULL ) {
F_19 ( & V_39 -> V_25 , L_5 ) ;
F_15 ( & V_28 -> V_33 , V_34 ) ;
F_16 ( & V_28 -> V_35 ) ;
return;
}
#define F_20 512
if ( V_28 -> V_42 < V_28 -> V_43 ) {
V_40 = ( V_28 -> V_42 + F_20 ) > V_28 -> V_43 ?
V_28 -> V_43 % F_20 : F_20 ;
if ( V_40 < F_20 )
memset ( V_28 -> V_44 , 0 , F_20 ) ;
F_12 ( 100 , L_6 , V_40 ,
V_28 -> V_42 ) ;
memcpy ( V_28 -> V_44 ,
( char * ) V_28 -> V_45 -> V_28 + V_28 -> V_42 , V_40 ) ;
F_21 ( V_28 -> V_30 , V_39 , F_22 ( V_39 , 2 ) ,
V_28 -> V_44 , F_20 ,
F_17 , V_28 ) ;
if ( F_13 ( V_28 -> V_30 , V_31 ) < 0 ) {
F_18 ( & V_39 -> V_25 , L_7 ) ;
F_15 ( & V_28 -> V_33 , V_34 ) ;
F_16 ( & V_28 -> V_35 ) ;
return;
}
V_28 -> V_42 += V_40 ;
} else {
F_15 ( & V_28 -> V_33 , V_46 ) ;
F_12 ( 100 , L_8 , V_29 ) ;
}
return;
}
static int F_23 ( struct V_47 * V_48 , int V_49 )
{
struct V_50 * V_51 = & V_48 -> V_52 ;
struct V_53 * V_54 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
unsigned long V_55 = 0 ;
int V_56 = 0 ;
F_24 ( & V_25 -> V_57 , V_55 ) ;
if ( F_25 ( & V_51 -> V_58 ) ) {
F_12 ( 1 , L_9 ) ;
V_56 = - 1 ;
goto V_59;
}
V_54 = F_26 ( V_51 -> V_58 . V_60 ,
struct V_53 , V_61 . V_62 ) ;
F_27 ( & V_54 -> V_61 . V_62 ) ;
F_28 ( & V_54 -> V_61 . V_63 ) ;
F_29 ( V_48 , V_54 , V_49 ) ;
F_16 ( & V_54 -> V_61 . V_64 ) ;
F_12 ( 2 , L_10 , V_29 , V_54 , V_54 -> V_61 . V_23 ) ;
V_59:
F_30 ( & V_25 -> V_57 , V_55 ) ;
return V_56 ;
}
static const struct V_65 * F_31 ( int V_66 )
{
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_32 ( V_67 ) ; V_23 ++ ) {
if ( - 1 == V_67 [ V_23 ] . V_66 )
continue;
if ( ! V_68 && ( ( V_67 [ V_23 ] . V_66 == V_69 ) ||
( V_67 [ V_23 ] . V_66 == V_70 ) ) )
continue;
if ( V_67 [ V_23 ] . V_66 == V_66 )
return V_67 + V_23 ;
}
return NULL ;
}
static void F_29 ( struct V_47 * V_48 ,
struct V_53 * V_54 , int V_49 )
{
int V_71 = 0 ;
struct V_72 V_63 ;
const char * V_73 ;
char * V_74 = F_33 ( & V_54 -> V_61 ) ;
unsigned long V_75 ;
if ( ! V_74 )
return;
V_75 = V_48 -> V_75 ;
if ( V_75 != - 1 ) {
V_73 =
( const char * ) V_48 -> V_76 . V_77 [ V_75 ] . V_78 ;
switch ( V_54 -> V_18 -> V_66 ) {
case V_24 :
case V_79 :
F_7 ( ( const unsigned char * ) V_73 ,
V_74 , V_54 -> V_61 . V_16 ,
V_54 -> V_61 . V_17 ,
V_54 -> V_18 -> V_66 ) ;
break;
case V_80 :
memcpy ( V_74 , V_73 , V_54 -> V_61 . V_16 * V_54 -> V_61 . V_17 ) ;
break;
case V_69 :
case V_70 :
V_54 -> V_61 . V_22 = V_49 ;
memcpy ( V_74 , V_73 , V_54 -> V_61 . V_22 ) ;
break;
case V_81 :
memcpy ( V_74 , V_73 ,
V_54 -> V_61 . V_16 * V_54 -> V_61 . V_17 * 2 ) ;
break;
default:
F_14 ( V_82 L_11 ) ;
}
V_48 -> V_75 = - 1 ;
} else {
F_14 ( V_32 L_12 ) ;
return;
}
F_12 ( 2 , L_13 ,
( unsigned long ) V_74 , V_71 ) ;
V_54 -> V_61 . V_83 = V_48 -> V_84 * 2 ;
F_28 ( & V_63 ) ;
V_54 -> V_61 . V_63 = V_63 ;
V_54 -> V_61 . V_85 = V_86 ;
}
static int F_34 ( struct V_87 * V_88 , unsigned int * V_89 ,
unsigned int * V_22 )
{
struct V_90 * V_91 = V_88 -> V_92 ;
struct V_47 * V_48 = V_91 -> V_48 ;
* V_22 = V_48 -> V_16 * V_48 -> V_17 * ( V_48 -> V_18 -> V_93 >> 3 ) ;
if ( 0 == * V_89 )
* V_89 = V_94 ;
if ( * V_22 * * V_89 > V_95 * 1024 * 1024 )
* V_89 = ( V_95 * 1024 * 1024 ) / * V_22 ;
return 0 ;
}
static void F_35 ( struct V_87 * V_88 , struct V_53 * V_54 )
{
F_12 ( 4 , L_1 , V_29 ) ;
F_36 ( & V_54 -> V_61 ) ;
V_54 -> V_61 . V_85 = V_96 ;
}
static int F_37 ( struct V_87 * V_88 , struct V_97 * V_61 ,
enum V_98 V_99 )
{
struct V_90 * V_91 = V_88 -> V_92 ;
struct V_47 * V_48 = V_91 -> V_48 ;
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
int V_56 ;
int V_100 = V_48 -> V_16 ;
int V_101 = V_48 -> V_17 ;
F_12 ( 4 , L_14 , V_29 , V_99 ) ;
if ( V_48 -> V_18 == NULL )
return - V_102 ;
if ( ( V_100 < F_5 ( & V_48 -> V_5 ) ) ||
( V_100 > F_3 ( & V_48 -> V_5 ) ) ||
( V_101 < F_6 ( & V_48 -> V_5 ) ) ||
( V_101 > F_4 ( & V_48 -> V_5 ) ) ) {
F_12 ( 4 , L_15 ) ;
return - V_102 ;
}
V_54 -> V_61 . V_22 = V_100 * V_101 * ( V_48 -> V_18 -> V_93 >> 3 ) ;
if ( 0 != V_54 -> V_61 . V_103 && V_54 -> V_61 . V_104 < V_54 -> V_61 . V_22 ) {
F_12 ( 4 , L_15 ) ;
return - V_102 ;
}
V_54 -> V_18 = V_48 -> V_18 ;
V_54 -> V_61 . V_16 = V_100 ;
V_54 -> V_61 . V_17 = V_101 ;
V_54 -> V_61 . V_99 = V_99 ;
if ( V_96 == V_54 -> V_61 . V_85 ) {
V_56 = F_38 ( V_88 , & V_54 -> V_61 , NULL ) ;
if ( V_56 < 0 )
goto V_105;
}
V_54 -> V_61 . V_85 = V_106 ;
return 0 ;
V_105:
F_35 ( V_88 , V_54 ) ;
return V_56 ;
}
static void F_39 ( struct V_87 * V_88 , struct V_97 * V_61 )
{
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
struct V_90 * V_91 = V_88 -> V_92 ;
struct V_47 * V_48 = V_91 -> V_48 ;
struct V_50 * V_52 = & V_48 -> V_52 ;
F_12 ( 1 , L_1 , V_29 ) ;
V_54 -> V_61 . V_85 = V_107 ;
F_40 ( & V_54 -> V_61 . V_62 , & V_52 -> V_58 ) ;
}
static void F_41 ( struct V_87 * V_88 ,
struct V_97 * V_61 )
{
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
struct V_90 * V_91 = V_88 -> V_92 ;
F_12 ( 4 , L_16 , V_29 , V_91 -> V_48 -> V_108 ) ;
F_35 ( V_88 , V_54 ) ;
}
static int F_42 ( struct V_90 * V_91 )
{
struct V_47 * V_48 = V_91 -> V_48 ;
if ( V_48 -> V_109 )
return 0 ;
V_48 -> V_109 = 1 ;
V_91 -> V_109 = 1 ;
F_12 ( 1 , L_17 ) ;
return 1 ;
}
static int F_43 ( struct V_90 * V_91 )
{
return V_91 -> V_48 -> V_109 ;
}
static int F_44 ( struct V_90 * V_91 )
{
return V_91 -> V_109 ;
}
static void F_45 ( struct V_90 * V_91 )
{
struct V_47 * V_48 = V_91 -> V_48 ;
V_48 -> V_109 = 0 ;
V_91 -> V_109 = 0 ;
F_12 ( 1 , L_18 ) ;
}
static int F_46 ( struct V_110 * V_110 , void * V_111 ,
struct V_112 * V_113 )
{
static const char * V_114 [] = {
L_19 ,
L_20 ,
NULL
} ;
if ( V_113 -> V_115 == V_116 ) {
int V_23 ;
const char * * V_117 = V_114 ;
for ( V_23 = 0 ; V_23 < V_113 -> V_118 && V_117 [ V_23 ] ; V_23 ++ )
;
if ( V_117 [ V_23 ] == NULL || V_117 [ V_23 ] [ 0 ] == '\0' )
return - V_102 ;
F_47 ( V_113 -> V_119 , V_117 [ V_113 -> V_118 ] ,
sizeof( V_113 -> V_119 ) ) ;
return 0 ;
}
return F_48 ( V_113 , NULL , NULL ) ;
}
static int F_49 ( struct V_110 * V_110 , void * V_111 ,
struct V_120 * V_121 )
{
struct V_90 * V_91 = V_110 -> V_122 ;
struct V_1 * V_25 = V_91 -> V_25 ;
F_47 ( V_121 -> V_123 , L_21 , sizeof( V_121 -> V_123 ) ) ;
F_47 ( V_121 -> V_124 , L_21 , sizeof( V_121 -> V_124 ) ) ;
F_50 ( V_25 -> V_39 , V_121 -> V_125 , sizeof( V_121 -> V_125 ) ) ;
V_121 -> V_126 = V_127 | V_128 ;
return 0 ;
}
static int F_51 ( struct V_110 * V_110 , void * V_111 ,
struct V_129 * V_130 )
{
int V_118 = V_130 -> V_118 ;
if ( V_118 >= F_32 ( V_67 ) )
return - V_102 ;
if ( ! V_68 && ( ( V_67 [ V_118 ] . V_66 == V_69 ) ||
( V_67 [ V_118 ] . V_66 == V_70 ) ) )
return - V_102 ;
F_12 ( 4 , L_22 , V_67 [ V_118 ] . V_119 ) ;
F_47 ( V_130 -> V_131 , V_67 [ V_118 ] . V_119 , sizeof( V_130 -> V_131 ) ) ;
V_130 -> V_132 = V_67 [ V_118 ] . V_66 ;
return 0 ;
}
static int F_52 ( struct V_110 * V_110 , void * V_111 ,
struct V_133 * V_130 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
V_130 -> V_18 . V_134 . V_16 = V_48 -> V_16 ;
V_130 -> V_18 . V_134 . V_17 = V_48 -> V_17 ;
V_130 -> V_18 . V_134 . V_99 = V_91 -> V_135 . V_99 ;
V_130 -> V_18 . V_134 . V_132 = V_48 -> V_18 -> V_66 ;
V_130 -> V_18 . V_134 . V_136 = V_130 -> V_18 . V_134 . V_16 * ( V_48 -> V_18 -> V_93 >> 3 ) ;
V_130 -> V_18 . V_134 . V_137 = V_130 -> V_18 . V_134 . V_17 * V_130 -> V_18 . V_134 . V_136 ;
return 0 ;
}
static int F_53 ( struct V_110 * V_110 , void * V_111 ,
struct V_133 * V_130 )
{
const struct V_65 * V_18 ;
enum V_98 V_99 ;
int V_138 = 0 ;
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
int V_139 ;
V_139 =
( V_48 -> V_5 . V_6 & V_7 ) ? 1 : 0 ;
V_18 = F_31 ( V_130 -> V_18 . V_134 . V_132 ) ;
if ( V_18 == NULL )
return - V_102 ;
V_99 = V_130 -> V_18 . V_134 . V_99 ;
if ( V_99 == V_140 )
V_138 = 1 ;
F_12 ( 50 , L_23 ,
V_29 , V_139 , V_130 -> V_18 . V_134 . V_16 , V_130 -> V_18 . V_134 . V_17 ) ;
if ( V_139 ) {
if ( V_130 -> V_18 . V_134 . V_17 >= V_10 * 2 ) {
V_130 -> V_18 . V_134 . V_17 = V_10 * 2 ;
if ( V_138 ) {
V_99 = V_141 ;
} else if ( ! ( ( V_99 == V_142 ) ||
( V_99 == V_141 ) ||
( V_99 == V_143 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_102 ;
}
} else {
V_130 -> V_18 . V_134 . V_17 = V_10 ;
if ( V_138 ) {
V_99 = V_144 ;
} else if ( ! ( ( V_99 == V_144 ) ||
( V_99 == V_145 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_102 ;
}
}
if ( V_130 -> V_18 . V_134 . V_16 >= V_8 )
V_130 -> V_18 . V_134 . V_16 = V_8 ;
else if ( V_130 -> V_18 . V_134 . V_16 >= V_146 )
V_130 -> V_18 . V_134 . V_16 = V_146 ;
else if ( V_130 -> V_18 . V_134 . V_16 >= V_12 )
V_130 -> V_18 . V_134 . V_16 = V_12 ;
else
V_130 -> V_18 . V_134 . V_16 = V_12 ;
} else {
if ( V_130 -> V_18 . V_134 . V_17 >= V_11 * 2 ) {
V_130 -> V_18 . V_134 . V_17 = V_11 * 2 ;
if ( V_138 ) {
V_99 = V_141 ;
} else if ( ! ( ( V_99 == V_142 ) ||
( V_99 == V_141 ) ||
( V_99 == V_143 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_102 ;
}
} else {
V_130 -> V_18 . V_134 . V_17 = V_11 ;
if ( V_138 ) {
V_99 = V_144 ;
} else if ( ! ( ( V_99 == V_144 ) ||
( V_99 == V_145 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_102 ;
}
}
if ( V_130 -> V_18 . V_134 . V_16 >= V_9 ) {
V_130 -> V_18 . V_134 . V_16 = V_9 ;
V_99 = V_141 ;
} else if ( V_130 -> V_18 . V_134 . V_16 >= V_147 ) {
V_130 -> V_18 . V_134 . V_16 = V_147 ;
V_99 = V_144 ;
} else if ( V_130 -> V_18 . V_134 . V_16 >= V_13 ) {
V_130 -> V_18 . V_134 . V_16 = V_13 ;
V_99 = V_144 ;
} else {
V_130 -> V_18 . V_134 . V_16 = V_13 ;
V_99 = V_144 ;
}
}
V_130 -> V_18 . V_134 . V_99 = V_99 ;
V_130 -> V_18 . V_134 . V_136 = ( V_130 -> V_18 . V_134 . V_16 * V_18 -> V_93 ) >> 3 ;
V_130 -> V_18 . V_134 . V_137 = V_130 -> V_18 . V_134 . V_17 * V_130 -> V_18 . V_134 . V_136 ;
F_12 ( 50 , L_25 , V_29 ,
V_130 -> V_18 . V_134 . V_16 , V_130 -> V_18 . V_134 . V_17 , V_130 -> V_18 . V_134 . V_99 ) ;
return 0 ;
}
static int F_54 ( struct V_110 * V_110 , void * V_111 ,
struct V_133 * V_130 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
const struct V_65 * V_18 ;
struct V_87 * V_148 = & V_91 -> V_135 ;
struct V_149 V_150 ;
int V_151 ;
V_151 = F_53 ( V_110 , V_91 , V_130 ) ;
if ( V_151 < 0 )
return V_151 ;
V_18 = F_31 ( V_130 -> V_18 . V_134 . V_132 ) ;
if ( V_18 == NULL )
return - V_102 ;
F_55 ( & V_148 -> V_152 ) ;
if ( F_56 ( & V_91 -> V_135 ) ) {
F_12 ( 1 , L_26 ) ;
V_151 = - V_153 ;
goto V_154;
}
if ( F_43 ( V_91 ) ) {
F_12 ( 1 , L_27 , V_29 ) ;
V_151 = - V_153 ;
goto V_154;
}
V_150 = V_48 -> V_150 ;
V_48 -> V_18 = V_18 ;
V_48 -> V_16 = V_130 -> V_18 . V_134 . V_16 ;
V_48 -> V_17 = V_130 -> V_18 . V_134 . V_17 ;
V_91 -> V_135 . V_99 = V_130 -> V_18 . V_134 . V_99 ;
V_91 -> type = V_130 -> type ;
if ( V_48 -> V_16 > F_5 ( & V_48 -> V_5 ) ) {
if ( V_48 -> V_17 > F_6 ( & V_48 -> V_5 ) ) {
if ( V_48 -> V_155 . V_156 &
V_157 )
V_150 . V_158 = V_159 ;
else
V_150 . V_158 = V_160 ;
} else
V_150 . V_158 = V_161 ;
} else {
V_150 . V_158 = V_162 ;
}
switch ( V_48 -> V_18 -> V_66 ) {
case V_80 :
V_150 . V_163 &= ~ V_164 ;
V_150 . V_163 |= V_165 ;
break;
case V_69 :
case V_70 :
V_150 . V_163 &= ~ V_164 ;
V_150 . V_163 |= V_166 ;
V_150 . V_163 |= ( V_48 -> V_167 . V_168 << 8 ) ;
break;
case V_81 :
V_150 . V_163 &= ~ V_164 ;
V_150 . V_163 |= V_169 ;
break;
case V_24 :
case V_79 :
default:
V_150 . V_163 &= ~ V_164 ;
V_150 . V_163 |= V_170 ;
break;
}
if ( ( V_150 . V_163 & V_164 ) != ( V_48 -> V_150 . V_163 & V_164 ) )
V_150 . V_171 = 1 ;
else if ( V_150 . V_158 != V_48 -> V_150 . V_158 )
V_150 . V_171 = 1 ;
else if ( V_150 . V_172 != V_48 -> V_150 . V_172 )
V_150 . V_171 = 1 ;
V_48 -> V_150 = V_150 ;
( void ) F_57 ( V_48 , & V_150 ) ;
V_151 = 0 ;
V_154:
F_58 ( & V_148 -> V_152 ) ;
return V_151 ;
}
static int F_59 ( struct V_110 * V_110 , void * V_111 ,
struct V_173 * V_174 )
{
int V_56 ;
struct V_90 * V_91 = V_111 ;
V_56 = F_60 ( & V_91 -> V_135 , V_174 ) ;
return V_56 ;
}
static int F_61 ( struct V_110 * V_110 , void * V_111 , struct V_175 * V_174 )
{
int V_56 ;
struct V_90 * V_91 = V_111 ;
V_56 = F_62 ( & V_91 -> V_135 , V_174 ) ;
return V_56 ;
}
static int F_63 ( struct V_110 * V_110 , void * V_111 , struct V_175 * V_174 )
{
int V_56 ;
struct V_90 * V_91 = V_111 ;
V_56 = F_64 ( & V_91 -> V_135 , V_174 ) ;
return V_56 ;
}
static int F_65 ( struct V_110 * V_110 , void * V_111 , struct V_175 * V_174 )
{
int V_56 ;
struct V_90 * V_91 = V_111 ;
V_56 = F_66 ( & V_91 -> V_135 , V_174 , V_110 -> V_176 & V_177 ) ;
return V_56 ;
}
static int F_67 ( struct V_38 * V_39 , unsigned char * V_178 ,
int V_22 )
{
int V_179 ;
int V_64 ;
long V_180 = - 1 ;
if ( V_39 ) {
V_179 = F_22 ( V_39 , V_181 ) ;
V_180 = F_68 ( V_39 , V_179 , V_178 , V_22 , & V_64 , 500 ) ;
}
return V_180 ;
}
static T_1 F_69 ( struct V_149 * V_150 )
{
int V_182 = V_183 ;
int V_184 = V_185 ;
T_1 V_186 ;
T_1 V_187 ;
unsigned int V_188 ;
if ( V_150 == NULL )
return 0 ;
if ( V_150 -> V_172 == V_189 ) {
switch ( V_150 -> V_158 ) {
case V_160 :
case V_159 :
V_182 = V_190 * 2 ;
V_184 = V_8 ;
break;
case V_161 :
V_182 = V_191 ;
V_184 = V_146 ;
break;
case V_162 :
V_182 = V_10 ;
V_184 = V_12 ;
break;
default:
break;
}
} else if ( V_150 -> V_172 == V_192 ) {
switch ( V_150 -> V_158 ) {
case V_160 :
case V_159 :
V_182 = V_193 * 2 ;
V_184 = V_9 ;
break;
case V_161 :
V_182 = V_194 ;
V_184 = V_147 ;
break;
case V_162 :
V_182 = V_11 ;
V_184 = V_13 ;
break;
default:
break;
}
}
V_186 = V_182 * V_184 ;
if ( ( V_150 -> V_163 & V_164 ) != V_165 ) {
V_186 *= 2 ;
}
V_187 = V_186 + V_195 ;
V_188 = 0xffffffffUL - V_196 + 1 ;
if ( V_187 & ~ V_188 )
V_187 = ( V_187 & V_188 ) + ( V_196 ) ;
return V_187 ;
}
static void F_70 ( struct V_1 * V_197 , struct V_149 * V_150 )
{
struct V_198 * V_25 = & V_197 -> V_39 -> V_25 ;
F_71 ( V_25 , L_28 ) ;
F_71 ( V_25 , L_29 , V_150 -> V_172 , V_150 -> V_158 ) ;
F_71 ( V_25 , L_30 , V_150 -> V_199 , V_150 -> V_163 ) ;
F_71 ( V_25 , L_31 , V_150 -> V_200 ) ;
F_71 ( V_25 , L_28 ) ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_149 * V_150 )
{
int V_201 ;
T_2 * V_76 ;
unsigned long V_202 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_202 = V_203 [ V_48 -> V_108 ] ;
F_12 ( 3 , L_32 , V_29 , V_48 -> V_108 ) ;
if ( ( V_150 -> V_163 & V_164 ) == V_166 ) {
V_150 -> V_163 &= ~ V_164 ;
V_150 -> V_163 |= V_166 ;
V_150 -> V_163 &= ~ V_204 ;
V_150 -> V_163 |= ( V_48 -> V_167 . V_168 << 8 ) ;
}
V_48 -> V_150 = * V_150 ;
V_48 -> V_205 = F_69 ( V_150 ) ;
F_12 ( 1 , L_33 , V_29 , V_48 -> V_205 ) ;
V_76 = F_72 ( 512 , V_206 ) ;
if ( V_76 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_207 ;
}
V_76 [ 0 ] = V_208 ;
V_76 [ 1 ] = ( T_2 ) F_73 ( V_202 ) ;
V_76 [ 2 ] = V_209 ;
memcpy ( & V_76 [ 3 ] , & V_48 -> V_150 , sizeof( struct V_149 ) ) ;
V_48 -> V_210 = 0 ;
V_201 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_76 , 512 ) ;
if ( V_211 )
F_70 ( V_25 , V_150 ) ;
F_74 ( V_76 ) ;
if ( V_150 -> V_171 ) {
F_75 ( V_48 -> V_212 ,
( V_48 -> V_210 != 0 ) ,
F_76 ( V_213 ) ) ;
if ( V_48 -> V_210 != 1 ) {
F_14 ( V_82 L_35 ) ;
V_201 = - V_214 ;
}
}
V_48 -> V_150 . V_171 = 0 ;
F_12 ( 1 , L_36 , V_29 , V_48 -> V_108 , V_201 ) ;
return V_201 ;
}
static int F_77 ( struct V_47 * V_48 , T_1 * V_215 )
{
int V_201 ;
T_2 * V_76 ;
T_1 V_202 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_202 = V_203 [ V_48 -> V_108 ] ;
F_12 ( 4 , L_37 , V_29 , V_48 -> V_108 ) ;
V_76 = F_72 ( 512 , V_206 ) ;
if ( V_76 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_207 ;
}
V_76 [ 0 ] = V_208 ;
V_76 [ 1 ] = ( T_2 ) F_73 ( V_202 ) ;
V_76 [ 2 ] = V_216 ;
* V_215 = 0 ;
V_48 -> V_217 = 0 ;
V_201 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_76 , 512 ) ;
F_74 ( V_76 ) ;
F_75 ( V_48 -> V_218 ,
( V_48 -> V_217 != 0 ) ,
F_76 ( V_219 ) ) ;
if ( V_48 -> V_217 != 1 ) {
F_14 ( V_82 L_38 ) ;
V_201 = - V_214 ;
}
* V_215 = V_48 -> V_220 ;
F_12 ( 4 , L_39 , V_29 , * V_215 ) ;
return V_201 ;
}
static int F_78 ( struct V_110 * V_110 , void * V_111 , enum V_221 V_23 )
{
int V_201 ;
struct V_90 * V_91 = V_111 ;
struct V_1 * V_25 = V_91 -> V_25 ;
struct V_47 * V_48 = V_91 -> V_48 ;
int V_222 ;
F_12 ( 4 , L_1 , V_29 ) ;
if ( V_91 -> type != V_223 ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_40 ) ;
return - V_102 ;
}
if ( V_23 != V_91 -> type ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_41 ) ;
return - V_102 ;
}
if ( ! F_42 ( V_91 ) ) {
F_19 ( & V_25 -> V_39 -> V_25 , L_42 ) ;
return - V_153 ;
}
V_48 -> V_75 = - 1 ;
V_48 -> V_224 = 0 ;
V_48 -> V_225 = 0 ;
V_48 -> V_84 = 0 ;
for ( V_222 = 0 ; V_222 < V_226 ; V_222 ++ ) {
V_48 -> V_76 . V_77 [ V_222 ] . V_227 = V_228 ;
V_48 -> V_76 . V_77 [ V_222 ] . V_229 = 0 ;
}
V_201 = F_79 ( & V_91 -> V_135 ) ;
if ( V_201 == 0 ) {
F_80 ( V_48 ) ;
V_48 -> V_230 = 1 ;
} else
F_45 ( V_91 ) ;
return V_201 ;
}
static int F_81 ( struct V_110 * V_110 , void * V_111 , enum V_221 V_23 )
{
struct V_90 * V_91 = V_111 ;
F_12 ( 4 , L_43 , V_29 , V_91 -> V_48 -> V_108 ) ;
if ( V_91 -> type != V_223 ) {
F_14 ( V_32 L_40 ) ;
return - V_102 ;
}
if ( V_23 != V_91 -> type ) {
F_14 ( V_32 L_44 ) ;
return - V_102 ;
}
F_82 ( V_91 -> V_48 ) ;
F_83 ( & V_91 -> V_135 ) ;
F_45 ( V_91 ) ;
return 0 ;
}
static int F_84 ( struct V_110 * V_110 , void * V_111 , T_3 * V_23 )
{
struct V_90 * V_91 = V_111 ;
struct V_149 V_150 ;
struct V_87 * V_148 = & V_91 -> V_135 ;
int V_151 = 0 ;
F_55 ( & V_148 -> V_152 ) ;
if ( F_56 ( V_148 ) ) {
F_12 ( 1 , L_26 ) ;
V_151 = - V_153 ;
goto V_231;
}
if ( F_43 ( V_91 ) ) {
F_12 ( 1 , L_45 ) ;
V_151 = - V_153 ;
goto V_231;
}
V_150 = V_91 -> V_48 -> V_150 ;
if ( * V_23 & V_7 ) {
F_12 ( 4 , L_46 , V_29 ) ;
if ( V_150 . V_172 != V_189 ) {
V_150 . V_171 = 1 ;
V_150 . V_172 = V_189 ;
V_150 . V_199 = V_232 ;
}
} else if ( * V_23 & V_233 ) {
F_12 ( 4 , L_47 , V_29 ) ;
if ( V_150 . V_172 != V_192 ) {
V_150 . V_171 = 1 ;
V_150 . V_172 = V_192 ;
V_150 . V_199 = V_232 ;
}
} else {
V_151 = - V_102 ;
}
if ( V_150 . V_171 )
F_57 ( V_91 -> V_48 , & V_150 ) ;
V_231:
F_58 ( & V_148 -> V_152 ) ;
return V_151 ;
}
static int F_85 ( struct V_110 * V_110 , void * V_111 ,
struct V_234 * V_235 )
{
struct V_90 * V_91 = V_111 ;
struct V_1 * V_25 = V_91 -> V_25 ;
struct V_47 * V_48 = V_91 -> V_48 ;
T_1 V_41 = 0 ;
if ( V_235 -> V_118 != 0 )
return - V_102 ;
V_235 -> type = V_236 ;
V_235 -> V_237 = V_238 ;
V_235 -> V_41 = 0 ;
if ( V_25 -> V_239 >= V_240 ) {
int V_56 ;
V_56 = F_77 ( V_91 -> V_48 , & V_41 ) ;
F_12 ( 4 , L_48 , V_56 , V_41 ) ;
if ( V_56 == 0 )
V_235 -> V_41 = ( V_41 & 0x01 ) ? 0
: V_241 ;
}
switch ( V_25 -> V_242 ) {
case 0x2255 :
default:
F_47 ( V_235 -> V_119 , L_49 , sizeof( V_235 -> V_119 ) ) ;
break;
case 0x2257 :
F_47 ( V_235 -> V_119 , ( V_48 -> V_108 < 2 ) ? L_49 : L_50 ,
sizeof( V_235 -> V_119 ) ) ;
break;
}
return 0 ;
}
static int F_86 ( struct V_110 * V_110 , void * V_111 , unsigned int * V_23 )
{
* V_23 = 0 ;
return 0 ;
}
static int F_87 ( struct V_110 * V_110 , void * V_111 , unsigned int V_23 )
{
if ( V_23 > 0 )
return - V_102 ;
return 0 ;
}
static int F_88 ( struct V_110 * V_110 , void * V_111 ,
struct V_243 * V_244 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
struct V_1 * V_25 = V_91 -> V_25 ;
switch ( V_244 -> V_115 ) {
case V_245 :
F_89 ( V_244 , - 127 , 127 , 1 , V_246 ) ;
break;
case V_247 :
F_89 ( V_244 , 0 , 255 , 1 , V_248 ) ;
break;
case V_249 :
F_89 ( V_244 , 0 , 255 , 1 , V_250 ) ;
break;
case V_251 :
F_89 ( V_244 , 0 , 255 , 1 , V_252 ) ;
break;
case V_116 :
if ( V_25 -> V_239 < V_253 )
return - V_102 ;
if ( ( V_25 -> V_242 == 0x2257 ) && ( V_48 -> V_108 > 1 ) )
return - V_102 ;
F_47 ( V_244 -> V_119 , L_51 , sizeof( V_244 -> V_119 ) ) ;
V_244 -> type = V_254 ;
V_244 -> V_255 = 0 ;
V_244 -> V_256 = 1 ;
V_244 -> V_257 = 1 ;
V_244 -> V_258 = 1 ;
V_244 -> V_55 = 0 ;
break;
default:
return - V_102 ;
}
F_12 ( 4 , L_52 , V_29 , V_244 -> V_115 ) ;
return 0 ;
}
static int F_90 ( struct V_110 * V_110 , void * V_111 ,
struct V_259 * V_260 )
{
struct V_90 * V_91 = V_111 ;
struct V_1 * V_25 = V_91 -> V_25 ;
struct V_47 * V_48 = V_91 -> V_48 ;
switch ( V_260 -> V_115 ) {
case V_245 :
V_260 -> V_261 = V_48 -> V_150 . V_200 ;
break;
case V_247 :
V_260 -> V_261 = V_48 -> V_150 . V_262 ;
break;
case V_249 :
V_260 -> V_261 = V_48 -> V_150 . V_263 ;
break;
case V_251 :
V_260 -> V_261 = V_48 -> V_150 . V_264 ;
break;
case V_116 :
if ( V_25 -> V_239 < V_253 )
return - V_102 ;
if ( ( V_25 -> V_242 == 0x2257 ) && ( V_48 -> V_108 > 1 ) )
return - V_102 ;
V_260 -> V_261 = ! ( ( V_48 -> V_150 . V_163 & V_265 ) >> 16 ) ;
break;
default:
return - V_102 ;
}
F_12 ( 4 , L_53 , V_29 , V_260 -> V_115 , V_260 -> V_261 ) ;
return 0 ;
}
static int F_91 ( struct V_110 * V_110 , void * V_111 ,
struct V_259 * V_260 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
struct V_149 V_150 ;
V_150 = V_48 -> V_150 ;
F_12 ( 4 , L_1 , V_29 ) ;
switch ( V_260 -> V_115 ) {
case V_245 :
V_150 . V_200 = V_260 -> V_261 ;
break;
case V_247 :
V_150 . V_262 = V_260 -> V_261 ;
break;
case V_251 :
V_150 . V_264 = V_260 -> V_261 ;
break;
case V_249 :
V_150 . V_263 = V_260 -> V_261 ;
break;
case V_116 :
if ( V_25 -> V_239 < V_253 )
return - V_102 ;
if ( ( V_25 -> V_242 == 0x2257 ) && ( V_48 -> V_108 > 1 ) )
return - V_102 ;
V_150 . V_163 &= ~ V_265 ;
V_150 . V_163 |= ( ( V_260 -> V_261 ? 0 : 1 ) << 16 ) ;
break;
default:
return - V_102 ;
}
V_150 . V_171 = 0 ;
F_57 ( V_91 -> V_48 , & V_150 ) ;
return 0 ;
}
static int F_92 ( struct V_110 * V_110 , void * V_111 ,
struct V_266 * V_167 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
* V_167 = V_48 -> V_167 ;
F_12 ( 2 , L_54 , V_29 , V_167 -> V_168 ) ;
return 0 ;
}
static int F_93 ( struct V_110 * V_110 , void * V_111 ,
const struct V_266 * V_167 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
if ( V_167 -> V_168 < 0 || V_167 -> V_168 > 100 )
return - V_102 ;
V_48 -> V_167 . V_168 = V_167 -> V_168 ;
F_12 ( 2 , L_54 , V_29 , V_167 -> V_168 ) ;
return 0 ;
}
static int F_94 ( struct V_110 * V_110 , void * V_111 ,
struct V_267 * V_268 )
{
struct V_90 * V_91 = V_111 ;
T_4 V_269 , V_270 ;
struct V_47 * V_48 = V_91 -> V_48 ;
if ( V_268 -> type != V_223 )
return - V_102 ;
memset ( V_268 , 0 , sizeof( struct V_267 ) ) ;
V_268 -> V_271 . V_272 . V_273 = V_274 ;
V_268 -> V_271 . V_272 . V_156 = V_48 -> V_155 . V_156 ;
V_269 = ( V_48 -> V_150 . V_172 == V_189 ) ? 1001 : 1000 ;
V_270 = ( V_48 -> V_150 . V_172 == V_189 ) ? 30000 : 25000 ;
V_268 -> V_271 . V_272 . V_275 . V_276 = V_270 ;
switch ( V_48 -> V_150 . V_199 ) {
default:
case V_232 :
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 ;
break;
case V_278 :
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 * 2 ;
break;
case V_279 :
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 * 3 ;
break;
case V_280 :
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 * 5 ;
break;
}
F_12 ( 4 , L_55 , V_29 ,
V_268 -> V_271 . V_272 . V_156 ,
V_268 -> V_271 . V_272 . V_275 . V_277 ,
V_268 -> V_271 . V_272 . V_275 . V_276 ) ;
return 0 ;
}
static int F_95 ( struct V_110 * V_110 , void * V_111 ,
struct V_267 * V_268 )
{
struct V_90 * V_91 = V_111 ;
struct V_47 * V_48 = V_91 -> V_48 ;
struct V_149 V_150 ;
int V_199 = V_232 ;
T_4 V_269 , V_270 ;
if ( V_268 -> type != V_223 )
return - V_102 ;
V_150 = V_48 -> V_150 ;
if ( V_48 -> V_155 . V_156
!= V_268 -> V_271 . V_272 . V_156 && F_43 ( V_91 ) )
return - V_153 ;
V_269 = ( V_150 . V_172 == V_189 ) ? 1001 : 1000 ;
V_270 = ( V_150 . V_172 == V_189 ) ? 30000 : 25000 ;
if ( V_270 != V_268 -> V_271 . V_272 . V_275 . V_276 )
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 ;
else if ( V_268 -> V_271 . V_272 . V_275 . V_277 <= V_269 )
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 ;
else if ( V_268 -> V_271 . V_272 . V_275 . V_277 <= ( V_269 * 2 ) ) {
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 * 2 ;
V_199 = V_278 ;
} else if ( V_268 -> V_271 . V_272 . V_275 . V_277 <= ( V_269 * 3 ) ) {
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 * 3 ;
V_199 = V_279 ;
} else {
V_268 -> V_271 . V_272 . V_275 . V_277 = V_269 * 5 ;
V_199 = V_280 ;
}
V_150 . V_199 = V_199 ;
V_268 -> V_271 . V_272 . V_275 . V_276 = V_270 ;
F_57 ( V_48 , & V_150 ) ;
F_12 ( 4 , L_56 ,
V_29 ,
V_268 -> V_271 . V_272 . V_156 ,
V_268 -> V_271 . V_272 . V_275 . V_277 ,
V_268 -> V_271 . V_272 . V_275 . V_276 , V_199 ) ;
return 0 ;
}
static int F_96 ( struct V_110 * V_110 , void * V_111 ,
struct V_281 * V_282 )
{
int V_139 = 0 ;
#define F_97 4
int V_283 [ F_97 ] = { 1 , 2 , 3 , 5 } ;
if ( V_282 -> V_118 >= F_97 )
return - V_102 ;
switch ( V_282 -> V_16 ) {
case 640 :
if ( V_282 -> V_17 != 240 && V_282 -> V_17 != 480 )
return - V_102 ;
V_139 = 1 ;
break;
case 320 :
if ( V_282 -> V_17 != 240 )
return - V_102 ;
V_139 = 1 ;
break;
case 704 :
if ( V_282 -> V_17 != 288 && V_282 -> V_17 != 576 )
return - V_102 ;
break;
case 352 :
if ( V_282 -> V_17 != 288 )
return - V_102 ;
break;
default:
return - V_102 ;
}
V_282 -> type = V_284 ;
V_282 -> V_285 . V_276 = V_139 ? 30000 : 25000 ;
V_282 -> V_285 . V_277 = ( V_139 ? 1001 : 1000 ) * V_283 [ V_282 -> V_118 ] ;
F_12 ( 4 , L_57 , V_29 , V_282 -> V_285 . V_277 ,
V_282 -> V_285 . V_276 ) ;
return 0 ;
}
static int F_98 ( struct V_110 * V_110 )
{
struct V_4 * V_5 = F_99 ( V_110 ) ;
struct V_47 * V_48 = F_100 ( V_110 ) ;
struct V_1 * V_25 = F_1 ( V_5 -> V_3 ) ;
struct V_90 * V_91 ;
enum V_221 type = V_223 ;
int V_85 ;
F_12 ( 1 , L_58 ,
F_101 ( V_5 ) ) ;
V_85 = F_102 ( & V_25 -> V_286 -> V_33 ) ;
switch ( V_85 ) {
case V_287 :
return - V_288 ;
case V_34 :
F_19 ( & V_25 -> V_39 -> V_25 ,
L_59 ) ;
F_103 ( V_25 , 1 ) ;
F_75 ( V_25 -> V_286 -> V_35 ,
( ( F_102 ( & V_25 -> V_286 -> V_33 )
== V_289 ) ||
( F_102 ( & V_25 -> V_286 -> V_33 )
== V_287 ) ) ,
F_76 ( V_290 ) ) ;
V_85 = F_102 ( & V_25 -> V_286 -> V_33 ) ;
break;
case V_291 :
case V_46 :
F_14 ( V_292 L_60 , V_29 ) ;
F_75 ( V_25 -> V_286 -> V_35 ,
( ( F_102 ( & V_25 -> V_286 -> V_33 )
== V_289 ) ||
( F_102 ( & V_25 -> V_286 -> V_33 )
== V_287 ) ) ,
F_76 ( V_290 ) ) ;
V_85 = F_102 ( & V_25 -> V_286 -> V_33 ) ;
break;
case V_289 :
default:
break;
}
switch ( V_85 ) {
case V_289 :
break;
case V_34 :
F_14 ( V_292 L_61 ) ;
return - V_288 ;
case V_287 :
F_14 ( V_292 L_62 , V_29 ) ;
return - V_288 ;
case V_46 :
case V_291 :
F_14 ( V_292 L_63
L_64 ,
V_29 ) ;
F_15 ( & V_25 -> V_286 -> V_33 ,
V_34 ) ;
return - V_293 ;
default:
F_14 ( V_292 L_65 , V_29 ) ;
return - V_214 ;
}
V_91 = F_72 ( sizeof( * V_91 ) , V_206 ) ;
if ( NULL == V_91 )
return - V_207 ;
V_110 -> V_122 = V_91 ;
V_91 -> V_25 = V_25 ;
V_91 -> type = V_223 ;
V_91 -> V_48 = V_48 ;
if ( ! V_48 -> V_294 ) {
V_48 -> V_18 = & V_67 [ 0 ] ;
F_57 ( V_48 , & V_48 -> V_150 ) ;
V_48 -> V_294 = 1 ;
}
F_12 ( 1 , L_66 , V_29 ,
F_101 ( V_5 ) , V_295 [ type ] ) ;
F_12 ( 2 , L_67 , V_29 ,
( unsigned long ) V_91 , ( unsigned long ) V_25 ,
( unsigned long ) & V_48 -> V_52 ) ;
F_12 ( 4 , L_68 , V_29 ,
F_25 ( & V_48 -> V_52 . V_58 ) ) ;
F_104 ( & V_91 -> V_135 , & V_296 ,
NULL , & V_25 -> V_57 ,
V_91 -> type ,
V_142 ,
sizeof( struct V_53 ) ,
V_91 , V_5 -> V_297 ) ;
return 0 ;
}
static int F_105 ( struct V_110 * V_110 )
{
struct V_4 * V_5 = F_99 ( V_110 ) ;
int V_151 ;
if ( F_106 ( V_5 -> V_297 ) )
return - V_298 ;
V_151 = F_98 ( V_110 ) ;
F_58 ( V_5 -> V_297 ) ;
return V_151 ;
}
static unsigned int F_107 ( struct V_110 * V_110 ,
struct V_299 * V_300 )
{
struct V_90 * V_91 = V_110 -> V_122 ;
struct V_1 * V_25 = V_91 -> V_25 ;
int V_56 ;
F_12 ( 100 , L_1 , V_29 ) ;
if ( V_223 != V_91 -> type )
return V_301 ;
F_55 ( & V_25 -> V_297 ) ;
V_56 = F_108 ( V_110 , & V_91 -> V_135 , V_300 ) ;
F_58 ( & V_25 -> V_297 ) ;
return V_56 ;
}
static void F_109 ( struct V_1 * V_25 )
{
F_110 ( V_25 ) ;
F_111 ( & V_25 -> V_302 ) ;
if ( V_25 -> V_286 -> V_30 ) {
F_112 ( V_25 -> V_286 -> V_30 ) ;
F_113 ( V_25 -> V_286 -> V_30 ) ;
V_25 -> V_286 -> V_30 = NULL ;
}
F_114 ( V_25 -> V_286 -> V_45 ) ;
F_74 ( V_25 -> V_286 -> V_44 ) ;
F_74 ( V_25 -> V_286 ) ;
F_8 ( V_25 ) ;
F_115 ( & V_25 -> V_297 ) ;
F_116 ( V_25 -> V_39 ) ;
F_117 ( & V_25 -> V_3 ) ;
F_12 ( 1 , L_69 , V_29 ) ;
F_74 ( V_25 ) ;
}
static int F_118 ( struct V_110 * V_110 )
{
struct V_90 * V_91 = V_110 -> V_122 ;
struct V_1 * V_25 = V_91 -> V_25 ;
struct V_4 * V_5 = F_99 ( V_110 ) ;
struct V_47 * V_48 = V_91 -> V_48 ;
if ( ! V_25 )
return - V_288 ;
F_55 ( & V_25 -> V_297 ) ;
if ( F_44 ( V_91 ) ) {
if ( V_48 -> V_230 )
F_82 ( V_91 -> V_48 ) ;
F_83 ( & V_91 -> V_135 ) ;
F_45 ( V_91 ) ;
}
F_119 ( & V_91 -> V_135 ) ;
F_58 ( & V_25 -> V_297 ) ;
F_12 ( 1 , L_70 , V_29 , F_101 ( V_5 ) ) ;
F_74 ( V_91 ) ;
return 0 ;
}
static int F_120 ( struct V_110 * V_110 , struct V_303 * V_304 )
{
struct V_90 * V_91 = V_110 -> V_122 ;
struct V_1 * V_25 ;
int V_151 ;
if ( ! V_91 )
return - V_288 ;
V_25 = V_91 -> V_25 ;
F_12 ( 4 , L_71 , V_29 , ( unsigned long ) V_304 ) ;
if ( F_106 ( & V_25 -> V_297 ) )
return - V_298 ;
V_151 = F_121 ( & V_91 -> V_135 , V_304 ) ;
F_58 ( & V_25 -> V_297 ) ;
F_12 ( 4 , L_72 , V_29 ,
( unsigned long ) V_304 -> V_305 ,
( unsigned long ) V_304 -> V_306 - ( unsigned long ) V_304 -> V_305 , V_151 ) ;
return V_151 ;
}
static void F_122 ( struct V_4 * V_5 )
{
struct V_1 * V_25 = F_1 ( V_5 -> V_3 ) ;
F_12 ( 4 , L_73 , V_29 ,
F_102 ( & V_25 -> V_307 ) ) ;
if ( F_123 ( & V_25 -> V_307 ) )
F_109 ( V_25 ) ;
return;
}
static int F_124 ( struct V_1 * V_25 )
{
int V_151 ;
int V_23 ;
int V_308 = V_309 ;
struct V_47 * V_48 ;
V_151 = F_125 ( & V_25 -> V_310 -> V_25 , & V_25 -> V_3 ) ;
if ( V_151 )
return V_151 ;
for ( V_23 = 0 ; V_23 < V_311 ; V_23 ++ ) {
V_48 = & V_25 -> V_48 [ V_23 ] ;
F_126 ( & V_48 -> V_52 . V_58 ) ;
V_48 -> V_52 . V_25 = V_25 ;
V_48 -> V_5 = V_312 ;
V_48 -> V_5 . V_297 = & V_25 -> V_297 ;
V_48 -> V_5 . V_3 = & V_25 -> V_3 ;
F_127 ( & V_48 -> V_5 , V_48 ) ;
if ( V_309 == - 1 )
V_151 = F_128 ( & V_48 -> V_5 ,
V_313 ,
V_309 ) ;
else
V_151 = F_128 ( & V_48 -> V_5 ,
V_313 ,
V_308 + V_23 ) ;
if ( V_151 ) {
F_18 ( & V_25 -> V_39 -> V_25 ,
L_74 ) ;
break;
}
F_129 ( & V_25 -> V_307 ) ;
F_130 ( & V_25 -> V_3 , L_75 ,
F_101 ( & V_48 -> V_5 ) ) ;
}
F_14 ( V_292 L_76 ,
V_314 ) ;
if ( F_102 ( & V_25 -> V_307 ) == 0 ) {
F_117 ( & V_25 -> V_3 ) ;
return V_151 ;
}
if ( F_102 ( & V_25 -> V_307 ) != V_311 )
F_14 ( V_315 L_77 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_25 , struct V_316 * V_317 )
{
char * V_318 ;
T_1 V_319 = 0 ;
int V_320 = 0 ;
char * V_321 ;
unsigned long V_322 ;
unsigned long V_22 ;
T_5 V_108 = - 1 ;
struct V_323 * V_324 ;
unsigned char * V_325 ;
struct V_47 * V_48 ;
F_12 ( 100 , L_78 ) ;
V_48 = & V_25 -> V_48 [ V_25 -> V_326 ] ;
V_108 = V_48 -> V_225 ;
V_324 = & V_48 -> V_76 . V_77 [ V_108 ] ;
if ( V_324 -> V_227 == V_228 ) {
int V_327 ;
unsigned int V_326 ;
T_2 * V_328 ;
int V_329 ;
V_325 = ( unsigned char * ) V_317 -> V_330 ;
V_328 = ( T_2 * ) V_325 ;
for ( V_327 = 0 ; V_327 < ( V_317 -> V_331 - 12 ) ; V_327 ++ ) {
switch ( * V_328 ) {
case V_332 :
F_12 ( 4 , L_79
L_80 , V_327 , V_325 [ 0 ] ,
V_325 [ 1 ] ) ;
V_319 = V_327 + V_195 ;
V_320 = 1 ;
V_326 = F_132 ( V_328 [ 1 ] ) ;
if ( V_326 >= V_311 ) {
F_14 ( V_32
L_81 ) ;
return - V_102 ;
}
V_25 -> V_326 = V_203 [ V_326 ] ;
V_48 = & V_25 -> V_48 [ V_25 -> V_326 ] ;
V_329 = F_132 ( V_328 [ 3 ] ) ;
if ( V_329 > V_48 -> V_205 ) {
V_48 -> V_224 ++ ;
return - V_102 ;
}
V_48 -> V_333 = V_329 ;
V_48 -> V_334 = F_132 ( V_328 [ 4 ] ) ;
break;
case V_335 :
V_325 += V_196 ;
V_327 += V_196 ;
if ( F_132 ( V_328 [ 1 ] ) >= V_311 )
break;
V_326 = V_203 [ F_132 ( V_328 [ 1 ] ) ] ;
if ( V_326 >= V_311 )
break;
V_48 = & V_25 -> V_48 [ V_326 ] ;
switch ( V_328 [ 2 ] ) {
case V_336 :
V_48 -> V_210 = 1 ;
F_16 ( & V_48 -> V_212 ) ;
F_12 ( 5 , L_82 , V_326 ) ;
break;
case V_337 :
V_25 -> V_338 |= ( 1 << V_326 ) ;
if ( ( V_25 -> V_338 & 0x0f ) != 0x0f )
break;
F_14 ( V_292 L_83 ) ;
F_15 ( & V_25 -> V_286 -> V_33 ,
V_289 ) ;
F_16 ( & V_25 -> V_286 -> V_35 ) ;
break;
case V_339 :
V_48 -> V_220 = F_132 ( V_328 [ 3 ] ) ;
V_48 -> V_217 = 1 ;
F_16 ( & V_48 -> V_218 ) ;
F_12 ( 5 , L_84 ,
F_132 ( V_328 [ 3 ] ) , V_326 ) ;
break;
default:
F_14 ( V_292 L_85 ) ;
}
default:
V_325 ++ ;
break;
}
if ( V_320 )
break;
}
if ( ! V_320 )
return - V_102 ;
}
V_48 = & V_25 -> V_48 [ V_25 -> V_326 ] ;
V_108 = V_48 -> V_225 ;
V_324 = & V_48 -> V_76 . V_77 [ V_108 ] ;
if ( ! V_48 -> V_230 ) {
V_324 -> V_227 = V_228 ;
return - V_102 ;
}
if ( V_324 -> V_227 == V_228 ) {
V_324 -> V_227 = V_340 ;
V_324 -> V_229 = 0 ;
}
V_321 = ( V_341 * ) V_317 -> V_330 + V_319 ;
if ( V_324 -> V_78 == NULL ) {
F_12 ( 1 , L_86 ,
V_324 , V_25 , V_25 -> V_326 , V_108 ) ;
return - V_207 ;
}
V_318 = V_324 -> V_78 + V_324 -> V_229 ;
V_322 = ( V_317 -> V_331 - V_319 ) ;
V_22 = V_48 -> V_333 - V_195 ;
if ( ( V_322 + V_324 -> V_229 ) < V_48 -> V_205 )
memcpy ( V_318 , V_321 , V_322 ) ;
V_324 -> V_229 += V_322 ;
F_12 ( 4 , L_87 , V_324 -> V_229 , V_22 ) ;
if ( V_324 -> V_229 >= V_22 ) {
F_12 ( 2 , L_88 ,
V_25 -> V_326 , V_108 ) ;
V_48 -> V_75 = V_48 -> V_225 ;
V_48 -> V_225 ++ ;
if ( ( V_48 -> V_225 == V_226 ) ||
( V_48 -> V_225 == V_48 -> V_76 . V_342 ) )
V_48 -> V_225 = 0 ;
if ( V_48 -> V_230 )
F_23 ( V_48 , V_48 -> V_334 ) ;
V_48 -> V_84 ++ ;
V_324 -> V_227 = V_228 ;
V_324 -> V_229 = 0 ;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_25 ,
struct V_316 * V_317 )
{
int V_201 ;
F_12 ( 50 , L_89 ) ;
if ( V_25 -> V_326 >= V_311 ) {
V_25 -> V_326 = 0 ;
F_18 ( & V_25 -> V_39 -> V_25 , L_90 ) ;
return;
}
V_201 = F_131 ( V_25 , V_317 ) ;
if ( V_201 != 0 )
F_12 ( 4 , L_91 ) ;
F_12 ( 50 , L_92 ) ;
return;
}
static long F_9 ( struct V_1 * V_25 , unsigned char V_343 ,
T_6 V_344 , T_6 V_345 , void * V_346 ,
T_5 V_347 , int V_348 )
{
int V_349 ;
if ( ! V_348 ) {
V_349 = F_134 ( V_25 -> V_39 , F_135 ( V_25 -> V_39 , 0 ) ,
V_343 ,
V_350 | V_351 |
V_352 ,
V_345 , V_344 , V_346 ,
V_347 , V_353 * 5 ) ;
} else {
V_349 = F_134 ( V_25 -> V_39 , F_136 ( V_25 -> V_39 , 0 ) ,
V_343 , V_350 | V_351 ,
V_345 , V_344 , V_346 ,
V_347 , V_353 * 5 ) ;
}
return V_349 ;
}
static int F_137 ( struct V_1 * V_25 )
{
int V_45 ;
int V_151 ;
unsigned char V_354 [ 64 ] ;
V_151 = F_9 ( V_25 , V_355 , 0 , 0 , V_354 , 2 ,
V_356 ) ;
if ( V_151 < 0 )
F_12 ( 2 , L_93 , V_151 ) ;
V_45 = V_354 [ 0 ] + ( V_354 [ 1 ] << 8 ) ;
F_12 ( 2 , L_94 , V_354 [ 0 ] , V_354 [ 1 ] ) ;
return V_45 ;
}
static int F_138 ( struct V_47 * V_48 )
{
unsigned long V_23 ;
unsigned long V_357 ;
F_12 ( 1 , L_95 ) ;
V_48 -> V_76 . V_342 = V_226 ;
V_357 = V_358 ;
if ( V_357 > V_358 )
V_357 = V_358 ;
for ( V_23 = 0 ; V_23 < V_226 ; V_23 ++ ) {
V_48 -> V_76 . V_77 [ V_23 ] . V_78 = F_139 ( V_357 ) ;
F_12 ( 1 , L_96 ,
& V_48 -> V_76 . V_77 [ V_23 ] , V_48 -> V_108 , V_23 ,
V_48 -> V_76 . V_77 [ V_23 ] . V_78 ) ;
V_48 -> V_76 . V_77 [ V_23 ] . V_22 = V_357 ;
if ( V_48 -> V_76 . V_77 [ V_23 ] . V_78 == NULL ) {
F_14 ( V_292 L_97 ) ;
V_48 -> V_76 . V_342 = V_23 ;
break;
}
}
for ( V_23 = 0 ; V_23 < V_226 ; V_23 ++ ) {
V_48 -> V_76 . V_77 [ V_23 ] . V_227 = 0 ;
V_48 -> V_76 . V_77 [ V_23 ] . V_229 = 0 ;
}
V_48 -> V_225 = 0 ;
V_48 -> V_75 = - 1 ;
return 0 ;
}
static int F_140 ( struct V_47 * V_48 )
{
unsigned long V_23 ;
F_12 ( 1 , L_98 ) ;
for ( V_23 = 0 ; V_23 < V_226 ; V_23 ++ ) {
if ( V_48 -> V_76 . V_77 [ V_23 ] . V_78 ) {
F_12 ( 1 , L_99 ,
V_48 -> V_76 . V_77 [ V_23 ] . V_78 ) ;
F_141 ( V_48 -> V_76 . V_77 [ V_23 ] . V_78 ) ;
}
V_48 -> V_76 . V_77 [ V_23 ] . V_78 = NULL ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_25 )
{
struct V_149 V_359 = V_360 ;
int V_361 ;
int V_222 ;
struct V_316 * V_179 = & V_25 -> V_179 ;
F_12 ( 4 , L_100 , V_25 ) ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_179 -> V_25 = V_25 ;
V_179 -> V_331 = V_362 ;
V_179 -> V_363 = V_362 ;
V_179 -> V_330 = F_72 ( V_179 -> V_363 ,
V_206 ) ;
if ( V_179 -> V_330 == NULL ) {
F_12 ( 1 , L_101 ) ;
return - V_207 ;
}
V_361 = F_137 ( V_25 ) ;
F_14 ( V_292 L_102 ,
( V_361 >> 8 ) & 0xff ,
V_361 & 0xff ) ;
if ( V_361 < V_364 )
F_14 ( V_292 L_103 ) ;
for ( V_222 = 0 ; V_222 < V_311 ; V_222 ++ ) {
struct V_47 * V_48 = & V_25 -> V_48 [ V_222 ] ;
V_48 -> V_230 = 0 ;
V_48 -> V_150 = V_359 ;
if ( V_25 -> V_242 == 0x2257 && V_222 > 1 )
V_48 -> V_150 . V_163 |= ( 1 << 16 ) ;
V_48 -> V_167 . V_168 = V_365 ;
V_48 -> V_16 = V_8 ;
V_48 -> V_17 = V_190 * 2 ;
V_48 -> V_18 = & V_67 [ 0 ] ;
V_48 -> V_150 . V_171 = 1 ;
V_48 -> V_205 = F_69 ( & V_359 ) ;
V_48 -> V_84 = 0 ;
F_138 ( V_48 ) ;
}
F_143 ( V_25 ) ;
F_12 ( 1 , L_104 , V_29 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_25 )
{
T_1 V_23 ;
F_12 ( 1 , L_105 , V_29 , V_25 ) ;
for ( V_23 = 0 ; V_23 < V_311 ; V_23 ++ ) {
if ( V_25 -> V_48 [ V_23 ] . V_230 )
F_82 ( & V_25 -> V_48 [ V_23 ] ) ;
}
F_144 ( V_25 ) ;
for ( V_23 = 0 ; V_23 < V_311 ; V_23 ++ )
F_140 ( & V_25 -> V_48 [ V_23 ] ) ;
F_74 ( V_25 -> V_179 . V_330 ) ;
return 0 ;
}
static void F_145 ( struct V_36 * V_366 )
{
struct V_316 * V_317 ;
struct V_1 * V_25 ;
int V_41 ;
int V_179 ;
V_317 = V_366 -> V_37 ;
F_12 ( 100 , L_106 , V_29 , V_366 ,
V_366 -> V_41 ) ;
if ( V_317 == NULL ) {
F_18 ( & V_366 -> V_25 -> V_25 , L_107 ) ;
return;
}
V_25 = V_317 -> V_25 ;
if ( V_25 == NULL ) {
F_18 ( & V_366 -> V_25 -> V_25 , L_107 ) ;
return;
}
V_41 = V_366 -> V_41 ;
if ( V_41 == - V_367 ) {
F_12 ( 2 , L_108 , V_29 ) ;
V_317 -> V_368 ++ ;
return;
}
if ( V_317 -> V_85 == 0 ) {
F_12 ( 2 , L_109 , V_29 ) ;
return;
}
if ( V_41 == 0 )
F_133 ( V_25 , V_317 ) ;
else {
V_317 -> V_368 ++ ;
F_12 ( 1 , L_110 , V_29 , V_41 ) ;
}
V_179 = F_146 ( V_25 -> V_39 , V_25 -> V_369 ) ;
F_21 ( V_317 -> V_370 , V_25 -> V_39 ,
V_179 ,
V_317 -> V_330 ,
V_317 -> V_331 ,
F_145 , V_317 ) ;
if ( V_317 -> V_85 != 0 ) {
if ( F_13 ( V_317 -> V_370 , V_31 ) ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_111 ) ;
}
} else {
F_12 ( 2 , L_112 , V_29 ) ;
}
return;
}
static int F_143 ( struct V_1 * V_25 )
{
int V_179 ;
int V_180 ;
struct V_316 * V_317 = & V_25 -> V_179 ;
V_179 = F_146 ( V_25 -> V_39 , V_25 -> V_369 ) ;
F_12 ( 2 , L_113 , V_29 , V_25 -> V_369 ) ;
V_317 -> V_85 = 1 ;
V_317 -> V_368 = 0 ;
V_317 -> V_370 = F_147 ( 0 , V_206 ) ;
if ( ! V_317 -> V_370 ) {
F_18 ( & V_25 -> V_39 -> V_25 ,
L_114 ) ;
return - V_207 ;
}
F_21 ( V_317 -> V_370 , V_25 -> V_39 ,
V_179 ,
V_317 -> V_330 ,
V_317 -> V_331 ,
F_145 , V_317 ) ;
V_180 = F_13 ( V_317 -> V_370 , V_206 ) ;
if ( V_180 ) {
F_14 ( V_32 L_115 ) ;
return V_180 ;
}
return 0 ;
}
static int F_80 ( struct V_47 * V_48 )
{
unsigned char * V_76 ;
int V_201 ;
unsigned long V_202 ;
int V_222 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_202 = V_203 [ V_48 -> V_108 ] ;
V_76 = F_72 ( 512 , V_206 ) ;
if ( V_76 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_207 ;
}
V_48 -> V_75 = - 1 ;
V_48 -> V_224 = 0 ;
V_48 -> V_225 = 0 ;
for ( V_222 = 0 ; V_222 < V_226 ; V_222 ++ ) {
V_48 -> V_76 . V_77 [ V_222 ] . V_227 = 0 ;
V_48 -> V_76 . V_77 [ V_222 ] . V_229 = 0 ;
}
* ( T_2 * ) V_76 = V_208 ;
* ( ( T_2 * ) V_76 + 1 ) = ( T_2 ) F_73 ( V_202 ) ;
* ( ( T_2 * ) V_76 + 2 ) = V_371 ;
V_201 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_76 , 512 ) ;
if ( V_201 != 0 )
F_18 ( & V_25 -> V_39 -> V_25 , L_116 ) ;
F_12 ( 2 , L_117 , V_48 -> V_108 , V_201 ) ;
F_74 ( V_76 ) ;
return 0 ;
}
static int F_82 ( struct V_47 * V_48 )
{
unsigned char * V_76 ;
int V_201 ;
unsigned long V_202 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_202 = V_203 [ V_48 -> V_108 ] ;
V_76 = F_72 ( 512 , V_206 ) ;
if ( V_76 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_207 ;
}
* ( T_2 * ) V_76 = V_208 ;
* ( ( T_2 * ) V_76 + 1 ) = ( T_2 ) F_73 ( V_202 ) ;
* ( ( T_2 * ) V_76 + 2 ) = V_372 ;
V_201 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_76 , 512 ) ;
if ( V_201 != 0 )
F_18 ( & V_25 -> V_39 -> V_25 , L_118 ) ;
F_74 ( V_76 ) ;
V_48 -> V_230 = 0 ;
F_12 ( 4 , L_119 , V_29 , V_48 -> V_108 , V_201 ) ;
return V_201 ;
}
static void F_144 ( struct V_1 * V_25 )
{
struct V_316 * V_179 = & V_25 -> V_179 ;
V_179 -> V_85 = 0 ;
if ( V_179 -> V_370 ) {
F_112 ( V_179 -> V_370 ) ;
F_113 ( V_179 -> V_370 ) ;
V_179 -> V_370 = NULL ;
}
F_12 ( 4 , L_69 , V_29 ) ;
return;
}
static void F_103 ( struct V_1 * V_25 , int V_373 )
{
if ( V_373 )
F_8 ( V_25 ) ;
V_25 -> V_286 -> V_43 = V_25 -> V_286 -> V_45 -> V_22 ;
F_15 ( & V_25 -> V_286 -> V_33 , V_291 ) ;
memcpy ( V_25 -> V_286 -> V_44 ,
V_25 -> V_286 -> V_45 -> V_28 , F_20 ) ;
V_25 -> V_286 -> V_42 = F_20 ;
F_21 ( V_25 -> V_286 -> V_30 , V_25 -> V_39 ,
F_22 ( V_25 -> V_39 , 2 ) ,
V_25 -> V_286 -> V_44 ,
F_20 , F_17 ,
V_25 -> V_286 ) ;
F_148 ( & V_25 -> V_302 , V_374 + V_353 ) ;
}
static int F_149 ( struct V_375 * V_310 ,
const struct V_376 * V_115 )
{
struct V_1 * V_25 = NULL ;
struct V_377 * V_378 ;
struct V_379 * V_380 ;
int V_23 ;
int V_180 = - V_207 ;
T_2 * V_325 ;
int V_43 ;
F_12 ( 2 , L_1 , V_29 ) ;
V_25 = F_72 ( sizeof( struct V_1 ) , V_206 ) ;
if ( V_25 == NULL ) {
F_19 ( & V_310 -> V_25 , L_120 ) ;
return - V_207 ;
}
F_15 ( & V_25 -> V_307 , 0 ) ;
V_25 -> V_242 = V_115 -> V_381 ;
V_25 -> V_286 = F_72 ( sizeof( struct V_27 ) , V_206 ) ;
if ( ! V_25 -> V_286 )
goto V_382;
F_150 ( & V_25 -> V_297 ) ;
V_25 -> V_39 = F_151 ( F_152 ( V_310 ) ) ;
if ( V_25 -> V_39 == NULL ) {
F_18 ( & V_310 -> V_25 , L_121 ) ;
V_180 = - V_288 ;
goto V_383;
}
F_12 ( 1 , L_122 , V_25 ,
V_25 -> V_39 , V_310 ) ;
V_25 -> V_310 = V_310 ;
V_378 = V_310 -> V_384 ;
F_12 ( 1 , L_123 , V_378 -> V_385 . V_386 ) ;
for ( V_23 = 0 ; V_23 < V_378 -> V_385 . V_386 ; ++ V_23 ) {
V_380 = & V_378 -> V_380 [ V_23 ] . V_385 ;
if ( ! V_25 -> V_369 && F_153 ( V_380 ) ) {
V_25 -> V_369 = V_380 -> V_387 ;
}
}
if ( ! V_25 -> V_369 ) {
F_18 ( & V_310 -> V_25 , L_124 ) ;
goto V_388;
}
F_154 ( & V_25 -> V_302 ) ;
V_25 -> V_302 . V_389 = F_11 ;
V_25 -> V_302 . V_28 = ( unsigned long ) V_25 -> V_286 ;
F_155 ( & V_25 -> V_286 -> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_311 ; V_23 ++ ) {
struct V_47 * V_48 = & V_25 -> V_48 [ V_23 ] ;
V_25 -> V_48 [ V_23 ] . V_108 = V_23 ;
F_155 ( & V_48 -> V_212 ) ;
F_155 ( & V_48 -> V_218 ) ;
}
V_25 -> V_286 -> V_30 = F_147 ( 0 , V_206 ) ;
if ( ! V_25 -> V_286 -> V_30 ) {
F_18 ( & V_310 -> V_25 , L_101 ) ;
goto V_390;
}
V_25 -> V_286 -> V_44 = F_72 ( F_20 , V_206 ) ;
if ( ! V_25 -> V_286 -> V_44 ) {
F_18 ( & V_310 -> V_25 , L_101 ) ;
goto V_391;
}
if ( F_156 ( & V_25 -> V_286 -> V_45 ,
V_392 , & V_25 -> V_39 -> V_25 ) ) {
F_14 ( V_32 L_125 ) ;
goto V_393;
}
V_43 = V_25 -> V_286 -> V_45 -> V_22 ;
V_325 = ( T_2 * ) & V_25 -> V_286 -> V_45 -> V_28 [ V_43 - 8 ] ;
if ( * V_325 != V_394 ) {
F_14 ( V_292 L_126 ) ;
V_180 = - V_288 ;
goto V_395;
} else {
T_2 * V_396 ;
V_396 = ( T_2 * ) & V_25 -> V_286 -> V_45 -> V_28 [ V_43 - 4 ] ;
F_14 ( V_292 L_127 , * V_396 ) ;
V_25 -> V_239 = F_132 ( * V_396 ) ;
if ( V_25 -> V_239 < V_397 )
F_14 ( V_292 L_128 ) ;
if ( V_25 -> V_242 == 0x2257 &&
V_25 -> V_239 < V_253 )
F_14 ( V_315 L_129
L_130 , V_253 ) ;
}
F_157 ( V_25 -> V_39 ) ;
V_180 = F_142 ( V_25 ) ;
if ( V_180 )
goto V_398;
F_158 ( & V_25 -> V_57 ) ;
F_103 ( V_25 , 0 ) ;
V_180 = F_124 ( V_25 ) ;
if ( V_180 )
goto V_398;
F_71 ( & V_310 -> V_25 , L_131 ) ;
return 0 ;
V_398:
F_110 ( V_25 ) ;
V_395:
F_114 ( V_25 -> V_286 -> V_45 ) ;
V_393:
F_74 ( V_25 -> V_286 -> V_44 ) ;
V_391:
F_113 ( V_25 -> V_286 -> V_30 ) ;
V_390:
F_111 ( & V_25 -> V_302 ) ;
V_388:
F_116 ( V_25 -> V_39 ) ;
V_383:
F_74 ( V_25 -> V_286 ) ;
F_115 ( & V_25 -> V_297 ) ;
V_382:
F_74 ( V_25 ) ;
F_14 ( V_315 L_132 , V_180 ) ;
return V_180 ;
}
static void F_159 ( struct V_375 * V_310 )
{
struct V_1 * V_25 = F_1 ( F_160 ( V_310 ) ) ;
int V_23 ;
int V_399 = F_102 ( & V_25 -> V_307 ) ;
F_55 ( & V_25 -> V_297 ) ;
F_161 ( & V_25 -> V_3 ) ;
F_58 ( & V_25 -> V_297 ) ;
F_129 ( & V_25 -> V_307 ) ;
for ( V_23 = 0 ; V_23 < V_399 ; V_23 ++ )
F_162 ( & V_25 -> V_48 [ V_23 ] . V_5 ) ;
F_15 ( & V_25 -> V_286 -> V_33 , V_287 ) ;
F_16 ( & V_25 -> V_286 -> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_311 ; V_23 ++ ) {
V_25 -> V_48 [ V_23 ] . V_210 = 1 ;
F_16 ( & V_25 -> V_48 [ V_23 ] . V_212 ) ;
V_25 -> V_48 [ V_23 ] . V_217 = 1 ;
F_16 ( & V_25 -> V_48 [ V_23 ] . V_218 ) ;
}
if ( F_123 ( & V_25 -> V_307 ) )
F_109 ( V_25 ) ;
F_71 ( & V_310 -> V_25 , L_1 , V_29 ) ;
}
