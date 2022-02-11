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
F_8 ( V_10 , V_7 -> V_14 , V_9 ) ;
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
F_53 ( F_62 ( & V_2 -> V_71 ) ) ;
F_53 ( F_2 ( V_2 ) -> V_72 ) ;
}
static void F_63 ( struct V_73 * V_74 )
{
struct V_50 * V_51 = F_64 ( V_74 , struct V_50 ,
V_74 ) ;
F_65 ( & V_51 -> V_2 ) ;
}
void F_66 ( void )
__acquires( T_3 )
{
F_67 () ;
F_68 ( & T_3 ) ;
if ( F_61 ( & V_75 ) ) {
F_69 ( V_60 , V_76 ) ;
F_70 ( & V_77 , & V_60 ) ;
for (; ; ) {
F_71 ( V_78 ) ;
if ( F_61 ( & V_75 ) == 0 )
break;
F_72 ( & T_3 ) ;
F_73 () ;
F_68 ( & T_3 ) ;
}
F_74 ( V_79 ) ;
F_75 ( & V_77 , & V_60 ) ;
}
}
void F_76 ( void )
__releases( T_3 )
{
F_72 ( & T_3 ) ;
F_77 ( & V_77 ) ;
}
static inline void
F_78 ( void )
{
F_79 ( & T_3 ) ;
F_41 ( & V_75 ) ;
F_80 ( & T_3 ) ;
}
static inline void
F_81 ( void )
{
if ( F_82 ( & V_75 ) )
F_77 ( & V_77 ) ;
}
static inline int F_83 ( struct V_80 * V_81 ,
const void * V_82 )
{
const struct V_83 * V_84 = V_81 -> V_85 ;
const struct V_50 * V_51 = V_82 ;
return V_51 -> V_11 != V_84 -> V_11 ||
! F_84 ( F_85 ( & V_51 -> V_2 ) , F_86 ( & V_84 -> V_86 ) ) ;
}
static void F_87 ( struct V_83 * V_81 ,
struct V_87 * V_87 , T_1 V_11 )
{
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
F_88 ( & V_81 -> V_86 , V_87 ) ;
V_81 -> V_11 = V_11 ;
}
static struct V_1 * F_89 ( struct V_88 * V_89 , T_1 V_11 ,
struct V_87 * V_87 )
{
struct V_83 V_81 ;
F_87 ( & V_81 , V_87 , V_11 ) ;
return F_90 ( & V_89 -> V_90 , & V_81 ,
V_91 ) ;
}
static int F_91 ( struct V_88 * V_89 , struct V_1 * V_2 )
{
struct V_83 V_81 ;
F_87 ( & V_81 , F_85 ( V_2 ) , F_2 ( V_2 ) -> V_11 ) ;
return F_92 ( & V_89 -> V_90 , & V_81 ,
& F_2 ( V_2 ) -> V_92 ,
V_91 ) ;
}
static struct V_1 * F_93 ( struct V_87 * V_87 , int V_43 , T_1 V_11 )
{
struct V_88 * V_89 = & V_93 [ V_43 ] ;
struct V_1 * V_2 ;
F_35 () ;
V_2 = F_89 ( V_89 , V_11 , V_87 ) ;
if ( V_2 )
F_94 ( V_2 ) ;
F_37 () ;
return V_2 ;
}
static void
F_95 ( struct V_1 * V_2 )
{
struct V_88 * V_94 = & V_93 [ V_2 -> V_29 ] ;
unsigned long V_95 ;
unsigned int V_96 ;
struct V_97 * V_97 ;
V_97 = F_96 ( V_94 -> V_97 ) ;
if ( ! V_97 )
return;
for ( V_96 = 0 ; V_96 < F_97 ( V_94 -> V_72 ) ; V_96 ++ ) {
V_95 = 0 ;
F_98 (sk, &tbl->mc_list) {
if ( V_96 < F_97 ( F_2 ( V_2 ) -> V_98 ) )
V_95 |= F_2 ( V_2 ) -> V_72 [ V_96 ] ;
}
V_97 -> V_99 [ V_96 ] = V_95 ;
}
}
static int F_99 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_88 * V_89 = & V_93 [ V_2 -> V_29 ] ;
int V_100 ;
F_100 ( V_2 ) ;
V_100 = F_2 ( V_2 ) -> V_11 == V_11 ? 0 : - V_101 ;
if ( F_2 ( V_2 ) -> V_102 )
goto V_100;
V_100 = - V_40 ;
if ( V_103 > 32 &&
F_10 ( F_61 ( & V_89 -> V_90 . V_104 ) >= V_105 ) )
goto V_100;
F_2 ( V_2 ) -> V_11 = V_11 ;
F_94 ( V_2 ) ;
V_100 = F_91 ( V_89 , V_2 ) ;
if ( V_100 ) {
if ( F_10 ( V_100 == - V_101 ) )
V_100 = - V_106 ;
if ( V_100 == - V_107 )
V_100 = - V_108 ;
F_101 ( V_2 ) ;
goto V_100;
}
F_102 () ;
F_2 ( V_2 ) -> V_102 = V_11 ;
V_100:
F_103 ( V_2 ) ;
return V_100 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_88 * V_89 ;
V_89 = & V_93 [ V_2 -> V_29 ] ;
if ( ! F_105 ( & V_89 -> V_90 , & F_2 ( V_2 ) -> V_92 ,
V_91 ) ) {
F_53 ( F_62 ( & V_2 -> V_109 ) == 1 ) ;
F_106 ( V_2 ) ;
}
F_66 () ;
if ( F_2 ( V_2 ) -> V_110 ) {
F_107 ( V_2 ) ;
F_95 ( V_2 ) ;
}
if ( V_2 -> V_29 == V_37 )
F_41 ( & V_111 ) ;
F_76 () ;
}
static int F_108 ( struct V_87 * V_87 , struct V_112 * V_1 ,
struct V_113 * V_114 , int V_43 ,
int V_115 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_1 -> V_116 = & V_117 ;
V_2 = F_109 ( V_87 , V_118 , V_119 , & V_120 , V_115 ) ;
if ( ! V_2 )
return - V_40 ;
F_110 ( V_1 , V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_114 ) {
V_51 -> V_114 = V_114 ;
} else {
V_51 -> V_114 = & V_51 -> V_121 ;
F_111 ( V_51 -> V_114 ) ;
F_112 ( V_51 -> V_114 ,
V_122 + V_43 ,
V_123 [ V_43 ] ) ;
}
F_113 ( & V_51 -> V_60 ) ;
V_2 -> V_124 = F_56 ;
V_2 -> V_29 = V_43 ;
return 0 ;
}
static int F_114 ( struct V_87 * V_87 , struct V_112 * V_1 , int V_43 ,
int V_115 )
{
struct V_23 * V_23 = NULL ;
struct V_113 * V_114 ;
struct V_50 * V_51 ;
int (* F_115)( struct V_87 * V_87 , int V_5 );
void (* F_116)( struct V_87 * V_87 , int V_5 );
int V_100 = 0 ;
V_1 -> V_54 = V_125 ;
if ( V_1 -> type != V_126 && V_1 -> type != V_127 )
return - V_128 ;
if ( V_43 < 0 || V_43 >= V_129 )
return - V_130 ;
F_78 () ;
#ifdef F_117
if ( ! V_93 [ V_43 ] . V_131 ) {
F_81 () ;
F_118 ( L_3 , V_118 , V_43 ) ;
F_78 () ;
}
#endif
if ( V_93 [ V_43 ] . V_131 &&
F_119 ( V_93 [ V_43 ] . V_23 ) )
V_23 = V_93 [ V_43 ] . V_23 ;
else
V_100 = - V_130 ;
V_114 = V_93 [ V_43 ] . V_114 ;
F_115 = V_93 [ V_43 ] . F_115 ;
F_116 = V_93 [ V_43 ] . F_116 ;
F_81 () ;
if ( V_100 < 0 )
goto V_26;
V_100 = F_108 ( V_87 , V_1 , V_114 , V_43 , V_115 ) ;
if ( V_100 < 0 )
goto V_132;
F_120 () ;
F_121 ( V_87 , & V_120 , 1 ) ;
F_122 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_23 = V_23 ;
V_51 -> V_133 = F_115 ;
V_51 -> V_134 = F_116 ;
V_26:
return V_100 ;
V_132:
F_19 ( V_23 ) ;
goto V_26;
}
static void F_123 ( struct V_135 * V_41 )
{
struct V_50 * V_51 = F_64 ( V_41 , struct V_50 , V_136 ) ;
struct V_1 * V_2 = & V_51 -> V_2 ;
if ( ! F_124 ( & V_2 -> V_109 ) )
return;
if ( V_51 -> V_66 && V_51 -> V_67 . V_68 ) {
F_125 ( & V_51 -> V_74 , F_63 ) ;
F_126 ( & V_51 -> V_74 ) ;
return;
}
F_65 ( V_2 ) ;
}
static int F_127 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_104 ( V_2 ) ;
F_128 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_134 ) {
int V_96 ;
for ( V_96 = 0 ; V_96 < V_51 -> V_98 ; V_96 ++ )
if ( F_45 ( V_96 , V_51 -> V_72 ) )
V_51 -> V_134 ( F_85 ( V_2 ) , V_96 + 1 ) ;
}
if ( V_2 -> V_29 == V_37 &&
F_48 ( & V_111 ) == 0 )
F_77 ( & V_137 ) ;
V_1 -> V_2 = NULL ;
F_129 ( & V_51 -> V_60 ) ;
F_58 ( & V_2 -> V_138 ) ;
if ( V_51 -> V_11 && V_51 -> V_102 ) {
struct V_139 V_140 = {
. V_87 = F_85 ( V_2 ) ,
. V_43 = V_2 -> V_29 ,
. V_11 = V_51 -> V_11 ,
} ;
F_130 ( & V_141 ,
V_142 , & V_140 ) ;
}
F_19 ( V_51 -> V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_66 () ;
F_131 ( V_93 [ V_2 -> V_29 ] . V_131 == 0 ) ;
if ( -- V_93 [ V_2 -> V_29 ] . V_131 == 0 ) {
struct V_97 * V_143 ;
V_143 = F_96 ( V_93 [ V_2 -> V_29 ] . V_97 ) ;
F_132 ( V_93 [ V_2 -> V_29 ] . V_97 , NULL ) ;
F_133 ( V_143 , V_136 ) ;
V_93 [ V_2 -> V_29 ] . V_23 = NULL ;
V_93 [ V_2 -> V_29 ] . F_115 = NULL ;
V_93 [ V_2 -> V_29 ] . F_116 = NULL ;
V_93 [ V_2 -> V_29 ] . V_3 = 0 ;
V_93 [ V_2 -> V_29 ] . V_131 = 0 ;
}
F_76 () ;
}
F_134 ( V_51 -> V_72 ) ;
V_51 -> V_72 = NULL ;
F_120 () ;
F_121 ( F_85 ( V_2 ) , & V_120 , - 1 ) ;
F_122 () ;
F_135 ( & V_51 -> V_136 , F_123 ) ;
return 0 ;
}
static int F_136 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_87 * V_87 = F_85 ( V_2 ) ;
struct V_88 * V_89 = & V_93 [ V_2 -> V_29 ] ;
T_4 V_11 = F_137 ( V_76 ) ;
int V_100 ;
T_4 V_144 = - 4096 ;
bool V_145 ;
V_146:
F_138 () ;
F_35 () ;
V_145 = ! F_89 ( V_89 , V_11 , V_87 ) ;
F_37 () ;
if ( ! V_145 ) {
if ( V_144 == - 4096 )
V_144 = V_147 + F_139 ( - 4096 - V_147 ) ;
else if ( V_144 >= - 4096 )
V_144 = - 4097 ;
V_11 = V_144 -- ;
goto V_146;
}
V_100 = F_99 ( V_2 , V_11 ) ;
if ( V_100 == - V_108 )
goto V_146;
if ( V_100 == - V_101 )
V_100 = 0 ;
return V_100 ;
}
bool F_140 ( const struct V_148 * V_149 ,
struct V_150 * V_151 , int V_152 )
{
return ( ( V_149 -> V_3 & V_153 ) ||
F_141 ( V_149 -> V_2 -> V_154 -> V_155 , V_151 , V_152 ) ) &&
F_142 ( V_151 , V_152 ) ;
}
bool F_143 ( const struct V_6 * V_7 ,
struct V_150 * V_151 , int V_152 )
{
return F_140 ( & F_7 ( V_7 ) , V_151 , V_152 ) ;
}
bool F_144 ( const struct V_6 * V_7 , int V_152 )
{
return F_143 ( V_7 , & V_156 , V_152 ) ;
}
bool F_145 ( const struct V_6 * V_7 , int V_152 )
{
return F_143 ( V_7 , F_85 ( V_7 -> V_2 ) -> V_151 , V_152 ) ;
}
static inline int F_146 ( const struct V_112 * V_1 , unsigned int V_157 )
{
return ( V_93 [ V_1 -> V_2 -> V_29 ] . V_3 & V_157 ) ||
F_142 ( F_85 ( V_1 -> V_2 ) -> V_151 , V_158 ) ;
}
static void
F_147 ( struct V_1 * V_2 , unsigned int V_110 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_110 && ! V_110 )
F_107 ( V_2 ) ;
else if ( ! V_51 -> V_110 && V_110 )
F_148 ( V_2 , & V_93 [ V_2 -> V_29 ] . V_159 ) ;
V_51 -> V_110 = V_110 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_72 ;
unsigned long * V_160 ;
int V_100 = 0 ;
F_66 () ;
V_72 = V_93 [ V_2 -> V_29 ] . V_72 ;
if ( ! V_93 [ V_2 -> V_29 ] . V_131 ) {
V_100 = - V_161 ;
goto V_162;
}
if ( V_51 -> V_98 >= V_72 )
goto V_162;
V_160 = F_150 ( V_51 -> V_72 , F_151 ( V_72 ) , V_42 ) ;
if ( V_160 == NULL ) {
V_100 = - V_40 ;
goto V_162;
}
memset ( ( char * ) V_160 + F_151 ( V_51 -> V_98 ) , 0 ,
F_151 ( V_72 ) - F_151 ( V_51 -> V_98 ) ) ;
V_51 -> V_72 = V_160 ;
V_51 -> V_98 = V_72 ;
V_162:
F_76 () ;
return V_100 ;
}
static void F_152 ( int V_5 , long unsigned int V_72 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_163 ;
if ( ! V_51 -> V_134 )
return;
for ( V_163 = 0 ; V_163 < V_5 ; V_163 ++ )
if ( F_45 ( V_163 , & V_72 ) )
V_51 -> V_134 ( F_85 ( V_2 ) , V_163 + 1 ) ;
}
static int V_133 ( struct V_112 * V_1 , struct V_164 * V_165 ,
int V_166 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_87 * V_87 = F_85 ( V_2 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_167 * V_168 = (struct V_167 * ) V_165 ;
int V_100 ;
long unsigned int V_72 = V_168 -> V_169 ;
bool V_102 ;
if ( V_166 < sizeof( struct V_167 ) )
return - V_19 ;
if ( V_168 -> V_170 != V_171 )
return - V_19 ;
if ( V_72 ) {
if ( ! F_146 ( V_1 , V_172 ) )
return - V_173 ;
V_100 = F_149 ( V_2 ) ;
if ( V_100 )
return V_100 ;
}
V_102 = V_51 -> V_102 ;
if ( V_102 ) {
F_153 () ;
if ( V_168 -> V_174 != V_51 -> V_11 )
return - V_19 ;
}
if ( V_51 -> V_133 && V_72 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_51 -> V_98 ; V_5 ++ ) {
if ( ! F_45 ( V_5 , & V_72 ) )
continue;
V_100 = V_51 -> V_133 ( V_87 , V_5 + 1 ) ;
if ( ! V_100 )
continue;
F_152 ( V_5 , V_72 , V_2 ) ;
return V_100 ;
}
}
if ( ! V_102 ) {
V_100 = V_168 -> V_174 ?
F_99 ( V_2 , V_168 -> V_174 ) :
F_136 ( V_1 ) ;
if ( V_100 ) {
F_152 ( V_51 -> V_98 , V_72 , V_2 ) ;
return V_100 ;
}
}
if ( ! V_72 && ( V_51 -> V_72 == NULL || ! ( T_1 ) V_51 -> V_72 [ 0 ] ) )
return 0 ;
F_66 () ;
F_147 ( V_2 , V_51 -> V_110 +
F_154 ( V_72 ) -
F_154 ( V_51 -> V_72 [ 0 ] ) ) ;
V_51 -> V_72 [ 0 ] = ( V_51 -> V_72 [ 0 ] & ~ 0xffffffffUL ) | V_72 ;
F_95 ( V_2 ) ;
F_76 () ;
return 0 ;
}
static int F_155 ( struct V_112 * V_1 , struct V_164 * V_165 ,
int V_175 , int V_3 )
{
int V_100 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_167 * V_168 = (struct V_167 * ) V_165 ;
if ( V_175 < sizeof( V_165 -> V_176 ) )
return - V_19 ;
if ( V_165 -> V_176 == V_177 ) {
V_2 -> V_178 = V_179 ;
V_51 -> V_180 = 0 ;
V_51 -> V_12 = 0 ;
return 0 ;
}
if ( V_165 -> V_176 != V_171 )
return - V_19 ;
if ( ( V_168 -> V_169 || V_168 -> V_174 ) &&
! F_146 ( V_1 , V_181 ) )
return - V_173 ;
if ( ! V_51 -> V_102 )
V_100 = F_136 ( V_1 ) ;
if ( V_100 == 0 ) {
V_2 -> V_178 = V_182 ;
V_51 -> V_180 = V_168 -> V_174 ;
V_51 -> V_12 = F_156 ( V_168 -> V_169 ) ;
}
return V_100 ;
}
static int F_157 ( struct V_112 * V_1 , struct V_164 * V_165 ,
int * V_166 , int V_183 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_158 ( struct V_167 * , V_168 , V_165 ) ;
V_168 -> V_170 = V_171 ;
V_168 -> V_184 = 0 ;
* V_166 = sizeof( * V_168 ) ;
if ( V_183 ) {
V_168 -> V_174 = V_51 -> V_180 ;
V_168 -> V_169 = F_3 ( V_51 -> V_12 ) ;
} else {
V_168 -> V_174 = V_51 -> V_11 ;
V_168 -> V_169 = V_51 -> V_72 ? V_51 -> V_72 [ 0 ] : 0 ;
}
return 0 ;
}
static int F_159 ( struct V_112 * V_1 , unsigned int V_185 ,
unsigned long V_81 )
{
return - V_186 ;
}
static struct V_1 * F_160 ( struct V_1 * V_187 , T_1 V_11 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_93 ( F_85 ( V_187 ) , V_187 -> V_29 , V_11 ) ;
if ( ! V_1 )
return F_161 ( - V_188 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_178 == V_182 &&
V_51 -> V_180 != F_2 ( V_187 ) -> V_11 ) {
F_101 ( V_1 ) ;
return F_161 ( - V_188 ) ;
}
return V_1 ;
}
struct V_1 * F_162 ( struct V_155 * V_189 )
{
struct V_190 * V_190 = F_163 ( V_189 ) ;
struct V_1 * V_1 ;
if ( ! F_164 ( V_190 -> V_191 ) )
return F_161 ( - V_192 ) ;
V_1 = F_165 ( V_190 ) -> V_2 ;
if ( V_1 -> V_193 != V_171 )
return F_161 ( - V_19 ) ;
F_94 ( V_1 ) ;
return V_1 ;
}
static struct V_6 * F_166 ( unsigned int V_194 ,
int V_195 )
{
struct V_6 * V_7 ;
void * V_14 ;
if ( V_194 <= V_196 || V_195 )
return F_6 ( V_194 , V_119 ) ;
V_194 = F_167 ( V_194 ) +
F_167 ( sizeof( struct V_197 ) ) ;
V_14 = F_168 ( V_194 ) ;
if ( V_14 == NULL )
return NULL ;
V_7 = F_169 ( V_14 , V_194 ) ;
if ( V_7 == NULL )
F_50 ( V_14 ) ;
else
V_7 -> V_63 = F_47 ;
return V_7 ;
}
int F_170 ( struct V_1 * V_2 , struct V_6 * V_7 ,
long * V_198 , struct V_1 * V_187 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_199 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) ) {
F_69 ( V_60 , V_76 ) ;
if ( ! * V_198 ) {
if ( ! V_187 || F_1 ( V_187 ) )
F_39 ( V_2 ) ;
F_101 ( V_2 ) ;
F_57 ( V_7 ) ;
return - V_200 ;
}
F_74 ( V_201 ) ;
F_171 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_199 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) &&
! F_59 ( V_2 , V_69 ) )
* V_198 = F_172 ( * V_198 ) ;
F_74 ( V_79 ) ;
F_75 ( & V_51 -> V_60 , & V_60 ) ;
F_101 ( V_2 ) ;
if ( F_173 ( V_76 ) ) {
F_57 ( V_7 ) ;
return F_174 ( * V_198 ) ;
}
return 1 ;
}
F_52 ( V_7 , V_2 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = V_7 -> V_9 ;
F_34 ( V_7 ) ;
F_176 ( & V_2 -> V_59 , V_7 ) ;
V_2 -> V_202 ( V_2 ) ;
return V_9 ;
}
int F_177 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = F_175 ( V_2 , V_7 ) ;
F_101 ( V_2 ) ;
return V_9 ;
}
void F_178 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_57 ( V_7 ) ;
F_101 ( V_2 ) ;
}
static struct V_6 * F_179 ( struct V_6 * V_7 , T_2 V_203 )
{
int V_204 ;
F_53 ( V_7 -> V_2 != NULL ) ;
V_204 = V_7 -> V_205 - V_7 -> V_206 ;
if ( F_25 ( V_7 -> V_41 ) || V_204 * 2 < V_7 -> V_64 )
return V_7 ;
if ( F_180 ( V_7 ) ) {
struct V_6 * V_39 = F_26 ( V_7 , V_203 ) ;
if ( ! V_39 )
return V_7 ;
F_181 ( V_7 ) ;
V_7 = V_39 ;
}
F_182 ( V_7 , 0 , - V_204 ,
( V_203 & ~ V_207 ) |
V_208 | V_209 ) ;
return V_7 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_1 * V_187 )
{
int V_28 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
V_28 = - V_188 ;
if ( V_51 -> V_210 != NULL ) {
V_28 = V_7 -> V_9 ;
F_52 ( V_7 , V_2 ) ;
F_7 ( V_7 ) . V_2 = V_187 ;
F_38 ( V_2 , V_187 , V_7 ) ;
V_51 -> V_210 ( V_7 ) ;
F_181 ( V_7 ) ;
} else {
F_57 ( V_7 ) ;
}
F_101 ( V_2 ) ;
return V_28 ;
}
int F_184 ( struct V_1 * V_187 , struct V_6 * V_7 ,
T_1 V_11 , int V_211 )
{
struct V_1 * V_2 ;
int V_100 ;
long V_198 ;
V_7 = F_179 ( V_7 , F_185 () ) ;
V_198 = F_186 ( V_187 , V_211 ) ;
V_146:
V_2 = F_160 ( V_187 , V_11 ) ;
if ( F_187 ( V_2 ) ) {
F_57 ( V_7 ) ;
return F_188 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_183 ( V_2 , V_7 , V_187 ) ;
if ( F_189 ( V_2 , V_7 ) ) {
V_100 = V_7 -> V_9 ;
F_57 ( V_7 ) ;
F_101 ( V_2 ) ;
return V_100 ;
}
V_100 = F_170 ( V_2 , V_7 , & V_198 , V_187 ) ;
if ( V_100 == 1 )
goto V_146;
if ( V_100 )
return V_100 ;
return F_177 ( V_2 , V_7 ) ;
}
int F_190 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_212 = 0 ;
struct V_97 * V_97 ;
F_131 ( ! F_1 ( V_2 ) ) ;
F_35 () ;
V_97 = F_191 ( V_93 [ V_2 -> V_29 ] . V_97 ) ;
if ( V_97 && V_5 - 1 < V_93 [ V_2 -> V_29 ] . V_72 )
V_212 = F_45 ( V_5 - 1 , V_97 -> V_99 ) ;
F_37 () ;
return V_212 ;
}
static int F_192 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_61 ( & V_2 -> V_65 ) <= V_2 -> V_199 &&
! F_45 ( V_53 , & V_51 -> V_54 ) ) {
F_52 ( V_7 , V_2 ) ;
F_175 ( V_2 , V_7 ) ;
return F_61 ( & V_2 -> V_65 ) > ( V_2 -> V_199 >> 1 ) ;
}
return - 1 ;
}
static void F_193 ( struct V_1 * V_2 ,
struct V_213 * V_214 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_215 ;
if ( V_214 -> V_216 == V_2 )
return;
if ( V_51 -> V_11 == V_214 -> V_11 || V_214 -> V_5 - 1 >= V_51 -> V_98 ||
! F_45 ( V_214 -> V_5 - 1 , V_51 -> V_72 ) )
return;
if ( ! F_84 ( F_85 ( V_2 ) , V_214 -> V_87 ) ) {
if ( ! ( V_51 -> V_3 & V_217 ) )
return;
if ( ! F_194 ( F_85 ( V_2 ) , V_214 -> V_87 ) )
return;
if ( ! F_141 ( V_2 -> V_154 -> V_155 , V_214 -> V_87 -> V_151 ,
V_218 ) )
return;
}
if ( V_214 -> V_219 ) {
F_39 ( V_2 ) ;
return;
}
F_94 ( V_2 ) ;
if ( V_214 -> V_220 == NULL ) {
if ( F_180 ( V_214 -> V_7 ) ) {
V_214 -> V_220 = F_26 ( V_214 -> V_7 , V_214 -> V_203 ) ;
} else {
V_214 -> V_220 = F_195 ( V_214 -> V_7 ) ;
F_196 ( V_214 -> V_220 ) ;
}
}
if ( V_214 -> V_220 == NULL ) {
F_39 ( V_2 ) ;
V_214 -> V_219 = 1 ;
if ( V_51 -> V_3 & V_221 )
V_214 -> V_222 = 1 ;
goto V_26;
}
if ( V_214 -> V_223 && V_214 -> V_223 ( V_2 , V_214 -> V_220 , V_214 -> V_224 ) ) {
F_57 ( V_214 -> V_220 ) ;
V_214 -> V_220 = NULL ;
goto V_26;
}
if ( F_189 ( V_2 , V_214 -> V_220 ) ) {
F_57 ( V_214 -> V_220 ) ;
V_214 -> V_220 = NULL ;
goto V_26;
}
F_7 ( V_214 -> V_220 ) . V_225 = F_197 ( F_85 ( V_2 ) , V_214 -> V_87 ) ;
if ( F_7 ( V_214 -> V_220 ) . V_225 != V_226 )
F_7 ( V_214 -> V_220 ) . V_227 = true ;
V_215 = F_192 ( V_2 , V_214 -> V_220 ) ;
if ( V_215 < 0 ) {
F_39 ( V_2 ) ;
if ( V_51 -> V_3 & V_221 )
V_214 -> V_222 = 1 ;
} else {
V_214 -> V_228 |= V_215 ;
V_214 -> V_229 = 1 ;
V_214 -> V_220 = NULL ;
}
V_26:
F_101 ( V_2 ) ;
}
int F_198 ( struct V_1 * V_187 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_203 ,
int (* F_199)( struct V_1 * V_230 , struct V_6 * V_7 , void * V_14 ) ,
void * V_231 )
{
struct V_87 * V_87 = F_85 ( V_187 ) ;
struct V_213 V_232 ;
struct V_1 * V_2 ;
V_7 = F_179 ( V_7 , V_203 ) ;
V_232 . V_216 = V_187 ;
V_232 . V_87 = V_87 ;
V_232 . V_11 = V_11 ;
V_232 . V_5 = V_5 ;
V_232 . V_219 = 0 ;
V_232 . V_222 = 0 ;
V_232 . V_228 = 0 ;
V_232 . V_229 = 0 ;
V_232 . V_203 = V_203 ;
V_232 . V_7 = V_7 ;
V_232 . V_220 = NULL ;
V_232 . V_223 = F_199 ;
V_232 . V_224 = V_231 ;
F_78 () ;
F_98 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_193 ( V_2 , & V_232 ) ;
F_181 ( V_7 ) ;
F_81 () ;
if ( V_232 . V_222 ) {
F_57 ( V_232 . V_220 ) ;
return - V_56 ;
}
F_181 ( V_232 . V_220 ) ;
if ( V_232 . V_229 ) {
if ( V_232 . V_228 && F_200 ( V_203 ) )
F_201 () ;
return 0 ;
}
return - V_233 ;
}
int F_202 ( struct V_1 * V_187 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_203 )
{
return F_198 ( V_187 , V_7 , V_11 , V_5 , V_203 ,
NULL , NULL ) ;
}
static int F_203 ( struct V_1 * V_2 , struct V_234 * V_214 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_28 = 0 ;
if ( V_2 == V_214 -> V_216 )
goto V_26;
if ( ! F_84 ( F_85 ( V_2 ) , F_85 ( V_214 -> V_216 ) ) )
goto V_26;
if ( V_51 -> V_11 == V_214 -> V_11 || V_214 -> V_5 - 1 >= V_51 -> V_98 ||
! F_45 ( V_214 -> V_5 - 1 , V_51 -> V_72 ) )
goto V_26;
if ( V_214 -> V_235 == V_56 && V_51 -> V_3 & V_52 ) {
V_28 = 1 ;
goto V_26;
}
V_2 -> V_55 = V_214 -> V_235 ;
V_2 -> V_57 ( V_2 ) ;
V_26:
return V_28 ;
}
int F_204 ( struct V_1 * V_187 , T_1 V_11 , T_1 V_5 , int V_235 )
{
struct V_234 V_232 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
V_232 . V_216 = V_187 ;
V_232 . V_11 = V_11 ;
V_232 . V_5 = V_5 ;
V_232 . V_235 = - V_235 ;
F_79 ( & T_3 ) ;
F_98 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_28 += F_203 ( V_2 , & V_232 ) ;
F_80 ( & T_3 ) ;
return V_28 ;
}
static void F_205 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_236 )
{
int V_143 , V_10 = ! ! V_236 , V_110 ;
V_143 = F_45 ( V_5 - 1 , V_51 -> V_72 ) ;
V_110 = V_51 -> V_110 - V_143 + V_10 ;
if ( V_10 )
F_206 ( V_5 - 1 , V_51 -> V_72 ) ;
else
F_207 ( V_5 - 1 , V_51 -> V_72 ) ;
F_147 ( & V_51 -> V_2 , V_110 ) ;
F_95 ( & V_51 -> V_2 ) ;
}
static int F_208 ( struct V_112 * V_1 , int V_237 , int V_238 ,
char T_5 * V_239 , unsigned int V_240 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_215 = 0 ;
int V_100 ;
if ( V_237 != V_241 )
return - V_242 ;
if ( V_240 >= sizeof( int ) &&
F_209 ( V_215 , ( unsigned int T_5 * ) V_239 ) )
return - V_243 ;
switch ( V_238 ) {
case V_244 :
if ( V_215 )
V_51 -> V_3 |= V_245 ;
else
V_51 -> V_3 &= ~ V_245 ;
V_100 = 0 ;
break;
case V_246 :
case V_247 : {
if ( ! F_146 ( V_1 , V_172 ) )
return - V_173 ;
V_100 = F_149 ( V_2 ) ;
if ( V_100 )
return V_100 ;
if ( ! V_215 || V_215 - 1 >= V_51 -> V_98 )
return - V_19 ;
if ( V_238 == V_246 && V_51 -> V_133 ) {
V_100 = V_51 -> V_133 ( F_85 ( V_2 ) , V_215 ) ;
if ( V_100 )
return V_100 ;
}
F_66 () ;
F_205 ( V_51 , V_215 ,
V_238 == V_246 ) ;
F_76 () ;
if ( V_238 == V_247 && V_51 -> V_134 )
V_51 -> V_134 ( F_85 ( V_2 ) , V_215 ) ;
V_100 = 0 ;
break;
}
case V_248 :
if ( V_215 )
V_51 -> V_3 |= V_221 ;
else
V_51 -> V_3 &= ~ V_221 ;
V_100 = 0 ;
break;
case V_249 :
if ( V_215 ) {
V_51 -> V_3 |= V_52 ;
F_44 ( V_53 , & V_51 -> V_54 ) ;
F_46 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_100 = 0 ;
break;
case V_250 :
if ( ! F_142 ( F_85 ( V_2 ) -> V_151 , V_218 ) )
return - V_173 ;
if ( V_215 )
V_51 -> V_3 |= V_217 ;
else
V_51 -> V_3 &= ~ V_217 ;
V_100 = 0 ;
break;
case V_251 :
if ( V_215 )
V_51 -> V_3 |= V_252 ;
else
V_51 -> V_3 &= ~ V_252 ;
V_100 = 0 ;
break;
case V_253 :
if ( V_215 )
V_51 -> V_3 |= V_254 ;
else
V_51 -> V_3 &= ~ V_254 ;
V_100 = 0 ;
break;
default:
V_100 = - V_242 ;
}
return V_100 ;
}
static int F_210 ( struct V_112 * V_1 , int V_237 , int V_238 ,
char T_5 * V_239 , int T_5 * V_240 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_9 , V_215 , V_100 ;
if ( V_237 != V_241 )
return - V_242 ;
if ( F_209 ( V_9 , V_240 ) )
return - V_243 ;
if ( V_9 < 0 )
return - V_19 ;
switch ( V_238 ) {
case V_244 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_245 ? 1 : 0 ;
if ( F_211 ( V_9 , V_240 ) ||
F_211 ( V_215 , V_239 ) )
return - V_243 ;
V_100 = 0 ;
break;
case V_248 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_221 ? 1 : 0 ;
if ( F_211 ( V_9 , V_240 ) ||
F_211 ( V_215 , V_239 ) )
return - V_243 ;
V_100 = 0 ;
break;
case V_249 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_211 ( V_9 , V_240 ) ||
F_211 ( V_215 , V_239 ) )
return - V_243 ;
V_100 = 0 ;
break;
case V_255 : {
int V_256 , V_257 , V_258 ;
V_100 = 0 ;
F_78 () ;
for ( V_256 = 0 ; V_256 * 8 < V_51 -> V_98 ; V_256 += sizeof( T_1 ) ) {
if ( V_9 - V_256 < sizeof( T_1 ) )
break;
V_257 = V_256 / sizeof( unsigned long ) ;
V_258 = ( V_256 % sizeof( unsigned long ) ) * 8 ;
if ( F_211 ( ( T_1 ) ( V_51 -> V_72 [ V_257 ] >> V_258 ) ,
( T_1 T_5 * ) ( V_239 + V_256 ) ) ) {
V_100 = - V_243 ;
break;
}
}
if ( F_211 ( F_212 ( V_51 -> V_98 / 8 , sizeof( T_1 ) ) , V_240 ) )
V_100 = - V_243 ;
F_81 () ;
break;
}
case V_251 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_252 ? 1 : 0 ;
if ( F_211 ( V_9 , V_240 ) ||
F_211 ( V_215 , V_239 ) )
return - V_243 ;
V_100 = 0 ;
break;
case V_253 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_254 ? 1 : 0 ;
if ( F_211 ( V_9 , V_240 ) || F_211 ( V_215 , V_239 ) )
return - V_243 ;
V_100 = 0 ;
break;
default:
V_100 = - V_242 ;
}
return V_100 ;
}
static void F_213 ( struct V_259 * V_260 , struct V_6 * V_7 )
{
struct V_261 V_232 ;
V_232 . V_5 = F_7 ( V_7 ) . V_12 ;
F_214 ( V_260 , V_241 , V_244 , sizeof( V_232 ) , & V_232 ) ;
}
static void F_215 ( struct V_1 * V_2 , struct V_259 * V_260 ,
struct V_6 * V_7 )
{
if ( ! F_7 ( V_7 ) . V_227 )
return;
F_214 ( V_260 , V_241 , V_250 , sizeof( int ) ,
& F_7 ( V_7 ) . V_225 ) ;
}
static int F_216 ( struct V_112 * V_1 , struct V_259 * V_260 , T_6 V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_158 ( struct V_167 * , V_165 , V_260 -> V_262 ) ;
T_1 V_180 ;
T_1 V_12 ;
struct V_6 * V_7 ;
int V_100 ;
struct V_263 V_264 ;
T_1 V_265 = 0 ;
if ( V_260 -> V_266 & V_267 )
return - V_268 ;
V_100 = F_217 ( V_1 , V_260 , & V_264 , true ) ;
if ( V_100 < 0 )
return V_100 ;
if ( V_260 -> V_269 ) {
V_100 = - V_19 ;
if ( V_165 -> V_170 != V_171 )
goto V_26;
V_180 = V_165 -> V_174 ;
V_12 = F_156 ( V_165 -> V_169 ) ;
V_100 = - V_173 ;
if ( ( V_12 || V_180 ) &&
! F_146 ( V_1 , V_181 ) )
goto V_26;
V_265 |= V_153 ;
} else {
V_180 = V_51 -> V_180 ;
V_12 = V_51 -> V_12 ;
}
if ( ! V_51 -> V_102 ) {
V_100 = F_136 ( V_1 ) ;
if ( V_100 )
goto V_26;
} else {
F_153 () ;
}
V_100 = - V_270 ;
if ( V_9 > V_2 -> V_271 - 32 )
goto V_26;
V_100 = - V_56 ;
V_7 = F_166 ( V_9 , V_12 ) ;
if ( V_7 == NULL )
goto V_26;
F_7 ( V_7 ) . V_11 = V_51 -> V_11 ;
F_7 ( V_7 ) . V_12 = V_12 ;
F_7 ( V_7 ) . V_13 = V_264 . V_13 ;
F_7 ( V_7 ) . V_3 = V_265 ;
V_100 = - V_243 ;
if ( F_218 ( F_219 ( V_7 , V_9 ) , V_260 , V_9 ) ) {
F_57 ( V_7 ) ;
goto V_26;
}
V_100 = F_220 ( V_2 , V_7 ) ;
if ( V_100 ) {
F_57 ( V_7 ) ;
goto V_26;
}
if ( V_12 ) {
F_221 ( & V_7 -> V_272 ) ;
F_202 ( V_2 , V_7 , V_180 , V_12 , V_119 ) ;
}
V_100 = F_184 ( V_2 , V_7 , V_180 , V_260 -> V_266 & V_273 ) ;
V_26:
F_222 ( & V_264 ) ;
return V_100 ;
}
static int F_223 ( struct V_112 * V_1 , struct V_259 * V_260 , T_6 V_9 ,
int V_3 )
{
struct V_263 V_264 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_274 = V_3 & V_273 ;
T_6 V_275 ;
struct V_6 * V_7 , * V_276 ;
int V_100 , V_28 ;
if ( V_3 & V_267 )
return - V_268 ;
V_275 = 0 ;
V_7 = F_224 ( V_2 , V_3 , V_274 , & V_100 ) ;
if ( V_7 == NULL )
goto V_26;
V_276 = V_7 ;
#ifdef F_225
if ( F_10 ( F_49 ( V_7 ) -> V_277 ) ) {
if ( V_3 & V_278 )
V_276 = F_49 ( V_7 ) -> V_277 ;
}
#endif
V_51 -> V_279 = F_226 ( V_51 -> V_279 , V_9 ) ;
V_51 -> V_279 = F_227 ( T_6 , V_51 -> V_279 ,
F_228 ( 32768 ) ) ;
V_275 = V_276 -> V_9 ;
if ( V_9 < V_275 ) {
V_260 -> V_266 |= V_280 ;
V_275 = V_9 ;
}
F_229 ( V_276 ) ;
V_100 = F_230 ( V_276 , 0 , V_260 , V_275 ) ;
if ( V_260 -> V_262 ) {
F_158 ( struct V_167 * , V_165 , V_260 -> V_262 ) ;
V_165 -> V_170 = V_171 ;
V_165 -> V_184 = 0 ;
V_165 -> V_174 = F_7 ( V_7 ) . V_11 ;
V_165 -> V_169 = F_3 ( F_7 ( V_7 ) . V_12 ) ;
V_260 -> V_269 = sizeof( * V_165 ) ;
}
if ( V_51 -> V_3 & V_245 )
F_213 ( V_260 , V_7 ) ;
if ( V_51 -> V_3 & V_217 )
F_215 ( V_2 , V_260 , V_7 ) ;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
V_264 . V_13 = * F_231 ( V_7 ) ;
if ( V_3 & V_280 )
V_275 = V_276 -> V_9 ;
F_232 ( V_2 , V_7 ) ;
if ( V_51 -> V_66 &&
F_61 ( & V_2 -> V_65 ) <= V_2 -> V_199 / 2 ) {
V_28 = F_233 ( V_2 ) ;
if ( V_28 ) {
V_2 -> V_55 = - V_28 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_234 ( V_1 , V_260 , & V_264 , V_3 ) ;
V_26:
F_42 ( V_2 ) ;
return V_100 ? : V_275 ;
}
static void F_235 ( struct V_1 * V_2 )
{
F_236 () ;
}
struct V_1 *
F_237 ( struct V_87 * V_87 , int V_281 , struct V_23 * V_23 ,
struct V_282 * V_283 )
{
struct V_112 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_97 * V_97 = NULL ;
struct V_113 * V_114 = V_283 ? V_283 -> V_114 : NULL ;
unsigned int V_72 ;
F_131 ( ! V_93 ) ;
if ( V_281 < 0 || V_281 >= V_129 )
return NULL ;
if ( F_238 ( V_118 , V_127 , V_281 , & V_1 ) )
return NULL ;
if ( F_108 ( V_87 , V_1 , V_114 , V_281 , 1 ) < 0 )
goto V_284;
V_2 = V_1 -> V_2 ;
if ( ! V_283 || V_283 -> V_72 < 32 )
V_72 = 32 ;
else
V_72 = V_283 -> V_72 ;
V_97 = F_239 ( sizeof( * V_97 ) + F_151 ( V_72 ) , V_119 ) ;
if ( ! V_97 )
goto V_285;
V_2 -> V_202 = F_235 ;
if ( V_283 && V_283 -> V_286 )
F_2 ( V_2 ) -> V_210 = V_283 -> V_286 ;
if ( F_99 ( V_2 , 0 ) )
goto V_285;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_66 () ;
if ( ! V_93 [ V_281 ] . V_131 ) {
V_93 [ V_281 ] . V_72 = V_72 ;
F_240 ( V_93 [ V_281 ] . V_97 , V_97 ) ;
V_93 [ V_281 ] . V_114 = V_114 ;
V_93 [ V_281 ] . V_23 = V_23 ;
if ( V_283 ) {
V_93 [ V_281 ] . F_115 = V_283 -> F_115 ;
V_93 [ V_281 ] . F_116 = V_283 -> F_116 ;
V_93 [ V_281 ] . V_3 = V_283 -> V_3 ;
if ( V_283 -> V_287 )
V_93 [ V_281 ] . V_287 = V_283 -> V_287 ;
}
V_93 [ V_281 ] . V_131 = 1 ;
} else {
F_134 ( V_97 ) ;
V_93 [ V_281 ] . V_131 ++ ;
}
F_76 () ;
return V_2 ;
V_285:
F_134 ( V_97 ) ;
F_241 ( V_2 ) ;
return NULL ;
V_284:
F_242 ( V_1 ) ;
return NULL ;
}
void
F_241 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_154 == NULL )
return;
F_242 ( V_2 -> V_154 ) ;
}
int F_243 ( struct V_1 * V_2 , unsigned int V_72 )
{
struct V_97 * V_10 , * V_143 ;
struct V_88 * V_94 = & V_93 [ V_2 -> V_29 ] ;
if ( V_72 < 32 )
V_72 = 32 ;
if ( F_151 ( V_94 -> V_72 ) < F_151 ( V_72 ) ) {
V_10 = F_239 ( sizeof( * V_10 ) + F_151 ( V_72 ) , V_42 ) ;
if ( ! V_10 )
return - V_40 ;
V_143 = F_96 ( V_94 -> V_97 ) ;
memcpy ( V_10 -> V_99 , V_143 -> V_99 , F_151 ( V_94 -> V_72 ) ) ;
F_240 ( V_94 -> V_97 , V_10 ) ;
F_133 ( V_143 , V_136 ) ;
}
V_94 -> V_72 = V_72 ;
return 0 ;
}
int F_244 ( struct V_1 * V_2 , unsigned int V_72 )
{
int V_100 ;
F_66 () ;
V_100 = F_243 ( V_2 , V_72 ) ;
F_76 () ;
return V_100 ;
}
void F_245 ( struct V_1 * V_288 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_88 * V_94 = & V_93 [ V_288 -> V_29 ] ;
F_98 (sk, &tbl->mc_list)
F_205 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_289 *
F_246 ( struct V_6 * V_7 , T_1 V_11 , T_1 V_290 , int type , int V_9 , int V_3 )
{
struct V_289 * V_291 ;
int V_194 = F_247 ( V_9 ) ;
V_291 = F_219 ( V_7 , F_248 ( V_194 ) ) ;
V_291 -> V_292 = type ;
V_291 -> V_293 = V_194 ;
V_291 -> V_294 = V_3 ;
V_291 -> V_295 = V_11 ;
V_291 -> V_296 = V_290 ;
if ( ! F_249 ( V_194 ) || F_248 ( V_194 ) - V_194 != 0 )
memset ( F_250 ( V_291 ) + V_9 , 0 , F_248 ( V_194 ) - V_194 ) ;
return V_291 ;
}
static int F_233 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_297 * V_67 ;
struct V_6 * V_7 = NULL ;
struct V_289 * V_291 ;
struct V_23 * V_23 ;
int V_9 , V_100 = - V_56 ;
int V_298 ;
int V_299 ;
F_251 ( V_51 -> V_114 ) ;
if ( ! V_51 -> V_66 ) {
V_100 = - V_19 ;
goto V_300;
}
if ( F_61 ( & V_2 -> V_65 ) >= V_2 -> V_199 )
goto V_300;
V_67 = & V_51 -> V_67 ;
V_298 = F_252 ( int , V_67 -> V_301 , V_196 ) ;
if ( V_298 < V_51 -> V_279 ) {
V_299 = V_51 -> V_279 ;
V_7 = F_6 ( V_299 ,
( V_119 & ~ V_207 ) |
V_208 | V_209 ) ;
}
if ( ! V_7 ) {
V_299 = V_298 ;
V_7 = F_6 ( V_299 , V_119 ) ;
}
if ( ! V_7 )
goto V_300;
F_253 ( V_7 , F_254 ( V_7 ) - V_299 ) ;
F_52 ( V_7 , V_2 ) ;
V_9 = V_67 -> V_302 ( V_7 , V_67 ) ;
if ( V_9 > 0 ) {
F_255 ( V_51 -> V_114 ) ;
if ( F_189 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_175 ( V_2 , V_7 ) ;
return 0 ;
}
V_291 = F_256 ( V_7 , V_67 , V_303 , sizeof( V_9 ) , V_304 ) ;
if ( ! V_291 )
goto V_300;
F_257 ( V_67 , V_291 ) ;
memcpy ( F_250 ( V_291 ) , & V_9 , sizeof( V_9 ) ) ;
if ( F_189 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_175 ( V_2 , V_7 ) ;
if ( V_67 -> V_68 )
V_67 -> V_68 ( V_67 ) ;
V_51 -> V_66 = false ;
V_23 = V_67 -> V_23 ;
V_7 = V_67 -> V_7 ;
F_255 ( V_51 -> V_114 ) ;
F_19 ( V_23 ) ;
F_181 ( V_7 ) ;
return 0 ;
V_300:
F_255 ( V_51 -> V_114 ) ;
F_57 ( V_7 ) ;
return V_100 ;
}
int F_258 ( struct V_1 * V_187 , struct V_6 * V_7 ,
const struct V_289 * V_291 ,
struct V_305 * V_306 )
{
struct V_297 * V_67 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_28 ;
F_221 ( & V_7 -> V_272 ) ;
V_2 = F_93 ( F_85 ( V_187 ) , V_187 -> V_29 , F_7 ( V_7 ) . V_11 ) ;
if ( V_2 == NULL ) {
V_28 = - V_188 ;
goto V_307;
}
V_51 = F_2 ( V_2 ) ;
F_251 ( V_51 -> V_114 ) ;
if ( V_51 -> V_66 ) {
V_28 = - V_101 ;
goto V_308;
}
if ( ! F_119 ( V_306 -> V_23 ) ) {
V_28 = - V_130 ;
goto V_308;
}
V_67 = & V_51 -> V_67 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_309 = V_306 -> V_309 ;
V_67 -> V_302 = V_306 -> V_302 ;
V_67 -> V_68 = V_306 -> V_68 ;
V_67 -> V_291 = V_291 ;
V_67 -> V_14 = V_306 -> V_14 ;
V_67 -> V_23 = V_306 -> V_23 ;
V_67 -> V_301 = V_306 -> V_301 ;
V_67 -> V_7 = V_7 ;
V_51 -> V_66 = true ;
F_255 ( V_51 -> V_114 ) ;
if ( V_67 -> V_309 )
V_67 -> V_309 ( V_67 ) ;
V_28 = F_233 ( V_2 ) ;
F_101 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return - V_310 ;
V_308:
F_101 ( V_2 ) ;
F_255 ( V_51 -> V_114 ) ;
V_307:
F_57 ( V_7 ) ;
return V_28 ;
}
void F_259 ( struct V_6 * V_311 , struct V_289 * V_291 , int V_100 ,
const struct V_312 * V_313 )
{
struct V_6 * V_7 ;
struct V_289 * V_314 ;
struct V_315 * V_316 ;
T_6 V_317 = sizeof( * V_316 ) ;
T_6 V_318 = 0 ;
struct V_50 * V_51 = F_2 ( F_7 ( V_311 ) . V_2 ) ;
unsigned int V_3 = 0 ;
if ( V_100 ) {
if ( ! ( V_51 -> V_3 & V_252 ) )
V_317 += V_293 ( V_291 ) ;
else
V_3 |= V_319 ;
if ( V_51 -> V_3 & V_254 && V_313 ) {
if ( V_313 -> V_320 )
V_318 += F_260 ( strlen ( V_313 -> V_320 ) + 1 ) ;
if ( V_313 -> V_321 )
V_318 += F_260 ( sizeof( T_1 ) ) ;
}
} else {
V_3 |= V_319 ;
if ( V_51 -> V_3 & V_254 &&
V_313 && V_313 -> V_322 )
V_318 += F_260 ( V_313 -> V_322 ) ;
}
if ( V_318 )
V_3 |= V_323 ;
V_7 = F_261 ( V_317 + V_318 , V_119 ) ;
if ( ! V_7 ) {
struct V_1 * V_2 ;
V_2 = F_93 ( F_85 ( V_311 -> V_2 ) ,
V_311 -> V_2 -> V_29 ,
F_7 ( V_311 ) . V_11 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_101 ( V_2 ) ;
}
return;
}
V_314 = F_246 ( V_7 , F_7 ( V_311 ) . V_11 , V_291 -> V_296 ,
V_324 , V_317 , V_3 ) ;
V_316 = F_250 ( V_314 ) ;
V_316 -> error = V_100 ;
memcpy ( & V_316 -> V_260 , V_291 , V_317 > sizeof( * V_316 ) ? V_291 -> V_293 : sizeof( * V_291 ) ) ;
if ( V_51 -> V_3 & V_254 && V_313 ) {
if ( V_100 ) {
if ( V_313 -> V_320 )
F_53 ( F_262 ( V_7 , V_325 ,
V_313 -> V_320 ) ) ;
if ( V_313 -> V_321 &&
! F_53 ( ( V_326 * ) V_313 -> V_321 < V_311 -> V_14 ||
( V_326 * ) V_313 -> V_321 >= V_311 -> V_14 +
V_311 -> V_9 ) )
F_53 ( F_263 ( V_7 , V_327 ,
( V_326 * ) V_313 -> V_321 -
V_311 -> V_14 ) ) ;
} else {
if ( V_313 -> V_322 )
F_53 ( F_264 ( V_7 , V_328 ,
V_313 -> V_322 ,
V_313 -> V_329 ) ) ;
}
}
F_265 ( V_7 , V_314 ) ;
F_184 ( V_311 -> V_2 , V_7 , F_7 ( V_311 ) . V_11 , V_273 ) ;
}
int F_266 ( struct V_6 * V_7 , int (* V_67)( struct V_6 * ,
struct V_289 * ,
struct V_312 * ) )
{
struct V_312 V_313 = {} ;
struct V_289 * V_291 ;
int V_100 ;
while ( V_7 -> V_9 >= F_267 ( 0 ) ) {
int V_330 ;
V_291 = F_268 ( V_7 ) ;
V_100 = 0 ;
if ( V_291 -> V_293 < V_331 || V_7 -> V_9 < V_291 -> V_293 )
return 0 ;
if ( ! ( V_291 -> V_294 & V_332 ) )
goto V_333;
if ( V_291 -> V_292 < V_334 )
goto V_333;
V_100 = V_67 ( V_7 , V_291 , & V_313 ) ;
if ( V_100 == - V_310 )
goto V_335;
V_333:
if ( V_291 -> V_294 & V_336 || V_100 )
F_259 ( V_7 , V_291 , V_100 , & V_313 ) ;
V_335:
V_330 = F_248 ( V_291 -> V_293 ) ;
if ( V_330 > V_7 -> V_9 )
V_330 = V_7 -> V_9 ;
F_269 ( V_7 , V_330 ) ;
}
return 0 ;
}
int F_270 ( struct V_1 * V_2 , struct V_6 * V_7 , T_1 V_11 ,
unsigned int V_5 , int V_337 , T_2 V_3 )
{
int V_100 = 0 ;
if ( V_5 ) {
int V_338 = 0 ;
if ( V_337 ) {
F_221 ( & V_7 -> V_272 ) ;
V_338 = V_11 ;
}
V_100 = F_271 ( V_2 , V_7 , V_338 , V_5 , V_3 ) ;
}
if ( V_337 ) {
int V_339 ;
V_339 = F_272 ( V_2 , V_7 , V_11 ) ;
if ( ! V_100 || V_100 == - V_233 )
V_100 = V_339 ;
}
return V_100 ;
}
static int F_273 ( struct V_340 * V_341 )
{
int V_100 ;
V_100 = F_274 ( & V_93 [ V_341 -> V_342 ] . V_90 , & V_341 -> V_343 ,
V_119 ) ;
if ( V_100 ) {
V_341 -> V_342 = V_129 ;
return V_100 ;
}
V_100 = F_275 ( & V_341 -> V_343 ) ;
return V_100 == - V_200 ? 0 : V_100 ;
}
static void F_276 ( struct V_340 * V_341 )
{
F_277 ( & V_341 -> V_343 ) ;
F_278 ( & V_341 -> V_343 ) ;
}
static void * F_279 ( struct V_344 * V_290 )
{
struct V_340 * V_341 = V_290 -> V_345 ;
struct V_50 * V_51 ;
do {
for (; ; ) {
int V_100 ;
V_51 = F_280 ( & V_341 -> V_343 ) ;
if ( F_187 ( V_51 ) ) {
if ( F_188 ( V_51 ) == - V_200 )
continue;
return V_51 ;
}
if ( V_51 )
break;
F_276 ( V_341 ) ;
if ( ++ V_341 -> V_342 >= V_129 )
return NULL ;
V_100 = F_273 ( V_341 ) ;
if ( V_100 )
return F_161 ( V_100 ) ;
}
} while ( F_85 ( & V_51 -> V_2 ) != F_281 ( V_290 ) );
return V_51 ;
}
static void * F_282 ( struct V_344 * V_290 , T_7 * V_346 )
{
struct V_340 * V_341 = V_290 -> V_345 ;
void * V_347 = V_348 ;
T_7 V_256 ;
int V_100 ;
V_341 -> V_342 = 0 ;
V_100 = F_273 ( V_341 ) ;
if ( V_100 )
return F_161 ( V_100 ) ;
for ( V_256 = * V_346 ; V_256 && V_347 && ! F_187 ( V_347 ) ; V_256 -- )
V_347 = F_279 ( V_290 ) ;
return V_347 ;
}
static void * F_283 ( struct V_344 * V_290 , void * V_349 , T_7 * V_256 )
{
++ * V_256 ;
return F_279 ( V_290 ) ;
}
static void F_284 ( struct V_344 * V_290 , void * V_349 )
{
struct V_340 * V_341 = V_290 -> V_345 ;
if ( V_341 -> V_342 >= V_129 )
return;
F_276 ( V_341 ) ;
}
static int F_285 ( struct V_344 * V_290 , void * V_349 )
{
if ( V_349 == V_348 ) {
F_286 ( V_290 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_350 = V_349 ;
struct V_50 * V_51 = F_2 ( V_350 ) ;
F_287 ( V_290 , L_6 ,
V_350 ,
V_350 -> V_29 ,
V_51 -> V_11 ,
V_51 -> V_72 ? ( T_1 ) V_51 -> V_72 [ 0 ] : 0 ,
F_288 ( V_350 ) ,
F_289 ( V_350 ) ,
V_51 -> V_66 ,
F_62 ( & V_350 -> V_109 ) ,
F_61 ( & V_350 -> V_58 ) ,
F_290 ( V_350 )
) ;
}
return 0 ;
}
static int F_291 ( struct V_190 * V_190 , struct V_155 * V_155 )
{
return F_292 ( V_190 , V_155 , & V_351 ,
sizeof( struct V_340 ) ) ;
}
int F_293 ( struct V_352 * V_353 )
{
return F_294 ( & V_141 , V_353 ) ;
}
int F_295 ( struct V_352 * V_353 )
{
return F_296 ( & V_141 , V_353 ) ;
}
static int T_8 F_297 ( struct V_87 * V_87 )
{
#ifdef F_298
if ( ! F_299 ( L_7 , 0 , V_87 -> V_354 , & V_355 ) )
return - V_40 ;
#endif
return 0 ;
}
static void T_9 F_300 ( struct V_87 * V_87 )
{
#ifdef F_298
F_301 ( L_7 , V_87 -> V_354 ) ;
#endif
}
static void T_10 F_302 ( void )
{
struct V_97 * V_97 ;
int V_72 = 32 ;
V_97 = F_239 ( sizeof( * V_97 ) + F_151 ( V_72 ) , V_119 ) ;
if ( ! V_97 )
F_303 ( L_8 ) ;
F_66 () ;
V_93 [ V_31 ] . V_72 = V_72 ;
F_240 ( V_93 [ V_31 ] . V_97 , V_97 ) ;
V_93 [ V_31 ] . V_23 = V_356 ;
V_93 [ V_31 ] . V_131 = 1 ;
V_93 [ V_31 ] . V_3 = V_181 ;
F_76 () ;
}
static inline T_1 F_304 ( const void * V_14 , T_1 V_9 , T_1 V_357 )
{
const struct V_50 * V_51 = V_14 ;
struct V_83 V_81 ;
F_87 ( & V_81 , F_85 ( & V_51 -> V_2 ) , V_51 -> V_11 ) ;
return F_305 ( ( T_1 * ) & V_81 , V_358 / sizeof( T_1 ) , V_357 ) ;
}
static int T_10 F_306 ( void )
{
int V_96 ;
int V_100 = F_307 ( & V_120 , 0 ) ;
if ( V_100 != 0 )
goto V_26;
F_308 ( sizeof( struct V_148 ) > F_309 ( struct V_6 , V_67 ) ) ;
V_93 = F_310 ( V_129 , sizeof( * V_93 ) , V_119 ) ;
if ( ! V_93 )
goto F_303;
for ( V_96 = 0 ; V_96 < V_129 ; V_96 ++ ) {
if ( F_311 ( & V_93 [ V_96 ] . V_90 ,
& V_91 ) < 0 ) {
while ( -- V_96 > 0 )
F_312 ( & V_93 [ V_96 ] . V_90 ) ;
F_134 ( V_93 ) ;
goto F_303;
}
}
F_313 ( & V_22 ) ;
F_302 () ;
F_314 ( & V_359 ) ;
F_315 ( & V_360 ) ;
F_316 () ;
V_26:
return V_100 ;
F_303:
F_303 ( L_9 ) ;
}
