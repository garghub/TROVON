static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( 0xFFC2 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF02 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x4 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0A , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x3 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF42 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF42 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFC4 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF03 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x4 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0B , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x3 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF44 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF44 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFC8 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF04 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x4 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0C , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x3 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF48 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF48 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFD0 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF05 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x4 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0D , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x3 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF50 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF50 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0 , V_3 -> V_4 + V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
int V_8 ;
F_6 ( 0 , V_3 -> V_4 + V_9 ) ;
F_6 ( 0 , V_3 -> V_4 + V_10 ) ;
F_6 ( 0 , V_3 -> V_4 + V_11 ) ;
F_6 ( 0xFFFF , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFEF , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF17 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xF000 , V_3 -> V_4 + V_6 ) ;
for ( V_8 = 1 ; V_8 <= 5 ; ++ V_8 ) {
F_6 ( 0xFF00 + V_8 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x0004 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF08 + V_8 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x3 , V_3 -> V_4 + V_6 ) ;
}
F_6 ( 0xFF5F , V_3 -> V_4 + V_5 ) ;
F_6 ( 0 , V_3 -> V_4 + V_7 ) ;
F_6 ( 0 , V_3 -> V_4 + V_12 ) ;
V_13 -> V_14 |= 1 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
V_13 -> V_15 = V_16 ;
F_6 ( 2048 , V_3 -> V_4 + V_17 ) ;
F_6 ( 2048 , V_3 -> V_4 + V_18 ) ;
}
static T_3 F_8 ( int V_19 , void * V_20 )
{
struct V_2 * V_3 = V_20 ;
struct V_21 * V_22 = V_3 -> V_23 + 0 ;
#ifdef F_9
F_10 ( V_24 L_1 ) ;
#endif
F_11 ( V_22 -> V_25 , F_12 ( V_3 -> V_4 + V_26 ) ) ;
F_13 ( V_3 , V_22 ) ;
return V_27 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_28 * V_29 )
{
int V_30 = 0 , V_31 ;
#ifdef F_9
F_10 ( V_24 L_2 ) ;
#endif
V_31 = V_29 -> V_32 ;
V_29 -> V_32 &= V_33 ;
if ( ! V_29 -> V_32 || V_31 != V_29 -> V_32 )
V_30 ++ ;
V_31 = V_29 -> V_34 ;
V_29 -> V_34 &= V_35 | V_36 ;
if ( ! V_29 -> V_34 || V_31 != V_29 -> V_34 )
V_30 ++ ;
V_31 = V_29 -> V_37 ;
V_29 -> V_37 &= V_36 ;
if ( ! V_29 -> V_37 || V_31 != V_29 -> V_37 )
V_30 ++ ;
V_31 = V_29 -> V_38 ;
V_29 -> V_38 &= V_39 ;
if ( ! V_29 -> V_38 || V_31 != V_29 -> V_38 )
V_30 ++ ;
V_31 = V_29 -> V_40 ;
V_29 -> V_40 &= V_39 | V_41 ;
if ( ! V_29 -> V_40 || V_31 != V_29 -> V_40 )
V_30 ++ ;
if ( V_30 )
return 1 ;
if ( V_29 -> V_34 != V_35 &&
V_29 -> V_34 != V_42 &&
V_29 -> V_34 != V_36 )
V_30 ++ ;
if ( V_29 -> V_40 != V_39 && V_29 -> V_40 != V_41 )
V_30 ++ ;
if ( V_30 )
return 2 ;
if ( V_29 -> V_43 != 0 ) {
V_29 -> V_43 = 0 ;
V_30 ++ ;
}
if ( V_29 -> V_34 == V_35 ) {
if ( V_29 -> V_44 != 0 ) {
V_29 -> V_44 = 0 ;
V_30 ++ ;
}
} else {
#if 0
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
#endif
}
if ( V_29 -> V_45 < 10000 ) {
V_29 -> V_45 = 10000 ;
V_30 ++ ;
}
#if 0
if (cmd->convert_arg > SLOWEST_TIMER) {
cmd->convert_arg = SLOWEST_TIMER;
err++;
}
#endif
if ( V_29 -> V_46 != V_29 -> V_47 ) {
V_29 -> V_46 = V_29 -> V_47 ;
V_30 ++ ;
}
if ( V_29 -> V_40 == V_39 ) {
} else {
if ( V_29 -> V_48 != 0 ) {
V_29 -> V_48 = 0 ;
V_30 ++ ;
}
}
if ( V_30 )
return 3 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
struct V_28 * V_29 = & V_22 -> V_25 -> V_29 ;
unsigned int V_49 , V_50 ;
unsigned int V_51 , V_31 , V_52 , V_53 ;
int V_8 ;
#ifdef F_9
F_10 ( V_24 L_3 ) ;
#endif
F_5 ( V_3 ) ;
V_22 -> V_25 -> V_54 = 0 ;
if ( V_29 -> V_47 < 2 ) {
V_13 -> V_14 &= ~ V_55 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
} else {
V_13 -> V_14 |= V_55 ;
V_13 -> V_56 |= V_57 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
F_6 ( V_13 -> V_56 , V_3 -> V_4 + V_10 ) ;
}
for ( V_8 = 0 ; V_8 < V_29 -> V_47 ; ++ V_8 ) {
V_52 = F_16 ( V_29 -> V_58 [ V_8 ] ) ;
V_53 = F_17 ( V_29 -> V_58 [ V_8 ] ) ;
F_6 ( V_8 , V_3 -> V_4 + V_59 ) ;
V_31 = V_52 | ( V_53 << 6 ) ;
if ( V_8 == V_29 -> V_46 - 1 )
V_31 |= 0x0010 ;
F_6 ( V_31 , V_3 -> V_4 + V_11 ) ;
}
if ( V_29 -> V_45 < 65536000 ) {
V_50 = V_60 ;
V_49 = V_29 -> V_45 / 1000 ;
} else if ( V_29 -> V_45 < 655360000 ) {
V_50 = V_61 ;
V_49 = V_29 -> V_45 / 10000 ;
} else if ( V_29 -> V_45 <= 0xffffffff ) {
V_50 = V_62 ;
V_49 = V_29 -> V_45 / 100000 ;
} else if ( V_29 -> V_45 <= 0xffffffff ) {
V_50 = V_63 ;
V_49 = V_29 -> V_45 / 1000000 ;
}
F_6 ( 0xFF03 , V_3 -> V_4 + V_5 ) ;
F_6 ( V_50 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0B , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x2 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF44 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFF3 , V_3 -> V_4 + V_5 ) ;
F_6 ( V_49 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF24 , V_3 -> V_4 + V_5 ) ;
V_51 = V_29 -> V_48 * V_29 -> V_46 ;
F_6 ( 0xFF04 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x1025 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0C , V_3 -> V_4 + V_5 ) ;
if ( V_51 < 65536 ) {
F_6 ( V_51 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF48 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFF4 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF28 , V_3 -> V_4 + V_5 ) ;
V_13 -> V_14 &= ~ V_64 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
} else {
V_31 = V_51 & 0xFFFF ;
if ( V_31 )
F_6 ( V_31 - 1 , V_3 -> V_4 + V_6 ) ;
else
F_6 ( 0xFFFF , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF48 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF28 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFF05 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x25 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0D , V_3 -> V_4 + V_5 ) ;
V_31 = V_51 & 0xFFFF ;
if ( ( V_31 == 0 ) || ( V_31 == 1 ) ) {
F_6 ( ( V_51 >> 16 ) & 0xFFFF ,
V_3 -> V_4 + V_6 ) ;
} else {
F_6 ( ( ( V_51 >> 16 ) & 0xFFFF ) + 1 ,
V_3 -> V_4 + V_6 ) ;
}
F_6 ( 0xFF70 , V_3 -> V_4 + V_5 ) ;
V_13 -> V_14 |= V_64 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
}
if ( V_29 -> V_47 > 1 ) {
if ( V_29 -> V_44 < 65536000 ) {
V_50 = V_60 ;
V_49 = V_29 -> V_44 / 1000 ;
} else if ( V_29 -> V_44 < 655360000 ) {
V_50 = V_61 ;
V_49 = V_29 -> V_44 / 10000 ;
} else if ( V_29 -> V_44 < 0xffffffff ) {
V_50 = V_62 ;
V_49 = V_29 -> V_44 / 100000 ;
} else if ( V_29 -> V_44 < 0xffffffff ) {
V_50 = V_63 ;
V_49 = V_29 -> V_44 / 1000000 ;
}
F_6 ( 0xFF02 , V_3 -> V_4 + V_5 ) ;
F_6 ( V_50 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF0A , V_3 -> V_4 + V_5 ) ;
F_6 ( 0x2 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF42 , V_3 -> V_4 + V_5 ) ;
F_6 ( 0xFFF2 , V_3 -> V_4 + V_5 ) ;
F_6 ( V_49 , V_3 -> V_4 + V_6 ) ;
F_6 ( 0xFF22 , V_3 -> V_4 + V_5 ) ;
}
F_6 ( 0 , V_3 -> V_4 + V_7 ) ;
F_6 ( 0 , V_3 -> V_4 + V_59 ) ;
F_6 ( 0 , V_3 -> V_4 + V_12 ) ;
V_13 -> V_14 |= V_65 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
V_13 -> V_14 |= V_66 ;
V_13 -> V_56 |= V_67 ;
F_6 ( V_13 -> V_14 , V_3 -> V_4 + V_9 ) ;
F_6 ( V_13 -> V_56 , V_3 -> V_4 + V_10 ) ;
F_6 ( 0 , V_3 -> V_4 + V_68 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
F_7 ( V_3 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_69 * V_70 , unsigned int * V_71 )
{
int V_8 , V_72 ;
int V_52 ;
int V_53 ;
int V_73 ;
#ifdef F_9
F_10 ( V_24 L_4 ) ;
#endif
V_52 = F_16 ( V_70 -> V_74 ) ;
V_53 = F_17 ( V_70 -> V_74 ) ;
F_6 ( V_52 | ( V_53 << 6 ) , V_3 -> V_4 + V_11 ) ;
for ( V_8 = 0 ; V_8 < V_70 -> V_75 ; V_8 ++ ) {
F_6 ( 0 , V_3 -> V_4 + V_76 ) ;
for ( V_72 = 0 ; V_72 < V_77 ; V_72 ++ ) {
V_73 = F_12 ( V_3 -> V_4 + V_78 ) ;
#ifdef F_9
F_10 ( V_24 L_5 , V_73 ) ;
#endif
if ( V_73 & V_79 ) {
V_71 [ V_8 ] = F_12 ( V_3 -> V_4 + V_26 ) ;
if ( V_13 -> V_15 == V_80 )
V_71 [ V_8 ] ^= 0x800 ;
break;
}
if ( V_73 & V_81 ) {
F_10 ( V_82 L_6 ) ;
F_6 ( 0 , V_3 -> V_4 + V_7 ) ;
return - V_83 ;
}
}
if ( V_72 == V_77 ) {
F_10 ( V_82 L_7 ) ;
return - V_83 ;
}
}
return V_8 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_69 * V_70 , unsigned int * V_71 )
{
int V_8 ;
#ifdef F_9
F_10 ( V_24 L_8 ) ;
#endif
for ( V_8 = 0 ; V_8 < V_70 -> V_75 ; V_8 ++ )
V_71 [ V_8 ] = V_13 -> V_84 [ F_16 ( V_70 -> V_74 ) ] ;
return V_8 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_69 * V_70 , unsigned int * V_71 )
{
int V_8 ;
int V_52 ;
int V_20 ;
#ifdef F_9
F_10 ( V_24 L_9 ) ;
#endif
V_52 = F_16 ( V_70 -> V_74 ) ;
for ( V_8 = 0 ; V_8 < V_70 -> V_75 ; V_8 ++ ) {
V_20 = V_71 [ V_8 ] ;
switch ( V_52 ) {
case 0 :
if ( V_13 -> V_85 == V_86 )
V_20 ^= 0x800 ;
F_6 ( V_20 , V_3 -> V_4 + V_17 ) ;
break;
case 1 :
if ( V_13 -> V_87 == V_86 )
V_20 ^= 0x800 ;
F_6 ( V_20 , V_3 -> V_4 + V_18 ) ;
break;
default:
return - V_88 ;
}
V_13 -> V_84 [ V_52 ] = V_71 [ V_8 ] ;
}
return V_8 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_69 * V_70 , unsigned int * V_71 )
{
if ( V_70 -> V_75 != 2 )
return - V_88 ;
if ( V_71 [ 0 ] ) {
V_22 -> V_89 &= ~ V_71 [ 0 ] ;
V_22 -> V_89 |= ( V_71 [ 0 ] | V_71 [ 1 ] ) ;
F_6 ( V_22 -> V_89 , V_3 -> V_4 + V_90 ) ;
}
V_71 [ 1 ] = F_12 ( V_3 -> V_4 + V_91 ) ;
return 2 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_69 * V_70 ,
unsigned int * V_71 )
{
int V_8 ;
int V_92 ;
for ( V_8 = 0 ; V_8 < V_70 -> V_75 ; V_8 ++ ) {
V_92 = ( F_16 ( V_70 -> V_74 ) < 4 ) ? 0x0f : 0xf0 ;
V_22 -> V_93 &= ~ V_92 ;
if ( V_71 [ V_8 ] )
V_22 -> V_93 |= V_92 ;
}
V_13 -> V_56 &= ~ ( V_94 | V_95 ) ;
if ( V_22 -> V_93 & 0x0f )
V_13 -> V_56 |= V_94 ;
if ( V_22 -> V_93 & 0xf0 )
V_13 -> V_56 |= V_95 ;
F_6 ( V_13 -> V_56 , V_3 -> V_4 + V_10 ) ;
return V_8 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_96 * V_97 )
{
unsigned int V_19 ;
unsigned long V_4 ;
int V_98 ;
struct V_21 * V_22 ;
V_4 = V_97 -> V_99 [ 0 ] ;
F_10 ( V_82 L_10 , V_3 -> V_100 , V_4 ) ;
if ( ! F_25 ( V_4 , V_101 , L_11 ) ) {
F_10 ( L_12 ) ;
return - V_102 ;
}
V_3 -> V_4 = V_4 ;
V_3 -> V_103 = V_104 -> V_105 ;
V_98 = F_26 ( V_3 , 4 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 = F_27 ( V_3 , sizeof( struct V_106 ) ) ;
if ( V_98 < 0 )
return V_98 ;
F_7 ( V_3 ) ;
V_19 = V_97 -> V_99 [ 1 ] ;
if ( V_19 ) {
V_98 = F_28 ( V_19 , F_8 , 0 , L_13 , V_3 ) ;
if ( V_98 < 0 ) {
F_10 ( V_82 L_14 , V_19 ) ;
return V_98 ;
}
V_3 -> V_19 = V_19 ;
F_10 ( V_82 L_15 , V_19 ) ;
} else {
F_10 ( V_82 L_16 ) ;
}
V_13 -> V_107 = V_97 -> V_99 [ 5 ] ;
V_13 -> V_108 = V_97 -> V_99 [ 6 ] ;
V_13 -> V_109 = V_97 -> V_99 [ 7 ] ;
V_13 -> V_110 = V_97 -> V_99 [ 8 ] ;
V_13 -> V_85 = V_97 -> V_99 [ 9 ] ;
V_13 -> V_111 = V_97 -> V_99 [ 10 ] ;
V_13 -> V_112 = V_97 -> V_99 [ 11 ] ;
V_13 -> V_87 = V_97 -> V_99 [ 12 ] ;
V_22 = V_3 -> V_23 + 0 ;
V_3 -> V_113 = V_22 ;
V_22 -> type = V_114 ;
V_22 -> V_115 = V_116 | V_117 | V_118 ;
V_22 -> V_119 = ( V_13 -> V_107 ? 16 : 8 ) ;
V_22 -> V_120 = 16 ;
V_22 -> V_121 = F_19 ;
V_22 -> V_122 = F_14 ;
V_22 -> V_123 = F_15 ;
V_22 -> V_124 = F_18 ;
V_22 -> V_125 = 0xfff ;
switch ( V_13 -> V_108 ) {
case V_126 :
V_22 -> V_127 = & V_128 ;
break;
case V_129 :
V_22 -> V_127 = & V_130 ;
break;
case V_131 :
V_22 -> V_127 = & V_132 ;
break;
}
V_22 ++ ;
V_22 -> type = V_133 ;
V_22 -> V_115 = V_134 ;
V_22 -> V_119 = 2 ;
V_22 -> V_121 = F_20 ;
V_22 -> V_135 = F_21 ;
V_22 -> V_125 = 0xfff ;
V_22 -> V_136 = V_13 -> V_137 ;
switch ( V_13 -> V_109 ) {
case V_138 :
V_13 -> V_137 [ 0 ] = & V_139 ;
break;
case V_140 :
V_13 -> V_137 [ 0 ] = & V_141 ;
break;
}
switch ( V_13 -> V_111 ) {
case V_138 :
V_13 -> V_137 [ 1 ] = & V_139 ;
break;
case V_140 :
V_13 -> V_137 [ 1 ] = & V_141 ;
break;
}
V_22 ++ ;
V_22 -> type = V_142 ;
V_22 -> V_115 = V_134 | V_116 ;
V_22 -> V_119 = 8 ;
V_22 -> V_143 = F_22 ;
V_22 -> V_144 = F_23 ;
V_22 -> V_125 = 1 ;
V_22 -> V_127 = & V_145 ;
V_22 ++ ;
if ( V_104 -> V_146 )
F_29 ( V_3 , V_22 , NULL , V_3 -> V_4 ) ;
else
V_22 -> type = V_147 ;
#if 0
s++;
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
F_10 ( L_17 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
F_10 ( V_82 L_18 , V_3 -> V_100 ) ;
if ( V_3 -> V_23 && V_104 -> V_146 )
F_31 ( V_3 , V_3 -> V_23 + 3 ) ;
if ( V_3 -> V_19 )
F_32 ( V_3 -> V_19 , V_3 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_4 )
F_33 ( V_3 -> V_4 , V_101 ) ;
return 0 ;
}
