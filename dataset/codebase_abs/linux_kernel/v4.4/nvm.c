static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , const T_2 * V_6 )
{
struct V_7 V_8 = {
. V_4 = F_2 ( V_4 ) ,
. V_5 = F_2 ( V_5 ) ,
. type = F_2 ( V_3 ) ,
. V_9 = V_10 ,
} ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = { sizeof( struct V_7 ) , V_5 } ,
. V_16 = V_17 ,
. V_6 = { & V_8 , V_6 } ,
. V_18 = { 0 , V_19 } ,
} ;
return F_3 ( V_2 , & V_12 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_2 * V_6 )
{
struct V_7 V_8 = {
. V_4 = F_2 ( V_4 ) ,
. V_5 = F_2 ( V_5 ) ,
. type = F_2 ( V_3 ) ,
. V_9 = V_20 ,
} ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_16 = V_25 | V_17 ,
. V_6 = { & V_8 , } ,
} ;
int V_26 , V_27 , V_28 ;
T_2 * V_29 ;
V_12 . V_15 [ 0 ] = sizeof( struct V_7 ) ;
V_26 = F_3 ( V_2 , & V_12 ) ;
if ( V_26 )
return V_26 ;
V_24 = V_12 . V_30 ;
V_22 = ( void * ) V_24 -> V_6 ;
V_26 = F_5 ( V_22 -> V_31 ) ;
V_27 = F_5 ( V_22 -> V_5 ) ;
V_28 = F_5 ( V_22 -> V_4 ) ;
V_29 = V_22 -> V_6 ;
if ( V_26 ) {
if ( ( V_4 != 0 ) &&
( V_26 == V_32 ) ) {
F_6 ( V_2 -> V_33 -> V_34 ,
L_1 ,
V_4 ) ;
V_26 = 0 ;
} else {
F_6 ( V_2 -> V_33 -> V_34 ,
L_2 ,
V_26 , V_2 -> V_35 -> V_36 ) ;
V_26 = - V_37 ;
}
goto exit;
}
if ( V_28 != V_4 ) {
F_7 ( V_2 , L_3 ,
V_28 ) ;
V_26 = - V_38 ;
goto exit;
}
memcpy ( V_6 + V_4 , V_29 , V_27 ) ;
V_26 = V_27 ;
exit:
F_8 ( & V_12 ) ;
return V_26 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
const T_2 * V_6 , T_1 V_5 )
{
int V_4 = 0 ;
while ( V_4 < V_5 ) {
int V_39 , V_26 ;
V_39 = F_10 ( V_40 ,
V_5 - V_4 ) ;
V_26 = F_1 ( V_2 , V_3 , V_4 ,
V_39 , V_6 + V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
V_4 += V_39 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_6 , T_3 V_41 )
{
T_1 V_5 , V_4 = 0 ;
int V_26 ;
V_5 = V_40 ;
V_26 = V_5 ;
while ( V_26 == V_5 ) {
if ( ( V_41 + V_4 + V_5 ) >
V_2 -> V_35 -> V_42 -> V_43 ) {
F_7 ( V_2 , L_4 ) ;
return - V_44 ;
}
V_26 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_26 < 0 ) {
F_6 ( V_2 -> V_33 -> V_34 ,
L_5 ,
V_3 , V_4 , V_5 ) ;
return V_26 ;
}
V_4 += V_26 ;
}
F_6 ( V_2 -> V_33 -> V_34 ,
L_6 , V_3 ) ;
return V_4 ;
}
static struct V_45 *
F_12 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_48 ;
const T_4 * V_49 , * V_50 , * V_51 , * V_52 , * V_53 , * V_54 ;
bool V_55 ;
T_3 V_56 , V_57 ;
if ( V_2 -> V_33 -> V_35 -> V_58 != V_59 ) {
if ( ! V_2 -> V_48 [ V_60 ] . V_6 ||
! V_2 -> V_48 [ V_2 -> V_35 -> V_61 ] . V_6 ) {
F_7 ( V_2 , L_7 ) ;
return NULL ;
}
} else {
if ( ! V_2 -> V_48 [ V_60 ] . V_6 ||
! V_2 -> V_48 [ V_62 ] . V_6 ) {
F_7 ( V_2 ,
L_8 ) ;
return NULL ;
}
if ( ! V_2 -> V_48 [ V_2 -> V_35 -> V_61 ] . V_6 &&
! V_2 -> V_48 [ V_63 ] . V_6 ) {
F_7 ( V_2 ,
L_9 ) ;
return NULL ;
}
if ( ! V_2 -> V_48 [ V_64 ] . V_6 ) {
F_7 ( V_2 ,
L_10 ) ;
return NULL ;
}
}
if ( F_13 ( ! V_2 -> V_35 ) )
return NULL ;
V_56 = F_14 ( V_2 -> V_33 , V_65 ) ;
V_57 = F_14 ( V_2 -> V_33 , V_66 ) ;
V_49 = ( const T_4 * ) V_47 [ V_2 -> V_35 -> V_61 ] . V_6 ;
V_50 = ( const T_4 * ) V_47 [ V_60 ] . V_6 ;
V_51 = ( const T_4 * ) V_47 [ V_67 ] . V_6 ;
V_52 = ( const T_4 * ) V_47 [ V_62 ] . V_6 ;
V_53 =
( const T_4 * ) V_47 [ V_63 ] . V_6 ;
V_54 = ( const T_4 * ) V_47 [ V_64 ] . V_6 ;
V_55 = ! V_68 . V_69 &&
F_15 ( & V_2 -> V_70 -> V_71 ,
V_72 ) ;
return F_16 ( V_2 -> V_33 -> V_34 , V_2 -> V_35 , V_49 , V_50 , V_51 ,
V_52 , V_53 , V_54 ,
V_2 -> V_70 -> V_73 , V_2 -> V_70 -> V_74 ,
V_55 , V_56 , V_57 ,
V_2 -> V_33 -> V_75 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_26 , V_76 ;
T_1 V_77 ;
const struct V_78 * V_79 ;
const struct {
T_4 V_80 ;
T_4 V_81 ;
T_2 V_6 [] ;
} * V_82 ;
const T_2 * V_83 , * V_84 ;
int V_85 ;
const T_5 * V_86 ;
#define F_18 ( T_6 ) (8 * (x & 0x03FF))
#define F_19 ( T_6 ) (x >> 12)
#define F_20 ( T_6 ) (2 * ((x & 0xFF) << 8 | x >> 8))
#define F_21 ( T_6 ) (x >> 4)
#define F_22 (0x2A504C54)
#define F_23 (0x4E564D2A)
#define F_24 (4 * sizeof(u32))
F_6 ( V_2 -> V_33 -> V_34 , L_11 ) ;
if ( V_2 -> V_33 -> V_35 -> V_58 != V_59 )
V_85 = V_87 ;
else
V_85 = V_88 ;
V_26 = F_25 ( & V_79 , V_2 -> V_89 ,
V_2 -> V_33 -> V_34 ) ;
if ( V_26 ) {
F_7 ( V_2 , L_12 ,
V_2 -> V_89 , V_26 ) ;
return V_26 ;
}
F_26 ( V_2 , L_13 ,
V_2 -> V_89 , V_79 -> V_90 ) ;
if ( V_79 -> V_90 > V_91 ) {
F_7 ( V_2 , L_14 ) ;
V_26 = - V_38 ;
goto V_92;
}
V_83 = V_79 -> V_6 + V_79 -> V_90 ;
V_86 = ( T_5 * ) V_79 -> V_6 ;
if ( V_79 -> V_90 > F_24 &&
V_86 [ 0 ] == F_27 ( F_22 ) &&
V_86 [ 1 ] == F_27 ( F_23 ) ) {
V_82 = ( void * ) ( V_79 -> V_6 + F_24 ) ;
F_26 ( V_2 , L_15 , F_28 ( V_86 [ 2 ] ) ) ;
F_26 ( V_2 , L_16 ,
F_28 ( V_86 [ 3 ] ) ) ;
if ( ( F_29 ( V_2 -> V_33 -> V_93 ) == V_94 &&
F_28 ( V_86 [ 2 ] ) < 0xE4A ) ||
( F_29 ( V_2 -> V_33 -> V_93 ) == V_95 &&
F_28 ( V_86 [ 2 ] ) >= 0xE4A ) ) {
V_26 = - V_96 ;
goto V_92;
}
} else {
V_82 = ( void * ) V_79 -> V_6 ;
}
while ( true ) {
if ( V_82 -> V_6 > V_83 ) {
F_7 ( V_2 ,
L_17 ) ;
V_26 = - V_38 ;
break;
}
if ( ! V_82 -> V_80 && ! V_82 -> V_81 ) {
V_26 = 0 ;
break;
}
if ( V_2 -> V_33 -> V_35 -> V_58 != V_59 ) {
V_76 =
2 * F_18 ( F_5 ( V_82 -> V_80 ) ) ;
V_77 = F_19 ( F_5 ( V_82 -> V_81 ) ) ;
} else {
V_76 = 2 * F_20 (
F_5 ( V_82 -> V_81 ) ) ;
V_77 = F_21 (
F_5 ( V_82 -> V_80 ) ) ;
}
if ( V_76 > V_85 ) {
F_7 ( V_2 , L_18 ,
V_76 ) ;
V_26 = - V_38 ;
break;
}
if ( ! V_76 ) {
F_7 ( V_2 , L_19 ) ;
V_26 = - V_38 ;
break;
}
if ( V_82 -> V_6 + V_76 > V_83 ) {
F_7 ( V_2 ,
L_20 ,
V_76 ) ;
V_26 = - V_38 ;
break;
}
if ( F_30 ( V_77 >= V_97 ,
L_21 , V_77 ) ) {
V_26 = - V_38 ;
break;
}
V_84 = F_31 ( V_82 -> V_6 , V_76 , V_98 ) ;
if ( ! V_84 ) {
V_26 = - V_99 ;
break;
}
F_32 ( V_2 -> V_48 [ V_77 ] . V_6 ) ;
V_2 -> V_48 [ V_77 ] . V_6 = V_84 ;
V_2 -> V_48 [ V_77 ] . V_5 = V_76 ;
V_82 = ( void * ) ( V_82 -> V_6 + V_76 ) ;
}
V_92:
F_33 ( V_79 ) ;
return V_26 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_100 , V_26 = 0 ;
struct V_46 * V_47 = V_2 -> V_48 ;
F_6 ( V_2 -> V_33 -> V_34 , L_22 ) ;
for ( V_100 = 0 ; V_100 < F_35 ( V_2 -> V_48 ) ; V_100 ++ ) {
if ( ! V_2 -> V_48 [ V_100 ] . V_6 || ! V_2 -> V_48 [ V_100 ] . V_5 )
continue;
V_26 = F_9 ( V_2 , V_100 , V_47 [ V_100 ] . V_6 ,
V_47 [ V_100 ] . V_5 ) ;
if ( V_26 < 0 ) {
F_7 ( V_2 , L_23 , V_26 ) ;
break;
}
}
return V_26 ;
}
int F_36 ( struct V_1 * V_2 , bool V_101 )
{
int V_26 , V_3 ;
T_3 V_41 = 0 ;
T_2 * V_102 , * V_84 ;
const char * V_103 = V_2 -> V_35 -> V_104 ;
const char * V_105 = V_2 -> V_35 -> V_106 ;
if ( F_37 ( V_2 -> V_35 -> V_61 >= V_97 ) )
return - V_38 ;
if ( V_101 ) {
F_6 ( V_2 -> V_33 -> V_34 , L_24 ) ;
V_102 = F_38 ( V_2 -> V_35 -> V_42 -> V_43 ,
V_98 ) ;
if ( ! V_102 )
return - V_99 ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_26 = F_11 ( V_2 , V_3 , V_102 ,
V_41 ) ;
if ( V_26 < 0 )
continue;
V_41 += V_26 ;
V_84 = F_31 ( V_102 , V_26 , V_98 ) ;
if ( ! V_84 ) {
V_26 = - V_99 ;
break;
}
V_2 -> V_48 [ V_3 ] . V_6 = V_84 ;
V_2 -> V_48 [ V_3 ] . V_5 = V_26 ;
#ifdef F_39
switch ( V_3 ) {
case V_60 :
V_2 -> V_107 . V_6 = V_84 ;
V_2 -> V_107 . V_90 = V_26 ;
break;
case V_67 :
V_2 -> V_108 . V_6 = V_84 ;
V_2 -> V_108 . V_90 = V_26 ;
break;
case V_109 :
V_2 -> V_110 . V_6 = V_84 ;
V_2 -> V_110 . V_90 = V_26 ;
break;
case V_64 :
V_2 -> V_111 . V_6 = V_84 ;
V_2 -> V_111 . V_90 = V_26 ;
break;
default:
if ( V_3 == V_2 -> V_35 -> V_61 ) {
V_2 -> V_112 . V_6 = V_84 ;
V_2 -> V_112 . V_90 = V_26 ;
break;
}
}
#endif
}
if ( ! V_41 )
F_7 ( V_2 , L_25 ) ;
F_32 ( V_102 ) ;
}
if ( V_2 -> V_89 ) {
V_26 = F_17 ( V_2 ) ;
if ( V_26 ) {
if ( F_29 ( V_2 -> V_33 -> V_93 ) ==
V_95 )
V_2 -> V_89 = V_103 ;
else
V_2 -> V_89 = V_105 ;
if ( V_26 == - V_96 && V_2 -> V_89 ) {
V_26 = F_17 ( V_2 ) ;
if ( V_26 )
return V_26 ;
} else {
return V_26 ;
}
}
}
V_2 -> V_113 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_113 )
return - V_114 ;
F_6 ( V_2 -> V_33 -> V_34 , L_26 ,
V_2 -> V_113 -> V_115 ) ;
return 0 ;
}
struct V_116 *
F_40 ( struct V_1 * V_2 , const char * V_117 ,
enum V_118 V_119 )
{
struct V_120 V_121 = {
. V_122 = F_2 ( V_117 [ 0 ] << 8 | V_117 [ 1 ] ) ,
. V_123 = ( T_2 ) V_119 ,
} ;
struct V_116 * V_124 , * V_125 = NULL ;
struct V_23 * V_24 ;
struct V_11 V_12 = {
. V_13 = V_126 ,
. V_16 = V_25 ,
. V_6 = { & V_121 } ,
} ;
int V_26 ;
T_3 V_31 ;
int V_127 , V_128 ;
T_1 V_122 ;
if ( F_37 ( ! F_41 ( V_2 ) ) )
return F_42 ( - V_129 ) ;
V_12 . V_15 [ 0 ] = sizeof( struct V_120 ) ;
F_43 ( V_2 , L_27 ,
V_117 [ 0 ] , V_117 [ 1 ] , V_119 ) ;
V_26 = F_3 ( V_2 , & V_12 ) ;
if ( V_26 )
return F_42 ( V_26 ) ;
V_24 = V_12 . V_30 ;
V_124 = ( void * ) V_24 -> V_6 ;
V_31 = F_28 ( V_124 -> V_31 ) ;
V_122 = F_5 ( V_124 -> V_122 ) ;
if ( V_122 == 0 ) {
V_122 = 0x3030 ;
V_124 -> V_122 = F_2 ( V_122 ) ;
}
V_128 = F_44 ( V_124 -> V_128 ) ;
F_43 ( V_2 ,
L_28 ,
V_31 , V_122 , V_122 >> 8 , V_122 & 0xff ,
! ! ( V_31 == V_130 ) , V_128 ) ;
V_127 = sizeof( * V_124 ) + V_128 * sizeof( T_5 ) ;
V_125 = F_31 ( V_124 , V_127 , V_98 ) ;
if ( ! V_125 ) {
V_26 = - V_99 ;
goto exit;
}
V_26 = 0 ;
exit:
F_8 ( & V_12 ) ;
if ( V_26 )
return F_42 ( V_26 ) ;
return V_125 ;
}
static T_3 F_45 ( struct V_1 * V_2 , union V_131 * V_132 )
{
union V_131 * V_133 , * V_134 , * V_135 ;
T_3 V_100 ;
if ( V_132 -> type != V_136 ||
V_132 -> V_137 . V_138 < 2 ||
V_132 -> V_137 . V_139 [ 0 ] . type != V_140 ||
V_132 -> V_137 . V_139 [ 0 ] . integer . V_141 != 0 ) {
F_43 ( V_2 , L_29 ) ;
return 0 ;
}
for ( V_100 = 1 ; V_100 < V_132 -> V_137 . V_138 ; ++ V_100 ) {
V_133 = & V_132 -> V_137 . V_139 [ V_100 ] ;
if ( V_133 -> type != V_136 ||
V_133 -> V_137 . V_138 < 2 ||
V_133 -> V_137 . V_139 [ 0 ] . type != V_140 ||
V_133 -> V_137 . V_139 [ 1 ] . type != V_140 ) {
V_133 = NULL ;
continue;
}
V_134 = & V_133 -> V_137 . V_139 [ 0 ] ;
if ( V_134 -> integer . V_141 == V_142 )
break;
V_133 = NULL ;
}
if ( V_133 ) {
V_135 = & V_133 -> V_137 . V_139 [ 1 ] ;
return V_135 -> integer . V_141 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , char * V_122 )
{
T_7 V_143 ;
T_7 V_144 ;
struct V_145 V_132 = { V_146 , NULL } ;
T_8 V_31 ;
T_3 V_147 ;
struct V_148 * V_149 = F_47 ( V_2 -> V_34 ) ;
V_143 = F_48 ( & V_149 -> V_34 ) ;
if ( ! V_143 ) {
F_43 ( V_2 ,
L_30 ) ;
return - V_150 ;
}
V_31 = F_49 ( V_143 , ( V_151 ) V_152 , & V_144 ) ;
if ( F_50 ( V_31 ) ) {
F_43 ( V_2 , L_31 ) ;
return - V_150 ;
}
V_31 = F_51 ( V_144 , NULL , NULL , & V_132 ) ;
if ( F_50 ( V_31 ) ) {
F_43 ( V_2 , L_32 , V_31 ) ;
return - V_150 ;
}
V_147 = F_45 ( V_2 , V_132 . V_153 ) ;
F_32 ( V_132 . V_153 ) ;
if ( ! V_147 )
return - V_150 ;
V_122 [ 0 ] = ( V_147 >> 8 ) & 0xff ;
V_122 [ 1 ] = V_147 & 0xff ;
V_122 [ 2 ] = '\0' ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , char * V_122 )
{
return - V_150 ;
}
int F_52 ( struct V_1 * V_2 )
{
bool V_154 ;
bool V_155 ;
int V_156 ;
struct V_157 * V_158 ;
char V_122 [ 3 ] ;
if ( V_2 -> V_35 -> V_58 == V_59 ) {
V_154 = F_15 ( & V_2 -> V_70 -> V_71 ,
V_72 ) ;
V_155 = V_2 -> V_113 -> V_55 ;
if ( V_154 != V_155 )
F_26 ( V_2 ,
L_33 ,
V_154 ? L_34 : L_35 ,
V_155 ? L_34 : L_35 ) ;
}
if ( ! F_41 ( V_2 ) )
return 0 ;
V_156 = F_53 ( V_2 ) ;
if ( V_156 != - V_150 )
return V_156 ;
V_2 -> V_159 = false ;
V_158 = F_54 ( V_2 , NULL ) ;
if ( F_55 ( V_158 ) )
return - V_37 ;
if ( F_56 ( V_2 ) &&
! F_46 ( V_2 , V_122 ) ) {
F_32 ( V_158 ) ;
V_158 = F_57 ( V_2 -> V_49 -> V_160 , V_122 ,
V_161 , NULL ) ;
if ( F_55 ( V_158 ) )
return - V_37 ;
}
V_156 = F_58 ( V_2 -> V_49 -> V_160 , V_158 ) ;
F_32 ( V_158 ) ;
return V_156 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_23 * V_24 = F_60 ( V_163 ) ;
struct V_164 * V_165 = ( void * ) V_24 -> V_6 ;
enum V_118 V_166 ;
char V_122 [ 3 ] ;
struct V_157 * V_158 ;
F_61 ( & V_2 -> V_167 ) ;
if ( F_37 ( ! F_41 ( V_2 ) ) )
return;
V_122 [ 0 ] = V_165 -> V_122 >> 8 ;
V_122 [ 1 ] = V_165 -> V_122 & 0xff ;
V_122 [ 2 ] = '\0' ;
V_166 = V_165 -> V_123 ;
F_43 ( V_2 ,
L_36 ,
V_122 , V_166 ) ;
V_158 = F_57 ( V_2 -> V_49 -> V_160 , V_122 , V_166 , NULL ) ;
if ( F_55 ( V_158 ) )
return;
F_62 ( V_2 -> V_49 -> V_160 , V_158 ) ;
F_32 ( V_158 ) ;
}
