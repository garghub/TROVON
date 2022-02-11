static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
if ( ! V_4 -> V_8 )
return;
F_3 ( V_7 , V_4 -> V_9 , 0 ,
V_10 , V_4 -> V_11 ) ;
}
static int F_4 ( struct V_3 * V_4 , int V_12 )
{
if ( V_12 <= 0 )
return 0 ;
V_12 *= 1000 ;
V_12 = V_12 - V_13
+ V_14 / 2 ;
if ( V_12 < 0 )
V_12 = 0 ;
else if ( V_12 >= ( V_15 - V_13 ) )
V_12 = 1 ;
else {
V_12 /= V_14 ;
V_12 = 255 - V_12 ;
}
return V_12 ;
}
static int F_5 ( struct V_3 * V_4 , int V_12 )
{
if ( V_12 <= 0 )
return 0 ;
V_12 = 12000 / V_12 ;
if ( V_12 > 0xff )
return 0xff ;
if ( V_12 <= 0 )
return 1 ;
return V_12 ;
}
static int F_6 ( struct V_16 * V_17 , unsigned int type ,
unsigned int V_18 , int V_12 )
{
struct V_3 * V_4 = F_7 ( V_17 ) ;
switch ( V_18 ) {
case V_19 :
if ( V_12 )
V_12 = 1000 ;
case V_20 :
if ( V_4 -> V_21 )
V_4 -> V_11 = F_4 ( V_4 , V_12 ) ;
else
V_4 -> V_11 = F_5 ( V_4 , V_12 ) ;
break;
default:
return - 1 ;
}
F_8 ( & V_4 -> V_5 ) ;
return 0 ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_17 ) ;
V_4 -> V_17 = NULL ;
F_11 ( & V_4 -> V_5 ) ;
F_3 ( V_4 -> V_7 , V_4 -> V_9 , 0 ,
V_10 , 0 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_16 * V_16 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_22 ;
V_16 = F_13 () ;
if ( ! V_16 ) {
F_14 ( V_23 L_1 ) ;
return - V_24 ;
}
V_16 -> V_25 = L_2 ;
V_16 -> V_26 = V_4 -> V_26 ;
V_16 -> V_27 . V_28 = V_29 ;
V_16 -> V_27 . V_30 = V_7 -> V_31 >> 16 ;
V_16 -> V_27 . V_32 = V_7 -> V_31 & 0xffff ;
V_16 -> V_27 . V_33 = 0x01 ;
V_16 -> V_34 [ 0 ] = F_15 ( V_35 ) ;
V_16 -> V_36 [ 0 ] = F_15 ( V_19 ) | F_15 ( V_20 ) ;
V_16 -> V_37 = F_6 ;
V_16 -> V_17 . V_38 = & V_7 -> V_39 -> V_40 -> V_17 ;
F_16 ( V_16 , V_4 ) ;
V_22 = F_17 ( V_16 ) ;
if ( V_22 < 0 ) {
F_18 ( V_16 ) ;
F_14 ( V_23 L_3 ) ;
return V_22 ;
}
V_4 -> V_17 = V_16 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_41 ) ;
F_20 ( & V_4 -> V_42 ) ;
if ( V_4 -> V_8 && ! V_4 -> V_17 )
F_12 ( V_4 ) ;
F_21 ( & V_4 -> V_42 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_43 . V_2 ) ;
F_20 ( & V_4 -> V_42 ) ;
if ( ! V_4 -> V_8 && V_4 -> V_17 )
F_9 ( V_4 ) ;
F_21 ( & V_4 -> V_42 ) ;
}
int F_23 ( struct V_6 * V_7 , int V_44 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
V_44 = ! ! V_44 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_8 != V_44 ) {
V_4 -> V_8 = V_44 ;
if ( ! V_44 ) {
F_3 ( V_4 -> V_7 , V_4 -> V_9 , 0 ,
V_10 , 0 ) ;
}
if ( V_4 -> V_45 == V_46 ) {
if ( V_44 ) {
F_24 ( & V_4 -> V_43 ) ;
F_8 ( & V_4 -> V_41 ) ;
} else {
F_25 ( & V_4 -> V_43 ,
V_47 ) ;
}
}
return 1 ;
}
return 0 ;
}
int F_26 ( struct V_6 * V_7 , int V_9 )
{
struct V_3 * V_4 ;
if ( ! F_27 ( V_7 , L_4 ) )
return 0 ;
if ( V_7 -> V_48 == V_49 )
return 0 ;
V_4 = F_28 ( sizeof( * V_4 ) , V_50 ) ;
if ( V_4 == NULL )
return - V_24 ;
snprintf ( V_4 -> V_26 , sizeof( V_4 -> V_26 ) ,
L_5 , V_7 -> V_39 -> V_51 -> V_52 , V_7 -> V_53 ) ;
F_3 ( V_7 , V_9 , 0 ,
V_54 , 0x01 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_45 = V_7 -> V_48 ;
V_7 -> V_4 = V_4 ;
F_29 ( & V_4 -> V_41 , & F_19 ) ;
F_30 ( & V_4 -> V_43 , & F_22 ) ;
F_29 ( & V_4 -> V_5 , & F_1 ) ;
F_31 ( & V_4 -> V_42 ) ;
if ( V_4 -> V_45 == V_55 ) {
int V_22 = F_12 ( V_4 ) ;
if ( V_22 < 0 ) {
F_32 ( V_4 ) ;
V_7 -> V_4 = NULL ;
return V_22 ;
}
}
return 0 ;
}
void F_33 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
if ( V_4 ) {
F_11 ( & V_4 -> V_41 ) ;
F_24 ( & V_4 -> V_43 ) ;
if ( V_4 -> V_17 )
F_9 ( V_4 ) ;
V_7 -> V_4 = NULL ;
F_32 ( V_4 ) ;
}
}
