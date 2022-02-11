static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void * F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_6 + V_3 ;
}
static inline T_1 F_6 ( T_2 V_7 , T_2 V_8 , T_2 V_9 , T_2 V_10 , T_2 V_11 ,
T_2 V_12 , int V_13 , int V_14 , int V_15 ,
int V_16 , int V_17 , int V_18 )
{
return F_7 ( V_7 << V_19 |
V_9 << V_20 |
V_8 << V_21 |
V_10 << V_22 |
V_11 << V_23 |
V_12 << V_24 |
V_13 << V_25 |
V_14 << V_26 |
V_15 << V_27 |
V_16 << V_28 |
V_17 << V_29 |
V_18 << V_30 ) ;
}
struct V_1 * F_8 ( const struct V_31 * V_32 )
{
struct V_1 * V_2 = F_9 ( sizeof( * V_2 ) , V_33 ) ;
T_1 V_34 ;
if ( ! V_2 )
return NULL ;
V_2 -> V_35 = V_32 ;
V_2 -> V_36 . V_37 = V_38 ;
V_2 -> V_39 = 0 ;
V_2 -> V_39 |= V_40 << V_41 ;
V_2 -> V_39 |= V_42 << V_43 ;
V_2 -> V_39 |= V_44 << V_45 ;
F_10 ( & V_2 -> V_46 . V_47 , 1 ) ;
V_2 -> V_46 . V_37 = V_38 ;
V_2 -> V_48 . V_49 = 0 ;
V_2 -> V_48 . V_37 = V_38 ;
if ( ( V_2 -> V_35 -> V_50 & V_51 ) < V_52 ) {
V_2 -> V_48 . V_53 = 4 ;
V_2 -> V_48 . V_54 = 1 ;
} else {
V_2 -> V_48 . V_53 = 8 ;
V_2 -> V_48 . V_54 = 0 ;
}
V_2 -> V_6 = V_32 -> V_55 ;
V_2 -> V_4 = V_32 -> V_56 ;
V_34 = F_6 ( V_2 -> V_48 . V_53 ,
1 ,
0 ,
3 ,
2 ,
3 ,
0 ,
1 ,
0 ,
1 ,
0 ,
0 ) ;
F_3 ( V_2 , V_57 , V_34 ) ;
V_34 = F_1 ( V_2 , V_57 ) ;
if ( ! V_34 ) {
F_11 ( L_1 ) ;
return NULL ;
}
F_3 ( V_2 , V_58 , 0 ) ;
return V_2 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
T_1 F_14 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_59 ) ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_60 )
{
F_3 ( V_2 , V_59 , V_60 ) ;
}
T_1 F_16 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_61 ) ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_60 )
{
F_3 ( V_2 , V_61 , V_60 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_62 ) ;
}
void F_19 ( struct V_1 * V_2 , int V_63 )
{
F_3 ( V_2 , V_62 , V_63 ? 0xffffffff : 0 ) ;
}
void * F_20 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_64 ) ;
}
void F_21 ( struct V_1 * V_2 , void * V_65 , T_2 V_66 )
{
T_2 * V_67 = V_65 ;
F_22 () ;
* V_67 = V_66 | V_2 -> V_36 . V_37 ;
}
void * F_23 ( struct V_1 * V_2 )
{
T_1 * V_68 , V_69 ;
V_68 = F_5 ( V_2 , F_24 ( V_2 -> V_36 . V_37 ) ) ;
V_69 = V_68 [ 0 ] & ~ V_38 ;
if ( ! V_69 )
return NULL ;
V_2 -> V_36 . V_37 ^= V_38 ;
return V_68 ;
}
void F_25 ( struct V_70 * V_32 )
{
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
}
void F_26 ( struct V_70 * V_32 , int V_71 )
{
V_32 -> V_69 &= ~ ( 1 << V_72 ) ;
if ( V_71 )
V_32 -> V_69 |= V_73 ;
else
V_32 -> V_69 |= V_74 ;
}
void F_27 ( struct V_70 * V_32 , T_1 V_75 )
{
V_32 -> V_69 &= ~ ( 1 << V_76 ) ;
V_32 -> V_77 = F_7 ( V_75 ) ;
}
void F_28 ( struct V_70 * V_32 , T_1 V_78 ,
T_1 V_79 , T_1 V_80 )
{
V_32 -> V_69 |= 1 << V_76 ;
V_32 -> V_77 = F_7 ( V_78 ) ;
V_32 -> V_81 = F_29 ( V_79 ) ;
V_32 -> V_82 = V_80 ;
}
int F_30 ( struct V_1 * V_83 , const struct V_70 * V_32 ,
const struct V_84 * V_85 )
{
struct V_70 * V_2 ;
T_1 V_86 = F_1 ( V_83 , V_87 ) ;
if ( ! F_31 ( V_86 ) )
return - V_88 ;
V_2 = F_5 ( V_83 , F_32 ( F_33 ( V_86 ) ) ) ;
memcpy ( & V_2 -> V_89 , & V_32 -> V_89 , 31 ) ;
memcpy ( & V_2 -> V_85 , V_85 , sizeof( * V_85 ) ) ;
F_22 () ;
V_2 -> V_69 = V_32 -> V_69 | F_34 ( V_86 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_83 , T_2 V_90 , int * V_91 )
{
T_3 V_92 = ( V_83 -> V_39 >> V_93 ) & V_94 ;
F_36 ( V_90 > 15 ) ;
* V_91 = V_92 | ( 1 << V_90 ) ;
}
void F_37 ( struct V_1 * V_83 , T_2 V_90 , int V_95 )
{
T_3 V_96 ;
F_36 ( V_90 > 15 ) ;
if ( V_95 )
V_83 -> V_39 |= 1 << V_90 ;
else
V_83 -> V_39 &= ~ ( 1 << V_90 ) ;
V_96 = ( V_83 -> V_39 >> V_93 ) & V_94 ;
if ( V_96 != 0 )
F_3 ( V_83 , V_58 , V_83 -> V_39 ) ;
else
F_3 ( V_83 , V_58 , 0 ) ;
}
void F_38 ( struct V_97 * V_32 )
{
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
}
void F_39 ( struct V_97 * V_32 ,
struct V_98 * V_99 ,
T_4 V_100 ,
int V_101 )
{
V_32 -> V_102 = ( V_103 ) V_99 ;
if ( ! V_99 ) {
V_32 -> V_69 &= ~ ( 1 << V_104 ) ;
return;
}
V_32 -> V_69 |= 1 << V_104 ;
if ( V_101 )
V_32 -> V_69 |= 1 << V_105 ;
else
V_32 -> V_69 &= ~ ( 1 << V_105 ) ;
V_32 -> V_106 = F_40 ( V_100 ) ;
}
void F_41 ( struct V_97 * V_32 , T_2 V_107 )
{
V_32 -> V_108 = V_107 - 1 ;
}
void F_42 ( struct V_97 * V_32 , T_2 V_109 )
{
V_32 -> V_110 = V_109 ;
}
void F_43 ( struct V_97 * V_32 , T_1 V_75 )
{
V_32 -> V_69 |= 1 << V_111 ;
V_32 -> V_69 |= V_112 << V_113 ;
V_32 -> V_114 = F_7 ( V_75 ) ;
}
void F_44 ( struct V_97 * V_32 , T_1 V_115 ,
enum V_116 V_117 )
{
V_32 -> V_69 |= V_117 << V_111 ;
V_32 -> V_69 |= V_118 << V_113 ;
V_32 -> V_114 = F_7 ( V_115 ) ;
}
void F_45 ( struct V_97 * V_32 , T_1 V_119 ,
enum V_116 V_117 )
{
V_32 -> V_69 |= V_117 << V_111 ;
V_32 -> V_69 |= V_120 << V_113 ;
V_32 -> V_114 = F_7 ( V_119 ) ;
}
int F_46 ( struct V_1 * V_83 , struct V_97 * V_32 )
{
struct V_97 * V_2 ;
if ( ! F_47 ( & V_83 -> V_46 . V_47 ) ) {
F_48 ( & V_83 -> V_46 . V_47 ) ;
return - V_88 ;
}
V_83 -> V_46 . V_99 = ( void * ) V_32 -> V_102 ;
V_2 = F_5 ( V_83 , V_121 ) ;
V_2 -> V_108 = V_32 -> V_108 ;
V_2 -> V_110 = V_122 ;
V_2 -> V_114 = V_32 -> V_114 ;
V_2 -> V_106 = V_32 -> V_106 ;
V_2 -> V_102 = V_32 -> V_102 ;
F_22 () ;
V_2 -> V_69 = V_32 -> V_69 | V_83 -> V_46 . V_37 ;
V_83 -> V_46 . V_37 ^= V_38 ;
return 0 ;
}
const struct V_98 * F_49 ( struct V_1 * V_83 )
{
T_1 V_69 ;
T_1 V_123 ;
T_1 V_124 ;
struct V_98 * V_2 ;
if ( F_50 ( V_83 -> V_48 . V_54 ) ) {
T_2 V_125 = F_1 ( V_83 , V_126 ) &
V_127 ;
if ( V_125 == V_83 -> V_48 . V_49 )
return NULL ;
if ( V_83 -> V_48 . V_49 == ( V_83 -> V_48 . V_53 - 1 ) ) {
F_51 ( L_2 ,
V_83 -> V_48 . V_49 , V_125 ) ;
V_83 -> V_48 . V_54 = 0 ;
}
F_52 ( F_5 ( V_83 ,
F_53 ( V_83 -> V_48 . V_49 ) ) ) ;
}
V_2 = F_5 ( V_83 , F_53 ( V_83 -> V_48 . V_49 ) ) ;
V_69 = V_2 -> V_128 . V_69 ;
if ( ( V_69 & V_38 ) != V_83 -> V_48 . V_37 ) {
F_52 ( F_5 ( V_83 ,
F_53 ( V_83 -> V_48 . V_49 ) ) ) ;
return NULL ;
}
V_83 -> V_48 . V_49 ++ ;
V_83 -> V_48 . V_49 &= V_83 -> V_48 . V_53 - 1 ;
if ( ! V_83 -> V_48 . V_49 )
V_83 -> V_48 . V_37 ^= V_38 ;
V_124 = V_2 -> V_128 . V_129 ;
V_123 = V_69 & V_130 ;
if ( ( V_123 == V_131 ) &&
( V_124 & V_132 ) &&
( V_124 & V_133 ) )
F_48 ( & V_83 -> V_46 . V_47 ) ;
F_52 ( F_5 ( V_83 , F_53 ( V_83 -> V_48 . V_49 ) ) ) ;
return V_2 ;
}
void F_54 ( struct V_1 * V_83 , const struct V_98 * V_128 )
{
F_3 ( V_83 , V_134 , F_55 ( V_128 ) ) ;
}
int F_56 ( struct V_1 * V_83 , const struct V_98 * V_128 )
{
if ( V_128 -> V_128 . V_110 != V_122 )
return 0 ;
( (struct V_98 * ) V_128 ) -> V_128 . V_110 = 0 ;
if ( V_83 -> V_46 . V_99 == V_128 ) {
V_83 -> V_46 . V_99 = NULL ;
F_48 ( & V_83 -> V_46 . V_47 ) ;
}
return 1 ;
}
void F_57 ( struct V_135 * V_32 )
{
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_69 = 1 << 5 ;
}
void F_58 ( struct V_135 * V_32 , T_3 V_136 )
{
V_32 -> V_136 = F_29 ( V_136 ) ;
}
void F_59 ( struct V_135 * V_32 , int V_95 )
{
if ( V_95 )
V_32 -> V_69 |= 1 << 6 ;
else
V_32 -> V_69 &= ~ ( 1 << 6 ) ;
}
int F_60 ( struct V_1 * V_83 , const struct V_135 * V_32 ,
const V_103 * V_137 , unsigned int V_138 )
{
int V_139 ;
struct V_135 * V_2 ;
T_1 V_140 ;
if ( ! V_138 || ( V_138 > 7 ) )
return - V_141 ;
V_140 = F_1 ( V_83 , V_142 ) ;
if ( ! F_61 ( V_140 ) )
return - V_88 ;
V_2 = F_5 ( V_83 , F_62 ( F_63 ( V_140 ) ) ) ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ )
V_2 -> V_143 [ V_139 ] = F_40 ( V_137 [ V_139 ] ) ;
V_2 -> V_136 = V_32 -> V_136 ;
F_22 () ;
V_2 -> V_69 = V_32 -> V_69 | F_64 ( V_140 ) | V_138 ;
return 0 ;
}
int F_65 ( struct V_1 * V_83 , T_3 V_136 , V_103 * V_137 ,
unsigned int V_138 )
{
struct V_144 * V_2 ;
struct V_145 * V_146 ;
int V_139 ;
if ( ! V_138 || ( V_138 > 7 ) )
return - V_141 ;
V_2 = F_20 ( V_83 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_136 = F_29 ( V_136 ) ;
V_2 -> V_147 = V_138 ;
V_146 = F_66 ( V_83 , V_2 , V_148 ) ;
if ( F_50 ( ! V_146 ) ) {
F_11 ( L_3 ,
V_136 ) ;
return - V_149 ;
}
F_36 ( ( V_146 -> V_69 & 0x7f ) != V_148 ) ;
if ( F_50 ( V_146 -> V_150 != V_151 ) ) {
F_11 ( L_4 ,
V_136 , V_146 -> V_150 ) ;
return - V_149 ;
}
F_36 ( V_146 -> V_147 > V_138 ) ;
for ( V_139 = 0 ; V_139 < V_146 -> V_147 ; V_139 ++ )
V_137 [ V_139 ] = F_67 ( V_146 -> V_143 [ V_139 ] ) ;
return ( int ) V_146 -> V_147 ;
}
int F_68 ( struct V_1 * V_83 , T_1 V_75 ,
T_2 V_152 )
{
struct V_153 * V_2 ;
struct V_154 * V_146 ;
V_2 = F_20 ( V_83 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_75 = F_7 ( V_75 ) & V_155 ;
V_146 = F_66 ( V_83 , V_2 , V_152 ) ;
if ( F_50 ( ! V_146 ) ) {
F_11 ( L_5 ,
V_152 ) ;
return - V_149 ;
}
F_36 ( ( V_146 -> V_69 & V_130 ) != V_152 ) ;
if ( F_50 ( V_146 -> V_150 != V_151 ) ) {
F_11 ( L_6 ,
V_75 , V_146 -> V_69 , V_146 -> V_150 ) ;
return - V_149 ;
}
return 0 ;
}
int F_69 ( struct V_1 * V_83 , T_3 V_156 ,
T_2 V_157 , T_2 V_158 ,
V_103 V_159 )
{
struct V_160 * V_2 = NULL ;
struct V_161 * V_146 = NULL ;
V_2 = F_20 ( V_83 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_162 = F_29 ( V_156 ) ;
V_2 -> V_163 = V_157 ;
if ( V_158 )
V_2 -> V_164 = 1 ;
else
V_2 -> V_164 = 0 ;
V_2 -> V_165 = F_40 ( V_159 ) ;
V_146 = F_66 ( V_83 , V_2 , V_166 ) ;
if ( F_50 ( ! V_146 ) ) {
F_11 ( L_7 ) ;
return - V_149 ;
}
F_36 ( ( V_146 -> V_69 & 0x7f ) != V_166 ) ;
if ( F_50 ( V_146 -> V_150 != V_151 ) ) {
F_11 ( L_8 ,
V_156 , V_146 -> V_150 ) ;
return - V_149 ;
}
return 0 ;
}
