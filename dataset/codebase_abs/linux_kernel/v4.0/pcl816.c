static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_7 = V_2 -> V_8 + V_9 ;
F_2 ( V_7 , 0 , 0 , V_10 | V_11 ) ;
F_3 ( V_7 , 0 , 0 , 0x00ff ) ;
F_4 ( 1 ) ;
F_2 ( V_7 , 0 , 2 , V_12 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_12 | V_11 ) ;
F_4 ( 1 ) ;
if ( V_3 ) {
F_3 ( V_7 , 0 , 2 , V_5 -> V_13 ) ;
F_3 ( V_7 , 0 , 1 , V_5 -> V_14 ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_18 * V_19 = V_5 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 [ V_19 -> V_22 ] ;
unsigned int V_23 = F_6 ( V_16 , V_21 -> V_24 ) ;
unsigned int V_25 ;
F_7 ( V_19 -> V_26 ) ;
V_25 = F_8 ( V_16 , V_23 + V_17 ) ;
if ( V_25 > V_17 ) {
V_25 -= V_17 ;
V_21 -> V_27 = F_9 ( V_16 , V_25 ) ;
F_10 ( V_21 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_26 ,
unsigned int V_28 )
{
F_12 ( V_26 , V_2 -> V_8 + V_29 ) ;
F_12 ( V_28 , V_2 -> V_8 + V_30 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_31 ,
unsigned int V_32 )
{
F_12 ( F_14 ( V_31 , V_32 ) ,
V_2 -> V_8 + V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int * V_33 ,
unsigned int V_34 )
{
unsigned int V_31 = F_16 ( V_33 [ 0 ] ) ;
unsigned int V_32 ;
unsigned int V_28 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
V_32 = F_16 ( V_33 [ V_35 ] ) ;
V_28 = F_17 ( V_33 [ V_35 ] ) ;
F_11 ( V_2 , V_32 , V_28 ) ;
}
F_4 ( 1 ) ;
F_13 ( V_2 , V_31 , V_32 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_12 ( 0 , V_2 -> V_8 + V_36 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_12 ( 0 , V_2 -> V_8 + V_37 ) ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned int V_38 ;
V_38 = F_21 ( V_2 -> V_8 + V_39 ) << 8 ;
V_38 |= F_21 ( V_2 -> V_8 + V_37 ) ;
return V_38 & V_16 -> V_40 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
unsigned int V_44 ;
V_44 = F_21 ( V_2 -> V_8 + V_45 ) ;
if ( ( V_44 & V_46 ) == 0 )
return 0 ;
return - V_47 ;
}
static bool F_23 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_48 * V_49 = & V_16 -> V_50 -> V_49 ;
if ( V_49 -> V_51 == V_52 &&
V_16 -> V_50 -> V_53 >= V_49 -> V_54 ) {
V_16 -> V_50 -> V_55 |= V_56 ;
return false ;
}
return true ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned short * V_57 ,
unsigned int V_58 , unsigned int V_59 )
{
unsigned short V_38 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_59 ; V_35 ++ ) {
V_38 = V_57 [ V_58 ++ ] ;
F_25 ( V_16 , & V_38 , 1 ) ;
if ( ! F_23 ( V_2 , V_16 ) )
return;
}
}
static T_1 F_26 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
struct V_15 * V_16 = V_2 -> V_62 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_18 * V_19 = V_5 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 [ V_19 -> V_22 ] ;
unsigned int V_25 ;
unsigned int V_58 ;
if ( ! V_2 -> V_63 || ! V_5 -> V_64 ) {
F_18 ( V_2 ) ;
return V_65 ;
}
if ( V_5 -> V_66 ) {
V_5 -> V_66 = 0 ;
F_18 ( V_2 ) ;
return V_65 ;
}
V_25 = F_6 ( V_16 , V_21 -> V_27 ) -
V_5 -> V_67 ;
V_58 = V_5 -> V_67 ;
V_5 -> V_67 = 0 ;
V_19 -> V_22 = 1 - V_19 -> V_22 ;
F_5 ( V_2 , V_16 , V_25 ) ;
F_24 ( V_2 , V_16 , V_21 -> V_68 , V_58 , V_25 ) ;
F_18 ( V_2 ) ;
F_27 ( V_2 , V_16 ) ;
return V_65 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int * V_33 ,
unsigned int V_69 )
{
unsigned int V_70 [ 16 ] ;
unsigned int V_35 , V_71 , V_34 , V_72 ;
if ( V_69 < 1 ) {
F_29 ( V_2 -> V_73 , L_1 ) ;
return 0 ;
}
if ( V_69 > 1 ) {
V_70 [ 0 ] = V_33 [ 0 ] ;
for ( V_35 = 1 , V_34 = 1 ; V_35 < V_69 ; V_35 ++ , V_34 ++ ) {
if ( V_33 [ 0 ] == V_33 [ V_35 ] )
break;
V_71 =
( F_16 ( V_70 [ V_35 - 1 ] ) + 1 ) % V_69 ;
if ( V_71 != F_16 ( V_33 [ V_35 ] ) ) {
F_30 ( V_2 -> V_73 ,
L_2 ,
V_35 , F_16 ( V_33 [ V_35 ] ) , V_71 ,
F_16 ( V_33 [ 0 ] ) ) ;
return 0 ;
}
V_70 [ V_35 ] = V_33 [ V_35 ] ;
}
for ( V_35 = 0 , V_72 = 0 ; V_35 < V_69 ; V_35 ++ ) {
if ( V_33 [ V_35 ] != V_70 [ V_35 % V_34 ] ) {
F_30 ( V_2 -> V_73 ,
L_3 ,
V_35 , F_16 ( V_70 [ V_35 ] ) ,
F_17 ( V_70 [ V_35 ] ) ,
F_31 ( V_70 [ V_35 ] ) ,
F_16 ( V_33 [ V_35 % V_34 ] ) ,
F_17 ( V_33 [ V_35 % V_34 ] ) ,
F_31 ( V_70 [ V_35 % V_34 ] ) ) ;
return 0 ;
}
}
} else {
V_34 = 1 ;
}
return V_34 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_48 * V_49 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_74 = 0 ;
unsigned int V_75 ;
V_74 |= F_33 ( & V_49 -> V_76 , V_77 ) ;
V_74 |= F_33 ( & V_49 -> V_78 , V_79 ) ;
V_74 |= F_33 ( & V_49 -> V_80 , V_81 | V_82 ) ;
V_74 |= F_33 ( & V_49 -> V_83 , V_52 ) ;
V_74 |= F_33 ( & V_49 -> V_51 , V_52 | V_84 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_34 ( V_49 -> V_80 ) ;
V_74 |= F_34 ( V_49 -> V_51 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_35 ( & V_49 -> V_85 , 0 ) ;
V_74 |= F_35 ( & V_49 -> V_86 , 0 ) ;
if ( V_49 -> V_80 == V_82 )
V_74 |= F_36 ( & V_49 -> V_87 , 10000 ) ;
else
V_74 |= F_35 ( & V_49 -> V_87 , 0 ) ;
V_74 |= F_35 ( & V_49 -> V_88 , V_49 -> V_89 ) ;
if ( V_49 -> V_51 == V_52 )
V_74 |= F_36 ( & V_49 -> V_54 , 1 ) ;
else
V_74 |= F_35 ( & V_49 -> V_54 , 0 ) ;
if ( V_74 )
return 3 ;
if ( V_49 -> V_80 == V_82 ) {
V_75 = V_49 -> V_87 ;
F_37 ( V_90 ,
& V_5 -> V_14 ,
& V_5 -> V_13 ,
& V_75 , V_49 -> V_91 ) ;
V_74 |= F_35 ( & V_49 -> V_87 , V_75 ) ;
}
if ( V_74 )
return 4 ;
if ( V_49 -> V_33 ) {
if ( ! F_28 ( V_2 , V_16 , V_49 -> V_33 ,
V_49 -> V_89 ) )
return 5 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_18 * V_19 = V_5 -> V_19 ;
struct V_48 * V_49 = & V_16 -> V_50 -> V_49 ;
unsigned int V_92 ;
unsigned int V_34 ;
if ( V_5 -> V_64 )
return - V_47 ;
F_1 ( V_2 , false ) ;
V_34 = F_28 ( V_2 , V_16 , V_49 -> V_33 , V_49 -> V_89 ) ;
if ( V_34 < 1 )
return - V_93 ;
F_15 ( V_2 , V_49 -> V_33 , V_34 ) ;
F_4 ( 1 ) ;
V_5 -> V_64 = 1 ;
V_5 -> V_67 = 0 ;
V_5 -> V_66 = 0 ;
V_19 -> V_22 = 0 ;
F_5 ( V_2 , V_16 , 0 ) ;
F_1 ( V_2 , true ) ;
V_92 = V_94 | V_95 | V_96 ;
if ( V_49 -> V_80 == V_82 )
V_92 |= V_97 ;
else
V_92 |= V_98 ;
F_12 ( V_92 , V_2 -> V_8 + V_99 ) ;
F_12 ( ( V_19 -> V_26 << 4 ) | V_2 -> V_60 ,
V_2 -> V_8 + V_45 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_18 * V_19 = V_5 -> V_19 ;
struct V_20 * V_21 ;
unsigned long V_91 ;
unsigned int V_100 ;
int V_101 ;
F_40 ( & V_2 -> V_102 , V_91 ) ;
V_100 = F_41 ( V_19 ) ;
V_100 = F_6 ( V_16 , V_100 ) ;
if ( V_100 > V_5 -> V_67 ) {
V_21 = & V_19 -> V_21 [ V_19 -> V_22 ] ;
F_24 ( V_2 , V_16 , V_21 -> V_68 ,
V_5 -> V_67 ,
V_100 - V_5 -> V_67 ) ;
V_5 -> V_67 = V_100 ;
F_27 ( V_2 , V_16 ) ;
V_101 = F_42 ( V_16 ) ;
} else {
V_101 = 0 ;
}
F_43 ( & V_2 -> V_102 , V_91 ) ;
return V_101 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_64 )
return 0 ;
F_12 ( V_103 , V_2 -> V_8 + V_99 ) ;
F_18 ( V_2 ) ;
F_2 ( V_2 -> V_8 + V_9 , 0 ,
2 , V_104 | V_11 ) ;
F_2 ( V_2 -> V_8 + V_9 , 0 ,
1 , V_104 | V_11 ) ;
V_5 -> V_64 = 0 ;
V_5 -> V_66 = 1 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_41 * V_42 ,
unsigned int * V_105 )
{
unsigned int V_26 = F_16 ( V_42 -> V_106 ) ;
unsigned int V_28 = F_17 ( V_42 -> V_106 ) ;
int V_101 = 0 ;
int V_35 ;
F_12 ( V_107 , V_2 -> V_8 + V_99 ) ;
F_11 ( V_2 , V_26 , V_28 ) ;
F_13 ( V_2 , V_26 , V_26 ) ;
for ( V_35 = 0 ; V_35 < V_42 -> V_108 ; V_35 ++ ) {
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
V_101 = F_46 ( V_2 , V_16 , V_42 , F_22 , 0 ) ;
if ( V_101 )
break;
V_105 [ V_35 ] = F_20 ( V_2 , V_16 ) ;
}
F_12 ( V_103 , V_2 -> V_8 + V_99 ) ;
F_18 ( V_2 ) ;
return V_101 ? V_101 : V_42 -> V_108 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_41 * V_42 ,
unsigned int * V_105 )
{
V_105 [ 1 ] = F_21 ( V_2 -> V_8 + V_109 ) |
( F_21 ( V_2 -> V_8 + V_110 ) << 8 ) ;
return V_42 -> V_108 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_41 * V_42 ,
unsigned int * V_105 )
{
if ( F_49 ( V_16 , V_105 ) ) {
F_12 ( V_16 -> V_111 & 0xff , V_2 -> V_8 + V_109 ) ;
F_12 ( ( V_16 -> V_111 >> 8 ) , V_2 -> V_8 + V_110 ) ;
}
V_105 [ 1 ] = V_16 -> V_111 ;
return V_42 -> V_108 ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_2 -> V_8 + V_9 ;
F_12 ( V_103 , V_2 -> V_8 + V_99 ) ;
F_11 ( V_2 , 0 , 0 ) ;
F_18 ( V_2 ) ;
F_2 ( V_7 , 0 , 2 , V_104 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_104 | V_11 ) ;
F_2 ( V_7 , 0 , 0 , V_104 | V_11 ) ;
F_12 ( 0 , V_2 -> V_8 + V_109 ) ;
F_12 ( 0 , V_2 -> V_8 + V_110 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_114 = V_113 -> V_115 [ 1 ] ;
unsigned int V_116 = V_113 -> V_115 [ 2 ] ;
if ( ! ( V_114 >= 2 && V_114 <= 7 ) ||
! ( V_116 == 3 || V_116 == 1 ) )
return;
if ( F_52 ( V_114 , F_26 , 0 , V_2 -> V_117 , V_2 ) )
return;
V_5 -> V_19 = F_53 ( V_2 , 2 , V_116 , V_116 ,
V_118 * 4 , V_119 ) ;
if ( ! V_5 -> V_19 )
F_54 ( V_114 , V_2 ) ;
else
V_2 -> V_60 = V_114 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 )
F_56 ( V_5 -> V_19 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
const struct V_120 * V_121 = V_2 -> V_122 ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
int V_101 ;
V_5 = F_58 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_123 ;
V_101 = F_59 ( V_2 , V_113 -> V_115 [ 0 ] , 0x10 ) ;
if ( V_101 )
return V_101 ;
F_51 ( V_2 , V_113 ) ;
V_101 = F_60 ( V_2 , 4 ) ;
if ( V_101 )
return V_101 ;
V_16 = & V_2 -> V_124 [ 0 ] ;
V_16 -> type = V_125 ;
V_16 -> V_126 = V_127 | V_128 ;
V_16 -> V_129 = 16 ;
V_16 -> V_40 = V_121 -> V_130 ;
V_16 -> V_131 = & V_132 ;
V_16 -> V_133 = F_45 ;
if ( V_2 -> V_60 ) {
V_2 -> V_62 = V_16 ;
V_16 -> V_126 |= V_127 ;
V_16 -> V_134 = V_121 -> V_135 ;
V_16 -> V_136 = F_32 ;
V_16 -> V_137 = F_38 ;
V_16 -> V_100 = F_39 ;
V_16 -> V_138 = F_44 ;
}
V_16 = & V_2 -> V_124 [ 2 ] ;
V_16 -> type = V_139 ;
#if 0
subdevs[1] = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 1;
s->maxdata = board->ao_maxdata;
s->range_table = &range_pcl816;
#endif
V_16 = & V_2 -> V_124 [ 2 ] ;
V_16 -> type = V_140 ;
V_16 -> V_126 = V_141 ;
V_16 -> V_129 = 16 ;
V_16 -> V_40 = 1 ;
V_16 -> V_131 = & V_142 ;
V_16 -> V_143 = F_47 ;
V_16 = & V_2 -> V_124 [ 3 ] ;
V_16 -> type = V_144 ;
V_16 -> V_126 = V_145 ;
V_16 -> V_129 = 16 ;
V_16 -> V_40 = 1 ;
V_16 -> V_131 = & V_142 ;
V_16 -> V_143 = F_48 ;
F_50 ( V_2 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 ) {
F_44 ( V_2 , V_2 -> V_62 ) ;
F_50 ( V_2 ) ;
}
F_55 ( V_2 ) ;
F_62 ( V_2 ) ;
}
