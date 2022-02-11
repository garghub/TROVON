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
struct V_14 * V_15 ;
F_13 ( & V_11 -> V_13 , L_1 ) ;
V_13 = F_14 ( sizeof( struct V_14 ) ) ;
if ( ! V_13 )
return - V_16 ;
V_15 = F_15 ( V_13 ) ;
V_15 -> V_13 = V_13 ;
V_15 -> V_17 = V_11 ;
V_11 -> V_18 = V_13 ;
V_11 -> V_19 = 1 ;
V_13 -> V_20 = & V_20 ;
V_13 -> V_21 = & V_22 ;
V_13 -> V_23 = V_24 ;
F_16 ( & V_15 -> V_25 , V_26 ) ;
return F_17 ( V_11 ) ;
}
static void
F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_18 ;
F_13 ( & V_11 -> V_13 , L_2 ) ;
F_19 ( V_13 ) ;
F_20 ( V_11 ) ;
F_21 ( V_13 ) ;
}
static int
F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_18 ;
struct V_14 * V_15 = F_15 ( V_13 ) ;
T_2 * V_27 ;
unsigned int V_28 , V_29 , V_30 ;
T_3 V_5 ;
V_5 = F_23 ( V_11 , V_31 , & V_27 ) ;
if ( V_5 < 5 ) {
F_24 ( & V_11 -> V_13 , L_3 ) ;
return 0 ;
}
V_28 = V_27 [ 2 ] ;
V_29 = V_27 [ 3 ] ;
V_30 = V_27 [ 4 ] ;
F_13 ( & V_11 -> V_13 , L_4 ,
V_28 , V_29 , V_30 ) ;
V_15 -> V_32 = 0 ;
V_15 -> V_33 = 0 ;
V_15 -> V_34 = 0 ;
V_15 -> V_35 = V_36 ;
if ( ! ( V_30 & 0x40 ) ) {
F_25 ( L_5 ) ;
return 0 ;
}
if ( ! ( V_29 & 0x01 ) ) {
F_25 ( L_6 ) ;
return 0 ;
}
if ( V_29 & 0x10 ) {
V_15 -> V_34 = 1 ;
switch( V_30 & 15 ) {
case 1 : V_15 -> V_35 = V_37 ; break;
case 2 : V_15 -> V_35 = V_38 ; break;
case 3 : V_15 -> V_35 = V_39 ; break;
case 4 : V_15 -> V_35 = V_40 ; break;
case 5 : V_15 -> V_35 = V_41 ;
V_15 -> V_32 = 1 ;
break;
case 6 :
case 7 :
V_15 -> V_35 = V_42 ;
V_15 -> V_32 = 1 ;
V_15 -> V_33 = 1 ;
break;
}
} else {
switch( V_30 & 15 ) {
case 1 : V_15 -> V_35 = F_26 ( V_11 ) ? V_43 : V_44 ;
break;
case 2 : V_15 -> V_35 = V_43 ; break;
case 3 : V_15 -> V_35 = V_45 ;
V_15 -> V_32 = 1 ;
break;
}
}
if ( V_15 -> V_35 == V_44 || V_15 -> V_35 == V_37 ) {
F_25 ( L_7 ) ;
return 0 ;
}
if ( V_15 -> V_35 == V_36 )
F_25 ( L_8 , V_29 , V_30 ) ;
return 1 ;
}
static int
F_26 ( struct V_10 * V_17 )
{
if ( V_17 -> V_46 [ 2 ] && strstr ( V_17 -> V_46 [ 2 ] , L_9 ) )
return 1 ;
return 0 ;
}
static int
F_27 ( struct V_10 * V_17 , void * V_47 )
{
unsigned int V_1 ;
if ( ( V_17 -> V_48 [ 0 ] -> V_49 & 0xf ) == 8 )
return - V_50 ;
V_17 -> V_48 [ 0 ] -> V_51 = 16 ;
V_17 -> V_48 [ 1 ] -> V_51 = 8 ;
V_17 -> V_48 [ 0 ] -> V_52 &= ~ V_53 ;
V_17 -> V_48 [ 0 ] -> V_52 |= V_54 ;
V_17 -> V_48 [ 1 ] -> V_52 &= ~ V_53 ;
V_17 -> V_48 [ 1 ] -> V_52 |= V_55 ;
V_17 -> V_56 = 10 ;
V_17 -> V_48 [ 1 ] -> V_49 = V_17 -> V_48 [ 0 ] -> V_49 ;
for ( V_1 = 0x300 ; V_1 < 0x400 ; V_1 += 0x10 ) {
V_17 -> V_48 [ 0 ] -> V_49 = V_1 ;
if ( ! F_28 ( V_17 ) )
return 0 ;
}
return - V_50 ;
}
static int
F_29 ( struct V_10 * V_17 , void * V_47 )
{
int * V_57 = V_47 ;
T_4 V_58 = V_17 -> V_48 [ 1 ] -> V_49 ;
V_58 += ( * V_57 ? ( V_17 -> V_19 & 0x20 ? - 24 : 8 )
: ( V_17 -> V_19 & 0x20 ? 8 : - 24 ) ) ;
if ( ( V_17 -> V_48 [ 0 ] -> V_49 & 0xf ) == 8 )
return - V_50 ;
V_17 -> V_48 [ 0 ] -> V_51 = 18 ;
V_17 -> V_48 [ 1 ] -> V_51 = 8 ;
V_17 -> V_48 [ 0 ] -> V_52 &= ~ V_53 ;
V_17 -> V_48 [ 0 ] -> V_52 |= V_54 ;
V_17 -> V_48 [ 1 ] -> V_52 &= ~ V_53 ;
V_17 -> V_48 [ 1 ] -> V_52 |= V_55 ;
V_17 -> V_56 = 10 ;
V_17 -> V_48 [ 1 ] -> V_49 = V_17 -> V_48 [ 0 ] -> V_49 ;
V_17 -> V_48 [ 0 ] -> V_49 = V_58 ;
return F_28 ( V_17 ) ;
}
static int F_30 ( struct V_10 * V_17 ,
T_5 * V_59 ,
void * V_18 )
{
struct V_12 * V_13 = V_18 ;
int V_9 ;
if ( V_59 -> V_60 != 13 )
return - V_61 ;
if ( ( V_59 -> V_62 [ 0 ] != 2 ) || ( V_59 -> V_62 [ 1 ] != 1 ) ||
( V_59 -> V_62 [ 2 ] != 6 ) )
return - V_61 ;
for ( V_9 = 2 ; V_9 < 6 ; V_9 ++ )
V_13 -> V_63 [ V_9 ] = V_59 -> V_62 [ V_9 + 2 ] ;
return 0 ;
}
static int
F_17 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_18 ;
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 ;
int V_64 ;
T_2 * V_27 ;
T_3 V_5 ;
V_15 -> V_65 = NULL ;
F_13 ( & V_11 -> V_13 , L_10 ) ;
if ( V_11 -> V_66 == 0 ) {
F_25 ( L_11 ) ;
goto V_67;
}
switch ( V_11 -> V_68 ) {
case V_69 :
V_15 -> V_70 = L_12 ;
break;
case V_71 :
V_15 -> V_70 = L_13 ;
break;
case V_72 :
case V_73 :
V_15 -> V_70 = L_14 ;
break;
case V_74 :
V_15 -> V_70 = L_15 ;
break;
case V_75 :
V_15 -> V_70 = L_16 ;
break;
default:
F_25 ( L_17 ,
( unsigned ) V_11 -> V_68 ) ;
goto V_67;
}
F_13 ( & V_11 -> V_13 , L_18 , V_15 -> V_70 ) ;
if ( ! F_22 ( V_11 ) ) {
F_25 ( L_19 ) ;
goto V_67;
}
V_64 = F_31 ( V_11 , V_13 ) ;
if ( V_64 ) {
V_5 = F_23 ( V_11 , 0x89 , & V_27 ) ;
if ( V_27 && V_5 == 8 ) {
if ( * V_27 == V_76 ) {
int V_9 ;
for ( V_9 = 2 ; V_9 < 6 ; V_9 ++ )
V_13 -> V_63 [ V_9 ] = V_27 [ V_9 + 2 ] ;
} else
V_64 = - 1 ;
}
F_32 ( V_27 ) ;
}
if ( V_64 )
V_64 = F_33 ( V_11 , V_77 , F_30 , V_13 ) ;
if ( V_64 ) {
F_25 ( L_20 ) ;
goto V_67;
}
if ( V_15 -> V_34 ) {
int V_57 ;
V_11 -> V_78 |= V_79 ;
if ( V_15 -> V_33 ) {
if ( ! F_34 ( V_11 , F_27 , NULL ) )
goto V_80;
} else {
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ )
if ( ! F_34 ( V_11 , F_29 ,
& V_57 ) )
goto V_80;
}
F_25 ( L_21 ) ;
} else {
V_11 -> V_56 = 10 ;
V_11 -> V_48 [ 0 ] -> V_51 = 16 ;
V_11 -> V_48 [ 0 ] -> V_52 |= V_54 ;
for ( V_1 = 0x300 ; V_1 < 0x400 ; V_1 += 0x10 ) {
V_11 -> V_48 [ 0 ] -> V_49 = V_1 ;
if ( ! ( V_64 = F_28 ( V_11 ) ) )
goto V_80;
}
V_11 -> V_48 [ 0 ] -> V_49 = 0 ;
if ( ( V_64 = F_28 ( V_11 ) ) )
goto V_81;
}
V_80:
if ( V_64 )
goto V_81;
if ( ( V_64 = F_35 ( V_11 , V_82 ) ) )
goto V_81;
V_11 -> V_78 |= V_83 ;
if ( V_84 )
V_11 -> V_78 |= V_85 ;
if ( ( V_64 = F_36 ( V_11 ) ) )
goto V_81;
if ( V_15 -> V_33 ) {
V_64 = F_37 ( V_11 , V_86 , ( T_2 )
V_11 -> V_48 [ 1 ] -> V_49 & 0xff ) ;
if ( V_64 )
goto V_81;
V_64 = F_37 ( V_11 , V_87 ,
( V_11 -> V_48 [ 1 ] -> V_49 >> 8 ) & 0xff ) ;
if ( V_64 )
goto V_81;
V_11 -> V_48 [ 2 ] -> V_52 = V_88 | V_89 |
V_90 ;
V_11 -> V_48 [ 2 ] -> V_49 = V_11 -> V_48 [ 2 ] -> V_51 = 0 ;
if ( ( V_64 = F_38 ( V_11 , V_11 -> V_48 [ 2 ] , 0 ) ) )
goto V_81;
V_15 -> V_65 = F_39 ( V_11 -> V_48 [ 2 ] -> V_49 , 0x1000 ) + 0x0800 ;
if ( ( V_64 = F_40 ( V_11 , V_11 -> V_48 [ 2 ] , 0 ) ) )
goto V_81;
F_41 ( 0x47 , V_15 -> V_65 + V_91 ) ;
V_1 = V_11 -> V_48 [ 0 ] -> V_49 ;
F_41 ( V_1 & 0xff , V_15 -> V_65 + V_86 ) ;
F_41 ( ( V_1 >> 8 ) & 0xff , V_15 -> V_65 + V_87 ) ;
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
F_41 ( 0x01 , V_15 -> V_65 + 0x20 ) ;
F_41 ( 0x0c , V_15 -> V_65 + 0x22 ) ;
F_41 ( 0x00 , V_15 -> V_65 + 0x24 ) ;
F_41 ( 0x00 , V_15 -> V_65 + 0x26 ) ;
F_41 ( 0x00 , V_15 -> V_65 + 0x28 ) ;
}
V_15 -> V_92 = 0 ;
if ( ! V_93 ) {
V_15 -> V_92 = V_13 -> V_93 = 1 ;
} else if ( ( V_93 >= 1 && V_93 <= 2 ) ||
( V_15 -> V_32 && V_93 == 4 ) )
V_13 -> V_93 = V_93 ;
else
F_25 ( L_22 ) ;
V_13 -> V_94 = V_11 -> V_94 ;
V_13 -> V_95 = V_11 -> V_48 [ 0 ] -> V_49 ;
if ( V_15 -> V_33 )
F_42 ( V_13 , 1 ) ;
F_43 ( V_13 , & V_11 -> V_13 ) ;
if ( ( V_64 = F_44 ( V_13 ) ) ) {
F_25 ( L_23 ) ;
goto V_81;
}
F_45 ( V_13 , L_24 ,
V_15 -> V_70 , ( V_96 ) V_13 -> V_95 , ( int ) V_13 -> V_94 ,
V_13 -> V_63 ) ;
return 0 ;
V_81:
F_20 ( V_11 ) ;
return - V_50 ;
V_67:
return - V_50 ;
}
static void
F_20 ( struct V_10 * V_11 )
{
F_13 ( & V_11 -> V_13 , L_25 ) ;
if ( V_11 -> V_48 [ 2 ] -> V_51 ) {
struct V_12 * V_13 = V_11 -> V_18 ;
struct V_14 * V_15 = F_15 ( V_13 ) ;
if ( V_15 -> V_33 )
F_46 ( V_15 -> V_65 - 0x0800 ) ;
}
F_47 ( V_11 ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_18 ;
if ( V_11 -> V_97 ) {
F_49 ( V_13 ) ;
F_50 ( V_13 ) ;
}
return 0 ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_18 ;
if ( V_11 -> V_97 ) {
F_42 ( V_13 , 1 ) ;
F_52 ( V_13 ) ;
}
return 0 ;
}
static T_6
V_82 ( int V_94 , void * V_98 )
{
struct V_12 * V_13 = (struct V_12 * ) V_98 ;
struct V_14 * V_99 = F_15 ( V_13 ) ;
unsigned int V_1 ;
T_1 V_100 ;
unsigned V_101 ;
unsigned V_102 , V_103 , V_104 , V_105 ;
unsigned V_106 , V_107 ;
T_7 V_108 = V_109 ;
if ( ! F_53 ( V_13 ) )
return V_110 ;
V_1 = V_13 -> V_95 ;
if ( V_99 -> V_32 ) {
F_2 ( V_111 , 0 ) ;
}
F_54 ( L_26 , V_13 -> V_112 , V_94 , V_1 ) ;
V_100 = F_7 ( V_113 ) ;
V_102 = F_7 ( V_114 ) ;
V_101 = 0 ;
V_115:
if ( V_102 == 0xff ) {
F_54 ( L_27 , V_13 -> V_112 , V_94 ) ;
goto V_116;
}
V_103 = F_7 ( V_117 ) ;
F_10 ( 0x40 ) ;
V_104 = F_7 ( V_118 ) ;
F_2 ( V_118 , ( ~ V_104 & 0xff ) ) ;
V_105 = F_7 ( V_119 ) ;
V_105 |= F_7 ( V_120 ) << 8 ;
F_2 ( V_119 , 0 ) ;
F_2 ( V_120 , 0 ) ;
F_54 ( L_28 ,
V_13 -> V_112 , V_102 , V_103 , V_104 , V_105 ) ;
F_10 ( 0 ) ;
while ( V_103 & V_121 ) {
V_106 = F_7 ( V_122 ) ;
if ( V_101 > V_123 && ( V_106 & V_124 ) ) {
V_13 -> V_125 . V_126 ++ ;
F_54 ( L_29 , V_13 -> V_112 ) ;
} else if ( V_106 & V_124 ) {
struct V_127 * V_128 ;
V_107 = F_55 ( V_129 ) ;
V_101 += V_107 ;
F_54 ( L_30 , V_106 , V_107 ) ;
V_128 = F_56 ( V_13 , V_107 + 3 ) ;
if ( ! V_128 ) {
V_13 -> V_125 . V_126 ++ ;
} else {
F_57 ( V_128 , 2 ) ;
if ( V_99 -> V_130 == 0 ) {
unsigned V_131 ;
F_10 ( 5 ) ;
V_131 = F_55 ( V_132 ) ;
F_10 ( 0 ) ;
V_131 += 3 ;
if ( V_131 >= 0x8000 )
V_131 = 0 ;
if ( V_131 + V_107 > 0x8000 ) {
unsigned V_9 ;
T_1 * V_27 = F_58 ( V_128 , V_107 ) ;
for ( V_9 = 0 ; V_9 < V_107 ; V_9 ++ , V_131 ++ ) {
V_27 [ V_9 ] = F_7 ( V_133 ) ;
if ( V_131 == 0x8000 ) {
V_131 = 0 ;
V_9 -- ;
}
}
} else {
F_59 ( V_1 + V_133 ,
F_58 ( V_128 , V_107 ) , ( V_107 + 1 ) >> 1 ) ;
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
F_59 ( V_1 + V_133 , F_58 ( V_128 , V_107 ) ,
( V_107 + 1 ) >> 1 ) ;
}
V_128 -> V_134 = F_60 ( V_128 , V_13 ) ;
F_61 ( V_128 ) ;
V_13 -> V_125 . V_135 ++ ;
V_13 -> V_125 . V_136 += V_107 ;
if ( ! ( V_106 & V_137 ) )
V_13 -> V_125 . V_138 ++ ;
}
} else {
F_54 ( L_31 , V_106 ) ;
}
if ( V_106 & V_139 ) {
V_13 -> V_125 . V_140 ++ ;
F_54 ( L_32 , V_13 -> V_112 ) ;
}
if ( V_106 & V_141 ) {
V_13 -> V_125 . V_142 ++ ;
F_54 ( L_33 , V_13 -> V_112 ) ;
}
if ( V_106 & V_143 ) {
V_13 -> V_125 . V_144 ++ ;
F_54 ( L_34 , V_13 -> V_112 ) ;
}
F_5 ( V_145 , 0x8000 ) ;
V_103 = F_7 ( V_117 ) ;
}
if ( V_104 & 0x10 ) {
V_13 -> V_125 . V_146 ++ ;
F_2 ( V_111 , V_147 ) ;
F_54 ( L_35 ) ;
}
if ( V_102 & V_148 ) {
unsigned V_149 , V_150 ;
V_149 = V_99 -> V_151 ;
V_150 = F_7 ( V_152 ) ;
V_99 -> V_151 = V_150 ;
if ( V_150 < V_149 )
V_13 -> V_125 . V_153 += 256 - V_149 ;
else if ( V_149 == V_150 ) {
F_54 ( L_36 ) ;
} else
V_13 -> V_125 . V_153 += V_99 -> V_151 - V_149 ;
F_62 ( V_13 ) ;
}
if ( V_105 & 0x0002 ) {
F_54 ( L_37 ) ;
F_2 ( V_111 , V_154 ) ;
}
if ( V_105 & 0x0040 )
V_13 -> V_125 . V_155 ++ ;
if ( V_101 > 1000 ) {
V_96 V_156 = V_109 - V_108 ;
if ( V_156 >= V_157 / 10 ) {
V_123 = ( V_101 * ( V_157 / 10 ) ) / V_156 ;
if ( V_123 < 2000 )
V_123 = 2000 ;
else if ( V_123 > 22000 )
V_123 = 22000 ;
F_54 ( L_38 ,
V_123 , V_101 , V_156 ) ;
} else if ( ! V_156 && V_123 < 22000 ) {
V_123 += 2000 ;
if ( V_123 > 22000 )
V_123 = 22000 ;
F_54 ( L_39 , V_123 ) ;
}
}
V_116:
if ( V_158 ) {
if ( V_102 != 0xff && ( V_102 = F_7 ( V_114 ) ) != 0 )
goto V_115;
}
F_10 ( V_100 ) ;
F_2 ( V_111 , V_159 ) ;
return V_110 ;
}
static void
V_26 ( struct V_160 * V_161 )
{
struct V_14 * V_15 =
F_63 ( V_161 , struct V_14 , V_25 ) ;
struct V_12 * V_13 = V_15 -> V_13 ;
F_42 ( V_13 , 1 ) ;
V_13 -> V_162 = V_109 ;
F_62 ( V_13 ) ;
}
static void
F_64 ( struct V_12 * V_13 )
{
struct V_14 * V_99 = F_15 ( V_13 ) ;
V_13 -> V_125 . V_163 ++ ;
F_65 ( V_13 , L_40 ) ;
F_66 ( & V_99 -> V_25 ) ;
}
static T_8
F_67 ( struct V_127 * V_128 , struct V_12 * V_13 )
{
struct V_14 * V_99 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
int V_164 ;
unsigned V_165 ;
unsigned V_107 = V_128 -> V_5 ;
F_54 ( L_41 ,
V_128 , V_13 , V_107 ) ;
if ( V_107 < V_166 )
{
if ( F_68 ( V_128 , V_166 ) )
return V_167 ;
V_107 = V_166 ;
}
F_69 ( V_13 ) ;
F_10 ( 0 ) ;
F_5 ( V_168 , ( V_169 ) V_107 + 2 ) ;
V_165 = F_55 ( V_170 ) ;
V_164 = V_165 & 0x8000 ;
V_165 &= 0x7fff ;
V_164 = V_107 + 2 < V_165 ;
F_54 ( L_42 ,
V_13 -> V_112 , V_165 , V_164 ? L_43 : L_44 ) ;
if ( ! V_164 ) {
return V_171 ;
}
F_5 ( V_133 , ( V_169 ) V_107 ) ;
F_70 ( V_1 + V_133 , V_128 -> V_3 , V_107 >> 1 ) ;
if ( V_107 & 1 )
F_2 ( V_133 , V_128 -> V_3 [ V_107 - 1 ] ) ;
if ( V_99 -> V_32 )
F_2 ( V_111 , V_172 | V_159 ) ;
F_71 ( V_128 ) ;
V_13 -> V_125 . V_173 += V_107 ;
F_72 ( V_13 ) ;
return V_167 ;
}
static void F_73 ( struct V_174 * V_175 , char * V_176 )
{
unsigned int V_1 = V_175 -> V_1 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
if ( V_175 -> V_177 > 15 ) {
V_175 -> V_177 = 8 ;
V_175 -> V_178 ++ ;
F_10 ( V_175 -> V_178 ) ;
}
if ( V_175 -> V_32 )
F_2 ( V_175 -> V_177 ++ , V_176 [ 5 - V_9 ] ) ;
else
F_2 ( V_175 -> V_177 ++ , V_176 [ V_9 ] ) ;
}
}
static void F_74 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
struct V_14 * V_99 = F_15 ( V_13 ) ;
struct V_179 * V_180 ;
struct V_174 V_175 ;
int V_9 ;
V_175 . V_177 = 15 + 1 ;
V_175 . V_178 = 0x50 - 1 ;
V_175 . V_32 = V_99 -> V_32 ;
V_175 . V_1 = V_1 ;
F_73 ( & V_175 , V_13 -> V_63 ) ;
V_9 = 0 ;
F_75 (ha, dev) {
if ( V_9 ++ == 9 )
break;
F_73 ( & V_175 , V_180 -> V_176 ) ;
}
while ( V_9 ++ < 9 )
F_73 ( & V_175 , V_13 -> V_63 ) ;
F_10 ( 0 ) ;
}
static void
F_76 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
unsigned V_181 ;
F_10 ( 0x42 ) ;
V_181 = F_7 ( V_182 ) & 0xC0 ;
if ( V_13 -> V_52 & V_183 ) {
F_2 ( V_182 , V_181 | 0x06 ) ;
} else if ( F_77 ( V_13 ) > 9 || ( V_13 -> V_52 & V_184 ) ) {
F_2 ( V_182 , V_181 | 0x02 ) ;
} else if ( ! F_78 ( V_13 ) ) {
F_2 ( V_182 , V_181 | 0x01 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_185 , V_186 ) ;
F_74 ( V_13 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_185 , V_187 | V_188 ) ;
} else {
F_2 ( V_182 , V_181 | 0x00 ) ;
}
F_10 ( 0 ) ;
}
static int
F_79 ( struct V_12 * V_13 , struct V_189 * V_190 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
F_54 ( L_45 , V_13 ) ;
if ( V_190 -> V_191 != 255 && V_190 -> V_191 != V_13 -> V_93 ) {
if ( V_190 -> V_191 > 4 )
return - V_61 ;
if ( ! V_190 -> V_191 ) {
V_15 -> V_92 = 1 ;
V_13 -> V_93 = 1 ;
} else {
V_15 -> V_92 = 0 ;
V_13 -> V_93 = V_190 -> V_191 ;
}
F_45 ( V_13 , L_46 , V_192 [ V_13 -> V_93 ] ) ;
F_42 ( V_13 , 1 ) ;
}
return 0 ;
}
static int
F_80 ( struct V_12 * V_13 )
{
struct V_14 * V_99 = F_15 ( V_13 ) ;
struct V_10 * V_11 = V_99 -> V_17 ;
F_13 ( & V_11 -> V_13 , L_47 , V_13 ) ;
if ( ! F_81 ( V_11 ) )
return - V_50 ;
V_11 -> V_97 ++ ;
F_72 ( V_13 ) ;
F_42 ( V_13 , 1 ) ;
return 0 ;
}
static void F_82 ( struct V_12 * V_13 ,
struct V_193 * V_194 )
{
F_83 ( V_194 -> V_195 , L_48 , sizeof( V_194 -> V_195 ) ) ;
snprintf ( V_194 -> V_196 , sizeof( V_194 -> V_196 ) , L_49 ,
V_13 -> V_95 ) ;
}
static int
F_84 ( struct V_12 * V_13 , struct V_197 * V_198 , int V_199 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
struct V_200 * V_3 = F_85 ( V_198 ) ;
F_54 ( L_50 ,
V_13 -> V_112 , V_198 -> V_201 . V_202 , V_199 ,
V_3 -> V_203 , V_3 -> V_204 , V_3 -> V_205 , V_3 -> V_206 ) ;
if ( ! V_15 -> V_32 )
return - V_207 ;
switch( V_199 ) {
case V_208 :
V_3 -> V_203 = 0 ;
case V_209 :
V_3 -> V_206 = F_9 ( V_1 , V_3 -> V_203 & 0x1f ,
V_3 -> V_204 & 0x1f ) ;
break;
case V_210 :
F_11 ( V_1 , V_3 -> V_203 & 0x1f , V_3 -> V_204 & 0x1f , V_3 -> V_205 ,
16 ) ;
break;
default:
return - V_207 ;
}
return 0 ;
}
static void
F_86 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
F_10 ( 4 ) ;
F_3 ( 1 ) ;
F_2 ( V_211 , 0 ) ;
F_87 ( 40 ) ;
if ( V_15 -> V_32 )
F_2 ( V_211 , 1 ) ;
else
F_2 ( V_211 , 1 | 4 ) ;
F_87 ( 20 ) ;
}
static void
F_42 ( struct V_12 * V_13 , int V_212 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
unsigned V_181 ;
F_54 ( L_51 , V_13 ? V_13 -> V_112 : L_52 , V_13 , V_212 ) ;
F_86 ( V_13 ) ;
F_2 ( V_111 , V_213 ) ;
F_87 ( 20 ) ;
F_2 ( V_111 , 0 ) ;
F_87 ( 40 ) ;
if ( V_15 -> V_32 ) {
F_10 ( 4 ) ;
F_2 ( V_214 , 0x0e ) ;
}
F_87 ( 500 ) ;
V_15 -> V_151 = 0 ;
V_15 -> V_130 = V_15 -> V_32 ? ( F_7 ( V_215 ) & 0x70 ) >> 4
: ( F_7 ( V_215 ) & 0x30 ) >> 4 ;
if ( V_15 -> V_92 ) {
if ( ! V_15 -> V_32 ) {
F_10 ( 4 ) ;
F_2 ( V_214 , 4 ) ;
V_15 -> V_92 = 0 ;
}
} else if ( V_13 -> V_93 == 2 ) {
F_10 ( 0x42 ) ;
F_2 ( V_182 , 0xC0 ) ;
} else {
F_10 ( 0x42 ) ;
F_2 ( V_182 , 0x80 ) ;
}
F_87 ( 40 ) ;
#if 0
{
SelectPage(0);
value = GetByte(XIRCREG_ESR);
pr_debug("%s: ESR is: %#02x\n", dev->name, value);
}
#endif
F_10 ( 1 ) ;
F_2 ( V_216 , 0xff ) ;
F_2 ( V_217 , 1 ) ;
V_181 = F_7 ( V_218 ) ;
#if 0
if (local->mohawk)
value |= DisableLinkPulse;
PutByte(XIRCREG1_ECR, value);
#endif
F_54 ( L_53 , V_13 -> V_112 , V_181 ) ;
F_10 ( 0x42 ) ;
F_2 ( V_219 , 0x20 ) ;
if ( V_15 -> V_130 != 1 ) {
F_10 ( 2 ) ;
F_5 ( V_220 , 0x2000 ) ;
}
if ( V_212 )
F_74 ( V_13 ) ;
F_10 ( 0 ) ;
F_5 ( V_145 , 0x2000 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_221 , 0xff ) ;
F_2 ( V_222 , 0xff ) ;
F_2 ( V_223 , 0xb0 ) ;
F_2 ( V_118 , 0x00 ) ;
F_2 ( V_119 , 0x00 ) ;
F_2 ( V_120 , 0x00 ) ;
if ( V_212 && V_15 -> V_32 && F_88 ( V_13 ) ) {
if ( V_13 -> V_93 == 4 || V_15 -> V_33 || V_15 -> V_224 ) {
F_45 ( V_13 , L_54 ) ;
F_10 ( 2 ) ;
F_2 ( V_225 , F_7 ( V_225 ) | 0x08 ) ;
F_87 ( 20 ) ;
} else {
F_45 ( V_13 , L_55 ) ;
F_10 ( 0x42 ) ;
if ( V_13 -> V_93 == 2 )
F_2 ( V_182 , 0xC0 ) ;
else
F_2 ( V_182 , 0x80 ) ;
F_87 ( 40 ) ;
}
if ( V_226 )
F_2 ( V_218 , F_7 ( V_218 | V_227 ) ) ;
} else {
F_10 ( 0 ) ;
V_181 = F_7 ( V_117 ) ;
V_13 -> V_93 = ( V_181 & V_228 ) ? 1 : 2 ;
}
F_10 ( 2 ) ;
if ( V_13 -> V_93 == 1 || V_13 -> V_93 == 4 )
F_2 ( V_229 , 0x3b ) ;
else
F_2 ( V_229 , 0x3a ) ;
if ( V_15 -> V_33 )
F_2 ( 0x0b , 0x04 ) ;
if ( V_212 ) {
F_76 ( V_13 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_185 , V_187 | V_188 ) ;
}
F_10 ( 1 ) ;
F_2 ( V_216 , 0xff ) ;
F_3 ( 1 ) ;
F_10 ( 0 ) ;
F_2 ( V_111 , V_159 ) ;
if ( V_15 -> V_34 && ! V_15 -> V_33 ) {
if ( ! ( F_7 ( 0x10 ) & 0x01 ) )
F_2 ( 0x10 , 0x11 ) ;
}
if ( V_212 )
F_45 ( V_13 , L_56 ,
V_192 [ V_13 -> V_93 ] , V_15 -> V_130 ) ;
F_10 ( 0 ) ;
}
static int
F_88 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
unsigned V_230 , V_231 , V_232 ;
int V_9 ;
if ( V_93 == 4 || V_93 == 1 ) {
V_13 -> V_93 = V_93 ;
V_15 -> V_92 = 0 ;
return 1 ;
}
V_231 = F_9 ( V_1 , 0 , 1 ) ;
if ( ( V_231 & 0xff00 ) != 0x7800 )
return 0 ;
V_15 -> V_224 = ( F_9 ( V_1 , 0 , 2 ) != 0xffff ) ;
if ( V_15 -> V_92 )
V_230 = 0x1000 ;
else if ( V_13 -> V_93 == 4 )
V_230 = 0x2000 ;
else
V_230 = 0x0000 ;
F_11 ( V_1 , 0 , 0 , V_230 , 16 ) ;
F_3 ( 100 ) ;
V_230 = F_9 ( V_1 , 0 , 0 ) ;
if ( V_230 & 0x0400 ) {
F_65 ( V_13 , L_57 ) ;
V_15 -> V_92 = 0 ;
return 0 ;
}
if ( V_15 -> V_92 ) {
for ( V_9 = 0 ; V_9 < 35 ; V_9 ++ ) {
F_87 ( 100 ) ;
V_231 = F_9 ( V_1 , 0 , 1 ) ;
if ( ( V_231 & 0x0020 ) && ( V_231 & 0x0004 ) )
break;
}
if ( ! ( V_231 & 0x0020 ) ) {
F_45 ( V_13 , L_58 ) ;
if ( ! V_15 -> V_224 ) {
V_230 = 0x0000 ;
F_11 ( V_1 , 0 , 0 , V_230 , 16 ) ;
F_3 ( 100 ) ;
F_10 ( 0 ) ;
V_13 -> V_93 = ( F_7 ( V_117 ) & V_228 ) ? 1 : 2 ;
}
} else {
V_232 = F_9 ( V_1 , 0 , 5 ) ;
F_45 ( V_13 , L_59 , V_232 ) ;
if ( V_232 & 0x0080 ) {
V_13 -> V_93 = 4 ;
} else
V_13 -> V_93 = 1 ;
}
}
return 1 ;
}
static void
F_50 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
F_54 ( L_60 , V_13 ) ;
F_10 ( 4 ) ;
F_2 ( V_211 , 0 ) ;
F_10 ( 0 ) ;
}
static int
F_89 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
struct V_14 * V_99 = F_15 ( V_13 ) ;
struct V_10 * V_11 = V_99 -> V_17 ;
F_13 ( & V_11 -> V_13 , L_61 , V_13 ) ;
if ( ! V_11 )
return - V_50 ;
F_69 ( V_13 ) ;
F_10 ( 0 ) ;
F_2 ( V_111 , 0 ) ;
F_10 ( 0x01 ) ;
F_2 ( V_216 , 0x00 ) ;
F_10 ( 4 ) ;
F_2 ( V_211 , 0 ) ;
F_10 ( 0 ) ;
V_11 -> V_97 -- ;
return 0 ;
}
static int T_9 F_90 ( char * V_233 )
{
int V_234 [ 10 ] = { - 1 } ;
V_233 = F_91 ( V_233 , 9 , V_234 ) ;
#define F_92 ( T_10 , T_11 ) if (ints[0] >= Y && ints[Y] != -1) { X = ints[Y]; }
F_92 ( V_93 , 3 ) ;
F_92 ( V_226 , 4 ) ;
F_92 ( V_84 , 5 ) ;
F_92 ( V_158 , 6 ) ;
#undef F_92
return 1 ;
}
