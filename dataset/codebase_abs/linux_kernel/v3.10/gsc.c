int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 ) ;
if ( V_3 < 0 ) {
F_3 ( L_1 ) ;
return V_3 ;
}
V_2 -> V_5 = F_4 ( V_3 ) ;
V_2 -> V_6 = F_5 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
return V_3 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 )
{
int V_7 = V_3 ;
V_3 += V_8 ;
V_3 = F_7 ( V_3 ) ;
if ( V_3 < 0 ) {
F_3 ( L_2 , V_7 ) ;
return V_3 ;
}
V_2 -> V_5 = F_4 ( V_3 ) ;
V_2 -> V_6 = F_5 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
return V_3 ;
}
T_1 F_8 ( int V_9 , void * V_10 )
{
unsigned long V_11 ;
struct V_12 * V_12 = V_10 ;
V_11 = F_9 ( V_12 -> V_13 + V_14 ) ;
if ( V_11 == 0 )
return V_15 ;
F_10 ( L_3 , V_12 -> V_16 , V_11 ) ;
do {
int V_17 = F_11 ( V_11 ) ;
unsigned int V_3 = V_12 -> V_18 [ V_17 ] ;
F_12 ( V_3 ) ;
V_11 &= ~ ( 1 << V_17 ) ;
} while ( V_11 );
return V_19 ;
}
int F_13 ( unsigned int V_3 , int * V_20 , int V_21 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
if ( V_20 [ V_17 ] == V_3 )
return V_17 ;
}
return V_22 ;
}
static void F_14 ( struct V_23 * V_24 )
{
struct V_12 * V_25 = F_15 ( V_24 ) ;
int V_17 = F_13 ( V_24 -> V_3 , V_25 -> V_18 , 32 ) ;
T_2 V_26 ;
F_10 ( V_27 L_4 , V_28 , V_24 -> V_3 ,
V_25 -> V_16 , V_26 ) ;
V_26 = F_9 ( V_25 -> V_13 + V_29 ) ;
V_26 &= ~ ( 1 << V_17 ) ;
F_16 ( V_26 , V_25 -> V_13 + V_29 ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_12 * V_25 = F_15 ( V_24 ) ;
int V_17 = F_13 ( V_24 -> V_3 , V_25 -> V_18 , 32 ) ;
T_2 V_26 ;
F_10 ( V_27 L_4 , V_28 , V_24 -> V_3 ,
V_25 -> V_16 , V_26 ) ;
V_26 = F_9 ( V_25 -> V_13 + V_29 ) ;
V_26 |= 1 << V_17 ;
F_16 ( V_26 , V_25 -> V_13 + V_29 ) ;
}
int F_18 ( struct V_30 * type , void * V_31 )
{
static int V_3 = V_32 ;
if ( V_3 > V_33 )
return V_22 ;
F_19 ( V_3 , type , V_34 ) ;
F_20 ( V_3 , V_31 ) ;
return V_3 ++ ;
}
void F_21 ( struct V_12 * V_35 , int V_17 , int * V_36 )
{
int V_3 = V_35 -> V_18 [ V_17 ] ;
if ( V_3 <= 0 ) {
V_3 = F_18 ( & V_37 , V_35 ) ;
if ( V_3 == V_22 )
return;
V_35 -> V_18 [ V_17 ] = V_3 ;
}
* V_36 = V_3 ;
}
static int F_22 ( struct V_38 * V_10 , void * V_31 )
{
struct V_39 * V_40 = F_23 ( V_10 ) ;
struct V_41 * V_42 = V_31 ;
if ( V_40 -> V_43 . V_44 == V_45 )
F_24 ( V_40 , V_42 -> V_46 , V_42 -> V_47 ) ;
V_42 -> V_47 ( V_40 , V_42 -> V_46 ) ;
return 0 ;
}
void F_24 ( struct V_39 * V_48 , void * V_46 ,
void (* V_47)( struct V_39 * , void * ) )
{
struct V_41 V_31 = {
. V_47 = V_47 ,
. V_46 = V_46 ,
} ;
F_25 ( & V_48 -> V_10 , & V_31 , F_22 ) ;
}
int F_26 ( struct V_39 * V_48 , struct V_12 * V_12 )
{
struct V_49 * V_50 ;
int V_2 ;
V_12 -> V_51 = V_48 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
V_12 -> V_18 [ V_2 ] = V_22 ;
}
V_50 = F_27 ( V_12 -> V_13 , 0x100000 , V_12 -> V_16 ) ;
if ( V_50 ) {
V_50 -> V_52 = V_53 ;
}
#if 0
printk(KERN_WARNING "%s IRQ %d EIM 0x%x", gsc_asic->name,
parent->irq, gsc_asic->eim);
if (gsc_readl(gsc_asic->hpa + OFFSET_IMR))
printk(" IMR is non-zero! (0x%x)",
gsc_readl(gsc_asic->hpa + OFFSET_IMR));
printk("\n");
#endif
return 0 ;
}
void T_3 F_28 ( void )
{
#ifdef F_29
F_30 ( & V_54 ) ;
F_30 ( & V_55 ) ;
#endif
#ifdef F_31
F_30 ( & V_56 ) ;
#endif
}
