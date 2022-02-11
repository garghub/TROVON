static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 += V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_4 = 0 ;
switch ( V_2 -> V_3 ) {
case 0 :
return - 1 ;
case 1 :
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
F_2 ( V_8 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_2 ( V_9 , L_2 ) ;
break;
default:
V_2 -> V_6 = true ;
if ( V_10 ) {
V_2 -> V_7 = true ;
V_2 -> V_5 = 1 ;
} else
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 , const unsigned int V_11 ,
const int V_12 )
{
int * V_13 , V_14 = 0 ;
F_4 ( & V_2 -> V_15 ) ;
V_13 = V_2 -> V_16 -> V_17 ( V_2 , V_12 ) ;
* V_13 += V_11 ;
if ( * V_13 > 65000 ) {
* V_13 = 65000 ;
F_5 ( V_18 L_3 ) ;
}
V_2 -> V_19 -- ;
if ( V_2 -> V_19 == 0 && ( V_12 & V_20 ) != V_21 )
V_14 = F_1 ( V_2 ) ;
else if ( V_2 -> V_19 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_22 ) ;
if ( V_14 )
F_8 ( V_2 ) ;
}
static void
F_9 ( struct V_1 * V_2 , const int V_13 )
{
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 = V_13 ;
F_6 ( & V_2 -> V_15 ) ;
}
static int *
F_10 ( struct V_1 * V_2 , const int V_12 )
{
switch ( V_12 ) {
case V_23 :
return & V_2 -> V_4 ;
case V_24 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_11 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_12 ( V_26 -> V_29 ) ;
return F_13 ( V_28 -> V_30 ) ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned int * V_32 , unsigned int * V_3 )
{
int V_14 = 0 ;
unsigned int V_33 ;
F_4 ( & V_2 -> V_15 ) ;
while ( 1 ) {
if ( V_2 -> V_3 <= 0 ) {
F_6 ( & V_2 -> V_15 ) ;
F_15 ( V_2 ) ;
V_14 = F_16 ( V_2 -> V_22 ,
F_17 ( V_2 , & V_2 -> V_3 ) ) ;
F_18 ( V_2 ) ;
if ( V_14 )
return V_14 ;
F_4 ( & V_2 -> V_15 ) ;
} else {
if ( V_2 -> V_34 == V_35 ) {
F_6 ( & V_2 -> V_15 ) ;
return - V_36 ;
}
V_33 = V_2 -> V_3 ;
if ( V_33 == 1 ) {
* V_32 = V_37 ;
* V_3 = 0 ;
break;
}
V_33 -- ;
* V_32 = F_19 (unsigned int, size,
scredits * SMB2_MAX_BUFFER_SIZE) ;
* V_3 = F_20 ( * V_32 , V_37 ) ;
V_2 -> V_3 -= * V_3 ;
V_2 -> V_19 ++ ;
break;
}
}
F_6 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static T_1
F_21 ( struct V_1 * V_2 )
{
T_1 V_26 ;
F_4 ( & V_38 ) ;
V_26 = V_2 -> V_39 ++ ;
F_6 ( & V_38 ) ;
return V_26 ;
}
static struct V_25 *
F_22 ( struct V_1 * V_2 , char * V_40 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 = F_12 ( V_40 ) ;
T_1 V_41 = F_23 ( V_28 -> V_42 ) ;
if ( V_28 -> V_43 == V_44 ) {
F_2 ( V_8 , L_4 ) ;
return NULL ;
}
F_4 ( & V_38 ) ;
F_24 (mid, &server->pending_mid_q, qhead) {
if ( ( V_26 -> V_26 == V_41 ) &&
( V_26 -> V_45 == V_46 ) &&
( V_26 -> V_47 == V_28 -> V_48 ) ) {
F_6 ( & V_38 ) ;
return V_26 ;
}
}
F_6 ( & V_38 ) ;
return NULL ;
}
static void
F_25 ( void * V_40 )
{
#ifdef F_26
struct V_27 * V_28 = F_12 ( V_40 ) ;
F_2 ( V_8 , L_5 ,
V_28 -> V_48 , V_28 -> V_49 , V_28 -> V_50 , V_28 -> V_42 ,
V_28 -> V_51 ) ;
F_2 ( V_8 , L_6 , V_40 , F_27 ( V_40 ) ) ;
#endif
}
static bool
F_28 ( struct V_1 * V_2 )
{
return V_2 -> V_52 == 0 ;
}
static int
F_29 ( const unsigned int V_53 , struct V_54 * V_55 )
{
int V_14 ;
V_55 -> V_2 -> V_39 = 0 ;
V_14 = F_30 ( V_53 , V_55 ) ;
if ( V_14 == - V_56 )
V_14 = - V_57 ;
return V_14 ;
}
static unsigned int
F_31 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_55 -> V_2 ;
unsigned int V_62 ;
V_62 = V_61 -> V_62 ? V_61 -> V_62 : V_63 ;
V_62 = F_19 (unsigned int, wsize, server->max_write) ;
if ( ! ( V_2 -> V_64 & V_65 ) )
V_62 = F_19 (unsigned int, wsize, SMB2_MAX_BUFFER_SIZE) ;
return V_62 ;
}
static unsigned int
F_32 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_59 -> V_55 -> V_2 ;
unsigned int V_66 ;
V_66 = V_61 -> V_66 ? V_61 -> V_66 : V_63 ;
V_66 = F_19 (unsigned int, rsize, server->max_read) ;
if ( ! ( V_2 -> V_64 & V_65 ) )
V_66 = F_19 (unsigned int, rsize, SMB2_MAX_BUFFER_SIZE) ;
return V_66 ;
}
static int
F_33 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
unsigned int V_67 = 0 ;
struct V_68 * V_69 ;
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_71 , true ,
false ,
NULL , 0 ,
( char * * ) & V_69 , & V_67 ) ;
if ( V_14 != 0 )
F_2 ( V_8 , L_7 , V_14 ) ;
else if ( V_67 < sizeof( struct V_68 ) ) {
F_2 ( V_8 , L_8 ) ;
V_14 = - V_72 ;
} else {
F_2 ( V_9 , L_9 ,
F_35 ( V_69 -> V_73 ) ) ;
F_2 ( V_9 , L_10 ,
F_23 ( V_69 -> V_74 ) ) ;
}
F_36 ( V_69 ) ;
return V_14 ;
}
static void
F_37 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
T_2 V_75 = 0 ;
T_3 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return;
#ifdef F_39
F_33 ( V_53 , V_59 ) ;
#endif
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_90 ) ;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_91 ) ;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_92 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return;
}
static void
F_42 ( const unsigned int V_53 , struct V_58 * V_59 )
{
int V_14 ;
T_2 V_75 = 0 ;
T_3 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_90 ) ;
F_40 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_91 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return;
}
static int
F_43 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_93 * V_94 , const char * V_95 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_96 = F_44 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
if ( V_14 ) {
F_36 ( V_96 ) ;
return V_14 ;
}
V_14 = F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
F_36 ( V_96 ) ;
return V_14 ;
}
static int
F_45 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_93 * V_94 , const char * V_95 ,
T_5 * V_98 , T_6 * V_99 )
{
* V_98 = F_23 ( V_99 -> V_100 ) ;
return 0 ;
}
static int
F_46 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 , T_6 * V_99 )
{
int V_14 ;
struct V_101 * V_102 ;
V_102 = F_47 ( sizeof( struct V_101 ) + V_103 * 2 ,
V_104 ) ;
if ( V_102 == NULL )
return - V_97 ;
V_14 = F_48 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ,
V_102 ) ;
if ( ! V_14 )
F_49 ( V_99 , V_102 ) ;
F_36 ( V_102 ) ;
return V_14 ;
}
static T_7
F_50 ( char * V_105 , T_8 V_106 ,
struct V_107 * V_108 , T_8 V_109 ,
const unsigned char * V_110 )
{
int V_14 = 0 ;
unsigned int V_111 = V_110 ? strlen ( V_110 ) : 0 ;
char * V_112 , * V_113 ;
T_8 V_114 , V_115 , V_116 ;
while ( V_109 > 0 ) {
V_112 = & V_108 -> V_117 [ 0 ] ;
V_114 = ( T_8 ) V_108 -> V_118 ;
V_113 = & V_108 -> V_117 [ V_108 -> V_118 + 1 ] ;
V_115 = ( T_8 ) F_13 ( V_108 -> V_119 ) ;
if ( V_114 == 0 ) {
break;
}
if ( V_109 < 8 + V_114 + 1 + V_115 ) {
F_2 ( V_9 , L_11 ) ;
V_14 = - V_120 ;
goto V_121;
}
if ( V_110 ) {
if ( V_111 == V_114 &&
memcmp ( V_110 , V_112 , V_114 ) == 0 ) {
V_14 = V_115 ;
if ( V_106 == 0 )
goto V_121;
if ( V_106 < V_115 ) {
V_14 = - V_122 ;
goto V_121;
}
memcpy ( V_105 , V_113 , V_115 ) ;
goto V_121;
}
} else {
V_116 = 5 + 1 + V_114 ;
V_14 += V_116 ;
if ( V_106 >= V_116 ) {
V_106 -= V_116 ;
memcpy ( V_105 , L_12 , 5 ) ;
V_105 += 5 ;
memcpy ( V_105 , V_108 -> V_117 , V_114 ) ;
V_105 += V_114 ;
* V_105 = 0 ;
++ V_105 ;
} else if ( V_106 == 0 ) {
} else {
V_14 = - V_122 ;
break;
}
}
if ( ! V_108 -> V_123 )
break;
if ( V_109 < F_35 ( V_108 -> V_123 ) ) {
V_14 = - V_122 ;
break;
}
V_109 -= F_35 ( V_108 -> V_123 ) ;
V_108 = ( void * ) ( ( char * ) V_108 +
F_35 ( V_108 -> V_123 ) ) ;
}
if ( V_110 )
V_14 = - V_124 ;
V_121:
return ( T_7 ) V_14 ;
}
static T_7
F_51 ( const unsigned int V_53 , struct V_58 * V_59 ,
const unsigned char * V_125 , const unsigned char * V_110 ,
char * V_117 , T_8 V_126 ,
struct V_93 * V_94 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_107 * V_102 ;
int V_127 = V_128 ;
V_96 = F_44 ( V_125 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_129 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( V_14 ) {
F_2 ( V_9 , L_13 , V_14 ) ;
return V_14 ;
}
while ( 1 ) {
V_102 = F_47 ( V_127 , V_104 ) ;
if ( V_102 == NULL ) {
F_41 ( V_53 , V_59 , V_81 . V_88 ,
V_81 . V_89 ) ;
return - V_97 ;
}
V_14 = F_52 ( V_53 , V_59 , V_81 . V_88 ,
V_81 . V_89 ,
V_127 , V_102 ) ;
if ( V_14 != - V_130 )
break;
F_36 ( V_102 ) ;
V_127 <<= 1 ;
if ( V_127 > V_131 ) {
F_2 ( V_8 , L_14 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 ,
V_81 . V_89 ) ;
return - V_97 ;
}
}
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
if ( ! V_14 )
V_14 = F_50 ( V_117 , V_126 , V_102 ,
V_131 , V_110 ) ;
F_36 ( V_102 ) ;
return V_14 ;
}
static int
F_53 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_125 , const char * V_110 , const void * V_132 ,
const T_9 V_133 , const struct V_134 * V_135 ,
struct V_93 * V_94 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_107 * V_136 ;
int V_111 = strlen ( V_110 ) ;
int V_137 ;
if ( V_111 > 255 )
return - V_72 ;
V_96 = F_44 ( V_125 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_138 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( V_14 ) {
F_2 ( V_9 , L_13 , V_14 ) ;
return V_14 ;
}
V_137 = sizeof( V_136 ) + V_111 + V_133 + 1 ;
V_136 = F_47 ( V_137 , V_104 ) ;
if ( V_136 == NULL ) {
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return - V_97 ;
}
V_136 -> V_118 = V_111 ;
V_136 -> V_119 = F_54 ( V_133 ) ;
memcpy ( V_136 -> V_117 , V_110 , V_111 + 1 ) ;
memcpy ( V_136 -> V_117 + V_111 + 1 , V_132 , V_133 ) ;
V_14 = F_55 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 , V_136 ,
V_137 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return V_14 ;
}
static bool
F_56 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_57 ( struct V_58 * V_59 )
{
#ifdef F_58
int V_139 ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ ) {
F_59 ( & V_59 -> V_141 . V_142 . V_143 [ V_139 ] , 0 ) ;
F_59 ( & V_59 -> V_141 . V_142 . V_144 [ V_139 ] , 0 ) ;
}
#endif
}
static void
F_60 ( struct V_145 * V_146 , struct V_58 * V_59 )
{
F_61 ( V_146 , L_15 ) ;
if ( V_59 -> V_64 & V_147 )
F_61 ( V_146 , L_16 ) ;
if ( V_59 -> V_64 & V_148 )
F_61 ( V_146 , L_17 ) ;
if ( V_59 -> V_64 & V_149 )
F_61 ( V_146 , L_18 ) ;
if ( V_59 -> V_64 & V_150 )
F_61 ( V_146 , L_19 ) ;
if ( V_59 -> V_64 & V_151 )
F_61 ( V_146 , L_20 ) ;
if ( V_59 -> V_64 == 0 )
F_61 ( V_146 , L_21 ) ;
if ( V_59 -> V_152 & V_153 )
F_61 ( V_146 , L_22 ) ;
if ( V_59 -> V_152 & V_154 )
F_61 ( V_146 , L_23 ) ;
if ( V_59 -> V_152 & V_155 )
F_61 ( V_146 , L_24 ) ;
if ( V_59 -> V_152 & V_156 )
F_61 ( V_146 , L_25 ) ;
F_62 ( V_146 , L_26 , V_59 -> V_157 ) ;
if ( V_59 -> V_158 )
F_62 ( V_146 , L_27 ,
V_59 -> V_158 ) ;
}
static void
F_63 ( struct V_145 * V_146 , struct V_58 * V_59 )
{
#ifdef F_58
T_10 * V_159 = V_59 -> V_141 . V_142 . V_143 ;
T_10 * V_160 = V_59 -> V_141 . V_142 . V_144 ;
F_62 ( V_146 , L_28 ,
F_64 ( & V_159 [ V_161 ] ) ,
F_64 ( & V_160 [ V_161 ] ) ) ;
F_62 ( V_146 , L_29 ,
F_64 ( & V_159 [ V_162 ] ) ,
F_64 ( & V_160 [ V_162 ] ) ) ;
F_62 ( V_146 , L_30 ,
F_64 ( & V_159 [ V_163 ] ) ,
F_64 ( & V_160 [ V_163 ] ) ) ;
F_62 ( V_146 , L_31 ,
F_64 ( & V_159 [ V_164 ] ) ,
F_64 ( & V_160 [ V_164 ] ) ) ;
F_62 ( V_146 , L_32 ,
F_64 ( & V_159 [ V_165 ] ) ,
F_64 ( & V_160 [ V_165 ] ) ) ;
F_62 ( V_146 , L_33 ,
F_64 ( & V_159 [ V_166 ] ) ,
F_64 ( & V_160 [ V_166 ] ) ) ;
F_62 ( V_146 , L_34 ,
F_64 ( & V_159 [ V_167 ] ) ,
F_64 ( & V_160 [ V_167 ] ) ) ;
F_62 ( V_146 , L_35 ,
F_64 ( & V_159 [ V_168 ] ) ,
F_64 ( & V_160 [ V_168 ] ) ) ;
F_62 ( V_146 , L_36 ,
F_64 ( & V_159 [ V_169 ] ) ,
F_64 ( & V_160 [ V_169 ] ) ) ;
F_62 ( V_146 , L_37 ,
F_64 ( & V_159 [ V_170 ] ) ,
F_64 ( & V_160 [ V_170 ] ) ) ;
F_62 ( V_146 , L_38 ,
F_64 ( & V_159 [ V_171 ] ) ,
F_64 ( & V_160 [ V_171 ] ) ) ;
F_62 ( V_146 , L_39 ,
F_64 ( & V_159 [ V_172 ] ) ,
F_64 ( & V_160 [ V_172 ] ) ) ;
F_62 ( V_146 , L_40 ,
F_64 ( & V_159 [ V_173 ] ) ,
F_64 ( & V_160 [ V_173 ] ) ) ;
F_62 ( V_146 , L_41 ,
F_64 ( & V_159 [ V_174 ] ) ,
F_64 ( & V_160 [ V_174 ] ) ) ;
F_62 ( V_146 , L_42 ,
F_64 ( & V_159 [ V_175 ] ) ,
F_64 ( & V_160 [ V_175 ] ) ) ;
F_62 ( V_146 , L_43 ,
F_64 ( & V_159 [ V_176 ] ) ,
F_64 ( & V_160 [ V_176 ] ) ) ;
F_62 ( V_146 , L_44 ,
F_64 ( & V_159 [ V_177 ] ) ,
F_64 ( & V_160 [ V_177 ] ) ) ;
F_62 ( V_146 , L_45 ,
F_64 ( & V_159 [ V_178 ] ) ,
F_64 ( & V_160 [ V_178 ] ) ) ;
F_62 ( V_146 , L_46 ,
F_64 ( & V_159 [ V_179 ] ) ,
F_64 ( & V_160 [ V_179 ] ) ) ;
#endif
}
static void
F_65 ( struct V_180 * V_181 , struct V_80 * V_81 , T_11 V_76 )
{
struct V_182 * V_183 = F_66 ( F_67 ( V_181 -> V_184 ) ) ;
struct V_1 * V_2 = F_68 ( V_181 -> V_185 ) -> V_55 -> V_2 ;
V_181 -> V_81 . V_88 = V_81 -> V_88 ;
V_181 -> V_81 . V_89 = V_81 -> V_89 ;
V_2 -> V_16 -> V_186 ( V_183 , V_76 , V_81 -> V_187 ,
& V_81 -> V_188 ) ;
V_183 -> V_189 = F_69 ( V_183 ) ;
memcpy ( V_181 -> V_81 . V_190 , V_81 -> V_190 , 16 ) ;
}
static void
F_70 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
F_41 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static int
F_71 ( const unsigned int V_53 , struct V_58 * V_59 ,
T_5 V_88 , T_5 V_89 ,
struct V_191 * V_192 )
{
int V_14 ;
unsigned int V_67 ;
struct V_193 * V_194 ;
V_14 = F_34 ( V_53 , V_59 , V_88 , V_89 ,
V_195 , true ,
false ,
NULL , 0 ,
( char * * ) & V_194 , & V_67 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_47 , V_14 ) ;
goto V_196;
}
if ( V_67 < sizeof( struct V_193 ) ) {
F_2 ( V_8 , L_48 ) ;
V_14 = - V_72 ;
goto V_196;
}
memcpy ( V_192 -> V_197 , V_194 -> V_198 , V_199 ) ;
V_196:
F_36 ( V_194 ) ;
return V_14 ;
}
static T_7
F_72 ( const unsigned int V_53 ,
struct V_180 * V_200 ,
struct V_180 * V_201 , T_5 V_202 ,
T_5 V_137 , T_5 V_203 )
{
int V_14 ;
unsigned int V_67 ;
struct V_191 * V_192 ;
struct V_204 * V_205 = NULL ;
struct V_58 * V_59 ;
int V_206 = 0 ;
bool V_207 = false ;
T_7 V_208 , V_209 = 0 ;
V_192 = F_73 ( sizeof( struct V_191 ) , V_104 ) ;
if ( V_192 == NULL )
return - V_97 ;
F_2 ( V_9 , L_49 ) ;
V_14 = F_71 ( V_53 , F_68 ( V_200 -> V_185 ) ,
V_200 -> V_81 . V_88 ,
V_200 -> V_81 . V_89 , V_192 ) ;
if ( V_14 )
goto V_210;
V_192 -> V_211 = F_74 ( 1 ) ;
V_192 -> V_212 = 0 ;
V_192 -> V_213 = 0 ;
V_59 = F_68 ( V_201 -> V_185 ) ;
while ( V_137 > 0 ) {
V_192 -> V_214 = F_75 ( V_202 ) ;
V_192 -> V_215 = F_75 ( V_203 ) ;
V_192 -> V_216 =
F_74 ( F_19 ( V_217 , V_137 , V_59 -> V_218 ) ) ;
V_14 = F_34 ( V_53 , V_59 , V_201 -> V_81 . V_88 ,
V_201 -> V_81 . V_89 , V_219 ,
true , false ,
( char * ) V_192 ,
sizeof( struct V_191 ) , ( char * * ) & V_205 ,
& V_67 ) ;
if ( V_14 == 0 ) {
if ( V_67 !=
sizeof( struct V_204 ) ) {
F_2 ( V_8 , L_50 ) ;
V_14 = - V_120 ;
goto V_210;
}
if ( V_205 -> V_220 == 0 ) {
F_2 ( V_9 , L_51 ) ;
V_14 = - V_120 ;
goto V_210;
}
if ( F_35 ( V_205 -> V_220 ) >
F_35 ( V_192 -> V_216 ) ) {
F_2 ( V_8 , L_52 ) ;
V_14 = - V_120 ;
goto V_210;
}
if ( F_35 ( V_205 -> V_221 ) != 1 ) {
F_2 ( V_8 , L_53 ) ;
V_14 = - V_120 ;
goto V_210;
}
V_206 ++ ;
V_208 = F_35 ( V_205 -> V_220 ) ;
V_202 += V_208 ;
V_203 += V_208 ;
V_137 -= V_208 ;
V_209 += V_208 ;
F_2 ( V_9 , L_54 ,
F_35 ( V_205 -> V_221 ) ,
F_35 ( V_205 -> V_222 ) ,
V_208 ) ;
} else if ( V_14 == - V_72 ) {
if ( V_67 != sizeof( struct V_204 ) )
goto V_210;
F_2 ( V_9 , L_55 ,
F_35 ( V_205 -> V_221 ) ,
F_35 ( V_205 -> V_222 ) ,
F_35 ( V_205 -> V_220 ) ) ;
if ( ( V_206 != 0 ) || V_207 )
goto V_210;
if ( F_35 ( V_205 -> V_222 ) <
V_59 -> V_218 )
V_59 -> V_218 =
F_35 ( V_205 -> V_222 ) ;
else
goto V_210;
V_207 = true ;
} else
goto V_210;
}
V_210:
F_36 ( V_192 ) ;
F_36 ( V_205 ) ;
if ( V_14 )
return V_14 ;
else
return V_209 ;
}
static int
F_76 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
return F_77 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static unsigned int
F_78 ( char * V_40 )
{
struct V_223 * V_224 = (struct V_223 * ) V_40 ;
return V_224 -> V_225 ;
}
static unsigned int
F_79 ( char * V_40 )
{
struct V_223 * V_224 = (struct V_223 * ) V_40 ;
return F_35 ( V_224 -> V_226 ) ;
}
static int
F_80 ( const unsigned int V_53 , struct V_80 * V_227 ,
struct V_228 * V_229 , unsigned int * V_230 ,
char * * V_40 , int * V_231 )
{
V_229 -> V_88 = V_227 -> V_88 ;
V_229 -> V_89 = V_227 -> V_89 ;
return F_81 ( V_53 , V_229 , V_230 , V_40 , V_231 ) ;
}
static int
F_82 ( const unsigned int V_53 , struct V_80 * V_227 ,
struct V_228 * V_229 , unsigned int * V_232 ,
struct V_233 * V_234 , unsigned long V_235 )
{
V_229 -> V_88 = V_227 -> V_88 ;
V_229 -> V_89 = V_227 -> V_89 ;
return F_83 ( V_53 , V_229 , V_232 , V_234 , V_235 ) ;
}
static bool F_84 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_180 * V_181 , struct V_236 * V_236 , T_4 V_237 )
{
struct V_182 * V_238 ;
int V_14 ;
V_238 = F_66 ( V_236 ) ;
if ( ( V_238 -> V_239 & V_240 ) && V_237 )
return true ;
if ( ! ( V_238 -> V_239 & V_240 ) && ! V_237 )
return true ;
if ( V_59 -> V_241 )
return false ;
V_14 = F_34 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 , V_242 ,
true , false ,
& V_237 , 1 , NULL , NULL ) ;
if ( V_14 ) {
V_59 -> V_241 = true ;
F_2 ( V_9 , L_56 , V_14 ) ;
return false ;
}
if ( V_237 )
V_238 -> V_239 |= V_240 ;
else
V_238 -> V_239 &= ( ~ V_240 ) ;
return true ;
}
static int
F_85 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_180 * V_181 , T_1 V_31 , bool V_243 )
{
T_12 V_244 = F_75 ( V_31 ) ;
struct V_236 * V_236 ;
V_236 = F_67 ( V_181 -> V_184 ) ;
if ( ! V_243 && ( V_31 > V_236 -> V_245 + 8192 ) ) {
T_4 V_246 = 1 ;
F_84 ( V_53 , V_59 , V_181 , V_236 , V_246 ) ;
}
return F_86 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 , V_181 -> V_247 , & V_244 , false ) ;
}
static int
F_87 ( const unsigned int V_53 ,
struct V_180 * V_200 ,
struct V_180 * V_201 , T_5 V_202 ,
T_5 V_137 , T_5 V_203 )
{
int V_14 ;
unsigned int V_67 ;
struct V_248 V_249 ;
struct V_58 * V_59 = F_68 ( V_201 -> V_185 ) ;
if ( ( F_35 ( V_59 -> V_250 . V_251 ) &
V_252 ) == 0 )
return - V_253 ;
V_249 . V_254 = V_200 -> V_81 . V_89 ;
V_249 . V_255 = V_200 -> V_81 . V_88 ;
V_249 . V_256 = F_75 ( V_202 ) ;
V_249 . V_257 = F_75 ( V_203 ) ;
V_249 . V_258 = F_75 ( V_137 ) ;
F_2 ( V_9 , L_57 ,
V_202 , V_203 , V_137 ) ;
V_14 = F_85 ( V_53 , V_59 , V_201 , V_203 + V_137 , false ) ;
if ( V_14 )
goto V_259;
V_14 = F_34 ( V_53 , V_59 , V_201 -> V_81 . V_88 ,
V_201 -> V_81 . V_89 ,
V_260 ,
true , false ,
( char * ) & V_249 ,
sizeof( struct V_248 ) ,
NULL ,
& V_67 ) ;
if ( V_67 > 0 )
F_2 ( V_9 , L_58 ) ;
V_259:
return V_14 ;
}
static int
F_88 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_180 * V_181 )
{
return F_89 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 ) ;
}
static int
F_90 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_180 * V_181 )
{
struct V_261 V_262 ;
unsigned int V_67 ;
V_262 . V_263 = F_54 ( V_264 ) ;
V_262 . V_50 = 0 ;
V_262 . V_212 = 0 ;
return F_34 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 ,
V_265 ,
true , false ,
( char * ) & V_262 ,
sizeof( struct V_261 ) ,
NULL ,
& V_67 ) ;
}
static int
F_91 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_180 * V_181 , void T_13 * V_266 )
{
char * V_205 = NULL ;
unsigned int V_67 = 0 ;
int V_14 ;
struct V_267 V_268 ;
V_14 = F_34 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 ,
V_269 ,
true , false ,
NULL , 0 ,
( char * * ) & V_205 ,
& V_67 ) ;
F_2 ( V_9 , L_59 ,
V_14 , V_67 ) ;
if ( V_14 )
return V_14 ;
if ( V_67 && ( V_266 != NULL ) && ( V_205 != NULL ) ) {
if ( F_92 ( & V_268 , V_266 ,
sizeof( struct V_267 ) ) ) {
V_14 = - V_270 ;
F_36 ( V_205 ) ;
return V_14 ;
}
if ( V_268 . V_271 < sizeof( struct V_267 ) ) {
V_14 = - V_122 ;
F_36 ( V_205 ) ;
return V_14 ;
}
if ( V_67 > V_268 . V_271 )
V_67 = V_268 . V_271 ;
if ( F_93 ( V_266 , V_205 , V_67 ) )
V_14 = - V_270 ;
}
F_36 ( V_205 ) ;
return V_14 ;
}
static int
F_94 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_125 , struct V_93 * V_94 ,
struct V_80 * V_81 , T_9 V_272 ,
struct V_273 * V_274 )
{
T_2 * V_96 ;
int V_14 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
V_96 = F_44 ( V_125 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 | V_275 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( V_14 ) {
F_2 ( V_9 , L_60 , V_14 ) ;
return V_14 ;
}
V_274 -> V_276 = 0 ;
V_274 -> V_277 = 0 ;
V_14 = F_95 ( V_53 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 , 0 , V_274 ) ;
if ( V_14 ) {
F_2 ( V_9 , L_61 , V_14 ) ;
F_41 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
return V_14 ;
}
static int
F_96 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 , T_9 V_272 ,
struct V_273 * V_274 )
{
return F_95 ( V_53 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 , 0 , V_274 ) ;
}
static int
F_97 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_80 * V_81 )
{
return F_41 ( V_53 , V_59 , V_81 -> V_88 , V_81 -> V_89 ) ;
}
static bool
F_98 ( char * V_40 , struct V_1 * V_2 , int V_278 )
{
struct V_27 * V_28 = F_12 ( V_40 ) ;
if ( V_28 -> V_49 != V_279 )
return false ;
if ( ! V_278 ) {
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_3 += F_13 ( V_28 -> V_30 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_22 ) ;
}
return true ;
}
static bool
F_99 ( char * V_40 )
{
struct V_27 * V_28 = F_12 ( V_40 ) ;
if ( V_28 -> V_49 != V_280 )
return false ;
F_2 ( V_9 , L_62 ) ;
return true ;
}
static int
F_100 ( struct V_58 * V_59 , struct V_80 * V_81 ,
struct V_182 * V_183 )
{
if ( V_59 -> V_55 -> V_2 -> V_64 & V_281 )
return F_101 ( 0 , V_59 , V_183 -> V_282 ,
F_102 ( V_183 ) ) ;
return F_103 ( 0 , V_59 , V_81 -> V_88 ,
V_81 -> V_89 ,
F_104 ( V_183 ) ? 1 : 0 ) ;
}
static int
F_105 ( const unsigned int V_53 , struct V_58 * V_59 ,
struct V_283 * V_40 )
{
int V_14 ;
T_2 V_75 = 0 ;
T_3 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , & V_75 , & V_76 , NULL , NULL ) ;
if ( V_14 )
return V_14 ;
V_40 -> V_284 = V_285 ;
V_14 = F_106 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ,
V_40 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
return V_14 ;
}
static bool
F_107 ( struct V_180 * V_286 , struct V_180 * V_287 )
{
return V_286 -> V_81 . V_88 == V_287 -> V_81 . V_88 &&
V_286 -> V_81 . V_89 == V_287 -> V_81 . V_89 ;
}
static int
F_108 ( const unsigned int V_53 , struct V_180 * V_181 , T_1 V_288 ,
T_1 V_278 , T_11 type , int V_289 , int V_290 , bool V_291 )
{
if ( V_290 && ! V_289 )
type = V_292 ;
return F_109 ( V_53 , F_68 ( V_181 -> V_185 ) ,
V_181 -> V_81 . V_88 , V_181 -> V_81 . V_89 ,
V_293 -> V_294 , V_278 , V_288 , type , V_291 ) ;
}
static void
F_110 ( struct V_236 * V_236 , struct V_80 * V_81 )
{
memcpy ( V_81 -> V_282 , F_66 ( V_236 ) -> V_282 , V_295 ) ;
}
static void
F_111 ( struct V_236 * V_236 , struct V_80 * V_81 )
{
memcpy ( F_66 ( V_236 ) -> V_282 , V_81 -> V_282 , V_295 ) ;
}
static void
F_112 ( struct V_80 * V_81 )
{
F_113 ( V_81 -> V_282 ) ;
}
static int
F_114 ( const unsigned int V_53 , struct V_54 * V_55 ,
const char * V_296 ,
struct V_297 * * V_298 ,
unsigned int * V_299 ,
const struct V_134 * V_135 , int V_300 )
{
int V_14 ;
T_2 * V_96 = NULL ;
int V_301 = 0 ;
struct V_58 * V_59 ;
struct V_302 * V_303 = NULL ;
struct V_304 * V_305 = NULL ;
V_217 V_306 = 0 , V_307 = 0 ;
F_2 ( V_9 , L_63 , V_296 ) ;
F_4 ( & V_308 ) ;
V_59 = F_115 ( & V_55 -> V_309 , struct V_58 ,
V_309 ) ;
if ( V_59 )
V_59 -> V_310 ++ ;
F_6 ( & V_308 ) ;
if ( ! V_59 ) {
F_2 ( V_8 , L_64 ,
V_55 ) ;
V_14 = - V_311 ;
goto V_121;
}
V_96 = F_116 ( V_296 , V_103 ,
& V_301 ,
V_135 , V_300 ) ;
if ( ! V_96 ) {
V_14 = - V_97 ;
goto V_121;
}
V_306 = sizeof( * V_303 ) + V_301 ;
V_303 = F_47 ( V_306 , V_104 ) ;
if ( ! V_303 ) {
V_14 = - V_97 ;
goto V_121;
}
V_303 -> V_312 = V_313 ;
memcpy ( V_303 -> V_314 , V_96 , V_301 ) ;
do {
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_315 ,
true , true ,
( char * ) V_303 , V_306 ,
( char * * ) & V_305 , & V_307 ) ;
if ( V_14 == - V_311 ) {
V_14 = F_34 ( V_53 , V_59 , V_70 , V_70 ,
V_315 ,
true , false ,
( char * ) V_303 , V_306 ,
( char * * ) & V_305 , & V_307 ) ;
}
} while ( V_14 == - V_56 );
if ( V_14 ) {
F_2 ( V_8 , L_65 , V_14 ) ;
goto V_121;
}
V_14 = F_117 ( V_305 , V_307 ,
V_299 , V_298 ,
V_135 , V_300 , V_296 ,
true ) ;
if ( V_14 ) {
F_2 ( V_8 , L_66 , V_14 ) ;
goto V_121;
}
V_121:
if ( V_59 ) {
F_4 ( & V_308 ) ;
V_59 -> V_310 -- ;
F_6 ( & V_308 ) ;
}
F_36 ( V_96 ) ;
F_36 ( V_303 ) ;
F_36 ( V_305 ) ;
return V_14 ;
}
static int
F_118 ( const unsigned int V_53 , struct V_58 * V_59 ,
const char * V_95 , char * * V_316 ,
struct V_93 * V_94 )
{
int V_14 ;
T_2 * V_96 ;
T_4 V_76 = V_77 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_317 * V_318 = NULL ;
struct V_319 * V_320 ;
unsigned int V_321 ;
unsigned int V_322 ;
unsigned int V_323 ;
unsigned int V_324 ;
F_2 ( V_9 , L_67 , V_325 , V_95 ) ;
V_96 = F_44 ( V_95 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_83 ;
V_79 . V_84 = V_85 ;
V_79 . V_86 = 0 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , & V_318 ) ;
if ( ! V_14 || ! V_318 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
if ( F_35 ( V_318 -> V_258 ) < sizeof( struct V_319 ) ||
F_119 ( V_318 ) + 4 < V_326 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
V_14 = 0 ;
V_320 = (struct V_319 * ) V_318 -> V_327 ;
V_321 = F_13 ( V_320 -> V_328 ) ;
V_322 = F_13 ( V_320 -> V_329 ) ;
V_323 = F_13 ( V_320 -> V_330 ) ;
V_324 = F_13 ( V_320 -> V_331 ) ;
if ( F_119 ( V_318 ) + 4 <
V_326 + V_322 + V_321 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
if ( F_119 ( V_318 ) + 4 <
V_326 + V_324 + V_323 ) {
F_36 ( V_96 ) ;
return - V_36 ;
}
* V_316 = F_120 (
( char * ) V_320 -> V_332 + V_322 ,
V_321 , true , V_94 -> V_333 ) ;
if ( ! ( * V_316 ) ) {
F_36 ( V_96 ) ;
return - V_97 ;
}
F_121 ( * V_316 , '/' ) ;
F_2 ( V_9 , L_68 , V_325 , * V_316 ) ;
F_36 ( V_96 ) ;
return V_14 ;
}
static struct V_334 *
F_122 ( struct V_93 * V_94 ,
const struct V_80 * V_335 , V_217 * V_336 )
{
struct V_334 * V_337 = NULL ;
unsigned int V_53 ;
int V_14 = - V_253 ;
struct V_338 * V_185 = F_123 ( V_94 ) ;
if ( F_124 ( V_185 ) )
return F_125 ( V_185 ) ;
V_53 = F_126 () ;
F_2 ( V_9 , L_69 ) ;
V_14 = F_127 ( V_53 , F_68 ( V_185 ) , V_335 -> V_88 ,
V_335 -> V_89 , ( void * * ) & V_337 , V_336 ) ;
F_128 ( V_53 ) ;
F_129 ( V_185 ) ;
F_2 ( V_9 , L_70 , V_325 , V_14 , * V_336 ) ;
if ( V_14 )
return F_130 ( V_14 ) ;
return V_337 ;
}
static struct V_334 *
F_131 ( struct V_93 * V_94 ,
const char * V_125 , V_217 * V_336 )
{
struct V_334 * V_337 = NULL ;
T_3 V_76 = V_77 ;
unsigned int V_53 ;
int V_14 ;
struct V_58 * V_59 ;
struct V_338 * V_185 = F_123 ( V_94 ) ;
struct V_80 V_81 ;
struct V_78 V_79 ;
T_2 * V_96 ;
F_2 ( V_9 , L_71 , V_125 ) ;
if ( F_124 ( V_185 ) )
return F_125 ( V_185 ) ;
V_59 = F_68 ( V_185 ) ;
V_53 = F_126 () ;
if ( F_132 ( V_94 ) )
V_79 . V_86 = V_339 ;
else
V_79 . V_86 = 0 ;
V_96 = F_44 ( V_125 , V_94 ) ;
if ( ! V_96 )
return F_130 ( - V_97 ) ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_340 ;
V_79 . V_84 = V_85 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( ! V_14 ) {
V_14 = F_127 ( V_53 , F_68 ( V_185 ) , V_81 . V_88 ,
V_81 . V_89 , ( void * * ) & V_337 , V_336 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
}
F_129 ( V_185 ) ;
F_128 ( V_53 ) ;
F_2 ( V_9 , L_70 , V_325 , V_14 , * V_336 ) ;
if ( V_14 )
return F_130 ( V_14 ) ;
return V_337 ;
}
static int
F_133 ( struct V_334 * V_341 , T_11 V_342 ,
struct V_236 * V_236 , const char * V_125 , int V_343 )
{
T_3 V_76 = V_77 ;
unsigned int V_53 ;
int V_14 , V_344 = 0 ;
struct V_58 * V_59 ;
struct V_93 * V_94 = F_134 ( V_236 -> V_345 ) ;
struct V_338 * V_185 = F_123 ( V_94 ) ;
struct V_80 V_81 ;
struct V_78 V_79 ;
T_2 * V_96 ;
F_2 ( V_9 , L_72 , V_125 ) ;
if ( F_124 ( V_185 ) )
return F_135 ( V_185 ) ;
V_59 = F_68 ( V_185 ) ;
V_53 = F_126 () ;
if ( F_132 ( V_94 ) )
V_79 . V_86 = V_339 ;
else
V_79 . V_86 = 0 ;
if ( V_343 == V_346 || V_343 == V_347 )
V_344 = V_348 ;
else
V_344 = V_349 ;
V_96 = F_44 ( V_125 , V_94 ) ;
if ( ! V_96 )
return - V_97 ;
V_79 . V_59 = V_59 ;
V_79 . V_82 = V_344 ;
V_79 . V_84 = V_85 ;
V_79 . V_125 = V_125 ;
V_79 . V_81 = & V_81 ;
V_79 . V_87 = false ;
V_14 = F_38 ( V_53 , & V_79 , V_96 , & V_76 , NULL , NULL ) ;
F_36 ( V_96 ) ;
if ( ! V_14 ) {
V_14 = F_136 ( V_53 , F_68 ( V_185 ) , V_81 . V_88 ,
V_81 . V_89 , V_341 , V_342 , V_343 ) ;
F_41 ( V_53 , V_59 , V_81 . V_88 , V_81 . V_89 ) ;
}
F_129 ( V_185 ) ;
F_128 ( V_53 ) ;
return V_14 ;
}
static struct V_334 *
F_137 ( struct V_93 * V_94 ,
struct V_236 * V_236 , const char * V_125 ,
V_217 * V_336 )
{
struct V_334 * V_337 = NULL ;
struct V_180 * V_350 = NULL ;
if ( V_236 )
V_350 = F_138 ( F_66 ( V_236 ) , true ) ;
if ( ! V_350 )
return F_131 ( V_94 , V_125 , V_336 ) ;
V_337 = F_122 ( V_94 , & V_350 -> V_81 , V_336 ) ;
F_139 ( V_350 ) ;
return V_337 ;
}
static long F_140 ( struct V_351 * V_351 , struct V_58 * V_59 ,
T_14 V_288 , T_14 V_137 , bool V_352 )
{
struct V_236 * V_236 ;
struct V_182 * V_238 ;
struct V_180 * V_181 = V_351 -> V_353 ;
struct V_354 V_355 ;
long V_14 ;
unsigned int V_53 ;
V_53 = F_126 () ;
V_236 = F_67 ( V_181 -> V_184 ) ;
V_238 = F_66 ( V_236 ) ;
if ( ! F_104 ( V_238 ) )
if ( V_352 == false )
return - V_253 ;
if ( ! ( V_238 -> V_239 & V_240 ) )
return - V_253 ;
if ( V_352 == false )
if ( F_141 ( V_236 ) < V_288 + V_137 )
return - V_253 ;
F_2 ( V_9 , L_73 , V_288 , V_137 ) ;
V_355 . V_356 = F_75 ( V_288 ) ;
V_355 . V_357 = F_75 ( V_288 + V_137 ) ;
V_14 = F_34 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 , V_358 ,
true , false ,
( char * ) & V_355 ,
sizeof( struct V_354 ) , NULL , NULL ) ;
F_128 ( V_53 ) ;
return V_14 ;
}
static long F_142 ( struct V_351 * V_351 , struct V_58 * V_59 ,
T_14 V_288 , T_14 V_137 )
{
struct V_236 * V_236 ;
struct V_182 * V_238 ;
struct V_180 * V_181 = V_351 -> V_353 ;
struct V_354 V_355 ;
long V_14 ;
unsigned int V_53 ;
T_4 V_246 = 1 ;
V_53 = F_126 () ;
V_236 = F_67 ( V_181 -> V_184 ) ;
V_238 = F_66 ( V_236 ) ;
if ( ! F_84 ( V_53 , V_59 , V_181 , V_236 , V_246 ) )
return - V_253 ;
F_2 ( V_9 , L_73 , V_288 , V_137 ) ;
V_355 . V_356 = F_75 ( V_288 ) ;
V_355 . V_357 = F_75 ( V_288 + V_137 ) ;
V_14 = F_34 ( V_53 , V_59 , V_181 -> V_81 . V_88 ,
V_181 -> V_81 . V_89 , V_358 ,
true , false ,
( char * ) & V_355 ,
sizeof( struct V_354 ) , NULL , NULL ) ;
F_128 ( V_53 ) ;
return V_14 ;
}
static long F_143 ( struct V_351 * V_351 , struct V_58 * V_59 ,
T_14 V_359 , T_14 V_137 , bool V_352 )
{
struct V_236 * V_236 ;
struct V_182 * V_238 ;
struct V_180 * V_181 = V_351 -> V_353 ;
long V_14 = - V_253 ;
unsigned int V_53 ;
V_53 = F_126 () ;
V_236 = F_67 ( V_181 -> V_184 ) ;
V_238 = F_66 ( V_236 ) ;
if ( ! F_104 ( V_238 ) )
if ( V_352 == false )
return - V_253 ;
if ( ( V_238 -> V_239 & V_240 ) == 0 ) {
if ( V_352 == true )
return 0 ;
else if ( F_141 ( V_236 ) >= V_359 + V_137 )
return 0 ;
else
return - V_253 ;
}
if ( ( V_352 == true ) || ( F_141 ( V_236 ) >= V_359 + V_137 ) ) {
if ( ( V_359 > 8192 ) || ( V_359 + V_137 + 8192 < F_141 ( V_236 ) ) )
return - V_253 ;
V_14 = F_84 ( V_53 , V_59 , V_181 , V_236 , false ) ;
}
F_128 ( V_53 ) ;
return V_14 ;
}
static long F_144 ( struct V_351 * V_351 , struct V_58 * V_59 , int V_360 ,
T_14 V_359 , T_14 V_137 )
{
if ( V_360 & V_361 )
return F_142 ( V_351 , V_59 , V_359 , V_137 ) ;
else if ( V_360 & V_362 ) {
if ( V_360 & V_363 )
return F_140 ( V_351 , V_59 , V_359 , V_137 , true ) ;
return F_140 ( V_351 , V_59 , V_359 , V_137 , false ) ;
} else if ( V_360 == V_363 )
return F_143 ( V_351 , V_59 , V_359 , V_137 , true ) ;
else if ( V_360 == 0 )
return F_143 ( V_351 , V_59 , V_359 , V_137 , false ) ;
return - V_253 ;
}
static void
F_145 ( struct V_1 * V_2 ,
struct V_182 * V_183 , bool V_364 )
{
if ( V_364 )
V_2 -> V_16 -> V_186 ( V_183 , V_365 ,
0 , NULL ) ;
else
V_2 -> V_16 -> V_186 ( V_183 , 0 , 0 , NULL ) ;
}
static void
F_146 ( struct V_182 * V_183 , T_11 V_76 ,
unsigned int V_187 , bool * V_188 )
{
V_76 &= 0xFF ;
if ( V_76 == V_366 )
return;
if ( V_76 == V_367 ) {
V_183 -> V_76 = V_368 ;
F_2 ( V_9 , L_74 ,
& V_183 -> V_369 ) ;
} else if ( V_76 == V_370 ) {
V_183 -> V_76 = V_371 ;
F_2 ( V_9 , L_75 ,
& V_183 -> V_369 ) ;
} else if ( V_76 == V_365 ) {
V_183 -> V_76 = V_372 ;
F_2 ( V_9 , L_76 ,
& V_183 -> V_369 ) ;
} else
V_183 -> V_76 = 0 ;
}
static void
F_147 ( struct V_182 * V_183 , T_11 V_76 ,
unsigned int V_187 , bool * V_188 )
{
char V_373 [ 5 ] = { 0 } ;
V_76 &= 0xFF ;
if ( V_76 == V_366 )
return;
V_183 -> V_76 = 0 ;
if ( V_76 & V_374 ) {
V_183 -> V_76 |= V_372 ;
strcat ( V_373 , L_77 ) ;
}
if ( V_76 & V_375 ) {
V_183 -> V_76 |= V_376 ;
strcat ( V_373 , L_78 ) ;
}
if ( V_76 & V_377 ) {
V_183 -> V_76 |= V_378 ;
strcat ( V_373 , L_79 ) ;
}
if ( ! V_183 -> V_76 )
strcat ( V_373 , L_80 ) ;
F_2 ( V_9 , L_81 , V_373 ,
& V_183 -> V_369 ) ;
}
static void
F_148 ( struct V_182 * V_183 , T_11 V_76 ,
unsigned int V_187 , bool * V_188 )
{
unsigned int V_379 = V_183 -> V_76 ;
F_147 ( V_183 , V_76 , V_187 , V_188 ) ;
if ( V_188 ) {
* V_188 = false ;
if ( V_379 == V_372 ) {
if ( V_183 -> V_76 == V_372 &&
( V_187 - V_183 -> V_187 > 0 ) )
* V_188 = true ;
else if ( V_183 -> V_76 == V_380 &&
( V_187 - V_183 -> V_187 > 1 ) )
* V_188 = true ;
else if ( V_183 -> V_76 == V_368 &&
( V_187 - V_183 -> V_187 > 1 ) )
* V_188 = true ;
else if ( V_183 -> V_76 == 0 &&
( V_187 - V_183 -> V_187 > 0 ) )
* V_188 = true ;
} else if ( V_379 == V_380 ) {
if ( V_183 -> V_76 == V_380 &&
( V_187 - V_183 -> V_187 > 0 ) )
* V_188 = true ;
else if ( V_183 -> V_76 == V_368 &&
( V_187 - V_183 -> V_187 > 1 ) )
* V_188 = true ;
}
V_183 -> V_187 = V_187 ;
}
}
static bool
F_149 ( T_11 V_76 )
{
return V_76 == V_365 ;
}
static bool
F_150 ( T_11 V_76 )
{
return ( V_76 & V_374 ) &&
! ( V_76 & V_377 ) ;
}
static T_15
F_151 ( T_3 V_76 )
{
if ( V_76 == V_370 )
return V_381 | V_382 ;
else if ( V_76 == V_365 )
return V_382 ;
else if ( V_76 == V_367 )
return V_383 | V_382 |
V_381 ;
return 0 ;
}
static char *
F_152 ( T_3 * V_282 , T_3 V_76 )
{
struct V_384 * V_40 ;
V_40 = F_47 ( sizeof( struct V_384 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_385 . V_386 = F_75 ( * ( ( T_5 * ) V_282 ) ) ;
V_40 -> V_385 . V_387 = F_75 ( * ( ( T_5 * ) ( V_282 + 8 ) ) ) ;
V_40 -> V_385 . V_388 = F_151 ( V_76 ) ;
V_40 -> V_389 . V_225 = F_54 ( F_153
( struct V_384 , V_385 ) ) ;
V_40 -> V_389 . V_226 = F_74 ( sizeof( struct V_390 ) ) ;
V_40 -> V_389 . V_391 = F_54 ( F_153
( struct V_384 , V_392 ) ) ;
V_40 -> V_389 . V_393 = F_54 ( 4 ) ;
V_40 -> V_392 [ 0 ] = 'R' ;
V_40 -> V_392 [ 1 ] = 'q' ;
V_40 -> V_392 [ 2 ] = 'L' ;
V_40 -> V_392 [ 3 ] = 's' ;
return ( char * ) V_40 ;
}
static char *
F_154 ( T_3 * V_282 , T_3 V_76 )
{
struct V_394 * V_40 ;
V_40 = F_47 ( sizeof( struct V_394 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_385 . V_386 = F_75 ( * ( ( T_5 * ) V_282 ) ) ;
V_40 -> V_385 . V_387 = F_75 ( * ( ( T_5 * ) ( V_282 + 8 ) ) ) ;
V_40 -> V_385 . V_388 = F_151 ( V_76 ) ;
V_40 -> V_389 . V_225 = F_54 ( F_153
( struct V_394 , V_385 ) ) ;
V_40 -> V_389 . V_226 = F_74 ( sizeof( struct V_395 ) ) ;
V_40 -> V_389 . V_391 = F_54 ( F_153
( struct V_394 , V_392 ) ) ;
V_40 -> V_389 . V_393 = F_54 ( 4 ) ;
V_40 -> V_392 [ 0 ] = 'R' ;
V_40 -> V_392 [ 1 ] = 'q' ;
V_40 -> V_392 [ 2 ] = 'L' ;
V_40 -> V_392 [ 3 ] = 's' ;
return ( char * ) V_40 ;
}
static T_4
F_155 ( void * V_40 , unsigned int * V_187 )
{
struct V_384 * V_396 = (struct V_384 * ) V_40 ;
* V_187 = 0 ;
if ( V_396 -> V_385 . V_397 & V_398 )
return V_366 ;
return F_35 ( V_396 -> V_385 . V_388 ) ;
}
static T_4
F_156 ( void * V_40 , unsigned int * V_187 )
{
struct V_394 * V_396 = (struct V_394 * ) V_40 ;
* V_187 = F_13 ( V_396 -> V_385 . V_399 ) ;
if ( V_396 -> V_385 . V_397 & V_398 )
return V_366 ;
return F_35 ( V_396 -> V_385 . V_388 ) ;
}
static unsigned int
F_157 ( struct V_236 * V_236 )
{
return F_19 (unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE) ;
}
static bool
F_158 ( struct V_180 * V_181 )
{
return ! V_181 -> V_400 ;
}
static void
F_159 ( struct V_401 * V_402 , struct V_403 * V_404 )
{
struct V_27 * V_28 =
(struct V_27 * ) V_404 -> V_405 [ 1 ] . V_406 ;
unsigned int V_407 = F_119 ( V_404 -> V_405 [ 0 ] . V_406 ) ;
memset ( V_402 , 0 , sizeof( struct V_401 ) ) ;
V_402 -> V_43 = V_44 ;
V_402 -> V_408 = F_74 ( V_407 ) ;
V_402 -> V_50 = F_54 ( 0x01 ) ;
F_160 ( & V_402 -> V_409 , V_410 ) ;
memcpy ( & V_402 -> V_411 , & V_28 -> V_411 , 8 ) ;
F_161 ( V_402 , sizeof( struct V_401 ) - 4 ) ;
F_161 ( V_402 , V_407 ) ;
}
static struct V_412 *
F_162 ( struct V_403 * V_413 , T_3 * V_414 )
{
unsigned int V_415 = V_413 -> V_416 + V_413 -> V_417 + 1 ;
unsigned int V_418 = sizeof( struct V_401 ) - 24 ;
struct V_412 * V_419 ;
unsigned int V_139 ;
unsigned int V_420 ;
V_419 = F_163 ( V_415 , sizeof( struct V_412 ) , V_104 ) ;
if ( ! V_419 )
return NULL ;
F_164 ( V_419 , V_415 ) ;
F_165 ( & V_419 [ 0 ] , V_413 -> V_405 [ 0 ] . V_406 + 24 , V_418 ) ;
for ( V_139 = 1 ; V_139 < V_413 -> V_416 ; V_139 ++ )
F_165 ( & V_419 [ V_139 ] , V_413 -> V_405 [ V_139 ] . V_406 ,
V_413 -> V_405 [ V_139 ] . V_421 ) ;
for ( V_420 = 0 ; V_139 < V_415 - 1 ; V_139 ++ , V_420 ++ ) {
unsigned int V_137 = ( V_420 < V_413 -> V_417 - 1 ) ? V_413 -> V_422
: V_413 -> V_423 ;
F_166 ( & V_419 [ V_139 ] , V_413 -> V_424 [ V_420 ] , V_137 , 0 ) ;
}
F_165 ( & V_419 [ V_415 - 1 ] , V_414 , V_425 ) ;
return V_419 ;
}
static void F_167 ( struct V_426 * V_427 , int V_428 )
{
struct V_429 * V_430 = V_427 -> V_99 ;
if ( V_428 == - V_431 )
return;
V_430 -> V_428 = V_428 ;
F_168 ( & V_430 -> V_432 ) ;
}
static int
F_169 ( struct V_1 * V_2 , T_1 V_433 , int V_434 , T_3 * V_435 )
{
struct V_54 * V_55 ;
T_3 * V_436 ;
F_4 ( & V_308 ) ;
F_24 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_55 -> V_437 != V_433 )
continue;
V_436 = V_434 ? V_55 -> V_438 :
V_55 -> V_439 ;
memcpy ( V_435 , V_436 , V_440 ) ;
F_6 ( & V_308 ) ;
return 0 ;
}
F_6 ( & V_308 ) ;
return 1 ;
}
static int
F_170 ( struct V_1 * V_2 , struct V_403 * V_413 , int V_434 )
{
struct V_401 * V_402 =
(struct V_401 * ) V_413 -> V_405 [ 0 ] . V_406 ;
unsigned int V_418 = sizeof( struct V_401 ) - 24 ;
int V_14 = 0 ;
struct V_412 * V_419 ;
T_3 V_414 [ V_425 ] = {} ;
T_3 V_435 [ V_440 ] ;
struct V_441 * V_427 ;
char * V_442 ;
unsigned int V_443 ;
struct V_429 V_444 = { 0 , } ;
struct V_445 * V_446 ;
unsigned int V_447 = F_35 ( V_402 -> V_408 ) ;
F_171 ( & V_444 . V_432 ) ;
V_14 = F_169 ( V_2 , V_402 -> V_411 , V_434 , V_435 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_82 , V_325 ,
V_434 ? L_83 : L_84 ) ;
return 0 ;
}
V_14 = F_172 ( V_2 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_85 , V_325 ) ;
return V_14 ;
}
V_446 = V_434 ? V_2 -> V_448 . V_449 :
V_2 -> V_448 . V_450 ;
V_14 = F_173 ( V_446 , V_435 , V_440 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_86 , V_325 , V_14 ) ;
return V_14 ;
}
V_14 = F_174 ( V_446 , V_425 ) ;
if ( V_14 ) {
F_2 ( V_8 , L_87 , V_325 , V_14 ) ;
return V_14 ;
}
V_427 = F_175 ( V_446 , V_104 ) ;
if ( ! V_427 ) {
F_2 ( V_8 , L_88 , V_325 ) ;
return - V_97 ;
}
if ( ! V_434 ) {
memcpy ( V_414 , & V_402 -> V_451 , V_425 ) ;
V_447 += V_425 ;
}
V_419 = F_162 ( V_413 , V_414 ) ;
if ( ! V_419 ) {
F_2 ( V_8 , L_89 , V_325 ) ;
V_14 = - V_97 ;
goto V_452;
}
V_443 = F_176 ( V_446 ) ;
V_442 = F_47 ( V_443 , V_104 ) ;
if ( ! V_442 ) {
F_2 ( V_8 , L_90 , V_325 ) ;
V_14 = - V_97 ;
goto V_453;
}
V_442 [ 0 ] = 3 ;
memcpy ( V_442 + 1 , ( char * ) V_402 -> V_409 , V_410 ) ;
F_177 ( V_427 , V_419 , V_419 , V_447 , V_442 ) ;
F_178 ( V_427 , V_418 ) ;
F_179 ( V_427 , V_454 ,
F_167 , & V_444 ) ;
V_14 = V_434 ? F_180 ( V_427 ) : F_181 ( V_427 ) ;
if ( V_14 == - V_431 || V_14 == - V_455 ) {
F_182 ( & V_444 . V_432 ) ;
V_14 = V_444 . V_428 ;
}
if ( ! V_14 && V_434 )
memcpy ( & V_402 -> V_451 , V_414 , V_425 ) ;
F_36 ( V_442 ) ;
V_453:
F_36 ( V_419 ) ;
V_452:
F_36 ( V_427 ) ;
return V_14 ;
}
static int
F_183 ( struct V_1 * V_2 , struct V_403 * V_456 ,
struct V_403 * V_404 )
{
struct V_233 * V_234 ;
struct V_457 * * V_458 ;
struct V_401 * V_402 ;
unsigned int V_459 = V_404 -> V_417 ;
int V_139 ;
int V_14 = - V_97 ;
V_458 = F_163 ( V_459 , sizeof( struct V_457 * ) , V_104 ) ;
if ( ! V_458 )
return V_14 ;
V_456 -> V_424 = V_458 ;
V_456 -> V_417 = V_404 -> V_417 ;
V_456 -> V_422 = V_404 -> V_422 ;
V_456 -> V_423 = V_404 -> V_423 ;
for ( V_139 = 0 ; V_139 < V_459 ; V_139 ++ ) {
V_458 [ V_139 ] = F_184 ( V_104 | V_460 ) ;
if ( ! V_458 [ V_139 ] )
goto V_461;
}
V_234 = F_163 ( V_404 -> V_416 , sizeof( struct V_233 ) , V_104 ) ;
if ( ! V_234 )
goto V_461;
memcpy ( & V_234 [ 1 ] , & V_404 -> V_405 [ 1 ] ,
sizeof( struct V_233 ) * ( V_404 -> V_416 - 1 ) ) ;
V_456 -> V_405 = V_234 ;
V_456 -> V_416 = V_404 -> V_416 ;
V_402 = F_73 ( sizeof( struct V_401 ) , V_104 ) ;
if ( ! V_402 )
goto V_462;
F_159 ( V_402 , V_404 ) ;
V_456 -> V_405 [ 0 ] . V_406 = V_402 ;
V_456 -> V_405 [ 0 ] . V_421 = sizeof( struct V_401 ) ;
for ( V_139 = 0 ; V_139 < V_459 ; V_139 ++ ) {
char * V_105 = F_185 ( V_456 -> V_424 [ V_139 ] ) ;
char * V_108 = F_185 ( V_404 -> V_424 [ V_139 ] ) ;
unsigned int V_137 = ( V_139 < V_459 - 1 ) ? V_456 -> V_422 :
V_456 -> V_423 ;
memcpy ( V_105 , V_108 , V_137 ) ;
F_186 ( V_456 -> V_424 [ V_139 ] ) ;
F_186 ( V_404 -> V_424 [ V_139 ] ) ;
}
V_14 = F_170 ( V_2 , V_456 , 1 ) ;
F_2 ( V_9 , L_91 , V_14 ) ;
if ( V_14 )
goto V_463;
return V_14 ;
V_463:
F_36 ( V_402 ) ;
V_462:
F_36 ( V_234 ) ;
V_461:
for ( V_139 = V_139 - 1 ; V_139 >= 0 ; V_139 -- )
F_187 ( V_458 [ V_139 ] ) ;
F_36 ( V_458 ) ;
return V_14 ;
}
static void
F_188 ( struct V_403 * V_413 )
{
int V_139 = V_413 -> V_417 - 1 ;
for (; V_139 >= 0 ; V_139 -- )
F_187 ( V_413 -> V_424 [ V_139 ] ) ;
F_36 ( V_413 -> V_424 ) ;
F_36 ( V_413 -> V_405 [ 0 ] . V_406 ) ;
F_36 ( V_413 -> V_405 ) ;
}
static int
F_189 ( void * V_40 )
{
struct V_401 * V_464 = V_40 ;
return V_464 -> V_43 == V_44 ;
}
static int
F_190 ( struct V_1 * V_2 , char * V_40 ,
unsigned int V_465 , struct V_457 * * V_458 ,
unsigned int V_459 , unsigned int V_466 )
{
struct V_233 V_234 [ 2 ] ;
struct V_403 V_413 = { NULL } ;
struct V_467 * V_468 ;
int V_14 ;
V_234 [ 0 ] . V_406 = V_40 ;
V_234 [ 0 ] . V_421 = sizeof( struct V_401 ) ;
V_234 [ 1 ] . V_406 = V_40 + sizeof( struct V_401 ) ;
V_234 [ 1 ] . V_421 = V_465 ;
V_413 . V_405 = V_234 ;
V_413 . V_416 = 2 ;
V_413 . V_424 = V_458 ;
V_413 . V_417 = V_459 ;
V_413 . V_422 = V_469 ;
V_413 . V_423 = ( V_466 % V_469 ) ? : V_469 ;
V_14 = F_170 ( V_2 , & V_413 , 0 ) ;
F_2 ( V_9 , L_92 , V_14 ) ;
if ( V_14 )
return V_14 ;
memmove ( V_40 + 4 , V_234 [ 1 ] . V_406 , V_465 ) ;
V_468 = (struct V_467 * ) V_40 ;
V_468 -> V_470 = F_191 ( V_465 + V_466 ) ;
V_2 -> V_471 = V_465 + V_466 + 4 ;
return V_14 ;
}
static int
F_192 ( struct V_1 * V_2 , struct V_457 * * V_458 ,
unsigned int V_459 , unsigned int V_137 )
{
int V_139 ;
int V_278 ;
for ( V_139 = 0 ; V_139 < V_459 ; V_139 ++ ) {
struct V_457 * V_457 = V_458 [ V_139 ] ;
T_8 V_472 ;
V_472 = V_137 ;
if ( V_137 >= V_469 ) {
V_472 = V_469 ;
V_137 -= V_472 ;
} else {
F_193 ( V_457 , V_137 , V_469 - V_137 ) ;
V_137 = 0 ;
}
V_278 = F_194 ( V_2 , V_457 , V_472 ) ;
if ( V_278 < 0 )
return V_278 ;
V_2 -> V_471 += V_278 ;
}
return 0 ;
}
static int
F_195 ( struct V_457 * * V_458 , unsigned int V_459 , unsigned int V_473 ,
unsigned int V_474 , struct V_475 * * V_476 )
{
struct V_475 * V_477 ;
int V_139 ;
V_477 = F_196 ( V_459 , sizeof( struct V_475 ) , V_104 ) ;
if ( ! V_477 )
return - V_97 ;
for ( V_139 = 0 ; V_139 < V_459 ; V_139 ++ ) {
V_477 [ V_139 ] . V_478 = V_458 [ V_139 ] ;
V_477 [ V_139 ] . V_479 = ( V_139 == 0 ) ? V_474 : 0 ;
V_477 [ V_139 ] . V_480 = F_19 (unsigned int, PAGE_SIZE, data_size) ;
V_473 -= V_477 [ V_139 ] . V_480 ;
}
if ( V_473 != 0 ) {
F_2 ( V_8 , L_93 , V_325 ) ;
F_36 ( V_477 ) ;
return - V_120 ;
}
* V_476 = V_477 ;
return 0 ;
}
static int
F_197 ( struct V_1 * V_2 , struct V_25 * V_26 ,
char * V_40 , unsigned int V_481 , struct V_457 * * V_458 ,
unsigned int V_459 , unsigned int V_466 )
{
unsigned int V_482 ;
unsigned int V_483 ;
unsigned int V_474 ;
unsigned int V_484 ;
unsigned int V_485 ;
struct V_486 * V_487 = V_26 -> V_488 ;
struct V_27 * V_28 = F_12 ( V_40 ) ;
struct V_475 * V_477 = NULL ;
struct V_489 V_490 ;
struct V_233 V_234 ;
int V_278 ;
if ( V_28 -> V_48 != V_491 ) {
F_2 ( V_8 , L_94 ) ;
return - V_492 ;
}
if ( V_2 -> V_16 -> V_493 &&
V_2 -> V_16 -> V_493 ( V_40 ) ) {
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_494 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_495 &&
V_2 -> V_16 -> V_495 ( V_40 , V_2 , 0 ) )
return - 1 ;
V_487 -> V_444 = V_2 -> V_16 -> V_496 ( V_40 , false ) ;
if ( V_487 -> V_444 != 0 ) {
F_2 ( V_9 , L_95 ,
V_325 , V_487 -> V_444 ) ;
F_198 ( V_26 , V_487 -> V_444 ) ;
return 0 ;
}
V_482 = V_2 -> V_16 -> V_497 ( V_40 ) + 4 ;
V_483 = V_2 -> V_16 -> V_498 ( V_40 ) ;
if ( V_482 < V_2 -> V_499 -> V_500 ) {
F_2 ( V_9 , L_96 ,
V_325 , V_482 ) ;
V_482 = V_2 -> V_499 -> V_500 ;
} else if ( V_482 > V_501 ) {
F_2 ( V_9 , L_97 ,
V_325 , V_482 ) ;
V_487 -> V_444 = - V_120 ;
F_198 ( V_26 , V_487 -> V_444 ) ;
return 0 ;
}
V_485 = V_482 - V_2 -> V_499 -> V_500 ;
if ( V_481 <= V_482 ) {
V_484 = V_485 / V_469 ;
V_474 = V_485 % V_469 ;
if ( V_484 != 0 ) {
F_2 ( V_9 , L_98 ,
V_325 , V_482 ) ;
V_487 -> V_444 = - V_120 ;
F_198 ( V_26 , V_487 -> V_444 ) ;
return 0 ;
}
if ( V_483 > V_466 - V_485 ) {
V_487 -> V_444 = - V_120 ;
F_198 ( V_26 , V_487 -> V_444 ) ;
return 0 ;
}
V_487 -> V_444 = F_195 ( V_458 , V_459 , V_466 ,
V_474 , & V_477 ) ;
if ( V_487 -> V_444 != 0 ) {
F_198 ( V_26 , V_487 -> V_444 ) ;
return 0 ;
}
F_199 ( & V_490 , V_502 | V_503 , V_477 , V_459 , V_483 ) ;
} else if ( V_481 >= V_482 + V_483 ) {
F_200 ( V_459 > 0 , L_99 ) ;
V_234 . V_406 = V_40 + V_482 ;
V_234 . V_421 = V_483 ;
F_201 ( & V_490 , V_502 | V_504 , & V_234 , 1 , V_483 ) ;
} else {
F_200 ( 1 , L_100 ) ;
V_487 -> V_444 = - V_120 ;
F_198 ( V_26 , V_487 -> V_444 ) ;
return 0 ;
}
V_487 -> V_234 [ 0 ] . V_406 = V_40 ;
V_487 -> V_234 [ 0 ] . V_421 = 4 ;
V_487 -> V_234 [ 1 ] . V_406 = V_40 + 4 ;
V_487 -> V_234 [ 1 ] . V_421 = V_2 -> V_499 -> V_500 - 4 ;
F_2 ( V_9 , L_101 ,
V_487 -> V_234 [ 0 ] . V_406 , V_2 -> V_499 -> V_500 ) ;
V_278 = V_487 -> V_505 ( V_2 , V_487 , & V_490 ) ;
F_36 ( V_477 ) ;
if ( V_278 < 0 )
return V_278 ;
F_198 ( V_26 , false ) ;
return V_278 ;
}
static int
F_202 ( struct V_1 * V_2 , struct V_25 * * V_26 )
{
char * V_40 = V_2 -> V_506 ;
struct V_401 * V_402 = (struct V_401 * ) V_40 ;
unsigned int V_459 ;
struct V_457 * * V_458 ;
unsigned int V_137 ;
unsigned int V_507 = F_119 ( V_40 ) + 4 ;
int V_14 ;
int V_139 = 0 ;
V_137 = F_19 (unsigned int, buflen, server->vals->read_rsp_size - 4 +
sizeof(struct smb2_transform_hdr)) - F_203 ( V_2 ) + 1 ;
V_14 = F_204 ( V_2 , V_40 + F_203 ( V_2 ) - 1 , V_137 ) ;
if ( V_14 < 0 )
return V_14 ;
V_2 -> V_471 += V_14 ;
V_137 = F_35 ( V_402 -> V_408 ) + 4 -
V_2 -> V_499 -> V_500 ;
V_459 = F_20 ( V_137 , V_469 ) ;
V_458 = F_163 ( V_459 , sizeof( struct V_457 * ) , V_104 ) ;
if ( ! V_458 ) {
V_14 = - V_97 ;
goto V_508;
}
for (; V_139 < V_459 ; V_139 ++ ) {
V_458 [ V_139 ] = F_184 ( V_104 | V_460 ) ;
if ( ! V_458 [ V_139 ] ) {
V_14 = - V_97 ;
goto V_508;
}
}
V_14 = F_192 ( V_2 , V_458 , V_459 , V_137 ) ;
if ( V_14 )
goto V_509;
V_14 = F_205 ( V_2 ) ;
if ( V_14 )
goto V_509;
V_14 = F_190 ( V_2 , V_40 , V_2 -> V_499 -> V_500 - 4 ,
V_458 , V_459 , V_137 ) ;
if ( V_14 )
goto V_509;
* V_26 = F_22 ( V_2 , V_40 ) ;
if ( * V_26 == NULL )
F_2 ( V_9 , L_102 ) ;
else {
F_2 ( V_9 , L_103 ) ;
( * V_26 ) -> V_510 = true ;
V_14 = F_197 ( V_2 , * V_26 , V_40 ,
V_2 -> V_499 -> V_500 ,
V_458 , V_459 , V_137 ) ;
}
V_509:
for ( V_139 = V_139 - 1 ; V_139 >= 0 ; V_139 -- )
F_187 ( V_458 [ V_139 ] ) ;
F_36 ( V_458 ) ;
return V_14 ;
V_508:
F_205 ( V_2 ) ;
goto V_509;
}
static int
F_206 ( struct V_1 * V_2 ,
struct V_25 * * V_26 )
{
int V_278 ;
char * V_40 = V_2 -> V_506 ;
unsigned int V_511 = F_119 ( V_40 ) ;
unsigned int V_126 ;
struct V_25 * V_512 ;
if ( V_511 + 4 > V_501 ) {
V_2 -> V_513 = true ;
memcpy ( V_2 -> V_514 , V_40 , V_2 -> V_471 ) ;
V_40 = V_2 -> V_514 ;
}
V_278 = F_204 ( V_2 , V_40 + F_203 ( V_2 ) - 1 ,
V_511 - F_203 ( V_2 ) + 1 + 4 ) ;
if ( V_278 < 0 )
return V_278 ;
V_2 -> V_471 += V_278 ;
V_126 = V_511 + 4 - sizeof( struct V_401 ) ;
V_278 = F_190 ( V_2 , V_40 , V_126 , NULL , 0 , 0 ) ;
if ( V_278 )
return V_278 ;
V_512 = F_22 ( V_2 , V_40 ) ;
if ( V_512 == NULL )
F_2 ( V_9 , L_102 ) ;
else {
F_2 ( V_9 , L_103 ) ;
V_512 -> V_510 = true ;
}
* V_26 = V_512 ;
if ( V_512 && V_512 -> V_515 )
return V_512 -> V_515 ( V_2 , V_512 ) ;
return F_207 ( V_2 , V_512 ) ;
}
static int
F_208 ( struct V_1 * V_2 , struct V_25 * * V_26 )
{
char * V_40 = V_2 -> V_506 ;
unsigned int V_511 = F_119 ( V_40 ) ;
struct V_401 * V_402 = (struct V_401 * ) V_40 ;
unsigned int V_407 = F_35 ( V_402 -> V_408 ) ;
if ( V_511 + 4 < sizeof( struct V_401 ) +
sizeof( struct V_27 ) ) {
F_2 ( V_8 , L_104 ,
V_511 ) ;
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_494 ) ;
return - V_516 ;
}
if ( V_511 + 4 < V_407 + sizeof( struct V_401 ) ) {
F_2 ( V_8 , L_105 ) ;
F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_494 ) ;
return - V_516 ;
}
if ( V_511 + 4 > V_517 + F_209 ( V_2 ) )
return F_202 ( V_2 , V_26 ) ;
return F_206 ( V_2 , V_26 ) ;
}
int
F_210 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
char * V_40 = V_2 -> V_513 ? V_2 -> V_514 : V_2 -> V_506 ;
return F_197 ( V_2 , V_26 , V_40 , F_119 ( V_40 ) + 4 ,
NULL , 0 , 0 ) ;
}
