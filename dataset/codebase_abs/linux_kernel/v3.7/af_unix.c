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
V_90 = - V_93 ;
if ( V_14 -> type != V_77 && V_14 -> type != V_78 )
goto V_94;
V_90 = - V_27 ;
if ( ! V_38 -> V_2 )
goto V_94;
F_12 ( V_15 ) ;
if ( V_15 -> V_74 != V_75 && V_15 -> V_74 != V_82 )
goto V_95;
if ( V_89 > V_15 -> V_18 )
F_49 ( & V_38 -> V_58 ) ;
V_15 -> V_18 = V_89 ;
V_15 -> V_74 = V_82 ;
F_66 ( V_15 ) ;
V_90 = 0 ;
V_95:
F_14 ( V_15 ) ;
F_67 ( V_92 ) ;
V_94:
return V_90 ;
}
static void F_75 ( struct V_14 * V_15 , int V_96 )
{
struct V_37 * V_38 = F_32 ( V_15 ) ;
F_76 ( & V_38 -> V_97 ) ;
V_15 -> V_98 = V_96 ;
F_77 ( & V_38 -> V_97 ) ;
}
static struct V_14 * F_78 ( struct V_33 * V_33 , struct V_88 * V_14 )
{
struct V_14 * V_15 = NULL ;
struct V_37 * V_38 ;
F_79 ( & V_65 ) ;
if ( F_58 ( & V_65 ) > 2 * F_80 () )
goto V_94;
V_15 = F_81 ( V_33 , V_99 , V_100 , & V_101 ) ;
if ( ! V_15 )
goto V_94;
F_82 ( V_14 , V_15 ) ;
F_83 ( & V_15 -> V_17 . V_102 ,
& V_103 ) ;
V_15 -> V_104 = F_39 ;
V_15 -> V_18 = V_33 -> V_105 . V_106 ;
V_15 -> V_107 = F_51 ;
V_38 = F_32 ( V_15 ) ;
V_38 -> V_44 . V_43 = NULL ;
V_38 -> V_44 . V_73 = NULL ;
F_84 ( & V_38 -> V_102 ) ;
F_85 ( & V_38 -> V_108 , 0 ) ;
F_86 ( & V_38 -> V_109 ) ;
F_87 ( & V_38 -> V_97 ) ;
F_88 ( & V_38 -> V_58 ) ;
F_29 ( F_1 ( V_15 ) , V_15 ) ;
V_94:
if ( V_15 == NULL )
F_53 ( & V_65 ) ;
else {
F_54 () ;
F_55 ( F_34 ( V_15 ) , V_15 -> V_66 , 1 ) ;
F_56 () ;
}
return V_15 ;
}
static int F_89 ( struct V_33 * V_33 , struct V_88 * V_14 , int V_110 ,
int V_111 )
{
if ( V_110 && V_110 != V_99 )
return - V_112 ;
V_14 -> V_70 = V_113 ;
switch ( V_14 -> type ) {
case V_77 :
V_14 -> V_114 = & V_115 ;
break;
case V_116 :
V_14 -> type = V_117 ;
case V_117 :
V_14 -> V_114 = & V_118 ;
break;
case V_78 :
V_14 -> V_114 = & V_119 ;
break;
default:
return - V_120 ;
}
return F_78 ( V_33 , V_14 ) ? 0 : - V_121 ;
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
static V_11 V_122 = 1 ;
struct V_21 * V_2 ;
int V_90 ;
unsigned int V_123 = 0 ;
F_76 ( & V_38 -> V_97 ) ;
V_90 = 0 ;
if ( V_38 -> V_2 )
goto V_94;
V_90 = - V_121 ;
V_2 = F_92 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_100 ) ;
if ( ! V_2 )
goto V_94;
V_2 -> V_39 -> V_28 = V_29 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
V_124:
V_2 -> V_25 = sprintf ( V_2 -> V_39 -> V_30 + 1 , L_3 , V_122 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_5 ( F_19 ( V_2 -> V_39 , V_2 -> V_25 , 0 ) ) ;
F_27 ( & V_32 ) ;
V_122 = ( V_122 + 1 ) & 0xFFFFF ;
if ( F_30 ( V_33 , V_2 -> V_39 , V_2 -> V_25 , V_14 -> type ,
V_2 -> V_3 ) ) {
F_28 ( & V_32 ) ;
F_94 () ;
if ( V_123 ++ == 0xFFFFF ) {
V_90 = - V_125 ;
F_17 ( V_2 ) ;
goto V_94;
}
goto V_124;
}
V_2 -> V_3 ^= V_15 -> V_76 ;
F_20 ( V_15 ) ;
V_38 -> V_2 = V_2 ;
F_22 ( & V_5 [ V_2 -> V_3 ] , V_15 ) ;
F_28 ( & V_32 ) ;
V_90 = 0 ;
V_94: F_77 ( & V_38 -> V_97 ) ;
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
V_90 = F_96 ( V_34 -> V_30 , V_126 , & V_44 ) ;
if ( V_90 )
goto V_127;
V_41 = V_44 . V_43 -> V_45 ;
V_90 = F_97 ( V_41 , V_128 ) ;
if ( V_90 )
goto V_129;
V_90 = - V_130 ;
if ( ! F_98 ( V_41 -> V_131 ) )
goto V_129;
V_38 = F_36 ( V_41 ) ;
if ( ! V_38 )
goto V_129;
if ( V_38 -> V_76 == type )
F_99 ( & V_44 ) ;
F_64 ( & V_44 ) ;
V_90 = - V_132 ;
if ( V_38 -> V_76 != type ) {
F_61 ( V_38 ) ;
goto V_127;
}
} else {
V_90 = - V_130 ;
V_38 = F_35 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_38 ) {
struct V_43 * V_43 ;
V_43 = F_32 ( V_38 ) -> V_44 . V_43 ;
if ( V_43 )
F_99 ( & F_32 ( V_38 ) -> V_44 ) ;
} else
goto V_127;
}
return V_38 ;
V_129:
F_64 ( & V_44 ) ;
V_127:
* error = V_90 ;
return NULL ;
}
static int F_100 ( const char * V_30 , T_2 V_133 , struct V_44 * V_134 )
{
struct V_43 * V_43 ;
struct V_44 V_44 ;
int V_90 = 0 ;
V_43 = F_101 ( V_135 , V_30 , & V_44 , 0 ) ;
V_90 = F_102 ( V_43 ) ;
if ( F_103 ( V_43 ) )
return V_90 ;
V_90 = F_104 ( & V_44 , V_43 , V_133 , 0 ) ;
if ( ! V_90 ) {
V_90 = F_105 ( V_44 . V_43 -> V_45 , V_43 , V_133 , 0 ) ;
if ( ! V_90 ) {
V_134 -> V_73 = F_106 ( V_44 . V_73 ) ;
V_134 -> V_43 = F_107 ( V_43 ) ;
}
}
F_108 ( & V_44 , V_43 ) ;
return V_90 ;
}
static int F_109 ( struct V_88 * V_14 , struct V_136 * V_137 , int V_138 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_137 ;
char * V_30 = V_24 -> V_30 ;
int V_90 ;
unsigned int V_3 ;
struct V_21 * V_2 ;
struct V_1 * V_31 ;
V_90 = - V_27 ;
if ( V_24 -> V_28 != V_29 )
goto V_94;
if ( V_138 == sizeof( short ) ) {
V_90 = F_91 ( V_14 ) ;
goto V_94;
}
V_90 = F_18 ( V_24 , V_138 , & V_3 ) ;
if ( V_90 < 0 )
goto V_94;
V_138 = V_90 ;
F_76 ( & V_38 -> V_97 ) ;
V_90 = - V_27 ;
if ( V_38 -> V_2 )
goto V_139;
V_90 = - V_121 ;
V_2 = F_110 ( sizeof( * V_2 ) + V_138 , V_100 ) ;
if ( ! V_2 )
goto V_139;
memcpy ( V_2 -> V_39 , V_24 , V_138 ) ;
V_2 -> V_25 = V_138 ;
V_2 -> V_3 = V_3 ^ V_15 -> V_76 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
if ( V_30 [ 0 ] ) {
struct V_44 V_44 ;
T_2 V_133 = V_140 |
( F_111 ( V_14 ) -> V_131 & ~ F_112 () ) ;
V_90 = F_100 ( V_30 , V_133 , & V_44 ) ;
if ( V_90 ) {
if ( V_90 == - V_141 )
V_90 = - V_142 ;
F_15 ( V_2 ) ;
goto V_139;
}
V_2 -> V_3 = V_4 ;
V_3 = V_44 . V_43 -> V_45 -> V_143 & ( V_4 - 1 ) ;
F_27 ( & V_32 ) ;
V_38 -> V_44 = V_44 ;
V_31 = & V_5 [ V_3 ] ;
} else {
F_27 ( & V_32 ) ;
V_90 = - V_142 ;
if ( F_30 ( V_33 , V_24 , V_138 ,
V_15 -> V_76 , V_3 ) ) {
F_15 ( V_2 ) ;
goto V_95;
}
V_31 = & V_5 [ V_2 -> V_3 ] ;
}
V_90 = 0 ;
F_20 ( V_15 ) ;
V_38 -> V_2 = V_2 ;
F_22 ( V_31 , V_15 ) ;
V_95:
F_28 ( & V_32 ) ;
V_139:
F_77 ( & V_38 -> V_97 ) ;
V_94:
return V_90 ;
}
static void F_113 ( struct V_14 * V_144 , struct V_14 * V_145 )
{
if ( F_114 ( V_144 == V_145 ) || ! V_145 ) {
F_12 ( V_144 ) ;
return;
}
if ( V_144 < V_145 ) {
F_12 ( V_144 ) ;
F_115 ( V_145 ) ;
} else {
F_12 ( V_145 ) ;
F_115 ( V_144 ) ;
}
}
static void F_116 ( struct V_14 * V_144 , struct V_14 * V_145 )
{
if ( F_114 ( V_144 == V_145 ) || ! V_145 ) {
F_14 ( V_144 ) ;
return;
}
F_14 ( V_144 ) ;
F_14 ( V_145 ) ;
}
static int F_117 ( struct V_88 * V_14 , struct V_136 * V_2 ,
int V_146 , int V_147 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_2 ;
struct V_14 * V_57 ;
unsigned int V_3 ;
int V_90 ;
if ( V_2 -> V_148 != V_149 ) {
V_90 = F_18 ( V_24 , V_146 , & V_3 ) ;
if ( V_90 < 0 )
goto V_94;
V_146 = V_90 ;
if ( F_118 ( V_150 , & V_14 -> V_147 ) &&
! F_32 ( V_15 ) -> V_2 && ( V_90 = F_91 ( V_14 ) ) != 0 )
goto V_94;
V_151:
V_57 = F_95 ( V_33 , V_24 , V_146 , V_14 -> type , V_3 , & V_90 ) ;
if ( ! V_57 )
goto V_94;
F_113 ( V_15 , V_57 ) ;
if ( F_50 ( V_57 , V_59 ) ) {
F_116 ( V_15 , V_57 ) ;
F_61 ( V_57 ) ;
goto V_151;
}
V_90 = - V_152 ;
if ( ! F_8 ( V_15 , V_57 ) )
goto V_95;
V_90 = F_119 ( V_15 -> V_63 , V_57 -> V_63 ) ;
if ( V_90 )
goto V_95;
} else {
V_57 = NULL ;
F_113 ( V_15 , V_57 ) ;
}
if ( F_7 ( V_15 ) ) {
struct V_14 * V_153 = F_7 ( V_15 ) ;
F_7 ( V_15 ) = V_57 ;
F_116 ( V_15 , V_57 ) ;
if ( V_57 != V_153 )
F_46 ( V_15 , V_153 ) ;
F_61 ( V_153 ) ;
} else {
F_7 ( V_15 ) = V_57 ;
F_116 ( V_15 , V_57 ) ;
}
return 0 ;
V_95:
F_116 ( V_15 , V_57 ) ;
F_61 ( V_57 ) ;
V_94:
return V_90 ;
}
static long F_120 ( struct V_14 * V_57 , long V_154 )
{
struct V_37 * V_38 = F_32 ( V_57 ) ;
int V_155 ;
F_121 ( V_51 ) ;
F_122 ( & V_38 -> V_58 , & V_51 , V_156 ) ;
V_155 = ! F_50 ( V_57 , V_59 ) &&
! ( V_57 -> V_71 & V_157 ) &&
F_9 ( V_57 ) ;
F_14 ( V_57 ) ;
if ( V_155 )
V_154 = F_123 ( V_154 ) ;
F_124 ( & V_38 -> V_58 , & V_51 ) ;
return V_154 ;
}
static int F_125 ( struct V_88 * V_14 , struct V_136 * V_137 ,
int V_138 , int V_147 )
{
struct V_23 * V_24 = (struct V_23 * ) V_137 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) , * V_158 , * V_159 ;
struct V_14 * V_160 = NULL ;
struct V_14 * V_57 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_161 ;
int V_90 ;
long V_154 ;
V_90 = F_18 ( V_24 , V_138 , & V_3 ) ;
if ( V_90 < 0 )
goto V_94;
V_138 = V_90 ;
if ( F_118 ( V_150 , & V_14 -> V_147 ) && ! V_38 -> V_2 &&
( V_90 = F_91 ( V_14 ) ) != 0 )
goto V_94;
V_154 = F_126 ( V_15 , V_147 & V_162 ) ;
V_90 = - V_121 ;
V_160 = F_78 ( F_34 ( V_15 ) , NULL ) ;
if ( V_160 == NULL )
goto V_94;
V_9 = F_127 ( V_160 , 1 , 0 , V_100 ) ;
if ( V_9 == NULL )
goto V_94;
V_151:
V_57 = F_95 ( V_33 , V_24 , V_138 , V_15 -> V_76 , V_3 , & V_90 ) ;
if ( ! V_57 )
goto V_94;
F_12 ( V_57 ) ;
if ( F_50 ( V_57 , V_59 ) ) {
F_14 ( V_57 ) ;
F_61 ( V_57 ) ;
goto V_151;
}
V_90 = - V_130 ;
if ( V_57 -> V_74 != V_82 )
goto V_95;
if ( V_57 -> V_71 & V_157 )
goto V_95;
if ( F_9 ( V_57 ) ) {
V_90 = - V_163 ;
if ( ! V_154 )
goto V_95;
V_154 = F_120 ( V_57 , V_154 ) ;
V_90 = F_128 ( V_154 ) ;
if ( F_129 ( V_86 ) )
goto V_94;
F_61 ( V_57 ) ;
goto V_151;
}
V_161 = V_15 -> V_74 ;
switch ( V_161 ) {
case V_75 :
break;
case V_164 :
V_90 = - V_165 ;
goto V_95;
default:
V_90 = - V_27 ;
goto V_95;
}
F_115 ( V_15 ) ;
if ( V_15 -> V_74 != V_161 ) {
F_14 ( V_15 ) ;
F_14 ( V_57 ) ;
F_61 ( V_57 ) ;
goto V_151;
}
V_90 = F_130 ( V_15 , V_57 , V_160 ) ;
if ( V_90 ) {
F_14 ( V_15 ) ;
goto V_95;
}
F_13 ( V_15 ) ;
F_7 ( V_160 ) = V_15 ;
V_160 -> V_74 = V_164 ;
V_160 -> V_76 = V_15 -> V_76 ;
F_66 ( V_160 ) ;
V_158 = F_32 ( V_160 ) ;
F_131 ( V_160 -> V_50 , & V_158 -> V_166 ) ;
V_159 = F_32 ( V_57 ) ;
if ( V_159 -> V_2 ) {
F_132 ( & V_159 -> V_2 -> V_22 ) ;
V_158 -> V_2 = V_159 -> V_2 ;
}
if ( V_159 -> V_44 . V_43 ) {
F_133 ( & V_159 -> V_44 ) ;
V_158 -> V_44 = V_159 -> V_44 ;
}
F_72 ( V_15 , V_57 ) ;
V_14 -> V_70 = V_167 ;
V_15 -> V_74 = V_164 ;
F_13 ( V_160 ) ;
F_134 () ;
F_7 ( V_15 ) = V_160 ;
F_14 ( V_15 ) ;
F_27 ( & V_57 -> V_17 . V_102 ) ;
F_135 ( & V_57 -> V_17 , V_9 ) ;
F_28 ( & V_57 -> V_17 . V_102 ) ;
F_14 ( V_57 ) ;
V_57 -> V_168 ( V_57 , 0 ) ;
F_61 ( V_57 ) ;
return 0 ;
V_95:
if ( V_57 )
F_14 ( V_57 ) ;
V_94:
F_63 ( V_9 ) ;
if ( V_160 )
F_59 ( V_160 , 0 ) ;
if ( V_57 )
F_61 ( V_57 ) ;
return V_90 ;
}
static int F_136 ( struct V_88 * V_169 , struct V_88 * V_170 )
{
struct V_14 * V_171 = V_169 -> V_15 , * V_9 = V_170 -> V_15 ;
F_13 ( V_171 ) ;
F_13 ( V_9 ) ;
F_7 ( V_171 ) = V_9 ;
F_7 ( V_9 ) = V_171 ;
F_66 ( V_171 ) ;
F_66 ( V_9 ) ;
if ( V_171 -> V_76 != V_117 ) {
V_171 -> V_74 = V_164 ;
V_9 -> V_74 = V_164 ;
V_169 -> V_70 = V_167 ;
V_170 -> V_70 = V_167 ;
}
return 0 ;
}
static int F_137 ( struct V_88 * V_14 , struct V_88 * V_172 , int V_147 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_173 ;
struct V_8 * V_9 ;
int V_90 ;
V_90 = - V_93 ;
if ( V_14 -> type != V_77 && V_14 -> type != V_78 )
goto V_94;
V_90 = - V_27 ;
if ( V_15 -> V_74 != V_82 )
goto V_94;
V_9 = F_138 ( V_15 , 0 , V_147 & V_162 , & V_90 ) ;
if ( ! V_9 ) {
if ( V_90 == 0 )
V_90 = - V_27 ;
goto V_94;
}
V_173 = V_9 -> V_15 ;
F_139 ( V_15 , V_9 ) ;
F_140 ( & F_32 ( V_15 ) -> V_58 ) ;
F_12 ( V_173 ) ;
V_172 -> V_70 = V_167 ;
F_141 ( V_173 , V_172 ) ;
F_14 ( V_173 ) ;
return 0 ;
V_94:
return V_90 ;
}
static int F_142 ( struct V_88 * V_14 , struct V_136 * V_137 , int * V_174 , int V_20 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 ;
F_143 ( struct V_23 * , V_24 , V_137 ) ;
int V_90 = 0 ;
if ( V_20 ) {
V_15 = F_11 ( V_15 ) ;
V_90 = - V_175 ;
if ( ! V_15 )
goto V_94;
V_90 = 0 ;
} else {
F_13 ( V_15 ) ;
}
V_38 = F_32 ( V_15 ) ;
F_12 ( V_15 ) ;
if ( ! V_38 -> V_2 ) {
V_24 -> V_28 = V_29 ;
V_24 -> V_30 [ 0 ] = 0 ;
* V_174 = sizeof( short ) ;
} else {
struct V_21 * V_2 = V_38 -> V_2 ;
* V_174 = V_2 -> V_25 ;
memcpy ( V_24 , V_2 -> V_39 , * V_174 ) ;
}
F_14 ( V_15 ) ;
F_61 ( V_15 ) ;
V_94:
return V_90 ;
}
static void F_144 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_42 ;
V_7 -> V_176 = F_145 ( V_9 ) . V_176 ;
F_145 ( V_9 ) . V_176 = NULL ;
for ( V_42 = V_7 -> V_176 -> V_177 - 1 ; V_42 >= 0 ; V_42 -- )
F_146 ( V_7 -> V_176 -> V_176 [ V_42 ] ) ;
}
static void F_147 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_91 = F_145 ( V_9 ) . V_91 ;
V_7 . V_178 = F_145 ( V_9 ) . V_178 ;
if ( F_145 ( V_9 ) . V_176 )
F_144 ( & V_7 , V_9 ) ;
F_148 ( & V_7 ) ;
F_149 ( V_9 ) ;
}
static int F_150 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_42 ;
unsigned char V_179 = 0 ;
int V_180 = 0 ;
for ( V_42 = V_7 -> V_176 -> V_177 - 1 ; V_42 >= 0 ; V_42 -- ) {
struct V_14 * V_15 = F_151 ( V_7 -> V_176 -> V_176 [ V_42 ] ) ;
if ( V_15 ) {
V_180 ++ ;
V_179 = F_152 ( V_179 ,
F_32 ( V_15 ) -> V_181 ) ;
}
}
if ( F_114 ( V_179 > V_182 ) )
return - V_183 ;
F_145 ( V_9 ) . V_176 = F_153 ( V_7 -> V_176 ) ;
if ( ! F_145 ( V_9 ) . V_176 )
return - V_121 ;
if ( V_180 ) {
for ( V_42 = V_7 -> V_176 -> V_177 - 1 ; V_42 >= 0 ; V_42 -- )
F_154 ( V_7 -> V_176 -> V_176 [ V_42 ] ) ;
}
return V_179 ;
}
static int F_155 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_184 )
{
int V_90 = 0 ;
F_145 ( V_9 ) . V_91 = F_69 ( V_7 -> V_91 ) ;
if ( V_7 -> V_178 )
F_145 ( V_9 ) . V_178 = F_73 ( V_7 -> V_178 ) ;
F_145 ( V_9 ) . V_176 = NULL ;
if ( V_7 -> V_176 && V_184 )
V_90 = F_150 ( V_7 , V_9 ) ;
V_9 -> V_185 = F_147 ;
return V_90 ;
}
static void F_156 ( struct V_8 * V_9 , const struct V_88 * V_14 ,
const struct V_14 * V_57 )
{
if ( F_145 ( V_9 ) . V_178 )
return;
if ( F_118 ( V_150 , & V_14 -> V_147 ) ||
! V_57 -> V_63 ||
F_118 ( V_150 , & V_57 -> V_63 -> V_147 ) ) {
F_145 ( V_9 ) . V_91 = F_69 ( F_70 ( V_86 ) ) ;
F_145 ( V_9 ) . V_178 = F_71 () ;
}
}
static int F_157 ( struct V_186 * V_186 , struct V_88 * V_14 ,
struct V_187 * V_188 , T_3 V_25 )
{
struct V_189 * V_190 = F_158 ( V_186 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_188 -> V_191 ;
struct V_14 * V_57 = NULL ;
int V_192 = 0 ;
int V_90 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_154 ;
struct V_6 V_193 ;
int V_179 ;
int V_194 = 0 ;
if ( NULL == V_190 -> V_7 )
V_190 -> V_7 = & V_193 ;
F_159 () ;
V_90 = F_160 ( V_14 , V_188 , V_190 -> V_7 , false ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = - V_93 ;
if ( V_188 -> V_195 & V_196 )
goto V_94;
if ( V_188 -> V_197 ) {
V_90 = F_18 ( V_24 , V_188 -> V_197 , & V_3 ) ;
if ( V_90 < 0 )
goto V_94;
V_192 = V_90 ;
} else {
V_24 = NULL ;
V_90 = - V_175 ;
V_57 = F_11 ( V_15 ) ;
if ( ! V_57 )
goto V_94;
}
if ( F_118 ( V_150 , & V_14 -> V_147 ) && ! V_38 -> V_2
&& ( V_90 = F_91 ( V_14 ) ) != 0 )
goto V_94;
V_90 = - V_198 ;
if ( V_25 > V_15 -> V_47 - 32 )
goto V_94;
if ( V_25 > V_199 )
V_194 = F_161 ( T_3 ,
V_25 - V_199 ,
V_200 * V_201 ) ;
V_9 = F_162 ( V_15 , V_25 - V_194 , V_194 ,
V_188 -> V_195 & V_202 , & V_90 ) ;
if ( V_9 == NULL )
goto V_94;
V_90 = F_155 ( V_190 -> V_7 , V_9 , true ) ;
if ( V_90 < 0 )
goto V_203;
V_179 = V_90 + 1 ;
F_2 ( V_190 -> V_7 , V_9 ) ;
F_163 ( V_9 , V_25 - V_194 ) ;
V_9 -> V_194 = V_194 ;
V_9 -> V_25 = V_25 ;
V_90 = F_164 ( V_9 , 0 , V_188 -> V_204 , 0 , V_25 ) ;
if ( V_90 )
goto V_203;
V_154 = F_126 ( V_15 , V_188 -> V_195 & V_202 ) ;
V_151:
if ( ! V_57 ) {
V_90 = - V_61 ;
if ( V_24 == NULL )
goto V_203;
V_57 = F_95 ( V_33 , V_24 , V_192 , V_15 -> V_76 ,
V_3 , & V_90 ) ;
if ( V_57 == NULL )
goto V_203;
}
if ( F_165 ( V_57 , V_9 ) < 0 ) {
V_90 = V_25 ;
goto V_203;
}
F_12 ( V_57 ) ;
V_90 = - V_152 ;
if ( ! F_8 ( V_15 , V_57 ) )
goto V_95;
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
V_90 = - V_130 ;
} else {
F_14 ( V_15 ) ;
}
V_57 = NULL ;
if ( V_90 )
goto V_203;
goto V_151;
}
V_90 = - V_205 ;
if ( V_57 -> V_71 & V_157 )
goto V_95;
if ( V_15 -> V_76 != V_78 ) {
V_90 = F_119 ( V_15 -> V_63 , V_57 -> V_63 ) ;
if ( V_90 )
goto V_95;
}
if ( F_7 ( V_57 ) != V_15 && F_9 ( V_57 ) ) {
if ( ! V_154 ) {
V_90 = - V_163 ;
goto V_95;
}
V_154 = F_120 ( V_57 , V_154 ) ;
V_90 = F_128 ( V_154 ) ;
if ( F_129 ( V_86 ) )
goto V_203;
goto V_151;
}
if ( F_50 ( V_57 , V_206 ) )
F_166 ( V_9 ) ;
F_156 ( V_9 , V_14 , V_57 ) ;
F_167 ( & V_57 -> V_17 , V_9 ) ;
if ( V_179 > F_32 ( V_57 ) -> V_181 )
F_32 ( V_57 ) -> V_181 = V_179 ;
F_14 ( V_57 ) ;
V_57 -> V_168 ( V_57 , V_25 ) ;
F_61 ( V_57 ) ;
F_148 ( V_190 -> V_7 ) ;
return V_25 ;
V_95:
F_14 ( V_57 ) ;
V_203:
F_63 ( V_9 ) ;
V_94:
if ( V_57 )
F_61 ( V_57 ) ;
F_148 ( V_190 -> V_7 ) ;
return V_90 ;
}
static int F_168 ( struct V_186 * V_186 , struct V_88 * V_14 ,
struct V_187 * V_188 , T_3 V_25 )
{
struct V_189 * V_190 = F_158 ( V_186 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_57 = NULL ;
int V_90 , V_207 ;
struct V_8 * V_9 ;
int V_208 = 0 ;
struct V_6 V_193 ;
bool V_209 = false ;
int V_179 ;
if ( NULL == V_190 -> V_7 )
V_190 -> V_7 = & V_193 ;
F_159 () ;
V_90 = F_160 ( V_14 , V_188 , V_190 -> V_7 , false ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = - V_93 ;
if ( V_188 -> V_195 & V_196 )
goto V_210;
if ( V_188 -> V_197 ) {
V_90 = V_15 -> V_74 == V_164 ? - V_165 : - V_93 ;
goto V_210;
} else {
V_90 = - V_175 ;
V_57 = F_7 ( V_15 ) ;
if ( ! V_57 )
goto V_210;
}
if ( V_15 -> V_71 & V_211 )
goto V_212;
while ( V_208 < V_25 ) {
V_207 = V_25 - V_208 ;
if ( V_207 > ( ( V_15 -> V_47 >> 1 ) - 64 ) )
V_207 = ( V_15 -> V_47 >> 1 ) - 64 ;
if ( V_207 > V_199 )
V_207 = V_199 ;
V_9 = F_169 ( V_15 , V_207 , V_188 -> V_195 & V_202 ,
& V_90 ) ;
if ( V_9 == NULL )
goto V_210;
V_207 = F_161 ( int , V_207 , F_170 ( V_9 ) ) ;
V_90 = F_155 ( V_190 -> V_7 , V_9 , ! V_209 ) ;
if ( V_90 < 0 ) {
F_63 ( V_9 ) ;
goto V_210;
}
V_179 = V_90 + 1 ;
V_209 = true ;
V_90 = F_171 ( F_163 ( V_9 , V_207 ) , V_188 -> V_204 , V_207 ) ;
if ( V_90 ) {
F_63 ( V_9 ) ;
goto V_210;
}
F_12 ( V_57 ) ;
if ( F_50 ( V_57 , V_59 ) ||
( V_57 -> V_71 & V_157 ) )
goto V_213;
F_156 ( V_9 , V_14 , V_57 ) ;
F_167 ( & V_57 -> V_17 , V_9 ) ;
if ( V_179 > F_32 ( V_57 ) -> V_181 )
F_32 ( V_57 ) -> V_181 = V_179 ;
F_14 ( V_57 ) ;
V_57 -> V_168 ( V_57 , V_207 ) ;
V_208 += V_207 ;
}
F_148 ( V_190 -> V_7 ) ;
V_190 -> V_7 = NULL ;
return V_208 ;
V_213:
F_14 ( V_57 ) ;
F_63 ( V_9 ) ;
V_212:
if ( V_208 == 0 && ! ( V_188 -> V_195 & V_214 ) )
F_172 ( V_215 , V_86 , 0 ) ;
V_90 = - V_205 ;
V_210:
F_148 ( V_190 -> V_7 ) ;
V_190 -> V_7 = NULL ;
return V_208 ? : V_90 ;
}
static int F_173 ( struct V_186 * V_186 , struct V_88 * V_14 ,
struct V_187 * V_188 , T_3 V_25 )
{
int V_90 ;
struct V_14 * V_15 = V_14 -> V_15 ;
V_90 = F_174 ( V_15 ) ;
if ( V_90 )
return V_90 ;
if ( V_15 -> V_74 != V_164 )
return - V_175 ;
if ( V_188 -> V_197 )
V_188 -> V_197 = 0 ;
return F_157 ( V_186 , V_14 , V_188 , V_25 ) ;
}
static int F_175 ( struct V_186 * V_216 , struct V_88 * V_14 ,
struct V_187 * V_188 , T_3 V_207 ,
int V_147 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( V_15 -> V_74 != V_164 )
return - V_175 ;
return F_176 ( V_216 , V_14 , V_188 , V_207 , V_147 ) ;
}
static void F_177 ( struct V_187 * V_188 , struct V_14 * V_15 )
{
struct V_37 * V_38 = F_32 ( V_15 ) ;
V_188 -> V_197 = 0 ;
if ( V_38 -> V_2 ) {
V_188 -> V_197 = V_38 -> V_2 -> V_25 ;
memcpy ( V_188 -> V_191 , V_38 -> V_2 -> V_39 , V_38 -> V_2 -> V_25 ) ;
}
}
static int F_176 ( struct V_186 * V_216 , struct V_88 * V_14 ,
struct V_187 * V_188 , T_3 V_207 ,
int V_147 )
{
struct V_189 * V_190 = F_158 ( V_216 ) ;
struct V_6 V_193 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
int V_217 = V_147 & V_202 ;
struct V_8 * V_9 ;
int V_90 ;
int V_218 , V_219 ;
V_90 = - V_93 ;
if ( V_147 & V_196 )
goto V_94;
V_188 -> V_197 = 0 ;
V_90 = F_178 ( & V_38 -> V_97 ) ;
if ( V_90 ) {
V_90 = F_128 ( F_179 ( V_15 , V_217 ) ) ;
goto V_94;
}
V_219 = F_180 ( V_15 , V_147 ) ;
V_9 = F_181 ( V_15 , V_147 , & V_218 , & V_219 , & V_90 ) ;
if ( ! V_9 ) {
F_12 ( V_15 ) ;
if ( V_15 -> V_76 == V_78 && V_90 == - V_163 &&
( V_15 -> V_71 & V_157 ) )
V_90 = 0 ;
F_14 ( V_15 ) ;
goto V_95;
}
F_43 ( & V_38 -> V_58 ,
V_52 | V_53 | V_54 ) ;
if ( V_188 -> V_191 )
F_177 ( V_188 , V_9 -> V_15 ) ;
if ( V_207 > V_9 -> V_25 - V_219 )
V_207 = V_9 -> V_25 - V_219 ;
else if ( V_207 < V_9 -> V_25 - V_219 )
V_188 -> V_195 |= V_220 ;
V_90 = F_182 ( V_9 , V_219 , V_188 -> V_204 , V_207 ) ;
if ( V_90 )
goto V_203;
if ( F_50 ( V_15 , V_206 ) )
F_183 ( V_188 , V_15 , V_9 ) ;
if ( ! V_190 -> V_7 ) {
V_190 -> V_7 = & V_193 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
}
F_184 ( V_190 -> V_7 , F_145 ( V_9 ) . V_91 , F_145 ( V_9 ) . V_178 ) ;
F_4 ( V_190 -> V_7 , V_9 ) ;
if ( ! ( V_147 & V_221 ) ) {
if ( F_145 ( V_9 ) . V_176 )
F_144 ( V_190 -> V_7 , V_9 ) ;
F_185 ( V_15 , V_9 -> V_25 ) ;
} else {
F_186 ( V_15 , V_207 ) ;
if ( F_145 ( V_9 ) . V_176 )
V_190 -> V_7 -> V_176 = F_153 ( F_145 ( V_9 ) . V_176 ) ;
}
V_90 = ( V_147 & V_220 ) ? V_9 -> V_25 - V_219 : V_207 ;
F_187 ( V_14 , V_188 , V_190 -> V_7 , V_147 ) ;
V_203:
F_139 ( V_15 , V_9 ) ;
V_95:
F_77 ( & V_38 -> V_97 ) ;
V_94:
return V_90 ;
}
static long F_188 ( struct V_14 * V_15 , long V_154 )
{
F_121 ( V_51 ) ;
F_12 ( V_15 ) ;
for (; ; ) {
F_189 ( F_190 ( V_15 ) , & V_51 , V_156 ) ;
if ( ! F_47 ( & V_15 -> V_17 ) ||
V_15 -> V_60 ||
( V_15 -> V_71 & V_157 ) ||
F_129 ( V_86 ) ||
! V_154 )
break;
F_191 ( V_222 , & V_15 -> V_63 -> V_147 ) ;
F_14 ( V_15 ) ;
V_154 = F_123 ( V_154 ) ;
F_12 ( V_15 ) ;
F_192 ( V_222 , & V_15 -> V_63 -> V_147 ) ;
}
F_124 ( F_190 ( V_15 ) , & V_51 ) ;
F_14 ( V_15 ) ;
return V_154 ;
}
static int F_193 ( struct V_186 * V_216 , struct V_88 * V_14 ,
struct V_187 * V_188 , T_3 V_207 ,
int V_147 )
{
struct V_189 * V_190 = F_158 ( V_216 ) ;
struct V_6 V_193 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_37 * V_38 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_188 -> V_191 ;
int V_223 = 0 ;
int V_224 = 0 ;
int V_225 ;
int V_90 = 0 ;
long V_154 ;
int V_219 ;
V_90 = - V_27 ;
if ( V_15 -> V_74 != V_164 )
goto V_94;
V_90 = - V_93 ;
if ( V_147 & V_196 )
goto V_94;
V_225 = F_194 ( V_15 , V_147 & V_226 , V_207 ) ;
V_154 = F_179 ( V_15 , V_147 & V_202 ) ;
V_188 -> V_197 = 0 ;
if ( ! V_190 -> V_7 ) {
V_190 -> V_7 = & V_193 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
}
V_90 = F_178 ( & V_38 -> V_97 ) ;
if ( V_90 ) {
V_90 = F_128 ( V_154 ) ;
goto V_94;
}
V_219 = F_180 ( V_15 , V_147 ) ;
do {
int V_227 ;
struct V_8 * V_9 ;
F_12 ( V_15 ) ;
V_9 = F_195 ( & V_15 -> V_17 ) ;
V_228:
if ( V_9 == NULL ) {
F_32 ( V_15 ) -> V_181 = 0 ;
if ( V_223 >= V_225 )
goto V_229;
V_90 = F_174 ( V_15 ) ;
if ( V_90 )
goto V_229;
if ( V_15 -> V_71 & V_157 )
goto V_229;
F_14 ( V_15 ) ;
V_90 = - V_163 ;
if ( ! V_154 )
break;
F_77 ( & V_38 -> V_97 ) ;
V_154 = F_188 ( V_15 , V_154 ) ;
if ( F_129 ( V_86 )
|| F_178 ( & V_38 -> V_97 ) ) {
V_90 = F_128 ( V_154 ) ;
goto V_94;
}
continue;
V_229:
F_14 ( V_15 ) ;
break;
}
if ( V_219 >= V_9 -> V_25 ) {
V_219 -= V_9 -> V_25 ;
V_9 = F_196 ( V_9 , & V_15 -> V_17 ) ;
goto V_228;
}
F_14 ( V_15 ) ;
if ( V_224 ) {
if ( ( F_145 ( V_9 ) . V_91 != V_190 -> V_7 -> V_91 ) ||
( F_145 ( V_9 ) . V_178 != V_190 -> V_7 -> V_178 ) )
break;
} else {
F_184 ( V_190 -> V_7 , F_145 ( V_9 ) . V_91 , F_145 ( V_9 ) . V_178 ) ;
V_224 = 1 ;
}
if ( V_24 ) {
F_177 ( V_188 , V_9 -> V_15 ) ;
V_24 = NULL ;
}
V_227 = F_161 (unsigned int, skb->len - skip, size) ;
if ( F_197 ( V_188 -> V_204 , V_9 -> V_230 + V_219 , V_227 ) ) {
if ( V_223 == 0 )
V_223 = - V_231 ;
break;
}
V_223 += V_227 ;
V_207 -= V_227 ;
if ( ! ( V_147 & V_221 ) ) {
F_198 ( V_9 , V_227 ) ;
F_185 ( V_15 , V_227 ) ;
if ( F_145 ( V_9 ) . V_176 )
F_144 ( V_190 -> V_7 , V_9 ) ;
if ( V_9 -> V_25 )
break;
F_199 ( V_9 , & V_15 -> V_17 ) ;
F_200 ( V_9 ) ;
if ( V_190 -> V_7 -> V_176 )
break;
} else {
if ( F_145 ( V_9 ) . V_176 )
V_190 -> V_7 -> V_176 = F_153 ( F_145 ( V_9 ) . V_176 ) ;
F_186 ( V_15 , V_227 ) ;
break;
}
} while ( V_207 );
F_77 ( & V_38 -> V_97 ) ;
F_187 ( V_14 , V_188 , V_190 -> V_7 , V_147 ) ;
V_94:
return V_223 ? : V_90 ;
}
static int F_201 ( struct V_88 * V_14 , int V_133 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_57 ;
if ( V_133 < V_232 || V_133 > V_233 )
return - V_27 ;
++ V_133 ;
F_12 ( V_15 ) ;
V_15 -> V_71 |= V_133 ;
V_57 = F_7 ( V_15 ) ;
if ( V_57 )
F_13 ( V_57 ) ;
F_14 ( V_15 ) ;
V_15 -> V_79 ( V_15 ) ;
if ( V_57 &&
( V_15 -> V_76 == V_77 || V_15 -> V_76 == V_78 ) ) {
int V_234 = 0 ;
if ( V_133 & V_157 )
V_234 |= V_211 ;
if ( V_133 & V_211 )
V_234 |= V_157 ;
F_12 ( V_57 ) ;
V_57 -> V_71 |= V_234 ;
F_14 ( V_57 ) ;
V_57 -> V_79 ( V_57 ) ;
if ( V_234 == V_72 )
F_44 ( V_57 , V_80 , V_81 ) ;
else if ( V_234 & V_157 )
F_44 ( V_57 , V_80 , V_235 ) ;
}
if ( V_57 )
F_61 ( V_57 ) ;
return 0 ;
}
long F_202 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
long V_236 = 0 ;
if ( V_15 -> V_74 == V_82 )
return - V_27 ;
F_27 ( & V_15 -> V_17 . V_102 ) ;
if ( V_15 -> V_76 == V_77 ||
V_15 -> V_76 == V_78 ) {
F_203 (&sk->sk_receive_queue, skb)
V_236 += V_9 -> V_25 ;
} else {
V_9 = F_195 ( & V_15 -> V_17 ) ;
if ( V_9 )
V_236 = V_9 -> V_25 ;
}
F_28 ( & V_15 -> V_17 . V_102 ) ;
return V_236 ;
}
long F_204 ( struct V_14 * V_15 )
{
return F_205 ( V_15 ) ;
}
static int F_206 ( struct V_88 * V_14 , unsigned int V_237 , unsigned long V_238 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
long V_236 = 0 ;
int V_90 ;
switch ( V_237 ) {
case V_239 :
V_236 = F_204 ( V_15 ) ;
V_90 = F_207 ( V_236 , ( int V_240 * ) V_238 ) ;
break;
case V_241 :
V_236 = F_202 ( V_15 ) ;
if ( V_236 < 0 )
V_90 = V_236 ;
else
V_90 = F_207 ( V_236 , ( int V_240 * ) V_238 ) ;
break;
default:
V_90 = - V_242 ;
break;
}
return V_90 ;
}
static unsigned int F_208 ( struct V_243 * V_243 , struct V_88 * V_14 , T_4 * V_51 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
unsigned int V_244 ;
F_209 ( V_243 , F_190 ( V_15 ) , V_51 ) ;
V_244 = 0 ;
if ( V_15 -> V_60 )
V_244 |= V_245 ;
if ( V_15 -> V_71 == V_72 )
V_244 |= V_246 ;
if ( V_15 -> V_71 & V_157 )
V_244 |= V_247 | V_248 | V_249 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_244 |= V_248 | V_249 ;
if ( ( V_15 -> V_76 == V_77 || V_15 -> V_76 == V_78 ) &&
V_15 -> V_74 == V_75 )
V_244 |= V_246 ;
if ( F_37 ( V_15 ) )
V_244 |= V_52 | V_53 | V_54 ;
return V_244 ;
}
static unsigned int F_210 ( struct V_243 * V_243 , struct V_88 * V_14 ,
T_4 * V_51 )
{
struct V_14 * V_15 = V_14 -> V_15 , * V_57 ;
unsigned int V_244 , V_250 ;
F_209 ( V_243 , F_190 ( V_15 ) , V_51 ) ;
V_244 = 0 ;
if ( V_15 -> V_60 || ! F_47 ( & V_15 -> V_251 ) )
V_244 |= V_245 ;
if ( V_15 -> V_71 & V_157 )
V_244 |= V_247 | V_248 | V_249 ;
if ( V_15 -> V_71 == V_72 )
V_244 |= V_246 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_244 |= V_248 | V_249 ;
if ( V_15 -> V_76 == V_78 ) {
if ( V_15 -> V_74 == V_75 )
V_244 |= V_246 ;
if ( V_15 -> V_74 == V_252 )
return V_244 ;
}
if ( ! ( F_211 ( V_51 ) & ( V_54 | V_53 | V_52 ) ) )
return V_244 ;
V_250 = F_37 ( V_15 ) ;
V_57 = F_11 ( V_15 ) ;
if ( V_57 ) {
if ( F_7 ( V_57 ) != V_15 ) {
F_209 ( V_243 , & F_32 ( V_57 ) -> V_58 , V_51 ) ;
if ( F_9 ( V_57 ) )
V_250 = 0 ;
}
F_61 ( V_57 ) ;
}
if ( V_250 )
V_244 |= V_52 | V_53 | V_54 ;
else
F_191 ( V_253 , & V_15 -> V_63 -> V_147 ) ;
return V_244 ;
}
static struct V_14 * F_212 ( struct V_254 * V_255 , T_5 * V_256 )
{
unsigned long V_257 = F_213 ( * V_256 ) ;
unsigned long V_258 = F_214 ( * V_256 ) ;
struct V_14 * V_15 ;
unsigned long V_177 = 0 ;
for ( V_15 = F_215 ( & V_5 [ V_258 ] ) ; V_15 ; V_15 = F_216 ( V_15 ) ) {
if ( F_34 ( V_15 ) != F_217 ( V_255 ) )
continue;
if ( ++ V_177 == V_257 )
break;
}
return V_15 ;
}
static struct V_14 * F_218 ( struct V_254 * V_255 ,
struct V_14 * V_15 ,
T_5 * V_256 )
{
unsigned long V_258 ;
while ( V_15 > (struct V_14 * ) V_259 ) {
V_15 = F_216 ( V_15 ) ;
if ( ! V_15 )
goto V_260;
if ( F_34 ( V_15 ) == F_217 ( V_255 ) )
return V_15 ;
}
do {
V_15 = F_212 ( V_255 , V_256 ) ;
if ( V_15 )
return V_15 ;
V_260:
V_258 = F_214 ( * V_256 ) + 1 ;
* V_256 = F_219 ( V_258 , 1 ) ;
} while ( V_258 < F_220 ( V_5 ) );
return NULL ;
}
static void * F_221 ( struct V_254 * V_255 , T_5 * V_256 )
__acquires( V_32 )
{
F_27 ( & V_32 ) ;
if ( ! * V_256 )
return V_259 ;
if ( F_214 ( * V_256 ) >= F_220 ( V_5 ) )
return NULL ;
return F_218 ( V_255 , NULL , V_256 ) ;
}
static void * F_222 ( struct V_254 * V_255 , void * V_261 , T_5 * V_256 )
{
++ * V_256 ;
return F_218 ( V_255 , V_261 , V_256 ) ;
}
static void F_223 ( struct V_254 * V_255 , void * V_261 )
__releases( V_32 )
{
F_28 ( & V_32 ) ;
}
static int F_224 ( struct V_254 * V_255 , void * V_261 )
{
if ( V_261 == V_259 )
F_225 ( V_255 , L_4
L_5 ) ;
else {
struct V_14 * V_19 = V_261 ;
struct V_37 * V_38 = F_32 ( V_19 ) ;
F_12 ( V_19 ) ;
F_226 ( V_255 , L_6 ,
V_19 ,
F_38 ( & V_19 -> V_262 ) ,
0 ,
V_19 -> V_74 == V_82 ? V_263 : 0 ,
V_19 -> V_76 ,
V_19 -> V_63 ?
( V_19 -> V_74 == V_164 ? V_167 : V_113 ) :
( V_19 -> V_74 == V_164 ? V_264 : V_265 ) ,
F_227 ( V_19 ) ) ;
if ( V_38 -> V_2 ) {
int V_42 , V_25 ;
F_228 ( V_255 , ' ' ) ;
V_42 = 0 ;
V_25 = V_38 -> V_2 -> V_25 - sizeof( short ) ;
if ( ! F_229 ( V_19 ) )
V_25 -- ;
else {
F_228 ( V_255 , '@' ) ;
V_42 ++ ;
}
for ( ; V_42 < V_25 ; V_42 ++ )
F_228 ( V_255 , V_38 -> V_2 -> V_39 -> V_30 [ V_42 ] ) ;
}
F_14 ( V_19 ) ;
F_228 ( V_255 , '\n' ) ;
}
return 0 ;
}
static int F_230 ( struct V_41 * V_41 , struct V_243 * V_243 )
{
return F_231 ( V_41 , V_243 , & V_266 ,
sizeof( struct V_267 ) ) ;
}
static int T_6 F_232 ( struct V_33 * V_33 )
{
int error = - V_121 ;
V_33 -> V_105 . V_106 = 10 ;
if ( F_233 ( V_33 ) )
goto V_94;
#ifdef F_234
if ( ! F_235 ( V_33 , L_7 , 0 , & V_268 ) ) {
F_236 ( V_33 ) ;
goto V_94;
}
#endif
error = 0 ;
V_94:
return error ;
}
static void T_7 F_237 ( struct V_33 * V_33 )
{
F_236 ( V_33 ) ;
F_238 ( V_33 , L_7 ) ;
}
static int T_8 F_239 ( void )
{
int V_269 = - 1 ;
struct V_8 * V_270 ;
F_240 ( sizeof( struct V_271 ) > sizeof( V_270 -> V_272 ) ) ;
V_269 = F_241 ( & V_101 , 1 ) ;
if ( V_269 != 0 ) {
F_52 ( V_273 L_8 ,
V_274 ) ;
goto V_94;
}
F_242 ( & V_275 ) ;
F_243 ( & V_276 ) ;
V_94:
return V_269 ;
}
static void T_9 F_244 ( void )
{
F_245 ( V_99 ) ;
F_246 ( & V_101 ) ;
F_247 ( & V_276 ) ;
}
