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
V_10 -> V_17 |= V_18 ;
}
static bool F_8 ( const struct V_9 * V_10 )
{
return ! ( V_10 -> V_17 & V_18 ) ;
}
static void F_9 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_1 V_21 )
{
if ( V_8 -> V_22 == V_23 ) {
T_1 V_24 [] = { ~ ( V_20 -> V_25 ) , V_21 } ;
V_8 -> V_26 = ~ F_10 ( ( char * ) V_24 , sizeof( V_24 ) ,
~ V_8 -> V_26 ) ;
}
V_20 -> V_25 = V_21 ;
}
static int F_11 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 ;
if ( V_8 -> V_31 )
return - V_32 ;
if ( F_12 ( V_8 , V_33 ) < 0 )
return - V_34 ;
if ( ! V_8 -> V_35 ) {
F_13 ( V_8 , V_8 -> V_36 ) ;
F_14 ( V_8 , V_8 -> V_37 ) ;
}
F_15 ( V_8 , V_33 ) ;
memmove ( F_16 ( V_8 ) - V_33 , F_16 ( V_8 ) ,
V_8 -> V_36 ) ;
F_17 ( V_8 ) ;
F_18 ( V_8 , V_8 -> V_36 ) ;
V_30 = F_19 ( V_8 ) ;
V_30 -> V_38 = V_28 -> V_39 ;
F_20 ( V_8 , V_30 , V_33 ) ;
if ( F_21 ( V_10 ) == V_40 )
F_9 ( V_8 , F_22 ( V_8 ) , V_28 -> V_41 ) ;
V_8 -> V_37 = V_28 -> V_41 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const T_1 V_21 )
{
int V_42 ;
V_42 = F_24 ( V_8 , V_8 -> V_36 + V_33 ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
F_26 ( V_8 , F_19 ( V_8 ) , V_33 ) ;
memmove ( F_16 ( V_8 ) + V_33 , F_16 ( V_8 ) ,
V_8 -> V_36 ) ;
F_27 ( V_8 , V_33 ) ;
F_17 ( V_8 ) ;
F_18 ( V_8 , V_8 -> V_36 ) ;
if ( F_21 ( V_10 ) == V_40 ) {
struct V_19 * V_20 ;
V_20 = (struct V_19 * ) ( ( void * ) F_19 ( V_8 ) - V_43 ) ;
F_9 ( V_8 , V_20 , V_21 ) ;
}
if ( F_28 ( V_8 -> V_37 ) )
V_8 -> V_37 = V_21 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const T_2 * V_39 , const T_2 * V_45 )
{
struct V_29 * V_46 ;
T_2 V_47 ;
int V_42 ;
V_42 = F_24 ( V_8 , V_8 -> V_36 + V_33 ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
V_46 = F_19 ( V_8 ) ;
V_47 = F_30 ( V_46 -> V_38 , * V_39 , * V_45 ) ;
if ( V_8 -> V_22 == V_23 ) {
T_2 V_24 [] = { ~ ( V_46 -> V_38 ) , V_47 } ;
V_8 -> V_26 = ~ F_10 ( ( char * ) V_24 , sizeof( V_24 ) ,
~ V_8 -> V_26 ) ;
}
V_46 -> V_38 = V_47 ;
V_44 -> V_28 . V_48 = V_47 ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_42 ;
V_42 = F_32 ( V_8 ) ;
if ( F_33 ( V_8 ) ) {
F_7 ( V_10 ) ;
} else {
V_10 -> V_49 . V_50 . V_51 = 0 ;
V_10 -> V_49 . V_50 . V_52 = 0 ;
}
return V_42 ;
}
static int F_34 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_53 * V_50 )
{
if ( F_33 ( V_8 ) ) {
F_7 ( V_10 ) ;
} else {
V_10 -> V_49 . V_50 . V_51 = V_50 -> V_54 ;
V_10 -> V_49 . V_50 . V_52 = V_50 -> V_55 ;
}
return F_35 ( V_8 , V_50 -> V_55 ,
F_36 ( V_50 -> V_54 ) & ~ V_56 ) ;
}
static void F_37 ( T_3 * V_57 , const T_3 * V_58 , const T_3 * V_59 )
{
T_4 * V_60 = ( T_4 * ) V_57 ;
const T_4 * V_61 = ( const T_4 * ) V_58 ;
const T_4 * V_45 = ( const T_4 * ) V_59 ;
F_38 ( V_60 [ 0 ] , V_61 [ 0 ] , V_45 [ 0 ] ) ;
F_38 ( V_60 [ 1 ] , V_61 [ 1 ] , V_45 [ 1 ] ) ;
F_38 ( V_60 [ 2 ] , V_61 [ 2 ] , V_45 [ 2 ] ) ;
}
static int F_39 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const struct V_62 * V_10 ,
const struct V_62 * V_45 )
{
int V_42 ;
V_42 = F_24 ( V_8 , V_43 ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
F_26 ( V_8 , F_22 ( V_8 ) , V_63 * 2 ) ;
F_37 ( F_22 ( V_8 ) -> V_64 , V_10 -> V_65 ,
V_45 -> V_65 ) ;
F_37 ( F_22 ( V_8 ) -> V_66 , V_10 -> V_67 ,
V_45 -> V_67 ) ;
F_20 ( V_8 , F_22 ( V_8 ) , V_63 * 2 ) ;
F_40 ( V_44 -> V_49 . V_61 , F_22 ( V_8 ) -> V_64 ) ;
F_40 ( V_44 -> V_49 . V_60 , F_22 ( V_8 ) -> V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
F_42 ( V_8 , V_43 ) ;
F_17 ( V_8 ) ;
F_43 ( V_8 ) ;
V_10 -> V_17 = V_68 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_69 * V_70 )
{
struct V_19 * V_20 ;
if ( F_12 ( V_8 , V_43 ) < 0 )
return - V_34 ;
F_15 ( V_8 , V_43 ) ;
F_17 ( V_8 ) ;
F_43 ( V_8 ) ;
V_20 = F_22 ( V_8 ) ;
F_40 ( V_20 -> V_64 , V_70 -> V_71 . V_65 ) ;
F_40 ( V_20 -> V_66 , V_70 -> V_71 . V_67 ) ;
V_20 -> V_25 = V_8 -> V_37 ;
F_20 ( V_8 , V_20 , V_43 ) ;
V_10 -> V_17 = V_40 ;
F_7 ( V_10 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_8 , struct V_72 * V_73 ,
T_2 V_74 , T_2 V_75 )
{
int V_76 = V_8 -> V_77 - F_46 ( V_8 ) ;
if ( V_73 -> V_78 & F_47 ( V_79 ) )
return;
if ( V_73 -> V_37 == V_80 ) {
if ( F_48 ( V_76 >= sizeof( struct V_81 ) ) )
F_49 ( & F_50 ( V_8 ) -> V_82 , V_8 ,
V_74 , V_75 , true ) ;
} else if ( V_73 -> V_37 == V_83 ) {
if ( F_48 ( V_76 >= sizeof( struct V_84 ) ) ) {
struct V_84 * V_85 = F_51 ( V_8 ) ;
if ( V_85 -> V_82 || V_8 -> V_22 == V_86 ) {
F_49 ( & V_85 -> V_82 , V_8 ,
V_74 , V_75 , true ) ;
if ( ! V_85 -> V_82 )
V_85 -> V_82 = V_87 ;
}
}
}
}
static void F_52 ( struct V_7 * V_8 , struct V_72 * V_73 ,
T_2 * V_74 , T_2 V_75 )
{
F_45 ( V_8 , V_73 , * V_74 , V_75 ) ;
F_53 ( & V_73 -> V_82 , * V_74 , V_75 ) ;
F_54 ( V_8 ) ;
* V_74 = V_75 ;
}
static void F_55 ( struct V_7 * V_8 , T_3 V_88 ,
T_2 V_74 [ 4 ] , const T_2 V_75 [ 4 ] )
{
int V_76 = V_8 -> V_77 - F_46 ( V_8 ) ;
if ( V_88 == V_89 ) {
if ( F_48 ( V_76 >= sizeof( struct V_81 ) ) )
F_56 ( & F_50 ( V_8 ) -> V_82 , V_8 ,
V_74 , V_75 , true ) ;
} else if ( V_88 == V_90 ) {
if ( F_48 ( V_76 >= sizeof( struct V_84 ) ) ) {
struct V_84 * V_85 = F_51 ( V_8 ) ;
if ( V_85 -> V_82 || V_8 -> V_22 == V_86 ) {
F_56 ( & V_85 -> V_82 , V_8 ,
V_74 , V_75 , true ) ;
if ( ! V_85 -> V_82 )
V_85 -> V_82 = V_87 ;
}
}
} else if ( V_88 == V_91 ) {
if ( F_48 ( V_76 >= sizeof( struct V_92 ) ) )
F_56 ( & F_57 ( V_8 ) -> V_93 ,
V_8 , V_74 , V_75 , true ) ;
}
}
static void F_58 ( const T_2 V_94 [ 4 ] , const T_2 V_74 [ 4 ] ,
const T_2 V_45 [ 4 ] , T_2 V_95 [ 4 ] )
{
V_95 [ 0 ] = F_30 ( V_94 [ 0 ] , V_74 [ 0 ] , V_45 [ 0 ] ) ;
V_95 [ 1 ] = F_30 ( V_94 [ 1 ] , V_74 [ 1 ] , V_45 [ 1 ] ) ;
V_95 [ 2 ] = F_30 ( V_94 [ 2 ] , V_74 [ 2 ] , V_45 [ 2 ] ) ;
V_95 [ 3 ] = F_30 ( V_94 [ 3 ] , V_74 [ 3 ] , V_45 [ 3 ] ) ;
}
static void F_59 ( struct V_7 * V_8 , T_3 V_88 ,
T_2 V_74 [ 4 ] , const T_2 V_75 [ 4 ] ,
bool V_96 )
{
if ( V_96 )
F_55 ( V_8 , V_88 , V_74 , V_75 ) ;
F_54 ( V_8 ) ;
memcpy ( V_74 , V_75 , sizeof( T_2 [ 4 ] ) ) ;
}
static void F_60 ( struct V_97 * V_73 , T_5 V_98 , T_5 V_45 )
{
F_38 ( V_73 -> V_99 [ 0 ] , ( T_3 ) ( V_98 >> 16 ) , ( T_3 ) ( V_45 >> 16 ) ) ;
F_38 ( V_73 -> V_99 [ 1 ] , ( T_3 ) ( V_98 >> 8 ) , ( T_3 ) ( V_45 >> 8 ) ) ;
F_38 ( V_73 -> V_99 [ 2 ] , ( T_3 ) V_98 , ( T_3 ) V_45 ) ;
}
static void F_61 ( struct V_7 * V_8 , struct V_72 * V_73 , T_3 V_100 ,
T_3 V_45 )
{
V_100 = F_30 ( V_73 -> V_101 , V_100 , V_45 ) ;
F_62 ( & V_73 -> V_82 , F_47 ( V_73 -> V_101 << 8 ) , F_47 ( V_100 << 8 ) ) ;
V_73 -> V_101 = V_100 ;
}
static int F_63 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const struct V_102 * V_10 ,
const struct V_102 * V_45 )
{
struct V_72 * V_73 ;
T_2 V_75 ;
int V_42 ;
V_42 = F_24 ( V_8 , F_64 ( V_8 ) +
sizeof( struct V_72 ) ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
V_73 = F_65 ( V_8 ) ;
if ( V_45 -> V_103 ) {
V_75 = F_30 ( V_73 -> V_104 , V_10 -> V_103 , V_45 -> V_103 ) ;
if ( F_25 ( V_75 != V_73 -> V_104 ) ) {
F_52 ( V_8 , V_73 , & V_73 -> V_104 , V_75 ) ;
V_44 -> V_105 . V_74 . V_61 = V_75 ;
}
}
if ( V_45 -> V_106 ) {
V_75 = F_30 ( V_73 -> V_107 , V_10 -> V_106 , V_45 -> V_106 ) ;
if ( F_25 ( V_75 != V_73 -> V_107 ) ) {
F_52 ( V_8 , V_73 , & V_73 -> V_107 , V_75 ) ;
V_44 -> V_105 . V_74 . V_60 = V_75 ;
}
}
if ( V_45 -> V_108 ) {
F_66 ( V_73 , ~ V_45 -> V_108 , V_10 -> V_108 ) ;
V_44 -> V_109 . V_110 = V_73 -> V_110 ;
}
if ( V_45 -> V_111 ) {
F_61 ( V_8 , V_73 , V_10 -> V_111 , V_45 -> V_111 ) ;
V_44 -> V_109 . V_101 = V_73 -> V_101 ;
}
return 0 ;
}
static bool F_67 ( const T_2 V_74 [ 4 ] )
{
return ! ! ( V_74 [ 0 ] | V_74 [ 1 ] | V_74 [ 2 ] | V_74 [ 3 ] ) ;
}
static int F_68 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const struct V_112 * V_10 ,
const struct V_112 * V_45 )
{
struct V_97 * V_73 ;
int V_42 ;
V_42 = F_24 ( V_8 , F_64 ( V_8 ) +
sizeof( struct V_97 ) ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
V_73 = F_69 ( V_8 ) ;
if ( F_67 ( V_45 -> V_113 ) ) {
T_2 * V_104 = ( T_2 * ) & V_73 -> V_104 ;
T_2 V_95 [ 4 ] ;
F_58 ( V_104 , V_10 -> V_113 , V_45 -> V_113 , V_95 ) ;
if ( F_25 ( memcmp ( V_104 , V_95 , sizeof( V_95 ) ) ) ) {
F_59 ( V_8 , V_44 -> V_109 . V_114 , V_104 , V_95 ,
true ) ;
memcpy ( & V_44 -> V_115 . V_74 . V_61 , V_95 ,
sizeof( V_44 -> V_115 . V_74 . V_61 ) ) ;
}
}
if ( F_67 ( V_45 -> V_116 ) ) {
unsigned int V_117 = 0 ;
int V_118 = V_119 ;
bool V_120 = true ;
T_2 * V_107 = ( T_2 * ) & V_73 -> V_107 ;
T_2 V_95 [ 4 ] ;
F_58 ( V_107 , V_10 -> V_116 , V_45 -> V_116 , V_95 ) ;
if ( F_25 ( memcmp ( V_107 , V_95 , sizeof( V_95 ) ) ) ) {
if ( F_70 ( V_73 -> V_121 ) )
V_120 = ( F_71 ( V_8 , & V_117 ,
V_122 ,
NULL , & V_118 )
!= V_122 ) ;
F_59 ( V_8 , V_44 -> V_109 . V_114 , V_107 , V_95 ,
V_120 ) ;
memcpy ( & V_44 -> V_115 . V_74 . V_60 , V_95 ,
sizeof( V_44 -> V_115 . V_74 . V_60 ) ) ;
}
}
if ( V_45 -> V_123 ) {
F_72 ( V_73 , ~ V_45 -> V_123 , V_10 -> V_123 ) ;
V_44 -> V_109 . V_110 = F_73 ( V_73 ) ;
}
if ( V_45 -> V_124 ) {
F_60 ( V_73 , F_74 ( V_10 -> V_124 ) ,
F_74 ( V_45 -> V_124 ) ) ;
V_44 -> V_115 . V_125 =
* ( T_2 * ) V_73 & F_75 ( V_126 ) ;
}
if ( V_45 -> V_127 ) {
F_38 ( V_73 -> V_128 , V_10 -> V_127 ,
V_45 -> V_127 ) ;
V_44 -> V_109 . V_101 = V_73 -> V_128 ;
}
return 0 ;
}
static void F_76 ( struct V_7 * V_8 , T_1 * V_129 ,
T_1 V_130 , T_6 * V_82 )
{
F_77 ( V_82 , V_8 , * V_129 , V_130 , false ) ;
* V_129 = V_130 ;
}
static int F_78 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const struct V_131 * V_10 ,
const struct V_131 * V_45 )
{
struct V_84 * V_85 ;
T_1 V_61 , V_60 ;
int V_42 ;
V_42 = F_24 ( V_8 , F_46 ( V_8 ) +
sizeof( struct V_84 ) ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
V_85 = F_51 ( V_8 ) ;
V_61 = F_30 ( V_85 -> V_132 , V_10 -> V_133 , V_45 -> V_133 ) ;
V_60 = F_30 ( V_85 -> V_134 , V_10 -> V_135 , V_45 -> V_135 ) ;
if ( V_85 -> V_82 && V_8 -> V_22 != V_86 ) {
if ( F_48 ( V_61 != V_85 -> V_132 ) ) {
F_76 ( V_8 , & V_85 -> V_132 , V_61 , & V_85 -> V_82 ) ;
V_44 -> V_136 . V_61 = V_61 ;
}
if ( F_48 ( V_60 != V_85 -> V_134 ) ) {
F_76 ( V_8 , & V_85 -> V_134 , V_60 , & V_85 -> V_82 ) ;
V_44 -> V_136 . V_60 = V_60 ;
}
if ( F_25 ( ! V_85 -> V_82 ) )
V_85 -> V_82 = V_87 ;
} else {
V_85 -> V_132 = V_61 ;
V_85 -> V_134 = V_60 ;
V_44 -> V_136 . V_61 = V_61 ;
V_44 -> V_136 . V_60 = V_60 ;
}
F_54 ( V_8 ) ;
return 0 ;
}
static int F_79 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const struct V_137 * V_10 ,
const struct V_137 * V_45 )
{
struct V_81 * V_138 ;
T_1 V_61 , V_60 ;
int V_42 ;
V_42 = F_24 ( V_8 , F_46 ( V_8 ) +
sizeof( struct V_81 ) ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
V_138 = F_50 ( V_8 ) ;
V_61 = F_30 ( V_138 -> V_132 , V_10 -> V_139 , V_45 -> V_139 ) ;
if ( F_48 ( V_61 != V_138 -> V_132 ) ) {
F_76 ( V_8 , & V_138 -> V_132 , V_61 , & V_138 -> V_82 ) ;
V_44 -> V_136 . V_61 = V_61 ;
}
V_60 = F_30 ( V_138 -> V_134 , V_10 -> V_140 , V_45 -> V_140 ) ;
if ( F_48 ( V_60 != V_138 -> V_134 ) ) {
F_76 ( V_8 , & V_138 -> V_134 , V_60 , & V_138 -> V_82 ) ;
V_44 -> V_136 . V_60 = V_60 ;
}
F_54 ( V_8 ) ;
return 0 ;
}
static int F_80 ( struct V_7 * V_8 , struct V_9 * V_44 ,
const struct V_141 * V_10 ,
const struct V_141 * V_45 )
{
unsigned int V_142 = F_46 ( V_8 ) ;
struct V_143 * V_144 ;
T_7 V_145 , V_146 , V_147 ;
int V_42 ;
V_42 = F_24 ( V_8 , V_142 + sizeof( struct V_143 ) ) ;
if ( F_25 ( V_42 ) )
return V_42 ;
V_144 = F_81 ( V_8 ) ;
V_147 = V_144 -> V_148 ;
V_145 = F_82 ( V_8 , V_142 ) ;
V_144 -> V_132 = F_30 ( V_144 -> V_132 , V_10 -> V_149 , V_45 -> V_149 ) ;
V_144 -> V_134 = F_30 ( V_144 -> V_134 , V_10 -> V_150 , V_45 -> V_150 ) ;
V_146 = F_82 ( V_8 , V_142 ) ;
V_144 -> V_148 = V_147 ^ V_145 ^ V_146 ;
F_54 ( V_8 ) ;
V_44 -> V_136 . V_61 = V_144 -> V_132 ;
V_44 -> V_136 . V_60 = V_144 -> V_134 ;
return 0 ;
}
static int F_83 ( struct V_151 * V_151 , struct V_152 * V_153 , struct V_7 * V_8 )
{
struct V_154 * V_155 = F_6 ( & V_156 ) ;
struct V_157 * V_157 = V_155 -> V_157 ;
if ( F_12 ( V_8 , V_155 -> V_158 ) < 0 ) {
F_84 ( V_8 ) ;
return - V_34 ;
}
F_85 ( V_8 , V_155 -> V_60 ) ;
* F_86 ( V_8 ) = V_155 -> V_159 ;
V_8 -> V_35 = V_155 -> V_35 ;
V_8 -> V_54 = V_155 -> V_54 ;
V_8 -> V_160 = V_155 -> V_160 ;
F_15 ( V_8 , V_155 -> V_158 ) ;
memcpy ( V_8 -> V_155 , & V_155 -> V_161 , V_155 -> V_158 ) ;
F_20 ( V_8 , V_8 -> V_155 , V_155 -> V_158 ) ;
F_17 ( V_8 ) ;
if ( F_28 ( V_8 -> V_37 ) ) {
V_8 -> V_162 = V_8 -> V_163 ;
F_18 ( V_8 , V_155 -> V_164 ) ;
F_43 ( V_8 ) ;
}
F_87 ( V_157 , V_8 , V_155 -> V_17 ) ;
return 0 ;
}
static unsigned int
F_88 ( const struct V_165 * V_60 )
{
return V_60 -> V_166 -> V_167 ;
}
static void F_89 ( struct V_157 * V_157 , struct V_7 * V_8 ,
T_4 V_168 , T_3 V_17 )
{
unsigned int V_169 = F_64 ( V_8 ) ;
struct V_154 * V_155 ;
V_155 = F_6 ( & V_156 ) ;
V_155 -> V_60 = V_8 -> V_170 ;
V_155 -> V_157 = V_157 ;
V_155 -> V_159 = * F_86 ( V_8 ) ;
V_155 -> V_35 = V_8 -> V_35 ;
V_155 -> V_164 = V_168 ;
V_155 -> V_54 = V_8 -> V_54 ;
V_155 -> V_160 = V_8 -> V_160 ;
V_155 -> V_17 = V_17 ;
V_155 -> V_158 = V_169 ;
memcpy ( & V_155 -> V_161 , V_8 -> V_155 , V_169 ) ;
memset ( F_90 ( V_8 ) , 0 , sizeof( struct V_171 ) ) ;
F_91 ( V_8 , V_169 ) ;
}
static void F_92 ( struct V_151 * V_151 , struct V_157 * V_157 ,
struct V_7 * V_8 , T_4 V_172 ,
struct V_9 * V_10 )
{
T_4 V_168 = 0 ;
if ( F_28 ( V_8 -> V_37 ) ) {
V_168 = F_64 ( V_8 ) ;
V_8 -> V_163 = V_8 -> V_162 ;
}
if ( F_64 ( V_8 ) > V_173 ) {
F_93 ( 1 , L_1 ) ;
goto V_42;
}
if ( V_10 -> V_49 . type == F_47 ( V_174 ) ) {
struct V_165 V_175 ;
unsigned long V_176 ;
F_89 ( V_157 , V_8 , V_168 ,
F_21 ( V_10 ) ) ;
F_94 ( & V_175 , & V_177 , NULL , 1 ,
V_178 , V_179 ) ;
V_175 . V_166 = V_157 -> V_166 ;
V_176 = V_8 -> V_170 ;
F_95 ( V_8 , & V_175 ) ;
F_90 ( V_8 ) -> V_180 = V_172 ;
F_96 ( V_151 , V_8 -> V_153 , V_8 , F_83 ) ;
F_97 ( V_176 ) ;
} else if ( V_10 -> V_49 . type == F_47 ( V_181 ) ) {
const struct V_182 * V_183 = F_98 () ;
unsigned long V_176 ;
struct V_184 V_185 ;
if ( ! V_183 ) {
goto V_42;
}
F_89 ( V_157 , V_8 , V_168 ,
F_21 ( V_10 ) ) ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
F_94 ( & V_185 . V_60 , & V_177 , NULL , 1 ,
V_178 , V_179 ) ;
V_185 . V_60 . V_166 = V_157 -> V_166 ;
V_176 = V_8 -> V_170 ;
F_95 ( V_8 , & V_185 . V_60 ) ;
F_99 ( V_8 ) -> V_180 = V_172 ;
V_183 -> V_186 ( V_151 , V_8 -> V_153 , V_8 , F_83 ) ;
F_97 ( V_176 ) ;
} else {
F_100 ( 1 , L_2 ,
F_101 ( V_157 ) , F_36 ( V_10 -> V_49 . type ) , V_172 ,
V_157 -> V_166 -> V_167 ) ;
goto V_42;
}
return;
V_42:
F_84 ( V_8 ) ;
}
static void F_102 ( struct V_187 * V_188 , struct V_7 * V_8 , int V_189 ,
struct V_9 * V_10 )
{
struct V_157 * V_157 = F_103 ( V_188 , V_189 ) ;
if ( F_48 ( V_157 ) ) {
T_4 V_172 = F_86 ( V_8 ) -> V_172 ;
T_5 V_190 = F_86 ( V_8 ) -> V_190 ;
if ( F_25 ( V_190 > 0 ) ) {
if ( V_8 -> V_77 - V_190 > F_104 ( V_10 ) )
F_105 ( V_8 , V_8 -> V_77 - V_190 ) ;
else
F_105 ( V_8 , F_104 ( V_10 ) ) ;
}
if ( F_48 ( ! V_172 ||
( V_8 -> V_77 <= V_172 + V_157 -> V_166 -> V_191 ) ) ) {
F_87 ( V_157 , V_8 , F_21 ( V_10 ) ) ;
} else if ( V_172 <= V_157 -> V_166 -> V_167 ) {
struct V_151 * V_151 = F_106 ( & V_188 -> V_151 ) ;
F_92 ( V_151 , V_157 , V_8 , V_172 , V_10 ) ;
} else {
F_84 ( V_8 ) ;
}
} else {
F_84 ( V_8 ) ;
}
}
static int F_107 ( struct V_187 * V_188 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_11 * V_15 , int V_192 ,
T_8 V_190 )
{
struct V_193 V_194 ;
const struct V_11 * V_195 ;
int V_196 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_194 . V_197 = V_198 ;
V_194 . V_172 = F_86 ( V_8 ) -> V_172 ;
for ( V_195 = F_108 ( V_12 ) , V_196 = F_109 ( V_12 ) ; V_196 > 0 ;
V_195 = F_110 ( V_195 , & V_196 ) ) {
switch ( F_111 ( V_195 ) ) {
case V_199 :
V_194 . V_200 = V_195 ;
break;
case V_201 :
V_194 . V_202 = F_112 ( V_195 ) ;
break;
case V_203 : {
struct V_157 * V_157 ;
V_157 = F_103 ( V_188 , F_112 ( V_195 ) ) ;
if ( V_157 ) {
int V_42 ;
V_42 = F_113 ( V_157 -> V_166 , V_8 ) ;
if ( ! V_42 )
V_194 . V_204 = F_114 ( V_8 ) ;
}
break;
}
case V_205 : {
V_194 . V_15 = V_15 ;
V_194 . V_192 = V_192 ;
break;
}
}
}
return F_115 ( V_188 , V_8 , V_10 , & V_194 , V_190 ) ;
}
static int F_116 ( struct V_187 * V_188 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_11 * V_15 , int V_192 )
{
const struct V_11 * V_206 = NULL ;
const struct V_11 * V_195 ;
int V_196 ;
T_5 V_190 = 0 ;
for ( V_195 = F_108 ( V_12 ) , V_196 = F_109 ( V_12 ) ; V_196 > 0 ;
V_195 = F_110 ( V_195 , & V_196 ) ) {
T_5 V_207 ;
switch ( F_111 ( V_195 ) ) {
case V_208 :
V_207 = F_112 ( V_195 ) ;
if ( ! V_207 || F_117 () > V_207 )
return 0 ;
break;
case V_209 :
V_206 = V_195 ;
break;
}
}
V_196 = F_109 ( V_206 ) ;
V_195 = F_108 ( V_206 ) ;
if ( F_25 ( ! V_196 ) )
return 0 ;
if ( F_25 ( F_111 ( V_195 ) == V_210 ) ) {
struct V_211 * V_212 = F_108 ( V_195 ) ;
if ( V_8 -> V_77 > V_212 -> V_213 )
V_190 = V_8 -> V_77 - V_212 -> V_213 ;
V_195 = F_110 ( V_195 , & V_196 ) ;
}
if ( F_48 ( F_111 ( V_195 ) == V_214 &&
F_118 ( V_195 , V_196 ) ) )
return F_107 ( V_188 , V_8 , V_10 , V_195 , V_15 ,
V_192 , V_190 ) ;
V_8 = F_119 ( V_8 , V_215 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_5 ( V_8 , V_10 , V_195 ) ) {
if ( F_120 () )
F_121 ( L_3 ,
F_122 ( V_188 ) ) ;
F_84 ( V_8 ) ;
}
return 0 ;
}
static void F_123 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_216 * V_217 = F_108 ( V_12 ) ;
T_5 V_218 = 0 ;
V_218 = F_124 ( V_8 ) ;
V_218 = F_125 ( V_218 , V_217 -> V_219 ) ;
if ( ! V_218 )
V_218 = 0x1 ;
V_10 -> V_220 = V_218 ;
}
static int F_126 ( struct V_7 * V_8 ,
struct V_9 * V_44 ,
const struct V_11 * V_195 )
{
if ( F_111 ( V_195 ) == V_221 ) {
struct V_222 * V_223 = F_108 ( V_195 ) ;
F_127 ( V_8 ) ;
F_128 ( (struct V_165 * ) V_223 -> V_224 ) ;
F_129 ( V_8 , (struct V_165 * ) V_223 -> V_224 ) ;
return 0 ;
}
return - V_225 ;
}
static int F_130 ( struct V_7 * V_8 ,
struct V_9 * V_44 ,
const struct V_11 * V_195 )
{
int V_42 = 0 ;
switch ( F_111 ( V_195 ) ) {
case V_226 :
F_38 ( V_8 -> V_227 , F_112 ( V_195 ) ,
* F_131 ( V_195 , T_5 * ) ) ;
V_44 -> V_228 . V_227 = V_8 -> V_227 ;
break;
case V_229 :
F_38 ( V_8 -> V_230 , F_112 ( V_195 ) , * F_131 ( V_195 , T_5 * ) ) ;
V_44 -> V_228 . V_231 = V_8 -> V_230 ;
break;
case V_221 :
V_42 = - V_225 ;
break;
case V_232 :
V_42 = F_39 ( V_8 , V_44 , F_108 ( V_195 ) ,
F_131 ( V_195 , struct V_62 * ) ) ;
break;
case V_233 :
V_42 = F_63 ( V_8 , V_44 , F_108 ( V_195 ) ,
F_131 ( V_195 , struct V_102 * ) ) ;
break;
case V_234 :
V_42 = F_68 ( V_8 , V_44 , F_108 ( V_195 ) ,
F_131 ( V_195 , struct V_112 * ) ) ;
break;
case V_235 :
V_42 = F_79 ( V_8 , V_44 , F_108 ( V_195 ) ,
F_131 ( V_195 , struct V_137 * ) ) ;
break;
case V_236 :
V_42 = F_78 ( V_8 , V_44 , F_108 ( V_195 ) ,
F_131 ( V_195 , struct V_131 * ) ) ;
break;
case V_237 :
V_42 = F_80 ( V_8 , V_44 , F_108 ( V_195 ) ,
F_131 ( V_195 , struct V_141 * ) ) ;
break;
case V_238 :
V_42 = F_29 ( V_8 , V_44 , F_108 ( V_195 ) , F_131 ( V_195 ,
T_2 * ) ) ;
break;
case V_239 :
case V_240 :
case V_241 :
case V_242 :
V_42 = - V_225 ;
break;
}
return V_42 ;
}
static int F_132 ( struct V_187 * V_188 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_195 , int V_196 )
{
struct V_5 * V_13 ;
int V_243 ;
if ( ! F_8 ( V_10 ) ) {
int V_42 ;
V_42 = F_133 ( V_8 , V_10 ) ;
if ( V_42 )
return V_42 ;
}
F_134 ( ! F_8 ( V_10 ) ) ;
if ( ! F_118 ( V_195 , V_196 ) ) {
V_8 = F_119 ( V_8 , V_215 ) ;
if ( ! V_8 )
return 0 ;
}
V_243 = F_135 ( V_244 ) ;
if ( V_243 <= V_245 ) {
struct V_246 * V_247 = F_6 ( V_246 ) ;
struct V_9 * V_248 = & V_247 -> V_10 [ V_243 - 1 ] ;
* V_248 = * V_10 ;
V_248 -> V_249 = F_112 ( V_195 ) ;
F_136 ( V_8 , V_248 ) ;
return 0 ;
}
V_13 = F_5 ( V_8 , V_10 , NULL ) ;
if ( V_13 ) {
V_13 -> V_16 . V_249 = F_112 ( V_195 ) ;
} else {
F_84 ( V_8 ) ;
if ( F_120 () )
F_121 ( L_4 ,
F_122 ( V_188 ) ) ;
}
return 0 ;
}
static int F_137 ( struct V_187 * V_188 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 , int V_77 )
{
int V_250 = - 1 ;
const struct V_11 * V_195 ;
int V_196 ;
for ( V_195 = V_12 , V_196 = V_77 ; V_196 > 0 ;
V_195 = F_110 ( V_195 , & V_196 ) ) {
int V_42 = 0 ;
if ( F_25 ( V_250 != - 1 ) ) {
struct V_7 * V_251 = F_119 ( V_8 , V_215 ) ;
if ( V_251 )
F_102 ( V_188 , V_251 , V_250 , V_10 ) ;
F_86 ( V_8 ) -> V_190 = 0 ;
V_250 = - 1 ;
}
switch ( F_111 ( V_195 ) ) {
case V_252 :
V_250 = F_112 ( V_195 ) ;
break;
case V_210 : {
struct V_211 * V_212 = F_108 ( V_195 ) ;
if ( V_8 -> V_77 > V_212 -> V_213 )
F_86 ( V_8 ) -> V_190 = V_8 -> V_77 - V_212 -> V_213 ;
break;
}
case V_214 :
F_107 ( V_188 , V_8 , V_10 , V_195 , V_12 ,
V_77 , F_86 ( V_8 ) -> V_190 ) ;
F_86 ( V_8 ) -> V_190 = 0 ;
break;
case V_253 :
F_123 ( V_8 , V_10 , V_195 ) ;
break;
case V_254 :
V_42 = F_11 ( V_8 , V_10 , F_108 ( V_195 ) ) ;
break;
case V_255 :
V_42 = F_23 ( V_8 , V_10 , F_138 ( V_195 ) ) ;
break;
case V_256 :
V_42 = F_34 ( V_8 , V_10 , F_108 ( V_195 ) ) ;
break;
case V_257 :
V_42 = F_31 ( V_8 , V_10 ) ;
break;
case V_258 :
V_42 = F_132 ( V_188 , V_8 , V_10 , V_195 , V_196 ) ;
if ( F_118 ( V_195 , V_196 ) ) {
return V_42 ;
}
break;
case V_259 :
V_42 = F_126 ( V_8 , V_10 , F_108 ( V_195 ) ) ;
break;
case V_260 :
case V_261 :
V_42 = F_130 ( V_8 , V_10 , F_108 ( V_195 ) ) ;
break;
case V_262 :
V_42 = F_116 ( V_188 , V_8 , V_10 , V_195 , V_12 , V_77 ) ;
break;
case V_263 :
if ( ! F_8 ( V_10 ) ) {
V_42 = F_133 ( V_8 , V_10 ) ;
if ( V_42 )
return V_42 ;
}
V_42 = F_139 ( F_140 ( V_188 ) , V_8 , V_10 ,
F_108 ( V_195 ) ) ;
if ( V_42 )
return V_42 == - V_264 ? 0 : V_42 ;
break;
case V_265 :
V_42 = F_44 ( V_8 , V_10 , F_108 ( V_195 ) ) ;
break;
case V_266 :
V_42 = F_41 ( V_8 , V_10 ) ;
break;
}
if ( F_25 ( V_42 ) ) {
F_84 ( V_8 ) ;
return V_42 ;
}
}
if ( V_250 != - 1 )
F_102 ( V_188 , V_8 , V_250 , V_10 ) ;
else
F_141 ( V_8 ) ;
return 0 ;
}
static void F_142 ( struct V_187 * V_188 )
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
F_137 ( V_188 , V_8 , V_10 , V_15 ,
F_109 ( V_15 ) ) ;
else
F_136 ( V_8 , V_10 ) ;
} while ( ! F_2 ( V_2 ) );
F_1 ( V_2 ) ;
}
int F_143 ( struct V_187 * V_188 , struct V_7 * V_8 ,
const struct V_267 * V_268 ,
struct V_9 * V_10 )
{
int V_42 , V_243 ;
V_243 = F_144 ( V_244 ) ;
if ( F_25 ( V_243 > V_269 ) ) {
F_145 ( L_5 ,
F_122 ( V_188 ) ) ;
F_84 ( V_8 ) ;
V_42 = - V_270 ;
goto V_271;
}
V_42 = F_137 ( V_188 , V_8 , V_10 ,
V_268 -> V_15 , V_268 -> V_192 ) ;
if ( V_243 == 1 )
F_142 ( V_188 ) ;
V_271:
F_146 ( V_244 ) ;
return V_42 ;
}
int F_147 ( void )
{
V_14 = F_148 ( struct V_1 ) ;
if ( ! V_14 )
return - V_34 ;
V_246 = F_148 ( struct V_246 ) ;
if ( ! V_246 ) {
F_149 ( V_14 ) ;
return - V_34 ;
}
return 0 ;
}
void F_150 ( void )
{
F_149 ( V_14 ) ;
F_149 ( V_246 ) ;
}
