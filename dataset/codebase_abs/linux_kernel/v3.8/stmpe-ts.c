static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_2 ( V_1 , V_3 ,
V_4 , V_4 ) ;
if ( V_2 )
return V_2 ;
return F_2 ( V_1 , V_3 ,
V_4 , 0 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
int V_7 ;
T_1 V_8 = 40 ;
struct V_9 * V_10 =
F_4 ( V_6 , struct V_9 , V_6 . V_6 ) ;
V_7 = F_5 ( V_10 -> V_1 , V_11 ) ;
while ( ( V_7 & ( 1 << V_12 ) ) && ( V_8 > 0 ) ) {
V_8 -- ;
V_7 = F_5 ( V_10 -> V_1 , V_11 ) ;
F_6 ( 100 ) ;
}
F_1 ( V_10 -> V_1 ) ;
F_7 ( V_10 -> V_13 , V_14 , 0 ) ;
F_8 ( V_10 -> V_13 ) ;
}
static T_2 F_9 ( int V_15 , void * V_16 )
{
T_3 V_17 [ 4 ] ;
int V_18 , V_19 , V_20 ;
struct V_9 * V_10 = V_16 ;
F_10 ( & V_10 -> V_6 ) ;
F_2 ( V_10 -> V_1 , V_21 ,
V_22 , 0 ) ;
F_11 ( V_10 -> V_1 , V_23 , 4 , V_17 ) ;
V_18 = ( V_17 [ 0 ] << 4 ) | ( V_17 [ 1 ] >> 4 ) ;
V_19 = ( ( V_17 [ 1 ] & 0xf ) << 8 ) | V_17 [ 2 ] ;
V_20 = V_17 [ 3 ] ;
F_7 ( V_10 -> V_13 , V_24 , V_18 ) ;
F_7 ( V_10 -> V_13 , V_25 , V_19 ) ;
F_7 ( V_10 -> V_13 , V_14 , V_20 ) ;
F_8 ( V_10 -> V_13 ) ;
F_1 ( V_10 -> V_1 ) ;
F_2 ( V_10 -> V_1 , V_21 ,
V_22 , V_22 ) ;
F_12 ( & V_10 -> V_6 , V_26 / 50 ) ;
return V_27 ;
}
static int F_13 ( struct V_9 * V_10 )
{
int V_2 ;
T_3 V_28 , V_29 , V_30 , V_31 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_32 * V_33 = V_10 -> V_33 ;
V_2 = F_14 ( V_1 , V_34 | V_35 ) ;
if ( V_2 ) {
F_15 ( V_33 , L_1 ) ;
return V_2 ;
}
V_28 = F_16 ( V_10 -> V_36 ) | F_17 ( V_10 -> V_37 ) |
F_18 ( V_10 -> V_38 ) ;
V_29 = F_16 ( 0xff ) | F_17 ( 0xff ) | F_18 ( 0xff ) ;
V_2 = F_2 ( V_1 , V_39 ,
V_29 , V_28 ) ;
if ( V_2 ) {
F_15 ( V_33 , L_2 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_40 ,
F_19 ( 0xff ) , F_19 ( V_10 -> V_41 ) ) ;
if ( V_2 ) {
F_15 ( V_33 , L_2 ) ;
return V_2 ;
}
V_30 = F_20 ( V_10 -> V_42 ) | F_21 ( V_10 -> V_43 ) |
F_22 ( V_10 -> V_44 ) ;
V_31 = F_20 ( 0xff ) | F_21 ( 0xff ) | F_22 ( 0xff ) ;
V_2 = F_2 ( V_1 , V_45 , V_31 , V_30 ) ;
if ( V_2 ) {
F_15 ( V_33 , L_3 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_46 ,
F_23 ( 0xff ) , F_23 ( V_10 -> V_47 ) ) ;
if ( V_2 ) {
F_15 ( V_33 , L_3 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_48 ,
F_24 ( 0xff ) , F_24 ( V_10 -> V_49 ) ) ;
if ( V_2 ) {
F_15 ( V_33 , L_3 ) ;
return V_2 ;
}
V_2 = F_25 ( V_1 , V_50 , 1 ) ;
if ( V_2 ) {
F_15 ( V_33 , L_4 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_21 ,
F_26 ( 0xff ) , F_26 ( V_51 ) ) ;
if ( V_2 ) {
F_15 ( V_33 , L_5 ) ;
return V_2 ;
}
return 0 ;
}
static int F_27 ( struct V_52 * V_33 )
{
struct V_9 * V_10 = F_28 ( V_33 ) ;
int V_2 = 0 ;
V_2 = F_1 ( V_10 -> V_1 ) ;
if ( V_2 )
return V_2 ;
return F_2 ( V_10 -> V_1 , V_21 ,
V_22 , V_22 ) ;
}
static void F_29 ( struct V_52 * V_33 )
{
struct V_9 * V_10 = F_28 ( V_33 ) ;
F_10 ( & V_10 -> V_6 ) ;
F_2 ( V_10 -> V_1 , V_21 ,
V_22 , 0 ) ;
}
static void F_30 ( struct V_53 * V_54 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_31 ( V_54 -> V_33 . V_55 ) ;
struct V_56 * V_57 = V_54 -> V_33 . V_58 ;
struct V_59 * V_60 = NULL ;
V_10 -> V_1 = V_1 ;
if ( V_1 -> V_61 && V_1 -> V_61 -> V_10 ) {
V_60 = V_1 -> V_61 -> V_10 ;
V_10 -> V_36 = V_60 -> V_36 ;
V_10 -> V_37 = V_60 -> V_37 ;
V_10 -> V_38 = V_60 -> V_38 ;
V_10 -> V_41 = V_60 -> V_41 ;
V_10 -> V_42 = V_60 -> V_42 ;
V_10 -> V_43 = V_60 -> V_43 ;
V_10 -> V_44 = V_60 -> V_44 ;
V_10 -> V_47 = V_60 -> V_47 ;
V_10 -> V_49 = V_60 -> V_49 ;
} else if ( V_57 ) {
T_1 V_62 ;
if ( ! F_32 ( V_57 , L_6 , & V_62 ) )
V_10 -> V_36 = V_62 ;
if ( ! F_32 ( V_57 , L_7 , & V_62 ) )
V_10 -> V_37 = V_62 ;
if ( ! F_32 ( V_57 , L_8 , & V_62 ) )
V_10 -> V_38 = V_62 ;
if ( ! F_32 ( V_57 , L_9 , & V_62 ) )
V_10 -> V_41 = V_62 ;
if ( ! F_32 ( V_57 , L_10 , & V_62 ) )
V_10 -> V_42 = V_62 ;
if ( ! F_32 ( V_57 , L_11 , & V_62 ) )
V_10 -> V_43 = V_62 ;
if ( ! F_32 ( V_57 , L_12 , & V_62 ) )
V_10 -> V_44 = V_62 ;
if ( ! F_32 ( V_57 , L_13 , & V_62 ) )
V_10 -> V_47 = V_62 ;
if ( ! F_32 ( V_57 , L_14 , & V_62 ) )
V_10 -> V_49 = V_62 ;
}
}
static int F_33 ( struct V_53 * V_54 )
{
struct V_9 * V_10 ;
struct V_52 * V_13 ;
int error ;
int V_63 ;
V_63 = F_34 ( V_54 , L_15 ) ;
if ( V_63 < 0 )
return V_63 ;
V_10 = F_35 ( & V_54 -> V_33 , sizeof( * V_10 ) , V_64 ) ;
if ( ! V_10 )
return - V_65 ;
V_13 = F_36 ( & V_54 -> V_33 ) ;
if ( ! V_13 )
return - V_65 ;
F_37 ( V_54 , V_10 ) ;
V_10 -> V_13 = V_13 ;
V_10 -> V_33 = & V_54 -> V_33 ;
F_30 ( V_54 , V_10 ) ;
F_38 ( & V_10 -> V_6 , F_3 ) ;
error = F_39 ( & V_54 -> V_33 , V_63 ,
NULL , F_9 ,
V_66 , V_67 , V_10 ) ;
if ( error ) {
F_15 ( & V_54 -> V_33 , L_16 , V_63 ) ;
return error ;
}
error = F_13 ( V_10 ) ;
if ( error )
return error ;
V_13 -> V_68 = V_67 ;
V_13 -> V_69 = V_67 L_17 ;
V_13 -> V_70 . V_71 = V_72 ;
V_13 -> V_73 [ 0 ] = F_40 ( V_74 ) | F_40 ( V_75 ) ;
V_13 -> V_76 [ F_41 ( V_77 ) ] = F_40 ( V_77 ) ;
V_13 -> V_78 = F_27 ;
V_13 -> V_79 = F_29 ;
F_42 ( V_13 , V_10 ) ;
F_43 ( V_13 , V_24 , 0 , V_80 , 0 , 0 ) ;
F_43 ( V_13 , V_25 , 0 , V_80 , 0 , 0 ) ;
F_43 ( V_13 , V_14 , 0x0 , 0xff , 0 , 0 ) ;
error = F_44 ( V_13 ) ;
if ( error ) {
F_15 ( & V_54 -> V_33 , L_18 ) ;
return error ;
}
return 0 ;
}
static int F_45 ( struct V_53 * V_54 )
{
struct V_9 * V_10 = F_46 ( V_54 ) ;
F_47 ( V_10 -> V_1 , V_34 ) ;
return 0 ;
}
