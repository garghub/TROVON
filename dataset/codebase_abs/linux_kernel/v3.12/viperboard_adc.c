static int F_1 ( struct V_1 * V_1 ,
struct V_2 const * V_3 ,
int * V_4 ,
int * V_5 ,
long V_6 )
{
int V_7 , error = 0 ;
struct V_8 * V_9 = F_2 ( V_1 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_14 ;
switch ( V_6 ) {
case V_15 :
F_3 ( & V_11 -> V_16 ) ;
V_13 -> V_17 = V_18 ;
V_13 -> V_3 = V_3 -> V_19 ;
V_13 -> V_4 = 0x00 ;
V_7 = F_4 ( V_11 -> V_20 ,
F_5 ( V_11 -> V_20 , 0 ) , V_21 ,
V_22 , 0x0000 , 0x0000 , V_13 ,
sizeof( struct V_12 ) , V_23 ) ;
if ( V_7 != sizeof( struct V_12 ) ) {
F_6 ( & V_1 -> V_24 , L_1 ) ;
error = - V_25 ;
}
V_7 = F_4 ( V_11 -> V_20 ,
F_7 ( V_11 -> V_20 , 0 ) , V_21 ,
V_26 , 0x0000 , 0x0000 , V_13 ,
sizeof( struct V_12 ) , V_23 ) ;
* V_4 = V_13 -> V_4 ;
F_8 ( & V_11 -> V_16 ) ;
if ( V_7 != sizeof( struct V_12 ) ) {
F_6 ( & V_1 -> V_24 , L_2 ) ;
error = - V_25 ;
}
if ( error )
goto error;
return V_27 ;
default:
error = - V_28 ;
break;
}
error:
return error ;
}
static int F_9 ( struct V_29 * V_30 )
{
struct V_10 * V_11 = F_10 ( V_30 -> V_24 . V_31 ) ;
struct V_8 * V_9 ;
struct V_1 * V_32 ;
int V_7 ;
V_32 = F_11 ( & V_30 -> V_24 , sizeof( * V_9 ) ) ;
if ( ! V_32 ) {
F_6 ( & V_30 -> V_24 , L_3 ) ;
return - V_33 ;
}
V_9 = F_2 ( V_32 ) ;
V_9 -> V_11 = V_11 ;
V_32 -> V_34 = L_4 ;
V_32 -> V_24 . V_31 = & V_30 -> V_24 ;
V_32 -> V_6 = & V_35 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_38 = V_39 ;
V_32 -> V_40 = F_12 ( V_39 ) ;
V_7 = F_13 ( V_32 ) ;
if ( V_7 ) {
F_6 ( & V_30 -> V_24 , L_5 ) ;
return V_7 ;
}
F_14 ( V_30 , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_1 * V_32 = F_16 ( V_30 ) ;
F_17 ( V_32 ) ;
return 0 ;
}
