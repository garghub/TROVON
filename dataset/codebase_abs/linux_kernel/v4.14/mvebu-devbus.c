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
V_3 , V_4 ) ;
return V_7 ;
}
* V_5 = ( V_6 + V_1 -> V_9 - 1 ) / V_1 -> V_9 ;
F_4 ( V_1 -> V_8 , L_2 ,
V_4 , V_6 , * V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
int V_7 ;
V_7 = F_2 ( V_3 , L_3 , & V_11 -> V_14 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_4 ,
V_3 ) ;
return V_7 ;
}
if ( V_11 -> V_14 == 8 )
V_11 -> V_14 = 0 ;
else if ( V_11 -> V_14 == 16 )
V_11 -> V_14 = 1 ;
else {
F_3 ( V_1 -> V_8 , L_5 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_7 = F_1 ( V_1 , V_3 , L_6 ,
& V_11 -> V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_7 ,
& V_11 -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_8 ,
& V_11 -> V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_9 ,
& V_11 -> V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_6 ( V_1 -> V_8 -> V_20 , L_10 ) ) {
V_7 = F_1 ( V_1 , V_3 , L_11 ,
& V_11 -> V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_12 ,
& V_11 -> V_22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_3 , L_13 ,
& V_13 -> V_23 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_14 ,
V_3 ) ;
return V_7 ;
}
}
V_7 = F_1 ( V_1 , V_3 , L_15 ,
& V_13 -> V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_16 ,
& V_13 -> V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_17 ,
& V_13 -> V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
T_1 V_27 ;
V_27 = ( V_11 -> V_17 & V_28 ) << V_29 |
( V_11 -> V_18 & V_30 ) << V_31 |
( V_11 -> V_19 & V_32 ) << V_33 |
( V_13 -> V_24 & V_34 ) << V_35 |
( V_13 -> V_25 & V_36 ) << V_37 |
( V_13 -> V_26 & V_38 ) << V_39 |
V_11 -> V_14 << V_40 |
( ( V_11 -> V_17 & V_41 ) ? V_42 : 0 ) |
( ( V_11 -> V_18 & V_43 ) ? V_44 : 0 ) |
( ( V_11 -> V_19 & V_45 ) ? V_46 : 0 ) |
( ( V_13 -> V_24 & V_47 ) ? V_48 : 0 ) |
( ( V_13 -> V_25 & V_49 ) ? V_50 : 0 ) |
( ( V_13 -> V_26 & V_51 ) ? V_52 : 0 ) |
( V_11 -> V_16 << V_53 ) |
V_54 ;
F_8 ( V_27 , V_1 -> V_55 ) ;
}
static void F_9 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
T_1 V_27 ;
V_27 = V_11 -> V_14 << V_56 |
V_11 -> V_16 << V_57 |
V_11 -> V_22 << V_58 |
V_11 -> V_19 << V_59 |
V_11 -> V_21 << V_60 |
V_11 -> V_18 << V_61 |
V_11 -> V_17 ;
F_4 ( V_1 -> V_8 , L_18 ,
V_1 -> V_55 + V_62 ,
V_27 ) ;
F_8 ( V_27 , V_1 -> V_55 + V_62 ) ;
V_27 = V_13 -> V_23 << V_63 |
V_13 -> V_25 << V_64 |
V_13 -> V_26 << V_65 |
V_13 -> V_24 ;
F_4 ( V_1 -> V_8 , L_19 ,
V_1 -> V_55 + V_66 ,
V_27 ) ;
F_8 ( V_27 , V_1 -> V_55 + V_66 ) ;
}
static int F_10 ( struct V_67 * V_68 )
{
struct V_69 * V_8 = & V_68 -> V_8 ;
struct V_2 * V_3 = V_68 -> V_8 . V_20 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
struct V_1 * V_1 ;
struct V_70 * V_71 ;
struct V_72 * V_72 ;
unsigned long V_73 ;
int V_7 ;
V_1 = F_11 ( & V_68 -> V_8 , sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_1 )
return - V_75 ;
V_1 -> V_8 = V_8 ;
V_71 = F_12 ( V_68 , V_76 , 0 ) ;
V_1 -> V_55 = F_13 ( & V_68 -> V_8 , V_71 ) ;
if ( F_14 ( V_1 -> V_55 ) )
return F_15 ( V_1 -> V_55 ) ;
V_72 = F_16 ( & V_68 -> V_8 , NULL ) ;
if ( F_14 ( V_72 ) )
return F_15 ( V_72 ) ;
F_17 ( V_72 ) ;
V_73 = F_18 ( V_72 ) / 1000 ;
V_1 -> V_9 = 1000000000 / V_73 ;
F_4 ( V_1 -> V_8 , L_20 ,
V_1 -> V_9 ) ;
if ( ! F_19 ( V_3 , L_21 ) ) {
V_7 = F_5 ( V_1 , V_3 , & V_11 , & V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_6 ( V_3 , L_22 ) )
F_7 ( V_1 , V_3 , & V_11 , & V_13 ) ;
else
F_9 ( V_1 , V_3 , & V_11 , & V_13 ) ;
}
V_7 = F_20 ( V_3 , NULL , NULL , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_77 ) ;
}
