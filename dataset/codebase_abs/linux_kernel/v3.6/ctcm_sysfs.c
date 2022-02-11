static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_1 , V_7 -> V_9 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_12 = V_7 -> V_14 [ V_15 ] -> V_16 ;
if ( ! ( V_7 && V_7 -> V_14 [ V_15 ] && V_12 ) ) {
F_4 ( V_17 , V_18 , L_2 ) ;
return - V_8 ;
}
sscanf ( V_5 , L_3 , & V_13 ) ;
if ( V_13 > V_19 )
goto V_20;
if ( V_13 < ( 576 + V_21 + 2 ) )
goto V_20;
V_7 -> V_9 = V_13 ;
if ( ( V_12 -> V_22 & V_23 ) &&
( V_13 < ( V_12 -> V_24 + V_21 + 2 ) ) )
goto V_20;
V_7 -> V_14 [ V_15 ] -> V_25 = V_13 ;
V_7 -> V_14 [ V_26 ] -> V_25 = V_13 ;
if ( ! ( V_12 -> V_22 & V_23 ) )
V_12 -> V_24 = V_13 - V_21 - 2 ;
V_7 -> V_14 [ V_15 ] -> V_22 |= V_27 ;
V_7 -> V_14 [ V_26 ] -> V_22 |= V_27 ;
F_5 ( V_17 , V_12 , V_5 ) ;
return V_10 ;
V_20:
F_5 ( V_17 , V_12 , L_4 ) ;
return - V_28 ;
}
static void F_6 ( struct V_6 * V_7 )
{
char * V_29 ;
char * V_30 ;
if ( ! V_7 )
return;
V_29 = F_7 ( 2048 , V_31 ) ;
if ( V_29 == NULL )
return;
V_30 = V_29 ;
V_30 += sprintf ( V_30 , L_5 ,
F_8 ( V_7 -> V_32 ) ) ;
V_30 += sprintf ( V_30 , L_6 ,
F_8 ( V_7 -> V_14 [ V_15 ] -> V_32 ) ) ;
V_30 += sprintf ( V_30 , L_7 ,
F_8 ( V_7 -> V_14 [ V_26 ] -> V_32 ) ) ;
V_30 += sprintf ( V_30 , L_8 ,
V_7 -> V_14 [ V_33 ] -> V_34 . V_35 ) ;
V_30 += sprintf ( V_30 , L_9 ,
V_7 -> V_14 [ V_33 ] -> V_34 . V_36 ) ;
V_30 += sprintf ( V_30 , L_10 ,
V_7 -> V_14 [ V_33 ] -> V_34 . V_37 ) ;
V_30 += sprintf ( V_30 , L_11 ,
V_7 -> V_14 [ V_33 ] -> V_34 . V_38 ) ;
V_30 += sprintf ( V_30 , L_12 ,
V_7 -> V_14 [ V_33 ] -> V_34 . V_39 ) ;
V_30 += sprintf ( V_30 , L_13 ,
V_7 -> V_14 [ V_33 ] -> V_34 . V_40 ) ;
F_9 ( V_41 L_14 ,
V_7 -> V_14 [ V_26 ] -> V_16 -> V_42 , V_29 ) ;
F_10 ( V_29 ) ;
return;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_43 * V_44 = F_12 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 || V_44 -> V_45 != V_46 )
return - V_8 ;
F_6 ( V_7 ) ;
return sprintf ( V_5 , L_15 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
memset ( & V_7 -> V_14 [ V_33 ] -> V_34 , 0 ,
sizeof( V_7 -> V_14 [ V_26 ] -> V_34 ) ) ;
return V_10 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_1 , V_7 -> V_47 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_10 )
{
int V_48 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
sscanf ( V_5 , L_3 , & V_48 ) ;
if ( ! ( ( V_48 == V_49 ) ||
( V_48 == V_50 ) ||
( V_48 == V_51 ) ||
( V_48 == V_52 ) ) )
return - V_28 ;
V_7 -> V_47 = V_48 ;
F_5 ( V_17 , V_2 , V_5 ) ;
return V_10 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_43 * V_53 ;
V_53 = F_12 ( V_2 ) ;
if ( ! V_53 )
return - V_8 ;
return sprintf ( V_5 , L_16 ,
V_54 [ V_53 -> V_55 [ 0 ] -> V_56 . V_57 ] ) ;
}
