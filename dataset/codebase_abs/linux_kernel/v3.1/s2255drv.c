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
struct V_76 * V_77 ;
if ( ! V_74 )
return;
V_75 = V_48 -> V_75 ;
if ( V_75 != - 1 ) {
V_77 = & V_48 -> V_78 . V_79 [ V_75 ] ;
V_73 =
( const char * ) V_48 -> V_78 . V_79 [ V_75 ] . V_80 ;
switch ( V_54 -> V_18 -> V_66 ) {
case V_24 :
case V_81 :
F_7 ( ( const unsigned char * ) V_73 ,
V_74 , V_54 -> V_61 . V_16 ,
V_54 -> V_61 . V_17 ,
V_54 -> V_18 -> V_66 ) ;
break;
case V_82 :
memcpy ( V_74 , V_73 , V_54 -> V_61 . V_16 * V_54 -> V_61 . V_17 ) ;
break;
case V_69 :
case V_70 :
V_54 -> V_61 . V_22 = V_49 ;
memcpy ( V_74 , V_73 , V_54 -> V_61 . V_22 ) ;
break;
case V_83 :
memcpy ( V_74 , V_73 ,
V_54 -> V_61 . V_16 * V_54 -> V_61 . V_17 * 2 ) ;
break;
default:
F_14 ( V_84 L_11 ) ;
}
V_48 -> V_75 = - 1 ;
} else {
F_14 ( V_32 L_12 ) ;
return;
}
F_12 ( 2 , L_13 ,
( unsigned long ) V_74 , V_71 ) ;
V_54 -> V_61 . V_85 = V_48 -> V_86 * 2 ;
F_28 ( & V_63 ) ;
V_54 -> V_61 . V_63 = V_63 ;
V_54 -> V_61 . V_87 = V_88 ;
}
static int F_34 ( struct V_89 * V_90 , unsigned int * V_91 ,
unsigned int * V_22 )
{
struct V_92 * V_93 = V_90 -> V_94 ;
struct V_47 * V_48 = V_93 -> V_48 ;
* V_22 = V_48 -> V_16 * V_48 -> V_17 * ( V_48 -> V_18 -> V_95 >> 3 ) ;
if ( 0 == * V_91 )
* V_91 = V_96 ;
if ( * V_22 * * V_91 > V_97 * 1024 * 1024 )
* V_91 = ( V_97 * 1024 * 1024 ) / * V_22 ;
return 0 ;
}
static void F_35 ( struct V_89 * V_90 , struct V_53 * V_54 )
{
F_12 ( 4 , L_1 , V_29 ) ;
F_36 ( & V_54 -> V_61 ) ;
V_54 -> V_61 . V_87 = V_98 ;
}
static int F_37 ( struct V_89 * V_90 , struct V_99 * V_61 ,
enum V_100 V_101 )
{
struct V_92 * V_93 = V_90 -> V_94 ;
struct V_47 * V_48 = V_93 -> V_48 ;
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
int V_56 ;
int V_102 = V_48 -> V_16 ;
int V_103 = V_48 -> V_17 ;
F_12 ( 4 , L_14 , V_29 , V_101 ) ;
if ( V_48 -> V_18 == NULL )
return - V_104 ;
if ( ( V_102 < F_5 ( & V_48 -> V_5 ) ) ||
( V_102 > F_3 ( & V_48 -> V_5 ) ) ||
( V_103 < F_6 ( & V_48 -> V_5 ) ) ||
( V_103 > F_4 ( & V_48 -> V_5 ) ) ) {
F_12 ( 4 , L_15 ) ;
return - V_104 ;
}
V_54 -> V_61 . V_22 = V_102 * V_103 * ( V_48 -> V_18 -> V_95 >> 3 ) ;
if ( 0 != V_54 -> V_61 . V_105 && V_54 -> V_61 . V_106 < V_54 -> V_61 . V_22 ) {
F_12 ( 4 , L_15 ) ;
return - V_104 ;
}
V_54 -> V_18 = V_48 -> V_18 ;
V_54 -> V_61 . V_16 = V_102 ;
V_54 -> V_61 . V_17 = V_103 ;
V_54 -> V_61 . V_101 = V_101 ;
if ( V_98 == V_54 -> V_61 . V_87 ) {
V_56 = F_38 ( V_90 , & V_54 -> V_61 , NULL ) ;
if ( V_56 < 0 )
goto V_107;
}
V_54 -> V_61 . V_87 = V_108 ;
return 0 ;
V_107:
F_35 ( V_90 , V_54 ) ;
return V_56 ;
}
static void F_39 ( struct V_89 * V_90 , struct V_99 * V_61 )
{
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
struct V_92 * V_93 = V_90 -> V_94 ;
struct V_47 * V_48 = V_93 -> V_48 ;
struct V_50 * V_52 = & V_48 -> V_52 ;
F_12 ( 1 , L_1 , V_29 ) ;
V_54 -> V_61 . V_87 = V_109 ;
F_40 ( & V_54 -> V_61 . V_62 , & V_52 -> V_58 ) ;
}
static void F_41 ( struct V_89 * V_90 ,
struct V_99 * V_61 )
{
struct V_53 * V_54 = F_2 ( V_61 , struct V_53 , V_61 ) ;
struct V_92 * V_93 = V_90 -> V_94 ;
F_12 ( 4 , L_16 , V_29 , V_93 -> V_48 -> V_110 ) ;
F_35 ( V_90 , V_54 ) ;
}
static int F_42 ( struct V_92 * V_93 )
{
struct V_47 * V_48 = V_93 -> V_48 ;
if ( V_48 -> V_111 )
return 0 ;
V_48 -> V_111 = 1 ;
V_93 -> V_111 = 1 ;
F_12 ( 1 , L_17 ) ;
return 1 ;
}
static int F_43 ( struct V_92 * V_93 )
{
return V_93 -> V_48 -> V_111 ;
}
static int F_44 ( struct V_92 * V_93 )
{
return V_93 -> V_111 ;
}
static void F_45 ( struct V_92 * V_93 )
{
struct V_47 * V_48 = V_93 -> V_48 ;
V_48 -> V_111 = 0 ;
V_93 -> V_111 = 0 ;
F_12 ( 1 , L_18 ) ;
}
static int F_46 ( struct V_112 * V_112 , void * V_113 ,
struct V_114 * V_115 )
{
static const char * V_116 [] = {
L_19 ,
L_20 ,
NULL
} ;
if ( V_115 -> V_117 == V_118 ) {
int V_23 ;
const char * * V_119 = V_116 ;
for ( V_23 = 0 ; V_23 < V_115 -> V_120 && V_119 [ V_23 ] ; V_23 ++ )
;
if ( V_119 [ V_23 ] == NULL || V_119 [ V_23 ] [ 0 ] == '\0' )
return - V_104 ;
F_47 ( V_115 -> V_121 , V_119 [ V_115 -> V_120 ] ,
sizeof( V_115 -> V_121 ) ) ;
return 0 ;
}
return F_48 ( V_115 , NULL , NULL ) ;
}
static int F_49 ( struct V_112 * V_112 , void * V_113 ,
struct V_122 * V_123 )
{
struct V_92 * V_93 = V_112 -> V_124 ;
struct V_1 * V_25 = V_93 -> V_25 ;
F_47 ( V_123 -> V_125 , L_21 , sizeof( V_123 -> V_125 ) ) ;
F_47 ( V_123 -> V_126 , L_21 , sizeof( V_123 -> V_126 ) ) ;
F_50 ( V_25 -> V_39 , V_123 -> V_127 , sizeof( V_123 -> V_127 ) ) ;
V_123 -> V_128 = V_129 | V_130 ;
return 0 ;
}
static int F_51 ( struct V_112 * V_112 , void * V_113 ,
struct V_131 * V_132 )
{
int V_120 = 0 ;
if ( V_132 )
V_120 = V_132 -> V_120 ;
if ( V_120 >= F_32 ( V_67 ) )
return - V_104 ;
if ( ! V_68 && ( ( V_67 [ V_120 ] . V_66 == V_69 ) ||
( V_67 [ V_120 ] . V_66 == V_70 ) ) )
return - V_104 ;
F_12 ( 4 , L_22 , V_67 [ V_120 ] . V_121 ) ;
F_47 ( V_132 -> V_133 , V_67 [ V_120 ] . V_121 , sizeof( V_132 -> V_133 ) ) ;
V_132 -> V_134 = V_67 [ V_120 ] . V_66 ;
return 0 ;
}
static int F_52 ( struct V_112 * V_112 , void * V_113 ,
struct V_135 * V_132 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
V_132 -> V_18 . V_136 . V_16 = V_48 -> V_16 ;
V_132 -> V_18 . V_136 . V_17 = V_48 -> V_17 ;
V_132 -> V_18 . V_136 . V_101 = V_93 -> V_137 . V_101 ;
V_132 -> V_18 . V_136 . V_134 = V_48 -> V_18 -> V_66 ;
V_132 -> V_18 . V_136 . V_138 = V_132 -> V_18 . V_136 . V_16 * ( V_48 -> V_18 -> V_95 >> 3 ) ;
V_132 -> V_18 . V_136 . V_139 = V_132 -> V_18 . V_136 . V_17 * V_132 -> V_18 . V_136 . V_138 ;
return 0 ;
}
static int F_53 ( struct V_112 * V_112 , void * V_113 ,
struct V_135 * V_132 )
{
const struct V_65 * V_18 ;
enum V_100 V_101 ;
int V_140 = 0 ;
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
int V_141 ;
V_141 =
( V_48 -> V_5 . V_6 & V_7 ) ? 1 : 0 ;
V_18 = F_31 ( V_132 -> V_18 . V_136 . V_134 ) ;
if ( V_18 == NULL )
return - V_104 ;
V_101 = V_132 -> V_18 . V_136 . V_101 ;
if ( V_101 == V_142 )
V_140 = 1 ;
F_12 ( 50 , L_23 ,
V_29 , V_141 , V_132 -> V_18 . V_136 . V_16 , V_132 -> V_18 . V_136 . V_17 ) ;
if ( V_141 ) {
if ( V_132 -> V_18 . V_136 . V_17 >= V_10 * 2 ) {
V_132 -> V_18 . V_136 . V_17 = V_10 * 2 ;
if ( V_140 ) {
V_101 = V_143 ;
} else if ( ! ( ( V_101 == V_144 ) ||
( V_101 == V_143 ) ||
( V_101 == V_145 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_104 ;
}
} else {
V_132 -> V_18 . V_136 . V_17 = V_10 ;
if ( V_140 ) {
V_101 = V_146 ;
} else if ( ! ( ( V_101 == V_146 ) ||
( V_101 == V_147 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_104 ;
}
}
if ( V_132 -> V_18 . V_136 . V_16 >= V_8 )
V_132 -> V_18 . V_136 . V_16 = V_8 ;
else if ( V_132 -> V_18 . V_136 . V_16 >= V_148 )
V_132 -> V_18 . V_136 . V_16 = V_148 ;
else if ( V_132 -> V_18 . V_136 . V_16 >= V_12 )
V_132 -> V_18 . V_136 . V_16 = V_12 ;
else
V_132 -> V_18 . V_136 . V_16 = V_12 ;
} else {
if ( V_132 -> V_18 . V_136 . V_17 >= V_11 * 2 ) {
V_132 -> V_18 . V_136 . V_17 = V_11 * 2 ;
if ( V_140 ) {
V_101 = V_143 ;
} else if ( ! ( ( V_101 == V_144 ) ||
( V_101 == V_143 ) ||
( V_101 == V_145 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_104 ;
}
} else {
V_132 -> V_18 . V_136 . V_17 = V_11 ;
if ( V_140 ) {
V_101 = V_146 ;
} else if ( ! ( ( V_101 == V_146 ) ||
( V_101 == V_147 ) ) ) {
F_12 ( 1 , L_24 ) ;
return - V_104 ;
}
}
if ( V_132 -> V_18 . V_136 . V_16 >= V_9 ) {
V_132 -> V_18 . V_136 . V_16 = V_9 ;
V_101 = V_143 ;
} else if ( V_132 -> V_18 . V_136 . V_16 >= V_149 ) {
V_132 -> V_18 . V_136 . V_16 = V_149 ;
V_101 = V_146 ;
} else if ( V_132 -> V_18 . V_136 . V_16 >= V_13 ) {
V_132 -> V_18 . V_136 . V_16 = V_13 ;
V_101 = V_146 ;
} else {
V_132 -> V_18 . V_136 . V_16 = V_13 ;
V_101 = V_146 ;
}
}
V_132 -> V_18 . V_136 . V_101 = V_101 ;
V_132 -> V_18 . V_136 . V_138 = ( V_132 -> V_18 . V_136 . V_16 * V_18 -> V_95 ) >> 3 ;
V_132 -> V_18 . V_136 . V_139 = V_132 -> V_18 . V_136 . V_17 * V_132 -> V_18 . V_136 . V_138 ;
F_12 ( 50 , L_25 , V_29 ,
V_132 -> V_18 . V_136 . V_16 , V_132 -> V_18 . V_136 . V_17 , V_132 -> V_18 . V_136 . V_101 ) ;
return 0 ;
}
static int F_54 ( struct V_112 * V_112 , void * V_113 ,
struct V_135 * V_132 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
const struct V_65 * V_18 ;
struct V_89 * V_150 = & V_93 -> V_137 ;
struct V_151 V_152 ;
int V_153 ;
int V_154 ;
V_153 = F_53 ( V_112 , V_93 , V_132 ) ;
if ( V_153 < 0 )
return V_153 ;
V_18 = F_31 ( V_132 -> V_18 . V_136 . V_134 ) ;
if ( V_18 == NULL )
return - V_104 ;
F_55 ( & V_150 -> V_155 ) ;
if ( F_56 ( & V_93 -> V_137 ) ) {
F_12 ( 1 , L_26 ) ;
V_153 = - V_156 ;
goto V_157;
}
if ( F_43 ( V_93 ) ) {
F_12 ( 1 , L_27 , V_29 ) ;
V_153 = - V_156 ;
goto V_157;
}
V_152 = V_48 -> V_152 ;
V_48 -> V_18 = V_18 ;
V_48 -> V_16 = V_132 -> V_18 . V_136 . V_16 ;
V_48 -> V_17 = V_132 -> V_18 . V_136 . V_17 ;
V_93 -> V_137 . V_101 = V_132 -> V_18 . V_136 . V_101 ;
V_93 -> type = V_132 -> type ;
V_154 = F_5 ( & V_48 -> V_5 ) ;
if ( V_48 -> V_16 > F_5 ( & V_48 -> V_5 ) ) {
if ( V_48 -> V_17 > F_6 ( & V_48 -> V_5 ) ) {
if ( V_48 -> V_158 . V_159 &
V_160 )
V_152 . V_161 = V_162 ;
else
V_152 . V_161 = V_163 ;
} else
V_152 . V_161 = V_164 ;
} else {
V_152 . V_161 = V_165 ;
}
switch ( V_48 -> V_18 -> V_66 ) {
case V_82 :
V_152 . V_166 &= ~ V_167 ;
V_152 . V_166 |= V_168 ;
break;
case V_69 :
case V_70 :
V_152 . V_166 &= ~ V_167 ;
V_152 . V_166 |= V_169 ;
V_152 . V_166 |= ( V_48 -> V_170 . V_171 << 8 ) ;
break;
case V_83 :
V_152 . V_166 &= ~ V_167 ;
V_152 . V_166 |= V_172 ;
break;
case V_24 :
case V_81 :
default:
V_152 . V_166 &= ~ V_167 ;
V_152 . V_166 |= V_173 ;
break;
}
if ( ( V_152 . V_166 & V_167 ) != ( V_48 -> V_152 . V_166 & V_167 ) )
V_152 . V_174 = 1 ;
else if ( V_152 . V_161 != V_48 -> V_152 . V_161 )
V_152 . V_174 = 1 ;
else if ( V_152 . V_175 != V_48 -> V_152 . V_175 )
V_152 . V_174 = 1 ;
V_48 -> V_152 = V_152 ;
( void ) F_57 ( V_48 , & V_152 ) ;
V_153 = 0 ;
V_157:
F_58 ( & V_150 -> V_155 ) ;
return V_153 ;
}
static int F_59 ( struct V_112 * V_112 , void * V_113 ,
struct V_176 * V_177 )
{
int V_56 ;
struct V_92 * V_93 = V_113 ;
V_56 = F_60 ( & V_93 -> V_137 , V_177 ) ;
return V_56 ;
}
static int F_61 ( struct V_112 * V_112 , void * V_113 , struct V_178 * V_177 )
{
int V_56 ;
struct V_92 * V_93 = V_113 ;
V_56 = F_62 ( & V_93 -> V_137 , V_177 ) ;
return V_56 ;
}
static int F_63 ( struct V_112 * V_112 , void * V_113 , struct V_178 * V_177 )
{
int V_56 ;
struct V_92 * V_93 = V_113 ;
V_56 = F_64 ( & V_93 -> V_137 , V_177 ) ;
return V_56 ;
}
static int F_65 ( struct V_112 * V_112 , void * V_113 , struct V_178 * V_177 )
{
int V_56 ;
struct V_92 * V_93 = V_113 ;
V_56 = F_66 ( & V_93 -> V_137 , V_177 , V_112 -> V_179 & V_180 ) ;
return V_56 ;
}
static int F_67 ( struct V_38 * V_39 , unsigned char * V_181 ,
int V_22 )
{
int V_182 ;
int V_64 ;
long V_183 = - 1 ;
if ( V_39 ) {
V_182 = F_22 ( V_39 , V_184 ) ;
V_183 = F_68 ( V_39 , V_182 , V_181 , V_22 , & V_64 , 500 ) ;
}
return V_183 ;
}
static T_1 F_69 ( struct V_151 * V_152 )
{
int V_185 = V_186 ;
int V_187 = V_188 ;
T_1 V_189 ;
T_1 V_190 ;
unsigned int V_191 ;
if ( V_152 == NULL )
return 0 ;
if ( V_152 -> V_175 == V_192 ) {
switch ( V_152 -> V_161 ) {
case V_163 :
case V_162 :
V_185 = V_193 * 2 ;
V_187 = V_8 ;
break;
case V_164 :
V_185 = V_194 ;
V_187 = V_148 ;
break;
case V_165 :
V_185 = V_10 ;
V_187 = V_12 ;
break;
default:
break;
}
} else if ( V_152 -> V_175 == V_195 ) {
switch ( V_152 -> V_161 ) {
case V_163 :
case V_162 :
V_185 = V_196 * 2 ;
V_187 = V_9 ;
break;
case V_164 :
V_185 = V_197 ;
V_187 = V_149 ;
break;
case V_165 :
V_185 = V_11 ;
V_187 = V_13 ;
break;
default:
break;
}
}
V_189 = V_185 * V_187 ;
if ( ( V_152 -> V_166 & V_167 ) != V_168 ) {
V_189 *= 2 ;
}
V_190 = V_189 + V_198 ;
V_191 = 0xffffffffUL - V_199 + 1 ;
if ( V_190 & ~ V_191 )
V_190 = ( V_190 & V_191 ) + ( V_199 ) ;
return V_190 ;
}
static void F_70 ( struct V_1 * V_200 , struct V_151 * V_152 )
{
struct V_201 * V_25 = & V_200 -> V_39 -> V_25 ;
F_71 ( V_25 , L_28 ) ;
F_71 ( V_25 , L_29 , V_152 -> V_175 , V_152 -> V_161 ) ;
F_71 ( V_25 , L_30 , V_152 -> V_202 , V_152 -> V_166 ) ;
F_71 ( V_25 , L_31 , V_152 -> V_203 ) ;
F_71 ( V_25 , L_28 ) ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_151 * V_152 )
{
int V_204 ;
T_2 * V_78 ;
unsigned long V_205 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_205 = V_206 [ V_48 -> V_110 ] ;
F_12 ( 3 , L_32 , V_29 , V_48 -> V_110 ) ;
if ( ( V_152 -> V_166 & V_167 ) == V_169 ) {
V_152 -> V_166 &= ~ V_167 ;
V_152 -> V_166 |= V_169 ;
V_152 -> V_166 &= ~ V_207 ;
V_152 -> V_166 |= ( V_48 -> V_170 . V_171 << 8 ) ;
}
V_48 -> V_152 = * V_152 ;
V_48 -> V_208 = F_69 ( V_152 ) ;
F_12 ( 1 , L_33 , V_29 , V_48 -> V_208 ) ;
V_78 = F_72 ( 512 , V_209 ) ;
if ( V_78 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_210 ;
}
V_78 [ 0 ] = V_211 ;
V_78 [ 1 ] = ( T_2 ) F_73 ( V_205 ) ;
V_78 [ 2 ] = V_212 ;
memcpy ( & V_78 [ 3 ] , & V_48 -> V_152 , sizeof( struct V_151 ) ) ;
V_48 -> V_213 = 0 ;
V_204 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_78 , 512 ) ;
if ( V_214 )
F_70 ( V_25 , V_152 ) ;
F_74 ( V_78 ) ;
if ( V_152 -> V_174 ) {
F_75 ( V_48 -> V_215 ,
( V_48 -> V_213 != 0 ) ,
F_76 ( V_216 ) ) ;
if ( V_48 -> V_213 != 1 ) {
F_14 ( V_84 L_35 ) ;
V_204 = - V_217 ;
}
}
V_48 -> V_152 . V_174 = 0 ;
F_12 ( 1 , L_36 , V_29 , V_48 -> V_110 , V_204 ) ;
return V_204 ;
}
static int F_77 ( struct V_47 * V_48 , T_1 * V_218 )
{
int V_204 ;
T_2 * V_78 ;
T_1 V_205 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_205 = V_206 [ V_48 -> V_110 ] ;
F_12 ( 4 , L_37 , V_29 , V_48 -> V_110 ) ;
V_78 = F_72 ( 512 , V_209 ) ;
if ( V_78 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_210 ;
}
V_78 [ 0 ] = V_211 ;
V_78 [ 1 ] = ( T_2 ) F_73 ( V_205 ) ;
V_78 [ 2 ] = V_219 ;
* V_218 = 0 ;
V_48 -> V_220 = 0 ;
V_204 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_78 , 512 ) ;
F_74 ( V_78 ) ;
F_75 ( V_48 -> V_221 ,
( V_48 -> V_220 != 0 ) ,
F_76 ( V_222 ) ) ;
if ( V_48 -> V_220 != 1 ) {
F_14 ( V_84 L_38 ) ;
V_204 = - V_217 ;
}
* V_218 = V_48 -> V_223 ;
F_12 ( 4 , L_39 , V_29 , * V_218 ) ;
return V_204 ;
}
static int F_78 ( struct V_112 * V_112 , void * V_113 , enum V_224 V_23 )
{
int V_204 ;
struct V_92 * V_93 = V_113 ;
struct V_1 * V_25 = V_93 -> V_25 ;
struct V_47 * V_48 = V_93 -> V_48 ;
int V_225 ;
F_12 ( 4 , L_1 , V_29 ) ;
if ( V_93 -> type != V_226 ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_40 ) ;
return - V_104 ;
}
if ( V_23 != V_93 -> type ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_41 ) ;
return - V_104 ;
}
if ( ! F_42 ( V_93 ) ) {
F_19 ( & V_25 -> V_39 -> V_25 , L_42 ) ;
return - V_156 ;
}
V_48 -> V_75 = - 1 ;
V_48 -> V_227 = 0 ;
V_48 -> V_228 = 0 ;
V_48 -> V_86 = 0 ;
for ( V_225 = 0 ; V_225 < V_229 ; V_225 ++ ) {
V_48 -> V_78 . V_79 [ V_225 ] . V_230 = V_231 ;
V_48 -> V_78 . V_79 [ V_225 ] . V_232 = 0 ;
}
V_204 = F_79 ( & V_93 -> V_137 ) ;
if ( V_204 == 0 ) {
F_80 ( V_48 ) ;
V_48 -> V_233 = 1 ;
} else
F_45 ( V_93 ) ;
return V_204 ;
}
static int F_81 ( struct V_112 * V_112 , void * V_113 , enum V_224 V_23 )
{
struct V_92 * V_93 = V_113 ;
F_12 ( 4 , L_43 , V_29 , V_93 -> V_48 -> V_110 ) ;
if ( V_93 -> type != V_226 ) {
F_14 ( V_32 L_40 ) ;
return - V_104 ;
}
if ( V_23 != V_93 -> type ) {
F_14 ( V_32 L_44 ) ;
return - V_104 ;
}
F_82 ( V_93 -> V_48 ) ;
F_83 ( & V_93 -> V_137 ) ;
F_45 ( V_93 ) ;
return 0 ;
}
static int F_84 ( struct V_112 * V_112 , void * V_113 , T_3 * V_23 )
{
struct V_92 * V_93 = V_113 ;
struct V_151 V_152 ;
struct V_89 * V_150 = & V_93 -> V_137 ;
int V_153 = 0 ;
F_55 ( & V_150 -> V_155 ) ;
if ( F_56 ( V_150 ) ) {
F_12 ( 1 , L_26 ) ;
V_153 = - V_156 ;
goto V_234;
}
if ( F_43 ( V_93 ) ) {
F_12 ( 1 , L_45 ) ;
V_153 = - V_156 ;
goto V_234;
}
V_152 = V_93 -> V_48 -> V_152 ;
if ( * V_23 & V_7 ) {
F_12 ( 4 , L_46 , V_29 ) ;
if ( V_152 . V_175 != V_192 ) {
V_152 . V_174 = 1 ;
V_152 . V_175 = V_192 ;
V_152 . V_202 = V_235 ;
}
} else if ( * V_23 & V_236 ) {
F_12 ( 4 , L_47 , V_29 ) ;
if ( V_152 . V_175 != V_195 ) {
V_152 . V_174 = 1 ;
V_152 . V_175 = V_195 ;
V_152 . V_202 = V_235 ;
}
} else {
V_153 = - V_104 ;
}
if ( V_152 . V_174 )
F_57 ( V_93 -> V_48 , & V_152 ) ;
V_234:
F_58 ( & V_150 -> V_155 ) ;
return V_153 ;
}
static int F_85 ( struct V_112 * V_112 , void * V_113 ,
struct V_237 * V_238 )
{
struct V_92 * V_93 = V_113 ;
struct V_1 * V_25 = V_93 -> V_25 ;
struct V_47 * V_48 = V_93 -> V_48 ;
T_1 V_41 = 0 ;
if ( V_238 -> V_120 != 0 )
return - V_104 ;
V_238 -> type = V_239 ;
V_238 -> V_240 = V_241 ;
V_238 -> V_41 = 0 ;
if ( V_25 -> V_242 >= V_243 ) {
int V_56 ;
V_56 = F_77 ( V_93 -> V_48 , & V_41 ) ;
F_12 ( 4 , L_48 , V_56 , V_41 ) ;
if ( V_56 == 0 )
V_238 -> V_41 = ( V_41 & 0x01 ) ? 0
: V_244 ;
}
switch ( V_25 -> V_245 ) {
case 0x2255 :
default:
F_47 ( V_238 -> V_121 , L_49 , sizeof( V_238 -> V_121 ) ) ;
break;
case 0x2257 :
F_47 ( V_238 -> V_121 , ( V_48 -> V_110 < 2 ) ? L_49 : L_50 ,
sizeof( V_238 -> V_121 ) ) ;
break;
}
return 0 ;
}
static int F_86 ( struct V_112 * V_112 , void * V_113 , unsigned int * V_23 )
{
* V_23 = 0 ;
return 0 ;
}
static int F_87 ( struct V_112 * V_112 , void * V_113 , unsigned int V_23 )
{
if ( V_23 > 0 )
return - V_104 ;
return 0 ;
}
static int F_88 ( struct V_112 * V_112 , void * V_113 ,
struct V_246 * V_247 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
struct V_1 * V_25 = V_93 -> V_25 ;
switch ( V_247 -> V_117 ) {
case V_248 :
F_89 ( V_247 , - 127 , 127 , 1 , V_249 ) ;
break;
case V_250 :
F_89 ( V_247 , 0 , 255 , 1 , V_251 ) ;
break;
case V_252 :
F_89 ( V_247 , 0 , 255 , 1 , V_253 ) ;
break;
case V_254 :
F_89 ( V_247 , 0 , 255 , 1 , V_255 ) ;
break;
case V_118 :
if ( V_25 -> V_242 < V_256 )
return - V_104 ;
if ( ( V_25 -> V_245 == 0x2257 ) && ( V_48 -> V_110 > 1 ) )
return - V_104 ;
F_47 ( V_247 -> V_121 , L_51 , sizeof( V_247 -> V_121 ) ) ;
V_247 -> type = V_257 ;
V_247 -> V_258 = 0 ;
V_247 -> V_259 = 1 ;
V_247 -> V_260 = 1 ;
V_247 -> V_261 = 1 ;
V_247 -> V_55 = 0 ;
break;
default:
return - V_104 ;
}
F_12 ( 4 , L_52 , V_29 , V_247 -> V_117 ) ;
return 0 ;
}
static int F_90 ( struct V_112 * V_112 , void * V_113 ,
struct V_262 * V_263 )
{
struct V_92 * V_93 = V_113 ;
struct V_1 * V_25 = V_93 -> V_25 ;
struct V_47 * V_48 = V_93 -> V_48 ;
switch ( V_263 -> V_117 ) {
case V_248 :
V_263 -> V_264 = V_48 -> V_152 . V_203 ;
break;
case V_250 :
V_263 -> V_264 = V_48 -> V_152 . V_265 ;
break;
case V_252 :
V_263 -> V_264 = V_48 -> V_152 . V_266 ;
break;
case V_254 :
V_263 -> V_264 = V_48 -> V_152 . V_267 ;
break;
case V_118 :
if ( V_25 -> V_242 < V_256 )
return - V_104 ;
if ( ( V_25 -> V_245 == 0x2257 ) && ( V_48 -> V_110 > 1 ) )
return - V_104 ;
V_263 -> V_264 = ! ( ( V_48 -> V_152 . V_166 & V_268 ) >> 16 ) ;
break;
default:
return - V_104 ;
}
F_12 ( 4 , L_53 , V_29 , V_263 -> V_117 , V_263 -> V_264 ) ;
return 0 ;
}
static int F_91 ( struct V_112 * V_112 , void * V_113 ,
struct V_262 * V_263 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
struct V_151 V_152 ;
V_152 = V_48 -> V_152 ;
F_12 ( 4 , L_1 , V_29 ) ;
switch ( V_263 -> V_117 ) {
case V_248 :
V_152 . V_203 = V_263 -> V_264 ;
break;
case V_250 :
V_152 . V_265 = V_263 -> V_264 ;
break;
case V_254 :
V_152 . V_267 = V_263 -> V_264 ;
break;
case V_252 :
V_152 . V_266 = V_263 -> V_264 ;
break;
case V_118 :
if ( V_25 -> V_242 < V_256 )
return - V_104 ;
if ( ( V_25 -> V_245 == 0x2257 ) && ( V_48 -> V_110 > 1 ) )
return - V_104 ;
V_152 . V_166 &= ~ V_268 ;
V_152 . V_166 |= ( ( V_263 -> V_264 ? 0 : 1 ) << 16 ) ;
break;
default:
return - V_104 ;
}
V_152 . V_174 = 0 ;
F_57 ( V_93 -> V_48 , & V_152 ) ;
return 0 ;
}
static int F_92 ( struct V_112 * V_112 , void * V_113 ,
struct V_269 * V_170 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
* V_170 = V_48 -> V_170 ;
F_12 ( 2 , L_54 , V_29 , V_170 -> V_171 ) ;
return 0 ;
}
static int F_93 ( struct V_112 * V_112 , void * V_113 ,
struct V_269 * V_170 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
if ( V_170 -> V_171 < 0 || V_170 -> V_171 > 100 )
return - V_104 ;
V_48 -> V_170 . V_171 = V_170 -> V_171 ;
F_12 ( 2 , L_54 , V_29 , V_170 -> V_171 ) ;
return 0 ;
}
static int F_94 ( struct V_112 * V_112 , void * V_113 ,
struct V_270 * V_271 )
{
struct V_92 * V_93 = V_113 ;
T_4 V_272 , V_273 ;
struct V_47 * V_48 = V_93 -> V_48 ;
if ( V_271 -> type != V_226 )
return - V_104 ;
memset ( V_271 , 0 , sizeof( struct V_270 ) ) ;
V_271 -> V_274 . V_275 . V_276 = V_277 ;
V_271 -> V_274 . V_275 . V_159 = V_48 -> V_158 . V_159 ;
V_272 = ( V_48 -> V_152 . V_175 == V_192 ) ? 1001 : 1000 ;
V_273 = ( V_48 -> V_152 . V_175 == V_192 ) ? 30000 : 25000 ;
V_271 -> V_274 . V_275 . V_278 . V_279 = V_273 ;
switch ( V_48 -> V_152 . V_202 ) {
default:
case V_235 :
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 ;
break;
case V_281 :
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 * 2 ;
break;
case V_282 :
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 * 3 ;
break;
case V_283 :
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 * 5 ;
break;
}
F_12 ( 4 , L_55 , V_29 ,
V_271 -> V_274 . V_275 . V_159 ,
V_271 -> V_274 . V_275 . V_278 . V_280 ,
V_271 -> V_274 . V_275 . V_278 . V_279 ) ;
return 0 ;
}
static int F_95 ( struct V_112 * V_112 , void * V_113 ,
struct V_270 * V_271 )
{
struct V_92 * V_93 = V_113 ;
struct V_47 * V_48 = V_93 -> V_48 ;
struct V_151 V_152 ;
int V_202 = V_235 ;
T_4 V_272 , V_273 ;
if ( V_271 -> type != V_226 )
return - V_104 ;
V_152 = V_48 -> V_152 ;
if ( V_48 -> V_158 . V_159
!= V_271 -> V_274 . V_275 . V_159 && F_43 ( V_93 ) )
return - V_156 ;
V_272 = ( V_152 . V_175 == V_192 ) ? 1001 : 1000 ;
V_273 = ( V_152 . V_175 == V_192 ) ? 30000 : 25000 ;
if ( V_273 != V_271 -> V_274 . V_275 . V_278 . V_279 )
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 ;
else if ( V_271 -> V_274 . V_275 . V_278 . V_280 <= V_272 )
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 ;
else if ( V_271 -> V_274 . V_275 . V_278 . V_280 <= ( V_272 * 2 ) ) {
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 * 2 ;
V_202 = V_281 ;
} else if ( V_271 -> V_274 . V_275 . V_278 . V_280 <= ( V_272 * 3 ) ) {
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 * 3 ;
V_202 = V_282 ;
} else {
V_271 -> V_274 . V_275 . V_278 . V_280 = V_272 * 5 ;
V_202 = V_283 ;
}
V_152 . V_202 = V_202 ;
V_271 -> V_274 . V_275 . V_278 . V_279 = V_273 ;
F_57 ( V_48 , & V_152 ) ;
F_12 ( 4 , L_56 ,
V_29 ,
V_271 -> V_274 . V_275 . V_159 ,
V_271 -> V_274 . V_275 . V_278 . V_280 ,
V_271 -> V_274 . V_275 . V_278 . V_279 , V_202 ) ;
return 0 ;
}
static int F_96 ( struct V_112 * V_112 , void * V_113 ,
struct V_284 * V_285 )
{
int V_141 = 0 ;
#define F_97 4
int V_286 [ F_97 ] = { 1 , 2 , 3 , 5 } ;
if ( V_285 -> V_120 < 0 || V_285 -> V_120 >= F_97 )
return - V_104 ;
switch ( V_285 -> V_16 ) {
case 640 :
if ( V_285 -> V_17 != 240 && V_285 -> V_17 != 480 )
return - V_104 ;
V_141 = 1 ;
break;
case 320 :
if ( V_285 -> V_17 != 240 )
return - V_104 ;
V_141 = 1 ;
break;
case 704 :
if ( V_285 -> V_17 != 288 && V_285 -> V_17 != 576 )
return - V_104 ;
break;
case 352 :
if ( V_285 -> V_17 != 288 )
return - V_104 ;
break;
default:
return - V_104 ;
}
V_285 -> type = V_287 ;
V_285 -> V_288 . V_279 = V_141 ? 30000 : 25000 ;
V_285 -> V_288 . V_280 = ( V_141 ? 1001 : 1000 ) * V_286 [ V_285 -> V_120 ] ;
F_12 ( 4 , L_57 , V_29 , V_285 -> V_288 . V_280 ,
V_285 -> V_288 . V_279 ) ;
return 0 ;
}
static int F_98 ( struct V_112 * V_112 )
{
struct V_4 * V_5 = F_99 ( V_112 ) ;
struct V_47 * V_48 = F_100 ( V_112 ) ;
struct V_1 * V_25 = F_1 ( V_5 -> V_3 ) ;
struct V_92 * V_93 ;
enum V_224 type = V_226 ;
int V_87 ;
F_12 ( 1 , L_58 ,
F_101 ( V_5 ) ) ;
F_55 ( & V_25 -> V_289 ) ;
V_87 = F_102 ( & V_25 -> V_290 -> V_33 ) ;
switch ( V_87 ) {
case V_291 :
F_58 ( & V_25 -> V_289 ) ;
return - V_292 ;
case V_34 :
F_19 ( & V_25 -> V_39 -> V_25 ,
L_59 ) ;
F_103 ( V_25 , 1 ) ;
F_75 ( V_25 -> V_290 -> V_35 ,
( ( F_102 ( & V_25 -> V_290 -> V_33 )
== V_293 ) ||
( F_102 ( & V_25 -> V_290 -> V_33 )
== V_291 ) ) ,
F_76 ( V_294 ) ) ;
V_87 = F_102 ( & V_25 -> V_290 -> V_33 ) ;
break;
case V_295 :
case V_46 :
F_14 ( V_296 L_60 , V_29 ) ;
F_75 ( V_25 -> V_290 -> V_35 ,
( ( F_102 ( & V_25 -> V_290 -> V_33 )
== V_293 ) ||
( F_102 ( & V_25 -> V_290 -> V_33 )
== V_291 ) ) ,
F_76 ( V_294 ) ) ;
V_87 = F_102 ( & V_25 -> V_290 -> V_33 ) ;
break;
case V_293 :
default:
break;
}
switch ( V_87 ) {
case V_293 :
break;
case V_34 :
F_14 ( V_296 L_61 ) ;
F_58 ( & V_25 -> V_289 ) ;
return - V_292 ;
case V_291 :
F_14 ( V_296 L_62 , V_29 ) ;
F_58 ( & V_25 -> V_289 ) ;
return - V_292 ;
case V_46 :
case V_295 :
F_14 ( V_296 L_63
L_64 ,
V_29 ) ;
F_15 ( & V_25 -> V_290 -> V_33 ,
V_34 ) ;
F_58 ( & V_25 -> V_289 ) ;
return - V_297 ;
default:
F_14 ( V_296 L_65 , V_29 ) ;
F_58 ( & V_25 -> V_289 ) ;
return - V_217 ;
}
F_58 ( & V_25 -> V_289 ) ;
V_93 = F_72 ( sizeof( * V_93 ) , V_209 ) ;
if ( NULL == V_93 )
return - V_210 ;
V_112 -> V_124 = V_93 ;
V_93 -> V_25 = V_25 ;
V_93 -> type = V_226 ;
V_93 -> V_48 = V_48 ;
if ( ! V_48 -> V_298 ) {
V_48 -> V_18 = & V_67 [ 0 ] ;
F_57 ( V_48 , & V_48 -> V_152 ) ;
V_48 -> V_298 = 1 ;
}
F_12 ( 1 , L_66 , V_29 ,
F_101 ( V_5 ) , V_299 [ type ] ) ;
F_12 ( 2 , L_67 , V_29 ,
( unsigned long ) V_93 , ( unsigned long ) V_25 ,
( unsigned long ) & V_48 -> V_52 ) ;
F_12 ( 4 , L_68 , V_29 ,
F_25 ( & V_48 -> V_52 . V_58 ) ) ;
F_104 ( & V_93 -> V_137 , & V_300 ,
NULL , & V_25 -> V_57 ,
V_93 -> type ,
V_144 ,
sizeof( struct V_53 ) ,
V_93 , V_5 -> V_301 ) ;
return 0 ;
}
static unsigned int F_105 ( struct V_112 * V_112 ,
struct V_302 * V_303 )
{
struct V_92 * V_93 = V_112 -> V_124 ;
int V_56 ;
F_12 ( 100 , L_1 , V_29 ) ;
if ( V_226 != V_93 -> type )
return V_304 ;
V_56 = F_106 ( V_112 , & V_93 -> V_137 , V_303 ) ;
return V_56 ;
}
static void F_107 ( struct V_1 * V_25 )
{
F_108 ( V_25 ) ;
F_109 ( & V_25 -> V_305 ) ;
if ( V_25 -> V_290 -> V_30 ) {
F_110 ( V_25 -> V_290 -> V_30 ) ;
F_111 ( V_25 -> V_290 -> V_30 ) ;
V_25 -> V_290 -> V_30 = NULL ;
}
if ( V_25 -> V_290 -> V_45 )
F_112 ( V_25 -> V_290 -> V_45 ) ;
F_74 ( V_25 -> V_290 -> V_44 ) ;
F_74 ( V_25 -> V_290 ) ;
F_8 ( V_25 ) ;
F_113 ( & V_25 -> V_289 ) ;
F_113 ( & V_25 -> V_301 ) ;
F_114 ( V_25 -> V_39 ) ;
F_115 ( & V_25 -> V_3 ) ;
F_12 ( 1 , L_69 , V_29 ) ;
F_74 ( V_25 ) ;
}
static int F_116 ( struct V_112 * V_112 )
{
struct V_92 * V_93 = V_112 -> V_124 ;
struct V_1 * V_25 = V_93 -> V_25 ;
struct V_4 * V_5 = F_99 ( V_112 ) ;
struct V_47 * V_48 = V_93 -> V_48 ;
if ( ! V_25 )
return - V_292 ;
if ( F_44 ( V_93 ) ) {
if ( V_48 -> V_233 )
F_82 ( V_93 -> V_48 ) ;
F_83 ( & V_93 -> V_137 ) ;
F_45 ( V_93 ) ;
}
F_117 ( & V_93 -> V_137 ) ;
F_12 ( 1 , L_70 , V_29 , F_101 ( V_5 ) ) ;
F_74 ( V_93 ) ;
return 0 ;
}
static int F_118 ( struct V_112 * V_112 , struct V_306 * V_307 )
{
struct V_92 * V_93 = V_112 -> V_124 ;
int V_153 ;
if ( ! V_93 )
return - V_292 ;
F_12 ( 4 , L_71 , V_29 , ( unsigned long ) V_307 ) ;
V_153 = F_119 ( & V_93 -> V_137 , V_307 ) ;
F_12 ( 4 , L_72 , V_29 ,
( unsigned long ) V_307 -> V_308 ,
( unsigned long ) V_307 -> V_309 - ( unsigned long ) V_307 -> V_308 , V_153 ) ;
return V_153 ;
}
static void F_120 ( struct V_4 * V_5 )
{
struct V_1 * V_25 = F_1 ( V_5 -> V_3 ) ;
F_12 ( 4 , L_73 , V_29 ,
F_102 ( & V_25 -> V_310 ) ) ;
if ( F_121 ( & V_25 -> V_310 ) )
F_107 ( V_25 ) ;
return;
}
static int F_122 ( struct V_1 * V_25 )
{
int V_153 ;
int V_23 ;
int V_311 = V_312 ;
struct V_47 * V_48 ;
V_153 = F_123 ( & V_25 -> V_313 -> V_25 , & V_25 -> V_3 ) ;
if ( V_153 )
return V_153 ;
for ( V_23 = 0 ; V_23 < V_314 ; V_23 ++ ) {
V_48 = & V_25 -> V_48 [ V_23 ] ;
F_124 ( & V_48 -> V_52 . V_58 ) ;
V_48 -> V_52 . V_25 = V_25 ;
V_48 -> V_5 = V_315 ;
V_48 -> V_5 . V_301 = & V_25 -> V_301 ;
V_48 -> V_5 . V_3 = & V_25 -> V_3 ;
F_125 ( & V_48 -> V_5 , V_48 ) ;
if ( V_312 == - 1 )
V_153 = F_126 ( & V_48 -> V_5 ,
V_316 ,
V_312 ) ;
else
V_153 = F_126 ( & V_48 -> V_5 ,
V_316 ,
V_311 + V_23 ) ;
if ( V_153 ) {
F_18 ( & V_25 -> V_39 -> V_25 ,
L_74 ) ;
break;
}
F_127 ( & V_25 -> V_310 ) ;
F_128 ( & V_25 -> V_3 , L_75 ,
F_101 ( & V_48 -> V_5 ) ) ;
}
F_14 ( V_296 L_76 ,
V_317 ) ;
if ( F_102 ( & V_25 -> V_310 ) == 0 ) {
F_115 ( & V_25 -> V_3 ) ;
return V_153 ;
}
if ( F_102 ( & V_25 -> V_310 ) != V_314 )
F_14 ( V_318 L_77 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_25 , struct V_319 * V_320 )
{
char * V_321 ;
T_1 V_322 = 0 ;
int V_323 = 0 ;
char * V_324 ;
unsigned long V_325 ;
unsigned long V_22 ;
T_5 V_110 = - 1 ;
struct V_76 * V_77 ;
unsigned char * V_326 ;
struct V_47 * V_48 ;
F_12 ( 100 , L_78 ) ;
V_48 = & V_25 -> V_48 [ V_25 -> V_327 ] ;
V_110 = V_48 -> V_228 ;
V_77 = & V_48 -> V_78 . V_79 [ V_110 ] ;
if ( V_77 -> V_230 == V_231 ) {
int V_328 ;
unsigned int V_327 ;
T_2 * V_329 ;
int V_330 ;
V_326 = ( unsigned char * ) V_320 -> V_331 ;
V_329 = ( T_2 * ) V_326 ;
for ( V_328 = 0 ; V_328 < ( V_320 -> V_332 - 12 ) ; V_328 ++ ) {
switch ( * V_329 ) {
case V_333 :
F_12 ( 4 , L_79
L_80 , V_328 , V_326 [ 0 ] ,
V_326 [ 1 ] ) ;
V_322 = V_328 + V_198 ;
V_323 = 1 ;
V_327 = V_329 [ 1 ] ;
if ( V_327 >= V_314 ) {
F_14 ( V_32
L_81 ) ;
return - V_104 ;
}
V_25 -> V_327 = V_206 [ V_327 ] ;
V_48 = & V_25 -> V_48 [ V_25 -> V_327 ] ;
V_330 = V_329 [ 3 ] ;
if ( V_330 > V_48 -> V_208 ) {
V_48 -> V_227 ++ ;
return - V_104 ;
}
V_48 -> V_334 = V_330 ;
V_48 -> V_335 = V_329 [ 4 ] ;
break;
case V_336 :
V_326 += V_199 ;
V_328 += V_199 ;
if ( V_329 [ 1 ] >= V_314 )
break;
V_327 = V_206 [ V_329 [ 1 ] ] ;
if ( V_327 >= V_314 )
break;
V_48 = & V_25 -> V_48 [ V_327 ] ;
switch ( V_329 [ 2 ] ) {
case V_337 :
V_48 -> V_213 = 1 ;
F_16 ( & V_48 -> V_215 ) ;
F_12 ( 5 , L_82 , V_327 ) ;
break;
case V_338 :
V_25 -> V_339 |= ( 1 << V_327 ) ;
if ( ( V_25 -> V_339 & 0x0f ) != 0x0f )
break;
F_14 ( V_296 L_83 ) ;
F_15 ( & V_25 -> V_290 -> V_33 ,
V_293 ) ;
F_16 ( & V_25 -> V_290 -> V_35 ) ;
break;
case V_340 :
V_48 -> V_223 = V_329 [ 3 ] ;
V_48 -> V_220 = 1 ;
F_16 ( & V_48 -> V_221 ) ;
F_12 ( 5 , L_84 ,
V_329 [ 3 ] , V_327 ) ;
break;
default:
F_14 ( V_296 L_85 ) ;
}
default:
V_326 ++ ;
break;
}
if ( V_323 )
break;
}
if ( ! V_323 )
return - V_104 ;
}
V_48 = & V_25 -> V_48 [ V_25 -> V_327 ] ;
V_110 = V_48 -> V_228 ;
V_77 = & V_48 -> V_78 . V_79 [ V_110 ] ;
if ( ! V_48 -> V_233 ) {
V_77 -> V_230 = V_231 ;
return - V_104 ;
}
if ( V_77 -> V_230 == V_231 ) {
V_77 -> V_230 = V_341 ;
V_77 -> V_232 = 0 ;
}
V_324 = ( V_342 * ) V_320 -> V_331 + V_322 ;
if ( V_77 -> V_80 == NULL ) {
F_12 ( 1 , L_86 ,
V_77 , V_25 , V_25 -> V_327 , V_110 ) ;
return - V_210 ;
}
V_321 = V_77 -> V_80 + V_77 -> V_232 ;
V_325 = ( V_320 -> V_332 - V_322 ) ;
V_22 = V_48 -> V_334 - V_198 ;
if ( ( V_325 + V_77 -> V_232 ) < V_48 -> V_208 )
memcpy ( V_321 , V_324 , V_325 ) ;
V_77 -> V_232 += V_325 ;
F_12 ( 4 , L_87 , V_77 -> V_232 , V_22 ) ;
if ( V_77 -> V_232 >= V_22 ) {
F_12 ( 2 , L_88 ,
V_25 -> V_327 , V_110 ) ;
V_48 -> V_75 = V_48 -> V_228 ;
V_48 -> V_228 ++ ;
if ( ( V_48 -> V_228 == V_229 ) ||
( V_48 -> V_228 == V_48 -> V_78 . V_343 ) )
V_48 -> V_228 = 0 ;
if ( V_48 -> V_233 )
F_23 ( V_48 , V_48 -> V_335 ) ;
V_48 -> V_86 ++ ;
V_77 -> V_230 = V_231 ;
V_77 -> V_232 = 0 ;
}
return 0 ;
}
static void F_130 ( struct V_1 * V_25 ,
struct V_319 * V_320 )
{
int V_204 ;
F_12 ( 50 , L_89 ) ;
if ( V_25 -> V_327 >= V_314 ) {
V_25 -> V_327 = 0 ;
F_18 ( & V_25 -> V_39 -> V_25 , L_90 ) ;
return;
}
V_204 = F_129 ( V_25 , V_320 ) ;
if ( V_204 != 0 )
F_12 ( 4 , L_91 ) ;
F_12 ( 50 , L_92 ) ;
return;
}
static long F_9 ( struct V_1 * V_25 , unsigned char V_344 ,
T_6 V_345 , T_6 V_346 , void * V_347 ,
T_5 V_348 , int V_349 )
{
int V_350 ;
if ( ! V_349 ) {
V_350 = F_131 ( V_25 -> V_39 , F_132 ( V_25 -> V_39 , 0 ) ,
V_344 ,
V_351 | V_352 |
V_353 ,
V_346 , V_345 , V_347 ,
V_348 , V_354 * 5 ) ;
} else {
V_350 = F_131 ( V_25 -> V_39 , F_133 ( V_25 -> V_39 , 0 ) ,
V_344 , V_351 | V_352 ,
V_346 , V_345 , V_347 ,
V_348 , V_354 * 5 ) ;
}
return V_350 ;
}
static int F_134 ( struct V_1 * V_25 )
{
int V_45 ;
int V_153 ;
unsigned char V_355 [ 64 ] ;
V_153 = F_9 ( V_25 , V_356 , 0 , 0 , V_355 , 2 ,
V_357 ) ;
if ( V_153 < 0 )
F_12 ( 2 , L_93 , V_153 ) ;
V_45 = V_355 [ 0 ] + ( V_355 [ 1 ] << 8 ) ;
F_12 ( 2 , L_94 , V_355 [ 0 ] , V_355 [ 1 ] ) ;
return V_45 ;
}
static int F_135 ( struct V_47 * V_48 )
{
unsigned long V_23 ;
unsigned long V_358 ;
F_12 ( 1 , L_95 ) ;
V_48 -> V_78 . V_343 = V_229 ;
V_358 = V_359 ;
if ( V_358 > V_359 )
V_358 = V_359 ;
for ( V_23 = 0 ; V_23 < V_229 ; V_23 ++ ) {
V_48 -> V_78 . V_79 [ V_23 ] . V_80 = F_136 ( V_358 ) ;
F_12 ( 1 , L_96 ,
& V_48 -> V_78 . V_79 [ V_23 ] , V_48 -> V_110 , V_23 ,
V_48 -> V_78 . V_79 [ V_23 ] . V_80 ) ;
V_48 -> V_78 . V_79 [ V_23 ] . V_22 = V_358 ;
if ( V_48 -> V_78 . V_79 [ V_23 ] . V_80 == NULL ) {
F_14 ( V_296 L_97 ) ;
V_48 -> V_78 . V_343 = V_23 ;
break;
}
}
for ( V_23 = 0 ; V_23 < V_229 ; V_23 ++ ) {
V_48 -> V_78 . V_79 [ V_23 ] . V_230 = 0 ;
V_48 -> V_78 . V_79 [ V_23 ] . V_232 = 0 ;
}
V_48 -> V_228 = 0 ;
V_48 -> V_75 = - 1 ;
return 0 ;
}
static int F_137 ( struct V_47 * V_48 )
{
unsigned long V_23 ;
F_12 ( 1 , L_98 ) ;
for ( V_23 = 0 ; V_23 < V_229 ; V_23 ++ ) {
if ( V_48 -> V_78 . V_79 [ V_23 ] . V_80 ) {
F_12 ( 1 , L_99 ,
V_48 -> V_78 . V_79 [ V_23 ] . V_80 ) ;
F_138 ( V_48 -> V_78 . V_79 [ V_23 ] . V_80 ) ;
}
V_48 -> V_78 . V_79 [ V_23 ] . V_80 = NULL ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_25 )
{
struct V_151 V_360 = V_361 ;
int V_362 ;
int V_225 ;
struct V_319 * V_182 = & V_25 -> V_182 ;
F_12 ( 4 , L_100 , V_25 ) ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_25 = V_25 ;
V_182 -> V_332 = V_363 ;
V_182 -> V_364 = V_363 ;
V_182 -> V_331 = F_72 ( V_182 -> V_364 ,
V_209 ) ;
if ( V_182 -> V_331 == NULL ) {
F_12 ( 1 , L_101 ) ;
return - V_210 ;
}
V_362 = F_134 ( V_25 ) ;
F_14 ( V_296 L_102 ,
( V_362 >> 8 ) & 0xff ,
V_362 & 0xff ) ;
if ( V_362 < V_365 )
F_14 ( V_296 L_103 ) ;
for ( V_225 = 0 ; V_225 < V_314 ; V_225 ++ ) {
struct V_47 * V_48 = & V_25 -> V_48 [ V_225 ] ;
V_48 -> V_233 = 0 ;
V_48 -> V_152 = V_360 ;
if ( V_25 -> V_245 == 0x2257 && V_225 > 1 )
V_48 -> V_152 . V_166 |= ( 1 << 16 ) ;
V_48 -> V_170 . V_171 = V_366 ;
V_48 -> V_16 = V_8 ;
V_48 -> V_17 = V_193 * 2 ;
V_48 -> V_18 = & V_67 [ 0 ] ;
V_48 -> V_152 . V_174 = 1 ;
V_48 -> V_208 = F_69 ( & V_360 ) ;
V_48 -> V_86 = 0 ;
F_135 ( V_48 ) ;
}
F_140 ( V_25 ) ;
F_12 ( 1 , L_104 , V_29 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_25 )
{
T_1 V_23 ;
F_12 ( 1 , L_105 , V_29 , V_25 ) ;
for ( V_23 = 0 ; V_23 < V_314 ; V_23 ++ ) {
if ( V_25 -> V_48 [ V_23 ] . V_233 )
F_82 ( & V_25 -> V_48 [ V_23 ] ) ;
}
F_141 ( V_25 ) ;
for ( V_23 = 0 ; V_23 < V_314 ; V_23 ++ )
F_137 ( & V_25 -> V_48 [ V_23 ] ) ;
F_74 ( V_25 -> V_182 . V_331 ) ;
return 0 ;
}
static void F_142 ( struct V_36 * V_367 )
{
struct V_319 * V_320 ;
struct V_1 * V_25 ;
int V_41 ;
int V_182 ;
V_320 = V_367 -> V_37 ;
F_12 ( 100 , L_106 , V_29 , V_367 ,
V_367 -> V_41 ) ;
if ( V_320 == NULL ) {
F_18 ( & V_367 -> V_25 -> V_25 , L_107 ) ;
return;
}
V_25 = V_320 -> V_25 ;
if ( V_25 == NULL ) {
F_18 ( & V_367 -> V_25 -> V_25 , L_107 ) ;
return;
}
V_41 = V_367 -> V_41 ;
if ( V_41 == - V_368 ) {
F_12 ( 2 , L_108 , V_29 ) ;
V_320 -> V_369 ++ ;
return;
}
if ( V_320 -> V_87 == 0 ) {
F_12 ( 2 , L_109 , V_29 ) ;
return;
}
if ( V_41 == 0 )
F_130 ( V_25 , V_320 ) ;
else {
V_320 -> V_369 ++ ;
F_12 ( 1 , L_110 , V_29 , V_41 ) ;
}
V_182 = F_143 ( V_25 -> V_39 , V_25 -> V_370 ) ;
F_21 ( V_320 -> V_371 , V_25 -> V_39 ,
V_182 ,
V_320 -> V_331 ,
V_320 -> V_332 ,
F_142 , V_320 ) ;
if ( V_320 -> V_87 != 0 ) {
if ( F_13 ( V_320 -> V_371 , V_31 ) ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_111 ) ;
}
} else {
F_12 ( 2 , L_112 , V_29 ) ;
}
return;
}
static int F_140 ( struct V_1 * V_25 )
{
int V_182 ;
int V_183 ;
struct V_319 * V_320 = & V_25 -> V_182 ;
V_182 = F_143 ( V_25 -> V_39 , V_25 -> V_370 ) ;
F_12 ( 2 , L_113 , V_29 , V_25 -> V_370 ) ;
V_320 -> V_87 = 1 ;
V_320 -> V_369 = 0 ;
V_320 -> V_371 = F_144 ( 0 , V_209 ) ;
if ( ! V_320 -> V_371 ) {
F_18 ( & V_25 -> V_39 -> V_25 ,
L_114 ) ;
return - V_210 ;
}
F_21 ( V_320 -> V_371 , V_25 -> V_39 ,
V_182 ,
V_320 -> V_331 ,
V_320 -> V_332 ,
F_142 , V_320 ) ;
V_183 = F_13 ( V_320 -> V_371 , V_209 ) ;
if ( V_183 ) {
F_14 ( V_32 L_115 ) ;
return V_183 ;
}
return 0 ;
}
static int F_80 ( struct V_47 * V_48 )
{
unsigned char * V_78 ;
int V_204 ;
unsigned long V_205 ;
int V_225 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_205 = V_206 [ V_48 -> V_110 ] ;
V_78 = F_72 ( 512 , V_209 ) ;
if ( V_78 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_210 ;
}
V_48 -> V_75 = - 1 ;
V_48 -> V_227 = 0 ;
V_48 -> V_228 = 0 ;
for ( V_225 = 0 ; V_225 < V_229 ; V_225 ++ ) {
V_48 -> V_78 . V_79 [ V_225 ] . V_230 = 0 ;
V_48 -> V_78 . V_79 [ V_225 ] . V_232 = 0 ;
}
* ( T_2 * ) V_78 = V_211 ;
* ( ( T_2 * ) V_78 + 1 ) = ( T_2 ) F_73 ( V_205 ) ;
* ( ( T_2 * ) V_78 + 2 ) = V_372 ;
V_204 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_78 , 512 ) ;
if ( V_204 != 0 )
F_18 ( & V_25 -> V_39 -> V_25 , L_116 ) ;
F_12 ( 2 , L_117 , V_48 -> V_110 , V_204 ) ;
F_74 ( V_78 ) ;
return 0 ;
}
static int F_82 ( struct V_47 * V_48 )
{
unsigned char * V_78 ;
int V_204 ;
unsigned long V_205 ;
struct V_1 * V_25 = F_1 ( V_48 -> V_5 . V_3 ) ;
V_205 = V_206 [ V_48 -> V_110 ] ;
V_78 = F_72 ( 512 , V_209 ) ;
if ( V_78 == NULL ) {
F_18 ( & V_25 -> V_39 -> V_25 , L_34 ) ;
return - V_210 ;
}
* ( T_2 * ) V_78 = V_211 ;
* ( ( T_2 * ) V_78 + 1 ) = ( T_2 ) F_73 ( V_205 ) ;
* ( ( T_2 * ) V_78 + 2 ) = V_373 ;
V_204 = F_67 ( V_25 -> V_39 , ( unsigned char * ) V_78 , 512 ) ;
if ( V_204 != 0 )
F_18 ( & V_25 -> V_39 -> V_25 , L_118 ) ;
F_74 ( V_78 ) ;
V_48 -> V_233 = 0 ;
F_12 ( 4 , L_119 , V_29 , V_48 -> V_110 , V_204 ) ;
return V_204 ;
}
static void F_141 ( struct V_1 * V_25 )
{
struct V_319 * V_182 = & V_25 -> V_182 ;
V_182 -> V_87 = 0 ;
if ( V_182 -> V_371 ) {
F_110 ( V_182 -> V_371 ) ;
F_111 ( V_182 -> V_371 ) ;
V_182 -> V_371 = NULL ;
}
F_12 ( 4 , L_69 , V_29 ) ;
return;
}
static void F_103 ( struct V_1 * V_25 , int V_374 )
{
if ( V_374 )
F_8 ( V_25 ) ;
V_25 -> V_290 -> V_43 = V_25 -> V_290 -> V_45 -> V_22 ;
F_15 ( & V_25 -> V_290 -> V_33 , V_295 ) ;
memcpy ( V_25 -> V_290 -> V_44 ,
V_25 -> V_290 -> V_45 -> V_28 , F_20 ) ;
V_25 -> V_290 -> V_42 = F_20 ;
F_21 ( V_25 -> V_290 -> V_30 , V_25 -> V_39 ,
F_22 ( V_25 -> V_39 , 2 ) ,
V_25 -> V_290 -> V_44 ,
F_20 , F_17 ,
V_25 -> V_290 ) ;
F_145 ( & V_25 -> V_305 , V_375 + V_354 ) ;
}
static int F_146 ( struct V_376 * V_313 ,
const struct V_377 * V_117 )
{
struct V_1 * V_25 = NULL ;
struct V_378 * V_379 ;
struct V_380 * V_381 ;
int V_23 ;
int V_183 = - V_210 ;
T_2 * V_326 ;
int V_43 ;
F_12 ( 2 , L_1 , V_29 ) ;
V_25 = F_72 ( sizeof( struct V_1 ) , V_209 ) ;
if ( V_25 == NULL ) {
F_19 ( & V_313 -> V_25 , L_120 ) ;
return - V_210 ;
}
F_15 ( & V_25 -> V_310 , 0 ) ;
V_25 -> V_245 = V_117 -> V_382 ;
V_25 -> V_290 = F_72 ( sizeof( struct V_27 ) , V_209 ) ;
if ( ! V_25 -> V_290 )
goto V_383;
F_147 ( & V_25 -> V_301 ) ;
F_147 ( & V_25 -> V_289 ) ;
V_25 -> V_39 = F_148 ( F_149 ( V_313 ) ) ;
if ( V_25 -> V_39 == NULL ) {
F_18 ( & V_313 -> V_25 , L_121 ) ;
V_183 = - V_292 ;
goto V_384;
}
F_12 ( 1 , L_122 , V_25 ,
V_25 -> V_39 , V_313 ) ;
V_25 -> V_313 = V_313 ;
V_379 = V_313 -> V_385 ;
F_12 ( 1 , L_123 , V_379 -> V_386 . V_387 ) ;
for ( V_23 = 0 ; V_23 < V_379 -> V_386 . V_387 ; ++ V_23 ) {
V_381 = & V_379 -> V_381 [ V_23 ] . V_386 ;
if ( ! V_25 -> V_370 && F_150 ( V_381 ) ) {
V_25 -> V_370 = V_381 -> V_388 ;
}
}
if ( ! V_25 -> V_370 ) {
F_18 ( & V_313 -> V_25 , L_124 ) ;
goto V_389;
}
F_151 ( & V_25 -> V_305 ) ;
V_25 -> V_305 . V_390 = F_11 ;
V_25 -> V_305 . V_28 = ( unsigned long ) V_25 -> V_290 ;
F_152 ( & V_25 -> V_290 -> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_314 ; V_23 ++ ) {
struct V_47 * V_48 = & V_25 -> V_48 [ V_23 ] ;
V_25 -> V_48 [ V_23 ] . V_110 = V_23 ;
F_152 ( & V_48 -> V_215 ) ;
F_152 ( & V_48 -> V_221 ) ;
}
V_25 -> V_290 -> V_30 = F_144 ( 0 , V_209 ) ;
if ( ! V_25 -> V_290 -> V_30 ) {
F_18 ( & V_313 -> V_25 , L_101 ) ;
goto V_391;
}
V_25 -> V_290 -> V_44 = F_72 ( F_20 , V_209 ) ;
if ( ! V_25 -> V_290 -> V_44 ) {
F_18 ( & V_313 -> V_25 , L_101 ) ;
goto V_392;
}
if ( F_153 ( & V_25 -> V_290 -> V_45 ,
V_393 , & V_25 -> V_39 -> V_25 ) ) {
F_14 ( V_32 L_125 ) ;
goto V_394;
}
V_43 = V_25 -> V_290 -> V_45 -> V_22 ;
V_326 = ( T_2 * ) & V_25 -> V_290 -> V_45 -> V_28 [ V_43 - 8 ] ;
if ( * V_326 != V_395 ) {
F_14 ( V_296 L_126 ) ;
V_183 = - V_292 ;
goto V_396;
} else {
T_2 * V_397 ;
V_397 = ( T_2 * ) & V_25 -> V_290 -> V_45 -> V_28 [ V_43 - 4 ] ;
F_14 ( V_296 L_127 , * V_397 ) ;
V_25 -> V_242 = * V_397 ;
if ( * V_397 < V_398 )
F_14 ( V_296 L_128 ) ;
if ( V_25 -> V_245 == 0x2257 && * V_397 < V_256 )
F_14 ( V_318 L_129
L_130 , V_256 ) ;
}
F_154 ( V_25 -> V_39 ) ;
V_183 = F_139 ( V_25 ) ;
if ( V_183 )
goto V_399;
F_155 ( & V_25 -> V_57 ) ;
F_103 ( V_25 , 0 ) ;
V_183 = F_122 ( V_25 ) ;
if ( V_183 )
goto V_399;
F_71 ( & V_313 -> V_25 , L_131 ) ;
return 0 ;
V_399:
F_108 ( V_25 ) ;
V_396:
F_112 ( V_25 -> V_290 -> V_45 ) ;
V_394:
F_74 ( V_25 -> V_290 -> V_44 ) ;
V_392:
F_111 ( V_25 -> V_290 -> V_30 ) ;
V_391:
F_109 ( & V_25 -> V_305 ) ;
V_389:
F_114 ( V_25 -> V_39 ) ;
V_384:
F_74 ( V_25 -> V_290 ) ;
F_113 ( & V_25 -> V_289 ) ;
F_113 ( & V_25 -> V_301 ) ;
V_383:
F_74 ( V_25 ) ;
F_14 ( V_318 L_132 , V_183 ) ;
return V_183 ;
}
static void F_156 ( struct V_376 * V_313 )
{
struct V_1 * V_25 = F_1 ( F_157 ( V_313 ) ) ;
int V_23 ;
int V_400 = F_102 ( & V_25 -> V_310 ) ;
F_55 ( & V_25 -> V_301 ) ;
F_158 ( & V_25 -> V_3 ) ;
F_58 ( & V_25 -> V_301 ) ;
F_127 ( & V_25 -> V_310 ) ;
for ( V_23 = 0 ; V_23 < V_400 ; V_23 ++ )
F_159 ( & V_25 -> V_48 [ V_23 ] . V_5 ) ;
F_15 ( & V_25 -> V_290 -> V_33 , V_291 ) ;
F_16 ( & V_25 -> V_290 -> V_35 ) ;
for ( V_23 = 0 ; V_23 < V_314 ; V_23 ++ ) {
V_25 -> V_48 [ V_23 ] . V_213 = 1 ;
F_16 ( & V_25 -> V_48 [ V_23 ] . V_215 ) ;
V_25 -> V_48 [ V_23 ] . V_220 = 1 ;
F_16 ( & V_25 -> V_48 [ V_23 ] . V_221 ) ;
}
if ( F_121 ( & V_25 -> V_310 ) )
F_107 ( V_25 ) ;
F_71 ( & V_313 -> V_25 , L_1 , V_29 ) ;
}
static int T_7 F_160 ( void )
{
int V_401 ;
V_401 = F_161 ( & V_402 ) ;
if ( V_401 )
F_162 ( V_403
L_133 , V_401 ) ;
F_12 ( 2 , L_1 , V_29 ) ;
return V_401 ;
}
static void T_8 F_163 ( void )
{
F_164 ( & V_402 ) ;
}
