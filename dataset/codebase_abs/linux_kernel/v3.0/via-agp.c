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
T_2 V_2 ;
struct V_3 * V_13 ;
V_13 = F_2 ( V_5 -> V_13 ) ;
F_6 ( V_5 -> V_8 , V_9 ,
V_13 -> V_11 ) ;
F_7 ( V_5 -> V_8 , V_16 , & V_2 ) ;
V_5 -> V_17 = ( V_2 & V_18 ) ;
F_8 ( V_5 -> V_8 , V_19 , 0x0000000f ) ;
F_8 ( V_5 -> V_8 , V_20 ,
( V_5 -> V_21 & 0xfffff000 ) | 3 ) ;
return 0 ;
}
static void F_9 ( void )
{
struct V_3 * V_12 ;
V_12 = F_2 ( V_5 -> V_12 ) ;
F_6 ( V_5 -> V_8 , V_9 ,
V_12 -> V_11 ) ;
}
static void F_10 ( struct V_22 * V_23 )
{
T_2 V_2 ;
F_7 ( V_5 -> V_8 , V_19 , & V_2 ) ;
V_2 |= ( 1 << 7 ) ;
F_8 ( V_5 -> V_8 , V_19 , V_2 ) ;
V_2 &= ~ ( 1 << 7 ) ;
F_8 ( V_5 -> V_8 , V_19 , V_2 ) ;
}
static int F_11 ( void )
{
int V_1 ;
T_3 V_2 ;
struct V_24 * V_4 ;
V_4 = F_12 ( V_5 -> V_6 -> V_7 ) ;
F_13 ( V_5 -> V_8 , V_25 , & V_2 ) ;
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
static int F_14 ( void )
{
T_2 V_2 ;
struct V_24 * V_13 ;
V_13 = F_12 ( V_5 -> V_13 ) ;
F_7 ( V_5 -> V_8 , V_16 , & V_2 ) ;
V_5 -> V_17 = ( V_2 & V_18 ) ;
F_8 ( V_5 -> V_8 , V_26 ,
V_5 -> V_21 & 0xfffff000 ) ;
F_7 ( V_5 -> V_8 , V_27 , & V_2 ) ;
F_8 ( V_5 -> V_8 , V_27 , V_2 | ( 3 << 7 ) ) ;
return 0 ;
}
static void F_15 ( void )
{
struct V_24 * V_12 ;
V_12 = F_12 ( V_5 -> V_12 ) ;
F_6 ( V_5 -> V_8 , V_9 , V_12 -> V_11 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
T_2 V_2 ;
F_7 ( V_5 -> V_8 , V_27 , & V_2 ) ;
F_8 ( V_5 -> V_8 , V_27 , V_2 & ~ ( 1 << 7 ) ) ;
F_8 ( V_5 -> V_8 , V_27 , V_2 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
T_1 V_30 ;
F_3 ( V_29 -> V_8 , V_31 , & V_30 ) ;
if ( ( V_30 & ( 1 << 1 ) ) == 0 )
V_29 -> V_6 = & V_32 ;
}
static int T_4 F_18 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_37 * V_38 = V_39 ;
struct V_28 * V_29 ;
int V_40 = 0 ;
T_1 V_41 ;
V_41 = F_19 ( V_34 , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
V_40 = V_36 - V_44 ;
F_4 (KERN_INFO PFX L_2 , devs[j].chipset_name) ;
V_29 = F_20 () ;
if ( ! V_29 )
return - V_45 ;
V_29 -> V_8 = V_34 ;
V_29 -> V_46 = V_41 ;
V_29 -> V_6 = & V_47 ;
if ( V_34 -> V_48 == V_49 ) {
if ( V_34 -> V_50 == V_51 ) {
F_4 (KERN_INFO PFX L_3 ) ;
F_17 ( V_29 ) ;
}
}
F_21 ( V_29 ) ;
if ( V_29 -> V_52 >= 3 )
F_17 ( V_29 ) ;
F_7 ( V_34 ,
V_29 -> V_46 + V_53 , & V_29 -> V_54 ) ;
F_22 ( V_34 , V_29 ) ;
return F_23 ( V_29 ) ;
}
static void T_5 F_24 ( struct V_33 * V_34 )
{
struct V_28 * V_29 = F_25 ( V_34 ) ;
F_26 ( V_29 ) ;
F_27 ( V_29 ) ;
}
static int F_28 ( struct V_33 * V_34 , T_6 V_55 )
{
F_29 ( V_34 ) ;
F_30 ( V_34 , V_56 ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_28 * V_29 = F_25 ( V_34 ) ;
F_30 ( V_34 , V_57 ) ;
F_32 ( V_34 ) ;
if ( V_29 -> V_6 == & V_32 )
return F_14 () ;
else if ( V_29 -> V_6 == & V_47 )
return F_5 () ;
return 0 ;
}
static int T_7 F_33 ( void )
{
if ( V_58 )
return - V_59 ;
return F_34 ( & V_60 ) ;
}
static void T_8 F_35 ( void )
{
F_36 ( & V_60 ) ;
}
