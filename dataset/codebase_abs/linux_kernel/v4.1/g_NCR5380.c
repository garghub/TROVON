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
static int T_1 F_10 ( struct V_17 * V_18 )
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
if ( V_28 -> V_14 == 255 )
V_28 -> V_14 = V_41 ;
if ( V_28 -> V_14 != V_41 )
if ( F_36 ( V_28 -> V_14 , V_53 ,
0 , L_12 , V_28 ) ) {
F_2 ( V_54 L_13 , V_28 -> V_55 , V_28 -> V_14 ) ;
V_28 -> V_14 = V_41 ;
}
if ( V_28 -> V_14 == V_41 ) {
F_2 ( V_56 L_14 , V_28 -> V_55 ) ;
F_2 ( V_56 L_15 , V_28 -> V_55 ) ;
}
++ V_19 ;
++ V_20 ;
}
return V_20 ;
}
static int F_37 ( struct V_27 * V_28 )
{
F_38 () ;
F_39 ( V_28 ) ;
if ( V_28 -> V_14 != V_41 )
F_40 ( V_28 -> V_14 , V_28 ) ;
F_41 ( V_28 ) ;
#ifndef F_11
F_27 ( V_28 -> V_49 , V_28 -> V_50 ) ;
#else
F_33 ( ( (struct V_48 * ) V_28 -> V_51 ) -> V_30 ) ;
F_31 ( V_28 -> V_49 , V_47 ) ;
#endif
return 0 ;
}
static int
F_42 ( struct V_57 * V_58 , struct V_59 * V_60 ,
T_4 V_61 , int * V_62 )
{
V_62 [ 0 ] = 64 ;
V_62 [ 1 ] = 32 ;
V_62 [ 2 ] = V_61 >> 11 ;
return 0 ;
}
static inline int F_43 ( struct V_27 * V_28 , unsigned char * V_63 , int V_64 )
{
int V_65 = V_64 / 128 ;
int V_66 = 0 ;
int V_67 ;
F_38 () ;
F_39 ( V_28 ) ;
F_44 ( V_68 , V_69 | V_70 ) ;
F_44 ( V_71 , V_65 ) ;
while ( 1 ) {
if ( ( V_67 = F_45 ( V_71 ) ) == 0 ) {
break;
}
if ( F_45 ( V_68 ) & V_72 ) {
F_2 ( V_6 L_16 , V_66 , V_65 ) ;
return - 1 ;
}
while ( F_45 ( V_68 ) & V_73 ) ;
#ifndef F_11
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
V_63 [ V_66 + V_22 ] = F_45 ( V_74 ) ;
}
#else
F_46 ( V_63 + V_66 , V_30 + V_75 , 128 ) ;
#endif
V_66 += 128 ;
V_65 -- ;
}
if ( V_65 ) {
while ( F_45 ( V_68 ) & V_73 )
{
}
#ifndef F_11
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
V_63 [ V_66 + V_22 ] = F_45 ( V_74 ) ;
}
#else
F_46 ( V_63 + V_66 , V_30 + V_75 , 128 ) ;
#endif
V_66 += 128 ;
V_65 -- ;
}
if ( ! ( F_45 ( V_68 ) & V_72 ) )
F_2 ( L_17 ) ;
#if 0
printk("53C400r: Waiting for 53C80 registers\n");
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_53C80_REG)
;
#endif
if ( ! ( F_45 ( V_76 ) & V_77 ) )
F_2 ( V_6 L_18 ) ;
F_44 ( V_78 , V_79 ) ;
F_45 ( V_80 ) ;
return 0 ;
}
static inline int F_47 ( struct V_27 * V_28 , unsigned char * V_81 , int V_64 )
{
int V_65 = V_64 / 128 ;
int V_66 = 0 ;
int V_67 ;
int V_22 ;
F_38 () ;
F_39 ( V_28 ) ;
F_44 ( V_68 , V_69 ) ;
F_44 ( V_71 , V_65 ) ;
while ( 1 ) {
if ( F_45 ( V_68 ) & V_72 ) {
F_2 ( V_6 L_19 , V_66 , V_65 ) ;
return - 1 ;
}
if ( ( V_67 = F_45 ( V_71 ) ) == 0 ) {
break;
}
while ( F_45 ( V_68 ) & V_73 )
;
#ifndef F_11
{
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
F_44 ( V_74 , V_81 [ V_66 + V_22 ] ) ;
}
#else
F_48 ( V_30 + V_75 , V_81 + V_66 , 128 ) ;
#endif
V_66 += 128 ;
V_65 -- ;
}
if ( V_65 ) {
while ( F_45 ( V_68 ) & V_73 )
;
#ifndef F_11
{
for ( V_22 = 0 ; V_22 < 128 ; V_22 ++ )
F_44 ( V_74 , V_81 [ V_66 + V_22 ] ) ;
}
#else
F_48 ( V_30 + V_75 , V_81 + V_66 , 128 ) ;
#endif
V_66 += 128 ;
V_65 -- ;
}
#if 0
printk("53C400w: waiting for registers to be available\n");
THEY NEVER DO ! while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_53C80_REG);
printk("53C400w: Got em\n");
#endif
while ( ! ( V_22 = F_45 ( V_68 ) & V_72 ) )
;
if ( V_22 ) {
if ( ! ( ( V_22 = F_45 ( V_76 ) ) & V_77 ) )
F_2 ( V_6 L_20 , V_22 ) ;
} else
F_2 ( V_6 L_21 ) ;
#if 0
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_END_DMA_TRANSFER)) {
printk(KERN_ERR "53C400w: no end dma signal\n");
}
#endif
while ( ! ( F_45 ( V_82 ) & V_83 ) )
;
return 0 ;
}
