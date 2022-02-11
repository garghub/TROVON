static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 ? 1 << ( V_5 - 1 ) : 0 ;
}
static struct V_6 * F_4 ( const struct V_6 * V_7 ,
T_2 V_8 )
{
unsigned int V_9 = F_5 ( V_7 ) ;
struct V_6 * V_10 ;
V_10 = F_6 ( V_9 , V_8 ) ;
if ( V_10 == NULL )
return NULL ;
F_7 ( V_10 ) . V_11 = F_7 ( V_7 ) . V_11 ;
F_7 ( V_10 ) . V_12 = F_7 ( V_7 ) . V_12 ;
F_7 ( V_10 ) . V_13 = F_7 ( V_7 ) . V_13 ;
memcpy ( F_8 ( V_10 , V_9 ) , V_7 -> V_14 , V_9 ) ;
return V_10 ;
}
int F_9 ( struct V_15 * V_16 )
{
if ( F_10 ( V_16 -> V_17 -> type != V_18 ) )
return - V_19 ;
F_11 ( & V_20 ) ;
F_12 ( & V_16 -> V_21 , & V_22 ) ;
F_13 ( & V_20 ) ;
F_14 ( V_16 -> V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
bool V_24 = false ;
struct V_15 * V_25 ;
F_11 ( & V_20 ) ;
F_16 (tmp, &netlink_tap_all, list) {
if ( V_16 == V_25 ) {
F_17 ( & V_16 -> V_21 ) ;
V_24 = true ;
goto V_26;
}
}
F_18 ( L_1 , V_16 ) ;
V_26:
F_13 ( & V_20 ) ;
if ( V_24 )
F_19 ( V_16 -> V_23 ) ;
return V_24 ? 0 : - V_27 ;
}
int F_20 ( struct V_15 * V_16 )
{
int V_28 ;
V_28 = F_15 ( V_16 ) ;
F_21 () ;
return V_28 ;
}
static bool F_22 ( const struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
switch ( V_2 -> V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return true ;
}
return false ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_38 * V_17 )
{
struct V_6 * V_39 ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_28 = - V_40 ;
F_24 ( V_17 ) ;
if ( F_25 ( V_7 -> V_41 ) )
V_39 = F_4 ( V_7 , V_42 ) ;
else
V_39 = F_26 ( V_7 , V_42 ) ;
if ( V_39 ) {
V_39 -> V_17 = V_17 ;
V_39 -> V_43 = F_27 ( ( V_44 ) V_2 -> V_29 ) ;
V_39 -> V_45 = F_1 ( V_2 ) ?
V_46 : V_47 ;
F_28 ( V_39 ) ;
V_28 = F_29 ( V_39 ) ;
if ( F_10 ( V_28 > 0 ) )
V_28 = F_30 ( V_28 ) ;
}
F_31 ( V_17 ) ;
return V_28 ;
}
static void F_32 ( struct V_6 * V_7 )
{
int V_28 ;
struct V_15 * V_25 ;
if ( ! F_22 ( V_7 ) )
return;
F_33 (tmp, &netlink_tap_all, list) {
V_28 = F_23 ( V_7 , V_25 -> V_17 ) ;
if ( F_10 ( V_28 ) )
break;
}
}
static void F_34 ( struct V_6 * V_7 )
{
F_35 () ;
if ( F_10 ( ! F_36 ( & V_22 ) ) )
F_32 ( V_7 ) ;
F_37 () ;
}
static void F_38 ( struct V_1 * V_48 , struct V_1 * V_49 ,
struct V_6 * V_7 )
{
if ( ! ( F_1 ( V_48 ) && F_1 ( V_49 ) ) )
F_34 ( V_7 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( ! ( V_51 -> V_3 & V_52 ) ) {
if ( ! F_40 ( V_53 ,
& F_2 ( V_2 ) -> V_54 ) ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_41 ( & V_2 -> V_58 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_59 ) )
F_44 ( V_53 , & V_51 -> V_54 ) ;
if ( ! F_45 ( V_53 , & V_51 -> V_54 ) )
F_46 ( & V_51 -> V_60 ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
if ( F_25 ( V_7 -> V_41 ) ) {
if ( ! V_7 -> V_61 ||
! F_48 ( & ( F_49 ( V_7 ) -> V_62 ) ) )
F_50 ( V_7 -> V_41 ) ;
V_7 -> V_41 = NULL ;
}
if ( V_7 -> V_2 != NULL )
F_51 ( V_7 ) ;
}
static void F_52 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
F_53 ( V_7 -> V_2 != NULL ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_63 = F_47 ;
F_54 ( V_7 -> V_64 , & V_2 -> V_65 ) ;
F_55 ( V_2 , V_7 -> V_64 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_66 ) {
if ( V_51 -> V_67 . V_68 )
V_51 -> V_67 . V_68 ( & V_51 -> V_67 ) ;
F_19 ( V_51 -> V_67 . V_23 ) ;
F_57 ( V_51 -> V_67 . V_7 ) ;
}
F_58 ( & V_2 -> V_59 ) ;
if ( ! F_59 ( V_2 , V_69 ) ) {
F_60 ( V_70 L_2 , V_2 ) ;
return;
}
F_53 ( F_61 ( & V_2 -> V_65 ) ) ;
F_53 ( F_61 ( & V_2 -> V_71 ) ) ;
F_53 ( F_2 ( V_2 ) -> V_72 ) ;
}
void F_62 ( void )
__acquires( T_3 )
{
F_63 () ;
F_64 ( & T_3 ) ;
if ( F_61 ( & V_73 ) ) {
F_65 ( V_60 , V_74 ) ;
F_66 ( & V_75 , & V_60 ) ;
for (; ; ) {
F_67 ( V_76 ) ;
if ( F_61 ( & V_73 ) == 0 )
break;
F_68 ( & T_3 ) ;
F_69 () ;
F_64 ( & T_3 ) ;
}
F_70 ( V_77 ) ;
F_71 ( & V_75 , & V_60 ) ;
}
}
void F_72 ( void )
__releases( T_3 )
{
F_68 ( & T_3 ) ;
F_73 ( & V_75 ) ;
}
static inline void
F_74 ( void )
{
F_75 ( & T_3 ) ;
F_41 ( & V_73 ) ;
F_76 ( & T_3 ) ;
}
static inline void
F_77 ( void )
{
if ( F_78 ( & V_73 ) )
F_73 ( & V_75 ) ;
}
static inline int F_79 ( struct V_78 * V_79 ,
const void * V_80 )
{
const struct V_81 * V_82 = V_79 -> V_83 ;
const struct V_50 * V_51 = V_80 ;
return V_51 -> V_11 != V_82 -> V_11 ||
! F_80 ( F_81 ( & V_51 -> V_2 ) , F_82 ( & V_82 -> V_84 ) ) ;
}
static void F_83 ( struct V_81 * V_79 ,
struct V_85 * V_85 , T_1 V_11 )
{
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
F_84 ( & V_79 -> V_84 , V_85 ) ;
V_79 -> V_11 = V_11 ;
}
static struct V_1 * F_85 ( struct V_86 * V_87 , T_1 V_11 ,
struct V_85 * V_85 )
{
struct V_81 V_79 ;
F_83 ( & V_79 , V_85 , V_11 ) ;
return F_86 ( & V_87 -> V_88 , & V_79 ,
V_89 ) ;
}
static int F_87 ( struct V_86 * V_87 , struct V_1 * V_2 )
{
struct V_81 V_79 ;
F_83 ( & V_79 , F_81 ( V_2 ) , F_2 ( V_2 ) -> V_11 ) ;
return F_88 ( & V_87 -> V_88 , & V_79 ,
& F_2 ( V_2 ) -> V_90 ,
V_89 ) ;
}
static struct V_1 * F_89 ( struct V_85 * V_85 , int V_43 , T_1 V_11 )
{
struct V_86 * V_87 = & V_91 [ V_43 ] ;
struct V_1 * V_2 ;
F_35 () ;
V_2 = F_85 ( V_87 , V_11 , V_85 ) ;
if ( V_2 )
F_90 ( V_2 ) ;
F_37 () ;
return V_2 ;
}
static void
F_91 ( struct V_1 * V_2 )
{
struct V_86 * V_92 = & V_91 [ V_2 -> V_29 ] ;
unsigned long V_93 ;
unsigned int V_94 ;
struct V_95 * V_95 ;
V_95 = F_92 ( V_92 -> V_95 ) ;
if ( ! V_95 )
return;
for ( V_94 = 0 ; V_94 < F_93 ( V_92 -> V_72 ) ; V_94 ++ ) {
V_93 = 0 ;
F_94 (sk, &tbl->mc_list) {
if ( V_94 < F_93 ( F_2 ( V_2 ) -> V_96 ) )
V_93 |= F_2 ( V_2 ) -> V_72 [ V_94 ] ;
}
V_95 -> V_97 [ V_94 ] = V_93 ;
}
}
static int F_95 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_86 * V_87 = & V_91 [ V_2 -> V_29 ] ;
int V_98 ;
F_96 ( V_2 ) ;
V_98 = F_2 ( V_2 ) -> V_11 == V_11 ? 0 : - V_99 ;
if ( F_2 ( V_2 ) -> V_100 )
goto V_98;
V_98 = - V_40 ;
if ( V_101 > 32 &&
F_10 ( F_61 ( & V_87 -> V_88 . V_102 ) >= V_103 ) )
goto V_98;
F_2 ( V_2 ) -> V_11 = V_11 ;
F_90 ( V_2 ) ;
V_98 = F_87 ( V_87 , V_2 ) ;
if ( V_98 ) {
if ( F_10 ( V_98 == - V_99 ) )
V_98 = - V_104 ;
if ( V_98 == - V_105 )
V_98 = - V_106 ;
F_97 ( V_2 ) ;
goto V_98;
}
F_98 () ;
F_2 ( V_2 ) -> V_100 = V_11 ;
V_98:
F_99 ( V_2 ) ;
return V_98 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_86 * V_87 ;
V_87 = & V_91 [ V_2 -> V_29 ] ;
if ( ! F_101 ( & V_87 -> V_88 , & F_2 ( V_2 ) -> V_90 ,
V_89 ) ) {
F_53 ( F_61 ( & V_2 -> V_107 ) == 1 ) ;
F_102 ( V_2 ) ;
}
F_62 () ;
if ( F_2 ( V_2 ) -> V_108 ) {
F_103 ( V_2 ) ;
F_91 ( V_2 ) ;
}
if ( V_2 -> V_29 == V_37 )
F_41 ( & V_109 ) ;
F_72 () ;
}
static int F_104 ( struct V_85 * V_85 , struct V_110 * V_1 ,
struct V_111 * V_112 , int V_43 ,
int V_113 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_1 -> V_114 = & V_115 ;
V_2 = F_105 ( V_85 , V_116 , V_117 , & V_118 , V_113 ) ;
if ( ! V_2 )
return - V_40 ;
F_106 ( V_1 , V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_112 ) {
V_51 -> V_112 = V_112 ;
} else {
V_51 -> V_112 = & V_51 -> V_119 ;
F_107 ( V_51 -> V_112 ) ;
}
F_108 ( & V_51 -> V_60 ) ;
V_2 -> V_120 = F_56 ;
V_2 -> V_29 = V_43 ;
return 0 ;
}
static int F_109 ( struct V_85 * V_85 , struct V_110 * V_1 , int V_43 ,
int V_113 )
{
struct V_23 * V_23 = NULL ;
struct V_111 * V_112 ;
struct V_50 * V_51 ;
int (* F_110)( struct V_85 * V_85 , int V_5 );
void (* F_111)( struct V_85 * V_85 , int V_5 );
int V_98 = 0 ;
V_1 -> V_54 = V_121 ;
if ( V_1 -> type != V_122 && V_1 -> type != V_123 )
return - V_124 ;
if ( V_43 < 0 || V_43 >= V_125 )
return - V_126 ;
F_74 () ;
#ifdef F_112
if ( ! V_91 [ V_43 ] . V_127 ) {
F_77 () ;
F_113 ( L_3 , V_116 , V_43 ) ;
F_74 () ;
}
#endif
if ( V_91 [ V_43 ] . V_127 &&
F_114 ( V_91 [ V_43 ] . V_23 ) )
V_23 = V_91 [ V_43 ] . V_23 ;
else
V_98 = - V_126 ;
V_112 = V_91 [ V_43 ] . V_112 ;
F_110 = V_91 [ V_43 ] . F_110 ;
F_111 = V_91 [ V_43 ] . F_111 ;
F_77 () ;
if ( V_98 < 0 )
goto V_26;
V_98 = F_104 ( V_85 , V_1 , V_112 , V_43 , V_113 ) ;
if ( V_98 < 0 )
goto V_128;
F_115 () ;
F_116 ( V_85 , & V_118 , 1 ) ;
F_117 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_23 = V_23 ;
V_51 -> V_129 = F_110 ;
V_51 -> V_130 = F_111 ;
V_26:
return V_98 ;
V_128:
F_19 ( V_23 ) ;
goto V_26;
}
static void F_118 ( struct V_131 * V_41 )
{
struct V_50 * V_51 = F_119 ( V_41 , struct V_50 , V_132 ) ;
F_97 ( & V_51 -> V_2 ) ;
}
static int F_120 ( struct V_110 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_100 ( V_2 ) ;
F_121 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_130 ) {
int V_94 ;
for ( V_94 = 0 ; V_94 < V_51 -> V_96 ; V_94 ++ )
if ( F_45 ( V_94 , V_51 -> V_72 ) )
V_51 -> V_130 ( F_81 ( V_2 ) , V_94 + 1 ) ;
}
if ( V_2 -> V_29 == V_37 &&
F_48 ( & V_109 ) == 0 )
F_73 ( & V_133 ) ;
V_1 -> V_2 = NULL ;
F_122 ( & V_51 -> V_60 ) ;
F_58 ( & V_2 -> V_134 ) ;
if ( V_51 -> V_11 && V_51 -> V_100 ) {
struct V_135 V_136 = {
. V_85 = F_81 ( V_2 ) ,
. V_43 = V_2 -> V_29 ,
. V_11 = V_51 -> V_11 ,
} ;
F_123 ( & V_137 ,
V_138 , & V_136 ) ;
}
F_19 ( V_51 -> V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_62 () ;
F_124 ( V_91 [ V_2 -> V_29 ] . V_127 == 0 ) ;
if ( -- V_91 [ V_2 -> V_29 ] . V_127 == 0 ) {
struct V_95 * V_139 ;
V_139 = F_92 ( V_91 [ V_2 -> V_29 ] . V_95 ) ;
F_125 ( V_91 [ V_2 -> V_29 ] . V_95 , NULL ) ;
F_126 ( V_139 , V_132 ) ;
V_91 [ V_2 -> V_29 ] . V_23 = NULL ;
V_91 [ V_2 -> V_29 ] . F_110 = NULL ;
V_91 [ V_2 -> V_29 ] . F_111 = NULL ;
V_91 [ V_2 -> V_29 ] . V_3 = 0 ;
V_91 [ V_2 -> V_29 ] . V_127 = 0 ;
}
F_72 () ;
}
F_127 ( V_51 -> V_72 ) ;
V_51 -> V_72 = NULL ;
F_115 () ;
F_116 ( F_81 ( V_2 ) , & V_118 , - 1 ) ;
F_117 () ;
F_128 ( & V_51 -> V_132 , F_118 ) ;
return 0 ;
}
static int F_129 ( struct V_110 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_85 * V_85 = F_81 ( V_2 ) ;
struct V_86 * V_87 = & V_91 [ V_2 -> V_29 ] ;
T_4 V_11 = F_130 ( V_74 ) ;
int V_98 ;
T_4 V_140 = - 4096 ;
bool V_141 ;
V_142:
F_131 () ;
F_35 () ;
V_141 = ! F_85 ( V_87 , V_11 , V_85 ) ;
F_37 () ;
if ( ! V_141 ) {
if ( V_140 == - 4096 )
V_140 = V_143 + F_132 ( - 4096 - V_143 ) ;
else if ( V_140 >= - 4096 )
V_140 = - 4097 ;
V_11 = V_140 -- ;
goto V_142;
}
V_98 = F_95 ( V_2 , V_11 ) ;
if ( V_98 == - V_106 )
goto V_142;
if ( V_98 == - V_99 )
V_98 = 0 ;
return V_98 ;
}
bool F_133 ( const struct V_144 * V_145 ,
struct V_146 * V_147 , int V_148 )
{
return ( ( V_145 -> V_3 & V_149 ) ||
F_134 ( V_145 -> V_2 -> V_150 -> V_151 , V_147 , V_148 ) ) &&
F_135 ( V_147 , V_148 ) ;
}
bool F_136 ( const struct V_6 * V_7 ,
struct V_146 * V_147 , int V_148 )
{
return F_133 ( & F_7 ( V_7 ) , V_147 , V_148 ) ;
}
bool F_137 ( const struct V_6 * V_7 , int V_148 )
{
return F_136 ( V_7 , & V_152 , V_148 ) ;
}
bool F_138 ( const struct V_6 * V_7 , int V_148 )
{
return F_136 ( V_7 , F_81 ( V_7 -> V_2 ) -> V_147 , V_148 ) ;
}
static inline int F_139 ( const struct V_110 * V_1 , unsigned int V_153 )
{
return ( V_91 [ V_1 -> V_2 -> V_29 ] . V_3 & V_153 ) ||
F_135 ( F_81 ( V_1 -> V_2 ) -> V_147 , V_154 ) ;
}
static void
F_140 ( struct V_1 * V_2 , unsigned int V_108 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_108 && ! V_108 )
F_103 ( V_2 ) ;
else if ( ! V_51 -> V_108 && V_108 )
F_141 ( V_2 , & V_91 [ V_2 -> V_29 ] . V_155 ) ;
V_51 -> V_108 = V_108 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_72 ;
unsigned long * V_156 ;
int V_98 = 0 ;
F_62 () ;
V_72 = V_91 [ V_2 -> V_29 ] . V_72 ;
if ( ! V_91 [ V_2 -> V_29 ] . V_127 ) {
V_98 = - V_157 ;
goto V_158;
}
if ( V_51 -> V_96 >= V_72 )
goto V_158;
V_156 = F_143 ( V_51 -> V_72 , F_144 ( V_72 ) , V_42 ) ;
if ( V_156 == NULL ) {
V_98 = - V_40 ;
goto V_158;
}
memset ( ( char * ) V_156 + F_144 ( V_51 -> V_96 ) , 0 ,
F_144 ( V_72 ) - F_144 ( V_51 -> V_96 ) ) ;
V_51 -> V_72 = V_156 ;
V_51 -> V_96 = V_72 ;
V_158:
F_72 () ;
return V_98 ;
}
static void F_145 ( int V_5 , long unsigned int V_72 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_159 ;
if ( ! V_51 -> V_130 )
return;
for ( V_159 = 0 ; V_159 < V_5 ; V_159 ++ )
if ( F_45 ( V_159 , & V_72 ) )
V_51 -> V_130 ( F_81 ( V_2 ) , V_159 + 1 ) ;
}
static int V_129 ( struct V_110 * V_1 , struct V_160 * V_161 ,
int V_162 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_85 * V_85 = F_81 ( V_2 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_163 * V_164 = (struct V_163 * ) V_161 ;
int V_98 ;
long unsigned int V_72 = V_164 -> V_165 ;
bool V_100 ;
if ( V_162 < sizeof( struct V_163 ) )
return - V_19 ;
if ( V_164 -> V_166 != V_167 )
return - V_19 ;
if ( V_72 ) {
if ( ! F_139 ( V_1 , V_168 ) )
return - V_169 ;
V_98 = F_142 ( V_2 ) ;
if ( V_98 )
return V_98 ;
}
V_100 = V_51 -> V_100 ;
if ( V_100 ) {
F_146 () ;
if ( V_164 -> V_170 != V_51 -> V_11 )
return - V_19 ;
}
if ( V_51 -> V_129 && V_72 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_51 -> V_96 ; V_5 ++ ) {
if ( ! F_45 ( V_5 , & V_72 ) )
continue;
V_98 = V_51 -> V_129 ( V_85 , V_5 + 1 ) ;
if ( ! V_98 )
continue;
F_145 ( V_5 , V_72 , V_2 ) ;
return V_98 ;
}
}
if ( ! V_100 ) {
V_98 = V_164 -> V_170 ?
F_95 ( V_2 , V_164 -> V_170 ) :
F_129 ( V_1 ) ;
if ( V_98 ) {
F_145 ( V_51 -> V_96 , V_72 , V_2 ) ;
return V_98 ;
}
}
if ( ! V_72 && ( V_51 -> V_72 == NULL || ! ( T_1 ) V_51 -> V_72 [ 0 ] ) )
return 0 ;
F_62 () ;
F_140 ( V_2 , V_51 -> V_108 +
F_147 ( V_72 ) -
F_147 ( V_51 -> V_72 [ 0 ] ) ) ;
V_51 -> V_72 [ 0 ] = ( V_51 -> V_72 [ 0 ] & ~ 0xffffffffUL ) | V_72 ;
F_91 ( V_2 ) ;
F_72 () ;
return 0 ;
}
static int F_148 ( struct V_110 * V_1 , struct V_160 * V_161 ,
int V_171 , int V_3 )
{
int V_98 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_163 * V_164 = (struct V_163 * ) V_161 ;
if ( V_171 < sizeof( V_161 -> V_172 ) )
return - V_19 ;
if ( V_161 -> V_172 == V_173 ) {
V_2 -> V_174 = V_175 ;
V_51 -> V_176 = 0 ;
V_51 -> V_12 = 0 ;
return 0 ;
}
if ( V_161 -> V_172 != V_167 )
return - V_19 ;
if ( ( V_164 -> V_165 || V_164 -> V_170 ) &&
! F_139 ( V_1 , V_177 ) )
return - V_169 ;
if ( ! V_51 -> V_100 )
V_98 = F_129 ( V_1 ) ;
if ( V_98 == 0 ) {
V_2 -> V_174 = V_178 ;
V_51 -> V_176 = V_164 -> V_170 ;
V_51 -> V_12 = F_149 ( V_164 -> V_165 ) ;
}
return V_98 ;
}
static int F_150 ( struct V_110 * V_1 , struct V_160 * V_161 ,
int * V_162 , int V_179 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_151 ( struct V_163 * , V_164 , V_161 ) ;
V_164 -> V_166 = V_167 ;
V_164 -> V_180 = 0 ;
* V_162 = sizeof( * V_164 ) ;
if ( V_179 ) {
V_164 -> V_170 = V_51 -> V_176 ;
V_164 -> V_165 = F_3 ( V_51 -> V_12 ) ;
} else {
V_164 -> V_170 = V_51 -> V_11 ;
V_164 -> V_165 = V_51 -> V_72 ? V_51 -> V_72 [ 0 ] : 0 ;
}
return 0 ;
}
static int F_152 ( struct V_110 * V_1 , unsigned int V_181 ,
unsigned long V_79 )
{
return - V_182 ;
}
static struct V_1 * F_153 ( struct V_1 * V_183 , T_1 V_11 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_89 ( F_81 ( V_183 ) , V_183 -> V_29 , V_11 ) ;
if ( ! V_1 )
return F_154 ( - V_184 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_174 == V_178 &&
V_51 -> V_176 != F_2 ( V_183 ) -> V_11 ) {
F_97 ( V_1 ) ;
return F_154 ( - V_184 ) ;
}
return V_1 ;
}
struct V_1 * F_155 ( struct V_151 * V_185 )
{
struct V_186 * V_186 = F_156 ( V_185 ) ;
struct V_1 * V_1 ;
if ( ! F_157 ( V_186 -> V_187 ) )
return F_154 ( - V_188 ) ;
V_1 = F_158 ( V_186 ) -> V_2 ;
if ( V_1 -> V_189 != V_167 )
return F_154 ( - V_19 ) ;
F_90 ( V_1 ) ;
return V_1 ;
}
static struct V_6 * F_159 ( unsigned int V_190 ,
int V_191 )
{
struct V_6 * V_7 ;
void * V_14 ;
if ( V_190 <= V_192 || V_191 )
return F_6 ( V_190 , V_117 ) ;
V_190 = F_160 ( V_190 ) +
F_160 ( sizeof( struct V_193 ) ) ;
V_14 = F_161 ( V_190 ) ;
if ( V_14 == NULL )
return NULL ;
V_7 = F_162 ( V_14 , V_190 ) ;
if ( V_7 == NULL )
F_50 ( V_14 ) ;
else
V_7 -> V_63 = F_47 ;
return V_7 ;
}
int F_163 ( struct V_1 * V_2 , struct V_6 * V_7 ,
long * V_194 , struct V_1 * V_183 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_195 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) ) {
F_65 ( V_60 , V_74 ) ;
if ( ! * V_194 ) {
if ( ! V_183 || F_1 ( V_183 ) )
F_39 ( V_2 ) ;
F_97 ( V_2 ) ;
F_57 ( V_7 ) ;
return - V_196 ;
}
F_70 ( V_197 ) ;
F_164 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_195 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) &&
! F_59 ( V_2 , V_69 ) )
* V_194 = F_165 ( * V_194 ) ;
F_70 ( V_77 ) ;
F_71 ( & V_51 -> V_60 , & V_60 ) ;
F_97 ( V_2 ) ;
if ( F_166 ( V_74 ) ) {
F_57 ( V_7 ) ;
return F_167 ( * V_194 ) ;
}
return 1 ;
}
F_52 ( V_7 , V_2 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = V_7 -> V_9 ;
F_34 ( V_7 ) ;
F_169 ( & V_2 -> V_59 , V_7 ) ;
V_2 -> V_198 ( V_2 ) ;
return V_9 ;
}
int F_170 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = F_168 ( V_2 , V_7 ) ;
F_97 ( V_2 ) ;
return V_9 ;
}
void F_171 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_57 ( V_7 ) ;
F_97 ( V_2 ) ;
}
static struct V_6 * F_172 ( struct V_6 * V_7 , T_2 V_199 )
{
int V_200 ;
F_53 ( V_7 -> V_2 != NULL ) ;
V_200 = V_7 -> V_201 - V_7 -> V_202 ;
if ( F_25 ( V_7 -> V_41 ) || V_200 * 2 < V_7 -> V_64 )
return V_7 ;
if ( F_173 ( V_7 ) ) {
struct V_6 * V_39 = F_26 ( V_7 , V_199 ) ;
if ( ! V_39 )
return V_7 ;
F_174 ( V_7 ) ;
V_7 = V_39 ;
}
if ( ! F_175 ( V_7 , 0 , - V_200 , V_199 ) )
V_7 -> V_64 -= V_200 ;
return V_7 ;
}
static int F_176 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_183 )
{
int V_28 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
V_28 = - V_184 ;
if ( V_51 -> V_203 != NULL ) {
V_28 = V_7 -> V_9 ;
F_52 ( V_7 , V_2 ) ;
F_7 ( V_7 ) . V_2 = V_183 ;
F_38 ( V_2 , V_183 , V_7 ) ;
V_51 -> V_203 ( V_7 ) ;
F_174 ( V_7 ) ;
} else {
F_57 ( V_7 ) ;
}
F_97 ( V_2 ) ;
return V_28 ;
}
int F_177 ( struct V_1 * V_183 , struct V_6 * V_7 ,
T_1 V_11 , int V_204 )
{
struct V_1 * V_2 ;
int V_98 ;
long V_194 ;
V_7 = F_172 ( V_7 , F_178 () ) ;
V_194 = F_179 ( V_183 , V_204 ) ;
V_142:
V_2 = F_153 ( V_183 , V_11 ) ;
if ( F_180 ( V_2 ) ) {
F_57 ( V_7 ) ;
return F_181 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_176 ( V_2 , V_7 , V_183 ) ;
if ( F_182 ( V_2 , V_7 ) ) {
V_98 = V_7 -> V_9 ;
F_57 ( V_7 ) ;
F_97 ( V_2 ) ;
return V_98 ;
}
V_98 = F_163 ( V_2 , V_7 , & V_194 , V_183 ) ;
if ( V_98 == 1 )
goto V_142;
if ( V_98 )
return V_98 ;
return F_170 ( V_2 , V_7 ) ;
}
int F_183 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_205 = 0 ;
struct V_95 * V_95 ;
F_124 ( ! F_1 ( V_2 ) ) ;
F_35 () ;
V_95 = F_184 ( V_91 [ V_2 -> V_29 ] . V_95 ) ;
if ( V_95 && V_5 - 1 < V_91 [ V_2 -> V_29 ] . V_72 )
V_205 = F_45 ( V_5 - 1 , V_95 -> V_97 ) ;
F_37 () ;
return V_205 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_61 ( & V_2 -> V_65 ) <= V_2 -> V_195 &&
! F_45 ( V_53 , & V_51 -> V_54 ) ) {
F_52 ( V_7 , V_2 ) ;
F_168 ( V_2 , V_7 ) ;
return F_61 ( & V_2 -> V_65 ) > ( V_2 -> V_195 >> 1 ) ;
}
return - 1 ;
}
static void F_186 ( struct V_1 * V_2 ,
struct V_206 * V_207 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_208 ;
if ( V_207 -> V_209 == V_2 )
return;
if ( V_51 -> V_11 == V_207 -> V_11 || V_207 -> V_5 - 1 >= V_51 -> V_96 ||
! F_45 ( V_207 -> V_5 - 1 , V_51 -> V_72 ) )
return;
if ( ! F_80 ( F_81 ( V_2 ) , V_207 -> V_85 ) ) {
if ( ! ( V_51 -> V_3 & V_210 ) )
return;
if ( ! F_187 ( F_81 ( V_2 ) , V_207 -> V_85 ) )
return;
if ( ! F_134 ( V_2 -> V_150 -> V_151 , V_207 -> V_85 -> V_147 ,
V_211 ) )
return;
}
if ( V_207 -> V_212 ) {
F_39 ( V_2 ) ;
return;
}
F_90 ( V_2 ) ;
if ( V_207 -> V_213 == NULL ) {
if ( F_173 ( V_207 -> V_7 ) ) {
V_207 -> V_213 = F_26 ( V_207 -> V_7 , V_207 -> V_199 ) ;
} else {
V_207 -> V_213 = F_188 ( V_207 -> V_7 ) ;
F_189 ( V_207 -> V_213 ) ;
}
}
if ( V_207 -> V_213 == NULL ) {
F_39 ( V_2 ) ;
V_207 -> V_212 = 1 ;
if ( V_51 -> V_3 & V_214 )
V_207 -> V_215 = 1 ;
goto V_26;
}
if ( V_207 -> V_216 && V_207 -> V_216 ( V_2 , V_207 -> V_213 , V_207 -> V_217 ) ) {
F_57 ( V_207 -> V_213 ) ;
V_207 -> V_213 = NULL ;
goto V_26;
}
if ( F_182 ( V_2 , V_207 -> V_213 ) ) {
F_57 ( V_207 -> V_213 ) ;
V_207 -> V_213 = NULL ;
goto V_26;
}
F_7 ( V_207 -> V_213 ) . V_218 = F_190 ( F_81 ( V_2 ) , V_207 -> V_85 ) ;
F_7 ( V_207 -> V_213 ) . V_219 = true ;
V_208 = F_185 ( V_2 , V_207 -> V_213 ) ;
if ( V_208 < 0 ) {
F_39 ( V_2 ) ;
if ( V_51 -> V_3 & V_214 )
V_207 -> V_215 = 1 ;
} else {
V_207 -> V_220 |= V_208 ;
V_207 -> V_221 = 1 ;
V_207 -> V_213 = NULL ;
}
V_26:
F_97 ( V_2 ) ;
}
int F_191 ( struct V_1 * V_183 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_199 ,
int (* F_192)( struct V_1 * V_222 , struct V_6 * V_7 , void * V_14 ) ,
void * V_223 )
{
struct V_85 * V_85 = F_81 ( V_183 ) ;
struct V_206 V_224 ;
struct V_1 * V_2 ;
V_7 = F_172 ( V_7 , V_199 ) ;
V_224 . V_209 = V_183 ;
V_224 . V_85 = V_85 ;
V_224 . V_11 = V_11 ;
V_224 . V_5 = V_5 ;
V_224 . V_212 = 0 ;
V_224 . V_215 = 0 ;
V_224 . V_220 = 0 ;
V_224 . V_221 = 0 ;
V_224 . V_199 = V_199 ;
V_224 . V_7 = V_7 ;
V_224 . V_213 = NULL ;
V_224 . V_216 = F_192 ;
V_224 . V_217 = V_223 ;
F_74 () ;
F_94 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_186 ( V_2 , & V_224 ) ;
F_174 ( V_7 ) ;
F_77 () ;
if ( V_224 . V_215 ) {
F_57 ( V_224 . V_213 ) ;
return - V_56 ;
}
F_174 ( V_224 . V_213 ) ;
if ( V_224 . V_221 ) {
if ( V_224 . V_220 && F_193 ( V_199 ) )
F_194 () ;
return 0 ;
}
return - V_225 ;
}
int F_195 ( struct V_1 * V_183 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_199 )
{
return F_191 ( V_183 , V_7 , V_11 , V_5 , V_199 ,
NULL , NULL ) ;
}
static int F_196 ( struct V_1 * V_2 , struct V_226 * V_207 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_28 = 0 ;
if ( V_2 == V_207 -> V_209 )
goto V_26;
if ( ! F_80 ( F_81 ( V_2 ) , F_81 ( V_207 -> V_209 ) ) )
goto V_26;
if ( V_51 -> V_11 == V_207 -> V_11 || V_207 -> V_5 - 1 >= V_51 -> V_96 ||
! F_45 ( V_207 -> V_5 - 1 , V_51 -> V_72 ) )
goto V_26;
if ( V_207 -> V_227 == V_56 && V_51 -> V_3 & V_52 ) {
V_28 = 1 ;
goto V_26;
}
V_2 -> V_55 = V_207 -> V_227 ;
V_2 -> V_57 ( V_2 ) ;
V_26:
return V_28 ;
}
int F_197 ( struct V_1 * V_183 , T_1 V_11 , T_1 V_5 , int V_227 )
{
struct V_226 V_224 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
V_224 . V_209 = V_183 ;
V_224 . V_11 = V_11 ;
V_224 . V_5 = V_5 ;
V_224 . V_227 = - V_227 ;
F_75 ( & T_3 ) ;
F_94 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_28 += F_196 ( V_2 , & V_224 ) ;
F_76 ( & T_3 ) ;
return V_28 ;
}
static void F_198 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_228 )
{
int V_139 , V_10 = ! ! V_228 , V_108 ;
V_139 = F_45 ( V_5 - 1 , V_51 -> V_72 ) ;
V_108 = V_51 -> V_108 - V_139 + V_10 ;
if ( V_10 )
F_199 ( V_5 - 1 , V_51 -> V_72 ) ;
else
F_200 ( V_5 - 1 , V_51 -> V_72 ) ;
F_140 ( & V_51 -> V_2 , V_108 ) ;
F_91 ( & V_51 -> V_2 ) ;
}
static int F_201 ( struct V_110 * V_1 , int V_229 , int V_230 ,
char T_5 * V_231 , unsigned int V_232 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_208 = 0 ;
int V_98 ;
if ( V_229 != V_233 )
return - V_234 ;
if ( V_232 >= sizeof( int ) &&
F_202 ( V_208 , ( unsigned int T_5 * ) V_231 ) )
return - V_235 ;
switch ( V_230 ) {
case V_236 :
if ( V_208 )
V_51 -> V_3 |= V_237 ;
else
V_51 -> V_3 &= ~ V_237 ;
V_98 = 0 ;
break;
case V_238 :
case V_239 : {
if ( ! F_139 ( V_1 , V_168 ) )
return - V_169 ;
V_98 = F_142 ( V_2 ) ;
if ( V_98 )
return V_98 ;
if ( ! V_208 || V_208 - 1 >= V_51 -> V_96 )
return - V_19 ;
if ( V_230 == V_238 && V_51 -> V_129 ) {
V_98 = V_51 -> V_129 ( F_81 ( V_2 ) , V_208 ) ;
if ( V_98 )
return V_98 ;
}
F_62 () ;
F_198 ( V_51 , V_208 ,
V_230 == V_238 ) ;
F_72 () ;
if ( V_230 == V_239 && V_51 -> V_130 )
V_51 -> V_130 ( F_81 ( V_2 ) , V_208 ) ;
V_98 = 0 ;
break;
}
case V_240 :
if ( V_208 )
V_51 -> V_3 |= V_214 ;
else
V_51 -> V_3 &= ~ V_214 ;
V_98 = 0 ;
break;
case V_241 :
if ( V_208 ) {
V_51 -> V_3 |= V_52 ;
F_44 ( V_53 , & V_51 -> V_54 ) ;
F_46 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_98 = 0 ;
break;
case V_242 :
if ( ! F_135 ( F_81 ( V_2 ) -> V_147 , V_211 ) )
return - V_169 ;
if ( V_208 )
V_51 -> V_3 |= V_210 ;
else
V_51 -> V_3 &= ~ V_210 ;
V_98 = 0 ;
break;
case V_243 :
if ( V_208 )
V_51 -> V_3 |= V_244 ;
else
V_51 -> V_3 &= ~ V_244 ;
V_98 = 0 ;
break;
default:
V_98 = - V_234 ;
}
return V_98 ;
}
static int F_203 ( struct V_110 * V_1 , int V_229 , int V_230 ,
char T_5 * V_231 , int T_5 * V_232 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_9 , V_208 , V_98 ;
if ( V_229 != V_233 )
return - V_234 ;
if ( F_202 ( V_9 , V_232 ) )
return - V_235 ;
if ( V_9 < 0 )
return - V_19 ;
switch ( V_230 ) {
case V_236 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_208 = V_51 -> V_3 & V_237 ? 1 : 0 ;
if ( F_204 ( V_9 , V_232 ) ||
F_204 ( V_208 , V_231 ) )
return - V_235 ;
V_98 = 0 ;
break;
case V_240 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_208 = V_51 -> V_3 & V_214 ? 1 : 0 ;
if ( F_204 ( V_9 , V_232 ) ||
F_204 ( V_208 , V_231 ) )
return - V_235 ;
V_98 = 0 ;
break;
case V_241 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_208 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_204 ( V_9 , V_232 ) ||
F_204 ( V_208 , V_231 ) )
return - V_235 ;
V_98 = 0 ;
break;
case V_245 : {
int V_246 , V_247 , V_248 ;
V_98 = 0 ;
F_74 () ;
for ( V_246 = 0 ; V_246 * 8 < V_51 -> V_96 ; V_246 += sizeof( T_1 ) ) {
if ( V_9 - V_246 < sizeof( T_1 ) )
break;
V_247 = V_246 / sizeof( unsigned long ) ;
V_248 = ( V_246 % sizeof( unsigned long ) ) * 8 ;
if ( F_204 ( ( T_1 ) ( V_51 -> V_72 [ V_247 ] >> V_248 ) ,
( T_1 T_5 * ) ( V_231 + V_246 ) ) ) {
V_98 = - V_235 ;
break;
}
}
if ( F_204 ( F_205 ( V_51 -> V_96 / 8 , sizeof( T_1 ) ) , V_232 ) )
V_98 = - V_235 ;
F_77 () ;
break;
}
case V_243 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_208 = V_51 -> V_3 & V_244 ? 1 : 0 ;
if ( F_204 ( V_9 , V_232 ) ||
F_204 ( V_208 , V_231 ) )
return - V_235 ;
V_98 = 0 ;
break;
default:
V_98 = - V_234 ;
}
return V_98 ;
}
static void F_206 ( struct V_249 * V_250 , struct V_6 * V_7 )
{
struct V_251 V_224 ;
V_224 . V_5 = F_7 ( V_7 ) . V_12 ;
F_207 ( V_250 , V_233 , V_236 , sizeof( V_224 ) , & V_224 ) ;
}
static void F_208 ( struct V_1 * V_2 , struct V_249 * V_250 ,
struct V_6 * V_7 )
{
if ( ! F_7 ( V_7 ) . V_219 )
return;
F_207 ( V_250 , V_233 , V_242 , sizeof( int ) ,
& F_7 ( V_7 ) . V_218 ) ;
}
static int F_209 ( struct V_110 * V_1 , struct V_249 * V_250 , T_6 V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_151 ( struct V_163 * , V_161 , V_250 -> V_252 ) ;
T_1 V_176 ;
T_1 V_12 ;
struct V_6 * V_7 ;
int V_98 ;
struct V_253 V_254 ;
T_1 V_255 = 0 ;
if ( V_250 -> V_256 & V_257 )
return - V_258 ;
V_98 = F_210 ( V_1 , V_250 , & V_254 , true ) ;
if ( V_98 < 0 )
return V_98 ;
if ( V_250 -> V_259 ) {
V_98 = - V_19 ;
if ( V_161 -> V_166 != V_167 )
goto V_26;
V_176 = V_161 -> V_170 ;
V_12 = F_149 ( V_161 -> V_165 ) ;
V_98 = - V_169 ;
if ( ( V_12 || V_176 ) &&
! F_139 ( V_1 , V_177 ) )
goto V_26;
V_255 |= V_149 ;
} else {
V_176 = V_51 -> V_176 ;
V_12 = V_51 -> V_12 ;
}
if ( ! V_51 -> V_100 ) {
V_98 = F_129 ( V_1 ) ;
if ( V_98 )
goto V_26;
} else {
F_146 () ;
}
V_98 = - V_260 ;
if ( V_9 > V_2 -> V_261 - 32 )
goto V_26;
V_98 = - V_56 ;
V_7 = F_159 ( V_9 , V_12 ) ;
if ( V_7 == NULL )
goto V_26;
F_7 ( V_7 ) . V_11 = V_51 -> V_11 ;
F_7 ( V_7 ) . V_12 = V_12 ;
F_7 ( V_7 ) . V_13 = V_254 . V_13 ;
F_7 ( V_7 ) . V_3 = V_255 ;
V_98 = - V_235 ;
if ( F_211 ( F_8 ( V_7 , V_9 ) , V_250 , V_9 ) ) {
F_57 ( V_7 ) ;
goto V_26;
}
V_98 = F_212 ( V_2 , V_7 ) ;
if ( V_98 ) {
F_57 ( V_7 ) ;
goto V_26;
}
if ( V_12 ) {
F_41 ( & V_7 -> V_262 ) ;
F_195 ( V_2 , V_7 , V_176 , V_12 , V_117 ) ;
}
V_98 = F_177 ( V_2 , V_7 , V_176 , V_250 -> V_256 & V_263 ) ;
V_26:
F_213 ( & V_254 ) ;
return V_98 ;
}
static int F_214 ( struct V_110 * V_1 , struct V_249 * V_250 , T_6 V_9 ,
int V_3 )
{
struct V_253 V_254 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_264 = V_3 & V_263 ;
T_6 V_265 ;
struct V_6 * V_7 , * V_266 ;
int V_98 , V_28 ;
if ( V_3 & V_257 )
return - V_258 ;
V_265 = 0 ;
V_7 = F_215 ( V_2 , V_3 , V_264 , & V_98 ) ;
if ( V_7 == NULL )
goto V_26;
V_266 = V_7 ;
#ifdef F_216
if ( F_10 ( F_49 ( V_7 ) -> V_267 ) ) {
if ( V_3 & V_268 )
V_266 = F_49 ( V_7 ) -> V_267 ;
}
#endif
V_51 -> V_269 = F_217 ( V_51 -> V_269 , V_9 ) ;
V_51 -> V_269 = F_218 ( T_6 , V_51 -> V_269 ,
16384 ) ;
V_265 = V_266 -> V_9 ;
if ( V_9 < V_265 ) {
V_250 -> V_256 |= V_270 ;
V_265 = V_9 ;
}
F_219 ( V_266 ) ;
V_98 = F_220 ( V_266 , 0 , V_250 , V_265 ) ;
if ( V_250 -> V_252 ) {
F_151 ( struct V_163 * , V_161 , V_250 -> V_252 ) ;
V_161 -> V_166 = V_167 ;
V_161 -> V_180 = 0 ;
V_161 -> V_170 = F_7 ( V_7 ) . V_11 ;
V_161 -> V_165 = F_3 ( F_7 ( V_7 ) . V_12 ) ;
V_250 -> V_259 = sizeof( * V_161 ) ;
}
if ( V_51 -> V_3 & V_237 )
F_206 ( V_250 , V_7 ) ;
if ( V_51 -> V_3 & V_210 )
F_208 ( V_2 , V_250 , V_7 ) ;
memset ( & V_254 , 0 , sizeof( V_254 ) ) ;
V_254 . V_13 = * F_221 ( V_7 ) ;
if ( V_3 & V_270 )
V_265 = V_266 -> V_9 ;
F_222 ( V_2 , V_7 ) ;
if ( V_51 -> V_66 &&
F_61 ( & V_2 -> V_65 ) <= V_2 -> V_195 / 2 ) {
V_28 = F_223 ( V_2 ) ;
if ( V_28 ) {
V_2 -> V_55 = - V_28 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_224 ( V_1 , V_250 , & V_254 , V_3 ) ;
V_26:
F_42 ( V_2 ) ;
return V_98 ? : V_265 ;
}
static void F_225 ( struct V_1 * V_2 )
{
F_226 () ;
}
struct V_1 *
F_227 ( struct V_85 * V_85 , int V_271 , struct V_23 * V_23 ,
struct V_272 * V_273 )
{
struct V_110 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_95 * V_95 = NULL ;
struct V_111 * V_112 = V_273 ? V_273 -> V_112 : NULL ;
unsigned int V_72 ;
F_124 ( ! V_91 ) ;
if ( V_271 < 0 || V_271 >= V_125 )
return NULL ;
if ( F_228 ( V_116 , V_123 , V_271 , & V_1 ) )
return NULL ;
if ( F_104 ( V_85 , V_1 , V_112 , V_271 , 1 ) < 0 )
goto V_274;
V_2 = V_1 -> V_2 ;
if ( ! V_273 || V_273 -> V_72 < 32 )
V_72 = 32 ;
else
V_72 = V_273 -> V_72 ;
V_95 = F_229 ( sizeof( * V_95 ) + F_144 ( V_72 ) , V_117 ) ;
if ( ! V_95 )
goto V_275;
V_2 -> V_198 = F_225 ;
if ( V_273 && V_273 -> V_276 )
F_2 ( V_2 ) -> V_203 = V_273 -> V_276 ;
if ( F_95 ( V_2 , 0 ) )
goto V_275;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_62 () ;
if ( ! V_91 [ V_271 ] . V_127 ) {
V_91 [ V_271 ] . V_72 = V_72 ;
F_230 ( V_91 [ V_271 ] . V_95 , V_95 ) ;
V_91 [ V_271 ] . V_112 = V_112 ;
V_91 [ V_271 ] . V_23 = V_23 ;
if ( V_273 ) {
V_91 [ V_271 ] . F_110 = V_273 -> F_110 ;
V_91 [ V_271 ] . F_111 = V_273 -> F_111 ;
V_91 [ V_271 ] . V_3 = V_273 -> V_3 ;
if ( V_273 -> V_277 )
V_91 [ V_271 ] . V_277 = V_273 -> V_277 ;
}
V_91 [ V_271 ] . V_127 = 1 ;
} else {
F_127 ( V_95 ) ;
V_91 [ V_271 ] . V_127 ++ ;
}
F_72 () ;
return V_2 ;
V_275:
F_127 ( V_95 ) ;
F_231 ( V_2 ) ;
return NULL ;
V_274:
F_232 ( V_1 ) ;
return NULL ;
}
void
F_231 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_150 == NULL )
return;
F_232 ( V_2 -> V_150 ) ;
}
int F_233 ( struct V_1 * V_2 , unsigned int V_72 )
{
struct V_95 * V_10 , * V_139 ;
struct V_86 * V_92 = & V_91 [ V_2 -> V_29 ] ;
if ( V_72 < 32 )
V_72 = 32 ;
if ( F_144 ( V_92 -> V_72 ) < F_144 ( V_72 ) ) {
V_10 = F_229 ( sizeof( * V_10 ) + F_144 ( V_72 ) , V_42 ) ;
if ( ! V_10 )
return - V_40 ;
V_139 = F_92 ( V_92 -> V_95 ) ;
memcpy ( V_10 -> V_97 , V_139 -> V_97 , F_144 ( V_92 -> V_72 ) ) ;
F_230 ( V_92 -> V_95 , V_10 ) ;
F_126 ( V_139 , V_132 ) ;
}
V_92 -> V_72 = V_72 ;
return 0 ;
}
int F_234 ( struct V_1 * V_2 , unsigned int V_72 )
{
int V_98 ;
F_62 () ;
V_98 = F_233 ( V_2 , V_72 ) ;
F_72 () ;
return V_98 ;
}
void F_235 ( struct V_1 * V_278 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_86 * V_92 = & V_91 [ V_278 -> V_29 ] ;
F_94 (sk, &tbl->mc_list)
F_198 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_279 *
F_236 ( struct V_6 * V_7 , T_1 V_11 , T_1 V_280 , int type , int V_9 , int V_3 )
{
struct V_279 * V_281 ;
int V_190 = F_237 ( V_9 ) ;
V_281 = (struct V_279 * ) F_8 ( V_7 , F_238 ( V_190 ) ) ;
V_281 -> V_282 = type ;
V_281 -> V_283 = V_190 ;
V_281 -> V_284 = V_3 ;
V_281 -> V_285 = V_11 ;
V_281 -> V_286 = V_280 ;
if ( ! F_239 ( V_190 ) || F_238 ( V_190 ) - V_190 != 0 )
memset ( F_240 ( V_281 ) + V_9 , 0 , F_238 ( V_190 ) - V_190 ) ;
return V_281 ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_287 * V_67 ;
struct V_6 * V_7 = NULL ;
struct V_279 * V_281 ;
struct V_23 * V_23 ;
int V_9 , V_98 = - V_56 ;
int V_288 ;
int V_289 ;
F_241 ( V_51 -> V_112 ) ;
if ( ! V_51 -> V_66 ) {
V_98 = - V_19 ;
goto V_290;
}
if ( F_61 ( & V_2 -> V_65 ) >= V_2 -> V_195 )
goto V_290;
V_67 = & V_51 -> V_67 ;
V_288 = F_242 ( int , V_67 -> V_291 , V_192 ) ;
if ( V_288 < V_51 -> V_269 ) {
V_289 = V_51 -> V_269 ;
V_7 = F_6 ( V_289 , V_117 |
V_292 | V_293 ) ;
}
if ( ! V_7 ) {
V_289 = V_288 ;
V_7 = F_6 ( V_289 , V_117 ) ;
}
if ( ! V_7 )
goto V_290;
F_243 ( V_7 , F_244 ( V_7 ) - V_289 ) ;
F_52 ( V_7 , V_2 ) ;
V_9 = V_67 -> V_294 ( V_7 , V_67 ) ;
if ( V_9 > 0 ) {
F_245 ( V_51 -> V_112 ) ;
if ( F_182 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_168 ( V_2 , V_7 ) ;
return 0 ;
}
V_281 = F_246 ( V_7 , V_67 , V_295 , sizeof( V_9 ) , V_296 ) ;
if ( ! V_281 )
goto V_290;
F_247 ( V_67 , V_281 ) ;
memcpy ( F_240 ( V_281 ) , & V_9 , sizeof( V_9 ) ) ;
if ( F_182 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_168 ( V_2 , V_7 ) ;
if ( V_67 -> V_68 )
V_67 -> V_68 ( V_67 ) ;
V_51 -> V_66 = false ;
V_23 = V_67 -> V_23 ;
V_7 = V_67 -> V_7 ;
F_245 ( V_51 -> V_112 ) ;
F_19 ( V_23 ) ;
F_174 ( V_7 ) ;
return 0 ;
V_290:
F_245 ( V_51 -> V_112 ) ;
F_57 ( V_7 ) ;
return V_98 ;
}
int F_248 ( struct V_1 * V_183 , struct V_6 * V_7 ,
const struct V_279 * V_281 ,
struct V_297 * V_298 )
{
struct V_287 * V_67 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_28 ;
F_41 ( & V_7 -> V_262 ) ;
V_2 = F_89 ( F_81 ( V_183 ) , V_183 -> V_29 , F_7 ( V_7 ) . V_11 ) ;
if ( V_2 == NULL ) {
V_28 = - V_184 ;
goto V_299;
}
V_51 = F_2 ( V_2 ) ;
F_241 ( V_51 -> V_112 ) ;
if ( V_51 -> V_66 ) {
V_28 = - V_99 ;
goto V_300;
}
if ( ! F_114 ( V_298 -> V_23 ) ) {
V_28 = - V_126 ;
goto V_300;
}
V_67 = & V_51 -> V_67 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_301 = V_298 -> V_301 ;
V_67 -> V_294 = V_298 -> V_294 ;
V_67 -> V_68 = V_298 -> V_68 ;
V_67 -> V_281 = V_281 ;
V_67 -> V_14 = V_298 -> V_14 ;
V_67 -> V_23 = V_298 -> V_23 ;
V_67 -> V_291 = V_298 -> V_291 ;
V_67 -> V_7 = V_7 ;
V_51 -> V_66 = true ;
F_245 ( V_51 -> V_112 ) ;
if ( V_67 -> V_301 )
V_67 -> V_301 ( V_67 ) ;
V_28 = F_223 ( V_2 ) ;
F_97 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return - V_302 ;
V_300:
F_97 ( V_2 ) ;
F_245 ( V_51 -> V_112 ) ;
V_299:
F_57 ( V_7 ) ;
return V_28 ;
}
void F_249 ( struct V_6 * V_303 , struct V_279 * V_281 , int V_98 )
{
struct V_6 * V_7 ;
struct V_279 * V_304 ;
struct V_305 * V_306 ;
T_6 V_307 = sizeof( * V_306 ) ;
struct V_50 * V_51 = F_2 ( F_7 ( V_303 ) . V_2 ) ;
if ( ! ( V_51 -> V_3 & V_244 ) && V_98 )
V_307 += V_283 ( V_281 ) ;
V_7 = F_250 ( V_307 , V_117 ) ;
if ( ! V_7 ) {
struct V_1 * V_2 ;
V_2 = F_89 ( F_81 ( V_303 -> V_2 ) ,
V_303 -> V_2 -> V_29 ,
F_7 ( V_303 ) . V_11 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_97 ( V_2 ) ;
}
return;
}
V_304 = F_236 ( V_7 , F_7 ( V_303 ) . V_11 , V_281 -> V_286 ,
V_308 , V_307 , 0 ) ;
V_306 = F_240 ( V_304 ) ;
V_306 -> error = V_98 ;
memcpy ( & V_306 -> V_250 , V_281 , V_307 > sizeof( * V_306 ) ? V_281 -> V_283 : sizeof( * V_281 ) ) ;
F_177 ( V_303 -> V_2 , V_7 , F_7 ( V_303 ) . V_11 , V_263 ) ;
}
int F_251 ( struct V_6 * V_7 , int (* V_67)( struct V_6 * ,
struct V_279 * ) )
{
struct V_279 * V_281 ;
int V_98 ;
while ( V_7 -> V_9 >= F_252 ( 0 ) ) {
int V_309 ;
V_281 = F_253 ( V_7 ) ;
V_98 = 0 ;
if ( V_281 -> V_283 < V_310 || V_7 -> V_9 < V_281 -> V_283 )
return 0 ;
if ( ! ( V_281 -> V_284 & V_311 ) )
goto V_312;
if ( V_281 -> V_282 < V_313 )
goto V_312;
V_98 = V_67 ( V_7 , V_281 ) ;
if ( V_98 == - V_302 )
goto V_314;
V_312:
if ( V_281 -> V_284 & V_315 || V_98 )
F_249 ( V_7 , V_281 , V_98 ) ;
V_314:
V_309 = F_238 ( V_281 -> V_283 ) ;
if ( V_309 > V_7 -> V_9 )
V_309 = V_7 -> V_9 ;
F_254 ( V_7 , V_309 ) ;
}
return 0 ;
}
int F_255 ( struct V_1 * V_2 , struct V_6 * V_7 , T_1 V_11 ,
unsigned int V_5 , int V_316 , T_2 V_3 )
{
int V_98 = 0 ;
if ( V_5 ) {
int V_317 = 0 ;
if ( V_316 ) {
F_41 ( & V_7 -> V_262 ) ;
V_317 = V_11 ;
}
V_98 = F_256 ( V_2 , V_7 , V_317 , V_5 , V_3 ) ;
}
if ( V_316 ) {
int V_318 ;
V_318 = F_257 ( V_2 , V_7 , V_11 ) ;
if ( ! V_98 || V_98 == - V_225 )
V_98 = V_318 ;
}
return V_98 ;
}
static int F_258 ( struct V_319 * V_320 )
{
int V_98 ;
V_98 = F_259 ( & V_91 [ V_320 -> V_321 ] . V_88 , & V_320 -> V_322 ,
V_117 ) ;
if ( V_98 ) {
V_320 -> V_321 = V_125 ;
return V_98 ;
}
V_98 = F_260 ( & V_320 -> V_322 ) ;
return V_98 == - V_196 ? 0 : V_98 ;
}
static void F_261 ( struct V_319 * V_320 )
{
F_262 ( & V_320 -> V_322 ) ;
F_263 ( & V_320 -> V_322 ) ;
}
static void * F_264 ( struct V_323 * V_280 )
{
struct V_319 * V_320 = V_280 -> V_324 ;
struct V_50 * V_51 ;
do {
for (; ; ) {
int V_98 ;
V_51 = F_265 ( & V_320 -> V_322 ) ;
if ( F_180 ( V_51 ) ) {
if ( F_181 ( V_51 ) == - V_196 )
continue;
return V_51 ;
}
if ( V_51 )
break;
F_261 ( V_320 ) ;
if ( ++ V_320 -> V_321 >= V_125 )
return NULL ;
V_98 = F_258 ( V_320 ) ;
if ( V_98 )
return F_154 ( V_98 ) ;
}
} while ( F_81 ( & V_51 -> V_2 ) != F_266 ( V_280 ) );
return V_51 ;
}
static void * F_267 ( struct V_323 * V_280 , T_7 * V_325 )
{
struct V_319 * V_320 = V_280 -> V_324 ;
void * V_326 = V_327 ;
T_7 V_246 ;
int V_98 ;
V_320 -> V_321 = 0 ;
V_98 = F_258 ( V_320 ) ;
if ( V_98 )
return F_154 ( V_98 ) ;
for ( V_246 = * V_325 ; V_246 && V_326 && ! F_180 ( V_326 ) ; V_246 -- )
V_326 = F_264 ( V_280 ) ;
return V_326 ;
}
static void * F_268 ( struct V_323 * V_280 , void * V_328 , T_7 * V_246 )
{
++ * V_246 ;
return F_264 ( V_280 ) ;
}
static void F_269 ( struct V_323 * V_280 , void * V_328 )
{
struct V_319 * V_320 = V_280 -> V_324 ;
if ( V_320 -> V_321 >= V_125 )
return;
F_261 ( V_320 ) ;
}
static int F_270 ( struct V_323 * V_280 , void * V_328 )
{
if ( V_328 == V_327 ) {
F_271 ( V_280 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_329 = V_328 ;
struct V_50 * V_51 = F_2 ( V_329 ) ;
F_272 ( V_280 , L_6 ,
V_329 ,
V_329 -> V_29 ,
V_51 -> V_11 ,
V_51 -> V_72 ? ( T_1 ) V_51 -> V_72 [ 0 ] : 0 ,
F_273 ( V_329 ) ,
F_274 ( V_329 ) ,
V_51 -> V_66 ,
F_61 ( & V_329 -> V_107 ) ,
F_61 ( & V_329 -> V_58 ) ,
F_275 ( V_329 )
) ;
}
return 0 ;
}
static int F_276 ( struct V_186 * V_186 , struct V_151 * V_151 )
{
return F_277 ( V_186 , V_151 , & V_330 ,
sizeof( struct V_319 ) ) ;
}
int F_278 ( struct V_331 * V_332 )
{
return F_279 ( & V_137 , V_332 ) ;
}
int F_280 ( struct V_331 * V_332 )
{
return F_281 ( & V_137 , V_332 ) ;
}
static int T_8 F_282 ( struct V_85 * V_85 )
{
#ifdef F_283
if ( ! F_284 ( L_7 , 0 , V_85 -> V_333 , & V_334 ) )
return - V_40 ;
#endif
return 0 ;
}
static void T_9 F_285 ( struct V_85 * V_85 )
{
#ifdef F_283
F_286 ( L_7 , V_85 -> V_333 ) ;
#endif
}
static void T_10 F_287 ( void )
{
struct V_95 * V_95 ;
int V_72 = 32 ;
V_95 = F_229 ( sizeof( * V_95 ) + F_144 ( V_72 ) , V_117 ) ;
if ( ! V_95 )
F_288 ( L_8 ) ;
F_62 () ;
V_91 [ V_31 ] . V_72 = V_72 ;
F_230 ( V_91 [ V_31 ] . V_95 , V_95 ) ;
V_91 [ V_31 ] . V_23 = V_335 ;
V_91 [ V_31 ] . V_127 = 1 ;
V_91 [ V_31 ] . V_3 = V_177 ;
F_72 () ;
}
static inline T_1 F_289 ( const void * V_14 , T_1 V_9 , T_1 V_336 )
{
const struct V_50 * V_51 = V_14 ;
struct V_81 V_79 ;
F_83 ( & V_79 , F_81 ( & V_51 -> V_2 ) , V_51 -> V_11 ) ;
return F_290 ( ( T_1 * ) & V_79 , V_337 / sizeof( T_1 ) , V_336 ) ;
}
static int T_10 F_291 ( void )
{
int V_94 ;
int V_98 = F_292 ( & V_118 , 0 ) ;
if ( V_98 != 0 )
goto V_26;
F_293 ( sizeof( struct V_144 ) > F_294 ( struct V_6 , V_67 ) ) ;
V_91 = F_295 ( V_125 , sizeof( * V_91 ) , V_117 ) ;
if ( ! V_91 )
goto F_288;
for ( V_94 = 0 ; V_94 < V_125 ; V_94 ++ ) {
if ( F_296 ( & V_91 [ V_94 ] . V_88 ,
& V_89 ) < 0 ) {
while ( -- V_94 > 0 )
F_297 ( & V_91 [ V_94 ] . V_88 ) ;
F_127 ( V_91 ) ;
goto F_288;
}
}
F_298 ( & V_22 ) ;
F_287 () ;
F_299 ( & V_338 ) ;
F_300 ( & V_339 ) ;
F_301 () ;
V_26:
return V_98 ;
F_288:
F_288 ( L_9 ) ;
}
