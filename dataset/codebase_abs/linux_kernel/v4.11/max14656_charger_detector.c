static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
T_2 V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 ,
L_1 ,
V_3 , V_5 ) ;
return V_5 ;
}
* V_4 = V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_2 V_5 ;
V_5 = F_5 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 ,
L_2 ,
V_4 , V_3 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_7 ( V_2 , V_3 , V_7 , V_4 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_3 ,
V_3 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 =
F_9 ( V_9 , struct V_10 , V_12 . V_9 ) ;
T_1 V_13 [ V_14 ] ;
T_1 V_15 ;
int V_5 = 0 ;
V_5 = F_6 ( V_11 -> V_2 , V_16 ,
V_14 , V_13 ) ;
if ( ( V_13 [ V_17 ] & V_18 ) &&
( V_13 [ V_17 ] & V_19 ) ) {
V_15 = V_13 [ V_17 ] & V_19 ;
if ( V_15 < V_20 )
V_11 -> V_21 . type = V_22 [ V_15 ] . type ;
else
V_11 -> V_21 . type = V_23 ;
V_11 -> V_24 = 1 ;
} else {
V_11 -> V_24 = 0 ;
V_11 -> V_21 . type = V_23 ;
}
F_10 ( V_11 -> V_25 ) ;
}
static T_3 F_11 ( int V_26 , void * V_27 )
{
struct V_10 * V_11 = V_27 ;
F_12 ( & V_11 -> V_12 , F_13 ( 100 ) ) ;
return V_28 ;
}
static int F_14 ( struct V_10 * V_11 )
{
T_4 V_4 = 0 ;
T_4 V_29 ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( F_1 ( V_2 , V_16 , & V_4 ) )
return - V_30 ;
if ( ( V_4 & V_31 ) != 0x20 ) {
F_3 ( & V_2 -> V_6 , L_4 ,
( ( V_4 & V_31 ) >> 4 ) ) ;
return - V_30 ;
}
V_29 = V_4 & V_32 ;
if ( F_4 ( V_2 , V_33 , V_34 ) )
return - V_35 ;
if ( F_4 ( V_2 , V_36 ,
V_37 |
V_38 |
V_39 |
V_40 ) )
return - V_35 ;
if ( F_4 ( V_2 , V_41 , 0x3 ) )
return - V_35 ;
if ( F_4 ( V_2 , V_42 , 0x1 ) )
return - V_35 ;
F_15 ( & V_2 -> V_6 , L_5 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_43 * V_44 ,
enum V_45 V_46 ,
union V_47 * V_4 )
{
struct V_10 * V_11 = F_17 ( V_44 ) ;
switch ( V_46 ) {
case V_48 :
V_4 -> V_49 = V_11 -> V_24 ;
break;
case V_50 :
V_4 -> V_51 = V_52 ;
break;
case V_53 :
V_4 -> V_51 = V_54 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_57 * V_58 = F_19 ( V_2 -> V_6 . V_59 ) ;
struct V_60 * V_6 = & V_2 -> V_6 ;
struct V_61 V_62 = {} ;
struct V_10 * V_11 ;
int V_26 = V_2 -> V_26 ;
int V_5 = 0 ;
if ( V_26 <= 0 ) {
F_3 ( V_6 , L_6 , V_26 ) ;
return - V_30 ;
}
if ( ! F_20 ( V_58 , V_63 ) ) {
F_3 ( V_6 , L_7 ) ;
return - V_30 ;
}
V_11 = F_21 ( V_6 , sizeof( * V_11 ) , V_64 ) ;
if ( ! V_11 )
return - V_65 ;
V_62 . V_66 = V_11 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_24 = 0 ;
V_11 -> V_21 . V_67 = V_52 ;
V_11 -> V_21 . type = V_23 ;
V_11 -> V_21 . V_68 = V_69 ;
V_11 -> V_21 . V_70 = F_22 ( V_69 ) ;
V_11 -> V_21 . V_71 = F_16 ;
V_11 -> V_26 = V_26 ;
V_5 = F_14 ( V_11 ) ;
if ( V_5 )
return - V_30 ;
F_23 ( & V_11 -> V_12 , F_8 ) ;
V_5 = F_24 ( V_6 , V_11 -> V_26 , F_11 ,
V_72 ,
V_52 , V_11 ) ;
if ( V_5 ) {
F_3 ( V_6 , L_8 , V_11 -> V_26 ) ;
return - V_35 ;
}
F_25 ( V_11 -> V_26 ) ;
V_11 -> V_25 = F_26 ( V_6 ,
& V_11 -> V_21 , & V_62 ) ;
if ( F_27 ( V_11 -> V_25 ) ) {
F_3 ( V_6 , L_9 ) ;
return - V_35 ;
}
F_12 ( & V_11 -> V_12 , F_13 ( 2000 ) ) ;
return 0 ;
}
