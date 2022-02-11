static unsigned int F_1 ( unsigned int line )
{
if ( line < 64 )
return 0x100 + line * 4 ;
return 0x1000 + line * 4 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
T_1 V_8 ;
F_3 ( V_2 , L_1 , V_5 -> V_9 ) ;
for ( V_7 = 0 ; V_7 < 70 ; V_7 ++ ) {
V_8 = F_4 ( V_5 -> V_10 + F_1 ( V_7 ) ) ;
if ( ( V_8 & V_11 ) == V_5 -> V_9 )
F_3 ( V_2 , L_2 , V_7 ,
! ! ( V_8 & V_12 ) ) ;
}
return 0 ;
}
static inline int F_5 ( T_1 V_13 )
{
int V_14 = ( V_13 >> 16 ) & 0x3 ;
return V_14 ? 4 << V_14 : 0 ;
}
static int F_6 ( unsigned long V_15 )
{
return F_7 ( F_8 ( V_15 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 , V_16 = 20 , V_14 , V_17 ;
T_1 V_13 ;
unsigned long V_18 , V_19 ;
struct V_20 * V_21 ;
V_18 = V_19 = F_10 ( V_5 , V_22 ) ;
F_3 ( V_2 , L_3 , V_5 -> V_9 ) ;
F_3 ( V_2 , L_4 , 0 ) ;
for ( V_7 = 1 ; V_7 < V_16 && F_6 ( V_18 ) ; V_7 ++ ) {
V_21 = F_11 ( V_18 ) ;
V_13 = V_21 -> V_13 ;
V_14 = F_5 ( V_13 ) ;
V_17 = ( 1 << ( ( V_13 >> 14 ) & 0x3 ) ) >> 1 ;
F_3 ( V_2 , L_5 ,
V_7 , V_18 , V_21 ) ;
F_3 ( V_2 , L_6 , V_21 -> V_19 ) ;
F_3 ( V_2 , L_7 , V_21 -> V_23 ) ;
F_3 ( V_2 , L_8 , V_21 -> V_24 ) ;
F_3 ( V_2 , L_9 ,
V_13 ,
F_12 ( V_25 ) , F_12 ( V_26 ) ,
F_12 ( V_27 ) , F_12 ( V_28 ) ,
F_12 ( V_29 ) , F_12 ( V_30 ) ,
F_12 ( V_31 ) , V_14 , V_17 ,
V_13 & V_32 ) ;
V_18 = V_21 -> V_19 ;
}
if ( V_7 == V_16 )
F_3 ( V_2 , L_10 ,
V_7 , V_18 ) ;
else
F_3 ( V_2 , L_11 ,
V_7 , V_18 , V_18 == V_33 ?
L_12 : L_13 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_34 , V_13 ;
int V_14 , V_17 ;
static const char * const V_35 [] = {
L_14 , L_15 , L_16 , L_13
} ;
V_34 = F_10 ( V_5 , V_36 ) ;
V_13 = F_10 ( V_5 , V_37 ) ;
V_14 = F_5 ( V_13 ) ;
V_17 = ( 1 << ( ( V_13 >> 14 ) & 0x3 ) ) >> 1 ;
F_3 ( V_2 , L_17 , V_5 -> V_9 ) ;
F_3 ( V_2 , L_18 ,
V_35 [ ( V_5 -> V_9 & 0xf ) / 4 ] ) ;
F_3 ( V_2 , L_19 ,
F_10 ( V_5 , V_38 ) & F_14 ( V_5 -> V_9 ) ?
L_20 : L_21 ) ;
F_3 ( V_2 , L_22 ,
V_34 , F_15 ( V_39 ) , F_15 ( V_40 ) ,
F_15 ( V_41 ) , F_15 ( V_42 ) ,
F_15 ( V_43 ) , F_15 ( V_44 ) ,
F_15 ( V_45 ) , F_15 ( V_46 ) ,
F_15 ( V_47 ) , F_15 ( V_48 ) ,
F_15 ( V_49 ) , F_15 ( V_50 ) ,
F_15 ( V_51 ) , F_15 ( V_52 ) ,
F_15 ( V_53 ) ) ;
F_3 ( V_2 , L_9 ,
V_13 ,
F_12 ( V_25 ) , F_12 ( V_26 ) ,
F_12 ( V_27 ) , F_12 ( V_28 ) ,
F_12 ( V_29 ) , F_12 ( V_30 ) ,
F_12 ( V_31 ) , V_14 , V_17 , V_13 & V_32 ) ;
F_3 ( V_2 , L_7 , F_10 ( V_5 , V_54 ) ) ;
F_3 ( V_2 , L_8 , F_10 ( V_5 , V_55 ) ) ;
F_3 ( V_2 , L_6 , F_10 ( V_5 , V_22 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_3 )
{
struct V_56 * V_57 = V_2 -> V_6 ;
F_17 ( V_2 , L_23 ) ;
F_3 ( V_2 , L_24 , V_57 -> V_58 ) ;
return 0 ;
}
static struct V_59 * F_18 ( struct V_56 * V_57 ,
int V_60 , struct V_59 * V_61 )
{
char V_62 [ 11 ] ;
struct V_59 * V_63 , * V_64 = NULL , * V_65 = NULL ;
struct V_59 * V_66 = NULL ;
void * V_67 ;
F_19 ( V_62 , sizeof( V_62 ) , L_25 , V_60 ) ;
V_63 = F_20 ( V_62 , V_61 ) ;
V_67 = ( void * ) & V_57 -> V_68 [ V_60 ] ;
if ( V_63 )
V_64 = F_21 ( L_26 , 0400 , V_63 , V_67 ,
& V_69 ) ;
if ( V_64 )
V_65 = F_21 ( L_27 , 0400 , V_63 , V_67 ,
& V_70 ) ;
if ( V_65 )
V_66 = F_21 ( L_28 , 0400 , V_63 , V_67 ,
& V_71 ) ;
if ( ! V_66 )
goto V_72;
return V_63 ;
V_72:
F_22 ( V_63 ) ;
return NULL ;
}
static void F_23 ( struct V_56 * V_57 )
{
int V_7 ;
struct V_59 * V_61 ;
V_57 -> V_73 = F_20 ( F_24 ( V_57 -> V_74 . V_75 ) , NULL ) ;
if ( F_25 ( V_57 -> V_73 ) || ! V_57 -> V_73 )
goto V_76;
V_57 -> V_77 = F_21 ( L_26 , 0400 , V_57 -> V_73 ,
V_57 , & V_78 ) ;
if ( ! V_57 -> V_77 )
goto V_72;
V_57 -> V_79 =
F_26 ( V_57 -> V_58 , sizeof( * V_57 -> V_77 ) ,
V_80 ) ;
if ( ! V_57 -> V_79 )
goto V_81;
V_61 = F_20 ( L_29 , V_57 -> V_73 ) ;
if ( ! V_61 )
goto V_82;
for ( V_7 = 0 ; V_7 < V_57 -> V_58 ; V_7 ++ ) {
V_57 -> V_79 [ V_7 ] = F_18 ( V_57 , V_7 , V_61 ) ;
if ( ! V_57 -> V_79 [ V_7 ] )
goto V_83;
}
return;
V_83:
V_82:
F_27 ( V_57 -> V_79 ) ;
V_81:
V_72:
F_22 ( V_57 -> V_73 ) ;
V_76:
F_28 ( L_30 ) ;
}
static void F_29 ( struct V_56 * V_57 )
{
F_22 ( V_57 -> V_73 ) ;
}
static inline void F_23 ( struct V_56 * V_57 ) {}
static inline void F_29 ( struct V_56 * V_57 ) {}
static struct V_4 * F_30 ( struct V_84 * V_85 )
{
int V_86 , V_7 ;
struct V_56 * V_57 = F_31 ( V_85 -> V_87 . V_63 . V_88 ) ;
struct V_4 * V_5 , * V_89 = NULL ;
unsigned long V_90 ;
F_32 ( & V_57 -> V_91 , V_90 ) ;
for ( V_86 = V_85 -> V_86 ; V_86 >= V_92 ; V_86 -- ) {
for ( V_7 = 0 ; V_7 < V_57 -> V_58 ; V_7 ++ ) {
if ( V_86 != ( V_7 & 0xf ) >> 2 )
continue;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ! V_5 -> V_93 ) {
V_5 -> V_93 = V_85 ;
V_89 = V_5 ;
goto V_94;
}
}
}
V_94:
F_33 ( & V_57 -> V_91 , V_90 ) ;
F_34 ( & V_85 -> V_87 . V_63 . V_75 -> V_88 ,
L_31 , V_95 , V_89 ,
V_89 ? V_89 -> V_9 : - 1 ) ;
return V_89 ;
}
static void F_35 ( struct V_84 * V_63 )
{
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
unsigned long V_90 ;
T_1 V_96 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_32 , V_95 ) ;
if ( ! V_63 -> V_5 )
return;
if ( V_63 -> V_8 <= V_57 -> V_97 ) {
V_96 = F_1 ( V_63 -> V_8 ) ;
F_36 ( 0 , V_63 -> V_5 -> V_10 + V_96 ) ;
}
F_32 ( & V_57 -> V_91 , V_90 ) ;
V_63 -> V_5 -> V_93 = NULL ;
V_63 -> V_5 = NULL ;
F_33 ( & V_57 -> V_91 , V_90 ) ;
}
static bool F_37 ( struct V_84 * V_63 )
{
T_1 V_34 ;
struct V_4 * V_5 = V_63 -> V_5 ;
if ( ! V_5 )
return false ;
V_34 = F_38 ( V_5 , V_36 ) ;
return V_34 & V_98 ;
}
static bool F_39 ( struct V_84 * V_63 )
{
T_1 V_99 ;
F_40 ( ! V_63 -> V_5 ) ;
V_99 = F_38 ( V_63 -> V_5 , V_38 ) ;
return V_99 & ( F_14 ( V_63 -> V_5 -> V_9 ) ) ;
}
static void F_41 ( struct V_4 * V_5 , bool V_100 )
{
struct V_56 * V_57 ;
T_1 V_96 , V_99 ;
if ( ! V_5 -> V_93 )
return;
F_34 ( & V_5 -> V_93 -> V_87 . V_63 . V_75 -> V_88 ,
L_33 , V_95 ,
V_5 , V_5 -> V_9 , V_100 ) ;
V_57 = F_31 ( V_5 -> V_93 -> V_87 . V_63 . V_88 ) ;
if ( V_5 -> V_93 -> V_8 <= V_57 -> V_97 ) {
V_96 = F_1 ( V_5 -> V_93 -> V_8 ) ;
F_36 ( V_12 | V_5 -> V_9 , V_5 -> V_10 + V_96 ) ;
}
V_99 = F_38 ( V_5 , V_38 ) ;
if ( V_100 )
V_99 |= F_14 ( V_5 -> V_9 ) ;
else
V_99 &= ~ F_14 ( V_5 -> V_9 ) ;
F_42 ( V_5 , V_99 , V_38 ) ;
F_43 ( V_5 , V_101 | V_102 |
V_103 | V_98 , V_36 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
T_1 V_34 ;
if ( ! V_5 )
return;
V_34 = F_38 ( V_5 , V_36 ) ;
F_34 ( & V_5 -> V_93 -> V_87 . V_63 . V_75 -> V_88 ,
L_31 , V_95 , V_5 , V_5 -> V_9 ) ;
F_43 ( V_5 , V_34 & ~ V_98 & ~ V_101 , V_36 ) ;
}
static void F_45 ( struct V_84 * V_63 ,
struct V_104 * V_21 )
{
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_34 , V_95 , V_21 ) ;
if ( ! V_63 -> V_5 ) {
V_63 -> V_5 = F_30 ( V_63 ) ;
if ( ! V_63 -> V_5 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_35 , V_95 ) ;
return;
}
}
V_63 -> V_105 = 0 ;
F_43 ( V_63 -> V_5 , V_21 -> V_106 , V_22 ) ;
F_41 ( V_63 -> V_5 , V_63 -> V_100 ) ;
F_46 ( & V_63 -> V_107 ) ;
}
static void F_47 ( struct V_104 * V_108 ,
unsigned long V_90 )
{
struct V_20 * V_109 =
V_108 -> V_110 [ V_108 -> V_111 - 1 ] ;
T_2 V_112 = V_108 -> V_110 [ V_108 -> V_111 - 2 ] -> V_19 ;
V_109 -> V_19 = V_33 ;
V_109 -> V_23 = V_112 ;
V_109 -> V_24 = V_112 + 8 ;
V_109 -> V_13 = V_113 | V_114 |
( V_32 & sizeof( T_1 ) ) ;
if ( V_90 & V_115 )
V_109 -> V_13 |= V_116 ;
if ( V_108 -> V_117 )
V_108 -> V_110 [ V_108 -> V_111 - 2 ] -> V_19 = V_108 -> V_106 ;
}
static bool F_48 ( struct V_118 * V_119 )
{
struct V_104 * V_108 = F_49 ( V_119 ) ;
struct V_20 * V_109 =
V_108 -> V_110 [ V_108 -> V_111 - 1 ] ;
return V_109 -> V_24 != ( V_109 -> V_23 + 8 ) ;
}
static void F_50 ( struct V_118 * V_120 ,
struct V_118 * V_121 )
{
struct V_104 * V_122 = F_49 ( V_120 ) ;
struct V_104 * V_123 = F_49 ( V_121 ) ;
T_2 V_124 ;
V_124 = V_123 -> V_106 ;
V_122 -> V_110 [ V_122 -> V_111 - 1 ] -> V_19 = V_124 ;
}
static bool F_51 ( struct V_125 * V_87 ,
struct V_118 * V_119 )
{
struct V_118 * V_126 = NULL ;
struct V_84 * V_63 = F_52 ( & V_87 -> V_63 ) ;
if ( F_37 ( V_63 ) ) {
F_40 ( F_53 ( & V_87 -> V_127 ) ) ;
if ( ! F_39 ( V_63 ) &&
F_49 ( V_119 ) -> V_100 )
return false ;
V_126 = F_54 ( V_87 -> V_127 . V_128 ,
struct V_118 , V_129 ) ;
F_50 ( V_126 , V_119 ) ;
if ( F_37 ( V_63 ) || F_48 ( V_119 ) )
return true ;
}
return false ;
}
static unsigned int F_55 ( struct V_4 * V_5 )
{
T_1 V_34 ;
T_1 V_130 = F_56 ( V_5 -> V_10 + V_131 ) ;
if ( ! ( V_130 & F_14 ( V_5 -> V_9 ) ) )
return V_98 ;
V_34 = F_38 ( V_5 , V_36 ) ;
F_43 ( V_5 , V_34 , V_36 ) ;
if ( ( V_34 & V_103 ) && ( V_5 -> V_93 ) )
F_57 ( & V_5 -> V_93 -> V_87 . V_63 . V_75 -> V_88 ,
L_36 ,
V_95 , & V_5 -> V_93 ) ;
return V_34 & ~ V_98 ;
}
static T_3 F_58 ( int V_132 , void * V_133 )
{
struct V_4 * V_5 = V_133 ;
struct V_84 * V_63 = V_5 -> V_93 ;
struct V_118 * V_119 , * V_134 ;
unsigned int V_34 ;
unsigned long V_90 ;
bool V_135 ;
T_4 V_136 = 0 ;
F_40 ( ! V_63 ) ;
V_34 = F_55 ( V_5 ) ;
if ( V_34 & V_98 )
return V_137 ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_59 (vd, tmp, &chan->vc.desc_issued, node) {
V_135 = F_48 ( V_119 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_37 ,
V_95 , V_119 , V_119 -> V_139 . V_140 , V_135 ,
V_34 ) ;
V_136 = V_119 -> V_139 . V_140 ;
if ( F_49 ( V_119 ) -> V_117 ) {
F_60 ( V_119 ) ;
break;
}
if ( V_135 ) {
F_61 ( & V_119 -> V_129 ) ;
F_62 ( V_119 ) ;
} else {
break;
}
}
if ( V_34 & V_103 ) {
V_63 -> V_105 = V_136 ;
F_44 ( V_5 ) ;
}
if ( ! V_63 -> V_105 && V_34 & V_141 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_38 ,
V_95 ,
F_53 ( & V_63 -> V_87 . V_142 ) ,
F_53 ( & V_63 -> V_87 . V_127 ) ) ;
F_42 ( V_5 , V_34 & ~ V_101 , V_36 ) ;
if ( F_53 ( & V_63 -> V_87 . V_127 ) ) {
V_63 -> V_100 =
! F_53 ( & V_63 -> V_87 . V_142 ) ;
} else {
V_119 = F_63 ( & V_63 -> V_87 . V_127 ,
struct V_118 , V_129 ) ;
F_45 ( V_63 , F_49 ( V_119 ) ) ;
}
}
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_46 ( & V_63 -> V_107 ) ;
return V_143 ;
}
static T_3 F_64 ( int V_132 , void * V_133 )
{
struct V_56 * V_57 = V_133 ;
struct V_4 * V_5 ;
T_1 V_130 = F_56 ( V_57 -> V_10 + V_131 ) ;
int V_7 , V_144 = V_137 ;
while ( V_130 ) {
V_7 = F_65 ( V_130 ) ;
V_130 &= ( V_130 - 1 ) ;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( F_58 ( V_132 , V_5 ) == V_143 )
V_144 = V_143 ;
}
return V_144 ;
}
static int F_66 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
if ( V_63 -> V_147 )
return 1 ;
V_63 -> V_147 = F_67 ( F_68 ( V_146 ) ,
V_57 -> V_74 . V_75 ,
sizeof( struct V_20 ) ,
F_69 ( struct V_20 ) ,
0 ) ;
if ( ! V_63 -> V_147 ) {
F_70 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_39 ,
V_95 ) ;
return - V_148 ;
}
return 1 ;
}
static void F_71 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
F_72 ( & V_63 -> V_87 ) ;
F_73 ( V_63 -> V_147 ) ;
V_63 -> V_147 = NULL ;
}
static void F_74 ( struct V_118 * V_119 )
{
int V_7 ;
T_2 V_112 ;
struct V_104 * V_108 = F_49 ( V_119 ) ;
F_40 ( V_108 -> V_111 == 0 ) ;
for ( V_7 = V_108 -> V_111 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 )
V_112 = V_108 -> V_110 [ V_7 - 1 ] -> V_19 ;
else
V_112 = V_108 -> V_106 ;
F_75 ( V_108 -> V_147 ,
V_108 -> V_110 [ V_7 ] , V_112 ) ;
}
V_108 -> V_111 = 0 ;
F_27 ( V_108 ) ;
}
static struct V_104 *
F_76 ( struct V_84 * V_63 , unsigned int V_149 )
{
struct V_104 * V_108 ;
T_2 V_112 ;
int V_7 ;
V_108 = F_77 ( sizeof( * V_108 ) +
V_149 * sizeof( struct V_20 * ) ,
V_150 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_147 = V_63 -> V_147 ;
for ( V_7 = 0 ; V_7 < V_149 ; V_7 ++ ) {
V_108 -> V_110 [ V_7 ] = F_78 ( V_108 -> V_147 ,
V_150 , & V_112 ) ;
if ( ! V_108 -> V_110 [ V_7 ] ) {
F_70 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_40 ,
V_95 , V_7 , V_108 -> V_147 ) ;
goto V_151;
}
if ( V_7 == 0 )
V_108 -> V_106 = V_112 ;
else
V_108 -> V_110 [ V_7 - 1 ] -> V_19 = V_112 ;
V_108 -> V_111 ++ ;
}
return V_108 ;
V_151:
F_74 ( & V_108 -> V_119 ) ;
return NULL ;
}
static T_4 F_79 ( struct V_152 * V_139 )
{
struct V_125 * V_87 = F_80 ( V_139 -> V_63 ) ;
struct V_84 * V_63 = F_52 ( & V_87 -> V_63 ) ;
struct V_118 * V_153 = NULL ,
* V_119 = F_81 ( V_139 , struct V_118 , V_139 ) ;
T_4 V_140 ;
unsigned long V_90 ;
F_47 ( F_49 ( V_119 ) , V_139 -> V_90 ) ;
F_32 ( & V_87 -> V_138 , V_90 ) ;
V_140 = F_82 ( V_139 ) ;
if ( F_53 ( & V_87 -> V_142 ) && F_51 ( V_87 , V_119 ) ) {
F_83 ( & V_119 -> V_129 , & V_87 -> V_127 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_41 ,
V_95 , V_119 , V_140 ) ;
goto V_154;
}
if ( ! F_53 ( & V_87 -> V_142 ) ) {
V_153 = F_54 ( V_87 -> V_142 . V_128 ,
struct V_118 , V_129 ) ;
if ( V_63 -> V_100 || ! F_49 ( V_119 ) -> V_100 )
F_50 ( V_153 , V_119 ) ;
else
V_153 = NULL ;
}
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_42 ,
V_95 , V_119 , V_140 , V_153 ? L_43 : L_44 ) ;
F_83 ( & V_119 -> V_129 , & V_87 -> V_142 ) ;
V_63 -> V_100 |= F_49 ( V_119 ) -> V_100 ;
V_154:
F_33 ( & V_87 -> V_138 , V_90 ) ;
return V_140 ;
}
static void F_84 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
struct V_118 * V_155 ;
unsigned long V_90 ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
if ( F_53 ( & V_63 -> V_87 . V_142 ) )
goto V_154;
V_155 = F_63 ( & V_63 -> V_87 . V_142 ,
struct V_118 , V_129 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_45 , V_95 , V_155 , V_155 -> V_139 . V_140 ) ;
F_85 ( & V_63 -> V_87 ) ;
if ( ! F_51 ( & V_63 -> V_87 , V_155 ) )
F_45 ( V_63 , F_49 ( V_155 ) ) ;
V_154:
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
}
static inline struct V_152 *
F_86 ( struct V_125 * V_87 , struct V_118 * V_119 ,
unsigned long V_156 )
{
struct V_152 * V_139 ;
struct V_84 * V_63 = F_81 ( V_87 , struct V_84 , V_87 ) ;
F_87 ( & V_119 -> V_129 ) ;
V_139 = F_88 ( V_87 , V_119 , V_156 ) ;
V_139 -> V_157 = F_79 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_46 , V_95 ,
V_87 , V_119 , V_119 -> V_139 . V_140 ,
V_156 ) ;
return V_139 ;
}
static void F_89 ( struct V_84 * V_63 ,
enum V_158 V_159 ,
T_1 * V_13 , T_1 * V_160 , T_1 * V_161 )
{
T_1 V_162 = 0 , V_163 = 0 ;
enum V_164 V_17 = V_165 ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
* V_13 = 0 ;
if ( V_159 == V_166 ) {
V_162 = V_63 -> V_167 . V_168 ;
V_17 = V_63 -> V_167 . V_169 ;
V_163 = V_63 -> V_167 . V_170 ;
* V_160 = V_163 ;
* V_13 |= V_171 ;
if ( V_63 -> V_8 <= V_57 -> V_97 )
* V_13 |= V_172 ;
}
if ( V_159 == V_173 ) {
V_162 = V_63 -> V_167 . V_174 ;
V_17 = V_63 -> V_167 . V_175 ;
V_163 = V_63 -> V_167 . V_176 ;
* V_161 = V_163 ;
* V_13 |= V_177 ;
if ( V_63 -> V_8 <= V_57 -> V_97 )
* V_13 |= V_178 ;
}
if ( V_159 == V_179 )
* V_13 |= V_114 | V_171 |
V_177 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_47 ,
V_95 , V_163 , V_162 , V_17 , V_159 ) ;
if ( V_17 == V_180 )
* V_13 |= V_181 ;
else if ( V_17 == V_182 )
* V_13 |= V_183 ;
else if ( V_17 == V_184 )
* V_13 |= V_113 ;
if ( V_162 == 8 )
* V_13 |= V_185 ;
else if ( V_162 == 16 )
* V_13 |= V_186 ;
else if ( V_162 == 32 )
* V_13 |= V_114 ;
if ( V_63 -> V_167 . V_187 )
V_63 -> V_8 = V_63 -> V_167 . V_187 ;
}
static struct V_152 *
F_90 ( struct V_145 * V_146 ,
T_2 V_188 , T_2 V_189 ,
T_5 V_190 , unsigned long V_90 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
struct V_104 * V_108 ;
struct V_20 * V_110 ;
T_1 V_13 ;
unsigned int V_7 , V_111 = 0 ;
T_5 V_191 ;
if ( ! V_146 || ! V_190 )
return NULL ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_48 ,
V_95 , ( unsigned long ) V_188 , ( unsigned long ) V_189 ,
V_190 , V_90 ) ;
F_89 ( V_63 , V_179 , & V_13 , NULL , NULL ) ;
V_111 = F_91 ( V_190 , V_192 ) ;
V_108 = F_76 ( V_63 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_190 = V_190 ;
if ( ! F_92 ( V_189 , 1 << V_193 ) ||
! F_92 ( V_188 , 1 << V_193 ) )
V_108 -> V_100 = true ;
V_7 = 0 ;
do {
V_110 = V_108 -> V_110 [ V_7 ++ ] ;
V_191 = F_93 ( T_5 , V_190 , V_192 ) ;
V_110 -> V_13 = V_13 | ( V_32 & V_191 ) ;
V_110 -> V_23 = V_189 ;
V_110 -> V_24 = V_188 ;
V_190 -= V_191 ;
V_189 += V_191 ;
V_188 += V_191 ;
} while ( V_190 );
F_47 ( V_108 , V_90 ) ;
return F_86 ( & V_63 -> V_87 , & V_108 -> V_119 , V_90 ) ;
}
static struct V_152 *
F_94 ( struct V_145 * V_146 , struct V_194 * V_195 ,
unsigned int V_196 , enum V_158 V_159 ,
unsigned long V_90 , void * V_197 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
struct V_104 * V_108 ;
T_5 V_190 , V_198 ;
struct V_194 * V_199 ;
T_2 V_112 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_111 = 0 , V_7 , V_200 = 0 ;
if ( ( V_195 == NULL ) || ( V_196 == 0 ) )
return NULL ;
F_89 ( V_63 , V_159 , & V_13 , & V_23 , & V_24 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_49 , V_95 , V_159 , V_90 ) ;
F_95 (sgl, sg, sg_len, i)
V_111 += F_91 ( F_96 ( V_199 ) , V_192 ) ;
V_108 = F_76 ( V_63 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
F_95 (sgl, sg, sg_len, i) {
V_112 = F_97 ( V_199 ) ;
V_198 = F_96 ( V_199 ) ;
V_108 -> V_190 += V_198 ;
do {
V_190 = F_93 ( T_5 , V_198 , V_192 ) ;
if ( V_112 & 0x7 )
V_108 -> V_100 = true ;
V_108 -> V_110 [ V_200 ] -> V_13 =
V_13 | ( V_32 & V_190 ) ;
V_108 -> V_110 [ V_200 ] -> V_23 = V_23 ? V_23 : V_112 ;
V_108 -> V_110 [ V_200 ++ ] -> V_24 = V_24 ? V_24 : V_112 ;
V_112 += V_190 ;
V_198 -= V_190 ;
} while ( V_198 );
}
F_47 ( V_108 , V_90 ) ;
return F_86 ( & V_63 -> V_87 , & V_108 -> V_119 , V_90 ) ;
}
static struct V_152 *
F_98 ( struct V_145 * V_146 ,
T_2 V_201 , T_5 V_190 , T_5 V_202 ,
enum V_158 V_159 , unsigned long V_90 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
struct V_104 * V_108 ;
struct V_20 * * V_203 ;
T_2 V_112 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_111 = 0 ;
if ( ! V_146 || ! V_190 || ! V_202 )
return NULL ;
if ( ( V_159 != V_166 ) && ( V_159 != V_173 ) ) {
F_70 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_50 ) ;
return NULL ;
}
if ( V_190 % V_202 != 0 || V_202 > V_192 ||
! F_92 ( V_202 , 1 << V_193 ) )
return NULL ;
F_89 ( V_63 , V_159 , & V_13 , & V_23 , & V_24 ) ;
V_13 |= V_116 | ( V_32 & V_202 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_51 ,
V_95 , ( unsigned long ) V_201 , V_190 , V_202 , V_159 , V_90 ) ;
V_111 = F_91 ( V_202 , V_192 ) ;
V_111 *= F_91 ( V_190 , V_202 ) ;
V_108 = F_76 ( V_63 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_117 = true ;
V_108 -> V_190 = V_190 ;
V_203 = V_108 -> V_110 ;
V_112 = V_201 ;
do {
V_203 [ 0 ] -> V_23 = V_23 ? V_23 : V_112 ;
V_203 [ 0 ] -> V_24 = V_24 ? V_24 : V_112 ;
V_203 [ 0 ] -> V_13 = V_13 ;
V_203 ++ ;
V_112 += V_202 ;
V_190 -= V_202 ;
} while ( V_190 );
F_47 ( V_108 , V_90 ) ;
return F_86 ( & V_63 -> V_87 , & V_108 -> V_119 , V_90 ) ;
}
static int F_99 ( struct V_145 * V_146 ,
struct V_204 * V_167 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
if ( ! V_146 )
return - V_205 ;
V_63 -> V_167 = * V_167 ;
return 0 ;
}
static int F_100 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
struct V_118 * V_119 = NULL ;
unsigned long V_90 ;
struct V_4 * V_5 ;
F_101 ( V_206 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_52 , V_95 , & V_63 -> V_87 ) ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_102 ( & V_63 -> V_87 , & V_206 ) ;
F_103 (vd, &head, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_53 , V_95 ,
V_119 , V_119 -> V_139 . V_140 , F_48 ( V_119 ) ) ;
}
V_5 = V_63 -> V_5 ;
if ( V_5 ) {
F_44 ( V_63 -> V_5 ) ;
F_35 ( V_63 ) ;
V_63 -> V_5 = NULL ;
F_104 ( & V_57 -> V_91 ) ;
V_5 -> V_93 = NULL ;
F_105 ( & V_57 -> V_91 ) ;
}
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_106 ( & V_63 -> V_87 , & V_206 ) ;
return 0 ;
}
static unsigned int F_107 ( struct V_84 * V_63 ,
T_4 V_140 )
{
struct V_118 * V_119 = NULL ;
struct V_104 * V_108 = NULL ;
struct V_20 * V_110 = NULL ;
T_1 V_207 , V_208 , V_190 , V_209 , V_210 = 0 ;
unsigned long V_90 ;
bool V_211 = false ;
int V_7 ;
if ( ! V_63 -> V_5 )
return 0 ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
V_119 = F_108 ( & V_63 -> V_87 , V_140 ) ;
if ( ! V_119 )
goto V_154;
V_108 = F_49 ( V_119 ) ;
if ( V_108 -> V_110 [ 0 ] -> V_13 & V_177 )
V_207 = F_38 ( V_63 -> V_5 , V_54 ) ;
else
V_207 = F_38 ( V_63 -> V_5 , V_55 ) ;
F_109 () ;
if ( F_48 ( V_119 ) )
goto V_154;
for ( V_7 = 0 ; V_7 < V_108 -> V_111 - 1 ; V_7 ++ ) {
V_110 = V_108 -> V_110 [ V_7 ] ;
if ( V_108 -> V_110 [ 0 ] -> V_13 & V_177 )
V_208 = V_110 -> V_23 ;
else
V_208 = V_110 -> V_24 ;
V_190 = V_110 -> V_13 & V_32 ;
V_209 = V_208 + V_190 ;
if ( V_211 ) {
V_210 += V_190 ;
} else if ( V_207 >= V_208 && V_207 <= V_209 ) {
V_210 += V_209 - V_207 ;
V_211 = true ;
}
}
if ( ! V_211 )
V_210 = V_108 -> V_190 ;
V_154:
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_54 ,
V_95 , V_119 , V_140 , V_108 , V_210 ) ;
return V_210 ;
}
static enum V_212 F_110 ( struct V_145 * V_146 ,
T_4 V_140 ,
struct V_213 * V_214 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
enum V_212 V_144 ;
if ( V_140 == V_63 -> V_105 )
return V_215 ;
V_144 = F_111 ( V_146 , V_140 , V_214 ) ;
if ( F_112 ( V_214 && ( V_144 != V_215 ) ) )
F_113 ( V_214 , F_107 ( V_63 , V_140 ) ) ;
return V_144 ;
}
static void F_114 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_52 ( V_146 ) ;
F_115 ( V_63 -> V_107 , ! F_37 ( V_63 ) ) ;
F_116 ( & V_63 -> V_87 ) ;
}
static void F_117 ( struct V_216 * V_217 )
{
struct V_84 * V_218 , * V_219 ;
F_59 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_61 ( & V_218 -> V_87 . V_63 . V_220 ) ;
F_118 ( & V_218 -> V_87 . V_221 ) ;
}
}
static int F_119 ( struct V_222 * V_223 )
{
struct V_56 * V_57 = F_120 ( V_223 ) ;
F_29 ( V_57 ) ;
F_117 ( & V_57 -> V_74 ) ;
F_121 ( & V_57 -> V_74 ) ;
return 0 ;
}
static int F_122 ( struct V_222 * V_223 ,
struct V_56 * V_57 ,
unsigned int V_224 )
{
int V_225 , V_132 , V_226 = 0 , V_7 , V_144 ;
struct V_4 * V_5 ;
V_225 = F_123 ( V_223 , 0 ) ;
if ( V_225 < 0 )
return V_225 ;
V_57 -> V_68 = F_124 ( & V_223 -> V_75 , V_224 ,
sizeof( V_57 -> V_68 [ 0 ] ) , V_80 ) ;
if ( ! V_57 -> V_68 )
return - V_148 ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ )
if ( F_123 ( V_223 , V_7 ) > 0 )
V_226 ++ ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ ) {
V_5 = & V_57 -> V_68 [ V_7 ] ;
V_5 -> V_10 = V_57 -> V_10 ;
V_5 -> V_9 = V_7 ;
V_132 = F_123 ( V_223 , V_7 ) ;
if ( ( V_226 > 1 ) && ( V_132 > 0 ) )
V_144 = F_125 ( & V_223 -> V_75 , V_132 ,
F_58 ,
V_227 , L_55 , V_5 ) ;
if ( ( V_226 == 1 ) && ( V_7 == 0 ) )
V_144 = F_125 ( & V_223 -> V_75 , V_225 ,
F_64 ,
V_227 , L_55 , V_57 ) ;
if ( V_144 ) {
F_70 ( V_57 -> V_74 . V_75 ,
L_56 , V_95 ,
V_132 , V_144 ) ;
return V_144 ;
}
}
return 0 ;
}
static struct V_145 * F_126 ( struct V_228 * V_229 ,
struct V_230 * V_231 )
{
struct V_56 * V_232 = V_231 -> V_233 ;
struct V_145 * V_63 ;
V_63 = F_127 ( & V_232 -> V_74 ) ;
if ( ! V_63 )
return NULL ;
F_52 ( V_63 ) -> V_8 = V_229 -> args [ 0 ] ;
F_52 ( V_63 ) -> V_86 = V_229 -> args [ 1 ] ;
return V_63 ;
}
static int F_128 ( struct V_222 * V_223 ,
struct V_56 * V_57 ,
unsigned int V_234 ,
unsigned int V_97 )
{
int V_144 ;
unsigned int V_7 ;
struct V_84 * V_218 ;
V_57 -> V_58 = V_234 ;
V_57 -> V_97 = V_97 ;
F_87 ( & V_57 -> V_74 . V_235 ) ;
V_57 -> V_74 . V_236 = F_66 ;
V_57 -> V_74 . V_237 = F_71 ;
V_57 -> V_74 . V_238 = F_110 ;
V_57 -> V_74 . V_239 = F_84 ;
V_57 -> V_74 . V_240 = F_99 ;
V_57 -> V_74 . V_241 = F_114 ;
V_57 -> V_74 . V_242 = F_100 ;
if ( V_223 -> V_75 . V_243 )
F_129 ( & V_223 -> V_75 , V_223 -> V_75 . V_243 ) ;
else
F_129 ( & V_223 -> V_75 , F_130 ( 32 ) ) ;
V_144 = F_122 ( V_223 , V_57 , V_234 ) ;
if ( V_144 )
return V_144 ;
for ( V_7 = 0 ; V_7 < V_234 ; V_7 ++ ) {
V_218 = F_131 ( & V_223 -> V_75 , sizeof( * V_218 ) , V_80 ) ;
if ( ! V_218 )
return - V_148 ;
V_218 -> V_87 . V_244 = F_74 ;
F_132 ( & V_218 -> V_87 , & V_57 -> V_74 ) ;
F_133 ( & V_218 -> V_107 ) ;
}
return F_134 ( & V_57 -> V_74 ) ;
}
static int F_135 ( struct V_222 * V_223 )
{
struct V_56 * V_57 ;
const struct V_245 * V_246 ;
struct V_247 * V_248 = F_136 ( & V_223 -> V_75 ) ;
struct V_249 * V_250 ;
int V_144 , V_251 = 0 , V_252 = 0 ;
const enum V_164 V_253 =
V_180 | V_182 |
V_184 ;
V_57 = F_131 ( & V_223 -> V_75 , sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return - V_148 ;
F_137 ( & V_57 -> V_91 ) ;
V_250 = F_138 ( V_223 , V_254 , 0 ) ;
V_57 -> V_10 = F_139 ( & V_223 -> V_75 , V_250 ) ;
if ( F_25 ( V_57 -> V_10 ) )
return F_140 ( V_57 -> V_10 ) ;
V_246 = F_141 ( V_255 , & V_223 -> V_75 ) ;
if ( V_246 ) {
F_142 ( V_223 -> V_75 . V_256 , L_57 ,
& V_251 ) ;
V_144 = F_142 ( V_223 -> V_75 . V_256 , L_58 ,
& V_252 ) ;
if ( V_144 ) {
F_57 ( V_57 -> V_74 . V_75 ,
L_59 ,
V_144 ) ;
V_252 = 32 ;
} ;
} else if ( V_248 && V_248 -> V_251 ) {
V_251 = V_248 -> V_251 ;
V_252 = V_248 -> V_252 ;
} else {
V_251 = 32 ;
}
F_143 ( V_257 , V_57 -> V_74 . V_258 ) ;
F_143 ( V_259 , V_57 -> V_74 . V_258 ) ;
F_143 ( V_260 , V_57 -> V_74 . V_258 ) ;
F_143 ( V_261 , V_57 -> V_74 . V_258 ) ;
V_57 -> V_74 . V_262 = F_90 ;
V_57 -> V_74 . V_263 = F_94 ;
V_57 -> V_74 . V_264 = F_98 ;
V_57 -> V_74 . V_265 = V_193 ;
V_57 -> V_74 . V_266 = V_253 ;
V_57 -> V_74 . V_267 = V_253 ;
V_57 -> V_74 . V_268 = F_14 ( V_173 ) | F_14 ( V_166 ) ;
V_57 -> V_74 . V_269 = V_270 ;
V_57 -> V_74 . V_271 = true ;
V_57 -> V_74 . V_75 = & V_223 -> V_75 ;
V_144 = F_128 ( V_223 , V_57 , V_251 , V_252 ) ;
if ( V_144 ) {
F_70 ( V_57 -> V_74 . V_75 , L_60 ) ;
return V_144 ;
}
if ( V_223 -> V_75 . V_256 ) {
V_144 = F_144 ( V_223 -> V_75 . V_256 ,
F_126 , V_57 ) ;
if ( V_144 < 0 ) {
F_70 ( V_57 -> V_74 . V_75 ,
L_61 ) ;
return V_144 ;
}
}
F_145 ( V_223 , V_57 ) ;
F_23 ( V_57 ) ;
F_146 ( V_57 -> V_74 . V_75 , L_62 ,
V_251 , V_252 ) ;
return 0 ;
}
bool F_147 ( struct V_145 * V_63 , void * V_272 )
{
struct V_84 * V_218 = F_52 ( V_63 ) ;
struct V_273 * V_3 = V_272 ;
if ( V_63 -> V_88 -> V_75 -> V_274 != & V_275 . V_274 )
return false ;
V_218 -> V_8 = V_3 -> V_8 ;
V_218 -> V_86 = V_3 -> V_86 ;
return true ;
}
