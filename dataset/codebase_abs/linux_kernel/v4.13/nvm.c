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
. V_16 = V_17 | V_18 ,
. V_6 = { & V_8 , V_6 } ,
. V_19 = { 0 , V_20 } ,
} ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
V_25 = F_3 ( V_2 , & V_12 ) ;
if ( V_25 )
return V_25 ;
V_22 = V_12 . V_26 ;
V_24 = ( void * ) V_22 -> V_6 ;
if ( F_4 ( V_24 -> V_27 ) != V_28 ) {
F_5 ( V_2 ,
L_1 ,
V_3 , F_4 ( V_24 -> V_27 ) ) ;
V_25 = - V_29 ;
}
F_6 ( & V_12 ) ;
return V_25 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_2 * V_6 )
{
struct V_7 V_8 = {
. V_4 = F_2 ( V_4 ) ,
. V_5 = F_2 ( V_5 ) ,
. type = F_2 ( V_3 ) ,
. V_9 = V_30 ,
} ;
struct V_23 * V_24 ;
struct V_21 * V_22 ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_16 = V_17 | V_18 ,
. V_6 = { & V_8 , } ,
} ;
int V_25 , V_31 , V_32 ;
T_2 * V_33 ;
V_12 . V_15 [ 0 ] = sizeof( struct V_7 ) ;
V_25 = F_3 ( V_2 , & V_12 ) ;
if ( V_25 )
return V_25 ;
V_22 = V_12 . V_26 ;
V_24 = ( void * ) V_22 -> V_6 ;
V_25 = F_4 ( V_24 -> V_27 ) ;
V_31 = F_4 ( V_24 -> V_5 ) ;
V_32 = F_4 ( V_24 -> V_4 ) ;
V_33 = V_24 -> V_6 ;
if ( V_25 ) {
if ( ( V_4 != 0 ) &&
( V_25 == V_34 ) ) {
F_8 ( V_2 -> V_35 -> V_36 ,
L_2 ,
V_4 ) ;
V_25 = 0 ;
} else {
F_8 ( V_2 -> V_35 -> V_36 ,
L_3 ,
V_25 , V_2 -> V_37 -> V_38 ) ;
V_25 = - V_29 ;
}
goto exit;
}
if ( V_32 != V_4 ) {
F_5 ( V_2 , L_4 ,
V_32 ) ;
V_25 = - V_39 ;
goto exit;
}
memcpy ( V_6 + V_4 , V_33 , V_31 ) ;
V_25 = V_31 ;
exit:
F_6 ( & V_12 ) ;
return V_25 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
const T_2 * V_6 , T_1 V_5 )
{
int V_4 = 0 ;
while ( V_4 < V_5 ) {
int V_40 , V_25 ;
V_40 = F_10 ( V_41 ,
V_5 - V_4 ) ;
V_25 = F_1 ( V_2 , V_3 , V_4 ,
V_40 , V_6 + V_4 ) ;
if ( V_25 < 0 )
return V_25 ;
V_4 += V_40 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 * V_6 , unsigned int V_15 )
{
#define F_12 0x5501
#define F_13 BIT(5)
if ( V_3 == V_42 &&
V_2 -> V_35 -> V_43 == F_12 && V_6 && V_15 >= 5 &&
( V_6 [ 4 ] & F_13 ) )
V_6 [ 3 ] = V_44 | ( V_44 << 4 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_6 , T_3 V_45 )
{
T_1 V_5 , V_4 = 0 ;
int V_25 ;
V_5 = V_41 ;
V_25 = V_5 ;
while ( V_25 == V_5 ) {
if ( ( V_45 + V_4 + V_5 ) >
V_2 -> V_37 -> V_46 -> V_47 ) {
F_5 ( V_2 , L_5 ) ;
return - V_48 ;
}
V_25 = F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_25 < 0 ) {
F_8 ( V_2 -> V_35 -> V_36 ,
L_6 ,
V_3 , V_4 , V_5 ) ;
return V_25 ;
}
V_4 += V_25 ;
}
F_11 ( V_2 , V_3 , V_6 , V_4 ) ;
F_8 ( V_2 -> V_35 -> V_36 ,
L_7 , V_3 ) ;
return V_4 ;
}
static struct V_49 *
F_15 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
const T_4 * V_53 , * V_54 , * V_55 , * V_56 , * V_57 , * V_58 ;
bool V_59 ;
if ( ! V_2 -> V_35 -> V_37 -> V_60 ) {
if ( ! V_2 -> V_52 [ V_61 ] . V_6 ||
! V_2 -> V_52 [ V_2 -> V_37 -> V_62 ] . V_6 ) {
F_5 ( V_2 , L_8 ) ;
return NULL ;
}
} else {
if ( ! V_2 -> V_52 [ V_61 ] . V_6 ||
! V_2 -> V_52 [ V_63 ] . V_6 ) {
F_5 ( V_2 ,
L_9 ) ;
return NULL ;
}
if ( ! V_2 -> V_52 [ V_2 -> V_37 -> V_62 ] . V_6 &&
! V_2 -> V_52 [ V_64 ] . V_6 ) {
F_5 ( V_2 ,
L_10 ) ;
return NULL ;
}
if ( ! V_2 -> V_52 [ V_42 ] . V_6 ) {
F_5 ( V_2 ,
L_11 ) ;
return NULL ;
}
}
if ( F_16 ( ! V_2 -> V_37 ) )
return NULL ;
V_53 = ( const T_4 * ) V_51 [ V_2 -> V_37 -> V_62 ] . V_6 ;
V_54 = ( const T_4 * ) V_51 [ V_61 ] . V_6 ;
V_55 = ( const T_4 * ) V_51 [ V_65 ] . V_6 ;
V_56 = ( const T_4 * ) V_51 [ V_63 ] . V_6 ;
V_57 =
( const T_4 * ) V_51 [ V_64 ] . V_6 ;
V_58 = ( const T_4 * ) V_51 [ V_42 ] . V_6 ;
V_59 = ! V_66 . V_67 &&
F_17 ( & V_2 -> V_68 -> V_69 ,
V_70 ) ;
return F_18 ( V_2 -> V_35 , V_2 -> V_37 , V_53 , V_54 , V_55 ,
V_56 , V_57 , V_58 ,
V_2 -> V_68 -> V_71 , V_2 -> V_68 -> V_72 ,
V_59 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_25 , V_73 ;
T_1 V_74 ;
const struct V_75 * V_76 ;
const struct {
T_4 V_77 ;
T_4 V_78 ;
T_2 V_6 [] ;
} * V_79 ;
const T_2 * V_80 ;
T_2 * V_81 ;
int V_82 ;
const T_5 * V_83 ;
#define F_20 ( T_6 ) (8 * (x & 0x03FF))
#define F_21 ( T_6 ) (x >> 12)
#define F_22 ( T_6 ) (2 * (((x) & 0xFF) << 8 | (x) >> 8))
#define F_23 ( T_6 ) ((x) >> 4)
#define F_24 (0x2A504C54)
#define F_25 (0x4E564D2A)
#define F_26 (4 * sizeof(u32))
F_8 ( V_2 -> V_35 -> V_36 , L_12 ) ;
if ( ! V_2 -> V_35 -> V_37 -> V_60 )
V_82 = V_84 ;
else
V_82 = V_85 ;
V_25 = F_27 ( & V_76 , V_2 -> V_86 ,
V_2 -> V_35 -> V_36 ) ;
if ( V_25 ) {
F_5 ( V_2 , L_13 ,
V_2 -> V_86 , V_25 ) ;
return V_25 ;
}
F_28 ( V_2 , L_14 ,
V_2 -> V_86 , V_76 -> V_87 ) ;
if ( V_76 -> V_87 > V_88 ) {
F_5 ( V_2 , L_15 ) ;
V_25 = - V_39 ;
goto V_89;
}
V_80 = V_76 -> V_6 + V_76 -> V_87 ;
V_83 = ( T_5 * ) V_76 -> V_6 ;
if ( V_76 -> V_87 > F_26 &&
V_83 [ 0 ] == F_29 ( F_24 ) &&
V_83 [ 1 ] == F_29 ( F_25 ) ) {
V_79 = ( void * ) ( V_76 -> V_6 + F_26 ) ;
F_28 ( V_2 , L_16 , F_30 ( V_83 [ 2 ] ) ) ;
F_28 ( V_2 , L_17 ,
F_30 ( V_83 [ 3 ] ) ) ;
if ( V_2 -> V_35 -> V_37 -> V_90 == V_91 &&
F_31 ( V_2 -> V_35 -> V_92 ) == V_93 &&
F_30 ( V_83 [ 2 ] ) < 0xE4A ) {
V_25 = - V_94 ;
goto V_89;
}
} else {
V_79 = ( void * ) V_76 -> V_6 ;
}
while ( true ) {
if ( V_79 -> V_6 > V_80 ) {
F_5 ( V_2 ,
L_18 ) ;
V_25 = - V_39 ;
break;
}
if ( ! V_79 -> V_77 && ! V_79 -> V_78 ) {
V_25 = 0 ;
break;
}
if ( ! V_2 -> V_35 -> V_37 -> V_60 ) {
V_73 =
2 * F_20 ( F_4 ( V_79 -> V_77 ) ) ;
V_74 = F_21 ( F_4 ( V_79 -> V_78 ) ) ;
} else {
V_73 = 2 * F_22 (
F_4 ( V_79 -> V_78 ) ) ;
V_74 = F_23 (
F_4 ( V_79 -> V_77 ) ) ;
}
if ( V_73 > V_82 ) {
F_5 ( V_2 , L_19 ,
V_73 ) ;
V_25 = - V_39 ;
break;
}
if ( ! V_73 ) {
F_5 ( V_2 , L_20 ) ;
V_25 = - V_39 ;
break;
}
if ( V_79 -> V_6 + V_73 > V_80 ) {
F_5 ( V_2 ,
L_21 ,
V_73 ) ;
V_25 = - V_39 ;
break;
}
if ( F_32 ( V_74 >= V_95 ,
L_22 , V_74 ) ) {
V_25 = - V_39 ;
break;
}
V_81 = F_33 ( V_79 -> V_6 , V_73 , V_96 ) ;
if ( ! V_81 ) {
V_25 = - V_97 ;
break;
}
F_11 ( V_2 , V_74 , V_81 , V_73 ) ;
F_34 ( V_2 -> V_52 [ V_74 ] . V_6 ) ;
V_2 -> V_52 [ V_74 ] . V_6 = V_81 ;
V_2 -> V_52 [ V_74 ] . V_5 = V_73 ;
V_79 = ( void * ) ( V_79 -> V_6 + V_73 ) ;
}
V_89:
F_35 ( V_76 ) ;
return V_25 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_98 , V_25 = 0 ;
struct V_50 * V_51 = V_2 -> V_52 ;
F_8 ( V_2 -> V_35 -> V_36 , L_23 ) ;
for ( V_98 = 0 ; V_98 < F_37 ( V_2 -> V_52 ) ; V_98 ++ ) {
if ( ! V_2 -> V_52 [ V_98 ] . V_6 || ! V_2 -> V_52 [ V_98 ] . V_5 )
continue;
V_25 = F_9 ( V_2 , V_98 , V_51 [ V_98 ] . V_6 ,
V_51 [ V_98 ] . V_5 ) ;
if ( V_25 < 0 ) {
F_5 ( V_2 , L_24 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_99 V_12 = {} ;
struct V_100 * V_101 ;
struct V_102 * V_35 = V_2 -> V_35 ;
struct V_11 V_103 = {
. V_16 = V_17 | V_18 ,
. V_6 = { & V_12 , } ,
. V_15 = { sizeof( V_12 ) } ,
. V_13 = F_39 (REGULATORY_AND_NVM_GROUP, NVM_GET_INFO)
} ;
int V_25 ;
bool V_104 = ! V_66 . V_67 &&
F_17 ( & V_2 -> V_68 -> V_69 ,
V_70 ) ;
F_40 ( & V_2 -> V_105 ) ;
V_25 = F_3 ( V_2 , & V_103 ) ;
if ( V_25 )
return V_25 ;
if ( F_32 ( F_41 ( V_103 . V_26 ) != sizeof( * V_101 ) ,
L_25 ,
F_41 ( V_103 . V_26 ) ) ) {
V_25 = - V_39 ;
goto V_89;
}
V_101 = ( void * ) V_103 . V_26 -> V_6 ;
if ( F_30 ( V_101 -> V_106 . V_16 ) ) {
F_5 ( V_2 , L_26 ) ;
V_25 = - V_39 ;
goto V_89;
}
V_2 -> V_107 = F_42 ( sizeof( * V_2 -> V_107 ) +
sizeof( struct V_108 ) *
V_109 , V_96 ) ;
if ( ! V_2 -> V_107 ) {
V_25 = - V_97 ;
goto V_89;
}
F_43 ( V_35 , V_2 -> V_107 ) ;
if ( ! F_44 ( V_2 -> V_107 -> V_110 ) ) {
F_5 ( V_35 , L_27 ) ;
V_25 = - V_39 ;
goto V_111;
}
F_28 ( V_35 , L_28 , V_2 -> V_107 -> V_110 ) ;
V_2 -> V_107 -> V_112 = F_4 ( V_101 -> V_106 . V_112 ) ;
V_2 -> V_107 -> V_113 =
F_30 ( V_101 -> V_114 . V_115 ) ;
V_2 -> V_107 -> V_116 =
F_30 ( V_101 -> V_114 . V_117 ) ;
V_2 -> V_107 -> V_118 =
F_30 ( V_101 -> V_114 . V_119 ) ;
V_2 -> V_107 -> V_120 =
F_30 ( V_101 -> V_114 . V_121 ) ;
V_2 -> V_107 -> V_122 =
F_30 ( V_101 -> V_114 . V_123 ) ;
V_2 -> V_107 -> V_71 = ( T_2 ) F_30 ( V_101 -> V_58 . V_124 ) ;
V_2 -> V_107 -> V_72 = ( T_2 ) F_30 ( V_101 -> V_58 . V_125 ) ;
V_2 -> V_107 -> V_59 =
F_30 ( V_101 -> V_56 . V_59 ) && V_104 ;
F_45 ( V_35 -> V_36 , V_35 -> V_37 , V_2 -> V_107 ,
V_101 -> V_56 . V_126 ,
V_2 -> V_107 -> V_71 & V_2 -> V_68 -> V_71 ,
V_2 -> V_107 -> V_72 & V_2 -> V_68 -> V_72 ,
V_101 -> V_56 . V_59 && V_104 ) ;
F_6 ( & V_103 ) ;
return 0 ;
V_111:
F_34 ( V_2 -> V_107 ) ;
V_89:
F_6 ( & V_103 ) ;
return V_25 ;
}
int F_46 ( struct V_1 * V_2 , bool V_127 )
{
int V_25 , V_3 ;
T_3 V_45 = 0 ;
T_2 * V_128 , * V_81 ;
const char * V_129 = V_2 -> V_37 -> V_130 ;
if ( F_47 ( V_2 -> V_37 -> V_62 >= V_95 ) )
return - V_39 ;
if ( V_127 ) {
F_8 ( V_2 -> V_35 -> V_36 , L_29 ) ;
V_128 = F_48 ( V_2 -> V_37 -> V_46 -> V_47 ,
V_96 ) ;
if ( ! V_128 )
return - V_97 ;
for ( V_3 = 0 ; V_3 < V_95 ; V_3 ++ ) {
V_25 = F_14 ( V_2 , V_3 , V_128 ,
V_45 ) ;
if ( V_25 < 0 )
continue;
V_45 += V_25 ;
V_81 = F_33 ( V_128 , V_25 , V_96 ) ;
if ( ! V_81 ) {
V_25 = - V_97 ;
break;
}
F_11 ( V_2 , V_3 , V_81 , V_25 ) ;
V_2 -> V_52 [ V_3 ] . V_6 = V_81 ;
V_2 -> V_52 [ V_3 ] . V_5 = V_25 ;
#ifdef F_49
switch ( V_3 ) {
case V_61 :
V_2 -> V_131 . V_6 = V_81 ;
V_2 -> V_131 . V_87 = V_25 ;
break;
case V_65 :
V_2 -> V_132 . V_6 = V_81 ;
V_2 -> V_132 . V_87 = V_25 ;
break;
case V_133 :
V_2 -> V_134 . V_6 = V_81 ;
V_2 -> V_134 . V_87 = V_25 ;
break;
case V_42 :
V_2 -> V_135 . V_6 = V_81 ;
V_2 -> V_135 . V_87 = V_25 ;
break;
default:
if ( V_3 == V_2 -> V_37 -> V_62 ) {
V_2 -> V_136 . V_6 = V_81 ;
V_2 -> V_136 . V_87 = V_25 ;
break;
}
}
#endif
}
if ( ! V_45 )
F_5 ( V_2 , L_30 ) ;
F_34 ( V_128 ) ;
}
if ( V_2 -> V_86 ) {
V_25 = F_19 ( V_2 ) ;
if ( V_25 ) {
V_2 -> V_86 = V_129 ;
if ( ( V_25 == - V_94 || V_25 == - V_137 ) &&
V_2 -> V_86 ) {
V_25 = F_19 ( V_2 ) ;
if ( V_25 )
return V_25 ;
} else {
return V_25 ;
}
}
}
V_2 -> V_107 = F_15 ( V_2 ) ;
if ( ! V_2 -> V_107 )
return - V_138 ;
F_8 ( V_2 -> V_35 -> V_36 , L_31 ,
V_2 -> V_107 -> V_112 ) ;
return 0 ;
}
struct V_139 *
F_50 ( struct V_1 * V_2 , const char * V_140 ,
enum V_141 V_142 )
{
struct V_143 V_144 = {
. V_145 = F_2 ( V_140 [ 0 ] << 8 | V_140 [ 1 ] ) ,
. V_146 = ( T_2 ) V_142 ,
} ;
struct V_139 * V_147 ;
struct V_21 * V_22 ;
struct V_11 V_12 = {
. V_13 = V_148 ,
. V_16 = V_17 ,
. V_6 = { & V_144 } ,
} ;
int V_25 ;
T_3 V_27 ;
int V_149 , V_150 ;
T_1 V_145 ;
bool V_151 = F_17 ( & V_2 -> V_68 -> V_69 ,
V_152 ) ;
if ( F_47 ( ! F_51 ( V_2 ) ) )
return F_52 ( - V_153 ) ;
V_12 . V_15 [ 0 ] = sizeof( struct V_143 ) ;
if ( ! V_151 )
V_12 . V_15 [ 0 ] = sizeof( struct V_154 ) ;
F_53 ( V_2 , L_32 ,
V_140 [ 0 ] , V_140 [ 1 ] , V_142 ) ;
V_25 = F_3 ( V_2 , & V_12 ) ;
if ( V_25 )
return F_52 ( V_25 ) ;
V_22 = V_12 . V_26 ;
if ( V_151 ) {
struct V_139 * V_155 = ( void * ) V_22 -> V_6 ;
V_150 = F_54 ( V_155 -> V_150 ) ;
V_149 = sizeof( struct V_139 ) +
V_150 * sizeof( T_5 ) ;
V_147 = F_33 ( V_155 , V_149 , V_96 ) ;
if ( ! V_147 ) {
V_147 = F_52 ( - V_97 ) ;
goto exit;
}
} else {
struct V_156 * V_157 = ( void * ) V_22 -> V_6 ;
V_150 = F_54 ( V_157 -> V_150 ) ;
V_149 = sizeof( struct V_139 ) +
V_150 * sizeof( T_5 ) ;
V_147 = F_42 ( V_149 , V_96 ) ;
if ( ! V_147 ) {
V_147 = F_52 ( - V_97 ) ;
goto exit;
}
V_147 -> V_27 = V_157 -> V_27 ;
V_147 -> V_145 = V_157 -> V_145 ;
V_147 -> V_158 = V_157 -> V_158 ;
V_147 -> V_146 = V_157 -> V_146 ;
V_147 -> V_150 = V_157 -> V_150 ;
memcpy ( V_147 -> V_159 , V_157 -> V_159 ,
V_150 * sizeof( T_5 ) ) ;
}
V_27 = F_30 ( V_147 -> V_27 ) ;
V_145 = F_4 ( V_147 -> V_145 ) ;
if ( V_145 == 0 ) {
V_145 = 0x3030 ;
V_147 -> V_145 = F_2 ( V_145 ) ;
}
F_53 ( V_2 ,
L_33 ,
V_27 , V_145 , V_145 >> 8 , V_145 & 0xff ,
! ! ( V_27 == V_160 ) , V_150 ) ;
exit:
F_6 ( & V_12 ) ;
return V_147 ;
}
int F_55 ( struct V_1 * V_2 )
{
bool V_161 ;
bool V_162 ;
int V_163 ;
struct V_164 * V_165 ;
char V_145 [ 3 ] ;
if ( V_2 -> V_37 -> V_60 ) {
V_161 = F_17 ( & V_2 -> V_68 -> V_69 ,
V_70 ) ;
V_162 = V_2 -> V_107 -> V_59 ;
if ( V_161 != V_162 )
F_28 ( V_2 ,
L_34 ,
V_161 ? L_35 : L_36 ,
V_162 ? L_35 : L_36 ) ;
}
if ( ! F_51 ( V_2 ) )
return 0 ;
V_163 = F_56 ( V_2 ) ;
if ( V_163 != - V_137 )
return V_163 ;
V_2 -> V_166 = false ;
V_165 = F_57 ( V_2 , NULL ) ;
if ( F_58 ( V_165 ) )
return - V_29 ;
if ( F_59 ( V_2 ) &&
! F_60 ( V_2 -> V_36 , V_145 ) ) {
F_34 ( V_165 ) ;
V_165 = F_61 ( V_2 -> V_53 -> V_167 , V_145 ,
V_168 , NULL ) ;
if ( F_58 ( V_165 ) )
return - V_29 ;
}
V_163 = F_62 ( V_2 -> V_53 -> V_167 , V_165 ) ;
F_34 ( V_165 ) ;
return V_163 ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_21 * V_22 = F_64 ( V_170 ) ;
struct V_171 * V_172 = ( void * ) V_22 -> V_6 ;
enum V_141 V_173 ;
char V_145 [ 3 ] ;
struct V_164 * V_165 ;
F_40 ( & V_2 -> V_105 ) ;
if ( F_65 ( V_2 ) && V_172 -> V_146 == V_174 ) {
F_53 ( V_2 , L_37 ) ;
return;
}
if ( F_47 ( ! F_51 ( V_2 ) ) )
return;
V_145 [ 0 ] = F_4 ( V_172 -> V_145 ) >> 8 ;
V_145 [ 1 ] = F_4 ( V_172 -> V_145 ) & 0xff ;
V_145 [ 2 ] = '\0' ;
V_173 = V_172 -> V_146 ;
F_53 ( V_2 ,
L_38 ,
V_145 , V_173 ) ;
V_165 = F_61 ( V_2 -> V_53 -> V_167 , V_145 , V_173 , NULL ) ;
if ( F_58 ( V_165 ) )
return;
F_66 ( V_2 -> V_53 -> V_167 , V_165 ) ;
F_34 ( V_165 ) ;
}
