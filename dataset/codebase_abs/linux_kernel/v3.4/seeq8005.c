struct V_1 * T_1 F_1 ( int V_2 )
{
struct V_1 * V_3 = F_2 ( sizeof( struct V_4 ) ) ;
unsigned * V_5 ;
int V_6 = 0 ;
if ( ! V_3 )
return F_3 ( - V_7 ) ;
if ( V_2 >= 0 ) {
sprintf ( V_3 -> V_8 , L_1 , V_2 ) ;
F_4 ( V_3 ) ;
V_9 = V_3 -> V_10 ;
V_11 = V_3 -> V_11 ;
}
if ( V_9 > 0x1ff ) {
V_6 = F_5 ( V_3 , V_9 ) ;
} else if ( V_9 != 0 ) {
V_6 = - V_12 ;
} else {
for ( V_5 = V_13 ; * V_5 ; V_5 ++ ) {
if ( F_5 ( V_3 , * V_5 ) == 0 )
break;
}
if ( ! * V_5 )
V_6 = - V_7 ;
}
if ( V_6 )
goto V_14;
V_6 = F_6 ( V_3 ) ;
if ( V_6 )
goto V_15;
return V_3 ;
V_15:
F_7 ( V_3 -> V_10 , V_16 ) ;
V_14:
F_8 ( V_3 ) ;
return F_3 ( V_6 ) ;
}
static int T_1 F_5 ( struct V_1 * V_3 , int V_17 )
{
static unsigned V_18 ;
int V_19 , V_20 ;
unsigned char V_21 [ 32 ] ;
int V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
if ( ! F_9 ( V_17 , V_16 , L_2 ) )
return - V_7 ;
if ( V_28 > 1 )
F_10 ( L_3 , V_17 ) ;
V_24 = F_11 ( V_29 ) ;
if ( V_24 == 0xffff ) {
V_27 = - V_7 ;
goto V_14;
}
if ( ( V_24 & 0x1800 ) != 0x1800 ) {
if ( V_28 > 1 ) {
F_10 ( L_4 ) ;
F_10 ( L_5 , V_24 ) ;
}
V_27 = - V_7 ;
goto V_14;
}
V_26 = F_11 ( V_30 ) ;
if ( V_26 == 0xffff ) {
F_12 ( 0 , V_30 ) ;
if ( F_11 ( V_30 ) == 0xffff ) {
V_27 = - V_7 ;
goto V_14;
}
} else if ( ( V_26 & 0xff00 ) != 0xff00 ) {
if ( V_28 > 1 ) {
F_10 ( L_6 ) ;
F_10 ( L_5 , V_26 ) ;
}
V_27 = - V_7 ;
goto V_14;
}
V_23 = F_11 ( V_31 ) ;
V_22 = F_11 ( V_32 ) ;
V_25 = F_11 ( V_33 ) ;
if ( V_28 > 4 ) {
F_10 ( L_7 , V_24 ) ;
F_10 ( L_8 , V_22 ) ;
F_10 ( L_9 , V_23 ) ;
F_10 ( L_10 , V_26 ) ;
F_10 ( L_11 , V_25 ) ;
}
F_12 ( V_34 | V_35 , V_36 ) ;
F_12 ( 0 , V_33 ) ;
F_12 ( V_37 , V_32 ) ;
V_20 = 0 ;
for( V_19 = 0 ; V_19 < 32 ; V_19 ++ ) {
V_20 += V_21 [ V_19 ] = F_11 ( V_38 ) & 0xff ;
}
#if 0
if ( (j&0xff) != 0 ) {
if (net_debug>1) {
printk("seeq8005: prom sum error\n");
}
outw( old_stat, SEEQ_STATUS);
outw( old_dmaar, SEEQ_DMAAR);
outw( old_cfg1, SEEQ_CFG1);
retval = -ENODEV;
goto out;
}
#endif
F_12 ( V_39 , V_31 ) ;
F_13 ( 5 ) ;
F_12 ( V_35 , V_36 ) ;
if ( V_28 ) {
F_10 ( L_12 , V_20 ) ;
for( V_20 = 0 ; V_20 < 32 ; V_20 += 16 ) {
F_10 ( L_13 , V_20 ) ;
for( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
F_10 ( L_14 , V_21 [ V_20 | V_19 ] ) ;
}
F_10 ( L_15 ) ;
for( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
if ( ( V_21 [ V_20 | V_19 ] > 31 ) && ( V_21 [ V_20 | V_19 ] < 127 ) ) {
F_10 ( L_16 , V_21 [ V_20 | V_19 ] ) ;
} else {
F_10 ( L_15 ) ;
}
}
F_10 ( L_17 ) ;
}
}
#if 0
if (net_debug>1) {
printk("seeq8005: testing packet buffer ... ");
outw( SEEQCFG1_BUFFER_BUFFER, SEEQ_CFG1);
outw( SEEQCMD_FIFO_WRITE | SEEQCMD_SET_ALL_OFF, SEEQ_CMD);
outw( 0 , SEEQ_DMAAR);
for(i=0;i<32768;i++) {
outw(0x5a5a, SEEQ_BUFFER);
}
j=jiffies+HZ;
while ( ((inw(SEEQ_STATUS) & SEEQSTAT_FIFO_EMPTY) != SEEQSTAT_FIFO_EMPTY) && time_before(jiffies, j) )
mb();
outw( 0 , SEEQ_DMAAR);
while ( ((inw(SEEQ_STATUS) & SEEQSTAT_WINDOW_INT) != SEEQSTAT_WINDOW_INT) && time_before(jiffies, j+HZ))
mb();
if ( (inw(SEEQ_STATUS) & SEEQSTAT_WINDOW_INT) == SEEQSTAT_WINDOW_INT)
outw( SEEQCMD_WINDOW_INT_ACK | (inw(SEEQ_STATUS)& SEEQCMD_INT_MASK), SEEQ_CMD);
outw( SEEQCMD_FIFO_READ | SEEQCMD_SET_ALL_OFF, SEEQ_CMD);
j=0;
for(i=0;i<32768;i++) {
if (inw(SEEQ_BUFFER) != 0x5a5a)
j++;
}
if (j) {
printk("%i\n",j);
} else {
printk("ok.\n");
}
}
#endif
if ( V_28 && V_18 ++ == 0 )
F_10 ( V_40 ) ;
F_10 ( L_18 , V_3 -> V_8 , L_2 , V_17 ) ;
V_3 -> V_10 = V_17 ;
V_3 -> V_11 = V_11 ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
V_3 -> V_41 [ V_19 ] = V_21 [ V_19 + 6 ] ;
F_10 ( L_19 , V_3 -> V_41 ) ;
if ( V_3 -> V_11 == 0xff )
;
else if ( V_3 -> V_11 < 2 ) {
unsigned long V_42 = F_14 () ;
F_12 ( V_43 | V_44 | V_45 , V_36 ) ;
V_3 -> V_11 = F_15 ( V_42 ) ;
if ( V_28 >= 2 )
F_10 ( L_20 , V_3 -> V_11 ) ;
} else if ( V_3 -> V_11 == 2 )
V_3 -> V_11 = 9 ;
#if 0
{
int irqval = request_irq(dev->irq, seeq8005_interrupt, 0, "seeq8005", dev);
if (irqval) {
printk ("%s: unable to get IRQ %d (irqval=%d).\n", dev->name,
dev->irq, irqval);
retval = -EAGAIN;
goto out;
}
}
#endif
V_3 -> V_46 = & V_47 ;
V_3 -> V_48 = V_49 / 20 ;
V_3 -> V_50 &= ~ V_51 ;
return 0 ;
V_14:
F_7 ( V_17 , V_16 ) ;
return V_27 ;
}
static int F_16 ( struct V_1 * V_3 )
{
struct V_4 * V_52 = F_17 ( V_3 ) ;
{
int V_53 = F_18 ( V_3 -> V_11 , V_54 , 0 , L_2 , V_3 ) ;
if ( V_53 ) {
F_10 ( L_21 , V_3 -> V_8 ,
V_3 -> V_11 , V_53 ) ;
return - V_55 ;
}
}
F_19 ( V_3 , 1 ) ;
V_52 -> V_56 = V_57 ;
F_20 ( V_3 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_3 )
{
int V_17 = V_3 -> V_10 ;
F_10 ( V_58 L_22 , V_3 -> V_8 ,
F_22 ( V_3 ) ? L_23 : L_24 ) ;
F_19 ( V_3 , 1 ) ;
V_3 -> V_59 = V_57 ;
F_23 ( V_3 ) ;
}
static T_2 F_24 ( struct V_60 * V_61 ,
struct V_1 * V_3 )
{
short V_62 = V_61 -> V_63 ;
unsigned char * V_64 ;
if ( V_62 < V_65 ) {
if ( F_25 ( V_61 , V_65 ) )
return V_66 ;
V_62 = V_65 ;
}
V_64 = V_61 -> V_67 ;
F_26 ( V_3 ) ;
F_27 ( V_3 , V_64 , V_62 ) ;
V_3 -> V_68 . V_69 += V_62 ;
F_28 ( V_61 ) ;
return V_66 ;
}
inline void F_29 ( struct V_1 * V_3 )
{
int V_17 = V_3 -> V_10 ;
unsigned long V_70 ;
int V_71 ;
V_70 = V_57 + V_49 ;
while ( ( ( ( V_71 = F_11 ( V_29 ) ) & V_72 ) != V_72 ) && F_30 ( V_57 , V_70 ) )
F_31 () ;
if ( ( V_71 & V_72 ) == V_72 )
F_12 ( V_73 | ( V_71 & V_74 ) , V_36 ) ;
}
static T_3 V_54 ( int V_11 , void * V_75 )
{
struct V_1 * V_3 = V_75 ;
struct V_4 * V_52 ;
int V_17 , V_71 , V_76 = 0 ;
int V_77 = 0 ;
V_17 = V_3 -> V_10 ;
V_52 = F_17 ( V_3 ) ;
V_71 = F_11 ( V_29 ) ;
do {
if ( V_28 > 2 ) {
F_10 ( L_25 , V_3 -> V_8 , V_71 ) ;
}
if ( V_71 & V_72 ) {
V_77 = 1 ;
F_12 ( V_73 | ( V_71 & V_74 ) , V_36 ) ;
if ( V_28 ) {
F_10 ( L_26 , V_3 -> V_8 ) ;
}
}
if ( V_71 & V_78 ) {
V_77 = 1 ;
F_12 ( V_79 | ( V_71 & V_74 ) , V_36 ) ;
V_3 -> V_68 . V_80 ++ ;
F_23 ( V_3 ) ;
}
if ( V_71 & V_81 ) {
V_77 = 1 ;
F_32 ( V_3 ) ;
}
V_71 = F_11 ( V_29 ) ;
} while ( ( ++ V_76 < 10 ) && ( V_71 & V_82 ) ) ;
if( V_28 > 2 ) {
F_10 ( L_27 , V_3 -> V_8 ) ;
}
return F_33 ( V_77 ) ;
}
static void F_32 ( struct V_1 * V_3 )
{
struct V_4 * V_52 = F_17 ( V_3 ) ;
int V_76 = 10 ;
int V_83 ;
int V_17 = V_3 -> V_10 ;
do {
int V_84 ;
int V_85 ;
int V_19 ;
int V_71 ;
V_71 = F_11 ( V_29 ) ;
F_12 ( V_52 -> V_86 , V_33 ) ;
F_12 ( V_87 | V_88 | ( V_71 & V_74 ) , V_36 ) ;
F_29 ( V_3 ) ;
V_84 = F_34 ( F_11 ( V_38 ) ) ;
V_83 = F_11 ( V_38 ) ;
if ( V_28 > 2 ) {
F_10 ( L_28 , V_3 -> V_8 , V_52 -> V_86 , V_84 , V_83 ) ;
}
if ( ( V_84 == 0 ) || ( ( V_83 & V_89 ) == 0 ) ) {
return;
}
if ( ( V_83 & V_90 ) == 0 )
break;
if ( V_84 < V_52 -> V_86 ) {
V_85 = ( V_84 + 0x10000 - ( ( V_91 + 1 ) << 8 ) ) - V_52 -> V_86 - 4 ;
} else {
V_85 = V_84 - V_52 -> V_86 - 4 ;
}
if ( V_84 < ( ( V_91 + 1 ) << 8 ) ) {
F_10 ( L_29 , V_3 -> V_8 ) ;
F_19 ( V_3 , 1 ) ;
return;
}
V_52 -> V_86 = V_84 ;
if ( V_28 > 2 ) {
F_10 ( L_30 , V_3 -> V_8 , V_85 ) ;
}
if ( V_83 & V_92 ) {
V_3 -> V_68 . V_93 ++ ;
if ( V_83 & V_94 ) V_3 -> V_68 . V_95 ++ ;
if ( V_83 & V_96 ) V_3 -> V_68 . V_95 ++ ;
if ( V_83 & V_97 ) V_3 -> V_68 . V_98 ++ ;
if ( V_83 & V_99 ) V_3 -> V_68 . V_100 ++ ;
F_12 ( V_34 | V_101 | ( V_71 & V_74 ) , V_36 ) ;
F_12 ( ( V_52 -> V_86 & 0xff00 ) >> 8 , V_30 ) ;
} else {
struct V_60 * V_61 ;
unsigned char * V_64 ;
V_61 = F_35 ( V_3 , V_85 ) ;
if ( V_61 == NULL ) {
F_10 ( L_31 , V_3 -> V_8 ) ;
V_3 -> V_68 . V_102 ++ ;
break;
}
F_36 ( V_61 , 2 ) ;
V_64 = F_37 ( V_61 , V_85 ) ;
F_38 ( V_38 , V_64 , ( V_85 + 1 ) >> 1 ) ;
if ( V_28 > 2 ) {
char * V_103 = V_64 ;
F_10 ( L_32 , V_3 -> V_8 ) ;
for( V_19 = 0 ; V_19 < 14 ; V_19 ++ ) {
F_10 ( L_14 , * ( V_103 ++ ) & 0xff ) ;
}
F_10 ( L_17 ) ;
}
V_61 -> V_104 = F_39 ( V_61 , V_3 ) ;
F_40 ( V_61 ) ;
V_3 -> V_68 . V_105 ++ ;
V_3 -> V_68 . V_106 += V_85 ;
}
} while ( ( -- V_76 ) && ( V_83 & V_89 ) );
}
static int F_41 ( struct V_1 * V_3 )
{
struct V_4 * V_52 = F_17 ( V_3 ) ;
int V_17 = V_3 -> V_10 ;
V_52 -> V_56 = 0 ;
F_26 ( V_3 ) ;
F_12 ( V_35 , V_36 ) ;
F_42 ( V_3 -> V_11 , V_3 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_3 )
{
#if 0
int ioaddr = dev->base_addr;
if (num_addrs) {
outw( (inw(SEEQ_CFG1) & ~SEEQCFG1_MATCH_MASK)| SEEQCFG1_MATCH_ALL, SEEQ_CFG1);
dev->flags|=IFF_PROMISC;
} else {
outw( (inw(SEEQ_CFG1) & ~SEEQCFG1_MATCH_MASK)| SEEQCFG1_MATCH_BROAD, SEEQ_CFG1);
}
#endif
}
void F_19 ( struct V_1 * V_3 , int V_107 )
{
struct V_4 * V_52 = F_17 ( V_3 ) ;
int V_17 = V_3 -> V_10 ;
int V_19 ;
F_12 ( V_39 , V_31 ) ;
F_13 ( 5 ) ;
F_12 ( V_34 | V_35 , V_36 ) ;
F_12 ( 0 , V_33 ) ;
F_12 ( V_108 , V_32 ) ;
for( V_19 = 0 ; V_19 < 6 ; V_19 ++ ) {
F_44 ( V_3 -> V_41 [ V_19 ] , V_38 ) ;
F_13 ( 2 ) ;
}
F_12 ( V_109 , V_32 ) ;
F_44 ( V_91 , V_38 ) ;
V_52 -> V_86 = ( V_91 + 1 ) << 8 ;
F_12 ( V_52 -> V_86 , V_110 ) ;
F_12 ( 0x00ff , V_30 ) ;
if ( V_28 > 4 ) {
F_10 ( L_33 , V_3 -> V_8 ) ;
F_12 ( V_87 | V_35 , V_36 ) ;
F_12 ( 0 , V_33 ) ;
F_12 ( V_108 , V_32 ) ;
for( V_19 = 0 ; V_19 < 6 ; V_19 ++ ) {
F_10 ( L_14 , F_45 ( V_38 ) ) ;
}
F_10 ( L_17 ) ;
}
F_12 ( V_111 | V_112 | V_113 , V_32 ) ;
F_12 ( V_114 | V_115 , V_31 ) ;
F_12 ( V_44 | V_116 | V_43 , V_36 ) ;
if ( V_28 > 4 ) {
int V_22 ;
V_22 = F_11 ( V_32 ) ;
F_10 ( L_34 , V_3 -> V_8 , F_11 ( V_29 ) ) ;
F_10 ( L_35 , V_3 -> V_8 , V_22 ) ;
F_10 ( L_36 , V_3 -> V_8 , F_11 ( V_31 ) ) ;
F_10 ( L_37 , V_3 -> V_8 , F_11 ( V_30 ) ) ;
F_10 ( L_38 , V_3 -> V_8 , F_11 ( V_33 ) ) ;
}
}
static void F_27 ( struct V_1 * V_3 , char * V_64 , int V_62 )
{
int V_17 = V_3 -> V_10 ;
int V_71 = F_11 ( V_29 ) ;
int V_117 = 0 ;
unsigned long V_70 ;
if ( V_28 > 4 ) {
F_10 ( L_39 , V_3 -> V_8 , V_62 ) ;
}
F_12 ( V_34 | ( V_71 & V_74 ) , V_36 ) ;
F_12 ( V_117 , V_33 ) ;
F_12 ( F_46 ( V_62 + 4 ) , V_38 ) ;
F_12 ( V_118 | V_119 | V_120 , V_38 ) ;
F_47 ( V_38 , V_64 , ( V_62 + 1 ) >> 1 ) ;
F_12 ( 0 , V_38 ) ;
F_12 ( 0 , V_38 ) ;
F_12 ( V_117 , V_121 ) ;
V_70 = V_57 ;
while ( ( ( ( V_71 = F_11 ( V_29 ) ) & V_122 ) == 0 ) && F_30 ( V_57 , V_70 + V_49 ) )
F_48 () ;
F_12 ( V_73 | V_123 | ( V_71 & V_74 ) , V_36 ) ;
}
int T_1 F_49 ( void )
{
V_124 = F_1 ( - 1 ) ;
if ( F_50 ( V_124 ) )
return F_51 ( V_124 ) ;
return 0 ;
}
void T_4 F_52 ( void )
{
F_53 ( V_124 ) ;
F_7 ( V_124 -> V_10 , V_16 ) ;
F_8 ( V_124 ) ;
}
