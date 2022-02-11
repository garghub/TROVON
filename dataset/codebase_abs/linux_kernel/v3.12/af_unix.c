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
F_31 (s, &unix_socket_table[hash ^ type]) {
struct V_35 * V_36 = F_32 ( V_19 ) ;
if ( ! F_33 ( F_34 ( V_19 ) , V_33 ) )
continue;
if ( V_36 -> V_2 -> V_25 == V_25 &&
! memcmp ( V_36 -> V_2 -> V_37 , V_34 , V_25 ) )
goto V_38;
}
V_19 = NULL ;
V_38:
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
static struct V_14 * F_36 ( struct V_39 * V_40 )
{
struct V_14 * V_19 ;
F_27 ( & V_32 ) ;
F_31 (s,
&unix_socket_table[i->i_ino & (UNIX_HASH_SIZE - 1)]) {
struct V_41 * V_41 = F_32 ( V_19 ) -> V_42 . V_41 ;
if ( V_41 && V_41 -> V_43 == V_40 ) {
F_13 ( V_19 ) ;
goto V_38;
}
}
V_19 = NULL ;
V_38:
F_28 ( & V_32 ) ;
return V_19 ;
}
static inline int F_37 ( struct V_14 * V_15 )
{
return ( F_38 ( & V_15 -> V_44 ) << 2 ) <= V_15 -> V_45 ;
}
static void F_39 ( struct V_14 * V_15 )
{
struct V_46 * V_47 ;
F_40 () ;
if ( F_37 ( V_15 ) ) {
V_47 = F_41 ( V_15 -> V_48 ) ;
if ( F_42 ( V_47 ) )
F_43 ( & V_47 -> V_49 ,
V_50 | V_51 | V_52 ) ;
F_44 ( V_15 , V_53 , V_54 ) ;
}
F_45 () ;
}
static void F_46 ( struct V_14 * V_15 , struct V_14 * V_55 )
{
if ( ! F_47 ( & V_15 -> V_17 ) ) {
F_48 ( & V_15 -> V_17 ) ;
F_49 ( & F_32 ( V_15 ) -> V_56 ) ;
if ( ! F_50 ( V_55 , V_57 ) && F_7 ( V_55 ) == V_15 ) {
V_55 -> V_58 = V_59 ;
V_55 -> V_60 ( V_55 ) ;
}
}
}
static void F_51 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_32 ( V_15 ) ;
F_48 ( & V_15 -> V_17 ) ;
F_23 ( F_38 ( & V_15 -> V_44 ) ) ;
F_23 ( ! F_24 ( V_15 ) ) ;
F_23 ( V_15 -> V_61 ) ;
if ( ! F_50 ( V_15 , V_57 ) ) {
F_52 ( V_62 L_1 , V_15 ) ;
return;
}
if ( V_36 -> V_2 )
F_15 ( V_36 -> V_2 ) ;
F_53 ( & V_63 ) ;
F_54 () ;
F_55 ( F_34 ( V_15 ) , V_15 -> V_64 , - 1 ) ;
F_56 () ;
#ifdef F_57
F_52 ( V_65 L_2 , V_15 ,
F_58 ( & V_63 ) ) ;
#endif
}
static void F_59 ( struct V_14 * V_15 , int V_66 )
{
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_42 V_42 ;
struct V_14 * V_67 ;
struct V_8 * V_9 ;
int V_68 ;
F_26 ( V_15 ) ;
F_12 ( V_15 ) ;
F_60 ( V_15 ) ;
V_15 -> V_69 = V_70 ;
V_42 = V_36 -> V_42 ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_71 = NULL ;
V_68 = V_15 -> V_72 ;
V_15 -> V_72 = V_73 ;
F_14 ( V_15 ) ;
F_49 ( & V_36 -> V_56 ) ;
V_67 = F_7 ( V_15 ) ;
if ( V_67 != NULL ) {
if ( V_15 -> V_74 == V_75 || V_15 -> V_74 == V_76 ) {
F_12 ( V_67 ) ;
V_67 -> V_69 = V_70 ;
if ( ! F_47 ( & V_15 -> V_17 ) || V_66 )
V_67 -> V_58 = V_59 ;
F_14 ( V_67 ) ;
V_67 -> V_77 ( V_67 ) ;
F_44 ( V_67 , V_78 , V_79 ) ;
}
F_61 ( V_67 ) ;
F_7 ( V_15 ) = NULL ;
}
while ( ( V_9 = F_62 ( & V_15 -> V_17 ) ) != NULL ) {
if ( V_68 == V_80 )
F_59 ( V_9 -> V_15 , 1 ) ;
F_63 ( V_9 ) ;
}
if ( V_42 . V_41 )
F_64 ( & V_42 ) ;
F_61 ( V_15 ) ;
if ( V_81 )
F_65 () ;
}
static void F_66 ( struct V_14 * V_15 )
{
F_67 ( V_15 -> V_82 ) ;
if ( V_15 -> V_83 )
F_68 ( V_15 -> V_83 ) ;
V_15 -> V_82 = F_69 ( F_70 ( V_84 ) ) ;
V_15 -> V_83 = F_71 () ;
}
static void F_72 ( struct V_14 * V_15 , struct V_14 * V_85 )
{
F_67 ( V_15 -> V_82 ) ;
if ( V_15 -> V_83 )
F_68 ( V_15 -> V_83 ) ;
V_15 -> V_82 = F_69 ( V_85 -> V_82 ) ;
V_15 -> V_83 = F_73 ( V_85 -> V_83 ) ;
}
static int F_74 ( struct V_86 * V_14 , int V_87 )
{
int V_88 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_89 * V_90 = NULL ;
V_88 = - V_91 ;
if ( V_14 -> type != V_75 && V_14 -> type != V_76 )
goto V_92;
V_88 = - V_27 ;
if ( ! V_36 -> V_2 )
goto V_92;
F_12 ( V_15 ) ;
if ( V_15 -> V_72 != V_73 && V_15 -> V_72 != V_80 )
goto V_93;
if ( V_87 > V_15 -> V_18 )
F_49 ( & V_36 -> V_56 ) ;
V_15 -> V_18 = V_87 ;
V_15 -> V_72 = V_80 ;
F_66 ( V_15 ) ;
V_88 = 0 ;
V_93:
F_14 ( V_15 ) ;
F_67 ( V_90 ) ;
V_92:
return V_88 ;
}
static void F_75 ( struct V_14 * V_15 , int V_94 )
{
struct V_35 * V_36 = F_32 ( V_15 ) ;
F_76 ( & V_36 -> V_95 ) ;
V_15 -> V_96 = V_94 ;
F_77 ( & V_36 -> V_95 ) ;
}
static struct V_14 * F_78 ( struct V_33 * V_33 , struct V_86 * V_14 )
{
struct V_14 * V_15 = NULL ;
struct V_35 * V_36 ;
F_79 ( & V_63 ) ;
if ( F_58 ( & V_63 ) > 2 * F_80 () )
goto V_92;
V_15 = F_81 ( V_33 , V_97 , V_98 , & V_99 ) ;
if ( ! V_15 )
goto V_92;
F_82 ( V_14 , V_15 ) ;
F_83 ( & V_15 -> V_17 . V_100 ,
& V_101 ) ;
V_15 -> V_102 = F_39 ;
V_15 -> V_18 = V_33 -> V_103 . V_104 ;
V_15 -> V_105 = F_51 ;
V_36 = F_32 ( V_15 ) ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_71 = NULL ;
F_84 ( & V_36 -> V_100 ) ;
F_85 ( & V_36 -> V_106 , 0 ) ;
F_86 ( & V_36 -> V_107 ) ;
F_87 ( & V_36 -> V_95 ) ;
F_88 ( & V_36 -> V_56 ) ;
F_29 ( F_1 ( V_15 ) , V_15 ) ;
V_92:
if ( V_15 == NULL )
F_53 ( & V_63 ) ;
else {
F_54 () ;
F_55 ( F_34 ( V_15 ) , V_15 -> V_64 , 1 ) ;
F_56 () ;
}
return V_15 ;
}
static int F_89 ( struct V_33 * V_33 , struct V_86 * V_14 , int V_108 ,
int V_109 )
{
if ( V_108 && V_108 != V_97 )
return - V_110 ;
V_14 -> V_68 = V_111 ;
switch ( V_14 -> type ) {
case V_75 :
V_14 -> V_112 = & V_113 ;
break;
case V_114 :
V_14 -> type = V_115 ;
case V_115 :
V_14 -> V_112 = & V_116 ;
break;
case V_76 :
V_14 -> V_112 = & V_117 ;
break;
default:
return - V_118 ;
}
return F_78 ( V_33 , V_14 ) ? 0 : - V_119 ;
}
static int F_90 ( struct V_86 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( ! V_15 )
return 0 ;
F_59 ( V_15 , 0 ) ;
V_14 -> V_15 = NULL ;
return 0 ;
}
static int F_91 ( struct V_86 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
static V_11 V_120 = 1 ;
struct V_21 * V_2 ;
int V_88 ;
unsigned int V_121 = 0 ;
F_76 ( & V_36 -> V_95 ) ;
V_88 = 0 ;
if ( V_36 -> V_2 )
goto V_92;
V_88 = - V_119 ;
V_2 = F_92 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_98 ) ;
if ( ! V_2 )
goto V_92;
V_2 -> V_37 -> V_28 = V_29 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
V_122:
V_2 -> V_25 = sprintf ( V_2 -> V_37 -> V_30 + 1 , L_3 , V_120 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_5 ( F_19 ( V_2 -> V_37 , V_2 -> V_25 , 0 ) ) ;
F_27 ( & V_32 ) ;
V_120 = ( V_120 + 1 ) & 0xFFFFF ;
if ( F_30 ( V_33 , V_2 -> V_37 , V_2 -> V_25 , V_14 -> type ,
V_2 -> V_3 ) ) {
F_28 ( & V_32 ) ;
F_94 () ;
if ( V_121 ++ == 0xFFFFF ) {
V_88 = - V_123 ;
F_17 ( V_2 ) ;
goto V_92;
}
goto V_122;
}
V_2 -> V_3 ^= V_15 -> V_74 ;
F_20 ( V_15 ) ;
V_36 -> V_2 = V_2 ;
F_22 ( & V_5 [ V_2 -> V_3 ] , V_15 ) ;
F_28 ( & V_32 ) ;
V_88 = 0 ;
V_92: F_77 ( & V_36 -> V_95 ) ;
return V_88 ;
}
static struct V_14 * F_95 ( struct V_33 * V_33 ,
struct V_23 * V_34 , int V_25 ,
int type , unsigned int V_3 , int * error )
{
struct V_14 * V_36 ;
struct V_42 V_42 ;
int V_88 = 0 ;
if ( V_34 -> V_30 [ 0 ] ) {
struct V_39 * V_39 ;
V_88 = F_96 ( V_34 -> V_30 , V_124 , & V_42 ) ;
if ( V_88 )
goto V_125;
V_39 = V_42 . V_41 -> V_43 ;
V_88 = F_97 ( V_39 , V_126 ) ;
if ( V_88 )
goto V_127;
V_88 = - V_128 ;
if ( ! F_98 ( V_39 -> V_129 ) )
goto V_127;
V_36 = F_36 ( V_39 ) ;
if ( ! V_36 )
goto V_127;
if ( V_36 -> V_74 == type )
F_99 ( & V_42 ) ;
F_64 ( & V_42 ) ;
V_88 = - V_130 ;
if ( V_36 -> V_74 != type ) {
F_61 ( V_36 ) ;
goto V_125;
}
} else {
V_88 = - V_128 ;
V_36 = F_35 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_36 ) {
struct V_41 * V_41 ;
V_41 = F_32 ( V_36 ) -> V_42 . V_41 ;
if ( V_41 )
F_99 ( & F_32 ( V_36 ) -> V_42 ) ;
} else
goto V_125;
}
return V_36 ;
V_127:
F_64 ( & V_42 ) ;
V_125:
* error = V_88 ;
return NULL ;
}
static int F_100 ( const char * V_30 , T_2 V_131 , struct V_42 * V_132 )
{
struct V_41 * V_41 ;
struct V_42 V_42 ;
int V_88 = 0 ;
V_41 = F_101 ( V_133 , V_30 , & V_42 , 0 ) ;
V_88 = F_102 ( V_41 ) ;
if ( F_103 ( V_41 ) )
return V_88 ;
V_88 = F_104 ( & V_42 , V_41 , V_131 , 0 ) ;
if ( ! V_88 ) {
V_88 = F_105 ( V_42 . V_41 -> V_43 , V_41 , V_131 , 0 ) ;
if ( ! V_88 ) {
V_132 -> V_71 = F_106 ( V_42 . V_71 ) ;
V_132 -> V_41 = F_107 ( V_41 ) ;
}
}
F_108 ( & V_42 , V_41 ) ;
return V_88 ;
}
static int F_109 ( struct V_86 * V_14 , struct V_134 * V_135 , int V_136 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_135 ;
char * V_30 = V_24 -> V_30 ;
int V_88 ;
unsigned int V_3 ;
struct V_21 * V_2 ;
struct V_1 * V_31 ;
V_88 = - V_27 ;
if ( V_24 -> V_28 != V_29 )
goto V_92;
if ( V_136 == sizeof( short ) ) {
V_88 = F_91 ( V_14 ) ;
goto V_92;
}
V_88 = F_18 ( V_24 , V_136 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_136 = V_88 ;
F_76 ( & V_36 -> V_95 ) ;
V_88 = - V_27 ;
if ( V_36 -> V_2 )
goto V_137;
V_88 = - V_119 ;
V_2 = F_110 ( sizeof( * V_2 ) + V_136 , V_98 ) ;
if ( ! V_2 )
goto V_137;
memcpy ( V_2 -> V_37 , V_24 , V_136 ) ;
V_2 -> V_25 = V_136 ;
V_2 -> V_3 = V_3 ^ V_15 -> V_74 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
if ( V_30 [ 0 ] ) {
struct V_42 V_42 ;
T_2 V_131 = V_138 |
( F_111 ( V_14 ) -> V_129 & ~ F_112 () ) ;
V_88 = F_100 ( V_30 , V_131 , & V_42 ) ;
if ( V_88 ) {
if ( V_88 == - V_139 )
V_88 = - V_140 ;
F_15 ( V_2 ) ;
goto V_137;
}
V_2 -> V_3 = V_4 ;
V_3 = V_42 . V_41 -> V_43 -> V_141 & ( V_4 - 1 ) ;
F_27 ( & V_32 ) ;
V_36 -> V_42 = V_42 ;
V_31 = & V_5 [ V_3 ] ;
} else {
F_27 ( & V_32 ) ;
V_88 = - V_140 ;
if ( F_30 ( V_33 , V_24 , V_136 ,
V_15 -> V_74 , V_3 ) ) {
F_15 ( V_2 ) ;
goto V_93;
}
V_31 = & V_5 [ V_2 -> V_3 ] ;
}
V_88 = 0 ;
F_20 ( V_15 ) ;
V_36 -> V_2 = V_2 ;
F_22 ( V_31 , V_15 ) ;
V_93:
F_28 ( & V_32 ) ;
V_137:
F_77 ( & V_36 -> V_95 ) ;
V_92:
return V_88 ;
}
static void F_113 ( struct V_14 * V_142 , struct V_14 * V_143 )
{
if ( F_114 ( V_142 == V_143 ) || ! V_143 ) {
F_12 ( V_142 ) ;
return;
}
if ( V_142 < V_143 ) {
F_12 ( V_142 ) ;
F_115 ( V_143 ) ;
} else {
F_12 ( V_143 ) ;
F_115 ( V_142 ) ;
}
}
static void F_116 ( struct V_14 * V_142 , struct V_14 * V_143 )
{
if ( F_114 ( V_142 == V_143 ) || ! V_143 ) {
F_14 ( V_142 ) ;
return;
}
F_14 ( V_142 ) ;
F_14 ( V_143 ) ;
}
static int F_117 ( struct V_86 * V_14 , struct V_134 * V_2 ,
int V_144 , int V_145 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_2 ;
struct V_14 * V_55 ;
unsigned int V_3 ;
int V_88 ;
if ( V_2 -> V_146 != V_147 ) {
V_88 = F_18 ( V_24 , V_144 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_144 = V_88 ;
if ( F_118 ( V_148 , & V_14 -> V_145 ) &&
! F_32 ( V_15 ) -> V_2 && ( V_88 = F_91 ( V_14 ) ) != 0 )
goto V_92;
V_149:
V_55 = F_95 ( V_33 , V_24 , V_144 , V_14 -> type , V_3 , & V_88 ) ;
if ( ! V_55 )
goto V_92;
F_113 ( V_15 , V_55 ) ;
if ( F_50 ( V_55 , V_57 ) ) {
F_116 ( V_15 , V_55 ) ;
F_61 ( V_55 ) ;
goto V_149;
}
V_88 = - V_150 ;
if ( ! F_8 ( V_15 , V_55 ) )
goto V_93;
V_88 = F_119 ( V_15 -> V_61 , V_55 -> V_61 ) ;
if ( V_88 )
goto V_93;
} else {
V_55 = NULL ;
F_113 ( V_15 , V_55 ) ;
}
if ( F_7 ( V_15 ) ) {
struct V_14 * V_151 = F_7 ( V_15 ) ;
F_7 ( V_15 ) = V_55 ;
F_116 ( V_15 , V_55 ) ;
if ( V_55 != V_151 )
F_46 ( V_15 , V_151 ) ;
F_61 ( V_151 ) ;
} else {
F_7 ( V_15 ) = V_55 ;
F_116 ( V_15 , V_55 ) ;
}
return 0 ;
V_93:
F_116 ( V_15 , V_55 ) ;
F_61 ( V_55 ) ;
V_92:
return V_88 ;
}
static long F_120 ( struct V_14 * V_55 , long V_152 )
{
struct V_35 * V_36 = F_32 ( V_55 ) ;
int V_153 ;
F_121 ( V_49 ) ;
F_122 ( & V_36 -> V_56 , & V_49 , V_154 ) ;
V_153 = ! F_50 ( V_55 , V_57 ) &&
! ( V_55 -> V_69 & V_155 ) &&
F_9 ( V_55 ) ;
F_14 ( V_55 ) ;
if ( V_153 )
V_152 = F_123 ( V_152 ) ;
F_124 ( & V_36 -> V_56 , & V_49 ) ;
return V_152 ;
}
static int F_125 ( struct V_86 * V_14 , struct V_134 * V_135 ,
int V_136 , int V_145 )
{
struct V_23 * V_24 = (struct V_23 * ) V_135 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) , * V_156 , * V_157 ;
struct V_14 * V_158 = NULL ;
struct V_14 * V_55 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_159 ;
int V_88 ;
long V_152 ;
V_88 = F_18 ( V_24 , V_136 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_136 = V_88 ;
if ( F_118 ( V_148 , & V_14 -> V_145 ) && ! V_36 -> V_2 &&
( V_88 = F_91 ( V_14 ) ) != 0 )
goto V_92;
V_152 = F_126 ( V_15 , V_145 & V_160 ) ;
V_88 = - V_119 ;
V_158 = F_78 ( F_34 ( V_15 ) , NULL ) ;
if ( V_158 == NULL )
goto V_92;
V_9 = F_127 ( V_158 , 1 , 0 , V_98 ) ;
if ( V_9 == NULL )
goto V_92;
V_149:
V_55 = F_95 ( V_33 , V_24 , V_136 , V_15 -> V_74 , V_3 , & V_88 ) ;
if ( ! V_55 )
goto V_92;
F_12 ( V_55 ) ;
if ( F_50 ( V_55 , V_57 ) ) {
F_14 ( V_55 ) ;
F_61 ( V_55 ) ;
goto V_149;
}
V_88 = - V_128 ;
if ( V_55 -> V_72 != V_80 )
goto V_93;
if ( V_55 -> V_69 & V_155 )
goto V_93;
if ( F_9 ( V_55 ) ) {
V_88 = - V_161 ;
if ( ! V_152 )
goto V_93;
V_152 = F_120 ( V_55 , V_152 ) ;
V_88 = F_128 ( V_152 ) ;
if ( F_129 ( V_84 ) )
goto V_92;
F_61 ( V_55 ) ;
goto V_149;
}
V_159 = V_15 -> V_72 ;
switch ( V_159 ) {
case V_73 :
break;
case V_162 :
V_88 = - V_163 ;
goto V_93;
default:
V_88 = - V_27 ;
goto V_93;
}
F_115 ( V_15 ) ;
if ( V_15 -> V_72 != V_159 ) {
F_14 ( V_15 ) ;
F_14 ( V_55 ) ;
F_61 ( V_55 ) ;
goto V_149;
}
V_88 = F_130 ( V_15 , V_55 , V_158 ) ;
if ( V_88 ) {
F_14 ( V_15 ) ;
goto V_93;
}
F_13 ( V_15 ) ;
F_7 ( V_158 ) = V_15 ;
V_158 -> V_72 = V_162 ;
V_158 -> V_74 = V_15 -> V_74 ;
F_66 ( V_158 ) ;
V_156 = F_32 ( V_158 ) ;
F_131 ( V_158 -> V_48 , & V_156 -> V_164 ) ;
V_157 = F_32 ( V_55 ) ;
if ( V_157 -> V_2 ) {
F_132 ( & V_157 -> V_2 -> V_22 ) ;
V_156 -> V_2 = V_157 -> V_2 ;
}
if ( V_157 -> V_42 . V_41 ) {
F_133 ( & V_157 -> V_42 ) ;
V_156 -> V_42 = V_157 -> V_42 ;
}
F_72 ( V_15 , V_55 ) ;
V_14 -> V_68 = V_165 ;
V_15 -> V_72 = V_162 ;
F_13 ( V_158 ) ;
F_134 () ;
F_7 ( V_15 ) = V_158 ;
F_14 ( V_15 ) ;
F_27 ( & V_55 -> V_17 . V_100 ) ;
F_135 ( & V_55 -> V_17 , V_9 ) ;
F_28 ( & V_55 -> V_17 . V_100 ) ;
F_14 ( V_55 ) ;
V_55 -> V_166 ( V_55 , 0 ) ;
F_61 ( V_55 ) ;
return 0 ;
V_93:
if ( V_55 )
F_14 ( V_55 ) ;
V_92:
F_63 ( V_9 ) ;
if ( V_158 )
F_59 ( V_158 , 0 ) ;
if ( V_55 )
F_61 ( V_55 ) ;
return V_88 ;
}
static int F_136 ( struct V_86 * V_167 , struct V_86 * V_168 )
{
struct V_14 * V_169 = V_167 -> V_15 , * V_9 = V_168 -> V_15 ;
F_13 ( V_169 ) ;
F_13 ( V_9 ) ;
F_7 ( V_169 ) = V_9 ;
F_7 ( V_9 ) = V_169 ;
F_66 ( V_169 ) ;
F_66 ( V_9 ) ;
if ( V_169 -> V_74 != V_115 ) {
V_169 -> V_72 = V_162 ;
V_9 -> V_72 = V_162 ;
V_167 -> V_68 = V_165 ;
V_168 -> V_68 = V_165 ;
}
return 0 ;
}
static void F_137 ( const struct V_86 * V_170 ,
struct V_86 * V_171 )
{
if ( F_118 ( V_148 , & V_170 -> V_145 ) )
F_138 ( V_148 , & V_171 -> V_145 ) ;
if ( F_118 ( V_172 , & V_170 -> V_145 ) )
F_138 ( V_172 , & V_171 -> V_145 ) ;
}
static int F_139 ( struct V_86 * V_14 , struct V_86 * V_173 , int V_145 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_174 ;
struct V_8 * V_9 ;
int V_88 ;
V_88 = - V_91 ;
if ( V_14 -> type != V_75 && V_14 -> type != V_76 )
goto V_92;
V_88 = - V_27 ;
if ( V_15 -> V_72 != V_80 )
goto V_92;
V_9 = F_140 ( V_15 , 0 , V_145 & V_160 , & V_88 ) ;
if ( ! V_9 ) {
if ( V_88 == 0 )
V_88 = - V_27 ;
goto V_92;
}
V_174 = V_9 -> V_15 ;
F_141 ( V_15 , V_9 ) ;
F_142 ( & F_32 ( V_15 ) -> V_56 ) ;
F_12 ( V_174 ) ;
V_173 -> V_68 = V_165 ;
F_137 ( V_14 , V_173 ) ;
F_143 ( V_174 , V_173 ) ;
F_14 ( V_174 ) ;
return 0 ;
V_92:
return V_88 ;
}
static int F_144 ( struct V_86 * V_14 , struct V_134 * V_135 , int * V_175 , int V_20 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 ;
F_145 ( struct V_23 * , V_24 , V_135 ) ;
int V_88 = 0 ;
if ( V_20 ) {
V_15 = F_11 ( V_15 ) ;
V_88 = - V_176 ;
if ( ! V_15 )
goto V_92;
V_88 = 0 ;
} else {
F_13 ( V_15 ) ;
}
V_36 = F_32 ( V_15 ) ;
F_12 ( V_15 ) ;
if ( ! V_36 -> V_2 ) {
V_24 -> V_28 = V_29 ;
V_24 -> V_30 [ 0 ] = 0 ;
* V_175 = sizeof( short ) ;
} else {
struct V_21 * V_2 = V_36 -> V_2 ;
* V_175 = V_2 -> V_25 ;
memcpy ( V_24 , V_2 -> V_37 , * V_175 ) ;
}
F_14 ( V_15 ) ;
F_61 ( V_15 ) ;
V_92:
return V_88 ;
}
static void F_146 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
V_7 -> V_177 = F_147 ( V_9 ) . V_177 ;
F_147 ( V_9 ) . V_177 = NULL ;
for ( V_40 = V_7 -> V_177 -> V_178 - 1 ; V_40 >= 0 ; V_40 -- )
F_148 ( V_7 -> V_177 -> V_177 [ V_40 ] ) ;
}
static void F_149 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_89 = F_147 ( V_9 ) . V_89 ;
if ( F_147 ( V_9 ) . V_177 )
F_146 ( & V_7 , V_9 ) ;
F_150 ( & V_7 ) ;
F_151 ( V_9 ) ;
}
static int F_152 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
unsigned char V_179 = 0 ;
int V_180 = 0 ;
for ( V_40 = V_7 -> V_177 -> V_178 - 1 ; V_40 >= 0 ; V_40 -- ) {
struct V_14 * V_15 = F_153 ( V_7 -> V_177 -> V_177 [ V_40 ] ) ;
if ( V_15 ) {
V_180 ++ ;
V_179 = F_154 ( V_179 ,
F_32 ( V_15 ) -> V_181 ) ;
}
}
if ( F_114 ( V_179 > V_182 ) )
return - V_183 ;
F_147 ( V_9 ) . V_177 = F_155 ( V_7 -> V_177 ) ;
if ( ! F_147 ( V_9 ) . V_177 )
return - V_119 ;
if ( V_180 ) {
for ( V_40 = V_7 -> V_177 -> V_178 - 1 ; V_40 >= 0 ; V_40 -- )
F_156 ( V_7 -> V_177 -> V_177 [ V_40 ] ) ;
}
return V_179 ;
}
static int F_157 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_184 )
{
int V_88 = 0 ;
F_147 ( V_9 ) . V_89 = F_69 ( V_7 -> V_89 ) ;
F_147 ( V_9 ) . V_185 = V_7 -> V_186 . V_185 ;
F_147 ( V_9 ) . V_187 = V_7 -> V_186 . V_187 ;
F_147 ( V_9 ) . V_177 = NULL ;
if ( V_7 -> V_177 && V_184 )
V_88 = F_152 ( V_7 , V_9 ) ;
V_9 -> V_188 = F_149 ;
return V_88 ;
}
static void F_158 ( struct V_8 * V_9 , const struct V_86 * V_14 ,
const struct V_14 * V_55 )
{
if ( F_147 ( V_9 ) . V_89 )
return;
if ( F_118 ( V_148 , & V_14 -> V_145 ) ||
! V_55 -> V_61 ||
F_118 ( V_148 , & V_55 -> V_61 -> V_145 ) ) {
F_147 ( V_9 ) . V_89 = F_69 ( F_70 ( V_84 ) ) ;
F_159 ( & F_147 ( V_9 ) . V_185 , & F_147 ( V_9 ) . V_187 ) ;
}
}
static int F_160 ( struct V_189 * V_189 , struct V_86 * V_14 ,
struct V_190 * V_191 , T_3 V_25 )
{
struct V_192 * V_193 = F_161 ( V_189 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_191 -> V_194 ;
struct V_14 * V_55 = NULL ;
int V_195 = 0 ;
int V_88 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_152 ;
struct V_6 V_196 ;
int V_179 ;
int V_197 = 0 ;
if ( NULL == V_193 -> V_7 )
V_193 -> V_7 = & V_196 ;
F_162 () ;
V_88 = F_163 ( V_14 , V_191 , V_193 -> V_7 , false ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = - V_91 ;
if ( V_191 -> V_198 & V_199 )
goto V_92;
if ( V_191 -> V_200 ) {
V_88 = F_18 ( V_24 , V_191 -> V_200 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_195 = V_88 ;
} else {
V_24 = NULL ;
V_88 = - V_176 ;
V_55 = F_11 ( V_15 ) ;
if ( ! V_55 )
goto V_92;
}
if ( F_118 ( V_148 , & V_14 -> V_145 ) && ! V_36 -> V_2
&& ( V_88 = F_91 ( V_14 ) ) != 0 )
goto V_92;
V_88 = - V_201 ;
if ( V_25 > V_15 -> V_45 - 32 )
goto V_92;
if ( V_25 > V_202 )
V_197 = F_164 ( T_3 ,
V_25 - V_202 ,
V_203 * V_204 ) ;
V_9 = F_165 ( V_15 , V_25 - V_197 , V_197 ,
V_191 -> V_198 & V_205 , & V_88 ,
V_206 ) ;
if ( V_9 == NULL )
goto V_92;
V_88 = F_157 ( V_193 -> V_7 , V_9 , true ) ;
if ( V_88 < 0 )
goto V_207;
V_179 = V_88 + 1 ;
F_2 ( V_193 -> V_7 , V_9 ) ;
F_166 ( V_9 , V_25 - V_197 ) ;
V_9 -> V_197 = V_197 ;
V_9 -> V_25 = V_25 ;
V_88 = F_167 ( V_9 , 0 , V_191 -> V_208 , 0 , V_25 ) ;
if ( V_88 )
goto V_207;
V_152 = F_126 ( V_15 , V_191 -> V_198 & V_205 ) ;
V_149:
if ( ! V_55 ) {
V_88 = - V_59 ;
if ( V_24 == NULL )
goto V_207;
V_55 = F_95 ( V_33 , V_24 , V_195 , V_15 -> V_74 ,
V_3 , & V_88 ) ;
if ( V_55 == NULL )
goto V_207;
}
if ( F_168 ( V_55 , V_9 ) < 0 ) {
V_88 = V_25 ;
goto V_207;
}
F_12 ( V_55 ) ;
V_88 = - V_150 ;
if ( ! F_8 ( V_15 , V_55 ) )
goto V_93;
if ( F_50 ( V_55 , V_57 ) ) {
F_14 ( V_55 ) ;
F_61 ( V_55 ) ;
V_88 = 0 ;
F_12 ( V_15 ) ;
if ( F_7 ( V_15 ) == V_55 ) {
F_7 ( V_15 ) = NULL ;
F_14 ( V_15 ) ;
F_46 ( V_15 , V_55 ) ;
F_61 ( V_55 ) ;
V_88 = - V_128 ;
} else {
F_14 ( V_15 ) ;
}
V_55 = NULL ;
if ( V_88 )
goto V_207;
goto V_149;
}
V_88 = - V_209 ;
if ( V_55 -> V_69 & V_155 )
goto V_93;
if ( V_15 -> V_74 != V_76 ) {
V_88 = F_119 ( V_15 -> V_61 , V_55 -> V_61 ) ;
if ( V_88 )
goto V_93;
}
if ( F_7 ( V_55 ) != V_15 && F_9 ( V_55 ) ) {
if ( ! V_152 ) {
V_88 = - V_161 ;
goto V_93;
}
V_152 = F_120 ( V_55 , V_152 ) ;
V_88 = F_128 ( V_152 ) ;
if ( F_129 ( V_84 ) )
goto V_207;
goto V_149;
}
if ( F_50 ( V_55 , V_210 ) )
F_169 ( V_9 ) ;
F_158 ( V_9 , V_14 , V_55 ) ;
F_170 ( & V_55 -> V_17 , V_9 ) ;
if ( V_179 > F_32 ( V_55 ) -> V_181 )
F_32 ( V_55 ) -> V_181 = V_179 ;
F_14 ( V_55 ) ;
V_55 -> V_166 ( V_55 , V_25 ) ;
F_61 ( V_55 ) ;
F_150 ( V_193 -> V_7 ) ;
return V_25 ;
V_93:
F_14 ( V_55 ) ;
V_207:
F_63 ( V_9 ) ;
V_92:
if ( V_55 )
F_61 ( V_55 ) ;
F_150 ( V_193 -> V_7 ) ;
return V_88 ;
}
static int F_171 ( struct V_189 * V_189 , struct V_86 * V_14 ,
struct V_190 * V_191 , T_3 V_25 )
{
struct V_192 * V_193 = F_161 ( V_189 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_55 = NULL ;
int V_88 , V_211 ;
struct V_8 * V_9 ;
int V_212 = 0 ;
struct V_6 V_196 ;
bool V_213 = false ;
int V_179 ;
int V_197 ;
if ( NULL == V_193 -> V_7 )
V_193 -> V_7 = & V_196 ;
F_162 () ;
V_88 = F_163 ( V_14 , V_191 , V_193 -> V_7 , false ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = - V_91 ;
if ( V_191 -> V_198 & V_199 )
goto V_214;
if ( V_191 -> V_200 ) {
V_88 = V_15 -> V_72 == V_162 ? - V_163 : - V_91 ;
goto V_214;
} else {
V_88 = - V_176 ;
V_55 = F_7 ( V_15 ) ;
if ( ! V_55 )
goto V_214;
}
if ( V_15 -> V_69 & V_215 )
goto V_216;
while ( V_212 < V_25 ) {
V_211 = V_25 - V_212 ;
V_211 = F_164 ( int , V_211 , ( V_15 -> V_45 >> 1 ) - 64 ) ;
V_211 = F_164 ( int , V_211 , F_172 ( 0 ) + V_217 ) ;
V_197 = F_173 ( int , 0 , V_211 - F_172 ( 0 ) ) ;
V_9 = F_165 ( V_15 , V_211 - V_197 , V_197 ,
V_191 -> V_198 & V_205 , & V_88 ,
F_174 ( V_217 ) ) ;
if ( ! V_9 )
goto V_214;
V_88 = F_157 ( V_193 -> V_7 , V_9 , ! V_213 ) ;
if ( V_88 < 0 ) {
F_63 ( V_9 ) ;
goto V_214;
}
V_179 = V_88 + 1 ;
V_213 = true ;
F_166 ( V_9 , V_211 - V_197 ) ;
V_9 -> V_197 = V_197 ;
V_9 -> V_25 = V_211 ;
V_88 = F_167 ( V_9 , 0 , V_191 -> V_208 ,
V_212 , V_211 ) ;
if ( V_88 ) {
F_63 ( V_9 ) ;
goto V_214;
}
F_12 ( V_55 ) ;
if ( F_50 ( V_55 , V_57 ) ||
( V_55 -> V_69 & V_155 ) )
goto V_218;
F_158 ( V_9 , V_14 , V_55 ) ;
F_170 ( & V_55 -> V_17 , V_9 ) ;
if ( V_179 > F_32 ( V_55 ) -> V_181 )
F_32 ( V_55 ) -> V_181 = V_179 ;
F_14 ( V_55 ) ;
V_55 -> V_166 ( V_55 , V_211 ) ;
V_212 += V_211 ;
}
F_150 ( V_193 -> V_7 ) ;
V_193 -> V_7 = NULL ;
return V_212 ;
V_218:
F_14 ( V_55 ) ;
F_63 ( V_9 ) ;
V_216:
if ( V_212 == 0 && ! ( V_191 -> V_198 & V_219 ) )
F_175 ( V_220 , V_84 , 0 ) ;
V_88 = - V_209 ;
V_214:
F_150 ( V_193 -> V_7 ) ;
V_193 -> V_7 = NULL ;
return V_212 ? : V_88 ;
}
static int F_176 ( struct V_189 * V_189 , struct V_86 * V_14 ,
struct V_190 * V_191 , T_3 V_25 )
{
int V_88 ;
struct V_14 * V_15 = V_14 -> V_15 ;
V_88 = F_177 ( V_15 ) ;
if ( V_88 )
return V_88 ;
if ( V_15 -> V_72 != V_162 )
return - V_176 ;
if ( V_191 -> V_200 )
V_191 -> V_200 = 0 ;
return F_160 ( V_189 , V_14 , V_191 , V_25 ) ;
}
static int F_178 ( struct V_189 * V_221 , struct V_86 * V_14 ,
struct V_190 * V_191 , T_3 V_211 ,
int V_145 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( V_15 -> V_72 != V_162 )
return - V_176 ;
return F_179 ( V_221 , V_14 , V_191 , V_211 , V_145 ) ;
}
static void F_180 ( struct V_190 * V_191 , struct V_14 * V_15 )
{
struct V_35 * V_36 = F_32 ( V_15 ) ;
V_191 -> V_200 = 0 ;
if ( V_36 -> V_2 ) {
V_191 -> V_200 = V_36 -> V_2 -> V_25 ;
memcpy ( V_191 -> V_194 , V_36 -> V_2 -> V_37 , V_36 -> V_2 -> V_25 ) ;
}
}
static int F_179 ( struct V_189 * V_221 , struct V_86 * V_14 ,
struct V_190 * V_191 , T_3 V_211 ,
int V_145 )
{
struct V_192 * V_193 = F_161 ( V_221 ) ;
struct V_6 V_196 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
int V_222 = V_145 & V_205 ;
struct V_8 * V_9 ;
int V_88 ;
int V_223 , V_224 ;
V_88 = - V_91 ;
if ( V_145 & V_199 )
goto V_92;
V_191 -> V_200 = 0 ;
V_88 = F_181 ( & V_36 -> V_95 ) ;
if ( V_88 ) {
V_88 = F_128 ( F_182 ( V_15 , V_222 ) ) ;
goto V_92;
}
V_224 = F_183 ( V_15 , V_145 ) ;
V_9 = F_184 ( V_15 , V_145 , & V_223 , & V_224 , & V_88 ) ;
if ( ! V_9 ) {
F_12 ( V_15 ) ;
if ( V_15 -> V_74 == V_76 && V_88 == - V_161 &&
( V_15 -> V_69 & V_155 ) )
V_88 = 0 ;
F_14 ( V_15 ) ;
goto V_93;
}
F_43 ( & V_36 -> V_56 ,
V_50 | V_51 | V_52 ) ;
if ( V_191 -> V_194 )
F_180 ( V_191 , V_9 -> V_15 ) ;
if ( V_211 > V_9 -> V_25 - V_224 )
V_211 = V_9 -> V_25 - V_224 ;
else if ( V_211 < V_9 -> V_25 - V_224 )
V_191 -> V_198 |= V_225 ;
V_88 = F_185 ( V_9 , V_224 , V_191 -> V_208 , V_211 ) ;
if ( V_88 )
goto V_207;
if ( F_50 ( V_15 , V_210 ) )
F_186 ( V_191 , V_15 , V_9 ) ;
if ( ! V_193 -> V_7 ) {
V_193 -> V_7 = & V_196 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
}
F_187 ( V_193 -> V_7 , F_147 ( V_9 ) . V_89 , F_147 ( V_9 ) . V_185 , F_147 ( V_9 ) . V_187 ) ;
F_4 ( V_193 -> V_7 , V_9 ) ;
if ( ! ( V_145 & V_226 ) ) {
if ( F_147 ( V_9 ) . V_177 )
F_146 ( V_193 -> V_7 , V_9 ) ;
F_188 ( V_15 , V_9 -> V_25 ) ;
} else {
F_189 ( V_15 , V_211 ) ;
if ( F_147 ( V_9 ) . V_177 )
V_193 -> V_7 -> V_177 = F_155 ( F_147 ( V_9 ) . V_177 ) ;
}
V_88 = ( V_145 & V_225 ) ? V_9 -> V_25 - V_224 : V_211 ;
F_190 ( V_14 , V_191 , V_193 -> V_7 , V_145 ) ;
V_207:
F_141 ( V_15 , V_9 ) ;
V_93:
F_77 ( & V_36 -> V_95 ) ;
V_92:
return V_88 ;
}
static long F_191 ( struct V_14 * V_15 , long V_152 ,
struct V_8 * V_227 )
{
F_121 ( V_49 ) ;
F_12 ( V_15 ) ;
for (; ; ) {
F_192 ( F_193 ( V_15 ) , & V_49 , V_154 ) ;
if ( F_194 ( & V_15 -> V_17 ) != V_227 ||
V_15 -> V_58 ||
( V_15 -> V_69 & V_155 ) ||
F_129 ( V_84 ) ||
! V_152 )
break;
F_138 ( V_228 , & V_15 -> V_61 -> V_145 ) ;
F_14 ( V_15 ) ;
V_152 = F_195 ( V_152 ) ;
F_12 ( V_15 ) ;
F_196 ( V_228 , & V_15 -> V_61 -> V_145 ) ;
}
F_124 ( F_193 ( V_15 ) , & V_49 ) ;
F_14 ( V_15 ) ;
return V_152 ;
}
static unsigned int F_197 ( const struct V_8 * V_9 )
{
return V_9 -> V_25 - F_147 ( V_9 ) . V_229 ;
}
static int F_198 ( struct V_189 * V_221 , struct V_86 * V_14 ,
struct V_190 * V_191 , T_3 V_211 ,
int V_145 )
{
struct V_192 * V_193 = F_161 ( V_221 ) ;
struct V_6 V_196 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_191 -> V_194 ;
int V_230 = 0 ;
int V_231 = 0 ;
int V_232 ;
int V_88 = 0 ;
long V_152 ;
int V_224 ;
V_88 = - V_27 ;
if ( V_15 -> V_72 != V_162 )
goto V_92;
V_88 = - V_91 ;
if ( V_145 & V_199 )
goto V_92;
V_232 = F_199 ( V_15 , V_145 & V_233 , V_211 ) ;
V_152 = F_182 ( V_15 , V_145 & V_205 ) ;
V_191 -> V_200 = 0 ;
if ( ! V_193 -> V_7 ) {
V_193 -> V_7 = & V_196 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
}
V_88 = F_181 ( & V_36 -> V_95 ) ;
if ( V_88 ) {
V_88 = F_128 ( V_152 ) ;
goto V_92;
}
do {
int V_234 ;
struct V_8 * V_9 , * V_227 ;
F_12 ( V_15 ) ;
V_227 = V_9 = F_200 ( & V_15 -> V_17 ) ;
V_235:
if ( V_9 == NULL ) {
F_32 ( V_15 ) -> V_181 = 0 ;
if ( V_230 >= V_232 )
goto V_236;
V_88 = F_177 ( V_15 ) ;
if ( V_88 )
goto V_236;
if ( V_15 -> V_69 & V_155 )
goto V_236;
F_14 ( V_15 ) ;
V_88 = - V_161 ;
if ( ! V_152 )
break;
F_77 ( & V_36 -> V_95 ) ;
V_152 = F_191 ( V_15 , V_152 , V_227 ) ;
if ( F_129 ( V_84 )
|| F_181 ( & V_36 -> V_95 ) ) {
V_88 = F_128 ( V_152 ) ;
goto V_92;
}
continue;
V_236:
F_14 ( V_15 ) ;
break;
}
V_224 = F_183 ( V_15 , V_145 ) ;
while ( V_224 >= F_197 ( V_9 ) ) {
V_224 -= F_197 ( V_9 ) ;
V_227 = V_9 ;
V_9 = F_201 ( V_9 , & V_15 -> V_17 ) ;
if ( ! V_9 )
goto V_235;
}
F_14 ( V_15 ) ;
if ( V_231 ) {
if ( ( F_147 ( V_9 ) . V_89 != V_193 -> V_7 -> V_89 ) ||
! F_202 ( F_147 ( V_9 ) . V_185 , V_193 -> V_7 -> V_186 . V_185 ) ||
! F_203 ( F_147 ( V_9 ) . V_187 , V_193 -> V_7 -> V_186 . V_187 ) )
break;
} else if ( F_118 ( V_148 , & V_14 -> V_145 ) ) {
F_187 ( V_193 -> V_7 , F_147 ( V_9 ) . V_89 , F_147 ( V_9 ) . V_185 , F_147 ( V_9 ) . V_187 ) ;
V_231 = 1 ;
}
if ( V_24 ) {
F_180 ( V_191 , V_9 -> V_15 ) ;
V_24 = NULL ;
}
V_234 = F_164 (unsigned int, unix_skb_len(skb) - skip, size) ;
if ( F_185 ( V_9 , F_147 ( V_9 ) . V_229 + V_224 ,
V_191 -> V_208 , V_234 ) ) {
if ( V_230 == 0 )
V_230 = - V_237 ;
break;
}
V_230 += V_234 ;
V_211 -= V_234 ;
if ( ! ( V_145 & V_226 ) ) {
F_147 ( V_9 ) . V_229 += V_234 ;
F_188 ( V_15 , V_234 ) ;
if ( F_147 ( V_9 ) . V_177 )
F_146 ( V_193 -> V_7 , V_9 ) ;
if ( F_197 ( V_9 ) )
break;
F_204 ( V_9 , & V_15 -> V_17 ) ;
F_205 ( V_9 ) ;
if ( V_193 -> V_7 -> V_177 )
break;
} else {
if ( F_147 ( V_9 ) . V_177 )
V_193 -> V_7 -> V_177 = F_155 ( F_147 ( V_9 ) . V_177 ) ;
F_189 ( V_15 , V_234 ) ;
break;
}
} while ( V_211 );
F_77 ( & V_36 -> V_95 ) ;
F_190 ( V_14 , V_191 , V_193 -> V_7 , V_145 ) ;
V_92:
return V_230 ? : V_88 ;
}
static int F_206 ( struct V_86 * V_14 , int V_131 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_55 ;
if ( V_131 < V_238 || V_131 > V_239 )
return - V_27 ;
++ V_131 ;
F_12 ( V_15 ) ;
V_15 -> V_69 |= V_131 ;
V_55 = F_7 ( V_15 ) ;
if ( V_55 )
F_13 ( V_55 ) ;
F_14 ( V_15 ) ;
V_15 -> V_77 ( V_15 ) ;
if ( V_55 &&
( V_15 -> V_74 == V_75 || V_15 -> V_74 == V_76 ) ) {
int V_240 = 0 ;
if ( V_131 & V_155 )
V_240 |= V_215 ;
if ( V_131 & V_215 )
V_240 |= V_155 ;
F_12 ( V_55 ) ;
V_55 -> V_69 |= V_240 ;
F_14 ( V_55 ) ;
V_55 -> V_77 ( V_55 ) ;
if ( V_240 == V_70 )
F_44 ( V_55 , V_78 , V_79 ) ;
else if ( V_240 & V_155 )
F_44 ( V_55 , V_78 , V_241 ) ;
}
if ( V_55 )
F_61 ( V_55 ) ;
return 0 ;
}
long F_207 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
long V_242 = 0 ;
if ( V_15 -> V_72 == V_80 )
return - V_27 ;
F_27 ( & V_15 -> V_17 . V_100 ) ;
if ( V_15 -> V_74 == V_75 ||
V_15 -> V_74 == V_76 ) {
F_208 (&sk->sk_receive_queue, skb)
V_242 += F_197 ( V_9 ) ;
} else {
V_9 = F_200 ( & V_15 -> V_17 ) ;
if ( V_9 )
V_242 = V_9 -> V_25 ;
}
F_28 ( & V_15 -> V_17 . V_100 ) ;
return V_242 ;
}
long F_209 ( struct V_14 * V_15 )
{
return F_210 ( V_15 ) ;
}
static int F_211 ( struct V_86 * V_14 , unsigned int V_243 , unsigned long V_244 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
long V_242 = 0 ;
int V_88 ;
switch ( V_243 ) {
case V_245 :
V_242 = F_209 ( V_15 ) ;
V_88 = F_212 ( V_242 , ( int V_246 * ) V_244 ) ;
break;
case V_247 :
V_242 = F_207 ( V_15 ) ;
if ( V_242 < 0 )
V_88 = V_242 ;
else
V_88 = F_212 ( V_242 , ( int V_246 * ) V_244 ) ;
break;
default:
V_88 = - V_248 ;
break;
}
return V_88 ;
}
static unsigned int F_213 ( struct V_249 * V_249 , struct V_86 * V_14 , T_4 * V_49 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
unsigned int V_250 ;
F_214 ( V_249 , F_193 ( V_15 ) , V_49 ) ;
V_250 = 0 ;
if ( V_15 -> V_58 )
V_250 |= V_251 ;
if ( V_15 -> V_69 == V_70 )
V_250 |= V_252 ;
if ( V_15 -> V_69 & V_155 )
V_250 |= V_253 | V_254 | V_255 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_250 |= V_254 | V_255 ;
if ( ( V_15 -> V_74 == V_75 || V_15 -> V_74 == V_76 ) &&
V_15 -> V_72 == V_73 )
V_250 |= V_252 ;
if ( F_37 ( V_15 ) )
V_250 |= V_50 | V_51 | V_52 ;
return V_250 ;
}
static unsigned int F_215 ( struct V_249 * V_249 , struct V_86 * V_14 ,
T_4 * V_49 )
{
struct V_14 * V_15 = V_14 -> V_15 , * V_55 ;
unsigned int V_250 , V_256 ;
F_214 ( V_249 , F_193 ( V_15 ) , V_49 ) ;
V_250 = 0 ;
if ( V_15 -> V_58 || ! F_47 ( & V_15 -> V_257 ) )
V_250 |= V_251 |
( F_50 ( V_15 , V_258 ) ? V_259 : 0 ) ;
if ( V_15 -> V_69 & V_155 )
V_250 |= V_253 | V_254 | V_255 ;
if ( V_15 -> V_69 == V_70 )
V_250 |= V_252 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_250 |= V_254 | V_255 ;
if ( V_15 -> V_74 == V_76 ) {
if ( V_15 -> V_72 == V_73 )
V_250 |= V_252 ;
if ( V_15 -> V_72 == V_260 )
return V_250 ;
}
if ( ! ( F_216 ( V_49 ) & ( V_52 | V_51 | V_50 ) ) )
return V_250 ;
V_256 = F_37 ( V_15 ) ;
V_55 = F_11 ( V_15 ) ;
if ( V_55 ) {
if ( F_7 ( V_55 ) != V_15 ) {
F_214 ( V_249 , & F_32 ( V_55 ) -> V_56 , V_49 ) ;
if ( F_9 ( V_55 ) )
V_256 = 0 ;
}
F_61 ( V_55 ) ;
}
if ( V_256 )
V_250 |= V_50 | V_51 | V_52 ;
else
F_138 ( V_261 , & V_15 -> V_61 -> V_145 ) ;
return V_250 ;
}
static struct V_14 * F_217 ( struct V_262 * V_263 , T_5 * V_264 )
{
unsigned long V_265 = F_218 ( * V_264 ) ;
unsigned long V_266 = F_219 ( * V_264 ) ;
struct V_14 * V_15 ;
unsigned long V_178 = 0 ;
for ( V_15 = F_220 ( & V_5 [ V_266 ] ) ; V_15 ; V_15 = F_221 ( V_15 ) ) {
if ( F_34 ( V_15 ) != F_222 ( V_263 ) )
continue;
if ( ++ V_178 == V_265 )
break;
}
return V_15 ;
}
static struct V_14 * F_223 ( struct V_262 * V_263 ,
struct V_14 * V_15 ,
T_5 * V_264 )
{
unsigned long V_266 ;
while ( V_15 > (struct V_14 * ) V_267 ) {
V_15 = F_221 ( V_15 ) ;
if ( ! V_15 )
goto V_268;
if ( F_34 ( V_15 ) == F_222 ( V_263 ) )
return V_15 ;
}
do {
V_15 = F_217 ( V_263 , V_264 ) ;
if ( V_15 )
return V_15 ;
V_268:
V_266 = F_219 ( * V_264 ) + 1 ;
* V_264 = F_224 ( V_266 , 1 ) ;
} while ( V_266 < F_225 ( V_5 ) );
return NULL ;
}
static void * F_226 ( struct V_262 * V_263 , T_5 * V_264 )
__acquires( V_32 )
{
F_27 ( & V_32 ) ;
if ( ! * V_264 )
return V_267 ;
if ( F_219 ( * V_264 ) >= F_225 ( V_5 ) )
return NULL ;
return F_223 ( V_263 , NULL , V_264 ) ;
}
static void * F_227 ( struct V_262 * V_263 , void * V_269 , T_5 * V_264 )
{
++ * V_264 ;
return F_223 ( V_263 , V_269 , V_264 ) ;
}
static void F_228 ( struct V_262 * V_263 , void * V_269 )
__releases( V_32 )
{
F_28 ( & V_32 ) ;
}
static int F_229 ( struct V_262 * V_263 , void * V_269 )
{
if ( V_269 == V_267 )
F_230 ( V_263 , L_4
L_5 ) ;
else {
struct V_14 * V_19 = V_269 ;
struct V_35 * V_36 = F_32 ( V_19 ) ;
F_12 ( V_19 ) ;
F_231 ( V_263 , L_6 ,
V_19 ,
F_38 ( & V_19 -> V_270 ) ,
0 ,
V_19 -> V_72 == V_80 ? V_271 : 0 ,
V_19 -> V_74 ,
V_19 -> V_61 ?
( V_19 -> V_72 == V_162 ? V_165 : V_111 ) :
( V_19 -> V_72 == V_162 ? V_272 : V_273 ) ,
F_232 ( V_19 ) ) ;
if ( V_36 -> V_2 ) {
int V_40 , V_25 ;
F_233 ( V_263 , ' ' ) ;
V_40 = 0 ;
V_25 = V_36 -> V_2 -> V_25 - sizeof( short ) ;
if ( ! F_234 ( V_19 ) )
V_25 -- ;
else {
F_233 ( V_263 , '@' ) ;
V_40 ++ ;
}
for ( ; V_40 < V_25 ; V_40 ++ )
F_233 ( V_263 , V_36 -> V_2 -> V_37 -> V_30 [ V_40 ] ) ;
}
F_14 ( V_19 ) ;
F_233 ( V_263 , '\n' ) ;
}
return 0 ;
}
static int F_235 ( struct V_39 * V_39 , struct V_249 * V_249 )
{
return F_236 ( V_39 , V_249 , & V_274 ,
sizeof( struct V_275 ) ) ;
}
static int T_6 F_237 ( struct V_33 * V_33 )
{
int error = - V_119 ;
V_33 -> V_103 . V_104 = 10 ;
if ( F_238 ( V_33 ) )
goto V_92;
#ifdef F_239
if ( ! F_240 ( L_7 , 0 , V_33 -> V_276 , & V_277 ) ) {
F_241 ( V_33 ) ;
goto V_92;
}
#endif
error = 0 ;
V_92:
return error ;
}
static void T_7 F_242 ( struct V_33 * V_33 )
{
F_241 ( V_33 ) ;
F_243 ( L_7 , V_33 -> V_276 ) ;
}
static int T_8 F_244 ( void )
{
int V_278 = - 1 ;
F_245 ( sizeof( struct V_279 ) > F_246 ( struct V_8 , V_280 ) ) ;
V_278 = F_247 ( & V_99 , 1 ) ;
if ( V_278 != 0 ) {
F_52 ( V_281 L_8 ,
V_282 ) ;
goto V_92;
}
F_248 ( & V_283 ) ;
F_249 ( & V_284 ) ;
V_92:
return V_278 ;
}
static void T_9 F_250 ( void )
{
F_251 ( V_97 ) ;
F_252 ( & V_99 ) ;
F_253 ( & V_284 ) ;
}
