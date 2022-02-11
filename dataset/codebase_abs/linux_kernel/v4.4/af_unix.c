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
V_14 -> V_111 = F_52 ;
V_14 -> V_17 = V_32 -> V_112 . V_113 ;
V_14 -> V_114 = F_64 ;
V_35 = F_34 ( V_14 ) ;
V_35 -> V_41 . V_40 = NULL ;
V_35 -> V_41 . V_80 = NULL ;
F_98 ( & V_35 -> V_53 ) ;
F_99 ( & V_35 -> V_115 , 0 ) ;
F_100 ( & V_35 -> V_116 ) ;
F_101 ( & V_35 -> V_103 ) ;
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
static int F_104 ( struct V_32 * V_32 , struct V_94 * V_13 , int V_117 ,
int V_106 )
{
if ( V_117 && V_117 != V_107 )
return - V_118 ;
V_13 -> V_77 = V_119 ;
switch ( V_13 -> type ) {
case V_83 :
V_13 -> V_120 = & V_121 ;
break;
case V_122 :
V_13 -> type = V_123 ;
case V_123 :
V_13 -> V_120 = & V_124 ;
break;
case V_84 :
V_13 -> V_120 = & V_125 ;
break;
default:
return - V_126 ;
}
return F_92 ( V_32 , V_13 , V_106 ) ? 0 : - V_127 ;
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
static T_4 V_128 = 1 ;
struct V_20 * V_2 ;
int V_96 ;
unsigned int V_129 = 0 ;
V_96 = F_90 ( & V_35 -> V_103 ) ;
if ( V_96 )
return V_96 ;
V_96 = 0 ;
if ( V_35 -> V_2 )
goto V_100;
V_96 = - V_127 ;
V_2 = F_107 ( sizeof( * V_2 ) + sizeof( short ) + 16 , V_108 ) ;
if ( ! V_2 )
goto V_100;
V_2 -> V_36 -> V_27 = V_28 ;
F_108 ( & V_2 -> V_21 , 1 ) ;
V_130:
V_2 -> V_24 = sprintf ( V_2 -> V_36 -> V_29 + 1 , L_3 , V_128 ) + 1 + sizeof( short ) ;
V_2 -> V_3 = F_6 ( F_21 ( V_2 -> V_36 , V_2 -> V_24 , 0 ) ) ;
F_29 ( & V_31 ) ;
V_128 = ( V_128 + 1 ) & 0xFFFFF ;
if ( F_32 ( V_32 , V_2 -> V_36 , V_2 -> V_24 , V_13 -> type ,
V_2 -> V_3 ) ) {
F_30 ( & V_31 ) ;
F_109 () ;
if ( V_129 ++ == 0xFFFFF ) {
V_96 = - V_131 ;
F_19 ( V_2 ) ;
goto V_100;
}
goto V_130;
}
V_2 -> V_3 ^= V_14 -> V_82 ;
F_22 ( V_14 ) ;
V_35 -> V_2 = V_2 ;
F_24 ( & V_5 [ V_2 -> V_3 ] , V_14 ) ;
F_30 ( & V_31 ) ;
V_96 = 0 ;
V_100: F_91 ( & V_35 -> V_103 ) ;
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
V_96 = F_111 ( V_33 -> V_29 , V_132 , & V_41 ) ;
if ( V_96 )
goto V_133;
V_38 = F_39 ( V_41 . V_40 ) ;
V_96 = F_112 ( V_38 , V_134 ) ;
if ( V_96 )
goto V_135;
V_96 = - V_136 ;
if ( ! F_113 ( V_38 -> V_137 ) )
goto V_135;
V_35 = F_38 ( V_38 ) ;
if ( ! V_35 )
goto V_135;
if ( V_35 -> V_82 == type )
F_114 ( & V_41 ) ;
F_78 ( & V_41 ) ;
V_96 = - V_138 ;
if ( V_35 -> V_82 != type ) {
F_75 ( V_35 ) ;
goto V_133;
}
} else {
V_96 = - V_136 ;
V_35 = F_37 ( V_32 , V_33 , V_24 , type , V_3 ) ;
if ( V_35 ) {
struct V_40 * V_40 ;
V_40 = F_34 ( V_35 ) -> V_41 . V_40 ;
if ( V_40 )
F_114 ( & F_34 ( V_35 ) -> V_41 ) ;
} else
goto V_133;
}
return V_35 ;
V_135:
F_78 ( & V_41 ) ;
V_133:
* error = V_96 ;
return NULL ;
}
static int F_115 ( struct V_40 * V_40 , struct V_41 * V_41 , T_5 V_43 ,
struct V_41 * V_139 )
{
int V_96 ;
V_96 = F_116 ( V_41 , V_40 , V_43 , 0 ) ;
if ( ! V_96 ) {
V_96 = F_117 ( F_118 ( V_41 -> V_40 ) , V_40 , V_43 , 0 ) ;
if ( ! V_96 ) {
V_139 -> V_80 = F_119 ( V_41 -> V_80 ) ;
V_139 -> V_40 = F_120 ( V_40 ) ;
}
}
return V_96 ;
}
static int F_121 ( struct V_94 * V_13 , struct V_140 * V_141 , int V_142 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_22 * V_23 = (struct V_22 * ) V_141 ;
char * V_29 = V_23 -> V_29 ;
int V_96 , V_143 ;
unsigned int V_3 ;
struct V_20 * V_2 ;
struct V_1 * V_30 ;
struct V_41 V_41 ;
struct V_40 * V_40 ;
V_96 = - V_26 ;
if ( V_23 -> V_27 != V_28 )
goto V_100;
if ( V_142 == sizeof( short ) ) {
V_96 = F_106 ( V_13 ) ;
goto V_100;
}
V_96 = F_20 ( V_23 , V_142 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_142 = V_96 ;
V_143 = 0 ;
V_40 = NULL ;
if ( V_29 [ 0 ] ) {
V_40 = F_122 ( V_144 , V_29 , & V_41 , 0 ) ;
if ( F_123 ( V_40 ) ) {
V_143 = F_124 ( V_40 ) ;
V_40 = NULL ;
}
}
V_96 = F_90 ( & V_35 -> V_103 ) ;
if ( V_96 )
goto V_145;
V_96 = - V_26 ;
if ( V_35 -> V_2 )
goto V_146;
if ( V_143 ) {
V_96 = V_143 == - V_147 ? - V_148 : V_143 ;
goto V_146;
}
V_96 = - V_127 ;
V_2 = F_125 ( sizeof( * V_2 ) + V_142 , V_108 ) ;
if ( ! V_2 )
goto V_146;
memcpy ( V_2 -> V_36 , V_23 , V_142 ) ;
V_2 -> V_24 = V_142 ;
V_2 -> V_3 = V_3 ^ V_14 -> V_82 ;
F_108 ( & V_2 -> V_21 , 1 ) ;
if ( V_40 ) {
struct V_41 V_149 ;
T_5 V_43 = V_150 |
( F_126 ( V_13 ) -> V_137 & ~ F_127 () ) ;
V_96 = F_115 ( V_40 , & V_41 , V_43 , & V_149 ) ;
if ( V_96 ) {
if ( V_96 == - V_147 )
V_96 = - V_148 ;
F_17 ( V_2 ) ;
goto V_146;
}
V_2 -> V_3 = V_4 ;
V_3 = F_39 ( V_40 ) -> V_151 & ( V_4 - 1 ) ;
F_29 ( & V_31 ) ;
V_35 -> V_41 = V_149 ;
V_30 = & V_5 [ V_3 ] ;
} else {
F_29 ( & V_31 ) ;
V_96 = - V_148 ;
if ( F_32 ( V_32 , V_23 , V_142 ,
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
V_146:
F_91 ( & V_35 -> V_103 ) ;
V_145:
if ( V_40 )
F_128 ( & V_41 , V_40 ) ;
V_100:
return V_96 ;
}
static void F_129 ( struct V_13 * V_152 , struct V_13 * V_153 )
{
if ( F_130 ( V_152 == V_153 ) || ! V_153 ) {
F_14 ( V_152 ) ;
return;
}
if ( V_152 < V_153 ) {
F_14 ( V_152 ) ;
F_131 ( V_153 ) ;
} else {
F_14 ( V_153 ) ;
F_131 ( V_152 ) ;
}
}
static void F_132 ( struct V_13 * V_152 , struct V_13 * V_153 )
{
if ( F_130 ( V_152 == V_153 ) || ! V_153 ) {
F_16 ( V_152 ) ;
return;
}
F_16 ( V_152 ) ;
F_16 ( V_153 ) ;
}
static int F_133 ( struct V_94 * V_13 , struct V_140 * V_2 ,
int V_154 , int V_44 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_22 * V_23 = (struct V_22 * ) V_2 ;
struct V_13 * V_50 ;
unsigned int V_3 ;
int V_96 ;
if ( V_2 -> V_155 != V_156 ) {
V_96 = F_20 ( V_23 , V_154 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_154 = V_96 ;
if ( F_134 ( V_157 , & V_13 -> V_44 ) &&
! F_34 ( V_14 ) -> V_2 && ( V_96 = F_106 ( V_13 ) ) != 0 )
goto V_100;
V_158:
V_50 = F_110 ( V_32 , V_23 , V_154 , V_13 -> type , V_3 , & V_96 ) ;
if ( ! V_50 )
goto V_100;
F_129 ( V_14 , V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ) {
F_132 ( V_14 , V_50 ) ;
F_75 ( V_50 ) ;
goto V_158;
}
V_96 = - V_159 ;
if ( ! F_10 ( V_14 , V_50 ) )
goto V_101;
V_96 = F_135 ( V_14 -> V_72 , V_50 -> V_72 ) ;
if ( V_96 )
goto V_101;
} else {
V_50 = NULL ;
F_129 ( V_14 , V_50 ) ;
}
if ( F_9 ( V_14 ) ) {
struct V_13 * V_160 = F_9 ( V_14 ) ;
F_9 ( V_14 ) = V_50 ;
F_48 ( V_14 , V_160 ) ;
F_132 ( V_14 , V_50 ) ;
if ( V_50 != V_160 )
F_59 ( V_14 , V_160 ) ;
F_75 ( V_160 ) ;
} else {
F_9 ( V_14 ) = V_50 ;
F_132 ( V_14 , V_50 ) ;
}
return 0 ;
V_101:
F_132 ( V_14 , V_50 ) ;
F_75 ( V_50 ) ;
V_100:
return V_96 ;
}
static long F_136 ( struct V_13 * V_50 , long V_161 )
{
struct V_34 * V_35 = F_34 ( V_50 ) ;
int V_162 ;
F_137 ( V_65 ) ;
F_138 ( & V_35 -> V_49 , & V_65 , V_163 ) ;
V_162 = ! F_63 ( V_50 , V_68 ) &&
! ( V_50 -> V_78 & V_164 ) &&
F_11 ( V_50 ) ;
F_16 ( V_50 ) ;
if ( V_162 )
V_161 = F_139 ( V_161 ) ;
F_140 ( & V_35 -> V_49 , & V_65 ) ;
return V_161 ;
}
static int F_141 ( struct V_94 * V_13 , struct V_140 * V_141 ,
int V_142 , int V_44 )
{
struct V_22 * V_23 = (struct V_22 * ) V_141 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) , * V_165 , * V_166 ;
struct V_13 * V_167 = NULL ;
struct V_13 * V_50 = NULL ;
struct V_8 * V_9 = NULL ;
unsigned int V_3 ;
int V_168 ;
int V_96 ;
long V_161 ;
V_96 = F_20 ( V_23 , V_142 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_142 = V_96 ;
if ( F_134 ( V_157 , & V_13 -> V_44 ) && ! V_35 -> V_2 &&
( V_96 = F_106 ( V_13 ) ) != 0 )
goto V_100;
V_161 = F_142 ( V_14 , V_44 & V_169 ) ;
V_96 = - V_127 ;
V_167 = F_92 ( F_36 ( V_14 ) , NULL , 0 ) ;
if ( V_167 == NULL )
goto V_100;
V_9 = F_143 ( V_167 , 1 , 0 , V_108 ) ;
if ( V_9 == NULL )
goto V_100;
V_158:
V_50 = F_110 ( V_32 , V_23 , V_142 , V_14 -> V_82 , V_3 , & V_96 ) ;
if ( ! V_50 )
goto V_100;
F_14 ( V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ) {
F_16 ( V_50 ) ;
F_75 ( V_50 ) ;
goto V_158;
}
V_96 = - V_136 ;
if ( V_50 -> V_58 != V_59 )
goto V_101;
if ( V_50 -> V_78 & V_164 )
goto V_101;
if ( F_11 ( V_50 ) ) {
V_96 = - V_170 ;
if ( ! V_161 )
goto V_101;
V_161 = F_136 ( V_50 , V_161 ) ;
V_96 = F_144 ( V_161 ) ;
if ( F_145 ( V_92 ) )
goto V_100;
F_75 ( V_50 ) ;
goto V_158;
}
V_168 = V_14 -> V_58 ;
switch ( V_168 ) {
case V_81 :
break;
case V_171 :
V_96 = - V_172 ;
goto V_101;
default:
V_96 = - V_26 ;
goto V_101;
}
F_131 ( V_14 ) ;
if ( V_14 -> V_58 != V_168 ) {
F_16 ( V_14 ) ;
F_16 ( V_50 ) ;
F_75 ( V_50 ) ;
goto V_158;
}
V_96 = F_146 ( V_14 , V_50 , V_167 ) ;
if ( V_96 ) {
F_16 ( V_14 ) ;
goto V_101;
}
F_15 ( V_14 ) ;
F_9 ( V_167 ) = V_14 ;
V_167 -> V_58 = V_171 ;
V_167 -> V_82 = V_14 -> V_82 ;
F_80 ( V_167 ) ;
V_165 = F_34 ( V_167 ) ;
F_147 ( V_167 -> V_64 , & V_165 -> V_173 ) ;
V_166 = F_34 ( V_50 ) ;
if ( V_166 -> V_2 ) {
F_148 ( & V_166 -> V_2 -> V_21 ) ;
V_165 -> V_2 = V_166 -> V_2 ;
}
if ( V_166 -> V_41 . V_40 ) {
F_149 ( & V_166 -> V_41 ) ;
V_165 -> V_41 = V_166 -> V_41 ;
}
F_86 ( V_14 , V_50 ) ;
V_13 -> V_77 = V_174 ;
V_14 -> V_58 = V_171 ;
F_15 ( V_167 ) ;
F_150 () ;
F_9 ( V_14 ) = V_167 ;
F_16 ( V_14 ) ;
F_29 ( & V_50 -> V_16 . V_53 ) ;
F_151 ( & V_50 -> V_16 , V_9 ) ;
F_30 ( & V_50 -> V_16 . V_53 ) ;
F_16 ( V_50 ) ;
V_50 -> V_175 ( V_50 ) ;
F_75 ( V_50 ) ;
return 0 ;
V_101:
if ( V_50 )
F_16 ( V_50 ) ;
V_100:
F_77 ( V_9 ) ;
if ( V_167 )
F_73 ( V_167 , 0 ) ;
if ( V_50 )
F_75 ( V_50 ) ;
return V_96 ;
}
static int F_152 ( struct V_94 * V_176 , struct V_94 * V_177 )
{
struct V_13 * V_178 = V_176 -> V_14 , * V_9 = V_177 -> V_14 ;
F_15 ( V_178 ) ;
F_15 ( V_9 ) ;
F_9 ( V_178 ) = V_9 ;
F_9 ( V_9 ) = V_178 ;
F_80 ( V_178 ) ;
F_80 ( V_9 ) ;
if ( V_178 -> V_82 != V_123 ) {
V_178 -> V_58 = V_171 ;
V_9 -> V_58 = V_171 ;
V_176 -> V_77 = V_174 ;
V_177 -> V_77 = V_174 ;
}
return 0 ;
}
static void F_153 ( const struct V_94 * V_179 ,
struct V_94 * V_180 )
{
if ( F_134 ( V_157 , & V_179 -> V_44 ) )
F_154 ( V_157 , & V_180 -> V_44 ) ;
if ( F_134 ( V_181 , & V_179 -> V_44 ) )
F_154 ( V_181 , & V_180 -> V_44 ) ;
}
static int F_155 ( struct V_94 * V_13 , struct V_94 * V_182 , int V_44 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_183 ;
struct V_8 * V_9 ;
int V_96 ;
V_96 = - V_99 ;
if ( V_13 -> type != V_83 && V_13 -> type != V_84 )
goto V_100;
V_96 = - V_26 ;
if ( V_14 -> V_58 != V_59 )
goto V_100;
V_9 = F_156 ( V_14 , 0 , V_44 & V_169 , & V_96 ) ;
if ( ! V_9 ) {
if ( V_96 == 0 )
V_96 = - V_26 ;
goto V_100;
}
V_183 = V_9 -> V_14 ;
F_157 ( V_14 , V_9 ) ;
F_158 ( & F_34 ( V_14 ) -> V_49 ) ;
F_14 ( V_183 ) ;
V_182 -> V_77 = V_174 ;
F_153 ( V_13 , V_182 ) ;
F_159 ( V_183 , V_182 ) ;
F_16 ( V_183 ) ;
return 0 ;
V_100:
return V_96 ;
}
static int F_160 ( struct V_94 * V_13 , struct V_140 * V_141 , int * V_184 , int V_19 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 ;
F_161 ( struct V_22 * , V_23 , V_141 ) ;
int V_96 = 0 ;
if ( V_19 ) {
V_14 = F_13 ( V_14 ) ;
V_96 = - V_185 ;
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
* V_184 = sizeof( short ) ;
} else {
struct V_20 * V_2 = V_35 -> V_2 ;
* V_184 = V_2 -> V_24 ;
memcpy ( V_23 , V_2 -> V_36 , * V_184 ) ;
}
F_16 ( V_14 ) ;
F_75 ( V_14 ) ;
V_100:
return V_96 ;
}
static void F_162 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_39 ;
V_7 -> V_186 = F_3 ( V_9 ) . V_186 ;
F_3 ( V_9 ) . V_186 = NULL ;
for ( V_39 = V_7 -> V_186 -> V_187 - 1 ; V_39 >= 0 ; V_39 -- )
F_163 ( V_7 -> V_186 -> V_186 [ V_39 ] ) ;
}
static void F_164 ( struct V_8 * V_9 )
{
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_97 = F_3 ( V_9 ) . V_97 ;
if ( F_3 ( V_9 ) . V_186 )
F_162 ( & V_7 , V_9 ) ;
F_165 ( & V_7 ) ;
F_166 ( V_9 ) ;
}
static int F_167 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_39 ;
unsigned char V_188 = 0 ;
int V_189 = 0 ;
for ( V_39 = V_7 -> V_186 -> V_187 - 1 ; V_39 >= 0 ; V_39 -- ) {
struct V_13 * V_14 = F_168 ( V_7 -> V_186 -> V_186 [ V_39 ] ) ;
if ( V_14 ) {
V_189 ++ ;
V_188 = F_169 ( V_188 ,
F_34 ( V_14 ) -> V_190 ) ;
}
}
if ( F_130 ( V_188 > V_191 ) )
return - V_192 ;
F_3 ( V_9 ) . V_186 = F_170 ( V_7 -> V_186 ) ;
if ( ! F_3 ( V_9 ) . V_186 )
return - V_127 ;
if ( V_189 ) {
for ( V_39 = V_7 -> V_186 -> V_187 - 1 ; V_39 >= 0 ; V_39 -- )
F_171 ( V_7 -> V_186 -> V_186 [ V_39 ] ) ;
}
return V_188 ;
}
static int F_172 ( struct V_6 * V_7 , struct V_8 * V_9 , bool V_193 )
{
int V_96 = 0 ;
F_3 ( V_9 ) . V_97 = F_83 ( V_7 -> V_97 ) ;
F_3 ( V_9 ) . V_194 = V_7 -> V_195 . V_194 ;
F_3 ( V_9 ) . V_196 = V_7 -> V_195 . V_196 ;
F_3 ( V_9 ) . V_186 = NULL ;
F_2 ( V_7 , V_9 ) ;
if ( V_7 -> V_186 && V_193 )
V_96 = F_167 ( V_7 , V_9 ) ;
V_9 -> V_197 = F_164 ;
return V_96 ;
}
static bool F_173 ( const struct V_94 * V_13 ,
const struct V_13 * V_50 )
{
return F_134 ( V_157 , & V_13 -> V_44 ) ||
! V_50 -> V_72 ||
F_134 ( V_157 , & V_50 -> V_72 -> V_44 ) ;
}
static void F_174 ( struct V_8 * V_9 , const struct V_94 * V_13 ,
const struct V_13 * V_50 )
{
if ( F_3 ( V_9 ) . V_97 )
return;
if ( F_173 ( V_13 , V_50 ) ) {
F_3 ( V_9 ) . V_97 = F_83 ( F_84 ( V_92 ) ) ;
F_175 ( & F_3 ( V_9 ) . V_194 , & F_3 ( V_9 ) . V_196 ) ;
}
}
static int F_176 ( struct V_6 * V_7 ,
struct V_94 * V_94 ,
const struct V_13 * V_50 )
{
int V_96 ;
struct V_198 V_199 = { . V_200 = 0 } ;
V_96 = F_177 ( V_94 , & V_199 , V_7 , false ) ;
if ( V_96 )
return V_96 ;
if ( F_173 ( V_94 , V_50 ) ) {
V_7 -> V_97 = F_83 ( F_84 ( V_92 ) ) ;
F_175 ( & V_7 -> V_195 . V_194 , & V_7 -> V_195 . V_196 ) ;
}
return V_96 ;
}
static bool F_178 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
const struct V_201 * V_35 = & F_3 ( V_9 ) ;
return V_35 -> V_97 == V_7 -> V_97 &&
F_179 ( V_35 -> V_194 , V_7 -> V_195 . V_194 ) &&
F_180 ( V_35 -> V_196 , V_7 -> V_195 . V_196 ) &&
F_5 ( V_7 , V_9 ) ;
}
static int F_181 ( struct V_94 * V_13 , struct V_198 * V_199 ,
T_6 V_24 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_32 * V_32 = F_36 ( V_14 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_161 ( struct V_22 * , V_23 , V_199 -> V_202 ) ;
struct V_13 * V_50 = NULL ;
int V_203 = 0 ;
int V_96 ;
unsigned int V_3 ;
struct V_8 * V_9 ;
long V_161 ;
struct V_6 V_7 ;
int V_188 ;
int V_204 = 0 ;
int V_205 ;
F_182 () ;
V_96 = F_177 ( V_13 , V_199 , & V_7 , false ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = - V_99 ;
if ( V_199 -> V_206 & V_207 )
goto V_100;
if ( V_199 -> V_208 ) {
V_96 = F_20 ( V_23 , V_199 -> V_208 , & V_3 ) ;
if ( V_96 < 0 )
goto V_100;
V_203 = V_96 ;
} else {
V_23 = NULL ;
V_96 = - V_185 ;
V_50 = F_13 ( V_14 ) ;
if ( ! V_50 )
goto V_100;
}
if ( F_134 ( V_157 , & V_13 -> V_44 ) && ! V_35 -> V_2
&& ( V_96 = F_106 ( V_13 ) ) != 0 )
goto V_100;
V_96 = - V_209 ;
if ( V_24 > V_14 -> V_61 - 32 )
goto V_100;
if ( V_24 > V_210 ) {
V_204 = F_183 ( T_6 ,
V_24 - V_210 ,
V_211 * V_212 ) ;
V_204 = F_184 ( V_204 ) ;
F_185 ( V_210 < V_212 ) ;
}
V_9 = F_186 ( V_14 , V_24 - V_204 , V_204 ,
V_199 -> V_206 & V_213 , & V_96 ,
V_214 ) ;
if ( V_9 == NULL )
goto V_100;
V_96 = F_172 ( & V_7 , V_9 , true ) ;
if ( V_96 < 0 )
goto V_215;
V_188 = V_96 + 1 ;
F_187 ( V_9 , V_24 - V_204 ) ;
V_9 -> V_204 = V_204 ;
V_9 -> V_24 = V_24 ;
V_96 = F_188 ( V_9 , 0 , & V_199 -> V_216 , V_24 ) ;
if ( V_96 )
goto V_215;
V_161 = F_142 ( V_14 , V_199 -> V_206 & V_213 ) ;
V_158:
if ( ! V_50 ) {
V_96 = - V_70 ;
if ( V_23 == NULL )
goto V_215;
V_50 = F_110 ( V_32 , V_23 , V_203 , V_14 -> V_82 ,
V_3 , & V_96 ) ;
if ( V_50 == NULL )
goto V_215;
}
if ( F_189 ( V_50 , V_9 ) < 0 ) {
V_96 = V_24 ;
goto V_215;
}
V_205 = 0 ;
F_14 ( V_50 ) ;
V_217:
V_96 = - V_159 ;
if ( ! F_10 ( V_14 , V_50 ) )
goto V_101;
if ( F_130 ( F_63 ( V_50 , V_68 ) ) ) {
F_16 ( V_50 ) ;
F_75 ( V_50 ) ;
if ( ! V_205 )
F_14 ( V_14 ) ;
V_96 = 0 ;
if ( F_9 ( V_14 ) == V_50 ) {
F_9 ( V_14 ) = NULL ;
F_48 ( V_14 , V_50 ) ;
F_16 ( V_14 ) ;
F_59 ( V_14 , V_50 ) ;
F_75 ( V_50 ) ;
V_96 = - V_136 ;
} else {
F_16 ( V_14 ) ;
}
V_50 = NULL ;
if ( V_96 )
goto V_215;
goto V_158;
}
V_96 = - V_218 ;
if ( V_50 -> V_78 & V_164 )
goto V_101;
if ( V_14 -> V_82 != V_84 ) {
V_96 = F_135 ( V_14 -> V_72 , V_50 -> V_72 ) ;
if ( V_96 )
goto V_101;
}
if ( F_130 ( F_9 ( V_50 ) != V_14 && F_11 ( V_50 ) ) ) {
if ( V_161 ) {
V_161 = F_136 ( V_50 , V_161 ) ;
V_96 = F_144 ( V_161 ) ;
if ( F_145 ( V_92 ) )
goto V_215;
goto V_158;
}
if ( ! V_205 ) {
F_16 ( V_50 ) ;
F_129 ( V_14 , V_50 ) ;
}
if ( F_9 ( V_14 ) != V_50 ||
F_49 ( V_14 , V_50 ) ) {
V_96 = - V_170 ;
V_205 = 1 ;
goto V_101;
}
if ( ! V_205 ) {
V_205 = 1 ;
goto V_217;
}
}
if ( F_130 ( V_205 ) )
F_16 ( V_14 ) ;
if ( F_63 ( V_50 , V_219 ) )
F_190 ( V_9 ) ;
F_174 ( V_9 , V_13 , V_50 ) ;
F_191 ( & V_50 -> V_16 , V_9 ) ;
if ( V_188 > F_34 ( V_50 ) -> V_190 )
F_34 ( V_50 ) -> V_190 = V_188 ;
F_16 ( V_50 ) ;
V_50 -> V_175 ( V_50 ) ;
F_75 ( V_50 ) ;
F_165 ( & V_7 ) ;
return V_24 ;
V_101:
if ( V_205 )
F_16 ( V_14 ) ;
F_16 ( V_50 ) ;
V_215:
F_77 ( V_9 ) ;
V_100:
if ( V_50 )
F_75 ( V_50 ) ;
F_165 ( & V_7 ) ;
return V_96 ;
}
static int F_192 ( struct V_94 * V_13 , struct V_198 * V_199 ,
T_6 V_24 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_50 = NULL ;
int V_96 , V_220 ;
struct V_8 * V_9 ;
int V_221 = 0 ;
struct V_6 V_7 ;
bool V_222 = false ;
int V_188 ;
int V_204 ;
F_182 () ;
V_96 = F_177 ( V_13 , V_199 , & V_7 , false ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = - V_99 ;
if ( V_199 -> V_206 & V_207 )
goto V_223;
if ( V_199 -> V_208 ) {
V_96 = V_14 -> V_58 == V_171 ? - V_172 : - V_99 ;
goto V_223;
} else {
V_96 = - V_185 ;
V_50 = F_9 ( V_14 ) ;
if ( ! V_50 )
goto V_223;
}
if ( V_14 -> V_78 & V_224 )
goto V_225;
while ( V_221 < V_24 ) {
V_220 = V_24 - V_221 ;
V_220 = F_183 ( int , V_220 , ( V_14 -> V_61 >> 1 ) - 64 ) ;
V_220 = F_183 ( int , V_220 , F_193 ( 0 ) + V_226 ) ;
V_204 = F_194 ( int , 0 , V_220 - F_193 ( 0 ) ) ;
V_204 = F_183 ( T_6 , V_220 , F_184 ( V_204 ) ) ;
V_9 = F_186 ( V_14 , V_220 - V_204 , V_204 ,
V_199 -> V_206 & V_213 , & V_96 ,
F_195 ( V_226 ) ) ;
if ( ! V_9 )
goto V_223;
V_96 = F_172 ( & V_7 , V_9 , ! V_222 ) ;
if ( V_96 < 0 ) {
F_77 ( V_9 ) ;
goto V_223;
}
V_188 = V_96 + 1 ;
V_222 = true ;
F_187 ( V_9 , V_220 - V_204 ) ;
V_9 -> V_204 = V_204 ;
V_9 -> V_24 = V_220 ;
V_96 = F_188 ( V_9 , 0 , & V_199 -> V_216 , V_220 ) ;
if ( V_96 ) {
F_77 ( V_9 ) ;
goto V_223;
}
F_14 ( V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ||
( V_50 -> V_78 & V_164 ) )
goto V_227;
F_174 ( V_9 , V_13 , V_50 ) ;
F_191 ( & V_50 -> V_16 , V_9 ) ;
if ( V_188 > F_34 ( V_50 ) -> V_190 )
F_34 ( V_50 ) -> V_190 = V_188 ;
F_16 ( V_50 ) ;
V_50 -> V_175 ( V_50 ) ;
V_221 += V_220 ;
}
F_165 ( & V_7 ) ;
return V_221 ;
V_227:
F_16 ( V_50 ) ;
F_77 ( V_9 ) ;
V_225:
if ( V_221 == 0 && ! ( V_199 -> V_206 & V_228 ) )
F_196 ( V_229 , V_92 , 0 ) ;
V_96 = - V_218 ;
V_223:
F_165 ( & V_7 ) ;
return V_221 ? : V_96 ;
}
static T_7 F_197 ( struct V_94 * V_94 , struct V_230 * V_230 ,
int V_231 , T_6 V_220 , int V_44 )
{
int V_96 ;
bool V_232 = false ;
bool V_233 = true ;
struct V_6 V_7 ;
struct V_13 * V_50 , * V_14 = V_94 -> V_14 ;
struct V_8 * V_9 , * V_234 = NULL , * V_235 = NULL ;
if ( V_44 & V_207 )
return - V_99 ;
V_50 = F_9 ( V_14 ) ;
if ( ! V_50 || V_14 -> V_58 != V_171 )
return - V_185 ;
if ( false ) {
V_236:
F_16 ( V_50 ) ;
F_91 ( & F_34 ( V_50 ) -> V_103 ) ;
V_234 = F_186 ( V_14 , 0 , 0 , V_44 & V_213 ,
& V_96 , 0 ) ;
if ( ! V_234 )
goto V_96;
}
V_96 = F_90 ( & F_34 ( V_50 ) -> V_103 ) ;
if ( V_96 ) {
V_96 = V_44 & V_213 ? - V_170 : - V_237 ;
goto V_96;
}
if ( V_14 -> V_78 & V_224 ) {
V_96 = - V_218 ;
V_232 = true ;
goto V_238;
}
F_14 ( V_50 ) ;
if ( F_63 ( V_50 , V_68 ) ||
V_50 -> V_78 & V_164 ) {
V_96 = - V_218 ;
V_232 = true ;
goto V_239;
}
if ( V_233 ) {
V_96 = F_176 ( & V_7 , V_94 , V_50 ) ;
if ( V_96 )
goto V_239;
V_233 = false ;
}
V_9 = F_198 ( & V_50 -> V_16 ) ;
if ( V_235 && V_235 == V_9 ) {
V_9 = V_234 ;
} else if ( ! V_9 || ! F_178 ( V_9 , & V_7 ) ) {
if ( V_234 ) {
V_9 = V_234 ;
} else {
V_235 = V_9 ;
goto V_236;
}
} else if ( V_234 ) {
F_199 ( V_234 ) ;
V_234 = NULL ;
}
if ( F_200 ( V_9 , V_230 , V_231 , V_220 ) ) {
V_235 = V_9 ;
goto V_236;
}
V_9 -> V_24 += V_220 ;
V_9 -> V_204 += V_220 ;
V_9 -> V_240 += V_220 ;
F_201 ( V_220 , & V_14 -> V_60 ) ;
if ( V_234 ) {
V_96 = F_172 ( & V_7 , V_9 , false ) ;
if ( V_96 )
goto V_239;
F_29 ( & V_50 -> V_16 . V_53 ) ;
F_151 ( & V_50 -> V_16 , V_234 ) ;
F_30 ( & V_50 -> V_16 . V_53 ) ;
}
F_16 ( V_50 ) ;
F_91 ( & F_34 ( V_50 ) -> V_103 ) ;
V_50 -> V_175 ( V_50 ) ;
F_165 ( & V_7 ) ;
return V_220 ;
V_239:
F_16 ( V_50 ) ;
V_238:
F_91 ( & F_34 ( V_50 ) -> V_103 ) ;
V_96:
F_77 ( V_234 ) ;
if ( V_232 && ! ( V_44 & V_228 ) )
F_196 ( V_229 , V_92 , 0 ) ;
if ( ! V_233 )
F_165 ( & V_7 ) ;
return V_96 ;
}
static int F_202 ( struct V_94 * V_13 , struct V_198 * V_199 ,
T_6 V_24 )
{
int V_96 ;
struct V_13 * V_14 = V_13 -> V_14 ;
V_96 = F_203 ( V_14 ) ;
if ( V_96 )
return V_96 ;
if ( V_14 -> V_58 != V_171 )
return - V_185 ;
if ( V_199 -> V_208 )
V_199 -> V_208 = 0 ;
return F_181 ( V_13 , V_199 , V_24 ) ;
}
static int F_204 ( struct V_94 * V_13 , struct V_198 * V_199 ,
T_6 V_220 , int V_44 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
if ( V_14 -> V_58 != V_171 )
return - V_185 ;
return F_205 ( V_13 , V_199 , V_220 , V_44 ) ;
}
static void F_206 ( struct V_198 * V_199 , struct V_13 * V_14 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
if ( V_35 -> V_2 ) {
V_199 -> V_208 = V_35 -> V_2 -> V_24 ;
memcpy ( V_199 -> V_202 , V_35 -> V_2 -> V_36 , V_35 -> V_2 -> V_24 ) ;
}
}
static int F_205 ( struct V_94 * V_13 , struct V_198 * V_199 ,
T_6 V_220 , int V_44 )
{
struct V_6 V_7 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
int V_241 = V_44 & V_213 ;
struct V_8 * V_9 ;
int V_96 ;
int V_242 , V_243 ;
V_96 = - V_99 ;
if ( V_44 & V_207 )
goto V_100;
V_96 = F_90 ( & V_35 -> V_103 ) ;
if ( F_130 ( V_96 ) ) {
V_96 = V_241 ? - V_170 : - V_237 ;
goto V_100;
}
V_243 = F_207 ( V_14 , V_44 ) ;
V_9 = F_208 ( V_14 , V_44 , & V_242 , & V_243 , & V_96 ) ;
if ( ! V_9 ) {
F_14 ( V_14 ) ;
if ( V_14 -> V_82 == V_84 && V_96 == - V_170 &&
( V_14 -> V_78 & V_164 ) )
V_96 = 0 ;
F_16 ( V_14 ) ;
goto V_101;
}
F_56 ( & V_35 -> V_49 ,
V_54 | V_55 | V_56 ) ;
if ( V_199 -> V_202 )
F_206 ( V_199 , V_9 -> V_14 ) ;
if ( V_220 > V_9 -> V_24 - V_243 )
V_220 = V_9 -> V_24 - V_243 ;
else if ( V_220 < V_9 -> V_24 - V_243 )
V_199 -> V_206 |= V_244 ;
V_96 = F_209 ( V_9 , V_243 , V_199 , V_220 ) ;
if ( V_96 )
goto V_215;
if ( F_63 ( V_14 , V_219 ) )
F_210 ( V_199 , V_14 , V_9 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_211 ( & V_7 , F_3 ( V_9 ) . V_97 , F_3 ( V_9 ) . V_194 , F_3 ( V_9 ) . V_196 ) ;
F_4 ( & V_7 , V_9 ) ;
if ( ! ( V_44 & V_245 ) ) {
if ( F_3 ( V_9 ) . V_186 )
F_162 ( & V_7 , V_9 ) ;
F_212 ( V_14 , V_9 -> V_24 ) ;
} else {
F_213 ( V_14 , V_220 ) ;
if ( F_3 ( V_9 ) . V_186 )
V_7 . V_186 = F_170 ( F_3 ( V_9 ) . V_186 ) ;
}
V_96 = ( V_44 & V_244 ) ? V_9 -> V_24 - V_243 : V_220 ;
F_214 ( V_13 , V_199 , & V_7 , V_44 ) ;
V_215:
F_157 ( V_14 , V_9 ) ;
V_101:
F_91 ( & V_35 -> V_103 ) ;
V_100:
return V_96 ;
}
static long F_215 ( struct V_13 * V_14 , long V_161 ,
struct V_8 * V_246 , unsigned int V_247 )
{
struct V_8 * V_235 ;
F_137 ( V_65 ) ;
F_14 ( V_14 ) ;
for (; ; ) {
F_216 ( F_43 ( V_14 ) , & V_65 , V_163 ) ;
V_235 = F_198 ( & V_14 -> V_16 ) ;
if ( V_235 != V_246 ||
( V_235 && V_235 -> V_24 != V_247 ) ||
V_14 -> V_69 ||
( V_14 -> V_78 & V_164 ) ||
F_145 ( V_92 ) ||
! V_161 )
break;
F_217 ( V_248 , V_14 ) ;
F_16 ( V_14 ) ;
V_161 = F_218 ( V_161 ) ;
F_14 ( V_14 ) ;
if ( F_63 ( V_14 , V_68 ) )
break;
F_219 ( V_248 , V_14 ) ;
}
F_140 ( F_43 ( V_14 ) , & V_65 ) ;
F_16 ( V_14 ) ;
return V_161 ;
}
static unsigned int F_220 ( const struct V_8 * V_9 )
{
return V_9 -> V_24 - F_3 ( V_9 ) . V_88 ;
}
static int F_221 ( struct V_249 * V_77 )
{
struct V_6 V_7 ;
struct V_94 * V_13 = V_77 -> V_94 ;
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
int V_250 = 0 ;
int V_44 = V_77 -> V_44 ;
int V_241 = V_44 & V_213 ;
bool V_251 = false ;
int V_252 ;
int V_96 = 0 ;
long V_161 ;
int V_243 ;
T_6 V_220 = V_77 -> V_220 ;
unsigned int V_247 ;
V_96 = - V_26 ;
if ( V_14 -> V_58 != V_171 )
goto V_100;
V_96 = - V_99 ;
if ( V_44 & V_207 )
goto V_100;
V_252 = F_222 ( V_14 , V_44 & V_253 , V_220 ) ;
V_161 = F_223 ( V_14 , V_241 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_224 ( & V_35 -> V_103 ) ;
if ( V_44 & V_245 )
V_243 = F_207 ( V_14 , V_44 ) ;
else
V_243 = 0 ;
do {
int V_254 ;
bool V_255 ;
struct V_8 * V_9 , * V_246 ;
F_14 ( V_14 ) ;
if ( F_63 ( V_14 , V_68 ) ) {
V_96 = - V_70 ;
goto V_256;
}
V_246 = V_9 = F_225 ( & V_14 -> V_16 ) ;
V_247 = V_246 ? V_246 -> V_24 : 0 ;
V_257:
if ( V_9 == NULL ) {
F_34 ( V_14 ) -> V_190 = 0 ;
if ( V_250 >= V_252 )
goto V_256;
V_96 = F_203 ( V_14 ) ;
if ( V_96 )
goto V_256;
if ( V_14 -> V_78 & V_164 )
goto V_256;
F_16 ( V_14 ) ;
V_96 = - V_170 ;
if ( ! V_161 )
break;
F_91 ( & V_35 -> V_103 ) ;
V_161 = F_215 ( V_14 , V_161 , V_246 ,
V_247 ) ;
if ( F_145 ( V_92 ) ) {
V_96 = F_144 ( V_161 ) ;
goto V_100;
}
F_224 ( & V_35 -> V_103 ) ;
continue;
V_256:
F_16 ( V_14 ) ;
break;
}
while ( V_243 >= F_220 ( V_9 ) ) {
V_243 -= F_220 ( V_9 ) ;
V_246 = V_9 ;
V_247 = V_9 -> V_24 ;
V_9 = F_226 ( V_9 , & V_14 -> V_16 ) ;
if ( ! V_9 )
goto V_257;
}
F_16 ( V_14 ) ;
if ( V_251 ) {
if ( ! F_178 ( V_9 , & V_7 ) )
break;
} else if ( F_134 ( V_157 , & V_13 -> V_44 ) ) {
F_211 ( & V_7 , F_3 ( V_9 ) . V_97 , F_3 ( V_9 ) . V_194 , F_3 ( V_9 ) . V_196 ) ;
F_4 ( & V_7 , V_9 ) ;
V_251 = true ;
}
if ( V_77 -> V_199 && V_77 -> V_199 -> V_202 ) {
F_161 ( struct V_22 * , V_23 ,
V_77 -> V_199 -> V_202 ) ;
F_206 ( V_77 -> V_199 , V_9 -> V_14 ) ;
V_23 = NULL ;
}
V_254 = F_183 (unsigned int, unix_skb_len(skb) - skip, size) ;
F_227 ( V_9 ) ;
V_254 = V_77 -> V_258 ( V_9 , V_243 , V_254 , V_77 ) ;
V_255 = ! F_220 ( V_9 ) ;
F_199 ( V_9 ) ;
if ( V_254 < 0 ) {
if ( V_250 == 0 )
V_250 = - V_259 ;
break;
}
V_250 += V_254 ;
V_220 -= V_254 ;
if ( V_255 ) {
V_96 = 0 ;
break;
}
if ( ! ( V_44 & V_245 ) ) {
F_3 ( V_9 ) . V_88 += V_254 ;
F_212 ( V_14 , V_254 ) ;
if ( F_3 ( V_9 ) . V_186 )
F_162 ( & V_7 , V_9 ) ;
if ( F_220 ( V_9 ) )
break;
F_228 ( V_9 , & V_14 -> V_16 ) ;
F_199 ( V_9 ) ;
if ( V_7 . V_186 )
break;
} else {
if ( F_3 ( V_9 ) . V_186 )
V_7 . V_186 = F_170 ( F_3 ( V_9 ) . V_186 ) ;
F_213 ( V_14 , V_254 ) ;
if ( F_3 ( V_9 ) . V_186 )
break;
V_243 = 0 ;
V_246 = V_9 ;
V_247 = V_9 -> V_24 ;
F_14 ( V_14 ) ;
V_9 = F_226 ( V_9 , & V_14 -> V_16 ) ;
if ( V_9 )
goto V_257;
F_16 ( V_14 ) ;
break;
}
} while ( V_220 );
F_91 ( & V_35 -> V_103 ) ;
if ( V_77 -> V_199 )
F_214 ( V_13 , V_77 -> V_199 , & V_7 , V_44 ) ;
else
F_165 ( & V_7 ) ;
V_100:
return V_250 ? : V_96 ;
}
static int F_229 ( struct V_8 * V_9 ,
int V_243 , int V_254 ,
struct V_249 * V_77 )
{
int V_260 ;
V_260 = F_209 ( V_9 , F_3 ( V_9 ) . V_88 + V_243 ,
V_77 -> V_199 , V_254 ) ;
return V_260 ? : V_254 ;
}
static int F_230 ( struct V_94 * V_13 , struct V_198 * V_199 ,
T_6 V_220 , int V_44 )
{
struct V_249 V_77 = {
. V_258 = F_229 ,
. V_94 = V_13 ,
. V_199 = V_199 ,
. V_220 = V_220 ,
. V_44 = V_44
} ;
return F_221 ( & V_77 ) ;
}
static T_7 F_231 ( struct V_13 * V_14 ,
struct V_261 * V_262 ,
struct V_263 * V_264 )
{
int V_260 ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
F_91 ( & V_35 -> V_103 ) ;
V_260 = F_232 ( V_262 , V_264 ) ;
F_224 ( & V_35 -> V_103 ) ;
return V_260 ;
}
static int F_233 ( struct V_8 * V_9 ,
int V_243 , int V_254 ,
struct V_249 * V_77 )
{
return F_234 ( V_9 , V_77 -> V_94 -> V_14 ,
F_3 ( V_9 ) . V_88 + V_243 ,
V_77 -> V_262 , V_254 , V_77 -> V_265 ,
F_231 ) ;
}
static T_7 F_235 ( struct V_94 * V_13 , T_8 * V_266 ,
struct V_261 * V_262 ,
T_6 V_220 , unsigned int V_44 )
{
struct V_249 V_77 = {
. V_258 = F_233 ,
. V_94 = V_13 ,
. V_262 = V_262 ,
. V_220 = V_220 ,
. V_265 = V_44 ,
} ;
if ( F_130 ( * V_266 ) )
return - V_267 ;
if ( V_13 -> V_268 -> V_269 & V_169 ||
V_44 & V_270 )
V_77 . V_44 = V_213 ;
return F_221 ( & V_77 ) ;
}
static int F_236 ( struct V_94 * V_13 , int V_43 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
struct V_13 * V_50 ;
if ( V_43 < V_271 || V_43 > V_272 )
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
int V_273 = 0 ;
if ( V_43 & V_164 )
V_273 |= V_224 ;
if ( V_43 & V_224 )
V_273 |= V_164 ;
F_14 ( V_50 ) ;
V_50 -> V_78 |= V_273 ;
F_16 ( V_50 ) ;
V_50 -> V_85 ( V_50 ) ;
if ( V_273 == V_79 )
F_57 ( V_50 , V_86 , V_87 ) ;
else if ( V_273 & V_164 )
F_57 ( V_50 , V_86 , V_274 ) ;
}
if ( V_50 )
F_75 ( V_50 ) ;
return 0 ;
}
long F_237 ( struct V_13 * V_14 )
{
struct V_8 * V_9 ;
long V_275 = 0 ;
if ( V_14 -> V_58 == V_59 )
return - V_26 ;
F_29 ( & V_14 -> V_16 . V_53 ) ;
if ( V_14 -> V_82 == V_83 ||
V_14 -> V_82 == V_84 ) {
F_238 (&sk->sk_receive_queue, skb)
V_275 += F_220 ( V_9 ) ;
} else {
V_9 = F_225 ( & V_14 -> V_16 ) ;
if ( V_9 )
V_275 = V_9 -> V_24 ;
}
F_30 ( & V_14 -> V_16 . V_53 ) ;
return V_275 ;
}
long F_239 ( struct V_13 * V_14 )
{
return F_240 ( V_14 ) ;
}
static int F_241 ( struct V_94 * V_13 , unsigned int V_276 , unsigned long V_277 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
long V_275 = 0 ;
int V_96 ;
switch ( V_276 ) {
case V_278 :
V_275 = F_239 ( V_14 ) ;
V_96 = F_242 ( V_275 , ( int V_279 * ) V_277 ) ;
break;
case V_280 :
V_275 = F_237 ( V_14 ) ;
if ( V_275 < 0 )
V_96 = V_275 ;
else
V_96 = F_242 ( V_275 , ( int V_279 * ) V_277 ) ;
break;
default:
V_96 = - V_281 ;
break;
}
return V_96 ;
}
static unsigned int F_243 ( struct V_268 * V_268 , struct V_94 * V_13 , T_9 * V_65 )
{
struct V_13 * V_14 = V_13 -> V_14 ;
unsigned int V_282 ;
F_244 ( V_268 , F_43 ( V_14 ) , V_65 ) ;
V_282 = 0 ;
if ( V_14 -> V_69 )
V_282 |= V_283 ;
if ( V_14 -> V_78 == V_79 )
V_282 |= V_284 ;
if ( V_14 -> V_78 & V_164 )
V_282 |= V_285 | V_286 | V_287 ;
if ( ! F_60 ( & V_14 -> V_16 ) )
V_282 |= V_286 | V_287 ;
if ( ( V_14 -> V_82 == V_83 || V_14 -> V_82 == V_84 ) &&
V_14 -> V_58 == V_81 )
V_282 |= V_284 ;
if ( F_50 ( V_14 ) )
V_282 |= V_54 | V_55 | V_56 ;
return V_282 ;
}
static unsigned int F_245 ( struct V_268 * V_268 , struct V_94 * V_13 ,
T_9 * V_65 )
{
struct V_13 * V_14 = V_13 -> V_14 , * V_50 ;
unsigned int V_282 , V_288 ;
F_244 ( V_268 , F_43 ( V_14 ) , V_65 ) ;
V_282 = 0 ;
if ( V_14 -> V_69 || ! F_60 ( & V_14 -> V_289 ) )
V_282 |= V_283 |
( F_63 ( V_14 , V_290 ) ? V_291 : 0 ) ;
if ( V_14 -> V_78 & V_164 )
V_282 |= V_285 | V_286 | V_287 ;
if ( V_14 -> V_78 == V_79 )
V_282 |= V_284 ;
if ( ! F_60 ( & V_14 -> V_16 ) )
V_282 |= V_286 | V_287 ;
if ( V_14 -> V_82 == V_84 ) {
if ( V_14 -> V_58 == V_81 )
V_282 |= V_284 ;
if ( V_14 -> V_58 == V_292 )
return V_282 ;
}
if ( ! ( F_246 ( V_65 ) & ( V_56 | V_55 | V_54 ) ) )
return V_282 ;
V_288 = F_50 ( V_14 ) ;
if ( V_288 ) {
F_14 ( V_14 ) ;
V_50 = F_9 ( V_14 ) ;
if ( V_50 && F_9 ( V_50 ) != V_14 &&
F_11 ( V_50 ) &&
F_49 ( V_14 , V_50 ) )
V_288 = 0 ;
F_16 ( V_14 ) ;
}
if ( V_288 )
V_282 |= V_54 | V_55 | V_56 ;
else
F_217 ( V_293 , V_14 ) ;
return V_282 ;
}
static struct V_13 * F_247 ( struct V_294 * V_295 , T_8 * V_296 )
{
unsigned long V_231 = F_248 ( * V_296 ) ;
unsigned long V_297 = F_249 ( * V_296 ) ;
struct V_13 * V_14 ;
unsigned long V_187 = 0 ;
for ( V_14 = F_250 ( & V_5 [ V_297 ] ) ; V_14 ; V_14 = F_251 ( V_14 ) ) {
if ( F_36 ( V_14 ) != F_252 ( V_295 ) )
continue;
if ( ++ V_187 == V_231 )
break;
}
return V_14 ;
}
static struct V_13 * F_253 ( struct V_294 * V_295 ,
struct V_13 * V_14 ,
T_8 * V_296 )
{
unsigned long V_297 ;
while ( V_14 > (struct V_13 * ) V_298 ) {
V_14 = F_251 ( V_14 ) ;
if ( ! V_14 )
goto V_299;
if ( F_36 ( V_14 ) == F_252 ( V_295 ) )
return V_14 ;
}
do {
V_14 = F_247 ( V_295 , V_296 ) ;
if ( V_14 )
return V_14 ;
V_299:
V_297 = F_249 ( * V_296 ) + 1 ;
* V_296 = F_254 ( V_297 , 1 ) ;
} while ( V_297 < F_255 ( V_5 ) );
return NULL ;
}
static void * F_256 ( struct V_294 * V_295 , T_8 * V_296 )
__acquires( V_31 )
{
F_29 ( & V_31 ) ;
if ( ! * V_296 )
return V_298 ;
if ( F_249 ( * V_296 ) >= F_255 ( V_5 ) )
return NULL ;
return F_253 ( V_295 , NULL , V_296 ) ;
}
static void * F_257 ( struct V_294 * V_295 , void * V_300 , T_8 * V_296 )
{
++ * V_296 ;
return F_253 ( V_295 , V_300 , V_296 ) ;
}
static void F_258 ( struct V_294 * V_295 , void * V_300 )
__releases( V_31 )
{
F_30 ( & V_31 ) ;
}
static int F_259 ( struct V_294 * V_295 , void * V_300 )
{
if ( V_300 == V_298 )
F_260 ( V_295 , L_4
L_5 ) ;
else {
struct V_13 * V_18 = V_300 ;
struct V_34 * V_35 = F_34 ( V_18 ) ;
F_14 ( V_18 ) ;
F_261 ( V_295 , L_6 ,
V_18 ,
F_51 ( & V_18 -> V_301 ) ,
0 ,
V_18 -> V_58 == V_59 ? V_302 : 0 ,
V_18 -> V_82 ,
V_18 -> V_72 ?
( V_18 -> V_58 == V_171 ? V_174 : V_119 ) :
( V_18 -> V_58 == V_171 ? V_303 : V_304 ) ,
F_262 ( V_18 ) ) ;
if ( V_35 -> V_2 ) {
int V_39 , V_24 ;
F_263 ( V_295 , ' ' ) ;
V_39 = 0 ;
V_24 = V_35 -> V_2 -> V_24 - sizeof( short ) ;
if ( ! F_264 ( V_18 ) )
V_24 -- ;
else {
F_263 ( V_295 , '@' ) ;
V_39 ++ ;
}
for ( ; V_39 < V_24 ; V_39 ++ )
F_263 ( V_295 , V_35 -> V_2 -> V_36 -> V_29 [ V_39 ] ) ;
}
F_16 ( V_18 ) ;
F_263 ( V_295 , '\n' ) ;
}
return 0 ;
}
static int F_265 ( struct V_38 * V_38 , struct V_268 * V_268 )
{
return F_266 ( V_38 , V_268 , & V_305 ,
sizeof( struct V_306 ) ) ;
}
static int T_10 F_267 ( struct V_32 * V_32 )
{
int error = - V_127 ;
V_32 -> V_112 . V_113 = 10 ;
if ( F_268 ( V_32 ) )
goto V_100;
#ifdef F_269
if ( ! F_270 ( L_7 , 0 , V_32 -> V_307 , & V_308 ) ) {
F_271 ( V_32 ) ;
goto V_100;
}
#endif
error = 0 ;
V_100:
return error ;
}
static void T_11 F_272 ( struct V_32 * V_32 )
{
F_271 ( V_32 ) ;
F_273 ( L_7 , V_32 -> V_307 ) ;
}
static int T_12 F_274 ( void )
{
int V_52 = - 1 ;
F_185 ( sizeof( struct V_201 ) > F_275 ( struct V_8 , V_309 ) ) ;
V_52 = F_276 ( & V_109 , 1 ) ;
if ( V_52 != 0 ) {
F_277 ( L_8 , V_310 ) ;
goto V_100;
}
F_278 ( & V_311 ) ;
F_279 ( & V_312 ) ;
V_100:
return V_52 ;
}
static void T_13 F_280 ( void )
{
F_281 ( V_107 ) ;
F_282 ( & V_109 ) ;
F_283 ( & V_312 ) ;
}
