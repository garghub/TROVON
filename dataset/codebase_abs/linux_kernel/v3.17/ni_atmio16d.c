static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0xFFC2 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF02 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x4 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0A , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x3 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF42 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF42 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFC4 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF03 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x4 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0B , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x3 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFC8 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF04 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x4 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0C , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x3 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFD0 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF05 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x4 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0D , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x3 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF50 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF50 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
F_2 ( 0 , V_2 -> V_3 + V_11 ) ;
F_2 ( 0 , V_2 -> V_3 + V_12 ) ;
F_2 ( 0 , V_2 -> V_3 + V_13 ) ;
F_2 ( 0xFFFF , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFEF , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF17 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xF000 , V_2 -> V_3 + V_5 ) ;
for ( V_10 = 1 ; V_10 <= 5 ; ++ V_10 ) {
F_2 ( 0xFF00 + V_10 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x0004 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF08 + V_10 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x3 , V_2 -> V_3 + V_5 ) ;
}
F_2 ( 0xFF5F , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_14 ) ;
V_8 -> V_15 |= 1 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
V_8 -> V_16 = V_17 ;
F_2 ( 2048 , V_2 -> V_3 + V_18 ) ;
F_2 ( 2048 , V_2 -> V_3 + V_19 ) ;
}
static T_1 F_4 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
struct V_22 * V_23 = V_2 -> V_24 ;
F_5 ( V_23 , F_6 ( V_2 -> V_3 + V_25 ) ) ;
F_7 ( V_2 , V_23 ) ;
return V_26 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_27 * V_28 )
{
int V_29 = 0 ;
V_29 |= F_9 ( & V_28 -> V_30 , V_31 ) ;
V_29 |= F_9 ( & V_28 -> V_32 ,
V_33 | V_34 ) ;
V_29 |= F_9 ( & V_28 -> V_35 , V_34 ) ;
V_29 |= F_9 ( & V_28 -> V_36 , V_37 ) ;
V_29 |= F_9 ( & V_28 -> V_38 , V_37 | V_39 ) ;
if ( V_29 )
return 1 ;
V_29 |= F_10 ( V_28 -> V_32 ) ;
V_29 |= F_10 ( V_28 -> V_38 ) ;
if ( V_29 )
return 2 ;
V_29 |= F_11 ( & V_28 -> V_40 , 0 ) ;
if ( V_28 -> V_32 == V_33 ) {
V_29 |= F_11 ( & V_28 -> V_41 , 0 ) ;
} else {
#if 0
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
#endif
}
V_29 |= F_12 ( & V_28 -> V_42 , 10000 ) ;
#if 0
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, SLOWEST_TIMER);
#endif
V_29 |= F_11 ( & V_28 -> V_43 , V_28 -> V_44 ) ;
if ( V_28 -> V_38 == V_37 ) {
} else {
V_29 |= F_11 ( & V_28 -> V_45 , 0 ) ;
}
if ( V_29 )
return 3 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_27 * V_28 = & V_23 -> V_46 -> V_28 ;
unsigned int V_47 , V_48 ;
unsigned int V_49 , V_50 , V_51 , V_52 ;
int V_10 ;
F_1 ( V_2 ) ;
V_23 -> V_46 -> V_53 = 0 ;
if ( V_28 -> V_44 < 2 ) {
V_8 -> V_15 &= ~ V_54 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
} else {
V_8 -> V_15 |= V_54 ;
V_8 -> V_55 |= V_56 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
F_2 ( V_8 -> V_55 , V_2 -> V_3 + V_12 ) ;
}
for ( V_10 = 0 ; V_10 < V_28 -> V_44 ; ++ V_10 ) {
V_51 = F_14 ( V_28 -> V_57 [ V_10 ] ) ;
V_52 = F_15 ( V_28 -> V_57 [ V_10 ] ) ;
F_2 ( V_10 , V_2 -> V_3 + V_58 ) ;
V_50 = V_51 | ( V_52 << 6 ) ;
if ( V_10 == V_28 -> V_43 - 1 )
V_50 |= 0x0010 ;
F_2 ( V_50 , V_2 -> V_3 + V_13 ) ;
}
if ( V_28 -> V_42 < 65536000 ) {
V_48 = V_59 ;
V_47 = V_28 -> V_42 / 1000 ;
} else if ( V_28 -> V_42 < 655360000 ) {
V_48 = V_60 ;
V_47 = V_28 -> V_42 / 10000 ;
} else {
V_48 = V_61 ;
V_47 = V_28 -> V_42 / 100000 ;
}
F_2 ( 0xFF03 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_48 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0B , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF3 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_47 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF24 , V_2 -> V_3 + V_4 ) ;
V_49 = V_28 -> V_45 * V_28 -> V_43 ;
F_2 ( 0xFF04 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x1025 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0C , V_2 -> V_3 + V_4 ) ;
if ( V_49 < 65536 ) {
F_2 ( V_49 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF4 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
V_8 -> V_15 &= ~ V_62 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
} else {
V_50 = V_49 & 0xFFFF ;
if ( V_50 )
F_2 ( V_50 - 1 , V_2 -> V_3 + V_5 ) ;
else
F_2 ( 0xFFFF , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF05 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x25 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0D , V_2 -> V_3 + V_4 ) ;
V_50 = V_49 & 0xFFFF ;
if ( ( V_50 == 0 ) || ( V_50 == 1 ) ) {
F_2 ( ( V_49 >> 16 ) & 0xFFFF ,
V_2 -> V_3 + V_5 ) ;
} else {
F_2 ( ( ( V_49 >> 16 ) & 0xFFFF ) + 1 ,
V_2 -> V_3 + V_5 ) ;
}
F_2 ( 0xFF70 , V_2 -> V_3 + V_4 ) ;
V_8 -> V_15 |= V_62 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
}
if ( V_28 -> V_44 > 1 ) {
if ( V_28 -> V_41 < 65536000 ) {
V_48 = V_59 ;
V_47 = V_28 -> V_41 / 1000 ;
} else if ( V_28 -> V_41 < 655360000 ) {
V_48 = V_60 ;
V_47 = V_28 -> V_41 / 10000 ;
} else {
V_48 = V_61 ;
V_47 = V_28 -> V_41 / 100000 ;
}
F_2 ( 0xFF02 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_48 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0A , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF42 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF2 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_47 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF22 , V_2 -> V_3 + V_4 ) ;
}
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_58 ) ;
F_2 ( 0 , V_2 -> V_3 + V_14 ) ;
V_8 -> V_15 |= V_63 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
V_8 -> V_15 |= V_64 ;
V_8 -> V_55 |= V_65 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
F_2 ( V_8 -> V_55 , V_2 -> V_3 + V_12 ) ;
F_2 ( 0 , V_2 -> V_3 + V_66 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
F_3 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_67 * V_68 ,
unsigned long V_69 )
{
unsigned int V_70 ;
V_70 = F_6 ( V_2 -> V_3 + V_71 ) ;
if ( V_70 & V_72 )
return 0 ;
if ( V_70 & V_73 ) {
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
return - V_74 ;
}
return - V_75 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_67 * V_68 , unsigned int * V_76 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
int V_51 ;
int V_52 ;
int V_77 ;
V_51 = F_14 ( V_68 -> V_78 ) ;
V_52 = F_15 ( V_68 -> V_78 ) ;
F_2 ( V_51 | ( V_52 << 6 ) , V_2 -> V_3 + V_13 ) ;
for ( V_10 = 0 ; V_10 < V_68 -> V_79 ; V_10 ++ ) {
F_2 ( 0 , V_2 -> V_3 + V_80 ) ;
V_77 = F_19 ( V_2 , V_23 , V_68 , F_17 , 0 ) ;
if ( V_77 )
return V_77 ;
V_76 [ V_10 ] = F_6 ( V_2 -> V_3 + V_25 ) ;
if ( V_8 -> V_16 == V_81 )
V_76 [ V_10 ] ^= 0x800 ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_67 * V_68 , unsigned int * V_76 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_68 -> V_79 ; V_10 ++ )
V_76 [ V_10 ] = V_8 -> V_82 [ F_14 ( V_68 -> V_78 ) ] ;
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_67 * V_68 , unsigned int * V_76 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
int V_51 ;
int V_21 ;
V_51 = F_14 ( V_68 -> V_78 ) ;
for ( V_10 = 0 ; V_10 < V_68 -> V_79 ; V_10 ++ ) {
V_21 = V_76 [ V_10 ] ;
switch ( V_51 ) {
case 0 :
if ( V_8 -> V_83 == V_84 )
V_21 ^= 0x800 ;
F_2 ( V_21 , V_2 -> V_3 + V_18 ) ;
break;
case 1 :
if ( V_8 -> V_85 == V_84 )
V_21 ^= 0x800 ;
F_2 ( V_21 , V_2 -> V_3 + V_19 ) ;
break;
default:
return - V_86 ;
}
V_8 -> V_82 [ V_51 ] = V_76 [ V_10 ] ;
}
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_67 * V_68 ,
unsigned int * V_76 )
{
if ( F_23 ( V_23 , V_76 ) )
F_2 ( V_23 -> V_87 , V_2 -> V_3 + V_88 ) ;
V_76 [ 1 ] = F_6 ( V_2 -> V_3 + V_89 ) ;
return V_68 -> V_79 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_67 * V_68 ,
unsigned int * V_76 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_51 = F_14 ( V_68 -> V_78 ) ;
unsigned int V_90 ;
int V_77 ;
if ( V_51 < 4 )
V_90 = 0x0f ;
else
V_90 = 0xf0 ;
V_77 = F_25 ( V_2 , V_23 , V_68 , V_76 , V_90 ) ;
if ( V_77 )
return V_77 ;
V_8 -> V_55 &= ~ ( V_91 | V_92 ) ;
if ( V_23 -> V_93 & 0x0f )
V_8 -> V_55 |= V_91 ;
if ( V_23 -> V_93 & 0xf0 )
V_8 -> V_55 |= V_92 ;
F_2 ( V_8 -> V_55 , V_2 -> V_3 + V_12 ) ;
return V_68 -> V_79 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
const struct V_96 * V_97 = F_27 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_22 * V_23 ;
int V_77 ;
V_77 = F_28 ( V_2 , V_95 -> V_98 [ 0 ] , 0x20 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_29 ( V_2 , 4 ) ;
if ( V_77 )
return V_77 ;
V_8 = F_30 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_99 ;
F_3 ( V_2 ) ;
if ( V_95 -> V_98 [ 1 ] ) {
V_77 = F_31 ( V_95 -> V_98 [ 1 ] , F_4 , 0 ,
V_2 -> V_100 , V_2 ) ;
if ( V_77 == 0 )
V_2 -> V_20 = V_95 -> V_98 [ 1 ] ;
}
V_8 -> V_101 = V_95 -> V_98 [ 5 ] ;
V_8 -> V_102 = V_95 -> V_98 [ 6 ] ;
V_8 -> V_103 = V_95 -> V_98 [ 7 ] ;
V_8 -> V_104 = V_95 -> V_98 [ 8 ] ;
V_8 -> V_83 = V_95 -> V_98 [ 9 ] ;
V_8 -> V_105 = V_95 -> V_98 [ 10 ] ;
V_8 -> V_106 = V_95 -> V_98 [ 11 ] ;
V_8 -> V_85 = V_95 -> V_98 [ 12 ] ;
V_23 = & V_2 -> V_107 [ 0 ] ;
V_23 -> type = V_108 ;
V_23 -> V_109 = V_110 | V_111 ;
V_23 -> V_112 = ( V_8 -> V_101 ? 16 : 8 ) ;
V_23 -> V_113 = F_18 ;
V_23 -> V_114 = 0xfff ;
switch ( V_8 -> V_102 ) {
case V_115 :
V_23 -> V_116 = & V_117 ;
break;
case V_118 :
V_23 -> V_116 = & V_119 ;
break;
case V_120 :
V_23 -> V_116 = & V_121 ;
break;
}
if ( V_2 -> V_20 ) {
V_2 -> V_24 = V_23 ;
V_23 -> V_109 |= V_122 ;
V_23 -> V_123 = 16 ;
V_23 -> V_124 = F_8 ;
V_23 -> V_125 = F_13 ;
V_23 -> V_126 = F_16 ;
}
V_23 = & V_2 -> V_107 [ 1 ] ;
V_23 -> type = V_127 ;
V_23 -> V_109 = V_128 ;
V_23 -> V_112 = 2 ;
V_23 -> V_113 = F_20 ;
V_23 -> V_129 = F_21 ;
V_23 -> V_114 = 0xfff ;
V_23 -> V_130 = V_8 -> V_131 ;
switch ( V_8 -> V_103 ) {
case V_132 :
V_8 -> V_131 [ 0 ] = & V_133 ;
break;
case V_134 :
V_8 -> V_131 [ 0 ] = & V_135 ;
break;
}
switch ( V_8 -> V_105 ) {
case V_132 :
V_8 -> V_131 [ 1 ] = & V_133 ;
break;
case V_134 :
V_8 -> V_131 [ 1 ] = & V_135 ;
break;
}
V_23 = & V_2 -> V_107 [ 2 ] ;
V_23 -> type = V_136 ;
V_23 -> V_109 = V_128 | V_110 ;
V_23 -> V_112 = 8 ;
V_23 -> V_137 = F_22 ;
V_23 -> V_138 = F_24 ;
V_23 -> V_114 = 1 ;
V_23 -> V_116 = & V_139 ;
V_23 = & V_2 -> V_107 [ 3 ] ;
if ( V_97 -> V_140 ) {
V_77 = F_32 ( V_2 , V_23 , NULL , V_2 -> V_3 ) ;
if ( V_77 )
return V_77 ;
} else {
V_23 -> type = V_141 ;
}
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_34 ( V_2 ) ;
}
