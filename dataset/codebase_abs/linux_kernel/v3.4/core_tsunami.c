static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 , unsigned char * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_10 ;
T_1 V_11 = V_2 -> V_12 ;
F_2 ( ( L_1
L_2 ,
V_11 , V_3 , V_4 , V_5 , V_6 ) ) ;
if ( ! V_2 -> V_13 )
V_11 = 0 ;
* V_6 = ( V_11 != 0 ) ;
V_10 = ( V_11 << 16 ) | ( V_3 << 8 ) | V_4 ;
V_10 |= V_8 -> V_14 ;
* V_5 = V_10 ;
F_2 ( ( L_3 , V_10 ) ) ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_11 , unsigned int V_15 , int V_4 ,
int V_16 , T_2 * V_17 )
{
unsigned long V_10 ;
unsigned char V_6 ;
if ( F_1 ( V_11 , V_15 , V_4 , & V_10 , & V_6 ) )
return V_18 ;
switch ( V_16 ) {
case 1 :
* V_17 = F_4 ( * ( V_19 ) V_10 ) ;
break;
case 2 :
* V_17 = F_5 ( * ( V_20 ) V_10 ) ;
break;
case 4 :
* V_17 = * ( V_21 ) V_10 ;
break;
}
return V_22 ;
}
static int
F_6 ( struct V_1 * V_11 , unsigned int V_15 , int V_4 ,
int V_16 , T_2 V_17 )
{
unsigned long V_10 ;
unsigned char V_6 ;
if ( F_1 ( V_11 , V_15 , V_4 , & V_10 , & V_6 ) )
return V_18 ;
switch ( V_16 ) {
case 1 :
F_7 ( V_17 , * ( V_19 ) V_10 ) ;
F_8 () ;
F_4 ( * ( V_19 ) V_10 ) ;
break;
case 2 :
F_9 ( V_17 , * ( V_20 ) V_10 ) ;
F_8 () ;
F_5 ( * ( V_20 ) V_10 ) ;
break;
case 4 :
* ( V_21 ) V_10 = V_17 ;
F_8 () ;
* ( V_21 ) V_10 ;
break;
}
return V_22 ;
}
void
F_10 ( struct V_7 * V_8 , T_3 V_23 , T_3 V_24 )
{
T_4 * V_25 = V_8 -> V_26 ? V_27 : V_28 ;
volatile unsigned long * V_29 ;
unsigned long V_17 ;
V_29 = & V_25 -> V_30 . V_29 ;
if ( ( ( V_23 ^ V_24 ) & 0xffff0000 ) == 0 )
V_29 = & V_25 -> V_31 . V_29 ;
V_17 = ( V_23 & 0xffff0000 ) >> 12 ;
* V_29 = V_17 ;
F_8 () ;
* V_29 ;
}
static long T_5
F_11 ( volatile unsigned long * V_32 )
{
long V_33 , V_34 ;
int V_35 = F_12 () ;
int V_36 = F_13 ( V_37 - 1 ) ;
F_14 ( V_35 ) = 0 ;
F_15 ( V_35 ) = 1 ;
F_8 () ;
V_33 = * V_32 ;
F_16 () ;
F_15 ( V_35 ) = 0 ;
V_34 = ! F_14 ( V_35 ) ;
F_14 ( V_35 ) = 0 ;
F_17 ( V_36 ) ;
F_18 ( L_4 , V_33 ) ;
return V_34 ;
}
static long T_5
F_19 ( volatile unsigned long * V_32 )
{
long V_38 , V_34 = 1 ;
V_39 -> V_40 . V_29 |= ( 1L << 28 ) ;
V_38 = * V_32 ;
* V_32 = 0 ;
F_16 () ;
if ( V_39 -> V_40 . V_29 & ( 1L << 28 ) ) {
int V_41 = ( V_39 -> V_40 . V_29 >> 29 ) & 7 ;
V_39 -> V_40 . V_29 |= ( 1L << 28 ) ;
V_34 = 0 ;
F_18 ( L_5 , V_41 ,
( unsigned long ) V_32 ) ;
}
if ( V_34 )
* V_32 = V_38 ;
return V_34 ;
}
static void T_5
F_20 ( T_4 * V_25 , int V_26 )
{
struct V_7 * V_8 ;
if ( F_11 ( & V_25 -> V_42 . V_29 ) == 0 )
return;
V_8 = F_21 () ;
if ( V_26 == 0 )
V_43 = V_8 ;
V_8 -> V_44 = F_22 () ;
V_8 -> V_45 = F_22 () ;
V_8 -> V_46 = 0 ;
V_8 -> V_47 = 0 ;
V_8 -> V_48
= ( F_23 ( V_26 ) & 0xffffffffffL ) | 0x80000000000L ;
V_8 -> V_49
= ( F_24 ( V_26 ) & 0xffffffffffL ) | 0x80000000000L ;
V_8 -> V_14 = F_25 ( V_26 ) ;
V_8 -> V_26 = V_26 ;
V_8 -> V_44 -> V_23 = F_24 ( V_26 ) - V_50 ;
V_8 -> V_44 -> V_24 = V_8 -> V_44 -> V_23 + V_51 - 1 ;
V_8 -> V_44 -> V_52 = V_53 [ V_26 ] ;
V_8 -> V_44 -> V_54 = V_55 ;
V_8 -> V_45 -> V_23 = F_23 ( V_26 ) - V_56 ;
V_8 -> V_45 -> V_24 = V_8 -> V_45 -> V_23 + 0xffffffff ;
V_8 -> V_45 -> V_52 = V_57 [ V_26 ] ;
V_8 -> V_45 -> V_54 = V_58 ;
if ( F_26 ( & V_59 , V_8 -> V_44 ) < 0 )
F_18 ( V_60 L_6 , V_26 ) ;
if ( F_26 ( & V_61 , V_8 -> V_45 ) < 0 )
F_18 ( V_60 L_7 , V_26 ) ;
V_62 [ V_26 ] . V_63 [ 0 ] = V_25 -> V_63 [ 0 ] . V_29 ;
V_62 [ V_26 ] . V_64 [ 0 ] = V_25 -> V_64 [ 0 ] . V_29 ;
V_62 [ V_26 ] . V_65 [ 0 ] = V_25 -> V_65 [ 0 ] . V_29 ;
V_62 [ V_26 ] . V_63 [ 1 ] = V_25 -> V_63 [ 1 ] . V_29 ;
V_62 [ V_26 ] . V_64 [ 1 ] = V_25 -> V_64 [ 1 ] . V_29 ;
V_62 [ V_26 ] . V_65 [ 1 ] = V_25 -> V_65 [ 1 ] . V_29 ;
V_62 [ V_26 ] . V_63 [ 2 ] = V_25 -> V_63 [ 2 ] . V_29 ;
V_62 [ V_26 ] . V_64 [ 2 ] = V_25 -> V_64 [ 2 ] . V_29 ;
V_62 [ V_26 ] . V_65 [ 2 ] = V_25 -> V_65 [ 2 ] . V_29 ;
V_62 [ V_26 ] . V_63 [ 3 ] = V_25 -> V_63 [ 3 ] . V_29 ;
V_62 [ V_26 ] . V_64 [ 3 ] = V_25 -> V_64 [ 3 ] . V_29 ;
V_62 [ V_26 ] . V_65 [ 3 ] = V_25 -> V_65 [ 3 ] . V_29 ;
V_8 -> V_66 = F_27 ( V_8 , 0x00800000 , 0x00800000 , 0 ) ;
V_8 -> V_66 -> V_67 = 4 ;
V_8 -> V_68 = F_27 ( V_8 , 0x40000000 ,
F_28 ( 0x40000000 ) , 0 ) ;
V_8 -> V_68 -> V_67 = 4 ;
V_69 = 0x80000000 ;
V_70 = 0x80000000 ;
V_25 -> V_63 [ 0 ] . V_29 = V_8 -> V_66 -> V_71 | 3 ;
V_25 -> V_64 [ 0 ] . V_29 = ( V_8 -> V_66 -> V_16 - 1 ) & 0xfff00000 ;
V_25 -> V_65 [ 0 ] . V_29 = F_29 ( V_8 -> V_66 -> V_72 ) ;
V_25 -> V_63 [ 1 ] . V_29 = V_8 -> V_68 -> V_71 | 3 ;
V_25 -> V_64 [ 1 ] . V_29 = ( V_8 -> V_68 -> V_16 - 1 ) & 0xfff00000 ;
V_25 -> V_65 [ 1 ] . V_29 = F_29 ( V_8 -> V_68 -> V_72 ) ;
V_25 -> V_63 [ 2 ] . V_29 = 0x80000000 | 1 ;
V_25 -> V_64 [ 2 ] . V_29 = ( 0x80000000 - 1 ) & 0xfff00000 ;
V_25 -> V_65 [ 2 ] . V_29 = 0 ;
V_25 -> V_63 [ 3 ] . V_29 = 0 ;
V_25 -> V_42 . V_29 |= V_73 ;
F_10 ( V_8 , 0 , - 1 ) ;
}
void T_6 *
F_30 ( unsigned long V_10 )
{
F_31 ( V_10 ) ;
return ( void T_6 * ) ( V_10 + V_50 ) ;
}
void T_6 *
F_32 ( unsigned long V_10 , unsigned long V_16 )
{
F_33 ( V_10 ) ;
return ( void T_6 * ) ( V_10 + V_56 ) ;
}
void T_5
F_34 ( void )
{
#ifdef F_35
unsigned long V_74 ;
F_36 ( V_75 , 0 ) ;
V_74 = ( unsigned long ) ( V_39 - 1 ) ;
F_18 ( L_8 , V_76 , V_77 ) ;
F_18 ( L_9 ,
F_19 ( ( unsigned long * ) V_77 )
? L_10 : L_11 ) ;
#endif
#if 0
printk("%s: CChip registers:\n", __func__);
printk("%s: CSR_CSC 0x%lx\n", __func__, TSUNAMI_cchip->csc.csr);
printk("%s: CSR_MTR 0x%lx\n", __func__, TSUNAMI_cchip.mtr.csr);
printk("%s: CSR_MISC 0x%lx\n", __func__, TSUNAMI_cchip->misc.csr);
printk("%s: CSR_DIM0 0x%lx\n", __func__, TSUNAMI_cchip->dim0.csr);
printk("%s: CSR_DIM1 0x%lx\n", __func__, TSUNAMI_cchip->dim1.csr);
printk("%s: CSR_DIR0 0x%lx\n", __func__, TSUNAMI_cchip->dir0.csr);
printk("%s: CSR_DIR1 0x%lx\n", __func__, TSUNAMI_cchip->dir1.csr);
printk("%s: CSR_DRIR 0x%lx\n", __func__, TSUNAMI_cchip->drir.csr);
printk("%s: DChip registers:\n");
printk("%s: CSR_DSC 0x%lx\n", __func__, TSUNAMI_dchip->dsc.csr);
printk("%s: CSR_STR 0x%lx\n", __func__, TSUNAMI_dchip->str.csr);
printk("%s: CSR_DREV 0x%lx\n", __func__, TSUNAMI_dchip->drev.csr);
#endif
V_59 . V_24 = ~ 0UL ;
F_20 ( V_28 , 0 ) ;
if ( V_39 -> V_78 . V_29 & 1L << 14 )
F_20 ( V_27 , 1 ) ;
F_37 () ;
}
static void
F_38 ( T_4 * V_25 , int V_26 )
{
V_25 -> V_63 [ 0 ] . V_29 = V_62 [ V_26 ] . V_63 [ 0 ] ;
V_25 -> V_64 [ 0 ] . V_29 = V_62 [ V_26 ] . V_64 [ 0 ] ;
V_25 -> V_65 [ 0 ] . V_29 = V_62 [ V_26 ] . V_65 [ 0 ] ;
V_25 -> V_63 [ 1 ] . V_29 = V_62 [ V_26 ] . V_63 [ 1 ] ;
V_25 -> V_64 [ 1 ] . V_29 = V_62 [ V_26 ] . V_64 [ 1 ] ;
V_25 -> V_65 [ 1 ] . V_29 = V_62 [ V_26 ] . V_65 [ 1 ] ;
V_25 -> V_63 [ 2 ] . V_29 = V_62 [ V_26 ] . V_63 [ 2 ] ;
V_25 -> V_64 [ 2 ] . V_29 = V_62 [ V_26 ] . V_64 [ 2 ] ;
V_25 -> V_65 [ 2 ] . V_29 = V_62 [ V_26 ] . V_65 [ 2 ] ;
V_25 -> V_63 [ 3 ] . V_29 = V_62 [ V_26 ] . V_63 [ 3 ] ;
V_25 -> V_64 [ 3 ] . V_29 = V_62 [ V_26 ] . V_64 [ 3 ] ;
V_25 -> V_65 [ 3 ] . V_29 = V_62 [ V_26 ] . V_65 [ 3 ] ;
}
void
F_39 ( int V_79 )
{
F_38 ( V_28 , 0 ) ;
if ( V_39 -> V_78 . V_29 & 1L << 14 )
F_38 ( V_27 , 1 ) ;
}
static inline void
F_40 ( T_4 * V_25 )
{
V_25 -> perror . V_29 ;
V_25 -> perror . V_29 = 0x040 ;
F_8 () ;
V_25 -> perror . V_29 ;
}
static inline void
F_41 ( void )
{
F_40 ( V_28 ) ;
if ( V_39 -> V_78 . V_29 & 1L << 14 )
F_40 ( V_27 ) ;
}
void
F_42 ( unsigned long V_80 , unsigned long V_81 )
{
F_8 () ;
F_8 () ;
F_16 () ;
F_41 () ;
F_43 ( 0x7 ) ;
F_8 () ;
F_44 ( V_80 , V_81 , L_12 ,
F_15 ( F_12 () ) ) ;
}
