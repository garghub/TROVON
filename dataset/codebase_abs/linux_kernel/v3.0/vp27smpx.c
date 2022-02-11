static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = F_4 ( V_3 ) ;
T_2 V_8 [ 3 ] = { 0x00 , 0x00 , 0x04 } ;
switch ( V_4 ) {
case V_9 :
case V_10 :
break;
case V_11 :
case V_12 :
V_8 [ 1 ] = 0x01 ;
break;
case V_13 :
V_8 [ 1 ] = 0x02 ;
break;
}
if ( F_5 ( V_7 , V_8 , sizeof( V_8 ) ) != sizeof( V_8 ) )
F_6 ( V_3 , L_1 ) ;
else
V_5 -> V_4 = V_4 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_14 = 1 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_3 V_15 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_14 = 0 ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_14 )
F_3 ( V_3 , V_17 -> V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_14 )
return 0 ;
V_17 -> V_4 = V_5 -> V_4 ;
V_17 -> V_18 = V_19 |
V_20 | V_21 ;
V_17 -> V_22 = V_23 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_12 ( V_7 , V_25 , V_26 , 0 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_14 ( V_3 , L_2 , V_5 -> V_4 ,
V_5 -> V_14 ? L_3 : L_4 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
if ( ! F_16 ( V_7 -> V_29 , V_30 ) )
return - V_31 ;
F_17 ( V_7 , L_5 ,
V_7 -> V_32 << 1 , V_7 -> V_29 -> V_33 ) ;
V_5 = F_18 ( sizeof( struct V_1 ) , V_34 ) ;
if ( V_5 == NULL )
return - V_35 ;
V_3 = & V_5 -> V_3 ;
F_19 ( V_3 , V_7 , & V_36 ) ;
V_5 -> V_4 = V_11 ;
F_3 ( V_3 , V_5 -> V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_21 ( V_7 ) ;
F_22 ( V_3 ) ;
F_23 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_4 int F_24 ( void )
{
return F_25 ( & V_37 ) ;
}
static T_5 void F_26 ( void )
{
F_27 ( & V_37 ) ;
}
