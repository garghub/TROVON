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
static void F_10 ( struct V_7 * V_8 , struct V_18 * V_19 ,
T_1 V_20 )
{
if ( V_8 -> V_21 == V_22 ) {
T_1 V_23 [] = { ~ ( V_19 -> V_24 ) , V_20 } ;
V_8 -> V_25 = ~ F_11 ( ( char * ) V_23 , sizeof( V_23 ) ,
~ V_8 -> V_25 ) ;
}
V_19 -> V_24 = V_20 ;
}
static int F_12 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 ;
if ( V_8 -> V_30 )
return - V_31 ;
if ( F_13 ( V_8 , V_32 ) < 0 )
return - V_33 ;
if ( ! V_8 -> V_34 ) {
F_14 ( V_8 , V_8 -> V_35 ) ;
F_15 ( V_8 , V_8 -> V_36 ) ;
}
F_16 ( V_8 , V_32 ) ;
memmove ( F_17 ( V_8 ) - V_32 , F_17 ( V_8 ) ,
V_8 -> V_35 ) ;
F_18 ( V_8 ) ;
F_19 ( V_8 , V_8 -> V_35 ) ;
V_29 = F_20 ( V_8 ) ;
V_29 -> V_37 = V_27 -> V_38 ;
F_21 ( V_8 , V_29 , V_32 ) ;
F_10 ( V_8 , F_22 ( V_8 ) , V_27 -> V_39 ) ;
V_8 -> V_36 = V_27 -> V_39 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const T_1 V_20 )
{
struct V_18 * V_19 ;
int V_40 ;
V_40 = F_24 ( V_8 , V_8 -> V_35 + V_32 ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
F_26 ( V_8 , F_20 ( V_8 ) , V_32 ) ;
memmove ( F_17 ( V_8 ) + V_32 , F_17 ( V_8 ) ,
V_8 -> V_35 ) ;
F_27 ( V_8 , V_32 ) ;
F_18 ( V_8 ) ;
F_19 ( V_8 , V_8 -> V_35 ) ;
V_19 = (struct V_18 * ) ( ( void * ) F_20 ( V_8 ) - V_41 ) ;
F_10 ( V_8 , V_19 , V_20 ) ;
if ( F_28 ( V_8 -> V_36 ) )
V_8 -> V_36 = V_20 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const T_2 * V_38 , const T_2 * V_43 )
{
struct V_28 * V_44 ;
T_2 V_45 ;
int V_40 ;
V_40 = F_24 ( V_8 , V_8 -> V_35 + V_32 ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
V_44 = F_20 ( V_8 ) ;
V_45 = F_30 ( V_44 -> V_37 , * V_38 , * V_43 ) ;
if ( V_8 -> V_21 == V_22 ) {
T_2 V_23 [] = { ~ ( V_44 -> V_37 ) , V_45 } ;
V_8 -> V_25 = ~ F_11 ( ( char * ) V_23 , sizeof( V_23 ) ,
~ V_8 -> V_25 ) ;
}
V_44 -> V_37 = V_45 ;
V_42 -> V_27 . V_46 = V_45 ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_40 ;
V_40 = F_32 ( V_8 ) ;
if ( F_33 ( V_8 ) ) {
F_7 ( V_10 ) ;
} else {
V_10 -> V_17 . V_47 . V_48 = 0 ;
V_10 -> V_17 . V_47 . V_49 = 0 ;
}
return V_40 ;
}
static int F_34 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_50 * V_47 )
{
if ( F_33 ( V_8 ) ) {
F_7 ( V_10 ) ;
} else {
V_10 -> V_17 . V_47 . V_48 = V_47 -> V_51 ;
V_10 -> V_17 . V_47 . V_49 = V_47 -> V_52 ;
}
return F_35 ( V_8 , V_47 -> V_52 ,
F_36 ( V_47 -> V_51 ) & ~ V_53 ) ;
}
static void F_37 ( T_3 * V_54 , const T_3 * V_55 , const T_3 * V_56 )
{
T_4 * V_57 = ( T_4 * ) V_54 ;
const T_4 * V_58 = ( const T_4 * ) V_55 ;
const T_4 * V_43 = ( const T_4 * ) V_56 ;
F_38 ( V_57 [ 0 ] , V_58 [ 0 ] , V_43 [ 0 ] ) ;
F_38 ( V_57 [ 1 ] , V_58 [ 1 ] , V_43 [ 1 ] ) ;
F_38 ( V_57 [ 2 ] , V_58 [ 2 ] , V_43 [ 2 ] ) ;
}
static int F_39 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const struct V_59 * V_10 ,
const struct V_59 * V_43 )
{
int V_40 ;
V_40 = F_24 ( V_8 , V_41 ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
F_26 ( V_8 , F_22 ( V_8 ) , V_60 * 2 ) ;
F_37 ( F_22 ( V_8 ) -> V_61 , V_10 -> V_62 ,
V_43 -> V_62 ) ;
F_37 ( F_22 ( V_8 ) -> V_63 , V_10 -> V_64 ,
V_43 -> V_64 ) ;
F_21 ( V_8 , F_22 ( V_8 ) , V_60 * 2 ) ;
F_40 ( V_42 -> V_17 . V_58 , F_22 ( V_8 ) -> V_61 ) ;
F_40 ( V_42 -> V_17 . V_57 , F_22 ( V_8 ) -> V_63 ) ;
return 0 ;
}
static void F_41 ( struct V_7 * V_8 , struct V_65 * V_66 ,
T_2 V_67 , T_2 V_68 )
{
int V_69 = V_8 -> V_70 - F_42 ( V_8 ) ;
if ( V_66 -> V_71 & F_8 ( V_72 ) )
return;
if ( V_66 -> V_36 == V_73 ) {
if ( F_43 ( V_69 >= sizeof( struct V_74 ) ) )
F_44 ( & F_45 ( V_8 ) -> V_75 , V_8 ,
V_67 , V_68 , true ) ;
} else if ( V_66 -> V_36 == V_76 ) {
if ( F_43 ( V_69 >= sizeof( struct V_77 ) ) ) {
struct V_77 * V_78 = F_46 ( V_8 ) ;
if ( V_78 -> V_75 || V_8 -> V_21 == V_79 ) {
F_44 ( & V_78 -> V_75 , V_8 ,
V_67 , V_68 , true ) ;
if ( ! V_78 -> V_75 )
V_78 -> V_75 = V_80 ;
}
}
}
}
static void F_47 ( struct V_7 * V_8 , struct V_65 * V_66 ,
T_2 * V_67 , T_2 V_68 )
{
F_41 ( V_8 , V_66 , * V_67 , V_68 ) ;
F_48 ( & V_66 -> V_75 , * V_67 , V_68 ) ;
F_49 ( V_8 ) ;
* V_67 = V_68 ;
}
static void F_50 ( struct V_7 * V_8 , T_3 V_81 ,
T_2 V_67 [ 4 ] , const T_2 V_68 [ 4 ] )
{
int V_69 = V_8 -> V_70 - F_42 ( V_8 ) ;
if ( V_81 == V_82 ) {
if ( F_43 ( V_69 >= sizeof( struct V_74 ) ) )
F_51 ( & F_45 ( V_8 ) -> V_75 , V_8 ,
V_67 , V_68 , true ) ;
} else if ( V_81 == V_83 ) {
if ( F_43 ( V_69 >= sizeof( struct V_77 ) ) ) {
struct V_77 * V_78 = F_46 ( V_8 ) ;
if ( V_78 -> V_75 || V_8 -> V_21 == V_79 ) {
F_51 ( & V_78 -> V_75 , V_8 ,
V_67 , V_68 , true ) ;
if ( ! V_78 -> V_75 )
V_78 -> V_75 = V_80 ;
}
}
} else if ( V_81 == V_84 ) {
if ( F_43 ( V_69 >= sizeof( struct V_85 ) ) )
F_51 ( & F_52 ( V_8 ) -> V_86 ,
V_8 , V_67 , V_68 , true ) ;
}
}
static void F_53 ( const T_2 V_87 [ 4 ] , const T_2 V_67 [ 4 ] ,
const T_2 V_43 [ 4 ] , T_2 V_88 [ 4 ] )
{
V_88 [ 0 ] = F_30 ( V_87 [ 0 ] , V_67 [ 0 ] , V_43 [ 0 ] ) ;
V_88 [ 1 ] = F_30 ( V_87 [ 1 ] , V_67 [ 1 ] , V_43 [ 1 ] ) ;
V_88 [ 2 ] = F_30 ( V_87 [ 2 ] , V_67 [ 2 ] , V_43 [ 2 ] ) ;
V_88 [ 3 ] = F_30 ( V_87 [ 3 ] , V_67 [ 3 ] , V_43 [ 3 ] ) ;
}
static void F_54 ( struct V_7 * V_8 , T_3 V_81 ,
T_2 V_67 [ 4 ] , const T_2 V_68 [ 4 ] ,
bool V_89 )
{
if ( V_89 )
F_50 ( V_8 , V_81 , V_67 , V_68 ) ;
F_49 ( V_8 ) ;
memcpy ( V_67 , V_68 , sizeof( T_2 [ 4 ] ) ) ;
}
static void F_55 ( struct V_90 * V_66 , T_5 V_91 , T_5 V_43 )
{
F_38 ( V_66 -> V_92 [ 0 ] , ( T_3 ) ( V_91 >> 16 ) , ( T_3 ) ( V_43 >> 16 ) ) ;
F_38 ( V_66 -> V_92 [ 1 ] , ( T_3 ) ( V_91 >> 8 ) , ( T_3 ) ( V_43 >> 8 ) ) ;
F_38 ( V_66 -> V_92 [ 2 ] , ( T_3 ) V_91 , ( T_3 ) V_43 ) ;
}
static void F_56 ( struct V_7 * V_8 , struct V_65 * V_66 , T_3 V_93 ,
T_3 V_43 )
{
V_93 = F_30 ( V_66 -> V_94 , V_93 , V_43 ) ;
F_57 ( & V_66 -> V_75 , F_8 ( V_66 -> V_94 << 8 ) , F_8 ( V_93 << 8 ) ) ;
V_66 -> V_94 = V_93 ;
}
static int F_58 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const struct V_95 * V_10 ,
const struct V_95 * V_43 )
{
struct V_65 * V_66 ;
T_2 V_68 ;
int V_40 ;
V_40 = F_24 ( V_8 , F_59 ( V_8 ) +
sizeof( struct V_65 ) ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
V_66 = F_60 ( V_8 ) ;
if ( V_43 -> V_96 ) {
V_68 = F_30 ( V_66 -> V_97 , V_10 -> V_96 , V_43 -> V_96 ) ;
if ( F_25 ( V_68 != V_66 -> V_97 ) ) {
F_47 ( V_8 , V_66 , & V_66 -> V_97 , V_68 ) ;
V_42 -> V_98 . V_67 . V_58 = V_68 ;
}
}
if ( V_43 -> V_99 ) {
V_68 = F_30 ( V_66 -> V_100 , V_10 -> V_99 , V_43 -> V_99 ) ;
if ( F_25 ( V_68 != V_66 -> V_100 ) ) {
F_47 ( V_8 , V_66 , & V_66 -> V_100 , V_68 ) ;
V_42 -> V_98 . V_67 . V_57 = V_68 ;
}
}
if ( V_43 -> V_101 ) {
F_61 ( V_66 , ~ V_43 -> V_101 , V_10 -> V_101 ) ;
V_42 -> V_102 . V_103 = V_66 -> V_103 ;
}
if ( V_43 -> V_104 ) {
F_56 ( V_8 , V_66 , V_10 -> V_104 , V_43 -> V_104 ) ;
V_42 -> V_102 . V_94 = V_66 -> V_94 ;
}
return 0 ;
}
static bool F_62 ( const T_2 V_67 [ 4 ] )
{
return ! ! ( V_67 [ 0 ] | V_67 [ 1 ] | V_67 [ 2 ] | V_67 [ 3 ] ) ;
}
static int F_63 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const struct V_105 * V_10 ,
const struct V_105 * V_43 )
{
struct V_90 * V_66 ;
int V_40 ;
V_40 = F_24 ( V_8 , F_59 ( V_8 ) +
sizeof( struct V_90 ) ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
V_66 = F_64 ( V_8 ) ;
if ( F_62 ( V_43 -> V_106 ) ) {
T_2 * V_97 = ( T_2 * ) & V_66 -> V_97 ;
T_2 V_88 [ 4 ] ;
F_53 ( V_97 , V_10 -> V_106 , V_43 -> V_106 , V_88 ) ;
if ( F_25 ( memcmp ( V_97 , V_88 , sizeof( V_88 ) ) ) ) {
F_54 ( V_8 , V_42 -> V_102 . V_107 , V_97 , V_88 ,
true ) ;
memcpy ( & V_42 -> V_108 . V_67 . V_58 , V_88 ,
sizeof( V_42 -> V_108 . V_67 . V_58 ) ) ;
}
}
if ( F_62 ( V_43 -> V_109 ) ) {
unsigned int V_110 = 0 ;
int V_111 = V_112 ;
bool V_113 = true ;
T_2 * V_100 = ( T_2 * ) & V_66 -> V_100 ;
T_2 V_88 [ 4 ] ;
F_53 ( V_100 , V_10 -> V_109 , V_43 -> V_109 , V_88 ) ;
if ( F_25 ( memcmp ( V_100 , V_88 , sizeof( V_88 ) ) ) ) {
if ( F_65 ( V_66 -> V_114 ) )
V_113 = ( F_66 ( V_8 , & V_110 ,
V_115 ,
NULL , & V_111 )
!= V_115 ) ;
F_54 ( V_8 , V_42 -> V_102 . V_107 , V_100 , V_88 ,
V_113 ) ;
memcpy ( & V_42 -> V_108 . V_67 . V_57 , V_88 ,
sizeof( V_42 -> V_108 . V_67 . V_57 ) ) ;
}
}
if ( V_43 -> V_116 ) {
F_67 ( V_66 , ~ V_43 -> V_116 , V_10 -> V_116 ) ;
V_42 -> V_102 . V_103 = F_68 ( V_66 ) ;
}
if ( V_43 -> V_117 ) {
F_55 ( V_66 , F_69 ( V_10 -> V_117 ) ,
F_69 ( V_43 -> V_117 ) ) ;
V_42 -> V_108 . V_118 =
* ( T_2 * ) V_66 & F_70 ( V_119 ) ;
}
if ( V_43 -> V_120 ) {
F_38 ( V_66 -> V_121 , V_10 -> V_120 ,
V_43 -> V_120 ) ;
V_42 -> V_102 . V_94 = V_66 -> V_121 ;
}
return 0 ;
}
static void F_71 ( struct V_7 * V_8 , T_1 * V_122 ,
T_1 V_123 , T_6 * V_75 )
{
F_72 ( V_75 , V_8 , * V_122 , V_123 , false ) ;
* V_122 = V_123 ;
}
static int F_73 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const struct V_124 * V_10 ,
const struct V_124 * V_43 )
{
struct V_77 * V_78 ;
T_1 V_58 , V_57 ;
int V_40 ;
V_40 = F_24 ( V_8 , F_42 ( V_8 ) +
sizeof( struct V_77 ) ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
V_78 = F_46 ( V_8 ) ;
V_58 = F_30 ( V_78 -> V_125 , V_10 -> V_126 , V_43 -> V_126 ) ;
V_57 = F_30 ( V_78 -> V_127 , V_10 -> V_128 , V_43 -> V_128 ) ;
if ( V_78 -> V_75 && V_8 -> V_21 != V_79 ) {
if ( F_43 ( V_58 != V_78 -> V_125 ) ) {
F_71 ( V_8 , & V_78 -> V_125 , V_58 , & V_78 -> V_75 ) ;
V_42 -> V_129 . V_58 = V_58 ;
}
if ( F_43 ( V_57 != V_78 -> V_127 ) ) {
F_71 ( V_8 , & V_78 -> V_127 , V_57 , & V_78 -> V_75 ) ;
V_42 -> V_129 . V_57 = V_57 ;
}
if ( F_25 ( ! V_78 -> V_75 ) )
V_78 -> V_75 = V_80 ;
} else {
V_78 -> V_125 = V_58 ;
V_78 -> V_127 = V_57 ;
V_42 -> V_129 . V_58 = V_58 ;
V_42 -> V_129 . V_57 = V_57 ;
}
F_49 ( V_8 ) ;
return 0 ;
}
static int F_74 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const struct V_130 * V_10 ,
const struct V_130 * V_43 )
{
struct V_74 * V_131 ;
T_1 V_58 , V_57 ;
int V_40 ;
V_40 = F_24 ( V_8 , F_42 ( V_8 ) +
sizeof( struct V_74 ) ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
V_131 = F_45 ( V_8 ) ;
V_58 = F_30 ( V_131 -> V_125 , V_10 -> V_132 , V_43 -> V_132 ) ;
if ( F_43 ( V_58 != V_131 -> V_125 ) ) {
F_71 ( V_8 , & V_131 -> V_125 , V_58 , & V_131 -> V_75 ) ;
V_42 -> V_129 . V_58 = V_58 ;
}
V_57 = F_30 ( V_131 -> V_127 , V_10 -> V_133 , V_43 -> V_133 ) ;
if ( F_43 ( V_57 != V_131 -> V_127 ) ) {
F_71 ( V_8 , & V_131 -> V_127 , V_57 , & V_131 -> V_75 ) ;
V_42 -> V_129 . V_57 = V_57 ;
}
F_49 ( V_8 ) ;
return 0 ;
}
static int F_75 ( struct V_7 * V_8 , struct V_9 * V_42 ,
const struct V_134 * V_10 ,
const struct V_134 * V_43 )
{
unsigned int V_135 = F_42 ( V_8 ) ;
struct V_136 * V_137 ;
T_7 V_138 , V_139 , V_140 ;
int V_40 ;
V_40 = F_24 ( V_8 , V_135 + sizeof( struct V_136 ) ) ;
if ( F_25 ( V_40 ) )
return V_40 ;
V_137 = F_76 ( V_8 ) ;
V_140 = V_137 -> V_141 ;
V_138 = F_77 ( V_8 , V_135 ) ;
V_137 -> V_125 = F_30 ( V_137 -> V_125 , V_10 -> V_142 , V_43 -> V_142 ) ;
V_137 -> V_127 = F_30 ( V_137 -> V_127 , V_10 -> V_143 , V_43 -> V_143 ) ;
V_139 = F_77 ( V_8 , V_135 ) ;
V_137 -> V_141 = V_140 ^ V_138 ^ V_139 ;
F_49 ( V_8 ) ;
V_42 -> V_129 . V_58 = V_137 -> V_125 ;
V_42 -> V_129 . V_57 = V_137 -> V_127 ;
return 0 ;
}
static int F_78 ( struct V_144 * V_144 , struct V_145 * V_146 , struct V_7 * V_8 )
{
struct V_147 * V_148 = F_6 ( & V_149 ) ;
struct V_150 * V_150 = V_148 -> V_150 ;
if ( F_13 ( V_8 , V_148 -> V_151 ) < 0 ) {
F_79 ( V_8 ) ;
return - V_33 ;
}
F_80 ( V_8 , V_148 -> V_57 ) ;
* F_81 ( V_8 ) = V_148 -> V_152 ;
V_8 -> V_34 = V_148 -> V_34 ;
V_8 -> V_51 = V_148 -> V_51 ;
V_8 -> V_153 = V_148 -> V_153 ;
F_16 ( V_8 , V_148 -> V_151 ) ;
memcpy ( V_8 -> V_148 , & V_148 -> V_154 , V_148 -> V_151 ) ;
F_21 ( V_8 , V_8 -> V_148 , V_148 -> V_151 ) ;
F_18 ( V_8 ) ;
F_82 ( V_150 , V_8 ) ;
return 0 ;
}
static unsigned int
F_83 ( const struct V_155 * V_57 )
{
return V_57 -> V_156 -> V_157 ;
}
static void F_84 ( struct V_150 * V_150 , struct V_7 * V_8 )
{
unsigned int V_158 = F_59 ( V_8 ) ;
struct V_147 * V_148 ;
V_148 = F_6 ( & V_149 ) ;
V_148 -> V_57 = V_8 -> V_159 ;
V_148 -> V_150 = V_150 ;
V_148 -> V_152 = * F_81 ( V_8 ) ;
V_148 -> V_34 = V_8 -> V_34 ;
V_148 -> V_51 = V_8 -> V_51 ;
V_148 -> V_153 = V_8 -> V_153 ;
V_148 -> V_151 = V_158 ;
memcpy ( & V_148 -> V_154 , V_8 -> V_148 , V_158 ) ;
memset ( F_85 ( V_8 ) , 0 , sizeof( struct V_160 ) ) ;
F_86 ( V_8 , V_158 ) ;
}
static void F_87 ( struct V_144 * V_144 , struct V_150 * V_150 ,
struct V_7 * V_8 , T_4 V_161 , T_1 V_20 )
{
if ( F_59 ( V_8 ) > V_162 ) {
F_88 ( 1 , L_1 ) ;
goto V_40;
}
if ( V_20 == F_8 ( V_163 ) ) {
struct V_155 V_164 ;
unsigned long V_165 ;
F_84 ( V_150 , V_8 ) ;
F_89 ( & V_164 , & V_166 , NULL , 1 ,
V_167 , V_168 ) ;
V_164 . V_156 = V_150 -> V_156 ;
V_165 = V_8 -> V_159 ;
F_90 ( V_8 , & V_164 ) ;
F_85 ( V_8 ) -> V_169 = V_161 ;
F_91 ( V_144 , V_8 -> V_146 , V_8 , F_78 ) ;
F_92 ( V_165 ) ;
} else if ( V_20 == F_8 ( V_170 ) ) {
const struct V_171 * V_172 = F_93 () ;
unsigned long V_165 ;
struct V_173 V_174 ;
if ( ! V_172 ) {
goto V_40;
}
F_84 ( V_150 , V_8 ) ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
F_89 ( & V_174 . V_57 , & V_166 , NULL , 1 ,
V_167 , V_168 ) ;
V_174 . V_57 . V_156 = V_150 -> V_156 ;
V_165 = V_8 -> V_159 ;
F_90 ( V_8 , & V_174 . V_57 ) ;
F_94 ( V_8 ) -> V_169 = V_161 ;
V_172 -> V_175 ( V_144 , V_8 -> V_146 , V_8 , F_78 ) ;
F_92 ( V_165 ) ;
} else {
F_95 ( 1 , L_2 ,
F_96 ( V_150 ) , F_36 ( V_20 ) , V_161 ,
V_150 -> V_156 -> V_157 ) ;
goto V_40;
}
return;
V_40:
F_79 ( V_8 ) ;
}
static void F_97 ( struct V_176 * V_177 , struct V_7 * V_8 , int V_178 ,
struct V_9 * V_10 )
{
struct V_150 * V_150 = F_98 ( V_177 , V_178 ) ;
if ( F_43 ( V_150 ) ) {
T_4 V_161 = F_81 ( V_8 ) -> V_161 ;
T_5 V_179 = F_81 ( V_8 ) -> V_179 ;
if ( F_25 ( V_179 > 0 ) ) {
if ( V_8 -> V_70 - V_179 > V_41 )
F_99 ( V_8 , V_8 -> V_70 - V_179 ) ;
else
F_99 ( V_8 , V_41 ) ;
}
if ( F_43 ( ! V_161 || ( V_8 -> V_70 <= V_161 + V_41 ) ) ) {
F_82 ( V_150 , V_8 ) ;
} else if ( V_161 <= V_150 -> V_156 -> V_157 ) {
struct V_144 * V_144 = F_100 ( & V_177 -> V_144 ) ;
T_1 V_20 = V_10 -> V_17 . type ;
if ( ! F_9 ( V_10 ) ) {
if ( F_28 ( V_8 -> V_36 ) )
V_20 = V_8 -> V_34 ;
else
V_20 = F_101 ( V_8 ) ;
}
F_87 ( V_144 , V_150 , V_8 , V_161 , V_20 ) ;
} else {
F_79 ( V_8 ) ;
}
} else {
F_79 ( V_8 ) ;
}
}
static int F_102 ( struct V_176 * V_177 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_11 * V_15 , int V_180 ,
T_8 V_179 )
{
struct V_181 V_182 ;
const struct V_11 * V_183 ;
int V_184 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_182 . V_185 = V_186 ;
V_182 . V_161 = F_81 ( V_8 ) -> V_161 ;
for ( V_183 = F_103 ( V_12 ) , V_184 = F_104 ( V_12 ) ; V_184 > 0 ;
V_183 = F_105 ( V_183 , & V_184 ) ) {
switch ( F_106 ( V_183 ) ) {
case V_187 :
V_182 . V_188 = V_183 ;
break;
case V_189 :
V_182 . V_190 = F_107 ( V_183 ) ;
break;
case V_191 : {
struct V_150 * V_150 ;
V_150 = F_98 ( V_177 , F_107 ( V_183 ) ) ;
if ( V_150 ) {
int V_40 ;
V_40 = F_108 ( V_150 -> V_156 , V_8 ) ;
if ( ! V_40 )
V_182 . V_192 = F_109 ( V_8 ) ;
}
break;
}
case V_193 : {
V_182 . V_15 = V_15 ;
V_182 . V_180 = V_180 ;
break;
}
}
}
return F_110 ( V_177 , V_8 , V_10 , & V_182 , V_179 ) ;
}
static int F_111 ( struct V_176 * V_177 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_11 * V_15 , int V_180 )
{
const struct V_11 * V_194 = NULL ;
const struct V_11 * V_183 ;
int V_184 ;
T_5 V_179 = 0 ;
for ( V_183 = F_103 ( V_12 ) , V_184 = F_104 ( V_12 ) ; V_184 > 0 ;
V_183 = F_105 ( V_183 , & V_184 ) ) {
T_5 V_195 ;
switch ( F_106 ( V_183 ) ) {
case V_196 :
V_195 = F_107 ( V_183 ) ;
if ( ! V_195 || F_112 () > V_195 )
return 0 ;
break;
case V_197 :
V_194 = V_183 ;
break;
}
}
V_184 = F_104 ( V_194 ) ;
V_183 = F_103 ( V_194 ) ;
if ( F_25 ( ! V_184 ) )
return 0 ;
if ( F_25 ( F_106 ( V_183 ) == V_198 ) ) {
struct V_199 * V_200 = F_103 ( V_183 ) ;
if ( V_8 -> V_70 > V_200 -> V_201 )
V_179 = V_8 -> V_70 - V_200 -> V_201 ;
V_183 = F_105 ( V_183 , & V_184 ) ;
}
if ( F_43 ( F_106 ( V_183 ) == V_202 &&
F_113 ( V_183 , V_184 ) ) )
return F_102 ( V_177 , V_8 , V_10 , V_183 , V_15 ,
V_180 , V_179 ) ;
V_8 = F_114 ( V_8 , V_203 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_5 ( V_8 , V_10 , V_183 ) ) {
if ( F_115 () )
F_116 ( L_3 ,
F_117 ( V_177 ) ) ;
F_79 ( V_8 ) ;
}
return 0 ;
}
static void F_118 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_204 * V_205 = F_103 ( V_12 ) ;
T_5 V_206 = 0 ;
V_206 = F_119 ( V_8 ) ;
V_206 = F_120 ( V_206 , V_205 -> V_207 ) ;
if ( ! V_206 )
V_206 = 0x1 ;
V_10 -> V_208 = V_206 ;
}
static int F_121 ( struct V_7 * V_8 ,
struct V_9 * V_42 ,
const struct V_11 * V_183 )
{
if ( F_106 ( V_183 ) == V_209 ) {
struct V_210 * V_211 = F_103 ( V_183 ) ;
F_122 ( V_8 ) ;
F_123 ( (struct V_155 * ) V_211 -> V_212 ) ;
F_124 ( V_8 , (struct V_155 * ) V_211 -> V_212 ) ;
return 0 ;
}
return - V_213 ;
}
static int F_125 ( struct V_7 * V_8 ,
struct V_9 * V_42 ,
const struct V_11 * V_183 )
{
int V_40 = 0 ;
switch ( F_106 ( V_183 ) ) {
case V_214 :
F_38 ( V_8 -> V_215 , F_107 ( V_183 ) ,
* F_126 ( V_183 , T_5 * ) ) ;
V_42 -> V_216 . V_215 = V_8 -> V_215 ;
break;
case V_217 :
F_38 ( V_8 -> V_218 , F_107 ( V_183 ) , * F_126 ( V_183 , T_5 * ) ) ;
V_42 -> V_216 . V_219 = V_8 -> V_218 ;
break;
case V_209 :
V_40 = - V_213 ;
break;
case V_220 :
V_40 = F_39 ( V_8 , V_42 , F_103 ( V_183 ) ,
F_126 ( V_183 , struct V_59 * ) ) ;
break;
case V_221 :
V_40 = F_58 ( V_8 , V_42 , F_103 ( V_183 ) ,
F_126 ( V_183 , struct V_95 * ) ) ;
break;
case V_222 :
V_40 = F_63 ( V_8 , V_42 , F_103 ( V_183 ) ,
F_126 ( V_183 , struct V_105 * ) ) ;
break;
case V_223 :
V_40 = F_74 ( V_8 , V_42 , F_103 ( V_183 ) ,
F_126 ( V_183 , struct V_130 * ) ) ;
break;
case V_224 :
V_40 = F_73 ( V_8 , V_42 , F_103 ( V_183 ) ,
F_126 ( V_183 , struct V_124 * ) ) ;
break;
case V_225 :
V_40 = F_75 ( V_8 , V_42 , F_103 ( V_183 ) ,
F_126 ( V_183 , struct V_134 * ) ) ;
break;
case V_226 :
V_40 = F_29 ( V_8 , V_42 , F_103 ( V_183 ) , F_126 ( V_183 ,
T_2 * ) ) ;
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
V_40 = - V_213 ;
break;
}
return V_40 ;
}
static int F_127 ( struct V_176 * V_177 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_183 , int V_184 )
{
struct V_5 * V_13 ;
int V_231 ;
if ( ! F_9 ( V_10 ) ) {
int V_40 ;
V_40 = F_128 ( V_8 , V_10 ) ;
if ( V_40 )
return V_40 ;
}
F_129 ( ! F_9 ( V_10 ) ) ;
if ( ! F_113 ( V_183 , V_184 ) ) {
V_8 = F_114 ( V_8 , V_203 ) ;
if ( ! V_8 )
return 0 ;
}
V_231 = F_130 ( V_232 ) ;
if ( V_231 <= V_233 ) {
struct V_234 * V_235 = F_6 ( V_234 ) ;
struct V_9 * V_236 = & V_235 -> V_10 [ V_231 - 1 ] ;
* V_236 = * V_10 ;
V_236 -> V_237 = F_107 ( V_183 ) ;
F_131 ( V_8 , V_236 ) ;
return 0 ;
}
V_13 = F_5 ( V_8 , V_10 , NULL ) ;
if ( V_13 ) {
V_13 -> V_16 . V_237 = F_107 ( V_183 ) ;
} else {
F_79 ( V_8 ) ;
if ( F_115 () )
F_116 ( L_4 ,
F_117 ( V_177 ) ) ;
}
return 0 ;
}
static int F_132 ( struct V_176 * V_177 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 , int V_70 )
{
int V_238 = - 1 ;
const struct V_11 * V_183 ;
int V_184 ;
for ( V_183 = V_12 , V_184 = V_70 ; V_184 > 0 ;
V_183 = F_105 ( V_183 , & V_184 ) ) {
int V_40 = 0 ;
if ( F_25 ( V_238 != - 1 ) ) {
struct V_7 * V_239 = F_114 ( V_8 , V_203 ) ;
if ( V_239 )
F_97 ( V_177 , V_239 , V_238 , V_10 ) ;
F_81 ( V_8 ) -> V_179 = 0 ;
V_238 = - 1 ;
}
switch ( F_106 ( V_183 ) ) {
case V_240 :
V_238 = F_107 ( V_183 ) ;
break;
case V_198 : {
struct V_199 * V_200 = F_103 ( V_183 ) ;
if ( V_8 -> V_70 > V_200 -> V_201 )
F_81 ( V_8 ) -> V_179 = V_8 -> V_70 - V_200 -> V_201 ;
break;
}
case V_202 :
F_102 ( V_177 , V_8 , V_10 , V_183 , V_12 ,
V_70 , F_81 ( V_8 ) -> V_179 ) ;
F_81 ( V_8 ) -> V_179 = 0 ;
break;
case V_241 :
F_118 ( V_8 , V_10 , V_183 ) ;
break;
case V_242 :
V_40 = F_12 ( V_8 , V_10 , F_103 ( V_183 ) ) ;
break;
case V_243 :
V_40 = F_23 ( V_8 , V_10 , F_133 ( V_183 ) ) ;
break;
case V_244 :
V_40 = F_34 ( V_8 , V_10 , F_103 ( V_183 ) ) ;
break;
case V_245 :
V_40 = F_31 ( V_8 , V_10 ) ;
break;
case V_246 :
V_40 = F_127 ( V_177 , V_8 , V_10 , V_183 , V_184 ) ;
if ( F_113 ( V_183 , V_184 ) ) {
return V_40 ;
}
break;
case V_247 :
V_40 = F_121 ( V_8 , V_10 , F_103 ( V_183 ) ) ;
break;
case V_248 :
case V_249 :
V_40 = F_125 ( V_8 , V_10 , F_103 ( V_183 ) ) ;
break;
case V_250 :
V_40 = F_111 ( V_177 , V_8 , V_10 , V_183 , V_12 , V_70 ) ;
break;
case V_251 :
if ( ! F_9 ( V_10 ) ) {
V_40 = F_128 ( V_8 , V_10 ) ;
if ( V_40 )
return V_40 ;
}
V_40 = F_134 ( F_135 ( V_177 ) , V_8 , V_10 ,
F_103 ( V_183 ) ) ;
if ( V_40 )
return V_40 == - V_252 ? 0 : V_40 ;
break;
}
if ( F_25 ( V_40 ) ) {
F_79 ( V_8 ) ;
return V_40 ;
}
}
if ( V_238 != - 1 )
F_97 ( V_177 , V_8 , V_238 , V_10 ) ;
else
F_136 ( V_8 ) ;
return 0 ;
}
static void F_137 ( struct V_176 * V_177 )
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
F_132 ( V_177 , V_8 , V_10 , V_15 ,
F_104 ( V_15 ) ) ;
else
F_131 ( V_8 , V_10 ) ;
} while ( ! F_2 ( V_2 ) );
F_1 ( V_2 ) ;
}
int F_138 ( struct V_176 * V_177 , struct V_7 * V_8 ,
const struct V_253 * V_254 ,
struct V_9 * V_10 )
{
int V_40 , V_231 ;
V_231 = F_139 ( V_232 ) ;
if ( F_25 ( V_231 > V_255 ) ) {
F_140 ( L_5 ,
F_117 ( V_177 ) ) ;
F_79 ( V_8 ) ;
V_40 = - V_256 ;
goto V_257;
}
V_40 = F_132 ( V_177 , V_8 , V_10 ,
V_254 -> V_15 , V_254 -> V_180 ) ;
if ( V_231 == 1 )
F_137 ( V_177 ) ;
V_257:
F_141 ( V_232 ) ;
return V_40 ;
}
int F_142 ( void )
{
V_14 = F_143 ( struct V_1 ) ;
if ( ! V_14 )
return - V_33 ;
V_234 = F_143 ( struct V_234 ) ;
if ( ! V_234 ) {
F_144 ( V_14 ) ;
return - V_33 ;
}
return 0 ;
}
void F_145 ( void )
{
F_144 ( V_14 ) ;
F_144 ( V_234 ) ;
}
