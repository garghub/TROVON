static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
int V_5 ;
T_2 V_6 ;
V_6 = F_2 ( ( V_3 >> 32 ) & 0xffffffff ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_6 = F_2 ( V_3 & 0xffffffff ) ;
V_5 = F_3 ( V_2 -> V_7 , V_9 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_6 = F_2 ( V_10 | V_4 ) ;
return F_3 ( V_2 -> V_7 , V_11 , & V_6 ,
sizeof( T_2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
T_2 V_12 , V_6 ;
int V_5 ;
* V_3 = 0ULL ;
V_6 = F_2 ( V_4 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_11 , & V_6 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 -> V_7 , V_8 , & V_12 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
* V_3 |= ( T_1 ) F_2 ( V_12 ) << 32 ;
V_5 = F_5 ( V_2 -> V_7 , V_9 , & V_12 ,
sizeof( T_2 ) ) ;
if ( V_5 )
return V_5 ;
* V_3 |= F_2 ( V_12 ) ;
return 0 ;
}
static T_3 F_6 ( struct V_13 * V_14 , char T_4 * V_15 , T_5 V_16 ,
T_6 * V_17 )
{
int V_5 ;
struct V_18 * V_19 =
(struct V_18 * ) V_14 -> V_20 ;
struct V_1 * V_21 = F_7 ( V_19 ) ;
struct V_22 * V_23 = & V_21 -> V_7 -> V_23 ;
T_1 V_24 ;
if ( V_16 != sizeof( T_1 ) )
return - V_25 ;
V_5 = F_4 ( V_21 , & V_24 , * V_17 ) ;
if ( V_5 ) {
F_8 ( V_23 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_9 ( V_15 , & V_24 , V_16 ) ;
if ( V_5 )
F_8 ( V_23 , L_2 , V_5 ) ;
return V_5 ? V_5 : V_16 ;
}
static T_3 F_10 ( struct V_13 * V_14 , const char T_4 * V_15 ,
T_5 V_16 , T_6 * V_17 )
{
int V_5 ;
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_1 * V_21 = F_7 ( V_19 ) ;
struct V_22 * V_23 = & V_21 -> V_7 -> V_23 ;
T_1 V_24 ;
if ( V_16 != sizeof( T_1 ) )
return - V_25 ;
V_5 = F_11 ( & V_24 , V_15 , V_16 ) ;
if ( V_5 ) {
F_8 ( V_23 , L_3 , V_5 ) ;
return - V_25 ;
}
V_5 = F_1 ( V_21 , V_24 , * V_17 ) ;
if ( V_5 ) {
F_8 ( V_23 , L_4 , V_5 ) ;
return V_5 ;
}
return V_16 ;
}
static T_6 F_12 ( struct V_13 * V_13 , T_6 V_17 , int V_26 )
{
switch ( V_26 ) {
case V_27 :
break;
case V_28 :
V_13 -> V_29 = V_17 ;
break;
default:
return - V_25 ;
}
return V_17 ;
}
static int F_13 ( struct V_22 * V_23 )
{
T_2 V_6 ;
struct V_30 * V_7 = F_14 ( V_23 ) ;
struct V_1 * V_21 ;
V_21 = F_15 ( V_23 , sizeof( * V_21 ) , V_31 ) ;
if ( ! V_21 )
return - V_32 ;
V_21 -> V_33 = F_16 ( & V_34 , 1 , V_35 , V_31 ) ;
snprintf ( V_21 -> V_36 , sizeof( V_21 -> V_36 ) , L_5 , V_21 -> V_33 ) ;
V_21 -> V_7 = V_7 ;
V_21 -> V_19 . V_37 = V_38 ;
V_21 -> V_19 . V_39 = & V_40 ;
V_21 -> V_19 . V_36 = V_21 -> V_36 ;
V_21 -> V_19 . V_41 = V_23 ;
F_17 ( & V_21 -> V_42 , & V_43 ) ;
V_6 = F_2 ( V_44 ) ;
F_3 ( V_7 , V_45 , & V_6 , sizeof( T_2 ) ) ;
return F_18 ( & V_21 -> V_19 ) ;
}
static int F_19 ( struct V_22 * V_23 )
{
struct V_1 * V_21 , * V_46 ;
struct V_30 * V_7 = F_14 ( V_23 ) ;
F_20 (scom, scom_tmp, &scom_devices, link) {
if ( V_21 -> V_7 == V_7 ) {
F_21 ( & V_21 -> V_42 ) ;
F_22 ( & V_34 , V_21 -> V_33 ) ;
F_23 ( & V_21 -> V_19 ) ;
}
}
return 0 ;
}
static int F_24 ( void )
{
F_25 ( & V_43 ) ;
return F_26 ( & V_47 ) ;
}
static void F_27 ( void )
{
struct V_48 * V_49 ;
struct V_1 * V_21 ;
F_28 (pos, &scom_devices) {
V_21 = F_29 ( V_49 , struct V_1 , V_42 ) ;
F_23 ( & V_21 -> V_19 ) ;
F_30 ( & V_21 -> V_7 -> V_23 , V_21 ) ;
}
F_31 ( & V_47 ) ;
}
