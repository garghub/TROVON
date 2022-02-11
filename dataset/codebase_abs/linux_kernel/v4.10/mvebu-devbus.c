static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_1 * V_5 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_3 , V_4 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 , L_1 ,
V_4 , V_3 -> V_9 ) ;
return V_7 ;
}
* V_5 = ( V_6 + V_1 -> V_10 - 1 ) / V_1 -> V_10 ;
F_4 ( V_1 -> V_8 , L_2 ,
V_4 , V_6 , * V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
int V_7 ;
V_7 = F_2 ( V_3 , L_3 , & V_12 -> V_15 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_4 ,
V_3 -> V_9 ) ;
return V_7 ;
}
if ( V_12 -> V_15 == 8 )
V_12 -> V_15 = 0 ;
else if ( V_12 -> V_15 == 16 )
V_12 -> V_15 = 1 ;
else {
F_3 ( V_1 -> V_8 , L_5 , V_12 -> V_15 ) ;
return - V_16 ;
}
V_7 = F_1 ( V_1 , V_3 , L_6 ,
& V_12 -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_7 ,
& V_12 -> V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_8 ,
& V_12 -> V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_9 ,
& V_12 -> V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_6 ( V_1 -> V_8 -> V_21 , L_10 ) ) {
V_7 = F_1 ( V_1 , V_3 , L_11 ,
& V_12 -> V_22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_12 ,
& V_12 -> V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_3 , L_13 ,
& V_14 -> V_24 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_14 ,
V_3 -> V_9 ) ;
return V_7 ;
}
}
V_7 = F_1 ( V_1 , V_3 , L_15 ,
& V_14 -> V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_16 ,
& V_14 -> V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_17 ,
& V_14 -> V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_1 V_28 ;
V_28 = ( V_12 -> V_18 & V_29 ) << V_30 |
( V_12 -> V_19 & V_31 ) << V_32 |
( V_12 -> V_20 & V_33 ) << V_34 |
( V_14 -> V_25 & V_35 ) << V_36 |
( V_14 -> V_26 & V_37 ) << V_38 |
( V_14 -> V_27 & V_39 ) << V_40 |
V_12 -> V_15 << V_41 |
( ( V_12 -> V_18 & V_42 ) ? V_43 : 0 ) |
( ( V_12 -> V_19 & V_44 ) ? V_45 : 0 ) |
( ( V_12 -> V_20 & V_46 ) ? V_47 : 0 ) |
( ( V_14 -> V_25 & V_48 ) ? V_49 : 0 ) |
( ( V_14 -> V_26 & V_50 ) ? V_51 : 0 ) |
( ( V_14 -> V_27 & V_52 ) ? V_53 : 0 ) |
( V_12 -> V_17 << V_54 ) |
V_55 ;
F_8 ( V_28 , V_1 -> V_56 ) ;
}
static void F_9 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_1 V_28 ;
V_28 = V_12 -> V_15 << V_57 |
V_12 -> V_17 << V_58 |
V_12 -> V_23 << V_59 |
V_12 -> V_20 << V_60 |
V_12 -> V_22 << V_61 |
V_12 -> V_19 << V_62 |
V_12 -> V_18 ;
F_4 ( V_1 -> V_8 , L_18 ,
V_1 -> V_56 + V_63 ,
V_28 ) ;
F_8 ( V_28 , V_1 -> V_56 + V_63 ) ;
V_28 = V_14 -> V_24 << V_64 |
V_14 -> V_26 << V_65 |
V_14 -> V_27 << V_66 |
V_14 -> V_25 ;
F_4 ( V_1 -> V_8 , L_19 ,
V_1 -> V_56 + V_67 ,
V_28 ) ;
F_8 ( V_28 , V_1 -> V_56 + V_67 ) ;
}
static int F_10 ( struct V_68 * V_69 )
{
struct V_70 * V_8 = & V_69 -> V_8 ;
struct V_2 * V_3 = V_69 -> V_8 . V_21 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
struct V_1 * V_1 ;
struct V_71 * V_72 ;
struct V_73 * V_73 ;
unsigned long V_74 ;
int V_7 ;
V_1 = F_11 ( & V_69 -> V_8 , sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_1 )
return - V_76 ;
V_1 -> V_8 = V_8 ;
V_72 = F_12 ( V_69 , V_77 , 0 ) ;
V_1 -> V_56 = F_13 ( & V_69 -> V_8 , V_72 ) ;
if ( F_14 ( V_1 -> V_56 ) )
return F_15 ( V_1 -> V_56 ) ;
V_73 = F_16 ( & V_69 -> V_8 , NULL ) ;
if ( F_14 ( V_73 ) )
return F_15 ( V_73 ) ;
F_17 ( V_73 ) ;
V_74 = F_18 ( V_73 ) / 1000 ;
V_1 -> V_10 = 1000000000 / V_74 ;
F_4 ( V_1 -> V_8 , L_20 ,
V_1 -> V_10 ) ;
if ( ! F_19 ( V_3 , L_21 ) ) {
V_7 = F_5 ( V_1 , V_3 , & V_12 , & V_14 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_6 ( V_3 , L_22 ) )
F_7 ( V_1 , V_3 , & V_12 , & V_14 ) ;
else
F_9 ( V_1 , V_3 , & V_12 , & V_14 ) ;
}
V_7 = F_20 ( V_3 , NULL , NULL , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_78 ) ;
}
