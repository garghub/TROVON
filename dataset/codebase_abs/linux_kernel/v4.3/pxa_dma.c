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
}
static bool F_47 ( struct V_116 * V_117 )
{
struct V_105 * V_107 = F_48 ( V_117 ) ;
struct V_20 * V_108 =
V_107 -> V_109 [ V_107 -> V_110 - 1 ] ;
return V_108 -> V_24 != ( V_108 -> V_23 + 8 ) ;
}
static void F_49 ( struct V_116 * V_118 ,
struct V_116 * V_119 )
{
struct V_105 * V_120 = F_48 ( V_118 ) ;
struct V_105 * V_121 = F_48 ( V_119 ) ;
T_2 V_122 ;
V_122 = V_121 -> V_106 ;
V_120 -> V_109 [ V_120 -> V_110 - 1 ] -> V_19 = V_122 ;
}
static bool F_50 ( struct V_123 * V_87 ,
struct V_116 * V_117 )
{
struct V_116 * V_124 = NULL ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
if ( F_37 ( V_63 ) ) {
F_40 ( F_52 ( & V_87 -> V_125 ) ) ;
if ( ! F_39 ( V_63 ) &&
F_48 ( V_117 ) -> V_101 )
return false ;
V_124 = F_53 ( V_87 -> V_125 . V_126 ,
struct V_116 , V_127 ) ;
F_49 ( V_124 , V_117 ) ;
if ( F_37 ( V_63 ) || F_47 ( V_124 ) )
return true ;
}
return false ;
}
static unsigned int F_54 ( struct V_4 * V_5 )
{
T_1 V_34 ;
T_1 V_128 = F_55 ( V_5 -> V_10 + V_129 ) ;
if ( ! ( V_128 & F_14 ( V_5 -> V_9 ) ) )
return V_99 ;
V_34 = F_38 ( V_5 , V_36 ) ;
F_43 ( V_5 , V_34 , V_36 ) ;
if ( ( V_34 & V_104 ) && ( V_5 -> V_94 ) )
F_56 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_36 ,
V_97 , & V_5 -> V_94 ) ;
return V_34 & ~ V_99 ;
}
static T_3 F_57 ( int V_130 , void * V_131 )
{
struct V_4 * V_5 = V_131 ;
struct V_84 * V_63 = V_5 -> V_94 ;
struct V_116 * V_117 , * V_132 ;
unsigned int V_34 ;
unsigned long V_90 ;
F_40 ( ! V_63 ) ;
V_34 = F_54 ( V_5 ) ;
if ( V_34 & V_99 )
return V_133 ;
F_32 ( & V_63 -> V_87 . V_134 , V_90 ) ;
F_58 (vd, tmp, &chan->vc.desc_issued, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_37 ,
V_97 , V_117 , V_117 -> V_135 . V_136 , F_47 ( V_117 ) ) ;
if ( F_47 ( V_117 ) ) {
F_59 ( & V_117 -> V_127 ) ;
F_60 ( V_117 ) ;
} else {
break;
}
}
if ( V_34 & V_137 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_38 ,
V_97 ,
F_52 ( & V_63 -> V_87 . V_138 ) ,
F_52 ( & V_63 -> V_87 . V_125 ) ) ;
F_42 ( V_5 , V_34 & ~ V_102 , V_36 ) ;
if ( F_52 ( & V_63 -> V_87 . V_125 ) ) {
V_63 -> V_101 =
! F_52 ( & V_63 -> V_87 . V_138 ) ;
} else {
V_117 = F_61 ( & V_63 -> V_87 . V_125 ,
struct V_116 , V_127 ) ;
F_45 ( V_63 , F_48 ( V_117 ) ) ;
}
}
F_33 ( & V_63 -> V_87 . V_134 , V_90 ) ;
return V_139 ;
}
static T_3 F_62 ( int V_130 , void * V_131 )
{
struct V_56 * V_57 = V_131 ;
struct V_4 * V_5 ;
T_1 V_128 = F_55 ( V_57 -> V_10 + V_129 ) ;
int V_7 , V_140 = V_133 ;
while ( V_128 ) {
V_7 = F_63 ( V_128 ) ;
V_128 &= ( V_128 - 1 ) ;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ( V_7 < 32 ) && ( V_93 & F_14 ( V_7 ) ) )
continue;
if ( F_57 ( V_130 , V_5 ) == V_139 )
V_140 = V_139 ;
}
return V_140 ;
}
static int F_64 ( struct V_141 * V_142 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
if ( V_63 -> V_143 )
return 1 ;
V_63 -> V_143 = F_65 ( F_66 ( V_142 ) ,
V_57 -> V_74 . V_75 ,
sizeof( struct V_20 ) ,
F_67 ( struct V_20 ) ,
0 ) ;
if ( ! V_63 -> V_143 ) {
F_68 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_39 ,
V_97 ) ;
return - V_144 ;
}
return 1 ;
}
static void F_69 ( struct V_141 * V_142 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
F_70 ( & V_63 -> V_87 ) ;
F_71 ( V_63 -> V_143 ) ;
V_63 -> V_143 = NULL ;
}
static void F_72 ( struct V_116 * V_117 )
{
int V_7 ;
T_2 V_111 ;
struct V_105 * V_107 = F_48 ( V_117 ) ;
F_40 ( V_107 -> V_110 == 0 ) ;
for ( V_7 = V_107 -> V_110 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 )
V_111 = V_107 -> V_109 [ V_7 - 1 ] -> V_19 ;
else
V_111 = V_107 -> V_106 ;
F_73 ( V_107 -> V_143 ,
V_107 -> V_109 [ V_7 ] , V_111 ) ;
}
V_107 -> V_110 = 0 ;
F_27 ( V_107 ) ;
}
static struct V_105 *
F_74 ( struct V_84 * V_63 , unsigned int V_145 )
{
struct V_105 * V_107 ;
T_2 V_111 ;
int V_7 ;
V_107 = F_75 ( sizeof( * V_107 ) +
V_145 * sizeof( struct V_20 * ) ,
V_146 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_143 = V_63 -> V_143 ;
for ( V_7 = 0 ; V_7 < V_145 ; V_7 ++ ) {
V_107 -> V_109 [ V_7 ] = F_76 ( V_107 -> V_143 ,
V_146 , & V_111 ) ;
if ( ! V_107 -> V_109 [ V_7 ] ) {
F_68 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_40 ,
V_97 , V_7 , V_107 -> V_143 ) ;
goto V_147;
}
if ( V_7 == 0 )
V_107 -> V_106 = V_111 ;
else
V_107 -> V_109 [ V_7 - 1 ] -> V_19 = V_111 ;
V_107 -> V_110 ++ ;
}
return V_107 ;
V_147:
F_72 ( & V_107 -> V_117 ) ;
return NULL ;
}
static T_4 F_77 ( struct V_148 * V_135 )
{
struct V_123 * V_87 = F_78 ( V_135 -> V_63 ) ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
struct V_116 * V_149 = NULL ,
* V_117 = F_79 ( V_135 , struct V_116 , V_135 ) ;
T_4 V_136 ;
unsigned long V_90 ;
F_46 ( F_48 ( V_117 ) , V_135 -> V_90 ) ;
F_32 ( & V_87 -> V_134 , V_90 ) ;
V_136 = F_80 ( V_135 ) ;
if ( F_52 ( & V_87 -> V_138 ) && F_50 ( V_87 , V_117 ) ) {
F_81 ( & V_117 -> V_127 , & V_87 -> V_125 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_41 ,
V_97 , V_117 , V_136 ) ;
goto V_150;
}
if ( ! F_52 ( & V_87 -> V_138 ) ) {
V_149 = F_53 ( V_87 -> V_138 . V_126 ,
struct V_116 , V_127 ) ;
if ( V_63 -> V_101 || ! F_48 ( V_117 ) -> V_101 )
F_49 ( V_149 , V_117 ) ;
else
V_149 = NULL ;
}
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_42 ,
V_97 , V_117 , V_136 , V_149 ? L_43 : L_44 ) ;
F_81 ( & V_117 -> V_127 , & V_87 -> V_138 ) ;
V_63 -> V_101 |= F_48 ( V_117 ) -> V_101 ;
V_150:
F_33 ( & V_87 -> V_134 , V_90 ) ;
return V_136 ;
}
static void F_82 ( struct V_141 * V_142 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
struct V_116 * V_151 ;
unsigned long V_90 ;
F_32 ( & V_63 -> V_87 . V_134 , V_90 ) ;
if ( F_52 ( & V_63 -> V_87 . V_138 ) )
goto V_150;
V_151 = F_61 ( & V_63 -> V_87 . V_138 ,
struct V_116 , V_127 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_45 , V_97 , V_151 , V_151 -> V_135 . V_136 ) ;
F_83 ( & V_63 -> V_87 ) ;
if ( ! F_50 ( & V_63 -> V_87 , V_151 ) )
F_45 ( V_63 , F_48 ( V_151 ) ) ;
V_150:
F_33 ( & V_63 -> V_87 . V_134 , V_90 ) ;
}
static inline struct V_148 *
F_84 ( struct V_123 * V_87 , struct V_116 * V_117 ,
unsigned long V_152 )
{
struct V_148 * V_135 ;
struct V_84 * V_63 = F_79 ( V_87 , struct V_84 , V_87 ) ;
F_85 ( & V_117 -> V_127 ) ;
V_135 = F_86 ( V_87 , V_117 , V_152 ) ;
V_135 -> V_153 = F_77 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_46 , V_97 ,
V_87 , V_117 , V_117 -> V_135 . V_136 ,
V_152 ) ;
return V_135 ;
}
static void F_87 ( struct V_84 * V_63 ,
enum V_154 V_155 ,
T_1 * V_13 , T_1 * V_156 , T_1 * V_157 )
{
T_1 V_158 = 0 , V_159 = 0 ;
enum V_160 V_17 = V_161 ;
* V_13 = 0 ;
if ( V_155 == V_162 ) {
V_158 = V_63 -> V_163 . V_164 ;
V_17 = V_63 -> V_163 . V_165 ;
V_159 = V_63 -> V_163 . V_166 ;
* V_156 = V_159 ;
* V_13 |= V_167 ;
if ( V_63 -> V_8 <= V_11 )
* V_13 |= V_168 ;
}
if ( V_155 == V_169 ) {
V_158 = V_63 -> V_163 . V_170 ;
V_17 = V_63 -> V_163 . V_171 ;
V_159 = V_63 -> V_163 . V_172 ;
* V_157 = V_159 ;
* V_13 |= V_173 ;
if ( V_63 -> V_8 <= V_11 )
* V_13 |= V_174 ;
}
if ( V_155 == V_175 )
* V_13 |= V_113 | V_167 |
V_173 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_47 ,
V_97 , V_159 , V_158 , V_17 , V_155 ) ;
if ( V_17 == V_176 )
* V_13 |= V_177 ;
else if ( V_17 == V_178 )
* V_13 |= V_179 ;
else if ( V_17 == V_180 )
* V_13 |= V_112 ;
if ( V_158 == 8 )
* V_13 |= V_181 ;
else if ( V_158 == 16 )
* V_13 |= V_182 ;
else if ( V_158 == 32 )
* V_13 |= V_113 ;
if ( V_63 -> V_163 . V_183 )
V_63 -> V_8 = V_63 -> V_163 . V_183 ;
}
static struct V_148 *
F_88 ( struct V_141 * V_142 ,
T_2 V_184 , T_2 V_185 ,
T_5 V_186 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
struct V_105 * V_107 ;
struct V_20 * V_109 ;
T_1 V_13 ;
unsigned int V_7 , V_110 = 0 ;
T_5 V_187 ;
if ( ! V_142 || ! V_186 )
return NULL ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_48 ,
V_97 , ( unsigned long ) V_184 , ( unsigned long ) V_185 ,
V_186 , V_90 ) ;
F_87 ( V_63 , V_175 , & V_13 , NULL , NULL ) ;
V_110 = F_89 ( V_186 , V_188 ) ;
V_107 = F_74 ( V_63 , V_110 + 1 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_186 = V_186 ;
if ( ! F_90 ( V_185 , 1 << V_189 ) ||
! F_90 ( V_184 , 1 << V_189 ) )
V_107 -> V_101 = true ;
V_7 = 0 ;
do {
V_109 = V_107 -> V_109 [ V_7 ++ ] ;
V_187 = F_91 ( T_5 , V_186 , V_188 ) ;
V_109 -> V_13 = V_13 | ( V_32 & V_187 ) ;
V_109 -> V_23 = V_185 ;
V_109 -> V_24 = V_184 ;
V_186 -= V_187 ;
V_185 += V_187 ;
V_184 += V_187 ;
} while ( V_186 );
F_46 ( V_107 , V_90 ) ;
return F_84 ( & V_63 -> V_87 , & V_107 -> V_117 , V_90 ) ;
}
static struct V_148 *
F_92 ( struct V_141 * V_142 , struct V_190 * V_191 ,
unsigned int V_192 , enum V_154 V_155 ,
unsigned long V_90 , void * V_193 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
struct V_105 * V_107 ;
T_5 V_186 , V_194 ;
struct V_190 * V_195 ;
T_2 V_111 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_110 = 0 , V_7 , V_196 = 0 ;
if ( ( V_191 == NULL ) || ( V_192 == 0 ) )
return NULL ;
F_87 ( V_63 , V_155 , & V_13 , & V_23 , & V_24 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_49 , V_97 , V_155 , V_90 ) ;
F_93 (sgl, sg, sg_len, i)
V_110 += F_89 ( F_94 ( V_195 ) , V_188 ) ;
V_107 = F_74 ( V_63 , V_110 + 1 ) ;
if ( ! V_107 )
return NULL ;
F_93 (sgl, sg, sg_len, i) {
V_111 = F_95 ( V_195 ) ;
V_194 = F_94 ( V_195 ) ;
V_107 -> V_186 += V_194 ;
do {
V_186 = F_91 ( T_5 , V_194 , V_188 ) ;
if ( V_111 & 0x7 )
V_107 -> V_101 = true ;
V_107 -> V_109 [ V_196 ] -> V_13 =
V_13 | ( V_32 & V_186 ) ;
V_107 -> V_109 [ V_196 ] -> V_23 = V_23 ? V_23 : V_111 ;
V_107 -> V_109 [ V_196 ++ ] -> V_24 = V_24 ? V_24 : V_111 ;
V_111 += V_186 ;
V_194 -= V_186 ;
} while ( V_194 );
}
F_46 ( V_107 , V_90 ) ;
return F_84 ( & V_63 -> V_87 , & V_107 -> V_117 , V_90 ) ;
}
static struct V_148 *
F_96 ( struct V_141 * V_142 ,
T_2 V_197 , T_5 V_186 , T_5 V_198 ,
enum V_154 V_155 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
struct V_105 * V_107 ;
struct V_20 * * V_199 ;
T_2 V_111 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_110 = 0 ;
if ( ! V_142 || ! V_186 || ! V_198 )
return NULL ;
if ( ( V_155 != V_162 ) && ( V_155 != V_169 ) ) {
F_68 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_50 ) ;
return NULL ;
}
if ( V_186 % V_198 != 0 || V_198 > V_188 ||
! F_90 ( V_198 , 1 << V_189 ) )
return NULL ;
F_87 ( V_63 , V_155 , & V_13 , & V_23 , & V_24 ) ;
V_13 |= V_115 | ( V_32 | V_198 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_51 ,
V_97 , ( unsigned long ) V_197 , V_186 , V_198 , V_155 , V_90 ) ;
V_110 = F_89 ( V_198 , V_188 ) ;
V_110 *= F_89 ( V_186 , V_198 ) ;
V_107 = F_74 ( V_63 , V_110 + 1 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_200 = true ;
V_107 -> V_186 = V_186 ;
V_199 = V_107 -> V_109 ;
V_111 = V_197 ;
do {
V_199 [ 0 ] -> V_23 = V_23 ? V_23 : V_111 ;
V_199 [ 0 ] -> V_24 = V_24 ? V_24 : V_111 ;
V_199 [ 0 ] -> V_13 = V_13 ;
V_199 ++ ;
V_111 += V_198 ;
V_186 -= V_198 ;
} while ( V_186 );
F_46 ( V_107 , V_90 ) ;
return F_84 ( & V_63 -> V_87 , & V_107 -> V_117 , V_90 ) ;
}
static int F_97 ( struct V_141 * V_142 ,
struct V_201 * V_163 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
if ( ! V_142 )
return - V_202 ;
V_63 -> V_163 = * V_163 ;
return 0 ;
}
static int F_98 ( struct V_141 * V_142 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
struct V_116 * V_117 = NULL ;
unsigned long V_90 ;
struct V_4 * V_5 ;
F_99 ( V_203 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_52 , V_97 , & V_63 -> V_87 ) ;
F_32 ( & V_63 -> V_87 . V_134 , V_90 ) ;
F_100 ( & V_63 -> V_87 , & V_203 ) ;
F_101 (vd, &head, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_53 , V_97 ,
V_117 , V_117 -> V_135 . V_136 , F_47 ( V_117 ) ) ;
}
V_5 = V_63 -> V_5 ;
if ( V_5 ) {
F_44 ( V_63 -> V_5 ) ;
F_35 ( V_63 ) ;
V_63 -> V_5 = NULL ;
F_102 ( & V_57 -> V_91 ) ;
V_5 -> V_94 = NULL ;
F_103 ( & V_57 -> V_91 ) ;
}
F_33 ( & V_63 -> V_87 . V_134 , V_90 ) ;
F_104 ( & V_63 -> V_87 , & V_203 ) ;
return 0 ;
}
static unsigned int F_105 ( struct V_84 * V_63 ,
T_4 V_136 )
{
struct V_116 * V_117 = NULL ;
struct V_105 * V_107 = NULL ;
struct V_20 * V_109 = NULL ;
T_1 V_204 , V_205 , V_186 , V_206 , V_207 = 0 ;
unsigned long V_90 ;
bool V_208 = false ;
int V_7 ;
if ( ! V_63 -> V_5 )
return 0 ;
F_32 ( & V_63 -> V_87 . V_134 , V_90 ) ;
V_117 = F_106 ( & V_63 -> V_87 , V_136 ) ;
if ( ! V_117 )
goto V_150;
V_107 = F_48 ( V_117 ) ;
if ( V_107 -> V_109 [ 0 ] -> V_13 & V_173 )
V_204 = F_38 ( V_63 -> V_5 , V_54 ) ;
else
V_204 = F_38 ( V_63 -> V_5 , V_55 ) ;
F_107 () ;
if ( F_47 ( V_117 ) )
goto V_150;
for ( V_7 = 0 ; V_7 < V_107 -> V_110 - 1 ; V_7 ++ ) {
V_109 = V_107 -> V_109 [ V_7 ] ;
if ( V_107 -> V_109 [ 0 ] -> V_13 & V_173 )
V_205 = V_109 -> V_23 ;
else
V_205 = V_109 -> V_24 ;
V_186 = V_109 -> V_13 & V_32 ;
V_206 = V_205 + V_186 ;
if ( V_208 ) {
V_207 += V_186 ;
} else if ( V_204 >= V_205 && V_204 <= V_206 ) {
V_207 += V_206 - V_204 ;
V_208 = true ;
}
}
if ( ! V_208 )
V_207 = V_107 -> V_186 ;
V_150:
F_33 ( & V_63 -> V_87 . V_134 , V_90 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_54 ,
V_97 , V_117 , V_136 , V_107 , V_207 ) ;
return V_207 ;
}
static enum V_209 F_108 ( struct V_141 * V_142 ,
T_4 V_136 ,
struct V_210 * V_211 )
{
struct V_84 * V_63 = F_51 ( V_142 ) ;
enum V_209 V_140 ;
V_140 = F_109 ( V_142 , V_136 , V_211 ) ;
if ( F_110 ( V_211 && ( V_140 != V_212 ) ) )
F_111 ( V_211 , F_105 ( V_63 , V_136 ) ) ;
return V_140 ;
}
static void F_112 ( struct V_213 * V_214 )
{
struct V_84 * V_215 , * V_216 ;
F_58 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_59 ( & V_215 -> V_87 . V_63 . V_217 ) ;
F_113 ( & V_215 -> V_87 . V_218 ) ;
}
}
static int F_114 ( struct V_219 * V_220 )
{
struct V_56 * V_57 = F_115 ( V_220 ) ;
F_29 ( V_57 ) ;
F_112 ( & V_57 -> V_74 ) ;
F_116 ( & V_57 -> V_74 ) ;
return 0 ;
}
static int F_117 ( struct V_219 * V_220 ,
struct V_56 * V_57 ,
unsigned int V_221 )
{
int V_222 , V_130 , V_223 = 0 , V_7 , V_140 ;
struct V_4 * V_5 ;
V_222 = F_118 ( V_220 , 0 ) ;
if ( V_222 < 0 )
return V_222 ;
V_57 -> V_68 = F_119 ( & V_220 -> V_75 , V_221 ,
sizeof( V_57 -> V_68 [ 0 ] ) , V_80 ) ;
if ( ! V_57 -> V_68 )
return - V_144 ;
for ( V_7 = 0 ; V_7 < V_221 ; V_7 ++ )
if ( F_118 ( V_220 , V_7 ) > 0 )
V_223 ++ ;
for ( V_7 = 0 ; V_7 < V_221 ; V_7 ++ ) {
V_5 = & V_57 -> V_68 [ V_7 ] ;
V_5 -> V_10 = V_57 -> V_10 ;
V_5 -> V_9 = V_7 ;
V_130 = F_118 ( V_220 , V_7 ) ;
if ( ( V_223 > 1 ) && ( V_130 > 0 ) )
V_140 = F_120 ( & V_220 -> V_75 , V_130 ,
F_57 ,
V_224 , L_55 , V_5 ) ;
if ( ( V_223 == 1 ) && ( V_7 == 0 ) )
V_140 = F_120 ( & V_220 -> V_75 , V_222 ,
F_62 ,
V_224 , L_55 , V_57 ) ;
if ( V_140 ) {
F_68 ( V_57 -> V_74 . V_75 ,
L_56 , V_97 ,
V_130 , V_140 ) ;
return V_140 ;
}
}
return 0 ;
}
static struct V_141 * F_121 ( struct V_225 * V_226 ,
struct V_227 * V_228 )
{
struct V_56 * V_229 = V_228 -> V_230 ;
struct V_141 * V_63 ;
V_63 = F_122 ( & V_229 -> V_74 ) ;
if ( ! V_63 )
return NULL ;
F_51 ( V_63 ) -> V_8 = V_226 -> args [ 0 ] ;
F_51 ( V_63 ) -> V_86 = V_226 -> args [ 1 ] ;
return V_63 ;
}
static int F_123 ( struct V_219 * V_220 ,
struct V_56 * V_57 ,
unsigned int V_231 )
{
int V_140 ;
unsigned int V_7 ;
struct V_84 * V_215 ;
V_57 -> V_58 = V_231 ;
F_85 ( & V_57 -> V_74 . V_232 ) ;
V_57 -> V_74 . V_233 = F_64 ;
V_57 -> V_74 . V_234 = F_69 ;
V_57 -> V_74 . V_235 = F_108 ;
V_57 -> V_74 . V_236 = F_82 ;
V_57 -> V_74 . V_237 = F_97 ;
V_57 -> V_74 . V_238 = F_98 ;
if ( V_220 -> V_75 . V_239 )
F_124 ( & V_220 -> V_75 , V_220 -> V_75 . V_239 ) ;
else
F_124 ( & V_220 -> V_75 , F_125 ( 32 ) ) ;
V_140 = F_117 ( V_220 , V_57 , V_231 ) ;
if ( V_140 )
return V_140 ;
for ( V_7 = 0 ; V_7 < V_231 ; V_7 ++ ) {
V_215 = F_126 ( & V_220 -> V_75 , sizeof( * V_215 ) , V_80 ) ;
if ( ! V_215 )
return - V_144 ;
V_215 -> V_87 . V_240 = F_72 ;
F_127 ( & V_215 -> V_87 , & V_57 -> V_74 ) ;
}
return F_128 ( & V_57 -> V_74 ) ;
}
static int F_129 ( struct V_219 * V_220 )
{
struct V_56 * V_57 ;
const struct V_241 * V_242 ;
struct V_243 * V_244 = F_130 ( & V_220 -> V_75 ) ;
struct V_245 * V_246 ;
int V_140 , V_247 = 0 ;
const enum V_160 V_248 =
V_176 | V_178 |
V_180 ;
V_57 = F_126 ( & V_220 -> V_75 , sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return - V_144 ;
F_131 ( & V_57 -> V_91 ) ;
V_246 = F_132 ( V_220 , V_249 , 0 ) ;
V_57 -> V_10 = F_133 ( & V_220 -> V_75 , V_246 ) ;
if ( F_25 ( V_57 -> V_10 ) )
return F_134 ( V_57 -> V_10 ) ;
V_242 = F_135 ( V_250 , & V_220 -> V_75 ) ;
if ( V_242 )
F_136 ( V_220 -> V_75 . V_251 , L_57 ,
& V_247 ) ;
else if ( V_244 && V_244 -> V_247 )
V_247 = V_244 -> V_247 ;
else
V_247 = 32 ;
F_137 ( V_252 , V_57 -> V_74 . V_253 ) ;
F_137 ( V_254 , V_57 -> V_74 . V_253 ) ;
F_137 ( V_255 , V_57 -> V_74 . V_253 ) ;
F_137 ( V_256 , V_57 -> V_74 . V_253 ) ;
V_57 -> V_74 . V_257 = F_88 ;
V_57 -> V_74 . V_258 = F_92 ;
V_57 -> V_74 . V_259 = F_96 ;
V_57 -> V_74 . V_260 = V_189 ;
V_57 -> V_74 . V_261 = V_248 ;
V_57 -> V_74 . V_262 = V_248 ;
V_57 -> V_74 . V_263 = F_14 ( V_169 ) | F_14 ( V_162 ) ;
V_57 -> V_74 . V_264 = V_265 ;
V_57 -> V_74 . V_75 = & V_220 -> V_75 ;
V_140 = F_123 ( V_220 , V_57 , V_247 ) ;
if ( V_140 ) {
F_68 ( V_57 -> V_74 . V_75 , L_58 ) ;
return V_140 ;
}
if ( V_220 -> V_75 . V_251 ) {
V_140 = F_138 ( V_220 -> V_75 . V_251 ,
F_121 , V_57 ) ;
if ( V_140 < 0 ) {
F_68 ( V_57 -> V_74 . V_75 ,
L_59 ) ;
return V_140 ;
}
}
F_139 ( V_220 , V_57 ) ;
F_23 ( V_57 ) ;
F_140 ( V_57 -> V_74 . V_75 , L_60 , V_247 ) ;
return 0 ;
}
bool F_141 ( struct V_141 * V_63 , void * V_266 )
{
struct V_84 * V_215 = F_51 ( V_63 ) ;
struct V_267 * V_3 = V_266 ;
if ( V_63 -> V_88 -> V_75 -> V_268 != & V_269 . V_268 )
return false ;
V_215 -> V_8 = V_3 -> V_8 ;
V_215 -> V_86 = V_3 -> V_86 ;
return true ;
}
int F_142 ( int V_270 )
{
if ( V_95 & ( F_14 ( V_270 ) ) )
return - V_271 ;
V_93 ^= F_14 ( V_270 ) ;
return 0 ;
}
