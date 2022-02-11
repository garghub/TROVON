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
F_111 ( V_51 -> V_114 ,
V_122 + V_43 ,
V_123 [ V_43 ] ) ;
}
F_112 ( & V_51 -> V_60 ) ;
V_2 -> V_124 = F_56 ;
V_2 -> V_29 = V_43 ;
return 0 ;
}
static int F_113 ( struct V_87 * V_87 , struct V_112 * V_1 , int V_43 ,
int V_115 )
{
struct V_23 * V_23 = NULL ;
struct V_113 * V_114 ;
struct V_50 * V_51 ;
int (* F_114)( struct V_87 * V_87 , int V_5 );
void (* F_115)( struct V_87 * V_87 , int V_5 );
int V_100 = 0 ;
V_1 -> V_54 = V_125 ;
if ( V_1 -> type != V_126 && V_1 -> type != V_127 )
return - V_128 ;
if ( V_43 < 0 || V_43 >= V_129 )
return - V_130 ;
F_77 () ;
#ifdef F_116
if ( ! V_93 [ V_43 ] . V_131 ) {
F_80 () ;
F_117 ( L_3 , V_118 , V_43 ) ;
F_77 () ;
}
#endif
if ( V_93 [ V_43 ] . V_131 &&
F_118 ( V_93 [ V_43 ] . V_23 ) )
V_23 = V_93 [ V_43 ] . V_23 ;
else
V_100 = - V_130 ;
V_114 = V_93 [ V_43 ] . V_114 ;
F_114 = V_93 [ V_43 ] . F_114 ;
F_115 = V_93 [ V_43 ] . F_115 ;
F_80 () ;
if ( V_100 < 0 )
goto V_26;
V_100 = F_107 ( V_87 , V_1 , V_114 , V_43 , V_115 ) ;
if ( V_100 < 0 )
goto V_132;
F_119 () ;
F_120 ( V_87 , & V_120 , 1 ) ;
F_121 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_23 = V_23 ;
V_51 -> V_133 = F_114 ;
V_51 -> V_134 = F_115 ;
V_26:
return V_100 ;
V_132:
F_19 ( V_23 ) ;
goto V_26;
}
static void F_122 ( struct V_135 * V_41 )
{
struct V_50 * V_51 = F_63 ( V_41 , struct V_50 , V_136 ) ;
struct V_1 * V_2 = & V_51 -> V_2 ;
if ( ! F_81 ( & V_2 -> V_109 ) )
return;
if ( V_51 -> V_66 && V_51 -> V_67 . V_68 ) {
F_123 ( & V_51 -> V_74 , F_62 ) ;
F_124 ( & V_51 -> V_74 ) ;
return;
}
F_64 ( V_2 ) ;
}
static int F_125 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_103 ( V_2 ) ;
F_126 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_134 ) {
int V_96 ;
for ( V_96 = 0 ; V_96 < V_51 -> V_98 ; V_96 ++ )
if ( F_45 ( V_96 , V_51 -> V_72 ) )
V_51 -> V_134 ( F_84 ( V_2 ) , V_96 + 1 ) ;
}
if ( V_2 -> V_29 == V_37 &&
F_48 ( & V_111 ) == 0 )
F_76 ( & V_137 ) ;
V_1 -> V_2 = NULL ;
F_127 ( & V_51 -> V_60 ) ;
F_58 ( & V_2 -> V_138 ) ;
if ( V_51 -> V_11 && V_51 -> V_102 ) {
struct V_139 V_140 = {
. V_87 = F_84 ( V_2 ) ,
. V_43 = V_2 -> V_29 ,
. V_11 = V_51 -> V_11 ,
} ;
F_128 ( & V_141 ,
V_142 , & V_140 ) ;
}
F_19 ( V_51 -> V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_65 () ;
F_129 ( V_93 [ V_2 -> V_29 ] . V_131 == 0 ) ;
if ( -- V_93 [ V_2 -> V_29 ] . V_131 == 0 ) {
struct V_97 * V_143 ;
V_143 = F_95 ( V_93 [ V_2 -> V_29 ] . V_97 ) ;
F_130 ( V_93 [ V_2 -> V_29 ] . V_97 , NULL ) ;
F_131 ( V_143 , V_136 ) ;
V_93 [ V_2 -> V_29 ] . V_23 = NULL ;
V_93 [ V_2 -> V_29 ] . F_114 = NULL ;
V_93 [ V_2 -> V_29 ] . F_115 = NULL ;
V_93 [ V_2 -> V_29 ] . V_3 = 0 ;
V_93 [ V_2 -> V_29 ] . V_131 = 0 ;
}
F_75 () ;
}
F_132 ( V_51 -> V_72 ) ;
V_51 -> V_72 = NULL ;
F_119 () ;
F_120 ( F_84 ( V_2 ) , & V_120 , - 1 ) ;
F_121 () ;
F_133 ( & V_51 -> V_136 , F_122 ) ;
return 0 ;
}
static int F_134 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_87 * V_87 = F_84 ( V_2 ) ;
struct V_88 * V_89 = & V_93 [ V_2 -> V_29 ] ;
T_4 V_11 = F_135 ( V_76 ) ;
int V_100 ;
T_4 V_144 = - 4096 ;
bool V_145 ;
V_146:
F_136 () ;
F_35 () ;
V_145 = ! F_88 ( V_89 , V_11 , V_87 ) ;
F_37 () ;
if ( ! V_145 ) {
if ( V_144 == - 4096 )
V_144 = V_147 + F_137 ( - 4096 - V_147 ) ;
else if ( V_144 >= - 4096 )
V_144 = - 4097 ;
V_11 = V_144 -- ;
goto V_146;
}
V_100 = F_98 ( V_2 , V_11 ) ;
if ( V_100 == - V_108 )
goto V_146;
if ( V_100 == - V_101 )
V_100 = 0 ;
return V_100 ;
}
bool F_138 ( const struct V_148 * V_149 ,
struct V_150 * V_151 , int V_152 )
{
return ( ( V_149 -> V_3 & V_153 ) ||
F_139 ( V_149 -> V_2 -> V_154 -> V_155 , V_151 , V_152 ) ) &&
F_140 ( V_151 , V_152 ) ;
}
bool F_141 ( const struct V_6 * V_7 ,
struct V_150 * V_151 , int V_152 )
{
return F_138 ( & F_7 ( V_7 ) , V_151 , V_152 ) ;
}
bool F_142 ( const struct V_6 * V_7 , int V_152 )
{
return F_141 ( V_7 , & V_156 , V_152 ) ;
}
bool F_143 ( const struct V_6 * V_7 , int V_152 )
{
return F_141 ( V_7 , F_84 ( V_7 -> V_2 ) -> V_151 , V_152 ) ;
}
static inline int F_144 ( const struct V_112 * V_1 , unsigned int V_157 )
{
return ( V_93 [ V_1 -> V_2 -> V_29 ] . V_3 & V_157 ) ||
F_140 ( F_84 ( V_1 -> V_2 ) -> V_151 , V_158 ) ;
}
static void
F_145 ( struct V_1 * V_2 , unsigned int V_110 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_110 && ! V_110 )
F_106 ( V_2 ) ;
else if ( ! V_51 -> V_110 && V_110 )
F_146 ( V_2 , & V_93 [ V_2 -> V_29 ] . V_159 ) ;
V_51 -> V_110 = V_110 ;
}
static int F_147 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_72 ;
unsigned long * V_160 ;
int V_100 = 0 ;
F_65 () ;
V_72 = V_93 [ V_2 -> V_29 ] . V_72 ;
if ( ! V_93 [ V_2 -> V_29 ] . V_131 ) {
V_100 = - V_161 ;
goto V_162;
}
if ( V_51 -> V_98 >= V_72 )
goto V_162;
V_160 = F_148 ( V_51 -> V_72 , F_149 ( V_72 ) , V_42 ) ;
if ( V_160 == NULL ) {
V_100 = - V_40 ;
goto V_162;
}
memset ( ( char * ) V_160 + F_149 ( V_51 -> V_98 ) , 0 ,
F_149 ( V_72 ) - F_149 ( V_51 -> V_98 ) ) ;
V_51 -> V_72 = V_160 ;
V_51 -> V_98 = V_72 ;
V_162:
F_75 () ;
return V_100 ;
}
static void F_150 ( int V_5 , long unsigned int V_72 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_163 ;
if ( ! V_51 -> V_134 )
return;
for ( V_163 = 0 ; V_163 < V_5 ; V_163 ++ )
if ( F_45 ( V_163 , & V_72 ) )
V_51 -> V_134 ( F_84 ( V_2 ) , V_163 + 1 ) ;
}
static int V_133 ( struct V_112 * V_1 , struct V_164 * V_165 ,
int V_166 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_87 * V_87 = F_84 ( V_2 ) ;
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
if ( ! F_144 ( V_1 , V_172 ) )
return - V_173 ;
V_100 = F_147 ( V_2 ) ;
if ( V_100 )
return V_100 ;
}
V_102 = V_51 -> V_102 ;
if ( V_102 ) {
F_151 () ;
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
F_150 ( V_5 , V_72 , V_2 ) ;
return V_100 ;
}
}
if ( ! V_102 ) {
V_100 = V_168 -> V_174 ?
F_98 ( V_2 , V_168 -> V_174 ) :
F_134 ( V_1 ) ;
if ( V_100 ) {
F_150 ( V_51 -> V_98 , V_72 , V_2 ) ;
return V_100 ;
}
}
if ( ! V_72 && ( V_51 -> V_72 == NULL || ! ( T_1 ) V_51 -> V_72 [ 0 ] ) )
return 0 ;
F_65 () ;
F_145 ( V_2 , V_51 -> V_110 +
F_152 ( V_72 ) -
F_152 ( V_51 -> V_72 [ 0 ] ) ) ;
V_51 -> V_72 [ 0 ] = ( V_51 -> V_72 [ 0 ] & ~ 0xffffffffUL ) | V_72 ;
F_94 ( V_2 ) ;
F_75 () ;
return 0 ;
}
static int F_153 ( struct V_112 * V_1 , struct V_164 * V_165 ,
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
! F_144 ( V_1 , V_181 ) )
return - V_173 ;
if ( ! V_51 -> V_102 )
V_100 = F_134 ( V_1 ) ;
if ( V_100 == 0 ) {
V_2 -> V_178 = V_182 ;
V_51 -> V_180 = V_168 -> V_174 ;
V_51 -> V_12 = F_154 ( V_168 -> V_169 ) ;
}
return V_100 ;
}
static int F_155 ( struct V_112 * V_1 , struct V_164 * V_165 ,
int * V_166 , int V_183 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_156 ( struct V_167 * , V_168 , V_165 ) ;
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
static int F_157 ( struct V_112 * V_1 , unsigned int V_185 ,
unsigned long V_81 )
{
return - V_186 ;
}
static struct V_1 * F_158 ( struct V_1 * V_187 , T_1 V_11 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_92 ( F_84 ( V_187 ) , V_187 -> V_29 , V_11 ) ;
if ( ! V_1 )
return F_159 ( - V_188 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_178 == V_182 &&
V_51 -> V_180 != F_2 ( V_187 ) -> V_11 ) {
F_100 ( V_1 ) ;
return F_159 ( - V_188 ) ;
}
return V_1 ;
}
struct V_1 * F_160 ( struct V_155 * V_189 )
{
struct V_190 * V_190 = F_161 ( V_189 ) ;
struct V_1 * V_1 ;
if ( ! F_162 ( V_190 -> V_191 ) )
return F_159 ( - V_192 ) ;
V_1 = F_163 ( V_190 ) -> V_2 ;
if ( V_1 -> V_193 != V_171 )
return F_159 ( - V_19 ) ;
F_93 ( V_1 ) ;
return V_1 ;
}
static struct V_6 * F_164 ( unsigned int V_194 ,
int V_195 )
{
struct V_6 * V_7 ;
void * V_14 ;
if ( V_194 <= V_196 || V_195 )
return F_6 ( V_194 , V_119 ) ;
V_194 = F_165 ( V_194 ) +
F_165 ( sizeof( struct V_197 ) ) ;
V_14 = F_166 ( V_194 ) ;
if ( V_14 == NULL )
return NULL ;
V_7 = F_167 ( V_14 , V_194 ) ;
if ( V_7 == NULL )
F_50 ( V_14 ) ;
else
V_7 -> V_63 = F_47 ;
return V_7 ;
}
int F_168 ( struct V_1 * V_2 , struct V_6 * V_7 ,
long * V_198 , struct V_1 * V_187 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_199 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) ) {
F_68 ( V_60 , V_76 ) ;
if ( ! * V_198 ) {
if ( ! V_187 || F_1 ( V_187 ) )
F_39 ( V_2 ) ;
F_100 ( V_2 ) ;
F_57 ( V_7 ) ;
return - V_200 ;
}
F_73 ( V_201 ) ;
F_169 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_61 ( & V_2 -> V_65 ) > V_2 -> V_199 ||
F_45 ( V_53 , & V_51 -> V_54 ) ) &&
! F_59 ( V_2 , V_69 ) )
* V_198 = F_170 ( * V_198 ) ;
F_73 ( V_79 ) ;
F_74 ( & V_51 -> V_60 , & V_60 ) ;
F_100 ( V_2 ) ;
if ( F_171 ( V_76 ) ) {
F_57 ( V_7 ) ;
return F_172 ( * V_198 ) ;
}
return 1 ;
}
F_52 ( V_7 , V_2 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = V_7 -> V_9 ;
F_34 ( V_7 ) ;
F_174 ( & V_2 -> V_59 , V_7 ) ;
V_2 -> V_202 ( V_2 ) ;
return V_9 ;
}
int F_175 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_9 = F_173 ( V_2 , V_7 ) ;
F_100 ( V_2 ) ;
return V_9 ;
}
void F_176 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_57 ( V_7 ) ;
F_100 ( V_2 ) ;
}
static struct V_6 * F_177 ( struct V_6 * V_7 , T_2 V_203 )
{
int V_204 ;
F_53 ( V_7 -> V_2 != NULL ) ;
V_204 = V_7 -> V_205 - V_7 -> V_206 ;
if ( F_25 ( V_7 -> V_41 ) || V_204 * 2 < V_7 -> V_64 )
return V_7 ;
if ( F_178 ( V_7 ) ) {
struct V_6 * V_39 = F_26 ( V_7 , V_203 ) ;
if ( ! V_39 )
return V_7 ;
F_179 ( V_7 ) ;
V_7 = V_39 ;
}
F_180 ( V_7 , 0 , - V_204 ,
( V_203 & ~ V_207 ) |
V_208 | V_209 ) ;
return V_7 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_6 * V_7 ,
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
F_179 ( V_7 ) ;
} else {
F_57 ( V_7 ) ;
}
F_100 ( V_2 ) ;
return V_28 ;
}
int F_182 ( struct V_1 * V_187 , struct V_6 * V_7 ,
T_1 V_11 , int V_211 )
{
struct V_1 * V_2 ;
int V_100 ;
long V_198 ;
V_7 = F_177 ( V_7 , F_183 () ) ;
V_198 = F_184 ( V_187 , V_211 ) ;
V_146:
V_2 = F_158 ( V_187 , V_11 ) ;
if ( F_185 ( V_2 ) ) {
F_57 ( V_7 ) ;
return F_186 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_181 ( V_2 , V_7 , V_187 ) ;
if ( F_187 ( V_2 , V_7 ) ) {
V_100 = V_7 -> V_9 ;
F_57 ( V_7 ) ;
F_100 ( V_2 ) ;
return V_100 ;
}
V_100 = F_168 ( V_2 , V_7 , & V_198 , V_187 ) ;
if ( V_100 == 1 )
goto V_146;
if ( V_100 )
return V_100 ;
return F_175 ( V_2 , V_7 ) ;
}
int F_188 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_212 = 0 ;
struct V_97 * V_97 ;
F_129 ( ! F_1 ( V_2 ) ) ;
F_35 () ;
V_97 = F_189 ( V_93 [ V_2 -> V_29 ] . V_97 ) ;
if ( V_97 && V_5 - 1 < V_93 [ V_2 -> V_29 ] . V_72 )
V_212 = F_45 ( V_5 - 1 , V_97 -> V_99 ) ;
F_37 () ;
return V_212 ;
}
static int F_190 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_61 ( & V_2 -> V_65 ) <= V_2 -> V_199 &&
! F_45 ( V_53 , & V_51 -> V_54 ) ) {
F_52 ( V_7 , V_2 ) ;
F_173 ( V_2 , V_7 ) ;
return F_61 ( & V_2 -> V_65 ) > ( V_2 -> V_199 >> 1 ) ;
}
return - 1 ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_213 * V_214 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_215 ;
if ( V_214 -> V_216 == V_2 )
return;
if ( V_51 -> V_11 == V_214 -> V_11 || V_214 -> V_5 - 1 >= V_51 -> V_98 ||
! F_45 ( V_214 -> V_5 - 1 , V_51 -> V_72 ) )
return;
if ( ! F_83 ( F_84 ( V_2 ) , V_214 -> V_87 ) ) {
if ( ! ( V_51 -> V_3 & V_217 ) )
return;
if ( ! F_192 ( F_84 ( V_2 ) , V_214 -> V_87 ) )
return;
if ( ! F_139 ( V_2 -> V_154 -> V_155 , V_214 -> V_87 -> V_151 ,
V_218 ) )
return;
}
if ( V_214 -> V_219 ) {
F_39 ( V_2 ) ;
return;
}
F_93 ( V_2 ) ;
if ( V_214 -> V_220 == NULL ) {
if ( F_178 ( V_214 -> V_7 ) ) {
V_214 -> V_220 = F_26 ( V_214 -> V_7 , V_214 -> V_203 ) ;
} else {
V_214 -> V_220 = F_193 ( V_214 -> V_7 ) ;
F_194 ( V_214 -> V_220 ) ;
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
if ( F_187 ( V_2 , V_214 -> V_220 ) ) {
F_57 ( V_214 -> V_220 ) ;
V_214 -> V_220 = NULL ;
goto V_26;
}
F_7 ( V_214 -> V_220 ) . V_225 = F_195 ( F_84 ( V_2 ) , V_214 -> V_87 ) ;
F_7 ( V_214 -> V_220 ) . V_226 = true ;
V_215 = F_190 ( V_2 , V_214 -> V_220 ) ;
if ( V_215 < 0 ) {
F_39 ( V_2 ) ;
if ( V_51 -> V_3 & V_221 )
V_214 -> V_222 = 1 ;
} else {
V_214 -> V_227 |= V_215 ;
V_214 -> V_228 = 1 ;
V_214 -> V_220 = NULL ;
}
V_26:
F_100 ( V_2 ) ;
}
int F_196 ( struct V_1 * V_187 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_203 ,
int (* F_197)( struct V_1 * V_229 , struct V_6 * V_7 , void * V_14 ) ,
void * V_230 )
{
struct V_87 * V_87 = F_84 ( V_187 ) ;
struct V_213 V_231 ;
struct V_1 * V_2 ;
V_7 = F_177 ( V_7 , V_203 ) ;
V_231 . V_216 = V_187 ;
V_231 . V_87 = V_87 ;
V_231 . V_11 = V_11 ;
V_231 . V_5 = V_5 ;
V_231 . V_219 = 0 ;
V_231 . V_222 = 0 ;
V_231 . V_227 = 0 ;
V_231 . V_228 = 0 ;
V_231 . V_203 = V_203 ;
V_231 . V_7 = V_7 ;
V_231 . V_220 = NULL ;
V_231 . V_223 = F_197 ;
V_231 . V_224 = V_230 ;
F_77 () ;
F_97 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_191 ( V_2 , & V_231 ) ;
F_179 ( V_7 ) ;
F_80 () ;
if ( V_231 . V_222 ) {
F_57 ( V_231 . V_220 ) ;
return - V_56 ;
}
F_179 ( V_231 . V_220 ) ;
if ( V_231 . V_228 ) {
if ( V_231 . V_227 && F_198 ( V_203 ) )
F_199 () ;
return 0 ;
}
return - V_232 ;
}
int F_200 ( struct V_1 * V_187 , struct V_6 * V_7 , T_1 V_11 ,
T_1 V_5 , T_2 V_203 )
{
return F_196 ( V_187 , V_7 , V_11 , V_5 , V_203 ,
NULL , NULL ) ;
}
static int F_201 ( struct V_1 * V_2 , struct V_233 * V_214 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_28 = 0 ;
if ( V_2 == V_214 -> V_216 )
goto V_26;
if ( ! F_83 ( F_84 ( V_2 ) , F_84 ( V_214 -> V_216 ) ) )
goto V_26;
if ( V_51 -> V_11 == V_214 -> V_11 || V_214 -> V_5 - 1 >= V_51 -> V_98 ||
! F_45 ( V_214 -> V_5 - 1 , V_51 -> V_72 ) )
goto V_26;
if ( V_214 -> V_234 == V_56 && V_51 -> V_3 & V_52 ) {
V_28 = 1 ;
goto V_26;
}
V_2 -> V_55 = V_214 -> V_234 ;
V_2 -> V_57 ( V_2 ) ;
V_26:
return V_28 ;
}
int F_202 ( struct V_1 * V_187 , T_1 V_11 , T_1 V_5 , int V_234 )
{
struct V_233 V_231 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
V_231 . V_216 = V_187 ;
V_231 . V_11 = V_11 ;
V_231 . V_5 = V_5 ;
V_231 . V_234 = - V_234 ;
F_78 ( & T_3 ) ;
F_97 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_28 += F_201 ( V_2 , & V_231 ) ;
F_79 ( & T_3 ) ;
return V_28 ;
}
static void F_203 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_235 )
{
int V_143 , V_10 = ! ! V_235 , V_110 ;
V_143 = F_45 ( V_5 - 1 , V_51 -> V_72 ) ;
V_110 = V_51 -> V_110 - V_143 + V_10 ;
if ( V_10 )
F_204 ( V_5 - 1 , V_51 -> V_72 ) ;
else
F_205 ( V_5 - 1 , V_51 -> V_72 ) ;
F_145 ( & V_51 -> V_2 , V_110 ) ;
F_94 ( & V_51 -> V_2 ) ;
}
static int F_206 ( struct V_112 * V_1 , int V_236 , int V_237 ,
char T_5 * V_238 , unsigned int V_239 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_215 = 0 ;
int V_100 ;
if ( V_236 != V_240 )
return - V_241 ;
if ( V_239 >= sizeof( int ) &&
F_207 ( V_215 , ( unsigned int T_5 * ) V_238 ) )
return - V_242 ;
switch ( V_237 ) {
case V_243 :
if ( V_215 )
V_51 -> V_3 |= V_244 ;
else
V_51 -> V_3 &= ~ V_244 ;
V_100 = 0 ;
break;
case V_245 :
case V_246 : {
if ( ! F_144 ( V_1 , V_172 ) )
return - V_173 ;
V_100 = F_147 ( V_2 ) ;
if ( V_100 )
return V_100 ;
if ( ! V_215 || V_215 - 1 >= V_51 -> V_98 )
return - V_19 ;
if ( V_237 == V_245 && V_51 -> V_133 ) {
V_100 = V_51 -> V_133 ( F_84 ( V_2 ) , V_215 ) ;
if ( V_100 )
return V_100 ;
}
F_65 () ;
F_203 ( V_51 , V_215 ,
V_237 == V_245 ) ;
F_75 () ;
if ( V_237 == V_246 && V_51 -> V_134 )
V_51 -> V_134 ( F_84 ( V_2 ) , V_215 ) ;
V_100 = 0 ;
break;
}
case V_247 :
if ( V_215 )
V_51 -> V_3 |= V_221 ;
else
V_51 -> V_3 &= ~ V_221 ;
V_100 = 0 ;
break;
case V_248 :
if ( V_215 ) {
V_51 -> V_3 |= V_52 ;
F_44 ( V_53 , & V_51 -> V_54 ) ;
F_46 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_100 = 0 ;
break;
case V_249 :
if ( ! F_140 ( F_84 ( V_2 ) -> V_151 , V_218 ) )
return - V_173 ;
if ( V_215 )
V_51 -> V_3 |= V_217 ;
else
V_51 -> V_3 &= ~ V_217 ;
V_100 = 0 ;
break;
case V_250 :
if ( V_215 )
V_51 -> V_3 |= V_251 ;
else
V_51 -> V_3 &= ~ V_251 ;
V_100 = 0 ;
break;
default:
V_100 = - V_241 ;
}
return V_100 ;
}
static int F_208 ( struct V_112 * V_1 , int V_236 , int V_237 ,
char T_5 * V_238 , int T_5 * V_239 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_9 , V_215 , V_100 ;
if ( V_236 != V_240 )
return - V_241 ;
if ( F_207 ( V_9 , V_239 ) )
return - V_242 ;
if ( V_9 < 0 )
return - V_19 ;
switch ( V_237 ) {
case V_243 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_244 ? 1 : 0 ;
if ( F_209 ( V_9 , V_239 ) ||
F_209 ( V_215 , V_238 ) )
return - V_242 ;
V_100 = 0 ;
break;
case V_247 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_221 ? 1 : 0 ;
if ( F_209 ( V_9 , V_239 ) ||
F_209 ( V_215 , V_238 ) )
return - V_242 ;
V_100 = 0 ;
break;
case V_248 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_209 ( V_9 , V_239 ) ||
F_209 ( V_215 , V_238 ) )
return - V_242 ;
V_100 = 0 ;
break;
case V_252 : {
int V_253 , V_254 , V_255 ;
V_100 = 0 ;
F_77 () ;
for ( V_253 = 0 ; V_253 * 8 < V_51 -> V_98 ; V_253 += sizeof( T_1 ) ) {
if ( V_9 - V_253 < sizeof( T_1 ) )
break;
V_254 = V_253 / sizeof( unsigned long ) ;
V_255 = ( V_253 % sizeof( unsigned long ) ) * 8 ;
if ( F_209 ( ( T_1 ) ( V_51 -> V_72 [ V_254 ] >> V_255 ) ,
( T_1 T_5 * ) ( V_238 + V_253 ) ) ) {
V_100 = - V_242 ;
break;
}
}
if ( F_209 ( F_210 ( V_51 -> V_98 / 8 , sizeof( T_1 ) ) , V_239 ) )
V_100 = - V_242 ;
F_80 () ;
break;
}
case V_250 :
if ( V_9 < sizeof( int ) )
return - V_19 ;
V_9 = sizeof( int ) ;
V_215 = V_51 -> V_3 & V_251 ? 1 : 0 ;
if ( F_209 ( V_9 , V_239 ) ||
F_209 ( V_215 , V_238 ) )
return - V_242 ;
V_100 = 0 ;
break;
default:
V_100 = - V_241 ;
}
return V_100 ;
}
static void F_211 ( struct V_256 * V_257 , struct V_6 * V_7 )
{
struct V_258 V_231 ;
V_231 . V_5 = F_7 ( V_7 ) . V_12 ;
F_212 ( V_257 , V_240 , V_243 , sizeof( V_231 ) , & V_231 ) ;
}
static void F_213 ( struct V_1 * V_2 , struct V_256 * V_257 ,
struct V_6 * V_7 )
{
if ( ! F_7 ( V_7 ) . V_226 )
return;
F_212 ( V_257 , V_240 , V_249 , sizeof( int ) ,
& F_7 ( V_7 ) . V_225 ) ;
}
static int F_214 ( struct V_112 * V_1 , struct V_256 * V_257 , T_6 V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_156 ( struct V_167 * , V_165 , V_257 -> V_259 ) ;
T_1 V_180 ;
T_1 V_12 ;
struct V_6 * V_7 ;
int V_100 ;
struct V_260 V_261 ;
T_1 V_262 = 0 ;
if ( V_257 -> V_263 & V_264 )
return - V_265 ;
V_100 = F_215 ( V_1 , V_257 , & V_261 , true ) ;
if ( V_100 < 0 )
return V_100 ;
if ( V_257 -> V_266 ) {
V_100 = - V_19 ;
if ( V_165 -> V_170 != V_171 )
goto V_26;
V_180 = V_165 -> V_174 ;
V_12 = F_154 ( V_165 -> V_169 ) ;
V_100 = - V_173 ;
if ( ( V_12 || V_180 ) &&
! F_144 ( V_1 , V_181 ) )
goto V_26;
V_262 |= V_153 ;
} else {
V_180 = V_51 -> V_180 ;
V_12 = V_51 -> V_12 ;
}
if ( ! V_51 -> V_102 ) {
V_100 = F_134 ( V_1 ) ;
if ( V_100 )
goto V_26;
} else {
F_151 () ;
}
V_100 = - V_267 ;
if ( V_9 > V_2 -> V_268 - 32 )
goto V_26;
V_100 = - V_56 ;
V_7 = F_164 ( V_9 , V_12 ) ;
if ( V_7 == NULL )
goto V_26;
F_7 ( V_7 ) . V_11 = V_51 -> V_11 ;
F_7 ( V_7 ) . V_12 = V_12 ;
F_7 ( V_7 ) . V_13 = V_261 . V_13 ;
F_7 ( V_7 ) . V_3 = V_262 ;
V_100 = - V_242 ;
if ( F_216 ( F_8 ( V_7 , V_9 ) , V_257 , V_9 ) ) {
F_57 ( V_7 ) ;
goto V_26;
}
V_100 = F_217 ( V_2 , V_7 ) ;
if ( V_100 ) {
F_57 ( V_7 ) ;
goto V_26;
}
if ( V_12 ) {
F_41 ( & V_7 -> V_269 ) ;
F_200 ( V_2 , V_7 , V_180 , V_12 , V_119 ) ;
}
V_100 = F_182 ( V_2 , V_7 , V_180 , V_257 -> V_263 & V_270 ) ;
V_26:
F_218 ( & V_261 ) ;
return V_100 ;
}
static int F_219 ( struct V_112 * V_1 , struct V_256 * V_257 , T_6 V_9 ,
int V_3 )
{
struct V_260 V_261 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_271 = V_3 & V_270 ;
T_6 V_272 ;
struct V_6 * V_7 , * V_273 ;
int V_100 , V_28 ;
if ( V_3 & V_264 )
return - V_265 ;
V_272 = 0 ;
V_7 = F_220 ( V_2 , V_3 , V_271 , & V_100 ) ;
if ( V_7 == NULL )
goto V_26;
V_273 = V_7 ;
#ifdef F_221
if ( F_10 ( F_49 ( V_7 ) -> V_274 ) ) {
if ( V_3 & V_275 )
V_273 = F_49 ( V_7 ) -> V_274 ;
}
#endif
V_51 -> V_276 = F_222 ( V_51 -> V_276 , V_9 ) ;
V_51 -> V_276 = F_223 ( T_6 , V_51 -> V_276 ,
F_224 ( 32768 ) ) ;
V_272 = V_273 -> V_9 ;
if ( V_9 < V_272 ) {
V_257 -> V_263 |= V_277 ;
V_272 = V_9 ;
}
F_225 ( V_273 ) ;
V_100 = F_226 ( V_273 , 0 , V_257 , V_272 ) ;
if ( V_257 -> V_259 ) {
F_156 ( struct V_167 * , V_165 , V_257 -> V_259 ) ;
V_165 -> V_170 = V_171 ;
V_165 -> V_184 = 0 ;
V_165 -> V_174 = F_7 ( V_7 ) . V_11 ;
V_165 -> V_169 = F_3 ( F_7 ( V_7 ) . V_12 ) ;
V_257 -> V_266 = sizeof( * V_165 ) ;
}
if ( V_51 -> V_3 & V_244 )
F_211 ( V_257 , V_7 ) ;
if ( V_51 -> V_3 & V_217 )
F_213 ( V_2 , V_257 , V_7 ) ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_13 = * F_227 ( V_7 ) ;
if ( V_3 & V_277 )
V_272 = V_273 -> V_9 ;
F_228 ( V_2 , V_7 ) ;
if ( V_51 -> V_66 &&
F_61 ( & V_2 -> V_65 ) <= V_2 -> V_199 / 2 ) {
V_28 = F_229 ( V_2 ) ;
if ( V_28 ) {
V_2 -> V_55 = - V_28 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_230 ( V_1 , V_257 , & V_261 , V_3 ) ;
V_26:
F_42 ( V_2 ) ;
return V_100 ? : V_272 ;
}
static void F_231 ( struct V_1 * V_2 )
{
F_232 () ;
}
struct V_1 *
F_233 ( struct V_87 * V_87 , int V_278 , struct V_23 * V_23 ,
struct V_279 * V_280 )
{
struct V_112 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_97 * V_97 = NULL ;
struct V_113 * V_114 = V_280 ? V_280 -> V_114 : NULL ;
unsigned int V_72 ;
F_129 ( ! V_93 ) ;
if ( V_278 < 0 || V_278 >= V_129 )
return NULL ;
if ( F_234 ( V_118 , V_127 , V_278 , & V_1 ) )
return NULL ;
if ( F_107 ( V_87 , V_1 , V_114 , V_278 , 1 ) < 0 )
goto V_281;
V_2 = V_1 -> V_2 ;
if ( ! V_280 || V_280 -> V_72 < 32 )
V_72 = 32 ;
else
V_72 = V_280 -> V_72 ;
V_97 = F_235 ( sizeof( * V_97 ) + F_149 ( V_72 ) , V_119 ) ;
if ( ! V_97 )
goto V_282;
V_2 -> V_202 = F_231 ;
if ( V_280 && V_280 -> V_283 )
F_2 ( V_2 ) -> V_210 = V_280 -> V_283 ;
if ( F_98 ( V_2 , 0 ) )
goto V_282;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_65 () ;
if ( ! V_93 [ V_278 ] . V_131 ) {
V_93 [ V_278 ] . V_72 = V_72 ;
F_236 ( V_93 [ V_278 ] . V_97 , V_97 ) ;
V_93 [ V_278 ] . V_114 = V_114 ;
V_93 [ V_278 ] . V_23 = V_23 ;
if ( V_280 ) {
V_93 [ V_278 ] . F_114 = V_280 -> F_114 ;
V_93 [ V_278 ] . F_115 = V_280 -> F_115 ;
V_93 [ V_278 ] . V_3 = V_280 -> V_3 ;
if ( V_280 -> V_284 )
V_93 [ V_278 ] . V_284 = V_280 -> V_284 ;
}
V_93 [ V_278 ] . V_131 = 1 ;
} else {
F_132 ( V_97 ) ;
V_93 [ V_278 ] . V_131 ++ ;
}
F_75 () ;
return V_2 ;
V_282:
F_132 ( V_97 ) ;
F_237 ( V_2 ) ;
return NULL ;
V_281:
F_238 ( V_1 ) ;
return NULL ;
}
void
F_237 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_154 == NULL )
return;
F_238 ( V_2 -> V_154 ) ;
}
int F_239 ( struct V_1 * V_2 , unsigned int V_72 )
{
struct V_97 * V_10 , * V_143 ;
struct V_88 * V_94 = & V_93 [ V_2 -> V_29 ] ;
if ( V_72 < 32 )
V_72 = 32 ;
if ( F_149 ( V_94 -> V_72 ) < F_149 ( V_72 ) ) {
V_10 = F_235 ( sizeof( * V_10 ) + F_149 ( V_72 ) , V_42 ) ;
if ( ! V_10 )
return - V_40 ;
V_143 = F_95 ( V_94 -> V_97 ) ;
memcpy ( V_10 -> V_99 , V_143 -> V_99 , F_149 ( V_94 -> V_72 ) ) ;
F_236 ( V_94 -> V_97 , V_10 ) ;
F_131 ( V_143 , V_136 ) ;
}
V_94 -> V_72 = V_72 ;
return 0 ;
}
int F_240 ( struct V_1 * V_2 , unsigned int V_72 )
{
int V_100 ;
F_65 () ;
V_100 = F_239 ( V_2 , V_72 ) ;
F_75 () ;
return V_100 ;
}
void F_241 ( struct V_1 * V_285 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_88 * V_94 = & V_93 [ V_285 -> V_29 ] ;
F_97 (sk, &tbl->mc_list)
F_203 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_286 *
F_242 ( struct V_6 * V_7 , T_1 V_11 , T_1 V_287 , int type , int V_9 , int V_3 )
{
struct V_286 * V_288 ;
int V_194 = F_243 ( V_9 ) ;
V_288 = (struct V_286 * ) F_8 ( V_7 , F_244 ( V_194 ) ) ;
V_288 -> V_289 = type ;
V_288 -> V_290 = V_194 ;
V_288 -> V_291 = V_3 ;
V_288 -> V_292 = V_11 ;
V_288 -> V_293 = V_287 ;
if ( ! F_245 ( V_194 ) || F_244 ( V_194 ) - V_194 != 0 )
memset ( F_246 ( V_288 ) + V_9 , 0 , F_244 ( V_194 ) - V_194 ) ;
return V_288 ;
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_294 * V_67 ;
struct V_6 * V_7 = NULL ;
struct V_286 * V_288 ;
struct V_23 * V_23 ;
int V_9 , V_100 = - V_56 ;
int V_295 ;
int V_296 ;
F_247 ( V_51 -> V_114 ) ;
if ( ! V_51 -> V_66 ) {
V_100 = - V_19 ;
goto V_297;
}
if ( F_61 ( & V_2 -> V_65 ) >= V_2 -> V_199 )
goto V_297;
V_67 = & V_51 -> V_67 ;
V_295 = F_248 ( int , V_67 -> V_298 , V_196 ) ;
if ( V_295 < V_51 -> V_276 ) {
V_296 = V_51 -> V_276 ;
V_7 = F_6 ( V_296 ,
( V_119 & ~ V_207 ) |
V_208 | V_209 ) ;
}
if ( ! V_7 ) {
V_296 = V_295 ;
V_7 = F_6 ( V_296 , V_119 ) ;
}
if ( ! V_7 )
goto V_297;
F_249 ( V_7 , F_250 ( V_7 ) - V_296 ) ;
F_52 ( V_7 , V_2 ) ;
V_9 = V_67 -> V_299 ( V_7 , V_67 ) ;
if ( V_9 > 0 ) {
F_251 ( V_51 -> V_114 ) ;
if ( F_187 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_173 ( V_2 , V_7 ) ;
return 0 ;
}
V_288 = F_252 ( V_7 , V_67 , V_300 , sizeof( V_9 ) , V_301 ) ;
if ( ! V_288 )
goto V_297;
F_253 ( V_67 , V_288 ) ;
memcpy ( F_246 ( V_288 ) , & V_9 , sizeof( V_9 ) ) ;
if ( F_187 ( V_2 , V_7 ) )
F_57 ( V_7 ) ;
else
F_173 ( V_2 , V_7 ) ;
if ( V_67 -> V_68 )
V_67 -> V_68 ( V_67 ) ;
V_51 -> V_66 = false ;
V_23 = V_67 -> V_23 ;
V_7 = V_67 -> V_7 ;
F_251 ( V_51 -> V_114 ) ;
F_19 ( V_23 ) ;
F_179 ( V_7 ) ;
return 0 ;
V_297:
F_251 ( V_51 -> V_114 ) ;
F_57 ( V_7 ) ;
return V_100 ;
}
int F_254 ( struct V_1 * V_187 , struct V_6 * V_7 ,
const struct V_286 * V_288 ,
struct V_302 * V_303 )
{
struct V_294 * V_67 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_28 ;
F_41 ( & V_7 -> V_269 ) ;
V_2 = F_92 ( F_84 ( V_187 ) , V_187 -> V_29 , F_7 ( V_7 ) . V_11 ) ;
if ( V_2 == NULL ) {
V_28 = - V_188 ;
goto V_304;
}
V_51 = F_2 ( V_2 ) ;
F_247 ( V_51 -> V_114 ) ;
if ( V_51 -> V_66 ) {
V_28 = - V_101 ;
goto V_305;
}
if ( ! F_118 ( V_303 -> V_23 ) ) {
V_28 = - V_130 ;
goto V_305;
}
V_67 = & V_51 -> V_67 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_306 = V_303 -> V_306 ;
V_67 -> V_299 = V_303 -> V_299 ;
V_67 -> V_68 = V_303 -> V_68 ;
V_67 -> V_288 = V_288 ;
V_67 -> V_14 = V_303 -> V_14 ;
V_67 -> V_23 = V_303 -> V_23 ;
V_67 -> V_298 = V_303 -> V_298 ;
V_67 -> V_7 = V_7 ;
V_51 -> V_66 = true ;
F_251 ( V_51 -> V_114 ) ;
if ( V_67 -> V_306 )
V_67 -> V_306 ( V_67 ) ;
V_28 = F_229 ( V_2 ) ;
F_100 ( V_2 ) ;
if ( V_28 )
return V_28 ;
return - V_307 ;
V_305:
F_100 ( V_2 ) ;
F_251 ( V_51 -> V_114 ) ;
V_304:
F_57 ( V_7 ) ;
return V_28 ;
}
void F_255 ( struct V_6 * V_308 , struct V_286 * V_288 , int V_100 )
{
struct V_6 * V_7 ;
struct V_286 * V_309 ;
struct V_310 * V_311 ;
T_6 V_312 = sizeof( * V_311 ) ;
struct V_50 * V_51 = F_2 ( F_7 ( V_308 ) . V_2 ) ;
if ( ! ( V_51 -> V_3 & V_251 ) && V_100 )
V_312 += V_290 ( V_288 ) ;
V_7 = F_256 ( V_312 , V_119 ) ;
if ( ! V_7 ) {
struct V_1 * V_2 ;
V_2 = F_92 ( F_84 ( V_308 -> V_2 ) ,
V_308 -> V_2 -> V_29 ,
F_7 ( V_308 ) . V_11 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_100 ( V_2 ) ;
}
return;
}
V_309 = F_242 ( V_7 , F_7 ( V_308 ) . V_11 , V_288 -> V_293 ,
V_313 , V_312 , 0 ) ;
V_311 = F_246 ( V_309 ) ;
V_311 -> error = V_100 ;
memcpy ( & V_311 -> V_257 , V_288 , V_312 > sizeof( * V_311 ) ? V_288 -> V_290 : sizeof( * V_288 ) ) ;
F_182 ( V_308 -> V_2 , V_7 , F_7 ( V_308 ) . V_11 , V_270 ) ;
}
int F_257 ( struct V_6 * V_7 , int (* V_67)( struct V_6 * ,
struct V_286 * ) )
{
struct V_286 * V_288 ;
int V_100 ;
while ( V_7 -> V_9 >= F_258 ( 0 ) ) {
int V_314 ;
V_288 = F_259 ( V_7 ) ;
V_100 = 0 ;
if ( V_288 -> V_290 < V_315 || V_7 -> V_9 < V_288 -> V_290 )
return 0 ;
if ( ! ( V_288 -> V_291 & V_316 ) )
goto V_317;
if ( V_288 -> V_289 < V_318 )
goto V_317;
V_100 = V_67 ( V_7 , V_288 ) ;
if ( V_100 == - V_307 )
goto V_319;
V_317:
if ( V_288 -> V_291 & V_320 || V_100 )
F_255 ( V_7 , V_288 , V_100 ) ;
V_319:
V_314 = F_244 ( V_288 -> V_290 ) ;
if ( V_314 > V_7 -> V_9 )
V_314 = V_7 -> V_9 ;
F_260 ( V_7 , V_314 ) ;
}
return 0 ;
}
int F_261 ( struct V_1 * V_2 , struct V_6 * V_7 , T_1 V_11 ,
unsigned int V_5 , int V_321 , T_2 V_3 )
{
int V_100 = 0 ;
if ( V_5 ) {
int V_322 = 0 ;
if ( V_321 ) {
F_41 ( & V_7 -> V_269 ) ;
V_322 = V_11 ;
}
V_100 = F_262 ( V_2 , V_7 , V_322 , V_5 , V_3 ) ;
}
if ( V_321 ) {
int V_323 ;
V_323 = F_263 ( V_2 , V_7 , V_11 ) ;
if ( ! V_100 || V_100 == - V_232 )
V_100 = V_323 ;
}
return V_100 ;
}
static int F_264 ( struct V_324 * V_325 )
{
int V_100 ;
V_100 = F_265 ( & V_93 [ V_325 -> V_326 ] . V_90 , & V_325 -> V_327 ,
V_119 ) ;
if ( V_100 ) {
V_325 -> V_326 = V_129 ;
return V_100 ;
}
V_100 = F_266 ( & V_325 -> V_327 ) ;
return V_100 == - V_200 ? 0 : V_100 ;
}
static void F_267 ( struct V_324 * V_325 )
{
F_268 ( & V_325 -> V_327 ) ;
F_269 ( & V_325 -> V_327 ) ;
}
static void * F_270 ( struct V_328 * V_287 )
{
struct V_324 * V_325 = V_287 -> V_329 ;
struct V_50 * V_51 ;
do {
for (; ; ) {
int V_100 ;
V_51 = F_271 ( & V_325 -> V_327 ) ;
if ( F_185 ( V_51 ) ) {
if ( F_186 ( V_51 ) == - V_200 )
continue;
return V_51 ;
}
if ( V_51 )
break;
F_267 ( V_325 ) ;
if ( ++ V_325 -> V_326 >= V_129 )
return NULL ;
V_100 = F_264 ( V_325 ) ;
if ( V_100 )
return F_159 ( V_100 ) ;
}
} while ( F_84 ( & V_51 -> V_2 ) != F_272 ( V_287 ) );
return V_51 ;
}
static void * F_273 ( struct V_328 * V_287 , T_7 * V_330 )
{
struct V_324 * V_325 = V_287 -> V_329 ;
void * V_331 = V_332 ;
T_7 V_253 ;
int V_100 ;
V_325 -> V_326 = 0 ;
V_100 = F_264 ( V_325 ) ;
if ( V_100 )
return F_159 ( V_100 ) ;
for ( V_253 = * V_330 ; V_253 && V_331 && ! F_185 ( V_331 ) ; V_253 -- )
V_331 = F_270 ( V_287 ) ;
return V_331 ;
}
static void * F_274 ( struct V_328 * V_287 , void * V_333 , T_7 * V_253 )
{
++ * V_253 ;
return F_270 ( V_287 ) ;
}
static void F_275 ( struct V_328 * V_287 , void * V_333 )
{
struct V_324 * V_325 = V_287 -> V_329 ;
if ( V_325 -> V_326 >= V_129 )
return;
F_267 ( V_325 ) ;
}
static int F_276 ( struct V_328 * V_287 , void * V_333 )
{
if ( V_333 == V_332 ) {
F_277 ( V_287 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_334 = V_333 ;
struct V_50 * V_51 = F_2 ( V_334 ) ;
F_278 ( V_287 , L_6 ,
V_334 ,
V_334 -> V_29 ,
V_51 -> V_11 ,
V_51 -> V_72 ? ( T_1 ) V_51 -> V_72 [ 0 ] : 0 ,
F_279 ( V_334 ) ,
F_280 ( V_334 ) ,
V_51 -> V_66 ,
F_61 ( & V_334 -> V_109 ) ,
F_61 ( & V_334 -> V_58 ) ,
F_281 ( V_334 )
) ;
}
return 0 ;
}
static int F_282 ( struct V_190 * V_190 , struct V_155 * V_155 )
{
return F_283 ( V_190 , V_155 , & V_335 ,
sizeof( struct V_324 ) ) ;
}
int F_284 ( struct V_336 * V_337 )
{
return F_285 ( & V_141 , V_337 ) ;
}
int F_286 ( struct V_336 * V_337 )
{
return F_287 ( & V_141 , V_337 ) ;
}
static int T_8 F_288 ( struct V_87 * V_87 )
{
#ifdef F_289
if ( ! F_290 ( L_7 , 0 , V_87 -> V_338 , & V_339 ) )
return - V_40 ;
#endif
return 0 ;
}
static void T_9 F_291 ( struct V_87 * V_87 )
{
#ifdef F_289
F_292 ( L_7 , V_87 -> V_338 ) ;
#endif
}
static void T_10 F_293 ( void )
{
struct V_97 * V_97 ;
int V_72 = 32 ;
V_97 = F_235 ( sizeof( * V_97 ) + F_149 ( V_72 ) , V_119 ) ;
if ( ! V_97 )
F_294 ( L_8 ) ;
F_65 () ;
V_93 [ V_31 ] . V_72 = V_72 ;
F_236 ( V_93 [ V_31 ] . V_97 , V_97 ) ;
V_93 [ V_31 ] . V_23 = V_340 ;
V_93 [ V_31 ] . V_131 = 1 ;
V_93 [ V_31 ] . V_3 = V_181 ;
F_75 () ;
}
static inline T_1 F_295 ( const void * V_14 , T_1 V_9 , T_1 V_341 )
{
const struct V_50 * V_51 = V_14 ;
struct V_83 V_81 ;
F_86 ( & V_81 , F_84 ( & V_51 -> V_2 ) , V_51 -> V_11 ) ;
return F_296 ( ( T_1 * ) & V_81 , V_342 / sizeof( T_1 ) , V_341 ) ;
}
static int T_10 F_297 ( void )
{
int V_96 ;
int V_100 = F_298 ( & V_120 , 0 ) ;
if ( V_100 != 0 )
goto V_26;
F_299 ( sizeof( struct V_148 ) > F_300 ( struct V_6 , V_67 ) ) ;
V_93 = F_301 ( V_129 , sizeof( * V_93 ) , V_119 ) ;
if ( ! V_93 )
goto F_294;
for ( V_96 = 0 ; V_96 < V_129 ; V_96 ++ ) {
if ( F_302 ( & V_93 [ V_96 ] . V_90 ,
& V_91 ) < 0 ) {
while ( -- V_96 > 0 )
F_303 ( & V_93 [ V_96 ] . V_90 ) ;
F_132 ( V_93 ) ;
goto F_294;
}
}
F_304 ( & V_22 ) ;
F_293 () ;
F_305 ( & V_343 ) ;
F_306 ( & V_344 ) ;
F_307 () ;
V_26:
return V_100 ;
F_294:
F_294 ( L_9 ) ;
}
