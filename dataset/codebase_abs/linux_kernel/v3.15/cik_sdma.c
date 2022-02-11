T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_5 , V_6 ;
if ( V_2 -> V_7 . V_8 ) {
V_5 = V_2 -> V_7 . V_7 [ V_4 -> V_9 / 4 ] ;
} else {
if ( V_4 -> V_10 == V_11 )
V_6 = V_12 + V_13 ;
else
V_6 = V_12 + V_14 ;
V_5 = F_2 ( V_6 ) ;
}
return ( V_5 & 0x3fffc ) >> 2 ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_6 ;
if ( V_4 -> V_10 == V_11 )
V_6 = V_15 + V_13 ;
else
V_6 = V_15 + V_14 ;
return ( F_2 ( V_6 ) & 0x3fffc ) >> 2 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_6 ;
if ( V_4 -> V_10 == V_11 )
V_6 = V_15 + V_13 ;
else
V_6 = V_15 + V_14 ;
F_5 ( V_6 , ( V_4 -> V_16 << 2 ) & 0x3fffc ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_18 -> V_4 ] ;
T_2 V_19 = ( V_18 -> V_20 ? V_18 -> V_20 -> V_21 : 0 ) & 0xf ;
if ( V_2 -> V_7 . V_8 ) {
T_2 V_22 = V_4 -> V_16 + 5 ;
while ( ( V_22 & 7 ) != 4 )
V_22 ++ ;
V_22 += 4 ;
F_7 ( V_4 , F_8 ( V_23 , V_24 , 0 ) ) ;
F_7 ( V_4 , V_4 -> V_25 & 0xfffffffc ) ;
F_7 ( V_4 , F_9 ( V_4 -> V_25 ) & 0xffffffff ) ;
F_7 ( V_4 , 1 ) ;
F_7 ( V_4 , V_22 ) ;
}
while ( ( V_4 -> V_16 & 7 ) != 4 )
F_7 ( V_4 , F_8 ( V_26 , 0 , 0 ) ) ;
F_7 ( V_4 , F_8 ( V_27 , 0 , V_19 ) ) ;
F_7 ( V_4 , V_18 -> V_28 & 0xffffffe0 ) ;
F_7 ( V_4 , F_9 ( V_18 -> V_28 ) & 0xffffffff ) ;
F_7 ( V_4 , V_18 -> V_29 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
int V_30 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_30 ] ;
T_2 V_19 = ( F_11 ( 1 ) |
F_12 ( 3 ) ) ;
T_2 V_31 ;
if ( V_30 == V_11 )
V_31 = V_32 ;
else
V_31 = V_33 ;
F_7 ( V_4 , F_8 ( V_34 , 0 , V_19 ) ) ;
F_7 ( V_4 , V_35 ) ;
F_7 ( V_4 , V_36 ) ;
F_7 ( V_4 , V_31 ) ;
F_7 ( V_4 , V_31 ) ;
F_7 ( V_4 , ( 0xfff << 16 ) | 10 ) ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_38 -> V_4 ] ;
T_3 V_39 = V_2 -> V_40 [ V_38 -> V_4 ] . V_28 ;
F_7 ( V_4 , F_8 ( V_41 , 0 , 0 ) ) ;
F_7 ( V_4 , V_39 & 0xffffffff ) ;
F_7 ( V_4 , F_9 ( V_39 ) & 0xffffffff ) ;
F_7 ( V_4 , V_38 -> V_42 ) ;
F_7 ( V_4 , F_8 ( V_43 , 0 , 0 ) ) ;
F_10 ( V_2 , V_38 -> V_4 ) ;
}
bool F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_44 * V_45 ,
bool V_46 )
{
T_3 V_39 = V_45 -> V_28 ;
T_2 V_19 = V_46 ? 0 : V_47 ;
F_7 ( V_4 , F_8 ( V_48 , 0 , V_19 ) ) ;
F_7 ( V_4 , V_39 & 0xfffffff8 ) ;
F_7 ( V_4 , F_9 ( V_39 ) & 0xffffffff ) ;
return true ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 V_49 , V_50 ;
int V_51 ;
if ( ( V_2 -> V_52 -> V_53 . V_54 == V_11 ) ||
( V_2 -> V_52 -> V_53 . V_54 == V_55 ) )
F_16 ( V_2 , V_2 -> V_56 . V_57 ) ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( V_51 == 0 )
V_50 = V_13 ;
else
V_50 = V_14 ;
V_49 = F_2 ( V_58 + V_50 ) ;
V_49 &= ~ V_59 ;
F_5 ( V_58 + V_50 , V_49 ) ;
F_5 ( V_60 + V_50 , 0 ) ;
}
V_2 -> V_4 [ V_11 ] . V_61 = false ;
V_2 -> V_4 [ V_55 ] . V_61 = false ;
}
static void F_17 ( struct V_1 * V_2 )
{
}
void F_18 ( struct V_1 * V_2 , bool V_62 )
{
T_2 V_63 , V_50 ;
int V_51 ;
if ( V_62 == false ) {
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
}
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( V_51 == 0 )
V_50 = V_13 ;
else
V_50 = V_14 ;
V_63 = F_2 ( V_64 + V_50 ) ;
if ( V_62 )
V_63 &= ~ V_65 ;
else
V_63 |= V_65 ;
F_5 ( V_64 + V_50 , V_63 ) ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_49 , V_66 ;
T_2 V_67 ;
T_2 V_50 , V_68 ;
int V_51 , V_69 ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( V_51 == 0 ) {
V_4 = & V_2 -> V_4 [ V_11 ] ;
V_50 = V_13 ;
V_68 = V_70 ;
} else {
V_4 = & V_2 -> V_4 [ V_55 ] ;
V_50 = V_14 ;
V_68 = V_71 ;
}
F_5 ( V_72 + V_50 , 0 ) ;
F_5 ( V_73 + V_50 , 0 ) ;
V_67 = F_20 ( V_4 -> V_74 / 4 ) ;
V_49 = V_67 << 1 ;
#ifdef F_21
V_49 |= V_75 | V_76 ;
#endif
F_5 ( V_58 + V_50 , V_49 ) ;
F_5 ( V_12 + V_50 , 0 ) ;
F_5 ( V_15 + V_50 , 0 ) ;
F_5 ( V_77 + V_50 ,
F_9 ( V_2 -> V_7 . V_28 + V_68 ) & 0xFFFFFFFF ) ;
F_5 ( V_78 + V_50 ,
( ( V_2 -> V_7 . V_28 + V_68 ) & 0xFFFFFFFC ) ) ;
if ( V_2 -> V_7 . V_8 )
V_49 |= V_79 ;
F_5 ( V_80 + V_50 , V_4 -> V_28 >> 8 ) ;
F_5 ( V_81 + V_50 , V_4 -> V_28 >> 40 ) ;
V_4 -> V_16 = 0 ;
F_5 ( V_15 + V_50 , V_4 -> V_16 << 2 ) ;
F_5 ( V_58 + V_50 , V_49 | V_59 ) ;
V_66 = V_82 ;
#ifdef F_21
V_66 |= V_83 ;
#endif
F_5 ( V_60 + V_50 , V_66 ) ;
V_4 -> V_61 = true ;
V_69 = F_22 ( V_2 , V_4 -> V_10 , V_4 ) ;
if ( V_69 ) {
V_4 -> V_61 = false ;
return V_69 ;
}
}
if ( ( V_2 -> V_52 -> V_53 . V_54 == V_11 ) ||
( V_2 -> V_52 -> V_53 . V_54 == V_55 ) )
F_16 ( V_2 , V_2 -> V_56 . V_84 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
const T_4 * V_85 ;
int V_51 ;
if ( ! V_2 -> V_86 )
return - V_87 ;
F_18 ( V_2 , false ) ;
V_85 = ( const T_4 * ) V_2 -> V_86 -> V_88 ;
F_5 ( V_89 + V_13 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_90 ; V_51 ++ )
F_5 ( V_91 + V_13 , F_25 ( V_85 ++ ) ) ;
F_5 ( V_91 + V_13 , V_92 ) ;
V_85 = ( const T_4 * ) V_2 -> V_86 -> V_88 ;
F_5 ( V_89 + V_14 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_90 ; V_51 ++ )
F_5 ( V_91 + V_14 , F_25 ( V_85 ++ ) ) ;
F_5 ( V_91 + V_14 , V_92 ) ;
F_5 ( V_89 + V_13 , 0 ) ;
F_5 ( V_89 + V_14 , 0 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_69 ;
F_5 ( V_93 , V_94 | V_95 ) ;
F_2 ( V_93 ) ;
F_27 ( 50 ) ;
F_5 ( V_93 , 0 ) ;
F_2 ( V_93 ) ;
V_69 = F_24 ( V_2 ) ;
if ( V_69 )
return V_69 ;
F_18 ( V_2 , true ) ;
V_69 = F_19 ( V_2 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_23 ( V_2 ) ;
if ( V_69 )
return V_69 ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_18 ( V_2 , false ) ;
F_29 ( V_2 , & V_2 -> V_4 [ V_11 ] ) ;
F_29 ( V_2 , & V_2 -> V_4 [ V_55 ] ) ;
}
int F_30 ( struct V_1 * V_2 ,
T_5 V_96 , T_5 V_97 ,
unsigned V_98 ,
struct V_37 * * V_38 )
{
struct V_44 * V_99 = NULL ;
int V_100 = V_2 -> V_52 -> V_53 . V_101 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_100 ] ;
T_2 V_102 , V_103 ;
int V_51 , V_104 ;
int V_69 = 0 ;
V_69 = F_31 ( V_2 , & V_99 ) ;
if ( V_69 ) {
F_32 ( L_1 , V_69 ) ;
return V_69 ;
}
V_102 = ( V_98 << V_105 ) ;
V_104 = F_33 ( V_102 , 0x1fffff ) ;
V_69 = F_34 ( V_2 , V_4 , V_104 * 7 + 14 ) ;
if ( V_69 ) {
F_32 ( L_1 , V_69 ) ;
F_35 ( V_2 , & V_99 , NULL ) ;
return V_69 ;
}
F_36 ( V_99 , * V_38 ) ;
F_37 ( V_2 , V_99 , V_4 -> V_10 ) ;
for ( V_51 = 0 ; V_51 < V_104 ; V_51 ++ ) {
V_103 = V_102 ;
if ( V_103 > 0x1fffff )
V_103 = 0x1fffff ;
V_102 -= V_103 ;
F_7 ( V_4 , F_8 ( V_106 , V_107 , 0 ) ) ;
F_7 ( V_4 , V_103 ) ;
F_7 ( V_4 , 0 ) ;
F_7 ( V_4 , V_96 & 0xffffffff ) ;
F_7 ( V_4 , F_9 ( V_96 ) & 0xffffffff ) ;
F_7 ( V_4 , V_97 & 0xffffffff ) ;
F_7 ( V_4 , F_9 ( V_97 ) & 0xffffffff ) ;
V_96 += V_103 ;
V_97 += V_103 ;
}
V_69 = F_38 ( V_2 , V_38 , V_4 -> V_10 ) ;
if ( V_69 ) {
F_39 ( V_2 , V_4 ) ;
F_35 ( V_2 , & V_99 , NULL ) ;
return V_69 ;
}
F_40 ( V_2 , V_4 ) ;
F_35 ( V_2 , & V_99 , * V_38 ) ;
return V_69 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned V_51 ;
int V_69 ;
void T_6 * V_108 = ( void * ) V_2 -> V_109 . V_108 ;
T_2 V_110 ;
if ( ! V_108 ) {
F_32 ( L_2 ) ;
return - V_87 ;
}
V_110 = 0xCAFEDEAD ;
F_42 ( V_110 , V_108 ) ;
V_69 = F_34 ( V_2 , V_4 , 5 ) ;
if ( V_69 ) {
F_32 ( L_3 , V_4 -> V_10 , V_69 ) ;
return V_69 ;
}
F_7 ( V_4 , F_8 ( V_23 , V_24 , 0 ) ) ;
F_7 ( V_4 , V_2 -> V_109 . V_28 & 0xfffffffc ) ;
F_7 ( V_4 , F_9 ( V_2 -> V_109 . V_28 ) & 0xffffffff ) ;
F_7 ( V_4 , 1 ) ;
F_7 ( V_4 , 0xDEADBEEF ) ;
F_40 ( V_2 , V_4 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_111 ; V_51 ++ ) {
V_110 = F_43 ( V_108 ) ;
if ( V_110 == 0xDEADBEEF )
break;
F_44 ( 1 ) ;
}
if ( V_51 < V_2 -> V_111 ) {
F_45 ( L_4 , V_4 -> V_10 , V_51 ) ;
} else {
F_32 ( L_5 ,
V_4 -> V_10 , V_110 ) ;
V_69 = - V_87 ;
}
return V_69 ;
}
int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 V_18 ;
unsigned V_51 ;
int V_69 ;
void T_6 * V_108 = ( void * ) V_2 -> V_109 . V_108 ;
T_2 V_110 = 0 ;
if ( ! V_108 ) {
F_32 ( L_2 ) ;
return - V_87 ;
}
V_110 = 0xCAFEDEAD ;
F_42 ( V_110 , V_108 ) ;
V_69 = F_47 ( V_2 , V_4 -> V_10 , & V_18 , NULL , 256 ) ;
if ( V_69 ) {
F_32 ( L_6 , V_69 ) ;
return V_69 ;
}
V_18 . V_108 [ 0 ] = F_8 ( V_23 , V_24 , 0 ) ;
V_18 . V_108 [ 1 ] = V_2 -> V_109 . V_28 & 0xfffffffc ;
V_18 . V_108 [ 2 ] = F_9 ( V_2 -> V_109 . V_28 ) & 0xffffffff ;
V_18 . V_108 [ 3 ] = 1 ;
V_18 . V_108 [ 4 ] = 0xDEADBEEF ;
V_18 . V_29 = 5 ;
V_69 = F_48 ( V_2 , & V_18 , NULL ) ;
if ( V_69 ) {
F_49 ( V_2 , & V_18 ) ;
F_32 ( L_7 , V_69 ) ;
return V_69 ;
}
V_69 = F_50 ( V_18 . V_38 , false ) ;
if ( V_69 ) {
F_32 ( L_8 , V_69 ) ;
return V_69 ;
}
for ( V_51 = 0 ; V_51 < V_2 -> V_111 ; V_51 ++ ) {
V_110 = F_43 ( V_108 ) ;
if ( V_110 == 0xDEADBEEF )
break;
F_44 ( 1 ) ;
}
if ( V_51 < V_2 -> V_111 ) {
F_45 ( L_9 , V_18 . V_38 -> V_4 , V_51 ) ;
} else {
F_32 ( L_10 , V_110 ) ;
V_69 = - V_87 ;
}
F_49 ( V_2 , & V_18 ) ;
return V_69 ;
}
bool F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_112 = F_52 ( V_2 ) ;
T_2 V_113 ;
if ( V_4 -> V_10 == V_11 )
V_113 = V_114 ;
else
V_113 = V_115 ;
if ( ! ( V_112 & V_113 ) ) {
F_53 ( V_2 , V_4 ) ;
return false ;
}
return F_54 ( V_2 , V_4 ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_5 V_116 ,
T_5 V_39 , unsigned V_117 ,
T_1 V_118 , T_1 V_119 )
{
T_5 V_120 ;
unsigned V_121 ;
F_56 ( V_116 , V_39 , V_117 , V_118 , V_119 ) ;
if ( V_119 & V_122 ) {
while ( V_117 ) {
V_121 = V_117 * 2 ;
if ( V_121 > 0xFFFFE )
V_121 = 0xFFFFE ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_8 ( V_23 , V_24 , 0 ) ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_116 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_9 ( V_116 ) ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_121 ;
for (; V_121 > 0 ; V_121 -= 2 , -- V_117 , V_116 += 8 ) {
V_120 = F_57 ( V_2 , V_39 ) ;
V_120 &= 0xFFFFFFFFFFFFF000ULL ;
V_39 += V_118 ;
V_120 |= V_119 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_120 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_9 ( V_120 ) ;
}
}
} else {
while ( V_117 ) {
V_121 = V_117 ;
if ( V_121 > 0x7FFFF )
V_121 = 0x7FFFF ;
if ( V_119 & V_123 )
V_120 = V_39 ;
else
V_120 = 0 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_8 ( V_124 , 0 , 0 ) ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_116 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_9 ( V_116 ) ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_119 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = 0 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_120 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_9 ( V_120 ) ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_118 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = 0 ;
V_18 -> V_108 [ V_18 -> V_29 ++ ] = V_121 ;
V_116 += V_121 * 8 ;
V_39 += V_121 * V_118 ;
V_117 -= V_121 ;
}
}
while ( V_18 -> V_29 & 0x7 )
V_18 -> V_108 [ V_18 -> V_29 ++ ] = F_8 ( V_26 , 0 , 0 ) ;
}
void F_58 ( struct V_1 * V_2 , int V_30 , struct V_125 * V_20 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_30 ] ;
if ( V_20 == NULL )
return;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
if ( V_20 -> V_21 < 8 ) {
F_7 ( V_4 , ( V_127 + ( V_20 -> V_21 << 2 ) ) >> 2 ) ;
} else {
F_7 ( V_4 , ( V_128 + ( ( V_20 -> V_21 - 8 ) << 2 ) ) >> 2 ) ;
}
F_7 ( V_4 , V_20 -> V_129 >> 12 ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_130 >> 2 ) ;
F_7 ( V_4 , F_59 ( V_20 -> V_21 ) ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_131 >> 2 ) ;
F_7 ( V_4 , 0 ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_132 >> 2 ) ;
F_7 ( V_4 , 0 ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_133 >> 2 ) ;
F_7 ( V_4 , 1 ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_134 >> 2 ) ;
F_7 ( V_4 , 0 ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_130 >> 2 ) ;
F_7 ( V_4 , F_59 ( 0 ) ) ;
F_10 ( V_2 , V_30 ) ;
F_7 ( V_4 , F_8 ( V_126 , 0 , 0xf000 ) ) ;
F_7 ( V_4 , V_135 >> 2 ) ;
F_7 ( V_4 , 1 << V_20 -> V_21 ) ;
}
