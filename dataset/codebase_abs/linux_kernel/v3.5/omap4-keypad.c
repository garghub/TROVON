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
static int T_3 F_20 ( struct V_41 * V_42 )
{
const struct V_43 * V_44 ;
struct V_1 * V_2 ;
struct V_10 * V_10 ;
struct V_45 * V_46 ;
T_4 V_47 ;
unsigned int V_24 , V_48 ;
int V_49 ;
int V_8 ;
int error ;
V_44 = V_42 -> V_32 . V_50 ;
if ( ! V_44 ) {
F_21 ( & V_42 -> V_32 , L_1 ) ;
return - V_51 ;
}
V_46 = F_22 ( V_42 , V_52 , 0 ) ;
if ( ! V_46 ) {
F_21 ( & V_42 -> V_32 , L_2 ) ;
return - V_51 ;
}
V_8 = F_23 ( V_42 , 0 ) ;
if ( ! V_8 ) {
F_21 ( & V_42 -> V_32 , L_3 ) ;
return - V_51 ;
}
if ( ! V_44 -> V_53 ) {
F_21 ( & V_42 -> V_32 , L_4 ) ;
return - V_51 ;
}
V_24 = F_24 ( V_44 -> V_23 ) ;
V_48 = V_44 -> V_22 << V_24 ;
V_2 = F_25 ( sizeof( struct V_1 ) +
V_48 * sizeof( V_2 -> V_27 [ 0 ] ) ,
V_54 ) ;
if ( ! V_2 ) {
F_21 ( & V_42 -> V_32 , L_5 ) ;
return - V_55 ;
}
V_47 = F_26 ( V_46 ) ;
V_46 = F_27 ( V_46 -> V_56 , V_47 , V_42 -> V_57 ) ;
if ( ! V_46 ) {
F_21 ( & V_42 -> V_32 , L_6 ) ;
error = - V_58 ;
goto V_59;
}
V_2 -> V_4 = F_28 ( V_46 -> V_56 , F_26 ( V_46 ) ) ;
if ( ! V_2 -> V_4 ) {
F_21 ( & V_42 -> V_32 , L_7 ) ;
error = - V_55 ;
goto V_60;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_22 = V_44 -> V_22 ;
V_2 -> V_23 = V_44 -> V_23 ;
F_29 ( & V_42 -> V_32 ) ;
error = F_15 ( & V_42 -> V_32 ) ;
if ( error ) {
F_21 ( & V_42 -> V_32 , L_8 ) ;
goto V_61;
}
V_49 = F_2 ( V_2 -> V_4 + V_62 ) ;
V_49 &= 0x03 << 30 ;
V_49 >>= 30 ;
switch ( V_49 ) {
case V_63 :
V_2 -> V_5 = 0x00 ;
V_2 -> V_7 = 0x00 ;
break;
case V_64 :
V_2 -> V_5 = 0x10 ;
V_2 -> V_7 = 0x0c ;
break;
default:
F_21 ( & V_42 -> V_32 ,
L_9 , V_49 ) ;
error = - V_51 ;
goto V_65;
}
V_2 -> V_11 = V_10 = F_30 () ;
if ( ! V_10 ) {
error = - V_55 ;
goto V_65;
}
V_10 -> V_57 = V_42 -> V_57 ;
V_10 -> V_32 . V_33 = & V_42 -> V_32 ;
V_10 -> V_66 . V_67 = V_68 ;
V_10 -> V_66 . V_69 = 0x0001 ;
V_10 -> V_66 . V_70 = 0x0001 ;
V_10 -> V_66 . V_71 = 0x0001 ;
V_10 -> V_72 = F_13 ;
V_10 -> V_73 = F_18 ;
error = F_31 ( V_44 -> V_53 , NULL ,
V_44 -> V_22 , V_44 -> V_23 ,
V_2 -> V_27 , V_10 ) ;
if ( error ) {
F_21 ( & V_42 -> V_32 , L_10 ) ;
goto V_74;
}
F_32 ( V_75 , V_10 -> V_76 ) ;
F_33 ( V_10 , V_25 , V_26 ) ;
F_34 ( V_10 , V_2 ) ;
error = F_35 ( V_2 -> V_8 , F_7 ,
V_77 ,
L_11 , V_2 ) ;
if ( error ) {
F_21 ( & V_42 -> V_32 , L_12 ) ;
goto V_74;
}
F_19 ( & V_42 -> V_32 ) ;
error = F_36 ( V_2 -> V_11 ) ;
if ( error < 0 ) {
F_21 ( & V_42 -> V_32 , L_13 ) ;
goto V_78;
}
F_37 ( V_42 , V_2 ) ;
return 0 ;
V_78:
F_38 ( & V_42 -> V_32 ) ;
F_39 ( V_2 -> V_8 , V_2 ) ;
V_74:
F_40 ( V_10 ) ;
V_65:
F_19 ( & V_42 -> V_32 ) ;
V_61:
F_41 ( V_2 -> V_4 ) ;
V_60:
F_42 ( V_46 -> V_56 , V_47 ) ;
V_59:
F_43 ( V_2 ) ;
return error ;
}
static int T_5 F_44 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_45 ( V_42 ) ;
struct V_45 * V_46 ;
F_39 ( V_2 -> V_8 , V_2 ) ;
F_38 ( & V_42 -> V_32 ) ;
F_46 ( V_2 -> V_11 ) ;
F_41 ( V_2 -> V_4 ) ;
V_46 = F_22 ( V_42 , V_52 , 0 ) ;
F_42 ( V_46 -> V_56 , F_26 ( V_46 ) ) ;
F_43 ( V_2 ) ;
F_37 ( V_42 , NULL ) ;
return 0 ;
}
