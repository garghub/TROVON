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
F_46 ( & V_63 -> V_109 ) ;
}
static void F_47 ( struct V_106 * V_110 ,
unsigned long V_90 )
{
struct V_20 * V_111 =
V_110 -> V_112 [ V_110 -> V_113 - 1 ] ;
T_2 V_114 = V_110 -> V_112 [ V_110 -> V_113 - 2 ] -> V_19 ;
V_111 -> V_19 = V_33 ;
V_111 -> V_23 = V_114 ;
V_111 -> V_24 = V_114 + 8 ;
V_111 -> V_13 = V_115 | V_116 |
( V_32 & sizeof( T_1 ) ) ;
if ( V_90 & V_117 )
V_111 -> V_13 |= V_118 ;
if ( V_110 -> V_119 )
V_110 -> V_112 [ V_110 -> V_113 - 2 ] -> V_19 = V_110 -> V_108 ;
}
static bool F_48 ( struct V_120 * V_121 )
{
struct V_106 * V_110 = F_49 ( V_121 ) ;
struct V_20 * V_111 =
V_110 -> V_112 [ V_110 -> V_113 - 1 ] ;
return V_111 -> V_24 != ( V_111 -> V_23 + 8 ) ;
}
static void F_50 ( struct V_120 * V_122 ,
struct V_120 * V_123 )
{
struct V_106 * V_124 = F_49 ( V_122 ) ;
struct V_106 * V_125 = F_49 ( V_123 ) ;
T_2 V_126 ;
V_126 = V_125 -> V_108 ;
V_124 -> V_112 [ V_124 -> V_113 - 1 ] -> V_19 = V_126 ;
}
static bool F_51 ( struct V_127 * V_87 ,
struct V_120 * V_121 )
{
struct V_120 * V_128 = NULL ;
struct V_84 * V_63 = F_52 ( & V_87 -> V_63 ) ;
if ( F_37 ( V_63 ) ) {
F_40 ( F_53 ( & V_87 -> V_129 ) ) ;
if ( ! F_39 ( V_63 ) &&
F_49 ( V_121 ) -> V_102 )
return false ;
V_128 = F_54 ( V_87 -> V_129 . V_130 ,
struct V_120 , V_131 ) ;
F_50 ( V_128 , V_121 ) ;
if ( F_37 ( V_63 ) || F_48 ( V_121 ) )
return true ;
}
return false ;
}
static unsigned int F_55 ( struct V_4 * V_5 )
{
T_1 V_34 ;
T_1 V_132 = F_56 ( V_5 -> V_10 + V_133 ) ;
if ( ! ( V_132 & F_14 ( V_5 -> V_9 ) ) )
return V_100 ;
V_34 = F_38 ( V_5 , V_36 ) ;
F_43 ( V_5 , V_34 , V_36 ) ;
if ( ( V_34 & V_105 ) && ( V_5 -> V_94 ) )
F_57 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_36 ,
V_97 , & V_5 -> V_94 ) ;
return V_34 & ~ V_100 ;
}
static T_3 F_58 ( int V_134 , void * V_135 )
{
struct V_4 * V_5 = V_135 ;
struct V_84 * V_63 = V_5 -> V_94 ;
struct V_120 * V_121 , * V_136 ;
unsigned int V_34 ;
unsigned long V_90 ;
bool V_137 ;
T_4 V_138 = 0 ;
F_40 ( ! V_63 ) ;
V_34 = F_55 ( V_5 ) ;
if ( V_34 & V_100 )
return V_139 ;
F_32 ( & V_63 -> V_87 . V_140 , V_90 ) ;
F_59 (vd, tmp, &chan->vc.desc_issued, node) {
V_137 = F_48 ( V_121 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_37 ,
V_97 , V_121 , V_121 -> V_141 . V_142 , V_137 ,
V_34 ) ;
V_138 = V_121 -> V_141 . V_142 ;
if ( F_49 ( V_121 ) -> V_119 ) {
F_60 ( V_121 ) ;
break;
}
if ( V_137 ) {
F_61 ( & V_121 -> V_131 ) ;
F_62 ( V_121 ) ;
} else {
break;
}
}
if ( V_34 & V_105 ) {
V_63 -> V_107 = V_138 ;
F_44 ( V_5 ) ;
}
if ( ! V_63 -> V_107 && V_34 & V_143 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_38 ,
V_97 ,
F_53 ( & V_63 -> V_87 . V_144 ) ,
F_53 ( & V_63 -> V_87 . V_129 ) ) ;
F_42 ( V_5 , V_34 & ~ V_103 , V_36 ) ;
if ( F_53 ( & V_63 -> V_87 . V_129 ) ) {
V_63 -> V_102 =
! F_53 ( & V_63 -> V_87 . V_144 ) ;
} else {
V_121 = F_63 ( & V_63 -> V_87 . V_129 ,
struct V_120 , V_131 ) ;
F_45 ( V_63 , F_49 ( V_121 ) ) ;
}
}
F_33 ( & V_63 -> V_87 . V_140 , V_90 ) ;
F_46 ( & V_63 -> V_109 ) ;
return V_145 ;
}
static T_3 F_64 ( int V_134 , void * V_135 )
{
struct V_56 * V_57 = V_135 ;
struct V_4 * V_5 ;
T_1 V_132 = F_56 ( V_57 -> V_10 + V_133 ) ;
int V_7 , V_146 = V_139 ;
while ( V_132 ) {
V_7 = F_65 ( V_132 ) ;
V_132 &= ( V_132 - 1 ) ;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ( V_7 < 32 ) && ( V_93 & F_14 ( V_7 ) ) )
continue;
if ( F_58 ( V_134 , V_5 ) == V_145 )
V_146 = V_145 ;
}
return V_146 ;
}
static int F_66 ( struct V_147 * V_148 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
if ( V_63 -> V_149 )
return 1 ;
V_63 -> V_149 = F_67 ( F_68 ( V_148 ) ,
V_57 -> V_74 . V_75 ,
sizeof( struct V_20 ) ,
F_69 ( struct V_20 ) ,
0 ) ;
if ( ! V_63 -> V_149 ) {
F_70 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_39 ,
V_97 ) ;
return - V_150 ;
}
return 1 ;
}
static void F_71 ( struct V_147 * V_148 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
F_72 ( & V_63 -> V_87 ) ;
F_73 ( V_63 -> V_149 ) ;
V_63 -> V_149 = NULL ;
}
static void F_74 ( struct V_120 * V_121 )
{
int V_7 ;
T_2 V_114 ;
struct V_106 * V_110 = F_49 ( V_121 ) ;
F_40 ( V_110 -> V_113 == 0 ) ;
for ( V_7 = V_110 -> V_113 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 )
V_114 = V_110 -> V_112 [ V_7 - 1 ] -> V_19 ;
else
V_114 = V_110 -> V_108 ;
F_75 ( V_110 -> V_149 ,
V_110 -> V_112 [ V_7 ] , V_114 ) ;
}
V_110 -> V_113 = 0 ;
F_27 ( V_110 ) ;
}
static struct V_106 *
F_76 ( struct V_84 * V_63 , unsigned int V_151 )
{
struct V_106 * V_110 ;
T_2 V_114 ;
int V_7 ;
V_110 = F_77 ( sizeof( * V_110 ) +
V_151 * sizeof( struct V_20 * ) ,
V_152 ) ;
if ( ! V_110 )
return NULL ;
V_110 -> V_149 = V_63 -> V_149 ;
for ( V_7 = 0 ; V_7 < V_151 ; V_7 ++ ) {
V_110 -> V_112 [ V_7 ] = F_78 ( V_110 -> V_149 ,
V_152 , & V_114 ) ;
if ( ! V_110 -> V_112 [ V_7 ] ) {
F_70 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_40 ,
V_97 , V_7 , V_110 -> V_149 ) ;
goto V_153;
}
if ( V_7 == 0 )
V_110 -> V_108 = V_114 ;
else
V_110 -> V_112 [ V_7 - 1 ] -> V_19 = V_114 ;
V_110 -> V_113 ++ ;
}
return V_110 ;
V_153:
F_74 ( & V_110 -> V_121 ) ;
return NULL ;
}
static T_4 F_79 ( struct V_154 * V_141 )
{
struct V_127 * V_87 = F_80 ( V_141 -> V_63 ) ;
struct V_84 * V_63 = F_52 ( & V_87 -> V_63 ) ;
struct V_120 * V_155 = NULL ,
* V_121 = F_81 ( V_141 , struct V_120 , V_141 ) ;
T_4 V_142 ;
unsigned long V_90 ;
F_47 ( F_49 ( V_121 ) , V_141 -> V_90 ) ;
F_32 ( & V_87 -> V_140 , V_90 ) ;
V_142 = F_82 ( V_141 ) ;
if ( F_53 ( & V_87 -> V_144 ) && F_51 ( V_87 , V_121 ) ) {
F_83 ( & V_121 -> V_131 , & V_87 -> V_129 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_41 ,
V_97 , V_121 , V_142 ) ;
goto V_156;
}
if ( ! F_53 ( & V_87 -> V_144 ) ) {
V_155 = F_54 ( V_87 -> V_144 . V_130 ,
struct V_120 , V_131 ) ;
if ( V_63 -> V_102 || ! F_49 ( V_121 ) -> V_102 )
F_50 ( V_155 , V_121 ) ;
else
V_155 = NULL ;
}
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_42 ,
V_97 , V_121 , V_142 , V_155 ? L_43 : L_44 ) ;
F_83 ( & V_121 -> V_131 , & V_87 -> V_144 ) ;
V_63 -> V_102 |= F_49 ( V_121 ) -> V_102 ;
V_156:
F_33 ( & V_87 -> V_140 , V_90 ) ;
return V_142 ;
}
static void F_84 ( struct V_147 * V_148 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
struct V_120 * V_157 ;
unsigned long V_90 ;
F_32 ( & V_63 -> V_87 . V_140 , V_90 ) ;
if ( F_53 ( & V_63 -> V_87 . V_144 ) )
goto V_156;
V_157 = F_63 ( & V_63 -> V_87 . V_144 ,
struct V_120 , V_131 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_45 , V_97 , V_157 , V_157 -> V_141 . V_142 ) ;
F_85 ( & V_63 -> V_87 ) ;
if ( ! F_51 ( & V_63 -> V_87 , V_157 ) )
F_45 ( V_63 , F_49 ( V_157 ) ) ;
V_156:
F_33 ( & V_63 -> V_87 . V_140 , V_90 ) ;
}
static inline struct V_154 *
F_86 ( struct V_127 * V_87 , struct V_120 * V_121 ,
unsigned long V_158 )
{
struct V_154 * V_141 ;
struct V_84 * V_63 = F_81 ( V_87 , struct V_84 , V_87 ) ;
F_87 ( & V_121 -> V_131 ) ;
V_141 = F_88 ( V_87 , V_121 , V_158 ) ;
V_141 -> V_159 = F_79 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_46 , V_97 ,
V_87 , V_121 , V_121 -> V_141 . V_142 ,
V_158 ) ;
return V_141 ;
}
static void F_89 ( struct V_84 * V_63 ,
enum V_160 V_161 ,
T_1 * V_13 , T_1 * V_162 , T_1 * V_163 )
{
T_1 V_164 = 0 , V_165 = 0 ;
enum V_166 V_17 = V_167 ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
* V_13 = 0 ;
if ( V_161 == V_168 ) {
V_164 = V_63 -> V_169 . V_170 ;
V_17 = V_63 -> V_169 . V_171 ;
V_165 = V_63 -> V_169 . V_172 ;
* V_162 = V_165 ;
* V_13 |= V_173 ;
if ( V_63 -> V_8 <= V_57 -> V_99 )
* V_13 |= V_174 ;
}
if ( V_161 == V_175 ) {
V_164 = V_63 -> V_169 . V_176 ;
V_17 = V_63 -> V_169 . V_177 ;
V_165 = V_63 -> V_169 . V_178 ;
* V_163 = V_165 ;
* V_13 |= V_179 ;
if ( V_63 -> V_8 <= V_57 -> V_99 )
* V_13 |= V_180 ;
}
if ( V_161 == V_181 )
* V_13 |= V_116 | V_173 |
V_179 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_47 ,
V_97 , V_165 , V_164 , V_17 , V_161 ) ;
if ( V_17 == V_182 )
* V_13 |= V_183 ;
else if ( V_17 == V_184 )
* V_13 |= V_185 ;
else if ( V_17 == V_186 )
* V_13 |= V_115 ;
if ( V_164 == 8 )
* V_13 |= V_187 ;
else if ( V_164 == 16 )
* V_13 |= V_188 ;
else if ( V_164 == 32 )
* V_13 |= V_116 ;
if ( V_63 -> V_169 . V_189 )
V_63 -> V_8 = V_63 -> V_169 . V_189 ;
}
static struct V_154 *
F_90 ( struct V_147 * V_148 ,
T_2 V_190 , T_2 V_191 ,
T_5 V_192 , unsigned long V_90 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
struct V_106 * V_110 ;
struct V_20 * V_112 ;
T_1 V_13 ;
unsigned int V_7 , V_113 = 0 ;
T_5 V_193 ;
if ( ! V_148 || ! V_192 )
return NULL ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_48 ,
V_97 , ( unsigned long ) V_190 , ( unsigned long ) V_191 ,
V_192 , V_90 ) ;
F_89 ( V_63 , V_181 , & V_13 , NULL , NULL ) ;
V_113 = F_91 ( V_192 , V_194 ) ;
V_110 = F_76 ( V_63 , V_113 + 1 ) ;
if ( ! V_110 )
return NULL ;
V_110 -> V_192 = V_192 ;
if ( ! F_92 ( V_191 , 1 << V_195 ) ||
! F_92 ( V_190 , 1 << V_195 ) )
V_110 -> V_102 = true ;
V_7 = 0 ;
do {
V_112 = V_110 -> V_112 [ V_7 ++ ] ;
V_193 = F_93 ( T_5 , V_192 , V_194 ) ;
V_112 -> V_13 = V_13 | ( V_32 & V_193 ) ;
V_112 -> V_23 = V_191 ;
V_112 -> V_24 = V_190 ;
V_192 -= V_193 ;
V_191 += V_193 ;
V_190 += V_193 ;
} while ( V_192 );
F_47 ( V_110 , V_90 ) ;
return F_86 ( & V_63 -> V_87 , & V_110 -> V_121 , V_90 ) ;
}
static struct V_154 *
F_94 ( struct V_147 * V_148 , struct V_196 * V_197 ,
unsigned int V_198 , enum V_160 V_161 ,
unsigned long V_90 , void * V_199 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
struct V_106 * V_110 ;
T_5 V_192 , V_200 ;
struct V_196 * V_201 ;
T_2 V_114 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_113 = 0 , V_7 , V_202 = 0 ;
if ( ( V_197 == NULL ) || ( V_198 == 0 ) )
return NULL ;
F_89 ( V_63 , V_161 , & V_13 , & V_23 , & V_24 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_49 , V_97 , V_161 , V_90 ) ;
F_95 (sgl, sg, sg_len, i)
V_113 += F_91 ( F_96 ( V_201 ) , V_194 ) ;
V_110 = F_76 ( V_63 , V_113 + 1 ) ;
if ( ! V_110 )
return NULL ;
F_95 (sgl, sg, sg_len, i) {
V_114 = F_97 ( V_201 ) ;
V_200 = F_96 ( V_201 ) ;
V_110 -> V_192 += V_200 ;
do {
V_192 = F_93 ( T_5 , V_200 , V_194 ) ;
if ( V_114 & 0x7 )
V_110 -> V_102 = true ;
V_110 -> V_112 [ V_202 ] -> V_13 =
V_13 | ( V_32 & V_192 ) ;
V_110 -> V_112 [ V_202 ] -> V_23 = V_23 ? V_23 : V_114 ;
V_110 -> V_112 [ V_202 ++ ] -> V_24 = V_24 ? V_24 : V_114 ;
V_114 += V_192 ;
V_200 -= V_192 ;
} while ( V_200 );
}
F_47 ( V_110 , V_90 ) ;
return F_86 ( & V_63 -> V_87 , & V_110 -> V_121 , V_90 ) ;
}
static struct V_154 *
F_98 ( struct V_147 * V_148 ,
T_2 V_203 , T_5 V_192 , T_5 V_204 ,
enum V_160 V_161 , unsigned long V_90 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
struct V_106 * V_110 ;
struct V_20 * * V_205 ;
T_2 V_114 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_113 = 0 ;
if ( ! V_148 || ! V_192 || ! V_204 )
return NULL ;
if ( ( V_161 != V_168 ) && ( V_161 != V_175 ) ) {
F_70 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_50 ) ;
return NULL ;
}
if ( V_192 % V_204 != 0 || V_204 > V_194 ||
! F_92 ( V_204 , 1 << V_195 ) )
return NULL ;
F_89 ( V_63 , V_161 , & V_13 , & V_23 , & V_24 ) ;
V_13 |= V_118 | ( V_32 & V_204 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_51 ,
V_97 , ( unsigned long ) V_203 , V_192 , V_204 , V_161 , V_90 ) ;
V_113 = F_91 ( V_204 , V_194 ) ;
V_113 *= F_91 ( V_192 , V_204 ) ;
V_110 = F_76 ( V_63 , V_113 + 1 ) ;
if ( ! V_110 )
return NULL ;
V_110 -> V_119 = true ;
V_110 -> V_192 = V_192 ;
V_205 = V_110 -> V_112 ;
V_114 = V_203 ;
do {
V_205 [ 0 ] -> V_23 = V_23 ? V_23 : V_114 ;
V_205 [ 0 ] -> V_24 = V_24 ? V_24 : V_114 ;
V_205 [ 0 ] -> V_13 = V_13 ;
V_205 ++ ;
V_114 += V_204 ;
V_192 -= V_204 ;
} while ( V_192 );
F_47 ( V_110 , V_90 ) ;
return F_86 ( & V_63 -> V_87 , & V_110 -> V_121 , V_90 ) ;
}
static int F_99 ( struct V_147 * V_148 ,
struct V_206 * V_169 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
if ( ! V_148 )
return - V_207 ;
V_63 -> V_169 = * V_169 ;
return 0 ;
}
static int F_100 ( struct V_147 * V_148 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
struct V_120 * V_121 = NULL ;
unsigned long V_90 ;
struct V_4 * V_5 ;
F_101 ( V_208 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_52 , V_97 , & V_63 -> V_87 ) ;
F_32 ( & V_63 -> V_87 . V_140 , V_90 ) ;
F_102 ( & V_63 -> V_87 , & V_208 ) ;
F_103 (vd, &head, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_53 , V_97 ,
V_121 , V_121 -> V_141 . V_142 , F_48 ( V_121 ) ) ;
}
V_5 = V_63 -> V_5 ;
if ( V_5 ) {
F_44 ( V_63 -> V_5 ) ;
F_35 ( V_63 ) ;
V_63 -> V_5 = NULL ;
F_104 ( & V_57 -> V_91 ) ;
V_5 -> V_94 = NULL ;
F_105 ( & V_57 -> V_91 ) ;
}
F_33 ( & V_63 -> V_87 . V_140 , V_90 ) ;
F_106 ( & V_63 -> V_87 , & V_208 ) ;
return 0 ;
}
static unsigned int F_107 ( struct V_84 * V_63 ,
T_4 V_142 )
{
struct V_120 * V_121 = NULL ;
struct V_106 * V_110 = NULL ;
struct V_20 * V_112 = NULL ;
T_1 V_209 , V_210 , V_192 , V_211 , V_212 = 0 ;
unsigned long V_90 ;
bool V_213 = false ;
int V_7 ;
if ( ! V_63 -> V_5 )
return 0 ;
F_32 ( & V_63 -> V_87 . V_140 , V_90 ) ;
V_121 = F_108 ( & V_63 -> V_87 , V_142 ) ;
if ( ! V_121 )
goto V_156;
V_110 = F_49 ( V_121 ) ;
if ( V_110 -> V_112 [ 0 ] -> V_13 & V_179 )
V_209 = F_38 ( V_63 -> V_5 , V_54 ) ;
else
V_209 = F_38 ( V_63 -> V_5 , V_55 ) ;
F_109 () ;
if ( F_48 ( V_121 ) )
goto V_156;
for ( V_7 = 0 ; V_7 < V_110 -> V_113 - 1 ; V_7 ++ ) {
V_112 = V_110 -> V_112 [ V_7 ] ;
if ( V_110 -> V_112 [ 0 ] -> V_13 & V_179 )
V_210 = V_112 -> V_23 ;
else
V_210 = V_112 -> V_24 ;
V_192 = V_112 -> V_13 & V_32 ;
V_211 = V_210 + V_192 ;
if ( V_213 ) {
V_212 += V_192 ;
} else if ( V_209 >= V_210 && V_209 <= V_211 ) {
V_212 += V_211 - V_209 ;
V_213 = true ;
}
}
if ( ! V_213 )
V_212 = V_110 -> V_192 ;
V_156:
F_33 ( & V_63 -> V_87 . V_140 , V_90 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_54 ,
V_97 , V_121 , V_142 , V_110 , V_212 ) ;
return V_212 ;
}
static enum V_214 F_110 ( struct V_147 * V_148 ,
T_4 V_142 ,
struct V_215 * V_216 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
enum V_214 V_146 ;
if ( V_142 == V_63 -> V_107 )
return V_217 ;
V_146 = F_111 ( V_148 , V_142 , V_216 ) ;
if ( F_112 ( V_216 && ( V_146 != V_217 ) ) )
F_113 ( V_216 , F_107 ( V_63 , V_142 ) ) ;
return V_146 ;
}
static void F_114 ( struct V_147 * V_148 )
{
struct V_84 * V_63 = F_52 ( V_148 ) ;
F_115 ( V_63 -> V_109 , ! F_37 ( V_63 ) ) ;
F_116 ( & V_63 -> V_87 ) ;
}
static void F_117 ( struct V_218 * V_219 )
{
struct V_84 * V_220 , * V_221 ;
F_59 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_61 ( & V_220 -> V_87 . V_63 . V_222 ) ;
F_118 ( & V_220 -> V_87 . V_223 ) ;
}
}
static int F_119 ( struct V_224 * V_225 )
{
struct V_56 * V_57 = F_120 ( V_225 ) ;
F_29 ( V_57 ) ;
F_117 ( & V_57 -> V_74 ) ;
F_121 ( & V_57 -> V_74 ) ;
return 0 ;
}
static int F_122 ( struct V_224 * V_225 ,
struct V_56 * V_57 ,
unsigned int V_226 )
{
int V_227 , V_134 , V_228 = 0 , V_7 , V_146 ;
struct V_4 * V_5 ;
V_227 = F_123 ( V_225 , 0 ) ;
if ( V_227 < 0 )
return V_227 ;
V_57 -> V_68 = F_124 ( & V_225 -> V_75 , V_226 ,
sizeof( V_57 -> V_68 [ 0 ] ) , V_80 ) ;
if ( ! V_57 -> V_68 )
return - V_150 ;
for ( V_7 = 0 ; V_7 < V_226 ; V_7 ++ )
if ( F_123 ( V_225 , V_7 ) > 0 )
V_228 ++ ;
for ( V_7 = 0 ; V_7 < V_226 ; V_7 ++ ) {
V_5 = & V_57 -> V_68 [ V_7 ] ;
V_5 -> V_10 = V_57 -> V_10 ;
V_5 -> V_9 = V_7 ;
V_134 = F_123 ( V_225 , V_7 ) ;
if ( ( V_228 > 1 ) && ( V_134 > 0 ) )
V_146 = F_125 ( & V_225 -> V_75 , V_134 ,
F_58 ,
V_229 , L_55 , V_5 ) ;
if ( ( V_228 == 1 ) && ( V_7 == 0 ) )
V_146 = F_125 ( & V_225 -> V_75 , V_227 ,
F_64 ,
V_229 , L_55 , V_57 ) ;
if ( V_146 ) {
F_70 ( V_57 -> V_74 . V_75 ,
L_56 , V_97 ,
V_134 , V_146 ) ;
return V_146 ;
}
}
return 0 ;
}
static struct V_147 * F_126 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
struct V_56 * V_234 = V_233 -> V_235 ;
struct V_147 * V_63 ;
V_63 = F_127 ( & V_234 -> V_74 ) ;
if ( ! V_63 )
return NULL ;
F_52 ( V_63 ) -> V_8 = V_231 -> args [ 0 ] ;
F_52 ( V_63 ) -> V_86 = V_231 -> args [ 1 ] ;
return V_63 ;
}
static int F_128 ( struct V_224 * V_225 ,
struct V_56 * V_57 ,
unsigned int V_236 ,
unsigned int V_99 )
{
int V_146 ;
unsigned int V_7 ;
struct V_84 * V_220 ;
V_57 -> V_58 = V_236 ;
V_57 -> V_99 = V_99 ;
F_87 ( & V_57 -> V_74 . V_237 ) ;
V_57 -> V_74 . V_238 = F_66 ;
V_57 -> V_74 . V_239 = F_71 ;
V_57 -> V_74 . V_240 = F_110 ;
V_57 -> V_74 . V_241 = F_84 ;
V_57 -> V_74 . V_242 = F_99 ;
V_57 -> V_74 . V_243 = F_114 ;
V_57 -> V_74 . V_244 = F_100 ;
if ( V_225 -> V_75 . V_245 )
F_129 ( & V_225 -> V_75 , V_225 -> V_75 . V_245 ) ;
else
F_129 ( & V_225 -> V_75 , F_130 ( 32 ) ) ;
V_146 = F_122 ( V_225 , V_57 , V_236 ) ;
if ( V_146 )
return V_146 ;
for ( V_7 = 0 ; V_7 < V_236 ; V_7 ++ ) {
V_220 = F_131 ( & V_225 -> V_75 , sizeof( * V_220 ) , V_80 ) ;
if ( ! V_220 )
return - V_150 ;
V_220 -> V_87 . V_246 = F_74 ;
F_132 ( & V_220 -> V_87 , & V_57 -> V_74 ) ;
F_133 ( & V_220 -> V_109 ) ;
}
return F_134 ( & V_57 -> V_74 ) ;
}
static int F_135 ( struct V_224 * V_225 )
{
struct V_56 * V_57 ;
const struct V_247 * V_248 ;
struct V_249 * V_250 = F_136 ( & V_225 -> V_75 ) ;
struct V_251 * V_252 ;
int V_146 , V_253 = 0 , V_254 = 0 ;
const enum V_166 V_255 =
V_182 | V_184 |
V_186 ;
V_57 = F_131 ( & V_225 -> V_75 , sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return - V_150 ;
F_137 ( & V_57 -> V_91 ) ;
V_252 = F_138 ( V_225 , V_256 , 0 ) ;
V_57 -> V_10 = F_139 ( & V_225 -> V_75 , V_252 ) ;
if ( F_25 ( V_57 -> V_10 ) )
return F_140 ( V_57 -> V_10 ) ;
V_248 = F_141 ( V_257 , & V_225 -> V_75 ) ;
if ( V_248 ) {
F_142 ( V_225 -> V_75 . V_258 , L_57 ,
& V_253 ) ;
V_146 = F_142 ( V_225 -> V_75 . V_258 , L_58 ,
& V_254 ) ;
if ( V_146 ) {
F_57 ( V_57 -> V_74 . V_75 ,
L_59 ,
V_146 ) ;
V_254 = 32 ;
} ;
} else if ( V_250 && V_250 -> V_253 ) {
V_253 = V_250 -> V_253 ;
V_254 = V_250 -> V_254 ;
} else {
V_253 = 32 ;
}
F_143 ( V_259 , V_57 -> V_74 . V_260 ) ;
F_143 ( V_261 , V_57 -> V_74 . V_260 ) ;
F_143 ( V_262 , V_57 -> V_74 . V_260 ) ;
F_143 ( V_263 , V_57 -> V_74 . V_260 ) ;
V_57 -> V_74 . V_264 = F_90 ;
V_57 -> V_74 . V_265 = F_94 ;
V_57 -> V_74 . V_266 = F_98 ;
V_57 -> V_74 . V_267 = V_195 ;
V_57 -> V_74 . V_268 = V_255 ;
V_57 -> V_74 . V_269 = V_255 ;
V_57 -> V_74 . V_270 = F_14 ( V_175 ) | F_14 ( V_168 ) ;
V_57 -> V_74 . V_271 = V_272 ;
V_57 -> V_74 . V_273 = true ;
V_57 -> V_74 . V_75 = & V_225 -> V_75 ;
V_146 = F_128 ( V_225 , V_57 , V_253 , V_254 ) ;
if ( V_146 ) {
F_70 ( V_57 -> V_74 . V_75 , L_60 ) ;
return V_146 ;
}
if ( V_225 -> V_75 . V_258 ) {
V_146 = F_144 ( V_225 -> V_75 . V_258 ,
F_126 , V_57 ) ;
if ( V_146 < 0 ) {
F_70 ( V_57 -> V_74 . V_75 ,
L_61 ) ;
return V_146 ;
}
}
F_145 ( V_225 , V_57 ) ;
F_23 ( V_57 ) ;
F_146 ( V_57 -> V_74 . V_75 , L_62 ,
V_253 , V_254 ) ;
return 0 ;
}
bool F_147 ( struct V_147 * V_63 , void * V_274 )
{
struct V_84 * V_220 = F_52 ( V_63 ) ;
struct V_275 * V_3 = V_274 ;
if ( V_63 -> V_88 -> V_75 -> V_276 != & V_277 . V_276 )
return false ;
V_220 -> V_8 = V_3 -> V_8 ;
V_220 -> V_86 = V_3 -> V_86 ;
return true ;
}
int F_148 ( int V_278 )
{
if ( V_95 & ( F_14 ( V_278 ) ) )
return - V_279 ;
V_93 ^= F_14 ( V_278 ) ;
return 0 ;
}
