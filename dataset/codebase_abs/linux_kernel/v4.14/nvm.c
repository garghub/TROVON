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
const T_4 * V_53 ;
const T_5 * V_54 , * V_55 , * V_56 , * V_57 , * V_58 ;
bool V_59 ;
int V_60 ;
if ( V_2 -> V_35 -> V_37 -> V_61 != V_62 ) {
if ( ! V_2 -> V_52 [ V_63 ] . V_6 ||
! V_2 -> V_52 [ V_2 -> V_37 -> V_64 ] . V_6 ) {
F_5 ( V_2 , L_8 ) ;
return NULL ;
}
} else {
if ( V_2 -> V_35 -> V_37 -> V_61 == V_65 )
V_60 = V_66 ;
else
V_60 = V_67 ;
if ( ! V_2 -> V_52 [ V_63 ] . V_6 ||
! V_2 -> V_52 [ V_60 ] . V_6 ) {
F_5 ( V_2 ,
L_9 ) ;
return NULL ;
}
if ( ! V_2 -> V_52 [ V_2 -> V_37 -> V_64 ] . V_6 &&
! V_2 -> V_52 [ V_68 ] . V_6 ) {
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
V_53 = ( const T_4 * ) V_51 [ V_2 -> V_37 -> V_64 ] . V_6 ;
V_54 = ( const T_5 * ) V_51 [ V_63 ] . V_6 ;
V_55 = ( const T_5 * ) V_51 [ V_69 ] . V_6 ;
V_57 =
( const T_5 * ) V_51 [ V_68 ] . V_6 ;
V_58 = ( const T_5 * ) V_51 [ V_42 ] . V_6 ;
V_56 = V_2 -> V_35 -> V_37 -> V_61 == V_65 ?
( const T_5 * ) V_51 [ V_66 ] . V_6 :
( const T_5 * ) V_51 [ V_67 ] . V_6 ;
V_59 = ! V_70 . V_71 &&
F_16 ( & V_2 -> V_72 -> V_73 ,
V_74 ) ;
return F_17 ( V_2 -> V_35 , V_2 -> V_37 , V_53 , V_54 , V_55 ,
V_56 , V_57 , V_58 ,
V_2 -> V_72 -> V_75 , V_2 -> V_72 -> V_76 ,
V_59 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_25 , V_77 ;
T_1 V_78 ;
const struct V_79 * V_80 ;
const struct {
T_5 V_81 ;
T_5 V_82 ;
T_2 V_6 [] ;
} * V_83 ;
const T_2 * V_84 ;
T_2 * V_85 ;
int V_86 ;
const T_6 * V_87 ;
#define F_19 ( T_7 ) (8 * (x & 0x03FF))
#define F_20 ( T_7 ) (x >> 12)
#define F_21 ( T_7 ) (2 * (((x) & 0xFF) << 8 | (x) >> 8))
#define F_22 ( T_7 ) ((x) >> 4)
#define F_23 (0x2A504C54)
#define F_24 (0x4E564D2A)
#define F_25 (4 * sizeof(u32))
F_8 ( V_2 -> V_35 -> V_36 , L_12 ) ;
if ( V_2 -> V_35 -> V_37 -> V_61 != V_62 )
V_86 = V_88 ;
else
V_86 = V_89 ;
V_25 = F_26 ( & V_80 , V_2 -> V_90 ,
V_2 -> V_35 -> V_36 ) ;
if ( V_25 ) {
F_5 ( V_2 , L_13 ,
V_2 -> V_90 , V_25 ) ;
return V_25 ;
}
F_27 ( V_2 , L_14 ,
V_2 -> V_90 , V_80 -> V_91 ) ;
if ( V_80 -> V_91 > V_92 ) {
F_5 ( V_2 , L_15 ) ;
V_25 = - V_39 ;
goto V_93;
}
V_84 = V_80 -> V_6 + V_80 -> V_91 ;
V_87 = ( T_6 * ) V_80 -> V_6 ;
if ( V_80 -> V_91 > F_25 &&
V_87 [ 0 ] == F_28 ( F_23 ) &&
V_87 [ 1 ] == F_28 ( F_24 ) ) {
V_83 = ( void * ) ( V_80 -> V_6 + F_25 ) ;
F_27 ( V_2 , L_16 , F_29 ( V_87 [ 2 ] ) ) ;
F_27 ( V_2 , L_17 ,
F_29 ( V_87 [ 3 ] ) ) ;
if ( V_2 -> V_35 -> V_37 -> V_94 == V_95 &&
F_30 ( V_2 -> V_35 -> V_96 ) == V_97 &&
F_29 ( V_87 [ 2 ] ) < 0xE4A ) {
V_25 = - V_98 ;
goto V_93;
}
} else {
V_83 = ( void * ) V_80 -> V_6 ;
}
while ( true ) {
if ( V_83 -> V_6 > V_84 ) {
F_5 ( V_2 ,
L_18 ) ;
V_25 = - V_39 ;
break;
}
if ( ! V_83 -> V_81 && ! V_83 -> V_82 ) {
V_25 = 0 ;
break;
}
if ( V_2 -> V_35 -> V_37 -> V_61 != V_62 ) {
V_77 =
2 * F_19 ( F_4 ( V_83 -> V_81 ) ) ;
V_78 = F_20 ( F_4 ( V_83 -> V_82 ) ) ;
} else {
V_77 = 2 * F_21 (
F_4 ( V_83 -> V_82 ) ) ;
V_78 = F_22 (
F_4 ( V_83 -> V_81 ) ) ;
}
if ( V_77 > V_86 ) {
F_5 ( V_2 , L_19 ,
V_77 ) ;
V_25 = - V_39 ;
break;
}
if ( ! V_77 ) {
F_5 ( V_2 , L_20 ) ;
V_25 = - V_39 ;
break;
}
if ( V_83 -> V_6 + V_77 > V_84 ) {
F_5 ( V_2 ,
L_21 ,
V_77 ) ;
V_25 = - V_39 ;
break;
}
if ( F_31 ( V_78 >= V_99 ,
L_22 , V_78 ) ) {
V_25 = - V_39 ;
break;
}
V_85 = F_32 ( V_83 -> V_6 , V_77 , V_100 ) ;
if ( ! V_85 ) {
V_25 = - V_101 ;
break;
}
F_11 ( V_2 , V_78 , V_85 , V_77 ) ;
F_33 ( V_2 -> V_52 [ V_78 ] . V_6 ) ;
V_2 -> V_52 [ V_78 ] . V_6 = V_85 ;
V_2 -> V_52 [ V_78 ] . V_5 = V_77 ;
V_83 = ( void * ) ( V_83 -> V_6 + V_77 ) ;
}
V_93:
F_34 ( V_80 ) ;
return V_25 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_102 , V_25 = 0 ;
struct V_50 * V_51 = V_2 -> V_52 ;
F_8 ( V_2 -> V_35 -> V_36 , L_23 ) ;
for ( V_102 = 0 ; V_102 < F_36 ( V_2 -> V_52 ) ; V_102 ++ ) {
if ( ! V_2 -> V_52 [ V_102 ] . V_6 || ! V_2 -> V_52 [ V_102 ] . V_5 )
continue;
V_25 = F_9 ( V_2 , V_102 , V_51 [ V_102 ] . V_6 ,
V_51 [ V_102 ] . V_5 ) ;
if ( V_25 < 0 ) {
F_5 ( V_2 , L_24 , V_25 ) ;
break;
}
}
return V_25 ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_25 , V_3 ;
T_3 V_45 = 0 ;
T_2 * V_103 , * V_85 ;
const char * V_104 = V_2 -> V_37 -> V_105 ;
if ( F_38 ( V_2 -> V_37 -> V_64 >= V_99 ) )
return - V_39 ;
F_8 ( V_2 -> V_35 -> V_36 , L_25 ) ;
V_103 = F_39 ( V_2 -> V_37 -> V_46 -> V_47 ,
V_100 ) ;
if ( ! V_103 )
return - V_101 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
V_25 = F_14 ( V_2 , V_3 , V_103 ,
V_45 ) ;
if ( V_25 < 0 )
continue;
V_45 += V_25 ;
V_85 = F_32 ( V_103 , V_25 , V_100 ) ;
if ( ! V_85 ) {
V_25 = - V_101 ;
break;
}
F_11 ( V_2 , V_3 , V_85 , V_25 ) ;
V_2 -> V_52 [ V_3 ] . V_6 = V_85 ;
V_2 -> V_52 [ V_3 ] . V_5 = V_25 ;
#ifdef F_40
switch ( V_3 ) {
case V_63 :
V_2 -> V_106 . V_6 = V_85 ;
V_2 -> V_106 . V_91 = V_25 ;
break;
case V_69 :
V_2 -> V_107 . V_6 = V_85 ;
V_2 -> V_107 . V_91 = V_25 ;
break;
case V_108 :
V_2 -> V_109 . V_6 = V_85 ;
V_2 -> V_109 . V_91 = V_25 ;
break;
case V_42 :
V_2 -> V_110 . V_6 = V_85 ;
V_2 -> V_110 . V_91 = V_25 ;
break;
default:
if ( V_3 == V_2 -> V_37 -> V_64 ) {
V_2 -> V_111 . V_6 = V_85 ;
V_2 -> V_111 . V_91 = V_25 ;
break;
}
}
#endif
}
if ( ! V_45 )
F_5 ( V_2 , L_26 ) ;
F_33 ( V_103 ) ;
if ( V_2 -> V_90 ) {
V_25 = F_18 ( V_2 ) ;
if ( V_25 ) {
V_2 -> V_90 = V_104 ;
if ( ( V_25 == - V_98 || V_25 == - V_112 ) &&
V_2 -> V_90 ) {
V_25 = F_18 ( V_2 ) ;
if ( V_25 )
return V_25 ;
} else {
return V_25 ;
}
}
}
V_2 -> V_113 = F_15 ( V_2 ) ;
if ( ! V_2 -> V_113 )
return - V_114 ;
F_8 ( V_2 -> V_35 -> V_36 , L_27 ,
V_2 -> V_113 -> V_115 ) ;
return 0 ;
}
struct V_116 *
F_41 ( struct V_1 * V_2 , const char * V_117 ,
enum V_118 V_119 )
{
struct V_120 V_121 = {
. V_122 = F_2 ( V_117 [ 0 ] << 8 | V_117 [ 1 ] ) ,
. V_123 = ( T_2 ) V_119 ,
} ;
struct V_116 * V_124 ;
struct V_21 * V_22 ;
struct V_11 V_12 = {
. V_13 = V_125 ,
. V_16 = V_17 ,
. V_6 = { & V_121 } ,
} ;
int V_25 ;
T_3 V_27 ;
int V_126 , V_127 ;
T_1 V_122 ;
bool V_128 = F_16 ( & V_2 -> V_72 -> V_73 ,
V_129 ) ;
if ( F_38 ( ! F_42 ( V_2 ) ) )
return F_43 ( - V_130 ) ;
V_12 . V_15 [ 0 ] = sizeof( struct V_120 ) ;
if ( ! V_128 )
V_12 . V_15 [ 0 ] = sizeof( struct V_131 ) ;
F_44 ( V_2 , L_28 ,
V_117 [ 0 ] , V_117 [ 1 ] , V_119 ) ;
V_25 = F_3 ( V_2 , & V_12 ) ;
if ( V_25 )
return F_43 ( V_25 ) ;
V_22 = V_12 . V_26 ;
if ( V_128 ) {
struct V_116 * V_132 = ( void * ) V_22 -> V_6 ;
V_127 = F_45 ( V_132 -> V_127 ) ;
V_126 = sizeof( struct V_116 ) +
V_127 * sizeof( T_6 ) ;
V_124 = F_32 ( V_132 , V_126 , V_100 ) ;
if ( ! V_124 ) {
V_124 = F_43 ( - V_101 ) ;
goto exit;
}
} else {
struct V_133 * V_134 = ( void * ) V_22 -> V_6 ;
V_127 = F_45 ( V_134 -> V_127 ) ;
V_126 = sizeof( struct V_116 ) +
V_127 * sizeof( T_6 ) ;
V_124 = F_46 ( V_126 , V_100 ) ;
if ( ! V_124 ) {
V_124 = F_43 ( - V_101 ) ;
goto exit;
}
V_124 -> V_27 = V_134 -> V_27 ;
V_124 -> V_122 = V_134 -> V_122 ;
V_124 -> V_135 = V_134 -> V_135 ;
V_124 -> V_123 = V_134 -> V_123 ;
V_124 -> V_127 = V_134 -> V_127 ;
memcpy ( V_124 -> V_136 , V_134 -> V_136 ,
V_127 * sizeof( T_6 ) ) ;
}
V_27 = F_29 ( V_124 -> V_27 ) ;
V_122 = F_4 ( V_124 -> V_122 ) ;
if ( V_122 == 0 ) {
V_122 = 0x3030 ;
V_124 -> V_122 = F_2 ( V_122 ) ;
}
F_44 ( V_2 ,
L_29 ,
V_27 , V_122 , V_122 >> 8 , V_122 & 0xff ,
! ! ( V_27 == V_137 ) , V_127 ) ;
exit:
F_6 ( & V_12 ) ;
return V_124 ;
}
int F_47 ( struct V_1 * V_2 )
{
bool V_138 ;
bool V_139 ;
int V_140 ;
struct V_141 * V_142 ;
char V_122 [ 3 ] ;
if ( V_2 -> V_37 -> V_61 == V_62 ) {
V_138 = F_16 ( & V_2 -> V_72 -> V_73 ,
V_74 ) ;
V_139 = V_2 -> V_113 -> V_59 ;
if ( V_138 != V_139 )
F_27 ( V_2 ,
L_30 ,
V_138 ? L_31 : L_32 ,
V_139 ? L_31 : L_32 ) ;
}
if ( ! F_42 ( V_2 ) )
return 0 ;
V_140 = F_48 ( V_2 ) ;
if ( V_140 != - V_112 )
return V_140 ;
V_2 -> V_143 = false ;
V_142 = F_49 ( V_2 , NULL ) ;
if ( F_50 ( V_142 ) )
return - V_29 ;
if ( F_51 ( V_2 ) &&
! F_52 ( V_2 -> V_36 , V_122 ) ) {
F_33 ( V_142 ) ;
V_142 = F_53 ( V_2 -> V_53 -> V_144 , V_122 ,
V_145 , NULL ) ;
if ( F_50 ( V_142 ) )
return - V_29 ;
}
V_140 = F_54 ( V_2 -> V_53 -> V_144 , V_142 ) ;
F_33 ( V_142 ) ;
return V_140 ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_21 * V_22 = F_56 ( V_147 ) ;
struct V_148 * V_149 = ( void * ) V_22 -> V_6 ;
enum V_118 V_150 ;
char V_122 [ 3 ] ;
struct V_141 * V_142 ;
F_57 ( & V_2 -> V_151 ) ;
if ( F_58 ( V_2 ) && V_149 -> V_123 == V_152 ) {
F_44 ( V_2 , L_33 ) ;
return;
}
if ( F_38 ( ! F_42 ( V_2 ) ) )
return;
V_122 [ 0 ] = F_4 ( V_149 -> V_122 ) >> 8 ;
V_122 [ 1 ] = F_4 ( V_149 -> V_122 ) & 0xff ;
V_122 [ 2 ] = '\0' ;
V_150 = V_149 -> V_123 ;
F_44 ( V_2 ,
L_34 ,
V_122 , V_150 ) ;
V_142 = F_53 ( V_2 -> V_53 -> V_144 , V_122 , V_150 , NULL ) ;
if ( F_50 ( V_142 ) )
return;
F_59 ( V_2 -> V_53 -> V_144 , V_142 ) ;
F_33 ( V_142 ) ;
}
