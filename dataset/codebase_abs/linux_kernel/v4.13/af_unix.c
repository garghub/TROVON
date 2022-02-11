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
static int F_40 ( T_2 * V_42 , unsigned V_43 , int V_44 ,
void * V_45 )
{
struct V_34 * V_35 ;
T_3 * V_46 ;
V_35 = F_41 ( V_42 , struct V_34 , V_47 ) ;
F_42 ( & F_34 ( V_35 -> V_47 . V_48 ) -> V_49 ,
V_42 ) ;
V_35 -> V_47 . V_48 = NULL ;
V_46 = F_43 ( & V_35 -> V_14 ) ;
if ( V_46 )
F_44 ( V_46 , V_45 ) ;
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , struct V_13 * V_50 )
{
struct V_34 * V_35 , * V_51 ;
int V_52 ;
V_35 = F_34 ( V_14 ) ;
V_51 = F_34 ( V_50 ) ;
V_52 = 0 ;
F_29 ( & V_51 -> V_49 . V_53 ) ;
if ( ! V_35 -> V_47 . V_48 ) {
V_35 -> V_47 . V_48 = V_50 ;
F_46 ( & V_51 -> V_49 , & V_35 -> V_47 ) ;
V_52 = 1 ;
}
F_30 ( & V_51 -> V_49 . V_53 ) ;
return V_52 ;
}
static void F_47 ( struct V_13 * V_14 ,
struct V_13 * V_50 )
{
struct V_34 * V_35 , * V_51 ;
V_35 = F_34 ( V_14 ) ;
V_51 = F_34 ( V_50 ) ;
F_29 ( & V_51 -> V_49 . V_53 ) ;
if ( V_35 -> V_47 . V_48 == V_50 ) {
F_42 ( & V_51 -> V_49 , & V_35 -> V_47 ) ;
V_35 -> V_47 . V_48 = NULL ;
}
F_30 ( & V_51 -> V_49 . V_53 ) ;
}
static void F_48 ( struct V_13 * V_14 ,
struct V_13 * V_50 )
{
F_47 ( V_14 , V_50 ) ;
F_44 ( F_43 ( V_14 ) ,
V_54 |
V_55 |
V_56 ) ;
}
static int F_49 ( struct V_13 * V_14 , struct V_13 * V_50 )
{
int V_57 ;
V_57 = F_45 ( V_14 , V_50 ) ;
if ( F_11 ( V_50 ) )
return 1 ;
if ( V_57 )
F_47 ( V_14 , V_50 ) ;
return 0 ;
}
static int F_50 ( const struct V_13 * V_14 )
{
return V_14 -> V_58 != V_59 &&
( F_51 ( & V_14 -> V_60 ) << 2 ) <= V_14 -> V_61 ;
}
static void F_52 ( struct V_13 * V_14 )
{
struct V_62 * V_63 ;
F_53 () ;
if ( F_50 ( V_14 ) ) {
V_63 = F_54 ( V_14 -> V_64 ) ;
if ( F_55 ( V_63 ) )
F_56 ( & V_63 -> V_65 ,
V_54 | V_55 | V_56 ) ;
F_57 ( V_14 , V_66 , V_67 ) ;
}
F_58 () ;
}
static void F_59 ( struct V_13 * V_14 , struct V_13 * V_50 )
{
if ( ! F_60 ( & V_14 -> V_16 ) ) {
F_61 ( & V_14 -> V_16 ) ;
F_62 ( & F_34 ( V_14 ) -> V_49 ) ;
if ( ! F_63 ( V_50 , V_68 ) && F_9 ( V_50 ) == V_14 ) {
V_50 -> V_69 = V_70 ;
V_50 -> V_71 ( V_50 ) ;
}
}
}
static void F_64 ( struct V_13 * V_14 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_61 ( & V_14 -> V_16 ) ;
F_25 ( F_51 ( & V_14 -> V_60 ) ) ;
F_25 ( ! F_26 ( V_14 ) ) ;
F_25 ( V_14 -> V_72 ) ;
if ( ! F_63 ( V_14 , V_68 ) ) {
F_65 ( L_1 , V_14 ) ;
return;
}
if ( V_35 -> V_2 )
F_17 ( V_35 -> V_2 ) ;
F_66 ( & V_73 ) ;
F_67 () ;
F_68 ( F_36 ( V_14 ) , V_14 -> V_74 , - 1 ) ;
F_69 () ;
#ifdef F_70
F_71 ( L_2 , V_14 ,
F_72 ( & V_73 ) ) ;
#endif
}
static void F_73 ( struct V_13 * V_14 , int V_75 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_41 V_41 ;
struct V_13 * V_76 ;
struct V_8 * V_9 ;
int V_77 ;
F_28 ( V_14 ) ;
F_14 ( V_14 ) ;
F_74 ( V_14 ) ;
V_14 -> V_78 = V_79 ;
V_41 = V_35 -> V_41 ;
V_35 -> V_41 . V_40 = NULL ;
V_35 -> V_41 . V_80 = NULL ;
V_77 = V_14 -> V_58 ;
V_14 -> V_58 = V_81 ;
F_16 ( V_14 ) ;
F_62 ( & V_35 -> V_49 ) ;
V_76 = F_9 ( V_14 ) ;
if ( V_76 != NULL ) {
if ( V_14 -> V_82 == V_83 || V_14 -> V_82 == V_84 ) {
F_14 ( V_76 ) ;
V_76 -> V_78 = V_79 ;
if ( ! F_60 ( & V_14 -> V_16 ) || V_75 )
V_76 -> V_69 = V_70 ;
F_16 ( V_76 ) ;
V_76 -> V_85 ( V_76 ) ;
F_57 ( V_76 , V_86 , V_87 ) ;
}
F_47 ( V_14 , V_76 ) ;
F_75 ( V_76 ) ;
F_9 ( V_14 ) = NULL ;
}
while ( ( V_9 = F_76 ( & V_14 -> V_16 ) ) != NULL ) {
if ( V_77 == V_59 )
F_73 ( V_9 -> V_14 , 1 ) ;
F_3 ( V_9 ) . V_88 = V_9 -> V_24 ;
F_77 ( V_9 ) ;
}
if ( V_41 . V_40 )
F_78 ( & V_41 ) ;
F_75 ( V_14 ) ;
if ( V_89 )
F_79 () ;
}
static void F_80 ( struct V_13 * V_14 )
{
F_81 ( V_14 -> V_90 ) ;
if ( V_14 -> V_91 )
F_82 ( V_14 -> V_91 ) ;
V_14 -> V_90 = F_83 ( F_84 ( V_92 ) ) ;
V_14 -> V_91 = F_85 () ;
}
static void F_86 ( struct V_13 * V_14 , struct V_13 * V_93 )
{
F_81 ( V_14 -> V_90 ) ;
if ( V_14 -> V_91 )
F_82 ( V_14 -> V_91 ) ;
V_14 -> V_90 = F_83 ( V_93 -> V_90 ) ;
V_14 -> V_91 = F_87 ( V_93 -> V_91 ) ;
}
static int F_88 ( struct V_94 * V_13 , int V_95 )
{
int V_96 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_97 * V_98 = NULL ;
V_96 = - V_99 ;
if ( V_13 -> type != V_83 && V_13 -> type != V_84 )
goto V_100;
V_96 = - V_26 ;
if ( ! V_35 -> V_2 )
goto V_100;
F_14 ( V_14 ) ;
if ( V_14 -> V_58 != V_81 && V_14 -> V_58 != V_59 )
goto V_101;
if ( V_95 > V_14 -> V_17 )
F_62 ( & V_35 -> V_49 ) ;
V_14 -> V_17 = V_95 ;
V_14 -> V_58 = V_59 ;
F_80 ( V_14 ) ;
V_96 = 0 ;
V_101:
F_16 ( V_14 ) ;
F_81 ( V_98 ) ;
V_100:
return V_96 ;
}
static int F_89 ( struct V_13 * V_14 , int V_102 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
if ( F_90 ( & V_35 -> V_103 ) )
return - V_104 ;
V_14 -> V_105 = V_102 ;
F_91 ( & V_35 -> V_103 ) ;
return 0 ;
}
static struct V_13 * F_92 ( struct V_32 * V_32 , struct V_94 * V_13 , int V_106 )
{
struct V_13 * V_14 = NULL ;
struct V_34 * V_35 ;
F_93 ( & V_73 ) ;
if ( F_72 ( & V_73 ) > 2 * F_94 () )
goto V_100;
V_14 = F_95 ( V_32 , V_107 , V_108 , & V_109 , V_106 ) ;
if ( ! V_14 )
goto V_100;
F_96 ( V_13 , V_14 ) ;
F_97 ( & V_14 -> V_16 . V_53 ,
& V_110 ) ;
V_14 -> V_111 = V_112 ;
V_14 -> V_113 = F_52 ;
V_14 -> V_17 = V_32 -> V_114 . V_115 ;
V_14 -> V_116 = F_64 ;
V_35 = F_34 ( V_14 ) ;
V_35 -> V_41 . V_40 = NULL ;
V_35 -> V_41 . V_80 = NULL ;
F_98 ( & V_35 -> V_53 ) ;
F_99 ( & V_35 -> V_117 , 0 ) ;
F_100 ( & V_35 -> V_118 ) ;
F_101 ( & V_35 -> V_103 ) ;
F_101 ( & V_35 -> V_119 ) ;
F_102 ( & V_35 -> V_49 ) ;
F_103 ( & V_35 -> V_47 , F_40 ) ;
F_31 ( F_1 ( V_14 ) , V_14 ) ;
V_100:
if ( V_14 == NULL )
F_66 ( & V_73 ) ;
else {
F_67 () ;
F_68 ( F_36 ( V_14 ) , V_14 -> V_74 , 1 ) ;
F_69 () ;
}
return V_14 ;
}
static int F_104 ( struct V_32 * V_32 , struct V_94 * V_13 , int V_120 ,
int V_106 )
{
if ( V_120 && V_120 != V_107 )
return - V_121 ;
V_13 -> V_77 = V_122 ;
switch ( V_13 -> type ) {
case V_83 :
V_13 -> V_123 = & V_124 ;
break;
case V_125 :
V_13 -> type = V_126 ;
case V_126 :
V_13 -> V_123 = & V_127 ;
break;
case V_84 :
V_13 -> V_123 = & V_128 ;
break;
default:
return - V_129 ;
}
return F_92 ( V_32 , V_13 , V_106 ) ? 0 : - V_130 ;
}
static int F_105 ( struct V_94 * V_13 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
if ( ! V_14 )
return 0 ;
F_73 ( V_14 , 0 ) ;
V_13 -> V_14 = NULL ;
return 0 ;
}
static int F_106 ( struct V_94 * V_13 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
static T_4 V_131 = 1 ;
struct V_20 * V_2 ;
int V_96 ;
unsigned int V_132 = 0 ;
V_96 = F_90 ( & V_35 -> V_119 ) ;
if ( V_96 )
return V_96 ;
V_96 = 0 ;
if ( V_35 -> V_2 )
goto V_100;
V_96 = - V_130 ;
V_2 = F_107 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_108 ) ;
if ( ! V_2 )
goto V_100;
V_2 -> V_36 -> V_27 = V_28 ;
F_108 ( & V_2 -> V_21 , 1 ) ;
V_133:
V_2 -> V_24 = sprintf ( V_2 -> V_36 -> V_29 + 1 , L_3 , V_131 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_6 ( F_21 ( V_2 -> V_36 , V_2 -> V_24 , 0 ) ) ;
F_29 ( & V_31 ) ;
V_131 = ( V_131 + 1 ) & 0xFFFFF ;
if ( F_32 ( V_32 , V_2 -> V_36 , V_2 -> V_24 , V_13 -> type ,
V_2 -> V_3 ) ) {
F_30 ( & V_31 ) ;
F_109 () ;
if ( V_132 ++ == 0xFFFFF ) {
V_96 = - V_134 ;
F_19 ( V_2 ) ;
goto V_100;
}
goto V_133;
}
V_2 -> V_3 ^= V_14 -> V_82 ;
F_22 ( V_14 ) ;
V_35 -> V_2 = V_2 ;
F_24 ( & V_5 [ V_2 -> V_3 ] , V_14 ) ;
F_30 ( & V_31 ) ;
V_96 = 0 ;
V_100: F_91 ( & V_35 -> V_119 ) ;
return V_96 ;
}
static struct V_13 * F_110 ( struct V_32 * V_32 ,
struct V_22 * V_33 , int V_24 ,
int type , unsigned int V_3 , int * error )
{
struct V_13 * V_35 ;
struct V_41 V_41 ;
int V_96 = 0 ;
if ( V_33 -> V_29 [ 0 ] ) {
struct V_38 * V_38 ;
V_96 = F_111 ( V_33 -> V_29 , V_135 , & V_41 ) ;
if ( V_96 )
goto V_136;
V_38 = F_39 ( V_41 . V_40 ) ;
V_96 = F_112 ( V_38 , V_137 ) ;
if ( V_96 )
goto V_138;
V_96 = - V_139 ;
if ( ! F_113 ( V_38 -> V_140 ) )
goto V_138;
V_35 = F_38 ( V_38 ) ;
if ( ! V_35 )
goto V_138;
if ( V_35 -> V_82 == type )
F_114 ( & V_41 ) ;
F_78 ( & V_41 ) ;
V_96 = - V_141 ;
if ( V_35 -> V_82 != type ) {
F_75 ( V_35 ) ;
goto V_136;
}
} else {
V_96 = - V_139 ;
V_35 = F_37 ( V_32 , V_33 , V_24 , type , V_3 ) ;
if ( V_35 ) {
struct V_40 * V_40 ;
V_40 = F_34 ( V_35 ) -> V_41 . V_40 ;
if ( V_40 )
F_114 ( & F_34 ( V_35 ) -> V_41 ) ;
} else
goto V_136;
}
return V_35 ;
V_138:
F_78 ( & V_41 ) ;
V_136:
* error = V_96 ;
return NULL ;
}
static int F_115 ( const char * V_29 , T_5 V_43 , struct V_41 * V_142 )
{
struct V_40 * V_40 ;
struct V_41 V_41 ;
int V_96 = 0 ;
V_40 = F_116 ( V_143 , V_29 , & V_41 , 0 ) ;
V_96 = F_117 ( V_40 ) ;
if ( F_118 ( V_40 ) )
return V_96 ;
V_96 = F_119 ( & V_41 , V_40 , V_43 , 0 ) ;
if ( ! V_96 ) {
V_96 = F_120 ( F_121 ( V_41 . V_40 ) , V_40 , V_43 , 0 ) ;
if ( ! V_96 ) {
V_142 -> V_80 = F_122 ( V_41 . V_80 ) ;
V_142 -> V_40 = F_123 ( V_40 ) ;
}
}
F_124 ( & V_41 , V_40 ) ;
return V_96 ;
}
static int F_125 ( struct V_94 * V_13 , struct V_144 * V_145 , int V_146 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_22 * V_23 = (struct V_22 * ) V_145 ;
char * V_29 = V_23 -> V_29 ;
int V_96 ;
unsigned int V_3 ;
struct V_20 * V_2 ;
struct V_1 * V_30 ;
struct V_41 V_41 = { } ;
V_96 = - V_26 ;
if ( V_146 < F_126 ( struct V_22 , V_27 ) ||
V_23 -> V_27 != V_28 )
goto V_100;
if ( V_146 == sizeof( short ) ) {
V_96 = F_106 ( V_13 ) ;
goto V_100;
}
V_96 = F_20 ( V_23 , V_146 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_146 = V_96 ;
if ( V_29 [ 0 ] ) {
T_5 V_43 = V_147 |
( F_127 ( V_13 ) -> V_140 & ~ F_128 () ) ;
V_96 = F_115 ( V_29 , V_43 , & V_41 ) ;
if ( V_96 ) {
if ( V_96 == - V_148 )
V_96 = - V_149 ;
goto V_100;
}
}
V_96 = F_90 ( & V_35 -> V_119 ) ;
if ( V_96 )
goto V_150;
V_96 = - V_26 ;
if ( V_35 -> V_2 )
goto V_151;
V_96 = - V_130 ;
V_2 = F_129 ( sizeof( * V_2 ) + V_146 , V_108 ) ;
if ( ! V_2 )
goto V_151;
memcpy ( V_2 -> V_36 , V_23 , V_146 ) ;
V_2 -> V_24 = V_146 ;
V_2 -> V_3 = V_3 ^ V_14 -> V_82 ;
F_108 ( & V_2 -> V_21 , 1 ) ;
if ( V_29 [ 0 ] ) {
V_2 -> V_3 = V_4 ;
V_3 = F_39 ( V_41 . V_40 ) -> V_152 & ( V_4 - 1 ) ;
F_29 ( & V_31 ) ;
V_35 -> V_41 = V_41 ;
V_30 = & V_5 [ V_3 ] ;
} else {
F_29 ( & V_31 ) ;
V_96 = - V_149 ;
if ( F_32 ( V_32 , V_23 , V_146 ,
V_14 -> V_82 , V_3 ) ) {
F_17 ( V_2 ) ;
goto V_101;
}
V_30 = & V_5 [ V_2 -> V_3 ] ;
}
V_96 = 0 ;
F_22 ( V_14 ) ;
V_35 -> V_2 = V_2 ;
F_24 ( V_30 , V_14 ) ;
V_101:
F_30 ( & V_31 ) ;
V_151:
F_91 ( & V_35 -> V_119 ) ;
V_150:
if ( V_96 )
F_78 ( & V_41 ) ;
V_100:
return V_96 ;
}
static void F_130 ( struct V_13 * V_153 , struct V_13 * V_154 )
{
if ( F_131 ( V_153 == V_154 ) || ! V_154 ) {
F_14 ( V_153 ) ;
return;
}
if ( V_153 < V_154 ) {
F_14 ( V_153 ) ;
F_132 ( V_154 ) ;
} else {
F_14 ( V_154 ) ;
F_132 ( V_153 ) ;
}
}
static void F_133 ( struct V_13 * V_153 , struct V_13 * V_154 )
{
if ( F_131 ( V_153 == V_154 ) || ! V_154 ) {
F_16 ( V_153 ) ;
return;
}
F_16 ( V_153 ) ;
F_16 ( V_154 ) ;
}
static int F_134 ( struct V_94 * V_13 , struct V_144 * V_2 ,
int V_155 , int V_44 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_22 * V_23 = (struct V_22 * ) V_2 ;
struct V_13 * V_50 ;
unsigned int V_3 ;
int V_96 ;
V_96 = - V_26 ;
if ( V_155 < F_126 ( struct V_144 , V_156 ) )
goto V_100;
if ( V_2 -> V_156 != V_157 ) {
V_96 = F_20 ( V_23 , V_155 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_155 = V_96 ;
if ( F_135 ( V_158 , & V_13 -> V_44 ) &&
! F_34 ( V_14 ) -> V_2 && ( V_96 = F_106 ( V_13 ) ) != 0 )
goto V_100;
V_159:
V_50 = F_110 ( V_32 , V_23 , V_155 , V_13 -> type , V_3 , & V_96 ) ;
if ( ! V_50 )
goto V_100;
F_130 ( V_14 , V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ) {
F_133 ( V_14 , V_50 ) ;
F_75 ( V_50 ) ;
goto V_159;
}
V_96 = - V_160 ;
if ( ! F_10 ( V_14 , V_50 ) )
goto V_101;
V_96 = F_136 ( V_14 -> V_72 , V_50 -> V_72 ) ;
if ( V_96 )
goto V_101;
} else {
V_50 = NULL ;
F_130 ( V_14 , V_50 ) ;
}
if ( F_9 ( V_14 ) ) {
struct V_13 * V_161 = F_9 ( V_14 ) ;
F_9 ( V_14 ) = V_50 ;
F_48 ( V_14 , V_161 ) ;
F_133 ( V_14 , V_50 ) ;
if ( V_50 != V_161 )
F_59 ( V_14 , V_161 ) ;
F_75 ( V_161 ) ;
} else {
F_9 ( V_14 ) = V_50 ;
F_133 ( V_14 , V_50 ) ;
}
return 0 ;
V_101:
F_133 ( V_14 , V_50 ) ;
F_75 ( V_50 ) ;
V_100:
return V_96 ;
}
static long F_137 ( struct V_13 * V_50 , long V_162 )
{
struct V_34 * V_35 = F_34 ( V_50 ) ;
int V_163 ;
F_138 ( V_65 ) ;
F_139 ( & V_35 -> V_49 , & V_65 , V_164 ) ;
V_163 = ! F_63 ( V_50 , V_68 ) &&
! ( V_50 -> V_78 & V_165 ) &&
F_11 ( V_50 ) ;
F_16 ( V_50 ) ;
if ( V_163 )
V_162 = F_140 ( V_162 ) ;
F_141 ( & V_35 -> V_49 , & V_65 ) ;
return V_162 ;
}
static int F_142 ( struct V_94 * V_13 , struct V_144 * V_145 ,
int V_146 , int V_44 )
{
struct V_22 * V_23 = (struct V_22 * ) V_145 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) , * V_166 , * V_167 ;
struct V_13 * V_168 = NULL ;
struct V_13 * V_50 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_169 ;
int V_96 ;
long V_162 ;
V_96 = F_20 ( V_23 , V_146 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_146 = V_96 ;
if ( F_135 ( V_158 , & V_13 -> V_44 ) && ! V_35 -> V_2 &&
( V_96 = F_106 ( V_13 ) ) != 0 )
goto V_100;
V_162 = F_143 ( V_14 , V_44 & V_170 ) ;
V_96 = - V_130 ;
V_168 = F_92 ( F_36 ( V_14 ) , NULL , 0 ) ;
if ( V_168 == NULL )
goto V_100;
V_9 = F_144 ( V_168 , 1 , 0 , V_108 ) ;
if ( V_9 == NULL )
goto V_100;
V_159:
V_50 = F_110 ( V_32 , V_23 , V_146 , V_14 -> V_82 , V_3 , & V_96 ) ;
if ( ! V_50 )
goto V_100;
F_14 ( V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ) {
F_16 ( V_50 ) ;
F_75 ( V_50 ) ;
goto V_159;
}
V_96 = - V_139 ;
if ( V_50 -> V_58 != V_59 )
goto V_101;
if ( V_50 -> V_78 & V_165 )
goto V_101;
if ( F_11 ( V_50 ) ) {
V_96 = - V_171 ;
if ( ! V_162 )
goto V_101;
V_162 = F_137 ( V_50 , V_162 ) ;
V_96 = F_145 ( V_162 ) ;
if ( F_146 ( V_92 ) )
goto V_100;
F_75 ( V_50 ) ;
goto V_159;
}
V_169 = V_14 -> V_58 ;
switch ( V_169 ) {
case V_81 :
break;
case V_172 :
V_96 = - V_173 ;
goto V_101;
default:
V_96 = - V_26 ;
goto V_101;
}
F_132 ( V_14 ) ;
if ( V_14 -> V_58 != V_169 ) {
F_16 ( V_14 ) ;
F_16 ( V_50 ) ;
F_75 ( V_50 ) ;
goto V_159;
}
V_96 = F_147 ( V_14 , V_50 , V_168 ) ;
if ( V_96 ) {
F_16 ( V_14 ) ;
goto V_101;
}
F_15 ( V_14 ) ;
F_9 ( V_168 ) = V_14 ;
V_168 -> V_58 = V_172 ;
V_168 -> V_82 = V_14 -> V_82 ;
F_80 ( V_168 ) ;
V_166 = F_34 ( V_168 ) ;
F_148 ( V_168 -> V_64 , & V_166 -> V_174 ) ;
V_167 = F_34 ( V_50 ) ;
if ( V_167 -> V_2 ) {
F_149 ( & V_167 -> V_2 -> V_21 ) ;
V_166 -> V_2 = V_167 -> V_2 ;
}
if ( V_167 -> V_41 . V_40 ) {
F_150 ( & V_167 -> V_41 ) ;
V_166 -> V_41 = V_167 -> V_41 ;
}
F_86 ( V_14 , V_50 ) ;
V_13 -> V_77 = V_175 ;
V_14 -> V_58 = V_172 ;
F_15 ( V_168 ) ;
F_151 () ;
F_9 ( V_14 ) = V_168 ;
F_16 ( V_14 ) ;
F_29 ( & V_50 -> V_16 . V_53 ) ;
F_152 ( & V_50 -> V_16 , V_9 ) ;
F_30 ( & V_50 -> V_16 . V_53 ) ;
F_16 ( V_50 ) ;
V_50 -> V_176 ( V_50 ) ;
F_75 ( V_50 ) ;
return 0 ;
V_101:
if ( V_50 )
F_16 ( V_50 ) ;
V_100:
F_77 ( V_9 ) ;
if ( V_168 )
F_73 ( V_168 , 0 ) ;
if ( V_50 )
F_75 ( V_50 ) ;
return V_96 ;
}
static int F_153 ( struct V_94 * V_177 , struct V_94 * V_178 )
{
struct V_13 * V_179 = V_177 -> V_14 , * V_9 = V_178 -> V_14 ;
F_15 ( V_179 ) ;
F_15 ( V_9 ) ;
F_9 ( V_179 ) = V_9 ;
F_9 ( V_9 ) = V_179 ;
F_80 ( V_179 ) ;
F_80 ( V_9 ) ;
if ( V_179 -> V_82 != V_126 ) {
V_179 -> V_58 = V_172 ;
V_9 -> V_58 = V_172 ;
V_177 -> V_77 = V_175 ;
V_178 -> V_77 = V_175 ;
}
return 0 ;
}
static void F_154 ( const struct V_94 * V_180 ,
struct V_94 * V_181 )
{
if ( F_135 ( V_158 , & V_180 -> V_44 ) )
F_155 ( V_158 , & V_181 -> V_44 ) ;
if ( F_135 ( V_182 , & V_180 -> V_44 ) )
F_155 ( V_182 , & V_181 -> V_44 ) ;
}
static int F_156 ( struct V_94 * V_13 , struct V_94 * V_183 , int V_44 ,
bool V_106 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_184 ;
struct V_8 * V_9 ;
int V_96 ;
V_96 = - V_99 ;
if ( V_13 -> type != V_83 && V_13 -> type != V_84 )
goto V_100;
V_96 = - V_26 ;
if ( V_14 -> V_58 != V_59 )
goto V_100;
V_9 = F_157 ( V_14 , 0 , V_44 & V_170 , & V_96 ) ;
if ( ! V_9 ) {
if ( V_96 == 0 )
V_96 = - V_26 ;
goto V_100;
}
V_184 = V_9 -> V_14 ;
F_158 ( V_14 , V_9 ) ;
F_159 ( & F_34 ( V_14 ) -> V_49 ) ;
F_14 ( V_184 ) ;
V_183 -> V_77 = V_175 ;
F_154 ( V_13 , V_183 ) ;
F_160 ( V_184 , V_183 ) ;
F_16 ( V_184 ) ;
return 0 ;
V_100:
return V_96 ;
}
static int F_161 ( struct V_94 * V_13 , struct V_144 * V_145 , int * V_185 , int V_19 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 ;
F_162 ( struct V_22 * , V_23 , V_145 ) ;
int V_96 = 0 ;
if ( V_19 ) {
V_14 = F_13 ( V_14 ) ;
V_96 = - V_186 ;
if ( ! V_14 )
goto V_100;
V_96 = 0 ;
} else {
F_15 ( V_14 ) ;
}
V_35 = F_34 ( V_14 ) ;
F_14 ( V_14 ) ;
if ( ! V_35 -> V_2 ) {
V_23 -> V_27 = V_28 ;
V_23 -> V_29 [ 0 ] = 0 ;
* V_185 = sizeof( short ) ;
} else {
struct V_20 * V_2 = V_35 -> V_2 ;
* V_185 = V_2 -> V_24 ;
memcpy ( V_23 , V_2 -> V_36 , * V_185 ) ;
}
F_16 ( V_14 ) ;
F_75 ( V_14 ) ;
V_100:
return V_96 ;
}
static void F_163 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_39 ;
V_7 -> V_187 = F_3 ( V_9 ) . V_187 ;
F_3 ( V_9 ) . V_187 = NULL ;
for ( V_39 = V_7 -> V_187 -> V_188 - 1 ; V_39 >= 0 ; V_39 -- )
F_164 ( V_7 -> V_187 -> V_189 , V_7 -> V_187 -> V_187 [ V_39 ] ) ;
}
static void F_165 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_97 = F_3 ( V_9 ) . V_97 ;
if ( F_3 ( V_9 ) . V_187 )
F_163 ( & V_7 , V_9 ) ;
F_166 ( & V_7 ) ;
F_167 ( V_9 ) ;
}
static inline bool F_168 ( struct V_190 * V_191 )
{
struct V_192 * V_189 = F_169 () ;
if ( F_131 ( V_189 -> V_193 > F_170 ( V_191 , V_194 ) ) )
return ! F_171 ( V_195 ) && ! F_171 ( V_196 ) ;
return false ;
}
static int F_172 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_39 ;
unsigned char V_197 = 0 ;
if ( F_168 ( V_92 ) )
return - V_198 ;
for ( V_39 = V_7 -> V_187 -> V_188 - 1 ; V_39 >= 0 ; V_39 -- ) {
struct V_13 * V_14 = F_173 ( V_7 -> V_187 -> V_187 [ V_39 ] ) ;
if ( V_14 )
V_197 = F_174 ( V_197 ,
F_34 ( V_14 ) -> V_199 ) ;
}
if ( F_131 ( V_197 > V_200 ) )
return - V_198 ;
F_3 ( V_9 ) . V_187 = F_175 ( V_7 -> V_187 ) ;
if ( ! F_3 ( V_9 ) . V_187 )
return - V_130 ;
for ( V_39 = V_7 -> V_187 -> V_188 - 1 ; V_39 >= 0 ; V_39 -- )
V_193 ( V_7 -> V_187 -> V_189 , V_7 -> V_187 -> V_187 [ V_39 ] ) ;
return V_197 ;
}
static int F_176 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_201 )
{
int V_96 = 0 ;
F_3 ( V_9 ) . V_97 = F_83 ( V_7 -> V_97 ) ;
F_3 ( V_9 ) . V_202 = V_7 -> V_203 . V_202 ;
F_3 ( V_9 ) . V_204 = V_7 -> V_203 . V_204 ;
F_3 ( V_9 ) . V_187 = NULL ;
F_2 ( V_7 , V_9 ) ;
if ( V_7 -> V_187 && V_201 )
V_96 = F_172 ( V_7 , V_9 ) ;
V_9 -> V_205 = F_165 ;
return V_96 ;
}
static bool F_177 ( const struct V_94 * V_13 ,
const struct V_13 * V_50 )
{
return F_135 ( V_158 , & V_13 -> V_44 ) ||
! V_50 -> V_72 ||
F_135 ( V_158 , & V_50 -> V_72 -> V_44 ) ;
}
static void F_178 ( struct V_8 * V_9 , const struct V_94 * V_13 ,
const struct V_13 * V_50 )
{
if ( F_3 ( V_9 ) . V_97 )
return;
if ( F_177 ( V_13 , V_50 ) ) {
F_3 ( V_9 ) . V_97 = F_83 ( F_84 ( V_92 ) ) ;
F_179 ( & F_3 ( V_9 ) . V_202 , & F_3 ( V_9 ) . V_204 ) ;
}
}
static int F_180 ( struct V_6 * V_7 ,
struct V_94 * V_94 ,
const struct V_13 * V_50 )
{
int V_96 ;
struct V_206 V_207 = { . V_208 = 0 } ;
V_96 = F_181 ( V_94 , & V_207 , V_7 , false ) ;
if ( V_96 )
return V_96 ;
if ( F_177 ( V_94 , V_50 ) ) {
V_7 -> V_97 = F_83 ( F_84 ( V_92 ) ) ;
F_179 ( & V_7 -> V_203 . V_202 , & V_7 -> V_203 . V_204 ) ;
}
return V_96 ;
}
static bool F_182 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
const struct V_209 * V_35 = & F_3 ( V_9 ) ;
return V_35 -> V_97 == V_7 -> V_97 &&
F_183 ( V_35 -> V_202 , V_7 -> V_203 . V_202 ) &&
F_184 ( V_35 -> V_204 , V_7 -> V_203 . V_204 ) &&
F_5 ( V_7 , V_9 ) ;
}
static int F_185 ( struct V_94 * V_13 , struct V_206 * V_207 ,
T_6 V_24 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_162 ( struct V_22 * , V_23 , V_207 -> V_210 ) ;
struct V_13 * V_50 = NULL ;
int V_211 = 0 ;
int V_96 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_162 ;
struct V_6 V_7 ;
int V_197 ;
int V_212 = 0 ;
int V_213 ;
F_186 () ;
V_96 = F_181 ( V_13 , V_207 , & V_7 , false ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = - V_99 ;
if ( V_207 -> V_214 & V_215 )
goto V_100;
if ( V_207 -> V_216 ) {
V_96 = F_20 ( V_23 , V_207 -> V_216 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_211 = V_96 ;
} else {
V_23 = NULL ;
V_96 = - V_186 ;
V_50 = F_13 ( V_14 ) ;
if ( ! V_50 )
goto V_100;
}
if ( F_135 ( V_158 , & V_13 -> V_44 ) && ! V_35 -> V_2
&& ( V_96 = F_106 ( V_13 ) ) != 0 )
goto V_100;
V_96 = - V_217 ;
if ( V_24 > V_14 -> V_61 - 32 )
goto V_100;
if ( V_24 > V_218 ) {
V_212 = F_187 ( T_6 ,
V_24 - V_218 ,
V_219 * V_220 ) ;
V_212 = F_188 ( V_212 ) ;
F_189 ( V_218 < V_220 ) ;
}
V_9 = F_190 ( V_14 , V_24 - V_212 , V_212 ,
V_207 -> V_214 & V_221 , & V_96 ,
V_222 ) ;
if ( V_9 == NULL )
goto V_100;
V_96 = F_176 ( & V_7 , V_9 , true ) ;
if ( V_96 < 0 )
goto V_223;
V_197 = V_96 + 1 ;
F_191 ( V_9 , V_24 - V_212 ) ;
V_9 -> V_212 = V_212 ;
V_9 -> V_24 = V_24 ;
V_96 = F_192 ( V_9 , 0 , & V_207 -> V_224 , V_24 ) ;
if ( V_96 )
goto V_223;
V_162 = F_143 ( V_14 , V_207 -> V_214 & V_221 ) ;
V_159:
if ( ! V_50 ) {
V_96 = - V_70 ;
if ( V_23 == NULL )
goto V_223;
V_50 = F_110 ( V_32 , V_23 , V_211 , V_14 -> V_82 ,
V_3 , & V_96 ) ;
if ( V_50 == NULL )
goto V_223;
}
if ( F_193 ( V_50 , V_9 ) < 0 ) {
V_96 = V_24 ;
goto V_223;
}
V_213 = 0 ;
F_14 ( V_50 ) ;
V_225:
V_96 = - V_160 ;
if ( ! F_10 ( V_14 , V_50 ) )
goto V_101;
if ( F_131 ( F_63 ( V_50 , V_68 ) ) ) {
F_16 ( V_50 ) ;
F_75 ( V_50 ) ;
if ( ! V_213 )
F_14 ( V_14 ) ;
V_96 = 0 ;
if ( F_9 ( V_14 ) == V_50 ) {
F_9 ( V_14 ) = NULL ;
F_48 ( V_14 , V_50 ) ;
F_16 ( V_14 ) ;
F_59 ( V_14 , V_50 ) ;
F_75 ( V_50 ) ;
V_96 = - V_139 ;
} else {
F_16 ( V_14 ) ;
}
V_50 = NULL ;
if ( V_96 )
goto V_223;
goto V_159;
}
V_96 = - V_226 ;
if ( V_50 -> V_78 & V_165 )
goto V_101;
if ( V_14 -> V_82 != V_84 ) {
V_96 = F_136 ( V_14 -> V_72 , V_50 -> V_72 ) ;
if ( V_96 )
goto V_101;
}
if ( V_50 != V_14 &&
F_131 ( F_9 ( V_50 ) != V_14 && F_11 ( V_50 ) ) ) {
if ( V_162 ) {
V_162 = F_137 ( V_50 , V_162 ) ;
V_96 = F_145 ( V_162 ) ;
if ( F_146 ( V_92 ) )
goto V_223;
goto V_159;
}
if ( ! V_213 ) {
F_16 ( V_50 ) ;
F_130 ( V_14 , V_50 ) ;
}
if ( F_9 ( V_14 ) != V_50 ||
F_49 ( V_14 , V_50 ) ) {
V_96 = - V_171 ;
V_213 = 1 ;
goto V_101;
}
if ( ! V_213 ) {
V_213 = 1 ;
goto V_225;
}
}
if ( F_131 ( V_213 ) )
F_16 ( V_14 ) ;
if ( F_63 ( V_50 , V_227 ) )
F_194 ( V_9 ) ;
F_178 ( V_9 , V_13 , V_50 ) ;
F_195 ( & V_50 -> V_16 , V_9 ) ;
if ( V_197 > F_34 ( V_50 ) -> V_199 )
F_34 ( V_50 ) -> V_199 = V_197 ;
F_16 ( V_50 ) ;
V_50 -> V_176 ( V_50 ) ;
F_75 ( V_50 ) ;
F_166 ( & V_7 ) ;
return V_24 ;
V_101:
if ( V_213 )
F_16 ( V_14 ) ;
F_16 ( V_50 ) ;
V_223:
F_77 ( V_9 ) ;
V_100:
if ( V_50 )
F_75 ( V_50 ) ;
F_166 ( & V_7 ) ;
return V_96 ;
}
static int F_196 ( struct V_94 * V_13 , struct V_206 * V_207 ,
T_6 V_24 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_50 = NULL ;
int V_96 , V_228 ;
struct V_8 * V_9 ;
int V_229 = 0 ;
struct V_6 V_7 ;
bool V_230 = false ;
int V_197 ;
int V_212 ;
F_186 () ;
V_96 = F_181 ( V_13 , V_207 , & V_7 , false ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = - V_99 ;
if ( V_207 -> V_214 & V_215 )
goto V_231;
if ( V_207 -> V_216 ) {
V_96 = V_14 -> V_58 == V_172 ? - V_173 : - V_99 ;
goto V_231;
} else {
V_96 = - V_186 ;
V_50 = F_9 ( V_14 ) ;
if ( ! V_50 )
goto V_231;
}
if ( V_14 -> V_78 & V_232 )
goto V_233;
while ( V_229 < V_24 ) {
V_228 = V_24 - V_229 ;
V_228 = F_187 ( int , V_228 , ( V_14 -> V_61 >> 1 ) - 64 ) ;
V_228 = F_187 ( int , V_228 , F_197 ( 0 ) + V_234 ) ;
V_212 = F_198 ( int , 0 , V_228 - F_197 ( 0 ) ) ;
V_212 = F_187 ( T_6 , V_228 , F_188 ( V_212 ) ) ;
V_9 = F_190 ( V_14 , V_228 - V_212 , V_212 ,
V_207 -> V_214 & V_221 , & V_96 ,
F_199 ( V_234 ) ) ;
if ( ! V_9 )
goto V_231;
V_96 = F_176 ( & V_7 , V_9 , ! V_230 ) ;
if ( V_96 < 0 ) {
F_77 ( V_9 ) ;
goto V_231;
}
V_197 = V_96 + 1 ;
V_230 = true ;
F_191 ( V_9 , V_228 - V_212 ) ;
V_9 -> V_212 = V_212 ;
V_9 -> V_24 = V_228 ;
V_96 = F_192 ( V_9 , 0 , & V_207 -> V_224 , V_228 ) ;
if ( V_96 ) {
F_77 ( V_9 ) ;
goto V_231;
}
F_14 ( V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ||
( V_50 -> V_78 & V_165 ) )
goto V_235;
F_178 ( V_9 , V_13 , V_50 ) ;
F_195 ( & V_50 -> V_16 , V_9 ) ;
if ( V_197 > F_34 ( V_50 ) -> V_199 )
F_34 ( V_50 ) -> V_199 = V_197 ;
F_16 ( V_50 ) ;
V_50 -> V_176 ( V_50 ) ;
V_229 += V_228 ;
}
F_166 ( & V_7 ) ;
return V_229 ;
V_235:
F_16 ( V_50 ) ;
F_77 ( V_9 ) ;
V_233:
if ( V_229 == 0 && ! ( V_207 -> V_214 & V_236 ) )
F_200 ( V_237 , V_92 , 0 ) ;
V_96 = - V_226 ;
V_231:
F_166 ( & V_7 ) ;
return V_229 ? : V_96 ;
}
static T_7 F_201 ( struct V_94 * V_94 , struct V_238 * V_238 ,
int V_239 , T_6 V_228 , int V_44 )
{
int V_96 ;
bool V_240 = false ;
bool V_241 = true ;
struct V_6 V_7 ;
struct V_13 * V_50 , * V_14 = V_94 -> V_14 ;
struct V_8 * V_9 , * V_242 = NULL , * V_243 = NULL ;
if ( V_44 & V_215 )
return - V_99 ;
V_50 = F_9 ( V_14 ) ;
if ( ! V_50 || V_14 -> V_58 != V_172 )
return - V_186 ;
if ( false ) {
V_244:
F_16 ( V_50 ) ;
F_91 ( & F_34 ( V_50 ) -> V_103 ) ;
V_242 = F_190 ( V_14 , 0 , 0 , V_44 & V_221 ,
& V_96 , 0 ) ;
if ( ! V_242 )
goto V_96;
}
V_96 = F_90 ( & F_34 ( V_50 ) -> V_103 ) ;
if ( V_96 ) {
V_96 = V_44 & V_221 ? - V_171 : - V_245 ;
goto V_96;
}
if ( V_14 -> V_78 & V_232 ) {
V_96 = - V_226 ;
V_240 = true ;
goto V_246;
}
F_14 ( V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ||
V_50 -> V_78 & V_165 ) {
V_96 = - V_226 ;
V_240 = true ;
goto V_247;
}
if ( V_241 ) {
V_96 = F_180 ( & V_7 , V_94 , V_50 ) ;
if ( V_96 )
goto V_247;
V_241 = false ;
}
V_9 = F_202 ( & V_50 -> V_16 ) ;
if ( V_243 && V_243 == V_9 ) {
V_9 = V_242 ;
} else if ( ! V_9 || ! F_182 ( V_9 , & V_7 ) ) {
if ( V_242 ) {
V_9 = V_242 ;
} else {
V_243 = V_9 ;
goto V_244;
}
} else if ( V_242 ) {
F_203 ( V_242 ) ;
V_242 = NULL ;
}
if ( F_204 ( V_9 , V_238 , V_239 , V_228 ) ) {
V_243 = V_9 ;
goto V_244;
}
V_9 -> V_24 += V_228 ;
V_9 -> V_212 += V_228 ;
V_9 -> V_248 += V_228 ;
F_205 ( V_228 , & V_14 -> V_60 ) ;
if ( V_242 ) {
V_96 = F_176 ( & V_7 , V_9 , false ) ;
if ( V_96 )
goto V_247;
F_29 ( & V_50 -> V_16 . V_53 ) ;
F_152 ( & V_50 -> V_16 , V_242 ) ;
F_30 ( & V_50 -> V_16 . V_53 ) ;
}
F_16 ( V_50 ) ;
F_91 ( & F_34 ( V_50 ) -> V_103 ) ;
V_50 -> V_176 ( V_50 ) ;
F_166 ( & V_7 ) ;
return V_228 ;
V_247:
F_16 ( V_50 ) ;
V_246:
F_91 ( & F_34 ( V_50 ) -> V_103 ) ;
V_96:
F_77 ( V_242 ) ;
if ( V_240 && ! ( V_44 & V_236 ) )
F_200 ( V_237 , V_92 , 0 ) ;
if ( ! V_241 )
F_166 ( & V_7 ) ;
return V_96 ;
}
static int F_206 ( struct V_94 * V_13 , struct V_206 * V_207 ,
T_6 V_24 )
{
int V_96 ;
struct V_13 * V_14 = V_13 -> V_14 ;
V_96 = F_207 ( V_14 ) ;
if ( V_96 )
return V_96 ;
if ( V_14 -> V_58 != V_172 )
return - V_186 ;
if ( V_207 -> V_216 )
V_207 -> V_216 = 0 ;
return F_185 ( V_13 , V_207 , V_24 ) ;
}
static int F_208 ( struct V_94 * V_13 , struct V_206 * V_207 ,
T_6 V_228 , int V_44 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
if ( V_14 -> V_58 != V_172 )
return - V_186 ;
return F_209 ( V_13 , V_207 , V_228 , V_44 ) ;
}
static void F_210 ( struct V_206 * V_207 , struct V_13 * V_14 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
if ( V_35 -> V_2 ) {
V_207 -> V_216 = V_35 -> V_2 -> V_24 ;
memcpy ( V_207 -> V_210 , V_35 -> V_2 -> V_36 , V_35 -> V_2 -> V_24 ) ;
}
}
static int F_209 ( struct V_94 * V_13 , struct V_206 * V_207 ,
T_6 V_228 , int V_44 )
{
struct V_6 V_7 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_8 * V_9 , * V_249 ;
long V_162 ;
int V_96 ;
int V_250 , V_251 ;
V_96 = - V_99 ;
if ( V_44 & V_215 )
goto V_100;
V_162 = F_211 ( V_14 , V_44 & V_221 ) ;
do {
F_212 ( & V_35 -> V_103 ) ;
V_251 = F_213 ( V_14 , V_44 ) ;
V_9 = F_214 ( V_14 , V_44 , NULL , & V_250 , & V_251 ,
& V_96 , & V_249 ) ;
if ( V_9 )
break;
F_91 ( & V_35 -> V_103 ) ;
if ( V_96 != - V_171 )
break;
} while ( V_162 &&
! F_215 ( V_14 , & V_96 , & V_162 , V_249 ) );
if ( ! V_9 ) {
F_14 ( V_14 ) ;
if ( V_14 -> V_82 == V_84 && V_96 == - V_171 &&
( V_14 -> V_78 & V_165 ) )
V_96 = 0 ;
F_16 ( V_14 ) ;
goto V_100;
}
if ( F_216 ( & V_35 -> V_49 ) )
F_56 ( & V_35 -> V_49 ,
V_54 | V_55 |
V_56 ) ;
if ( V_207 -> V_210 )
F_210 ( V_207 , V_9 -> V_14 ) ;
if ( V_228 > V_9 -> V_24 - V_251 )
V_228 = V_9 -> V_24 - V_251 ;
else if ( V_228 < V_9 -> V_24 - V_251 )
V_207 -> V_214 |= V_252 ;
V_96 = F_217 ( V_9 , V_251 , V_207 , V_228 ) ;
if ( V_96 )
goto V_223;
if ( F_63 ( V_14 , V_227 ) )
F_218 ( V_207 , V_14 , V_9 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_219 ( & V_7 , F_3 ( V_9 ) . V_97 , F_3 ( V_9 ) . V_202 , F_3 ( V_9 ) . V_204 ) ;
F_4 ( & V_7 , V_9 ) ;
if ( ! ( V_44 & V_253 ) ) {
if ( F_3 ( V_9 ) . V_187 )
F_163 ( & V_7 , V_9 ) ;
F_220 ( V_14 , V_9 -> V_24 ) ;
} else {
F_221 ( V_14 , V_228 ) ;
if ( F_3 ( V_9 ) . V_187 )
V_7 . V_187 = F_175 ( F_3 ( V_9 ) . V_187 ) ;
}
V_96 = ( V_44 & V_252 ) ? V_9 -> V_24 - V_251 : V_228 ;
F_222 ( V_13 , V_207 , & V_7 , V_44 ) ;
V_223:
F_158 ( V_14 , V_9 ) ;
F_91 ( & V_35 -> V_103 ) ;
V_100:
return V_96 ;
}
static long F_223 ( struct V_13 * V_14 , long V_162 ,
struct V_8 * V_249 , unsigned int V_254 ,
bool V_255 )
{
struct V_8 * V_243 ;
F_138 ( V_65 ) ;
F_14 ( V_14 ) ;
for (; ; ) {
F_224 ( F_43 ( V_14 ) , & V_65 , V_164 ) ;
V_243 = F_202 ( & V_14 -> V_16 ) ;
if ( V_243 != V_249 ||
( V_243 && V_243 -> V_24 != V_254 ) ||
V_14 -> V_69 ||
( V_14 -> V_78 & V_165 ) ||
F_146 ( V_92 ) ||
! V_162 )
break;
F_225 ( V_256 , V_14 ) ;
F_16 ( V_14 ) ;
if ( V_255 )
V_162 = F_226 ( V_162 ) ;
else
V_162 = F_140 ( V_162 ) ;
F_14 ( V_14 ) ;
if ( F_63 ( V_14 , V_68 ) )
break;
F_227 ( V_256 , V_14 ) ;
}
F_141 ( F_43 ( V_14 ) , & V_65 ) ;
F_16 ( V_14 ) ;
return V_162 ;
}
static unsigned int F_228 ( const struct V_8 * V_9 )
{
return V_9 -> V_24 - F_3 ( V_9 ) . V_88 ;
}
static int F_229 ( struct V_257 * V_77 ,
bool V_255 )
{
struct V_6 V_7 ;
struct V_94 * V_13 = V_77 -> V_94 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
int V_258 = 0 ;
int V_44 = V_77 -> V_44 ;
int V_259 = V_44 & V_221 ;
bool V_260 = false ;
int V_261 ;
int V_96 = 0 ;
long V_162 ;
int V_251 ;
T_6 V_228 = V_77 -> V_228 ;
unsigned int V_254 ;
if ( F_131 ( V_14 -> V_58 != V_172 ) ) {
V_96 = - V_26 ;
goto V_100;
}
if ( F_131 ( V_44 & V_215 ) ) {
V_96 = - V_99 ;
goto V_100;
}
V_261 = F_230 ( V_14 , V_44 & V_262 , V_228 ) ;
V_162 = F_211 ( V_14 , V_259 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_212 ( & V_35 -> V_103 ) ;
V_251 = F_174 ( F_213 ( V_14 , V_44 ) , 0 ) ;
do {
int V_263 ;
bool V_264 ;
struct V_8 * V_9 , * V_249 ;
V_265:
F_14 ( V_14 ) ;
if ( F_63 ( V_14 , V_68 ) ) {
V_96 = - V_70 ;
goto V_266;
}
V_249 = V_9 = F_231 ( & V_14 -> V_16 ) ;
V_254 = V_249 ? V_249 -> V_24 : 0 ;
V_267:
if ( V_9 == NULL ) {
F_34 ( V_14 ) -> V_199 = 0 ;
if ( V_258 >= V_261 )
goto V_266;
V_96 = F_207 ( V_14 ) ;
if ( V_96 )
goto V_266;
if ( V_14 -> V_78 & V_165 )
goto V_266;
F_16 ( V_14 ) ;
if ( ! V_162 ) {
V_96 = - V_171 ;
break;
}
F_91 ( & V_35 -> V_103 ) ;
V_162 = F_223 ( V_14 , V_162 , V_249 ,
V_254 , V_255 ) ;
if ( F_146 ( V_92 ) ) {
V_96 = F_145 ( V_162 ) ;
F_166 ( & V_7 ) ;
goto V_100;
}
F_212 ( & V_35 -> V_103 ) ;
goto V_265;
V_266:
F_16 ( V_14 ) ;
break;
}
while ( V_251 >= F_228 ( V_9 ) ) {
V_251 -= F_228 ( V_9 ) ;
V_249 = V_9 ;
V_254 = V_9 -> V_24 ;
V_9 = F_232 ( V_9 , & V_14 -> V_16 ) ;
if ( ! V_9 )
goto V_267;
}
F_16 ( V_14 ) ;
if ( V_260 ) {
if ( ! F_182 ( V_9 , & V_7 ) )
break;
} else if ( F_135 ( V_158 , & V_13 -> V_44 ) ) {
F_219 ( & V_7 , F_3 ( V_9 ) . V_97 , F_3 ( V_9 ) . V_202 , F_3 ( V_9 ) . V_204 ) ;
F_4 ( & V_7 , V_9 ) ;
V_260 = true ;
}
if ( V_77 -> V_207 && V_77 -> V_207 -> V_210 ) {
F_162 ( struct V_22 * , V_23 ,
V_77 -> V_207 -> V_210 ) ;
F_210 ( V_77 -> V_207 , V_9 -> V_14 ) ;
V_23 = NULL ;
}
V_263 = F_187 (unsigned int, unix_skb_len(skb) - skip, size) ;
F_233 ( V_9 ) ;
V_263 = V_77 -> V_268 ( V_9 , V_251 , V_263 , V_77 ) ;
V_264 = ! F_228 ( V_9 ) ;
F_203 ( V_9 ) ;
if ( V_263 < 0 ) {
if ( V_258 == 0 )
V_258 = - V_269 ;
break;
}
V_258 += V_263 ;
V_228 -= V_263 ;
if ( V_264 ) {
V_96 = 0 ;
break;
}
if ( ! ( V_44 & V_253 ) ) {
F_3 ( V_9 ) . V_88 += V_263 ;
F_220 ( V_14 , V_263 ) ;
if ( F_3 ( V_9 ) . V_187 )
F_163 ( & V_7 , V_9 ) ;
if ( F_228 ( V_9 ) )
break;
F_234 ( V_9 , & V_14 -> V_16 ) ;
F_203 ( V_9 ) ;
if ( V_7 . V_187 )
break;
} else {
if ( F_3 ( V_9 ) . V_187 )
V_7 . V_187 = F_175 ( F_3 ( V_9 ) . V_187 ) ;
F_221 ( V_14 , V_263 ) ;
if ( F_3 ( V_9 ) . V_187 )
break;
V_251 = 0 ;
V_249 = V_9 ;
V_254 = V_9 -> V_24 ;
F_14 ( V_14 ) ;
V_9 = F_232 ( V_9 , & V_14 -> V_16 ) ;
if ( V_9 )
goto V_267;
F_16 ( V_14 ) ;
break;
}
} while ( V_228 );
F_91 ( & V_35 -> V_103 ) ;
if ( V_77 -> V_207 )
F_222 ( V_13 , V_77 -> V_207 , & V_7 , V_44 ) ;
else
F_166 ( & V_7 ) ;
V_100:
return V_258 ? : V_96 ;
}
static int F_235 ( struct V_8 * V_9 ,
int V_251 , int V_263 ,
struct V_257 * V_77 )
{
int V_270 ;
V_270 = F_217 ( V_9 , F_3 ( V_9 ) . V_88 + V_251 ,
V_77 -> V_207 , V_263 ) ;
return V_270 ? : V_263 ;
}
static int F_236 ( struct V_94 * V_13 , struct V_206 * V_207 ,
T_6 V_228 , int V_44 )
{
struct V_257 V_77 = {
. V_268 = F_235 ,
. V_94 = V_13 ,
. V_207 = V_207 ,
. V_228 = V_228 ,
. V_44 = V_44
} ;
return F_229 ( & V_77 , true ) ;
}
static int F_237 ( struct V_8 * V_9 ,
int V_251 , int V_263 ,
struct V_257 * V_77 )
{
return F_238 ( V_9 , V_77 -> V_94 -> V_14 ,
F_3 ( V_9 ) . V_88 + V_251 ,
V_77 -> V_271 , V_263 , V_77 -> V_272 ) ;
}
static T_7 F_239 ( struct V_94 * V_13 , T_8 * V_273 ,
struct V_274 * V_271 ,
T_6 V_228 , unsigned int V_44 )
{
struct V_257 V_77 = {
. V_268 = F_237 ,
. V_94 = V_13 ,
. V_271 = V_271 ,
. V_228 = V_228 ,
. V_272 = V_44 ,
} ;
if ( F_131 ( * V_273 ) )
return - V_275 ;
if ( V_13 -> V_276 -> V_277 & V_170 ||
V_44 & V_278 )
V_77 . V_44 = V_221 ;
return F_229 ( & V_77 , false ) ;
}
static int F_240 ( struct V_94 * V_13 , int V_43 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_50 ;
if ( V_43 < V_279 || V_43 > V_280 )
return - V_26 ;
++ V_43 ;
F_14 ( V_14 ) ;
V_14 -> V_78 |= V_43 ;
V_50 = F_9 ( V_14 ) ;
if ( V_50 )
F_15 ( V_50 ) ;
F_16 ( V_14 ) ;
V_14 -> V_85 ( V_14 ) ;
if ( V_50 &&
( V_14 -> V_82 == V_83 || V_14 -> V_82 == V_84 ) ) {
int V_281 = 0 ;
if ( V_43 & V_165 )
V_281 |= V_232 ;
if ( V_43 & V_232 )
V_281 |= V_165 ;
F_14 ( V_50 ) ;
V_50 -> V_78 |= V_281 ;
F_16 ( V_50 ) ;
V_50 -> V_85 ( V_50 ) ;
if ( V_281 == V_79 )
F_57 ( V_50 , V_86 , V_87 ) ;
else if ( V_281 & V_165 )
F_57 ( V_50 , V_86 , V_282 ) ;
}
if ( V_50 )
F_75 ( V_50 ) ;
return 0 ;
}
long F_241 ( struct V_13 * V_14 )
{
struct V_8 * V_9 ;
long V_283 = 0 ;
if ( V_14 -> V_58 == V_59 )
return - V_26 ;
F_29 ( & V_14 -> V_16 . V_53 ) ;
if ( V_14 -> V_82 == V_83 ||
V_14 -> V_82 == V_84 ) {
F_242 (&sk->sk_receive_queue, skb)
V_283 += F_228 ( V_9 ) ;
} else {
V_9 = F_231 ( & V_14 -> V_16 ) ;
if ( V_9 )
V_283 = V_9 -> V_24 ;
}
F_30 ( & V_14 -> V_16 . V_53 ) ;
return V_283 ;
}
long F_243 ( struct V_13 * V_14 )
{
return F_244 ( V_14 ) ;
}
static int F_245 ( struct V_13 * V_14 )
{
struct V_41 V_41 ;
struct V_276 * V_284 ;
int V_285 ;
if ( ! F_246 ( F_36 ( V_14 ) -> V_286 , V_287 ) )
return - V_160 ;
F_14 ( V_14 ) ;
V_41 = F_34 ( V_14 ) -> V_41 ;
if ( ! V_41 . V_40 ) {
F_16 ( V_14 ) ;
return - V_288 ;
}
F_150 ( & V_41 ) ;
F_16 ( V_14 ) ;
V_285 = F_247 ( V_289 ) ;
if ( V_285 < 0 )
goto V_100;
V_284 = F_248 ( & V_41 , V_290 , F_249 () ) ;
if ( F_118 ( V_284 ) ) {
F_250 ( V_285 ) ;
V_285 = F_117 ( V_284 ) ;
goto V_100;
}
F_251 ( V_285 , V_284 ) ;
V_100:
F_78 ( & V_41 ) ;
return V_285 ;
}
static int F_252 ( struct V_94 * V_13 , unsigned int V_291 , unsigned long V_292 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
long V_283 = 0 ;
int V_96 ;
switch ( V_291 ) {
case V_293 :
V_283 = F_243 ( V_14 ) ;
V_96 = F_253 ( V_283 , ( int V_294 * ) V_292 ) ;
break;
case V_295 :
V_283 = F_241 ( V_14 ) ;
if ( V_283 < 0 )
V_96 = V_283 ;
else
V_96 = F_253 ( V_283 , ( int V_294 * ) V_292 ) ;
break;
case V_296 :
V_96 = F_245 ( V_14 ) ;
break;
default:
V_96 = - V_297 ;
break;
}
return V_96 ;
}
static unsigned int F_254 ( struct V_276 * V_276 , struct V_94 * V_13 , T_9 * V_65 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
unsigned int V_298 ;
F_255 ( V_276 , F_43 ( V_14 ) , V_65 ) ;
V_298 = 0 ;
if ( V_14 -> V_69 )
V_298 |= V_299 ;
if ( V_14 -> V_78 == V_79 )
V_298 |= V_300 ;
if ( V_14 -> V_78 & V_165 )
V_298 |= V_301 | V_302 | V_303 ;
if ( ! F_60 ( & V_14 -> V_16 ) )
V_298 |= V_302 | V_303 ;
if ( ( V_14 -> V_82 == V_83 || V_14 -> V_82 == V_84 ) &&
V_14 -> V_58 == V_81 )
V_298 |= V_300 ;
if ( F_50 ( V_14 ) )
V_298 |= V_54 | V_55 | V_56 ;
return V_298 ;
}
static unsigned int F_256 ( struct V_276 * V_276 , struct V_94 * V_13 ,
T_9 * V_65 )
{
struct V_13 * V_14 = V_13 -> V_14 , * V_50 ;
unsigned int V_298 , V_304 ;
F_255 ( V_276 , F_43 ( V_14 ) , V_65 ) ;
V_298 = 0 ;
if ( V_14 -> V_69 || ! F_60 ( & V_14 -> V_305 ) )
V_298 |= V_299 |
( F_63 ( V_14 , V_306 ) ? V_307 : 0 ) ;
if ( V_14 -> V_78 & V_165 )
V_298 |= V_301 | V_302 | V_303 ;
if ( V_14 -> V_78 == V_79 )
V_298 |= V_300 ;
if ( ! F_60 ( & V_14 -> V_16 ) )
V_298 |= V_302 | V_303 ;
if ( V_14 -> V_82 == V_84 ) {
if ( V_14 -> V_58 == V_81 )
V_298 |= V_300 ;
if ( V_14 -> V_58 == V_308 )
return V_298 ;
}
if ( ! ( F_257 ( V_65 ) & ( V_56 | V_55 | V_54 ) ) )
return V_298 ;
V_304 = F_50 ( V_14 ) ;
if ( V_304 ) {
F_14 ( V_14 ) ;
V_50 = F_9 ( V_14 ) ;
if ( V_50 && F_9 ( V_50 ) != V_14 &&
F_11 ( V_50 ) &&
F_49 ( V_14 , V_50 ) )
V_304 = 0 ;
F_16 ( V_14 ) ;
}
if ( V_304 )
V_298 |= V_54 | V_55 | V_56 ;
else
F_225 ( V_309 , V_14 ) ;
return V_298 ;
}
static struct V_13 * F_258 ( struct V_310 * V_311 , T_8 * V_312 )
{
unsigned long V_239 = F_259 ( * V_312 ) ;
unsigned long V_313 = F_260 ( * V_312 ) ;
struct V_13 * V_14 ;
unsigned long V_188 = 0 ;
for ( V_14 = F_261 ( & V_5 [ V_313 ] ) ; V_14 ; V_14 = F_262 ( V_14 ) ) {
if ( F_36 ( V_14 ) != F_263 ( V_311 ) )
continue;
if ( ++ V_188 == V_239 )
break;
}
return V_14 ;
}
static struct V_13 * F_264 ( struct V_310 * V_311 ,
struct V_13 * V_14 ,
T_8 * V_312 )
{
unsigned long V_313 ;
while ( V_14 > (struct V_13 * ) V_314 ) {
V_14 = F_262 ( V_14 ) ;
if ( ! V_14 )
goto V_315;
if ( F_36 ( V_14 ) == F_263 ( V_311 ) )
return V_14 ;
}
do {
V_14 = F_258 ( V_311 , V_312 ) ;
if ( V_14 )
return V_14 ;
V_315:
V_313 = F_260 ( * V_312 ) + 1 ;
* V_312 = F_265 ( V_313 , 1 ) ;
} while ( V_313 < F_266 ( V_5 ) );
return NULL ;
}
static void * F_267 ( struct V_310 * V_311 , T_8 * V_312 )
__acquires( V_31 )
{
F_29 ( & V_31 ) ;
if ( ! * V_312 )
return V_314 ;
if ( F_260 ( * V_312 ) >= F_266 ( V_5 ) )
return NULL ;
return F_264 ( V_311 , NULL , V_312 ) ;
}
static void * F_268 ( struct V_310 * V_311 , void * V_316 , T_8 * V_312 )
{
++ * V_312 ;
return F_264 ( V_311 , V_316 , V_312 ) ;
}
static void F_269 ( struct V_310 * V_311 , void * V_316 )
__releases( V_31 )
{
F_30 ( & V_31 ) ;
}
static int F_270 ( struct V_310 * V_311 , void * V_316 )
{
if ( V_316 == V_314 )
F_271 ( V_311 , L_4
L_5 ) ;
else {
struct V_13 * V_18 = V_316 ;
struct V_34 * V_35 = F_34 ( V_18 ) ;
F_14 ( V_18 ) ;
F_272 ( V_311 , L_6 ,
V_18 ,
F_51 ( & V_18 -> V_317 ) ,
0 ,
V_18 -> V_58 == V_59 ? V_318 : 0 ,
V_18 -> V_82 ,
V_18 -> V_72 ?
( V_18 -> V_58 == V_172 ? V_175 : V_122 ) :
( V_18 -> V_58 == V_172 ? V_319 : V_320 ) ,
F_273 ( V_18 ) ) ;
if ( V_35 -> V_2 ) {
int V_39 , V_24 ;
F_274 ( V_311 , ' ' ) ;
V_39 = 0 ;
V_24 = V_35 -> V_2 -> V_24 - sizeof( short ) ;
if ( ! F_275 ( V_18 ) )
V_24 -- ;
else {
F_274 ( V_311 , '@' ) ;
V_39 ++ ;
}
for ( ; V_39 < V_24 ; V_39 ++ )
F_274 ( V_311 , V_35 -> V_2 -> V_36 -> V_29 [ V_39 ] ? :
'@' ) ;
}
F_16 ( V_18 ) ;
F_274 ( V_311 , '\n' ) ;
}
return 0 ;
}
static int F_276 ( struct V_38 * V_38 , struct V_276 * V_276 )
{
return F_277 ( V_38 , V_276 , & V_321 ,
sizeof( struct V_322 ) ) ;
}
static int T_10 F_278 ( struct V_32 * V_32 )
{
int error = - V_130 ;
V_32 -> V_114 . V_115 = 10 ;
if ( F_279 ( V_32 ) )
goto V_100;
#ifdef F_280
if ( ! F_281 ( L_7 , 0 , V_32 -> V_323 , & V_324 ) ) {
F_282 ( V_32 ) ;
goto V_100;
}
#endif
error = 0 ;
V_100:
return error ;
}
static void T_11 F_283 ( struct V_32 * V_32 )
{
F_282 ( V_32 ) ;
F_284 ( L_7 , V_32 -> V_323 ) ;
}
static int T_12 F_285 ( void )
{
int V_52 = - 1 ;
F_189 ( sizeof( struct V_209 ) > F_286 ( struct V_8 , V_325 ) ) ;
V_52 = F_287 ( & V_109 , 1 ) ;
if ( V_52 != 0 ) {
F_288 ( L_8 , V_326 ) ;
goto V_100;
}
F_289 ( & V_327 ) ;
F_290 ( & V_328 ) ;
V_100:
return V_52 ;
}
static void T_13 F_291 ( void )
{
F_292 ( V_107 ) ;
F_293 ( & V_109 ) ;
F_294 ( & V_328 ) ;
}
