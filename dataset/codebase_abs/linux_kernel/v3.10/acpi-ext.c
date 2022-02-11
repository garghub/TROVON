static T_1 F_1 ( T_2 V_1 , T_3 * V_2 , T_3 * V_3 )
{
T_1 V_4 ;
struct V_5 V_6 = { V_7 , NULL } ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_4 = F_2 ( V_1 , V_12 , & V_13 ,
& V_6 ) ;
V_9 = V_6 . V_14 ;
V_11 = & V_9 -> V_15 . V_16 ;
if ( F_3 ( V_4 ) || V_11 -> V_17 < 16 ) {
V_4 = V_18 ;
goto exit;
}
memcpy ( V_2 , V_11 -> V_19 , sizeof( * V_2 ) ) ;
memcpy ( V_3 , V_11 -> V_19 + 8 , sizeof( * V_3 ) ) ;
exit:
F_4 ( V_6 . V_14 ) ;
return V_4 ;
}
static T_1 F_5 ( struct V_8 * V_9 , void * V_15 )
{
struct V_20 * V_21 = V_15 ;
struct V_22 V_23 ;
T_1 V_4 ;
V_4 = F_6 ( V_9 , & V_23 ) ;
if ( F_7 ( V_4 ) &&
V_23 . V_24 == V_25 &&
V_23 . V_26 &&
V_23 . V_27 == V_28 ) {
V_21 -> V_2 = V_23 . V_29 ;
V_21 -> V_3 = V_23 . V_26 ;
return V_30 ;
}
return V_31 ;
}
static T_1 F_8 ( T_2 V_1 , T_3 * V_2 , T_3 * V_3 )
{
struct V_20 V_21 = { 0 , 0 } ;
F_9 ( V_1 , V_12 , F_5 , & V_21 ) ;
if ( ! V_21 . V_3 )
return V_18 ;
* V_2 = V_21 . V_2 ;
* V_3 = V_21 . V_3 ;
return V_31 ;
}
T_1 F_10 ( T_2 V_1 , T_3 * V_32 , T_3 * V_33 )
{
T_1 V_4 ;
V_4 = F_1 ( V_1 , V_32 , V_33 ) ;
if ( F_7 ( V_4 ) )
return V_4 ;
return F_8 ( V_1 , V_32 , V_33 ) ;
}
