static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_6 ) ;
V_4 -> V_8 . integer . V_8 [ 0 ] = V_7 -> V_9 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_7 = F_3 ( V_6 ) ;
T_1 V_8 = V_4 -> V_8 . integer . V_8 [ 0 ] ;
V_7 -> V_9 = V_8 ;
if ( V_6 -> V_10 . V_11 == V_12 )
F_5 ( V_7 -> V_13 , V_14 , 0x0F , V_8 + 6 ) ;
return 1 ;
}
static int F_6 ( struct V_5 * V_6 ,
enum V_15 V_16 )
{
struct V_7 * V_7 = F_3 ( V_6 ) ;
switch ( V_16 ) {
case V_12 :
F_5 ( V_7 -> V_13 , V_14 , 0x0F ,
V_7 -> V_9 + 6 ) ;
break;
case V_17 :
F_5 ( V_7 -> V_13 , V_14 , 0x0F , 0 ) ;
break;
default:
break;
}
V_6 -> V_10 . V_11 = V_16 ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( & V_19 -> V_22 , sizeof( * V_7 ) , V_23 ) ;
if ( ! V_7 )
return - V_24 ;
F_9 ( V_19 , V_7 ) ;
V_7 -> V_13 = F_10 ( V_19 , & V_25 ) ;
if ( F_11 ( V_7 -> V_13 ) )
return F_12 ( V_7 -> V_13 ) ;
return F_13 ( & V_19 -> V_22 , & V_26 , NULL , 0 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
F_15 ( & V_19 -> V_22 ) ;
return 0 ;
}
