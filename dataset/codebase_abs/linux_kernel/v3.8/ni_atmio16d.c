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
struct V_22 * V_23 = & V_2 -> V_24 [ 0 ] ;
F_5 ( V_23 -> V_25 , F_6 ( V_2 -> V_3 + V_26 ) ) ;
F_7 ( V_2 , V_23 ) ;
return V_27 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_28 * V_29 )
{
int V_30 = 0 ;
V_30 |= F_9 ( & V_29 -> V_31 , V_32 ) ;
V_30 |= F_9 ( & V_29 -> V_33 ,
V_34 | V_35 ) ;
V_30 |= F_9 ( & V_29 -> V_36 , V_35 ) ;
V_30 |= F_9 ( & V_29 -> V_37 , V_38 ) ;
V_30 |= F_9 ( & V_29 -> V_39 , V_38 | V_40 ) ;
if ( V_30 )
return 1 ;
V_30 |= F_10 ( V_29 -> V_33 ) ;
V_30 |= F_10 ( V_29 -> V_39 ) ;
if ( V_30 )
return 2 ;
V_30 |= F_11 ( & V_29 -> V_41 , 0 ) ;
if ( V_29 -> V_33 == V_34 ) {
V_30 |= F_11 ( & V_29 -> V_42 , 0 ) ;
} else {
#if 0
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
#endif
}
V_30 |= F_12 ( & V_29 -> V_43 , 10000 ) ;
#if 0
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, SLOWEST_TIMER);
#endif
V_30 |= F_11 ( & V_29 -> V_44 , V_29 -> V_45 ) ;
if ( V_29 -> V_39 == V_38 ) {
} else {
V_30 |= F_11 ( & V_29 -> V_46 , 0 ) ;
}
if ( V_30 )
return 3 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_28 * V_29 = & V_23 -> V_25 -> V_29 ;
unsigned int V_47 , V_48 ;
unsigned int V_49 , V_50 , V_51 , V_52 ;
int V_10 ;
F_1 ( V_2 ) ;
V_23 -> V_25 -> V_53 = 0 ;
if ( V_29 -> V_45 < 2 ) {
V_8 -> V_15 &= ~ V_54 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
} else {
V_8 -> V_15 |= V_54 ;
V_8 -> V_55 |= V_56 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
F_2 ( V_8 -> V_55 , V_2 -> V_3 + V_12 ) ;
}
for ( V_10 = 0 ; V_10 < V_29 -> V_45 ; ++ V_10 ) {
V_51 = F_14 ( V_29 -> V_57 [ V_10 ] ) ;
V_52 = F_15 ( V_29 -> V_57 [ V_10 ] ) ;
F_2 ( V_10 , V_2 -> V_3 + V_58 ) ;
V_50 = V_51 | ( V_52 << 6 ) ;
if ( V_10 == V_29 -> V_44 - 1 )
V_50 |= 0x0010 ;
F_2 ( V_50 , V_2 -> V_3 + V_13 ) ;
}
if ( V_29 -> V_43 < 65536000 ) {
V_48 = V_59 ;
V_47 = V_29 -> V_43 / 1000 ;
} else if ( V_29 -> V_43 < 655360000 ) {
V_48 = V_60 ;
V_47 = V_29 -> V_43 / 10000 ;
} else if ( V_29 -> V_43 <= 0xffffffff ) {
V_48 = V_61 ;
V_47 = V_29 -> V_43 / 100000 ;
} else if ( V_29 -> V_43 <= 0xffffffff ) {
V_48 = V_62 ;
V_47 = V_29 -> V_43 / 1000000 ;
}
F_2 ( 0xFF03 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_48 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0B , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF3 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_47 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF24 , V_2 -> V_3 + V_4 ) ;
V_49 = V_29 -> V_46 * V_29 -> V_44 ;
F_2 ( 0xFF04 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x1025 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0C , V_2 -> V_3 + V_4 ) ;
if ( V_49 < 65536 ) {
F_2 ( V_49 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF4 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
V_8 -> V_15 &= ~ V_63 ;
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
V_8 -> V_15 |= V_63 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
}
if ( V_29 -> V_45 > 1 ) {
if ( V_29 -> V_42 < 65536000 ) {
V_48 = V_59 ;
V_47 = V_29 -> V_42 / 1000 ;
} else if ( V_29 -> V_42 < 655360000 ) {
V_48 = V_60 ;
V_47 = V_29 -> V_42 / 10000 ;
} else if ( V_29 -> V_42 < 0xffffffff ) {
V_48 = V_61 ;
V_47 = V_29 -> V_42 / 100000 ;
} else if ( V_29 -> V_42 < 0xffffffff ) {
V_48 = V_62 ;
V_47 = V_29 -> V_42 / 1000000 ;
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
V_8 -> V_15 |= V_64 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
V_8 -> V_15 |= V_65 ;
V_8 -> V_55 |= V_66 ;
F_2 ( V_8 -> V_15 , V_2 -> V_3 + V_11 ) ;
F_2 ( V_8 -> V_55 , V_2 -> V_3 + V_12 ) ;
F_2 ( 0 , V_2 -> V_3 + V_67 ) ;
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
struct V_68 * V_69 , unsigned int * V_70 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 , V_71 ;
int V_51 ;
int V_52 ;
int V_72 ;
V_51 = F_14 ( V_69 -> V_73 ) ;
V_52 = F_15 ( V_69 -> V_73 ) ;
F_2 ( V_51 | ( V_52 << 6 ) , V_2 -> V_3 + V_13 ) ;
for ( V_10 = 0 ; V_10 < V_69 -> V_74 ; V_10 ++ ) {
F_2 ( 0 , V_2 -> V_3 + V_75 ) ;
for ( V_71 = 0 ; V_71 < V_76 ; V_71 ++ ) {
V_72 = F_6 ( V_2 -> V_3 + V_77 ) ;
if ( V_72 & V_78 ) {
V_70 [ V_10 ] = F_6 ( V_2 -> V_3 + V_26 ) ;
if ( V_8 -> V_16 == V_79 )
V_70 [ V_10 ] ^= 0x800 ;
break;
}
if ( V_72 & V_80 ) {
F_18 ( V_81 L_1 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
return - V_82 ;
}
}
if ( V_71 == V_76 ) {
F_18 ( V_81 L_2 ) ;
return - V_82 ;
}
}
return V_10 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_68 * V_69 , unsigned int * V_70 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_69 -> V_74 ; V_10 ++ )
V_70 [ V_10 ] = V_8 -> V_83 [ F_14 ( V_69 -> V_73 ) ] ;
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_68 * V_69 , unsigned int * V_70 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
int V_51 ;
int V_21 ;
V_51 = F_14 ( V_69 -> V_73 ) ;
for ( V_10 = 0 ; V_10 < V_69 -> V_74 ; V_10 ++ ) {
V_21 = V_70 [ V_10 ] ;
switch ( V_51 ) {
case 0 :
if ( V_8 -> V_84 == V_85 )
V_21 ^= 0x800 ;
F_2 ( V_21 , V_2 -> V_3 + V_18 ) ;
break;
case 1 :
if ( V_8 -> V_86 == V_85 )
V_21 ^= 0x800 ;
F_2 ( V_21 , V_2 -> V_3 + V_19 ) ;
break;
default:
return - V_87 ;
}
V_8 -> V_83 [ V_51 ] = V_70 [ V_10 ] ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_68 * V_69 , unsigned int * V_70 )
{
if ( V_70 [ 0 ] ) {
V_23 -> V_88 &= ~ V_70 [ 0 ] ;
V_23 -> V_88 |= ( V_70 [ 0 ] | V_70 [ 1 ] ) ;
F_2 ( V_23 -> V_88 , V_2 -> V_3 + V_89 ) ;
}
V_70 [ 1 ] = F_6 ( V_2 -> V_3 + V_90 ) ;
return V_69 -> V_74 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_68 * V_69 ,
unsigned int * V_70 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
int V_91 ;
for ( V_10 = 0 ; V_10 < V_69 -> V_74 ; V_10 ++ ) {
V_91 = ( F_14 ( V_69 -> V_73 ) < 4 ) ? 0x0f : 0xf0 ;
V_23 -> V_92 &= ~ V_91 ;
if ( V_70 [ V_10 ] )
V_23 -> V_92 |= V_91 ;
}
V_8 -> V_55 &= ~ ( V_93 | V_94 ) ;
if ( V_23 -> V_92 & 0x0f )
V_8 -> V_55 |= V_93 ;
if ( V_23 -> V_92 & 0xf0 )
V_8 -> V_55 |= V_94 ;
F_2 ( V_8 -> V_55 , V_2 -> V_3 + V_12 ) ;
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
const struct V_97 * V_98 = F_24 ( V_2 ) ;
struct V_7 * V_8 ;
unsigned int V_20 ;
unsigned long V_3 ;
int V_99 ;
struct V_22 * V_23 ;
V_3 = V_96 -> V_100 [ 0 ] ;
F_18 ( V_81 L_3 , V_2 -> V_101 , V_3 ) ;
if ( ! F_25 ( V_3 , V_102 , L_4 ) ) {
F_18 ( L_5 ) ;
return - V_103 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_104 = V_98 -> V_105 ;
V_99 = F_26 ( V_2 , 4 ) ;
if ( V_99 )
return V_99 ;
V_8 = F_27 ( sizeof( * V_8 ) , V_106 ) ;
if ( ! V_8 )
return - V_107 ;
V_2 -> V_9 = V_8 ;
F_3 ( V_2 ) ;
V_20 = V_96 -> V_100 [ 1 ] ;
if ( V_20 ) {
V_99 = F_28 ( V_20 , F_4 , 0 , L_6 , V_2 ) ;
if ( V_99 < 0 ) {
F_18 ( V_81 L_7 , V_20 ) ;
return V_99 ;
}
V_2 -> V_20 = V_20 ;
F_18 ( V_81 L_8 , V_20 ) ;
} else {
F_18 ( V_81 L_9 ) ;
}
V_8 -> V_108 = V_96 -> V_100 [ 5 ] ;
V_8 -> V_109 = V_96 -> V_100 [ 6 ] ;
V_8 -> V_110 = V_96 -> V_100 [ 7 ] ;
V_8 -> V_111 = V_96 -> V_100 [ 8 ] ;
V_8 -> V_84 = V_96 -> V_100 [ 9 ] ;
V_8 -> V_112 = V_96 -> V_100 [ 10 ] ;
V_8 -> V_113 = V_96 -> V_100 [ 11 ] ;
V_8 -> V_86 = V_96 -> V_100 [ 12 ] ;
V_23 = & V_2 -> V_24 [ 0 ] ;
V_2 -> V_114 = V_23 ;
V_23 -> type = V_115 ;
V_23 -> V_116 = V_117 | V_118 | V_119 ;
V_23 -> V_120 = ( V_8 -> V_108 ? 16 : 8 ) ;
V_23 -> V_121 = 16 ;
V_23 -> V_122 = F_17 ;
V_23 -> V_123 = F_8 ;
V_23 -> V_124 = F_13 ;
V_23 -> V_125 = F_16 ;
V_23 -> V_126 = 0xfff ;
switch ( V_8 -> V_109 ) {
case V_127 :
V_23 -> V_128 = & V_129 ;
break;
case V_130 :
V_23 -> V_128 = & V_131 ;
break;
case V_132 :
V_23 -> V_128 = & V_133 ;
break;
}
V_23 = & V_2 -> V_24 [ 1 ] ;
V_23 -> type = V_134 ;
V_23 -> V_116 = V_135 ;
V_23 -> V_120 = 2 ;
V_23 -> V_122 = F_19 ;
V_23 -> V_136 = F_20 ;
V_23 -> V_126 = 0xfff ;
V_23 -> V_137 = V_8 -> V_138 ;
switch ( V_8 -> V_110 ) {
case V_139 :
V_8 -> V_138 [ 0 ] = & V_140 ;
break;
case V_141 :
V_8 -> V_138 [ 0 ] = & V_142 ;
break;
}
switch ( V_8 -> V_112 ) {
case V_139 :
V_8 -> V_138 [ 1 ] = & V_140 ;
break;
case V_141 :
V_8 -> V_138 [ 1 ] = & V_142 ;
break;
}
V_23 = & V_2 -> V_24 [ 2 ] ;
V_23 -> type = V_143 ;
V_23 -> V_116 = V_135 | V_117 ;
V_23 -> V_120 = 8 ;
V_23 -> V_144 = F_21 ;
V_23 -> V_145 = F_22 ;
V_23 -> V_126 = 1 ;
V_23 -> V_128 = & V_146 ;
V_23 = & V_2 -> V_24 [ 3 ] ;
if ( V_98 -> V_147 )
F_29 ( V_2 , V_23 , NULL , V_2 -> V_3 ) ;
else
V_23 -> type = V_148 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
F_18 ( L_10 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
const struct V_97 * V_98 = F_24 ( V_2 ) ;
struct V_22 * V_23 ;
if ( V_2 -> V_24 && V_98 -> V_147 ) {
V_23 = & V_2 -> V_24 [ 3 ] ;
F_31 ( V_2 , V_23 ) ;
}
if ( V_2 -> V_20 )
F_32 ( V_2 -> V_20 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_3 )
F_33 ( V_2 -> V_3 , V_102 ) ;
}
