static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = ( V_3 << 6 ) | V_4 ;
V_6 = F_3 ( V_2 -> V_7 , & V_5 , 1 ) ;
if ( V_6 != 1 ) {
F_4 ( V_2 -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_9 ;
int V_6 ;
V_6 = F_6 ( V_2 , V_3 , & V_9 ) ;
if ( V_6 )
return - 1 ;
return V_9 ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
struct V_14 * V_14 = F_9 ( V_2 ) ;
V_13 -> V_4 . integer . V_4 [ 0 ] = V_14 -> V_15 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
struct V_14 * V_14 = F_9 ( V_2 ) ;
T_1 V_4 = V_13 -> V_4 . integer . V_4 [ 0 ] ;
V_14 -> V_15 = V_4 ;
if ( V_2 -> V_16 . V_17 == V_18 )
F_11 ( V_2 , V_19 , 0x0F , V_4 + 6 ) ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
struct V_14 * V_14 = F_9 ( V_2 ) ;
switch ( V_21 ) {
case V_18 :
F_11 ( V_2 , V_19 , 0x0F , V_14 -> V_15 + 6 ) ;
break;
case V_22 :
F_11 ( V_2 , V_19 , 0x0F , 0 ) ;
break;
default:
break;
}
V_2 -> V_16 . V_17 = V_21 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_9 ( V_2 ) ;
struct V_23 * V_16 = & V_2 -> V_16 ;
int V_6 ;
V_2 -> V_7 = V_14 -> V_24 ;
V_6 = F_14 ( V_2 , V_25 ,
F_15 ( V_25 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_16 ( V_16 , V_26 ,
F_15 ( V_26 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_17 ( V_16 , V_27 ,
F_15 ( V_27 ) ) ;
if ( V_6 )
return V_6 ;
F_18 ( V_16 ) ;
return 0 ;
}
static int T_2 F_19 ( struct V_28 * V_24 ,
const struct V_29 * V_30 )
{
struct V_14 * V_14 ;
int V_6 ;
V_14 = F_20 ( & V_24 -> V_8 , sizeof( * V_14 ) , V_31 ) ;
if ( ! V_14 )
return - V_32 ;
F_21 ( V_24 , V_14 ) ;
V_14 -> V_24 = V_24 ;
V_6 = F_22 ( & V_24 -> V_8 , & V_33 , NULL , 0 ) ;
return V_6 ;
}
static int T_3 F_23 ( struct V_28 * V_24 )
{
F_24 ( & V_24 -> V_8 ) ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_34 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_34 ) ;
}
