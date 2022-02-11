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
if ( V_13 & V_26 )
F_7 ( V_7 -> V_24 ,
V_27 , 0 ) ;
V_14 = F_8 ( V_9 -> V_28 ) ;
if ( V_13 & V_29 )
V_14 |= V_30 ;
F_7 ( V_7 -> V_24 , V_14 , 0 ) ;
}
F_9 ( & V_7 -> V_21 , V_10 ) ;
if ( ! ( V_13 & V_29 ) )
F_10 ( & V_2 -> V_17 , 0 ) ;
break;
default:
F_4 ( & V_2 -> V_17 ,
L_3 , V_11 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_1 V_33 ,
T_3 V_34 )
{
struct V_3 * V_4 ;
T_1 V_35 ;
switch ( V_32 -> type ) {
case V_36 :
break;
case V_37 :
V_35 = V_33 - ( V_32 -> V_38 << 3 ) ;
if ( V_35 <= sizeof( struct V_39 ) ) {
F_4 ( & V_2 -> V_17 ,
L_4 ,
V_32 -> type , V_34 , V_35 ) ;
break;
}
V_4 = ( void * ) V_32 + ( V_32 -> V_38 << 3 ) ;
F_1 ( V_2 , V_4 , V_35 ) ;
break;
default:
F_4 ( & V_2 -> V_17 ,
L_5 ,
V_32 -> type , V_34 , V_33 ) ;
break;
}
}
static void F_12 ( void * V_40 )
{
struct V_1 * V_2 = V_40 ;
void * V_41 ;
int V_42 = 0x100 ;
T_1 V_33 ;
T_3 V_34 ;
int error ;
V_41 = F_13 ( V_42 , V_43 ) ;
if ( ! V_41 )
return;
while ( 1 ) {
error = F_14 ( V_2 -> V_44 , V_41 , V_42 ,
& V_33 , & V_34 ) ;
switch ( error ) {
case 0 :
if ( V_33 == 0 ) {
F_15 ( V_41 ) ;
return;
}
F_11 ( V_2 , V_41 ,
V_33 , V_34 ) ;
break;
case - V_45 :
F_15 ( V_41 ) ;
V_42 = V_33 ;
V_41 = F_13 ( V_33 , V_43 ) ;
if ( ! V_41 )
return;
break;
}
}
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_46 * V_47 ;
struct V_16 * V_48 ;
T_1 V_49 ;
int error ;
V_47 = & V_7 -> V_50 ;
memset ( V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 -> V_12 . type = F_17 ( V_51 ) ;
V_47 -> V_52 . V_53 = F_17 ( V_54 ) ;
error = F_18 ( V_2 -> V_44 , V_47 ,
sizeof( struct V_46 ) ,
( unsigned long ) V_47 ,
V_37 ,
V_55 ) ;
if ( error )
return error ;
if ( ! F_19 ( & V_7 -> V_19 , 10 * V_56 ) )
return - V_57 ;
V_48 = & V_7 -> V_18 ;
V_49 = F_3 ( V_48 -> V_49 ) ;
if ( ! ( V_49 & V_58 ) ) {
F_4 ( & V_2 -> V_17 ,
L_6 ,
V_54 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_20 ( struct V_60 * V_60 )
{
struct V_6 * V_7 = V_60 -> V_61 ;
unsigned long V_10 ;
F_6 ( & V_7 -> V_21 , V_10 ) ;
V_7 -> V_22 = true ;
F_9 ( & V_7 -> V_21 , V_10 ) ;
return 0 ;
}
static void F_21 ( struct V_60 * V_60 )
{
struct V_6 * V_7 = V_60 -> V_61 ;
unsigned long V_10 ;
F_6 ( & V_7 -> V_21 , V_10 ) ;
V_7 -> V_22 = false ;
F_9 ( & V_7 -> V_21 , V_10 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
struct V_6 * V_7 ;
struct V_60 * V_24 ;
int error ;
V_7 = F_23 ( sizeof( struct V_6 ) , V_64 ) ;
V_24 = F_23 ( sizeof( struct V_60 ) , V_64 ) ;
if ( ! V_7 || ! V_24 ) {
error = - V_65 ;
goto V_66;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_24 = V_24 ;
F_24 ( & V_7 -> V_21 ) ;
F_25 ( & V_7 -> V_19 ) ;
F_26 ( V_2 , V_7 ) ;
V_24 -> V_67 . V_68 = & V_2 -> V_17 ;
V_24 -> V_69 . type = V_70 ;
V_24 -> V_61 = V_7 ;
F_27 ( V_24 -> V_71 , F_28 ( & V_2 -> V_17 ) ,
sizeof( V_24 -> V_71 ) ) ;
F_27 ( V_24 -> V_72 , F_28 ( & V_2 -> V_17 ) ,
sizeof( V_24 -> V_72 ) ) ;
V_24 -> V_73 = F_20 ;
V_24 -> V_74 = F_21 ;
error = F_29 ( V_2 -> V_44 ,
V_75 ,
V_76 ,
NULL , 0 ,
F_12 ,
V_2 ) ;
if ( error )
goto V_66;
error = F_16 ( V_2 ) ;
if ( error )
goto V_77;
F_30 ( V_7 -> V_24 ) ;
F_31 ( & V_2 -> V_17 , true ) ;
return 0 ;
V_77:
F_32 ( V_2 -> V_44 ) ;
V_66:
F_15 ( V_24 ) ;
F_15 ( V_7 ) ;
return error ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_31 ( & V_2 -> V_17 , false ) ;
F_34 ( V_7 -> V_24 ) ;
F_32 ( V_2 -> V_44 ) ;
F_15 ( V_7 ) ;
F_26 ( V_2 , NULL ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_78 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_78 ) ;
}
