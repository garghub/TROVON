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
int F_70 ( struct V_2 * V_3 )
{
int V_155 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_10 ) ;
V_155 = F_72 ( & V_16 -> V_157 -> V_4 ) ;
F_73 ( V_155 < 0 ) ;
return V_155 < 0 ? V_155 : 0 ;
}
void F_74 ( struct V_2 * V_3 )
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
static inline void F_83 ( struct V_2 * V_3 ,
bool V_163 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_163 )
F_84 ( V_16 -> V_164 ) ;
else
F_85 ( V_16 -> V_164 ) ;
if ( V_163 && V_16 -> V_165 ) {
if ( F_18 ( V_3 , V_166 , 1 , 1 ) != 1 )
F_44 ( L_15 ) ;
}
}
static void F_86 ( struct V_2 * V_3 )
{
T_1 V_167 ;
int V_168 , V_169 , V_170 ;
V_167 = F_9 ( V_3 , V_171 ) ;
if ( F_87 ( V_172 ) ) {
V_168 = 28 ;
V_169 = 27 ;
V_170 = 26 ;
} else {
V_168 = 24 ;
V_169 = 25 ;
V_170 = 26 ;
}
#define F_88 ( T_8 , T_9 , T_10 ) \
FLD_GET(dsi_read_reg(dsidev, DSI_##fld), start, end)
F_36 ( L_16 ,
F_88 ( V_173 , 0 , 0 ) ,
F_88 ( V_174 , 29 , 29 ) ,
F_88 ( V_175 , V_168 , V_168 ) ,
F_88 ( V_175 , V_169 , V_169 ) ,
F_88 ( V_175 , V_170 , V_170 ) ,
F_88 ( V_175 , 29 , 29 ) ,
F_88 ( V_175 , 30 , 30 ) ,
F_88 ( V_175 , 31 , 31 ) ) ;
#undef F_88
}
static inline int F_89 ( struct V_2 * V_3 , bool V_163 )
{
F_71 ( L_17 , V_163 ) ;
V_163 = V_163 ? 1 : 0 ;
F_90 ( V_3 , V_176 , V_163 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_176 , 0 , V_163 ) != V_163 ) {
F_44 ( L_18 , V_163 ) ;
return - V_177 ;
}
return 0 ;
}
unsigned long F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_178 . V_179 ;
}
static unsigned long F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_178 . V_180 ;
}
static unsigned long F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_178 . V_181 / 16 ;
}
static unsigned long F_94 ( struct V_2 * V_3 )
{
unsigned long V_155 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( F_95 ( V_16 -> V_182 ) == V_183 ) {
V_155 = F_96 ( V_16 -> V_184 ) ;
} else {
V_155 = F_92 ( V_3 ) ;
}
return V_155 ;
}
static int F_97 ( struct V_185 * V_186 ,
unsigned long V_187 , unsigned long V_188 )
{
unsigned long V_189 = V_186 -> V_180 ;
unsigned V_190 ;
unsigned long V_191 ;
V_190 = F_98 ( V_189 , V_188 * 2 ) ;
V_191 = V_189 / 2 / V_190 ;
if ( V_191 < V_187 || V_191 > V_188 )
return - V_153 ;
V_186 -> V_190 = V_190 ;
V_186 -> V_191 = V_191 ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_189 ;
unsigned V_190 ;
unsigned long V_191 ;
V_190 = V_16 -> V_192 . V_190 ;
if ( V_190 == 0 || V_190 > V_16 -> V_193 )
return - V_153 ;
V_189 = F_94 ( V_3 ) ;
V_191 = V_189 / 2 / V_190 ;
F_71 ( L_19 , V_190 , V_191 ) ;
V_16 -> V_178 . V_191 = V_191 ;
V_16 -> V_178 . V_190 = V_190 ;
F_90 ( V_3 , V_194 , V_190 , 12 , 0 ) ;
F_90 ( V_3 , V_194 , V_189 > 30000000 ? 1 : 0 , 21 , 21 ) ;
return 0 ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_195 ++ == 0 )
F_90 ( V_3 , V_194 , 1 , 14 , 14 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_195 == 0 ) ;
if ( -- V_16 -> V_195 == 0 )
F_90 ( V_3 , V_194 , 0 , 14 , 14 ) ;
}
static int F_102 ( struct V_2 * V_3 ,
enum V_196 V_197 )
{
int V_33 = 0 ;
if ( F_87 ( V_198 ) &&
V_197 == V_199 )
V_197 = V_200 ;
F_90 ( V_3 , V_194 , V_197 , 31 , 30 ) ;
while ( F_103 ( F_9 ( V_3 , V_194 ) , 29 , 28 ) != V_197 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_20 ,
V_197 ) ;
return - V_201 ;
}
F_104 ( 1 ) ;
}
return 0 ;
}
unsigned long F_105 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return F_96 ( V_16 -> V_164 ) ;
}
bool F_106 ( struct V_2 * V_3 , unsigned long V_202 ,
unsigned long V_203 , T_11 V_204 , void * V_26 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_205 , V_206 , V_207 ;
unsigned long V_208 ;
unsigned long V_8 ;
V_203 = V_203 ? V_203 : 1 ;
V_208 = F_107 ( V_209 ) ;
V_206 = F_108 ( F_98 ( V_202 , V_208 ) , 1ul ) ;
V_207 = F_109 ( V_202 / V_203 , V_16 -> V_210 ) ;
for ( V_205 = V_206 ; V_205 <= V_207 ; ++ V_205 ) {
V_8 = V_202 / V_205 ;
if ( V_204 ( V_205 , V_8 , V_26 ) )
return true ;
}
return false ;
}
bool F_110 ( struct V_2 * V_3 , unsigned long V_211 ,
unsigned long V_212 , unsigned long V_213 ,
T_12 V_204 , void * V_26 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_214 , V_215 , V_216 ;
int V_205 , V_206 , V_207 ;
unsigned long V_217 , V_202 ;
const unsigned long V_218 = 1800000000 ;
unsigned long V_219 , V_220 ;
V_219 = V_16 -> V_221 ;
V_220 = V_16 -> V_222 ;
V_215 = F_108 ( F_98 ( V_211 , V_220 ) , 1ul ) ;
V_216 = F_109 ( V_211 / V_219 , V_16 -> V_223 ) ;
V_213 = V_213 ? V_213 : V_224 ;
for ( V_214 = V_215 ; V_214 <= V_216 ; ++ V_214 ) {
V_217 = V_211 / V_214 ;
V_206 = F_108 ( F_98 ( F_98 ( V_212 , V_217 ) , 2 ) ,
1ul ) ;
V_207 = F_111 ( V_213 / V_217 / 2 ,
V_218 / V_217 / 2 ,
V_16 -> V_225 ) ;
for ( V_205 = V_206 ; V_205 <= V_207 ; ++ V_205 ) {
V_202 = 2 * V_205 * V_217 ;
if ( V_204 ( V_214 , V_205 , V_217 , V_202 , V_26 ) )
return true ;
}
}
return false ;
}
static int F_112 ( struct V_2 * V_3 ,
struct V_185 * V_186 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_186 -> V_214 == 0 || V_186 -> V_214 > V_16 -> V_223 )
return - V_153 ;
if ( V_186 -> V_205 == 0 || V_186 -> V_205 > V_16 -> V_225 )
return - V_153 ;
if ( V_186 -> V_226 > V_16 -> V_210 )
return - V_153 ;
if ( V_186 -> V_227 > V_16 -> V_228 )
return - V_153 ;
V_186 -> V_211 = F_96 ( V_16 -> V_164 ) ;
V_186 -> V_217 = V_186 -> V_211 / V_186 -> V_214 ;
if ( V_186 -> V_217 > V_16 -> V_222 || V_186 -> V_217 < V_16 -> V_221 )
return - V_153 ;
V_186 -> V_181 = 2 * V_186 -> V_205 * V_186 -> V_217 ;
if ( V_186 -> V_181 > 1800 * 1000 * 1000 )
return - V_153 ;
if ( V_186 -> V_226 > 0 )
V_186 -> V_179 =
V_186 -> V_181 / V_186 -> V_226 ;
else
V_186 -> V_179 = 0 ;
if ( V_186 -> V_227 > 0 )
V_186 -> V_180 =
V_186 -> V_181 / V_186 -> V_227 ;
else
V_186 -> V_180 = 0 ;
return 0 ;
}
static void F_113 ( struct V_185 * V_186 )
{
unsigned long V_229 ;
V_229 = F_107 ( V_230 ) ;
V_186 -> V_227 = F_98 ( V_186 -> V_181 , V_229 ) ;
V_186 -> V_180 = V_186 -> V_181 / V_186 -> V_227 ;
}
int F_114 ( struct V_2 * V_3 ,
struct V_185 * V_186 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 = 0 ;
T_1 V_167 ;
int V_231 = 0 ;
T_4 V_215 , V_232 , V_206 , V_233 ;
T_4 V_234 , V_235 , V_236 , V_237 ;
F_71 ( L_21 ) ;
V_16 -> V_178 . V_211 = V_186 -> V_211 ;
V_16 -> V_178 . V_217 = V_186 -> V_217 ;
V_16 -> V_178 . V_181 = V_186 -> V_181 ;
V_16 -> V_178 . V_179 =
V_186 -> V_179 ;
V_16 -> V_178 . V_180 =
V_186 -> V_180 ;
V_16 -> V_178 . V_214 = V_186 -> V_214 ;
V_16 -> V_178 . V_205 = V_186 -> V_205 ;
V_16 -> V_178 . V_226 = V_186 -> V_226 ;
V_16 -> V_178 . V_227 = V_186 -> V_227 ;
F_71 ( L_22 , V_186 -> V_217 ) ;
F_71 ( L_23 , V_186 -> V_211 ) ;
F_71 ( L_24 ,
V_186 -> V_205 ,
V_186 -> V_214 ,
V_186 -> V_211 ,
V_186 -> V_181 ) ;
F_71 ( L_25 ,
V_186 -> V_181 / 1000 / 1000 / 2 ) ;
F_71 ( L_26 , V_186 -> V_181 / 4 ) ;
F_71 ( L_27 , V_186 -> V_226 ,
F_115 ( V_238 ) ,
F_116 ( V_238 ) ,
V_186 -> V_179 ) ;
F_71 ( L_28 , V_186 -> V_227 ,
F_115 ( V_239 ) ,
F_116 ( V_239 ) ,
V_186 -> V_180 ) ;
F_117 ( V_240 , & V_215 , & V_232 ) ;
F_117 ( V_241 , & V_206 , & V_233 ) ;
F_117 ( V_242 , & V_234 ,
& V_235 ) ;
F_117 ( V_243 , & V_236 ,
& V_237 ) ;
F_90 ( V_3 , V_244 , 0 , 0 , 0 ) ;
V_167 = F_9 ( V_3 , V_245 ) ;
V_167 = F_118 ( V_167 , 1 , 0 , 0 ) ;
V_167 = F_118 ( V_167 , V_186 -> V_214 - 1 , V_215 , V_232 ) ;
V_167 = F_118 ( V_167 , V_186 -> V_205 , V_206 , V_233 ) ;
V_167 = F_118 ( V_167 , V_186 -> V_226 > 0 ? V_186 -> V_226 - 1 : 0 ,
V_234 , V_235 ) ;
V_167 = F_118 ( V_167 , V_186 -> V_227 > 0 ? V_186 -> V_227 - 1 : 0 ,
V_236 , V_237 ) ;
F_7 ( V_3 , V_245 , V_167 ) ;
F_61 ( V_186 -> V_217 < V_16 -> V_221 || V_186 -> V_217 > V_16 -> V_222 ) ;
V_167 = F_9 ( V_3 , V_246 ) ;
if ( F_87 ( V_247 ) ) {
V_231 = V_186 -> V_217 < 1000000 ? 0x3 :
V_186 -> V_217 < 1250000 ? 0x4 :
V_186 -> V_217 < 1500000 ? 0x5 :
V_186 -> V_217 < 1750000 ? 0x6 :
0x7 ;
V_167 = F_118 ( V_167 , V_231 , 4 , 1 ) ;
} else if ( F_87 ( V_248 ) ) {
V_231 = V_186 -> V_181 < 1000000000 ? 0x2 : 0x4 ;
V_167 = F_118 ( V_167 , V_231 , 4 , 1 ) ;
}
V_167 = F_118 ( V_167 , 1 , 13 , 13 ) ;
V_167 = F_118 ( V_167 , 0 , 14 , 14 ) ;
V_167 = F_118 ( V_167 , 1 , 20 , 20 ) ;
if ( F_87 ( V_249 ) )
V_167 = F_118 ( V_167 , 3 , 22 , 21 ) ;
F_7 ( V_3 , V_246 , V_167 ) ;
F_90 ( V_3 , V_250 , 1 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_250 , 0 , 0 ) != 0 ) {
F_44 ( L_29 ) ;
V_155 = - V_177 ;
goto V_251;
}
if ( F_18 ( V_3 , V_166 , 1 , 1 ) != 1 ) {
F_44 ( L_30 ) ;
V_155 = - V_177 ;
goto V_251;
}
V_16 -> V_165 = 1 ;
V_167 = F_9 ( V_3 , V_246 ) ;
V_167 = F_118 ( V_167 , 0 , 0 , 0 ) ;
V_167 = F_118 ( V_167 , 0 , 5 , 5 ) ;
V_167 = F_118 ( V_167 , 0 , 6 , 6 ) ;
V_167 = F_118 ( V_167 , 0 , 7 , 7 ) ;
V_167 = F_118 ( V_167 , 0 , 8 , 8 ) ;
V_167 = F_118 ( V_167 , 0 , 10 , 9 ) ;
V_167 = F_118 ( V_167 , 1 , 13 , 13 ) ;
V_167 = F_118 ( V_167 , 1 , 14 , 14 ) ;
V_167 = F_118 ( V_167 , 0 , 15 , 15 ) ;
V_167 = F_118 ( V_167 , 1 , 16 , 16 ) ;
V_167 = F_118 ( V_167 , 0 , 17 , 17 ) ;
V_167 = F_118 ( V_167 , 1 , 18 , 18 ) ;
V_167 = F_118 ( V_167 , 0 , 19 , 19 ) ;
V_167 = F_118 ( V_167 , 0 , 20 , 20 ) ;
F_7 ( V_3 , V_246 , V_167 ) ;
F_71 ( L_31 ) ;
V_251:
return V_155 ;
}
int F_119 ( struct V_2 * V_3 , bool V_252 ,
bool V_253 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 = 0 ;
enum V_196 V_254 ;
F_71 ( L_32 ) ;
V_252 = V_253 = true ;
V_155 = F_76 ( V_3 ) ;
if ( V_155 )
return V_155 ;
F_83 ( V_3 , 1 ) ;
F_100 ( V_3 ) ;
if ( ! V_16 -> V_255 ) {
V_155 = F_120 ( V_16 -> V_161 ) ;
if ( V_155 )
goto V_256;
V_16 -> V_255 = true ;
}
F_121 ( 1 ) ;
if ( F_18 ( V_3 , V_166 , 0 , 1 ) != 1 ) {
F_44 ( L_33 ) ;
V_155 = - V_201 ;
F_121 ( 0 ) ;
goto V_257;
}
F_121 ( 0 ) ;
if ( V_252 && V_253 )
V_254 = V_200 ;
else if ( V_252 )
V_254 = V_258 ;
else if ( V_253 )
V_254 = V_199 ;
else
V_254 = V_259 ;
V_155 = F_102 ( V_3 , V_254 ) ;
if ( V_155 )
goto V_257;
F_71 ( L_34 ) ;
return 0 ;
V_257:
if ( V_16 -> V_255 ) {
F_122 ( V_16 -> V_161 ) ;
V_16 -> V_255 = false ;
}
V_256:
F_101 ( V_3 ) ;
F_83 ( V_3 , 0 ) ;
return V_155 ;
}
void F_123 ( struct V_2 * V_3 , bool V_260 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_165 = 0 ;
F_102 ( V_3 , V_259 ) ;
if ( V_260 ) {
F_73 ( ! V_16 -> V_255 ) ;
F_122 ( V_16 -> V_161 ) ;
V_16 -> V_255 = false ;
}
F_101 ( V_3 ) ;
F_83 ( V_3 , 0 ) ;
F_71 ( L_35 ) ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_261 * V_262 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_185 * V_186 = & V_16 -> V_178 ;
enum V_263 V_264 , V_265 ;
int V_266 = V_16 -> V_182 ;
V_264 = F_125 () ;
V_265 = F_95 ( V_266 ) ;
if ( F_70 ( V_3 ) )
return;
F_126 ( V_262 , L_36 , V_266 + 1 ) ;
F_126 ( V_262 , L_37 , V_186 -> V_211 ) ;
F_126 ( V_262 , L_38 , V_186 -> V_217 , V_186 -> V_214 ) ;
F_126 ( V_262 , L_39 ,
V_186 -> V_181 , V_186 -> V_205 ) ;
F_126 ( V_262 , L_40 ,
F_116 ( V_266 == 0 ?
V_238 :
V_267 ) ,
V_186 -> V_179 ,
V_186 -> V_226 ,
V_264 == V_183 ?
L_41 : L_42 ) ;
F_126 ( V_262 , L_43 ,
F_116 ( V_266 == 0 ?
V_239 :
V_268 ) ,
V_186 -> V_180 ,
V_186 -> V_227 ,
V_265 == V_183 ?
L_41 : L_42 ) ;
F_126 ( V_262 , L_44 , V_266 + 1 ) ;
F_126 ( V_262 , L_45 ,
F_115 ( V_265 ) ,
F_116 ( V_265 ) ) ;
F_126 ( V_262 , L_46 , F_94 ( V_3 ) ) ;
F_126 ( V_262 , L_47 ,
V_186 -> V_181 / 4 ) ;
F_126 ( V_262 , L_48 , F_93 ( V_3 ) ) ;
F_126 ( V_262 , L_49 , V_186 -> V_191 ) ;
F_74 ( V_3 ) ;
}
void F_127 ( struct V_261 * V_262 )
{
struct V_2 * V_3 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_269 ; V_109 ++ ) {
V_3 = F_5 ( V_109 ) ;
if ( V_3 )
F_124 ( V_3 , V_262 ) ;
}
}
static void F_128 ( struct V_2 * V_3 ,
struct V_261 * V_262 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_151 ;
struct V_270 V_271 ;
F_58 ( & V_16 -> V_110 , V_151 ) ;
V_271 = V_16 -> V_111 ;
memset ( & V_16 -> V_111 , 0 , sizeof( V_16 -> V_111 ) ) ;
V_16 -> V_111 . V_272 = V_34 ;
F_59 ( & V_16 -> V_110 , V_151 ) ;
F_126 ( V_262 , L_50 ,
F_129 ( V_34 - V_271 . V_272 ) ) ;
F_126 ( V_262 , L_51 , V_271 . V_112 ) ;
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d\n", #x, stats.dsi_irqs[ffs(DSI_IRQ_##x)-1]);
F_126 ( V_262 , L_52 , V_16 -> V_182 + 1 ) ;
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
F_126 ( V_262 , L_53 ) ;
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
F_126 ( V_262 , L_54 ) ;
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
static void F_130 ( struct V_261 * V_262 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_128 ( V_3 , V_262 ) ;
}
static void F_131 ( struct V_261 * V_262 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_128 ( V_3 , V_262 ) ;
}
static void F_132 ( struct V_2 * V_3 ,
struct V_261 * V_262 )
{
#define F_133 ( V_155 ) seq_printf(s, "%-35s %08x\n", #r, dsi_read_reg(dsidev, r))
if ( F_70 ( V_3 ) )
return;
F_100 ( V_3 ) ;
F_133 ( V_273 ) ;
F_133 ( V_274 ) ;
F_133 ( V_275 ) ;
F_133 ( V_137 ) ;
F_133 ( V_148 ) ;
F_133 ( V_176 ) ;
F_133 ( V_276 ) ;
F_133 ( V_139 ) ;
F_133 ( V_150 ) ;
F_133 ( V_194 ) ;
F_133 ( V_277 ) ;
F_133 ( V_278 ) ;
F_133 ( V_279 ) ;
F_133 ( V_280 ) ;
F_133 ( V_281 ) ;
F_133 ( V_282 ) ;
F_133 ( V_283 ) ;
F_133 ( V_284 ) ;
F_133 ( V_285 ) ;
F_133 ( V_286 ) ;
F_133 ( V_287 ) ;
F_133 ( V_288 ) ;
F_133 ( V_289 ) ;
F_133 ( V_290 ) ;
F_133 ( V_291 ) ;
F_133 ( V_292 ) ;
F_133 ( F_134 ( 0 ) ) ;
F_133 ( F_135 ( 0 ) ) ;
F_133 ( F_136 ( 0 ) ) ;
F_133 ( F_137 ( 0 ) ) ;
F_133 ( F_138 ( 0 ) ) ;
F_133 ( F_49 ( 0 ) ) ;
F_133 ( F_55 ( 0 ) ) ;
F_133 ( F_134 ( 1 ) ) ;
F_133 ( F_135 ( 1 ) ) ;
F_133 ( F_136 ( 1 ) ) ;
F_133 ( F_137 ( 1 ) ) ;
F_133 ( F_138 ( 1 ) ) ;
F_133 ( F_49 ( 1 ) ) ;
F_133 ( F_55 ( 1 ) ) ;
F_133 ( F_134 ( 2 ) ) ;
F_133 ( F_135 ( 2 ) ) ;
F_133 ( F_136 ( 2 ) ) ;
F_133 ( F_137 ( 2 ) ) ;
F_133 ( F_138 ( 2 ) ) ;
F_133 ( F_49 ( 2 ) ) ;
F_133 ( F_55 ( 2 ) ) ;
F_133 ( F_134 ( 3 ) ) ;
F_133 ( F_135 ( 3 ) ) ;
F_133 ( F_136 ( 3 ) ) ;
F_133 ( F_137 ( 3 ) ) ;
F_133 ( F_138 ( 3 ) ) ;
F_133 ( F_49 ( 3 ) ) ;
F_133 ( F_55 ( 3 ) ) ;
F_133 ( V_293 ) ;
F_133 ( V_294 ) ;
F_133 ( V_295 ) ;
F_133 ( V_171 ) ;
F_133 ( V_244 ) ;
F_133 ( V_166 ) ;
F_133 ( V_250 ) ;
F_133 ( V_245 ) ;
F_133 ( V_246 ) ;
F_101 ( V_3 ) ;
F_74 ( V_3 ) ;
#undef F_133
}
static void F_139 ( struct V_261 * V_262 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_132 ( V_3 , V_262 ) ;
}
static void F_140 ( struct V_261 * V_262 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_132 ( V_3 , V_262 ) ;
}
static int F_141 ( struct V_2 * V_3 ,
enum V_296 V_197 )
{
int V_33 = 0 ;
F_90 ( V_3 , V_276 , V_197 , 28 , 27 ) ;
while ( F_103 ( F_9 ( V_3 , V_276 ) ,
26 , 25 ) != V_197 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_55
L_56 , V_197 ) ;
return - V_201 ;
}
F_104 ( 1 ) ;
}
return 0 ;
}
static unsigned F_142 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! F_87 ( V_297 ) )
return 1023 * 3 ;
V_15 = F_19 ( V_3 , V_298 , 14 , 12 ) ;
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
static int F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
static const T_4 V_299 [] = { 0 , 4 , 8 , 12 , 16 } ;
static const enum V_300 V_301 [] = {
V_302 ,
V_303 ,
V_304 ,
V_305 ,
V_306 ,
} ;
T_1 V_155 ;
int V_109 ;
V_155 = F_9 ( V_3 , V_276 ) ;
for ( V_109 = 0 ; V_109 < V_16 -> V_307 ; ++ V_109 ) {
unsigned V_308 = V_299 [ V_109 ] ;
unsigned V_309 , V_310 ;
unsigned V_33 ;
for ( V_33 = 0 ; V_33 < V_16 -> V_311 ; ++ V_33 )
if ( V_16 -> V_312 [ V_33 ] . V_313 == V_301 [ V_109 ] )
break;
if ( V_33 == V_16 -> V_311 )
return - V_153 ;
V_310 = V_33 ;
V_309 = V_16 -> V_312 [ V_33 ] . V_309 ;
V_155 = F_118 ( V_155 , V_310 + 1 , V_308 + 2 , V_308 ) ;
V_155 = F_118 ( V_155 , V_309 , V_308 + 3 , V_308 + 3 ) ;
}
for (; V_109 < V_16 -> V_311 ; ++ V_109 ) {
unsigned V_308 = V_299 [ V_109 ] ;
V_155 = F_118 ( V_155 , 0 , V_308 + 2 , V_308 ) ;
V_155 = F_118 ( V_155 , 0 , V_308 + 3 , V_308 + 3 ) ;
}
F_7 ( V_3 , V_276 , V_155 ) ;
return 0 ;
}
static inline unsigned F_144 ( struct V_2 * V_3 , unsigned V_314 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_315 = V_16 -> V_178 . V_181 / 4 ;
return ( V_314 * ( V_315 / 1000 / 1000 ) + 999 ) / 1000 ;
}
static inline unsigned F_145 ( struct V_2 * V_3 , unsigned V_316 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_315 = V_16 -> V_178 . V_181 / 4 ;
return V_316 * 1000 * 1000 / ( V_315 / 1000 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
T_1 V_155 ;
T_1 V_317 , V_318 , V_319 , V_320 ;
T_1 V_321 , V_322 , V_323 ;
T_1 V_324 ;
V_317 = F_144 ( V_3 , 70 ) + 2 ;
V_318 = F_144 ( V_3 , 175 ) + 2 ;
V_319 = F_144 ( V_3 , 60 ) + 5 ;
V_320 = F_144 ( V_3 , 145 ) ;
V_321 = F_144 ( V_3 , 25 ) ;
V_322 = F_144 ( V_3 , 60 ) + 2 ;
V_324 = F_144 ( V_3 , 65 ) ;
V_323 = F_144 ( V_3 , 260 ) ;
F_71 ( L_57 ,
V_317 , F_145 ( V_3 , V_317 ) ,
V_318 , F_145 ( V_3 , V_318 ) ) ;
F_71 ( L_58 ,
V_319 , F_145 ( V_3 , V_319 ) ,
V_320 , F_145 ( V_3 , V_320 ) ) ;
F_71 ( L_59
L_60 ,
V_321 , F_145 ( V_3 , V_321 ) ,
V_322 , F_145 ( V_3 , V_322 ) ,
V_323 , F_145 ( V_3 , V_323 ) ) ;
F_71 ( L_61 ,
V_324 , F_145 ( V_3 , V_324 ) ) ;
V_155 = F_9 ( V_3 , V_293 ) ;
V_155 = F_118 ( V_155 , V_317 , 31 , 24 ) ;
V_155 = F_118 ( V_155 , V_318 , 23 , 16 ) ;
V_155 = F_118 ( V_155 , V_319 , 15 , 8 ) ;
V_155 = F_118 ( V_155 , V_320 , 7 , 0 ) ;
F_7 ( V_3 , V_293 , V_155 ) ;
V_155 = F_9 ( V_3 , V_294 ) ;
V_155 = F_118 ( V_155 , V_321 , 20 , 16 ) ;
V_155 = F_118 ( V_155 , V_322 , 15 , 8 ) ;
V_155 = F_118 ( V_155 , V_323 , 7 , 0 ) ;
if ( F_87 ( V_325 ) ) {
V_155 = F_118 ( V_155 , 0 , 21 , 21 ) ;
V_155 = F_118 ( V_155 , 1 , 22 , 22 ) ;
V_155 = F_118 ( V_155 , 1 , 23 , 23 ) ;
}
F_7 ( V_3 , V_294 , V_155 ) ;
V_155 = F_9 ( V_3 , V_295 ) ;
V_155 = F_118 ( V_155 , V_324 , 7 , 0 ) ;
F_7 ( V_3 , V_295 , V_155 ) ;
}
static void F_147 ( struct V_2 * V_3 ,
unsigned V_326 , unsigned V_327 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
T_1 V_167 ;
T_4 V_328 = V_16 -> V_311 == 3 ? 22 : 26 ;
V_167 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 ) {
unsigned V_329 = V_16 -> V_312 [ V_109 ] . V_309 ;
if ( V_326 & ( 1 << V_109 ) )
V_167 |= 1 << ( V_109 * 2 + ( V_329 ? 0 : 1 ) ) ;
if ( V_327 & ( 1 << V_109 ) )
V_167 |= 1 << ( V_109 * 2 + ( V_329 ? 1 : 0 ) ) ;
}
F_90 ( V_3 , V_330 , V_167 , V_328 , 17 ) ;
F_90 ( V_3 , V_330 , 1 , 27 , 27 ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
F_90 ( V_3 , V_330 , 0 , 27 , 27 ) ;
F_90 ( V_3 , V_330 , 0 , 22 , 17 ) ;
}
static int F_149 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_33 , V_109 ;
bool V_331 [ V_332 ] ;
static const T_4 V_333 [] = { 28 , 27 , 26 } ;
static const T_4 V_334 [] = { 24 , 25 , 26 , 27 , 28 } ;
const T_4 * V_299 ;
if ( F_87 ( V_172 ) )
V_299 = V_333 ;
else
V_299 = V_334 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 )
V_331 [ V_109 ] = V_16 -> V_312 [ V_109 ] . V_313 != V_335 ;
V_33 = 100000 ;
while ( true ) {
T_1 V_167 ;
int V_336 ;
V_167 = F_9 ( V_3 , V_171 ) ;
V_336 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 ) {
if ( ! V_331 [ V_109 ] || ( V_167 & ( 1 << V_299 [ V_109 ] ) ) )
V_336 ++ ;
}
if ( V_336 == V_16 -> V_311 )
break;
if ( -- V_33 == 0 ) {
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 ) {
if ( ! V_331 [ V_109 ] || ( V_167 & ( 1 << V_299 [ V_109 ] ) ) )
continue;
F_44 ( L_62 \
L_63 , V_109 ) ;
}
return - V_177 ;
}
}
return 0 ;
}
static unsigned F_150 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_27 = 0 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 ) {
if ( V_16 -> V_312 [ V_109 ] . V_313 != V_335 )
V_27 |= 1 << V_109 ;
}
return V_27 ;
}
static int F_151 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
T_1 V_167 ;
F_71 ( L_64 ) ;
V_155 = F_152 ( V_16 -> V_182 , F_150 ( V_3 ) ) ;
if ( V_155 )
return V_155 ;
F_100 ( V_3 ) ;
F_9 ( V_3 , V_171 ) ;
if ( F_18 ( V_3 , V_171 , 30 , 1 ) != 1 ) {
F_44 ( L_65 ) ;
V_155 = - V_177 ;
goto V_337;
}
V_155 = F_143 ( V_3 ) ;
if ( V_155 )
goto V_337;
V_167 = F_9 ( V_3 , V_277 ) ;
V_167 = F_118 ( V_167 , 1 , 15 , 15 ) ;
V_167 = F_118 ( V_167 , 1 , 14 , 14 ) ;
V_167 = F_118 ( V_167 , 1 , 13 , 13 ) ;
V_167 = F_118 ( V_167 , 0x1fff , 12 , 0 ) ;
F_7 ( V_3 , V_277 , V_167 ) ;
if ( V_16 -> V_338 ) {
unsigned V_326 ;
int V_109 ;
F_71 ( L_66 ) ;
V_326 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 ) {
if ( V_16 -> V_312 [ V_109 ] . V_313 == V_335 )
continue;
V_326 |= 1 << V_109 ;
}
F_147 ( V_3 , V_326 , 0 ) ;
}
V_155 = F_141 ( V_3 , V_339 ) ;
if ( V_155 )
goto V_340;
if ( F_18 ( V_3 , V_276 , 29 , 1 ) != 1 ) {
F_44 ( L_67 ) ;
V_155 = - V_201 ;
goto V_341;
}
F_89 ( V_3 , true ) ;
F_89 ( V_3 , false ) ;
F_90 ( V_3 , V_194 , 1 , 20 , 20 ) ;
V_155 = F_149 ( V_3 ) ;
if ( V_155 )
goto V_342;
if ( V_16 -> V_338 ) {
T_3 V_32 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_35 ) ;
F_24 ( & V_32 , V_36 ) ;
F_148 ( V_3 ) ;
}
F_90 ( V_3 , V_277 , 0 , 15 , 15 ) ;
F_146 ( V_3 ) ;
if ( V_16 -> V_343 == V_344 ) {
F_90 ( V_3 , V_194 ,
V_16 -> V_345 . V_346 , 13 , 13 ) ;
}
V_16 -> V_338 = false ;
F_71 ( L_68 ) ;
return 0 ;
V_342:
F_90 ( V_3 , V_194 , 0 , 20 , 20 ) ;
V_341:
F_141 ( V_3 , V_347 ) ;
V_340:
if ( V_16 -> V_338 )
F_148 ( V_3 ) ;
V_337:
F_101 ( V_3 ) ;
F_153 ( V_16 -> V_182 , F_150 ( V_3 ) ) ;
return V_155 ;
}
static void F_154 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_90 ( V_3 , V_194 , 0 , 13 , 13 ) ;
F_141 ( V_3 , V_347 ) ;
F_101 ( V_3 ) ;
F_153 ( V_16 -> V_182 , F_150 ( V_3 ) ) ;
}
static void F_155 ( struct V_2 * V_3 ,
enum V_348 V_349 , enum V_348 V_350 ,
enum V_348 V_351 , enum V_348 V_352 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 = 0 ;
int V_353 = 0 ;
int V_109 ;
V_16 -> V_149 [ 0 ] . V_354 = V_349 ;
V_16 -> V_149 [ 1 ] . V_354 = V_350 ;
V_16 -> V_149 [ 2 ] . V_354 = V_351 ;
V_16 -> V_149 [ 3 ] . V_354 = V_352 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ ) {
T_4 V_355 ;
int V_356 = V_16 -> V_149 [ V_109 ] . V_354 ;
if ( V_353 + V_356 > 4 ) {
F_44 ( L_69 ) ;
F_26 () ;
return;
}
V_355 = F_156 ( V_353 , 2 , 0 ) | F_156 ( V_356 , 7 , 4 ) ;
V_155 |= V_355 << ( 8 * V_109 ) ;
V_353 += V_356 ;
}
F_7 ( V_3 , V_283 , V_155 ) ;
}
static void F_157 ( struct V_2 * V_3 ,
enum V_348 V_349 , enum V_348 V_350 ,
enum V_348 V_351 , enum V_348 V_352 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 = 0 ;
int V_353 = 0 ;
int V_109 ;
V_16 -> V_149 [ 0 ] . V_357 = V_349 ;
V_16 -> V_149 [ 1 ] . V_357 = V_350 ;
V_16 -> V_149 [ 2 ] . V_357 = V_351 ;
V_16 -> V_149 [ 3 ] . V_357 = V_352 ;
for ( V_109 = 0 ; V_109 < 4 ; V_109 ++ ) {
T_4 V_355 ;
int V_356 = V_16 -> V_149 [ V_109 ] . V_357 ;
if ( V_353 + V_356 > 4 ) {
F_44 ( L_69 ) ;
F_26 () ;
return;
}
V_355 = F_156 ( V_353 , 2 , 0 ) | F_156 ( V_356 , 7 , 4 ) ;
V_155 |= V_355 << ( 8 * V_109 ) ;
V_353 += V_356 ;
}
F_7 ( V_3 , V_284 , V_155 ) ;
}
static int F_158 ( struct V_2 * V_3 )
{
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_277 ) ;
V_155 = F_118 ( V_155 , 1 , 15 , 15 ) ;
F_7 ( V_3 , V_277 , V_155 ) ;
if ( F_18 ( V_3 , V_277 , 15 , 0 ) != 0 ) {
F_44 ( L_70 ) ;
return - V_177 ;
}
return 0 ;
}
static bool F_159 ( struct V_2 * V_3 , int V_75 )
{
return F_19 ( V_3 , F_134 ( V_75 ) , 0 , 0 ) ;
}
static void F_160 ( void * V_26 , T_1 V_27 )
{
struct V_358 * V_359 =
(struct V_358 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_359 -> V_3 ) ;
const int V_75 = V_16 -> V_360 ;
T_4 V_361 = V_16 -> V_362 ? 30 : 31 ;
if ( F_19 ( V_359 -> V_3 , F_135 ( V_75 ) , V_361 , V_361 ) == 0 )
F_17 ( V_359 -> V_28 ) ;
}
static int F_161 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_162 ( V_28 ) ;
struct V_358 V_359 = { V_3 , & V_28 } ;
int V_155 = 0 ;
T_4 V_361 ;
V_361 = V_16 -> V_362 ? 30 : 31 ;
V_155 = F_65 ( V_3 , V_75 , F_160 ,
& V_359 , V_76 ) ;
if ( V_155 )
goto V_256;
if ( F_19 ( V_3 , F_135 ( V_75 ) , V_361 , V_361 ) ) {
if ( F_163 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_71 ) ;
V_155 = - V_177 ;
goto V_257;
}
}
F_66 ( V_3 , V_75 , F_160 ,
& V_359 , V_76 ) ;
return 0 ;
V_257:
F_66 ( V_3 , V_75 , F_160 ,
& V_359 , V_76 ) ;
V_256:
return V_155 ;
}
static void F_164 ( void * V_26 , T_1 V_27 )
{
struct V_358 * V_363 =
(struct V_358 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_363 -> V_3 ) ;
const int V_75 = V_16 -> V_360 ;
if ( F_19 ( V_363 -> V_3 , F_134 ( V_75 ) , 5 , 5 ) == 0 )
F_17 ( V_363 -> V_28 ) ;
}
static int F_165 ( struct V_2 * V_3 , int V_75 )
{
F_162 ( V_28 ) ;
struct V_358 V_363 = { V_3 , & V_28 } ;
int V_155 = 0 ;
V_155 = F_65 ( V_3 , V_75 , F_164 ,
& V_363 , V_76 ) ;
if ( V_155 )
goto V_256;
if ( F_19 ( V_3 , F_134 ( V_75 ) , 5 , 5 ) ) {
if ( F_163 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_72 ) ;
V_155 = - V_177 ;
goto V_257;
}
}
F_66 ( V_3 , V_75 , F_164 ,
& V_363 , V_76 ) ;
return 0 ;
V_257:
F_66 ( V_3 , V_75 , F_164 ,
& V_363 , V_76 ) ;
V_256:
return V_155 ;
}
static int F_166 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( F_167 () ) ;
if ( ! F_159 ( V_3 , V_75 ) )
return 0 ;
switch ( V_16 -> V_149 [ V_75 ] . V_364 ) {
case V_365 :
return F_161 ( V_3 , V_75 ) ;
case V_366 :
return F_165 ( V_3 , V_75 ) ;
default:
F_26 () ;
return - V_153 ;
}
}
static int F_168 ( struct V_2 * V_3 , int V_75 ,
bool V_163 )
{
F_71 ( L_73 ,
V_75 , V_163 ) ;
V_163 = V_163 ? 1 : 0 ;
F_90 ( V_3 , F_134 ( V_75 ) , V_163 , 0 , 0 ) ;
if ( F_18 ( V_3 , F_134 ( V_75 ) ,
0 , V_163 ) != V_163 ) {
F_44 ( L_74 , V_163 ) ;
return - V_177 ;
}
return 0 ;
}
static void F_169 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 ;
F_71 ( L_75 , V_75 ) ;
V_155 = F_9 ( V_3 , F_134 ( V_75 ) ) ;
if ( F_103 ( V_155 , 15 , 15 ) )
F_44 ( L_76 ,
V_75 ) ;
V_155 = F_118 ( V_155 , 0 , 1 , 1 ) ;
V_155 = F_118 ( V_155 , 0 , 2 , 2 ) ;
V_155 = F_118 ( V_155 , 0 , 3 , 3 ) ;
V_155 = F_118 ( V_155 , 0 , 4 , 4 ) ;
V_155 = F_118 ( V_155 , 1 , 7 , 7 ) ;
V_155 = F_118 ( V_155 , 1 , 8 , 8 ) ;
V_155 = F_118 ( V_155 , 0 , 9 , 9 ) ;
if ( F_87 ( V_367 ) )
V_155 = F_118 ( V_155 , 3 , 11 , 10 ) ;
V_155 = F_118 ( V_155 , 4 , 29 , 27 ) ;
V_155 = F_118 ( V_155 , 4 , 23 , 21 ) ;
F_7 ( V_3 , F_134 ( V_75 ) , V_155 ) ;
V_16 -> V_149 [ V_75 ] . V_364 = V_366 ;
}
static int F_170 ( struct V_2 * V_3 , int V_75 ,
enum V_368 V_364 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_149 [ V_75 ] . V_364 == V_364 )
return 0 ;
F_71 ( L_77 , V_75 ) ;
F_166 ( V_3 , V_75 ) ;
F_168 ( V_3 , V_75 , 0 ) ;
if ( F_18 ( V_3 , F_134 ( V_75 ) , 15 , 0 ) != 0 ) {
F_44 ( L_78 , V_75 ) ;
return - V_177 ;
}
F_90 ( V_3 , F_134 ( V_75 ) , V_364 , 1 , 1 ) ;
if ( F_87 ( V_369 ) ) {
bool V_163 = V_364 == V_365 ;
F_90 ( V_3 , F_134 ( V_75 ) , V_163 , 30 , 30 ) ;
}
F_168 ( V_3 , V_75 , 1 ) ;
V_16 -> V_149 [ V_75 ] . V_364 = V_364 ;
return 0 ;
}
static void F_171 ( struct V_5 * V_6 , int V_75 ,
bool V_163 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_79 , V_75 , V_163 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_168 ( V_3 , V_75 , 0 ) ;
F_89 ( V_3 , 0 ) ;
F_90 ( V_3 , F_134 ( V_75 ) , V_163 , 9 , 9 ) ;
F_168 ( V_3 , V_75 , 1 ) ;
F_89 ( V_3 , 1 ) ;
F_158 ( V_3 ) ;
if ( V_16 -> V_345 . V_346 && V_163 )
F_172 ( V_6 , V_75 ) ;
}
static void F_173 ( struct V_2 * V_3 , int V_75 )
{
while ( F_19 ( V_3 , F_134 ( V_75 ) , 20 , 20 ) ) {
T_1 V_15 ;
V_15 = F_9 ( V_3 , F_138 ( V_75 ) ) ;
F_71 ( L_80 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
}
}
static void F_174 ( T_13 V_251 )
{
F_44 ( L_81 , V_251 ) ;
if ( V_251 & ( 1 << 0 ) )
F_44 ( L_82 ) ;
if ( V_251 & ( 1 << 1 ) )
F_44 ( L_83 ) ;
if ( V_251 & ( 1 << 2 ) )
F_44 ( L_84 ) ;
if ( V_251 & ( 1 << 3 ) )
F_44 ( L_85 ) ;
if ( V_251 & ( 1 << 4 ) )
F_44 ( L_86 ) ;
if ( V_251 & ( 1 << 5 ) )
F_44 ( L_87 ) ;
if ( V_251 & ( 1 << 6 ) )
F_44 ( L_88 ) ;
if ( V_251 & ( 1 << 7 ) )
F_44 ( L_89 ) ;
if ( V_251 & ( 1 << 8 ) )
F_44 ( L_90 ) ;
if ( V_251 & ( 1 << 9 ) )
F_44 ( L_91 ) ;
if ( V_251 & ( 1 << 10 ) )
F_44 ( L_92 ) ;
if ( V_251 & ( 1 << 11 ) )
F_44 ( L_93 ) ;
if ( V_251 & ( 1 << 12 ) )
F_44 ( L_94 ) ;
if ( V_251 & ( 1 << 13 ) )
F_44 ( L_95 ) ;
if ( V_251 & ( 1 << 14 ) )
F_44 ( L_96 ) ;
if ( V_251 & ( 1 << 15 ) )
F_44 ( L_97 ) ;
}
static T_13 F_175 ( struct V_2 * V_3 ,
int V_75 )
{
while ( F_19 ( V_3 , F_134 ( V_75 ) , 20 , 20 ) ) {
T_1 V_15 ;
T_4 V_370 ;
V_15 = F_9 ( V_3 , F_138 ( V_75 ) ) ;
F_44 ( L_98 , V_15 ) ;
V_370 = F_103 ( V_15 , 5 , 0 ) ;
if ( V_370 == V_371 ) {
T_13 V_251 = F_103 ( V_15 , 23 , 8 ) ;
F_174 ( V_251 ) ;
} else if ( V_370 == V_372 ) {
F_44 ( L_99 ,
F_103 ( V_15 , 23 , 8 ) ) ;
} else if ( V_370 == V_373 ) {
F_44 ( L_100 ,
F_103 ( V_15 , 23 , 8 ) ) ;
} else if ( V_370 == V_374 ) {
F_44 ( L_101 ,
F_103 ( V_15 , 23 , 8 ) ) ;
F_173 ( V_3 , V_75 ) ;
} else {
F_44 ( L_102 , V_370 ) ;
}
}
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , int V_75 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_375 || V_16 -> V_376 )
F_71 ( L_103 , V_75 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( F_19 ( V_3 , F_134 ( V_75 ) , 20 , 20 ) ) {
F_44 ( L_104 ) ;
F_175 ( V_3 , V_75 ) ;
}
F_90 ( V_3 , F_134 ( V_75 ) , 1 , 6 , 6 ) ;
F_9 ( V_3 , F_134 ( V_75 ) ) ;
return 0 ;
}
static int F_177 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
F_162 ( V_28 ) ;
int V_155 = 0 ;
T_1 V_251 ;
V_155 = F_65 ( V_3 , V_75 , F_16 ,
& V_28 , V_377 ) ;
if ( V_155 )
goto V_256;
V_155 = F_63 ( V_3 , F_16 , & V_28 ,
V_116 ) ;
if ( V_155 )
goto V_257;
V_155 = F_176 ( V_3 , V_75 ) ;
if ( V_155 )
goto V_378;
if ( F_163 ( & V_28 ,
F_20 ( 500 ) ) == 0 ) {
F_44 ( L_105 ) ;
V_155 = - V_177 ;
goto V_378;
}
V_251 = F_69 ( V_3 ) ;
if ( V_251 ) {
F_44 ( L_106 , V_251 ) ;
V_155 = - V_177 ;
goto V_378;
}
V_378:
F_64 ( V_3 , F_16 , & V_28 ,
V_116 ) ;
V_257:
F_66 ( V_3 , V_75 , F_16 ,
& V_28 , V_377 ) ;
V_256:
return V_155 ;
}
static inline void F_178 ( struct V_2 * V_3 ,
int V_75 , T_4 V_379 , T_13 V_380 , T_4 V_381 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_382 ;
F_73 ( ! F_15 ( V_3 ) ) ;
V_382 = V_379 | V_16 -> V_149 [ V_75 ] . V_383 << 6 ;
V_15 = F_156 ( V_382 , 7 , 0 ) | F_156 ( V_380 , 23 , 8 ) |
F_156 ( V_381 , 31 , 24 ) ;
F_7 ( V_3 , F_136 ( V_75 ) , V_15 ) ;
}
static inline void F_179 ( struct V_2 * V_3 ,
int V_75 , T_4 V_169 , T_4 V_170 , T_4 V_384 , T_4 V_385 )
{
T_1 V_15 ;
V_15 = V_385 << 24 | V_384 << 16 | V_170 << 8 | V_169 << 0 ;
F_7 ( V_3 , F_137 ( V_75 ) , V_15 ) ;
}
static int F_180 ( struct V_2 * V_3 , int V_75 ,
T_4 V_379 , T_4 * V_26 , T_13 V_380 , T_4 V_381 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_109 ;
T_4 * V_329 ;
int V_155 = 0 ;
T_4 V_169 , V_170 , V_384 , V_385 ;
if ( V_16 -> V_375 )
F_71 ( L_107 , V_380 ) ;
if ( V_16 -> V_149 [ V_75 ] . V_354 * 32 * 4 < V_380 + 4 ) {
F_44 ( L_108 ) ;
return - V_153 ;
}
F_170 ( V_3 , V_75 , V_366 ) ;
F_178 ( V_3 , V_75 , V_379 , V_380 , V_381 ) ;
V_329 = V_26 ;
for ( V_109 = 0 ; V_109 < V_380 > > 2 ; V_109 ++ ) {
if ( V_16 -> V_375 )
F_71 ( L_109 , V_109 ) ;
V_169 = * V_329 ++ ;
V_170 = * V_329 ++ ;
V_384 = * V_329 ++ ;
V_385 = * V_329 ++ ;
F_179 ( V_3 , V_75 , V_169 , V_170 , V_384 , V_385 ) ;
}
V_109 = V_380 % 4 ;
if ( V_109 ) {
V_169 = 0 ; V_170 = 0 ; V_384 = 0 ;
if ( V_16 -> V_375 )
F_71 ( L_110 , V_109 ) ;
switch ( V_109 ) {
case 3 :
V_169 = * V_329 ++ ;
V_170 = * V_329 ++ ;
V_384 = * V_329 ++ ;
break;
case 2 :
V_169 = * V_329 ++ ;
V_170 = * V_329 ++ ;
break;
case 1 :
V_169 = * V_329 ++ ;
break;
}
F_179 ( V_3 , V_75 , V_169 , V_170 , V_384 , 0 ) ;
}
return V_155 ;
}
static int F_181 ( struct V_2 * V_3 , int V_75 ,
T_4 V_379 , T_13 V_26 , T_4 V_381 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 ;
T_4 V_382 ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( V_16 -> V_375 )
F_71 ( L_111 ,
V_75 ,
V_379 , V_26 & 0xff , ( V_26 >> 8 ) & 0xff ) ;
F_170 ( V_3 , V_75 , V_366 ) ;
if ( F_103 ( F_9 ( V_3 , F_134 ( V_75 ) ) , 16 , 16 ) ) {
F_44 ( L_112 ) ;
return - V_153 ;
}
V_382 = V_379 | V_16 -> V_149 [ V_75 ] . V_383 << 6 ;
V_155 = ( V_382 << 0 ) | ( V_26 << 8 ) | ( V_381 << 24 ) ;
F_7 ( V_3 , F_138 ( V_75 ) , V_155 ) ;
return 0 ;
}
static int F_172 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_180 ( V_3 , V_75 , V_386 , NULL ,
0 , 0 ) ;
}
static int F_182 ( struct V_2 * V_3 ,
int V_75 , T_4 * V_26 , int V_380 , enum V_387 type )
{
int V_155 ;
if ( V_380 == 0 ) {
F_61 ( type == V_388 ) ;
V_155 = F_181 ( V_3 , V_75 ,
V_389 , 0 , 0 ) ;
} else if ( V_380 == 1 ) {
V_155 = F_181 ( V_3 , V_75 ,
type == V_390 ?
V_391 :
V_392 , V_26 [ 0 ] , 0 ) ;
} else if ( V_380 == 2 ) {
V_155 = F_181 ( V_3 , V_75 ,
type == V_390 ?
V_393 :
V_394 ,
V_26 [ 0 ] | ( V_26 [ 1 ] << 8 ) , 0 ) ;
} else {
V_155 = F_180 ( V_3 , V_75 ,
type == V_390 ?
V_395 :
V_396 , V_26 , V_380 , 0 ) ;
}
return V_155 ;
}
static int F_183 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_380 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_182 ( V_3 , V_75 , V_26 , V_380 ,
V_388 ) ;
}
static int F_184 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_380 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_182 ( V_3 , V_75 , V_26 , V_380 ,
V_390 ) ;
}
static int F_185 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_26 , int V_380 , enum V_387 type )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_155 ;
V_155 = F_182 ( V_3 , V_75 , V_26 , V_380 , type ) ;
if ( V_155 )
goto V_251;
V_155 = F_177 ( V_6 , V_75 ) ;
if ( V_155 )
goto V_251;
if ( F_19 ( V_3 , F_134 ( V_75 ) , 20 , 20 ) ) {
F_44 ( L_113 ) ;
F_175 ( V_3 , V_75 ) ;
V_155 = - V_177 ;
goto V_251;
}
return 0 ;
V_251:
F_44 ( L_114 ,
V_75 , V_26 [ 0 ] , V_380 ) ;
return V_155 ;
}
static int F_186 ( struct V_5 * V_6 , int V_75 , T_4 * V_26 ,
int V_380 )
{
return F_185 ( V_6 , V_75 , V_26 , V_380 ,
V_388 ) ;
}
static int F_187 ( struct V_5 * V_6 , int V_75 , T_4 * V_26 ,
int V_380 )
{
return F_185 ( V_6 , V_75 , V_26 , V_380 ,
V_390 ) ;
}
static int F_188 ( struct V_2 * V_3 ,
int V_75 , T_4 V_397 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
if ( V_16 -> V_376 )
F_71 ( L_115 ,
V_75 , V_397 ) ;
V_155 = F_181 ( V_3 , V_75 , V_398 , V_397 , 0 ) ;
if ( V_155 ) {
F_44 ( L_116
L_117 , V_75 , V_397 ) ;
return V_155 ;
}
return 0 ;
}
static int F_189 ( struct V_2 * V_3 ,
int V_75 , T_4 * V_399 , int V_400 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_13 V_26 ;
T_4 V_379 ;
int V_155 ;
if ( V_16 -> V_376 )
F_71 ( L_118 ,
V_75 , V_400 ) ;
if ( V_400 == 0 ) {
V_379 = V_401 ;
V_26 = 0 ;
} else if ( V_400 == 1 ) {
V_379 = V_402 ;
V_26 = V_399 [ 0 ] ;
} else if ( V_400 == 2 ) {
V_379 = V_403 ;
V_26 = V_399 [ 0 ] | ( V_399 [ 1 ] << 8 ) ;
} else {
F_26 () ;
return - V_153 ;
}
V_155 = F_181 ( V_3 , V_75 , V_379 , V_26 , 0 ) ;
if ( V_155 ) {
F_44 ( L_119
L_117 , V_75 , V_400 ) ;
return V_155 ;
}
return 0 ;
}
static int F_190 ( struct V_2 * V_3 , int V_75 ,
T_4 * V_404 , int V_405 , enum V_387 type )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_370 ;
int V_155 ;
if ( F_19 ( V_3 , F_134 ( V_75 ) , 20 , 20 ) == 0 ) {
F_44 ( L_120 ) ;
V_155 = - V_177 ;
goto V_251;
}
V_15 = F_9 ( V_3 , F_138 ( V_75 ) ) ;
if ( V_16 -> V_376 )
F_71 ( L_121 , V_15 ) ;
V_370 = F_103 ( V_15 , 5 , 0 ) ;
if ( V_370 == V_371 ) {
T_13 V_251 = F_103 ( V_15 , 23 , 8 ) ;
F_174 ( V_251 ) ;
V_155 = - V_177 ;
goto V_251;
} else if ( V_370 == ( type == V_390 ?
V_406 :
V_372 ) ) {
T_4 V_26 = F_103 ( V_15 , 15 , 8 ) ;
if ( V_16 -> V_376 )
F_71 ( L_122 ,
type == V_390 ? L_123 :
L_124 , V_26 ) ;
if ( V_405 < 1 ) {
V_155 = - V_177 ;
goto V_251;
}
V_404 [ 0 ] = V_26 ;
return 1 ;
} else if ( V_370 == ( type == V_390 ?
V_407 :
V_373 ) ) {
T_13 V_26 = F_103 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_376 )
F_71 ( L_125 ,
type == V_390 ? L_123 :
L_124 , V_26 ) ;
if ( V_405 < 2 ) {
V_155 = - V_177 ;
goto V_251;
}
V_404 [ 0 ] = V_26 & 0xff ;
V_404 [ 1 ] = ( V_26 >> 8 ) & 0xff ;
return 2 ;
} else if ( V_370 == ( type == V_390 ?
V_408 :
V_374 ) ) {
int V_409 ;
int V_380 = F_103 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_376 )
F_71 ( L_126 ,
type == V_390 ? L_123 :
L_124 , V_380 ) ;
if ( V_380 > V_405 ) {
V_155 = - V_177 ;
goto V_251;
}
for ( V_409 = 0 ; V_409 < V_380 + 2 ; ) {
int V_410 ;
V_15 = F_9 ( V_3 ,
F_138 ( V_75 ) ) ;
if ( V_16 -> V_376 )
F_71 ( L_127 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
for ( V_410 = 0 ; V_410 < 4 ; ++ V_410 ) {
if ( V_409 < V_380 )
V_404 [ V_409 ] = ( V_15 >> ( V_410 * 8 ) ) & 0xff ;
++ V_409 ;
}
}
return V_380 ;
} else {
F_44 ( L_102 , V_370 ) ;
V_155 = - V_177 ;
goto V_251;
}
V_251:
F_44 ( L_128 , V_75 ,
type == V_390 ? L_123 : L_124 ) ;
return V_155 ;
}
static int F_191 ( struct V_5 * V_6 , int V_75 , T_4 V_397 ,
T_4 * V_404 , int V_405 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_155 ;
V_155 = F_188 ( V_3 , V_75 , V_397 ) ;
if ( V_155 )
goto V_251;
V_155 = F_177 ( V_6 , V_75 ) ;
if ( V_155 )
goto V_251;
V_155 = F_190 ( V_3 , V_75 , V_404 , V_405 ,
V_388 ) ;
if ( V_155 < 0 )
goto V_251;
if ( V_155 != V_405 ) {
V_155 = - V_177 ;
goto V_251;
}
return 0 ;
V_251:
F_44 ( L_129 , V_75 , V_397 ) ;
return V_155 ;
}
static int F_192 ( struct V_5 * V_6 , int V_75 ,
T_4 * V_399 , int V_400 , T_4 * V_404 , int V_405 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_155 ;
V_155 = F_189 ( V_3 , V_75 , V_399 , V_400 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_177 ( V_6 , V_75 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_190 ( V_3 , V_75 , V_404 , V_405 ,
V_390 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( V_155 != V_405 ) {
V_155 = - V_177 ;
return V_155 ;
}
return 0 ;
}
static int F_193 ( struct V_5 * V_6 , int V_75 ,
T_13 V_380 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_181 ( V_3 , V_75 ,
V_411 , V_380 , 0 ) ;
}
static int F_194 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_162 ( V_28 ) ;
int V_155 , V_109 ;
unsigned V_27 ;
F_71 ( L_130 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( V_16 -> V_338 ) ;
if ( V_16 -> V_338 )
return 0 ;
if ( F_19 ( V_3 , V_194 , 13 , 13 ) ) {
F_89 ( V_3 , 0 ) ;
F_90 ( V_3 , V_194 , 0 , 13 , 13 ) ;
F_89 ( V_3 , 1 ) ;
}
F_166 ( V_3 , 0 ) ;
F_166 ( V_3 , 1 ) ;
F_166 ( V_3 , 2 ) ;
F_166 ( V_3 , 3 ) ;
F_158 ( V_3 ) ;
F_168 ( V_3 , 0 , false ) ;
F_168 ( V_3 , 1 , false ) ;
F_168 ( V_3 , 2 , false ) ;
F_168 ( V_3 , 3 , false ) ;
if ( F_19 ( V_3 , V_285 , 16 , 16 ) ) {
F_44 ( L_131 ) ;
return - V_177 ;
}
if ( F_19 ( V_3 , V_285 , 17 , 17 ) ) {
F_44 ( L_132 ) ;
return - V_177 ;
}
V_155 = F_67 ( V_3 , F_16 , & V_28 ,
V_412 ) ;
if ( V_155 )
return V_155 ;
V_27 = 0 ;
for ( V_109 = 0 ; V_109 < V_16 -> V_311 ; ++ V_109 ) {
if ( V_16 -> V_312 [ V_109 ] . V_313 == V_335 )
continue;
V_27 |= 1 << V_109 ;
}
F_90 ( V_3 , V_285 , V_27 , 9 , 5 ) ;
F_9 ( V_3 , V_285 ) ;
if ( F_163 ( & V_28 ,
F_20 ( 1000 ) ) == 0 ) {
F_44 ( L_133 ) ;
V_155 = - V_177 ;
goto V_251;
}
F_68 ( V_3 , F_16 , & V_28 ,
V_412 ) ;
F_90 ( V_3 , V_285 , 0 , 9 , 5 ) ;
F_9 ( V_3 , V_285 ) ;
F_141 ( V_3 , V_413 ) ;
F_89 ( V_3 , false ) ;
V_16 -> V_338 = true ;
return 0 ;
V_251:
F_68 ( V_3 , F_16 , & V_28 ,
V_412 ) ;
return V_155 ;
}
static void F_195 ( struct V_2 * V_3 ,
unsigned V_414 , bool V_415 , bool V_416 )
{
unsigned long V_417 ;
unsigned long V_418 ;
T_1 V_155 ;
F_61 ( V_414 > 0x1fff ) ;
V_417 = F_94 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_278 ) ;
V_155 = F_118 ( V_155 , 1 , 15 , 15 ) ;
V_155 = F_118 ( V_155 , V_416 ? 1 : 0 , 14 , 14 ) ;
V_155 = F_118 ( V_155 , V_415 ? 1 : 0 , 13 , 13 ) ;
V_155 = F_118 ( V_155 , V_414 , 12 , 0 ) ;
F_7 ( V_3 , V_278 , V_155 ) ;
V_418 = V_414 * ( V_416 ? 16 : 1 ) * ( V_415 ? 4 : 1 ) ;
F_71 ( L_134 ,
V_418 ,
V_414 , V_415 ? L_135 : L_4 , V_416 ? L_136 : L_4 ,
( V_418 * 1000 ) / ( V_417 / 1000 / 1000 ) ) ;
}
static void F_196 ( struct V_2 * V_3 , unsigned V_414 ,
bool V_419 , bool V_416 )
{
unsigned long V_417 ;
unsigned long V_418 ;
T_1 V_155 ;
F_61 ( V_414 > 0x1fff ) ;
V_417 = F_94 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_277 ) ;
V_155 = F_118 ( V_155 , 1 , 31 , 31 ) ;
V_155 = F_118 ( V_155 , V_416 ? 1 : 0 , 30 , 30 ) ;
V_155 = F_118 ( V_155 , V_419 ? 1 : 0 , 29 , 29 ) ;
V_155 = F_118 ( V_155 , V_414 , 28 , 16 ) ;
F_7 ( V_3 , V_277 , V_155 ) ;
V_418 = V_414 * ( V_416 ? 16 : 1 ) * ( V_419 ? 8 : 1 ) ;
F_71 ( L_137 ,
V_418 ,
V_414 , V_419 ? L_138 : L_4 , V_416 ? L_136 : L_4 ,
( V_418 * 1000 ) / ( V_417 / 1000 / 1000 ) ) ;
}
static void F_197 ( struct V_2 * V_3 ,
unsigned V_414 , bool V_415 , bool V_416 )
{
unsigned long V_417 ;
unsigned long V_418 ;
T_1 V_155 ;
F_61 ( V_414 > 0x1fff ) ;
V_417 = F_94 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_277 ) ;
V_155 = F_118 ( V_155 , 1 , 15 , 15 ) ;
V_155 = F_118 ( V_155 , V_416 ? 1 : 0 , 14 , 14 ) ;
V_155 = F_118 ( V_155 , V_415 ? 1 : 0 , 13 , 13 ) ;
V_155 = F_118 ( V_155 , V_414 , 12 , 0 ) ;
F_7 ( V_3 , V_277 , V_155 ) ;
V_418 = V_414 * ( V_416 ? 16 : 1 ) * ( V_415 ? 4 : 1 ) ;
F_71 ( L_139 ,
V_418 ,
V_414 , V_415 ? L_135 : L_4 , V_416 ? L_136 : L_4 ,
( V_418 * 1000 ) / ( V_417 / 1000 / 1000 ) ) ;
}
static void F_198 ( struct V_2 * V_3 ,
unsigned V_414 , bool V_415 , bool V_416 )
{
unsigned long V_417 ;
unsigned long V_418 ;
T_1 V_155 ;
F_61 ( V_414 > 0x1fff ) ;
V_417 = F_93 ( V_3 ) ;
V_155 = F_9 ( V_3 , V_278 ) ;
V_155 = F_118 ( V_155 , 1 , 31 , 31 ) ;
V_155 = F_118 ( V_155 , V_416 ? 1 : 0 , 30 , 30 ) ;
V_155 = F_118 ( V_155 , V_415 ? 1 : 0 , 29 , 29 ) ;
V_155 = F_118 ( V_155 , V_414 , 28 , 16 ) ;
F_7 ( V_3 , V_278 , V_155 ) ;
V_418 = V_414 * ( V_416 ? 16 : 1 ) * ( V_415 ? 4 : 1 ) ;
F_71 ( L_140 ,
V_418 ,
V_414 , V_415 ? L_135 : L_4 , V_416 ? L_136 : L_4 ,
( V_418 * 1000 ) / ( V_417 / 1000 / 1000 ) ) ;
}
static void F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_420 ;
if ( V_16 -> V_343 == V_344 ) {
int V_421 = F_25 ( V_16 -> V_422 ) ;
struct V_423 * V_424 = & V_16 -> V_424 ;
if ( V_16 -> V_425 <= V_424 -> V_426 * V_421 / 8 )
V_420 = 0 ;
else
V_420 = 2 ;
} else {
V_420 = 2 ;
}
F_90 ( V_3 , V_176 , V_420 , 13 , 12 ) ;
}
static void F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
bool V_427 ;
T_1 V_155 ;
if ( V_16 -> V_345 . V_428 == V_429 )
V_427 = true ;
else
V_427 = false ;
V_155 = F_9 ( V_3 , V_176 ) ;
V_155 = F_118 ( V_155 , 1 , 9 , 9 ) ;
V_155 = F_118 ( V_155 , 1 , 10 , 10 ) ;
V_155 = F_118 ( V_155 , 1 , 11 , 11 ) ;
V_155 = F_118 ( V_155 , 1 , 15 , 15 ) ;
V_155 = F_118 ( V_155 , V_427 , 16 , 16 ) ;
V_155 = F_118 ( V_155 , 1 , 17 , 17 ) ;
V_155 = F_118 ( V_155 , V_427 , 18 , 18 ) ;
F_7 ( V_3 , V_176 , V_155 ) ;
}
static void F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_430 = V_16 -> V_345 . V_430 ;
int V_431 = V_16 -> V_345 . V_431 ;
int V_432 = V_16 -> V_345 . V_432 ;
int V_433 = V_16 -> V_345 . V_433 ;
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_176 ) ;
V_155 = F_118 ( V_155 , V_430 , 20 , 20 ) ;
V_155 = F_118 ( V_155 , V_431 , 21 , 21 ) ;
V_155 = F_118 ( V_155 , V_432 , 22 , 22 ) ;
V_155 = F_118 ( V_155 , V_433 , 23 , 23 ) ;
F_7 ( V_3 , V_176 , V_155 ) ;
}
static int F_202 ( int V_434 , bool V_435 , int V_436 ,
int V_437 , int V_438 , int V_439 , int V_440 )
{
int V_441 ;
if ( V_435 ) {
V_441 = V_436 + V_437 + F_108 ( V_436 , 2 ) + 1 ;
} else {
int V_442 , V_443 ;
V_442 = V_439 + V_436 + V_437 + F_108 ( V_436 , 2 ) + 1 ;
V_443 = V_439 + V_436 + V_438 + V_440 + V_439 +
V_436 + 1 ;
V_441 = F_108 ( V_442 , V_443 ) ;
}
return V_434 > V_441 ? V_434 - V_441 : 0 ;
}
static int F_203 ( int V_434 , int V_436 , int V_437 ,
int V_190 , int V_444 )
{
int V_445 ;
int V_446 ;
int V_447 ;
int V_448 = 16 ;
int V_449 ;
V_445 = V_437 + F_108 ( V_436 , 2 ) + 1 ;
V_446 = V_448 * ( V_434 - V_445 ) ;
V_447 = V_444 * V_190 ;
V_449 = ( ( V_446 - 8 * V_448 - 5 * V_444 ) / V_447 -
26 ) / 16 ;
return F_108 ( V_449 , 0 ) ;
}
static void F_204 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_430 ;
int V_431 , V_432 , V_433 ;
int V_450 , V_451 , V_452 , V_453 , V_454 , V_190 ;
int V_455 , V_456 , V_457 , V_458 ;
int V_322 , V_320 , V_438 ;
bool V_435 ;
struct V_423 * V_424 = & V_16 -> V_424 ;
int V_421 = F_25 ( V_16 -> V_422 ) ;
int V_459 = V_16 -> V_307 - 1 ;
int V_460 = V_16 -> V_192 . V_227 + 1 ;
int V_461 = 0 , V_462 = 0 ;
int V_463 = 0 , V_464 = 0 ;
int V_465 = 0 , V_466 = 0 ;
int V_467 = 0 , V_468 = 0 ;
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_176 ) ;
V_430 = F_103 ( V_155 , 20 , 20 ) ;
V_431 = F_103 ( V_155 , 21 , 21 ) ;
V_432 = F_103 ( V_155 , 22 , 22 ) ;
V_433 = F_103 ( V_155 , 23 , 23 ) ;
V_155 = F_9 ( V_3 , V_279 ) ;
V_452 = F_103 ( V_155 , 11 , 0 ) ;
V_451 = F_103 ( V_155 , 23 , 12 ) ;
V_450 = F_103 ( V_155 , 31 , 24 ) ;
V_155 = F_9 ( V_3 , V_282 ) ;
V_456 = F_103 ( V_155 , 7 , 0 ) ;
V_455 = F_103 ( V_155 , 15 , 8 ) ;
V_155 = F_9 ( V_3 , V_291 ) ;
V_458 = F_103 ( V_155 , 15 , 0 ) ;
V_457 = F_103 ( V_155 , 31 , 16 ) ;
V_155 = F_9 ( V_3 , V_194 ) ;
V_190 = F_103 ( V_155 , 12 , 0 ) ;
V_435 = F_103 ( V_155 , 13 , 13 ) ;
V_155 = F_9 ( V_3 , V_293 ) ;
V_320 = F_103 ( V_155 , 7 , 0 ) ;
V_155 = F_9 ( V_3 , V_294 ) ;
V_322 = F_103 ( V_155 , 15 , 8 ) ;
V_438 = V_320 + V_322 ;
V_453 = F_98 ( V_424 -> V_426 * V_421 , 8 ) ;
V_454 = V_452 + V_451 + V_450 + F_98 ( V_453 + 6 , V_459 ) ;
if ( ! V_433 ) {
V_461 = F_202 ( V_450 , V_435 ,
V_457 , V_458 ,
V_438 , V_455 , V_456 ) ;
V_462 = F_203 ( V_450 ,
V_457 , V_458 ,
V_190 , V_460 ) ;
}
if ( ! V_431 ) {
V_463 = F_202 ( V_451 , V_435 ,
V_457 , V_458 ,
V_438 , V_455 , V_456 ) ;
V_464 = F_203 ( V_451 ,
V_457 , V_458 ,
V_190 , V_460 ) ;
}
if ( ! V_432 ) {
V_465 = F_202 ( V_452 , V_435 ,
V_457 , V_458 ,
V_438 , V_455 , V_456 ) ;
V_466 = F_203 ( V_452 ,
V_457 , V_458 ,
V_190 , V_460 ) ;
}
if ( ! V_430 ) {
V_467 = F_202 ( V_454 , V_435 ,
V_457 , V_458 ,
V_438 , V_455 , V_456 ) ;
V_468 = F_203 ( V_454 ,
V_457 , V_458 ,
V_190 , V_460 ) ;
}
F_71 ( L_141 ,
V_461 , V_463 , V_465 ,
V_467 ) ;
F_71 ( L_142 ,
V_462 , V_464 , V_466 ,
V_468 ) ;
V_155 = F_9 ( V_3 , V_287 ) ;
V_155 = F_118 ( V_155 , V_461 , 23 , 16 ) ;
V_155 = F_118 ( V_155 , V_463 , 15 , 8 ) ;
V_155 = F_118 ( V_155 , V_465 , 7 , 0 ) ;
F_7 ( V_3 , V_287 , V_155 ) ;
V_155 = F_9 ( V_3 , V_289 ) ;
V_155 = F_118 ( V_155 , V_462 , 23 , 16 ) ;
V_155 = F_118 ( V_155 , V_464 , 15 , 8 ) ;
V_155 = F_118 ( V_155 , V_466 , 7 , 0 ) ;
F_7 ( V_3 , V_289 , V_155 ) ;
V_155 = F_9 ( V_3 , V_290 ) ;
V_155 = F_118 ( V_155 , V_467 , 31 , 15 ) ;
V_155 = F_118 ( V_155 , V_468 , 16 , 0 ) ;
F_7 ( V_3 , V_290 , V_155 ) ;
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_155 ;
int V_469 = 0 ;
F_155 ( V_3 , V_470 ,
V_470 ,
V_470 ,
V_470 ) ;
F_157 ( V_3 , V_470 ,
V_470 ,
V_470 ,
V_470 ) ;
F_197 ( V_3 , 0x1000 , false , false ) ;
F_196 ( V_3 , 0x1fff , true , true ) ;
F_195 ( V_3 , 0x1fff , true , true ) ;
F_198 ( V_3 , 0x1fff , true , true ) ;
switch ( F_25 ( V_16 -> V_422 ) ) {
case 16 :
V_469 = 0 ;
break;
case 18 :
V_469 = 1 ;
break;
case 24 :
V_469 = 2 ;
break;
default:
F_26 () ;
return - V_153 ;
}
V_155 = F_9 ( V_3 , V_176 ) ;
V_155 = F_118 ( V_155 , 1 , 1 , 1 ) ;
V_155 = F_118 ( V_155 , 1 , 2 , 2 ) ;
V_155 = F_118 ( V_155 , 1 , 3 , 3 ) ;
V_155 = F_118 ( V_155 , 1 , 4 , 4 ) ;
V_155 = F_118 ( V_155 , V_469 , 7 , 6 ) ;
V_155 = F_118 ( V_155 , 0 , 8 , 8 ) ;
V_155 = F_118 ( V_155 , 1 , 14 , 14 ) ;
V_155 = F_118 ( V_155 , 1 , 19 , 19 ) ;
if ( ! F_87 ( V_369 ) ) {
V_155 = F_118 ( V_155 , 1 , 24 , 24 ) ;
V_155 = F_118 ( V_155 , 0 , 25 , 25 ) ;
}
F_7 ( V_3 , V_176 , V_155 ) ;
F_199 ( V_3 ) ;
if ( V_16 -> V_343 == V_344 ) {
F_200 ( V_3 ) ;
F_201 ( V_3 ) ;
F_204 ( V_3 ) ;
}
F_169 ( V_3 , 0 ) ;
F_169 ( V_3 , 1 ) ;
F_169 ( V_3 , 2 ) ;
F_169 ( V_3 , 3 ) ;
return 0 ;
}
static void F_206 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_471 , V_323 , V_324 , V_322 ;
unsigned V_472 , V_473 ;
unsigned V_317 , V_318 , V_474 ;
unsigned V_319 , V_320 ;
unsigned V_455 , V_456 ;
unsigned V_457 , V_458 ;
unsigned V_475 ;
int V_459 = V_16 -> V_307 - 1 ;
T_1 V_155 ;
V_155 = F_9 ( V_3 , V_293 ) ;
V_317 = F_103 ( V_155 , 31 , 24 ) ;
V_318 = F_103 ( V_155 , 23 , 16 ) ;
V_474 = V_318 - V_317 ;
V_319 = F_103 ( V_155 , 15 , 8 ) ;
V_320 = F_103 ( V_155 , 7 , 0 ) ;
V_155 = F_9 ( V_3 , V_294 ) ;
V_471 = F_103 ( V_155 , 20 , 16 ) * 2 ;
V_322 = F_103 ( V_155 , 15 , 8 ) ;
V_323 = F_103 ( V_155 , 7 , 0 ) ;
V_155 = F_9 ( V_3 , V_295 ) ;
V_324 = F_103 ( V_155 , 7 , 0 ) ;
V_472 = 20 ;
V_473 = F_144 ( V_3 , 60 ) + 26 ;
V_475 = F_98 ( 4 , V_459 ) ;
V_455 = F_98 ( V_472 + V_471 + V_323 + V_324 ,
4 ) ;
V_456 = F_98 ( V_473 + V_319 , 4 ) + V_475 ;
F_61 ( V_455 == 0 || V_455 > 255 ) ;
F_61 ( V_456 == 0 || V_456 > 255 ) ;
V_155 = F_9 ( V_3 , V_282 ) ;
V_155 = F_118 ( V_155 , V_455 , 15 , 8 ) ;
V_155 = F_118 ( V_155 , V_456 , 7 , 0 ) ;
F_7 ( V_3 , V_282 , V_155 ) ;
F_71 ( L_143 ,
V_455 ,
V_456 ) ;
V_457 = 1 + F_98 ( V_471 , 4 ) +
F_98 ( V_317 , 4 ) +
F_98 ( V_474 + 3 , 4 ) ;
V_458 = F_98 ( V_319 + V_320 , 4 ) + 1 + V_475 ;
V_155 = F_156 ( V_457 , 31 , 16 ) |
F_156 ( V_458 , 15 , 0 ) ;
F_7 ( V_3 , V_291 , V_155 ) ;
F_71 ( L_144 ,
V_457 , V_458 ) ;
if ( V_16 -> V_343 == V_344 ) {
int V_450 = V_16 -> V_345 . V_450 ;
int V_451 = V_16 -> V_345 . V_451 ;
int V_452 = V_16 -> V_345 . V_452 ;
int V_476 = V_16 -> V_345 . V_476 ;
int V_477 = V_16 -> V_345 . V_477 ;
int V_478 = V_16 -> V_345 . V_478 ;
int V_479 = V_16 -> V_345 . V_479 ;
bool V_480 ;
struct V_423 * V_424 = & V_16 -> V_424 ;
int V_421 = F_25 ( V_16 -> V_422 ) ;
int V_481 , V_482 , V_453 ;
V_480 = V_16 -> V_345 . V_428 == V_429 ;
V_482 = V_480 ?
( ( V_450 == 0 && V_459 == 3 ) ? 1 : F_98 ( 4 , V_459 ) ) : 0 ;
V_453 = F_98 ( V_424 -> V_426 * V_421 , 8 ) ;
V_481 = F_98 ( 4 , V_459 ) + ( V_480 ? V_450 : 0 ) + V_482 + V_451 +
F_98 ( V_453 + 6 , V_459 ) + V_452 ;
F_71 ( L_145 , V_452 ,
V_451 , V_480 ? V_450 : 0 , V_481 ) ;
F_71 ( L_146 , V_478 , V_477 ,
V_476 , V_424 -> V_483 ) ;
V_155 = F_9 ( V_3 , V_279 ) ;
V_155 = F_118 ( V_155 , V_452 , 11 , 0 ) ;
V_155 = F_118 ( V_155 , V_451 , 23 , 12 ) ;
V_155 = F_118 ( V_155 , V_480 ? V_450 : 0 , 31 , 24 ) ;
F_7 ( V_3 , V_279 , V_155 ) ;
V_155 = F_9 ( V_3 , V_280 ) ;
V_155 = F_118 ( V_155 , V_478 , 7 , 0 ) ;
V_155 = F_118 ( V_155 , V_477 , 15 , 8 ) ;
V_155 = F_118 ( V_155 , V_476 , 23 , 16 ) ;
V_155 = F_118 ( V_155 , V_479 , 27 , 24 ) ;
F_7 ( V_3 , V_280 , V_155 ) ;
V_155 = F_9 ( V_3 , V_281 ) ;
V_155 = F_118 ( V_155 , V_424 -> V_483 , 14 , 0 ) ;
V_155 = F_118 ( V_155 , V_481 , 31 , 16 ) ;
F_7 ( V_3 , V_281 , V_155 ) ;
}
}
static int F_207 ( struct V_5 * V_6 ,
const struct V_484 * V_485 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_486 ;
const int * V_487 ;
struct V_488 V_312 [ V_332 ] ;
int V_489 ;
int V_109 ;
static const enum V_300 V_301 [] = {
V_302 ,
V_303 ,
V_304 ,
V_305 ,
V_306 ,
} ;
V_486 = V_485 -> V_486 ;
V_487 = V_485 -> V_487 ;
if ( V_486 < 4 || V_486 > V_16 -> V_311 * 2
|| V_486 % 2 != 0 )
return - V_153 ;
for ( V_109 = 0 ; V_109 < V_332 ; ++ V_109 )
V_312 [ V_109 ] . V_313 = V_335 ;
V_489 = 0 ;
for ( V_109 = 0 ; V_109 < V_486 ; V_109 += 2 ) {
T_4 V_490 , V_491 ;
int V_492 , V_493 ;
V_492 = V_487 [ V_109 ] ;
V_493 = V_487 [ V_109 + 1 ] ;
if ( V_492 < 0 || V_492 >= V_16 -> V_311 * 2 )
return - V_153 ;
if ( V_493 < 0 || V_493 >= V_16 -> V_311 * 2 )
return - V_153 ;
if ( V_492 & 1 ) {
if ( V_493 != V_492 - 1 )
return - V_153 ;
V_491 = 1 ;
} else {
if ( V_493 != V_492 + 1 )
return - V_153 ;
V_491 = 0 ;
}
V_490 = V_492 / 2 ;
V_312 [ V_490 ] . V_313 = V_301 [ V_109 / 2 ] ;
V_312 [ V_490 ] . V_309 = V_491 ;
V_489 ++ ;
}
memcpy ( V_16 -> V_312 , V_312 , sizeof( V_16 -> V_312 ) ) ;
V_16 -> V_307 = V_489 ;
return 0 ;
}
static int F_208 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_494 * V_495 = V_16 -> V_496 . V_497 ;
int V_421 = F_25 ( V_16 -> V_422 ) ;
struct V_5 * V_8 = & V_16 -> V_496 ;
T_4 V_379 ;
T_13 V_498 ;
int V_155 ;
if ( V_8 == NULL || V_8 -> V_497 == NULL ) {
F_44 ( L_147 ) ;
return - V_201 ;
}
V_155 = F_209 ( V_3 , V_495 ) ;
if ( V_155 )
goto V_499;
if ( V_16 -> V_343 == V_344 ) {
switch ( V_16 -> V_422 ) {
case V_39 :
V_379 = V_500 ;
break;
case V_40 :
V_379 = V_501 ;
break;
case V_41 :
V_379 = V_502 ;
break;
case V_42 :
V_379 = V_503 ;
break;
default:
V_155 = - V_153 ;
goto V_504;
}
F_89 ( V_3 , false ) ;
F_168 ( V_3 , V_75 , false ) ;
F_90 ( V_3 , F_134 ( V_75 ) , 1 , 4 , 4 ) ;
V_498 = F_98 ( V_16 -> V_424 . V_426 * V_421 , 8 ) ;
F_178 ( V_3 , V_75 , V_379 ,
V_498 , 0 ) ;
F_168 ( V_3 , V_75 , true ) ;
F_89 ( V_3 , true ) ;
}
V_155 = F_210 ( V_495 ) ;
if ( V_155 )
goto V_505;
return 0 ;
V_505:
if ( V_16 -> V_343 == V_344 ) {
F_89 ( V_3 , false ) ;
F_168 ( V_3 , V_75 , false ) ;
}
V_504:
F_211 ( V_3 , V_495 ) ;
V_499:
return V_155 ;
}
static void F_212 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_494 * V_495 = V_16 -> V_496 . V_497 ;
if ( V_16 -> V_343 == V_344 ) {
F_89 ( V_3 , false ) ;
F_168 ( V_3 , V_75 , false ) ;
F_90 ( V_3 , F_134 ( V_75 ) , 0 , 4 , 4 ) ;
F_168 ( V_3 , V_75 , true ) ;
F_89 ( V_3 , true ) ;
}
F_213 ( V_495 ) ;
F_211 ( V_3 , V_495 ) ;
}
static void F_214 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_494 * V_495 = V_16 -> V_496 . V_497 ;
unsigned V_506 ;
unsigned V_507 ;
unsigned V_508 ;
unsigned V_509 ;
unsigned V_510 ;
unsigned V_511 ;
T_1 V_167 ;
int V_155 ;
const unsigned V_75 = V_16 -> V_360 ;
const unsigned V_512 = V_16 -> V_425 ;
T_13 V_409 = V_16 -> V_424 . V_426 ;
T_13 V_513 = V_16 -> V_424 . V_483 ;
F_71 ( L_148 , V_409 , V_513 ) ;
F_170 ( V_3 , V_75 , V_365 ) ;
V_506 = F_25 ( V_16 -> V_422 ) / 8 ;
V_507 = V_409 * V_506 ;
V_508 = V_507 * V_513 ;
if ( V_508 < V_512 )
V_510 = V_508 ;
else
V_510 = ( V_512 ) / V_507 * V_507 ;
V_511 = V_510 + 1 ;
V_509 = ( V_508 / V_510 ) * V_511 ;
if ( V_508 % V_510 )
V_509 += ( V_508 % V_510 ) + 1 ;
V_167 = F_156 ( V_509 , 23 , 0 ) ;
F_7 ( V_3 , F_135 ( V_75 ) , V_167 ) ;
F_178 ( V_3 , V_75 , V_396 ,
V_511 , 0 ) ;
if ( V_16 -> V_362 )
V_167 = F_118 ( V_167 , 1 , 30 , 30 ) ;
else
V_167 = F_118 ( V_167 , 1 , 31 , 31 ) ;
F_7 ( V_3 , F_135 ( V_75 ) , V_167 ) ;
F_215 () ;
F_29 ( V_3 ) ;
V_155 = F_216 ( & V_16 -> V_514 ,
F_20 ( 250 ) ) ;
F_61 ( V_155 == 0 ) ;
F_217 ( V_495 , & V_16 -> V_424 ) ;
F_218 ( V_495 ) ;
if ( V_16 -> V_362 ) {
F_90 ( V_3 , V_278 , 0 , 15 , 15 ) ;
F_176 ( V_3 , V_75 ) ;
#ifdef F_50
F_219 ( & V_16 -> V_141 , V_34 + F_20 ( 250 ) ) ;
#endif
}
}
static void F_220 ( unsigned long V_127 )
{
F_44 ( L_149 ) ;
}
static void F_221 ( struct V_2 * V_3 , int error )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_222 () ;
if ( V_16 -> V_362 ) {
F_90 ( V_3 , V_278 , 1 , 15 , 15 ) ;
}
V_16 -> V_515 ( error , V_16 -> V_516 ) ;
if ( ! error )
F_30 ( V_3 , L_150 ) ;
}
static void F_223 ( struct V_517 * V_518 )
{
struct V_1 * V_16 = F_224 ( V_518 , struct V_1 ,
V_514 . V_518 ) ;
F_44 ( L_151 ) ;
F_221 ( V_16 -> V_157 , - V_519 ) ;
}
static void F_225 ( void * V_26 )
{
struct V_2 * V_3 = (struct V_2 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_226 ( & V_16 -> V_514 ) ;
F_221 ( V_3 , 0 ) ;
}
static int F_227 ( struct V_5 * V_6 , int V_75 ,
void (* F_228)( int , void * ) , void * V_26 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_13 V_520 , V_521 ;
F_27 ( V_3 ) ;
V_16 -> V_360 = V_75 ;
V_16 -> V_515 = F_228 ;
V_16 -> V_516 = V_26 ;
V_520 = V_16 -> V_424 . V_426 ;
V_521 = V_16 -> V_424 . V_483 ;
#ifdef F_229
V_16 -> V_53 = V_520 * V_521 *
F_25 ( V_16 -> V_422 ) / 8 ;
#endif
F_214 ( V_3 ) ;
return 0 ;
}
static int F_230 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_522 V_523 ;
int V_155 ;
unsigned long V_417 ;
V_417 = F_91 ( V_3 ) ;
V_523 . V_524 = V_16 -> V_525 . V_524 ;
V_523 . V_526 = V_16 -> V_525 . V_526 ;
V_155 = F_231 ( V_417 , & V_523 ) ;
if ( V_155 ) {
F_44 ( L_152 ) ;
return V_155 ;
}
V_16 -> V_527 . V_528 = V_523 ;
return 0 ;
}
static int F_209 ( struct V_2 * V_3 ,
struct V_494 * V_495 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
F_232 ( V_495 -> V_10 , V_16 -> V_182 == 0 ?
V_238 :
V_267 ) ;
if ( V_16 -> V_343 == V_529 ) {
V_155 = F_233 ( V_495 ,
F_225 , V_3 ) ;
if ( V_155 ) {
F_44 ( L_153 ) ;
goto V_251;
}
V_16 -> V_527 . V_530 = true ;
V_16 -> V_527 . V_531 = true ;
} else {
V_16 -> V_527 . V_530 = false ;
V_16 -> V_527 . V_531 = false ;
}
V_16 -> V_424 . V_532 = false ;
V_16 -> V_424 . V_533 = V_534 ;
V_16 -> V_424 . V_535 = V_534 ;
V_16 -> V_424 . V_536 = V_537 ;
V_16 -> V_424 . V_538 = V_534 ;
V_16 -> V_424 . V_539 = V_540 ;
F_217 ( V_495 , & V_16 -> V_424 ) ;
V_155 = F_230 ( V_3 ) ;
if ( V_155 )
goto V_257;
V_16 -> V_527 . V_541 = V_542 ;
V_16 -> V_527 . V_543 =
F_25 ( V_16 -> V_422 ) ;
V_16 -> V_527 . V_544 = 0 ;
F_234 ( V_495 , & V_16 -> V_527 ) ;
return 0 ;
V_257:
if ( V_16 -> V_343 == V_529 )
F_235 ( V_495 ,
F_225 , V_3 ) ;
V_251:
F_232 ( V_495 -> V_10 , V_183 ) ;
return V_155 ;
}
static void F_211 ( struct V_2 * V_3 ,
struct V_494 * V_495 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_343 == V_529 )
F_235 ( V_495 ,
F_225 , V_3 ) ;
F_232 ( V_495 -> V_10 , V_183 ) ;
}
static int F_236 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_185 V_186 ;
int V_155 ;
V_186 = V_16 -> V_192 ;
V_155 = F_112 ( V_3 , & V_186 ) ;
if ( V_155 ) {
F_44 ( L_154 ) ;
return V_155 ;
}
V_155 = F_114 ( V_3 , & V_186 ) ;
if ( V_155 ) {
F_44 ( L_155 ) ;
return V_155 ;
}
return 0 ;
}
static int F_237 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 ;
V_155 = F_119 ( V_3 , true , true ) ;
if ( V_155 )
goto V_256;
V_155 = F_236 ( V_3 ) ;
if ( V_155 )
goto V_257;
F_238 ( V_16 -> V_182 , V_16 -> V_182 == 0 ?
V_239 :
V_268 ) ;
F_71 ( L_156 ) ;
V_155 = F_151 ( V_3 ) ;
if ( V_155 )
goto V_378;
F_86 ( V_3 ) ;
F_206 ( V_3 ) ;
F_99 ( V_3 ) ;
if ( 1 )
F_86 ( V_3 ) ;
V_155 = F_205 ( V_3 ) ;
if ( V_155 )
goto V_545;
F_168 ( V_3 , 0 , 1 ) ;
F_168 ( V_3 , 1 , 1 ) ;
F_168 ( V_3 , 2 , 1 ) ;
F_168 ( V_3 , 3 , 1 ) ;
F_89 ( V_3 , 1 ) ;
F_158 ( V_3 ) ;
return 0 ;
V_545:
F_154 ( V_3 ) ;
V_378:
F_238 ( V_16 -> V_182 , V_183 ) ;
V_257:
F_123 ( V_3 , true ) ;
V_256:
return V_155 ;
}
static void F_239 ( struct V_2 * V_3 ,
bool V_260 , bool V_546 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_546 && ! V_16 -> V_338 )
F_194 ( V_3 ) ;
F_89 ( V_3 , 0 ) ;
F_168 ( V_3 , 0 , 0 ) ;
F_168 ( V_3 , 1 , 0 ) ;
F_168 ( V_3 , 2 , 0 ) ;
F_168 ( V_3 , 3 , 0 ) ;
F_238 ( V_16 -> V_182 , V_183 ) ;
F_154 ( V_3 ) ;
F_123 ( V_3 , V_260 ) ;
}
static int F_240 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_155 = 0 ;
F_71 ( L_157 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_241 ( & V_16 -> V_547 ) ;
V_155 = F_70 ( V_3 ) ;
if ( V_155 )
goto V_548;
F_83 ( V_3 , 1 ) ;
F_57 ( V_3 ) ;
V_155 = F_237 ( V_3 ) ;
if ( V_155 )
goto V_549;
F_242 ( & V_16 -> V_547 ) ;
return 0 ;
V_549:
F_83 ( V_3 , 0 ) ;
F_74 ( V_3 ) ;
V_548:
F_242 ( & V_16 -> V_547 ) ;
F_71 ( L_158 ) ;
return V_155 ;
}
static void F_243 ( struct V_5 * V_6 ,
bool V_260 , bool V_546 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_159 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_241 ( & V_16 -> V_547 ) ;
F_166 ( V_3 , 0 ) ;
F_166 ( V_3 , 1 ) ;
F_166 ( V_3 , 2 ) ;
F_166 ( V_3 , 3 ) ;
F_239 ( V_3 , V_260 , V_546 ) ;
F_74 ( V_3 ) ;
F_83 ( V_3 , 0 ) ;
F_242 ( & V_16 -> V_547 ) ;
}
static int F_244 ( struct V_5 * V_6 , bool V_163 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_362 = V_163 ;
return 0 ;
}
static void F_245 ( const char * V_550 ,
const struct V_551 * V_33 )
{
unsigned long V_552 = V_33 -> V_553 / 4 ;
int V_554 , V_555 , V_556 , V_557 ;
V_555 = F_98 ( V_33 -> V_558 * V_33 -> V_559 , 8 ) ;
V_556 = F_98 ( V_555 + 6 , V_33 -> V_459 ) ;
V_554 = V_33 -> V_560 + V_33 -> V_450 + V_33 -> V_561 + V_33 -> V_452 + V_33 -> V_451 ;
V_557 = V_554 + V_556 ;
#define F_246 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, byteclk))
F_36 ( L_160
L_161 ,
V_550 ,
V_552 ,
V_33 -> V_560 , V_33 -> V_450 , V_33 -> V_561 , V_33 -> V_452 , V_556 , V_33 -> V_451 ,
V_554 , V_556 , V_557 ,
F_246 ( V_33 -> V_560 ) ,
F_246 ( V_33 -> V_450 ) ,
F_246 ( V_33 -> V_561 ) ,
F_246 ( V_33 -> V_452 ) ,
F_246 ( V_556 ) ,
F_246 ( V_33 -> V_451 ) ,
F_246 ( V_554 ) ,
F_246 ( V_556 ) ,
F_246 ( V_557 ) ) ;
#undef F_246
}
static void F_247 ( const char * V_550 , const struct V_423 * V_33 )
{
unsigned long V_562 = V_33 -> V_563 ;
int V_558 , V_554 , V_557 ;
V_558 = V_33 -> V_426 ;
V_554 = V_33 -> V_564 + V_33 -> V_452 + V_33 -> V_451 ;
V_557 = V_558 + V_554 ;
#define F_248 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, pck))
F_36 ( L_162
L_163 ,
V_550 ,
V_562 ,
V_33 -> V_564 , V_33 -> V_452 , V_558 , V_33 -> V_451 ,
V_554 , V_558 , V_557 ,
F_248 ( V_33 -> V_564 ) ,
F_248 ( V_33 -> V_452 ) ,
F_248 ( V_558 ) ,
F_248 ( V_33 -> V_451 ) ,
F_248 ( V_554 ) ,
F_248 ( V_558 ) ,
F_248 ( V_557 ) ) ;
#undef F_248
}
static void F_249 ( const char * V_550 ,
const struct V_551 * V_33 )
{
struct V_423 V_565 = { 0 } ;
unsigned long V_552 = V_33 -> V_553 / 4 ;
unsigned long V_562 ;
T_14 V_566 ;
int V_567 , V_568 ;
V_566 = ( T_14 ) V_552 * V_33 -> V_459 * 8 ;
V_562 = ( T_1 ) F_250 ( V_566 , V_33 -> V_559 ) ;
V_567 = F_98 ( F_98 ( V_33 -> V_558 * V_33 -> V_559 , 8 ) + 6 , V_33 -> V_459 ) ;
V_568 = V_33 -> V_560 + V_33 -> V_450 + V_33 -> V_561 + V_33 -> V_452 + V_567 + V_33 -> V_451 ;
V_565 . V_563 = V_562 ;
V_565 . V_564 = F_250 ( ( T_14 ) ( V_33 -> V_450 + V_33 -> V_561 ) * V_562 , V_552 ) ;
V_565 . V_452 = F_250 ( ( T_14 ) V_33 -> V_452 * V_562 , V_552 ) ;
V_565 . V_451 = F_250 ( ( T_14 ) V_33 -> V_451 * V_562 , V_552 ) ;
V_565 . V_426 = V_33 -> V_558 ;
F_247 ( V_550 , & V_565 ) ;
}
static bool F_251 ( int V_569 , int V_570 , unsigned long V_571 ,
unsigned long V_562 , void * V_26 )
{
struct V_572 * V_573 = V_26 ;
struct V_423 * V_33 = & V_573 -> V_574 ;
V_573 -> V_523 . V_524 = V_569 ;
V_573 -> V_523 . V_526 = V_570 ;
V_573 -> V_523 . V_571 = V_571 ;
V_573 -> V_523 . V_562 = V_562 ;
* V_33 = * V_573 -> V_575 -> V_424 ;
V_33 -> V_563 = V_562 ;
V_33 -> V_426 = V_573 -> V_575 -> V_424 -> V_426 ;
V_33 -> V_483 = V_573 -> V_575 -> V_424 -> V_483 ;
V_33 -> V_564 = V_33 -> V_451 = V_33 -> V_452 = V_33 -> V_576 = 1 ;
V_33 -> V_477 = V_33 -> V_478 = 0 ;
return true ;
}
static bool F_252 ( int V_226 , unsigned long V_577 ,
void * V_26 )
{
struct V_572 * V_573 = V_26 ;
V_573 -> V_578 . V_226 = V_226 ;
V_573 -> V_578 . V_179 = V_577 ;
return F_253 ( V_577 , V_573 -> V_579 , V_573 -> V_580 ,
F_251 , V_573 ) ;
}
static bool F_254 ( int V_214 , int V_205 , unsigned long V_217 ,
unsigned long V_202 , void * V_26 )
{
struct V_572 * V_573 = V_26 ;
V_573 -> V_578 . V_214 = V_214 ;
V_573 -> V_578 . V_205 = V_205 ;
V_573 -> V_578 . V_217 = V_217 ;
V_573 -> V_578 . V_181 = V_202 ;
return F_106 ( V_573 -> V_3 , V_202 , V_573 -> V_579 ,
F_252 , V_573 ) ;
}
static bool F_255 ( struct V_1 * V_16 ,
const struct V_581 * V_582 ,
struct V_572 * V_573 )
{
unsigned long V_211 ;
int V_559 , V_459 ;
unsigned long V_212 , V_213 ;
unsigned long V_562 , V_583 ;
V_211 = F_96 ( V_16 -> V_164 ) ;
V_559 = F_25 ( V_582 -> V_584 ) ;
V_459 = V_16 -> V_307 - 1 ;
V_562 = V_582 -> V_424 -> V_563 ;
V_562 = V_562 * 3 / 2 ;
V_583 = V_562 * V_559 / 8 / V_459 ;
memset ( V_573 , 0 , sizeof( * V_573 ) ) ;
V_573 -> V_3 = V_16 -> V_157 ;
V_573 -> V_575 = V_582 ;
V_573 -> V_579 = V_562 ;
V_573 -> V_585 = V_562 ;
V_573 -> V_580 = V_562 * 3 / 2 ;
V_573 -> V_578 . V_211 = V_211 ;
V_212 = F_108 ( V_582 -> V_586 * 4 , V_583 * 4 * 4 ) ;
V_213 = V_582 -> V_587 * 4 ;
return F_110 ( V_16 -> V_157 , V_211 ,
V_212 , V_213 ,
F_254 , V_573 ) ;
}
static bool F_256 ( struct V_572 * V_573 )
{
struct V_1 * V_16 = F_1 ( V_573 -> V_3 ) ;
const struct V_581 * V_582 = V_573 -> V_575 ;
int V_559 = F_25 ( V_582 -> V_584 ) ;
int V_459 = V_16 -> V_307 - 1 ;
unsigned long V_553 = V_573 -> V_578 . V_181 / 4 ;
unsigned long V_552 = V_553 / 4 ;
unsigned long V_588 , V_579 , V_585 , V_580 ;
int V_589 ;
int V_590 , V_591 ;
int V_592 , V_593 ;
int V_568 , V_567 , V_594 , V_560 , V_561 ;
int V_451 , V_450 , V_452 ;
const struct V_423 * V_595 ;
struct V_423 * V_574 ;
struct V_551 * V_596 ;
T_14 V_566 , V_597 ;
V_566 = ( T_14 ) V_552 * V_459 * 8 ;
V_595 = V_582 -> V_424 ;
V_579 = V_573 -> V_579 ;
V_580 = V_573 -> V_580 ;
V_585 = V_573 -> V_585 ;
V_588 = V_573 -> V_523 . V_562 ;
V_597 = ( T_14 ) V_588 * V_559 ;
V_589 = V_595 -> V_426 ;
V_591 = V_595 -> V_451 + V_595 -> V_452 + V_595 -> V_564 ;
V_590 = V_589 + V_591 ;
V_567 = F_98 ( F_98 ( V_589 * V_559 , 8 ) + 6 , V_459 ) ;
if ( V_16 -> V_425 < V_589 * V_559 / 8 ) {
if ( V_597 != V_566 )
return false ;
} else {
if ( V_597 < V_566 )
return false ;
}
if ( V_566 < ( T_14 ) V_559 * V_579 )
return false ;
if ( V_582 -> V_428 != V_598 ) {
if ( V_566 > ( T_14 ) V_559 * V_580 )
return false ;
}
V_560 = F_98 ( 4 , V_459 ) ;
if ( V_582 -> V_428 == V_429 ) {
if ( V_459 == 3 && V_595 -> V_564 == 0 )
V_561 = 1 ;
else
V_561 = F_98 ( 4 , V_459 ) ;
} else {
V_561 = 0 ;
}
V_568 = F_250 ( ( T_14 ) V_590 * V_552 , V_585 ) ;
if ( V_568 < V_560 + V_561 + V_567 )
return false ;
V_594 = V_568 - V_567 ;
V_592 = F_250 ( ( T_14 ) V_568 * V_588 , V_552 ) ;
if ( ( T_14 ) V_568 * V_588 != ( T_14 ) V_592 * V_552 )
return false ;
V_593 = V_592 - V_589 ;
V_596 = & V_573 -> V_596 ;
memset ( V_596 , 0 , sizeof( * V_596 ) ) ;
V_596 -> V_553 = V_553 ;
V_596 -> V_459 = V_459 ;
V_596 -> V_559 = V_559 ;
if ( V_582 -> V_428 != V_429 ) {
V_450 = 0 ;
} else if ( V_459 == 3 && V_595 -> V_564 == 0 ) {
V_450 = 0 ;
} else {
V_450 = F_250 ( ( T_14 ) V_595 -> V_564 * V_552 , V_585 ) ;
V_450 = F_108 ( V_450 - V_561 , 1 ) ;
}
V_452 = F_250 ( ( T_14 ) V_595 -> V_452 * V_552 , V_585 ) ;
V_452 = F_108 ( V_452 , 1 ) ;
V_451 = V_594 - ( V_560 + V_450 + V_561 + V_452 ) ;
if ( V_451 < 1 ) {
int V_33 ;
V_33 = 1 - V_451 ;
V_452 = F_108 ( V_452 - V_33 , 1 ) ;
V_451 = V_594 - ( V_560 + V_450 + V_561 + V_452 ) ;
if ( V_451 < 1 && V_450 > 0 ) {
V_33 = 1 - V_451 ;
V_450 = F_108 ( V_450 - V_33 , 1 ) ;
V_451 = V_594 - ( V_560 + V_450 + V_561 + V_452 ) ;
}
}
if ( V_451 < 1 )
return false ;
V_596 -> V_560 = V_560 ;
V_596 -> V_450 = V_450 ;
V_596 -> V_561 = V_561 ;
V_596 -> V_452 = V_452 ;
V_596 -> V_558 = V_589 ;
V_596 -> V_451 = V_451 ;
V_596 -> V_476 = V_595 -> V_576 ;
V_596 -> V_478 = V_595 -> V_478 ;
V_596 -> V_599 = V_595 -> V_483 ;
V_596 -> V_477 = V_595 -> V_477 ;
V_596 -> V_428 = V_582 -> V_428 ;
V_596 -> V_430 = 0 ;
V_596 -> V_433 = 1 ;
V_596 -> V_431 = 1 ;
V_596 -> V_432 = 1 ;
V_596 -> V_346 = V_582 -> V_346 ;
V_596 -> V_479 = 4 ;
V_574 = & V_573 -> V_574 ;
* V_574 = * V_595 ;
V_574 -> V_563 = V_588 ;
if ( V_582 -> V_428 == V_429 ) {
V_450 = F_250 ( ( T_14 ) V_595 -> V_564 * V_588 ,
V_585 ) ;
V_450 = F_108 ( V_450 , 1 ) ;
} else {
V_450 = 1 ;
}
V_452 = F_250 ( ( T_14 ) V_595 -> V_452 * V_588 , V_585 ) ;
V_452 = F_108 ( V_452 , 1 ) ;
V_451 = V_593 - V_450 - V_452 ;
if ( V_451 < 1 ) {
int V_33 ;
V_33 = 1 - V_451 ;
V_452 = F_108 ( V_452 - V_33 , 1 ) ;
V_451 = V_593 - V_450 - V_452 ;
if ( V_451 < 1 ) {
V_33 = 1 - V_451 ;
V_450 = F_108 ( V_450 - V_33 , 1 ) ;
V_451 = V_593 - V_450 - V_452 ;
}
}
if ( V_451 < 1 )
return false ;
V_574 -> V_451 = V_451 ;
V_574 -> V_564 = V_450 ;
V_574 -> V_452 = V_452 ;
return true ;
}
static bool F_257 ( int V_569 , int V_570 , unsigned long V_571 ,
unsigned long V_562 , void * V_26 )
{
struct V_572 * V_573 = V_26 ;
V_573 -> V_523 . V_524 = V_569 ;
V_573 -> V_523 . V_526 = V_570 ;
V_573 -> V_523 . V_571 = V_571 ;
V_573 -> V_523 . V_562 = V_562 ;
if ( F_256 ( V_573 ) == false )
return false ;
#ifdef F_258
F_247 ( L_164 , & V_573 -> V_574 ) ;
F_245 ( L_165 , & V_573 -> V_596 ) ;
F_247 ( L_166 , V_573 -> V_575 -> V_424 ) ;
F_249 ( L_167 , & V_573 -> V_596 ) ;
#endif
return true ;
}
static bool F_259 ( int V_226 , unsigned long V_577 ,
void * V_26 )
{
struct V_572 * V_573 = V_26 ;
unsigned long V_600 ;
V_573 -> V_578 . V_226 = V_226 ;
V_573 -> V_578 . V_179 = V_577 ;
if ( V_573 -> V_575 -> V_428 == V_598 )
V_600 = V_573 -> V_580 + 10000000 ;
else
V_600 = V_573 -> V_580 ;
return F_253 ( V_577 , V_573 -> V_579 , V_600 ,
F_257 , V_573 ) ;
}
static bool F_260 ( int V_214 , int V_205 , unsigned long V_217 ,
unsigned long V_202 , void * V_26 )
{
struct V_572 * V_573 = V_26 ;
V_573 -> V_578 . V_214 = V_214 ;
V_573 -> V_578 . V_205 = V_205 ;
V_573 -> V_578 . V_217 = V_217 ;
V_573 -> V_578 . V_181 = V_202 ;
return F_106 ( V_573 -> V_3 , V_202 , V_573 -> V_579 ,
F_259 , V_573 ) ;
}
static bool F_261 ( struct V_1 * V_16 ,
const struct V_581 * V_582 ,
struct V_572 * V_573 )
{
const struct V_423 * V_33 = V_582 -> V_424 ;
unsigned long V_211 ;
unsigned long V_212 ;
unsigned long V_213 ;
int V_459 = V_16 -> V_307 - 1 ;
int V_559 = F_25 ( V_582 -> V_584 ) ;
unsigned long V_601 ;
V_211 = F_96 ( V_16 -> V_164 ) ;
memset ( V_573 , 0 , sizeof( * V_573 ) ) ;
V_573 -> V_3 = V_16 -> V_157 ;
V_573 -> V_575 = V_582 ;
V_573 -> V_578 . V_211 = V_211 ;
V_573 -> V_579 = V_33 -> V_563 - 1000 ;
V_573 -> V_585 = V_33 -> V_563 ;
V_573 -> V_580 = V_33 -> V_563 + 1000 ;
V_601 = F_250 ( ( T_14 ) V_573 -> V_579 * V_559 , V_459 * 8 ) ;
V_212 = F_108 ( V_582 -> V_586 * 4 , V_601 * 4 * 4 ) ;
if ( V_582 -> V_428 == V_598 ) {
V_213 = V_582 -> V_587 * 4 ;
} else {
unsigned long V_602 ;
V_602 = F_250 ( ( T_14 ) V_573 -> V_580 * V_559 ,
V_459 * 8 ) ;
V_213 = V_602 * 4 * 4 ;
}
return F_110 ( V_16 -> V_157 , V_211 ,
V_212 , V_213 ,
F_260 , V_573 ) ;
}
static int F_262 ( struct V_5 * V_6 ,
const struct V_581 * V_575 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_572 V_573 ;
bool V_336 ;
int V_155 ;
F_241 ( & V_16 -> V_547 ) ;
V_16 -> V_422 = V_575 -> V_584 ;
V_16 -> V_343 = V_575 -> V_343 ;
if ( V_575 -> V_343 == V_344 )
V_336 = F_261 ( V_16 , V_575 , & V_573 ) ;
else
V_336 = F_255 ( V_16 , V_575 , & V_573 ) ;
if ( ! V_336 ) {
F_44 ( L_168 ) ;
V_155 = - V_153 ;
goto V_251;
}
F_113 ( & V_573 . V_578 ) ;
V_155 = F_97 ( & V_573 . V_578 , V_575 -> V_187 ,
V_575 -> V_188 ) ;
if ( V_155 ) {
F_44 ( L_169 ) ;
goto V_251;
}
V_16 -> V_192 = V_573 . V_578 ;
V_16 -> V_525 = V_573 . V_523 ;
V_16 -> V_424 = V_573 . V_574 ;
V_16 -> V_345 = V_573 . V_596 ;
F_242 ( & V_16 -> V_547 ) ;
return 0 ;
V_251:
F_242 ( & V_16 -> V_547 ) ;
return V_155 ;
}
static enum V_603 F_263 ( int V_182 )
{
switch ( F_264 () ) {
case V_604 :
case V_605 :
F_265 ( L_170 ) ;
return V_606 ;
case V_607 :
case V_608 :
case V_609 :
case V_610 :
return V_606 ;
case V_611 :
case V_612 :
case V_613 :
switch ( V_182 ) {
case 0 :
return V_606 ;
case 1 :
return V_614 ;
default:
F_265 ( L_171 ) ;
return V_606 ;
}
case V_615 :
switch ( V_182 ) {
case 0 :
return V_606 ;
case 1 :
return V_616 ;
default:
F_265 ( L_171 ) ;
return V_606 ;
}
default:
F_265 ( L_172 ) ;
return V_606 ;
}
}
static int F_266 ( struct V_5 * V_6 , int * V_75 )
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
F_44 ( L_173 , V_6 -> V_45 ) ;
return - V_617 ;
}
static int F_267 ( struct V_5 * V_6 , int V_75 , int V_383 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_383 < 0 || V_383 > 3 ) {
F_44 ( L_174 ) ;
return - V_153 ;
}
if ( V_75 < 0 || V_75 > 3 ) {
F_44 ( L_175 ) ;
return - V_153 ;
}
if ( V_16 -> V_149 [ V_75 ] . V_6 != V_6 ) {
F_44 ( L_176 ,
V_6 -> V_45 ) ;
return - V_153 ;
}
V_16 -> V_149 [ V_75 ] . V_383 = V_383 ;
return 0 ;
}
static void F_268 ( struct V_5 * V_6 , int V_75 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ( V_75 >= 0 && V_75 <= 3 ) &&
V_16 -> V_149 [ V_75 ] . V_6 == V_6 ) {
V_16 -> V_149 [ V_75 ] . V_6 = NULL ;
V_16 -> V_149 [ V_75 ] . V_383 = 0 ;
}
}
void F_269 ( struct V_2 * V_3 )
{
if ( F_18 ( V_3 , V_166 , 7 , 1 ) != 1 )
F_44 ( L_177 ,
F_115 ( V_238 ) ,
F_116 ( V_238 ) ) ;
}
void F_270 ( struct V_2 * V_3 )
{
if ( F_18 ( V_3 , V_166 , 8 , 1 ) != 1 )
F_44 ( L_177 ,
F_115 ( V_239 ) ,
F_116 ( V_239 ) ) ;
}
static void F_271 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_223 = F_107 ( V_618 ) ;
V_16 -> V_225 = F_107 ( V_619 ) ;
V_16 -> V_210 =
F_107 ( V_620 ) ;
V_16 -> V_228 = F_107 ( V_621 ) ;
V_16 -> V_221 = F_272 ( V_622 ) ;
V_16 -> V_222 = F_107 ( V_622 ) ;
V_16 -> V_193 = F_107 ( V_623 ) ;
}
static int F_273 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_624 * V_624 ;
V_624 = F_274 ( & V_3 -> V_4 , L_178 ) ;
if ( F_78 ( V_624 ) ) {
F_44 ( L_179 ) ;
return F_79 ( V_624 ) ;
}
V_16 -> V_184 = V_624 ;
V_624 = F_274 ( & V_3 -> V_4 , L_180 ) ;
if ( F_78 ( V_624 ) ) {
F_44 ( L_181 ) ;
return F_79 ( V_624 ) ;
}
V_16 -> V_164 = V_624 ;
return 0 ;
}
static int F_275 ( struct V_5 * V_6 ,
struct V_5 * V_625 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_494 * V_495 ;
int V_155 ;
V_155 = F_76 ( V_3 ) ;
if ( V_155 )
return V_155 ;
V_495 = F_276 ( V_6 -> V_626 ) ;
if ( ! V_495 )
return - V_201 ;
V_155 = F_277 ( V_495 , V_6 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_278 ( V_6 , V_625 ) ;
if ( V_155 ) {
F_44 ( L_182 ,
V_6 -> V_45 ) ;
F_279 ( V_495 , V_6 ) ;
return V_155 ;
}
return 0 ;
}
static void F_280 ( struct V_5 * V_6 ,
struct V_5 * V_625 )
{
F_73 ( V_625 != V_6 -> V_625 ) ;
if ( V_625 != V_6 -> V_625 )
return;
F_281 ( V_6 ) ;
if ( V_6 -> V_497 )
F_279 ( V_6 -> V_497 , V_6 ) ;
}
static void F_282 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_496 ;
V_8 -> V_4 = & V_3 -> V_4 ;
V_8 -> V_10 = V_16 -> V_182 == 0 ?
V_11 : V_12 ;
V_8 -> V_627 = V_628 ;
V_8 -> V_45 = V_16 -> V_182 == 0 ? L_183 : L_184 ;
V_8 -> V_626 = F_263 ( V_16 -> V_182 ) ;
V_8 -> V_629 . V_16 = & V_630 ;
V_8 -> V_631 = V_632 ;
F_283 ( V_8 ) ;
}
static void F_284 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_496 ;
F_285 ( V_8 ) ;
}
static int F_286 ( struct V_2 * V_157 )
{
struct V_633 * V_634 = V_157 -> V_4 . V_635 ;
struct V_1 * V_16 = F_1 ( V_157 ) ;
struct V_636 * V_637 ;
T_1 V_638 [ 10 ] ;
int V_380 , V_486 ;
int V_155 , V_109 ;
struct V_633 * V_639 ;
struct V_484 V_485 ;
V_639 = F_287 ( V_634 ) ;
if ( ! V_639 )
return 0 ;
V_637 = F_288 ( V_639 , L_185 , & V_380 ) ;
if ( V_637 == NULL ) {
F_289 ( & V_157 -> V_4 , L_186 ) ;
V_155 = - V_153 ;
goto V_251;
}
V_486 = V_380 / sizeof( T_1 ) ;
if ( V_486 < 4 || V_486 % 2 != 0 ||
V_486 > V_16 -> V_311 * 2 ) {
F_289 ( & V_157 -> V_4 , L_187 ) ;
V_155 = - V_153 ;
goto V_251;
}
V_155 = F_290 ( V_639 , L_185 , V_638 , V_486 ) ;
if ( V_155 ) {
F_289 ( & V_157 -> V_4 , L_188 ) ;
goto V_251;
}
V_485 . V_486 = V_486 ;
for ( V_109 = 0 ; V_109 < V_486 ; ++ V_109 )
V_485 . V_487 [ V_109 ] = ( int ) V_638 [ V_109 ] ;
V_155 = F_207 ( & V_16 -> V_496 , & V_485 ) ;
if ( V_155 ) {
F_289 ( & V_157 -> V_4 , L_189 ) ;
goto V_251;
}
F_291 ( V_639 ) ;
return 0 ;
V_251:
F_291 ( V_639 ) ;
return V_155 ;
}
static int F_292 ( struct V_2 * V_3 )
{
T_1 V_640 ;
int V_155 , V_109 ;
struct V_1 * V_16 ;
struct V_641 * V_642 ;
struct V_641 * V_643 ;
struct V_641 V_644 ;
V_16 = F_293 ( & V_3 -> V_4 , sizeof( * V_16 ) , V_645 ) ;
if ( ! V_16 )
return - V_646 ;
V_16 -> V_157 = V_3 ;
F_294 ( & V_3 -> V_4 , V_16 ) ;
F_295 ( & V_16 -> V_136 ) ;
F_295 ( & V_16 -> V_117 ) ;
V_16 -> V_118 = 0 ;
#ifdef F_296
F_295 ( & V_16 -> V_110 ) ;
V_16 -> V_111 . V_272 = V_34 ;
#endif
F_297 ( & V_16 -> V_547 ) ;
F_298 ( & V_16 -> V_24 , 1 ) ;
F_299 ( & V_16 -> V_514 ,
F_223 ) ;
#ifdef F_50
F_300 ( & V_16 -> V_141 ) ;
V_16 -> V_141 . V_313 = F_220 ;
V_16 -> V_141 . V_26 = 0 ;
#endif
V_643 = F_301 ( V_3 , V_647 , L_190 ) ;
if ( ! V_643 ) {
V_643 = F_302 ( V_3 , V_647 , 0 ) ;
if ( ! V_643 ) {
F_44 ( L_191 ) ;
return - V_153 ;
}
V_644 . T_9 = V_643 -> T_9 ;
V_644 . T_10 = V_644 . T_9 + V_648 - 1 ;
V_643 = & V_644 ;
}
V_642 = V_643 ;
V_16 -> V_19 = F_303 ( & V_3 -> V_4 , V_643 -> T_9 ,
F_304 ( V_643 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_192 ) ;
return - V_646 ;
}
V_643 = F_301 ( V_3 , V_647 , L_193 ) ;
if ( ! V_643 ) {
V_643 = F_302 ( V_3 , V_647 , 0 ) ;
if ( ! V_643 ) {
F_44 ( L_191 ) ;
return - V_153 ;
}
V_644 . T_9 = V_643 -> T_9 + V_649 ;
V_644 . T_10 = V_644 . T_9 + V_650 - 1 ;
V_643 = & V_644 ;
}
V_16 -> V_21 = F_303 ( & V_3 -> V_4 , V_643 -> T_9 ,
F_304 ( V_643 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_194 ) ;
return - V_646 ;
}
V_643 = F_301 ( V_3 , V_647 , L_195 ) ;
if ( ! V_643 ) {
V_643 = F_302 ( V_3 , V_647 , 0 ) ;
if ( ! V_643 ) {
F_44 ( L_191 ) ;
return - V_153 ;
}
V_644 . T_9 = V_643 -> T_9 + V_651 ;
V_644 . T_10 = V_644 . T_9 + V_652 - 1 ;
V_643 = & V_644 ;
}
V_16 -> V_23 = F_303 ( & V_3 -> V_4 , V_643 -> T_9 ,
F_304 ( V_643 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_196 ) ;
return - V_646 ;
}
V_16 -> V_133 = F_305 ( V_16 -> V_157 , 0 ) ;
if ( V_16 -> V_133 < 0 ) {
F_44 ( L_197 ) ;
return - V_201 ;
}
V_155 = F_306 ( & V_3 -> V_4 , V_16 -> V_133 , F_48 ,
V_653 , F_307 ( & V_3 -> V_4 ) , V_16 -> V_157 ) ;
if ( V_155 < 0 ) {
F_44 ( L_198 ) ;
return V_155 ;
}
if ( V_3 -> V_4 . V_635 ) {
const struct V_654 * V_655 ;
const struct V_656 * V_657 ;
V_655 = F_308 ( V_658 , V_3 -> V_4 . V_635 ) ;
if ( ! V_655 ) {
F_44 ( L_199 ) ;
return - V_201 ;
}
V_657 = V_655 -> V_26 ;
while ( V_657 -> V_659 != 0 && V_657 -> V_659 != V_642 -> T_9 )
V_657 ++ ;
if ( V_657 -> V_659 == 0 ) {
F_44 ( L_199 ) ;
return - V_201 ;
}
V_16 -> V_182 = V_657 -> V_10 ;
} else {
V_16 -> V_182 = V_3 -> V_10 ;
}
for ( V_109 = 0 ; V_109 < F_47 ( V_16 -> V_149 ) ; V_109 ++ ) {
V_16 -> V_149 [ V_109 ] . V_364 = V_366 ;
V_16 -> V_149 [ V_109 ] . V_6 = NULL ;
V_16 -> V_149 [ V_109 ] . V_383 = 0 ;
}
F_271 ( V_3 ) ;
V_155 = F_273 ( V_3 ) ;
if ( V_155 )
return V_155 ;
F_309 ( & V_3 -> V_4 ) ;
V_155 = F_70 ( V_3 ) ;
if ( V_155 )
goto V_660;
V_640 = F_9 ( V_3 , V_273 ) ;
F_310 ( & V_3 -> V_4 , L_200 ,
F_103 ( V_640 , 7 , 4 ) , F_103 ( V_640 , 3 , 0 ) ) ;
if ( F_87 ( V_297 ) )
V_16 -> V_311 = 1 + F_19 ( V_3 , V_298 , 11 , 9 ) ;
else
V_16 -> V_311 = 3 ;
V_16 -> V_425 = F_142 ( V_3 ) ;
F_282 ( V_3 ) ;
if ( V_3 -> V_4 . V_635 ) {
V_155 = F_286 ( V_3 ) ;
if ( V_155 ) {
F_44 ( L_201 ) ;
goto V_661;
}
V_155 = F_311 ( V_3 -> V_4 . V_635 , NULL , NULL ,
& V_3 -> V_4 ) ;
if ( V_155 )
F_44 ( L_202 , V_155 ) ;
}
F_74 ( V_3 ) ;
if ( V_16 -> V_182 == 0 )
F_312 ( L_203 , F_139 ) ;
else if ( V_16 -> V_182 == 1 )
F_312 ( L_204 , F_140 ) ;
#ifdef F_296
if ( V_16 -> V_182 == 0 )
F_312 ( L_205 , F_130 ) ;
else if ( V_16 -> V_182 == 1 )
F_312 ( L_206 , F_131 ) ;
#endif
return 0 ;
V_661:
F_284 ( V_3 ) ;
F_74 ( V_3 ) ;
V_660:
F_313 ( & V_3 -> V_4 ) ;
return V_155 ;
}
static int T_15 F_314 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_315 ( & V_3 -> V_4 ) ;
F_73 ( V_16 -> V_195 > 0 ) ;
F_284 ( V_3 ) ;
F_313 ( & V_3 -> V_4 ) ;
if ( V_16 -> V_161 != NULL && V_16 -> V_255 ) {
F_122 ( V_16 -> V_161 ) ;
V_16 -> V_255 = false ;
}
return 0 ;
}
static int F_316 ( struct V_662 * V_4 )
{
struct V_2 * V_157 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_157 ) ;
V_16 -> V_134 = false ;
F_317 () ;
F_318 ( V_16 -> V_133 ) ;
F_319 () ;
return 0 ;
}
static int F_320 ( struct V_662 * V_4 )
{
struct V_2 * V_157 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_157 ) ;
int V_155 ;
V_155 = F_321 () ;
if ( V_155 )
return V_155 ;
V_16 -> V_134 = true ;
F_317 () ;
return 0 ;
}
int T_16 F_322 ( void )
{
return F_323 ( & V_663 ) ;
}
void T_15 F_324 ( void )
{
F_325 ( & V_663 ) ;
}
