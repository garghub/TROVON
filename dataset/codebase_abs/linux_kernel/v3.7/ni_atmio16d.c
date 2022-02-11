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
int V_7 ;
F_2 ( 0 , V_2 -> V_3 + V_8 ) ;
F_2 ( 0 , V_2 -> V_3 + V_9 ) ;
F_2 ( 0 , V_2 -> V_3 + V_10 ) ;
F_2 ( 0xFFFF , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFEF , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF17 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xF000 , V_2 -> V_3 + V_5 ) ;
for ( V_7 = 1 ; V_7 <= 5 ; ++ V_7 ) {
F_2 ( 0xFF00 + V_7 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x0004 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF08 + V_7 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x3 , V_2 -> V_3 + V_5 ) ;
}
F_2 ( 0xFF5F , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_11 ) ;
V_12 -> V_13 |= 1 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
V_12 -> V_14 = V_15 ;
F_2 ( 2048 , V_2 -> V_3 + V_16 ) ;
F_2 ( 2048 , V_2 -> V_3 + V_17 ) ;
}
static T_1 F_4 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 * V_21 = & V_2 -> V_22 [ 0 ] ;
F_5 ( V_21 -> V_23 , F_6 ( V_2 -> V_3 + V_24 ) ) ;
F_7 ( V_2 , V_21 ) ;
return V_25 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_26 * V_27 )
{
int V_28 = 0 ;
V_28 |= F_9 ( & V_27 -> V_29 , V_30 ) ;
V_28 |= F_9 ( & V_27 -> V_31 ,
V_32 | V_33 ) ;
V_28 |= F_9 ( & V_27 -> V_34 , V_33 ) ;
V_28 |= F_9 ( & V_27 -> V_35 , V_36 ) ;
V_28 |= F_9 ( & V_27 -> V_37 , V_36 | V_38 ) ;
if ( V_28 )
return 1 ;
V_28 |= F_10 ( V_27 -> V_31 ) ;
V_28 |= F_10 ( V_27 -> V_37 ) ;
if ( V_28 )
return 2 ;
if ( V_27 -> V_39 != 0 ) {
V_27 -> V_39 = 0 ;
V_28 ++ ;
}
if ( V_27 -> V_31 == V_32 ) {
if ( V_27 -> V_40 != 0 ) {
V_27 -> V_40 = 0 ;
V_28 ++ ;
}
} else {
#if 0
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
#endif
}
if ( V_27 -> V_41 < 10000 ) {
V_27 -> V_41 = 10000 ;
V_28 ++ ;
}
#if 0
if (cmd->convert_arg > SLOWEST_TIMER) {
cmd->convert_arg = SLOWEST_TIMER;
err++;
}
#endif
if ( V_27 -> V_42 != V_27 -> V_43 ) {
V_27 -> V_42 = V_27 -> V_43 ;
V_28 ++ ;
}
if ( V_27 -> V_37 == V_36 ) {
} else {
if ( V_27 -> V_44 != 0 ) {
V_27 -> V_44 = 0 ;
V_28 ++ ;
}
}
if ( V_28 )
return 3 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_26 * V_27 = & V_21 -> V_23 -> V_27 ;
unsigned int V_45 , V_46 ;
unsigned int V_47 , V_48 , V_49 , V_50 ;
int V_7 ;
F_1 ( V_2 ) ;
V_21 -> V_23 -> V_51 = 0 ;
if ( V_27 -> V_43 < 2 ) {
V_12 -> V_13 &= ~ V_52 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
} else {
V_12 -> V_13 |= V_52 ;
V_12 -> V_53 |= V_54 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
F_2 ( V_12 -> V_53 , V_2 -> V_3 + V_9 ) ;
}
for ( V_7 = 0 ; V_7 < V_27 -> V_43 ; ++ V_7 ) {
V_49 = F_12 ( V_27 -> V_55 [ V_7 ] ) ;
V_50 = F_13 ( V_27 -> V_55 [ V_7 ] ) ;
F_2 ( V_7 , V_2 -> V_3 + V_56 ) ;
V_48 = V_49 | ( V_50 << 6 ) ;
if ( V_7 == V_27 -> V_42 - 1 )
V_48 |= 0x0010 ;
F_2 ( V_48 , V_2 -> V_3 + V_10 ) ;
}
if ( V_27 -> V_41 < 65536000 ) {
V_46 = V_57 ;
V_45 = V_27 -> V_41 / 1000 ;
} else if ( V_27 -> V_41 < 655360000 ) {
V_46 = V_58 ;
V_45 = V_27 -> V_41 / 10000 ;
} else if ( V_27 -> V_41 <= 0xffffffff ) {
V_46 = V_59 ;
V_45 = V_27 -> V_41 / 100000 ;
} else if ( V_27 -> V_41 <= 0xffffffff ) {
V_46 = V_60 ;
V_45 = V_27 -> V_41 / 1000000 ;
}
F_2 ( 0xFF03 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_46 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0B , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF3 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_45 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF24 , V_2 -> V_3 + V_4 ) ;
V_47 = V_27 -> V_44 * V_27 -> V_42 ;
F_2 ( 0xFF04 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x1025 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0C , V_2 -> V_3 + V_4 ) ;
if ( V_47 < 65536 ) {
F_2 ( V_47 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF4 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
V_12 -> V_13 &= ~ V_61 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
} else {
V_48 = V_47 & 0xFFFF ;
if ( V_48 )
F_2 ( V_48 - 1 , V_2 -> V_3 + V_5 ) ;
else
F_2 ( 0xFFFF , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF05 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x25 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0D , V_2 -> V_3 + V_4 ) ;
V_48 = V_47 & 0xFFFF ;
if ( ( V_48 == 0 ) || ( V_48 == 1 ) ) {
F_2 ( ( V_47 >> 16 ) & 0xFFFF ,
V_2 -> V_3 + V_5 ) ;
} else {
F_2 ( ( ( V_47 >> 16 ) & 0xFFFF ) + 1 ,
V_2 -> V_3 + V_5 ) ;
}
F_2 ( 0xFF70 , V_2 -> V_3 + V_4 ) ;
V_12 -> V_13 |= V_61 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
}
if ( V_27 -> V_43 > 1 ) {
if ( V_27 -> V_40 < 65536000 ) {
V_46 = V_57 ;
V_45 = V_27 -> V_40 / 1000 ;
} else if ( V_27 -> V_40 < 655360000 ) {
V_46 = V_58 ;
V_45 = V_27 -> V_40 / 10000 ;
} else if ( V_27 -> V_40 < 0xffffffff ) {
V_46 = V_59 ;
V_45 = V_27 -> V_40 / 100000 ;
} else if ( V_27 -> V_40 < 0xffffffff ) {
V_46 = V_60 ;
V_45 = V_27 -> V_40 / 1000000 ;
}
F_2 ( 0xFF02 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_46 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0A , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF42 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF2 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_45 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF22 , V_2 -> V_3 + V_4 ) ;
}
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_56 ) ;
F_2 ( 0 , V_2 -> V_3 + V_11 ) ;
V_12 -> V_13 |= V_62 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
V_12 -> V_13 |= V_63 ;
V_12 -> V_53 |= V_64 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
F_2 ( V_12 -> V_53 , V_2 -> V_3 + V_9 ) ;
F_2 ( 0 , V_2 -> V_3 + V_65 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_3 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_66 * V_67 , unsigned int * V_68 )
{
int V_7 , V_69 ;
int V_49 ;
int V_50 ;
int V_70 ;
V_49 = F_12 ( V_67 -> V_71 ) ;
V_50 = F_13 ( V_67 -> V_71 ) ;
F_2 ( V_49 | ( V_50 << 6 ) , V_2 -> V_3 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_67 -> V_72 ; V_7 ++ ) {
F_2 ( 0 , V_2 -> V_3 + V_73 ) ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
V_70 = F_6 ( V_2 -> V_3 + V_75 ) ;
if ( V_70 & V_76 ) {
V_68 [ V_7 ] = F_6 ( V_2 -> V_3 + V_24 ) ;
if ( V_12 -> V_14 == V_77 )
V_68 [ V_7 ] ^= 0x800 ;
break;
}
if ( V_70 & V_78 ) {
F_16 ( V_79 L_1 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
return - V_80 ;
}
}
if ( V_69 == V_74 ) {
F_16 ( V_79 L_2 ) ;
return - V_80 ;
}
}
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_66 * V_67 , unsigned int * V_68 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_67 -> V_72 ; V_7 ++ )
V_68 [ V_7 ] = V_12 -> V_81 [ F_12 ( V_67 -> V_71 ) ] ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_66 * V_67 , unsigned int * V_68 )
{
int V_7 ;
int V_49 ;
int V_19 ;
V_49 = F_12 ( V_67 -> V_71 ) ;
for ( V_7 = 0 ; V_7 < V_67 -> V_72 ; V_7 ++ ) {
V_19 = V_68 [ V_7 ] ;
switch ( V_49 ) {
case 0 :
if ( V_12 -> V_82 == V_83 )
V_19 ^= 0x800 ;
F_2 ( V_19 , V_2 -> V_3 + V_16 ) ;
break;
case 1 :
if ( V_12 -> V_84 == V_83 )
V_19 ^= 0x800 ;
F_2 ( V_19 , V_2 -> V_3 + V_17 ) ;
break;
default:
return - V_85 ;
}
V_12 -> V_81 [ V_49 ] = V_68 [ V_7 ] ;
}
return V_7 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_66 * V_67 , unsigned int * V_68 )
{
if ( V_68 [ 0 ] ) {
V_21 -> V_86 &= ~ V_68 [ 0 ] ;
V_21 -> V_86 |= ( V_68 [ 0 ] | V_68 [ 1 ] ) ;
F_2 ( V_21 -> V_86 , V_2 -> V_3 + V_87 ) ;
}
V_68 [ 1 ] = F_6 ( V_2 -> V_3 + V_88 ) ;
return V_67 -> V_72 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_66 * V_67 ,
unsigned int * V_68 )
{
int V_7 ;
int V_89 ;
for ( V_7 = 0 ; V_7 < V_67 -> V_72 ; V_7 ++ ) {
V_89 = ( F_12 ( V_67 -> V_71 ) < 4 ) ? 0x0f : 0xf0 ;
V_21 -> V_90 &= ~ V_89 ;
if ( V_68 [ V_7 ] )
V_21 -> V_90 |= V_89 ;
}
V_12 -> V_53 &= ~ ( V_91 | V_92 ) ;
if ( V_21 -> V_90 & 0x0f )
V_12 -> V_53 |= V_91 ;
if ( V_21 -> V_90 & 0xf0 )
V_12 -> V_53 |= V_92 ;
F_2 ( V_12 -> V_53 , V_2 -> V_3 + V_9 ) ;
return V_7 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
const struct V_95 * V_96 = F_22 ( V_2 ) ;
unsigned int V_18 ;
unsigned long V_3 ;
int V_97 ;
struct V_20 * V_21 ;
V_3 = V_94 -> V_98 [ 0 ] ;
F_16 ( V_79 L_3 , V_2 -> V_99 , V_3 ) ;
if ( ! F_23 ( V_3 , V_100 , L_4 ) ) {
F_16 ( L_5 ) ;
return - V_101 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_102 = V_96 -> V_103 ;
V_97 = F_24 ( V_2 , 4 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_25 ( V_2 , sizeof( struct V_104 ) ) ;
if ( V_97 < 0 )
return V_97 ;
F_3 ( V_2 ) ;
V_18 = V_94 -> V_98 [ 1 ] ;
if ( V_18 ) {
V_97 = F_26 ( V_18 , F_4 , 0 , L_6 , V_2 ) ;
if ( V_97 < 0 ) {
F_16 ( V_79 L_7 , V_18 ) ;
return V_97 ;
}
V_2 -> V_18 = V_18 ;
F_16 ( V_79 L_8 , V_18 ) ;
} else {
F_16 ( V_79 L_9 ) ;
}
V_12 -> V_105 = V_94 -> V_98 [ 5 ] ;
V_12 -> V_106 = V_94 -> V_98 [ 6 ] ;
V_12 -> V_107 = V_94 -> V_98 [ 7 ] ;
V_12 -> V_108 = V_94 -> V_98 [ 8 ] ;
V_12 -> V_82 = V_94 -> V_98 [ 9 ] ;
V_12 -> V_109 = V_94 -> V_98 [ 10 ] ;
V_12 -> V_110 = V_94 -> V_98 [ 11 ] ;
V_12 -> V_84 = V_94 -> V_98 [ 12 ] ;
V_21 = & V_2 -> V_22 [ 0 ] ;
V_2 -> V_111 = V_21 ;
V_21 -> type = V_112 ;
V_21 -> V_113 = V_114 | V_115 | V_116 ;
V_21 -> V_117 = ( V_12 -> V_105 ? 16 : 8 ) ;
V_21 -> V_118 = 16 ;
V_21 -> V_119 = F_15 ;
V_21 -> V_120 = F_8 ;
V_21 -> V_121 = F_11 ;
V_21 -> V_122 = F_14 ;
V_21 -> V_123 = 0xfff ;
switch ( V_12 -> V_106 ) {
case V_124 :
V_21 -> V_125 = & V_126 ;
break;
case V_127 :
V_21 -> V_125 = & V_128 ;
break;
case V_129 :
V_21 -> V_125 = & V_130 ;
break;
}
V_21 = & V_2 -> V_22 [ 1 ] ;
V_21 -> type = V_131 ;
V_21 -> V_113 = V_132 ;
V_21 -> V_117 = 2 ;
V_21 -> V_119 = F_17 ;
V_21 -> V_133 = F_18 ;
V_21 -> V_123 = 0xfff ;
V_21 -> V_134 = V_12 -> V_135 ;
switch ( V_12 -> V_107 ) {
case V_136 :
V_12 -> V_135 [ 0 ] = & V_137 ;
break;
case V_138 :
V_12 -> V_135 [ 0 ] = & V_139 ;
break;
}
switch ( V_12 -> V_109 ) {
case V_136 :
V_12 -> V_135 [ 1 ] = & V_137 ;
break;
case V_138 :
V_12 -> V_135 [ 1 ] = & V_139 ;
break;
}
V_21 = & V_2 -> V_22 [ 2 ] ;
V_21 -> type = V_140 ;
V_21 -> V_113 = V_132 | V_114 ;
V_21 -> V_117 = 8 ;
V_21 -> V_141 = F_19 ;
V_21 -> V_142 = F_20 ;
V_21 -> V_123 = 1 ;
V_21 -> V_125 = & V_143 ;
V_21 = & V_2 -> V_22 [ 3 ] ;
if ( V_96 -> V_144 )
F_27 ( V_2 , V_21 , NULL , V_2 -> V_3 ) ;
else
V_21 -> type = V_145 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
F_16 ( L_10 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
const struct V_95 * V_96 = F_22 ( V_2 ) ;
struct V_20 * V_21 ;
if ( V_2 -> V_22 && V_96 -> V_144 ) {
V_21 = & V_2 -> V_22 [ 3 ] ;
F_29 ( V_2 , V_21 ) ;
}
if ( V_2 -> V_18 )
F_30 ( V_2 -> V_18 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_3 )
F_31 ( V_2 -> V_3 , V_100 ) ;
}
