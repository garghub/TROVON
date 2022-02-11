static void
F_1 ( unsigned int V_1 )
{
int V_2 = ( V_1 >> 8 ) & ( V_3 - 1 ) ;
int V_4 = ( V_1 >> 6 ) & ( V_5 - 1 ) ;
T_1 * V_6 ;
volatile unsigned long * V_7 ;
if ( ! F_2 ( V_2 , V_4 ) ) {
if ( ! V_8 ) {
F_3 ( V_9 L_1
L_2
L_3 ,
V_1 , V_4 , V_2 ) ;
}
return;
}
V_6 = F_4 ( V_2 , V_4 ) ;
V_7 = ( unsigned long * ) & V_6 -> V_10 [ 0 ] . V_11 ;
* V_7 = V_12 [ V_2 * V_5 + V_4 ] ;
F_5 () ;
* V_7 ;
}
static void T_2
F_6 ( void )
{
#if 0
register wildfire_pca * pca = WILDFIRE_pca(0, 0);
volatile unsigned long * enable0, * enable1, * enable2, *enable3;
volatile unsigned long * target0, * target1, * target2, *target3;
enable0 = (unsigned long *) &pca->pca_int[0].enable;
enable1 = (unsigned long *) &pca->pca_int[1].enable;
enable2 = (unsigned long *) &pca->pca_int[2].enable;
enable3 = (unsigned long *) &pca->pca_int[3].enable;
target0 = (unsigned long *) &pca->pca_int[0].target;
target1 = (unsigned long *) &pca->pca_int[1].target;
target2 = (unsigned long *) &pca->pca_int[2].target;
target3 = (unsigned long *) &pca->pca_int[3].target;
*enable0 = *enable1 = *enable2 = *enable3 = 0;
*target0 = (1UL<<8) | WILDFIRE_QBB(0);
*target1 = *target2 = *target3 = 0;
mb();
*enable0; *enable1; *enable2; *enable3;
*target0; *target1; *target2; *target3;
#else
int V_13 ;
V_8 = 1 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 += V_15 )
F_1 ( V_13 ) ;
V_8 = 0 ;
#endif
}
static void
F_7 ( struct V_16 * V_17 )
{
unsigned int V_1 = V_17 -> V_1 ;
if ( V_1 < 16 )
F_8 ( V_17 ) ;
F_9 ( & V_18 ) ;
F_10 ( V_1 , & V_12 ) ;
F_1 ( V_1 ) ;
F_11 ( & V_18 ) ;
}
static void
F_12 ( struct V_16 * V_17 )
{
unsigned int V_1 = V_17 -> V_1 ;
if ( V_1 < 16 )
F_13 ( V_17 ) ;
F_9 ( & V_18 ) ;
F_14 ( V_1 , & V_12 ) ;
F_1 ( V_1 ) ;
F_11 ( & V_18 ) ;
}
static void
F_15 ( struct V_16 * V_17 )
{
unsigned int V_1 = V_17 -> V_1 ;
if ( V_1 < 16 )
F_16 ( V_17 ) ;
F_9 ( & V_18 ) ;
F_14 ( V_1 , & V_12 ) ;
F_1 ( V_1 ) ;
F_11 ( & V_18 ) ;
}
static void T_2
F_17 ( int V_2 , int V_4 )
{
int V_13 , V_19 ;
static struct V_20 V_21 = {
. V_22 = V_23 ,
. V_24 = L_4 ,
} ;
V_19 = V_2 * ( V_5 * V_15 )
+ V_4 * V_15 ;
#if 0
unsigned long io_bias;
io_bias = WILDFIRE_IO(qbbno, pcano<<1) - WILDFIRE_IO_BIAS;
outb(0, DMA1_RESET_REG + io_bias);
outb(0, DMA2_RESET_REG + io_bias);
outb(DMA_MODE_CASCADE, DMA2_MODE_REG + io_bias);
outb(0, DMA2_MASK_REG + io_bias);
#endif
#if 0
init_i8259a_irqs();
#endif
for ( V_13 = 0 ; V_13 < 16 ; ++ V_13 ) {
if ( V_13 == 2 )
continue;
F_18 ( V_13 + V_19 , & V_25 ,
V_26 ) ;
F_19 ( V_13 + V_19 , V_27 ) ;
}
F_18 ( 36 + V_19 , & V_25 ,
V_26 ) ;
F_19 ( 36 + V_19 , V_27 ) ;
for ( V_13 = 40 ; V_13 < 64 ; ++ V_13 ) {
F_18 ( V_13 + V_19 , & V_25 ,
V_26 ) ;
F_19 ( V_13 + V_19 , V_27 ) ;
}
F_20 ( 32 + V_19 , & V_21 ) ;
}
static void T_2
F_21 ( void )
{
int V_2 , V_4 ;
#if 1
F_6 () ;
F_22 () ;
#endif
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( F_23 ( V_2 ) ) {
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( F_2 ( V_2 , V_4 ) ) {
F_17 ( V_2 , V_4 ) ;
}
}
}
}
}
static void
F_24 ( unsigned long V_28 )
{
int V_1 ;
V_1 = ( V_28 - 0x800 ) >> 4 ;
F_25 ( V_1 ) ;
return;
}
static int T_2
F_26 ( struct V_29 * V_30 , T_3 V_31 , T_3 V_32 )
{
static char V_33 [ 8 ] [ 5 ] V_34 = {
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 36 , 36 , 36 + 1 , 36 + 2 , 36 + 3 } ,
{ 40 , 40 , 40 + 1 , 40 + 2 , 40 + 3 } ,
{ 44 , 44 , 44 + 1 , 44 + 2 , 44 + 3 } ,
{ 48 , 48 , 48 + 1 , 48 + 2 , 48 + 3 } ,
{ 52 , 52 , 52 + 1 , 52 + 2 , 52 + 3 } ,
{ 56 , 56 , 56 + 1 , 56 + 2 , 56 + 3 } ,
{ 60 , 60 , 60 + 1 , 60 + 2 , 60 + 3 } ,
} ;
long V_35 = 0 , V_36 = 7 , V_37 = 5 ;
struct V_38 * V_39 = V_30 -> V_40 ;
int V_1 = V_41 ;
if ( V_1 > 0 ) {
int V_2 = V_39 -> V_42 >> 3 ;
int V_4 = ( V_39 -> V_42 >> 1 ) & 3 ;
V_1 += ( V_2 << 8 ) + ( V_4 << 6 ) ;
}
return V_1 ;
}
