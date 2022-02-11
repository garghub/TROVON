static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
int V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_7 ) ;
V_5 = F_3 ( V_2 -> V_8 , V_9 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_6 = F_2 ( ( V_3 >> 32 ) & 0xffffffff ) ;
V_5 = F_3 ( V_2 -> V_8 , V_10 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_6 = F_2 ( V_3 & 0xffffffff ) ;
V_5 = F_3 ( V_2 -> V_8 , V_11 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_6 = F_2 ( V_12 | V_4 ) ;
return F_3 ( V_2 -> V_8 , V_13 , & V_6 ,
sizeof( T_2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
T_2 V_14 , V_6 ;
int V_5 ;
* V_3 = 0ULL ;
V_6 = F_2 ( V_4 ) ;
V_5 = F_3 ( V_2 -> V_8 , V_13 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 -> V_8 , V_10 , & V_14 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
* V_3 |= ( T_1 ) F_2 ( V_14 ) << 32 ;
V_5 = F_5 ( V_2 -> V_8 , V_11 , & V_14 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
* V_3 |= F_2 ( V_14 ) ;
return 0 ;
}
static T_3 F_6 ( struct V_15 * V_16 , char T_4 * V_17 , T_5 V_18 ,
T_6 * V_19 )
{
int V_5 ;
struct V_20 * V_21 =
(struct V_20 * ) V_16 -> V_22 ;
struct V_1 * V_23 = F_7 ( V_21 ) ;
struct V_24 * V_25 = & V_23 -> V_8 -> V_25 ;
T_1 V_26 ;
if ( V_18 != sizeof( T_1 ) )
return - V_27 ;
V_5 = F_4 ( V_23 , & V_26 , * V_19 ) ;
if ( V_5 ) {
F_8 ( V_25 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_9 ( V_17 , & V_26 , V_18 ) ;
if ( V_5 )
F_8 ( V_25 , L_2 , V_5 ) ;
return V_5 ? V_5 : V_18 ;
}
static T_3 F_10 ( struct V_15 * V_16 , const char T_4 * V_17 ,
T_5 V_18 , T_6 * V_19 )
{
int V_5 ;
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_1 * V_23 = F_7 ( V_21 ) ;
struct V_24 * V_25 = & V_23 -> V_8 -> V_25 ;
T_1 V_26 ;
if ( V_18 != sizeof( T_1 ) )
return - V_27 ;
V_5 = F_11 ( & V_26 , V_17 , V_18 ) ;
if ( V_5 ) {
F_8 ( V_25 , L_3 , V_5 ) ;
return - V_27 ;
}
V_5 = F_1 ( V_23 , V_26 , * V_19 ) ;
if ( V_5 ) {
F_8 ( V_25 , L_4 , V_5 ) ;
return V_5 ;
}
return V_18 ;
}
static T_6 F_12 ( struct V_15 * V_15 , T_6 V_19 , int V_28 )
{
switch ( V_28 ) {
case V_29 :
break;
case V_30 :
V_15 -> V_31 = V_19 ;
break;
default:
return - V_27 ;
}
return V_19 ;
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_32 * V_8 = F_14 ( V_25 ) ;
struct V_1 * V_23 ;
V_23 = F_15 ( V_25 , sizeof( * V_23 ) , V_33 ) ;
if ( ! V_23 )
return - V_34 ;
V_23 -> V_35 = F_16 ( & V_36 , 1 , V_37 , V_33 ) ;
snprintf ( V_23 -> V_38 , sizeof( V_23 -> V_38 ) , L_5 , V_23 -> V_35 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_21 . V_39 = V_40 ;
V_23 -> V_21 . V_41 = & V_42 ;
V_23 -> V_21 . V_38 = V_23 -> V_38 ;
V_23 -> V_21 . V_43 = V_25 ;
F_17 ( & V_23 -> V_44 , & V_45 ) ;
return F_18 ( & V_23 -> V_21 ) ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_1 * V_23 , * V_46 ;
struct V_32 * V_8 = F_14 ( V_25 ) ;
F_20 (scom, scom_tmp, &scom_devices, link) {
if ( V_23 -> V_8 == V_8 ) {
F_21 ( & V_23 -> V_44 ) ;
F_22 ( & V_36 , V_23 -> V_35 ) ;
F_23 ( & V_23 -> V_21 ) ;
}
}
return 0 ;
}
static int F_24 ( void )
{
F_25 ( & V_45 ) ;
return F_26 ( & V_47 ) ;
}
static void F_27 ( void )
{
struct V_48 * V_49 ;
struct V_1 * V_23 ;
F_28 (pos, &scom_devices) {
V_23 = F_29 ( V_49 , struct V_1 , V_44 ) ;
F_23 ( & V_23 -> V_21 ) ;
F_30 ( & V_23 -> V_8 -> V_25 , V_23 ) ;
}
F_31 ( & V_47 ) ;
}
