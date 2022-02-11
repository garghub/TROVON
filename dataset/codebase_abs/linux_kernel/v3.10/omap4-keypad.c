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
struct V_10 * V_10 = V_2 -> V_11 ;
unsigned char V_12 [ F_8 ( V_2 -> V_12 ) ] ;
unsigned int V_13 , V_14 , V_15 , V_16 ;
T_1 * V_17 = ( T_1 * ) V_12 ;
F_6 ( V_2 , V_18 ,
V_19 ) ;
* V_17 = F_1 ( V_2 , V_20 ) ;
* ( V_17 + 1 ) = F_1 ( V_2 , V_21 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_22 ; V_14 ++ ) {
V_16 = V_12 [ V_14 ] ^ V_2 -> V_12 [ V_14 ] ;
if ( ! V_16 )
continue;
for ( V_13 = 0 ; V_13 < V_2 -> V_23 ; V_13 ++ ) {
if ( V_16 & ( 1 << V_13 ) ) {
V_15 = F_9 ( V_14 , V_13 ,
V_2 -> V_24 ) ;
F_10 ( V_10 , V_25 , V_26 , V_15 ) ;
F_11 ( V_10 ,
V_2 -> V_27 [ V_15 ] ,
V_12 [ V_14 ] & ( 1 << V_13 ) ) ;
}
}
}
F_12 ( V_10 ) ;
memcpy ( V_2 -> V_12 , V_12 ,
sizeof( V_2 -> V_12 ) ) ;
F_6 ( V_2 , V_28 ,
F_5 ( V_2 , V_28 ) ) ;
F_6 ( V_2 , V_18 ,
V_29 |
V_30 ) ;
return V_31 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_14 ( V_11 ) ;
F_15 ( V_11 -> V_32 . V_33 ) ;
F_16 ( V_2 -> V_8 ) ;
F_3 ( V_2 , V_34 ,
V_35 ) ;
F_3 ( V_2 , V_36 ,
V_37 ) ;
F_6 ( V_2 , V_28 ,
V_19 ) ;
F_6 ( V_2 , V_18 ,
V_29 |
V_30 ) ;
F_3 ( V_2 , V_38 ,
V_39 | V_40 ) ;
F_17 ( V_2 -> V_8 ) ;
return 0 ;
}
static void F_18 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_14 ( V_11 ) ;
F_16 ( V_2 -> V_8 ) ;
F_6 ( V_2 , V_18 ,
V_19 ) ;
F_6 ( V_2 , V_28 ,
F_5 ( V_2 , V_28 ) ) ;
F_17 ( V_2 -> V_8 ) ;
F_19 ( V_11 -> V_32 . V_33 ) ;
}
static int F_20 ( struct V_41 * V_32 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 = V_32 -> V_44 ;
int V_45 ;
V_45 = F_21 ( V_32 , & V_2 -> V_22 ,
& V_2 -> V_23 ) ;
if ( V_45 )
return V_45 ;
if ( F_22 ( V_43 , L_1 , NULL ) )
V_2 -> V_46 = true ;
return 0 ;
}
static inline int F_20 ( struct V_41 * V_32 ,
struct V_1 * V_2 )
{
return - V_47 ;
}
static int F_23 ( struct V_48 * V_49 )
{
const struct V_50 * V_51 =
F_24 ( & V_49 -> V_32 ) ;
const struct V_52 * V_53 =
V_51 ? V_51 -> V_53 : NULL ;
struct V_1 * V_2 ;
struct V_10 * V_10 ;
struct V_54 * V_55 ;
unsigned int V_56 ;
int V_57 ;
int V_8 ;
int error ;
V_55 = F_25 ( V_49 , V_58 , 0 ) ;
if ( ! V_55 ) {
F_26 ( & V_49 -> V_32 , L_2 ) ;
return - V_59 ;
}
V_8 = F_27 ( V_49 , 0 ) ;
if ( ! V_8 ) {
F_26 ( & V_49 -> V_32 , L_3 ) ;
return - V_59 ;
}
V_2 = F_28 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 ) {
F_26 ( & V_49 -> V_32 , L_4 ) ;
return - V_61 ;
}
V_2 -> V_8 = V_8 ;
if ( V_51 ) {
V_2 -> V_22 = V_51 -> V_22 ;
V_2 -> V_23 = V_51 -> V_23 ;
} else {
error = F_20 ( & V_49 -> V_32 , V_2 ) ;
if ( error )
return error ;
}
V_55 = F_29 ( V_55 -> V_62 , F_30 ( V_55 ) , V_49 -> V_63 ) ;
if ( ! V_55 ) {
F_26 ( & V_49 -> V_32 , L_5 ) ;
error = - V_64 ;
goto V_65;
}
V_2 -> V_4 = F_31 ( V_55 -> V_62 , F_30 ( V_55 ) ) ;
if ( ! V_2 -> V_4 ) {
F_26 ( & V_49 -> V_32 , L_6 ) ;
error = - V_61 ;
goto V_66;
}
F_32 ( & V_49 -> V_32 ) ;
error = F_15 ( & V_49 -> V_32 ) ;
if ( error ) {
F_26 ( & V_49 -> V_32 , L_7 ) ;
goto V_67;
}
V_57 = F_2 ( V_2 -> V_4 + V_68 ) ;
V_57 &= 0x03 << 30 ;
V_57 >>= 30 ;
switch ( V_57 ) {
case V_69 :
V_2 -> V_5 = 0x00 ;
V_2 -> V_7 = 0x00 ;
break;
case V_70 :
V_2 -> V_5 = 0x10 ;
V_2 -> V_7 = 0x0c ;
break;
default:
F_26 ( & V_49 -> V_32 ,
L_8 , V_57 ) ;
error = - V_59 ;
goto V_71;
}
V_2 -> V_11 = V_10 = F_33 () ;
if ( ! V_10 ) {
error = - V_61 ;
goto V_71;
}
V_10 -> V_63 = V_49 -> V_63 ;
V_10 -> V_32 . V_33 = & V_49 -> V_32 ;
V_10 -> V_72 . V_73 = V_74 ;
V_10 -> V_72 . V_75 = 0x0001 ;
V_10 -> V_72 . V_76 = 0x0001 ;
V_10 -> V_72 . V_77 = 0x0001 ;
V_10 -> V_78 = F_13 ;
V_10 -> V_79 = F_18 ;
F_34 ( V_10 , V_25 , V_26 ) ;
if ( ! V_2 -> V_46 )
F_35 ( V_80 , V_10 -> V_81 ) ;
F_36 ( V_10 , V_2 ) ;
V_2 -> V_24 = F_37 ( V_2 -> V_23 ) ;
V_56 = V_2 -> V_22 << V_2 -> V_24 ;
V_2 -> V_27 = F_28 ( V_56 * sizeof( V_2 -> V_27 [ 0 ] ) ,
V_60 ) ;
if ( ! V_2 -> V_27 ) {
F_26 ( & V_49 -> V_32 , L_9 ) ;
error = - V_61 ;
goto V_82;
}
error = F_38 ( V_53 , NULL ,
V_2 -> V_22 , V_2 -> V_23 ,
V_2 -> V_27 , V_10 ) ;
if ( error ) {
F_26 ( & V_49 -> V_32 , L_10 ) ;
goto V_83;
}
error = F_39 ( V_2 -> V_8 , F_7 ,
V_84 ,
L_11 , V_2 ) ;
if ( error ) {
F_26 ( & V_49 -> V_32 , L_12 ) ;
goto V_82;
}
F_19 ( & V_49 -> V_32 ) ;
error = F_40 ( V_2 -> V_11 ) ;
if ( error < 0 ) {
F_26 ( & V_49 -> V_32 , L_13 ) ;
goto V_85;
}
F_41 ( V_49 , V_2 ) ;
return 0 ;
V_85:
F_42 ( & V_49 -> V_32 ) ;
F_43 ( V_2 -> V_8 , V_2 ) ;
V_83:
F_44 ( V_2 -> V_27 ) ;
V_82:
F_45 ( V_10 ) ;
V_71:
F_19 ( & V_49 -> V_32 ) ;
V_67:
F_46 ( V_2 -> V_4 ) ;
V_66:
F_47 ( V_55 -> V_62 , F_30 ( V_55 ) ) ;
V_65:
F_44 ( V_2 ) ;
return error ;
}
static int F_48 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_49 ( V_49 ) ;
struct V_54 * V_55 ;
F_43 ( V_2 -> V_8 , V_2 ) ;
F_42 ( & V_49 -> V_32 ) ;
F_50 ( V_2 -> V_11 ) ;
F_46 ( V_2 -> V_4 ) ;
V_55 = F_25 ( V_49 , V_58 , 0 ) ;
F_47 ( V_55 -> V_62 , F_30 ( V_55 ) ) ;
F_44 ( V_2 -> V_27 ) ;
F_44 ( V_2 ) ;
F_41 ( V_49 , NULL ) ;
return 0 ;
}
