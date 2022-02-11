static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 -> V_7 , V_5 ) ;
if ( V_4 < 8 ) {
F_3 ( V_3 , V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_8 ) ;
F_3 ( V_3 , V_9 ) ;
}
F_4 ( & V_6 -> V_7 , V_5 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_5 ;
T_1 V_10 ;
F_2 ( & V_6 -> V_7 , V_5 ) ;
if ( V_4 < 8 ) {
V_10 = F_6 ( V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_8 ) ;
V_10 = F_6 ( V_9 ) ;
}
F_4 ( & V_6 -> V_7 , V_5 ) ;
return V_10 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_11 )
F_9 ( V_2 -> V_11 , V_2 ) ;
}
static int F_10 ( struct V_12 * V_13 )
{
V_14 = V_13 ;
F_11 ( V_13 ) ;
return 0 ;
}
static void F_12 ( struct V_12 * V_13 )
{
F_13 ( V_13 ) ;
}
static void F_14 ( struct V_12 * V_13 )
{
F_12 ( V_13 ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
F_16 ( L_1 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
F_16 ( L_2 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_15 , void * V_16 )
{
int V_17 , V_10 ;
V_15 -> V_18 [ 0 ] -> V_5 &= ~ V_19 ;
V_15 -> V_18 [ 0 ] -> V_5 |= V_20 ;
for ( V_17 = 0x000 ; V_17 < 0x400 ; V_17 += 0x20 ) {
V_15 -> V_18 [ 0 ] -> V_21 = V_17 ;
V_10 = F_19 ( V_15 ) ;
if ( ! V_10 )
return 0 ;
}
return - V_22 ;
}
static void F_11 ( struct V_12 * V_13 )
{
int V_10 ;
F_16 ( L_3 , V_13 ) ;
V_13 -> V_23 |= V_24 | V_25 ;
V_10 = F_20 ( V_13 , F_18 , NULL ) ;
if ( V_10 ) {
F_21 ( & V_13 -> V_2 , L_4 ) ;
return;
}
if ( ! V_13 -> V_11 )
F_22 ( & V_13 -> V_2 , L_5 ) ;
V_10 = F_23 ( V_13 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_12 * V_13 ;
unsigned int V_11 ;
int V_10 ;
F_16 ( L_6 , V_2 , V_27 ) ;
V_13 = V_14 ;
if ( ! V_13 )
return - V_28 ;
V_2 -> V_29 = & V_30 ;
V_2 -> V_31 = V_13 -> V_18 [ 0 ] -> V_21 ;
V_11 = V_13 -> V_11 ;
F_25 ( L_7 ,
V_2 -> V_32 , V_2 -> V_29 -> V_33 , V_2 -> V_31 , V_11 ) ;
#if 0
{
int i;
printk(" board fingerprint:");
for (i = 0; i < 32; i += 2) {
printk(" %04x %02x", inw(dev->iobase + i),
inb(dev->iobase + i + 1));
}
printk("\n");
printk(" board fingerprint (windowed):");
for (i = 0; i < 10; i++)
printk(" 0x%04x", win_in(i));
printk("\n");
}
#endif
V_2 -> V_34 = V_35 + F_26 ( V_2 , V_13 ) ;
F_25 ( L_8 , V_36 . V_37 ) ;
V_2 -> V_38 = V_36 . V_37 ;
V_10 = F_27 ( V_11 , V_39 , V_40 ,
L_9 , V_2 ) ;
if ( V_10 < 0 ) {
F_25 ( L_10 ) ;
return - V_41 ;
}
V_2 -> V_11 = V_11 ;
V_10 = F_28 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_42 = & F_1 ;
V_6 -> V_43 = & F_5 ;
V_6 -> V_44 = & V_45 ;
V_6 -> V_46 = & V_47 ;
V_10 = F_29 ( V_2 , V_27 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
if ( V_35 [ V_48 ] . V_50 == V_13 -> V_51 )
return V_48 ;
}
F_25 ( L_11 , V_13 -> V_51 ) ;
return 0 ;
}
int F_30 ( void )
{
F_31 ( & V_52 ) ;
F_32 ( & V_30 ) ;
return 0 ;
}
void F_33 ( void )
{
F_34 ( & V_52 ) ;
#if 0
while (cur_dev != NULL)
cs_detach(cur_dev->handle);
#endif
F_35 ( & V_30 ) ;
}
