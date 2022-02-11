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
char * V_28 = V_22 -> V_28 ;
struct V_42 * V_42 = NULL ;
struct V_127 V_127 ;
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
goto V_138;
V_89 = - V_121 ;
V_19 = F_101 ( sizeof( * V_19 ) + V_137 , V_98 ) ;
if ( ! V_19 )
goto V_138;
memcpy ( V_19 -> V_38 , V_22 , V_137 ) ;
V_19 -> V_23 = V_137 ;
V_19 -> V_8 = V_8 ^ V_12 -> V_75 ;
F_91 ( & V_19 -> V_20 , 1 ) ;
if ( V_28 [ 0 ] ) {
T_2 V_139 ;
V_89 = 0 ;
V_42 = F_102 ( V_140 , V_28 , & V_127 , 0 ) ;
V_89 = F_103 ( V_42 ) ;
if ( F_104 ( V_42 ) )
goto V_141;
V_139 = V_142 |
( F_105 ( V_11 ) -> V_133 & ~ F_106 () ) ;
V_89 = F_107 ( V_127 . V_68 ) ;
if ( V_89 )
goto V_143;
V_89 = F_108 ( & V_127 , V_42 , V_139 , 0 ) ;
if ( V_89 )
goto V_144;
V_89 = F_109 ( V_127 . V_42 -> V_43 , V_42 , V_139 , 0 ) ;
V_144:
F_110 ( V_127 . V_68 ) ;
if ( V_89 )
goto V_143;
F_93 ( & V_127 . V_42 -> V_43 -> V_145 ) ;
F_63 ( V_127 . V_42 ) ;
V_127 . V_42 = V_42 ;
V_19 -> V_8 = V_10 ;
}
F_26 ( & V_31 ) ;
if ( ! V_28 [ 0 ] ) {
V_89 = - V_146 ;
if ( F_29 ( V_32 , V_22 , V_137 ,
V_12 -> V_75 , V_8 ) ) {
F_14 ( V_19 ) ;
goto V_96;
}
V_30 = & V_126 [ V_19 -> V_8 ] ;
} else {
V_30 = & V_126 [ V_42 -> V_43 -> V_147 & ( V_10 - 1 ) ] ;
V_37 -> V_42 = V_127 . V_42 ;
V_37 -> V_68 = V_127 . V_68 ;
}
V_89 = 0 ;
F_19 ( V_12 ) ;
V_37 -> V_19 = V_19 ;
F_21 ( V_30 , V_12 ) ;
V_96:
F_27 ( & V_31 ) ;
V_138:
F_93 ( & V_37 -> V_108 ) ;
V_95:
return V_89 ;
V_143:
F_63 ( V_42 ) ;
F_93 ( & V_127 . V_42 -> V_43 -> V_145 ) ;
F_99 ( & V_127 ) ;
V_141:
if ( V_89 == - V_148 )
V_89 = - V_146 ;
F_14 ( V_19 ) ;
goto V_138;
}
static void F_111 ( struct V_11 * V_149 , struct V_11 * V_150 )
{
if ( F_112 ( V_149 == V_150 ) || ! V_150 ) {
F_11 ( V_149 ) ;
return;
}
if ( V_149 < V_150 ) {
F_11 ( V_149 ) ;
F_113 ( V_150 ) ;
} else {
F_11 ( V_150 ) ;
F_113 ( V_149 ) ;
}
}
static void F_114 ( struct V_11 * V_149 , struct V_11 * V_150 )
{
if ( F_112 ( V_149 == V_150 ) || ! V_150 ) {
F_13 ( V_149 ) ;
return;
}
F_13 ( V_149 ) ;
F_13 ( V_150 ) ;
}
static int F_115 ( struct V_87 * V_11 , struct V_135 * V_19 ,
int V_151 , int V_152 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_19 ;
struct V_11 * V_55 ;
unsigned V_8 ;
int V_89 ;
if ( V_19 -> V_153 != V_154 ) {
V_89 = F_17 ( V_22 , V_151 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_151 = V_89 ;
if ( F_116 ( V_155 , & V_11 -> V_152 ) &&
! F_31 ( V_12 ) -> V_19 && ( V_89 = F_88 ( V_11 ) ) != 0 )
goto V_95;
V_156:
V_55 = F_94 ( V_32 , V_22 , V_151 , V_11 -> type , V_8 , & V_89 ) ;
if ( ! V_55 )
goto V_95;
F_111 ( V_12 , V_55 ) ;
if ( F_49 ( V_55 , V_57 ) ) {
F_114 ( V_12 , V_55 ) ;
F_60 ( V_55 ) ;
goto V_156;
}
V_89 = - V_157 ;
if ( ! F_7 ( V_12 , V_55 ) )
goto V_96;
V_89 = F_117 ( V_12 -> V_61 , V_55 -> V_61 ) ;
if ( V_89 )
goto V_96;
} else {
V_55 = NULL ;
F_111 ( V_12 , V_55 ) ;
}
if ( F_6 ( V_12 ) ) {
struct V_11 * V_158 = F_6 ( V_12 ) ;
F_6 ( V_12 ) = V_55 ;
F_114 ( V_12 , V_55 ) ;
if ( V_55 != V_158 )
F_45 ( V_12 , V_158 ) ;
F_60 ( V_158 ) ;
} else {
F_6 ( V_12 ) = V_55 ;
F_114 ( V_12 , V_55 ) ;
}
return 0 ;
V_96:
F_114 ( V_12 , V_55 ) ;
F_60 ( V_55 ) ;
V_95:
return V_89 ;
}
static long F_118 ( struct V_11 * V_55 , long V_159 )
{
struct V_36 * V_37 = F_31 ( V_55 ) ;
int V_160 ;
F_119 ( V_49 ) ;
F_120 ( & V_37 -> V_56 , & V_49 , V_161 ) ;
V_160 = ! F_49 ( V_55 , V_57 ) &&
! ( V_55 -> V_71 & V_162 ) &&
F_8 ( V_55 ) ;
F_13 ( V_55 ) ;
if ( V_160 )
V_159 = F_121 ( V_159 ) ;
F_122 ( & V_37 -> V_56 , & V_49 ) ;
return V_159 ;
}
static int F_123 ( struct V_87 * V_11 , struct V_135 * V_136 ,
int V_137 , int V_152 )
{
struct V_21 * V_22 = (struct V_21 * ) V_136 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) , * V_163 , * V_164 ;
struct V_11 * V_165 = NULL ;
struct V_11 * V_55 = NULL ;
struct V_3 * V_4 = NULL ;
unsigned V_8 ;
int V_166 ;
int V_89 ;
long V_159 ;
V_89 = F_17 ( V_22 , V_137 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_137 = V_89 ;
if ( F_116 ( V_155 , & V_11 -> V_152 ) && ! V_37 -> V_19 &&
( V_89 = F_88 ( V_11 ) ) != 0 )
goto V_95;
V_159 = F_124 ( V_12 , V_152 & V_167 ) ;
V_89 = - V_121 ;
V_165 = F_75 ( F_33 ( V_12 ) , NULL ) ;
if ( V_165 == NULL )
goto V_95;
V_4 = F_125 ( V_165 , 1 , 0 , V_98 ) ;
if ( V_4 == NULL )
goto V_95;
V_156:
V_55 = F_94 ( V_32 , V_22 , V_137 , V_12 -> V_75 , V_8 , & V_89 ) ;
if ( ! V_55 )
goto V_95;
F_11 ( V_55 ) ;
if ( F_49 ( V_55 , V_57 ) ) {
F_13 ( V_55 ) ;
F_60 ( V_55 ) ;
goto V_156;
}
V_89 = - V_132 ;
if ( V_55 -> V_73 != V_81 )
goto V_96;
if ( V_55 -> V_71 & V_162 )
goto V_96;
if ( F_8 ( V_55 ) ) {
V_89 = - V_168 ;
if ( ! V_159 )
goto V_96;
V_159 = F_118 ( V_55 , V_159 ) ;
V_89 = F_126 ( V_159 ) ;
if ( F_127 ( V_85 ) )
goto V_95;
F_60 ( V_55 ) ;
goto V_156;
}
V_166 = V_12 -> V_73 ;
switch ( V_166 ) {
case V_74 :
break;
case V_169 :
V_89 = - V_170 ;
goto V_96;
default:
V_89 = - V_25 ;
goto V_96;
}
F_113 ( V_12 ) ;
if ( V_12 -> V_73 != V_166 ) {
F_13 ( V_12 ) ;
F_13 ( V_55 ) ;
F_60 ( V_55 ) ;
goto V_156;
}
V_89 = F_128 ( V_12 , V_55 , V_165 ) ;
if ( V_89 ) {
F_13 ( V_12 ) ;
goto V_96;
}
F_12 ( V_12 ) ;
F_6 ( V_165 ) = V_12 ;
V_165 -> V_73 = V_169 ;
V_165 -> V_75 = V_12 -> V_75 ;
F_66 ( V_165 ) ;
V_163 = F_31 ( V_165 ) ;
F_129 ( V_165 -> V_48 , & V_163 -> V_171 ) ;
V_164 = F_31 ( V_55 ) ;
if ( V_164 -> V_19 ) {
F_130 ( & V_164 -> V_19 -> V_20 ) ;
V_163 -> V_19 = V_164 -> V_19 ;
}
if ( V_164 -> V_42 ) {
V_163 -> V_42 = F_131 ( V_164 -> V_42 ) ;
V_163 -> V_68 = F_132 ( V_164 -> V_68 ) ;
}
F_72 ( V_12 , V_55 ) ;
V_11 -> V_70 = V_172 ;
V_12 -> V_73 = V_169 ;
F_12 ( V_165 ) ;
F_133 () ;
F_6 ( V_12 ) = V_165 ;
F_13 ( V_12 ) ;
F_26 ( & V_55 -> V_14 . V_100 ) ;
F_134 ( & V_55 -> V_14 , V_4 ) ;
F_27 ( & V_55 -> V_14 . V_100 ) ;
F_13 ( V_55 ) ;
V_55 -> V_173 ( V_55 , 0 ) ;
F_60 ( V_55 ) ;
return 0 ;
V_96:
if ( V_55 )
F_13 ( V_55 ) ;
V_95:
F_62 ( V_4 ) ;
if ( V_165 )
F_58 ( V_165 , 0 ) ;
if ( V_55 )
F_60 ( V_55 ) ;
return V_89 ;
}
static int F_135 ( struct V_87 * V_174 , struct V_87 * V_175 )
{
struct V_11 * V_176 = V_174 -> V_12 , * V_4 = V_175 -> V_12 ;
F_12 ( V_176 ) ;
F_12 ( V_4 ) ;
F_6 ( V_176 ) = V_4 ;
F_6 ( V_4 ) = V_176 ;
F_66 ( V_176 ) ;
F_66 ( V_4 ) ;
if ( V_176 -> V_75 != V_117 ) {
V_176 -> V_73 = V_169 ;
V_4 -> V_73 = V_169 ;
V_174 -> V_70 = V_172 ;
V_175 -> V_70 = V_172 ;
}
return 0 ;
}
static int F_136 ( struct V_87 * V_11 , struct V_87 * V_177 , int V_152 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_178 ;
struct V_3 * V_4 ;
int V_89 ;
V_89 = - V_94 ;
if ( V_11 -> type != V_76 && V_11 -> type != V_77 )
goto V_95;
V_89 = - V_25 ;
if ( V_12 -> V_73 != V_81 )
goto V_95;
V_4 = F_137 ( V_12 , 0 , V_152 & V_167 , & V_89 ) ;
if ( ! V_4 ) {
if ( V_89 == 0 )
V_89 = - V_25 ;
goto V_95;
}
V_178 = V_4 -> V_12 ;
F_138 ( V_12 , V_4 ) ;
F_139 ( & F_31 ( V_12 ) -> V_56 ) ;
F_11 ( V_178 ) ;
V_177 -> V_70 = V_172 ;
F_140 ( V_178 , V_177 ) ;
F_13 ( V_178 ) ;
return 0 ;
V_95:
return V_89 ;
}
static int F_141 ( struct V_87 * V_11 , struct V_135 * V_136 , int * V_179 , int V_17 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 ;
F_142 ( struct V_21 * , V_22 , V_136 ) ;
int V_89 = 0 ;
if ( V_17 ) {
V_12 = F_10 ( V_12 ) ;
V_89 = - V_180 ;
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
* V_179 = sizeof( short ) ;
} else {
struct V_18 * V_19 = V_37 -> V_19 ;
* V_179 = V_19 -> V_23 ;
memcpy ( V_22 , V_19 -> V_38 , * V_179 ) ;
}
F_13 ( V_12 ) ;
F_60 ( V_12 ) ;
V_95:
return V_89 ;
}
static void F_143 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_41 ;
V_2 -> V_181 = F_144 ( V_4 ) . V_181 ;
F_144 ( V_4 ) . V_181 = NULL ;
for ( V_41 = V_2 -> V_181 -> V_182 - 1 ; V_41 >= 0 ; V_41 -- )
F_145 ( V_2 -> V_181 -> V_181 [ V_41 ] ) ;
}
static void F_146 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_90 = F_144 ( V_4 ) . V_90 ;
V_2 . V_92 = F_144 ( V_4 ) . V_92 ;
if ( F_144 ( V_4 ) . V_181 )
F_143 ( & V_2 , V_4 ) ;
F_147 ( & V_2 ) ;
F_148 ( V_4 ) ;
}
static int F_149 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_41 ;
unsigned char V_183 = 0 ;
int V_184 = 0 ;
for ( V_41 = V_2 -> V_181 -> V_182 - 1 ; V_41 >= 0 ; V_41 -- ) {
struct V_11 * V_12 = F_150 ( V_2 -> V_181 -> V_181 [ V_41 ] ) ;
if ( V_12 ) {
V_184 ++ ;
V_183 = F_151 ( V_183 ,
F_31 ( V_12 ) -> V_185 ) ;
}
}
if ( F_112 ( V_183 > V_186 ) )
return - V_187 ;
F_144 ( V_4 ) . V_181 = F_152 ( V_2 -> V_181 ) ;
if ( ! F_144 ( V_4 ) . V_181 )
return - V_121 ;
if ( V_184 ) {
for ( V_41 = V_2 -> V_181 -> V_182 - 1 ; V_41 >= 0 ; V_41 -- )
F_153 ( V_2 -> V_181 -> V_181 [ V_41 ] ) ;
}
return V_183 ;
}
static int F_154 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_188 )
{
int V_89 = 0 ;
F_144 ( V_4 ) . V_90 = F_69 ( V_2 -> V_90 ) ;
if ( V_2 -> V_92 )
F_144 ( V_4 ) . V_92 = F_73 ( V_2 -> V_92 ) ;
F_144 ( V_4 ) . V_181 = NULL ;
if ( V_2 -> V_181 && V_188 )
V_89 = F_149 ( V_2 , V_4 ) ;
V_4 -> V_189 = F_146 ;
return V_89 ;
}
static void F_155 ( struct V_3 * V_4 , const struct V_87 * V_11 ,
const struct V_11 * V_55 )
{
if ( F_144 ( V_4 ) . V_92 )
return;
if ( F_116 ( V_155 , & V_11 -> V_152 ) ||
! V_55 -> V_61 ||
F_116 ( V_155 , & V_55 -> V_61 -> V_152 ) ) {
F_144 ( V_4 ) . V_90 = F_69 ( F_70 ( V_85 ) ) ;
F_144 ( V_4 ) . V_92 = F_71 () ;
}
}
static int F_156 ( struct V_190 * V_190 , struct V_87 * V_11 ,
struct V_191 * V_192 , T_3 V_23 )
{
struct V_193 * V_194 = F_157 ( V_190 ) ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_32 * V_32 = F_33 ( V_12 ) ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = V_192 -> V_195 ;
struct V_11 * V_55 = NULL ;
int V_196 = 0 ;
int V_89 ;
unsigned V_8 ;
struct V_3 * V_4 ;
long V_159 ;
struct V_1 V_197 ;
int V_183 ;
if ( NULL == V_194 -> V_2 )
V_194 -> V_2 = & V_197 ;
F_158 () ;
V_89 = F_159 ( V_11 , V_192 , V_194 -> V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = - V_94 ;
if ( V_192 -> V_198 & V_199 )
goto V_95;
if ( V_192 -> V_200 ) {
V_89 = F_17 ( V_22 , V_192 -> V_200 , & V_8 ) ;
if ( V_89 < 0 )
goto V_95;
V_196 = V_89 ;
} else {
V_22 = NULL ;
V_89 = - V_180 ;
V_55 = F_10 ( V_12 ) ;
if ( ! V_55 )
goto V_95;
}
if ( F_116 ( V_155 , & V_11 -> V_152 ) && ! V_37 -> V_19
&& ( V_89 = F_88 ( V_11 ) ) != 0 )
goto V_95;
V_89 = - V_201 ;
if ( V_23 > V_12 -> V_45 - 32 )
goto V_95;
V_4 = F_160 ( V_12 , V_23 , V_192 -> V_198 & V_202 , & V_89 ) ;
if ( V_4 == NULL )
goto V_95;
V_89 = F_154 ( V_194 -> V_2 , V_4 , true ) ;
if ( V_89 < 0 )
goto V_203;
V_183 = V_89 + 1 ;
F_1 ( V_194 -> V_2 , V_4 ) ;
F_161 ( V_4 ) ;
V_89 = F_162 ( F_163 ( V_4 , V_23 ) , V_192 -> V_204 , V_23 ) ;
if ( V_89 )
goto V_203;
V_159 = F_124 ( V_12 , V_192 -> V_198 & V_202 ) ;
V_156:
if ( ! V_55 ) {
V_89 = - V_59 ;
if ( V_22 == NULL )
goto V_203;
V_55 = F_94 ( V_32 , V_22 , V_196 , V_12 -> V_75 ,
V_8 , & V_89 ) ;
if ( V_55 == NULL )
goto V_203;
}
if ( F_164 ( V_55 , V_4 ) < 0 ) {
V_89 = V_23 ;
goto V_203;
}
F_11 ( V_55 ) ;
V_89 = - V_157 ;
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
goto V_203;
goto V_156;
}
V_89 = - V_205 ;
if ( V_55 -> V_71 & V_162 )
goto V_96;
if ( V_12 -> V_75 != V_77 ) {
V_89 = F_117 ( V_12 -> V_61 , V_55 -> V_61 ) ;
if ( V_89 )
goto V_96;
}
if ( F_6 ( V_55 ) != V_12 && F_8 ( V_55 ) ) {
if ( ! V_159 ) {
V_89 = - V_168 ;
goto V_96;
}
V_159 = F_118 ( V_55 , V_159 ) ;
V_89 = F_126 ( V_159 ) ;
if ( F_127 ( V_85 ) )
goto V_203;
goto V_156;
}
if ( F_49 ( V_55 , V_206 ) )
F_165 ( V_4 ) ;
F_155 ( V_4 , V_11 , V_55 ) ;
F_166 ( & V_55 -> V_14 , V_4 ) ;
if ( V_183 > F_31 ( V_55 ) -> V_185 )
F_31 ( V_55 ) -> V_185 = V_183 ;
F_13 ( V_55 ) ;
V_55 -> V_173 ( V_55 , V_23 ) ;
F_60 ( V_55 ) ;
F_147 ( V_194 -> V_2 ) ;
return V_23 ;
V_96:
F_13 ( V_55 ) ;
V_203:
F_62 ( V_4 ) ;
V_95:
if ( V_55 )
F_60 ( V_55 ) ;
F_147 ( V_194 -> V_2 ) ;
return V_89 ;
}
static int F_167 ( struct V_190 * V_190 , struct V_87 * V_11 ,
struct V_191 * V_192 , T_3 V_23 )
{
struct V_193 * V_194 = F_157 ( V_190 ) ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_55 = NULL ;
int V_89 , V_207 ;
struct V_3 * V_4 ;
int V_208 = 0 ;
struct V_1 V_197 ;
bool V_209 = false ;
int V_183 ;
if ( NULL == V_194 -> V_2 )
V_194 -> V_2 = & V_197 ;
F_158 () ;
V_89 = F_159 ( V_11 , V_192 , V_194 -> V_2 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = - V_94 ;
if ( V_192 -> V_198 & V_199 )
goto V_210;
if ( V_192 -> V_200 ) {
V_89 = V_12 -> V_73 == V_169 ? - V_170 : - V_94 ;
goto V_210;
} else {
V_89 = - V_180 ;
V_55 = F_6 ( V_12 ) ;
if ( ! V_55 )
goto V_210;
}
if ( V_12 -> V_71 & V_211 )
goto V_212;
while ( V_208 < V_23 ) {
V_207 = V_23 - V_208 ;
if ( V_207 > ( ( V_12 -> V_45 >> 1 ) - 64 ) )
V_207 = ( V_12 -> V_45 >> 1 ) - 64 ;
if ( V_207 > V_213 )
V_207 = V_213 ;
V_4 = F_160 ( V_12 , V_207 , V_192 -> V_198 & V_202 ,
& V_89 ) ;
if ( V_4 == NULL )
goto V_210;
V_207 = F_168 ( int , V_207 , F_169 ( V_4 ) ) ;
V_89 = F_154 ( V_194 -> V_2 , V_4 , ! V_209 ) ;
if ( V_89 < 0 ) {
F_62 ( V_4 ) ;
goto V_210;
}
V_183 = V_89 + 1 ;
V_209 = true ;
V_89 = F_162 ( F_163 ( V_4 , V_207 ) , V_192 -> V_204 , V_207 ) ;
if ( V_89 ) {
F_62 ( V_4 ) ;
goto V_210;
}
F_11 ( V_55 ) ;
if ( F_49 ( V_55 , V_57 ) ||
( V_55 -> V_71 & V_162 ) )
goto V_214;
F_155 ( V_4 , V_11 , V_55 ) ;
F_166 ( & V_55 -> V_14 , V_4 ) ;
if ( V_183 > F_31 ( V_55 ) -> V_185 )
F_31 ( V_55 ) -> V_185 = V_183 ;
F_13 ( V_55 ) ;
V_55 -> V_173 ( V_55 , V_207 ) ;
V_208 += V_207 ;
}
F_147 ( V_194 -> V_2 ) ;
V_194 -> V_2 = NULL ;
return V_208 ;
V_214:
F_13 ( V_55 ) ;
F_62 ( V_4 ) ;
V_212:
if ( V_208 == 0 && ! ( V_192 -> V_198 & V_215 ) )
F_170 ( V_216 , V_85 , 0 ) ;
V_89 = - V_205 ;
V_210:
F_147 ( V_194 -> V_2 ) ;
V_194 -> V_2 = NULL ;
return V_208 ? : V_89 ;
}
static int F_171 ( struct V_190 * V_190 , struct V_87 * V_11 ,
struct V_191 * V_192 , T_3 V_23 )
{
int V_89 ;
struct V_11 * V_12 = V_11 -> V_12 ;
V_89 = F_172 ( V_12 ) ;
if ( V_89 )
return V_89 ;
if ( V_12 -> V_73 != V_169 )
return - V_180 ;
if ( V_192 -> V_200 )
V_192 -> V_200 = 0 ;
return F_156 ( V_190 , V_11 , V_192 , V_23 ) ;
}
static int F_173 ( struct V_190 * V_217 , struct V_87 * V_11 ,
struct V_191 * V_192 , T_3 V_207 ,
int V_152 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
if ( V_12 -> V_73 != V_169 )
return - V_180 ;
return F_174 ( V_217 , V_11 , V_192 , V_207 , V_152 ) ;
}
static void F_175 ( struct V_191 * V_192 , struct V_11 * V_12 )
{
struct V_36 * V_37 = F_31 ( V_12 ) ;
V_192 -> V_200 = 0 ;
if ( V_37 -> V_19 ) {
V_192 -> V_200 = V_37 -> V_19 -> V_23 ;
memcpy ( V_192 -> V_195 , V_37 -> V_19 -> V_38 , V_37 -> V_19 -> V_23 ) ;
}
}
static int F_174 ( struct V_190 * V_217 , struct V_87 * V_11 ,
struct V_191 * V_192 , T_3 V_207 ,
int V_152 )
{
struct V_193 * V_194 = F_157 ( V_217 ) ;
struct V_1 V_197 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
int V_218 = V_152 & V_202 ;
struct V_3 * V_4 ;
int V_89 ;
V_89 = - V_94 ;
if ( V_152 & V_199 )
goto V_95;
V_192 -> V_200 = 0 ;
V_89 = F_176 ( & V_37 -> V_108 ) ;
if ( V_89 ) {
V_89 = F_126 ( F_177 ( V_12 , V_218 ) ) ;
goto V_95;
}
V_4 = F_137 ( V_12 , V_152 , V_218 , & V_89 ) ;
if ( ! V_4 ) {
F_11 ( V_12 ) ;
if ( V_12 -> V_75 == V_77 && V_89 == - V_168 &&
( V_12 -> V_71 & V_162 ) )
V_89 = 0 ;
F_13 ( V_12 ) ;
goto V_96;
}
F_42 ( & V_37 -> V_56 ,
V_50 | V_51 | V_52 ) ;
if ( V_192 -> V_195 )
F_175 ( V_192 , V_4 -> V_12 ) ;
if ( V_207 > V_4 -> V_23 )
V_207 = V_4 -> V_23 ;
else if ( V_207 < V_4 -> V_23 )
V_192 -> V_198 |= V_219 ;
V_89 = F_178 ( V_4 , 0 , V_192 -> V_204 , V_207 ) ;
if ( V_89 )
goto V_203;
if ( F_49 ( V_12 , V_206 ) )
F_179 ( V_192 , V_12 , V_4 ) ;
if ( ! V_194 -> V_2 ) {
V_194 -> V_2 = & V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
}
F_180 ( V_194 -> V_2 , F_144 ( V_4 ) . V_90 , F_144 ( V_4 ) . V_92 ) ;
F_3 ( V_194 -> V_2 , V_4 ) ;
if ( ! ( V_152 & V_220 ) ) {
if ( F_144 ( V_4 ) . V_181 )
F_143 ( V_194 -> V_2 , V_4 ) ;
} else {
if ( F_144 ( V_4 ) . V_181 )
V_194 -> V_2 -> V_181 = F_152 ( F_144 ( V_4 ) . V_181 ) ;
}
V_89 = V_207 ;
F_181 ( V_11 , V_192 , V_194 -> V_2 , V_152 ) ;
V_203:
F_138 ( V_12 , V_4 ) ;
V_96:
F_93 ( & V_37 -> V_108 ) ;
V_95:
return V_89 ;
}
static long F_182 ( struct V_11 * V_12 , long V_159 )
{
F_119 ( V_49 ) ;
F_11 ( V_12 ) ;
for (; ; ) {
F_183 ( F_184 ( V_12 ) , & V_49 , V_161 ) ;
if ( ! F_46 ( & V_12 -> V_14 ) ||
V_12 -> V_58 ||
( V_12 -> V_71 & V_162 ) ||
F_127 ( V_85 ) ||
! V_159 )
break;
F_185 ( V_221 , & V_12 -> V_61 -> V_152 ) ;
F_13 ( V_12 ) ;
V_159 = F_121 ( V_159 ) ;
F_11 ( V_12 ) ;
F_186 ( V_221 , & V_12 -> V_61 -> V_152 ) ;
}
F_122 ( F_184 ( V_12 ) , & V_49 ) ;
F_13 ( V_12 ) ;
return V_159 ;
}
static int F_187 ( struct V_190 * V_217 , struct V_87 * V_11 ,
struct V_191 * V_192 , T_3 V_207 ,
int V_152 )
{
struct V_193 * V_194 = F_157 ( V_217 ) ;
struct V_1 V_197 ;
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_36 * V_37 = F_31 ( V_12 ) ;
struct V_21 * V_22 = V_192 -> V_195 ;
int V_222 = 0 ;
int V_223 = 0 ;
int V_224 ;
int V_89 = 0 ;
long V_159 ;
V_89 = - V_25 ;
if ( V_12 -> V_73 != V_169 )
goto V_95;
V_89 = - V_94 ;
if ( V_152 & V_199 )
goto V_95;
V_224 = F_188 ( V_12 , V_152 & V_225 , V_207 ) ;
V_159 = F_177 ( V_12 , V_152 & V_202 ) ;
V_192 -> V_200 = 0 ;
if ( ! V_194 -> V_2 ) {
V_194 -> V_2 = & V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
}
V_89 = F_176 ( & V_37 -> V_108 ) ;
if ( V_89 ) {
V_89 = F_126 ( V_159 ) ;
goto V_95;
}
do {
int V_226 ;
struct V_3 * V_4 ;
F_11 ( V_12 ) ;
V_4 = F_189 ( & V_12 -> V_14 ) ;
if ( V_4 == NULL ) {
F_31 ( V_12 ) -> V_185 = 0 ;
if ( V_222 >= V_224 )
goto V_227;
V_89 = F_172 ( V_12 ) ;
if ( V_89 )
goto V_227;
if ( V_12 -> V_71 & V_162 )
goto V_227;
F_13 ( V_12 ) ;
V_89 = - V_168 ;
if ( ! V_159 )
break;
F_93 ( & V_37 -> V_108 ) ;
V_159 = F_182 ( V_12 , V_159 ) ;
if ( F_127 ( V_85 )
|| F_176 ( & V_37 -> V_108 ) ) {
V_89 = F_126 ( V_159 ) ;
goto V_95;
}
continue;
V_227:
F_13 ( V_12 ) ;
break;
}
F_13 ( V_12 ) ;
if ( V_223 ) {
if ( ( F_144 ( V_4 ) . V_90 != V_194 -> V_2 -> V_90 ) ||
( F_144 ( V_4 ) . V_92 != V_194 -> V_2 -> V_92 ) )
break;
} else {
F_180 ( V_194 -> V_2 , F_144 ( V_4 ) . V_90 , F_144 ( V_4 ) . V_92 ) ;
V_223 = 1 ;
}
if ( V_22 ) {
F_175 ( V_192 , V_4 -> V_12 ) ;
V_22 = NULL ;
}
V_226 = F_168 (unsigned int, skb->len, size) ;
if ( F_190 ( V_192 -> V_204 , V_4 -> V_228 , V_226 ) ) {
if ( V_222 == 0 )
V_222 = - V_229 ;
break;
}
V_222 += V_226 ;
V_207 -= V_226 ;
if ( ! ( V_152 & V_220 ) ) {
F_191 ( V_4 , V_226 ) ;
if ( F_144 ( V_4 ) . V_181 )
F_143 ( V_194 -> V_2 , V_4 ) ;
if ( V_4 -> V_23 )
break;
F_192 ( V_4 , & V_12 -> V_14 ) ;
F_193 ( V_4 ) ;
if ( V_194 -> V_2 -> V_181 )
break;
} else {
if ( F_144 ( V_4 ) . V_181 )
V_194 -> V_2 -> V_181 = F_152 ( F_144 ( V_4 ) . V_181 ) ;
break;
}
} while ( V_207 );
F_93 ( & V_37 -> V_108 ) ;
F_181 ( V_11 , V_192 , V_194 -> V_2 , V_152 ) ;
V_95:
return V_222 ? : V_89 ;
}
static int F_194 ( struct V_87 * V_11 , int V_139 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
struct V_11 * V_55 ;
V_139 = ( V_139 + 1 ) & ( V_162 | V_211 ) ;
if ( ! V_139 )
return 0 ;
F_11 ( V_12 ) ;
V_12 -> V_71 |= V_139 ;
V_55 = F_6 ( V_12 ) ;
if ( V_55 )
F_12 ( V_55 ) ;
F_13 ( V_12 ) ;
V_12 -> V_78 ( V_12 ) ;
if ( V_55 &&
( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) ) {
int V_230 = 0 ;
if ( V_139 & V_162 )
V_230 |= V_211 ;
if ( V_139 & V_211 )
V_230 |= V_162 ;
F_11 ( V_55 ) ;
V_55 -> V_71 |= V_230 ;
F_13 ( V_55 ) ;
V_55 -> V_78 ( V_55 ) ;
if ( V_230 == V_72 )
F_43 ( V_55 , V_79 , V_80 ) ;
else if ( V_230 & V_162 )
F_43 ( V_55 , V_79 , V_231 ) ;
}
if ( V_55 )
F_60 ( V_55 ) ;
return 0 ;
}
long F_195 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
long V_232 = 0 ;
if ( V_12 -> V_73 == V_81 )
return - V_25 ;
F_26 ( & V_12 -> V_14 . V_100 ) ;
if ( V_12 -> V_75 == V_76 ||
V_12 -> V_75 == V_77 ) {
F_196 (&sk->sk_receive_queue, skb)
V_232 += V_4 -> V_23 ;
} else {
V_4 = F_189 ( & V_12 -> V_14 ) ;
if ( V_4 )
V_232 = V_4 -> V_23 ;
}
F_27 ( & V_12 -> V_14 . V_100 ) ;
return V_232 ;
}
long F_197 ( struct V_11 * V_12 )
{
return F_198 ( V_12 ) ;
}
static int F_199 ( struct V_87 * V_11 , unsigned int V_233 , unsigned long V_234 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
long V_232 = 0 ;
int V_89 ;
switch ( V_233 ) {
case V_235 :
V_232 = F_197 ( V_12 ) ;
V_89 = F_200 ( V_232 , ( int V_236 * ) V_234 ) ;
break;
case V_237 :
V_232 = F_195 ( V_12 ) ;
if ( V_232 < 0 )
V_89 = V_232 ;
else
V_89 = F_200 ( V_232 , ( int V_236 * ) V_234 ) ;
break;
default:
V_89 = - V_238 ;
break;
}
return V_89 ;
}
static unsigned int F_201 ( struct V_239 * V_239 , struct V_87 * V_11 , T_4 * V_49 )
{
struct V_11 * V_12 = V_11 -> V_12 ;
unsigned int V_240 ;
F_202 ( V_239 , F_184 ( V_12 ) , V_49 ) ;
V_240 = 0 ;
if ( V_12 -> V_58 )
V_240 |= V_241 ;
if ( V_12 -> V_71 == V_72 )
V_240 |= V_242 ;
if ( V_12 -> V_71 & V_162 )
V_240 |= V_243 | V_244 | V_245 ;
if ( ! F_46 ( & V_12 -> V_14 ) )
V_240 |= V_244 | V_245 ;
if ( ( V_12 -> V_75 == V_76 || V_12 -> V_75 == V_77 ) &&
V_12 -> V_73 == V_74 )
V_240 |= V_242 ;
if ( F_36 ( V_12 ) )
V_240 |= V_50 | V_51 | V_52 ;
return V_240 ;
}
static unsigned int F_203 ( struct V_239 * V_239 , struct V_87 * V_11 ,
T_4 * V_49 )
{
struct V_11 * V_12 = V_11 -> V_12 , * V_55 ;
unsigned int V_240 , V_246 ;
F_202 ( V_239 , F_184 ( V_12 ) , V_49 ) ;
V_240 = 0 ;
if ( V_12 -> V_58 || ! F_46 ( & V_12 -> V_247 ) )
V_240 |= V_241 ;
if ( V_12 -> V_71 & V_162 )
V_240 |= V_243 | V_244 | V_245 ;
if ( V_12 -> V_71 == V_72 )
V_240 |= V_242 ;
if ( ! F_46 ( & V_12 -> V_14 ) )
V_240 |= V_244 | V_245 ;
if ( V_12 -> V_75 == V_77 ) {
if ( V_12 -> V_73 == V_74 )
V_240 |= V_242 ;
if ( V_12 -> V_73 == V_248 )
return V_240 ;
}
if ( V_49 && ! ( V_49 -> V_249 & ( V_52 | V_51 | V_50 ) ) )
return V_240 ;
V_246 = F_36 ( V_12 ) ;
V_55 = F_10 ( V_12 ) ;
if ( V_55 ) {
if ( F_6 ( V_55 ) != V_12 ) {
F_202 ( V_239 , & F_31 ( V_55 ) -> V_56 , V_49 ) ;
if ( F_8 ( V_55 ) )
V_246 = 0 ;
}
F_60 ( V_55 ) ;
}
if ( V_246 )
V_240 |= V_50 | V_51 | V_52 ;
else
F_185 ( V_250 , & V_12 -> V_61 -> V_152 ) ;
return V_240 ;
}
static struct V_11 * F_204 ( int * V_41 )
{
for ( * V_41 = 0 ; * V_41 <= V_10 ; ( * V_41 ) ++ ) {
if ( ! F_205 ( & V_126 [ * V_41 ] ) )
return F_206 ( & V_126 [ * V_41 ] ) ;
}
return NULL ;
}
static struct V_11 * F_207 ( int * V_41 , struct V_11 * V_16 )
{
struct V_11 * V_251 = F_208 ( V_16 ) ;
if ( V_251 )
return V_251 ;
for ( ( * V_41 ) ++ ; * V_41 <= V_10 ; ( * V_41 ) ++ ) {
if ( ! F_205 ( & V_126 [ * V_41 ] ) )
return F_206 ( & V_126 [ * V_41 ] ) ;
}
return NULL ;
}
static struct V_11 * F_209 ( struct V_252 * V_253 , T_5 V_254 )
{
struct V_255 * V_256 = V_253 -> V_257 ;
T_5 V_258 = 0 ;
struct V_11 * V_16 ;
for ( V_16 = F_204 ( & V_256 -> V_41 ) ; V_16 ; V_16 = F_207 ( & V_256 -> V_41 , V_16 ) ) {
if ( F_33 ( V_16 ) != F_210 ( V_253 ) )
continue;
if ( V_258 == V_254 )
return V_16 ;
++ V_258 ;
}
return NULL ;
}
static void * F_211 ( struct V_252 * V_253 , T_5 * V_254 )
__acquires( V_31 )
{
F_26 ( & V_31 ) ;
return * V_254 ? F_209 ( V_253 , * V_254 - 1 ) : V_259 ;
}
static void * F_212 ( struct V_252 * V_253 , void * V_260 , T_5 * V_254 )
{
struct V_255 * V_256 = V_253 -> V_257 ;
struct V_11 * V_12 = V_260 ;
++ * V_254 ;
if ( V_260 == V_259 )
V_12 = F_204 ( & V_256 -> V_41 ) ;
else
V_12 = F_207 ( & V_256 -> V_41 , V_12 ) ;
while ( V_12 && ( F_33 ( V_12 ) != F_210 ( V_253 ) ) )
V_12 = F_207 ( & V_256 -> V_41 , V_12 ) ;
return V_12 ;
}
static void F_213 ( struct V_252 * V_253 , void * V_260 )
__releases( V_31 )
{
F_27 ( & V_31 ) ;
}
static int F_214 ( struct V_252 * V_253 , void * V_260 )
{
if ( V_260 == V_259 )
F_215 ( V_253 , L_4
L_5 ) ;
else {
struct V_11 * V_16 = V_260 ;
struct V_36 * V_37 = F_31 ( V_16 ) ;
F_11 ( V_16 ) ;
F_216 ( V_253 , L_6 ,
V_16 ,
F_37 ( & V_16 -> V_261 ) ,
0 ,
V_16 -> V_73 == V_81 ? V_262 : 0 ,
V_16 -> V_75 ,
V_16 -> V_61 ?
( V_16 -> V_73 == V_169 ? V_172 : V_113 ) :
( V_16 -> V_73 == V_169 ? V_263 : V_264 ) ,
F_217 ( V_16 ) ) ;
if ( V_37 -> V_19 ) {
int V_41 , V_23 ;
F_218 ( V_253 , ' ' ) ;
V_41 = 0 ;
V_23 = V_37 -> V_19 -> V_23 - sizeof( short ) ;
if ( ! F_219 ( V_16 ) )
V_23 -- ;
else {
F_218 ( V_253 , '@' ) ;
V_41 ++ ;
}
for ( ; V_41 < V_23 ; V_41 ++ )
F_218 ( V_253 , V_37 -> V_19 -> V_38 -> V_28 [ V_41 ] ) ;
}
F_13 ( V_16 ) ;
F_218 ( V_253 , '\n' ) ;
}
return 0 ;
}
static int F_220 ( struct V_40 * V_40 , struct V_239 * V_239 )
{
return F_221 ( V_40 , V_239 , & V_265 ,
sizeof( struct V_255 ) ) ;
}
static int T_6 F_222 ( struct V_32 * V_32 )
{
int error = - V_121 ;
V_32 -> V_103 . V_104 = 10 ;
if ( F_223 ( V_32 ) )
goto V_95;
#ifdef F_224
if ( ! F_225 ( V_32 , L_7 , 0 , & V_266 ) ) {
F_226 ( V_32 ) ;
goto V_95;
}
#endif
error = 0 ;
V_95:
return error ;
}
static void T_7 F_227 ( struct V_32 * V_32 )
{
F_226 ( V_32 ) ;
F_228 ( V_32 , L_7 ) ;
}
static int T_8 F_229 ( void )
{
int V_267 = - 1 ;
struct V_3 * V_268 ;
F_230 ( sizeof( struct V_269 ) > sizeof( V_268 -> V_270 ) ) ;
V_267 = F_231 ( & V_99 , 1 ) ;
if ( V_267 != 0 ) {
F_51 ( V_271 L_8 ,
V_272 ) ;
goto V_95;
}
F_232 ( & V_273 ) ;
F_233 ( & V_274 ) ;
V_95:
return V_267 ;
}
static void T_9 F_234 ( void )
{
F_235 ( V_97 ) ;
F_236 ( & V_99 ) ;
F_237 ( & V_274 ) ;
}
