static inline T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
enum V_4 V_5 )
{
T_1 V_6 = V_7 ;
V_6 |= F_2 ( V_3 ) ;
switch ( V_5 ) {
case V_8 :
if ( F_3 ( V_2 ) )
V_6 |= V_9 ;
else
V_6 |= V_10 ;
break;
case V_11 :
V_6 |= V_9 ;
break;
case V_12 :
if ( F_3 ( V_2 ) )
V_6 |= V_13 ;
else
V_6 |= V_14 ;
break;
default:
F_4 () ;
}
return V_6 ;
}
static void F_5 ( struct V_15 * V_16 ,
unsigned V_17 ,
unsigned V_18 )
{
T_1 * V_19 ;
T_1 V_20 ;
unsigned V_21 = V_17 / V_22 ;
unsigned V_23 = V_17 % V_22 ;
unsigned V_24 , V_25 ;
V_20 = F_1 ( V_16 -> V_2 , V_16 -> V_26 ,
V_11 ) ;
while ( V_18 ) {
V_24 = V_23 + V_18 ;
if ( V_24 > V_22 )
V_24 = V_22 ;
V_19 = F_6 ( V_16 -> V_27 [ V_21 ] ) ;
for ( V_25 = V_23 ; V_25 < V_24 ; V_25 ++ )
V_19 [ V_25 ] = V_20 ;
F_7 ( V_19 ) ;
V_18 -= V_24 - V_23 ;
V_23 = 0 ;
V_21 ++ ;
}
}
int F_8 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_15 * V_16 ;
unsigned V_31 ;
int V_25 ;
int V_32 = - V_33 ;
V_31 = V_29 -> V_34 . V_35 -> V_36 - V_37 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_38 ) ;
if ( ! V_16 )
return V_32 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_39 = V_37 ;
V_16 -> V_27 = F_9 ( sizeof( struct V_40 * ) * V_16 -> V_39 ,
V_38 ) ;
if ( ! V_16 -> V_27 )
goto V_41;
for ( V_25 = 0 ; V_25 < V_16 -> V_39 ; V_25 ++ ) {
V_16 -> V_27 [ V_25 ] = F_10 ( V_38 ) ;
if ( ! V_16 -> V_27 [ V_25 ] )
goto V_42;
}
if ( V_29 -> V_34 . V_35 -> V_43 ) {
V_16 -> V_44 = F_9 ( sizeof( T_2 )
* V_16 -> V_39 ,
V_38 ) ;
if ( ! V_16 -> V_44 )
goto V_42;
for ( V_25 = 0 ; V_25 < V_16 -> V_39 ; V_25 ++ ) {
T_2 V_45 ;
V_45 = F_11 ( V_2 -> V_46 , V_16 -> V_27 [ V_25 ] ,
0 , 4096 ,
V_47 ) ;
if ( F_12 ( V_2 -> V_46 ,
V_45 ) ) {
V_32 = - V_48 ;
goto V_49;
}
V_16 -> V_44 [ V_25 ] = V_45 ;
}
}
V_16 -> V_26 = V_29 -> V_34 . V_35 -> V_50 ;
F_5 ( V_16 , 0 ,
V_16 -> V_39 * V_22 ) ;
V_16 -> V_51 = ( V_31 ) * sizeof( T_1 ) ;
V_29 -> V_34 . V_52 = V_16 ;
return 0 ;
V_49:
if ( V_16 -> V_44 ) {
for ( V_25 -- ; V_25 >= 0 ; V_25 -- )
F_13 ( V_2 -> V_46 , V_16 -> V_44 [ V_25 ] ,
4096 , V_47 ) ;
}
V_42:
F_14 ( V_16 -> V_44 ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_39 ; V_25 ++ ) {
if ( V_16 -> V_27 [ V_25 ] )
F_15 ( V_16 -> V_27 [ V_25 ] ) ;
}
F_14 ( V_16 -> V_27 ) ;
V_41:
F_14 ( V_16 ) ;
return V_32 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_15 * V_16 = V_29 -> V_34 . V_52 ;
int V_25 ;
if ( ! V_16 )
return;
if ( V_16 -> V_44 ) {
for ( V_25 = 0 ; V_25 < V_16 -> V_39 ; V_25 ++ )
F_13 ( V_2 -> V_46 , V_16 -> V_44 [ V_25 ] ,
4096 , V_47 ) ;
}
F_14 ( V_16 -> V_44 ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_39 ; V_25 ++ )
F_15 ( V_16 -> V_27 [ V_25 ] ) ;
F_14 ( V_16 -> V_27 ) ;
F_14 ( V_16 ) ;
}
static void F_17 ( struct V_15 * V_16 ,
const struct V_53 * V_54 ,
unsigned V_17 ,
enum V_4 V_55 )
{
T_1 * V_19 ;
unsigned V_21 = V_17 / V_22 ;
unsigned V_23 = V_17 % V_22 ;
unsigned V_25 , V_56 , V_57 , V_58 ;
T_2 V_59 ;
struct V_60 * V_61 ;
V_61 = V_54 -> V_62 ;
V_25 = 0 ;
V_58 = F_18 ( V_61 ) >> V_63 ;
V_57 = 0 ;
while ( V_25 < V_54 -> V_64 ) {
V_19 = F_6 ( V_16 -> V_27 [ V_21 ] ) ;
for ( V_56 = V_23 ; V_56 < V_22 ; V_56 ++ ) {
V_59 = F_19 ( V_61 ) + ( V_57 << V_63 ) ;
V_19 [ V_56 ] = F_1 ( V_16 -> V_2 , V_59 ,
V_55 ) ;
if ( ++ V_57 == V_58 ) {
if ( ++ V_25 == V_54 -> V_64 )
break;
V_61 = F_20 ( V_61 ) ;
V_58 = F_18 ( V_61 ) >> V_63 ;
V_57 = 0 ;
}
}
F_7 ( V_19 ) ;
V_23 = 0 ;
V_21 ++ ;
}
}
void F_21 ( struct V_15 * V_16 ,
struct V_65 * V_66 ,
enum V_4 V_55 )
{
F_17 ( V_16 ,
V_66 -> V_54 ,
V_66 -> V_67 -> V_68 >> V_63 ,
V_55 ) ;
}
void F_22 ( struct V_15 * V_16 ,
struct V_65 * V_66 )
{
F_5 ( V_16 ,
V_66 -> V_67 -> V_68 >> V_63 ,
V_66 -> V_69 . V_70 >> V_63 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
T_3 * V_29 = V_2 -> V_30 ;
T_4 V_51 ;
struct V_71 * V_72 ;
struct V_15 * V_16 = V_29 -> V_34 . V_52 ;
T_4 T_5 * V_73 ;
T_4 V_74 ;
int V_25 ;
if ( ! V_29 -> V_34 . V_52 )
return;
V_73 = V_29 -> V_34 . V_35 -> V_35 + V_16 -> V_51 / sizeof( T_4 ) ;
for ( V_25 = 0 ; V_25 < V_16 -> V_39 ; V_25 ++ ) {
T_2 V_45 ;
if ( V_29 -> V_34 . V_35 -> V_43 )
V_45 = V_16 -> V_44 [ V_25 ] ;
else
V_45 = F_24 ( V_16 -> V_27 [ V_25 ] ) ;
V_74 = F_25 ( V_45 ) ;
V_74 |= V_75 ;
F_26 ( V_74 , V_73 + V_25 ) ;
}
F_27 ( V_73 ) ;
V_51 = V_16 -> V_51 ;
V_51 /= 64 ;
V_51 <<= 16 ;
if ( F_28 ( V_2 ) -> V_76 == 6 ) {
T_4 V_77 , V_78 , V_79 ;
V_79 = F_29 ( V_80 ) ;
F_30 ( V_80 , V_79 | V_81 ) ;
V_78 = F_29 ( V_82 ) ;
F_30 ( V_82 , V_78 | V_83 ) ;
V_77 = F_29 ( V_84 ) ;
F_30 ( V_84 , V_77 | V_85 |
V_86 ) ;
F_30 ( V_87 , F_31 ( V_88 ) ) ;
} else if ( F_28 ( V_2 ) -> V_76 >= 7 ) {
F_30 ( V_84 , V_86 ) ;
}
F_32 (ring, dev_priv, i) {
if ( F_28 ( V_2 ) -> V_76 >= 7 )
F_30 ( F_33 ( V_72 ) ,
F_31 ( V_88 ) ) ;
F_30 ( F_34 ( V_72 ) , V_89 ) ;
F_30 ( F_35 ( V_72 ) , V_51 ) ;
}
}
static bool F_36 ( struct V_28 * V_29 )
{
bool V_32 = V_29 -> V_34 . V_90 ;
if ( F_37 ( V_29 -> V_34 . V_35 -> V_91 ) ) {
V_29 -> V_34 . V_90 = false ;
if ( F_38 ( V_29 -> V_2 ) ) {
F_39 ( L_1 ) ;
F_40 ( 10 ) ;
}
}
return V_32 ;
}
static void F_41 ( struct V_28 * V_29 , bool V_90 )
{
if ( F_37 ( V_29 -> V_34 . V_35 -> V_91 ) )
V_29 -> V_34 . V_90 = V_90 ;
}
static void F_42 ( struct V_1 * V_2 ,
unsigned V_17 ,
unsigned V_18 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
T_1 V_20 ;
T_1 T_5 * V_92 = V_29 -> V_34 . V_35 -> V_35 + V_17 ;
const int V_93 = V_29 -> V_34 . V_35 -> V_36 - V_17 ;
int V_25 ;
if ( F_28 ( V_2 ) -> V_76 < 6 ) {
F_43 ( V_17 , V_18 ) ;
return;
}
if ( F_44 ( V_18 > V_93 ,
L_2 ,
V_17 , V_18 , V_93 ) )
V_18 = V_93 ;
V_20 = F_1 ( V_2 , V_29 -> V_34 . V_35 -> V_50 , V_11 ) ;
for ( V_25 = 0 ; V_25 < V_18 ; V_25 ++ )
F_45 ( V_20 , & V_92 [ V_25 ] ) ;
F_27 ( V_92 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_65 * V_66 ;
F_42 ( V_2 , V_29 -> V_34 . V_94 / V_95 ,
( V_29 -> V_34 . V_96 - V_29 -> V_34 . V_94 ) / V_95 ) ;
F_47 (obj, &dev_priv->mm.bound_list, gtt_list) {
F_48 ( V_66 ) ;
F_49 ( V_66 , V_66 -> V_55 ) ;
}
F_50 ( V_2 ) ;
}
int F_51 ( struct V_65 * V_66 )
{
if ( V_66 -> V_97 )
return 0 ;
if ( ! F_52 ( & V_66 -> V_69 . V_2 -> V_46 -> V_2 ,
V_66 -> V_54 -> V_62 , V_66 -> V_54 -> V_64 ,
V_47 ) )
return - V_98 ;
return 0 ;
}
static void F_53 ( struct V_65 * V_66 ,
enum V_4 V_5 )
{
struct V_1 * V_2 = V_66 -> V_69 . V_2 ;
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_53 * V_99 = V_66 -> V_54 ;
struct V_60 * V_61 = V_99 -> V_62 ;
const int V_17 = V_66 -> V_67 -> V_68 >> V_63 ;
const int V_93 = V_29 -> V_34 . V_35 -> V_36 - V_17 ;
T_1 T_5 * V_100 = V_29 -> V_34 . V_35 -> V_35 + V_17 ;
int V_101 , V_25 = 0 ;
unsigned int V_102 , V_57 = 0 ;
T_2 V_3 ;
F_54 (st->sgl, sg, st->nents, unused) {
V_102 = F_18 ( V_61 ) >> V_63 ;
for ( V_57 = 0 ; V_57 < V_102 ; V_57 ++ ) {
V_3 = F_19 ( V_61 ) + ( V_57 << V_63 ) ;
F_45 ( F_1 ( V_2 , V_3 , V_5 ) , & V_100 [ V_25 ] ) ;
V_25 ++ ;
}
}
F_55 ( V_25 > V_93 ) ;
F_55 ( V_25 != V_66 -> V_69 . V_70 / V_95 ) ;
if ( V_25 != 0 )
F_56 ( F_27 ( & V_100 [ V_25 - 1 ] ) != F_1 ( V_2 , V_3 , V_5 ) ) ;
F_30 ( V_103 , V_104 ) ;
F_57 ( V_103 ) ;
}
void F_49 ( struct V_65 * V_66 ,
enum V_4 V_55 )
{
struct V_1 * V_2 = V_66 -> V_69 . V_2 ;
if ( F_28 ( V_2 ) -> V_76 < 6 ) {
unsigned int V_105 = ( V_55 == V_12 ) ?
V_106 : V_107 ;
F_58 ( V_66 -> V_54 ,
V_66 -> V_67 -> V_68 >> V_63 ,
V_105 ) ;
} else {
F_53 ( V_66 , V_55 ) ;
}
V_66 -> V_108 = 1 ;
}
void F_59 ( struct V_65 * V_66 )
{
F_42 ( V_66 -> V_69 . V_2 ,
V_66 -> V_67 -> V_68 >> V_63 ,
V_66 -> V_69 . V_70 >> V_63 ) ;
V_66 -> V_108 = 0 ;
}
void F_60 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_69 . V_2 ;
struct V_28 * V_29 = V_2 -> V_30 ;
bool V_90 ;
V_90 = F_36 ( V_29 ) ;
if ( ! V_66 -> V_97 )
F_61 ( & V_2 -> V_46 -> V_2 ,
V_66 -> V_54 -> V_62 , V_66 -> V_54 -> V_64 ,
V_47 ) ;
F_41 ( V_29 , V_90 ) ;
}
static void F_62 ( struct V_109 * V_110 ,
unsigned long V_111 ,
unsigned long * V_68 ,
unsigned long * V_112 )
{
if ( V_110 -> V_111 != V_111 )
* V_68 += 4096 ;
if ( ! F_63 ( & V_110 -> V_113 ) ) {
V_110 = F_64 ( V_110 -> V_113 . V_114 ,
struct V_109 ,
V_113 ) ;
if ( V_110 -> V_115 && V_110 -> V_111 != V_111 )
* V_112 -= 4096 ;
}
}
void F_65 ( struct V_1 * V_2 ,
unsigned long V_68 ,
unsigned long V_116 ,
unsigned long V_112 )
{
T_3 * V_29 = V_2 -> V_30 ;
F_66 ( & V_29 -> V_34 . V_67 , V_68 , V_112 - V_68 - V_95 ) ;
if ( ! F_67 ( V_2 ) )
V_29 -> V_34 . V_67 . V_117 = F_62 ;
V_29 -> V_34 . V_94 = V_68 ;
V_29 -> V_34 . V_118 = V_116 ;
V_29 -> V_34 . V_96 = V_112 ;
V_29 -> V_34 . V_119 = V_112 - V_68 ;
V_29 -> V_34 . V_120 = F_68 ( V_112 , V_116 ) - V_68 ;
F_42 ( V_2 , V_68 / V_95 , ( V_112 - V_68 ) / V_95 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_40 * V_40 ;
T_2 V_121 ;
V_40 = F_10 ( V_38 | V_122 | V_123 ) ;
if ( V_40 == NULL )
return - V_33 ;
F_70 ( V_40 ) ;
F_71 ( V_40 , 1 ) ;
#ifdef F_72
V_121 = F_11 ( V_2 -> V_46 , V_40 , 0 , V_95 ,
V_47 ) ;
if ( F_12 ( V_2 -> V_46 , V_121 ) )
return - V_124 ;
#else
V_121 = F_24 ( V_40 ) ;
#endif
V_29 -> V_34 . V_35 -> V_125 = V_40 ;
V_29 -> V_34 . V_35 -> V_50 = V_121 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
F_74 ( V_29 -> V_34 . V_35 -> V_125 , 1 ) ;
F_13 ( V_2 -> V_46 , V_29 -> V_34 . V_35 -> V_50 ,
V_95 , V_47 ) ;
F_75 ( V_29 -> V_34 . V_35 -> V_125 ) ;
F_15 ( V_29 -> V_34 . V_35 -> V_125 ) ;
}
static inline unsigned int F_76 ( T_6 V_126 )
{
V_126 >>= V_127 ;
V_126 &= V_128 ;
return V_126 << 20 ;
}
static inline unsigned int F_77 ( T_6 V_126 )
{
V_126 >>= V_129 ;
V_126 &= V_130 ;
return V_126 << 25 ;
}
static inline unsigned int F_78 ( T_6 V_126 )
{
static const int V_131 [] = {
0 , 0 , 0 , 0 , 0 , 32 , 48 , 64 , 128 , 256 , 96 , 160 , 224 , 352 } ;
V_126 >>= V_132 ;
V_126 &= V_133 ;
return V_131 [ V_126 ] << 20 ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
T_7 V_134 ;
T_6 V_126 ;
int V_32 ;
if ( F_28 ( V_2 ) -> V_76 < 6 ) {
V_32 = F_80 ( V_29 -> V_135 , V_2 -> V_46 , NULL ) ;
if ( ! V_32 ) {
F_39 ( L_3 ) ;
return - V_48 ;
}
V_29 -> V_34 . V_35 = F_81 () ;
if ( ! V_29 -> V_34 . V_35 ) {
F_39 ( L_4 ) ;
F_82 () ;
return - V_136 ;
}
return 0 ;
}
V_29 -> V_34 . V_35 = F_9 ( sizeof( * V_29 -> V_34 . V_35 ) , V_38 ) ;
if ( ! V_29 -> V_34 . V_35 )
return - V_33 ;
if ( ! F_83 ( V_2 -> V_46 , F_84 ( 40 ) ) )
F_85 ( V_2 -> V_46 , F_84 ( 40 ) ) ;
#ifdef F_72
V_29 -> V_34 . V_35 -> V_43 = 1 ;
#endif
V_134 = F_86 ( V_2 -> V_46 , 0 ) + ( 2 << 20 ) ;
V_29 -> V_34 . V_35 -> V_137 = F_86 ( V_2 -> V_46 , 2 ) ;
F_87 ( V_2 -> V_46 , V_138 , & V_126 ) ;
V_29 -> V_34 . V_35 -> V_36 =
F_76 ( V_126 ) / sizeof( T_1 ) ;
if ( F_28 ( V_2 ) -> V_76 < 7 )
V_29 -> V_34 . V_35 -> V_139 = F_77 ( V_126 ) ;
else
V_29 -> V_34 . V_35 -> V_139 = F_78 ( V_126 ) ;
V_29 -> V_34 . V_35 -> V_140 = F_88 ( V_2 -> V_46 , 2 ) >> V_63 ;
if ( ( V_29 -> V_34 . V_35 -> V_140 >> 8 ) < 64 ||
V_29 -> V_34 . V_35 -> V_140 > V_29 -> V_34 . V_35 -> V_36 ) {
F_39 ( L_5 ,
V_29 -> V_34 . V_35 -> V_140 ) ;
V_32 = - V_141 ;
goto V_142;
}
V_32 = F_69 ( V_2 ) ;
if ( V_32 ) {
F_39 ( L_6 ) ;
goto V_142;
}
V_29 -> V_34 . V_35 -> V_35 = F_89 ( V_134 ,
V_29 -> V_34 . V_35 -> V_36 * sizeof( T_1 ) ) ;
if ( ! V_29 -> V_34 . V_35 -> V_35 ) {
F_39 ( L_7 ) ;
F_73 ( V_2 ) ;
V_32 = - V_33 ;
goto V_142;
}
F_90 ( L_8 , V_29 -> V_34 . V_35 -> V_36 >> 8 ) ;
F_91 ( L_9 , V_29 -> V_34 . V_35 -> V_140 >> 8 ) ;
F_91 ( L_10 , V_29 -> V_34 . V_35 -> V_139 >> 20 ) ;
return 0 ;
V_142:
F_14 ( V_29 -> V_34 . V_35 ) ;
if ( F_28 ( V_2 ) -> V_76 < 6 )
F_82 () ;
return V_32 ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
F_93 ( V_29 -> V_34 . V_35 -> V_35 ) ;
F_73 ( V_2 ) ;
if ( F_28 ( V_2 ) -> V_76 < 6 )
F_82 () ;
F_14 ( V_29 -> V_34 . V_35 ) ;
}
