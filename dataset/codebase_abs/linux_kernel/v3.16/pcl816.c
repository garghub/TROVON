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
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_18 ;
unsigned int V_20 ;
unsigned int V_21 ;
V_21 = V_5 -> V_22 ;
if ( V_18 -> V_23 == V_24 ) {
V_21 = V_18 -> V_25 * F_6 ( V_16 ) ;
V_5 -> V_26 = V_21 / V_5 -> V_22 ;
V_5 -> V_27 = V_21 % V_5 -> V_22 ;
V_5 -> V_26 -- ;
if ( V_5 -> V_26 >= 0 )
V_21 = V_5 -> V_22 ;
} else
V_5 -> V_26 = - 1 ;
V_5 -> V_28 = 0 ;
F_7 ( V_5 -> V_29 , V_30 ) ;
V_20 = F_8 () ;
F_9 ( V_5 -> V_29 ) ;
F_10 ( V_5 -> V_29 , V_5 -> V_31 [ 0 ] ) ;
F_11 ( V_5 -> V_29 , V_21 ) ;
F_12 ( V_20 ) ;
F_13 ( V_5 -> V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_18 ;
unsigned long V_20 ;
F_15 ( V_5 -> V_29 ) ;
if ( V_5 -> V_26 > - 1 || V_18 -> V_23 == V_32 ) {
V_5 -> V_28 = 1 - V_5 -> V_28 ;
F_7 ( V_5 -> V_29 , V_30 ) ;
V_20 = F_8 () ;
F_10 ( V_5 -> V_29 ,
V_5 -> V_31 [ V_5 -> V_28 ] ) ;
if ( V_5 -> V_26 )
F_11 ( V_5 -> V_29 , V_5 -> V_22 ) ;
else
F_11 ( V_5 -> V_29 , V_5 -> V_27 ) ;
F_12 ( V_20 ) ;
F_13 ( V_5 -> V_29 ) ;
}
V_5 -> V_26 -- ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_33 ,
unsigned int V_34 )
{
F_17 ( V_33 , V_2 -> V_8 + V_35 ) ;
F_17 ( V_34 , V_2 -> V_8 + V_36 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_37 ,
unsigned int V_38 )
{
F_17 ( F_19 ( V_37 , V_38 ) ,
V_2 -> V_8 + V_35 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
unsigned int * V_39 ,
unsigned int V_40 )
{
unsigned int V_37 = F_21 ( V_39 [ 0 ] ) ;
unsigned int V_38 ;
unsigned int V_34 ;
unsigned int V_41 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
V_38 = F_21 ( V_39 [ V_41 ] ) ;
V_34 = F_22 ( V_39 [ V_41 ] ) ;
F_16 ( V_2 , V_38 , V_34 ) ;
}
F_4 ( 1 ) ;
F_18 ( V_2 , V_37 , V_38 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_17 ( 0 , V_2 -> V_8 + V_42 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_17 ( 0 , V_2 -> V_8 + V_43 ) ;
}
static unsigned int F_25 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned int V_44 ;
V_44 = F_26 ( V_2 -> V_8 + V_45 ) << 8 ;
V_44 |= F_26 ( V_2 -> V_8 + V_43 ) ;
return V_44 & V_16 -> V_46 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned long V_49 )
{
unsigned int V_50 ;
V_50 = F_26 ( V_2 -> V_8 + V_51 ) ;
if ( ( V_50 & V_52 ) == 0 )
return 0 ;
return - V_53 ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_18 ;
V_16 -> V_19 -> V_54 |= V_55 ;
V_16 -> V_19 -> V_56 ++ ;
if ( V_16 -> V_19 -> V_56 >= V_18 -> V_57 ) {
V_16 -> V_19 -> V_56 = 0 ;
V_5 -> V_58 ++ ;
V_16 -> V_19 -> V_54 |= V_59 ;
}
if ( V_18 -> V_23 == V_24 &&
V_5 -> V_58 >= V_18 -> V_25 ) {
V_16 -> V_19 -> V_54 |= V_60 ;
return false ;
}
return true ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned short * V_61 ,
unsigned int V_62 , unsigned int V_63 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_63 ; V_41 ++ ) {
F_30 ( V_16 , V_61 [ V_62 ++ ] ) ;
if ( ! F_28 ( V_2 , V_16 ) )
return;
}
}
static T_1 F_31 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
struct V_15 * V_16 = V_2 -> V_66 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned short * V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
if ( ! V_2 -> V_67 || ! V_5 -> V_68 ) {
F_23 ( V_2 ) ;
return V_69 ;
}
if ( V_5 -> V_70 ) {
V_5 -> V_70 = 0 ;
F_23 ( V_2 ) ;
return V_69 ;
}
V_61 = ( unsigned short * ) V_5 -> V_71 [ V_5 -> V_28 ] ;
F_14 ( V_2 , V_16 ) ;
V_63 = ( V_5 -> V_22 >> 1 ) - V_5 -> V_72 ;
V_62 = V_5 -> V_72 ;
V_5 -> V_72 = 0 ;
F_29 ( V_2 , V_16 , V_61 , V_62 , V_63 ) ;
F_23 ( V_2 ) ;
F_32 ( V_2 , V_16 ) ;
return V_69 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_73 = 0 ;
unsigned int V_74 ;
V_73 |= F_34 ( & V_18 -> V_75 , V_76 ) ;
V_73 |= F_34 ( & V_18 -> V_77 , V_78 ) ;
V_73 |= F_34 ( & V_18 -> V_79 , V_80 | V_81 ) ;
V_73 |= F_34 ( & V_18 -> V_82 , V_24 ) ;
V_73 |= F_34 ( & V_18 -> V_23 , V_24 | V_32 ) ;
if ( V_73 )
return 1 ;
V_73 |= F_35 ( V_18 -> V_79 ) ;
V_73 |= F_35 ( V_18 -> V_23 ) ;
if ( V_73 )
return 2 ;
V_73 |= F_36 ( & V_18 -> V_83 , 0 ) ;
V_73 |= F_36 ( & V_18 -> V_84 , 0 ) ;
if ( V_18 -> V_79 == V_81 )
V_73 |= F_37 ( & V_18 -> V_85 , 10000 ) ;
else
V_73 |= F_36 ( & V_18 -> V_85 , 0 ) ;
V_73 |= F_36 ( & V_18 -> V_86 , V_18 -> V_57 ) ;
if ( V_18 -> V_23 == V_24 )
V_73 |= F_37 ( & V_18 -> V_25 , 1 ) ;
else
V_73 |= F_36 ( & V_18 -> V_25 , 0 ) ;
if ( V_73 )
return 3 ;
if ( V_18 -> V_79 == V_81 ) {
V_74 = V_18 -> V_85 ;
F_38 ( V_87 ,
& V_5 -> V_14 ,
& V_5 -> V_13 ,
& V_74 , V_18 -> V_88 ) ;
V_73 |= F_36 ( & V_18 -> V_85 , V_74 ) ;
}
if ( V_73 )
return 4 ;
if ( V_18 -> V_39 ) {
if ( ! F_39 ( V_2 , V_16 , V_18 -> V_39 ,
V_18 -> V_57 ) )
return 5 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_18 ;
unsigned int V_89 ;
unsigned int V_40 ;
if ( V_5 -> V_68 )
return - V_53 ;
F_1 ( V_2 , false ) ;
V_40 = F_39 ( V_2 , V_16 , V_18 -> V_39 , V_18 -> V_57 ) ;
if ( V_40 < 1 )
return - V_90 ;
F_20 ( V_2 , V_18 -> V_39 , V_40 ) ;
F_4 ( 1 ) ;
V_5 -> V_58 = 0 ;
V_16 -> V_19 -> V_56 = 0 ;
V_5 -> V_68 = 1 ;
V_5 -> V_72 = 0 ;
V_5 -> V_70 = 0 ;
F_5 ( V_2 , V_16 ) ;
F_1 ( V_2 , true ) ;
V_89 = V_91 | V_92 | V_93 ;
if ( V_18 -> V_79 == V_81 )
V_89 |= V_94 ;
else
V_89 |= V_95 ;
F_17 ( V_89 , V_2 -> V_8 + V_96 ) ;
F_17 ( ( V_5 -> V_29 << 4 ) | V_2 -> V_64 , V_2 -> V_8 + V_51 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_88 ;
unsigned int V_97 , V_98 , V_41 ;
F_42 ( & V_2 -> V_99 , V_88 ) ;
for ( V_41 = 0 ; V_41 < 20 ; V_41 ++ ) {
V_97 = F_43 ( V_5 -> V_29 ) ;
V_98 = F_43 ( V_5 -> V_29 ) ;
if ( V_97 == V_98 )
break;
}
if ( V_97 != V_98 ) {
F_44 ( & V_2 -> V_99 , V_88 ) ;
return 0 ;
}
V_97 = V_5 -> V_22 - V_97 ;
V_97 >>= 1 ;
V_98 = V_97 - V_5 -> V_72 ;
if ( V_98 < 1 ) {
F_44 ( & V_2 -> V_99 , V_88 ) ;
return 0 ;
}
F_29 ( V_2 , V_16 ,
( unsigned short * ) V_5 -> V_71 [ V_5 ->
V_28 ] ,
V_5 -> V_72 , V_98 ) ;
V_5 -> V_72 = V_97 ;
F_44 ( & V_2 -> V_99 , V_88 ) ;
F_32 ( V_2 , V_16 ) ;
return V_16 -> V_19 -> V_100 - V_16 -> V_19 -> V_101 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_68 )
return 0 ;
F_17 ( V_102 , V_2 -> V_8 + V_96 ) ;
F_23 ( V_2 ) ;
F_2 ( V_2 -> V_8 + V_9 , 0 ,
2 , V_103 | V_11 ) ;
F_2 ( V_2 -> V_8 + V_9 , 0 ,
1 , V_103 | V_11 ) ;
V_5 -> V_68 = 0 ;
V_5 -> V_70 = 1 ;
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned int * V_39 ,
unsigned int V_104 )
{
unsigned int V_105 [ 16 ] ;
unsigned int V_41 , V_106 , V_40 , V_107 ;
if ( V_104 < 1 ) {
F_46 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_104 > 1 ) {
V_105 [ 0 ] = V_39 [ 0 ] ;
for ( V_41 = 1 , V_40 = 1 ; V_41 < V_104 ; V_41 ++ , V_40 ++ ) {
if ( V_39 [ 0 ] == V_39 [ V_41 ] )
break;
V_106 =
( F_21 ( V_105 [ V_41 - 1 ] ) + 1 ) % V_104 ;
if ( V_106 != F_21 ( V_39 [ V_41 ] ) ) {
F_47 ( V_2 -> V_108 ,
L_2 ,
V_41 , F_21 ( V_39 [ V_41 ] ) , V_106 ,
F_21 ( V_39 [ 0 ] ) ) ;
return 0 ;
}
V_105 [ V_41 ] = V_39 [ V_41 ] ;
}
for ( V_41 = 0 , V_107 = 0 ; V_41 < V_104 ; V_41 ++ ) {
if ( V_39 [ V_41 ] != V_105 [ V_41 % V_40 ] ) {
F_47 ( V_2 -> V_108 ,
L_3 ,
V_41 , F_21 ( V_105 [ V_41 ] ) ,
F_22 ( V_105 [ V_41 ] ) ,
F_48 ( V_105 [ V_41 ] ) ,
F_21 ( V_39 [ V_41 % V_40 ] ) ,
F_22 ( V_39 [ V_41 % V_40 ] ) ,
F_48 ( V_105 [ V_41 % V_40 ] ) ) ;
return 0 ;
}
}
} else {
V_40 = 1 ;
}
return V_40 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned int * V_109 )
{
unsigned int V_33 = F_21 ( V_48 -> V_110 ) ;
unsigned int V_34 = F_22 ( V_48 -> V_110 ) ;
int V_111 = 0 ;
int V_41 ;
F_17 ( V_112 , V_2 -> V_8 + V_96 ) ;
F_16 ( V_2 , V_33 , V_34 ) ;
F_18 ( V_2 , V_33 , V_33 ) ;
for ( V_41 = 0 ; V_41 < V_48 -> V_113 ; V_41 ++ ) {
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_111 = F_50 ( V_2 , V_16 , V_48 , F_27 , 0 ) ;
if ( V_111 )
break;
V_109 [ V_41 ] = F_25 ( V_2 , V_16 ) ;
}
F_17 ( V_102 , V_2 -> V_8 + V_96 ) ;
F_23 ( V_2 ) ;
return V_111 ? V_111 : V_48 -> V_113 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned int * V_109 )
{
V_109 [ 1 ] = F_26 ( V_2 -> V_8 + V_114 ) |
( F_26 ( V_2 -> V_8 + V_115 ) << 8 ) ;
return V_48 -> V_113 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned int * V_109 )
{
if ( F_53 ( V_16 , V_109 ) ) {
F_17 ( V_16 -> V_116 & 0xff , V_2 -> V_8 + V_114 ) ;
F_17 ( ( V_16 -> V_116 >> 8 ) , V_2 -> V_8 + V_115 ) ;
}
V_109 [ 1 ] = V_16 -> V_116 ;
return V_48 -> V_113 ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_2 -> V_8 + V_9 ;
F_17 ( V_102 , V_2 -> V_8 + V_96 ) ;
F_16 ( V_2 , 0 , 0 ) ;
F_23 ( V_2 ) ;
F_2 ( V_7 , 0 , 2 , V_103 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_103 | V_11 ) ;
F_2 ( V_7 , 0 , 0 , V_103 | V_11 ) ;
F_17 ( 0 , V_2 -> V_8 + V_114 ) ;
F_17 ( 0 , V_2 -> V_8 + V_115 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
const struct V_119 * V_120 = F_56 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
int V_111 ;
int V_41 ;
V_5 = F_57 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_121 ;
V_111 = F_58 ( V_2 , V_118 -> V_122 [ 0 ] , 0x10 ) ;
if ( V_111 )
return V_111 ;
if ( V_118 -> V_122 [ 1 ] >= 2 && V_118 -> V_122 [ 1 ] <= 7 ) {
V_111 = F_59 ( V_118 -> V_122 [ 1 ] , F_31 , 0 ,
V_2 -> V_123 , V_2 ) ;
if ( V_111 == 0 )
V_2 -> V_64 = V_118 -> V_122 [ 1 ] ;
}
if ( V_2 -> V_64 && ( V_118 -> V_122 [ 2 ] == 3 || V_118 -> V_122 [ 2 ] == 1 ) ) {
V_111 = F_60 ( V_118 -> V_122 [ 2 ] , V_2 -> V_123 ) ;
if ( V_111 ) {
F_61 ( V_2 -> V_108 ,
L_4 ,
V_118 -> V_122 [ 2 ] ) ;
return - V_53 ;
}
V_5 -> V_29 = V_118 -> V_122 [ 2 ] ;
V_5 -> V_124 = 2 ;
V_5 -> V_22 = ( 1 << V_5 -> V_124 ) * V_125 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
unsigned long V_71 ;
V_71 = F_62 ( V_126 , V_5 -> V_124 ) ;
if ( ! V_71 )
return - V_121 ;
V_5 -> V_71 [ V_41 ] = V_71 ;
V_5 -> V_31 [ V_41 ] = F_63 ( ( void * ) V_71 ) ;
}
}
V_111 = F_64 ( V_2 , 4 ) ;
if ( V_111 )
return V_111 ;
V_16 = & V_2 -> V_127 [ 0 ] ;
V_16 -> type = V_128 ;
V_16 -> V_129 = V_130 | V_131 ;
V_16 -> V_132 = 16 ;
V_16 -> V_46 = V_120 -> V_133 ;
V_16 -> V_134 = & V_135 ;
V_16 -> V_136 = F_49 ;
if ( V_5 -> V_29 ) {
V_2 -> V_66 = V_16 ;
V_16 -> V_129 |= V_130 ;
V_16 -> V_137 = V_120 -> V_138 ;
V_16 -> V_139 = F_33 ;
V_16 -> V_140 = F_40 ;
V_16 -> V_141 = F_41 ;
V_16 -> V_142 = F_45 ;
}
V_16 = & V_2 -> V_127 [ 2 ] ;
V_16 -> type = V_143 ;
#if 0
subdevs[1] = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 1;
s->maxdata = board->ao_maxdata;
s->range_table = &range_pcl816;
#endif
V_16 = & V_2 -> V_127 [ 2 ] ;
V_16 -> type = V_144 ;
V_16 -> V_129 = V_145 ;
V_16 -> V_132 = 16 ;
V_16 -> V_46 = 1 ;
V_16 -> V_134 = & V_146 ;
V_16 -> V_147 = F_51 ;
V_16 = & V_2 -> V_127 [ 3 ] ;
V_16 -> type = V_148 ;
V_16 -> V_129 = V_149 ;
V_16 -> V_132 = 16 ;
V_16 -> V_46 = 1 ;
V_16 -> V_134 = & V_146 ;
V_16 -> V_147 = F_52 ;
F_54 ( V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_6 ) {
F_45 ( V_2 , V_2 -> V_66 ) ;
F_54 ( V_2 ) ;
if ( V_5 -> V_29 )
F_66 ( V_5 -> V_29 ) ;
if ( V_5 -> V_71 [ 0 ] )
F_67 ( V_5 -> V_71 [ 0 ] , V_5 -> V_124 ) ;
if ( V_5 -> V_71 [ 1 ] )
F_67 ( V_5 -> V_71 [ 1 ] , V_5 -> V_124 ) ;
}
F_68 ( V_2 ) ;
}
