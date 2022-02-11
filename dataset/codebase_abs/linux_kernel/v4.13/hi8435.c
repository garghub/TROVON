static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
V_3 |= V_5 ;
return F_2 ( V_2 -> V_6 , & V_3 , 1 , V_4 , 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_7 ;
T_3 V_8 ;
V_3 |= V_5 ;
V_7 = F_2 ( V_2 -> V_6 , & V_3 , 1 , & V_8 , 2 ) ;
* V_4 = F_4 ( V_8 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_4 * V_4 )
{
int V_7 ;
T_5 V_8 ;
V_3 |= V_5 ;
V_7 = F_2 ( V_2 -> V_6 , & V_3 , 1 , & V_8 , 4 ) ;
* V_4 = F_6 ( V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
V_2 -> V_9 [ 0 ] = V_3 | V_10 ;
V_2 -> V_9 [ 1 ] = V_4 ;
return F_8 ( V_2 -> V_6 , V_2 -> V_9 , 2 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_9 [ 0 ] = V_3 | V_10 ;
V_2 -> V_9 [ 1 ] = ( V_4 >> 8 ) & 0xff ;
V_2 -> V_9 [ 2 ] = V_4 & 0xff ;
return F_8 ( V_2 -> V_6 , V_2 -> V_9 , 3 ) ;
}
static int F_10 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
int * V_4 , int * V_15 , long V_16 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_4 V_17 ;
int V_7 ;
switch ( V_16 ) {
case V_18 :
V_7 = F_5 ( V_2 , V_19 , & V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = ! ! ( V_17 & F_12 ( V_14 -> V_20 ) ) ;
return V_21 ;
default:
return - V_22 ;
}
}
static int F_13 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_23 type ,
enum V_24 V_25 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return ! ! ( V_2 -> V_26 & F_12 ( V_14 -> V_20 ) ) ;
}
static int F_14 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_23 type ,
enum V_24 V_25 , int V_27 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_4 V_17 ;
if ( V_27 ) {
V_7 = F_5 ( V_2 , V_19 , & V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_17 & F_12 ( V_14 -> V_20 ) )
V_2 -> V_28 |= F_12 ( V_14 -> V_20 ) ;
else
V_2 -> V_28 &= ~ F_12 ( V_14 -> V_20 ) ;
V_2 -> V_26 |= F_12 ( V_14 -> V_20 ) ;
} else
V_2 -> V_26 &= ~ F_12 ( V_14 -> V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_23 type ,
enum V_24 V_25 ,
enum V_29 V_30 ,
int * V_4 , int * V_15 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_31 , V_32 ;
T_2 V_3 ;
V_7 = F_1 ( V_2 , V_33 , & V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_31 = ! ! ( V_32 & F_12 ( V_14 -> V_20 / 8 ) ) ;
V_7 = F_3 ( V_2 , V_31 ? V_34 :
V_35 , & V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_25 == V_36 )
* V_4 = ( ( V_3 & 0xff ) - ( V_3 >> 8 ) ) / 2 ;
else if ( V_25 == V_37 )
* V_4 = ( ( V_3 & 0xff ) + ( V_3 >> 8 ) ) / 2 ;
return V_21 ;
}
static int F_16 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_23 type ,
enum V_24 V_25 ,
enum V_29 V_30 ,
int V_4 , int V_15 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_31 , V_32 ;
T_2 V_3 ;
V_7 = F_1 ( V_2 , V_33 , & V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_31 = ! ! ( V_32 & F_12 ( V_14 -> V_20 / 8 ) ) ;
V_7 = F_3 ( V_2 , V_31 ? V_34 :
V_35 , & V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_25 == V_36 ) {
if ( V_4 < 2 || V_4 > 21 || ( V_4 + 2 ) > V_2 -> V_38 [ V_31 ] )
return - V_22 ;
if ( V_4 == V_2 -> V_39 [ V_31 ] )
return 0 ;
V_2 -> V_39 [ V_31 ] = V_4 ;
if ( ( V_2 -> V_38 [ V_31 ] - V_2 -> V_39 [ V_31 ] ) % 2 )
V_2 -> V_38 [ V_31 ] -- ;
} else if ( V_25 == V_37 ) {
if ( V_4 < 3 || V_4 > 22 || V_4 < ( V_2 -> V_39 [ V_31 ] + 2 ) )
return - V_22 ;
if ( V_4 == V_2 -> V_38 [ V_31 ] )
return 0 ;
V_2 -> V_38 [ V_31 ] = V_4 ;
if ( ( V_2 -> V_38 [ V_31 ] - V_2 -> V_39 [ V_31 ] ) % 2 )
V_2 -> V_39 [ V_31 ] ++ ;
}
F_17 ( & V_2 -> V_40 ) ;
V_7 = F_3 ( V_2 , V_31 ? V_34 :
V_35 , & V_3 ) ;
if ( V_7 < 0 ) {
F_18 ( & V_2 -> V_40 ) ;
return V_7 ;
}
V_3 = V_2 -> V_38 [ V_31 ] - V_2 -> V_39 [ V_31 ] ;
V_3 <<= 8 ;
V_3 |= ( V_2 -> V_38 [ V_31 ] + V_2 -> V_39 [ V_31 ] ) ;
V_7 = F_9 ( V_2 , V_31 ? V_34 :
V_35 , V_3 ) ;
F_18 ( & V_2 -> V_40 ) ;
return V_7 ;
}
static int F_19 ( struct V_11 * V_12 ,
unsigned V_3 , unsigned V_41 ,
unsigned * V_42 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_4 ;
if ( V_42 != NULL ) {
V_7 = F_1 ( V_2 , V_3 , & V_4 ) ;
* V_42 = V_4 ;
} else {
V_4 = ( T_1 ) V_41 ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
}
return V_7 ;
}
static int F_20 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_3 ;
V_7 = F_1 ( V_2 , V_33 , & V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ! ( V_3 & F_12 ( V_14 -> V_20 / 8 ) ) ;
}
static int F_21 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
unsigned int V_31 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_3 ;
F_17 ( & V_2 -> V_40 ) ;
V_7 = F_1 ( V_2 , V_33 , & V_3 ) ;
if ( V_7 < 0 ) {
F_18 ( & V_2 -> V_40 ) ;
return V_7 ;
}
V_3 &= ~ F_12 ( V_14 -> V_20 / 8 ) ;
if ( V_31 )
V_3 |= F_12 ( V_14 -> V_20 / 8 ) ;
V_7 = F_7 ( V_2 , V_33 , V_3 ) ;
F_18 ( & V_2 -> V_40 ) ;
return V_7 ;
}
static void F_22 ( struct V_11 * V_12 , unsigned int V_4 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
enum V_24 V_25 ;
unsigned int V_43 ;
unsigned int V_44 = V_2 -> V_28 ^ V_4 ;
if ( ! V_44 )
return;
F_23 (i, &priv->event_scan_mask, 32 ) {
if ( V_44 & F_12 ( V_43 ) ) {
V_25 = V_4 & F_12 ( V_43 ) ? V_37 :
V_36 ;
F_24 ( V_12 ,
F_25 ( V_45 , V_43 ,
V_46 , V_25 ) ,
F_26 ( V_12 ) ) ;
}
}
V_2 -> V_28 = V_4 ;
}
static T_6 F_27 ( int V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
struct V_11 * V_12 = V_50 -> V_51 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_4 V_4 ;
int V_7 ;
V_7 = F_5 ( V_2 , V_19 , & V_4 ) ;
if ( V_7 < 0 )
goto V_52;
F_22 ( V_12 , V_4 ) ;
V_52:
F_28 ( V_12 -> V_53 ) ;
return V_54 ;
}
static int F_29 ( struct V_55 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
int V_7 ;
V_12 = F_30 ( & V_6 -> V_58 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_59 ;
V_2 = F_11 ( V_12 ) ;
V_2 -> V_6 = V_6 ;
V_57 = F_31 ( & V_6 -> V_58 , NULL , V_60 ) ;
if ( F_32 ( V_57 ) ) {
F_7 ( V_2 , V_61 , V_62 ) ;
F_7 ( V_2 , V_61 , 0 ) ;
} else {
F_33 ( 5 ) ;
F_34 ( V_57 , 1 ) ;
}
F_35 ( V_6 , V_12 ) ;
F_36 ( & V_2 -> V_40 ) ;
V_12 -> V_58 . V_63 = & V_6 -> V_58 ;
V_12 -> V_58 . V_64 = V_6 -> V_58 . V_64 ;
V_12 -> V_65 = F_37 ( V_6 ) -> V_65 ;
V_12 -> V_66 = V_67 ;
V_12 -> V_30 = & V_68 ;
V_12 -> V_69 = V_70 ;
V_12 -> V_71 = F_38 ( V_70 ) ;
V_2 -> V_26 = ~ ( 0 ) ;
V_2 -> V_39 [ 0 ] = V_2 -> V_39 [ 1 ] = 2 ;
V_2 -> V_38 [ 0 ] = V_2 -> V_38 [ 1 ] = 4 ;
F_9 ( V_2 , V_35 , 0x206 ) ;
F_9 ( V_2 , V_34 , 0x206 ) ;
V_7 = F_39 ( V_12 , NULL , F_27 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_40 ( V_12 ) ;
if ( V_7 < 0 ) {
F_41 ( & V_6 -> V_58 , L_1 ) ;
goto V_72;
}
return 0 ;
V_72:
F_42 ( V_12 ) ;
return V_7 ;
}
static int F_43 ( struct V_55 * V_6 )
{
struct V_11 * V_12 = F_44 ( V_6 ) ;
F_45 ( V_12 ) ;
F_42 ( V_12 ) ;
return 0 ;
}
