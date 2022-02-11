static void T_1 F_1 ( int V_1 , char * V_2 , int * V_3 )
{
static int V_4 = 0 ;
switch ( V_1 ) {
case V_5 :
if ( V_3 [ 0 ] != 2 && V_3 [ 0 ] != 3 ) {
F_2 ( V_6 L_1 F_3 ( V_7 ) L_2 ) ;
return;
}
break;
case V_8 :
if ( V_3 [ 0 ] != 2 ) {
F_2 ( V_6 L_3 F_3 ( V_7 ) L_4 ) ;
return;
}
break;
case V_9 :
if ( V_3 [ 0 ] != 2 ) {
F_2 ( V_6 L_5 F_3 ( V_7 ) L_4 ) ;
return;
}
break;
case V_10 :
if ( V_3 [ 0 ] != 2 ) {
F_2 ( L_6 F_3 ( V_7 ) L_4 ) ;
return;
}
break;
}
if ( V_4 < V_11 ) {
V_12 [ V_4 ] . V_7 = ( V_13 ) V_3 [ 1 ] ;
V_12 [ V_4 ] . V_14 = V_3 [ 2 ] ;
if ( V_3 [ 0 ] == 3 )
V_12 [ V_4 ] . V_15 = V_3 [ 3 ] ;
else
V_12 [ V_4 ] . V_15 = V_16 ;
V_12 [ V_4 ] . V_1 = V_1 ;
++ V_4 ;
}
}
static int T_1 F_4 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_5 , V_2 , V_3 ) ;
return 1 ;
}
static int T_1 F_7 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_8 , V_2 , V_3 ) ;
return 1 ;
}
static int T_1 F_8 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_9 , V_2 , V_3 ) ;
return 1 ;
}
static int T_1 F_9 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_10 , V_2 , V_3 ) ;
return 1 ;
}
int T_1 F_10 ( struct V_17 * V_18 )
{
static int V_19 = 0 ;
int V_20 ;
unsigned int * V_21 ;
#ifndef F_11
int V_22 ;
unsigned long V_23 = 16 ;
#endif
static unsigned int T_2 V_24 [] = {
0x280 , 0x290 , 0x300 , 0x310 , 0x330 , 0x340 , 0x348 , 0x350 , 0
} ;
static unsigned int T_2 V_25 [] = {
0x220 , 0x240 , 0x280 , 0x2a0 , 0x2c0 , 0x300 , 0x320 , 0x340 , 0
} ;
int V_26 = 0 ;
struct V_27 * V_28 ;
#ifdef F_11
unsigned long V_29 ;
void T_3 * V_30 ;
#endif
if ( V_31 != V_32 )
V_12 [ 0 ] . V_14 = V_31 ;
if ( V_33 != V_32 )
V_12 [ 0 ] . V_15 = V_33 ;
if ( V_34 != V_32 )
V_12 [ 0 ] . V_7 = ( V_13 ) V_34 ;
if ( V_35 != V_32 )
V_12 [ 0 ] . V_1 = V_5 ;
else if ( V_36 != V_32 )
V_12 [ 0 ] . V_1 = V_8 ;
else if ( V_37 != V_32 )
V_12 [ 0 ] . V_1 = V_9 ;
else if ( V_38 != V_32 )
V_12 [ 0 ] . V_1 = V_10 ;
#ifndef F_11
if ( ! V_19 && F_12 () ) {
struct V_39 * V_40 = NULL ;
V_20 = 0 ;
while ( ( V_40 = F_13 ( NULL , F_14 ( 'D' , 'T' , 'C' ) , F_15 ( 0x436e ) , V_40 ) ) ) {
if ( V_20 >= V_11 )
break;
if ( F_16 ( V_40 ) < 0 )
continue;
if ( F_17 ( V_40 ) < 0 ) {
F_2 ( V_6 L_7 ) ;
F_18 ( V_40 ) ;
continue;
}
if ( ! F_19 ( V_40 , 0 ) ) {
F_2 ( V_6 L_8 ) ;
F_18 ( V_40 ) ;
continue;
}
if ( F_20 ( V_40 , 0 ) )
V_12 [ V_20 ] . V_14 = F_21 ( V_40 , 0 ) ;
else
V_12 [ V_20 ] . V_14 = V_41 ;
if ( F_22 ( V_40 , 0 ) )
V_12 [ V_20 ] . V_15 = F_23 ( V_40 , 0 ) ;
else
V_12 [ V_20 ] . V_15 = V_16 ;
V_12 [ V_20 ] . V_7 = ( V_13 ) F_24 ( V_40 , 0 ) ;
V_12 [ V_20 ] . V_1 = V_10 ;
V_20 ++ ;
}
}
#endif
V_18 -> V_42 = L_9 ;
for ( V_20 = 0 ; V_19 < V_11 ; ++ V_19 ) {
if ( ! ( V_12 [ V_19 ] . V_7 ) )
continue;
V_21 = NULL ;
switch ( V_12 [ V_19 ] . V_1 ) {
case V_5 :
V_26 = V_43 ;
break;
case V_8 :
V_26 = V_44 ;
break;
case V_9 :
V_26 = V_43 ;
V_21 = V_24 ;
break;
case V_10 :
V_26 = V_43 | V_45 ;
V_21 = V_25 ;
break;
}
#ifndef F_11
if ( V_21 ) {
F_25 ( 0x59 , 0x779 ) ;
F_25 ( 0xb9 , 0x379 ) ;
F_25 ( 0xc5 , 0x379 ) ;
F_25 ( 0xae , 0x379 ) ;
F_25 ( 0xa6 , 0x379 ) ;
F_25 ( 0x00 , 0x379 ) ;
if ( V_12 [ V_19 ] . V_7 != V_46 )
for ( V_22 = 0 ; V_21 [ V_22 ] ; V_22 ++ ) {
if ( ! F_26 ( V_21 [ V_22 ] , 16 , L_10 ) )
continue;
if ( V_12 [ V_19 ] . V_7 == V_21 [ V_22 ] )
break;
F_27 ( V_21 [ V_22 ] , 16 ) ;
} else
for ( V_22 = 0 ; V_21 [ V_22 ] ; V_22 ++ ) {
if ( ! F_26 ( V_21 [ V_22 ] , 16 , L_10 ) )
continue;
if ( F_28 ( V_21 [ V_22 ] ) == 0xff )
break;
F_27 ( V_21 [ V_22 ] , 16 ) ;
}
if ( V_21 [ V_22 ] ) {
F_25 ( 0x59 , 0x779 ) ;
F_25 ( 0xb9 , 0x379 ) ;
F_25 ( 0xc5 , 0x379 ) ;
F_25 ( 0xae , 0x379 ) ;
F_25 ( 0xa6 , 0x379 ) ;
F_25 ( 0x80 | V_22 , 0x379 ) ;
F_25 ( 0xc0 , V_21 [ V_22 ] + 9 ) ;
if ( F_28 ( V_21 [ V_22 ] + 9 ) != 0x80 )
continue;
else
V_12 [ V_19 ] . V_7 = V_21 [ V_22 ] ;
} else
continue;
}
else
{
if( ! ( F_26 ( V_12 [ V_19 ] . V_7 , V_47 , L_11 ) ) )
continue;
V_23 = V_47 ;
}
#else
V_29 = V_12 [ V_19 ] . V_7 ;
if ( ! F_29 ( V_29 , V_47 , L_11 ) )
continue;
V_30 = F_30 ( V_29 , V_47 ) ;
if ( ! V_30 ) {
F_31 ( V_29 , V_47 ) ;
continue;
}
#endif
V_28 = F_32 ( V_18 , sizeof( struct V_48 ) ) ;
if ( V_28 == NULL ) {
#ifndef F_11
F_27 ( V_12 [ V_19 ] . V_7 , V_23 ) ;
#else
F_33 ( V_30 ) ;
F_31 ( V_29 , V_47 ) ;
#endif
continue;
}
V_28 -> V_49 = V_12 [ V_19 ] . V_7 ;
#ifndef F_11
V_28 -> V_50 = V_23 ;
#else
( (struct V_48 * ) V_28 -> V_51 ) -> V_30 = V_30 ;
#endif
F_34 ( V_28 , V_26 ) ;
if ( V_12 [ V_19 ] . V_14 != V_52 )
V_28 -> V_14 = V_12 [ V_19 ] . V_14 ;
else
V_28 -> V_14 = F_35 ( V_28 , 0xffff ) ;
if ( V_28 -> V_14 != V_41 )
if ( F_36 ( V_28 -> V_14 , V_53 ,
V_54 , L_12 , V_28 ) ) {
F_2 ( V_55 L_13 , V_28 -> V_56 , V_28 -> V_14 ) ;
V_28 -> V_14 = V_41 ;
}
if ( V_28 -> V_14 == V_41 ) {
F_2 ( V_57 L_14 , V_28 -> V_56 ) ;
F_2 ( V_57 L_15 , V_28 -> V_56 ) ;
}
F_2 ( V_57 L_16 F_3 ( V_7 ) L_17 , V_28 -> V_56 , ( unsigned int ) V_28 -> V_49 ) ;
if ( V_28 -> V_14 == V_41 )
F_2 ( L_18 ) ;
else
F_2 ( L_19 , V_28 -> V_14 ) ;
F_2 ( L_20 , V_58 , V_59 , V_60 ) ;
F_37 ( V_28 ) ;
F_2 ( L_21 ) ;
++ V_19 ;
++ V_20 ;
}
return V_20 ;
}
const char * F_38 ( struct V_27 * V_61 )
{
static const char string [] = L_22 ;
return string ;
}
int F_39 ( struct V_27 * V_28 )
{
F_40 () ;
F_41 ( V_28 ) ;
if ( V_28 -> V_14 != V_41 )
F_42 ( V_28 -> V_14 , V_28 ) ;
F_43 ( V_28 ) ;
#ifndef F_11
F_27 ( V_28 -> V_49 , V_28 -> V_50 ) ;
#else
F_33 ( ( (struct V_48 * ) V_28 -> V_51 ) -> V_30 ) ;
F_31 ( V_28 -> V_49 , V_47 ) ;
#endif
return 0 ;
}
static int
F_44 ( struct V_62 * V_63 , struct V_64 * V_65 ,
T_4 V_66 , int * V_67 )
{
V_67 [ 0 ] = 64 ;
V_67 [ 1 ] = 32 ;
V_67 [ 2 ] = V_66 >> 11 ;
return 0 ;
}
static inline int F_45 ( struct V_27 * V_28 , unsigned char * V_68 , int V_69 )
{
int V_70 = V_69 / 128 ;
int V_71 = 0 ;
int V_72 ;
F_40 () ;
F_41 ( V_28 ) ;
F_46 ( V_73 , V_74 | V_75 ) ;
F_46 ( V_76 , V_70 ) ;
while ( 1 ) {
if ( ( V_72 = F_47 ( V_76 ) ) == 0 ) {
break;
}
if ( F_47 ( V_73 ) & V_77 ) {
F_2 ( V_6 L_23 , V_71 , V_70 ) ;
return - 1 ;
}
while ( F_47 ( V_73 ) & V_78 ) ;
#ifndef F_11
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
V_68 [ V_71 + V_22 ] = F_47 ( V_79 ) ;
}
#else
F_48 ( V_68 + V_71 , V_30 + V_80 , 128 ) ;
#endif
V_71 += 128 ;
V_70 -- ;
}
if ( V_70 ) {
while ( F_47 ( V_73 ) & V_78 )
{
}
#ifndef F_11
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
V_68 [ V_71 + V_22 ] = F_47 ( V_79 ) ;
}
#else
F_48 ( V_68 + V_71 , V_30 + V_80 , 128 ) ;
#endif
V_71 += 128 ;
V_70 -- ;
}
if ( ! ( F_47 ( V_73 ) & V_77 ) )
F_2 ( L_24 ) ;
#if 0
printk("53C400r: Waiting for 53C80 registers\n");
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_53C80_REG)
;
#endif
if ( ! ( F_47 ( V_81 ) & V_82 ) )
F_2 ( V_6 L_25 ) ;
F_46 ( V_83 , V_84 ) ;
F_47 ( V_85 ) ;
return 0 ;
}
static inline int F_49 ( struct V_27 * V_28 , unsigned char * V_86 , int V_69 )
{
int V_70 = V_69 / 128 ;
int V_71 = 0 ;
int V_72 ;
int V_22 ;
F_40 () ;
F_41 ( V_28 ) ;
F_46 ( V_73 , V_74 ) ;
F_46 ( V_76 , V_70 ) ;
while ( 1 ) {
if ( F_47 ( V_73 ) & V_77 ) {
F_2 ( V_6 L_26 , V_71 , V_70 ) ;
return - 1 ;
}
if ( ( V_72 = F_47 ( V_76 ) ) == 0 ) {
break;
}
while ( F_47 ( V_73 ) & V_78 )
;
#ifndef F_11
{
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
F_46 ( V_79 , V_86 [ V_71 + V_22 ] ) ;
}
#else
F_50 ( V_30 + V_80 , V_86 + V_71 , 128 ) ;
#endif
V_71 += 128 ;
V_70 -- ;
}
if ( V_70 ) {
while ( F_47 ( V_73 ) & V_78 )
;
#ifndef F_11
{
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
F_46 ( V_79 , V_86 [ V_71 + V_22 ] ) ;
}
#else
F_50 ( V_30 + V_80 , V_86 + V_71 , 128 ) ;
#endif
V_71 += 128 ;
V_70 -- ;
}
#if 0
printk("53C400w: waiting for registers to be available\n");
THEY NEVER DO ! while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_53C80_REG);
printk("53C400w: Got em\n");
#endif
while ( ! ( V_22 = F_47 ( V_73 ) & V_77 ) )
;
if ( V_22 ) {
if ( ! ( ( V_22 = F_47 ( V_81 ) ) & V_82 ) )
F_2 ( V_6 L_27 , V_22 ) ;
} else
F_2 ( V_6 L_28 ) ;
#if 0
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_END_DMA_TRANSFER)) {
printk(KERN_ERR "53C400w: no end dma signal\n");
}
#endif
while ( ! ( F_47 ( V_87 ) & V_88 ) )
;
return 0 ;
}
static void F_51 ( struct V_89 * V_90 , int V_91 )
{
F_52 ( L_29 ANDP opcode) ;
}
static void F_53 ( struct V_89 * V_90 , unsigned char * V_92 )
{
int V_22 , V_93 ;
F_51 ( V_90 , V_92 [ 0 ] ) ;
for ( V_22 = 1 , V_93 = F_54 ( V_92 [ 0 ] ) ; V_22 < V_93 ; ++ V_22 )
F_52 ( L_30 ANDP command[i]) ;
F_52 ( L_21 ) ;
}
static void F_55 ( struct V_89 * V_90 , T_5 * V_94 )
{
F_52 ( L_31 ANDP cmd->device->host->host_no ANDP cmd->device->id ANDP cmd->device->lun) ;
F_52 ( L_32 ) ;
F_53 ( V_90 , V_94 -> V_95 ) ;
}
static int F_56 ( struct V_89 * V_90 , struct V_27 * V_96 )
{
F_40 () ;
unsigned long V_26 ;
unsigned char V_97 ;
int V_22 ;
T_5 * V_98 ;
struct V_48 * V_51 ;
#ifdef F_57
struct V_62 * V_40 ;
#endif
F_41 ( V_96 ) ;
V_51 = (struct V_48 * ) V_96 -> V_51 ;
F_58 ( V_96 -> V_99 , V_26 ) ;
F_52 ( L_33 ANDP scsi_ptr->host_no ANDP scsi_ptr->hostt->name) ;
F_52 ( L_34 ANDP GENERIC_NCR5380_PUBLIC_RELEASE) ;
F_52 ( L_35 ANDP NCR5380_PUBLIC_RELEASE) ;
#ifdef F_59
F_52 ( L_36 ANDP NCR53C400_PUBLIC_RELEASE) ;
F_52 ( L_37 F_60 ( ( (struct V_48 * ) V_96 -> V_51 ) -> V_26 & V_44 ) ? L_38 : L_39 ) ;
# if V_100
F_52 ( L_40 ) ;
# endif
#else
F_52 ( L_41 ) ;
#endif
F_52 ( L_42 ANDP STRVAL(NCR5380_map_config) ANDP STRVAL(NCR5380_map_name) ANDP scsi_ptr->NCR5380_instance_name) ;
if ( V_96 -> V_14 == V_41 )
F_52 ( L_43 ) ;
else
F_52 ( L_44 ANDP scsi_ptr->irq) ;
#ifdef F_57
if ( V_51 -> V_101 || V_51 -> V_102 || V_51 -> V_103 )
F_52 ( L_45 ) ;
if ( V_51 -> V_104 )
F_52 ( L_46 ANDP hostdata->pendingr) ;
if ( V_51 -> V_105 )
F_52 ( L_47 ANDP hostdata->pendingw) ;
if ( V_51 -> V_104 || V_51 -> V_105 )
F_52 ( L_21 ) ;
F_61 (dev, scsi_ptr) {
unsigned long V_106 = V_51 -> V_107 [ V_40 -> V_108 ] ;
unsigned long V_109 = V_51 -> V_110 [ V_40 -> V_108 ] ;
long V_111 = V_51 -> V_112 [ V_40 -> V_108 ] / V_113 ;
long V_114 = V_51 -> V_115 [ V_40 -> V_108 ] / V_113 ;
F_52 ( L_48 ANDP dev->id ANDP scsi_device_type(dev->type)) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
if ( V_40 -> V_116 [ V_22 ] >= 0x20 )
F_62 ( V_90 , V_40 -> V_116 [ V_22 ] ) ;
F_62 ( V_90 , ' ' ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
if ( V_40 -> V_117 [ V_22 ] >= 0x20 )
F_62 ( V_90 , V_40 -> V_117 [ V_22 ] ) ;
F_62 ( V_90 , ' ' ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
if ( V_40 -> V_118 [ V_22 ] >= 0x20 )
F_62 ( V_90 , V_40 -> V_118 [ V_22 ] ) ;
F_62 ( V_90 , ' ' ) ;
F_52 ( L_49 ANDP br / 1024 ANDP tr) ;
if ( V_111 )
F_52 ( L_50 ANDP br / tr) ;
F_52 ( L_51 ANDP bw / 1024 ANDP tw) ;
if ( V_114 )
F_52 ( L_50 ANDP bw / tw) ;
F_52 ( L_21 ) ;
}
#endif
V_97 = F_47 ( V_119 ) ;
if ( ! ( V_97 & V_120 ) )
F_52 ( L_52 ) ;
else {
for ( V_22 = 0 ; ( V_121 [ V_22 ] . V_122 != V_123 ) && ( V_121 [ V_22 ] . V_122 != ( V_97 & V_124 ) ) ; ++ V_22 ) ;
F_52 ( L_53 ANDP phases[i].name) ;
}
if ( ! V_51 -> V_101 ) {
F_52 ( L_54 ) ;
} else {
F_55 ( V_90 , ( T_5 * ) V_51 -> V_101 ) ;
}
F_52 ( L_55 ) ;
for ( V_98 = ( T_5 * ) V_51 -> V_102 ; V_98 ; V_98 = ( T_5 * ) V_98 -> V_125 )
F_55 ( V_90 , V_98 ) ;
F_52 ( L_56 ) ;
for ( V_98 = ( T_5 * ) V_51 -> V_103 ; V_98 ; V_98 = ( T_5 * ) V_98 -> V_125 )
F_55 ( V_90 , V_98 ) ;
F_63 ( V_96 -> V_99 , V_26 ) ;
return 0 ;
}
