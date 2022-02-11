static int
F_1 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 . V_10 . V_7 ;
struct V_11 * V_12 = & V_2 -> V_12 ;
const T_1 V_13 = V_5 * 0x2000 ;
union {
struct V_14 V_15 ;
} * args = V_3 ;
T_1 line ;
int V_16 = - V_17 ;
F_2 ( V_12 , L_1 , V_4 ) ;
if ( ! ( V_16 = F_3 ( V_16 , & V_3 , & V_4 , args -> V_15 , 0 , 0 , false ) ) ) {
F_2 ( V_12 , L_2 ,
args -> V_15 . V_18 ) ;
args -> V_15 . V_19 = F_4 ( V_7 , 0x680800 + V_13 ) & 0xffff ;
args -> V_15 . V_20 = F_4 ( V_7 , 0x680804 + V_13 ) & 0xffff ;
args -> V_15 . V_21 = args -> V_15 . V_20 - 1 ;
args -> V_15 . V_22 = F_4 ( V_7 , 0x680820 + V_13 ) & 0xffff ;
args -> V_15 . V_23 = F_4 ( V_7 , 0x680824 + V_13 ) & 0xffff ;
args -> V_15 . V_24 = args -> V_15 . V_23 - 1 ;
if ( ! args -> V_15 . V_20 || ! args -> V_15 . V_23 )
return - V_25 ;
args -> V_15 . time [ 0 ] = F_5 ( F_6 () ) ;
line = F_4 ( V_7 , 0x600868 + V_13 ) ;
args -> V_15 . time [ 1 ] = F_5 ( F_6 () ) ;
args -> V_15 . V_26 = ( line & 0xffff0000 ) >> 16 ;
args -> V_15 . V_27 = ( line & 0x0000ffff ) ;
} else
return V_16 ;
return 0 ;
}
static int
F_7 ( struct V_11 * V_12 , T_1 V_28 , void * V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
union {
struct V_29 V_15 ;
} * args = V_3 ;
int V_5 , V_16 = - V_17 ;
F_2 ( V_12 , L_3 , V_4 ) ;
if ( ! ( V_16 = F_3 ( V_16 , & V_3 , & V_4 , args -> V_15 , 0 , 0 , true ) ) ) {
F_2 ( V_12 , L_4 ,
args -> V_15 . V_18 , args -> V_15 . V_30 , args -> V_15 . V_5 ) ;
V_28 = args -> V_15 . V_30 ;
V_5 = args -> V_15 . V_5 ;
} else
return V_16 ;
if ( V_5 < 0 || V_5 >= 2 )
return - V_31 ;
switch ( V_28 ) {
case V_32 :
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
default:
break;
}
return - V_33 ;
}
static int
F_8 ( struct V_34 * V_8 , const struct V_35 * V_36 ,
void * V_3 , T_1 V_4 , struct V_11 * * V_37 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = F_9 ( sizeof( * V_2 ) , V_38 ) ) )
return - V_39 ;
V_2 -> V_8 = V_8 ;
* V_37 = & V_2 -> V_12 ;
F_10 ( & V_1 , V_36 , & V_2 -> V_12 ) ;
return 0 ;
}
