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
F_8 ( V_15 , V_16 -> V_17 + V_14 . V_14 ) ;
}
static inline T_1 F_9 ( struct V_2 * V_3 ,
const struct V_13 V_14 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return F_10 ( V_16 -> V_17 + V_14 . V_14 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_12 ( & V_16 -> V_18 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_14 ( & V_16 -> V_18 ) ;
}
static bool F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_18 . V_19 == 0 ;
}
static void F_16 ( void * V_20 , T_1 V_21 )
{
F_17 ( (struct V_22 * ) V_20 ) ;
}
static inline int F_18 ( struct V_2 * V_3 ,
const struct V_13 V_14 , int V_23 , int V_24 )
{
unsigned long V_25 ;
T_2 V_26 ;
int V_27 ;
V_27 = 100 ;
while ( V_27 -- > 0 ) {
if ( F_19 ( V_3 , V_14 , V_23 , V_23 ) == V_24 )
return V_24 ;
}
V_25 = V_28 + F_20 ( 500 ) ;
while ( F_21 ( V_28 , V_25 ) ) {
if ( F_19 ( V_3 , V_14 , V_23 , V_23 ) == V_24 )
return V_24 ;
V_26 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_29 ) ;
F_24 ( & V_26 , V_30 ) ;
}
return ! V_24 ;
}
T_3 F_25 ( enum V_31 V_32 )
{
switch ( V_32 ) {
case V_33 :
case V_34 :
return 24 ;
case V_35 :
return 18 ;
case V_36 :
return 16 ;
default:
F_26 () ;
return 0 ;
}
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_37 = F_28 () ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_38 = F_28 () ;
}
static void F_30 ( struct V_2 * V_3 , const char * V_39 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_2 V_27 , V_40 , V_41 ;
T_1 V_42 ;
T_1 V_43 , V_44 , V_45 ;
if ( ! V_46 )
return;
V_27 = F_28 () ;
V_40 = F_31 ( V_16 -> V_38 , V_16 -> V_37 ) ;
V_43 = ( T_1 ) F_32 ( V_40 ) ;
if ( V_43 == 0 )
V_43 = 1 ;
V_41 = F_31 ( V_27 , V_16 -> V_38 ) ;
V_44 = ( T_1 ) F_32 ( V_41 ) ;
if ( V_44 == 0 )
V_44 = 1 ;
V_45 = V_43 + V_44 ;
V_42 = V_16 -> V_47 ;
F_33 ( V_48 L_1
L_2 ,
V_39 ,
V_43 ,
V_44 ,
V_45 ,
1000 * 1000 / V_45 ,
V_42 ,
V_42 * 1000 / V_45 ) ;
}
static inline void F_27 ( struct V_2 * V_3 )
{
}
static inline void F_29 ( struct V_2 * V_3 )
{
}
static inline void F_30 ( struct V_2 * V_3 ,
const char * V_39 )
{
}
static void F_34 ( T_1 V_49 )
{
if ( V_49 == 0 )
return;
if ( ! V_50 && ( V_49 & ~ V_51 ) == 0 )
return;
#define F_35 ( T_4 ) (status & DSI_IRQ_##x) ? (#x " ") : ""
F_36 ( L_3 ,
V_49 ,
V_50 ? F_35 ( V_52 ) : L_4 ,
V_50 ? F_35 ( V_53 ) : L_4 ,
V_50 ? F_35 ( V_54 ) : L_4 ,
V_50 ? F_35 ( V_55 ) : L_4 ,
F_35 ( V_56 ) ,
F_35 ( V_57 ) ,
F_35 ( V_58 ) ,
F_35 ( V_59 ) ,
F_35 ( V_60 ) ,
F_35 ( V_61 ) ,
F_35 ( V_62 ) ,
F_35 ( V_63 ) ,
F_35 ( V_64 ) ,
F_35 ( V_65 ) ,
F_35 ( V_66 ) ,
F_35 ( V_67 ) ,
F_35 ( V_68 ) ) ;
#undef F_35
}
static void F_37 ( int V_69 , T_1 V_49 )
{
if ( V_49 == 0 )
return;
if ( ! V_50 && ( V_49 & ~ V_70 ) == 0 )
return;
#define F_35 ( T_4 ) (status & DSI_VC_IRQ_##x) ? (#x " ") : ""
F_36 ( L_5 ,
V_69 ,
V_49 ,
F_35 ( V_71 ) ,
F_35 ( V_72 ) ,
F_35 ( V_73 ) ,
V_50 ? F_35 ( V_74 ) : L_4 ,
F_35 ( V_75 ) ,
F_35 ( V_76 ) ,
F_35 ( V_77 ) ,
F_35 ( V_78 ) ,
F_35 ( V_79 ) ) ;
#undef F_35
}
static void F_38 ( T_1 V_49 )
{
if ( V_49 == 0 )
return;
#define F_35 ( T_4 ) (status & DSI_CIO_IRQ_##x) ? (#x " ") : ""
F_36 ( L_6 ,
V_49 ,
F_35 ( V_80 ) ,
F_35 ( V_81 ) ,
F_35 ( V_82 ) ,
F_35 ( V_83 ) ,
F_35 ( V_84 ) ,
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
F_35 ( V_99 ) ) ;
#undef F_35
}
static void F_39 ( struct V_2 * V_3 , T_1 V_100 ,
T_1 * V_101 , T_1 V_102 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_103 ;
F_40 ( & V_16 -> V_104 ) ;
V_16 -> V_105 . V_106 ++ ;
F_41 ( V_100 , V_16 -> V_105 . V_107 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 )
F_41 ( V_101 [ V_103 ] , V_16 -> V_105 . V_108 [ V_103 ] ) ;
F_41 ( V_102 , V_16 -> V_105 . V_109 ) ;
F_42 ( & V_16 -> V_104 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_1 V_100 ,
T_1 * V_101 , T_1 V_102 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_103 ;
if ( V_100 & V_110 ) {
F_44 ( L_7 , V_100 ) ;
F_34 ( V_100 ) ;
F_40 ( & V_16 -> V_111 ) ;
V_16 -> V_112 |= V_100 & V_110 ;
F_42 ( & V_16 -> V_111 ) ;
} else if ( V_113 ) {
F_34 ( V_100 ) ;
}
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
if ( V_101 [ V_103 ] & V_114 ) {
F_44 ( L_8 ,
V_103 , V_101 [ V_103 ] ) ;
F_37 ( V_103 , V_101 [ V_103 ] ) ;
} else if ( V_113 ) {
F_37 ( V_103 , V_101 [ V_103 ] ) ;
}
}
if ( V_102 & V_115 ) {
F_44 ( L_9 , V_102 ) ;
F_38 ( V_102 ) ;
} else if ( V_113 ) {
F_38 ( V_102 ) ;
}
}
static void F_45 ( struct V_116 * V_117 ,
unsigned V_118 , T_1 V_100 )
{
struct V_116 * V_119 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_118 ; V_103 ++ ) {
V_119 = & V_117 [ V_103 ] ;
if ( V_119 -> V_120 && V_119 -> V_21 & V_100 )
V_119 -> V_120 ( V_119 -> V_121 , V_100 ) ;
}
}
static void F_46 ( struct V_122 * V_123 ,
T_1 V_100 , T_1 * V_101 , T_1 V_102 )
{
int V_103 ;
F_45 ( V_123 -> V_124 ,
F_47 ( V_123 -> V_124 ) ,
V_100 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
if ( V_101 [ V_103 ] == 0 )
continue;
F_45 ( V_123 -> V_125 [ V_103 ] ,
F_47 ( V_123 -> V_125 [ V_103 ] ) ,
V_101 [ V_103 ] ) ;
}
if ( V_102 != 0 )
F_45 ( V_123 -> V_126 ,
F_47 ( V_123 -> V_126 ) ,
V_102 ) ;
}
static T_5 F_48 ( int V_127 , void * V_121 )
{
struct V_2 * V_3 ;
struct V_1 * V_16 ;
T_1 V_100 , V_101 [ 4 ] , V_102 ;
int V_103 ;
V_3 = (struct V_2 * ) V_121 ;
V_16 = F_1 ( V_3 ) ;
F_40 ( & V_16 -> V_128 ) ;
V_100 = F_9 ( V_3 , V_129 ) ;
if ( ! V_100 ) {
F_42 ( & V_16 -> V_128 ) ;
return V_130 ;
}
F_7 ( V_3 , V_129 , V_100 & ~ V_51 ) ;
F_9 ( V_3 , V_129 ) ;
for ( V_103 = 0 ; V_103 < 4 ; ++ V_103 ) {
if ( ( V_100 & ( 1 << V_103 ) ) == 0 ) {
V_101 [ V_103 ] = 0 ;
continue;
}
V_101 [ V_103 ] = F_9 ( V_3 , F_49 ( V_103 ) ) ;
F_7 ( V_3 , F_49 ( V_103 ) , V_101 [ V_103 ] ) ;
F_9 ( V_3 , F_49 ( V_103 ) ) ;
}
if ( V_100 & V_131 ) {
V_102 = F_9 ( V_3 , V_132 ) ;
F_7 ( V_3 , V_132 , V_102 ) ;
F_9 ( V_3 , V_132 ) ;
} else {
V_102 = 0 ;
}
#ifdef F_50
if ( V_100 & V_133 )
F_51 ( & V_16 -> V_134 ) ;
#endif
memcpy ( & V_16 -> V_135 , & V_16 -> V_123 ,
sizeof( V_16 -> V_123 ) ) ;
F_42 ( & V_16 -> V_128 ) ;
F_46 ( & V_16 -> V_135 , V_100 , V_101 , V_102 ) ;
F_43 ( V_3 , V_100 , V_101 , V_102 ) ;
F_39 ( V_3 , V_100 , V_101 , V_102 ) ;
return V_136 ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_116 * V_117 ,
unsigned V_118 , T_1 V_137 ,
const struct V_13 V_138 ,
const struct V_13 V_139 )
{
struct V_116 * V_119 ;
T_1 V_21 ;
T_1 V_140 ;
int V_103 ;
V_21 = V_137 ;
for ( V_103 = 0 ; V_103 < V_118 ; V_103 ++ ) {
V_119 = & V_117 [ V_103 ] ;
if ( V_119 -> V_120 == NULL )
continue;
V_21 |= V_119 -> V_21 ;
}
V_140 = F_9 ( V_3 , V_138 ) ;
F_7 ( V_3 , V_139 , ( V_21 ^ V_140 ) & V_21 ) ;
F_7 ( V_3 , V_138 , V_21 ) ;
F_9 ( V_3 , V_138 ) ;
F_9 ( V_3 , V_139 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_21 = V_110 ;
#ifdef F_50
V_21 |= V_133 ;
#endif
F_52 ( V_3 , V_16 -> V_123 . V_124 ,
F_47 ( V_16 -> V_123 . V_124 ) , V_21 ,
V_141 , V_129 ) ;
}
static void F_54 ( struct V_2 * V_3 , int V_142 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_123 . V_125 [ V_142 ] ,
F_47 ( V_16 -> V_123 . V_125 [ V_142 ] ) ,
V_114 ,
F_55 ( V_142 ) , F_49 ( V_142 ) ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_52 ( V_3 , V_16 -> V_123 . V_126 ,
F_47 ( V_16 -> V_123 . V_126 ) ,
V_115 ,
V_143 , V_132 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_142 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
memset ( & V_16 -> V_123 , 0 , sizeof( V_16 -> V_123 ) ) ;
F_53 ( V_3 ) ;
for ( V_142 = 0 ; V_142 < 4 ; ++ V_142 )
F_54 ( V_3 , V_142 ) ;
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
}
static int F_60 ( T_6 V_120 , void * V_121 , T_1 V_21 ,
struct V_116 * V_117 , unsigned V_118 )
{
struct V_116 * V_119 ;
int V_145 ;
int V_103 ;
F_61 ( V_120 == NULL ) ;
V_145 = - 1 ;
for ( V_103 = 0 ; V_103 < V_118 ; V_103 ++ ) {
V_119 = & V_117 [ V_103 ] ;
if ( V_119 -> V_120 == V_120 && V_119 -> V_121 == V_121 &&
V_119 -> V_21 == V_21 ) {
return - V_146 ;
}
if ( V_119 -> V_120 == NULL && V_145 == - 1 )
V_145 = V_103 ;
}
if ( V_145 == - 1 )
return - V_147 ;
V_119 = & V_117 [ V_145 ] ;
V_119 -> V_120 = V_120 ;
V_119 -> V_121 = V_121 ;
V_119 -> V_21 = V_21 ;
return 0 ;
}
static int F_62 ( T_6 V_120 , void * V_121 , T_1 V_21 ,
struct V_116 * V_117 , unsigned V_118 )
{
struct V_116 * V_119 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_118 ; V_103 ++ ) {
V_119 = & V_117 [ V_103 ] ;
if ( V_119 -> V_120 != V_120 || V_119 -> V_121 != V_121 ||
V_119 -> V_21 != V_21 )
continue;
V_119 -> V_120 = NULL ;
V_119 -> V_121 = NULL ;
V_119 -> V_21 = 0 ;
return 0 ;
}
return - V_146 ;
}
static int F_63 ( struct V_2 * V_3 , T_6 V_120 ,
void * V_121 , T_1 V_21 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_148 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
V_148 = F_60 ( V_120 , V_121 , V_21 , V_16 -> V_123 . V_124 ,
F_47 ( V_16 -> V_123 . V_124 ) ) ;
if ( V_148 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
return V_148 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_6 V_120 , void * V_121 , T_1 V_21 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_148 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
V_148 = F_62 ( V_120 , V_121 , V_21 , V_16 -> V_123 . V_124 ,
F_47 ( V_16 -> V_123 . V_124 ) ) ;
if ( V_148 == 0 )
F_53 ( V_3 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
return V_148 ;
}
static int F_65 ( struct V_2 * V_3 , int V_69 ,
T_6 V_120 , void * V_121 , T_1 V_21 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_148 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
V_148 = F_60 ( V_120 , V_121 , V_21 ,
V_16 -> V_123 . V_125 [ V_69 ] ,
F_47 ( V_16 -> V_123 . V_125 [ V_69 ] ) ) ;
if ( V_148 == 0 )
F_54 ( V_3 , V_69 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
return V_148 ;
}
static int F_66 ( struct V_2 * V_3 , int V_69 ,
T_6 V_120 , void * V_121 , T_1 V_21 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_148 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
V_148 = F_62 ( V_120 , V_121 , V_21 ,
V_16 -> V_123 . V_125 [ V_69 ] ,
F_47 ( V_16 -> V_123 . V_125 [ V_69 ] ) ) ;
if ( V_148 == 0 )
F_54 ( V_3 , V_69 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
return V_148 ;
}
static int F_67 ( struct V_2 * V_3 ,
T_6 V_120 , void * V_121 , T_1 V_21 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_148 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
V_148 = F_60 ( V_120 , V_121 , V_21 , V_16 -> V_123 . V_126 ,
F_47 ( V_16 -> V_123 . V_126 ) ) ;
if ( V_148 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
return V_148 ;
}
static int F_68 ( struct V_2 * V_3 ,
T_6 V_120 , void * V_121 , T_1 V_21 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
int V_148 ;
F_58 ( & V_16 -> V_128 , V_144 ) ;
V_148 = F_62 ( V_120 , V_121 , V_21 , V_16 -> V_123 . V_126 ,
F_47 ( V_16 -> V_123 . V_126 ) ) ;
if ( V_148 == 0 )
F_56 ( V_3 ) ;
F_59 ( & V_16 -> V_128 , V_144 ) ;
return V_148 ;
}
static T_1 F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
T_1 V_149 ;
F_58 ( & V_16 -> V_111 , V_144 ) ;
V_149 = V_16 -> V_112 ;
V_16 -> V_112 = 0 ;
F_59 ( & V_16 -> V_111 , V_144 ) ;
return V_149 ;
}
int F_70 ( struct V_2 * V_3 )
{
int V_148 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_10 ) ;
V_148 = F_72 ( & V_16 -> V_150 -> V_4 ) ;
F_73 ( V_148 < 0 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 ;
F_71 ( L_11 ) ;
V_148 = F_75 ( & V_16 -> V_150 -> V_4 ) ;
F_73 ( V_148 < 0 && V_148 != - V_151 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_152 * V_153 ;
if ( V_16 -> V_154 != NULL )
return 0 ;
V_153 = F_77 ( & V_16 -> V_150 -> V_4 , L_12 ) ;
if ( F_78 ( V_153 ) )
V_153 = F_77 ( & V_16 -> V_150 -> V_4 , L_13 ) ;
if ( F_78 ( V_153 ) ) {
F_44 ( L_14 ) ;
return F_79 ( V_153 ) ;
}
V_16 -> V_154 = V_153 ;
return 0 ;
}
static inline void F_80 ( struct V_2 * V_3 ,
bool V_155 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_155 )
F_81 ( V_16 -> V_156 ) ;
else
F_82 ( V_16 -> V_156 ) ;
if ( V_155 && V_16 -> V_157 ) {
if ( F_18 ( V_3 , V_158 , 1 , 1 ) != 1 )
F_44 ( L_15 ) ;
}
}
static void F_83 ( struct V_2 * V_3 )
{
T_1 V_159 ;
int V_160 , V_161 , V_162 ;
V_159 = F_9 ( V_3 , V_163 ) ;
if ( F_84 ( V_164 ) ) {
V_160 = 28 ;
V_161 = 27 ;
V_162 = 26 ;
} else {
V_160 = 24 ;
V_161 = 25 ;
V_162 = 26 ;
}
#define F_85 ( T_7 , T_8 , T_9 ) \
FLD_GET(dsi_read_reg(dsidev, DSI_##fld), start, end)
F_36 ( L_16 ,
F_85 ( V_165 , 0 , 0 ) ,
F_85 ( V_166 , 29 , 29 ) ,
F_85 ( V_167 , V_160 , V_160 ) ,
F_85 ( V_167 , V_161 , V_161 ) ,
F_85 ( V_167 , V_162 , V_162 ) ,
F_85 ( V_167 , 29 , 29 ) ,
F_85 ( V_167 , 30 , 30 ) ,
F_85 ( V_167 , 31 , 31 ) ) ;
#undef F_85
}
static inline int F_86 ( struct V_2 * V_3 , bool V_155 )
{
F_71 ( L_17 , V_155 ) ;
V_155 = V_155 ? 1 : 0 ;
F_87 ( V_3 , V_168 , V_155 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_168 , 0 , V_155 ) != V_155 ) {
F_44 ( L_18 , V_155 ) ;
return - V_169 ;
}
return 0 ;
}
unsigned long F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_170 . V_171 ;
}
static unsigned long F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_170 . V_172 ;
}
static unsigned long F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return V_16 -> V_170 . V_173 / 16 ;
}
static unsigned long F_91 ( struct V_2 * V_3 )
{
unsigned long V_148 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( F_92 ( V_16 -> V_174 ) == V_175 ) {
V_148 = F_93 ( V_16 -> V_176 ) ;
} else {
V_148 = F_89 ( V_3 ) ;
}
return V_148 ;
}
static int F_94 ( struct V_177 * V_178 ,
unsigned long V_179 , unsigned long V_180 )
{
unsigned long V_181 = V_178 -> V_172 ;
unsigned V_182 ;
unsigned long V_183 ;
V_182 = F_95 ( V_181 , V_180 * 2 ) ;
V_183 = V_181 / 2 / V_182 ;
if ( V_183 < V_179 || V_183 > V_180 )
return - V_146 ;
V_178 -> V_182 = V_182 ;
V_178 -> V_183 = V_183 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_181 ;
unsigned V_182 ;
unsigned long V_183 ;
V_182 = V_16 -> V_184 . V_182 ;
if ( V_182 == 0 || V_182 > V_16 -> V_185 )
return - V_146 ;
V_181 = F_91 ( V_3 ) ;
V_183 = V_181 / 2 / V_182 ;
F_71 ( L_19 , V_182 , V_183 ) ;
V_16 -> V_170 . V_183 = V_183 ;
V_16 -> V_170 . V_182 = V_182 ;
F_87 ( V_3 , V_186 , V_182 , 12 , 0 ) ;
F_87 ( V_3 , V_186 , V_181 > 30000000 ? 1 : 0 , 21 , 21 ) ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_187 ++ == 0 )
F_87 ( V_3 , V_186 , 1 , 14 , 14 ) ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_187 == 0 ) ;
if ( -- V_16 -> V_187 == 0 )
F_87 ( V_3 , V_186 , 0 , 14 , 14 ) ;
}
static int F_99 ( struct V_2 * V_3 ,
enum V_188 V_189 )
{
int V_27 = 0 ;
if ( F_84 ( V_190 ) &&
V_189 == V_191 )
V_189 = V_192 ;
F_87 ( V_3 , V_186 , V_189 , 31 , 30 ) ;
while ( F_100 ( F_9 ( V_3 , V_186 ) , 29 , 28 ) != V_189 ) {
if ( ++ V_27 > 1000 ) {
F_44 ( L_20 ,
V_189 ) ;
return - V_193 ;
}
F_101 ( 1 ) ;
}
return 0 ;
}
unsigned long F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
return F_93 ( V_16 -> V_156 ) ;
}
bool F_103 ( struct V_2 * V_3 , unsigned long V_194 ,
unsigned long V_195 , T_10 V_196 , void * V_20 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_197 , V_198 , V_199 ;
unsigned long V_200 ;
unsigned long V_8 ;
V_195 = V_195 ? V_195 : 1 ;
V_200 = F_104 ( V_201 ) ;
V_198 = F_105 ( F_95 ( V_194 , V_200 ) , 1ul ) ;
V_199 = F_106 ( V_194 / V_195 , V_16 -> V_202 ) ;
for ( V_197 = V_198 ; V_197 <= V_199 ; ++ V_197 ) {
V_8 = V_194 / V_197 ;
if ( V_196 ( V_197 , V_8 , V_20 ) )
return true ;
}
return false ;
}
bool F_107 ( struct V_2 * V_3 , unsigned long V_203 ,
unsigned long V_204 , unsigned long V_205 ,
T_11 V_196 , void * V_20 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_206 , V_207 , V_208 ;
int V_197 , V_198 , V_199 ;
unsigned long V_209 , V_194 ;
const unsigned long V_210 = 1800000000 ;
unsigned long V_211 , V_212 ;
V_211 = V_16 -> V_213 ;
V_212 = V_16 -> V_214 ;
V_207 = F_105 ( F_95 ( V_203 , V_212 ) , 1ul ) ;
V_208 = F_106 ( V_203 / V_211 , V_16 -> V_215 ) ;
V_205 = V_205 ? V_205 : V_216 ;
for ( V_206 = V_207 ; V_206 <= V_208 ; ++ V_206 ) {
V_209 = V_203 / V_206 ;
V_198 = F_105 ( F_95 ( F_95 ( V_204 , V_209 ) , 2 ) ,
1ul ) ;
V_199 = F_108 ( V_205 / V_209 / 2 ,
V_210 / V_209 / 2 ,
V_16 -> V_217 ) ;
for ( V_197 = V_198 ; V_197 <= V_199 ; ++ V_197 ) {
V_194 = 2 * V_197 * V_209 ;
if ( V_196 ( V_206 , V_197 , V_209 , V_194 , V_20 ) )
return true ;
}
}
return false ;
}
static int F_109 ( struct V_2 * V_3 ,
struct V_177 * V_178 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_178 -> V_206 == 0 || V_178 -> V_206 > V_16 -> V_215 )
return - V_146 ;
if ( V_178 -> V_197 == 0 || V_178 -> V_197 > V_16 -> V_217 )
return - V_146 ;
if ( V_178 -> V_218 > V_16 -> V_202 )
return - V_146 ;
if ( V_178 -> V_219 > V_16 -> V_220 )
return - V_146 ;
V_178 -> V_203 = F_93 ( V_16 -> V_156 ) ;
V_178 -> V_209 = V_178 -> V_203 / V_178 -> V_206 ;
if ( V_178 -> V_209 > V_16 -> V_214 || V_178 -> V_209 < V_16 -> V_213 )
return - V_146 ;
V_178 -> V_173 = 2 * V_178 -> V_197 * V_178 -> V_209 ;
if ( V_178 -> V_173 > 1800 * 1000 * 1000 )
return - V_146 ;
if ( V_178 -> V_218 > 0 )
V_178 -> V_171 =
V_178 -> V_173 / V_178 -> V_218 ;
else
V_178 -> V_171 = 0 ;
if ( V_178 -> V_219 > 0 )
V_178 -> V_172 =
V_178 -> V_173 / V_178 -> V_219 ;
else
V_178 -> V_172 = 0 ;
return 0 ;
}
static void F_110 ( struct V_177 * V_178 )
{
unsigned long V_221 ;
V_221 = F_104 ( V_222 ) ;
V_178 -> V_219 = F_95 ( V_178 -> V_173 , V_221 ) ;
V_178 -> V_172 = V_178 -> V_173 / V_178 -> V_219 ;
}
int F_111 ( struct V_2 * V_3 ,
struct V_177 * V_178 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 = 0 ;
T_1 V_159 ;
int V_223 = 0 ;
T_3 V_207 , V_224 , V_198 , V_225 ;
T_3 V_226 , V_227 , V_228 , V_229 ;
F_71 ( L_21 ) ;
V_16 -> V_170 . V_203 = V_178 -> V_203 ;
V_16 -> V_170 . V_209 = V_178 -> V_209 ;
V_16 -> V_170 . V_173 = V_178 -> V_173 ;
V_16 -> V_170 . V_171 =
V_178 -> V_171 ;
V_16 -> V_170 . V_172 =
V_178 -> V_172 ;
V_16 -> V_170 . V_206 = V_178 -> V_206 ;
V_16 -> V_170 . V_197 = V_178 -> V_197 ;
V_16 -> V_170 . V_218 = V_178 -> V_218 ;
V_16 -> V_170 . V_219 = V_178 -> V_219 ;
F_71 ( L_22 , V_178 -> V_209 ) ;
F_71 ( L_23 , V_178 -> V_203 ) ;
F_71 ( L_24 ,
V_178 -> V_197 ,
V_178 -> V_206 ,
V_178 -> V_203 ,
V_178 -> V_173 ) ;
F_71 ( L_25 ,
V_178 -> V_173 / 1000 / 1000 / 2 ) ;
F_71 ( L_26 , V_178 -> V_173 / 4 ) ;
F_71 ( L_27 , V_178 -> V_218 ,
F_112 ( V_230 ) ,
F_113 ( V_230 ) ,
V_178 -> V_171 ) ;
F_71 ( L_28 , V_178 -> V_219 ,
F_112 ( V_231 ) ,
F_113 ( V_231 ) ,
V_178 -> V_172 ) ;
F_114 ( V_232 , & V_207 , & V_224 ) ;
F_114 ( V_233 , & V_198 , & V_225 ) ;
F_114 ( V_234 , & V_226 ,
& V_227 ) ;
F_114 ( V_235 , & V_228 ,
& V_229 ) ;
F_87 ( V_3 , V_236 , 0 , 0 , 0 ) ;
V_159 = F_9 ( V_3 , V_237 ) ;
V_159 = F_115 ( V_159 , 1 , 0 , 0 ) ;
V_159 = F_115 ( V_159 , V_178 -> V_206 - 1 , V_207 , V_224 ) ;
V_159 = F_115 ( V_159 , V_178 -> V_197 , V_198 , V_225 ) ;
V_159 = F_115 ( V_159 , V_178 -> V_218 > 0 ? V_178 -> V_218 - 1 : 0 ,
V_226 , V_227 ) ;
V_159 = F_115 ( V_159 , V_178 -> V_219 > 0 ? V_178 -> V_219 - 1 : 0 ,
V_228 , V_229 ) ;
F_7 ( V_3 , V_237 , V_159 ) ;
F_61 ( V_178 -> V_209 < V_16 -> V_213 || V_178 -> V_209 > V_16 -> V_214 ) ;
V_159 = F_9 ( V_3 , V_238 ) ;
if ( F_84 ( V_239 ) ) {
V_223 = V_178 -> V_209 < 1000000 ? 0x3 :
V_178 -> V_209 < 1250000 ? 0x4 :
V_178 -> V_209 < 1500000 ? 0x5 :
V_178 -> V_209 < 1750000 ? 0x6 :
0x7 ;
V_159 = F_115 ( V_159 , V_223 , 4 , 1 ) ;
} else if ( F_84 ( V_240 ) ) {
V_223 = V_178 -> V_173 < 1000000000 ? 0x2 : 0x4 ;
V_159 = F_115 ( V_159 , V_223 , 4 , 1 ) ;
}
V_159 = F_115 ( V_159 , 1 , 13 , 13 ) ;
V_159 = F_115 ( V_159 , 0 , 14 , 14 ) ;
V_159 = F_115 ( V_159 , 1 , 20 , 20 ) ;
if ( F_84 ( V_241 ) )
V_159 = F_115 ( V_159 , 3 , 22 , 21 ) ;
F_7 ( V_3 , V_238 , V_159 ) ;
F_87 ( V_3 , V_242 , 1 , 0 , 0 ) ;
if ( F_18 ( V_3 , V_242 , 0 , 0 ) != 0 ) {
F_44 ( L_29 ) ;
V_148 = - V_169 ;
goto V_243;
}
if ( F_18 ( V_3 , V_158 , 1 , 1 ) != 1 ) {
F_44 ( L_30 ) ;
V_148 = - V_169 ;
goto V_243;
}
V_16 -> V_157 = 1 ;
V_159 = F_9 ( V_3 , V_238 ) ;
V_159 = F_115 ( V_159 , 0 , 0 , 0 ) ;
V_159 = F_115 ( V_159 , 0 , 5 , 5 ) ;
V_159 = F_115 ( V_159 , 0 , 6 , 6 ) ;
V_159 = F_115 ( V_159 , 0 , 7 , 7 ) ;
V_159 = F_115 ( V_159 , 0 , 8 , 8 ) ;
V_159 = F_115 ( V_159 , 0 , 10 , 9 ) ;
V_159 = F_115 ( V_159 , 1 , 13 , 13 ) ;
V_159 = F_115 ( V_159 , 1 , 14 , 14 ) ;
V_159 = F_115 ( V_159 , 0 , 15 , 15 ) ;
V_159 = F_115 ( V_159 , 1 , 16 , 16 ) ;
V_159 = F_115 ( V_159 , 0 , 17 , 17 ) ;
V_159 = F_115 ( V_159 , 1 , 18 , 18 ) ;
V_159 = F_115 ( V_159 , 0 , 19 , 19 ) ;
V_159 = F_115 ( V_159 , 0 , 20 , 20 ) ;
F_7 ( V_3 , V_238 , V_159 ) ;
F_71 ( L_31 ) ;
V_243:
return V_148 ;
}
int F_116 ( struct V_2 * V_3 , bool V_244 ,
bool V_245 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 = 0 ;
enum V_188 V_246 ;
F_71 ( L_32 ) ;
V_244 = V_245 = true ;
V_148 = F_76 ( V_3 ) ;
if ( V_148 )
return V_148 ;
F_80 ( V_3 , 1 ) ;
F_97 ( V_3 ) ;
if ( ! V_16 -> V_247 ) {
V_148 = F_117 ( V_16 -> V_154 ) ;
if ( V_148 )
goto V_248;
V_16 -> V_247 = true ;
}
F_118 ( 1 ) ;
if ( F_18 ( V_3 , V_158 , 0 , 1 ) != 1 ) {
F_44 ( L_33 ) ;
V_148 = - V_193 ;
F_118 ( 0 ) ;
goto V_249;
}
F_118 ( 0 ) ;
if ( V_244 && V_245 )
V_246 = V_192 ;
else if ( V_244 )
V_246 = V_250 ;
else if ( V_245 )
V_246 = V_191 ;
else
V_246 = V_251 ;
V_148 = F_99 ( V_3 , V_246 ) ;
if ( V_148 )
goto V_249;
F_71 ( L_34 ) ;
return 0 ;
V_249:
if ( V_16 -> V_247 ) {
F_119 ( V_16 -> V_154 ) ;
V_16 -> V_247 = false ;
}
V_248:
F_98 ( V_3 ) ;
F_80 ( V_3 , 0 ) ;
return V_148 ;
}
void F_120 ( struct V_2 * V_3 , bool V_252 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_157 = 0 ;
F_99 ( V_3 , V_251 ) ;
if ( V_252 ) {
F_73 ( ! V_16 -> V_247 ) ;
F_119 ( V_16 -> V_154 ) ;
V_16 -> V_247 = false ;
}
F_98 ( V_3 ) ;
F_80 ( V_3 , 0 ) ;
F_71 ( L_35 ) ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_253 * V_254 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_177 * V_178 = & V_16 -> V_170 ;
enum V_255 V_256 , V_257 ;
int V_258 = V_16 -> V_174 ;
V_256 = F_122 () ;
V_257 = F_92 ( V_258 ) ;
if ( F_70 ( V_3 ) )
return;
F_123 ( V_254 , L_36 , V_258 + 1 ) ;
F_123 ( V_254 , L_37 , V_178 -> V_203 ) ;
F_123 ( V_254 , L_38 , V_178 -> V_209 , V_178 -> V_206 ) ;
F_123 ( V_254 , L_39 ,
V_178 -> V_173 , V_178 -> V_197 ) ;
F_123 ( V_254 , L_40 ,
F_113 ( V_258 == 0 ?
V_230 :
V_259 ) ,
V_178 -> V_171 ,
V_178 -> V_218 ,
V_256 == V_175 ?
L_41 : L_42 ) ;
F_123 ( V_254 , L_43 ,
F_113 ( V_258 == 0 ?
V_231 :
V_260 ) ,
V_178 -> V_172 ,
V_178 -> V_219 ,
V_257 == V_175 ?
L_41 : L_42 ) ;
F_123 ( V_254 , L_44 , V_258 + 1 ) ;
F_123 ( V_254 , L_45 ,
F_112 ( V_257 ) ,
F_113 ( V_257 ) ) ;
F_123 ( V_254 , L_46 , F_91 ( V_3 ) ) ;
F_123 ( V_254 , L_47 ,
V_178 -> V_173 / 4 ) ;
F_123 ( V_254 , L_48 , F_90 ( V_3 ) ) ;
F_123 ( V_254 , L_49 , V_178 -> V_183 ) ;
F_74 ( V_3 ) ;
}
void F_124 ( struct V_253 * V_254 )
{
struct V_2 * V_3 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_261 ; V_103 ++ ) {
V_3 = F_5 ( V_103 ) ;
if ( V_3 )
F_121 ( V_3 , V_254 ) ;
}
}
static void F_125 ( struct V_2 * V_3 ,
struct V_253 * V_254 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_144 ;
struct V_262 V_263 ;
F_58 ( & V_16 -> V_104 , V_144 ) ;
V_263 = V_16 -> V_105 ;
memset ( & V_16 -> V_105 , 0 , sizeof( V_16 -> V_105 ) ) ;
V_16 -> V_105 . V_264 = V_28 ;
F_59 ( & V_16 -> V_104 , V_144 ) ;
F_123 ( V_254 , L_50 ,
F_126 ( V_28 - V_263 . V_264 ) ) ;
F_123 ( V_254 , L_51 , V_263 . V_106 ) ;
#define F_35 ( T_4 ) \
seq_printf(s, "%-20s %10d\n", #x, stats.dsi_irqs[ffs(DSI_IRQ_##x)-1]);
F_123 ( V_254 , L_52 , V_16 -> V_174 + 1 ) ;
F_35 ( V_52 ) ;
F_35 ( V_53 ) ;
F_35 ( V_54 ) ;
F_35 ( V_55 ) ;
F_35 ( V_56 ) ;
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
#undef F_35
#define F_35 ( T_4 ) \
seq_printf(s, "%-20s %10d %10d %10d %10d\n", #x, \
stats.vc_irqs[0][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[1][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[2][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[3][ffs(DSI_VC_IRQ_##x)-1]);
F_123 ( V_254 , L_53 ) ;
F_35 ( V_71 ) ;
F_35 ( V_72 ) ;
F_35 ( V_74 ) ;
F_35 ( V_76 ) ;
F_35 ( V_77 ) ;
F_35 ( V_75 ) ;
F_35 ( V_73 ) ;
F_35 ( V_78 ) ;
F_35 ( V_79 ) ;
#undef F_35
#define F_35 ( T_4 ) \
seq_printf(s, "%-20s %10d\n", #x, \
stats.cio_irqs[ffs(DSI_CIO_IRQ_##x)-1]);
F_123 ( V_254 , L_54 ) ;
F_35 ( V_80 ) ;
F_35 ( V_81 ) ;
F_35 ( V_82 ) ;
F_35 ( V_83 ) ;
F_35 ( V_84 ) ;
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
#undef F_35
}
static void F_127 ( struct V_253 * V_254 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_125 ( V_3 , V_254 ) ;
}
static void F_128 ( struct V_253 * V_254 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_125 ( V_3 , V_254 ) ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_253 * V_254 )
{
#define F_130 ( V_148 ) seq_printf(s, "%-35s %08x\n", #r, dsi_read_reg(dsidev, r))
if ( F_70 ( V_3 ) )
return;
F_97 ( V_3 ) ;
F_130 ( V_265 ) ;
F_130 ( V_266 ) ;
F_130 ( V_267 ) ;
F_130 ( V_129 ) ;
F_130 ( V_141 ) ;
F_130 ( V_168 ) ;
F_130 ( V_268 ) ;
F_130 ( V_132 ) ;
F_130 ( V_143 ) ;
F_130 ( V_186 ) ;
F_130 ( V_269 ) ;
F_130 ( V_270 ) ;
F_130 ( V_271 ) ;
F_130 ( V_272 ) ;
F_130 ( V_273 ) ;
F_130 ( V_274 ) ;
F_130 ( V_275 ) ;
F_130 ( V_276 ) ;
F_130 ( V_277 ) ;
F_130 ( V_278 ) ;
F_130 ( V_279 ) ;
F_130 ( V_280 ) ;
F_130 ( V_281 ) ;
F_130 ( V_282 ) ;
F_130 ( V_283 ) ;
F_130 ( V_284 ) ;
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
F_130 ( V_285 ) ;
F_130 ( V_286 ) ;
F_130 ( V_287 ) ;
F_130 ( V_163 ) ;
F_130 ( V_236 ) ;
F_130 ( V_158 ) ;
F_130 ( V_242 ) ;
F_130 ( V_237 ) ;
F_130 ( V_238 ) ;
F_98 ( V_3 ) ;
F_74 ( V_3 ) ;
#undef F_130
}
static void F_136 ( struct V_253 * V_254 )
{
struct V_2 * V_3 = F_5 ( 0 ) ;
F_129 ( V_3 , V_254 ) ;
}
static void F_137 ( struct V_253 * V_254 )
{
struct V_2 * V_3 = F_5 ( 1 ) ;
F_129 ( V_3 , V_254 ) ;
}
static int F_138 ( struct V_2 * V_3 ,
enum V_288 V_189 )
{
int V_27 = 0 ;
F_87 ( V_3 , V_268 , V_189 , 28 , 27 ) ;
while ( F_100 ( F_9 ( V_3 , V_268 ) ,
26 , 25 ) != V_189 ) {
if ( ++ V_27 > 1000 ) {
F_44 ( L_55
L_56 , V_189 ) ;
return - V_193 ;
}
F_101 ( 1 ) ;
}
return 0 ;
}
static unsigned F_139 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! F_84 ( V_289 ) )
return 1023 * 3 ;
V_15 = F_19 ( V_3 , V_290 , 14 , 12 ) ;
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
static const T_3 V_291 [] = { 0 , 4 , 8 , 12 , 16 } ;
static const enum V_292 V_293 [] = {
V_294 ,
V_295 ,
V_296 ,
V_297 ,
V_298 ,
} ;
T_1 V_148 ;
int V_103 ;
V_148 = F_9 ( V_3 , V_268 ) ;
for ( V_103 = 0 ; V_103 < V_16 -> V_299 ; ++ V_103 ) {
unsigned V_300 = V_291 [ V_103 ] ;
unsigned V_301 , V_302 ;
unsigned V_27 ;
for ( V_27 = 0 ; V_27 < V_16 -> V_303 ; ++ V_27 )
if ( V_16 -> V_304 [ V_27 ] . V_305 == V_293 [ V_103 ] )
break;
if ( V_27 == V_16 -> V_303 )
return - V_146 ;
V_302 = V_27 ;
V_301 = V_16 -> V_304 [ V_27 ] . V_301 ;
V_148 = F_115 ( V_148 , V_302 + 1 , V_300 + 2 , V_300 ) ;
V_148 = F_115 ( V_148 , V_301 , V_300 + 3 , V_300 + 3 ) ;
}
for (; V_103 < V_16 -> V_303 ; ++ V_103 ) {
unsigned V_300 = V_291 [ V_103 ] ;
V_148 = F_115 ( V_148 , 0 , V_300 + 2 , V_300 ) ;
V_148 = F_115 ( V_148 , 0 , V_300 + 3 , V_300 + 3 ) ;
}
F_7 ( V_3 , V_268 , V_148 ) ;
return 0 ;
}
static inline unsigned F_141 ( struct V_2 * V_3 , unsigned V_306 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_307 = V_16 -> V_170 . V_173 / 4 ;
return ( V_306 * ( V_307 / 1000 / 1000 ) + 999 ) / 1000 ;
}
static inline unsigned F_142 ( struct V_2 * V_3 , unsigned V_308 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned long V_307 = V_16 -> V_170 . V_173 / 4 ;
return V_308 * 1000 * 1000 / ( V_307 / 1000 ) ;
}
static void F_143 ( struct V_2 * V_3 )
{
T_1 V_148 ;
T_1 V_309 , V_310 , V_311 , V_312 ;
T_1 V_313 , V_314 , V_315 ;
T_1 V_316 ;
V_309 = F_141 ( V_3 , 70 ) + 2 ;
V_310 = F_141 ( V_3 , 175 ) + 2 ;
V_311 = F_141 ( V_3 , 60 ) + 5 ;
V_312 = F_141 ( V_3 , 145 ) ;
V_313 = F_141 ( V_3 , 25 ) ;
V_314 = F_141 ( V_3 , 60 ) + 2 ;
V_316 = F_141 ( V_3 , 65 ) ;
V_315 = F_141 ( V_3 , 260 ) ;
F_71 ( L_57 ,
V_309 , F_142 ( V_3 , V_309 ) ,
V_310 , F_142 ( V_3 , V_310 ) ) ;
F_71 ( L_58 ,
V_311 , F_142 ( V_3 , V_311 ) ,
V_312 , F_142 ( V_3 , V_312 ) ) ;
F_71 ( L_59
L_60 ,
V_313 , F_142 ( V_3 , V_313 ) ,
V_314 , F_142 ( V_3 , V_314 ) ,
V_315 , F_142 ( V_3 , V_315 ) ) ;
F_71 ( L_61 ,
V_316 , F_142 ( V_3 , V_316 ) ) ;
V_148 = F_9 ( V_3 , V_285 ) ;
V_148 = F_115 ( V_148 , V_309 , 31 , 24 ) ;
V_148 = F_115 ( V_148 , V_310 , 23 , 16 ) ;
V_148 = F_115 ( V_148 , V_311 , 15 , 8 ) ;
V_148 = F_115 ( V_148 , V_312 , 7 , 0 ) ;
F_7 ( V_3 , V_285 , V_148 ) ;
V_148 = F_9 ( V_3 , V_286 ) ;
V_148 = F_115 ( V_148 , V_313 , 20 , 16 ) ;
V_148 = F_115 ( V_148 , V_314 , 15 , 8 ) ;
V_148 = F_115 ( V_148 , V_315 , 7 , 0 ) ;
if ( F_84 ( V_317 ) ) {
V_148 = F_115 ( V_148 , 0 , 21 , 21 ) ;
V_148 = F_115 ( V_148 , 1 , 22 , 22 ) ;
V_148 = F_115 ( V_148 , 1 , 23 , 23 ) ;
}
F_7 ( V_3 , V_286 , V_148 ) ;
V_148 = F_9 ( V_3 , V_287 ) ;
V_148 = F_115 ( V_148 , V_316 , 7 , 0 ) ;
F_7 ( V_3 , V_287 , V_148 ) ;
}
static void F_144 ( struct V_2 * V_3 ,
unsigned V_318 , unsigned V_319 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_103 ;
T_1 V_159 ;
T_3 V_320 = V_16 -> V_303 == 3 ? 22 : 26 ;
V_159 = 0 ;
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 ) {
unsigned V_321 = V_16 -> V_304 [ V_103 ] . V_301 ;
if ( V_318 & ( 1 << V_103 ) )
V_159 |= 1 << ( V_103 * 2 + ( V_321 ? 0 : 1 ) ) ;
if ( V_319 & ( 1 << V_103 ) )
V_159 |= 1 << ( V_103 * 2 + ( V_321 ? 1 : 0 ) ) ;
}
F_87 ( V_3 , V_322 , V_159 , V_320 , 17 ) ;
F_87 ( V_3 , V_322 , 1 , 27 , 27 ) ;
}
static void F_145 ( struct V_2 * V_3 )
{
F_87 ( V_3 , V_322 , 0 , 27 , 27 ) ;
F_87 ( V_3 , V_322 , 0 , 22 , 17 ) ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_27 , V_103 ;
bool V_323 [ V_324 ] ;
static const T_3 V_325 [] = { 28 , 27 , 26 } ;
static const T_3 V_326 [] = { 24 , 25 , 26 , 27 , 28 } ;
const T_3 * V_291 ;
if ( F_84 ( V_164 ) )
V_291 = V_325 ;
else
V_291 = V_326 ;
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 )
V_323 [ V_103 ] = V_16 -> V_304 [ V_103 ] . V_305 != V_327 ;
V_27 = 100000 ;
while ( true ) {
T_1 V_159 ;
int V_328 ;
V_159 = F_9 ( V_3 , V_163 ) ;
V_328 = 0 ;
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 ) {
if ( ! V_323 [ V_103 ] || ( V_159 & ( 1 << V_291 [ V_103 ] ) ) )
V_328 ++ ;
}
if ( V_328 == V_16 -> V_303 )
break;
if ( -- V_27 == 0 ) {
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 ) {
if ( ! V_323 [ V_103 ] || ( V_159 & ( 1 << V_291 [ V_103 ] ) ) )
continue;
F_44 ( L_62 \
L_63 , V_103 ) ;
}
return - V_169 ;
}
}
return 0 ;
}
static unsigned F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
unsigned V_21 = 0 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 ) {
if ( V_16 -> V_304 [ V_103 ] . V_305 != V_327 )
V_21 |= 1 << V_103 ;
}
return V_21 ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 ;
T_1 V_159 ;
F_71 ( L_64 ) ;
V_148 = F_149 ( V_16 -> V_174 , F_147 ( V_3 ) ) ;
if ( V_148 )
return V_148 ;
F_97 ( V_3 ) ;
F_9 ( V_3 , V_163 ) ;
if ( F_18 ( V_3 , V_163 , 30 , 1 ) != 1 ) {
F_44 ( L_65 ) ;
V_148 = - V_169 ;
goto V_329;
}
V_148 = F_140 ( V_3 ) ;
if ( V_148 )
goto V_329;
V_159 = F_9 ( V_3 , V_269 ) ;
V_159 = F_115 ( V_159 , 1 , 15 , 15 ) ;
V_159 = F_115 ( V_159 , 1 , 14 , 14 ) ;
V_159 = F_115 ( V_159 , 1 , 13 , 13 ) ;
V_159 = F_115 ( V_159 , 0x1fff , 12 , 0 ) ;
F_7 ( V_3 , V_269 , V_159 ) ;
if ( V_16 -> V_330 ) {
unsigned V_318 ;
int V_103 ;
F_71 ( L_66 ) ;
V_318 = 0 ;
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 ) {
if ( V_16 -> V_304 [ V_103 ] . V_305 == V_327 )
continue;
V_318 |= 1 << V_103 ;
}
F_144 ( V_3 , V_318 , 0 ) ;
}
V_148 = F_138 ( V_3 , V_331 ) ;
if ( V_148 )
goto V_332;
if ( F_18 ( V_3 , V_268 , 29 , 1 ) != 1 ) {
F_44 ( L_67 ) ;
V_148 = - V_193 ;
goto V_333;
}
F_86 ( V_3 , true ) ;
F_86 ( V_3 , false ) ;
F_87 ( V_3 , V_186 , 1 , 20 , 20 ) ;
V_148 = F_146 ( V_3 ) ;
if ( V_148 )
goto V_334;
if ( V_16 -> V_330 ) {
T_2 V_26 = F_22 ( 1000 * 1000 ) ;
F_23 ( V_29 ) ;
F_24 ( & V_26 , V_30 ) ;
F_145 ( V_3 ) ;
}
F_87 ( V_3 , V_269 , 0 , 15 , 15 ) ;
F_143 ( V_3 ) ;
if ( V_16 -> V_335 == V_336 ) {
F_87 ( V_3 , V_186 ,
V_16 -> V_337 . V_338 , 13 , 13 ) ;
}
V_16 -> V_330 = false ;
F_71 ( L_68 ) ;
return 0 ;
V_334:
F_87 ( V_3 , V_186 , 0 , 20 , 20 ) ;
V_333:
F_138 ( V_3 , V_339 ) ;
V_332:
if ( V_16 -> V_330 )
F_145 ( V_3 ) ;
V_329:
F_98 ( V_3 ) ;
F_150 ( V_16 -> V_174 , F_147 ( V_3 ) ) ;
return V_148 ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_87 ( V_3 , V_186 , 0 , 13 , 13 ) ;
F_138 ( V_3 , V_339 ) ;
F_98 ( V_3 ) ;
F_150 ( V_16 -> V_174 , F_147 ( V_3 ) ) ;
}
static void F_152 ( struct V_2 * V_3 ,
enum V_340 V_341 , enum V_340 V_342 ,
enum V_340 V_343 , enum V_340 V_344 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_148 = 0 ;
int V_345 = 0 ;
int V_103 ;
V_16 -> V_142 [ 0 ] . V_340 = V_341 ;
V_16 -> V_142 [ 1 ] . V_340 = V_342 ;
V_16 -> V_142 [ 2 ] . V_340 = V_343 ;
V_16 -> V_142 [ 3 ] . V_340 = V_344 ;
for ( V_103 = 0 ; V_103 < 4 ; V_103 ++ ) {
T_3 V_346 ;
int V_347 = V_16 -> V_142 [ V_103 ] . V_340 ;
if ( V_345 + V_347 > 4 ) {
F_44 ( L_69 ) ;
F_26 () ;
return;
}
V_346 = F_153 ( V_345 , 2 , 0 ) | F_153 ( V_347 , 7 , 4 ) ;
V_148 |= V_346 << ( 8 * V_103 ) ;
V_345 += V_347 ;
}
F_7 ( V_3 , V_275 , V_148 ) ;
}
static void F_154 ( struct V_2 * V_3 ,
enum V_340 V_341 , enum V_340 V_342 ,
enum V_340 V_343 , enum V_340 V_344 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_148 = 0 ;
int V_345 = 0 ;
int V_103 ;
V_16 -> V_142 [ 0 ] . V_340 = V_341 ;
V_16 -> V_142 [ 1 ] . V_340 = V_342 ;
V_16 -> V_142 [ 2 ] . V_340 = V_343 ;
V_16 -> V_142 [ 3 ] . V_340 = V_344 ;
for ( V_103 = 0 ; V_103 < 4 ; V_103 ++ ) {
T_3 V_346 ;
int V_347 = V_16 -> V_142 [ V_103 ] . V_340 ;
if ( V_345 + V_347 > 4 ) {
F_44 ( L_69 ) ;
F_26 () ;
return;
}
V_346 = F_153 ( V_345 , 2 , 0 ) | F_153 ( V_347 , 7 , 4 ) ;
V_148 |= V_346 << ( 8 * V_103 ) ;
V_345 += V_347 ;
}
F_7 ( V_3 , V_276 , V_148 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
T_1 V_148 ;
V_148 = F_9 ( V_3 , V_269 ) ;
V_148 = F_115 ( V_148 , 1 , 15 , 15 ) ;
F_7 ( V_3 , V_269 , V_148 ) ;
if ( F_18 ( V_3 , V_269 , 15 , 0 ) != 0 ) {
F_44 ( L_70 ) ;
return - V_169 ;
}
return 0 ;
}
static bool F_156 ( struct V_2 * V_3 , int V_69 )
{
return F_19 ( V_3 , F_131 ( V_69 ) , 0 , 0 ) ;
}
static void F_157 ( void * V_20 , T_1 V_21 )
{
struct V_348 * V_349 =
(struct V_348 * ) V_20 ;
struct V_1 * V_16 = F_1 ( V_349 -> V_3 ) ;
const int V_69 = V_16 -> V_350 ;
T_3 V_351 = V_16 -> V_352 ? 30 : 31 ;
if ( F_19 ( V_349 -> V_3 , F_132 ( V_69 ) , V_351 , V_351 ) == 0 )
F_17 ( V_349 -> V_22 ) ;
}
static int F_158 ( struct V_2 * V_3 , int V_69 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_159 ( V_22 ) ;
struct V_348 V_349 = { V_3 , & V_22 } ;
int V_148 = 0 ;
T_3 V_351 ;
V_351 = V_16 -> V_352 ? 30 : 31 ;
V_148 = F_65 ( V_3 , V_69 , F_157 ,
& V_349 , V_70 ) ;
if ( V_148 )
goto V_248;
if ( F_19 ( V_3 , F_132 ( V_69 ) , V_351 , V_351 ) ) {
if ( F_160 ( & V_22 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_71 ) ;
V_148 = - V_169 ;
goto V_249;
}
}
F_66 ( V_3 , V_69 , F_157 ,
& V_349 , V_70 ) ;
return 0 ;
V_249:
F_66 ( V_3 , V_69 , F_157 ,
& V_349 , V_70 ) ;
V_248:
return V_148 ;
}
static void F_161 ( void * V_20 , T_1 V_21 )
{
struct V_348 * V_353 =
(struct V_348 * ) V_20 ;
struct V_1 * V_16 = F_1 ( V_353 -> V_3 ) ;
const int V_69 = V_16 -> V_350 ;
if ( F_19 ( V_353 -> V_3 , F_131 ( V_69 ) , 5 , 5 ) == 0 )
F_17 ( V_353 -> V_22 ) ;
}
static int F_162 ( struct V_2 * V_3 , int V_69 )
{
F_159 ( V_22 ) ;
struct V_348 V_353 = { V_3 , & V_22 } ;
int V_148 = 0 ;
V_148 = F_65 ( V_3 , V_69 , F_161 ,
& V_353 , V_70 ) ;
if ( V_148 )
goto V_248;
if ( F_19 ( V_3 , F_131 ( V_69 ) , 5 , 5 ) ) {
if ( F_160 ( & V_22 ,
F_20 ( 10 ) ) == 0 ) {
F_44 ( L_72 ) ;
V_148 = - V_169 ;
goto V_249;
}
}
F_66 ( V_3 , V_69 , F_161 ,
& V_353 , V_70 ) ;
return 0 ;
V_249:
F_66 ( V_3 , V_69 , F_161 ,
& V_353 , V_70 ) ;
V_248:
return V_148 ;
}
static int F_163 ( struct V_2 * V_3 , int V_69 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( F_164 () ) ;
if ( ! F_156 ( V_3 , V_69 ) )
return 0 ;
switch ( V_16 -> V_142 [ V_69 ] . V_354 ) {
case V_355 :
return F_158 ( V_3 , V_69 ) ;
case V_356 :
return F_162 ( V_3 , V_69 ) ;
default:
F_26 () ;
return - V_146 ;
}
}
static int F_165 ( struct V_2 * V_3 , int V_69 ,
bool V_155 )
{
F_71 ( L_73 ,
V_69 , V_155 ) ;
V_155 = V_155 ? 1 : 0 ;
F_87 ( V_3 , F_131 ( V_69 ) , V_155 , 0 , 0 ) ;
if ( F_18 ( V_3 , F_131 ( V_69 ) ,
0 , V_155 ) != V_155 ) {
F_44 ( L_74 , V_155 ) ;
return - V_169 ;
}
return 0 ;
}
static void F_166 ( struct V_2 * V_3 , int V_69 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_148 ;
F_71 ( L_75 , V_69 ) ;
V_148 = F_9 ( V_3 , F_131 ( V_69 ) ) ;
if ( F_100 ( V_148 , 15 , 15 ) )
F_44 ( L_76 ,
V_69 ) ;
V_148 = F_115 ( V_148 , 0 , 1 , 1 ) ;
V_148 = F_115 ( V_148 , 0 , 2 , 2 ) ;
V_148 = F_115 ( V_148 , 0 , 3 , 3 ) ;
V_148 = F_115 ( V_148 , 0 , 4 , 4 ) ;
V_148 = F_115 ( V_148 , 1 , 7 , 7 ) ;
V_148 = F_115 ( V_148 , 1 , 8 , 8 ) ;
V_148 = F_115 ( V_148 , 0 , 9 , 9 ) ;
if ( F_84 ( V_357 ) )
V_148 = F_115 ( V_148 , 3 , 11 , 10 ) ;
V_148 = F_115 ( V_148 , 4 , 29 , 27 ) ;
V_148 = F_115 ( V_148 , 4 , 23 , 21 ) ;
F_7 ( V_3 , F_131 ( V_69 ) , V_148 ) ;
V_16 -> V_142 [ V_69 ] . V_354 = V_356 ;
}
static int F_167 ( struct V_2 * V_3 , int V_69 ,
enum V_358 V_354 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_142 [ V_69 ] . V_354 == V_354 )
return 0 ;
F_71 ( L_77 , V_69 ) ;
F_163 ( V_3 , V_69 ) ;
F_165 ( V_3 , V_69 , 0 ) ;
if ( F_18 ( V_3 , F_131 ( V_69 ) , 15 , 0 ) != 0 ) {
F_44 ( L_78 , V_69 ) ;
return - V_169 ;
}
F_87 ( V_3 , F_131 ( V_69 ) , V_354 , 1 , 1 ) ;
if ( F_84 ( V_359 ) ) {
bool V_155 = V_354 == V_355 ;
F_87 ( V_3 , F_131 ( V_69 ) , V_155 , 30 , 30 ) ;
}
F_165 ( V_3 , V_69 , 1 ) ;
V_16 -> V_142 [ V_69 ] . V_354 = V_354 ;
return 0 ;
}
static void F_168 ( struct V_5 * V_6 , int V_69 ,
bool V_155 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_79 , V_69 , V_155 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_165 ( V_3 , V_69 , 0 ) ;
F_86 ( V_3 , 0 ) ;
F_87 ( V_3 , F_131 ( V_69 ) , V_155 , 9 , 9 ) ;
F_165 ( V_3 , V_69 , 1 ) ;
F_86 ( V_3 , 1 ) ;
F_155 ( V_3 ) ;
if ( V_16 -> V_337 . V_338 && V_155 )
F_169 ( V_6 , V_69 ) ;
}
static void F_170 ( struct V_2 * V_3 , int V_69 )
{
while ( F_19 ( V_3 , F_131 ( V_69 ) , 20 , 20 ) ) {
T_1 V_15 ;
V_15 = F_9 ( V_3 , F_135 ( V_69 ) ) ;
F_71 ( L_80 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
}
}
static void F_171 ( T_12 V_243 )
{
F_44 ( L_81 , V_243 ) ;
if ( V_243 & ( 1 << 0 ) )
F_44 ( L_82 ) ;
if ( V_243 & ( 1 << 1 ) )
F_44 ( L_83 ) ;
if ( V_243 & ( 1 << 2 ) )
F_44 ( L_84 ) ;
if ( V_243 & ( 1 << 3 ) )
F_44 ( L_85 ) ;
if ( V_243 & ( 1 << 4 ) )
F_44 ( L_86 ) ;
if ( V_243 & ( 1 << 5 ) )
F_44 ( L_87 ) ;
if ( V_243 & ( 1 << 6 ) )
F_44 ( L_88 ) ;
if ( V_243 & ( 1 << 7 ) )
F_44 ( L_89 ) ;
if ( V_243 & ( 1 << 8 ) )
F_44 ( L_90 ) ;
if ( V_243 & ( 1 << 9 ) )
F_44 ( L_91 ) ;
if ( V_243 & ( 1 << 10 ) )
F_44 ( L_92 ) ;
if ( V_243 & ( 1 << 11 ) )
F_44 ( L_93 ) ;
if ( V_243 & ( 1 << 12 ) )
F_44 ( L_94 ) ;
if ( V_243 & ( 1 << 13 ) )
F_44 ( L_95 ) ;
if ( V_243 & ( 1 << 14 ) )
F_44 ( L_96 ) ;
if ( V_243 & ( 1 << 15 ) )
F_44 ( L_97 ) ;
}
static T_12 F_172 ( struct V_2 * V_3 ,
int V_69 )
{
while ( F_19 ( V_3 , F_131 ( V_69 ) , 20 , 20 ) ) {
T_1 V_15 ;
T_3 V_360 ;
V_15 = F_9 ( V_3 , F_135 ( V_69 ) ) ;
F_44 ( L_98 , V_15 ) ;
V_360 = F_100 ( V_15 , 5 , 0 ) ;
if ( V_360 == V_361 ) {
T_12 V_243 = F_100 ( V_15 , 23 , 8 ) ;
F_171 ( V_243 ) ;
} else if ( V_360 == V_362 ) {
F_44 ( L_99 ,
F_100 ( V_15 , 23 , 8 ) ) ;
} else if ( V_360 == V_363 ) {
F_44 ( L_100 ,
F_100 ( V_15 , 23 , 8 ) ) ;
} else if ( V_360 == V_364 ) {
F_44 ( L_101 ,
F_100 ( V_15 , 23 , 8 ) ) ;
F_170 ( V_3 , V_69 ) ;
} else {
F_44 ( L_102 , V_360 ) ;
}
}
return 0 ;
}
static int F_173 ( struct V_2 * V_3 , int V_69 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_365 || V_16 -> V_366 )
F_71 ( L_103 , V_69 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( F_19 ( V_3 , F_131 ( V_69 ) , 20 , 20 ) ) {
F_44 ( L_104 ) ;
F_172 ( V_3 , V_69 ) ;
}
F_87 ( V_3 , F_131 ( V_69 ) , 1 , 6 , 6 ) ;
F_9 ( V_3 , F_131 ( V_69 ) ) ;
return 0 ;
}
static int F_174 ( struct V_5 * V_6 , int V_69 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
F_159 ( V_22 ) ;
int V_148 = 0 ;
T_1 V_243 ;
V_148 = F_65 ( V_3 , V_69 , F_16 ,
& V_22 , V_367 ) ;
if ( V_148 )
goto V_248;
V_148 = F_63 ( V_3 , F_16 , & V_22 ,
V_110 ) ;
if ( V_148 )
goto V_249;
V_148 = F_173 ( V_3 , V_69 ) ;
if ( V_148 )
goto V_368;
if ( F_160 ( & V_22 ,
F_20 ( 500 ) ) == 0 ) {
F_44 ( L_105 ) ;
V_148 = - V_169 ;
goto V_368;
}
V_243 = F_69 ( V_3 ) ;
if ( V_243 ) {
F_44 ( L_106 , V_243 ) ;
V_148 = - V_169 ;
goto V_368;
}
V_368:
F_64 ( V_3 , F_16 , & V_22 ,
V_110 ) ;
V_249:
F_66 ( V_3 , V_69 , F_16 ,
& V_22 , V_367 ) ;
V_248:
return V_148 ;
}
static inline void F_175 ( struct V_2 * V_3 ,
int V_69 , T_3 V_369 , T_12 V_370 , T_3 V_371 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_3 V_372 ;
F_73 ( ! F_15 ( V_3 ) ) ;
V_372 = V_369 | V_16 -> V_142 [ V_69 ] . V_373 << 6 ;
V_15 = F_153 ( V_372 , 7 , 0 ) | F_153 ( V_370 , 23 , 8 ) |
F_153 ( V_371 , 31 , 24 ) ;
F_7 ( V_3 , F_133 ( V_69 ) , V_15 ) ;
}
static inline void F_176 ( struct V_2 * V_3 ,
int V_69 , T_3 V_161 , T_3 V_162 , T_3 V_374 , T_3 V_375 )
{
T_1 V_15 ;
V_15 = V_375 << 24 | V_374 << 16 | V_162 << 8 | V_161 << 0 ;
F_7 ( V_3 , F_134 ( V_69 ) , V_15 ) ;
}
static int F_177 ( struct V_2 * V_3 , int V_69 ,
T_3 V_369 , T_3 * V_20 , T_12 V_370 , T_3 V_371 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_103 ;
T_3 * V_321 ;
int V_148 = 0 ;
T_3 V_161 , V_162 , V_374 , V_375 ;
if ( V_16 -> V_365 )
F_71 ( L_107 , V_370 ) ;
if ( V_16 -> V_142 [ V_69 ] . V_340 * 32 * 4 < V_370 + 4 ) {
F_44 ( L_108 ) ;
return - V_146 ;
}
F_167 ( V_3 , V_69 , V_356 ) ;
F_175 ( V_3 , V_69 , V_369 , V_370 , V_371 ) ;
V_321 = V_20 ;
for ( V_103 = 0 ; V_103 < V_370 > > 2 ; V_103 ++ ) {
if ( V_16 -> V_365 )
F_71 ( L_109 , V_103 ) ;
V_161 = * V_321 ++ ;
V_162 = * V_321 ++ ;
V_374 = * V_321 ++ ;
V_375 = * V_321 ++ ;
F_176 ( V_3 , V_69 , V_161 , V_162 , V_374 , V_375 ) ;
}
V_103 = V_370 % 4 ;
if ( V_103 ) {
V_161 = 0 ; V_162 = 0 ; V_374 = 0 ;
if ( V_16 -> V_365 )
F_71 ( L_110 , V_103 ) ;
switch ( V_103 ) {
case 3 :
V_161 = * V_321 ++ ;
V_162 = * V_321 ++ ;
V_374 = * V_321 ++ ;
break;
case 2 :
V_161 = * V_321 ++ ;
V_162 = * V_321 ++ ;
break;
case 1 :
V_161 = * V_321 ++ ;
break;
}
F_176 ( V_3 , V_69 , V_161 , V_162 , V_374 , 0 ) ;
}
return V_148 ;
}
static int F_178 ( struct V_2 * V_3 , int V_69 ,
T_3 V_369 , T_12 V_20 , T_3 V_371 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_148 ;
T_3 V_372 ;
F_73 ( ! F_15 ( V_3 ) ) ;
if ( V_16 -> V_365 )
F_71 ( L_111 ,
V_69 ,
V_369 , V_20 & 0xff , ( V_20 >> 8 ) & 0xff ) ;
F_167 ( V_3 , V_69 , V_356 ) ;
if ( F_100 ( F_9 ( V_3 , F_131 ( V_69 ) ) , 16 , 16 ) ) {
F_44 ( L_112 ) ;
return - V_146 ;
}
V_372 = V_369 | V_16 -> V_142 [ V_69 ] . V_373 << 6 ;
V_148 = ( V_372 << 0 ) | ( V_20 << 8 ) | ( V_371 << 24 ) ;
F_7 ( V_3 , F_135 ( V_69 ) , V_148 ) ;
return 0 ;
}
static int F_169 ( struct V_5 * V_6 , int V_69 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_177 ( V_3 , V_69 , V_376 , NULL ,
0 , 0 ) ;
}
static int F_179 ( struct V_2 * V_3 ,
int V_69 , T_3 * V_20 , int V_370 , enum V_377 type )
{
int V_148 ;
if ( V_370 == 0 ) {
F_61 ( type == V_378 ) ;
V_148 = F_178 ( V_3 , V_69 ,
V_379 , 0 , 0 ) ;
} else if ( V_370 == 1 ) {
V_148 = F_178 ( V_3 , V_69 ,
type == V_380 ?
V_381 :
V_382 , V_20 [ 0 ] , 0 ) ;
} else if ( V_370 == 2 ) {
V_148 = F_178 ( V_3 , V_69 ,
type == V_380 ?
V_383 :
V_384 ,
V_20 [ 0 ] | ( V_20 [ 1 ] << 8 ) , 0 ) ;
} else {
V_148 = F_177 ( V_3 , V_69 ,
type == V_380 ?
V_385 :
V_386 , V_20 , V_370 , 0 ) ;
}
return V_148 ;
}
static int F_180 ( struct V_5 * V_6 , int V_69 ,
T_3 * V_20 , int V_370 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_179 ( V_3 , V_69 , V_20 , V_370 ,
V_378 ) ;
}
static int F_181 ( struct V_5 * V_6 , int V_69 ,
T_3 * V_20 , int V_370 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_179 ( V_3 , V_69 , V_20 , V_370 ,
V_380 ) ;
}
static int F_182 ( struct V_5 * V_6 , int V_69 ,
T_3 * V_20 , int V_370 , enum V_377 type )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_148 ;
V_148 = F_179 ( V_3 , V_69 , V_20 , V_370 , type ) ;
if ( V_148 )
goto V_243;
V_148 = F_174 ( V_6 , V_69 ) ;
if ( V_148 )
goto V_243;
if ( F_19 ( V_3 , F_131 ( V_69 ) , 20 , 20 ) ) {
F_44 ( L_113 ) ;
F_172 ( V_3 , V_69 ) ;
V_148 = - V_169 ;
goto V_243;
}
return 0 ;
V_243:
F_44 ( L_114 ,
V_69 , V_20 [ 0 ] , V_370 ) ;
return V_148 ;
}
static int F_183 ( struct V_5 * V_6 , int V_69 , T_3 * V_20 ,
int V_370 )
{
return F_182 ( V_6 , V_69 , V_20 , V_370 ,
V_378 ) ;
}
static int F_184 ( struct V_5 * V_6 , int V_69 , T_3 * V_20 ,
int V_370 )
{
return F_182 ( V_6 , V_69 , V_20 , V_370 ,
V_380 ) ;
}
static int F_185 ( struct V_2 * V_3 ,
int V_69 , T_3 V_387 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 ;
if ( V_16 -> V_366 )
F_71 ( L_115 ,
V_69 , V_387 ) ;
V_148 = F_178 ( V_3 , V_69 , V_388 , V_387 , 0 ) ;
if ( V_148 ) {
F_44 ( L_116
L_117 , V_69 , V_387 ) ;
return V_148 ;
}
return 0 ;
}
static int F_186 ( struct V_2 * V_3 ,
int V_69 , T_3 * V_389 , int V_390 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_12 V_20 ;
T_3 V_369 ;
int V_148 ;
if ( V_16 -> V_366 )
F_71 ( L_118 ,
V_69 , V_390 ) ;
if ( V_390 == 0 ) {
V_369 = V_391 ;
V_20 = 0 ;
} else if ( V_390 == 1 ) {
V_369 = V_392 ;
V_20 = V_389 [ 0 ] ;
} else if ( V_390 == 2 ) {
V_369 = V_393 ;
V_20 = V_389 [ 0 ] | ( V_389 [ 1 ] << 8 ) ;
} else {
F_26 () ;
return - V_146 ;
}
V_148 = F_178 ( V_3 , V_69 , V_369 , V_20 , 0 ) ;
if ( V_148 ) {
F_44 ( L_119
L_117 , V_69 , V_390 ) ;
return V_148 ;
}
return 0 ;
}
static int F_187 ( struct V_2 * V_3 , int V_69 ,
T_3 * V_394 , int V_395 , enum V_377 type )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_15 ;
T_3 V_360 ;
int V_148 ;
if ( F_19 ( V_3 , F_131 ( V_69 ) , 20 , 20 ) == 0 ) {
F_44 ( L_120 ) ;
V_148 = - V_169 ;
goto V_243;
}
V_15 = F_9 ( V_3 , F_135 ( V_69 ) ) ;
if ( V_16 -> V_366 )
F_71 ( L_121 , V_15 ) ;
V_360 = F_100 ( V_15 , 5 , 0 ) ;
if ( V_360 == V_361 ) {
T_12 V_243 = F_100 ( V_15 , 23 , 8 ) ;
F_171 ( V_243 ) ;
V_148 = - V_169 ;
goto V_243;
} else if ( V_360 == ( type == V_380 ?
V_396 :
V_362 ) ) {
T_3 V_20 = F_100 ( V_15 , 15 , 8 ) ;
if ( V_16 -> V_366 )
F_71 ( L_122 ,
type == V_380 ? L_123 :
L_124 , V_20 ) ;
if ( V_395 < 1 ) {
V_148 = - V_169 ;
goto V_243;
}
V_394 [ 0 ] = V_20 ;
return 1 ;
} else if ( V_360 == ( type == V_380 ?
V_397 :
V_363 ) ) {
T_12 V_20 = F_100 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_366 )
F_71 ( L_125 ,
type == V_380 ? L_123 :
L_124 , V_20 ) ;
if ( V_395 < 2 ) {
V_148 = - V_169 ;
goto V_243;
}
V_394 [ 0 ] = V_20 & 0xff ;
V_394 [ 1 ] = ( V_20 >> 8 ) & 0xff ;
return 2 ;
} else if ( V_360 == ( type == V_380 ?
V_398 :
V_364 ) ) {
int V_399 ;
int V_370 = F_100 ( V_15 , 23 , 8 ) ;
if ( V_16 -> V_366 )
F_71 ( L_126 ,
type == V_380 ? L_123 :
L_124 , V_370 ) ;
if ( V_370 > V_395 ) {
V_148 = - V_169 ;
goto V_243;
}
for ( V_399 = 0 ; V_399 < V_370 + 2 ; ) {
int V_400 ;
V_15 = F_9 ( V_3 ,
F_135 ( V_69 ) ) ;
if ( V_16 -> V_366 )
F_71 ( L_127 ,
( V_15 >> 0 ) & 0xff ,
( V_15 >> 8 ) & 0xff ,
( V_15 >> 16 ) & 0xff ,
( V_15 >> 24 ) & 0xff ) ;
for ( V_400 = 0 ; V_400 < 4 ; ++ V_400 ) {
if ( V_399 < V_370 )
V_394 [ V_399 ] = ( V_15 >> ( V_400 * 8 ) ) & 0xff ;
++ V_399 ;
}
}
return V_370 ;
} else {
F_44 ( L_102 , V_360 ) ;
V_148 = - V_169 ;
goto V_243;
}
V_243:
F_44 ( L_128 , V_69 ,
type == V_380 ? L_123 : L_124 ) ;
return V_148 ;
}
static int F_188 ( struct V_5 * V_6 , int V_69 , T_3 V_387 ,
T_3 * V_394 , int V_395 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_148 ;
V_148 = F_185 ( V_3 , V_69 , V_387 ) ;
if ( V_148 )
goto V_243;
V_148 = F_174 ( V_6 , V_69 ) ;
if ( V_148 )
goto V_243;
V_148 = F_187 ( V_3 , V_69 , V_394 , V_395 ,
V_378 ) ;
if ( V_148 < 0 )
goto V_243;
if ( V_148 != V_395 ) {
V_148 = - V_169 ;
goto V_243;
}
return 0 ;
V_243:
F_44 ( L_129 , V_69 , V_387 ) ;
return V_148 ;
}
static int F_189 ( struct V_5 * V_6 , int V_69 ,
T_3 * V_389 , int V_390 , T_3 * V_394 , int V_395 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
int V_148 ;
V_148 = F_186 ( V_3 , V_69 , V_389 , V_390 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_174 ( V_6 , V_69 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_187 ( V_3 , V_69 , V_394 , V_395 ,
V_380 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_148 != V_395 ) {
V_148 = - V_169 ;
return V_148 ;
}
return 0 ;
}
static int F_190 ( struct V_5 * V_6 , int V_69 ,
T_12 V_370 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
return F_178 ( V_3 , V_69 ,
V_401 , V_370 , 0 ) ;
}
static int F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_159 ( V_22 ) ;
int V_148 , V_103 ;
unsigned V_21 ;
F_71 ( L_130 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_73 ( V_16 -> V_330 ) ;
if ( V_16 -> V_330 )
return 0 ;
if ( F_19 ( V_3 , V_186 , 13 , 13 ) ) {
F_86 ( V_3 , 0 ) ;
F_87 ( V_3 , V_186 , 0 , 13 , 13 ) ;
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
if ( F_19 ( V_3 , V_277 , 16 , 16 ) ) {
F_44 ( L_131 ) ;
return - V_169 ;
}
if ( F_19 ( V_3 , V_277 , 17 , 17 ) ) {
F_44 ( L_132 ) ;
return - V_169 ;
}
V_148 = F_67 ( V_3 , F_16 , & V_22 ,
V_402 ) ;
if ( V_148 )
return V_148 ;
V_21 = 0 ;
for ( V_103 = 0 ; V_103 < V_16 -> V_303 ; ++ V_103 ) {
if ( V_16 -> V_304 [ V_103 ] . V_305 == V_327 )
continue;
V_21 |= 1 << V_103 ;
}
F_87 ( V_3 , V_277 , V_21 , 9 , 5 ) ;
F_9 ( V_3 , V_277 ) ;
if ( F_160 ( & V_22 ,
F_20 ( 1000 ) ) == 0 ) {
F_44 ( L_133 ) ;
V_148 = - V_169 ;
goto V_243;
}
F_68 ( V_3 , F_16 , & V_22 ,
V_402 ) ;
F_87 ( V_3 , V_277 , 0 , 9 , 5 ) ;
F_9 ( V_3 , V_277 ) ;
F_138 ( V_3 , V_403 ) ;
F_86 ( V_3 , false ) ;
V_16 -> V_330 = true ;
return 0 ;
V_243:
F_68 ( V_3 , F_16 , & V_22 ,
V_402 ) ;
return V_148 ;
}
static void F_192 ( struct V_2 * V_3 ,
unsigned V_404 , bool V_405 , bool V_406 )
{
unsigned long V_407 ;
unsigned long V_408 ;
T_1 V_148 ;
F_61 ( V_404 > 0x1fff ) ;
V_407 = F_91 ( V_3 ) ;
V_148 = F_9 ( V_3 , V_270 ) ;
V_148 = F_115 ( V_148 , 1 , 15 , 15 ) ;
V_148 = F_115 ( V_148 , V_406 ? 1 : 0 , 14 , 14 ) ;
V_148 = F_115 ( V_148 , V_405 ? 1 : 0 , 13 , 13 ) ;
V_148 = F_115 ( V_148 , V_404 , 12 , 0 ) ;
F_7 ( V_3 , V_270 , V_148 ) ;
V_408 = V_404 * ( V_406 ? 16 : 1 ) * ( V_405 ? 4 : 1 ) ;
F_71 ( L_134 ,
V_408 ,
V_404 , V_405 ? L_135 : L_4 , V_406 ? L_136 : L_4 ,
( V_408 * 1000 ) / ( V_407 / 1000 / 1000 ) ) ;
}
static void F_193 ( struct V_2 * V_3 , unsigned V_404 ,
bool V_409 , bool V_406 )
{
unsigned long V_407 ;
unsigned long V_408 ;
T_1 V_148 ;
F_61 ( V_404 > 0x1fff ) ;
V_407 = F_91 ( V_3 ) ;
V_148 = F_9 ( V_3 , V_269 ) ;
V_148 = F_115 ( V_148 , 1 , 31 , 31 ) ;
V_148 = F_115 ( V_148 , V_406 ? 1 : 0 , 30 , 30 ) ;
V_148 = F_115 ( V_148 , V_409 ? 1 : 0 , 29 , 29 ) ;
V_148 = F_115 ( V_148 , V_404 , 28 , 16 ) ;
F_7 ( V_3 , V_269 , V_148 ) ;
V_408 = V_404 * ( V_406 ? 16 : 1 ) * ( V_409 ? 8 : 1 ) ;
F_71 ( L_137 ,
V_408 ,
V_404 , V_409 ? L_138 : L_4 , V_406 ? L_136 : L_4 ,
( V_408 * 1000 ) / ( V_407 / 1000 / 1000 ) ) ;
}
static void F_194 ( struct V_2 * V_3 ,
unsigned V_404 , bool V_405 , bool V_406 )
{
unsigned long V_407 ;
unsigned long V_408 ;
T_1 V_148 ;
F_61 ( V_404 > 0x1fff ) ;
V_407 = F_91 ( V_3 ) ;
V_148 = F_9 ( V_3 , V_269 ) ;
V_148 = F_115 ( V_148 , 1 , 15 , 15 ) ;
V_148 = F_115 ( V_148 , V_406 ? 1 : 0 , 14 , 14 ) ;
V_148 = F_115 ( V_148 , V_405 ? 1 : 0 , 13 , 13 ) ;
V_148 = F_115 ( V_148 , V_404 , 12 , 0 ) ;
F_7 ( V_3 , V_269 , V_148 ) ;
V_408 = V_404 * ( V_406 ? 16 : 1 ) * ( V_405 ? 4 : 1 ) ;
F_71 ( L_139 ,
V_408 ,
V_404 , V_405 ? L_135 : L_4 , V_406 ? L_136 : L_4 ,
( V_408 * 1000 ) / ( V_407 / 1000 / 1000 ) ) ;
}
static void F_195 ( struct V_2 * V_3 ,
unsigned V_404 , bool V_405 , bool V_406 )
{
unsigned long V_407 ;
unsigned long V_408 ;
T_1 V_148 ;
F_61 ( V_404 > 0x1fff ) ;
V_407 = F_90 ( V_3 ) ;
V_148 = F_9 ( V_3 , V_270 ) ;
V_148 = F_115 ( V_148 , 1 , 31 , 31 ) ;
V_148 = F_115 ( V_148 , V_406 ? 1 : 0 , 30 , 30 ) ;
V_148 = F_115 ( V_148 , V_405 ? 1 : 0 , 29 , 29 ) ;
V_148 = F_115 ( V_148 , V_404 , 28 , 16 ) ;
F_7 ( V_3 , V_270 , V_148 ) ;
V_408 = V_404 * ( V_406 ? 16 : 1 ) * ( V_405 ? 4 : 1 ) ;
F_71 ( L_140 ,
V_408 ,
V_404 , V_405 ? L_135 : L_4 , V_406 ? L_136 : L_4 ,
( V_408 * 1000 ) / ( V_407 / 1000 / 1000 ) ) ;
}
static void F_196 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_410 ;
if ( V_16 -> V_335 == V_336 ) {
int V_411 = F_25 ( V_16 -> V_412 ) ;
struct V_413 * V_414 = & V_16 -> V_414 ;
if ( V_16 -> V_415 <= V_414 -> V_416 * V_411 / 8 )
V_410 = 0 ;
else
V_410 = 2 ;
} else {
V_410 = 2 ;
}
F_87 ( V_3 , V_168 , V_410 , 13 , 12 ) ;
}
static void F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
bool V_417 ;
T_1 V_148 ;
if ( V_16 -> V_337 . V_418 == V_419 )
V_417 = true ;
else
V_417 = false ;
V_148 = F_9 ( V_3 , V_168 ) ;
V_148 = F_115 ( V_148 , 1 , 9 , 9 ) ;
V_148 = F_115 ( V_148 , 1 , 10 , 10 ) ;
V_148 = F_115 ( V_148 , 1 , 11 , 11 ) ;
V_148 = F_115 ( V_148 , 1 , 15 , 15 ) ;
V_148 = F_115 ( V_148 , V_417 , 16 , 16 ) ;
V_148 = F_115 ( V_148 , 1 , 17 , 17 ) ;
V_148 = F_115 ( V_148 , V_417 , 18 , 18 ) ;
F_7 ( V_3 , V_168 , V_148 ) ;
}
static void F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_420 = V_16 -> V_337 . V_420 ;
int V_421 = V_16 -> V_337 . V_421 ;
int V_422 = V_16 -> V_337 . V_422 ;
int V_423 = V_16 -> V_337 . V_423 ;
T_1 V_148 ;
V_148 = F_9 ( V_3 , V_168 ) ;
V_148 = F_115 ( V_148 , V_420 , 20 , 20 ) ;
V_148 = F_115 ( V_148 , V_421 , 21 , 21 ) ;
V_148 = F_115 ( V_148 , V_422 , 22 , 22 ) ;
V_148 = F_115 ( V_148 , V_423 , 23 , 23 ) ;
F_7 ( V_3 , V_168 , V_148 ) ;
}
static int F_199 ( int V_424 , bool V_425 , int V_426 ,
int V_427 , int V_428 , int V_429 , int V_430 )
{
int V_431 ;
if ( V_425 ) {
V_431 = V_426 + V_427 + F_105 ( V_426 , 2 ) + 1 ;
} else {
int V_432 , V_433 ;
V_432 = V_429 + V_426 + V_427 + F_105 ( V_426 , 2 ) + 1 ;
V_433 = V_429 + V_426 + V_428 + V_430 + V_429 +
V_426 + 1 ;
V_431 = F_105 ( V_432 , V_433 ) ;
}
return V_424 > V_431 ? V_424 - V_431 : 0 ;
}
static int F_200 ( int V_424 , int V_426 , int V_427 ,
int V_182 , int V_434 )
{
int V_435 ;
int V_436 ;
int V_437 ;
int V_438 = 16 ;
int V_439 ;
V_435 = V_427 + F_105 ( V_426 , 2 ) + 1 ;
V_436 = V_438 * ( V_424 - V_435 ) ;
V_437 = V_434 * V_182 ;
V_439 = ( ( V_436 - 8 * V_438 - 5 * V_434 ) / V_437 -
26 ) / 16 ;
return F_105 ( V_439 , 0 ) ;
}
static void F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_420 ;
int V_421 , V_422 , V_423 ;
int V_440 , V_441 , V_442 , V_443 , V_444 , V_182 ;
int V_445 , V_446 , V_447 , V_448 ;
int V_314 , V_312 , V_428 ;
bool V_425 ;
struct V_413 * V_414 = & V_16 -> V_414 ;
int V_411 = F_25 ( V_16 -> V_412 ) ;
int V_449 = V_16 -> V_299 - 1 ;
int V_450 = V_16 -> V_184 . V_219 + 1 ;
int V_451 = 0 , V_452 = 0 ;
int V_453 = 0 , V_454 = 0 ;
int V_455 = 0 , V_456 = 0 ;
int V_457 = 0 , V_458 = 0 ;
T_1 V_148 ;
V_148 = F_9 ( V_3 , V_168 ) ;
V_420 = F_100 ( V_148 , 20 , 20 ) ;
V_421 = F_100 ( V_148 , 21 , 21 ) ;
V_422 = F_100 ( V_148 , 22 , 22 ) ;
V_423 = F_100 ( V_148 , 23 , 23 ) ;
V_148 = F_9 ( V_3 , V_271 ) ;
V_442 = F_100 ( V_148 , 11 , 0 ) ;
V_441 = F_100 ( V_148 , 23 , 12 ) ;
V_440 = F_100 ( V_148 , 31 , 24 ) ;
V_148 = F_9 ( V_3 , V_274 ) ;
V_446 = F_100 ( V_148 , 7 , 0 ) ;
V_445 = F_100 ( V_148 , 15 , 8 ) ;
V_148 = F_9 ( V_3 , V_283 ) ;
V_448 = F_100 ( V_148 , 15 , 0 ) ;
V_447 = F_100 ( V_148 , 31 , 16 ) ;
V_148 = F_9 ( V_3 , V_186 ) ;
V_182 = F_100 ( V_148 , 12 , 0 ) ;
V_425 = F_100 ( V_148 , 13 , 13 ) ;
V_148 = F_9 ( V_3 , V_285 ) ;
V_312 = F_100 ( V_148 , 7 , 0 ) ;
V_148 = F_9 ( V_3 , V_286 ) ;
V_314 = F_100 ( V_148 , 15 , 8 ) ;
V_428 = V_312 + V_314 ;
V_443 = F_95 ( V_414 -> V_416 * V_411 , 8 ) ;
V_444 = V_442 + V_441 + V_440 + F_95 ( V_443 + 6 , V_449 ) ;
if ( ! V_423 ) {
V_451 = F_199 ( V_440 , V_425 ,
V_447 , V_448 ,
V_428 , V_445 , V_446 ) ;
V_452 = F_200 ( V_440 ,
V_447 , V_448 ,
V_182 , V_450 ) ;
}
if ( ! V_421 ) {
V_453 = F_199 ( V_441 , V_425 ,
V_447 , V_448 ,
V_428 , V_445 , V_446 ) ;
V_454 = F_200 ( V_441 ,
V_447 , V_448 ,
V_182 , V_450 ) ;
}
if ( ! V_422 ) {
V_455 = F_199 ( V_442 , V_425 ,
V_447 , V_448 ,
V_428 , V_445 , V_446 ) ;
V_456 = F_200 ( V_442 ,
V_447 , V_448 ,
V_182 , V_450 ) ;
}
if ( ! V_420 ) {
V_457 = F_199 ( V_444 , V_425 ,
V_447 , V_448 ,
V_428 , V_445 , V_446 ) ;
V_458 = F_200 ( V_444 ,
V_447 , V_448 ,
V_182 , V_450 ) ;
}
F_71 ( L_141 ,
V_451 , V_453 , V_455 ,
V_457 ) ;
F_71 ( L_142 ,
V_452 , V_454 , V_456 ,
V_458 ) ;
V_148 = F_9 ( V_3 , V_279 ) ;
V_148 = F_115 ( V_148 , V_451 , 23 , 16 ) ;
V_148 = F_115 ( V_148 , V_453 , 15 , 8 ) ;
V_148 = F_115 ( V_148 , V_455 , 7 , 0 ) ;
F_7 ( V_3 , V_279 , V_148 ) ;
V_148 = F_9 ( V_3 , V_281 ) ;
V_148 = F_115 ( V_148 , V_452 , 23 , 16 ) ;
V_148 = F_115 ( V_148 , V_454 , 15 , 8 ) ;
V_148 = F_115 ( V_148 , V_456 , 7 , 0 ) ;
F_7 ( V_3 , V_281 , V_148 ) ;
V_148 = F_9 ( V_3 , V_282 ) ;
V_148 = F_115 ( V_148 , V_457 , 31 , 15 ) ;
V_148 = F_115 ( V_148 , V_458 , 16 , 0 ) ;
F_7 ( V_3 , V_282 , V_148 ) ;
}
static int F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_1 V_148 ;
int V_459 = 0 ;
F_152 ( V_3 , V_460 ,
V_460 ,
V_460 ,
V_460 ) ;
F_154 ( V_3 , V_460 ,
V_460 ,
V_460 ,
V_460 ) ;
F_194 ( V_3 , 0x1000 , false , false ) ;
F_193 ( V_3 , 0x1fff , true , true ) ;
F_192 ( V_3 , 0x1fff , true , true ) ;
F_195 ( V_3 , 0x1fff , true , true ) ;
switch ( F_25 ( V_16 -> V_412 ) ) {
case 16 :
V_459 = 0 ;
break;
case 18 :
V_459 = 1 ;
break;
case 24 :
V_459 = 2 ;
break;
default:
F_26 () ;
return - V_146 ;
}
V_148 = F_9 ( V_3 , V_168 ) ;
V_148 = F_115 ( V_148 , 1 , 1 , 1 ) ;
V_148 = F_115 ( V_148 , 1 , 2 , 2 ) ;
V_148 = F_115 ( V_148 , 1 , 3 , 3 ) ;
V_148 = F_115 ( V_148 , 1 , 4 , 4 ) ;
V_148 = F_115 ( V_148 , V_459 , 7 , 6 ) ;
V_148 = F_115 ( V_148 , 0 , 8 , 8 ) ;
V_148 = F_115 ( V_148 , 1 , 14 , 14 ) ;
V_148 = F_115 ( V_148 , 1 , 19 , 19 ) ;
if ( ! F_84 ( V_359 ) ) {
V_148 = F_115 ( V_148 , 1 , 24 , 24 ) ;
V_148 = F_115 ( V_148 , 0 , 25 , 25 ) ;
}
F_7 ( V_3 , V_168 , V_148 ) ;
F_196 ( V_3 ) ;
if ( V_16 -> V_335 == V_336 ) {
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
unsigned V_461 , V_315 , V_316 , V_314 ;
unsigned V_462 , V_463 ;
unsigned V_309 , V_310 , V_464 ;
unsigned V_311 , V_312 ;
unsigned V_445 , V_446 ;
unsigned V_447 , V_448 ;
unsigned V_465 ;
int V_449 = V_16 -> V_299 - 1 ;
T_1 V_148 ;
V_148 = F_9 ( V_3 , V_285 ) ;
V_309 = F_100 ( V_148 , 31 , 24 ) ;
V_310 = F_100 ( V_148 , 23 , 16 ) ;
V_464 = V_310 - V_309 ;
V_311 = F_100 ( V_148 , 15 , 8 ) ;
V_312 = F_100 ( V_148 , 7 , 0 ) ;
V_148 = F_9 ( V_3 , V_286 ) ;
V_461 = F_100 ( V_148 , 20 , 16 ) * 2 ;
V_314 = F_100 ( V_148 , 15 , 8 ) ;
V_315 = F_100 ( V_148 , 7 , 0 ) ;
V_148 = F_9 ( V_3 , V_287 ) ;
V_316 = F_100 ( V_148 , 7 , 0 ) ;
V_462 = 20 ;
V_463 = F_141 ( V_3 , 60 ) + 26 ;
V_465 = F_95 ( 4 , V_449 ) ;
V_445 = F_95 ( V_462 + V_461 + V_315 + V_316 ,
4 ) ;
V_446 = F_95 ( V_463 + V_311 , 4 ) + V_465 ;
F_61 ( V_445 == 0 || V_445 > 255 ) ;
F_61 ( V_446 == 0 || V_446 > 255 ) ;
V_148 = F_9 ( V_3 , V_274 ) ;
V_148 = F_115 ( V_148 , V_445 , 15 , 8 ) ;
V_148 = F_115 ( V_148 , V_446 , 7 , 0 ) ;
F_7 ( V_3 , V_274 , V_148 ) ;
F_71 ( L_143 ,
V_445 ,
V_446 ) ;
V_447 = 1 + F_95 ( V_461 , 4 ) +
F_95 ( V_309 , 4 ) +
F_95 ( V_464 + 3 , 4 ) ;
V_448 = F_95 ( V_311 + V_312 , 4 ) + 1 + V_465 ;
V_148 = F_153 ( V_447 , 31 , 16 ) |
F_153 ( V_448 , 15 , 0 ) ;
F_7 ( V_3 , V_283 , V_148 ) ;
F_71 ( L_144 ,
V_447 , V_448 ) ;
if ( V_16 -> V_335 == V_336 ) {
int V_440 = V_16 -> V_337 . V_440 ;
int V_441 = V_16 -> V_337 . V_441 ;
int V_442 = V_16 -> V_337 . V_442 ;
int V_466 = V_16 -> V_337 . V_466 ;
int V_467 = V_16 -> V_337 . V_467 ;
int V_468 = V_16 -> V_337 . V_468 ;
int V_469 = V_16 -> V_337 . V_469 ;
bool V_470 ;
struct V_413 * V_414 = & V_16 -> V_414 ;
int V_411 = F_25 ( V_16 -> V_412 ) ;
int V_471 , V_472 , V_443 ;
V_470 = V_16 -> V_337 . V_418 == V_419 ;
V_472 = V_470 ?
( ( V_440 == 0 && V_449 == 3 ) ? 1 : F_95 ( 4 , V_449 ) ) : 0 ;
V_443 = F_95 ( V_414 -> V_416 * V_411 , 8 ) ;
V_471 = F_95 ( 4 , V_449 ) + ( V_470 ? V_440 : 0 ) + V_472 + V_441 +
F_95 ( V_443 + 6 , V_449 ) + V_442 ;
F_71 ( L_145 , V_442 ,
V_441 , V_470 ? V_440 : 0 , V_471 ) ;
F_71 ( L_146 , V_468 , V_467 ,
V_466 , V_414 -> V_473 ) ;
V_148 = F_9 ( V_3 , V_271 ) ;
V_148 = F_115 ( V_148 , V_442 , 11 , 0 ) ;
V_148 = F_115 ( V_148 , V_441 , 23 , 12 ) ;
V_148 = F_115 ( V_148 , V_470 ? V_440 : 0 , 31 , 24 ) ;
F_7 ( V_3 , V_271 , V_148 ) ;
V_148 = F_9 ( V_3 , V_272 ) ;
V_148 = F_115 ( V_148 , V_468 , 7 , 0 ) ;
V_148 = F_115 ( V_148 , V_467 , 15 , 8 ) ;
V_148 = F_115 ( V_148 , V_466 , 23 , 16 ) ;
V_148 = F_115 ( V_148 , V_469 , 27 , 24 ) ;
F_7 ( V_3 , V_272 , V_148 ) ;
V_148 = F_9 ( V_3 , V_273 ) ;
V_148 = F_115 ( V_148 , V_414 -> V_473 , 14 , 0 ) ;
V_148 = F_115 ( V_148 , V_471 , 31 , 16 ) ;
F_7 ( V_3 , V_273 , V_148 ) ;
}
}
static int F_204 ( struct V_5 * V_6 ,
const struct V_474 * V_475 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_476 ;
const int * V_477 ;
struct V_478 V_304 [ V_324 ] ;
int V_479 ;
int V_103 ;
static const enum V_292 V_293 [] = {
V_294 ,
V_295 ,
V_296 ,
V_297 ,
V_298 ,
} ;
V_476 = V_475 -> V_476 ;
V_477 = V_475 -> V_477 ;
if ( V_476 < 4 || V_476 > V_16 -> V_303 * 2
|| V_476 % 2 != 0 )
return - V_146 ;
for ( V_103 = 0 ; V_103 < V_324 ; ++ V_103 )
V_304 [ V_103 ] . V_305 = V_327 ;
V_479 = 0 ;
for ( V_103 = 0 ; V_103 < V_476 ; V_103 += 2 ) {
T_3 V_480 , V_481 ;
int V_482 , V_483 ;
V_482 = V_477 [ V_103 ] ;
V_483 = V_477 [ V_103 + 1 ] ;
if ( V_482 < 0 || V_482 >= V_16 -> V_303 * 2 )
return - V_146 ;
if ( V_483 < 0 || V_483 >= V_16 -> V_303 * 2 )
return - V_146 ;
if ( V_482 & 1 ) {
if ( V_483 != V_482 - 1 )
return - V_146 ;
V_481 = 1 ;
} else {
if ( V_483 != V_482 + 1 )
return - V_146 ;
V_481 = 0 ;
}
V_480 = V_482 / 2 ;
V_304 [ V_480 ] . V_305 = V_293 [ V_103 / 2 ] ;
V_304 [ V_480 ] . V_301 = V_481 ;
V_479 ++ ;
}
memcpy ( V_16 -> V_304 , V_304 , sizeof( V_16 -> V_304 ) ) ;
V_16 -> V_299 = V_479 ;
return 0 ;
}
static int F_205 ( struct V_5 * V_6 , int V_69 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_484 * V_485 = V_16 -> V_486 . V_487 ;
int V_411 = F_25 ( V_16 -> V_412 ) ;
struct V_5 * V_8 = & V_16 -> V_486 ;
T_3 V_369 ;
T_12 V_488 ;
int V_148 ;
if ( V_8 == NULL || V_8 -> V_487 == NULL ) {
F_44 ( L_147 ) ;
return - V_193 ;
}
V_148 = F_206 ( V_3 , V_485 ) ;
if ( V_148 )
goto V_489;
if ( V_16 -> V_335 == V_336 ) {
switch ( V_16 -> V_412 ) {
case V_33 :
V_369 = V_490 ;
break;
case V_34 :
V_369 = V_491 ;
break;
case V_35 :
V_369 = V_492 ;
break;
case V_36 :
V_369 = V_493 ;
break;
default:
V_148 = - V_146 ;
goto V_494;
} ;
F_86 ( V_3 , false ) ;
F_165 ( V_3 , V_69 , false ) ;
F_87 ( V_3 , F_131 ( V_69 ) , 1 , 4 , 4 ) ;
V_488 = F_95 ( V_16 -> V_414 . V_416 * V_411 , 8 ) ;
F_175 ( V_3 , V_69 , V_369 ,
V_488 , 0 ) ;
F_165 ( V_3 , V_69 , true ) ;
F_86 ( V_3 , true ) ;
}
V_148 = F_207 ( V_485 ) ;
if ( V_148 )
goto V_495;
return 0 ;
V_495:
if ( V_16 -> V_335 == V_336 ) {
F_86 ( V_3 , false ) ;
F_165 ( V_3 , V_69 , false ) ;
}
V_494:
F_208 ( V_3 , V_485 ) ;
V_489:
return V_148 ;
}
static void F_209 ( struct V_5 * V_6 , int V_69 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_484 * V_485 = V_16 -> V_486 . V_487 ;
if ( V_16 -> V_335 == V_336 ) {
F_86 ( V_3 , false ) ;
F_165 ( V_3 , V_69 , false ) ;
F_87 ( V_3 , F_131 ( V_69 ) , 0 , 4 , 4 ) ;
F_165 ( V_3 , V_69 , true ) ;
F_86 ( V_3 , true ) ;
}
F_210 ( V_485 ) ;
F_208 ( V_3 , V_485 ) ;
}
static void F_211 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_484 * V_485 = V_16 -> V_486 . V_487 ;
unsigned V_496 ;
unsigned V_497 ;
unsigned V_498 ;
unsigned V_499 ;
unsigned V_500 ;
unsigned V_501 ;
T_1 V_159 ;
int V_148 ;
const unsigned V_69 = V_16 -> V_350 ;
const unsigned V_502 = V_16 -> V_415 ;
T_12 V_399 = V_16 -> V_414 . V_416 ;
T_12 V_503 = V_16 -> V_414 . V_473 ;
F_71 ( L_148 , V_399 , V_503 ) ;
F_167 ( V_3 , V_69 , V_355 ) ;
V_496 = F_25 ( V_16 -> V_412 ) / 8 ;
V_497 = V_399 * V_496 ;
V_498 = V_497 * V_503 ;
if ( V_498 < V_502 )
V_500 = V_498 ;
else
V_500 = ( V_502 ) / V_497 * V_497 ;
V_501 = V_500 + 1 ;
V_499 = ( V_498 / V_500 ) * V_501 ;
if ( V_498 % V_500 )
V_499 += ( V_498 % V_500 ) + 1 ;
V_159 = F_153 ( V_499 , 23 , 0 ) ;
F_7 ( V_3 , F_132 ( V_69 ) , V_159 ) ;
F_175 ( V_3 , V_69 , V_386 ,
V_501 , 0 ) ;
if ( V_16 -> V_352 )
V_159 = F_115 ( V_159 , 1 , 30 , 30 ) ;
else
V_159 = F_115 ( V_159 , 1 , 31 , 31 ) ;
F_7 ( V_3 , F_132 ( V_69 ) , V_159 ) ;
F_212 () ;
F_29 ( V_3 ) ;
V_148 = F_213 ( & V_16 -> V_504 ,
F_20 ( 250 ) ) ;
F_61 ( V_148 == 0 ) ;
F_214 ( V_485 , & V_16 -> V_414 ) ;
F_215 ( V_485 ) ;
if ( V_16 -> V_352 ) {
F_87 ( V_3 , V_270 , 0 , 15 , 15 ) ;
F_173 ( V_3 , V_69 ) ;
#ifdef F_50
F_216 ( & V_16 -> V_134 , V_28 + F_20 ( 250 ) ) ;
#endif
}
}
static void F_217 ( unsigned long V_121 )
{
F_44 ( L_149 ) ;
}
static void F_218 ( struct V_2 * V_3 , int error )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_219 () ;
if ( V_16 -> V_352 ) {
F_87 ( V_3 , V_270 , 1 , 15 , 15 ) ;
}
V_16 -> V_505 ( error , V_16 -> V_506 ) ;
if ( ! error )
F_30 ( V_3 , L_150 ) ;
}
static void F_220 ( struct V_507 * V_508 )
{
struct V_1 * V_16 = F_221 ( V_508 , struct V_1 ,
V_504 . V_508 ) ;
F_44 ( L_151 ) ;
F_218 ( V_16 -> V_150 , - V_509 ) ;
}
static void F_222 ( void * V_20 )
{
struct V_2 * V_3 = (struct V_2 * ) V_20 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_223 ( & V_16 -> V_504 ) ;
F_218 ( V_3 , 0 ) ;
}
static int F_224 ( struct V_5 * V_6 , int V_69 ,
void (* F_225)( int , void * ) , void * V_20 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
T_12 V_510 , V_511 ;
F_27 ( V_3 ) ;
V_16 -> V_350 = V_69 ;
V_16 -> V_505 = F_225 ;
V_16 -> V_506 = V_20 ;
V_510 = V_16 -> V_414 . V_416 ;
V_511 = V_16 -> V_414 . V_473 ;
#ifdef F_226
V_16 -> V_47 = V_510 * V_511 *
F_25 ( V_16 -> V_412 ) / 8 ;
#endif
F_211 ( V_3 ) ;
return 0 ;
}
static int F_227 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_512 V_513 ;
int V_148 ;
unsigned long V_407 ;
V_407 = F_88 ( V_3 ) ;
V_513 . V_514 = V_16 -> V_515 . V_514 ;
V_513 . V_516 = V_16 -> V_515 . V_516 ;
V_148 = F_228 ( V_407 , & V_513 ) ;
if ( V_148 ) {
F_44 ( L_152 ) ;
return V_148 ;
}
V_16 -> V_517 . V_518 = V_513 ;
return 0 ;
}
static int F_206 ( struct V_2 * V_3 ,
struct V_484 * V_485 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 ;
F_229 ( V_485 -> V_10 , V_16 -> V_174 == 0 ?
V_230 :
V_259 ) ;
if ( V_16 -> V_335 == V_519 ) {
V_148 = F_230 ( V_485 ,
F_222 , V_3 ) ;
if ( V_148 ) {
F_44 ( L_153 ) ;
goto V_243;
}
V_16 -> V_517 . V_520 = true ;
V_16 -> V_517 . V_521 = true ;
} else {
V_16 -> V_517 . V_520 = false ;
V_16 -> V_517 . V_521 = false ;
}
V_16 -> V_414 . V_522 = false ;
V_16 -> V_414 . V_523 = V_524 ;
V_16 -> V_414 . V_525 = V_524 ;
V_16 -> V_414 . V_526 = V_527 ;
V_16 -> V_414 . V_528 = V_524 ;
V_16 -> V_414 . V_529 = V_530 ;
F_214 ( V_485 , & V_16 -> V_414 ) ;
V_148 = F_227 ( V_3 ) ;
if ( V_148 )
goto V_249;
V_16 -> V_517 . V_531 = V_532 ;
V_16 -> V_517 . V_533 =
F_25 ( V_16 -> V_412 ) ;
V_16 -> V_517 . V_534 = 0 ;
F_231 ( V_485 , & V_16 -> V_517 ) ;
return 0 ;
V_249:
if ( V_16 -> V_335 == V_519 )
F_232 ( V_485 ,
F_222 , V_3 ) ;
V_243:
F_229 ( V_485 -> V_10 , V_175 ) ;
return V_148 ;
}
static void F_208 ( struct V_2 * V_3 ,
struct V_484 * V_485 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_16 -> V_335 == V_519 )
F_232 ( V_485 ,
F_222 , V_3 ) ;
F_229 ( V_485 -> V_10 , V_175 ) ;
}
static int F_233 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_177 V_178 ;
int V_148 ;
V_178 = V_16 -> V_184 ;
V_148 = F_109 ( V_3 , & V_178 ) ;
if ( V_148 ) {
F_44 ( L_154 ) ;
return V_148 ;
}
V_148 = F_111 ( V_3 , & V_178 ) ;
if ( V_148 ) {
F_44 ( L_155 ) ;
return V_148 ;
}
return 0 ;
}
static int F_234 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 ;
V_148 = F_116 ( V_3 , true , true ) ;
if ( V_148 )
goto V_248;
V_148 = F_233 ( V_3 ) ;
if ( V_148 )
goto V_249;
F_235 ( V_16 -> V_174 , V_16 -> V_174 == 0 ?
V_231 :
V_260 ) ;
F_71 ( L_156 ) ;
V_148 = F_148 ( V_3 ) ;
if ( V_148 )
goto V_368;
F_83 ( V_3 ) ;
F_203 ( V_3 ) ;
F_96 ( V_3 ) ;
if ( 1 )
F_83 ( V_3 ) ;
V_148 = F_202 ( V_3 ) ;
if ( V_148 )
goto V_535;
F_165 ( V_3 , 0 , 1 ) ;
F_165 ( V_3 , 1 , 1 ) ;
F_165 ( V_3 , 2 , 1 ) ;
F_165 ( V_3 , 3 , 1 ) ;
F_86 ( V_3 , 1 ) ;
F_155 ( V_3 ) ;
return 0 ;
V_535:
F_151 ( V_3 ) ;
V_368:
F_235 ( V_16 -> V_174 , V_175 ) ;
V_249:
F_120 ( V_3 , true ) ;
V_248:
return V_148 ;
}
static void F_236 ( struct V_2 * V_3 ,
bool V_252 , bool V_536 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_536 && ! V_16 -> V_330 )
F_191 ( V_3 ) ;
F_86 ( V_3 , 0 ) ;
F_165 ( V_3 , 0 , 0 ) ;
F_165 ( V_3 , 1 , 0 ) ;
F_165 ( V_3 , 2 , 0 ) ;
F_165 ( V_3 , 3 , 0 ) ;
F_235 ( V_16 -> V_174 , V_175 ) ;
F_151 ( V_3 ) ;
F_120 ( V_3 , V_252 ) ;
}
static int F_237 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_148 = 0 ;
F_71 ( L_157 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_238 ( & V_16 -> V_537 ) ;
V_148 = F_70 ( V_3 ) ;
if ( V_148 )
goto V_538;
F_80 ( V_3 , 1 ) ;
F_57 ( V_3 ) ;
V_148 = F_234 ( V_3 ) ;
if ( V_148 )
goto V_539;
F_239 ( & V_16 -> V_537 ) ;
return 0 ;
V_539:
F_80 ( V_3 , 0 ) ;
F_74 ( V_3 ) ;
V_538:
F_239 ( & V_16 -> V_537 ) ;
F_71 ( L_158 ) ;
return V_148 ;
}
static void F_240 ( struct V_5 * V_6 ,
bool V_252 , bool V_536 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_71 ( L_159 ) ;
F_73 ( ! F_15 ( V_3 ) ) ;
F_238 ( & V_16 -> V_537 ) ;
F_163 ( V_3 , 0 ) ;
F_163 ( V_3 , 1 ) ;
F_163 ( V_3 , 2 ) ;
F_163 ( V_3 , 3 ) ;
F_236 ( V_3 , V_252 , V_536 ) ;
F_74 ( V_3 ) ;
F_80 ( V_3 , 0 ) ;
F_239 ( & V_16 -> V_537 ) ;
}
static int F_241 ( struct V_5 * V_6 , bool V_155 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_352 = V_155 ;
return 0 ;
}
static void F_242 ( const char * V_540 ,
const struct V_541 * V_27 )
{
unsigned long V_542 = V_27 -> V_543 / 4 ;
int V_544 , V_545 , V_546 , V_547 ;
V_545 = F_95 ( V_27 -> V_548 * V_27 -> V_549 , 8 ) ;
V_546 = F_95 ( V_545 + 6 , V_27 -> V_449 ) ;
V_544 = V_27 -> V_550 + V_27 -> V_440 + V_27 -> V_551 + V_27 -> V_442 + V_27 -> V_441 ;
V_547 = V_544 + V_546 ;
#define F_243 ( T_4 ) ((u32)div64_u64((u64)x * 1000000000llu, byteclk))
F_36 ( L_160
L_161 ,
V_540 ,
V_542 ,
V_27 -> V_550 , V_27 -> V_440 , V_27 -> V_551 , V_27 -> V_442 , V_546 , V_27 -> V_441 ,
V_544 , V_546 , V_547 ,
F_243 ( V_27 -> V_550 ) ,
F_243 ( V_27 -> V_440 ) ,
F_243 ( V_27 -> V_551 ) ,
F_243 ( V_27 -> V_442 ) ,
F_243 ( V_546 ) ,
F_243 ( V_27 -> V_441 ) ,
F_243 ( V_544 ) ,
F_243 ( V_546 ) ,
F_243 ( V_547 ) ) ;
#undef F_243
}
static void F_244 ( const char * V_540 , const struct V_413 * V_27 )
{
unsigned long V_552 = V_27 -> V_553 * 1000 ;
int V_548 , V_544 , V_547 ;
V_548 = V_27 -> V_416 ;
V_544 = V_27 -> V_554 + V_27 -> V_442 + V_27 -> V_441 ;
V_547 = V_548 + V_544 ;
#define F_245 ( T_4 ) ((u32)div64_u64((u64)x * 1000000000llu, pck))
F_36 ( L_162
L_163 ,
V_540 ,
V_552 ,
V_27 -> V_554 , V_27 -> V_442 , V_548 , V_27 -> V_441 ,
V_544 , V_548 , V_547 ,
F_245 ( V_27 -> V_554 ) ,
F_245 ( V_27 -> V_442 ) ,
F_245 ( V_548 ) ,
F_245 ( V_27 -> V_441 ) ,
F_245 ( V_544 ) ,
F_245 ( V_548 ) ,
F_245 ( V_547 ) ) ;
#undef F_245
}
static void F_246 ( const char * V_540 ,
const struct V_541 * V_27 )
{
struct V_413 V_555 = { 0 } ;
unsigned long V_542 = V_27 -> V_543 / 4 ;
unsigned long V_552 ;
T_13 V_556 ;
int V_557 , V_558 ;
V_556 = ( T_13 ) V_542 * V_27 -> V_449 * 8 ;
V_552 = ( T_1 ) F_247 ( V_556 , V_27 -> V_549 ) ;
V_557 = F_95 ( F_95 ( V_27 -> V_548 * V_27 -> V_549 , 8 ) + 6 , V_27 -> V_449 ) ;
V_558 = V_27 -> V_550 + V_27 -> V_440 + V_27 -> V_551 + V_27 -> V_442 + V_557 + V_27 -> V_441 ;
V_555 . V_553 = V_552 / 1000 ;
V_555 . V_554 = F_247 ( ( T_13 ) ( V_27 -> V_440 + V_27 -> V_551 ) * V_552 , V_542 ) ;
V_555 . V_442 = F_247 ( ( T_13 ) V_27 -> V_442 * V_552 , V_542 ) ;
V_555 . V_441 = F_247 ( ( T_13 ) V_27 -> V_441 * V_552 , V_542 ) ;
V_555 . V_416 = V_27 -> V_548 ;
F_244 ( V_540 , & V_555 ) ;
}
static bool F_248 ( int V_559 , int V_560 , unsigned long V_561 ,
unsigned long V_552 , void * V_20 )
{
struct V_562 * V_563 = V_20 ;
struct V_413 * V_27 = & V_563 -> V_564 ;
V_563 -> V_513 . V_514 = V_559 ;
V_563 -> V_513 . V_516 = V_560 ;
V_563 -> V_513 . V_561 = V_561 ;
V_563 -> V_513 . V_552 = V_552 ;
* V_27 = * V_563 -> V_565 -> V_414 ;
V_27 -> V_553 = V_552 / 1000 ;
V_27 -> V_416 = V_563 -> V_565 -> V_414 -> V_416 ;
V_27 -> V_473 = V_563 -> V_565 -> V_414 -> V_473 ;
V_27 -> V_554 = V_27 -> V_441 = V_27 -> V_442 = V_27 -> V_566 = 1 ;
V_27 -> V_467 = V_27 -> V_468 = 0 ;
return true ;
}
static bool F_249 ( int V_218 , unsigned long V_567 ,
void * V_20 )
{
struct V_562 * V_563 = V_20 ;
V_563 -> V_568 . V_218 = V_218 ;
V_563 -> V_568 . V_171 = V_567 ;
return F_250 ( V_567 , V_563 -> V_569 , V_563 -> V_570 ,
F_248 , V_563 ) ;
}
static bool F_251 ( int V_206 , int V_197 , unsigned long V_209 ,
unsigned long V_194 , void * V_20 )
{
struct V_562 * V_563 = V_20 ;
V_563 -> V_568 . V_206 = V_206 ;
V_563 -> V_568 . V_197 = V_197 ;
V_563 -> V_568 . V_209 = V_209 ;
V_563 -> V_568 . V_173 = V_194 ;
return F_103 ( V_563 -> V_3 , V_194 , V_563 -> V_569 ,
F_249 , V_563 ) ;
}
static bool F_252 ( struct V_1 * V_16 ,
const struct V_571 * V_572 ,
struct V_562 * V_563 )
{
unsigned long V_203 ;
int V_549 , V_449 ;
unsigned long V_204 , V_205 ;
unsigned long V_552 , V_573 ;
V_203 = F_93 ( V_16 -> V_156 ) ;
V_549 = F_25 ( V_572 -> V_574 ) ;
V_449 = V_16 -> V_299 - 1 ;
V_552 = V_572 -> V_414 -> V_553 * 1000 ;
V_552 = V_552 * 3 / 2 ;
V_573 = V_552 * V_549 / 8 / V_449 ;
memset ( V_563 , 0 , sizeof( * V_563 ) ) ;
V_563 -> V_3 = V_16 -> V_150 ;
V_563 -> V_565 = V_572 ;
V_563 -> V_569 = V_552 ;
V_563 -> V_575 = V_552 ;
V_563 -> V_570 = V_552 * 3 / 2 ;
V_563 -> V_568 . V_203 = V_203 ;
V_204 = F_105 ( V_572 -> V_576 * 4 , V_573 * 4 * 4 ) ;
V_205 = V_572 -> V_577 * 4 ;
return F_107 ( V_16 -> V_150 , V_203 ,
V_204 , V_205 ,
F_251 , V_563 ) ;
}
static bool F_253 ( struct V_562 * V_563 )
{
struct V_1 * V_16 = F_1 ( V_563 -> V_3 ) ;
const struct V_571 * V_572 = V_563 -> V_565 ;
int V_549 = F_25 ( V_572 -> V_574 ) ;
int V_449 = V_16 -> V_299 - 1 ;
unsigned long V_543 = V_563 -> V_568 . V_173 / 4 ;
unsigned long V_542 = V_543 / 4 ;
unsigned long V_578 , V_569 , V_575 , V_570 ;
int V_579 ;
int V_580 , V_581 ;
int V_582 , V_583 ;
int V_558 , V_557 , V_584 , V_550 , V_551 ;
int V_441 , V_440 , V_442 ;
const struct V_413 * V_585 ;
struct V_413 * V_564 ;
struct V_541 * V_586 ;
T_13 V_556 , V_587 ;
V_556 = ( T_13 ) V_542 * V_449 * 8 ;
V_585 = V_572 -> V_414 ;
V_569 = V_563 -> V_569 ;
V_570 = V_563 -> V_570 ;
V_575 = V_563 -> V_575 ;
V_578 = V_563 -> V_513 . V_552 ;
V_587 = ( T_13 ) V_578 * V_549 ;
V_579 = V_585 -> V_416 ;
V_581 = V_585 -> V_441 + V_585 -> V_442 + V_585 -> V_554 ;
V_580 = V_579 + V_581 ;
V_557 = F_95 ( F_95 ( V_579 * V_549 , 8 ) + 6 , V_449 ) ;
if ( V_16 -> V_415 < V_579 * V_549 / 8 ) {
if ( V_587 != V_556 )
return false ;
} else {
if ( V_587 < V_556 )
return false ;
}
if ( V_556 < ( T_13 ) V_549 * V_569 )
return false ;
if ( V_572 -> V_418 != V_588 ) {
if ( V_556 > ( T_13 ) V_549 * V_570 )
return false ;
}
V_550 = F_95 ( 4 , V_449 ) ;
if ( V_572 -> V_418 == V_419 ) {
if ( V_449 == 3 && V_585 -> V_554 == 0 )
V_551 = 1 ;
else
V_551 = F_95 ( 4 , V_449 ) ;
} else {
V_551 = 0 ;
}
V_558 = F_247 ( ( T_13 ) V_580 * V_542 , V_575 ) ;
if ( V_558 < V_550 + V_551 + V_557 )
return false ;
V_584 = V_558 - V_557 ;
V_582 = F_247 ( ( T_13 ) V_558 * V_578 , V_542 ) ;
if ( ( T_13 ) V_558 * V_578 != ( T_13 ) V_582 * V_542 )
return false ;
V_583 = V_582 - V_579 ;
V_586 = & V_563 -> V_586 ;
memset ( V_586 , 0 , sizeof( * V_586 ) ) ;
V_586 -> V_543 = V_543 ;
V_586 -> V_449 = V_449 ;
V_586 -> V_549 = V_549 ;
if ( V_572 -> V_418 != V_419 ) {
V_440 = 0 ;
} else if ( V_449 == 3 && V_585 -> V_554 == 0 ) {
V_440 = 0 ;
} else {
V_440 = F_247 ( ( T_13 ) V_585 -> V_554 * V_542 , V_575 ) ;
V_440 = F_105 ( V_440 - V_551 , 1 ) ;
}
V_442 = F_247 ( ( T_13 ) V_585 -> V_442 * V_542 , V_575 ) ;
V_442 = F_105 ( V_442 , 1 ) ;
V_441 = V_584 - ( V_550 + V_440 + V_551 + V_442 ) ;
if ( V_441 < 1 ) {
int V_27 ;
V_27 = 1 - V_441 ;
V_442 = F_105 ( V_442 - V_27 , 1 ) ;
V_441 = V_584 - ( V_550 + V_440 + V_551 + V_442 ) ;
if ( V_441 < 1 && V_440 > 0 ) {
V_27 = 1 - V_441 ;
V_440 = F_105 ( V_440 - V_27 , 1 ) ;
V_441 = V_584 - ( V_550 + V_440 + V_551 + V_442 ) ;
}
}
if ( V_441 < 1 )
return false ;
V_586 -> V_550 = V_550 ;
V_586 -> V_440 = V_440 ;
V_586 -> V_551 = V_551 ;
V_586 -> V_442 = V_442 ;
V_586 -> V_548 = V_579 ;
V_586 -> V_441 = V_441 ;
V_586 -> V_466 = V_585 -> V_566 ;
V_586 -> V_468 = V_585 -> V_468 ;
V_586 -> V_589 = V_585 -> V_473 ;
V_586 -> V_467 = V_585 -> V_467 ;
V_586 -> V_418 = V_572 -> V_418 ;
V_586 -> V_420 = 0 ;
V_586 -> V_423 = 1 ;
V_586 -> V_421 = 1 ;
V_586 -> V_422 = 1 ;
V_586 -> V_338 = V_572 -> V_338 ;
V_586 -> V_469 = 4 ;
V_564 = & V_563 -> V_564 ;
* V_564 = * V_585 ;
V_564 -> V_553 = V_578 / 1000 ;
if ( V_572 -> V_418 == V_419 ) {
V_440 = F_247 ( ( T_13 ) V_585 -> V_554 * V_578 ,
V_575 ) ;
V_440 = F_105 ( V_440 , 1 ) ;
} else {
V_440 = 1 ;
}
V_442 = F_247 ( ( T_13 ) V_585 -> V_442 * V_578 , V_575 ) ;
V_442 = F_105 ( V_442 , 1 ) ;
V_441 = V_583 - V_440 - V_442 ;
if ( V_441 < 1 ) {
int V_27 ;
V_27 = 1 - V_441 ;
V_442 = F_105 ( V_442 - V_27 , 1 ) ;
V_441 = V_583 - V_440 - V_442 ;
if ( V_441 < 1 ) {
V_27 = 1 - V_441 ;
V_440 = F_105 ( V_440 - V_27 , 1 ) ;
V_441 = V_583 - V_440 - V_442 ;
}
}
if ( V_441 < 1 )
return false ;
V_564 -> V_441 = V_441 ;
V_564 -> V_554 = V_440 ;
V_564 -> V_442 = V_442 ;
return true ;
}
static bool F_254 ( int V_559 , int V_560 , unsigned long V_561 ,
unsigned long V_552 , void * V_20 )
{
struct V_562 * V_563 = V_20 ;
V_563 -> V_513 . V_514 = V_559 ;
V_563 -> V_513 . V_516 = V_560 ;
V_563 -> V_513 . V_561 = V_561 ;
V_563 -> V_513 . V_552 = V_552 ;
if ( F_253 ( V_563 ) == false )
return false ;
#ifdef F_255
F_244 ( L_164 , & V_563 -> V_564 ) ;
F_242 ( L_165 , & V_563 -> V_586 ) ;
F_244 ( L_166 , V_563 -> V_565 -> V_414 ) ;
F_246 ( L_167 , & V_563 -> V_586 ) ;
#endif
return true ;
}
static bool F_256 ( int V_218 , unsigned long V_567 ,
void * V_20 )
{
struct V_562 * V_563 = V_20 ;
unsigned long V_590 ;
V_563 -> V_568 . V_218 = V_218 ;
V_563 -> V_568 . V_171 = V_567 ;
if ( V_563 -> V_565 -> V_418 == V_588 )
V_590 = V_563 -> V_570 + 10000000 ;
else
V_590 = V_563 -> V_570 ;
return F_250 ( V_567 , V_563 -> V_569 , V_590 ,
F_254 , V_563 ) ;
}
static bool F_257 ( int V_206 , int V_197 , unsigned long V_209 ,
unsigned long V_194 , void * V_20 )
{
struct V_562 * V_563 = V_20 ;
V_563 -> V_568 . V_206 = V_206 ;
V_563 -> V_568 . V_197 = V_197 ;
V_563 -> V_568 . V_209 = V_209 ;
V_563 -> V_568 . V_173 = V_194 ;
return F_103 ( V_563 -> V_3 , V_194 , V_563 -> V_569 ,
F_256 , V_563 ) ;
}
static bool F_258 ( struct V_1 * V_16 ,
const struct V_571 * V_572 ,
struct V_562 * V_563 )
{
const struct V_413 * V_27 = V_572 -> V_414 ;
unsigned long V_203 ;
unsigned long V_204 ;
unsigned long V_205 ;
int V_449 = V_16 -> V_299 - 1 ;
int V_549 = F_25 ( V_572 -> V_574 ) ;
unsigned long V_591 ;
V_203 = F_93 ( V_16 -> V_156 ) ;
memset ( V_563 , 0 , sizeof( * V_563 ) ) ;
V_563 -> V_3 = V_16 -> V_150 ;
V_563 -> V_565 = V_572 ;
V_563 -> V_568 . V_203 = V_203 ;
V_563 -> V_569 = V_27 -> V_553 * 1000 - 1000 ;
V_563 -> V_575 = V_27 -> V_553 * 1000 ;
V_563 -> V_570 = V_27 -> V_553 * 1000 + 1000 ;
V_591 = F_247 ( ( T_13 ) V_563 -> V_569 * V_549 , V_449 * 8 ) ;
V_204 = F_105 ( V_572 -> V_576 * 4 , V_591 * 4 * 4 ) ;
if ( V_572 -> V_418 == V_588 ) {
V_205 = V_572 -> V_577 * 4 ;
} else {
unsigned long V_592 ;
V_592 = F_247 ( ( T_13 ) V_563 -> V_570 * V_549 ,
V_449 * 8 ) ;
V_205 = V_592 * 4 * 4 ;
}
return F_107 ( V_16 -> V_150 , V_203 ,
V_204 , V_205 ,
F_257 , V_563 ) ;
}
static int F_259 ( struct V_5 * V_6 ,
const struct V_571 * V_565 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_562 V_563 ;
bool V_328 ;
int V_148 ;
F_238 ( & V_16 -> V_537 ) ;
V_16 -> V_412 = V_565 -> V_574 ;
V_16 -> V_335 = V_565 -> V_335 ;
if ( V_565 -> V_335 == V_336 )
V_328 = F_258 ( V_16 , V_565 , & V_563 ) ;
else
V_328 = F_252 ( V_16 , V_565 , & V_563 ) ;
if ( ! V_328 ) {
F_44 ( L_168 ) ;
V_148 = - V_146 ;
goto V_243;
}
F_110 ( & V_563 . V_568 ) ;
V_148 = F_94 ( & V_563 . V_568 , V_565 -> V_179 ,
V_565 -> V_180 ) ;
if ( V_148 ) {
F_44 ( L_169 ) ;
goto V_243;
}
V_16 -> V_184 = V_563 . V_568 ;
V_16 -> V_515 = V_563 . V_513 ;
V_16 -> V_414 = V_563 . V_564 ;
V_16 -> V_337 = V_563 . V_586 ;
F_239 ( & V_16 -> V_537 ) ;
return 0 ;
V_243:
F_239 ( & V_16 -> V_537 ) ;
return V_148 ;
}
static enum V_593 F_260 ( int V_174 )
{
switch ( F_261 () ) {
case V_594 :
F_262 ( L_170 ) ;
return V_595 ;
case V_596 :
case V_597 :
case V_598 :
case V_599 :
return V_595 ;
case V_600 :
case V_601 :
case V_602 :
switch ( V_174 ) {
case 0 :
return V_595 ;
case 1 :
return V_603 ;
default:
F_262 ( L_171 ) ;
return V_595 ;
}
case V_604 :
switch ( V_174 ) {
case 0 :
return V_595 ;
case 1 :
return V_605 ;
default:
F_262 ( L_171 ) ;
return V_595 ;
}
default:
F_262 ( L_172 ) ;
return V_595 ;
}
}
static int F_263 ( struct V_5 * V_6 , int * V_69 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_103 ;
for ( V_103 = 0 ; V_103 < F_47 ( V_16 -> V_142 ) ; V_103 ++ ) {
if ( ! V_16 -> V_142 [ V_103 ] . V_6 ) {
V_16 -> V_142 [ V_103 ] . V_6 = V_6 ;
* V_69 = V_103 ;
return 0 ;
}
}
F_44 ( L_173 , V_6 -> V_39 ) ;
return - V_606 ;
}
static int F_264 ( struct V_5 * V_6 , int V_69 , int V_373 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_373 < 0 || V_373 > 3 ) {
F_44 ( L_174 ) ;
return - V_146 ;
}
if ( V_69 < 0 || V_69 > 3 ) {
F_44 ( L_175 ) ;
return - V_146 ;
}
if ( V_16 -> V_142 [ V_69 ] . V_6 != V_6 ) {
F_44 ( L_176 ,
V_6 -> V_39 ) ;
return - V_146 ;
}
V_16 -> V_142 [ V_69 ] . V_373 = V_373 ;
return 0 ;
}
static void F_265 ( struct V_5 * V_6 , int V_69 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( ( V_69 >= 0 && V_69 <= 3 ) &&
V_16 -> V_142 [ V_69 ] . V_6 == V_6 ) {
V_16 -> V_142 [ V_69 ] . V_6 = NULL ;
V_16 -> V_142 [ V_69 ] . V_373 = 0 ;
}
}
void F_266 ( struct V_2 * V_3 )
{
if ( F_18 ( V_3 , V_158 , 7 , 1 ) != 1 )
F_44 ( L_177 ,
F_112 ( V_230 ) ,
F_113 ( V_230 ) ) ;
}
void F_267 ( struct V_2 * V_3 )
{
if ( F_18 ( V_3 , V_158 , 8 , 1 ) != 1 )
F_44 ( L_177 ,
F_112 ( V_231 ) ,
F_113 ( V_231 ) ) ;
}
static void F_268 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_16 -> V_215 = F_104 ( V_607 ) ;
V_16 -> V_217 = F_104 ( V_608 ) ;
V_16 -> V_202 =
F_104 ( V_609 ) ;
V_16 -> V_220 = F_104 ( V_610 ) ;
V_16 -> V_213 = F_269 ( V_611 ) ;
V_16 -> V_214 = F_104 ( V_611 ) ;
V_16 -> V_185 = F_104 ( V_612 ) ;
}
static int F_270 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_613 * V_613 ;
V_613 = F_271 ( & V_3 -> V_4 , L_178 ) ;
if ( F_78 ( V_613 ) ) {
F_44 ( L_179 ) ;
return F_79 ( V_613 ) ;
}
V_16 -> V_176 = V_613 ;
V_613 = F_271 ( & V_3 -> V_4 , L_180 ) ;
if ( F_78 ( V_613 ) ) {
F_44 ( L_181 ) ;
return F_79 ( V_613 ) ;
}
V_16 -> V_156 = V_613 ;
return 0 ;
}
static int F_272 ( struct V_5 * V_6 ,
struct V_5 * V_614 )
{
struct V_2 * V_3 = F_3 ( V_6 ) ;
struct V_484 * V_485 ;
int V_148 ;
V_148 = F_76 ( V_3 ) ;
if ( V_148 )
return V_148 ;
V_485 = F_273 ( V_6 -> V_615 ) ;
if ( ! V_485 )
return - V_193 ;
V_148 = F_274 ( V_485 , V_6 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_275 ( V_6 , V_614 ) ;
if ( V_148 ) {
F_44 ( L_182 ,
V_6 -> V_39 ) ;
F_276 ( V_485 , V_6 ) ;
return V_148 ;
}
return 0 ;
}
static void F_277 ( struct V_5 * V_6 ,
struct V_5 * V_614 )
{
F_73 ( V_614 != V_6 -> V_614 ) ;
if ( V_614 != V_6 -> V_614 )
return;
F_278 ( V_6 ) ;
if ( V_6 -> V_487 )
F_276 ( V_6 -> V_487 , V_6 ) ;
}
static void F_279 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_486 ;
V_8 -> V_4 = & V_3 -> V_4 ;
V_8 -> V_10 = V_16 -> V_174 == 0 ?
V_11 : V_12 ;
V_8 -> V_616 = V_617 ;
V_8 -> V_39 = V_16 -> V_174 == 0 ? L_183 : L_184 ;
V_8 -> V_615 = F_260 ( V_16 -> V_174 ) ;
V_8 -> V_618 . V_16 = & V_619 ;
V_8 -> V_620 = V_621 ;
F_280 ( V_8 ) ;
}
static void F_281 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_5 * V_8 = & V_16 -> V_486 ;
F_282 ( V_8 ) ;
}
static int F_283 ( struct V_2 * V_3 )
{
T_1 V_622 ;
int V_148 , V_103 ;
struct V_623 * V_624 ;
struct V_1 * V_16 ;
V_16 = F_284 ( & V_3 -> V_4 , sizeof( * V_16 ) , V_625 ) ;
if ( ! V_16 )
return - V_626 ;
V_16 -> V_174 = V_3 -> V_10 ;
V_16 -> V_150 = V_3 ;
F_285 ( & V_3 -> V_4 , V_16 ) ;
F_286 ( & V_16 -> V_128 ) ;
F_286 ( & V_16 -> V_111 ) ;
V_16 -> V_112 = 0 ;
#ifdef F_287
F_286 ( & V_16 -> V_104 ) ;
V_16 -> V_105 . V_264 = V_28 ;
#endif
F_288 ( & V_16 -> V_537 ) ;
F_289 ( & V_16 -> V_18 , 1 ) ;
F_290 ( & V_16 -> V_504 ,
F_220 ) ;
#ifdef F_50
F_291 ( & V_16 -> V_134 ) ;
V_16 -> V_134 . V_305 = F_217 ;
V_16 -> V_134 . V_20 = 0 ;
#endif
V_624 = F_292 ( V_16 -> V_150 , V_627 , 0 ) ;
if ( ! V_624 ) {
F_44 ( L_185 ) ;
return - V_146 ;
}
V_16 -> V_17 = F_293 ( & V_3 -> V_4 , V_624 -> T_8 ,
F_294 ( V_624 ) ) ;
if ( ! V_16 -> V_17 ) {
F_44 ( L_186 ) ;
return - V_626 ;
}
V_16 -> V_127 = F_295 ( V_16 -> V_150 , 0 ) ;
if ( V_16 -> V_127 < 0 ) {
F_44 ( L_187 ) ;
return - V_193 ;
}
V_148 = F_296 ( & V_3 -> V_4 , V_16 -> V_127 , F_48 ,
V_628 , F_297 ( & V_3 -> V_4 ) , V_16 -> V_150 ) ;
if ( V_148 < 0 ) {
F_44 ( L_188 ) ;
return V_148 ;
}
for ( V_103 = 0 ; V_103 < F_47 ( V_16 -> V_142 ) ; V_103 ++ ) {
V_16 -> V_142 [ V_103 ] . V_354 = V_356 ;
V_16 -> V_142 [ V_103 ] . V_6 = NULL ;
V_16 -> V_142 [ V_103 ] . V_373 = 0 ;
}
F_268 ( V_3 ) ;
V_148 = F_270 ( V_3 ) ;
if ( V_148 )
return V_148 ;
F_298 ( & V_3 -> V_4 ) ;
V_148 = F_70 ( V_3 ) ;
if ( V_148 )
goto V_629;
V_622 = F_9 ( V_3 , V_265 ) ;
F_299 ( & V_3 -> V_4 , L_189 ,
F_100 ( V_622 , 7 , 4 ) , F_100 ( V_622 , 3 , 0 ) ) ;
if ( F_84 ( V_289 ) )
V_16 -> V_303 = 1 + F_19 ( V_3 , V_290 , 11 , 9 ) ;
else
V_16 -> V_303 = 3 ;
V_16 -> V_415 = F_139 ( V_3 ) ;
F_279 ( V_3 ) ;
F_74 ( V_3 ) ;
if ( V_16 -> V_174 == 0 )
F_300 ( L_190 , F_136 ) ;
else if ( V_16 -> V_174 == 1 )
F_300 ( L_191 , F_137 ) ;
#ifdef F_287
if ( V_16 -> V_174 == 0 )
F_300 ( L_192 , F_127 ) ;
else if ( V_16 -> V_174 == 1 )
F_300 ( L_193 , F_128 ) ;
#endif
return 0 ;
V_629:
F_301 ( & V_3 -> V_4 ) ;
return V_148 ;
}
static int T_14 F_302 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_73 ( V_16 -> V_187 > 0 ) ;
F_281 ( V_3 ) ;
F_301 ( & V_3 -> V_4 ) ;
if ( V_16 -> V_154 != NULL && V_16 -> V_247 ) {
F_119 ( V_16 -> V_154 ) ;
V_16 -> V_247 = false ;
}
return 0 ;
}
static int F_303 ( struct V_630 * V_4 )
{
F_304 () ;
return 0 ;
}
static int F_305 ( struct V_630 * V_4 )
{
int V_148 ;
V_148 = F_306 () ;
if ( V_148 )
return V_148 ;
return 0 ;
}
int T_15 F_307 ( void )
{
return F_308 ( & V_631 ) ;
}
void T_14 F_309 ( void )
{
F_310 ( & V_631 ) ;
}
