static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_2 , V_5 , 0x00 ) ;
F_4 ( V_2 , V_5 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_6 ,
unsigned long V_7 ,
unsigned int V_8 ,
unsigned int V_9 )
{
unsigned long V_3 ;
unsigned int V_10 ;
unsigned char V_11 ;
unsigned int V_12 ;
F_7 ( L_1 ,
V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_13 . V_14 > 3 ) {
if ( V_2 -> V_13 . V_15 ) {
V_10 = V_6 >> 1 ;
} else {
if ( V_6 & 0x1f ) {
F_8 ( L_2 , V_6 ) ;
return;
}
V_10 = ( V_6 & 0x000c0000 ) | ( ( V_6 & 0x0003ffff ) >> 1 ) ;
}
} else {
V_10 = V_6 ;
}
V_11 = V_16 | ( unsigned short ) V_9 ;
#if 0
dma_cmd |= 0x08;
#endif
if ( V_11 & V_17 ) {
V_8 ++ ;
V_8 &= ~ 1 ;
}
if ( V_2 -> V_13 . V_14 > 3 ) {
V_11 |= V_18 ;
V_8 ++ ;
V_8 &= ~ 1 ;
}
F_1 ( V_2 ) ;
F_9 ( V_2 -> V_13 . V_14 , V_7 , V_8 , V_11 & V_19 ? V_20 : V_21 ) ;
#if 0
snd_printk(KERN_DEBUG "address = 0x%x, count = 0x%x, dma_cmd = 0x%x\n",
address << 1, count, dma_cmd);
#endif
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( V_2 -> V_13 . V_15 ) {
V_12 = ( ( V_10 >> 16 ) & 0x000000f0 ) | ( V_10 & 0x0000000f ) ;
F_10 ( V_2 , V_22 , ( unsigned short ) ( V_10 >> 4 ) ) ;
F_3 ( V_2 , V_23 , ( unsigned char ) V_12 ) ;
} else
F_10 ( V_2 , V_22 , ( unsigned short ) ( V_10 >> 4 ) ) ;
F_3 ( V_2 , V_5 , V_11 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
}
static struct V_24 * F_11 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
if ( V_2 -> V_13 . V_26 ) {
V_25 = V_2 -> V_13 . V_26 ;
if ( V_2 -> V_13 . V_27 == V_25 ) {
V_2 -> V_13 . V_26 =
V_2 -> V_13 . V_27 = NULL ;
} else {
V_2 -> V_13 . V_26 = V_25 -> V_28 ;
}
} else if ( V_2 -> V_13 . V_29 ) {
V_25 = V_2 -> V_13 . V_29 ;
if ( V_2 -> V_13 . V_30 == V_25 ) {
V_2 -> V_13 . V_29 =
V_2 -> V_13 . V_30 = NULL ;
} else {
V_2 -> V_13 . V_29 = V_25 -> V_28 ;
}
} else {
V_25 = NULL ;
}
if ( V_25 ) {
V_2 -> V_13 . V_31 = V_25 -> V_32 ;
V_2 -> V_13 . V_33 = V_25 -> V_34 ;
}
return V_25 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
F_1 ( V_2 ) ;
if ( V_2 -> V_13 . V_31 )
V_2 -> V_13 . V_31 ( V_2 , V_2 -> V_13 . V_33 ) ;
F_13 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_13 . V_26 == NULL &&
V_2 -> V_13 . V_29 == NULL ) {
V_2 -> V_13 . V_31 = NULL ;
V_2 -> V_13 . V_36 &= ~ V_37 ;
F_14 ( & V_2 -> V_35 ) ;
return;
}
V_25 = F_11 ( V_2 ) ;
F_14 ( & V_2 -> V_35 ) ;
F_6 ( V_2 , V_25 -> V_6 , V_25 -> V_7 , V_25 -> V_8 , ( unsigned short ) V_25 -> V_9 ) ;
F_15 ( V_25 ) ;
#if 0
snd_printd(KERN_DEBUG "program dma (IRQ) - "
"addr = 0x%x, buffer = 0x%lx, count = 0x%x, cmd = 0x%x\n",
block->addr, block->buf_addr, block->count, block->cmd);
#endif
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_38 ) ;
V_2 -> V_13 . V_39 ++ ;
if ( V_2 -> V_13 . V_39 > 1 ) {
F_18 ( & V_2 -> V_38 ) ;
return 0 ;
}
V_2 -> V_13 . V_40 = F_12 ;
V_2 -> V_13 . V_26 =
V_2 -> V_13 . V_27 =
V_2 -> V_13 . V_29 =
V_2 -> V_13 . V_30 = NULL ;
F_18 ( & V_2 -> V_38 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
F_17 ( & V_2 -> V_38 ) ;
V_2 -> V_13 . V_39 -- ;
if ( ! V_2 -> V_13 . V_39 ) {
F_20 ( V_2 -> V_13 . V_14 ) ;
F_21 ( V_2 , V_41 ) ;
F_1 ( V_2 ) ;
while ( ( V_25 = V_2 -> V_13 . V_26 ) ) {
V_2 -> V_13 . V_26 = V_25 -> V_28 ;
F_15 ( V_25 ) ;
}
while ( ( V_25 = V_2 -> V_13 . V_29 ) ) {
V_2 -> V_13 . V_29 = V_25 -> V_28 ;
F_15 ( V_25 ) ;
}
V_2 -> V_13 . V_27 =
V_2 -> V_13 . V_30 = NULL ;
}
F_18 ( & V_2 -> V_38 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_24 * __block ,
int V_42 ,
int V_43 )
{
unsigned long V_3 ;
struct V_24 * V_25 ;
V_25 = F_23 ( sizeof( * V_25 ) , V_42 ? V_44 : V_45 ) ;
if ( V_25 == NULL ) {
F_24 ( V_46 L_3 ) ;
return - V_47 ;
}
* V_25 = * __block ;
V_25 -> V_28 = NULL ;
F_7 ( L_4 ,
V_25 -> V_6 , ( long ) V_25 -> V_48 , V_25 -> V_8 ,
V_25 -> V_9 ) ;
F_7 ( L_5 ,
( long ) V_2 -> V_13 . V_27 ) ;
F_7 ( L_6 ,
( long ) V_2 -> V_13 . V_26 ) ;
F_2 ( & V_2 -> V_35 , V_3 ) ;
if ( V_43 ) {
if ( V_2 -> V_13 . V_30 ) {
V_2 -> V_13 . V_30 -> V_28 = V_25 ;
V_2 -> V_13 . V_30 = V_25 ;
} else {
V_2 -> V_13 . V_29 =
V_2 -> V_13 . V_30 = V_25 ;
}
} else {
if ( V_2 -> V_13 . V_27 ) {
V_2 -> V_13 . V_27 -> V_28 = V_25 ;
V_2 -> V_13 . V_27 = V_25 ;
} else {
V_2 -> V_13 . V_26 =
V_2 -> V_13 . V_27 = V_25 ;
}
}
if ( ! ( V_2 -> V_13 . V_36 & V_37 ) ) {
V_2 -> V_13 . V_36 |= V_37 ;
V_25 = F_11 ( V_2 ) ;
F_5 ( & V_2 -> V_35 , V_3 ) ;
if ( V_25 == NULL )
return 0 ;
F_6 ( V_2 , V_25 -> V_6 , V_25 -> V_7 , V_25 -> V_8 , ( unsigned short ) V_25 -> V_9 ) ;
F_15 ( V_25 ) ;
return 0 ;
}
F_5 ( & V_2 -> V_35 , V_3 ) ;
return 0 ;
}
