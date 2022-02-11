static inline void F_1 ( unsigned int V_1 )
{
int V_2 ;
unsigned long V_3 [ 4 ] ;
V_2 = ( V_1 / 256 ) * 4 ;
V_3 [ 0 ] = V_4 [ V_2 + 0 ]
& V_5 [ V_2 + 0 ] ;
V_3 [ 1 ] = V_4 [ V_2 + 1 ]
& V_5 [ V_2 + 1 ] ;
V_3 [ 2 ] = V_4 [ V_2 + 2 ]
& V_5 [ V_2 + 2 ] ;
V_3 [ 3 ] = V_4 [ V_2 + 3 ]
& V_5 [ V_2 + 3 ] ;
if ( F_2 ( V_1 & ~ 255UL ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) != 0 )
F_3 ( L_1 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
F_5 ( & V_9 , V_8 ) ;
V_4 [ V_7 -> V_10 / 64 ] &= ~ ( 1UL << ( 63 - ( V_7 -> V_10 % 64 ) ) ) ;
F_1 ( V_7 -> V_10 ) ;
F_6 ( & V_9 , V_8 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
F_5 ( & V_9 , V_8 ) ;
V_4 [ V_7 -> V_10 / 64 ] |= 1UL << ( 63 - ( V_7 -> V_10 % 64 ) ) ;
F_1 ( V_7 -> V_10 ) ;
F_6 ( & V_9 , V_8 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
F_5 ( & V_9 , V_8 ) ;
V_5 [ V_7 -> V_10 / 64 ] &= ~ ( 1UL << ( 63 - ( V_7 -> V_10 % 64 ) ) ) ;
F_1 ( V_7 -> V_10 ) ;
F_6 ( & V_9 , V_8 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
T_1 V_11 ;
unsigned long V_8 ;
V_11 = F_10 ( V_7 -> V_10 ) ;
if ( V_11 != 0 ) {
if ( ( V_11 & 0xFFFFFFFF ) != 0xFFFFFFF5 )
F_3 ( L_2 , V_11 ) ;
F_11 ( V_12 L_3 , V_7 -> V_10 ) ;
}
F_5 ( & V_9 , V_8 ) ;
V_5 [ V_7 -> V_10 / 64 ] |= 1UL << ( 63 - ( V_7 -> V_10 % 64 ) ) ;
F_1 ( V_7 -> V_10 ) ;
F_6 ( & V_9 , V_8 ) ;
}
static void F_12 ( struct V_13 * V_14 , unsigned int V_15 )
{
F_13 ( V_15 ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned int V_15 ,
T_2 V_16 )
{
T_3 V_11 ;
V_11 = F_15 ( V_15 , V_16 ) ;
if ( V_11 < 0 )
return - V_17 ;
F_16 ( V_15 , V_18 ) ;
F_17 ( V_15 , & V_19 , V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 , struct V_21 * V_22 ,
const T_4 * V_23 , unsigned int V_24 ,
T_2 * V_25 ,
unsigned int * V_26 )
{
const T_5 * V_27 = ( const T_5 * ) V_23 ;
* V_25 = * V_27 ;
* V_26 |= V_28 ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 , struct V_21 * V_29 )
{
return 1 ;
}
static inline unsigned int F_20 ( void )
{
int V_30 ;
T_6 V_31 [ 4 ] , V_32 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 += 256 ) {
F_21 ( V_30 , V_31 ) ;
__asm__ ("cntlzd %0,%1":"=r"(ub):
"r"(pending[0] & beatic_irq_mask_enable[i/64+0]
& beatic_irq_mask_ack[i/64+0]));
if ( V_32 != 64 )
return V_30 + V_32 + 0 ;
__asm__ ("cntlzd %0,%1":"=r"(ub):
"r"(pending[1] & beatic_irq_mask_enable[i/64+1]
& beatic_irq_mask_ack[i/64+1]));
if ( V_32 != 64 )
return V_30 + V_32 + 64 ;
__asm__ ("cntlzd %0,%1":"=r"(ub):
"r"(pending[2] & beatic_irq_mask_enable[i/64+2]
& beatic_irq_mask_ack[i/64+2]));
if ( V_32 != 64 )
return V_30 + V_32 + 128 ;
__asm__ ("cntlzd %0,%1":"=r"(ub):
"r"(pending[3] & beatic_irq_mask_enable[i/64+3]
& beatic_irq_mask_ack[i/64+3]));
if ( V_32 != 64 )
return V_30 + V_32 + 192 ;
}
return V_34 ;
}
unsigned int F_22 ( void )
{
unsigned int V_35 ;
V_35 = F_20 () ;
if ( V_35 != V_34 )
F_8 ( F_23 ( V_35 ) ) ;
return V_35 ;
}
void T_7 F_24 ( void )
{
int V_30 ;
memset ( V_4 , 0 , sizeof( V_4 ) ) ;
memset ( V_5 , 255 , sizeof( V_5 ) ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 += 256 )
F_2 ( V_30 , 0L , 0L , 0L , 0L ) ;
V_36 . V_37 = F_22 ;
V_38 = F_25 ( NULL , ~ 0 , & V_39 , NULL ) ;
F_26 ( V_38 == NULL ) ;
F_27 ( V_38 ) ;
}
void F_28 ( void )
{
int V_30 ;
for ( V_30 = 1 ; V_30 < V_40 ; V_30 ++ )
F_13 ( V_30 ) ;
}
