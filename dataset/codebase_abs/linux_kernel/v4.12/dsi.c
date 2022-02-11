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
static T_4 F_25 ( enum V_37 V_38 )
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
F_33 ( L_1 ,
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
static void F_34 ( T_1 V_54 )
{
if ( V_54 == 0 )
return;
if ( ! V_55 && ( V_54 & ~ V_56 ) == 0 )
return;
#define F_35 ( T_5 ) (status & DSI_IRQ_##x) ? (#x " ") : ""
F_36 ( L_2 ,
V_54 ,
V_55 ? F_35 ( V_57 ) : L_3 ,
V_55 ? F_35 ( V_58 ) : L_3 ,
V_55 ? F_35 ( V_59 ) : L_3 ,
V_55 ? F_35 ( V_60 ) : L_3 ,
F_35 ( V_61 ) ,
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
F_35 ( V_73 ) ) ;
#undef F_35
}
static void F_37 ( int V_74 , T_1 V_54 )
{
if ( V_54 == 0 )
return;
if ( ! V_55 && ( V_54 & ~ V_75 ) == 0 )
return;
#define F_35 ( T_5 ) (status & DSI_VC_IRQ_##x) ? (#x " ") : ""
F_36 ( L_4 ,
V_74 ,
V_54 ,
F_35 ( V_76 ) ,
F_35 ( V_77 ) ,
F_35 ( V_78 ) ,
V_55 ? F_35 ( V_79 ) : L_3 ,
F_35 ( V_80 ) ,
F_35 ( V_81 ) ,
F_35 ( V_82 ) ,
F_35 ( V_83 ) ,
F_35 ( V_84 ) ) ;
#undef F_35
}
static void F_38 ( T_1 V_54 )
{
if ( V_54 == 0 )
return;
#define F_35 ( T_5 ) (status & DSI_CIO_IRQ_##x) ? (#x " ") : ""
F_36 ( L_5 ,
V_54 ,
F_35 ( V_85 ) ,
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
F_35 ( V_104 ) ) ;
#undef F_35
}
static void F_39 ( struct V_2 * V_3 , T_1 V_105 ,
T_1 * V_106 , T_1 V_107 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_108 ;
F_40 ( & V_16 -> V_109 ) ;
V_16 -> V_110 . V_111 ++ ;
F_41 ( V_105 , V_16 -> V_110 . V_112 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 )
F_41 ( V_106 [ V_108 ] , V_16 -> V_110 . V_113 [ V_108 ] ) ;
F_41 ( V_107 , V_16 -> V_110 . V_114 ) ;
F_42 ( & V_16 -> V_109 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_1 V_105 ,
T_1 * V_106 , T_1 V_107 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_108 ;
if ( V_105 & V_115 ) {
F_44 ( L_6 , V_105 ) ;
F_34 ( V_105 ) ;
F_40 ( & V_16 -> V_116 ) ;
V_16 -> V_117 |= V_105 & V_115 ;
F_42 ( & V_16 -> V_116 ) ;
} else if ( V_118 ) {
F_34 ( V_105 ) ;
}
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
if ( V_106 [ V_108 ] & V_119 ) {
F_44 ( L_7 ,
V_108 , V_106 [ V_108 ] ) ;
F_37 ( V_108 , V_106 [ V_108 ] ) ;
} else if ( V_118 ) {
F_37 ( V_108 , V_106 [ V_108 ] ) ;
}
}
if ( V_107 & V_120 ) {
F_44 ( L_8 , V_107 ) ;
F_38 ( V_107 ) ;
} else if ( V_118 ) {
F_38 ( V_107 ) ;
}
}
static void F_45 ( struct V_121 * V_122 ,
unsigned V_123 , T_1 V_105 )
{
struct V_121 * V_124 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_123 ; V_108 ++ ) {
V_124 = & V_122 [ V_108 ] ;
if ( V_124 -> V_125 && V_124 -> V_27 & V_105 )
V_124 -> V_125 ( V_124 -> V_126 , V_105 ) ;
}
}
static void F_46 ( struct V_127 * V_128 ,
T_1 V_105 , T_1 * V_106 , T_1 V_107 )
{
int V_108 ;
F_45 ( V_128 -> V_129 ,
F_47 ( V_128 -> V_129 ) ,
V_105 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
if ( V_106 [ V_108 ] == 0 )
continue;
F_45 ( V_128 -> V_130 [ V_108 ] ,
F_47 ( V_128 -> V_130 [ V_108 ] ) ,
V_106 [ V_108 ] ) ;
}
if ( V_107 != 0 )
F_45 ( V_128 -> V_131 ,
F_47 ( V_128 -> V_131 ) ,
V_107 ) ;
}
static T_6 F_48 ( int V_132 , void * V_126 )
{
struct V_2 * V_3 ;
struct V_1 * V_16 ;
T_1 V_105 , V_106 [ 4 ] , V_107 ;
int V_108 ;
V_3 = (struct V_2 * ) V_126 ;
V_16 = F_1 ( V_3 ) ;
if ( ! V_16 -> V_133 )
return V_134 ;
F_40 ( & V_16 -> V_135 ) ;
V_105 = F_9 ( V_3 , V_136 ) ;
if ( ! V_105 ) {
F_42 ( & V_16 -> V_135 ) ;
return V_134 ;
}
F_7 ( V_3 , V_136 , V_105 & ~ V_56 ) ;
F_9 ( V_3 , V_136 ) ;
for ( V_108 = 0 ; V_108 < 4 ; ++ V_108 ) {
if ( ( V_105 & ( 1 << V_108 ) ) == 0 ) {
V_106 [ V_108 ] = 0 ;
continue;
}
V_106 [ V_108 ] = F_9 ( V_3 , F_49 ( V_108 ) ) ;
F_7 ( V_3 , F_49 ( V_108 ) , V_106 [ V_108 ] ) ;
F_9 ( V_3 , F_49 ( V_108 ) ) ;
}
if ( V_105 & V_137 ) {
V_107 = F_9 ( V_3 , V_138 ) ;
F_7 ( V_3 , V_138 , V_107 ) ;
F_9 ( V_3 , V_138 ) ;
} else {
V_107 = 0 ;
}
#ifdef F_50
if ( V_105 & V_139 )
F_51 ( & V_16 -> V_140 ) ;
#endif
memcpy ( & V_16 -> V_141 , & V_16 -> V_128 ,
sizeof( V_16 -> V_128 ) ) ;
F_42 ( & V_16 -> V_135 ) ;
F_46 ( & V_16 -> V_141 , V_105 , V_106 , V_107 ) ;
F_43 ( V_3 , V_105 , V_106 , V_107 ) ;
F_39 ( V_3 , V_105 , V_106 , V_107 ) ;
return V_142 ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_121 * V_122 ,
unsigned V_123 , T_1 V_143 ,
const struct V_13 V_144 ,
const struct V_13 V_145 )
{
struct V_121 * V_124 ;
T_1 V_27 ;
T_1 V_146 ;
int V_108 ;
V_27 = V_143 ;
for ( V_108 = 0 ; V_108 < V_123 ; V_108 ++ ) {
V_124 = & V_122 [ V_108 ] ;
if ( V_124 -> V_125 == NULL )
continue;
V_27 |= V_124 -> V_27 ;
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
T_1 V_27 = V_115 ;
#ifdef F_50
V_27 |= V_139 ;
#endif
F_52 ( V_3 , V_16 -> V_128 . V_129 ,
F_47 ( V_16 -> V_128 . V_129 ) , V_27 ,
V_147 , V_136 ) ;
}
static void F_54 ( struct V_2 * V_3 , int V_148 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_128 . V_130 [ V_148 ] ,
F_47 ( V_16 -> V_128 . V_130 [ V_148 ] ) ,
V_119 ,
F_55 ( V_148 ) , F_49 ( V_148 ) ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_128 . V_131 ,
F_47 ( V_16 -> V_128 . V_131 ) ,
V_120 ,
V_149 , V_138 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_148 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
memset ( & V_16 -> V_128 , 0 , sizeof( V_16 -> V_128 ) ) ;
F_53 ( V_3 ) ;
for ( V_148 = 0 ; V_148 < 4 ; ++ V_148 )
F_54 ( V_3 , V_148 ) ;
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
}
static int F_60 ( T_7 V_125 , void * V_126 , T_1 V_27 ,
struct V_121 * V_122 , unsigned V_123 )
{
struct V_121 * V_124 ;
int V_151 ;
int V_108 ;
F_61 ( V_125 == NULL ) ;
V_151 = - 1 ;
for ( V_108 = 0 ; V_108 < V_123 ; V_108 ++ ) {
V_124 = & V_122 [ V_108 ] ;
if ( V_124 -> V_125 == V_125 && V_124 -> V_126 == V_126 &&
V_124 -> V_27 == V_27 ) {
return - V_152 ;
}
if ( V_124 -> V_125 == NULL && V_151 == - 1 )
V_151 = V_108 ;
}
if ( V_151 == - 1 )
return - V_153 ;
V_124 = & V_122 [ V_151 ] ;
V_124 -> V_125 = V_125 ;
V_124 -> V_126 = V_126 ;
V_124 -> V_27 = V_27 ;
return 0 ;
}
static int F_62 ( T_7 V_125 , void * V_126 , T_1 V_27 ,
struct V_121 * V_122 , unsigned V_123 )
{
struct V_121 * V_124 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_123 ; V_108 ++ ) {
V_124 = & V_122 [ V_108 ] ;
if ( V_124 -> V_125 != V_125 || V_124 -> V_126 != V_126 ||
V_124 -> V_27 != V_27 )
continue;
V_124 -> V_125 = NULL ;
V_124 -> V_126 = NULL ;
V_124 -> V_27 = 0 ;
return 0 ;
}
return - V_152 ;
}
static int F_63 ( struct V_2 * V_3 , T_7 V_125 ,
void * V_126 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
V_154 = F_60 ( V_125 , V_126 , V_27 , V_16 -> V_128 . V_129 ,
F_47 ( V_16 -> V_128 . V_129 ) ) ;
if ( V_154 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
return V_154 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_7 V_125 , void * V_126 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
V_154 = F_62 ( V_125 , V_126 , V_27 , V_16 -> V_128 . V_129 ,
F_47 ( V_16 -> V_128 . V_129 ) ) ;
if ( V_154 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
return V_154 ;
}
static int F_65 ( struct V_2 * V_3 , int V_74 ,
T_7 V_125 , void * V_126 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
V_154 = F_60 ( V_125 , V_126 , V_27 ,
V_16 -> V_128 . V_130 [ V_74 ] ,
F_47 ( V_16 -> V_128 . V_130 [ V_74 ] ) ) ;
if ( V_154 == 0 )
F_54 ( V_3 , V_74 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
return V_154 ;
}
static int F_66 ( struct V_2 * V_3 , int V_74 ,
T_7 V_125 , void * V_126 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
V_154 = F_62 ( V_125 , V_126 , V_27 ,
V_16 -> V_128 . V_130 [ V_74 ] ,
F_47 ( V_16 -> V_128 . V_130 [ V_74 ] ) ) ;
if ( V_154 == 0 )
F_54 ( V_3 , V_74 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
return V_154 ;
}
static int F_67 ( struct V_2 * V_3 ,
T_7 V_125 , void * V_126 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
V_154 = F_60 ( V_125 , V_126 , V_27 , V_16 -> V_128 . V_131 ,
F_47 ( V_16 -> V_128 . V_131 ) ) ;
if ( V_154 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
return V_154 ;
}
static int F_68 ( struct V_2 * V_3 ,
T_7 V_125 , void * V_126 , T_1 V_27 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
int V_154 ;
F_58 ( & V_16 -> V_135 , V_150 ) ;
V_154 = F_62 ( V_125 , V_126 , V_27 , V_16 -> V_128 . V_131 ,
F_47 ( V_16 -> V_128 . V_131 ) ) ;
if ( V_154 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_135 , V_150 ) ;
return V_154 ;
}
static T_1 F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
T_1 V_155 ;
F_58 ( & V_16 -> V_116 , V_150 ) ;
V_155 = V_16 -> V_117 ;
V_16 -> V_117 = 0 ;
F_59 ( & V_16 -> V_116 , V_150 ) ;
return V_155 ;
}
static int F_70 ( struct V_2 * V_3 )
{
int V_154 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_9 ) ;
V_154 = F_72 ( & V_16 -> V_156 -> V_4 ) ;
F_73 ( V_154 < 0 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
F_71 ( L_10 ) ;
V_154 = F_75 ( & V_16 -> V_156 -> V_4 ) ;
F_73 ( V_154 < 0 && V_154 != - V_157 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_158 * V_159 ;
if ( V_16 -> V_160 != NULL )
return 0 ;
V_159 = F_77 ( & V_16 -> V_156 -> V_4 , L_11 ) ;
if ( F_78 ( V_159 ) ) {
if ( F_79 ( V_159 ) != - V_161 )
F_44 ( L_12 ) ;
return F_79 ( V_159 ) ;
}
V_16 -> V_160 = V_159 ;
return 0 ;
}
static void F_80 ( struct V_2 * V_3 )
{
T_1 V_162 ;
int V_163 , V_164 , V_165 ;
V_162 = F_9 ( V_3 , V_166 ) ;
if ( F_81 ( V_167 ) ) {
V_163 = 28 ;
V_164 = 27 ;
V_165 = 26 ;
} else {
V_163 = 24 ;
V_164 = 25 ;
V_165 = 26 ;
}
#define F_82 ( T_8 , T_9 , T_10 ) \
FLD_GET(dsi_read_reg(dsidev, DSI_##fld), start, end)
F_36 ( L_13 ,
F_82 ( V_168 , 0 , 0 ) ,
F_82 ( V_169 , 29 , 29 ) ,
F_82 ( V_170 , V_163 , V_163 ) ,
F_82 ( V_170 , V_164 , V_164 ) ,
F_82 ( V_170 , V_165 , V_165 ) ,
F_82 ( V_170 , 29 , 29 ) ,
F_82 ( V_170 , 30 , 30 ) ,
F_82 ( V_170 , 31 , 31 ) ) ;
#undef F_82
}
static inline int F_83 ( struct V_2 * V_3 , bool V_171 )
{
F_71 ( L_14 , V_171 ) ;
V_171 = V_171 ? 1 : 0 ;
F_84 ( V_3 , V_172 , V_171 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_172 , 0 , V_171 ) != V_171 ) {
F_44 ( L_15 , V_171 ) ;
return - V_173 ;
}
return 0 ;
}
static unsigned long F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_174 . V_175 . V_176 [ V_177 ] ;
}
static unsigned long F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_174 . V_175 . V_176 [ V_178 ] ;
}
static unsigned long F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_174 . V_175 . V_179 / 16 ;
}
static unsigned long F_88 ( struct V_2 * V_3 )
{
unsigned long V_154 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( F_89 ( V_16 -> V_180 ) == V_181 ) {
V_154 = F_90 ( V_16 -> V_182 ) ;
} else {
V_154 = F_86 ( V_3 ) ;
}
return V_154 ;
}
static int F_91 ( unsigned long V_183 ,
unsigned long V_184 , unsigned long V_185 ,
struct V_186 * V_187 )
{
unsigned V_188 ;
unsigned long V_189 ;
V_188 = F_92 ( V_183 , V_185 * 2 ) ;
V_189 = V_183 / 2 / V_188 ;
if ( V_189 < V_184 || V_189 > V_185 )
return - V_152 ;
V_187 -> V_188 = V_188 ;
V_187 -> V_189 = V_189 ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_183 ;
unsigned V_188 ;
unsigned long V_189 ;
unsigned V_190 = F_94 ( V_191 ) ;
V_188 = V_16 -> V_192 . V_188 ;
if ( V_188 == 0 || V_188 > V_190 )
return - V_152 ;
V_183 = F_88 ( V_3 ) ;
V_189 = V_183 / 2 / V_188 ;
F_71 ( L_16 , V_188 , V_189 ) ;
V_16 -> V_193 . V_189 = V_189 ;
V_16 -> V_193 . V_188 = V_188 ;
F_84 ( V_3 , V_194 , V_188 , 12 , 0 ) ;
F_84 ( V_3 , V_194 , V_183 > 30000000 ? 1 : 0 , 21 , 21 ) ;
return 0 ;
}
static void F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_195 ++ == 0 )
F_84 ( V_3 , V_194 , 1 , 14 , 14 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_195 == 0 ) ;
if ( -- V_16 -> V_195 == 0 )
F_84 ( V_3 , V_194 , 0 , 14 , 14 ) ;
}
static int F_97 ( struct V_2 * V_3 ,
enum V_196 V_197 )
{
int V_33 = 0 ;
if ( F_81 ( V_198 ) &&
V_197 == V_199 )
V_197 = V_200 ;
F_84 ( V_3 , V_194 , V_197 , 31 , 30 ) ;
while ( F_98 ( F_9 ( V_3 , V_194 ) , 29 , 28 ) != V_197 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_17 ,
V_197 ) ;
return - V_201 ;
}
F_99 ( 1 ) ;
}
return 0 ;
}
static void F_100 ( struct V_202 * V_175 )
{
unsigned long V_203 ;
V_203 = F_94 ( V_204 ) ;
V_175 -> V_205 [ V_178 ] = F_92 ( V_175 -> V_179 , V_203 ) ;
V_175 -> V_176 [ V_178 ] = V_175 -> V_179 / V_175 -> V_205 [ V_178 ] ;
}
static int F_101 ( struct V_206 * V_174 )
{
struct V_1 * V_16 = F_102 ( V_174 , struct V_1 , V_174 ) ;
struct V_2 * V_3 = V_16 -> V_156 ;
int V_154 = 0 ;
F_71 ( L_18 ) ;
V_154 = F_76 ( V_3 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_70 ( V_3 ) ;
if ( V_154 )
return V_154 ;
F_95 ( V_3 ) ;
if ( ! V_16 -> V_207 ) {
V_154 = F_103 ( V_16 -> V_160 ) ;
if ( V_154 )
goto V_208;
V_16 -> V_207 = true ;
}
F_104 ( 1 ) ;
if ( F_18 ( V_3 , V_209 , 0 , 1 ) != 1 ) {
F_44 ( L_19 ) ;
V_154 = - V_201 ;
F_104 ( 0 ) ;
goto V_210;
}
F_104 ( 0 ) ;
V_154 = F_97 ( V_3 , V_200 ) ;
if ( V_154 )
goto V_210;
F_71 ( L_20 ) ;
return 0 ;
V_210:
if ( V_16 -> V_207 ) {
F_105 ( V_16 -> V_160 ) ;
V_16 -> V_207 = false ;
}
V_208:
F_96 ( V_3 ) ;
F_74 ( V_3 ) ;
return V_154 ;
}
static void F_106 ( struct V_2 * V_3 , bool V_211 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_97 ( V_3 , V_212 ) ;
if ( V_211 ) {
F_73 ( ! V_16 -> V_207 ) ;
F_105 ( V_16 -> V_160 ) ;
V_16 -> V_207 = false ;
}
F_96 ( V_3 ) ;
F_74 ( V_3 ) ;
F_71 ( L_21 ) ;
}
static void F_107 ( struct V_206 * V_174 )
{
struct V_1 * V_16 = F_102 ( V_174 , struct V_1 , V_174 ) ;
struct V_2 * V_3 = V_16 -> V_156 ;
F_106 ( V_3 , true ) ;
}
static void F_108 ( struct V_2 * V_3 ,
struct V_213 * V_214 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_202 * V_175 = & V_16 -> V_174 . V_175 ;
enum V_215 V_216 , V_217 ;
int V_218 = V_16 -> V_180 ;
struct V_206 * V_174 = & V_16 -> V_174 ;
V_216 = F_109 () ;
V_217 = F_89 ( V_218 ) ;
if ( F_70 ( V_3 ) )
return;
F_110 ( V_214 , L_22 , V_218 + 1 ) ;
F_110 ( V_214 , L_23 , F_90 ( V_174 -> V_219 ) ) ;
F_110 ( V_214 , L_24 , V_175 -> V_220 , V_175 -> V_221 ) ;
F_110 ( V_214 , L_25 ,
V_175 -> V_179 , V_175 -> V_222 ) ;
F_110 ( V_214 , L_26 ,
F_111 ( V_218 == 0 ?
V_223 :
V_224 ) ,
V_175 -> V_176 [ V_177 ] ,
V_175 -> V_205 [ V_177 ] ,
V_216 == V_181 ?
L_27 : L_28 ) ;
F_110 ( V_214 , L_29 ,
F_111 ( V_218 == 0 ?
V_225 :
V_226 ) ,
V_175 -> V_176 [ V_178 ] ,
V_175 -> V_205 [ V_178 ] ,
V_217 == V_181 ?
L_27 : L_28 ) ;
F_110 ( V_214 , L_30 , V_218 + 1 ) ;
F_110 ( V_214 , L_31 ,
F_111 ( V_217 ) ) ;
F_110 ( V_214 , L_32 , F_88 ( V_3 ) ) ;
F_110 ( V_214 , L_33 ,
V_175 -> V_179 / 4 ) ;
F_110 ( V_214 , L_34 , F_87 ( V_3 ) ) ;
F_110 ( V_214 , L_35 , V_16 -> V_193 . V_189 ) ;
F_74 ( V_3 ) ;
}
void F_112 ( struct V_213 * V_214 )
{
struct V_2 * V_3 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_227 ; V_108 ++ ) {
V_3 = F_5 ( V_108 ) ;
if ( V_3 )
F_108 ( V_3 , V_214 ) ;
}
}
static void F_113 ( struct V_2 * V_3 ,
struct V_213 * V_214 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_150 ;
struct V_228 V_229 ;
F_58 ( & V_16 -> V_109 , V_150 ) ;
V_229 = V_16 -> V_110 ;
memset ( & V_16 -> V_110 , 0 , sizeof( V_16 -> V_110 ) ) ;
V_16 -> V_110 . V_230 = V_34 ;
F_59 ( & V_16 -> V_109 , V_150 ) ;
F_110 ( V_214 , L_36 ,
F_114 ( V_34 - V_229 . V_230 ) ) ;
F_110 ( V_214 , L_37 , V_229 . V_111 ) ;
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d\n", #x, stats.dsi_irqs[ffs(DSI_IRQ_##x)-1]);
F_110 ( V_214 , L_38 , V_16 -> V_180 + 1 ) ;
F_35 ( V_57 ) ;
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
#undef F_35
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d %10d %10d %10d\n", #x, \
stats.vc_irqs[0][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[1][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[2][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[3][ffs(DSI_VC_IRQ_##x)-1]);
F_110 ( V_214 , L_39 ) ;
F_35 ( V_76 ) ;
F_35 ( V_77 ) ;
F_35 ( V_79 ) ;
F_35 ( V_81 ) ;
F_35 ( V_82 ) ;
F_35 ( V_80 ) ;
F_35 ( V_78 ) ;
F_35 ( V_83 ) ;
F_35 ( V_84 ) ;
#undef F_35
#define F_35 ( T_5 ) \
seq_printf(s, "%-20s %10d\n", #x, \
stats.cio_irqs[ffs(DSI_CIO_IRQ_##x)-1]);
F_110 ( V_214 , L_40 ) ;
F_35 ( V_85 ) ;
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
#undef F_35
}
static void F_115 ( struct V_213 * V_214 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_113 ( V_3 , V_214 ) ;
}
static void F_116 ( struct V_213 * V_214 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_113 ( V_3 , V_214 ) ;
}
static void F_117 ( struct V_2 * V_3 ,
struct V_213 * V_214 )
{
#define F_118 ( V_154 ) seq_printf(s, "%-35s %08x\n", #r, dsi_read_reg(dsidev, r))
if ( F_70 ( V_3 ) )
return;
F_95 ( V_3 ) ;
F_118 ( V_231 ) ;
F_118 ( V_232 ) ;
F_118 ( V_233 ) ;
F_118 ( V_136 ) ;
F_118 ( V_147 ) ;
F_118 ( V_172 ) ;
F_118 ( V_234 ) ;
F_118 ( V_138 ) ;
F_118 ( V_149 ) ;
F_118 ( V_194 ) ;
F_118 ( V_235 ) ;
F_118 ( V_236 ) ;
F_118 ( V_237 ) ;
F_118 ( V_238 ) ;
F_118 ( V_239 ) ;
F_118 ( V_240 ) ;
F_118 ( V_241 ) ;
F_118 ( V_242 ) ;
F_118 ( V_243 ) ;
F_118 ( V_244 ) ;
F_118 ( V_245 ) ;
F_118 ( V_246 ) ;
F_118 ( V_247 ) ;
F_118 ( V_248 ) ;
F_118 ( V_249 ) ;
F_118 ( V_250 ) ;
F_118 ( F_119 ( 0 ) ) ;
F_118 ( F_120 ( 0 ) ) ;
F_118 ( F_121 ( 0 ) ) ;
F_118 ( F_122 ( 0 ) ) ;
F_118 ( F_123 ( 0 ) ) ;
F_118 ( F_49 ( 0 ) ) ;
F_118 ( F_55 ( 0 ) ) ;
F_118 ( F_119 ( 1 ) ) ;
F_118 ( F_120 ( 1 ) ) ;
F_118 ( F_121 ( 1 ) ) ;
F_118 ( F_122 ( 1 ) ) ;
F_118 ( F_123 ( 1 ) ) ;
F_118 ( F_49 ( 1 ) ) ;
F_118 ( F_55 ( 1 ) ) ;
F_118 ( F_119 ( 2 ) ) ;
F_118 ( F_120 ( 2 ) ) ;
F_118 ( F_121 ( 2 ) ) ;
F_118 ( F_122 ( 2 ) ) ;
F_118 ( F_123 ( 2 ) ) ;
F_118 ( F_49 ( 2 ) ) ;
F_118 ( F_55 ( 2 ) ) ;
F_118 ( F_119 ( 3 ) ) ;
F_118 ( F_120 ( 3 ) ) ;
F_118 ( F_121 ( 3 ) ) ;
F_118 ( F_122 ( 3 ) ) ;
F_118 ( F_123 ( 3 ) ) ;
F_118 ( F_49 ( 3 ) ) ;
F_118 ( F_55 ( 3 ) ) ;
F_118 ( V_251 ) ;
F_118 ( V_252 ) ;
F_118 ( V_253 ) ;
F_118 ( V_166 ) ;
F_118 ( V_254 ) ;
F_118 ( V_209 ) ;
F_118 ( V_255 ) ;
F_118 ( V_256 ) ;
F_118 ( V_257 ) ;
F_96 ( V_3 ) ;
F_74 ( V_3 ) ;
#undef F_118
}
static void F_124 ( struct V_213 * V_214 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_117 ( V_3 , V_214 ) ;
}
static void F_125 ( struct V_213 * V_214 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_117 ( V_3 , V_214 ) ;
}
static int F_126 ( struct V_2 * V_3 ,
enum V_258 V_197 )
{
int V_33 = 0 ;
F_84 ( V_3 , V_234 , V_197 , 28 , 27 ) ;
while ( F_98 ( F_9 ( V_3 , V_234 ) ,
26 , 25 ) != V_197 ) {
if ( ++ V_33 > 1000 ) {
F_44 ( L_41
L_42 , V_197 ) ;
return - V_201 ;
}
F_99 ( 1 ) ;
}
return 0 ;
}
static unsigned F_127 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! F_81 ( V_259 ) )
return 1023 * 3 ;
V_15 = F_19 ( V_3 , V_260 , 14 , 12 ) ;
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
static int F_128 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
static const T_4 V_261 [] = { 0 , 4 , 8 , 12 , 16 } ;
static const enum V_262 V_263 [] = {
V_264 ,
V_265 ,
V_266 ,
V_267 ,
V_268 ,
} ;
T_1 V_154 ;
int V_108 ;
V_154 = F_9 ( V_3 , V_234 ) ;
for ( V_108 = 0 ; V_108 < V_16 -> V_269 ; ++ V_108 ) {
unsigned V_270 = V_261 [ V_108 ] ;
unsigned V_271 , V_272 ;
unsigned V_33 ;
for ( V_33 = 0 ; V_33 < V_16 -> V_273 ; ++ V_33 )
if ( V_16 -> V_274 [ V_33 ] . V_275 == V_263 [ V_108 ] )
break;
if ( V_33 == V_16 -> V_273 )
return - V_152 ;
V_272 = V_33 ;
V_271 = V_16 -> V_274 [ V_33 ] . V_271 ;
V_154 = F_129 ( V_154 , V_272 + 1 , V_270 + 2 , V_270 ) ;
V_154 = F_129 ( V_154 , V_271 , V_270 + 3 , V_270 + 3 ) ;
}
for (; V_108 < V_16 -> V_273 ; ++ V_108 ) {
unsigned V_270 = V_261 [ V_108 ] ;
V_154 = F_129 ( V_154 , 0 , V_270 + 2 , V_270 ) ;
V_154 = F_129 ( V_154 , 0 , V_270 + 3 , V_270 + 3 ) ;
}
F_7 ( V_3 , V_234 , V_154 ) ;
return 0 ;
}
static inline unsigned F_130 ( struct V_2 * V_3 , unsigned V_276 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_277 = V_16 -> V_174 . V_175 . V_179 / 4 ;
return ( V_276 * ( V_277 / 1000 / 1000 ) + 999 ) / 1000 ;
}
static inline unsigned F_131 ( struct V_2 * V_3 , unsigned V_278 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_277 = V_16 -> V_174 . V_175 . V_179 / 4 ;
return V_278 * 1000 * 1000 / ( V_277 / 1000 ) ;
}
static void F_132 ( struct V_2 * V_3 )
{
T_1 V_154 ;
T_1 V_279 , V_280 , V_281 , V_282 ;
T_1 V_283 , V_284 , V_285 ;
T_1 V_286 ;
V_279 = F_130 ( V_3 , 70 ) + 2 ;
V_280 = F_130 ( V_3 , 175 ) + 2 ;
V_281 = F_130 ( V_3 , 60 ) + 5 ;
V_282 = F_130 ( V_3 , 145 ) ;
V_283 = F_130 ( V_3 , 25 ) ;
V_284 = F_130 ( V_3 , 60 ) + 2 ;
V_286 = F_130 ( V_3 , 65 ) ;
V_285 = F_130 ( V_3 , 260 ) ;
F_71 ( L_43 ,
V_279 , F_131 ( V_3 , V_279 ) ,
V_280 , F_131 ( V_3 , V_280 ) ) ;
F_71 ( L_44 ,
V_281 , F_131 ( V_3 , V_281 ) ,
V_282 , F_131 ( V_3 , V_282 ) ) ;
F_71 ( L_45
L_46 ,
V_283 , F_131 ( V_3 , V_283 ) ,
V_284 , F_131 ( V_3 , V_284 ) ,
V_285 , F_131 ( V_3 , V_285 ) ) ;
F_71 ( L_47 ,
V_286 , F_131 ( V_3 , V_286 ) ) ;
V_154 = F_9 ( V_3 , V_251 ) ;
V_154 = F_129 ( V_154 , V_279 , 31 , 24 ) ;
V_154 = F_129 ( V_154 , V_280 , 23 , 16 ) ;
V_154 = F_129 ( V_154 , V_281 , 15 , 8 ) ;
V_154 = F_129 ( V_154 , V_282 , 7 , 0 ) ;
F_7 ( V_3 , V_251 , V_154 ) ;
V_154 = F_9 ( V_3 , V_252 ) ;
V_154 = F_129 ( V_154 , V_283 , 20 , 16 ) ;
V_154 = F_129 ( V_154 , V_284 , 15 , 8 ) ;
V_154 = F_129 ( V_154 , V_285 , 7 , 0 ) ;
if ( F_81 ( V_287 ) ) {
V_154 = F_129 ( V_154 , 0 , 21 , 21 ) ;
V_154 = F_129 ( V_154 , 1 , 22 , 22 ) ;
V_154 = F_129 ( V_154 , 1 , 23 , 23 ) ;
}
F_7 ( V_3 , V_252 , V_154 ) ;
V_154 = F_9 ( V_3 , V_253 ) ;
V_154 = F_129 ( V_154 , V_286 , 7 , 0 ) ;
F_7 ( V_3 , V_253 , V_154 ) ;
}
static void F_133 ( struct V_2 * V_3 ,
unsigned V_288 , unsigned V_289 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_108 ;
T_1 V_162 ;
T_4 V_290 = V_16 -> V_273 == 3 ? 22 : 26 ;
V_162 = 0 ;
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 ) {
unsigned V_291 = V_16 -> V_274 [ V_108 ] . V_271 ;
if ( V_288 & ( 1 << V_108 ) )
V_162 |= 1 << ( V_108 * 2 + ( V_291 ? 0 : 1 ) ) ;
if ( V_289 & ( 1 << V_108 ) )
V_162 |= 1 << ( V_108 * 2 + ( V_291 ? 1 : 0 ) ) ;
}
F_84 ( V_3 , V_292 , V_162 , V_290 , 17 ) ;
F_84 ( V_3 , V_292 , 1 , 27 , 27 ) ;
}
static void F_134 ( struct V_2 * V_3 )
{
F_84 ( V_3 , V_292 , 0 , 27 , 27 ) ;
F_84 ( V_3 , V_292 , 0 , 22 , 17 ) ;
}
static int F_135 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_33 , V_108 ;
bool V_293 [ V_294 ] ;
static const T_4 V_295 [] = { 28 , 27 , 26 } ;
static const T_4 V_296 [] = { 24 , 25 , 26 , 27 , 28 } ;
const T_4 * V_261 ;
if ( F_81 ( V_167 ) )
V_261 = V_295 ;
else
V_261 = V_296 ;
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 )
V_293 [ V_108 ] = V_16 -> V_274 [ V_108 ] . V_275 != V_297 ;
V_33 = 100000 ;
while ( true ) {
T_1 V_162 ;
int V_298 ;
V_162 = F_9 ( V_3 , V_166 ) ;
V_298 = 0 ;
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 ) {
if ( ! V_293 [ V_108 ] || ( V_162 & ( 1 << V_261 [ V_108 ] ) ) )
V_298 ++ ;
}
if ( V_298 == V_16 -> V_273 )
break;
if ( -- V_33 == 0 ) {
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 ) {
if ( ! V_293 [ V_108 ] || ( V_162 & ( 1 << V_261 [ V_108 ] ) ) )
continue;
F_44 ( L_48 \
L_49 , V_108 ) ;
}
return - V_173 ;
}
}
return 0 ;
}
static unsigned F_136 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_27 = 0 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 ) {
if ( V_16 -> V_274 [ V_108 ] . V_275 != V_297 )
V_27 |= 1 << V_108 ;
}
return V_27 ;
}
static int F_137 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
T_1 V_162 ;
F_71 ( L_50 ) ;
V_154 = F_138 ( V_16 -> V_180 , F_136 ( V_3 ) ) ;
if ( V_154 )
return V_154 ;
F_95 ( V_3 ) ;
F_9 ( V_3 , V_166 ) ;
if ( F_18 ( V_3 , V_166 , 30 , 1 ) != 1 ) {
F_44 ( L_51 ) ;
V_154 = - V_173 ;
goto V_299;
}
V_154 = F_128 ( V_3 ) ;
if ( V_154 )
goto V_299;
V_162 = F_9 ( V_3 , V_235 ) ;
V_162 = F_129 ( V_162 , 1 , 15 , 15 ) ;
V_162 = F_129 ( V_162 , 1 , 14 , 14 ) ;
V_162 = F_129 ( V_162 , 1 , 13 , 13 ) ;
V_162 = F_129 ( V_162 , 0x1fff , 12 , 0 ) ;
F_7 ( V_3 , V_235 , V_162 ) ;
if ( V_16 -> V_300 ) {
unsigned V_288 ;
int V_108 ;
F_71 ( L_52 ) ;
V_288 = 0 ;
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 ) {
if ( V_16 -> V_274 [ V_108 ] . V_275 == V_297 )
continue;
V_288 |= 1 << V_108 ;
}
F_133 ( V_3 , V_288 , 0 ) ;
}
V_154 = F_126 ( V_3 , V_301 ) ;
if ( V_154 )
goto V_302;
if ( F_18 ( V_3 , V_234 , 29 , 1 ) != 1 ) {
F_44 ( L_53 ) ;
V_154 = - V_201 ;
goto V_303;
}
F_83 ( V_3 , true ) ;
F_83 ( V_3 , false ) ;
F_84 ( V_3 , V_194 , 1 , 20 , 20 ) ;
V_154 = F_135 ( V_3 ) ;
if ( V_154 )
goto V_304;
if ( V_16 -> V_300 ) {
T_3 V_32 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_35 ) ;
F_24 ( & V_32 , V_36 ) ;
F_134 ( V_3 ) ;
}
F_84 ( V_3 , V_235 , 0 , 15 , 15 ) ;
F_132 ( V_3 ) ;
if ( V_16 -> V_305 == V_306 ) {
F_84 ( V_3 , V_194 ,
V_16 -> V_307 . V_308 , 13 , 13 ) ;
}
V_16 -> V_300 = false ;
F_71 ( L_54 ) ;
return 0 ;
V_304:
F_84 ( V_3 , V_194 , 0 , 20 , 20 ) ;
V_303:
F_126 ( V_3 , V_309 ) ;
V_302:
if ( V_16 -> V_300 )
F_134 ( V_3 ) ;
V_299:
F_96 ( V_3 ) ;
F_139 ( V_16 -> V_180 , F_136 ( V_3 ) ) ;
return V_154 ;
}
static void F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_84 ( V_3 , V_194 , 0 , 13 , 13 ) ;
F_126 ( V_3 , V_309 ) ;
F_96 ( V_3 ) ;
F_139 ( V_16 -> V_180 , F_136 ( V_3 ) ) ;
}
static void F_141 ( struct V_2 * V_3 ,
enum V_310 V_311 , enum V_310 V_312 ,
enum V_310 V_313 , enum V_310 V_314 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 = 0 ;
int V_315 = 0 ;
int V_108 ;
V_16 -> V_148 [ 0 ] . V_316 = V_311 ;
V_16 -> V_148 [ 1 ] . V_316 = V_312 ;
V_16 -> V_148 [ 2 ] . V_316 = V_313 ;
V_16 -> V_148 [ 3 ] . V_316 = V_314 ;
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
T_4 V_317 ;
int V_318 = V_16 -> V_148 [ V_108 ] . V_316 ;
if ( V_315 + V_318 > 4 ) {
F_44 ( L_55 ) ;
F_26 () ;
return;
}
V_317 = F_142 ( V_315 , 2 , 0 ) | F_142 ( V_318 , 7 , 4 ) ;
V_154 |= V_317 << ( 8 * V_108 ) ;
V_315 += V_318 ;
}
F_7 ( V_3 , V_241 , V_154 ) ;
}
static void F_143 ( struct V_2 * V_3 ,
enum V_310 V_311 , enum V_310 V_312 ,
enum V_310 V_313 , enum V_310 V_314 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 = 0 ;
int V_315 = 0 ;
int V_108 ;
V_16 -> V_148 [ 0 ] . V_319 = V_311 ;
V_16 -> V_148 [ 1 ] . V_319 = V_312 ;
V_16 -> V_148 [ 2 ] . V_319 = V_313 ;
V_16 -> V_148 [ 3 ] . V_319 = V_314 ;
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
T_4 V_317 ;
int V_318 = V_16 -> V_148 [ V_108 ] . V_319 ;
if ( V_315 + V_318 > 4 ) {
F_44 ( L_55 ) ;
F_26 () ;
return;
}
V_317 = F_142 ( V_315 , 2 , 0 ) | F_142 ( V_318 , 7 , 4 ) ;
V_154 |= V_317 << ( 8 * V_108 ) ;
V_315 += V_318 ;
}
F_7 ( V_3 , V_242 , V_154 ) ;
}
static int F_144 ( struct V_2 * V_3 )
{
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_235 ) ;
V_154 = F_129 ( V_154 , 1 , 15 , 15 ) ;
F_7 ( V_3 , V_235 , V_154 ) ;
if ( F_18 ( V_3 , V_235 , 15 , 0 ) != 0 ) {
F_44 ( L_56 ) ;
return - V_173 ;
}
return 0 ;
}
static bool F_145 ( struct V_2 * V_3 , int V_74 )
{
return F_19 ( V_3 , F_119 ( V_74 ) , 0 , 0 ) ;
}
static void F_146 ( void * V_26 , T_1 V_27 )
{
struct V_320 * V_321 =
(struct V_320 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_321 -> V_3 ) ;
const int V_74 = V_16 -> V_322 ;
T_4 V_323 = V_16 -> V_324 ? 30 : 31 ;
if ( F_19 ( V_321 -> V_3 , F_120 ( V_74 ) , V_323 , V_323 ) == 0 )
F_17 ( V_321 -> V_28 ) ;
}
static int F_147 ( struct V_2 * V_3 , int V_74 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_148 ( V_28 ) ;
struct V_320 V_321 = {
. V_3 = V_3 ,
. V_28 = & V_28
} ;
int V_154 = 0 ;
T_4 V_323 ;
V_323 = V_16 -> V_324 ? 30 : 31 ;
V_154 = F_65 ( V_3 , V_74 , F_146 ,
& V_321 , V_75 ) ;
if ( V_154 )
goto V_208;
if ( F_19 ( V_3 , F_120 ( V_74 ) , V_323 , V_323 ) ) {
if ( F_149 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_57 ) ;
V_154 = - V_173 ;
goto V_210;
}
}
F_66 ( V_3 , V_74 , F_146 ,
& V_321 , V_75 ) ;
return 0 ;
V_210:
F_66 ( V_3 , V_74 , F_146 ,
& V_321 , V_75 ) ;
V_208:
return V_154 ;
}
static void F_150 ( void * V_26 , T_1 V_27 )
{
struct V_320 * V_325 =
(struct V_320 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_325 -> V_3 ) ;
const int V_74 = V_16 -> V_322 ;
if ( F_19 ( V_325 -> V_3 , F_119 ( V_74 ) , 5 , 5 ) == 0 )
F_17 ( V_325 -> V_28 ) ;
}
static int F_151 ( struct V_2 * V_3 , int V_74 )
{
F_148 ( V_28 ) ;
struct V_320 V_325 = {
. V_3 = V_3 ,
. V_28 = & V_28
} ;
int V_154 = 0 ;
V_154 = F_65 ( V_3 , V_74 , F_150 ,
& V_325 , V_75 ) ;
if ( V_154 )
goto V_208;
if ( F_19 ( V_3 , F_119 ( V_74 ) , 5 , 5 ) ) {
if ( F_149 ( & V_28 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_58 ) ;
V_154 = - V_173 ;
goto V_210;
}
}
F_66 ( V_3 , V_74 , F_150 ,
& V_325 , V_75 ) ;
return 0 ;
V_210:
F_66 ( V_3 , V_74 , F_150 ,
& V_325 , V_75 ) ;
V_208:
return V_154 ;
}
static int F_152 ( struct V_2 * V_3 , int V_74 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( F_153 () ) ;
if ( ! F_145 ( V_3 , V_74 ) )
return 0 ;
switch ( V_16 -> V_148 [ V_74 ] . V_326 ) {
case V_327 :
return F_147 ( V_3 , V_74 ) ;
case V_328 :
return F_151 ( V_3 , V_74 ) ;
default:
F_26 () ;
return - V_152 ;
}
}
static int F_154 ( struct V_2 * V_3 , int V_74 ,
bool V_171 )
{
F_71 ( L_59 ,
V_74 , V_171 ) ;
V_171 = V_171 ? 1 : 0 ;
F_84 ( V_3 , F_119 ( V_74 ) , V_171 , 0 , 0 ) ;
if ( F_18 ( V_3 , F_119 ( V_74 ) ,
0 , V_171 ) != V_171 ) {
F_44 ( L_60 , V_171 ) ;
return - V_173 ;
}
return 0 ;
}
static void F_155 ( struct V_2 * V_3 , int V_74 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 ;
F_71 ( L_61 , V_74 ) ;
V_154 = F_9 ( V_3 , F_119 ( V_74 ) ) ;
if ( F_98 ( V_154 , 15 , 15 ) )
F_44 ( L_62 ,
V_74 ) ;
V_154 = F_129 ( V_154 , 0 , 1 , 1 ) ;
V_154 = F_129 ( V_154 , 0 , 2 , 2 ) ;
V_154 = F_129 ( V_154 , 0 , 3 , 3 ) ;
V_154 = F_129 ( V_154 , 0 , 4 , 4 ) ;
V_154 = F_129 ( V_154 , 1 , 7 , 7 ) ;
V_154 = F_129 ( V_154 , 1 , 8 , 8 ) ;
V_154 = F_129 ( V_154 , 0 , 9 , 9 ) ;
if ( F_81 ( V_329 ) )
V_154 = F_129 ( V_154 , 3 , 11 , 10 ) ;
V_154 = F_129 ( V_154 , 4 , 29 , 27 ) ;
V_154 = F_129 ( V_154 , 4 , 23 , 21 ) ;
F_7 ( V_3 , F_119 ( V_74 ) , V_154 ) ;
V_16 -> V_148 [ V_74 ] . V_326 = V_328 ;
}
static int F_156 ( struct V_2 * V_3 , int V_74 ,
enum V_330 V_326 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_148 [ V_74 ] . V_326 == V_326 )
return 0 ;
F_71 ( L_63 , V_74 ) ;
F_152 ( V_3 , V_74 ) ;
F_154 ( V_3 , V_74 , 0 ) ;
if ( F_18 ( V_3 , F_119 ( V_74 ) , 15 , 0 ) != 0 ) {
F_44 ( L_64 , V_74 ) ;
return - V_173 ;
}
F_84 ( V_3 , F_119 ( V_74 ) , V_326 , 1 , 1 ) ;
if ( F_81 ( V_331 ) ) {
bool V_171 = V_326 == V_327 ;
F_84 ( V_3 , F_119 ( V_74 ) , V_171 , 30 , 30 ) ;
}
F_154 ( V_3 , V_74 , 1 ) ;
V_16 -> V_148 [ V_74 ] . V_326 = V_326 ;
return 0 ;
}
static void F_157 ( struct V_5 * V_6 , int V_74 ,
bool V_171 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_65 , V_74 , V_171 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_154 ( V_3 , V_74 , 0 ) ;
F_83 ( V_3 , 0 ) ;
F_84 ( V_3 , F_119 ( V_74 ) , V_171 , 9 , 9 ) ;
F_154 ( V_3 , V_74 , 1 ) ;
F_83 ( V_3 , 1 ) ;
F_144 ( V_3 ) ;
if ( V_16 -> V_307 . V_308 && V_171 )
F_158 ( V_6 , V_74 ) ;
}
static void F_159 ( struct V_2 * V_3 , int V_74 )
{
while ( F_19 ( V_3 , F_119 ( V_74 ) , 20 , 20 ) ) {
T_1 V_15 ;
V_15 = F_9 ( V_3 , F_123 ( V_74 ) ) ;
F_71 ( L_66 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
}
}
static void F_160 ( T_11 V_332 )
{
F_44 ( L_67 , V_332 ) ;
if ( V_332 & ( 1 << 0 ) )
F_44 ( L_68 ) ;
if ( V_332 & ( 1 << 1 ) )
F_44 ( L_69 ) ;
if ( V_332 & ( 1 << 2 ) )
F_44 ( L_70 ) ;
if ( V_332 & ( 1 << 3 ) )
F_44 ( L_71 ) ;
if ( V_332 & ( 1 << 4 ) )
F_44 ( L_72 ) ;
if ( V_332 & ( 1 << 5 ) )
F_44 ( L_73 ) ;
if ( V_332 & ( 1 << 6 ) )
F_44 ( L_74 ) ;
if ( V_332 & ( 1 << 7 ) )
F_44 ( L_75 ) ;
if ( V_332 & ( 1 << 8 ) )
F_44 ( L_76 ) ;
if ( V_332 & ( 1 << 9 ) )
F_44 ( L_77 ) ;
if ( V_332 & ( 1 << 10 ) )
F_44 ( L_78 ) ;
if ( V_332 & ( 1 << 11 ) )
F_44 ( L_79 ) ;
if ( V_332 & ( 1 << 12 ) )
F_44 ( L_80 ) ;
if ( V_332 & ( 1 << 13 ) )
F_44 ( L_81 ) ;
if ( V_332 & ( 1 << 14 ) )
F_44 ( L_82 ) ;
if ( V_332 & ( 1 << 15 ) )
F_44 ( L_83 ) ;
}
static T_11 F_161 ( struct V_2 * V_3 ,
int V_74 )
{
while ( F_19 ( V_3 , F_119 ( V_74 ) , 20 , 20 ) ) {
T_1 V_15 ;
T_4 V_333 ;
V_15 = F_9 ( V_3 , F_123 ( V_74 ) ) ;
F_44 ( L_84 , V_15 ) ;
V_333 = F_98 ( V_15 , 5 , 0 ) ;
if ( V_333 == V_334 ) {
T_11 V_332 = F_98 ( V_15 , 23 , 8 ) ;
F_160 ( V_332 ) ;
} else if ( V_333 == V_335 ) {
F_44 ( L_85 ,
F_98 ( V_15 , 23 , 8 ) ) ;
} else if ( V_333 == V_336 ) {
F_44 ( L_86 ,
F_98 ( V_15 , 23 , 8 ) ) ;
} else if ( V_333 == V_337 ) {
F_44 ( L_87 ,
F_98 ( V_15 , 23 , 8 ) ) ;
F_159 ( V_3 , V_74 ) ;
} else {
F_44 ( L_88 , V_333 ) ;
}
}
return 0 ;
}
static int F_162 ( struct V_2 * V_3 , int V_74 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_338 || V_16 -> V_339 )
F_71 ( L_89 , V_74 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( F_19 ( V_3 , F_119 ( V_74 ) , 20 , 20 ) ) {
F_44 ( L_90 ) ;
F_161 ( V_3 , V_74 ) ;
}
F_84 ( V_3 , F_119 ( V_74 ) , 1 , 6 , 6 ) ;
F_9 ( V_3 , F_119 ( V_74 ) ) ;
return 0 ;
}
static int F_163 ( struct V_5 * V_6 , int V_74 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
F_148 ( V_28 ) ;
int V_154 = 0 ;
T_1 V_332 ;
V_154 = F_65 ( V_3 , V_74 , F_16 ,
& V_28 , V_340 ) ;
if ( V_154 )
goto V_208;
V_154 = F_63 ( V_3 , F_16 , & V_28 ,
V_115 ) ;
if ( V_154 )
goto V_210;
V_154 = F_162 ( V_3 , V_74 ) ;
if ( V_154 )
goto V_341;
if ( F_149 ( & V_28 ,
F_20 ( 500 ) ) == 0 ) {
F_44 ( L_91 ) ;
V_154 = - V_173 ;
goto V_341;
}
V_332 = F_69 ( V_3 ) ;
if ( V_332 ) {
F_44 ( L_92 , V_332 ) ;
V_154 = - V_173 ;
goto V_341;
}
V_341:
F_64 ( V_3 , F_16 , & V_28 ,
V_115 ) ;
V_210:
F_66 ( V_3 , V_74 , F_16 ,
& V_28 , V_340 ) ;
V_208:
return V_154 ;
}
static inline void F_164 ( struct V_2 * V_3 ,
int V_74 , T_4 V_342 , T_11 V_343 , T_4 V_344 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_345 ;
F_73 ( ! F_15 ( V_3 ) ) ;
V_345 = V_342 | V_16 -> V_148 [ V_74 ] . V_346 << 6 ;
V_15 = F_142 ( V_345 , 7 , 0 ) | F_142 ( V_343 , 23 , 8 ) |
F_142 ( V_344 , 31 , 24 ) ;
F_7 ( V_3 , F_121 ( V_74 ) , V_15 ) ;
}
static inline void F_165 ( struct V_2 * V_3 ,
int V_74 , T_4 V_164 , T_4 V_165 , T_4 V_347 , T_4 V_348 )
{
T_1 V_15 ;
V_15 = V_348 << 24 | V_347 << 16 | V_165 << 8 | V_164 << 0 ;
F_7 ( V_3 , F_122 ( V_74 ) , V_15 ) ;
}
static int F_166 ( struct V_2 * V_3 , int V_74 ,
T_4 V_342 , T_4 * V_26 , T_11 V_343 , T_4 V_344 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_108 ;
T_4 * V_291 ;
int V_154 = 0 ;
T_4 V_164 , V_165 , V_347 , V_348 ;
if ( V_16 -> V_338 )
F_71 ( L_93 , V_343 ) ;
if ( V_16 -> V_148 [ V_74 ] . V_316 * 32 * 4 < V_343 + 4 ) {
F_44 ( L_94 ) ;
return - V_152 ;
}
F_156 ( V_3 , V_74 , V_328 ) ;
F_164 ( V_3 , V_74 , V_342 , V_343 , V_344 ) ;
V_291 = V_26 ;
for ( V_108 = 0 ; V_108 < V_343 > > 2 ; V_108 ++ ) {
if ( V_16 -> V_338 )
F_71 ( L_95 , V_108 ) ;
V_164 = * V_291 ++ ;
V_165 = * V_291 ++ ;
V_347 = * V_291 ++ ;
V_348 = * V_291 ++ ;
F_165 ( V_3 , V_74 , V_164 , V_165 , V_347 , V_348 ) ;
}
V_108 = V_343 % 4 ;
if ( V_108 ) {
V_164 = 0 ; V_165 = 0 ; V_347 = 0 ;
if ( V_16 -> V_338 )
F_71 ( L_96 , V_108 ) ;
switch ( V_108 ) {
case 3 :
V_164 = * V_291 ++ ;
V_165 = * V_291 ++ ;
V_347 = * V_291 ++ ;
break;
case 2 :
V_164 = * V_291 ++ ;
V_165 = * V_291 ++ ;
break;
case 1 :
V_164 = * V_291 ++ ;
break;
}
F_165 ( V_3 , V_74 , V_164 , V_165 , V_347 , 0 ) ;
}
return V_154 ;
}
static int F_167 ( struct V_2 * V_3 , int V_74 ,
T_4 V_342 , T_11 V_26 , T_4 V_344 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 ;
T_4 V_345 ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( V_16 -> V_338 )
F_71 ( L_97 ,
V_74 ,
V_342 , V_26 & 0xff , ( V_26 >> 8 ) & 0xff ) ;
F_156 ( V_3 , V_74 , V_328 ) ;
if ( F_98 ( F_9 ( V_3 , F_119 ( V_74 ) ) , 16 , 16 ) ) {
F_44 ( L_98 ) ;
return - V_152 ;
}
V_345 = V_342 | V_16 -> V_148 [ V_74 ] . V_346 << 6 ;
V_154 = ( V_345 << 0 ) | ( V_26 << 8 ) | ( V_344 << 24 ) ;
F_7 ( V_3 , F_123 ( V_74 ) , V_154 ) ;
return 0 ;
}
static int F_158 ( struct V_5 * V_6 , int V_74 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_166 ( V_3 , V_74 , V_349 , NULL ,
0 , 0 ) ;
}
static int F_168 ( struct V_2 * V_3 ,
int V_74 , T_4 * V_26 , int V_343 , enum V_350 type )
{
int V_154 ;
if ( V_343 == 0 ) {
F_61 ( type == V_351 ) ;
V_154 = F_167 ( V_3 , V_74 ,
V_352 , 0 , 0 ) ;
} else if ( V_343 == 1 ) {
V_154 = F_167 ( V_3 , V_74 ,
type == V_353 ?
V_354 :
V_355 , V_26 [ 0 ] , 0 ) ;
} else if ( V_343 == 2 ) {
V_154 = F_167 ( V_3 , V_74 ,
type == V_353 ?
V_356 :
V_357 ,
V_26 [ 0 ] | ( V_26 [ 1 ] << 8 ) , 0 ) ;
} else {
V_154 = F_166 ( V_3 , V_74 ,
type == V_353 ?
V_358 :
V_359 , V_26 , V_343 , 0 ) ;
}
return V_154 ;
}
static int F_169 ( struct V_5 * V_6 , int V_74 ,
T_4 * V_26 , int V_343 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_168 ( V_3 , V_74 , V_26 , V_343 ,
V_351 ) ;
}
static int F_170 ( struct V_5 * V_6 , int V_74 ,
T_4 * V_26 , int V_343 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_168 ( V_3 , V_74 , V_26 , V_343 ,
V_353 ) ;
}
static int F_171 ( struct V_5 * V_6 , int V_74 ,
T_4 * V_26 , int V_343 , enum V_350 type )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_154 ;
V_154 = F_168 ( V_3 , V_74 , V_26 , V_343 , type ) ;
if ( V_154 )
goto V_332;
V_154 = F_163 ( V_6 , V_74 ) ;
if ( V_154 )
goto V_332;
if ( F_19 ( V_3 , F_119 ( V_74 ) , 20 , 20 ) ) {
F_44 ( L_99 ) ;
F_161 ( V_3 , V_74 ) ;
V_154 = - V_173 ;
goto V_332;
}
return 0 ;
V_332:
F_44 ( L_100 ,
V_74 , V_26 [ 0 ] , V_343 ) ;
return V_154 ;
}
static int F_172 ( struct V_5 * V_6 , int V_74 , T_4 * V_26 ,
int V_343 )
{
return F_171 ( V_6 , V_74 , V_26 , V_343 ,
V_351 ) ;
}
static int F_173 ( struct V_5 * V_6 , int V_74 , T_4 * V_26 ,
int V_343 )
{
return F_171 ( V_6 , V_74 , V_26 , V_343 ,
V_353 ) ;
}
static int F_174 ( struct V_2 * V_3 ,
int V_74 , T_4 V_360 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
if ( V_16 -> V_339 )
F_71 ( L_101 ,
V_74 , V_360 ) ;
V_154 = F_167 ( V_3 , V_74 , V_361 , V_360 , 0 ) ;
if ( V_154 ) {
F_44 ( L_102
L_103 , V_74 , V_360 ) ;
return V_154 ;
}
return 0 ;
}
static int F_175 ( struct V_2 * V_3 ,
int V_74 , T_4 * V_362 , int V_363 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_11 V_26 ;
T_4 V_342 ;
int V_154 ;
if ( V_16 -> V_339 )
F_71 ( L_104 ,
V_74 , V_363 ) ;
if ( V_363 == 0 ) {
V_342 = V_364 ;
V_26 = 0 ;
} else if ( V_363 == 1 ) {
V_342 = V_365 ;
V_26 = V_362 [ 0 ] ;
} else if ( V_363 == 2 ) {
V_342 = V_366 ;
V_26 = V_362 [ 0 ] | ( V_362 [ 1 ] << 8 ) ;
} else {
F_26 () ;
return - V_152 ;
}
V_154 = F_167 ( V_3 , V_74 , V_342 , V_26 , 0 ) ;
if ( V_154 ) {
F_44 ( L_105
L_103 , V_74 , V_363 ) ;
return V_154 ;
}
return 0 ;
}
static int F_176 ( struct V_2 * V_3 , int V_74 ,
T_4 * V_367 , int V_368 , enum V_350 type )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_4 V_333 ;
int V_154 ;
if ( F_19 ( V_3 , F_119 ( V_74 ) , 20 , 20 ) == 0 ) {
F_44 ( L_106 ) ;
V_154 = - V_173 ;
goto V_332;
}
V_15 = F_9 ( V_3 , F_123 ( V_74 ) ) ;
if ( V_16 -> V_339 )
F_71 ( L_107 , V_15 ) ;
V_333 = F_98 ( V_15 , 5 , 0 ) ;
if ( V_333 == V_334 ) {
T_11 V_332 = F_98 ( V_15 , 23 , 8 ) ;
F_160 ( V_332 ) ;
V_154 = - V_173 ;
goto V_332;
} else if ( V_333 == ( type == V_353 ?
V_369 :
V_335 ) ) {
T_4 V_26 = F_98 ( V_15 , 15 , 8 ) ;
if ( V_16 -> V_339 )
F_71 ( L_108 ,
type == V_353 ? L_109 :
L_110 , V_26 ) ;
if ( V_368 < 1 ) {
V_154 = - V_173 ;
goto V_332;
}
V_367 [ 0 ] = V_26 ;
return 1 ;
} else if ( V_333 == ( type == V_353 ?
V_370 :
V_336 ) ) {
T_11 V_26 = F_98 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_339 )
F_71 ( L_111 ,
type == V_353 ? L_109 :
L_110 , V_26 ) ;
if ( V_368 < 2 ) {
V_154 = - V_173 ;
goto V_332;
}
V_367 [ 0 ] = V_26 & 0xff ;
V_367 [ 1 ] = ( V_26 >> 8 ) & 0xff ;
return 2 ;
} else if ( V_333 == ( type == V_353 ?
V_371 :
V_337 ) ) {
int V_372 ;
int V_343 = F_98 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_339 )
F_71 ( L_112 ,
type == V_353 ? L_109 :
L_110 , V_343 ) ;
if ( V_343 > V_368 ) {
V_154 = - V_173 ;
goto V_332;
}
for ( V_372 = 0 ; V_372 < V_343 + 2 ; ) {
int V_373 ;
V_15 = F_9 ( V_3 ,
F_123 ( V_74 ) ) ;
if ( V_16 -> V_339 )
F_71 ( L_113 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
for ( V_373 = 0 ; V_373 < 4 ; ++ V_373 ) {
if ( V_372 < V_343 )
V_367 [ V_372 ] = ( V_15 >> ( V_373 * 8 ) ) & 0xff ;
++ V_372 ;
}
}
return V_343 ;
} else {
F_44 ( L_88 , V_333 ) ;
V_154 = - V_173 ;
goto V_332;
}
V_332:
F_44 ( L_114 , V_74 ,
type == V_353 ? L_109 : L_110 ) ;
return V_154 ;
}
static int F_177 ( struct V_5 * V_6 , int V_74 , T_4 V_360 ,
T_4 * V_367 , int V_368 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_154 ;
V_154 = F_174 ( V_3 , V_74 , V_360 ) ;
if ( V_154 )
goto V_332;
V_154 = F_163 ( V_6 , V_74 ) ;
if ( V_154 )
goto V_332;
V_154 = F_176 ( V_3 , V_74 , V_367 , V_368 ,
V_351 ) ;
if ( V_154 < 0 )
goto V_332;
if ( V_154 != V_368 ) {
V_154 = - V_173 ;
goto V_332;
}
return 0 ;
V_332:
F_44 ( L_115 , V_74 , V_360 ) ;
return V_154 ;
}
static int F_178 ( struct V_5 * V_6 , int V_74 ,
T_4 * V_362 , int V_363 , T_4 * V_367 , int V_368 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_154 ;
V_154 = F_175 ( V_3 , V_74 , V_362 , V_363 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_163 ( V_6 , V_74 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_176 ( V_3 , V_74 , V_367 , V_368 ,
V_353 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( V_154 != V_368 ) {
V_154 = - V_173 ;
return V_154 ;
}
return 0 ;
}
static int F_179 ( struct V_5 * V_6 , int V_74 ,
T_11 V_343 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_167 ( V_3 , V_74 ,
V_374 , V_343 , 0 ) ;
}
static int F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_148 ( V_28 ) ;
int V_154 , V_108 ;
unsigned V_27 ;
F_71 ( L_116 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( V_16 -> V_300 ) ;
if ( V_16 -> V_300 )
return 0 ;
if ( F_19 ( V_3 , V_194 , 13 , 13 ) ) {
F_83 ( V_3 , 0 ) ;
F_84 ( V_3 , V_194 , 0 , 13 , 13 ) ;
F_83 ( V_3 , 1 ) ;
}
F_152 ( V_3 , 0 ) ;
F_152 ( V_3 , 1 ) ;
F_152 ( V_3 , 2 ) ;
F_152 ( V_3 , 3 ) ;
F_144 ( V_3 ) ;
F_154 ( V_3 , 0 , false ) ;
F_154 ( V_3 , 1 , false ) ;
F_154 ( V_3 , 2 , false ) ;
F_154 ( V_3 , 3 , false ) ;
if ( F_19 ( V_3 , V_243 , 16 , 16 ) ) {
F_44 ( L_117 ) ;
return - V_173 ;
}
if ( F_19 ( V_3 , V_243 , 17 , 17 ) ) {
F_44 ( L_118 ) ;
return - V_173 ;
}
V_154 = F_67 ( V_3 , F_16 , & V_28 ,
V_375 ) ;
if ( V_154 )
return V_154 ;
V_27 = 0 ;
for ( V_108 = 0 ; V_108 < V_16 -> V_273 ; ++ V_108 ) {
if ( V_16 -> V_274 [ V_108 ] . V_275 == V_297 )
continue;
V_27 |= 1 << V_108 ;
}
F_84 ( V_3 , V_243 , V_27 , 9 , 5 ) ;
F_9 ( V_3 , V_243 ) ;
if ( F_149 ( & V_28 ,
F_20 ( 1000 ) ) == 0 ) {
F_44 ( L_119 ) ;
V_154 = - V_173 ;
goto V_332;
}
F_68 ( V_3 , F_16 , & V_28 ,
V_375 ) ;
F_84 ( V_3 , V_243 , 0 , 9 , 5 ) ;
F_9 ( V_3 , V_243 ) ;
F_126 ( V_3 , V_376 ) ;
F_83 ( V_3 , false ) ;
V_16 -> V_300 = true ;
return 0 ;
V_332:
F_68 ( V_3 , F_16 , & V_28 ,
V_375 ) ;
return V_154 ;
}
static void F_181 ( struct V_2 * V_3 ,
unsigned V_377 , bool V_378 , bool V_379 )
{
unsigned long V_380 ;
unsigned long V_381 ;
T_1 V_154 ;
F_61 ( V_377 > 0x1fff ) ;
V_380 = F_88 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_236 ) ;
V_154 = F_129 ( V_154 , 1 , 15 , 15 ) ;
V_154 = F_129 ( V_154 , V_379 ? 1 : 0 , 14 , 14 ) ;
V_154 = F_129 ( V_154 , V_378 ? 1 : 0 , 13 , 13 ) ;
V_154 = F_129 ( V_154 , V_377 , 12 , 0 ) ;
F_7 ( V_3 , V_236 , V_154 ) ;
V_381 = V_377 * ( V_379 ? 16 : 1 ) * ( V_378 ? 4 : 1 ) ;
F_71 ( L_120 ,
V_381 ,
V_377 , V_378 ? L_121 : L_3 , V_379 ? L_122 : L_3 ,
( V_381 * 1000 ) / ( V_380 / 1000 / 1000 ) ) ;
}
static void F_182 ( struct V_2 * V_3 , unsigned V_377 ,
bool V_382 , bool V_379 )
{
unsigned long V_380 ;
unsigned long V_381 ;
T_1 V_154 ;
F_61 ( V_377 > 0x1fff ) ;
V_380 = F_88 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_235 ) ;
V_154 = F_129 ( V_154 , 1 , 31 , 31 ) ;
V_154 = F_129 ( V_154 , V_379 ? 1 : 0 , 30 , 30 ) ;
V_154 = F_129 ( V_154 , V_382 ? 1 : 0 , 29 , 29 ) ;
V_154 = F_129 ( V_154 , V_377 , 28 , 16 ) ;
F_7 ( V_3 , V_235 , V_154 ) ;
V_381 = V_377 * ( V_379 ? 16 : 1 ) * ( V_382 ? 8 : 1 ) ;
F_71 ( L_123 ,
V_381 ,
V_377 , V_382 ? L_124 : L_3 , V_379 ? L_122 : L_3 ,
( V_381 * 1000 ) / ( V_380 / 1000 / 1000 ) ) ;
}
static void F_183 ( struct V_2 * V_3 ,
unsigned V_377 , bool V_378 , bool V_379 )
{
unsigned long V_380 ;
unsigned long V_381 ;
T_1 V_154 ;
F_61 ( V_377 > 0x1fff ) ;
V_380 = F_88 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_235 ) ;
V_154 = F_129 ( V_154 , 1 , 15 , 15 ) ;
V_154 = F_129 ( V_154 , V_379 ? 1 : 0 , 14 , 14 ) ;
V_154 = F_129 ( V_154 , V_378 ? 1 : 0 , 13 , 13 ) ;
V_154 = F_129 ( V_154 , V_377 , 12 , 0 ) ;
F_7 ( V_3 , V_235 , V_154 ) ;
V_381 = V_377 * ( V_379 ? 16 : 1 ) * ( V_378 ? 4 : 1 ) ;
F_71 ( L_125 ,
V_381 ,
V_377 , V_378 ? L_121 : L_3 , V_379 ? L_122 : L_3 ,
( V_381 * 1000 ) / ( V_380 / 1000 / 1000 ) ) ;
}
static void F_184 ( struct V_2 * V_3 ,
unsigned V_377 , bool V_378 , bool V_379 )
{
unsigned long V_380 ;
unsigned long V_381 ;
T_1 V_154 ;
F_61 ( V_377 > 0x1fff ) ;
V_380 = F_87 ( V_3 ) ;
V_154 = F_9 ( V_3 , V_236 ) ;
V_154 = F_129 ( V_154 , 1 , 31 , 31 ) ;
V_154 = F_129 ( V_154 , V_379 ? 1 : 0 , 30 , 30 ) ;
V_154 = F_129 ( V_154 , V_378 ? 1 : 0 , 29 , 29 ) ;
V_154 = F_129 ( V_154 , V_377 , 28 , 16 ) ;
F_7 ( V_3 , V_236 , V_154 ) ;
V_381 = V_377 * ( V_379 ? 16 : 1 ) * ( V_378 ? 4 : 1 ) ;
F_71 ( L_126 ,
V_381 ,
V_377 , V_378 ? L_121 : L_3 , V_379 ? L_122 : L_3 ,
( V_381 * 1000 ) / ( V_380 / 1000 / 1000 ) ) ;
}
static void F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_383 ;
if ( V_16 -> V_305 == V_306 ) {
int V_384 = F_25 ( V_16 -> V_385 ) ;
struct V_386 * V_387 = & V_16 -> V_387 ;
if ( V_16 -> V_388 <= V_387 -> V_389 * V_384 / 8 )
V_383 = 0 ;
else
V_383 = 2 ;
} else {
V_383 = 2 ;
}
F_84 ( V_3 , V_172 , V_383 , 13 , 12 ) ;
}
static void F_186 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
bool V_390 ;
T_1 V_154 ;
if ( V_16 -> V_307 . V_391 == V_392 )
V_390 = true ;
else
V_390 = false ;
V_154 = F_9 ( V_3 , V_172 ) ;
V_154 = F_129 ( V_154 , 1 , 9 , 9 ) ;
V_154 = F_129 ( V_154 , 1 , 10 , 10 ) ;
V_154 = F_129 ( V_154 , 1 , 11 , 11 ) ;
V_154 = F_129 ( V_154 , 1 , 15 , 15 ) ;
V_154 = F_129 ( V_154 , V_390 , 16 , 16 ) ;
V_154 = F_129 ( V_154 , 1 , 17 , 17 ) ;
V_154 = F_129 ( V_154 , V_390 , 18 , 18 ) ;
F_7 ( V_3 , V_172 , V_154 ) ;
}
static void F_187 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_393 = V_16 -> V_307 . V_393 ;
int V_394 = V_16 -> V_307 . V_394 ;
int V_395 = V_16 -> V_307 . V_395 ;
int V_396 = V_16 -> V_307 . V_396 ;
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_172 ) ;
V_154 = F_129 ( V_154 , V_393 , 20 , 20 ) ;
V_154 = F_129 ( V_154 , V_394 , 21 , 21 ) ;
V_154 = F_129 ( V_154 , V_395 , 22 , 22 ) ;
V_154 = F_129 ( V_154 , V_396 , 23 , 23 ) ;
F_7 ( V_3 , V_172 , V_154 ) ;
}
static int F_188 ( int V_397 , bool V_398 , int V_399 ,
int V_400 , int V_401 , int V_402 , int V_403 )
{
int V_404 ;
if ( V_398 ) {
V_404 = V_399 + V_400 + F_189 ( V_399 , 2 ) + 1 ;
} else {
int V_405 , V_406 ;
V_405 = V_402 + V_399 + V_400 + F_189 ( V_399 , 2 ) + 1 ;
V_406 = V_402 + V_399 + V_401 + V_403 + V_402 +
V_399 + 1 ;
V_404 = F_189 ( V_405 , V_406 ) ;
}
return V_397 > V_404 ? V_397 - V_404 : 0 ;
}
static int F_190 ( int V_397 , int V_399 , int V_400 ,
int V_188 , int V_407 )
{
int V_408 ;
int V_409 ;
int V_410 ;
int V_411 = 16 ;
int V_412 ;
V_408 = V_400 + F_189 ( V_399 , 2 ) + 1 ;
V_409 = V_411 * ( V_397 - V_408 ) ;
V_410 = V_407 * V_188 ;
V_412 = ( ( V_409 - 8 * V_411 - 5 * V_407 ) / V_410 -
26 ) / 16 ;
return F_189 ( V_412 , 0 ) ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_393 ;
int V_394 , V_395 , V_396 ;
int V_413 , V_414 , V_415 , V_416 , V_417 , V_188 ;
int V_418 , V_419 , V_420 , V_421 ;
int V_284 , V_282 , V_401 ;
bool V_398 ;
struct V_386 * V_387 = & V_16 -> V_387 ;
int V_384 = F_25 ( V_16 -> V_385 ) ;
int V_422 = V_16 -> V_269 - 1 ;
int V_423 = V_16 -> V_424 . V_205 [ V_178 ] + 1 ;
int V_425 = 0 , V_426 = 0 ;
int V_427 = 0 , V_428 = 0 ;
int V_429 = 0 , V_430 = 0 ;
int V_431 = 0 , V_432 = 0 ;
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_172 ) ;
V_393 = F_98 ( V_154 , 20 , 20 ) ;
V_394 = F_98 ( V_154 , 21 , 21 ) ;
V_395 = F_98 ( V_154 , 22 , 22 ) ;
V_396 = F_98 ( V_154 , 23 , 23 ) ;
V_154 = F_9 ( V_3 , V_237 ) ;
V_415 = F_98 ( V_154 , 11 , 0 ) ;
V_414 = F_98 ( V_154 , 23 , 12 ) ;
V_413 = F_98 ( V_154 , 31 , 24 ) ;
V_154 = F_9 ( V_3 , V_240 ) ;
V_419 = F_98 ( V_154 , 7 , 0 ) ;
V_418 = F_98 ( V_154 , 15 , 8 ) ;
V_154 = F_9 ( V_3 , V_249 ) ;
V_421 = F_98 ( V_154 , 15 , 0 ) ;
V_420 = F_98 ( V_154 , 31 , 16 ) ;
V_154 = F_9 ( V_3 , V_194 ) ;
V_188 = F_98 ( V_154 , 12 , 0 ) ;
V_398 = F_98 ( V_154 , 13 , 13 ) ;
V_154 = F_9 ( V_3 , V_251 ) ;
V_282 = F_98 ( V_154 , 7 , 0 ) ;
V_154 = F_9 ( V_3 , V_252 ) ;
V_284 = F_98 ( V_154 , 15 , 8 ) ;
V_401 = V_282 + V_284 ;
V_416 = F_92 ( V_387 -> V_389 * V_384 , 8 ) ;
V_417 = V_415 + V_414 + V_413 + F_92 ( V_416 + 6 , V_422 ) ;
if ( ! V_396 ) {
V_425 = F_188 ( V_413 , V_398 ,
V_420 , V_421 ,
V_401 , V_418 , V_419 ) ;
V_426 = F_190 ( V_413 ,
V_420 , V_421 ,
V_188 , V_423 ) ;
}
if ( ! V_394 ) {
V_427 = F_188 ( V_414 , V_398 ,
V_420 , V_421 ,
V_401 , V_418 , V_419 ) ;
V_428 = F_190 ( V_414 ,
V_420 , V_421 ,
V_188 , V_423 ) ;
}
if ( ! V_395 ) {
V_429 = F_188 ( V_415 , V_398 ,
V_420 , V_421 ,
V_401 , V_418 , V_419 ) ;
V_430 = F_190 ( V_415 ,
V_420 , V_421 ,
V_188 , V_423 ) ;
}
if ( ! V_393 ) {
V_431 = F_188 ( V_417 , V_398 ,
V_420 , V_421 ,
V_401 , V_418 , V_419 ) ;
V_432 = F_190 ( V_417 ,
V_420 , V_421 ,
V_188 , V_423 ) ;
}
F_71 ( L_127 ,
V_425 , V_427 , V_429 ,
V_431 ) ;
F_71 ( L_128 ,
V_426 , V_428 , V_430 ,
V_432 ) ;
V_154 = F_9 ( V_3 , V_245 ) ;
V_154 = F_129 ( V_154 , V_425 , 23 , 16 ) ;
V_154 = F_129 ( V_154 , V_427 , 15 , 8 ) ;
V_154 = F_129 ( V_154 , V_429 , 7 , 0 ) ;
F_7 ( V_3 , V_245 , V_154 ) ;
V_154 = F_9 ( V_3 , V_247 ) ;
V_154 = F_129 ( V_154 , V_426 , 23 , 16 ) ;
V_154 = F_129 ( V_154 , V_428 , 15 , 8 ) ;
V_154 = F_129 ( V_154 , V_430 , 7 , 0 ) ;
F_7 ( V_3 , V_247 , V_154 ) ;
V_154 = F_9 ( V_3 , V_248 ) ;
V_154 = F_129 ( V_154 , V_431 , 31 , 15 ) ;
V_154 = F_129 ( V_154 , V_432 , 16 , 0 ) ;
F_7 ( V_3 , V_248 , V_154 ) ;
}
static int F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_154 ;
int V_433 = 0 ;
F_141 ( V_3 , V_434 ,
V_434 ,
V_434 ,
V_434 ) ;
F_143 ( V_3 , V_434 ,
V_434 ,
V_434 ,
V_434 ) ;
F_183 ( V_3 , 0x1000 , false , false ) ;
F_182 ( V_3 , 0x1fff , true , true ) ;
F_181 ( V_3 , 0x1fff , true , true ) ;
F_184 ( V_3 , 0x1fff , true , true ) ;
switch ( F_25 ( V_16 -> V_385 ) ) {
case 16 :
V_433 = 0 ;
break;
case 18 :
V_433 = 1 ;
break;
case 24 :
V_433 = 2 ;
break;
default:
F_26 () ;
return - V_152 ;
}
V_154 = F_9 ( V_3 , V_172 ) ;
V_154 = F_129 ( V_154 , 1 , 1 , 1 ) ;
V_154 = F_129 ( V_154 , 1 , 2 , 2 ) ;
V_154 = F_129 ( V_154 , 1 , 3 , 3 ) ;
V_154 = F_129 ( V_154 , 1 , 4 , 4 ) ;
V_154 = F_129 ( V_154 , V_433 , 7 , 6 ) ;
V_154 = F_129 ( V_154 , 0 , 8 , 8 ) ;
V_154 = F_129 ( V_154 , 1 , 14 , 14 ) ;
V_154 = F_129 ( V_154 , 1 , 19 , 19 ) ;
if ( ! F_81 ( V_331 ) ) {
V_154 = F_129 ( V_154 , 1 , 24 , 24 ) ;
V_154 = F_129 ( V_154 , 0 , 25 , 25 ) ;
}
F_7 ( V_3 , V_172 , V_154 ) ;
F_185 ( V_3 ) ;
if ( V_16 -> V_305 == V_306 ) {
F_186 ( V_3 ) ;
F_187 ( V_3 ) ;
F_191 ( V_3 ) ;
}
F_155 ( V_3 , 0 ) ;
F_155 ( V_3 , 1 ) ;
F_155 ( V_3 , 2 ) ;
F_155 ( V_3 , 3 ) ;
return 0 ;
}
static void F_193 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_435 , V_285 , V_286 , V_284 ;
unsigned V_436 , V_437 ;
unsigned V_279 , V_280 , V_438 ;
unsigned V_281 , V_282 ;
unsigned V_418 , V_419 ;
unsigned V_420 , V_421 ;
unsigned V_439 ;
int V_422 = V_16 -> V_269 - 1 ;
T_1 V_154 ;
V_154 = F_9 ( V_3 , V_251 ) ;
V_279 = F_98 ( V_154 , 31 , 24 ) ;
V_280 = F_98 ( V_154 , 23 , 16 ) ;
V_438 = V_280 - V_279 ;
V_281 = F_98 ( V_154 , 15 , 8 ) ;
V_282 = F_98 ( V_154 , 7 , 0 ) ;
V_154 = F_9 ( V_3 , V_252 ) ;
V_435 = F_98 ( V_154 , 20 , 16 ) * 2 ;
V_284 = F_98 ( V_154 , 15 , 8 ) ;
V_285 = F_98 ( V_154 , 7 , 0 ) ;
V_154 = F_9 ( V_3 , V_253 ) ;
V_286 = F_98 ( V_154 , 7 , 0 ) ;
V_436 = 20 ;
V_437 = F_130 ( V_3 , 60 ) + 26 ;
V_439 = F_92 ( 4 , V_422 ) ;
V_418 = F_92 ( V_436 + V_435 + V_285 + V_286 ,
4 ) ;
V_419 = F_92 ( V_437 + V_281 , 4 ) + V_439 ;
F_61 ( V_418 == 0 || V_418 > 255 ) ;
F_61 ( V_419 == 0 || V_419 > 255 ) ;
V_154 = F_9 ( V_3 , V_240 ) ;
V_154 = F_129 ( V_154 , V_418 , 15 , 8 ) ;
V_154 = F_129 ( V_154 , V_419 , 7 , 0 ) ;
F_7 ( V_3 , V_240 , V_154 ) ;
F_71 ( L_129 ,
V_418 ,
V_419 ) ;
V_420 = 1 + F_92 ( V_435 , 4 ) +
F_92 ( V_279 , 4 ) +
F_92 ( V_438 + 3 , 4 ) ;
V_421 = F_92 ( V_281 + V_282 , 4 ) + 1 + V_439 ;
V_154 = F_142 ( V_420 , 31 , 16 ) |
F_142 ( V_421 , 15 , 0 ) ;
F_7 ( V_3 , V_249 , V_154 ) ;
F_71 ( L_130 ,
V_420 , V_421 ) ;
if ( V_16 -> V_305 == V_306 ) {
int V_413 = V_16 -> V_307 . V_413 ;
int V_414 = V_16 -> V_307 . V_414 ;
int V_415 = V_16 -> V_307 . V_415 ;
int V_440 = V_16 -> V_307 . V_440 ;
int V_441 = V_16 -> V_307 . V_441 ;
int V_442 = V_16 -> V_307 . V_442 ;
int V_443 = V_16 -> V_307 . V_443 ;
bool V_444 ;
struct V_386 * V_387 = & V_16 -> V_387 ;
int V_384 = F_25 ( V_16 -> V_385 ) ;
int V_445 , V_446 , V_416 ;
V_444 = V_16 -> V_307 . V_391 == V_392 ;
V_446 = V_444 ?
( ( V_413 == 0 && V_422 == 3 ) ? 1 : F_92 ( 4 , V_422 ) ) : 0 ;
V_416 = F_92 ( V_387 -> V_389 * V_384 , 8 ) ;
V_445 = F_92 ( 4 , V_422 ) + ( V_444 ? V_413 : 0 ) + V_446 + V_414 +
F_92 ( V_416 + 6 , V_422 ) + V_415 ;
F_71 ( L_131 , V_415 ,
V_414 , V_444 ? V_413 : 0 , V_445 ) ;
F_71 ( L_132 , V_442 , V_441 ,
V_440 , V_387 -> V_447 ) ;
V_154 = F_9 ( V_3 , V_237 ) ;
V_154 = F_129 ( V_154 , V_415 , 11 , 0 ) ;
V_154 = F_129 ( V_154 , V_414 , 23 , 12 ) ;
V_154 = F_129 ( V_154 , V_444 ? V_413 : 0 , 31 , 24 ) ;
F_7 ( V_3 , V_237 , V_154 ) ;
V_154 = F_9 ( V_3 , V_238 ) ;
V_154 = F_129 ( V_154 , V_442 , 7 , 0 ) ;
V_154 = F_129 ( V_154 , V_441 , 15 , 8 ) ;
V_154 = F_129 ( V_154 , V_440 , 23 , 16 ) ;
V_154 = F_129 ( V_154 , V_443 , 27 , 24 ) ;
F_7 ( V_3 , V_238 , V_154 ) ;
V_154 = F_9 ( V_3 , V_239 ) ;
V_154 = F_129 ( V_154 , V_387 -> V_447 , 14 , 0 ) ;
V_154 = F_129 ( V_154 , V_445 , 31 , 16 ) ;
F_7 ( V_3 , V_239 , V_154 ) ;
}
}
static int F_194 ( struct V_5 * V_6 ,
const struct V_448 * V_449 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_450 ;
const int * V_451 ;
struct V_452 V_274 [ V_294 ] ;
int V_453 ;
int V_108 ;
static const enum V_262 V_263 [] = {
V_264 ,
V_265 ,
V_266 ,
V_267 ,
V_268 ,
} ;
V_450 = V_449 -> V_450 ;
V_451 = V_449 -> V_451 ;
if ( V_450 < 4 || V_450 > V_16 -> V_273 * 2
|| V_450 % 2 != 0 )
return - V_152 ;
for ( V_108 = 0 ; V_108 < V_294 ; ++ V_108 )
V_274 [ V_108 ] . V_275 = V_297 ;
V_453 = 0 ;
for ( V_108 = 0 ; V_108 < V_450 ; V_108 += 2 ) {
T_4 V_454 , V_455 ;
int V_456 , V_457 ;
V_456 = V_451 [ V_108 ] ;
V_457 = V_451 [ V_108 + 1 ] ;
if ( V_456 < 0 || V_456 >= V_16 -> V_273 * 2 )
return - V_152 ;
if ( V_457 < 0 || V_457 >= V_16 -> V_273 * 2 )
return - V_152 ;
if ( V_456 & 1 ) {
if ( V_457 != V_456 - 1 )
return - V_152 ;
V_455 = 1 ;
} else {
if ( V_457 != V_456 + 1 )
return - V_152 ;
V_455 = 0 ;
}
V_454 = V_456 / 2 ;
V_274 [ V_454 ] . V_275 = V_263 [ V_108 / 2 ] ;
V_274 [ V_454 ] . V_271 = V_455 ;
V_453 ++ ;
}
memcpy ( V_16 -> V_274 , V_274 , sizeof( V_16 -> V_274 ) ) ;
V_16 -> V_269 = V_453 ;
return 0 ;
}
static int F_195 ( struct V_5 * V_6 , int V_74 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_458 V_459 = V_6 -> V_459 ;
int V_384 = F_25 ( V_16 -> V_385 ) ;
struct V_5 * V_8 = & V_16 -> V_460 ;
T_4 V_342 ;
T_11 V_461 ;
int V_154 ;
if ( ! V_8 -> V_462 ) {
F_44 ( L_133 ) ;
return - V_201 ;
}
V_154 = F_196 ( V_3 , V_459 ) ;
if ( V_154 )
goto V_463;
if ( V_16 -> V_305 == V_306 ) {
switch ( V_16 -> V_385 ) {
case V_39 :
V_342 = V_464 ;
break;
case V_40 :
V_342 = V_465 ;
break;
case V_41 :
V_342 = V_466 ;
break;
case V_42 :
V_342 = V_467 ;
break;
default:
V_154 = - V_152 ;
goto V_468;
}
F_83 ( V_3 , false ) ;
F_154 ( V_3 , V_74 , false ) ;
F_84 ( V_3 , F_119 ( V_74 ) , 1 , 4 , 4 ) ;
V_461 = F_92 ( V_16 -> V_387 . V_389 * V_384 , 8 ) ;
F_164 ( V_3 , V_74 , V_342 ,
V_461 , 0 ) ;
F_154 ( V_3 , V_74 , true ) ;
F_83 ( V_3 , true ) ;
}
V_154 = F_197 ( V_459 ) ;
if ( V_154 )
goto V_469;
return 0 ;
V_469:
if ( V_16 -> V_305 == V_306 ) {
F_83 ( V_3 , false ) ;
F_154 ( V_3 , V_74 , false ) ;
}
V_468:
F_198 ( V_3 , V_459 ) ;
V_463:
return V_154 ;
}
static void F_199 ( struct V_5 * V_6 , int V_74 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_458 V_459 = V_6 -> V_459 ;
if ( V_16 -> V_305 == V_306 ) {
F_83 ( V_3 , false ) ;
F_154 ( V_3 , V_74 , false ) ;
F_84 ( V_3 , F_119 ( V_74 ) , 0 , 4 , 4 ) ;
F_154 ( V_3 , V_74 , true ) ;
F_83 ( V_3 , true ) ;
}
F_200 ( V_459 ) ;
F_198 ( V_3 , V_459 ) ;
}
static void F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
enum V_458 V_459 = V_16 -> V_460 . V_459 ;
unsigned V_470 ;
unsigned V_471 ;
unsigned V_472 ;
unsigned V_473 ;
unsigned V_474 ;
unsigned V_475 ;
T_1 V_162 ;
int V_154 ;
const unsigned V_74 = V_16 -> V_322 ;
const unsigned V_476 = V_16 -> V_388 ;
T_11 V_372 = V_16 -> V_387 . V_389 ;
T_11 V_477 = V_16 -> V_387 . V_447 ;
F_71 ( L_134 , V_372 , V_477 ) ;
F_156 ( V_3 , V_74 , V_327 ) ;
V_470 = F_25 ( V_16 -> V_385 ) / 8 ;
V_471 = V_372 * V_470 ;
V_472 = V_471 * V_477 ;
if ( V_472 < V_476 )
V_474 = V_472 ;
else
V_474 = ( V_476 ) / V_471 * V_471 ;
V_475 = V_474 + 1 ;
V_473 = ( V_472 / V_474 ) * V_475 ;
if ( V_472 % V_474 )
V_473 += ( V_472 % V_474 ) + 1 ;
V_162 = F_142 ( V_473 , 23 , 0 ) ;
F_7 ( V_3 , F_120 ( V_74 ) , V_162 ) ;
F_164 ( V_3 , V_74 , V_359 ,
V_475 , 0 ) ;
if ( V_16 -> V_324 )
V_162 = F_129 ( V_162 , 1 , 30 , 30 ) ;
else
V_162 = F_129 ( V_162 , 1 , 31 , 31 ) ;
F_7 ( V_3 , F_120 ( V_74 ) , V_162 ) ;
F_202 () ;
F_29 ( V_3 ) ;
V_154 = F_203 ( & V_16 -> V_478 ,
F_20 ( 250 ) ) ;
F_61 ( V_154 == 0 ) ;
F_204 ( V_459 , & V_16 -> V_387 ) ;
F_205 ( V_459 ) ;
if ( V_16 -> V_324 ) {
F_84 ( V_3 , V_236 , 0 , 15 , 15 ) ;
F_162 ( V_3 , V_74 ) ;
#ifdef F_50
F_206 ( & V_16 -> V_140 , V_34 + F_20 ( 250 ) ) ;
#endif
}
}
static void F_207 ( unsigned long V_126 )
{
F_44 ( L_135 ) ;
}
static void F_208 ( struct V_2 * V_3 , int error )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_209 () ;
if ( V_16 -> V_324 ) {
F_84 ( V_3 , V_236 , 1 , 15 , 15 ) ;
}
V_16 -> V_479 ( error , V_16 -> V_480 ) ;
if ( ! error )
F_30 ( V_3 , L_136 ) ;
}
static void F_210 ( struct V_481 * V_482 )
{
struct V_1 * V_16 = F_102 ( V_482 , struct V_1 ,
V_478 . V_482 ) ;
F_44 ( L_137 ) ;
F_208 ( V_16 -> V_156 , - V_483 ) ;
}
static void F_211 ( void * V_26 )
{
struct V_2 * V_3 = (struct V_2 * ) V_26 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_212 ( & V_16 -> V_478 ) ;
F_208 ( V_3 , 0 ) ;
}
static int F_213 ( struct V_5 * V_6 , int V_74 ,
void (* F_214)( int , void * ) , void * V_26 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_11 V_484 , V_485 ;
F_27 ( V_3 ) ;
V_16 -> V_322 = V_74 ;
V_16 -> V_479 = F_214 ;
V_16 -> V_480 = V_26 ;
V_484 = V_16 -> V_387 . V_389 ;
V_485 = V_16 -> V_387 . V_447 ;
#ifdef F_215
V_16 -> V_53 = V_484 * V_485 *
F_25 ( V_16 -> V_385 ) / 8 ;
#endif
F_201 ( V_3 ) ;
return 0 ;
}
static int F_216 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_486 V_487 ;
int V_154 ;
unsigned long V_380 ;
V_380 = F_85 ( V_3 ) ;
V_487 . V_488 = V_16 -> V_489 . V_488 ;
V_487 . V_490 = V_16 -> V_489 . V_490 ;
V_154 = F_217 ( V_380 , & V_487 ) ;
if ( V_154 ) {
F_44 ( L_138 ) ;
return V_154 ;
}
V_16 -> V_491 . V_492 = V_487 ;
return 0 ;
}
static int F_196 ( struct V_2 * V_3 ,
enum V_458 V_74 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
F_218 ( V_74 , V_16 -> V_180 == 0 ?
V_223 :
V_224 ) ;
if ( V_16 -> V_305 == V_493 ) {
V_154 = F_219 ( V_74 ,
F_211 , V_3 ) ;
if ( V_154 ) {
F_44 ( L_139 ) ;
goto V_332;
}
V_16 -> V_491 . V_494 = true ;
V_16 -> V_491 . V_495 = true ;
} else {
V_16 -> V_491 . V_494 = false ;
V_16 -> V_491 . V_495 = false ;
}
V_16 -> V_387 . V_150 &= ~ V_496 ;
V_16 -> V_387 . V_150 &= ~ V_497 ;
V_16 -> V_387 . V_150 |= V_498 ;
V_16 -> V_387 . V_150 &= ~ V_499 ;
V_16 -> V_387 . V_150 |= V_500 ;
V_16 -> V_387 . V_150 &= ~ V_501 ;
V_16 -> V_387 . V_150 |= V_502 ;
V_16 -> V_387 . V_150 &= ~ V_503 ;
V_16 -> V_387 . V_150 |= V_504 ;
V_16 -> V_387 . V_150 &= ~ V_505 ;
V_16 -> V_387 . V_150 |= V_506 ;
F_204 ( V_74 , & V_16 -> V_387 ) ;
V_154 = F_216 ( V_3 ) ;
if ( V_154 )
goto V_210;
V_16 -> V_491 . V_507 = V_508 ;
V_16 -> V_491 . V_509 =
F_25 ( V_16 -> V_385 ) ;
V_16 -> V_491 . V_510 = 0 ;
F_220 ( V_74 , & V_16 -> V_491 ) ;
return 0 ;
V_210:
if ( V_16 -> V_305 == V_493 )
F_221 ( V_74 ,
F_211 , V_3 ) ;
V_332:
F_218 ( V_74 , V_181 ) ;
return V_154 ;
}
static void F_198 ( struct V_2 * V_3 ,
enum V_458 V_74 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_305 == V_493 )
F_221 ( V_74 ,
F_211 , V_3 ) ;
F_218 ( V_74 , V_181 ) ;
}
static int F_222 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_202 V_175 ;
int V_154 ;
V_175 = V_16 -> V_424 ;
V_154 = F_223 ( & V_16 -> V_174 , & V_175 ) ;
if ( V_154 ) {
F_44 ( L_140 ) ;
return V_154 ;
}
return 0 ;
}
static int F_224 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 ;
V_154 = F_225 ( & V_16 -> V_174 ) ;
if ( V_154 )
goto V_208;
V_154 = F_222 ( V_3 ) ;
if ( V_154 )
goto V_210;
F_226 ( V_16 -> V_180 , V_16 -> V_180 == 0 ?
V_225 :
V_226 ) ;
F_71 ( L_141 ) ;
V_154 = F_137 ( V_3 ) ;
if ( V_154 )
goto V_341;
F_80 ( V_3 ) ;
F_193 ( V_3 ) ;
F_93 ( V_3 ) ;
if ( 1 )
F_80 ( V_3 ) ;
V_154 = F_192 ( V_3 ) ;
if ( V_154 )
goto V_511;
F_154 ( V_3 , 0 , 1 ) ;
F_154 ( V_3 , 1 , 1 ) ;
F_154 ( V_3 , 2 , 1 ) ;
F_154 ( V_3 , 3 , 1 ) ;
F_83 ( V_3 , 1 ) ;
F_144 ( V_3 ) ;
return 0 ;
V_511:
F_140 ( V_3 ) ;
V_341:
F_226 ( V_16 -> V_180 , V_181 ) ;
V_210:
F_227 ( & V_16 -> V_174 ) ;
V_208:
return V_154 ;
}
static void F_228 ( struct V_2 * V_3 ,
bool V_211 , bool V_512 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_512 && ! V_16 -> V_300 )
F_180 ( V_3 ) ;
F_83 ( V_3 , 0 ) ;
F_154 ( V_3 , 0 , 0 ) ;
F_154 ( V_3 , 1 , 0 ) ;
F_154 ( V_3 , 2 , 0 ) ;
F_154 ( V_3 , 3 , 0 ) ;
F_226 ( V_16 -> V_180 , V_181 ) ;
F_140 ( V_3 ) ;
F_106 ( V_3 , V_211 ) ;
}
static int F_229 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_154 = 0 ;
F_71 ( L_142 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_230 ( & V_16 -> V_513 ) ;
V_154 = F_70 ( V_3 ) ;
if ( V_154 )
goto V_514;
F_57 ( V_3 ) ;
V_154 = F_224 ( V_3 ) ;
if ( V_154 )
goto V_515;
F_231 ( & V_16 -> V_513 ) ;
return 0 ;
V_515:
F_74 ( V_3 ) ;
V_514:
F_231 ( & V_16 -> V_513 ) ;
F_71 ( L_143 ) ;
return V_154 ;
}
static void F_232 ( struct V_5 * V_6 ,
bool V_211 , bool V_512 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_144 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_230 ( & V_16 -> V_513 ) ;
F_152 ( V_3 , 0 ) ;
F_152 ( V_3 , 1 ) ;
F_152 ( V_3 , 2 ) ;
F_152 ( V_3 , 3 ) ;
F_228 ( V_3 , V_211 , V_512 ) ;
F_74 ( V_3 ) ;
F_231 ( & V_16 -> V_513 ) ;
}
static int F_233 ( struct V_5 * V_6 , bool V_171 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_324 = V_171 ;
return 0 ;
}
static void F_234 ( const char * V_516 ,
const struct V_517 * V_33 )
{
unsigned long V_518 = V_33 -> V_519 / 4 ;
int V_520 , V_521 , V_522 , V_523 ;
V_521 = F_92 ( V_33 -> V_524 * V_33 -> V_525 , 8 ) ;
V_522 = F_92 ( V_521 + 6 , V_33 -> V_422 ) ;
V_520 = V_33 -> V_526 + V_33 -> V_413 + V_33 -> V_527 + V_33 -> V_415 + V_33 -> V_414 ;
V_523 = V_520 + V_522 ;
#define F_235 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, byteclk))
F_36 ( L_145
L_146 ,
V_516 ,
V_518 ,
V_33 -> V_526 , V_33 -> V_413 , V_33 -> V_527 , V_33 -> V_415 , V_522 , V_33 -> V_414 ,
V_520 , V_522 , V_523 ,
F_235 ( V_33 -> V_526 ) ,
F_235 ( V_33 -> V_413 ) ,
F_235 ( V_33 -> V_527 ) ,
F_235 ( V_33 -> V_415 ) ,
F_235 ( V_522 ) ,
F_235 ( V_33 -> V_414 ) ,
F_235 ( V_520 ) ,
F_235 ( V_522 ) ,
F_235 ( V_523 ) ) ;
#undef F_235
}
static void F_236 ( const char * V_516 , const struct V_386 * V_387 )
{
unsigned long V_528 = V_387 -> V_529 ;
int V_524 , V_520 , V_523 ;
V_524 = V_387 -> V_389 ;
V_520 = V_387 -> V_530 + V_387 -> V_531 + V_387 -> V_532 ;
V_523 = V_524 + V_520 ;
#define F_237 ( T_5 ) ((u32)div64_u64((u64)x * 1000000000llu, pck))
F_36 ( L_147
L_148 ,
V_516 ,
V_528 ,
V_387 -> V_530 , V_387 -> V_531 , V_524 , V_387 -> V_532 ,
V_520 , V_524 , V_523 ,
F_237 ( V_387 -> V_530 ) ,
F_237 ( V_387 -> V_531 ) ,
F_237 ( V_524 ) ,
F_237 ( V_387 -> V_532 ) ,
F_237 ( V_520 ) ,
F_237 ( V_524 ) ,
F_237 ( V_523 ) ) ;
#undef F_237
}
static void F_238 ( const char * V_516 ,
const struct V_517 * V_33 )
{
struct V_386 V_387 = { 0 } ;
unsigned long V_518 = V_33 -> V_519 / 4 ;
unsigned long V_528 ;
T_12 V_533 ;
int V_534 , V_535 ;
V_533 = ( T_12 ) V_518 * V_33 -> V_422 * 8 ;
V_528 = ( T_1 ) F_239 ( V_533 , V_33 -> V_525 ) ;
V_534 = F_92 ( F_92 ( V_33 -> V_524 * V_33 -> V_525 , 8 ) + 6 , V_33 -> V_422 ) ;
V_535 = V_33 -> V_526 + V_33 -> V_413 + V_33 -> V_527 + V_33 -> V_415 + V_534 + V_33 -> V_414 ;
V_387 . V_529 = V_528 ;
V_387 . V_530 = F_239 ( ( T_12 ) ( V_33 -> V_413 + V_33 -> V_527 ) * V_528 , V_518 ) ;
V_387 . V_531 = F_239 ( ( T_12 ) V_33 -> V_415 * V_528 , V_518 ) ;
V_387 . V_532 = F_239 ( ( T_12 ) V_33 -> V_414 * V_528 , V_518 ) ;
V_387 . V_389 = V_33 -> V_524 ;
F_236 ( V_516 , & V_387 ) ;
}
static bool F_240 ( int V_536 , int V_537 , unsigned long V_538 ,
unsigned long V_528 , void * V_26 )
{
struct V_539 * V_540 = V_26 ;
struct V_386 * V_387 = & V_540 -> V_387 ;
V_540 -> V_487 . V_488 = V_536 ;
V_540 -> V_487 . V_490 = V_537 ;
V_540 -> V_487 . V_538 = V_538 ;
V_540 -> V_487 . V_528 = V_528 ;
* V_387 = * V_540 -> V_541 -> V_387 ;
V_387 -> V_529 = V_528 ;
V_387 -> V_389 = V_540 -> V_541 -> V_387 -> V_389 ;
V_387 -> V_447 = V_540 -> V_541 -> V_387 -> V_447 ;
V_387 -> V_530 = V_387 -> V_532 = V_387 -> V_531 = V_387 -> V_542 = 1 ;
V_387 -> V_543 = V_387 -> V_544 = 0 ;
return true ;
}
static bool F_241 ( int V_545 , unsigned long V_546 ,
void * V_26 )
{
struct V_539 * V_540 = V_26 ;
V_540 -> V_547 . V_205 [ V_177 ] = V_545 ;
V_540 -> V_547 . V_176 [ V_177 ] = V_546 ;
return F_242 ( V_546 , V_540 -> V_548 , V_540 -> V_549 ,
F_240 , V_540 ) ;
}
static bool F_243 ( int V_221 , int V_222 , unsigned long V_220 ,
unsigned long V_179 , void * V_26 )
{
struct V_539 * V_540 = V_26 ;
V_540 -> V_547 . V_221 = V_221 ;
V_540 -> V_547 . V_222 = V_222 ;
V_540 -> V_547 . V_220 = V_220 ;
V_540 -> V_547 . V_179 = V_179 ;
return F_244 ( V_540 -> V_174 , V_179 , V_540 -> V_548 ,
F_94 ( V_550 ) ,
F_241 , V_540 ) ;
}
static bool F_245 ( struct V_1 * V_16 ,
const struct V_551 * V_552 ,
struct V_539 * V_540 )
{
unsigned long V_219 ;
int V_525 , V_422 ;
unsigned long V_553 , V_554 ;
unsigned long V_528 , V_555 ;
V_219 = F_90 ( V_16 -> V_174 . V_219 ) ;
V_525 = F_25 ( V_552 -> V_556 ) ;
V_422 = V_16 -> V_269 - 1 ;
V_528 = V_552 -> V_387 -> V_529 ;
V_528 = V_528 * 3 / 2 ;
V_555 = V_528 * V_525 / 8 / V_422 ;
memset ( V_540 , 0 , sizeof( * V_540 ) ) ;
V_540 -> V_3 = V_16 -> V_156 ;
V_540 -> V_174 = & V_16 -> V_174 ;
V_540 -> V_541 = V_552 ;
V_540 -> V_548 = V_528 ;
V_540 -> V_557 = V_528 ;
V_540 -> V_549 = V_528 * 3 / 2 ;
V_553 = F_189 ( V_552 -> V_558 * 4 , V_555 * 4 * 4 ) ;
V_554 = V_552 -> V_559 * 4 ;
return F_246 ( V_540 -> V_174 , V_219 ,
V_553 , V_554 ,
F_243 , V_540 ) ;
}
static bool F_247 ( struct V_539 * V_540 )
{
struct V_1 * V_16 = F_1 ( V_540 -> V_3 ) ;
const struct V_551 * V_552 = V_540 -> V_541 ;
int V_525 = F_25 ( V_552 -> V_556 ) ;
int V_422 = V_16 -> V_269 - 1 ;
unsigned long V_519 = V_540 -> V_547 . V_179 / 4 ;
unsigned long V_518 = V_519 / 4 ;
unsigned long V_560 , V_548 , V_557 , V_549 ;
int V_561 ;
int V_562 , V_563 ;
int V_564 , V_565 ;
int V_535 , V_534 , V_566 , V_526 , V_527 ;
int V_414 , V_413 , V_415 ;
const struct V_386 * V_567 ;
struct V_386 * V_568 ;
struct V_517 * V_569 ;
T_12 V_533 , V_570 ;
V_533 = ( T_12 ) V_518 * V_422 * 8 ;
V_567 = V_552 -> V_387 ;
V_548 = V_540 -> V_548 ;
V_549 = V_540 -> V_549 ;
V_557 = V_540 -> V_557 ;
V_560 = V_540 -> V_487 . V_528 ;
V_570 = ( T_12 ) V_560 * V_525 ;
V_561 = V_567 -> V_389 ;
V_563 = V_567 -> V_532 + V_567 -> V_531 +
V_567 -> V_530 ;
V_562 = V_561 + V_563 ;
V_534 = F_92 ( F_92 ( V_561 * V_525 , 8 ) + 6 , V_422 ) ;
if ( V_16 -> V_388 < V_561 * V_525 / 8 ) {
if ( V_570 != V_533 )
return false ;
} else {
if ( V_570 < V_533 )
return false ;
}
if ( V_533 < ( T_12 ) V_525 * V_548 )
return false ;
if ( V_552 -> V_391 != V_571 ) {
if ( V_533 > ( T_12 ) V_525 * V_549 )
return false ;
}
V_526 = F_92 ( 4 , V_422 ) ;
if ( V_552 -> V_391 == V_392 ) {
if ( V_422 == 3 && V_567 -> V_530 == 0 )
V_527 = 1 ;
else
V_527 = F_92 ( 4 , V_422 ) ;
} else {
V_527 = 0 ;
}
V_535 = F_239 ( ( T_12 ) V_562 * V_518 , V_557 ) ;
if ( V_535 < V_526 + V_527 + V_534 )
return false ;
V_566 = V_535 - V_534 ;
V_564 = F_239 ( ( T_12 ) V_535 * V_560 , V_518 ) ;
if ( ( T_12 ) V_535 * V_560 != ( T_12 ) V_564 * V_518 )
return false ;
V_565 = V_564 - V_561 ;
V_569 = & V_540 -> V_569 ;
memset ( V_569 , 0 , sizeof( * V_569 ) ) ;
V_569 -> V_519 = V_519 ;
V_569 -> V_422 = V_422 ;
V_569 -> V_525 = V_525 ;
if ( V_552 -> V_391 != V_392 ) {
V_413 = 0 ;
} else if ( V_422 == 3 && V_567 -> V_530 == 0 ) {
V_413 = 0 ;
} else {
V_413 = F_239 ( ( T_12 ) V_567 -> V_530 * V_518 , V_557 ) ;
V_413 = F_189 ( V_413 - V_527 , 1 ) ;
}
V_415 = F_239 ( ( T_12 ) V_567 -> V_531 * V_518 , V_557 ) ;
V_415 = F_189 ( V_415 , 1 ) ;
V_414 = V_566 - ( V_526 + V_413 + V_527 + V_415 ) ;
if ( V_414 < 1 ) {
int V_33 ;
V_33 = 1 - V_414 ;
V_415 = F_189 ( V_415 - V_33 , 1 ) ;
V_414 = V_566 - ( V_526 + V_413 + V_527 + V_415 ) ;
if ( V_414 < 1 && V_413 > 0 ) {
V_33 = 1 - V_414 ;
V_413 = F_189 ( V_413 - V_33 , 1 ) ;
V_414 = V_566 - ( V_526 + V_413 + V_527 + V_415 ) ;
}
}
if ( V_414 < 1 )
return false ;
V_569 -> V_526 = V_526 ;
V_569 -> V_413 = V_413 ;
V_569 -> V_527 = V_527 ;
V_569 -> V_415 = V_415 ;
V_569 -> V_524 = V_561 ;
V_569 -> V_414 = V_414 ;
V_569 -> V_440 = V_567 -> V_542 ;
V_569 -> V_442 = V_567 -> V_544 ;
V_569 -> V_572 = V_567 -> V_447 ;
V_569 -> V_441 = V_567 -> V_543 ;
V_569 -> V_391 = V_552 -> V_391 ;
V_569 -> V_393 = 0 ;
V_569 -> V_396 = 1 ;
V_569 -> V_394 = 1 ;
V_569 -> V_395 = 1 ;
V_569 -> V_308 = V_552 -> V_308 ;
V_569 -> V_443 = 4 ;
V_568 = & V_540 -> V_387 ;
* V_568 = * V_567 ;
V_568 -> V_529 = V_560 ;
if ( V_552 -> V_391 == V_392 ) {
V_413 = F_239 ( ( T_12 ) V_567 -> V_530 * V_560 ,
V_557 ) ;
V_413 = F_189 ( V_413 , 1 ) ;
} else {
V_413 = 1 ;
}
V_415 = F_239 ( ( T_12 ) V_567 -> V_531 * V_560 , V_557 ) ;
V_415 = F_189 ( V_415 , 1 ) ;
V_414 = V_565 - V_413 - V_415 ;
if ( V_414 < 1 ) {
int V_33 ;
V_33 = 1 - V_414 ;
V_415 = F_189 ( V_415 - V_33 , 1 ) ;
V_414 = V_565 - V_413 - V_415 ;
if ( V_414 < 1 ) {
V_33 = 1 - V_414 ;
V_413 = F_189 ( V_413 - V_33 , 1 ) ;
V_414 = V_565 - V_413 - V_415 ;
}
}
if ( V_414 < 1 )
return false ;
V_568 -> V_532 = V_414 ;
V_568 -> V_530 = V_413 ;
V_568 -> V_531 = V_415 ;
return true ;
}
static bool F_248 ( int V_536 , int V_537 , unsigned long V_538 ,
unsigned long V_528 , void * V_26 )
{
struct V_539 * V_540 = V_26 ;
V_540 -> V_487 . V_488 = V_536 ;
V_540 -> V_487 . V_490 = V_537 ;
V_540 -> V_487 . V_538 = V_538 ;
V_540 -> V_487 . V_528 = V_528 ;
if ( F_247 ( V_540 ) == false )
return false ;
#ifdef F_249
F_236 ( L_149 , & V_540 -> V_387 ) ;
F_234 ( L_150 , & V_540 -> V_569 ) ;
F_236 ( L_151 , V_540 -> V_541 -> V_387 ) ;
F_238 ( L_152 , & V_540 -> V_569 ) ;
#endif
return true ;
}
static bool F_250 ( int V_545 , unsigned long V_546 ,
void * V_26 )
{
struct V_539 * V_540 = V_26 ;
unsigned long V_573 ;
V_540 -> V_547 . V_205 [ V_177 ] = V_545 ;
V_540 -> V_547 . V_176 [ V_177 ] = V_546 ;
if ( V_540 -> V_541 -> V_391 == V_571 )
V_573 = V_540 -> V_549 + 10000000 ;
else
V_573 = V_540 -> V_549 ;
return F_242 ( V_546 , V_540 -> V_548 , V_573 ,
F_248 , V_540 ) ;
}
static bool F_251 ( int V_221 , int V_222 , unsigned long V_220 ,
unsigned long V_179 , void * V_26 )
{
struct V_539 * V_540 = V_26 ;
V_540 -> V_547 . V_221 = V_221 ;
V_540 -> V_547 . V_222 = V_222 ;
V_540 -> V_547 . V_220 = V_220 ;
V_540 -> V_547 . V_179 = V_179 ;
return F_244 ( V_540 -> V_174 , V_179 , V_540 -> V_548 ,
F_94 ( V_550 ) ,
F_250 , V_540 ) ;
}
static bool F_252 ( struct V_1 * V_16 ,
const struct V_551 * V_552 ,
struct V_539 * V_540 )
{
const struct V_386 * V_387 = V_552 -> V_387 ;
unsigned long V_219 ;
unsigned long V_553 ;
unsigned long V_554 ;
int V_422 = V_16 -> V_269 - 1 ;
int V_525 = F_25 ( V_552 -> V_556 ) ;
unsigned long V_574 ;
V_219 = F_90 ( V_16 -> V_174 . V_219 ) ;
memset ( V_540 , 0 , sizeof( * V_540 ) ) ;
V_540 -> V_3 = V_16 -> V_156 ;
V_540 -> V_174 = & V_16 -> V_174 ;
V_540 -> V_541 = V_552 ;
V_540 -> V_548 = V_387 -> V_529 - 1000 ;
V_540 -> V_557 = V_387 -> V_529 ;
V_540 -> V_549 = V_387 -> V_529 + 1000 ;
V_574 = F_239 ( ( T_12 ) V_540 -> V_548 * V_525 , V_422 * 8 ) ;
V_553 = F_189 ( V_552 -> V_558 * 4 , V_574 * 4 * 4 ) ;
if ( V_552 -> V_391 == V_571 ) {
V_554 = V_552 -> V_559 * 4 ;
} else {
unsigned long V_575 ;
V_575 = F_239 ( ( T_12 ) V_540 -> V_549 * V_525 ,
V_422 * 8 ) ;
V_554 = V_575 * 4 * 4 ;
}
return F_246 ( V_540 -> V_174 , V_219 ,
V_553 , V_554 ,
F_251 , V_540 ) ;
}
static int F_253 ( struct V_5 * V_6 ,
const struct V_551 * V_541 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_539 V_540 ;
bool V_298 ;
int V_154 ;
F_230 ( & V_16 -> V_513 ) ;
V_16 -> V_385 = V_541 -> V_556 ;
V_16 -> V_305 = V_541 -> V_305 ;
if ( V_541 -> V_305 == V_306 )
V_298 = F_252 ( V_16 , V_541 , & V_540 ) ;
else
V_298 = F_245 ( V_16 , V_541 , & V_540 ) ;
if ( ! V_298 ) {
F_44 ( L_153 ) ;
V_154 = - V_152 ;
goto V_332;
}
F_100 ( & V_540 . V_547 ) ;
V_154 = F_91 ( V_540 . V_547 . V_176 [ V_178 ] ,
V_541 -> V_184 , V_541 -> V_185 , & V_16 -> V_192 ) ;
if ( V_154 ) {
F_44 ( L_154 ) ;
goto V_332;
}
V_16 -> V_424 = V_540 . V_547 ;
V_16 -> V_489 = V_540 . V_487 ;
V_16 -> V_387 = V_540 . V_387 ;
V_16 -> V_307 = V_540 . V_569 ;
F_231 ( & V_16 -> V_513 ) ;
return 0 ;
V_332:
F_231 ( & V_16 -> V_513 ) ;
return V_154 ;
}
static enum V_458 F_254 ( int V_180 )
{
switch ( F_255 () ) {
case V_576 :
case V_577 :
F_256 ( L_155 ) ;
return V_578 ;
case V_579 :
case V_580 :
case V_581 :
case V_582 :
return V_578 ;
case V_583 :
case V_584 :
case V_585 :
switch ( V_180 ) {
case 0 :
return V_578 ;
case 1 :
return V_586 ;
default:
F_256 ( L_156 ) ;
return V_578 ;
}
case V_587 :
switch ( V_180 ) {
case 0 :
return V_578 ;
case 1 :
return V_588 ;
default:
F_256 ( L_156 ) ;
return V_578 ;
}
default:
F_256 ( L_157 ) ;
return V_578 ;
}
}
static int F_257 ( struct V_5 * V_6 , int * V_74 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_108 ;
for ( V_108 = 0 ; V_108 < F_47 ( V_16 -> V_148 ) ; V_108 ++ ) {
if ( ! V_16 -> V_148 [ V_108 ] . V_6 ) {
V_16 -> V_148 [ V_108 ] . V_6 = V_6 ;
* V_74 = V_108 ;
return 0 ;
}
}
F_44 ( L_158 , V_6 -> V_45 ) ;
return - V_589 ;
}
static int F_258 ( struct V_5 * V_6 , int V_74 , int V_346 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_346 < 0 || V_346 > 3 ) {
F_44 ( L_159 ) ;
return - V_152 ;
}
if ( V_74 < 0 || V_74 > 3 ) {
F_44 ( L_160 ) ;
return - V_152 ;
}
if ( V_16 -> V_148 [ V_74 ] . V_6 != V_6 ) {
F_44 ( L_161 ,
V_6 -> V_45 ) ;
return - V_152 ;
}
V_16 -> V_148 [ V_74 ] . V_346 = V_346 ;
return 0 ;
}
static void F_259 ( struct V_5 * V_6 , int V_74 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ( V_74 >= 0 && V_74 <= 3 ) &&
V_16 -> V_148 [ V_74 ] . V_6 == V_6 ) {
V_16 -> V_148 [ V_74 ] . V_6 = NULL ;
V_16 -> V_148 [ V_74 ] . V_346 = 0 ;
}
}
static int F_260 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_590 * V_590 ;
V_590 = F_261 ( & V_3 -> V_4 , L_162 ) ;
if ( F_78 ( V_590 ) ) {
F_44 ( L_163 ) ;
return F_79 ( V_590 ) ;
}
V_16 -> V_182 = V_590 ;
return 0 ;
}
static int F_262 ( struct V_5 * V_6 ,
struct V_5 * V_591 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
enum V_458 V_459 = V_6 -> V_459 ;
int V_154 ;
V_154 = F_76 ( V_3 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_263 ( V_459 , V_6 ) ;
if ( V_154 )
return V_154 ;
V_154 = F_264 ( V_6 , V_591 ) ;
if ( V_154 ) {
F_44 ( L_164 ,
V_6 -> V_45 ) ;
F_265 ( V_459 , V_6 ) ;
return V_154 ;
}
return 0 ;
}
static void F_266 ( struct V_5 * V_6 ,
struct V_5 * V_591 )
{
enum V_458 V_459 = V_6 -> V_459 ;
F_73 ( V_591 != V_6 -> V_591 ) ;
if ( V_591 != V_6 -> V_591 )
return;
F_267 ( V_6 ) ;
F_265 ( V_459 , V_6 ) ;
}
static void F_268 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_460 ;
V_8 -> V_4 = & V_3 -> V_4 ;
V_8 -> V_10 = V_16 -> V_180 == 0 ?
V_11 : V_12 ;
V_8 -> V_592 = V_593 ;
V_8 -> V_45 = V_16 -> V_180 == 0 ? L_165 : L_166 ;
V_8 -> V_459 = F_254 ( V_16 -> V_180 ) ;
V_8 -> V_594 . V_16 = & V_595 ;
V_8 -> V_596 = V_597 ;
F_269 ( V_8 ) ;
}
static void F_270 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_460 ;
F_271 ( V_8 ) ;
}
static int F_272 ( struct V_2 * V_156 )
{
struct V_598 * V_599 = V_156 -> V_4 . V_600 ;
struct V_1 * V_16 = F_1 ( V_156 ) ;
struct V_601 * V_602 ;
T_1 V_603 [ 10 ] ;
int V_343 , V_450 ;
int V_154 , V_108 ;
struct V_598 * V_604 ;
struct V_448 V_449 ;
V_604 = F_273 ( V_599 , 0 , 0 ) ;
if ( ! V_604 )
return 0 ;
V_602 = F_274 ( V_604 , L_167 , & V_343 ) ;
if ( V_602 == NULL ) {
F_275 ( & V_156 -> V_4 , L_168 ) ;
V_154 = - V_152 ;
goto V_332;
}
V_450 = V_343 / sizeof( T_1 ) ;
if ( V_450 < 4 || V_450 % 2 != 0 ||
V_450 > V_16 -> V_273 * 2 ) {
F_275 ( & V_156 -> V_4 , L_169 ) ;
V_154 = - V_152 ;
goto V_332;
}
V_154 = F_276 ( V_604 , L_167 , V_603 , V_450 ) ;
if ( V_154 ) {
F_275 ( & V_156 -> V_4 , L_170 ) ;
goto V_332;
}
V_449 . V_450 = V_450 ;
for ( V_108 = 0 ; V_108 < V_450 ; ++ V_108 )
V_449 . V_451 [ V_108 ] = ( int ) V_603 [ V_108 ] ;
V_154 = F_194 ( & V_16 -> V_460 , & V_449 ) ;
if ( V_154 ) {
F_275 ( & V_156 -> V_4 , L_171 ) ;
goto V_332;
}
F_277 ( V_604 ) ;
return 0 ;
V_332:
F_277 ( V_604 ) ;
return V_154 ;
}
static int F_278 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_206 * V_174 = & V_16 -> V_174 ;
struct V_590 * V_590 ;
int V_154 ;
V_590 = F_261 ( & V_3 -> V_4 , L_172 ) ;
if ( F_78 ( V_590 ) ) {
F_44 ( L_173 ) ;
return F_79 ( V_590 ) ;
}
V_174 -> V_45 = V_16 -> V_180 == 0 ? L_174 : L_175 ;
V_174 -> V_10 = V_16 -> V_180 == 0 ? V_605 : V_606 ;
V_174 -> V_219 = V_590 ;
V_174 -> V_17 = V_16 -> V_23 ;
switch ( F_255 () ) {
case V_579 :
case V_580 :
case V_581 :
case V_582 :
V_174 -> V_607 = & V_608 ;
break;
case V_583 :
case V_584 :
case V_585 :
V_174 -> V_607 = & V_609 ;
break;
case V_587 :
V_174 -> V_607 = & V_610 ;
break;
default:
return - V_201 ;
}
V_174 -> V_594 = & V_611 ;
V_154 = F_279 ( V_174 ) ;
if ( V_154 )
return V_154 ;
return 0 ;
}
static int F_280 ( struct V_612 * V_4 , struct V_612 * V_613 , void * V_26 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
T_1 V_614 ;
int V_154 , V_108 ;
struct V_1 * V_16 ;
struct V_615 * V_616 ;
struct V_615 * V_617 ;
struct V_615 V_618 ;
V_16 = F_281 ( & V_3 -> V_4 , sizeof( * V_16 ) , V_619 ) ;
if ( ! V_16 )
return - V_620 ;
V_16 -> V_156 = V_3 ;
F_282 ( & V_3 -> V_4 , V_16 ) ;
F_283 ( & V_16 -> V_135 ) ;
F_283 ( & V_16 -> V_116 ) ;
V_16 -> V_117 = 0 ;
#ifdef F_284
F_283 ( & V_16 -> V_109 ) ;
V_16 -> V_110 . V_230 = V_34 ;
#endif
F_285 ( & V_16 -> V_513 ) ;
F_286 ( & V_16 -> V_24 , 1 ) ;
F_287 ( & V_16 -> V_478 ,
F_210 ) ;
#ifdef F_50
F_288 ( & V_16 -> V_140 ) ;
V_16 -> V_140 . V_275 = F_207 ;
V_16 -> V_140 . V_26 = 0 ;
#endif
V_617 = F_289 ( V_3 , V_621 , L_176 ) ;
if ( ! V_617 ) {
V_617 = F_290 ( V_3 , V_621 , 0 ) ;
if ( ! V_617 ) {
F_44 ( L_177 ) ;
return - V_152 ;
}
V_618 . T_9 = V_617 -> T_9 ;
V_618 . T_10 = V_618 . T_9 + V_622 - 1 ;
V_617 = & V_618 ;
}
V_616 = V_617 ;
V_16 -> V_19 = F_291 ( & V_3 -> V_4 , V_617 -> T_9 ,
F_292 ( V_617 ) ) ;
if ( ! V_16 -> V_19 ) {
F_44 ( L_178 ) ;
return - V_620 ;
}
V_617 = F_289 ( V_3 , V_621 , L_179 ) ;
if ( ! V_617 ) {
V_617 = F_290 ( V_3 , V_621 , 0 ) ;
if ( ! V_617 ) {
F_44 ( L_177 ) ;
return - V_152 ;
}
V_618 . T_9 = V_617 -> T_9 + V_623 ;
V_618 . T_10 = V_618 . T_9 + V_624 - 1 ;
V_617 = & V_618 ;
}
V_16 -> V_21 = F_291 ( & V_3 -> V_4 , V_617 -> T_9 ,
F_292 ( V_617 ) ) ;
if ( ! V_16 -> V_21 ) {
F_44 ( L_180 ) ;
return - V_620 ;
}
V_617 = F_289 ( V_3 , V_621 , L_181 ) ;
if ( ! V_617 ) {
V_617 = F_290 ( V_3 , V_621 , 0 ) ;
if ( ! V_617 ) {
F_44 ( L_177 ) ;
return - V_152 ;
}
V_618 . T_9 = V_617 -> T_9 + V_625 ;
V_618 . T_10 = V_618 . T_9 + V_626 - 1 ;
V_617 = & V_618 ;
}
V_16 -> V_23 = F_291 ( & V_3 -> V_4 , V_617 -> T_9 ,
F_292 ( V_617 ) ) ;
if ( ! V_16 -> V_23 ) {
F_44 ( L_182 ) ;
return - V_620 ;
}
V_16 -> V_132 = F_293 ( V_16 -> V_156 , 0 ) ;
if ( V_16 -> V_132 < 0 ) {
F_44 ( L_183 ) ;
return - V_201 ;
}
V_154 = F_294 ( & V_3 -> V_4 , V_16 -> V_132 , F_48 ,
V_627 , F_295 ( & V_3 -> V_4 ) , V_16 -> V_156 ) ;
if ( V_154 < 0 ) {
F_44 ( L_184 ) ;
return V_154 ;
}
if ( V_3 -> V_4 . V_600 ) {
const struct V_628 * V_629 ;
const struct V_630 * V_631 ;
V_629 = F_296 ( V_632 , V_3 -> V_4 . V_600 ) ;
if ( ! V_629 ) {
F_44 ( L_185 ) ;
return - V_201 ;
}
V_631 = V_629 -> V_26 ;
while ( V_631 -> V_633 != 0 && V_631 -> V_633 != V_616 -> T_9 )
V_631 ++ ;
if ( V_631 -> V_633 == 0 ) {
F_44 ( L_185 ) ;
return - V_201 ;
}
V_16 -> V_180 = V_631 -> V_10 ;
} else {
V_16 -> V_180 = V_3 -> V_10 ;
}
for ( V_108 = 0 ; V_108 < F_47 ( V_16 -> V_148 ) ; V_108 ++ ) {
V_16 -> V_148 [ V_108 ] . V_326 = V_328 ;
V_16 -> V_148 [ V_108 ] . V_6 = NULL ;
V_16 -> V_148 [ V_108 ] . V_346 = 0 ;
}
V_154 = F_260 ( V_3 ) ;
if ( V_154 )
return V_154 ;
F_278 ( V_3 ) ;
F_297 ( & V_3 -> V_4 ) ;
V_154 = F_70 ( V_3 ) ;
if ( V_154 )
goto V_634;
V_614 = F_9 ( V_3 , V_231 ) ;
F_298 ( & V_3 -> V_4 , L_186 ,
F_98 ( V_614 , 7 , 4 ) , F_98 ( V_614 , 3 , 0 ) ) ;
if ( F_81 ( V_259 ) )
V_16 -> V_273 = 1 + F_19 ( V_3 , V_260 , 11 , 9 ) ;
else
V_16 -> V_273 = 3 ;
V_16 -> V_388 = F_127 ( V_3 ) ;
F_268 ( V_3 ) ;
if ( V_3 -> V_4 . V_600 ) {
V_154 = F_272 ( V_3 ) ;
if ( V_154 ) {
F_44 ( L_187 ) ;
goto V_635;
}
V_154 = F_299 ( V_3 -> V_4 . V_600 , NULL , NULL ,
& V_3 -> V_4 ) ;
if ( V_154 )
F_44 ( L_188 , V_154 ) ;
}
F_74 ( V_3 ) ;
if ( V_16 -> V_180 == 0 )
F_300 ( L_189 , F_124 ) ;
else if ( V_16 -> V_180 == 1 )
F_300 ( L_190 , F_125 ) ;
#ifdef F_284
if ( V_16 -> V_180 == 0 )
F_300 ( L_191 , F_115 ) ;
else if ( V_16 -> V_180 == 1 )
F_300 ( L_192 , F_116 ) ;
#endif
return 0 ;
V_635:
F_270 ( V_3 ) ;
F_74 ( V_3 ) ;
V_634:
F_301 ( & V_3 -> V_4 ) ;
return V_154 ;
}
static void F_302 ( struct V_612 * V_4 , struct V_612 * V_613 , void * V_26 )
{
struct V_2 * V_3 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_303 ( & V_3 -> V_4 ) ;
F_73 ( V_16 -> V_195 > 0 ) ;
F_304 ( & V_16 -> V_174 ) ;
F_270 ( V_3 ) ;
F_301 ( & V_3 -> V_4 ) ;
if ( V_16 -> V_160 != NULL && V_16 -> V_207 ) {
F_105 ( V_16 -> V_160 ) ;
V_16 -> V_207 = false ;
}
}
static int F_305 ( struct V_2 * V_156 )
{
return F_306 ( & V_156 -> V_4 , & V_636 ) ;
}
static int F_307 ( struct V_2 * V_156 )
{
F_308 ( & V_156 -> V_4 , & V_636 ) ;
return 0 ;
}
static int F_309 ( struct V_612 * V_4 )
{
struct V_2 * V_156 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_156 ) ;
V_16 -> V_133 = false ;
F_310 () ;
F_311 ( V_16 -> V_132 ) ;
F_312 () ;
return 0 ;
}
static int F_313 ( struct V_612 * V_4 )
{
struct V_2 * V_156 = F_4 ( V_4 ) ;
struct V_1 * V_16 = F_1 ( V_156 ) ;
int V_154 ;
V_154 = F_314 () ;
if ( V_154 )
return V_154 ;
V_16 -> V_133 = true ;
F_310 () ;
return 0 ;
}
int T_13 F_315 ( void )
{
return F_316 ( & V_637 ) ;
}
void F_317 ( void )
{
F_318 ( & V_637 ) ;
}
