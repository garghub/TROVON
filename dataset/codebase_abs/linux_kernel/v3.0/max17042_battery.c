static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static int F_6 ( struct V_8 * V_9 ,
enum V_10 V_11 ,
union V_12 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_9 ,
struct V_14 , V_16 ) ;
switch ( V_11 ) {
case V_17 :
V_13 -> V_18 = F_4 ( V_15 -> V_2 ,
V_19 ) * 83 ;
break;
case V_20 :
V_13 -> V_18 = F_4 ( V_15 -> V_2 ,
V_21 ) * 83 ;
break;
case V_22 :
V_13 -> V_18 = F_4 ( V_15 -> V_2 ,
V_23 ) / 256 ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static int T_3 F_8 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_9 ( V_2 -> V_6 . V_29 ) ;
struct V_14 * V_15 ;
int V_5 ;
if ( ! F_10 ( V_28 , V_30 ) )
return - V_31 ;
V_15 = F_11 ( sizeof( * V_15 ) , V_32 ) ;
if ( ! V_15 )
return - V_33 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_34 = V_2 -> V_6 . V_35 ;
F_12 ( V_2 , V_15 ) ;
V_15 -> V_16 . V_36 = L_2 ;
V_15 -> V_16 . type = V_37 ;
V_15 -> V_16 . V_38 = F_6 ;
V_15 -> V_16 . V_39 = V_40 ;
V_15 -> V_16 . V_41 = F_13 ( V_40 ) ;
V_5 = F_14 ( & V_2 -> V_6 , & V_15 -> V_16 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
F_12 ( V_2 , NULL ) ;
F_15 ( V_15 ) ;
return V_5 ;
}
if ( ! V_15 -> V_34 -> V_42 ) {
F_1 ( V_2 , V_43 , 0x0000 ) ;
F_1 ( V_2 , V_44 , 0x0003 ) ;
F_1 ( V_2 , V_45 , 0x0007 ) ;
}
return 0 ;
}
static int T_4 F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_17 ( V_2 ) ;
F_18 ( & V_15 -> V_16 ) ;
F_12 ( V_2 , NULL ) ;
F_15 ( V_15 ) ;
return 0 ;
}
static int T_5 F_19 ( void )
{
return F_20 ( & V_46 ) ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_46 ) ;
}
