static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ) ;
}
static inline struct V_2 * F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_4 ) ;
}
struct V_2 * F_5 ( int V_7 )
{
struct V_5 * V_8 ;
enum V_9 V_10 ;
switch ( V_7 ) {
case 0 :
V_10 = V_11 ;
break;
case 1 :
V_10 = V_12 ;
break;
default:
return NULL ;
}
V_8 = F_6 ( V_10 ) ;
return V_8 ? F_4 ( V_8 -> V_4 ) : NULL ;
}
static inline void F_7 ( struct V_2 * V_3 ,
const struct V_13 V_14 , T_1 V_15 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
void T_2 * V_17 ;
switch( V_14 . V_7 ) {
case V_18 : V_17 = V_16 -> V_19 ; break;
case V_20 : V_17 = V_16 -> V_21 ; break;
case V_22 : V_17 = V_16 -> V_23 ; break;
default: return;
}
F_8 ( V_15 , V_17 + V_14 . V_14 ) ;
}
static inline T_1 F_9 ( struct V_2 * V_3 ,
const struct V_13 V_14 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
void T_2 * V_17 ;
switch( V_14 . V_7 ) {
case V_18 : V_17 = V_16 -> V_19 ; break;
case V_20 : V_17 = V_16 -> V_21 ; break;
case V_22 : V_17 = V_16 -> V_23 ; break;
default: return 0 ;
}
return F_10 ( V_17 + V_14 . V_14 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_12 ( & V_16 -> V_24 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_14 ( & V_16 -> V_24 ) ;
}
static bool F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_24 . V_25 == 0 ;
}
static void F_16 ( void * V_26 , T_1 V_27 )
{
F_17 ( (struct V_28 * ) V_26 ) ;
}
static inline int F_18 ( struct V_2 * V_3 ,
const struct V_13 V_14 , int V_29 , int V_30 )
{
unsigned long V_31 ;
T_3 V_32 ;
int V_33 ;
V_33 = 100 ;
while ( V_33 -- > 0 ) {
if ( F_19 ( V_3 , V_14 , V_29 , V_29 ) == V_30 )
return V_30 ;
}
V_31 = V_34 + F_20 ( 500 ) ;
while ( F_21 ( V_34 , V_31 ) ) {
if ( F_19 ( V_3 , V_14 , V_29 , V_29 ) == V_30 )
return V_30 ;
V_32 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_35 ) ;
F_24 ( & V_32 , V_36 ) ;
}
return ! V_30 ;
}
T_4 F_25 ( enum V_37 V_38 )
{
switch ( V_38 ) {
case V_39 :
case V_40 :
return 24 ;
case V_41 :
return 18 ;
case V_42 :
return 16 ;
default:
F_26 () ;
return 0 ;
}
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_43 = F_28 () ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_44 = F_28 () ;
}
static void F_30 ( struct V_2 * V_3 , const char * V_45 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_3 V_33 , V_46 , V_47 ;
T_1 V_48 ;
T_1 V_49 , V_50 , V_51 ;
if ( ! V_52 )
return;
V_33 = F_28 () ;
V_46 = F_31 ( V_16 -> V_44 , V_16 -> V_43 ) ;
V_49 = ( T_1 ) F_32 ( V_46 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_47 = F_31 ( V_33 , V_16 -> V_44 ) ;
V_50 = ( T_1 ) F_32 ( V_47 ) ;
if ( V_50 == 0 )
V_50 = 1 ;
V_51 = V_49 + V_50 ;
V_48 = V_16 -> V_53 ;
F_33 ( V_54 L_1
L_2 ,
V_45 ,
V_49 ,
V_50 ,
V_51 ,
1000 * 1000 / V_51 ,
V_48 ,
V_48 * 1000 / V_51 ) ;
}
static inline void F_27 ( struct V_2 * V_3 )
{
}
static inline void F_29 ( struct V_2 * V_3 )
{
}
static inline void F_30 ( struct V_2 * V_3 ,
const char * V_45 )
{
}
static void F_34 ( T_1 V_55 )
{
if ( V_55 == 0 )
return;
if ( ! V_56 && ( V_55 & ~ V_57 ) == 0 )
return;
#define F_35 ( T_5 ) (status & DSI_IRQ_##x) ? (#x " ") : ""
F_36 ( L_3 ,
V_55 ,
V_56 ? F_35 ( V_58 ) : L_4 ,
V_56 ? F_35 ( V_59 ) : L_4 ,
V_56 ? F_35 ( V_60 ) : L_4 ,
V_56 ? F_35 ( V_61 ) : L_4 ,
F_35 ( V_62 ) ,
F_35 ( V_63 ) ,
F_35 ( V_64 ) ,
F_35 ( V_65 ) ,
F_35 ( V_66 ) ,
F_35 ( V_67 ) ,
F_35 ( V_68 ) ,
F_35 ( V_69 ) ,
F_35 ( V_70 ) ,
F_35 ( V_71 ) ,
F_35 ( V_72 ) ,
F_35 ( V_73 ) ,
F_35 ( V_74 ) ) ;
#undef F_35
}
static void F_37 ( int V_75 , T_1 V_55 )
{
if ( V_55 == 0 )
return;
if ( ! V_56 && ( V_55 & ~ V_76 ) == 0 )
return;
#define F_35 ( T_5 ) (status & DSI_VC_IRQ_##x) ? (#x " ") : ""
F_36 ( L_5 ,
V_75 ,
V_55 ,
F_35 ( V_77 ) ,
F_35 ( V_78 ) ,
F_35 ( V_79 ) ,
V_56 ? F_35 ( V_80 ) : L_4 ,
F_35 ( V_81 ) ,
F_35 ( V_82 ) ,
F_35 ( V_83 ) ,
F_35 ( V_84 ) ,
F_35 ( V_85 ) ) ;
#undef F_35
}
static void F_38 ( T_1 V_55 )
{
if ( V_55 == 0 )
return;
#define F_35 ( T_5 ) (status & DSI_CIO_IRQ_##x) ? (#x " ") : ""
F_36 ( L_6 ,
V_55 ,
F_35 ( V_86 ) ,
F_35 ( V_87 ) ,
F_35 ( V_88 ) ,
F_35 ( V_89 ) ,
F_35 ( V_90 ) ,
F_35 ( V_91 ) ,
F_35 ( V_92 ) ,
F_35 ( V_93 ) ,
F_35 ( V_94 ) ,
F_35 ( V_95 ) ,
F_35 ( V_96 ) ,
F_35 ( V_97 ) ,
F_35 ( V_98 ) ,
F_35 ( V_99 ) ,
F_35 ( V_100 ) ,
F_35 ( V_101 ) ,
F_35 ( V_102 ) ,
F_35 ( V_103 ) ,
F_35 ( V_104 ) ,
F_35 ( V_105 ) ) ;
#undef F_35
}
static void F_39 ( struct V_2 * V_3 , T_1 V_106 ,
T_1 * V_107 , T_1 V_108 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
F_40 ( & V_16 -> V_110 ) ;
V_16 -> V_111 . V_112 ++ ;
F_41 ( V_106 , V_16 -> V_111 . V_113 ) ;
for ( V_109 = 0 ; V_109 < 4 ; ++ V_109 )
F_41 ( V_107 [ V_109 ] , V_16 -> V_111 . V_114 [ V_109 ] ) ;
F_41 ( V_108 , V_16 -> V_111 . V_115 ) ;
F_42 ( & V_16 -> V_110 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_1 V_106 ,
T_1 * V_107 , T_1 V_108 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
if ( V_106 & V_116 ) {
F_44 ( L_7 , V_106 ) ;
F_34 ( V_106 ) ;
F_40 ( & V_16 -> V_117 ) ;
V_16 -> V_118 |= V_106 & V_116 ;
F_42 ( & V_16 -> V_117 ) ;
} else if ( V_119 ) {
F_34 ( V_106 ) ;
}
for ( V_109 = 0 ; V_109 < 4 ; ++ V_109 ) {
if ( V_107 [ V_109 ] & V_120 ) {
F_44 ( L_8 ,
V_109 , V_107 [ V_109 ] ) ;
F_37 ( V_109 , V_107 [ V_109 ] ) ;
} else if ( V_119 ) {
F_37 ( V_109 , V_107 [ V_109 ] ) ;
}
}
if ( V_108 & V_121 ) {
F_44 ( L_9 , V_108 ) ;
F_38 ( V_108 ) ;
} else if ( V_119 ) {
F_38 ( V_108 ) ;
}
}
static void F_45 ( struct V_122 * V_123 ,
unsigned V_124 , T_1 V_106 )
{
struct V_122 * V_125 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_124 ; V_109 ++ ) {
V_125 = & V_123 [ V_109 ] ;
if ( V_125 -> V_126 && V_125 -> V_27 & V_106 )
V_125 -> V_126 ( V_125 -> V_127 , V_106 ) ;
}
}
static void F_46 ( struct V_128 * V_129 ,
T_1 V_106 , T_1 * V_107 , T_1 V_108 )
{
int V_109 ;
F_45 ( V_129 -> V_130 ,
F_47 ( V_129 -> V_130 ) ,
V_106 ) ;
for ( V_109 = 0 ; V_109 < 4 ; ++ V_109 ) {
if ( V_107 [ V_109 ] == 0 )
continue;
F_45 ( V_129 -> V_131 [ V_109 ] ,
F_47 ( V_129 -> V_131 [ V_109 ] ) ,
V_107 [ V_109 ] ) ;
}
if ( V_108 != 0 )
F_45 ( V_129 -> V_132 ,
F_47 ( V_129 -> V_132 ) ,
V_108 ) ;
}
static T_6 F_48 ( int V_133 , void * V_127 )
{
struct V_2 * V_3 ;
struct V_1 * V_16 ;
T_1 V_106 , V_107 [ 4 ] , V_108 ;
int V_109 ;
V_3 = (struct V_2 * ) V_127 ;
V_16 = F_1 ( V_3 ) ;
F_40 ( & V_16 -> V_134 ) ;
V_106 = F_9 ( V_3 , V_135 ) ;
if ( ! V_106 ) {
F_42 ( & V_16 -> V_134 ) ;
return V_136 ;
}
F_7 ( V_3 , V_135 , V_106 & ~ V_57 ) ;
F_9 ( V_3 , V_135 ) ;
for ( V_109 = 0 ; V_109 < 4 ; ++ V_109 ) {
if ( ( V_106 & ( 1 << V_109 ) ) == 0 ) {
V_107 [ V_109 ] = 0 ;
continue;
}
V_107 [ V_109 ] = F_9 ( V_3 , F_49 ( V_109 ) ) ;
F_7 ( V_3 , F_49 ( V_109 ) , V_107 [ V_109 ] ) ;
F_9 ( V_3 , F_49 ( V_109 ) ) ;
}
if ( V_106 & V_137 ) {
V_108 = F_9 ( V_3 , V_138 ) ;
F_7 ( V_3 , V_138 , V_108 ) ;
F_9 ( V_3 , V_138 ) ;
} else {
V_108 = 0 ;
}
#ifdef F_50
if ( V_106 & V_139 )
F_51 ( & V_16 -> V_140 ) ;
#endif
memcpy ( & V_16 -> V_141 , & V_16 -> V_129 ,
sizeof( V_16 -> V_129 ) ) ;
F_42 ( & V_16 -> V_134 ) ;
F_46 ( & V_16 -> V_141 , V_106 , V_107 , V_108 ) ;
F_43 ( V_3 , V_106 , V_107 , V_108 ) ;
F_39 ( V_3 , V_106 , V_107 , V_108 ) ;
return V_142 ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
unsigned V_124 , T_1 V_143 ,
const struct V_13 V_144 ,
const struct V_13 V_145 )
{
struct V_122 * V_125 ;
T_1 V_27 ;
T_1 V_146 ;
int V_109 ;
V_27 = V_143 ;
for ( V_109 = 0 ; V_109 < V_124 ; V_109 ++ ) {
V_125 = & V_123 [ V_109 ] ;
if ( V_125 -> V_126 == NULL )
continue;
V_27 |= V_125 -> V_27 ;
}
V_146 = F_9 ( V_3 , V_144 ) ;
F_7 ( V_3 , V_145 , ( V_27 ^ V_146 ) & V_27 ) ;
F_7 ( V_3 , V_144 , V_27 ) ;
F_9 ( V_3 , V_144 ) ;
F_9 ( V_3 , V_145 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_27 = V_116 ;
#ifdef F_50
V_27 |= V_139 ;
#endif
F_52 ( V_3 , V_16 -> V_129 . V_130 ,
F_47 ( V_16 -> V_129 . V_130 ) , V_27 ,
V_147 , V_135 ) ;
}
static void F_54 ( struct V_2 * V_3 , int V_148 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_129 . V_131 [ V_148 ] ,
F_47 ( V_16 -> V_129 . V_131 [ V_148 ] ) ,
V_120 ,
F_55 ( V_148 ) , F_49 ( V_148 ) ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_129 . V_132 ,
F_47 ( V_16 -> V_129 . V_132 ) ,
V_121 ,
V_149 , V_138 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_148 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
memset ( & V_16 -> V_129 , 0 , sizeof( V_16 -> V_129 ) ) ;
F_53 ( V_3 ) ;
for ( V_148 = 0 ; V_148 < 4 ; ++ V_148 )
F_54 ( V_3 , V_148 ) ;
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
}
static int F_60 ( T_7 V_126 , void * V_127 , T_1 V_27 ,
struct V_122 * V_123 , unsigned V_124 )
{
struct V_122 * V_125 ;
int V_151 ;
int V_109 ;
F_61 ( V_126 == NULL ) ;
V_151 = - 1 ;
for ( V_109 = 0 ; V_109 < V_124 ; V_109 ++ ) {
V_125 = & V_123 [ V_109 ] ;
if ( V_125 -> V_126 == V_126 && V_125 -> V_127 == V_127 &&
V_125 -> V_27 == V_27 ) {
return - V_152 ;
}
if ( V_125 -> V_126 == NULL && V_151 == - 1 )
V_151 = V_109 ;
}
if ( V_151 == - 1 )
return - V_153 ;
V_125 = & V_123 [ V_151 ] ;
V_125 -> V_126 = V_126 ;
V_125 -> V_127 = V_127 ;
V_125 -> V_27 = V_27 ;
return 0 ;
}
static int F_62 ( T_7 V_126 , void * V_127 , T_1 V_27 ,
struct V_122 * V_123 , unsigned V_124 )
{
struct V_122 * V_125 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_124 ; V_109 ++ ) {
V_125 = & V_123 [ V_109 ] ;
if ( V_125 -> V_126 != V_126 || V_125 -> V_127 != V_127 ||
V_125 -> V_27 != V_27 )
continue;
V_125 -> V_126 = NULL ;
V_125 -> V_127 = NULL ;
V_125 -> V_27 = 0 ;
return 0 ;
}
return - V_152 ;
}
static int F_63 ( struct V_2 * V_3 , T_7 V_126 ,
void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
V_154 = F_60 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_130 ,
F_47 ( V_16 -> V_129 . V_130 ) ) ;
if ( V_154 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
return V_154 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
V_154 = F_62 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_130 ,
F_47 ( V_16 -> V_129 . V_130 ) ) ;
if ( V_154 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
return V_154 ;
}
static int F_65 ( struct V_2 * V_3 , int V_75 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
V_154 = F_60 ( V_126 , V_127 , V_27 ,
V_16 -> V_129 . V_131 [ V_75 ] ,
F_47 ( V_16 -> V_129 . V_131 [ V_75 ] ) ) ;
if ( V_154 == 0 )
F_54 ( V_3 , V_75 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
return V_154 ;
}
static int F_66 ( struct V_2 * V_3 , int V_75 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
V_154 = F_62 ( V_126 , V_127 , V_27 ,
V_16 -> V_129 . V_131 [ V_75 ] ,
F_47 ( V_16 -> V_129 . V_131 [ V_75 ] ) ) ;
if ( V_154 == 0 )
F_54 ( V_3 , V_75 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
return V_154 ;
}
static int F_67 ( struct V_2 * V_3 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
V_154 = F_60 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_132 ,
F_47 ( V_16 -> V_129 . V_132 ) ) ;
if ( V_154 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
return V_154 ;
}
static int F_68 ( struct V_2 * V_3 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_134 , V_150 ) ;
V_154 = F_62 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_132 ,
F_47 ( V_16 -> V_129 . V_132 ) ) ;
if ( V_154 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_134 , V_150 ) ;
return V_154 ;
}
static T_1 F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
T_1 V_155 ;
F_58 ( & V_16 -> V_117 , V_150 ) ;
V_155 = V_16 -> V_118 ;
V_16 -> V_118 = 0 ;
F_59 ( & V_16 -> V_117 , V_150 ) ;
return V_155 ;
}
int F_70 ( struct V_2 * V_3 )
{
int V_154 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_10 ) ;
V_154 = F_72 ( & V_16 -> V_156 -> V_4 ) ;
F_73 ( V_154 < 0 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
F_71 ( L_11 ) ;
V_154 = F_75 ( & V_16 -> V_156 -> V_4 ) ;
F_73 ( V_154 < 0 && V_154 != - V_157 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_158 * V_159 ;
if ( V_16 -> V_160 != NULL )
return 0 ;
V_159 = F_77 ( & V_16 -> V_156 -> V_4 , L_12 ) ;
if ( F_78 ( V_159 ) )
V_159 = F_77 ( & V_16 -> V_156 -> V_4 , L_13 ) ;
if ( F_78 ( V_159 ) ) {
if ( F_79 ( V_159 ) != - V_161 )
F_44 ( L_14 ) ;
return F_79 ( V_159 ) ;
}
V_16 -> V_160 = V_159 ;
return 0 ;
}
static inline void F_80 ( struct V_2 * V_3 ,
bool V_162 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_162 )
F_81 ( V_16 -> V_163 ) ;
else
F_82 ( V_16 -> V_163 ) ;
if ( V_162 && V_16 -> V_164 ) {
if ( F_18 ( V_3 , V_165 , 1 , 1 ) != 1 )
F_44 ( L_15 ) ;
}
}
static void F_83 ( struct V_2 * V_3 )
{
T_1 V_166 ;
int V_167 , V_168 , V_169 ;
V_166 = F_9 ( V_3 , V_170 ) ;
if ( F_84 ( V_171 ) ) {
V_167 = 28 ;
V_168 = 27 ;
V_169 = 26 ;
} else {
V_167 = 24 ;
V_168 = 25 ;
V_169 = 26 ;
}
#define F_85 ( T_8 , T_9 , T_10 ) \
FLD_GET(dsi_read_reg(dsidev, DSI_##fld), start, end)
F_36 ( L_16 ,
F_85 ( V_172 , 0 , 0 ) ,
F_85 ( V_173 , 29 , 29 ) ,
F_85 ( V_174 , V_167 , V_167 ) ,
F_85 ( V_174 , V_168 , V_168 ) ,
F_85 ( V_174 , V_169 , V_169 ) ,
F_85 ( V_174 , 29 , 29 ) ,
F_85 ( V_174 , 30 , 30 ) ,
F_85 ( V_174 , 31 , 31 ) ) ;
#undef F_85
}
static inline int F_86 ( struct V_2 * V_3 , bool V_162 )
{
F_71 ( L_17 , V_162 ) ;
V_162 = V_162 ? 1 : 0 ;
F_87 ( V_3 , V_175 , V_162 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_175 , 0 , V_162 ) != V_162 ) {
F_44 ( L_18 , V_162 ) ;
return - V_176 ;
}
return 0 ;
}
unsigned long F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_177 . V_178 ;
}
static unsigned long F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_177 . V_179 ;
}
static unsigned long F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_177 . V_180 / 16 ;
}
static unsigned long F_91 ( struct V_2 * V_3 )
{
unsigned long V_154 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( F_92 ( V_16 -> V_181 ) == V_182 ) {
V_154 = F_93 ( V_16 -> V_183 ) ;
} else {
V_154 = F_89 ( V_3 ) ;
}
return V_154 ;
}
static int F_94 ( struct V_184 * V_185 ,
unsigned long V_186 , unsigned long V_187 )
{
unsigned long V_188 = V_185 -> V_179 ;
unsigned V_189 ;
unsigned long V_190 ;
V_189 = F_95 ( V_188 , V_187 * 2 ) ;
V_190 = V_188 / 2 / V_189 ;
if ( V_190 < V_186 || V_190 > V_187 )
return - V_152 ;
V_185 -> V_189 = V_189 ;
V_185 -> V_190 = V_190 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_188 ;
unsigned V_189 ;
unsigned long V_190 ;
V_189 = V_16 -> V_191 . V_189 ;
if ( V_189 == 0 || V_189 > V_16 -> V_192 )
return - V_152 ;
V_188 = F_91 ( V_3 ) ;
V_190 = V_188 / 2 / V_189 ;
F_71 ( L_19 , V_189 , V_190 ) ;
V_16 -> V_177 . V_190 = V_190 ;
V_16 -> V_177 . V_189 = V_189 ;
F_87 ( V_3 , V_193 , V_189 , 12 , 0 ) ;
F_87 ( V_3 , V_193 , V_188 > 30000000 ? 1 : 0 , 21 , 21 ) ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_194 ++ == 0 )
F_87 ( V_3 , V_193 , 1 , 14 , 14 ) ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_194 == 0 ) ;
if ( -- V_16 -> V_194 == 0 )
F_87 ( V_3 , V_193 , 0 , 14 , 14 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
enum V_195 V_196 )
{
int V_33 = 0 ;
if ( F_84 ( V_197 ) &&
V_196 == V_198 )
V_196 = V_199 ;
F_87 ( V_3 , V_193 , V_196 , 31 , 30 ) ;
while ( F_100 ( F_9 ( V_3 , V_193 ) , 29 , 28 ) != V_196 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_20 ,
V_196 ) ;
return - V_200 ;
}
F_101 ( 1 ) ;
}
return 0 ;
}
unsigned long F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return F_93 ( V_16 -> V_163 ) ;
}
bool F_103 ( struct V_2 * V_3 , unsigned long V_201 ,
unsigned long V_202 , T_11 V_203 , void * V_26 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_204 , V_205 , V_206 ;
unsigned long V_207 ;
unsigned long V_8 ;
V_202 = V_202 ? V_202 : 1 ;
V_207 = F_104 ( V_208 ) ;
V_205 = F_105 ( F_95 ( V_201 , V_207 ) , 1ul ) ;
V_206 = F_106 ( V_201 / V_202 , V_16 -> V_209 ) ;
for ( V_204 = V_205 ; V_204 <= V_206 ; ++ V_204 ) {
V_8 = V_201 / V_204 ;
if ( V_203 ( V_204 , V_8 , V_26 ) )
return true ;
}
return false ;
}
bool F_107 ( struct V_2 * V_3 , unsigned long V_210 ,
unsigned long V_211 , unsigned long V_212 ,
T_12 V_203 , void * V_26 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_213 , V_214 , V_215 ;
int V_204 , V_205 , V_206 ;
unsigned long V_216 , V_201 ;
const unsigned long V_217 = 1800000000 ;
unsigned long V_218 , V_219 ;
V_218 = V_16 -> V_220 ;
V_219 = V_16 -> V_221 ;
V_214 = F_105 ( F_95 ( V_210 , V_219 ) , 1ul ) ;
V_215 = F_106 ( V_210 / V_218 , V_16 -> V_222 ) ;
V_212 = V_212 ? V_212 : V_223 ;
for ( V_213 = V_214 ; V_213 <= V_215 ; ++ V_213 ) {
V_216 = V_210 / V_213 ;
V_205 = F_105 ( F_95 ( F_95 ( V_211 , V_216 ) , 2 ) ,
1ul ) ;
V_206 = F_108 ( V_212 / V_216 / 2 ,
V_217 / V_216 / 2 ,
V_16 -> V_224 ) ;
for ( V_204 = V_205 ; V_204 <= V_206 ; ++ V_204 ) {
V_201 = 2 * V_204 * V_216 ;
if ( V_203 ( V_213 , V_204 , V_216 , V_201 , V_26 ) )
return true ;
}
}
return false ;
}
static int F_109 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_185 -> V_213 == 0 || V_185 -> V_213 > V_16 -> V_222 )
return - V_152 ;
if ( V_185 -> V_204 == 0 || V_185 -> V_204 > V_16 -> V_224 )
return - V_152 ;
if ( V_185 -> V_225 > V_16 -> V_209 )
return - V_152 ;
if ( V_185 -> V_226 > V_16 -> V_227 )
return - V_152 ;
V_185 -> V_210 = F_93 ( V_16 -> V_163 ) ;
V_185 -> V_216 = V_185 -> V_210 / V_185 -> V_213 ;
if ( V_185 -> V_216 > V_16 -> V_221 || V_185 -> V_216 < V_16 -> V_220 )
return - V_152 ;
V_185 -> V_180 = 2 * V_185 -> V_204 * V_185 -> V_216 ;
if ( V_185 -> V_180 > 1800 * 1000 * 1000 )
return - V_152 ;
if ( V_185 -> V_225 > 0 )
V_185 -> V_178 =
V_185 -> V_180 / V_185 -> V_225 ;
else
V_185 -> V_178 = 0 ;
if ( V_185 -> V_226 > 0 )
V_185 -> V_179 =
V_185 -> V_180 / V_185 -> V_226 ;
else
V_185 -> V_179 = 0 ;
return 0 ;
}
static void F_110 ( struct V_184 * V_185 )
{
unsigned long V_228 ;
V_228 = F_104 ( V_229 ) ;
V_185 -> V_226 = F_95 ( V_185 -> V_180 , V_228 ) ;
V_185 -> V_179 = V_185 -> V_180 / V_185 -> V_226 ;
}
int F_111 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 = 0 ;
T_1 V_166 ;
int V_230 = 0 ;
T_4 V_214 , V_231 , V_205 , V_232 ;
T_4 V_233 , V_234 , V_235 , V_236 ;
F_71 ( L_21 ) ;
V_16 -> V_177 . V_210 = V_185 -> V_210 ;
V_16 -> V_177 . V_216 = V_185 -> V_216 ;
V_16 -> V_177 . V_180 = V_185 -> V_180 ;
V_16 -> V_177 . V_178 =
V_185 -> V_178 ;
V_16 -> V_177 . V_179 =
V_185 -> V_179 ;
V_16 -> V_177 . V_213 = V_185 -> V_213 ;
V_16 -> V_177 . V_204 = V_185 -> V_204 ;
V_16 -> V_177 . V_225 = V_185 -> V_225 ;
V_16 -> V_177 . V_226 = V_185 -> V_226 ;
F_71 ( L_22 , V_185 -> V_216 ) ;
F_71 ( L_23 , V_185 -> V_210 ) ;
F_71 ( L_24 ,
V_185 -> V_204 ,
V_185 -> V_213 ,
V_185 -> V_210 ,
V_185 -> V_180 ) ;
F_71 ( L_25 ,
V_185 -> V_180 / 1000 / 1000 / 2 ) ;
F_71 ( L_26 , V_185 -> V_180 / 4 ) ;
F_71 ( L_27 , V_185 -> V_225 ,
F_112 ( V_237 ) ,
F_113 ( V_237 ) ,
V_185 -> V_178 ) ;
F_71 ( L_28 , V_185 -> V_226 ,
F_112 ( V_238 ) ,
F_113 ( V_238 ) ,
V_185 -> V_179 ) ;
F_114 ( V_239 , & V_214 , & V_231 ) ;
F_114 ( V_240 , & V_205 , & V_232 ) ;
F_114 ( V_241 , & V_233 ,
& V_234 ) ;
F_114 ( V_242 , & V_235 ,
& V_236 ) ;
F_87 ( V_3 , V_243 , 0 , 0 , 0 ) ;
V_166 = F_9 ( V_3 , V_244 ) ;
V_166 = F_115 ( V_166 , 1 , 0 , 0 ) ;
V_166 = F_115 ( V_166 , V_185 -> V_213 - 1 , V_214 , V_231 ) ;
V_166 = F_115 ( V_166 , V_185 -> V_204 , V_205 , V_232 ) ;
V_166 = F_115 ( V_166 , V_185 -> V_225 > 0 ? V_185 -> V_225 - 1 : 0 ,
V_233 , V_234 ) ;
V_166 = F_115 ( V_166 , V_185 -> V_226 > 0 ? V_185 -> V_226 - 1 : 0 ,
V_235 , V_236 ) ;
F_7 ( V_3 , V_244 , V_166 ) ;
F_61 ( V_185 -> V_216 < V_16 -> V_220 || V_185 -> V_216 > V_16 -> V_221 ) ;
V_166 = F_9 ( V_3 , V_245 ) ;
if ( F_84 ( V_246 ) ) {
V_230 = V_185 -> V_216 < 1000000 ? 0x3 :
V_185 -> V_216 < 1250000 ? 0x4 :
V_185 -> V_216 < 1500000 ? 0x5 :
V_185 -> V_216 < 1750000 ? 0x6 :
0x7 ;
V_166 = F_115 ( V_166 , V_230 , 4 , 1 ) ;
} else if ( F_84 ( V_247 ) ) {
V_230 = V_185 -> V_180 < 1000000000 ? 0x2 : 0x4 ;
V_166 = F_115 ( V_166 , V_230 , 4 , 1 ) ;
}
V_166 = F_115 ( V_166 , 1 , 13 , 13 ) ;
V_166 = F_115 ( V_166 , 0 , 14 , 14 ) ;
V_166 = F_115 ( V_166 , 1 , 20 , 20 ) ;
if ( F_84 ( V_248 ) )
V_166 = F_115 ( V_166 , 3 , 22 , 21 ) ;
F_7 ( V_3 , V_245 , V_166 ) ;
F_87 ( V_3 , V_249 , 1 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_249 , 0 , 0 ) != 0 ) {
F_44 ( L_29 ) ;
V_154 = - V_176 ;
goto V_250;
}
if ( F_18 ( V_3 , V_165 , 1 , 1 ) != 1 ) {
F_44 ( L_30 ) ;
V_154 = - V_176 ;
goto V_250;
}
V_16 -> V_164 = 1 ;
V_166 = F_9 ( V_3 , V_245 ) ;
V_166 = F_115 ( V_166 , 0 , 0 , 0 ) ;
V_166 = F_115 ( V_166 , 0 , 5 , 5 ) ;
V_166 = F_115 ( V_166 , 0 , 6 , 6 ) ;
V_166 = F_115 ( V_166 , 0 , 7 , 7 ) ;
V_166 = F_115 ( V_166 , 0 , 8 , 8 ) ;
V_166 = F_115 ( V_166 , 0 , 10 , 9 ) ;
V_166 = F_115 ( V_166 , 1 , 13 , 13 ) ;
V_166 = F_115 ( V_166 , 1 , 14 , 14 ) ;
V_166 = F_115 ( V_166 , 0 , 15 , 15 ) ;
V_166 = F_115 ( V_166 , 1 , 16 , 16 ) ;
V_166 = F_115 ( V_166 , 0 , 17 , 17 ) ;
V_166 = F_115 ( V_166 , 1 , 18 , 18 ) ;
V_166 = F_115 ( V_166 , 0 , 19 , 19 ) ;
V_166 = F_115 ( V_166 , 0 , 20 , 20 ) ;
F_7 ( V_3 , V_245 , V_166 ) ;
F_71 ( L_31 ) ;
V_250:
return V_154 ;
}
int F_116 ( struct V_2 * V_3 , bool V_251 ,
bool V_252 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 = 0 ;
enum V_195 V_253 ;
F_71 ( L_32 ) ;
V_251 = V_252 = true ;
V_154 = F_76 ( V_3 ) ;
if ( V_154 )
return V_154 ;
F_80 ( V_3 , 1 ) ;
F_97 ( V_3 ) ;
if ( ! V_16 -> V_254 ) {
V_154 = F_117 ( V_16 -> V_160 ) ;
if ( V_154 )
goto V_255;
V_16 -> V_254 = true ;
}
F_118 ( 1 ) ;
if ( F_18 ( V_3 , V_165 , 0 , 1 ) != 1 ) {
F_44 ( L_33 ) ;
V_154 = - V_200 ;
F_118 ( 0 ) ;
goto V_256;
}
F_118 ( 0 ) ;
if ( V_251 && V_252 )
V_253 = V_199 ;
else if ( V_251 )
V_253 = V_257 ;
else if ( V_252 )
V_253 = V_198 ;
else
V_253 = V_258 ;
V_154 = F_99 ( V_3 , V_253 ) ;
if ( V_154 )
goto V_256;
F_71 ( L_34 ) ;
return 0 ;
V_256:
if ( V_16 -> V_254 ) {
F_119 ( V_16 -> V_160 ) ;
V_16 -> V_254 = false ;
}
V_255:
F_98 ( V_3 ) ;
F_80 ( V_3 , 0 ) ;
return V_154 ;
}
void F_120 ( struct V_2 * V_3 , bool V_259 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_164 = 0 ;
F_99 ( V_3 , V_258 ) ;
if ( V_259 ) {
F_73 ( ! V_16 -> V_254 ) ;
F_119 ( V_16 -> V_160 ) ;
V_16 -> V_254 = false ;
}
F_98 ( V_3 ) ;
F_80 ( V_3 , 0 ) ;
F_71 ( L_35 ) ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_260 * V_261 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_184 * V_185 = & V_16 -> V_177 ;
enum V_262 V_263 , V_264 ;
int V_265 = V_16 -> V_181 ;
V_263 = F_122 () ;
V_264 = F_92 ( V_265 ) ;
if ( F_70 ( V_3 ) )
return;
F_123 ( V_261 , L_36 , V_265 + 1 ) ;
F_123 ( V_261 , L_37 , V_185 -> V_210 ) ;
F_123 ( V_261 , L_38 , V_185 -> V_216 , V_185 -> V_213 ) ;
F_123 ( V_261 , L_39 ,
V_185 -> V_180 , V_185 -> V_204 ) ;
F_123 ( V_261 , L_40 ,
F_113 ( V_265 == 0 ?
V_237 :
V_266 ) ,
V_185 -> V_178 ,
V_185 -> V_225 ,
V_263 == V_182 ?
L_41 : L_42 ) ;
F_123 ( V_261 , L_43 ,
F_113 ( V_265 == 0 ?
V_238 :
V_267 ) ,
V_185 -> V_179 ,
V_185 -> V_226 ,
V_264 == V_182 ?
L_41 : L_42 ) ;
F_123 ( V_261 , L_44 , V_265 + 1 ) ;
F_123 ( V_261 , L_45 ,
F_112 ( V_264 ) ,
F_113 ( V_264 ) ) ;
F_123 ( V_261 , L_46 , F_91 ( V_3 ) ) ;
F_123 ( V_261 , L_47 ,
V_185 -> V_180 / 4 ) ;
F_123 ( V_261 , L_48 , F_90 ( V_3 ) ) ;
F_123 ( V_261 , L_49 , V_185 -> V_190 ) ;
F_74 ( V_3 ) ;
}
void F_124 ( struct V_260 * V_261 )
{
struct V_2 * V_3 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_268 ; V_109 ++ ) {
V_3 = F_5 ( V_109 ) ;
if ( V_3 )
F_121 ( V_3 , V_261 ) ;
}
}
static void F_125 ( struct V_2 * V_3 ,
struct V_260 * V_261 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
struct V_269 V_270 ;
F_58 ( & V_16 -> V_110 , V_150 ) ;
V_270 = V_16 -> V_111 ;
memset ( & V_16 -> V_111 , 0 , sizeof( V_16 -> V_111 ) ) ;
V_16 -> V_111 . V_271 = V_34 ;
F_59 ( & V_16 -> V_110 , V_150 ) ;
F_123 ( V_261 , L_50 ,
F_126 ( V_34 - V_270 . V_271 ) ) ;
F_123 ( V_261 , L_51 , V_270 . V_112 ) ;
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d\n", #x, stats.dsi_irqs[ffs(DSI_IRQ_##x)-1]);
F_123 ( V_261 , L_52 , V_16 -> V_181 + 1 ) ;
F_35 ( V_58 ) ;
F_35 ( V_59 ) ;
F_35 ( V_60 ) ;
F_35 ( V_61 ) ;
F_35 ( V_62 ) ;
F_35 ( V_63 ) ;
F_35 ( V_64 ) ;
F_35 ( V_65 ) ;
F_35 ( V_66 ) ;
F_35 ( V_67 ) ;
F_35 ( V_68 ) ;
F_35 ( V_69 ) ;
F_35 ( V_70 ) ;
F_35 ( V_71 ) ;
F_35 ( V_72 ) ;
F_35 ( V_73 ) ;
F_35 ( V_74 ) ;
#undef F_35
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d %10d %10d %10d\n", #x, \
stats.vc_irqs[0][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[1][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[2][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[3][ffs(DSI_VC_IRQ_##x)-1]);
F_123 ( V_261 , L_53 ) ;
F_35 ( V_77 ) ;
F_35 ( V_78 ) ;
F_35 ( V_80 ) ;
F_35 ( V_82 ) ;
F_35 ( V_83 ) ;
F_35 ( V_81 ) ;
F_35 ( V_79 ) ;
F_35 ( V_84 ) ;
F_35 ( V_85 ) ;
#undef F_35
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d\n", #x, \
stats.cio_irqs[ffs(DSI_CIO_IRQ_##x)-1]);
F_123 ( V_261 , L_54 ) ;
F_35 ( V_86 ) ;
F_35 ( V_87 ) ;
F_35 ( V_88 ) ;
F_35 ( V_89 ) ;
F_35 ( V_90 ) ;
F_35 ( V_91 ) ;
F_35 ( V_92 ) ;
F_35 ( V_93 ) ;
F_35 ( V_94 ) ;
F_35 ( V_95 ) ;
F_35 ( V_96 ) ;
F_35 ( V_97 ) ;
F_35 ( V_98 ) ;
F_35 ( V_99 ) ;
F_35 ( V_100 ) ;
F_35 ( V_101 ) ;
F_35 ( V_102 ) ;
F_35 ( V_103 ) ;
F_35 ( V_104 ) ;
F_35 ( V_105 ) ;
#undef F_35
}
static void F_127 ( struct V_260 * V_261 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_125 ( V_3 , V_261 ) ;
}
static void F_128 ( struct V_260 * V_261 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_125 ( V_3 , V_261 ) ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_260 * V_261 )
{
#define F_130 ( V_154 ) seq_printf(s, "%-35s %08x\n", #r, dsi_read_reg(dsidev, r))
if ( F_70 ( V_3 ) )
return;
F_97 ( V_3 ) ;
F_130 ( V_272 ) ;
F_130 ( V_273 ) ;
F_130 ( V_274 ) ;
F_130 ( V_135 ) ;
F_130 ( V_147 ) ;
F_130 ( V_175 ) ;
F_130 ( V_275 ) ;
F_130 ( V_138 ) ;
F_130 ( V_149 ) ;
F_130 ( V_193 ) ;
F_130 ( V_276 ) ;
F_130 ( V_277 ) ;
F_130 ( V_278 ) ;
F_130 ( V_279 ) ;
F_130 ( V_280 ) ;
F_130 ( V_281 ) ;
F_130 ( V_282 ) ;
F_130 ( V_283 ) ;
F_130 ( V_284 ) ;
F_130 ( V_285 ) ;
F_130 ( V_286 ) ;
F_130 ( V_287 ) ;
F_130 ( V_288 ) ;
F_130 ( V_289 ) ;
F_130 ( V_290 ) ;
F_130 ( V_291 ) ;
F_130 ( F_131 ( 0 ) ) ;
F_130 ( F_132 ( 0 ) ) ;
F_130 ( F_133 ( 0 ) ) ;
F_130 ( F_134 ( 0 ) ) ;
F_130 ( F_135 ( 0 ) ) ;
F_130 ( F_49 ( 0 ) ) ;
F_130 ( F_55 ( 0 ) ) ;
F_130 ( F_131 ( 1 ) ) ;
F_130 ( F_132 ( 1 ) ) ;
F_130 ( F_133 ( 1 ) ) ;
F_130 ( F_134 ( 1 ) ) ;
F_130 ( F_135 ( 1 ) ) ;
F_130 ( F_49 ( 1 ) ) ;
F_130 ( F_55 ( 1 ) ) ;
F_130 ( F_131 ( 2 ) ) ;
F_130 ( F_132 ( 2 ) ) ;
F_130 ( F_133 ( 2 ) ) ;
F_130 ( F_134 ( 2 ) ) ;
F_130 ( F_135 ( 2 ) ) ;
F_130 ( F_49 ( 2 ) ) ;
F_130 ( F_55 ( 2 ) ) ;
F_130 ( F_131 ( 3 ) ) ;
F_130 ( F_132 ( 3 ) ) ;
F_130 ( F_133 ( 3 ) ) ;
F_130 ( F_134 ( 3 ) ) ;
F_130 ( F_135 ( 3 ) ) ;
F_130 ( F_49 ( 3 ) ) ;
F_130 ( F_55 ( 3 ) ) ;
F_130 ( V_292 ) ;
F_130 ( V_293 ) ;
F_130 ( V_294 ) ;
F_130 ( V_170 ) ;
F_130 ( V_243 ) ;
F_130 ( V_165 ) ;
F_130 ( V_249 ) ;
F_130 ( V_244 ) ;
F_130 ( V_245 ) ;
F_98 ( V_3 ) ;
F_74 ( V_3 ) ;
#undef F_130
}
static void F_136 ( struct V_260 * V_261 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_129 ( V_3 , V_261 ) ;
}
static void F_137 ( struct V_260 * V_261 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_129 ( V_3 , V_261 ) ;
}
static int F_138 ( struct V_2 * V_3 ,
enum V_295 V_196 )
{
int V_33 = 0 ;
F_87 ( V_3 , V_275 , V_196 , 28 , 27 ) ;
while ( F_100 ( F_9 ( V_3 , V_275 ) ,
26 , 25 ) != V_196 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_55
L_56 , V_196 ) ;
return - V_200 ;
}
F_101 ( 1 ) ;
}
return 0 ;
}
static unsigned F_139 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! F_84 ( V_296 ) )
return 1023 * 3 ;
V_15 = F_19 ( V_3 , V_297 , 14 , 12 ) ;
switch ( V_15 ) {
case 1 :
return 512 * 3 ;
case 2 :
return 682 * 3 ;
case 3 :
return 853 * 3 ;
case 4 :
return 1024 * 3 ;
case 5 :
return 1194 * 3 ;
case 6 :
return 1365 * 3 ;
case 7 :
return 1920 * 3 ;
default:
F_26 () ;
return 0 ;
}
}
static int F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
static const T_4 V_298 [] = { 0 , 4 , 8 , 12 , 16 } ;
static const enum V_299 V_300 [] = {
V_301 ,
V_302 ,
V_303 ,
V_304 ,
V_305 ,
} ;
T_1 V_154 ;
int V_109 ;
V_154 = F_9 ( V_3 , V_275 ) ;
for ( V_109 = 0 ; V_109 < V_16 -> V_306 ; ++ V_109 ) {
unsigned V_307 = V_298 [ V_109 ] ;
unsigned V_308 , V_309 ;
unsigned V_33 ;
for ( V_33 = 0 ; V_33 < V_16 -> V_310 ; ++ V_33 )
if ( V_16 -> V_311 [ V_33 ] . V_312 == V_300 [ V_109 ] )
break;
if ( V_33 == V_16 -> V_310 )
return - V_152 ;
V_309 = V_33 ;
V_308 = V_16 -> V_311 [ V_33 ] . V_308 ;
V_154 = F_115 ( V_154 , V_309 + 1 , V_307 + 2 , V_307 ) ;
V_154 = F_115 ( V_154 , V_308 , V_307 + 3 , V_307 + 3 ) ;
}
for (; V_109 < V_16 -> V_310 ; ++ V_109 ) {
unsigned V_307 = V_298 [ V_109 ] ;
V_154 = F_115 ( V_154 , 0 , V_307 + 2 , V_307 ) ;
V_154 = F_115 ( V_154 , 0 , V_307 + 3 , V_307 + 3 ) ;
}
F_7 ( V_3 , V_275 , V_154 ) ;
return 0 ;
}
static inline unsigned F_141 ( struct V_2 * V_3 , unsigned V_313 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_314 = V_16 -> V_177 . V_180 / 4 ;
return ( V_313 * ( V_314 / 1000 / 1000 ) + 999 ) / 1000 ;
}
static inline unsigned F_142 ( struct V_2 * V_3 , unsigned V_315 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_314 = V_16 -> V_177 . V_180 / 4 ;
return V_315 * 1000 * 1000 / ( V_314 / 1000 ) ;
}
static void F_143 ( struct V_2 * V_3 )
{
T_1 V_154 ;
T_1 V_316 , V_317 , V_318 , V_319 ;
T_1 V_320 , V_321 , V_322 ;
T_1 V_323 ;
V_316 = F_141 ( V_3 , 70 ) + 2 ;
V_317 = F_141 ( V_3 , 175 ) + 2 ;
V_318 = F_141 ( V_3 , 60 ) + 5 ;
V_319 = F_141 ( V_3 , 145 ) ;
V_320 = F_141 ( V_3 , 25 ) ;
V_321 = F_141 ( V_3 , 60 ) + 2 ;
V_323 = F_141 ( V_3 , 65 ) ;
V_322 = F_141 ( V_3 , 260 ) ;
F_71 ( L_57 ,
V_316 , F_142 ( V_3 , V_316 ) ,
V_317 , F_142 ( V_3 , V_317 ) ) ;
F_71 ( L_58 ,
V_318 , F_142 ( V_3 , V_318 ) ,
V_319 , F_142 ( V_3 , V_319 ) ) ;
F_71 ( L_59
L_60 ,
V_320 , F_142 ( V_3 , V_320 ) ,
V_321 , F_142 ( V_3 , V_321 ) ,
V_322 , F_142 ( V_3 , V_322 ) ) ;
F_71 ( L_61 ,
V_323 , F_142 ( V_3 , V_323 ) ) ;
V_154 = F_9 ( V_3 , V_292 ) ;
V_154 = F_115 ( V_154 , V_316 , 31 , 24 ) ;
V_154 = F_115 ( V_154 , V_317 , 23 , 16 ) ;
V_154 = F_115 ( V_154 , V_318 , 15 , 8 ) ;
V_154 = F_115 ( V_154 , V_319 , 7 , 0 ) ;
F_7 ( V_3 , V_292 , V_154 ) ;
V_154 = F_9 ( V_3 , V_293 ) ;
V_154 = F_115 ( V_154 , V_320 , 20 , 16 ) ;
V_154 = F_115 ( V_154 , V_321 , 15 , 8 ) ;
V_154 = F_115 ( V_154 , V_322 , 7 , 0 ) ;
if ( F_84 ( V_324 ) ) {
V_154 = F_115 ( V_154 , 0 , 21 , 21 ) ;
V_154 = F_115 ( V_154 , 1 , 22 , 22 ) ;
V_154 = F_115 ( V_154 , 1 , 23 , 23 ) ;
}
F_7 ( V_3 , V_293 , V_154 ) ;
V_154 = F_9 ( V_3 , V_294 ) ;
V_154 = F_115 ( V_154 , V_323 , 7 , 0 ) ;
F_7 ( V_3 , V_294 , V_154 ) ;
}
static void F_144 ( struct V_2 * V_3 ,
unsigned V_325 , unsigned V_326 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
T_1 V_166 ;
T_4 V_327 = V_16 -> V_310 == 3 ? 22 : 26 ;
V_166 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 ) {
unsigned V_328 = V_16 -> V_311 [ V_109 ] . V_308 ;
if ( V_325 & ( 1 << V_109 ) )
V_166 |= 1 << ( V_109 * 2 + ( V_328 ? 0 : 1 ) ) ;
if ( V_326 & ( 1 << V_109 ) )
V_166 |= 1 << ( V_109 * 2 + ( V_328 ? 1 : 0 ) ) ;
}
F_87 ( V_3 , V_329 , V_166 , V_327 , 17 ) ;
F_87 ( V_3 , V_329 , 1 , 27 , 27 ) ;
}
static void F_145 ( struct V_2 * V_3 )
{
F_87 ( V_3 , V_329 , 0 , 27 , 27 ) ;
F_87 ( V_3 , V_329 , 0 , 22 , 17 ) ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_33 , V_109 ;
bool V_330 [ V_331 ] ;
static const T_4 V_332 [] = { 28 , 27 , 26 } ;
static const T_4 V_333 [] = { 24 , 25 , 26 , 27 , 28 } ;
const T_4 * V_298 ;
if ( F_84 ( V_171 ) )
V_298 = V_332 ;
else
V_298 = V_333 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 )
V_330 [ V_109 ] = V_16 -> V_311 [ V_109 ] . V_312 != V_334 ;
V_33 = 100000 ;
while ( true ) {
T_1 V_166 ;
int V_335 ;
V_166 = F_9 ( V_3 , V_170 ) ;
V_335 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 ) {
if ( ! V_330 [ V_109 ] || ( V_166 & ( 1 << V_298 [ V_109 ] ) ) )
V_335 ++ ;
}
if ( V_335 == V_16 -> V_310 )
break;
if ( -- V_33 == 0 ) {
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 ) {
if ( ! V_330 [ V_109 ] || ( V_166 & ( 1 << V_298 [ V_109 ] ) ) )
continue;
F_44 ( L_62 \
L_63 , V_109 ) ;
}
return - V_176 ;
}
}
return 0 ;
}
static unsigned F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_27 = 0 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 ) {
if ( V_16 -> V_311 [ V_109 ] . V_312 != V_334 )
V_27 |= 1 << V_109 ;
}
return V_27 ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
T_1 V_166 ;
F_71 ( L_64 ) ;
V_154 = F_149 ( V_16 -> V_181 , F_147 ( V_3 ) ) ;
if ( V_154 )
return V_154 ;
F_97 ( V_3 ) ;
F_9 ( V_3 , V_170 ) ;
if ( F_18 ( V_3 , V_170 , 30 , 1 ) != 1 ) {
F_44 ( L_65 ) ;
V_154 = - V_176 ;
goto V_336;
}
V_154 = F_140 ( V_3 ) ;
if ( V_154 )
goto V_336;
V_166 = F_9 ( V_3 , V_276 ) ;
V_166 = F_115 ( V_166 , 1 , 15 , 15 ) ;
V_166 = F_115 ( V_166 , 1 , 14 , 14 ) ;
V_166 = F_115 ( V_166 , 1 , 13 , 13 ) ;
V_166 = F_115 ( V_166 , 0x1fff , 12 , 0 ) ;
F_7 ( V_3 , V_276 , V_166 ) ;
if ( V_16 -> V_337 ) {
unsigned V_325 ;
int V_109 ;
F_71 ( L_66 ) ;
V_325 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 ) {
if ( V_16 -> V_311 [ V_109 ] . V_312 == V_334 )
continue;
V_325 |= 1 << V_109 ;
}
F_144 ( V_3 , V_325 , 0 ) ;
}
V_154 = F_138 ( V_3 , V_338 ) ;
if ( V_154 )
goto V_339;
if ( F_18 ( V_3 , V_275 , 29 , 1 ) != 1 ) {
F_44 ( L_67 ) ;
V_154 = - V_200 ;
goto V_340;
}
F_86 ( V_3 , true ) ;
F_86 ( V_3 , false ) ;
F_87 ( V_3 , V_193 , 1 , 20 , 20 ) ;
V_154 = F_146 ( V_3 ) ;
if ( V_154 )
goto V_341;
if ( V_16 -> V_337 ) {
T_3 V_32 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_35 ) ;
F_24 ( & V_32 , V_36 ) ;
F_145 ( V_3 ) ;
}
F_87 ( V_3 , V_276 , 0 , 15 , 15 ) ;
F_143 ( V_3 ) ;
if ( V_16 -> V_342 == V_343 ) {
F_87 ( V_3 , V_193 ,
V_16 -> V_344 . V_345 , 13 , 13 ) ;
}
V_16 -> V_337 = false ;
F_71 ( L_68 ) ;
return 0 ;
V_341:
F_87 ( V_3 , V_193 , 0 , 20 , 20 ) ;
V_340:
F_138 ( V_3 , V_346 ) ;
V_339:
if ( V_16 -> V_337 )
F_145 ( V_3 ) ;
V_336:
F_98 ( V_3 ) ;
F_150 ( V_16 -> V_181 , F_147 ( V_3 ) ) ;
return V_154 ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_87 ( V_3 , V_193 , 0 , 13 , 13 ) ;
F_138 ( V_3 , V_346 ) ;
F_98 ( V_3 ) ;
F_150 ( V_16 -> V_181 , F_147 ( V_3 ) ) ;
}
static void F_152 ( struct V_2 * V_3 ,
enum V_347 V_348 , enum V_347 V_349 ,
enum V_347 V_350 , enum V_347 V_351 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 = 0 ;
int V_352 = 0 ;
int V_109 ;
V_16 -> V_148 [ 0 ] . V_353 = V_348 ;
V_16 -> V_148 [ 1 ] . V_353 = V_349 ;
V_16 -> V_148 [ 2 ] . V_353 = V_350 ;
V_16 -> V_148 [ 3 ] . V_353 = V_351 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ ) {
T_4 V_354 ;
int V_355 = V_16 -> V_148 [ V_109 ] . V_353 ;
if ( V_352 + V_355 > 4 ) {
F_44 ( L_69 ) ;
F_26 () ;
return;
}
V_354 = F_153 ( V_352 , 2 , 0 ) | F_153 ( V_355 , 7 , 4 ) ;
V_154 |= V_354 << ( 8 * V_109 ) ;
V_352 += V_355 ;
}
F_7 ( V_3 , V_282 , V_154 ) ;
}
static void F_154 ( struct V_2 * V_3 ,
enum V_347 V_348 , enum V_347 V_349 ,
enum V_347 V_350 , enum V_347 V_351 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 = 0 ;
int V_352 = 0 ;
int V_109 ;
V_16 -> V_148 [ 0 ] . V_356 = V_348 ;
V_16 -> V_148 [ 1 ] . V_356 = V_349 ;
V_16 -> V_148 [ 2 ] . V_356 = V_350 ;
V_16 -> V_148 [ 3 ] . V_356 = V_351 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ ) {
T_4 V_354 ;
int V_355 = V_16 -> V_148 [ V_109 ] . V_356 ;
if ( V_352 + V_355 > 4 ) {
F_44 ( L_69 ) ;
F_26 () ;
return;
}
V_354 = F_153 ( V_352 , 2 , 0 ) | F_153 ( V_355 , 7 , 4 ) ;
V_154 |= V_354 << ( 8 * V_109 ) ;
V_352 += V_355 ;
}
F_7 ( V_3 , V_283 , V_154 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_276 ) ;
V_154 = F_115 ( V_154 , 1 , 15 , 15 ) ;
F_7 ( V_3 , V_276 , V_154 ) ;
if ( F_18 ( V_3 , V_276 , 15 , 0 ) != 0 ) {
F_44 ( L_70 ) ;
return - V_176 ;
}
return 0 ;
}
static bool F_156 ( struct V_2 * V_3 , int V_75 )
{
return F_19 ( V_3 , F_131 ( V_75 ) , 0 , 0 ) ;
}
static void F_157 ( void * V_26 , T_1 V_27 )
{
struct V_357 * V_358 =
(struct V_357 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_358 -> V_3 ) ;
const int V_75 = V_16 -> V_359 ;
T_4 V_360 = V_16 -> V_361 ? 30 : 31 ;
if ( F_19 ( V_358 -> V_3 , F_132 ( V_75 ) , V_360 , V_360 ) == 0 )
F_17 ( V_358 -> V_28 ) ;
}
static int F_158 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_159 ( V_28 ) ;
struct V_357 V_358 = { V_3 , & V_28 } ;
int V_154 = 0 ;
T_4 V_360 ;
V_360 = V_16 -> V_361 ? 30 : 31 ;
V_154 = F_65 ( V_3 , V_75 , F_157 ,
& V_358 , V_76 ) ;
if ( V_154 )
goto V_255;
if ( F_19 ( V_3 , F_132 ( V_75 ) , V_360 , V_360 ) ) {
if ( F_160 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_71 ) ;
V_154 = - V_176 ;
goto V_256;
}
}
F_66 ( V_3 , V_75 , F_157 ,
& V_358 , V_76 ) ;
return 0 ;
V_256:
F_66 ( V_3 , V_75 , F_157 ,
& V_358 , V_76 ) ;
V_255:
return V_154 ;
}
static void F_161 ( void * V_26 , T_1 V_27 )
{
struct V_357 * V_362 =
(struct V_357 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_362 -> V_3 ) ;
const int V_75 = V_16 -> V_359 ;
if ( F_19 ( V_362 -> V_3 , F_131 ( V_75 ) , 5 , 5 ) == 0 )
F_17 ( V_362 -> V_28 ) ;
}
static int F_162 ( struct V_2 * V_3 , int V_75 )
{
F_159 ( V_28 ) ;
struct V_357 V_362 = { V_3 , & V_28 } ;
int V_154 = 0 ;
V_154 = F_65 ( V_3 , V_75 , F_161 ,
& V_362 , V_76 ) ;
if ( V_154 )
goto V_255;
if ( F_19 ( V_3 , F_131 ( V_75 ) , 5 , 5 ) ) {
if ( F_160 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_72 ) ;
V_154 = - V_176 ;
goto V_256;
}
}
F_66 ( V_3 , V_75 , F_161 ,
& V_362 , V_76 ) ;
return 0 ;
V_256:
F_66 ( V_3 , V_75 , F_161 ,
& V_362 , V_76 ) ;
V_255:
return V_154 ;
}
static int F_163 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( F_164 () ) ;
if ( ! F_156 ( V_3 , V_75 ) )
return 0 ;
switch ( V_16 -> V_148 [ V_75 ] . V_363 ) {
case V_364 :
return F_158 ( V_3 , V_75 ) ;
case V_365 :
return F_162 ( V_3 , V_75 ) ;
default:
F_26 () ;
return - V_152 ;
}
}
static int F_165 ( struct V_2 * V_3 , int V_75 ,
bool V_162 )
{
F_71 ( L_73 ,
V_75 , V_162 ) ;
V_162 = V_162 ? 1 : 0 ;
F_87 ( V_3 , F_131 ( V_75 ) , V_162 , 0 , 0 ) ;
if ( F_18 ( V_3 , F_131 ( V_75 ) ,
0 , V_162 ) != V_162 ) {
F_44 ( L_74 , V_162 ) ;
return - V_176 ;
}
return 0 ;
}
static void F_166 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 ;
F_71 ( L_75 , V_75 ) ;
V_154 = F_9 ( V_3 , F_131 ( V_75 ) ) ;
if ( F_100 ( V_154 , 15 , 15 ) )
F_44 ( L_76 ,
V_75 ) ;
V_154 = F_115 ( V_154 , 0 , 1 , 1 ) ;
V_154 = F_115 ( V_154 , 0 , 2 , 2 ) ;
V_154 = F_115 ( V_154 , 0 , 3 , 3 ) ;
V_154 = F_115 ( V_154 , 0 , 4 , 4 ) ;
V_154 = F_115 ( V_154 , 1 , 7 , 7 ) ;
V_154 = F_115 ( V_154 , 1 , 8 , 8 ) ;
V_154 = F_115 ( V_154 , 0 , 9 , 9 ) ;
if ( F_84 ( V_366 ) )
V_154 = F_115 ( V_154 , 3 , 11 , 10 ) ;
V_154 = F_115 ( V_154 , 4 , 29 , 27 ) ;
V_154 = F_115 ( V_154 , 4 , 23 , 21 ) ;
F_7 ( V_3 , F_131 ( V_75 ) , V_154 ) ;
V_16 -> V_148 [ V_75 ] . V_363 = V_365 ;
}
static int F_167 ( struct V_2 * V_3 , int V_75 ,
enum V_367 V_363 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_148 [ V_75 ] . V_363 == V_363 )
return 0 ;
F_71 ( L_77 , V_75 ) ;
F_163 ( V_3 , V_75 ) ;
F_165 ( V_3 , V_75 , 0 ) ;
if ( F_18 ( V_3 , F_131 ( V_75 ) , 15 , 0 ) != 0 ) {
F_44 ( L_78 , V_75 ) ;
return - V_176 ;
}
F_87 ( V_3 , F_131 ( V_75 ) , V_363 , 1 , 1 ) ;
if ( F_84 ( V_368 ) ) {
bool V_162 = V_363 == V_364 ;
F_87 ( V_3 , F_131 ( V_75 ) , V_162 , 30 , 30 ) ;
}
F_165 ( V_3 , V_75 , 1 ) ;
V_16 -> V_148 [ V_75 ] . V_363 = V_363 ;
return 0 ;
}
static void F_168 ( struct V_5 * V_6 , int V_75 ,
bool V_162 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_79 , V_75 , V_162 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_165 ( V_3 , V_75 , 0 ) ;
F_86 ( V_3 , 0 ) ;
F_87 ( V_3 , F_131 ( V_75 ) , V_162 , 9 , 9 ) ;
F_165 ( V_3 , V_75 , 1 ) ;
F_86 ( V_3 , 1 ) ;
F_155 ( V_3 ) ;
if ( V_16 -> V_344 . V_345 && V_162 )
F_169 ( V_6 , V_75 ) ;
}
static void F_170 ( struct V_2 * V_3 , int V_75 )
{
while ( F_19 ( V_3 , F_131 ( V_75 ) , 20 , 20 ) ) {
T_1 V_15 ;
V_15 = F_9 ( V_3 , F_135 ( V_75 ) ) ;
F_71 ( L_80 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
}
}
static void F_171 ( T_13 V_250 )
{
F_44 ( L_81 , V_250 ) ;
if ( V_250 & ( 1 << 0 ) )
F_44 ( L_82 ) ;
if ( V_250 & ( 1 << 1 ) )
F_44 ( L_83 ) ;
if ( V_250 & ( 1 << 2 ) )
F_44 ( L_84 ) ;
if ( V_250 & ( 1 << 3 ) )
F_44 ( L_85 ) ;
if ( V_250 & ( 1 << 4 ) )
F_44 ( L_86 ) ;
if ( V_250 & ( 1 << 5 ) )
F_44 ( L_87 ) ;
if ( V_250 & ( 1 << 6 ) )
F_44 ( L_88 ) ;
if ( V_250 & ( 1 << 7 ) )
F_44 ( L_89 ) ;
if ( V_250 & ( 1 << 8 ) )
F_44 ( L_90 ) ;
if ( V_250 & ( 1 << 9 ) )
F_44 ( L_91 ) ;
if ( V_250 & ( 1 << 10 ) )
F_44 ( L_92 ) ;
if ( V_250 & ( 1 << 11 ) )
F_44 ( L_93 ) ;
if ( V_250 & ( 1 << 12 ) )
F_44 ( L_94 ) ;
if ( V_250 & ( 1 << 13 ) )
F_44 ( L_95 ) ;
if ( V_250 & ( 1 << 14 ) )
F_44 ( L_96 ) ;
if ( V_250 & ( 1 << 15 ) )
F_44 ( L_97 ) ;
}
static T_13 F_172 ( struct V_2 * V_3 ,
int V_75 )
{
while ( F_19 ( V_3 , F_131 ( V_75 ) , 20 , 20 ) ) {
T_1 V_15 ;
T_4 V_369 ;
V_15 = F_9 ( V_3 , F_135 ( V_75 ) ) ;
F_44 ( L_98 , V_15 ) ;
V_369 = F_100 ( V_15 , 5 , 0 ) ;
if ( V_369 == V_370 ) {
T_13 V_250 = F_100 ( V_15 , 23 , 8 ) ;
F_171 ( V_250 ) ;
} else if ( V_369 == V_371 ) {
F_44 ( L_99 ,
F_100 ( V_15 , 23 , 8 ) ) ;
} else if ( V_369 == V_372 ) {
F_44 ( L_100 ,
F_100 ( V_15 , 23 , 8 ) ) ;
} else if ( V_369 == V_373 ) {
F_44 ( L_101 ,
F_100 ( V_15 , 23 , 8 ) ) ;
F_170 ( V_3 , V_75 ) ;
} else {
F_44 ( L_102 , V_369 ) ;
}
}
return 0 ;
}
static int F_173 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_374 || V_16 -> V_375 )
F_71 ( L_103 , V_75 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( F_19 ( V_3 , F_131 ( V_75 ) , 20 , 20 ) ) {
F_44 ( L_104 ) ;
F_172 ( V_3 , V_75 ) ;
}
F_87 ( V_3 , F_131 ( V_75 ) , 1 , 6 , 6 ) ;
F_9 ( V_3 , F_131 ( V_75 ) ) ;
return 0 ;
}
static int F_174 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
F_159 ( V_28 ) ;
int V_154 = 0 ;
T_1 V_250 ;
V_154 = F_65 ( V_3 , V_75 , F_16 ,
& V_28 , V_376 ) ;
if ( V_154 )
goto V_255;
V_154 = F_63 ( V_3 , F_16 , & V_28 ,
V_116 ) ;
if ( V_154 )
goto V_256;
V_154 = F_173 ( V_3 , V_75 ) ;
if ( V_154 )
goto V_377;
if ( F_160 ( & V_28 ,
F_20 ( 500 ) ) == 0 ) {
F_44 ( L_105 ) ;
V_154 = - V_176 ;
goto V_377;
}
V_250 = F_69 ( V_3 ) ;
if ( V_250 ) {
F_44 ( L_106 , V_250 ) ;
V_154 = - V_176 ;
goto V_377;
}
V_377:
F_64 ( V_3 , F_16 , & V_28 ,
V_116 ) ;
V_256:
F_66 ( V_3 , V_75 , F_16 ,
& V_28 , V_376 ) ;
V_255:
return V_154 ;
}
static inline void F_175 ( struct V_2 * V_3 ,
int V_75 , T_4 V_378 , T_13 V_379 , T_4 V_380 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_381 ;
F_73 ( ! F_15 ( V_3 ) ) ;
V_381 = V_378 | V_16 -> V_148 [ V_75 ] . V_382 << 6 ;
V_15 = F_153 ( V_381 , 7 , 0 ) | F_153 ( V_379 , 23 , 8 ) |
F_153 ( V_380 , 31 , 24 ) ;
F_7 ( V_3 , F_133 ( V_75 ) , V_15 ) ;
}
static inline void F_176 ( struct V_2 * V_3 ,
int V_75 , T_4 V_168 , T_4 V_169 , T_4 V_383 , T_4 V_384 )
{
T_1 V_15 ;
V_15 = V_384 << 24 | V_383 << 16 | V_169 << 8 | V_168 << 0 ;
F_7 ( V_3 , F_134 ( V_75 ) , V_15 ) ;
}
static int F_177 ( struct V_2 * V_3 , int V_75 ,
T_4 V_378 , T_4 * V_26 , T_13 V_379 , T_4 V_380 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
T_4 * V_328 ;
int V_154 = 0 ;
T_4 V_168 , V_169 , V_383 , V_384 ;
if ( V_16 -> V_374 )
F_71 ( L_107 , V_379 ) ;
if ( V_16 -> V_148 [ V_75 ] . V_353 * 32 * 4 < V_379 + 4 ) {
F_44 ( L_108 ) ;
return - V_152 ;
}
F_167 ( V_3 , V_75 , V_365 ) ;
F_175 ( V_3 , V_75 , V_378 , V_379 , V_380 ) ;
V_328 = V_26 ;
for ( V_109 = 0 ; V_109 < V_379 > > 2 ; V_109 ++ ) {
if ( V_16 -> V_374 )
F_71 ( L_109 , V_109 ) ;
V_168 = * V_328 ++ ;
V_169 = * V_328 ++ ;
V_383 = * V_328 ++ ;
V_384 = * V_328 ++ ;
F_176 ( V_3 , V_75 , V_168 , V_169 , V_383 , V_384 ) ;
}
V_109 = V_379 % 4 ;
if ( V_109 ) {
V_168 = 0 ; V_169 = 0 ; V_383 = 0 ;
if ( V_16 -> V_374 )
F_71 ( L_110 , V_109 ) ;
switch ( V_109 ) {
case 3 :
V_168 = * V_328 ++ ;
V_169 = * V_328 ++ ;
V_383 = * V_328 ++ ;
break;
case 2 :
V_168 = * V_328 ++ ;
V_169 = * V_328 ++ ;
break;
case 1 :
V_168 = * V_328 ++ ;
break;
}
F_176 ( V_3 , V_75 , V_168 , V_169 , V_383 , 0 ) ;
}
return V_154 ;
}
static int F_178 ( struct V_2 * V_3 , int V_75 ,
T_4 V_378 , T_13 V_26 , T_4 V_380 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 ;
T_4 V_381 ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( V_16 -> V_374 )
F_71 ( L_111 ,
V_75 ,
V_378 , V_26 & 0xff , ( V_26 >> 8 ) & 0xff ) ;
F_167 ( V_3 , V_75 , V_365 ) ;
if ( F_100 ( F_9 ( V_3 , F_131 ( V_75 ) ) , 16 , 16 ) ) {
F_44 ( L_112 ) ;
return - V_152 ;
}
V_381 = V_378 | V_16 -> V_148 [ V_75 ] . V_382 << 6 ;
V_154 = ( V_381 << 0 ) | ( V_26 << 8 ) | ( V_380 << 24 ) ;
F_7 ( V_3 , F_135 ( V_75 ) , V_154 ) ;
return 0 ;
}
static int F_169 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_177 ( V_3 , V_75 , V_385 , NULL ,
0 , 0 ) ;
}
static int F_179 ( struct V_2 * V_3 ,
int V_75 , T_4 * V_26 , int V_379 , enum V_386 type )
{
int V_154 ;
if ( V_379 == 0 ) {
F_61 ( type == V_387 ) ;
V_154 = F_178 ( V_3 , V_75 ,
V_388 , 0 , 0 ) ;
} else if ( V_379 == 1 ) {
V_154 = F_178 ( V_3 , V_75 ,
type == V_389 ?
V_390 :
V_391 , V_26 [ 0 ] , 0 ) ;
} else if ( V_379 == 2 ) {
V_154 = F_178 ( V_3 , V_75 ,
type == V_389 ?
V_392 :
V_393 ,
V_26 [ 0 ] | ( V_26 [ 1 ] << 8 ) , 0 ) ;
} else {
V_154 = F_177 ( V_3 , V_75 ,
type == V_389 ?
V_394 :
V_395 , V_26 , V_379 , 0 ) ;
}
return V_154 ;
}
static int F_180 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_379 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_179 ( V_3 , V_75 , V_26 , V_379 ,
V_387 ) ;
}
static int F_181 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_379 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_179 ( V_3 , V_75 , V_26 , V_379 ,
V_389 ) ;
}
static int F_182 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_379 , enum V_386 type )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_154 ;
V_154 = F_179 ( V_3 , V_75 , V_26 , V_379 , type ) ;
if ( V_154 )
goto V_250;
V_154 = F_174 ( V_6 , V_75 ) ;
if ( V_154 )
goto V_250;
if ( F_19 ( V_3 , F_131 ( V_75 ) , 20 , 20 ) ) {
F_44 ( L_113 ) ;
F_172 ( V_3 , V_75 ) ;
V_154 = - V_176 ;
goto V_250;
}
return 0 ;
V_250:
F_44 ( L_114 ,
V_75 , V_26 [ 0 ] , V_379 ) ;
return V_154 ;
}
static int F_183 ( struct V_5 * V_6 , int V_75 , T_4 * V_26 ,
int V_379 )
{
return F_182 ( V_6 , V_75 , V_26 , V_379 ,
V_387 ) ;
}
static int F_184 ( struct V_5 * V_6 , int V_75 , T_4 * V_26 ,
int V_379 )
{
return F_182 ( V_6 , V_75 , V_26 , V_379 ,
V_389 ) ;
}
static int F_185 ( struct V_2 * V_3 ,
int V_75 , T_4 V_396 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
if ( V_16 -> V_375 )
F_71 ( L_115 ,
V_75 , V_396 ) ;
V_154 = F_178 ( V_3 , V_75 , V_397 , V_396 , 0 ) ;
if ( V_154 ) {
F_44 ( L_116
L_117 , V_75 , V_396 ) ;
return V_154 ;
}
return 0 ;
}
static int F_186 ( struct V_2 * V_3 ,
int V_75 , T_4 * V_398 , int V_399 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_13 V_26 ;
T_4 V_378 ;
int V_154 ;
if ( V_16 -> V_375 )
F_71 ( L_118 ,
V_75 , V_399 ) ;
if ( V_399 == 0 ) {
V_378 = V_400 ;
V_26 = 0 ;
} else if ( V_399 == 1 ) {
V_378 = V_401 ;
V_26 = V_398 [ 0 ] ;
} else if ( V_399 == 2 ) {
V_378 = V_402 ;
V_26 = V_398 [ 0 ] | ( V_398 [ 1 ] << 8 ) ;
} else {
F_26 () ;
return - V_152 ;
}
V_154 = F_178 ( V_3 , V_75 , V_378 , V_26 , 0 ) ;
if ( V_154 ) {
F_44 ( L_119
L_117 , V_75 , V_399 ) ;
return V_154 ;
}
return 0 ;
}
static int F_187 ( struct V_2 * V_3 , int V_75 ,
T_4 * V_403 , int V_404 , enum V_386 type )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_369 ;
int V_154 ;
if ( F_19 ( V_3 , F_131 ( V_75 ) , 20 , 20 ) == 0 ) {
F_44 ( L_120 ) ;
V_154 = - V_176 ;
goto V_250;
}
V_15 = F_9 ( V_3 , F_135 ( V_75 ) ) ;
if ( V_16 -> V_375 )
F_71 ( L_121 , V_15 ) ;
V_369 = F_100 ( V_15 , 5 , 0 ) ;
if ( V_369 == V_370 ) {
T_13 V_250 = F_100 ( V_15 , 23 , 8 ) ;
F_171 ( V_250 ) ;
V_154 = - V_176 ;
goto V_250;
} else if ( V_369 == ( type == V_389 ?
V_405 :
V_371 ) ) {
T_4 V_26 = F_100 ( V_15 , 15 , 8 ) ;
if ( V_16 -> V_375 )
F_71 ( L_122 ,
type == V_389 ? L_123 :
L_124 , V_26 ) ;
if ( V_404 < 1 ) {
V_154 = - V_176 ;
goto V_250;
}
V_403 [ 0 ] = V_26 ;
return 1 ;
} else if ( V_369 == ( type == V_389 ?
V_406 :
V_372 ) ) {
T_13 V_26 = F_100 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_375 )
F_71 ( L_125 ,
type == V_389 ? L_123 :
L_124 , V_26 ) ;
if ( V_404 < 2 ) {
V_154 = - V_176 ;
goto V_250;
}
V_403 [ 0 ] = V_26 & 0xff ;
V_403 [ 1 ] = ( V_26 >> 8 ) & 0xff ;
return 2 ;
} else if ( V_369 == ( type == V_389 ?
V_407 :
V_373 ) ) {
int V_408 ;
int V_379 = F_100 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_375 )
F_71 ( L_126 ,
type == V_389 ? L_123 :
L_124 , V_379 ) ;
if ( V_379 > V_404 ) {
V_154 = - V_176 ;
goto V_250;
}
for ( V_408 = 0 ; V_408 < V_379 + 2 ; ) {
int V_409 ;
V_15 = F_9 ( V_3 ,
F_135 ( V_75 ) ) ;
if ( V_16 -> V_375 )
F_71 ( L_127 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
for ( V_409 = 0 ; V_409 < 4 ; ++ V_409 ) {
if ( V_408 < V_379 )
V_403 [ V_408 ] = ( V_15 >> ( V_409 * 8 ) ) & 0xff ;
++ V_408 ;
}
}
return V_379 ;
} else {
F_44 ( L_102 , V_369 ) ;
V_154 = - V_176 ;
goto V_250;
}
V_250:
F_44 ( L_128 , V_75 ,
type == V_389 ? L_123 : L_124 ) ;
return V_154 ;
}
static int F_188 ( struct V_5 * V_6 , int V_75 , T_4 V_396 ,
T_4 * V_403 , int V_404 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_154 ;
V_154 = F_185 ( V_3 , V_75 , V_396 ) ;
if ( V_154 )
goto V_250;
V_154 = F_174 ( V_6 , V_75 ) ;
if ( V_154 )
goto V_250;
V_154 = F_187 ( V_3 , V_75 , V_403 , V_404 ,
V_387 ) ;
if ( V_154 < 0 )
goto V_250;
if ( V_154 != V_404 ) {
V_154 = - V_176 ;
goto V_250;
}
return 0 ;
V_250:
F_44 ( L_129 , V_75 , V_396 ) ;
return V_154 ;
}
static int F_189 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_398 , int V_399 , T_4 * V_403 , int V_404 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_154 ;
V_154 = F_186 ( V_3 , V_75 , V_398 , V_399 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_174 ( V_6 , V_75 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_187 ( V_3 , V_75 , V_403 , V_404 ,
V_389 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( V_154 != V_404 ) {
V_154 = - V_176 ;
return V_154 ;
}
return 0 ;
}
static int F_190 ( struct V_5 * V_6 , int V_75 ,
T_13 V_379 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_178 ( V_3 , V_75 ,
V_410 , V_379 , 0 ) ;
}
static int F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_159 ( V_28 ) ;
int V_154 , V_109 ;
unsigned V_27 ;
F_71 ( L_130 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( V_16 -> V_337 ) ;
if ( V_16 -> V_337 )
return 0 ;
if ( F_19 ( V_3 , V_193 , 13 , 13 ) ) {
F_86 ( V_3 , 0 ) ;
F_87 ( V_3 , V_193 , 0 , 13 , 13 ) ;
F_86 ( V_3 , 1 ) ;
}
F_163 ( V_3 , 0 ) ;
F_163 ( V_3 , 1 ) ;
F_163 ( V_3 , 2 ) ;
F_163 ( V_3 , 3 ) ;
F_155 ( V_3 ) ;
F_165 ( V_3 , 0 , false ) ;
F_165 ( V_3 , 1 , false ) ;
F_165 ( V_3 , 2 , false ) ;
F_165 ( V_3 , 3 , false ) ;
if ( F_19 ( V_3 , V_284 , 16 , 16 ) ) {
F_44 ( L_131 ) ;
return - V_176 ;
}
if ( F_19 ( V_3 , V_284 , 17 , 17 ) ) {
F_44 ( L_132 ) ;
return - V_176 ;
}
V_154 = F_67 ( V_3 , F_16 , & V_28 ,
V_411 ) ;
if ( V_154 )
return V_154 ;
V_27 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_310 ; ++ V_109 ) {
if ( V_16 -> V_311 [ V_109 ] . V_312 == V_334 )
continue;
V_27 |= 1 << V_109 ;
}
F_87 ( V_3 , V_284 , V_27 , 9 , 5 ) ;
F_9 ( V_3 , V_284 ) ;
if ( F_160 ( & V_28 ,
F_20 ( 1000 ) ) == 0 ) {
F_44 ( L_133 ) ;
V_154 = - V_176 ;
goto V_250;
}
F_68 ( V_3 , F_16 , & V_28 ,
V_411 ) ;
F_87 ( V_3 , V_284 , 0 , 9 , 5 ) ;
F_9 ( V_3 , V_284 ) ;
F_138 ( V_3 , V_412 ) ;
F_86 ( V_3 , false ) ;
V_16 -> V_337 = true ;
return 0 ;
V_250:
F_68 ( V_3 , F_16 , & V_28 ,
V_411 ) ;
return V_154 ;
}
static void F_192 ( struct V_2 * V_3 ,
unsigned V_413 , bool V_414 , bool V_415 )
{
unsigned long V_416 ;
unsigned long V_417 ;
T_1 V_154 ;
F_61 ( V_413 > 0x1fff ) ;
V_416 = F_91 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_277 ) ;
V_154 = F_115 ( V_154 , 1 , 15 , 15 ) ;
V_154 = F_115 ( V_154 , V_415 ? 1 : 0 , 14 , 14 ) ;
V_154 = F_115 ( V_154 , V_414 ? 1 : 0 , 13 , 13 ) ;
V_154 = F_115 ( V_154 , V_413 , 12 , 0 ) ;
F_7 ( V_3 , V_277 , V_154 ) ;
V_417 = V_413 * ( V_415 ? 16 : 1 ) * ( V_414 ? 4 : 1 ) ;
F_71 ( L_134 ,
V_417 ,
V_413 , V_414 ? L_135 : L_4 , V_415 ? L_136 : L_4 ,
( V_417 * 1000 ) / ( V_416 / 1000 / 1000 ) ) ;
}
static void F_193 ( struct V_2 * V_3 , unsigned V_413 ,
bool V_418 , bool V_415 )
{
unsigned long V_416 ;
unsigned long V_417 ;
T_1 V_154 ;
F_61 ( V_413 > 0x1fff ) ;
V_416 = F_91 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_276 ) ;
V_154 = F_115 ( V_154 , 1 , 31 , 31 ) ;
V_154 = F_115 ( V_154 , V_415 ? 1 : 0 , 30 , 30 ) ;
V_154 = F_115 ( V_154 , V_418 ? 1 : 0 , 29 , 29 ) ;
V_154 = F_115 ( V_154 , V_413 , 28 , 16 ) ;
F_7 ( V_3 , V_276 , V_154 ) ;
V_417 = V_413 * ( V_415 ? 16 : 1 ) * ( V_418 ? 8 : 1 ) ;
F_71 ( L_137 ,
V_417 ,
V_413 , V_418 ? L_138 : L_4 , V_415 ? L_136 : L_4 ,
( V_417 * 1000 ) / ( V_416 / 1000 / 1000 ) ) ;
}
static void F_194 ( struct V_2 * V_3 ,
unsigned V_413 , bool V_414 , bool V_415 )
{
unsigned long V_416 ;
unsigned long V_417 ;
T_1 V_154 ;
F_61 ( V_413 > 0x1fff ) ;
V_416 = F_91 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_276 ) ;
V_154 = F_115 ( V_154 , 1 , 15 , 15 ) ;
V_154 = F_115 ( V_154 , V_415 ? 1 : 0 , 14 , 14 ) ;
V_154 = F_115 ( V_154 , V_414 ? 1 : 0 , 13 , 13 ) ;
V_154 = F_115 ( V_154 , V_413 , 12 , 0 ) ;
F_7 ( V_3 , V_276 , V_154 ) ;
V_417 = V_413 * ( V_415 ? 16 : 1 ) * ( V_414 ? 4 : 1 ) ;
F_71 ( L_139 ,
V_417 ,
V_413 , V_414 ? L_135 : L_4 , V_415 ? L_136 : L_4 ,
( V_417 * 1000 ) / ( V_416 / 1000 / 1000 ) ) ;
}
static void F_195 ( struct V_2 * V_3 ,
unsigned V_413 , bool V_414 , bool V_415 )
{
unsigned long V_416 ;
unsigned long V_417 ;
T_1 V_154 ;
F_61 ( V_413 > 0x1fff ) ;
V_416 = F_90 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_277 ) ;
V_154 = F_115 ( V_154 , 1 , 31 , 31 ) ;
V_154 = F_115 ( V_154 , V_415 ? 1 : 0 , 30 , 30 ) ;
V_154 = F_115 ( V_154 , V_414 ? 1 : 0 , 29 , 29 ) ;
V_154 = F_115 ( V_154 , V_413 , 28 , 16 ) ;
F_7 ( V_3 , V_277 , V_154 ) ;
V_417 = V_413 * ( V_415 ? 16 : 1 ) * ( V_414 ? 4 : 1 ) ;
F_71 ( L_140 ,
V_417 ,
V_413 , V_414 ? L_135 : L_4 , V_415 ? L_136 : L_4 ,
( V_417 * 1000 ) / ( V_416 / 1000 / 1000 ) ) ;
}
static void F_196 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_419 ;
if ( V_16 -> V_342 == V_343 ) {
int V_420 = F_25 ( V_16 -> V_421 ) ;
struct V_422 * V_423 = & V_16 -> V_423 ;
if ( V_16 -> V_424 <= V_423 -> V_425 * V_420 / 8 )
V_419 = 0 ;
else
V_419 = 2 ;
} else {
V_419 = 2 ;
}
F_87 ( V_3 , V_175 , V_419 , 13 , 12 ) ;
}
static void F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
bool V_426 ;
T_1 V_154 ;
if ( V_16 -> V_344 . V_427 == V_428 )
V_426 = true ;
else
V_426 = false ;
V_154 = F_9 ( V_3 , V_175 ) ;
V_154 = F_115 ( V_154 , 1 , 9 , 9 ) ;
V_154 = F_115 ( V_154 , 1 , 10 , 10 ) ;
V_154 = F_115 ( V_154 , 1 , 11 , 11 ) ;
V_154 = F_115 ( V_154 , 1 , 15 , 15 ) ;
V_154 = F_115 ( V_154 , V_426 , 16 , 16 ) ;
V_154 = F_115 ( V_154 , 1 , 17 , 17 ) ;
V_154 = F_115 ( V_154 , V_426 , 18 , 18 ) ;
F_7 ( V_3 , V_175 , V_154 ) ;
}
static void F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_429 = V_16 -> V_344 . V_429 ;
int V_430 = V_16 -> V_344 . V_430 ;
int V_431 = V_16 -> V_344 . V_431 ;
int V_432 = V_16 -> V_344 . V_432 ;
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_175 ) ;
V_154 = F_115 ( V_154 , V_429 , 20 , 20 ) ;
V_154 = F_115 ( V_154 , V_430 , 21 , 21 ) ;
V_154 = F_115 ( V_154 , V_431 , 22 , 22 ) ;
V_154 = F_115 ( V_154 , V_432 , 23 , 23 ) ;
F_7 ( V_3 , V_175 , V_154 ) ;
}
static int F_199 ( int V_433 , bool V_434 , int V_435 ,
int V_436 , int V_437 , int V_438 , int V_439 )
{
int V_440 ;
if ( V_434 ) {
V_440 = V_435 + V_436 + F_105 ( V_435 , 2 ) + 1 ;
} else {
int V_441 , V_442 ;
V_441 = V_438 + V_435 + V_436 + F_105 ( V_435 , 2 ) + 1 ;
V_442 = V_438 + V_435 + V_437 + V_439 + V_438 +
V_435 + 1 ;
V_440 = F_105 ( V_441 , V_442 ) ;
}
return V_433 > V_440 ? V_433 - V_440 : 0 ;
}
static int F_200 ( int V_433 , int V_435 , int V_436 ,
int V_189 , int V_443 )
{
int V_444 ;
int V_445 ;
int V_446 ;
int V_447 = 16 ;
int V_448 ;
V_444 = V_436 + F_105 ( V_435 , 2 ) + 1 ;
V_445 = V_447 * ( V_433 - V_444 ) ;
V_446 = V_443 * V_189 ;
V_448 = ( ( V_445 - 8 * V_447 - 5 * V_443 ) / V_446 -
26 ) / 16 ;
return F_105 ( V_448 , 0 ) ;
}
static void F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_429 ;
int V_430 , V_431 , V_432 ;
int V_449 , V_450 , V_451 , V_452 , V_453 , V_189 ;
int V_454 , V_455 , V_456 , V_457 ;
int V_321 , V_319 , V_437 ;
bool V_434 ;
struct V_422 * V_423 = & V_16 -> V_423 ;
int V_420 = F_25 ( V_16 -> V_421 ) ;
int V_458 = V_16 -> V_306 - 1 ;
int V_459 = V_16 -> V_191 . V_226 + 1 ;
int V_460 = 0 , V_461 = 0 ;
int V_462 = 0 , V_463 = 0 ;
int V_464 = 0 , V_465 = 0 ;
int V_466 = 0 , V_467 = 0 ;
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_175 ) ;
V_429 = F_100 ( V_154 , 20 , 20 ) ;
V_430 = F_100 ( V_154 , 21 , 21 ) ;
V_431 = F_100 ( V_154 , 22 , 22 ) ;
V_432 = F_100 ( V_154 , 23 , 23 ) ;
V_154 = F_9 ( V_3 , V_278 ) ;
V_451 = F_100 ( V_154 , 11 , 0 ) ;
V_450 = F_100 ( V_154 , 23 , 12 ) ;
V_449 = F_100 ( V_154 , 31 , 24 ) ;
V_154 = F_9 ( V_3 , V_281 ) ;
V_455 = F_100 ( V_154 , 7 , 0 ) ;
V_454 = F_100 ( V_154 , 15 , 8 ) ;
V_154 = F_9 ( V_3 , V_290 ) ;
V_457 = F_100 ( V_154 , 15 , 0 ) ;
V_456 = F_100 ( V_154 , 31 , 16 ) ;
V_154 = F_9 ( V_3 , V_193 ) ;
V_189 = F_100 ( V_154 , 12 , 0 ) ;
V_434 = F_100 ( V_154 , 13 , 13 ) ;
V_154 = F_9 ( V_3 , V_292 ) ;
V_319 = F_100 ( V_154 , 7 , 0 ) ;
V_154 = F_9 ( V_3 , V_293 ) ;
V_321 = F_100 ( V_154 , 15 , 8 ) ;
V_437 = V_319 + V_321 ;
V_452 = F_95 ( V_423 -> V_425 * V_420 , 8 ) ;
V_453 = V_451 + V_450 + V_449 + F_95 ( V_452 + 6 , V_458 ) ;
if ( ! V_432 ) {
V_460 = F_199 ( V_449 , V_434 ,
V_456 , V_457 ,
V_437 , V_454 , V_455 ) ;
V_461 = F_200 ( V_449 ,
V_456 , V_457 ,
V_189 , V_459 ) ;
}
if ( ! V_430 ) {
V_462 = F_199 ( V_450 , V_434 ,
V_456 , V_457 ,
V_437 , V_454 , V_455 ) ;
V_463 = F_200 ( V_450 ,
V_456 , V_457 ,
V_189 , V_459 ) ;
}
if ( ! V_431 ) {
V_464 = F_199 ( V_451 , V_434 ,
V_456 , V_457 ,
V_437 , V_454 , V_455 ) ;
V_465 = F_200 ( V_451 ,
V_456 , V_457 ,
V_189 , V_459 ) ;
}
if ( ! V_429 ) {
V_466 = F_199 ( V_453 , V_434 ,
V_456 , V_457 ,
V_437 , V_454 , V_455 ) ;
V_467 = F_200 ( V_453 ,
V_456 , V_457 ,
V_189 , V_459 ) ;
}
F_71 ( L_141 ,
V_460 , V_462 , V_464 ,
V_466 ) ;
F_71 ( L_142 ,
V_461 , V_463 , V_465 ,
V_467 ) ;
V_154 = F_9 ( V_3 , V_286 ) ;
V_154 = F_115 ( V_154 , V_460 , 23 , 16 ) ;
V_154 = F_115 ( V_154 , V_462 , 15 , 8 ) ;
V_154 = F_115 ( V_154 , V_464 , 7 , 0 ) ;
F_7 ( V_3 , V_286 , V_154 ) ;
V_154 = F_9 ( V_3 , V_288 ) ;
V_154 = F_115 ( V_154 , V_461 , 23 , 16 ) ;
V_154 = F_115 ( V_154 , V_463 , 15 , 8 ) ;
V_154 = F_115 ( V_154 , V_465 , 7 , 0 ) ;
F_7 ( V_3 , V_288 , V_154 ) ;
V_154 = F_9 ( V_3 , V_289 ) ;
V_154 = F_115 ( V_154 , V_466 , 31 , 15 ) ;
V_154 = F_115 ( V_154 , V_467 , 16 , 0 ) ;
F_7 ( V_3 , V_289 , V_154 ) ;
}
static int F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 ;
int V_468 = 0 ;
F_152 ( V_3 , V_469 ,
V_469 ,
V_469 ,
V_469 ) ;
F_154 ( V_3 , V_469 ,
V_469 ,
V_469 ,
V_469 ) ;
F_194 ( V_3 , 0x1000 , false , false ) ;
F_193 ( V_3 , 0x1fff , true , true ) ;
F_192 ( V_3 , 0x1fff , true , true ) ;
F_195 ( V_3 , 0x1fff , true , true ) ;
switch ( F_25 ( V_16 -> V_421 ) ) {
case 16 :
V_468 = 0 ;
break;
case 18 :
V_468 = 1 ;
break;
case 24 :
V_468 = 2 ;
break;
default:
F_26 () ;
return - V_152 ;
}
V_154 = F_9 ( V_3 , V_175 ) ;
V_154 = F_115 ( V_154 , 1 , 1 , 1 ) ;
V_154 = F_115 ( V_154 , 1 , 2 , 2 ) ;
V_154 = F_115 ( V_154 , 1 , 3 , 3 ) ;
V_154 = F_115 ( V_154 , 1 , 4 , 4 ) ;
V_154 = F_115 ( V_154 , V_468 , 7 , 6 ) ;
V_154 = F_115 ( V_154 , 0 , 8 , 8 ) ;
V_154 = F_115 ( V_154 , 1 , 14 , 14 ) ;
V_154 = F_115 ( V_154 , 1 , 19 , 19 ) ;
if ( ! F_84 ( V_368 ) ) {
V_154 = F_115 ( V_154 , 1 , 24 , 24 ) ;
V_154 = F_115 ( V_154 , 0 , 25 , 25 ) ;
}
F_7 ( V_3 , V_175 , V_154 ) ;
F_196 ( V_3 ) ;
if ( V_16 -> V_342 == V_343 ) {
F_197 ( V_3 ) ;
F_198 ( V_3 ) ;
F_201 ( V_3 ) ;
}
F_166 ( V_3 , 0 ) ;
F_166 ( V_3 , 1 ) ;
F_166 ( V_3 , 2 ) ;
F_166 ( V_3 , 3 ) ;
return 0 ;
}
static void F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_470 , V_322 , V_323 , V_321 ;
unsigned V_471 , V_472 ;
unsigned V_316 , V_317 , V_473 ;
unsigned V_318 , V_319 ;
unsigned V_454 , V_455 ;
unsigned V_456 , V_457 ;
unsigned V_474 ;
int V_458 = V_16 -> V_306 - 1 ;
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_292 ) ;
V_316 = F_100 ( V_154 , 31 , 24 ) ;
V_317 = F_100 ( V_154 , 23 , 16 ) ;
V_473 = V_317 - V_316 ;
V_318 = F_100 ( V_154 , 15 , 8 ) ;
V_319 = F_100 ( V_154 , 7 , 0 ) ;
V_154 = F_9 ( V_3 , V_293 ) ;
V_470 = F_100 ( V_154 , 20 , 16 ) * 2 ;
V_321 = F_100 ( V_154 , 15 , 8 ) ;
V_322 = F_100 ( V_154 , 7 , 0 ) ;
V_154 = F_9 ( V_3 , V_294 ) ;
V_323 = F_100 ( V_154 , 7 , 0 ) ;
V_471 = 20 ;
V_472 = F_141 ( V_3 , 60 ) + 26 ;
V_474 = F_95 ( 4 , V_458 ) ;
V_454 = F_95 ( V_471 + V_470 + V_322 + V_323 ,
4 ) ;
V_455 = F_95 ( V_472 + V_318 , 4 ) + V_474 ;
F_61 ( V_454 == 0 || V_454 > 255 ) ;
F_61 ( V_455 == 0 || V_455 > 255 ) ;
V_154 = F_9 ( V_3 , V_281 ) ;
V_154 = F_115 ( V_154 , V_454 , 15 , 8 ) ;
V_154 = F_115 ( V_154 , V_455 , 7 , 0 ) ;
F_7 ( V_3 , V_281 , V_154 ) ;
F_71 ( L_143 ,
V_454 ,
V_455 ) ;
V_456 = 1 + F_95 ( V_470 , 4 ) +
F_95 ( V_316 , 4 ) +
F_95 ( V_473 + 3 , 4 ) ;
V_457 = F_95 ( V_318 + V_319 , 4 ) + 1 + V_474 ;
V_154 = F_153 ( V_456 , 31 , 16 ) |
F_153 ( V_457 , 15 , 0 ) ;
F_7 ( V_3 , V_290 , V_154 ) ;
F_71 ( L_144 ,
V_456 , V_457 ) ;
if ( V_16 -> V_342 == V_343 ) {
int V_449 = V_16 -> V_344 . V_449 ;
int V_450 = V_16 -> V_344 . V_450 ;
int V_451 = V_16 -> V_344 . V_451 ;
int V_475 = V_16 -> V_344 . V_475 ;
int V_476 = V_16 -> V_344 . V_476 ;
int V_477 = V_16 -> V_344 . V_477 ;
int V_478 = V_16 -> V_344 . V_478 ;
bool V_479 ;
struct V_422 * V_423 = & V_16 -> V_423 ;
int V_420 = F_25 ( V_16 -> V_421 ) ;
int V_480 , V_481 , V_452 ;
V_479 = V_16 -> V_344 . V_427 == V_428 ;
V_481 = V_479 ?
( ( V_449 == 0 && V_458 == 3 ) ? 1 : F_95 ( 4 , V_458 ) ) : 0 ;
V_452 = F_95 ( V_423 -> V_425 * V_420 , 8 ) ;
V_480 = F_95 ( 4 , V_458 ) + ( V_479 ? V_449 : 0 ) + V_481 + V_450 +
F_95 ( V_452 + 6 , V_458 ) + V_451 ;
F_71 ( L_145 , V_451 ,
V_450 , V_479 ? V_449 : 0 , V_480 ) ;
F_71 ( L_146 , V_477 , V_476 ,
V_475 , V_423 -> V_482 ) ;
V_154 = F_9 ( V_3 , V_278 ) ;
V_154 = F_115 ( V_154 , V_451 , 11 , 0 ) ;
V_154 = F_115 ( V_154 , V_450 , 23 , 12 ) ;
V_154 = F_115 ( V_154 , V_479 ? V_449 : 0 , 31 , 24 ) ;
F_7 ( V_3 , V_278 , V_154 ) ;
V_154 = F_9 ( V_3 , V_279 ) ;
V_154 = F_115 ( V_154 , V_477 , 7 , 0 ) ;
V_154 = F_115 ( V_154 , V_476 , 15 , 8 ) ;
V_154 = F_115 ( V_154 , V_475 , 23 , 16 ) ;
V_154 = F_115 ( V_154 , V_478 , 27 , 24 ) ;
F_7 ( V_3 , V_279 , V_154 ) ;
V_154 = F_9 ( V_3 , V_280 ) ;
V_154 = F_115 ( V_154 , V_423 -> V_482 , 14 , 0 ) ;
V_154 = F_115 ( V_154 , V_480 , 31 , 16 ) ;
F_7 ( V_3 , V_280 , V_154 ) ;
}
}
static int F_204 ( struct V_5 * V_6 ,
const struct V_483 * V_484 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_485 ;
const int * V_486 ;
struct V_487 V_311 [ V_331 ] ;
int V_488 ;
int V_109 ;
static const enum V_299 V_300 [] = {
V_301 ,
V_302 ,
V_303 ,
V_304 ,
V_305 ,
} ;
V_485 = V_484 -> V_485 ;
V_486 = V_484 -> V_486 ;
if ( V_485 < 4 || V_485 > V_16 -> V_310 * 2
|| V_485 % 2 != 0 )
return - V_152 ;
for ( V_109 = 0 ; V_109 < V_331 ; ++ V_109 )
V_311 [ V_109 ] . V_312 = V_334 ;
V_488 = 0 ;
for ( V_109 = 0 ; V_109 < V_485 ; V_109 += 2 ) {
T_4 V_489 , V_490 ;
int V_491 , V_492 ;
V_491 = V_486 [ V_109 ] ;
V_492 = V_486 [ V_109 + 1 ] ;
if ( V_491 < 0 || V_491 >= V_16 -> V_310 * 2 )
return - V_152 ;
if ( V_492 < 0 || V_492 >= V_16 -> V_310 * 2 )
return - V_152 ;
if ( V_491 & 1 ) {
if ( V_492 != V_491 - 1 )
return - V_152 ;
V_490 = 1 ;
} else {
if ( V_492 != V_491 + 1 )
return - V_152 ;
V_490 = 0 ;
}
V_489 = V_491 / 2 ;
V_311 [ V_489 ] . V_312 = V_300 [ V_109 / 2 ] ;
V_311 [ V_489 ] . V_308 = V_490 ;
V_488 ++ ;
}
memcpy ( V_16 -> V_311 , V_311 , sizeof( V_16 -> V_311 ) ) ;
V_16 -> V_306 = V_488 ;
return 0 ;
}
static int F_205 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_493 * V_494 = V_16 -> V_495 . V_496 ;
int V_420 = F_25 ( V_16 -> V_421 ) ;
struct V_5 * V_8 = & V_16 -> V_495 ;
T_4 V_378 ;
T_13 V_497 ;
int V_154 ;
if ( V_8 == NULL || V_8 -> V_496 == NULL ) {
F_44 ( L_147 ) ;
return - V_200 ;
}
V_154 = F_206 ( V_3 , V_494 ) ;
if ( V_154 )
goto V_498;
if ( V_16 -> V_342 == V_343 ) {
switch ( V_16 -> V_421 ) {
case V_39 :
V_378 = V_499 ;
break;
case V_40 :
V_378 = V_500 ;
break;
case V_41 :
V_378 = V_501 ;
break;
case V_42 :
V_378 = V_502 ;
break;
default:
V_154 = - V_152 ;
goto V_503;
}
F_86 ( V_3 , false ) ;
F_165 ( V_3 , V_75 , false ) ;
F_87 ( V_3 , F_131 ( V_75 ) , 1 , 4 , 4 ) ;
V_497 = F_95 ( V_16 -> V_423 . V_425 * V_420 , 8 ) ;
F_175 ( V_3 , V_75 , V_378 ,
V_497 , 0 ) ;
F_165 ( V_3 , V_75 , true ) ;
F_86 ( V_3 , true ) ;
}
V_154 = F_207 ( V_494 ) ;
if ( V_154 )
goto V_504;
return 0 ;
V_504:
if ( V_16 -> V_342 == V_343 ) {
F_86 ( V_3 , false ) ;
F_165 ( V_3 , V_75 , false ) ;
}
V_503:
F_208 ( V_3 , V_494 ) ;
V_498:
return V_154 ;
}
static void F_209 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_493 * V_494 = V_16 -> V_495 . V_496 ;
if ( V_16 -> V_342 == V_343 ) {
F_86 ( V_3 , false ) ;
F_165 ( V_3 , V_75 , false ) ;
F_87 ( V_3 , F_131 ( V_75 ) , 0 , 4 , 4 ) ;
F_165 ( V_3 , V_75 , true ) ;
F_86 ( V_3 , true ) ;
}
F_210 ( V_494 ) ;
F_208 ( V_3 , V_494 ) ;
}
static void F_211 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_493 * V_494 = V_16 -> V_495 . V_496 ;
unsigned V_505 ;
unsigned V_506 ;
unsigned V_507 ;
unsigned V_508 ;
unsigned V_509 ;
unsigned V_510 ;
T_1 V_166 ;
int V_154 ;
const unsigned V_75 = V_16 -> V_359 ;
const unsigned V_511 = V_16 -> V_424 ;
T_13 V_408 = V_16 -> V_423 . V_425 ;
T_13 V_512 = V_16 -> V_423 . V_482 ;
F_71 ( L_148 , V_408 , V_512 ) ;
F_167 ( V_3 , V_75 , V_364 ) ;
V_505 = F_25 ( V_16 -> V_421 ) / 8 ;
V_506 = V_408 * V_505 ;
V_507 = V_506 * V_512 ;
if ( V_507 < V_511 )
V_509 = V_507 ;
else
V_509 = ( V_511 ) / V_506 * V_506 ;
V_510 = V_509 + 1 ;
V_508 = ( V_507 / V_509 ) * V_510 ;
if ( V_507 % V_509 )
V_508 += ( V_507 % V_509 ) + 1 ;
V_166 = F_153 ( V_508 , 23 , 0 ) ;
F_7 ( V_3 , F_132 ( V_75 ) , V_166 ) ;
F_175 ( V_3 , V_75 , V_395 ,
V_510 , 0 ) ;
if ( V_16 -> V_361 )
V_166 = F_115 ( V_166 , 1 , 30 , 30 ) ;
else
V_166 = F_115 ( V_166 , 1 , 31 , 31 ) ;
F_7 ( V_3 , F_132 ( V_75 ) , V_166 ) ;
F_212 () ;
F_29 ( V_3 ) ;
V_154 = F_213 ( & V_16 -> V_513 ,
F_20 ( 250 ) ) ;
F_61 ( V_154 == 0 ) ;
F_214 ( V_494 , & V_16 -> V_423 ) ;
F_215 ( V_494 ) ;
if ( V_16 -> V_361 ) {
F_87 ( V_3 , V_277 , 0 , 15 , 15 ) ;
F_173 ( V_3 , V_75 ) ;
#ifdef F_50
F_216 ( & V_16 -> V_140 , V_34 + F_20 ( 250 ) ) ;
#endif
}
}
static void F_217 ( unsigned long V_127 )
{
F_44 ( L_149 ) ;
}
static void F_218 ( struct V_2 * V_3 , int error )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_219 () ;
if ( V_16 -> V_361 ) {
F_87 ( V_3 , V_277 , 1 , 15 , 15 ) ;
}
V_16 -> V_514 ( error , V_16 -> V_515 ) ;
if ( ! error )
F_30 ( V_3 , L_150 ) ;
}
static void F_220 ( struct V_516 * V_517 )
{
struct V_1 * V_16 = F_221 ( V_517 , struct V_1 ,
V_513 . V_517 ) ;
F_44 ( L_151 ) ;
F_218 ( V_16 -> V_156 , - V_518 ) ;
}
static void F_222 ( void * V_26 )
{
struct V_2 * V_3 = (struct V_2 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_223 ( & V_16 -> V_513 ) ;
F_218 ( V_3 , 0 ) ;
}
static int F_224 ( struct V_5 * V_6 , int V_75 ,
void (* F_225)( int , void * ) , void * V_26 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_13 V_519 , V_520 ;
F_27 ( V_3 ) ;
V_16 -> V_359 = V_75 ;
V_16 -> V_514 = F_225 ;
V_16 -> V_515 = V_26 ;
V_519 = V_16 -> V_423 . V_425 ;
V_520 = V_16 -> V_423 . V_482 ;
#ifdef F_226
V_16 -> V_53 = V_519 * V_520 *
F_25 ( V_16 -> V_421 ) / 8 ;
#endif
F_211 ( V_3 ) ;
return 0 ;
}
static int F_227 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_521 V_522 ;
int V_154 ;
unsigned long V_416 ;
V_416 = F_88 ( V_3 ) ;
V_522 . V_523 = V_16 -> V_524 . V_523 ;
V_522 . V_525 = V_16 -> V_524 . V_525 ;
V_154 = F_228 ( V_416 , & V_522 ) ;
if ( V_154 ) {
F_44 ( L_152 ) ;
return V_154 ;
}
V_16 -> V_526 . V_527 = V_522 ;
return 0 ;
}
static int F_206 ( struct V_2 * V_3 ,
struct V_493 * V_494 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
F_229 ( V_494 -> V_10 , V_16 -> V_181 == 0 ?
V_237 :
V_266 ) ;
if ( V_16 -> V_342 == V_528 ) {
V_154 = F_230 ( V_494 ,
F_222 , V_3 ) ;
if ( V_154 ) {
F_44 ( L_153 ) ;
goto V_250;
}
V_16 -> V_526 . V_529 = true ;
V_16 -> V_526 . V_530 = true ;
} else {
V_16 -> V_526 . V_529 = false ;
V_16 -> V_526 . V_530 = false ;
}
V_16 -> V_423 . V_531 = false ;
V_16 -> V_423 . V_532 = V_533 ;
V_16 -> V_423 . V_534 = V_533 ;
V_16 -> V_423 . V_535 = V_536 ;
V_16 -> V_423 . V_537 = V_533 ;
V_16 -> V_423 . V_538 = V_539 ;
F_214 ( V_494 , & V_16 -> V_423 ) ;
V_154 = F_227 ( V_3 ) ;
if ( V_154 )
goto V_256;
V_16 -> V_526 . V_540 = V_541 ;
V_16 -> V_526 . V_542 =
F_25 ( V_16 -> V_421 ) ;
V_16 -> V_526 . V_543 = 0 ;
F_231 ( V_494 , & V_16 -> V_526 ) ;
return 0 ;
V_256:
if ( V_16 -> V_342 == V_528 )
F_232 ( V_494 ,
F_222 , V_3 ) ;
V_250:
F_229 ( V_494 -> V_10 , V_182 ) ;
return V_154 ;
}
static void F_208 ( struct V_2 * V_3 ,
struct V_493 * V_494 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_342 == V_528 )
F_232 ( V_494 ,
F_222 , V_3 ) ;
F_229 ( V_494 -> V_10 , V_182 ) ;
}
static int F_233 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_184 V_185 ;
int V_154 ;
V_185 = V_16 -> V_191 ;
V_154 = F_109 ( V_3 , & V_185 ) ;
if ( V_154 ) {
F_44 ( L_154 ) ;
return V_154 ;
}
V_154 = F_111 ( V_3 , & V_185 ) ;
if ( V_154 ) {
F_44 ( L_155 ) ;
return V_154 ;
}
return 0 ;
}
static int F_234 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
V_154 = F_116 ( V_3 , true , true ) ;
if ( V_154 )
goto V_255;
V_154 = F_233 ( V_3 ) ;
if ( V_154 )
goto V_256;
F_235 ( V_16 -> V_181 , V_16 -> V_181 == 0 ?
V_238 :
V_267 ) ;
F_71 ( L_156 ) ;
V_154 = F_148 ( V_3 ) ;
if ( V_154 )
goto V_377;
F_83 ( V_3 ) ;
F_203 ( V_3 ) ;
F_96 ( V_3 ) ;
if ( 1 )
F_83 ( V_3 ) ;
V_154 = F_202 ( V_3 ) ;
if ( V_154 )
goto V_544;
F_165 ( V_3 , 0 , 1 ) ;
F_165 ( V_3 , 1 , 1 ) ;
F_165 ( V_3 , 2 , 1 ) ;
F_165 ( V_3 , 3 , 1 ) ;
F_86 ( V_3 , 1 ) ;
F_155 ( V_3 ) ;
return 0 ;
V_544:
F_151 ( V_3 ) ;
V_377:
F_235 ( V_16 -> V_181 , V_182 ) ;
V_256:
F_120 ( V_3 , true ) ;
V_255:
return V_154 ;
}
static void F_236 ( struct V_2 * V_3 ,
bool V_259 , bool V_545 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_545 && ! V_16 -> V_337 )
F_191 ( V_3 ) ;
F_86 ( V_3 , 0 ) ;
F_165 ( V_3 , 0 , 0 ) ;
F_165 ( V_3 , 1 , 0 ) ;
F_165 ( V_3 , 2 , 0 ) ;
F_165 ( V_3 , 3 , 0 ) ;
F_235 ( V_16 -> V_181 , V_182 ) ;
F_151 ( V_3 ) ;
F_120 ( V_3 , V_259 ) ;
}
static int F_237 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 = 0 ;
F_71 ( L_157 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_238 ( & V_16 -> V_546 ) ;
V_154 = F_70 ( V_3 ) ;
if ( V_154 )
goto V_547;
F_80 ( V_3 , 1 ) ;
F_57 ( V_3 ) ;
V_154 = F_234 ( V_3 ) ;
if ( V_154 )
goto V_548;
F_239 ( & V_16 -> V_546 ) ;
return 0 ;
V_548:
F_80 ( V_3 , 0 ) ;
F_74 ( V_3 ) ;
V_547:
F_239 ( & V_16 -> V_546 ) ;
F_71 ( L_158 ) ;
return V_154 ;
}
static void F_240 ( struct V_5 * V_6 ,
bool V_259 , bool V_545 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_159 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_238 ( & V_16 -> V_546 ) ;
F_163 ( V_3 , 0 ) ;
F_163 ( V_3 , 1 ) ;
F_163 ( V_3 , 2 ) ;
F_163 ( V_3 , 3 ) ;
F_236 ( V_3 , V_259 , V_545 ) ;
F_74 ( V_3 ) ;
F_80 ( V_3 , 0 ) ;
F_239 ( & V_16 -> V_546 ) ;
}
static int F_241 ( struct V_5 * V_6 , bool V_162 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_361 = V_162 ;
return 0 ;
}
static void F_242 ( const char * V_549 ,
const struct V_550 * V_33 )
{
unsigned long V_551 = V_33 -> V_552 / 4 ;
int V_553 , V_554 , V_555 , V_556 ;
V_554 = F_95 ( V_33 -> V_557 * V_33 -> V_558 , 8 ) ;
V_555 = F_95 ( V_554 + 6 , V_33 -> V_458 ) ;
V_553 = V_33 -> V_559 + V_33 -> V_449 + V_33 -> V_560 + V_33 -> V_451 + V_33 -> V_450 ;
V_556 = V_553 + V_555 ;
#define F_243 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, byteclk))
F_36 ( L_160
L_161 ,
V_549 ,
V_551 ,
V_33 -> V_559 , V_33 -> V_449 , V_33 -> V_560 , V_33 -> V_451 , V_555 , V_33 -> V_450 ,
V_553 , V_555 , V_556 ,
F_243 ( V_33 -> V_559 ) ,
F_243 ( V_33 -> V_449 ) ,
F_243 ( V_33 -> V_560 ) ,
F_243 ( V_33 -> V_451 ) ,
F_243 ( V_555 ) ,
F_243 ( V_33 -> V_450 ) ,
F_243 ( V_553 ) ,
F_243 ( V_555 ) ,
F_243 ( V_556 ) ) ;
#undef F_243
}
static void F_244 ( const char * V_549 , const struct V_422 * V_33 )
{
unsigned long V_561 = V_33 -> V_562 * 1000 ;
int V_557 , V_553 , V_556 ;
V_557 = V_33 -> V_425 ;
V_553 = V_33 -> V_563 + V_33 -> V_451 + V_33 -> V_450 ;
V_556 = V_557 + V_553 ;
#define F_245 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, pck))
F_36 ( L_162
L_163 ,
V_549 ,
V_561 ,
V_33 -> V_563 , V_33 -> V_451 , V_557 , V_33 -> V_450 ,
V_553 , V_557 , V_556 ,
F_245 ( V_33 -> V_563 ) ,
F_245 ( V_33 -> V_451 ) ,
F_245 ( V_557 ) ,
F_245 ( V_33 -> V_450 ) ,
F_245 ( V_553 ) ,
F_245 ( V_557 ) ,
F_245 ( V_556 ) ) ;
#undef F_245
}
static void F_246 ( const char * V_549 ,
const struct V_550 * V_33 )
{
struct V_422 V_564 = { 0 } ;
unsigned long V_551 = V_33 -> V_552 / 4 ;
unsigned long V_561 ;
T_14 V_565 ;
int V_566 , V_567 ;
V_565 = ( T_14 ) V_551 * V_33 -> V_458 * 8 ;
V_561 = ( T_1 ) F_247 ( V_565 , V_33 -> V_558 ) ;
V_566 = F_95 ( F_95 ( V_33 -> V_557 * V_33 -> V_558 , 8 ) + 6 , V_33 -> V_458 ) ;
V_567 = V_33 -> V_559 + V_33 -> V_449 + V_33 -> V_560 + V_33 -> V_451 + V_566 + V_33 -> V_450 ;
V_564 . V_562 = V_561 / 1000 ;
V_564 . V_563 = F_247 ( ( T_14 ) ( V_33 -> V_449 + V_33 -> V_560 ) * V_561 , V_551 ) ;
V_564 . V_451 = F_247 ( ( T_14 ) V_33 -> V_451 * V_561 , V_551 ) ;
V_564 . V_450 = F_247 ( ( T_14 ) V_33 -> V_450 * V_561 , V_551 ) ;
V_564 . V_425 = V_33 -> V_557 ;
F_244 ( V_549 , & V_564 ) ;
}
static bool F_248 ( int V_568 , int V_569 , unsigned long V_570 ,
unsigned long V_561 , void * V_26 )
{
struct V_571 * V_572 = V_26 ;
struct V_422 * V_33 = & V_572 -> V_573 ;
V_572 -> V_522 . V_523 = V_568 ;
V_572 -> V_522 . V_525 = V_569 ;
V_572 -> V_522 . V_570 = V_570 ;
V_572 -> V_522 . V_561 = V_561 ;
* V_33 = * V_572 -> V_574 -> V_423 ;
V_33 -> V_562 = V_561 / 1000 ;
V_33 -> V_425 = V_572 -> V_574 -> V_423 -> V_425 ;
V_33 -> V_482 = V_572 -> V_574 -> V_423 -> V_482 ;
V_33 -> V_563 = V_33 -> V_450 = V_33 -> V_451 = V_33 -> V_575 = 1 ;
V_33 -> V_476 = V_33 -> V_477 = 0 ;
return true ;
}
static bool F_249 ( int V_225 , unsigned long V_576 ,
void * V_26 )
{
struct V_571 * V_572 = V_26 ;
V_572 -> V_577 . V_225 = V_225 ;
V_572 -> V_577 . V_178 = V_576 ;
return F_250 ( V_576 , V_572 -> V_578 , V_572 -> V_579 ,
F_248 , V_572 ) ;
}
static bool F_251 ( int V_213 , int V_204 , unsigned long V_216 ,
unsigned long V_201 , void * V_26 )
{
struct V_571 * V_572 = V_26 ;
V_572 -> V_577 . V_213 = V_213 ;
V_572 -> V_577 . V_204 = V_204 ;
V_572 -> V_577 . V_216 = V_216 ;
V_572 -> V_577 . V_180 = V_201 ;
return F_103 ( V_572 -> V_3 , V_201 , V_572 -> V_578 ,
F_249 , V_572 ) ;
}
static bool F_252 ( struct V_1 * V_16 ,
const struct V_580 * V_581 ,
struct V_571 * V_572 )
{
unsigned long V_210 ;
int V_558 , V_458 ;
unsigned long V_211 , V_212 ;
unsigned long V_561 , V_582 ;
V_210 = F_93 ( V_16 -> V_163 ) ;
V_558 = F_25 ( V_581 -> V_583 ) ;
V_458 = V_16 -> V_306 - 1 ;
V_561 = V_581 -> V_423 -> V_562 * 1000 ;
V_561 = V_561 * 3 / 2 ;
V_582 = V_561 * V_558 / 8 / V_458 ;
memset ( V_572 , 0 , sizeof( * V_572 ) ) ;
V_572 -> V_3 = V_16 -> V_156 ;
V_572 -> V_574 = V_581 ;
V_572 -> V_578 = V_561 ;
V_572 -> V_584 = V_561 ;
V_572 -> V_579 = V_561 * 3 / 2 ;
V_572 -> V_577 . V_210 = V_210 ;
V_211 = F_105 ( V_581 -> V_585 * 4 , V_582 * 4 * 4 ) ;
V_212 = V_581 -> V_586 * 4 ;
return F_107 ( V_16 -> V_156 , V_210 ,
V_211 , V_212 ,
F_251 , V_572 ) ;
}
static bool F_253 ( struct V_571 * V_572 )
{
struct V_1 * V_16 = F_1 ( V_572 -> V_3 ) ;
const struct V_580 * V_581 = V_572 -> V_574 ;
int V_558 = F_25 ( V_581 -> V_583 ) ;
int V_458 = V_16 -> V_306 - 1 ;
unsigned long V_552 = V_572 -> V_577 . V_180 / 4 ;
unsigned long V_551 = V_552 / 4 ;
unsigned long V_587 , V_578 , V_584 , V_579 ;
int V_588 ;
int V_589 , V_590 ;
int V_591 , V_592 ;
int V_567 , V_566 , V_593 , V_559 , V_560 ;
int V_450 , V_449 , V_451 ;
const struct V_422 * V_594 ;
struct V_422 * V_573 ;
struct V_550 * V_595 ;
T_14 V_565 , V_596 ;
V_565 = ( T_14 ) V_551 * V_458 * 8 ;
V_594 = V_581 -> V_423 ;
V_578 = V_572 -> V_578 ;
V_579 = V_572 -> V_579 ;
V_584 = V_572 -> V_584 ;
V_587 = V_572 -> V_522 . V_561 ;
V_596 = ( T_14 ) V_587 * V_558 ;
V_588 = V_594 -> V_425 ;
V_590 = V_594 -> V_450 + V_594 -> V_451 + V_594 -> V_563 ;
V_589 = V_588 + V_590 ;
V_566 = F_95 ( F_95 ( V_588 * V_558 , 8 ) + 6 , V_458 ) ;
if ( V_16 -> V_424 < V_588 * V_558 / 8 ) {
if ( V_596 != V_565 )
return false ;
} else {
if ( V_596 < V_565 )
return false ;
}
if ( V_565 < ( T_14 ) V_558 * V_578 )
return false ;
if ( V_581 -> V_427 != V_597 ) {
if ( V_565 > ( T_14 ) V_558 * V_579 )
return false ;
}
V_559 = F_95 ( 4 , V_458 ) ;
if ( V_581 -> V_427 == V_428 ) {
if ( V_458 == 3 && V_594 -> V_563 == 0 )
V_560 = 1 ;
else
V_560 = F_95 ( 4 , V_458 ) ;
} else {
V_560 = 0 ;
}
V_567 = F_247 ( ( T_14 ) V_589 * V_551 , V_584 ) ;
if ( V_567 < V_559 + V_560 + V_566 )
return false ;
V_593 = V_567 - V_566 ;
V_591 = F_247 ( ( T_14 ) V_567 * V_587 , V_551 ) ;
if ( ( T_14 ) V_567 * V_587 != ( T_14 ) V_591 * V_551 )
return false ;
V_592 = V_591 - V_588 ;
V_595 = & V_572 -> V_595 ;
memset ( V_595 , 0 , sizeof( * V_595 ) ) ;
V_595 -> V_552 = V_552 ;
V_595 -> V_458 = V_458 ;
V_595 -> V_558 = V_558 ;
if ( V_581 -> V_427 != V_428 ) {
V_449 = 0 ;
} else if ( V_458 == 3 && V_594 -> V_563 == 0 ) {
V_449 = 0 ;
} else {
V_449 = F_247 ( ( T_14 ) V_594 -> V_563 * V_551 , V_584 ) ;
V_449 = F_105 ( V_449 - V_560 , 1 ) ;
}
V_451 = F_247 ( ( T_14 ) V_594 -> V_451 * V_551 , V_584 ) ;
V_451 = F_105 ( V_451 , 1 ) ;
V_450 = V_593 - ( V_559 + V_449 + V_560 + V_451 ) ;
if ( V_450 < 1 ) {
int V_33 ;
V_33 = 1 - V_450 ;
V_451 = F_105 ( V_451 - V_33 , 1 ) ;
V_450 = V_593 - ( V_559 + V_449 + V_560 + V_451 ) ;
if ( V_450 < 1 && V_449 > 0 ) {
V_33 = 1 - V_450 ;
V_449 = F_105 ( V_449 - V_33 , 1 ) ;
V_450 = V_593 - ( V_559 + V_449 + V_560 + V_451 ) ;
}
}
if ( V_450 < 1 )
return false ;
V_595 -> V_559 = V_559 ;
V_595 -> V_449 = V_449 ;
V_595 -> V_560 = V_560 ;
V_595 -> V_451 = V_451 ;
V_595 -> V_557 = V_588 ;
V_595 -> V_450 = V_450 ;
V_595 -> V_475 = V_594 -> V_575 ;
V_595 -> V_477 = V_594 -> V_477 ;
V_595 -> V_598 = V_594 -> V_482 ;
V_595 -> V_476 = V_594 -> V_476 ;
V_595 -> V_427 = V_581 -> V_427 ;
V_595 -> V_429 = 0 ;
V_595 -> V_432 = 1 ;
V_595 -> V_430 = 1 ;
V_595 -> V_431 = 1 ;
V_595 -> V_345 = V_581 -> V_345 ;
V_595 -> V_478 = 4 ;
V_573 = & V_572 -> V_573 ;
* V_573 = * V_594 ;
V_573 -> V_562 = V_587 / 1000 ;
if ( V_581 -> V_427 == V_428 ) {
V_449 = F_247 ( ( T_14 ) V_594 -> V_563 * V_587 ,
V_584 ) ;
V_449 = F_105 ( V_449 , 1 ) ;
} else {
V_449 = 1 ;
}
V_451 = F_247 ( ( T_14 ) V_594 -> V_451 * V_587 , V_584 ) ;
V_451 = F_105 ( V_451 , 1 ) ;
V_450 = V_592 - V_449 - V_451 ;
if ( V_450 < 1 ) {
int V_33 ;
V_33 = 1 - V_450 ;
V_451 = F_105 ( V_451 - V_33 , 1 ) ;
V_450 = V_592 - V_449 - V_451 ;
if ( V_450 < 1 ) {
V_33 = 1 - V_450 ;
V_449 = F_105 ( V_449 - V_33 , 1 ) ;
V_450 = V_592 - V_449 - V_451 ;
}
}
if ( V_450 < 1 )
return false ;
V_573 -> V_450 = V_450 ;
V_573 -> V_563 = V_449 ;
V_573 -> V_451 = V_451 ;
return true ;
}
static bool F_254 ( int V_568 , int V_569 , unsigned long V_570 ,
unsigned long V_561 , void * V_26 )
{
struct V_571 * V_572 = V_26 ;
V_572 -> V_522 . V_523 = V_568 ;
V_572 -> V_522 . V_525 = V_569 ;
V_572 -> V_522 . V_570 = V_570 ;
V_572 -> V_522 . V_561 = V_561 ;
if ( F_253 ( V_572 ) == false )
return false ;
#ifdef F_255
F_244 ( L_164 , & V_572 -> V_573 ) ;
F_242 ( L_165 , & V_572 -> V_595 ) ;
F_244 ( L_166 , V_572 -> V_574 -> V_423 ) ;
F_246 ( L_167 , & V_572 -> V_595 ) ;
#endif
return true ;
}
static bool F_256 ( int V_225 , unsigned long V_576 ,
void * V_26 )
{
struct V_571 * V_572 = V_26 ;
unsigned long V_599 ;
V_572 -> V_577 . V_225 = V_225 ;
V_572 -> V_577 . V_178 = V_576 ;
if ( V_572 -> V_574 -> V_427 == V_597 )
V_599 = V_572 -> V_579 + 10000000 ;
else
V_599 = V_572 -> V_579 ;
return F_250 ( V_576 , V_572 -> V_578 , V_599 ,
F_254 , V_572 ) ;
}
static bool F_257 ( int V_213 , int V_204 , unsigned long V_216 ,
unsigned long V_201 , void * V_26 )
{
struct V_571 * V_572 = V_26 ;
V_572 -> V_577 . V_213 = V_213 ;
V_572 -> V_577 . V_204 = V_204 ;
V_572 -> V_577 . V_216 = V_216 ;
V_572 -> V_577 . V_180 = V_201 ;
return F_103 ( V_572 -> V_3 , V_201 , V_572 -> V_578 ,
F_256 , V_572 ) ;
}
static bool F_258 ( struct V_1 * V_16 ,
const struct V_580 * V_581 ,
struct V_571 * V_572 )
{
const struct V_422 * V_33 = V_581 -> V_423 ;
unsigned long V_210 ;
unsigned long V_211 ;
unsigned long V_212 ;
int V_458 = V_16 -> V_306 - 1 ;
int V_558 = F_25 ( V_581 -> V_583 ) ;
unsigned long V_600 ;
V_210 = F_93 ( V_16 -> V_163 ) ;
memset ( V_572 , 0 , sizeof( * V_572 ) ) ;
V_572 -> V_3 = V_16 -> V_156 ;
V_572 -> V_574 = V_581 ;
V_572 -> V_577 . V_210 = V_210 ;
V_572 -> V_578 = V_33 -> V_562 * 1000 - 1000 ;
V_572 -> V_584 = V_33 -> V_562 * 1000 ;
V_572 -> V_579 = V_33 -> V_562 * 1000 + 1000 ;
V_600 = F_247 ( ( T_14 ) V_572 -> V_578 * V_558 , V_458 * 8 ) ;
V_211 = F_105 ( V_581 -> V_585 * 4 , V_600 * 4 * 4 ) ;
if ( V_581 -> V_427 == V_597 ) {
V_212 = V_581 -> V_586 * 4 ;
} else {
unsigned long V_601 ;
V_601 = F_247 ( ( T_14 ) V_572 -> V_579 * V_558 ,
V_458 * 8 ) ;
V_212 = V_601 * 4 * 4 ;
}
return F_107 ( V_16 -> V_156 , V_210 ,
V_211 , V_212 ,
F_257 , V_572 ) ;
}
static int F_259 ( struct V_5 * V_6 ,
const struct V_580 * V_574 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_571 V_572 ;
bool V_335 ;
int V_154 ;
F_238 ( & V_16 -> V_546 ) ;
V_16 -> V_421 = V_574 -> V_583 ;
V_16 -> V_342 = V_574 -> V_342 ;
if ( V_574 -> V_342 == V_343 )
V_335 = F_258 ( V_16 , V_574 , & V_572 ) ;
else
V_335 = F_252 ( V_16 , V_574 , & V_572 ) ;
if ( ! V_335 ) {
F_44 ( L_168 ) ;
V_154 = - V_152 ;
goto V_250;
}
F_110 ( & V_572 . V_577 ) ;
V_154 = F_94 ( & V_572 . V_577 , V_574 -> V_186 ,
V_574 -> V_187 ) ;
if ( V_154 ) {
F_44 ( L_169 ) ;
goto V_250;
}
V_16 -> V_191 = V_572 . V_577 ;
V_16 -> V_524 = V_572 . V_522 ;
V_16 -> V_423 = V_572 . V_573 ;
V_16 -> V_344 = V_572 . V_595 ;
F_239 ( & V_16 -> V_546 ) ;
return 0 ;
V_250:
F_239 ( & V_16 -> V_546 ) ;
return V_154 ;
}
static enum V_602 F_260 ( int V_181 )
{
switch ( F_261 () ) {
case V_603 :
F_262 ( L_170 ) ;
return V_604 ;
case V_605 :
case V_606 :
case V_607 :
case V_608 :
return V_604 ;
case V_609 :
case V_610 :
case V_611 :
switch ( V_181 ) {
case 0 :
return V_604 ;
case 1 :
return V_612 ;
default:
F_262 ( L_171 ) ;
return V_604 ;
}
case V_613 :
switch ( V_181 ) {
case 0 :
return V_604 ;
case 1 :
return V_614 ;
default:
F_262 ( L_171 ) ;
return V_604 ;
}
default:
F_262 ( L_172 ) ;
return V_604 ;
}
}
static int F_263 ( struct V_5 * V_6 , int * V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
for ( V_109 = 0 ; V_109 < F_47 ( V_16 -> V_148 ) ; V_109 ++ ) {
if ( ! V_16 -> V_148 [ V_109 ] . V_6 ) {
V_16 -> V_148 [ V_109 ] . V_6 = V_6 ;
* V_75 = V_109 ;
return 0 ;
}
}
F_44 ( L_173 , V_6 -> V_45 ) ;
return - V_615 ;
}
static int F_264 ( struct V_5 * V_6 , int V_75 , int V_382 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_382 < 0 || V_382 > 3 ) {
F_44 ( L_174 ) ;
return - V_152 ;
}
if ( V_75 < 0 || V_75 > 3 ) {
F_44 ( L_175 ) ;
return - V_152 ;
}
if ( V_16 -> V_148 [ V_75 ] . V_6 != V_6 ) {
F_44 ( L_176 ,
V_6 -> V_45 ) ;
return - V_152 ;
}
V_16 -> V_148 [ V_75 ] . V_382 = V_382 ;
return 0 ;
}
static void F_265 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ( V_75 >= 0 && V_75 <= 3 ) &&
V_16 -> V_148 [ V_75 ] . V_6 == V_6 ) {
V_16 -> V_148 [ V_75 ] . V_6 = NULL ;
V_16 -> V_148 [ V_75 ] . V_382 = 0 ;
}
}
void F_266 ( struct V_2 * V_3 )
{
if ( F_18 ( V_3 , V_165 , 7 , 1 ) != 1 )
F_44 ( L_177 ,
F_112 ( V_237 ) ,
F_113 ( V_237 ) ) ;
}
void F_267 ( struct V_2 * V_3 )
{
if ( F_18 ( V_3 , V_165 , 8 , 1 ) != 1 )
F_44 ( L_177 ,
F_112 ( V_238 ) ,
F_113 ( V_238 ) ) ;
}
static void F_268 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_222 = F_104 ( V_616 ) ;
V_16 -> V_224 = F_104 ( V_617 ) ;
V_16 -> V_209 =
F_104 ( V_618 ) ;
V_16 -> V_227 = F_104 ( V_619 ) ;
V_16 -> V_220 = F_269 ( V_620 ) ;
V_16 -> V_221 = F_104 ( V_620 ) ;
V_16 -> V_192 = F_104 ( V_621 ) ;
}
static int F_270 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_622 * V_622 ;
V_622 = F_271 ( & V_3 -> V_4 , L_178 ) ;
if ( F_78 ( V_622 ) ) {
F_44 ( L_179 ) ;
return F_79 ( V_622 ) ;
}
V_16 -> V_183 = V_622 ;
V_622 = F_271 ( & V_3 -> V_4 , L_180 ) ;
if ( F_78 ( V_622 ) ) {
F_44 ( L_181 ) ;
return F_79 ( V_622 ) ;
}
V_16 -> V_163 = V_622 ;
return 0 ;
}
static int F_272 ( struct V_5 * V_6 ,
struct V_5 * V_623 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_493 * V_494 ;
int V_154 ;
V_154 = F_76 ( V_3 ) ;
if ( V_154 )
return V_154 ;
V_494 = F_273 ( V_6 -> V_624 ) ;
if ( ! V_494 )
return - V_200 ;
V_154 = F_274 ( V_494 , V_6 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_275 ( V_6 , V_623 ) ;
if ( V_154 ) {
F_44 ( L_182 ,
V_6 -> V_45 ) ;
F_276 ( V_494 , V_6 ) ;
return V_154 ;
}
return 0 ;
}
static void F_277 ( struct V_5 * V_6 ,
struct V_5 * V_623 )
{
F_73 ( V_623 != V_6 -> V_623 ) ;
if ( V_623 != V_6 -> V_623 )
return;
F_278 ( V_6 ) ;
if ( V_6 -> V_496 )
F_276 ( V_6 -> V_496 , V_6 ) ;
}
static void F_279 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_495 ;
V_8 -> V_4 = & V_3 -> V_4 ;
V_8 -> V_10 = V_16 -> V_181 == 0 ?
V_11 : V_12 ;
V_8 -> V_625 = V_626 ;
V_8 -> V_45 = V_16 -> V_181 == 0 ? L_183 : L_184 ;
V_8 -> V_624 = F_260 ( V_16 -> V_181 ) ;
V_8 -> V_627 . V_16 = & V_628 ;
V_8 -> V_629 = V_630 ;
F_280 ( V_8 ) ;
}
static void F_281 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_495 ;
F_282 ( V_8 ) ;
}
static int F_283 ( struct V_2 * V_3 )
{
T_1 V_631 ;
int V_154 , V_109 ;
struct V_1 * V_16 ;
struct V_632 * V_633 ;
struct V_632 V_634 ;
V_16 = F_284 ( & V_3 -> V_4 , sizeof( * V_16 ) , V_635 ) ;
if ( ! V_16 )
return - V_636 ;
V_16 -> V_181 = V_3 -> V_10 ;
V_16 -> V_156 = V_3 ;
F_285 ( & V_3 -> V_4 , V_16 ) ;
F_286 ( & V_16 -> V_134 ) ;
F_286 ( & V_16 -> V_117 ) ;
V_16 -> V_118 = 0 ;
#ifdef F_287
F_286 ( & V_16 -> V_110 ) ;
V_16 -> V_111 . V_271 = V_34 ;
#endif
F_288 ( & V_16 -> V_546 ) ;
F_289 ( & V_16 -> V_24 , 1 ) ;
F_290 ( & V_16 -> V_513 ,
F_220 ) ;
#ifdef F_50
F_291 ( & V_16 -> V_140 ) ;
V_16 -> V_140 . V_312 = F_217 ;
V_16 -> V_140 . V_26 = 0 ;
#endif
V_633 = F_292 ( V_3 , V_637 , L_185 ) ;
if ( ! V_633 ) {
V_633 = F_293 ( V_3 , V_637 , 0 ) ;
if ( ! V_633 ) {
F_44 ( L_186 ) ;
return - V_152 ;
}
V_634 . T_9 = V_633 -> T_9 ;
V_634 . T_10 = V_634 . T_9 + V_638 - 1 ;
V_633 = & V_634 ;
}
V_16 -> V_19 = F_294 ( & V_3 -> V_4 , V_633 -> T_9 ,
F_295 ( V_633 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_187 ) ;
return - V_636 ;
}
V_633 = F_292 ( V_3 , V_637 , L_188 ) ;
if ( ! V_633 ) {
V_633 = F_293 ( V_3 , V_637 , 0 ) ;
if ( ! V_633 ) {
F_44 ( L_186 ) ;
return - V_152 ;
}
V_634 . T_9 = V_633 -> T_9 + V_639 ;
V_634 . T_10 = V_634 . T_9 + V_640 - 1 ;
V_633 = & V_634 ;
}
V_16 -> V_21 = F_294 ( & V_3 -> V_4 , V_633 -> T_9 ,
F_295 ( V_633 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_189 ) ;
return - V_636 ;
}
V_633 = F_292 ( V_3 , V_637 , L_190 ) ;
if ( ! V_633 ) {
V_633 = F_293 ( V_3 , V_637 , 0 ) ;
if ( ! V_633 ) {
F_44 ( L_186 ) ;
return - V_152 ;
}
V_634 . T_9 = V_633 -> T_9 + V_641 ;
V_634 . T_10 = V_634 . T_9 + V_642 - 1 ;
V_633 = & V_634 ;
}
V_16 -> V_23 = F_294 ( & V_3 -> V_4 , V_633 -> T_9 ,
F_295 ( V_633 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_191 ) ;
return - V_636 ;
}
V_16 -> V_133 = F_296 ( V_16 -> V_156 , 0 ) ;
if ( V_16 -> V_133 < 0 ) {
F_44 ( L_192 ) ;
return - V_200 ;
}
V_154 = F_297 ( & V_3 -> V_4 , V_16 -> V_133 , F_48 ,
V_643 , F_298 ( & V_3 -> V_4 ) , V_16 -> V_156 ) ;
if ( V_154 < 0 ) {
F_44 ( L_193 ) ;
return V_154 ;
}
for ( V_109 = 0 ; V_109 < F_47 ( V_16 -> V_148 ) ; V_109 ++ ) {
V_16 -> V_148 [ V_109 ] . V_363 = V_365 ;
V_16 -> V_148 [ V_109 ] . V_6 = NULL ;
V_16 -> V_148 [ V_109 ] . V_382 = 0 ;
}
F_268 ( V_3 ) ;
V_154 = F_270 ( V_3 ) ;
if ( V_154 )
return V_154 ;
F_299 ( & V_3 -> V_4 ) ;
V_154 = F_70 ( V_3 ) ;
if ( V_154 )
goto V_644;
V_631 = F_9 ( V_3 , V_272 ) ;
F_300 ( & V_3 -> V_4 , L_194 ,
F_100 ( V_631 , 7 , 4 ) , F_100 ( V_631 , 3 , 0 ) ) ;
if ( F_84 ( V_296 ) )
V_16 -> V_310 = 1 + F_19 ( V_3 , V_297 , 11 , 9 ) ;
else
V_16 -> V_310 = 3 ;
V_16 -> V_424 = F_139 ( V_3 ) ;
F_279 ( V_3 ) ;
F_74 ( V_3 ) ;
if ( V_16 -> V_181 == 0 )
F_301 ( L_195 , F_136 ) ;
else if ( V_16 -> V_181 == 1 )
F_301 ( L_196 , F_137 ) ;
#ifdef F_287
if ( V_16 -> V_181 == 0 )
F_301 ( L_197 , F_127 ) ;
else if ( V_16 -> V_181 == 1 )
F_301 ( L_198 , F_128 ) ;
#endif
return 0 ;
V_644:
F_302 ( & V_3 -> V_4 ) ;
return V_154 ;
}
static int T_15 F_303 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_194 > 0 ) ;
F_281 ( V_3 ) ;
F_302 ( & V_3 -> V_4 ) ;
if ( V_16 -> V_160 != NULL && V_16 -> V_254 ) {
F_119 ( V_16 -> V_160 ) ;
V_16 -> V_254 = false ;
}
return 0 ;
}
static int F_304 ( struct V_645 * V_4 )
{
F_305 () ;
return 0 ;
}
static int F_306 ( struct V_645 * V_4 )
{
int V_154 ;
V_154 = F_307 () ;
if ( V_154 )
return V_154 ;
return 0 ;
}
int T_16 F_308 ( void )
{
return F_309 ( & V_646 ) ;
}
void T_15 F_310 ( void )
{
F_311 ( & V_646 ) ;
}
