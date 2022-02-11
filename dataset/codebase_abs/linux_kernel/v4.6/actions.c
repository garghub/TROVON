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
F_16 ( V_8 , V_20 , V_25 ) ;
V_22 = F_17 ( V_8 ) ;
V_22 -> V_29 = V_19 -> V_30 ;
if ( ! V_8 -> V_31 )
F_18 ( V_8 , V_8 -> V_32 ) ;
V_8 -> V_32 = V_19 -> V_30 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const T_2 V_33 )
{
struct V_21 * V_22 ;
int V_34 ;
V_34 = F_20 ( V_8 , V_8 -> V_27 + V_25 ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
F_22 ( V_8 , F_15 ( V_8 ) , V_25 ) ;
memmove ( F_13 ( V_8 ) + V_25 , F_13 ( V_8 ) ,
V_8 -> V_27 ) ;
F_23 ( V_8 , V_25 ) ;
F_14 ( V_8 ) ;
V_22 = (struct V_21 * ) ( F_15 ( V_8 ) - V_35 ) ;
V_22 -> V_29 = V_33 ;
if ( F_24 ( V_8 -> V_32 ) )
V_8 -> V_32 = V_33 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const T_1 * V_28 , const T_1 * V_37 )
{
T_1 * V_38 ;
T_1 V_39 ;
int V_34 ;
V_34 = F_20 ( V_8 , V_8 -> V_27 + V_25 ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
V_38 = ( T_1 * ) F_15 ( V_8 ) ;
V_39 = F_26 ( * V_38 , * V_28 , * V_37 ) ;
if ( V_8 -> V_40 == V_41 ) {
T_1 V_42 [] = { ~ ( * V_38 ) , V_39 } ;
V_8 -> V_43 = ~ F_27 ( ( char * ) V_42 , sizeof( V_42 ) ,
~ V_8 -> V_43 ) ;
}
* V_38 = V_39 ;
V_36 -> V_19 . V_44 = V_39 ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_34 ;
V_34 = F_29 ( V_8 ) ;
if ( F_30 ( V_8 ) )
F_7 ( V_10 ) ;
else
V_10 -> V_17 . V_45 = 0 ;
return V_34 ;
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
const T_4 * V_37 = ( const T_4 * ) V_53 ;
F_35 ( V_54 [ 0 ] , V_55 [ 0 ] , V_37 [ 0 ] ) ;
F_35 ( V_54 [ 1 ] , V_55 [ 1 ] , V_37 [ 1 ] ) ;
F_35 ( V_54 [ 2 ] , V_55 [ 2 ] , V_37 [ 2 ] ) ;
}
static int F_36 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const struct V_56 * V_10 ,
const struct V_56 * V_37 )
{
int V_34 ;
V_34 = F_20 ( V_8 , V_35 ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
F_22 ( V_8 , F_17 ( V_8 ) , V_57 * 2 ) ;
F_34 ( F_17 ( V_8 ) -> V_58 , V_10 -> V_59 ,
V_37 -> V_59 ) ;
F_34 ( F_17 ( V_8 ) -> V_60 , V_10 -> V_61 ,
V_37 -> V_61 ) ;
F_16 ( V_8 , F_17 ( V_8 ) , V_57 * 2 ) ;
F_37 ( V_36 -> V_17 . V_55 , F_17 ( V_8 ) -> V_58 ) ;
F_37 ( V_36 -> V_17 . V_54 , F_17 ( V_8 ) -> V_60 ) ;
return 0 ;
}
static void F_38 ( struct V_7 * V_8 , struct V_62 * V_63 ,
T_1 V_64 , T_1 V_65 )
{
int V_66 = V_8 -> V_67 - F_39 ( V_8 ) ;
if ( V_63 -> V_68 & F_8 ( V_69 ) )
return;
if ( V_63 -> V_32 == V_70 ) {
if ( F_40 ( V_66 >= sizeof( struct V_71 ) ) )
F_41 ( & F_42 ( V_8 ) -> V_72 , V_8 ,
V_64 , V_65 , true ) ;
} else if ( V_63 -> V_32 == V_73 ) {
if ( F_40 ( V_66 >= sizeof( struct V_74 ) ) ) {
struct V_74 * V_75 = F_43 ( V_8 ) ;
if ( V_75 -> V_72 || V_8 -> V_40 == V_76 ) {
F_41 ( & V_75 -> V_72 , V_8 ,
V_64 , V_65 , true ) ;
if ( ! V_75 -> V_72 )
V_75 -> V_72 = V_77 ;
}
}
}
}
static void F_44 ( struct V_7 * V_8 , struct V_62 * V_63 ,
T_1 * V_64 , T_1 V_65 )
{
F_38 ( V_8 , V_63 , * V_64 , V_65 ) ;
F_45 ( & V_63 -> V_72 , * V_64 , V_65 ) ;
F_46 ( V_8 ) ;
* V_64 = V_65 ;
}
static void F_47 ( struct V_7 * V_8 , T_3 V_78 ,
T_1 V_64 [ 4 ] , const T_1 V_65 [ 4 ] )
{
int V_66 = V_8 -> V_67 - F_39 ( V_8 ) ;
if ( V_78 == V_79 ) {
if ( F_40 ( V_66 >= sizeof( struct V_71 ) ) )
F_48 ( & F_42 ( V_8 ) -> V_72 , V_8 ,
V_64 , V_65 , true ) ;
} else if ( V_78 == V_80 ) {
if ( F_40 ( V_66 >= sizeof( struct V_74 ) ) ) {
struct V_74 * V_75 = F_43 ( V_8 ) ;
if ( V_75 -> V_72 || V_8 -> V_40 == V_76 ) {
F_48 ( & V_75 -> V_72 , V_8 ,
V_64 , V_65 , true ) ;
if ( ! V_75 -> V_72 )
V_75 -> V_72 = V_77 ;
}
}
} else if ( V_78 == V_81 ) {
if ( F_40 ( V_66 >= sizeof( struct V_82 ) ) )
F_48 ( & F_49 ( V_8 ) -> V_83 ,
V_8 , V_64 , V_65 , true ) ;
}
}
static void F_50 ( const T_1 V_84 [ 4 ] , const T_1 V_64 [ 4 ] ,
const T_1 V_37 [ 4 ] , T_1 V_85 [ 4 ] )
{
V_85 [ 0 ] = F_26 ( V_84 [ 0 ] , V_64 [ 0 ] , V_37 [ 0 ] ) ;
V_85 [ 1 ] = F_26 ( V_84 [ 1 ] , V_64 [ 1 ] , V_37 [ 1 ] ) ;
V_85 [ 2 ] = F_26 ( V_84 [ 2 ] , V_64 [ 2 ] , V_37 [ 2 ] ) ;
V_85 [ 3 ] = F_26 ( V_84 [ 3 ] , V_64 [ 3 ] , V_37 [ 3 ] ) ;
}
static void F_51 ( struct V_7 * V_8 , T_3 V_78 ,
T_1 V_64 [ 4 ] , const T_1 V_65 [ 4 ] ,
bool V_86 )
{
if ( V_86 )
F_47 ( V_8 , V_78 , V_64 , V_65 ) ;
F_46 ( V_8 ) ;
memcpy ( V_64 , V_65 , sizeof( T_1 [ 4 ] ) ) ;
}
static void F_52 ( struct V_87 * V_63 , T_5 V_88 , T_5 V_37 )
{
F_35 ( V_63 -> V_89 [ 0 ] , ( T_3 ) ( V_88 >> 16 ) , ( T_3 ) ( V_37 >> 16 ) ) ;
F_35 ( V_63 -> V_89 [ 1 ] , ( T_3 ) ( V_88 >> 8 ) , ( T_3 ) ( V_37 >> 8 ) ) ;
F_35 ( V_63 -> V_89 [ 2 ] , ( T_3 ) V_88 , ( T_3 ) V_37 ) ;
}
static void F_53 ( struct V_7 * V_8 , struct V_62 * V_63 , T_3 V_90 ,
T_3 V_37 )
{
V_90 = F_26 ( V_63 -> V_91 , V_90 , V_37 ) ;
F_54 ( & V_63 -> V_72 , F_8 ( V_63 -> V_91 << 8 ) , F_8 ( V_90 << 8 ) ) ;
V_63 -> V_91 = V_90 ;
}
static int F_55 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const struct V_92 * V_10 ,
const struct V_92 * V_37 )
{
struct V_62 * V_63 ;
T_1 V_65 ;
int V_34 ;
V_34 = F_20 ( V_8 , F_56 ( V_8 ) +
sizeof( struct V_62 ) ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
V_63 = F_57 ( V_8 ) ;
if ( V_37 -> V_93 ) {
V_65 = F_26 ( V_63 -> V_94 , V_10 -> V_93 , V_37 -> V_93 ) ;
if ( F_21 ( V_65 != V_63 -> V_94 ) ) {
F_44 ( V_8 , V_63 , & V_63 -> V_94 , V_65 ) ;
V_36 -> V_95 . V_64 . V_55 = V_65 ;
}
}
if ( V_37 -> V_96 ) {
V_65 = F_26 ( V_63 -> V_97 , V_10 -> V_96 , V_37 -> V_96 ) ;
if ( F_21 ( V_65 != V_63 -> V_97 ) ) {
F_44 ( V_8 , V_63 , & V_63 -> V_97 , V_65 ) ;
V_36 -> V_95 . V_64 . V_54 = V_65 ;
}
}
if ( V_37 -> V_98 ) {
F_58 ( V_63 , ~ V_37 -> V_98 , V_10 -> V_98 ) ;
V_36 -> V_99 . V_100 = V_63 -> V_100 ;
}
if ( V_37 -> V_101 ) {
F_53 ( V_8 , V_63 , V_10 -> V_101 , V_37 -> V_101 ) ;
V_36 -> V_99 . V_91 = V_63 -> V_91 ;
}
return 0 ;
}
static bool F_59 ( const T_1 V_64 [ 4 ] )
{
return ! ! ( V_64 [ 0 ] | V_64 [ 1 ] | V_64 [ 2 ] | V_64 [ 3 ] ) ;
}
static int F_60 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const struct V_102 * V_10 ,
const struct V_102 * V_37 )
{
struct V_87 * V_63 ;
int V_34 ;
V_34 = F_20 ( V_8 , F_56 ( V_8 ) +
sizeof( struct V_87 ) ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
V_63 = F_61 ( V_8 ) ;
if ( F_59 ( V_37 -> V_103 ) ) {
T_1 * V_94 = ( T_1 * ) & V_63 -> V_94 ;
T_1 V_85 [ 4 ] ;
F_50 ( V_94 , V_10 -> V_103 , V_37 -> V_103 , V_85 ) ;
if ( F_21 ( memcmp ( V_94 , V_85 , sizeof( V_85 ) ) ) ) {
F_51 ( V_8 , V_36 -> V_99 . V_104 , V_94 , V_85 ,
true ) ;
memcpy ( & V_36 -> V_105 . V_64 . V_55 , V_85 ,
sizeof( V_36 -> V_105 . V_64 . V_55 ) ) ;
}
}
if ( F_59 ( V_37 -> V_106 ) ) {
unsigned int V_107 = 0 ;
int V_108 = V_109 ;
bool V_110 = true ;
T_1 * V_97 = ( T_1 * ) & V_63 -> V_97 ;
T_1 V_85 [ 4 ] ;
F_50 ( V_97 , V_10 -> V_106 , V_37 -> V_106 , V_85 ) ;
if ( F_21 ( memcmp ( V_97 , V_85 , sizeof( V_85 ) ) ) ) {
if ( F_62 ( V_63 -> V_111 ) )
V_110 = ( F_63 ( V_8 , & V_107 ,
V_112 ,
NULL , & V_108 )
!= V_112 ) ;
F_51 ( V_8 , V_36 -> V_99 . V_104 , V_97 , V_85 ,
V_110 ) ;
memcpy ( & V_36 -> V_105 . V_64 . V_54 , V_85 ,
sizeof( V_36 -> V_105 . V_64 . V_54 ) ) ;
}
}
if ( V_37 -> V_113 ) {
F_64 ( V_63 , ~ V_37 -> V_113 , V_10 -> V_113 ) ;
V_36 -> V_99 . V_100 = F_65 ( V_63 ) ;
}
if ( V_37 -> V_114 ) {
F_52 ( V_63 , F_66 ( V_10 -> V_114 ) ,
F_66 ( V_37 -> V_114 ) ) ;
V_36 -> V_105 . V_115 =
* ( T_1 * ) V_63 & F_67 ( V_116 ) ;
}
if ( V_37 -> V_117 ) {
F_35 ( V_63 -> V_118 , V_10 -> V_117 ,
V_37 -> V_117 ) ;
V_36 -> V_99 . V_91 = V_63 -> V_118 ;
}
return 0 ;
}
static void F_68 ( struct V_7 * V_8 , T_2 * V_119 ,
T_2 V_120 , T_6 * V_72 )
{
F_69 ( V_72 , V_8 , * V_119 , V_120 , false ) ;
* V_119 = V_120 ;
}
static int F_70 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const struct V_121 * V_10 ,
const struct V_121 * V_37 )
{
struct V_74 * V_75 ;
T_2 V_55 , V_54 ;
int V_34 ;
V_34 = F_20 ( V_8 , F_39 ( V_8 ) +
sizeof( struct V_74 ) ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
V_75 = F_43 ( V_8 ) ;
V_55 = F_26 ( V_75 -> V_122 , V_10 -> V_123 , V_37 -> V_123 ) ;
V_54 = F_26 ( V_75 -> V_124 , V_10 -> V_125 , V_37 -> V_125 ) ;
if ( V_75 -> V_72 && V_8 -> V_40 != V_76 ) {
if ( F_40 ( V_55 != V_75 -> V_122 ) ) {
F_68 ( V_8 , & V_75 -> V_122 , V_55 , & V_75 -> V_72 ) ;
V_36 -> V_126 . V_55 = V_55 ;
}
if ( F_40 ( V_54 != V_75 -> V_124 ) ) {
F_68 ( V_8 , & V_75 -> V_124 , V_54 , & V_75 -> V_72 ) ;
V_36 -> V_126 . V_54 = V_54 ;
}
if ( F_21 ( ! V_75 -> V_72 ) )
V_75 -> V_72 = V_77 ;
} else {
V_75 -> V_122 = V_55 ;
V_75 -> V_124 = V_54 ;
V_36 -> V_126 . V_55 = V_55 ;
V_36 -> V_126 . V_54 = V_54 ;
}
F_46 ( V_8 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const struct V_127 * V_10 ,
const struct V_127 * V_37 )
{
struct V_71 * V_128 ;
T_2 V_55 , V_54 ;
int V_34 ;
V_34 = F_20 ( V_8 , F_39 ( V_8 ) +
sizeof( struct V_71 ) ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
V_128 = F_42 ( V_8 ) ;
V_55 = F_26 ( V_128 -> V_122 , V_10 -> V_129 , V_37 -> V_129 ) ;
if ( F_40 ( V_55 != V_128 -> V_122 ) ) {
F_68 ( V_8 , & V_128 -> V_122 , V_55 , & V_128 -> V_72 ) ;
V_36 -> V_126 . V_55 = V_55 ;
}
V_54 = F_26 ( V_128 -> V_124 , V_10 -> V_130 , V_37 -> V_130 ) ;
if ( F_40 ( V_54 != V_128 -> V_124 ) ) {
F_68 ( V_8 , & V_128 -> V_124 , V_54 , & V_128 -> V_72 ) ;
V_36 -> V_126 . V_54 = V_54 ;
}
F_46 ( V_8 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_8 , struct V_9 * V_36 ,
const struct V_131 * V_10 ,
const struct V_131 * V_37 )
{
unsigned int V_132 = F_39 ( V_8 ) ;
struct V_133 * V_134 ;
T_7 V_135 , V_136 , V_137 ;
int V_34 ;
V_34 = F_20 ( V_8 , V_132 + sizeof( struct V_133 ) ) ;
if ( F_21 ( V_34 ) )
return V_34 ;
V_134 = F_73 ( V_8 ) ;
V_137 = V_134 -> V_138 ;
V_135 = F_74 ( V_8 , V_132 ) ;
V_134 -> V_122 = F_26 ( V_134 -> V_122 , V_10 -> V_139 , V_37 -> V_139 ) ;
V_134 -> V_124 = F_26 ( V_134 -> V_124 , V_10 -> V_140 , V_37 -> V_140 ) ;
V_136 = F_74 ( V_8 , V_132 ) ;
V_134 -> V_138 = V_137 ^ V_135 ^ V_136 ;
F_46 ( V_8 ) ;
V_36 -> V_126 . V_55 = V_134 -> V_122 ;
V_36 -> V_126 . V_54 = V_134 -> V_124 ;
return 0 ;
}
static int F_75 ( struct V_141 * V_141 , struct V_142 * V_143 , struct V_7 * V_8 )
{
struct V_144 * V_145 = F_6 ( & V_146 ) ;
struct V_147 * V_147 = V_145 -> V_147 ;
if ( F_11 ( V_8 , V_145 -> V_148 ) < 0 ) {
F_76 ( V_8 ) ;
return - V_26 ;
}
F_77 ( V_8 , V_145 -> V_54 ) ;
* F_78 ( V_8 ) = V_145 -> V_149 ;
V_8 -> V_31 = V_145 -> V_31 ;
V_8 -> V_48 = V_145 -> V_48 ;
V_8 -> V_150 = V_145 -> V_150 ;
F_12 ( V_8 , V_145 -> V_148 ) ;
memcpy ( V_8 -> V_145 , & V_145 -> V_151 , V_145 -> V_148 ) ;
F_16 ( V_8 , V_8 -> V_145 , V_145 -> V_148 ) ;
F_14 ( V_8 ) ;
F_79 ( V_147 , V_8 ) ;
return 0 ;
}
static unsigned int
F_80 ( const struct V_152 * V_54 )
{
return V_54 -> V_153 -> V_154 ;
}
static void F_81 ( struct V_147 * V_147 , struct V_7 * V_8 )
{
unsigned int V_155 = F_56 ( V_8 ) ;
struct V_144 * V_145 ;
V_145 = F_6 ( & V_146 ) ;
V_145 -> V_54 = V_8 -> V_156 ;
V_145 -> V_147 = V_147 ;
V_145 -> V_149 = * F_78 ( V_8 ) ;
V_145 -> V_31 = V_8 -> V_31 ;
V_145 -> V_48 = V_8 -> V_48 ;
V_145 -> V_150 = V_8 -> V_150 ;
V_145 -> V_148 = V_155 ;
memcpy ( & V_145 -> V_151 , V_8 -> V_145 , V_155 ) ;
memset ( F_82 ( V_8 ) , 0 , sizeof( struct V_157 ) ) ;
F_83 ( V_8 , V_155 ) ;
}
static void F_84 ( struct V_141 * V_141 , struct V_147 * V_147 ,
struct V_7 * V_8 , T_4 V_158 , T_2 V_33 )
{
if ( F_56 ( V_8 ) > V_159 ) {
F_85 ( 1 , L_1 ) ;
goto V_34;
}
if ( V_33 == F_8 ( V_160 ) ) {
struct V_152 V_161 ;
unsigned long V_162 ;
F_81 ( V_147 , V_8 ) ;
F_86 ( & V_161 , & V_163 , NULL , 1 ,
V_164 , V_165 ) ;
V_161 . V_153 = V_147 -> V_153 ;
V_162 = V_8 -> V_156 ;
F_87 ( V_8 , & V_161 ) ;
F_82 ( V_8 ) -> V_166 = V_158 ;
F_88 ( V_141 , V_8 -> V_143 , V_8 , F_75 ) ;
F_89 ( V_162 ) ;
} else if ( V_33 == F_8 ( V_167 ) ) {
const struct V_168 * V_169 = F_90 () ;
unsigned long V_162 ;
struct V_170 V_171 ;
if ( ! V_169 ) {
goto V_34;
}
F_81 ( V_147 , V_8 ) ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
F_86 ( & V_171 . V_54 , & V_163 , NULL , 1 ,
V_164 , V_165 ) ;
V_171 . V_54 . V_153 = V_147 -> V_153 ;
V_162 = V_8 -> V_156 ;
F_87 ( V_8 , & V_171 . V_54 ) ;
F_91 ( V_8 ) -> V_166 = V_158 ;
V_169 -> V_172 ( V_141 , V_8 -> V_143 , V_8 , F_75 ) ;
F_89 ( V_162 ) ;
} else {
F_92 ( 1 , L_2 ,
F_93 ( V_147 ) , F_33 ( V_33 ) , V_158 ,
V_147 -> V_153 -> V_154 ) ;
goto V_34;
}
return;
V_34:
F_76 ( V_8 ) ;
}
static void F_94 ( struct V_173 * V_174 , struct V_7 * V_8 , int V_175 ,
struct V_9 * V_10 )
{
struct V_147 * V_147 = F_95 ( V_174 , V_175 ) ;
if ( F_40 ( V_147 ) ) {
T_4 V_158 = F_78 ( V_8 ) -> V_158 ;
if ( F_40 ( ! V_158 || ( V_8 -> V_67 <= V_158 + V_35 ) ) ) {
F_79 ( V_147 , V_8 ) ;
} else if ( V_158 <= V_147 -> V_153 -> V_154 ) {
struct V_141 * V_141 = F_96 ( & V_174 -> V_141 ) ;
T_2 V_33 = V_10 -> V_17 . type ;
if ( ! F_9 ( V_10 ) ) {
if ( F_24 ( V_8 -> V_32 ) )
V_33 = V_8 -> V_31 ;
else
V_33 = F_97 ( V_8 ) ;
}
F_84 ( V_141 , V_147 , V_8 , V_158 , V_33 ) ;
} else {
F_76 ( V_8 ) ;
}
} else {
F_76 ( V_8 ) ;
}
}
static int F_98 ( struct V_173 * V_174 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_11 * V_15 , int V_176 )
{
struct V_177 V_178 ;
const struct V_11 * V_179 ;
int V_180 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_181 = V_182 ;
V_178 . V_158 = F_78 ( V_8 ) -> V_158 ;
for ( V_179 = F_99 ( V_12 ) , V_180 = F_100 ( V_12 ) ; V_180 > 0 ;
V_179 = F_101 ( V_179 , & V_180 ) ) {
switch ( F_102 ( V_179 ) ) {
case V_183 :
V_178 . V_184 = V_179 ;
break;
case V_185 :
V_178 . V_186 = F_103 ( V_179 ) ;
break;
case V_187 : {
struct V_147 * V_147 ;
V_147 = F_95 ( V_174 , F_103 ( V_179 ) ) ;
if ( V_147 ) {
int V_34 ;
V_34 = F_104 ( V_147 -> V_153 , V_8 ) ;
if ( ! V_34 )
V_178 . V_188 = F_105 ( V_8 ) ;
}
break;
}
case V_189 : {
V_178 . V_15 = V_15 ;
V_178 . V_176 = V_176 ;
break;
}
}
}
return F_106 ( V_174 , V_8 , V_10 , & V_178 ) ;
}
static int F_107 ( struct V_173 * V_174 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_11 * V_15 , int V_176 )
{
const struct V_11 * V_190 = NULL ;
const struct V_11 * V_179 ;
int V_180 ;
for ( V_179 = F_99 ( V_12 ) , V_180 = F_100 ( V_12 ) ; V_180 > 0 ;
V_179 = F_101 ( V_179 , & V_180 ) ) {
T_5 V_191 ;
switch ( F_102 ( V_179 ) ) {
case V_192 :
V_191 = F_103 ( V_179 ) ;
if ( ! V_191 || F_108 () > V_191 )
return 0 ;
break;
case V_193 :
V_190 = V_179 ;
break;
}
}
V_180 = F_100 ( V_190 ) ;
V_179 = F_99 ( V_190 ) ;
if ( F_21 ( ! V_180 ) )
return 0 ;
if ( F_40 ( F_102 ( V_179 ) == V_194 &&
F_109 ( V_179 , V_180 ) ) )
return F_98 ( V_174 , V_8 , V_10 , V_179 , V_15 , V_176 ) ;
V_8 = F_110 ( V_8 , V_195 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_5 ( V_8 , V_10 , V_179 ) ) {
if ( F_111 () )
F_112 ( L_3 ,
F_113 ( V_174 ) ) ;
F_76 ( V_8 ) ;
}
return 0 ;
}
static void F_114 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_196 * V_197 = F_99 ( V_12 ) ;
T_5 V_198 = 0 ;
V_198 = F_115 ( V_8 ) ;
V_198 = F_116 ( V_198 , V_197 -> V_199 ) ;
if ( ! V_198 )
V_198 = 0x1 ;
V_10 -> V_200 = V_198 ;
}
static int F_117 ( struct V_7 * V_8 ,
struct V_9 * V_36 ,
const struct V_11 * V_179 )
{
if ( F_102 ( V_179 ) == V_201 ) {
struct V_202 * V_203 = F_99 ( V_179 ) ;
F_118 ( V_8 ) ;
F_119 ( (struct V_152 * ) V_203 -> V_204 ) ;
F_120 ( V_8 , (struct V_152 * ) V_203 -> V_204 ) ;
return 0 ;
}
return - V_205 ;
}
static int F_121 ( struct V_7 * V_8 ,
struct V_9 * V_36 ,
const struct V_11 * V_179 )
{
int V_34 = 0 ;
switch ( F_102 ( V_179 ) ) {
case V_206 :
F_35 ( V_8 -> V_207 , F_103 ( V_179 ) ,
* F_122 ( V_179 , T_5 * ) ) ;
V_36 -> V_208 . V_207 = V_8 -> V_207 ;
break;
case V_209 :
F_35 ( V_8 -> V_210 , F_103 ( V_179 ) , * F_122 ( V_179 , T_5 * ) ) ;
V_36 -> V_208 . V_211 = V_8 -> V_210 ;
break;
case V_201 :
V_34 = - V_205 ;
break;
case V_212 :
V_34 = F_36 ( V_8 , V_36 , F_99 ( V_179 ) ,
F_122 ( V_179 , struct V_56 * ) ) ;
break;
case V_213 :
V_34 = F_55 ( V_8 , V_36 , F_99 ( V_179 ) ,
F_122 ( V_179 , struct V_92 * ) ) ;
break;
case V_214 :
V_34 = F_60 ( V_8 , V_36 , F_99 ( V_179 ) ,
F_122 ( V_179 , struct V_102 * ) ) ;
break;
case V_215 :
V_34 = F_71 ( V_8 , V_36 , F_99 ( V_179 ) ,
F_122 ( V_179 , struct V_127 * ) ) ;
break;
case V_216 :
V_34 = F_70 ( V_8 , V_36 , F_99 ( V_179 ) ,
F_122 ( V_179 , struct V_121 * ) ) ;
break;
case V_217 :
V_34 = F_72 ( V_8 , V_36 , F_99 ( V_179 ) ,
F_122 ( V_179 , struct V_131 * ) ) ;
break;
case V_218 :
V_34 = F_25 ( V_8 , V_36 , F_99 ( V_179 ) , F_122 ( V_179 ,
T_1 * ) ) ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
V_34 = - V_205 ;
break;
}
return V_34 ;
}
static int F_123 ( struct V_173 * V_174 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_179 , int V_180 )
{
struct V_5 * V_13 ;
if ( ! F_9 ( V_10 ) ) {
int V_34 ;
V_34 = F_124 ( V_8 , V_10 ) ;
if ( V_34 )
return V_34 ;
}
F_125 ( ! F_9 ( V_10 ) ) ;
if ( ! F_109 ( V_179 , V_180 ) ) {
V_8 = F_110 ( V_8 , V_195 ) ;
if ( ! V_8 )
return 0 ;
}
V_13 = F_5 ( V_8 , V_10 , NULL ) ;
if ( V_13 ) {
V_13 -> V_16 . V_223 = F_103 ( V_179 ) ;
} else {
F_76 ( V_8 ) ;
if ( F_111 () )
F_112 ( L_4 ,
F_113 ( V_174 ) ) ;
}
return 0 ;
}
static int F_126 ( struct V_173 * V_174 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 , int V_67 )
{
int V_224 = - 1 ;
const struct V_11 * V_179 ;
int V_180 ;
for ( V_179 = V_12 , V_180 = V_67 ; V_180 > 0 ;
V_179 = F_101 ( V_179 , & V_180 ) ) {
int V_34 = 0 ;
if ( F_21 ( V_224 != - 1 ) ) {
struct V_7 * V_225 = F_110 ( V_8 , V_195 ) ;
if ( V_225 )
F_94 ( V_174 , V_225 , V_224 , V_10 ) ;
V_224 = - 1 ;
}
switch ( F_102 ( V_179 ) ) {
case V_226 :
V_224 = F_103 ( V_179 ) ;
break;
case V_194 :
F_98 ( V_174 , V_8 , V_10 , V_179 , V_12 , V_67 ) ;
break;
case V_227 :
F_114 ( V_8 , V_10 , V_179 ) ;
break;
case V_228 :
V_34 = F_10 ( V_8 , V_10 , F_99 ( V_179 ) ) ;
break;
case V_229 :
V_34 = F_19 ( V_8 , V_10 , F_127 ( V_179 ) ) ;
break;
case V_230 :
V_34 = F_31 ( V_8 , V_10 , F_99 ( V_179 ) ) ;
break;
case V_231 :
V_34 = F_28 ( V_8 , V_10 ) ;
break;
case V_232 :
V_34 = F_123 ( V_174 , V_8 , V_10 , V_179 , V_180 ) ;
if ( F_109 ( V_179 , V_180 ) ) {
return V_34 ;
}
break;
case V_233 :
V_34 = F_117 ( V_8 , V_10 , F_99 ( V_179 ) ) ;
break;
case V_234 :
case V_235 :
V_34 = F_121 ( V_8 , V_10 , F_99 ( V_179 ) ) ;
break;
case V_236 :
V_34 = F_107 ( V_174 , V_8 , V_10 , V_179 , V_12 , V_67 ) ;
break;
case V_237 :
if ( ! F_9 ( V_10 ) ) {
V_34 = F_124 ( V_8 , V_10 ) ;
if ( V_34 )
return V_34 ;
}
V_34 = F_128 ( F_129 ( V_174 ) , V_8 , V_10 ,
F_99 ( V_179 ) ) ;
if ( V_34 )
return V_34 == - V_238 ? 0 : V_34 ;
break;
}
if ( F_21 ( V_34 ) ) {
F_76 ( V_8 ) ;
return V_34 ;
}
}
if ( V_224 != - 1 )
F_94 ( V_174 , V_8 , V_224 , V_10 ) ;
else
F_130 ( V_8 ) ;
return 0 ;
}
static void F_131 ( struct V_173 * V_174 )
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
F_126 ( V_174 , V_8 , V_10 , V_15 ,
F_100 ( V_15 ) ) ;
else
F_132 ( V_8 , V_10 ) ;
} while ( ! F_2 ( V_2 ) );
F_1 ( V_2 ) ;
}
int F_133 ( struct V_173 * V_174 , struct V_7 * V_8 ,
const struct V_239 * V_240 ,
struct V_9 * V_10 )
{
static const int V_241 = 5 ;
int V_34 , V_242 ;
V_242 = F_134 ( V_243 ) ;
if ( F_21 ( V_242 > V_241 ) ) {
F_135 ( L_5 ,
F_113 ( V_174 ) ) ;
F_76 ( V_8 ) ;
V_34 = - V_244 ;
goto V_245;
}
V_34 = F_126 ( V_174 , V_8 , V_10 ,
V_240 -> V_15 , V_240 -> V_176 ) ;
if ( V_242 == 1 )
F_131 ( V_174 ) ;
V_245:
F_136 ( V_243 ) ;
return V_34 ;
}
int F_137 ( void )
{
V_14 = F_138 ( struct V_1 ) ;
if ( ! V_14 )
return - V_26 ;
return 0 ;
}
void F_139 ( void )
{
F_140 ( V_14 ) ;
}
