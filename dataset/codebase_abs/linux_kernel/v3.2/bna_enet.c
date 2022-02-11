static inline int
F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_4 -> V_5 . type == V_6 )
V_3 = ( ( V_2 -> V_7 & V_8 ) &&
( V_2 -> V_7 & V_9 ) &&
( V_2 -> V_7 & V_10 ) ) ;
else
V_3 = ( ( V_2 -> V_7 & V_8 ) &&
( V_2 -> V_7 & V_9 ) &&
! ( V_2 -> V_7 & V_10 ) ) ;
return V_3 ;
}
static void
F_2 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_2 -> V_7 |= V_10 ;
if ( F_1 ( V_2 ) )
F_3 ( V_2 , V_13 ) ;
}
static void
F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_14 = F_5 ( V_2 ) ;
V_2 -> V_7 &= ~ V_10 ;
if ( V_14 )
F_3 ( V_2 , V_15 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_16 * V_17 =
& V_2 -> V_18 . V_17 ;
struct V_19 * V_20 = (struct V_19 * ) V_12 ;
switch ( V_17 -> V_21 ) {
case V_22 :
if ( V_20 -> error == V_23 )
F_3 ( V_2 , V_24 ) ;
else {
V_2 -> V_7 &= ~ V_10 ;
F_3 ( V_2 , V_25 ) ;
}
break;
case V_26 :
F_3 ( V_2 , V_27 ) ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 ( V_2 -> V_4 -> V_31 , V_29 ) ;
break;
}
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_32 * V_33 =
& V_2 -> V_18 . V_34 ;
struct V_19 * V_20 = (struct V_19 * ) V_12 ;
switch ( V_33 -> V_21 ) {
case V_22 :
if ( V_20 -> error == V_23 )
F_3 ( V_2 , V_24 ) ;
else {
V_2 -> V_7 &= ~ V_8 ;
F_3 ( V_2 , V_25 ) ;
}
break;
case V_26 :
F_3 ( V_2 , V_27 ) ;
break;
}
}
static void
F_8 ( struct V_35 * V_5 , struct V_11 * V_12 )
{
F_3 ( V_5 , V_36 ) ;
}
static void
F_9 ( struct V_37 * V_38 ,
struct V_11 * V_12 )
{
struct V_39 * V_20 = (struct V_39 * ) V_12 ;
if ( ! V_38 -> V_40 . V_41 ) {
V_38 -> V_40 . V_42 = F_10 ( V_20 -> V_43 ) ;
V_38 -> V_40 . V_44 = F_10 ( V_20 -> V_43 ) ;
V_38 -> V_40 . V_45 = F_10 ( V_20 -> V_46 ) ;
V_38 -> V_40 . V_47 = V_48 ;
V_38 -> V_40 . V_49 = F_10 ( V_20 -> V_50 ) ;
V_38 -> V_40 . V_41 = true ;
}
F_3 ( V_38 , V_51 ) ;
}
static void
F_11 ( struct V_4 * V_4 , struct V_11 * V_12 )
{
struct V_52 * V_53 = & V_4 -> V_54 . V_55 ;
T_1 * V_56 ;
T_1 * V_57 ;
T_2 V_58 = F_10 ( V_53 -> V_58 ) ;
T_2 V_59 = F_10 ( V_53 -> V_59 ) ;
int V_60 ;
int V_61 ;
F_12 ( V_62 , V_62 ) ;
F_12 ( V_63 , V_63 ) ;
F_12 ( V_64 , V_64 ) ;
F_12 ( V_65 , V_64 ) ;
F_12 ( V_66 , V_66 ) ;
F_12 ( V_67 , V_67 ) ;
V_56 = ( T_1 * ) & ( V_4 -> V_68 . V_69 -> V_70 [ 0 ] ) ;
for ( V_61 = 0 ; V_61 < V_71 ; V_61 ++ ) {
V_57 = ( T_1 * ) & ( V_4 -> V_68 . V_72 . V_70 [ V_61 ] ) ;
memset ( V_57 , 0 , sizeof( struct V_73 ) ) ;
if ( V_59 & ( ( T_2 ) ( 1 << V_61 ) ) ) {
int V_74 ;
V_60 = sizeof( struct V_73 ) /
sizeof( T_1 ) ;
for ( V_74 = 0 ; V_74 < V_60 ; V_74 ++ ) {
V_57 [ V_74 ] = F_13 ( * V_56 ) ;
V_56 ++ ;
}
}
}
for ( V_61 = 0 ; V_61 < V_71 ; V_61 ++ ) {
V_57 = ( T_1 * ) & ( V_4 -> V_68 . V_72 . V_75 [ V_61 ] ) ;
memset ( V_57 , 0 , sizeof( struct V_76 ) ) ;
if ( V_58 & ( ( T_2 ) ( 1 << V_61 ) ) ) {
int V_74 ;
V_60 = sizeof( struct V_76 ) /
sizeof( T_1 ) ;
for ( V_74 = 0 ; V_74 < V_60 ; V_74 ++ ) {
V_57 [ V_74 ] = F_13 ( * V_56 ) ;
V_56 ++ ;
}
}
}
V_4 -> V_54 . V_77 = false ;
F_14 ( V_4 -> V_31 , V_78 , & V_4 -> V_68 ) ;
}
static void
F_15 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_2 -> V_28 = V_79 ;
V_2 -> V_30 ( V_2 -> V_4 -> V_31 , V_2 -> V_28 ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_2 -> V_28 = V_29 ;
V_2 -> V_30 ( V_2 -> V_4 -> V_31 , V_29 ) ;
}
static void
F_17 ( struct V_4 * V_4 , T_2 V_80 )
{
if ( F_18 ( V_4 , V_80 ) )
F_19 ( V_4 ) ;
F_20 ( & V_4 -> V_38 . V_81 ) ;
}
void
F_21 ( struct V_4 * V_4 , T_2 V_80 )
{
if ( F_22 ( V_4 , V_80 ) ) {
F_17 ( V_4 , V_80 ) ;
return;
}
if ( F_23 ( V_4 , V_80 ) )
F_24 ( & V_4 -> V_38 . V_81 ) ;
}
static void
F_25 ( void * V_82 , struct V_11 * V_12 )
{
struct V_4 * V_4 = (struct V_4 * ) V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
switch ( V_12 -> V_87 ) {
case V_88 :
F_26 ( V_4 , V_12 -> V_89 , V_86 ) ;
if ( V_86 )
F_27 ( V_86 , V_12 ) ;
break;
case V_90 :
F_26 ( V_4 , V_12 -> V_89 , V_86 ) ;
if ( V_86 )
F_28 ( V_86 , V_12 ) ;
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
F_26 ( V_4 , V_12 -> V_89 , V_86 ) ;
if ( V_86 )
F_29 ( & V_86 -> V_104 , V_12 ) ;
break;
case V_105 :
F_26 ( V_4 , V_12 -> V_89 , V_86 ) ;
if ( V_86 )
F_30 ( & V_86 -> V_104 , V_12 ) ;
break;
case V_106 :
F_31 ( V_4 , V_12 -> V_89 , V_84 ) ;
if ( V_84 )
F_32 ( V_84 , V_12 ) ;
break;
case V_107 :
F_31 ( V_4 , V_12 -> V_89 , V_84 ) ;
if ( V_84 )
F_33 ( V_84 , V_12 ) ;
break;
case V_108 :
F_6 ( & V_4 -> V_2 , V_12 ) ;
break;
case V_109 :
F_7 ( & V_4 -> V_2 , V_12 ) ;
break;
case V_110 :
F_8 ( & V_4 -> V_5 , V_12 ) ;
break;
case V_111 :
F_9 ( & V_4 -> V_38 , V_12 ) ;
break;
case V_112 :
F_11 ( V_4 , V_12 ) ;
break;
case V_113 :
break;
case V_114 :
F_15 ( & V_4 -> V_2 , V_12 ) ;
break;
case V_115 :
F_16 ( & V_4 -> V_2 , V_12 ) ;
break;
case V_116 :
F_2 ( & V_4 -> V_2 , V_12 ) ;
break;
case V_117 :
F_4 ( & V_4 -> V_2 , V_12 ) ;
break;
case V_118 :
F_34 ( & V_4 -> V_119 ) ;
break;
default:
break;
}
}
static void
F_35 ( struct V_1 * V_2 )
{
struct V_16 * V_120 =
& V_2 -> V_18 . V_17 ;
F_36 ( V_120 -> V_121 , V_122 ,
V_123 , 0 , 0 ) ;
V_120 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_16 ) ) ) ;
V_120 -> V_21 = V_22 ;
F_39 ( & V_2 -> V_125 , NULL , NULL ,
sizeof( struct V_16 ) , & V_120 -> V_121 ) ;
F_40 ( & V_2 -> V_4 -> V_126 , & V_2 -> V_125 ) ;
}
static void
F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_127 =
& V_2 -> V_18 . V_17 ;
F_36 ( V_127 -> V_121 , V_122 ,
V_123 , 0 , 0 ) ;
V_127 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_16 ) ) ) ;
V_127 -> V_21 = V_26 ;
F_39 ( & V_2 -> V_125 , NULL , NULL ,
sizeof( struct V_16 ) , & V_127 -> V_121 ) ;
F_40 ( & V_2 -> V_4 -> V_126 , & V_2 -> V_125 ) ;
}
static void
F_42 ( struct V_1 * V_2 )
{
struct V_32 * V_128 =
& V_2 -> V_18 . V_34 ;
F_36 ( V_128 -> V_121 , V_122 ,
V_129 , 0 , 0 ) ;
V_128 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_32 ) ) ) ;
V_128 -> V_130 = ( V_2 -> V_4 -> V_5 . type ==
V_131 ) ?
V_132 :
V_133 ;
V_128 -> V_21 = V_22 ;
F_39 ( & V_2 -> V_125 , NULL , NULL ,
sizeof( struct V_32 ) , & V_128 -> V_121 ) ;
F_40 ( & V_2 -> V_4 -> V_126 , & V_2 -> V_125 ) ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_32 * V_134 =
& V_2 -> V_18 . V_34 ;
F_36 ( V_134 -> V_121 , V_122 ,
V_129 , 0 , 0 ) ;
V_134 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_32 ) ) ) ;
V_134 -> V_21 = V_26 ;
F_39 ( & V_2 -> V_125 , NULL , NULL ,
sizeof( struct V_32 ) , & V_134 -> V_121 ) ;
F_40 ( & V_2 -> V_4 -> V_126 , & V_2 -> V_125 ) ;
}
static void
F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . type == V_6 )
F_35 ( V_2 ) ;
else
F_42 ( V_2 ) ;
}
static void
F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . type == V_6 )
F_41 ( V_2 ) ;
else
F_43 ( V_2 ) ;
}
static void
F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
}
static void
F_48 ( struct V_1 * V_2 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_137 :
F_49 ( V_2 , V_138 ) ;
break;
case V_139 :
F_47 ( V_2 ) ;
break;
case V_140 :
break;
case V_15 :
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_51 ( struct V_1 * V_2 )
{
}
static void
V_138 ( struct V_1 * V_2 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_139 :
F_49 ( V_2 , F_48 ) ;
break;
case V_140 :
F_49 ( V_2 , F_48 ) ;
break;
case V_13 :
F_49 ( V_2 , V_141 ) ;
F_44 ( V_2 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_52 ( struct V_1 * V_2 )
{
}
static void
V_141 ( struct V_1 * V_2 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_139 :
F_49 ( V_2 , V_142 ) ;
break;
case V_140 :
F_53 ( V_2 , V_143 ) ;
F_49 ( V_2 , F_48 ) ;
break;
case V_15 :
F_53 ( V_2 , V_144 ) ;
F_49 ( V_2 , V_145 ) ;
break;
case V_24 :
F_53 ( V_2 , V_78 ) ;
F_49 ( V_2 , V_146 ) ;
break;
case V_25 :
F_53 ( V_2 , V_143 ) ;
F_49 ( V_2 , V_138 ) ;
break;
case V_27 :
F_44 ( V_2 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_54 ( struct V_1 * V_2 )
{
}
static void
V_145 ( struct V_1 * V_2 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_139 :
F_49 ( V_2 , V_142 ) ;
break;
case V_140 :
F_49 ( V_2 , F_48 ) ;
break;
case V_13 :
F_49 ( V_2 , V_141 ) ;
break;
case V_24 :
F_45 ( V_2 ) ;
break;
case V_25 :
case V_27 :
F_49 ( V_2 , V_138 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_55 ( struct V_1 * V_2 )
{
}
static void
V_146 ( struct V_1 * V_2 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_139 :
F_49 ( V_2 , V_142 ) ;
F_45 ( V_2 ) ;
break;
case V_140 :
F_49 ( V_2 , F_48 ) ;
break;
case V_15 :
F_49 ( V_2 , V_145 ) ;
F_45 ( V_2 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_56 ( struct V_1 * V_2 )
{
}
static void
V_142 ( struct V_1 * V_2 ,
enum V_135 V_136 )
{
switch ( V_136 ) {
case V_140 :
F_49 ( V_2 , F_48 ) ;
break;
case V_15 :
break;
case V_24 :
F_45 ( V_2 ) ;
break;
case V_25 :
case V_27 :
F_49 ( V_2 , F_48 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_57 ( struct V_1 * V_2 , struct V_4 * V_4 )
{
V_2 -> V_7 |= ( V_8 | V_10 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_147 ;
V_2 -> V_148 = 0 ;
V_2 -> V_149 = NULL ;
V_2 -> V_150 = NULL ;
F_49 ( V_2 , F_48 ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
V_2 -> V_7 &= ~ V_8 ;
V_2 -> V_7 &= ~ V_10 ;
V_2 -> V_4 = NULL ;
}
static void
F_59 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_137 ) ;
}
static void
F_60 ( struct V_35 * V_5 )
{
F_61 ( & V_5 -> V_151 ) ;
}
static void
F_62 ( struct V_1 * V_2 )
{
V_2 -> V_149 = F_60 ;
F_3 ( V_2 , V_139 ) ;
}
static void
F_63 ( struct V_1 * V_2 )
{
V_2 -> V_7 |= V_10 ;
if ( V_2 -> V_28 != V_29 ) {
V_2 -> V_28 = V_29 ;
V_2 -> V_30 ( V_2 -> V_4 -> V_31 , V_29 ) ;
}
F_3 ( V_2 , V_140 ) ;
}
void
F_64 ( struct V_1 * V_2 )
{
V_2 -> V_148 ++ ;
if ( V_2 -> V_148 == 1 ) {
V_2 -> V_7 |= V_9 ;
if ( F_1 ( V_2 ) )
F_3 ( V_2 , V_13 ) ;
}
}
void
F_65 ( struct V_1 * V_2 )
{
int V_14 = F_5 ( V_2 ) ;
V_2 -> V_148 -- ;
if ( V_2 -> V_148 == 0 ) {
V_2 -> V_7 &= ~ V_9 ;
if ( V_14 )
F_3 ( V_2 , V_15 ) ;
}
}
static void
F_66 ( struct V_35 * V_5 )
{
F_67 ( V_5 ) ;
F_68 ( V_5 ) ;
F_69 ( V_5 ) ;
}
static void
F_70 ( struct V_35 * V_5 , enum V_152 V_136 )
{
switch ( V_136 ) {
case V_153 :
F_49 ( V_5 , V_154 ) ;
break;
case V_155 :
F_69 ( V_5 ) ;
break;
case V_156 :
break;
case V_157 :
F_67 ( V_5 ) ;
break;
case V_158 :
F_68 ( V_5 ) ;
break;
case V_159 :
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_71 ( struct V_35 * V_5 )
{
F_72 ( V_5 ) ;
}
static void
V_154 ( struct V_35 * V_5 ,
enum V_152 V_136 )
{
switch ( V_136 ) {
case V_155 :
V_5 -> V_7 &= ~ V_160 ;
F_49 ( V_5 , V_161 ) ;
break;
case V_156 :
V_5 -> V_7 &= ~ V_160 ;
F_49 ( V_5 , F_70 ) ;
break;
case V_157 :
V_5 -> V_7 |= V_160 ;
break;
case V_158 :
break;
case V_36 :
if ( V_5 -> V_7 & V_160 ) {
V_5 -> V_7 &= ~ V_160 ;
F_72 ( V_5 ) ;
} else {
F_49 ( V_5 , V_162 ) ;
F_73 ( V_5 ) ;
}
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_74 ( struct V_35 * V_5 )
{
V_5 -> V_7 &= ~ V_160 ;
}
static void
V_161 ( struct V_35 * V_5 ,
enum V_152 V_136 )
{
switch ( V_136 ) {
case V_156 :
case V_36 :
F_49 ( V_5 , F_70 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_75 ( struct V_35 * V_5 )
{
F_67 ( V_5 ) ;
F_68 ( V_5 ) ;
}
static void
V_162 ( struct V_35 * V_5 ,
enum V_152 V_136 )
{
switch ( V_136 ) {
case V_155 :
F_49 ( V_5 , V_163 ) ;
break;
case V_156 :
F_49 ( V_5 , F_70 ) ;
F_76 ( V_5 ) ;
break;
case V_157 :
F_49 ( V_5 , V_164 ) ;
F_72 ( V_5 ) ;
break;
case V_158 :
F_49 ( V_5 , V_164 ) ;
F_77 ( V_5 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_78 ( struct V_35 * V_5 )
{
}
static void
V_164 ( struct V_35 * V_5 ,
enum V_152 V_136 )
{
switch ( V_136 ) {
case V_155 :
V_5 -> V_7 &= ~ V_160 ;
V_5 -> V_7 &= ~ V_165 ;
F_49 ( V_5 , V_166 ) ;
break;
case V_156 :
V_5 -> V_7 &= ~ V_160 ;
V_5 -> V_7 &= ~ V_165 ;
F_49 ( V_5 , F_70 ) ;
F_76 ( V_5 ) ;
break;
case V_157 :
V_5 -> V_7 |= V_160 ;
break;
case V_158 :
V_5 -> V_7 |= V_165 ;
break;
case V_159 :
F_79 ( V_5 ) ;
case V_36 :
if ( V_5 -> V_7 & V_160 ) {
V_5 -> V_7 &= ~ V_160 ;
F_72 ( V_5 ) ;
} else if ( V_5 -> V_7 & V_165 ) {
V_5 -> V_7 &= ~ V_165 ;
F_77 ( V_5 ) ;
} else {
F_49 ( V_5 , V_162 ) ;
}
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_80 ( struct V_35 * V_5 )
{
V_5 -> V_7 &= ~ V_160 ;
V_5 -> V_7 &= ~ V_165 ;
}
static void
V_166 ( struct V_35 * V_5 ,
enum V_152 V_136 )
{
switch ( V_136 ) {
case V_156 :
F_49 ( V_5 , F_70 ) ;
F_76 ( V_5 ) ;
break;
case V_36 :
case V_159 :
F_49 ( V_5 , V_163 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_81 ( struct V_35 * V_5 )
{
F_82 ( V_5 ) ;
}
static void
V_163 ( struct V_35 * V_5 ,
enum V_152 V_136 )
{
switch ( V_136 ) {
case V_156 :
F_49 ( V_5 , F_70 ) ;
F_76 ( V_5 ) ;
break;
case V_159 :
F_49 ( V_5 , F_70 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_72 ( struct V_35 * V_5 )
{
struct V_167 * V_168 = & V_5 -> V_168 ;
F_36 ( V_168 -> V_121 , V_122 ,
V_169 , 0 , 0 ) ;
V_168 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_167 ) ) ) ;
V_168 -> V_170 = V_5 -> V_171 . V_170 ;
V_168 -> V_172 = V_5 -> V_171 . V_172 ;
F_39 ( & V_5 -> V_125 , NULL , NULL ,
sizeof( struct V_167 ) , & V_168 -> V_121 ) ;
F_40 ( & V_5 -> V_4 -> V_126 , & V_5 -> V_125 ) ;
}
static void
F_83 ( void * V_82 )
{
struct V_35 * V_5 = (struct V_35 * ) V_82 ;
F_3 ( V_5 , V_159 ) ;
}
static void
F_84 ( struct V_35 * V_5 , struct V_4 * V_4 )
{
V_5 -> V_4 = V_4 ;
V_5 -> V_7 = 0 ;
V_5 -> V_173 = 0 ;
V_5 -> type = V_6 ;
V_5 -> V_149 = NULL ;
V_5 -> V_174 = NULL ;
V_5 -> V_175 = NULL ;
V_5 -> V_176 = NULL ;
F_49 ( V_5 , F_70 ) ;
}
static void
F_85 ( struct V_35 * V_5 )
{
V_5 -> V_7 = 0 ;
V_5 -> V_4 = NULL ;
}
static void
F_86 ( struct V_35 * V_5 )
{
V_5 -> V_7 |= V_177 ;
if ( V_5 -> V_7 & V_178 )
F_3 ( V_5 , V_153 ) ;
}
static void
F_87 ( void * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
F_3 ( V_38 , V_179 ) ;
}
static void
F_88 ( struct V_35 * V_5 )
{
V_5 -> V_149 = F_87 ;
V_5 -> V_174 = & V_5 -> V_4 -> V_38 ;
V_5 -> V_7 &= ~ V_177 ;
F_3 ( V_5 , V_155 ) ;
}
static void
F_89 ( struct V_35 * V_5 )
{
V_5 -> V_7 &= ~ V_177 ;
F_3 ( V_5 , V_156 ) ;
}
void
F_90 ( struct V_35 * V_5 )
{
F_61 ( & V_5 -> V_151 ) ;
}
void
F_91 ( struct V_35 * V_5 )
{
F_61 ( & V_5 -> V_151 ) ;
}
int
F_92 ( struct V_35 * V_5 )
{
return V_5 -> V_173 ;
}
void
F_93 ( struct V_35 * V_5 )
{
if ( V_5 -> V_180 != ( V_181 ) F_70 )
return;
V_5 -> V_7 |= V_178 ;
if ( V_5 -> V_7 & V_177 )
F_3 ( V_5 , V_153 ) ;
}
void
F_94 ( struct V_35 * V_5 , enum V_182 type ,
void (* F_95)( void * ) )
{
if ( type == V_183 ) {
(* F_95)( V_5 -> V_4 -> V_31 ) ;
return;
}
V_5 -> V_149 = F_95 ;
V_5 -> V_174 = V_5 -> V_4 -> V_31 ;
V_5 -> V_7 &= ~ V_178 ;
F_3 ( V_5 , V_155 ) ;
}
void
F_96 ( struct V_35 * V_5 ,
struct V_184 * V_171 ,
void (* F_95)( struct V_31 * ) )
{
V_5 -> V_171 = * V_171 ;
V_5 -> V_175 = F_95 ;
F_3 ( V_5 , V_157 ) ;
}
void
F_97 ( struct V_35 * V_5 , int V_173 ,
void (* F_95)( struct V_31 * ) )
{
V_5 -> V_173 = V_173 ;
V_5 -> V_176 = F_95 ;
F_3 ( V_5 , V_158 ) ;
}
void
F_98 ( struct V_35 * V_5 , T_3 * V_62 )
{
* V_62 = F_99 ( & V_5 -> V_4 -> V_38 . V_81 ) ;
}
static void
F_100 ( struct V_37 * V_38 )
{
F_101 ( V_38 ) ;
}
static void
F_102 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_186 :
F_49 ( V_38 , V_187 ) ;
F_103 ( & V_38 -> V_81 ) ;
break;
case V_188 :
F_49 ( V_38 , F_102 ) ;
break;
case V_189 :
F_104 ( V_38 ) ;
break;
case V_190 :
F_105 ( V_38 ) ;
F_49 ( V_38 , V_191 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_106 ( struct V_37 * V_38 )
{
}
static void
V_187 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_188 :
F_49 ( V_38 , V_192 ) ;
F_107 ( & V_38 -> V_81 ) ;
break;
case V_189 :
F_104 ( V_38 ) ;
break;
case V_190 :
F_105 ( V_38 ) ;
F_49 ( V_38 , V_191 ) ;
break;
case V_193 :
F_49 ( V_38 , V_194 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_108 ( struct V_37 * V_38 )
{
F_109 ( V_38 ) ;
}
static void
V_194 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_188 :
F_49 ( V_38 , V_195 ) ;
break;
case V_190 :
F_105 ( V_38 ) ;
F_49 ( V_38 , V_191 ) ;
break;
case V_51 :
F_49 ( V_38 , V_196 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_110 ( struct V_37 * V_38 )
{
F_86 ( & V_38 -> V_4 -> V_5 ) ;
F_111 ( & V_38 -> V_4 -> V_54 ) ;
F_112 ( V_38 -> V_4 -> V_31 ) ;
}
static void
V_196 ( struct V_37 * V_38 , enum V_185 V_136 )
{
switch ( V_136 ) {
case V_188 :
F_49 ( V_38 , V_197 ) ;
break;
case V_190 :
F_105 ( V_38 ) ;
F_89 ( & V_38 -> V_4 -> V_5 ) ;
F_113 ( & V_38 -> V_4 -> V_54 ) ;
F_49 ( V_38 , V_191 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_114 ( struct V_37 * V_38 )
{
}
static void
V_195 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_190 :
F_49 ( V_38 , V_192 ) ;
F_105 ( V_38 ) ;
F_107 ( & V_38 -> V_81 ) ;
break;
case V_51 :
F_49 ( V_38 , V_192 ) ;
F_107 ( & V_38 -> V_81 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_115 ( struct V_37 * V_38 )
{
F_116 ( & V_38 -> V_4 -> V_54 ) ;
F_88 ( & V_38 -> V_4 -> V_5 ) ;
}
static void
V_197 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_190 :
F_49 ( V_38 , V_192 ) ;
F_105 ( V_38 ) ;
F_89 ( & V_38 -> V_4 -> V_5 ) ;
F_113 ( & V_38 -> V_4 -> V_54 ) ;
F_107 ( & V_38 -> V_81 ) ;
break;
case V_179 :
F_49 ( V_38 , V_192 ) ;
F_107 ( & V_38 -> V_81 ) ;
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_117 ( struct V_37 * V_38 )
{
}
static void
V_192 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_198 :
F_105 ( V_38 ) ;
F_49 ( V_38 , F_102 ) ;
break;
case V_179 :
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_118 ( struct V_37 * V_38 )
{
F_119 ( V_38 -> V_4 -> V_31 ) ;
}
static void
V_191 ( struct V_37 * V_38 ,
enum V_185 V_136 )
{
switch ( V_136 ) {
case V_188 :
F_49 ( V_38 , V_192 ) ;
F_107 ( & V_38 -> V_81 ) ;
break;
case V_189 :
F_104 ( V_38 ) ;
F_49 ( V_38 , V_187 ) ;
break;
case V_190 :
break;
default:
F_50 ( V_136 ) ;
}
}
static void
F_109 ( struct V_37 * V_38 )
{
struct V_199 * V_200 = & V_38 -> V_200 ;
F_36 ( V_200 -> V_121 , V_122 ,
V_201 , 0 , 0 ) ;
V_200 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_199 ) ) ) ;
F_39 ( & V_38 -> V_125 , NULL , NULL ,
sizeof( struct V_199 ) , & V_200 -> V_121 ) ;
F_40 ( & V_38 -> V_4 -> V_126 , & V_38 -> V_125 ) ;
}
static void
F_120 ( void * V_82 , enum V_202 error )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
if ( error )
F_3 ( V_38 , V_190 ) ;
else
F_3 ( V_38 , V_193 ) ;
}
static void
F_121 ( void * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
F_3 ( V_38 , V_198 ) ;
}
static void
F_122 ( void * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
F_3 ( V_38 , V_190 ) ;
}
static void
F_123 ( void * V_82 )
{
struct V_37 * V_38 = (struct V_37 * ) V_82 ;
F_3 ( V_38 , V_189 ) ;
}
static void F_124 ( struct V_37 * V_38 )
{
V_38 -> V_40 . V_42 = V_203 ;
V_38 -> V_40 . V_44 = V_204 ;
V_38 -> V_40 . V_45 = V_205 ;
V_38 -> V_40 . V_47 = V_48 ;
V_38 -> V_40 . V_49 = V_206 ;
V_38 -> V_40 . V_41 = false ;
}
static void
F_125 ( struct V_37 * V_38 , struct V_4 * V_4 ,
struct V_207 * V_208 )
{
T_1 V_209 ;
T_4 * V_210 ;
V_38 -> V_4 = V_4 ;
F_126 ( & V_38 -> V_81 , V_38 , & V_211 ) ;
F_127 ( & V_38 -> V_81 , & V_4 -> V_212 , V_213 ) ;
F_128 (
& V_208 [ V_214 ] . V_215 . V_216 . V_217 [ 0 ] . V_209 , V_209 ) ;
V_210 = V_208 [ V_214 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
F_129 ( & V_38 -> V_81 , V_210 , V_209 ) ;
V_210 = V_208 [ V_218 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
F_128 (
& V_208 [ V_219 ] . V_215 . V_216 . V_217 [ 0 ] . V_209 , V_209 ) ;
V_210 = V_208 [ V_219 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
F_130 ( & V_4 -> V_220 , & V_38 -> V_81 , V_4 ) ;
F_131 ( & V_4 -> V_220 , V_210 , V_209 ) ;
V_210 += F_132 () ;
V_209 += F_132 () ;
F_133 ( & V_4 -> V_126 , & V_38 -> V_81 ) ;
F_134 ( & V_4 -> V_126 , V_210 , V_209 ) ;
F_135 ( & V_4 -> V_126 , V_122 , F_25 , V_4 ) ;
V_210 += F_136 () ;
V_209 += F_136 () ;
V_38 -> V_149 = NULL ;
V_38 -> V_174 = NULL ;
F_124 ( V_38 ) ;
F_49 ( V_38 , F_102 ) ;
}
static void
F_137 ( struct V_37 * V_38 )
{
F_138 ( & V_38 -> V_81 ) ;
V_38 -> V_4 = NULL ;
}
void
F_139 ( struct V_37 * V_38 )
{
if ( V_38 -> V_180 == ( V_221 ) V_196 ) {
F_112 ( V_38 -> V_4 -> V_31 ) ;
return;
}
if ( V_38 -> V_180 == ( V_221 ) F_102 )
F_3 ( V_38 , V_186 ) ;
}
void
F_140 ( struct V_37 * V_38 , enum V_182 type )
{
if ( type == V_183 ) {
F_141 ( V_38 -> V_4 -> V_31 ) ;
return;
}
V_38 -> V_149 = F_141 ;
V_38 -> V_174 = V_38 -> V_4 -> V_31 ;
F_3 ( V_38 , V_188 ) ;
}
static void
F_142 ( struct V_222 * V_223 , struct V_4 * V_4 ,
struct V_207 * V_208 )
{
int V_61 ;
V_223 -> V_224 = (struct V_225 * )
V_208 [ V_226 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
F_143 ( & V_223 -> V_227 ) ;
for ( V_61 = 0 ; V_61 < V_4 -> V_38 . V_40 . V_45 ; V_61 ++ ) {
F_144 ( & V_223 -> V_224 [ V_61 ] . V_228 ) ;
F_145 ( & V_223 -> V_224 [ V_61 ] . V_228 , & V_223 -> V_227 ) ;
}
V_223 -> V_4 = V_4 ;
}
static void
F_146 ( struct V_222 * V_223 )
{
struct V_229 * V_228 ;
int V_61 = 0 ;
F_147 (qe, &ucam_mod->free_q)
V_61 ++ ;
V_223 -> V_4 = NULL ;
}
static void
F_148 ( struct V_230 * V_231 , struct V_4 * V_4 ,
struct V_207 * V_208 )
{
int V_61 ;
V_231 -> V_232 = (struct V_225 * )
V_208 [ V_233 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
F_143 ( & V_231 -> V_227 ) ;
for ( V_61 = 0 ; V_61 < V_4 -> V_38 . V_40 . V_47 ; V_61 ++ ) {
F_144 ( & V_231 -> V_232 [ V_61 ] . V_228 ) ;
F_145 ( & V_231 -> V_232 [ V_61 ] . V_228 , & V_231 -> V_227 ) ;
}
V_231 -> V_234 = (struct V_235 * )
V_208 [ V_236 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
F_143 ( & V_231 -> V_237 ) ;
for ( V_61 = 0 ; V_61 < V_4 -> V_38 . V_40 . V_47 ; V_61 ++ ) {
F_144 ( & V_231 -> V_234 [ V_61 ] . V_228 ) ;
F_145 ( & V_231 -> V_234 [ V_61 ] . V_228 ,
& V_231 -> V_237 ) ;
}
V_231 -> V_4 = V_4 ;
}
static void
F_149 ( struct V_230 * V_231 )
{
struct V_229 * V_228 ;
int V_61 ;
V_61 = 0 ;
F_147 (qe, &mcam_mod->free_q) V_61 ++ ;
V_61 = 0 ;
F_147 (qe, &mcam_mod->free_handle_q) V_61 ++ ;
V_231 -> V_4 = NULL ;
}
static void
F_150 ( struct V_4 * V_4 )
{
struct V_52 * V_53 = & V_4 -> V_54 . V_55 ;
V_4 -> V_54 . V_77 = true ;
F_36 ( V_53 -> V_121 , V_122 ,
V_238 , 0 , 0 ) ;
V_53 -> V_121 . V_124 = F_37 (
F_38 ( sizeof( struct V_52 ) ) ) ;
V_53 -> V_239 = F_37 ( V_240 ) ;
V_53 -> V_58 = F_151 ( V_4 -> V_119 . V_241 ) ;
V_53 -> V_59 = F_151 ( V_4 -> V_242 . V_241 ) ;
V_53 -> V_243 . V_244 . V_245 = V_4 -> V_68 . V_246 . V_247 ;
V_53 -> V_243 . V_244 . V_248 = V_4 -> V_68 . V_246 . V_249 ;
F_39 ( & V_4 -> V_54 . V_250 , NULL , NULL ,
sizeof( struct V_52 ) , & V_53 -> V_121 ) ;
F_40 ( & V_4 -> V_126 , & V_4 -> V_54 . V_250 ) ;
}
void
F_152 ( struct V_207 * V_208 )
{
V_208 [ V_219 ] . V_251 = V_252 ;
V_208 [ V_219 ] . V_215 . V_216 . V_253 = V_254 ;
V_208 [ V_219 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_219 ] . V_215 . V_216 . V_256 = F_153 (
( F_132 () +
F_136 () ) , V_257 ) ;
V_208 [ V_214 ] . V_251 = V_252 ;
V_208 [ V_214 ] . V_215 . V_216 . V_253 = V_254 ;
V_208 [ V_214 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_214 ] . V_215 . V_216 . V_256 =
F_153 ( F_154 () , V_257 ) ;
V_208 [ V_218 ] . V_251 = V_252 ;
V_208 [ V_218 ] . V_215 . V_216 . V_253 = V_258 ;
V_208 [ V_218 ] . V_215 . V_216 . V_255 = 0 ;
V_208 [ V_218 ] . V_215 . V_216 . V_256 = 0 ;
V_208 [ V_259 ] . V_251 = V_252 ;
V_208 [ V_259 ] . V_215 . V_216 . V_253 = V_254 ;
V_208 [ V_259 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_259 ] . V_215 . V_216 . V_256 =
F_153 ( sizeof( struct V_260 ) ,
V_257 ) ;
}
void
F_155 ( struct V_4 * V_4 , struct V_207 * V_208 )
{
struct V_261 * V_40 = & V_4 -> V_38 . V_40 ;
V_208 [ V_262 ] . V_251 = V_252 ;
V_208 [ V_262 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_262 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_262 ] . V_215 . V_216 . V_256 =
V_40 -> V_42 * sizeof( struct V_83 ) ;
V_208 [ V_263 ] . V_251 = V_252 ;
V_208 [ V_263 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_263 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_263 ] . V_215 . V_216 . V_256 =
V_40 -> V_42 * sizeof( struct V_264 ) ;
V_208 [ V_265 ] . V_251 = V_252 ;
V_208 [ V_265 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_265 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_265 ] . V_215 . V_216 . V_256 =
V_40 -> V_44 * sizeof( struct V_85 ) ;
V_208 [ V_266 ] . V_251 = V_252 ;
V_208 [ V_266 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_266 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_266 ] . V_215 . V_216 . V_256 =
V_40 -> V_44 * sizeof( struct V_267 ) ;
V_208 [ V_268 ] . V_251 = V_252 ;
V_208 [ V_268 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_268 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_268 ] . V_215 . V_216 . V_256 =
( V_40 -> V_44 * 2 ) * sizeof( struct V_269 ) ;
V_208 [ V_226 ] . V_251 = V_252 ;
V_208 [ V_226 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_226 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_226 ] . V_215 . V_216 . V_256 =
V_40 -> V_45 * sizeof( struct V_225 ) ;
V_208 [ V_233 ] . V_251 = V_252 ;
V_208 [ V_233 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_233 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_233 ] . V_215 . V_216 . V_256 =
V_40 -> V_47 * sizeof( struct V_225 ) ;
V_208 [ V_236 ] . V_251 = V_252 ;
V_208 [ V_236 ] . V_215 . V_216 . V_253 =
V_258 ;
V_208 [ V_236 ] . V_215 . V_216 . V_255 = 1 ;
V_208 [ V_236 ] . V_215 . V_216 . V_256 =
V_40 -> V_47 * sizeof( struct V_235 ) ;
}
void
F_156 ( struct V_4 * V_4 , struct V_31 * V_31 ,
struct V_270 * V_212 , struct V_207 * V_208 )
{
V_4 -> V_31 = V_31 ;
V_4 -> V_212 = * V_212 ;
V_4 -> V_68 . V_69 = (struct V_260 * )
V_208 [ V_259 ] . V_215 . V_216 . V_217 [ 0 ] . V_210 ;
V_4 -> V_68 . V_246 . V_247 =
V_208 [ V_259 ] . V_215 . V_216 . V_217 [ 0 ] . V_209 . V_247 ;
V_4 -> V_68 . V_246 . V_249 =
V_208 [ V_259 ] . V_215 . V_216 . V_217 [ 0 ] . V_209 . V_249 ;
F_157 ( V_4 , & V_4 -> V_212 ) ;
F_125 ( & V_4 -> V_38 , V_4 , V_208 ) ;
F_84 ( & V_4 -> V_5 , V_4 ) ;
F_57 ( & V_4 -> V_2 , V_4 ) ;
}
void
F_158 ( struct V_4 * V_4 , struct V_207 * V_208 )
{
F_159 ( & V_4 -> V_119 , V_4 , V_208 ) ;
F_160 ( & V_4 -> V_242 , V_4 , V_208 ) ;
F_142 ( & V_4 -> V_223 , V_4 , V_208 ) ;
F_148 ( & V_4 -> V_231 , V_4 , V_208 ) ;
V_4 -> V_271 = V_272 ;
V_4 -> V_273 = V_272 ;
V_4 -> V_274 |= V_275 ;
}
void
F_161 ( struct V_4 * V_4 )
{
if ( V_4 -> V_274 & V_275 ) {
F_149 ( & V_4 -> V_231 ) ;
F_146 ( & V_4 -> V_223 ) ;
F_162 ( & V_4 -> V_242 ) ;
F_163 ( & V_4 -> V_119 ) ;
V_4 -> V_274 &= ~ V_275 ;
}
F_164 ( & V_4 -> V_54 ) ;
F_58 ( & V_4 -> V_2 ) ;
F_85 ( & V_4 -> V_5 ) ;
F_137 ( & V_4 -> V_38 ) ;
V_4 -> V_31 = NULL ;
}
int
F_165 ( struct V_4 * V_4 , int V_42 )
{
if ( V_4 -> V_38 . V_40 . V_41 &&
( V_42 <= V_4 -> V_38 . V_40 . V_42 ) ) {
V_4 -> V_38 . V_40 . V_42 = V_42 ;
return V_78 ;
}
return V_143 ;
}
int
F_166 ( struct V_4 * V_4 , int V_44 )
{
if ( V_4 -> V_38 . V_40 . V_41 &&
( V_44 <= V_4 -> V_38 . V_40 . V_44 ) ) {
V_4 -> V_38 . V_40 . V_44 = V_44 ;
return V_78 ;
}
return V_143 ;
}
struct V_225 *
F_167 ( struct V_222 * V_223 )
{
struct V_229 * V_228 ;
if ( F_168 ( & V_223 -> V_227 ) )
return NULL ;
F_169 ( & V_223 -> V_227 , & V_228 ) ;
return (struct V_225 * ) V_228 ;
}
void
F_170 ( struct V_222 * V_223 , struct V_225 * V_62 )
{
F_145 ( & V_62 -> V_228 , & V_223 -> V_227 ) ;
}
struct V_225 *
F_171 ( struct V_230 * V_231 )
{
struct V_229 * V_228 ;
if ( F_168 ( & V_231 -> V_227 ) )
return NULL ;
F_169 ( & V_231 -> V_227 , & V_228 ) ;
return (struct V_225 * ) V_228 ;
}
void
F_172 ( struct V_230 * V_231 , struct V_225 * V_62 )
{
F_145 ( & V_62 -> V_228 , & V_231 -> V_227 ) ;
}
struct V_235 *
F_173 ( struct V_230 * V_231 )
{
struct V_229 * V_228 ;
if ( F_168 ( & V_231 -> V_237 ) )
return NULL ;
F_169 ( & V_231 -> V_237 , & V_228 ) ;
return (struct V_235 * ) V_228 ;
}
void
F_174 ( struct V_230 * V_231 ,
struct V_235 * V_276 )
{
F_145 ( & V_276 -> V_228 , & V_231 -> V_237 ) ;
}
void
F_175 ( struct V_4 * V_4 )
{
if ( ! V_4 -> V_54 . V_277 ) {
F_14 ( V_4 -> V_31 , V_143 , & V_4 -> V_68 ) ;
return;
}
if ( V_4 -> V_54 . V_77 ) {
F_14 ( V_4 -> V_31 , V_278 , & V_4 -> V_68 ) ;
return;
}
F_150 ( V_4 ) ;
}
