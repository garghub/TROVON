static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 [ 2 ] ;
T_1 V_7 = 0 ;
int V_8 ;
V_6 [ 0 ] . V_9 = V_2 -> V_9 ;
V_6 [ 0 ] . V_10 = 0 ;
V_6 [ 0 ] . V_11 = sizeof( V_3 ) ;
V_6 [ 0 ] . V_12 = & V_3 ;
V_6 [ 1 ] . V_9 = V_2 -> V_9 ;
V_6 [ 1 ] . V_10 = V_13 ;
V_6 [ 1 ] . V_11 = sizeof( V_7 ) ;
V_6 [ 1 ] . V_12 = & V_7 ;
V_8 = F_2 ( V_2 -> V_14 , V_6 , F_3 ( V_6 ) ) ;
if ( V_8 < 0 )
return V_8 ;
* V_4 = V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
T_1 V_15 [ 2 ] = { V_3 , V_7 } ;
struct V_5 V_16 ;
int V_8 ;
V_16 . V_9 = V_2 -> V_9 ;
V_16 . V_10 = 0 ;
V_16 . V_11 = sizeof( V_15 ) ;
V_16 . V_12 = V_15 ;
V_8 = F_2 ( V_2 -> V_14 , & V_16 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , bool V_17 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_18 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! V_17 )
V_7 &= ~ V_19 ;
else
V_7 |= V_19 ;
V_8 = F_4 ( V_2 , V_18 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_20 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_21 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 = ( V_7 & ~ V_22 ) | V_20 ;
V_8 = F_4 ( V_2 , V_21 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_18 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 |= V_23 ;
V_8 = F_4 ( V_2 , V_18 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_18 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 &= ~ V_23 ;
V_8 = F_4 ( V_2 , V_18 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
T_1 V_28 = V_29 , V_30 [ 7 ] ;
struct V_5 V_6 [ 2 ] ;
int V_8 ;
V_6 [ 0 ] . V_9 = V_2 -> V_9 ;
V_6 [ 0 ] . V_10 = 0 ;
V_6 [ 0 ] . V_11 = 1 ;
V_6 [ 0 ] . V_12 = & V_28 ;
V_6 [ 1 ] . V_9 = V_2 -> V_9 ;
V_6 [ 1 ] . V_10 = V_13 ;
V_6 [ 1 ] . V_11 = sizeof( V_30 ) ;
V_6 [ 1 ] . V_12 = V_30 ;
V_8 = F_2 ( V_2 -> V_14 , V_6 , F_3 ( V_6 ) ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_30 [ 0 ] & V_31 ) {
V_30 [ 0 ] &= ~ V_31 ;
V_8 = F_4 ( V_2 , V_29 , V_30 [ 0 ] ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_1 ( V_2 , V_29 , & V_30 [ 0 ] ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_30 [ 0 ] & V_31 )
return - V_32 ;
}
V_27 -> V_33 = F_11 ( V_30 [ 0 ] & 0x7f ) ;
V_27 -> V_34 = F_11 ( V_30 [ 1 ] & 0x7f ) ;
V_27 -> V_35 = F_11 ( V_30 [ 2 ] & 0x3f ) ;
V_27 -> V_36 = F_11 ( V_30 [ 3 ] & 0x3f ) ;
V_27 -> V_37 = V_30 [ 4 ] & 0x7 ;
V_27 -> V_38 = F_11 ( V_30 [ 5 ] & 0x1f ) - 1 ;
V_27 -> V_39 = F_11 ( V_30 [ 6 ] ) + 100 ;
return F_12 ( V_27 ) ;
}
static int F_13 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
struct V_5 V_16 ;
T_1 V_30 [ 8 ] ;
int V_8 ;
if ( V_27 -> V_39 < 100 || V_27 -> V_39 >= 200 )
return - V_40 ;
V_8 = F_7 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_30 [ 0 ] = V_29 ;
V_30 [ 1 ] = F_14 ( V_27 -> V_33 ) ;
V_30 [ 2 ] = F_14 ( V_27 -> V_34 ) ;
V_30 [ 3 ] = F_14 ( V_27 -> V_35 ) ;
V_30 [ 4 ] = F_14 ( V_27 -> V_36 ) ;
V_30 [ 5 ] = V_27 -> V_37 ;
V_30 [ 6 ] = F_14 ( V_27 -> V_38 + 1 ) ;
V_30 [ 7 ] = F_14 ( V_27 -> V_39 - 100 ) ;
V_16 . V_9 = V_2 -> V_9 ;
V_16 . V_10 = 0 ;
V_16 . V_11 = sizeof( V_30 ) ;
V_16 . V_12 = V_30 ;
V_8 = F_2 ( V_2 -> V_14 , & V_16 , 1 ) ;
if ( V_8 < 0 ) {
F_8 ( V_2 ) ;
return V_8 ;
}
return F_8 ( V_2 ) ;
}
static int F_15 ( struct V_24 * V_25 , unsigned int V_41 ,
unsigned long V_42 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
T_1 V_7 ;
int V_43 = 0 , V_8 ;
switch ( V_41 ) {
case V_44 :
V_8 = F_1 ( V_2 , V_21 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_7 & V_45 )
V_43 = 1 ;
if ( F_16 ( ( void V_46 * ) V_42 , & V_43 , sizeof( int ) ) )
return - V_47 ;
return 0 ;
default:
return - V_48 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
struct V_51 * V_52 ;
int V_8 ;
if ( ! F_18 ( V_2 -> V_14 , V_53 ) )
return - V_54 ;
V_52 = F_19 ( & V_2 -> V_25 , sizeof( * V_52 ) , V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_8 = F_5 ( V_2 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_52 -> V_57 = F_20 ( & V_2 -> V_25 , V_58 ,
& V_59 , V_60 ) ;
if ( F_21 ( V_52 -> V_57 ) )
return F_22 ( V_52 -> V_57 ) ;
F_23 ( V_2 , V_52 ) ;
return 0 ;
}
