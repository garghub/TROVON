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
#ifdef F_5
F_6 ( V_23 L_1 ) ;
#endif
F_7 ( V_21 -> V_24 , F_8 ( V_2 -> V_3 + V_25 ) ) ;
F_9 ( V_2 , V_21 ) ;
return V_26 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_27 * V_28 )
{
int V_29 = 0 , V_30 ;
#ifdef F_5
F_6 ( V_23 L_2 ) ;
#endif
V_30 = V_28 -> V_31 ;
V_28 -> V_31 &= V_32 ;
if ( ! V_28 -> V_31 || V_30 != V_28 -> V_31 )
V_29 ++ ;
V_30 = V_28 -> V_33 ;
V_28 -> V_33 &= V_34 | V_35 ;
if ( ! V_28 -> V_33 || V_30 != V_28 -> V_33 )
V_29 ++ ;
V_30 = V_28 -> V_36 ;
V_28 -> V_36 &= V_35 ;
if ( ! V_28 -> V_36 || V_30 != V_28 -> V_36 )
V_29 ++ ;
V_30 = V_28 -> V_37 ;
V_28 -> V_37 &= V_38 ;
if ( ! V_28 -> V_37 || V_30 != V_28 -> V_37 )
V_29 ++ ;
V_30 = V_28 -> V_39 ;
V_28 -> V_39 &= V_38 | V_40 ;
if ( ! V_28 -> V_39 || V_30 != V_28 -> V_39 )
V_29 ++ ;
if ( V_29 )
return 1 ;
if ( V_28 -> V_33 != V_34 &&
V_28 -> V_33 != V_41 &&
V_28 -> V_33 != V_35 )
V_29 ++ ;
if ( V_28 -> V_39 != V_38 && V_28 -> V_39 != V_40 )
V_29 ++ ;
if ( V_29 )
return 2 ;
if ( V_28 -> V_42 != 0 ) {
V_28 -> V_42 = 0 ;
V_29 ++ ;
}
if ( V_28 -> V_33 == V_34 ) {
if ( V_28 -> V_43 != 0 ) {
V_28 -> V_43 = 0 ;
V_29 ++ ;
}
} else {
#if 0
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
#endif
}
if ( V_28 -> V_44 < 10000 ) {
V_28 -> V_44 = 10000 ;
V_29 ++ ;
}
#if 0
if (cmd->convert_arg > SLOWEST_TIMER) {
cmd->convert_arg = SLOWEST_TIMER;
err++;
}
#endif
if ( V_28 -> V_45 != V_28 -> V_46 ) {
V_28 -> V_45 = V_28 -> V_46 ;
V_29 ++ ;
}
if ( V_28 -> V_39 == V_38 ) {
} else {
if ( V_28 -> V_47 != 0 ) {
V_28 -> V_47 = 0 ;
V_29 ++ ;
}
}
if ( V_29 )
return 3 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_27 * V_28 = & V_21 -> V_24 -> V_28 ;
unsigned int V_48 , V_49 ;
unsigned int V_50 , V_30 , V_51 , V_52 ;
int V_7 ;
#ifdef F_5
F_6 ( V_23 L_3 ) ;
#endif
F_1 ( V_2 ) ;
V_21 -> V_24 -> V_53 = 0 ;
if ( V_28 -> V_46 < 2 ) {
V_12 -> V_13 &= ~ V_54 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
} else {
V_12 -> V_13 |= V_54 ;
V_12 -> V_55 |= V_56 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
F_2 ( V_12 -> V_55 , V_2 -> V_3 + V_9 ) ;
}
for ( V_7 = 0 ; V_7 < V_28 -> V_46 ; ++ V_7 ) {
V_51 = F_12 ( V_28 -> V_57 [ V_7 ] ) ;
V_52 = F_13 ( V_28 -> V_57 [ V_7 ] ) ;
F_2 ( V_7 , V_2 -> V_3 + V_58 ) ;
V_30 = V_51 | ( V_52 << 6 ) ;
if ( V_7 == V_28 -> V_45 - 1 )
V_30 |= 0x0010 ;
F_2 ( V_30 , V_2 -> V_3 + V_10 ) ;
}
if ( V_28 -> V_44 < 65536000 ) {
V_49 = V_59 ;
V_48 = V_28 -> V_44 / 1000 ;
} else if ( V_28 -> V_44 < 655360000 ) {
V_49 = V_60 ;
V_48 = V_28 -> V_44 / 10000 ;
} else if ( V_28 -> V_44 <= 0xffffffff ) {
V_49 = V_61 ;
V_48 = V_28 -> V_44 / 100000 ;
} else if ( V_28 -> V_44 <= 0xffffffff ) {
V_49 = V_62 ;
V_48 = V_28 -> V_44 / 1000000 ;
}
F_2 ( 0xFF03 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_49 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0B , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF44 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF3 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_48 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF24 , V_2 -> V_3 + V_4 ) ;
V_50 = V_28 -> V_47 * V_28 -> V_45 ;
F_2 ( 0xFF04 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x1025 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0C , V_2 -> V_3 + V_4 ) ;
if ( V_50 < 65536 ) {
F_2 ( V_50 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF4 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
V_12 -> V_13 &= ~ V_63 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
} else {
V_30 = V_50 & 0xFFFF ;
if ( V_30 )
F_2 ( V_30 - 1 , V_2 -> V_3 + V_5 ) ;
else
F_2 ( 0xFFFF , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF48 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF28 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFF05 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x25 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0D , V_2 -> V_3 + V_4 ) ;
V_30 = V_50 & 0xFFFF ;
if ( ( V_30 == 0 ) || ( V_30 == 1 ) ) {
F_2 ( ( V_50 >> 16 ) & 0xFFFF ,
V_2 -> V_3 + V_5 ) ;
} else {
F_2 ( ( ( V_50 >> 16 ) & 0xFFFF ) + 1 ,
V_2 -> V_3 + V_5 ) ;
}
F_2 ( 0xFF70 , V_2 -> V_3 + V_4 ) ;
V_12 -> V_13 |= V_63 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
}
if ( V_28 -> V_46 > 1 ) {
if ( V_28 -> V_43 < 65536000 ) {
V_49 = V_59 ;
V_48 = V_28 -> V_43 / 1000 ;
} else if ( V_28 -> V_43 < 655360000 ) {
V_49 = V_60 ;
V_48 = V_28 -> V_43 / 10000 ;
} else if ( V_28 -> V_43 < 0xffffffff ) {
V_49 = V_61 ;
V_48 = V_28 -> V_43 / 100000 ;
} else if ( V_28 -> V_43 < 0xffffffff ) {
V_49 = V_62 ;
V_48 = V_28 -> V_43 / 1000000 ;
}
F_2 ( 0xFF02 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_49 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF0A , V_2 -> V_3 + V_4 ) ;
F_2 ( 0x2 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF42 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0xFFF2 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_48 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0xFF22 , V_2 -> V_3 + V_4 ) ;
}
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_58 ) ;
F_2 ( 0 , V_2 -> V_3 + V_11 ) ;
V_12 -> V_13 |= V_64 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
V_12 -> V_13 |= V_65 ;
V_12 -> V_55 |= V_66 ;
F_2 ( V_12 -> V_13 , V_2 -> V_3 + V_8 ) ;
F_2 ( V_12 -> V_55 , V_2 -> V_3 + V_9 ) ;
F_2 ( 0 , V_2 -> V_3 + V_67 ) ;
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
struct V_68 * V_69 , unsigned int * V_70 )
{
int V_7 , V_71 ;
int V_51 ;
int V_52 ;
int V_72 ;
#ifdef F_5
F_6 ( V_23 L_4 ) ;
#endif
V_51 = F_12 ( V_69 -> V_73 ) ;
V_52 = F_13 ( V_69 -> V_73 ) ;
F_2 ( V_51 | ( V_52 << 6 ) , V_2 -> V_3 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_74 ; V_7 ++ ) {
F_2 ( 0 , V_2 -> V_3 + V_75 ) ;
for ( V_71 = 0 ; V_71 < V_76 ; V_71 ++ ) {
V_72 = F_8 ( V_2 -> V_3 + V_77 ) ;
#ifdef F_5
F_6 ( V_23 L_5 , V_72 ) ;
#endif
if ( V_72 & V_78 ) {
V_70 [ V_7 ] = F_8 ( V_2 -> V_3 + V_25 ) ;
if ( V_12 -> V_14 == V_79 )
V_70 [ V_7 ] ^= 0x800 ;
break;
}
if ( V_72 & V_80 ) {
F_6 ( V_81 L_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
return - V_82 ;
}
}
if ( V_71 == V_76 ) {
F_6 ( V_81 L_7 ) ;
return - V_82 ;
}
}
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_68 * V_69 , unsigned int * V_70 )
{
int V_7 ;
#ifdef F_5
F_6 ( V_23 L_8 ) ;
#endif
for ( V_7 = 0 ; V_7 < V_69 -> V_74 ; V_7 ++ )
V_70 [ V_7 ] = V_12 -> V_83 [ F_12 ( V_69 -> V_73 ) ] ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_68 * V_69 , unsigned int * V_70 )
{
int V_7 ;
int V_51 ;
int V_19 ;
#ifdef F_5
F_6 ( V_23 L_9 ) ;
#endif
V_51 = F_12 ( V_69 -> V_73 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_74 ; V_7 ++ ) {
V_19 = V_70 [ V_7 ] ;
switch ( V_51 ) {
case 0 :
if ( V_12 -> V_84 == V_85 )
V_19 ^= 0x800 ;
F_2 ( V_19 , V_2 -> V_3 + V_16 ) ;
break;
case 1 :
if ( V_12 -> V_86 == V_85 )
V_19 ^= 0x800 ;
F_2 ( V_19 , V_2 -> V_3 + V_17 ) ;
break;
default:
return - V_87 ;
}
V_12 -> V_83 [ V_51 ] = V_70 [ V_7 ] ;
}
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_68 * V_69 , unsigned int * V_70 )
{
if ( V_69 -> V_74 != 2 )
return - V_87 ;
if ( V_70 [ 0 ] ) {
V_21 -> V_88 &= ~ V_70 [ 0 ] ;
V_21 -> V_88 |= ( V_70 [ 0 ] | V_70 [ 1 ] ) ;
F_2 ( V_21 -> V_88 , V_2 -> V_3 + V_89 ) ;
}
V_70 [ 1 ] = F_8 ( V_2 -> V_3 + V_90 ) ;
return 2 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_68 * V_69 ,
unsigned int * V_70 )
{
int V_7 ;
int V_91 ;
for ( V_7 = 0 ; V_7 < V_69 -> V_74 ; V_7 ++ ) {
V_91 = ( F_12 ( V_69 -> V_73 ) < 4 ) ? 0x0f : 0xf0 ;
V_21 -> V_92 &= ~ V_91 ;
if ( V_70 [ V_7 ] )
V_21 -> V_92 |= V_91 ;
}
V_12 -> V_55 &= ~ ( V_93 | V_94 ) ;
if ( V_21 -> V_92 & 0x0f )
V_12 -> V_55 |= V_93 ;
if ( V_21 -> V_92 & 0xf0 )
V_12 -> V_55 |= V_94 ;
F_2 ( V_12 -> V_55 , V_2 -> V_3 + V_9 ) ;
return V_7 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
unsigned int V_18 ;
unsigned long V_3 ;
int V_97 ;
struct V_20 * V_21 ;
V_3 = V_96 -> V_98 [ 0 ] ;
F_6 ( V_81 L_10 , V_2 -> V_99 , V_3 ) ;
if ( ! F_21 ( V_3 , V_100 , L_11 ) ) {
F_6 ( L_12 ) ;
return - V_101 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_102 = V_103 -> V_104 ;
V_97 = F_22 ( V_2 , 4 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_23 ( V_2 , sizeof( struct V_105 ) ) ;
if ( V_97 < 0 )
return V_97 ;
F_3 ( V_2 ) ;
V_18 = V_96 -> V_98 [ 1 ] ;
if ( V_18 ) {
V_97 = F_24 ( V_18 , F_4 , 0 , L_13 , V_2 ) ;
if ( V_97 < 0 ) {
F_6 ( V_81 L_14 , V_18 ) ;
return V_97 ;
}
V_2 -> V_18 = V_18 ;
F_6 ( V_81 L_15 , V_18 ) ;
} else {
F_6 ( V_81 L_16 ) ;
}
V_12 -> V_106 = V_96 -> V_98 [ 5 ] ;
V_12 -> V_107 = V_96 -> V_98 [ 6 ] ;
V_12 -> V_108 = V_96 -> V_98 [ 7 ] ;
V_12 -> V_109 = V_96 -> V_98 [ 8 ] ;
V_12 -> V_84 = V_96 -> V_98 [ 9 ] ;
V_12 -> V_110 = V_96 -> V_98 [ 10 ] ;
V_12 -> V_111 = V_96 -> V_98 [ 11 ] ;
V_12 -> V_86 = V_96 -> V_98 [ 12 ] ;
V_21 = V_2 -> V_22 + 0 ;
V_2 -> V_112 = V_21 ;
V_21 -> type = V_113 ;
V_21 -> V_114 = V_115 | V_116 | V_117 ;
V_21 -> V_118 = ( V_12 -> V_106 ? 16 : 8 ) ;
V_21 -> V_119 = 16 ;
V_21 -> V_120 = F_15 ;
V_21 -> V_121 = F_10 ;
V_21 -> V_122 = F_11 ;
V_21 -> V_123 = F_14 ;
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
V_21 -> V_120 = F_16 ;
V_21 -> V_134 = F_17 ;
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
V_21 -> V_142 = F_18 ;
V_21 -> V_143 = F_19 ;
V_21 -> V_124 = 1 ;
V_21 -> V_126 = & V_144 ;
V_21 ++ ;
if ( V_103 -> V_145 )
F_25 ( V_2 , V_21 , NULL , V_2 -> V_3 ) ;
else
V_21 -> type = V_146 ;
#if 0
s++;
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
F_6 ( L_17 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 && V_103 -> V_145 )
F_27 ( V_2 , V_2 -> V_22 + 3 ) ;
if ( V_2 -> V_18 )
F_28 ( V_2 -> V_18 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_3 )
F_29 ( V_2 -> V_3 , V_100 ) ;
}
