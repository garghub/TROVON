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
static inline unsigned F_4 ( T_1 V_7 )
{
unsigned V_8 = ( V_9 unsigned ) V_7 ;
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
static struct V_11 * F_10 ( struct V_11 * V_16 )
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
static int F_17 ( struct V_21 * V_22 , int V_23 , unsigned * V_24 )
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
int V_23 , int type , unsigned V_8 )
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
unsigned V_8 )
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
struct V_42 * V_42 = F_31 ( V_16 ) -> V_42 ;
if ( V_42 && V_42 -> V_43 == V_41 ) {
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
return ( F_37 ( & V_12 -> V_44 ) << 2 ) <= V_12 -> V_45 ;
}
static void F_38 ( struct V_11 * V_12 )
{
struct V_46 * V_47 ;
F_39 () ;
if ( F_36 ( V_12 ) ) {
V_47 = F_40 ( V_12 -> V_48 ) ;
if ( F_41 ( V_47 ) )
F_42 ( & V_47 -> V_49 ,
V_50 | V_51 | V_52 ) ;
F_43 ( V_12 , V_53 , V_54 ) ;
}
F_44 () ;
}
static void F_45 ( struct V_11 * V_12 , struct V_11 * V_55 )
{
if ( ! F_46 ( & V_12 -> V_14 ) ) {
F_47 ( & V_12 -> V_14 ) ;
F_48 ( & F_31 ( V_12 ) -> V_56 ) ;
if ( ! F_49 ( V_55 , V_57 ) && F_6 ( V_55 ) == V_12 ) {
V_55 -> V_58 = V_59 ;
V_55 -> V_60 ( V_55 ) ;
}
}
}
static void F_50 ( struct V_11 * V_12 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
F_47 ( & V_12 -> V_14 ) ;
F_22 ( F_37 ( & V_12 -> V_44 ) ) ;
F_22 ( ! F_23 ( V_12 ) ) ;
F_22 ( V_12 -> V_61 ) ;
if ( ! F_49 ( V_12 , V_57 ) ) {
F_51 ( V_62 L_1 , V_12 ) ;
return;
}
if ( V_37 -> V_19 )
F_14 ( V_37 -> V_19 ) ;
F_52 ( & V_63 ) ;
F_53 () ;
F_54 ( F_33 ( V_12 ) , V_12 -> V_64 , - 1 ) ;
F_55 () ;
#ifdef F_56
F_51 ( V_65 L_2 , V_12 ,
F_57 ( & V_63 ) ) ;
#endif
}
static int F_58 ( struct V_11 * V_12 , int V_66 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_42 * V_42 ;
struct V_67 * V_68 ;
struct V_11 * V_69 ;
struct V_3 * V_4 ;
int V_70 ;
F_25 ( V_12 ) ;
F_11 ( V_12 ) ;
F_59 ( V_12 ) ;
V_12 -> V_71 = V_72 ;
V_42 = V_37 -> V_42 ;
V_37 -> V_42 = NULL ;
V_68 = V_37 -> V_68 ;
V_37 -> V_68 = NULL ;
V_70 = V_12 -> V_73 ;
V_12 -> V_73 = V_74 ;
F_13 ( V_12 ) ;
F_48 ( & V_37 -> V_56 ) ;
V_69 = F_6 ( V_12 ) ;
if ( V_69 != NULL ) {
if ( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) {
F_11 ( V_69 ) ;
V_69 -> V_71 = V_72 ;
if ( ! F_46 ( & V_12 -> V_14 ) || V_66 )
V_69 -> V_58 = V_59 ;
F_13 ( V_69 ) ;
V_69 -> V_78 ( V_69 ) ;
F_43 ( V_69 , V_79 , V_80 ) ;
}
F_60 ( V_69 ) ;
F_6 ( V_12 ) = NULL ;
}
while ( ( V_4 = F_61 ( & V_12 -> V_14 ) ) != NULL ) {
if ( V_70 == V_81 )
F_58 ( V_4 -> V_12 , 1 ) ;
F_62 ( V_4 ) ;
}
if ( V_42 ) {
F_63 ( V_42 ) ;
F_64 ( V_68 ) ;
}
F_60 ( V_12 ) ;
if ( V_82 )
F_65 () ;
return 0 ;
}
static void F_66 ( struct V_11 * V_12 )
{
F_67 ( V_12 -> V_83 ) ;
if ( V_12 -> V_84 )
F_68 ( V_12 -> V_84 ) ;
V_12 -> V_83 = F_69 ( F_70 ( V_85 ) ) ;
V_12 -> V_84 = F_71 () ;
}
static void F_72 ( struct V_11 * V_12 , struct V_11 * V_86 )
{
F_67 ( V_12 -> V_83 ) ;
if ( V_12 -> V_84 )
F_68 ( V_12 -> V_84 ) ;
V_12 -> V_83 = F_69 ( V_86 -> V_83 ) ;
V_12 -> V_84 = F_73 ( V_86 -> V_84 ) ;
}
static int F_74 ( struct V_87 * V_11 , int V_88 )
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
F_48 ( & V_37 -> V_56 ) ;
V_12 -> V_15 = V_88 ;
V_12 -> V_73 = V_81 ;
F_66 ( V_12 ) ;
V_89 = 0 ;
V_96:
F_13 ( V_12 ) ;
F_67 ( V_91 ) ;
if ( V_93 )
F_68 ( V_93 ) ;
V_95:
return V_89 ;
}
static struct V_11 * F_75 ( struct V_32 * V_32 , struct V_87 * V_11 )
{
struct V_11 * V_12 = NULL ;
struct V_36 * V_37 ;
F_76 ( & V_63 ) ;
if ( F_57 ( & V_63 ) > 2 * F_77 () )
goto V_95;
V_12 = F_78 ( V_32 , V_97 , V_98 , & V_99 ) ;
if ( ! V_12 )
goto V_95;
F_79 ( V_11 , V_12 ) ;
F_80 ( & V_12 -> V_14 . V_100 ,
& V_101 ) ;
V_12 -> V_102 = F_38 ;
V_12 -> V_15 = V_32 -> V_103 . V_104 ;
V_12 -> V_105 = F_50 ;
V_37 = F_31 ( V_12 ) ;
V_37 -> V_42 = NULL ;
V_37 -> V_68 = NULL ;
F_81 ( & V_37 -> V_100 ) ;
F_82 ( & V_37 -> V_106 , 0 ) ;
F_83 ( & V_37 -> V_107 ) ;
F_84 ( & V_37 -> V_108 ) ;
F_85 ( & V_37 -> V_56 ) ;
F_28 ( V_109 , V_12 ) ;
V_95:
if ( V_12 == NULL )
F_52 ( & V_63 ) ;
else {
F_53 () ;
F_54 ( F_33 ( V_12 ) , V_12 -> V_64 , 1 ) ;
F_55 () ;
}
return V_12 ;
}
static int F_86 ( struct V_32 * V_32 , struct V_87 * V_11 , int V_110 ,
int V_111 )
{
if ( V_110 && V_110 != V_97 )
return - V_112 ;
V_11 -> V_70 = V_113 ;
switch ( V_11 -> type ) {
case V_76 :
V_11 -> V_114 = & V_115 ;
break;
case V_116 :
V_11 -> type = V_117 ;
case V_117 :
V_11 -> V_114 = & V_118 ;
break;
case V_77 :
V_11 -> V_114 = & V_119 ;
break;
default:
return - V_120 ;
}
return F_75 ( V_32 , V_11 ) ? 0 : - V_121 ;
}
static int F_87 ( struct V_87 * V_11 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
if ( ! V_12 )
return 0 ;
V_11 -> V_12 = NULL ;
return F_58 ( V_12 , 0 ) ;
}
static int F_88 ( struct V_87 * V_11 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
static V_6 V_122 = 1 ;
struct V_18 * V_19 ;
int V_89 ;
unsigned int V_123 = 0 ;
F_89 ( & V_37 -> V_108 ) ;
V_89 = 0 ;
if ( V_37 -> V_19 )
goto V_95;
V_89 = - V_121 ;
V_19 = F_90 ( sizeof( * V_19 ) + sizeof( short ) + 16 , V_98 ) ;
if ( ! V_19 )
goto V_95;
V_19 -> V_38 -> V_26 = V_27 ;
F_91 ( & V_19 -> V_20 , 1 ) ;
V_124:
V_19 -> V_23 = sprintf ( V_19 -> V_38 -> V_28 + 1 , L_3 , V_122 ) + 1 + sizeof( short ) ;
V_19 -> V_8 = F_4 ( F_18 ( V_19 -> V_38 , V_19 -> V_23 , 0 ) ) ;
F_26 ( & V_31 ) ;
V_122 = ( V_122 + 1 ) & 0xFFFFF ;
if ( F_29 ( V_32 , V_19 -> V_38 , V_19 -> V_23 , V_11 -> type ,
V_19 -> V_8 ) ) {
F_27 ( & V_31 ) ;
F_92 () ;
if ( V_123 ++ == 0xFFFFF ) {
V_89 = - V_125 ;
F_16 ( V_19 ) ;
goto V_95;
}
goto V_124;
}
V_19 -> V_8 ^= V_12 -> V_75 ;
F_19 ( V_12 ) ;
V_37 -> V_19 = V_19 ;
F_21 ( & V_126 [ V_19 -> V_8 ] , V_12 ) ;
F_27 ( & V_31 ) ;
V_89 = 0 ;
V_95: F_93 ( & V_37 -> V_108 ) ;
return V_89 ;
}
static struct V_11 * F_94 ( struct V_32 * V_32 ,
struct V_21 * V_33 , int V_23 ,
int type , unsigned V_8 , int * error )
{
struct V_11 * V_37 ;
struct V_127 V_127 ;
int V_89 = 0 ;
if ( V_33 -> V_28 [ 0 ] ) {
struct V_40 * V_40 ;
V_89 = F_95 ( V_33 -> V_28 , V_128 , & V_127 ) ;
if ( V_89 )
goto V_129;
V_40 = V_127 . V_42 -> V_43 ;
V_89 = F_96 ( V_40 , V_130 ) ;
if ( V_89 )
goto V_131;
V_89 = - V_132 ;
if ( ! F_97 ( V_40 -> V_133 ) )
goto V_131;
V_37 = F_35 ( V_40 ) ;
if ( ! V_37 )
goto V_131;
if ( V_37 -> V_75 == type )
F_98 ( V_127 . V_68 , V_127 . V_42 ) ;
F_99 ( & V_127 ) ;
V_89 = - V_134 ;
if ( V_37 -> V_75 != type ) {
F_60 ( V_37 ) ;
goto V_129;
}
} else {
V_89 = - V_132 ;
V_37 = F_34 ( V_32 , V_33 , V_23 , type , V_8 ) ;
if ( V_37 ) {
struct V_42 * V_42 ;
V_42 = F_31 ( V_37 ) -> V_42 ;
if ( V_42 )
F_98 ( F_31 ( V_37 ) -> V_68 , V_42 ) ;
} else
goto V_129;
}
return V_37 ;
V_131:
F_99 ( & V_127 ) ;
V_129:
* error = V_89 ;
return NULL ;
}
static int F_100 ( struct V_87 * V_11 , struct V_135 * V_136 , int V_137 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_136 ;
struct V_42 * V_42 = NULL ;
struct V_138 V_139 ;
int V_89 ;
unsigned V_8 ;
struct V_18 * V_19 ;
struct V_29 * V_30 ;
V_89 = - V_25 ;
if ( V_22 -> V_26 != V_27 )
goto V_95;
if ( V_137 == sizeof( short ) ) {
V_89 = F_88 ( V_11 ) ;
goto V_95;
}
V_89 = F_17 ( V_22 , V_137 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_137 = V_89 ;
F_89 ( & V_37 -> V_108 ) ;
V_89 = - V_25 ;
if ( V_37 -> V_19 )
goto V_140;
V_89 = - V_121 ;
V_19 = F_101 ( sizeof( * V_19 ) + V_137 , V_98 ) ;
if ( ! V_19 )
goto V_140;
memcpy ( V_19 -> V_38 , V_22 , V_137 ) ;
V_19 -> V_23 = V_137 ;
V_19 -> V_8 = V_8 ^ V_12 -> V_75 ;
F_91 ( & V_19 -> V_20 , 1 ) ;
if ( V_22 -> V_28 [ 0 ] ) {
unsigned int V_141 ;
V_89 = 0 ;
V_89 = F_102 ( V_22 -> V_28 , & V_139 ) ;
if ( V_89 )
goto V_142;
V_42 = F_103 ( & V_139 , 0 ) ;
V_89 = F_104 ( V_42 ) ;
if ( F_105 ( V_42 ) )
goto V_143;
V_141 = V_144 |
( F_106 ( V_11 ) -> V_133 & ~ F_107 () ) ;
V_89 = F_108 ( V_139 . V_127 . V_68 ) ;
if ( V_89 )
goto V_145;
V_89 = F_109 ( & V_139 . V_127 , V_42 , V_141 , 0 ) ;
if ( V_89 )
goto V_146;
V_89 = F_110 ( V_139 . V_127 . V_42 -> V_43 , V_42 , V_141 , 0 ) ;
V_146:
F_111 ( V_139 . V_127 . V_68 ) ;
if ( V_89 )
goto V_145;
F_93 ( & V_139 . V_127 . V_42 -> V_43 -> V_147 ) ;
F_63 ( V_139 . V_127 . V_42 ) ;
V_139 . V_127 . V_42 = V_42 ;
V_19 -> V_8 = V_10 ;
}
F_26 ( & V_31 ) ;
if ( ! V_22 -> V_28 [ 0 ] ) {
V_89 = - V_148 ;
if ( F_29 ( V_32 , V_22 , V_137 ,
V_12 -> V_75 , V_8 ) ) {
F_14 ( V_19 ) ;
goto V_96;
}
V_30 = & V_126 [ V_19 -> V_8 ] ;
} else {
V_30 = & V_126 [ V_42 -> V_43 -> V_149 & ( V_10 - 1 ) ] ;
V_37 -> V_42 = V_139 . V_127 . V_42 ;
V_37 -> V_68 = V_139 . V_127 . V_68 ;
}
V_89 = 0 ;
F_19 ( V_12 ) ;
V_37 -> V_19 = V_19 ;
F_21 ( V_30 , V_12 ) ;
V_96:
F_27 ( & V_31 ) ;
V_140:
F_93 ( & V_37 -> V_108 ) ;
V_95:
return V_89 ;
V_145:
F_63 ( V_42 ) ;
V_143:
F_93 ( & V_139 . V_127 . V_42 -> V_43 -> V_147 ) ;
F_99 ( & V_139 . V_127 ) ;
V_142:
if ( V_89 == - V_150 )
V_89 = - V_148 ;
F_14 ( V_19 ) ;
goto V_140;
}
static void F_112 ( struct V_11 * V_151 , struct V_11 * V_152 )
{
if ( F_113 ( V_151 == V_152 ) || ! V_152 ) {
F_11 ( V_151 ) ;
return;
}
if ( V_151 < V_152 ) {
F_11 ( V_151 ) ;
F_114 ( V_152 ) ;
} else {
F_11 ( V_152 ) ;
F_114 ( V_151 ) ;
}
}
static void F_115 ( struct V_11 * V_151 , struct V_11 * V_152 )
{
if ( F_113 ( V_151 == V_152 ) || ! V_152 ) {
F_13 ( V_151 ) ;
return;
}
F_13 ( V_151 ) ;
F_13 ( V_152 ) ;
}
static int F_116 ( struct V_87 * V_11 , struct V_135 * V_19 ,
int V_153 , int V_154 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_19 ;
struct V_11 * V_55 ;
unsigned V_8 ;
int V_89 ;
if ( V_19 -> V_155 != V_156 ) {
V_89 = F_17 ( V_22 , V_153 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_153 = V_89 ;
if ( F_117 ( V_157 , & V_11 -> V_154 ) &&
! F_31 ( V_12 ) -> V_19 && ( V_89 = F_88 ( V_11 ) ) != 0 )
goto V_95;
V_158:
V_55 = F_94 ( V_32 , V_22 , V_153 , V_11 -> type , V_8 , & V_89 ) ;
if ( ! V_55 )
goto V_95;
F_112 ( V_12 , V_55 ) ;
if ( F_49 ( V_55 , V_57 ) ) {
F_115 ( V_12 , V_55 ) ;
F_60 ( V_55 ) ;
goto V_158;
}
V_89 = - V_159 ;
if ( ! F_7 ( V_12 , V_55 ) )
goto V_96;
V_89 = F_118 ( V_12 -> V_61 , V_55 -> V_61 ) ;
if ( V_89 )
goto V_96;
} else {
V_55 = NULL ;
F_112 ( V_12 , V_55 ) ;
}
if ( F_6 ( V_12 ) ) {
struct V_11 * V_160 = F_6 ( V_12 ) ;
F_6 ( V_12 ) = V_55 ;
F_115 ( V_12 , V_55 ) ;
if ( V_55 != V_160 )
F_45 ( V_12 , V_160 ) ;
F_60 ( V_160 ) ;
} else {
F_6 ( V_12 ) = V_55 ;
F_115 ( V_12 , V_55 ) ;
}
return 0 ;
V_96:
F_115 ( V_12 , V_55 ) ;
F_60 ( V_55 ) ;
V_95:
return V_89 ;
}
static long F_119 ( struct V_11 * V_55 , long V_161 )
{
struct V_36 * V_37 = F_31 ( V_55 ) ;
int V_162 ;
F_120 ( V_49 ) ;
F_121 ( & V_37 -> V_56 , & V_49 , V_163 ) ;
V_162 = ! F_49 ( V_55 , V_57 ) &&
! ( V_55 -> V_71 & V_164 ) &&
F_8 ( V_55 ) ;
F_13 ( V_55 ) ;
if ( V_162 )
V_161 = F_122 ( V_161 ) ;
F_123 ( & V_37 -> V_56 , & V_49 ) ;
return V_161 ;
}
static int F_124 ( struct V_87 * V_11 , struct V_135 * V_136 ,
int V_137 , int V_154 )
{
struct V_21 * V_22 = (struct V_21 * ) V_136 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) , * V_165 , * V_166 ;
struct V_11 * V_167 = NULL ;
struct V_11 * V_55 = NULL ;
struct V_3 * V_4 = NULL ;
unsigned V_8 ;
int V_168 ;
int V_89 ;
long V_161 ;
V_89 = F_17 ( V_22 , V_137 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_137 = V_89 ;
if ( F_117 ( V_157 , & V_11 -> V_154 ) && ! V_37 -> V_19 &&
( V_89 = F_88 ( V_11 ) ) != 0 )
goto V_95;
V_161 = F_125 ( V_12 , V_154 & V_169 ) ;
V_89 = - V_121 ;
V_167 = F_75 ( F_33 ( V_12 ) , NULL ) ;
if ( V_167 == NULL )
goto V_95;
V_4 = F_126 ( V_167 , 1 , 0 , V_98 ) ;
if ( V_4 == NULL )
goto V_95;
V_158:
V_55 = F_94 ( V_32 , V_22 , V_137 , V_12 -> V_75 , V_8 , & V_89 ) ;
if ( ! V_55 )
goto V_95;
F_11 ( V_55 ) ;
if ( F_49 ( V_55 , V_57 ) ) {
F_13 ( V_55 ) ;
F_60 ( V_55 ) ;
goto V_158;
}
V_89 = - V_132 ;
if ( V_55 -> V_73 != V_81 )
goto V_96;
if ( V_55 -> V_71 & V_164 )
goto V_96;
if ( F_8 ( V_55 ) ) {
V_89 = - V_170 ;
if ( ! V_161 )
goto V_96;
V_161 = F_119 ( V_55 , V_161 ) ;
V_89 = F_127 ( V_161 ) ;
if ( F_128 ( V_85 ) )
goto V_95;
F_60 ( V_55 ) ;
goto V_158;
}
V_168 = V_12 -> V_73 ;
switch ( V_168 ) {
case V_74 :
break;
case V_171 :
V_89 = - V_172 ;
goto V_96;
default:
V_89 = - V_25 ;
goto V_96;
}
F_114 ( V_12 ) ;
if ( V_12 -> V_73 != V_168 ) {
F_13 ( V_12 ) ;
F_13 ( V_55 ) ;
F_60 ( V_55 ) ;
goto V_158;
}
V_89 = F_129 ( V_12 , V_55 , V_167 ) ;
if ( V_89 ) {
F_13 ( V_12 ) ;
goto V_96;
}
F_12 ( V_12 ) ;
F_6 ( V_167 ) = V_12 ;
V_167 -> V_73 = V_171 ;
V_167 -> V_75 = V_12 -> V_75 ;
F_66 ( V_167 ) ;
V_165 = F_31 ( V_167 ) ;
F_130 ( V_167 -> V_48 , & V_165 -> V_173 ) ;
V_166 = F_31 ( V_55 ) ;
if ( V_166 -> V_19 ) {
F_131 ( & V_166 -> V_19 -> V_20 ) ;
V_165 -> V_19 = V_166 -> V_19 ;
}
if ( V_166 -> V_42 ) {
V_165 -> V_42 = F_132 ( V_166 -> V_42 ) ;
V_165 -> V_68 = F_133 ( V_166 -> V_68 ) ;
}
F_72 ( V_12 , V_55 ) ;
V_11 -> V_70 = V_174 ;
V_12 -> V_73 = V_171 ;
F_12 ( V_167 ) ;
F_134 () ;
F_6 ( V_12 ) = V_167 ;
F_13 ( V_12 ) ;
F_26 ( & V_55 -> V_14 . V_100 ) ;
F_135 ( & V_55 -> V_14 , V_4 ) ;
F_27 ( & V_55 -> V_14 . V_100 ) ;
F_13 ( V_55 ) ;
V_55 -> V_175 ( V_55 , 0 ) ;
F_60 ( V_55 ) ;
return 0 ;
V_96:
if ( V_55 )
F_13 ( V_55 ) ;
V_95:
F_62 ( V_4 ) ;
if ( V_167 )
F_58 ( V_167 , 0 ) ;
if ( V_55 )
F_60 ( V_55 ) ;
return V_89 ;
}
static int F_136 ( struct V_87 * V_176 , struct V_87 * V_177 )
{
struct V_11 * V_178 = V_176 -> V_12 , * V_4 = V_177 -> V_12 ;
F_12 ( V_178 ) ;
F_12 ( V_4 ) ;
F_6 ( V_178 ) = V_4 ;
F_6 ( V_4 ) = V_178 ;
F_66 ( V_178 ) ;
F_66 ( V_4 ) ;
if ( V_178 -> V_75 != V_117 ) {
V_178 -> V_73 = V_171 ;
V_4 -> V_73 = V_171 ;
V_176 -> V_70 = V_174 ;
V_177 -> V_70 = V_174 ;
}
return 0 ;
}
static int F_137 ( struct V_87 * V_11 , struct V_87 * V_179 , int V_154 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_180 ;
struct V_3 * V_4 ;
int V_89 ;
V_89 = - V_94 ;
if ( V_11 -> type != V_76 && V_11 -> type != V_77 )
goto V_95;
V_89 = - V_25 ;
if ( V_12 -> V_73 != V_81 )
goto V_95;
V_4 = F_138 ( V_12 , 0 , V_154 & V_169 , & V_89 ) ;
if ( ! V_4 ) {
if ( V_89 == 0 )
V_89 = - V_25 ;
goto V_95;
}
V_180 = V_4 -> V_12 ;
F_139 ( V_12 , V_4 ) ;
F_140 ( & F_31 ( V_12 ) -> V_56 ) ;
F_11 ( V_180 ) ;
V_179 -> V_70 = V_174 ;
F_141 ( V_180 , V_179 ) ;
F_13 ( V_180 ) ;
return 0 ;
V_95:
return V_89 ;
}
static int F_142 ( struct V_87 * V_11 , struct V_135 * V_136 , int * V_181 , int V_17 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 ;
F_143 ( struct V_21 * , V_22 , V_136 ) ;
int V_89 = 0 ;
if ( V_17 ) {
V_12 = F_10 ( V_12 ) ;
V_89 = - V_182 ;
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
* V_181 = sizeof( short ) ;
} else {
struct V_18 * V_19 = V_37 -> V_19 ;
* V_181 = V_19 -> V_23 ;
memcpy ( V_22 , V_19 -> V_38 , * V_181 ) ;
}
F_13 ( V_12 ) ;
F_60 ( V_12 ) ;
V_95:
return V_89 ;
}
static void F_144 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_41 ;
V_2 -> V_183 = F_145 ( V_4 ) . V_183 ;
F_145 ( V_4 ) . V_183 = NULL ;
for ( V_41 = V_2 -> V_183 -> V_184 - 1 ; V_41 >= 0 ; V_41 -- )
F_146 ( V_2 -> V_183 -> V_183 [ V_41 ] ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_90 = F_145 ( V_4 ) . V_90 ;
V_2 . V_92 = F_145 ( V_4 ) . V_92 ;
if ( F_145 ( V_4 ) . V_183 )
F_144 ( & V_2 , V_4 ) ;
F_148 ( & V_2 ) ;
F_149 ( V_4 ) ;
}
static int F_150 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_41 ;
unsigned char V_185 = 0 ;
int V_186 = 0 ;
for ( V_41 = V_2 -> V_183 -> V_184 - 1 ; V_41 >= 0 ; V_41 -- ) {
struct V_11 * V_12 = F_151 ( V_2 -> V_183 -> V_183 [ V_41 ] ) ;
if ( V_12 ) {
V_186 ++ ;
V_185 = F_152 ( V_185 ,
F_31 ( V_12 ) -> V_187 ) ;
}
}
if ( F_113 ( V_185 > V_188 ) )
return - V_189 ;
F_145 ( V_4 ) . V_183 = F_153 ( V_2 -> V_183 ) ;
if ( ! F_145 ( V_4 ) . V_183 )
return - V_121 ;
if ( V_186 ) {
for ( V_41 = V_2 -> V_183 -> V_184 - 1 ; V_41 >= 0 ; V_41 -- )
F_154 ( V_2 -> V_183 -> V_183 [ V_41 ] ) ;
}
return V_185 ;
}
static int F_155 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_190 )
{
int V_89 = 0 ;
F_145 ( V_4 ) . V_90 = F_69 ( V_2 -> V_90 ) ;
F_145 ( V_4 ) . V_92 = F_73 ( V_2 -> V_92 ) ;
F_145 ( V_4 ) . V_183 = NULL ;
if ( V_2 -> V_183 && V_190 )
V_89 = F_150 ( V_2 , V_4 ) ;
V_4 -> V_191 = F_147 ;
return V_89 ;
}
static int F_156 ( struct V_192 * V_192 , struct V_87 * V_11 ,
struct V_193 * V_194 , T_2 V_23 )
{
struct V_195 * V_196 = F_157 ( V_192 ) ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = V_194 -> V_197 ;
struct V_11 * V_55 = NULL ;
int V_198 = 0 ;
int V_89 ;
unsigned V_8 ;
struct V_3 * V_4 ;
long V_161 ;
struct V_1 V_199 ;
int V_185 ;
if ( NULL == V_196 -> V_2 )
V_196 -> V_2 = & V_199 ;
F_158 () ;
V_89 = F_159 ( V_11 , V_194 , V_196 -> V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = - V_94 ;
if ( V_194 -> V_200 & V_201 )
goto V_95;
if ( V_194 -> V_202 ) {
V_89 = F_17 ( V_22 , V_194 -> V_202 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_198 = V_89 ;
} else {
V_22 = NULL ;
V_89 = - V_182 ;
V_55 = F_10 ( V_12 ) ;
if ( ! V_55 )
goto V_95;
}
if ( F_117 ( V_157 , & V_11 -> V_154 ) && ! V_37 -> V_19
&& ( V_89 = F_88 ( V_11 ) ) != 0 )
goto V_95;
V_89 = - V_203 ;
if ( V_23 > V_12 -> V_45 - 32 )
goto V_95;
V_4 = F_160 ( V_12 , V_23 , V_194 -> V_200 & V_204 , & V_89 ) ;
if ( V_4 == NULL )
goto V_95;
V_89 = F_155 ( V_196 -> V_2 , V_4 , true ) ;
if ( V_89 < 0 )
goto V_205;
V_185 = V_89 + 1 ;
F_1 ( V_196 -> V_2 , V_4 ) ;
F_161 ( V_4 ) ;
V_89 = F_162 ( F_163 ( V_4 , V_23 ) , V_194 -> V_206 , V_23 ) ;
if ( V_89 )
goto V_205;
V_161 = F_125 ( V_12 , V_194 -> V_200 & V_204 ) ;
V_158:
if ( ! V_55 ) {
V_89 = - V_59 ;
if ( V_22 == NULL )
goto V_205;
V_55 = F_94 ( V_32 , V_22 , V_198 , V_12 -> V_75 ,
V_8 , & V_89 ) ;
if ( V_55 == NULL )
goto V_205;
}
if ( F_164 ( V_55 , V_4 ) < 0 ) {
V_89 = V_23 ;
goto V_205;
}
F_11 ( V_55 ) ;
V_89 = - V_159 ;
if ( ! F_7 ( V_12 , V_55 ) )
goto V_96;
if ( F_49 ( V_55 , V_57 ) ) {
F_13 ( V_55 ) ;
F_60 ( V_55 ) ;
V_89 = 0 ;
F_11 ( V_12 ) ;
if ( F_6 ( V_12 ) == V_55 ) {
F_6 ( V_12 ) = NULL ;
F_13 ( V_12 ) ;
F_45 ( V_12 , V_55 ) ;
F_60 ( V_55 ) ;
V_89 = - V_132 ;
} else {
F_13 ( V_12 ) ;
}
V_55 = NULL ;
if ( V_89 )
goto V_205;
goto V_158;
}
V_89 = - V_207 ;
if ( V_55 -> V_71 & V_164 )
goto V_96;
if ( V_12 -> V_75 != V_77 ) {
V_89 = F_118 ( V_12 -> V_61 , V_55 -> V_61 ) ;
if ( V_89 )
goto V_96;
}
if ( F_6 ( V_55 ) != V_12 && F_8 ( V_55 ) ) {
if ( ! V_161 ) {
V_89 = - V_170 ;
goto V_96;
}
V_161 = F_119 ( V_55 , V_161 ) ;
V_89 = F_127 ( V_161 ) ;
if ( F_128 ( V_85 ) )
goto V_205;
goto V_158;
}
if ( F_49 ( V_55 , V_208 ) )
F_165 ( V_4 ) ;
F_166 ( & V_55 -> V_14 , V_4 ) ;
if ( V_185 > F_31 ( V_55 ) -> V_187 )
F_31 ( V_55 ) -> V_187 = V_185 ;
F_13 ( V_55 ) ;
V_55 -> V_175 ( V_55 , V_23 ) ;
F_60 ( V_55 ) ;
F_148 ( V_196 -> V_2 ) ;
return V_23 ;
V_96:
F_13 ( V_55 ) ;
V_205:
F_62 ( V_4 ) ;
V_95:
if ( V_55 )
F_60 ( V_55 ) ;
F_148 ( V_196 -> V_2 ) ;
return V_89 ;
}
static int F_167 ( struct V_192 * V_192 , struct V_87 * V_11 ,
struct V_193 * V_194 , T_2 V_23 )
{
struct V_195 * V_196 = F_157 ( V_192 ) ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_55 = NULL ;
int V_89 , V_209 ;
struct V_3 * V_4 ;
int V_210 = 0 ;
struct V_1 V_199 ;
bool V_211 = false ;
int V_185 ;
if ( NULL == V_196 -> V_2 )
V_196 -> V_2 = & V_199 ;
F_158 () ;
V_89 = F_159 ( V_11 , V_194 , V_196 -> V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = - V_94 ;
if ( V_194 -> V_200 & V_201 )
goto V_212;
if ( V_194 -> V_202 ) {
V_89 = V_12 -> V_73 == V_171 ? - V_172 : - V_94 ;
goto V_212;
} else {
V_89 = - V_182 ;
V_55 = F_6 ( V_12 ) ;
if ( ! V_55 )
goto V_212;
}
if ( V_12 -> V_71 & V_213 )
goto V_214;
while ( V_210 < V_23 ) {
V_209 = V_23 - V_210 ;
if ( V_209 > ( ( V_12 -> V_45 >> 1 ) - 64 ) )
V_209 = ( V_12 -> V_45 >> 1 ) - 64 ;
if ( V_209 > V_215 )
V_209 = V_215 ;
V_4 = F_160 ( V_12 , V_209 , V_194 -> V_200 & V_204 ,
& V_89 ) ;
if ( V_4 == NULL )
goto V_212;
V_209 = F_168 ( int , V_209 , F_169 ( V_4 ) ) ;
V_89 = F_155 ( V_196 -> V_2 , V_4 , ! V_211 ) ;
if ( V_89 < 0 ) {
F_62 ( V_4 ) ;
goto V_212;
}
V_185 = V_89 + 1 ;
V_211 = true ;
V_89 = F_162 ( F_163 ( V_4 , V_209 ) , V_194 -> V_206 , V_209 ) ;
if ( V_89 ) {
F_62 ( V_4 ) ;
goto V_212;
}
F_11 ( V_55 ) ;
if ( F_49 ( V_55 , V_57 ) ||
( V_55 -> V_71 & V_164 ) )
goto V_216;
F_166 ( & V_55 -> V_14 , V_4 ) ;
if ( V_185 > F_31 ( V_55 ) -> V_187 )
F_31 ( V_55 ) -> V_187 = V_185 ;
F_13 ( V_55 ) ;
V_55 -> V_175 ( V_55 , V_209 ) ;
V_210 += V_209 ;
}
F_148 ( V_196 -> V_2 ) ;
V_196 -> V_2 = NULL ;
return V_210 ;
V_216:
F_13 ( V_55 ) ;
F_62 ( V_4 ) ;
V_214:
if ( V_210 == 0 && ! ( V_194 -> V_200 & V_217 ) )
F_170 ( V_218 , V_85 , 0 ) ;
V_89 = - V_207 ;
V_212:
F_148 ( V_196 -> V_2 ) ;
V_196 -> V_2 = NULL ;
return V_210 ? : V_89 ;
}
static int F_171 ( struct V_192 * V_192 , struct V_87 * V_11 ,
struct V_193 * V_194 , T_2 V_23 )
{
int V_89 ;
struct V_11 * V_12 = V_11 -> V_12 ;
V_89 = F_172 ( V_12 ) ;
if ( V_89 )
return V_89 ;
if ( V_12 -> V_73 != V_171 )
return - V_182 ;
if ( V_194 -> V_202 )
V_194 -> V_202 = 0 ;
return F_156 ( V_192 , V_11 , V_194 , V_23 ) ;
}
static int F_173 ( struct V_192 * V_219 , struct V_87 * V_11 ,
struct V_193 * V_194 , T_2 V_209 ,
int V_154 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
if ( V_12 -> V_73 != V_171 )
return - V_182 ;
return F_174 ( V_219 , V_11 , V_194 , V_209 , V_154 ) ;
}
static void F_175 ( struct V_193 * V_194 , struct V_11 * V_12 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
V_194 -> V_202 = 0 ;
if ( V_37 -> V_19 ) {
V_194 -> V_202 = V_37 -> V_19 -> V_23 ;
memcpy ( V_194 -> V_197 , V_37 -> V_19 -> V_38 , V_37 -> V_19 -> V_23 ) ;
}
}
static int F_174 ( struct V_192 * V_219 , struct V_87 * V_11 ,
struct V_193 * V_194 , T_2 V_209 ,
int V_154 )
{
struct V_195 * V_196 = F_157 ( V_219 ) ;
struct V_1 V_199 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
int V_220 = V_154 & V_204 ;
struct V_3 * V_4 ;
int V_89 ;
V_89 = - V_94 ;
if ( V_154 & V_201 )
goto V_95;
V_194 -> V_202 = 0 ;
V_89 = F_176 ( & V_37 -> V_108 ) ;
if ( V_89 ) {
V_89 = F_127 ( F_177 ( V_12 , V_220 ) ) ;
goto V_95;
}
V_4 = F_138 ( V_12 , V_154 , V_220 , & V_89 ) ;
if ( ! V_4 ) {
F_11 ( V_12 ) ;
if ( V_12 -> V_75 == V_77 && V_89 == - V_170 &&
( V_12 -> V_71 & V_164 ) )
V_89 = 0 ;
F_13 ( V_12 ) ;
goto V_96;
}
F_42 ( & V_37 -> V_56 ,
V_50 | V_51 | V_52 ) ;
if ( V_194 -> V_197 )
F_175 ( V_194 , V_4 -> V_12 ) ;
if ( V_209 > V_4 -> V_23 )
V_209 = V_4 -> V_23 ;
else if ( V_209 < V_4 -> V_23 )
V_194 -> V_200 |= V_221 ;
V_89 = F_178 ( V_4 , 0 , V_194 -> V_206 , V_209 ) ;
if ( V_89 )
goto V_205;
if ( F_49 ( V_12 , V_208 ) )
F_179 ( V_194 , V_12 , V_4 ) ;
if ( ! V_196 -> V_2 ) {
V_196 -> V_2 = & V_199 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
}
F_180 ( V_196 -> V_2 , F_145 ( V_4 ) . V_90 , F_145 ( V_4 ) . V_92 ) ;
F_3 ( V_196 -> V_2 , V_4 ) ;
if ( ! ( V_154 & V_222 ) ) {
if ( F_145 ( V_4 ) . V_183 )
F_144 ( V_196 -> V_2 , V_4 ) ;
} else {
if ( F_145 ( V_4 ) . V_183 )
V_196 -> V_2 -> V_183 = F_153 ( F_145 ( V_4 ) . V_183 ) ;
}
V_89 = V_209 ;
F_181 ( V_11 , V_194 , V_196 -> V_2 , V_154 ) ;
V_205:
F_139 ( V_12 , V_4 ) ;
V_96:
F_93 ( & V_37 -> V_108 ) ;
V_95:
return V_89 ;
}
static long F_182 ( struct V_11 * V_12 , long V_161 )
{
F_120 ( V_49 ) ;
F_11 ( V_12 ) ;
for (; ; ) {
F_183 ( F_184 ( V_12 ) , & V_49 , V_163 ) ;
if ( ! F_46 ( & V_12 -> V_14 ) ||
V_12 -> V_58 ||
( V_12 -> V_71 & V_164 ) ||
F_128 ( V_85 ) ||
! V_161 )
break;
F_185 ( V_223 , & V_12 -> V_61 -> V_154 ) ;
F_13 ( V_12 ) ;
V_161 = F_122 ( V_161 ) ;
F_11 ( V_12 ) ;
F_186 ( V_223 , & V_12 -> V_61 -> V_154 ) ;
}
F_123 ( F_184 ( V_12 ) , & V_49 ) ;
F_13 ( V_12 ) ;
return V_161 ;
}
static int F_187 ( struct V_192 * V_219 , struct V_87 * V_11 ,
struct V_193 * V_194 , T_2 V_209 ,
int V_154 )
{
struct V_195 * V_196 = F_157 ( V_219 ) ;
struct V_1 V_199 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = V_194 -> V_197 ;
int V_224 = 0 ;
int V_225 = 0 ;
int V_226 ;
int V_89 = 0 ;
long V_161 ;
V_89 = - V_25 ;
if ( V_12 -> V_73 != V_171 )
goto V_95;
V_89 = - V_94 ;
if ( V_154 & V_201 )
goto V_95;
V_226 = F_188 ( V_12 , V_154 & V_227 , V_209 ) ;
V_161 = F_177 ( V_12 , V_154 & V_204 ) ;
V_194 -> V_202 = 0 ;
if ( ! V_196 -> V_2 ) {
V_196 -> V_2 = & V_199 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
}
V_89 = F_176 ( & V_37 -> V_108 ) ;
if ( V_89 ) {
V_89 = F_127 ( V_161 ) ;
goto V_95;
}
do {
int V_228 ;
struct V_3 * V_4 ;
F_11 ( V_12 ) ;
V_4 = F_61 ( & V_12 -> V_14 ) ;
if ( V_4 == NULL ) {
F_31 ( V_12 ) -> V_187 = 0 ;
if ( V_224 >= V_226 )
goto V_229;
V_89 = F_172 ( V_12 ) ;
if ( V_89 )
goto V_229;
if ( V_12 -> V_71 & V_164 )
goto V_229;
F_13 ( V_12 ) ;
V_89 = - V_170 ;
if ( ! V_161 )
break;
F_93 ( & V_37 -> V_108 ) ;
V_161 = F_182 ( V_12 , V_161 ) ;
if ( F_128 ( V_85 )
|| F_176 ( & V_37 -> V_108 ) ) {
V_89 = F_127 ( V_161 ) ;
goto V_95;
}
continue;
V_229:
F_13 ( V_12 ) ;
break;
}
F_13 ( V_12 ) ;
if ( V_225 ) {
if ( ( F_145 ( V_4 ) . V_90 != V_196 -> V_2 -> V_90 ) ||
( F_145 ( V_4 ) . V_92 != V_196 -> V_2 -> V_92 ) ) {
F_189 ( & V_12 -> V_14 , V_4 ) ;
break;
}
} else {
F_180 ( V_196 -> V_2 , F_145 ( V_4 ) . V_90 , F_145 ( V_4 ) . V_92 ) ;
V_225 = 1 ;
}
if ( V_22 ) {
F_175 ( V_194 , V_4 -> V_12 ) ;
V_22 = NULL ;
}
V_228 = F_168 (unsigned int, skb->len, size) ;
if ( F_190 ( V_194 -> V_206 , V_4 -> V_230 , V_228 ) ) {
F_189 ( & V_12 -> V_14 , V_4 ) ;
if ( V_224 == 0 )
V_224 = - V_231 ;
break;
}
V_224 += V_228 ;
V_209 -= V_228 ;
if ( ! ( V_154 & V_222 ) ) {
F_191 ( V_4 , V_228 ) ;
if ( F_145 ( V_4 ) . V_183 )
F_144 ( V_196 -> V_2 , V_4 ) ;
if ( V_4 -> V_23 ) {
F_189 ( & V_12 -> V_14 , V_4 ) ;
break;
}
F_192 ( V_4 ) ;
if ( V_196 -> V_2 -> V_183 )
break;
} else {
if ( F_145 ( V_4 ) . V_183 )
V_196 -> V_2 -> V_183 = F_153 ( F_145 ( V_4 ) . V_183 ) ;
F_189 ( & V_12 -> V_14 , V_4 ) ;
break;
}
} while ( V_209 );
F_93 ( & V_37 -> V_108 ) ;
F_181 ( V_11 , V_194 , V_196 -> V_2 , V_154 ) ;
V_95:
return V_224 ? : V_89 ;
}
static int F_193 ( struct V_87 * V_11 , int V_141 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_55 ;
V_141 = ( V_141 + 1 ) & ( V_164 | V_213 ) ;
if ( ! V_141 )
return 0 ;
F_11 ( V_12 ) ;
V_12 -> V_71 |= V_141 ;
V_55 = F_6 ( V_12 ) ;
if ( V_55 )
F_12 ( V_55 ) ;
F_13 ( V_12 ) ;
V_12 -> V_78 ( V_12 ) ;
if ( V_55 &&
( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) ) {
int V_232 = 0 ;
if ( V_141 & V_164 )
V_232 |= V_213 ;
if ( V_141 & V_213 )
V_232 |= V_164 ;
F_11 ( V_55 ) ;
V_55 -> V_71 |= V_232 ;
F_13 ( V_55 ) ;
V_55 -> V_78 ( V_55 ) ;
if ( V_232 == V_72 )
F_43 ( V_55 , V_79 , V_80 ) ;
else if ( V_232 & V_164 )
F_43 ( V_55 , V_79 , V_233 ) ;
}
if ( V_55 )
F_60 ( V_55 ) ;
return 0 ;
}
static int F_194 ( struct V_87 * V_11 , unsigned int V_234 , unsigned long V_235 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
long V_236 = 0 ;
int V_89 ;
switch ( V_234 ) {
case V_237 :
V_236 = F_195 ( V_12 ) ;
V_89 = F_196 ( V_236 , ( int V_238 * ) V_235 ) ;
break;
case V_239 :
{
struct V_3 * V_4 ;
if ( V_12 -> V_73 == V_81 ) {
V_89 = - V_25 ;
break;
}
F_26 ( & V_12 -> V_14 . V_100 ) ;
if ( V_12 -> V_75 == V_76 ||
V_12 -> V_75 == V_77 ) {
F_197 (&sk->sk_receive_queue, skb)
V_236 += V_4 -> V_23 ;
} else {
V_4 = F_198 ( & V_12 -> V_14 ) ;
if ( V_4 )
V_236 = V_4 -> V_23 ;
}
F_27 ( & V_12 -> V_14 . V_100 ) ;
V_89 = F_196 ( V_236 , ( int V_238 * ) V_235 ) ;
break;
}
default:
V_89 = - V_240 ;
break;
}
return V_89 ;
}
static unsigned int F_199 ( struct V_241 * V_241 , struct V_87 * V_11 , T_3 * V_49 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
unsigned int V_242 ;
F_200 ( V_241 , F_184 ( V_12 ) , V_49 ) ;
V_242 = 0 ;
if ( V_12 -> V_58 )
V_242 |= V_243 ;
if ( V_12 -> V_71 == V_72 )
V_242 |= V_244 ;
if ( V_12 -> V_71 & V_164 )
V_242 |= V_245 | V_246 | V_247 ;
if ( ! F_46 ( & V_12 -> V_14 ) )
V_242 |= V_246 | V_247 ;
if ( ( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) &&
V_12 -> V_73 == V_74 )
V_242 |= V_244 ;
if ( F_36 ( V_12 ) )
V_242 |= V_50 | V_51 | V_52 ;
return V_242 ;
}
static unsigned int F_201 ( struct V_241 * V_241 , struct V_87 * V_11 ,
T_3 * V_49 )
{
struct V_11 * V_12 = V_11 -> V_12 , * V_55 ;
unsigned int V_242 , V_248 ;
F_200 ( V_241 , F_184 ( V_12 ) , V_49 ) ;
V_242 = 0 ;
if ( V_12 -> V_58 || ! F_46 ( & V_12 -> V_249 ) )
V_242 |= V_243 ;
if ( V_12 -> V_71 & V_164 )
V_242 |= V_245 | V_246 | V_247 ;
if ( V_12 -> V_71 == V_72 )
V_242 |= V_244 ;
if ( ! F_46 ( & V_12 -> V_14 ) )
V_242 |= V_246 | V_247 ;
if ( V_12 -> V_75 == V_77 ) {
if ( V_12 -> V_73 == V_74 )
V_242 |= V_244 ;
if ( V_12 -> V_73 == V_250 )
return V_242 ;
}
if ( V_49 && ! ( V_49 -> V_251 & ( V_52 | V_51 | V_50 ) ) )
return V_242 ;
V_248 = F_36 ( V_12 ) ;
V_55 = F_10 ( V_12 ) ;
if ( V_55 ) {
if ( F_6 ( V_55 ) != V_12 ) {
F_200 ( V_241 , & F_31 ( V_55 ) -> V_56 , V_49 ) ;
if ( F_8 ( V_55 ) )
V_248 = 0 ;
}
F_60 ( V_55 ) ;
}
if ( V_248 )
V_242 |= V_50 | V_51 | V_52 ;
else
F_185 ( V_252 , & V_12 -> V_61 -> V_154 ) ;
return V_242 ;
}
static struct V_11 * F_202 ( int * V_41 )
{
for ( * V_41 = 0 ; * V_41 <= V_10 ; ( * V_41 ) ++ ) {
if ( ! F_203 ( & V_126 [ * V_41 ] ) )
return F_204 ( & V_126 [ * V_41 ] ) ;
}
return NULL ;
}
static struct V_11 * F_205 ( int * V_41 , struct V_11 * V_16 )
{
struct V_11 * V_253 = F_206 ( V_16 ) ;
if ( V_253 )
return V_253 ;
for ( ( * V_41 ) ++ ; * V_41 <= V_10 ; ( * V_41 ) ++ ) {
if ( ! F_203 ( & V_126 [ * V_41 ] ) )
return F_204 ( & V_126 [ * V_41 ] ) ;
}
return NULL ;
}
static struct V_11 * F_207 ( struct V_254 * V_255 , T_4 V_256 )
{
struct V_257 * V_258 = V_255 -> V_259 ;
T_4 V_260 = 0 ;
struct V_11 * V_16 ;
for ( V_16 = F_202 ( & V_258 -> V_41 ) ; V_16 ; V_16 = F_205 ( & V_258 -> V_41 , V_16 ) ) {
if ( F_33 ( V_16 ) != F_208 ( V_255 ) )
continue;
if ( V_260 == V_256 )
return V_16 ;
++ V_260 ;
}
return NULL ;
}
static void * F_209 ( struct V_254 * V_255 , T_4 * V_256 )
__acquires( V_31 )
{
F_26 ( & V_31 ) ;
return * V_256 ? F_207 ( V_255 , * V_256 - 1 ) : V_261 ;
}
static void * F_210 ( struct V_254 * V_255 , void * V_262 , T_4 * V_256 )
{
struct V_257 * V_258 = V_255 -> V_259 ;
struct V_11 * V_12 = V_262 ;
++ * V_256 ;
if ( V_262 == V_261 )
V_12 = F_202 ( & V_258 -> V_41 ) ;
else
V_12 = F_205 ( & V_258 -> V_41 , V_12 ) ;
while ( V_12 && ( F_33 ( V_12 ) != F_208 ( V_255 ) ) )
V_12 = F_205 ( & V_258 -> V_41 , V_12 ) ;
return V_12 ;
}
static void F_211 ( struct V_254 * V_255 , void * V_262 )
__releases( V_31 )
{
F_27 ( & V_31 ) ;
}
static int F_212 ( struct V_254 * V_255 , void * V_262 )
{
if ( V_262 == V_261 )
F_213 ( V_255 , L_4
L_5 ) ;
else {
struct V_11 * V_16 = V_262 ;
struct V_36 * V_37 = F_31 ( V_16 ) ;
F_11 ( V_16 ) ;
F_214 ( V_255 , L_6 ,
V_16 ,
F_37 ( & V_16 -> V_263 ) ,
0 ,
V_16 -> V_73 == V_81 ? V_264 : 0 ,
V_16 -> V_75 ,
V_16 -> V_61 ?
( V_16 -> V_73 == V_171 ? V_174 : V_113 ) :
( V_16 -> V_73 == V_171 ? V_265 : V_266 ) ,
F_215 ( V_16 ) ) ;
if ( V_37 -> V_19 ) {
int V_41 , V_23 ;
F_216 ( V_255 , ' ' ) ;
V_41 = 0 ;
V_23 = V_37 -> V_19 -> V_23 - sizeof( short ) ;
if ( ! F_217 ( V_16 ) )
V_23 -- ;
else {
F_216 ( V_255 , '@' ) ;
V_41 ++ ;
}
for ( ; V_41 < V_23 ; V_41 ++ )
F_216 ( V_255 , V_37 -> V_19 -> V_38 -> V_28 [ V_41 ] ) ;
}
F_13 ( V_16 ) ;
F_216 ( V_255 , '\n' ) ;
}
return 0 ;
}
static int F_218 ( struct V_40 * V_40 , struct V_241 * V_241 )
{
return F_219 ( V_40 , V_241 , & V_267 ,
sizeof( struct V_257 ) ) ;
}
static int T_5 F_220 ( struct V_32 * V_32 )
{
int error = - V_121 ;
V_32 -> V_103 . V_104 = 10 ;
if ( F_221 ( V_32 ) )
goto V_95;
#ifdef F_222
if ( ! F_223 ( V_32 , L_7 , 0 , & V_268 ) ) {
F_224 ( V_32 ) ;
goto V_95;
}
#endif
error = 0 ;
V_95:
return error ;
}
static void T_6 F_225 ( struct V_32 * V_32 )
{
F_224 ( V_32 ) ;
F_226 ( V_32 , L_7 ) ;
}
static int T_7 F_227 ( void )
{
int V_269 = - 1 ;
struct V_3 * V_270 ;
F_228 ( sizeof( struct V_271 ) > sizeof( V_270 -> V_272 ) ) ;
V_269 = F_229 ( & V_99 , 1 ) ;
if ( V_269 != 0 ) {
F_51 ( V_273 L_8 ,
V_274 ) ;
goto V_95;
}
F_230 ( & V_275 ) ;
F_231 ( & V_276 ) ;
V_95:
return V_269 ;
}
static void T_8 F_232 ( void )
{
F_233 ( V_97 ) ;
F_234 ( & V_99 ) ;
F_235 ( & V_276 ) ;
}
