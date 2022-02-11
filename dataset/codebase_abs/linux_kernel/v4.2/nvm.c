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
F_15 ( & V_2 -> V_72 -> V_73 ,
V_74 ) ;
return F_16 ( V_2 -> V_36 -> V_37 , V_2 -> V_38 , V_51 , V_52 , V_53 ,
V_54 , V_55 , V_56 ,
V_2 -> V_72 -> V_75 , V_2 -> V_72 -> V_76 ,
V_57 , V_58 , V_59 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_26 , V_77 ;
T_1 V_78 ;
const struct V_79 * V_80 ;
const struct {
T_4 V_81 ;
T_4 V_82 ;
T_2 V_6 [] ;
} * V_83 ;
const T_2 * V_84 , * V_85 ;
int V_86 ;
const T_5 * V_87 ;
#define F_18 ( T_6 ) (8 * (x & 0x03FF))
#define F_19 ( T_6 ) (x >> 12)
#define F_20 ( T_6 ) (2 * ((x & 0xFF) << 8 | x >> 8))
#define F_21 ( T_6 ) (x >> 4)
#define F_22 (0x2A504C54)
#define F_23 (0x4E564D2A)
#define F_24 (4 * sizeof(u32))
F_7 ( V_2 -> V_36 -> V_37 , L_12 ) ;
if ( V_2 -> V_36 -> V_38 -> V_60 != V_61 )
V_86 = V_88 ;
else
V_86 = V_89 ;
V_26 = F_25 ( & V_80 , V_2 -> V_90 ,
V_2 -> V_36 -> V_37 ) ;
if ( V_26 ) {
F_5 ( V_2 , L_13 ,
V_2 -> V_90 , V_26 ) ;
return V_26 ;
}
F_26 ( V_2 , L_14 ,
V_2 -> V_90 , V_80 -> V_91 ) ;
if ( V_80 -> V_91 > V_92 ) {
F_5 ( V_2 , L_15 ) ;
V_26 = - V_40 ;
goto V_93;
}
V_84 = V_80 -> V_6 + V_80 -> V_91 ;
V_87 = ( T_5 * ) V_80 -> V_6 ;
if ( V_80 -> V_91 > F_24 &&
V_87 [ 0 ] == F_27 ( F_22 ) &&
V_87 [ 1 ] == F_27 ( F_23 ) ) {
V_83 = ( void * ) ( V_80 -> V_6 + F_24 ) ;
F_26 ( V_2 , L_16 , F_28 ( V_87 [ 2 ] ) ) ;
F_26 ( V_2 , L_17 ,
F_28 ( V_87 [ 3 ] ) ) ;
if ( ( F_29 ( V_2 -> V_36 -> V_94 ) == V_95 &&
F_28 ( V_87 [ 2 ] ) < 0xE4A ) ||
( F_29 ( V_2 -> V_36 -> V_94 ) == V_96 &&
F_28 ( V_87 [ 2 ] ) >= 0xE4A ) ) {
V_26 = - V_97 ;
goto V_93;
}
} else {
V_83 = ( void * ) V_80 -> V_6 ;
}
while ( true ) {
if ( V_83 -> V_6 > V_84 ) {
F_5 ( V_2 ,
L_18 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_83 -> V_81 && ! V_83 -> V_82 ) {
V_26 = 0 ;
break;
}
if ( V_2 -> V_36 -> V_38 -> V_60 != V_61 ) {
V_77 =
2 * F_18 ( F_6 ( V_83 -> V_81 ) ) ;
V_78 = F_19 ( F_6 ( V_83 -> V_82 ) ) ;
} else {
V_77 = 2 * F_20 (
F_6 ( V_83 -> V_82 ) ) ;
V_78 = F_21 (
F_6 ( V_83 -> V_81 ) ) ;
}
if ( V_77 > V_86 ) {
F_5 ( V_2 , L_19 ,
V_77 ) ;
V_26 = - V_40 ;
break;
}
if ( ! V_77 ) {
F_5 ( V_2 , L_20 ) ;
V_26 = - V_40 ;
break;
}
if ( V_83 -> V_6 + V_77 > V_84 ) {
F_5 ( V_2 ,
L_21 ,
V_77 ) ;
V_26 = - V_40 ;
break;
}
if ( F_30 ( V_78 >= V_98 ,
L_22 , V_78 ) ) {
V_26 = - V_40 ;
break;
}
V_85 = F_31 ( V_83 -> V_6 , V_77 , V_99 ) ;
if ( ! V_85 ) {
V_26 = - V_100 ;
break;
}
V_2 -> V_50 [ V_78 ] . V_6 = V_85 ;
V_2 -> V_50 [ V_78 ] . V_5 = V_77 ;
V_83 = ( void * ) ( V_83 -> V_6 + V_77 ) ;
}
V_93:
F_32 ( V_80 ) ;
return V_26 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_101 , V_26 = 0 ;
struct V_48 * V_49 = V_2 -> V_50 ;
F_7 ( V_2 -> V_36 -> V_37 , L_23 ) ;
for ( V_101 = 0 ; V_101 < F_34 ( V_2 -> V_50 ) ; V_101 ++ ) {
if ( ! V_2 -> V_50 [ V_101 ] . V_6 || ! V_2 -> V_50 [ V_101 ] . V_5 )
continue;
V_26 = F_9 ( V_2 , V_101 , V_49 [ V_101 ] . V_6 ,
V_49 [ V_101 ] . V_5 ) ;
if ( V_26 < 0 ) {
F_5 ( V_2 , L_24 , V_26 ) ;
break;
}
}
return V_26 ;
}
int F_35 ( struct V_1 * V_2 , bool V_102 )
{
int V_26 , V_3 ;
T_3 V_43 = 0 ;
T_2 * V_103 , * V_85 ;
const char * V_104 = V_2 -> V_38 -> V_105 ;
const char * V_106 = V_2 -> V_38 -> V_107 ;
if ( F_36 ( V_2 -> V_38 -> V_63 >= V_98 ) )
return - V_40 ;
if ( V_102 ) {
F_7 ( V_2 -> V_36 -> V_37 , L_25 ) ;
V_103 = F_37 ( V_2 -> V_38 -> V_44 -> V_45 ,
V_99 ) ;
if ( ! V_103 )
return - V_100 ;
for ( V_3 = 0 ; V_3 < V_98 ; V_3 ++ ) {
V_26 = F_11 ( V_2 , V_3 , V_103 ,
V_43 ) ;
if ( V_26 < 0 )
continue;
V_43 += V_26 ;
V_85 = F_31 ( V_103 , V_26 , V_99 ) ;
if ( ! V_85 ) {
V_26 = - V_100 ;
break;
}
V_2 -> V_50 [ V_3 ] . V_6 = V_85 ;
V_2 -> V_50 [ V_3 ] . V_5 = V_26 ;
#ifdef F_38
switch ( V_3 ) {
case V_62 :
V_2 -> V_108 . V_6 = V_85 ;
V_2 -> V_108 . V_91 = V_26 ;
break;
case V_69 :
V_2 -> V_109 . V_6 = V_85 ;
V_2 -> V_109 . V_91 = V_26 ;
break;
case V_110 :
V_2 -> V_111 . V_6 = V_85 ;
V_2 -> V_111 . V_91 = V_26 ;
break;
default:
if ( V_3 == V_2 -> V_38 -> V_63 ) {
V_2 -> V_112 . V_6 = V_85 ;
V_2 -> V_112 . V_91 = V_26 ;
break;
}
}
#endif
}
if ( ! V_43 )
F_5 ( V_2 , L_26 ) ;
F_39 ( V_103 ) ;
}
if ( V_2 -> V_90 ) {
V_26 = F_17 ( V_2 ) ;
if ( V_26 ) {
if ( F_29 ( V_2 -> V_36 -> V_94 ) ==
V_96 )
V_2 -> V_90 = V_104 ;
else
V_2 -> V_90 = V_106 ;
if ( V_26 == - V_97 && V_2 -> V_90 ) {
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
F_7 ( V_2 -> V_36 -> V_37 , L_27 ,
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
T_3 V_34 ;
int V_127 , V_128 ;
T_1 V_122 ;
if ( F_36 ( ! F_41 ( V_2 ) ) )
return F_42 ( - V_129 ) ;
V_12 . V_15 [ 0 ] = sizeof( struct V_120 ) ;
F_43 ( V_2 , L_28 ,
V_117 [ 0 ] , V_117 [ 1 ] , V_119 ) ;
V_26 = F_3 ( V_2 , & V_12 ) ;
if ( V_26 )
return F_42 ( V_26 ) ;
V_24 = V_12 . V_30 ;
if ( V_24 -> V_31 . V_16 & V_32 ) {
F_5 ( V_2 , L_29 ,
V_24 -> V_31 . V_16 ) ;
V_26 = - V_33 ;
goto exit;
}
V_124 = ( void * ) V_24 -> V_6 ;
V_34 = F_28 ( V_124 -> V_34 ) ;
V_122 = F_6 ( V_124 -> V_122 ) ;
if ( V_122 == 0 ) {
V_122 = 0x3030 ;
V_124 -> V_122 = F_2 ( V_122 ) ;
}
V_128 = F_44 ( V_124 -> V_128 ) ;
F_43 ( V_2 ,
L_30 ,
V_34 , V_122 , V_122 >> 8 , V_122 & 0xff ,
! ! ( V_34 == V_130 ) , V_128 ) ;
V_127 = sizeof( * V_124 ) + V_128 * sizeof( T_5 ) ;
V_125 = F_31 ( V_124 , V_127 , V_99 ) ;
if ( ! V_125 ) {
V_26 = - V_100 ;
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
T_3 V_101 ;
if ( V_132 -> type != V_136 ||
V_132 -> V_137 . V_138 < 2 ||
V_132 -> V_137 . V_139 [ 0 ] . type != V_140 ||
V_132 -> V_137 . V_139 [ 0 ] . integer . V_141 != 0 ) {
F_43 ( V_2 , L_31 ) ;
return 0 ;
}
for ( V_101 = 1 ; V_101 < V_132 -> V_137 . V_138 ; ++ V_101 ) {
V_133 = & V_132 -> V_137 . V_139 [ V_101 ] ;
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
T_8 V_34 ;
T_3 V_147 ;
struct V_148 * V_149 = F_47 ( V_2 -> V_37 ) ;
V_143 = F_48 ( & V_149 -> V_37 ) ;
if ( ! V_143 ) {
F_43 ( V_2 ,
L_32 ) ;
return - V_150 ;
}
V_34 = F_49 ( V_143 , ( V_151 ) V_152 , & V_144 ) ;
if ( F_50 ( V_34 ) ) {
F_43 ( V_2 , L_33 ) ;
return - V_150 ;
}
V_34 = F_51 ( V_144 , NULL , NULL , & V_132 ) ;
if ( F_50 ( V_34 ) ) {
F_43 ( V_2 , L_34 , V_34 ) ;
return - V_150 ;
}
V_147 = F_45 ( V_2 , V_132 . V_153 ) ;
F_39 ( V_132 . V_153 ) ;
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
if ( V_2 -> V_38 -> V_60 == V_61 ) {
V_154 = F_15 ( & V_2 -> V_72 -> V_73 ,
V_74 ) ;
V_155 = V_2 -> V_113 -> V_57 ;
if ( V_154 != V_155 )
F_26 ( V_2 ,
L_35 ,
V_154 ? L_36 : L_37 ,
V_155 ? L_36 : L_37 ) ;
}
if ( ! F_41 ( V_2 ) )
return 0 ;
V_156 = F_53 ( V_2 ) ;
if ( V_156 != - V_150 )
return V_156 ;
V_2 -> V_159 = false ;
V_158 = F_54 ( V_2 , NULL ) ;
if ( F_55 ( V_158 ) )
return - V_33 ;
if ( F_56 ( V_2 ) &&
! F_46 ( V_2 , V_122 ) ) {
F_39 ( V_158 ) ;
V_158 = F_57 ( V_2 -> V_51 -> V_160 , V_122 ,
V_161 , NULL ) ;
if ( F_55 ( V_158 ) )
return - V_33 ;
}
V_156 = F_58 ( V_2 -> V_51 -> V_160 , V_158 ) ;
F_39 ( V_158 ) ;
return V_156 ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_162 * V_163 ,
struct V_164 * V_12 )
{
struct V_23 * V_24 = F_60 ( V_163 ) ;
struct V_165 * V_166 = ( void * ) V_24 -> V_6 ;
enum V_118 V_167 ;
char V_122 [ 3 ] ;
struct V_157 * V_158 ;
F_61 ( & V_2 -> V_168 ) ;
if ( F_36 ( ! F_41 ( V_2 ) ) )
return 0 ;
V_122 [ 0 ] = V_166 -> V_122 >> 8 ;
V_122 [ 1 ] = V_166 -> V_122 & 0xff ;
V_122 [ 2 ] = '\0' ;
V_167 = V_166 -> V_123 ;
F_43 ( V_2 ,
L_38 ,
V_122 , V_167 ) ;
V_158 = F_57 ( V_2 -> V_51 -> V_160 , V_122 , V_167 , NULL ) ;
if ( F_55 ( V_158 ) )
return 0 ;
F_62 ( V_2 -> V_51 -> V_160 , V_158 ) ;
F_39 ( V_158 ) ;
return 0 ;
}
