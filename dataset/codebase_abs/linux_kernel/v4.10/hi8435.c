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
enum V_15 type ,
enum V_16 V_17 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return ! ! ( V_2 -> V_18 & F_12 ( V_14 -> V_19 ) ) ;
}
static int F_13 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_15 type ,
enum V_16 V_17 , int V_20 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
V_2 -> V_18 &= ~ F_12 ( V_14 -> V_19 ) ;
if ( V_20 )
V_2 -> V_18 |= F_12 ( V_14 -> V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_15 type ,
enum V_16 V_17 ,
enum V_21 V_22 ,
int * V_4 , int * V_23 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_24 , V_25 ;
T_2 V_3 ;
V_7 = F_1 ( V_2 , V_26 , & V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_24 = ! ! ( V_25 & F_12 ( V_14 -> V_19 / 8 ) ) ;
V_7 = F_3 ( V_2 , V_24 ? V_27 :
V_28 , & V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_17 == V_29 )
* V_4 = ( ( V_3 & 0xff ) - ( V_3 >> 8 ) ) / 2 ;
else if ( V_17 == V_30 )
* V_4 = ( ( V_3 & 0xff ) + ( V_3 >> 8 ) ) / 2 ;
return V_31 ;
}
static int F_15 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
enum V_15 type ,
enum V_16 V_17 ,
enum V_21 V_22 ,
int V_4 , int V_23 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_24 , V_25 ;
T_2 V_3 ;
V_7 = F_1 ( V_2 , V_26 , & V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_24 = ! ! ( V_25 & F_12 ( V_14 -> V_19 / 8 ) ) ;
V_7 = F_3 ( V_2 , V_24 ? V_27 :
V_28 , & V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_17 == V_29 ) {
if ( V_4 < 2 || V_4 > 21 || ( V_4 + 2 ) > V_2 -> V_32 [ V_24 ] )
return - V_33 ;
if ( V_4 == V_2 -> V_34 [ V_24 ] )
return 0 ;
V_2 -> V_34 [ V_24 ] = V_4 ;
if ( ( V_2 -> V_32 [ V_24 ] - V_2 -> V_34 [ V_24 ] ) % 2 )
V_2 -> V_32 [ V_24 ] -- ;
} else if ( V_17 == V_30 ) {
if ( V_4 < 3 || V_4 > 22 || V_4 < ( V_2 -> V_34 [ V_24 ] + 2 ) )
return - V_33 ;
if ( V_4 == V_2 -> V_32 [ V_24 ] )
return 0 ;
V_2 -> V_32 [ V_24 ] = V_4 ;
if ( ( V_2 -> V_32 [ V_24 ] - V_2 -> V_34 [ V_24 ] ) % 2 )
V_2 -> V_34 [ V_24 ] ++ ;
}
F_16 ( & V_2 -> V_35 ) ;
V_7 = F_3 ( V_2 , V_24 ? V_27 :
V_28 , & V_3 ) ;
if ( V_7 < 0 ) {
F_17 ( & V_2 -> V_35 ) ;
return V_7 ;
}
V_3 = V_2 -> V_32 [ V_24 ] - V_2 -> V_34 [ V_24 ] ;
V_3 <<= 8 ;
V_3 |= ( V_2 -> V_32 [ V_24 ] + V_2 -> V_34 [ V_24 ] ) ;
V_7 = F_9 ( V_2 , V_24 ? V_27 :
V_28 , V_3 ) ;
F_17 ( & V_2 -> V_35 ) ;
return V_7 ;
}
static int F_18 ( struct V_11 * V_12 ,
unsigned V_3 , unsigned V_36 ,
unsigned * V_37 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_4 ;
if ( V_37 != NULL ) {
V_7 = F_1 ( V_2 , V_3 , & V_4 ) ;
* V_37 = V_4 ;
} else {
V_4 = ( T_1 ) V_36 ;
V_7 = F_7 ( V_2 , V_3 , V_4 ) ;
}
return V_7 ;
}
static int F_19 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_3 ;
V_7 = F_1 ( V_2 , V_26 , & V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ! ( V_3 & F_12 ( V_14 -> V_19 / 8 ) ) ;
}
static int F_20 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
unsigned int V_24 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_7 ;
T_1 V_3 ;
F_16 ( & V_2 -> V_35 ) ;
V_7 = F_1 ( V_2 , V_26 , & V_3 ) ;
if ( V_7 < 0 ) {
F_17 ( & V_2 -> V_35 ) ;
return V_7 ;
}
V_3 &= ~ F_12 ( V_14 -> V_19 / 8 ) ;
if ( V_24 )
V_3 |= F_12 ( V_14 -> V_19 / 8 ) ;
V_7 = F_7 ( V_2 , V_26 , V_3 ) ;
F_17 ( & V_2 -> V_35 ) ;
return V_7 ;
}
static void F_21 ( struct V_11 * V_12 , unsigned int V_4 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
enum V_16 V_17 ;
unsigned int V_38 ;
unsigned int V_39 = V_2 -> V_40 ^ V_4 ;
if ( ! V_39 )
return;
F_22 (i, &priv->event_scan_mask, 32 ) {
if ( V_39 & F_12 ( V_38 ) ) {
V_17 = V_4 & F_12 ( V_38 ) ? V_30 :
V_29 ;
F_23 ( V_12 ,
F_24 ( V_41 , V_38 ,
V_42 , V_17 ) ,
F_25 ( V_12 ) ) ;
}
}
V_2 -> V_40 = V_4 ;
}
static T_6 F_26 ( int V_43 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
struct V_11 * V_12 = V_46 -> V_47 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_4 V_4 ;
int V_7 ;
V_7 = F_5 ( V_2 , V_48 , & V_4 ) ;
if ( V_7 < 0 )
goto V_49;
F_21 ( V_12 , V_4 ) ;
V_49:
F_27 ( V_12 -> V_50 ) ;
return V_51 ;
}
static int F_28 ( struct V_52 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
int V_7 ;
V_12 = F_29 ( & V_6 -> V_55 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_56 ;
V_2 = F_11 ( V_12 ) ;
V_2 -> V_6 = V_6 ;
V_54 = F_30 ( & V_6 -> V_55 , NULL , V_57 ) ;
if ( F_31 ( V_54 ) ) {
F_7 ( V_2 , V_58 , V_59 ) ;
F_7 ( V_2 , V_58 , 0 ) ;
} else {
F_32 ( 5 ) ;
F_33 ( V_54 , 1 ) ;
}
F_34 ( V_6 , V_12 ) ;
F_35 ( & V_2 -> V_35 ) ;
V_12 -> V_55 . V_60 = & V_6 -> V_55 ;
V_12 -> V_55 . V_61 = V_6 -> V_55 . V_61 ;
V_12 -> V_62 = F_36 ( V_6 ) -> V_62 ;
V_12 -> V_63 = V_64 ;
V_12 -> V_22 = & V_65 ;
V_12 -> V_66 = V_67 ;
V_12 -> V_68 = F_37 ( V_67 ) ;
V_2 -> V_18 = ~ ( 0 ) ;
V_2 -> V_34 [ 0 ] = V_2 -> V_34 [ 1 ] = 2 ;
V_2 -> V_32 [ 0 ] = V_2 -> V_32 [ 1 ] = 4 ;
F_9 ( V_2 , V_28 , 0x206 ) ;
F_9 ( V_2 , V_27 , 0x206 ) ;
V_7 = F_38 ( V_12 , NULL , F_26 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_39 ( V_12 ) ;
if ( V_7 < 0 ) {
F_40 ( & V_6 -> V_55 , L_1 ) ;
goto V_69;
}
return 0 ;
V_69:
F_41 ( V_12 ) ;
return V_7 ;
}
static int F_42 ( struct V_52 * V_6 )
{
struct V_11 * V_12 = F_43 ( V_6 ) ;
F_44 ( V_12 ) ;
F_41 ( V_12 ) ;
return 0 ;
}
