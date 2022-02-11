static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 [ 0 ] ;
}
static inline void F_2 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
V_3 -> V_4 [ 0 ] = ( unsigned long ) V_5 ;
}
static inline int F_3 ( struct V_6 * V_7 )
{
return V_7 -> V_8 == F_4 ( V_9 ) ;
}
static int F_5 ( struct V_6 * V_7 , struct V_2 * V_3 )
{
F_6 ( V_7 ) ;
if ( F_7 ( V_7 ) ) {
F_8 ( V_3 -> V_10 , L_1 ) ;
return 0 ;
}
if ( ! F_9 ( V_7 , V_11 ) )
return 0 ;
V_7 -> V_8 = F_10 ( V_7 ) -> V_12 ;
return 1 ;
}
static const T_1 * F_11 ( struct V_13 * V_14 , const T_1 * V_15 )
{
V_14 -> V_16 = 1 ;
V_14 -> V_17 = F_12 ( V_15 ) ;
return V_15 + sizeof( V_14 -> V_17 ) ;
}
static const T_1 * F_13 ( struct V_13 * V_14 , const T_1 * V_15 )
{
V_14 -> V_16 = 1 ;
V_14 -> V_18 = * V_15 ;
return V_15 + sizeof( V_14 -> V_18 ) ;
}
static int F_14 ( const T_1 * V_19 , const T_2 V_20 , struct V_21 * V_22 )
{
const T_1 * V_23 = V_19 ;
int V_24 ;
if ( V_20 < V_25 )
return - V_26 ;
V_23 = F_11 ( & V_22 -> V_27 , V_23 ) ;
V_23 = F_13 ( & V_22 -> V_28 , V_23 ) ;
V_23 = F_13 ( & V_22 -> V_29 , V_23 ) ;
V_24 = V_22 -> V_28 . V_18 & 0x80 ;
V_22 -> V_28 . V_18 &= 0x7F ;
V_22 -> V_30 . V_16 = ( V_22 -> V_28 . V_18 == V_31 ) ;
if ( V_22 -> V_30 . V_16 ) {
if ( V_20 < V_32 )
return - V_26 ;
V_22 -> V_27 . V_17 &= 0x3FFF ;
V_23 = F_11 ( & V_22 -> V_30 , V_23 ) ;
V_22 -> V_30 . V_17 &= 0x03FF ;
V_22 -> V_33 = V_32 ;
} else {
V_22 -> V_27 . V_17 &= 0x07FF ;
V_22 -> V_33 = V_25 ;
}
if ( V_24 ) {
V_22 -> V_33 ++ ;
V_22 -> V_27 . V_17 -- ;
}
if ( V_20 < ( V_22 -> V_33 + V_22 -> V_27 . V_17 ) )
return - V_34 ;
return 0 ;
}
static void F_15 ( T_1 * V_19 , const T_3 V_35 ,
struct V_1 * V_5 )
{
F_16 ( V_35 , V_19 ) ;
memcpy ( V_19 + 2 , V_5 -> V_36 , sizeof( V_5 -> V_36 ) ) ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 * V_37 , int V_38 , const char * V_39 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_40 ;
V_40 = F_18 ( V_3 , V_41 ,
V_42 | V_43 | V_44 ,
0 , V_5 -> V_45 , V_37 , V_38 ) ;
if ( V_40 != V_38 && V_40 != - V_46 )
F_8 ( V_3 -> V_10 , L_2 , V_39 , V_40 ) ;
return V_40 ;
}
static int F_19 ( struct V_2 * V_3 )
{
int V_40 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
V_40 = F_17 ( V_3 , V_5 -> V_49 ,
sizeof( V_5 -> V_49 ) , L_4 ) ;
return V_40 ;
}
static void F_21 ( struct V_1 * V_5 , T_1 V_50 )
{
F_20 ( & ( V_5 -> V_2 -> V_47 -> V_3 ) , L_5 , V_48 , V_50 ) ;
V_5 -> V_36 [ 0 ] = 0x3F ;
V_5 -> V_36 [ 1 ] = V_50 ;
* ( ( V_51 * ) & V_5 -> V_36 [ 2 ] ) =
F_4 ( V_52 ) ;
}
static inline int F_22 ( T_1 V_53 )
{
return V_53 == sizeof( struct V_54 ) ;
}
static int F_23 ( struct V_2 * V_3 , char * V_4 , int V_55 )
{
struct V_56 * V_57 = (struct V_56 * ) V_4 ;
if ( V_55 < sizeof( struct V_56 ) ) {
F_8 ( V_3 -> V_10 , L_6 ,
V_48 , V_55 ,
sizeof( struct V_56 ) ) ;
return - 1 ;
}
if ( V_57 -> V_58 != F_4 ( V_59 ) ) {
F_8 ( V_3 -> V_10 , L_7 ,
V_48 , F_24 ( V_57 -> V_58 ) ,
( T_2 ) V_59 ) ;
return - 1 ;
}
if ( V_57 -> V_8 != V_60 ) {
F_8 ( V_3 -> V_10 , L_8 ,
V_57 -> V_8 ) ;
return - 1 ;
}
if ( V_57 -> V_61 != V_62 ) {
F_8 ( V_3 -> V_10 , L_9 ,
V_57 -> V_61 ) ;
return - 1 ;
}
if ( V_57 -> V_63 == V_64
|| V_57 -> V_63 == V_65 ) {
F_8 ( V_3 -> V_10 , L_10 , V_57 -> V_63 ) ;
return 0 ;
}
if ( V_57 -> V_66 == V_67 ) {
F_8 ( V_3 -> V_10 , L_11 ,
V_57 -> V_66 ) ;
return 0 ;
}
return 1 ;
}
static void F_25 ( struct V_2 * V_3 , char * V_4 ,
struct V_21 * V_22 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_68 ;
V_68 = F_23 ( V_3 , V_4 + V_22 -> V_33 ,
V_22 -> V_27 . V_17 ) ;
if ( V_68 < 0 ) {
F_8 ( V_3 -> V_10 , L_12 ) ;
return;
}
if ( V_68 ) {
F_21 ( V_5 , V_22 -> V_29 . V_18 ) ;
V_5 -> V_68 = 1 ;
} else {
V_5 -> V_68 = 0 ;
}
F_26 ( V_3 , V_68 , 0 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
int V_40 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
V_40 = F_19 ( V_3 ) ;
if ( V_40 < 0 )
F_8 ( V_3 -> V_10 ,
L_13 , V_40 ) ;
V_40 = F_19 ( V_3 ) ;
if ( V_40 < 0 )
F_8 ( V_3 -> V_10 ,
L_13 , V_40 ) ;
V_5 -> V_69 . V_70 = V_71 ;
V_5 -> V_69 . V_4 = ( unsigned long ) V_3 ;
V_5 -> V_69 . V_72 = V_73 + V_74 ;
F_28 ( & V_5 -> V_69 ) ;
}
static void F_29 ( struct V_75 * V_76 )
{
struct V_1 * V_5 =
F_30 ( V_76 , struct V_1 , F_29 ) ;
struct V_2 * V_3 = V_5 -> V_2 ;
int V_53 ;
int V_77 ;
T_1 * V_19 ;
T_1 V_45 ;
if ( F_31 ( V_78 , & V_5 -> V_79 ) ) {
F_32 ( V_78 , & V_5 -> V_79 ) ;
V_19 = F_33 ( V_80 , V_81 ) ;
if ( ! V_19 )
return;
V_45 = V_5 -> V_45 ;
V_53 = F_34 ( V_3 -> V_47 , F_35 ( V_3 -> V_47 , 0 ) ,
V_82 ,
V_83 | V_43 | V_44 ,
0 , V_45 , V_19 , V_80 ,
V_84 ) ;
if ( V_53 < 0 ) {
F_8 ( V_3 -> V_10 ,
L_14 , V_53 ) ;
} else {
struct V_21 V_22 ;
F_20 ( & V_3 -> V_47 -> V_3 , L_15
L_16 , V_48 , V_53 ) ;
V_77 = F_14 ( V_19 , V_53 , & V_22 ) ;
if ( V_77 ) {
F_8 ( V_3 -> V_10 , L_17
L_18 , V_48 , V_77 ) ;
F_36 ( V_19 ) ;
return;
}
if ( V_53 != V_22 . V_33 + V_22 . V_27 . V_17 ) {
F_8 ( V_3 -> V_10 , L_19
L_20 , V_48 , V_53 ,
V_22 . V_33 + V_22 . V_27 . V_17 ) ;
F_36 ( V_19 ) ;
return;
}
switch ( V_22 . V_28 . V_18 ) {
case V_85 :
F_20 ( & V_3 -> V_47 -> V_3 , L_21 ,
V_22 . V_29 . V_18 ) ;
F_25 ( V_3 , V_19 , & V_22 ) ;
break;
case V_86 :
F_20 ( & V_3 -> V_47 -> V_3 , L_22
L_23 ,
V_22 . V_29 . V_18 ) ;
F_37 ( & V_5 -> V_69 ) ;
F_32 ( V_87 ,
& V_5 -> V_79 ) ;
break;
case V_88 :
F_20 ( & V_3 -> V_47 -> V_3 , L_24 ) ;
V_77 = F_19 ( V_3 ) ;
if ( V_77 < 0 )
F_8 ( V_3 -> V_10 ,
L_25 , V_77 ) ;
break;
case V_31 :
F_8 ( V_3 -> V_10 , L_26
L_27 , V_22 . V_30 . V_17 ) ;
break;
case V_89 :
break;
default:
F_8 ( V_3 -> V_10 , L_26
L_28 , V_22 . V_28 . V_18 ) ;
break;
}
}
F_36 ( V_19 ) ;
}
if ( F_31 ( V_87 , & V_5 -> V_79 ) ) {
F_32 ( V_87 , & V_5 -> V_79 ) ;
F_20 ( & V_3 -> V_47 -> V_3 , L_29 ) ;
F_27 ( V_5 -> V_2 ) ;
}
if ( V_5 -> V_79 )
F_20 ( & V_3 -> V_47 -> V_3 , L_30
L_31 , V_5 -> V_79 ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_76 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_39 ( V_76 , & V_5 -> V_79 ) ;
F_40 ( & V_5 -> F_29 ) ;
}
static void V_71 ( unsigned long V_90 )
{
struct V_2 * V_3 = (struct V_2 * ) V_90 ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
F_38 ( V_3 , V_87 ) ;
}
static void F_41 ( struct V_2 * V_3 , struct V_91 * V_91 )
{
struct V_92 * V_93 ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
if ( V_91 -> V_94 < sizeof *V_93 )
return;
V_93 = V_91 -> V_95 ;
switch ( V_93 -> V_96 ) {
case V_97 :
case V_98 :
break;
case V_99 :
F_38 ( V_3 , V_78 ) ;
break;
default:
F_8 ( V_3 -> V_10 , L_32 ,
V_93 -> V_96 ) ;
break;
}
}
static void F_42 ( struct V_100 * V_10 ,
struct V_101 * V_102 )
{
F_43 ( V_10 , V_102 ) ;
F_44 ( V_102 -> V_103 , V_104 , sizeof( V_102 -> V_103 ) ) ;
F_44 ( V_102 -> V_105 , V_106 , sizeof( V_102 -> V_105 ) ) ;
}
static T_2 F_45 ( struct V_100 * V_10 )
{
struct V_2 * V_3 = F_46 ( V_10 ) ;
return F_1 ( V_3 ) -> V_68 && F_47 ( V_10 ) ;
}
static int F_48 ( struct V_100 * V_10 , int V_107 )
{
if ( V_107 > V_108 )
return - V_34 ;
return F_49 ( V_10 , V_107 ) ;
}
static int F_50 ( struct V_2 * V_3 , T_3 * V_15 )
{
int V_109 = 0 ;
T_4 V_110 ;
V_109 = F_51 ( V_3 ,
V_111 ,
V_83 | V_112 ,
0x0000 ,
0x0000 ,
& V_110 ,
sizeof( V_110 )
) ;
if ( V_109 < 0 )
return - V_113 ;
* V_15 = F_52 ( V_110 ) ;
return V_109 ;
}
static int F_53 ( struct V_2 * V_3 , struct V_114 * V_115 )
{
T_1 V_116 ;
T_1 V_117 ;
T_3 V_118 = 0 ;
int V_40 ;
struct V_119 * V_120 ;
struct V_1 * V_5 ;
static const T_1 V_121 [ sizeof( V_5 -> V_49 ) ] = {
0x00 , 0x00 , V_122 , 0x00 } ;
static const T_1 V_123 [ sizeof( V_5 -> V_124 ) ] = {
0x00 , 0x00 , V_125 , 0x00 } ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
V_116 = V_115 -> V_126 -> V_127 . V_128 ;
V_117 = V_115 -> V_126 -> V_127 . V_129 ;
if ( V_117 != 3 ) {
F_54 ( & V_3 -> V_47 -> V_3 , L_33 ,
V_117 ) ;
return - V_46 ;
}
V_3 -> V_40 = NULL ;
V_40 = F_55 ( V_3 , V_115 ) ;
if ( V_40 < 0 ) {
F_54 ( & V_3 -> V_47 -> V_3 , L_34 ,
V_40 ) ;
return - V_46 ;
}
V_5 = F_33 ( sizeof *V_5 , V_81 ) ;
if ( ! V_5 )
return - V_130 ;
V_5 -> V_2 = V_3 ;
V_5 -> V_45 = V_116 ;
V_3 -> V_10 -> V_131 = & V_132 ;
V_3 -> V_10 -> V_133 [ V_134 - 2 ] = F_56 ( & V_135 ) ;
V_3 -> V_10 -> V_133 [ V_134 - 1 ] = V_116 ;
V_120 = (struct V_119 * ) V_5 -> V_136 ;
memcpy ( & V_120 -> V_137 , V_3 -> V_10 -> V_133 , V_134 ) ;
V_120 -> V_12 = F_4 ( V_9 ) ;
memcpy ( V_5 -> V_124 , V_123 , sizeof( V_5 -> V_124 ) ) ;
F_21 ( V_5 , 0 ) ;
memcpy ( V_5 -> V_49 , V_121 , sizeof( V_5 -> V_49 ) ) ;
V_3 -> V_138 = V_139 ;
if ( V_3 -> V_47 -> V_140 != V_141 )
V_3 -> V_138 = F_57 ( V_142 , 4096 , V_139 ) ;
V_3 -> V_10 -> V_143 += V_32 ;
V_3 -> V_144 = V_3 -> V_10 -> V_145 + V_3 -> V_10 -> V_143 ;
V_3 -> V_10 -> V_146 |= V_147 ;
V_3 -> V_10 -> V_148 = & V_149 ;
F_58 ( V_3 -> V_10 ) ;
F_2 ( V_3 , V_5 ) ;
V_5 -> V_79 = 0 ;
F_59 ( & V_5 -> F_29 , F_29 ) ;
F_60 ( & V_5 -> V_69 ) ;
V_40 = F_50 ( V_3 , & V_118 ) ;
F_20 ( & V_3 -> V_47 -> V_3 , L_35 , V_118 ) ;
if ( ! ( V_40 == sizeof( V_118 ) && ( V_118 & V_150 ) ) ) {
F_54 ( & V_3 -> V_47 -> V_3 , L_36
L_37 ) ;
F_36 ( V_5 ) ;
return - V_46 ;
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 , struct V_114 * V_115 )
{
int V_40 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
F_37 ( & V_5 -> V_69 ) ;
F_62 ( & V_5 -> F_29 ) ;
V_40 = F_17 ( V_3 , V_5 -> V_124 ,
sizeof( V_5 -> V_124 ) , L_38 ) ;
if ( V_40 < 0 )
F_8 ( V_3 -> V_10 ,
L_14 , V_40 ) ;
F_63 ( V_3 ) ;
F_2 ( V_3 , NULL ) ;
F_36 ( V_5 ) ;
}
static struct V_6 * F_64 ( struct V_2 * V_3 ,
struct V_6 * V_7 , int V_53 )
{
struct V_6 * V_151 ;
V_151 = F_65 ( V_7 , V_152 ) ;
F_66 ( V_7 , V_53 ) ;
if ( V_151 ) {
F_67 ( V_151 , V_53 ) ;
} else {
if ( F_68 ( V_3 ) )
F_8 ( V_3 -> V_10 , L_39 ) ;
V_3 -> V_10 -> V_153 . V_154 ++ ;
}
return V_151 ;
}
static int F_69 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
int V_77 ;
struct V_21 V_22 ;
struct V_6 * V_151 ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
while ( F_70 ( V_7 -> V_53 ) ) {
V_77 = F_14 ( V_7 -> V_4 , V_7 -> V_53 , & V_22 ) ;
if ( V_77 ) {
if ( F_68 ( V_3 ) )
F_8 ( V_3 -> V_10 , L_40 ,
V_77 ) ;
V_3 -> V_10 -> V_153 . V_155 ++ ;
return 0 ;
}
if ( ! V_22 . V_30 . V_16
|| V_22 . V_30 . V_17 != V_156 ) {
if ( F_68 ( V_3 ) )
F_8 ( V_3 -> V_10 , L_41 ) ;
V_3 -> V_10 -> V_153 . V_157 ++ ;
return 0 ;
}
F_66 ( V_7 , V_22 . V_33 ) ;
memcpy ( V_7 -> V_4 , F_1 ( V_3 ) -> V_136 ,
V_11 ) ;
if ( V_22 . V_27 . V_17 == V_7 -> V_53 )
return 1 ;
V_151 = F_64 ( V_3 , V_7 , V_22 . V_27 . V_17 ) ;
if ( V_151 )
F_71 ( V_3 , V_151 ) ;
}
return 0 ;
}
static struct V_6 * F_72 ( struct V_2 * V_3 ,
struct V_6 * V_7 , T_5 V_146 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_53 ;
bool V_158 ;
F_73 ( F_74 ( struct V_2 , V_4 )
< sizeof( struct V_159 ) ) ;
F_20 ( & V_3 -> V_47 -> V_3 , L_3 , V_48 ) ;
if ( V_5 -> V_68 && F_5 ( V_7 , V_3 ) && F_3 ( V_7 ) ) {
if ( V_32 <= F_75 ( V_7 ) ) {
V_53 = V_7 -> V_53 ;
F_76 ( V_7 , V_32 ) ;
V_158 = ( ( V_53 + V_32 )
% V_3 -> V_160 == 0 ) ;
if ( V_158 ) {
if ( F_77 ( F_78 ( V_7 ) == 0 ) ) {
F_8 ( V_3 -> V_10 , L_42
L_43 ) ;
F_79 ( V_7 ) ;
return NULL ;
} else {
V_7 -> V_4 [ V_7 -> V_53 ] = 0 ;
F_80 ( V_7 , 1 ) ;
V_53 = V_53 + 1 ;
}
}
F_15 ( V_7 -> V_4 , V_53 , V_5 ) ;
return V_7 ;
} else {
F_8 ( V_3 -> V_10 , L_44 ) ;
}
}
if ( ! V_5 -> V_68 )
V_3 -> V_10 -> V_153 . V_161 ++ ;
F_79 ( V_7 ) ;
return NULL ;
}
static int
F_81 ( struct V_114 * V_47 , const struct V_162 * V_163 )
{
int V_164 ;
V_164 = F_82 ( V_47 , V_163 ) ;
if ( V_164 == 0 ) {
struct V_2 * V_3 = F_83 ( V_47 ) ;
V_164 = F_84 ( V_3 , V_81 ) ;
if ( V_164 == 0 ) {
F_27 ( V_3 ) ;
}
}
return V_164 ;
}
