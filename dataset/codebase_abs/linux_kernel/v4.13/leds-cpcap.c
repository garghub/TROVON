static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
V_1 &= 0x1f ;
V_2 &= 0x0f ;
return V_1 << 4 | V_2 ;
}
static int F_2 ( struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
if ( V_5 == V_4 -> V_7 )
return 0 ;
if ( V_5 )
V_6 = F_3 ( V_4 -> V_8 ) ;
else
V_6 = F_4 ( V_4 -> V_8 ) ;
if ( V_6 ) {
F_5 ( V_4 -> V_9 , L_1 , V_6 ) ;
return V_6 ;
}
V_4 -> V_7 = V_5 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 , enum V_12 V_13 )
{
struct V_3 * V_4 = F_7 ( V_11 , struct V_3 , V_4 ) ;
int V_14 ;
int V_6 ;
F_8 ( & V_4 -> V_15 ) ;
if ( V_13 > V_16 ) {
V_6 = F_2 ( V_4 , true ) ;
if ( V_6 )
goto exit;
}
if ( V_13 == V_16 ) {
V_6 = F_9 ( V_4 -> V_17 ,
V_4 -> V_18 -> V_19 , V_4 -> V_18 -> V_20 , V_21 ) ;
if ( V_6 ) {
F_5 ( V_4 -> V_9 , L_2 , V_6 ) ;
goto exit;
}
V_14 = F_1 ( V_13 , V_16 ) ;
} else {
V_14 = F_1 ( V_13 , V_22 ) ;
}
V_6 = F_9 ( V_4 -> V_17 , V_4 -> V_18 -> V_19 , V_4 -> V_18 -> V_20 ,
V_14 ) ;
if ( V_6 ) {
F_5 ( V_4 -> V_9 , L_2 , V_6 ) ;
goto exit;
}
if ( V_13 == V_16 ) {
V_6 = F_2 ( V_4 , false ) ;
if ( V_6 )
goto exit;
}
exit:
F_10 ( & V_4 -> V_15 ) ;
return V_6 ;
}
static int F_11 ( struct V_23 * V_24 )
{
const struct V_25 * V_26 ;
struct V_3 * V_4 ;
int V_6 ;
V_26 = F_12 ( F_13 ( V_27 ) , & V_24 -> V_9 ) ;
if ( ! V_26 || ! V_26 -> V_28 )
return - V_29 ;
V_4 = F_14 ( & V_24 -> V_9 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
F_15 ( V_24 , V_4 ) ;
V_4 -> V_18 = V_26 -> V_28 ;
V_4 -> V_9 = & V_24 -> V_9 ;
if ( V_4 -> V_18 -> V_19 == 0x0000 ) {
F_5 ( V_4 -> V_9 , L_3 ) ;
return - V_32 ;
}
V_4 -> V_17 = F_16 ( V_24 -> V_9 . V_33 , NULL ) ;
if ( ! V_4 -> V_17 )
return - V_32 ;
V_4 -> V_8 = F_17 ( & V_24 -> V_9 , L_4 ) ;
if ( F_18 ( V_4 -> V_8 ) ) {
V_6 = F_19 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_9 , L_5 , V_6 ) ;
return V_6 ;
}
V_6 = F_20 ( & V_24 -> V_9 , L_6 , & V_4 -> V_4 . V_34 ) ;
if ( V_6 ) {
F_5 ( V_4 -> V_9 , L_7 , V_6 ) ;
return V_6 ;
}
if ( V_4 -> V_18 -> V_35 ) {
V_6 = F_9 ( V_4 -> V_17 , V_4 -> V_18 -> V_19 ,
V_4 -> V_18 -> V_35 , V_4 -> V_18 -> V_36 ) ;
if ( V_6 ) {
F_5 ( V_4 -> V_9 , L_2 , V_6 ) ;
return V_6 ;
}
}
F_21 ( & V_4 -> V_15 ) ;
V_4 -> V_4 . V_37 = V_4 -> V_18 -> V_38 ;
V_4 -> V_4 . V_39 = F_6 ;
V_6 = F_22 ( & V_24 -> V_9 , & V_4 -> V_4 ) ;
if ( V_6 ) {
F_5 ( V_4 -> V_9 , L_8 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
