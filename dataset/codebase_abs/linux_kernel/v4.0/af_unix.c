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
unsigned int V_3 = ( V_13 unsigned int ) F_6 ( V_12 ) ;
V_3 ^= V_3 >> 8 ;
return V_3 & ( V_4 - 1 ) ;
}
static inline int F_7 ( struct V_14 * V_15 , struct V_14 * V_16 )
{
return F_8 ( V_16 ) == V_15 ;
}
static inline int F_9 ( struct V_14 * V_15 , struct V_14 * V_16 )
{
return F_8 ( V_16 ) == NULL || F_7 ( V_15 , V_16 ) ;
}
static inline int F_10 ( struct V_14 const * V_15 )
{
return F_11 ( & V_15 -> V_17 ) > V_15 -> V_18 ;
}
struct V_14 * F_12 ( struct V_14 * V_19 )
{
struct V_14 * V_20 ;
F_13 ( V_19 ) ;
V_20 = F_8 ( V_19 ) ;
if ( V_20 )
F_14 ( V_20 ) ;
F_15 ( V_19 ) ;
return V_20 ;
}
static inline void F_16 ( struct V_21 * V_2 )
{
if ( F_17 ( & V_2 -> V_22 ) )
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_23 * V_24 , int V_25 , unsigned int * V_26 )
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
* V_26 = F_5 ( F_20 ( V_24 , V_25 , 0 ) ) ;
return V_25 ;
}
static void F_21 ( struct V_14 * V_15 )
{
F_22 ( V_15 ) ;
}
static void F_23 ( struct V_1 * V_31 , struct V_14 * V_15 )
{
F_24 ( ! F_25 ( V_15 ) ) ;
F_26 ( V_15 , V_31 ) ;
}
static inline void F_27 ( struct V_14 * V_15 )
{
F_28 ( & V_32 ) ;
F_21 ( V_15 ) ;
F_29 ( & V_32 ) ;
}
static inline void F_30 ( struct V_1 * V_31 , struct V_14 * V_15 )
{
F_28 ( & V_32 ) ;
F_23 ( V_31 , V_15 ) ;
F_29 ( & V_32 ) ;
}
static struct V_14 * F_31 ( struct V_33 * V_33 ,
struct V_23 * V_34 ,
int V_25 , int type , unsigned int V_3 )
{
struct V_14 * V_19 ;
F_32 (s, &unix_socket_table[hash ^ type]) {
struct V_35 * V_36 = F_33 ( V_19 ) ;
if ( ! F_34 ( F_35 ( V_19 ) , V_33 ) )
continue;
if ( V_36 -> V_2 -> V_25 == V_25 &&
! memcmp ( V_36 -> V_2 -> V_37 , V_34 , V_25 ) )
goto V_38;
}
V_19 = NULL ;
V_38:
return V_19 ;
}
static inline struct V_14 * F_36 ( struct V_33 * V_33 ,
struct V_23 * V_34 ,
int V_25 , int type ,
unsigned int V_3 )
{
struct V_14 * V_19 ;
F_28 ( & V_32 ) ;
V_19 = F_31 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_19 )
F_14 ( V_19 ) ;
F_29 ( & V_32 ) ;
return V_19 ;
}
static struct V_14 * F_37 ( struct V_39 * V_40 )
{
struct V_14 * V_19 ;
F_28 ( & V_32 ) ;
F_32 (s,
&unix_socket_table[i->i_ino & (UNIX_HASH_SIZE - 1)]) {
struct V_41 * V_41 = F_33 ( V_19 ) -> V_42 . V_41 ;
if ( V_41 && V_41 -> V_43 == V_40 ) {
F_14 ( V_19 ) ;
goto V_38;
}
}
V_19 = NULL ;
V_38:
F_29 ( & V_32 ) ;
return V_19 ;
}
static inline int F_38 ( struct V_14 * V_15 )
{
return ( F_39 ( & V_15 -> V_44 ) << 2 ) <= V_15 -> V_45 ;
}
static void F_40 ( struct V_14 * V_15 )
{
struct V_46 * V_47 ;
F_41 () ;
if ( F_38 ( V_15 ) ) {
V_47 = F_42 ( V_15 -> V_48 ) ;
if ( F_43 ( V_47 ) )
F_44 ( & V_47 -> V_49 ,
V_50 | V_51 | V_52 ) ;
F_45 ( V_15 , V_53 , V_54 ) ;
}
F_46 () ;
}
static void F_47 ( struct V_14 * V_15 , struct V_14 * V_55 )
{
if ( ! F_48 ( & V_15 -> V_17 ) ) {
F_49 ( & V_15 -> V_17 ) ;
F_50 ( & F_33 ( V_15 ) -> V_56 ) ;
if ( ! F_51 ( V_55 , V_57 ) && F_8 ( V_55 ) == V_15 ) {
V_55 -> V_58 = V_59 ;
V_55 -> V_60 ( V_55 ) ;
}
}
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
F_49 ( & V_15 -> V_17 ) ;
F_24 ( F_39 ( & V_15 -> V_44 ) ) ;
F_24 ( ! F_25 ( V_15 ) ) ;
F_24 ( V_15 -> V_61 ) ;
if ( ! F_51 ( V_15 , V_57 ) ) {
F_53 ( L_1 , V_15 ) ;
return;
}
if ( V_36 -> V_2 )
F_16 ( V_36 -> V_2 ) ;
F_54 ( & V_62 ) ;
F_55 () ;
F_56 ( F_35 ( V_15 ) , V_15 -> V_63 , - 1 ) ;
F_57 () ;
#ifdef F_58
F_59 ( L_2 , V_15 ,
F_60 ( & V_62 ) ) ;
#endif
}
static void F_61 ( struct V_14 * V_15 , int V_64 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
struct V_42 V_42 ;
struct V_14 * V_65 ;
struct V_8 * V_9 ;
int V_66 ;
F_27 ( V_15 ) ;
F_13 ( V_15 ) ;
F_62 ( V_15 ) ;
V_15 -> V_67 = V_68 ;
V_42 = V_36 -> V_42 ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_69 = NULL ;
V_66 = V_15 -> V_70 ;
V_15 -> V_70 = V_71 ;
F_15 ( V_15 ) ;
F_50 ( & V_36 -> V_56 ) ;
V_65 = F_8 ( V_15 ) ;
if ( V_65 != NULL ) {
if ( V_15 -> V_72 == V_73 || V_15 -> V_72 == V_74 ) {
F_13 ( V_65 ) ;
V_65 -> V_67 = V_68 ;
if ( ! F_48 ( & V_15 -> V_17 ) || V_64 )
V_65 -> V_58 = V_59 ;
F_15 ( V_65 ) ;
V_65 -> V_75 ( V_65 ) ;
F_45 ( V_65 , V_76 , V_77 ) ;
}
F_63 ( V_65 ) ;
F_8 ( V_15 ) = NULL ;
}
while ( ( V_9 = F_64 ( & V_15 -> V_17 ) ) != NULL ) {
if ( V_66 == V_78 )
F_61 ( V_9 -> V_15 , 1 ) ;
F_65 ( V_9 ) ;
}
if ( V_42 . V_41 )
F_66 ( & V_42 ) ;
F_63 ( V_15 ) ;
if ( V_79 )
F_67 () ;
}
static void F_68 ( struct V_14 * V_15 )
{
F_69 ( V_15 -> V_80 ) ;
if ( V_15 -> V_81 )
F_70 ( V_15 -> V_81 ) ;
V_15 -> V_80 = F_71 ( F_72 ( V_82 ) ) ;
V_15 -> V_81 = F_73 () ;
}
static void F_74 ( struct V_14 * V_15 , struct V_14 * V_83 )
{
F_69 ( V_15 -> V_80 ) ;
if ( V_15 -> V_81 )
F_70 ( V_15 -> V_81 ) ;
V_15 -> V_80 = F_71 ( V_83 -> V_80 ) ;
V_15 -> V_81 = F_75 ( V_83 -> V_81 ) ;
}
static int F_76 ( struct V_84 * V_14 , int V_85 )
{
int V_86 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
struct V_87 * V_88 = NULL ;
V_86 = - V_89 ;
if ( V_14 -> type != V_73 && V_14 -> type != V_74 )
goto V_90;
V_86 = - V_27 ;
if ( ! V_36 -> V_2 )
goto V_90;
F_13 ( V_15 ) ;
if ( V_15 -> V_70 != V_71 && V_15 -> V_70 != V_78 )
goto V_91;
if ( V_85 > V_15 -> V_18 )
F_50 ( & V_36 -> V_56 ) ;
V_15 -> V_18 = V_85 ;
V_15 -> V_70 = V_78 ;
F_68 ( V_15 ) ;
V_86 = 0 ;
V_91:
F_15 ( V_15 ) ;
F_69 ( V_88 ) ;
V_90:
return V_86 ;
}
static int F_77 ( struct V_14 * V_15 , int V_92 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
if ( F_78 ( & V_36 -> V_93 ) )
return - V_94 ;
V_15 -> V_95 = V_92 ;
F_79 ( & V_36 -> V_93 ) ;
return 0 ;
}
static struct V_14 * F_80 ( struct V_33 * V_33 , struct V_84 * V_14 )
{
struct V_14 * V_15 = NULL ;
struct V_35 * V_36 ;
F_81 ( & V_62 ) ;
if ( F_60 ( & V_62 ) > 2 * F_82 () )
goto V_90;
V_15 = F_83 ( V_33 , V_96 , V_97 , & V_98 ) ;
if ( ! V_15 )
goto V_90;
F_84 ( V_14 , V_15 ) ;
F_85 ( & V_15 -> V_17 . V_99 ,
& V_100 ) ;
V_15 -> V_101 = F_40 ;
V_15 -> V_18 = V_33 -> V_102 . V_103 ;
V_15 -> V_104 = F_52 ;
V_36 = F_33 ( V_15 ) ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_69 = NULL ;
F_86 ( & V_36 -> V_99 ) ;
F_87 ( & V_36 -> V_105 , 0 ) ;
F_88 ( & V_36 -> V_106 ) ;
F_89 ( & V_36 -> V_93 ) ;
F_90 ( & V_36 -> V_56 ) ;
F_30 ( F_1 ( V_15 ) , V_15 ) ;
V_90:
if ( V_15 == NULL )
F_54 ( & V_62 ) ;
else {
F_55 () ;
F_56 ( F_35 ( V_15 ) , V_15 -> V_63 , 1 ) ;
F_57 () ;
}
return V_15 ;
}
static int F_91 ( struct V_33 * V_33 , struct V_84 * V_14 , int V_107 ,
int V_108 )
{
if ( V_107 && V_107 != V_96 )
return - V_109 ;
V_14 -> V_66 = V_110 ;
switch ( V_14 -> type ) {
case V_73 :
V_14 -> V_111 = & V_112 ;
break;
case V_113 :
V_14 -> type = V_114 ;
case V_114 :
V_14 -> V_111 = & V_115 ;
break;
case V_74 :
V_14 -> V_111 = & V_116 ;
break;
default:
return - V_117 ;
}
return F_80 ( V_33 , V_14 ) ? 0 : - V_118 ;
}
static int F_92 ( struct V_84 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( ! V_15 )
return 0 ;
F_61 ( V_15 , 0 ) ;
V_14 -> V_15 = NULL ;
return 0 ;
}
static int F_93 ( struct V_84 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
static V_11 V_119 = 1 ;
struct V_21 * V_2 ;
int V_86 ;
unsigned int V_120 = 0 ;
V_86 = F_78 ( & V_36 -> V_93 ) ;
if ( V_86 )
return V_86 ;
V_86 = 0 ;
if ( V_36 -> V_2 )
goto V_90;
V_86 = - V_118 ;
V_2 = F_94 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_97 ) ;
if ( ! V_2 )
goto V_90;
V_2 -> V_37 -> V_28 = V_29 ;
F_95 ( & V_2 -> V_22 , 1 ) ;
V_121:
V_2 -> V_25 = sprintf ( V_2 -> V_37 -> V_30 + 1 , L_3 , V_119 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_5 ( F_20 ( V_2 -> V_37 , V_2 -> V_25 , 0 ) ) ;
F_28 ( & V_32 ) ;
V_119 = ( V_119 + 1 ) & 0xFFFFF ;
if ( F_31 ( V_33 , V_2 -> V_37 , V_2 -> V_25 , V_14 -> type ,
V_2 -> V_3 ) ) {
F_29 ( & V_32 ) ;
F_96 () ;
if ( V_120 ++ == 0xFFFFF ) {
V_86 = - V_122 ;
F_18 ( V_2 ) ;
goto V_90;
}
goto V_121;
}
V_2 -> V_3 ^= V_15 -> V_72 ;
F_21 ( V_15 ) ;
V_36 -> V_2 = V_2 ;
F_23 ( & V_5 [ V_2 -> V_3 ] , V_15 ) ;
F_29 ( & V_32 ) ;
V_86 = 0 ;
V_90: F_79 ( & V_36 -> V_93 ) ;
return V_86 ;
}
static struct V_14 * F_97 ( struct V_33 * V_33 ,
struct V_23 * V_34 , int V_25 ,
int type , unsigned int V_3 , int * error )
{
struct V_14 * V_36 ;
struct V_42 V_42 ;
int V_86 = 0 ;
if ( V_34 -> V_30 [ 0 ] ) {
struct V_39 * V_39 ;
V_86 = F_98 ( V_34 -> V_30 , V_123 , & V_42 ) ;
if ( V_86 )
goto V_124;
V_39 = V_42 . V_41 -> V_43 ;
V_86 = F_99 ( V_39 , V_125 ) ;
if ( V_86 )
goto V_126;
V_86 = - V_127 ;
if ( ! F_100 ( V_39 -> V_128 ) )
goto V_126;
V_36 = F_37 ( V_39 ) ;
if ( ! V_36 )
goto V_126;
if ( V_36 -> V_72 == type )
F_101 ( & V_42 ) ;
F_66 ( & V_42 ) ;
V_86 = - V_129 ;
if ( V_36 -> V_72 != type ) {
F_63 ( V_36 ) ;
goto V_124;
}
} else {
V_86 = - V_127 ;
V_36 = F_36 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_36 ) {
struct V_41 * V_41 ;
V_41 = F_33 ( V_36 ) -> V_42 . V_41 ;
if ( V_41 )
F_101 ( & F_33 ( V_36 ) -> V_42 ) ;
} else
goto V_124;
}
return V_36 ;
V_126:
F_66 ( & V_42 ) ;
V_124:
* error = V_86 ;
return NULL ;
}
static int F_102 ( const char * V_30 , T_2 V_130 , struct V_42 * V_131 )
{
struct V_41 * V_41 ;
struct V_42 V_42 ;
int V_86 = 0 ;
V_41 = F_103 ( V_132 , V_30 , & V_42 , 0 ) ;
V_86 = F_104 ( V_41 ) ;
if ( F_105 ( V_41 ) )
return V_86 ;
V_86 = F_106 ( & V_42 , V_41 , V_130 , 0 ) ;
if ( ! V_86 ) {
V_86 = F_107 ( V_42 . V_41 -> V_43 , V_41 , V_130 , 0 ) ;
if ( ! V_86 ) {
V_131 -> V_69 = F_108 ( V_42 . V_69 ) ;
V_131 -> V_41 = F_109 ( V_41 ) ;
}
}
F_110 ( & V_42 , V_41 ) ;
return V_86 ;
}
static int F_111 ( struct V_84 * V_14 , struct V_133 * V_134 , int V_135 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_134 ;
char * V_30 = V_24 -> V_30 ;
int V_86 ;
unsigned int V_3 ;
struct V_21 * V_2 ;
struct V_1 * V_31 ;
V_86 = - V_27 ;
if ( V_24 -> V_28 != V_29 )
goto V_90;
if ( V_135 == sizeof( short ) ) {
V_86 = F_93 ( V_14 ) ;
goto V_90;
}
V_86 = F_19 ( V_24 , V_135 , & V_3 ) ;
if ( V_86 < 0 )
goto V_90;
V_135 = V_86 ;
V_86 = F_78 ( & V_36 -> V_93 ) ;
if ( V_86 )
goto V_90;
V_86 = - V_27 ;
if ( V_36 -> V_2 )
goto V_136;
V_86 = - V_118 ;
V_2 = F_112 ( sizeof( * V_2 ) + V_135 , V_97 ) ;
if ( ! V_2 )
goto V_136;
memcpy ( V_2 -> V_37 , V_24 , V_135 ) ;
V_2 -> V_25 = V_135 ;
V_2 -> V_3 = V_3 ^ V_15 -> V_72 ;
F_95 ( & V_2 -> V_22 , 1 ) ;
if ( V_30 [ 0 ] ) {
struct V_42 V_42 ;
T_2 V_130 = V_137 |
( F_113 ( V_14 ) -> V_128 & ~ F_114 () ) ;
V_86 = F_102 ( V_30 , V_130 , & V_42 ) ;
if ( V_86 ) {
if ( V_86 == - V_138 )
V_86 = - V_139 ;
F_16 ( V_2 ) ;
goto V_136;
}
V_2 -> V_3 = V_4 ;
V_3 = V_42 . V_41 -> V_43 -> V_140 & ( V_4 - 1 ) ;
F_28 ( & V_32 ) ;
V_36 -> V_42 = V_42 ;
V_31 = & V_5 [ V_3 ] ;
} else {
F_28 ( & V_32 ) ;
V_86 = - V_139 ;
if ( F_31 ( V_33 , V_24 , V_135 ,
V_15 -> V_72 , V_3 ) ) {
F_16 ( V_2 ) ;
goto V_91;
}
V_31 = & V_5 [ V_2 -> V_3 ] ;
}
V_86 = 0 ;
F_21 ( V_15 ) ;
V_36 -> V_2 = V_2 ;
F_23 ( V_31 , V_15 ) ;
V_91:
F_29 ( & V_32 ) ;
V_136:
F_79 ( & V_36 -> V_93 ) ;
V_90:
return V_86 ;
}
static void F_115 ( struct V_14 * V_141 , struct V_14 * V_142 )
{
if ( F_116 ( V_141 == V_142 ) || ! V_142 ) {
F_13 ( V_141 ) ;
return;
}
if ( V_141 < V_142 ) {
F_13 ( V_141 ) ;
F_117 ( V_142 ) ;
} else {
F_13 ( V_142 ) ;
F_117 ( V_141 ) ;
}
}
static void F_118 ( struct V_14 * V_141 , struct V_14 * V_142 )
{
if ( F_116 ( V_141 == V_142 ) || ! V_142 ) {
F_15 ( V_141 ) ;
return;
}
F_15 ( V_141 ) ;
F_15 ( V_142 ) ;
}
static int F_119 ( struct V_84 * V_14 , struct V_133 * V_2 ,
int V_143 , int V_144 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_2 ;
struct V_14 * V_55 ;
unsigned int V_3 ;
int V_86 ;
if ( V_2 -> V_145 != V_146 ) {
V_86 = F_19 ( V_24 , V_143 , & V_3 ) ;
if ( V_86 < 0 )
goto V_90;
V_143 = V_86 ;
if ( F_120 ( V_147 , & V_14 -> V_144 ) &&
! F_33 ( V_15 ) -> V_2 && ( V_86 = F_93 ( V_14 ) ) != 0 )
goto V_90;
V_148:
V_55 = F_97 ( V_33 , V_24 , V_143 , V_14 -> type , V_3 , & V_86 ) ;
if ( ! V_55 )
goto V_90;
F_115 ( V_15 , V_55 ) ;
if ( F_51 ( V_55 , V_57 ) ) {
F_118 ( V_15 , V_55 ) ;
F_63 ( V_55 ) ;
goto V_148;
}
V_86 = - V_149 ;
if ( ! F_9 ( V_15 , V_55 ) )
goto V_91;
V_86 = F_121 ( V_15 -> V_61 , V_55 -> V_61 ) ;
if ( V_86 )
goto V_91;
} else {
V_55 = NULL ;
F_115 ( V_15 , V_55 ) ;
}
if ( F_8 ( V_15 ) ) {
struct V_14 * V_150 = F_8 ( V_15 ) ;
F_8 ( V_15 ) = V_55 ;
F_118 ( V_15 , V_55 ) ;
if ( V_55 != V_150 )
F_47 ( V_15 , V_150 ) ;
F_63 ( V_150 ) ;
} else {
F_8 ( V_15 ) = V_55 ;
F_118 ( V_15 , V_55 ) ;
}
return 0 ;
V_91:
F_118 ( V_15 , V_55 ) ;
F_63 ( V_55 ) ;
V_90:
return V_86 ;
}
static long F_122 ( struct V_14 * V_55 , long V_151 )
{
struct V_35 * V_36 = F_33 ( V_55 ) ;
int V_152 ;
F_123 ( V_49 ) ;
F_124 ( & V_36 -> V_56 , & V_49 , V_153 ) ;
V_152 = ! F_51 ( V_55 , V_57 ) &&
! ( V_55 -> V_67 & V_154 ) &&
F_10 ( V_55 ) ;
F_15 ( V_55 ) ;
if ( V_152 )
V_151 = F_125 ( V_151 ) ;
F_126 ( & V_36 -> V_56 , & V_49 ) ;
return V_151 ;
}
static int F_127 ( struct V_84 * V_14 , struct V_133 * V_134 ,
int V_135 , int V_144 )
{
struct V_23 * V_24 = (struct V_23 * ) V_134 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) , * V_155 , * V_156 ;
struct V_14 * V_157 = NULL ;
struct V_14 * V_55 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_158 ;
int V_86 ;
long V_151 ;
V_86 = F_19 ( V_24 , V_135 , & V_3 ) ;
if ( V_86 < 0 )
goto V_90;
V_135 = V_86 ;
if ( F_120 ( V_147 , & V_14 -> V_144 ) && ! V_36 -> V_2 &&
( V_86 = F_93 ( V_14 ) ) != 0 )
goto V_90;
V_151 = F_128 ( V_15 , V_144 & V_159 ) ;
V_86 = - V_118 ;
V_157 = F_80 ( F_35 ( V_15 ) , NULL ) ;
if ( V_157 == NULL )
goto V_90;
V_9 = F_129 ( V_157 , 1 , 0 , V_97 ) ;
if ( V_9 == NULL )
goto V_90;
V_148:
V_55 = F_97 ( V_33 , V_24 , V_135 , V_15 -> V_72 , V_3 , & V_86 ) ;
if ( ! V_55 )
goto V_90;
F_13 ( V_55 ) ;
if ( F_51 ( V_55 , V_57 ) ) {
F_15 ( V_55 ) ;
F_63 ( V_55 ) ;
goto V_148;
}
V_86 = - V_127 ;
if ( V_55 -> V_70 != V_78 )
goto V_91;
if ( V_55 -> V_67 & V_154 )
goto V_91;
if ( F_10 ( V_55 ) ) {
V_86 = - V_160 ;
if ( ! V_151 )
goto V_91;
V_151 = F_122 ( V_55 , V_151 ) ;
V_86 = F_130 ( V_151 ) ;
if ( F_131 ( V_82 ) )
goto V_90;
F_63 ( V_55 ) ;
goto V_148;
}
V_158 = V_15 -> V_70 ;
switch ( V_158 ) {
case V_71 :
break;
case V_161 :
V_86 = - V_162 ;
goto V_91;
default:
V_86 = - V_27 ;
goto V_91;
}
F_117 ( V_15 ) ;
if ( V_15 -> V_70 != V_158 ) {
F_15 ( V_15 ) ;
F_15 ( V_55 ) ;
F_63 ( V_55 ) ;
goto V_148;
}
V_86 = F_132 ( V_15 , V_55 , V_157 ) ;
if ( V_86 ) {
F_15 ( V_15 ) ;
goto V_91;
}
F_14 ( V_15 ) ;
F_8 ( V_157 ) = V_15 ;
V_157 -> V_70 = V_161 ;
V_157 -> V_72 = V_15 -> V_72 ;
F_68 ( V_157 ) ;
V_155 = F_33 ( V_157 ) ;
F_133 ( V_157 -> V_48 , & V_155 -> V_163 ) ;
V_156 = F_33 ( V_55 ) ;
if ( V_156 -> V_2 ) {
F_134 ( & V_156 -> V_2 -> V_22 ) ;
V_155 -> V_2 = V_156 -> V_2 ;
}
if ( V_156 -> V_42 . V_41 ) {
F_135 ( & V_156 -> V_42 ) ;
V_155 -> V_42 = V_156 -> V_42 ;
}
F_74 ( V_15 , V_55 ) ;
V_14 -> V_66 = V_164 ;
V_15 -> V_70 = V_161 ;
F_14 ( V_157 ) ;
F_136 () ;
F_8 ( V_15 ) = V_157 ;
F_15 ( V_15 ) ;
F_28 ( & V_55 -> V_17 . V_99 ) ;
F_137 ( & V_55 -> V_17 , V_9 ) ;
F_29 ( & V_55 -> V_17 . V_99 ) ;
F_15 ( V_55 ) ;
V_55 -> V_165 ( V_55 ) ;
F_63 ( V_55 ) ;
return 0 ;
V_91:
if ( V_55 )
F_15 ( V_55 ) ;
V_90:
F_65 ( V_9 ) ;
if ( V_157 )
F_61 ( V_157 , 0 ) ;
if ( V_55 )
F_63 ( V_55 ) ;
return V_86 ;
}
static int F_138 ( struct V_84 * V_166 , struct V_84 * V_167 )
{
struct V_14 * V_168 = V_166 -> V_15 , * V_9 = V_167 -> V_15 ;
F_14 ( V_168 ) ;
F_14 ( V_9 ) ;
F_8 ( V_168 ) = V_9 ;
F_8 ( V_9 ) = V_168 ;
F_68 ( V_168 ) ;
F_68 ( V_9 ) ;
if ( V_168 -> V_72 != V_114 ) {
V_168 -> V_70 = V_161 ;
V_9 -> V_70 = V_161 ;
V_166 -> V_66 = V_164 ;
V_167 -> V_66 = V_164 ;
}
return 0 ;
}
static void F_139 ( const struct V_84 * V_169 ,
struct V_84 * V_170 )
{
if ( F_120 ( V_147 , & V_169 -> V_144 ) )
F_140 ( V_147 , & V_170 -> V_144 ) ;
if ( F_120 ( V_171 , & V_169 -> V_144 ) )
F_140 ( V_171 , & V_170 -> V_144 ) ;
}
static int F_141 ( struct V_84 * V_14 , struct V_84 * V_172 , int V_144 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_173 ;
struct V_8 * V_9 ;
int V_86 ;
V_86 = - V_89 ;
if ( V_14 -> type != V_73 && V_14 -> type != V_74 )
goto V_90;
V_86 = - V_27 ;
if ( V_15 -> V_70 != V_78 )
goto V_90;
V_9 = F_142 ( V_15 , 0 , V_144 & V_159 , & V_86 ) ;
if ( ! V_9 ) {
if ( V_86 == 0 )
V_86 = - V_27 ;
goto V_90;
}
V_173 = V_9 -> V_15 ;
F_143 ( V_15 , V_9 ) ;
F_144 ( & F_33 ( V_15 ) -> V_56 ) ;
F_13 ( V_173 ) ;
V_172 -> V_66 = V_164 ;
F_139 ( V_14 , V_172 ) ;
F_145 ( V_173 , V_172 ) ;
F_15 ( V_173 ) ;
return 0 ;
V_90:
return V_86 ;
}
static int F_146 ( struct V_84 * V_14 , struct V_133 * V_134 , int * V_174 , int V_20 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 ;
F_147 ( struct V_23 * , V_24 , V_134 ) ;
int V_86 = 0 ;
if ( V_20 ) {
V_15 = F_12 ( V_15 ) ;
V_86 = - V_175 ;
if ( ! V_15 )
goto V_90;
V_86 = 0 ;
} else {
F_14 ( V_15 ) ;
}
V_36 = F_33 ( V_15 ) ;
F_13 ( V_15 ) ;
if ( ! V_36 -> V_2 ) {
V_24 -> V_28 = V_29 ;
V_24 -> V_30 [ 0 ] = 0 ;
* V_174 = sizeof( short ) ;
} else {
struct V_21 * V_2 = V_36 -> V_2 ;
* V_174 = V_2 -> V_25 ;
memcpy ( V_24 , V_2 -> V_37 , * V_174 ) ;
}
F_15 ( V_15 ) ;
F_63 ( V_15 ) ;
V_90:
return V_86 ;
}
static void F_148 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
V_7 -> V_176 = F_149 ( V_9 ) . V_176 ;
F_149 ( V_9 ) . V_176 = NULL ;
for ( V_40 = V_7 -> V_176 -> V_177 - 1 ; V_40 >= 0 ; V_40 -- )
F_150 ( V_7 -> V_176 -> V_176 [ V_40 ] ) ;
}
static void F_151 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_87 = F_149 ( V_9 ) . V_87 ;
if ( F_149 ( V_9 ) . V_176 )
F_148 ( & V_7 , V_9 ) ;
F_152 ( & V_7 ) ;
F_153 ( V_9 ) ;
}
static int F_154 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
unsigned char V_178 = 0 ;
int V_179 = 0 ;
for ( V_40 = V_7 -> V_176 -> V_177 - 1 ; V_40 >= 0 ; V_40 -- ) {
struct V_14 * V_15 = F_155 ( V_7 -> V_176 -> V_176 [ V_40 ] ) ;
if ( V_15 ) {
V_179 ++ ;
V_178 = F_156 ( V_178 ,
F_33 ( V_15 ) -> V_180 ) ;
}
}
if ( F_116 ( V_178 > V_181 ) )
return - V_182 ;
F_149 ( V_9 ) . V_176 = F_157 ( V_7 -> V_176 ) ;
if ( ! F_149 ( V_9 ) . V_176 )
return - V_118 ;
if ( V_179 ) {
for ( V_40 = V_7 -> V_176 -> V_177 - 1 ; V_40 >= 0 ; V_40 -- )
F_158 ( V_7 -> V_176 -> V_176 [ V_40 ] ) ;
}
return V_178 ;
}
static int F_159 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_183 )
{
int V_86 = 0 ;
F_149 ( V_9 ) . V_87 = F_71 ( V_7 -> V_87 ) ;
F_149 ( V_9 ) . V_184 = V_7 -> V_185 . V_184 ;
F_149 ( V_9 ) . V_186 = V_7 -> V_185 . V_186 ;
F_149 ( V_9 ) . V_176 = NULL ;
if ( V_7 -> V_176 && V_183 )
V_86 = F_154 ( V_7 , V_9 ) ;
V_9 -> V_187 = F_151 ;
return V_86 ;
}
static void F_160 ( struct V_8 * V_9 , const struct V_84 * V_14 ,
const struct V_14 * V_55 )
{
if ( F_149 ( V_9 ) . V_87 )
return;
if ( F_120 ( V_147 , & V_14 -> V_144 ) ||
! V_55 -> V_61 ||
F_120 ( V_147 , & V_55 -> V_61 -> V_144 ) ) {
F_149 ( V_9 ) . V_87 = F_71 ( F_72 ( V_82 ) ) ;
F_161 ( & F_149 ( V_9 ) . V_184 , & F_149 ( V_9 ) . V_186 ) ;
}
}
static int F_162 ( struct V_188 * V_188 , struct V_84 * V_14 ,
struct V_189 * V_190 , T_3 V_25 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
F_147 ( struct V_23 * , V_24 , V_190 -> V_191 ) ;
struct V_14 * V_55 = NULL ;
int V_192 = 0 ;
int V_86 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_151 ;
struct V_6 V_7 ;
int V_178 ;
int V_193 = 0 ;
F_163 () ;
V_86 = F_164 ( V_14 , V_190 , & V_7 , false ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = - V_89 ;
if ( V_190 -> V_194 & V_195 )
goto V_90;
if ( V_190 -> V_196 ) {
V_86 = F_19 ( V_24 , V_190 -> V_196 , & V_3 ) ;
if ( V_86 < 0 )
goto V_90;
V_192 = V_86 ;
} else {
V_24 = NULL ;
V_86 = - V_175 ;
V_55 = F_12 ( V_15 ) ;
if ( ! V_55 )
goto V_90;
}
if ( F_120 ( V_147 , & V_14 -> V_144 ) && ! V_36 -> V_2
&& ( V_86 = F_93 ( V_14 ) ) != 0 )
goto V_90;
V_86 = - V_197 ;
if ( V_25 > V_15 -> V_45 - 32 )
goto V_90;
if ( V_25 > V_198 ) {
V_193 = F_165 ( T_3 ,
V_25 - V_198 ,
V_199 * V_200 ) ;
V_193 = F_166 ( V_193 ) ;
F_167 ( V_198 < V_200 ) ;
}
V_9 = F_168 ( V_15 , V_25 - V_193 , V_193 ,
V_190 -> V_194 & V_201 , & V_86 ,
V_202 ) ;
if ( V_9 == NULL )
goto V_90;
V_86 = F_159 ( & V_7 , V_9 , true ) ;
if ( V_86 < 0 )
goto V_203;
V_178 = V_86 + 1 ;
F_2 ( & V_7 , V_9 ) ;
F_169 ( V_9 , V_25 - V_193 ) ;
V_9 -> V_193 = V_193 ;
V_9 -> V_25 = V_25 ;
V_86 = F_170 ( V_9 , 0 , & V_190 -> V_204 , V_25 ) ;
if ( V_86 )
goto V_203;
V_151 = F_128 ( V_15 , V_190 -> V_194 & V_201 ) ;
V_148:
if ( ! V_55 ) {
V_86 = - V_59 ;
if ( V_24 == NULL )
goto V_203;
V_55 = F_97 ( V_33 , V_24 , V_192 , V_15 -> V_72 ,
V_3 , & V_86 ) ;
if ( V_55 == NULL )
goto V_203;
}
if ( F_171 ( V_55 , V_9 ) < 0 ) {
V_86 = V_25 ;
goto V_203;
}
F_13 ( V_55 ) ;
V_86 = - V_149 ;
if ( ! F_9 ( V_15 , V_55 ) )
goto V_91;
if ( F_51 ( V_55 , V_57 ) ) {
F_15 ( V_55 ) ;
F_63 ( V_55 ) ;
V_86 = 0 ;
F_13 ( V_15 ) ;
if ( F_8 ( V_15 ) == V_55 ) {
F_8 ( V_15 ) = NULL ;
F_15 ( V_15 ) ;
F_47 ( V_15 , V_55 ) ;
F_63 ( V_55 ) ;
V_86 = - V_127 ;
} else {
F_15 ( V_15 ) ;
}
V_55 = NULL ;
if ( V_86 )
goto V_203;
goto V_148;
}
V_86 = - V_205 ;
if ( V_55 -> V_67 & V_154 )
goto V_91;
if ( V_15 -> V_72 != V_74 ) {
V_86 = F_121 ( V_15 -> V_61 , V_55 -> V_61 ) ;
if ( V_86 )
goto V_91;
}
if ( F_8 ( V_55 ) != V_15 && F_10 ( V_55 ) ) {
if ( ! V_151 ) {
V_86 = - V_160 ;
goto V_91;
}
V_151 = F_122 ( V_55 , V_151 ) ;
V_86 = F_130 ( V_151 ) ;
if ( F_131 ( V_82 ) )
goto V_203;
goto V_148;
}
if ( F_51 ( V_55 , V_206 ) )
F_172 ( V_9 ) ;
F_160 ( V_9 , V_14 , V_55 ) ;
F_173 ( & V_55 -> V_17 , V_9 ) ;
if ( V_178 > F_33 ( V_55 ) -> V_180 )
F_33 ( V_55 ) -> V_180 = V_178 ;
F_15 ( V_55 ) ;
V_55 -> V_165 ( V_55 ) ;
F_63 ( V_55 ) ;
F_152 ( & V_7 ) ;
return V_25 ;
V_91:
F_15 ( V_55 ) ;
V_203:
F_65 ( V_9 ) ;
V_90:
if ( V_55 )
F_63 ( V_55 ) ;
F_152 ( & V_7 ) ;
return V_86 ;
}
static int F_174 ( struct V_188 * V_188 , struct V_84 * V_14 ,
struct V_189 * V_190 , T_3 V_25 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_55 = NULL ;
int V_86 , V_207 ;
struct V_8 * V_9 ;
int V_208 = 0 ;
struct V_6 V_7 ;
bool V_209 = false ;
int V_178 ;
int V_193 ;
F_163 () ;
V_86 = F_164 ( V_14 , V_190 , & V_7 , false ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = - V_89 ;
if ( V_190 -> V_194 & V_195 )
goto V_210;
if ( V_190 -> V_196 ) {
V_86 = V_15 -> V_70 == V_161 ? - V_162 : - V_89 ;
goto V_210;
} else {
V_86 = - V_175 ;
V_55 = F_8 ( V_15 ) ;
if ( ! V_55 )
goto V_210;
}
if ( V_15 -> V_67 & V_211 )
goto V_212;
while ( V_208 < V_25 ) {
V_207 = V_25 - V_208 ;
V_207 = F_165 ( int , V_207 , ( V_15 -> V_45 >> 1 ) - 64 ) ;
V_207 = F_165 ( int , V_207 , F_175 ( 0 ) + V_213 ) ;
V_193 = F_176 ( int , 0 , V_207 - F_175 ( 0 ) ) ;
V_193 = F_165 ( T_3 , V_207 , F_166 ( V_193 ) ) ;
V_9 = F_168 ( V_15 , V_207 - V_193 , V_193 ,
V_190 -> V_194 & V_201 , & V_86 ,
F_177 ( V_213 ) ) ;
if ( ! V_9 )
goto V_210;
V_86 = F_159 ( & V_7 , V_9 , ! V_209 ) ;
if ( V_86 < 0 ) {
F_65 ( V_9 ) ;
goto V_210;
}
V_178 = V_86 + 1 ;
V_209 = true ;
F_169 ( V_9 , V_207 - V_193 ) ;
V_9 -> V_193 = V_193 ;
V_9 -> V_25 = V_207 ;
V_86 = F_170 ( V_9 , 0 , & V_190 -> V_204 , V_207 ) ;
if ( V_86 ) {
F_65 ( V_9 ) ;
goto V_210;
}
F_13 ( V_55 ) ;
if ( F_51 ( V_55 , V_57 ) ||
( V_55 -> V_67 & V_154 ) )
goto V_214;
F_160 ( V_9 , V_14 , V_55 ) ;
F_173 ( & V_55 -> V_17 , V_9 ) ;
if ( V_178 > F_33 ( V_55 ) -> V_180 )
F_33 ( V_55 ) -> V_180 = V_178 ;
F_15 ( V_55 ) ;
V_55 -> V_165 ( V_55 ) ;
V_208 += V_207 ;
}
F_152 ( & V_7 ) ;
return V_208 ;
V_214:
F_15 ( V_55 ) ;
F_65 ( V_9 ) ;
V_212:
if ( V_208 == 0 && ! ( V_190 -> V_194 & V_215 ) )
F_178 ( V_216 , V_82 , 0 ) ;
V_86 = - V_205 ;
V_210:
F_152 ( & V_7 ) ;
return V_208 ? : V_86 ;
}
static int F_179 ( struct V_188 * V_188 , struct V_84 * V_14 ,
struct V_189 * V_190 , T_3 V_25 )
{
int V_86 ;
struct V_14 * V_15 = V_14 -> V_15 ;
V_86 = F_180 ( V_15 ) ;
if ( V_86 )
return V_86 ;
if ( V_15 -> V_70 != V_161 )
return - V_175 ;
if ( V_190 -> V_196 )
V_190 -> V_196 = 0 ;
return F_162 ( V_188 , V_14 , V_190 , V_25 ) ;
}
static int F_181 ( struct V_188 * V_217 , struct V_84 * V_14 ,
struct V_189 * V_190 , T_3 V_207 ,
int V_144 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( V_15 -> V_70 != V_161 )
return - V_175 ;
return F_182 ( V_217 , V_14 , V_190 , V_207 , V_144 ) ;
}
static void F_183 ( struct V_189 * V_190 , struct V_14 * V_15 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
if ( V_36 -> V_2 ) {
V_190 -> V_196 = V_36 -> V_2 -> V_25 ;
memcpy ( V_190 -> V_191 , V_36 -> V_2 -> V_37 , V_36 -> V_2 -> V_25 ) ;
}
}
static int F_182 ( struct V_188 * V_217 , struct V_84 * V_14 ,
struct V_189 * V_190 , T_3 V_207 ,
int V_144 )
{
struct V_6 V_7 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
int V_218 = V_144 & V_201 ;
struct V_8 * V_9 ;
int V_86 ;
int V_219 , V_220 ;
V_86 = - V_89 ;
if ( V_144 & V_195 )
goto V_90;
V_86 = F_78 ( & V_36 -> V_93 ) ;
if ( F_116 ( V_86 ) ) {
V_86 = V_218 ? - V_160 : - V_221 ;
goto V_90;
}
V_220 = F_184 ( V_15 , V_144 ) ;
V_9 = F_185 ( V_15 , V_144 , & V_219 , & V_220 , & V_86 ) ;
if ( ! V_9 ) {
F_13 ( V_15 ) ;
if ( V_15 -> V_72 == V_74 && V_86 == - V_160 &&
( V_15 -> V_67 & V_154 ) )
V_86 = 0 ;
F_15 ( V_15 ) ;
goto V_91;
}
F_44 ( & V_36 -> V_56 ,
V_50 | V_51 | V_52 ) ;
if ( V_190 -> V_191 )
F_183 ( V_190 , V_9 -> V_15 ) ;
if ( V_207 > V_9 -> V_25 - V_220 )
V_207 = V_9 -> V_25 - V_220 ;
else if ( V_207 < V_9 -> V_25 - V_220 )
V_190 -> V_194 |= V_222 ;
V_86 = F_186 ( V_9 , V_220 , V_190 , V_207 ) ;
if ( V_86 )
goto V_203;
if ( F_51 ( V_15 , V_206 ) )
F_187 ( V_190 , V_15 , V_9 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_188 ( & V_7 , F_149 ( V_9 ) . V_87 , F_149 ( V_9 ) . V_184 , F_149 ( V_9 ) . V_186 ) ;
F_4 ( & V_7 , V_9 ) ;
if ( ! ( V_144 & V_223 ) ) {
if ( F_149 ( V_9 ) . V_176 )
F_148 ( & V_7 , V_9 ) ;
F_189 ( V_15 , V_9 -> V_25 ) ;
} else {
F_190 ( V_15 , V_207 ) ;
if ( F_149 ( V_9 ) . V_176 )
V_7 . V_176 = F_157 ( F_149 ( V_9 ) . V_176 ) ;
}
V_86 = ( V_144 & V_222 ) ? V_9 -> V_25 - V_220 : V_207 ;
F_191 ( V_14 , V_190 , & V_7 , V_144 ) ;
V_203:
F_143 ( V_15 , V_9 ) ;
V_91:
F_79 ( & V_36 -> V_93 ) ;
V_90:
return V_86 ;
}
static long F_192 ( struct V_14 * V_15 , long V_151 ,
struct V_8 * V_224 )
{
F_123 ( V_49 ) ;
F_13 ( V_15 ) ;
for (; ; ) {
F_193 ( F_194 ( V_15 ) , & V_49 , V_153 ) ;
if ( F_195 ( & V_15 -> V_17 ) != V_224 ||
V_15 -> V_58 ||
( V_15 -> V_67 & V_154 ) ||
F_131 ( V_82 ) ||
! V_151 )
break;
F_140 ( V_225 , & V_15 -> V_61 -> V_144 ) ;
F_15 ( V_15 ) ;
V_151 = F_196 ( V_151 ) ;
F_13 ( V_15 ) ;
F_197 ( V_225 , & V_15 -> V_61 -> V_144 ) ;
}
F_126 ( F_194 ( V_15 ) , & V_49 ) ;
F_15 ( V_15 ) ;
return V_151 ;
}
static unsigned int F_198 ( const struct V_8 * V_9 )
{
return V_9 -> V_25 - F_149 ( V_9 ) . V_226 ;
}
static int F_199 ( struct V_188 * V_217 , struct V_84 * V_14 ,
struct V_189 * V_190 , T_3 V_207 ,
int V_144 )
{
struct V_6 V_7 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
F_147 ( struct V_23 * , V_24 , V_190 -> V_191 ) ;
int V_227 = 0 ;
int V_218 = V_144 & V_201 ;
int V_228 = 0 ;
int V_229 ;
int V_86 = 0 ;
long V_151 ;
int V_220 ;
V_86 = - V_27 ;
if ( V_15 -> V_70 != V_161 )
goto V_90;
V_86 = - V_89 ;
if ( V_144 & V_195 )
goto V_90;
V_229 = F_200 ( V_15 , V_144 & V_230 , V_207 ) ;
V_151 = F_201 ( V_15 , V_218 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_86 = F_78 ( & V_36 -> V_93 ) ;
if ( F_116 ( V_86 ) ) {
V_86 = V_218 ? - V_160 : - V_221 ;
goto V_90;
}
do {
int V_231 ;
struct V_8 * V_9 , * V_224 ;
F_13 ( V_15 ) ;
V_224 = V_9 = F_202 ( & V_15 -> V_17 ) ;
V_232:
if ( V_9 == NULL ) {
F_33 ( V_15 ) -> V_180 = 0 ;
if ( V_227 >= V_229 )
goto V_233;
V_86 = F_180 ( V_15 ) ;
if ( V_86 )
goto V_233;
if ( V_15 -> V_67 & V_154 )
goto V_233;
F_15 ( V_15 ) ;
V_86 = - V_160 ;
if ( ! V_151 )
break;
F_79 ( & V_36 -> V_93 ) ;
V_151 = F_192 ( V_15 , V_151 , V_224 ) ;
if ( F_131 ( V_82 )
|| F_78 ( & V_36 -> V_93 ) ) {
V_86 = F_130 ( V_151 ) ;
goto V_90;
}
continue;
V_233:
F_15 ( V_15 ) ;
break;
}
V_220 = F_184 ( V_15 , V_144 ) ;
while ( V_220 >= F_198 ( V_9 ) ) {
V_220 -= F_198 ( V_9 ) ;
V_224 = V_9 ;
V_9 = F_203 ( V_9 , & V_15 -> V_17 ) ;
if ( ! V_9 )
goto V_232;
}
F_15 ( V_15 ) ;
if ( V_228 ) {
if ( ( F_149 ( V_9 ) . V_87 != V_7 . V_87 ) ||
! F_204 ( F_149 ( V_9 ) . V_184 , V_7 . V_185 . V_184 ) ||
! F_205 ( F_149 ( V_9 ) . V_186 , V_7 . V_185 . V_186 ) )
break;
} else if ( F_120 ( V_147 , & V_14 -> V_144 ) ) {
F_188 ( & V_7 , F_149 ( V_9 ) . V_87 , F_149 ( V_9 ) . V_184 , F_149 ( V_9 ) . V_186 ) ;
V_228 = 1 ;
}
if ( V_24 ) {
F_183 ( V_190 , V_9 -> V_15 ) ;
V_24 = NULL ;
}
V_231 = F_165 (unsigned int, unix_skb_len(skb) - skip, size) ;
if ( F_186 ( V_9 , F_149 ( V_9 ) . V_226 + V_220 ,
V_190 , V_231 ) ) {
if ( V_227 == 0 )
V_227 = - V_234 ;
break;
}
V_227 += V_231 ;
V_207 -= V_231 ;
if ( ! ( V_144 & V_223 ) ) {
F_149 ( V_9 ) . V_226 += V_231 ;
F_189 ( V_15 , V_231 ) ;
if ( F_149 ( V_9 ) . V_176 )
F_148 ( & V_7 , V_9 ) ;
if ( F_198 ( V_9 ) )
break;
F_206 ( V_9 , & V_15 -> V_17 ) ;
F_207 ( V_9 ) ;
if ( V_7 . V_176 )
break;
} else {
if ( F_149 ( V_9 ) . V_176 )
V_7 . V_176 = F_157 ( F_149 ( V_9 ) . V_176 ) ;
F_190 ( V_15 , V_231 ) ;
break;
}
} while ( V_207 );
F_79 ( & V_36 -> V_93 ) ;
F_191 ( V_14 , V_190 , & V_7 , V_144 ) ;
V_90:
return V_227 ? : V_86 ;
}
static int F_208 ( struct V_84 * V_14 , int V_130 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_55 ;
if ( V_130 < V_235 || V_130 > V_236 )
return - V_27 ;
++ V_130 ;
F_13 ( V_15 ) ;
V_15 -> V_67 |= V_130 ;
V_55 = F_8 ( V_15 ) ;
if ( V_55 )
F_14 ( V_55 ) ;
F_15 ( V_15 ) ;
V_15 -> V_75 ( V_15 ) ;
if ( V_55 &&
( V_15 -> V_72 == V_73 || V_15 -> V_72 == V_74 ) ) {
int V_237 = 0 ;
if ( V_130 & V_154 )
V_237 |= V_211 ;
if ( V_130 & V_211 )
V_237 |= V_154 ;
F_13 ( V_55 ) ;
V_55 -> V_67 |= V_237 ;
F_15 ( V_55 ) ;
V_55 -> V_75 ( V_55 ) ;
if ( V_237 == V_68 )
F_45 ( V_55 , V_76 , V_77 ) ;
else if ( V_237 & V_154 )
F_45 ( V_55 , V_76 , V_238 ) ;
}
if ( V_55 )
F_63 ( V_55 ) ;
return 0 ;
}
long F_209 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
long V_239 = 0 ;
if ( V_15 -> V_70 == V_78 )
return - V_27 ;
F_28 ( & V_15 -> V_17 . V_99 ) ;
if ( V_15 -> V_72 == V_73 ||
V_15 -> V_72 == V_74 ) {
F_210 (&sk->sk_receive_queue, skb)
V_239 += F_198 ( V_9 ) ;
} else {
V_9 = F_202 ( & V_15 -> V_17 ) ;
if ( V_9 )
V_239 = V_9 -> V_25 ;
}
F_29 ( & V_15 -> V_17 . V_99 ) ;
return V_239 ;
}
long F_211 ( struct V_14 * V_15 )
{
return F_212 ( V_15 ) ;
}
static int F_213 ( struct V_84 * V_14 , unsigned int V_240 , unsigned long V_241 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
long V_239 = 0 ;
int V_86 ;
switch ( V_240 ) {
case V_242 :
V_239 = F_211 ( V_15 ) ;
V_86 = F_214 ( V_239 , ( int V_243 * ) V_241 ) ;
break;
case V_244 :
V_239 = F_209 ( V_15 ) ;
if ( V_239 < 0 )
V_86 = V_239 ;
else
V_86 = F_214 ( V_239 , ( int V_243 * ) V_241 ) ;
break;
default:
V_86 = - V_245 ;
break;
}
return V_86 ;
}
static unsigned int F_215 ( struct V_246 * V_246 , struct V_84 * V_14 , T_4 * V_49 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
unsigned int V_247 ;
F_216 ( V_246 , F_194 ( V_15 ) , V_49 ) ;
V_247 = 0 ;
if ( V_15 -> V_58 )
V_247 |= V_248 ;
if ( V_15 -> V_67 == V_68 )
V_247 |= V_249 ;
if ( V_15 -> V_67 & V_154 )
V_247 |= V_250 | V_251 | V_252 ;
if ( ! F_48 ( & V_15 -> V_17 ) )
V_247 |= V_251 | V_252 ;
if ( ( V_15 -> V_72 == V_73 || V_15 -> V_72 == V_74 ) &&
V_15 -> V_70 == V_71 )
V_247 |= V_249 ;
if ( F_38 ( V_15 ) )
V_247 |= V_50 | V_51 | V_52 ;
return V_247 ;
}
static unsigned int F_217 ( struct V_246 * V_246 , struct V_84 * V_14 ,
T_4 * V_49 )
{
struct V_14 * V_15 = V_14 -> V_15 , * V_55 ;
unsigned int V_247 , V_253 ;
F_216 ( V_246 , F_194 ( V_15 ) , V_49 ) ;
V_247 = 0 ;
if ( V_15 -> V_58 || ! F_48 ( & V_15 -> V_254 ) )
V_247 |= V_248 |
( F_51 ( V_15 , V_255 ) ? V_256 : 0 ) ;
if ( V_15 -> V_67 & V_154 )
V_247 |= V_250 | V_251 | V_252 ;
if ( V_15 -> V_67 == V_68 )
V_247 |= V_249 ;
if ( ! F_48 ( & V_15 -> V_17 ) )
V_247 |= V_251 | V_252 ;
if ( V_15 -> V_72 == V_74 ) {
if ( V_15 -> V_70 == V_71 )
V_247 |= V_249 ;
if ( V_15 -> V_70 == V_257 )
return V_247 ;
}
if ( ! ( F_218 ( V_49 ) & ( V_52 | V_51 | V_50 ) ) )
return V_247 ;
V_253 = F_38 ( V_15 ) ;
V_55 = F_12 ( V_15 ) ;
if ( V_55 ) {
if ( F_8 ( V_55 ) != V_15 ) {
F_216 ( V_246 , & F_33 ( V_55 ) -> V_56 , V_49 ) ;
if ( F_10 ( V_55 ) )
V_253 = 0 ;
}
F_63 ( V_55 ) ;
}
if ( V_253 )
V_247 |= V_50 | V_51 | V_52 ;
else
F_140 ( V_258 , & V_15 -> V_61 -> V_144 ) ;
return V_247 ;
}
static struct V_14 * F_219 ( struct V_259 * V_260 , T_5 * V_261 )
{
unsigned long V_262 = F_220 ( * V_261 ) ;
unsigned long V_263 = F_221 ( * V_261 ) ;
struct V_14 * V_15 ;
unsigned long V_177 = 0 ;
for ( V_15 = F_222 ( & V_5 [ V_263 ] ) ; V_15 ; V_15 = F_223 ( V_15 ) ) {
if ( F_35 ( V_15 ) != F_224 ( V_260 ) )
continue;
if ( ++ V_177 == V_262 )
break;
}
return V_15 ;
}
static struct V_14 * F_225 ( struct V_259 * V_260 ,
struct V_14 * V_15 ,
T_5 * V_261 )
{
unsigned long V_263 ;
while ( V_15 > (struct V_14 * ) V_264 ) {
V_15 = F_223 ( V_15 ) ;
if ( ! V_15 )
goto V_265;
if ( F_35 ( V_15 ) == F_224 ( V_260 ) )
return V_15 ;
}
do {
V_15 = F_219 ( V_260 , V_261 ) ;
if ( V_15 )
return V_15 ;
V_265:
V_263 = F_221 ( * V_261 ) + 1 ;
* V_261 = F_226 ( V_263 , 1 ) ;
} while ( V_263 < F_227 ( V_5 ) );
return NULL ;
}
static void * F_228 ( struct V_259 * V_260 , T_5 * V_261 )
__acquires( V_32 )
{
F_28 ( & V_32 ) ;
if ( ! * V_261 )
return V_264 ;
if ( F_221 ( * V_261 ) >= F_227 ( V_5 ) )
return NULL ;
return F_225 ( V_260 , NULL , V_261 ) ;
}
static void * F_229 ( struct V_259 * V_260 , void * V_266 , T_5 * V_261 )
{
++ * V_261 ;
return F_225 ( V_260 , V_266 , V_261 ) ;
}
static void F_230 ( struct V_259 * V_260 , void * V_266 )
__releases( V_32 )
{
F_29 ( & V_32 ) ;
}
static int F_231 ( struct V_259 * V_260 , void * V_266 )
{
if ( V_266 == V_264 )
F_232 ( V_260 , L_4
L_5 ) ;
else {
struct V_14 * V_19 = V_266 ;
struct V_35 * V_36 = F_33 ( V_19 ) ;
F_13 ( V_19 ) ;
F_233 ( V_260 , L_6 ,
V_19 ,
F_39 ( & V_19 -> V_267 ) ,
0 ,
V_19 -> V_70 == V_78 ? V_268 : 0 ,
V_19 -> V_72 ,
V_19 -> V_61 ?
( V_19 -> V_70 == V_161 ? V_164 : V_110 ) :
( V_19 -> V_70 == V_161 ? V_269 : V_270 ) ,
F_234 ( V_19 ) ) ;
if ( V_36 -> V_2 ) {
int V_40 , V_25 ;
F_235 ( V_260 , ' ' ) ;
V_40 = 0 ;
V_25 = V_36 -> V_2 -> V_25 - sizeof( short ) ;
if ( ! F_236 ( V_19 ) )
V_25 -- ;
else {
F_235 ( V_260 , '@' ) ;
V_40 ++ ;
}
for ( ; V_40 < V_25 ; V_40 ++ )
F_235 ( V_260 , V_36 -> V_2 -> V_37 -> V_30 [ V_40 ] ) ;
}
F_15 ( V_19 ) ;
F_235 ( V_260 , '\n' ) ;
}
return 0 ;
}
static int F_237 ( struct V_39 * V_39 , struct V_246 * V_246 )
{
return F_238 ( V_39 , V_246 , & V_271 ,
sizeof( struct V_272 ) ) ;
}
static int T_6 F_239 ( struct V_33 * V_33 )
{
int error = - V_118 ;
V_33 -> V_102 . V_103 = 10 ;
if ( F_240 ( V_33 ) )
goto V_90;
#ifdef F_241
if ( ! F_242 ( L_7 , 0 , V_33 -> V_273 , & V_274 ) ) {
F_243 ( V_33 ) ;
goto V_90;
}
#endif
error = 0 ;
V_90:
return error ;
}
static void T_7 F_244 ( struct V_33 * V_33 )
{
F_243 ( V_33 ) ;
F_245 ( L_7 , V_33 -> V_273 ) ;
}
static int T_8 F_246 ( void )
{
int V_275 = - 1 ;
F_167 ( sizeof( struct V_276 ) > F_247 ( struct V_8 , V_277 ) ) ;
V_275 = F_248 ( & V_98 , 1 ) ;
if ( V_275 != 0 ) {
F_249 ( L_8 , V_278 ) ;
goto V_90;
}
F_250 ( & V_279 ) ;
F_251 ( & V_280 ) ;
V_90:
return V_275 ;
}
static void T_9 F_252 ( void )
{
F_253 ( V_96 ) ;
F_254 ( & V_98 ) ;
F_255 ( & V_280 ) ;
}
