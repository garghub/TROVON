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
F_43 ( V_63 -> V_5 , V_21 -> V_107 , V_22 ) ;
F_41 ( V_63 -> V_5 , V_63 -> V_102 ) ;
}
static void F_46 ( struct V_106 * V_108 ,
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
V_108 -> V_110 [ V_108 -> V_111 - 2 ] -> V_19 = V_108 -> V_107 ;
}
static bool F_47 ( struct V_118 * V_119 )
{
struct V_106 * V_108 = F_48 ( V_119 ) ;
struct V_20 * V_109 =
V_108 -> V_110 [ V_108 -> V_111 - 1 ] ;
return V_109 -> V_24 != ( V_109 -> V_23 + 8 ) ;
}
static void F_49 ( struct V_118 * V_120 ,
struct V_118 * V_121 )
{
struct V_106 * V_122 = F_48 ( V_120 ) ;
struct V_106 * V_123 = F_48 ( V_121 ) ;
T_2 V_124 ;
V_124 = V_123 -> V_107 ;
V_122 -> V_110 [ V_122 -> V_111 - 1 ] -> V_19 = V_124 ;
}
static bool F_50 ( struct V_125 * V_87 ,
struct V_118 * V_119 )
{
struct V_118 * V_126 = NULL ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
if ( F_37 ( V_63 ) ) {
F_40 ( F_52 ( & V_87 -> V_127 ) ) ;
if ( ! F_39 ( V_63 ) &&
F_48 ( V_119 ) -> V_102 )
return false ;
V_126 = F_53 ( V_87 -> V_127 . V_128 ,
struct V_118 , V_129 ) ;
F_49 ( V_126 , V_119 ) ;
if ( F_37 ( V_63 ) || F_47 ( V_126 ) )
return true ;
}
return false ;
}
static unsigned int F_54 ( struct V_4 * V_5 )
{
T_1 V_34 ;
T_1 V_130 = F_55 ( V_5 -> V_10 + V_131 ) ;
if ( ! ( V_130 & F_14 ( V_5 -> V_9 ) ) )
return V_100 ;
V_34 = F_38 ( V_5 , V_36 ) ;
F_43 ( V_5 , V_34 , V_36 ) ;
if ( ( V_34 & V_105 ) && ( V_5 -> V_94 ) )
F_56 ( & V_5 -> V_94 -> V_87 . V_63 . V_75 -> V_88 ,
L_36 ,
V_97 , & V_5 -> V_94 ) ;
return V_34 & ~ V_100 ;
}
static T_3 F_57 ( int V_132 , void * V_133 )
{
struct V_4 * V_5 = V_133 ;
struct V_84 * V_63 = V_5 -> V_94 ;
struct V_118 * V_119 , * V_134 ;
unsigned int V_34 ;
unsigned long V_90 ;
F_40 ( ! V_63 ) ;
V_34 = F_54 ( V_5 ) ;
if ( V_34 & V_100 )
return V_135 ;
F_32 ( & V_63 -> V_87 . V_136 , V_90 ) ;
F_58 (vd, tmp, &chan->vc.desc_issued, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_37 ,
V_97 , V_119 , V_119 -> V_137 . V_138 , F_47 ( V_119 ) ) ;
if ( F_48 ( V_119 ) -> V_117 ) {
F_59 ( V_119 ) ;
break;
}
if ( F_47 ( V_119 ) ) {
F_60 ( & V_119 -> V_129 ) ;
F_61 ( V_119 ) ;
} else {
break;
}
}
if ( V_34 & V_139 ) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_38 ,
V_97 ,
F_52 ( & V_63 -> V_87 . V_140 ) ,
F_52 ( & V_63 -> V_87 . V_127 ) ) ;
F_42 ( V_5 , V_34 & ~ V_103 , V_36 ) ;
if ( F_52 ( & V_63 -> V_87 . V_127 ) ) {
V_63 -> V_102 =
! F_52 ( & V_63 -> V_87 . V_140 ) ;
} else {
V_119 = F_62 ( & V_63 -> V_87 . V_127 ,
struct V_118 , V_129 ) ;
F_45 ( V_63 , F_48 ( V_119 ) ) ;
}
}
F_33 ( & V_63 -> V_87 . V_136 , V_90 ) ;
return V_141 ;
}
static T_3 F_63 ( int V_132 , void * V_133 )
{
struct V_56 * V_57 = V_133 ;
struct V_4 * V_5 ;
T_1 V_130 = F_55 ( V_57 -> V_10 + V_131 ) ;
int V_7 , V_142 = V_135 ;
while ( V_130 ) {
V_7 = F_64 ( V_130 ) ;
V_130 &= ( V_130 - 1 ) ;
V_5 = & V_57 -> V_68 [ V_7 ] ;
if ( ( V_7 < 32 ) && ( V_93 & F_14 ( V_7 ) ) )
continue;
if ( F_57 ( V_132 , V_5 ) == V_141 )
V_142 = V_141 ;
}
return V_142 ;
}
static int F_65 ( struct V_143 * V_144 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
if ( V_63 -> V_145 )
return 1 ;
V_63 -> V_145 = F_66 ( F_67 ( V_144 ) ,
V_57 -> V_74 . V_75 ,
sizeof( struct V_20 ) ,
F_68 ( struct V_20 ) ,
0 ) ;
if ( ! V_63 -> V_145 ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_39 ,
V_97 ) ;
return - V_146 ;
}
return 1 ;
}
static void F_70 ( struct V_143 * V_144 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
F_71 ( & V_63 -> V_87 ) ;
F_72 ( V_63 -> V_145 ) ;
V_63 -> V_145 = NULL ;
}
static void F_73 ( struct V_118 * V_119 )
{
int V_7 ;
T_2 V_112 ;
struct V_106 * V_108 = F_48 ( V_119 ) ;
F_40 ( V_108 -> V_111 == 0 ) ;
for ( V_7 = V_108 -> V_111 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 )
V_112 = V_108 -> V_110 [ V_7 - 1 ] -> V_19 ;
else
V_112 = V_108 -> V_107 ;
F_74 ( V_108 -> V_145 ,
V_108 -> V_110 [ V_7 ] , V_112 ) ;
}
V_108 -> V_111 = 0 ;
F_27 ( V_108 ) ;
}
static struct V_106 *
F_75 ( struct V_84 * V_63 , unsigned int V_147 )
{
struct V_106 * V_108 ;
T_2 V_112 ;
int V_7 ;
V_108 = F_76 ( sizeof( * V_108 ) +
V_147 * sizeof( struct V_20 * ) ,
V_148 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_145 = V_63 -> V_145 ;
for ( V_7 = 0 ; V_7 < V_147 ; V_7 ++ ) {
V_108 -> V_110 [ V_7 ] = F_77 ( V_108 -> V_145 ,
V_148 , & V_112 ) ;
if ( ! V_108 -> V_110 [ V_7 ] ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_40 ,
V_97 , V_7 , V_108 -> V_145 ) ;
goto V_149;
}
if ( V_7 == 0 )
V_108 -> V_107 = V_112 ;
else
V_108 -> V_110 [ V_7 - 1 ] -> V_19 = V_112 ;
V_108 -> V_111 ++ ;
}
return V_108 ;
V_149:
F_73 ( & V_108 -> V_119 ) ;
return NULL ;
}
static T_4 F_78 ( struct V_150 * V_137 )
{
struct V_125 * V_87 = F_79 ( V_137 -> V_63 ) ;
struct V_84 * V_63 = F_51 ( & V_87 -> V_63 ) ;
struct V_118 * V_151 = NULL ,
* V_119 = F_80 ( V_137 , struct V_118 , V_137 ) ;
T_4 V_138 ;
unsigned long V_90 ;
F_46 ( F_48 ( V_119 ) , V_137 -> V_90 ) ;
F_32 ( & V_87 -> V_136 , V_90 ) ;
V_138 = F_81 ( V_137 ) ;
if ( F_52 ( & V_87 -> V_140 ) && F_50 ( V_87 , V_119 ) ) {
F_82 ( & V_119 -> V_129 , & V_87 -> V_127 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_41 ,
V_97 , V_119 , V_138 ) ;
goto V_152;
}
if ( ! F_52 ( & V_87 -> V_140 ) ) {
V_151 = F_53 ( V_87 -> V_140 . V_128 ,
struct V_118 , V_129 ) ;
if ( V_63 -> V_102 || ! F_48 ( V_119 ) -> V_102 )
F_49 ( V_151 , V_119 ) ;
else
V_151 = NULL ;
}
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_42 ,
V_97 , V_119 , V_138 , V_151 ? L_43 : L_44 ) ;
F_82 ( & V_119 -> V_129 , & V_87 -> V_140 ) ;
V_63 -> V_102 |= F_48 ( V_119 ) -> V_102 ;
V_152:
F_33 ( & V_87 -> V_136 , V_90 ) ;
return V_138 ;
}
static void F_83 ( struct V_143 * V_144 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
struct V_118 * V_153 ;
unsigned long V_90 ;
F_32 ( & V_63 -> V_87 . V_136 , V_90 ) ;
if ( F_52 ( & V_63 -> V_87 . V_140 ) )
goto V_152;
V_153 = F_62 ( & V_63 -> V_87 . V_140 ,
struct V_118 , V_129 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_45 , V_97 , V_153 , V_153 -> V_137 . V_138 ) ;
F_84 ( & V_63 -> V_87 ) ;
if ( ! F_50 ( & V_63 -> V_87 , V_153 ) )
F_45 ( V_63 , F_48 ( V_153 ) ) ;
V_152:
F_33 ( & V_63 -> V_87 . V_136 , V_90 ) ;
}
static inline struct V_150 *
F_85 ( struct V_125 * V_87 , struct V_118 * V_119 ,
unsigned long V_154 )
{
struct V_150 * V_137 ;
struct V_84 * V_63 = F_80 ( V_87 , struct V_84 , V_87 ) ;
F_86 ( & V_119 -> V_129 ) ;
V_137 = F_87 ( V_87 , V_119 , V_154 ) ;
V_137 -> V_155 = F_78 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_46 , V_97 ,
V_87 , V_119 , V_119 -> V_137 . V_138 ,
V_154 ) ;
return V_137 ;
}
static void F_88 ( struct V_84 * V_63 ,
enum V_156 V_157 ,
T_1 * V_13 , T_1 * V_158 , T_1 * V_159 )
{
T_1 V_160 = 0 , V_161 = 0 ;
enum V_162 V_17 = V_163 ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
* V_13 = 0 ;
if ( V_157 == V_164 ) {
V_160 = V_63 -> V_165 . V_166 ;
V_17 = V_63 -> V_165 . V_167 ;
V_161 = V_63 -> V_165 . V_168 ;
* V_158 = V_161 ;
* V_13 |= V_169 ;
if ( V_63 -> V_8 <= V_57 -> V_99 )
* V_13 |= V_170 ;
}
if ( V_157 == V_171 ) {
V_160 = V_63 -> V_165 . V_172 ;
V_17 = V_63 -> V_165 . V_173 ;
V_161 = V_63 -> V_165 . V_174 ;
* V_159 = V_161 ;
* V_13 |= V_175 ;
if ( V_63 -> V_8 <= V_57 -> V_99 )
* V_13 |= V_176 ;
}
if ( V_157 == V_177 )
* V_13 |= V_114 | V_169 |
V_175 ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_47 ,
V_97 , V_161 , V_160 , V_17 , V_157 ) ;
if ( V_17 == V_178 )
* V_13 |= V_179 ;
else if ( V_17 == V_180 )
* V_13 |= V_181 ;
else if ( V_17 == V_182 )
* V_13 |= V_113 ;
if ( V_160 == 8 )
* V_13 |= V_183 ;
else if ( V_160 == 16 )
* V_13 |= V_184 ;
else if ( V_160 == 32 )
* V_13 |= V_114 ;
if ( V_63 -> V_165 . V_185 )
V_63 -> V_8 = V_63 -> V_165 . V_185 ;
}
static struct V_150 *
F_89 ( struct V_143 * V_144 ,
T_2 V_186 , T_2 V_187 ,
T_5 V_188 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
struct V_106 * V_108 ;
struct V_20 * V_110 ;
T_1 V_13 ;
unsigned int V_7 , V_111 = 0 ;
T_5 V_189 ;
if ( ! V_144 || ! V_188 )
return NULL ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_48 ,
V_97 , ( unsigned long ) V_186 , ( unsigned long ) V_187 ,
V_188 , V_90 ) ;
F_88 ( V_63 , V_177 , & V_13 , NULL , NULL ) ;
V_111 = F_90 ( V_188 , V_190 ) ;
V_108 = F_75 ( V_63 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_188 = V_188 ;
if ( ! F_91 ( V_187 , 1 << V_191 ) ||
! F_91 ( V_186 , 1 << V_191 ) )
V_108 -> V_102 = true ;
V_7 = 0 ;
do {
V_110 = V_108 -> V_110 [ V_7 ++ ] ;
V_189 = F_92 ( T_5 , V_188 , V_190 ) ;
V_110 -> V_13 = V_13 | ( V_32 & V_189 ) ;
V_110 -> V_23 = V_187 ;
V_110 -> V_24 = V_186 ;
V_188 -= V_189 ;
V_187 += V_189 ;
V_186 += V_189 ;
} while ( V_188 );
F_46 ( V_108 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_108 -> V_119 , V_90 ) ;
}
static struct V_150 *
F_93 ( struct V_143 * V_144 , struct V_192 * V_193 ,
unsigned int V_194 , enum V_156 V_157 ,
unsigned long V_90 , void * V_195 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
struct V_106 * V_108 ;
T_5 V_188 , V_196 ;
struct V_192 * V_197 ;
T_2 V_112 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_111 = 0 , V_7 , V_198 = 0 ;
if ( ( V_193 == NULL ) || ( V_194 == 0 ) )
return NULL ;
F_88 ( V_63 , V_157 , & V_13 , & V_23 , & V_24 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_49 , V_97 , V_157 , V_90 ) ;
F_94 (sgl, sg, sg_len, i)
V_111 += F_90 ( F_95 ( V_197 ) , V_190 ) ;
V_108 = F_75 ( V_63 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
F_94 (sgl, sg, sg_len, i) {
V_112 = F_96 ( V_197 ) ;
V_196 = F_95 ( V_197 ) ;
V_108 -> V_188 += V_196 ;
do {
V_188 = F_92 ( T_5 , V_196 , V_190 ) ;
if ( V_112 & 0x7 )
V_108 -> V_102 = true ;
V_108 -> V_110 [ V_198 ] -> V_13 =
V_13 | ( V_32 & V_188 ) ;
V_108 -> V_110 [ V_198 ] -> V_23 = V_23 ? V_23 : V_112 ;
V_108 -> V_110 [ V_198 ++ ] -> V_24 = V_24 ? V_24 : V_112 ;
V_112 += V_188 ;
V_196 -= V_188 ;
} while ( V_196 );
}
F_46 ( V_108 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_108 -> V_119 , V_90 ) ;
}
static struct V_150 *
F_97 ( struct V_143 * V_144 ,
T_2 V_199 , T_5 V_188 , T_5 V_200 ,
enum V_156 V_157 , unsigned long V_90 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
struct V_106 * V_108 ;
struct V_20 * * V_201 ;
T_2 V_112 ;
T_1 V_13 , V_23 = 0 , V_24 = 0 ;
unsigned int V_111 = 0 ;
if ( ! V_144 || ! V_188 || ! V_200 )
return NULL ;
if ( ( V_157 != V_164 ) && ( V_157 != V_171 ) ) {
F_69 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_50 ) ;
return NULL ;
}
if ( V_188 % V_200 != 0 || V_200 > V_190 ||
! F_91 ( V_200 , 1 << V_191 ) )
return NULL ;
F_88 ( V_63 , V_157 , & V_13 , & V_23 , & V_24 ) ;
V_13 |= V_116 | ( V_32 & V_200 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_51 ,
V_97 , ( unsigned long ) V_199 , V_188 , V_200 , V_157 , V_90 ) ;
V_111 = F_90 ( V_200 , V_190 ) ;
V_111 *= F_90 ( V_188 , V_200 ) ;
V_108 = F_75 ( V_63 , V_111 + 1 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_117 = true ;
V_108 -> V_188 = V_188 ;
V_201 = V_108 -> V_110 ;
V_112 = V_199 ;
do {
V_201 [ 0 ] -> V_23 = V_23 ? V_23 : V_112 ;
V_201 [ 0 ] -> V_24 = V_24 ? V_24 : V_112 ;
V_201 [ 0 ] -> V_13 = V_13 ;
V_201 ++ ;
V_112 += V_200 ;
V_188 -= V_200 ;
} while ( V_188 );
F_46 ( V_108 , V_90 ) ;
return F_85 ( & V_63 -> V_87 , & V_108 -> V_119 , V_90 ) ;
}
static int F_98 ( struct V_143 * V_144 ,
struct V_202 * V_165 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
if ( ! V_144 )
return - V_203 ;
V_63 -> V_165 = * V_165 ;
return 0 ;
}
static int F_99 ( struct V_143 * V_144 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
struct V_56 * V_57 = F_31 ( V_63 -> V_87 . V_63 . V_88 ) ;
struct V_118 * V_119 = NULL ;
unsigned long V_90 ;
struct V_4 * V_5 ;
F_100 ( V_204 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_52 , V_97 , & V_63 -> V_87 ) ;
F_32 ( & V_63 -> V_87 . V_136 , V_90 ) ;
F_101 ( & V_63 -> V_87 , & V_204 ) ;
F_102 (vd, &head, node) {
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_53 , V_97 ,
V_119 , V_119 -> V_137 . V_138 , F_47 ( V_119 ) ) ;
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
F_33 ( & V_63 -> V_87 . V_136 , V_90 ) ;
F_105 ( & V_63 -> V_87 , & V_204 ) ;
return 0 ;
}
static unsigned int F_106 ( struct V_84 * V_63 ,
T_4 V_138 )
{
struct V_118 * V_119 = NULL ;
struct V_106 * V_108 = NULL ;
struct V_20 * V_110 = NULL ;
T_1 V_205 , V_206 , V_188 , V_207 , V_208 = 0 ;
unsigned long V_90 ;
bool V_209 = false ;
int V_7 ;
if ( ! V_63 -> V_5 )
return 0 ;
F_32 ( & V_63 -> V_87 . V_136 , V_90 ) ;
V_119 = F_107 ( & V_63 -> V_87 , V_138 ) ;
if ( ! V_119 )
goto V_152;
V_108 = F_48 ( V_119 ) ;
if ( V_108 -> V_110 [ 0 ] -> V_13 & V_175 )
V_205 = F_38 ( V_63 -> V_5 , V_54 ) ;
else
V_205 = F_38 ( V_63 -> V_5 , V_55 ) ;
F_108 () ;
if ( F_47 ( V_119 ) )
goto V_152;
for ( V_7 = 0 ; V_7 < V_108 -> V_111 - 1 ; V_7 ++ ) {
V_110 = V_108 -> V_110 [ V_7 ] ;
if ( V_108 -> V_110 [ 0 ] -> V_13 & V_175 )
V_206 = V_110 -> V_23 ;
else
V_206 = V_110 -> V_24 ;
V_188 = V_110 -> V_13 & V_32 ;
V_207 = V_206 + V_188 ;
if ( V_209 ) {
V_208 += V_188 ;
} else if ( V_205 >= V_206 && V_205 <= V_207 ) {
V_208 += V_207 - V_205 ;
V_209 = true ;
}
}
if ( ! V_209 )
V_208 = V_108 -> V_188 ;
V_152:
F_33 ( & V_63 -> V_87 . V_136 , V_90 ) ;
F_34 ( & V_63 -> V_87 . V_63 . V_75 -> V_88 ,
L_54 ,
V_97 , V_119 , V_138 , V_108 , V_208 ) ;
return V_208 ;
}
static enum V_210 F_109 ( struct V_143 * V_144 ,
T_4 V_138 ,
struct V_211 * V_212 )
{
struct V_84 * V_63 = F_51 ( V_144 ) ;
enum V_210 V_142 ;
V_142 = F_110 ( V_144 , V_138 , V_212 ) ;
if ( F_111 ( V_212 && ( V_142 != V_213 ) ) )
F_112 ( V_212 , F_106 ( V_63 , V_138 ) ) ;
return V_142 ;
}
static void F_113 ( struct V_214 * V_215 )
{
struct V_84 * V_216 , * V_217 ;
F_58 (c, cn, &dmadev->channels,
vc.chan.device_node) {
F_60 ( & V_216 -> V_87 . V_63 . V_218 ) ;
F_114 ( & V_216 -> V_87 . V_219 ) ;
}
}
static int F_115 ( struct V_220 * V_221 )
{
struct V_56 * V_57 = F_116 ( V_221 ) ;
F_29 ( V_57 ) ;
F_113 ( & V_57 -> V_74 ) ;
F_117 ( & V_57 -> V_74 ) ;
return 0 ;
}
static int F_118 ( struct V_220 * V_221 ,
struct V_56 * V_57 ,
unsigned int V_222 )
{
int V_223 , V_132 , V_224 = 0 , V_7 , V_142 ;
struct V_4 * V_5 ;
V_223 = F_119 ( V_221 , 0 ) ;
if ( V_223 < 0 )
return V_223 ;
V_57 -> V_68 = F_120 ( & V_221 -> V_75 , V_222 ,
sizeof( V_57 -> V_68 [ 0 ] ) , V_80 ) ;
if ( ! V_57 -> V_68 )
return - V_146 ;
for ( V_7 = 0 ; V_7 < V_222 ; V_7 ++ )
if ( F_119 ( V_221 , V_7 ) > 0 )
V_224 ++ ;
for ( V_7 = 0 ; V_7 < V_222 ; V_7 ++ ) {
V_5 = & V_57 -> V_68 [ V_7 ] ;
V_5 -> V_10 = V_57 -> V_10 ;
V_5 -> V_9 = V_7 ;
V_132 = F_119 ( V_221 , V_7 ) ;
if ( ( V_224 > 1 ) && ( V_132 > 0 ) )
V_142 = F_121 ( & V_221 -> V_75 , V_132 ,
F_57 ,
V_225 , L_55 , V_5 ) ;
if ( ( V_224 == 1 ) && ( V_7 == 0 ) )
V_142 = F_121 ( & V_221 -> V_75 , V_223 ,
F_63 ,
V_225 , L_55 , V_57 ) ;
if ( V_142 ) {
F_69 ( V_57 -> V_74 . V_75 ,
L_56 , V_97 ,
V_132 , V_142 ) ;
return V_142 ;
}
}
return 0 ;
}
static struct V_143 * F_122 ( struct V_226 * V_227 ,
struct V_228 * V_229 )
{
struct V_56 * V_230 = V_229 -> V_231 ;
struct V_143 * V_63 ;
V_63 = F_123 ( & V_230 -> V_74 ) ;
if ( ! V_63 )
return NULL ;
F_51 ( V_63 ) -> V_8 = V_227 -> args [ 0 ] ;
F_51 ( V_63 ) -> V_86 = V_227 -> args [ 1 ] ;
return V_63 ;
}
static int F_124 ( struct V_220 * V_221 ,
struct V_56 * V_57 ,
unsigned int V_232 ,
unsigned int V_99 )
{
int V_142 ;
unsigned int V_7 ;
struct V_84 * V_216 ;
V_57 -> V_58 = V_232 ;
V_57 -> V_99 = V_99 ;
F_86 ( & V_57 -> V_74 . V_233 ) ;
V_57 -> V_74 . V_234 = F_65 ;
V_57 -> V_74 . V_235 = F_70 ;
V_57 -> V_74 . V_236 = F_109 ;
V_57 -> V_74 . V_237 = F_83 ;
V_57 -> V_74 . V_238 = F_98 ;
V_57 -> V_74 . V_239 = F_99 ;
if ( V_221 -> V_75 . V_240 )
F_125 ( & V_221 -> V_75 , V_221 -> V_75 . V_240 ) ;
else
F_125 ( & V_221 -> V_75 , F_126 ( 32 ) ) ;
V_142 = F_118 ( V_221 , V_57 , V_232 ) ;
if ( V_142 )
return V_142 ;
for ( V_7 = 0 ; V_7 < V_232 ; V_7 ++ ) {
V_216 = F_127 ( & V_221 -> V_75 , sizeof( * V_216 ) , V_80 ) ;
if ( ! V_216 )
return - V_146 ;
V_216 -> V_87 . V_241 = F_73 ;
F_128 ( & V_216 -> V_87 , & V_57 -> V_74 ) ;
}
return F_129 ( & V_57 -> V_74 ) ;
}
static int F_130 ( struct V_220 * V_221 )
{
struct V_56 * V_57 ;
const struct V_242 * V_243 ;
struct V_244 * V_245 = F_131 ( & V_221 -> V_75 ) ;
struct V_246 * V_247 ;
int V_142 , V_248 = 0 , V_249 = 0 ;
const enum V_162 V_250 =
V_178 | V_180 |
V_182 ;
V_57 = F_127 ( & V_221 -> V_75 , sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return - V_146 ;
F_132 ( & V_57 -> V_91 ) ;
V_247 = F_133 ( V_221 , V_251 , 0 ) ;
V_57 -> V_10 = F_134 ( & V_221 -> V_75 , V_247 ) ;
if ( F_25 ( V_57 -> V_10 ) )
return F_135 ( V_57 -> V_10 ) ;
V_243 = F_136 ( V_252 , & V_221 -> V_75 ) ;
if ( V_243 ) {
F_137 ( V_221 -> V_75 . V_253 , L_57 ,
& V_248 ) ;
V_142 = F_137 ( V_221 -> V_75 . V_253 , L_58 ,
& V_249 ) ;
if ( V_142 ) {
F_56 ( V_57 -> V_74 . V_75 ,
L_59 ,
V_142 ) ;
V_249 = 32 ;
} ;
} else if ( V_245 && V_245 -> V_248 ) {
V_248 = V_245 -> V_248 ;
V_249 = V_245 -> V_249 ;
} else {
V_248 = 32 ;
}
F_138 ( V_254 , V_57 -> V_74 . V_255 ) ;
F_138 ( V_256 , V_57 -> V_74 . V_255 ) ;
F_138 ( V_257 , V_57 -> V_74 . V_255 ) ;
F_138 ( V_258 , V_57 -> V_74 . V_255 ) ;
V_57 -> V_74 . V_259 = F_89 ;
V_57 -> V_74 . V_260 = F_93 ;
V_57 -> V_74 . V_261 = F_97 ;
V_57 -> V_74 . V_262 = V_191 ;
V_57 -> V_74 . V_263 = V_250 ;
V_57 -> V_74 . V_264 = V_250 ;
V_57 -> V_74 . V_265 = F_14 ( V_171 ) | F_14 ( V_164 ) ;
V_57 -> V_74 . V_266 = V_267 ;
V_57 -> V_74 . V_268 = true ;
V_57 -> V_74 . V_75 = & V_221 -> V_75 ;
V_142 = F_124 ( V_221 , V_57 , V_248 , V_249 ) ;
if ( V_142 ) {
F_69 ( V_57 -> V_74 . V_75 , L_60 ) ;
return V_142 ;
}
if ( V_221 -> V_75 . V_253 ) {
V_142 = F_139 ( V_221 -> V_75 . V_253 ,
F_122 , V_57 ) ;
if ( V_142 < 0 ) {
F_69 ( V_57 -> V_74 . V_75 ,
L_61 ) ;
return V_142 ;
}
}
F_140 ( V_221 , V_57 ) ;
F_23 ( V_57 ) ;
F_141 ( V_57 -> V_74 . V_75 , L_62 ,
V_248 , V_249 ) ;
return 0 ;
}
bool F_142 ( struct V_143 * V_63 , void * V_269 )
{
struct V_84 * V_216 = F_51 ( V_63 ) ;
struct V_270 * V_3 = V_269 ;
if ( V_63 -> V_88 -> V_75 -> V_271 != & V_272 . V_271 )
return false ;
V_216 -> V_8 = V_3 -> V_8 ;
V_216 -> V_86 = V_3 -> V_86 ;
return true ;
}
int F_143 ( int V_273 )
{
if ( V_95 & ( F_14 ( V_273 ) ) )
return - V_274 ;
V_93 ^= F_14 ( V_273 ) ;
return 0 ;
}
