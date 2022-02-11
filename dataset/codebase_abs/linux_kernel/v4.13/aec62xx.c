static T_1 F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
for ( ; V_3 -> V_4 ; V_3 ++ )
if ( V_3 -> V_4 == V_1 ) {
return V_3 -> V_5 ;
}
return V_3 -> V_5 ;
}
static T_1 F_2 ( T_1 V_1 , struct V_2 * V_3 )
{
for ( ; V_3 -> V_4 ; V_3 ++ )
if ( V_3 -> V_4 == V_1 ) {
return V_3 -> V_6 ;
}
return V_3 -> V_6 ;
}
static void F_3 ( T_2 * V_7 , T_3 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 -> V_10 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_2 * V_13 = V_12 -> V_14 ;
T_4 V_15 = 0 ;
T_1 V_16 = 0 , V_17 = 0 ;
T_1 V_18 = 0 , V_19 = 0 , V_20 = 0 ;
const T_1 V_1 = V_8 -> V_21 ;
unsigned long V_22 ;
F_6 ( V_22 ) ;
F_7 ( V_10 , 0x40 | ( 2 * V_8 -> V_23 ) , & V_15 ) ;
V_18 = F_1 ( V_1 , V_13 ) ;
V_15 = ( ( V_18 & 0xf0 ) << 4 ) | ( V_18 & 0xf ) ;
F_8 ( V_10 , 0x40 | ( 2 * V_8 -> V_23 ) , V_15 ) ;
V_19 = 0x00 ;
V_20 = 0x00 ;
F_9 ( V_10 , 0x54 , & V_16 ) ;
V_19 = ( ( 0x00 << ( 2 * V_8 -> V_23 ) ) | ( V_16 & ~ ( 3 << ( 2 * V_8 -> V_23 ) ) ) ) ;
V_17 = F_2 ( V_1 , V_13 ) ;
V_20 = ( ( V_17 << ( 2 * V_8 -> V_23 ) ) | ( V_19 & ~ ( 3 << ( 2 * V_8 -> V_23 ) ) ) ) ;
F_10 ( V_10 , 0x54 , V_20 ) ;
F_11 ( V_22 ) ;
}
static void F_12 ( T_2 * V_7 , T_3 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 -> V_10 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_2 * V_13 = V_12 -> V_14 ;
T_1 V_24 = V_8 -> V_23 & 1 ;
T_1 V_19 = 0 , V_20 = 0 ;
T_1 V_16 = 0 , V_25 = 0 , V_17 = 0 ;
const T_1 V_1 = V_8 -> V_21 ;
unsigned long V_22 ;
F_6 ( V_22 ) ;
F_9 ( V_10 , 0x40 | V_8 -> V_23 , & V_25 ) ;
V_25 = F_1 ( V_1 , V_13 ) ;
F_10 ( V_10 , 0x40 | V_8 -> V_23 , V_25 ) ;
F_9 ( V_10 , ( 0x44 | V_7 -> V_26 ) , & V_16 ) ;
V_19 = ( ( 0x00 << ( 4 * V_24 ) ) | ( V_16 & ~ ( 7 << ( 4 * V_24 ) ) ) ) ;
V_17 = F_2 ( V_1 , V_13 ) ;
V_20 = ( ( V_17 << ( 4 * V_24 ) ) | ( V_19 & ~ ( 7 << ( 4 * V_24 ) ) ) ) ;
F_10 ( V_10 , ( 0x44 | V_7 -> V_26 ) , V_20 ) ;
F_11 ( V_22 ) ;
}
static void F_13 ( T_2 * V_7 , T_3 * V_8 )
{
V_8 -> V_21 = V_8 -> V_27 ;
V_7 -> V_28 -> V_29 ( V_7 , V_8 ) ;
}
static int F_14 ( struct V_9 * V_10 )
{
if ( ( V_10 -> V_30 == V_31 ) ||
( V_10 -> V_30 == V_32 ) ) {
T_1 V_33 = 0 , V_34 = 0 ;
F_9 ( V_10 , 0x49 , & V_33 ) ;
F_10 ( V_10 , 0x49 , V_33 & ~ 0x30 ) ;
F_9 ( V_10 , 0x4a , & V_34 ) ;
F_10 ( V_10 , 0x4a , V_34 & ~ 0x01 ) ;
F_9 ( V_10 , 0x4a , & V_34 ) ;
F_10 ( V_10 , 0x4a , V_34 | 0x80 ) ;
}
return 0 ;
}
static T_1 F_15 ( T_2 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 -> V_10 ) ;
T_1 V_35 = 0 , V_36 = V_7 -> V_26 ? 0x02 : 0x01 ;
F_9 ( V_10 , 0x49 , & V_35 ) ;
return ( V_35 & V_36 ) ? V_37 : V_38 ;
}
static int F_16 ( struct V_9 * V_10 , const struct V_39 * V_40 )
{
const struct V_2 * V_13 ;
struct V_41 V_42 ;
T_1 V_43 = V_40 -> V_44 ;
int V_45 = V_46 ? V_46 : 33 ;
int V_47 ;
if ( V_45 <= 33 )
V_13 = V_48 ;
else
V_13 = V_49 ;
V_47 = F_17 ( V_10 ) ;
if ( V_47 )
return V_47 ;
V_42 = V_50 [ V_43 ] ;
if ( V_43 == 3 || V_43 == 4 ) {
unsigned long V_51 = F_18 ( V_10 , 4 ) ;
if ( F_19 ( V_51 + 2 ) & 0x10 ) {
F_20 (KERN_INFO DRV_NAME L_1
L_2 , pci_name(dev), (idx == 4) ? L_3 : L_4 ) ;
V_42 . V_52 = V_53 ;
}
}
V_47 = F_21 ( V_10 , & V_42 , ( void * ) V_13 ) ;
if ( V_47 )
F_22 ( V_10 ) ;
return V_47 ;
}
static void F_23 ( struct V_9 * V_10 )
{
F_24 ( V_10 ) ;
F_22 ( V_10 ) ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_54 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_54 ) ;
}
