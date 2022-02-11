static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
if ( ! ( F_2 ( V_2 ) & 0x01 ) )
return 1 ;
F_2 ( V_2 ) ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 | 0x01 , F_4 ( V_2 ) ) ;
F_3 ( V_3 & 0xfe , F_4 ( V_2 ) ) ;
V_3 = F_2 ( V_2 ) ;
return ! ( V_3 & 0x01 ) ;
}
void F_5 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
V_7 -> V_8 . V_9 . V_10 = 0xc | ( V_5 -> V_11 ? 0x10 : 0x0 ) ;
}
void F_6 ( struct V_1 * V_12 , struct V_6 * V_7 )
{
V_7 -> V_8 . V_9 . V_10 = F_7 ( F_8 ( V_12 ) ) ;
}
void F_9 ( struct V_1 * V_12 , struct V_6 * V_7 )
{
F_3 ( V_7 -> V_8 . V_9 . V_10 , F_8 ( V_12 ) ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned char V_3 , V_13 ;
F_1 ( V_2 ) ;
V_13 = 0xc ;
F_3 ( V_13 , F_8 ( V_2 ) ) ;
V_3 = F_7 ( F_8 ( V_2 ) ) ;
if ( ( V_3 & 0xf ) == V_13 ) {
V_13 = 0xe ;
F_3 ( V_13 , F_8 ( V_2 ) ) ;
V_3 = F_7 ( F_8 ( V_2 ) ) ;
F_3 ( 0xc , F_8 ( V_2 ) ) ;
if ( ( V_3 & 0xf ) == V_13 )
return V_14 ;
}
V_13 = 0xaa ;
F_11 ( V_2 , V_13 ) ;
V_3 = F_12 ( V_2 ) ;
if ( V_3 == V_13 ) {
V_13 = 0x55 ;
F_11 ( V_2 , V_13 ) ;
V_3 = F_12 ( V_2 ) ;
if ( V_3 == V_13 )
return V_14 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
F_1 ( V_2 ) ;
F_14 ( V_2 ) ;
F_11 ( V_2 , 0x55 ) ;
if ( F_12 ( V_2 ) != 0x55 ) V_15 ++ ;
F_11 ( V_2 , 0xaa ) ;
if ( F_12 ( V_2 ) != 0xaa ) V_15 ++ ;
F_15 ( V_2 ) ;
if ( V_15 ) {
V_2 -> V_16 |= V_17 ;
} else {
struct V_18 * V_19 = V_2 -> V_20 ;
V_19 -> V_21 &= ~ 0x20 ;
}
return V_15 ;
}
struct V_1 * F_16 ( unsigned long V_22 ,
unsigned long V_23 , int V_24 ,
int V_25 , struct V_26 * V_5 )
{
struct V_18 * V_19 ;
struct V_27 * V_28 ;
struct V_1 V_29 ;
struct V_1 * V_12 = & V_29 ;
V_19 = F_17 ( sizeof ( struct V_18 ) , V_30 ) ;
if ( ! V_19 ) {
F_18 ( V_31 L_1 , V_22 ) ;
return NULL ;
}
V_28 = F_19 ( sizeof ( struct V_27 ) , V_30 ) ;
if ( ! V_28 ) {
F_18 ( V_31 L_2 ,
V_22 ) ;
F_20 ( V_19 ) ;
return NULL ;
}
memcpy ( V_28 , & V_32 , sizeof ( struct V_27 ) ) ;
V_19 -> V_10 = 0xc ;
V_19 -> V_21 = 0xff ;
V_19 -> V_33 = 0 ;
V_19 -> V_34 = 0 ;
V_19 -> V_5 = V_5 ;
V_12 -> V_22 = V_22 ;
V_12 -> V_23 = V_23 ;
V_12 -> V_24 = V_24 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_16 = V_14 | V_35 ;
V_12 -> V_28 = V_28 ;
V_12 -> V_20 = V_19 ;
V_12 -> V_36 = V_12 ;
if ( ! F_10 ( V_12 ) ) {
F_20 ( V_19 ) ;
F_20 ( V_28 ) ;
return NULL ;
}
F_13 ( V_12 ) ;
if ( ! ( V_12 = F_21 ( V_22 , V_37 ,
V_38 , V_28 ) ) ) {
F_20 ( V_19 ) ;
F_20 ( V_28 ) ;
return NULL ;
}
V_12 -> V_23 = V_23 ;
V_12 -> V_16 = V_29 . V_16 ;
V_12 -> V_39 = ( V_12 -> V_16 & V_40 ) ? 8 : 3 ;
V_12 -> V_20 = V_19 ;
F_18 ( V_41 L_3 , V_12 -> V_42 , V_12 -> V_22 ) ;
V_12 -> V_24 = V_24 ;
if ( V_12 -> V_24 == V_43 ) {
V_12 -> V_24 = V_37 ;
}
if ( V_12 -> V_24 != V_37 ) {
F_18 ( L_4 , V_12 -> V_24 ) ;
if ( V_12 -> V_25 == V_44 ) {
V_12 -> V_25 = V_38 ;
}
}
if ( V_12 -> V_25 == V_44 )
V_12 -> V_25 = V_38 ;
F_18 ( L_5 ) ;
#define F_22 ( T_1 ) {if(p->modes&PARPORT_MODE_##x){printk("%s%s",f?",":"",#x);f++;}}
{
int V_45 = 0 ;
F_22 ( V_46 ) ;
F_22 ( V_47 ) ;
F_22 (COMPAT)
F_22 ( V_48 ) ;
}
#undef F_22
F_18 ( L_6 ) ;
if ( V_12 -> V_24 != V_37 ) {
if ( F_23 ( V_12 -> V_24 , V_49 ,
0 , V_12 -> V_42 , V_12 ) ) {
F_18 ( V_50 L_7
L_8 ,
V_12 -> V_42 , V_12 -> V_24 ) ;
V_12 -> V_24 = V_37 ;
V_12 -> V_25 = V_38 ;
}
}
F_11 ( V_12 , 0 ) ;
F_15 ( V_12 ) ;
F_24 ( V_12 ) ;
return V_12 ;
}
static int F_25 ( struct V_51 * V_5 )
{
struct V_1 * V_12 ;
unsigned long V_52 ;
if ( ! V_5 -> V_24 ) {
F_18 ( V_50 L_9 ,
( unsigned long long ) V_5 -> V_53 . V_54 ) ;
return - V_55 ;
}
V_52 = V_5 -> V_53 . V_54 + V_56 ;
if ( V_57 . V_58 > V_59 && ! F_26 ( V_52 + 4 ) ) {
F_18 ( L_10 , V_60 ) ;
F_3 ( ( 0x10 + 0x20 ) , V_52 + 4 ) ;
} else {
F_18 ( L_11 , V_60 ) ;
}
V_12 = F_16 ( V_52 , 0 , V_5 -> V_24 ,
V_38 , NULL ) ;
if ( V_12 )
V_61 ++ ;
F_27 ( & V_5 -> V_5 , V_12 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_5 )
{
struct V_1 * V_12 = F_29 ( & V_5 -> V_5 ) ;
if ( V_12 ) {
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_27 * V_28 = V_12 -> V_28 ;
F_30 ( V_12 ) ;
if ( V_12 -> V_25 != V_38 )
F_31 ( V_12 -> V_25 ) ;
if ( V_12 -> V_24 != V_37 )
F_32 ( V_12 -> V_24 , V_12 ) ;
if ( V_19 -> V_33 )
F_33 ( V_19 -> V_5 , V_62 ,
V_19 -> V_33 ,
V_19 -> V_34 ) ;
F_20 ( V_12 -> V_20 ) ;
F_34 ( V_12 ) ;
F_20 ( V_28 ) ;
}
return 0 ;
}
int F_35 ( void )
{
return F_36 ( & V_63 ) ;
}
static void F_37 ( void )
{
F_38 ( & V_63 ) ;
}
