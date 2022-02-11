static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ) ;
}
static inline struct V_2 * F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_4 ) ;
}
static struct V_2 * F_5 ( int V_7 )
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
if ( ! V_16 -> V_134 )
return V_135 ;
F_40 ( & V_16 -> V_136 ) ;
V_106 = F_9 ( V_3 , V_137 ) ;
if ( ! V_106 ) {
F_42 ( & V_16 -> V_136 ) ;
return V_135 ;
}
F_7 ( V_3 , V_137 , V_106 & ~ V_57 ) ;
F_9 ( V_3 , V_137 ) ;
for ( V_109 = 0 ; V_109 < 4 ; ++ V_109 ) {
if ( ( V_106 & ( 1 << V_109 ) ) == 0 ) {
V_107 [ V_109 ] = 0 ;
continue;
}
V_107 [ V_109 ] = F_9 ( V_3 , F_49 ( V_109 ) ) ;
F_7 ( V_3 , F_49 ( V_109 ) , V_107 [ V_109 ] ) ;
F_9 ( V_3 , F_49 ( V_109 ) ) ;
}
if ( V_106 & V_138 ) {
V_108 = F_9 ( V_3 , V_139 ) ;
F_7 ( V_3 , V_139 , V_108 ) ;
F_9 ( V_3 , V_139 ) ;
} else {
V_108 = 0 ;
}
#ifdef F_50
if ( V_106 & V_140 )
F_51 ( & V_16 -> V_141 ) ;
#endif
memcpy ( & V_16 -> V_142 , & V_16 -> V_129 ,
sizeof( V_16 -> V_129 ) ) ;
F_42 ( & V_16 -> V_136 ) ;
F_46 ( & V_16 -> V_142 , V_106 , V_107 , V_108 ) ;
F_43 ( V_3 , V_106 , V_107 , V_108 ) ;
F_39 ( V_3 , V_106 , V_107 , V_108 ) ;
return V_143 ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
unsigned V_124 , T_1 V_144 ,
const struct V_13 V_145 ,
const struct V_13 V_146 )
{
struct V_122 * V_125 ;
T_1 V_27 ;
T_1 V_147 ;
int V_109 ;
V_27 = V_144 ;
for ( V_109 = 0 ; V_109 < V_124 ; V_109 ++ ) {
V_125 = & V_123 [ V_109 ] ;
if ( V_125 -> V_126 == NULL )
continue;
V_27 |= V_125 -> V_27 ;
}
V_147 = F_9 ( V_3 , V_145 ) ;
F_7 ( V_3 , V_146 , ( V_27 ^ V_147 ) & V_27 ) ;
F_7 ( V_3 , V_145 , V_27 ) ;
F_9 ( V_3 , V_145 ) ;
F_9 ( V_3 , V_146 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_27 = V_116 ;
#ifdef F_50
V_27 |= V_140 ;
#endif
F_52 ( V_3 , V_16 -> V_129 . V_130 ,
F_47 ( V_16 -> V_129 . V_130 ) , V_27 ,
V_148 , V_137 ) ;
}
static void F_54 ( struct V_2 * V_3 , int V_149 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_129 . V_131 [ V_149 ] ,
F_47 ( V_16 -> V_129 . V_131 [ V_149 ] ) ,
V_120 ,
F_55 ( V_149 ) , F_49 ( V_149 ) ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_129 . V_132 ,
F_47 ( V_16 -> V_129 . V_132 ) ,
V_121 ,
V_150 , V_139 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_149 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
memset ( & V_16 -> V_129 , 0 , sizeof( V_16 -> V_129 ) ) ;
F_53 ( V_3 ) ;
for ( V_149 = 0 ; V_149 < 4 ; ++ V_149 )
F_54 ( V_3 , V_149 ) ;
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
}
static int F_60 ( T_7 V_126 , void * V_127 , T_1 V_27 ,
struct V_122 * V_123 , unsigned V_124 )
{
struct V_122 * V_125 ;
int V_152 ;
int V_109 ;
F_61 ( V_126 == NULL ) ;
V_152 = - 1 ;
for ( V_109 = 0 ; V_109 < V_124 ; V_109 ++ ) {
V_125 = & V_123 [ V_109 ] ;
if ( V_125 -> V_126 == V_126 && V_125 -> V_127 == V_127 &&
V_125 -> V_27 == V_27 ) {
return - V_153 ;
}
if ( V_125 -> V_126 == NULL && V_152 == - 1 )
V_152 = V_109 ;
}
if ( V_152 == - 1 )
return - V_154 ;
V_125 = & V_123 [ V_152 ] ;
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
return - V_153 ;
}
static int F_63 ( struct V_2 * V_3 , T_7 V_126 ,
void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_155 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
V_155 = F_60 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_130 ,
F_47 ( V_16 -> V_129 . V_130 ) ) ;
if ( V_155 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
return V_155 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_155 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
V_155 = F_62 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_130 ,
F_47 ( V_16 -> V_129 . V_130 ) ) ;
if ( V_155 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
return V_155 ;
}
static int F_65 ( struct V_2 * V_3 , int V_75 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_155 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
V_155 = F_60 ( V_126 , V_127 , V_27 ,
V_16 -> V_129 . V_131 [ V_75 ] ,
F_47 ( V_16 -> V_129 . V_131 [ V_75 ] ) ) ;
if ( V_155 == 0 )
F_54 ( V_3 , V_75 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
return V_155 ;
}
static int F_66 ( struct V_2 * V_3 , int V_75 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_155 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
V_155 = F_62 ( V_126 , V_127 , V_27 ,
V_16 -> V_129 . V_131 [ V_75 ] ,
F_47 ( V_16 -> V_129 . V_131 [ V_75 ] ) ) ;
if ( V_155 == 0 )
F_54 ( V_3 , V_75 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
return V_155 ;
}
static int F_67 ( struct V_2 * V_3 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_155 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
V_155 = F_60 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_132 ,
F_47 ( V_16 -> V_129 . V_132 ) ) ;
if ( V_155 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
return V_155 ;
}
static int F_68 ( struct V_2 * V_3 ,
T_7 V_126 , void * V_127 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
int V_155 ;
F_58 ( & V_16 -> V_136 , V_151 ) ;
V_155 = F_62 ( V_126 , V_127 , V_27 , V_16 -> V_129 . V_132 ,
F_47 ( V_16 -> V_129 . V_132 ) ) ;
if ( V_155 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_136 , V_151 ) ;
return V_155 ;
}
static T_1 F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
T_1 V_156 ;
F_58 ( & V_16 -> V_117 , V_151 ) ;
V_156 = V_16 -> V_118 ;
V_16 -> V_118 = 0 ;
F_59 ( & V_16 -> V_117 , V_151 ) ;
return V_156 ;
}
static int F_70 ( struct V_2 * V_3 )
{
int V_155 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_10 ) ;
V_155 = F_72 ( & V_16 -> V_157 -> V_4 ) ;
F_73 ( V_155 < 0 ) ;
return V_155 < 0 ? V_155 : 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
F_71 ( L_11 ) ;
V_155 = F_75 ( & V_16 -> V_157 -> V_4 ) ;
F_73 ( V_155 < 0 && V_155 != - V_158 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_159 * V_160 ;
int V_155 ;
if ( V_16 -> V_161 != NULL )
return 0 ;
V_160 = F_77 ( & V_16 -> V_157 -> V_4 , L_12 ) ;
if ( F_78 ( V_160 ) ) {
if ( F_79 ( V_160 ) != - V_162 )
F_44 ( L_13 ) ;
return F_79 ( V_160 ) ;
}
if ( F_80 ( V_160 ) ) {
V_155 = F_81 ( V_160 , 1800000 , 1800000 ) ;
if ( V_155 ) {
F_82 ( V_160 ) ;
F_44 ( L_14 ) ;
return V_155 ;
}
}
V_16 -> V_161 = V_160 ;
return 0 ;
}
static void F_83 ( struct V_2 * V_3 )
{
T_1 V_163 ;
int V_164 , V_165 , V_166 ;
V_163 = F_9 ( V_3 , V_167 ) ;
if ( F_84 ( V_168 ) ) {
V_164 = 28 ;
V_165 = 27 ;
V_166 = 26 ;
} else {
V_164 = 24 ;
V_165 = 25 ;
V_166 = 26 ;
}
#define F_85 ( T_8 , T_9 , T_10 ) \
FLD_GET(dsi_read_reg(dsidev, DSI_##fld), start, end)
F_36 ( L_15 ,
F_85 ( V_169 , 0 , 0 ) ,
F_85 ( V_170 , 29 , 29 ) ,
F_85 ( V_171 , V_164 , V_164 ) ,
F_85 ( V_171 , V_165 , V_165 ) ,
F_85 ( V_171 , V_166 , V_166 ) ,
F_85 ( V_171 , 29 , 29 ) ,
F_85 ( V_171 , 30 , 30 ) ,
F_85 ( V_171 , 31 , 31 ) ) ;
#undef F_85
}
static inline int F_86 ( struct V_2 * V_3 , bool V_172 )
{
F_71 ( L_16 , V_172 ) ;
V_172 = V_172 ? 1 : 0 ;
F_87 ( V_3 , V_173 , V_172 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_173 , 0 , V_172 ) != V_172 ) {
F_44 ( L_17 , V_172 ) ;
return - V_174 ;
}
return 0 ;
}
static unsigned long F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_175 . V_176 . V_177 [ V_178 ] ;
}
static unsigned long F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_175 . V_176 . V_177 [ V_179 ] ;
}
static unsigned long F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_175 . V_176 . V_180 / 16 ;
}
static unsigned long F_91 ( struct V_2 * V_3 )
{
unsigned long V_155 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( F_92 ( V_16 -> V_181 ) == V_182 ) {
V_155 = F_93 ( V_16 -> V_183 ) ;
} else {
V_155 = F_89 ( V_3 ) ;
}
return V_155 ;
}
static int F_94 ( unsigned long V_184 ,
unsigned long V_185 , unsigned long V_186 ,
struct V_187 * V_188 )
{
unsigned V_189 ;
unsigned long V_190 ;
V_189 = F_95 ( V_184 , V_186 * 2 ) ;
V_190 = V_184 / 2 / V_189 ;
if ( V_190 < V_185 || V_190 > V_186 )
return - V_153 ;
V_188 -> V_189 = V_189 ;
V_188 -> V_190 = V_190 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_184 ;
unsigned V_189 ;
unsigned long V_190 ;
unsigned V_191 = F_97 ( V_192 ) ;
V_189 = V_16 -> V_193 . V_189 ;
if ( V_189 == 0 || V_189 > V_191 )
return - V_153 ;
V_184 = F_91 ( V_3 ) ;
V_190 = V_184 / 2 / V_189 ;
F_71 ( L_18 , V_189 , V_190 ) ;
V_16 -> V_194 . V_190 = V_190 ;
V_16 -> V_194 . V_189 = V_189 ;
F_87 ( V_3 , V_195 , V_189 , 12 , 0 ) ;
F_87 ( V_3 , V_195 , V_184 > 30000000 ? 1 : 0 , 21 , 21 ) ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_196 ++ == 0 )
F_87 ( V_3 , V_195 , 1 , 14 , 14 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_196 == 0 ) ;
if ( -- V_16 -> V_196 == 0 )
F_87 ( V_3 , V_195 , 0 , 14 , 14 ) ;
}
static int F_100 ( struct V_2 * V_3 ,
enum V_197 V_198 )
{
int V_33 = 0 ;
if ( F_84 ( V_199 ) &&
V_198 == V_200 )
V_198 = V_201 ;
F_87 ( V_3 , V_195 , V_198 , 31 , 30 ) ;
while ( F_101 ( F_9 ( V_3 , V_195 ) , 29 , 28 ) != V_198 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_19 ,
V_198 ) ;
return - V_202 ;
}
F_102 ( 1 ) ;
}
return 0 ;
}
static void F_103 ( struct V_203 * V_176 )
{
unsigned long V_204 ;
V_204 = F_97 ( V_205 ) ;
V_176 -> V_206 [ V_179 ] = F_95 ( V_176 -> V_180 , V_204 ) ;
V_176 -> V_177 [ V_179 ] = V_176 -> V_180 / V_176 -> V_206 [ V_179 ] ;
}
static int F_104 ( struct V_207 * V_175 )
{
struct V_1 * V_16 = F_105 ( V_175 , struct V_1 , V_175 ) ;
struct V_2 * V_3 = V_16 -> V_157 ;
int V_155 = 0 ;
F_71 ( L_20 ) ;
V_155 = F_76 ( V_3 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_70 ( V_3 ) ;
if ( V_155 )
return V_155 ;
F_98 ( V_3 ) ;
if ( ! V_16 -> V_208 ) {
V_155 = F_106 ( V_16 -> V_161 ) ;
if ( V_155 )
goto V_209;
V_16 -> V_208 = true ;
}
F_107 ( 1 ) ;
if ( F_18 ( V_3 , V_210 , 0 , 1 ) != 1 ) {
F_44 ( L_21 ) ;
V_155 = - V_202 ;
F_107 ( 0 ) ;
goto V_211;
}
F_107 ( 0 ) ;
V_155 = F_100 ( V_3 , V_201 ) ;
if ( V_155 )
goto V_211;
F_71 ( L_22 ) ;
return 0 ;
V_211:
if ( V_16 -> V_208 ) {
F_108 ( V_16 -> V_161 ) ;
V_16 -> V_208 = false ;
}
V_209:
F_99 ( V_3 ) ;
F_74 ( V_3 ) ;
return V_155 ;
}
static void F_109 ( struct V_2 * V_3 , bool V_212 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_100 ( V_3 , V_213 ) ;
if ( V_212 ) {
F_73 ( ! V_16 -> V_208 ) ;
F_108 ( V_16 -> V_161 ) ;
V_16 -> V_208 = false ;
}
F_99 ( V_3 ) ;
F_74 ( V_3 ) ;
F_71 ( L_23 ) ;
}
static void F_110 ( struct V_207 * V_175 )
{
struct V_1 * V_16 = F_105 ( V_175 , struct V_1 , V_175 ) ;
struct V_2 * V_3 = V_16 -> V_157 ;
F_109 ( V_3 , true ) ;
}
static void F_111 ( struct V_2 * V_3 ,
struct V_214 * V_215 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_203 * V_176 = & V_16 -> V_175 . V_176 ;
enum V_216 V_217 , V_218 ;
int V_219 = V_16 -> V_181 ;
struct V_207 * V_175 = & V_16 -> V_175 ;
V_217 = F_112 () ;
V_218 = F_92 ( V_219 ) ;
if ( F_70 ( V_3 ) )
return;
F_113 ( V_215 , L_24 , V_219 + 1 ) ;
F_113 ( V_215 , L_25 , F_93 ( V_175 -> V_220 ) ) ;
F_113 ( V_215 , L_26 , V_176 -> V_221 , V_176 -> V_222 ) ;
F_113 ( V_215 , L_27 ,
V_176 -> V_180 , V_176 -> V_223 ) ;
F_113 ( V_215 , L_28 ,
F_114 ( V_219 == 0 ?
V_224 :
V_225 ) ,
V_176 -> V_177 [ V_178 ] ,
V_176 -> V_206 [ V_178 ] ,
V_217 == V_182 ?
L_29 : L_30 ) ;
F_113 ( V_215 , L_31 ,
F_114 ( V_219 == 0 ?
V_226 :
V_227 ) ,
V_176 -> V_177 [ V_179 ] ,
V_176 -> V_206 [ V_179 ] ,
V_218 == V_182 ?
L_29 : L_30 ) ;
F_113 ( V_215 , L_32 , V_219 + 1 ) ;
F_113 ( V_215 , L_33 ,
F_115 ( V_218 ) ,
F_114 ( V_218 ) ) ;
F_113 ( V_215 , L_34 , F_91 ( V_3 ) ) ;
F_113 ( V_215 , L_35 ,
V_176 -> V_180 / 4 ) ;
F_113 ( V_215 , L_36 , F_90 ( V_3 ) ) ;
F_113 ( V_215 , L_37 , V_16 -> V_194 . V_190 ) ;
F_74 ( V_3 ) ;
}
void F_116 ( struct V_214 * V_215 )
{
struct V_2 * V_3 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_228 ; V_109 ++ ) {
V_3 = F_5 ( V_109 ) ;
if ( V_3 )
F_111 ( V_3 , V_215 ) ;
}
}
static void F_117 ( struct V_2 * V_3 ,
struct V_214 * V_215 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
struct V_229 V_230 ;
F_58 ( & V_16 -> V_110 , V_151 ) ;
V_230 = V_16 -> V_111 ;
memset ( & V_16 -> V_111 , 0 , sizeof( V_16 -> V_111 ) ) ;
V_16 -> V_111 . V_231 = V_34 ;
F_59 ( & V_16 -> V_110 , V_151 ) ;
F_113 ( V_215 , L_38 ,
F_118 ( V_34 - V_230 . V_231 ) ) ;
F_113 ( V_215 , L_39 , V_230 . V_112 ) ;
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d\n", #x, stats.dsi_irqs[ffs(DSI_IRQ_##x)-1]);
F_113 ( V_215 , L_40 , V_16 -> V_181 + 1 ) ;
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
F_113 ( V_215 , L_41 ) ;
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
F_113 ( V_215 , L_42 ) ;
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
static void F_119 ( struct V_214 * V_215 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_117 ( V_3 , V_215 ) ;
}
static void F_120 ( struct V_214 * V_215 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_117 ( V_3 , V_215 ) ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_214 * V_215 )
{
#define F_122 ( V_155 ) seq_printf(s, "%-35s %08x\n", #r, dsi_read_reg(dsidev, r))
if ( F_70 ( V_3 ) )
return;
F_98 ( V_3 ) ;
F_122 ( V_232 ) ;
F_122 ( V_233 ) ;
F_122 ( V_234 ) ;
F_122 ( V_137 ) ;
F_122 ( V_148 ) ;
F_122 ( V_173 ) ;
F_122 ( V_235 ) ;
F_122 ( V_139 ) ;
F_122 ( V_150 ) ;
F_122 ( V_195 ) ;
F_122 ( V_236 ) ;
F_122 ( V_237 ) ;
F_122 ( V_238 ) ;
F_122 ( V_239 ) ;
F_122 ( V_240 ) ;
F_122 ( V_241 ) ;
F_122 ( V_242 ) ;
F_122 ( V_243 ) ;
F_122 ( V_244 ) ;
F_122 ( V_245 ) ;
F_122 ( V_246 ) ;
F_122 ( V_247 ) ;
F_122 ( V_248 ) ;
F_122 ( V_249 ) ;
F_122 ( V_250 ) ;
F_122 ( V_251 ) ;
F_122 ( F_123 ( 0 ) ) ;
F_122 ( F_124 ( 0 ) ) ;
F_122 ( F_125 ( 0 ) ) ;
F_122 ( F_126 ( 0 ) ) ;
F_122 ( F_127 ( 0 ) ) ;
F_122 ( F_49 ( 0 ) ) ;
F_122 ( F_55 ( 0 ) ) ;
F_122 ( F_123 ( 1 ) ) ;
F_122 ( F_124 ( 1 ) ) ;
F_122 ( F_125 ( 1 ) ) ;
F_122 ( F_126 ( 1 ) ) ;
F_122 ( F_127 ( 1 ) ) ;
F_122 ( F_49 ( 1 ) ) ;
F_122 ( F_55 ( 1 ) ) ;
F_122 ( F_123 ( 2 ) ) ;
F_122 ( F_124 ( 2 ) ) ;
F_122 ( F_125 ( 2 ) ) ;
F_122 ( F_126 ( 2 ) ) ;
F_122 ( F_127 ( 2 ) ) ;
F_122 ( F_49 ( 2 ) ) ;
F_122 ( F_55 ( 2 ) ) ;
F_122 ( F_123 ( 3 ) ) ;
F_122 ( F_124 ( 3 ) ) ;
F_122 ( F_125 ( 3 ) ) ;
F_122 ( F_126 ( 3 ) ) ;
F_122 ( F_127 ( 3 ) ) ;
F_122 ( F_49 ( 3 ) ) ;
F_122 ( F_55 ( 3 ) ) ;
F_122 ( V_252 ) ;
F_122 ( V_253 ) ;
F_122 ( V_254 ) ;
F_122 ( V_167 ) ;
F_122 ( V_255 ) ;
F_122 ( V_210 ) ;
F_122 ( V_256 ) ;
F_122 ( V_257 ) ;
F_122 ( V_258 ) ;
F_99 ( V_3 ) ;
F_74 ( V_3 ) ;
#undef F_122
}
static void F_128 ( struct V_214 * V_215 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_121 ( V_3 , V_215 ) ;
}
static void F_129 ( struct V_214 * V_215 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_121 ( V_3 , V_215 ) ;
}
static int F_130 ( struct V_2 * V_3 ,
enum V_259 V_198 )
{
int V_33 = 0 ;
F_87 ( V_3 , V_235 , V_198 , 28 , 27 ) ;
while ( F_101 ( F_9 ( V_3 , V_235 ) ,
26 , 25 ) != V_198 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_43
L_44 , V_198 ) ;
return - V_202 ;
}
F_102 ( 1 ) ;
}
return 0 ;
}
static unsigned F_131 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! F_84 ( V_260 ) )
return 1023 * 3 ;
V_15 = F_19 ( V_3 , V_261 , 14 , 12 ) ;
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
static int F_132 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
static const T_4 V_262 [] = { 0 , 4 , 8 , 12 , 16 } ;
static const enum V_263 V_264 [] = {
V_265 ,
V_266 ,
V_267 ,
V_268 ,
V_269 ,
} ;
T_1 V_155 ;
int V_109 ;
V_155 = F_9 ( V_3 , V_235 ) ;
for ( V_109 = 0 ; V_109 < V_16 -> V_270 ; ++ V_109 ) {
unsigned V_271 = V_262 [ V_109 ] ;
unsigned V_272 , V_273 ;
unsigned V_33 ;
for ( V_33 = 0 ; V_33 < V_16 -> V_274 ; ++ V_33 )
if ( V_16 -> V_275 [ V_33 ] . V_276 == V_264 [ V_109 ] )
break;
if ( V_33 == V_16 -> V_274 )
return - V_153 ;
V_273 = V_33 ;
V_272 = V_16 -> V_275 [ V_33 ] . V_272 ;
V_155 = F_133 ( V_155 , V_273 + 1 , V_271 + 2 , V_271 ) ;
V_155 = F_133 ( V_155 , V_272 , V_271 + 3 , V_271 + 3 ) ;
}
for (; V_109 < V_16 -> V_274 ; ++ V_109 ) {
unsigned V_271 = V_262 [ V_109 ] ;
V_155 = F_133 ( V_155 , 0 , V_271 + 2 , V_271 ) ;
V_155 = F_133 ( V_155 , 0 , V_271 + 3 , V_271 + 3 ) ;
}
F_7 ( V_3 , V_235 , V_155 ) ;
return 0 ;
}
static inline unsigned F_134 ( struct V_2 * V_3 , unsigned V_277 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_278 = V_16 -> V_175 . V_176 . V_180 / 4 ;
return ( V_277 * ( V_278 / 1000 / 1000 ) + 999 ) / 1000 ;
}
static inline unsigned F_135 ( struct V_2 * V_3 , unsigned V_279 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_278 = V_16 -> V_175 . V_176 . V_180 / 4 ;
return V_279 * 1000 * 1000 / ( V_278 / 1000 ) ;
}
static void F_136 ( struct V_2 * V_3 )
{
T_1 V_155 ;
T_1 V_280 , V_281 , V_282 , V_283 ;
T_1 V_284 , V_285 , V_286 ;
T_1 V_287 ;
V_280 = F_134 ( V_3 , 70 ) + 2 ;
V_281 = F_134 ( V_3 , 175 ) + 2 ;
V_282 = F_134 ( V_3 , 60 ) + 5 ;
V_283 = F_134 ( V_3 , 145 ) ;
V_284 = F_134 ( V_3 , 25 ) ;
V_285 = F_134 ( V_3 , 60 ) + 2 ;
V_287 = F_134 ( V_3 , 65 ) ;
V_286 = F_134 ( V_3 , 260 ) ;
F_71 ( L_45 ,
V_280 , F_135 ( V_3 , V_280 ) ,
V_281 , F_135 ( V_3 , V_281 ) ) ;
F_71 ( L_46 ,
V_282 , F_135 ( V_3 , V_282 ) ,
V_283 , F_135 ( V_3 , V_283 ) ) ;
F_71 ( L_47
L_48 ,
V_284 , F_135 ( V_3 , V_284 ) ,
V_285 , F_135 ( V_3 , V_285 ) ,
V_286 , F_135 ( V_3 , V_286 ) ) ;
F_71 ( L_49 ,
V_287 , F_135 ( V_3 , V_287 ) ) ;
V_155 = F_9 ( V_3 , V_252 ) ;
V_155 = F_133 ( V_155 , V_280 , 31 , 24 ) ;
V_155 = F_133 ( V_155 , V_281 , 23 , 16 ) ;
V_155 = F_133 ( V_155 , V_282 , 15 , 8 ) ;
V_155 = F_133 ( V_155 , V_283 , 7 , 0 ) ;
F_7 ( V_3 , V_252 , V_155 ) ;
V_155 = F_9 ( V_3 , V_253 ) ;
V_155 = F_133 ( V_155 , V_284 , 20 , 16 ) ;
V_155 = F_133 ( V_155 , V_285 , 15 , 8 ) ;
V_155 = F_133 ( V_155 , V_286 , 7 , 0 ) ;
if ( F_84 ( V_288 ) ) {
V_155 = F_133 ( V_155 , 0 , 21 , 21 ) ;
V_155 = F_133 ( V_155 , 1 , 22 , 22 ) ;
V_155 = F_133 ( V_155 , 1 , 23 , 23 ) ;
}
F_7 ( V_3 , V_253 , V_155 ) ;
V_155 = F_9 ( V_3 , V_254 ) ;
V_155 = F_133 ( V_155 , V_287 , 7 , 0 ) ;
F_7 ( V_3 , V_254 , V_155 ) ;
}
static void F_137 ( struct V_2 * V_3 ,
unsigned V_289 , unsigned V_290 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
T_1 V_163 ;
T_4 V_291 = V_16 -> V_274 == 3 ? 22 : 26 ;
V_163 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 ) {
unsigned V_292 = V_16 -> V_275 [ V_109 ] . V_272 ;
if ( V_289 & ( 1 << V_109 ) )
V_163 |= 1 << ( V_109 * 2 + ( V_292 ? 0 : 1 ) ) ;
if ( V_290 & ( 1 << V_109 ) )
V_163 |= 1 << ( V_109 * 2 + ( V_292 ? 1 : 0 ) ) ;
}
F_87 ( V_3 , V_293 , V_163 , V_291 , 17 ) ;
F_87 ( V_3 , V_293 , 1 , 27 , 27 ) ;
}
static void F_138 ( struct V_2 * V_3 )
{
F_87 ( V_3 , V_293 , 0 , 27 , 27 ) ;
F_87 ( V_3 , V_293 , 0 , 22 , 17 ) ;
}
static int F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_33 , V_109 ;
bool V_294 [ V_295 ] ;
static const T_4 V_296 [] = { 28 , 27 , 26 } ;
static const T_4 V_297 [] = { 24 , 25 , 26 , 27 , 28 } ;
const T_4 * V_262 ;
if ( F_84 ( V_168 ) )
V_262 = V_296 ;
else
V_262 = V_297 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 )
V_294 [ V_109 ] = V_16 -> V_275 [ V_109 ] . V_276 != V_298 ;
V_33 = 100000 ;
while ( true ) {
T_1 V_163 ;
int V_299 ;
V_163 = F_9 ( V_3 , V_167 ) ;
V_299 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 ) {
if ( ! V_294 [ V_109 ] || ( V_163 & ( 1 << V_262 [ V_109 ] ) ) )
V_299 ++ ;
}
if ( V_299 == V_16 -> V_274 )
break;
if ( -- V_33 == 0 ) {
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 ) {
if ( ! V_294 [ V_109 ] || ( V_163 & ( 1 << V_262 [ V_109 ] ) ) )
continue;
F_44 ( L_50 \
L_51 , V_109 ) ;
}
return - V_174 ;
}
}
return 0 ;
}
static unsigned F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_27 = 0 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 ) {
if ( V_16 -> V_275 [ V_109 ] . V_276 != V_298 )
V_27 |= 1 << V_109 ;
}
return V_27 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
T_1 V_163 ;
F_71 ( L_52 ) ;
V_155 = F_142 ( V_16 -> V_181 , F_140 ( V_3 ) ) ;
if ( V_155 )
return V_155 ;
F_98 ( V_3 ) ;
F_9 ( V_3 , V_167 ) ;
if ( F_18 ( V_3 , V_167 , 30 , 1 ) != 1 ) {
F_44 ( L_53 ) ;
V_155 = - V_174 ;
goto V_300;
}
V_155 = F_132 ( V_3 ) ;
if ( V_155 )
goto V_300;
V_163 = F_9 ( V_3 , V_236 ) ;
V_163 = F_133 ( V_163 , 1 , 15 , 15 ) ;
V_163 = F_133 ( V_163 , 1 , 14 , 14 ) ;
V_163 = F_133 ( V_163 , 1 , 13 , 13 ) ;
V_163 = F_133 ( V_163 , 0x1fff , 12 , 0 ) ;
F_7 ( V_3 , V_236 , V_163 ) ;
if ( V_16 -> V_301 ) {
unsigned V_289 ;
int V_109 ;
F_71 ( L_54 ) ;
V_289 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 ) {
if ( V_16 -> V_275 [ V_109 ] . V_276 == V_298 )
continue;
V_289 |= 1 << V_109 ;
}
F_137 ( V_3 , V_289 , 0 ) ;
}
V_155 = F_130 ( V_3 , V_302 ) ;
if ( V_155 )
goto V_303;
if ( F_18 ( V_3 , V_235 , 29 , 1 ) != 1 ) {
F_44 ( L_55 ) ;
V_155 = - V_202 ;
goto V_304;
}
F_86 ( V_3 , true ) ;
F_86 ( V_3 , false ) ;
F_87 ( V_3 , V_195 , 1 , 20 , 20 ) ;
V_155 = F_139 ( V_3 ) ;
if ( V_155 )
goto V_305;
if ( V_16 -> V_301 ) {
T_3 V_32 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_35 ) ;
F_24 ( & V_32 , V_36 ) ;
F_138 ( V_3 ) ;
}
F_87 ( V_3 , V_236 , 0 , 15 , 15 ) ;
F_136 ( V_3 ) ;
if ( V_16 -> V_306 == V_307 ) {
F_87 ( V_3 , V_195 ,
V_16 -> V_308 . V_309 , 13 , 13 ) ;
}
V_16 -> V_301 = false ;
F_71 ( L_56 ) ;
return 0 ;
V_305:
F_87 ( V_3 , V_195 , 0 , 20 , 20 ) ;
V_304:
F_130 ( V_3 , V_310 ) ;
V_303:
if ( V_16 -> V_301 )
F_138 ( V_3 ) ;
V_300:
F_99 ( V_3 ) ;
F_143 ( V_16 -> V_181 , F_140 ( V_3 ) ) ;
return V_155 ;
}
static void F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_87 ( V_3 , V_195 , 0 , 13 , 13 ) ;
F_130 ( V_3 , V_310 ) ;
F_99 ( V_3 ) ;
F_143 ( V_16 -> V_181 , F_140 ( V_3 ) ) ;
}
static void F_145 ( struct V_2 * V_3 ,
enum V_311 V_312 , enum V_311 V_313 ,
enum V_311 V_314 , enum V_311 V_315 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 = 0 ;
int V_316 = 0 ;
int V_109 ;
V_16 -> V_149 [ 0 ] . V_317 = V_312 ;
V_16 -> V_149 [ 1 ] . V_317 = V_313 ;
V_16 -> V_149 [ 2 ] . V_317 = V_314 ;
V_16 -> V_149 [ 3 ] . V_317 = V_315 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ ) {
T_4 V_318 ;
int V_319 = V_16 -> V_149 [ V_109 ] . V_317 ;
if ( V_316 + V_319 > 4 ) {
F_44 ( L_57 ) ;
F_26 () ;
return;
}
V_318 = F_146 ( V_316 , 2 , 0 ) | F_146 ( V_319 , 7 , 4 ) ;
V_155 |= V_318 << ( 8 * V_109 ) ;
V_316 += V_319 ;
}
F_7 ( V_3 , V_242 , V_155 ) ;
}
static void F_147 ( struct V_2 * V_3 ,
enum V_311 V_312 , enum V_311 V_313 ,
enum V_311 V_314 , enum V_311 V_315 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 = 0 ;
int V_316 = 0 ;
int V_109 ;
V_16 -> V_149 [ 0 ] . V_320 = V_312 ;
V_16 -> V_149 [ 1 ] . V_320 = V_313 ;
V_16 -> V_149 [ 2 ] . V_320 = V_314 ;
V_16 -> V_149 [ 3 ] . V_320 = V_315 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ ) {
T_4 V_318 ;
int V_319 = V_16 -> V_149 [ V_109 ] . V_320 ;
if ( V_316 + V_319 > 4 ) {
F_44 ( L_57 ) ;
F_26 () ;
return;
}
V_318 = F_146 ( V_316 , 2 , 0 ) | F_146 ( V_319 , 7 , 4 ) ;
V_155 |= V_318 << ( 8 * V_109 ) ;
V_316 += V_319 ;
}
F_7 ( V_3 , V_243 , V_155 ) ;
}
static int F_148 ( struct V_2 * V_3 )
{
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_236 ) ;
V_155 = F_133 ( V_155 , 1 , 15 , 15 ) ;
F_7 ( V_3 , V_236 , V_155 ) ;
if ( F_18 ( V_3 , V_236 , 15 , 0 ) != 0 ) {
F_44 ( L_58 ) ;
return - V_174 ;
}
return 0 ;
}
static bool F_149 ( struct V_2 * V_3 , int V_75 )
{
return F_19 ( V_3 , F_123 ( V_75 ) , 0 , 0 ) ;
}
static void F_150 ( void * V_26 , T_1 V_27 )
{
struct V_321 * V_322 =
(struct V_321 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_322 -> V_3 ) ;
const int V_75 = V_16 -> V_323 ;
T_4 V_324 = V_16 -> V_325 ? 30 : 31 ;
if ( F_19 ( V_322 -> V_3 , F_124 ( V_75 ) , V_324 , V_324 ) == 0 )
F_17 ( V_322 -> V_28 ) ;
}
static int F_151 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_152 ( V_28 ) ;
struct V_321 V_322 = {
. V_3 = V_3 ,
. V_28 = & V_28
} ;
int V_155 = 0 ;
T_4 V_324 ;
V_324 = V_16 -> V_325 ? 30 : 31 ;
V_155 = F_65 ( V_3 , V_75 , F_150 ,
& V_322 , V_76 ) ;
if ( V_155 )
goto V_209;
if ( F_19 ( V_3 , F_124 ( V_75 ) , V_324 , V_324 ) ) {
if ( F_153 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_59 ) ;
V_155 = - V_174 ;
goto V_211;
}
}
F_66 ( V_3 , V_75 , F_150 ,
& V_322 , V_76 ) ;
return 0 ;
V_211:
F_66 ( V_3 , V_75 , F_150 ,
& V_322 , V_76 ) ;
V_209:
return V_155 ;
}
static void F_154 ( void * V_26 , T_1 V_27 )
{
struct V_321 * V_326 =
(struct V_321 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_326 -> V_3 ) ;
const int V_75 = V_16 -> V_323 ;
if ( F_19 ( V_326 -> V_3 , F_123 ( V_75 ) , 5 , 5 ) == 0 )
F_17 ( V_326 -> V_28 ) ;
}
static int F_155 ( struct V_2 * V_3 , int V_75 )
{
F_152 ( V_28 ) ;
struct V_321 V_326 = {
. V_3 = V_3 ,
. V_28 = & V_28
} ;
int V_155 = 0 ;
V_155 = F_65 ( V_3 , V_75 , F_154 ,
& V_326 , V_76 ) ;
if ( V_155 )
goto V_209;
if ( F_19 ( V_3 , F_123 ( V_75 ) , 5 , 5 ) ) {
if ( F_153 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_60 ) ;
V_155 = - V_174 ;
goto V_211;
}
}
F_66 ( V_3 , V_75 , F_154 ,
& V_326 , V_76 ) ;
return 0 ;
V_211:
F_66 ( V_3 , V_75 , F_154 ,
& V_326 , V_76 ) ;
V_209:
return V_155 ;
}
static int F_156 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( F_157 () ) ;
if ( ! F_149 ( V_3 , V_75 ) )
return 0 ;
switch ( V_16 -> V_149 [ V_75 ] . V_327 ) {
case V_328 :
return F_151 ( V_3 , V_75 ) ;
case V_329 :
return F_155 ( V_3 , V_75 ) ;
default:
F_26 () ;
return - V_153 ;
}
}
static int F_158 ( struct V_2 * V_3 , int V_75 ,
bool V_172 )
{
F_71 ( L_61 ,
V_75 , V_172 ) ;
V_172 = V_172 ? 1 : 0 ;
F_87 ( V_3 , F_123 ( V_75 ) , V_172 , 0 , 0 ) ;
if ( F_18 ( V_3 , F_123 ( V_75 ) ,
0 , V_172 ) != V_172 ) {
F_44 ( L_62 , V_172 ) ;
return - V_174 ;
}
return 0 ;
}
static void F_159 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 ;
F_71 ( L_63 , V_75 ) ;
V_155 = F_9 ( V_3 , F_123 ( V_75 ) ) ;
if ( F_101 ( V_155 , 15 , 15 ) )
F_44 ( L_64 ,
V_75 ) ;
V_155 = F_133 ( V_155 , 0 , 1 , 1 ) ;
V_155 = F_133 ( V_155 , 0 , 2 , 2 ) ;
V_155 = F_133 ( V_155 , 0 , 3 , 3 ) ;
V_155 = F_133 ( V_155 , 0 , 4 , 4 ) ;
V_155 = F_133 ( V_155 , 1 , 7 , 7 ) ;
V_155 = F_133 ( V_155 , 1 , 8 , 8 ) ;
V_155 = F_133 ( V_155 , 0 , 9 , 9 ) ;
if ( F_84 ( V_330 ) )
V_155 = F_133 ( V_155 , 3 , 11 , 10 ) ;
V_155 = F_133 ( V_155 , 4 , 29 , 27 ) ;
V_155 = F_133 ( V_155 , 4 , 23 , 21 ) ;
F_7 ( V_3 , F_123 ( V_75 ) , V_155 ) ;
V_16 -> V_149 [ V_75 ] . V_327 = V_329 ;
}
static int F_160 ( struct V_2 * V_3 , int V_75 ,
enum V_331 V_327 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_149 [ V_75 ] . V_327 == V_327 )
return 0 ;
F_71 ( L_65 , V_75 ) ;
F_156 ( V_3 , V_75 ) ;
F_158 ( V_3 , V_75 , 0 ) ;
if ( F_18 ( V_3 , F_123 ( V_75 ) , 15 , 0 ) != 0 ) {
F_44 ( L_66 , V_75 ) ;
return - V_174 ;
}
F_87 ( V_3 , F_123 ( V_75 ) , V_327 , 1 , 1 ) ;
if ( F_84 ( V_332 ) ) {
bool V_172 = V_327 == V_328 ;
F_87 ( V_3 , F_123 ( V_75 ) , V_172 , 30 , 30 ) ;
}
F_158 ( V_3 , V_75 , 1 ) ;
V_16 -> V_149 [ V_75 ] . V_327 = V_327 ;
return 0 ;
}
static void F_161 ( struct V_5 * V_6 , int V_75 ,
bool V_172 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_67 , V_75 , V_172 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_158 ( V_3 , V_75 , 0 ) ;
F_86 ( V_3 , 0 ) ;
F_87 ( V_3 , F_123 ( V_75 ) , V_172 , 9 , 9 ) ;
F_158 ( V_3 , V_75 , 1 ) ;
F_86 ( V_3 , 1 ) ;
F_148 ( V_3 ) ;
if ( V_16 -> V_308 . V_309 && V_172 )
F_162 ( V_6 , V_75 ) ;
}
static void F_163 ( struct V_2 * V_3 , int V_75 )
{
while ( F_19 ( V_3 , F_123 ( V_75 ) , 20 , 20 ) ) {
T_1 V_15 ;
V_15 = F_9 ( V_3 , F_127 ( V_75 ) ) ;
F_71 ( L_68 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
}
}
static void F_164 ( T_11 V_333 )
{
F_44 ( L_69 , V_333 ) ;
if ( V_333 & ( 1 << 0 ) )
F_44 ( L_70 ) ;
if ( V_333 & ( 1 << 1 ) )
F_44 ( L_71 ) ;
if ( V_333 & ( 1 << 2 ) )
F_44 ( L_72 ) ;
if ( V_333 & ( 1 << 3 ) )
F_44 ( L_73 ) ;
if ( V_333 & ( 1 << 4 ) )
F_44 ( L_74 ) ;
if ( V_333 & ( 1 << 5 ) )
F_44 ( L_75 ) ;
if ( V_333 & ( 1 << 6 ) )
F_44 ( L_76 ) ;
if ( V_333 & ( 1 << 7 ) )
F_44 ( L_77 ) ;
if ( V_333 & ( 1 << 8 ) )
F_44 ( L_78 ) ;
if ( V_333 & ( 1 << 9 ) )
F_44 ( L_79 ) ;
if ( V_333 & ( 1 << 10 ) )
F_44 ( L_80 ) ;
if ( V_333 & ( 1 << 11 ) )
F_44 ( L_81 ) ;
if ( V_333 & ( 1 << 12 ) )
F_44 ( L_82 ) ;
if ( V_333 & ( 1 << 13 ) )
F_44 ( L_83 ) ;
if ( V_333 & ( 1 << 14 ) )
F_44 ( L_84 ) ;
if ( V_333 & ( 1 << 15 ) )
F_44 ( L_85 ) ;
}
static T_11 F_165 ( struct V_2 * V_3 ,
int V_75 )
{
while ( F_19 ( V_3 , F_123 ( V_75 ) , 20 , 20 ) ) {
T_1 V_15 ;
T_4 V_334 ;
V_15 = F_9 ( V_3 , F_127 ( V_75 ) ) ;
F_44 ( L_86 , V_15 ) ;
V_334 = F_101 ( V_15 , 5 , 0 ) ;
if ( V_334 == V_335 ) {
T_11 V_333 = F_101 ( V_15 , 23 , 8 ) ;
F_164 ( V_333 ) ;
} else if ( V_334 == V_336 ) {
F_44 ( L_87 ,
F_101 ( V_15 , 23 , 8 ) ) ;
} else if ( V_334 == V_337 ) {
F_44 ( L_88 ,
F_101 ( V_15 , 23 , 8 ) ) ;
} else if ( V_334 == V_338 ) {
F_44 ( L_89 ,
F_101 ( V_15 , 23 , 8 ) ) ;
F_163 ( V_3 , V_75 ) ;
} else {
F_44 ( L_90 , V_334 ) ;
}
}
return 0 ;
}
static int F_166 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_339 || V_16 -> V_340 )
F_71 ( L_91 , V_75 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( F_19 ( V_3 , F_123 ( V_75 ) , 20 , 20 ) ) {
F_44 ( L_92 ) ;
F_165 ( V_3 , V_75 ) ;
}
F_87 ( V_3 , F_123 ( V_75 ) , 1 , 6 , 6 ) ;
F_9 ( V_3 , F_123 ( V_75 ) ) ;
return 0 ;
}
static int F_167 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
F_152 ( V_28 ) ;
int V_155 = 0 ;
T_1 V_333 ;
V_155 = F_65 ( V_3 , V_75 , F_16 ,
& V_28 , V_341 ) ;
if ( V_155 )
goto V_209;
V_155 = F_63 ( V_3 , F_16 , & V_28 ,
V_116 ) ;
if ( V_155 )
goto V_211;
V_155 = F_166 ( V_3 , V_75 ) ;
if ( V_155 )
goto V_342;
if ( F_153 ( & V_28 ,
F_20 ( 500 ) ) == 0 ) {
F_44 ( L_93 ) ;
V_155 = - V_174 ;
goto V_342;
}
V_333 = F_69 ( V_3 ) ;
if ( V_333 ) {
F_44 ( L_94 , V_333 ) ;
V_155 = - V_174 ;
goto V_342;
}
V_342:
F_64 ( V_3 , F_16 , & V_28 ,
V_116 ) ;
V_211:
F_66 ( V_3 , V_75 , F_16 ,
& V_28 , V_341 ) ;
V_209:
return V_155 ;
}
static inline void F_168 ( struct V_2 * V_3 ,
int V_75 , T_4 V_343 , T_11 V_344 , T_4 V_345 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_346 ;
F_73 ( ! F_15 ( V_3 ) ) ;
V_346 = V_343 | V_16 -> V_149 [ V_75 ] . V_347 << 6 ;
V_15 = F_146 ( V_346 , 7 , 0 ) | F_146 ( V_344 , 23 , 8 ) |
F_146 ( V_345 , 31 , 24 ) ;
F_7 ( V_3 , F_125 ( V_75 ) , V_15 ) ;
}
static inline void F_169 ( struct V_2 * V_3 ,
int V_75 , T_4 V_165 , T_4 V_166 , T_4 V_348 , T_4 V_349 )
{
T_1 V_15 ;
V_15 = V_349 << 24 | V_348 << 16 | V_166 << 8 | V_165 << 0 ;
F_7 ( V_3 , F_126 ( V_75 ) , V_15 ) ;
}
static int F_170 ( struct V_2 * V_3 , int V_75 ,
T_4 V_343 , T_4 * V_26 , T_11 V_344 , T_4 V_345 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
T_4 * V_292 ;
int V_155 = 0 ;
T_4 V_165 , V_166 , V_348 , V_349 ;
if ( V_16 -> V_339 )
F_71 ( L_95 , V_344 ) ;
if ( V_16 -> V_149 [ V_75 ] . V_317 * 32 * 4 < V_344 + 4 ) {
F_44 ( L_96 ) ;
return - V_153 ;
}
F_160 ( V_3 , V_75 , V_329 ) ;
F_168 ( V_3 , V_75 , V_343 , V_344 , V_345 ) ;
V_292 = V_26 ;
for ( V_109 = 0 ; V_109 < V_344 > > 2 ; V_109 ++ ) {
if ( V_16 -> V_339 )
F_71 ( L_97 , V_109 ) ;
V_165 = * V_292 ++ ;
V_166 = * V_292 ++ ;
V_348 = * V_292 ++ ;
V_349 = * V_292 ++ ;
F_169 ( V_3 , V_75 , V_165 , V_166 , V_348 , V_349 ) ;
}
V_109 = V_344 % 4 ;
if ( V_109 ) {
V_165 = 0 ; V_166 = 0 ; V_348 = 0 ;
if ( V_16 -> V_339 )
F_71 ( L_98 , V_109 ) ;
switch ( V_109 ) {
case 3 :
V_165 = * V_292 ++ ;
V_166 = * V_292 ++ ;
V_348 = * V_292 ++ ;
break;
case 2 :
V_165 = * V_292 ++ ;
V_166 = * V_292 ++ ;
break;
case 1 :
V_165 = * V_292 ++ ;
break;
}
F_169 ( V_3 , V_75 , V_165 , V_166 , V_348 , 0 ) ;
}
return V_155 ;
}
static int F_171 ( struct V_2 * V_3 , int V_75 ,
T_4 V_343 , T_11 V_26 , T_4 V_345 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 ;
T_4 V_346 ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( V_16 -> V_339 )
F_71 ( L_99 ,
V_75 ,
V_343 , V_26 & 0xff , ( V_26 >> 8 ) & 0xff ) ;
F_160 ( V_3 , V_75 , V_329 ) ;
if ( F_101 ( F_9 ( V_3 , F_123 ( V_75 ) ) , 16 , 16 ) ) {
F_44 ( L_100 ) ;
return - V_153 ;
}
V_346 = V_343 | V_16 -> V_149 [ V_75 ] . V_347 << 6 ;
V_155 = ( V_346 << 0 ) | ( V_26 << 8 ) | ( V_345 << 24 ) ;
F_7 ( V_3 , F_127 ( V_75 ) , V_155 ) ;
return 0 ;
}
static int F_162 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_170 ( V_3 , V_75 , V_350 , NULL ,
0 , 0 ) ;
}
static int F_172 ( struct V_2 * V_3 ,
int V_75 , T_4 * V_26 , int V_344 , enum V_351 type )
{
int V_155 ;
if ( V_344 == 0 ) {
F_61 ( type == V_352 ) ;
V_155 = F_171 ( V_3 , V_75 ,
V_353 , 0 , 0 ) ;
} else if ( V_344 == 1 ) {
V_155 = F_171 ( V_3 , V_75 ,
type == V_354 ?
V_355 :
V_356 , V_26 [ 0 ] , 0 ) ;
} else if ( V_344 == 2 ) {
V_155 = F_171 ( V_3 , V_75 ,
type == V_354 ?
V_357 :
V_358 ,
V_26 [ 0 ] | ( V_26 [ 1 ] << 8 ) , 0 ) ;
} else {
V_155 = F_170 ( V_3 , V_75 ,
type == V_354 ?
V_359 :
V_360 , V_26 , V_344 , 0 ) ;
}
return V_155 ;
}
static int F_173 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_344 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_172 ( V_3 , V_75 , V_26 , V_344 ,
V_352 ) ;
}
static int F_174 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_344 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_172 ( V_3 , V_75 , V_26 , V_344 ,
V_354 ) ;
}
static int F_175 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_344 , enum V_351 type )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_155 ;
V_155 = F_172 ( V_3 , V_75 , V_26 , V_344 , type ) ;
if ( V_155 )
goto V_333;
V_155 = F_167 ( V_6 , V_75 ) ;
if ( V_155 )
goto V_333;
if ( F_19 ( V_3 , F_123 ( V_75 ) , 20 , 20 ) ) {
F_44 ( L_101 ) ;
F_165 ( V_3 , V_75 ) ;
V_155 = - V_174 ;
goto V_333;
}
return 0 ;
V_333:
F_44 ( L_102 ,
V_75 , V_26 [ 0 ] , V_344 ) ;
return V_155 ;
}
static int F_176 ( struct V_5 * V_6 , int V_75 , T_4 * V_26 ,
int V_344 )
{
return F_175 ( V_6 , V_75 , V_26 , V_344 ,
V_352 ) ;
}
static int F_177 ( struct V_5 * V_6 , int V_75 , T_4 * V_26 ,
int V_344 )
{
return F_175 ( V_6 , V_75 , V_26 , V_344 ,
V_354 ) ;
}
static int F_178 ( struct V_2 * V_3 ,
int V_75 , T_4 V_361 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
if ( V_16 -> V_340 )
F_71 ( L_103 ,
V_75 , V_361 ) ;
V_155 = F_171 ( V_3 , V_75 , V_362 , V_361 , 0 ) ;
if ( V_155 ) {
F_44 ( L_104
L_105 , V_75 , V_361 ) ;
return V_155 ;
}
return 0 ;
}
static int F_179 ( struct V_2 * V_3 ,
int V_75 , T_4 * V_363 , int V_364 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_11 V_26 ;
T_4 V_343 ;
int V_155 ;
if ( V_16 -> V_340 )
F_71 ( L_106 ,
V_75 , V_364 ) ;
if ( V_364 == 0 ) {
V_343 = V_365 ;
V_26 = 0 ;
} else if ( V_364 == 1 ) {
V_343 = V_366 ;
V_26 = V_363 [ 0 ] ;
} else if ( V_364 == 2 ) {
V_343 = V_367 ;
V_26 = V_363 [ 0 ] | ( V_363 [ 1 ] << 8 ) ;
} else {
F_26 () ;
return - V_153 ;
}
V_155 = F_171 ( V_3 , V_75 , V_343 , V_26 , 0 ) ;
if ( V_155 ) {
F_44 ( L_107
L_105 , V_75 , V_364 ) ;
return V_155 ;
}
return 0 ;
}
static int F_180 ( struct V_2 * V_3 , int V_75 ,
T_4 * V_368 , int V_369 , enum V_351 type )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_334 ;
int V_155 ;
if ( F_19 ( V_3 , F_123 ( V_75 ) , 20 , 20 ) == 0 ) {
F_44 ( L_108 ) ;
V_155 = - V_174 ;
goto V_333;
}
V_15 = F_9 ( V_3 , F_127 ( V_75 ) ) ;
if ( V_16 -> V_340 )
F_71 ( L_109 , V_15 ) ;
V_334 = F_101 ( V_15 , 5 , 0 ) ;
if ( V_334 == V_335 ) {
T_11 V_333 = F_101 ( V_15 , 23 , 8 ) ;
F_164 ( V_333 ) ;
V_155 = - V_174 ;
goto V_333;
} else if ( V_334 == ( type == V_354 ?
V_370 :
V_336 ) ) {
T_4 V_26 = F_101 ( V_15 , 15 , 8 ) ;
if ( V_16 -> V_340 )
F_71 ( L_110 ,
type == V_354 ? L_111 :
L_112 , V_26 ) ;
if ( V_369 < 1 ) {
V_155 = - V_174 ;
goto V_333;
}
V_368 [ 0 ] = V_26 ;
return 1 ;
} else if ( V_334 == ( type == V_354 ?
V_371 :
V_337 ) ) {
T_11 V_26 = F_101 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_340 )
F_71 ( L_113 ,
type == V_354 ? L_111 :
L_112 , V_26 ) ;
if ( V_369 < 2 ) {
V_155 = - V_174 ;
goto V_333;
}
V_368 [ 0 ] = V_26 & 0xff ;
V_368 [ 1 ] = ( V_26 >> 8 ) & 0xff ;
return 2 ;
} else if ( V_334 == ( type == V_354 ?
V_372 :
V_338 ) ) {
int V_373 ;
int V_344 = F_101 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_340 )
F_71 ( L_114 ,
type == V_354 ? L_111 :
L_112 , V_344 ) ;
if ( V_344 > V_369 ) {
V_155 = - V_174 ;
goto V_333;
}
for ( V_373 = 0 ; V_373 < V_344 + 2 ; ) {
int V_374 ;
V_15 = F_9 ( V_3 ,
F_127 ( V_75 ) ) ;
if ( V_16 -> V_340 )
F_71 ( L_115 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
for ( V_374 = 0 ; V_374 < 4 ; ++ V_374 ) {
if ( V_373 < V_344 )
V_368 [ V_373 ] = ( V_15 >> ( V_374 * 8 ) ) & 0xff ;
++ V_373 ;
}
}
return V_344 ;
} else {
F_44 ( L_90 , V_334 ) ;
V_155 = - V_174 ;
goto V_333;
}
V_333:
F_44 ( L_116 , V_75 ,
type == V_354 ? L_111 : L_112 ) ;
return V_155 ;
}
static int F_181 ( struct V_5 * V_6 , int V_75 , T_4 V_361 ,
T_4 * V_368 , int V_369 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_155 ;
V_155 = F_178 ( V_3 , V_75 , V_361 ) ;
if ( V_155 )
goto V_333;
V_155 = F_167 ( V_6 , V_75 ) ;
if ( V_155 )
goto V_333;
V_155 = F_180 ( V_3 , V_75 , V_368 , V_369 ,
V_352 ) ;
if ( V_155 < 0 )
goto V_333;
if ( V_155 != V_369 ) {
V_155 = - V_174 ;
goto V_333;
}
return 0 ;
V_333:
F_44 ( L_117 , V_75 , V_361 ) ;
return V_155 ;
}
static int F_182 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_363 , int V_364 , T_4 * V_368 , int V_369 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_155 ;
V_155 = F_179 ( V_3 , V_75 , V_363 , V_364 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_167 ( V_6 , V_75 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_180 ( V_3 , V_75 , V_368 , V_369 ,
V_354 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( V_155 != V_369 ) {
V_155 = - V_174 ;
return V_155 ;
}
return 0 ;
}
static int F_183 ( struct V_5 * V_6 , int V_75 ,
T_11 V_344 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_171 ( V_3 , V_75 ,
V_375 , V_344 , 0 ) ;
}
static int F_184 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_152 ( V_28 ) ;
int V_155 , V_109 ;
unsigned V_27 ;
F_71 ( L_118 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( V_16 -> V_301 ) ;
if ( V_16 -> V_301 )
return 0 ;
if ( F_19 ( V_3 , V_195 , 13 , 13 ) ) {
F_86 ( V_3 , 0 ) ;
F_87 ( V_3 , V_195 , 0 , 13 , 13 ) ;
F_86 ( V_3 , 1 ) ;
}
F_156 ( V_3 , 0 ) ;
F_156 ( V_3 , 1 ) ;
F_156 ( V_3 , 2 ) ;
F_156 ( V_3 , 3 ) ;
F_148 ( V_3 ) ;
F_158 ( V_3 , 0 , false ) ;
F_158 ( V_3 , 1 , false ) ;
F_158 ( V_3 , 2 , false ) ;
F_158 ( V_3 , 3 , false ) ;
if ( F_19 ( V_3 , V_244 , 16 , 16 ) ) {
F_44 ( L_119 ) ;
return - V_174 ;
}
if ( F_19 ( V_3 , V_244 , 17 , 17 ) ) {
F_44 ( L_120 ) ;
return - V_174 ;
}
V_155 = F_67 ( V_3 , F_16 , & V_28 ,
V_376 ) ;
if ( V_155 )
return V_155 ;
V_27 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_274 ; ++ V_109 ) {
if ( V_16 -> V_275 [ V_109 ] . V_276 == V_298 )
continue;
V_27 |= 1 << V_109 ;
}
F_87 ( V_3 , V_244 , V_27 , 9 , 5 ) ;
F_9 ( V_3 , V_244 ) ;
if ( F_153 ( & V_28 ,
F_20 ( 1000 ) ) == 0 ) {
F_44 ( L_121 ) ;
V_155 = - V_174 ;
goto V_333;
}
F_68 ( V_3 , F_16 , & V_28 ,
V_376 ) ;
F_87 ( V_3 , V_244 , 0 , 9 , 5 ) ;
F_9 ( V_3 , V_244 ) ;
F_130 ( V_3 , V_377 ) ;
F_86 ( V_3 , false ) ;
V_16 -> V_301 = true ;
return 0 ;
V_333:
F_68 ( V_3 , F_16 , & V_28 ,
V_376 ) ;
return V_155 ;
}
static void F_185 ( struct V_2 * V_3 ,
unsigned V_378 , bool V_379 , bool V_380 )
{
unsigned long V_381 ;
unsigned long V_382 ;
T_1 V_155 ;
F_61 ( V_378 > 0x1fff ) ;
V_381 = F_91 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_237 ) ;
V_155 = F_133 ( V_155 , 1 , 15 , 15 ) ;
V_155 = F_133 ( V_155 , V_380 ? 1 : 0 , 14 , 14 ) ;
V_155 = F_133 ( V_155 , V_379 ? 1 : 0 , 13 , 13 ) ;
V_155 = F_133 ( V_155 , V_378 , 12 , 0 ) ;
F_7 ( V_3 , V_237 , V_155 ) ;
V_382 = V_378 * ( V_380 ? 16 : 1 ) * ( V_379 ? 4 : 1 ) ;
F_71 ( L_122 ,
V_382 ,
V_378 , V_379 ? L_123 : L_4 , V_380 ? L_124 : L_4 ,
( V_382 * 1000 ) / ( V_381 / 1000 / 1000 ) ) ;
}
static void F_186 ( struct V_2 * V_3 , unsigned V_378 ,
bool V_383 , bool V_380 )
{
unsigned long V_381 ;
unsigned long V_382 ;
T_1 V_155 ;
F_61 ( V_378 > 0x1fff ) ;
V_381 = F_91 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_236 ) ;
V_155 = F_133 ( V_155 , 1 , 31 , 31 ) ;
V_155 = F_133 ( V_155 , V_380 ? 1 : 0 , 30 , 30 ) ;
V_155 = F_133 ( V_155 , V_383 ? 1 : 0 , 29 , 29 ) ;
V_155 = F_133 ( V_155 , V_378 , 28 , 16 ) ;
F_7 ( V_3 , V_236 , V_155 ) ;
V_382 = V_378 * ( V_380 ? 16 : 1 ) * ( V_383 ? 8 : 1 ) ;
F_71 ( L_125 ,
V_382 ,
V_378 , V_383 ? L_126 : L_4 , V_380 ? L_124 : L_4 ,
( V_382 * 1000 ) / ( V_381 / 1000 / 1000 ) ) ;
}
static void F_187 ( struct V_2 * V_3 ,
unsigned V_378 , bool V_379 , bool V_380 )
{
unsigned long V_381 ;
unsigned long V_382 ;
T_1 V_155 ;
F_61 ( V_378 > 0x1fff ) ;
V_381 = F_91 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_236 ) ;
V_155 = F_133 ( V_155 , 1 , 15 , 15 ) ;
V_155 = F_133 ( V_155 , V_380 ? 1 : 0 , 14 , 14 ) ;
V_155 = F_133 ( V_155 , V_379 ? 1 : 0 , 13 , 13 ) ;
V_155 = F_133 ( V_155 , V_378 , 12 , 0 ) ;
F_7 ( V_3 , V_236 , V_155 ) ;
V_382 = V_378 * ( V_380 ? 16 : 1 ) * ( V_379 ? 4 : 1 ) ;
F_71 ( L_127 ,
V_382 ,
V_378 , V_379 ? L_123 : L_4 , V_380 ? L_124 : L_4 ,
( V_382 * 1000 ) / ( V_381 / 1000 / 1000 ) ) ;
}
static void F_188 ( struct V_2 * V_3 ,
unsigned V_378 , bool V_379 , bool V_380 )
{
unsigned long V_381 ;
unsigned long V_382 ;
T_1 V_155 ;
F_61 ( V_378 > 0x1fff ) ;
V_381 = F_90 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_237 ) ;
V_155 = F_133 ( V_155 , 1 , 31 , 31 ) ;
V_155 = F_133 ( V_155 , V_380 ? 1 : 0 , 30 , 30 ) ;
V_155 = F_133 ( V_155 , V_379 ? 1 : 0 , 29 , 29 ) ;
V_155 = F_133 ( V_155 , V_378 , 28 , 16 ) ;
F_7 ( V_3 , V_237 , V_155 ) ;
V_382 = V_378 * ( V_380 ? 16 : 1 ) * ( V_379 ? 4 : 1 ) ;
F_71 ( L_128 ,
V_382 ,
V_378 , V_379 ? L_123 : L_4 , V_380 ? L_124 : L_4 ,
( V_382 * 1000 ) / ( V_381 / 1000 / 1000 ) ) ;
}
static void F_189 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_384 ;
if ( V_16 -> V_306 == V_307 ) {
int V_385 = F_25 ( V_16 -> V_386 ) ;
struct V_387 * V_388 = & V_16 -> V_388 ;
if ( V_16 -> V_389 <= V_388 -> V_390 * V_385 / 8 )
V_384 = 0 ;
else
V_384 = 2 ;
} else {
V_384 = 2 ;
}
F_87 ( V_3 , V_173 , V_384 , 13 , 12 ) ;
}
static void F_190 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
bool V_391 ;
T_1 V_155 ;
if ( V_16 -> V_308 . V_392 == V_393 )
V_391 = true ;
else
V_391 = false ;
V_155 = F_9 ( V_3 , V_173 ) ;
V_155 = F_133 ( V_155 , 1 , 9 , 9 ) ;
V_155 = F_133 ( V_155 , 1 , 10 , 10 ) ;
V_155 = F_133 ( V_155 , 1 , 11 , 11 ) ;
V_155 = F_133 ( V_155 , 1 , 15 , 15 ) ;
V_155 = F_133 ( V_155 , V_391 , 16 , 16 ) ;
V_155 = F_133 ( V_155 , 1 , 17 , 17 ) ;
V_155 = F_133 ( V_155 , V_391 , 18 , 18 ) ;
F_7 ( V_3 , V_173 , V_155 ) ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_394 = V_16 -> V_308 . V_394 ;
int V_395 = V_16 -> V_308 . V_395 ;
int V_396 = V_16 -> V_308 . V_396 ;
int V_397 = V_16 -> V_308 . V_397 ;
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_173 ) ;
V_155 = F_133 ( V_155 , V_394 , 20 , 20 ) ;
V_155 = F_133 ( V_155 , V_395 , 21 , 21 ) ;
V_155 = F_133 ( V_155 , V_396 , 22 , 22 ) ;
V_155 = F_133 ( V_155 , V_397 , 23 , 23 ) ;
F_7 ( V_3 , V_173 , V_155 ) ;
}
static int F_192 ( int V_398 , bool V_399 , int V_400 ,
int V_401 , int V_402 , int V_403 , int V_404 )
{
int V_405 ;
if ( V_399 ) {
V_405 = V_400 + V_401 + F_193 ( V_400 , 2 ) + 1 ;
} else {
int V_406 , V_407 ;
V_406 = V_403 + V_400 + V_401 + F_193 ( V_400 , 2 ) + 1 ;
V_407 = V_403 + V_400 + V_402 + V_404 + V_403 +
V_400 + 1 ;
V_405 = F_193 ( V_406 , V_407 ) ;
}
return V_398 > V_405 ? V_398 - V_405 : 0 ;
}
static int F_194 ( int V_398 , int V_400 , int V_401 ,
int V_189 , int V_408 )
{
int V_409 ;
int V_410 ;
int V_411 ;
int V_412 = 16 ;
int V_413 ;
V_409 = V_401 + F_193 ( V_400 , 2 ) + 1 ;
V_410 = V_412 * ( V_398 - V_409 ) ;
V_411 = V_408 * V_189 ;
V_413 = ( ( V_410 - 8 * V_412 - 5 * V_408 ) / V_411 -
26 ) / 16 ;
return F_193 ( V_413 , 0 ) ;
}
static void F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_394 ;
int V_395 , V_396 , V_397 ;
int V_414 , V_415 , V_416 , V_417 , V_418 , V_189 ;
int V_419 , V_420 , V_421 , V_422 ;
int V_285 , V_283 , V_402 ;
bool V_399 ;
struct V_387 * V_388 = & V_16 -> V_388 ;
int V_385 = F_25 ( V_16 -> V_386 ) ;
int V_423 = V_16 -> V_270 - 1 ;
int V_424 = V_16 -> V_425 . V_206 [ V_179 ] + 1 ;
int V_426 = 0 , V_427 = 0 ;
int V_428 = 0 , V_429 = 0 ;
int V_430 = 0 , V_431 = 0 ;
int V_432 = 0 , V_433 = 0 ;
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_173 ) ;
V_394 = F_101 ( V_155 , 20 , 20 ) ;
V_395 = F_101 ( V_155 , 21 , 21 ) ;
V_396 = F_101 ( V_155 , 22 , 22 ) ;
V_397 = F_101 ( V_155 , 23 , 23 ) ;
V_155 = F_9 ( V_3 , V_238 ) ;
V_416 = F_101 ( V_155 , 11 , 0 ) ;
V_415 = F_101 ( V_155 , 23 , 12 ) ;
V_414 = F_101 ( V_155 , 31 , 24 ) ;
V_155 = F_9 ( V_3 , V_241 ) ;
V_420 = F_101 ( V_155 , 7 , 0 ) ;
V_419 = F_101 ( V_155 , 15 , 8 ) ;
V_155 = F_9 ( V_3 , V_250 ) ;
V_422 = F_101 ( V_155 , 15 , 0 ) ;
V_421 = F_101 ( V_155 , 31 , 16 ) ;
V_155 = F_9 ( V_3 , V_195 ) ;
V_189 = F_101 ( V_155 , 12 , 0 ) ;
V_399 = F_101 ( V_155 , 13 , 13 ) ;
V_155 = F_9 ( V_3 , V_252 ) ;
V_283 = F_101 ( V_155 , 7 , 0 ) ;
V_155 = F_9 ( V_3 , V_253 ) ;
V_285 = F_101 ( V_155 , 15 , 8 ) ;
V_402 = V_283 + V_285 ;
V_417 = F_95 ( V_388 -> V_390 * V_385 , 8 ) ;
V_418 = V_416 + V_415 + V_414 + F_95 ( V_417 + 6 , V_423 ) ;
if ( ! V_397 ) {
V_426 = F_192 ( V_414 , V_399 ,
V_421 , V_422 ,
V_402 , V_419 , V_420 ) ;
V_427 = F_194 ( V_414 ,
V_421 , V_422 ,
V_189 , V_424 ) ;
}
if ( ! V_395 ) {
V_428 = F_192 ( V_415 , V_399 ,
V_421 , V_422 ,
V_402 , V_419 , V_420 ) ;
V_429 = F_194 ( V_415 ,
V_421 , V_422 ,
V_189 , V_424 ) ;
}
if ( ! V_396 ) {
V_430 = F_192 ( V_416 , V_399 ,
V_421 , V_422 ,
V_402 , V_419 , V_420 ) ;
V_431 = F_194 ( V_416 ,
V_421 , V_422 ,
V_189 , V_424 ) ;
}
if ( ! V_394 ) {
V_432 = F_192 ( V_418 , V_399 ,
V_421 , V_422 ,
V_402 , V_419 , V_420 ) ;
V_433 = F_194 ( V_418 ,
V_421 , V_422 ,
V_189 , V_424 ) ;
}
F_71 ( L_129 ,
V_426 , V_428 , V_430 ,
V_432 ) ;
F_71 ( L_130 ,
V_427 , V_429 , V_431 ,
V_433 ) ;
V_155 = F_9 ( V_3 , V_246 ) ;
V_155 = F_133 ( V_155 , V_426 , 23 , 16 ) ;
V_155 = F_133 ( V_155 , V_428 , 15 , 8 ) ;
V_155 = F_133 ( V_155 , V_430 , 7 , 0 ) ;
F_7 ( V_3 , V_246 , V_155 ) ;
V_155 = F_9 ( V_3 , V_248 ) ;
V_155 = F_133 ( V_155 , V_427 , 23 , 16 ) ;
V_155 = F_133 ( V_155 , V_429 , 15 , 8 ) ;
V_155 = F_133 ( V_155 , V_431 , 7 , 0 ) ;
F_7 ( V_3 , V_248 , V_155 ) ;
V_155 = F_9 ( V_3 , V_249 ) ;
V_155 = F_133 ( V_155 , V_432 , 31 , 15 ) ;
V_155 = F_133 ( V_155 , V_433 , 16 , 0 ) ;
F_7 ( V_3 , V_249 , V_155 ) ;
}
static int F_196 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 ;
int V_434 = 0 ;
F_145 ( V_3 , V_435 ,
V_435 ,
V_435 ,
V_435 ) ;
F_147 ( V_3 , V_435 ,
V_435 ,
V_435 ,
V_435 ) ;
F_187 ( V_3 , 0x1000 , false , false ) ;
F_186 ( V_3 , 0x1fff , true , true ) ;
F_185 ( V_3 , 0x1fff , true , true ) ;
F_188 ( V_3 , 0x1fff , true , true ) ;
switch ( F_25 ( V_16 -> V_386 ) ) {
case 16 :
V_434 = 0 ;
break;
case 18 :
V_434 = 1 ;
break;
case 24 :
V_434 = 2 ;
break;
default:
F_26 () ;
return - V_153 ;
}
V_155 = F_9 ( V_3 , V_173 ) ;
V_155 = F_133 ( V_155 , 1 , 1 , 1 ) ;
V_155 = F_133 ( V_155 , 1 , 2 , 2 ) ;
V_155 = F_133 ( V_155 , 1 , 3 , 3 ) ;
V_155 = F_133 ( V_155 , 1 , 4 , 4 ) ;
V_155 = F_133 ( V_155 , V_434 , 7 , 6 ) ;
V_155 = F_133 ( V_155 , 0 , 8 , 8 ) ;
V_155 = F_133 ( V_155 , 1 , 14 , 14 ) ;
V_155 = F_133 ( V_155 , 1 , 19 , 19 ) ;
if ( ! F_84 ( V_332 ) ) {
V_155 = F_133 ( V_155 , 1 , 24 , 24 ) ;
V_155 = F_133 ( V_155 , 0 , 25 , 25 ) ;
}
F_7 ( V_3 , V_173 , V_155 ) ;
F_189 ( V_3 ) ;
if ( V_16 -> V_306 == V_307 ) {
F_190 ( V_3 ) ;
F_191 ( V_3 ) ;
F_195 ( V_3 ) ;
}
F_159 ( V_3 , 0 ) ;
F_159 ( V_3 , 1 ) ;
F_159 ( V_3 , 2 ) ;
F_159 ( V_3 , 3 ) ;
return 0 ;
}
static void F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_436 , V_286 , V_287 , V_285 ;
unsigned V_437 , V_438 ;
unsigned V_280 , V_281 , V_439 ;
unsigned V_282 , V_283 ;
unsigned V_419 , V_420 ;
unsigned V_421 , V_422 ;
unsigned V_440 ;
int V_423 = V_16 -> V_270 - 1 ;
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_252 ) ;
V_280 = F_101 ( V_155 , 31 , 24 ) ;
V_281 = F_101 ( V_155 , 23 , 16 ) ;
V_439 = V_281 - V_280 ;
V_282 = F_101 ( V_155 , 15 , 8 ) ;
V_283 = F_101 ( V_155 , 7 , 0 ) ;
V_155 = F_9 ( V_3 , V_253 ) ;
V_436 = F_101 ( V_155 , 20 , 16 ) * 2 ;
V_285 = F_101 ( V_155 , 15 , 8 ) ;
V_286 = F_101 ( V_155 , 7 , 0 ) ;
V_155 = F_9 ( V_3 , V_254 ) ;
V_287 = F_101 ( V_155 , 7 , 0 ) ;
V_437 = 20 ;
V_438 = F_134 ( V_3 , 60 ) + 26 ;
V_440 = F_95 ( 4 , V_423 ) ;
V_419 = F_95 ( V_437 + V_436 + V_286 + V_287 ,
4 ) ;
V_420 = F_95 ( V_438 + V_282 , 4 ) + V_440 ;
F_61 ( V_419 == 0 || V_419 > 255 ) ;
F_61 ( V_420 == 0 || V_420 > 255 ) ;
V_155 = F_9 ( V_3 , V_241 ) ;
V_155 = F_133 ( V_155 , V_419 , 15 , 8 ) ;
V_155 = F_133 ( V_155 , V_420 , 7 , 0 ) ;
F_7 ( V_3 , V_241 , V_155 ) ;
F_71 ( L_131 ,
V_419 ,
V_420 ) ;
V_421 = 1 + F_95 ( V_436 , 4 ) +
F_95 ( V_280 , 4 ) +
F_95 ( V_439 + 3 , 4 ) ;
V_422 = F_95 ( V_282 + V_283 , 4 ) + 1 + V_440 ;
V_155 = F_146 ( V_421 , 31 , 16 ) |
F_146 ( V_422 , 15 , 0 ) ;
F_7 ( V_3 , V_250 , V_155 ) ;
F_71 ( L_132 ,
V_421 , V_422 ) ;
if ( V_16 -> V_306 == V_307 ) {
int V_414 = V_16 -> V_308 . V_414 ;
int V_415 = V_16 -> V_308 . V_415 ;
int V_416 = V_16 -> V_308 . V_416 ;
int V_441 = V_16 -> V_308 . V_441 ;
int V_442 = V_16 -> V_308 . V_442 ;
int V_443 = V_16 -> V_308 . V_443 ;
int V_444 = V_16 -> V_308 . V_444 ;
bool V_445 ;
struct V_387 * V_388 = & V_16 -> V_388 ;
int V_385 = F_25 ( V_16 -> V_386 ) ;
int V_446 , V_447 , V_417 ;
V_445 = V_16 -> V_308 . V_392 == V_393 ;
V_447 = V_445 ?
( ( V_414 == 0 && V_423 == 3 ) ? 1 : F_95 ( 4 , V_423 ) ) : 0 ;
V_417 = F_95 ( V_388 -> V_390 * V_385 , 8 ) ;
V_446 = F_95 ( 4 , V_423 ) + ( V_445 ? V_414 : 0 ) + V_447 + V_415 +
F_95 ( V_417 + 6 , V_423 ) + V_416 ;
F_71 ( L_133 , V_416 ,
V_415 , V_445 ? V_414 : 0 , V_446 ) ;
F_71 ( L_134 , V_443 , V_442 ,
V_441 , V_388 -> V_448 ) ;
V_155 = F_9 ( V_3 , V_238 ) ;
V_155 = F_133 ( V_155 , V_416 , 11 , 0 ) ;
V_155 = F_133 ( V_155 , V_415 , 23 , 12 ) ;
V_155 = F_133 ( V_155 , V_445 ? V_414 : 0 , 31 , 24 ) ;
F_7 ( V_3 , V_238 , V_155 ) ;
V_155 = F_9 ( V_3 , V_239 ) ;
V_155 = F_133 ( V_155 , V_443 , 7 , 0 ) ;
V_155 = F_133 ( V_155 , V_442 , 15 , 8 ) ;
V_155 = F_133 ( V_155 , V_441 , 23 , 16 ) ;
V_155 = F_133 ( V_155 , V_444 , 27 , 24 ) ;
F_7 ( V_3 , V_239 , V_155 ) ;
V_155 = F_9 ( V_3 , V_240 ) ;
V_155 = F_133 ( V_155 , V_388 -> V_448 , 14 , 0 ) ;
V_155 = F_133 ( V_155 , V_446 , 31 , 16 ) ;
F_7 ( V_3 , V_240 , V_155 ) ;
}
}
static int F_198 ( struct V_5 * V_6 ,
const struct V_449 * V_450 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_451 ;
const int * V_452 ;
struct V_453 V_275 [ V_295 ] ;
int V_454 ;
int V_109 ;
static const enum V_263 V_264 [] = {
V_265 ,
V_266 ,
V_267 ,
V_268 ,
V_269 ,
} ;
V_451 = V_450 -> V_451 ;
V_452 = V_450 -> V_452 ;
if ( V_451 < 4 || V_451 > V_16 -> V_274 * 2
|| V_451 % 2 != 0 )
return - V_153 ;
for ( V_109 = 0 ; V_109 < V_295 ; ++ V_109 )
V_275 [ V_109 ] . V_276 = V_298 ;
V_454 = 0 ;
for ( V_109 = 0 ; V_109 < V_451 ; V_109 += 2 ) {
T_4 V_455 , V_456 ;
int V_457 , V_458 ;
V_457 = V_452 [ V_109 ] ;
V_458 = V_452 [ V_109 + 1 ] ;
if ( V_457 < 0 || V_457 >= V_16 -> V_274 * 2 )
return - V_153 ;
if ( V_458 < 0 || V_458 >= V_16 -> V_274 * 2 )
return - V_153 ;
if ( V_457 & 1 ) {
if ( V_458 != V_457 - 1 )
return - V_153 ;
V_456 = 1 ;
} else {
if ( V_458 != V_457 + 1 )
return - V_153 ;
V_456 = 0 ;
}
V_455 = V_457 / 2 ;
V_275 [ V_455 ] . V_276 = V_264 [ V_109 / 2 ] ;
V_275 [ V_455 ] . V_272 = V_456 ;
V_454 ++ ;
}
memcpy ( V_16 -> V_275 , V_275 , sizeof( V_16 -> V_275 ) ) ;
V_16 -> V_270 = V_454 ;
return 0 ;
}
static int F_199 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_459 * V_460 = V_16 -> V_461 . V_462 ;
int V_385 = F_25 ( V_16 -> V_386 ) ;
struct V_5 * V_8 = & V_16 -> V_461 ;
T_4 V_343 ;
T_11 V_463 ;
int V_155 ;
if ( V_8 -> V_462 == NULL ) {
F_44 ( L_135 ) ;
return - V_202 ;
}
V_155 = F_200 ( V_3 , V_460 ) ;
if ( V_155 )
goto V_464;
if ( V_16 -> V_306 == V_307 ) {
switch ( V_16 -> V_386 ) {
case V_39 :
V_343 = V_465 ;
break;
case V_40 :
V_343 = V_466 ;
break;
case V_41 :
V_343 = V_467 ;
break;
case V_42 :
V_343 = V_468 ;
break;
default:
V_155 = - V_153 ;
goto V_469;
}
F_86 ( V_3 , false ) ;
F_158 ( V_3 , V_75 , false ) ;
F_87 ( V_3 , F_123 ( V_75 ) , 1 , 4 , 4 ) ;
V_463 = F_95 ( V_16 -> V_388 . V_390 * V_385 , 8 ) ;
F_168 ( V_3 , V_75 , V_343 ,
V_463 , 0 ) ;
F_158 ( V_3 , V_75 , true ) ;
F_86 ( V_3 , true ) ;
}
V_155 = F_201 ( V_460 ) ;
if ( V_155 )
goto V_470;
return 0 ;
V_470:
if ( V_16 -> V_306 == V_307 ) {
F_86 ( V_3 , false ) ;
F_158 ( V_3 , V_75 , false ) ;
}
V_469:
F_202 ( V_3 , V_460 ) ;
V_464:
return V_155 ;
}
static void F_203 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_459 * V_460 = V_16 -> V_461 . V_462 ;
if ( V_16 -> V_306 == V_307 ) {
F_86 ( V_3 , false ) ;
F_158 ( V_3 , V_75 , false ) ;
F_87 ( V_3 , F_123 ( V_75 ) , 0 , 4 , 4 ) ;
F_158 ( V_3 , V_75 , true ) ;
F_86 ( V_3 , true ) ;
}
F_204 ( V_460 ) ;
F_202 ( V_3 , V_460 ) ;
}
static void F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_459 * V_460 = V_16 -> V_461 . V_462 ;
unsigned V_471 ;
unsigned V_472 ;
unsigned V_473 ;
unsigned V_474 ;
unsigned V_475 ;
unsigned V_476 ;
T_1 V_163 ;
int V_155 ;
const unsigned V_75 = V_16 -> V_323 ;
const unsigned V_477 = V_16 -> V_389 ;
T_11 V_373 = V_16 -> V_388 . V_390 ;
T_11 V_478 = V_16 -> V_388 . V_448 ;
F_71 ( L_136 , V_373 , V_478 ) ;
F_160 ( V_3 , V_75 , V_328 ) ;
V_471 = F_25 ( V_16 -> V_386 ) / 8 ;
V_472 = V_373 * V_471 ;
V_473 = V_472 * V_478 ;
if ( V_473 < V_477 )
V_475 = V_473 ;
else
V_475 = ( V_477 ) / V_472 * V_472 ;
V_476 = V_475 + 1 ;
V_474 = ( V_473 / V_475 ) * V_476 ;
if ( V_473 % V_475 )
V_474 += ( V_473 % V_475 ) + 1 ;
V_163 = F_146 ( V_474 , 23 , 0 ) ;
F_7 ( V_3 , F_124 ( V_75 ) , V_163 ) ;
F_168 ( V_3 , V_75 , V_360 ,
V_476 , 0 ) ;
if ( V_16 -> V_325 )
V_163 = F_133 ( V_163 , 1 , 30 , 30 ) ;
else
V_163 = F_133 ( V_163 , 1 , 31 , 31 ) ;
F_7 ( V_3 , F_124 ( V_75 ) , V_163 ) ;
F_206 () ;
F_29 ( V_3 ) ;
V_155 = F_207 ( & V_16 -> V_479 ,
F_20 ( 250 ) ) ;
F_61 ( V_155 == 0 ) ;
F_208 ( V_460 , & V_16 -> V_388 ) ;
F_209 ( V_460 ) ;
if ( V_16 -> V_325 ) {
F_87 ( V_3 , V_237 , 0 , 15 , 15 ) ;
F_166 ( V_3 , V_75 ) ;
#ifdef F_50
F_210 ( & V_16 -> V_141 , V_34 + F_20 ( 250 ) ) ;
#endif
}
}
static void F_211 ( unsigned long V_127 )
{
F_44 ( L_137 ) ;
}
static void F_212 ( struct V_2 * V_3 , int error )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_213 () ;
if ( V_16 -> V_325 ) {
F_87 ( V_3 , V_237 , 1 , 15 , 15 ) ;
}
V_16 -> V_480 ( error , V_16 -> V_481 ) ;
if ( ! error )
F_30 ( V_3 , L_138 ) ;
}
static void F_214 ( struct V_482 * V_483 )
{
struct V_1 * V_16 = F_105 ( V_483 , struct V_1 ,
V_479 . V_483 ) ;
F_44 ( L_139 ) ;
F_212 ( V_16 -> V_157 , - V_484 ) ;
}
static void F_215 ( void * V_26 )
{
struct V_2 * V_3 = (struct V_2 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_216 ( & V_16 -> V_479 ) ;
F_212 ( V_3 , 0 ) ;
}
static int F_217 ( struct V_5 * V_6 , int V_75 ,
void (* F_218)( int , void * ) , void * V_26 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_11 V_485 , V_486 ;
F_27 ( V_3 ) ;
V_16 -> V_323 = V_75 ;
V_16 -> V_480 = F_218 ;
V_16 -> V_481 = V_26 ;
V_485 = V_16 -> V_388 . V_390 ;
V_486 = V_16 -> V_388 . V_448 ;
#ifdef F_219
V_16 -> V_53 = V_485 * V_486 *
F_25 ( V_16 -> V_386 ) / 8 ;
#endif
F_205 ( V_3 ) ;
return 0 ;
}
static int F_220 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_487 V_488 ;
int V_155 ;
unsigned long V_381 ;
V_381 = F_88 ( V_3 ) ;
V_488 . V_489 = V_16 -> V_490 . V_489 ;
V_488 . V_491 = V_16 -> V_490 . V_491 ;
V_155 = F_221 ( V_381 , & V_488 ) ;
if ( V_155 ) {
F_44 ( L_140 ) ;
return V_155 ;
}
V_16 -> V_492 . V_493 = V_488 ;
return 0 ;
}
static int F_200 ( struct V_2 * V_3 ,
struct V_459 * V_460 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
F_222 ( V_460 -> V_10 , V_16 -> V_181 == 0 ?
V_224 :
V_225 ) ;
if ( V_16 -> V_306 == V_494 ) {
V_155 = F_223 ( V_460 ,
F_215 , V_3 ) ;
if ( V_155 ) {
F_44 ( L_141 ) ;
goto V_333;
}
V_16 -> V_492 . V_495 = true ;
V_16 -> V_492 . V_496 = true ;
} else {
V_16 -> V_492 . V_495 = false ;
V_16 -> V_492 . V_496 = false ;
}
V_16 -> V_388 . V_497 = false ;
V_16 -> V_388 . V_498 = V_499 ;
V_16 -> V_388 . V_500 = V_499 ;
V_16 -> V_388 . V_501 = V_502 ;
V_16 -> V_388 . V_503 = V_499 ;
V_16 -> V_388 . V_504 = V_505 ;
F_208 ( V_460 , & V_16 -> V_388 ) ;
V_155 = F_220 ( V_3 ) ;
if ( V_155 )
goto V_211;
V_16 -> V_492 . V_506 = V_507 ;
V_16 -> V_492 . V_508 =
F_25 ( V_16 -> V_386 ) ;
V_16 -> V_492 . V_509 = 0 ;
F_224 ( V_460 , & V_16 -> V_492 ) ;
return 0 ;
V_211:
if ( V_16 -> V_306 == V_494 )
F_225 ( V_460 ,
F_215 , V_3 ) ;
V_333:
F_222 ( V_460 -> V_10 , V_182 ) ;
return V_155 ;
}
static void F_202 ( struct V_2 * V_3 ,
struct V_459 * V_460 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_306 == V_494 )
F_225 ( V_460 ,
F_215 , V_3 ) ;
F_222 ( V_460 -> V_10 , V_182 ) ;
}
static int F_226 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_203 V_176 ;
int V_155 ;
V_176 = V_16 -> V_425 ;
V_155 = F_227 ( & V_16 -> V_175 , & V_176 ) ;
if ( V_155 ) {
F_44 ( L_142 ) ;
return V_155 ;
}
return 0 ;
}
static int F_228 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
V_155 = F_229 ( & V_16 -> V_175 ) ;
if ( V_155 )
goto V_209;
V_155 = F_226 ( V_3 ) ;
if ( V_155 )
goto V_211;
F_230 ( V_16 -> V_181 , V_16 -> V_181 == 0 ?
V_226 :
V_227 ) ;
F_71 ( L_143 ) ;
V_155 = F_141 ( V_3 ) ;
if ( V_155 )
goto V_342;
F_83 ( V_3 ) ;
F_197 ( V_3 ) ;
F_96 ( V_3 ) ;
if ( 1 )
F_83 ( V_3 ) ;
V_155 = F_196 ( V_3 ) ;
if ( V_155 )
goto V_510;
F_158 ( V_3 , 0 , 1 ) ;
F_158 ( V_3 , 1 , 1 ) ;
F_158 ( V_3 , 2 , 1 ) ;
F_158 ( V_3 , 3 , 1 ) ;
F_86 ( V_3 , 1 ) ;
F_148 ( V_3 ) ;
return 0 ;
V_510:
F_144 ( V_3 ) ;
V_342:
F_230 ( V_16 -> V_181 , V_182 ) ;
V_211:
F_231 ( & V_16 -> V_175 ) ;
V_209:
return V_155 ;
}
static void F_232 ( struct V_2 * V_3 ,
bool V_212 , bool V_511 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_511 && ! V_16 -> V_301 )
F_184 ( V_3 ) ;
F_86 ( V_3 , 0 ) ;
F_158 ( V_3 , 0 , 0 ) ;
F_158 ( V_3 , 1 , 0 ) ;
F_158 ( V_3 , 2 , 0 ) ;
F_158 ( V_3 , 3 , 0 ) ;
F_230 ( V_16 -> V_181 , V_182 ) ;
F_144 ( V_3 ) ;
F_109 ( V_3 , V_212 ) ;
}
static int F_233 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 = 0 ;
F_71 ( L_144 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_234 ( & V_16 -> V_512 ) ;
V_155 = F_70 ( V_3 ) ;
if ( V_155 )
goto V_513;
F_57 ( V_3 ) ;
V_155 = F_228 ( V_3 ) ;
if ( V_155 )
goto V_514;
F_235 ( & V_16 -> V_512 ) ;
return 0 ;
V_514:
F_74 ( V_3 ) ;
V_513:
F_235 ( & V_16 -> V_512 ) ;
F_71 ( L_145 ) ;
return V_155 ;
}
static void F_236 ( struct V_5 * V_6 ,
bool V_212 , bool V_511 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_146 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_234 ( & V_16 -> V_512 ) ;
F_156 ( V_3 , 0 ) ;
F_156 ( V_3 , 1 ) ;
F_156 ( V_3 , 2 ) ;
F_156 ( V_3 , 3 ) ;
F_232 ( V_3 , V_212 , V_511 ) ;
F_74 ( V_3 ) ;
F_235 ( & V_16 -> V_512 ) ;
}
static int F_237 ( struct V_5 * V_6 , bool V_172 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_325 = V_172 ;
return 0 ;
}
static void F_238 ( const char * V_515 ,
const struct V_516 * V_33 )
{
unsigned long V_517 = V_33 -> V_518 / 4 ;
int V_519 , V_520 , V_521 , V_522 ;
V_520 = F_95 ( V_33 -> V_523 * V_33 -> V_524 , 8 ) ;
V_521 = F_95 ( V_520 + 6 , V_33 -> V_423 ) ;
V_519 = V_33 -> V_525 + V_33 -> V_414 + V_33 -> V_526 + V_33 -> V_416 + V_33 -> V_415 ;
V_522 = V_519 + V_521 ;
#define F_239 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, byteclk))
F_36 ( L_147
L_148 ,
V_515 ,
V_517 ,
V_33 -> V_525 , V_33 -> V_414 , V_33 -> V_526 , V_33 -> V_416 , V_521 , V_33 -> V_415 ,
V_519 , V_521 , V_522 ,
F_239 ( V_33 -> V_525 ) ,
F_239 ( V_33 -> V_414 ) ,
F_239 ( V_33 -> V_526 ) ,
F_239 ( V_33 -> V_416 ) ,
F_239 ( V_521 ) ,
F_239 ( V_33 -> V_415 ) ,
F_239 ( V_519 ) ,
F_239 ( V_521 ) ,
F_239 ( V_522 ) ) ;
#undef F_239
}
static void F_240 ( const char * V_515 , const struct V_387 * V_33 )
{
unsigned long V_527 = V_33 -> V_528 ;
int V_523 , V_519 , V_522 ;
V_523 = V_33 -> V_390 ;
V_519 = V_33 -> V_529 + V_33 -> V_416 + V_33 -> V_415 ;
V_522 = V_523 + V_519 ;
#define F_241 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, pck))
F_36 ( L_149
L_150 ,
V_515 ,
V_527 ,
V_33 -> V_529 , V_33 -> V_416 , V_523 , V_33 -> V_415 ,
V_519 , V_523 , V_522 ,
F_241 ( V_33 -> V_529 ) ,
F_241 ( V_33 -> V_416 ) ,
F_241 ( V_523 ) ,
F_241 ( V_33 -> V_415 ) ,
F_241 ( V_519 ) ,
F_241 ( V_523 ) ,
F_241 ( V_522 ) ) ;
#undef F_241
}
static void F_242 ( const char * V_515 ,
const struct V_516 * V_33 )
{
struct V_387 V_530 = { 0 } ;
unsigned long V_517 = V_33 -> V_518 / 4 ;
unsigned long V_527 ;
T_12 V_531 ;
int V_532 , V_533 ;
V_531 = ( T_12 ) V_517 * V_33 -> V_423 * 8 ;
V_527 = ( T_1 ) F_243 ( V_531 , V_33 -> V_524 ) ;
V_532 = F_95 ( F_95 ( V_33 -> V_523 * V_33 -> V_524 , 8 ) + 6 , V_33 -> V_423 ) ;
V_533 = V_33 -> V_525 + V_33 -> V_414 + V_33 -> V_526 + V_33 -> V_416 + V_532 + V_33 -> V_415 ;
V_530 . V_528 = V_527 ;
V_530 . V_529 = F_243 ( ( T_12 ) ( V_33 -> V_414 + V_33 -> V_526 ) * V_527 , V_517 ) ;
V_530 . V_416 = F_243 ( ( T_12 ) V_33 -> V_416 * V_527 , V_517 ) ;
V_530 . V_415 = F_243 ( ( T_12 ) V_33 -> V_415 * V_527 , V_517 ) ;
V_530 . V_390 = V_33 -> V_523 ;
F_240 ( V_515 , & V_530 ) ;
}
static bool F_244 ( int V_534 , int V_535 , unsigned long V_536 ,
unsigned long V_527 , void * V_26 )
{
struct V_537 * V_538 = V_26 ;
struct V_387 * V_33 = & V_538 -> V_539 ;
V_538 -> V_488 . V_489 = V_534 ;
V_538 -> V_488 . V_491 = V_535 ;
V_538 -> V_488 . V_536 = V_536 ;
V_538 -> V_488 . V_527 = V_527 ;
* V_33 = * V_538 -> V_540 -> V_388 ;
V_33 -> V_528 = V_527 ;
V_33 -> V_390 = V_538 -> V_540 -> V_388 -> V_390 ;
V_33 -> V_448 = V_538 -> V_540 -> V_388 -> V_448 ;
V_33 -> V_529 = V_33 -> V_415 = V_33 -> V_416 = V_33 -> V_541 = 1 ;
V_33 -> V_442 = V_33 -> V_443 = 0 ;
return true ;
}
static bool F_245 ( int V_542 , unsigned long V_543 ,
void * V_26 )
{
struct V_537 * V_538 = V_26 ;
V_538 -> V_544 . V_206 [ V_178 ] = V_542 ;
V_538 -> V_544 . V_177 [ V_178 ] = V_543 ;
return F_246 ( V_543 , V_538 -> V_545 , V_538 -> V_546 ,
F_244 , V_538 ) ;
}
static bool F_247 ( int V_222 , int V_223 , unsigned long V_221 ,
unsigned long V_180 , void * V_26 )
{
struct V_537 * V_538 = V_26 ;
V_538 -> V_544 . V_222 = V_222 ;
V_538 -> V_544 . V_223 = V_223 ;
V_538 -> V_544 . V_221 = V_221 ;
V_538 -> V_544 . V_180 = V_180 ;
return F_248 ( V_538 -> V_175 , V_180 , V_538 -> V_545 ,
F_97 ( V_547 ) ,
F_245 , V_538 ) ;
}
static bool F_249 ( struct V_1 * V_16 ,
const struct V_548 * V_549 ,
struct V_537 * V_538 )
{
unsigned long V_220 ;
int V_524 , V_423 ;
unsigned long V_550 , V_551 ;
unsigned long V_527 , V_552 ;
V_220 = F_93 ( V_16 -> V_175 . V_220 ) ;
V_524 = F_25 ( V_549 -> V_553 ) ;
V_423 = V_16 -> V_270 - 1 ;
V_527 = V_549 -> V_388 -> V_528 ;
V_527 = V_527 * 3 / 2 ;
V_552 = V_527 * V_524 / 8 / V_423 ;
memset ( V_538 , 0 , sizeof( * V_538 ) ) ;
V_538 -> V_3 = V_16 -> V_157 ;
V_538 -> V_175 = & V_16 -> V_175 ;
V_538 -> V_540 = V_549 ;
V_538 -> V_545 = V_527 ;
V_538 -> V_554 = V_527 ;
V_538 -> V_546 = V_527 * 3 / 2 ;
V_550 = F_193 ( V_549 -> V_555 * 4 , V_552 * 4 * 4 ) ;
V_551 = V_549 -> V_556 * 4 ;
return F_250 ( V_538 -> V_175 , V_220 ,
V_550 , V_551 ,
F_247 , V_538 ) ;
}
static bool F_251 ( struct V_537 * V_538 )
{
struct V_1 * V_16 = F_1 ( V_538 -> V_3 ) ;
const struct V_548 * V_549 = V_538 -> V_540 ;
int V_524 = F_25 ( V_549 -> V_553 ) ;
int V_423 = V_16 -> V_270 - 1 ;
unsigned long V_518 = V_538 -> V_544 . V_180 / 4 ;
unsigned long V_517 = V_518 / 4 ;
unsigned long V_557 , V_545 , V_554 , V_546 ;
int V_558 ;
int V_559 , V_560 ;
int V_561 , V_562 ;
int V_533 , V_532 , V_563 , V_525 , V_526 ;
int V_415 , V_414 , V_416 ;
const struct V_387 * V_564 ;
struct V_387 * V_539 ;
struct V_516 * V_565 ;
T_12 V_531 , V_566 ;
V_531 = ( T_12 ) V_517 * V_423 * 8 ;
V_564 = V_549 -> V_388 ;
V_545 = V_538 -> V_545 ;
V_546 = V_538 -> V_546 ;
V_554 = V_538 -> V_554 ;
V_557 = V_538 -> V_488 . V_527 ;
V_566 = ( T_12 ) V_557 * V_524 ;
V_558 = V_564 -> V_390 ;
V_560 = V_564 -> V_415 + V_564 -> V_416 + V_564 -> V_529 ;
V_559 = V_558 + V_560 ;
V_532 = F_95 ( F_95 ( V_558 * V_524 , 8 ) + 6 , V_423 ) ;
if ( V_16 -> V_389 < V_558 * V_524 / 8 ) {
if ( V_566 != V_531 )
return false ;
} else {
if ( V_566 < V_531 )
return false ;
}
if ( V_531 < ( T_12 ) V_524 * V_545 )
return false ;
if ( V_549 -> V_392 != V_567 ) {
if ( V_531 > ( T_12 ) V_524 * V_546 )
return false ;
}
V_525 = F_95 ( 4 , V_423 ) ;
if ( V_549 -> V_392 == V_393 ) {
if ( V_423 == 3 && V_564 -> V_529 == 0 )
V_526 = 1 ;
else
V_526 = F_95 ( 4 , V_423 ) ;
} else {
V_526 = 0 ;
}
V_533 = F_243 ( ( T_12 ) V_559 * V_517 , V_554 ) ;
if ( V_533 < V_525 + V_526 + V_532 )
return false ;
V_563 = V_533 - V_532 ;
V_561 = F_243 ( ( T_12 ) V_533 * V_557 , V_517 ) ;
if ( ( T_12 ) V_533 * V_557 != ( T_12 ) V_561 * V_517 )
return false ;
V_562 = V_561 - V_558 ;
V_565 = & V_538 -> V_565 ;
memset ( V_565 , 0 , sizeof( * V_565 ) ) ;
V_565 -> V_518 = V_518 ;
V_565 -> V_423 = V_423 ;
V_565 -> V_524 = V_524 ;
if ( V_549 -> V_392 != V_393 ) {
V_414 = 0 ;
} else if ( V_423 == 3 && V_564 -> V_529 == 0 ) {
V_414 = 0 ;
} else {
V_414 = F_243 ( ( T_12 ) V_564 -> V_529 * V_517 , V_554 ) ;
V_414 = F_193 ( V_414 - V_526 , 1 ) ;
}
V_416 = F_243 ( ( T_12 ) V_564 -> V_416 * V_517 , V_554 ) ;
V_416 = F_193 ( V_416 , 1 ) ;
V_415 = V_563 - ( V_525 + V_414 + V_526 + V_416 ) ;
if ( V_415 < 1 ) {
int V_33 ;
V_33 = 1 - V_415 ;
V_416 = F_193 ( V_416 - V_33 , 1 ) ;
V_415 = V_563 - ( V_525 + V_414 + V_526 + V_416 ) ;
if ( V_415 < 1 && V_414 > 0 ) {
V_33 = 1 - V_415 ;
V_414 = F_193 ( V_414 - V_33 , 1 ) ;
V_415 = V_563 - ( V_525 + V_414 + V_526 + V_416 ) ;
}
}
if ( V_415 < 1 )
return false ;
V_565 -> V_525 = V_525 ;
V_565 -> V_414 = V_414 ;
V_565 -> V_526 = V_526 ;
V_565 -> V_416 = V_416 ;
V_565 -> V_523 = V_558 ;
V_565 -> V_415 = V_415 ;
V_565 -> V_441 = V_564 -> V_541 ;
V_565 -> V_443 = V_564 -> V_443 ;
V_565 -> V_568 = V_564 -> V_448 ;
V_565 -> V_442 = V_564 -> V_442 ;
V_565 -> V_392 = V_549 -> V_392 ;
V_565 -> V_394 = 0 ;
V_565 -> V_397 = 1 ;
V_565 -> V_395 = 1 ;
V_565 -> V_396 = 1 ;
V_565 -> V_309 = V_549 -> V_309 ;
V_565 -> V_444 = 4 ;
V_539 = & V_538 -> V_539 ;
* V_539 = * V_564 ;
V_539 -> V_528 = V_557 ;
if ( V_549 -> V_392 == V_393 ) {
V_414 = F_243 ( ( T_12 ) V_564 -> V_529 * V_557 ,
V_554 ) ;
V_414 = F_193 ( V_414 , 1 ) ;
} else {
V_414 = 1 ;
}
V_416 = F_243 ( ( T_12 ) V_564 -> V_416 * V_557 , V_554 ) ;
V_416 = F_193 ( V_416 , 1 ) ;
V_415 = V_562 - V_414 - V_416 ;
if ( V_415 < 1 ) {
int V_33 ;
V_33 = 1 - V_415 ;
V_416 = F_193 ( V_416 - V_33 , 1 ) ;
V_415 = V_562 - V_414 - V_416 ;
if ( V_415 < 1 ) {
V_33 = 1 - V_415 ;
V_414 = F_193 ( V_414 - V_33 , 1 ) ;
V_415 = V_562 - V_414 - V_416 ;
}
}
if ( V_415 < 1 )
return false ;
V_539 -> V_415 = V_415 ;
V_539 -> V_529 = V_414 ;
V_539 -> V_416 = V_416 ;
return true ;
}
static bool F_252 ( int V_534 , int V_535 , unsigned long V_536 ,
unsigned long V_527 , void * V_26 )
{
struct V_537 * V_538 = V_26 ;
V_538 -> V_488 . V_489 = V_534 ;
V_538 -> V_488 . V_491 = V_535 ;
V_538 -> V_488 . V_536 = V_536 ;
V_538 -> V_488 . V_527 = V_527 ;
if ( F_251 ( V_538 ) == false )
return false ;
#ifdef F_253
F_240 ( L_151 , & V_538 -> V_539 ) ;
F_238 ( L_152 , & V_538 -> V_565 ) ;
F_240 ( L_153 , V_538 -> V_540 -> V_388 ) ;
F_242 ( L_154 , & V_538 -> V_565 ) ;
#endif
return true ;
}
static bool F_254 ( int V_542 , unsigned long V_543 ,
void * V_26 )
{
struct V_537 * V_538 = V_26 ;
unsigned long V_569 ;
V_538 -> V_544 . V_206 [ V_178 ] = V_542 ;
V_538 -> V_544 . V_177 [ V_178 ] = V_543 ;
if ( V_538 -> V_540 -> V_392 == V_567 )
V_569 = V_538 -> V_546 + 10000000 ;
else
V_569 = V_538 -> V_546 ;
return F_246 ( V_543 , V_538 -> V_545 , V_569 ,
F_252 , V_538 ) ;
}
static bool F_255 ( int V_222 , int V_223 , unsigned long V_221 ,
unsigned long V_180 , void * V_26 )
{
struct V_537 * V_538 = V_26 ;
V_538 -> V_544 . V_222 = V_222 ;
V_538 -> V_544 . V_223 = V_223 ;
V_538 -> V_544 . V_221 = V_221 ;
V_538 -> V_544 . V_180 = V_180 ;
return F_248 ( V_538 -> V_175 , V_180 , V_538 -> V_545 ,
F_97 ( V_547 ) ,
F_254 , V_538 ) ;
}
static bool F_256 ( struct V_1 * V_16 ,
const struct V_548 * V_549 ,
struct V_537 * V_538 )
{
const struct V_387 * V_33 = V_549 -> V_388 ;
unsigned long V_220 ;
unsigned long V_550 ;
unsigned long V_551 ;
int V_423 = V_16 -> V_270 - 1 ;
int V_524 = F_25 ( V_549 -> V_553 ) ;
unsigned long V_570 ;
V_220 = F_93 ( V_16 -> V_175 . V_220 ) ;
memset ( V_538 , 0 , sizeof( * V_538 ) ) ;
V_538 -> V_3 = V_16 -> V_157 ;
V_538 -> V_175 = & V_16 -> V_175 ;
V_538 -> V_540 = V_549 ;
V_538 -> V_545 = V_33 -> V_528 - 1000 ;
V_538 -> V_554 = V_33 -> V_528 ;
V_538 -> V_546 = V_33 -> V_528 + 1000 ;
V_570 = F_243 ( ( T_12 ) V_538 -> V_545 * V_524 , V_423 * 8 ) ;
V_550 = F_193 ( V_549 -> V_555 * 4 , V_570 * 4 * 4 ) ;
if ( V_549 -> V_392 == V_567 ) {
V_551 = V_549 -> V_556 * 4 ;
} else {
unsigned long V_571 ;
V_571 = F_243 ( ( T_12 ) V_538 -> V_546 * V_524 ,
V_423 * 8 ) ;
V_551 = V_571 * 4 * 4 ;
}
return F_250 ( V_538 -> V_175 , V_220 ,
V_550 , V_551 ,
F_255 , V_538 ) ;
}
static int F_257 ( struct V_5 * V_6 ,
const struct V_548 * V_540 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_537 V_538 ;
bool V_299 ;
int V_155 ;
F_234 ( & V_16 -> V_512 ) ;
V_16 -> V_386 = V_540 -> V_553 ;
V_16 -> V_306 = V_540 -> V_306 ;
if ( V_540 -> V_306 == V_307 )
V_299 = F_256 ( V_16 , V_540 , & V_538 ) ;
else
V_299 = F_249 ( V_16 , V_540 , & V_538 ) ;
if ( ! V_299 ) {
F_44 ( L_155 ) ;
V_155 = - V_153 ;
goto V_333;
}
F_103 ( & V_538 . V_544 ) ;
V_155 = F_94 ( V_538 . V_544 . V_177 [ V_179 ] ,
V_540 -> V_185 , V_540 -> V_186 , & V_16 -> V_193 ) ;
if ( V_155 ) {
F_44 ( L_156 ) ;
goto V_333;
}
V_16 -> V_425 = V_538 . V_544 ;
V_16 -> V_490 = V_538 . V_488 ;
V_16 -> V_388 = V_538 . V_539 ;
V_16 -> V_308 = V_538 . V_565 ;
F_235 ( & V_16 -> V_512 ) ;
return 0 ;
V_333:
F_235 ( & V_16 -> V_512 ) ;
return V_155 ;
}
static enum V_572 F_258 ( int V_181 )
{
switch ( F_259 () ) {
case V_573 :
case V_574 :
F_260 ( L_157 ) ;
return V_575 ;
case V_576 :
case V_577 :
case V_578 :
case V_579 :
return V_575 ;
case V_580 :
case V_581 :
case V_582 :
switch ( V_181 ) {
case 0 :
return V_575 ;
case 1 :
return V_583 ;
default:
F_260 ( L_158 ) ;
return V_575 ;
}
case V_584 :
switch ( V_181 ) {
case 0 :
return V_575 ;
case 1 :
return V_585 ;
default:
F_260 ( L_158 ) ;
return V_575 ;
}
default:
F_260 ( L_159 ) ;
return V_575 ;
}
}
static int F_261 ( struct V_5 * V_6 , int * V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
for ( V_109 = 0 ; V_109 < F_47 ( V_16 -> V_149 ) ; V_109 ++ ) {
if ( ! V_16 -> V_149 [ V_109 ] . V_6 ) {
V_16 -> V_149 [ V_109 ] . V_6 = V_6 ;
* V_75 = V_109 ;
return 0 ;
}
}
F_44 ( L_160 , V_6 -> V_45 ) ;
return - V_586 ;
}
static int F_262 ( struct V_5 * V_6 , int V_75 , int V_347 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_347 < 0 || V_347 > 3 ) {
F_44 ( L_161 ) ;
return - V_153 ;
}
if ( V_75 < 0 || V_75 > 3 ) {
F_44 ( L_162 ) ;
return - V_153 ;
}
if ( V_16 -> V_149 [ V_75 ] . V_6 != V_6 ) {
F_44 ( L_163 ,
V_6 -> V_45 ) ;
return - V_153 ;
}
V_16 -> V_149 [ V_75 ] . V_347 = V_347 ;
return 0 ;
}
static void F_263 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ( V_75 >= 0 && V_75 <= 3 ) &&
V_16 -> V_149 [ V_75 ] . V_6 == V_6 ) {
V_16 -> V_149 [ V_75 ] . V_6 = NULL ;
V_16 -> V_149 [ V_75 ] . V_347 = 0 ;
}
}
static int F_264 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_587 * V_587 ;
V_587 = F_265 ( & V_3 -> V_4 , L_164 ) ;
if ( F_78 ( V_587 ) ) {
F_44 ( L_165 ) ;
return F_79 ( V_587 ) ;
}
V_16 -> V_183 = V_587 ;
return 0 ;
}
static int F_266 ( struct V_5 * V_6 ,
struct V_5 * V_588 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_459 * V_460 ;
int V_155 ;
V_155 = F_76 ( V_3 ) ;
if ( V_155 )
return V_155 ;
V_460 = F_267 ( V_6 -> V_589 ) ;
if ( ! V_460 )
return - V_202 ;
V_155 = F_268 ( V_460 , V_6 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_269 ( V_6 , V_588 ) ;
if ( V_155 ) {
F_44 ( L_166 ,
V_6 -> V_45 ) ;
F_270 ( V_460 , V_6 ) ;
return V_155 ;
}
return 0 ;
}
static void F_271 ( struct V_5 * V_6 ,
struct V_5 * V_588 )
{
F_73 ( V_588 != V_6 -> V_588 ) ;
if ( V_588 != V_6 -> V_588 )
return;
F_272 ( V_6 ) ;
if ( V_6 -> V_462 )
F_270 ( V_6 -> V_462 , V_6 ) ;
}
static void F_273 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_461 ;
V_8 -> V_4 = & V_3 -> V_4 ;
V_8 -> V_10 = V_16 -> V_181 == 0 ?
V_11 : V_12 ;
V_8 -> V_590 = V_591 ;
V_8 -> V_45 = V_16 -> V_181 == 0 ? L_167 : L_168 ;
V_8 -> V_589 = F_258 ( V_16 -> V_181 ) ;
V_8 -> V_592 . V_16 = & V_593 ;
V_8 -> V_594 = V_595 ;
F_274 ( V_8 ) ;
}
static void F_275 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_461 ;
F_276 ( V_8 ) ;
}
static int F_277 ( struct V_2 * V_157 )
{
struct V_596 * V_597 = V_157 -> V_4 . V_598 ;
struct V_1 * V_16 = F_1 ( V_157 ) ;
struct V_599 * V_600 ;
T_1 V_601 [ 10 ] ;
int V_344 , V_451 ;
int V_155 , V_109 ;
struct V_596 * V_602 ;
struct V_449 V_450 ;
V_602 = F_278 ( V_597 ) ;
if ( ! V_602 )
return 0 ;
V_600 = F_279 ( V_602 , L_169 , & V_344 ) ;
if ( V_600 == NULL ) {
F_280 ( & V_157 -> V_4 , L_170 ) ;
V_155 = - V_153 ;
goto V_333;
}
V_451 = V_344 / sizeof( T_1 ) ;
if ( V_451 < 4 || V_451 % 2 != 0 ||
V_451 > V_16 -> V_274 * 2 ) {
F_280 ( & V_157 -> V_4 , L_171 ) ;
V_155 = - V_153 ;
goto V_333;
}
V_155 = F_281 ( V_602 , L_169 , V_601 , V_451 ) ;
if ( V_155 ) {
F_280 ( & V_157 -> V_4 , L_172 ) ;
goto V_333;
}
V_450 . V_451 = V_451 ;
for ( V_109 = 0 ; V_109 < V_451 ; ++ V_109 )
V_450 . V_452 [ V_109 ] = ( int ) V_601 [ V_109 ] ;
V_155 = F_198 ( & V_16 -> V_461 , & V_450 ) ;
if ( V_155 ) {
F_280 ( & V_157 -> V_4 , L_173 ) ;
goto V_333;
}
F_282 ( V_602 ) ;
return 0 ;
V_333:
F_282 ( V_602 ) ;
return V_155 ;
}
static int F_283 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_207 * V_175 = & V_16 -> V_175 ;
struct V_587 * V_587 ;
int V_155 ;
V_587 = F_265 ( & V_3 -> V_4 , L_174 ) ;
if ( F_78 ( V_587 ) ) {
F_44 ( L_175 ) ;
return F_79 ( V_587 ) ;
}
V_175 -> V_45 = V_16 -> V_181 == 0 ? L_176 : L_177 ;
V_175 -> V_10 = V_16 -> V_181 == 0 ? V_603 : V_604 ;
V_175 -> V_220 = V_587 ;
V_175 -> V_17 = V_16 -> V_23 ;
switch ( F_259 () ) {
case V_576 :
case V_577 :
case V_578 :
case V_579 :
V_175 -> V_605 = & V_606 ;
break;
case V_580 :
case V_581 :
case V_582 :
V_175 -> V_605 = & V_607 ;
break;
case V_584 :
V_175 -> V_605 = & V_608 ;
break;
default:
return - V_202 ;
}
V_175 -> V_592 = & V_609 ;
V_155 = F_284 ( V_175 ) ;
if ( V_155 )
return V_155 ;
return 0 ;
}
static int F_285 ( struct V_610 * V_4 , struct V_610 * V_611 , void * V_26 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
T_1 V_612 ;
int V_155 , V_109 ;
struct V_1 * V_16 ;
struct V_613 * V_614 ;
struct V_613 * V_615 ;
struct V_613 V_616 ;
V_16 = F_286 ( & V_3 -> V_4 , sizeof( * V_16 ) , V_617 ) ;
if ( ! V_16 )
return - V_618 ;
V_16 -> V_157 = V_3 ;
F_287 ( & V_3 -> V_4 , V_16 ) ;
F_288 ( & V_16 -> V_136 ) ;
F_288 ( & V_16 -> V_117 ) ;
V_16 -> V_118 = 0 ;
#ifdef F_289
F_288 ( & V_16 -> V_110 ) ;
V_16 -> V_111 . V_231 = V_34 ;
#endif
F_290 ( & V_16 -> V_512 ) ;
F_291 ( & V_16 -> V_24 , 1 ) ;
F_292 ( & V_16 -> V_479 ,
F_214 ) ;
#ifdef F_50
F_293 ( & V_16 -> V_141 ) ;
V_16 -> V_141 . V_276 = F_211 ;
V_16 -> V_141 . V_26 = 0 ;
#endif
V_615 = F_294 ( V_3 , V_619 , L_178 ) ;
if ( ! V_615 ) {
V_615 = F_295 ( V_3 , V_619 , 0 ) ;
if ( ! V_615 ) {
F_44 ( L_179 ) ;
return - V_153 ;
}
V_616 . T_9 = V_615 -> T_9 ;
V_616 . T_10 = V_616 . T_9 + V_620 - 1 ;
V_615 = & V_616 ;
}
V_614 = V_615 ;
V_16 -> V_19 = F_296 ( & V_3 -> V_4 , V_615 -> T_9 ,
F_297 ( V_615 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_180 ) ;
return - V_618 ;
}
V_615 = F_294 ( V_3 , V_619 , L_181 ) ;
if ( ! V_615 ) {
V_615 = F_295 ( V_3 , V_619 , 0 ) ;
if ( ! V_615 ) {
F_44 ( L_179 ) ;
return - V_153 ;
}
V_616 . T_9 = V_615 -> T_9 + V_621 ;
V_616 . T_10 = V_616 . T_9 + V_622 - 1 ;
V_615 = & V_616 ;
}
V_16 -> V_21 = F_296 ( & V_3 -> V_4 , V_615 -> T_9 ,
F_297 ( V_615 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_182 ) ;
return - V_618 ;
}
V_615 = F_294 ( V_3 , V_619 , L_183 ) ;
if ( ! V_615 ) {
V_615 = F_295 ( V_3 , V_619 , 0 ) ;
if ( ! V_615 ) {
F_44 ( L_179 ) ;
return - V_153 ;
}
V_616 . T_9 = V_615 -> T_9 + V_623 ;
V_616 . T_10 = V_616 . T_9 + V_624 - 1 ;
V_615 = & V_616 ;
}
V_16 -> V_23 = F_296 ( & V_3 -> V_4 , V_615 -> T_9 ,
F_297 ( V_615 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_184 ) ;
return - V_618 ;
}
V_16 -> V_133 = F_298 ( V_16 -> V_157 , 0 ) ;
if ( V_16 -> V_133 < 0 ) {
F_44 ( L_185 ) ;
return - V_202 ;
}
V_155 = F_299 ( & V_3 -> V_4 , V_16 -> V_133 , F_48 ,
V_625 , F_300 ( & V_3 -> V_4 ) , V_16 -> V_157 ) ;
if ( V_155 < 0 ) {
F_44 ( L_186 ) ;
return V_155 ;
}
if ( V_3 -> V_4 . V_598 ) {
const struct V_626 * V_627 ;
const struct V_628 * V_629 ;
V_627 = F_301 ( V_630 , V_3 -> V_4 . V_598 ) ;
if ( ! V_627 ) {
F_44 ( L_187 ) ;
return - V_202 ;
}
V_629 = V_627 -> V_26 ;
while ( V_629 -> V_631 != 0 && V_629 -> V_631 != V_614 -> T_9 )
V_629 ++ ;
if ( V_629 -> V_631 == 0 ) {
F_44 ( L_187 ) ;
return - V_202 ;
}
V_16 -> V_181 = V_629 -> V_10 ;
} else {
V_16 -> V_181 = V_3 -> V_10 ;
}
for ( V_109 = 0 ; V_109 < F_47 ( V_16 -> V_149 ) ; V_109 ++ ) {
V_16 -> V_149 [ V_109 ] . V_327 = V_329 ;
V_16 -> V_149 [ V_109 ] . V_6 = NULL ;
V_16 -> V_149 [ V_109 ] . V_347 = 0 ;
}
V_155 = F_264 ( V_3 ) ;
if ( V_155 )
return V_155 ;
F_283 ( V_3 ) ;
F_302 ( & V_3 -> V_4 ) ;
V_155 = F_70 ( V_3 ) ;
if ( V_155 )
goto V_632;
V_612 = F_9 ( V_3 , V_232 ) ;
F_303 ( & V_3 -> V_4 , L_188 ,
F_101 ( V_612 , 7 , 4 ) , F_101 ( V_612 , 3 , 0 ) ) ;
if ( F_84 ( V_260 ) )
V_16 -> V_274 = 1 + F_19 ( V_3 , V_261 , 11 , 9 ) ;
else
V_16 -> V_274 = 3 ;
V_16 -> V_389 = F_131 ( V_3 ) ;
F_273 ( V_3 ) ;
if ( V_3 -> V_4 . V_598 ) {
V_155 = F_277 ( V_3 ) ;
if ( V_155 ) {
F_44 ( L_189 ) ;
goto V_633;
}
V_155 = F_304 ( V_3 -> V_4 . V_598 , NULL , NULL ,
& V_3 -> V_4 ) ;
if ( V_155 )
F_44 ( L_190 , V_155 ) ;
}
F_74 ( V_3 ) ;
if ( V_16 -> V_181 == 0 )
F_305 ( L_191 , F_128 ) ;
else if ( V_16 -> V_181 == 1 )
F_305 ( L_192 , F_129 ) ;
#ifdef F_289
if ( V_16 -> V_181 == 0 )
F_305 ( L_193 , F_119 ) ;
else if ( V_16 -> V_181 == 1 )
F_305 ( L_194 , F_120 ) ;
#endif
return 0 ;
V_633:
F_275 ( V_3 ) ;
F_74 ( V_3 ) ;
V_632:
F_306 ( & V_3 -> V_4 ) ;
return V_155 ;
}
static void F_307 ( struct V_610 * V_4 , struct V_610 * V_611 , void * V_26 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_308 ( & V_3 -> V_4 ) ;
F_73 ( V_16 -> V_196 > 0 ) ;
F_309 ( & V_16 -> V_175 ) ;
F_275 ( V_3 ) ;
F_306 ( & V_3 -> V_4 ) ;
if ( V_16 -> V_161 != NULL && V_16 -> V_208 ) {
F_108 ( V_16 -> V_161 ) ;
V_16 -> V_208 = false ;
}
}
static int F_310 ( struct V_2 * V_157 )
{
return F_311 ( & V_157 -> V_4 , & V_634 ) ;
}
static int F_312 ( struct V_2 * V_157 )
{
F_313 ( & V_157 -> V_4 , & V_634 ) ;
return 0 ;
}
static int F_314 ( struct V_610 * V_4 )
{
struct V_2 * V_157 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_157 ) ;
V_16 -> V_134 = false ;
F_315 () ;
F_316 ( V_16 -> V_133 ) ;
F_317 () ;
return 0 ;
}
static int F_318 ( struct V_610 * V_4 )
{
struct V_2 * V_157 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_157 ) ;
int V_155 ;
V_155 = F_319 () ;
if ( V_155 )
return V_155 ;
V_16 -> V_134 = true ;
F_315 () ;
return 0 ;
}
int T_13 F_320 ( void )
{
return F_321 ( & V_635 ) ;
}
void F_322 ( void )
{
F_323 ( & V_635 ) ;
}
