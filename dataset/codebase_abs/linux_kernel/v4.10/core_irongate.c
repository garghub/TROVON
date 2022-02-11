static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 , unsigned char * V_6 )
{
unsigned long V_7 ;
T_1 V_8 = V_2 -> V_9 ;
F_2 ( ( L_1
L_2 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ) ;
* V_6 = ( V_8 != 0 ) ;
V_7 = ( V_8 << 16 ) | ( V_3 << 8 ) | V_4 ;
V_7 |= V_10 ;
* V_5 = V_7 ;
F_2 ( ( L_3 , V_7 ) ) ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_8 , unsigned int V_11 , int V_4 ,
int V_12 , T_2 * V_13 )
{
unsigned long V_7 ;
unsigned char V_6 ;
if ( F_1 ( V_8 , V_11 , V_4 , & V_7 , & V_6 ) )
return V_14 ;
switch ( V_12 ) {
case 1 :
* V_13 = F_4 ( * ( V_15 ) V_7 ) ;
break;
case 2 :
* V_13 = F_5 ( * ( V_16 ) V_7 ) ;
break;
case 4 :
* V_13 = * ( V_17 ) V_7 ;
break;
}
return V_18 ;
}
static int
F_6 ( struct V_1 * V_8 , unsigned int V_11 , int V_4 ,
int V_12 , T_2 V_13 )
{
unsigned long V_7 ;
unsigned char V_6 ;
if ( F_1 ( V_8 , V_11 , V_4 , & V_7 , & V_6 ) )
return V_14 ;
switch ( V_12 ) {
case 1 :
F_7 ( V_13 , * ( V_15 ) V_7 ) ;
F_8 () ;
F_4 ( * ( V_15 ) V_7 ) ;
break;
case 2 :
F_9 ( V_13 , * ( V_16 ) V_7 ) ;
F_8 () ;
F_5 ( * ( V_16 ) V_7 ) ;
break;
case 4 :
* ( V_17 ) V_7 = V_13 ;
F_8 () ;
* ( V_17 ) V_7 ;
break;
}
return V_18 ;
}
int
F_10 ( void )
{
unsigned int V_19 = 0 ;
unsigned int V_20 ;
V_21:
V_20 = V_22 -> V_23 ;
F_11 ( L_4 , V_20 ) ;
V_22 -> V_23 = V_20 ;
F_8 () ;
V_20 = V_22 -> V_23 ;
V_20 = * V_24 ;
F_11 ( L_5 , V_20 ) ;
* V_24 = V_20 ;
F_8 () ;
V_20 = * V_24 ;
V_19 = F_12 ( 0x61 ) ;
V_19 |= 0x0c ;
F_13 ( V_19 , 0x61 ) ;
V_19 &= ~ 0x0c ;
F_13 ( V_19 , 0x61 ) ;
V_20 = * V_24 ;
if ( V_20 & 0x300 ) goto V_21;
return 0 ;
}
static void T_3
F_14 ( void )
{
unsigned long V_25 = V_26 << V_27 ;
unsigned long V_28 = ( V_25 + 0x1000000UL ) & ~ 0xffffffUL ;
struct V_29 * V_30 ;
int V_31 , V_32 ;
V_30 = (struct V_29 * ) ( ( char * ) V_33 + V_33 -> V_34 ) ;
V_31 = V_30 -> V_35 & 0xffff ;
V_32 = ( V_30 -> V_35 >> 16 ) & 0xff ;
if ( V_36 &&
( V_31 < 0x13e || ( V_31 == 0x13e && V_32 < 2 ) ) )
F_11 ( V_37 L_6
L_7 ) ;
if ( V_28 > V_38 )
V_28 = V_38 ;
V_22 -> V_28 = V_28 ;
V_39 . V_40 = V_28 ;
if ( V_25 > V_28 ) {
#ifdef F_15
extern unsigned long V_41 , V_42 ;
extern void * V_43 ( unsigned long ) ;
if ( V_42 && F_16 ( V_42 ) > V_28 ) {
unsigned long V_12 ;
V_12 = V_42 - V_41 ;
F_17 ( F_18 ( 0 ) , F_16 ( V_41 ) ,
F_19 ( V_12 ) ) ;
if ( ! V_43 ( V_28 ) )
F_11 ( L_8
L_9 ,
V_12 / 1024 ) ;
}
#endif
F_20 ( F_18 ( 0 ) , V_28 , V_25 -
V_28 , V_44 ) ;
F_11 ( L_10
L_11 , V_28 , V_25 - 1 ) ;
}
}
static void T_3
F_21 ( void )
{
V_22 -> V_45 = V_22 -> V_45 & ~ 0xf ;
V_46 = 0 ;
}
void T_3
F_22 ( void )
{
struct V_47 * V_48 ;
int V_49 = ( V_22 -> V_50 >> 16 ) > 0x7006 ;
V_24 = V_49 ? & V_22 -> V_51 : & V_22 -> V_52 ;
F_10 () ;
if ( V_49 )
F_14 () ;
F_21 () ;
V_53 = V_48 = F_23 () ;
V_48 -> V_54 = & V_55 ;
V_48 -> V_56 = & V_57 ;
V_48 -> V_58 = 0 ;
V_48 -> V_59 = 0 ;
V_48 -> V_60 = 0 ;
V_48 -> V_61
= ( V_62 & 0xffffffffffUL ) | 0x80000000000UL ;
V_48 -> V_63
= ( V_64 & 0xffffffffffUL ) | 0x80000000000UL ;
V_48 -> V_65 = V_48 -> V_66 = NULL ;
V_67 = 0 ;
V_68 = 0xffffffff ;
}
void T_4 *
F_24 ( unsigned long V_7 , unsigned long V_12 )
{
struct V_69 * V_70 ;
unsigned long V_71 ;
unsigned long V_72 , V_73 ;
T_2 * V_74 , * V_75 , * V_76 , V_77 ;
unsigned long V_78 ;
if ( ! V_46 )
return ( void T_4 * ) ( V_7 + V_62 ) ;
V_78 = ( unsigned long ) V_22 -> V_79 &
V_80 ;
do {
if ( V_7 >= V_78 && V_7 + V_12 - 1 <
V_78 + V_46 )
break;
return ( void T_4 * ) ( V_7 + V_62 ) ;
} while( 0 );
V_74 = ( T_2 * ) ( ( ( unsigned long ) V_22 -> V_81 &
V_80 ) + V_62 ) ;
V_75 = ( T_2 * ) ( F_25 ( V_74 [ 1 ] ) ) ;
if ( V_7 & ~ V_82 ) {
F_11 ( L_12 ,
V_7 ) ;
return ( void T_4 * ) ( V_7 + V_62 ) ;
}
V_73 = V_7 + V_12 - 1 ;
V_12 = F_19 ( V_73 ) - V_7 ;
#if 0
printk("irongate_ioremap(0x%lx, 0x%lx)\n", addr, size);
printk("irongate_ioremap: gart_bus_addr 0x%lx\n", gart_bus_addr);
printk("irongate_ioremap: gart_aper_size 0x%lx\n", gart_aper_size);
printk("irongate_ioremap: mmio_regs %p\n", mmio_regs);
printk("irongate_ioremap: gatt_pages %p\n", gatt_pages);
for(baddr = addr; baddr <= last; baddr += PAGE_SIZE)
{
cur_gatt = phys_to_virt(GET_GATT(baddr) & ~1);
pte = cur_gatt[GET_GATT_OFF(baddr)] & ~1;
printk("irongate_ioremap: cur_gatt %p pte 0x%x\n",
cur_gatt, pte);
}
#endif
V_70 = F_26 ( V_12 , V_83 ) ;
if ( ! V_70 ) return NULL ;
for( V_72 = V_7 , V_71 = ( unsigned long ) V_70 -> V_7 ;
V_72 <= V_73 ;
V_72 += V_84 , V_71 += V_84 )
{
V_76 = F_25 ( F_27 ( V_72 ) & ~ 1 ) ;
V_77 = V_76 [ F_28 ( V_72 ) ] & ~ 1 ;
if ( F_29 ( V_71 ,
V_77 , V_84 , 0 ) ) {
F_11 ( L_13 ) ;
F_30 ( V_70 -> V_7 ) ;
return NULL ;
}
}
F_31 () ;
V_71 = ( unsigned long ) V_70 -> V_7 + ( V_7 & ~ V_82 ) ;
#if 0
printk("irongate_ioremap(0x%lx, 0x%lx) returning 0x%lx\n",
addr, size, vaddr);
#endif
return ( void T_4 * ) V_71 ;
}
void
F_32 ( volatile void T_4 * V_85 )
{
unsigned long V_7 = ( unsigned long ) V_85 ;
if ( ( ( long ) V_7 >> 41 ) == - 2 )
return;
if ( V_7 )
return F_30 ( ( void * ) ( V_82 & V_7 ) ) ;
}
