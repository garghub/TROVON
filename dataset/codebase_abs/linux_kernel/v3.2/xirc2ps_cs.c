static void
F_1 ( unsigned int V_1 )
{
F_2 ( V_2 , 0x04 | 0 ) ;
F_3 ( 1 ) ;
F_2 ( V_2 , 0x04 | 1 ) ;
F_3 ( 1 ) ;
}
static void
F_4 ( unsigned int V_1 , unsigned V_3 )
{
#if 1
if ( V_3 ) {
F_2 ( V_2 , 0x0c | 2 | 0 ) ;
F_3 ( 1 ) ;
F_2 ( V_2 , 0x0c | 2 | 1 ) ;
F_3 ( 1 ) ;
} else {
F_2 ( V_2 , 0x0c | 0 | 0 ) ;
F_3 ( 1 ) ;
F_2 ( V_2 , 0x0c | 0 | 1 ) ;
F_3 ( 1 ) ;
}
#else
if ( V_3 ) {
F_5 ( V_2 - 1 , 0x0e0e ) ;
F_3 ( 1 ) ;
F_5 ( V_2 - 1 , 0x0f0f ) ;
F_3 ( 1 ) ;
} else {
F_5 ( V_2 - 1 , 0x0c0c ) ;
F_3 ( 1 ) ;
F_5 ( V_2 - 1 , 0x0d0d ) ;
F_3 ( 1 ) ;
}
#endif
}
static int
F_6 ( unsigned int V_1 )
{
unsigned V_4 ;
F_2 ( V_2 , 4 | 0 ) ;
F_3 ( 1 ) ;
V_4 = F_7 ( V_2 ) ;
F_2 ( V_2 , 4 | 1 ) ;
F_3 ( 1 ) ;
return V_4 & 0x20 ;
}
static void
F_8 ( unsigned int V_1 , unsigned V_3 , int V_5 )
{
unsigned V_6 = 1 << ( V_5 - 1 ) ;
for (; V_6 ; V_6 >>= 1 )
F_4 ( V_1 , V_3 & V_6 ) ;
}
static unsigned
F_9 ( unsigned int V_1 , T_1 V_7 , T_1 V_8 )
{
int V_9 ;
unsigned V_3 = 0 , V_6 ;
F_10 ( 2 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ )
F_4 ( V_1 , 1 ) ;
F_8 ( V_1 , 0x06 , 4 ) ;
F_8 ( V_1 , V_7 , 5 ) ;
F_8 ( V_1 , V_8 , 5 ) ;
F_1 ( V_1 ) ;
F_6 ( V_1 ) ;
for ( V_6 = 1 << 15 ; V_6 ; V_6 >>= 1 )
if ( F_6 ( V_1 ) )
V_3 |= V_6 ;
F_1 ( V_1 ) ;
return V_3 ;
}
static void
F_11 ( unsigned int V_1 , T_1 V_7 , T_1 V_8 , unsigned V_3 ,
int V_5 )
{
int V_9 ;
F_10 ( 2 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ )
F_4 ( V_1 , 1 ) ;
F_8 ( V_1 , 0x05 , 4 ) ;
F_8 ( V_1 , V_7 , 5 ) ;
F_8 ( V_1 , V_8 , 5 ) ;
F_4 ( V_1 , 1 ) ;
F_4 ( V_1 , 0 ) ;
F_8 ( V_1 , V_3 , V_5 ) ;
F_1 ( V_1 ) ;
}
static int
F_12 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
T_2 * V_14 ;
F_13 ( & V_11 -> V_13 , L_1 ) ;
V_13 = F_14 ( sizeof( T_2 ) ) ;
if ( ! V_13 )
return - V_15 ;
V_14 = F_15 ( V_13 ) ;
V_14 -> V_13 = V_13 ;
V_14 -> V_16 = V_11 ;
V_11 -> V_17 = V_13 ;
V_11 -> V_18 = 1 ;
V_13 -> V_19 = & V_19 ;
V_13 -> V_20 = & V_21 ;
V_13 -> V_22 = V_23 ;
F_16 ( & V_14 -> V_24 , V_25 ) ;
return F_17 ( V_11 ) ;
}
static void
F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_17 ;
F_13 ( & V_11 -> V_13 , L_2 ) ;
F_19 ( V_13 ) ;
F_20 ( V_11 ) ;
F_21 ( V_13 ) ;
}
static int
F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_17 ;
T_2 * V_14 = F_15 ( V_13 ) ;
T_3 * V_26 ;
unsigned int V_27 , V_28 , V_29 ;
T_4 V_5 ;
V_5 = F_23 ( V_11 , V_30 , & V_26 ) ;
if ( V_5 < 5 ) {
F_24 ( & V_11 -> V_13 , L_3 ) ;
return 0 ;
}
V_27 = V_26 [ 2 ] ;
V_28 = V_26 [ 3 ] ;
V_29 = V_26 [ 4 ] ;
F_13 ( & V_11 -> V_13 , L_4 ,
V_27 , V_28 , V_29 ) ;
V_14 -> V_31 = 0 ;
V_14 -> V_32 = 0 ;
V_14 -> V_33 = 0 ;
V_14 -> V_34 = V_35 ;
if ( ! ( V_29 & 0x40 ) ) {
F_25 ( L_5 ) ;
return 0 ;
}
if ( ! ( V_28 & 0x01 ) ) {
F_25 ( L_6 ) ;
return 0 ;
}
if ( V_28 & 0x10 ) {
V_14 -> V_33 = 1 ;
switch( V_29 & 15 ) {
case 1 : V_14 -> V_34 = V_36 ; break;
case 2 : V_14 -> V_34 = V_37 ; break;
case 3 : V_14 -> V_34 = V_38 ; break;
case 4 : V_14 -> V_34 = V_39 ; break;
case 5 : V_14 -> V_34 = V_40 ;
V_14 -> V_31 = 1 ;
break;
case 6 :
case 7 :
V_14 -> V_34 = V_41 ;
V_14 -> V_31 = 1 ;
V_14 -> V_32 = 1 ;
break;
}
} else {
switch( V_29 & 15 ) {
case 1 : V_14 -> V_34 = F_26 ( V_11 ) ? V_42 : V_43 ;
break;
case 2 : V_14 -> V_34 = V_42 ; break;
case 3 : V_14 -> V_34 = V_44 ;
V_14 -> V_31 = 1 ;
break;
}
}
if ( V_14 -> V_34 == V_43 || V_14 -> V_34 == V_36 ) {
F_25 ( L_7 ) ;
return 0 ;
}
if ( V_14 -> V_34 == V_35 )
F_25 ( L_8 , V_28 , V_29 ) ;
return 1 ;
}
static int
F_26 ( struct V_10 * V_16 )
{
if ( V_16 -> V_45 [ 2 ] && strstr ( V_16 -> V_45 [ 2 ] , L_9 ) )
return 1 ;
return 0 ;
}
static int
F_27 ( struct V_10 * V_16 , void * V_46 )
{
unsigned int V_1 ;
if ( ( V_16 -> V_47 [ 0 ] -> V_48 & 0xf ) == 8 )
return - V_49 ;
V_16 -> V_47 [ 0 ] -> V_50 = 16 ;
V_16 -> V_47 [ 1 ] -> V_50 = 8 ;
V_16 -> V_47 [ 0 ] -> V_51 &= ~ V_52 ;
V_16 -> V_47 [ 0 ] -> V_51 |= V_53 ;
V_16 -> V_47 [ 1 ] -> V_51 &= ~ V_52 ;
V_16 -> V_47 [ 1 ] -> V_51 |= V_54 ;
V_16 -> V_55 = 10 ;
V_16 -> V_47 [ 1 ] -> V_48 = V_16 -> V_47 [ 0 ] -> V_48 ;
for ( V_1 = 0x300 ; V_1 < 0x400 ; V_1 += 0x10 ) {
V_16 -> V_47 [ 0 ] -> V_48 = V_1 ;
if ( ! F_28 ( V_16 ) )
return 0 ;
}
return - V_49 ;
}
static int
F_29 ( struct V_10 * V_16 , void * V_46 )
{
int * V_56 = V_46 ;
T_5 V_57 = V_16 -> V_47 [ 1 ] -> V_48 ;
V_57 += ( * V_56 ? ( V_16 -> V_18 & 0x20 ? - 24 : 8 )
: ( V_16 -> V_18 & 0x20 ? 8 : - 24 ) ) ;
if ( ( V_16 -> V_47 [ 0 ] -> V_48 & 0xf ) == 8 )
return - V_49 ;
V_16 -> V_47 [ 0 ] -> V_50 = 18 ;
V_16 -> V_47 [ 1 ] -> V_50 = 8 ;
V_16 -> V_47 [ 0 ] -> V_51 &= ~ V_52 ;
V_16 -> V_47 [ 0 ] -> V_51 |= V_53 ;
V_16 -> V_47 [ 1 ] -> V_51 &= ~ V_52 ;
V_16 -> V_47 [ 1 ] -> V_51 |= V_54 ;
V_16 -> V_55 = 10 ;
V_16 -> V_47 [ 1 ] -> V_48 = V_16 -> V_47 [ 0 ] -> V_48 ;
V_16 -> V_47 [ 0 ] -> V_48 = V_57 ;
return F_28 ( V_16 ) ;
}
static int F_30 ( struct V_10 * V_16 ,
T_6 * V_58 ,
void * V_17 )
{
struct V_12 * V_13 = V_17 ;
int V_9 ;
if ( V_58 -> V_59 != 13 )
return - V_60 ;
if ( ( V_58 -> V_61 [ 0 ] != 2 ) || ( V_58 -> V_61 [ 1 ] != 1 ) ||
( V_58 -> V_61 [ 2 ] != 6 ) )
return - V_60 ;
for ( V_9 = 2 ; V_9 < 6 ; V_9 ++ )
V_13 -> V_62 [ V_9 ] = V_58 -> V_61 [ V_9 + 2 ] ;
return 0 ;
}
static int
F_17 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_17 ;
T_2 * V_14 = F_15 ( V_13 ) ;
unsigned int V_1 ;
int V_63 ;
T_3 * V_26 ;
T_4 V_5 ;
V_14 -> V_64 = NULL ;
F_13 ( & V_11 -> V_13 , L_10 ) ;
if ( V_11 -> V_65 == 0 ) {
F_25 ( L_11 ) ;
goto V_66;
}
switch ( V_11 -> V_67 ) {
case V_68 :
V_14 -> V_69 = L_12 ;
break;
case V_70 :
V_14 -> V_69 = L_13 ;
break;
case V_71 :
case V_72 :
V_14 -> V_69 = L_14 ;
break;
case V_73 :
V_14 -> V_69 = L_15 ;
break;
case V_74 :
V_14 -> V_69 = L_16 ;
break;
default:
F_25 ( L_17 ,
( unsigned ) V_11 -> V_67 ) ;
goto V_66;
}
F_13 ( & V_11 -> V_13 , L_18 , V_14 -> V_69 ) ;
if ( ! F_22 ( V_11 ) ) {
F_25 ( L_19 ) ;
goto V_66;
}
V_63 = F_31 ( V_11 , V_13 ) ;
if ( V_63 ) {
V_5 = F_23 ( V_11 , 0x89 , & V_26 ) ;
if ( V_26 && V_5 == 8 ) {
if ( * V_26 == V_75 ) {
int V_9 ;
for ( V_9 = 2 ; V_9 < 6 ; V_9 ++ )
V_13 -> V_62 [ V_9 ] = V_26 [ V_9 + 2 ] ;
} else
V_63 = - 1 ;
}
F_32 ( V_26 ) ;
}
if ( V_63 )
V_63 = F_33 ( V_11 , V_76 , F_30 , V_13 ) ;
if ( V_63 ) {
F_25 ( L_20 ) ;
goto V_66;
}
if ( V_14 -> V_33 ) {
int V_56 ;
V_11 -> V_77 |= V_78 ;
if ( V_14 -> V_32 ) {
if ( ! F_34 ( V_11 , F_27 , NULL ) )
goto V_79;
} else {
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ )
if ( ! F_34 ( V_11 , F_29 ,
& V_56 ) )
goto V_79;
}
F_25 ( L_21 ) ;
} else {
V_11 -> V_55 = 10 ;
V_11 -> V_47 [ 0 ] -> V_50 = 16 ;
V_11 -> V_47 [ 0 ] -> V_51 |= V_53 ;
for ( V_1 = 0x300 ; V_1 < 0x400 ; V_1 += 0x10 ) {
V_11 -> V_47 [ 0 ] -> V_48 = V_1 ;
if ( ! ( V_63 = F_28 ( V_11 ) ) )
goto V_79;
}
V_11 -> V_47 [ 0 ] -> V_48 = 0 ;
if ( ( V_63 = F_28 ( V_11 ) ) )
goto V_80;
}
V_79:
if ( V_63 )
goto V_80;
if ( ( V_63 = F_35 ( V_11 , V_81 ) ) )
goto V_80;
V_11 -> V_77 |= V_82 ;
if ( V_83 )
V_11 -> V_77 |= V_84 ;
if ( ( V_63 = F_36 ( V_11 ) ) )
goto V_80;
if ( V_14 -> V_32 ) {
V_63 = F_37 ( V_11 , V_85 , ( T_3 )
V_11 -> V_47 [ 1 ] -> V_48 & 0xff ) ;
if ( V_63 )
goto V_80;
V_63 = F_37 ( V_11 , V_86 ,
( V_11 -> V_47 [ 1 ] -> V_48 >> 8 ) & 0xff ) ;
if ( V_63 )
goto V_80;
V_11 -> V_47 [ 2 ] -> V_51 = V_87 | V_88 |
V_89 ;
V_11 -> V_47 [ 2 ] -> V_48 = V_11 -> V_47 [ 2 ] -> V_50 = 0 ;
if ( ( V_63 = F_38 ( V_11 , V_11 -> V_47 [ 2 ] , 0 ) ) )
goto V_80;
V_14 -> V_64 = F_39 ( V_11 -> V_47 [ 2 ] -> V_48 , 0x1000 ) + 0x0800 ;
if ( ( V_63 = F_40 ( V_11 , V_11 -> V_47 [ 2 ] , 0 ) ) )
goto V_80;
F_41 ( 0x47 , V_14 -> V_64 + V_90 ) ;
V_1 = V_11 -> V_47 [ 0 ] -> V_48 ;
F_41 ( V_1 & 0xff , V_14 -> V_64 + V_85 ) ;
F_41 ( ( V_1 >> 8 ) & 0xff , V_14 -> V_64 + V_86 ) ;
#if 0
{
u_char tmp;
pr_info("ECOR:");
for (i=0; i < 7; i++) {
tmp = readb(local->dingo_ccr + i*2);
pr_cont(" %02x", tmp);
}
pr_cont("\n");
pr_info("DCOR:");
for (i=0; i < 4; i++) {
tmp = readb(local->dingo_ccr + 0x20 + i*2);
pr_cont(" %02x", tmp);
}
pr_cont("\n");
pr_info("SCOR:");
for (i=0; i < 10; i++) {
tmp = readb(local->dingo_ccr + 0x40 + i*2);
pr_cont(" %02x", tmp);
}
pr_cont("\n");
}
#endif
F_41 ( 0x01 , V_14 -> V_64 + 0x20 ) ;
F_41 ( 0x0c , V_14 -> V_64 + 0x22 ) ;
F_41 ( 0x00 , V_14 -> V_64 + 0x24 ) ;
F_41 ( 0x00 , V_14 -> V_64 + 0x26 ) ;
F_41 ( 0x00 , V_14 -> V_64 + 0x28 ) ;
}
V_14 -> V_91 = 0 ;
if ( ! V_92 ) {
V_14 -> V_91 = V_13 -> V_92 = 1 ;
} else if ( ( V_92 >= 1 && V_92 <= 2 ) ||
( V_14 -> V_31 && V_92 == 4 ) )
V_13 -> V_92 = V_92 ;
else
F_25 ( L_22 ) ;
V_13 -> V_93 = V_11 -> V_93 ;
V_13 -> V_94 = V_11 -> V_47 [ 0 ] -> V_48 ;
if ( V_14 -> V_32 )
F_42 ( V_13 , 1 ) ;
F_43 ( V_13 , & V_11 -> V_13 ) ;
if ( ( V_63 = F_44 ( V_13 ) ) ) {
F_25 ( L_23 ) ;
goto V_80;
}
F_45 ( V_13 , L_24 ,
V_14 -> V_69 , ( V_95 ) V_13 -> V_94 , ( int ) V_13 -> V_93 ,
V_13 -> V_62 ) ;
return 0 ;
V_80:
F_20 ( V_11 ) ;
return - V_49 ;
V_66:
return - V_49 ;
}
static void
F_20 ( struct V_10 * V_11 )
{
F_13 ( & V_11 -> V_13 , L_25 ) ;
if ( V_11 -> V_47 [ 2 ] -> V_50 ) {
struct V_12 * V_13 = V_11 -> V_17 ;
T_2 * V_14 = F_15 ( V_13 ) ;
if ( V_14 -> V_32 )
F_46 ( V_14 -> V_64 - 0x0800 ) ;
}
F_47 ( V_11 ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_17 ;
if ( V_11 -> V_96 ) {
F_49 ( V_13 ) ;
F_50 ( V_13 ) ;
}
return 0 ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_17 ;
if ( V_11 -> V_96 ) {
F_42 ( V_13 , 1 ) ;
F_52 ( V_13 ) ;
}
return 0 ;
}
static T_7
V_81 ( int V_93 , void * V_97 )
{
struct V_12 * V_13 = (struct V_12 * ) V_97 ;
T_2 * V_98 = F_15 ( V_13 ) ;
unsigned int V_1 ;
T_1 V_99 ;
unsigned V_100 ;
unsigned V_101 , V_102 , V_103 , V_104 ;
unsigned V_105 , V_106 ;
T_8 V_107 = V_108 ;
if ( ! F_53 ( V_13 ) )
return V_109 ;
V_1 = V_13 -> V_94 ;
if ( V_98 -> V_31 ) {
F_2 ( V_110 , 0 ) ;
}
F_54 ( L_26 , V_13 -> V_111 , V_93 , V_1 ) ;
V_99 = F_7 ( V_112 ) ;
V_101 = F_7 ( V_113 ) ;
V_100 = 0 ;
V_114:
if ( V_101 == 0xff ) {
F_54 ( L_27 , V_13 -> V_111 , V_93 ) ;
goto V_115;
}
V_102 = F_7 ( V_116 ) ;
F_10 ( 0x40 ) ;
V_103 = F_7 ( V_117 ) ;
F_2 ( V_117 , ( ~ V_103 & 0xff ) ) ;
V_104 = F_7 ( V_118 ) ;
V_104 |= F_7 ( V_119 ) << 8 ;
F_2 ( V_118 , 0 ) ;
F_2 ( V_119 , 0 ) ;
F_54 ( L_28 ,
V_13 -> V_111 , V_101 , V_102 , V_103 , V_104 ) ;
F_10 ( 0 ) ;
while ( V_102 & V_120 ) {
V_105 = F_7 ( V_121 ) ;
if ( V_100 > V_122 && ( V_105 & V_123 ) ) {
V_13 -> V_124 . V_125 ++ ;
F_54 ( L_29 , V_13 -> V_111 ) ;
} else if ( V_105 & V_123 ) {
struct V_126 * V_127 ;
V_106 = F_55 ( V_128 ) ;
V_100 += V_106 ;
F_54 ( L_30 , V_105 , V_106 ) ;
V_127 = F_56 ( V_106 + 3 ) ;
if ( ! V_127 ) {
F_25 ( L_31 , V_106 ) ;
V_13 -> V_124 . V_125 ++ ;
} else {
F_57 ( V_127 , 2 ) ;
if ( V_98 -> V_129 == 0 ) {
unsigned V_130 ;
F_10 ( 5 ) ;
V_130 = F_55 ( V_131 ) ;
F_10 ( 0 ) ;
V_130 += 3 ;
if ( V_130 >= 0x8000 )
V_130 = 0 ;
if ( V_130 + V_106 > 0x8000 ) {
unsigned V_9 ;
T_1 * V_26 = F_58 ( V_127 , V_106 ) ;
for ( V_9 = 0 ; V_9 < V_106 ; V_9 ++ , V_130 ++ ) {
V_26 [ V_9 ] = F_7 ( V_132 ) ;
if ( V_130 == 0x8000 ) {
V_130 = 0 ;
V_9 -- ;
}
}
} else {
F_59 ( V_1 + V_132 ,
F_58 ( V_127 , V_106 ) , ( V_106 + 1 ) >> 1 ) ;
}
}
#if 0
else if (lp->mohawk) {
unsigned i;
u_long *p = skb_put(skb, pktlen);
register u_long a;
unsigned int edpreg = ioaddr+XIRCREG_EDP-2;
for (i=0; i < len ; i += 4, p++) {
a = inl(edpreg);
__asm__("rorl $16,%0\n\t"
:"=q" (a)
: "0" (a));
*p = a;
}
}
#endif
else {
F_59 ( V_1 + V_132 , F_58 ( V_127 , V_106 ) ,
( V_106 + 1 ) >> 1 ) ;
}
V_127 -> V_133 = F_60 ( V_127 , V_13 ) ;
F_61 ( V_127 ) ;
V_13 -> V_124 . V_134 ++ ;
V_13 -> V_124 . V_135 += V_106 ;
if ( ! ( V_105 & V_136 ) )
V_13 -> V_124 . V_137 ++ ;
}
} else {
F_54 ( L_32 , V_105 ) ;
}
if ( V_105 & V_138 ) {
V_13 -> V_124 . V_139 ++ ;
F_54 ( L_33 , V_13 -> V_111 ) ;
}
if ( V_105 & V_140 ) {
V_13 -> V_124 . V_141 ++ ;
F_54 ( L_34 , V_13 -> V_111 ) ;
}
if ( V_105 & V_142 ) {
V_13 -> V_124 . V_143 ++ ;
F_54 ( L_35 , V_13 -> V_111 ) ;
}
F_5 ( V_144 , 0x8000 ) ;
V_102 = F_7 ( V_116 ) ;
}
if ( V_103 & 0x10 ) {
V_13 -> V_124 . V_145 ++ ;
F_2 ( V_110 , V_146 ) ;
F_54 ( L_36 ) ;
}
if ( V_101 & V_147 ) {
unsigned V_148 , V_149 ;
V_148 = V_98 -> V_150 ;
V_149 = F_7 ( V_151 ) ;
V_98 -> V_150 = V_149 ;
if ( V_149 < V_148 )
V_13 -> V_124 . V_152 += 256 - V_148 ;
else if ( V_148 == V_149 ) {
F_54 ( L_37 ) ;
} else
V_13 -> V_124 . V_152 += V_98 -> V_150 - V_148 ;
F_62 ( V_13 ) ;
}
if ( V_104 & 0x0002 ) {
F_54 ( L_38 ) ;
F_2 ( V_110 , V_153 ) ;
}
if ( V_104 & 0x0040 )
V_13 -> V_124 . V_154 ++ ;
if ( V_100 > 1000 ) {
V_95 V_155 = V_108 - V_107 ;
if ( V_155 >= V_156 / 10 ) {
V_122 = ( V_100 * ( V_156 / 10 ) ) / V_155 ;
if ( V_122 < 2000 )
V_122 = 2000 ;
else if ( V_122 > 22000 )
V_122 = 22000 ;
F_54 ( L_39 ,
V_122 , V_100 , V_155 ) ;
} else if ( ! V_155 && V_122 < 22000 ) {
V_122 += 2000 ;
if ( V_122 > 22000 )
V_122 = 22000 ;
F_54 ( L_40 , V_122 ) ;
}
}
V_115:
if ( V_157 ) {
if ( V_101 != 0xff && ( V_101 = F_7 ( V_113 ) ) != 0 )
goto V_114;
}
F_10 ( V_99 ) ;
F_2 ( V_110 , V_158 ) ;
return V_109 ;
}
static void
V_25 ( struct V_159 * V_160 )
{
T_2 * V_14 =
F_63 ( V_160 , T_2 , V_24 ) ;
struct V_12 * V_13 = V_14 -> V_13 ;
F_42 ( V_13 , 1 ) ;
V_13 -> V_161 = V_108 ;
F_62 ( V_13 ) ;
}
static void
F_64 ( struct V_12 * V_13 )
{
T_2 * V_98 = F_15 ( V_13 ) ;
V_13 -> V_124 . V_162 ++ ;
F_65 ( V_13 , L_41 ) ;
F_66 ( & V_98 -> V_24 ) ;
}
static T_9
F_67 ( struct V_126 * V_127 , struct V_12 * V_13 )
{
T_2 * V_98 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_94 ;
int V_163 ;
unsigned V_164 ;
unsigned V_106 = V_127 -> V_5 ;
F_54 ( L_42 ,
V_127 , V_13 , V_106 ) ;
if ( V_106 < V_165 )
{
if ( F_68 ( V_127 , V_165 ) )
return V_166 ;
V_106 = V_165 ;
}
F_69 ( V_13 ) ;
F_10 ( 0 ) ;
F_5 ( V_167 , ( V_168 ) V_106 + 2 ) ;
V_164 = F_55 ( V_169 ) ;
V_163 = V_164 & 0x8000 ;
V_164 &= 0x7fff ;
V_163 = V_106 + 2 < V_164 ;
F_54 ( L_43 ,
V_13 -> V_111 , V_164 , V_163 ? L_44 : L_45 ) ;
if ( ! V_163 ) {
return V_170 ;
}
F_5 ( V_132 , ( V_168 ) V_106 ) ;
F_70 ( V_1 + V_132 , V_127 -> V_3 , V_106 >> 1 ) ;
if ( V_106 & 1 )
F_2 ( V_132 , V_127 -> V_3 [ V_106 - 1 ] ) ;
if ( V_98 -> V_31 )
F_2 ( V_110 , V_171 | V_158 ) ;
F_71 ( V_127 ) ;
V_13 -> V_124 . V_172 += V_106 ;
F_72 ( V_13 ) ;
return V_166 ;
}
static void F_73 ( struct V_173 * V_174 , char * V_175 )
{
unsigned int V_1 = V_174 -> V_1 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
if ( V_174 -> V_176 > 15 ) {
V_174 -> V_176 = 8 ;
V_174 -> V_177 ++ ;
F_10 ( V_174 -> V_177 ) ;
}
if ( V_174 -> V_31 )
F_2 ( V_174 -> V_176 ++ , V_175 [ 5 - V_9 ] ) ;
else
F_2 ( V_174 -> V_176 ++ , V_175 [ V_9 ] ) ;
}
}
static void F_74 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_94 ;
T_2 * V_98 = F_15 ( V_13 ) ;
struct V_178 * V_179 ;
struct V_173 V_174 ;
int V_9 ;
V_174 . V_176 = 15 + 1 ;
V_174 . V_177 = 0x50 - 1 ;
V_174 . V_31 = V_98 -> V_31 ;
V_174 . V_1 = V_1 ;
F_73 ( & V_174 , V_13 -> V_62 ) ;
V_9 = 0 ;
F_75 (ha, dev) {
if ( V_9 ++ == 9 )
break;
F_73 ( & V_174 , V_179 -> V_175 ) ;
}
while ( V_9 ++ < 9 )
F_73 ( & V_174 , V_13 -> V_62 ) ;
F_10 ( 0 ) ;
}
static void
F_76 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_94 ;
unsigned V_180 ;
F_10 ( 0x42 ) ;
V_180 = F_7 ( V_181 ) & 0xC0 ;
if ( V_13 -> V_51 & V_182 ) {
F_2 ( V_181 , V_180 | 0x06 ) ;
} else if ( F_77 ( V_13 ) > 9 || ( V_13 -> V_51 & V_183 ) ) {
F_2 ( V_181 , V_180 | 0x02 ) ;
} else if ( ! F_78 ( V_13 ) ) {
F_2 ( V_181 , V_180 | 0x01 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_184 , V_185 ) ;
F_74 ( V_13 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_184 , V_186 | V_187 ) ;
} else {
F_2 ( V_181 , V_180 | 0x00 ) ;
}
F_10 ( 0 ) ;
}
static int
F_79 ( struct V_12 * V_13 , struct V_188 * V_189 )
{
T_2 * V_14 = F_15 ( V_13 ) ;
F_54 ( L_46 , V_13 ) ;
if ( V_189 -> V_190 != 255 && V_189 -> V_190 != V_13 -> V_92 ) {
if ( V_189 -> V_190 > 4 )
return - V_60 ;
if ( ! V_189 -> V_190 ) {
V_14 -> V_91 = 1 ;
V_13 -> V_92 = 1 ;
} else {
V_14 -> V_91 = 0 ;
V_13 -> V_92 = V_189 -> V_190 ;
}
F_45 ( V_13 , L_47 , V_191 [ V_13 -> V_92 ] ) ;
F_42 ( V_13 , 1 ) ;
}
return 0 ;
}
static int
F_80 ( struct V_12 * V_13 )
{
T_2 * V_98 = F_15 ( V_13 ) ;
struct V_10 * V_11 = V_98 -> V_16 ;
F_13 ( & V_11 -> V_13 , L_48 , V_13 ) ;
if ( ! F_81 ( V_11 ) )
return - V_49 ;
V_11 -> V_96 ++ ;
F_72 ( V_13 ) ;
F_42 ( V_13 , 1 ) ;
return 0 ;
}
static void F_82 ( struct V_12 * V_13 ,
struct V_192 * V_193 )
{
strcpy ( V_193 -> V_194 , L_49 ) ;
sprintf ( V_193 -> V_195 , L_50 , V_13 -> V_94 ) ;
}
static int
F_83 ( struct V_12 * V_13 , struct V_196 * V_197 , int V_198 )
{
T_2 * V_14 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_94 ;
struct V_199 * V_3 = F_84 ( V_197 ) ;
F_54 ( L_51 ,
V_13 -> V_111 , V_197 -> V_200 . V_201 , V_198 ,
V_3 -> V_202 , V_3 -> V_203 , V_3 -> V_204 , V_3 -> V_205 ) ;
if ( ! V_14 -> V_31 )
return - V_206 ;
switch( V_198 ) {
case V_207 :
V_3 -> V_202 = 0 ;
case V_208 :
V_3 -> V_205 = F_9 ( V_1 , V_3 -> V_202 & 0x1f ,
V_3 -> V_203 & 0x1f ) ;
break;
case V_209 :
F_11 ( V_1 , V_3 -> V_202 & 0x1f , V_3 -> V_203 & 0x1f , V_3 -> V_204 ,
16 ) ;
break;
default:
return - V_206 ;
}
return 0 ;
}
static void
F_85 ( struct V_12 * V_13 )
{
T_2 * V_14 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_94 ;
F_10 ( 4 ) ;
F_3 ( 1 ) ;
F_2 ( V_210 , 0 ) ;
F_86 ( 40 ) ;
if ( V_14 -> V_31 )
F_2 ( V_210 , 1 ) ;
else
F_2 ( V_210 , 1 | 4 ) ;
F_86 ( 20 ) ;
}
static void
F_42 ( struct V_12 * V_13 , int V_211 )
{
T_2 * V_14 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_94 ;
unsigned V_180 ;
F_54 ( L_52 , V_13 ? V_13 -> V_111 : L_53 , V_13 , V_211 ) ;
F_85 ( V_13 ) ;
F_2 ( V_110 , V_212 ) ;
F_86 ( 20 ) ;
F_2 ( V_110 , 0 ) ;
F_86 ( 40 ) ;
if ( V_14 -> V_31 ) {
F_10 ( 4 ) ;
F_2 ( V_213 , 0x0e ) ;
}
F_86 ( 500 ) ;
V_14 -> V_150 = 0 ;
V_14 -> V_129 = V_14 -> V_31 ? ( F_7 ( V_214 ) & 0x70 ) >> 4
: ( F_7 ( V_214 ) & 0x30 ) >> 4 ;
if ( V_14 -> V_91 ) {
if ( ! V_14 -> V_31 ) {
F_10 ( 4 ) ;
F_2 ( V_213 , 4 ) ;
V_14 -> V_91 = 0 ;
}
} else if ( V_13 -> V_92 == 2 ) {
F_10 ( 0x42 ) ;
F_2 ( V_181 , 0xC0 ) ;
} else {
F_10 ( 0x42 ) ;
F_2 ( V_181 , 0x80 ) ;
}
F_86 ( 40 ) ;
#if 0
{
SelectPage(0);
value = GetByte(XIRCREG_ESR);
pr_debug("%s: ESR is: %#02x\n", dev->name, value);
}
#endif
F_10 ( 1 ) ;
F_2 ( V_215 , 0xff ) ;
F_2 ( V_216 , 1 ) ;
V_180 = F_7 ( V_217 ) ;
#if 0
if (local->mohawk)
value |= DisableLinkPulse;
PutByte(XIRCREG1_ECR, value);
#endif
F_54 ( L_54 , V_13 -> V_111 , V_180 ) ;
F_10 ( 0x42 ) ;
F_2 ( V_218 , 0x20 ) ;
if ( V_14 -> V_129 != 1 ) {
F_10 ( 2 ) ;
F_5 ( V_219 , 0x2000 ) ;
}
if ( V_211 )
F_74 ( V_13 ) ;
F_10 ( 0 ) ;
F_5 ( V_144 , 0x2000 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_220 , 0xff ) ;
F_2 ( V_221 , 0xff ) ;
F_2 ( V_222 , 0xb0 ) ;
F_2 ( V_117 , 0x00 ) ;
F_2 ( V_118 , 0x00 ) ;
F_2 ( V_119 , 0x00 ) ;
if ( V_211 && V_14 -> V_31 && F_87 ( V_13 ) ) {
if ( V_13 -> V_92 == 4 || V_14 -> V_32 || V_14 -> V_223 ) {
F_45 ( V_13 , L_55 ) ;
F_10 ( 2 ) ;
F_2 ( V_224 , F_7 ( V_224 ) | 0x08 ) ;
F_86 ( 20 ) ;
} else {
F_45 ( V_13 , L_56 ) ;
F_10 ( 0x42 ) ;
if ( V_13 -> V_92 == 2 )
F_2 ( V_181 , 0xC0 ) ;
else
F_2 ( V_181 , 0x80 ) ;
F_86 ( 40 ) ;
}
if ( V_225 )
F_2 ( V_217 , F_7 ( V_217 | V_226 ) ) ;
} else {
F_10 ( 0 ) ;
V_180 = F_7 ( V_116 ) ;
V_13 -> V_92 = ( V_180 & V_227 ) ? 1 : 2 ;
}
F_10 ( 2 ) ;
if ( V_13 -> V_92 == 1 || V_13 -> V_92 == 4 )
F_2 ( V_228 , 0x3b ) ;
else
F_2 ( V_228 , 0x3a ) ;
if ( V_14 -> V_32 )
F_2 ( 0x0b , 0x04 ) ;
if ( V_211 ) {
F_76 ( V_13 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_184 , V_186 | V_187 ) ;
}
F_10 ( 1 ) ;
F_2 ( V_215 , 0xff ) ;
F_3 ( 1 ) ;
F_10 ( 0 ) ;
F_2 ( V_110 , V_158 ) ;
if ( V_14 -> V_33 && ! V_14 -> V_32 ) {
if ( ! ( F_7 ( 0x10 ) & 0x01 ) )
F_2 ( 0x10 , 0x11 ) ;
}
if ( V_211 )
F_45 ( V_13 , L_57 ,
V_191 [ V_13 -> V_92 ] , V_14 -> V_129 ) ;
F_10 ( 0 ) ;
}
static int
F_87 ( struct V_12 * V_13 )
{
T_2 * V_14 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_94 ;
unsigned V_229 , V_230 , V_231 ;
int V_9 ;
if ( V_92 == 4 || V_92 == 1 ) {
V_13 -> V_92 = V_92 ;
V_14 -> V_91 = 0 ;
return 1 ;
}
V_230 = F_9 ( V_1 , 0 , 1 ) ;
if ( ( V_230 & 0xff00 ) != 0x7800 )
return 0 ;
V_14 -> V_223 = ( F_9 ( V_1 , 0 , 2 ) != 0xffff ) ;
if ( V_14 -> V_91 )
V_229 = 0x1000 ;
else if ( V_13 -> V_92 == 4 )
V_229 = 0x2000 ;
else
V_229 = 0x0000 ;
F_11 ( V_1 , 0 , 0 , V_229 , 16 ) ;
F_3 ( 100 ) ;
V_229 = F_9 ( V_1 , 0 , 0 ) ;
if ( V_229 & 0x0400 ) {
F_65 ( V_13 , L_58 ) ;
V_14 -> V_91 = 0 ;
return 0 ;
}
if ( V_14 -> V_91 ) {
for ( V_9 = 0 ; V_9 < 35 ; V_9 ++ ) {
F_86 ( 100 ) ;
V_230 = F_9 ( V_1 , 0 , 1 ) ;
if ( ( V_230 & 0x0020 ) && ( V_230 & 0x0004 ) )
break;
}
if ( ! ( V_230 & 0x0020 ) ) {
F_45 ( V_13 , L_59 ) ;
if ( ! V_14 -> V_223 ) {
V_229 = 0x0000 ;
F_11 ( V_1 , 0 , 0 , V_229 , 16 ) ;
F_3 ( 100 ) ;
F_10 ( 0 ) ;
V_13 -> V_92 = ( F_7 ( V_116 ) & V_227 ) ? 1 : 2 ;
}
} else {
V_231 = F_9 ( V_1 , 0 , 5 ) ;
F_45 ( V_13 , L_60 , V_231 ) ;
if ( V_231 & 0x0080 ) {
V_13 -> V_92 = 4 ;
} else
V_13 -> V_92 = 1 ;
}
}
return 1 ;
}
static void
F_50 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_94 ;
F_54 ( L_61 , V_13 ) ;
F_10 ( 4 ) ;
F_2 ( V_210 , 0 ) ;
F_10 ( 0 ) ;
}
static int
F_88 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_94 ;
T_2 * V_98 = F_15 ( V_13 ) ;
struct V_10 * V_11 = V_98 -> V_16 ;
F_13 ( & V_11 -> V_13 , L_62 , V_13 ) ;
if ( ! V_11 )
return - V_49 ;
F_69 ( V_13 ) ;
F_10 ( 0 ) ;
F_2 ( V_110 , 0 ) ;
F_10 ( 0x01 ) ;
F_2 ( V_215 , 0x00 ) ;
F_10 ( 4 ) ;
F_2 ( V_210 , 0 ) ;
F_10 ( 0 ) ;
V_11 -> V_96 -- ;
return 0 ;
}
static int T_10
F_89 ( void )
{
return F_90 ( & V_232 ) ;
}
static void T_11
F_91 ( void )
{
F_92 ( & V_232 ) ;
}
static int T_10 F_93 ( char * V_233 )
{
int V_234 [ 10 ] = { - 1 } ;
V_233 = F_94 ( V_233 , 9 , V_234 ) ;
#define F_95 ( T_12 , T_13 ) if (ints[0] >= Y && ints[Y] != -1) { X = ints[Y]; }
F_95 ( V_92 , 3 ) ;
F_95 ( V_225 , 4 ) ;
F_95 ( V_83 , 5 ) ;
F_95 ( V_157 , 6 ) ;
#undef F_95
return 1 ;
}
