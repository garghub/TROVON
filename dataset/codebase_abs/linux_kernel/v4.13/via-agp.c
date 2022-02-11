static int F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
struct V_3 * V_4 ;
V_4 = F_2 ( V_5 -> V_6 -> V_7 ) ;
F_3 ( V_5 -> V_8 , V_9 , & V_2 ) ;
for ( V_1 = 0 ; V_1 < V_5 -> V_6 -> V_10 ; V_1 ++ ) {
if ( V_2 == V_4 [ V_1 ] . V_11 ) {
V_5 -> V_12 =
V_5 -> V_13 = ( void * ) ( V_4 + V_1 ) ;
V_5 -> V_14 = V_1 ;
return V_4 [ V_1 ] . V_15 ;
}
}
F_4 (KERN_ERR PFX L_1 , temp) ;
return 0 ;
}
static int F_5 ( void )
{
struct V_3 * V_13 ;
V_13 = F_2 ( V_5 -> V_13 ) ;
F_6 ( V_5 -> V_8 , V_9 ,
V_13 -> V_11 ) ;
V_5 -> V_16 = F_7 ( V_5 -> V_8 ,
V_17 ) ;
F_8 ( V_5 -> V_8 , V_18 , 0x0000000f ) ;
F_8 ( V_5 -> V_8 , V_19 ,
( V_5 -> V_20 & 0xfffff000 ) | 3 ) ;
return 0 ;
}
static void F_9 ( void )
{
struct V_3 * V_12 ;
V_12 = F_2 ( V_5 -> V_12 ) ;
F_6 ( V_5 -> V_8 , V_9 ,
V_12 -> V_11 ) ;
}
static void F_10 ( struct V_21 * V_22 )
{
T_2 V_2 ;
F_11 ( V_5 -> V_8 , V_18 , & V_2 ) ;
V_2 |= ( 1 << 7 ) ;
F_8 ( V_5 -> V_8 , V_18 , V_2 ) ;
V_2 &= ~ ( 1 << 7 ) ;
F_8 ( V_5 -> V_8 , V_18 , V_2 ) ;
}
static int F_12 ( void )
{
int V_1 ;
T_3 V_2 ;
struct V_23 * V_4 ;
V_4 = F_13 ( V_5 -> V_6 -> V_7 ) ;
F_14 ( V_5 -> V_8 , V_24 , & V_2 ) ;
V_2 &= 0xfff ;
for ( V_1 = 0 ; V_1 < V_5 -> V_6 -> V_10 ; V_1 ++ ) {
if ( V_2 == V_4 [ V_1 ] . V_11 ) {
V_5 -> V_12 =
V_5 -> V_13 = ( void * ) ( V_4 + V_1 ) ;
V_5 -> V_14 = V_1 ;
return V_4 [ V_1 ] . V_15 ;
}
}
return 0 ;
}
static int F_15 ( void )
{
T_2 V_2 ;
struct V_23 * V_13 ;
V_13 = F_13 ( V_5 -> V_13 ) ;
V_5 -> V_16 = F_7 ( V_5 -> V_8 ,
V_17 ) ;
F_8 ( V_5 -> V_8 , V_25 ,
V_5 -> V_20 & 0xfffff000 ) ;
F_11 ( V_5 -> V_8 , V_26 , & V_2 ) ;
F_8 ( V_5 -> V_8 , V_26 , V_2 | ( 3 << 7 ) ) ;
return 0 ;
}
static void F_16 ( void )
{
struct V_23 * V_12 ;
V_12 = F_13 ( V_5 -> V_12 ) ;
F_6 ( V_5 -> V_8 , V_9 , V_12 -> V_11 ) ;
}
static void F_17 ( struct V_21 * V_22 )
{
T_2 V_2 ;
F_11 ( V_5 -> V_8 , V_26 , & V_2 ) ;
F_8 ( V_5 -> V_8 , V_26 , V_2 & ~ ( 1 << 7 ) ) ;
F_8 ( V_5 -> V_8 , V_26 , V_2 ) ;
}
static void F_18 ( struct V_27 * V_28 )
{
T_1 V_29 ;
F_3 ( V_28 -> V_8 , V_30 , & V_29 ) ;
if ( ( V_29 & ( 1 << 1 ) ) == 0 )
V_28 -> V_6 = & V_31 ;
}
static int F_19 ( struct V_32 * V_33 , const struct V_34 * V_35 )
{
struct V_36 * V_37 = V_38 ;
struct V_27 * V_28 ;
int V_39 = 0 ;
T_1 V_40 ;
V_40 = F_20 ( V_33 , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
V_39 = V_35 - V_43 ;
F_4 (KERN_INFO PFX L_2 , devs[j].chipset_name) ;
V_28 = F_21 () ;
if ( ! V_28 )
return - V_44 ;
V_28 -> V_8 = V_33 ;
V_28 -> V_45 = V_40 ;
V_28 -> V_6 = & V_46 ;
if ( V_33 -> V_47 == V_48 ) {
if ( V_33 -> V_49 == V_50 ) {
F_4 (KERN_INFO PFX L_3 ) ;
F_18 ( V_28 ) ;
}
}
F_22 ( V_28 ) ;
if ( V_28 -> V_51 >= 3 )
F_18 ( V_28 ) ;
F_11 ( V_33 ,
V_28 -> V_45 + V_52 , & V_28 -> V_53 ) ;
F_23 ( V_33 , V_28 ) ;
return F_24 ( V_28 ) ;
}
static void F_25 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = F_26 ( V_33 ) ;
F_27 ( V_28 ) ;
F_28 ( V_28 ) ;
}
static int F_29 ( struct V_32 * V_33 , T_4 V_54 )
{
F_30 ( V_33 ) ;
F_31 ( V_33 , V_55 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = F_26 ( V_33 ) ;
F_31 ( V_33 , V_56 ) ;
F_33 ( V_33 ) ;
if ( V_28 -> V_6 == & V_31 )
return F_15 () ;
else if ( V_28 -> V_6 == & V_46 )
return F_5 () ;
return 0 ;
}
static int T_5 F_34 ( void )
{
if ( V_57 )
return - V_58 ;
return F_35 ( & V_59 ) ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_59 ) ;
}
