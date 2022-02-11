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
unsigned int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_14 ;
V_12 = V_7 -> V_15 [ V_16 ] -> V_17 ;
if ( ! ( V_7 && V_7 -> V_15 [ V_16 ] && V_12 ) ) {
F_4 ( V_18 , V_19 , L_2 ) ;
return - V_8 ;
}
V_14 = sscanf ( V_5 , L_3 , & V_13 ) ;
if ( V_14 != 1 )
goto V_20;
if ( V_13 > V_21 )
goto V_20;
if ( V_13 < ( 576 + V_22 + 2 ) )
goto V_20;
V_7 -> V_9 = V_13 ;
if ( ( V_12 -> V_23 & V_24 ) &&
( V_13 < ( V_12 -> V_25 + V_22 + 2 ) ) )
goto V_20;
V_7 -> V_15 [ V_16 ] -> V_26 = V_13 ;
V_7 -> V_15 [ V_27 ] -> V_26 = V_13 ;
if ( ! ( V_12 -> V_23 & V_24 ) )
V_12 -> V_25 = V_13 - V_22 - 2 ;
V_7 -> V_15 [ V_16 ] -> V_23 |= V_28 ;
V_7 -> V_15 [ V_27 ] -> V_23 |= V_28 ;
F_5 ( V_18 , V_12 , V_5 ) ;
return V_10 ;
V_20:
F_5 ( V_18 , V_12 , L_4 ) ;
return - V_29 ;
}
static void F_6 ( struct V_6 * V_7 )
{
char * V_30 ;
char * V_31 ;
if ( ! V_7 )
return;
V_30 = F_7 ( 2048 , V_32 ) ;
if ( V_30 == NULL )
return;
V_31 = V_30 ;
V_31 += sprintf ( V_31 , L_5 ,
F_8 ( V_7 -> V_33 ) ) ;
V_31 += sprintf ( V_31 , L_6 ,
F_8 ( V_7 -> V_15 [ V_16 ] -> V_33 ) ) ;
V_31 += sprintf ( V_31 , L_7 ,
F_8 ( V_7 -> V_15 [ V_27 ] -> V_33 ) ) ;
V_31 += sprintf ( V_31 , L_8 ,
V_7 -> V_15 [ V_34 ] -> V_35 . V_36 ) ;
V_31 += sprintf ( V_31 , L_9 ,
V_7 -> V_15 [ V_34 ] -> V_35 . V_37 ) ;
V_31 += sprintf ( V_31 , L_10 ,
V_7 -> V_15 [ V_34 ] -> V_35 . V_38 ) ;
V_31 += sprintf ( V_31 , L_11 ,
V_7 -> V_15 [ V_34 ] -> V_35 . V_39 ) ;
V_31 += sprintf ( V_31 , L_12 ,
V_7 -> V_15 [ V_34 ] -> V_35 . V_40 ) ;
V_31 += sprintf ( V_31 , L_13 ,
V_7 -> V_15 [ V_34 ] -> V_35 . V_41 ) ;
F_9 ( V_42 L_14 ,
V_7 -> V_15 [ V_27 ] -> V_17 -> V_43 , V_30 ) ;
F_10 ( V_30 ) ;
return;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_44 * V_45 = F_12 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 || V_45 -> V_46 != V_47 )
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
memset ( & V_7 -> V_15 [ V_34 ] -> V_35 , 0 ,
sizeof( V_7 -> V_15 [ V_27 ] -> V_35 ) ) ;
return V_10 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
return sprintf ( V_5 , L_1 , V_7 -> V_48 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_10 )
{
int V_49 , V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return - V_8 ;
V_14 = sscanf ( V_5 , L_16 , & V_49 ) ;
if ( ( V_14 != 1 ) ||
! ( ( V_49 == V_50 ) ||
( V_49 == V_51 ) ||
( V_49 == V_52 ) ||
( V_49 == V_53 ) ) )
return - V_29 ;
V_7 -> V_48 = V_49 ;
F_5 ( V_18 , V_2 , V_5 ) ;
return V_10 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_44 * V_54 ;
V_54 = F_12 ( V_2 ) ;
if ( ! V_54 )
return - V_8 ;
return sprintf ( V_5 , L_17 ,
V_55 [ V_54 -> V_56 [ 0 ] -> V_57 . V_58 ] ) ;
}
