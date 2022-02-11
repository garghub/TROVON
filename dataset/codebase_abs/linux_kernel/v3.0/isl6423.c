static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 -> V_6 ;
int V_8 = 0 ;
struct V_9 V_10 = { . V_6 = V_6 , . V_11 = 0 , . V_12 = & V_3 , . V_13 = 1 } ;
F_2 ( V_14 , 1 , L_1 , V_3 ) ;
V_8 = F_3 ( V_5 , & V_10 , 1 ) ;
if ( V_8 < 0 )
goto exit;
return 0 ;
exit:
F_2 ( V_15 , 1 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_4 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
const struct V_19 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
T_1 V_20 = 0 ;
V_20 = 0x01 << 5 ;
if ( V_7 -> V_21 )
V_20 |= ( 1 << 3 ) ;
else
V_20 |= ( 1 << 4 ) ;
V_8 = F_1 ( V_2 , V_20 ) ;
if ( V_8 < 0 )
goto exit;
return 0 ;
exit:
F_2 ( V_15 , 1 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_16 * V_17 , long V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
T_1 V_23 = V_2 -> V_23 ;
T_1 V_24 = V_2 -> V_24 ;
int V_8 = 0 ;
if ( V_22 ) {
V_24 |= ( 1 << 4 ) ;
V_24 |= 0x1 ;
V_23 |= ( 1 << 3 ) ;
} else {
V_24 |= ( 1 << 4 ) ;
V_24 &= ~ 0x1 ;
V_23 |= ( 1 << 3 ) ;
}
V_8 = F_1 ( V_2 , V_23 ) ;
if ( V_8 < 0 )
goto exit;
V_8 = F_1 ( V_2 , V_24 ) ;
if ( V_8 < 0 )
goto exit;
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_24 ;
return 0 ;
exit:
F_2 ( V_15 , 1 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_6 ( struct V_16 * V_17 ,
enum V_25 V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
T_1 V_23 = V_2 -> V_23 ;
T_1 V_24 = V_2 -> V_24 ;
int V_8 = 0 ;
switch ( V_26 ) {
case V_27 :
V_24 &= ~ ( 1 << 4 ) ;
break;
case V_28 :
V_24 |= ( 1 << 4 ) ;
V_24 &= ~ 0x3 ;
V_23 |= ( 1 << 3 ) ;
break;
case V_29 :
V_24 |= ( 1 << 4 ) ;
V_24 |= 0x2 ;
V_24 &= ~ 0x1 ;
V_23 |= ( 1 << 3 ) ;
break;
default:
break;
}
V_8 = F_1 ( V_2 , V_23 ) ;
if ( V_8 < 0 )
goto exit;
V_8 = F_1 ( V_2 , V_24 ) ;
if ( V_8 < 0 )
goto exit;
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_24 ;
return 0 ;
exit:
F_2 ( V_15 , 1 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
T_1 V_23 = V_2 -> V_23 ;
const struct V_19 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
switch ( V_7 -> V_30 ) {
case V_31 :
V_23 &= ~ 0x3 ;
break;
case V_32 :
V_23 &= ~ 0x2 ;
V_23 |= 0x1 ;
break;
case V_33 :
V_23 &= ~ 0x1 ;
V_23 |= 0x2 ;
break;
case V_34 :
V_23 |= 0x3 ;
break;
}
V_8 = F_1 ( V_2 , V_23 ) ;
if ( V_8 < 0 )
goto exit;
switch ( V_7 -> V_35 ) {
case V_36 :
V_23 &= ~ 0x10 ;
break;
case V_37 :
V_23 |= 0x10 ;
break;
}
V_8 = F_1 ( V_2 , V_23 ) ;
if ( V_8 < 0 )
goto exit;
V_2 -> V_23 = V_23 ;
return 0 ;
exit:
F_2 ( V_15 , 1 , L_2 , V_8 ) ;
return V_8 ;
}
static void F_8 ( struct V_16 * V_17 )
{
F_6 ( V_17 , V_27 ) ;
F_9 ( V_17 -> V_18 ) ;
V_17 -> V_18 = NULL ;
}
struct V_16 * F_10 ( struct V_16 * V_17 ,
struct V_4 * V_5 ,
const struct V_19 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( sizeof( struct V_1 ) , V_38 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = V_5 ;
V_17 -> V_18 = V_2 ;
V_2 -> V_23 = 0x02 << 5 ;
V_2 -> V_24 = 0x03 << 5 ;
if ( F_7 ( V_17 ) )
goto exit;
if ( F_4 ( V_17 ) )
goto exit;
V_17 -> V_39 . V_40 = F_8 ;
V_17 -> V_39 . V_41 = F_6 ;
V_17 -> V_39 . V_42 = F_5 ;
V_2 -> V_43 = V_43 ;
return V_17 ;
exit:
F_9 ( V_2 ) ;
V_17 -> V_18 = NULL ;
return NULL ;
}
