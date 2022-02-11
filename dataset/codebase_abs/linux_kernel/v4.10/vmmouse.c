static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_2 * V_4 ,
struct V_2 * V_5 ,
unsigned int V_6 , int V_7 )
{
if ( F_2 ( V_6 , V_3 -> V_8 ) )
V_5 = V_3 ;
else if ( F_2 ( V_6 , V_4 -> V_8 ) )
V_5 = V_4 ;
F_3 ( V_5 , V_6 , V_7 ) ;
}
static T_1 F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_4 = V_1 -> V_9 ;
struct V_10 * V_11 = V_1 -> V_12 ;
struct V_2 * V_3 = V_11 -> V_3 ;
struct V_2 * V_5 ;
T_2 V_13 , V_14 , V_15 , V_16 ;
T_2 V_17 , V_18 , V_19 ;
unsigned int V_20 ;
unsigned int V_21 = 255 ;
while ( V_21 -- ) {
F_5 ( V_22 , 0 ,
V_13 , V_17 , V_18 , V_19 ) ;
if ( ( V_13 & V_23 ) == V_23 ) {
F_6 ( V_1 , L_1 ) ;
return V_24 ;
}
V_20 = V_13 & 0xffff ;
if ( V_20 == 0 )
break;
if ( V_20 % 4 ) {
F_6 ( V_1 , L_2 ) ;
return V_24 ;
}
F_5 ( V_25 , 4 , V_13 , V_14 , V_15 , V_16 ) ;
if ( V_13 & V_26 ) {
V_5 = V_4 ;
F_7 ( V_4 , V_27 , ( V_28 ) V_14 ) ;
F_7 ( V_4 , V_29 , - ( V_28 ) V_15 ) ;
} else {
V_5 = V_3 ;
F_8 ( V_3 , V_30 , V_14 ) ;
F_8 ( V_3 , V_31 , V_15 ) ;
}
F_7 ( V_4 , V_32 , - ( V_33 ) ( ( V_34 ) V_16 ) ) ;
F_1 ( V_1 , V_3 , V_4 ,
V_5 , V_35 ,
V_13 & V_36 ) ;
F_1 ( V_1 , V_3 , V_4 ,
V_5 , V_37 ,
V_13 & V_38 ) ;
F_1 ( V_1 , V_3 , V_4 ,
V_5 , V_39 ,
V_13 & V_40 ) ;
F_9 ( V_3 ) ;
F_9 ( V_4 ) ;
}
return V_41 ;
}
static T_1 F_10 ( struct V_1 * V_1 )
{
unsigned char * V_42 = V_1 -> V_42 ;
switch ( V_1 -> V_43 ) {
case 1 :
return ( V_42 [ 0 ] & 0x8 ) == 0x8 ?
V_44 : V_24 ;
case 2 :
return V_44 ;
default:
return F_4 ( V_1 ) ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
T_2 V_13 ;
T_2 V_17 , V_18 , V_19 , V_45 ;
F_5 ( V_46 , V_47 ,
V_17 , V_18 , V_19 , V_45 ) ;
F_5 ( V_22 , 0 ,
V_13 , V_17 , V_18 , V_19 ) ;
if ( ( V_13 & V_23 ) != V_23 )
F_12 ( V_1 , L_3 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
T_2 V_13 , V_48 ;
T_2 V_17 , V_18 , V_19 , V_45 ;
F_5 ( V_46 , V_49 ,
V_17 , V_18 , V_19 , V_45 ) ;
F_5 ( V_22 , 0 , V_13 , V_17 , V_18 , V_19 ) ;
if ( ( V_13 & 0x0000ffff ) == 0 ) {
F_14 ( V_1 , L_4 ) ;
return - V_50 ;
}
F_5 ( V_25 , 1 ,
V_48 , V_17 , V_18 , V_19 ) ;
if ( V_48 != V_51 ) {
F_14 ( V_1 , L_5 ,
( unsigned ) V_48 , V_51 ) ;
F_11 ( V_1 ) ;
return - V_50 ;
}
F_5 ( V_52 , V_53 ,
V_17 , V_18 , V_19 , V_45 ) ;
F_5 ( V_46 , V_54 ,
V_17 , V_18 , V_19 , V_45 ) ;
return 0 ;
}
static bool F_15 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < F_16 ( V_56 ) ; V_55 ++ )
if ( V_56 [ V_55 ] == V_57 )
return true ;
return false ;
}
int F_17 ( struct V_1 * V_1 , bool V_58 )
{
T_2 V_59 , V_48 , V_17 , V_18 ;
if ( ! F_15 () ) {
F_14 ( V_1 ,
L_6 ) ;
return - V_50 ;
}
V_59 = ~ V_60 ;
F_5 ( V_61 , 0 , V_48 , V_59 , V_17 , V_18 ) ;
if ( V_59 != V_60 || V_48 == 0xffffffffU )
return - V_50 ;
if ( V_58 ) {
V_1 -> V_62 = V_63 ;
V_1 -> V_64 = V_65 ;
V_1 -> V_66 = V_48 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_12 ;
F_11 ( V_1 ) ;
F_19 ( V_1 ) ;
F_20 ( V_11 -> V_3 ) ;
F_21 ( V_11 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
int error ;
F_19 ( V_1 ) ;
F_11 ( V_1 ) ;
error = F_13 ( V_1 ) ;
if ( error ) {
F_6 ( V_1 ,
L_7 ,
error ) ;
return error ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 )
{
struct V_10 * V_11 ;
struct V_2 * V_4 = V_1 -> V_9 , * V_3 ;
int error ;
F_19 ( V_1 ) ;
error = F_13 ( V_1 ) ;
if ( error )
return error ;
V_11 = F_24 ( sizeof( * V_11 ) , V_67 ) ;
V_3 = F_25 () ;
if ( ! V_11 || ! V_3 ) {
error = - V_68 ;
goto V_69;
}
V_11 -> V_3 = V_3 ;
V_1 -> V_12 = V_11 ;
snprintf ( V_11 -> V_70 , sizeof( V_11 -> V_70 ) , L_8 ,
V_1 -> V_71 . V_72 -> V_70 ) ;
snprintf ( V_11 -> V_73 , sizeof( V_11 -> V_73 ) , L_9 ,
V_74 , V_63 , V_65 ) ;
V_3 -> V_70 = V_11 -> V_70 ;
V_3 -> V_64 = V_11 -> V_73 ;
V_3 -> V_75 . V_76 = V_77 ;
V_3 -> V_75 . V_62 = 0x0002 ;
V_3 -> V_75 . V_78 = V_79 ;
V_3 -> V_75 . V_48 = V_1 -> V_66 ;
V_3 -> V_9 . V_80 = & V_1 -> V_71 . V_72 -> V_9 ;
F_26 ( V_3 , V_81 , V_35 ) ;
F_26 ( V_3 , V_81 , V_37 ) ;
F_26 ( V_3 , V_81 , V_39 ) ;
F_26 ( V_3 , V_82 , V_30 ) ;
F_26 ( V_3 , V_82 , V_31 ) ;
F_27 ( V_3 , V_30 , 0 , V_83 , 0 , 0 ) ;
F_27 ( V_3 , V_31 , 0 , V_84 , 0 , 0 ) ;
error = F_28 ( V_11 -> V_3 ) ;
if ( error )
goto V_69;
F_26 ( V_4 , V_85 , V_32 ) ;
V_1 -> V_86 = F_10 ;
V_1 -> V_87 = F_18 ;
V_1 -> V_88 = F_22 ;
return 0 ;
V_69:
F_11 ( V_1 ) ;
F_19 ( V_1 ) ;
F_29 ( V_3 ) ;
F_21 ( V_11 ) ;
V_1 -> V_12 = NULL ;
return error ;
}
