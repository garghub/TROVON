static struct V_1 * F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
int V_6 = F_3 ( V_7 ) ;
struct V_1 * V_8 = NULL ;
if ( V_6 <= V_9 ) {
V_8 = & V_4 -> V_8 [ V_6 - 1 ] ;
* V_8 = * V_2 ;
}
return V_8 ;
}
static void F_4 ( struct V_10 * V_11 )
{
V_11 -> V_12 = 0 ;
V_11 -> V_13 = 0 ;
}
static bool F_5 ( const struct V_10 * V_11 )
{
return ( V_11 -> V_12 == V_11 -> V_13 ) ;
}
static struct V_14 * F_6 ( struct V_10 * V_11 )
{
if ( F_5 ( V_11 ) )
return NULL ;
return & V_11 -> V_11 [ V_11 -> V_13 ++ ] ;
}
static struct V_14 * F_7 ( struct V_10 * V_11 )
{
if ( V_11 -> V_12 >= V_15 - 1 )
return NULL ;
return & V_11 -> V_11 [ V_11 -> V_12 ++ ] ;
}
static struct V_14 * F_8 ( struct V_16 * V_17 ,
const struct V_1 * V_8 ,
const struct V_18 * V_19 ,
const int V_20 )
{
struct V_10 * V_11 ;
struct V_14 * V_21 ;
V_11 = F_2 ( V_22 ) ;
V_21 = F_7 ( V_11 ) ;
if ( V_21 ) {
V_21 -> V_17 = V_17 ;
V_21 -> V_19 = V_19 ;
V_21 -> V_20 = V_20 ;
V_21 -> V_23 = * V_8 ;
}
return V_21 ;
}
static void F_9 ( struct V_1 * V_8 )
{
V_8 -> V_24 |= V_25 ;
}
static bool F_10 ( const struct V_1 * V_8 )
{
return ! ( V_8 -> V_24 & V_25 ) ;
}
static void F_11 ( struct V_16 * V_17 , struct V_26 * V_27 ,
T_1 V_28 )
{
if ( V_17 -> V_29 == V_30 ) {
T_1 V_31 [] = { ~ ( V_27 -> V_32 ) , V_28 } ;
V_17 -> V_33 = ~ F_12 ( ( char * ) V_31 , sizeof( V_31 ) ,
~ V_17 -> V_33 ) ;
}
V_27 -> V_32 = V_28 ;
}
static int F_13 ( struct V_16 * V_17 , struct V_1 * V_8 ,
const struct V_34 * V_35 )
{
struct V_36 * V_37 ;
if ( V_17 -> V_38 )
return - V_39 ;
if ( F_14 ( V_17 , V_40 ) < 0 )
return - V_41 ;
if ( ! V_17 -> V_42 ) {
F_15 ( V_17 , V_17 -> V_43 ) ;
F_16 ( V_17 , V_17 -> V_44 ) ;
}
F_17 ( V_17 , V_40 ) ;
memmove ( F_18 ( V_17 ) - V_40 , F_18 ( V_17 ) ,
V_17 -> V_43 ) ;
F_19 ( V_17 ) ;
F_20 ( V_17 , V_17 -> V_43 ) ;
V_37 = F_21 ( V_17 ) ;
V_37 -> V_45 = V_35 -> V_46 ;
F_22 ( V_17 , V_37 , V_40 ) ;
if ( F_23 ( V_8 ) == V_47 )
F_11 ( V_17 , F_24 ( V_17 ) , V_35 -> V_48 ) ;
V_17 -> V_44 = V_35 -> V_48 ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 , struct V_1 * V_8 ,
const T_1 V_28 )
{
int V_49 ;
V_49 = F_26 ( V_17 , V_17 -> V_43 + V_40 ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
F_28 ( V_17 , F_21 ( V_17 ) , V_40 ) ;
memmove ( F_18 ( V_17 ) + V_40 , F_18 ( V_17 ) ,
V_17 -> V_43 ) ;
F_29 ( V_17 , V_40 ) ;
F_19 ( V_17 ) ;
F_20 ( V_17 , V_17 -> V_43 ) ;
if ( F_23 ( V_8 ) == V_47 ) {
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) ( ( void * ) F_21 ( V_17 ) - V_50 ) ;
F_11 ( V_17 , V_27 , V_28 ) ;
}
if ( F_30 ( V_17 -> V_44 ) )
V_17 -> V_44 = V_28 ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const T_2 * V_46 , const T_2 * V_52 )
{
struct V_36 * V_53 ;
T_2 V_54 ;
int V_49 ;
V_49 = F_26 ( V_17 , V_17 -> V_43 + V_40 ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_53 = F_21 ( V_17 ) ;
V_54 = F_32 ( V_53 -> V_45 , * V_46 , * V_52 ) ;
if ( V_17 -> V_29 == V_30 ) {
T_2 V_31 [] = { ~ ( V_53 -> V_45 ) , V_54 } ;
V_17 -> V_33 = ~ F_12 ( ( char * ) V_31 , sizeof( V_31 ) ,
~ V_17 -> V_33 ) ;
}
V_53 -> V_45 = V_54 ;
V_51 -> V_35 . V_55 = V_54 ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 , struct V_1 * V_8 )
{
int V_49 ;
V_49 = F_34 ( V_17 ) ;
if ( F_35 ( V_17 ) ) {
F_9 ( V_8 ) ;
} else {
V_8 -> V_56 . V_57 . V_58 = 0 ;
V_8 -> V_56 . V_57 . V_59 = 0 ;
}
return V_49 ;
}
static int F_36 ( struct V_16 * V_17 , struct V_1 * V_8 ,
const struct V_60 * V_57 )
{
if ( F_35 ( V_17 ) ) {
F_9 ( V_8 ) ;
} else {
V_8 -> V_56 . V_57 . V_58 = V_57 -> V_61 ;
V_8 -> V_56 . V_57 . V_59 = V_57 -> V_62 ;
}
return F_37 ( V_17 , V_57 -> V_62 ,
F_38 ( V_57 -> V_61 ) & ~ V_63 ) ;
}
static void F_39 ( T_3 * V_64 , const T_3 * V_65 , const T_3 * V_66 )
{
T_4 * V_67 = ( T_4 * ) V_64 ;
const T_4 * V_68 = ( const T_4 * ) V_65 ;
const T_4 * V_52 = ( const T_4 * ) V_66 ;
F_40 ( V_67 [ 0 ] , V_68 [ 0 ] , V_52 [ 0 ] ) ;
F_40 ( V_67 [ 1 ] , V_68 [ 1 ] , V_52 [ 1 ] ) ;
F_40 ( V_67 [ 2 ] , V_68 [ 2 ] , V_52 [ 2 ] ) ;
}
static int F_41 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const struct V_69 * V_8 ,
const struct V_69 * V_52 )
{
int V_49 ;
V_49 = F_26 ( V_17 , V_50 ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
F_28 ( V_17 , F_24 ( V_17 ) , V_70 * 2 ) ;
F_39 ( F_24 ( V_17 ) -> V_71 , V_8 -> V_72 ,
V_52 -> V_72 ) ;
F_39 ( F_24 ( V_17 ) -> V_73 , V_8 -> V_74 ,
V_52 -> V_74 ) ;
F_22 ( V_17 , F_24 ( V_17 ) , V_70 * 2 ) ;
F_42 ( V_51 -> V_56 . V_68 , F_24 ( V_17 ) -> V_71 ) ;
F_42 ( V_51 -> V_56 . V_67 , F_24 ( V_17 ) -> V_73 ) ;
return 0 ;
}
static int F_43 ( struct V_16 * V_17 , struct V_1 * V_8 )
{
F_44 ( V_17 , V_50 ) ;
F_19 ( V_17 ) ;
F_45 ( V_17 ) ;
V_8 -> V_24 = V_75 ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_46 ( struct V_16 * V_17 , struct V_1 * V_8 ,
const struct V_76 * V_77 )
{
struct V_26 * V_27 ;
if ( F_14 ( V_17 , V_50 ) < 0 )
return - V_41 ;
F_17 ( V_17 , V_50 ) ;
F_19 ( V_17 ) ;
F_45 ( V_17 ) ;
V_27 = F_24 ( V_17 ) ;
F_42 ( V_27 -> V_71 , V_77 -> V_78 . V_72 ) ;
F_42 ( V_27 -> V_73 , V_77 -> V_78 . V_74 ) ;
V_27 -> V_32 = V_17 -> V_44 ;
F_22 ( V_17 , V_27 , V_50 ) ;
V_8 -> V_24 = V_47 ;
F_9 ( V_8 ) ;
return 0 ;
}
static void F_47 ( struct V_16 * V_17 , struct V_79 * V_80 ,
T_2 V_81 , T_2 V_82 )
{
int V_83 = V_17 -> V_84 - F_48 ( V_17 ) ;
if ( V_80 -> V_85 & F_49 ( V_86 ) )
return;
if ( V_80 -> V_44 == V_87 ) {
if ( F_50 ( V_83 >= sizeof( struct V_88 ) ) )
F_51 ( & F_52 ( V_17 ) -> V_89 , V_17 ,
V_81 , V_82 , true ) ;
} else if ( V_80 -> V_44 == V_90 ) {
if ( F_50 ( V_83 >= sizeof( struct V_91 ) ) ) {
struct V_91 * V_92 = F_53 ( V_17 ) ;
if ( V_92 -> V_89 || V_17 -> V_29 == V_93 ) {
F_51 ( & V_92 -> V_89 , V_17 ,
V_81 , V_82 , true ) ;
if ( ! V_92 -> V_89 )
V_92 -> V_89 = V_94 ;
}
}
}
}
static void F_54 ( struct V_16 * V_17 , struct V_79 * V_80 ,
T_2 * V_81 , T_2 V_82 )
{
F_47 ( V_17 , V_80 , * V_81 , V_82 ) ;
F_55 ( & V_80 -> V_89 , * V_81 , V_82 ) ;
F_56 ( V_17 ) ;
* V_81 = V_82 ;
}
static void F_57 ( struct V_16 * V_17 , T_3 V_95 ,
T_2 V_81 [ 4 ] , const T_2 V_82 [ 4 ] )
{
int V_83 = V_17 -> V_84 - F_48 ( V_17 ) ;
if ( V_95 == V_96 ) {
if ( F_50 ( V_83 >= sizeof( struct V_88 ) ) )
F_58 ( & F_52 ( V_17 ) -> V_89 , V_17 ,
V_81 , V_82 , true ) ;
} else if ( V_95 == V_97 ) {
if ( F_50 ( V_83 >= sizeof( struct V_91 ) ) ) {
struct V_91 * V_92 = F_53 ( V_17 ) ;
if ( V_92 -> V_89 || V_17 -> V_29 == V_93 ) {
F_58 ( & V_92 -> V_89 , V_17 ,
V_81 , V_82 , true ) ;
if ( ! V_92 -> V_89 )
V_92 -> V_89 = V_94 ;
}
}
} else if ( V_95 == V_98 ) {
if ( F_50 ( V_83 >= sizeof( struct V_99 ) ) )
F_58 ( & F_59 ( V_17 ) -> V_100 ,
V_17 , V_81 , V_82 , true ) ;
}
}
static void F_60 ( const T_2 V_101 [ 4 ] , const T_2 V_81 [ 4 ] ,
const T_2 V_52 [ 4 ] , T_2 V_102 [ 4 ] )
{
V_102 [ 0 ] = F_32 ( V_101 [ 0 ] , V_81 [ 0 ] , V_52 [ 0 ] ) ;
V_102 [ 1 ] = F_32 ( V_101 [ 1 ] , V_81 [ 1 ] , V_52 [ 1 ] ) ;
V_102 [ 2 ] = F_32 ( V_101 [ 2 ] , V_81 [ 2 ] , V_52 [ 2 ] ) ;
V_102 [ 3 ] = F_32 ( V_101 [ 3 ] , V_81 [ 3 ] , V_52 [ 3 ] ) ;
}
static void F_61 ( struct V_16 * V_17 , T_3 V_95 ,
T_2 V_81 [ 4 ] , const T_2 V_82 [ 4 ] ,
bool V_103 )
{
if ( V_103 )
F_57 ( V_17 , V_95 , V_81 , V_82 ) ;
F_56 ( V_17 ) ;
memcpy ( V_81 , V_82 , sizeof( T_2 [ 4 ] ) ) ;
}
static void F_62 ( struct V_104 * V_80 , T_5 V_105 , T_5 V_52 )
{
F_40 ( V_80 -> V_106 [ 0 ] , ( T_3 ) ( V_105 >> 16 ) , ( T_3 ) ( V_52 >> 16 ) ) ;
F_40 ( V_80 -> V_106 [ 1 ] , ( T_3 ) ( V_105 >> 8 ) , ( T_3 ) ( V_52 >> 8 ) ) ;
F_40 ( V_80 -> V_106 [ 2 ] , ( T_3 ) V_105 , ( T_3 ) V_52 ) ;
}
static void F_63 ( struct V_16 * V_17 , struct V_79 * V_80 , T_3 V_107 ,
T_3 V_52 )
{
V_107 = F_32 ( V_80 -> V_108 , V_107 , V_52 ) ;
F_64 ( & V_80 -> V_89 , F_49 ( V_80 -> V_108 << 8 ) , F_49 ( V_107 << 8 ) ) ;
V_80 -> V_108 = V_107 ;
}
static int F_65 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const struct V_109 * V_8 ,
const struct V_109 * V_52 )
{
struct V_79 * V_80 ;
T_2 V_82 ;
int V_49 ;
V_49 = F_26 ( V_17 , F_66 ( V_17 ) +
sizeof( struct V_79 ) ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_80 = F_67 ( V_17 ) ;
if ( V_52 -> V_110 ) {
V_82 = F_32 ( V_80 -> V_111 , V_8 -> V_110 , V_52 -> V_110 ) ;
if ( F_27 ( V_82 != V_80 -> V_111 ) ) {
F_54 ( V_17 , V_80 , & V_80 -> V_111 , V_82 ) ;
V_51 -> V_112 . V_81 . V_68 = V_82 ;
}
}
if ( V_52 -> V_113 ) {
V_82 = F_32 ( V_80 -> V_114 , V_8 -> V_113 , V_52 -> V_113 ) ;
if ( F_27 ( V_82 != V_80 -> V_114 ) ) {
F_54 ( V_17 , V_80 , & V_80 -> V_114 , V_82 ) ;
V_51 -> V_112 . V_81 . V_67 = V_82 ;
}
}
if ( V_52 -> V_115 ) {
F_68 ( V_80 , ~ V_52 -> V_115 , V_8 -> V_115 ) ;
V_51 -> V_116 . V_117 = V_80 -> V_117 ;
}
if ( V_52 -> V_118 ) {
F_63 ( V_17 , V_80 , V_8 -> V_118 , V_52 -> V_118 ) ;
V_51 -> V_116 . V_108 = V_80 -> V_108 ;
}
return 0 ;
}
static bool F_69 ( const T_2 V_81 [ 4 ] )
{
return ! ! ( V_81 [ 0 ] | V_81 [ 1 ] | V_81 [ 2 ] | V_81 [ 3 ] ) ;
}
static int F_70 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const struct V_119 * V_8 ,
const struct V_119 * V_52 )
{
struct V_104 * V_80 ;
int V_49 ;
V_49 = F_26 ( V_17 , F_66 ( V_17 ) +
sizeof( struct V_104 ) ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_80 = F_71 ( V_17 ) ;
if ( F_69 ( V_52 -> V_120 ) ) {
T_2 * V_111 = ( T_2 * ) & V_80 -> V_111 ;
T_2 V_102 [ 4 ] ;
F_60 ( V_111 , V_8 -> V_120 , V_52 -> V_120 , V_102 ) ;
if ( F_27 ( memcmp ( V_111 , V_102 , sizeof( V_102 ) ) ) ) {
F_61 ( V_17 , V_51 -> V_116 . V_121 , V_111 , V_102 ,
true ) ;
memcpy ( & V_51 -> V_122 . V_81 . V_68 , V_102 ,
sizeof( V_51 -> V_122 . V_81 . V_68 ) ) ;
}
}
if ( F_69 ( V_52 -> V_123 ) ) {
unsigned int V_124 = 0 ;
int V_125 = V_126 ;
bool V_127 = true ;
T_2 * V_114 = ( T_2 * ) & V_80 -> V_114 ;
T_2 V_102 [ 4 ] ;
F_60 ( V_114 , V_8 -> V_123 , V_52 -> V_123 , V_102 ) ;
if ( F_27 ( memcmp ( V_114 , V_102 , sizeof( V_102 ) ) ) ) {
if ( F_72 ( V_80 -> V_128 ) )
V_127 = ( F_73 ( V_17 , & V_124 ,
V_129 ,
NULL , & V_125 )
!= V_129 ) ;
F_61 ( V_17 , V_51 -> V_116 . V_121 , V_114 , V_102 ,
V_127 ) ;
memcpy ( & V_51 -> V_122 . V_81 . V_67 , V_102 ,
sizeof( V_51 -> V_122 . V_81 . V_67 ) ) ;
}
}
if ( V_52 -> V_130 ) {
F_74 ( V_80 , ~ V_52 -> V_130 , V_8 -> V_130 ) ;
V_51 -> V_116 . V_117 = F_75 ( V_80 ) ;
}
if ( V_52 -> V_131 ) {
F_62 ( V_80 , F_76 ( V_8 -> V_131 ) ,
F_76 ( V_52 -> V_131 ) ) ;
V_51 -> V_122 . V_132 =
* ( T_2 * ) V_80 & F_77 ( V_133 ) ;
}
if ( V_52 -> V_134 ) {
F_40 ( V_80 -> V_135 , V_8 -> V_134 ,
V_52 -> V_134 ) ;
V_51 -> V_116 . V_108 = V_80 -> V_135 ;
}
return 0 ;
}
static void F_78 ( struct V_16 * V_17 , T_1 * V_136 ,
T_1 V_137 , T_6 * V_89 )
{
F_79 ( V_89 , V_17 , * V_136 , V_137 , false ) ;
* V_136 = V_137 ;
}
static int F_80 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const struct V_138 * V_8 ,
const struct V_138 * V_52 )
{
struct V_91 * V_92 ;
T_1 V_68 , V_67 ;
int V_49 ;
V_49 = F_26 ( V_17 , F_48 ( V_17 ) +
sizeof( struct V_91 ) ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_92 = F_53 ( V_17 ) ;
V_68 = F_32 ( V_92 -> V_139 , V_8 -> V_140 , V_52 -> V_140 ) ;
V_67 = F_32 ( V_92 -> V_141 , V_8 -> V_142 , V_52 -> V_142 ) ;
if ( V_92 -> V_89 && V_17 -> V_29 != V_93 ) {
if ( F_50 ( V_68 != V_92 -> V_139 ) ) {
F_78 ( V_17 , & V_92 -> V_139 , V_68 , & V_92 -> V_89 ) ;
V_51 -> V_143 . V_68 = V_68 ;
}
if ( F_50 ( V_67 != V_92 -> V_141 ) ) {
F_78 ( V_17 , & V_92 -> V_141 , V_67 , & V_92 -> V_89 ) ;
V_51 -> V_143 . V_67 = V_67 ;
}
if ( F_27 ( ! V_92 -> V_89 ) )
V_92 -> V_89 = V_94 ;
} else {
V_92 -> V_139 = V_68 ;
V_92 -> V_141 = V_67 ;
V_51 -> V_143 . V_68 = V_68 ;
V_51 -> V_143 . V_67 = V_67 ;
}
F_56 ( V_17 ) ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const struct V_144 * V_8 ,
const struct V_144 * V_52 )
{
struct V_88 * V_145 ;
T_1 V_68 , V_67 ;
int V_49 ;
V_49 = F_26 ( V_17 , F_48 ( V_17 ) +
sizeof( struct V_88 ) ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_145 = F_52 ( V_17 ) ;
V_68 = F_32 ( V_145 -> V_139 , V_8 -> V_146 , V_52 -> V_146 ) ;
if ( F_50 ( V_68 != V_145 -> V_139 ) ) {
F_78 ( V_17 , & V_145 -> V_139 , V_68 , & V_145 -> V_89 ) ;
V_51 -> V_143 . V_68 = V_68 ;
}
V_67 = F_32 ( V_145 -> V_141 , V_8 -> V_147 , V_52 -> V_147 ) ;
if ( F_50 ( V_67 != V_145 -> V_141 ) ) {
F_78 ( V_17 , & V_145 -> V_141 , V_67 , & V_145 -> V_89 ) ;
V_51 -> V_143 . V_67 = V_67 ;
}
F_56 ( V_17 ) ;
return 0 ;
}
static int F_82 ( struct V_16 * V_17 , struct V_1 * V_51 ,
const struct V_148 * V_8 ,
const struct V_148 * V_52 )
{
unsigned int V_149 = F_48 ( V_17 ) ;
struct V_150 * V_151 ;
T_7 V_152 , V_153 , V_154 ;
int V_49 ;
V_49 = F_26 ( V_17 , V_149 + sizeof( struct V_150 ) ) ;
if ( F_27 ( V_49 ) )
return V_49 ;
V_151 = F_83 ( V_17 ) ;
V_154 = V_151 -> V_155 ;
V_152 = F_84 ( V_17 , V_149 ) ;
V_151 -> V_139 = F_32 ( V_151 -> V_139 , V_8 -> V_156 , V_52 -> V_156 ) ;
V_151 -> V_141 = F_32 ( V_151 -> V_141 , V_8 -> V_157 , V_52 -> V_157 ) ;
V_153 = F_84 ( V_17 , V_149 ) ;
V_151 -> V_155 = V_154 ^ V_152 ^ V_153 ;
F_56 ( V_17 ) ;
V_51 -> V_143 . V_68 = V_151 -> V_139 ;
V_51 -> V_143 . V_67 = V_151 -> V_141 ;
return 0 ;
}
static int F_85 ( struct V_158 * V_158 , struct V_159 * V_160 , struct V_16 * V_17 )
{
struct V_161 * V_162 = F_2 ( & V_163 ) ;
struct V_164 * V_164 = V_162 -> V_164 ;
if ( F_14 ( V_17 , V_162 -> V_165 ) < 0 ) {
F_86 ( V_17 ) ;
return - V_41 ;
}
F_87 ( V_17 , V_162 -> V_67 ) ;
* F_88 ( V_17 ) = V_162 -> V_166 ;
V_17 -> V_42 = V_162 -> V_42 ;
V_17 -> V_61 = V_162 -> V_61 ;
V_17 -> V_167 = V_162 -> V_167 ;
F_17 ( V_17 , V_162 -> V_165 ) ;
memcpy ( V_17 -> V_162 , & V_162 -> V_168 , V_162 -> V_165 ) ;
F_22 ( V_17 , V_17 -> V_162 , V_162 -> V_165 ) ;
F_19 ( V_17 ) ;
if ( F_30 ( V_17 -> V_44 ) ) {
V_17 -> V_169 = V_17 -> V_170 ;
F_20 ( V_17 , V_162 -> V_171 ) ;
F_45 ( V_17 ) ;
}
F_89 ( V_164 , V_17 , V_162 -> V_24 ) ;
return 0 ;
}
static unsigned int
F_90 ( const struct V_172 * V_67 )
{
return V_67 -> V_173 -> V_174 ;
}
static void F_91 ( struct V_164 * V_164 , struct V_16 * V_17 ,
T_4 V_175 , T_3 V_24 )
{
unsigned int V_176 = F_66 ( V_17 ) ;
struct V_161 * V_162 ;
V_162 = F_2 ( & V_163 ) ;
V_162 -> V_67 = V_17 -> V_177 ;
V_162 -> V_164 = V_164 ;
V_162 -> V_166 = * F_88 ( V_17 ) ;
V_162 -> V_42 = V_17 -> V_42 ;
V_162 -> V_171 = V_175 ;
V_162 -> V_61 = V_17 -> V_61 ;
V_162 -> V_167 = V_17 -> V_167 ;
V_162 -> V_24 = V_24 ;
V_162 -> V_165 = V_176 ;
memcpy ( & V_162 -> V_168 , V_17 -> V_162 , V_176 ) ;
memset ( F_92 ( V_17 ) , 0 , sizeof( struct V_178 ) ) ;
F_93 ( V_17 , V_176 ) ;
}
static void F_94 ( struct V_158 * V_158 , struct V_164 * V_164 ,
struct V_16 * V_17 , T_4 V_179 ,
struct V_1 * V_8 )
{
T_4 V_175 = 0 ;
if ( F_30 ( V_17 -> V_44 ) ) {
V_175 = F_66 ( V_17 ) ;
V_17 -> V_170 = V_17 -> V_169 ;
}
if ( F_66 ( V_17 ) > V_180 ) {
F_95 ( 1 , L_1 ) ;
goto V_49;
}
if ( V_8 -> V_56 . type == F_49 ( V_181 ) ) {
struct V_172 V_182 ;
unsigned long V_183 ;
F_91 ( V_164 , V_17 , V_175 ,
F_23 ( V_8 ) ) ;
F_96 ( & V_182 , & V_184 , NULL , 1 ,
V_185 , V_186 ) ;
V_182 . V_173 = V_164 -> V_173 ;
V_183 = V_17 -> V_177 ;
F_97 ( V_17 , & V_182 ) ;
F_92 ( V_17 ) -> V_187 = V_179 ;
F_98 ( V_158 , V_17 -> V_160 , V_17 , F_85 ) ;
F_99 ( V_183 ) ;
} else if ( V_8 -> V_56 . type == F_49 ( V_188 ) ) {
const struct V_189 * V_190 = F_100 () ;
unsigned long V_183 ;
struct V_191 V_192 ;
if ( ! V_190 )
goto V_49;
F_91 ( V_164 , V_17 , V_175 ,
F_23 ( V_8 ) ) ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
F_96 ( & V_192 . V_67 , & V_184 , NULL , 1 ,
V_185 , V_186 ) ;
V_192 . V_67 . V_173 = V_164 -> V_173 ;
V_183 = V_17 -> V_177 ;
F_97 ( V_17 , & V_192 . V_67 ) ;
F_101 ( V_17 ) -> V_187 = V_179 ;
V_190 -> V_193 ( V_158 , V_17 -> V_160 , V_17 , F_85 ) ;
F_99 ( V_183 ) ;
} else {
F_102 ( 1 , L_2 ,
F_103 ( V_164 ) , F_38 ( V_8 -> V_56 . type ) , V_179 ,
V_164 -> V_173 -> V_174 ) ;
goto V_49;
}
return;
V_49:
F_86 ( V_17 ) ;
}
static void F_104 ( struct V_194 * V_195 , struct V_16 * V_17 , int V_196 ,
struct V_1 * V_8 )
{
struct V_164 * V_164 = F_105 ( V_195 , V_196 ) ;
if ( F_50 ( V_164 ) ) {
T_4 V_179 = F_88 ( V_17 ) -> V_179 ;
T_5 V_197 = F_88 ( V_17 ) -> V_197 ;
if ( F_27 ( V_197 > 0 ) ) {
if ( V_17 -> V_84 - V_197 > F_106 ( V_8 ) )
F_107 ( V_17 , V_17 -> V_84 - V_197 ) ;
else
F_107 ( V_17 , F_106 ( V_8 ) ) ;
}
if ( F_50 ( ! V_179 ||
( V_17 -> V_84 <= V_179 + V_164 -> V_173 -> V_198 ) ) ) {
F_89 ( V_164 , V_17 , F_23 ( V_8 ) ) ;
} else if ( V_179 <= V_164 -> V_173 -> V_174 ) {
struct V_158 * V_158 = F_108 ( & V_195 -> V_158 ) ;
F_94 ( V_158 , V_164 , V_17 , V_179 , V_8 ) ;
} else {
F_86 ( V_17 ) ;
}
} else {
F_86 ( V_17 ) ;
}
}
static int F_109 ( struct V_194 * V_195 , struct V_16 * V_17 ,
struct V_1 * V_8 , const struct V_18 * V_199 ,
const struct V_18 * V_19 , int V_20 ,
T_8 V_197 )
{
struct V_200 V_201 ;
const struct V_18 * V_202 ;
int V_203 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_204 = V_205 ;
V_201 . V_179 = F_88 ( V_17 ) -> V_179 ;
for ( V_202 = F_110 ( V_199 ) , V_203 = F_111 ( V_199 ) ; V_203 > 0 ;
V_202 = F_112 ( V_202 , & V_203 ) ) {
switch ( F_113 ( V_202 ) ) {
case V_206 :
V_201 . V_207 = V_202 ;
break;
case V_208 :
V_201 . V_209 = F_114 ( V_202 ) ;
break;
case V_210 : {
struct V_164 * V_164 ;
V_164 = F_105 ( V_195 , F_114 ( V_202 ) ) ;
if ( V_164 ) {
int V_49 ;
V_49 = F_115 ( V_164 -> V_173 , V_17 ) ;
if ( ! V_49 )
V_201 . V_211 = F_116 ( V_17 ) ;
}
break;
}
case V_212 : {
V_201 . V_19 = V_19 ;
V_201 . V_20 = V_20 ;
break;
}
}
}
return F_117 ( V_195 , V_17 , V_8 , & V_201 , V_197 ) ;
}
static int F_118 ( struct V_194 * V_195 , struct V_16 * V_17 ,
struct V_1 * V_8 , const struct V_18 * V_199 ,
bool V_213 )
{
struct V_18 * V_19 ;
struct V_18 * V_214 ;
int V_203 = F_111 ( V_199 ) ;
const struct V_214 * V_215 ;
bool V_216 ;
V_214 = F_110 ( V_199 ) ;
V_215 = F_110 ( V_214 ) ;
V_19 = F_112 ( V_214 , & V_203 ) ;
if ( ( V_215 -> V_217 != V_218 ) &&
( ! V_215 -> V_217 || F_119 () > V_215 -> V_217 ) ) {
if ( V_213 )
F_120 ( V_17 ) ;
return 0 ;
}
V_216 = ! V_215 -> V_219 ;
return F_121 ( V_195 , V_17 , V_8 , 0 , V_19 , V_203 , V_213 ,
V_216 ) ;
}
static void F_122 ( struct V_16 * V_17 , struct V_1 * V_8 ,
const struct V_18 * V_199 )
{
struct V_220 * V_221 = F_110 ( V_199 ) ;
T_5 V_222 = 0 ;
V_222 = F_123 ( V_17 ) ;
V_222 = F_124 ( V_222 , V_221 -> V_223 ) ;
if ( ! V_222 )
V_222 = 0x1 ;
V_8 -> V_224 = V_222 ;
}
static int F_125 ( struct V_16 * V_17 ,
struct V_1 * V_51 ,
const struct V_18 * V_202 )
{
if ( F_113 ( V_202 ) == V_225 ) {
struct V_226 * V_227 = F_110 ( V_202 ) ;
F_126 ( V_17 ) ;
F_127 ( (struct V_172 * ) V_227 -> V_228 ) ;
F_128 ( V_17 , (struct V_172 * ) V_227 -> V_228 ) ;
return 0 ;
}
return - V_229 ;
}
static int F_129 ( struct V_16 * V_17 ,
struct V_1 * V_51 ,
const struct V_18 * V_202 )
{
int V_49 = 0 ;
switch ( F_113 ( V_202 ) ) {
case V_230 :
F_40 ( V_17 -> V_231 , F_114 ( V_202 ) ,
* F_130 ( V_202 , T_5 * ) ) ;
V_51 -> V_232 . V_231 = V_17 -> V_231 ;
break;
case V_233 :
F_40 ( V_17 -> V_234 , F_114 ( V_202 ) , * F_130 ( V_202 , T_5 * ) ) ;
V_51 -> V_232 . V_235 = V_17 -> V_234 ;
break;
case V_225 :
V_49 = - V_229 ;
break;
case V_236 :
V_49 = F_41 ( V_17 , V_51 , F_110 ( V_202 ) ,
F_130 ( V_202 , struct V_69 * ) ) ;
break;
case V_237 :
V_49 = F_65 ( V_17 , V_51 , F_110 ( V_202 ) ,
F_130 ( V_202 , struct V_109 * ) ) ;
break;
case V_238 :
V_49 = F_70 ( V_17 , V_51 , F_110 ( V_202 ) ,
F_130 ( V_202 , struct V_119 * ) ) ;
break;
case V_239 :
V_49 = F_81 ( V_17 , V_51 , F_110 ( V_202 ) ,
F_130 ( V_202 , struct V_144 * ) ) ;
break;
case V_240 :
V_49 = F_80 ( V_17 , V_51 , F_110 ( V_202 ) ,
F_130 ( V_202 , struct V_138 * ) ) ;
break;
case V_241 :
V_49 = F_82 ( V_17 , V_51 , F_110 ( V_202 ) ,
F_130 ( V_202 , struct V_148 * ) ) ;
break;
case V_242 :
V_49 = F_31 ( V_17 , V_51 , F_110 ( V_202 ) , F_130 ( V_202 ,
T_2 * ) ) ;
break;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_49 = - V_229 ;
break;
}
return V_49 ;
}
static int F_131 ( struct V_194 * V_195 , struct V_16 * V_17 ,
struct V_1 * V_8 ,
const struct V_18 * V_202 , bool V_213 )
{
T_5 V_249 ;
if ( ! F_10 ( V_8 ) ) {
int V_49 ;
V_49 = F_132 ( V_17 , V_8 ) ;
if ( V_49 )
return V_49 ;
}
F_133 ( ! F_10 ( V_8 ) ) ;
V_249 = F_114 ( V_202 ) ;
return F_121 ( V_195 , V_17 , V_8 , V_249 , NULL , 0 , V_213 , true ) ;
}
static int F_134 ( struct V_194 * V_195 , struct V_16 * V_17 ,
struct V_1 * V_8 ,
const struct V_18 * V_199 , int V_84 )
{
const struct V_18 * V_202 ;
int V_203 ;
for ( V_202 = V_199 , V_203 = V_84 ; V_203 > 0 ;
V_202 = F_112 ( V_202 , & V_203 ) ) {
int V_49 = 0 ;
switch ( F_113 ( V_202 ) ) {
case V_250 : {
int V_136 = F_114 ( V_202 ) ;
struct V_16 * V_251 ;
if ( F_135 ( V_202 , V_203 ) ) {
F_104 ( V_195 , V_17 , V_136 , V_8 ) ;
return 0 ;
}
V_251 = F_136 ( V_17 , V_252 ) ;
if ( V_251 )
F_104 ( V_195 , V_251 , V_136 , V_8 ) ;
F_88 ( V_17 ) -> V_197 = 0 ;
break;
}
case V_253 : {
struct V_254 * V_255 = F_110 ( V_202 ) ;
if ( V_17 -> V_84 > V_255 -> V_256 )
F_88 ( V_17 ) -> V_197 = V_17 -> V_84 - V_255 -> V_256 ;
break;
}
case V_257 :
F_109 ( V_195 , V_17 , V_8 , V_202 , V_199 ,
V_84 , F_88 ( V_17 ) -> V_197 ) ;
F_88 ( V_17 ) -> V_197 = 0 ;
break;
case V_258 :
F_122 ( V_17 , V_8 , V_202 ) ;
break;
case V_259 :
V_49 = F_13 ( V_17 , V_8 , F_110 ( V_202 ) ) ;
break;
case V_260 :
V_49 = F_25 ( V_17 , V_8 , F_137 ( V_202 ) ) ;
break;
case V_261 :
V_49 = F_36 ( V_17 , V_8 , F_110 ( V_202 ) ) ;
break;
case V_262 :
V_49 = F_33 ( V_17 , V_8 ) ;
break;
case V_263 : {
bool V_213 = F_135 ( V_202 , V_203 ) ;
V_49 = F_131 ( V_195 , V_17 , V_8 , V_202 , V_213 ) ;
if ( V_213 ) {
return V_49 ;
}
break;
}
case V_264 :
V_49 = F_125 ( V_17 , V_8 , F_110 ( V_202 ) ) ;
break;
case V_265 :
case V_266 :
V_49 = F_129 ( V_17 , V_8 , F_110 ( V_202 ) ) ;
break;
case V_267 : {
bool V_213 = F_135 ( V_202 , V_203 ) ;
V_49 = F_118 ( V_195 , V_17 , V_8 , V_202 , V_213 ) ;
if ( V_213 )
return V_49 ;
break;
}
case V_268 :
if ( ! F_10 ( V_8 ) ) {
V_49 = F_132 ( V_17 , V_8 ) ;
if ( V_49 )
return V_49 ;
}
V_49 = F_138 ( F_139 ( V_195 ) , V_17 , V_8 ,
F_110 ( V_202 ) ) ;
if ( V_49 )
return V_49 == - V_269 ? 0 : V_49 ;
break;
case V_270 :
V_49 = F_46 ( V_17 , V_8 , F_110 ( V_202 ) ) ;
break;
case V_271 :
V_49 = F_43 ( V_17 , V_8 ) ;
break;
}
if ( F_27 ( V_49 ) ) {
F_86 ( V_17 ) ;
return V_49 ;
}
}
F_120 ( V_17 ) ;
return 0 ;
}
static int F_121 ( struct V_194 * V_195 , struct V_16 * V_17 ,
struct V_1 * V_8 , T_5 V_249 ,
const struct V_18 * V_19 , int V_84 ,
bool V_213 , bool V_216 )
{
struct V_14 * V_21 ;
struct V_1 * V_251 ;
V_17 = V_213 ? V_17 : F_136 ( V_17 , V_252 ) ;
if ( ! V_17 ) {
return 0 ;
}
V_251 = V_216 ? F_1 ( V_8 ) : V_8 ;
if ( V_251 ) {
int V_49 = 0 ;
if ( V_19 ) {
if ( V_216 )
F_140 ( V_7 ) ;
V_49 = F_134 ( V_195 , V_17 , V_251 ,
V_19 , V_84 ) ;
if ( V_216 )
F_141 ( V_7 ) ;
} else {
V_251 -> V_249 = V_249 ;
F_142 ( V_17 , V_251 ) ;
}
return V_49 ;
}
V_21 = F_8 ( V_17 , V_8 , V_19 , V_84 ) ;
if ( V_21 ) {
if ( ! V_19 ) {
V_8 = & V_21 -> V_23 ;
V_8 -> V_249 = V_249 ;
}
} else {
F_86 ( V_17 ) ;
if ( F_143 () ) {
if ( V_19 ) {
F_144 ( L_3 ,
F_145 ( V_195 ) ) ;
} else {
F_144 ( L_4 ,
F_145 ( V_195 ) ) ;
}
}
}
return 0 ;
}
static void F_146 ( struct V_194 * V_195 )
{
struct V_10 * V_11 = F_2 ( V_22 ) ;
if ( F_5 ( V_11 ) )
return;
do {
struct V_14 * V_21 = F_6 ( V_11 ) ;
struct V_16 * V_17 = V_21 -> V_17 ;
struct V_1 * V_8 = & V_21 -> V_23 ;
const struct V_18 * V_19 = V_21 -> V_19 ;
int V_20 = V_21 -> V_20 ;
if ( V_19 )
F_134 ( V_195 , V_17 , V_8 , V_19 , V_20 ) ;
else
F_142 ( V_17 , V_8 ) ;
} while ( ! F_5 ( V_11 ) );
F_4 ( V_11 ) ;
}
int F_147 ( struct V_194 * V_195 , struct V_16 * V_17 ,
const struct V_272 * V_273 ,
struct V_1 * V_8 )
{
int V_49 , V_6 ;
V_6 = F_148 ( V_7 ) ;
if ( F_27 ( V_6 > V_274 ) ) {
F_149 ( L_5 ,
F_145 ( V_195 ) ) ;
F_86 ( V_17 ) ;
V_49 = - V_275 ;
goto V_276;
}
F_88 ( V_17 ) -> V_277 = V_273 -> V_278 ;
V_49 = F_134 ( V_195 , V_17 , V_8 ,
V_273 -> V_19 , V_273 -> V_20 ) ;
if ( V_6 == 1 )
F_146 ( V_195 ) ;
V_276:
F_141 ( V_7 ) ;
return V_49 ;
}
int F_150 ( void )
{
V_22 = F_151 ( struct V_10 ) ;
if ( ! V_22 )
return - V_41 ;
V_5 = F_151 ( struct V_3 ) ;
if ( ! V_5 ) {
F_152 ( V_22 ) ;
return - V_41 ;
}
return 0 ;
}
void F_153 ( void )
{
F_152 ( V_22 ) ;
F_152 ( V_5 ) ;
}
