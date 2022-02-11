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
F_8 ( V_10 -> V_13 , V_15 , 0 ) ;
F_9 ( V_10 -> V_13 ) ;
}
static T_2 F_10 ( int V_16 , void * V_17 )
{
T_3 V_18 [ 4 ] ;
int V_19 , V_20 , V_21 ;
struct V_9 * V_10 = V_17 ;
F_11 ( & V_10 -> V_6 ) ;
F_2 ( V_10 -> V_1 , V_22 ,
V_23 , 0 ) ;
F_12 ( V_10 -> V_1 , V_24 , 4 , V_18 ) ;
V_19 = ( V_18 [ 0 ] << 4 ) | ( V_18 [ 1 ] >> 4 ) ;
V_20 = ( ( V_18 [ 1 ] & 0xf ) << 8 ) | V_18 [ 2 ] ;
V_21 = V_18 [ 3 ] ;
F_7 ( V_10 -> V_13 , V_25 , V_19 ) ;
F_7 ( V_10 -> V_13 , V_26 , V_20 ) ;
F_7 ( V_10 -> V_13 , V_14 , V_21 ) ;
F_8 ( V_10 -> V_13 , V_15 , 1 ) ;
F_9 ( V_10 -> V_13 ) ;
F_1 ( V_10 -> V_1 ) ;
F_2 ( V_10 -> V_1 , V_22 ,
V_23 , V_23 ) ;
F_13 ( & V_10 -> V_6 , V_27 / 50 ) ;
return V_28 ;
}
static int F_14 ( struct V_9 * V_10 )
{
int V_2 ;
T_3 V_29 , V_30 , V_31 , V_32 ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_33 * V_34 = V_10 -> V_34 ;
V_2 = F_15 ( V_1 , V_35 | V_36 ) ;
if ( V_2 ) {
F_16 ( V_34 , L_1 ) ;
return V_2 ;
}
V_29 = F_17 ( V_10 -> V_37 ) | F_18 ( V_10 -> V_38 ) |
F_19 ( V_10 -> V_39 ) ;
V_30 = F_17 ( 0xff ) | F_18 ( 0xff ) | F_19 ( 0xff ) ;
V_2 = F_2 ( V_1 , V_40 ,
V_30 , V_29 ) ;
if ( V_2 ) {
F_16 ( V_34 , L_2 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_41 ,
F_20 ( 0xff ) , F_20 ( V_10 -> V_42 ) ) ;
if ( V_2 ) {
F_16 ( V_34 , L_2 ) ;
return V_2 ;
}
V_31 = F_21 ( V_10 -> V_43 ) | F_22 ( V_10 -> V_44 ) |
F_23 ( V_10 -> V_45 ) ;
V_32 = F_21 ( 0xff ) | F_22 ( 0xff ) | F_23 ( 0xff ) ;
V_2 = F_2 ( V_1 , V_46 , V_32 , V_31 ) ;
if ( V_2 ) {
F_16 ( V_34 , L_3 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_47 ,
F_24 ( 0xff ) , F_24 ( V_10 -> V_48 ) ) ;
if ( V_2 ) {
F_16 ( V_34 , L_3 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_49 ,
F_25 ( 0xff ) , F_25 ( V_10 -> V_50 ) ) ;
if ( V_2 ) {
F_16 ( V_34 , L_3 ) ;
return V_2 ;
}
V_2 = F_26 ( V_1 , V_51 , 1 ) ;
if ( V_2 ) {
F_16 ( V_34 , L_4 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 , V_22 ,
F_27 ( 0xff ) , F_27 ( V_52 ) ) ;
if ( V_2 ) {
F_16 ( V_34 , L_5 ) ;
return V_2 ;
}
return 0 ;
}
static int F_28 ( struct V_53 * V_34 )
{
struct V_9 * V_10 = F_29 ( V_34 ) ;
int V_2 = 0 ;
V_2 = F_1 ( V_10 -> V_1 ) ;
if ( V_2 )
return V_2 ;
return F_2 ( V_10 -> V_1 , V_22 ,
V_23 , V_23 ) ;
}
static void F_30 ( struct V_53 * V_34 )
{
struct V_9 * V_10 = F_29 ( V_34 ) ;
F_11 ( & V_10 -> V_6 ) ;
F_2 ( V_10 -> V_1 , V_22 ,
V_23 , 0 ) ;
}
static void F_31 ( struct V_54 * V_55 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_32 ( V_55 -> V_34 . V_56 ) ;
struct V_57 * V_58 = V_55 -> V_34 . V_59 ;
struct V_60 * V_61 = NULL ;
V_10 -> V_1 = V_1 ;
if ( V_1 -> V_62 && V_1 -> V_62 -> V_10 ) {
V_61 = V_1 -> V_62 -> V_10 ;
V_10 -> V_37 = V_61 -> V_37 ;
V_10 -> V_38 = V_61 -> V_38 ;
V_10 -> V_39 = V_61 -> V_39 ;
V_10 -> V_42 = V_61 -> V_42 ;
V_10 -> V_43 = V_61 -> V_43 ;
V_10 -> V_44 = V_61 -> V_44 ;
V_10 -> V_45 = V_61 -> V_45 ;
V_10 -> V_48 = V_61 -> V_48 ;
V_10 -> V_50 = V_61 -> V_50 ;
} else if ( V_58 ) {
T_1 V_63 ;
if ( ! F_33 ( V_58 , L_6 , & V_63 ) )
V_10 -> V_37 = V_63 ;
if ( ! F_33 ( V_58 , L_7 , & V_63 ) )
V_10 -> V_38 = V_63 ;
if ( ! F_33 ( V_58 , L_8 , & V_63 ) )
V_10 -> V_39 = V_63 ;
if ( ! F_33 ( V_58 , L_9 , & V_63 ) )
V_10 -> V_42 = V_63 ;
if ( ! F_33 ( V_58 , L_10 , & V_63 ) )
V_10 -> V_43 = V_63 ;
if ( ! F_33 ( V_58 , L_11 , & V_63 ) )
V_10 -> V_44 = V_63 ;
if ( ! F_33 ( V_58 , L_12 , & V_63 ) )
V_10 -> V_45 = V_63 ;
if ( ! F_33 ( V_58 , L_13 , & V_63 ) )
V_10 -> V_48 = V_63 ;
if ( ! F_33 ( V_58 , L_14 , & V_63 ) )
V_10 -> V_50 = V_63 ;
}
}
static int F_34 ( struct V_54 * V_55 )
{
struct V_9 * V_10 ;
struct V_53 * V_13 ;
int error ;
int V_64 ;
V_64 = F_35 ( V_55 , L_15 ) ;
if ( V_64 < 0 )
return V_64 ;
V_10 = F_36 ( & V_55 -> V_34 , sizeof( * V_10 ) , V_65 ) ;
if ( ! V_10 )
return - V_66 ;
V_13 = F_37 ( & V_55 -> V_34 ) ;
if ( ! V_13 )
return - V_66 ;
F_38 ( V_55 , V_10 ) ;
V_10 -> V_13 = V_13 ;
V_10 -> V_34 = & V_55 -> V_34 ;
F_31 ( V_55 , V_10 ) ;
F_39 ( & V_10 -> V_6 , F_3 ) ;
error = F_40 ( & V_55 -> V_34 , V_64 ,
NULL , F_10 ,
V_67 , V_68 , V_10 ) ;
if ( error ) {
F_16 ( & V_55 -> V_34 , L_16 , V_64 ) ;
return error ;
}
error = F_14 ( V_10 ) ;
if ( error )
return error ;
V_13 -> V_69 = V_68 ;
V_13 -> V_70 = V_68 L_17 ;
V_13 -> V_71 . V_72 = V_73 ;
V_13 -> V_74 [ 0 ] = F_41 ( V_75 ) | F_41 ( V_76 ) ;
V_13 -> V_77 [ F_42 ( V_15 ) ] = F_41 ( V_15 ) ;
V_13 -> V_78 = F_28 ;
V_13 -> V_79 = F_30 ;
F_43 ( V_13 , V_10 ) ;
F_44 ( V_13 , V_25 , 0 , V_80 , 0 , 0 ) ;
F_44 ( V_13 , V_26 , 0 , V_80 , 0 , 0 ) ;
F_44 ( V_13 , V_14 , 0x0 , 0xff , 0 , 0 ) ;
error = F_45 ( V_13 ) ;
if ( error ) {
F_16 ( & V_55 -> V_34 , L_18 ) ;
return error ;
}
return 0 ;
}
static int F_46 ( struct V_54 * V_55 )
{
struct V_9 * V_10 = F_47 ( V_55 ) ;
F_48 ( V_10 -> V_1 , V_35 ) ;
return 0 ;
}
