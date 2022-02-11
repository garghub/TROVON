static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
struct V_12 V_13 ;
const unsigned long V_14 = 1000000 / 33 ;
const T_1 V_15 [] = { 0x40 , 0x40 , 0x40 , 0x80 , 0x00 } ;
T_1 V_16 ;
int V_17 = V_18 + 2 * V_4 -> V_19 ;
struct V_3 * V_20 = F_3 ( V_4 ) ;
if ( F_4 ( V_4 , V_4 -> V_21 , & V_13 , V_14 , 0 ) < 0 ) {
F_5 (KERN_ERR DRV_NAME L_1 ) ;
return;
}
if ( V_2 -> V_22 && V_20 ) {
struct V_12 V_23 ;
F_4 ( V_20 , V_20 -> V_21 , & V_23 , V_14 , 1 ) ;
F_6 ( & V_23 , & V_13 , & V_13 , V_24 ) ;
}
if ( V_13 . V_25 > 16 ) {
V_13 . V_26 += V_13 . V_25 - 16 ;
V_13 . V_25 = 16 ;
}
if ( V_13 . V_26 > 16 )
V_13 . V_26 = 16 ;
if ( V_13 . V_25 > 1 )
V_13 . V_25 -- ;
else
V_13 . V_25 = 15 ;
if ( V_13 . V_27 > 4 )
V_13 . V_27 = 0xC0 ;
else
V_13 . V_27 = V_15 [ V_13 . V_27 ] ;
if ( V_2 -> V_22 == 0 ) {
V_13 . V_26 &= 0x0F ;
F_7 ( V_9 , V_17 , & V_16 ) ;
V_16 &= 0x3F ;
V_16 |= V_13 . V_27 ;
F_8 ( V_9 , V_17 , V_16 ) ;
F_8 ( V_9 , V_17 + 1 , ( V_13 . V_26 << 4 ) | V_13 . V_25 ) ;
} else {
F_7 ( V_9 , V_28 , & V_16 ) ;
V_16 &= 0x3F ;
V_16 |= V_13 . V_27 ;
F_8 ( V_9 , V_28 , V_16 ) ;
V_6 -> V_29 [ V_4 -> V_19 ] = ( V_13 . V_26 << 4 ) | V_13 . V_25 ;
}
}
static unsigned int F_9 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_3 * V_4 = V_31 -> V_11 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_2 -> V_22 != 0 && V_4 -> V_19 != V_6 -> V_32 ) {
F_8 ( V_9 , V_33 , V_6 -> V_29 [ V_4 -> V_19 ] ) ;
V_6 -> V_32 = V_4 -> V_19 ;
}
return F_10 ( V_31 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
struct V_5 * V_6 ;
V_6 = F_12 ( & V_9 -> V_11 , sizeof( struct V_5 ) , V_34 ) ;
if ( V_6 == NULL )
return - V_35 ;
V_6 -> V_32 = - 1 ;
V_2 -> V_7 = V_6 ;
return 0 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
int V_36 = V_2 -> V_22 ? V_28 : V_37 ;
T_1 V_38 , V_39 = V_2 -> V_22 ? 0x10 : 0x04 ;
F_7 ( V_9 , V_36 , & V_38 ) ;
return V_38 & V_39 ;
}
static void F_14 ( struct V_8 * V_9 )
{
T_1 V_40 ;
F_8 ( V_9 , 0x5B , 0x00 ) ;
F_8 ( V_9 , V_41 , 0 ) ;
F_8 ( V_9 , V_42 , 0x40 ) ;
F_7 ( V_9 , V_43 , & V_40 ) ;
F_8 ( V_9 , V_43 , V_40 | 0xC0 ) ;
F_7 ( V_9 , V_28 , & V_40 ) ;
V_40 |= 0x0C ;
F_8 ( V_9 , V_28 , V_40 ) ;
}
static int F_15 ( struct V_8 * V_9 , const struct V_44 * V_45 )
{
static const struct V_46 V_47 = {
. V_48 = V_49 ,
. V_50 = V_51 ,
. V_52 = & V_53
} ;
const struct V_46 * V_54 [] = { & V_47 , NULL } ;
int V_55 ;
V_55 = F_16 ( V_9 ) ;
if ( V_55 )
return V_55 ;
F_14 ( V_9 ) ;
return F_17 ( V_9 , V_54 , & V_56 , NULL , 0 ) ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_57 * V_10 = F_19 ( V_9 ) ;
int V_55 ;
V_55 = F_20 ( V_9 ) ;
if ( V_55 )
return V_55 ;
F_14 ( V_9 ) ;
F_21 ( V_10 ) ;
return 0 ;
}
