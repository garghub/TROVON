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
static int F_75 ( struct V_14 * V_15 , int V_94 )
{
struct V_35 * V_36 = F_32 ( V_15 ) ;
if ( F_76 ( & V_36 -> V_95 ) )
return - V_96 ;
V_15 -> V_97 = V_94 ;
F_77 ( & V_36 -> V_95 ) ;
return 0 ;
}
static struct V_14 * F_78 ( struct V_33 * V_33 , struct V_86 * V_14 )
{
struct V_14 * V_15 = NULL ;
struct V_35 * V_36 ;
F_79 ( & V_63 ) ;
if ( F_58 ( & V_63 ) > 2 * F_80 () )
goto V_92;
V_15 = F_81 ( V_33 , V_98 , V_99 , & V_100 ) ;
if ( ! V_15 )
goto V_92;
F_82 ( V_14 , V_15 ) ;
F_83 ( & V_15 -> V_17 . V_101 ,
& V_102 ) ;
V_15 -> V_103 = F_39 ;
V_15 -> V_18 = V_33 -> V_104 . V_105 ;
V_15 -> V_106 = F_51 ;
V_36 = F_32 ( V_15 ) ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_71 = NULL ;
F_84 ( & V_36 -> V_101 ) ;
F_85 ( & V_36 -> V_107 , 0 ) ;
F_86 ( & V_36 -> V_108 ) ;
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
static int F_89 ( struct V_33 * V_33 , struct V_86 * V_14 , int V_109 ,
int V_110 )
{
if ( V_109 && V_109 != V_98 )
return - V_111 ;
V_14 -> V_68 = V_112 ;
switch ( V_14 -> type ) {
case V_75 :
V_14 -> V_113 = & V_114 ;
break;
case V_115 :
V_14 -> type = V_116 ;
case V_116 :
V_14 -> V_113 = & V_117 ;
break;
case V_76 :
V_14 -> V_113 = & V_118 ;
break;
default:
return - V_119 ;
}
return F_78 ( V_33 , V_14 ) ? 0 : - V_120 ;
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
static V_11 V_121 = 1 ;
struct V_21 * V_2 ;
int V_88 ;
unsigned int V_122 = 0 ;
V_88 = F_76 ( & V_36 -> V_95 ) ;
if ( V_88 )
return V_88 ;
V_88 = 0 ;
if ( V_36 -> V_2 )
goto V_92;
V_88 = - V_120 ;
V_2 = F_92 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_99 ) ;
if ( ! V_2 )
goto V_92;
V_2 -> V_37 -> V_28 = V_29 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
V_123:
V_2 -> V_25 = sprintf ( V_2 -> V_37 -> V_30 + 1 , L_3 , V_121 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_5 ( F_19 ( V_2 -> V_37 , V_2 -> V_25 , 0 ) ) ;
F_27 ( & V_32 ) ;
V_121 = ( V_121 + 1 ) & 0xFFFFF ;
if ( F_30 ( V_33 , V_2 -> V_37 , V_2 -> V_25 , V_14 -> type ,
V_2 -> V_3 ) ) {
F_28 ( & V_32 ) ;
F_94 () ;
if ( V_122 ++ == 0xFFFFF ) {
V_88 = - V_124 ;
F_17 ( V_2 ) ;
goto V_92;
}
goto V_123;
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
V_88 = F_96 ( V_34 -> V_30 , V_125 , & V_42 ) ;
if ( V_88 )
goto V_126;
V_39 = V_42 . V_41 -> V_43 ;
V_88 = F_97 ( V_39 , V_127 ) ;
if ( V_88 )
goto V_128;
V_88 = - V_129 ;
if ( ! F_98 ( V_39 -> V_130 ) )
goto V_128;
V_36 = F_36 ( V_39 ) ;
if ( ! V_36 )
goto V_128;
if ( V_36 -> V_74 == type )
F_99 ( & V_42 ) ;
F_64 ( & V_42 ) ;
V_88 = - V_131 ;
if ( V_36 -> V_74 != type ) {
F_61 ( V_36 ) ;
goto V_126;
}
} else {
V_88 = - V_129 ;
V_36 = F_35 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_36 ) {
struct V_41 * V_41 ;
V_41 = F_32 ( V_36 ) -> V_42 . V_41 ;
if ( V_41 )
F_99 ( & F_32 ( V_36 ) -> V_42 ) ;
} else
goto V_126;
}
return V_36 ;
V_128:
F_64 ( & V_42 ) ;
V_126:
* error = V_88 ;
return NULL ;
}
static int F_100 ( const char * V_30 , T_2 V_132 , struct V_42 * V_133 )
{
struct V_41 * V_41 ;
struct V_42 V_42 ;
int V_88 = 0 ;
V_41 = F_101 ( V_134 , V_30 , & V_42 , 0 ) ;
V_88 = F_102 ( V_41 ) ;
if ( F_103 ( V_41 ) )
return V_88 ;
V_88 = F_104 ( & V_42 , V_41 , V_132 , 0 ) ;
if ( ! V_88 ) {
V_88 = F_105 ( V_42 . V_41 -> V_43 , V_41 , V_132 , 0 ) ;
if ( ! V_88 ) {
V_133 -> V_71 = F_106 ( V_42 . V_71 ) ;
V_133 -> V_41 = F_107 ( V_41 ) ;
}
}
F_108 ( & V_42 , V_41 ) ;
return V_88 ;
}
static int F_109 ( struct V_86 * V_14 , struct V_135 * V_136 , int V_137 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_136 ;
char * V_30 = V_24 -> V_30 ;
int V_88 ;
unsigned int V_3 ;
struct V_21 * V_2 ;
struct V_1 * V_31 ;
V_88 = - V_27 ;
if ( V_24 -> V_28 != V_29 )
goto V_92;
if ( V_137 == sizeof( short ) ) {
V_88 = F_91 ( V_14 ) ;
goto V_92;
}
V_88 = F_18 ( V_24 , V_137 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_137 = V_88 ;
V_88 = F_76 ( & V_36 -> V_95 ) ;
if ( V_88 )
goto V_92;
V_88 = - V_27 ;
if ( V_36 -> V_2 )
goto V_138;
V_88 = - V_120 ;
V_2 = F_110 ( sizeof( * V_2 ) + V_137 , V_99 ) ;
if ( ! V_2 )
goto V_138;
memcpy ( V_2 -> V_37 , V_24 , V_137 ) ;
V_2 -> V_25 = V_137 ;
V_2 -> V_3 = V_3 ^ V_15 -> V_74 ;
F_93 ( & V_2 -> V_22 , 1 ) ;
if ( V_30 [ 0 ] ) {
struct V_42 V_42 ;
T_2 V_132 = V_139 |
( F_111 ( V_14 ) -> V_130 & ~ F_112 () ) ;
V_88 = F_100 ( V_30 , V_132 , & V_42 ) ;
if ( V_88 ) {
if ( V_88 == - V_140 )
V_88 = - V_141 ;
F_15 ( V_2 ) ;
goto V_138;
}
V_2 -> V_3 = V_4 ;
V_3 = V_42 . V_41 -> V_43 -> V_142 & ( V_4 - 1 ) ;
F_27 ( & V_32 ) ;
V_36 -> V_42 = V_42 ;
V_31 = & V_5 [ V_3 ] ;
} else {
F_27 ( & V_32 ) ;
V_88 = - V_141 ;
if ( F_30 ( V_33 , V_24 , V_137 ,
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
V_138:
F_77 ( & V_36 -> V_95 ) ;
V_92:
return V_88 ;
}
static void F_113 ( struct V_14 * V_143 , struct V_14 * V_144 )
{
if ( F_114 ( V_143 == V_144 ) || ! V_144 ) {
F_12 ( V_143 ) ;
return;
}
if ( V_143 < V_144 ) {
F_12 ( V_143 ) ;
F_115 ( V_144 ) ;
} else {
F_12 ( V_144 ) ;
F_115 ( V_143 ) ;
}
}
static void F_116 ( struct V_14 * V_143 , struct V_14 * V_144 )
{
if ( F_114 ( V_143 == V_144 ) || ! V_144 ) {
F_14 ( V_143 ) ;
return;
}
F_14 ( V_143 ) ;
F_14 ( V_144 ) ;
}
static int F_117 ( struct V_86 * V_14 , struct V_135 * V_2 ,
int V_145 , int V_146 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_2 ;
struct V_14 * V_55 ;
unsigned int V_3 ;
int V_88 ;
if ( V_2 -> V_147 != V_148 ) {
V_88 = F_18 ( V_24 , V_145 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_145 = V_88 ;
if ( F_118 ( V_149 , & V_14 -> V_146 ) &&
! F_32 ( V_15 ) -> V_2 && ( V_88 = F_91 ( V_14 ) ) != 0 )
goto V_92;
V_150:
V_55 = F_95 ( V_33 , V_24 , V_145 , V_14 -> type , V_3 , & V_88 ) ;
if ( ! V_55 )
goto V_92;
F_113 ( V_15 , V_55 ) ;
if ( F_50 ( V_55 , V_57 ) ) {
F_116 ( V_15 , V_55 ) ;
F_61 ( V_55 ) ;
goto V_150;
}
V_88 = - V_151 ;
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
struct V_14 * V_152 = F_7 ( V_15 ) ;
F_7 ( V_15 ) = V_55 ;
F_116 ( V_15 , V_55 ) ;
if ( V_55 != V_152 )
F_46 ( V_15 , V_152 ) ;
F_61 ( V_152 ) ;
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
static long F_120 ( struct V_14 * V_55 , long V_153 )
{
struct V_35 * V_36 = F_32 ( V_55 ) ;
int V_154 ;
F_121 ( V_49 ) ;
F_122 ( & V_36 -> V_56 , & V_49 , V_155 ) ;
V_154 = ! F_50 ( V_55 , V_57 ) &&
! ( V_55 -> V_69 & V_156 ) &&
F_9 ( V_55 ) ;
F_14 ( V_55 ) ;
if ( V_154 )
V_153 = F_123 ( V_153 ) ;
F_124 ( & V_36 -> V_56 , & V_49 ) ;
return V_153 ;
}
static int F_125 ( struct V_86 * V_14 , struct V_135 * V_136 ,
int V_137 , int V_146 )
{
struct V_23 * V_24 = (struct V_23 * ) V_136 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) , * V_157 , * V_158 ;
struct V_14 * V_159 = NULL ;
struct V_14 * V_55 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_160 ;
int V_88 ;
long V_153 ;
V_88 = F_18 ( V_24 , V_137 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_137 = V_88 ;
if ( F_118 ( V_149 , & V_14 -> V_146 ) && ! V_36 -> V_2 &&
( V_88 = F_91 ( V_14 ) ) != 0 )
goto V_92;
V_153 = F_126 ( V_15 , V_146 & V_161 ) ;
V_88 = - V_120 ;
V_159 = F_78 ( F_34 ( V_15 ) , NULL ) ;
if ( V_159 == NULL )
goto V_92;
V_9 = F_127 ( V_159 , 1 , 0 , V_99 ) ;
if ( V_9 == NULL )
goto V_92;
V_150:
V_55 = F_95 ( V_33 , V_24 , V_137 , V_15 -> V_74 , V_3 , & V_88 ) ;
if ( ! V_55 )
goto V_92;
F_12 ( V_55 ) ;
if ( F_50 ( V_55 , V_57 ) ) {
F_14 ( V_55 ) ;
F_61 ( V_55 ) ;
goto V_150;
}
V_88 = - V_129 ;
if ( V_55 -> V_72 != V_80 )
goto V_93;
if ( V_55 -> V_69 & V_156 )
goto V_93;
if ( F_9 ( V_55 ) ) {
V_88 = - V_162 ;
if ( ! V_153 )
goto V_93;
V_153 = F_120 ( V_55 , V_153 ) ;
V_88 = F_128 ( V_153 ) ;
if ( F_129 ( V_84 ) )
goto V_92;
F_61 ( V_55 ) ;
goto V_150;
}
V_160 = V_15 -> V_72 ;
switch ( V_160 ) {
case V_73 :
break;
case V_163 :
V_88 = - V_164 ;
goto V_93;
default:
V_88 = - V_27 ;
goto V_93;
}
F_115 ( V_15 ) ;
if ( V_15 -> V_72 != V_160 ) {
F_14 ( V_15 ) ;
F_14 ( V_55 ) ;
F_61 ( V_55 ) ;
goto V_150;
}
V_88 = F_130 ( V_15 , V_55 , V_159 ) ;
if ( V_88 ) {
F_14 ( V_15 ) ;
goto V_93;
}
F_13 ( V_15 ) ;
F_7 ( V_159 ) = V_15 ;
V_159 -> V_72 = V_163 ;
V_159 -> V_74 = V_15 -> V_74 ;
F_66 ( V_159 ) ;
V_157 = F_32 ( V_159 ) ;
F_131 ( V_159 -> V_48 , & V_157 -> V_165 ) ;
V_158 = F_32 ( V_55 ) ;
if ( V_158 -> V_2 ) {
F_132 ( & V_158 -> V_2 -> V_22 ) ;
V_157 -> V_2 = V_158 -> V_2 ;
}
if ( V_158 -> V_42 . V_41 ) {
F_133 ( & V_158 -> V_42 ) ;
V_157 -> V_42 = V_158 -> V_42 ;
}
F_72 ( V_15 , V_55 ) ;
V_14 -> V_68 = V_166 ;
V_15 -> V_72 = V_163 ;
F_13 ( V_159 ) ;
F_134 () ;
F_7 ( V_15 ) = V_159 ;
F_14 ( V_15 ) ;
F_27 ( & V_55 -> V_17 . V_101 ) ;
F_135 ( & V_55 -> V_17 , V_9 ) ;
F_28 ( & V_55 -> V_17 . V_101 ) ;
F_14 ( V_55 ) ;
V_55 -> V_167 ( V_55 , 0 ) ;
F_61 ( V_55 ) ;
return 0 ;
V_93:
if ( V_55 )
F_14 ( V_55 ) ;
V_92:
F_63 ( V_9 ) ;
if ( V_159 )
F_59 ( V_159 , 0 ) ;
if ( V_55 )
F_61 ( V_55 ) ;
return V_88 ;
}
static int F_136 ( struct V_86 * V_168 , struct V_86 * V_169 )
{
struct V_14 * V_170 = V_168 -> V_15 , * V_9 = V_169 -> V_15 ;
F_13 ( V_170 ) ;
F_13 ( V_9 ) ;
F_7 ( V_170 ) = V_9 ;
F_7 ( V_9 ) = V_170 ;
F_66 ( V_170 ) ;
F_66 ( V_9 ) ;
if ( V_170 -> V_74 != V_116 ) {
V_170 -> V_72 = V_163 ;
V_9 -> V_72 = V_163 ;
V_168 -> V_68 = V_166 ;
V_169 -> V_68 = V_166 ;
}
return 0 ;
}
static void F_137 ( const struct V_86 * V_171 ,
struct V_86 * V_172 )
{
if ( F_118 ( V_149 , & V_171 -> V_146 ) )
F_138 ( V_149 , & V_172 -> V_146 ) ;
if ( F_118 ( V_173 , & V_171 -> V_146 ) )
F_138 ( V_173 , & V_172 -> V_146 ) ;
}
static int F_139 ( struct V_86 * V_14 , struct V_86 * V_174 , int V_146 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_175 ;
struct V_8 * V_9 ;
int V_88 ;
V_88 = - V_91 ;
if ( V_14 -> type != V_75 && V_14 -> type != V_76 )
goto V_92;
V_88 = - V_27 ;
if ( V_15 -> V_72 != V_80 )
goto V_92;
V_9 = F_140 ( V_15 , 0 , V_146 & V_161 , & V_88 ) ;
if ( ! V_9 ) {
if ( V_88 == 0 )
V_88 = - V_27 ;
goto V_92;
}
V_175 = V_9 -> V_15 ;
F_141 ( V_15 , V_9 ) ;
F_142 ( & F_32 ( V_15 ) -> V_56 ) ;
F_12 ( V_175 ) ;
V_174 -> V_68 = V_166 ;
F_137 ( V_14 , V_174 ) ;
F_143 ( V_175 , V_174 ) ;
F_14 ( V_175 ) ;
return 0 ;
V_92:
return V_88 ;
}
static int F_144 ( struct V_86 * V_14 , struct V_135 * V_136 , int * V_176 , int V_20 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 ;
F_145 ( struct V_23 * , V_24 , V_136 ) ;
int V_88 = 0 ;
if ( V_20 ) {
V_15 = F_11 ( V_15 ) ;
V_88 = - V_177 ;
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
* V_176 = sizeof( short ) ;
} else {
struct V_21 * V_2 = V_36 -> V_2 ;
* V_176 = V_2 -> V_25 ;
memcpy ( V_24 , V_2 -> V_37 , * V_176 ) ;
}
F_14 ( V_15 ) ;
F_61 ( V_15 ) ;
V_92:
return V_88 ;
}
static void F_146 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
V_7 -> V_178 = F_147 ( V_9 ) . V_178 ;
F_147 ( V_9 ) . V_178 = NULL ;
for ( V_40 = V_7 -> V_178 -> V_179 - 1 ; V_40 >= 0 ; V_40 -- )
F_148 ( V_7 -> V_178 -> V_178 [ V_40 ] ) ;
}
static void F_149 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_89 = F_147 ( V_9 ) . V_89 ;
if ( F_147 ( V_9 ) . V_178 )
F_146 ( & V_7 , V_9 ) ;
F_150 ( & V_7 ) ;
F_151 ( V_9 ) ;
}
static int F_152 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
unsigned char V_180 = 0 ;
int V_181 = 0 ;
for ( V_40 = V_7 -> V_178 -> V_179 - 1 ; V_40 >= 0 ; V_40 -- ) {
struct V_14 * V_15 = F_153 ( V_7 -> V_178 -> V_178 [ V_40 ] ) ;
if ( V_15 ) {
V_181 ++ ;
V_180 = F_154 ( V_180 ,
F_32 ( V_15 ) -> V_182 ) ;
}
}
if ( F_114 ( V_180 > V_183 ) )
return - V_184 ;
F_147 ( V_9 ) . V_178 = F_155 ( V_7 -> V_178 ) ;
if ( ! F_147 ( V_9 ) . V_178 )
return - V_120 ;
if ( V_181 ) {
for ( V_40 = V_7 -> V_178 -> V_179 - 1 ; V_40 >= 0 ; V_40 -- )
F_156 ( V_7 -> V_178 -> V_178 [ V_40 ] ) ;
}
return V_180 ;
}
static int F_157 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_185 )
{
int V_88 = 0 ;
F_147 ( V_9 ) . V_89 = F_69 ( V_7 -> V_89 ) ;
F_147 ( V_9 ) . V_186 = V_7 -> V_187 . V_186 ;
F_147 ( V_9 ) . V_188 = V_7 -> V_187 . V_188 ;
F_147 ( V_9 ) . V_178 = NULL ;
if ( V_7 -> V_178 && V_185 )
V_88 = F_152 ( V_7 , V_9 ) ;
V_9 -> V_189 = F_149 ;
return V_88 ;
}
static void F_158 ( struct V_8 * V_9 , const struct V_86 * V_14 ,
const struct V_14 * V_55 )
{
if ( F_147 ( V_9 ) . V_89 )
return;
if ( F_118 ( V_149 , & V_14 -> V_146 ) ||
! V_55 -> V_61 ||
F_118 ( V_149 , & V_55 -> V_61 -> V_146 ) ) {
F_147 ( V_9 ) . V_89 = F_69 ( F_70 ( V_84 ) ) ;
F_159 ( & F_147 ( V_9 ) . V_186 , & F_147 ( V_9 ) . V_188 ) ;
}
}
static int F_160 ( struct V_190 * V_190 , struct V_86 * V_14 ,
struct V_191 * V_192 , T_3 V_25 )
{
struct V_193 * V_194 = F_161 ( V_190 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_34 ( V_15 ) ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_192 -> V_195 ;
struct V_14 * V_55 = NULL ;
int V_196 = 0 ;
int V_88 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_153 ;
struct V_6 V_197 ;
int V_180 ;
int V_198 = 0 ;
if ( NULL == V_194 -> V_7 )
V_194 -> V_7 = & V_197 ;
F_162 () ;
V_88 = F_163 ( V_14 , V_192 , V_194 -> V_7 , false ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = - V_91 ;
if ( V_192 -> V_199 & V_200 )
goto V_92;
if ( V_192 -> V_201 ) {
V_88 = F_18 ( V_24 , V_192 -> V_201 , & V_3 ) ;
if ( V_88 < 0 )
goto V_92;
V_196 = V_88 ;
} else {
V_24 = NULL ;
V_88 = - V_177 ;
V_55 = F_11 ( V_15 ) ;
if ( ! V_55 )
goto V_92;
}
if ( F_118 ( V_149 , & V_14 -> V_146 ) && ! V_36 -> V_2
&& ( V_88 = F_91 ( V_14 ) ) != 0 )
goto V_92;
V_88 = - V_202 ;
if ( V_25 > V_15 -> V_45 - 32 )
goto V_92;
if ( V_25 > V_203 )
V_198 = F_164 ( T_3 ,
V_25 - V_203 ,
V_204 * V_205 ) ;
V_9 = F_165 ( V_15 , V_25 - V_198 , V_198 ,
V_192 -> V_199 & V_206 , & V_88 ,
V_207 ) ;
if ( V_9 == NULL )
goto V_92;
V_88 = F_157 ( V_194 -> V_7 , V_9 , true ) ;
if ( V_88 < 0 )
goto V_208;
V_180 = V_88 + 1 ;
F_2 ( V_194 -> V_7 , V_9 ) ;
F_166 ( V_9 , V_25 - V_198 ) ;
V_9 -> V_198 = V_198 ;
V_9 -> V_25 = V_25 ;
V_88 = F_167 ( V_9 , 0 , V_192 -> V_209 , 0 , V_25 ) ;
if ( V_88 )
goto V_208;
V_153 = F_126 ( V_15 , V_192 -> V_199 & V_206 ) ;
V_150:
if ( ! V_55 ) {
V_88 = - V_59 ;
if ( V_24 == NULL )
goto V_208;
V_55 = F_95 ( V_33 , V_24 , V_196 , V_15 -> V_74 ,
V_3 , & V_88 ) ;
if ( V_55 == NULL )
goto V_208;
}
if ( F_168 ( V_55 , V_9 ) < 0 ) {
V_88 = V_25 ;
goto V_208;
}
F_12 ( V_55 ) ;
V_88 = - V_151 ;
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
V_88 = - V_129 ;
} else {
F_14 ( V_15 ) ;
}
V_55 = NULL ;
if ( V_88 )
goto V_208;
goto V_150;
}
V_88 = - V_210 ;
if ( V_55 -> V_69 & V_156 )
goto V_93;
if ( V_15 -> V_74 != V_76 ) {
V_88 = F_119 ( V_15 -> V_61 , V_55 -> V_61 ) ;
if ( V_88 )
goto V_93;
}
if ( F_7 ( V_55 ) != V_15 && F_9 ( V_55 ) ) {
if ( ! V_153 ) {
V_88 = - V_162 ;
goto V_93;
}
V_153 = F_120 ( V_55 , V_153 ) ;
V_88 = F_128 ( V_153 ) ;
if ( F_129 ( V_84 ) )
goto V_208;
goto V_150;
}
if ( F_50 ( V_55 , V_211 ) )
F_169 ( V_9 ) ;
F_158 ( V_9 , V_14 , V_55 ) ;
F_170 ( & V_55 -> V_17 , V_9 ) ;
if ( V_180 > F_32 ( V_55 ) -> V_182 )
F_32 ( V_55 ) -> V_182 = V_180 ;
F_14 ( V_55 ) ;
V_55 -> V_167 ( V_55 , V_25 ) ;
F_61 ( V_55 ) ;
F_150 ( V_194 -> V_7 ) ;
return V_25 ;
V_93:
F_14 ( V_55 ) ;
V_208:
F_63 ( V_9 ) ;
V_92:
if ( V_55 )
F_61 ( V_55 ) ;
F_150 ( V_194 -> V_7 ) ;
return V_88 ;
}
static int F_171 ( struct V_190 * V_190 , struct V_86 * V_14 ,
struct V_191 * V_192 , T_3 V_25 )
{
struct V_193 * V_194 = F_161 ( V_190 ) ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_55 = NULL ;
int V_88 , V_212 ;
struct V_8 * V_9 ;
int V_213 = 0 ;
struct V_6 V_197 ;
bool V_214 = false ;
int V_180 ;
int V_198 ;
if ( NULL == V_194 -> V_7 )
V_194 -> V_7 = & V_197 ;
F_162 () ;
V_88 = F_163 ( V_14 , V_192 , V_194 -> V_7 , false ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = - V_91 ;
if ( V_192 -> V_199 & V_200 )
goto V_215;
if ( V_192 -> V_201 ) {
V_88 = V_15 -> V_72 == V_163 ? - V_164 : - V_91 ;
goto V_215;
} else {
V_88 = - V_177 ;
V_55 = F_7 ( V_15 ) ;
if ( ! V_55 )
goto V_215;
}
if ( V_15 -> V_69 & V_216 )
goto V_217;
while ( V_213 < V_25 ) {
V_212 = V_25 - V_213 ;
V_212 = F_164 ( int , V_212 , ( V_15 -> V_45 >> 1 ) - 64 ) ;
V_212 = F_164 ( int , V_212 , F_172 ( 0 ) + V_218 ) ;
V_198 = F_173 ( int , 0 , V_212 - F_172 ( 0 ) ) ;
V_9 = F_165 ( V_15 , V_212 - V_198 , V_198 ,
V_192 -> V_199 & V_206 , & V_88 ,
F_174 ( V_218 ) ) ;
if ( ! V_9 )
goto V_215;
V_88 = F_157 ( V_194 -> V_7 , V_9 , ! V_214 ) ;
if ( V_88 < 0 ) {
F_63 ( V_9 ) ;
goto V_215;
}
V_180 = V_88 + 1 ;
V_214 = true ;
F_166 ( V_9 , V_212 - V_198 ) ;
V_9 -> V_198 = V_198 ;
V_9 -> V_25 = V_212 ;
V_88 = F_167 ( V_9 , 0 , V_192 -> V_209 ,
V_213 , V_212 ) ;
if ( V_88 ) {
F_63 ( V_9 ) ;
goto V_215;
}
F_12 ( V_55 ) ;
if ( F_50 ( V_55 , V_57 ) ||
( V_55 -> V_69 & V_156 ) )
goto V_219;
F_158 ( V_9 , V_14 , V_55 ) ;
F_170 ( & V_55 -> V_17 , V_9 ) ;
if ( V_180 > F_32 ( V_55 ) -> V_182 )
F_32 ( V_55 ) -> V_182 = V_180 ;
F_14 ( V_55 ) ;
V_55 -> V_167 ( V_55 , V_212 ) ;
V_213 += V_212 ;
}
F_150 ( V_194 -> V_7 ) ;
V_194 -> V_7 = NULL ;
return V_213 ;
V_219:
F_14 ( V_55 ) ;
F_63 ( V_9 ) ;
V_217:
if ( V_213 == 0 && ! ( V_192 -> V_199 & V_220 ) )
F_175 ( V_221 , V_84 , 0 ) ;
V_88 = - V_210 ;
V_215:
F_150 ( V_194 -> V_7 ) ;
V_194 -> V_7 = NULL ;
return V_213 ? : V_88 ;
}
static int F_176 ( struct V_190 * V_190 , struct V_86 * V_14 ,
struct V_191 * V_192 , T_3 V_25 )
{
int V_88 ;
struct V_14 * V_15 = V_14 -> V_15 ;
V_88 = F_177 ( V_15 ) ;
if ( V_88 )
return V_88 ;
if ( V_15 -> V_72 != V_163 )
return - V_177 ;
if ( V_192 -> V_201 )
V_192 -> V_201 = 0 ;
return F_160 ( V_190 , V_14 , V_192 , V_25 ) ;
}
static int F_178 ( struct V_190 * V_222 , struct V_86 * V_14 ,
struct V_191 * V_192 , T_3 V_212 ,
int V_146 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( V_15 -> V_72 != V_163 )
return - V_177 ;
return F_179 ( V_222 , V_14 , V_192 , V_212 , V_146 ) ;
}
static void F_180 ( struct V_191 * V_192 , struct V_14 * V_15 )
{
struct V_35 * V_36 = F_32 ( V_15 ) ;
if ( V_36 -> V_2 ) {
V_192 -> V_201 = V_36 -> V_2 -> V_25 ;
memcpy ( V_192 -> V_195 , V_36 -> V_2 -> V_37 , V_36 -> V_2 -> V_25 ) ;
}
}
static int F_179 ( struct V_190 * V_222 , struct V_86 * V_14 ,
struct V_191 * V_192 , T_3 V_212 ,
int V_146 )
{
struct V_193 * V_194 = F_161 ( V_222 ) ;
struct V_6 V_197 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
int V_223 = V_146 & V_206 ;
struct V_8 * V_9 ;
int V_88 ;
int V_224 , V_225 ;
V_88 = - V_91 ;
if ( V_146 & V_200 )
goto V_92;
V_88 = F_76 ( & V_36 -> V_95 ) ;
if ( V_88 ) {
V_88 = F_128 ( F_181 ( V_15 , V_223 ) ) ;
goto V_92;
}
V_225 = F_182 ( V_15 , V_146 ) ;
V_9 = F_183 ( V_15 , V_146 , & V_224 , & V_225 , & V_88 ) ;
if ( ! V_9 ) {
F_12 ( V_15 ) ;
if ( V_15 -> V_74 == V_76 && V_88 == - V_162 &&
( V_15 -> V_69 & V_156 ) )
V_88 = 0 ;
F_14 ( V_15 ) ;
goto V_93;
}
F_43 ( & V_36 -> V_56 ,
V_50 | V_51 | V_52 ) ;
if ( V_192 -> V_195 )
F_180 ( V_192 , V_9 -> V_15 ) ;
if ( V_212 > V_9 -> V_25 - V_225 )
V_212 = V_9 -> V_25 - V_225 ;
else if ( V_212 < V_9 -> V_25 - V_225 )
V_192 -> V_199 |= V_226 ;
V_88 = F_184 ( V_9 , V_225 , V_192 -> V_209 , V_212 ) ;
if ( V_88 )
goto V_208;
if ( F_50 ( V_15 , V_211 ) )
F_185 ( V_192 , V_15 , V_9 ) ;
if ( ! V_194 -> V_7 ) {
V_194 -> V_7 = & V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
}
F_186 ( V_194 -> V_7 , F_147 ( V_9 ) . V_89 , F_147 ( V_9 ) . V_186 , F_147 ( V_9 ) . V_188 ) ;
F_4 ( V_194 -> V_7 , V_9 ) ;
if ( ! ( V_146 & V_227 ) ) {
if ( F_147 ( V_9 ) . V_178 )
F_146 ( V_194 -> V_7 , V_9 ) ;
F_187 ( V_15 , V_9 -> V_25 ) ;
} else {
F_188 ( V_15 , V_212 ) ;
if ( F_147 ( V_9 ) . V_178 )
V_194 -> V_7 -> V_178 = F_155 ( F_147 ( V_9 ) . V_178 ) ;
}
V_88 = ( V_146 & V_226 ) ? V_9 -> V_25 - V_225 : V_212 ;
F_189 ( V_14 , V_192 , V_194 -> V_7 , V_146 ) ;
V_208:
F_141 ( V_15 , V_9 ) ;
V_93:
F_77 ( & V_36 -> V_95 ) ;
V_92:
return V_88 ;
}
static long F_190 ( struct V_14 * V_15 , long V_153 ,
struct V_8 * V_228 )
{
F_121 ( V_49 ) ;
F_12 ( V_15 ) ;
for (; ; ) {
F_191 ( F_192 ( V_15 ) , & V_49 , V_155 ) ;
if ( F_193 ( & V_15 -> V_17 ) != V_228 ||
V_15 -> V_58 ||
( V_15 -> V_69 & V_156 ) ||
F_129 ( V_84 ) ||
! V_153 )
break;
F_138 ( V_229 , & V_15 -> V_61 -> V_146 ) ;
F_14 ( V_15 ) ;
V_153 = F_194 ( V_153 ) ;
F_12 ( V_15 ) ;
F_195 ( V_229 , & V_15 -> V_61 -> V_146 ) ;
}
F_124 ( F_192 ( V_15 ) , & V_49 ) ;
F_14 ( V_15 ) ;
return V_153 ;
}
static unsigned int F_196 ( const struct V_8 * V_9 )
{
return V_9 -> V_25 - F_147 ( V_9 ) . V_230 ;
}
static int F_197 ( struct V_190 * V_222 , struct V_86 * V_14 ,
struct V_191 * V_192 , T_3 V_212 ,
int V_146 )
{
struct V_193 * V_194 = F_161 ( V_222 ) ;
struct V_6 V_197 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_32 ( V_15 ) ;
struct V_23 * V_24 = V_192 -> V_195 ;
int V_231 = 0 ;
int V_232 = 0 ;
int V_233 ;
int V_88 = 0 ;
long V_153 ;
int V_225 ;
V_88 = - V_27 ;
if ( V_15 -> V_72 != V_163 )
goto V_92;
V_88 = - V_91 ;
if ( V_146 & V_200 )
goto V_92;
V_233 = F_198 ( V_15 , V_146 & V_234 , V_212 ) ;
V_153 = F_181 ( V_15 , V_146 & V_206 ) ;
if ( ! V_194 -> V_7 ) {
V_194 -> V_7 = & V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
}
V_88 = F_76 ( & V_36 -> V_95 ) ;
if ( V_88 ) {
V_88 = F_128 ( V_153 ) ;
goto V_92;
}
do {
int V_235 ;
struct V_8 * V_9 , * V_228 ;
F_12 ( V_15 ) ;
V_228 = V_9 = F_199 ( & V_15 -> V_17 ) ;
V_236:
if ( V_9 == NULL ) {
F_32 ( V_15 ) -> V_182 = 0 ;
if ( V_231 >= V_233 )
goto V_237;
V_88 = F_177 ( V_15 ) ;
if ( V_88 )
goto V_237;
if ( V_15 -> V_69 & V_156 )
goto V_237;
F_14 ( V_15 ) ;
V_88 = - V_162 ;
if ( ! V_153 )
break;
F_77 ( & V_36 -> V_95 ) ;
V_153 = F_190 ( V_15 , V_153 , V_228 ) ;
if ( F_129 ( V_84 )
|| F_76 ( & V_36 -> V_95 ) ) {
V_88 = F_128 ( V_153 ) ;
goto V_92;
}
continue;
V_237:
F_14 ( V_15 ) ;
break;
}
V_225 = F_182 ( V_15 , V_146 ) ;
while ( V_225 >= F_196 ( V_9 ) ) {
V_225 -= F_196 ( V_9 ) ;
V_228 = V_9 ;
V_9 = F_200 ( V_9 , & V_15 -> V_17 ) ;
if ( ! V_9 )
goto V_236;
}
F_14 ( V_15 ) ;
if ( V_232 ) {
if ( ( F_147 ( V_9 ) . V_89 != V_194 -> V_7 -> V_89 ) ||
! F_201 ( F_147 ( V_9 ) . V_186 , V_194 -> V_7 -> V_187 . V_186 ) ||
! F_202 ( F_147 ( V_9 ) . V_188 , V_194 -> V_7 -> V_187 . V_188 ) )
break;
} else if ( F_118 ( V_149 , & V_14 -> V_146 ) ) {
F_186 ( V_194 -> V_7 , F_147 ( V_9 ) . V_89 , F_147 ( V_9 ) . V_186 , F_147 ( V_9 ) . V_188 ) ;
V_232 = 1 ;
}
if ( V_24 ) {
F_180 ( V_192 , V_9 -> V_15 ) ;
V_24 = NULL ;
}
V_235 = F_164 (unsigned int, unix_skb_len(skb) - skip, size) ;
if ( F_184 ( V_9 , F_147 ( V_9 ) . V_230 + V_225 ,
V_192 -> V_209 , V_235 ) ) {
if ( V_231 == 0 )
V_231 = - V_238 ;
break;
}
V_231 += V_235 ;
V_212 -= V_235 ;
if ( ! ( V_146 & V_227 ) ) {
F_147 ( V_9 ) . V_230 += V_235 ;
F_187 ( V_15 , V_235 ) ;
if ( F_147 ( V_9 ) . V_178 )
F_146 ( V_194 -> V_7 , V_9 ) ;
if ( F_196 ( V_9 ) )
break;
F_203 ( V_9 , & V_15 -> V_17 ) ;
F_204 ( V_9 ) ;
if ( V_194 -> V_7 -> V_178 )
break;
} else {
if ( F_147 ( V_9 ) . V_178 )
V_194 -> V_7 -> V_178 = F_155 ( F_147 ( V_9 ) . V_178 ) ;
F_188 ( V_15 , V_235 ) ;
break;
}
} while ( V_212 );
F_77 ( & V_36 -> V_95 ) ;
F_189 ( V_14 , V_192 , V_194 -> V_7 , V_146 ) ;
V_92:
return V_231 ? : V_88 ;
}
static int F_205 ( struct V_86 * V_14 , int V_132 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_55 ;
if ( V_132 < V_239 || V_132 > V_240 )
return - V_27 ;
++ V_132 ;
F_12 ( V_15 ) ;
V_15 -> V_69 |= V_132 ;
V_55 = F_7 ( V_15 ) ;
if ( V_55 )
F_13 ( V_55 ) ;
F_14 ( V_15 ) ;
V_15 -> V_77 ( V_15 ) ;
if ( V_55 &&
( V_15 -> V_74 == V_75 || V_15 -> V_74 == V_76 ) ) {
int V_241 = 0 ;
if ( V_132 & V_156 )
V_241 |= V_216 ;
if ( V_132 & V_216 )
V_241 |= V_156 ;
F_12 ( V_55 ) ;
V_55 -> V_69 |= V_241 ;
F_14 ( V_55 ) ;
V_55 -> V_77 ( V_55 ) ;
if ( V_241 == V_70 )
F_44 ( V_55 , V_78 , V_79 ) ;
else if ( V_241 & V_156 )
F_44 ( V_55 , V_78 , V_242 ) ;
}
if ( V_55 )
F_61 ( V_55 ) ;
return 0 ;
}
long F_206 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
long V_243 = 0 ;
if ( V_15 -> V_72 == V_80 )
return - V_27 ;
F_27 ( & V_15 -> V_17 . V_101 ) ;
if ( V_15 -> V_74 == V_75 ||
V_15 -> V_74 == V_76 ) {
F_207 (&sk->sk_receive_queue, skb)
V_243 += F_196 ( V_9 ) ;
} else {
V_9 = F_199 ( & V_15 -> V_17 ) ;
if ( V_9 )
V_243 = V_9 -> V_25 ;
}
F_28 ( & V_15 -> V_17 . V_101 ) ;
return V_243 ;
}
long F_208 ( struct V_14 * V_15 )
{
return F_209 ( V_15 ) ;
}
static int F_210 ( struct V_86 * V_14 , unsigned int V_244 , unsigned long V_245 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
long V_243 = 0 ;
int V_88 ;
switch ( V_244 ) {
case V_246 :
V_243 = F_208 ( V_15 ) ;
V_88 = F_211 ( V_243 , ( int V_247 * ) V_245 ) ;
break;
case V_248 :
V_243 = F_206 ( V_15 ) ;
if ( V_243 < 0 )
V_88 = V_243 ;
else
V_88 = F_211 ( V_243 , ( int V_247 * ) V_245 ) ;
break;
default:
V_88 = - V_249 ;
break;
}
return V_88 ;
}
static unsigned int F_212 ( struct V_250 * V_250 , struct V_86 * V_14 , T_4 * V_49 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
unsigned int V_251 ;
F_213 ( V_250 , F_192 ( V_15 ) , V_49 ) ;
V_251 = 0 ;
if ( V_15 -> V_58 )
V_251 |= V_252 ;
if ( V_15 -> V_69 == V_70 )
V_251 |= V_253 ;
if ( V_15 -> V_69 & V_156 )
V_251 |= V_254 | V_255 | V_256 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_251 |= V_255 | V_256 ;
if ( ( V_15 -> V_74 == V_75 || V_15 -> V_74 == V_76 ) &&
V_15 -> V_72 == V_73 )
V_251 |= V_253 ;
if ( F_37 ( V_15 ) )
V_251 |= V_50 | V_51 | V_52 ;
return V_251 ;
}
static unsigned int F_214 ( struct V_250 * V_250 , struct V_86 * V_14 ,
T_4 * V_49 )
{
struct V_14 * V_15 = V_14 -> V_15 , * V_55 ;
unsigned int V_251 , V_257 ;
F_213 ( V_250 , F_192 ( V_15 ) , V_49 ) ;
V_251 = 0 ;
if ( V_15 -> V_58 || ! F_47 ( & V_15 -> V_258 ) )
V_251 |= V_252 |
( F_50 ( V_15 , V_259 ) ? V_260 : 0 ) ;
if ( V_15 -> V_69 & V_156 )
V_251 |= V_254 | V_255 | V_256 ;
if ( V_15 -> V_69 == V_70 )
V_251 |= V_253 ;
if ( ! F_47 ( & V_15 -> V_17 ) )
V_251 |= V_255 | V_256 ;
if ( V_15 -> V_74 == V_76 ) {
if ( V_15 -> V_72 == V_73 )
V_251 |= V_253 ;
if ( V_15 -> V_72 == V_261 )
return V_251 ;
}
if ( ! ( F_215 ( V_49 ) & ( V_52 | V_51 | V_50 ) ) )
return V_251 ;
V_257 = F_37 ( V_15 ) ;
V_55 = F_11 ( V_15 ) ;
if ( V_55 ) {
if ( F_7 ( V_55 ) != V_15 ) {
F_213 ( V_250 , & F_32 ( V_55 ) -> V_56 , V_49 ) ;
if ( F_9 ( V_55 ) )
V_257 = 0 ;
}
F_61 ( V_55 ) ;
}
if ( V_257 )
V_251 |= V_50 | V_51 | V_52 ;
else
F_138 ( V_262 , & V_15 -> V_61 -> V_146 ) ;
return V_251 ;
}
static struct V_14 * F_216 ( struct V_263 * V_264 , T_5 * V_265 )
{
unsigned long V_266 = F_217 ( * V_265 ) ;
unsigned long V_267 = F_218 ( * V_265 ) ;
struct V_14 * V_15 ;
unsigned long V_179 = 0 ;
for ( V_15 = F_219 ( & V_5 [ V_267 ] ) ; V_15 ; V_15 = F_220 ( V_15 ) ) {
if ( F_34 ( V_15 ) != F_221 ( V_264 ) )
continue;
if ( ++ V_179 == V_266 )
break;
}
return V_15 ;
}
static struct V_14 * F_222 ( struct V_263 * V_264 ,
struct V_14 * V_15 ,
T_5 * V_265 )
{
unsigned long V_267 ;
while ( V_15 > (struct V_14 * ) V_268 ) {
V_15 = F_220 ( V_15 ) ;
if ( ! V_15 )
goto V_269;
if ( F_34 ( V_15 ) == F_221 ( V_264 ) )
return V_15 ;
}
do {
V_15 = F_216 ( V_264 , V_265 ) ;
if ( V_15 )
return V_15 ;
V_269:
V_267 = F_218 ( * V_265 ) + 1 ;
* V_265 = F_223 ( V_267 , 1 ) ;
} while ( V_267 < F_224 ( V_5 ) );
return NULL ;
}
static void * F_225 ( struct V_263 * V_264 , T_5 * V_265 )
__acquires( V_32 )
{
F_27 ( & V_32 ) ;
if ( ! * V_265 )
return V_268 ;
if ( F_218 ( * V_265 ) >= F_224 ( V_5 ) )
return NULL ;
return F_222 ( V_264 , NULL , V_265 ) ;
}
static void * F_226 ( struct V_263 * V_264 , void * V_270 , T_5 * V_265 )
{
++ * V_265 ;
return F_222 ( V_264 , V_270 , V_265 ) ;
}
static void F_227 ( struct V_263 * V_264 , void * V_270 )
__releases( V_32 )
{
F_28 ( & V_32 ) ;
}
static int F_228 ( struct V_263 * V_264 , void * V_270 )
{
if ( V_270 == V_268 )
F_229 ( V_264 , L_4
L_5 ) ;
else {
struct V_14 * V_19 = V_270 ;
struct V_35 * V_36 = F_32 ( V_19 ) ;
F_12 ( V_19 ) ;
F_230 ( V_264 , L_6 ,
V_19 ,
F_38 ( & V_19 -> V_271 ) ,
0 ,
V_19 -> V_72 == V_80 ? V_272 : 0 ,
V_19 -> V_74 ,
V_19 -> V_61 ?
( V_19 -> V_72 == V_163 ? V_166 : V_112 ) :
( V_19 -> V_72 == V_163 ? V_273 : V_274 ) ,
F_231 ( V_19 ) ) ;
if ( V_36 -> V_2 ) {
int V_40 , V_25 ;
F_232 ( V_264 , ' ' ) ;
V_40 = 0 ;
V_25 = V_36 -> V_2 -> V_25 - sizeof( short ) ;
if ( ! F_233 ( V_19 ) )
V_25 -- ;
else {
F_232 ( V_264 , '@' ) ;
V_40 ++ ;
}
for ( ; V_40 < V_25 ; V_40 ++ )
F_232 ( V_264 , V_36 -> V_2 -> V_37 -> V_30 [ V_40 ] ) ;
}
F_14 ( V_19 ) ;
F_232 ( V_264 , '\n' ) ;
}
return 0 ;
}
static int F_234 ( struct V_39 * V_39 , struct V_250 * V_250 )
{
return F_235 ( V_39 , V_250 , & V_275 ,
sizeof( struct V_276 ) ) ;
}
static int T_6 F_236 ( struct V_33 * V_33 )
{
int error = - V_120 ;
V_33 -> V_104 . V_105 = 10 ;
if ( F_237 ( V_33 ) )
goto V_92;
#ifdef F_238
if ( ! F_239 ( L_7 , 0 , V_33 -> V_277 , & V_278 ) ) {
F_240 ( V_33 ) ;
goto V_92;
}
#endif
error = 0 ;
V_92:
return error ;
}
static void T_7 F_241 ( struct V_33 * V_33 )
{
F_240 ( V_33 ) ;
F_242 ( L_7 , V_33 -> V_277 ) ;
}
static int T_8 F_243 ( void )
{
int V_279 = - 1 ;
F_244 ( sizeof( struct V_280 ) > F_245 ( struct V_8 , V_281 ) ) ;
V_279 = F_246 ( & V_100 , 1 ) ;
if ( V_279 != 0 ) {
F_52 ( V_282 L_8 ,
V_283 ) ;
goto V_92;
}
F_247 ( & V_284 ) ;
F_248 ( & V_285 ) ;
V_92:
return V_279 ;
}
static void T_9 F_249 ( void )
{
F_250 ( V_98 ) ;
F_251 ( & V_100 ) ;
F_252 ( & V_285 ) ;
}
