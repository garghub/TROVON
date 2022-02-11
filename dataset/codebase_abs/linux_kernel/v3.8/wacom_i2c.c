static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_7 , V_8 ,
V_9 , V_10 } ;
T_1 V_11 [] = { V_12 , V_13 } ;
T_1 V_14 [ V_15 ] ;
struct V_16 V_17 [] = {
{
. V_18 = V_2 -> V_18 ,
. V_19 = 0 ,
. V_20 = sizeof( V_6 ) ,
. V_21 = V_6 ,
} ,
{
. V_18 = V_2 -> V_18 ,
. V_19 = 0 ,
. V_20 = sizeof( V_11 ) ,
. V_21 = V_11 ,
} ,
{
. V_18 = V_2 -> V_18 ,
. V_19 = V_22 ,
. V_20 = sizeof( V_14 ) ,
. V_21 = V_14 ,
} ,
} ;
V_5 = F_2 ( V_2 -> V_23 , V_17 , F_3 ( V_17 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != F_3 ( V_17 ) )
return - V_24 ;
V_4 -> V_25 = F_4 ( & V_14 [ 3 ] ) ;
V_4 -> V_26 = F_4 ( & V_14 [ 5 ] ) ;
V_4 -> V_27 = F_4 ( & V_14 [ 11 ] ) ;
V_4 -> V_28 = F_4 ( & V_14 [ 13 ] ) ;
F_5 ( & V_2 -> V_29 ,
L_1 ,
V_4 -> V_25 , V_4 -> V_26 ,
V_4 -> V_27 , V_4 -> V_28 ) ;
return 0 ;
}
static T_2 F_6 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_34 * V_35 = V_33 -> V_35 ;
T_1 * V_14 = V_33 -> V_14 ;
unsigned int V_36 , V_37 , V_38 ;
unsigned char V_39 , V_40 , V_41 , V_42 ;
int error ;
error = F_7 ( V_33 -> V_2 ,
V_33 -> V_14 , sizeof( V_33 -> V_14 ) ) ;
if ( error < 0 )
goto V_43;
V_39 = V_14 [ 3 ] & 0x01 ;
V_42 = V_14 [ 3 ] & 0x04 ;
V_40 = V_14 [ 3 ] & 0x02 ;
V_41 = V_14 [ 3 ] & 0x10 ;
V_36 = F_8 ( ( V_44 * ) & V_14 [ 4 ] ) ;
V_37 = F_8 ( ( V_44 * ) & V_14 [ 6 ] ) ;
V_38 = F_8 ( ( V_44 * ) & V_14 [ 8 ] ) ;
F_9 ( V_35 , V_45 , V_39 || V_42 ) ;
F_9 ( V_35 , V_46 , V_39 ) ;
F_9 ( V_35 , V_47 , V_42 ) ;
F_9 ( V_35 , V_48 , V_40 ) ;
F_9 ( V_35 , V_49 , V_41 ) ;
F_10 ( V_35 , V_50 , V_36 ) ;
F_10 ( V_35 , V_51 , V_37 ) ;
F_10 ( V_35 , V_52 , V_38 ) ;
F_11 ( V_35 ) ;
V_43:
return V_53 ;
}
static int F_12 ( struct V_34 * V_29 )
{
struct V_32 * V_33 = F_13 ( V_29 ) ;
struct V_1 * V_2 = V_33 -> V_2 ;
F_14 ( V_2 -> V_30 ) ;
return 0 ;
}
static void F_15 ( struct V_34 * V_29 )
{
struct V_32 * V_33 = F_13 ( V_29 ) ;
struct V_1 * V_2 = V_33 -> V_2 ;
F_16 ( V_2 -> V_30 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_3 V_4 = { 0 } ;
int error ;
if ( ! F_18 ( V_2 -> V_23 , V_56 ) ) {
F_19 ( & V_2 -> V_29 , L_2 ) ;
return - V_24 ;
}
error = F_1 ( V_2 , & V_4 ) ;
if ( error )
return error ;
V_33 = F_20 ( sizeof( * V_33 ) , V_57 ) ;
V_35 = F_21 () ;
if ( ! V_33 || ! V_35 ) {
error = - V_58 ;
goto V_59;
}
V_33 -> V_2 = V_2 ;
V_33 -> V_35 = V_35 ;
V_35 -> V_60 = L_3 ;
V_35 -> V_55 . V_61 = V_62 ;
V_35 -> V_55 . V_63 = 0x56a ;
V_35 -> V_55 . V_64 = V_4 . V_28 ;
V_35 -> V_29 . V_65 = & V_2 -> V_29 ;
V_35 -> V_66 = F_12 ;
V_35 -> V_67 = F_15 ;
V_35 -> V_68 [ 0 ] |= F_22 ( V_69 ) | F_22 ( V_70 ) ;
F_23 ( V_46 , V_35 -> V_71 ) ;
F_23 ( V_47 , V_35 -> V_71 ) ;
F_23 ( V_48 , V_35 -> V_71 ) ;
F_23 ( V_49 , V_35 -> V_71 ) ;
F_23 ( V_45 , V_35 -> V_71 ) ;
F_24 ( V_35 , V_50 , 0 , V_4 . V_25 , 0 , 0 ) ;
F_24 ( V_35 , V_51 , 0 , V_4 . V_26 , 0 , 0 ) ;
F_24 ( V_35 , V_52 ,
0 , V_4 . V_27 , 0 , 0 ) ;
F_25 ( V_35 , V_33 ) ;
error = F_26 ( V_2 -> V_30 , NULL , F_6 ,
V_72 | V_73 ,
L_4 , V_33 ) ;
if ( error ) {
F_19 ( & V_2 -> V_29 ,
L_5 , error ) ;
goto V_59;
}
F_16 ( V_2 -> V_30 ) ;
error = F_27 ( V_33 -> V_35 ) ;
if ( error ) {
F_19 ( & V_2 -> V_29 ,
L_6 , error ) ;
goto V_74;
}
F_28 ( V_2 , V_33 ) ;
return 0 ;
V_74:
F_29 ( V_2 -> V_30 , V_33 ) ;
V_59:
F_30 ( V_35 ) ;
F_31 ( V_33 ) ;
return error ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_33 ( V_2 ) ;
F_29 ( V_2 -> V_30 , V_33 ) ;
F_34 ( V_33 -> V_35 ) ;
F_31 ( V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_75 * V_29 )
{
struct V_1 * V_2 = F_36 ( V_29 ) ;
F_16 ( V_2 -> V_30 ) ;
return 0 ;
}
static int F_37 ( struct V_75 * V_29 )
{
struct V_1 * V_2 = F_36 ( V_29 ) ;
F_14 ( V_2 -> V_30 ) ;
return 0 ;
}
