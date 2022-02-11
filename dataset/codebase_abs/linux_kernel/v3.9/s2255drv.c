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
const char * V_72 ;
char * V_73 = F_33 ( & V_54 -> V_61 ) ;
unsigned long V_74 ;
if ( ! V_73 )
return;
V_74 = V_48 -> V_74 ;
if ( V_74 != - 1 ) {
V_72 =
( const char * ) V_48 -> V_75 . V_76 [ V_74 ] . V_77 ;
switch ( V_54 -> V_18 -> V_66 ) {
case V_24 :
case V_78 :
F_7 ( ( const unsigned char * ) V_72 ,
V_73 , V_54 -> V_61 . V_16 ,
V_54 -> V_61 . V_17 ,
V_54 -> V_18 -> V_66 ) ;
break;
case V_79 :
memcpy ( V_73 , V_72 , V_54 -> V_61 . V_16 * V_54 -> V_61 . V_17 ) ;
break;
case V_69 :
case V_70 :
V_54 -> V_61 . V_22 = V_49 ;
memcpy ( V_73 , V_72 , V_54 -> V_61 . V_22 ) ;
break;
case V_80 :
memcpy ( V_73 , V_72 ,
V_54 -> V_61 . V_16 * V_54 -> V_61 . V_17 * 2 ) ;
break;
default:
F_14 ( V_81 L_11 ) ;
}
V_48 -> V_74 = - 1 ;
} else {
F_14 ( V_32 L_12 ) ;
return;
}
F_12 ( 2 , L_13 ,
( unsigned long ) V_73 , V_71 ) ;
V_54 -> V_61 . V_82 = V_48 -> V_83 * 2 ;
F_28 ( & V_54 -> V_61 . V_63 ) ;
V_54 -> V_61 . V_84 = V_85 ;
}
static int F_34 ( struct V_86 * V_87 , unsigned int * V_88 ,
unsigned int * V_22 )
{
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_47 * V_48 = V_90 -> V_48 ;
* V_22 = V_48 -> V_16 * V_48 -> V_17 * ( V_48 -> V_18 -> V_92 >> 3 ) ;
if ( 0 == * V_88 )
* V_88 = V_93 ;
if ( * V_22 * * V_88 > V_94 * 1024 * 1024 )
* V_88 = ( V_94 * 1024 * 1024 ) / * V_22 ;
return 0 ;
}
static void F_35 ( struct V_86 * V_87 , struct V_53 * V_54 )
{
F_12 ( 4 , L_1 , V_29 ) ;
F_36 ( & V_54 -> V_61 ) ;
V_54 -> V_61 . V_84 = V_95 ;
}
static int F_37 ( struct V_86 * V_87 , struct V_96 * V_61 ,
enum V_97 V_98 )
{
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_47 * V_48 = V_90 -> V_48 ;
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
int V_56 ;
int V_99 = V_48 -> V_16 ;
int V_100 = V_48 -> V_17 ;
F_12 ( 4 , L_14 , V_29 , V_98 ) ;
if ( V_48 -> V_18 == NULL )
return - V_101 ;
if ( ( V_99 < F_5 ( & V_48 -> V_5 ) ) ||
( V_99 > F_3 ( & V_48 -> V_5 ) ) ||
( V_100 < F_6 ( & V_48 -> V_5 ) ) ||
( V_100 > F_4 ( & V_48 -> V_5 ) ) ) {
F_12 ( 4 , L_15 ) ;
return - V_101 ;
}
V_54 -> V_61 . V_22 = V_99 * V_100 * ( V_48 -> V_18 -> V_92 >> 3 ) ;
if ( 0 != V_54 -> V_61 . V_102 && V_54 -> V_61 . V_103 < V_54 -> V_61 . V_22 ) {
F_12 ( 4 , L_15 ) ;
return - V_101 ;
}
V_54 -> V_18 = V_48 -> V_18 ;
V_54 -> V_61 . V_16 = V_99 ;
V_54 -> V_61 . V_17 = V_100 ;
V_54 -> V_61 . V_98 = V_98 ;
if ( V_95 == V_54 -> V_61 . V_84 ) {
V_56 = F_38 ( V_87 , & V_54 -> V_61 , NULL ) ;
if ( V_56 < 0 )
goto V_104;
}
V_54 -> V_61 . V_84 = V_105 ;
return 0 ;
V_104:
F_35 ( V_87 , V_54 ) ;
return V_56 ;
}
static void F_39 ( struct V_86 * V_87 , struct V_96 * V_61 )
{
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_47 * V_48 = V_90 -> V_48 ;
struct V_50 * V_52 = & V_48 -> V_52 ;
F_12 ( 1 , L_1 , V_29 ) ;
V_54 -> V_61 . V_84 = V_106 ;
F_40 ( & V_54 -> V_61 . V_62 , & V_52 -> V_58 ) ;
}
static void F_41 ( struct V_86 * V_87 ,
struct V_96 * V_61 )
{
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
struct V_89 * V_90 = V_87 -> V_91 ;
F_12 ( 4 , L_16 , V_29 , V_90 -> V_48 -> V_107 ) ;
F_35 ( V_87 , V_54 ) ;
}
static int F_42 ( struct V_89 * V_90 )
{
struct V_47 * V_48 = V_90 -> V_48 ;
if ( V_48 -> V_108 )
return 0 ;
V_48 -> V_108 = 1 ;
V_90 -> V_108 = 1 ;
F_12 ( 1 , L_17 ) ;
return 1 ;
}
static int F_43 ( struct V_89 * V_90 )
{
return V_90 -> V_48 -> V_108 ;
}
static int F_44 ( struct V_89 * V_90 )
{
return V_90 -> V_108 ;
}
static void F_45 ( struct V_89 * V_90 )
{
struct V_47 * V_48 = V_90 -> V_48 ;
V_48 -> V_108 = 0 ;
V_90 -> V_108 = 0 ;
F_12 ( 1 , L_18 ) ;
}
static int F_46 ( struct V_109 * V_109 , void * V_110 ,
struct V_111 * V_112 )
{
static const char * V_113 [] = {
L_19 ,
L_20 ,
NULL
} ;
if ( V_112 -> V_114 == V_115 ) {
int V_23 ;
const char * * V_116 = V_113 ;
for ( V_23 = 0 ; V_23 < V_112 -> V_117 && V_116 [ V_23 ] ; V_23 ++ )
;
if ( V_116 [ V_23 ] == NULL || V_116 [ V_23 ] [ 0 ] == '\0' )
return - V_101 ;
F_47 ( V_112 -> V_118 , V_116 [ V_112 -> V_117 ] ,
sizeof( V_112 -> V_118 ) ) ;
return 0 ;
}
return F_48 ( V_112 , NULL , NULL ) ;
}
static int F_49 ( struct V_109 * V_109 , void * V_110 ,
struct V_119 * V_120 )
{
struct V_89 * V_90 = V_109 -> V_121 ;
struct V_1 * V_25 = V_90 -> V_25 ;
F_47 ( V_120 -> V_122 , L_21 , sizeof( V_120 -> V_122 ) ) ;
F_47 ( V_120 -> V_123 , L_21 , sizeof( V_120 -> V_123 ) ) ;
F_50 ( V_25 -> V_39 , V_120 -> V_124 , sizeof( V_120 -> V_124 ) ) ;
V_120 -> V_125 = V_126 | V_127 ;
return 0 ;
}
static int F_51 ( struct V_109 * V_109 , void * V_110 ,
struct V_128 * V_129 )
{
int V_117 = V_129 -> V_117 ;
if ( V_117 >= F_32 ( V_67 ) )
return - V_101 ;
if ( ! V_68 && ( ( V_67 [ V_117 ] . V_66 == V_69 ) ||
( V_67 [ V_117 ] . V_66 == V_70 ) ) )
return - V_101 ;
F_12 ( 4 , L_22 , V_67 [ V_117 ] . V_118 ) ;
F_47 ( V_129 -> V_130 , V_67 [ V_117 ] . V_118 , sizeof( V_129 -> V_130 ) ) ;
V_129 -> V_131 = V_67 [ V_117 ] . V_66 ;
return 0 ;
}
static int F_52 ( struct V_109 * V_109 , void * V_110 ,
struct V_132 * V_129 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
V_129 -> V_18 . V_133 . V_16 = V_48 -> V_16 ;
V_129 -> V_18 . V_133 . V_17 = V_48 -> V_17 ;
V_129 -> V_18 . V_133 . V_98 = V_90 -> V_134 . V_98 ;
V_129 -> V_18 . V_133 . V_131 = V_48 -> V_18 -> V_66 ;
V_129 -> V_18 . V_133 . V_135 = V_129 -> V_18 . V_133 . V_16 * ( V_48 -> V_18 -> V_92 >> 3 ) ;
V_129 -> V_18 . V_133 . V_136 = V_129 -> V_18 . V_133 . V_17 * V_129 -> V_18 . V_133 . V_135 ;
return 0 ;
}
static int F_53 ( struct V_109 * V_109 , void * V_110 ,
struct V_132 * V_129 )
{
const struct V_65 * V_18 ;
enum V_97 V_98 ;
int V_137 = 0 ;
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
int V_138 ;
V_138 =
( V_48 -> V_5 . V_6 & V_7 ) ? 1 : 0 ;
V_18 = F_31 ( V_129 -> V_18 . V_133 . V_131 ) ;
if ( V_18 == NULL )
return - V_101 ;
V_98 = V_129 -> V_18 . V_133 . V_98 ;
if ( V_98 == V_139 )
V_137 = 1 ;
F_12 ( 50 , L_23 ,
V_29 , V_138 , V_129 -> V_18 . V_133 . V_16 , V_129 -> V_18 . V_133 . V_17 ) ;
if ( V_138 ) {
if ( V_129 -> V_18 . V_133 . V_17 >= V_10 * 2 ) {
V_129 -> V_18 . V_133 . V_17 = V_10 * 2 ;
if ( V_137 ) {
V_98 = V_140 ;
} else if ( ! ( ( V_98 == V_141 ) ||
( V_98 == V_140 ) ||
( V_98 == V_142 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_101 ;
}
} else {
V_129 -> V_18 . V_133 . V_17 = V_10 ;
if ( V_137 ) {
V_98 = V_143 ;
} else if ( ! ( ( V_98 == V_143 ) ||
( V_98 == V_144 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_101 ;
}
}
if ( V_129 -> V_18 . V_133 . V_16 >= V_8 )
V_129 -> V_18 . V_133 . V_16 = V_8 ;
else if ( V_129 -> V_18 . V_133 . V_16 >= V_145 )
V_129 -> V_18 . V_133 . V_16 = V_145 ;
else if ( V_129 -> V_18 . V_133 . V_16 >= V_12 )
V_129 -> V_18 . V_133 . V_16 = V_12 ;
else
V_129 -> V_18 . V_133 . V_16 = V_12 ;
} else {
if ( V_129 -> V_18 . V_133 . V_17 >= V_11 * 2 ) {
V_129 -> V_18 . V_133 . V_17 = V_11 * 2 ;
if ( V_137 ) {
V_98 = V_140 ;
} else if ( ! ( ( V_98 == V_141 ) ||
( V_98 == V_140 ) ||
( V_98 == V_142 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_101 ;
}
} else {
V_129 -> V_18 . V_133 . V_17 = V_11 ;
if ( V_137 ) {
V_98 = V_143 ;
} else if ( ! ( ( V_98 == V_143 ) ||
( V_98 == V_144 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_101 ;
}
}
if ( V_129 -> V_18 . V_133 . V_16 >= V_9 ) {
V_129 -> V_18 . V_133 . V_16 = V_9 ;
V_98 = V_140 ;
} else if ( V_129 -> V_18 . V_133 . V_16 >= V_146 ) {
V_129 -> V_18 . V_133 . V_16 = V_146 ;
V_98 = V_143 ;
} else if ( V_129 -> V_18 . V_133 . V_16 >= V_13 ) {
V_129 -> V_18 . V_133 . V_16 = V_13 ;
V_98 = V_143 ;
} else {
V_129 -> V_18 . V_133 . V_16 = V_13 ;
V_98 = V_143 ;
}
}
V_129 -> V_18 . V_133 . V_98 = V_98 ;
V_129 -> V_18 . V_133 . V_135 = ( V_129 -> V_18 . V_133 . V_16 * V_18 -> V_92 ) >> 3 ;
V_129 -> V_18 . V_133 . V_136 = V_129 -> V_18 . V_133 . V_17 * V_129 -> V_18 . V_133 . V_135 ;
F_12 ( 50 , L_25 , V_29 ,
V_129 -> V_18 . V_133 . V_16 , V_129 -> V_18 . V_133 . V_17 , V_129 -> V_18 . V_133 . V_98 ) ;
return 0 ;
}
static int F_54 ( struct V_109 * V_109 , void * V_110 ,
struct V_132 * V_129 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
const struct V_65 * V_18 ;
struct V_86 * V_147 = & V_90 -> V_134 ;
struct V_148 V_149 ;
int V_150 ;
V_150 = F_53 ( V_109 , V_90 , V_129 ) ;
if ( V_150 < 0 )
return V_150 ;
V_18 = F_31 ( V_129 -> V_18 . V_133 . V_131 ) ;
if ( V_18 == NULL )
return - V_101 ;
F_55 ( & V_147 -> V_151 ) ;
if ( F_56 ( & V_90 -> V_134 ) ) {
F_12 ( 1 , L_26 ) ;
V_150 = - V_152 ;
goto V_153;
}
if ( F_43 ( V_90 ) ) {
F_12 ( 1 , L_27 , V_29 ) ;
V_150 = - V_152 ;
goto V_153;
}
V_149 = V_48 -> V_149 ;
V_48 -> V_18 = V_18 ;
V_48 -> V_16 = V_129 -> V_18 . V_133 . V_16 ;
V_48 -> V_17 = V_129 -> V_18 . V_133 . V_17 ;
V_90 -> V_134 . V_98 = V_129 -> V_18 . V_133 . V_98 ;
V_90 -> type = V_129 -> type ;
if ( V_48 -> V_16 > F_5 ( & V_48 -> V_5 ) ) {
if ( V_48 -> V_17 > F_6 ( & V_48 -> V_5 ) ) {
if ( V_48 -> V_154 . V_155 &
V_156 )
V_149 . V_157 = V_158 ;
else
V_149 . V_157 = V_159 ;
} else
V_149 . V_157 = V_160 ;
} else {
V_149 . V_157 = V_161 ;
}
switch ( V_48 -> V_18 -> V_66 ) {
case V_79 :
V_149 . V_162 &= ~ V_163 ;
V_149 . V_162 |= V_164 ;
break;
case V_69 :
case V_70 :
V_149 . V_162 &= ~ V_163 ;
V_149 . V_162 |= V_165 ;
V_149 . V_162 |= ( V_48 -> V_166 . V_167 << 8 ) ;
break;
case V_80 :
V_149 . V_162 &= ~ V_163 ;
V_149 . V_162 |= V_168 ;
break;
case V_24 :
case V_78 :
default:
V_149 . V_162 &= ~ V_163 ;
V_149 . V_162 |= V_169 ;
break;
}
if ( ( V_149 . V_162 & V_163 ) != ( V_48 -> V_149 . V_162 & V_163 ) )
V_149 . V_170 = 1 ;
else if ( V_149 . V_157 != V_48 -> V_149 . V_157 )
V_149 . V_170 = 1 ;
else if ( V_149 . V_171 != V_48 -> V_149 . V_171 )
V_149 . V_170 = 1 ;
V_48 -> V_149 = V_149 ;
( void ) F_57 ( V_48 , & V_149 ) ;
V_150 = 0 ;
V_153:
F_58 ( & V_147 -> V_151 ) ;
return V_150 ;
}
static int F_59 ( struct V_109 * V_109 , void * V_110 ,
struct V_172 * V_173 )
{
int V_56 ;
struct V_89 * V_90 = V_110 ;
V_56 = F_60 ( & V_90 -> V_134 , V_173 ) ;
return V_56 ;
}
static int F_61 ( struct V_109 * V_109 , void * V_110 , struct V_174 * V_173 )
{
int V_56 ;
struct V_89 * V_90 = V_110 ;
V_56 = F_62 ( & V_90 -> V_134 , V_173 ) ;
return V_56 ;
}
static int F_63 ( struct V_109 * V_109 , void * V_110 , struct V_174 * V_173 )
{
int V_56 ;
struct V_89 * V_90 = V_110 ;
V_56 = F_64 ( & V_90 -> V_134 , V_173 ) ;
return V_56 ;
}
static int F_65 ( struct V_109 * V_109 , void * V_110 , struct V_174 * V_173 )
{
int V_56 ;
struct V_89 * V_90 = V_110 ;
V_56 = F_66 ( & V_90 -> V_134 , V_173 , V_109 -> V_175 & V_176 ) ;
return V_56 ;
}
static int F_67 ( struct V_38 * V_39 , unsigned char * V_177 ,
int V_22 )
{
int V_178 ;
int V_64 ;
long V_179 = - 1 ;
if ( V_39 ) {
V_178 = F_22 ( V_39 , V_180 ) ;
V_179 = F_68 ( V_39 , V_178 , V_177 , V_22 , & V_64 , 500 ) ;
}
return V_179 ;
}
static T_1 F_69 ( struct V_148 * V_149 )
{
int V_181 = V_182 ;
int V_183 = V_184 ;
T_1 V_185 ;
T_1 V_186 ;
unsigned int V_187 ;
if ( V_149 == NULL )
return 0 ;
if ( V_149 -> V_171 == V_188 ) {
switch ( V_149 -> V_157 ) {
case V_159 :
case V_158 :
V_181 = V_189 * 2 ;
V_183 = V_8 ;
break;
case V_160 :
V_181 = V_190 ;
V_183 = V_145 ;
break;
case V_161 :
V_181 = V_10 ;
V_183 = V_12 ;
break;
default:
break;
}
} else if ( V_149 -> V_171 == V_191 ) {
switch ( V_149 -> V_157 ) {
case V_159 :
case V_158 :
V_181 = V_192 * 2 ;
V_183 = V_9 ;
break;
case V_160 :
V_181 = V_193 ;
V_183 = V_146 ;
break;
case V_161 :
V_181 = V_11 ;
V_183 = V_13 ;
break;
default:
break;
}
}
V_185 = V_181 * V_183 ;
if ( ( V_149 -> V_162 & V_163 ) != V_164 ) {
V_185 *= 2 ;
}
V_186 = V_185 + V_194 ;
V_187 = 0xffffffffUL - V_195 + 1 ;
if ( V_186 & ~ V_187 )
V_186 = ( V_186 & V_187 ) + ( V_195 ) ;
return V_186 ;
}
static void F_70 ( struct V_1 * V_196 , struct V_148 * V_149 )
{
struct V_197 * V_25 = & V_196 -> V_39 -> V_25 ;
F_71 ( V_25 , L_28 ) ;
F_71 ( V_25 , L_29 , V_149 -> V_171 , V_149 -> V_157 ) ;
F_71 ( V_25 , L_30 , V_149 -> V_198 , V_149 -> V_162 ) ;
F_71 ( V_25 , L_31 , V_149 -> V_199 ) ;
F_71 ( V_25 , L_28 ) ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_148 * V_149 )
{
int V_200 ;
T_2 * V_75 ;
unsigned long V_201 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_201 = V_202 [ V_48 -> V_107 ] ;
F_12 ( 3 , L_32 , V_29 , V_48 -> V_107 ) ;
if ( ( V_149 -> V_162 & V_163 ) == V_165 ) {
V_149 -> V_162 &= ~ V_163 ;
V_149 -> V_162 |= V_165 ;
V_149 -> V_162 &= ~ V_203 ;
V_149 -> V_162 |= ( V_48 -> V_166 . V_167 << 8 ) ;
}
V_48 -> V_149 = * V_149 ;
V_48 -> V_204 = F_69 ( V_149 ) ;
F_12 ( 1 , L_33 , V_29 , V_48 -> V_204 ) ;
V_75 = F_72 ( 512 , V_205 ) ;
if ( V_75 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_206 ;
}
V_75 [ 0 ] = V_207 ;
V_75 [ 1 ] = ( T_2 ) F_73 ( V_201 ) ;
V_75 [ 2 ] = V_208 ;
memcpy ( & V_75 [ 3 ] , & V_48 -> V_149 , sizeof( struct V_148 ) ) ;
V_48 -> V_209 = 0 ;
V_200 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_75 , 512 ) ;
if ( V_210 )
F_70 ( V_25 , V_149 ) ;
F_74 ( V_75 ) ;
if ( V_149 -> V_170 ) {
F_75 ( V_48 -> V_211 ,
( V_48 -> V_209 != 0 ) ,
F_76 ( V_212 ) ) ;
if ( V_48 -> V_209 != 1 ) {
F_14 ( V_81 L_35 ) ;
V_200 = - V_213 ;
}
}
V_48 -> V_149 . V_170 = 0 ;
F_12 ( 1 , L_36 , V_29 , V_48 -> V_107 , V_200 ) ;
return V_200 ;
}
static int F_77 ( struct V_47 * V_48 , T_1 * V_214 )
{
int V_200 ;
T_2 * V_75 ;
T_1 V_201 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_201 = V_202 [ V_48 -> V_107 ] ;
F_12 ( 4 , L_37 , V_29 , V_48 -> V_107 ) ;
V_75 = F_72 ( 512 , V_205 ) ;
if ( V_75 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_206 ;
}
V_75 [ 0 ] = V_207 ;
V_75 [ 1 ] = ( T_2 ) F_73 ( V_201 ) ;
V_75 [ 2 ] = V_215 ;
* V_214 = 0 ;
V_48 -> V_216 = 0 ;
V_200 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_75 , 512 ) ;
F_74 ( V_75 ) ;
F_75 ( V_48 -> V_217 ,
( V_48 -> V_216 != 0 ) ,
F_76 ( V_218 ) ) ;
if ( V_48 -> V_216 != 1 ) {
F_14 ( V_81 L_38 ) ;
V_200 = - V_213 ;
}
* V_214 = V_48 -> V_219 ;
F_12 ( 4 , L_39 , V_29 , * V_214 ) ;
return V_200 ;
}
static int F_78 ( struct V_109 * V_109 , void * V_110 , enum V_220 V_23 )
{
int V_200 ;
struct V_89 * V_90 = V_110 ;
struct V_1 * V_25 = V_90 -> V_25 ;
struct V_47 * V_48 = V_90 -> V_48 ;
int V_221 ;
F_12 ( 4 , L_1 , V_29 ) ;
if ( V_90 -> type != V_222 ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_40 ) ;
return - V_101 ;
}
if ( V_23 != V_90 -> type ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_41 ) ;
return - V_101 ;
}
if ( ! F_42 ( V_90 ) ) {
F_19 ( & V_25 -> V_39 -> V_25 , L_42 ) ;
return - V_152 ;
}
V_48 -> V_74 = - 1 ;
V_48 -> V_223 = 0 ;
V_48 -> V_224 = 0 ;
V_48 -> V_83 = 0 ;
for ( V_221 = 0 ; V_221 < V_225 ; V_221 ++ ) {
V_48 -> V_75 . V_76 [ V_221 ] . V_226 = V_227 ;
V_48 -> V_75 . V_76 [ V_221 ] . V_228 = 0 ;
}
V_200 = F_79 ( & V_90 -> V_134 ) ;
if ( V_200 == 0 ) {
F_80 ( V_48 ) ;
V_48 -> V_229 = 1 ;
} else
F_45 ( V_90 ) ;
return V_200 ;
}
static int F_81 ( struct V_109 * V_109 , void * V_110 , enum V_220 V_23 )
{
struct V_89 * V_90 = V_110 ;
F_12 ( 4 , L_43 , V_29 , V_90 -> V_48 -> V_107 ) ;
if ( V_90 -> type != V_222 ) {
F_14 ( V_32 L_40 ) ;
return - V_101 ;
}
if ( V_23 != V_90 -> type ) {
F_14 ( V_32 L_44 ) ;
return - V_101 ;
}
F_82 ( V_90 -> V_48 ) ;
F_83 ( & V_90 -> V_134 ) ;
F_45 ( V_90 ) ;
return 0 ;
}
static int F_84 ( struct V_109 * V_109 , void * V_110 , T_3 * V_23 )
{
struct V_89 * V_90 = V_110 ;
struct V_148 V_149 ;
struct V_86 * V_147 = & V_90 -> V_134 ;
int V_150 = 0 ;
F_55 ( & V_147 -> V_151 ) ;
if ( F_56 ( V_147 ) ) {
F_12 ( 1 , L_26 ) ;
V_150 = - V_152 ;
goto V_230;
}
if ( F_43 ( V_90 ) ) {
F_12 ( 1 , L_45 ) ;
V_150 = - V_152 ;
goto V_230;
}
V_149 = V_90 -> V_48 -> V_149 ;
if ( * V_23 & V_7 ) {
F_12 ( 4 , L_46 , V_29 ) ;
if ( V_149 . V_171 != V_188 ) {
V_149 . V_170 = 1 ;
V_149 . V_171 = V_188 ;
V_149 . V_198 = V_231 ;
}
} else if ( * V_23 & V_232 ) {
F_12 ( 4 , L_47 , V_29 ) ;
if ( V_149 . V_171 != V_191 ) {
V_149 . V_170 = 1 ;
V_149 . V_171 = V_191 ;
V_149 . V_198 = V_231 ;
}
} else {
V_150 = - V_101 ;
}
if ( V_149 . V_170 )
F_57 ( V_90 -> V_48 , & V_149 ) ;
V_230:
F_58 ( & V_147 -> V_151 ) ;
return V_150 ;
}
static int F_85 ( struct V_109 * V_109 , void * V_110 ,
struct V_233 * V_234 )
{
struct V_89 * V_90 = V_110 ;
struct V_1 * V_25 = V_90 -> V_25 ;
struct V_47 * V_48 = V_90 -> V_48 ;
T_1 V_41 = 0 ;
if ( V_234 -> V_117 != 0 )
return - V_101 ;
V_234 -> type = V_235 ;
V_234 -> V_236 = V_237 ;
V_234 -> V_41 = 0 ;
if ( V_25 -> V_238 >= V_239 ) {
int V_56 ;
V_56 = F_77 ( V_90 -> V_48 , & V_41 ) ;
F_12 ( 4 , L_48 , V_56 , V_41 ) ;
if ( V_56 == 0 )
V_234 -> V_41 = ( V_41 & 0x01 ) ? 0
: V_240 ;
}
switch ( V_25 -> V_241 ) {
case 0x2255 :
default:
F_47 ( V_234 -> V_118 , L_49 , sizeof( V_234 -> V_118 ) ) ;
break;
case 0x2257 :
F_47 ( V_234 -> V_118 , ( V_48 -> V_107 < 2 ) ? L_49 : L_50 ,
sizeof( V_234 -> V_118 ) ) ;
break;
}
return 0 ;
}
static int F_86 ( struct V_109 * V_109 , void * V_110 , unsigned int * V_23 )
{
* V_23 = 0 ;
return 0 ;
}
static int F_87 ( struct V_109 * V_109 , void * V_110 , unsigned int V_23 )
{
if ( V_23 > 0 )
return - V_101 ;
return 0 ;
}
static int F_88 ( struct V_109 * V_109 , void * V_110 ,
struct V_242 * V_243 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
struct V_1 * V_25 = V_90 -> V_25 ;
switch ( V_243 -> V_114 ) {
case V_244 :
F_89 ( V_243 , - 127 , 127 , 1 , V_245 ) ;
break;
case V_246 :
F_89 ( V_243 , 0 , 255 , 1 , V_247 ) ;
break;
case V_248 :
F_89 ( V_243 , 0 , 255 , 1 , V_249 ) ;
break;
case V_250 :
F_89 ( V_243 , 0 , 255 , 1 , V_251 ) ;
break;
case V_115 :
if ( V_25 -> V_238 < V_252 )
return - V_101 ;
if ( ( V_25 -> V_241 == 0x2257 ) && ( V_48 -> V_107 > 1 ) )
return - V_101 ;
F_47 ( V_243 -> V_118 , L_51 , sizeof( V_243 -> V_118 ) ) ;
V_243 -> type = V_253 ;
V_243 -> V_254 = 0 ;
V_243 -> V_255 = 1 ;
V_243 -> V_256 = 1 ;
V_243 -> V_257 = 1 ;
V_243 -> V_55 = 0 ;
break;
default:
return - V_101 ;
}
F_12 ( 4 , L_52 , V_29 , V_243 -> V_114 ) ;
return 0 ;
}
static int F_90 ( struct V_109 * V_109 , void * V_110 ,
struct V_258 * V_259 )
{
struct V_89 * V_90 = V_110 ;
struct V_1 * V_25 = V_90 -> V_25 ;
struct V_47 * V_48 = V_90 -> V_48 ;
switch ( V_259 -> V_114 ) {
case V_244 :
V_259 -> V_260 = V_48 -> V_149 . V_199 ;
break;
case V_246 :
V_259 -> V_260 = V_48 -> V_149 . V_261 ;
break;
case V_248 :
V_259 -> V_260 = V_48 -> V_149 . V_262 ;
break;
case V_250 :
V_259 -> V_260 = V_48 -> V_149 . V_263 ;
break;
case V_115 :
if ( V_25 -> V_238 < V_252 )
return - V_101 ;
if ( ( V_25 -> V_241 == 0x2257 ) && ( V_48 -> V_107 > 1 ) )
return - V_101 ;
V_259 -> V_260 = ! ( ( V_48 -> V_149 . V_162 & V_264 ) >> 16 ) ;
break;
default:
return - V_101 ;
}
F_12 ( 4 , L_53 , V_29 , V_259 -> V_114 , V_259 -> V_260 ) ;
return 0 ;
}
static int F_91 ( struct V_109 * V_109 , void * V_110 ,
struct V_258 * V_259 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
struct V_148 V_149 ;
V_149 = V_48 -> V_149 ;
F_12 ( 4 , L_1 , V_29 ) ;
switch ( V_259 -> V_114 ) {
case V_244 :
V_149 . V_199 = V_259 -> V_260 ;
break;
case V_246 :
V_149 . V_261 = V_259 -> V_260 ;
break;
case V_250 :
V_149 . V_263 = V_259 -> V_260 ;
break;
case V_248 :
V_149 . V_262 = V_259 -> V_260 ;
break;
case V_115 :
if ( V_25 -> V_238 < V_252 )
return - V_101 ;
if ( ( V_25 -> V_241 == 0x2257 ) && ( V_48 -> V_107 > 1 ) )
return - V_101 ;
V_149 . V_162 &= ~ V_264 ;
V_149 . V_162 |= ( ( V_259 -> V_260 ? 0 : 1 ) << 16 ) ;
break;
default:
return - V_101 ;
}
V_149 . V_170 = 0 ;
F_57 ( V_90 -> V_48 , & V_149 ) ;
return 0 ;
}
static int F_92 ( struct V_109 * V_109 , void * V_110 ,
struct V_265 * V_166 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
* V_166 = V_48 -> V_166 ;
F_12 ( 2 , L_54 , V_29 , V_166 -> V_167 ) ;
return 0 ;
}
static int F_93 ( struct V_109 * V_109 , void * V_110 ,
const struct V_265 * V_166 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
if ( V_166 -> V_167 < 0 || V_166 -> V_167 > 100 )
return - V_101 ;
V_48 -> V_166 . V_167 = V_166 -> V_167 ;
F_12 ( 2 , L_54 , V_29 , V_166 -> V_167 ) ;
return 0 ;
}
static int F_94 ( struct V_109 * V_109 , void * V_110 ,
struct V_266 * V_267 )
{
struct V_89 * V_90 = V_110 ;
T_4 V_268 , V_269 ;
struct V_47 * V_48 = V_90 -> V_48 ;
if ( V_267 -> type != V_222 )
return - V_101 ;
memset ( V_267 , 0 , sizeof( struct V_266 ) ) ;
V_267 -> V_270 . V_271 . V_272 = V_273 ;
V_267 -> V_270 . V_271 . V_155 = V_48 -> V_154 . V_155 ;
V_268 = ( V_48 -> V_149 . V_171 == V_188 ) ? 1001 : 1000 ;
V_269 = ( V_48 -> V_149 . V_171 == V_188 ) ? 30000 : 25000 ;
V_267 -> V_270 . V_271 . V_274 . V_275 = V_269 ;
switch ( V_48 -> V_149 . V_198 ) {
default:
case V_231 :
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 ;
break;
case V_277 :
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 * 2 ;
break;
case V_278 :
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 * 3 ;
break;
case V_279 :
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 * 5 ;
break;
}
F_12 ( 4 , L_55 , V_29 ,
V_267 -> V_270 . V_271 . V_155 ,
V_267 -> V_270 . V_271 . V_274 . V_276 ,
V_267 -> V_270 . V_271 . V_274 . V_275 ) ;
return 0 ;
}
static int F_95 ( struct V_109 * V_109 , void * V_110 ,
struct V_266 * V_267 )
{
struct V_89 * V_90 = V_110 ;
struct V_47 * V_48 = V_90 -> V_48 ;
struct V_148 V_149 ;
int V_198 = V_231 ;
T_4 V_268 , V_269 ;
if ( V_267 -> type != V_222 )
return - V_101 ;
V_149 = V_48 -> V_149 ;
if ( V_48 -> V_154 . V_155
!= V_267 -> V_270 . V_271 . V_155 && F_43 ( V_90 ) )
return - V_152 ;
V_268 = ( V_149 . V_171 == V_188 ) ? 1001 : 1000 ;
V_269 = ( V_149 . V_171 == V_188 ) ? 30000 : 25000 ;
if ( V_269 != V_267 -> V_270 . V_271 . V_274 . V_275 )
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 ;
else if ( V_267 -> V_270 . V_271 . V_274 . V_276 <= V_268 )
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 ;
else if ( V_267 -> V_270 . V_271 . V_274 . V_276 <= ( V_268 * 2 ) ) {
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 * 2 ;
V_198 = V_277 ;
} else if ( V_267 -> V_270 . V_271 . V_274 . V_276 <= ( V_268 * 3 ) ) {
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 * 3 ;
V_198 = V_278 ;
} else {
V_267 -> V_270 . V_271 . V_274 . V_276 = V_268 * 5 ;
V_198 = V_279 ;
}
V_149 . V_198 = V_198 ;
V_267 -> V_270 . V_271 . V_274 . V_275 = V_269 ;
F_57 ( V_48 , & V_149 ) ;
F_12 ( 4 , L_56 ,
V_29 ,
V_267 -> V_270 . V_271 . V_155 ,
V_267 -> V_270 . V_271 . V_274 . V_276 ,
V_267 -> V_270 . V_271 . V_274 . V_275 , V_198 ) ;
return 0 ;
}
static int F_96 ( struct V_109 * V_109 , void * V_110 ,
struct V_280 * V_281 )
{
int V_138 = 0 ;
#define F_97 4
int V_282 [ F_97 ] = { 1 , 2 , 3 , 5 } ;
if ( V_281 -> V_117 >= F_97 )
return - V_101 ;
switch ( V_281 -> V_16 ) {
case 640 :
if ( V_281 -> V_17 != 240 && V_281 -> V_17 != 480 )
return - V_101 ;
V_138 = 1 ;
break;
case 320 :
if ( V_281 -> V_17 != 240 )
return - V_101 ;
V_138 = 1 ;
break;
case 704 :
if ( V_281 -> V_17 != 288 && V_281 -> V_17 != 576 )
return - V_101 ;
break;
case 352 :
if ( V_281 -> V_17 != 288 )
return - V_101 ;
break;
default:
return - V_101 ;
}
V_281 -> type = V_283 ;
V_281 -> V_284 . V_275 = V_138 ? 30000 : 25000 ;
V_281 -> V_284 . V_276 = ( V_138 ? 1001 : 1000 ) * V_282 [ V_281 -> V_117 ] ;
F_12 ( 4 , L_57 , V_29 , V_281 -> V_284 . V_276 ,
V_281 -> V_284 . V_275 ) ;
return 0 ;
}
static int F_98 ( struct V_109 * V_109 )
{
struct V_4 * V_5 = F_99 ( V_109 ) ;
struct V_47 * V_48 = F_100 ( V_109 ) ;
struct V_1 * V_25 = F_1 ( V_5 -> V_3 ) ;
struct V_89 * V_90 ;
enum V_220 type = V_222 ;
int V_84 ;
F_12 ( 1 , L_58 ,
F_101 ( V_5 ) ) ;
V_84 = F_102 ( & V_25 -> V_285 -> V_33 ) ;
switch ( V_84 ) {
case V_286 :
return - V_287 ;
case V_34 :
F_19 ( & V_25 -> V_39 -> V_25 ,
L_59 ) ;
F_103 ( V_25 , 1 ) ;
F_75 ( V_25 -> V_285 -> V_35 ,
( ( F_102 ( & V_25 -> V_285 -> V_33 )
== V_288 ) ||
( F_102 ( & V_25 -> V_285 -> V_33 )
== V_286 ) ) ,
F_76 ( V_289 ) ) ;
V_84 = F_102 ( & V_25 -> V_285 -> V_33 ) ;
break;
case V_290 :
case V_46 :
F_14 ( V_291 L_60 , V_29 ) ;
F_75 ( V_25 -> V_285 -> V_35 ,
( ( F_102 ( & V_25 -> V_285 -> V_33 )
== V_288 ) ||
( F_102 ( & V_25 -> V_285 -> V_33 )
== V_286 ) ) ,
F_76 ( V_289 ) ) ;
V_84 = F_102 ( & V_25 -> V_285 -> V_33 ) ;
break;
case V_288 :
default:
break;
}
switch ( V_84 ) {
case V_288 :
break;
case V_34 :
F_14 ( V_291 L_61 ) ;
return - V_287 ;
case V_286 :
F_14 ( V_291 L_62 , V_29 ) ;
return - V_287 ;
case V_46 :
case V_290 :
F_14 ( V_291 L_63
L_64 ,
V_29 ) ;
F_15 ( & V_25 -> V_285 -> V_33 ,
V_34 ) ;
return - V_292 ;
default:
F_14 ( V_291 L_65 , V_29 ) ;
return - V_213 ;
}
V_90 = F_72 ( sizeof( * V_90 ) , V_205 ) ;
if ( NULL == V_90 )
return - V_206 ;
V_109 -> V_121 = V_90 ;
V_90 -> V_25 = V_25 ;
V_90 -> type = V_222 ;
V_90 -> V_48 = V_48 ;
if ( ! V_48 -> V_293 ) {
V_48 -> V_18 = & V_67 [ 0 ] ;
F_57 ( V_48 , & V_48 -> V_149 ) ;
V_48 -> V_293 = 1 ;
}
F_12 ( 1 , L_66 , V_29 ,
F_101 ( V_5 ) , V_294 [ type ] ) ;
F_12 ( 2 , L_67 , V_29 ,
( unsigned long ) V_90 , ( unsigned long ) V_25 ,
( unsigned long ) & V_48 -> V_52 ) ;
F_12 ( 4 , L_68 , V_29 ,
F_25 ( & V_48 -> V_52 . V_58 ) ) ;
F_104 ( & V_90 -> V_134 , & V_295 ,
NULL , & V_25 -> V_57 ,
V_90 -> type ,
V_141 ,
sizeof( struct V_53 ) ,
V_90 , V_5 -> V_296 ) ;
return 0 ;
}
static int F_105 ( struct V_109 * V_109 )
{
struct V_4 * V_5 = F_99 ( V_109 ) ;
int V_150 ;
if ( F_106 ( V_5 -> V_296 ) )
return - V_297 ;
V_150 = F_98 ( V_109 ) ;
F_58 ( V_5 -> V_296 ) ;
return V_150 ;
}
static unsigned int F_107 ( struct V_109 * V_109 ,
struct V_298 * V_299 )
{
struct V_89 * V_90 = V_109 -> V_121 ;
struct V_1 * V_25 = V_90 -> V_25 ;
int V_56 ;
F_12 ( 100 , L_1 , V_29 ) ;
if ( V_222 != V_90 -> type )
return V_300 ;
F_55 ( & V_25 -> V_296 ) ;
V_56 = F_108 ( V_109 , & V_90 -> V_134 , V_299 ) ;
F_58 ( & V_25 -> V_296 ) ;
return V_56 ;
}
static void F_109 ( struct V_1 * V_25 )
{
F_110 ( V_25 ) ;
F_111 ( & V_25 -> V_301 ) ;
if ( V_25 -> V_285 -> V_30 ) {
F_112 ( V_25 -> V_285 -> V_30 ) ;
F_113 ( V_25 -> V_285 -> V_30 ) ;
V_25 -> V_285 -> V_30 = NULL ;
}
F_114 ( V_25 -> V_285 -> V_45 ) ;
F_74 ( V_25 -> V_285 -> V_44 ) ;
F_74 ( V_25 -> V_285 ) ;
F_8 ( V_25 ) ;
F_115 ( & V_25 -> V_296 ) ;
F_116 ( V_25 -> V_39 ) ;
F_117 ( & V_25 -> V_3 ) ;
F_12 ( 1 , L_69 , V_29 ) ;
F_74 ( V_25 ) ;
}
static int F_118 ( struct V_109 * V_109 )
{
struct V_89 * V_90 = V_109 -> V_121 ;
struct V_1 * V_25 = V_90 -> V_25 ;
struct V_4 * V_5 = F_99 ( V_109 ) ;
struct V_47 * V_48 = V_90 -> V_48 ;
if ( ! V_25 )
return - V_287 ;
F_55 ( & V_25 -> V_296 ) ;
if ( F_44 ( V_90 ) ) {
if ( V_48 -> V_229 )
F_82 ( V_90 -> V_48 ) ;
F_83 ( & V_90 -> V_134 ) ;
F_45 ( V_90 ) ;
}
F_119 ( & V_90 -> V_134 ) ;
F_58 ( & V_25 -> V_296 ) ;
F_12 ( 1 , L_70 , V_29 , F_101 ( V_5 ) ) ;
F_74 ( V_90 ) ;
return 0 ;
}
static int F_120 ( struct V_109 * V_109 , struct V_302 * V_303 )
{
struct V_89 * V_90 = V_109 -> V_121 ;
struct V_1 * V_25 ;
int V_150 ;
if ( ! V_90 )
return - V_287 ;
V_25 = V_90 -> V_25 ;
F_12 ( 4 , L_71 , V_29 , ( unsigned long ) V_303 ) ;
if ( F_106 ( & V_25 -> V_296 ) )
return - V_297 ;
V_150 = F_121 ( & V_90 -> V_134 , V_303 ) ;
F_58 ( & V_25 -> V_296 ) ;
F_12 ( 4 , L_72 , V_29 ,
( unsigned long ) V_303 -> V_304 ,
( unsigned long ) V_303 -> V_305 - ( unsigned long ) V_303 -> V_304 , V_150 ) ;
return V_150 ;
}
static void F_122 ( struct V_4 * V_5 )
{
struct V_1 * V_25 = F_1 ( V_5 -> V_3 ) ;
F_12 ( 4 , L_73 , V_29 ,
F_102 ( & V_25 -> V_306 ) ) ;
if ( F_123 ( & V_25 -> V_306 ) )
F_109 ( V_25 ) ;
return;
}
static int F_124 ( struct V_1 * V_25 )
{
int V_150 ;
int V_23 ;
int V_307 = V_308 ;
struct V_47 * V_48 ;
V_150 = F_125 ( & V_25 -> V_309 -> V_25 , & V_25 -> V_3 ) ;
if ( V_150 )
return V_150 ;
for ( V_23 = 0 ; V_23 < V_310 ; V_23 ++ ) {
V_48 = & V_25 -> V_48 [ V_23 ] ;
F_126 ( & V_48 -> V_52 . V_58 ) ;
V_48 -> V_52 . V_25 = V_25 ;
V_48 -> V_5 = V_311 ;
V_48 -> V_5 . V_296 = & V_25 -> V_296 ;
V_48 -> V_5 . V_3 = & V_25 -> V_3 ;
F_127 ( & V_48 -> V_5 , V_48 ) ;
if ( V_308 == - 1 )
V_150 = F_128 ( & V_48 -> V_5 ,
V_312 ,
V_308 ) ;
else
V_150 = F_128 ( & V_48 -> V_5 ,
V_312 ,
V_307 + V_23 ) ;
if ( V_150 ) {
F_18 ( & V_25 -> V_39 -> V_25 ,
L_74 ) ;
break;
}
F_129 ( & V_25 -> V_306 ) ;
F_130 ( & V_25 -> V_3 , L_75 ,
F_101 ( & V_48 -> V_5 ) ) ;
}
F_14 ( V_291 L_76 ,
V_313 ) ;
if ( F_102 ( & V_25 -> V_306 ) == 0 ) {
F_117 ( & V_25 -> V_3 ) ;
return V_150 ;
}
if ( F_102 ( & V_25 -> V_306 ) != V_310 )
F_14 ( V_314 L_77 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_25 , struct V_315 * V_316 )
{
char * V_317 ;
T_1 V_318 = 0 ;
int V_319 = 0 ;
char * V_320 ;
unsigned long V_321 ;
unsigned long V_22 ;
T_5 V_107 = - 1 ;
struct V_322 * V_323 ;
unsigned char * V_324 ;
struct V_47 * V_48 ;
F_12 ( 100 , L_78 ) ;
V_48 = & V_25 -> V_48 [ V_25 -> V_325 ] ;
V_107 = V_48 -> V_224 ;
V_323 = & V_48 -> V_75 . V_76 [ V_107 ] ;
if ( V_323 -> V_226 == V_227 ) {
int V_326 ;
unsigned int V_325 ;
T_2 * V_327 ;
int V_328 ;
V_324 = ( unsigned char * ) V_316 -> V_329 ;
V_327 = ( T_2 * ) V_324 ;
for ( V_326 = 0 ; V_326 < ( V_316 -> V_330 - 12 ) ; V_326 ++ ) {
switch ( * V_327 ) {
case V_331 :
F_12 ( 4 , L_79
L_80 , V_326 , V_324 [ 0 ] ,
V_324 [ 1 ] ) ;
V_318 = V_326 + V_194 ;
V_319 = 1 ;
V_325 = F_132 ( V_327 [ 1 ] ) ;
if ( V_325 >= V_310 ) {
F_14 ( V_32
L_81 ) ;
return - V_101 ;
}
V_25 -> V_325 = V_202 [ V_325 ] ;
V_48 = & V_25 -> V_48 [ V_25 -> V_325 ] ;
V_328 = F_132 ( V_327 [ 3 ] ) ;
if ( V_328 > V_48 -> V_204 ) {
V_48 -> V_223 ++ ;
return - V_101 ;
}
V_48 -> V_332 = V_328 ;
V_48 -> V_333 = F_132 ( V_327 [ 4 ] ) ;
break;
case V_334 :
V_324 += V_195 ;
V_326 += V_195 ;
if ( F_132 ( V_327 [ 1 ] ) >= V_310 )
break;
V_325 = V_202 [ F_132 ( V_327 [ 1 ] ) ] ;
if ( V_325 >= V_310 )
break;
V_48 = & V_25 -> V_48 [ V_325 ] ;
switch ( V_327 [ 2 ] ) {
case V_335 :
V_48 -> V_209 = 1 ;
F_16 ( & V_48 -> V_211 ) ;
F_12 ( 5 , L_82 , V_325 ) ;
break;
case V_336 :
V_25 -> V_337 |= ( 1 << V_325 ) ;
if ( ( V_25 -> V_337 & 0x0f ) != 0x0f )
break;
F_14 ( V_291 L_83 ) ;
F_15 ( & V_25 -> V_285 -> V_33 ,
V_288 ) ;
F_16 ( & V_25 -> V_285 -> V_35 ) ;
break;
case V_338 :
V_48 -> V_219 = F_132 ( V_327 [ 3 ] ) ;
V_48 -> V_216 = 1 ;
F_16 ( & V_48 -> V_217 ) ;
F_12 ( 5 , L_84 ,
F_132 ( V_327 [ 3 ] ) , V_325 ) ;
break;
default:
F_14 ( V_291 L_85 ) ;
}
default:
V_324 ++ ;
break;
}
if ( V_319 )
break;
}
if ( ! V_319 )
return - V_101 ;
}
V_48 = & V_25 -> V_48 [ V_25 -> V_325 ] ;
V_107 = V_48 -> V_224 ;
V_323 = & V_48 -> V_75 . V_76 [ V_107 ] ;
if ( ! V_48 -> V_229 ) {
V_323 -> V_226 = V_227 ;
return - V_101 ;
}
if ( V_323 -> V_226 == V_227 ) {
V_323 -> V_226 = V_339 ;
V_323 -> V_228 = 0 ;
}
V_320 = ( V_340 * ) V_316 -> V_329 + V_318 ;
if ( V_323 -> V_77 == NULL ) {
F_12 ( 1 , L_86 ,
V_323 , V_25 , V_25 -> V_325 , V_107 ) ;
return - V_206 ;
}
V_317 = V_323 -> V_77 + V_323 -> V_228 ;
V_321 = ( V_316 -> V_330 - V_318 ) ;
V_22 = V_48 -> V_332 - V_194 ;
if ( ( V_321 + V_323 -> V_228 ) < V_48 -> V_204 )
memcpy ( V_317 , V_320 , V_321 ) ;
V_323 -> V_228 += V_321 ;
F_12 ( 4 , L_87 , V_323 -> V_228 , V_22 ) ;
if ( V_323 -> V_228 >= V_22 ) {
F_12 ( 2 , L_88 ,
V_25 -> V_325 , V_107 ) ;
V_48 -> V_74 = V_48 -> V_224 ;
V_48 -> V_224 ++ ;
if ( ( V_48 -> V_224 == V_225 ) ||
( V_48 -> V_224 == V_48 -> V_75 . V_341 ) )
V_48 -> V_224 = 0 ;
if ( V_48 -> V_229 )
F_23 ( V_48 , V_48 -> V_333 ) ;
V_48 -> V_83 ++ ;
V_323 -> V_226 = V_227 ;
V_323 -> V_228 = 0 ;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_25 ,
struct V_315 * V_316 )
{
int V_200 ;
F_12 ( 50 , L_89 ) ;
if ( V_25 -> V_325 >= V_310 ) {
V_25 -> V_325 = 0 ;
F_18 ( & V_25 -> V_39 -> V_25 , L_90 ) ;
return;
}
V_200 = F_131 ( V_25 , V_316 ) ;
if ( V_200 != 0 )
F_12 ( 4 , L_91 ) ;
F_12 ( 50 , L_92 ) ;
return;
}
static long F_9 ( struct V_1 * V_25 , unsigned char V_342 ,
T_6 V_343 , T_6 V_344 , void * V_345 ,
T_5 V_346 , int V_347 )
{
int V_348 ;
if ( ! V_347 ) {
V_348 = F_134 ( V_25 -> V_39 , F_135 ( V_25 -> V_39 , 0 ) ,
V_342 ,
V_349 | V_350 |
V_351 ,
V_344 , V_343 , V_345 ,
V_346 , V_352 * 5 ) ;
} else {
V_348 = F_134 ( V_25 -> V_39 , F_136 ( V_25 -> V_39 , 0 ) ,
V_342 , V_349 | V_350 ,
V_344 , V_343 , V_345 ,
V_346 , V_352 * 5 ) ;
}
return V_348 ;
}
static int F_137 ( struct V_1 * V_25 )
{
int V_45 ;
int V_150 ;
unsigned char V_353 [ 64 ] ;
V_150 = F_9 ( V_25 , V_354 , 0 , 0 , V_353 , 2 ,
V_355 ) ;
if ( V_150 < 0 )
F_12 ( 2 , L_93 , V_150 ) ;
V_45 = V_353 [ 0 ] + ( V_353 [ 1 ] << 8 ) ;
F_12 ( 2 , L_94 , V_353 [ 0 ] , V_353 [ 1 ] ) ;
return V_45 ;
}
static int F_138 ( struct V_47 * V_48 )
{
unsigned long V_23 ;
unsigned long V_356 ;
F_12 ( 1 , L_95 ) ;
V_48 -> V_75 . V_341 = V_225 ;
V_356 = V_357 ;
if ( V_356 > V_357 )
V_356 = V_357 ;
for ( V_23 = 0 ; V_23 < V_225 ; V_23 ++ ) {
V_48 -> V_75 . V_76 [ V_23 ] . V_77 = F_139 ( V_356 ) ;
F_12 ( 1 , L_96 ,
& V_48 -> V_75 . V_76 [ V_23 ] , V_48 -> V_107 , V_23 ,
V_48 -> V_75 . V_76 [ V_23 ] . V_77 ) ;
V_48 -> V_75 . V_76 [ V_23 ] . V_22 = V_356 ;
if ( V_48 -> V_75 . V_76 [ V_23 ] . V_77 == NULL ) {
F_14 ( V_291 L_97 ) ;
V_48 -> V_75 . V_341 = V_23 ;
break;
}
}
for ( V_23 = 0 ; V_23 < V_225 ; V_23 ++ ) {
V_48 -> V_75 . V_76 [ V_23 ] . V_226 = 0 ;
V_48 -> V_75 . V_76 [ V_23 ] . V_228 = 0 ;
}
V_48 -> V_224 = 0 ;
V_48 -> V_74 = - 1 ;
return 0 ;
}
static int F_140 ( struct V_47 * V_48 )
{
unsigned long V_23 ;
F_12 ( 1 , L_98 ) ;
for ( V_23 = 0 ; V_23 < V_225 ; V_23 ++ ) {
if ( V_48 -> V_75 . V_76 [ V_23 ] . V_77 ) {
F_12 ( 1 , L_99 ,
V_48 -> V_75 . V_76 [ V_23 ] . V_77 ) ;
F_141 ( V_48 -> V_75 . V_76 [ V_23 ] . V_77 ) ;
}
V_48 -> V_75 . V_76 [ V_23 ] . V_77 = NULL ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_25 )
{
struct V_148 V_358 = V_359 ;
int V_360 ;
int V_221 ;
struct V_315 * V_178 = & V_25 -> V_178 ;
F_12 ( 4 , L_100 , V_25 ) ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_25 = V_25 ;
V_178 -> V_330 = V_361 ;
V_178 -> V_362 = V_361 ;
V_178 -> V_329 = F_72 ( V_178 -> V_362 ,
V_205 ) ;
if ( V_178 -> V_329 == NULL ) {
F_12 ( 1 , L_101 ) ;
return - V_206 ;
}
V_360 = F_137 ( V_25 ) ;
F_14 ( V_291 L_102 ,
( V_360 >> 8 ) & 0xff ,
V_360 & 0xff ) ;
if ( V_360 < V_363 )
F_14 ( V_291 L_103 ) ;
for ( V_221 = 0 ; V_221 < V_310 ; V_221 ++ ) {
struct V_47 * V_48 = & V_25 -> V_48 [ V_221 ] ;
V_48 -> V_229 = 0 ;
V_48 -> V_149 = V_358 ;
if ( V_25 -> V_241 == 0x2257 && V_221 > 1 )
V_48 -> V_149 . V_162 |= ( 1 << 16 ) ;
V_48 -> V_166 . V_167 = V_364 ;
V_48 -> V_16 = V_8 ;
V_48 -> V_17 = V_189 * 2 ;
V_48 -> V_18 = & V_67 [ 0 ] ;
V_48 -> V_149 . V_170 = 1 ;
V_48 -> V_204 = F_69 ( & V_358 ) ;
V_48 -> V_83 = 0 ;
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
for ( V_23 = 0 ; V_23 < V_310 ; V_23 ++ ) {
if ( V_25 -> V_48 [ V_23 ] . V_229 )
F_82 ( & V_25 -> V_48 [ V_23 ] ) ;
}
F_144 ( V_25 ) ;
for ( V_23 = 0 ; V_23 < V_310 ; V_23 ++ )
F_140 ( & V_25 -> V_48 [ V_23 ] ) ;
F_74 ( V_25 -> V_178 . V_329 ) ;
return 0 ;
}
static void F_145 ( struct V_36 * V_365 )
{
struct V_315 * V_316 ;
struct V_1 * V_25 ;
int V_41 ;
int V_178 ;
V_316 = V_365 -> V_37 ;
F_12 ( 100 , L_106 , V_29 , V_365 ,
V_365 -> V_41 ) ;
if ( V_316 == NULL ) {
F_18 ( & V_365 -> V_25 -> V_25 , L_107 ) ;
return;
}
V_25 = V_316 -> V_25 ;
if ( V_25 == NULL ) {
F_18 ( & V_365 -> V_25 -> V_25 , L_107 ) ;
return;
}
V_41 = V_365 -> V_41 ;
if ( V_41 == - V_366 ) {
F_12 ( 2 , L_108 , V_29 ) ;
V_316 -> V_367 ++ ;
return;
}
if ( V_316 -> V_84 == 0 ) {
F_12 ( 2 , L_109 , V_29 ) ;
return;
}
if ( V_41 == 0 )
F_133 ( V_25 , V_316 ) ;
else {
V_316 -> V_367 ++ ;
F_12 ( 1 , L_110 , V_29 , V_41 ) ;
}
V_178 = F_146 ( V_25 -> V_39 , V_25 -> V_368 ) ;
F_21 ( V_316 -> V_369 , V_25 -> V_39 ,
V_178 ,
V_316 -> V_329 ,
V_316 -> V_330 ,
F_145 , V_316 ) ;
if ( V_316 -> V_84 != 0 ) {
if ( F_13 ( V_316 -> V_369 , V_31 ) ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_111 ) ;
}
} else {
F_12 ( 2 , L_112 , V_29 ) ;
}
return;
}
static int F_143 ( struct V_1 * V_25 )
{
int V_178 ;
int V_179 ;
struct V_315 * V_316 = & V_25 -> V_178 ;
V_178 = F_146 ( V_25 -> V_39 , V_25 -> V_368 ) ;
F_12 ( 2 , L_113 , V_29 , V_25 -> V_368 ) ;
V_316 -> V_84 = 1 ;
V_316 -> V_367 = 0 ;
V_316 -> V_369 = F_147 ( 0 , V_205 ) ;
if ( ! V_316 -> V_369 ) {
F_18 ( & V_25 -> V_39 -> V_25 ,
L_114 ) ;
return - V_206 ;
}
F_21 ( V_316 -> V_369 , V_25 -> V_39 ,
V_178 ,
V_316 -> V_329 ,
V_316 -> V_330 ,
F_145 , V_316 ) ;
V_179 = F_13 ( V_316 -> V_369 , V_205 ) ;
if ( V_179 ) {
F_14 ( V_32 L_115 ) ;
return V_179 ;
}
return 0 ;
}
static int F_80 ( struct V_47 * V_48 )
{
unsigned char * V_75 ;
int V_200 ;
unsigned long V_201 ;
int V_221 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_201 = V_202 [ V_48 -> V_107 ] ;
V_75 = F_72 ( 512 , V_205 ) ;
if ( V_75 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_206 ;
}
V_48 -> V_74 = - 1 ;
V_48 -> V_223 = 0 ;
V_48 -> V_224 = 0 ;
for ( V_221 = 0 ; V_221 < V_225 ; V_221 ++ ) {
V_48 -> V_75 . V_76 [ V_221 ] . V_226 = 0 ;
V_48 -> V_75 . V_76 [ V_221 ] . V_228 = 0 ;
}
* ( T_2 * ) V_75 = V_207 ;
* ( ( T_2 * ) V_75 + 1 ) = ( T_2 ) F_73 ( V_201 ) ;
* ( ( T_2 * ) V_75 + 2 ) = V_370 ;
V_200 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_75 , 512 ) ;
if ( V_200 != 0 )
F_18 ( & V_25 -> V_39 -> V_25 , L_116 ) ;
F_12 ( 2 , L_117 , V_48 -> V_107 , V_200 ) ;
F_74 ( V_75 ) ;
return 0 ;
}
static int F_82 ( struct V_47 * V_48 )
{
unsigned char * V_75 ;
int V_200 ;
unsigned long V_201 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_201 = V_202 [ V_48 -> V_107 ] ;
V_75 = F_72 ( 512 , V_205 ) ;
if ( V_75 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_206 ;
}
* ( T_2 * ) V_75 = V_207 ;
* ( ( T_2 * ) V_75 + 1 ) = ( T_2 ) F_73 ( V_201 ) ;
* ( ( T_2 * ) V_75 + 2 ) = V_371 ;
V_200 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_75 , 512 ) ;
if ( V_200 != 0 )
F_18 ( & V_25 -> V_39 -> V_25 , L_118 ) ;
F_74 ( V_75 ) ;
V_48 -> V_229 = 0 ;
F_12 ( 4 , L_119 , V_29 , V_48 -> V_107 , V_200 ) ;
return V_200 ;
}
static void F_144 ( struct V_1 * V_25 )
{
struct V_315 * V_178 = & V_25 -> V_178 ;
V_178 -> V_84 = 0 ;
if ( V_178 -> V_369 ) {
F_112 ( V_178 -> V_369 ) ;
F_113 ( V_178 -> V_369 ) ;
V_178 -> V_369 = NULL ;
}
F_12 ( 4 , L_69 , V_29 ) ;
return;
}
static void F_103 ( struct V_1 * V_25 , int V_372 )
{
if ( V_372 )
F_8 ( V_25 ) ;
V_25 -> V_285 -> V_43 = V_25 -> V_285 -> V_45 -> V_22 ;
F_15 ( & V_25 -> V_285 -> V_33 , V_290 ) ;
memcpy ( V_25 -> V_285 -> V_44 ,
V_25 -> V_285 -> V_45 -> V_28 , F_20 ) ;
V_25 -> V_285 -> V_42 = F_20 ;
F_21 ( V_25 -> V_285 -> V_30 , V_25 -> V_39 ,
F_22 ( V_25 -> V_39 , 2 ) ,
V_25 -> V_285 -> V_44 ,
F_20 , F_17 ,
V_25 -> V_285 ) ;
F_148 ( & V_25 -> V_301 , V_373 + V_352 ) ;
}
static int F_149 ( struct V_374 * V_309 ,
const struct V_375 * V_114 )
{
struct V_1 * V_25 = NULL ;
struct V_376 * V_377 ;
struct V_378 * V_379 ;
int V_23 ;
int V_179 = - V_206 ;
T_2 * V_324 ;
int V_43 ;
F_12 ( 2 , L_1 , V_29 ) ;
V_25 = F_72 ( sizeof( struct V_1 ) , V_205 ) ;
if ( V_25 == NULL ) {
F_19 ( & V_309 -> V_25 , L_120 ) ;
return - V_206 ;
}
F_15 ( & V_25 -> V_306 , 0 ) ;
V_25 -> V_241 = V_114 -> V_380 ;
V_25 -> V_285 = F_72 ( sizeof( struct V_27 ) , V_205 ) ;
if ( ! V_25 -> V_285 )
goto V_381;
F_150 ( & V_25 -> V_296 ) ;
V_25 -> V_39 = F_151 ( F_152 ( V_309 ) ) ;
if ( V_25 -> V_39 == NULL ) {
F_18 ( & V_309 -> V_25 , L_121 ) ;
V_179 = - V_287 ;
goto V_382;
}
F_12 ( 1 , L_122 , V_25 ,
V_25 -> V_39 , V_309 ) ;
V_25 -> V_309 = V_309 ;
V_377 = V_309 -> V_383 ;
F_12 ( 1 , L_123 , V_377 -> V_384 . V_385 ) ;
for ( V_23 = 0 ; V_23 < V_377 -> V_384 . V_385 ; ++ V_23 ) {
V_379 = & V_377 -> V_379 [ V_23 ] . V_384 ;
if ( ! V_25 -> V_368 && F_153 ( V_379 ) ) {
V_25 -> V_368 = V_379 -> V_386 ;
}
}
if ( ! V_25 -> V_368 ) {
F_18 ( & V_309 -> V_25 , L_124 ) ;
goto V_387;
}
F_154 ( & V_25 -> V_301 ) ;
V_25 -> V_301 . V_388 = F_11 ;
V_25 -> V_301 . V_28 = ( unsigned long ) V_25 -> V_285 ;
F_155 ( & V_25 -> V_285 -> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_310 ; V_23 ++ ) {
struct V_47 * V_48 = & V_25 -> V_48 [ V_23 ] ;
V_25 -> V_48 [ V_23 ] . V_107 = V_23 ;
F_155 ( & V_48 -> V_211 ) ;
F_155 ( & V_48 -> V_217 ) ;
}
V_25 -> V_285 -> V_30 = F_147 ( 0 , V_205 ) ;
if ( ! V_25 -> V_285 -> V_30 ) {
F_18 ( & V_309 -> V_25 , L_101 ) ;
goto V_389;
}
V_25 -> V_285 -> V_44 = F_72 ( F_20 , V_205 ) ;
if ( ! V_25 -> V_285 -> V_44 ) {
F_18 ( & V_309 -> V_25 , L_101 ) ;
goto V_390;
}
if ( F_156 ( & V_25 -> V_285 -> V_45 ,
V_391 , & V_25 -> V_39 -> V_25 ) ) {
F_14 ( V_32 L_125 ) ;
goto V_392;
}
V_43 = V_25 -> V_285 -> V_45 -> V_22 ;
V_324 = ( T_2 * ) & V_25 -> V_285 -> V_45 -> V_28 [ V_43 - 8 ] ;
if ( * V_324 != V_393 ) {
F_14 ( V_291 L_126 ) ;
V_179 = - V_287 ;
goto V_394;
} else {
T_2 * V_395 ;
V_395 = ( T_2 * ) & V_25 -> V_285 -> V_45 -> V_28 [ V_43 - 4 ] ;
F_14 ( V_291 L_127 , * V_395 ) ;
V_25 -> V_238 = F_132 ( * V_395 ) ;
if ( V_25 -> V_238 < V_396 )
F_14 ( V_291 L_128 ) ;
if ( V_25 -> V_241 == 0x2257 &&
V_25 -> V_238 < V_252 )
F_14 ( V_314 L_129
L_130 , V_252 ) ;
}
F_157 ( V_25 -> V_39 ) ;
V_179 = F_142 ( V_25 ) ;
if ( V_179 )
goto V_397;
F_158 ( & V_25 -> V_57 ) ;
F_103 ( V_25 , 0 ) ;
V_179 = F_124 ( V_25 ) ;
if ( V_179 )
goto V_397;
F_71 ( & V_309 -> V_25 , L_131 ) ;
return 0 ;
V_397:
F_110 ( V_25 ) ;
V_394:
F_114 ( V_25 -> V_285 -> V_45 ) ;
V_392:
F_74 ( V_25 -> V_285 -> V_44 ) ;
V_390:
F_113 ( V_25 -> V_285 -> V_30 ) ;
V_389:
F_111 ( & V_25 -> V_301 ) ;
V_387:
F_116 ( V_25 -> V_39 ) ;
V_382:
F_74 ( V_25 -> V_285 ) ;
F_115 ( & V_25 -> V_296 ) ;
V_381:
F_74 ( V_25 ) ;
F_14 ( V_314 L_132 , V_179 ) ;
return V_179 ;
}
static void F_159 ( struct V_374 * V_309 )
{
struct V_1 * V_25 = F_1 ( F_160 ( V_309 ) ) ;
int V_23 ;
int V_398 = F_102 ( & V_25 -> V_306 ) ;
F_55 ( & V_25 -> V_296 ) ;
F_161 ( & V_25 -> V_3 ) ;
F_58 ( & V_25 -> V_296 ) ;
F_129 ( & V_25 -> V_306 ) ;
for ( V_23 = 0 ; V_23 < V_398 ; V_23 ++ )
F_162 ( & V_25 -> V_48 [ V_23 ] . V_5 ) ;
F_15 ( & V_25 -> V_285 -> V_33 , V_286 ) ;
F_16 ( & V_25 -> V_285 -> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_310 ; V_23 ++ ) {
V_25 -> V_48 [ V_23 ] . V_209 = 1 ;
F_16 ( & V_25 -> V_48 [ V_23 ] . V_211 ) ;
V_25 -> V_48 [ V_23 ] . V_216 = 1 ;
F_16 ( & V_25 -> V_48 [ V_23 ] . V_217 ) ;
}
if ( F_123 ( & V_25 -> V_306 ) )
F_109 ( V_25 ) ;
F_71 ( & V_309 -> V_25 , L_1 , V_29 ) ;
}
