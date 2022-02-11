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
if ( ! F_18 ( V_60 , 4 , L_7 ) ) {
F_14 ( V_1 , L_8 ) ;
return - V_61 ;
}
V_59 = ~ V_62 ;
F_5 ( V_63 , 0 , V_48 , V_59 , V_17 , V_18 ) ;
if ( V_59 != V_62 || V_48 == 0xffffffffU ) {
F_19 ( V_60 , 4 ) ;
return - V_50 ;
}
if ( V_58 ) {
V_1 -> V_64 = V_65 ;
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_48 ;
}
F_19 ( V_60 , 4 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_12 ;
F_11 ( V_1 ) ;
F_21 ( V_1 ) ;
F_22 ( V_11 -> V_3 ) ;
F_23 ( V_11 ) ;
F_19 ( V_60 , 4 ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
int error ;
F_21 ( V_1 ) ;
F_11 ( V_1 ) ;
error = F_13 ( V_1 ) ;
if ( error ) {
F_6 ( V_1 ,
L_9 ,
error ) ;
return error ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_1 )
{
struct V_10 * V_11 ;
struct V_2 * V_4 = V_1 -> V_9 , * V_3 ;
int error ;
if ( ! F_18 ( V_60 , 4 , L_7 ) ) {
F_14 ( V_1 , L_8 ) ;
return - V_61 ;
}
F_21 ( V_1 ) ;
error = F_13 ( V_1 ) ;
if ( error )
goto F_19;
V_11 = F_26 ( sizeof( * V_11 ) , V_69 ) ;
V_3 = F_27 () ;
if ( ! V_11 || ! V_3 ) {
error = - V_70 ;
goto V_71;
}
V_11 -> V_3 = V_3 ;
V_1 -> V_12 = V_11 ;
F_28 ( V_4 , V_72 , V_32 ) ;
snprintf ( V_11 -> V_73 , sizeof( V_11 -> V_73 ) , L_10 ,
V_1 -> V_74 . V_75 -> V_73 ) ;
snprintf ( V_11 -> V_76 , sizeof( V_11 -> V_76 ) , L_11 ,
V_77 , V_65 , V_67 ) ;
V_3 -> V_73 = V_11 -> V_73 ;
V_3 -> V_66 = V_11 -> V_76 ;
V_3 -> V_78 . V_79 = V_80 ;
V_3 -> V_78 . V_64 = 0x0002 ;
V_3 -> V_78 . V_81 = V_82 ;
V_3 -> V_78 . V_48 = V_1 -> V_68 ;
V_3 -> V_9 . V_83 = & V_1 -> V_74 . V_75 -> V_9 ;
error = F_29 ( V_11 -> V_3 ) ;
if ( error )
goto V_71;
F_28 ( V_3 , V_84 , V_35 ) ;
F_28 ( V_3 , V_84 , V_37 ) ;
F_28 ( V_3 , V_84 , V_39 ) ;
F_28 ( V_3 , V_85 , V_30 ) ;
F_28 ( V_3 , V_85 , V_31 ) ;
F_30 ( V_3 , V_30 , 0 , V_86 , 0 , 0 ) ;
F_30 ( V_3 , V_31 , 0 , V_87 , 0 , 0 ) ;
V_1 -> V_88 = F_10 ;
V_1 -> V_89 = F_20 ;
V_1 -> V_90 = F_24 ;
return 0 ;
V_71:
F_11 ( V_1 ) ;
F_21 ( V_1 ) ;
F_31 ( V_3 ) ;
F_23 ( V_11 ) ;
V_1 -> V_12 = NULL ;
F_19:
F_19 ( V_60 , 4 ) ;
return error ;
}
