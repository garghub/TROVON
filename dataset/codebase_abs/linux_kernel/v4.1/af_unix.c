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
if ( V_41 && F_38 ( V_41 ) == V_40 ) {
F_14 ( V_19 ) ;
goto V_38;
}
}
V_19 = NULL ;
V_38:
F_29 ( & V_32 ) ;
return V_19 ;
}
static inline int F_39 ( struct V_14 * V_15 )
{
return ( F_40 ( & V_15 -> V_43 ) << 2 ) <= V_15 -> V_44 ;
}
static void F_41 ( struct V_14 * V_15 )
{
struct V_45 * V_46 ;
F_42 () ;
if ( F_39 ( V_15 ) ) {
V_46 = F_43 ( V_15 -> V_47 ) ;
if ( F_44 ( V_46 ) )
F_45 ( & V_46 -> V_48 ,
V_49 | V_50 | V_51 ) ;
F_46 ( V_15 , V_52 , V_53 ) ;
}
F_47 () ;
}
static void F_48 ( struct V_14 * V_15 , struct V_14 * V_54 )
{
if ( ! F_49 ( & V_15 -> V_17 ) ) {
F_50 ( & V_15 -> V_17 ) ;
F_51 ( & F_33 ( V_15 ) -> V_55 ) ;
if ( ! F_52 ( V_54 , V_56 ) && F_8 ( V_54 ) == V_15 ) {
V_54 -> V_57 = V_58 ;
V_54 -> V_59 ( V_54 ) ;
}
}
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
F_50 ( & V_15 -> V_17 ) ;
F_24 ( F_40 ( & V_15 -> V_43 ) ) ;
F_24 ( ! F_25 ( V_15 ) ) ;
F_24 ( V_15 -> V_60 ) ;
if ( ! F_52 ( V_15 , V_56 ) ) {
F_54 ( L_1 , V_15 ) ;
return;
}
if ( V_36 -> V_2 )
F_16 ( V_36 -> V_2 ) ;
F_55 ( & V_61 ) ;
F_56 () ;
F_57 ( F_35 ( V_15 ) , V_15 -> V_62 , - 1 ) ;
F_58 () ;
#ifdef F_59
F_60 ( L_2 , V_15 ,
F_61 ( & V_61 ) ) ;
#endif
}
static void F_62 ( struct V_14 * V_15 , int V_63 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
struct V_42 V_42 ;
struct V_14 * V_64 ;
struct V_8 * V_9 ;
int V_65 ;
F_27 ( V_15 ) ;
F_13 ( V_15 ) ;
F_63 ( V_15 ) ;
V_15 -> V_66 = V_67 ;
V_42 = V_36 -> V_42 ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_68 = NULL ;
V_65 = V_15 -> V_69 ;
V_15 -> V_69 = V_70 ;
F_15 ( V_15 ) ;
F_51 ( & V_36 -> V_55 ) ;
V_64 = F_8 ( V_15 ) ;
if ( V_64 != NULL ) {
if ( V_15 -> V_71 == V_72 || V_15 -> V_71 == V_73 ) {
F_13 ( V_64 ) ;
V_64 -> V_66 = V_67 ;
if ( ! F_49 ( & V_15 -> V_17 ) || V_63 )
V_64 -> V_57 = V_58 ;
F_15 ( V_64 ) ;
V_64 -> V_74 ( V_64 ) ;
F_46 ( V_64 , V_75 , V_76 ) ;
}
F_64 ( V_64 ) ;
F_8 ( V_15 ) = NULL ;
}
while ( ( V_9 = F_65 ( & V_15 -> V_17 ) ) != NULL ) {
if ( V_65 == V_77 )
F_62 ( V_9 -> V_15 , 1 ) ;
F_66 ( V_9 ) ;
}
if ( V_42 . V_41 )
F_67 ( & V_42 ) ;
F_64 ( V_15 ) ;
if ( V_78 )
F_68 () ;
}
static void F_69 ( struct V_14 * V_15 )
{
F_70 ( V_15 -> V_79 ) ;
if ( V_15 -> V_80 )
F_71 ( V_15 -> V_80 ) ;
V_15 -> V_79 = F_72 ( F_73 ( V_81 ) ) ;
V_15 -> V_80 = F_74 () ;
}
static void F_75 ( struct V_14 * V_15 , struct V_14 * V_82 )
{
F_70 ( V_15 -> V_79 ) ;
if ( V_15 -> V_80 )
F_71 ( V_15 -> V_80 ) ;
V_15 -> V_79 = F_72 ( V_82 -> V_79 ) ;
V_15 -> V_80 = F_76 ( V_82 -> V_80 ) ;
}
static int F_77 ( struct V_83 * V_14 , int V_84 )
{
int V_85 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
struct V_86 * V_87 = NULL ;
V_85 = - V_88 ;
if ( V_14 -> type != V_72 && V_14 -> type != V_73 )
goto V_89;
V_85 = - V_27 ;
if ( ! V_36 -> V_2 )
goto V_89;
F_13 ( V_15 ) ;
if ( V_15 -> V_69 != V_70 && V_15 -> V_69 != V_77 )
goto V_90;
if ( V_84 > V_15 -> V_18 )
F_51 ( & V_36 -> V_55 ) ;
V_15 -> V_18 = V_84 ;
V_15 -> V_69 = V_77 ;
F_69 ( V_15 ) ;
V_85 = 0 ;
V_90:
F_15 ( V_15 ) ;
F_70 ( V_87 ) ;
V_89:
return V_85 ;
}
static int F_78 ( struct V_14 * V_15 , int V_91 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
if ( F_79 ( & V_36 -> V_92 ) )
return - V_93 ;
V_15 -> V_94 = V_91 ;
F_80 ( & V_36 -> V_92 ) ;
return 0 ;
}
static struct V_14 * F_81 ( struct V_33 * V_33 , struct V_83 * V_14 )
{
struct V_14 * V_15 = NULL ;
struct V_35 * V_36 ;
F_82 ( & V_61 ) ;
if ( F_61 ( & V_61 ) > 2 * F_83 () )
goto V_89;
V_15 = F_84 ( V_33 , V_95 , V_96 , & V_97 ) ;
if ( ! V_15 )
goto V_89;
F_85 ( V_14 , V_15 ) ;
F_86 ( & V_15 -> V_17 . V_98 ,
& V_99 ) ;
V_15 -> V_100 = F_41 ;
V_15 -> V_18 = V_33 -> V_101 . V_102 ;
V_15 -> V_103 = F_53 ;
V_36 = F_33 ( V_15 ) ;
V_36 -> V_42 . V_41 = NULL ;
V_36 -> V_42 . V_68 = NULL ;
F_87 ( & V_36 -> V_98 ) ;
F_88 ( & V_36 -> V_104 , 0 ) ;
F_89 ( & V_36 -> V_105 ) ;
F_90 ( & V_36 -> V_92 ) ;
F_91 ( & V_36 -> V_55 ) ;
F_30 ( F_1 ( V_15 ) , V_15 ) ;
V_89:
if ( V_15 == NULL )
F_55 ( & V_61 ) ;
else {
F_56 () ;
F_57 ( F_35 ( V_15 ) , V_15 -> V_62 , 1 ) ;
F_58 () ;
}
return V_15 ;
}
static int F_92 ( struct V_33 * V_33 , struct V_83 * V_14 , int V_106 ,
int V_107 )
{
if ( V_106 && V_106 != V_95 )
return - V_108 ;
V_14 -> V_65 = V_109 ;
switch ( V_14 -> type ) {
case V_72 :
V_14 -> V_110 = & V_111 ;
break;
case V_112 :
V_14 -> type = V_113 ;
case V_113 :
V_14 -> V_110 = & V_114 ;
break;
case V_73 :
V_14 -> V_110 = & V_115 ;
break;
default:
return - V_116 ;
}
return F_81 ( V_33 , V_14 ) ? 0 : - V_117 ;
}
static int F_93 ( struct V_83 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( ! V_15 )
return 0 ;
F_62 ( V_15 , 0 ) ;
V_14 -> V_15 = NULL ;
return 0 ;
}
static int F_94 ( struct V_83 * V_14 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
static V_11 V_118 = 1 ;
struct V_21 * V_2 ;
int V_85 ;
unsigned int V_119 = 0 ;
V_85 = F_79 ( & V_36 -> V_92 ) ;
if ( V_85 )
return V_85 ;
V_85 = 0 ;
if ( V_36 -> V_2 )
goto V_89;
V_85 = - V_117 ;
V_2 = F_95 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_96 ) ;
if ( ! V_2 )
goto V_89;
V_2 -> V_37 -> V_28 = V_29 ;
F_96 ( & V_2 -> V_22 , 1 ) ;
V_120:
V_2 -> V_25 = sprintf ( V_2 -> V_37 -> V_30 + 1 , L_3 , V_118 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_5 ( F_20 ( V_2 -> V_37 , V_2 -> V_25 , 0 ) ) ;
F_28 ( & V_32 ) ;
V_118 = ( V_118 + 1 ) & 0xFFFFF ;
if ( F_31 ( V_33 , V_2 -> V_37 , V_2 -> V_25 , V_14 -> type ,
V_2 -> V_3 ) ) {
F_29 ( & V_32 ) ;
F_97 () ;
if ( V_119 ++ == 0xFFFFF ) {
V_85 = - V_121 ;
F_18 ( V_2 ) ;
goto V_89;
}
goto V_120;
}
V_2 -> V_3 ^= V_15 -> V_71 ;
F_21 ( V_15 ) ;
V_36 -> V_2 = V_2 ;
F_23 ( & V_5 [ V_2 -> V_3 ] , V_15 ) ;
F_29 ( & V_32 ) ;
V_85 = 0 ;
V_89: F_80 ( & V_36 -> V_92 ) ;
return V_85 ;
}
static struct V_14 * F_98 ( struct V_33 * V_33 ,
struct V_23 * V_34 , int V_25 ,
int type , unsigned int V_3 , int * error )
{
struct V_14 * V_36 ;
struct V_42 V_42 ;
int V_85 = 0 ;
if ( V_34 -> V_30 [ 0 ] ) {
struct V_39 * V_39 ;
V_85 = F_99 ( V_34 -> V_30 , V_122 , & V_42 ) ;
if ( V_85 )
goto V_123;
V_39 = F_38 ( V_42 . V_41 ) ;
V_85 = F_100 ( V_39 , V_124 ) ;
if ( V_85 )
goto V_125;
V_85 = - V_126 ;
if ( ! F_101 ( V_39 -> V_127 ) )
goto V_125;
V_36 = F_37 ( V_39 ) ;
if ( ! V_36 )
goto V_125;
if ( V_36 -> V_71 == type )
F_102 ( & V_42 ) ;
F_67 ( & V_42 ) ;
V_85 = - V_128 ;
if ( V_36 -> V_71 != type ) {
F_64 ( V_36 ) ;
goto V_123;
}
} else {
V_85 = - V_126 ;
V_36 = F_36 ( V_33 , V_34 , V_25 , type , V_3 ) ;
if ( V_36 ) {
struct V_41 * V_41 ;
V_41 = F_33 ( V_36 ) -> V_42 . V_41 ;
if ( V_41 )
F_102 ( & F_33 ( V_36 ) -> V_42 ) ;
} else
goto V_123;
}
return V_36 ;
V_125:
F_67 ( & V_42 ) ;
V_123:
* error = V_85 ;
return NULL ;
}
static int F_103 ( const char * V_30 , T_2 V_129 , struct V_42 * V_130 )
{
struct V_41 * V_41 ;
struct V_42 V_42 ;
int V_85 = 0 ;
V_41 = F_104 ( V_131 , V_30 , & V_42 , 0 ) ;
V_85 = F_105 ( V_41 ) ;
if ( F_106 ( V_41 ) )
return V_85 ;
V_85 = F_107 ( & V_42 , V_41 , V_129 , 0 ) ;
if ( ! V_85 ) {
V_85 = F_108 ( F_109 ( V_42 . V_41 ) , V_41 , V_129 , 0 ) ;
if ( ! V_85 ) {
V_130 -> V_68 = F_110 ( V_42 . V_68 ) ;
V_130 -> V_41 = F_111 ( V_41 ) ;
}
}
F_112 ( & V_42 , V_41 ) ;
return V_85 ;
}
static int F_113 ( struct V_83 * V_14 , struct V_132 * V_133 , int V_134 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_133 ;
char * V_30 = V_24 -> V_30 ;
int V_85 ;
unsigned int V_3 ;
struct V_21 * V_2 ;
struct V_1 * V_31 ;
V_85 = - V_27 ;
if ( V_24 -> V_28 != V_29 )
goto V_89;
if ( V_134 == sizeof( short ) ) {
V_85 = F_94 ( V_14 ) ;
goto V_89;
}
V_85 = F_19 ( V_24 , V_134 , & V_3 ) ;
if ( V_85 < 0 )
goto V_89;
V_134 = V_85 ;
V_85 = F_79 ( & V_36 -> V_92 ) ;
if ( V_85 )
goto V_89;
V_85 = - V_27 ;
if ( V_36 -> V_2 )
goto V_135;
V_85 = - V_117 ;
V_2 = F_114 ( sizeof( * V_2 ) + V_134 , V_96 ) ;
if ( ! V_2 )
goto V_135;
memcpy ( V_2 -> V_37 , V_24 , V_134 ) ;
V_2 -> V_25 = V_134 ;
V_2 -> V_3 = V_3 ^ V_15 -> V_71 ;
F_96 ( & V_2 -> V_22 , 1 ) ;
if ( V_30 [ 0 ] ) {
struct V_42 V_42 ;
T_2 V_129 = V_136 |
( F_115 ( V_14 ) -> V_127 & ~ F_116 () ) ;
V_85 = F_103 ( V_30 , V_129 , & V_42 ) ;
if ( V_85 ) {
if ( V_85 == - V_137 )
V_85 = - V_138 ;
F_16 ( V_2 ) ;
goto V_135;
}
V_2 -> V_3 = V_4 ;
V_3 = F_38 ( V_42 . V_41 ) -> V_139 & ( V_4 - 1 ) ;
F_28 ( & V_32 ) ;
V_36 -> V_42 = V_42 ;
V_31 = & V_5 [ V_3 ] ;
} else {
F_28 ( & V_32 ) ;
V_85 = - V_138 ;
if ( F_31 ( V_33 , V_24 , V_134 ,
V_15 -> V_71 , V_3 ) ) {
F_16 ( V_2 ) ;
goto V_90;
}
V_31 = & V_5 [ V_2 -> V_3 ] ;
}
V_85 = 0 ;
F_21 ( V_15 ) ;
V_36 -> V_2 = V_2 ;
F_23 ( V_31 , V_15 ) ;
V_90:
F_29 ( & V_32 ) ;
V_135:
F_80 ( & V_36 -> V_92 ) ;
V_89:
return V_85 ;
}
static void F_117 ( struct V_14 * V_140 , struct V_14 * V_141 )
{
if ( F_118 ( V_140 == V_141 ) || ! V_141 ) {
F_13 ( V_140 ) ;
return;
}
if ( V_140 < V_141 ) {
F_13 ( V_140 ) ;
F_119 ( V_141 ) ;
} else {
F_13 ( V_141 ) ;
F_119 ( V_140 ) ;
}
}
static void F_120 ( struct V_14 * V_140 , struct V_14 * V_141 )
{
if ( F_118 ( V_140 == V_141 ) || ! V_141 ) {
F_15 ( V_140 ) ;
return;
}
F_15 ( V_140 ) ;
F_15 ( V_141 ) ;
}
static int F_121 ( struct V_83 * V_14 , struct V_132 * V_2 ,
int V_142 , int V_143 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_2 ;
struct V_14 * V_54 ;
unsigned int V_3 ;
int V_85 ;
if ( V_2 -> V_144 != V_145 ) {
V_85 = F_19 ( V_24 , V_142 , & V_3 ) ;
if ( V_85 < 0 )
goto V_89;
V_142 = V_85 ;
if ( F_122 ( V_146 , & V_14 -> V_143 ) &&
! F_33 ( V_15 ) -> V_2 && ( V_85 = F_94 ( V_14 ) ) != 0 )
goto V_89;
V_147:
V_54 = F_98 ( V_33 , V_24 , V_142 , V_14 -> type , V_3 , & V_85 ) ;
if ( ! V_54 )
goto V_89;
F_117 ( V_15 , V_54 ) ;
if ( F_52 ( V_54 , V_56 ) ) {
F_120 ( V_15 , V_54 ) ;
F_64 ( V_54 ) ;
goto V_147;
}
V_85 = - V_148 ;
if ( ! F_9 ( V_15 , V_54 ) )
goto V_90;
V_85 = F_123 ( V_15 -> V_60 , V_54 -> V_60 ) ;
if ( V_85 )
goto V_90;
} else {
V_54 = NULL ;
F_117 ( V_15 , V_54 ) ;
}
if ( F_8 ( V_15 ) ) {
struct V_14 * V_149 = F_8 ( V_15 ) ;
F_8 ( V_15 ) = V_54 ;
F_120 ( V_15 , V_54 ) ;
if ( V_54 != V_149 )
F_48 ( V_15 , V_149 ) ;
F_64 ( V_149 ) ;
} else {
F_8 ( V_15 ) = V_54 ;
F_120 ( V_15 , V_54 ) ;
}
return 0 ;
V_90:
F_120 ( V_15 , V_54 ) ;
F_64 ( V_54 ) ;
V_89:
return V_85 ;
}
static long F_124 ( struct V_14 * V_54 , long V_150 )
{
struct V_35 * V_36 = F_33 ( V_54 ) ;
int V_151 ;
F_125 ( V_48 ) ;
F_126 ( & V_36 -> V_55 , & V_48 , V_152 ) ;
V_151 = ! F_52 ( V_54 , V_56 ) &&
! ( V_54 -> V_66 & V_153 ) &&
F_10 ( V_54 ) ;
F_15 ( V_54 ) ;
if ( V_151 )
V_150 = F_127 ( V_150 ) ;
F_128 ( & V_36 -> V_55 , & V_48 ) ;
return V_150 ;
}
static int F_129 ( struct V_83 * V_14 , struct V_132 * V_133 ,
int V_134 , int V_143 )
{
struct V_23 * V_24 = (struct V_23 * ) V_133 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) , * V_154 , * V_155 ;
struct V_14 * V_156 = NULL ;
struct V_14 * V_54 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_157 ;
int V_85 ;
long V_150 ;
V_85 = F_19 ( V_24 , V_134 , & V_3 ) ;
if ( V_85 < 0 )
goto V_89;
V_134 = V_85 ;
if ( F_122 ( V_146 , & V_14 -> V_143 ) && ! V_36 -> V_2 &&
( V_85 = F_94 ( V_14 ) ) != 0 )
goto V_89;
V_150 = F_130 ( V_15 , V_143 & V_158 ) ;
V_85 = - V_117 ;
V_156 = F_81 ( F_35 ( V_15 ) , NULL ) ;
if ( V_156 == NULL )
goto V_89;
V_9 = F_131 ( V_156 , 1 , 0 , V_96 ) ;
if ( V_9 == NULL )
goto V_89;
V_147:
V_54 = F_98 ( V_33 , V_24 , V_134 , V_15 -> V_71 , V_3 , & V_85 ) ;
if ( ! V_54 )
goto V_89;
F_13 ( V_54 ) ;
if ( F_52 ( V_54 , V_56 ) ) {
F_15 ( V_54 ) ;
F_64 ( V_54 ) ;
goto V_147;
}
V_85 = - V_126 ;
if ( V_54 -> V_69 != V_77 )
goto V_90;
if ( V_54 -> V_66 & V_153 )
goto V_90;
if ( F_10 ( V_54 ) ) {
V_85 = - V_159 ;
if ( ! V_150 )
goto V_90;
V_150 = F_124 ( V_54 , V_150 ) ;
V_85 = F_132 ( V_150 ) ;
if ( F_133 ( V_81 ) )
goto V_89;
F_64 ( V_54 ) ;
goto V_147;
}
V_157 = V_15 -> V_69 ;
switch ( V_157 ) {
case V_70 :
break;
case V_160 :
V_85 = - V_161 ;
goto V_90;
default:
V_85 = - V_27 ;
goto V_90;
}
F_119 ( V_15 ) ;
if ( V_15 -> V_69 != V_157 ) {
F_15 ( V_15 ) ;
F_15 ( V_54 ) ;
F_64 ( V_54 ) ;
goto V_147;
}
V_85 = F_134 ( V_15 , V_54 , V_156 ) ;
if ( V_85 ) {
F_15 ( V_15 ) ;
goto V_90;
}
F_14 ( V_15 ) ;
F_8 ( V_156 ) = V_15 ;
V_156 -> V_69 = V_160 ;
V_156 -> V_71 = V_15 -> V_71 ;
F_69 ( V_156 ) ;
V_154 = F_33 ( V_156 ) ;
F_135 ( V_156 -> V_47 , & V_154 -> V_162 ) ;
V_155 = F_33 ( V_54 ) ;
if ( V_155 -> V_2 ) {
F_136 ( & V_155 -> V_2 -> V_22 ) ;
V_154 -> V_2 = V_155 -> V_2 ;
}
if ( V_155 -> V_42 . V_41 ) {
F_137 ( & V_155 -> V_42 ) ;
V_154 -> V_42 = V_155 -> V_42 ;
}
F_75 ( V_15 , V_54 ) ;
V_14 -> V_65 = V_163 ;
V_15 -> V_69 = V_160 ;
F_14 ( V_156 ) ;
F_138 () ;
F_8 ( V_15 ) = V_156 ;
F_15 ( V_15 ) ;
F_28 ( & V_54 -> V_17 . V_98 ) ;
F_139 ( & V_54 -> V_17 , V_9 ) ;
F_29 ( & V_54 -> V_17 . V_98 ) ;
F_15 ( V_54 ) ;
V_54 -> V_164 ( V_54 ) ;
F_64 ( V_54 ) ;
return 0 ;
V_90:
if ( V_54 )
F_15 ( V_54 ) ;
V_89:
F_66 ( V_9 ) ;
if ( V_156 )
F_62 ( V_156 , 0 ) ;
if ( V_54 )
F_64 ( V_54 ) ;
return V_85 ;
}
static int F_140 ( struct V_83 * V_165 , struct V_83 * V_166 )
{
struct V_14 * V_167 = V_165 -> V_15 , * V_9 = V_166 -> V_15 ;
F_14 ( V_167 ) ;
F_14 ( V_9 ) ;
F_8 ( V_167 ) = V_9 ;
F_8 ( V_9 ) = V_167 ;
F_69 ( V_167 ) ;
F_69 ( V_9 ) ;
if ( V_167 -> V_71 != V_113 ) {
V_167 -> V_69 = V_160 ;
V_9 -> V_69 = V_160 ;
V_165 -> V_65 = V_163 ;
V_166 -> V_65 = V_163 ;
}
return 0 ;
}
static void F_141 ( const struct V_83 * V_168 ,
struct V_83 * V_169 )
{
if ( F_122 ( V_146 , & V_168 -> V_143 ) )
F_142 ( V_146 , & V_169 -> V_143 ) ;
if ( F_122 ( V_170 , & V_168 -> V_143 ) )
F_142 ( V_170 , & V_169 -> V_143 ) ;
}
static int F_143 ( struct V_83 * V_14 , struct V_83 * V_171 , int V_143 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_172 ;
struct V_8 * V_9 ;
int V_85 ;
V_85 = - V_88 ;
if ( V_14 -> type != V_72 && V_14 -> type != V_73 )
goto V_89;
V_85 = - V_27 ;
if ( V_15 -> V_69 != V_77 )
goto V_89;
V_9 = F_144 ( V_15 , 0 , V_143 & V_158 , & V_85 ) ;
if ( ! V_9 ) {
if ( V_85 == 0 )
V_85 = - V_27 ;
goto V_89;
}
V_172 = V_9 -> V_15 ;
F_145 ( V_15 , V_9 ) ;
F_146 ( & F_33 ( V_15 ) -> V_55 ) ;
F_13 ( V_172 ) ;
V_171 -> V_65 = V_163 ;
F_141 ( V_14 , V_171 ) ;
F_147 ( V_172 , V_171 ) ;
F_15 ( V_172 ) ;
return 0 ;
V_89:
return V_85 ;
}
static int F_148 ( struct V_83 * V_14 , struct V_132 * V_133 , int * V_173 , int V_20 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 ;
F_149 ( struct V_23 * , V_24 , V_133 ) ;
int V_85 = 0 ;
if ( V_20 ) {
V_15 = F_12 ( V_15 ) ;
V_85 = - V_174 ;
if ( ! V_15 )
goto V_89;
V_85 = 0 ;
} else {
F_14 ( V_15 ) ;
}
V_36 = F_33 ( V_15 ) ;
F_13 ( V_15 ) ;
if ( ! V_36 -> V_2 ) {
V_24 -> V_28 = V_29 ;
V_24 -> V_30 [ 0 ] = 0 ;
* V_173 = sizeof( short ) ;
} else {
struct V_21 * V_2 = V_36 -> V_2 ;
* V_173 = V_2 -> V_25 ;
memcpy ( V_24 , V_2 -> V_37 , * V_173 ) ;
}
F_15 ( V_15 ) ;
F_64 ( V_15 ) ;
V_89:
return V_85 ;
}
static void F_150 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
V_7 -> V_175 = F_151 ( V_9 ) . V_175 ;
F_151 ( V_9 ) . V_175 = NULL ;
for ( V_40 = V_7 -> V_175 -> V_176 - 1 ; V_40 >= 0 ; V_40 -- )
F_152 ( V_7 -> V_175 -> V_175 [ V_40 ] ) ;
}
static void F_153 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_86 = F_151 ( V_9 ) . V_86 ;
if ( F_151 ( V_9 ) . V_175 )
F_150 ( & V_7 , V_9 ) ;
F_154 ( & V_7 ) ;
F_155 ( V_9 ) ;
}
static int F_156 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_40 ;
unsigned char V_177 = 0 ;
int V_178 = 0 ;
for ( V_40 = V_7 -> V_175 -> V_176 - 1 ; V_40 >= 0 ; V_40 -- ) {
struct V_14 * V_15 = F_157 ( V_7 -> V_175 -> V_175 [ V_40 ] ) ;
if ( V_15 ) {
V_178 ++ ;
V_177 = F_158 ( V_177 ,
F_33 ( V_15 ) -> V_179 ) ;
}
}
if ( F_118 ( V_177 > V_180 ) )
return - V_181 ;
F_151 ( V_9 ) . V_175 = F_159 ( V_7 -> V_175 ) ;
if ( ! F_151 ( V_9 ) . V_175 )
return - V_117 ;
if ( V_178 ) {
for ( V_40 = V_7 -> V_175 -> V_176 - 1 ; V_40 >= 0 ; V_40 -- )
F_160 ( V_7 -> V_175 -> V_175 [ V_40 ] ) ;
}
return V_177 ;
}
static int F_161 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_182 )
{
int V_85 = 0 ;
F_151 ( V_9 ) . V_86 = F_72 ( V_7 -> V_86 ) ;
F_151 ( V_9 ) . V_183 = V_7 -> V_184 . V_183 ;
F_151 ( V_9 ) . V_185 = V_7 -> V_184 . V_185 ;
F_151 ( V_9 ) . V_175 = NULL ;
if ( V_7 -> V_175 && V_182 )
V_85 = F_156 ( V_7 , V_9 ) ;
V_9 -> V_186 = F_153 ;
return V_85 ;
}
static void F_162 ( struct V_8 * V_9 , const struct V_83 * V_14 ,
const struct V_14 * V_54 )
{
if ( F_151 ( V_9 ) . V_86 )
return;
if ( F_122 ( V_146 , & V_14 -> V_143 ) ||
! V_54 -> V_60 ||
F_122 ( V_146 , & V_54 -> V_60 -> V_143 ) ) {
F_151 ( V_9 ) . V_86 = F_72 ( F_73 ( V_81 ) ) ;
F_163 ( & F_151 ( V_9 ) . V_183 , & F_151 ( V_9 ) . V_185 ) ;
}
}
static int F_164 ( struct V_83 * V_14 , struct V_187 * V_188 ,
T_3 V_25 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_33 * V_33 = F_35 ( V_15 ) ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
F_149 ( struct V_23 * , V_24 , V_188 -> V_189 ) ;
struct V_14 * V_54 = NULL ;
int V_190 = 0 ;
int V_85 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_150 ;
struct V_6 V_7 ;
int V_177 ;
int V_191 = 0 ;
F_165 () ;
V_85 = F_166 ( V_14 , V_188 , & V_7 , false ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = - V_88 ;
if ( V_188 -> V_192 & V_193 )
goto V_89;
if ( V_188 -> V_194 ) {
V_85 = F_19 ( V_24 , V_188 -> V_194 , & V_3 ) ;
if ( V_85 < 0 )
goto V_89;
V_190 = V_85 ;
} else {
V_24 = NULL ;
V_85 = - V_174 ;
V_54 = F_12 ( V_15 ) ;
if ( ! V_54 )
goto V_89;
}
if ( F_122 ( V_146 , & V_14 -> V_143 ) && ! V_36 -> V_2
&& ( V_85 = F_94 ( V_14 ) ) != 0 )
goto V_89;
V_85 = - V_195 ;
if ( V_25 > V_15 -> V_44 - 32 )
goto V_89;
if ( V_25 > V_196 ) {
V_191 = F_167 ( T_3 ,
V_25 - V_196 ,
V_197 * V_198 ) ;
V_191 = F_168 ( V_191 ) ;
F_169 ( V_196 < V_198 ) ;
}
V_9 = F_170 ( V_15 , V_25 - V_191 , V_191 ,
V_188 -> V_192 & V_199 , & V_85 ,
V_200 ) ;
if ( V_9 == NULL )
goto V_89;
V_85 = F_161 ( & V_7 , V_9 , true ) ;
if ( V_85 < 0 )
goto V_201;
V_177 = V_85 + 1 ;
F_2 ( & V_7 , V_9 ) ;
F_171 ( V_9 , V_25 - V_191 ) ;
V_9 -> V_191 = V_191 ;
V_9 -> V_25 = V_25 ;
V_85 = F_172 ( V_9 , 0 , & V_188 -> V_202 , V_25 ) ;
if ( V_85 )
goto V_201;
V_150 = F_130 ( V_15 , V_188 -> V_192 & V_199 ) ;
V_147:
if ( ! V_54 ) {
V_85 = - V_58 ;
if ( V_24 == NULL )
goto V_201;
V_54 = F_98 ( V_33 , V_24 , V_190 , V_15 -> V_71 ,
V_3 , & V_85 ) ;
if ( V_54 == NULL )
goto V_201;
}
if ( F_173 ( V_54 , V_9 ) < 0 ) {
V_85 = V_25 ;
goto V_201;
}
F_13 ( V_54 ) ;
V_85 = - V_148 ;
if ( ! F_9 ( V_15 , V_54 ) )
goto V_90;
if ( F_52 ( V_54 , V_56 ) ) {
F_15 ( V_54 ) ;
F_64 ( V_54 ) ;
V_85 = 0 ;
F_13 ( V_15 ) ;
if ( F_8 ( V_15 ) == V_54 ) {
F_8 ( V_15 ) = NULL ;
F_15 ( V_15 ) ;
F_48 ( V_15 , V_54 ) ;
F_64 ( V_54 ) ;
V_85 = - V_126 ;
} else {
F_15 ( V_15 ) ;
}
V_54 = NULL ;
if ( V_85 )
goto V_201;
goto V_147;
}
V_85 = - V_203 ;
if ( V_54 -> V_66 & V_153 )
goto V_90;
if ( V_15 -> V_71 != V_73 ) {
V_85 = F_123 ( V_15 -> V_60 , V_54 -> V_60 ) ;
if ( V_85 )
goto V_90;
}
if ( F_8 ( V_54 ) != V_15 && F_10 ( V_54 ) ) {
if ( ! V_150 ) {
V_85 = - V_159 ;
goto V_90;
}
V_150 = F_124 ( V_54 , V_150 ) ;
V_85 = F_132 ( V_150 ) ;
if ( F_133 ( V_81 ) )
goto V_201;
goto V_147;
}
if ( F_52 ( V_54 , V_204 ) )
F_174 ( V_9 ) ;
F_162 ( V_9 , V_14 , V_54 ) ;
F_175 ( & V_54 -> V_17 , V_9 ) ;
if ( V_177 > F_33 ( V_54 ) -> V_179 )
F_33 ( V_54 ) -> V_179 = V_177 ;
F_15 ( V_54 ) ;
V_54 -> V_164 ( V_54 ) ;
F_64 ( V_54 ) ;
F_154 ( & V_7 ) ;
return V_25 ;
V_90:
F_15 ( V_54 ) ;
V_201:
F_66 ( V_9 ) ;
V_89:
if ( V_54 )
F_64 ( V_54 ) ;
F_154 ( & V_7 ) ;
return V_85 ;
}
static int F_176 ( struct V_83 * V_14 , struct V_187 * V_188 ,
T_3 V_25 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_54 = NULL ;
int V_85 , V_205 ;
struct V_8 * V_9 ;
int V_206 = 0 ;
struct V_6 V_7 ;
bool V_207 = false ;
int V_177 ;
int V_191 ;
F_165 () ;
V_85 = F_166 ( V_14 , V_188 , & V_7 , false ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = - V_88 ;
if ( V_188 -> V_192 & V_193 )
goto V_208;
if ( V_188 -> V_194 ) {
V_85 = V_15 -> V_69 == V_160 ? - V_161 : - V_88 ;
goto V_208;
} else {
V_85 = - V_174 ;
V_54 = F_8 ( V_15 ) ;
if ( ! V_54 )
goto V_208;
}
if ( V_15 -> V_66 & V_209 )
goto V_210;
while ( V_206 < V_25 ) {
V_205 = V_25 - V_206 ;
V_205 = F_167 ( int , V_205 , ( V_15 -> V_44 >> 1 ) - 64 ) ;
V_205 = F_167 ( int , V_205 , F_177 ( 0 ) + V_211 ) ;
V_191 = F_178 ( int , 0 , V_205 - F_177 ( 0 ) ) ;
V_191 = F_167 ( T_3 , V_205 , F_168 ( V_191 ) ) ;
V_9 = F_170 ( V_15 , V_205 - V_191 , V_191 ,
V_188 -> V_192 & V_199 , & V_85 ,
F_179 ( V_211 ) ) ;
if ( ! V_9 )
goto V_208;
V_85 = F_161 ( & V_7 , V_9 , ! V_207 ) ;
if ( V_85 < 0 ) {
F_66 ( V_9 ) ;
goto V_208;
}
V_177 = V_85 + 1 ;
V_207 = true ;
F_171 ( V_9 , V_205 - V_191 ) ;
V_9 -> V_191 = V_191 ;
V_9 -> V_25 = V_205 ;
V_85 = F_172 ( V_9 , 0 , & V_188 -> V_202 , V_205 ) ;
if ( V_85 ) {
F_66 ( V_9 ) ;
goto V_208;
}
F_13 ( V_54 ) ;
if ( F_52 ( V_54 , V_56 ) ||
( V_54 -> V_66 & V_153 ) )
goto V_212;
F_162 ( V_9 , V_14 , V_54 ) ;
F_175 ( & V_54 -> V_17 , V_9 ) ;
if ( V_177 > F_33 ( V_54 ) -> V_179 )
F_33 ( V_54 ) -> V_179 = V_177 ;
F_15 ( V_54 ) ;
V_54 -> V_164 ( V_54 ) ;
V_206 += V_205 ;
}
F_154 ( & V_7 ) ;
return V_206 ;
V_212:
F_15 ( V_54 ) ;
F_66 ( V_9 ) ;
V_210:
if ( V_206 == 0 && ! ( V_188 -> V_192 & V_213 ) )
F_180 ( V_214 , V_81 , 0 ) ;
V_85 = - V_203 ;
V_208:
F_154 ( & V_7 ) ;
return V_206 ? : V_85 ;
}
static int F_181 ( struct V_83 * V_14 , struct V_187 * V_188 ,
T_3 V_25 )
{
int V_85 ;
struct V_14 * V_15 = V_14 -> V_15 ;
V_85 = F_182 ( V_15 ) ;
if ( V_85 )
return V_85 ;
if ( V_15 -> V_69 != V_160 )
return - V_174 ;
if ( V_188 -> V_194 )
V_188 -> V_194 = 0 ;
return F_164 ( V_14 , V_188 , V_25 ) ;
}
static int F_183 ( struct V_83 * V_14 , struct V_187 * V_188 ,
T_3 V_205 , int V_143 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
if ( V_15 -> V_69 != V_160 )
return - V_174 ;
return F_184 ( V_14 , V_188 , V_205 , V_143 ) ;
}
static void F_185 ( struct V_187 * V_188 , struct V_14 * V_15 )
{
struct V_35 * V_36 = F_33 ( V_15 ) ;
if ( V_36 -> V_2 ) {
V_188 -> V_194 = V_36 -> V_2 -> V_25 ;
memcpy ( V_188 -> V_189 , V_36 -> V_2 -> V_37 , V_36 -> V_2 -> V_25 ) ;
}
}
static int F_184 ( struct V_83 * V_14 , struct V_187 * V_188 ,
T_3 V_205 , int V_143 )
{
struct V_6 V_7 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
int V_215 = V_143 & V_199 ;
struct V_8 * V_9 ;
int V_85 ;
int V_216 , V_217 ;
V_85 = - V_88 ;
if ( V_143 & V_193 )
goto V_89;
V_85 = F_79 ( & V_36 -> V_92 ) ;
if ( F_118 ( V_85 ) ) {
V_85 = V_215 ? - V_159 : - V_218 ;
goto V_89;
}
V_217 = F_186 ( V_15 , V_143 ) ;
V_9 = F_187 ( V_15 , V_143 , & V_216 , & V_217 , & V_85 ) ;
if ( ! V_9 ) {
F_13 ( V_15 ) ;
if ( V_15 -> V_71 == V_73 && V_85 == - V_159 &&
( V_15 -> V_66 & V_153 ) )
V_85 = 0 ;
F_15 ( V_15 ) ;
goto V_90;
}
F_45 ( & V_36 -> V_55 ,
V_49 | V_50 | V_51 ) ;
if ( V_188 -> V_189 )
F_185 ( V_188 , V_9 -> V_15 ) ;
if ( V_205 > V_9 -> V_25 - V_217 )
V_205 = V_9 -> V_25 - V_217 ;
else if ( V_205 < V_9 -> V_25 - V_217 )
V_188 -> V_192 |= V_219 ;
V_85 = F_188 ( V_9 , V_217 , V_188 , V_205 ) ;
if ( V_85 )
goto V_201;
if ( F_52 ( V_15 , V_204 ) )
F_189 ( V_188 , V_15 , V_9 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_190 ( & V_7 , F_151 ( V_9 ) . V_86 , F_151 ( V_9 ) . V_183 , F_151 ( V_9 ) . V_185 ) ;
F_4 ( & V_7 , V_9 ) ;
if ( ! ( V_143 & V_220 ) ) {
if ( F_151 ( V_9 ) . V_175 )
F_150 ( & V_7 , V_9 ) ;
F_191 ( V_15 , V_9 -> V_25 ) ;
} else {
F_192 ( V_15 , V_205 ) ;
if ( F_151 ( V_9 ) . V_175 )
V_7 . V_175 = F_159 ( F_151 ( V_9 ) . V_175 ) ;
}
V_85 = ( V_143 & V_219 ) ? V_9 -> V_25 - V_217 : V_205 ;
F_193 ( V_14 , V_188 , & V_7 , V_143 ) ;
V_201:
F_145 ( V_15 , V_9 ) ;
V_90:
F_80 ( & V_36 -> V_92 ) ;
V_89:
return V_85 ;
}
static long F_194 ( struct V_14 * V_15 , long V_150 ,
struct V_8 * V_221 )
{
F_125 ( V_48 ) ;
F_13 ( V_15 ) ;
for (; ; ) {
F_195 ( F_196 ( V_15 ) , & V_48 , V_152 ) ;
if ( F_197 ( & V_15 -> V_17 ) != V_221 ||
V_15 -> V_57 ||
( V_15 -> V_66 & V_153 ) ||
F_133 ( V_81 ) ||
! V_150 )
break;
F_142 ( V_222 , & V_15 -> V_60 -> V_143 ) ;
F_15 ( V_15 ) ;
V_150 = F_198 ( V_150 ) ;
F_13 ( V_15 ) ;
if ( F_52 ( V_15 , V_56 ) )
break;
F_199 ( V_222 , & V_15 -> V_60 -> V_143 ) ;
}
F_128 ( F_196 ( V_15 ) , & V_48 ) ;
F_15 ( V_15 ) ;
return V_150 ;
}
static unsigned int F_200 ( const struct V_8 * V_9 )
{
return V_9 -> V_25 - F_151 ( V_9 ) . V_223 ;
}
static int F_201 ( struct V_83 * V_14 , struct V_187 * V_188 ,
T_3 V_205 , int V_143 )
{
struct V_6 V_7 ;
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_35 * V_36 = F_33 ( V_15 ) ;
F_149 ( struct V_23 * , V_24 , V_188 -> V_189 ) ;
int V_224 = 0 ;
int V_215 = V_143 & V_199 ;
int V_225 = 0 ;
int V_226 ;
int V_85 = 0 ;
long V_150 ;
int V_217 ;
V_85 = - V_27 ;
if ( V_15 -> V_69 != V_160 )
goto V_89;
V_85 = - V_88 ;
if ( V_143 & V_193 )
goto V_89;
V_226 = F_202 ( V_15 , V_143 & V_227 , V_205 ) ;
V_150 = F_203 ( V_15 , V_215 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_85 = F_79 ( & V_36 -> V_92 ) ;
if ( F_118 ( V_85 ) ) {
V_85 = V_215 ? - V_159 : - V_218 ;
goto V_89;
}
do {
int V_228 ;
struct V_8 * V_9 , * V_221 ;
F_13 ( V_15 ) ;
if ( F_52 ( V_15 , V_56 ) ) {
V_85 = - V_58 ;
goto V_229;
}
V_221 = V_9 = F_204 ( & V_15 -> V_17 ) ;
V_230:
if ( V_9 == NULL ) {
F_33 ( V_15 ) -> V_179 = 0 ;
if ( V_224 >= V_226 )
goto V_229;
V_85 = F_182 ( V_15 ) ;
if ( V_85 )
goto V_229;
if ( V_15 -> V_66 & V_153 )
goto V_229;
F_15 ( V_15 ) ;
V_85 = - V_159 ;
if ( ! V_150 )
break;
F_80 ( & V_36 -> V_92 ) ;
V_150 = F_194 ( V_15 , V_150 , V_221 ) ;
if ( F_133 ( V_81 )
|| F_79 ( & V_36 -> V_92 ) ) {
V_85 = F_132 ( V_150 ) ;
goto V_89;
}
continue;
V_229:
F_15 ( V_15 ) ;
break;
}
V_217 = F_186 ( V_15 , V_143 ) ;
while ( V_217 >= F_200 ( V_9 ) ) {
V_217 -= F_200 ( V_9 ) ;
V_221 = V_9 ;
V_9 = F_205 ( V_9 , & V_15 -> V_17 ) ;
if ( ! V_9 )
goto V_230;
}
F_15 ( V_15 ) ;
if ( V_225 ) {
if ( ( F_151 ( V_9 ) . V_86 != V_7 . V_86 ) ||
! F_206 ( F_151 ( V_9 ) . V_183 , V_7 . V_184 . V_183 ) ||
! F_207 ( F_151 ( V_9 ) . V_185 , V_7 . V_184 . V_185 ) )
break;
} else if ( F_122 ( V_146 , & V_14 -> V_143 ) ) {
F_190 ( & V_7 , F_151 ( V_9 ) . V_86 , F_151 ( V_9 ) . V_183 , F_151 ( V_9 ) . V_185 ) ;
V_225 = 1 ;
}
if ( V_24 ) {
F_185 ( V_188 , V_9 -> V_15 ) ;
V_24 = NULL ;
}
V_228 = F_167 (unsigned int, unix_skb_len(skb) - skip, size) ;
if ( F_188 ( V_9 , F_151 ( V_9 ) . V_223 + V_217 ,
V_188 , V_228 ) ) {
if ( V_224 == 0 )
V_224 = - V_231 ;
break;
}
V_224 += V_228 ;
V_205 -= V_228 ;
if ( ! ( V_143 & V_220 ) ) {
F_151 ( V_9 ) . V_223 += V_228 ;
F_191 ( V_15 , V_228 ) ;
if ( F_151 ( V_9 ) . V_175 )
F_150 ( & V_7 , V_9 ) ;
if ( F_200 ( V_9 ) )
break;
F_208 ( V_9 , & V_15 -> V_17 ) ;
F_209 ( V_9 ) ;
if ( V_7 . V_175 )
break;
} else {
if ( F_151 ( V_9 ) . V_175 )
V_7 . V_175 = F_159 ( F_151 ( V_9 ) . V_175 ) ;
F_192 ( V_15 , V_228 ) ;
break;
}
} while ( V_205 );
F_80 ( & V_36 -> V_92 ) ;
F_193 ( V_14 , V_188 , & V_7 , V_143 ) ;
V_89:
return V_224 ? : V_85 ;
}
static int F_210 ( struct V_83 * V_14 , int V_129 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
struct V_14 * V_54 ;
if ( V_129 < V_232 || V_129 > V_233 )
return - V_27 ;
++ V_129 ;
F_13 ( V_15 ) ;
V_15 -> V_66 |= V_129 ;
V_54 = F_8 ( V_15 ) ;
if ( V_54 )
F_14 ( V_54 ) ;
F_15 ( V_15 ) ;
V_15 -> V_74 ( V_15 ) ;
if ( V_54 &&
( V_15 -> V_71 == V_72 || V_15 -> V_71 == V_73 ) ) {
int V_234 = 0 ;
if ( V_129 & V_153 )
V_234 |= V_209 ;
if ( V_129 & V_209 )
V_234 |= V_153 ;
F_13 ( V_54 ) ;
V_54 -> V_66 |= V_234 ;
F_15 ( V_54 ) ;
V_54 -> V_74 ( V_54 ) ;
if ( V_234 == V_67 )
F_46 ( V_54 , V_75 , V_76 ) ;
else if ( V_234 & V_153 )
F_46 ( V_54 , V_75 , V_235 ) ;
}
if ( V_54 )
F_64 ( V_54 ) ;
return 0 ;
}
long F_211 ( struct V_14 * V_15 )
{
struct V_8 * V_9 ;
long V_236 = 0 ;
if ( V_15 -> V_69 == V_77 )
return - V_27 ;
F_28 ( & V_15 -> V_17 . V_98 ) ;
if ( V_15 -> V_71 == V_72 ||
V_15 -> V_71 == V_73 ) {
F_212 (&sk->sk_receive_queue, skb)
V_236 += F_200 ( V_9 ) ;
} else {
V_9 = F_204 ( & V_15 -> V_17 ) ;
if ( V_9 )
V_236 = V_9 -> V_25 ;
}
F_29 ( & V_15 -> V_17 . V_98 ) ;
return V_236 ;
}
long F_213 ( struct V_14 * V_15 )
{
return F_214 ( V_15 ) ;
}
static int F_215 ( struct V_83 * V_14 , unsigned int V_237 , unsigned long V_238 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
long V_236 = 0 ;
int V_85 ;
switch ( V_237 ) {
case V_239 :
V_236 = F_213 ( V_15 ) ;
V_85 = F_216 ( V_236 , ( int V_240 * ) V_238 ) ;
break;
case V_241 :
V_236 = F_211 ( V_15 ) ;
if ( V_236 < 0 )
V_85 = V_236 ;
else
V_85 = F_216 ( V_236 , ( int V_240 * ) V_238 ) ;
break;
default:
V_85 = - V_242 ;
break;
}
return V_85 ;
}
static unsigned int F_217 ( struct V_243 * V_243 , struct V_83 * V_14 , T_4 * V_48 )
{
struct V_14 * V_15 = V_14 -> V_15 ;
unsigned int V_244 ;
F_218 ( V_243 , F_196 ( V_15 ) , V_48 ) ;
V_244 = 0 ;
if ( V_15 -> V_57 )
V_244 |= V_245 ;
if ( V_15 -> V_66 == V_67 )
V_244 |= V_246 ;
if ( V_15 -> V_66 & V_153 )
V_244 |= V_247 | V_248 | V_249 ;
if ( ! F_49 ( & V_15 -> V_17 ) )
V_244 |= V_248 | V_249 ;
if ( ( V_15 -> V_71 == V_72 || V_15 -> V_71 == V_73 ) &&
V_15 -> V_69 == V_70 )
V_244 |= V_246 ;
if ( F_39 ( V_15 ) )
V_244 |= V_49 | V_50 | V_51 ;
return V_244 ;
}
static unsigned int F_219 ( struct V_243 * V_243 , struct V_83 * V_14 ,
T_4 * V_48 )
{
struct V_14 * V_15 = V_14 -> V_15 , * V_54 ;
unsigned int V_244 , V_250 ;
F_218 ( V_243 , F_196 ( V_15 ) , V_48 ) ;
V_244 = 0 ;
if ( V_15 -> V_57 || ! F_49 ( & V_15 -> V_251 ) )
V_244 |= V_245 |
( F_52 ( V_15 , V_252 ) ? V_253 : 0 ) ;
if ( V_15 -> V_66 & V_153 )
V_244 |= V_247 | V_248 | V_249 ;
if ( V_15 -> V_66 == V_67 )
V_244 |= V_246 ;
if ( ! F_49 ( & V_15 -> V_17 ) )
V_244 |= V_248 | V_249 ;
if ( V_15 -> V_71 == V_73 ) {
if ( V_15 -> V_69 == V_70 )
V_244 |= V_246 ;
if ( V_15 -> V_69 == V_254 )
return V_244 ;
}
if ( ! ( F_220 ( V_48 ) & ( V_51 | V_50 | V_49 ) ) )
return V_244 ;
V_250 = F_39 ( V_15 ) ;
V_54 = F_12 ( V_15 ) ;
if ( V_54 ) {
if ( F_8 ( V_54 ) != V_15 ) {
F_218 ( V_243 , & F_33 ( V_54 ) -> V_55 , V_48 ) ;
if ( F_10 ( V_54 ) )
V_250 = 0 ;
}
F_64 ( V_54 ) ;
}
if ( V_250 )
V_244 |= V_49 | V_50 | V_51 ;
else
F_142 ( V_255 , & V_15 -> V_60 -> V_143 ) ;
return V_244 ;
}
static struct V_14 * F_221 ( struct V_256 * V_257 , T_5 * V_258 )
{
unsigned long V_259 = F_222 ( * V_258 ) ;
unsigned long V_260 = F_223 ( * V_258 ) ;
struct V_14 * V_15 ;
unsigned long V_176 = 0 ;
for ( V_15 = F_224 ( & V_5 [ V_260 ] ) ; V_15 ; V_15 = F_225 ( V_15 ) ) {
if ( F_35 ( V_15 ) != F_226 ( V_257 ) )
continue;
if ( ++ V_176 == V_259 )
break;
}
return V_15 ;
}
static struct V_14 * F_227 ( struct V_256 * V_257 ,
struct V_14 * V_15 ,
T_5 * V_258 )
{
unsigned long V_260 ;
while ( V_15 > (struct V_14 * ) V_261 ) {
V_15 = F_225 ( V_15 ) ;
if ( ! V_15 )
goto V_262;
if ( F_35 ( V_15 ) == F_226 ( V_257 ) )
return V_15 ;
}
do {
V_15 = F_221 ( V_257 , V_258 ) ;
if ( V_15 )
return V_15 ;
V_262:
V_260 = F_223 ( * V_258 ) + 1 ;
* V_258 = F_228 ( V_260 , 1 ) ;
} while ( V_260 < F_229 ( V_5 ) );
return NULL ;
}
static void * F_230 ( struct V_256 * V_257 , T_5 * V_258 )
__acquires( V_32 )
{
F_28 ( & V_32 ) ;
if ( ! * V_258 )
return V_261 ;
if ( F_223 ( * V_258 ) >= F_229 ( V_5 ) )
return NULL ;
return F_227 ( V_257 , NULL , V_258 ) ;
}
static void * F_231 ( struct V_256 * V_257 , void * V_263 , T_5 * V_258 )
{
++ * V_258 ;
return F_227 ( V_257 , V_263 , V_258 ) ;
}
static void F_232 ( struct V_256 * V_257 , void * V_263 )
__releases( V_32 )
{
F_29 ( & V_32 ) ;
}
static int F_233 ( struct V_256 * V_257 , void * V_263 )
{
if ( V_263 == V_261 )
F_234 ( V_257 , L_4
L_5 ) ;
else {
struct V_14 * V_19 = V_263 ;
struct V_35 * V_36 = F_33 ( V_19 ) ;
F_13 ( V_19 ) ;
F_235 ( V_257 , L_6 ,
V_19 ,
F_40 ( & V_19 -> V_264 ) ,
0 ,
V_19 -> V_69 == V_77 ? V_265 : 0 ,
V_19 -> V_71 ,
V_19 -> V_60 ?
( V_19 -> V_69 == V_160 ? V_163 : V_109 ) :
( V_19 -> V_69 == V_160 ? V_266 : V_267 ) ,
F_236 ( V_19 ) ) ;
if ( V_36 -> V_2 ) {
int V_40 , V_25 ;
F_237 ( V_257 , ' ' ) ;
V_40 = 0 ;
V_25 = V_36 -> V_2 -> V_25 - sizeof( short ) ;
if ( ! F_238 ( V_19 ) )
V_25 -- ;
else {
F_237 ( V_257 , '@' ) ;
V_40 ++ ;
}
for ( ; V_40 < V_25 ; V_40 ++ )
F_237 ( V_257 , V_36 -> V_2 -> V_37 -> V_30 [ V_40 ] ) ;
}
F_15 ( V_19 ) ;
F_237 ( V_257 , '\n' ) ;
}
return 0 ;
}
static int F_239 ( struct V_39 * V_39 , struct V_243 * V_243 )
{
return F_240 ( V_39 , V_243 , & V_268 ,
sizeof( struct V_269 ) ) ;
}
static int T_6 F_241 ( struct V_33 * V_33 )
{
int error = - V_117 ;
V_33 -> V_101 . V_102 = 10 ;
if ( F_242 ( V_33 ) )
goto V_89;
#ifdef F_243
if ( ! F_244 ( L_7 , 0 , V_33 -> V_270 , & V_271 ) ) {
F_245 ( V_33 ) ;
goto V_89;
}
#endif
error = 0 ;
V_89:
return error ;
}
static void T_7 F_246 ( struct V_33 * V_33 )
{
F_245 ( V_33 ) ;
F_247 ( L_7 , V_33 -> V_270 ) ;
}
static int T_8 F_248 ( void )
{
int V_272 = - 1 ;
F_169 ( sizeof( struct V_273 ) > F_249 ( struct V_8 , V_274 ) ) ;
V_272 = F_250 ( & V_97 , 1 ) ;
if ( V_272 != 0 ) {
F_251 ( L_8 , V_275 ) ;
goto V_89;
}
F_252 ( & V_276 ) ;
F_253 ( & V_277 ) ;
V_89:
return V_272 ;
}
static void T_9 F_254 ( void )
{
F_255 ( V_95 ) ;
F_256 ( & V_97 ) ;
F_257 ( & V_277 ) ;
}
