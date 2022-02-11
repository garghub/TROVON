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
static void F_62 ( struct V_73 * V_74 )
{
struct V_50 * V_51 = F_63 ( V_74 , struct V_50 ,
V_74 ) ;
F_64 ( & V_51 -> V_2 ) ;
}
void F_65 ( void )
__acquires( T_3 )
{
F_66 () ;
F_67 ( & T_3 ) ;
if ( F_61 ( & V_75 ) ) {
F_68 ( V_60 , V_76 ) ;
F_69 ( & V_77 , & V_60 ) ;
for (; ; ) {
F_70 ( V_78 ) ;
if ( F_61 ( & V_75 ) == 0 )
break;
F_71 ( & T_3 ) ;
F_72 () ;
F_67 ( & T_3 ) ;
}
F_73 ( V_79 ) ;
F_74 ( & V_77 , & V_60 ) ;
}
}
void F_75 ( void )
__releases( T_3 )
{
F_71 ( & T_3 ) ;
F_76 ( & V_77 ) ;
}
static inline void
F_77 ( void )
{
F_78 ( & T_3 ) ;
F_41 ( & V_75 ) ;
F_79 ( & T_3 ) ;
}
static inline void
F_80 ( void )
{
if ( F_81 ( & V_75 ) )
F_76 ( & V_77 ) ;
}
static inline int F_82 ( struct V_80 * V_81 ,
const void * V_82 )
{
const struct V_83 * V_84 = V_81 -> V_85 ;
const struct V_50 * V_51 = V_82 ;
return V_51 -> V_11 != V_84 -> V_11 ||
! F_83 ( F_84 ( & V_51 -> V_2 ) , F_85 ( & V_84 -> V_86 ) ) ;
}
static void F_86 ( struct V_83 * V_81 ,
struct V_87 * V_87 , T_1 V_11 )
{
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
F_87 ( & V_81 -> V_86 , V_87 ) ;
V_81 -> V_11 = V_11 ;
}
static struct V_1 * F_88 ( struct V_88 * V_89 , T_1 V_11 ,
struct V_87 * V_87 )
{
struct V_83 V_81 ;
F_86 ( & V_81 , V_87 , V_11 ) ;
return F_89 ( & V_89 -> V_90 , & V_81 ,
V_91 ) ;
}
static int F_90 ( struct V_88 * V_89 , struct V_1 * V_2 )
{
struct V_83 V_81 ;
F_86 ( & V_81 , F_84 ( V_2 ) , F_2 ( V_2 ) -> V_11 ) ;
return F_91 ( & V_89 -> V_90 , & V_81 ,
& F_2 ( V_2 ) -> V_92 ,
V_91 ) ;
}
static struct V_1 * F_92 ( struct V_87 * V_87 , int V_43 , T_1 V_11 )
{
struct V_88 * V_89 = & V_93 [ V_43 ] ;
struct V_1 * V_2 ;
F_35 () ;
V_2 = F_88 ( V_89 , V_11 , V_87 ) ;
if ( V_2 )
F_93 ( V_2 ) ;
F_37 () ;
return V_2 ;
}
static void
F_94 ( struct V_1 * V_2 )
{
struct V_88 * V_94 = & V_93 [ V_2 -> V_29 ] ;
unsigned long V_95 ;
unsigned int V_96 ;
struct V_97 * V_97 ;
V_97 = F_95 ( V_94 -> V_97 ) ;
if ( ! V_97 )
return;
for ( V_96 = 0 ; V_96 < F_96 ( V_94 -> V_72 ) ; V_96 ++ ) {
V_95 = 0 ;
F_97 (sk, &tbl->mc_list) {
if ( V_96 < F_96 ( F_2 ( V_2 ) -> V_98 ) )
V_95 |= F_2 ( V_2 ) -> V_72 [ V_96 ] ;
}
V_97 -> V_99 [ V_96 ] = V_95 ;
}
}
static int F_98 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_88 * V_89 = & V_93 [ V_2 -> V_29 ] ;
int V_100 ;
F_99 ( V_2 ) ;
V_100 = F_2 ( V_2 ) -> V_11 == V_11 ? 0 : - V_101 ;
if ( F_2 ( V_2 ) -> V_102 )
goto V_100;
V_100 = - V_40 ;
if ( V_103 > 32 &&
F_10 ( F_61 ( & V_89 -> V_90 . V_104 ) >= V_105 ) )
goto V_100;
F_2 ( V_2 ) -> V_11 = V_11 ;
F_93 ( V_2 ) ;
V_100 = F_90 ( V_89 , V_2 ) ;
if ( V_100 ) {
if ( F_10 ( V_100 == - V_101 ) )
V_100 = - V_106 ;
if ( V_100 == - V_107 )
V_100 = - V_108 ;
F_100 ( V_2 ) ;
goto V_100;
}
F_101 () ;
F_2 ( V_2 ) -> V_102 = V_11 ;
V_100:
F_102 ( V_2 ) ;
return V_100 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_88 * V_89 ;
V_89 = & V_93 [ V_2 -> V_29 ] ;
if ( ! F_104 ( & V_89 -> V_90 , & F_2 ( V_2 ) -> V_92 ,
V_91 ) ) {
F_53 ( F_61 ( & V_2 -> V_109 ) == 1 ) ;
F_105 ( V_2 ) ;
}
F_65 () ;
if ( F_2 ( V_2 ) -> V_110 ) {
F_106 ( V_2 ) ;
F_94 ( V_2 ) ;
}
if ( V_2 -> V_29 == V_37 )
F_41 ( & V_111 ) ;
F_75 () ;
}
static int F_107 ( struct V_87 * V_87 , struct V_112 * V_1 ,
struct V_113 * V_114 , int V_43 ,
int V_115 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_1 -> V_116 = & V_117 ;
V_2 = F_108 ( V_87 , V_118 , V_119 , & V_120 , V_115 ) ;
if ( ! V_2 )
return - V_40 ;
F_109 ( V_1 , V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_114 ) {
V_51 -> V_114 = V_114 ;
} else {
V_51 -> V_114 = & V_51 -> V_121 ;
F_110 ( V_51 -> V_114 ) ;
}
F_111 ( & V_51 -> V_60 ) ;
V_2 -> V_122 = F_56 ;
V_2 -> V_29 = V_43 ;
return 0 ;
}
static int F_112 ( struct V_87 * V_87 , struct V_112 * V_1 , int V_43 ,
int V_115 )
{
struct V_23 * V_23 = NULL ;
struct V_113 * V_114 ;
struct V_50 * V_51 ;
int (* F_113)( struct V_87 * V_87 , int V_5 );
void (* F_114)( struct V_87 * V_87 , int V_5 );
int V_100 = 0 ;
V_1 -> V_54 = V_123 ;
if ( V_1 -> type != V_124 && V_1 -> type != V_125 )
return - V_126 ;
if ( V_43 < 0 || V_43 >= V_127 )
return - V_128 ;
F_77 () ;
#ifdef F_115
if ( ! V_93 [ V_43 ] . V_129 ) {
F_80 () ;
F_116 ( L_3 , V_118 , V_43 ) ;
F_77 () ;
}
#endif
if ( V_93 [ V_43 ] . V_129 &&
F_117 ( V_93 [ V_43 ] . V_23 ) )
V_23 = V_93 [ V_43 ] . V_23 ;
else
V_100 = - V_128 ;
V_114 = V_93 [ V_43 ] . V_114 ;
F_113 = V_93 [ V_43 ] . F_113 ;
F_114 = V_93 [ V_43 ] . F_114 ;
F_80 () ;
if ( V_100 < 0 )
goto V_26;
V_100 = F_107 ( V_87 , V_1 , V_114 , V_43 , V_115 ) ;
if ( V_100 < 0 )
goto V_130;
F_118 () ;
F_119 ( V_87 , & V_120 , 1 ) ;
F_120 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_23 = V_23 ;
V_51 -> V_131 = F_113 ;
V_51 -> V_132 = F_114 ;
V_26:
return V_100 ;
V_130:
F_19 ( V_23 ) ;
goto V_26;
}
static void F_121 ( struct V_133 * V_41 )
{
struct V_50 * V_51 = F_63 ( V_41 , struct V_50 , V_134 ) ;
struct V_1 * V_2 = & V_51 -> V_2 ;
if ( ! F_81 ( & V_2 -> V_109 ) )
return;
if ( V_51 -> V_66 && V_51 -> V_67 . V_68 ) {
F_122 ( & V_51 -> V_74 , F_62 ) ;
F_123 ( & V_51 -> V_74 ) ;
return;
}
F_64 ( V_2 ) ;
}
static int F_124 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_103 ( V_2 ) ;
F_125 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_132 ) {
int V_96 ;
for ( V_96 = 0 ; V_96 < V_51 -> V_98 ; V_96 ++ )
if ( F_45 ( V_96 , V_51 -> V_72 ) )
V_51 -> V_132 ( F_84 ( V_2 ) , V_96 + 1 ) ;
}
if ( V_2 -> V_29 == V_37 &&
F_48 ( & V_111 ) == 0 )
F_76 ( & V_135 ) ;
V_1 -> V_2 = NULL ;
F_126 ( & V_51 -> V_60 ) ;
F_58 ( & V_2 -> V_136 ) ;
if ( V_51 -> V_11 && V_51 -> V_102 ) {
struct V_137 V_138 = {
. V_87 = F_84 ( V_2 ) ,
. V_43 = V_2 -> V_29 ,
. V_11 = V_51 -> V_11 ,
} ;
F_127 ( & V_139 ,
V_140 , & V_138 ) ;
}
F_19 ( V_51 -> V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_65 () ;
F_128 ( V_93 [ V_2 -> V_29 ] . V_129 == 0 ) ;
if ( -- V_93 [ V_2 -> V_29 ] . V_129 == 0 ) {
struct V_97 * V_141 ;
V_141 = F_95 ( V_93 [ V_2 -> V_29 ] . V_97 ) ;
F_129 ( V_93 [ V_2 -> V_29 ] . V_97 , NULL ) ;
F_130 ( V_141 , V_134 ) ;
V_93 [ V_2 -> V_29 ] . V_23 = NULL ;
V_93 [ V_2 -> V_29 ] . F_113 = NULL ;
V_93 [ V_2 -> V_29 ] . F_114 = NULL ;
V_93 [ V_2 -> V_29 ] . V_3 = 0 ;
V_93 [ V_2 -> V_29 ] . V_129 = 0 ;
}
F_75 () ;
}
F_131 ( V_51 -> V_72 ) ;
V_51 -> V_72 = NULL ;
F_118 () ;
F_119 ( F_84 ( V_2 ) , & V_120 , - 1 ) ;
F_120 () ;
F_132 ( & V_51 -> V_134 , F_121 ) ;
return 0 ;
}
static int F_133 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_87 * V_87 = F_84 ( V_2 ) ;
struct V_88 * V_89 = & V_93 [ V_2 -> V_29 ] ;
T_4 V_11 = F_134 ( V_76 ) ;
int V_100 ;
T_4 V_142 = - 4096 ;
bool V_143 ;
V_144:
F_135 () ;
F_35 () ;
V_143 = ! F_88 ( V_89 , V_11 , V_87 ) ;
F_37 () ;
if ( ! V_143 ) {
if ( V_142 == - 4096 )
V_142 = V_145 + F_136 ( - 4096 - V_145 ) ;
else if ( V_142 >= - 4096 )
V_142 = - 4097 ;
V_11 = V_142 -- ;
goto V_144;
}
V_100 = F_98 ( V_2 , V_11 ) ;
if ( V_100 == - V_108 )
goto V_144;
if ( V_100 == - V_101 )
V_100 = 0 ;
return V_100 ;
}
bool F_137 ( const struct V_146 * V_147 ,
struct V_148 * V_149 , int V_150 )
{
return ( ( V_147 -> V_3 & V_151 ) ||
F_138 ( V_147 -> V_2 -> V_152 -> V_153 , V_149 , V_150 ) ) &&
F_139 ( V_149 , V_150 ) ;
}
bool F_140 ( const struct V_6 * V_7 ,
struct V_148 * V_149 , int V_150 )
{
return F_137 ( & F_7 ( V_7 ) , V_149 , V_150 ) ;
}
bool F_141 ( const struct V_6 * V_7 , int V_150 )
{
return F_140 ( V_7 , & V_154 , V_150 ) ;
}
bool F_142 ( const struct V_6 * V_7 , int V_150 )
{
return F_140 ( V_7 , F_84 ( V_7 -> V_2 ) -> V_149 , V_150 ) ;
}
static inline int F_143 ( const struct V_112 * V_1 , unsigned int V_155 )
{
return ( V_93 [ V_1 -> V_2 -> V_29 ] . V_3 & V_155 ) ||
F_139 ( F_84 ( V_1 -> V_2 ) -> V_149 , V_156 ) ;
}
static void
F_144 ( struct V_1 * V_2 , unsigned int V_110 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_110 && ! V_110 )
F_106 ( V_2 ) ;
else if ( ! V_51 -> V_110 && V_110 )
F_145 ( V_2 , & V_93 [ V_2 -> V_29 ] . V_157 ) ;
V_51 -> V_110 = V_110 ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_72 ;
unsigned long * V_158 ;
int V_100 = 0 ;
F_65 () ;
V_72 = V_93 [ V_2 -> V_29 ] . V_72 ;
if ( ! V_93 [ V_2 -> V_29 ] . V_129 ) {
V_100 = - V_159 ;
goto V_160;
}
if ( V_51 -> V_98 >= V_72 )
goto V_160;
V_158 = F_147 ( V_51 -> V_72 , F_148 ( V_72 ) , V_42 ) ;
if ( V_158 == NULL ) {
V_100 = - V_40 ;
goto V_160;
}
memset ( ( char * ) V_158 + F_148 ( V_51 -> V_98 ) , 0 ,
F_148 ( V_72 ) - F_148 ( V_51 -> V_98 ) ) ;
V_51 -> V_72 = V_158 ;
V_51 -> V_98 = V_72 ;
V_160:
F_75 () ;
return V_100 ;
}
static void F_149 ( int V_5 , long unsigned int V_72 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_161 ;
if ( ! V_51 -> V_132 )
return;
for ( V_161 = 0 ; V_161 < V_5 ; V_161 ++ )
if ( F_45 ( V_161 , & V_72 ) )
V_51 -> V_132 ( F_84 ( V_2 ) , V_161 + 1 ) ;
}
static int V_131 ( struct V_112 * V_1 , struct V_162 * V_163 ,
int V_164 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_87 * V_87 = F_84 ( V_2 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_165 * V_166 = (struct V_165 * ) V_163 ;
int V_100 ;
long unsigned int V_72 = V_166 -> V_167 ;
bool V_102 ;
if ( V_164 < sizeof( struct V_165 ) )
return - V_19 ;
if ( V_166 -> V_168 != V_169 )
return - V_19 ;
if ( V_72 ) {
if ( ! F_143 ( V_1 , V_170 ) )
return - V_171 ;
V_100 = F_146 ( V_2 ) ;
if ( V_100 )
return V_100 ;
}
V_102 = V_51 -> V_102 ;
if ( V_102 ) {
F_150 () ;
if ( V_166 -> V_172 != V_51 -> V_11 )
return - V_19 ;
}
if ( V_51 -> V_131 && V_72 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_51 -> V_98 ; V_5 ++ ) {
if ( ! F_45 ( V_5 , & V_72 ) )
continue;
V_100 = V_51 -> V_131 ( V_87 , V_5 + 1 ) ;
if ( ! V_100 )
continue;
F_149 ( V_5 , V_72 , V_2 ) ;
return V_100 ;
}
}
if ( ! V_102 ) {
V_100 = V_166 -> V_172 ?
F_98 ( V_2 , V_166 -> V_172 ) :
F_133 ( V_1 ) ;
if ( V_100 ) {
F_149 ( V_51 -> V_98 , V_72 , V_2 ) ;
return V_100 ;
}
}
if ( ! V_72 && ( V_51 -> V_72 == NULL || ! ( T_1 ) V_51 -> V_72 [ 0 ] ) )
return 0 ;
F_65 () ;
F_144 ( V_2 , V_51 -> V_110 +
F_151 ( V_72 ) -
F_151 ( V_51 -> V_72 [ 0 ] ) ) ;
V_51 -> V_72 [ 0 ] = ( V_51 -> V_72 [ 0 ] & ~ 0xffffffffUL ) | V_72 ;
F_94 ( V_2 ) ;
F_75 () ;
return 0 ;
}
static int F_152 ( struct V_112 * V_1 , struct V_162 * V_163 ,
int V_173 , int V_3 )
{
int V_100 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_165 * V_166 = (struct V_165 * ) V_163 ;
if ( V_173 < sizeof( V_163 -> V_174 ) )
return - V_19 ;
if ( V_163 -> V_174 == V_175 ) {
V_2 -> V_176 = V_177 ;
V_51 -> V_178 = 0 ;
V_51 -> V_12 = 0 ;
return 0 ;
}
if ( V_163 -> V_174 != V_169 )
return - V_19 ;
if ( ( V_166 -> V_167 || V_166 -> V_172 ) &&
! F_143 ( V_1 , V_179 ) )
return - V_171 ;
if ( ! V_51 -> V_102 )
V_100 = F_133 ( V_1 ) ;
if ( V_100 == 0 ) {
V_2 -> V_176 = V_180 ;
V_51 -> V_178 = V_166 -> V_172 ;
V_51 -> V_12 = F_153 ( V_166 -> V_167 ) ;
}
return V_100 ;
}
static int F_154 ( struct V_112 * V_1 , struct V_162 * V_163 ,
int * V_164 , int V_181 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_155 ( struct V_165 * , V_166 , V_163 ) ;
V_166 -> V_168 = V_169 ;
V_166 -> V_182 = 0 ;
* V_164 = sizeof( * V_166 ) ;
if ( V_181 ) {
V_166 -> V_172 = V_51 -> V_178 ;
V_166 -> V_167 = F_3 ( V_51 -> V_12 ) ;
} else {
V_166 -> V_172 = V_51 -> V_11 ;
V_166 -> V_167 = V_51 -> V_72 ? V_51 -> V_72 [ 0 ] : 0 ;
}
return 0 ;
}
static int F_156 ( struct V_112 * V_1 , unsigned int V_183 ,
unsigned long V_81 )
{
return - V_184 ;
}
static struct V_1 * F_157 ( struct V_1 * V_185 , T_1 V_11 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_92 ( F_84 ( V_185 ) , V_185 -> V_29 , V_11 ) ;
if ( ! V_1 )
return F_158 ( - V_186 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_176 == V_180 &&
V_51 -> V_178 != F_2 ( V_185 ) -> V_11 ) {
F_100 ( V_1 ) ;
return F_158 ( - V_186 ) ;
}
return V_1 ;
}
struct V_1 * F_159 ( struct V_153 * V_187 )
{
struct V_188 * V_188 = F_160 ( V_187 ) ;
struct V_1 * V_1 ;
if ( ! F_161 ( V_188 -> V_189 ) )
return F_158 ( - V_190 ) ;
V_1 = F_162 ( V_188 ) -> V_2 ;
if ( V_1 -> V_191 != V_169 )
return F_158 ( - V_19 ) ;
F_93 ( V_1 ) ;
return V_1 ;
}
static struct V_6 * F_163 ( unsigned int V_192 ,
int V_193 )
{
struct V_6 * V_7 ;
void * V_14 ;
if ( V_192 <= V_194 || V_193 )
return F_6 ( V_192 , V_119 ) ;
V_192 = F_164 ( V_192 ) +
F_164 ( sizeof( struct V_195 ) ) ;
V_14 = F_165 ( V_192 ) ;
if ( V_14 == NULL )
return NULL ;
V_7 = F_166 ( V_14 , V_192 ) ;
if ( V_7 == NULL )
F_50 ( V_14 ) ;
else
V_7 -> V_63 = F_47 ;
return V_7 ;
}
int F_167 ( struct V_1 * V_2 , struct V_6 * V_7 ,
long * V_196 , struct V_1 * V_185 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_197 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) ) {
F_68 ( V_60 , V_76 ) ;
if ( ! * V_196 ) {
if ( ! V_185 || F_1 ( V_185 ) )
F_39 ( V_2 ) ;
F_100 ( V_2 ) ;
F_57 ( V_7 ) ;
return - V_198 ;
}
F_73 ( V_199 ) ;
F_168 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_197 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) &&
! F_59 ( V_2 , V_69 ) )
* V_196 = F_169 ( * V_196 ) ;
F_73 ( V_79 ) ;
F_74 ( & V_51 -> V_60 , & V_60 ) ;
F_100 ( V_2 ) ;
if ( F_170 ( V_76 ) ) {
F_57 ( V_7 ) ;
return F_171 ( * V_196 ) ;
}
return 1 ;
}
F_52 ( V_7 , V_2 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = V_7 -> V_9 ;
F_34 ( V_7 ) ;
F_173 ( & V_2 -> V_59 , V_7 ) ;
V_2 -> V_200 ( V_2 ) ;
return V_9 ;
}
int F_174 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = F_172 ( V_2 , V_7 ) ;
F_100 ( V_2 ) ;
return V_9 ;
}
void F_175 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_57 ( V_7 ) ;
F_100 ( V_2 ) ;
}
static struct V_6 * F_176 ( struct V_6 * V_7 , T_2 V_201 )
{
int V_202 ;
F_53 ( V_7 -> V_2 != NULL ) ;
V_202 = V_7 -> V_203 - V_7 -> V_204 ;
if ( F_25 ( V_7 -> V_41 ) || V_202 * 2 < V_7 -> V_64 )
return V_7 ;
if ( F_177 ( V_7 ) ) {
struct V_6 * V_39 = F_26 ( V_7 , V_201 ) ;
if ( ! V_39 )
return V_7 ;
F_178 ( V_7 ) ;
V_7 = V_39 ;
}
if ( ! F_179 ( V_7 , 0 , - V_202 , V_201 ) )
V_7 -> V_64 -= V_202 ;
return V_7 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_185 )
{
int V_28 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
V_28 = - V_186 ;
if ( V_51 -> V_205 != NULL ) {
V_28 = V_7 -> V_9 ;
F_52 ( V_7 , V_2 ) ;
F_7 ( V_7 ) . V_2 = V_185 ;
F_38 ( V_2 , V_185 , V_7 ) ;
V_51 -> V_205 ( V_7 ) ;
F_178 ( V_7 ) ;
} else {
F_57 ( V_7 ) ;
}
F_100 ( V_2 ) ;
return V_28 ;
}
int F_181 ( struct V_1 * V_185 , struct V_6 * V_7 ,
T_1 V_11 , int V_206 )
{
struct V_1 * V_2 ;
int V_100 ;
long V_196 ;
V_7 = F_176 ( V_7 , F_182 () ) ;
V_196 = F_183 ( V_185 , V_206 ) ;
V_144:
V_2 = F_157 ( V_185 , V_11 ) ;
if ( F_184 ( V_2 ) ) {
F_57 ( V_7 ) ;
return F_185 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_180 ( V_2 , V_7 , V_185 ) ;
if ( F_186 ( V_2 , V_7 ) ) {
V_100 = V_7 -> V_9 ;
F_57 ( V_7 ) ;
F_100 ( V_2 ) ;
return V_100 ;
}
V_100 = F_167 ( V_2 , V_7 , & V_196 , V_185 ) ;
if ( V_100 == 1 )
goto V_144;
if ( V_100 )
return V_100 ;
return F_174 ( V_2 , V_7 ) ;
}
int F_187 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_207 = 0 ;
struct V_97 * V_97 ;
F_128 ( ! F_1 ( V_2 ) ) ;
F_35 () ;
V_97 = F_188 ( V_93 [ V_2 -> V_29 ] . V_97 ) ;
if ( V_97 && V_5 - 1 < V_93 [ V_2 -> V_29 ] . V_72 )
V_207 = F_45 ( V_5 - 1 , V_97 -> V_99 ) ;
F_37 () ;
return V_207 ;
}
static int F_189 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_61 ( & V_2 -> V_65 ) <= V_2 -> V_197 &&
! F_45 ( V_53 , & V_51 -> V_54 ) ) {
F_52 ( V_7 , V_2 ) ;
F_172 ( V_2 , V_7 ) ;
return F_61 ( & V_2 -> V_65 ) > ( V_2 -> V_197 >> 1 ) ;
}
return - 1 ;
}
static void F_190 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_210 ;
if ( V_209 -> V_211 == V_2 )
return;
if ( V_51 -> V_11 == V_209 -> V_11 || V_209 -> V_5 - 1 >= V_51 -> V_98 ||
! F_45 ( V_209 -> V_5 - 1 , V_51 -> V_72 ) )
return;
if ( ! F_83 ( F_84 ( V_2 ) , V_209 -> V_87 ) ) {
if ( ! ( V_51 -> V_3 & V_212 ) )
return;
if ( ! F_191 ( F_84 ( V_2 ) , V_209 -> V_87 ) )
return;
if ( ! F_138 ( V_2 -> V_152 -> V_153 , V_209 -> V_87 -> V_149 ,
V_213 ) )
return;
}
if ( V_209 -> V_214 ) {
F_39 ( V_2 ) ;
return;
}
F_93 ( V_2 ) ;
if ( V_209 -> V_215 == NULL ) {
if ( F_177 ( V_209 -> V_7 ) ) {
V_209 -> V_215 = F_26 ( V_209 -> V_7 , V_209 -> V_201 ) ;
} else {
V_209 -> V_215 = F_192 ( V_209 -> V_7 ) ;
F_193 ( V_209 -> V_215 ) ;
}
}
if ( V_209 -> V_215 == NULL ) {
F_39 ( V_2 ) ;
V_209 -> V_214 = 1 ;
if ( V_51 -> V_3 & V_216 )
V_209 -> V_217 = 1 ;
goto V_26;
}
if ( V_209 -> V_218 && V_209 -> V_218 ( V_2 , V_209 -> V_215 , V_209 -> V_219 ) ) {
F_57 ( V_209 -> V_215 ) ;
V_209 -> V_215 = NULL ;
goto V_26;
}
if ( F_186 ( V_2 , V_209 -> V_215 ) ) {
F_57 ( V_209 -> V_215 ) ;
V_209 -> V_215 = NULL ;
goto V_26;
}
F_7 ( V_209 -> V_215 ) . V_220 = F_194 ( F_84 ( V_2 ) , V_209 -> V_87 ) ;
F_7 ( V_209 -> V_215 ) . V_221 = true ;
V_210 = F_189 ( V_2 , V_209 -> V_215 ) ;
if ( V_210 < 0 ) {
F_39 ( V_2 ) ;
if ( V_51 -> V_3 & V_216 )
V_209 -> V_217 = 1 ;
} else {
V_209 -> V_222 |= V_210 ;
V_209 -> V_223 = 1 ;
V_209 -> V_215 = NULL ;
}
V_26:
F_100 ( V_2 ) ;
}
int F_195 ( struct V_1 * V_185 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_201 ,
int (* F_196)( struct V_1 * V_224 , struct V_6 * V_7 , void * V_14 ) ,
void * V_225 )
{
struct V_87 * V_87 = F_84 ( V_185 ) ;
struct V_208 V_226 ;
struct V_1 * V_2 ;
V_7 = F_176 ( V_7 , V_201 ) ;
V_226 . V_211 = V_185 ;
V_226 . V_87 = V_87 ;
V_226 . V_11 = V_11 ;
V_226 . V_5 = V_5 ;
V_226 . V_214 = 0 ;
V_226 . V_217 = 0 ;
V_226 . V_222 = 0 ;
V_226 . V_223 = 0 ;
V_226 . V_201 = V_201 ;
V_226 . V_7 = V_7 ;
V_226 . V_215 = NULL ;
V_226 . V_218 = F_196 ;
V_226 . V_219 = V_225 ;
F_77 () ;
F_97 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_190 ( V_2 , & V_226 ) ;
F_178 ( V_7 ) ;
F_80 () ;
if ( V_226 . V_217 ) {
F_57 ( V_226 . V_215 ) ;
return - V_56 ;
}
F_178 ( V_226 . V_215 ) ;
if ( V_226 . V_223 ) {
if ( V_226 . V_222 && F_197 ( V_201 ) )
F_198 () ;
return 0 ;
}
return - V_227 ;
}
int F_199 ( struct V_1 * V_185 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_201 )
{
return F_195 ( V_185 , V_7 , V_11 , V_5 , V_201 ,
NULL , NULL ) ;
}
static int F_200 ( struct V_1 * V_2 , struct V_228 * V_209 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_28 = 0 ;
if ( V_2 == V_209 -> V_211 )
goto V_26;
if ( ! F_83 ( F_84 ( V_2 ) , F_84 ( V_209 -> V_211 ) ) )
goto V_26;
if ( V_51 -> V_11 == V_209 -> V_11 || V_209 -> V_5 - 1 >= V_51 -> V_98 ||
! F_45 ( V_209 -> V_5 - 1 , V_51 -> V_72 ) )
goto V_26;
if ( V_209 -> V_229 == V_56 && V_51 -> V_3 & V_52 ) {
V_28 = 1 ;
goto V_26;
}
V_2 -> V_55 = V_209 -> V_229 ;
V_2 -> V_57 ( V_2 ) ;
V_26:
return V_28 ;
}
int F_201 ( struct V_1 * V_185 , T_1 V_11 , T_1 V_5 , int V_229 )
{
struct V_228 V_226 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
V_226 . V_211 = V_185 ;
V_226 . V_11 = V_11 ;
V_226 . V_5 = V_5 ;
V_226 . V_229 = - V_229 ;
F_78 ( & T_3 ) ;
F_97 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_28 += F_200 ( V_2 , & V_226 ) ;
F_79 ( & T_3 ) ;
return V_28 ;
}
static void F_202 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_230 )
{
int V_141 , V_10 = ! ! V_230 , V_110 ;
V_141 = F_45 ( V_5 - 1 , V_51 -> V_72 ) ;
V_110 = V_51 -> V_110 - V_141 + V_10 ;
if ( V_10 )
F_203 ( V_5 - 1 , V_51 -> V_72 ) ;
else
F_204 ( V_5 - 1 , V_51 -> V_72 ) ;
F_144 ( & V_51 -> V_2 , V_110 ) ;
F_94 ( & V_51 -> V_2 ) ;
}
static int F_205 ( struct V_112 * V_1 , int V_231 , int V_232 ,
char T_5 * V_233 , unsigned int V_234 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_210 = 0 ;
int V_100 ;
if ( V_231 != V_235 )
return - V_236 ;
if ( V_234 >= sizeof( int ) &&
F_206 ( V_210 , ( unsigned int T_5 * ) V_233 ) )
return - V_237 ;
switch ( V_232 ) {
case V_238 :
if ( V_210 )
V_51 -> V_3 |= V_239 ;
else
V_51 -> V_3 &= ~ V_239 ;
V_100 = 0 ;
break;
case V_240 :
case V_241 : {
if ( ! F_143 ( V_1 , V_170 ) )
return - V_171 ;
V_100 = F_146 ( V_2 ) ;
if ( V_100 )
return V_100 ;
if ( ! V_210 || V_210 - 1 >= V_51 -> V_98 )
return - V_19 ;
if ( V_232 == V_240 && V_51 -> V_131 ) {
V_100 = V_51 -> V_131 ( F_84 ( V_2 ) , V_210 ) ;
if ( V_100 )
return V_100 ;
}
F_65 () ;
F_202 ( V_51 , V_210 ,
V_232 == V_240 ) ;
F_75 () ;
if ( V_232 == V_241 && V_51 -> V_132 )
V_51 -> V_132 ( F_84 ( V_2 ) , V_210 ) ;
V_100 = 0 ;
break;
}
case V_242 :
if ( V_210 )
V_51 -> V_3 |= V_216 ;
else
V_51 -> V_3 &= ~ V_216 ;
V_100 = 0 ;
break;
case V_243 :
if ( V_210 ) {
V_51 -> V_3 |= V_52 ;
F_44 ( V_53 , & V_51 -> V_54 ) ;
F_46 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_100 = 0 ;
break;
case V_244 :
if ( ! F_139 ( F_84 ( V_2 ) -> V_149 , V_213 ) )
return - V_171 ;
if ( V_210 )
V_51 -> V_3 |= V_212 ;
else
V_51 -> V_3 &= ~ V_212 ;
V_100 = 0 ;
break;
case V_245 :
if ( V_210 )
V_51 -> V_3 |= V_246 ;
else
V_51 -> V_3 &= ~ V_246 ;
V_100 = 0 ;
break;
default:
V_100 = - V_236 ;
}
return V_100 ;
}
static int F_207 ( struct V_112 * V_1 , int V_231 , int V_232 ,
char T_5 * V_233 , int T_5 * V_234 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_9 , V_210 , V_100 ;
if ( V_231 != V_235 )
return - V_236 ;
if ( F_206 ( V_9 , V_234 ) )
return - V_237 ;
if ( V_9 < 0 )
return - V_19 ;
switch ( V_232 ) {
case V_238 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_210 = V_51 -> V_3 & V_239 ? 1 : 0 ;
if ( F_208 ( V_9 , V_234 ) ||
F_208 ( V_210 , V_233 ) )
return - V_237 ;
V_100 = 0 ;
break;
case V_242 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_210 = V_51 -> V_3 & V_216 ? 1 : 0 ;
if ( F_208 ( V_9 , V_234 ) ||
F_208 ( V_210 , V_233 ) )
return - V_237 ;
V_100 = 0 ;
break;
case V_243 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_210 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_208 ( V_9 , V_234 ) ||
F_208 ( V_210 , V_233 ) )
return - V_237 ;
V_100 = 0 ;
break;
case V_247 : {
int V_248 , V_249 , V_250 ;
V_100 = 0 ;
F_77 () ;
for ( V_248 = 0 ; V_248 * 8 < V_51 -> V_98 ; V_248 += sizeof( T_1 ) ) {
if ( V_9 - V_248 < sizeof( T_1 ) )
break;
V_249 = V_248 / sizeof( unsigned long ) ;
V_250 = ( V_248 % sizeof( unsigned long ) ) * 8 ;
if ( F_208 ( ( T_1 ) ( V_51 -> V_72 [ V_249 ] >> V_250 ) ,
( T_1 T_5 * ) ( V_233 + V_248 ) ) ) {
V_100 = - V_237 ;
break;
}
}
if ( F_208 ( F_209 ( V_51 -> V_98 / 8 , sizeof( T_1 ) ) , V_234 ) )
V_100 = - V_237 ;
F_80 () ;
break;
}
case V_245 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_210 = V_51 -> V_3 & V_246 ? 1 : 0 ;
if ( F_208 ( V_9 , V_234 ) ||
F_208 ( V_210 , V_233 ) )
return - V_237 ;
V_100 = 0 ;
break;
default:
V_100 = - V_236 ;
}
return V_100 ;
}
static void F_210 ( struct V_251 * V_252 , struct V_6 * V_7 )
{
struct V_253 V_226 ;
V_226 . V_5 = F_7 ( V_7 ) . V_12 ;
F_211 ( V_252 , V_235 , V_238 , sizeof( V_226 ) , & V_226 ) ;
}
static void F_212 ( struct V_1 * V_2 , struct V_251 * V_252 ,
struct V_6 * V_7 )
{
if ( ! F_7 ( V_7 ) . V_221 )
return;
F_211 ( V_252 , V_235 , V_244 , sizeof( int ) ,
& F_7 ( V_7 ) . V_220 ) ;
}
static int F_213 ( struct V_112 * V_1 , struct V_251 * V_252 , T_6 V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_155 ( struct V_165 * , V_163 , V_252 -> V_254 ) ;
T_1 V_178 ;
T_1 V_12 ;
struct V_6 * V_7 ;
int V_100 ;
struct V_255 V_256 ;
T_1 V_257 = 0 ;
if ( V_252 -> V_258 & V_259 )
return - V_260 ;
V_100 = F_214 ( V_1 , V_252 , & V_256 , true ) ;
if ( V_100 < 0 )
return V_100 ;
if ( V_252 -> V_261 ) {
V_100 = - V_19 ;
if ( V_163 -> V_168 != V_169 )
goto V_26;
V_178 = V_163 -> V_172 ;
V_12 = F_153 ( V_163 -> V_167 ) ;
V_100 = - V_171 ;
if ( ( V_12 || V_178 ) &&
! F_143 ( V_1 , V_179 ) )
goto V_26;
V_257 |= V_151 ;
} else {
V_178 = V_51 -> V_178 ;
V_12 = V_51 -> V_12 ;
}
if ( ! V_51 -> V_102 ) {
V_100 = F_133 ( V_1 ) ;
if ( V_100 )
goto V_26;
} else {
F_150 () ;
}
V_100 = - V_262 ;
if ( V_9 > V_2 -> V_263 - 32 )
goto V_26;
V_100 = - V_56 ;
V_7 = F_163 ( V_9 , V_12 ) ;
if ( V_7 == NULL )
goto V_26;
F_7 ( V_7 ) . V_11 = V_51 -> V_11 ;
F_7 ( V_7 ) . V_12 = V_12 ;
F_7 ( V_7 ) . V_13 = V_256 . V_13 ;
F_7 ( V_7 ) . V_3 = V_257 ;
V_100 = - V_237 ;
if ( F_215 ( F_8 ( V_7 , V_9 ) , V_252 , V_9 ) ) {
F_57 ( V_7 ) ;
goto V_26;
}
V_100 = F_216 ( V_2 , V_7 ) ;
if ( V_100 ) {
F_57 ( V_7 ) ;
goto V_26;
}
if ( V_12 ) {
F_41 ( & V_7 -> V_264 ) ;
F_199 ( V_2 , V_7 , V_178 , V_12 , V_119 ) ;
}
V_100 = F_181 ( V_2 , V_7 , V_178 , V_252 -> V_258 & V_265 ) ;
V_26:
F_217 ( & V_256 ) ;
return V_100 ;
}
static int F_218 ( struct V_112 * V_1 , struct V_251 * V_252 , T_6 V_9 ,
int V_3 )
{
struct V_255 V_256 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_266 = V_3 & V_265 ;
T_6 V_267 ;
struct V_6 * V_7 , * V_268 ;
int V_100 , V_28 ;
if ( V_3 & V_259 )
return - V_260 ;
V_267 = 0 ;
V_7 = F_219 ( V_2 , V_3 , V_266 , & V_100 ) ;
if ( V_7 == NULL )
goto V_26;
V_268 = V_7 ;
#ifdef F_220
if ( F_10 ( F_49 ( V_7 ) -> V_269 ) ) {
if ( V_3 & V_270 )
V_268 = F_49 ( V_7 ) -> V_269 ;
}
#endif
V_51 -> V_271 = F_221 ( V_51 -> V_271 , V_9 ) ;
V_51 -> V_271 = F_222 ( T_6 , V_51 -> V_271 ,
F_223 ( 32768 ) ) ;
V_267 = V_268 -> V_9 ;
if ( V_9 < V_267 ) {
V_252 -> V_258 |= V_272 ;
V_267 = V_9 ;
}
F_224 ( V_268 ) ;
V_100 = F_225 ( V_268 , 0 , V_252 , V_267 ) ;
if ( V_252 -> V_254 ) {
F_155 ( struct V_165 * , V_163 , V_252 -> V_254 ) ;
V_163 -> V_168 = V_169 ;
V_163 -> V_182 = 0 ;
V_163 -> V_172 = F_7 ( V_7 ) . V_11 ;
V_163 -> V_167 = F_3 ( F_7 ( V_7 ) . V_12 ) ;
V_252 -> V_261 = sizeof( * V_163 ) ;
}
if ( V_51 -> V_3 & V_239 )
F_210 ( V_252 , V_7 ) ;
if ( V_51 -> V_3 & V_212 )
F_212 ( V_2 , V_252 , V_7 ) ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_256 . V_13 = * F_226 ( V_7 ) ;
if ( V_3 & V_272 )
V_267 = V_268 -> V_9 ;
F_227 ( V_2 , V_7 ) ;
if ( V_51 -> V_66 &&
F_61 ( & V_2 -> V_65 ) <= V_2 -> V_197 / 2 ) {
V_28 = F_228 ( V_2 ) ;
if ( V_28 ) {
V_2 -> V_55 = - V_28 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_229 ( V_1 , V_252 , & V_256 , V_3 ) ;
V_26:
F_42 ( V_2 ) ;
return V_100 ? : V_267 ;
}
static void F_230 ( struct V_1 * V_2 )
{
F_231 () ;
}
struct V_1 *
F_232 ( struct V_87 * V_87 , int V_273 , struct V_23 * V_23 ,
struct V_274 * V_275 )
{
struct V_112 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_97 * V_97 = NULL ;
struct V_113 * V_114 = V_275 ? V_275 -> V_114 : NULL ;
unsigned int V_72 ;
F_128 ( ! V_93 ) ;
if ( V_273 < 0 || V_273 >= V_127 )
return NULL ;
if ( F_233 ( V_118 , V_125 , V_273 , & V_1 ) )
return NULL ;
if ( F_107 ( V_87 , V_1 , V_114 , V_273 , 1 ) < 0 )
goto V_276;
V_2 = V_1 -> V_2 ;
if ( ! V_275 || V_275 -> V_72 < 32 )
V_72 = 32 ;
else
V_72 = V_275 -> V_72 ;
V_97 = F_234 ( sizeof( * V_97 ) + F_148 ( V_72 ) , V_119 ) ;
if ( ! V_97 )
goto V_277;
V_2 -> V_200 = F_230 ;
if ( V_275 && V_275 -> V_278 )
F_2 ( V_2 ) -> V_205 = V_275 -> V_278 ;
if ( F_98 ( V_2 , 0 ) )
goto V_277;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_65 () ;
if ( ! V_93 [ V_273 ] . V_129 ) {
V_93 [ V_273 ] . V_72 = V_72 ;
F_235 ( V_93 [ V_273 ] . V_97 , V_97 ) ;
V_93 [ V_273 ] . V_114 = V_114 ;
V_93 [ V_273 ] . V_23 = V_23 ;
if ( V_275 ) {
V_93 [ V_273 ] . F_113 = V_275 -> F_113 ;
V_93 [ V_273 ] . F_114 = V_275 -> F_114 ;
V_93 [ V_273 ] . V_3 = V_275 -> V_3 ;
if ( V_275 -> V_279 )
V_93 [ V_273 ] . V_279 = V_275 -> V_279 ;
}
V_93 [ V_273 ] . V_129 = 1 ;
} else {
F_131 ( V_97 ) ;
V_93 [ V_273 ] . V_129 ++ ;
}
F_75 () ;
return V_2 ;
V_277:
F_131 ( V_97 ) ;
F_236 ( V_2 ) ;
return NULL ;
V_276:
F_237 ( V_1 ) ;
return NULL ;
}
void
F_236 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_152 == NULL )
return;
F_237 ( V_2 -> V_152 ) ;
}
int F_238 ( struct V_1 * V_2 , unsigned int V_72 )
{
struct V_97 * V_10 , * V_141 ;
struct V_88 * V_94 = & V_93 [ V_2 -> V_29 ] ;
if ( V_72 < 32 )
V_72 = 32 ;
if ( F_148 ( V_94 -> V_72 ) < F_148 ( V_72 ) ) {
V_10 = F_234 ( sizeof( * V_10 ) + F_148 ( V_72 ) , V_42 ) ;
if ( ! V_10 )
return - V_40 ;
V_141 = F_95 ( V_94 -> V_97 ) ;
memcpy ( V_10 -> V_99 , V_141 -> V_99 , F_148 ( V_94 -> V_72 ) ) ;
F_235 ( V_94 -> V_97 , V_10 ) ;
F_130 ( V_141 , V_134 ) ;
}
V_94 -> V_72 = V_72 ;
return 0 ;
}
int F_239 ( struct V_1 * V_2 , unsigned int V_72 )
{
int V_100 ;
F_65 () ;
V_100 = F_238 ( V_2 , V_72 ) ;
F_75 () ;
return V_100 ;
}
void F_240 ( struct V_1 * V_280 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_88 * V_94 = & V_93 [ V_280 -> V_29 ] ;
F_97 (sk, &tbl->mc_list)
F_202 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_281 *
F_241 ( struct V_6 * V_7 , T_1 V_11 , T_1 V_282 , int type , int V_9 , int V_3 )
{
struct V_281 * V_283 ;
int V_192 = F_242 ( V_9 ) ;
V_283 = (struct V_281 * ) F_8 ( V_7 , F_243 ( V_192 ) ) ;
V_283 -> V_284 = type ;
V_283 -> V_285 = V_192 ;
V_283 -> V_286 = V_3 ;
V_283 -> V_287 = V_11 ;
V_283 -> V_288 = V_282 ;
if ( ! F_244 ( V_192 ) || F_243 ( V_192 ) - V_192 != 0 )
memset ( F_245 ( V_283 ) + V_9 , 0 , F_243 ( V_192 ) - V_192 ) ;
return V_283 ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_289 * V_67 ;
struct V_6 * V_7 = NULL ;
struct V_281 * V_283 ;
struct V_23 * V_23 ;
int V_9 , V_100 = - V_56 ;
int V_290 ;
int V_291 ;
F_246 ( V_51 -> V_114 ) ;
if ( ! V_51 -> V_66 ) {
V_100 = - V_19 ;
goto V_292;
}
if ( F_61 ( & V_2 -> V_65 ) >= V_2 -> V_197 )
goto V_292;
V_67 = & V_51 -> V_67 ;
V_290 = F_247 ( int , V_67 -> V_293 , V_194 ) ;
if ( V_290 < V_51 -> V_271 ) {
V_291 = V_51 -> V_271 ;
V_7 = F_6 ( V_291 ,
( V_119 & ~ V_294 ) |
V_295 | V_296 ) ;
}
if ( ! V_7 ) {
V_291 = V_290 ;
V_7 = F_6 ( V_291 , V_119 ) ;
}
if ( ! V_7 )
goto V_292;
F_248 ( V_7 , F_249 ( V_7 ) - V_291 ) ;
F_52 ( V_7 , V_2 ) ;
V_9 = V_67 -> V_297 ( V_7 , V_67 ) ;
if ( V_9 > 0 ) {
F_250 ( V_51 -> V_114 ) ;
if ( F_186 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_172 ( V_2 , V_7 ) ;
return 0 ;
}
V_283 = F_251 ( V_7 , V_67 , V_298 , sizeof( V_9 ) , V_299 ) ;
if ( ! V_283 )
goto V_292;
F_252 ( V_67 , V_283 ) ;
memcpy ( F_245 ( V_283 ) , & V_9 , sizeof( V_9 ) ) ;
if ( F_186 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_172 ( V_2 , V_7 ) ;
if ( V_67 -> V_68 )
V_67 -> V_68 ( V_67 ) ;
V_51 -> V_66 = false ;
V_23 = V_67 -> V_23 ;
V_7 = V_67 -> V_7 ;
F_250 ( V_51 -> V_114 ) ;
F_19 ( V_23 ) ;
F_178 ( V_7 ) ;
return 0 ;
V_292:
F_250 ( V_51 -> V_114 ) ;
F_57 ( V_7 ) ;
return V_100 ;
}
int F_253 ( struct V_1 * V_185 , struct V_6 * V_7 ,
const struct V_281 * V_283 ,
struct V_300 * V_301 )
{
struct V_289 * V_67 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_28 ;
F_41 ( & V_7 -> V_264 ) ;
V_2 = F_92 ( F_84 ( V_185 ) , V_185 -> V_29 , F_7 ( V_7 ) . V_11 ) ;
if ( V_2 == NULL ) {
V_28 = - V_186 ;
goto V_302;
}
V_51 = F_2 ( V_2 ) ;
F_246 ( V_51 -> V_114 ) ;
if ( V_51 -> V_66 ) {
V_28 = - V_101 ;
goto V_303;
}
if ( ! F_117 ( V_301 -> V_23 ) ) {
V_28 = - V_128 ;
goto V_303;
}
V_67 = & V_51 -> V_67 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_304 = V_301 -> V_304 ;
V_67 -> V_297 = V_301 -> V_297 ;
V_67 -> V_68 = V_301 -> V_68 ;
V_67 -> V_283 = V_283 ;
V_67 -> V_14 = V_301 -> V_14 ;
V_67 -> V_23 = V_301 -> V_23 ;
V_67 -> V_293 = V_301 -> V_293 ;
V_67 -> V_7 = V_7 ;
V_51 -> V_66 = true ;
F_250 ( V_51 -> V_114 ) ;
if ( V_67 -> V_304 )
V_67 -> V_304 ( V_67 ) ;
V_28 = F_228 ( V_2 ) ;
F_100 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return - V_305 ;
V_303:
F_100 ( V_2 ) ;
F_250 ( V_51 -> V_114 ) ;
V_302:
F_57 ( V_7 ) ;
return V_28 ;
}
void F_254 ( struct V_6 * V_306 , struct V_281 * V_283 , int V_100 )
{
struct V_6 * V_7 ;
struct V_281 * V_307 ;
struct V_308 * V_309 ;
T_6 V_310 = sizeof( * V_309 ) ;
struct V_50 * V_51 = F_2 ( F_7 ( V_306 ) . V_2 ) ;
if ( ! ( V_51 -> V_3 & V_246 ) && V_100 )
V_310 += V_285 ( V_283 ) ;
V_7 = F_255 ( V_310 , V_119 ) ;
if ( ! V_7 ) {
struct V_1 * V_2 ;
V_2 = F_92 ( F_84 ( V_306 -> V_2 ) ,
V_306 -> V_2 -> V_29 ,
F_7 ( V_306 ) . V_11 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_100 ( V_2 ) ;
}
return;
}
V_307 = F_241 ( V_7 , F_7 ( V_306 ) . V_11 , V_283 -> V_288 ,
V_311 , V_310 , 0 ) ;
V_309 = F_245 ( V_307 ) ;
V_309 -> error = V_100 ;
memcpy ( & V_309 -> V_252 , V_283 , V_310 > sizeof( * V_309 ) ? V_283 -> V_285 : sizeof( * V_283 ) ) ;
F_181 ( V_306 -> V_2 , V_7 , F_7 ( V_306 ) . V_11 , V_265 ) ;
}
int F_256 ( struct V_6 * V_7 , int (* V_67)( struct V_6 * ,
struct V_281 * ) )
{
struct V_281 * V_283 ;
int V_100 ;
while ( V_7 -> V_9 >= F_257 ( 0 ) ) {
int V_312 ;
V_283 = F_258 ( V_7 ) ;
V_100 = 0 ;
if ( V_283 -> V_285 < V_313 || V_7 -> V_9 < V_283 -> V_285 )
return 0 ;
if ( ! ( V_283 -> V_286 & V_314 ) )
goto V_315;
if ( V_283 -> V_284 < V_316 )
goto V_315;
V_100 = V_67 ( V_7 , V_283 ) ;
if ( V_100 == - V_305 )
goto V_317;
V_315:
if ( V_283 -> V_286 & V_318 || V_100 )
F_254 ( V_7 , V_283 , V_100 ) ;
V_317:
V_312 = F_243 ( V_283 -> V_285 ) ;
if ( V_312 > V_7 -> V_9 )
V_312 = V_7 -> V_9 ;
F_259 ( V_7 , V_312 ) ;
}
return 0 ;
}
int F_260 ( struct V_1 * V_2 , struct V_6 * V_7 , T_1 V_11 ,
unsigned int V_5 , int V_319 , T_2 V_3 )
{
int V_100 = 0 ;
if ( V_5 ) {
int V_320 = 0 ;
if ( V_319 ) {
F_41 ( & V_7 -> V_264 ) ;
V_320 = V_11 ;
}
V_100 = F_261 ( V_2 , V_7 , V_320 , V_5 , V_3 ) ;
}
if ( V_319 ) {
int V_321 ;
V_321 = F_262 ( V_2 , V_7 , V_11 ) ;
if ( ! V_100 || V_100 == - V_227 )
V_100 = V_321 ;
}
return V_100 ;
}
static int F_263 ( struct V_322 * V_323 )
{
int V_100 ;
V_100 = F_264 ( & V_93 [ V_323 -> V_324 ] . V_90 , & V_323 -> V_325 ,
V_119 ) ;
if ( V_100 ) {
V_323 -> V_324 = V_127 ;
return V_100 ;
}
V_100 = F_265 ( & V_323 -> V_325 ) ;
return V_100 == - V_198 ? 0 : V_100 ;
}
static void F_266 ( struct V_322 * V_323 )
{
F_267 ( & V_323 -> V_325 ) ;
F_268 ( & V_323 -> V_325 ) ;
}
static void * F_269 ( struct V_326 * V_282 )
{
struct V_322 * V_323 = V_282 -> V_327 ;
struct V_50 * V_51 ;
do {
for (; ; ) {
int V_100 ;
V_51 = F_270 ( & V_323 -> V_325 ) ;
if ( F_184 ( V_51 ) ) {
if ( F_185 ( V_51 ) == - V_198 )
continue;
return V_51 ;
}
if ( V_51 )
break;
F_266 ( V_323 ) ;
if ( ++ V_323 -> V_324 >= V_127 )
return NULL ;
V_100 = F_263 ( V_323 ) ;
if ( V_100 )
return F_158 ( V_100 ) ;
}
} while ( F_84 ( & V_51 -> V_2 ) != F_271 ( V_282 ) );
return V_51 ;
}
static void * F_272 ( struct V_326 * V_282 , T_7 * V_328 )
{
struct V_322 * V_323 = V_282 -> V_327 ;
void * V_329 = V_330 ;
T_7 V_248 ;
int V_100 ;
V_323 -> V_324 = 0 ;
V_100 = F_263 ( V_323 ) ;
if ( V_100 )
return F_158 ( V_100 ) ;
for ( V_248 = * V_328 ; V_248 && V_329 && ! F_184 ( V_329 ) ; V_248 -- )
V_329 = F_269 ( V_282 ) ;
return V_329 ;
}
static void * F_273 ( struct V_326 * V_282 , void * V_331 , T_7 * V_248 )
{
++ * V_248 ;
return F_269 ( V_282 ) ;
}
static void F_274 ( struct V_326 * V_282 , void * V_331 )
{
struct V_322 * V_323 = V_282 -> V_327 ;
if ( V_323 -> V_324 >= V_127 )
return;
F_266 ( V_323 ) ;
}
static int F_275 ( struct V_326 * V_282 , void * V_331 )
{
if ( V_331 == V_330 ) {
F_276 ( V_282 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_332 = V_331 ;
struct V_50 * V_51 = F_2 ( V_332 ) ;
F_277 ( V_282 , L_6 ,
V_332 ,
V_332 -> V_29 ,
V_51 -> V_11 ,
V_51 -> V_72 ? ( T_1 ) V_51 -> V_72 [ 0 ] : 0 ,
F_278 ( V_332 ) ,
F_279 ( V_332 ) ,
V_51 -> V_66 ,
F_61 ( & V_332 -> V_109 ) ,
F_61 ( & V_332 -> V_58 ) ,
F_280 ( V_332 )
) ;
}
return 0 ;
}
static int F_281 ( struct V_188 * V_188 , struct V_153 * V_153 )
{
return F_282 ( V_188 , V_153 , & V_333 ,
sizeof( struct V_322 ) ) ;
}
int F_283 ( struct V_334 * V_335 )
{
return F_284 ( & V_139 , V_335 ) ;
}
int F_285 ( struct V_334 * V_335 )
{
return F_286 ( & V_139 , V_335 ) ;
}
static int T_8 F_287 ( struct V_87 * V_87 )
{
#ifdef F_288
if ( ! F_289 ( L_7 , 0 , V_87 -> V_336 , & V_337 ) )
return - V_40 ;
#endif
return 0 ;
}
static void T_9 F_290 ( struct V_87 * V_87 )
{
#ifdef F_288
F_291 ( L_7 , V_87 -> V_336 ) ;
#endif
}
static void T_10 F_292 ( void )
{
struct V_97 * V_97 ;
int V_72 = 32 ;
V_97 = F_234 ( sizeof( * V_97 ) + F_148 ( V_72 ) , V_119 ) ;
if ( ! V_97 )
F_293 ( L_8 ) ;
F_65 () ;
V_93 [ V_31 ] . V_72 = V_72 ;
F_235 ( V_93 [ V_31 ] . V_97 , V_97 ) ;
V_93 [ V_31 ] . V_23 = V_338 ;
V_93 [ V_31 ] . V_129 = 1 ;
V_93 [ V_31 ] . V_3 = V_179 ;
F_75 () ;
}
static inline T_1 F_294 ( const void * V_14 , T_1 V_9 , T_1 V_339 )
{
const struct V_50 * V_51 = V_14 ;
struct V_83 V_81 ;
F_86 ( & V_81 , F_84 ( & V_51 -> V_2 ) , V_51 -> V_11 ) ;
return F_295 ( ( T_1 * ) & V_81 , V_340 / sizeof( T_1 ) , V_339 ) ;
}
static int T_10 F_296 ( void )
{
int V_96 ;
int V_100 = F_297 ( & V_120 , 0 ) ;
if ( V_100 != 0 )
goto V_26;
F_298 ( sizeof( struct V_146 ) > F_299 ( struct V_6 , V_67 ) ) ;
V_93 = F_300 ( V_127 , sizeof( * V_93 ) , V_119 ) ;
if ( ! V_93 )
goto F_293;
for ( V_96 = 0 ; V_96 < V_127 ; V_96 ++ ) {
if ( F_301 ( & V_93 [ V_96 ] . V_90 ,
& V_91 ) < 0 ) {
while ( -- V_96 > 0 )
F_302 ( & V_93 [ V_96 ] . V_90 ) ;
F_131 ( V_93 ) ;
goto F_293;
}
}
F_303 ( & V_22 ) ;
F_292 () ;
F_304 ( & V_341 ) ;
F_305 ( & V_342 ) ;
F_306 () ;
V_26:
return V_100 ;
F_293:
F_293 ( L_9 ) ;
}
