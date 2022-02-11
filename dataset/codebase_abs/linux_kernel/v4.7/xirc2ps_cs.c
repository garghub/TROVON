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
F_64 ( V_13 ) ;
F_62 ( V_13 ) ;
}
static void
F_65 ( struct V_12 * V_13 )
{
struct V_14 * V_99 = F_15 ( V_13 ) ;
V_13 -> V_125 . V_162 ++ ;
F_66 ( V_13 , L_40 ) ;
F_67 ( & V_99 -> V_25 ) ;
}
static T_8
F_68 ( struct V_127 * V_128 , struct V_12 * V_13 )
{
struct V_14 * V_99 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
int V_163 ;
unsigned V_164 ;
unsigned V_107 = V_128 -> V_5 ;
F_54 ( L_41 ,
V_128 , V_13 , V_107 ) ;
if ( V_107 < V_165 )
{
if ( F_69 ( V_128 , V_165 ) )
return V_166 ;
V_107 = V_165 ;
}
F_70 ( V_13 ) ;
F_10 ( 0 ) ;
F_5 ( V_167 , ( V_168 ) V_107 + 2 ) ;
V_164 = F_55 ( V_169 ) ;
V_163 = V_164 & 0x8000 ;
V_164 &= 0x7fff ;
V_163 = V_107 + 2 < V_164 ;
F_54 ( L_42 ,
V_13 -> V_112 , V_164 , V_163 ? L_43 : L_44 ) ;
if ( ! V_163 ) {
return V_170 ;
}
F_5 ( V_133 , ( V_168 ) V_107 ) ;
F_71 ( V_1 + V_133 , V_128 -> V_3 , V_107 >> 1 ) ;
if ( V_107 & 1 )
F_2 ( V_133 , V_128 -> V_3 [ V_107 - 1 ] ) ;
if ( V_99 -> V_32 )
F_2 ( V_111 , V_171 | V_159 ) ;
F_72 ( V_128 ) ;
V_13 -> V_125 . V_172 += V_107 ;
F_73 ( V_13 ) ;
return V_166 ;
}
static void F_74 ( struct V_173 * V_174 , char * V_175 )
{
unsigned int V_1 = V_174 -> V_1 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
if ( V_174 -> V_176 > 15 ) {
V_174 -> V_176 = 8 ;
V_174 -> V_177 ++ ;
F_10 ( V_174 -> V_177 ) ;
}
if ( V_174 -> V_32 )
F_2 ( V_174 -> V_176 ++ , V_175 [ 5 - V_9 ] ) ;
else
F_2 ( V_174 -> V_176 ++ , V_175 [ V_9 ] ) ;
}
}
static void F_75 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
struct V_14 * V_99 = F_15 ( V_13 ) ;
struct V_178 * V_179 ;
struct V_173 V_174 ;
int V_9 ;
V_174 . V_176 = 15 + 1 ;
V_174 . V_177 = 0x50 - 1 ;
V_174 . V_32 = V_99 -> V_32 ;
V_174 . V_1 = V_1 ;
F_74 ( & V_174 , V_13 -> V_63 ) ;
V_9 = 0 ;
F_76 (ha, dev) {
if ( V_9 ++ == 9 )
break;
F_74 ( & V_174 , V_179 -> V_175 ) ;
}
while ( V_9 ++ < 9 )
F_74 ( & V_174 , V_13 -> V_63 ) ;
F_10 ( 0 ) ;
}
static void
F_77 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
unsigned V_180 ;
F_10 ( 0x42 ) ;
V_180 = F_7 ( V_181 ) & 0xC0 ;
if ( V_13 -> V_52 & V_182 ) {
F_2 ( V_181 , V_180 | 0x06 ) ;
} else if ( F_78 ( V_13 ) > 9 || ( V_13 -> V_52 & V_183 ) ) {
F_2 ( V_181 , V_180 | 0x02 ) ;
} else if ( ! F_79 ( V_13 ) ) {
F_2 ( V_181 , V_180 | 0x01 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_184 , V_185 ) ;
F_75 ( V_13 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_184 , V_186 | V_187 ) ;
} else {
F_2 ( V_181 , V_180 | 0x00 ) ;
}
F_10 ( 0 ) ;
}
static int
F_80 ( struct V_12 * V_13 , struct V_188 * V_189 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
F_54 ( L_45 , V_13 ) ;
if ( V_189 -> V_190 != 255 && V_189 -> V_190 != V_13 -> V_93 ) {
if ( V_189 -> V_190 > 4 )
return - V_61 ;
if ( ! V_189 -> V_190 ) {
V_15 -> V_92 = 1 ;
V_13 -> V_93 = 1 ;
} else {
V_15 -> V_92 = 0 ;
V_13 -> V_93 = V_189 -> V_190 ;
}
F_45 ( V_13 , L_46 , V_191 [ V_13 -> V_93 ] ) ;
F_42 ( V_13 , 1 ) ;
}
return 0 ;
}
static int
F_81 ( struct V_12 * V_13 )
{
struct V_14 * V_99 = F_15 ( V_13 ) ;
struct V_10 * V_11 = V_99 -> V_17 ;
F_13 ( & V_11 -> V_13 , L_47 , V_13 ) ;
if ( ! F_82 ( V_11 ) )
return - V_50 ;
V_11 -> V_97 ++ ;
F_73 ( V_13 ) ;
F_42 ( V_13 , 1 ) ;
return 0 ;
}
static void F_83 ( struct V_12 * V_13 ,
struct V_192 * V_193 )
{
F_84 ( V_193 -> V_194 , L_48 , sizeof( V_193 -> V_194 ) ) ;
snprintf ( V_193 -> V_195 , sizeof( V_193 -> V_195 ) , L_49 ,
V_13 -> V_95 ) ;
}
static int
F_85 ( struct V_12 * V_13 , struct V_196 * V_197 , int V_198 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
struct V_199 * V_3 = F_86 ( V_197 ) ;
F_54 ( L_50 ,
V_13 -> V_112 , V_197 -> V_200 . V_201 , V_198 ,
V_3 -> V_202 , V_3 -> V_203 , V_3 -> V_204 , V_3 -> V_205 ) ;
if ( ! V_15 -> V_32 )
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
F_87 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
F_10 ( 4 ) ;
F_3 ( 1 ) ;
F_2 ( V_210 , 0 ) ;
F_88 ( 40 ) ;
if ( V_15 -> V_32 )
F_2 ( V_210 , 1 ) ;
else
F_2 ( V_210 , 1 | 4 ) ;
F_88 ( 20 ) ;
}
static void
F_42 ( struct V_12 * V_13 , int V_211 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
unsigned V_180 ;
F_54 ( L_51 , V_13 ? V_13 -> V_112 : L_52 , V_13 , V_211 ) ;
F_87 ( V_13 ) ;
F_2 ( V_111 , V_212 ) ;
F_88 ( 20 ) ;
F_2 ( V_111 , 0 ) ;
F_88 ( 40 ) ;
if ( V_15 -> V_32 ) {
F_10 ( 4 ) ;
F_2 ( V_213 , 0x0e ) ;
}
F_88 ( 500 ) ;
V_15 -> V_151 = 0 ;
V_15 -> V_130 = V_15 -> V_32 ? ( F_7 ( V_214 ) & 0x70 ) >> 4
: ( F_7 ( V_214 ) & 0x30 ) >> 4 ;
if ( V_15 -> V_92 ) {
if ( ! V_15 -> V_32 ) {
F_10 ( 4 ) ;
F_2 ( V_213 , 4 ) ;
V_15 -> V_92 = 0 ;
}
} else if ( V_13 -> V_93 == 2 ) {
F_10 ( 0x42 ) ;
F_2 ( V_181 , 0xC0 ) ;
} else {
F_10 ( 0x42 ) ;
F_2 ( V_181 , 0x80 ) ;
}
F_88 ( 40 ) ;
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
F_54 ( L_53 , V_13 -> V_112 , V_180 ) ;
F_10 ( 0x42 ) ;
F_2 ( V_218 , 0x20 ) ;
if ( V_15 -> V_130 != 1 ) {
F_10 ( 2 ) ;
F_5 ( V_219 , 0x2000 ) ;
}
if ( V_211 )
F_75 ( V_13 ) ;
F_10 ( 0 ) ;
F_5 ( V_145 , 0x2000 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_220 , 0xff ) ;
F_2 ( V_221 , 0xff ) ;
F_2 ( V_222 , 0xb0 ) ;
F_2 ( V_118 , 0x00 ) ;
F_2 ( V_119 , 0x00 ) ;
F_2 ( V_120 , 0x00 ) ;
if ( V_211 && V_15 -> V_32 && F_89 ( V_13 ) ) {
if ( V_13 -> V_93 == 4 || V_15 -> V_33 || V_15 -> V_223 ) {
F_45 ( V_13 , L_54 ) ;
F_10 ( 2 ) ;
F_2 ( V_224 , F_7 ( V_224 ) | 0x08 ) ;
F_88 ( 20 ) ;
} else {
F_45 ( V_13 , L_55 ) ;
F_10 ( 0x42 ) ;
if ( V_13 -> V_93 == 2 )
F_2 ( V_181 , 0xC0 ) ;
else
F_2 ( V_181 , 0x80 ) ;
F_88 ( 40 ) ;
}
if ( V_225 )
F_2 ( V_217 , F_7 ( V_217 | V_226 ) ) ;
} else {
F_10 ( 0 ) ;
V_180 = F_7 ( V_117 ) ;
V_13 -> V_93 = ( V_180 & V_227 ) ? 1 : 2 ;
}
F_10 ( 2 ) ;
if ( V_13 -> V_93 == 1 || V_13 -> V_93 == 4 )
F_2 ( V_228 , 0x3b ) ;
else
F_2 ( V_228 , 0x3a ) ;
if ( V_15 -> V_33 )
F_2 ( 0x0b , 0x04 ) ;
if ( V_211 ) {
F_77 ( V_13 ) ;
F_10 ( 0x40 ) ;
F_2 ( V_184 , V_186 | V_187 ) ;
}
F_10 ( 1 ) ;
F_2 ( V_215 , 0xff ) ;
F_3 ( 1 ) ;
F_10 ( 0 ) ;
F_2 ( V_111 , V_159 ) ;
if ( V_15 -> V_34 && ! V_15 -> V_33 ) {
if ( ! ( F_7 ( 0x10 ) & 0x01 ) )
F_2 ( 0x10 , 0x11 ) ;
}
if ( V_211 )
F_45 ( V_13 , L_56 ,
V_191 [ V_13 -> V_93 ] , V_15 -> V_130 ) ;
F_10 ( 0 ) ;
}
static int
F_89 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_15 ( V_13 ) ;
unsigned int V_1 = V_13 -> V_95 ;
unsigned V_229 , V_230 , V_231 ;
int V_9 ;
if ( V_93 == 4 || V_93 == 1 ) {
V_13 -> V_93 = V_93 ;
V_15 -> V_92 = 0 ;
return 1 ;
}
V_230 = F_9 ( V_1 , 0 , 1 ) ;
if ( ( V_230 & 0xff00 ) != 0x7800 )
return 0 ;
V_15 -> V_223 = ( F_9 ( V_1 , 0 , 2 ) != 0xffff ) ;
if ( V_15 -> V_92 )
V_229 = 0x1000 ;
else if ( V_13 -> V_93 == 4 )
V_229 = 0x2000 ;
else
V_229 = 0x0000 ;
F_11 ( V_1 , 0 , 0 , V_229 , 16 ) ;
F_3 ( 100 ) ;
V_229 = F_9 ( V_1 , 0 , 0 ) ;
if ( V_229 & 0x0400 ) {
F_66 ( V_13 , L_57 ) ;
V_15 -> V_92 = 0 ;
return 0 ;
}
if ( V_15 -> V_92 ) {
for ( V_9 = 0 ; V_9 < 35 ; V_9 ++ ) {
F_88 ( 100 ) ;
V_230 = F_9 ( V_1 , 0 , 1 ) ;
if ( ( V_230 & 0x0020 ) && ( V_230 & 0x0004 ) )
break;
}
if ( ! ( V_230 & 0x0020 ) ) {
F_45 ( V_13 , L_58 ) ;
if ( ! V_15 -> V_223 ) {
V_229 = 0x0000 ;
F_11 ( V_1 , 0 , 0 , V_229 , 16 ) ;
F_3 ( 100 ) ;
F_10 ( 0 ) ;
V_13 -> V_93 = ( F_7 ( V_117 ) & V_227 ) ? 1 : 2 ;
}
} else {
V_231 = F_9 ( V_1 , 0 , 5 ) ;
F_45 ( V_13 , L_59 , V_231 ) ;
if ( V_231 & 0x0080 ) {
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
F_2 ( V_210 , 0 ) ;
F_10 ( 0 ) ;
}
static int
F_90 ( struct V_12 * V_13 )
{
unsigned int V_1 = V_13 -> V_95 ;
struct V_14 * V_99 = F_15 ( V_13 ) ;
struct V_10 * V_11 = V_99 -> V_17 ;
F_13 ( & V_11 -> V_13 , L_61 , V_13 ) ;
if ( ! V_11 )
return - V_50 ;
F_70 ( V_13 ) ;
F_10 ( 0 ) ;
F_2 ( V_111 , 0 ) ;
F_10 ( 0x01 ) ;
F_2 ( V_215 , 0x00 ) ;
F_10 ( 4 ) ;
F_2 ( V_210 , 0 ) ;
F_10 ( 0 ) ;
V_11 -> V_97 -- ;
return 0 ;
}
static int T_9 F_91 ( char * V_232 )
{
int V_233 [ 10 ] = { - 1 } ;
V_232 = F_92 ( V_232 , 9 , V_233 ) ;
#define F_93 ( T_10 , T_11 ) if (ints[0] >= Y && ints[Y] != -1) { X = ints[Y]; }
F_93 ( V_93 , 3 ) ;
F_93 ( V_225 , 4 ) ;
F_93 ( V_84 , 5 ) ;
F_93 ( V_158 , 6 ) ;
#undef F_93
return 1 ;
}
