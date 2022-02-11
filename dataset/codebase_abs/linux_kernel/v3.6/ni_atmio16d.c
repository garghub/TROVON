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
struct V_20 * V_21 = V_2 -> V_22 + 0 ;
F_5 ( V_21 -> V_23 , F_6 ( V_2 -> V_3 + V_24 ) ) ;
F_7 ( V_2 , V_21 ) ;
return V_25 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_26 * V_27 )
{
int V_28 = 0 , V_29 ;
V_29 = V_27 -> V_30 ;
V_27 -> V_30 &= V_31 ;
if ( ! V_27 -> V_30 || V_29 != V_27 -> V_30 )
V_28 ++ ;
V_29 = V_27 -> V_32 ;
V_27 -> V_32 &= V_33 | V_34 ;
if ( ! V_27 -> V_32 || V_29 != V_27 -> V_32 )
V_28 ++ ;
V_29 = V_27 -> V_35 ;
V_27 -> V_35 &= V_34 ;
if ( ! V_27 -> V_35 || V_29 != V_27 -> V_35 )
V_28 ++ ;
V_29 = V_27 -> V_36 ;
V_27 -> V_36 &= V_37 ;
if ( ! V_27 -> V_36 || V_29 != V_27 -> V_36 )
V_28 ++ ;
V_29 = V_27 -> V_38 ;
V_27 -> V_38 &= V_37 | V_39 ;
if ( ! V_27 -> V_38 || V_29 != V_27 -> V_38 )
V_28 ++ ;
if ( V_28 )
return 1 ;
if ( V_27 -> V_32 != V_33 &&
V_27 -> V_32 != V_40 &&
V_27 -> V_32 != V_34 )
V_28 ++ ;
if ( V_27 -> V_38 != V_37 && V_27 -> V_38 != V_39 )
V_28 ++ ;
if ( V_28 )
return 2 ;
if ( V_27 -> V_41 != 0 ) {
V_27 -> V_41 = 0 ;
V_28 ++ ;
}
if ( V_27 -> V_32 == V_33 ) {
if ( V_27 -> V_42 != 0 ) {
V_27 -> V_42 = 0 ;
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
if ( V_27 -> V_43 < 10000 ) {
V_27 -> V_43 = 10000 ;
V_28 ++ ;
}
#if 0
if (cmd->convert_arg > SLOWEST_TIMER) {
cmd->convert_arg = SLOWEST_TIMER;
err++;
}
#endif
if ( V_27 -> V_44 != V_27 -> V_45 ) {
V_27 -> V_44 = V_27 -> V_45 ;
V_28 ++ ;
}
if ( V_27 -> V_38 == V_37 ) {
} else {
if ( V_27 -> V_46 != 0 ) {
V_27 -> V_46 = 0 ;
V_28 ++ ;
}
}
if ( V_28 )
return 3 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_26 * V_27 = & V_21 -> V_23 -> V_27 ;
unsigned int V_47 , V_48 ;
unsigned int V_49 , V_29 , V_50 , V_51 ;
int V_7 ;
F_1 ( V_2 ) ;
V_21 -> V_23 -> V_52 = 0 ;
if ( V_27 -> V_45 < 2 ) {
V_12 -> V_13 &= ~ V_53 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
} else {
V_12 -> V_13 |= V_53 ;
V_12 -> V_54 |= V_55 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
F_2 ( V_12 -> V_54 , V_2 -> V_3 + V_9 ) ;
}
for ( V_7 = 0 ; V_7 < V_27 -> V_45 ; ++ V_7 ) {
V_50 = F_10 ( V_27 -> V_56 [ V_7 ] ) ;
V_51 = F_11 ( V_27 -> V_56 [ V_7 ] ) ;
F_2 ( V_7 , V_2 -> V_3 + V_57 ) ;
V_29 = V_50 | ( V_51 << 6 ) ;
if ( V_7 == V_27 -> V_44 - 1 )
V_29 |= 0x0010 ;
F_2 ( V_29 , V_2 -> V_3 + V_10 ) ;
}
if ( V_27 -> V_43 < 65536000 ) {
V_48 = V_58 ;
V_47 = V_27 -> V_43 / 1000 ;
} else if ( V_27 -> V_43 < 655360000 ) {
V_48 = V_59 ;
V_47 = V_27 -> V_43 / 10000 ;
} else if ( V_27 -> V_43 <= 0xffffffff ) {
V_48 = V_60 ;
V_47 = V_27 -> V_43 / 100000 ;
} else if ( V_27 -> V_43 <= 0xffffffff ) {
V_48 = V_61 ;
V_47 = V_27 -> V_43 / 1000000 ;
}
F_2 ( 0xFF03 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_48 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0B , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF3 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_47 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF24 , V_2 -> V_3 + V_4 ) ;
V_49 = V_27 -> V_46 * V_27 -> V_44 ;
F_2 ( 0xFF04 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x1025 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0C , V_2 -> V_3 + V_4 ) ;
if ( V_49 < 65536 ) {
F_2 ( V_49 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF4 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
V_12 -> V_13 &= ~ V_62 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
} else {
V_29 = V_49 & 0xFFFF ;
if ( V_29 )
F_2 ( V_29 - 1 , V_2 -> V_3 + V_5 ) ;
else
F_2 ( 0xFFFF , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF05 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x25 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0D , V_2 -> V_3 + V_4 ) ;
V_29 = V_49 & 0xFFFF ;
if ( ( V_29 == 0 ) || ( V_29 == 1 ) ) {
F_2 ( ( V_49 >> 16 ) & 0xFFFF ,
V_2 -> V_3 + V_5 ) ;
} else {
F_2 ( ( ( V_49 >> 16 ) & 0xFFFF ) + 1 ,
V_2 -> V_3 + V_5 ) ;
}
F_2 ( 0xFF70 , V_2 -> V_3 + V_4 ) ;
V_12 -> V_13 |= V_62 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
}
if ( V_27 -> V_45 > 1 ) {
if ( V_27 -> V_42 < 65536000 ) {
V_48 = V_58 ;
V_47 = V_27 -> V_42 / 1000 ;
} else if ( V_27 -> V_42 < 655360000 ) {
V_48 = V_59 ;
V_47 = V_27 -> V_42 / 10000 ;
} else if ( V_27 -> V_42 < 0xffffffff ) {
V_48 = V_60 ;
V_47 = V_27 -> V_42 / 100000 ;
} else if ( V_27 -> V_42 < 0xffffffff ) {
V_48 = V_61 ;
V_47 = V_27 -> V_42 / 1000000 ;
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
F_2 ( 0 , V_2 -> V_3 + V_57 ) ;
F_2 ( 0 , V_2 -> V_3 + V_11 ) ;
V_12 -> V_13 |= V_63 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
V_12 -> V_13 |= V_64 ;
V_12 -> V_54 |= V_65 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
F_2 ( V_12 -> V_54 , V_2 -> V_3 + V_9 ) ;
F_2 ( 0 , V_2 -> V_3 + V_66 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_3 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_67 * V_68 , unsigned int * V_69 )
{
int V_7 , V_70 ;
int V_50 ;
int V_51 ;
int V_71 ;
V_50 = F_10 ( V_68 -> V_72 ) ;
V_51 = F_11 ( V_68 -> V_72 ) ;
F_2 ( V_50 | ( V_51 << 6 ) , V_2 -> V_3 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_68 -> V_73 ; V_7 ++ ) {
F_2 ( 0 , V_2 -> V_3 + V_74 ) ;
for ( V_70 = 0 ; V_70 < V_75 ; V_70 ++ ) {
V_71 = F_6 ( V_2 -> V_3 + V_76 ) ;
if ( V_71 & V_77 ) {
V_69 [ V_7 ] = F_6 ( V_2 -> V_3 + V_24 ) ;
if ( V_12 -> V_14 == V_78 )
V_69 [ V_7 ] ^= 0x800 ;
break;
}
if ( V_71 & V_79 ) {
F_14 ( V_80 L_1 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
return - V_81 ;
}
}
if ( V_70 == V_75 ) {
F_14 ( V_80 L_2 ) ;
return - V_81 ;
}
}
return V_7 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_67 * V_68 , unsigned int * V_69 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_68 -> V_73 ; V_7 ++ )
V_69 [ V_7 ] = V_12 -> V_82 [ F_10 ( V_68 -> V_72 ) ] ;
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_67 * V_68 , unsigned int * V_69 )
{
int V_7 ;
int V_50 ;
int V_19 ;
V_50 = F_10 ( V_68 -> V_72 ) ;
for ( V_7 = 0 ; V_7 < V_68 -> V_73 ; V_7 ++ ) {
V_19 = V_69 [ V_7 ] ;
switch ( V_50 ) {
case 0 :
if ( V_12 -> V_83 == V_84 )
V_19 ^= 0x800 ;
F_2 ( V_19 , V_2 -> V_3 + V_16 ) ;
break;
case 1 :
if ( V_12 -> V_85 == V_84 )
V_19 ^= 0x800 ;
F_2 ( V_19 , V_2 -> V_3 + V_17 ) ;
break;
default:
return - V_86 ;
}
V_12 -> V_82 [ V_50 ] = V_69 [ V_7 ] ;
}
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_67 * V_68 , unsigned int * V_69 )
{
if ( V_69 [ 0 ] ) {
V_21 -> V_87 &= ~ V_69 [ 0 ] ;
V_21 -> V_87 |= ( V_69 [ 0 ] | V_69 [ 1 ] ) ;
F_2 ( V_21 -> V_87 , V_2 -> V_3 + V_88 ) ;
}
V_69 [ 1 ] = F_6 ( V_2 -> V_3 + V_89 ) ;
return V_68 -> V_73 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
int V_7 ;
int V_90 ;
for ( V_7 = 0 ; V_7 < V_68 -> V_73 ; V_7 ++ ) {
V_90 = ( F_10 ( V_68 -> V_72 ) < 4 ) ? 0x0f : 0xf0 ;
V_21 -> V_91 &= ~ V_90 ;
if ( V_69 [ V_7 ] )
V_21 -> V_91 |= V_90 ;
}
V_12 -> V_54 &= ~ ( V_92 | V_93 ) ;
if ( V_21 -> V_91 & 0x0f )
V_12 -> V_54 |= V_92 ;
if ( V_21 -> V_91 & 0xf0 )
V_12 -> V_54 |= V_93 ;
F_2 ( V_12 -> V_54 , V_2 -> V_3 + V_9 ) ;
return V_7 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
const struct V_96 * V_97 = F_20 ( V_2 ) ;
unsigned int V_18 ;
unsigned long V_3 ;
int V_98 ;
struct V_20 * V_21 ;
V_3 = V_95 -> V_99 [ 0 ] ;
F_14 ( V_80 L_3 , V_2 -> V_100 , V_3 ) ;
if ( ! F_21 ( V_3 , V_101 , L_4 ) ) {
F_14 ( L_5 ) ;
return - V_102 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_103 = V_97 -> V_104 ;
V_98 = F_22 ( V_2 , 4 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_23 ( V_2 , sizeof( struct V_105 ) ) ;
if ( V_98 < 0 )
return V_98 ;
F_3 ( V_2 ) ;
V_18 = V_95 -> V_99 [ 1 ] ;
if ( V_18 ) {
V_98 = F_24 ( V_18 , F_4 , 0 , L_6 , V_2 ) ;
if ( V_98 < 0 ) {
F_14 ( V_80 L_7 , V_18 ) ;
return V_98 ;
}
V_2 -> V_18 = V_18 ;
F_14 ( V_80 L_8 , V_18 ) ;
} else {
F_14 ( V_80 L_9 ) ;
}
V_12 -> V_106 = V_95 -> V_99 [ 5 ] ;
V_12 -> V_107 = V_95 -> V_99 [ 6 ] ;
V_12 -> V_108 = V_95 -> V_99 [ 7 ] ;
V_12 -> V_109 = V_95 -> V_99 [ 8 ] ;
V_12 -> V_83 = V_95 -> V_99 [ 9 ] ;
V_12 -> V_110 = V_95 -> V_99 [ 10 ] ;
V_12 -> V_111 = V_95 -> V_99 [ 11 ] ;
V_12 -> V_85 = V_95 -> V_99 [ 12 ] ;
V_21 = V_2 -> V_22 + 0 ;
V_2 -> V_112 = V_21 ;
V_21 -> type = V_113 ;
V_21 -> V_114 = V_115 | V_116 | V_117 ;
V_21 -> V_118 = ( V_12 -> V_106 ? 16 : 8 ) ;
V_21 -> V_119 = 16 ;
V_21 -> V_120 = F_13 ;
V_21 -> V_121 = F_8 ;
V_21 -> V_122 = F_9 ;
V_21 -> V_123 = F_12 ;
V_21 -> V_124 = 0xfff ;
switch ( V_12 -> V_107 ) {
case V_125 :
V_21 -> V_126 = & V_127 ;
break;
case V_128 :
V_21 -> V_126 = & V_129 ;
break;
case V_130 :
V_21 -> V_126 = & V_131 ;
break;
}
V_21 ++ ;
V_21 -> type = V_132 ;
V_21 -> V_114 = V_133 ;
V_21 -> V_118 = 2 ;
V_21 -> V_120 = F_15 ;
V_21 -> V_134 = F_16 ;
V_21 -> V_124 = 0xfff ;
V_21 -> V_135 = V_12 -> V_136 ;
switch ( V_12 -> V_108 ) {
case V_137 :
V_12 -> V_136 [ 0 ] = & V_138 ;
break;
case V_139 :
V_12 -> V_136 [ 0 ] = & V_140 ;
break;
}
switch ( V_12 -> V_110 ) {
case V_137 :
V_12 -> V_136 [ 1 ] = & V_138 ;
break;
case V_139 :
V_12 -> V_136 [ 1 ] = & V_140 ;
break;
}
V_21 ++ ;
V_21 -> type = V_141 ;
V_21 -> V_114 = V_133 | V_115 ;
V_21 -> V_118 = 8 ;
V_21 -> V_142 = F_17 ;
V_21 -> V_143 = F_18 ;
V_21 -> V_124 = 1 ;
V_21 -> V_126 = & V_144 ;
V_21 ++ ;
if ( V_97 -> V_145 )
F_25 ( V_2 , V_21 , NULL , V_2 -> V_3 ) ;
else
V_21 -> type = V_146 ;
#if 0
s++;
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
F_14 ( L_10 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_20 ( V_2 ) ;
if ( V_2 -> V_22 && V_97 -> V_145 )
F_27 ( V_2 , V_2 -> V_22 + 3 ) ;
if ( V_2 -> V_18 )
F_28 ( V_2 -> V_18 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_3 )
F_29 ( V_2 -> V_3 , V_101 ) ;
}
