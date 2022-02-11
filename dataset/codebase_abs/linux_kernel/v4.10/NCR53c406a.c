static T_1 int F_1 ( unsigned char * V_1 , unsigned int V_2 , unsigned char V_3 )
{
unsigned V_4 ;
unsigned long V_5 = 0 ;
F_2 ( F_3 ( L_1 , V_2 ) ) ;
if ( V_6 <= 3 ) {
if ( V_2 > 65536 )
V_2 = 65536 ;
V_4 = 65536 - ( ( ( unsigned ) V_1 ) & 0xFFFF ) ;
} else {
if ( V_2 > ( 65536 << 1 ) )
V_2 = ( 65536 << 1 ) ;
V_4 = ( 65536 << 1 ) - ( ( ( unsigned ) V_1 ) & 0x1FFFF ) ;
}
if ( V_2 > V_4 )
V_2 = V_4 ;
F_2 ( F_3 ( L_2 , V_2 ) ) ;
if ( ( V_2 & 1 ) || ( ( ( unsigned ) V_1 ) & 1 ) )
F_4 ( L_3 ) ;
V_5 = F_5 () ;
F_6 ( V_6 ) ;
F_7 ( V_6 ) ;
F_8 ( V_6 , ( long ) V_1 ) ;
F_9 ( V_6 , V_2 ) ;
F_10 ( V_6 , V_3 ) ;
F_11 ( V_6 ) ;
F_12 ( V_5 ) ;
return V_2 ;
}
static T_1 int F_13 ( unsigned char * V_7 , unsigned int V_2 )
{
return F_1 ( V_7 , V_2 , V_8 ) ;
}
static T_1 int F_14 ( unsigned char * V_7 , unsigned int V_2 )
{
return F_1 ( V_7 , V_2 , V_9 ) ;
}
static T_1 int F_15 ( void )
{
register int V_10 ;
unsigned long V_5 ;
V_5 = F_5 () ;
F_7 ( V_6 ) ;
V_10 = F_16 ( V_6 ) ;
F_12 ( V_5 ) ;
return V_10 ;
}
static T_1 int F_17 ( unsigned char * V_11 , unsigned int V_12 )
{
int V_13 ;
int V_14 ;
V_15 ;
while ( V_12 ) {
V_13 = F_18 ( V_16 ) ;
if ( V_13 & 0x80 )
return 0 ;
switch ( V_13 & 0x1e ) {
default:
case 0x10 :
V_14 = 0 ;
break;
case 0x0 :
V_14 = 1 ;
break;
case 0x8 :
V_14 = 42 ;
break;
case 0xc :
V_14 = 84 ;
break;
case 0xe :
V_14 = 128 ;
break;
}
if ( ( V_13 & 0x40 ) && V_14 == 0 ) {
return 0 ;
}
if ( V_14 ) {
if ( V_14 > V_12 )
V_14 = V_12 ;
if ( V_17 && V_14 > 3 ) {
F_19 ( V_18 , V_11 , V_14 >> 2 ) ;
V_11 += V_14 & 0xfc ;
V_12 -= V_14 & 0xfc ;
} else {
while ( V_14 -- ) {
* V_11 ++ = F_18 ( V_18 ) ;
V_12 -- ;
}
}
}
}
return 0 ;
}
static T_1 int F_20 ( unsigned char * V_11 , unsigned int V_12 )
{
int V_13 = 0 ;
int V_14 ;
V_15 ;
while ( V_12 && ! ( V_13 & 0x40 ) ) {
V_13 = F_18 ( V_16 ) ;
if ( V_13 & 0x80 )
return 0 ;
switch ( V_13 & 0x1e ) {
case 0x10 :
V_14 = 128 ;
break;
case 0x0 :
V_14 = 84 ;
break;
case 0x8 :
V_14 = 42 ;
break;
case 0xc :
V_14 = 1 ;
break;
default:
case 0xe :
V_14 = 0 ;
break;
}
if ( V_14 ) {
if ( V_14 > V_12 )
V_14 = V_12 ;
if ( V_17 && V_14 > 3 ) {
F_21 ( V_18 , V_11 , V_14 >> 2 ) ;
V_11 += V_14 & 0xfc ;
V_12 -= V_14 & 0xfc ;
} else {
while ( V_14 -- ) {
F_22 ( * V_11 ++ , V_18 ) ;
V_12 -- ;
}
}
}
}
return 0 ;
}
static int T_2 F_23 ( struct V_19 * V_20 )
{
int V_21 = 0 ;
struct V_22 * V_23 = NULL ;
#ifndef F_24
int V_13 ;
#endif
#if V_24
int V_25 , V_26 ;
V_27 = 0 ;
for ( V_25 = 0 ; V_25 < V_28 && ! V_27 ; V_25 ++ )
for ( V_26 = 0 ; ( V_26 < V_29 ) && ! V_27 ; V_26 ++ )
if ( ! memcmp ( ( void * ) V_30 [ V_25 ] + V_31 [ V_26 ] . V_32 , ( void * ) V_31 [ V_26 ] . V_33 , ( int ) V_31 [ V_26 ] . V_34 ) )
V_27 = V_30 [ V_25 ] ;
if ( ! V_27 ) {
F_3 ( L_4 ) ;
return 0 ;
}
F_25 (printk(L_5, (unsigned int) bios_base);
) ;
#endif
#ifdef F_24
if ( ! F_26 ( V_35 , 0x10 , L_6 ) )
V_35 = 0 ;
#else
if ( V_35 ) {
if ( ! F_26 ( V_35 , 0x10 , L_6 ) )
V_35 = 0 ;
} else {
for ( V_13 = 0 ; V_13 < V_36 && ! V_35 ; V_13 ++ ) {
if ( ! F_26 ( V_37 [ V_13 ] , 0x10 , L_6 ) ) {
F_25 ( F_3 ( L_7 , V_37 [ V_13 ] ) ) ;
} else {
F_2 ( F_3 ( L_8 , V_37 [ V_13 ] ) ) ;
F_22 ( V_38 , V_37 [ V_13 ] + 0x0d ) ;
if ( ( F_18 ( V_37 [ V_13 ] + 0x0e ) ^ F_18 ( V_37 [ V_13 ] + 0x0e ) ) == 7 && ( F_18 ( V_37 [ V_13 ] + 0x0e ) ^ F_18 ( V_37 [ V_13 ] + 0x0e ) ) == 7 && ( F_18 ( V_37 [ V_13 ] + 0x0e ) & 0xf8 ) == 0x58 ) {
V_35 = V_37 [ V_13 ] ;
F_2 ( F_3 ( L_9 ) ) ;
F_2 ( F_3 ( L_10 , V_35 ) ) ;
break;
}
F_27 ( V_37 [ V_13 ] , 0x10 ) ;
}
}
}
#endif
if ( ! V_35 ) {
F_3 ( L_11 ) ;
return 0 ;
}
F_25 ( F_3 ( L_12 ) ) ;
F_28 () ;
F_29 () ;
#ifndef F_30
if ( V_39 < 0 ) {
V_39 = F_31 () ;
if ( V_39 < 0 ) {
F_3 ( L_13 , V_39 ) ;
goto V_40;
}
}
#endif
F_25 ( F_3 ( L_14 , V_35 ) ) ;
V_21 = 1 ;
V_20 -> V_41 = L_6 ;
V_23 = F_32 ( V_20 , 0 ) ;
if ( ! V_23 ) {
F_3 ( L_15 ) ;
goto V_40;
}
if ( V_39 > 0 ) {
if ( F_33 ( V_39 , V_42 , 0 , L_6 , V_23 ) ) {
F_3 ( L_16 , V_39 ) ;
goto V_43;
}
V_20 -> V_44 = 1 ;
F_25 ( F_3 ( L_17 , V_39 ) ) ;
} else if ( V_39 == 0 ) {
V_20 -> V_44 = 0 ;
F_25 ( F_3 ( L_18 ) ) ;
F_3 ( L_19 ) ;
F_3 ( L_20 ) ;
#if V_45
F_3 ( L_21 ) ;
#endif
goto V_43;
} else {
F_25 ( F_3 ( L_22 ) ) ;
goto V_43;
}
#if V_45
V_6 = V_46 ;
if ( F_34 ( V_6 , L_6 ) != 0 ) {
F_3 ( L_23 , V_6 ) ;
goto V_47;
}
F_25 ( F_3 ( L_24 , V_6 ) ) ;
#endif
V_23 -> V_48 = V_39 ;
V_23 -> V_49 = V_35 ;
V_23 -> V_50 = 0x10 ;
#if V_45
V_23 -> V_51 = V_6 ;
#endif
#if V_45
sprintf ( V_52 , L_25 , V_35 , V_39 , V_6 ) ;
#else
sprintf ( V_52 , L_26 , V_35 , V_39 , V_17 ? L_27 : L_28 ) ;
#endif
return ( V_21 ) ;
#if V_45
V_47:
if ( V_39 )
F_35 ( V_39 , V_23 ) ;
#endif
V_43:
F_36 ( V_23 ) ;
V_40:
F_27 ( V_35 , 0x10 ) ;
return 0 ;
}
static int F_37 ( struct V_22 * V_53 )
{
if ( V_53 -> V_48 )
F_35 ( V_53 -> V_48 , NULL ) ;
#if V_45
if ( V_53 -> V_54 != 0xff )
F_38 ( V_53 -> V_54 ) ;
#endif
if ( V_53 -> V_49 && V_53 -> V_50 )
F_27 ( V_53 -> V_49 , V_53 -> V_50 ) ;
F_36 ( V_53 ) ;
return 0 ;
}
static int T_2 F_39 ( char * V_55 )
{
static T_3 V_56 = 0 ;
T_3 V_13 ;
int V_57 [ 4 ] ;
F_25 (printk(L_29);
) ;
if ( V_56 >= V_36 - 1 ) {
F_3 ( L_30 ) ;
return 0 ;
}
F_40 ( V_55 , 4 , V_57 ) ;
if ( V_57 [ 0 ] < 1 || V_57 [ 0 ] > 3 ) {
F_3 ( L_31 ) ;
F_3 ( L_32 ) ;
return 0 ;
}
for ( V_13 = 0 ; V_13 < V_36 && ! V_35 ; V_13 ++ )
if ( V_37 [ V_13 ] == V_57 [ 1 ] ) {
V_35 = V_57 [ 1 ] ;
F_25 (printk(L_33, port_base);
)
}
if ( ! V_35 ) {
F_3 ( L_34 , V_57 [ 1 ] ) ;
return 0 ;
}
if ( V_57 [ 0 ] > 1 ) {
if ( V_57 [ 2 ] == 0 ) {
V_39 = 0 ;
F_25 (printk(L_35, irq_level);
)
} else
for ( V_13 = 0 ; V_13 < V_58 && V_39 < 0 ; V_13 ++ )
if ( V_59 [ V_13 ] == V_57 [ 2 ] ) {
V_39 = V_57 [ 2 ] ;
F_25 (printk(L_35, port_base);
)
}
if ( V_39 < 0 )
F_3 ( L_36 , V_57 [ 2 ] ) ;
}
if ( V_57 [ 0 ] > 2 )
V_17 = V_57 [ 3 ] ;
F_25 (printk(L_37, port_base, irq_level, fast_pio);)
return 1 ;
}
static const char * F_41 ( struct V_22 * V_60 )
{
F_25 ( F_3 ( L_38 ) ) ;
return ( V_52 ) ;
}
static int F_42 ( T_4 * V_61 , void (* F_43) ( T_4 * ) )
{
int V_13 ;
F_2 ( F_3 ( L_39 ) ) ;
F_25 ( F_3 ( L_40 , V_61 -> V_62 [ 0 ] , V_61 -> V_63 , V_61 -> V_64 -> V_65 , ( V_66 ) V_61 -> V_64 -> V_67 , F_44 ( V_61 ) ) ) ;
#if 0
VDEB(for (i = 0; i < SCpnt->cmd_len; i++)
printk("cmd[%d]=%02x ", i, SCpnt->cmnd[i]));
VDEB(printk("\n"));
#endif
V_68 = V_61 ;
V_68 -> V_69 = F_43 ;
V_68 -> V_70 . V_71 = V_72 ;
V_68 -> V_70 . V_73 = 0 ;
V_68 -> V_70 . V_74 = 0 ;
V_75 ;
F_22 ( F_45 ( V_61 ) , V_76 ) ;
F_22 ( V_77 , V_78 ) ;
for ( V_13 = 0 ; V_13 < V_61 -> V_63 ; V_13 ++ ) {
F_22 ( V_61 -> V_62 [ V_13 ] , V_79 ) ;
}
F_22 ( V_80 , V_78 ) ;
F_46 ( 1 ) ;
return 0 ;
}
static int F_47 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
T_5 V_85 , int * V_86 )
{
int V_87 ;
F_25 ( F_3 ( L_41 ) ) ;
V_87 = V_85 ;
V_86 [ 0 ] = 64 ;
V_86 [ 1 ] = 32 ;
V_86 [ 2 ] = V_87 >> 11 ;
if ( V_86 [ 2 ] > 1024 ) {
V_86 [ 0 ] = 255 ;
V_86 [ 1 ] = 63 ;
V_86 [ 2 ] = V_87 / ( 255 * 63 ) ;
}
return 0 ;
}
static T_6 V_42 ( int V_88 , void * V_89 )
{
unsigned long V_5 ;
struct V_22 * V_84 = V_89 ;
F_48 ( V_84 -> V_90 , V_5 ) ;
F_49 ( V_89 ) ;
F_50 ( V_84 -> V_90 , V_5 ) ;
return V_91 ;
}
static void F_49 ( void * V_89 )
{
F_25 (unsigned char fifo_size;
)
F_25 (unsigned char seq_reg;
)
unsigned char V_92 , V_93 ;
#if V_94
unsigned char V_95 ;
struct V_96 * V_97 ;
int V_13 ;
#endif
F_2 ( F_3 ( L_42 ) ) ;
#if V_94
V_15 ;
V_95 = F_18 ( V_16 ) ;
#endif
V_75 ;
V_92 = F_18 ( V_98 ) ;
F_25 ( V_99 = F_18 ( V_100 ) ) ;
V_93 = F_18 ( V_101 ) ;
F_25 ( V_102 = F_18 ( V_103 ) & 0x1f ) ;
#if V_104
F_3 ( L_43 , V_92 , V_99 , V_93 , V_102 ) ;
#if ( V_45 )
F_3 ( L_44 ) ;
#else
F_3 ( L_45 , V_95 ) ;
#endif
#endif
if ( V_93 & 0x80 ) {
F_46 ( 3 ) ;
F_25 ( F_3 ( L_46 ) ) ;
V_68 -> V_70 . V_71 = V_105 ;
V_68 -> V_106 = V_107 << 16 ;
V_68 -> V_69 ( V_68 ) ;
return;
}
#if V_94
if ( V_95 & 0x80 ) {
F_3 ( L_47 ) ;
V_68 -> V_70 . V_71 = V_105 ;
V_68 -> V_106 = V_108 << 16 ;
V_68 -> V_69 ( V_68 ) ;
return;
}
#endif
if ( V_92 & 0x20 ) {
F_3 ( L_48 ) ;
V_68 -> V_70 . V_71 = V_105 ;
V_68 -> V_106 = V_109 << 16 ;
V_68 -> V_69 ( V_68 ) ;
return;
}
if ( V_92 & 0x40 ) {
F_3 ( L_49 ) ;
V_68 -> V_70 . V_71 = V_105 ;
V_68 -> V_106 = V_108 << 16 ;
V_68 -> V_69 ( V_68 ) ;
return;
}
if ( V_93 & 0x20 ) {
F_25 ( F_3 ( L_50 ) ) ;
if ( V_68 -> V_70 . V_71 != V_110 ) {
V_68 -> V_106 = V_111 << 16 ;
} else {
V_68 -> V_106 = ( V_68 -> V_70 . V_73 & 0xff )
| ( ( V_68 -> V_70 . V_74 & 0xff ) << 8 ) | ( V_112 << 16 ) ;
}
F_46 ( 0 ) ;
V_68 -> V_70 . V_71 = V_105 ;
V_68 -> V_69 ( V_68 ) ;
return;
}
switch ( V_92 & 0x07 ) {
case 0x00 :
if ( V_93 & 0x10 ) {
F_46 ( 5 ) ;
V_68 -> V_70 . V_71 = V_113 ;
F_2 ( F_3 ( L_51 ) ) ;
F_22 ( V_77 , V_78 ) ;
F_51 ( F_44 ( V_68 ) ) ;
#if V_45
F_13 ( F_52 ( V_68 ) ,
F_53 ( V_68 ) ) ;
#endif
F_22 ( V_114 | V_115 , V_78 ) ;
#if V_94
F_54 (current_SC, sg, scsi_sg_count(current_SC), i) {
F_20 ( F_55 ( V_97 ) , V_97 -> V_116 ) ;
}
V_75 ;
#endif
}
break;
case 0x01 :
if ( V_93 & 0x10 ) {
F_46 ( 6 ) ;
V_68 -> V_70 . V_71 = V_117 ;
F_2 ( F_3 ( L_52 ) ) ;
F_22 ( V_77 , V_78 ) ;
F_51 ( F_44 ( V_68 ) ) ;
#if V_45
F_14 ( F_52 ( V_68 ) ,
F_53 ( V_68 ) ) ;
#endif
F_22 ( V_114 | V_115 , V_78 ) ;
#if V_94
F_54 (current_SC, sg, scsi_sg_count(current_SC), i) {
F_17 ( F_55 ( V_97 ) , V_97 -> V_116 ) ;
}
V_75 ;
#endif
}
break;
case 0x02 :
V_68 -> V_70 . V_71 = V_72 ;
F_3 ( L_53 ) ;
break;
case 0x03 :
F_46 ( 7 ) ;
V_68 -> V_70 . V_71 = V_118 ;
F_2 ( F_3 ( L_54 ) ) ;
F_22 ( V_77 , V_78 ) ;
F_22 ( V_119 , V_78 ) ;
break;
case 0x04 :
case 0x05 :
F_3 ( L_55 ) ;
break;
case 0x06 :
F_25 ( F_3 ( L_56 ) ) ;
V_68 -> V_70 . V_71 = V_120 ;
F_22 ( V_121 , V_78 ) ;
F_22 ( V_122 , V_78 ) ;
break;
case 0x07 :
F_46 ( 4 ) ;
F_2 ( F_3 ( L_57 ) ) ;
V_68 -> V_70 . V_71 = V_110 ;
V_68 -> V_70 . V_73 = F_18 ( V_79 ) ;
V_68 -> V_70 . V_74 = F_18 ( V_79 ) ;
F_2 ( F_3 ( L_58 , F_18 ( V_103 ) & 0x1f ) ) ;
F_25 ( F_3 ( L_59 , V_68 -> V_70 . V_73 , V_68 -> V_70 . V_74 ) ) ;
if ( V_68 -> V_70 . V_74 == V_123 || V_68 -> V_70 . V_74 == V_124 ) {
F_22 ( V_121 , V_78 ) ;
F_25 ( F_3 ( L_60 ) ) ;
}
F_22 ( V_122 , V_78 ) ;
break;
}
}
static int F_31 ( void )
{
int V_125 , V_48 ;
unsigned long V_13 ;
F_18 ( V_101 ) ;
V_125 = F_56 () ;
V_75 ;
F_22 ( 0xff , V_78 ) ;
V_13 = V_126 + V_127 ;
while ( F_57 ( V_13 , V_126 ) && ! ( F_18 ( V_98 ) & 0x80 ) )
F_58 () ;
if ( F_59 ( V_13 , V_126 ) ) {
F_60 ( V_125 ) ;
return - 1 ;
}
V_48 = F_60 ( V_125 ) ;
F_22 ( V_128 , V_78 ) ;
F_22 ( V_129 , V_78 ) ;
F_29 () ;
return V_48 ;
}
static void F_29 ( void )
{
V_15 ;
#if V_45
F_22 ( 0x00 , V_16 ) ;
#else
F_22 ( 0x01 , V_16 ) ;
#endif
F_22 ( 0x00 , V_130 ) ;
F_22 ( V_131 , V_132 ) ;
F_22 ( V_133 , V_134 ) ;
F_22 ( V_135 , V_136 ) ;
F_22 ( V_137 , V_138 ) ;
F_22 ( 0x05 , V_139 ) ;
F_22 ( 0x9C , V_140 ) ;
F_22 ( 0x05 , V_141 ) ;
F_22 ( V_142 , V_143 ) ;
}
static void T_2 F_28 ( void )
{
V_144 = ( V_35 + 0x00 ) ;
V_145 = ( V_35 + 0x01 ) ;
V_79 = ( V_35 + 0x02 ) ;
V_78 = ( V_35 + 0x03 ) ;
V_98 = ( V_35 + 0x04 ) ;
V_76 = ( V_35 + 0x04 ) ;
V_101 = ( V_35 + 0x05 ) ;
V_140 = ( V_35 + 0x05 ) ;
V_100 = ( V_35 + 0x06 ) ;
V_141 = ( V_35 + 0x06 ) ;
V_103 = ( V_35 + 0x07 ) ;
V_143 = ( V_35 + 0x07 ) ;
V_138 = ( V_35 + 0x08 ) ;
V_139 = ( V_35 + 0x09 ) ;
V_136 = ( V_35 + 0x0B ) ;
V_134 = ( V_35 + 0x0C ) ;
V_132 = ( V_35 + 0x0D ) ;
V_146 = ( V_35 + 0x0E ) ;
V_18 = ( V_35 + 0x04 ) ;
V_16 = ( V_35 + 0x08 ) ;
V_130 = ( V_35 + 0x0B ) ;
V_147 = ( V_35 + 0x0D ) ;
}
