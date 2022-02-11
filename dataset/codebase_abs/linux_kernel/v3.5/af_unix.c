static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
memcpy ( F_2 ( V_4 ) , & V_2 -> V_5 , sizeof( V_6 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = * F_2 ( V_4 ) ;
}
static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{ }
static inline void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{ }
static inline unsigned int F_4 ( T_1 V_7 )
{
unsigned int V_8 = ( V_9 unsigned int ) V_7 ;
V_8 ^= V_8 >> 16 ;
V_8 ^= V_8 >> 8 ;
return V_8 & ( V_10 - 1 ) ;
}
static inline int F_5 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_6 ( V_13 ) == V_12 ;
}
static inline int F_7 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_6 ( V_13 ) == NULL || F_5 ( V_12 , V_13 ) ;
}
static inline int F_8 ( struct V_11 const * V_12 )
{
return F_9 ( & V_12 -> V_14 ) > V_12 -> V_15 ;
}
struct V_11 * F_10 ( struct V_11 * V_16 )
{
struct V_11 * V_17 ;
F_11 ( V_16 ) ;
V_17 = F_6 ( V_16 ) ;
if ( V_17 )
F_12 ( V_17 ) ;
F_13 ( V_16 ) ;
return V_17 ;
}
static inline void F_14 ( struct V_18 * V_19 )
{
if ( F_15 ( & V_19 -> V_20 ) )
F_16 ( V_19 ) ;
}
static int F_17 ( struct V_21 * V_22 , int V_23 , unsigned int * V_24 )
{
if ( V_23 <= sizeof( short ) || V_23 > sizeof( * V_22 ) )
return - V_25 ;
if ( ! V_22 || V_22 -> V_26 != V_27 )
return - V_25 ;
if ( V_22 -> V_28 [ 0 ] ) {
( ( char * ) V_22 ) [ V_23 ] = 0 ;
V_23 = strlen ( V_22 -> V_28 ) + 1 + sizeof( short ) ;
return V_23 ;
}
* V_24 = F_4 ( F_18 ( V_22 , V_23 , 0 ) ) ;
return V_23 ;
}
static void F_19 ( struct V_11 * V_12 )
{
F_20 ( V_12 ) ;
}
static void F_21 ( struct V_29 * V_30 , struct V_11 * V_12 )
{
F_22 ( ! F_23 ( V_12 ) ) ;
F_24 ( V_12 , V_30 ) ;
}
static inline void F_25 ( struct V_11 * V_12 )
{
F_26 ( & V_31 ) ;
F_19 ( V_12 ) ;
F_27 ( & V_31 ) ;
}
static inline void F_28 ( struct V_29 * V_30 , struct V_11 * V_12 )
{
F_26 ( & V_31 ) ;
F_21 ( V_30 , V_12 ) ;
F_27 ( & V_31 ) ;
}
static struct V_11 * F_29 ( struct V_32 * V_32 ,
struct V_21 * V_33 ,
int V_23 , int type , unsigned int V_8 )
{
struct V_11 * V_16 ;
struct V_34 * V_35 ;
F_30 (s, node, &unix_socket_table[hash ^ type]) {
struct V_36 * V_37 = F_31 ( V_16 ) ;
if ( ! F_32 ( F_33 ( V_16 ) , V_32 ) )
continue;
if ( V_37 -> V_19 -> V_23 == V_23 &&
! memcmp ( V_37 -> V_19 -> V_38 , V_33 , V_23 ) )
goto V_39;
}
V_16 = NULL ;
V_39:
return V_16 ;
}
static inline struct V_11 * F_34 ( struct V_32 * V_32 ,
struct V_21 * V_33 ,
int V_23 , int type ,
unsigned int V_8 )
{
struct V_11 * V_16 ;
F_26 ( & V_31 ) ;
V_16 = F_29 ( V_32 , V_33 , V_23 , type , V_8 ) ;
if ( V_16 )
F_12 ( V_16 ) ;
F_27 ( & V_31 ) ;
return V_16 ;
}
static struct V_11 * F_35 ( struct V_40 * V_41 )
{
struct V_11 * V_16 ;
struct V_34 * V_35 ;
F_26 ( & V_31 ) ;
F_30 (s, node,
&unix_socket_table[i->i_ino & (UNIX_HASH_SIZE - 1)]) {
struct V_42 * V_42 = F_31 ( V_16 ) -> V_43 . V_42 ;
if ( V_42 && V_42 -> V_44 == V_41 ) {
F_12 ( V_16 ) ;
goto V_39;
}
}
V_16 = NULL ;
V_39:
F_27 ( & V_31 ) ;
return V_16 ;
}
static inline int F_36 ( struct V_11 * V_12 )
{
return ( F_37 ( & V_12 -> V_45 ) << 2 ) <= V_12 -> V_46 ;
}
static void F_38 ( struct V_11 * V_12 )
{
struct V_47 * V_48 ;
F_39 () ;
if ( F_36 ( V_12 ) ) {
V_48 = F_40 ( V_12 -> V_49 ) ;
if ( F_41 ( V_48 ) )
F_42 ( & V_48 -> V_50 ,
V_51 | V_52 | V_53 ) ;
F_43 ( V_12 , V_54 , V_55 ) ;
}
F_44 () ;
}
static void F_45 ( struct V_11 * V_12 , struct V_11 * V_56 )
{
if ( ! F_46 ( & V_12 -> V_14 ) ) {
F_47 ( & V_12 -> V_14 ) ;
F_48 ( & F_31 ( V_12 ) -> V_57 ) ;
if ( ! F_49 ( V_56 , V_58 ) && F_6 ( V_56 ) == V_12 ) {
V_56 -> V_59 = V_60 ;
V_56 -> V_61 ( V_56 ) ;
}
}
}
static void F_50 ( struct V_11 * V_12 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
F_47 ( & V_12 -> V_14 ) ;
F_22 ( F_37 ( & V_12 -> V_45 ) ) ;
F_22 ( ! F_23 ( V_12 ) ) ;
F_22 ( V_12 -> V_62 ) ;
if ( ! F_49 ( V_12 , V_58 ) ) {
F_51 ( V_63 L_1 , V_12 ) ;
return;
}
if ( V_37 -> V_19 )
F_14 ( V_37 -> V_19 ) ;
F_52 ( & V_64 ) ;
F_53 () ;
F_54 ( F_33 ( V_12 ) , V_12 -> V_65 , - 1 ) ;
F_55 () ;
#ifdef F_56
F_51 ( V_66 L_2 , V_12 ,
F_57 ( & V_64 ) ) ;
#endif
}
static int F_58 ( struct V_11 * V_12 , int V_67 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_43 V_43 ;
struct V_11 * V_68 ;
struct V_3 * V_4 ;
int V_69 ;
F_25 ( V_12 ) ;
F_11 ( V_12 ) ;
F_59 ( V_12 ) ;
V_12 -> V_70 = V_71 ;
V_43 = V_37 -> V_43 ;
V_37 -> V_43 . V_42 = NULL ;
V_37 -> V_43 . V_72 = NULL ;
V_69 = V_12 -> V_73 ;
V_12 -> V_73 = V_74 ;
F_13 ( V_12 ) ;
F_48 ( & V_37 -> V_57 ) ;
V_68 = F_6 ( V_12 ) ;
if ( V_68 != NULL ) {
if ( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) {
F_11 ( V_68 ) ;
V_68 -> V_70 = V_71 ;
if ( ! F_46 ( & V_12 -> V_14 ) || V_67 )
V_68 -> V_59 = V_60 ;
F_13 ( V_68 ) ;
V_68 -> V_78 ( V_68 ) ;
F_43 ( V_68 , V_79 , V_80 ) ;
}
F_60 ( V_68 ) ;
F_6 ( V_12 ) = NULL ;
}
while ( ( V_4 = F_61 ( & V_12 -> V_14 ) ) != NULL ) {
if ( V_69 == V_81 )
F_58 ( V_4 -> V_12 , 1 ) ;
F_62 ( V_4 ) ;
}
if ( V_43 . V_42 )
F_63 ( & V_43 ) ;
F_60 ( V_12 ) ;
if ( V_82 )
F_64 () ;
return 0 ;
}
static void F_65 ( struct V_11 * V_12 )
{
F_66 ( V_12 -> V_83 ) ;
if ( V_12 -> V_84 )
F_67 ( V_12 -> V_84 ) ;
V_12 -> V_83 = F_68 ( F_69 ( V_85 ) ) ;
V_12 -> V_84 = F_70 () ;
}
static void F_71 ( struct V_11 * V_12 , struct V_11 * V_86 )
{
F_66 ( V_12 -> V_83 ) ;
if ( V_12 -> V_84 )
F_67 ( V_12 -> V_84 ) ;
V_12 -> V_83 = F_68 ( V_86 -> V_83 ) ;
V_12 -> V_84 = F_72 ( V_86 -> V_84 ) ;
}
static int F_73 ( struct V_87 * V_11 , int V_88 )
{
int V_89 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_90 * V_91 = NULL ;
const struct V_92 * V_93 = NULL ;
V_89 = - V_94 ;
if ( V_11 -> type != V_76 && V_11 -> type != V_77 )
goto V_95;
V_89 = - V_25 ;
if ( ! V_37 -> V_19 )
goto V_95;
F_11 ( V_12 ) ;
if ( V_12 -> V_73 != V_74 && V_12 -> V_73 != V_81 )
goto V_96;
if ( V_88 > V_12 -> V_15 )
F_48 ( & V_37 -> V_57 ) ;
V_12 -> V_15 = V_88 ;
V_12 -> V_73 = V_81 ;
F_65 ( V_12 ) ;
V_89 = 0 ;
V_96:
F_13 ( V_12 ) ;
F_66 ( V_91 ) ;
if ( V_93 )
F_67 ( V_93 ) ;
V_95:
return V_89 ;
}
static void F_74 ( struct V_11 * V_12 , int V_97 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
F_75 ( & V_37 -> V_98 ) ;
V_12 -> V_99 = V_97 ;
F_76 ( & V_37 -> V_98 ) ;
}
static struct V_11 * F_77 ( struct V_32 * V_32 , struct V_87 * V_11 )
{
struct V_11 * V_12 = NULL ;
struct V_36 * V_37 ;
F_78 ( & V_64 ) ;
if ( F_57 ( & V_64 ) > 2 * F_79 () )
goto V_95;
V_12 = F_80 ( V_32 , V_100 , V_101 , & V_102 ) ;
if ( ! V_12 )
goto V_95;
F_81 ( V_11 , V_12 ) ;
F_82 ( & V_12 -> V_14 . V_103 ,
& V_104 ) ;
V_12 -> V_105 = F_38 ;
V_12 -> V_15 = V_32 -> V_106 . V_107 ;
V_12 -> V_108 = F_50 ;
V_37 = F_31 ( V_12 ) ;
V_37 -> V_43 . V_42 = NULL ;
V_37 -> V_43 . V_72 = NULL ;
F_83 ( & V_37 -> V_103 ) ;
F_84 ( & V_37 -> V_109 , 0 ) ;
F_85 ( & V_37 -> V_110 ) ;
F_86 ( & V_37 -> V_98 ) ;
F_87 ( & V_37 -> V_57 ) ;
F_28 ( V_111 , V_12 ) ;
V_95:
if ( V_12 == NULL )
F_52 ( & V_64 ) ;
else {
F_53 () ;
F_54 ( F_33 ( V_12 ) , V_12 -> V_65 , 1 ) ;
F_55 () ;
}
return V_12 ;
}
static int F_88 ( struct V_32 * V_32 , struct V_87 * V_11 , int V_112 ,
int V_113 )
{
if ( V_112 && V_112 != V_100 )
return - V_114 ;
V_11 -> V_69 = V_115 ;
switch ( V_11 -> type ) {
case V_76 :
V_11 -> V_116 = & V_117 ;
break;
case V_118 :
V_11 -> type = V_119 ;
case V_119 :
V_11 -> V_116 = & V_120 ;
break;
case V_77 :
V_11 -> V_116 = & V_121 ;
break;
default:
return - V_122 ;
}
return F_77 ( V_32 , V_11 ) ? 0 : - V_123 ;
}
static int F_89 ( struct V_87 * V_11 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
if ( ! V_12 )
return 0 ;
V_11 -> V_12 = NULL ;
return F_58 ( V_12 , 0 ) ;
}
static int F_90 ( struct V_87 * V_11 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
static V_6 V_124 = 1 ;
struct V_18 * V_19 ;
int V_89 ;
unsigned int V_125 = 0 ;
F_75 ( & V_37 -> V_98 ) ;
V_89 = 0 ;
if ( V_37 -> V_19 )
goto V_95;
V_89 = - V_123 ;
V_19 = F_91 ( sizeof( * V_19 ) + sizeof( short ) + 16 , V_101 ) ;
if ( ! V_19 )
goto V_95;
V_19 -> V_38 -> V_26 = V_27 ;
F_92 ( & V_19 -> V_20 , 1 ) ;
V_126:
V_19 -> V_23 = sprintf ( V_19 -> V_38 -> V_28 + 1 , L_3 , V_124 ) + 1 + sizeof( short ) ;
V_19 -> V_8 = F_4 ( F_18 ( V_19 -> V_38 , V_19 -> V_23 , 0 ) ) ;
F_26 ( & V_31 ) ;
V_124 = ( V_124 + 1 ) & 0xFFFFF ;
if ( F_29 ( V_32 , V_19 -> V_38 , V_19 -> V_23 , V_11 -> type ,
V_19 -> V_8 ) ) {
F_27 ( & V_31 ) ;
F_93 () ;
if ( V_125 ++ == 0xFFFFF ) {
V_89 = - V_127 ;
F_16 ( V_19 ) ;
goto V_95;
}
goto V_126;
}
V_19 -> V_8 ^= V_12 -> V_75 ;
F_19 ( V_12 ) ;
V_37 -> V_19 = V_19 ;
F_21 ( & V_128 [ V_19 -> V_8 ] , V_12 ) ;
F_27 ( & V_31 ) ;
V_89 = 0 ;
V_95: F_76 ( & V_37 -> V_98 ) ;
return V_89 ;
}
static struct V_11 * F_94 ( struct V_32 * V_32 ,
struct V_21 * V_33 , int V_23 ,
int type , unsigned int V_8 , int * error )
{
struct V_11 * V_37 ;
struct V_43 V_43 ;
int V_89 = 0 ;
if ( V_33 -> V_28 [ 0 ] ) {
struct V_40 * V_40 ;
V_89 = F_95 ( V_33 -> V_28 , V_129 , & V_43 ) ;
if ( V_89 )
goto V_130;
V_40 = V_43 . V_42 -> V_44 ;
V_89 = F_96 ( V_40 , V_131 ) ;
if ( V_89 )
goto V_132;
V_89 = - V_133 ;
if ( ! F_97 ( V_40 -> V_134 ) )
goto V_132;
V_37 = F_35 ( V_40 ) ;
if ( ! V_37 )
goto V_132;
if ( V_37 -> V_75 == type )
F_98 ( & V_43 ) ;
F_63 ( & V_43 ) ;
V_89 = - V_135 ;
if ( V_37 -> V_75 != type ) {
F_60 ( V_37 ) ;
goto V_130;
}
} else {
V_89 = - V_133 ;
V_37 = F_34 ( V_32 , V_33 , V_23 , type , V_8 ) ;
if ( V_37 ) {
struct V_42 * V_42 ;
V_42 = F_31 ( V_37 ) -> V_43 . V_42 ;
if ( V_42 )
F_98 ( & F_31 ( V_37 ) -> V_43 ) ;
} else
goto V_130;
}
return V_37 ;
V_132:
F_63 ( & V_43 ) ;
V_130:
* error = V_89 ;
return NULL ;
}
static int F_99 ( struct V_87 * V_11 , struct V_136 * V_137 , int V_138 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_137 ;
char * V_28 = V_22 -> V_28 ;
struct V_42 * V_42 = NULL ;
struct V_43 V_43 ;
int V_89 ;
unsigned int V_8 ;
struct V_18 * V_19 ;
struct V_29 * V_30 ;
V_89 = - V_25 ;
if ( V_22 -> V_26 != V_27 )
goto V_95;
if ( V_138 == sizeof( short ) ) {
V_89 = F_90 ( V_11 ) ;
goto V_95;
}
V_89 = F_17 ( V_22 , V_138 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_138 = V_89 ;
F_75 ( & V_37 -> V_98 ) ;
V_89 = - V_25 ;
if ( V_37 -> V_19 )
goto V_139;
V_89 = - V_123 ;
V_19 = F_100 ( sizeof( * V_19 ) + V_138 , V_101 ) ;
if ( ! V_19 )
goto V_139;
memcpy ( V_19 -> V_38 , V_22 , V_138 ) ;
V_19 -> V_23 = V_138 ;
V_19 -> V_8 = V_8 ^ V_12 -> V_75 ;
F_92 ( & V_19 -> V_20 , 1 ) ;
if ( V_28 [ 0 ] ) {
T_2 V_140 ;
V_89 = 0 ;
V_42 = F_101 ( V_141 , V_28 , & V_43 , 0 ) ;
V_89 = F_102 ( V_42 ) ;
if ( F_103 ( V_42 ) )
goto V_142;
V_140 = V_143 |
( F_104 ( V_11 ) -> V_134 & ~ F_105 () ) ;
V_89 = F_106 ( V_43 . V_72 ) ;
if ( V_89 )
goto V_144;
V_89 = F_107 ( & V_43 , V_42 , V_140 , 0 ) ;
if ( V_89 )
goto V_145;
V_89 = F_108 ( V_43 . V_42 -> V_44 , V_42 , V_140 , 0 ) ;
V_145:
F_109 ( V_43 . V_72 ) ;
if ( V_89 )
goto V_144;
F_76 ( & V_43 . V_42 -> V_44 -> V_146 ) ;
F_110 ( V_43 . V_42 ) ;
V_43 . V_42 = V_42 ;
V_19 -> V_8 = V_10 ;
}
F_26 ( & V_31 ) ;
if ( ! V_28 [ 0 ] ) {
V_89 = - V_147 ;
if ( F_29 ( V_32 , V_22 , V_138 ,
V_12 -> V_75 , V_8 ) ) {
F_14 ( V_19 ) ;
goto V_96;
}
V_30 = & V_128 [ V_19 -> V_8 ] ;
} else {
V_30 = & V_128 [ V_42 -> V_44 -> V_148 & ( V_10 - 1 ) ] ;
V_37 -> V_43 = V_43 ;
}
V_89 = 0 ;
F_19 ( V_12 ) ;
V_37 -> V_19 = V_19 ;
F_21 ( V_30 , V_12 ) ;
V_96:
F_27 ( & V_31 ) ;
V_139:
F_76 ( & V_37 -> V_98 ) ;
V_95:
return V_89 ;
V_144:
F_110 ( V_42 ) ;
F_76 ( & V_43 . V_42 -> V_44 -> V_146 ) ;
F_63 ( & V_43 ) ;
V_142:
if ( V_89 == - V_149 )
V_89 = - V_147 ;
F_14 ( V_19 ) ;
goto V_139;
}
static void F_111 ( struct V_11 * V_150 , struct V_11 * V_151 )
{
if ( F_112 ( V_150 == V_151 ) || ! V_151 ) {
F_11 ( V_150 ) ;
return;
}
if ( V_150 < V_151 ) {
F_11 ( V_150 ) ;
F_113 ( V_151 ) ;
} else {
F_11 ( V_151 ) ;
F_113 ( V_150 ) ;
}
}
static void F_114 ( struct V_11 * V_150 , struct V_11 * V_151 )
{
if ( F_112 ( V_150 == V_151 ) || ! V_151 ) {
F_13 ( V_150 ) ;
return;
}
F_13 ( V_150 ) ;
F_13 ( V_151 ) ;
}
static int F_115 ( struct V_87 * V_11 , struct V_136 * V_19 ,
int V_152 , int V_153 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_19 ;
struct V_11 * V_56 ;
unsigned int V_8 ;
int V_89 ;
if ( V_19 -> V_154 != V_155 ) {
V_89 = F_17 ( V_22 , V_152 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_152 = V_89 ;
if ( F_116 ( V_156 , & V_11 -> V_153 ) &&
! F_31 ( V_12 ) -> V_19 && ( V_89 = F_90 ( V_11 ) ) != 0 )
goto V_95;
V_157:
V_56 = F_94 ( V_32 , V_22 , V_152 , V_11 -> type , V_8 , & V_89 ) ;
if ( ! V_56 )
goto V_95;
F_111 ( V_12 , V_56 ) ;
if ( F_49 ( V_56 , V_58 ) ) {
F_114 ( V_12 , V_56 ) ;
F_60 ( V_56 ) ;
goto V_157;
}
V_89 = - V_158 ;
if ( ! F_7 ( V_12 , V_56 ) )
goto V_96;
V_89 = F_117 ( V_12 -> V_62 , V_56 -> V_62 ) ;
if ( V_89 )
goto V_96;
} else {
V_56 = NULL ;
F_111 ( V_12 , V_56 ) ;
}
if ( F_6 ( V_12 ) ) {
struct V_11 * V_159 = F_6 ( V_12 ) ;
F_6 ( V_12 ) = V_56 ;
F_114 ( V_12 , V_56 ) ;
if ( V_56 != V_159 )
F_45 ( V_12 , V_159 ) ;
F_60 ( V_159 ) ;
} else {
F_6 ( V_12 ) = V_56 ;
F_114 ( V_12 , V_56 ) ;
}
return 0 ;
V_96:
F_114 ( V_12 , V_56 ) ;
F_60 ( V_56 ) ;
V_95:
return V_89 ;
}
static long F_118 ( struct V_11 * V_56 , long V_160 )
{
struct V_36 * V_37 = F_31 ( V_56 ) ;
int V_161 ;
F_119 ( V_50 ) ;
F_120 ( & V_37 -> V_57 , & V_50 , V_162 ) ;
V_161 = ! F_49 ( V_56 , V_58 ) &&
! ( V_56 -> V_70 & V_163 ) &&
F_8 ( V_56 ) ;
F_13 ( V_56 ) ;
if ( V_161 )
V_160 = F_121 ( V_160 ) ;
F_122 ( & V_37 -> V_57 , & V_50 ) ;
return V_160 ;
}
static int F_123 ( struct V_87 * V_11 , struct V_136 * V_137 ,
int V_138 , int V_153 )
{
struct V_21 * V_22 = (struct V_21 * ) V_137 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) , * V_164 , * V_165 ;
struct V_11 * V_166 = NULL ;
struct V_11 * V_56 = NULL ;
struct V_3 * V_4 = NULL ;
unsigned int V_8 ;
int V_167 ;
int V_89 ;
long V_160 ;
V_89 = F_17 ( V_22 , V_138 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_138 = V_89 ;
if ( F_116 ( V_156 , & V_11 -> V_153 ) && ! V_37 -> V_19 &&
( V_89 = F_90 ( V_11 ) ) != 0 )
goto V_95;
V_160 = F_124 ( V_12 , V_153 & V_168 ) ;
V_89 = - V_123 ;
V_166 = F_77 ( F_33 ( V_12 ) , NULL ) ;
if ( V_166 == NULL )
goto V_95;
V_4 = F_125 ( V_166 , 1 , 0 , V_101 ) ;
if ( V_4 == NULL )
goto V_95;
V_157:
V_56 = F_94 ( V_32 , V_22 , V_138 , V_12 -> V_75 , V_8 , & V_89 ) ;
if ( ! V_56 )
goto V_95;
F_11 ( V_56 ) ;
if ( F_49 ( V_56 , V_58 ) ) {
F_13 ( V_56 ) ;
F_60 ( V_56 ) ;
goto V_157;
}
V_89 = - V_133 ;
if ( V_56 -> V_73 != V_81 )
goto V_96;
if ( V_56 -> V_70 & V_163 )
goto V_96;
if ( F_8 ( V_56 ) ) {
V_89 = - V_169 ;
if ( ! V_160 )
goto V_96;
V_160 = F_118 ( V_56 , V_160 ) ;
V_89 = F_126 ( V_160 ) ;
if ( F_127 ( V_85 ) )
goto V_95;
F_60 ( V_56 ) ;
goto V_157;
}
V_167 = V_12 -> V_73 ;
switch ( V_167 ) {
case V_74 :
break;
case V_170 :
V_89 = - V_171 ;
goto V_96;
default:
V_89 = - V_25 ;
goto V_96;
}
F_113 ( V_12 ) ;
if ( V_12 -> V_73 != V_167 ) {
F_13 ( V_12 ) ;
F_13 ( V_56 ) ;
F_60 ( V_56 ) ;
goto V_157;
}
V_89 = F_128 ( V_12 , V_56 , V_166 ) ;
if ( V_89 ) {
F_13 ( V_12 ) ;
goto V_96;
}
F_12 ( V_12 ) ;
F_6 ( V_166 ) = V_12 ;
V_166 -> V_73 = V_170 ;
V_166 -> V_75 = V_12 -> V_75 ;
F_65 ( V_166 ) ;
V_164 = F_31 ( V_166 ) ;
F_129 ( V_166 -> V_49 , & V_164 -> V_172 ) ;
V_165 = F_31 ( V_56 ) ;
if ( V_165 -> V_19 ) {
F_130 ( & V_165 -> V_19 -> V_20 ) ;
V_164 -> V_19 = V_165 -> V_19 ;
}
if ( V_165 -> V_43 . V_42 ) {
F_131 ( & V_165 -> V_43 ) ;
V_164 -> V_43 = V_165 -> V_43 ;
}
F_71 ( V_12 , V_56 ) ;
V_11 -> V_69 = V_173 ;
V_12 -> V_73 = V_170 ;
F_12 ( V_166 ) ;
F_132 () ;
F_6 ( V_12 ) = V_166 ;
F_13 ( V_12 ) ;
F_26 ( & V_56 -> V_14 . V_103 ) ;
F_133 ( & V_56 -> V_14 , V_4 ) ;
F_27 ( & V_56 -> V_14 . V_103 ) ;
F_13 ( V_56 ) ;
V_56 -> V_174 ( V_56 , 0 ) ;
F_60 ( V_56 ) ;
return 0 ;
V_96:
if ( V_56 )
F_13 ( V_56 ) ;
V_95:
F_62 ( V_4 ) ;
if ( V_166 )
F_58 ( V_166 , 0 ) ;
if ( V_56 )
F_60 ( V_56 ) ;
return V_89 ;
}
static int F_134 ( struct V_87 * V_175 , struct V_87 * V_176 )
{
struct V_11 * V_177 = V_175 -> V_12 , * V_4 = V_176 -> V_12 ;
F_12 ( V_177 ) ;
F_12 ( V_4 ) ;
F_6 ( V_177 ) = V_4 ;
F_6 ( V_4 ) = V_177 ;
F_65 ( V_177 ) ;
F_65 ( V_4 ) ;
if ( V_177 -> V_75 != V_119 ) {
V_177 -> V_73 = V_170 ;
V_4 -> V_73 = V_170 ;
V_175 -> V_69 = V_173 ;
V_176 -> V_69 = V_173 ;
}
return 0 ;
}
static int F_135 ( struct V_87 * V_11 , struct V_87 * V_178 , int V_153 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_179 ;
struct V_3 * V_4 ;
int V_89 ;
V_89 = - V_94 ;
if ( V_11 -> type != V_76 && V_11 -> type != V_77 )
goto V_95;
V_89 = - V_25 ;
if ( V_12 -> V_73 != V_81 )
goto V_95;
V_4 = F_136 ( V_12 , 0 , V_153 & V_168 , & V_89 ) ;
if ( ! V_4 ) {
if ( V_89 == 0 )
V_89 = - V_25 ;
goto V_95;
}
V_179 = V_4 -> V_12 ;
F_137 ( V_12 , V_4 ) ;
F_138 ( & F_31 ( V_12 ) -> V_57 ) ;
F_11 ( V_179 ) ;
V_178 -> V_69 = V_173 ;
F_139 ( V_179 , V_178 ) ;
F_13 ( V_179 ) ;
return 0 ;
V_95:
return V_89 ;
}
static int F_140 ( struct V_87 * V_11 , struct V_136 * V_137 , int * V_180 , int V_17 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 ;
F_141 ( struct V_21 * , V_22 , V_137 ) ;
int V_89 = 0 ;
if ( V_17 ) {
V_12 = F_10 ( V_12 ) ;
V_89 = - V_181 ;
if ( ! V_12 )
goto V_95;
V_89 = 0 ;
} else {
F_12 ( V_12 ) ;
}
V_37 = F_31 ( V_12 ) ;
F_11 ( V_12 ) ;
if ( ! V_37 -> V_19 ) {
V_22 -> V_26 = V_27 ;
V_22 -> V_28 [ 0 ] = 0 ;
* V_180 = sizeof( short ) ;
} else {
struct V_18 * V_19 = V_37 -> V_19 ;
* V_180 = V_19 -> V_23 ;
memcpy ( V_22 , V_19 -> V_38 , * V_180 ) ;
}
F_13 ( V_12 ) ;
F_60 ( V_12 ) ;
V_95:
return V_89 ;
}
static void F_142 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_41 ;
V_2 -> V_182 = F_143 ( V_4 ) . V_182 ;
F_143 ( V_4 ) . V_182 = NULL ;
for ( V_41 = V_2 -> V_182 -> V_183 - 1 ; V_41 >= 0 ; V_41 -- )
F_144 ( V_2 -> V_182 -> V_182 [ V_41 ] ) ;
}
static void F_145 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_90 = F_143 ( V_4 ) . V_90 ;
V_2 . V_92 = F_143 ( V_4 ) . V_92 ;
if ( F_143 ( V_4 ) . V_182 )
F_142 ( & V_2 , V_4 ) ;
F_146 ( & V_2 ) ;
F_147 ( V_4 ) ;
}
static int F_148 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_41 ;
unsigned char V_184 = 0 ;
int V_185 = 0 ;
for ( V_41 = V_2 -> V_182 -> V_183 - 1 ; V_41 >= 0 ; V_41 -- ) {
struct V_11 * V_12 = F_149 ( V_2 -> V_182 -> V_182 [ V_41 ] ) ;
if ( V_12 ) {
V_185 ++ ;
V_184 = F_150 ( V_184 ,
F_31 ( V_12 ) -> V_186 ) ;
}
}
if ( F_112 ( V_184 > V_187 ) )
return - V_188 ;
F_143 ( V_4 ) . V_182 = F_151 ( V_2 -> V_182 ) ;
if ( ! F_143 ( V_4 ) . V_182 )
return - V_123 ;
if ( V_185 ) {
for ( V_41 = V_2 -> V_182 -> V_183 - 1 ; V_41 >= 0 ; V_41 -- )
F_152 ( V_2 -> V_182 -> V_182 [ V_41 ] ) ;
}
return V_184 ;
}
static int F_153 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_189 )
{
int V_89 = 0 ;
F_143 ( V_4 ) . V_90 = F_68 ( V_2 -> V_90 ) ;
if ( V_2 -> V_92 )
F_143 ( V_4 ) . V_92 = F_72 ( V_2 -> V_92 ) ;
F_143 ( V_4 ) . V_182 = NULL ;
if ( V_2 -> V_182 && V_189 )
V_89 = F_148 ( V_2 , V_4 ) ;
V_4 -> V_190 = F_145 ;
return V_89 ;
}
static void F_154 ( struct V_3 * V_4 , const struct V_87 * V_11 ,
const struct V_11 * V_56 )
{
if ( F_143 ( V_4 ) . V_92 )
return;
if ( F_116 ( V_156 , & V_11 -> V_153 ) ||
! V_56 -> V_62 ||
F_116 ( V_156 , & V_56 -> V_62 -> V_153 ) ) {
F_143 ( V_4 ) . V_90 = F_68 ( F_69 ( V_85 ) ) ;
F_143 ( V_4 ) . V_92 = F_70 () ;
}
}
static int F_155 ( struct V_191 * V_191 , struct V_87 * V_11 ,
struct V_192 * V_193 , T_3 V_23 )
{
struct V_194 * V_195 = F_156 ( V_191 ) ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = V_193 -> V_196 ;
struct V_11 * V_56 = NULL ;
int V_197 = 0 ;
int V_89 ;
unsigned int V_8 ;
struct V_3 * V_4 ;
long V_160 ;
struct V_1 V_198 ;
int V_184 ;
int V_199 = 0 ;
if ( NULL == V_195 -> V_2 )
V_195 -> V_2 = & V_198 ;
F_157 () ;
V_89 = F_158 ( V_11 , V_193 , V_195 -> V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = - V_94 ;
if ( V_193 -> V_200 & V_201 )
goto V_95;
if ( V_193 -> V_202 ) {
V_89 = F_17 ( V_22 , V_193 -> V_202 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_197 = V_89 ;
} else {
V_22 = NULL ;
V_89 = - V_181 ;
V_56 = F_10 ( V_12 ) ;
if ( ! V_56 )
goto V_95;
}
if ( F_116 ( V_156 , & V_11 -> V_153 ) && ! V_37 -> V_19
&& ( V_89 = F_90 ( V_11 ) ) != 0 )
goto V_95;
V_89 = - V_203 ;
if ( V_23 > V_12 -> V_46 - 32 )
goto V_95;
if ( V_23 > V_204 )
V_199 = F_159 ( T_3 ,
V_23 - V_204 ,
V_205 * V_206 ) ;
V_4 = F_160 ( V_12 , V_23 - V_199 , V_199 ,
V_193 -> V_200 & V_207 , & V_89 ) ;
if ( V_4 == NULL )
goto V_95;
V_89 = F_153 ( V_195 -> V_2 , V_4 , true ) ;
if ( V_89 < 0 )
goto V_208;
V_184 = V_89 + 1 ;
F_1 ( V_195 -> V_2 , V_4 ) ;
F_161 ( V_4 , V_23 - V_199 ) ;
V_4 -> V_199 = V_199 ;
V_4 -> V_23 = V_23 ;
V_89 = F_162 ( V_4 , 0 , V_193 -> V_209 , 0 , V_23 ) ;
if ( V_89 )
goto V_208;
V_160 = F_124 ( V_12 , V_193 -> V_200 & V_207 ) ;
V_157:
if ( ! V_56 ) {
V_89 = - V_60 ;
if ( V_22 == NULL )
goto V_208;
V_56 = F_94 ( V_32 , V_22 , V_197 , V_12 -> V_75 ,
V_8 , & V_89 ) ;
if ( V_56 == NULL )
goto V_208;
}
if ( F_163 ( V_56 , V_4 ) < 0 ) {
V_89 = V_23 ;
goto V_208;
}
F_11 ( V_56 ) ;
V_89 = - V_158 ;
if ( ! F_7 ( V_12 , V_56 ) )
goto V_96;
if ( F_49 ( V_56 , V_58 ) ) {
F_13 ( V_56 ) ;
F_60 ( V_56 ) ;
V_89 = 0 ;
F_11 ( V_12 ) ;
if ( F_6 ( V_12 ) == V_56 ) {
F_6 ( V_12 ) = NULL ;
F_13 ( V_12 ) ;
F_45 ( V_12 , V_56 ) ;
F_60 ( V_56 ) ;
V_89 = - V_133 ;
} else {
F_13 ( V_12 ) ;
}
V_56 = NULL ;
if ( V_89 )
goto V_208;
goto V_157;
}
V_89 = - V_210 ;
if ( V_56 -> V_70 & V_163 )
goto V_96;
if ( V_12 -> V_75 != V_77 ) {
V_89 = F_117 ( V_12 -> V_62 , V_56 -> V_62 ) ;
if ( V_89 )
goto V_96;
}
if ( F_6 ( V_56 ) != V_12 && F_8 ( V_56 ) ) {
if ( ! V_160 ) {
V_89 = - V_169 ;
goto V_96;
}
V_160 = F_118 ( V_56 , V_160 ) ;
V_89 = F_126 ( V_160 ) ;
if ( F_127 ( V_85 ) )
goto V_208;
goto V_157;
}
if ( F_49 ( V_56 , V_211 ) )
F_164 ( V_4 ) ;
F_154 ( V_4 , V_11 , V_56 ) ;
F_165 ( & V_56 -> V_14 , V_4 ) ;
if ( V_184 > F_31 ( V_56 ) -> V_186 )
F_31 ( V_56 ) -> V_186 = V_184 ;
F_13 ( V_56 ) ;
V_56 -> V_174 ( V_56 , V_23 ) ;
F_60 ( V_56 ) ;
F_146 ( V_195 -> V_2 ) ;
return V_23 ;
V_96:
F_13 ( V_56 ) ;
V_208:
F_62 ( V_4 ) ;
V_95:
if ( V_56 )
F_60 ( V_56 ) ;
F_146 ( V_195 -> V_2 ) ;
return V_89 ;
}
static int F_166 ( struct V_191 * V_191 , struct V_87 * V_11 ,
struct V_192 * V_193 , T_3 V_23 )
{
struct V_194 * V_195 = F_156 ( V_191 ) ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_56 = NULL ;
int V_89 , V_212 ;
struct V_3 * V_4 ;
int V_213 = 0 ;
struct V_1 V_198 ;
bool V_214 = false ;
int V_184 ;
if ( NULL == V_195 -> V_2 )
V_195 -> V_2 = & V_198 ;
F_157 () ;
V_89 = F_158 ( V_11 , V_193 , V_195 -> V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = - V_94 ;
if ( V_193 -> V_200 & V_201 )
goto V_215;
if ( V_193 -> V_202 ) {
V_89 = V_12 -> V_73 == V_170 ? - V_171 : - V_94 ;
goto V_215;
} else {
V_89 = - V_181 ;
V_56 = F_6 ( V_12 ) ;
if ( ! V_56 )
goto V_215;
}
if ( V_12 -> V_70 & V_216 )
goto V_217;
while ( V_213 < V_23 ) {
V_212 = V_23 - V_213 ;
if ( V_212 > ( ( V_12 -> V_46 >> 1 ) - 64 ) )
V_212 = ( V_12 -> V_46 >> 1 ) - 64 ;
if ( V_212 > V_204 )
V_212 = V_204 ;
V_4 = F_167 ( V_12 , V_212 , V_193 -> V_200 & V_207 ,
& V_89 ) ;
if ( V_4 == NULL )
goto V_215;
V_212 = F_159 ( int , V_212 , F_168 ( V_4 ) ) ;
V_89 = F_153 ( V_195 -> V_2 , V_4 , ! V_214 ) ;
if ( V_89 < 0 ) {
F_62 ( V_4 ) ;
goto V_215;
}
V_184 = V_89 + 1 ;
V_214 = true ;
V_89 = F_169 ( F_161 ( V_4 , V_212 ) , V_193 -> V_209 , V_212 ) ;
if ( V_89 ) {
F_62 ( V_4 ) ;
goto V_215;
}
F_11 ( V_56 ) ;
if ( F_49 ( V_56 , V_58 ) ||
( V_56 -> V_70 & V_163 ) )
goto V_218;
F_154 ( V_4 , V_11 , V_56 ) ;
F_165 ( & V_56 -> V_14 , V_4 ) ;
if ( V_184 > F_31 ( V_56 ) -> V_186 )
F_31 ( V_56 ) -> V_186 = V_184 ;
F_13 ( V_56 ) ;
V_56 -> V_174 ( V_56 , V_212 ) ;
V_213 += V_212 ;
}
F_146 ( V_195 -> V_2 ) ;
V_195 -> V_2 = NULL ;
return V_213 ;
V_218:
F_13 ( V_56 ) ;
F_62 ( V_4 ) ;
V_217:
if ( V_213 == 0 && ! ( V_193 -> V_200 & V_219 ) )
F_170 ( V_220 , V_85 , 0 ) ;
V_89 = - V_210 ;
V_215:
F_146 ( V_195 -> V_2 ) ;
V_195 -> V_2 = NULL ;
return V_213 ? : V_89 ;
}
static int F_171 ( struct V_191 * V_191 , struct V_87 * V_11 ,
struct V_192 * V_193 , T_3 V_23 )
{
int V_89 ;
struct V_11 * V_12 = V_11 -> V_12 ;
V_89 = F_172 ( V_12 ) ;
if ( V_89 )
return V_89 ;
if ( V_12 -> V_73 != V_170 )
return - V_181 ;
if ( V_193 -> V_202 )
V_193 -> V_202 = 0 ;
return F_155 ( V_191 , V_11 , V_193 , V_23 ) ;
}
static int F_173 ( struct V_191 * V_221 , struct V_87 * V_11 ,
struct V_192 * V_193 , T_3 V_212 ,
int V_153 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
if ( V_12 -> V_73 != V_170 )
return - V_181 ;
return F_174 ( V_221 , V_11 , V_193 , V_212 , V_153 ) ;
}
static void F_175 ( struct V_192 * V_193 , struct V_11 * V_12 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
V_193 -> V_202 = 0 ;
if ( V_37 -> V_19 ) {
V_193 -> V_202 = V_37 -> V_19 -> V_23 ;
memcpy ( V_193 -> V_196 , V_37 -> V_19 -> V_38 , V_37 -> V_19 -> V_23 ) ;
}
}
static int F_174 ( struct V_191 * V_221 , struct V_87 * V_11 ,
struct V_192 * V_193 , T_3 V_212 ,
int V_153 )
{
struct V_194 * V_195 = F_156 ( V_221 ) ;
struct V_1 V_198 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
int V_222 = V_153 & V_207 ;
struct V_3 * V_4 ;
int V_89 ;
int V_223 , V_224 ;
V_89 = - V_94 ;
if ( V_153 & V_201 )
goto V_95;
V_193 -> V_202 = 0 ;
V_89 = F_176 ( & V_37 -> V_98 ) ;
if ( V_89 ) {
V_89 = F_126 ( F_177 ( V_12 , V_222 ) ) ;
goto V_95;
}
V_224 = F_178 ( V_12 , V_153 ) ;
V_4 = F_179 ( V_12 , V_153 , & V_223 , & V_224 , & V_89 ) ;
if ( ! V_4 ) {
F_11 ( V_12 ) ;
if ( V_12 -> V_75 == V_77 && V_89 == - V_169 &&
( V_12 -> V_70 & V_163 ) )
V_89 = 0 ;
F_13 ( V_12 ) ;
goto V_96;
}
F_42 ( & V_37 -> V_57 ,
V_51 | V_52 | V_53 ) ;
if ( V_193 -> V_196 )
F_175 ( V_193 , V_4 -> V_12 ) ;
if ( V_212 > V_4 -> V_23 - V_224 )
V_212 = V_4 -> V_23 - V_224 ;
else if ( V_212 < V_4 -> V_23 - V_224 )
V_193 -> V_200 |= V_225 ;
V_89 = F_180 ( V_4 , V_224 , V_193 -> V_209 , V_212 ) ;
if ( V_89 )
goto V_208;
if ( F_49 ( V_12 , V_211 ) )
F_181 ( V_193 , V_12 , V_4 ) ;
if ( ! V_195 -> V_2 ) {
V_195 -> V_2 = & V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
}
F_182 ( V_195 -> V_2 , F_143 ( V_4 ) . V_90 , F_143 ( V_4 ) . V_92 ) ;
F_3 ( V_195 -> V_2 , V_4 ) ;
if ( ! ( V_153 & V_226 ) ) {
if ( F_143 ( V_4 ) . V_182 )
F_142 ( V_195 -> V_2 , V_4 ) ;
F_183 ( V_12 , V_4 -> V_23 ) ;
} else {
F_184 ( V_12 , V_212 ) ;
if ( F_143 ( V_4 ) . V_182 )
V_195 -> V_2 -> V_182 = F_151 ( F_143 ( V_4 ) . V_182 ) ;
}
V_89 = ( V_153 & V_225 ) ? V_4 -> V_23 - V_224 : V_212 ;
F_185 ( V_11 , V_193 , V_195 -> V_2 , V_153 ) ;
V_208:
F_137 ( V_12 , V_4 ) ;
V_96:
F_76 ( & V_37 -> V_98 ) ;
V_95:
return V_89 ;
}
static long F_186 ( struct V_11 * V_12 , long V_160 )
{
F_119 ( V_50 ) ;
F_11 ( V_12 ) ;
for (; ; ) {
F_187 ( F_188 ( V_12 ) , & V_50 , V_162 ) ;
if ( ! F_46 ( & V_12 -> V_14 ) ||
V_12 -> V_59 ||
( V_12 -> V_70 & V_163 ) ||
F_127 ( V_85 ) ||
! V_160 )
break;
F_189 ( V_227 , & V_12 -> V_62 -> V_153 ) ;
F_13 ( V_12 ) ;
V_160 = F_121 ( V_160 ) ;
F_11 ( V_12 ) ;
F_190 ( V_227 , & V_12 -> V_62 -> V_153 ) ;
}
F_122 ( F_188 ( V_12 ) , & V_50 ) ;
F_13 ( V_12 ) ;
return V_160 ;
}
static int F_191 ( struct V_191 * V_221 , struct V_87 * V_11 ,
struct V_192 * V_193 , T_3 V_212 ,
int V_153 )
{
struct V_194 * V_195 = F_156 ( V_221 ) ;
struct V_1 V_198 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = V_193 -> V_196 ;
int V_228 = 0 ;
int V_229 = 0 ;
int V_230 ;
int V_89 = 0 ;
long V_160 ;
int V_224 ;
V_89 = - V_25 ;
if ( V_12 -> V_73 != V_170 )
goto V_95;
V_89 = - V_94 ;
if ( V_153 & V_201 )
goto V_95;
V_230 = F_192 ( V_12 , V_153 & V_231 , V_212 ) ;
V_160 = F_177 ( V_12 , V_153 & V_207 ) ;
V_193 -> V_202 = 0 ;
if ( ! V_195 -> V_2 ) {
V_195 -> V_2 = & V_198 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
}
V_89 = F_176 ( & V_37 -> V_98 ) ;
if ( V_89 ) {
V_89 = F_126 ( V_160 ) ;
goto V_95;
}
V_224 = F_178 ( V_12 , V_153 ) ;
do {
int V_232 ;
struct V_3 * V_4 ;
F_11 ( V_12 ) ;
V_4 = F_193 ( & V_12 -> V_14 ) ;
V_233:
if ( V_4 == NULL ) {
F_31 ( V_12 ) -> V_186 = 0 ;
if ( V_228 >= V_230 )
goto V_234;
V_89 = F_172 ( V_12 ) ;
if ( V_89 )
goto V_234;
if ( V_12 -> V_70 & V_163 )
goto V_234;
F_13 ( V_12 ) ;
V_89 = - V_169 ;
if ( ! V_160 )
break;
F_76 ( & V_37 -> V_98 ) ;
V_160 = F_186 ( V_12 , V_160 ) ;
if ( F_127 ( V_85 )
|| F_176 ( & V_37 -> V_98 ) ) {
V_89 = F_126 ( V_160 ) ;
goto V_95;
}
continue;
V_234:
F_13 ( V_12 ) ;
break;
}
if ( V_224 >= V_4 -> V_23 ) {
V_224 -= V_4 -> V_23 ;
V_4 = F_194 ( V_4 , & V_12 -> V_14 ) ;
goto V_233;
}
F_13 ( V_12 ) ;
if ( V_229 ) {
if ( ( F_143 ( V_4 ) . V_90 != V_195 -> V_2 -> V_90 ) ||
( F_143 ( V_4 ) . V_92 != V_195 -> V_2 -> V_92 ) )
break;
} else {
F_182 ( V_195 -> V_2 , F_143 ( V_4 ) . V_90 , F_143 ( V_4 ) . V_92 ) ;
V_229 = 1 ;
}
if ( V_22 ) {
F_175 ( V_193 , V_4 -> V_12 ) ;
V_22 = NULL ;
}
V_232 = F_159 (unsigned int, skb->len - skip, size) ;
if ( F_195 ( V_193 -> V_209 , V_4 -> V_235 + V_224 , V_232 ) ) {
if ( V_228 == 0 )
V_228 = - V_236 ;
break;
}
V_228 += V_232 ;
V_212 -= V_232 ;
if ( ! ( V_153 & V_226 ) ) {
F_196 ( V_4 , V_232 ) ;
F_183 ( V_12 , V_232 ) ;
if ( F_143 ( V_4 ) . V_182 )
F_142 ( V_195 -> V_2 , V_4 ) ;
if ( V_4 -> V_23 )
break;
F_197 ( V_4 , & V_12 -> V_14 ) ;
F_198 ( V_4 ) ;
if ( V_195 -> V_2 -> V_182 )
break;
} else {
if ( F_143 ( V_4 ) . V_182 )
V_195 -> V_2 -> V_182 = F_151 ( F_143 ( V_4 ) . V_182 ) ;
F_184 ( V_12 , V_232 ) ;
break;
}
} while ( V_212 );
F_76 ( & V_37 -> V_98 ) ;
F_185 ( V_11 , V_193 , V_195 -> V_2 , V_153 ) ;
V_95:
return V_228 ? : V_89 ;
}
static int F_199 ( struct V_87 * V_11 , int V_140 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_56 ;
V_140 = ( V_140 + 1 ) & ( V_163 | V_216 ) ;
if ( ! V_140 )
return 0 ;
F_11 ( V_12 ) ;
V_12 -> V_70 |= V_140 ;
V_56 = F_6 ( V_12 ) ;
if ( V_56 )
F_12 ( V_56 ) ;
F_13 ( V_12 ) ;
V_12 -> V_78 ( V_12 ) ;
if ( V_56 &&
( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) ) {
int V_237 = 0 ;
if ( V_140 & V_163 )
V_237 |= V_216 ;
if ( V_140 & V_216 )
V_237 |= V_163 ;
F_11 ( V_56 ) ;
V_56 -> V_70 |= V_237 ;
F_13 ( V_56 ) ;
V_56 -> V_78 ( V_56 ) ;
if ( V_237 == V_71 )
F_43 ( V_56 , V_79 , V_80 ) ;
else if ( V_237 & V_163 )
F_43 ( V_56 , V_79 , V_238 ) ;
}
if ( V_56 )
F_60 ( V_56 ) ;
return 0 ;
}
long F_200 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
long V_239 = 0 ;
if ( V_12 -> V_73 == V_81 )
return - V_25 ;
F_26 ( & V_12 -> V_14 . V_103 ) ;
if ( V_12 -> V_75 == V_76 ||
V_12 -> V_75 == V_77 ) {
F_201 (&sk->sk_receive_queue, skb)
V_239 += V_4 -> V_23 ;
} else {
V_4 = F_193 ( & V_12 -> V_14 ) ;
if ( V_4 )
V_239 = V_4 -> V_23 ;
}
F_27 ( & V_12 -> V_14 . V_103 ) ;
return V_239 ;
}
long F_202 ( struct V_11 * V_12 )
{
return F_203 ( V_12 ) ;
}
static int F_204 ( struct V_87 * V_11 , unsigned int V_240 , unsigned long V_241 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
long V_239 = 0 ;
int V_89 ;
switch ( V_240 ) {
case V_242 :
V_239 = F_202 ( V_12 ) ;
V_89 = F_205 ( V_239 , ( int V_243 * ) V_241 ) ;
break;
case V_244 :
V_239 = F_200 ( V_12 ) ;
if ( V_239 < 0 )
V_89 = V_239 ;
else
V_89 = F_205 ( V_239 , ( int V_243 * ) V_241 ) ;
break;
default:
V_89 = - V_245 ;
break;
}
return V_89 ;
}
static unsigned int F_206 ( struct V_246 * V_246 , struct V_87 * V_11 , T_4 * V_50 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
unsigned int V_247 ;
F_207 ( V_246 , F_188 ( V_12 ) , V_50 ) ;
V_247 = 0 ;
if ( V_12 -> V_59 )
V_247 |= V_248 ;
if ( V_12 -> V_70 == V_71 )
V_247 |= V_249 ;
if ( V_12 -> V_70 & V_163 )
V_247 |= V_250 | V_251 | V_252 ;
if ( ! F_46 ( & V_12 -> V_14 ) )
V_247 |= V_251 | V_252 ;
if ( ( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) &&
V_12 -> V_73 == V_74 )
V_247 |= V_249 ;
if ( F_36 ( V_12 ) )
V_247 |= V_51 | V_52 | V_53 ;
return V_247 ;
}
static unsigned int F_208 ( struct V_246 * V_246 , struct V_87 * V_11 ,
T_4 * V_50 )
{
struct V_11 * V_12 = V_11 -> V_12 , * V_56 ;
unsigned int V_247 , V_253 ;
F_207 ( V_246 , F_188 ( V_12 ) , V_50 ) ;
V_247 = 0 ;
if ( V_12 -> V_59 || ! F_46 ( & V_12 -> V_254 ) )
V_247 |= V_248 ;
if ( V_12 -> V_70 & V_163 )
V_247 |= V_250 | V_251 | V_252 ;
if ( V_12 -> V_70 == V_71 )
V_247 |= V_249 ;
if ( ! F_46 ( & V_12 -> V_14 ) )
V_247 |= V_251 | V_252 ;
if ( V_12 -> V_75 == V_77 ) {
if ( V_12 -> V_73 == V_74 )
V_247 |= V_249 ;
if ( V_12 -> V_73 == V_255 )
return V_247 ;
}
if ( ! ( F_209 ( V_50 ) & ( V_53 | V_52 | V_51 ) ) )
return V_247 ;
V_253 = F_36 ( V_12 ) ;
V_56 = F_10 ( V_12 ) ;
if ( V_56 ) {
if ( F_6 ( V_56 ) != V_12 ) {
F_207 ( V_246 , & F_31 ( V_56 ) -> V_57 , V_50 ) ;
if ( F_8 ( V_56 ) )
V_253 = 0 ;
}
F_60 ( V_56 ) ;
}
if ( V_253 )
V_247 |= V_51 | V_52 | V_53 ;
else
F_189 ( V_256 , & V_12 -> V_62 -> V_153 ) ;
return V_247 ;
}
static struct V_11 * F_210 ( int * V_41 )
{
for ( * V_41 = 0 ; * V_41 <= V_10 ; ( * V_41 ) ++ ) {
if ( ! F_211 ( & V_128 [ * V_41 ] ) )
return F_212 ( & V_128 [ * V_41 ] ) ;
}
return NULL ;
}
static struct V_11 * F_213 ( int * V_41 , struct V_11 * V_16 )
{
struct V_11 * V_257 = F_214 ( V_16 ) ;
if ( V_257 )
return V_257 ;
for ( ( * V_41 ) ++ ; * V_41 <= V_10 ; ( * V_41 ) ++ ) {
if ( ! F_211 ( & V_128 [ * V_41 ] ) )
return F_212 ( & V_128 [ * V_41 ] ) ;
}
return NULL ;
}
static struct V_11 * F_215 ( struct V_258 * V_259 , T_5 V_260 )
{
struct V_261 * V_262 = V_259 -> V_263 ;
T_5 V_264 = 0 ;
struct V_11 * V_16 ;
for ( V_16 = F_210 ( & V_262 -> V_41 ) ; V_16 ; V_16 = F_213 ( & V_262 -> V_41 , V_16 ) ) {
if ( F_33 ( V_16 ) != F_216 ( V_259 ) )
continue;
if ( V_264 == V_260 )
return V_16 ;
++ V_264 ;
}
return NULL ;
}
static void * F_217 ( struct V_258 * V_259 , T_5 * V_260 )
__acquires( V_31 )
{
F_26 ( & V_31 ) ;
return * V_260 ? F_215 ( V_259 , * V_260 - 1 ) : V_265 ;
}
static void * F_218 ( struct V_258 * V_259 , void * V_266 , T_5 * V_260 )
{
struct V_261 * V_262 = V_259 -> V_263 ;
struct V_11 * V_12 = V_266 ;
++ * V_260 ;
if ( V_266 == V_265 )
V_12 = F_210 ( & V_262 -> V_41 ) ;
else
V_12 = F_213 ( & V_262 -> V_41 , V_12 ) ;
while ( V_12 && ( F_33 ( V_12 ) != F_216 ( V_259 ) ) )
V_12 = F_213 ( & V_262 -> V_41 , V_12 ) ;
return V_12 ;
}
static void F_219 ( struct V_258 * V_259 , void * V_266 )
__releases( V_31 )
{
F_27 ( & V_31 ) ;
}
static int F_220 ( struct V_258 * V_259 , void * V_266 )
{
if ( V_266 == V_265 )
F_221 ( V_259 , L_4
L_5 ) ;
else {
struct V_11 * V_16 = V_266 ;
struct V_36 * V_37 = F_31 ( V_16 ) ;
F_11 ( V_16 ) ;
F_222 ( V_259 , L_6 ,
V_16 ,
F_37 ( & V_16 -> V_267 ) ,
0 ,
V_16 -> V_73 == V_81 ? V_268 : 0 ,
V_16 -> V_75 ,
V_16 -> V_62 ?
( V_16 -> V_73 == V_170 ? V_173 : V_115 ) :
( V_16 -> V_73 == V_170 ? V_269 : V_270 ) ,
F_223 ( V_16 ) ) ;
if ( V_37 -> V_19 ) {
int V_41 , V_23 ;
F_224 ( V_259 , ' ' ) ;
V_41 = 0 ;
V_23 = V_37 -> V_19 -> V_23 - sizeof( short ) ;
if ( ! F_225 ( V_16 ) )
V_23 -- ;
else {
F_224 ( V_259 , '@' ) ;
V_41 ++ ;
}
for ( ; V_41 < V_23 ; V_41 ++ )
F_224 ( V_259 , V_37 -> V_19 -> V_38 -> V_28 [ V_41 ] ) ;
}
F_13 ( V_16 ) ;
F_224 ( V_259 , '\n' ) ;
}
return 0 ;
}
static int F_226 ( struct V_40 * V_40 , struct V_246 * V_246 )
{
return F_227 ( V_40 , V_246 , & V_271 ,
sizeof( struct V_261 ) ) ;
}
static int T_6 F_228 ( struct V_32 * V_32 )
{
int error = - V_123 ;
V_32 -> V_106 . V_107 = 10 ;
if ( F_229 ( V_32 ) )
goto V_95;
#ifdef F_230
if ( ! F_231 ( V_32 , L_7 , 0 , & V_272 ) ) {
F_232 ( V_32 ) ;
goto V_95;
}
#endif
error = 0 ;
V_95:
return error ;
}
static void T_7 F_233 ( struct V_32 * V_32 )
{
F_232 ( V_32 ) ;
F_234 ( V_32 , L_7 ) ;
}
static int T_8 F_235 ( void )
{
int V_273 = - 1 ;
struct V_3 * V_274 ;
F_236 ( sizeof( struct V_275 ) > sizeof( V_274 -> V_276 ) ) ;
V_273 = F_237 ( & V_102 , 1 ) ;
if ( V_273 != 0 ) {
F_51 ( V_277 L_8 ,
V_278 ) ;
goto V_95;
}
F_238 ( & V_279 ) ;
F_239 ( & V_280 ) ;
V_95:
return V_273 ;
}
static void T_9 F_240 ( void )
{
F_241 ( V_100 ) ;
F_242 ( & V_102 ) ;
F_243 ( & V_280 ) ;
}
