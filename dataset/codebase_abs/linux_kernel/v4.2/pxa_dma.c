static unsigned int F_1 ( unsigned int line )
{
if ( line < 64 )
return 0x100 + line * 4 ;
return 0x1000 + line * 4 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
T_1 V_9 ;
V_4 += F_3 ( V_2 , L_1 , V_6 -> V_10 ) ;
for ( V_8 = 0 ; V_8 < 70 ; V_8 ++ ) {
V_9 = F_4 ( V_6 -> V_11 + F_1 ( V_8 ) ) ;
if ( ( V_9 & V_12 ) == V_6 -> V_10 )
V_4 += F_3 ( V_2 , L_2 , V_8 ,
! ! ( V_9 & V_13 ) ) ;
}
return V_4 ;
}
static inline int F_5 ( T_1 V_14 )
{
int V_15 = ( V_14 >> 16 ) & 0x3 ;
return V_15 ? 4 << V_15 : 0 ;
}
static int F_6 ( unsigned long V_16 )
{
return F_7 ( F_8 ( V_16 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 , V_17 = 20 , V_15 , V_18 ;
T_1 V_14 ;
unsigned long V_19 , V_20 ;
struct V_21 * V_22 ;
V_19 = V_20 = F_10 ( V_6 , V_23 ) ;
F_3 ( V_2 , L_3 , V_6 -> V_10 ) ;
F_3 ( V_2 , L_4 , 0 ) ;
for ( V_8 = 1 ; V_8 < V_17 && F_6 ( V_19 ) ; V_8 ++ ) {
V_22 = F_11 ( V_19 ) ;
V_14 = V_22 -> V_14 ;
V_15 = F_5 ( V_14 ) ;
V_18 = ( 1 << ( ( V_14 >> 14 ) & 0x3 ) ) >> 1 ;
F_3 ( V_2 , L_5 ,
V_8 , V_19 , V_22 ) ;
F_3 ( V_2 , L_6 , V_22 -> V_20 ) ;
F_3 ( V_2 , L_7 , V_22 -> V_24 ) ;
F_3 ( V_2 , L_8 , V_22 -> V_25 ) ;
F_3 ( V_2 , L_9 ,
V_14 ,
F_12 ( V_26 ) , F_12 ( V_27 ) ,
F_12 ( V_28 ) , F_12 ( V_29 ) ,
F_12 ( V_30 ) , F_12 ( V_31 ) ,
F_12 ( V_32 ) , V_15 , V_18 ,
V_14 & V_33 ) ;
V_19 = V_22 -> V_20 ;
}
if ( V_8 == V_17 )
F_3 ( V_2 , L_10 ,
V_8 , V_19 ) ;
else
F_3 ( V_2 , L_11 ,
V_8 , V_19 , V_19 == V_34 ?
L_12 : L_13 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_35 , V_14 ;
int V_15 , V_18 ;
static const char * const V_36 [] = {
L_14 , L_15 , L_16 , L_13
} ;
V_35 = F_10 ( V_6 , V_37 ) ;
V_14 = F_10 ( V_6 , V_38 ) ;
V_15 = F_5 ( V_14 ) ;
V_18 = ( 1 << ( ( V_14 >> 14 ) & 0x3 ) ) >> 1 ;
F_3 ( V_2 , L_17 , V_6 -> V_10 ) ;
F_3 ( V_2 , L_18 ,
V_36 [ ( V_6 -> V_10 & 0xf ) / 4 ] ) ;
F_3 ( V_2 , L_19 ,
F_10 ( V_6 , V_39 ) & F_14 ( V_6 -> V_10 ) ?
L_20 : L_21 ) ;
F_3 ( V_2 , L_22 ,
V_35 , F_15 ( V_40 ) , F_15 ( V_41 ) ,
F_15 ( V_42 ) , F_15 ( V_43 ) ,
F_15 ( V_44 ) , F_15 ( V_45 ) ,
F_15 ( V_46 ) , F_15 ( V_47 ) ,
F_15 ( V_48 ) , F_15 ( V_49 ) ,
F_15 ( V_50 ) , F_15 ( V_51 ) ,
F_15 ( V_52 ) , F_15 ( V_53 ) ,
F_15 ( V_54 ) ) ;
F_3 ( V_2 , L_9 ,
V_14 ,
F_12 ( V_26 ) , F_12 ( V_27 ) ,
F_12 ( V_28 ) , F_12 ( V_29 ) ,
F_12 ( V_30 ) , F_12 ( V_31 ) ,
F_12 ( V_32 ) , V_15 , V_18 , V_14 & V_33 ) ;
F_3 ( V_2 , L_7 , F_10 ( V_6 , V_55 ) ) ;
F_3 ( V_2 , L_8 , F_10 ( V_6 , V_56 ) ) ;
F_3 ( V_2 , L_6 , F_10 ( V_6 , V_23 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_3 )
{
struct V_57 * V_58 = V_2 -> V_7 ;
F_17 ( V_2 , L_23 ) ;
F_3 ( V_2 , L_24 , V_58 -> V_59 ) ;
return 0 ;
}
static struct V_60 * F_18 ( struct V_57 * V_58 ,
int V_61 , struct V_60 * V_62 )
{
char V_63 [ 11 ] ;
struct V_60 * V_64 , * V_65 = NULL , * V_66 = NULL ;
struct V_60 * V_67 = NULL ;
void * V_68 ;
F_19 ( V_63 , sizeof( V_63 ) , L_25 , V_61 ) ;
V_64 = F_20 ( V_63 , V_62 ) ;
V_68 = ( void * ) & V_58 -> V_69 [ V_61 ] ;
if ( V_64 )
V_65 = F_21 ( L_26 , 0400 , V_64 , V_68 ,
& V_70 ) ;
if ( V_65 )
V_66 = F_21 ( L_27 , 0400 , V_64 , V_68 ,
& V_71 ) ;
if ( V_66 )
V_67 = F_21 ( L_28 , 0400 , V_64 , V_68 ,
& V_72 ) ;
if ( ! V_67 )
goto V_73;
return V_64 ;
V_73:
F_22 ( V_64 ) ;
return NULL ;
}
static void F_23 ( struct V_57 * V_58 )
{
int V_8 ;
struct V_60 * V_62 ;
V_58 -> V_74 = F_20 ( F_24 ( V_58 -> V_75 . V_76 ) , NULL ) ;
if ( F_25 ( V_58 -> V_74 ) || ! V_58 -> V_74 )
goto V_77;
V_58 -> V_78 = F_21 ( L_26 , 0400 , V_58 -> V_74 ,
V_58 , & V_79 ) ;
if ( ! V_58 -> V_78 )
goto V_73;
V_58 -> V_80 =
F_26 ( V_58 -> V_59 , sizeof( * V_58 -> V_78 ) ,
V_81 ) ;
if ( ! V_58 -> V_80 )
goto V_82;
V_62 = F_20 ( L_29 , V_58 -> V_74 ) ;
if ( ! V_62 )
goto V_83;
for ( V_8 = 0 ; V_8 < V_58 -> V_59 ; V_8 ++ ) {
V_58 -> V_80 [ V_8 ] = F_18 ( V_58 , V_8 , V_62 ) ;
if ( ! V_58 -> V_80 [ V_8 ] )
goto V_84;
}
return;
V_84:
V_83:
F_27 ( V_58 -> V_80 ) ;
V_82:
V_73:
F_22 ( V_58 -> V_74 ) ;
V_77:
F_28 ( L_30 ) ;
}
static void F_29 ( struct V_57 * V_58 )
{
F_22 ( V_58 -> V_74 ) ;
}
static inline void F_23 ( struct V_57 * V_58 ) {}
static inline void F_29 ( struct V_57 * V_58 ) {}
static struct V_5 * F_30 ( struct V_85 * V_86 )
{
int V_87 , V_8 ;
struct V_57 * V_58 = F_31 ( V_86 -> V_88 . V_64 . V_89 ) ;
struct V_5 * V_6 , * V_90 = NULL ;
unsigned long V_91 ;
F_32 ( & V_58 -> V_92 , V_91 ) ;
for ( V_87 = V_86 -> V_87 ; V_87 >= V_93 ; V_87 -- ) {
for ( V_8 = 0 ; V_8 < V_58 -> V_59 ; V_8 ++ ) {
if ( V_87 != ( V_8 & 0xf ) >> 2 )
continue;
if ( ( V_8 < 32 ) && ( V_94 & F_14 ( V_8 ) ) )
continue;
V_6 = & V_58 -> V_69 [ V_8 ] ;
if ( ! V_6 -> V_95 ) {
V_6 -> V_95 = V_86 ;
V_90 = V_6 ;
if ( V_8 < 32 )
V_96 |= F_14 ( V_8 ) ;
goto V_97;
}
}
}
V_97:
F_33 ( & V_58 -> V_92 , V_91 ) ;
F_34 ( & V_86 -> V_88 . V_64 . V_76 -> V_89 ,
L_31 , V_98 , V_90 ,
V_90 ? V_90 -> V_10 : - 1 ) ;
return V_90 ;
}
static void F_35 ( struct V_85 * V_64 )
{
struct V_57 * V_58 = F_31 ( V_64 -> V_88 . V_64 . V_89 ) ;
unsigned long V_91 ;
T_1 V_99 ;
int V_8 ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_32 , V_98 ) ;
if ( ! V_64 -> V_6 )
return;
V_99 = F_1 ( V_64 -> V_9 ) ;
F_36 ( 0 , V_64 -> V_6 -> V_11 + V_99 ) ;
F_32 ( & V_58 -> V_92 , V_91 ) ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ )
if ( V_64 -> V_6 == & V_58 -> V_69 [ V_8 ] )
V_96 &= ~ F_14 ( V_8 ) ;
V_64 -> V_6 -> V_95 = NULL ;
V_64 -> V_6 = NULL ;
F_33 ( & V_58 -> V_92 , V_91 ) ;
}
static bool F_37 ( struct V_85 * V_64 )
{
T_1 V_35 ;
struct V_5 * V_6 = V_64 -> V_6 ;
if ( ! V_6 )
return false ;
V_35 = F_38 ( V_6 , V_37 ) ;
return V_35 & V_100 ;
}
static bool F_39 ( struct V_85 * V_64 )
{
T_1 V_101 ;
F_40 ( ! V_64 -> V_6 ) ;
V_101 = F_38 ( V_64 -> V_6 , V_39 ) ;
return V_101 & ( F_14 ( V_64 -> V_6 -> V_10 ) ) ;
}
static void F_41 ( struct V_5 * V_6 , bool V_102 )
{
T_1 V_99 , V_101 ;
if ( ! V_6 -> V_95 )
return;
F_34 ( & V_6 -> V_95 -> V_88 . V_64 . V_76 -> V_89 ,
L_33 , V_98 ,
V_6 , V_6 -> V_10 , V_102 ) ;
V_99 = F_1 ( V_6 -> V_95 -> V_9 ) ;
F_36 ( V_13 | V_6 -> V_10 , V_6 -> V_11 + V_99 ) ;
V_101 = F_38 ( V_6 , V_39 ) ;
if ( V_102 )
V_101 |= F_14 ( V_6 -> V_10 ) ;
else
V_101 &= ~ F_14 ( V_6 -> V_10 ) ;
F_42 ( V_6 , V_101 , V_39 ) ;
F_43 ( V_6 , V_103 | V_104 |
V_105 | V_100 , V_37 ) ;
}
static void F_44 ( struct V_5 * V_6 )
{
T_1 V_35 ;
if ( ! V_6 )
return;
V_35 = F_38 ( V_6 , V_37 ) ;
F_34 ( & V_6 -> V_95 -> V_88 . V_64 . V_76 -> V_89 ,
L_31 , V_98 , V_6 , V_6 -> V_10 ) ;
F_43 ( V_6 , V_35 & ~ V_100 & ~ V_103 , V_37 ) ;
}
static void F_45 ( struct V_85 * V_64 ,
struct V_106 * V_22 )
{
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_34 , V_98 , V_22 ) ;
if ( ! V_64 -> V_6 ) {
V_64 -> V_6 = F_30 ( V_64 ) ;
if ( ! V_64 -> V_6 ) {
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_35 , V_98 ) ;
return;
}
}
F_43 ( V_64 -> V_6 , V_22 -> V_107 , V_23 ) ;
F_41 ( V_64 -> V_6 , V_64 -> V_102 ) ;
}
static void F_46 ( struct V_106 * V_108 ,
unsigned long V_91 )
{
struct V_21 * V_109 =
V_108 -> V_110 [ V_108 -> V_111 - 1 ] ;
T_2 V_112 = V_108 -> V_110 [ V_108 -> V_111 - 2 ] -> V_20 ;
V_109 -> V_20 = V_34 ;
V_109 -> V_24 = V_112 ;
V_109 -> V_25 = V_112 + 8 ;
V_109 -> V_14 = V_113 | V_114 |
( V_33 & sizeof( T_1 ) ) ;
if ( V_91 & V_115 )
V_109 -> V_14 |= V_116 ;
}
static bool F_47 ( struct V_117 * V_118 )
{
struct V_106 * V_108 = F_48 ( V_118 ) ;
struct V_21 * V_109 =
V_108 -> V_110 [ V_108 -> V_111 - 1 ] ;
return V_109 -> V_25 != ( V_109 -> V_24 + 8 ) ;
}
static void F_49 ( struct V_117 * V_119 ,
struct V_117 * V_120 )
{
struct V_106 * V_121 = F_48 ( V_119 ) ;
struct V_106 * V_122 = F_48 ( V_120 ) ;
T_2 V_123 ;
V_123 = V_122 -> V_107 ;
V_121 -> V_110 [ V_121 -> V_111 - 1 ] -> V_20 = V_123 ;
}
static bool F_50 ( struct V_124 * V_88 ,
struct V_117 * V_118 )
{
struct V_117 * V_125 = NULL ;
struct V_85 * V_64 = F_51 ( & V_88 -> V_64 ) ;
if ( F_37 ( V_64 ) ) {
F_40 ( F_52 ( & V_88 -> V_126 ) ) ;
if ( ! F_39 ( V_64 ) &&
F_48 ( V_118 ) -> V_102 )
return false ;
V_125 = F_53 ( V_88 -> V_126 . V_127 ,
struct V_117 , V_128 ) ;
F_49 ( V_125 , V_118 ) ;
if ( F_37 ( V_64 ) || F_47 ( V_125 ) )
return true ;
}
return false ;
}
static unsigned int F_54 ( struct V_5 * V_6 )
{
T_1 V_35 ;
T_1 V_129 = F_55 ( V_6 -> V_11 + V_130 ) ;
if ( ! ( V_129 & F_14 ( V_6 -> V_10 ) ) )
return V_100 ;
V_35 = F_38 ( V_6 , V_37 ) ;
F_43 ( V_6 , V_35 , V_37 ) ;
if ( ( V_35 & V_105 ) && ( V_6 -> V_95 ) )
F_56 ( & V_6 -> V_95 -> V_88 . V_64 . V_76 -> V_89 ,
L_36 ,
V_98 , & V_6 -> V_95 ) ;
return V_35 & ~ V_100 ;
}
static T_3 F_57 ( int V_131 , void * V_132 )
{
struct V_5 * V_6 = V_132 ;
struct V_85 * V_64 = V_6 -> V_95 ;
struct V_117 * V_118 , * V_133 ;
unsigned int V_35 ;
unsigned long V_91 ;
F_40 ( ! V_64 ) ;
V_35 = F_54 ( V_6 ) ;
if ( V_35 & V_100 )
return V_134 ;
F_32 ( & V_64 -> V_88 . V_135 , V_91 ) ;
F_58 (vd, tmp, &chan->vc.desc_issued, node) {
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_37 ,
V_98 , V_118 , V_118 -> V_136 . V_137 , F_47 ( V_118 ) ) ;
if ( F_47 ( V_118 ) ) {
F_59 ( & V_118 -> V_128 ) ;
F_60 ( V_118 ) ;
} else {
break;
}
}
if ( V_35 & V_138 ) {
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_38 ,
V_98 ,
F_52 ( & V_64 -> V_88 . V_139 ) ,
F_52 ( & V_64 -> V_88 . V_126 ) ) ;
F_42 ( V_6 , V_35 & ~ V_103 , V_37 ) ;
if ( F_52 ( & V_64 -> V_88 . V_126 ) ) {
V_64 -> V_102 =
! F_52 ( & V_64 -> V_88 . V_139 ) ;
} else {
V_118 = F_61 ( & V_64 -> V_88 . V_126 ,
struct V_117 , V_128 ) ;
F_45 ( V_64 , F_48 ( V_118 ) ) ;
}
}
F_33 ( & V_64 -> V_88 . V_135 , V_91 ) ;
return V_140 ;
}
static T_3 F_62 ( int V_131 , void * V_132 )
{
struct V_57 * V_58 = V_132 ;
struct V_5 * V_6 ;
T_1 V_129 = F_55 ( V_58 -> V_11 + V_130 ) ;
int V_8 , V_141 = V_134 ;
while ( V_129 ) {
V_8 = F_63 ( V_129 ) ;
V_129 &= ( V_129 - 1 ) ;
V_6 = & V_58 -> V_69 [ V_8 ] ;
if ( ( V_8 < 32 ) && ( V_94 & F_14 ( V_8 ) ) )
continue;
if ( F_57 ( V_131 , V_6 ) == V_140 )
V_141 = V_140 ;
}
return V_141 ;
}
static int F_64 ( struct V_142 * V_143 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
struct V_57 * V_58 = F_31 ( V_64 -> V_88 . V_64 . V_89 ) ;
if ( V_64 -> V_144 )
return 1 ;
V_64 -> V_144 = F_65 ( F_66 ( V_143 ) ,
V_58 -> V_75 . V_76 ,
sizeof( struct V_21 ) ,
F_67 ( struct V_21 ) ,
0 ) ;
if ( ! V_64 -> V_144 ) {
F_68 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_39 ,
V_98 ) ;
return - V_145 ;
}
return 1 ;
}
static void F_69 ( struct V_142 * V_143 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
F_70 ( & V_64 -> V_88 ) ;
F_71 ( V_64 -> V_144 ) ;
V_64 -> V_144 = NULL ;
}
static void F_72 ( struct V_117 * V_118 )
{
int V_8 ;
T_2 V_112 ;
struct V_106 * V_108 = F_48 ( V_118 ) ;
F_40 ( V_108 -> V_111 == 0 ) ;
for ( V_8 = V_108 -> V_111 - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( V_8 > 0 )
V_112 = V_108 -> V_110 [ V_8 - 1 ] -> V_20 ;
else
V_112 = V_108 -> V_107 ;
F_73 ( V_108 -> V_144 ,
V_108 -> V_110 [ V_8 ] , V_112 ) ;
}
V_108 -> V_111 = 0 ;
F_27 ( V_108 ) ;
}
static struct V_106 *
F_74 ( struct V_85 * V_64 , unsigned int V_146 )
{
struct V_106 * V_108 ;
T_2 V_112 ;
int V_8 ;
V_108 = F_75 ( sizeof( * V_108 ) +
V_146 * sizeof( struct V_21 * ) ,
V_147 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_144 = V_64 -> V_144 ;
for ( V_8 = 0 ; V_8 < V_146 ; V_8 ++ ) {
V_108 -> V_110 [ V_8 ] = F_76 ( V_108 -> V_144 ,
V_147 , & V_112 ) ;
if ( ! V_108 -> V_110 [ V_8 ] ) {
F_68 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_40 ,
V_98 , V_8 , V_108 -> V_144 ) ;
goto V_148;
}
if ( V_8 == 0 )
V_108 -> V_107 = V_112 ;
else
V_108 -> V_110 [ V_8 - 1 ] -> V_20 = V_112 ;
V_108 -> V_111 ++ ;
}
return V_108 ;
V_148:
F_72 ( & V_108 -> V_118 ) ;
return NULL ;
}
static T_4 F_77 ( struct V_149 * V_136 )
{
struct V_124 * V_88 = F_78 ( V_136 -> V_64 ) ;
struct V_85 * V_64 = F_51 ( & V_88 -> V_64 ) ;
struct V_117 * V_150 = NULL ,
* V_118 = F_79 ( V_136 , struct V_117 , V_136 ) ;
T_4 V_137 ;
unsigned long V_91 ;
F_46 ( F_48 ( V_118 ) , V_136 -> V_91 ) ;
F_32 ( & V_88 -> V_135 , V_91 ) ;
V_137 = F_80 ( V_136 ) ;
if ( F_52 ( & V_88 -> V_139 ) && F_50 ( V_88 , V_118 ) ) {
F_81 ( & V_118 -> V_128 , & V_88 -> V_126 ) ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_41 ,
V_98 , V_118 , V_137 ) ;
goto V_151;
}
if ( ! F_52 ( & V_88 -> V_139 ) ) {
V_150 = F_53 ( V_88 -> V_139 . V_127 ,
struct V_117 , V_128 ) ;
if ( V_64 -> V_102 || ! F_48 ( V_118 ) -> V_102 )
F_49 ( V_150 , V_118 ) ;
else
V_150 = NULL ;
}
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_42 ,
V_98 , V_118 , V_137 , V_150 ? L_43 : L_44 ) ;
F_81 ( & V_118 -> V_128 , & V_88 -> V_139 ) ;
V_64 -> V_102 |= F_48 ( V_118 ) -> V_102 ;
V_151:
F_33 ( & V_88 -> V_135 , V_91 ) ;
return V_137 ;
}
static void F_82 ( struct V_142 * V_143 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
struct V_117 * V_152 ;
unsigned long V_91 ;
F_32 ( & V_64 -> V_88 . V_135 , V_91 ) ;
if ( F_52 ( & V_64 -> V_88 . V_139 ) )
goto V_151;
V_152 = F_61 ( & V_64 -> V_88 . V_139 ,
struct V_117 , V_128 ) ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_45 , V_98 , V_152 , V_152 -> V_136 . V_137 ) ;
F_83 ( & V_64 -> V_88 ) ;
if ( ! F_50 ( & V_64 -> V_88 , V_152 ) )
F_45 ( V_64 , F_48 ( V_152 ) ) ;
V_151:
F_33 ( & V_64 -> V_88 . V_135 , V_91 ) ;
}
static inline struct V_149 *
F_84 ( struct V_124 * V_88 , struct V_117 * V_118 ,
unsigned long V_153 )
{
struct V_149 * V_136 ;
struct V_85 * V_64 = F_79 ( V_88 , struct V_85 , V_88 ) ;
V_136 = F_85 ( V_88 , V_118 , V_153 ) ;
V_136 -> V_154 = F_77 ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_46 , V_98 ,
V_88 , V_118 , V_118 -> V_136 . V_137 ,
V_153 ) ;
return V_136 ;
}
static void F_86 ( struct V_85 * V_64 ,
enum V_155 V_156 ,
T_1 * V_14 , T_1 * V_157 , T_1 * V_158 )
{
T_1 V_159 = 0 , V_160 = 0 ;
enum V_161 V_18 = V_162 ;
* V_14 = 0 ;
if ( V_64 -> V_163 . V_164 == V_165 ) {
V_159 = V_64 -> V_163 . V_166 ;
V_18 = V_64 -> V_163 . V_167 ;
V_160 = V_64 -> V_163 . V_168 ;
* V_157 = V_160 ;
* V_14 |= V_169 | V_170 ;
}
if ( V_64 -> V_163 . V_164 == V_171 ) {
V_159 = V_64 -> V_163 . V_172 ;
V_18 = V_64 -> V_163 . V_173 ;
V_160 = V_64 -> V_163 . V_174 ;
* V_158 = V_160 ;
* V_14 |= V_175 | V_176 ;
}
if ( V_64 -> V_163 . V_164 == V_177 )
* V_14 |= V_114 | V_169 |
V_175 ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_47 ,
V_98 , V_160 , V_159 , V_18 , V_156 ) ;
if ( V_18 == V_178 )
* V_14 |= V_179 ;
else if ( V_18 == V_180 )
* V_14 |= V_181 ;
else if ( V_18 == V_182 )
* V_14 |= V_113 ;
if ( V_159 == 8 )
* V_14 |= V_183 ;
else if ( V_159 == 16 )
* V_14 |= V_184 ;
else if ( V_159 == 32 )
* V_14 |= V_114 ;
if ( V_64 -> V_163 . V_185 )
V_64 -> V_9 = V_64 -> V_163 . V_185 ;
}
static struct V_149 *
F_87 ( struct V_142 * V_143 ,
T_2 V_186 , T_2 V_187 ,
T_5 V_188 , unsigned long V_91 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
struct V_106 * V_108 ;
struct V_21 * V_110 ;
T_1 V_14 ;
unsigned int V_8 , V_111 = 0 ;
T_5 V_189 ;
if ( ! V_143 || ! V_188 )
return NULL ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_48 ,
V_98 , ( unsigned long ) V_186 , ( unsigned long ) V_187 ,
V_188 , V_91 ) ;
F_86 ( V_64 , V_177 , & V_14 , NULL , NULL ) ;
V_111 = F_88 ( V_188 , V_190 ) ;
V_108 = F_74 ( V_64 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_188 = V_188 ;
if ( ! F_89 ( V_187 , 1 << V_191 ) ||
! F_89 ( V_186 , 1 << V_191 ) )
V_108 -> V_102 = true ;
V_8 = 0 ;
do {
V_110 = V_108 -> V_110 [ V_8 ++ ] ;
V_189 = F_90 ( T_5 , V_188 , V_190 ) ;
V_110 -> V_14 = V_14 | ( V_33 & V_189 ) ;
V_110 -> V_24 = V_187 ;
V_110 -> V_25 = V_186 ;
V_188 -= V_189 ;
V_187 += V_189 ;
V_186 += V_189 ;
} while ( V_188 );
F_46 ( V_108 , V_91 ) ;
return F_84 ( & V_64 -> V_88 , & V_108 -> V_118 , V_91 ) ;
}
static struct V_149 *
F_91 ( struct V_142 * V_143 , struct V_192 * V_193 ,
unsigned int V_194 , enum V_155 V_156 ,
unsigned long V_91 , void * V_195 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
struct V_106 * V_108 ;
T_5 V_188 , V_196 ;
struct V_192 * V_197 ;
T_2 V_112 ;
T_1 V_14 , V_24 = 0 , V_25 = 0 ;
unsigned int V_111 = 0 , V_8 , V_198 = 0 ;
if ( ( V_193 == NULL ) || ( V_194 == 0 ) )
return NULL ;
F_86 ( V_64 , V_156 , & V_14 , & V_24 , & V_25 ) ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_49 , V_98 , V_156 , V_91 ) ;
F_92 (sgl, sg, sg_len, i)
V_111 += F_88 ( F_93 ( V_197 ) , V_190 ) ;
V_108 = F_74 ( V_64 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
F_92 (sgl, sg, sg_len, i) {
V_112 = F_94 ( V_197 ) ;
V_196 = F_93 ( V_197 ) ;
V_108 -> V_188 += V_196 ;
do {
V_188 = F_90 ( T_5 , V_196 , V_190 ) ;
if ( V_112 & 0x7 )
V_108 -> V_102 = true ;
V_108 -> V_110 [ V_198 ] -> V_14 =
V_14 | ( V_33 & V_188 ) ;
V_108 -> V_110 [ V_198 ] -> V_24 = V_24 ? V_24 : V_112 ;
V_108 -> V_110 [ V_198 ++ ] -> V_25 = V_25 ? V_25 : V_112 ;
V_112 += V_188 ;
V_196 -= V_188 ;
} while ( V_196 );
}
F_46 ( V_108 , V_91 ) ;
return F_84 ( & V_64 -> V_88 , & V_108 -> V_118 , V_91 ) ;
}
static struct V_149 *
F_95 ( struct V_142 * V_143 ,
T_2 V_199 , T_5 V_188 , T_5 V_200 ,
enum V_155 V_156 , unsigned long V_91 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
struct V_106 * V_108 ;
struct V_21 * * V_201 ;
T_2 V_112 ;
T_1 V_14 , V_24 = 0 , V_25 = 0 ;
unsigned int V_111 = 0 ;
if ( ! V_143 || ! V_188 || ! V_200 )
return NULL ;
if ( ( V_156 != V_165 ) && ( V_156 != V_171 ) ) {
F_68 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_50 ) ;
return NULL ;
}
if ( V_188 % V_200 != 0 || V_200 > V_190 ||
! F_89 ( V_200 , 1 << V_191 ) )
return NULL ;
F_86 ( V_64 , V_156 , & V_14 , & V_24 , & V_25 ) ;
V_14 |= V_116 | ( V_33 | V_200 ) ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_51 ,
V_98 , ( unsigned long ) V_199 , V_188 , V_200 , V_156 , V_91 ) ;
V_111 = F_88 ( V_200 , V_190 ) ;
V_111 *= F_88 ( V_188 , V_200 ) ;
V_108 = F_74 ( V_64 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_202 = true ;
V_108 -> V_188 = V_188 ;
V_201 = V_108 -> V_110 ;
V_112 = V_199 ;
do {
V_201 [ 0 ] -> V_24 = V_24 ? V_24 : V_112 ;
V_201 [ 0 ] -> V_25 = V_25 ? V_25 : V_112 ;
V_201 [ 0 ] -> V_14 = V_14 ;
V_201 ++ ;
V_112 += V_200 ;
V_188 -= V_200 ;
} while ( V_188 );
F_46 ( V_108 , V_91 ) ;
return F_84 ( & V_64 -> V_88 , & V_108 -> V_118 , V_91 ) ;
}
static int F_96 ( struct V_142 * V_143 ,
struct V_203 * V_163 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
if ( ! V_143 )
return - V_204 ;
V_64 -> V_163 = * V_163 ;
return 0 ;
}
static int F_97 ( struct V_142 * V_143 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
struct V_57 * V_58 = F_31 ( V_64 -> V_88 . V_64 . V_89 ) ;
struct V_117 * V_118 = NULL ;
unsigned long V_91 ;
struct V_5 * V_6 ;
F_98 ( V_205 ) ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_52 , V_98 , & V_64 -> V_88 ) ;
F_32 ( & V_64 -> V_88 . V_135 , V_91 ) ;
F_99 ( & V_64 -> V_88 , & V_205 ) ;
F_100 (vd, &head, node) {
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_53 , V_98 ,
V_118 , V_118 -> V_136 . V_137 , F_47 ( V_118 ) ) ;
}
V_6 = V_64 -> V_6 ;
if ( V_6 ) {
F_44 ( V_64 -> V_6 ) ;
F_35 ( V_64 ) ;
V_64 -> V_6 = NULL ;
F_101 ( & V_58 -> V_92 ) ;
V_6 -> V_95 = NULL ;
F_102 ( & V_58 -> V_92 ) ;
}
F_33 ( & V_64 -> V_88 . V_135 , V_91 ) ;
F_103 ( & V_64 -> V_88 , & V_205 ) ;
return 0 ;
}
static unsigned int F_104 ( struct V_85 * V_64 ,
T_4 V_137 )
{
struct V_117 * V_118 = NULL ;
struct V_106 * V_108 = NULL ;
struct V_21 * V_110 = NULL ;
T_1 V_206 , V_207 , V_188 , V_208 , V_209 = 0 ;
unsigned long V_91 ;
bool V_210 = false ;
int V_8 ;
if ( ! V_64 -> V_6 )
return 0 ;
F_32 ( & V_64 -> V_88 . V_135 , V_91 ) ;
V_118 = F_105 ( & V_64 -> V_88 , V_137 ) ;
if ( ! V_118 )
goto V_151;
V_108 = F_48 ( V_118 ) ;
if ( V_108 -> V_110 [ 0 ] -> V_14 & V_175 )
V_206 = F_38 ( V_64 -> V_6 , V_55 ) ;
else
V_206 = F_38 ( V_64 -> V_6 , V_56 ) ;
for ( V_8 = 0 ; V_8 < V_108 -> V_111 - 1 ; V_8 ++ ) {
V_110 = V_108 -> V_110 [ V_8 ] ;
if ( V_108 -> V_110 [ 0 ] -> V_14 & V_175 )
V_207 = V_110 -> V_24 ;
else
V_207 = V_110 -> V_25 ;
V_188 = V_110 -> V_14 & V_33 ;
V_208 = V_207 + V_188 ;
if ( V_210 ) {
V_209 += V_188 ;
} else if ( V_206 >= V_207 && V_206 <= V_208 ) {
V_209 += V_208 - V_206 ;
V_210 = true ;
}
}
if ( ! V_210 )
V_209 = V_108 -> V_188 ;
V_151:
F_33 ( & V_64 -> V_88 . V_135 , V_91 ) ;
F_34 ( & V_64 -> V_88 . V_64 . V_76 -> V_89 ,
L_54 ,
V_98 , V_118 , V_137 , V_108 , V_209 ) ;
return V_209 ;
}
static enum V_211 F_106 ( struct V_142 * V_143 ,
T_4 V_137 ,
struct V_212 * V_213 )
{
struct V_85 * V_64 = F_51 ( V_143 ) ;
enum V_211 V_141 ;
V_141 = F_107 ( V_143 , V_137 , V_213 ) ;
if ( F_108 ( V_213 && ( V_141 != V_214 ) ) )
F_109 ( V_213 , F_104 ( V_64 , V_137 ) ) ;
return V_141 ;
}
static void F_110 ( struct V_215 * V_216 )
{
struct V_85 * V_217 , * V_218 ;
F_58 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_59 ( & V_217 -> V_88 . V_64 . V_219 ) ;
F_111 ( & V_217 -> V_88 . V_220 ) ;
}
}
static int F_112 ( struct V_221 * V_222 )
{
struct V_57 * V_58 = F_113 ( V_222 ) ;
F_29 ( V_58 ) ;
F_110 ( & V_58 -> V_75 ) ;
F_114 ( & V_58 -> V_75 ) ;
return 0 ;
}
static int F_115 ( struct V_221 * V_222 ,
struct V_57 * V_58 ,
unsigned int V_223 )
{
int V_224 , V_131 , V_225 = 0 , V_8 , V_141 ;
struct V_5 * V_6 ;
V_224 = F_116 ( V_222 , 0 ) ;
if ( V_224 < 0 )
return V_224 ;
V_58 -> V_69 = F_117 ( & V_222 -> V_76 , V_223 ,
sizeof( V_58 -> V_69 [ 0 ] ) , V_81 ) ;
if ( ! V_58 -> V_69 )
return - V_145 ;
for ( V_8 = 0 ; V_8 < V_223 ; V_8 ++ )
if ( F_116 ( V_222 , V_8 ) > 0 )
V_225 ++ ;
for ( V_8 = 0 ; V_8 < V_223 ; V_8 ++ ) {
V_6 = & V_58 -> V_69 [ V_8 ] ;
V_6 -> V_11 = V_58 -> V_11 ;
V_6 -> V_10 = V_8 ;
V_131 = F_116 ( V_222 , V_8 ) ;
if ( ( V_225 > 1 ) && ( V_131 > 0 ) )
V_141 = F_118 ( & V_222 -> V_76 , V_131 ,
F_57 ,
V_226 , L_55 , V_6 ) ;
if ( ( V_225 == 1 ) && ( V_8 == 0 ) )
V_141 = F_118 ( & V_222 -> V_76 , V_224 ,
F_62 ,
V_226 , L_55 , V_58 ) ;
if ( V_141 ) {
F_68 ( V_58 -> V_75 . V_76 ,
L_56 , V_98 ,
V_131 , V_141 ) ;
return V_141 ;
}
}
return 0 ;
}
static struct V_142 * F_119 ( struct V_227 * V_228 ,
struct V_229 * V_230 )
{
struct V_57 * V_231 = V_230 -> V_232 ;
struct V_142 * V_64 ;
V_64 = F_120 ( & V_231 -> V_75 ) ;
if ( ! V_64 )
return NULL ;
F_51 ( V_64 ) -> V_9 = V_228 -> args [ 0 ] ;
F_51 ( V_64 ) -> V_87 = V_228 -> args [ 1 ] ;
return V_64 ;
}
static int F_121 ( struct V_221 * V_222 ,
struct V_57 * V_58 ,
unsigned int V_233 )
{
int V_141 ;
unsigned int V_8 ;
struct V_85 * V_217 ;
V_58 -> V_59 = V_233 ;
F_122 ( & V_58 -> V_75 . V_234 ) ;
V_58 -> V_75 . V_235 = F_64 ;
V_58 -> V_75 . V_236 = F_69 ;
V_58 -> V_75 . V_237 = F_106 ;
V_58 -> V_75 . V_238 = F_82 ;
V_58 -> V_75 . V_239 = F_96 ;
V_58 -> V_75 . V_240 = F_97 ;
if ( V_222 -> V_76 . V_241 )
F_123 ( & V_222 -> V_76 , V_222 -> V_76 . V_241 ) ;
else
F_123 ( & V_222 -> V_76 , F_124 ( 32 ) ) ;
V_141 = F_115 ( V_222 , V_58 , V_233 ) ;
if ( V_141 )
return V_141 ;
for ( V_8 = 0 ; V_8 < V_233 ; V_8 ++ ) {
V_217 = F_125 ( & V_222 -> V_76 , sizeof( * V_217 ) , V_81 ) ;
if ( ! V_217 )
return - V_145 ;
V_217 -> V_88 . V_242 = F_72 ;
F_126 ( & V_217 -> V_88 , & V_58 -> V_75 ) ;
}
return F_127 ( & V_58 -> V_75 ) ;
}
static int F_128 ( struct V_221 * V_222 )
{
struct V_57 * V_58 ;
const struct V_243 * V_244 ;
struct V_245 * V_246 = F_129 ( & V_222 -> V_76 ) ;
struct V_247 * V_248 ;
int V_141 , V_249 = 0 ;
const enum V_161 V_250 =
V_178 | V_180 |
V_182 ;
V_58 = F_125 ( & V_222 -> V_76 , sizeof( * V_58 ) , V_81 ) ;
if ( ! V_58 )
return - V_145 ;
F_130 ( & V_58 -> V_92 ) ;
V_248 = F_131 ( V_222 , V_251 , 0 ) ;
V_58 -> V_11 = F_132 ( & V_222 -> V_76 , V_248 ) ;
if ( F_25 ( V_58 -> V_11 ) )
return F_133 ( V_58 -> V_11 ) ;
V_244 = F_134 ( V_252 , & V_222 -> V_76 ) ;
if ( V_244 )
F_135 ( V_222 -> V_76 . V_253 , L_57 ,
& V_249 ) ;
else if ( V_246 && V_246 -> V_249 )
V_249 = V_246 -> V_249 ;
else
V_249 = 32 ;
F_136 ( V_254 , V_58 -> V_75 . V_255 ) ;
F_136 ( V_256 , V_58 -> V_75 . V_255 ) ;
F_136 ( V_257 , V_58 -> V_75 . V_255 ) ;
F_136 ( V_258 , V_58 -> V_75 . V_255 ) ;
V_58 -> V_75 . V_259 = F_87 ;
V_58 -> V_75 . V_260 = F_91 ;
V_58 -> V_75 . V_261 = F_95 ;
V_58 -> V_75 . V_262 = V_191 ;
V_58 -> V_75 . V_263 = V_250 ;
V_58 -> V_75 . V_264 = V_250 ;
V_58 -> V_75 . V_265 = F_14 ( V_171 ) | F_14 ( V_165 ) ;
V_58 -> V_75 . V_266 = V_267 ;
V_58 -> V_75 . V_76 = & V_222 -> V_76 ;
V_141 = F_121 ( V_222 , V_58 , V_249 ) ;
if ( V_141 ) {
F_68 ( V_58 -> V_75 . V_76 , L_58 ) ;
return V_141 ;
}
if ( V_222 -> V_76 . V_253 ) {
V_141 = F_137 ( V_222 -> V_76 . V_253 ,
F_119 , V_58 ) ;
if ( V_141 < 0 ) {
F_68 ( V_58 -> V_75 . V_76 ,
L_59 ) ;
return V_141 ;
}
}
F_138 ( V_222 , V_58 ) ;
F_23 ( V_58 ) ;
F_139 ( V_58 -> V_75 . V_76 , L_60 , V_249 ) ;
return 0 ;
}
bool F_140 ( struct V_142 * V_64 , void * V_268 )
{
struct V_85 * V_217 = F_51 ( V_64 ) ;
struct V_269 * V_3 = V_268 ;
if ( V_64 -> V_89 -> V_76 -> V_270 != & V_271 . V_270 )
return false ;
V_217 -> V_9 = V_3 -> V_9 ;
V_217 -> V_87 = V_3 -> V_87 ;
return true ;
}
int F_141 ( int V_272 )
{
if ( V_96 & ( F_14 ( V_272 ) ) )
return - V_273 ;
V_94 ^= F_14 ( V_272 ) ;
return 0 ;
}
