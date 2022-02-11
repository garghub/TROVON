static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
return F_2 ( V_4 , V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_8 = V_7 -> V_9 & 0x01 ;
int V_10 ;
V_10 = F_4 ( V_2 -> V_11 ,
F_5 ( & V_7 -> V_12 ) ) ;
if ( V_10 < 0 )
return;
F_6 ( V_2 -> V_11 , V_10 ) ;
F_7 ( V_2 -> V_11 , V_13 , V_8 ) ;
if ( V_8 ) {
F_8 ( V_2 -> V_11 ,
V_14 ,
F_5 ( & V_7 -> V_15 ) ) ;
F_8 ( V_2 -> V_11 ,
V_16 ,
F_5 ( & V_7 -> V_17 ) ) ;
F_8 ( V_2 -> V_11 ,
V_18 ,
F_5 ( & V_7 -> V_19 ) ) ;
F_8 ( V_2 -> V_11 ,
V_20 ,
F_5 ( & V_7 -> V_21 ) ) ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_22 )
{
T_2 V_23 ;
unsigned int V_24 ;
V_23 = F_5 ( & V_22 [ 15 ] ) ;
for ( V_24 = 0 ; V_24 < 13 ; V_24 ++ ) {
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) & V_22 [ 17 +
V_24 * sizeof( struct V_6 ) ] ;
if ( V_7 -> V_9 & 0x10 )
break;
F_3 ( V_2 , V_7 ) ;
}
F_10 ( V_2 -> V_11 ) ;
F_11 ( V_2 -> V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_11 * V_27 = V_2 -> V_28 ;
int V_8 = V_26 -> V_9 ;
int V_29 = V_8 & 0x01 ;
int V_30 = V_8 & 0x18 ;
int V_31 = ( V_29 && V_30 ) ? V_32 : V_33 ;
if ( V_2 -> V_34 != V_31 ) {
F_13 ( V_27 , V_2 -> V_34 , 0 ) ;
F_11 ( V_27 ) ;
V_2 -> V_34 = V_31 ;
}
F_13 ( V_27 , V_35 , V_8 & 0x12 ) ;
F_13 ( V_27 , V_2 -> V_34 , V_29 ) ;
if ( V_8 ) {
F_13 ( V_27 ,
V_36 ,
V_8 & 0x04 ) ;
F_8 ( V_27 ,
V_37 ,
F_5 ( & V_26 -> V_15 ) ) ;
F_8 ( V_27 ,
V_38 ,
F_5 ( & V_26 -> V_17 ) ) ;
F_8 ( V_27 ,
V_39 ,
F_5 ( & V_26 -> V_40 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_22 )
{
struct V_25 * V_26 ;
V_26 = (struct V_25 * ) & V_22 [ 15 ] ;
F_12 ( V_2 , V_26 ) ;
F_11 ( V_2 -> V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
const char V_41 [] = {
0xff , 0xff , 0xff , 0xff , 0xa5 , 0x5a , 0xe7 , 0x7e , 0x01
} ;
T_1 * V_22 = V_2 -> V_5 ;
if ( memcmp ( V_41 , V_22 , sizeof( V_41 ) ) )
F_16 ( & V_2 -> V_4 -> V_27 ,
L_1 ,
V_42 , ( int ) sizeof( V_41 ) , V_22 ) ;
switch ( V_22 [ 9 ] ) {
case V_43 :
F_9 ( V_2 , V_22 ) ;
break;
case V_44 :
F_14 ( V_2 , V_22 ) ;
break;
default:
F_16 ( & V_2 -> V_4 -> V_27 ,
L_2 ,
V_42 , V_22 [ 9 ] ) ;
break;
}
}
static T_3 F_17 ( int V_45 , void * V_46 )
{
struct V_1 * V_22 = V_46 ;
if ( F_1 ( V_22 ) )
return V_47 ;
F_18 ( & V_22 -> V_4 -> V_27 , L_3 ,
V_42 , V_48 , V_22 -> V_5 ) ;
F_15 ( V_22 ) ;
return V_47 ;
}
static void F_19 ( struct V_1 * V_22 , bool V_49 )
{
F_20 ( V_22 -> V_50 [ 0 ] , V_49 ) ;
F_20 ( V_22 -> V_50 [ 1 ] , V_49 ) ;
F_21 ( 20 ) ;
}
static int F_22 ( struct V_1 * V_22 )
{
int error ;
struct V_51 * V_27 ;
struct V_52 * V_53 ;
int V_24 ;
V_27 = & V_22 -> V_4 -> V_27 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
V_53 = F_23 ( V_27 , NULL , V_24 , V_54 ) ;
if ( F_24 ( V_53 ) ) {
error = F_25 ( V_53 ) ;
if ( error != - V_55 )
F_16 ( V_27 ,
L_4 ,
V_24 ,
error ) ;
return error ;
}
V_22 -> V_50 [ V_24 ] = V_53 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_22 )
{
struct V_11 * V_56 ;
int error ;
V_56 = F_27 ( & V_22 -> V_4 -> V_27 ) ;
if ( ! V_56 )
return - V_57 ;
V_22 -> V_11 = V_56 ;
F_28 ( V_56 , V_14 , 0 , 9600 , 0 , 0 ) ;
F_29 ( V_56 , V_14 , 40 ) ;
F_28 ( V_56 , V_16 , 0 , 7200 , 0 , 0 ) ;
F_29 ( V_56 , V_16 , 48 ) ;
F_28 ( V_56 , V_18 , 0 , 1024 , 0 , 0 ) ;
F_28 ( V_56 , V_20 , 0 , 1024 , 0 , 0 ) ;
F_30 ( V_56 , 10 , V_58 ) ;
V_56 -> V_59 = L_5 ;
V_56 -> V_60 = L_6 ;
V_56 -> V_61 . V_62 = V_63 ;
V_56 -> V_61 . V_64 = 0x045e ;
V_56 -> V_61 . V_65 = 0x0001 ;
V_56 -> V_61 . V_66 = 0x0000 ;
error = F_31 ( V_56 ) ;
if ( error ) {
F_16 ( & V_22 -> V_4 -> V_27 ,
L_7 , error ) ;
return error ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_22 )
{
struct V_11 * V_56 ;
int error ;
V_56 = F_27 ( & V_22 -> V_4 -> V_27 ) ;
if ( ! V_56 )
return - V_57 ;
V_22 -> V_28 = V_56 ;
V_22 -> V_34 = V_33 ;
F_33 ( V_67 , V_56 -> V_68 ) ;
F_33 ( V_69 , V_56 -> V_68 ) ;
F_28 ( V_56 , V_37 , 0 , 9600 , 0 , 0 ) ;
F_29 ( V_56 , V_37 , 40 ) ;
F_28 ( V_56 , V_38 , 0 , 7200 , 0 , 0 ) ;
F_29 ( V_56 , V_38 , 48 ) ;
F_28 ( V_56 , V_39 , 0 , 1024 , 0 , 0 ) ;
F_34 ( V_56 , V_70 , V_35 ) ;
F_34 ( V_56 , V_70 , V_36 ) ;
F_34 ( V_56 , V_70 , V_33 ) ;
F_34 ( V_56 , V_70 , V_32 ) ;
V_56 -> V_59 = L_8 ;
V_56 -> V_60 = L_6 ;
V_56 -> V_61 . V_62 = V_63 ;
V_56 -> V_61 . V_64 = 0x045e ;
V_56 -> V_61 . V_65 = 0x0002 ;
V_56 -> V_61 . V_66 = 0x0000 ;
error = F_31 ( V_56 ) ;
if ( error ) {
F_16 ( & V_22 -> V_4 -> V_27 ,
L_7 , error ) ;
return error ;
}
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_22 ;
int error ;
V_4 -> V_71 = 8 ;
V_4 -> V_72 = V_73 ;
error = F_36 ( V_4 ) ;
if ( error )
return error ;
V_22 = F_37 ( & V_4 -> V_27 , sizeof( * V_22 ) , V_74 ) ;
if ( ! V_22 )
return - V_57 ;
V_22 -> V_4 = V_4 ;
F_38 ( V_4 , V_22 ) ;
error = F_22 ( V_22 ) ;
if ( error )
return error ;
F_19 ( V_22 , true ) ;
F_19 ( V_22 , false ) ;
F_19 ( V_22 , true ) ;
error = F_26 ( V_22 ) ;
if ( error )
return error ;
error = F_32 ( V_22 ) ;
if ( error )
return error ;
error = F_39 ( & V_4 -> V_27 , V_4 -> V_45 ,
NULL , F_17 ,
V_75 ,
L_9 , V_22 ) ;
if ( error )
return error ;
return 0 ;
}
static int T_4 F_40 ( struct V_51 * V_27 )
{
struct V_3 * V_4 = F_41 ( V_27 ) ;
struct V_1 * V_22 = F_42 ( V_4 ) ;
F_43 ( V_22 -> V_4 -> V_45 ) ;
F_19 ( V_22 , false ) ;
return 0 ;
}
static int T_4 F_44 ( struct V_51 * V_27 )
{
struct V_3 * V_4 = F_41 ( V_27 ) ;
struct V_1 * V_22 = F_42 ( V_4 ) ;
F_19 ( V_22 , true ) ;
F_45 ( V_22 -> V_4 -> V_45 ) ;
return 0 ;
}
