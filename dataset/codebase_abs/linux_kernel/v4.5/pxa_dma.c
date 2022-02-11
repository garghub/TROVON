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
if ( V_63 -> V_8 <= V_11 ) {
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
return V_34 & V_99 ;
}
static bool F_39 ( struct V_84 * V_63 )
{
T_1 V_100 ;
F_40 ( ! V_63 -> V_5 ) ;
V_100 = F_38 ( V_63 -> V_5 , V_38 ) ;
return V_100 & ( F_14 ( V_63 -> V_5 -> V_9 ) ) ;
}
static void F_41 ( struct V_4 * V_5 , bool V_101 )
{
T_1 V_98 , V_100 ;
if ( ! V_5 -> V_94 )
return;
F_34 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_33 , V_97 ,
V_5 , V_5 -> V_9 , V_101 ) ;
if ( V_5 -> V_94 -> V_8 <= V_11 ) {
V_98 = F_1 ( V_5 -> V_94 -> V_8 ) ;
F_36 ( V_12 | V_5 -> V_9 , V_5 -> V_10 + V_98 ) ;
}
V_100 = F_38 ( V_5 , V_38 ) ;
if ( V_101 )
V_100 |= F_14 ( V_5 -> V_9 ) ;
else
V_100 &= ~ F_14 ( V_5 -> V_9 ) ;
F_42 ( V_5 , V_100 , V_38 ) ;
F_43 ( V_5 , V_102 | V_103 |
V_104 | V_99 , V_36 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
T_1 V_34 ;
if ( ! V_5 )
return;
V_34 = F_38 ( V_5 , V_36 ) ;
F_34 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_31 , V_97 , V_5 , V_5 -> V_9 ) ;
F_43 ( V_5 , V_34 & ~ V_99 & ~ V_102 , V_36 ) ;
}
static void F_45 ( struct V_84 * V_63 ,
struct V_105 * V_21 )
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
F_43 ( V_63 -> V_5 , V_21 -> V_106 , V_22 ) ;
F_41 ( V_63 -> V_5 , V_63 -> V_101 ) ;
}
static void F_46 ( struct V_105 * V_107 ,
unsigned long V_90 )
{
struct V_20 * V_108 =
V_107 -> V_109 [ V_107 -> V_110 - 1 ] ;
T_2 V_111 = V_107 -> V_109 [ V_107 -> V_110 - 2 ] -> V_19 ;
V_108 -> V_19 = V_33 ;
V_108 -> V_23 = V_111 ;
V_108 -> V_24 = V_111 + 8 ;
V_108 -> V_13 = V_112 | V_113 |
( V_32 & sizeof( T_1 ) ) ;
if ( V_90 & V_114 )
V_108 -> V_13 |= V_115 ;
if ( V_107 -> V_116 )
V_107 -> V_109 [ V_107 -> V_110 - 2 ] -> V_19 = V_107 -> V_106 ;
}
static bool F_47 ( struct V_117 * V_118 )
{
struct V_105 * V_107 = F_48 ( V_118 ) ;
struct V_20 * V_108 =
V_107 -> V_109 [ V_107 -> V_110 - 1 ] ;
return V_108 -> V_24 != ( V_108 -> V_23 + 8 ) ;
}
static void F_49 ( struct V_117 * V_119 ,
struct V_117 * V_120 )
{
struct V_105 * V_121 = F_48 ( V_119 ) ;
struct V_105 * V_122 = F_48 ( V_120 ) ;
T_2 V_123 ;
V_123 = V_122 -> V_106 ;
V_121 -> V_109 [ V_121 -> V_110 - 1 ] -> V_19 = V_123 ;
}
static bool F_50 ( struct V_124 * V_87 ,
struct V_117 * V_118 )
{
struct V_117 * V_125 = NULL ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
if ( F_37 ( V_63 ) ) {
F_40 ( F_52 ( & V_87 -> V_126 ) ) ;
if ( ! F_39 ( V_63 ) &&
F_48 ( V_118 ) -> V_101 )
return false ;
V_125 = F_53 ( V_87 -> V_126 . V_127 ,
struct V_117 , V_128 ) ;
F_49 ( V_125 , V_118 ) ;
if ( F_37 ( V_63 ) || F_47 ( V_125 ) )
return true ;
}
return false ;
}
static unsigned int F_54 ( struct V_4 * V_5 )
{
T_1 V_34 ;
T_1 V_129 = F_55 ( V_5 -> V_10 + V_130 ) ;
if ( ! ( V_129 & F_14 ( V_5 -> V_9 ) ) )
return V_99 ;
V_34 = F_38 ( V_5 , V_36 ) ;
F_43 ( V_5 , V_34 , V_36 ) ;
if ( ( V_34 & V_104 ) && ( V_5 -> V_94 ) )
F_56 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_36 ,
V_97 , & V_5 -> V_94 ) ;
return V_34 & ~ V_99 ;
}
static T_3 F_57 ( int V_131 , void * V_132 )
{
struct V_4 * V_5 = V_132 ;
struct V_84 * V_63 = V_5 -> V_94 ;
struct V_117 * V_118 , * V_133 ;
unsigned int V_34 ;
unsigned long V_90 ;
F_40 ( ! V_63 ) ;
V_34 = F_54 ( V_5 ) ;
if ( V_34 & V_99 )
return V_134 ;
F_32 ( & V_63 -> V_87 . V_135 , V_90 ) ;
F_58 (vd, tmp, &chan->vc.desc_issued, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_37 ,
V_97 , V_118 , V_118 -> V_136 . V_137 , F_47 ( V_118 ) ) ;
if ( F_48 ( V_118 ) -> V_116 ) {
F_59 ( V_118 ) ;
break;
}
if ( F_47 ( V_118 ) ) {
F_60 ( & V_118 -> V_128 ) ;
F_61 ( V_118 ) ;
} else {
break;
}
}
if ( V_34 & V_138 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_38 ,
V_97 ,
F_52 ( & V_63 -> V_87 . V_139 ) ,
F_52 ( & V_63 -> V_87 . V_126 ) ) ;
F_42 ( V_5 , V_34 & ~ V_102 , V_36 ) ;
if ( F_52 ( & V_63 -> V_87 . V_126 ) ) {
V_63 -> V_101 =
! F_52 ( & V_63 -> V_87 . V_139 ) ;
} else {
V_118 = F_62 ( & V_63 -> V_87 . V_126 ,
struct V_117 , V_128 ) ;
F_45 ( V_63 , F_48 ( V_118 ) ) ;
}
}
F_33 ( & V_63 -> V_87 . V_135 , V_90 ) ;
return V_140 ;
}
static T_3 F_63 ( int V_131 , void * V_132 )
{
struct V_56 * V_57 = V_132 ;
struct V_4 * V_5 ;
T_1 V_129 = F_55 ( V_57 -> V_10 + V_130 ) ;
int V_7 , V_141 = V_134 ;
while ( V_129 ) {
V_7 = F_64 ( V_129 ) ;
V_129 &= ( V_129 - 1 ) ;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ( V_7 < 32 ) && ( V_93 & F_14 ( V_7 ) ) )
continue;
if ( F_57 ( V_131 , V_5 ) == V_140 )
V_141 = V_140 ;
}
return V_141 ;
}
static int F_65 ( struct V_142 * V_143 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
if ( V_63 -> V_144 )
return 1 ;
V_63 -> V_144 = F_66 ( F_67 ( V_143 ) ,
V_57 -> V_74 . V_75 ,
sizeof( struct V_20 ) ,
F_68 ( struct V_20 ) ,
0 ) ;
if ( ! V_63 -> V_144 ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_39 ,
V_97 ) ;
return - V_145 ;
}
return 1 ;
}
static void F_70 ( struct V_142 * V_143 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
F_71 ( & V_63 -> V_87 ) ;
F_72 ( V_63 -> V_144 ) ;
V_63 -> V_144 = NULL ;
}
static void F_73 ( struct V_117 * V_118 )
{
int V_7 ;
T_2 V_111 ;
struct V_105 * V_107 = F_48 ( V_118 ) ;
F_40 ( V_107 -> V_110 == 0 ) ;
for ( V_7 = V_107 -> V_110 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 )
V_111 = V_107 -> V_109 [ V_7 - 1 ] -> V_19 ;
else
V_111 = V_107 -> V_106 ;
F_74 ( V_107 -> V_144 ,
V_107 -> V_109 [ V_7 ] , V_111 ) ;
}
V_107 -> V_110 = 0 ;
F_27 ( V_107 ) ;
}
static struct V_105 *
F_75 ( struct V_84 * V_63 , unsigned int V_146 )
{
struct V_105 * V_107 ;
T_2 V_111 ;
int V_7 ;
V_107 = F_76 ( sizeof( * V_107 ) +
V_146 * sizeof( struct V_20 * ) ,
V_147 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_144 = V_63 -> V_144 ;
for ( V_7 = 0 ; V_7 < V_146 ; V_7 ++ ) {
V_107 -> V_109 [ V_7 ] = F_77 ( V_107 -> V_144 ,
V_147 , & V_111 ) ;
if ( ! V_107 -> V_109 [ V_7 ] ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_40 ,
V_97 , V_7 , V_107 -> V_144 ) ;
goto V_148;
}
if ( V_7 == 0 )
V_107 -> V_106 = V_111 ;
else
V_107 -> V_109 [ V_7 - 1 ] -> V_19 = V_111 ;
V_107 -> V_110 ++ ;
}
return V_107 ;
V_148:
F_73 ( & V_107 -> V_118 ) ;
return NULL ;
}
static T_4 F_78 ( struct V_149 * V_136 )
{
struct V_124 * V_87 = F_79 ( V_136 -> V_63 ) ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
struct V_117 * V_150 = NULL ,
* V_118 = F_80 ( V_136 , struct V_117 , V_136 ) ;
T_4 V_137 ;
unsigned long V_90 ;
F_46 ( F_48 ( V_118 ) , V_136 -> V_90 ) ;
F_32 ( & V_87 -> V_135 , V_90 ) ;
V_137 = F_81 ( V_136 ) ;
if ( F_52 ( & V_87 -> V_139 ) && F_50 ( V_87 , V_118 ) ) {
F_82 ( & V_118 -> V_128 , & V_87 -> V_126 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_41 ,
V_97 , V_118 , V_137 ) ;
goto V_151;
}
if ( ! F_52 ( & V_87 -> V_139 ) ) {
V_150 = F_53 ( V_87 -> V_139 . V_127 ,
struct V_117 , V_128 ) ;
if ( V_63 -> V_101 || ! F_48 ( V_118 ) -> V_101 )
F_49 ( V_150 , V_118 ) ;
else
V_150 = NULL ;
}
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_42 ,
V_97 , V_118 , V_137 , V_150 ? L_43 : L_44 ) ;
F_82 ( & V_118 -> V_128 , & V_87 -> V_139 ) ;
V_63 -> V_101 |= F_48 ( V_118 ) -> V_101 ;
V_151:
F_33 ( & V_87 -> V_135 , V_90 ) ;
return V_137 ;
}
static void F_83 ( struct V_142 * V_143 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
struct V_117 * V_152 ;
unsigned long V_90 ;
F_32 ( & V_63 -> V_87 . V_135 , V_90 ) ;
if ( F_52 ( & V_63 -> V_87 . V_139 ) )
goto V_151;
V_152 = F_62 ( & V_63 -> V_87 . V_139 ,
struct V_117 , V_128 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_45 , V_97 , V_152 , V_152 -> V_136 . V_137 ) ;
F_84 ( & V_63 -> V_87 ) ;
if ( ! F_50 ( & V_63 -> V_87 , V_152 ) )
F_45 ( V_63 , F_48 ( V_152 ) ) ;
V_151:
F_33 ( & V_63 -> V_87 . V_135 , V_90 ) ;
}
static inline struct V_149 *
F_85 ( struct V_124 * V_87 , struct V_117 * V_118 ,
unsigned long V_153 )
{
struct V_149 * V_136 ;
struct V_84 * V_63 = F_80 ( V_87 , struct V_84 , V_87 ) ;
F_86 ( & V_118 -> V_128 ) ;
V_136 = F_87 ( V_87 , V_118 , V_153 ) ;
V_136 -> V_154 = F_78 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_46 , V_97 ,
V_87 , V_118 , V_118 -> V_136 . V_137 ,
V_153 ) ;
return V_136 ;
}
static void F_88 ( struct V_84 * V_63 ,
enum V_155 V_156 ,
T_1 * V_13 , T_1 * V_157 , T_1 * V_158 )
{
T_1 V_159 = 0 , V_160 = 0 ;
enum V_161 V_17 = V_162 ;
* V_13 = 0 ;
if ( V_156 == V_163 ) {
V_159 = V_63 -> V_164 . V_165 ;
V_17 = V_63 -> V_164 . V_166 ;
V_160 = V_63 -> V_164 . V_167 ;
* V_157 = V_160 ;
* V_13 |= V_168 ;
if ( V_63 -> V_8 <= V_11 )
* V_13 |= V_169 ;
}
if ( V_156 == V_170 ) {
V_159 = V_63 -> V_164 . V_171 ;
V_17 = V_63 -> V_164 . V_172 ;
V_160 = V_63 -> V_164 . V_173 ;
* V_158 = V_160 ;
* V_13 |= V_174 ;
if ( V_63 -> V_8 <= V_11 )
* V_13 |= V_175 ;
}
if ( V_156 == V_176 )
* V_13 |= V_113 | V_168 |
V_174 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_47 ,
V_97 , V_160 , V_159 , V_17 , V_156 ) ;
if ( V_17 == V_177 )
* V_13 |= V_178 ;
else if ( V_17 == V_179 )
* V_13 |= V_180 ;
else if ( V_17 == V_181 )
* V_13 |= V_112 ;
if ( V_159 == 8 )
* V_13 |= V_182 ;
else if ( V_159 == 16 )
* V_13 |= V_183 ;
else if ( V_159 == 32 )
* V_13 |= V_113 ;
if ( V_63 -> V_164 . V_184 )
V_63 -> V_8 = V_63 -> V_164 . V_184 ;
}
static struct V_149 *
F_89 ( struct V_142 * V_143 ,
T_2 V_185 , T_2 V_186 ,
T_5 V_187 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
struct V_105 * V_107 ;
struct V_20 * V_109 ;
T_1 V_13 ;
unsigned int V_7 , V_110 = 0 ;
T_5 V_188 ;
if ( ! V_143 || ! V_187 )
return NULL ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_48 ,
V_97 , ( unsigned long ) V_185 , ( unsigned long ) V_186 ,
V_187 , V_90 ) ;
F_88 ( V_63 , V_176 , & V_13 , NULL , NULL ) ;
V_110 = F_90 ( V_187 , V_189 ) ;
V_107 = F_75 ( V_63 , V_110 + 1 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_187 = V_187 ;
if ( ! F_91 ( V_186 , 1 << V_190 ) ||
! F_91 ( V_185 , 1 << V_190 ) )
V_107 -> V_101 = true ;
V_7 = 0 ;
do {
V_109 = V_107 -> V_109 [ V_7 ++ ] ;
V_188 = F_92 ( T_5 , V_187 , V_189 ) ;
V_109 -> V_13 = V_13 | ( V_32 & V_188 ) ;
V_109 -> V_23 = V_186 ;
V_109 -> V_24 = V_185 ;
V_187 -= V_188 ;
V_186 += V_188 ;
V_185 += V_188 ;
} while ( V_187 );
F_46 ( V_107 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_107 -> V_118 , V_90 ) ;
}
static struct V_149 *
F_93 ( struct V_142 * V_143 , struct V_191 * V_192 ,
unsigned int V_193 , enum V_155 V_156 ,
unsigned long V_90 , void * V_194 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
struct V_105 * V_107 ;
T_5 V_187 , V_195 ;
struct V_191 * V_196 ;
T_2 V_111 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_110 = 0 , V_7 , V_197 = 0 ;
if ( ( V_192 == NULL ) || ( V_193 == 0 ) )
return NULL ;
F_88 ( V_63 , V_156 , & V_13 , & V_23 , & V_24 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_49 , V_97 , V_156 , V_90 ) ;
F_94 (sgl, sg, sg_len, i)
V_110 += F_90 ( F_95 ( V_196 ) , V_189 ) ;
V_107 = F_75 ( V_63 , V_110 + 1 ) ;
if ( ! V_107 )
return NULL ;
F_94 (sgl, sg, sg_len, i) {
V_111 = F_96 ( V_196 ) ;
V_195 = F_95 ( V_196 ) ;
V_107 -> V_187 += V_195 ;
do {
V_187 = F_92 ( T_5 , V_195 , V_189 ) ;
if ( V_111 & 0x7 )
V_107 -> V_101 = true ;
V_107 -> V_109 [ V_197 ] -> V_13 =
V_13 | ( V_32 & V_187 ) ;
V_107 -> V_109 [ V_197 ] -> V_23 = V_23 ? V_23 : V_111 ;
V_107 -> V_109 [ V_197 ++ ] -> V_24 = V_24 ? V_24 : V_111 ;
V_111 += V_187 ;
V_195 -= V_187 ;
} while ( V_195 );
}
F_46 ( V_107 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_107 -> V_118 , V_90 ) ;
}
static struct V_149 *
F_97 ( struct V_142 * V_143 ,
T_2 V_198 , T_5 V_187 , T_5 V_199 ,
enum V_155 V_156 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
struct V_105 * V_107 ;
struct V_20 * * V_200 ;
T_2 V_111 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_110 = 0 ;
if ( ! V_143 || ! V_187 || ! V_199 )
return NULL ;
if ( ( V_156 != V_163 ) && ( V_156 != V_170 ) ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_50 ) ;
return NULL ;
}
if ( V_187 % V_199 != 0 || V_199 > V_189 ||
! F_91 ( V_199 , 1 << V_190 ) )
return NULL ;
F_88 ( V_63 , V_156 , & V_13 , & V_23 , & V_24 ) ;
V_13 |= V_115 | ( V_32 & V_199 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_51 ,
V_97 , ( unsigned long ) V_198 , V_187 , V_199 , V_156 , V_90 ) ;
V_110 = F_90 ( V_199 , V_189 ) ;
V_110 *= F_90 ( V_187 , V_199 ) ;
V_107 = F_75 ( V_63 , V_110 + 1 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_116 = true ;
V_107 -> V_187 = V_187 ;
V_200 = V_107 -> V_109 ;
V_111 = V_198 ;
do {
V_200 [ 0 ] -> V_23 = V_23 ? V_23 : V_111 ;
V_200 [ 0 ] -> V_24 = V_24 ? V_24 : V_111 ;
V_200 [ 0 ] -> V_13 = V_13 ;
V_200 ++ ;
V_111 += V_199 ;
V_187 -= V_199 ;
} while ( V_187 );
F_46 ( V_107 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_107 -> V_118 , V_90 ) ;
}
static int F_98 ( struct V_142 * V_143 ,
struct V_201 * V_164 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
if ( ! V_143 )
return - V_202 ;
V_63 -> V_164 = * V_164 ;
return 0 ;
}
static int F_99 ( struct V_142 * V_143 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
struct V_117 * V_118 = NULL ;
unsigned long V_90 ;
struct V_4 * V_5 ;
F_100 ( V_203 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_52 , V_97 , & V_63 -> V_87 ) ;
F_32 ( & V_63 -> V_87 . V_135 , V_90 ) ;
F_101 ( & V_63 -> V_87 , & V_203 ) ;
F_102 (vd, &head, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_53 , V_97 ,
V_118 , V_118 -> V_136 . V_137 , F_47 ( V_118 ) ) ;
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
F_33 ( & V_63 -> V_87 . V_135 , V_90 ) ;
F_105 ( & V_63 -> V_87 , & V_203 ) ;
return 0 ;
}
static unsigned int F_106 ( struct V_84 * V_63 ,
T_4 V_137 )
{
struct V_117 * V_118 = NULL ;
struct V_105 * V_107 = NULL ;
struct V_20 * V_109 = NULL ;
T_1 V_204 , V_205 , V_187 , V_206 , V_207 = 0 ;
unsigned long V_90 ;
bool V_208 = false ;
int V_7 ;
if ( ! V_63 -> V_5 )
return 0 ;
F_32 ( & V_63 -> V_87 . V_135 , V_90 ) ;
V_118 = F_107 ( & V_63 -> V_87 , V_137 ) ;
if ( ! V_118 )
goto V_151;
V_107 = F_48 ( V_118 ) ;
if ( V_107 -> V_109 [ 0 ] -> V_13 & V_174 )
V_204 = F_38 ( V_63 -> V_5 , V_54 ) ;
else
V_204 = F_38 ( V_63 -> V_5 , V_55 ) ;
F_108 () ;
if ( F_47 ( V_118 ) )
goto V_151;
for ( V_7 = 0 ; V_7 < V_107 -> V_110 - 1 ; V_7 ++ ) {
V_109 = V_107 -> V_109 [ V_7 ] ;
if ( V_107 -> V_109 [ 0 ] -> V_13 & V_174 )
V_205 = V_109 -> V_23 ;
else
V_205 = V_109 -> V_24 ;
V_187 = V_109 -> V_13 & V_32 ;
V_206 = V_205 + V_187 ;
if ( V_208 ) {
V_207 += V_187 ;
} else if ( V_204 >= V_205 && V_204 <= V_206 ) {
V_207 += V_206 - V_204 ;
V_208 = true ;
}
}
if ( ! V_208 )
V_207 = V_107 -> V_187 ;
V_151:
F_33 ( & V_63 -> V_87 . V_135 , V_90 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_54 ,
V_97 , V_118 , V_137 , V_107 , V_207 ) ;
return V_207 ;
}
static enum V_209 F_109 ( struct V_142 * V_143 ,
T_4 V_137 ,
struct V_210 * V_211 )
{
struct V_84 * V_63 = F_51 ( V_143 ) ;
enum V_209 V_141 ;
V_141 = F_110 ( V_143 , V_137 , V_211 ) ;
if ( F_111 ( V_211 && ( V_141 != V_212 ) ) )
F_112 ( V_211 , F_106 ( V_63 , V_137 ) ) ;
return V_141 ;
}
static void F_113 ( struct V_213 * V_214 )
{
struct V_84 * V_215 , * V_216 ;
F_58 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_60 ( & V_215 -> V_87 . V_63 . V_217 ) ;
F_114 ( & V_215 -> V_87 . V_218 ) ;
}
}
static int F_115 ( struct V_219 * V_220 )
{
struct V_56 * V_57 = F_116 ( V_220 ) ;
F_29 ( V_57 ) ;
F_113 ( & V_57 -> V_74 ) ;
F_117 ( & V_57 -> V_74 ) ;
return 0 ;
}
static int F_118 ( struct V_219 * V_220 ,
struct V_56 * V_57 ,
unsigned int V_221 )
{
int V_222 , V_131 , V_223 = 0 , V_7 , V_141 ;
struct V_4 * V_5 ;
V_222 = F_119 ( V_220 , 0 ) ;
if ( V_222 < 0 )
return V_222 ;
V_57 -> V_68 = F_120 ( & V_220 -> V_75 , V_221 ,
sizeof( V_57 -> V_68 [ 0 ] ) , V_80 ) ;
if ( ! V_57 -> V_68 )
return - V_145 ;
for ( V_7 = 0 ; V_7 < V_221 ; V_7 ++ )
if ( F_119 ( V_220 , V_7 ) > 0 )
V_223 ++ ;
for ( V_7 = 0 ; V_7 < V_221 ; V_7 ++ ) {
V_5 = & V_57 -> V_68 [ V_7 ] ;
V_5 -> V_10 = V_57 -> V_10 ;
V_5 -> V_9 = V_7 ;
V_131 = F_119 ( V_220 , V_7 ) ;
if ( ( V_223 > 1 ) && ( V_131 > 0 ) )
V_141 = F_121 ( & V_220 -> V_75 , V_131 ,
F_57 ,
V_224 , L_55 , V_5 ) ;
if ( ( V_223 == 1 ) && ( V_7 == 0 ) )
V_141 = F_121 ( & V_220 -> V_75 , V_222 ,
F_63 ,
V_224 , L_55 , V_57 ) ;
if ( V_141 ) {
F_69 ( V_57 -> V_74 . V_75 ,
L_56 , V_97 ,
V_131 , V_141 ) ;
return V_141 ;
}
}
return 0 ;
}
static struct V_142 * F_122 ( struct V_225 * V_226 ,
struct V_227 * V_228 )
{
struct V_56 * V_229 = V_228 -> V_230 ;
struct V_142 * V_63 ;
V_63 = F_123 ( & V_229 -> V_74 ) ;
if ( ! V_63 )
return NULL ;
F_51 ( V_63 ) -> V_8 = V_226 -> args [ 0 ] ;
F_51 ( V_63 ) -> V_86 = V_226 -> args [ 1 ] ;
return V_63 ;
}
static int F_124 ( struct V_219 * V_220 ,
struct V_56 * V_57 ,
unsigned int V_231 )
{
int V_141 ;
unsigned int V_7 ;
struct V_84 * V_215 ;
V_57 -> V_58 = V_231 ;
F_86 ( & V_57 -> V_74 . V_232 ) ;
V_57 -> V_74 . V_233 = F_65 ;
V_57 -> V_74 . V_234 = F_70 ;
V_57 -> V_74 . V_235 = F_109 ;
V_57 -> V_74 . V_236 = F_83 ;
V_57 -> V_74 . V_237 = F_98 ;
V_57 -> V_74 . V_238 = F_99 ;
if ( V_220 -> V_75 . V_239 )
F_125 ( & V_220 -> V_75 , V_220 -> V_75 . V_239 ) ;
else
F_125 ( & V_220 -> V_75 , F_126 ( 32 ) ) ;
V_141 = F_118 ( V_220 , V_57 , V_231 ) ;
if ( V_141 )
return V_141 ;
for ( V_7 = 0 ; V_7 < V_231 ; V_7 ++ ) {
V_215 = F_127 ( & V_220 -> V_75 , sizeof( * V_215 ) , V_80 ) ;
if ( ! V_215 )
return - V_145 ;
V_215 -> V_87 . V_240 = F_73 ;
F_128 ( & V_215 -> V_87 , & V_57 -> V_74 ) ;
}
return F_129 ( & V_57 -> V_74 ) ;
}
static int F_130 ( struct V_219 * V_220 )
{
struct V_56 * V_57 ;
const struct V_241 * V_242 ;
struct V_243 * V_244 = F_131 ( & V_220 -> V_75 ) ;
struct V_245 * V_246 ;
int V_141 , V_247 = 0 ;
const enum V_161 V_248 =
V_177 | V_179 |
V_181 ;
V_57 = F_127 ( & V_220 -> V_75 , sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return - V_145 ;
F_132 ( & V_57 -> V_91 ) ;
V_246 = F_133 ( V_220 , V_249 , 0 ) ;
V_57 -> V_10 = F_134 ( & V_220 -> V_75 , V_246 ) ;
if ( F_25 ( V_57 -> V_10 ) )
return F_135 ( V_57 -> V_10 ) ;
V_242 = F_136 ( V_250 , & V_220 -> V_75 ) ;
if ( V_242 )
F_137 ( V_220 -> V_75 . V_251 , L_57 ,
& V_247 ) ;
else if ( V_244 && V_244 -> V_247 )
V_247 = V_244 -> V_247 ;
else
V_247 = 32 ;
F_138 ( V_252 , V_57 -> V_74 . V_253 ) ;
F_138 ( V_254 , V_57 -> V_74 . V_253 ) ;
F_138 ( V_255 , V_57 -> V_74 . V_253 ) ;
F_138 ( V_256 , V_57 -> V_74 . V_253 ) ;
V_57 -> V_74 . V_257 = F_89 ;
V_57 -> V_74 . V_258 = F_93 ;
V_57 -> V_74 . V_259 = F_97 ;
V_57 -> V_74 . V_260 = V_190 ;
V_57 -> V_74 . V_261 = V_248 ;
V_57 -> V_74 . V_262 = V_248 ;
V_57 -> V_74 . V_263 = F_14 ( V_170 ) | F_14 ( V_163 ) ;
V_57 -> V_74 . V_264 = V_265 ;
V_57 -> V_74 . V_266 = true ;
V_57 -> V_74 . V_75 = & V_220 -> V_75 ;
V_141 = F_124 ( V_220 , V_57 , V_247 ) ;
if ( V_141 ) {
F_69 ( V_57 -> V_74 . V_75 , L_58 ) ;
return V_141 ;
}
if ( V_220 -> V_75 . V_251 ) {
V_141 = F_139 ( V_220 -> V_75 . V_251 ,
F_122 , V_57 ) ;
if ( V_141 < 0 ) {
F_69 ( V_57 -> V_74 . V_75 ,
L_59 ) ;
return V_141 ;
}
}
F_140 ( V_220 , V_57 ) ;
F_23 ( V_57 ) ;
F_141 ( V_57 -> V_74 . V_75 , L_60 , V_247 ) ;
return 0 ;
}
bool F_142 ( struct V_142 * V_63 , void * V_267 )
{
struct V_84 * V_215 = F_51 ( V_63 ) ;
struct V_268 * V_3 = V_267 ;
if ( V_63 -> V_88 -> V_75 -> V_269 != & V_270 . V_269 )
return false ;
V_215 -> V_8 = V_3 -> V_8 ;
V_215 -> V_86 = V_3 -> V_86 ;
return true ;
}
int F_143 ( int V_271 )
{
if ( V_95 & ( F_14 ( V_271 ) ) )
return - V_272 ;
V_93 ^= F_14 ( V_271 ) ;
return 0 ;
}
