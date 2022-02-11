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
V_55 , V_56 , V_57 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_26 , V_75 ;
T_1 V_76 ;
const struct V_77 * V_78 ;
const struct {
T_4 V_79 ;
T_4 V_80 ;
T_2 V_6 [] ;
} * V_81 ;
const T_2 * V_82 , * V_83 ;
int V_84 ;
const T_5 * V_85 ;
#define F_18 ( T_6 ) (8 * (x & 0x03FF))
#define F_19 ( T_6 ) (x >> 12)
#define F_20 ( T_6 ) (2 * ((x & 0xFF) << 8 | x >> 8))
#define F_21 ( T_6 ) (x >> 4)
#define F_22 (0x2A504C54)
#define F_23 (0x4E564D2A)
#define F_24 (4 * sizeof(u32))
F_6 ( V_2 -> V_33 -> V_34 , L_11 ) ;
if ( V_2 -> V_33 -> V_35 -> V_58 != V_59 )
V_84 = V_86 ;
else
V_84 = V_87 ;
V_26 = F_25 ( & V_78 , V_2 -> V_88 ,
V_2 -> V_33 -> V_34 ) ;
if ( V_26 ) {
F_7 ( V_2 , L_12 ,
V_2 -> V_88 , V_26 ) ;
return V_26 ;
}
F_26 ( V_2 , L_13 ,
V_2 -> V_88 , V_78 -> V_89 ) ;
if ( V_78 -> V_89 > V_90 ) {
F_7 ( V_2 , L_14 ) ;
V_26 = - V_38 ;
goto V_91;
}
V_82 = V_78 -> V_6 + V_78 -> V_89 ;
V_85 = ( T_5 * ) V_78 -> V_6 ;
if ( V_78 -> V_89 > F_24 &&
V_85 [ 0 ] == F_27 ( F_22 ) &&
V_85 [ 1 ] == F_27 ( F_23 ) ) {
V_81 = ( void * ) ( V_78 -> V_6 + F_24 ) ;
F_26 ( V_2 , L_15 , F_28 ( V_85 [ 2 ] ) ) ;
F_26 ( V_2 , L_16 ,
F_28 ( V_85 [ 3 ] ) ) ;
if ( ( F_29 ( V_2 -> V_33 -> V_92 ) == V_93 &&
F_28 ( V_85 [ 2 ] ) < 0xE4A ) ||
( F_29 ( V_2 -> V_33 -> V_92 ) == V_94 &&
F_28 ( V_85 [ 2 ] ) >= 0xE4A ) ) {
V_26 = - V_95 ;
goto V_91;
}
} else {
V_81 = ( void * ) V_78 -> V_6 ;
}
while ( true ) {
if ( V_81 -> V_6 > V_82 ) {
F_7 ( V_2 ,
L_17 ) ;
V_26 = - V_38 ;
break;
}
if ( ! V_81 -> V_79 && ! V_81 -> V_80 ) {
V_26 = 0 ;
break;
}
if ( V_2 -> V_33 -> V_35 -> V_58 != V_59 ) {
V_75 =
2 * F_18 ( F_5 ( V_81 -> V_79 ) ) ;
V_76 = F_19 ( F_5 ( V_81 -> V_80 ) ) ;
} else {
V_75 = 2 * F_20 (
F_5 ( V_81 -> V_80 ) ) ;
V_76 = F_21 (
F_5 ( V_81 -> V_79 ) ) ;
}
if ( V_75 > V_84 ) {
F_7 ( V_2 , L_18 ,
V_75 ) ;
V_26 = - V_38 ;
break;
}
if ( ! V_75 ) {
F_7 ( V_2 , L_19 ) ;
V_26 = - V_38 ;
break;
}
if ( V_81 -> V_6 + V_75 > V_82 ) {
F_7 ( V_2 ,
L_20 ,
V_75 ) ;
V_26 = - V_38 ;
break;
}
if ( F_30 ( V_76 >= V_96 ,
L_21 , V_76 ) ) {
V_26 = - V_38 ;
break;
}
V_83 = F_31 ( V_81 -> V_6 , V_75 , V_97 ) ;
if ( ! V_83 ) {
V_26 = - V_98 ;
break;
}
V_2 -> V_48 [ V_76 ] . V_6 = V_83 ;
V_2 -> V_48 [ V_76 ] . V_5 = V_75 ;
V_81 = ( void * ) ( V_81 -> V_6 + V_75 ) ;
}
V_91:
F_32 ( V_78 ) ;
return V_26 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_99 , V_26 = 0 ;
struct V_46 * V_47 = V_2 -> V_48 ;
F_6 ( V_2 -> V_33 -> V_34 , L_22 ) ;
for ( V_99 = 0 ; V_99 < F_34 ( V_2 -> V_48 ) ; V_99 ++ ) {
if ( ! V_2 -> V_48 [ V_99 ] . V_6 || ! V_2 -> V_48 [ V_99 ] . V_5 )
continue;
V_26 = F_9 ( V_2 , V_99 , V_47 [ V_99 ] . V_6 ,
V_47 [ V_99 ] . V_5 ) ;
if ( V_26 < 0 ) {
F_7 ( V_2 , L_23 , V_26 ) ;
break;
}
}
return V_26 ;
}
int F_35 ( struct V_1 * V_2 , bool V_100 )
{
int V_26 , V_3 ;
T_3 V_41 = 0 ;
T_2 * V_101 , * V_83 ;
const char * V_102 = V_2 -> V_35 -> V_103 ;
const char * V_104 = V_2 -> V_35 -> V_105 ;
if ( F_36 ( V_2 -> V_35 -> V_61 >= V_96 ) )
return - V_38 ;
if ( V_100 ) {
F_6 ( V_2 -> V_33 -> V_34 , L_24 ) ;
V_101 = F_37 ( V_2 -> V_35 -> V_42 -> V_43 ,
V_97 ) ;
if ( ! V_101 )
return - V_98 ;
for ( V_3 = 0 ; V_3 < V_96 ; V_3 ++ ) {
V_26 = F_11 ( V_2 , V_3 , V_101 ,
V_41 ) ;
if ( V_26 < 0 )
continue;
V_41 += V_26 ;
V_83 = F_31 ( V_101 , V_26 , V_97 ) ;
if ( ! V_83 ) {
V_26 = - V_98 ;
break;
}
V_2 -> V_48 [ V_3 ] . V_6 = V_83 ;
V_2 -> V_48 [ V_3 ] . V_5 = V_26 ;
#ifdef F_38
switch ( V_3 ) {
case V_60 :
V_2 -> V_106 . V_6 = V_83 ;
V_2 -> V_106 . V_89 = V_26 ;
break;
case V_67 :
V_2 -> V_107 . V_6 = V_83 ;
V_2 -> V_107 . V_89 = V_26 ;
break;
case V_108 :
V_2 -> V_109 . V_6 = V_83 ;
V_2 -> V_109 . V_89 = V_26 ;
break;
default:
if ( V_3 == V_2 -> V_35 -> V_61 ) {
V_2 -> V_110 . V_6 = V_83 ;
V_2 -> V_110 . V_89 = V_26 ;
break;
}
}
#endif
}
if ( ! V_41 )
F_7 ( V_2 , L_25 ) ;
F_39 ( V_101 ) ;
}
if ( V_2 -> V_88 ) {
V_26 = F_17 ( V_2 ) ;
if ( V_26 ) {
if ( F_29 ( V_2 -> V_33 -> V_92 ) ==
V_94 )
V_2 -> V_88 = V_102 ;
else
V_2 -> V_88 = V_104 ;
if ( V_26 == - V_95 && V_2 -> V_88 ) {
V_26 = F_17 ( V_2 ) ;
if ( V_26 )
return V_26 ;
} else {
return V_26 ;
}
}
}
V_2 -> V_111 = F_12 ( V_2 ) ;
if ( ! V_2 -> V_111 )
return - V_112 ;
F_6 ( V_2 -> V_33 -> V_34 , L_26 ,
V_2 -> V_111 -> V_113 ) ;
return 0 ;
}
struct V_114 *
F_40 ( struct V_1 * V_2 , const char * V_115 ,
enum V_116 V_117 )
{
struct V_118 V_119 = {
. V_120 = F_2 ( V_115 [ 0 ] << 8 | V_115 [ 1 ] ) ,
. V_121 = ( T_2 ) V_117 ,
} ;
struct V_114 * V_122 , * V_123 = NULL ;
struct V_23 * V_24 ;
struct V_11 V_12 = {
. V_13 = V_124 ,
. V_16 = V_25 ,
. V_6 = { & V_119 } ,
} ;
int V_26 ;
T_3 V_31 ;
int V_125 , V_126 ;
T_1 V_120 ;
if ( F_36 ( ! F_41 ( V_2 ) ) )
return F_42 ( - V_127 ) ;
V_12 . V_15 [ 0 ] = sizeof( struct V_118 ) ;
F_43 ( V_2 , L_27 ,
V_115 [ 0 ] , V_115 [ 1 ] , V_117 ) ;
V_26 = F_3 ( V_2 , & V_12 ) ;
if ( V_26 )
return F_42 ( V_26 ) ;
V_24 = V_12 . V_30 ;
V_122 = ( void * ) V_24 -> V_6 ;
V_31 = F_28 ( V_122 -> V_31 ) ;
V_120 = F_5 ( V_122 -> V_120 ) ;
if ( V_120 == 0 ) {
V_120 = 0x3030 ;
V_122 -> V_120 = F_2 ( V_120 ) ;
}
V_126 = F_44 ( V_122 -> V_126 ) ;
F_43 ( V_2 ,
L_28 ,
V_31 , V_120 , V_120 >> 8 , V_120 & 0xff ,
! ! ( V_31 == V_128 ) , V_126 ) ;
V_125 = sizeof( * V_122 ) + V_126 * sizeof( T_5 ) ;
V_123 = F_31 ( V_122 , V_125 , V_97 ) ;
if ( ! V_123 ) {
V_26 = - V_98 ;
goto exit;
}
V_26 = 0 ;
exit:
F_8 ( & V_12 ) ;
if ( V_26 )
return F_42 ( V_26 ) ;
return V_123 ;
}
static T_3 F_45 ( struct V_1 * V_2 , union V_129 * V_130 )
{
union V_129 * V_131 , * V_132 , * V_133 ;
T_3 V_99 ;
if ( V_130 -> type != V_134 ||
V_130 -> V_135 . V_136 < 2 ||
V_130 -> V_135 . V_137 [ 0 ] . type != V_138 ||
V_130 -> V_135 . V_137 [ 0 ] . integer . V_139 != 0 ) {
F_43 ( V_2 , L_29 ) ;
return 0 ;
}
for ( V_99 = 1 ; V_99 < V_130 -> V_135 . V_136 ; ++ V_99 ) {
V_131 = & V_130 -> V_135 . V_137 [ V_99 ] ;
if ( V_131 -> type != V_134 ||
V_131 -> V_135 . V_136 < 2 ||
V_131 -> V_135 . V_137 [ 0 ] . type != V_138 ||
V_131 -> V_135 . V_137 [ 1 ] . type != V_138 ) {
V_131 = NULL ;
continue;
}
V_132 = & V_131 -> V_135 . V_137 [ 0 ] ;
if ( V_132 -> integer . V_139 == V_140 )
break;
V_131 = NULL ;
}
if ( V_131 ) {
V_133 = & V_131 -> V_135 . V_137 [ 1 ] ;
return V_133 -> integer . V_139 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , char * V_120 )
{
T_7 V_141 ;
T_7 V_142 ;
struct V_143 V_130 = { V_144 , NULL } ;
T_8 V_31 ;
T_3 V_145 ;
struct V_146 * V_147 = F_47 ( V_2 -> V_34 ) ;
V_141 = F_48 ( & V_147 -> V_34 ) ;
if ( ! V_141 ) {
F_43 ( V_2 ,
L_30 ) ;
return - V_148 ;
}
V_31 = F_49 ( V_141 , ( V_149 ) V_150 , & V_142 ) ;
if ( F_50 ( V_31 ) ) {
F_43 ( V_2 , L_31 ) ;
return - V_148 ;
}
V_31 = F_51 ( V_142 , NULL , NULL , & V_130 ) ;
if ( F_50 ( V_31 ) ) {
F_43 ( V_2 , L_32 , V_31 ) ;
return - V_148 ;
}
V_145 = F_45 ( V_2 , V_130 . V_151 ) ;
F_39 ( V_130 . V_151 ) ;
if ( ! V_145 )
return - V_148 ;
V_120 [ 0 ] = ( V_145 >> 8 ) & 0xff ;
V_120 [ 1 ] = V_145 & 0xff ;
V_120 [ 2 ] = '\0' ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , char * V_120 )
{
return - V_148 ;
}
int F_52 ( struct V_1 * V_2 )
{
bool V_152 ;
bool V_153 ;
int V_154 ;
struct V_155 * V_156 ;
char V_120 [ 3 ] ;
if ( V_2 -> V_35 -> V_58 == V_59 ) {
V_152 = F_15 ( & V_2 -> V_70 -> V_71 ,
V_72 ) ;
V_153 = V_2 -> V_111 -> V_55 ;
if ( V_152 != V_153 )
F_26 ( V_2 ,
L_33 ,
V_152 ? L_34 : L_35 ,
V_153 ? L_34 : L_35 ) ;
}
if ( ! F_41 ( V_2 ) )
return 0 ;
V_154 = F_53 ( V_2 ) ;
if ( V_154 != - V_148 )
return V_154 ;
V_2 -> V_157 = false ;
V_156 = F_54 ( V_2 , NULL ) ;
if ( F_55 ( V_156 ) )
return - V_37 ;
if ( F_56 ( V_2 ) &&
! F_46 ( V_2 , V_120 ) ) {
F_39 ( V_156 ) ;
V_156 = F_57 ( V_2 -> V_49 -> V_158 , V_120 ,
V_159 , NULL ) ;
if ( F_55 ( V_156 ) )
return - V_37 ;
}
V_154 = F_58 ( V_2 -> V_49 -> V_158 , V_156 ) ;
F_39 ( V_156 ) ;
return V_154 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_160 * V_161 )
{
struct V_23 * V_24 = F_60 ( V_161 ) ;
struct V_162 * V_163 = ( void * ) V_24 -> V_6 ;
enum V_116 V_164 ;
char V_120 [ 3 ] ;
struct V_155 * V_156 ;
F_61 ( & V_2 -> V_165 ) ;
if ( F_36 ( ! F_41 ( V_2 ) ) )
return;
V_120 [ 0 ] = V_163 -> V_120 >> 8 ;
V_120 [ 1 ] = V_163 -> V_120 & 0xff ;
V_120 [ 2 ] = '\0' ;
V_164 = V_163 -> V_121 ;
F_43 ( V_2 ,
L_36 ,
V_120 , V_164 ) ;
V_156 = F_57 ( V_2 -> V_49 -> V_158 , V_120 , V_164 , NULL ) ;
if ( F_55 ( V_156 ) )
return;
F_62 ( V_2 -> V_49 -> V_158 , V_156 ) ;
F_39 ( V_156 ) ;
}
