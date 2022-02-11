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
if ( ( V_7 < 32 ) && ( V_93 & F_14 ( V_7 ) ) )
continue;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ! V_5 -> V_94 ) {
V_5 -> V_94 = V_85 ;
V_89 = V_5 ;
if ( V_7 < 32 )
V_95 |= F_14 ( V_7 ) ;
goto V_96;
}
}
}
V_96:
F_33 ( & V_57 -> V_91 , V_90 ) ;
F_34 ( & V_85 -> V_87 . V_63 . V_75 -> V_88 ,
L_31 , V_97 , V_89 ,
V_89 ? V_89 -> V_9 : - 1 ) ;
return V_89 ;
}
static void F_35 ( struct V_84 * V_63 )
{
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
unsigned long V_90 ;
T_1 V_98 ;
int V_7 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_32 , V_97 ) ;
if ( ! V_63 -> V_5 )
return;
if ( V_63 -> V_8 <= V_57 -> V_99 ) {
V_98 = F_1 ( V_63 -> V_8 ) ;
F_36 ( 0 , V_63 -> V_5 -> V_10 + V_98 ) ;
}
F_32 ( & V_57 -> V_91 , V_90 ) ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ )
if ( V_63 -> V_5 == & V_57 -> V_68 [ V_7 ] )
V_95 &= ~ F_14 ( V_7 ) ;
V_63 -> V_5 -> V_94 = NULL ;
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
return V_34 & V_100 ;
}
static bool F_39 ( struct V_84 * V_63 )
{
T_1 V_101 ;
F_40 ( ! V_63 -> V_5 ) ;
V_101 = F_38 ( V_63 -> V_5 , V_38 ) ;
return V_101 & ( F_14 ( V_63 -> V_5 -> V_9 ) ) ;
}
static void F_41 ( struct V_4 * V_5 , bool V_102 )
{
struct V_56 * V_57 ;
T_1 V_98 , V_101 ;
if ( ! V_5 -> V_94 )
return;
F_34 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_33 , V_97 ,
V_5 , V_5 -> V_9 , V_102 ) ;
V_57 = F_31 ( V_5 -> V_94 -> V_87 . V_63 . V_88 ) ;
if ( V_5 -> V_94 -> V_8 <= V_57 -> V_99 ) {
V_98 = F_1 ( V_5 -> V_94 -> V_8 ) ;
F_36 ( V_12 | V_5 -> V_9 , V_5 -> V_10 + V_98 ) ;
}
V_101 = F_38 ( V_5 , V_38 ) ;
if ( V_102 )
V_101 |= F_14 ( V_5 -> V_9 ) ;
else
V_101 &= ~ F_14 ( V_5 -> V_9 ) ;
F_42 ( V_5 , V_101 , V_38 ) ;
F_43 ( V_5 , V_103 | V_104 |
V_105 | V_100 , V_36 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
T_1 V_34 ;
if ( ! V_5 )
return;
V_34 = F_38 ( V_5 , V_36 ) ;
F_34 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_31 , V_97 , V_5 , V_5 -> V_9 ) ;
F_43 ( V_5 , V_34 & ~ V_100 & ~ V_103 , V_36 ) ;
}
static void F_45 ( struct V_84 * V_63 ,
struct V_106 * V_21 )
{
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_34 , V_97 , V_21 ) ;
if ( ! V_63 -> V_5 ) {
V_63 -> V_5 = F_30 ( V_63 ) ;
if ( ! V_63 -> V_5 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_35 , V_97 ) ;
return;
}
}
V_63 -> V_107 = 0 ;
F_43 ( V_63 -> V_5 , V_21 -> V_108 , V_22 ) ;
F_41 ( V_63 -> V_5 , V_63 -> V_102 ) ;
}
static void F_46 ( struct V_106 * V_109 ,
unsigned long V_90 )
{
struct V_20 * V_110 =
V_109 -> V_111 [ V_109 -> V_112 - 1 ] ;
T_2 V_113 = V_109 -> V_111 [ V_109 -> V_112 - 2 ] -> V_19 ;
V_110 -> V_19 = V_33 ;
V_110 -> V_23 = V_113 ;
V_110 -> V_24 = V_113 + 8 ;
V_110 -> V_13 = V_114 | V_115 |
( V_32 & sizeof( T_1 ) ) ;
if ( V_90 & V_116 )
V_110 -> V_13 |= V_117 ;
if ( V_109 -> V_118 )
V_109 -> V_111 [ V_109 -> V_112 - 2 ] -> V_19 = V_109 -> V_108 ;
}
static bool F_47 ( struct V_119 * V_120 )
{
struct V_106 * V_109 = F_48 ( V_120 ) ;
struct V_20 * V_110 =
V_109 -> V_111 [ V_109 -> V_112 - 1 ] ;
return V_110 -> V_24 != ( V_110 -> V_23 + 8 ) ;
}
static void F_49 ( struct V_119 * V_121 ,
struct V_119 * V_122 )
{
struct V_106 * V_123 = F_48 ( V_121 ) ;
struct V_106 * V_124 = F_48 ( V_122 ) ;
T_2 V_125 ;
V_125 = V_124 -> V_108 ;
V_123 -> V_111 [ V_123 -> V_112 - 1 ] -> V_19 = V_125 ;
}
static bool F_50 ( struct V_126 * V_87 ,
struct V_119 * V_120 )
{
struct V_119 * V_127 = NULL ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
if ( F_37 ( V_63 ) ) {
F_40 ( F_52 ( & V_87 -> V_128 ) ) ;
if ( ! F_39 ( V_63 ) &&
F_48 ( V_120 ) -> V_102 )
return false ;
V_127 = F_53 ( V_87 -> V_128 . V_129 ,
struct V_119 , V_130 ) ;
F_49 ( V_127 , V_120 ) ;
if ( F_37 ( V_63 ) || F_47 ( V_127 ) )
return true ;
}
return false ;
}
static unsigned int F_54 ( struct V_4 * V_5 )
{
T_1 V_34 ;
T_1 V_131 = F_55 ( V_5 -> V_10 + V_132 ) ;
if ( ! ( V_131 & F_14 ( V_5 -> V_9 ) ) )
return V_100 ;
V_34 = F_38 ( V_5 , V_36 ) ;
F_43 ( V_5 , V_34 , V_36 ) ;
if ( ( V_34 & V_105 ) && ( V_5 -> V_94 ) )
F_56 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_36 ,
V_97 , & V_5 -> V_94 ) ;
return V_34 & ~ V_100 ;
}
static T_3 F_57 ( int V_133 , void * V_134 )
{
struct V_4 * V_5 = V_134 ;
struct V_84 * V_63 = V_5 -> V_94 ;
struct V_119 * V_120 , * V_135 ;
unsigned int V_34 ;
unsigned long V_90 ;
T_4 V_136 = 0 ;
F_40 ( ! V_63 ) ;
V_34 = F_54 ( V_5 ) ;
if ( V_34 & V_100 )
return V_137 ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_58 (vd, tmp, &chan->vc.desc_issued, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_37 ,
V_97 , V_120 , V_120 -> V_139 . V_140 , F_47 ( V_120 ) ) ;
V_136 = V_120 -> V_139 . V_140 ;
if ( F_48 ( V_120 ) -> V_118 ) {
F_59 ( V_120 ) ;
break;
}
if ( F_47 ( V_120 ) ) {
F_60 ( & V_120 -> V_130 ) ;
F_61 ( V_120 ) ;
} else {
break;
}
}
if ( V_34 & V_105 ) {
V_63 -> V_107 = V_136 ;
F_44 ( V_5 ) ;
}
if ( ! V_63 -> V_107 && V_34 & V_141 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_38 ,
V_97 ,
F_52 ( & V_63 -> V_87 . V_142 ) ,
F_52 ( & V_63 -> V_87 . V_128 ) ) ;
F_42 ( V_5 , V_34 & ~ V_103 , V_36 ) ;
if ( F_52 ( & V_63 -> V_87 . V_128 ) ) {
V_63 -> V_102 =
! F_52 ( & V_63 -> V_87 . V_142 ) ;
} else {
V_120 = F_62 ( & V_63 -> V_87 . V_128 ,
struct V_119 , V_130 ) ;
F_45 ( V_63 , F_48 ( V_120 ) ) ;
}
}
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
return V_143 ;
}
static T_3 F_63 ( int V_133 , void * V_134 )
{
struct V_56 * V_57 = V_134 ;
struct V_4 * V_5 ;
T_1 V_131 = F_55 ( V_57 -> V_10 + V_132 ) ;
int V_7 , V_144 = V_137 ;
while ( V_131 ) {
V_7 = F_64 ( V_131 ) ;
V_131 &= ( V_131 - 1 ) ;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ( V_7 < 32 ) && ( V_93 & F_14 ( V_7 ) ) )
continue;
if ( F_57 ( V_133 , V_5 ) == V_143 )
V_144 = V_143 ;
}
return V_144 ;
}
static int F_65 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
if ( V_63 -> V_147 )
return 1 ;
V_63 -> V_147 = F_66 ( F_67 ( V_146 ) ,
V_57 -> V_74 . V_75 ,
sizeof( struct V_20 ) ,
F_68 ( struct V_20 ) ,
0 ) ;
if ( ! V_63 -> V_147 ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_39 ,
V_97 ) ;
return - V_148 ;
}
return 1 ;
}
static void F_70 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
F_71 ( & V_63 -> V_87 ) ;
F_72 ( V_63 -> V_147 ) ;
V_63 -> V_147 = NULL ;
}
static void F_73 ( struct V_119 * V_120 )
{
int V_7 ;
T_2 V_113 ;
struct V_106 * V_109 = F_48 ( V_120 ) ;
F_40 ( V_109 -> V_112 == 0 ) ;
for ( V_7 = V_109 -> V_112 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 )
V_113 = V_109 -> V_111 [ V_7 - 1 ] -> V_19 ;
else
V_113 = V_109 -> V_108 ;
F_74 ( V_109 -> V_147 ,
V_109 -> V_111 [ V_7 ] , V_113 ) ;
}
V_109 -> V_112 = 0 ;
F_27 ( V_109 ) ;
}
static struct V_106 *
F_75 ( struct V_84 * V_63 , unsigned int V_149 )
{
struct V_106 * V_109 ;
T_2 V_113 ;
int V_7 ;
V_109 = F_76 ( sizeof( * V_109 ) +
V_149 * sizeof( struct V_20 * ) ,
V_150 ) ;
if ( ! V_109 )
return NULL ;
V_109 -> V_147 = V_63 -> V_147 ;
for ( V_7 = 0 ; V_7 < V_149 ; V_7 ++ ) {
V_109 -> V_111 [ V_7 ] = F_77 ( V_109 -> V_147 ,
V_150 , & V_113 ) ;
if ( ! V_109 -> V_111 [ V_7 ] ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_40 ,
V_97 , V_7 , V_109 -> V_147 ) ;
goto V_151;
}
if ( V_7 == 0 )
V_109 -> V_108 = V_113 ;
else
V_109 -> V_111 [ V_7 - 1 ] -> V_19 = V_113 ;
V_109 -> V_112 ++ ;
}
return V_109 ;
V_151:
F_73 ( & V_109 -> V_120 ) ;
return NULL ;
}
static T_4 F_78 ( struct V_152 * V_139 )
{
struct V_126 * V_87 = F_79 ( V_139 -> V_63 ) ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
struct V_119 * V_153 = NULL ,
* V_120 = F_80 ( V_139 , struct V_119 , V_139 ) ;
T_4 V_140 ;
unsigned long V_90 ;
F_46 ( F_48 ( V_120 ) , V_139 -> V_90 ) ;
F_32 ( & V_87 -> V_138 , V_90 ) ;
V_140 = F_81 ( V_139 ) ;
if ( F_52 ( & V_87 -> V_142 ) && F_50 ( V_87 , V_120 ) ) {
F_82 ( & V_120 -> V_130 , & V_87 -> V_128 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_41 ,
V_97 , V_120 , V_140 ) ;
goto V_154;
}
if ( ! F_52 ( & V_87 -> V_142 ) ) {
V_153 = F_53 ( V_87 -> V_142 . V_129 ,
struct V_119 , V_130 ) ;
if ( V_63 -> V_102 || ! F_48 ( V_120 ) -> V_102 )
F_49 ( V_153 , V_120 ) ;
else
V_153 = NULL ;
}
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_42 ,
V_97 , V_120 , V_140 , V_153 ? L_43 : L_44 ) ;
F_82 ( & V_120 -> V_130 , & V_87 -> V_142 ) ;
V_63 -> V_102 |= F_48 ( V_120 ) -> V_102 ;
V_154:
F_33 ( & V_87 -> V_138 , V_90 ) ;
return V_140 ;
}
static void F_83 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
struct V_119 * V_155 ;
unsigned long V_90 ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
if ( F_52 ( & V_63 -> V_87 . V_142 ) )
goto V_154;
V_155 = F_62 ( & V_63 -> V_87 . V_142 ,
struct V_119 , V_130 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_45 , V_97 , V_155 , V_155 -> V_139 . V_140 ) ;
F_84 ( & V_63 -> V_87 ) ;
if ( ! F_50 ( & V_63 -> V_87 , V_155 ) )
F_45 ( V_63 , F_48 ( V_155 ) ) ;
V_154:
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
}
static inline struct V_152 *
F_85 ( struct V_126 * V_87 , struct V_119 * V_120 ,
unsigned long V_156 )
{
struct V_152 * V_139 ;
struct V_84 * V_63 = F_80 ( V_87 , struct V_84 , V_87 ) ;
F_86 ( & V_120 -> V_130 ) ;
V_139 = F_87 ( V_87 , V_120 , V_156 ) ;
V_139 -> V_157 = F_78 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_46 , V_97 ,
V_87 , V_120 , V_120 -> V_139 . V_140 ,
V_156 ) ;
return V_139 ;
}
static void F_88 ( struct V_84 * V_63 ,
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
if ( V_63 -> V_8 <= V_57 -> V_99 )
* V_13 |= V_172 ;
}
if ( V_159 == V_173 ) {
V_162 = V_63 -> V_167 . V_174 ;
V_17 = V_63 -> V_167 . V_175 ;
V_163 = V_63 -> V_167 . V_176 ;
* V_161 = V_163 ;
* V_13 |= V_177 ;
if ( V_63 -> V_8 <= V_57 -> V_99 )
* V_13 |= V_178 ;
}
if ( V_159 == V_179 )
* V_13 |= V_115 | V_171 |
V_177 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_47 ,
V_97 , V_163 , V_162 , V_17 , V_159 ) ;
if ( V_17 == V_180 )
* V_13 |= V_181 ;
else if ( V_17 == V_182 )
* V_13 |= V_183 ;
else if ( V_17 == V_184 )
* V_13 |= V_114 ;
if ( V_162 == 8 )
* V_13 |= V_185 ;
else if ( V_162 == 16 )
* V_13 |= V_186 ;
else if ( V_162 == 32 )
* V_13 |= V_115 ;
if ( V_63 -> V_167 . V_187 )
V_63 -> V_8 = V_63 -> V_167 . V_187 ;
}
static struct V_152 *
F_89 ( struct V_145 * V_146 ,
T_2 V_188 , T_2 V_189 ,
T_5 V_190 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
struct V_106 * V_109 ;
struct V_20 * V_111 ;
T_1 V_13 ;
unsigned int V_7 , V_112 = 0 ;
T_5 V_191 ;
if ( ! V_146 || ! V_190 )
return NULL ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_48 ,
V_97 , ( unsigned long ) V_188 , ( unsigned long ) V_189 ,
V_190 , V_90 ) ;
F_88 ( V_63 , V_179 , & V_13 , NULL , NULL ) ;
V_112 = F_90 ( V_190 , V_192 ) ;
V_109 = F_75 ( V_63 , V_112 + 1 ) ;
if ( ! V_109 )
return NULL ;
V_109 -> V_190 = V_190 ;
if ( ! F_91 ( V_189 , 1 << V_193 ) ||
! F_91 ( V_188 , 1 << V_193 ) )
V_109 -> V_102 = true ;
V_7 = 0 ;
do {
V_111 = V_109 -> V_111 [ V_7 ++ ] ;
V_191 = F_92 ( T_5 , V_190 , V_192 ) ;
V_111 -> V_13 = V_13 | ( V_32 & V_191 ) ;
V_111 -> V_23 = V_189 ;
V_111 -> V_24 = V_188 ;
V_190 -= V_191 ;
V_189 += V_191 ;
V_188 += V_191 ;
} while ( V_190 );
F_46 ( V_109 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_109 -> V_120 , V_90 ) ;
}
static struct V_152 *
F_93 ( struct V_145 * V_146 , struct V_194 * V_195 ,
unsigned int V_196 , enum V_158 V_159 ,
unsigned long V_90 , void * V_197 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
struct V_106 * V_109 ;
T_5 V_190 , V_198 ;
struct V_194 * V_199 ;
T_2 V_113 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_112 = 0 , V_7 , V_200 = 0 ;
if ( ( V_195 == NULL ) || ( V_196 == 0 ) )
return NULL ;
F_88 ( V_63 , V_159 , & V_13 , & V_23 , & V_24 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_49 , V_97 , V_159 , V_90 ) ;
F_94 (sgl, sg, sg_len, i)
V_112 += F_90 ( F_95 ( V_199 ) , V_192 ) ;
V_109 = F_75 ( V_63 , V_112 + 1 ) ;
if ( ! V_109 )
return NULL ;
F_94 (sgl, sg, sg_len, i) {
V_113 = F_96 ( V_199 ) ;
V_198 = F_95 ( V_199 ) ;
V_109 -> V_190 += V_198 ;
do {
V_190 = F_92 ( T_5 , V_198 , V_192 ) ;
if ( V_113 & 0x7 )
V_109 -> V_102 = true ;
V_109 -> V_111 [ V_200 ] -> V_13 =
V_13 | ( V_32 & V_190 ) ;
V_109 -> V_111 [ V_200 ] -> V_23 = V_23 ? V_23 : V_113 ;
V_109 -> V_111 [ V_200 ++ ] -> V_24 = V_24 ? V_24 : V_113 ;
V_113 += V_190 ;
V_198 -= V_190 ;
} while ( V_198 );
}
F_46 ( V_109 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_109 -> V_120 , V_90 ) ;
}
static struct V_152 *
F_97 ( struct V_145 * V_146 ,
T_2 V_201 , T_5 V_190 , T_5 V_202 ,
enum V_158 V_159 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
struct V_106 * V_109 ;
struct V_20 * * V_203 ;
T_2 V_113 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_112 = 0 ;
if ( ! V_146 || ! V_190 || ! V_202 )
return NULL ;
if ( ( V_159 != V_166 ) && ( V_159 != V_173 ) ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_50 ) ;
return NULL ;
}
if ( V_190 % V_202 != 0 || V_202 > V_192 ||
! F_91 ( V_202 , 1 << V_193 ) )
return NULL ;
F_88 ( V_63 , V_159 , & V_13 , & V_23 , & V_24 ) ;
V_13 |= V_117 | ( V_32 & V_202 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_51 ,
V_97 , ( unsigned long ) V_201 , V_190 , V_202 , V_159 , V_90 ) ;
V_112 = F_90 ( V_202 , V_192 ) ;
V_112 *= F_90 ( V_190 , V_202 ) ;
V_109 = F_75 ( V_63 , V_112 + 1 ) ;
if ( ! V_109 )
return NULL ;
V_109 -> V_118 = true ;
V_109 -> V_190 = V_190 ;
V_203 = V_109 -> V_111 ;
V_113 = V_201 ;
do {
V_203 [ 0 ] -> V_23 = V_23 ? V_23 : V_113 ;
V_203 [ 0 ] -> V_24 = V_24 ? V_24 : V_113 ;
V_203 [ 0 ] -> V_13 = V_13 ;
V_203 ++ ;
V_113 += V_202 ;
V_190 -= V_202 ;
} while ( V_190 );
F_46 ( V_109 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_109 -> V_120 , V_90 ) ;
}
static int F_98 ( struct V_145 * V_146 ,
struct V_204 * V_167 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
if ( ! V_146 )
return - V_205 ;
V_63 -> V_167 = * V_167 ;
return 0 ;
}
static int F_99 ( struct V_145 * V_146 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
struct V_119 * V_120 = NULL ;
unsigned long V_90 ;
struct V_4 * V_5 ;
F_100 ( V_206 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_52 , V_97 , & V_63 -> V_87 ) ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_101 ( & V_63 -> V_87 , & V_206 ) ;
F_102 (vd, &head, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_53 , V_97 ,
V_120 , V_120 -> V_139 . V_140 , F_47 ( V_120 ) ) ;
}
V_5 = V_63 -> V_5 ;
if ( V_5 ) {
F_44 ( V_63 -> V_5 ) ;
F_35 ( V_63 ) ;
V_63 -> V_5 = NULL ;
F_103 ( & V_57 -> V_91 ) ;
V_5 -> V_94 = NULL ;
F_104 ( & V_57 -> V_91 ) ;
}
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_105 ( & V_63 -> V_87 , & V_206 ) ;
return 0 ;
}
static unsigned int F_106 ( struct V_84 * V_63 ,
T_4 V_140 )
{
struct V_119 * V_120 = NULL ;
struct V_106 * V_109 = NULL ;
struct V_20 * V_111 = NULL ;
T_1 V_207 , V_208 , V_190 , V_209 , V_210 = 0 ;
unsigned long V_90 ;
bool V_211 = false ;
int V_7 ;
if ( ! V_63 -> V_5 )
return 0 ;
F_32 ( & V_63 -> V_87 . V_138 , V_90 ) ;
V_120 = F_107 ( & V_63 -> V_87 , V_140 ) ;
if ( ! V_120 )
goto V_154;
V_109 = F_48 ( V_120 ) ;
if ( V_109 -> V_111 [ 0 ] -> V_13 & V_177 )
V_207 = F_38 ( V_63 -> V_5 , V_54 ) ;
else
V_207 = F_38 ( V_63 -> V_5 , V_55 ) ;
F_108 () ;
if ( F_47 ( V_120 ) )
goto V_154;
for ( V_7 = 0 ; V_7 < V_109 -> V_112 - 1 ; V_7 ++ ) {
V_111 = V_109 -> V_111 [ V_7 ] ;
if ( V_109 -> V_111 [ 0 ] -> V_13 & V_177 )
V_208 = V_111 -> V_23 ;
else
V_208 = V_111 -> V_24 ;
V_190 = V_111 -> V_13 & V_32 ;
V_209 = V_208 + V_190 ;
if ( V_211 ) {
V_210 += V_190 ;
} else if ( V_207 >= V_208 && V_207 <= V_209 ) {
V_210 += V_209 - V_207 ;
V_211 = true ;
}
}
if ( ! V_211 )
V_210 = V_109 -> V_190 ;
V_154:
F_33 ( & V_63 -> V_87 . V_138 , V_90 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_54 ,
V_97 , V_120 , V_140 , V_109 , V_210 ) ;
return V_210 ;
}
static enum V_212 F_109 ( struct V_145 * V_146 ,
T_4 V_140 ,
struct V_213 * V_214 )
{
struct V_84 * V_63 = F_51 ( V_146 ) ;
enum V_212 V_144 ;
if ( V_140 == V_63 -> V_107 )
return V_215 ;
V_144 = F_110 ( V_146 , V_140 , V_214 ) ;
if ( F_111 ( V_214 && ( V_144 != V_215 ) ) )
F_112 ( V_214 , F_106 ( V_63 , V_140 ) ) ;
return V_144 ;
}
static void F_113 ( struct V_216 * V_217 )
{
struct V_84 * V_218 , * V_219 ;
F_58 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_60 ( & V_218 -> V_87 . V_63 . V_220 ) ;
F_114 ( & V_218 -> V_87 . V_221 ) ;
}
}
static int F_115 ( struct V_222 * V_223 )
{
struct V_56 * V_57 = F_116 ( V_223 ) ;
F_29 ( V_57 ) ;
F_113 ( & V_57 -> V_74 ) ;
F_117 ( & V_57 -> V_74 ) ;
return 0 ;
}
static int F_118 ( struct V_222 * V_223 ,
struct V_56 * V_57 ,
unsigned int V_224 )
{
int V_225 , V_133 , V_226 = 0 , V_7 , V_144 ;
struct V_4 * V_5 ;
V_225 = F_119 ( V_223 , 0 ) ;
if ( V_225 < 0 )
return V_225 ;
V_57 -> V_68 = F_120 ( & V_223 -> V_75 , V_224 ,
sizeof( V_57 -> V_68 [ 0 ] ) , V_80 ) ;
if ( ! V_57 -> V_68 )
return - V_148 ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ )
if ( F_119 ( V_223 , V_7 ) > 0 )
V_226 ++ ;
for ( V_7 = 0 ; V_7 < V_224 ; V_7 ++ ) {
V_5 = & V_57 -> V_68 [ V_7 ] ;
V_5 -> V_10 = V_57 -> V_10 ;
V_5 -> V_9 = V_7 ;
V_133 = F_119 ( V_223 , V_7 ) ;
if ( ( V_226 > 1 ) && ( V_133 > 0 ) )
V_144 = F_121 ( & V_223 -> V_75 , V_133 ,
F_57 ,
V_227 , L_55 , V_5 ) ;
if ( ( V_226 == 1 ) && ( V_7 == 0 ) )
V_144 = F_121 ( & V_223 -> V_75 , V_225 ,
F_63 ,
V_227 , L_55 , V_57 ) ;
if ( V_144 ) {
F_69 ( V_57 -> V_74 . V_75 ,
L_56 , V_97 ,
V_133 , V_144 ) ;
return V_144 ;
}
}
return 0 ;
}
static struct V_145 * F_122 ( struct V_228 * V_229 ,
struct V_230 * V_231 )
{
struct V_56 * V_232 = V_231 -> V_233 ;
struct V_145 * V_63 ;
V_63 = F_123 ( & V_232 -> V_74 ) ;
if ( ! V_63 )
return NULL ;
F_51 ( V_63 ) -> V_8 = V_229 -> args [ 0 ] ;
F_51 ( V_63 ) -> V_86 = V_229 -> args [ 1 ] ;
return V_63 ;
}
static int F_124 ( struct V_222 * V_223 ,
struct V_56 * V_57 ,
unsigned int V_234 ,
unsigned int V_99 )
{
int V_144 ;
unsigned int V_7 ;
struct V_84 * V_218 ;
V_57 -> V_58 = V_234 ;
V_57 -> V_99 = V_99 ;
F_86 ( & V_57 -> V_74 . V_235 ) ;
V_57 -> V_74 . V_236 = F_65 ;
V_57 -> V_74 . V_237 = F_70 ;
V_57 -> V_74 . V_238 = F_109 ;
V_57 -> V_74 . V_239 = F_83 ;
V_57 -> V_74 . V_240 = F_98 ;
V_57 -> V_74 . V_241 = F_99 ;
if ( V_223 -> V_75 . V_242 )
F_125 ( & V_223 -> V_75 , V_223 -> V_75 . V_242 ) ;
else
F_125 ( & V_223 -> V_75 , F_126 ( 32 ) ) ;
V_144 = F_118 ( V_223 , V_57 , V_234 ) ;
if ( V_144 )
return V_144 ;
for ( V_7 = 0 ; V_7 < V_234 ; V_7 ++ ) {
V_218 = F_127 ( & V_223 -> V_75 , sizeof( * V_218 ) , V_80 ) ;
if ( ! V_218 )
return - V_148 ;
V_218 -> V_87 . V_243 = F_73 ;
F_128 ( & V_218 -> V_87 , & V_57 -> V_74 ) ;
}
return F_129 ( & V_57 -> V_74 ) ;
}
static int F_130 ( struct V_222 * V_223 )
{
struct V_56 * V_57 ;
const struct V_244 * V_245 ;
struct V_246 * V_247 = F_131 ( & V_223 -> V_75 ) ;
struct V_248 * V_249 ;
int V_144 , V_250 = 0 , V_251 = 0 ;
const enum V_164 V_252 =
V_180 | V_182 |
V_184 ;
V_57 = F_127 ( & V_223 -> V_75 , sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return - V_148 ;
F_132 ( & V_57 -> V_91 ) ;
V_249 = F_133 ( V_223 , V_253 , 0 ) ;
V_57 -> V_10 = F_134 ( & V_223 -> V_75 , V_249 ) ;
if ( F_25 ( V_57 -> V_10 ) )
return F_135 ( V_57 -> V_10 ) ;
V_245 = F_136 ( V_254 , & V_223 -> V_75 ) ;
if ( V_245 ) {
F_137 ( V_223 -> V_75 . V_255 , L_57 ,
& V_250 ) ;
V_144 = F_137 ( V_223 -> V_75 . V_255 , L_58 ,
& V_251 ) ;
if ( V_144 ) {
F_56 ( V_57 -> V_74 . V_75 ,
L_59 ,
V_144 ) ;
V_251 = 32 ;
} ;
} else if ( V_247 && V_247 -> V_250 ) {
V_250 = V_247 -> V_250 ;
V_251 = V_247 -> V_251 ;
} else {
V_250 = 32 ;
}
F_138 ( V_256 , V_57 -> V_74 . V_257 ) ;
F_138 ( V_258 , V_57 -> V_74 . V_257 ) ;
F_138 ( V_259 , V_57 -> V_74 . V_257 ) ;
F_138 ( V_260 , V_57 -> V_74 . V_257 ) ;
V_57 -> V_74 . V_261 = F_89 ;
V_57 -> V_74 . V_262 = F_93 ;
V_57 -> V_74 . V_263 = F_97 ;
V_57 -> V_74 . V_264 = V_193 ;
V_57 -> V_74 . V_265 = V_252 ;
V_57 -> V_74 . V_266 = V_252 ;
V_57 -> V_74 . V_267 = F_14 ( V_173 ) | F_14 ( V_166 ) ;
V_57 -> V_74 . V_268 = V_269 ;
V_57 -> V_74 . V_270 = true ;
V_57 -> V_74 . V_75 = & V_223 -> V_75 ;
V_144 = F_124 ( V_223 , V_57 , V_250 , V_251 ) ;
if ( V_144 ) {
F_69 ( V_57 -> V_74 . V_75 , L_60 ) ;
return V_144 ;
}
if ( V_223 -> V_75 . V_255 ) {
V_144 = F_139 ( V_223 -> V_75 . V_255 ,
F_122 , V_57 ) ;
if ( V_144 < 0 ) {
F_69 ( V_57 -> V_74 . V_75 ,
L_61 ) ;
return V_144 ;
}
}
F_140 ( V_223 , V_57 ) ;
F_23 ( V_57 ) ;
F_141 ( V_57 -> V_74 . V_75 , L_62 ,
V_250 , V_251 ) ;
return 0 ;
}
bool F_142 ( struct V_145 * V_63 , void * V_271 )
{
struct V_84 * V_218 = F_51 ( V_63 ) ;
struct V_272 * V_3 = V_271 ;
if ( V_63 -> V_88 -> V_75 -> V_273 != & V_274 . V_273 )
return false ;
V_218 -> V_8 = V_3 -> V_8 ;
V_218 -> V_86 = V_3 -> V_86 ;
return true ;
}
int F_143 ( int V_275 )
{
if ( V_95 & ( F_14 ( V_275 ) ) )
return - V_276 ;
V_93 ^= F_14 ( V_275 ) ;
return 0 ;
}
