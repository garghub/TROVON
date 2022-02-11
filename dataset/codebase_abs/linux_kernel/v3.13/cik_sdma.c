void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_4 -> V_6 ] ;
T_1 V_7 = ( V_4 -> V_8 ? V_4 -> V_8 -> V_9 : 0 ) & 0xf ;
if ( V_2 -> V_10 . V_11 ) {
T_1 V_12 = V_6 -> V_13 + 5 ;
while ( ( V_12 & 7 ) != 4 )
V_12 ++ ;
V_12 += 4 ;
F_2 ( V_6 , F_3 ( V_14 , V_15 , 0 ) ) ;
F_2 ( V_6 , V_6 -> V_16 & 0xfffffffc ) ;
F_2 ( V_6 , F_4 ( V_6 -> V_16 ) & 0xffffffff ) ;
F_2 ( V_6 , 1 ) ;
F_2 ( V_6 , V_12 ) ;
}
while ( ( V_6 -> V_13 & 7 ) != 4 )
F_2 ( V_6 , F_3 ( V_17 , 0 , 0 ) ) ;
F_2 ( V_6 , F_3 ( V_18 , 0 , V_7 ) ) ;
F_2 ( V_6 , V_4 -> V_19 & 0xffffffe0 ) ;
F_2 ( V_6 , F_4 ( V_4 -> V_19 ) & 0xffffffff ) ;
F_2 ( V_6 , V_4 -> V_20 ) ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_22 -> V_6 ] ;
T_2 V_23 = V_2 -> V_24 [ V_22 -> V_6 ] . V_19 ;
F_2 ( V_6 , F_3 ( V_25 , 0 , 0 ) ) ;
F_2 ( V_6 , V_23 & 0xffffffff ) ;
F_2 ( V_6 , F_4 ( V_23 ) & 0xffffffff ) ;
F_2 ( V_6 , V_22 -> V_26 ) ;
F_2 ( V_6 , F_3 ( V_27 , 0 , 0 ) ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_29 >> 2 ) ;
F_2 ( V_6 , 0 ) ;
}
bool F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_30 * V_31 ,
bool V_32 )
{
T_2 V_23 = V_31 -> V_19 ;
T_1 V_7 = V_32 ? 0 : V_33 ;
F_2 ( V_6 , F_3 ( V_34 , 0 , V_7 ) ) ;
F_2 ( V_6 , V_23 & 0xfffffff8 ) ;
F_2 ( V_6 , F_4 ( V_23 ) & 0xffffffff ) ;
return true ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_35 , V_36 ;
int V_37 ;
F_8 ( V_2 , V_2 -> V_38 . V_39 ) ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
if ( V_37 == 0 )
V_36 = V_40 ;
else
V_36 = V_41 ;
V_35 = F_9 ( V_42 + V_36 ) ;
V_35 &= ~ V_43 ;
F_10 ( V_42 + V_36 , V_35 ) ;
F_10 ( V_44 + V_36 , 0 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
}
void F_12 ( struct V_1 * V_2 , bool V_45 )
{
T_1 V_46 , V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
if ( V_37 == 0 )
V_36 = V_40 ;
else
V_36 = V_41 ;
V_46 = F_9 ( V_47 + V_36 ) ;
if ( V_45 )
V_46 &= ~ V_48 ;
else
V_46 |= V_48 ;
F_10 ( V_47 + V_36 , V_46 ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_1 V_35 , V_49 ;
T_1 V_50 ;
T_1 V_36 , V_51 ;
int V_37 , V_52 ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
if ( V_37 == 0 ) {
V_6 = & V_2 -> V_6 [ V_53 ] ;
V_36 = V_40 ;
V_51 = V_54 ;
} else {
V_6 = & V_2 -> V_6 [ V_55 ] ;
V_36 = V_41 ;
V_51 = V_56 ;
}
F_10 ( V_57 + V_36 , 0 ) ;
F_10 ( V_58 + V_36 , 0 ) ;
V_50 = F_14 ( V_6 -> V_59 / 4 ) ;
V_35 = V_50 << 1 ;
#ifdef F_15
V_35 |= V_60 | V_61 ;
#endif
F_10 ( V_42 + V_36 , V_35 ) ;
F_10 ( V_62 + V_36 , 0 ) ;
F_10 ( V_63 + V_36 , 0 ) ;
F_10 ( V_64 + V_36 ,
F_4 ( V_2 -> V_10 . V_19 + V_51 ) & 0xFFFFFFFF ) ;
F_10 ( V_65 + V_36 ,
( ( V_2 -> V_10 . V_19 + V_51 ) & 0xFFFFFFFC ) ) ;
if ( V_2 -> V_10 . V_11 )
V_35 |= V_66 ;
F_10 ( V_67 + V_36 , V_6 -> V_19 >> 8 ) ;
F_10 ( V_68 + V_36 , V_6 -> V_19 >> 40 ) ;
V_6 -> V_13 = 0 ;
F_10 ( V_63 + V_36 , V_6 -> V_13 << 2 ) ;
V_6 -> V_69 = F_9 ( V_62 + V_36 ) >> 2 ;
F_10 ( V_42 + V_36 , V_35 | V_43 ) ;
V_49 = V_70 ;
#ifdef F_15
V_49 |= V_71 ;
#endif
F_10 ( V_44 + V_36 , V_49 ) ;
V_6 -> V_72 = true ;
V_52 = F_16 ( V_2 , V_6 -> V_73 , V_6 ) ;
if ( V_52 ) {
V_6 -> V_72 = false ;
return V_52 ;
}
}
F_8 ( V_2 , V_2 -> V_38 . V_74 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const T_3 * V_75 ;
int V_37 ;
if ( ! V_2 -> V_76 )
return - V_77 ;
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 , false ) ;
V_75 = ( const T_3 * ) V_2 -> V_76 -> V_78 ;
F_10 ( V_79 + V_40 , 0 ) ;
for ( V_37 = 0 ; V_37 < V_80 ; V_37 ++ )
F_10 ( V_81 + V_40 , F_19 ( V_75 ++ ) ) ;
F_10 ( V_81 + V_40 , V_82 ) ;
V_75 = ( const T_3 * ) V_2 -> V_76 -> V_78 ;
F_10 ( V_79 + V_41 , 0 ) ;
for ( V_37 = 0 ; V_37 < V_80 ; V_37 ++ )
F_10 ( V_81 + V_41 , F_19 ( V_75 ++ ) ) ;
F_10 ( V_81 + V_41 , V_82 ) ;
F_10 ( V_79 + V_40 , 0 ) ;
F_10 ( V_79 + V_41 , 0 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_52 ;
F_10 ( V_83 , V_84 | V_85 ) ;
F_9 ( V_83 ) ;
F_21 ( 50 ) ;
F_10 ( V_83 , 0 ) ;
F_9 ( V_83 ) ;
V_52 = F_18 ( V_2 ) ;
if ( V_52 )
return V_52 ;
F_12 ( V_2 , true ) ;
V_52 = F_13 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_17 ( V_2 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 , false ) ;
F_23 ( V_2 , & V_2 -> V_6 [ V_53 ] ) ;
F_23 ( V_2 , & V_2 -> V_6 [ V_55 ] ) ;
}
int F_24 ( struct V_1 * V_2 ,
T_4 V_86 , T_4 V_87 ,
unsigned V_88 ,
struct V_21 * * V_22 )
{
struct V_30 * V_89 = NULL ;
int V_90 = V_2 -> V_91 -> V_92 . V_93 ;
struct V_5 * V_6 = & V_2 -> V_6 [ V_90 ] ;
T_1 V_94 , V_95 ;
int V_37 , V_96 ;
int V_52 = 0 ;
V_52 = F_25 ( V_2 , & V_89 ) ;
if ( V_52 ) {
F_26 ( L_1 , V_52 ) ;
return V_52 ;
}
V_94 = ( V_88 << V_97 ) ;
V_96 = F_27 ( V_94 , 0x1fffff ) ;
V_52 = F_28 ( V_2 , V_6 , V_96 * 7 + 14 ) ;
if ( V_52 ) {
F_26 ( L_1 , V_52 ) ;
F_29 ( V_2 , & V_89 , NULL ) ;
return V_52 ;
}
F_30 ( V_89 , * V_22 ) ;
F_31 ( V_2 , V_89 , V_6 -> V_73 ) ;
for ( V_37 = 0 ; V_37 < V_96 ; V_37 ++ ) {
V_95 = V_94 ;
if ( V_95 > 0x1fffff )
V_95 = 0x1fffff ;
V_94 -= V_95 ;
F_2 ( V_6 , F_3 ( V_98 , V_99 , 0 ) ) ;
F_2 ( V_6 , V_95 ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , V_86 & 0xffffffff ) ;
F_2 ( V_6 , F_4 ( V_86 ) & 0xffffffff ) ;
F_2 ( V_6 , V_87 & 0xffffffff ) ;
F_2 ( V_6 , F_4 ( V_87 ) & 0xffffffff ) ;
V_86 += V_95 ;
V_87 += V_95 ;
}
V_52 = F_32 ( V_2 , V_22 , V_6 -> V_73 ) ;
if ( V_52 ) {
F_33 ( V_2 , V_6 ) ;
return V_52 ;
}
F_34 ( V_2 , V_6 ) ;
F_29 ( V_2 , & V_89 , * V_22 ) ;
return V_52 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
unsigned V_37 ;
int V_52 ;
void T_5 * V_100 = ( void * ) V_2 -> V_101 . V_100 ;
T_1 V_102 ;
if ( ! V_100 ) {
F_26 ( L_2 ) ;
return - V_77 ;
}
V_102 = 0xCAFEDEAD ;
F_36 ( V_102 , V_100 ) ;
V_52 = F_28 ( V_2 , V_6 , 4 ) ;
if ( V_52 ) {
F_26 ( L_3 , V_6 -> V_73 , V_52 ) ;
return V_52 ;
}
F_2 ( V_6 , F_3 ( V_14 , V_15 , 0 ) ) ;
F_2 ( V_6 , V_2 -> V_101 . V_19 & 0xfffffffc ) ;
F_2 ( V_6 , F_4 ( V_2 -> V_101 . V_19 ) & 0xffffffff ) ;
F_2 ( V_6 , 1 ) ;
F_2 ( V_6 , 0xDEADBEEF ) ;
F_34 ( V_2 , V_6 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_103 ; V_37 ++ ) {
V_102 = F_37 ( V_100 ) ;
if ( V_102 == 0xDEADBEEF )
break;
F_38 ( 1 ) ;
}
if ( V_37 < V_2 -> V_103 ) {
F_39 ( L_4 , V_6 -> V_73 , V_37 ) ;
} else {
F_26 ( L_5 ,
V_6 -> V_73 , V_102 ) ;
V_52 = - V_77 ;
}
return V_52 ;
}
int F_40 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 V_4 ;
unsigned V_37 ;
int V_52 ;
void T_5 * V_100 = ( void * ) V_2 -> V_101 . V_100 ;
T_1 V_102 = 0 ;
if ( ! V_100 ) {
F_26 ( L_2 ) ;
return - V_77 ;
}
V_102 = 0xCAFEDEAD ;
F_36 ( V_102 , V_100 ) ;
V_52 = F_41 ( V_2 , V_6 -> V_73 , & V_4 , NULL , 256 ) ;
if ( V_52 ) {
F_26 ( L_6 , V_52 ) ;
return V_52 ;
}
V_4 . V_100 [ 0 ] = F_3 ( V_14 , V_15 , 0 ) ;
V_4 . V_100 [ 1 ] = V_2 -> V_101 . V_19 & 0xfffffffc ;
V_4 . V_100 [ 2 ] = F_4 ( V_2 -> V_101 . V_19 ) & 0xffffffff ;
V_4 . V_100 [ 3 ] = 1 ;
V_4 . V_100 [ 4 ] = 0xDEADBEEF ;
V_4 . V_20 = 5 ;
V_52 = F_42 ( V_2 , & V_4 , NULL ) ;
if ( V_52 ) {
F_43 ( V_2 , & V_4 ) ;
F_26 ( L_7 , V_52 ) ;
return V_52 ;
}
V_52 = F_44 ( V_4 . V_22 , false ) ;
if ( V_52 ) {
F_26 ( L_8 , V_52 ) ;
return V_52 ;
}
for ( V_37 = 0 ; V_37 < V_2 -> V_103 ; V_37 ++ ) {
V_102 = F_37 ( V_100 ) ;
if ( V_102 == 0xDEADBEEF )
break;
F_38 ( 1 ) ;
}
if ( V_37 < V_2 -> V_103 ) {
F_39 ( L_9 , V_4 . V_22 -> V_6 , V_37 ) ;
} else {
F_26 ( L_10 , V_102 ) ;
V_52 = - V_77 ;
}
F_43 ( V_2 , & V_4 ) ;
return V_52 ;
}
bool F_45 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_104 = F_46 ( V_2 ) ;
T_1 V_105 ;
if ( V_6 -> V_73 == V_53 )
V_105 = V_106 ;
else
V_105 = V_107 ;
if ( ! ( V_104 & V_105 ) ) {
F_47 ( V_6 ) ;
return false ;
}
F_48 ( V_2 , V_6 ) ;
return F_49 ( V_2 , V_6 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_4 V_108 ,
T_4 V_23 , unsigned V_109 ,
T_6 V_110 , T_6 V_111 )
{
T_4 V_112 ;
unsigned V_113 ;
F_51 ( V_108 , V_23 , V_109 , V_110 , V_111 ) ;
if ( V_111 & V_114 ) {
while ( V_109 ) {
V_113 = V_109 * 2 ;
if ( V_113 > 0xFFFFE )
V_113 = 0xFFFFE ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_3 ( V_14 , V_15 , 0 ) ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_108 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_4 ( V_108 ) ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_113 ;
for (; V_113 > 0 ; V_113 -= 2 , -- V_109 , V_108 += 8 ) {
V_112 = F_52 ( V_2 , V_23 ) ;
V_112 &= 0xFFFFFFFFFFFFF000ULL ;
V_23 += V_110 ;
V_112 |= V_111 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_112 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_4 ( V_112 ) ;
}
}
} else {
while ( V_109 ) {
V_113 = V_109 ;
if ( V_113 > 0x7FFFF )
V_113 = 0x7FFFF ;
if ( V_111 & V_115 )
V_112 = V_23 ;
else
V_112 = 0 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_3 ( V_116 , 0 , 0 ) ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_108 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_4 ( V_108 ) ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_111 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = 0 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_112 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_4 ( V_112 ) ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_110 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = 0 ;
V_4 -> V_100 [ V_4 -> V_20 ++ ] = V_113 ;
V_108 += V_113 * 8 ;
V_23 += V_113 * V_110 ;
V_109 -= V_113 ;
}
}
while ( V_4 -> V_20 & 0x7 )
V_4 -> V_100 [ V_4 -> V_20 ++ ] = F_3 ( V_17 , 0 , 0 ) ;
}
void F_53 ( struct V_1 * V_2 , int V_117 , struct V_118 * V_8 )
{
struct V_5 * V_6 = & V_2 -> V_6 [ V_117 ] ;
if ( V_8 == NULL )
return;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
if ( V_8 -> V_9 < 8 ) {
F_2 ( V_6 , ( V_119 + ( V_8 -> V_9 << 2 ) ) >> 2 ) ;
} else {
F_2 ( V_6 , ( V_120 + ( ( V_8 -> V_9 - 8 ) << 2 ) ) >> 2 ) ;
}
F_2 ( V_6 , V_8 -> V_121 >> 12 ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_122 >> 2 ) ;
F_2 ( V_6 , F_54 ( V_8 -> V_9 ) ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_123 >> 2 ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_124 >> 2 ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_125 >> 2 ) ;
F_2 ( V_6 , 1 ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_126 >> 2 ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_122 >> 2 ) ;
F_2 ( V_6 , F_54 ( 0 ) ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_29 >> 2 ) ;
F_2 ( V_6 , 0 ) ;
F_2 ( V_6 , F_3 ( V_28 , 0 , 0xf000 ) ) ;
F_2 ( V_6 , V_127 >> 2 ) ;
F_2 ( V_6 , 1 << V_8 -> V_9 ) ;
}
