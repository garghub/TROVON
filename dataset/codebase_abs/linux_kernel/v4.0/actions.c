static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_2 -> V_4 ) ;
}
static struct V_5 * F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return NULL ;
return & V_2 -> V_2 [ V_2 -> V_4 ++ ] ;
}
static struct V_5 * F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_6 - 1 )
return NULL ;
return & V_2 -> V_2 [ V_2 -> V_3 ++ ] ;
}
static struct V_5 * F_5 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_5 * V_13 ;
V_2 = F_6 ( V_14 ) ;
V_13 = F_4 ( V_2 ) ;
if ( V_13 ) {
V_13 -> V_8 = V_8 ;
V_13 -> V_15 = V_12 ;
V_13 -> V_16 = * V_10 ;
}
return V_13 ;
}
static void F_7 ( struct V_9 * V_10 )
{
V_10 -> V_17 . type = F_8 ( 0 ) ;
}
static bool F_9 ( const struct V_9 * V_10 )
{
return ! ! V_10 -> V_17 . type ;
}
static int F_10 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_18 * V_19 )
{
T_1 * V_20 ;
struct V_21 * V_22 ;
if ( V_8 -> V_23 )
return - V_24 ;
if ( F_11 ( V_8 , V_25 ) < 0 )
return - V_26 ;
F_12 ( V_8 , V_25 ) ;
memmove ( F_13 ( V_8 ) - V_25 , F_13 ( V_8 ) ,
V_8 -> V_27 ) ;
F_14 ( V_8 ) ;
V_20 = ( T_1 * ) F_15 ( V_8 ) ;
* V_20 = V_19 -> V_28 ;
if ( V_8 -> V_29 == V_30 )
V_8 -> V_31 = F_16 ( V_8 -> V_31 , F_17 ( V_20 ,
V_25 , 0 ) ) ;
V_22 = F_18 ( V_8 ) ;
V_22 -> V_32 = V_19 -> V_33 ;
if ( ! V_8 -> V_34 )
F_19 ( V_8 , V_8 -> V_35 ) ;
V_8 -> V_35 = V_19 -> V_33 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const T_2 V_36 )
{
struct V_21 * V_22 ;
int V_37 ;
V_37 = F_21 ( V_8 , V_8 -> V_27 + V_25 ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
F_23 ( V_8 , F_15 ( V_8 ) , V_25 ) ;
memmove ( F_13 ( V_8 ) + V_25 , F_13 ( V_8 ) ,
V_8 -> V_27 ) ;
F_24 ( V_8 , V_25 ) ;
F_14 ( V_8 ) ;
V_22 = (struct V_21 * ) ( F_15 ( V_8 ) - V_38 ) ;
V_22 -> V_32 = V_36 ;
if ( F_25 ( V_8 -> V_35 ) )
V_8 -> V_35 = V_36 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const T_1 * V_28 , const T_1 * V_40 )
{
T_1 * V_41 ;
T_1 V_42 ;
int V_37 ;
V_37 = F_21 ( V_8 , V_8 -> V_27 + V_25 ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_41 = ( T_1 * ) F_15 ( V_8 ) ;
V_42 = F_27 ( * V_41 , * V_28 , * V_40 ) ;
if ( V_8 -> V_29 == V_30 ) {
T_1 V_43 [] = { ~ ( * V_41 ) , V_42 } ;
V_8 -> V_31 = ~ F_17 ( ( char * ) V_43 , sizeof( V_43 ) ,
~ V_8 -> V_31 ) ;
}
* V_41 = V_42 ;
V_39 -> V_19 . V_44 = V_42 ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_37 ;
V_37 = F_29 ( V_8 ) ;
if ( F_30 ( V_8 ) )
F_7 ( V_10 ) ;
else
V_10 -> V_17 . V_45 = 0 ;
return V_37 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_46 * V_47 )
{
if ( F_30 ( V_8 ) )
F_7 ( V_10 ) ;
else
V_10 -> V_17 . V_45 = V_47 -> V_48 ;
return F_32 ( V_8 , V_47 -> V_49 ,
F_33 ( V_47 -> V_48 ) & ~ V_50 ) ;
}
static void F_34 ( T_3 * V_51 , const T_3 * V_52 , const T_3 * V_53 )
{
T_4 * V_54 = ( T_4 * ) V_51 ;
const T_4 * V_55 = ( const T_4 * ) V_52 ;
const T_4 * V_40 = ( const T_4 * ) V_53 ;
F_35 ( V_54 [ 0 ] , V_55 [ 0 ] , V_40 [ 0 ] ) ;
F_35 ( V_54 [ 1 ] , V_55 [ 1 ] , V_40 [ 1 ] ) ;
F_35 ( V_54 [ 2 ] , V_55 [ 2 ] , V_40 [ 2 ] ) ;
}
static int F_36 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const struct V_56 * V_10 ,
const struct V_56 * V_40 )
{
int V_37 ;
V_37 = F_21 ( V_8 , V_38 ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
F_23 ( V_8 , F_18 ( V_8 ) , V_57 * 2 ) ;
F_34 ( F_18 ( V_8 ) -> V_58 , V_10 -> V_59 ,
V_40 -> V_59 ) ;
F_34 ( F_18 ( V_8 ) -> V_60 , V_10 -> V_61 ,
V_40 -> V_61 ) ;
F_37 ( V_8 , F_18 ( V_8 ) , V_57 * 2 ) ;
F_38 ( V_39 -> V_17 . V_55 , F_18 ( V_8 ) -> V_58 ) ;
F_38 ( V_39 -> V_17 . V_54 , F_18 ( V_8 ) -> V_60 ) ;
return 0 ;
}
static void F_39 ( struct V_7 * V_8 , struct V_62 * V_63 ,
T_1 * V_64 , T_1 V_65 )
{
int V_66 = V_8 -> V_67 - F_40 ( V_8 ) ;
if ( V_63 -> V_35 == V_68 ) {
if ( F_41 ( V_66 >= sizeof( struct V_69 ) ) )
F_42 ( & F_43 ( V_8 ) -> V_70 , V_8 ,
* V_64 , V_65 , 1 ) ;
} else if ( V_63 -> V_35 == V_71 ) {
if ( F_41 ( V_66 >= sizeof( struct V_72 ) ) ) {
struct V_72 * V_73 = F_44 ( V_8 ) ;
if ( V_73 -> V_70 || V_8 -> V_29 == V_74 ) {
F_42 ( & V_73 -> V_70 , V_8 ,
* V_64 , V_65 , 1 ) ;
if ( ! V_73 -> V_70 )
V_73 -> V_70 = V_75 ;
}
}
}
F_45 ( & V_63 -> V_70 , * V_64 , V_65 ) ;
F_46 ( V_8 ) ;
* V_64 = V_65 ;
}
static void F_47 ( struct V_7 * V_8 , T_3 V_76 ,
T_1 V_64 [ 4 ] , const T_1 V_65 [ 4 ] )
{
int V_66 = V_8 -> V_67 - F_40 ( V_8 ) ;
if ( V_76 == V_77 ) {
if ( F_41 ( V_66 >= sizeof( struct V_69 ) ) )
F_48 ( & F_43 ( V_8 ) -> V_70 , V_8 ,
V_64 , V_65 , 1 ) ;
} else if ( V_76 == V_78 ) {
if ( F_41 ( V_66 >= sizeof( struct V_72 ) ) ) {
struct V_72 * V_73 = F_44 ( V_8 ) ;
if ( V_73 -> V_70 || V_8 -> V_29 == V_74 ) {
F_48 ( & V_73 -> V_70 , V_8 ,
V_64 , V_65 , 1 ) ;
if ( ! V_73 -> V_70 )
V_73 -> V_70 = V_75 ;
}
}
} else if ( V_76 == V_79 ) {
if ( F_41 ( V_66 >= sizeof( struct V_80 ) ) )
F_48 ( & F_49 ( V_8 ) -> V_81 ,
V_8 , V_64 , V_65 , 1 ) ;
}
}
static void F_50 ( const T_1 V_82 [ 4 ] , const T_1 V_64 [ 4 ] ,
const T_1 V_40 [ 4 ] , T_1 V_83 [ 4 ] )
{
V_83 [ 0 ] = F_27 ( V_82 [ 0 ] , V_64 [ 0 ] , V_40 [ 0 ] ) ;
V_83 [ 1 ] = F_27 ( V_82 [ 1 ] , V_64 [ 1 ] , V_40 [ 1 ] ) ;
V_83 [ 2 ] = F_27 ( V_82 [ 2 ] , V_64 [ 2 ] , V_40 [ 2 ] ) ;
V_83 [ 3 ] = F_27 ( V_82 [ 3 ] , V_64 [ 3 ] , V_40 [ 3 ] ) ;
}
static void F_51 ( struct V_7 * V_8 , T_3 V_76 ,
T_1 V_64 [ 4 ] , const T_1 V_65 [ 4 ] ,
bool V_84 )
{
if ( V_84 )
F_47 ( V_8 , V_76 , V_64 , V_65 ) ;
F_46 ( V_8 ) ;
memcpy ( V_64 , V_65 , sizeof( T_1 [ 4 ] ) ) ;
}
static void F_52 ( struct V_85 * V_63 , T_5 V_86 , T_5 V_40 )
{
F_35 ( V_63 -> V_87 [ 0 ] , ( T_3 ) ( V_86 >> 16 ) , ( T_3 ) ( V_40 >> 16 ) ) ;
F_35 ( V_63 -> V_87 [ 1 ] , ( T_3 ) ( V_86 >> 8 ) , ( T_3 ) ( V_40 >> 8 ) ) ;
F_35 ( V_63 -> V_87 [ 2 ] , ( T_3 ) V_86 , ( T_3 ) V_40 ) ;
}
static void F_53 ( struct V_7 * V_8 , struct V_62 * V_63 , T_3 V_88 ,
T_3 V_40 )
{
V_88 = F_27 ( V_63 -> V_89 , V_88 , V_40 ) ;
F_54 ( & V_63 -> V_70 , F_8 ( V_63 -> V_89 << 8 ) , F_8 ( V_88 << 8 ) ) ;
V_63 -> V_89 = V_88 ;
}
static int F_55 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const struct V_90 * V_10 ,
const struct V_90 * V_40 )
{
struct V_62 * V_63 ;
T_1 V_65 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_56 ( V_8 ) +
sizeof( struct V_62 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_63 = F_57 ( V_8 ) ;
if ( V_40 -> V_91 ) {
V_65 = F_27 ( V_63 -> V_92 , V_10 -> V_91 , V_40 -> V_91 ) ;
if ( F_22 ( V_65 != V_63 -> V_92 ) ) {
F_39 ( V_8 , V_63 , & V_63 -> V_92 , V_65 ) ;
V_39 -> V_93 . V_64 . V_55 = V_65 ;
}
}
if ( V_40 -> V_94 ) {
V_65 = F_27 ( V_63 -> V_95 , V_10 -> V_94 , V_40 -> V_94 ) ;
if ( F_22 ( V_65 != V_63 -> V_95 ) ) {
F_39 ( V_8 , V_63 , & V_63 -> V_95 , V_65 ) ;
V_39 -> V_93 . V_64 . V_54 = V_65 ;
}
}
if ( V_40 -> V_96 ) {
F_58 ( V_63 , ~ V_40 -> V_96 , V_10 -> V_96 ) ;
V_39 -> V_97 . V_98 = V_63 -> V_98 ;
}
if ( V_40 -> V_99 ) {
F_53 ( V_8 , V_63 , V_10 -> V_99 , V_40 -> V_99 ) ;
V_39 -> V_97 . V_89 = V_63 -> V_89 ;
}
return 0 ;
}
static bool F_59 ( const T_1 V_64 [ 4 ] )
{
return ! ! ( V_64 [ 0 ] | V_64 [ 1 ] | V_64 [ 2 ] | V_64 [ 3 ] ) ;
}
static int F_60 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const struct V_100 * V_10 ,
const struct V_100 * V_40 )
{
struct V_85 * V_63 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_56 ( V_8 ) +
sizeof( struct V_85 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_63 = F_61 ( V_8 ) ;
if ( F_59 ( V_40 -> V_101 ) ) {
T_1 * V_92 = ( T_1 * ) & V_63 -> V_92 ;
T_1 V_83 [ 4 ] ;
F_50 ( V_92 , V_10 -> V_101 , V_40 -> V_101 , V_83 ) ;
if ( F_22 ( memcmp ( V_92 , V_83 , sizeof( V_83 ) ) ) ) {
F_51 ( V_8 , V_10 -> V_102 , V_92 , V_83 ,
true ) ;
memcpy ( & V_39 -> V_103 . V_64 . V_55 , V_83 ,
sizeof( V_39 -> V_103 . V_64 . V_55 ) ) ;
}
}
if ( F_59 ( V_40 -> V_104 ) ) {
unsigned int V_105 = 0 ;
int V_106 = V_107 ;
bool V_108 = true ;
T_1 * V_95 = ( T_1 * ) & V_63 -> V_95 ;
T_1 V_83 [ 4 ] ;
F_50 ( V_95 , V_10 -> V_104 , V_40 -> V_104 , V_83 ) ;
if ( F_22 ( memcmp ( V_95 , V_83 , sizeof( V_83 ) ) ) ) {
if ( F_62 ( V_63 -> V_109 ) )
V_108 = ( F_63 ( V_8 , & V_105 ,
V_110 ,
NULL , & V_106 )
!= V_110 ) ;
F_51 ( V_8 , V_10 -> V_102 , V_95 , V_83 ,
V_108 ) ;
memcpy ( & V_39 -> V_103 . V_64 . V_54 , V_83 ,
sizeof( V_39 -> V_103 . V_64 . V_54 ) ) ;
}
}
if ( V_40 -> V_111 ) {
F_64 ( V_63 , ~ V_40 -> V_111 , V_10 -> V_111 ) ;
V_39 -> V_97 . V_98 = F_65 ( V_63 ) ;
}
if ( V_40 -> V_112 ) {
F_52 ( V_63 , F_66 ( V_10 -> V_112 ) ,
F_66 ( V_40 -> V_112 ) ) ;
V_39 -> V_103 . V_113 =
* ( T_1 * ) V_63 & F_67 ( V_114 ) ;
}
if ( V_40 -> V_115 ) {
F_35 ( V_63 -> V_116 , V_10 -> V_115 , V_40 -> V_115 ) ;
V_39 -> V_97 . V_89 = V_63 -> V_116 ;
}
return 0 ;
}
static void F_68 ( struct V_7 * V_8 , T_2 * V_117 ,
T_2 V_118 , T_6 * V_70 )
{
F_69 ( V_70 , V_8 , * V_117 , V_118 , 0 ) ;
* V_117 = V_118 ;
}
static int F_70 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const struct V_119 * V_10 ,
const struct V_119 * V_40 )
{
struct V_72 * V_73 ;
T_2 V_55 , V_54 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_40 ( V_8 ) +
sizeof( struct V_72 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_73 = F_44 ( V_8 ) ;
V_55 = F_27 ( V_73 -> V_120 , V_10 -> V_121 , V_40 -> V_121 ) ;
V_54 = F_27 ( V_73 -> V_122 , V_10 -> V_123 , V_40 -> V_123 ) ;
if ( V_73 -> V_70 && V_8 -> V_29 != V_74 ) {
if ( F_41 ( V_55 != V_73 -> V_120 ) ) {
F_68 ( V_8 , & V_73 -> V_120 , V_55 , & V_73 -> V_70 ) ;
V_39 -> V_124 . V_55 = V_55 ;
}
if ( F_41 ( V_54 != V_73 -> V_122 ) ) {
F_68 ( V_8 , & V_73 -> V_122 , V_54 , & V_73 -> V_70 ) ;
V_39 -> V_124 . V_54 = V_54 ;
}
if ( F_22 ( ! V_73 -> V_70 ) )
V_73 -> V_70 = V_75 ;
} else {
V_73 -> V_120 = V_55 ;
V_73 -> V_122 = V_54 ;
V_39 -> V_124 . V_55 = V_55 ;
V_39 -> V_124 . V_54 = V_54 ;
}
F_46 ( V_8 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const struct V_125 * V_10 ,
const struct V_125 * V_40 )
{
struct V_69 * V_126 ;
T_2 V_55 , V_54 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_40 ( V_8 ) +
sizeof( struct V_69 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_126 = F_43 ( V_8 ) ;
V_55 = F_27 ( V_126 -> V_120 , V_10 -> V_127 , V_40 -> V_127 ) ;
if ( F_41 ( V_55 != V_126 -> V_120 ) ) {
F_68 ( V_8 , & V_126 -> V_120 , V_55 , & V_126 -> V_70 ) ;
V_39 -> V_124 . V_55 = V_55 ;
}
V_54 = F_27 ( V_126 -> V_122 , V_10 -> V_128 , V_40 -> V_128 ) ;
if ( F_41 ( V_54 != V_126 -> V_122 ) ) {
F_68 ( V_8 , & V_126 -> V_122 , V_54 , & V_126 -> V_70 ) ;
V_39 -> V_124 . V_54 = V_54 ;
}
F_46 ( V_8 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_8 , struct V_9 * V_39 ,
const struct V_129 * V_10 ,
const struct V_129 * V_40 )
{
unsigned int V_130 = F_40 ( V_8 ) ;
struct V_131 * V_132 ;
T_7 V_133 , V_134 , V_135 ;
int V_37 ;
V_37 = F_21 ( V_8 , V_130 + sizeof( struct V_131 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_132 = F_73 ( V_8 ) ;
V_135 = V_132 -> V_136 ;
V_133 = F_74 ( V_8 , V_130 ) ;
V_132 -> V_120 = F_27 ( V_132 -> V_120 , V_10 -> V_137 , V_40 -> V_137 ) ;
V_132 -> V_122 = F_27 ( V_132 -> V_122 , V_10 -> V_138 , V_40 -> V_138 ) ;
V_134 = F_74 ( V_8 , V_130 ) ;
V_132 -> V_136 = V_135 ^ V_133 ^ V_134 ;
F_46 ( V_8 ) ;
V_39 -> V_124 . V_55 = V_132 -> V_120 ;
V_39 -> V_124 . V_54 = V_132 -> V_122 ;
return 0 ;
}
static void F_75 ( struct V_139 * V_140 , struct V_7 * V_8 , int V_141 )
{
struct V_142 * V_142 = F_76 ( V_140 , V_141 ) ;
if ( F_41 ( V_142 ) )
F_77 ( V_142 , V_8 ) ;
else
F_78 ( V_8 ) ;
}
static int F_79 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
struct V_143 V_144 ;
struct V_145 V_146 ;
const struct V_11 * V_147 ;
int V_148 ;
V_146 . V_149 = V_150 ;
V_146 . V_151 = NULL ;
V_146 . V_152 = 0 ;
V_146 . V_153 = NULL ;
for ( V_147 = F_80 ( V_12 ) , V_148 = F_81 ( V_12 ) ; V_148 > 0 ;
V_147 = F_82 ( V_147 , & V_148 ) ) {
switch ( F_83 ( V_147 ) ) {
case V_154 :
V_146 . V_151 = V_147 ;
break;
case V_155 :
V_146 . V_152 = F_84 ( V_147 ) ;
break;
case V_156 : {
struct V_142 * V_142 ;
V_142 = F_76 ( V_140 , F_84 ( V_147 ) ) ;
if ( V_142 ) {
int V_37 ;
V_37 = F_85 ( V_142 , V_8 ,
& V_144 ) ;
if ( ! V_37 )
V_146 . V_153 = & V_144 ;
}
break;
}
}
}
return F_86 ( V_140 , V_8 , V_10 , & V_146 ) ;
}
static int F_87 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
const struct V_11 * V_157 = NULL ;
const struct V_11 * V_147 ;
int V_148 ;
for ( V_147 = F_80 ( V_12 ) , V_148 = F_81 ( V_12 ) ; V_148 > 0 ;
V_147 = F_82 ( V_147 , & V_148 ) ) {
switch ( F_83 ( V_147 ) ) {
case V_158 :
if ( F_88 () >= F_84 ( V_147 ) )
return 0 ;
break;
case V_159 :
V_157 = V_147 ;
break;
}
}
V_148 = F_81 ( V_157 ) ;
V_147 = F_80 ( V_157 ) ;
if ( F_22 ( ! V_148 ) )
return 0 ;
if ( F_41 ( F_83 ( V_147 ) == V_160 &&
F_89 ( V_147 , V_148 ) ) )
return F_79 ( V_140 , V_8 , V_10 , V_147 ) ;
V_8 = F_90 ( V_8 , V_161 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_5 ( V_8 , V_10 , V_147 ) ) {
if ( F_91 () )
F_92 ( L_1 ,
F_93 ( V_140 ) ) ;
F_78 ( V_8 ) ;
}
return 0 ;
}
static void F_94 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_162 * V_163 = F_80 ( V_12 ) ;
T_5 V_164 = 0 ;
V_164 = F_95 ( V_8 ) ;
V_164 = F_96 ( V_164 , V_163 -> V_165 ) ;
if ( ! V_164 )
V_164 = 0x1 ;
V_10 -> V_166 = V_164 ;
}
static int F_97 ( struct V_7 * V_8 ,
struct V_9 * V_39 ,
const struct V_11 * V_147 )
{
if ( F_83 ( V_147 ) == V_167 ) {
F_98 ( V_8 ) -> V_153 = F_80 ( V_147 ) ;
return 0 ;
}
return - V_168 ;
}
static int F_99 ( struct V_7 * V_8 ,
struct V_9 * V_39 ,
const struct V_11 * V_147 )
{
int V_37 = 0 ;
switch ( F_83 ( V_147 ) ) {
case V_169 :
F_35 ( V_8 -> V_170 , F_84 ( V_147 ) , * F_100 ( V_147 , T_5 * ) ) ;
V_39 -> V_171 . V_170 = V_8 -> V_170 ;
break;
case V_172 :
F_35 ( V_8 -> V_173 , F_84 ( V_147 ) , * F_100 ( V_147 , T_5 * ) ) ;
V_39 -> V_171 . V_174 = V_8 -> V_173 ;
break;
case V_167 :
V_37 = - V_168 ;
break;
case V_175 :
V_37 = F_36 ( V_8 , V_39 , F_80 ( V_147 ) ,
F_100 ( V_147 , struct V_56 * ) ) ;
break;
case V_176 :
V_37 = F_55 ( V_8 , V_39 , F_80 ( V_147 ) ,
F_100 ( V_147 , struct V_90 * ) ) ;
break;
case V_177 :
V_37 = F_60 ( V_8 , V_39 , F_80 ( V_147 ) ,
F_100 ( V_147 , struct V_100 * ) ) ;
break;
case V_178 :
V_37 = F_71 ( V_8 , V_39 , F_80 ( V_147 ) ,
F_100 ( V_147 , struct V_125 * ) ) ;
break;
case V_179 :
V_37 = F_70 ( V_8 , V_39 , F_80 ( V_147 ) ,
F_100 ( V_147 , struct V_119 * ) ) ;
break;
case V_180 :
V_37 = F_72 ( V_8 , V_39 , F_80 ( V_147 ) ,
F_100 ( V_147 , struct V_129 * ) ) ;
break;
case V_181 :
V_37 = F_26 ( V_8 , V_39 , F_80 ( V_147 ) , F_100 ( V_147 ,
T_1 * ) ) ;
break;
}
return V_37 ;
}
static int F_101 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_147 , int V_148 )
{
struct V_5 * V_13 ;
if ( ! F_9 ( V_10 ) ) {
int V_37 ;
V_37 = F_102 ( V_8 , V_10 ) ;
if ( V_37 )
return V_37 ;
}
F_103 ( ! F_9 ( V_10 ) ) ;
if ( ! F_89 ( V_147 , V_148 ) ) {
V_8 = F_90 ( V_8 , V_161 ) ;
if ( ! V_8 )
return 0 ;
}
V_13 = F_5 ( V_8 , V_10 , NULL ) ;
if ( V_13 ) {
V_13 -> V_16 . V_182 = F_84 ( V_147 ) ;
} else {
F_78 ( V_8 ) ;
if ( F_91 () )
F_92 ( L_2 ,
F_93 ( V_140 ) ) ;
}
return 0 ;
}
static int F_104 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 , int V_67 )
{
int V_183 = - 1 ;
const struct V_11 * V_147 ;
int V_148 ;
for ( V_147 = V_12 , V_148 = V_67 ; V_148 > 0 ;
V_147 = F_82 ( V_147 , & V_148 ) ) {
int V_37 = 0 ;
if ( F_22 ( V_183 != - 1 ) ) {
struct V_7 * V_184 = F_90 ( V_8 , V_161 ) ;
if ( V_184 )
F_75 ( V_140 , V_184 , V_183 ) ;
V_183 = - 1 ;
}
switch ( F_83 ( V_147 ) ) {
case V_185 :
V_183 = F_84 ( V_147 ) ;
break;
case V_160 :
F_79 ( V_140 , V_8 , V_10 , V_147 ) ;
break;
case V_186 :
F_94 ( V_8 , V_10 , V_147 ) ;
break;
case V_187 :
V_37 = F_10 ( V_8 , V_10 , F_80 ( V_147 ) ) ;
break;
case V_188 :
V_37 = F_20 ( V_8 , V_10 , F_105 ( V_147 ) ) ;
break;
case V_189 :
V_37 = F_31 ( V_8 , V_10 , F_80 ( V_147 ) ) ;
break;
case V_190 :
V_37 = F_28 ( V_8 , V_10 ) ;
break;
case V_191 :
V_37 = F_101 ( V_140 , V_8 , V_10 , V_147 , V_148 ) ;
if ( F_89 ( V_147 , V_148 ) ) {
return V_37 ;
}
break;
case V_192 :
V_37 = F_97 ( V_8 , V_10 , F_80 ( V_147 ) ) ;
break;
case V_193 :
case V_194 :
V_37 = F_99 ( V_8 , V_10 , F_80 ( V_147 ) ) ;
break;
case V_195 :
V_37 = F_87 ( V_140 , V_8 , V_10 , V_147 ) ;
break;
}
if ( F_22 ( V_37 ) ) {
F_78 ( V_8 ) ;
return V_37 ;
}
}
if ( V_183 != - 1 )
F_75 ( V_140 , V_8 , V_183 ) ;
else
F_106 ( V_8 ) ;
return 0 ;
}
static void F_107 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
if ( F_2 ( V_2 ) )
return;
do {
struct V_5 * V_13 = F_3 ( V_2 ) ;
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_9 * V_10 = & V_13 -> V_16 ;
const struct V_11 * V_15 = V_13 -> V_15 ;
if ( V_15 )
F_104 ( V_140 , V_8 , V_10 , V_15 ,
F_81 ( V_15 ) ) ;
else
F_108 ( V_8 , V_10 ) ;
} while ( ! F_2 ( V_2 ) );
F_1 ( V_2 ) ;
}
int F_109 ( struct V_139 * V_140 , struct V_7 * V_8 ,
const struct V_196 * V_197 ,
struct V_9 * V_10 )
{
int V_198 = F_110 ( V_199 ) ;
int V_37 ;
F_111 ( V_199 ) ;
F_98 ( V_8 ) -> V_153 = NULL ;
V_37 = F_104 ( V_140 , V_8 , V_10 ,
V_197 -> V_15 , V_197 -> V_200 ) ;
if ( ! V_198 )
F_107 ( V_140 ) ;
F_112 ( V_199 ) ;
return V_37 ;
}
int F_113 ( void )
{
V_14 = F_114 ( struct V_1 ) ;
if ( ! V_14 )
return - V_26 ;
return 0 ;
}
void F_115 ( void )
{
F_116 ( V_14 ) ;
}
