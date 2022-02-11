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
F_3 ( V_9 ) . V_10 = V_7 -> V_10 ;
}
static inline void F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_7 -> V_10 = F_3 ( V_9 ) . V_10 ;
}
static inline bool F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
return ( V_7 -> V_10 == F_3 ( V_9 ) . V_10 ) ;
}
static inline void F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{ }
static inline void F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{ }
static inline bool F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
return true ;
}
static inline unsigned int F_6 ( T_1 V_11 )
{
unsigned int V_3 = ( V_12 unsigned int ) F_7 ( V_11 ) ;
V_3 ^= V_3 >> 8 ;
return V_3 & ( V_4 - 1 ) ;
}
static inline int F_8 ( struct V_13 * V_14 , struct V_13 * V_15 )
{
return F_9 ( V_15 ) == V_14 ;
}
static inline int F_10 ( struct V_13 * V_14 , struct V_13 * V_15 )
{
return F_9 ( V_15 ) == NULL || F_8 ( V_14 , V_15 ) ;
}
static inline int F_11 ( struct V_13 const * V_14 )
{
return F_12 ( & V_14 -> V_16 ) > V_14 -> V_17 ;
}
struct V_13 * F_13 ( struct V_13 * V_18 )
{
struct V_13 * V_19 ;
F_14 ( V_18 ) ;
V_19 = F_9 ( V_18 ) ;
if ( V_19 )
F_15 ( V_19 ) ;
F_16 ( V_18 ) ;
return V_19 ;
}
static inline void F_17 ( struct V_20 * V_2 )
{
if ( F_18 ( & V_2 -> V_21 ) )
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_22 * V_23 , int V_24 , unsigned int * V_25 )
{
if ( V_24 <= sizeof( short ) || V_24 > sizeof( * V_23 ) )
return - V_26 ;
if ( ! V_23 || V_23 -> V_27 != V_28 )
return - V_26 ;
if ( V_23 -> V_29 [ 0 ] ) {
( ( char * ) V_23 ) [ V_24 ] = 0 ;
V_24 = strlen ( V_23 -> V_29 ) + 1 + sizeof( short ) ;
return V_24 ;
}
* V_25 = F_6 ( F_21 ( V_23 , V_24 , 0 ) ) ;
return V_24 ;
}
static void F_22 ( struct V_13 * V_14 )
{
F_23 ( V_14 ) ;
}
static void F_24 ( struct V_1 * V_30 , struct V_13 * V_14 )
{
F_25 ( ! F_26 ( V_14 ) ) ;
F_27 ( V_14 , V_30 ) ;
}
static inline void F_28 ( struct V_13 * V_14 )
{
F_29 ( & V_31 ) ;
F_22 ( V_14 ) ;
F_30 ( & V_31 ) ;
}
static inline void F_31 ( struct V_1 * V_30 , struct V_13 * V_14 )
{
F_29 ( & V_31 ) ;
F_24 ( V_30 , V_14 ) ;
F_30 ( & V_31 ) ;
}
static struct V_13 * F_32 ( struct V_32 * V_32 ,
struct V_22 * V_33 ,
int V_24 , int type , unsigned int V_3 )
{
struct V_13 * V_18 ;
F_33 (s, &unix_socket_table[hash ^ type]) {
struct V_34 * V_35 = F_34 ( V_18 ) ;
if ( ! F_35 ( F_36 ( V_18 ) , V_32 ) )
continue;
if ( V_35 -> V_2 -> V_24 == V_24 &&
! memcmp ( V_35 -> V_2 -> V_36 , V_33 , V_24 ) )
goto V_37;
}
V_18 = NULL ;
V_37:
return V_18 ;
}
static inline struct V_13 * F_37 ( struct V_32 * V_32 ,
struct V_22 * V_33 ,
int V_24 , int type ,
unsigned int V_3 )
{
struct V_13 * V_18 ;
F_29 ( & V_31 ) ;
V_18 = F_32 ( V_32 , V_33 , V_24 , type , V_3 ) ;
if ( V_18 )
F_15 ( V_18 ) ;
F_30 ( & V_31 ) ;
return V_18 ;
}
static struct V_13 * F_38 ( struct V_38 * V_39 )
{
struct V_13 * V_18 ;
F_29 ( & V_31 ) ;
F_33 (s,
&unix_socket_table[i->i_ino & (UNIX_HASH_SIZE - 1)]) {
struct V_40 * V_40 = F_34 ( V_18 ) -> V_41 . V_40 ;
if ( V_40 && F_39 ( V_40 ) == V_39 ) {
F_15 ( V_18 ) ;
goto V_37;
}
}
V_18 = NULL ;
V_37:
F_30 ( & V_31 ) ;
return V_18 ;
}
static inline int F_40 ( struct V_13 * V_14 )
{
return ( F_41 ( & V_14 -> V_42 ) << 2 ) <= V_14 -> V_43 ;
}
static void F_42 ( struct V_13 * V_14 )
{
struct V_44 * V_45 ;
F_43 () ;
if ( F_40 ( V_14 ) ) {
V_45 = F_44 ( V_14 -> V_46 ) ;
if ( F_45 ( V_45 ) )
F_46 ( & V_45 -> V_47 ,
V_48 | V_49 | V_50 ) ;
F_47 ( V_14 , V_51 , V_52 ) ;
}
F_48 () ;
}
static void F_49 ( struct V_13 * V_14 , struct V_13 * V_53 )
{
if ( ! F_50 ( & V_14 -> V_16 ) ) {
F_51 ( & V_14 -> V_16 ) ;
F_52 ( & F_34 ( V_14 ) -> V_54 ) ;
if ( ! F_53 ( V_53 , V_55 ) && F_9 ( V_53 ) == V_14 ) {
V_53 -> V_56 = V_57 ;
V_53 -> V_58 ( V_53 ) ;
}
}
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_51 ( & V_14 -> V_16 ) ;
F_25 ( F_41 ( & V_14 -> V_42 ) ) ;
F_25 ( ! F_26 ( V_14 ) ) ;
F_25 ( V_14 -> V_59 ) ;
if ( ! F_53 ( V_14 , V_55 ) ) {
F_55 ( L_1 , V_14 ) ;
return;
}
if ( V_35 -> V_2 )
F_17 ( V_35 -> V_2 ) ;
F_56 ( & V_60 ) ;
F_57 () ;
F_58 ( F_36 ( V_14 ) , V_14 -> V_61 , - 1 ) ;
F_59 () ;
#ifdef F_60
F_61 ( L_2 , V_14 ,
F_62 ( & V_60 ) ) ;
#endif
}
static void F_63 ( struct V_13 * V_14 , int V_62 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_41 V_41 ;
struct V_13 * V_63 ;
struct V_8 * V_9 ;
int V_64 ;
F_28 ( V_14 ) ;
F_14 ( V_14 ) ;
F_64 ( V_14 ) ;
V_14 -> V_65 = V_66 ;
V_41 = V_35 -> V_41 ;
V_35 -> V_41 . V_40 = NULL ;
V_35 -> V_41 . V_67 = NULL ;
V_64 = V_14 -> V_68 ;
V_14 -> V_68 = V_69 ;
F_16 ( V_14 ) ;
F_52 ( & V_35 -> V_54 ) ;
V_63 = F_9 ( V_14 ) ;
if ( V_63 != NULL ) {
if ( V_14 -> V_70 == V_71 || V_14 -> V_70 == V_72 ) {
F_14 ( V_63 ) ;
V_63 -> V_65 = V_66 ;
if ( ! F_50 ( & V_14 -> V_16 ) || V_62 )
V_63 -> V_56 = V_57 ;
F_16 ( V_63 ) ;
V_63 -> V_73 ( V_63 ) ;
F_47 ( V_63 , V_74 , V_75 ) ;
}
F_65 ( V_63 ) ;
F_9 ( V_14 ) = NULL ;
}
while ( ( V_9 = F_66 ( & V_14 -> V_16 ) ) != NULL ) {
if ( V_64 == V_76 )
F_63 ( V_9 -> V_14 , 1 ) ;
F_67 ( V_9 ) ;
}
if ( V_41 . V_40 )
F_68 ( & V_41 ) ;
F_65 ( V_14 ) ;
if ( V_77 )
F_69 () ;
}
static void F_70 ( struct V_13 * V_14 )
{
F_71 ( V_14 -> V_78 ) ;
if ( V_14 -> V_79 )
F_72 ( V_14 -> V_79 ) ;
V_14 -> V_78 = F_73 ( F_74 ( V_80 ) ) ;
V_14 -> V_79 = F_75 () ;
}
static void F_76 ( struct V_13 * V_14 , struct V_13 * V_81 )
{
F_71 ( V_14 -> V_78 ) ;
if ( V_14 -> V_79 )
F_72 ( V_14 -> V_79 ) ;
V_14 -> V_78 = F_73 ( V_81 -> V_78 ) ;
V_14 -> V_79 = F_77 ( V_81 -> V_79 ) ;
}
static int F_78 ( struct V_82 * V_13 , int V_83 )
{
int V_84 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_85 * V_86 = NULL ;
V_84 = - V_87 ;
if ( V_13 -> type != V_71 && V_13 -> type != V_72 )
goto V_88;
V_84 = - V_26 ;
if ( ! V_35 -> V_2 )
goto V_88;
F_14 ( V_14 ) ;
if ( V_14 -> V_68 != V_69 && V_14 -> V_68 != V_76 )
goto V_89;
if ( V_83 > V_14 -> V_17 )
F_52 ( & V_35 -> V_54 ) ;
V_14 -> V_17 = V_83 ;
V_14 -> V_68 = V_76 ;
F_70 ( V_14 ) ;
V_84 = 0 ;
V_89:
F_16 ( V_14 ) ;
F_71 ( V_86 ) ;
V_88:
return V_84 ;
}
static int F_79 ( struct V_13 * V_14 , int V_90 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
if ( F_80 ( & V_35 -> V_91 ) )
return - V_92 ;
V_14 -> V_93 = V_90 ;
F_81 ( & V_35 -> V_91 ) ;
return 0 ;
}
static struct V_13 * F_82 ( struct V_32 * V_32 , struct V_82 * V_13 , int V_94 )
{
struct V_13 * V_14 = NULL ;
struct V_34 * V_35 ;
F_83 ( & V_60 ) ;
if ( F_62 ( & V_60 ) > 2 * F_84 () )
goto V_88;
V_14 = F_85 ( V_32 , V_95 , V_96 , & V_97 , V_94 ) ;
if ( ! V_14 )
goto V_88;
F_86 ( V_13 , V_14 ) ;
F_87 ( & V_14 -> V_16 . V_98 ,
& V_99 ) ;
V_14 -> V_100 = F_42 ;
V_14 -> V_17 = V_32 -> V_101 . V_102 ;
V_14 -> V_103 = F_54 ;
V_35 = F_34 ( V_14 ) ;
V_35 -> V_41 . V_40 = NULL ;
V_35 -> V_41 . V_67 = NULL ;
F_88 ( & V_35 -> V_98 ) ;
F_89 ( & V_35 -> V_104 , 0 ) ;
F_90 ( & V_35 -> V_105 ) ;
F_91 ( & V_35 -> V_91 ) ;
F_92 ( & V_35 -> V_54 ) ;
F_31 ( F_1 ( V_14 ) , V_14 ) ;
V_88:
if ( V_14 == NULL )
F_56 ( & V_60 ) ;
else {
F_57 () ;
F_58 ( F_36 ( V_14 ) , V_14 -> V_61 , 1 ) ;
F_59 () ;
}
return V_14 ;
}
static int F_93 ( struct V_32 * V_32 , struct V_82 * V_13 , int V_106 ,
int V_94 )
{
if ( V_106 && V_106 != V_95 )
return - V_107 ;
V_13 -> V_64 = V_108 ;
switch ( V_13 -> type ) {
case V_71 :
V_13 -> V_109 = & V_110 ;
break;
case V_111 :
V_13 -> type = V_112 ;
case V_112 :
V_13 -> V_109 = & V_113 ;
break;
case V_72 :
V_13 -> V_109 = & V_114 ;
break;
default:
return - V_115 ;
}
return F_82 ( V_32 , V_13 , V_94 ) ? 0 : - V_116 ;
}
static int F_94 ( struct V_82 * V_13 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
if ( ! V_14 )
return 0 ;
F_63 ( V_14 , 0 ) ;
V_13 -> V_14 = NULL ;
return 0 ;
}
static int F_95 ( struct V_82 * V_13 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
static T_2 V_117 = 1 ;
struct V_20 * V_2 ;
int V_84 ;
unsigned int V_118 = 0 ;
V_84 = F_80 ( & V_35 -> V_91 ) ;
if ( V_84 )
return V_84 ;
V_84 = 0 ;
if ( V_35 -> V_2 )
goto V_88;
V_84 = - V_116 ;
V_2 = F_96 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_96 ) ;
if ( ! V_2 )
goto V_88;
V_2 -> V_36 -> V_27 = V_28 ;
F_97 ( & V_2 -> V_21 , 1 ) ;
V_119:
V_2 -> V_24 = sprintf ( V_2 -> V_36 -> V_29 + 1 , L_3 , V_117 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_6 ( F_21 ( V_2 -> V_36 , V_2 -> V_24 , 0 ) ) ;
F_29 ( & V_31 ) ;
V_117 = ( V_117 + 1 ) & 0xFFFFF ;
if ( F_32 ( V_32 , V_2 -> V_36 , V_2 -> V_24 , V_13 -> type ,
V_2 -> V_3 ) ) {
F_30 ( & V_31 ) ;
F_98 () ;
if ( V_118 ++ == 0xFFFFF ) {
V_84 = - V_120 ;
F_19 ( V_2 ) ;
goto V_88;
}
goto V_119;
}
V_2 -> V_3 ^= V_14 -> V_70 ;
F_22 ( V_14 ) ;
V_35 -> V_2 = V_2 ;
F_24 ( & V_5 [ V_2 -> V_3 ] , V_14 ) ;
F_30 ( & V_31 ) ;
V_84 = 0 ;
V_88: F_81 ( & V_35 -> V_91 ) ;
return V_84 ;
}
static struct V_13 * F_99 ( struct V_32 * V_32 ,
struct V_22 * V_33 , int V_24 ,
int type , unsigned int V_3 , int * error )
{
struct V_13 * V_35 ;
struct V_41 V_41 ;
int V_84 = 0 ;
if ( V_33 -> V_29 [ 0 ] ) {
struct V_38 * V_38 ;
V_84 = F_100 ( V_33 -> V_29 , V_121 , & V_41 ) ;
if ( V_84 )
goto V_122;
V_38 = F_39 ( V_41 . V_40 ) ;
V_84 = F_101 ( V_38 , V_123 ) ;
if ( V_84 )
goto V_124;
V_84 = - V_125 ;
if ( ! F_102 ( V_38 -> V_126 ) )
goto V_124;
V_35 = F_38 ( V_38 ) ;
if ( ! V_35 )
goto V_124;
if ( V_35 -> V_70 == type )
F_103 ( & V_41 ) ;
F_68 ( & V_41 ) ;
V_84 = - V_127 ;
if ( V_35 -> V_70 != type ) {
F_65 ( V_35 ) ;
goto V_122;
}
} else {
V_84 = - V_125 ;
V_35 = F_37 ( V_32 , V_33 , V_24 , type , V_3 ) ;
if ( V_35 ) {
struct V_40 * V_40 ;
V_40 = F_34 ( V_35 ) -> V_41 . V_40 ;
if ( V_40 )
F_103 ( & F_34 ( V_35 ) -> V_41 ) ;
} else
goto V_122;
}
return V_35 ;
V_124:
F_68 ( & V_41 ) ;
V_122:
* error = V_84 ;
return NULL ;
}
static int F_104 ( const char * V_29 , T_3 V_128 , struct V_41 * V_129 )
{
struct V_40 * V_40 ;
struct V_41 V_41 ;
int V_84 = 0 ;
V_40 = F_105 ( V_130 , V_29 , & V_41 , 0 ) ;
V_84 = F_106 ( V_40 ) ;
if ( F_107 ( V_40 ) )
return V_84 ;
V_84 = F_108 ( & V_41 , V_40 , V_128 , 0 ) ;
if ( ! V_84 ) {
V_84 = F_109 ( F_110 ( V_41 . V_40 ) , V_40 , V_128 , 0 ) ;
if ( ! V_84 ) {
V_129 -> V_67 = F_111 ( V_41 . V_67 ) ;
V_129 -> V_40 = F_112 ( V_40 ) ;
}
}
F_113 ( & V_41 , V_40 ) ;
return V_84 ;
}
static int F_114 ( struct V_82 * V_13 , struct V_131 * V_132 , int V_133 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_22 * V_23 = (struct V_22 * ) V_132 ;
char * V_29 = V_23 -> V_29 ;
int V_84 ;
unsigned int V_3 ;
struct V_20 * V_2 ;
struct V_1 * V_30 ;
V_84 = - V_26 ;
if ( V_23 -> V_27 != V_28 )
goto V_88;
if ( V_133 == sizeof( short ) ) {
V_84 = F_95 ( V_13 ) ;
goto V_88;
}
V_84 = F_20 ( V_23 , V_133 , & V_3 ) ;
if ( V_84 < 0 )
goto V_88;
V_133 = V_84 ;
V_84 = F_80 ( & V_35 -> V_91 ) ;
if ( V_84 )
goto V_88;
V_84 = - V_26 ;
if ( V_35 -> V_2 )
goto V_134;
V_84 = - V_116 ;
V_2 = F_115 ( sizeof( * V_2 ) + V_133 , V_96 ) ;
if ( ! V_2 )
goto V_134;
memcpy ( V_2 -> V_36 , V_23 , V_133 ) ;
V_2 -> V_24 = V_133 ;
V_2 -> V_3 = V_3 ^ V_14 -> V_70 ;
F_97 ( & V_2 -> V_21 , 1 ) ;
if ( V_29 [ 0 ] ) {
struct V_41 V_41 ;
T_3 V_128 = V_135 |
( F_116 ( V_13 ) -> V_126 & ~ F_117 () ) ;
V_84 = F_104 ( V_29 , V_128 , & V_41 ) ;
if ( V_84 ) {
if ( V_84 == - V_136 )
V_84 = - V_137 ;
F_17 ( V_2 ) ;
goto V_134;
}
V_2 -> V_3 = V_4 ;
V_3 = F_39 ( V_41 . V_40 ) -> V_138 & ( V_4 - 1 ) ;
F_29 ( & V_31 ) ;
V_35 -> V_41 = V_41 ;
V_30 = & V_5 [ V_3 ] ;
} else {
F_29 ( & V_31 ) ;
V_84 = - V_137 ;
if ( F_32 ( V_32 , V_23 , V_133 ,
V_14 -> V_70 , V_3 ) ) {
F_17 ( V_2 ) ;
goto V_89;
}
V_30 = & V_5 [ V_2 -> V_3 ] ;
}
V_84 = 0 ;
F_22 ( V_14 ) ;
V_35 -> V_2 = V_2 ;
F_24 ( V_30 , V_14 ) ;
V_89:
F_30 ( & V_31 ) ;
V_134:
F_81 ( & V_35 -> V_91 ) ;
V_88:
return V_84 ;
}
static void F_118 ( struct V_13 * V_139 , struct V_13 * V_140 )
{
if ( F_119 ( V_139 == V_140 ) || ! V_140 ) {
F_14 ( V_139 ) ;
return;
}
if ( V_139 < V_140 ) {
F_14 ( V_139 ) ;
F_120 ( V_140 ) ;
} else {
F_14 ( V_140 ) ;
F_120 ( V_139 ) ;
}
}
static void F_121 ( struct V_13 * V_139 , struct V_13 * V_140 )
{
if ( F_119 ( V_139 == V_140 ) || ! V_140 ) {
F_16 ( V_139 ) ;
return;
}
F_16 ( V_139 ) ;
F_16 ( V_140 ) ;
}
static int F_122 ( struct V_82 * V_13 , struct V_131 * V_2 ,
int V_141 , int V_142 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_22 * V_23 = (struct V_22 * ) V_2 ;
struct V_13 * V_53 ;
unsigned int V_3 ;
int V_84 ;
if ( V_2 -> V_143 != V_144 ) {
V_84 = F_20 ( V_23 , V_141 , & V_3 ) ;
if ( V_84 < 0 )
goto V_88;
V_141 = V_84 ;
if ( F_123 ( V_145 , & V_13 -> V_142 ) &&
! F_34 ( V_14 ) -> V_2 && ( V_84 = F_95 ( V_13 ) ) != 0 )
goto V_88;
V_146:
V_53 = F_99 ( V_32 , V_23 , V_141 , V_13 -> type , V_3 , & V_84 ) ;
if ( ! V_53 )
goto V_88;
F_118 ( V_14 , V_53 ) ;
if ( F_53 ( V_53 , V_55 ) ) {
F_121 ( V_14 , V_53 ) ;
F_65 ( V_53 ) ;
goto V_146;
}
V_84 = - V_147 ;
if ( ! F_10 ( V_14 , V_53 ) )
goto V_89;
V_84 = F_124 ( V_14 -> V_59 , V_53 -> V_59 ) ;
if ( V_84 )
goto V_89;
} else {
V_53 = NULL ;
F_118 ( V_14 , V_53 ) ;
}
if ( F_9 ( V_14 ) ) {
struct V_13 * V_148 = F_9 ( V_14 ) ;
F_9 ( V_14 ) = V_53 ;
F_121 ( V_14 , V_53 ) ;
if ( V_53 != V_148 )
F_49 ( V_14 , V_148 ) ;
F_65 ( V_148 ) ;
} else {
F_9 ( V_14 ) = V_53 ;
F_121 ( V_14 , V_53 ) ;
}
return 0 ;
V_89:
F_121 ( V_14 , V_53 ) ;
F_65 ( V_53 ) ;
V_88:
return V_84 ;
}
static long F_125 ( struct V_13 * V_53 , long V_149 )
{
struct V_34 * V_35 = F_34 ( V_53 ) ;
int V_150 ;
F_126 ( V_47 ) ;
F_127 ( & V_35 -> V_54 , & V_47 , V_151 ) ;
V_150 = ! F_53 ( V_53 , V_55 ) &&
! ( V_53 -> V_65 & V_152 ) &&
F_11 ( V_53 ) ;
F_16 ( V_53 ) ;
if ( V_150 )
V_149 = F_128 ( V_149 ) ;
F_129 ( & V_35 -> V_54 , & V_47 ) ;
return V_149 ;
}
static int F_130 ( struct V_82 * V_13 , struct V_131 * V_132 ,
int V_133 , int V_142 )
{
struct V_22 * V_23 = (struct V_22 * ) V_132 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) , * V_153 , * V_154 ;
struct V_13 * V_155 = NULL ;
struct V_13 * V_53 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_156 ;
int V_84 ;
long V_149 ;
V_84 = F_20 ( V_23 , V_133 , & V_3 ) ;
if ( V_84 < 0 )
goto V_88;
V_133 = V_84 ;
if ( F_123 ( V_145 , & V_13 -> V_142 ) && ! V_35 -> V_2 &&
( V_84 = F_95 ( V_13 ) ) != 0 )
goto V_88;
V_149 = F_131 ( V_14 , V_142 & V_157 ) ;
V_84 = - V_116 ;
V_155 = F_82 ( F_36 ( V_14 ) , NULL , 0 ) ;
if ( V_155 == NULL )
goto V_88;
V_9 = F_132 ( V_155 , 1 , 0 , V_96 ) ;
if ( V_9 == NULL )
goto V_88;
V_146:
V_53 = F_99 ( V_32 , V_23 , V_133 , V_14 -> V_70 , V_3 , & V_84 ) ;
if ( ! V_53 )
goto V_88;
F_14 ( V_53 ) ;
if ( F_53 ( V_53 , V_55 ) ) {
F_16 ( V_53 ) ;
F_65 ( V_53 ) ;
goto V_146;
}
V_84 = - V_125 ;
if ( V_53 -> V_68 != V_76 )
goto V_89;
if ( V_53 -> V_65 & V_152 )
goto V_89;
if ( F_11 ( V_53 ) ) {
V_84 = - V_158 ;
if ( ! V_149 )
goto V_89;
V_149 = F_125 ( V_53 , V_149 ) ;
V_84 = F_133 ( V_149 ) ;
if ( F_134 ( V_80 ) )
goto V_88;
F_65 ( V_53 ) ;
goto V_146;
}
V_156 = V_14 -> V_68 ;
switch ( V_156 ) {
case V_69 :
break;
case V_159 :
V_84 = - V_160 ;
goto V_89;
default:
V_84 = - V_26 ;
goto V_89;
}
F_120 ( V_14 ) ;
if ( V_14 -> V_68 != V_156 ) {
F_16 ( V_14 ) ;
F_16 ( V_53 ) ;
F_65 ( V_53 ) ;
goto V_146;
}
V_84 = F_135 ( V_14 , V_53 , V_155 ) ;
if ( V_84 ) {
F_16 ( V_14 ) ;
goto V_89;
}
F_15 ( V_14 ) ;
F_9 ( V_155 ) = V_14 ;
V_155 -> V_68 = V_159 ;
V_155 -> V_70 = V_14 -> V_70 ;
F_70 ( V_155 ) ;
V_153 = F_34 ( V_155 ) ;
F_136 ( V_155 -> V_46 , & V_153 -> V_161 ) ;
V_154 = F_34 ( V_53 ) ;
if ( V_154 -> V_2 ) {
F_137 ( & V_154 -> V_2 -> V_21 ) ;
V_153 -> V_2 = V_154 -> V_2 ;
}
if ( V_154 -> V_41 . V_40 ) {
F_138 ( & V_154 -> V_41 ) ;
V_153 -> V_41 = V_154 -> V_41 ;
}
F_76 ( V_14 , V_53 ) ;
V_13 -> V_64 = V_162 ;
V_14 -> V_68 = V_159 ;
F_15 ( V_155 ) ;
F_139 () ;
F_9 ( V_14 ) = V_155 ;
F_16 ( V_14 ) ;
F_29 ( & V_53 -> V_16 . V_98 ) ;
F_140 ( & V_53 -> V_16 , V_9 ) ;
F_30 ( & V_53 -> V_16 . V_98 ) ;
F_16 ( V_53 ) ;
V_53 -> V_163 ( V_53 ) ;
F_65 ( V_53 ) ;
return 0 ;
V_89:
if ( V_53 )
F_16 ( V_53 ) ;
V_88:
F_67 ( V_9 ) ;
if ( V_155 )
F_63 ( V_155 , 0 ) ;
if ( V_53 )
F_65 ( V_53 ) ;
return V_84 ;
}
static int F_141 ( struct V_82 * V_164 , struct V_82 * V_165 )
{
struct V_13 * V_166 = V_164 -> V_14 , * V_9 = V_165 -> V_14 ;
F_15 ( V_166 ) ;
F_15 ( V_9 ) ;
F_9 ( V_166 ) = V_9 ;
F_9 ( V_9 ) = V_166 ;
F_70 ( V_166 ) ;
F_70 ( V_9 ) ;
if ( V_166 -> V_70 != V_112 ) {
V_166 -> V_68 = V_159 ;
V_9 -> V_68 = V_159 ;
V_164 -> V_64 = V_162 ;
V_165 -> V_64 = V_162 ;
}
return 0 ;
}
static void F_142 ( const struct V_82 * V_167 ,
struct V_82 * V_168 )
{
if ( F_123 ( V_145 , & V_167 -> V_142 ) )
F_143 ( V_145 , & V_168 -> V_142 ) ;
if ( F_123 ( V_169 , & V_167 -> V_142 ) )
F_143 ( V_169 , & V_168 -> V_142 ) ;
}
static int F_144 ( struct V_82 * V_13 , struct V_82 * V_170 , int V_142 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_171 ;
struct V_8 * V_9 ;
int V_84 ;
V_84 = - V_87 ;
if ( V_13 -> type != V_71 && V_13 -> type != V_72 )
goto V_88;
V_84 = - V_26 ;
if ( V_14 -> V_68 != V_76 )
goto V_88;
V_9 = F_145 ( V_14 , 0 , V_142 & V_157 , & V_84 ) ;
if ( ! V_9 ) {
if ( V_84 == 0 )
V_84 = - V_26 ;
goto V_88;
}
V_171 = V_9 -> V_14 ;
F_146 ( V_14 , V_9 ) ;
F_147 ( & F_34 ( V_14 ) -> V_54 ) ;
F_14 ( V_171 ) ;
V_170 -> V_64 = V_162 ;
F_142 ( V_13 , V_170 ) ;
F_148 ( V_171 , V_170 ) ;
F_16 ( V_171 ) ;
return 0 ;
V_88:
return V_84 ;
}
static int F_149 ( struct V_82 * V_13 , struct V_131 * V_132 , int * V_172 , int V_19 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 ;
F_150 ( struct V_22 * , V_23 , V_132 ) ;
int V_84 = 0 ;
if ( V_19 ) {
V_14 = F_13 ( V_14 ) ;
V_84 = - V_173 ;
if ( ! V_14 )
goto V_88;
V_84 = 0 ;
} else {
F_15 ( V_14 ) ;
}
V_35 = F_34 ( V_14 ) ;
F_14 ( V_14 ) ;
if ( ! V_35 -> V_2 ) {
V_23 -> V_27 = V_28 ;
V_23 -> V_29 [ 0 ] = 0 ;
* V_172 = sizeof( short ) ;
} else {
struct V_20 * V_2 = V_35 -> V_2 ;
* V_172 = V_2 -> V_24 ;
memcpy ( V_23 , V_2 -> V_36 , * V_172 ) ;
}
F_16 ( V_14 ) ;
F_65 ( V_14 ) ;
V_88:
return V_84 ;
}
static void F_151 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_39 ;
V_7 -> V_174 = F_3 ( V_9 ) . V_174 ;
F_3 ( V_9 ) . V_174 = NULL ;
for ( V_39 = V_7 -> V_174 -> V_175 - 1 ; V_39 >= 0 ; V_39 -- )
F_152 ( V_7 -> V_174 -> V_174 [ V_39 ] ) ;
}
static void F_153 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_85 = F_3 ( V_9 ) . V_85 ;
if ( F_3 ( V_9 ) . V_174 )
F_151 ( & V_7 , V_9 ) ;
F_154 ( & V_7 ) ;
F_155 ( V_9 ) ;
}
static int F_156 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_39 ;
unsigned char V_176 = 0 ;
int V_177 = 0 ;
for ( V_39 = V_7 -> V_174 -> V_175 - 1 ; V_39 >= 0 ; V_39 -- ) {
struct V_13 * V_14 = F_157 ( V_7 -> V_174 -> V_174 [ V_39 ] ) ;
if ( V_14 ) {
V_177 ++ ;
V_176 = F_158 ( V_176 ,
F_34 ( V_14 ) -> V_178 ) ;
}
}
if ( F_119 ( V_176 > V_179 ) )
return - V_180 ;
F_3 ( V_9 ) . V_174 = F_159 ( V_7 -> V_174 ) ;
if ( ! F_3 ( V_9 ) . V_174 )
return - V_116 ;
if ( V_177 ) {
for ( V_39 = V_7 -> V_174 -> V_175 - 1 ; V_39 >= 0 ; V_39 -- )
F_160 ( V_7 -> V_174 -> V_174 [ V_39 ] ) ;
}
return V_176 ;
}
static int F_161 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_181 )
{
int V_84 = 0 ;
F_3 ( V_9 ) . V_85 = F_73 ( V_7 -> V_85 ) ;
F_3 ( V_9 ) . V_182 = V_7 -> V_183 . V_182 ;
F_3 ( V_9 ) . V_184 = V_7 -> V_183 . V_184 ;
F_3 ( V_9 ) . V_174 = NULL ;
F_2 ( V_7 , V_9 ) ;
if ( V_7 -> V_174 && V_181 )
V_84 = F_156 ( V_7 , V_9 ) ;
V_9 -> V_185 = F_153 ;
return V_84 ;
}
static void F_162 ( struct V_8 * V_9 , const struct V_82 * V_13 ,
const struct V_13 * V_53 )
{
if ( F_3 ( V_9 ) . V_85 )
return;
if ( F_123 ( V_145 , & V_13 -> V_142 ) ||
! V_53 -> V_59 ||
F_123 ( V_145 , & V_53 -> V_59 -> V_142 ) ) {
F_3 ( V_9 ) . V_85 = F_73 ( F_74 ( V_80 ) ) ;
F_163 ( & F_3 ( V_9 ) . V_182 , & F_3 ( V_9 ) . V_184 ) ;
}
}
static int F_164 ( struct V_82 * V_13 , struct V_186 * V_187 ,
T_4 V_24 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_150 ( struct V_22 * , V_23 , V_187 -> V_188 ) ;
struct V_13 * V_53 = NULL ;
int V_189 = 0 ;
int V_84 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_149 ;
struct V_6 V_7 ;
int V_176 ;
int V_190 = 0 ;
F_165 () ;
V_84 = F_166 ( V_13 , V_187 , & V_7 , false ) ;
if ( V_84 < 0 )
return V_84 ;
V_84 = - V_87 ;
if ( V_187 -> V_191 & V_192 )
goto V_88;
if ( V_187 -> V_193 ) {
V_84 = F_20 ( V_23 , V_187 -> V_193 , & V_3 ) ;
if ( V_84 < 0 )
goto V_88;
V_189 = V_84 ;
} else {
V_23 = NULL ;
V_84 = - V_173 ;
V_53 = F_13 ( V_14 ) ;
if ( ! V_53 )
goto V_88;
}
if ( F_123 ( V_145 , & V_13 -> V_142 ) && ! V_35 -> V_2
&& ( V_84 = F_95 ( V_13 ) ) != 0 )
goto V_88;
V_84 = - V_194 ;
if ( V_24 > V_14 -> V_43 - 32 )
goto V_88;
if ( V_24 > V_195 ) {
V_190 = F_167 ( T_4 ,
V_24 - V_195 ,
V_196 * V_197 ) ;
V_190 = F_168 ( V_190 ) ;
F_169 ( V_195 < V_197 ) ;
}
V_9 = F_170 ( V_14 , V_24 - V_190 , V_190 ,
V_187 -> V_191 & V_198 , & V_84 ,
V_199 ) ;
if ( V_9 == NULL )
goto V_88;
V_84 = F_161 ( & V_7 , V_9 , true ) ;
if ( V_84 < 0 )
goto V_200;
V_176 = V_84 + 1 ;
F_171 ( V_9 , V_24 - V_190 ) ;
V_9 -> V_190 = V_190 ;
V_9 -> V_24 = V_24 ;
V_84 = F_172 ( V_9 , 0 , & V_187 -> V_201 , V_24 ) ;
if ( V_84 )
goto V_200;
V_149 = F_131 ( V_14 , V_187 -> V_191 & V_198 ) ;
V_146:
if ( ! V_53 ) {
V_84 = - V_57 ;
if ( V_23 == NULL )
goto V_200;
V_53 = F_99 ( V_32 , V_23 , V_189 , V_14 -> V_70 ,
V_3 , & V_84 ) ;
if ( V_53 == NULL )
goto V_200;
}
if ( F_173 ( V_53 , V_9 ) < 0 ) {
V_84 = V_24 ;
goto V_200;
}
F_14 ( V_53 ) ;
V_84 = - V_147 ;
if ( ! F_10 ( V_14 , V_53 ) )
goto V_89;
if ( F_53 ( V_53 , V_55 ) ) {
F_16 ( V_53 ) ;
F_65 ( V_53 ) ;
V_84 = 0 ;
F_14 ( V_14 ) ;
if ( F_9 ( V_14 ) == V_53 ) {
F_9 ( V_14 ) = NULL ;
F_16 ( V_14 ) ;
F_49 ( V_14 , V_53 ) ;
F_65 ( V_53 ) ;
V_84 = - V_125 ;
} else {
F_16 ( V_14 ) ;
}
V_53 = NULL ;
if ( V_84 )
goto V_200;
goto V_146;
}
V_84 = - V_202 ;
if ( V_53 -> V_65 & V_152 )
goto V_89;
if ( V_14 -> V_70 != V_72 ) {
V_84 = F_124 ( V_14 -> V_59 , V_53 -> V_59 ) ;
if ( V_84 )
goto V_89;
}
if ( F_9 ( V_53 ) != V_14 && F_11 ( V_53 ) ) {
if ( ! V_149 ) {
V_84 = - V_158 ;
goto V_89;
}
V_149 = F_125 ( V_53 , V_149 ) ;
V_84 = F_133 ( V_149 ) ;
if ( F_134 ( V_80 ) )
goto V_200;
goto V_146;
}
if ( F_53 ( V_53 , V_203 ) )
F_174 ( V_9 ) ;
F_162 ( V_9 , V_13 , V_53 ) ;
F_175 ( & V_53 -> V_16 , V_9 ) ;
if ( V_176 > F_34 ( V_53 ) -> V_178 )
F_34 ( V_53 ) -> V_178 = V_176 ;
F_16 ( V_53 ) ;
V_53 -> V_163 ( V_53 ) ;
F_65 ( V_53 ) ;
F_154 ( & V_7 ) ;
return V_24 ;
V_89:
F_16 ( V_53 ) ;
V_200:
F_67 ( V_9 ) ;
V_88:
if ( V_53 )
F_65 ( V_53 ) ;
F_154 ( & V_7 ) ;
return V_84 ;
}
static int F_176 ( struct V_82 * V_13 , struct V_186 * V_187 ,
T_4 V_24 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_53 = NULL ;
int V_84 , V_204 ;
struct V_8 * V_9 ;
int V_205 = 0 ;
struct V_6 V_7 ;
bool V_206 = false ;
int V_176 ;
int V_190 ;
F_165 () ;
V_84 = F_166 ( V_13 , V_187 , & V_7 , false ) ;
if ( V_84 < 0 )
return V_84 ;
V_84 = - V_87 ;
if ( V_187 -> V_191 & V_192 )
goto V_207;
if ( V_187 -> V_193 ) {
V_84 = V_14 -> V_68 == V_159 ? - V_160 : - V_87 ;
goto V_207;
} else {
V_84 = - V_173 ;
V_53 = F_9 ( V_14 ) ;
if ( ! V_53 )
goto V_207;
}
if ( V_14 -> V_65 & V_208 )
goto V_209;
while ( V_205 < V_24 ) {
V_204 = V_24 - V_205 ;
V_204 = F_167 ( int , V_204 , ( V_14 -> V_43 >> 1 ) - 64 ) ;
V_204 = F_167 ( int , V_204 , F_177 ( 0 ) + V_210 ) ;
V_190 = F_178 ( int , 0 , V_204 - F_177 ( 0 ) ) ;
V_190 = F_167 ( T_4 , V_204 , F_168 ( V_190 ) ) ;
V_9 = F_170 ( V_14 , V_204 - V_190 , V_190 ,
V_187 -> V_191 & V_198 , & V_84 ,
F_179 ( V_210 ) ) ;
if ( ! V_9 )
goto V_207;
V_84 = F_161 ( & V_7 , V_9 , ! V_206 ) ;
if ( V_84 < 0 ) {
F_67 ( V_9 ) ;
goto V_207;
}
V_176 = V_84 + 1 ;
V_206 = true ;
F_171 ( V_9 , V_204 - V_190 ) ;
V_9 -> V_190 = V_190 ;
V_9 -> V_24 = V_204 ;
V_84 = F_172 ( V_9 , 0 , & V_187 -> V_201 , V_204 ) ;
if ( V_84 ) {
F_67 ( V_9 ) ;
goto V_207;
}
F_14 ( V_53 ) ;
if ( F_53 ( V_53 , V_55 ) ||
( V_53 -> V_65 & V_152 ) )
goto V_211;
F_162 ( V_9 , V_13 , V_53 ) ;
F_175 ( & V_53 -> V_16 , V_9 ) ;
if ( V_176 > F_34 ( V_53 ) -> V_178 )
F_34 ( V_53 ) -> V_178 = V_176 ;
F_16 ( V_53 ) ;
V_53 -> V_163 ( V_53 ) ;
V_205 += V_204 ;
}
F_154 ( & V_7 ) ;
return V_205 ;
V_211:
F_16 ( V_53 ) ;
F_67 ( V_9 ) ;
V_209:
if ( V_205 == 0 && ! ( V_187 -> V_191 & V_212 ) )
F_180 ( V_213 , V_80 , 0 ) ;
V_84 = - V_202 ;
V_207:
F_154 ( & V_7 ) ;
return V_205 ? : V_84 ;
}
static T_5 F_181 ( struct V_82 * V_82 , struct V_214 * V_214 ,
int V_215 , T_4 V_204 , int V_142 )
{
int V_84 = 0 ;
bool V_216 = true ;
struct V_13 * V_53 , * V_14 = V_82 -> V_14 ;
struct V_8 * V_9 , * V_217 = NULL , * V_218 = NULL ;
if ( V_142 & V_192 )
return - V_87 ;
V_53 = F_9 ( V_14 ) ;
if ( ! V_53 || V_14 -> V_68 != V_159 )
return - V_173 ;
if ( false ) {
V_219:
F_16 ( V_53 ) ;
F_81 ( & F_34 ( V_53 ) -> V_91 ) ;
V_217 = F_170 ( V_14 , 0 , 0 , V_142 & V_198 ,
& V_84 , 0 ) ;
if ( ! V_217 )
return V_84 ;
}
V_84 = F_80 ( & F_34 ( V_53 ) -> V_91 ) ;
if ( V_84 ) {
V_84 = V_142 & V_198 ? - V_158 : - V_220 ;
V_216 = false ;
goto V_84;
}
if ( V_14 -> V_65 & V_208 ) {
V_84 = - V_202 ;
goto V_221;
}
F_14 ( V_53 ) ;
if ( F_53 ( V_53 , V_55 ) ||
V_53 -> V_65 & V_152 ) {
V_84 = - V_202 ;
goto V_222;
}
V_9 = F_182 ( & V_53 -> V_16 ) ;
if ( V_218 && V_218 == V_9 ) {
V_9 = V_217 ;
} else if ( ! V_9 ) {
if ( V_217 )
V_9 = V_217 ;
else
goto V_219;
} else if ( V_217 ) {
F_183 ( V_217 ) ;
}
if ( F_184 ( V_9 , V_214 , V_215 , V_204 ) ) {
V_218 = V_9 ;
goto V_219;
}
V_9 -> V_24 += V_204 ;
V_9 -> V_190 += V_204 ;
V_9 -> V_223 += V_204 ;
F_185 ( V_204 , & V_14 -> V_42 ) ;
if ( V_217 )
F_140 ( & V_53 -> V_16 , V_217 ) ;
F_16 ( V_53 ) ;
F_81 ( & F_34 ( V_53 ) -> V_91 ) ;
V_53 -> V_163 ( V_53 ) ;
return V_204 ;
V_222:
F_16 ( V_53 ) ;
V_221:
F_81 ( & F_34 ( V_53 ) -> V_91 ) ;
V_84:
F_67 ( V_217 ) ;
if ( V_216 && ! ( V_142 & V_212 ) )
F_180 ( V_213 , V_80 , 0 ) ;
return V_84 ;
}
static int F_186 ( struct V_82 * V_13 , struct V_186 * V_187 ,
T_4 V_24 )
{
int V_84 ;
struct V_13 * V_14 = V_13 -> V_14 ;
V_84 = F_187 ( V_14 ) ;
if ( V_84 )
return V_84 ;
if ( V_14 -> V_68 != V_159 )
return - V_173 ;
if ( V_187 -> V_193 )
V_187 -> V_193 = 0 ;
return F_164 ( V_13 , V_187 , V_24 ) ;
}
static int F_188 ( struct V_82 * V_13 , struct V_186 * V_187 ,
T_4 V_204 , int V_142 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
if ( V_14 -> V_68 != V_159 )
return - V_173 ;
return F_189 ( V_13 , V_187 , V_204 , V_142 ) ;
}
static void F_190 ( struct V_186 * V_187 , struct V_13 * V_14 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
if ( V_35 -> V_2 ) {
V_187 -> V_193 = V_35 -> V_2 -> V_24 ;
memcpy ( V_187 -> V_188 , V_35 -> V_2 -> V_36 , V_35 -> V_2 -> V_24 ) ;
}
}
static int F_189 ( struct V_82 * V_13 , struct V_186 * V_187 ,
T_4 V_204 , int V_142 )
{
struct V_6 V_7 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
int V_224 = V_142 & V_198 ;
struct V_8 * V_9 ;
int V_84 ;
int V_225 , V_226 ;
V_84 = - V_87 ;
if ( V_142 & V_192 )
goto V_88;
V_84 = F_80 ( & V_35 -> V_91 ) ;
if ( F_119 ( V_84 ) ) {
V_84 = V_224 ? - V_158 : - V_220 ;
goto V_88;
}
V_226 = F_191 ( V_14 , V_142 ) ;
V_9 = F_192 ( V_14 , V_142 , & V_225 , & V_226 , & V_84 ) ;
if ( ! V_9 ) {
F_14 ( V_14 ) ;
if ( V_14 -> V_70 == V_72 && V_84 == - V_158 &&
( V_14 -> V_65 & V_152 ) )
V_84 = 0 ;
F_16 ( V_14 ) ;
goto V_89;
}
F_46 ( & V_35 -> V_54 ,
V_48 | V_49 | V_50 ) ;
if ( V_187 -> V_188 )
F_190 ( V_187 , V_9 -> V_14 ) ;
if ( V_204 > V_9 -> V_24 - V_226 )
V_204 = V_9 -> V_24 - V_226 ;
else if ( V_204 < V_9 -> V_24 - V_226 )
V_187 -> V_191 |= V_227 ;
V_84 = F_193 ( V_9 , V_226 , V_187 , V_204 ) ;
if ( V_84 )
goto V_200;
if ( F_53 ( V_14 , V_203 ) )
F_194 ( V_187 , V_14 , V_9 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_195 ( & V_7 , F_3 ( V_9 ) . V_85 , F_3 ( V_9 ) . V_182 , F_3 ( V_9 ) . V_184 ) ;
F_4 ( & V_7 , V_9 ) ;
if ( ! ( V_142 & V_228 ) ) {
if ( F_3 ( V_9 ) . V_174 )
F_151 ( & V_7 , V_9 ) ;
F_196 ( V_14 , V_9 -> V_24 ) ;
} else {
F_197 ( V_14 , V_204 ) ;
if ( F_3 ( V_9 ) . V_174 )
V_7 . V_174 = F_159 ( F_3 ( V_9 ) . V_174 ) ;
}
V_84 = ( V_142 & V_227 ) ? V_9 -> V_24 - V_226 : V_204 ;
F_198 ( V_13 , V_187 , & V_7 , V_142 ) ;
V_200:
F_146 ( V_14 , V_9 ) ;
V_89:
F_81 ( & V_35 -> V_91 ) ;
V_88:
return V_84 ;
}
static long F_199 ( struct V_13 * V_14 , long V_149 ,
struct V_8 * V_229 , unsigned int V_230 )
{
struct V_8 * V_218 ;
F_126 ( V_47 ) ;
F_14 ( V_14 ) ;
for (; ; ) {
F_200 ( F_201 ( V_14 ) , & V_47 , V_151 ) ;
V_218 = F_182 ( & V_14 -> V_16 ) ;
if ( V_218 != V_229 ||
( V_218 && V_218 -> V_24 != V_230 ) ||
V_14 -> V_56 ||
( V_14 -> V_65 & V_152 ) ||
F_134 ( V_80 ) ||
! V_149 )
break;
F_143 ( V_231 , & V_14 -> V_59 -> V_142 ) ;
F_16 ( V_14 ) ;
V_149 = F_202 ( V_149 ) ;
F_14 ( V_14 ) ;
if ( F_53 ( V_14 , V_55 ) )
break;
F_203 ( V_231 , & V_14 -> V_59 -> V_142 ) ;
}
F_129 ( F_201 ( V_14 ) , & V_47 ) ;
F_16 ( V_14 ) ;
return V_149 ;
}
static unsigned int F_204 ( const struct V_8 * V_9 )
{
return V_9 -> V_24 - F_3 ( V_9 ) . V_232 ;
}
static int F_205 ( struct V_233 * V_64 )
{
struct V_6 V_7 ;
struct V_82 * V_13 = V_64 -> V_82 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
int V_234 = 0 ;
int V_142 = V_64 -> V_142 ;
int V_224 = V_142 & V_198 ;
bool V_235 = false ;
int V_236 ;
int V_84 = 0 ;
long V_149 ;
int V_226 ;
T_4 V_204 = V_64 -> V_204 ;
unsigned int V_230 ;
V_84 = - V_26 ;
if ( V_14 -> V_68 != V_159 )
goto V_88;
V_84 = - V_87 ;
if ( V_142 & V_192 )
goto V_88;
V_236 = F_206 ( V_14 , V_142 & V_237 , V_204 ) ;
V_149 = F_207 ( V_14 , V_224 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_84 = F_80 ( & V_35 -> V_91 ) ;
if ( F_119 ( V_84 ) ) {
V_84 = V_224 ? - V_158 : - V_220 ;
goto V_88;
}
do {
int V_238 ;
struct V_8 * V_9 , * V_229 ;
F_14 ( V_14 ) ;
if ( F_53 ( V_14 , V_55 ) ) {
V_84 = - V_57 ;
goto V_239;
}
V_229 = V_9 = F_208 ( & V_14 -> V_16 ) ;
V_230 = V_229 ? V_229 -> V_24 : 0 ;
V_240:
if ( V_9 == NULL ) {
F_34 ( V_14 ) -> V_178 = 0 ;
if ( V_234 >= V_236 )
goto V_239;
V_84 = F_187 ( V_14 ) ;
if ( V_84 )
goto V_239;
if ( V_14 -> V_65 & V_152 )
goto V_239;
F_16 ( V_14 ) ;
V_84 = - V_158 ;
if ( ! V_149 )
break;
F_81 ( & V_35 -> V_91 ) ;
V_149 = F_199 ( V_14 , V_149 , V_229 ,
V_230 ) ;
if ( F_134 ( V_80 ) ||
F_80 ( & V_35 -> V_91 ) ) {
V_84 = F_133 ( V_149 ) ;
goto V_88;
}
continue;
V_239:
F_16 ( V_14 ) ;
break;
}
V_226 = F_191 ( V_14 , V_142 ) ;
while ( V_226 >= F_204 ( V_9 ) ) {
V_226 -= F_204 ( V_9 ) ;
V_229 = V_9 ;
V_230 = V_9 -> V_24 ;
V_9 = F_209 ( V_9 , & V_14 -> V_16 ) ;
if ( ! V_9 )
goto V_240;
}
F_16 ( V_14 ) ;
if ( V_235 ) {
if ( ( F_3 ( V_9 ) . V_85 != V_7 . V_85 ) ||
! F_210 ( F_3 ( V_9 ) . V_182 , V_7 . V_183 . V_182 ) ||
! F_211 ( F_3 ( V_9 ) . V_184 , V_7 . V_183 . V_184 ) ||
! F_5 ( & V_7 , V_9 ) )
break;
} else if ( F_123 ( V_145 , & V_13 -> V_142 ) ) {
F_195 ( & V_7 , F_3 ( V_9 ) . V_85 , F_3 ( V_9 ) . V_182 , F_3 ( V_9 ) . V_184 ) ;
F_4 ( & V_7 , V_9 ) ;
V_235 = true ;
}
if ( V_64 -> V_187 && V_64 -> V_187 -> V_188 ) {
F_150 ( struct V_22 * , V_23 ,
V_64 -> V_187 -> V_188 ) ;
F_190 ( V_64 -> V_187 , V_9 -> V_14 ) ;
V_23 = NULL ;
}
V_238 = F_167 (unsigned int, unix_skb_len(skb) - skip, size) ;
V_238 = V_64 -> V_241 ( V_9 , V_226 , V_238 , V_64 ) ;
if ( V_238 < 0 ) {
if ( V_234 == 0 )
V_234 = - V_242 ;
break;
}
V_234 += V_238 ;
V_204 -= V_238 ;
if ( ! ( V_142 & V_228 ) ) {
F_3 ( V_9 ) . V_232 += V_238 ;
F_196 ( V_14 , V_238 ) ;
if ( F_3 ( V_9 ) . V_174 )
F_151 ( & V_7 , V_9 ) ;
if ( F_204 ( V_9 ) )
break;
F_212 ( V_9 , & V_14 -> V_16 ) ;
F_183 ( V_9 ) ;
if ( V_7 . V_174 )
break;
} else {
if ( F_3 ( V_9 ) . V_174 )
V_7 . V_174 = F_159 ( F_3 ( V_9 ) . V_174 ) ;
F_197 ( V_14 , V_238 ) ;
break;
}
} while ( V_204 );
F_81 ( & V_35 -> V_91 ) ;
if ( V_64 -> V_187 )
F_198 ( V_13 , V_64 -> V_187 , & V_7 , V_142 ) ;
else
F_154 ( & V_7 ) ;
V_88:
return V_234 ? : V_84 ;
}
static int F_213 ( struct V_8 * V_9 ,
int V_226 , int V_238 ,
struct V_233 * V_64 )
{
int V_243 ;
V_243 = F_193 ( V_9 , F_3 ( V_9 ) . V_232 + V_226 ,
V_64 -> V_187 , V_238 ) ;
return V_243 ? : V_238 ;
}
static int F_214 ( struct V_82 * V_13 , struct V_186 * V_187 ,
T_4 V_204 , int V_142 )
{
struct V_233 V_64 = {
. V_241 = F_213 ,
. V_82 = V_13 ,
. V_187 = V_187 ,
. V_204 = V_204 ,
. V_142 = V_142
} ;
return F_205 ( & V_64 ) ;
}
static T_5 F_215 ( struct V_13 * V_14 ,
struct V_244 * V_245 ,
struct V_246 * V_247 )
{
int V_243 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_81 ( & V_35 -> V_91 ) ;
V_243 = F_216 ( V_245 , V_247 ) ;
F_217 ( & V_35 -> V_91 ) ;
return V_243 ;
}
static int F_218 ( struct V_8 * V_9 ,
int V_226 , int V_238 ,
struct V_233 * V_64 )
{
return F_219 ( V_9 , V_64 -> V_82 -> V_14 ,
F_3 ( V_9 ) . V_232 + V_226 ,
V_64 -> V_245 , V_238 , V_64 -> V_248 ,
F_215 ) ;
}
static T_5 F_220 ( struct V_82 * V_13 , T_6 * V_249 ,
struct V_244 * V_245 ,
T_4 V_204 , unsigned int V_142 )
{
struct V_233 V_64 = {
. V_241 = F_218 ,
. V_82 = V_13 ,
. V_245 = V_245 ,
. V_204 = V_204 ,
. V_248 = V_142 ,
} ;
if ( F_119 ( * V_249 ) )
return - V_250 ;
if ( V_13 -> V_251 -> V_252 & V_157 ||
V_142 & V_253 )
V_64 . V_142 = V_198 ;
return F_205 ( & V_64 ) ;
}
static int F_221 ( struct V_82 * V_13 , int V_128 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_53 ;
if ( V_128 < V_254 || V_128 > V_255 )
return - V_26 ;
++ V_128 ;
F_14 ( V_14 ) ;
V_14 -> V_65 |= V_128 ;
V_53 = F_9 ( V_14 ) ;
if ( V_53 )
F_15 ( V_53 ) ;
F_16 ( V_14 ) ;
V_14 -> V_73 ( V_14 ) ;
if ( V_53 &&
( V_14 -> V_70 == V_71 || V_14 -> V_70 == V_72 ) ) {
int V_256 = 0 ;
if ( V_128 & V_152 )
V_256 |= V_208 ;
if ( V_128 & V_208 )
V_256 |= V_152 ;
F_14 ( V_53 ) ;
V_53 -> V_65 |= V_256 ;
F_16 ( V_53 ) ;
V_53 -> V_73 ( V_53 ) ;
if ( V_256 == V_66 )
F_47 ( V_53 , V_74 , V_75 ) ;
else if ( V_256 & V_152 )
F_47 ( V_53 , V_74 , V_257 ) ;
}
if ( V_53 )
F_65 ( V_53 ) ;
return 0 ;
}
long F_222 ( struct V_13 * V_14 )
{
struct V_8 * V_9 ;
long V_258 = 0 ;
if ( V_14 -> V_68 == V_76 )
return - V_26 ;
F_29 ( & V_14 -> V_16 . V_98 ) ;
if ( V_14 -> V_70 == V_71 ||
V_14 -> V_70 == V_72 ) {
F_223 (&sk->sk_receive_queue, skb)
V_258 += F_204 ( V_9 ) ;
} else {
V_9 = F_208 ( & V_14 -> V_16 ) ;
if ( V_9 )
V_258 = V_9 -> V_24 ;
}
F_30 ( & V_14 -> V_16 . V_98 ) ;
return V_258 ;
}
long F_224 ( struct V_13 * V_14 )
{
return F_225 ( V_14 ) ;
}
static int F_226 ( struct V_82 * V_13 , unsigned int V_259 , unsigned long V_260 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
long V_258 = 0 ;
int V_84 ;
switch ( V_259 ) {
case V_261 :
V_258 = F_224 ( V_14 ) ;
V_84 = F_227 ( V_258 , ( int V_262 * ) V_260 ) ;
break;
case V_263 :
V_258 = F_222 ( V_14 ) ;
if ( V_258 < 0 )
V_84 = V_258 ;
else
V_84 = F_227 ( V_258 , ( int V_262 * ) V_260 ) ;
break;
default:
V_84 = - V_264 ;
break;
}
return V_84 ;
}
static unsigned int F_228 ( struct V_251 * V_251 , struct V_82 * V_13 , T_7 * V_47 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
unsigned int V_265 ;
F_229 ( V_251 , F_201 ( V_14 ) , V_47 ) ;
V_265 = 0 ;
if ( V_14 -> V_56 )
V_265 |= V_266 ;
if ( V_14 -> V_65 == V_66 )
V_265 |= V_267 ;
if ( V_14 -> V_65 & V_152 )
V_265 |= V_268 | V_269 | V_270 ;
if ( ! F_50 ( & V_14 -> V_16 ) )
V_265 |= V_269 | V_270 ;
if ( ( V_14 -> V_70 == V_71 || V_14 -> V_70 == V_72 ) &&
V_14 -> V_68 == V_69 )
V_265 |= V_267 ;
if ( F_40 ( V_14 ) )
V_265 |= V_48 | V_49 | V_50 ;
return V_265 ;
}
static unsigned int F_230 ( struct V_251 * V_251 , struct V_82 * V_13 ,
T_7 * V_47 )
{
struct V_13 * V_14 = V_13 -> V_14 , * V_53 ;
unsigned int V_265 , V_271 ;
F_229 ( V_251 , F_201 ( V_14 ) , V_47 ) ;
V_265 = 0 ;
if ( V_14 -> V_56 || ! F_50 ( & V_14 -> V_272 ) )
V_265 |= V_266 |
( F_53 ( V_14 , V_273 ) ? V_274 : 0 ) ;
if ( V_14 -> V_65 & V_152 )
V_265 |= V_268 | V_269 | V_270 ;
if ( V_14 -> V_65 == V_66 )
V_265 |= V_267 ;
if ( ! F_50 ( & V_14 -> V_16 ) )
V_265 |= V_269 | V_270 ;
if ( V_14 -> V_70 == V_72 ) {
if ( V_14 -> V_68 == V_69 )
V_265 |= V_267 ;
if ( V_14 -> V_68 == V_275 )
return V_265 ;
}
if ( ! ( F_231 ( V_47 ) & ( V_50 | V_49 | V_48 ) ) )
return V_265 ;
V_271 = F_40 ( V_14 ) ;
V_53 = F_13 ( V_14 ) ;
if ( V_53 ) {
if ( F_9 ( V_53 ) != V_14 ) {
F_229 ( V_251 , & F_34 ( V_53 ) -> V_54 , V_47 ) ;
if ( F_11 ( V_53 ) )
V_271 = 0 ;
}
F_65 ( V_53 ) ;
}
if ( V_271 )
V_265 |= V_48 | V_49 | V_50 ;
else
F_143 ( V_276 , & V_14 -> V_59 -> V_142 ) ;
return V_265 ;
}
static struct V_13 * F_232 ( struct V_277 * V_278 , T_6 * V_279 )
{
unsigned long V_215 = F_233 ( * V_279 ) ;
unsigned long V_280 = F_234 ( * V_279 ) ;
struct V_13 * V_14 ;
unsigned long V_175 = 0 ;
for ( V_14 = F_235 ( & V_5 [ V_280 ] ) ; V_14 ; V_14 = F_236 ( V_14 ) ) {
if ( F_36 ( V_14 ) != F_237 ( V_278 ) )
continue;
if ( ++ V_175 == V_215 )
break;
}
return V_14 ;
}
static struct V_13 * F_238 ( struct V_277 * V_278 ,
struct V_13 * V_14 ,
T_6 * V_279 )
{
unsigned long V_280 ;
while ( V_14 > (struct V_13 * ) V_281 ) {
V_14 = F_236 ( V_14 ) ;
if ( ! V_14 )
goto V_282;
if ( F_36 ( V_14 ) == F_237 ( V_278 ) )
return V_14 ;
}
do {
V_14 = F_232 ( V_278 , V_279 ) ;
if ( V_14 )
return V_14 ;
V_282:
V_280 = F_234 ( * V_279 ) + 1 ;
* V_279 = F_239 ( V_280 , 1 ) ;
} while ( V_280 < F_240 ( V_5 ) );
return NULL ;
}
static void * F_241 ( struct V_277 * V_278 , T_6 * V_279 )
__acquires( V_31 )
{
F_29 ( & V_31 ) ;
if ( ! * V_279 )
return V_281 ;
if ( F_234 ( * V_279 ) >= F_240 ( V_5 ) )
return NULL ;
return F_238 ( V_278 , NULL , V_279 ) ;
}
static void * F_242 ( struct V_277 * V_278 , void * V_283 , T_6 * V_279 )
{
++ * V_279 ;
return F_238 ( V_278 , V_283 , V_279 ) ;
}
static void F_243 ( struct V_277 * V_278 , void * V_283 )
__releases( V_31 )
{
F_30 ( & V_31 ) ;
}
static int F_244 ( struct V_277 * V_278 , void * V_283 )
{
if ( V_283 == V_281 )
F_245 ( V_278 , L_4
L_5 ) ;
else {
struct V_13 * V_18 = V_283 ;
struct V_34 * V_35 = F_34 ( V_18 ) ;
F_14 ( V_18 ) ;
F_246 ( V_278 , L_6 ,
V_18 ,
F_41 ( & V_18 -> V_284 ) ,
0 ,
V_18 -> V_68 == V_76 ? V_285 : 0 ,
V_18 -> V_70 ,
V_18 -> V_59 ?
( V_18 -> V_68 == V_159 ? V_162 : V_108 ) :
( V_18 -> V_68 == V_159 ? V_286 : V_287 ) ,
F_247 ( V_18 ) ) ;
if ( V_35 -> V_2 ) {
int V_39 , V_24 ;
F_248 ( V_278 , ' ' ) ;
V_39 = 0 ;
V_24 = V_35 -> V_2 -> V_24 - sizeof( short ) ;
if ( ! F_249 ( V_18 ) )
V_24 -- ;
else {
F_248 ( V_278 , '@' ) ;
V_39 ++ ;
}
for ( ; V_39 < V_24 ; V_39 ++ )
F_248 ( V_278 , V_35 -> V_2 -> V_36 -> V_29 [ V_39 ] ) ;
}
F_16 ( V_18 ) ;
F_248 ( V_278 , '\n' ) ;
}
return 0 ;
}
static int F_250 ( struct V_38 * V_38 , struct V_251 * V_251 )
{
return F_251 ( V_38 , V_251 , & V_288 ,
sizeof( struct V_289 ) ) ;
}
static int T_8 F_252 ( struct V_32 * V_32 )
{
int error = - V_116 ;
V_32 -> V_101 . V_102 = 10 ;
if ( F_253 ( V_32 ) )
goto V_88;
#ifdef F_254
if ( ! F_255 ( L_7 , 0 , V_32 -> V_290 , & V_291 ) ) {
F_256 ( V_32 ) ;
goto V_88;
}
#endif
error = 0 ;
V_88:
return error ;
}
static void T_9 F_257 ( struct V_32 * V_32 )
{
F_256 ( V_32 ) ;
F_258 ( L_7 , V_32 -> V_290 ) ;
}
static int T_10 F_259 ( void )
{
int V_292 = - 1 ;
F_169 ( sizeof( struct V_293 ) > F_260 ( struct V_8 , V_294 ) ) ;
V_292 = F_261 ( & V_97 , 1 ) ;
if ( V_292 != 0 ) {
F_262 ( L_8 , V_295 ) ;
goto V_88;
}
F_263 ( & V_296 ) ;
F_264 ( & V_297 ) ;
V_88:
return V_292 ;
}
static void T_11 F_265 ( void )
{
F_266 ( V_95 ) ;
F_267 ( & V_97 ) ;
F_268 ( & V_297 ) ;
}
