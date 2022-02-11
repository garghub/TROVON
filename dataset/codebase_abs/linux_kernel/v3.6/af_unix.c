static struct V_1 * F_1 ( void * V_2 )
{
unsigned long V_3 = ( unsigned long ) V_2 ;
V_3 ^= V_3 >> 16 ;
V_3 ^= V_3 >> 8 ;
V_3 %= V_4 ;
return & V_5 [ V_4 + V_3 ] ;
}
static void F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
memcpy ( F_3 ( V_9 ) , & V_7 -> V_10 , sizeof( V_11 ) ) ;
}
static inline void F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_7 -> V_10 = * F_3 ( V_9 ) ;
}
static inline void F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{ }
static inline void F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{ }
static inline unsigned int F_5 ( T_1 V_12 )
{
unsigned int V_3 = ( V_13 unsigned int ) V_12 ;
V_3 ^= V_3 >> 16 ;
V_3 ^= V_3 >> 8 ;
return V_3 & ( V_4 - 1 ) ;
}
static inline int F_6 ( struct V_14 * V_15 , struct V_14 * V_16 )
{
return F_7 ( V_16 ) == V_15 ;
}
static inline int F_8 ( struct V_14 * V_15 , struct V_14 * V_16 )
{
return F_7 ( V_16 ) == NULL || F_6 ( V_15 , V_16 ) ;
}
static inline int F_9 ( struct V_14 const * V_15 )
{
return F_10 ( & V_15 -> V_17 ) > V_15 -> V_18 ;
}
struct V_14 * F_11 ( struct V_14 * V_19 )
{
struct V_14 * V_20 ;
F_12 ( V_19 ) ;
V_20 = F_7 ( V_19 ) ;
if ( V_20 )
F_13 ( V_20 ) ;
F_14 ( V_19 ) ;
return V_20 ;
}
static inline void F_15 ( struct V_21 * V_2 )
{
if ( F_16 ( & V_2 -> V_22 ) )
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_23 * V_24 , int V_25 , unsigned int * V_26 )
{
if ( V_25 <= sizeof( short ) || V_25 > sizeof( * V_24 ) )
return - V_27 ;
if ( ! V_24 || V_24 -> V_28 != V_29 )
return - V_27 ;
if ( V_24 -> V_30 [ 0 ] ) {
( ( char * ) V_24 ) [ V_25 ] = 0 ;
V_25 = strlen ( V_24 -> V_30 ) + 1 + sizeof( short ) ;
return V_25 ;
}
* V_26 = F_5 ( F_19 ( V_24 , V_25 , 0 ) ) ;
return V_25 ;
}
static void F_20 ( struct V_14 * V_15 )
{
F_21 ( V_15 ) ;
}
static void F_22 ( struct V_1 * V_31 , struct V_14 * V_15 )
{
F_23 ( ! F_24 ( V_15 ) ) ;
F_25 ( V_15 , V_31 ) ;
}
static inline void F_26 ( struct V_14 * V_15 )
{
F_27 ( & V_32 ) ;
F_20 ( V_15 ) ;
F_28 ( & V_32 ) ;
}
static inline void F_29 ( struct V_1 * V_31 , struct V_14 * V_15 )
{
F_27 ( & V_32 ) ;
F_22 ( V_31 , V_15 ) ;
F_28 ( & V_32 ) ;
}
static struct V_14 * F_30 ( struct V_33 * V_33 ,
struct V_23 * V_34 ,
int V_25 , int type , unsigned int V_3 )
{
struct V_14 * V_19 ;
struct V_35 * V_36 ;
F_31 (s, node, &unix_socket_table[hash ^ type]) {
struct V_37 * V_38 = F_32 ( V_19 ) ;
if ( ! F_33 ( F_34 ( V_19 ) , V_33 ) )
continue;
if ( V_38 -> V_2 -> V_25 == V_25 &&
! memcmp ( V_38 -> V_2 -> V_39 , V_34 , V_25 ) )
goto V_40;
}
V_19 = NULL ;
V_40:
return V_19 ;
}
static inline struct V_14 * F_35 ( struct V_33 * V_33 ,
struct V_23 * V_34 ,
int V_25 , int type ,
unsigned int V_3 )
{
struct V_14 * V_19 ;
F_27 ( & V_32 ) ;
V_19 = F_30 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_19 )
F_13 ( V_19 ) ;
F_28 ( & V_32 ) ;
return V_19 ;
}
static struct V_14 * F_36 ( struct V_41 * V_42 )
{
struct V_14 * V_19 ;
struct V_35 * V_36 ;
F_27 ( & V_32 ) ;
F_31 (s, node,
&unix_socket_table[i->i_ino & (UNIX_HASH_SIZE - 1)]) {
struct V_43 * V_43 = F_32 ( V_19 ) -> V_44 . V_43 ;
if ( V_43 && V_43 -> V_45 == V_42 ) {
F_13 ( V_19 ) ;
goto V_40;
}
}
V_19 = NULL ;
V_40:
F_28 ( & V_32 ) ;
return V_19 ;
}
static inline int F_37 ( struct V_14 * V_15 )
{
return ( F_38 ( & V_15 -> V_46 ) << 2 ) <= V_15 -> V_47 ;
}
static void F_39 ( struct V_14 * V_15 )
{
struct V_48 * V_49 ;
F_40 () ;
if ( F_37 ( V_15 ) ) {
V_49 = F_41 ( V_15 -> V_50 ) ;
if ( F_42 ( V_49 ) )
F_43 ( & V_49 -> V_51 ,
V_52 | V_53 | V_54 ) ;
F_44 ( V_15 , V_55 , V_56 ) ;
}
F_45 () ;
}
static void F_46 ( struct V_14 * V_15 , struct V_14 * V_57 )
{
if ( ! F_47 ( & V_15 -> V_17 ) ) {
F_48 ( & V_15 -> V_17 ) ;
F_49 ( & F_32 ( V_15 ) -> V_58 ) ;
if ( ! F_50 ( V_57 , V_59 ) && F_7 ( V_57 ) == V_15 ) {
V_57 -> V_60 = V_61 ;
V_57 -> V_62 ( V_57 ) ;
}
}
}
static void F_51 ( struct V_14 * V_15 )
{
struct V_37 * V_38 = F_32 ( V_15 ) ;
F_48 ( & V_15 -> V_17 ) ;
F_23 ( F_38 ( & V_15 -> V_46 ) ) ;
F_23 ( ! F_24 ( V_15 ) ) ;
F_23 ( V_15 -> V_63 ) ;
if ( ! F_50 ( V_15 , V_59 ) ) {
F_52 ( V_64 L_1 , V_15 ) ;
return;
}
if ( V_38 -> V_2 )
F_15 ( V_38 -> V_2 ) ;
F_53 ( & V_65 ) ;
F_54 () ;
F_55 ( F_34 ( V_15 ) , V_15 -> V_66 , - 1 ) ;
F_56 () ;
#ifdef F_57
F_52 ( V_67 L_2 , V_15 ,
F_58 ( & V_65 ) ) ;
#endif
}
static int F_59 ( struct V_14 * V_15 , int V_68 )
{
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_44 V_44 ;
struct V_14 * V_69 ;
struct V_8 * V_9 ;
int V_70 ;
F_26 ( V_15 ) ;
F_12 ( V_15 ) ;
F_60 ( V_15 ) ;
V_15 -> V_71 = V_72 ;
V_44 = V_38 -> V_44 ;
V_38 -> V_44 . V_43 = NULL ;
V_38 -> V_44 . V_73 = NULL ;
V_70 = V_15 -> V_74 ;
V_15 -> V_74 = V_75 ;
F_14 ( V_15 ) ;
F_49 ( & V_38 -> V_58 ) ;
V_69 = F_7 ( V_15 ) ;
if ( V_69 != NULL ) {
if ( V_15 -> V_76 == V_77 || V_15 -> V_76 == V_78 ) {
F_12 ( V_69 ) ;
V_69 -> V_71 = V_72 ;
if ( ! F_47 ( & V_15 -> V_17 ) || V_68 )
V_69 -> V_60 = V_61 ;
F_14 ( V_69 ) ;
V_69 -> V_79 ( V_69 ) ;
F_44 ( V_69 , V_80 , V_81 ) ;
}
F_61 ( V_69 ) ;
F_7 ( V_15 ) = NULL ;
}
while ( ( V_9 = F_62 ( & V_15 -> V_17 ) ) != NULL ) {
if ( V_70 == V_82 )
F_59 ( V_9 -> V_15 , 1 ) ;
F_63 ( V_9 ) ;
}
if ( V_44 . V_43 )
F_64 ( & V_44 ) ;
F_61 ( V_15 ) ;
if ( V_83 )
F_65 () ;
return 0 ;
}
static void F_66 ( struct V_14 * V_15 )
{
F_67 ( V_15 -> V_84 ) ;
if ( V_15 -> V_85 )
F_68 ( V_15 -> V_85 ) ;
V_15 -> V_84 = F_69 ( F_70 ( V_86 ) ) ;
V_15 -> V_85 = F_71 () ;
}
static void F_72 ( struct V_14 * V_15 , struct V_14 * V_87 )
{
F_67 ( V_15 -> V_84 ) ;
if ( V_15 -> V_85 )
F_68 ( V_15 -> V_85 ) ;
V_15 -> V_84 = F_69 ( V_87 -> V_84 ) ;
V_15 -> V_85 = F_73 ( V_87 -> V_85 ) ;
}
static int F_74 ( struct V_88 * V_14 , int V_89 )
{
int V_90 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_91 * V_92 = NULL ;
const struct V_93 * V_94 = NULL ;
V_90 = - V_95 ;
if ( V_14 -> type != V_77 && V_14 -> type != V_78 )
goto V_96;
V_90 = - V_27 ;
if ( ! V_38 -> V_2 )
goto V_96;
F_12 ( V_15 ) ;
if ( V_15 -> V_74 != V_75 && V_15 -> V_74 != V_82 )
goto V_97;
if ( V_89 > V_15 -> V_18 )
F_49 ( & V_38 -> V_58 ) ;
V_15 -> V_18 = V_89 ;
V_15 -> V_74 = V_82 ;
F_66 ( V_15 ) ;
V_90 = 0 ;
V_97:
F_14 ( V_15 ) ;
F_67 ( V_92 ) ;
if ( V_94 )
F_68 ( V_94 ) ;
V_96:
return V_90 ;
}
static void F_75 ( struct V_14 * V_15 , int V_98 )
{
struct V_37 * V_38 = F_32 ( V_15 ) ;
F_76 ( & V_38 -> V_99 ) ;
V_15 -> V_100 = V_98 ;
F_77 ( & V_38 -> V_99 ) ;
}
static struct V_14 * F_78 ( struct V_33 * V_33 , struct V_88 * V_14 )
{
struct V_14 * V_15 = NULL ;
struct V_37 * V_38 ;
F_79 ( & V_65 ) ;
if ( F_58 ( & V_65 ) > 2 * F_80 () )
goto V_96;
V_15 = F_81 ( V_33 , V_101 , V_102 , & V_103 ) ;
if ( ! V_15 )
goto V_96;
F_82 ( V_14 , V_15 ) ;
F_83 ( & V_15 -> V_17 . V_104 ,
& V_105 ) ;
V_15 -> V_106 = F_39 ;
V_15 -> V_18 = V_33 -> V_107 . V_108 ;
V_15 -> V_109 = F_51 ;
V_38 = F_32 ( V_15 ) ;
V_38 -> V_44 . V_43 = NULL ;
V_38 -> V_44 . V_73 = NULL ;
F_84 ( & V_38 -> V_104 ) ;
F_85 ( & V_38 -> V_110 , 0 ) ;
F_86 ( & V_38 -> V_111 ) ;
F_87 ( & V_38 -> V_99 ) ;
F_88 ( & V_38 -> V_58 ) ;
F_29 ( F_1 ( V_15 ) , V_15 ) ;
V_96:
if ( V_15 == NULL )
F_53 ( & V_65 ) ;
else {
F_54 () ;
F_55 ( F_34 ( V_15 ) , V_15 -> V_66 , 1 ) ;
F_56 () ;
}
return V_15 ;
}
static int F_89 ( struct V_33 * V_33 , struct V_88 * V_14 , int V_112 ,
int V_113 )
{
if ( V_112 && V_112 != V_101 )
return - V_114 ;
V_14 -> V_70 = V_115 ;
switch ( V_14 -> type ) {
case V_77 :
V_14 -> V_116 = & V_117 ;
break;
case V_118 :
V_14 -> type = V_119 ;
case V_119 :
V_14 -> V_116 = & V_120 ;
break;
case V_78 :
V_14 -> V_116 = & V_121 ;
break;
default:
return - V_122 ;
}
return F_78 ( V_33 , V_14 ) ? 0 : - V_123 ;
}
static int F_90 ( struct V_88 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( ! V_15 )
return 0 ;
V_14 -> V_15 = NULL ;
return F_59 ( V_15 , 0 ) ;
}
static int F_91 ( struct V_88 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
static V_11 V_124 = 1 ;
struct V_21 * V_2 ;
int V_90 ;
unsigned int V_125 = 0 ;
F_76 ( & V_38 -> V_99 ) ;
V_90 = 0 ;
if ( V_38 -> V_2 )
goto V_96;
V_90 = - V_123 ;
V_2 = F_92 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_102 ) ;
if ( ! V_2 )
goto V_96;
V_2 -> V_39 -> V_28 = V_29 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
V_126:
V_2 -> V_25 = sprintf ( V_2 -> V_39 -> V_30 + 1 , L_3 , V_124 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_5 ( F_19 ( V_2 -> V_39 , V_2 -> V_25 , 0 ) ) ;
F_27 ( & V_32 ) ;
V_124 = ( V_124 + 1 ) & 0xFFFFF ;
if ( F_30 ( V_33 , V_2 -> V_39 , V_2 -> V_25 , V_14 -> type ,
V_2 -> V_3 ) ) {
F_28 ( & V_32 ) ;
F_94 () ;
if ( V_125 ++ == 0xFFFFF ) {
V_90 = - V_127 ;
F_17 ( V_2 ) ;
goto V_96;
}
goto V_126;
}
V_2 -> V_3 ^= V_15 -> V_76 ;
F_20 ( V_15 ) ;
V_38 -> V_2 = V_2 ;
F_22 ( & V_5 [ V_2 -> V_3 ] , V_15 ) ;
F_28 ( & V_32 ) ;
V_90 = 0 ;
V_96: F_77 ( & V_38 -> V_99 ) ;
return V_90 ;
}
static struct V_14 * F_95 ( struct V_33 * V_33 ,
struct V_23 * V_34 , int V_25 ,
int type , unsigned int V_3 , int * error )
{
struct V_14 * V_38 ;
struct V_44 V_44 ;
int V_90 = 0 ;
if ( V_34 -> V_30 [ 0 ] ) {
struct V_41 * V_41 ;
V_90 = F_96 ( V_34 -> V_30 , V_128 , & V_44 ) ;
if ( V_90 )
goto V_129;
V_41 = V_44 . V_43 -> V_45 ;
V_90 = F_97 ( V_41 , V_130 ) ;
if ( V_90 )
goto V_131;
V_90 = - V_132 ;
if ( ! F_98 ( V_41 -> V_133 ) )
goto V_131;
V_38 = F_36 ( V_41 ) ;
if ( ! V_38 )
goto V_131;
if ( V_38 -> V_76 == type )
F_99 ( & V_44 ) ;
F_64 ( & V_44 ) ;
V_90 = - V_134 ;
if ( V_38 -> V_76 != type ) {
F_61 ( V_38 ) ;
goto V_129;
}
} else {
V_90 = - V_132 ;
V_38 = F_35 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_38 ) {
struct V_43 * V_43 ;
V_43 = F_32 ( V_38 ) -> V_44 . V_43 ;
if ( V_43 )
F_99 ( & F_32 ( V_38 ) -> V_44 ) ;
} else
goto V_129;
}
return V_38 ;
V_131:
F_64 ( & V_44 ) ;
V_129:
* error = V_90 ;
return NULL ;
}
static int F_100 ( const char * V_30 , T_2 V_135 , struct V_44 * V_136 )
{
struct V_43 * V_43 ;
struct V_44 V_44 ;
int V_90 = 0 ;
V_43 = F_101 ( V_137 , V_30 , & V_44 , 0 ) ;
V_90 = F_102 ( V_43 ) ;
if ( F_103 ( V_43 ) )
return V_90 ;
V_90 = F_104 ( & V_44 , V_43 , V_135 , 0 ) ;
if ( ! V_90 ) {
V_90 = F_105 ( V_44 . V_43 -> V_45 , V_43 , V_135 , 0 ) ;
if ( ! V_90 ) {
V_136 -> V_73 = F_106 ( V_44 . V_73 ) ;
V_136 -> V_43 = F_107 ( V_43 ) ;
}
}
F_108 ( & V_44 , V_43 ) ;
return V_90 ;
}
static int F_109 ( struct V_88 * V_14 , struct V_138 * V_139 , int V_140 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_139 ;
char * V_30 = V_24 -> V_30 ;
int V_90 ;
unsigned int V_3 ;
struct V_21 * V_2 ;
struct V_1 * V_31 ;
V_90 = - V_27 ;
if ( V_24 -> V_28 != V_29 )
goto V_96;
if ( V_140 == sizeof( short ) ) {
V_90 = F_91 ( V_14 ) ;
goto V_96;
}
V_90 = F_18 ( V_24 , V_140 , & V_3 ) ;
if ( V_90 < 0 )
goto V_96;
V_140 = V_90 ;
F_76 ( & V_38 -> V_99 ) ;
V_90 = - V_27 ;
if ( V_38 -> V_2 )
goto V_141;
V_90 = - V_123 ;
V_2 = F_110 ( sizeof( * V_2 ) + V_140 , V_102 ) ;
if ( ! V_2 )
goto V_141;
memcpy ( V_2 -> V_39 , V_24 , V_140 ) ;
V_2 -> V_25 = V_140 ;
V_2 -> V_3 = V_3 ^ V_15 -> V_76 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
if ( V_30 [ 0 ] ) {
struct V_44 V_44 ;
T_2 V_135 = V_142 |
( F_111 ( V_14 ) -> V_133 & ~ F_112 () ) ;
V_90 = F_100 ( V_30 , V_135 , & V_44 ) ;
if ( V_90 ) {
if ( V_90 == - V_143 )
V_90 = - V_144 ;
F_15 ( V_2 ) ;
goto V_141;
}
V_2 -> V_3 = V_4 ;
V_3 = V_44 . V_43 -> V_45 -> V_145 & ( V_4 - 1 ) ;
F_27 ( & V_32 ) ;
V_38 -> V_44 = V_44 ;
V_31 = & V_5 [ V_3 ] ;
} else {
F_27 ( & V_32 ) ;
V_90 = - V_144 ;
if ( F_30 ( V_33 , V_24 , V_140 ,
V_15 -> V_76 , V_3 ) ) {
F_15 ( V_2 ) ;
goto V_97;
}
V_31 = & V_5 [ V_2 -> V_3 ] ;
}
V_90 = 0 ;
F_20 ( V_15 ) ;
V_38 -> V_2 = V_2 ;
F_22 ( V_31 , V_15 ) ;
V_97:
F_28 ( & V_32 ) ;
V_141:
F_77 ( & V_38 -> V_99 ) ;
V_96:
return V_90 ;
}
static void F_113 ( struct V_14 * V_146 , struct V_14 * V_147 )
{
if ( F_114 ( V_146 == V_147 ) || ! V_147 ) {
F_12 ( V_146 ) ;
return;
}
if ( V_146 < V_147 ) {
F_12 ( V_146 ) ;
F_115 ( V_147 ) ;
} else {
F_12 ( V_147 ) ;
F_115 ( V_146 ) ;
}
}
static void F_116 ( struct V_14 * V_146 , struct V_14 * V_147 )
{
if ( F_114 ( V_146 == V_147 ) || ! V_147 ) {
F_14 ( V_146 ) ;
return;
}
F_14 ( V_146 ) ;
F_14 ( V_147 ) ;
}
static int F_117 ( struct V_88 * V_14 , struct V_138 * V_2 ,
int V_148 , int V_149 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_2 ;
struct V_14 * V_57 ;
unsigned int V_3 ;
int V_90 ;
if ( V_2 -> V_150 != V_151 ) {
V_90 = F_18 ( V_24 , V_148 , & V_3 ) ;
if ( V_90 < 0 )
goto V_96;
V_148 = V_90 ;
if ( F_118 ( V_152 , & V_14 -> V_149 ) &&
! F_32 ( V_15 ) -> V_2 && ( V_90 = F_91 ( V_14 ) ) != 0 )
goto V_96;
V_153:
V_57 = F_95 ( V_33 , V_24 , V_148 , V_14 -> type , V_3 , & V_90 ) ;
if ( ! V_57 )
goto V_96;
F_113 ( V_15 , V_57 ) ;
if ( F_50 ( V_57 , V_59 ) ) {
F_116 ( V_15 , V_57 ) ;
F_61 ( V_57 ) ;
goto V_153;
}
V_90 = - V_154 ;
if ( ! F_8 ( V_15 , V_57 ) )
goto V_97;
V_90 = F_119 ( V_15 -> V_63 , V_57 -> V_63 ) ;
if ( V_90 )
goto V_97;
} else {
V_57 = NULL ;
F_113 ( V_15 , V_57 ) ;
}
if ( F_7 ( V_15 ) ) {
struct V_14 * V_155 = F_7 ( V_15 ) ;
F_7 ( V_15 ) = V_57 ;
F_116 ( V_15 , V_57 ) ;
if ( V_57 != V_155 )
F_46 ( V_15 , V_155 ) ;
F_61 ( V_155 ) ;
} else {
F_7 ( V_15 ) = V_57 ;
F_116 ( V_15 , V_57 ) ;
}
return 0 ;
V_97:
F_116 ( V_15 , V_57 ) ;
F_61 ( V_57 ) ;
V_96:
return V_90 ;
}
static long F_120 ( struct V_14 * V_57 , long V_156 )
{
struct V_37 * V_38 = F_32 ( V_57 ) ;
int V_157 ;
F_121 ( V_51 ) ;
F_122 ( & V_38 -> V_58 , & V_51 , V_158 ) ;
V_157 = ! F_50 ( V_57 , V_59 ) &&
! ( V_57 -> V_71 & V_159 ) &&
F_9 ( V_57 ) ;
F_14 ( V_57 ) ;
if ( V_157 )
V_156 = F_123 ( V_156 ) ;
F_124 ( & V_38 -> V_58 , & V_51 ) ;
return V_156 ;
}
static int F_125 ( struct V_88 * V_14 , struct V_138 * V_139 ,
int V_140 , int V_149 )
{
struct V_23 * V_24 = (struct V_23 * ) V_139 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) , * V_160 , * V_161 ;
struct V_14 * V_162 = NULL ;
struct V_14 * V_57 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_163 ;
int V_90 ;
long V_156 ;
V_90 = F_18 ( V_24 , V_140 , & V_3 ) ;
if ( V_90 < 0 )
goto V_96;
V_140 = V_90 ;
if ( F_118 ( V_152 , & V_14 -> V_149 ) && ! V_38 -> V_2 &&
( V_90 = F_91 ( V_14 ) ) != 0 )
goto V_96;
V_156 = F_126 ( V_15 , V_149 & V_164 ) ;
V_90 = - V_123 ;
V_162 = F_78 ( F_34 ( V_15 ) , NULL ) ;
if ( V_162 == NULL )
goto V_96;
V_9 = F_127 ( V_162 , 1 , 0 , V_102 ) ;
if ( V_9 == NULL )
goto V_96;
V_153:
V_57 = F_95 ( V_33 , V_24 , V_140 , V_15 -> V_76 , V_3 , & V_90 ) ;
if ( ! V_57 )
goto V_96;
F_12 ( V_57 ) ;
if ( F_50 ( V_57 , V_59 ) ) {
F_14 ( V_57 ) ;
F_61 ( V_57 ) ;
goto V_153;
}
V_90 = - V_132 ;
if ( V_57 -> V_74 != V_82 )
goto V_97;
if ( V_57 -> V_71 & V_159 )
goto V_97;
if ( F_9 ( V_57 ) ) {
V_90 = - V_165 ;
if ( ! V_156 )
goto V_97;
V_156 = F_120 ( V_57 , V_156 ) ;
V_90 = F_128 ( V_156 ) ;
if ( F_129 ( V_86 ) )
goto V_96;
F_61 ( V_57 ) ;
goto V_153;
}
V_163 = V_15 -> V_74 ;
switch ( V_163 ) {
case V_75 :
break;
case V_166 :
V_90 = - V_167 ;
goto V_97;
default:
V_90 = - V_27 ;
goto V_97;
}
F_115 ( V_15 ) ;
if ( V_15 -> V_74 != V_163 ) {
F_14 ( V_15 ) ;
F_14 ( V_57 ) ;
F_61 ( V_57 ) ;
goto V_153;
}
V_90 = F_130 ( V_15 , V_57 , V_162 ) ;
if ( V_90 ) {
F_14 ( V_15 ) ;
goto V_97;
}
F_13 ( V_15 ) ;
F_7 ( V_162 ) = V_15 ;
V_162 -> V_74 = V_166 ;
V_162 -> V_76 = V_15 -> V_76 ;
F_66 ( V_162 ) ;
V_160 = F_32 ( V_162 ) ;
F_131 ( V_162 -> V_50 , & V_160 -> V_168 ) ;
V_161 = F_32 ( V_57 ) ;
if ( V_161 -> V_2 ) {
F_132 ( & V_161 -> V_2 -> V_22 ) ;
V_160 -> V_2 = V_161 -> V_2 ;
}
if ( V_161 -> V_44 . V_43 ) {
F_133 ( & V_161 -> V_44 ) ;
V_160 -> V_44 = V_161 -> V_44 ;
}
F_72 ( V_15 , V_57 ) ;
V_14 -> V_70 = V_169 ;
V_15 -> V_74 = V_166 ;
F_13 ( V_162 ) ;
F_134 () ;
F_7 ( V_15 ) = V_162 ;
F_14 ( V_15 ) ;
F_27 ( & V_57 -> V_17 . V_104 ) ;
F_135 ( & V_57 -> V_17 , V_9 ) ;
F_28 ( & V_57 -> V_17 . V_104 ) ;
F_14 ( V_57 ) ;
V_57 -> V_170 ( V_57 , 0 ) ;
F_61 ( V_57 ) ;
return 0 ;
V_97:
if ( V_57 )
F_14 ( V_57 ) ;
V_96:
F_63 ( V_9 ) ;
if ( V_162 )
F_59 ( V_162 , 0 ) ;
if ( V_57 )
F_61 ( V_57 ) ;
return V_90 ;
}
static int F_136 ( struct V_88 * V_171 , struct V_88 * V_172 )
{
struct V_14 * V_173 = V_171 -> V_15 , * V_9 = V_172 -> V_15 ;
F_13 ( V_173 ) ;
F_13 ( V_9 ) ;
F_7 ( V_173 ) = V_9 ;
F_7 ( V_9 ) = V_173 ;
F_66 ( V_173 ) ;
F_66 ( V_9 ) ;
if ( V_173 -> V_76 != V_119 ) {
V_173 -> V_74 = V_166 ;
V_9 -> V_74 = V_166 ;
V_171 -> V_70 = V_169 ;
V_172 -> V_70 = V_169 ;
}
return 0 ;
}
static int F_137 ( struct V_88 * V_14 , struct V_88 * V_174 , int V_149 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_175 ;
struct V_8 * V_9 ;
int V_90 ;
V_90 = - V_95 ;
if ( V_14 -> type != V_77 && V_14 -> type != V_78 )
goto V_96;
V_90 = - V_27 ;
if ( V_15 -> V_74 != V_82 )
goto V_96;
V_9 = F_138 ( V_15 , 0 , V_149 & V_164 , & V_90 ) ;
if ( ! V_9 ) {
if ( V_90 == 0 )
V_90 = - V_27 ;
goto V_96;
}
V_175 = V_9 -> V_15 ;
F_139 ( V_15 , V_9 ) ;
F_140 ( & F_32 ( V_15 ) -> V_58 ) ;
F_12 ( V_175 ) ;
V_174 -> V_70 = V_169 ;
F_141 ( V_175 , V_174 ) ;
F_14 ( V_175 ) ;
return 0 ;
V_96:
return V_90 ;
}
static int F_142 ( struct V_88 * V_14 , struct V_138 * V_139 , int * V_176 , int V_20 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 ;
F_143 ( struct V_23 * , V_24 , V_139 ) ;
int V_90 = 0 ;
if ( V_20 ) {
V_15 = F_11 ( V_15 ) ;
V_90 = - V_177 ;
if ( ! V_15 )
goto V_96;
V_90 = 0 ;
} else {
F_13 ( V_15 ) ;
}
V_38 = F_32 ( V_15 ) ;
F_12 ( V_15 ) ;
if ( ! V_38 -> V_2 ) {
V_24 -> V_28 = V_29 ;
V_24 -> V_30 [ 0 ] = 0 ;
* V_176 = sizeof( short ) ;
} else {
struct V_21 * V_2 = V_38 -> V_2 ;
* V_176 = V_2 -> V_25 ;
memcpy ( V_24 , V_2 -> V_39 , * V_176 ) ;
}
F_14 ( V_15 ) ;
F_61 ( V_15 ) ;
V_96:
return V_90 ;
}
static void F_144 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_42 ;
V_7 -> V_178 = F_145 ( V_9 ) . V_178 ;
F_145 ( V_9 ) . V_178 = NULL ;
for ( V_42 = V_7 -> V_178 -> V_179 - 1 ; V_42 >= 0 ; V_42 -- )
F_146 ( V_7 -> V_178 -> V_178 [ V_42 ] ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_91 = F_145 ( V_9 ) . V_91 ;
V_7 . V_93 = F_145 ( V_9 ) . V_93 ;
if ( F_145 ( V_9 ) . V_178 )
F_144 ( & V_7 , V_9 ) ;
F_148 ( & V_7 ) ;
F_149 ( V_9 ) ;
}
static int F_150 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_42 ;
unsigned char V_180 = 0 ;
int V_181 = 0 ;
for ( V_42 = V_7 -> V_178 -> V_179 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_14 * V_15 = F_151 ( V_7 -> V_178 -> V_178 [ V_42 ] ) ;
if ( V_15 ) {
V_181 ++ ;
V_180 = F_152 ( V_180 ,
F_32 ( V_15 ) -> V_182 ) ;
}
}
if ( F_114 ( V_180 > V_183 ) )
return - V_184 ;
F_145 ( V_9 ) . V_178 = F_153 ( V_7 -> V_178 ) ;
if ( ! F_145 ( V_9 ) . V_178 )
return - V_123 ;
if ( V_181 ) {
for ( V_42 = V_7 -> V_178 -> V_179 - 1 ; V_42 >= 0 ; V_42 -- )
F_154 ( V_7 -> V_178 -> V_178 [ V_42 ] ) ;
}
return V_180 ;
}
static int F_155 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_185 )
{
int V_90 = 0 ;
F_145 ( V_9 ) . V_91 = F_69 ( V_7 -> V_91 ) ;
if ( V_7 -> V_93 )
F_145 ( V_9 ) . V_93 = F_73 ( V_7 -> V_93 ) ;
F_145 ( V_9 ) . V_178 = NULL ;
if ( V_7 -> V_178 && V_185 )
V_90 = F_150 ( V_7 , V_9 ) ;
V_9 -> V_186 = F_147 ;
return V_90 ;
}
static void F_156 ( struct V_8 * V_9 , const struct V_88 * V_14 ,
const struct V_14 * V_57 )
{
if ( F_145 ( V_9 ) . V_93 )
return;
if ( F_118 ( V_152 , & V_14 -> V_149 ) ||
! V_57 -> V_63 ||
F_118 ( V_152 , & V_57 -> V_63 -> V_149 ) ) {
F_145 ( V_9 ) . V_91 = F_69 ( F_70 ( V_86 ) ) ;
F_145 ( V_9 ) . V_93 = F_71 () ;
}
}
static int F_157 ( struct V_187 * V_187 , struct V_88 * V_14 ,
struct V_188 * V_189 , T_3 V_25 )
{
struct V_190 * V_191 = F_158 ( V_187 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_189 -> V_192 ;
struct V_14 * V_57 = NULL ;
int V_193 = 0 ;
int V_90 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_156 ;
struct V_6 V_194 ;
int V_180 ;
int V_195 = 0 ;
if ( NULL == V_191 -> V_7 )
V_191 -> V_7 = & V_194 ;
F_159 () ;
V_90 = F_160 ( V_14 , V_189 , V_191 -> V_7 , false ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = - V_95 ;
if ( V_189 -> V_196 & V_197 )
goto V_96;
if ( V_189 -> V_198 ) {
V_90 = F_18 ( V_24 , V_189 -> V_198 , & V_3 ) ;
if ( V_90 < 0 )
goto V_96;
V_193 = V_90 ;
} else {
V_24 = NULL ;
V_90 = - V_177 ;
V_57 = F_11 ( V_15 ) ;
if ( ! V_57 )
goto V_96;
}
if ( F_118 ( V_152 , & V_14 -> V_149 ) && ! V_38 -> V_2
&& ( V_90 = F_91 ( V_14 ) ) != 0 )
goto V_96;
V_90 = - V_199 ;
if ( V_25 > V_15 -> V_47 - 32 )
goto V_96;
if ( V_25 > V_200 )
V_195 = F_161 ( T_3 ,
V_25 - V_200 ,
V_201 * V_202 ) ;
V_9 = F_162 ( V_15 , V_25 - V_195 , V_195 ,
V_189 -> V_196 & V_203 , & V_90 ) ;
if ( V_9 == NULL )
goto V_96;
V_90 = F_155 ( V_191 -> V_7 , V_9 , true ) ;
if ( V_90 < 0 )
goto V_204;
V_180 = V_90 + 1 ;
F_2 ( V_191 -> V_7 , V_9 ) ;
F_163 ( V_9 , V_25 - V_195 ) ;
V_9 -> V_195 = V_195 ;
V_9 -> V_25 = V_25 ;
V_90 = F_164 ( V_9 , 0 , V_189 -> V_205 , 0 , V_25 ) ;
if ( V_90 )
goto V_204;
V_156 = F_126 ( V_15 , V_189 -> V_196 & V_203 ) ;
V_153:
if ( ! V_57 ) {
V_90 = - V_61 ;
if ( V_24 == NULL )
goto V_204;
V_57 = F_95 ( V_33 , V_24 , V_193 , V_15 -> V_76 ,
V_3 , & V_90 ) ;
if ( V_57 == NULL )
goto V_204;
}
if ( F_165 ( V_57 , V_9 ) < 0 ) {
V_90 = V_25 ;
goto V_204;
}
F_12 ( V_57 ) ;
V_90 = - V_154 ;
if ( ! F_8 ( V_15 , V_57 ) )
goto V_97;
if ( F_50 ( V_57 , V_59 ) ) {
F_14 ( V_57 ) ;
F_61 ( V_57 ) ;
V_90 = 0 ;
F_12 ( V_15 ) ;
if ( F_7 ( V_15 ) == V_57 ) {
F_7 ( V_15 ) = NULL ;
F_14 ( V_15 ) ;
F_46 ( V_15 , V_57 ) ;
F_61 ( V_57 ) ;
V_90 = - V_132 ;
} else {
F_14 ( V_15 ) ;
}
V_57 = NULL ;
if ( V_90 )
goto V_204;
goto V_153;
}
V_90 = - V_206 ;
if ( V_57 -> V_71 & V_159 )
goto V_97;
if ( V_15 -> V_76 != V_78 ) {
V_90 = F_119 ( V_15 -> V_63 , V_57 -> V_63 ) ;
if ( V_90 )
goto V_97;
}
if ( F_7 ( V_57 ) != V_15 && F_9 ( V_57 ) ) {
if ( ! V_156 ) {
V_90 = - V_165 ;
goto V_97;
}
V_156 = F_120 ( V_57 , V_156 ) ;
V_90 = F_128 ( V_156 ) ;
if ( F_129 ( V_86 ) )
goto V_204;
goto V_153;
}
if ( F_50 ( V_57 , V_207 ) )
F_166 ( V_9 ) ;
F_156 ( V_9 , V_14 , V_57 ) ;
F_167 ( & V_57 -> V_17 , V_9 ) ;
if ( V_180 > F_32 ( V_57 ) -> V_182 )
F_32 ( V_57 ) -> V_182 = V_180 ;
F_14 ( V_57 ) ;
V_57 -> V_170 ( V_57 , V_25 ) ;
F_61 ( V_57 ) ;
F_148 ( V_191 -> V_7 ) ;
return V_25 ;
V_97:
F_14 ( V_57 ) ;
V_204:
F_63 ( V_9 ) ;
V_96:
if ( V_57 )
F_61 ( V_57 ) ;
F_148 ( V_191 -> V_7 ) ;
return V_90 ;
}
static int F_168 ( struct V_187 * V_187 , struct V_88 * V_14 ,
struct V_188 * V_189 , T_3 V_25 )
{
struct V_190 * V_191 = F_158 ( V_187 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_57 = NULL ;
int V_90 , V_208 ;
struct V_8 * V_9 ;
int V_209 = 0 ;
struct V_6 V_194 ;
bool V_210 = false ;
int V_180 ;
if ( NULL == V_191 -> V_7 )
V_191 -> V_7 = & V_194 ;
F_159 () ;
V_90 = F_160 ( V_14 , V_189 , V_191 -> V_7 , false ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = - V_95 ;
if ( V_189 -> V_196 & V_197 )
goto V_211;
if ( V_189 -> V_198 ) {
V_90 = V_15 -> V_74 == V_166 ? - V_167 : - V_95 ;
goto V_211;
} else {
V_90 = - V_177 ;
V_57 = F_7 ( V_15 ) ;
if ( ! V_57 )
goto V_211;
}
if ( V_15 -> V_71 & V_212 )
goto V_213;
while ( V_209 < V_25 ) {
V_208 = V_25 - V_209 ;
if ( V_208 > ( ( V_15 -> V_47 >> 1 ) - 64 ) )
V_208 = ( V_15 -> V_47 >> 1 ) - 64 ;
if ( V_208 > V_200 )
V_208 = V_200 ;
V_9 = F_169 ( V_15 , V_208 , V_189 -> V_196 & V_203 ,
& V_90 ) ;
if ( V_9 == NULL )
goto V_211;
V_208 = F_161 ( int , V_208 , F_170 ( V_9 ) ) ;
V_90 = F_155 ( V_191 -> V_7 , V_9 , ! V_210 ) ;
if ( V_90 < 0 ) {
F_63 ( V_9 ) ;
goto V_211;
}
V_180 = V_90 + 1 ;
V_210 = true ;
V_90 = F_171 ( F_163 ( V_9 , V_208 ) , V_189 -> V_205 , V_208 ) ;
if ( V_90 ) {
F_63 ( V_9 ) ;
goto V_211;
}
F_12 ( V_57 ) ;
if ( F_50 ( V_57 , V_59 ) ||
( V_57 -> V_71 & V_159 ) )
goto V_214;
F_156 ( V_9 , V_14 , V_57 ) ;
F_167 ( & V_57 -> V_17 , V_9 ) ;
if ( V_180 > F_32 ( V_57 ) -> V_182 )
F_32 ( V_57 ) -> V_182 = V_180 ;
F_14 ( V_57 ) ;
V_57 -> V_170 ( V_57 , V_208 ) ;
V_209 += V_208 ;
}
F_148 ( V_191 -> V_7 ) ;
V_191 -> V_7 = NULL ;
return V_209 ;
V_214:
F_14 ( V_57 ) ;
F_63 ( V_9 ) ;
V_213:
if ( V_209 == 0 && ! ( V_189 -> V_196 & V_215 ) )
F_172 ( V_216 , V_86 , 0 ) ;
V_90 = - V_206 ;
V_211:
F_148 ( V_191 -> V_7 ) ;
V_191 -> V_7 = NULL ;
return V_209 ? : V_90 ;
}
static int F_173 ( struct V_187 * V_187 , struct V_88 * V_14 ,
struct V_188 * V_189 , T_3 V_25 )
{
int V_90 ;
struct V_14 * V_15 = V_14 -> V_15 ;
V_90 = F_174 ( V_15 ) ;
if ( V_90 )
return V_90 ;
if ( V_15 -> V_74 != V_166 )
return - V_177 ;
if ( V_189 -> V_198 )
V_189 -> V_198 = 0 ;
return F_157 ( V_187 , V_14 , V_189 , V_25 ) ;
}
static int F_175 ( struct V_187 * V_217 , struct V_88 * V_14 ,
struct V_188 * V_189 , T_3 V_208 ,
int V_149 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( V_15 -> V_74 != V_166 )
return - V_177 ;
return F_176 ( V_217 , V_14 , V_189 , V_208 , V_149 ) ;
}
static void F_177 ( struct V_188 * V_189 , struct V_14 * V_15 )
{
struct V_37 * V_38 = F_32 ( V_15 ) ;
V_189 -> V_198 = 0 ;
if ( V_38 -> V_2 ) {
V_189 -> V_198 = V_38 -> V_2 -> V_25 ;
memcpy ( V_189 -> V_192 , V_38 -> V_2 -> V_39 , V_38 -> V_2 -> V_25 ) ;
}
}
static int F_176 ( struct V_187 * V_217 , struct V_88 * V_14 ,
struct V_188 * V_189 , T_3 V_208 ,
int V_149 )
{
struct V_190 * V_191 = F_158 ( V_217 ) ;
struct V_6 V_194 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
int V_218 = V_149 & V_203 ;
struct V_8 * V_9 ;
int V_90 ;
int V_219 , V_220 ;
V_90 = - V_95 ;
if ( V_149 & V_197 )
goto V_96;
V_189 -> V_198 = 0 ;
V_90 = F_178 ( & V_38 -> V_99 ) ;
if ( V_90 ) {
V_90 = F_128 ( F_179 ( V_15 , V_218 ) ) ;
goto V_96;
}
V_220 = F_180 ( V_15 , V_149 ) ;
V_9 = F_181 ( V_15 , V_149 , & V_219 , & V_220 , & V_90 ) ;
if ( ! V_9 ) {
F_12 ( V_15 ) ;
if ( V_15 -> V_76 == V_78 && V_90 == - V_165 &&
( V_15 -> V_71 & V_159 ) )
V_90 = 0 ;
F_14 ( V_15 ) ;
goto V_97;
}
F_43 ( & V_38 -> V_58 ,
V_52 | V_53 | V_54 ) ;
if ( V_189 -> V_192 )
F_177 ( V_189 , V_9 -> V_15 ) ;
if ( V_208 > V_9 -> V_25 - V_220 )
V_208 = V_9 -> V_25 - V_220 ;
else if ( V_208 < V_9 -> V_25 - V_220 )
V_189 -> V_196 |= V_221 ;
V_90 = F_182 ( V_9 , V_220 , V_189 -> V_205 , V_208 ) ;
if ( V_90 )
goto V_204;
if ( F_50 ( V_15 , V_207 ) )
F_183 ( V_189 , V_15 , V_9 ) ;
if ( ! V_191 -> V_7 ) {
V_191 -> V_7 = & V_194 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
}
F_184 ( V_191 -> V_7 , F_145 ( V_9 ) . V_91 , F_145 ( V_9 ) . V_93 ) ;
F_4 ( V_191 -> V_7 , V_9 ) ;
if ( ! ( V_149 & V_222 ) ) {
if ( F_145 ( V_9 ) . V_178 )
F_144 ( V_191 -> V_7 , V_9 ) ;
F_185 ( V_15 , V_9 -> V_25 ) ;
} else {
F_186 ( V_15 , V_208 ) ;
if ( F_145 ( V_9 ) . V_178 )
V_191 -> V_7 -> V_178 = F_153 ( F_145 ( V_9 ) . V_178 ) ;
}
V_90 = ( V_149 & V_221 ) ? V_9 -> V_25 - V_220 : V_208 ;
F_187 ( V_14 , V_189 , V_191 -> V_7 , V_149 ) ;
V_204:
F_139 ( V_15 , V_9 ) ;
V_97:
F_77 ( & V_38 -> V_99 ) ;
V_96:
return V_90 ;
}
static long F_188 ( struct V_14 * V_15 , long V_156 )
{
F_121 ( V_51 ) ;
F_12 ( V_15 ) ;
for (; ; ) {
F_189 ( F_190 ( V_15 ) , & V_51 , V_158 ) ;
if ( ! F_47 ( & V_15 -> V_17 ) ||
V_15 -> V_60 ||
( V_15 -> V_71 & V_159 ) ||
F_129 ( V_86 ) ||
! V_156 )
break;
F_191 ( V_223 , & V_15 -> V_63 -> V_149 ) ;
F_14 ( V_15 ) ;
V_156 = F_123 ( V_156 ) ;
F_12 ( V_15 ) ;
F_192 ( V_223 , & V_15 -> V_63 -> V_149 ) ;
}
F_124 ( F_190 ( V_15 ) , & V_51 ) ;
F_14 ( V_15 ) ;
return V_156 ;
}
static int F_193 ( struct V_187 * V_217 , struct V_88 * V_14 ,
struct V_188 * V_189 , T_3 V_208 ,
int V_149 )
{
struct V_190 * V_191 = F_158 ( V_217 ) ;
struct V_6 V_194 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_189 -> V_192 ;
int V_224 = 0 ;
int V_225 = 0 ;
int V_226 ;
int V_90 = 0 ;
long V_156 ;
int V_220 ;
V_90 = - V_27 ;
if ( V_15 -> V_74 != V_166 )
goto V_96;
V_90 = - V_95 ;
if ( V_149 & V_197 )
goto V_96;
V_226 = F_194 ( V_15 , V_149 & V_227 , V_208 ) ;
V_156 = F_179 ( V_15 , V_149 & V_203 ) ;
V_189 -> V_198 = 0 ;
if ( ! V_191 -> V_7 ) {
V_191 -> V_7 = & V_194 ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
}
V_90 = F_178 ( & V_38 -> V_99 ) ;
if ( V_90 ) {
V_90 = F_128 ( V_156 ) ;
goto V_96;
}
V_220 = F_180 ( V_15 , V_149 ) ;
do {
int V_228 ;
struct V_8 * V_9 ;
F_12 ( V_15 ) ;
V_9 = F_195 ( & V_15 -> V_17 ) ;
V_229:
if ( V_9 == NULL ) {
F_32 ( V_15 ) -> V_182 = 0 ;
if ( V_224 >= V_226 )
goto V_230;
V_90 = F_174 ( V_15 ) ;
if ( V_90 )
goto V_230;
if ( V_15 -> V_71 & V_159 )
goto V_230;
F_14 ( V_15 ) ;
V_90 = - V_165 ;
if ( ! V_156 )
break;
F_77 ( & V_38 -> V_99 ) ;
V_156 = F_188 ( V_15 , V_156 ) ;
if ( F_129 ( V_86 )
|| F_178 ( & V_38 -> V_99 ) ) {
V_90 = F_128 ( V_156 ) ;
goto V_96;
}
continue;
V_230:
F_14 ( V_15 ) ;
break;
}
if ( V_220 >= V_9 -> V_25 ) {
V_220 -= V_9 -> V_25 ;
V_9 = F_196 ( V_9 , & V_15 -> V_17 ) ;
goto V_229;
}
F_14 ( V_15 ) ;
if ( V_225 ) {
if ( ( F_145 ( V_9 ) . V_91 != V_191 -> V_7 -> V_91 ) ||
( F_145 ( V_9 ) . V_93 != V_191 -> V_7 -> V_93 ) )
break;
} else {
F_184 ( V_191 -> V_7 , F_145 ( V_9 ) . V_91 , F_145 ( V_9 ) . V_93 ) ;
V_225 = 1 ;
}
if ( V_24 ) {
F_177 ( V_189 , V_9 -> V_15 ) ;
V_24 = NULL ;
}
V_228 = F_161 (unsigned int, skb->len - skip, size) ;
if ( F_197 ( V_189 -> V_205 , V_9 -> V_231 + V_220 , V_228 ) ) {
if ( V_224 == 0 )
V_224 = - V_232 ;
break;
}
V_224 += V_228 ;
V_208 -= V_228 ;
if ( ! ( V_149 & V_222 ) ) {
F_198 ( V_9 , V_228 ) ;
F_185 ( V_15 , V_228 ) ;
if ( F_145 ( V_9 ) . V_178 )
F_144 ( V_191 -> V_7 , V_9 ) ;
if ( V_9 -> V_25 )
break;
F_199 ( V_9 , & V_15 -> V_17 ) ;
F_200 ( V_9 ) ;
if ( V_191 -> V_7 -> V_178 )
break;
} else {
if ( F_145 ( V_9 ) . V_178 )
V_191 -> V_7 -> V_178 = F_153 ( F_145 ( V_9 ) . V_178 ) ;
F_186 ( V_15 , V_228 ) ;
break;
}
} while ( V_208 );
F_77 ( & V_38 -> V_99 ) ;
F_187 ( V_14 , V_189 , V_191 -> V_7 , V_149 ) ;
V_96:
return V_224 ? : V_90 ;
}
static int F_201 ( struct V_88 * V_14 , int V_135 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_57 ;
V_135 = ( V_135 + 1 ) & ( V_159 | V_212 ) ;
if ( ! V_135 )
return 0 ;
F_12 ( V_15 ) ;
V_15 -> V_71 |= V_135 ;
V_57 = F_7 ( V_15 ) ;
if ( V_57 )
F_13 ( V_57 ) ;
F_14 ( V_15 ) ;
V_15 -> V_79 ( V_15 ) ;
if ( V_57 &&
( V_15 -> V_76 == V_77 || V_15 -> V_76 == V_78 ) ) {
int V_233 = 0 ;
if ( V_135 & V_159 )
V_233 |= V_212 ;
if ( V_135 & V_212 )
V_233 |= V_159 ;
F_12 ( V_57 ) ;
V_57 -> V_71 |= V_233 ;
F_14 ( V_57 ) ;
V_57 -> V_79 ( V_57 ) ;
if ( V_233 == V_72 )
F_44 ( V_57 , V_80 , V_81 ) ;
else if ( V_233 & V_159 )
F_44 ( V_57 , V_80 , V_234 ) ;
}
if ( V_57 )
F_61 ( V_57 ) ;
return 0 ;
}
long F_202 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
long V_235 = 0 ;
if ( V_15 -> V_74 == V_82 )
return - V_27 ;
F_27 ( & V_15 -> V_17 . V_104 ) ;
if ( V_15 -> V_76 == V_77 ||
V_15 -> V_76 == V_78 ) {
F_203 (&sk->sk_receive_queue, skb)
V_235 += V_9 -> V_25 ;
} else {
V_9 = F_195 ( & V_15 -> V_17 ) ;
if ( V_9 )
V_235 = V_9 -> V_25 ;
}
F_28 ( & V_15 -> V_17 . V_104 ) ;
return V_235 ;
}
long F_204 ( struct V_14 * V_15 )
{
return F_205 ( V_15 ) ;
}
static int F_206 ( struct V_88 * V_14 , unsigned int V_236 , unsigned long V_237 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
long V_235 = 0 ;
int V_90 ;
switch ( V_236 ) {
case V_238 :
V_235 = F_204 ( V_15 ) ;
V_90 = F_207 ( V_235 , ( int V_239 * ) V_237 ) ;
break;
case V_240 :
V_235 = F_202 ( V_15 ) ;
if ( V_235 < 0 )
V_90 = V_235 ;
else
V_90 = F_207 ( V_235 , ( int V_239 * ) V_237 ) ;
break;
default:
V_90 = - V_241 ;
break;
}
return V_90 ;
}
static unsigned int F_208 ( struct V_242 * V_242 , struct V_88 * V_14 , T_4 * V_51 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
unsigned int V_243 ;
F_209 ( V_242 , F_190 ( V_15 ) , V_51 ) ;
V_243 = 0 ;
if ( V_15 -> V_60 )
V_243 |= V_244 ;
if ( V_15 -> V_71 == V_72 )
V_243 |= V_245 ;
if ( V_15 -> V_71 & V_159 )
V_243 |= V_246 | V_247 | V_248 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_243 |= V_247 | V_248 ;
if ( ( V_15 -> V_76 == V_77 || V_15 -> V_76 == V_78 ) &&
V_15 -> V_74 == V_75 )
V_243 |= V_245 ;
if ( F_37 ( V_15 ) )
V_243 |= V_52 | V_53 | V_54 ;
return V_243 ;
}
static unsigned int F_210 ( struct V_242 * V_242 , struct V_88 * V_14 ,
T_4 * V_51 )
{
struct V_14 * V_15 = V_14 -> V_15 , * V_57 ;
unsigned int V_243 , V_249 ;
F_209 ( V_242 , F_190 ( V_15 ) , V_51 ) ;
V_243 = 0 ;
if ( V_15 -> V_60 || ! F_47 ( & V_15 -> V_250 ) )
V_243 |= V_244 ;
if ( V_15 -> V_71 & V_159 )
V_243 |= V_246 | V_247 | V_248 ;
if ( V_15 -> V_71 == V_72 )
V_243 |= V_245 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_243 |= V_247 | V_248 ;
if ( V_15 -> V_76 == V_78 ) {
if ( V_15 -> V_74 == V_75 )
V_243 |= V_245 ;
if ( V_15 -> V_74 == V_251 )
return V_243 ;
}
if ( ! ( F_211 ( V_51 ) & ( V_54 | V_53 | V_52 ) ) )
return V_243 ;
V_249 = F_37 ( V_15 ) ;
V_57 = F_11 ( V_15 ) ;
if ( V_57 ) {
if ( F_7 ( V_57 ) != V_15 ) {
F_209 ( V_242 , & F_32 ( V_57 ) -> V_58 , V_51 ) ;
if ( F_9 ( V_57 ) )
V_249 = 0 ;
}
F_61 ( V_57 ) ;
}
if ( V_249 )
V_243 |= V_52 | V_53 | V_54 ;
else
F_191 ( V_252 , & V_15 -> V_63 -> V_149 ) ;
return V_243 ;
}
static struct V_14 * F_212 ( struct V_253 * V_254 , T_5 * V_255 )
{
unsigned long V_256 = F_213 ( * V_255 ) ;
unsigned long V_257 = F_214 ( * V_255 ) ;
struct V_14 * V_15 ;
unsigned long V_179 = 0 ;
for ( V_15 = F_215 ( & V_5 [ V_257 ] ) ; V_15 ; V_15 = F_216 ( V_15 ) ) {
if ( F_34 ( V_15 ) != F_217 ( V_254 ) )
continue;
if ( ++ V_179 == V_256 )
break;
}
return V_15 ;
}
static struct V_14 * F_218 ( struct V_253 * V_254 ,
struct V_14 * V_15 ,
T_5 * V_255 )
{
unsigned long V_257 ;
while ( V_15 > (struct V_14 * ) V_258 ) {
V_15 = F_216 ( V_15 ) ;
if ( ! V_15 )
goto V_259;
if ( F_34 ( V_15 ) == F_217 ( V_254 ) )
return V_15 ;
}
do {
V_15 = F_212 ( V_254 , V_255 ) ;
if ( V_15 )
return V_15 ;
V_259:
V_257 = F_214 ( * V_255 ) + 1 ;
* V_255 = F_219 ( V_257 , 1 ) ;
} while ( V_257 < F_220 ( V_5 ) );
return NULL ;
}
static void * F_221 ( struct V_253 * V_254 , T_5 * V_255 )
__acquires( V_32 )
{
F_27 ( & V_32 ) ;
if ( ! * V_255 )
return V_258 ;
if ( F_214 ( * V_255 ) >= F_220 ( V_5 ) )
return NULL ;
return F_218 ( V_254 , NULL , V_255 ) ;
}
static void * F_222 ( struct V_253 * V_254 , void * V_260 , T_5 * V_255 )
{
++ * V_255 ;
return F_218 ( V_254 , V_260 , V_255 ) ;
}
static void F_223 ( struct V_253 * V_254 , void * V_260 )
__releases( V_32 )
{
F_28 ( & V_32 ) ;
}
static int F_224 ( struct V_253 * V_254 , void * V_260 )
{
if ( V_260 == V_258 )
F_225 ( V_254 , L_4
L_5 ) ;
else {
struct V_14 * V_19 = V_260 ;
struct V_37 * V_38 = F_32 ( V_19 ) ;
F_12 ( V_19 ) ;
F_226 ( V_254 , L_6 ,
V_19 ,
F_38 ( & V_19 -> V_261 ) ,
0 ,
V_19 -> V_74 == V_82 ? V_262 : 0 ,
V_19 -> V_76 ,
V_19 -> V_63 ?
( V_19 -> V_74 == V_166 ? V_169 : V_115 ) :
( V_19 -> V_74 == V_166 ? V_263 : V_264 ) ,
F_227 ( V_19 ) ) ;
if ( V_38 -> V_2 ) {
int V_42 , V_25 ;
F_228 ( V_254 , ' ' ) ;
V_42 = 0 ;
V_25 = V_38 -> V_2 -> V_25 - sizeof( short ) ;
if ( ! F_229 ( V_19 ) )
V_25 -- ;
else {
F_228 ( V_254 , '@' ) ;
V_42 ++ ;
}
for ( ; V_42 < V_25 ; V_42 ++ )
F_228 ( V_254 , V_38 -> V_2 -> V_39 -> V_30 [ V_42 ] ) ;
}
F_14 ( V_19 ) ;
F_228 ( V_254 , '\n' ) ;
}
return 0 ;
}
static int F_230 ( struct V_41 * V_41 , struct V_242 * V_242 )
{
return F_231 ( V_41 , V_242 , & V_265 ,
sizeof( struct V_266 ) ) ;
}
static int T_6 F_232 ( struct V_33 * V_33 )
{
int error = - V_123 ;
V_33 -> V_107 . V_108 = 10 ;
if ( F_233 ( V_33 ) )
goto V_96;
#ifdef F_234
if ( ! F_235 ( V_33 , L_7 , 0 , & V_267 ) ) {
F_236 ( V_33 ) ;
goto V_96;
}
#endif
error = 0 ;
V_96:
return error ;
}
static void T_7 F_237 ( struct V_33 * V_33 )
{
F_236 ( V_33 ) ;
F_238 ( V_33 , L_7 ) ;
}
static int T_8 F_239 ( void )
{
int V_268 = - 1 ;
struct V_8 * V_269 ;
F_240 ( sizeof( struct V_270 ) > sizeof( V_269 -> V_271 ) ) ;
V_268 = F_241 ( & V_103 , 1 ) ;
if ( V_268 != 0 ) {
F_52 ( V_272 L_8 ,
V_273 ) ;
goto V_96;
}
F_242 ( & V_274 ) ;
F_243 ( & V_275 ) ;
V_96:
return V_268 ;
}
static void T_9 F_244 ( void )
{
F_245 ( V_101 ) ;
F_246 ( & V_103 ) ;
F_247 ( & V_275 ) ;
}
