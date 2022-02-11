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
return V_7 -> V_8 == F_4 ( V_9 ) ||
V_7 -> V_8 == F_4 ( V_10 ) ;
}
static int F_5 ( struct V_6 * V_7 , struct V_2 * V_3 )
{
F_6 ( V_7 ) ;
if ( F_7 ( V_7 ) ) {
F_8 ( V_3 -> V_11 , L_1 ) ;
return 0 ;
}
if ( ! F_9 ( V_7 , V_12 ) )
return 0 ;
V_7 -> V_8 = F_10 ( V_7 ) -> V_13 ;
return 1 ;
}
static const T_1 * F_11 ( struct V_14 * V_15 , const T_1 * V_16 )
{
V_15 -> V_17 = 1 ;
V_15 -> V_18 = F_12 ( V_16 ) ;
return V_16 + sizeof( V_15 -> V_18 ) ;
}
static const T_1 * F_13 ( struct V_14 * V_15 , const T_1 * V_16 )
{
V_15 -> V_17 = 1 ;
V_15 -> V_19 = * V_16 ;
return V_16 + sizeof( V_15 -> V_19 ) ;
}
static int F_14 ( const T_1 * V_20 , const T_2 V_21 , struct V_22 * V_23 )
{
const T_1 * V_24 = V_20 ;
int V_25 ;
if ( V_21 < V_26 )
return - V_27 ;
V_24 = F_11 ( & V_23 -> V_28 , V_24 ) ;
V_24 = F_13 ( & V_23 -> V_29 , V_24 ) ;
V_24 = F_13 ( & V_23 -> V_30 , V_24 ) ;
V_25 = V_23 -> V_29 . V_19 & 0x80 ;
V_23 -> V_29 . V_19 &= 0x7F ;
V_23 -> V_31 . V_17 = ( V_23 -> V_29 . V_19 == V_32 ) ;
if ( V_23 -> V_31 . V_17 ) {
if ( V_21 < V_33 )
return - V_27 ;
V_23 -> V_28 . V_18 &= 0x3FFF ;
V_24 = F_11 ( & V_23 -> V_31 , V_24 ) ;
V_23 -> V_31 . V_18 &= 0x03FF ;
V_23 -> V_34 = V_33 ;
} else {
V_23 -> V_28 . V_18 &= 0x07FF ;
V_23 -> V_34 = V_26 ;
}
if ( V_25 ) {
V_23 -> V_34 ++ ;
V_23 -> V_28 . V_18 -- ;
}
if ( V_21 < ( V_23 -> V_34 + V_23 -> V_28 . V_18 ) )
return - V_35 ;
return 0 ;
}
static void F_15 ( T_1 * V_20 , const T_3 V_36 ,
struct V_1 * V_5 )
{
F_16 ( V_36 , V_20 ) ;
memcpy ( V_20 + 2 , V_5 -> V_37 , sizeof( V_5 -> V_37 ) ) ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 * V_38 , int V_39 , const char * V_40 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_41 ;
V_41 = F_18 ( V_3 , V_42 ,
V_43 | V_44 | V_45 ,
0 , V_5 -> V_46 , V_38 , V_39 ) ;
if ( V_41 != V_39 && V_41 != - V_47 )
F_8 ( V_3 -> V_11 , L_2 , V_40 , V_41 ) ;
return V_41 ;
}
static int F_19 ( struct V_2 * V_3 )
{
int V_41 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
V_41 = F_17 ( V_3 , V_5 -> V_50 ,
sizeof( V_5 -> V_50 ) , L_4 ) ;
return V_41 ;
}
static void F_21 ( struct V_1 * V_5 , T_1 V_51 )
{
F_20 ( & ( V_5 -> V_2 -> V_48 -> V_3 ) , L_5 , V_49 , V_51 ) ;
V_5 -> V_37 [ 0 ] = 0x3F ;
V_5 -> V_37 [ 1 ] = V_51 ;
* ( ( V_52 * ) & V_5 -> V_37 [ 2 ] ) =
F_4 ( V_53 ) ;
}
static inline int F_22 ( T_1 V_54 )
{
return V_54 == sizeof( struct V_55 ) ;
}
static int F_23 ( struct V_2 * V_3 , char * V_4 , int V_56 )
{
struct V_57 * V_58 = (struct V_57 * ) V_4 ;
T_2 V_59 ;
if ( V_56 < sizeof( struct V_60 ) ) {
F_8 ( V_3 -> V_11 , L_6 ,
V_49 , V_56 , sizeof( struct V_60 ) ) ;
return - 1 ;
}
if ( V_58 -> V_61 == V_62 ) {
F_8 ( V_3 -> V_11 , L_7 ,
V_58 -> V_61 ) ;
return 0 ;
}
if ( V_58 -> V_8 == V_63 ) {
struct V_60 * V_64 = (struct V_60 * ) V_58 ;
if ( V_64 -> V_65 != V_66 &&
V_64 -> V_65 != V_67 ) {
F_8 ( V_3 -> V_11 , L_8 ,
V_64 -> V_65 ) ;
return - 1 ;
}
V_59 = V_68 ;
} else if ( V_58 -> V_8 == V_69 ) {
V_59 = V_70 ;
} else {
F_8 ( V_3 -> V_11 , L_9 ,
V_58 -> V_8 ) ;
return - 1 ;
}
if ( F_24 ( V_58 -> V_71 ) != V_59 ) {
F_8 ( V_3 -> V_11 , L_10 ,
V_49 , F_24 ( V_58 -> V_71 ) , V_59 ) ;
return - 1 ;
}
if ( V_58 -> V_72 == V_73 ||
V_58 -> V_72 == V_74 ) {
F_8 ( V_3 -> V_11 , L_11 , V_58 -> V_72 ) ;
return 0 ;
}
return 1 ;
}
static void F_25 ( struct V_2 * V_3 , char * V_4 ,
struct V_22 * V_23 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_75 ;
V_75 = F_23 ( V_3 , V_4 + V_23 -> V_34 ,
V_23 -> V_28 . V_18 ) ;
if ( V_75 < 0 ) {
F_8 ( V_3 -> V_11 , L_12 ) ;
return;
}
if ( V_75 ) {
F_21 ( V_5 , V_23 -> V_30 . V_19 ) ;
V_5 -> V_75 = 1 ;
} else {
V_5 -> V_75 = 0 ;
}
F_26 ( V_3 , V_75 , 0 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
int V_41 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
V_41 = F_19 ( V_3 ) ;
if ( V_41 < 0 )
F_8 ( V_3 -> V_11 ,
L_13 , V_41 ) ;
V_41 = F_19 ( V_3 ) ;
if ( V_41 < 0 )
F_8 ( V_3 -> V_11 ,
L_13 , V_41 ) ;
V_5 -> V_76 . V_77 = V_78 ;
V_5 -> V_76 . V_4 = ( unsigned long ) V_3 ;
V_5 -> V_76 . V_79 = V_80 + V_81 ;
F_28 ( & V_5 -> V_76 ) ;
}
static void F_29 ( struct V_82 * V_83 )
{
struct V_1 * V_5 =
F_30 ( V_83 , struct V_1 , F_29 ) ;
struct V_2 * V_3 = V_5 -> V_2 ;
int V_54 ;
int V_84 ;
T_1 * V_20 ;
T_1 V_46 ;
if ( F_31 ( V_85 , & V_5 -> V_86 ) ) {
F_32 ( V_85 , & V_5 -> V_86 ) ;
V_20 = F_33 ( V_87 , V_88 ) ;
if ( ! V_20 )
return;
V_46 = V_5 -> V_46 ;
V_54 = F_34 ( V_3 -> V_48 , F_35 ( V_3 -> V_48 , 0 ) ,
V_89 ,
V_90 | V_44 | V_45 ,
0 , V_46 , V_20 , V_87 ,
V_91 ) ;
if ( V_54 < 0 ) {
F_8 ( V_3 -> V_11 ,
L_14 , V_54 ) ;
} else {
struct V_22 V_23 ;
F_20 ( & V_3 -> V_48 -> V_3 , L_15
L_16 , V_49 , V_54 ) ;
V_84 = F_14 ( V_20 , V_54 , & V_23 ) ;
if ( V_84 ) {
F_8 ( V_3 -> V_11 , L_17
L_18 , V_49 , V_84 ) ;
F_36 ( V_20 ) ;
return;
}
if ( V_54 != V_23 . V_34 + V_23 . V_28 . V_18 ) {
F_8 ( V_3 -> V_11 , L_19
L_20 , V_49 , V_54 ,
V_23 . V_34 + V_23 . V_28 . V_18 ) ;
F_36 ( V_20 ) ;
return;
}
switch ( V_23 . V_29 . V_19 ) {
case V_92 :
F_20 ( & V_3 -> V_48 -> V_3 , L_21 ,
V_23 . V_30 . V_19 ) ;
F_25 ( V_3 , V_20 , & V_23 ) ;
break;
case V_93 :
F_20 ( & V_3 -> V_48 -> V_3 , L_22
L_23 ,
V_23 . V_30 . V_19 ) ;
F_37 ( & V_5 -> V_76 ) ;
F_32 ( V_94 ,
& V_5 -> V_86 ) ;
break;
case V_95 :
F_20 ( & V_3 -> V_48 -> V_3 , L_24 ) ;
V_84 = F_19 ( V_3 ) ;
if ( V_84 < 0 )
F_8 ( V_3 -> V_11 ,
L_25 , V_84 ) ;
break;
case V_32 :
F_8 ( V_3 -> V_11 , L_26
L_27 , V_23 . V_31 . V_18 ) ;
break;
case V_96 :
break;
default:
F_8 ( V_3 -> V_11 , L_26
L_28 , V_23 . V_29 . V_19 ) ;
break;
}
}
F_36 ( V_20 ) ;
}
if ( F_31 ( V_94 , & V_5 -> V_86 ) ) {
F_32 ( V_94 , & V_5 -> V_86 ) ;
F_20 ( & V_3 -> V_48 -> V_3 , L_29 ) ;
F_27 ( V_5 -> V_2 ) ;
}
if ( V_5 -> V_86 )
F_20 ( & V_3 -> V_48 -> V_3 , L_30
L_31 , V_5 -> V_86 ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_83 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_39 ( V_83 , & V_5 -> V_86 ) ;
F_40 ( & V_5 -> F_29 ) ;
}
static void V_78 ( unsigned long V_97 )
{
struct V_2 * V_3 = (struct V_2 * ) V_97 ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
F_38 ( V_3 , V_94 ) ;
}
static void F_41 ( struct V_2 * V_3 , struct V_98 * V_98 )
{
struct V_99 * V_100 ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
if ( V_98 -> V_101 < sizeof *V_100 )
return;
V_100 = V_98 -> V_102 ;
switch ( V_100 -> V_103 ) {
case V_104 :
case V_105 :
break;
case V_106 :
F_38 ( V_3 , V_85 ) ;
break;
default:
F_8 ( V_3 -> V_11 , L_32 ,
V_100 -> V_103 ) ;
break;
}
}
static void F_42 ( struct V_107 * V_11 ,
struct V_108 * V_109 )
{
F_43 ( V_11 , V_109 ) ;
F_44 ( V_109 -> V_110 , V_111 , sizeof( V_109 -> V_110 ) ) ;
F_44 ( V_109 -> V_112 , V_113 , sizeof( V_109 -> V_112 ) ) ;
}
static T_2 F_45 ( struct V_107 * V_11 )
{
struct V_2 * V_3 = F_46 ( V_11 ) ;
return F_1 ( V_3 ) -> V_75 && F_47 ( V_11 ) ;
}
static int F_48 ( struct V_2 * V_3 , T_3 * V_16 )
{
int V_114 = 0 ;
T_4 V_115 ;
V_114 = F_49 ( V_3 ,
V_116 ,
V_90 | V_117 ,
0x0000 ,
0x0000 ,
& V_115 ,
sizeof( V_115 )
) ;
if ( V_114 < 0 )
return - V_118 ;
* V_16 = F_50 ( V_115 ) ;
return V_114 ;
}
static int F_51 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
T_1 V_121 ;
T_1 V_122 ;
T_3 V_123 = 0 ;
int V_41 ;
struct V_1 * V_5 ;
static const T_1 V_124 [ sizeof( V_5 -> V_50 ) ] = {
0x00 , 0x00 , V_125 , 0x00 } ;
static const T_1 V_126 [ sizeof( V_5 -> V_127 ) ] = {
0x00 , 0x00 , V_128 , 0x00 } ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
V_121 = V_120 -> V_129 -> V_130 . V_131 ;
V_122 = V_120 -> V_129 -> V_130 . V_132 ;
if ( V_122 != 3 ) {
F_52 ( & V_3 -> V_48 -> V_3 , L_33 ,
V_122 ) ;
return - V_47 ;
}
V_3 -> V_41 = NULL ;
V_41 = F_53 ( V_3 , V_120 ) ;
if ( V_41 < 0 ) {
F_52 ( & V_3 -> V_48 -> V_3 , L_34 ,
V_41 ) ;
return - V_47 ;
}
V_5 = F_33 ( sizeof *V_5 , V_88 ) ;
if ( ! V_5 )
return - V_133 ;
V_5 -> V_2 = V_3 ;
V_5 -> V_46 = V_121 ;
V_3 -> V_11 -> V_134 = & V_135 ;
V_3 -> V_11 -> V_136 [ V_137 - 2 ] = F_54 ( & V_138 ) ;
V_3 -> V_11 -> V_136 [ V_137 - 1 ] = V_121 ;
memcpy ( V_5 -> V_127 , V_126 , sizeof( V_5 -> V_127 ) ) ;
F_21 ( V_5 , 0 ) ;
memcpy ( V_5 -> V_50 , V_124 , sizeof( V_5 -> V_50 ) ) ;
V_3 -> V_139 = V_140 ;
if ( V_3 -> V_48 -> V_141 != V_142 )
V_3 -> V_139 = F_55 ( V_143 , 4096 , V_140 ) ;
V_3 -> V_11 -> V_144 += V_33 ;
V_3 -> V_145 = V_3 -> V_11 -> V_146 + V_3 -> V_11 -> V_144 ;
V_3 -> V_11 -> V_147 = V_148 ;
V_3 -> V_11 -> V_149 |= V_150 ;
V_3 -> V_11 -> V_151 = & V_152 ;
F_56 ( V_3 -> V_11 ) ;
F_2 ( V_3 , V_5 ) ;
V_5 -> V_86 = 0 ;
F_57 ( & V_5 -> F_29 , F_29 ) ;
F_58 ( & V_5 -> V_76 ) ;
V_41 = F_48 ( V_3 , & V_123 ) ;
F_20 ( & V_3 -> V_48 -> V_3 , L_35 , V_123 ) ;
if ( ! ( V_41 == sizeof( V_123 ) && ( V_123 & V_153 ) ) ) {
F_52 ( & V_3 -> V_48 -> V_3 , L_36
L_37 ) ;
F_36 ( V_5 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_59 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
int V_41 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
F_37 ( & V_5 -> V_76 ) ;
F_60 ( & V_5 -> F_29 ) ;
V_41 = F_17 ( V_3 , V_5 -> V_127 ,
sizeof( V_5 -> V_127 ) , L_38 ) ;
if ( V_41 < 0 )
F_8 ( V_3 -> V_11 ,
L_14 , V_41 ) ;
F_61 ( V_3 ) ;
F_2 ( V_3 , NULL ) ;
F_36 ( V_5 ) ;
}
static struct V_6 * F_62 ( struct V_2 * V_3 ,
struct V_6 * V_7 , int V_54 )
{
struct V_6 * V_154 ;
V_154 = F_63 ( V_7 , V_155 ) ;
F_64 ( V_7 , V_54 ) ;
if ( V_154 ) {
F_65 ( V_154 , V_54 ) ;
} else {
if ( F_66 ( V_3 ) )
F_8 ( V_3 -> V_11 , L_39 ) ;
V_3 -> V_11 -> V_156 . V_157 ++ ;
}
return V_154 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
int V_84 ;
struct V_22 V_23 ;
struct V_6 * V_154 ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
while ( F_68 ( V_7 -> V_54 ) ) {
V_84 = F_14 ( V_7 -> V_4 , V_7 -> V_54 , & V_23 ) ;
if ( V_84 ) {
if ( F_66 ( V_3 ) )
F_8 ( V_3 -> V_11 , L_40 ,
V_84 ) ;
V_3 -> V_11 -> V_156 . V_158 ++ ;
return 0 ;
}
if ( ! V_23 . V_31 . V_17
|| V_23 . V_31 . V_18 != V_159 ) {
if ( F_66 ( V_3 ) )
F_8 ( V_3 -> V_11 , L_41 ) ;
V_3 -> V_11 -> V_156 . V_160 ++ ;
return 0 ;
}
F_64 ( V_7 , V_23 . V_34 ) ;
F_6 ( V_7 ) ;
if ( F_10 ( V_7 ) -> V_13 != F_4 ( V_10 ) )
F_10 ( V_7 ) -> V_13 = F_4 ( V_9 ) ;
F_69 ( F_10 ( V_7 ) -> V_161 ) ;
memcpy ( F_10 ( V_7 ) -> V_162 , V_3 -> V_11 -> V_136 , V_137 ) ;
if ( V_23 . V_28 . V_18 == V_7 -> V_54 )
return 1 ;
V_154 = F_62 ( V_3 , V_7 , V_23 . V_28 . V_18 ) ;
if ( V_154 )
F_70 ( V_3 , V_154 ) ;
}
return 0 ;
}
static struct V_6 * F_71 ( struct V_2 * V_3 ,
struct V_6 * V_7 , T_5 V_149 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_54 ;
bool V_163 ;
F_72 ( F_73 ( struct V_2 , V_4 )
< sizeof( struct V_164 ) ) ;
F_20 ( & V_3 -> V_48 -> V_3 , L_3 , V_49 ) ;
if ( V_5 -> V_75 && F_5 ( V_7 , V_3 ) && F_3 ( V_7 ) ) {
if ( V_33 <= F_74 ( V_7 ) ) {
V_54 = V_7 -> V_54 ;
F_75 ( V_7 , V_33 ) ;
V_163 = ( ( V_54 + V_33 )
% V_3 -> V_165 == 0 ) ;
if ( V_163 ) {
if ( F_76 ( F_77 ( V_7 ) == 0 ) ) {
F_8 ( V_3 -> V_11 , L_42
L_43 ) ;
F_78 ( V_7 ) ;
return NULL ;
} else {
V_7 -> V_4 [ V_7 -> V_54 ] = 0 ;
F_79 ( V_7 , 1 ) ;
V_54 = V_54 + 1 ;
}
}
F_15 ( V_7 -> V_4 , V_54 , V_5 ) ;
return V_7 ;
} else {
F_8 ( V_3 -> V_11 , L_44 ) ;
}
}
if ( ! V_5 -> V_75 )
V_3 -> V_11 -> V_156 . V_166 ++ ;
F_78 ( V_7 ) ;
return NULL ;
}
static int
F_80 ( struct V_119 * V_48 , const struct V_167 * V_168 )
{
int V_169 ;
V_169 = F_81 ( V_48 , V_168 ) ;
if ( V_169 == 0 ) {
struct V_2 * V_3 = F_82 ( V_48 ) ;
V_169 = F_83 ( V_3 , V_88 ) ;
if ( V_169 == 0 ) {
F_27 ( V_3 ) ;
}
}
return V_169 ;
}
