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
if ( V_24 -> V_31 . V_16 & V_32 ) {
F_5 ( V_2 , L_1 ,
V_24 -> V_31 . V_16 ) ;
V_26 = - V_33 ;
goto exit;
}
V_22 = ( void * ) V_24 -> V_6 ;
V_26 = F_6 ( V_22 -> V_34 ) ;
V_27 = F_6 ( V_22 -> V_5 ) ;
V_28 = F_6 ( V_22 -> V_4 ) ;
V_29 = V_22 -> V_6 ;
if ( V_26 ) {
if ( ( V_4 != 0 ) &&
( V_26 == V_35 ) ) {
F_7 ( V_2 -> V_36 -> V_37 ,
L_2 ,
V_4 ) ;
V_26 = 0 ;
} else {
F_7 ( V_2 -> V_36 -> V_37 ,
L_3 ,
V_26 , V_2 -> V_38 -> V_39 ) ;
V_26 = - V_33 ;
}
goto exit;
}
if ( V_28 != V_4 ) {
F_5 ( V_2 , L_4 ,
V_28 ) ;
V_26 = - V_40 ;
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
int V_41 , V_26 ;
V_41 = F_10 ( V_42 ,
V_5 - V_4 ) ;
V_26 = F_1 ( V_2 , V_3 , V_4 ,
V_41 , V_6 + V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
V_4 += V_41 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_6 , T_3 V_43 )
{
T_1 V_5 , V_4 = 0 ;
int V_26 ;
V_5 = V_42 ;
V_26 = V_5 ;
while ( V_26 == V_5 ) {
if ( ( V_43 + V_4 + V_5 ) >
V_2 -> V_38 -> V_44 -> V_45 ) {
F_5 ( V_2 , L_5 ) ;
return - V_46 ;
}
V_26 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_26 < 0 ) {
F_7 ( V_2 -> V_36 -> V_37 ,
L_6 ,
V_3 , V_4 , V_5 ) ;
return V_26 ;
}
V_4 += V_26 ;
}
F_7 ( V_2 -> V_36 -> V_37 ,
L_7 , V_3 ) ;
return V_4 ;
}
static struct V_47 *
F_12 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
const T_4 * V_51 , * V_52 , * V_53 , * V_54 , * V_55 , * V_56 ;
bool V_57 ;
T_3 V_58 , V_59 ;
if ( V_2 -> V_36 -> V_38 -> V_60 != V_61 ) {
if ( ! V_2 -> V_50 [ V_62 ] . V_6 ||
! V_2 -> V_50 [ V_2 -> V_38 -> V_63 ] . V_6 ) {
F_5 ( V_2 , L_8 ) ;
return NULL ;
}
} else {
if ( ! V_2 -> V_50 [ V_62 ] . V_6 ||
! V_2 -> V_50 [ V_64 ] . V_6 ) {
F_5 ( V_2 ,
L_9 ) ;
return NULL ;
}
if ( ! V_2 -> V_50 [ V_2 -> V_38 -> V_63 ] . V_6 &&
! V_2 -> V_50 [ V_65 ] . V_6 ) {
F_5 ( V_2 ,
L_10 ) ;
return NULL ;
}
if ( ! V_2 -> V_50 [ V_66 ] . V_6 ) {
F_5 ( V_2 ,
L_11 ) ;
return NULL ;
}
}
if ( F_13 ( ! V_2 -> V_38 ) )
return NULL ;
V_58 = F_14 ( V_2 -> V_36 , V_67 ) ;
V_59 = F_14 ( V_2 -> V_36 , V_68 ) ;
V_51 = ( const T_4 * ) V_49 [ V_2 -> V_38 -> V_63 ] . V_6 ;
V_52 = ( const T_4 * ) V_49 [ V_62 ] . V_6 ;
V_53 = ( const T_4 * ) V_49 [ V_69 ] . V_6 ;
V_54 = ( const T_4 * ) V_49 [ V_64 ] . V_6 ;
V_55 =
( const T_4 * ) V_49 [ V_65 ] . V_6 ;
V_56 = ( const T_4 * ) V_49 [ V_66 ] . V_6 ;
V_57 = ! V_70 . V_71 &&
( V_2 -> V_72 -> V_73 . V_74 [ 0 ] &
V_75 ) ;
return F_15 ( V_2 -> V_36 -> V_37 , V_2 -> V_38 , V_51 , V_52 , V_53 ,
V_54 , V_55 , V_56 ,
V_2 -> V_72 -> V_76 , V_2 -> V_72 -> V_77 ,
V_57 , V_58 , V_59 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_26 , V_78 ;
T_1 V_79 ;
const struct V_80 * V_81 ;
const struct {
T_4 V_82 ;
T_4 V_83 ;
T_2 V_6 [] ;
} * V_84 ;
const T_2 * V_85 , * V_86 ;
int V_87 ;
const T_5 * V_88 ;
#define F_17 ( T_6 ) (8 * (x & 0x03FF))
#define F_18 ( T_6 ) (x >> 12)
#define F_19 ( T_6 ) (2 * ((x & 0xFF) << 8 | x >> 8))
#define F_20 ( T_6 ) (x >> 4)
#define F_21 (0x2A504C54)
#define F_22 (0x4E564D2A)
#define F_23 (4 * sizeof(u32))
F_7 ( V_2 -> V_36 -> V_37 , L_12 ) ;
if ( V_2 -> V_36 -> V_38 -> V_60 != V_61 )
V_87 = V_89 ;
else
V_87 = V_90 ;
V_26 = F_24 ( & V_81 , V_2 -> V_91 ,
V_2 -> V_36 -> V_37 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_13 ,
V_2 -> V_91 , V_26 ) ;
return V_26 ;
}
F_25 ( V_2 , L_14 ,
V_2 -> V_91 , V_81 -> V_92 ) ;
if ( V_81 -> V_92 > V_93 ) {
F_5 ( V_2 , L_15 ) ;
V_26 = - V_40 ;
goto V_94;
}
V_85 = V_81 -> V_6 + V_81 -> V_92 ;
V_88 = ( T_5 * ) V_81 -> V_6 ;
if ( V_81 -> V_92 > F_23 &&
V_88 [ 0 ] == F_26 ( F_21 ) &&
V_88 [ 1 ] == F_26 ( F_22 ) ) {
V_84 = ( void * ) ( V_81 -> V_6 + F_23 ) ;
F_25 ( V_2 , L_16 , F_27 ( V_88 [ 2 ] ) ) ;
F_25 ( V_2 , L_17 ,
F_27 ( V_88 [ 3 ] ) ) ;
if ( ( F_28 ( V_2 -> V_36 -> V_95 ) == V_96 &&
F_27 ( V_88 [ 2 ] ) < 0xE4A ) ||
( F_28 ( V_2 -> V_36 -> V_95 ) == V_97 &&
F_27 ( V_88 [ 2 ] ) >= 0xE4A ) ) {
V_26 = - V_98 ;
goto V_94;
}
} else {
V_84 = ( void * ) V_81 -> V_6 ;
}
while ( true ) {
if ( V_84 -> V_6 > V_85 ) {
F_5 ( V_2 ,
L_18 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_84 -> V_82 && ! V_84 -> V_83 ) {
V_26 = 0 ;
break;
}
if ( V_2 -> V_36 -> V_38 -> V_60 != V_61 ) {
V_78 =
2 * F_17 ( F_6 ( V_84 -> V_82 ) ) ;
V_79 = F_18 ( F_6 ( V_84 -> V_83 ) ) ;
} else {
V_78 = 2 * F_19 (
F_6 ( V_84 -> V_83 ) ) ;
V_79 = F_20 (
F_6 ( V_84 -> V_82 ) ) ;
}
if ( V_78 > V_87 ) {
F_5 ( V_2 , L_19 ,
V_78 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_78 ) {
F_5 ( V_2 , L_20 ) ;
V_26 = - V_40 ;
break;
}
if ( V_84 -> V_6 + V_78 > V_85 ) {
F_5 ( V_2 ,
L_21 ,
V_78 ) ;
V_26 = - V_40 ;
break;
}
if ( F_29 ( V_79 >= V_99 ,
L_22 , V_79 ) ) {
V_26 = - V_40 ;
break;
}
V_86 = F_30 ( V_84 -> V_6 , V_78 , V_100 ) ;
if ( ! V_86 ) {
V_26 = - V_101 ;
break;
}
V_2 -> V_50 [ V_79 ] . V_6 = V_86 ;
V_2 -> V_50 [ V_79 ] . V_5 = V_78 ;
V_84 = ( void * ) ( V_84 -> V_6 + V_78 ) ;
}
V_94:
F_31 ( V_81 ) ;
return V_26 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_102 , V_26 = 0 ;
struct V_48 * V_49 = V_2 -> V_50 ;
F_7 ( V_2 -> V_36 -> V_37 , L_23 ) ;
for ( V_102 = 0 ; V_102 < F_33 ( V_2 -> V_50 ) ; V_102 ++ ) {
if ( ! V_2 -> V_50 [ V_102 ] . V_6 || ! V_2 -> V_50 [ V_102 ] . V_5 )
continue;
V_26 = F_9 ( V_2 , V_102 , V_49 [ V_102 ] . V_6 ,
V_49 [ V_102 ] . V_5 ) ;
if ( V_26 < 0 ) {
F_5 ( V_2 , L_24 , V_26 ) ;
break;
}
}
return V_26 ;
}
int F_34 ( struct V_1 * V_2 , bool V_103 )
{
int V_26 , V_3 ;
T_3 V_43 = 0 ;
T_2 * V_104 , * V_86 ;
const char * V_105 = V_2 -> V_38 -> V_106 ;
const char * V_107 = V_2 -> V_38 -> V_108 ;
if ( F_35 ( V_2 -> V_38 -> V_63 >= V_99 ) )
return - V_40 ;
if ( V_103 ) {
F_7 ( V_2 -> V_36 -> V_37 , L_25 ) ;
V_104 = F_36 ( V_2 -> V_38 -> V_44 -> V_45 ,
V_100 ) ;
if ( ! V_104 )
return - V_101 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
V_26 = F_11 ( V_2 , V_3 , V_104 ,
V_43 ) ;
if ( V_26 < 0 )
continue;
V_43 += V_26 ;
V_86 = F_30 ( V_104 , V_26 , V_100 ) ;
if ( ! V_86 ) {
V_26 = - V_101 ;
break;
}
V_2 -> V_50 [ V_3 ] . V_6 = V_86 ;
V_2 -> V_50 [ V_3 ] . V_5 = V_26 ;
#ifdef F_37
switch ( V_3 ) {
case V_62 :
V_2 -> V_109 . V_6 = V_86 ;
V_2 -> V_109 . V_92 = V_26 ;
break;
case V_69 :
V_2 -> V_110 . V_6 = V_86 ;
V_2 -> V_110 . V_92 = V_26 ;
break;
case V_111 :
V_2 -> V_112 . V_6 = V_86 ;
V_2 -> V_112 . V_92 = V_26 ;
break;
default:
if ( V_3 == V_2 -> V_38 -> V_63 ) {
V_2 -> V_113 . V_6 = V_86 ;
V_2 -> V_113 . V_92 = V_26 ;
break;
}
}
#endif
}
if ( ! V_43 )
F_5 ( V_2 , L_26 ) ;
F_38 ( V_104 ) ;
}
if ( V_2 -> V_91 ) {
V_26 = F_16 ( V_2 ) ;
if ( V_26 ) {
if ( F_28 ( V_2 -> V_36 -> V_95 ) ==
V_97 )
V_2 -> V_91 = V_105 ;
else
V_2 -> V_91 = V_107 ;
if ( V_26 == - V_98 && V_2 -> V_91 ) {
V_26 = F_16 ( V_2 ) ;
if ( V_26 )
return V_26 ;
} else {
return V_26 ;
}
}
}
V_2 -> V_114 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_114 )
return - V_115 ;
F_7 ( V_2 -> V_36 -> V_37 , L_27 ,
V_2 -> V_114 -> V_116 ) ;
return 0 ;
}
struct V_117 *
F_39 ( struct V_1 * V_2 , const char * V_118 ,
enum V_119 V_120 )
{
struct V_121 V_122 = {
. V_123 = F_2 ( V_118 [ 0 ] << 8 | V_118 [ 1 ] ) ,
. V_124 = ( T_2 ) V_120 ,
} ;
struct V_117 * V_125 , * V_126 = NULL ;
struct V_23 * V_24 ;
struct V_11 V_12 = {
. V_13 = V_127 ,
. V_16 = V_25 ,
. V_6 = { & V_122 } ,
} ;
int V_26 ;
T_3 V_34 ;
int V_128 , V_129 ;
T_1 V_123 ;
if ( F_35 ( ! F_40 ( V_2 ) ) )
return F_41 ( - V_130 ) ;
V_12 . V_15 [ 0 ] = sizeof( struct V_121 ) ;
F_42 ( V_2 , L_28 ,
V_118 [ 0 ] , V_118 [ 1 ] , V_120 ) ;
V_26 = F_3 ( V_2 , & V_12 ) ;
if ( V_26 )
return F_41 ( V_26 ) ;
V_24 = V_12 . V_30 ;
if ( V_24 -> V_31 . V_16 & V_32 ) {
F_5 ( V_2 , L_29 ,
V_24 -> V_31 . V_16 ) ;
V_26 = - V_33 ;
goto exit;
}
V_125 = ( void * ) V_24 -> V_6 ;
V_34 = F_27 ( V_125 -> V_34 ) ;
V_123 = F_6 ( V_125 -> V_123 ) ;
if ( V_123 == 0 ) {
V_123 = 0x3030 ;
V_125 -> V_123 = F_2 ( V_123 ) ;
}
V_129 = F_43 ( V_125 -> V_129 ) ;
F_42 ( V_2 ,
L_30 ,
V_34 , V_123 , V_123 >> 8 , V_123 & 0xff ,
! ! ( V_34 == V_131 ) , V_129 ) ;
V_128 = sizeof( * V_125 ) + V_129 * sizeof( T_5 ) ;
V_126 = F_30 ( V_125 , V_128 , V_100 ) ;
if ( ! V_126 ) {
V_26 = - V_101 ;
goto exit;
}
V_26 = 0 ;
exit:
F_8 ( & V_12 ) ;
if ( V_26 )
return F_41 ( V_26 ) ;
return V_126 ;
}
static T_3 F_44 ( struct V_1 * V_2 , union V_132 * V_133 )
{
union V_132 * V_134 , * V_135 , * V_136 ;
T_3 V_102 ;
if ( V_133 -> type != V_137 ||
V_133 -> V_138 . V_139 < 2 ||
V_133 -> V_138 . V_140 [ 0 ] . type != V_141 ||
V_133 -> V_138 . V_140 [ 0 ] . integer . V_142 != 0 ) {
F_42 ( V_2 , L_31 ) ;
return 0 ;
}
for ( V_102 = 1 ; V_102 < V_133 -> V_138 . V_139 ; ++ V_102 ) {
V_134 = & V_133 -> V_138 . V_140 [ V_102 ] ;
if ( V_134 -> type != V_137 ||
V_134 -> V_138 . V_139 < 2 ||
V_134 -> V_138 . V_140 [ 0 ] . type != V_141 ||
V_134 -> V_138 . V_140 [ 1 ] . type != V_141 ) {
V_134 = NULL ;
continue;
}
V_135 = & V_134 -> V_138 . V_140 [ 0 ] ;
if ( V_135 -> integer . V_142 == V_143 )
break;
V_134 = NULL ;
}
if ( V_134 ) {
V_136 = & V_134 -> V_138 . V_140 [ 1 ] ;
return V_136 -> integer . V_142 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , char * V_123 )
{
T_7 V_144 ;
T_7 V_145 ;
struct V_146 V_133 = { V_147 , NULL } ;
T_8 V_34 ;
T_3 V_148 ;
struct V_149 * V_150 = F_46 ( V_2 -> V_37 ) ;
V_144 = F_47 ( & V_150 -> V_37 ) ;
if ( ! V_144 ) {
F_42 ( V_2 ,
L_32 ) ;
return - V_151 ;
}
V_34 = F_48 ( V_144 , ( V_152 ) V_153 , & V_145 ) ;
if ( F_49 ( V_34 ) ) {
F_42 ( V_2 , L_33 ) ;
return - V_151 ;
}
V_34 = F_50 ( V_145 , NULL , NULL , & V_133 ) ;
if ( F_49 ( V_34 ) ) {
F_42 ( V_2 , L_34 , V_34 ) ;
return - V_151 ;
}
V_148 = F_44 ( V_2 , V_133 . V_154 ) ;
F_38 ( V_133 . V_154 ) ;
if ( ! V_148 )
return - V_151 ;
V_123 [ 0 ] = ( V_148 >> 8 ) & 0xff ;
V_123 [ 1 ] = V_148 & 0xff ;
V_123 [ 2 ] = '\0' ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , char * V_123 )
{
return - V_151 ;
}
int F_51 ( struct V_1 * V_2 )
{
bool V_155 ;
bool V_156 ;
int V_157 ;
struct V_158 * V_159 ;
char V_123 [ 3 ] ;
if ( V_2 -> V_38 -> V_60 == V_61 ) {
V_155 = V_2 -> V_72 -> V_73 . V_74 [ 0 ] &
V_75 ;
V_156 = V_2 -> V_114 -> V_57 ;
if ( V_155 != V_156 )
F_25 ( V_2 ,
L_35 ,
V_155 ? L_36 : L_37 ,
V_156 ? L_36 : L_37 ) ;
}
if ( ! F_40 ( V_2 ) )
return 0 ;
V_157 = F_52 ( V_2 ) ;
if ( V_157 != - V_151 )
return V_157 ;
V_2 -> V_160 = false ;
V_159 = F_53 ( V_2 , NULL ) ;
if ( F_54 ( V_159 ) )
return - V_33 ;
if ( F_55 ( V_2 ) &&
! F_45 ( V_2 , V_123 ) ) {
F_38 ( V_159 ) ;
V_159 = F_56 ( V_2 -> V_51 -> V_161 , V_123 ,
V_162 , NULL ) ;
if ( F_54 ( V_159 ) )
return - V_33 ;
}
V_157 = F_57 ( V_2 -> V_51 -> V_161 , V_159 ) ;
F_38 ( V_159 ) ;
return V_157 ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_163 * V_164 ,
struct V_165 * V_12 )
{
struct V_23 * V_24 = F_59 ( V_164 ) ;
struct V_166 * V_167 = ( void * ) V_24 -> V_6 ;
enum V_119 V_168 ;
char V_123 [ 3 ] ;
struct V_158 * V_159 ;
F_60 ( & V_2 -> V_169 ) ;
if ( F_35 ( ! F_40 ( V_2 ) ) )
return 0 ;
V_123 [ 0 ] = V_167 -> V_123 >> 8 ;
V_123 [ 1 ] = V_167 -> V_123 & 0xff ;
V_123 [ 2 ] = '\0' ;
V_168 = V_167 -> V_124 ;
F_42 ( V_2 ,
L_38 ,
V_123 , V_168 ) ;
V_159 = F_56 ( V_2 -> V_51 -> V_161 , V_123 , V_168 , NULL ) ;
if ( F_54 ( V_159 ) )
return 0 ;
F_61 ( V_2 -> V_51 -> V_161 , V_159 ) ;
F_38 ( V_159 ) ;
return 0 ;
}
