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
struct V_17 * V_18 = & V_16 -> V_19 -> V_18 ;
if ( V_18 -> V_23 == V_24 &&
V_16 -> V_19 -> V_54 >= V_18 -> V_25 ) {
V_16 -> V_19 -> V_55 |= V_56 ;
return false ;
}
return true ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned short * V_57 ,
unsigned int V_58 , unsigned int V_59 )
{
unsigned short V_44 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_59 ; V_41 ++ ) {
V_44 = V_57 [ V_58 ++ ] ;
F_30 ( V_16 , & V_44 , 1 ) ;
if ( ! F_28 ( V_2 , V_16 ) )
return;
}
}
static T_1 F_31 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
struct V_15 * V_16 = V_2 -> V_62 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned short * V_57 ;
unsigned int V_58 ;
unsigned int V_59 ;
if ( ! V_2 -> V_63 || ! V_5 -> V_64 ) {
F_23 ( V_2 ) ;
return V_65 ;
}
if ( V_5 -> V_66 ) {
V_5 -> V_66 = 0 ;
F_23 ( V_2 ) ;
return V_65 ;
}
V_57 = ( unsigned short * ) V_5 -> V_67 [ V_5 -> V_28 ] ;
F_14 ( V_2 , V_16 ) ;
V_59 = ( V_5 -> V_22 >> 1 ) - V_5 -> V_68 ;
V_58 = V_5 -> V_68 ;
V_5 -> V_68 = 0 ;
F_29 ( V_2 , V_16 , V_57 , V_58 , V_59 ) ;
F_23 ( V_2 ) ;
F_32 ( V_2 , V_16 ) ;
return V_65 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int * V_39 ,
unsigned int V_69 )
{
unsigned int V_70 [ 16 ] ;
unsigned int V_41 , V_71 , V_40 , V_72 ;
if ( V_69 < 1 ) {
F_34 ( V_2 -> V_73 , L_1 ) ;
return 0 ;
}
if ( V_69 > 1 ) {
V_70 [ 0 ] = V_39 [ 0 ] ;
for ( V_41 = 1 , V_40 = 1 ; V_41 < V_69 ; V_41 ++ , V_40 ++ ) {
if ( V_39 [ 0 ] == V_39 [ V_41 ] )
break;
V_71 =
( F_21 ( V_70 [ V_41 - 1 ] ) + 1 ) % V_69 ;
if ( V_71 != F_21 ( V_39 [ V_41 ] ) ) {
F_35 ( V_2 -> V_73 ,
L_2 ,
V_41 , F_21 ( V_39 [ V_41 ] ) , V_71 ,
F_21 ( V_39 [ 0 ] ) ) ;
return 0 ;
}
V_70 [ V_41 ] = V_39 [ V_41 ] ;
}
for ( V_41 = 0 , V_72 = 0 ; V_41 < V_69 ; V_41 ++ ) {
if ( V_39 [ V_41 ] != V_70 [ V_41 % V_40 ] ) {
F_35 ( V_2 -> V_73 ,
L_3 ,
V_41 , F_21 ( V_70 [ V_41 ] ) ,
F_22 ( V_70 [ V_41 ] ) ,
F_36 ( V_70 [ V_41 ] ) ,
F_21 ( V_39 [ V_41 % V_40 ] ) ,
F_22 ( V_39 [ V_41 % V_40 ] ) ,
F_36 ( V_70 [ V_41 % V_40 ] ) ) ;
return 0 ;
}
}
} else {
V_40 = 1 ;
}
return V_40 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_74 = 0 ;
unsigned int V_75 ;
V_74 |= F_38 ( & V_18 -> V_76 , V_77 ) ;
V_74 |= F_38 ( & V_18 -> V_78 , V_79 ) ;
V_74 |= F_38 ( & V_18 -> V_80 , V_81 | V_82 ) ;
V_74 |= F_38 ( & V_18 -> V_83 , V_24 ) ;
V_74 |= F_38 ( & V_18 -> V_23 , V_24 | V_32 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_39 ( V_18 -> V_80 ) ;
V_74 |= F_39 ( V_18 -> V_23 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_40 ( & V_18 -> V_84 , 0 ) ;
V_74 |= F_40 ( & V_18 -> V_85 , 0 ) ;
if ( V_18 -> V_80 == V_82 )
V_74 |= F_41 ( & V_18 -> V_86 , 10000 ) ;
else
V_74 |= F_40 ( & V_18 -> V_86 , 0 ) ;
V_74 |= F_40 ( & V_18 -> V_87 , V_18 -> V_88 ) ;
if ( V_18 -> V_23 == V_24 )
V_74 |= F_41 ( & V_18 -> V_25 , 1 ) ;
else
V_74 |= F_40 ( & V_18 -> V_25 , 0 ) ;
if ( V_74 )
return 3 ;
if ( V_18 -> V_80 == V_82 ) {
V_75 = V_18 -> V_86 ;
F_42 ( V_89 ,
& V_5 -> V_14 ,
& V_5 -> V_13 ,
& V_75 , V_18 -> V_90 ) ;
V_74 |= F_40 ( & V_18 -> V_86 , V_75 ) ;
}
if ( V_74 )
return 4 ;
if ( V_18 -> V_39 ) {
if ( ! F_33 ( V_2 , V_16 , V_18 -> V_39 ,
V_18 -> V_88 ) )
return 5 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_18 ;
unsigned int V_91 ;
unsigned int V_40 ;
if ( V_5 -> V_64 )
return - V_53 ;
F_1 ( V_2 , false ) ;
V_40 = F_33 ( V_2 , V_16 , V_18 -> V_39 , V_18 -> V_88 ) ;
if ( V_40 < 1 )
return - V_92 ;
F_20 ( V_2 , V_18 -> V_39 , V_40 ) ;
F_4 ( 1 ) ;
V_5 -> V_64 = 1 ;
V_5 -> V_68 = 0 ;
V_5 -> V_66 = 0 ;
F_5 ( V_2 , V_16 ) ;
F_1 ( V_2 , true ) ;
V_91 = V_93 | V_94 | V_95 ;
if ( V_18 -> V_80 == V_82 )
V_91 |= V_96 ;
else
V_91 |= V_97 ;
F_17 ( V_91 , V_2 -> V_8 + V_98 ) ;
F_17 ( ( V_5 -> V_29 << 4 ) | V_2 -> V_60 , V_2 -> V_8 + V_51 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_90 ;
unsigned int V_99 , V_100 , V_41 ;
F_45 ( & V_2 -> V_101 , V_90 ) ;
for ( V_41 = 0 ; V_41 < 20 ; V_41 ++ ) {
V_99 = F_46 ( V_5 -> V_29 ) ;
V_100 = F_46 ( V_5 -> V_29 ) ;
if ( V_99 == V_100 )
break;
}
if ( V_99 != V_100 ) {
F_47 ( & V_2 -> V_101 , V_90 ) ;
return 0 ;
}
V_99 = V_5 -> V_22 - V_99 ;
V_99 >>= 1 ;
V_100 = V_99 - V_5 -> V_68 ;
if ( V_100 < 1 ) {
F_47 ( & V_2 -> V_101 , V_90 ) ;
return 0 ;
}
F_29 ( V_2 , V_16 ,
( unsigned short * ) V_5 -> V_67 [ V_5 ->
V_28 ] ,
V_5 -> V_68 , V_100 ) ;
V_5 -> V_68 = V_99 ;
F_47 ( & V_2 -> V_101 , V_90 ) ;
F_32 ( V_2 , V_16 ) ;
return F_48 ( V_16 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_64 )
return 0 ;
F_17 ( V_102 , V_2 -> V_8 + V_98 ) ;
F_23 ( V_2 ) ;
F_2 ( V_2 -> V_8 + V_9 , 0 ,
2 , V_103 | V_11 ) ;
F_2 ( V_2 -> V_8 + V_9 , 0 ,
1 , V_103 | V_11 ) ;
V_5 -> V_64 = 0 ;
V_5 -> V_66 = 1 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned int * V_104 )
{
unsigned int V_33 = F_21 ( V_48 -> V_105 ) ;
unsigned int V_34 = F_22 ( V_48 -> V_105 ) ;
int V_106 = 0 ;
int V_41 ;
F_17 ( V_107 , V_2 -> V_8 + V_98 ) ;
F_16 ( V_2 , V_33 , V_34 ) ;
F_18 ( V_2 , V_33 , V_33 ) ;
for ( V_41 = 0 ; V_41 < V_48 -> V_108 ; V_41 ++ ) {
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_106 = F_51 ( V_2 , V_16 , V_48 , F_27 , 0 ) ;
if ( V_106 )
break;
V_104 [ V_41 ] = F_25 ( V_2 , V_16 ) ;
}
F_17 ( V_102 , V_2 -> V_8 + V_98 ) ;
F_23 ( V_2 ) ;
return V_106 ? V_106 : V_48 -> V_108 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned int * V_104 )
{
V_104 [ 1 ] = F_26 ( V_2 -> V_8 + V_109 ) |
( F_26 ( V_2 -> V_8 + V_110 ) << 8 ) ;
return V_48 -> V_108 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_47 * V_48 ,
unsigned int * V_104 )
{
if ( F_54 ( V_16 , V_104 ) ) {
F_17 ( V_16 -> V_111 & 0xff , V_2 -> V_8 + V_109 ) ;
F_17 ( ( V_16 -> V_111 >> 8 ) , V_2 -> V_8 + V_110 ) ;
}
V_104 [ 1 ] = V_16 -> V_111 ;
return V_48 -> V_108 ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_2 -> V_8 + V_9 ;
F_17 ( V_102 , V_2 -> V_8 + V_98 ) ;
F_16 ( V_2 , 0 , 0 ) ;
F_23 ( V_2 ) ;
F_2 ( V_7 , 0 , 2 , V_103 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_103 | V_11 ) ;
F_2 ( V_7 , 0 , 0 , V_103 | V_11 ) ;
F_17 ( 0 , V_2 -> V_8 + V_109 ) ;
F_17 ( 0 , V_2 -> V_8 + V_110 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
const struct V_114 * V_115 = V_2 -> V_116 ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
int V_106 ;
int V_41 ;
V_5 = F_57 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_117 ;
V_106 = F_58 ( V_2 , V_113 -> V_118 [ 0 ] , 0x10 ) ;
if ( V_106 )
return V_106 ;
if ( V_113 -> V_118 [ 1 ] >= 2 && V_113 -> V_118 [ 1 ] <= 7 ) {
V_106 = F_59 ( V_113 -> V_118 [ 1 ] , F_31 , 0 ,
V_2 -> V_119 , V_2 ) ;
if ( V_106 == 0 )
V_2 -> V_60 = V_113 -> V_118 [ 1 ] ;
}
if ( V_2 -> V_60 && ( V_113 -> V_118 [ 2 ] == 3 || V_113 -> V_118 [ 2 ] == 1 ) ) {
V_106 = F_60 ( V_113 -> V_118 [ 2 ] , V_2 -> V_119 ) ;
if ( V_106 ) {
F_34 ( V_2 -> V_73 ,
L_4 ,
V_113 -> V_118 [ 2 ] ) ;
return - V_53 ;
}
V_5 -> V_29 = V_113 -> V_118 [ 2 ] ;
V_5 -> V_120 = 2 ;
V_5 -> V_22 = ( 1 << V_5 -> V_120 ) * V_121 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
unsigned long V_67 ;
V_67 = F_61 ( V_122 , V_5 -> V_120 ) ;
if ( ! V_67 )
return - V_117 ;
V_5 -> V_67 [ V_41 ] = V_67 ;
V_5 -> V_31 [ V_41 ] = F_62 ( ( void * ) V_67 ) ;
}
}
V_106 = F_63 ( V_2 , 4 ) ;
if ( V_106 )
return V_106 ;
V_16 = & V_2 -> V_123 [ 0 ] ;
V_16 -> type = V_124 ;
V_16 -> V_125 = V_126 | V_127 ;
V_16 -> V_128 = 16 ;
V_16 -> V_46 = V_115 -> V_129 ;
V_16 -> V_130 = & V_131 ;
V_16 -> V_132 = F_50 ;
if ( V_5 -> V_29 ) {
V_2 -> V_62 = V_16 ;
V_16 -> V_125 |= V_126 ;
V_16 -> V_133 = V_115 -> V_134 ;
V_16 -> V_135 = F_37 ;
V_16 -> V_136 = F_43 ;
V_16 -> V_137 = F_44 ;
V_16 -> V_138 = F_49 ;
}
V_16 = & V_2 -> V_123 [ 2 ] ;
V_16 -> type = V_139 ;
#if 0
subdevs[1] = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 1;
s->maxdata = board->ao_maxdata;
s->range_table = &range_pcl816;
#endif
V_16 = & V_2 -> V_123 [ 2 ] ;
V_16 -> type = V_140 ;
V_16 -> V_125 = V_141 ;
V_16 -> V_128 = 16 ;
V_16 -> V_46 = 1 ;
V_16 -> V_130 = & V_142 ;
V_16 -> V_143 = F_52 ;
V_16 = & V_2 -> V_123 [ 3 ] ;
V_16 -> type = V_144 ;
V_16 -> V_125 = V_145 ;
V_16 -> V_128 = 16 ;
V_16 -> V_46 = 1 ;
V_16 -> V_130 = & V_142 ;
V_16 -> V_143 = F_53 ;
F_55 ( V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_6 ) {
F_49 ( V_2 , V_2 -> V_62 ) ;
F_55 ( V_2 ) ;
if ( V_5 -> V_29 )
F_65 ( V_5 -> V_29 ) ;
if ( V_5 -> V_67 [ 0 ] )
F_66 ( V_5 -> V_67 [ 0 ] , V_5 -> V_120 ) ;
if ( V_5 -> V_67 [ 1 ] )
F_66 ( V_5 -> V_67 [ 1 ] , V_5 -> V_120 ) ;
}
F_67 ( V_2 ) ;
}
