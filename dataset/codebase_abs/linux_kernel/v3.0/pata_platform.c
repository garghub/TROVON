static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
F_2 (dev, link, ENABLED) {
V_5 -> V_6 = V_5 -> V_7 = V_8 ;
V_5 -> V_9 = V_10 ;
V_5 -> V_11 |= V_12 ;
F_3 ( V_5 , V_13 , L_1 ) ;
}
return 0 ;
}
static void F_4 ( struct V_14 * V_15 ,
unsigned int V_16 )
{
V_15 -> V_17 = V_15 -> V_18 + ( V_19 << V_16 ) ;
V_15 -> V_20 = V_15 -> V_18 + ( V_21 << V_16 ) ;
V_15 -> V_22 = V_15 -> V_18 + ( V_23 << V_16 ) ;
V_15 -> V_24 = V_15 -> V_18 + ( V_25 << V_16 ) ;
V_15 -> V_26 = V_15 -> V_18 + ( V_27 << V_16 ) ;
V_15 -> V_28 = V_15 -> V_18 + ( V_29 << V_16 ) ;
V_15 -> V_30 = V_15 -> V_18 + ( V_31 << V_16 ) ;
V_15 -> V_32 = V_15 -> V_18 + ( V_33 << V_16 ) ;
V_15 -> V_34 = V_15 -> V_18 + ( V_35 << V_16 ) ;
V_15 -> V_36 = V_15 -> V_18 + ( V_37 << V_16 ) ;
}
int T_1 F_5 ( struct V_38 * V_5 ,
struct V_39 * V_40 ,
struct V_39 * V_41 ,
struct V_39 * V_42 ,
unsigned int V_43 ,
int V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned int V_49 ;
int V_50 = 0 ;
int V_51 = 0 ;
V_49 = ( ( V_40 -> V_11 == V_52 ) &&
( V_41 -> V_11 == V_52 ) ) ;
if ( V_42 && V_42 -> V_53 > 0 ) {
V_50 = V_42 -> V_53 ;
V_51 = V_42 -> V_11 ;
}
V_46 = F_6 ( V_5 , 1 ) ;
if ( ! V_46 )
return - V_54 ;
V_48 = V_46 -> V_55 [ 0 ] ;
V_48 -> V_56 = & V_57 ;
V_48 -> V_58 = V_44 ;
V_48 -> V_11 |= V_59 ;
if ( ! V_50 ) {
V_48 -> V_11 |= V_60 ;
F_7 ( V_48 , L_2 ) ;
}
if ( V_49 ) {
V_48 -> V_15 . V_18 = F_8 ( V_5 , V_40 -> V_53 ,
F_9 ( V_40 ) ) ;
V_48 -> V_15 . V_61 = F_8 ( V_5 , V_41 -> V_53 ,
F_9 ( V_41 ) ) ;
} else {
V_48 -> V_15 . V_18 = F_10 ( V_5 , V_40 -> V_53 ,
F_9 ( V_40 ) ) ;
V_48 -> V_15 . V_61 = F_10 ( V_5 , V_41 -> V_53 ,
F_9 ( V_41 ) ) ;
}
if ( ! V_48 -> V_15 . V_18 || ! V_48 -> V_15 . V_61 ) {
F_11 ( V_5 , L_3 ) ;
return - V_54 ;
}
V_48 -> V_15 . V_62 = V_48 -> V_15 . V_61 ;
F_4 ( & V_48 -> V_15 , V_43 ) ;
F_7 ( V_48 , L_4 , V_49 ? L_5 : L_6 ,
( unsigned long long ) V_40 -> V_53 ,
( unsigned long long ) V_41 -> V_53 ) ;
return F_12 ( V_46 , V_50 , V_50 ? V_63 : NULL ,
V_51 , & V_64 ) ;
}
int F_13 ( struct V_38 * V_5 )
{
struct V_45 * V_46 = F_14 ( V_5 ) ;
F_15 ( V_46 ) ;
return 0 ;
}
static int T_1 F_16 ( struct V_65 * V_66 )
{
struct V_39 * V_40 ;
struct V_39 * V_41 ;
struct V_39 * V_42 ;
struct V_67 * V_68 = V_66 -> V_5 . V_69 ;
if ( ( V_66 -> V_70 != 3 ) && ( V_66 -> V_70 != 2 ) ) {
F_11 ( & V_66 -> V_5 , L_7 ) ;
return - V_71 ;
}
V_40 = F_17 ( V_66 , V_72 , 0 ) ;
if ( V_40 == NULL ) {
V_40 = F_17 ( V_66 , V_52 , 0 ) ;
if ( F_18 ( V_40 == NULL ) )
return - V_71 ;
}
V_41 = F_17 ( V_66 , V_72 , 1 ) ;
if ( V_41 == NULL ) {
V_41 = F_17 ( V_66 , V_52 , 1 ) ;
if ( F_18 ( V_41 == NULL ) )
return - V_71 ;
}
V_42 = F_17 ( V_66 , V_73 , 0 ) ;
if ( V_42 )
V_42 -> V_11 = V_68 ? V_68 -> V_51 : 0 ;
return F_5 ( & V_66 -> V_5 , V_40 , V_41 , V_42 ,
V_68 ? V_68 -> V_43 : 0 ,
V_58 ) ;
}
static int T_2 F_19 ( struct V_65 * V_66 )
{
return F_13 ( & V_66 -> V_5 ) ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_74 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_74 ) ;
}
