static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 = V_4 -> V_6 + V_7 ;
unsigned long V_8 = V_4 -> V_6 + V_9 ;
unsigned long V_10 , V_11 , V_12 ;
int V_13 ;
V_11 = F_2 ( V_8 ) ;
V_10 = F_2 ( V_5 ) ;
V_12 = V_10 &
( V_14 | V_15 | V_16 |
V_17 | V_18 | V_19 ) ;
if ( ! V_12 )
return V_20 ;
F_3 ( V_12 , V_5 ) ;
F_4 ( L_1 ,
V_4 -> V_21 ,
( ( ( V_12 & V_14 ) ?
L_2 :
( ( V_12 & V_15 ) ?
L_3 :
( ( V_12 & V_16 ) ?
L_4 : L_5 ) ) ) ) ) ;
F_4 ( L_6 ,
V_4 -> V_21 ,
( V_10 & V_22 ) >> 32UL ,
( V_10 & V_23 ) >> 29UL ,
( V_10 & V_24 ) >> 24UL ,
( ( V_10 & V_25 ) ? 1 : 0 ) ) ;
F_4 ( L_7 , V_4 -> V_21 , V_11 ) ;
F_4 ( L_8 , V_4 -> V_21 ) ;
V_13 = 0 ;
if ( V_10 & V_17 ) {
V_13 ++ ;
F_4 ( L_9 ) ;
}
if ( V_10 & V_18 ) {
V_13 ++ ;
F_4 ( L_10 ) ;
}
if ( V_10 & V_19 ) {
V_13 ++ ;
F_4 ( L_11 ) ;
}
if ( ! V_13 )
F_4 ( L_12 ) ;
F_4 ( L_13 ) ;
F_5 ( V_4 , V_10 , V_11 , V_26 ) ;
if ( V_4 -> V_27 )
F_5 ( V_4 -> V_27 , V_10 , V_11 , V_26 ) ;
return V_28 ;
}
static T_1 F_6 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 = V_4 -> V_6 + V_29 ;
unsigned long V_8 = V_4 -> V_6 + V_30 ;
unsigned long V_10 , V_11 , V_12 ;
int V_13 ;
V_11 = F_2 ( V_8 ) ;
V_10 = F_2 ( V_5 ) ;
V_12 = V_10 &
( V_31 | V_32 | V_33 |
V_34 | V_35 | V_36 ) ;
if ( ! V_12 )
return V_20 ;
F_3 ( V_12 , V_5 ) ;
F_4 ( L_14 ,
V_4 -> V_21 ,
( ( ( V_12 & V_31 ) ?
L_2 :
( ( V_12 & V_32 ) ?
L_3 :
( ( V_12 & V_33 ) ?
L_4 : L_5 ) ) ) ) ) ;
F_4 ( L_15
L_16 ,
V_4 -> V_21 ,
( V_10 & V_37 ) >> 48UL ,
( V_10 & V_38 ) >> 32UL ,
( V_10 & V_39 ) >> 29UL ,
( V_10 & V_40 ) >> 24UL ,
( ( V_10 & V_41 ) ? 1 : 0 ) ) ;
F_4 ( L_17 , V_4 -> V_21 , V_11 ) ;
F_4 ( L_18 , V_4 -> V_21 ) ;
V_13 = 0 ;
if ( V_10 & V_34 ) {
V_13 ++ ;
F_4 ( L_9 ) ;
}
if ( V_10 & V_35 ) {
V_13 ++ ;
F_4 ( L_10 ) ;
}
if ( V_10 & V_36 ) {
V_13 ++ ;
F_4 ( L_11 ) ;
}
if ( ! V_13 )
F_4 ( L_12 ) ;
F_4 ( L_13 ) ;
return V_28 ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_42 * V_43 = F_8 ( V_4 -> V_43 -> V_44 . V_45 ) ;
unsigned long V_46 = V_4 -> V_6 ;
T_2 V_47 ;
int V_48 ;
if ( ! V_43 )
return;
if ( V_43 -> V_49 . V_50 < 6 )
return;
V_48 = F_9 ( V_43 -> V_49 . V_51 [ 1 ] , F_1 , V_52 ,
L_19 , V_4 ) ;
V_48 = F_9 ( V_43 -> V_49 . V_51 [ 2 ] , F_6 , V_52 ,
L_20 , V_4 ) ;
V_48 = F_9 ( V_43 -> V_49 . V_51 [ 0 ] , V_53 , V_52 ,
L_21 , V_4 ) ;
if ( V_48 )
F_4 ( V_54 L_22
L_23 , V_4 -> V_21 , V_48 ) ;
F_3 ( ( V_55 |
V_56 |
V_57 ) , V_46 + V_58 ) ;
V_47 = F_2 ( V_46 + V_59 ) ;
V_47 |= ( V_60 |
V_61 |
V_62 ) ;
V_47 &= ~ ( V_63 ) ;
F_3 ( V_47 , V_46 + V_59 ) ;
V_47 = F_2 ( V_46 + V_64 ) ;
V_47 |= ( V_60 |
V_61 |
V_62 ) ;
V_47 &= ~ ( V_63 ) ;
F_3 ( V_47 , V_46 + V_64 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
T_3 * V_65 ;
V_65 = F_11 ( V_4 , V_4 -> V_66 ,
0 , V_67 ) ;
F_12 ( V_65 , 64 / sizeof( V_68 ) ) ;
V_65 = F_11 ( V_4 , V_4 -> V_66 ,
0 , V_69 ) ;
F_12 ( V_65 , 64 ) ;
}
static void F_13 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
F_10 ( V_4 ) ;
V_4 -> V_72 = 0 ;
V_4 -> V_73 = F_14 ( V_4 , V_71 ) ;
F_7 ( V_4 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
T_2 V_47 ;
F_3 ( 5 , V_4 -> V_6 + V_74 ) ;
V_47 = F_2 ( V_4 -> V_6 + V_59 ) ;
V_47 |= V_75 ;
F_3 ( V_47 , V_4 -> V_6 + V_59 ) ;
V_47 = F_2 ( V_4 -> V_6 + V_64 ) ;
V_47 |= V_75 ;
F_3 ( V_47 , V_4 -> V_6 + V_64 ) ;
V_47 = F_2 ( V_4 -> V_6 + V_76 ) ;
V_47 |= V_77 ;
F_3 ( V_47 , V_4 -> V_6 + V_76 ) ;
V_47 = F_2 ( V_4 -> V_6 + V_78 ) ;
V_47 |= V_77 ;
F_3 ( V_47 , V_4 -> V_6 + V_78 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
int V_79 )
{
unsigned long V_46 = V_4 -> V_6 ;
T_2 V_80 ;
if ( V_79 ) {
V_4 -> V_81 . V_82 = V_46 + V_83 ;
V_4 -> V_81 . V_84 = V_46 + V_85 ;
V_4 -> V_81 . V_86 = V_46 + V_87 ;
V_4 -> V_81 . V_88 = V_46 + V_89 ;
V_4 -> V_81 . V_90 = V_46 + V_91 ;
V_4 -> V_81 . V_92 = V_46 + V_93 ;
} else {
V_4 -> V_81 . V_82 = V_46 + V_94 ;
V_4 -> V_81 . V_84 = V_46 + V_95 ;
V_4 -> V_81 . V_86 = V_46 + V_96 ;
V_4 -> V_81 . V_88 = V_46 + V_97 ;
V_4 -> V_81 . V_90 = V_46 + V_98 ;
V_4 -> V_81 . V_92 = V_46 + V_99 ;
}
V_4 -> V_81 . V_100 = 0 ;
V_4 -> V_81 . V_101 = 0 ;
V_4 -> V_81 . V_102 = ( volatile unsigned long * )
( ( ( ( unsigned long ) & V_4 -> V_81 . V_103 [ 0 ] )
+ 63UL )
& ~ 63UL ) ;
V_4 -> V_81 . V_104 = ( unsigned long )
F_17 ( V_4 -> V_81 . V_102 ) ;
#undef V_105
#undef V_106
V_80 = F_2 ( V_4 -> V_81 . V_82 ) ;
V_80 |= V_107 ;
V_80 &= ~ ( V_108 | V_109 ) ;
#ifdef V_105
V_80 &= ~ ( V_110 ) ;
#else
#ifdef V_106
V_80 |= V_110 ;
#endif
#endif
F_3 ( V_80 , V_4 -> V_81 . V_82 ) ;
V_4 -> V_81 . V_111 = 1 ;
}
static void F_18 ( struct V_3 * V_4 ,
struct V_42 * V_43 , int V_79 )
{
F_19 ( V_4 , V_43 , L_24 , V_112 ) ;
F_16 ( V_4 , V_79 ) ;
F_13 ( V_4 , & V_43 -> V_44 ) ;
}
static struct V_3 * F_20 ( V_68 V_113 )
{
struct V_3 * V_4 ;
for ( V_4 = V_114 ; V_4 ; V_4 = V_4 -> V_115 ) {
if ( V_4 -> V_116 == V_113 )
return V_4 ;
}
return NULL ;
}
static int F_21 ( struct V_42 * V_43 )
{
const struct V_117 * V_118 ;
struct V_119 * V_120 = V_43 -> V_44 . V_45 ;
struct V_3 * V_4 ;
struct V_121 * V_121 ;
int V_79 , V_48 ;
V_68 V_113 ;
V_113 = F_22 ( V_120 , L_25 , 0xff ) ;
V_48 = - V_122 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_123 ) ;
if ( ! V_4 ) {
F_4 (KERN_ERR PFX L_26 ) ;
goto V_124;
}
V_4 -> V_27 = F_20 ( V_113 ) ;
if ( V_4 -> V_27 ) {
V_121 = V_4 -> V_27 -> V_121 ;
} else {
V_121 = F_23 ( sizeof( struct V_121 ) , V_123 ) ;
if ( ! V_121 ) {
F_4 (KERN_ERR PFX L_27 ) ;
goto V_125;
}
}
V_4 -> V_121 = V_121 ;
V_4 -> V_116 = V_113 ;
V_118 = F_24 ( V_120 , L_28 , NULL ) ;
V_48 = - V_126 ;
if ( ! V_118 ) {
F_4 (KERN_ERR PFX L_29 ) ;
goto V_127;
}
V_79 = ( ( V_118 [ 0 ] . V_128 & 0x6000 ) == 0x2000 ) ;
V_4 -> V_6 = V_118 [ 2 ] . V_128 ;
V_4 -> V_129 = ( V_118 [ 2 ] . V_128 + V_130 ) ;
if ( V_79 ) {
V_4 -> V_131 = V_4 -> V_6 + V_132 ;
V_4 -> V_133 = V_4 -> V_6 + V_134 ;
V_4 -> V_135 = V_4 -> V_6 + V_59 ;
} else {
V_4 -> V_131 = V_4 -> V_6 + V_136 ;
V_4 -> V_133 = V_4 -> V_6 + V_137 ;
V_4 -> V_135 = V_4 -> V_6 + V_64 ;
}
F_15 ( V_4 ) ;
if ( ! V_4 -> V_27 ) {
V_48 = F_25 ( V_4 , 128 , 0xc0000000 ,
0xffffffff , V_138 ) ;
if ( V_48 )
goto V_127;
if ( V_139 )
F_26 ( V_4 -> V_116 ) ;
}
F_18 ( V_4 , V_43 , V_79 ) ;
V_4 -> V_115 = V_114 ;
V_114 = V_4 ;
if ( V_4 -> V_27 )
V_4 -> V_27 -> V_27 = V_4 ;
F_27 ( & V_43 -> V_44 , V_4 ) ;
return 0 ;
V_127:
if ( ! V_4 -> V_27 )
F_28 ( V_4 -> V_121 ) ;
V_125:
F_28 ( V_4 ) ;
V_124:
return V_48 ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_140 ) ;
}
