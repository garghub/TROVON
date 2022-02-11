static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
unsigned long V_10 ;
T_1 V_11 = F_3 ( V_4 -> V_12 . type ) ;
T_1 V_13 ;
T_2 V_14 ;
switch ( V_11 ) {
case V_15 :
if ( V_5 < sizeof( struct V_16 ) ) {
F_4 ( & V_2 -> V_17 ,
L_1 ,
V_5 ) ;
break;
}
memcpy ( & V_7 -> V_18 , V_4 ,
sizeof( struct V_16 ) ) ;
F_5 ( & V_7 -> V_19 ) ;
break;
case V_20 :
if ( V_5 < sizeof( struct V_8 ) ) {
F_4 ( & V_2 -> V_17 ,
L_2 ,
V_5 ) ;
break;
}
V_9 = (struct V_8 * ) V_4 ;
V_13 = F_3 ( V_9 -> V_13 ) ;
F_6 ( & V_7 -> V_21 , V_10 ) ;
if ( V_7 -> V_22 ) {
if ( V_13 & V_23 )
F_7 ( V_7 -> V_24 ,
V_25 , 0 ) ;
V_14 = F_8 ( V_9 -> V_26 ) ;
if ( V_13 & V_27 )
V_14 |= V_28 ;
F_7 ( V_7 -> V_24 , V_14 , 0 ) ;
}
F_9 ( & V_7 -> V_21 , V_10 ) ;
break;
default:
F_4 ( & V_2 -> V_17 ,
L_3 , V_11 ) ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
T_1 V_31 ,
T_3 V_32 )
{
struct V_3 * V_4 ;
T_1 V_33 ;
switch ( V_30 -> type ) {
case V_34 :
break;
case V_35 :
V_33 = V_31 - ( V_30 -> V_36 << 3 ) ;
if ( V_33 <= sizeof( struct V_37 ) ) {
F_4 ( & V_2 -> V_17 ,
L_4 ,
V_30 -> type , V_32 , V_33 ) ;
break;
}
V_4 = ( void * ) V_30 + ( V_30 -> V_36 << 3 ) ;
F_1 ( V_2 , V_4 , V_33 ) ;
break;
default:
F_4 ( & V_2 -> V_17 ,
L_5 ,
V_30 -> type , V_32 , V_31 ) ;
break;
}
}
static void F_11 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
void * V_39 ;
int V_40 = 0x100 ;
T_1 V_31 ;
T_3 V_32 ;
int error ;
V_39 = F_12 ( V_40 , V_41 ) ;
if ( ! V_39 )
return;
while ( 1 ) {
error = F_13 ( V_2 -> V_42 , V_39 , V_40 ,
& V_31 , & V_32 ) ;
switch ( error ) {
case 0 :
if ( V_31 == 0 ) {
F_14 ( V_39 ) ;
return;
}
F_10 ( V_2 , V_39 ,
V_31 , V_32 ) ;
break;
case - V_43 :
F_14 ( V_39 ) ;
V_40 = V_31 ;
V_39 = F_12 ( V_31 , V_41 ) ;
if ( ! V_39 )
return;
break;
}
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_44 * V_45 ;
struct V_16 * V_46 ;
T_1 V_47 ;
int error ;
V_45 = & V_7 -> V_48 ;
memset ( V_45 , 0 , sizeof( struct V_44 ) ) ;
V_45 -> V_12 . type = F_16 ( V_49 ) ;
V_45 -> V_50 . V_51 = F_16 ( V_52 ) ;
error = F_17 ( V_2 -> V_42 , V_45 ,
sizeof( struct V_44 ) ,
( unsigned long ) V_45 ,
V_35 ,
V_53 ) ;
if ( error )
return error ;
if ( ! F_18 ( & V_7 -> V_19 , 10 * V_54 ) )
return - V_55 ;
V_46 = & V_7 -> V_18 ;
V_47 = F_3 ( V_46 -> V_47 ) ;
if ( ! ( V_47 & V_56 ) ) {
F_4 ( & V_2 -> V_17 ,
L_6 ,
V_52 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_19 ( struct V_58 * V_58 )
{
struct V_6 * V_7 = V_58 -> V_59 ;
unsigned long V_10 ;
F_6 ( & V_7 -> V_21 , V_10 ) ;
V_7 -> V_22 = true ;
F_9 ( & V_7 -> V_21 , V_10 ) ;
return 0 ;
}
static void F_20 ( struct V_58 * V_58 )
{
struct V_6 * V_7 = V_58 -> V_59 ;
unsigned long V_10 ;
F_6 ( & V_7 -> V_21 , V_10 ) ;
V_7 -> V_22 = false ;
F_9 ( & V_7 -> V_21 , V_10 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
struct V_6 * V_7 ;
struct V_58 * V_24 ;
int error ;
V_7 = F_22 ( sizeof( struct V_6 ) , V_62 ) ;
V_24 = F_22 ( sizeof( struct V_58 ) , V_62 ) ;
if ( ! V_7 || ! V_24 ) {
error = - V_63 ;
goto V_64;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_24 = V_24 ;
F_23 ( & V_7 -> V_21 ) ;
F_24 ( & V_7 -> V_19 ) ;
F_25 ( V_2 , V_7 ) ;
V_24 -> V_65 . V_66 = & V_2 -> V_17 ;
V_24 -> V_67 . type = V_68 ;
V_24 -> V_59 = V_7 ;
F_26 ( V_24 -> V_69 , F_27 ( & V_2 -> V_17 ) ,
sizeof( V_24 -> V_69 ) ) ;
F_26 ( V_24 -> V_70 , F_27 ( & V_2 -> V_17 ) ,
sizeof( V_24 -> V_70 ) ) ;
V_24 -> V_71 = F_19 ;
V_24 -> V_72 = F_20 ;
error = F_28 ( V_2 -> V_42 ,
V_73 ,
V_74 ,
NULL , 0 ,
F_11 ,
V_2 ) ;
if ( error )
goto V_64;
error = F_15 ( V_2 ) ;
if ( error )
goto V_75;
F_29 ( V_7 -> V_24 ) ;
return 0 ;
V_75:
F_30 ( V_2 -> V_42 ) ;
V_64:
F_14 ( V_24 ) ;
F_14 ( V_7 ) ;
return error ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_32 ( V_7 -> V_24 ) ;
F_30 ( V_2 -> V_42 ) ;
F_14 ( V_7 ) ;
F_25 ( V_2 , NULL ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
return F_34 ( & V_76 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_76 ) ;
}
