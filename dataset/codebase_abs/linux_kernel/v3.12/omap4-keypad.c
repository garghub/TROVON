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
static inline int F_21 ( struct V_45 * V_34 ,
struct V_1 * V_2 )
{
return - V_51 ;
}
static int F_24 ( struct V_52 * V_53 )
{
const struct V_54 * V_55 =
F_25 ( & V_53 -> V_34 ) ;
const struct V_56 * V_57 =
V_55 ? V_55 -> V_57 : NULL ;
struct V_1 * V_2 ;
struct V_15 * V_15 ;
struct V_58 * V_59 ;
unsigned int V_60 ;
int V_61 ;
int V_8 ;
int error ;
V_59 = F_26 ( V_53 , V_62 , 0 ) ;
if ( ! V_59 ) {
F_27 ( & V_53 -> V_34 , L_2 ) ;
return - V_63 ;
}
V_8 = F_28 ( V_53 , 0 ) ;
if ( ! V_8 ) {
F_27 ( & V_53 -> V_34 , L_3 ) ;
return - V_63 ;
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_2 ) {
F_27 ( & V_53 -> V_34 , L_4 ) ;
return - V_65 ;
}
V_2 -> V_8 = V_8 ;
if ( V_55 ) {
V_2 -> V_25 = V_55 -> V_25 ;
V_2 -> V_26 = V_55 -> V_26 ;
} else {
error = F_21 ( & V_53 -> V_34 , V_2 ) ;
if ( error )
return error ;
}
V_59 = F_30 ( V_59 -> V_66 , F_31 ( V_59 ) , V_53 -> V_67 ) ;
if ( ! V_59 ) {
F_27 ( & V_53 -> V_34 , L_5 ) ;
error = - V_68 ;
goto V_69;
}
V_2 -> V_4 = F_32 ( V_59 -> V_66 , F_31 ( V_59 ) ) ;
if ( ! V_2 -> V_4 ) {
F_27 ( & V_53 -> V_34 , L_6 ) ;
error = - V_65 ;
goto V_70;
}
F_33 ( & V_53 -> V_34 ) ;
error = F_16 ( & V_53 -> V_34 ) ;
if ( error ) {
F_27 ( & V_53 -> V_34 , L_7 ) ;
goto V_71;
}
V_61 = F_2 ( V_2 -> V_4 + V_72 ) ;
V_61 &= 0x03 << 30 ;
V_61 >>= 30 ;
switch ( V_61 ) {
case V_73 :
V_2 -> V_5 = 0x00 ;
V_2 -> V_7 = 0x00 ;
break;
case V_74 :
V_2 -> V_5 = 0x10 ;
V_2 -> V_7 = 0x0c ;
break;
default:
F_27 ( & V_53 -> V_34 ,
L_8 , V_61 ) ;
error = - V_63 ;
goto V_75;
}
V_2 -> V_16 = V_15 = F_34 () ;
if ( ! V_15 ) {
error = - V_65 ;
goto V_75;
}
V_15 -> V_67 = V_53 -> V_67 ;
V_15 -> V_34 . V_35 = & V_53 -> V_34 ;
V_15 -> V_76 . V_77 = V_78 ;
V_15 -> V_76 . V_79 = 0x0001 ;
V_15 -> V_76 . V_80 = 0x0001 ;
V_15 -> V_76 . V_81 = 0x0001 ;
V_15 -> V_82 = F_14 ;
V_15 -> V_83 = F_19 ;
F_35 ( V_15 , V_28 , V_29 ) ;
if ( ! V_2 -> V_50 )
F_36 ( V_84 , V_15 -> V_85 ) ;
F_37 ( V_15 , V_2 ) ;
V_2 -> V_27 = F_38 ( V_2 -> V_26 ) ;
V_60 = V_2 -> V_25 << V_2 -> V_27 ;
V_2 -> V_30 = F_29 ( V_60 * sizeof( V_2 -> V_30 [ 0 ] ) ,
V_64 ) ;
if ( ! V_2 -> V_30 ) {
F_27 ( & V_53 -> V_34 , L_9 ) ;
error = - V_65 ;
goto V_86;
}
error = F_39 ( V_57 , NULL ,
V_2 -> V_25 , V_2 -> V_26 ,
V_2 -> V_30 , V_15 ) ;
if ( error ) {
F_27 ( & V_53 -> V_34 , L_10 ) ;
goto V_87;
}
error = F_40 ( V_2 -> V_8 , F_7 ,
F_8 , 0 ,
L_11 , V_2 ) ;
if ( error ) {
F_27 ( & V_53 -> V_34 , L_12 ) ;
goto V_86;
}
F_41 ( & V_53 -> V_34 , true ) ;
F_20 ( & V_53 -> V_34 ) ;
error = F_42 ( V_2 -> V_16 ) ;
if ( error < 0 ) {
F_27 ( & V_53 -> V_34 , L_13 ) ;
goto V_88;
}
F_43 ( V_53 , V_2 ) ;
return 0 ;
V_88:
F_44 ( & V_53 -> V_34 ) ;
F_41 ( & V_53 -> V_34 , false ) ;
F_45 ( V_2 -> V_8 , V_2 ) ;
V_87:
F_46 ( V_2 -> V_30 ) ;
V_86:
F_47 ( V_15 ) ;
V_75:
F_20 ( & V_53 -> V_34 ) ;
V_71:
F_48 ( V_2 -> V_4 ) ;
V_70:
F_49 ( V_59 -> V_66 , F_31 ( V_59 ) ) ;
V_69:
F_46 ( V_2 ) ;
return error ;
}
static int F_50 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_51 ( V_53 ) ;
struct V_58 * V_59 ;
F_45 ( V_2 -> V_8 , V_2 ) ;
F_44 ( & V_53 -> V_34 ) ;
F_41 ( & V_53 -> V_34 , false ) ;
F_52 ( V_2 -> V_16 ) ;
F_48 ( V_2 -> V_4 ) ;
V_59 = F_26 ( V_53 , V_62 , 0 ) ;
F_49 ( V_59 -> V_66 , F_31 ( V_59 ) ) ;
F_46 ( V_2 -> V_30 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_45 * V_34 )
{
struct V_52 * V_53 = F_54 ( V_34 ) ;
struct V_1 * V_2 = F_51 ( V_53 ) ;
int error ;
if ( F_55 ( & V_53 -> V_34 ) ) {
error = F_56 ( V_2 -> V_8 ) ;
if ( ! error )
V_2 -> V_89 = true ;
}
return 0 ;
}
static int F_57 ( struct V_45 * V_34 )
{
struct V_52 * V_53 = F_54 ( V_34 ) ;
struct V_1 * V_2 = F_51 ( V_53 ) ;
if ( F_55 ( & V_53 -> V_34 ) && V_2 -> V_89 ) {
F_58 ( V_2 -> V_8 ) ;
V_2 -> V_89 = false ;
}
return 0 ;
}
