static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 +
V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 ,
V_2 -> V_4 + V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 +
V_2 -> V_7 + V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 ,
V_2 -> V_4 + V_2 -> V_7 + V_3 ) ;
}
static T_2 F_7 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
if ( F_5 ( V_2 , V_10 ) ) {
F_6 ( V_2 , V_11 ,
V_12 ) ;
return V_13 ;
}
return V_14 ;
}
static T_2 F_8 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
struct V_15 * V_15 = V_2 -> V_16 ;
unsigned char V_17 [ F_9 ( V_2 -> V_17 ) ] ;
unsigned int V_18 , V_19 , V_20 , V_21 ;
T_1 * V_22 = ( T_1 * ) V_17 ;
* V_22 = F_1 ( V_2 , V_23 ) ;
* ( V_22 + 1 ) = F_1 ( V_2 , V_24 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_25 ; V_19 ++ ) {
V_21 = V_17 [ V_19 ] ^ V_2 -> V_17 [ V_19 ] ;
if ( ! V_21 )
continue;
for ( V_18 = 0 ; V_18 < V_2 -> V_26 ; V_18 ++ ) {
if ( V_21 & ( 1 << V_18 ) ) {
V_20 = F_10 ( V_19 , V_18 ,
V_2 -> V_27 ) ;
F_11 ( V_15 , V_28 , V_29 , V_20 ) ;
F_12 ( V_15 ,
V_2 -> V_30 [ V_20 ] ,
V_17 [ V_19 ] & ( 1 << V_18 ) ) ;
}
}
}
F_13 ( V_15 ) ;
memcpy ( V_2 -> V_17 , V_17 ,
sizeof( V_2 -> V_17 ) ) ;
F_6 ( V_2 , V_10 ,
F_5 ( V_2 , V_10 ) ) ;
F_6 ( V_2 , V_11 ,
V_31 |
V_32 ) ;
return V_33 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
F_16 ( V_16 -> V_34 . V_35 ) ;
F_17 ( V_2 -> V_8 ) ;
F_3 ( V_2 , V_36 ,
V_37 |
( V_38 << V_39 ) ) ;
F_3 ( V_2 , V_40 ,
V_41 ) ;
F_6 ( V_2 , V_10 ,
F_5 ( V_2 , V_10 ) ) ;
F_6 ( V_2 , V_11 ,
V_31 |
V_32 ) ;
F_3 ( V_2 , V_42 ,
V_43 | V_44 ) ;
F_18 ( V_2 -> V_8 ) ;
return 0 ;
}
static void F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
F_17 ( V_2 -> V_8 ) ;
F_6 ( V_2 , V_11 ,
V_12 ) ;
F_6 ( V_2 , V_10 ,
F_5 ( V_2 , V_10 ) ) ;
F_18 ( V_2 -> V_8 ) ;
F_20 ( V_16 -> V_34 . V_35 ) ;
}
static int F_21 ( struct V_45 * V_34 ,
struct V_1 * V_2 )
{
struct V_46 * V_47 = V_34 -> V_48 ;
int V_49 ;
V_49 = F_22 ( V_34 , & V_2 -> V_25 ,
& V_2 -> V_26 ) ;
if ( V_49 )
return V_49 ;
if ( F_23 ( V_47 , L_1 , NULL ) )
V_2 -> V_50 = true ;
return 0 ;
}
static int F_24 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_15 * V_15 ;
struct V_53 * V_54 ;
unsigned int V_55 ;
int V_56 ;
int V_8 ;
int error ;
V_54 = F_25 ( V_52 , V_57 , 0 ) ;
if ( ! V_54 ) {
F_26 ( & V_52 -> V_34 , L_2 ) ;
return - V_58 ;
}
V_8 = F_27 ( V_52 , 0 ) ;
if ( ! V_8 ) {
F_26 ( & V_52 -> V_34 , L_3 ) ;
return - V_58 ;
}
V_2 = F_28 ( sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 ) {
F_26 ( & V_52 -> V_34 , L_4 ) ;
return - V_60 ;
}
V_2 -> V_8 = V_8 ;
error = F_21 ( & V_52 -> V_34 , V_2 ) ;
if ( error )
return error ;
V_54 = F_29 ( V_54 -> V_61 , F_30 ( V_54 ) , V_52 -> V_62 ) ;
if ( ! V_54 ) {
F_26 ( & V_52 -> V_34 , L_5 ) ;
error = - V_63 ;
goto V_64;
}
V_2 -> V_4 = F_31 ( V_54 -> V_61 , F_30 ( V_54 ) ) ;
if ( ! V_2 -> V_4 ) {
F_26 ( & V_52 -> V_34 , L_6 ) ;
error = - V_60 ;
goto V_65;
}
F_32 ( & V_52 -> V_34 ) ;
error = F_16 ( & V_52 -> V_34 ) ;
if ( error ) {
F_26 ( & V_52 -> V_34 , L_7 ) ;
goto V_66;
}
V_56 = F_2 ( V_2 -> V_4 + V_67 ) ;
V_56 &= 0x03 << 30 ;
V_56 >>= 30 ;
switch ( V_56 ) {
case V_68 :
V_2 -> V_5 = 0x00 ;
V_2 -> V_7 = 0x00 ;
break;
case V_69 :
V_2 -> V_5 = 0x10 ;
V_2 -> V_7 = 0x0c ;
break;
default:
F_26 ( & V_52 -> V_34 ,
L_8 , V_56 ) ;
error = - V_58 ;
goto V_70;
}
V_2 -> V_16 = V_15 = F_33 () ;
if ( ! V_15 ) {
error = - V_60 ;
goto V_70;
}
V_15 -> V_62 = V_52 -> V_62 ;
V_15 -> V_34 . V_35 = & V_52 -> V_34 ;
V_15 -> V_71 . V_72 = V_73 ;
V_15 -> V_71 . V_74 = 0x0001 ;
V_15 -> V_71 . V_75 = 0x0001 ;
V_15 -> V_71 . V_76 = 0x0001 ;
V_15 -> V_77 = F_14 ;
V_15 -> V_78 = F_19 ;
F_34 ( V_15 , V_28 , V_29 ) ;
if ( ! V_2 -> V_50 )
F_35 ( V_79 , V_15 -> V_80 ) ;
F_36 ( V_15 , V_2 ) ;
V_2 -> V_27 = F_37 ( V_2 -> V_26 ) ;
V_55 = V_2 -> V_25 << V_2 -> V_27 ;
V_2 -> V_30 = F_28 ( V_55 * sizeof( V_2 -> V_30 [ 0 ] ) ,
V_59 ) ;
if ( ! V_2 -> V_30 ) {
F_26 ( & V_52 -> V_34 , L_9 ) ;
error = - V_60 ;
goto V_81;
}
error = F_38 ( NULL , NULL ,
V_2 -> V_25 , V_2 -> V_26 ,
V_2 -> V_30 , V_15 ) ;
if ( error ) {
F_26 ( & V_52 -> V_34 , L_10 ) ;
goto V_82;
}
error = F_39 ( V_2 -> V_8 , F_7 ,
F_8 , 0 ,
L_11 , V_2 ) ;
if ( error ) {
F_26 ( & V_52 -> V_34 , L_12 ) ;
goto V_81;
}
F_40 ( & V_52 -> V_34 , true ) ;
F_20 ( & V_52 -> V_34 ) ;
error = F_41 ( V_2 -> V_16 ) ;
if ( error < 0 ) {
F_26 ( & V_52 -> V_34 , L_13 ) ;
goto V_83;
}
F_42 ( V_52 , V_2 ) ;
return 0 ;
V_83:
F_43 ( & V_52 -> V_34 ) ;
F_40 ( & V_52 -> V_34 , false ) ;
F_44 ( V_2 -> V_8 , V_2 ) ;
V_82:
F_45 ( V_2 -> V_30 ) ;
V_81:
F_46 ( V_15 ) ;
V_70:
F_20 ( & V_52 -> V_34 ) ;
V_66:
F_47 ( V_2 -> V_4 ) ;
V_65:
F_48 ( V_54 -> V_61 , F_30 ( V_54 ) ) ;
V_64:
F_45 ( V_2 ) ;
return error ;
}
static int F_49 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_50 ( V_52 ) ;
struct V_53 * V_54 ;
F_44 ( V_2 -> V_8 , V_2 ) ;
F_43 ( & V_52 -> V_34 ) ;
F_40 ( & V_52 -> V_34 , false ) ;
F_51 ( V_2 -> V_16 ) ;
F_47 ( V_2 -> V_4 ) ;
V_54 = F_25 ( V_52 , V_57 , 0 ) ;
F_48 ( V_54 -> V_61 , F_30 ( V_54 ) ) ;
F_45 ( V_2 -> V_30 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_45 * V_34 )
{
struct V_51 * V_52 = F_53 ( V_34 ) ;
struct V_1 * V_2 = F_50 ( V_52 ) ;
int error ;
if ( F_54 ( & V_52 -> V_34 ) ) {
error = F_55 ( V_2 -> V_8 ) ;
if ( ! error )
V_2 -> V_84 = true ;
}
return 0 ;
}
static int F_56 ( struct V_45 * V_34 )
{
struct V_51 * V_52 = F_53 ( V_34 ) ;
struct V_1 * V_2 = F_50 ( V_52 ) ;
if ( F_54 ( & V_52 -> V_34 ) && V_2 -> V_84 ) {
F_57 ( V_2 -> V_8 ) ;
V_2 -> V_84 = false ;
}
return 0 ;
}
