static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
F_2 (dev, link, ENABLED) {
V_5 -> V_6 = V_5 -> V_7 = V_8 ;
V_5 -> V_9 = V_10 ;
V_5 -> V_11 |= V_12 ;
F_3 ( V_5 , L_1 ) ;
}
return 0 ;
}
static void F_4 ( struct V_13 * V_14 ,
unsigned int V_15 )
{
V_14 -> V_16 = V_14 -> V_17 + ( V_18 << V_15 ) ;
V_14 -> V_19 = V_14 -> V_17 + ( V_20 << V_15 ) ;
V_14 -> V_21 = V_14 -> V_17 + ( V_22 << V_15 ) ;
V_14 -> V_23 = V_14 -> V_17 + ( V_24 << V_15 ) ;
V_14 -> V_25 = V_14 -> V_17 + ( V_26 << V_15 ) ;
V_14 -> V_27 = V_14 -> V_17 + ( V_28 << V_15 ) ;
V_14 -> V_29 = V_14 -> V_17 + ( V_30 << V_15 ) ;
V_14 -> V_31 = V_14 -> V_17 + ( V_32 << V_15 ) ;
V_14 -> V_33 = V_14 -> V_17 + ( V_34 << V_15 ) ;
V_14 -> V_35 = V_14 -> V_17 + ( V_36 << V_15 ) ;
}
int T_1 F_5 ( struct V_37 * V_5 ,
struct V_38 * V_39 ,
struct V_38 * V_40 ,
struct V_38 * V_41 ,
unsigned int V_42 ,
int V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned int V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
V_48 = ( ( V_39 -> V_11 == V_51 ) &&
( V_40 -> V_11 == V_51 ) ) ;
if ( V_41 && V_41 -> V_52 > 0 ) {
V_49 = V_41 -> V_52 ;
V_50 = V_41 -> V_11 ;
}
V_45 = F_6 ( V_5 , 1 ) ;
if ( ! V_45 )
return - V_53 ;
V_47 = V_45 -> V_54 [ 0 ] ;
V_47 -> V_55 = & V_56 ;
V_47 -> V_57 = V_43 ;
V_47 -> V_11 |= V_58 ;
if ( ! V_49 ) {
V_47 -> V_11 |= V_59 ;
F_7 ( V_47 , L_2 ) ;
}
if ( V_48 ) {
V_47 -> V_14 . V_17 = F_8 ( V_5 , V_39 -> V_52 ,
F_9 ( V_39 ) ) ;
V_47 -> V_14 . V_60 = F_8 ( V_5 , V_40 -> V_52 ,
F_9 ( V_40 ) ) ;
} else {
V_47 -> V_14 . V_17 = F_10 ( V_5 , V_39 -> V_52 ,
F_9 ( V_39 ) ) ;
V_47 -> V_14 . V_60 = F_10 ( V_5 , V_40 -> V_52 ,
F_9 ( V_40 ) ) ;
}
if ( ! V_47 -> V_14 . V_17 || ! V_47 -> V_14 . V_60 ) {
F_11 ( V_5 , L_3 ) ;
return - V_53 ;
}
V_47 -> V_14 . V_61 = V_47 -> V_14 . V_60 ;
F_4 ( & V_47 -> V_14 , V_42 ) ;
F_7 ( V_47 , L_4 , V_48 ? L_5 : L_6 ,
( unsigned long long ) V_39 -> V_52 ,
( unsigned long long ) V_40 -> V_52 ) ;
return F_12 ( V_45 , V_49 , V_49 ? V_62 : NULL ,
V_50 , & V_63 ) ;
}
int F_13 ( struct V_37 * V_5 )
{
struct V_44 * V_45 = F_14 ( V_5 ) ;
F_15 ( V_45 ) ;
return 0 ;
}
static int T_1 F_16 ( struct V_64 * V_65 )
{
struct V_38 * V_39 ;
struct V_38 * V_40 ;
struct V_38 * V_41 ;
struct V_66 * V_67 = V_65 -> V_5 . V_68 ;
if ( ( V_65 -> V_69 != 3 ) && ( V_65 -> V_69 != 2 ) ) {
F_11 ( & V_65 -> V_5 , L_7 ) ;
return - V_70 ;
}
V_39 = F_17 ( V_65 , V_71 , 0 ) ;
if ( V_39 == NULL ) {
V_39 = F_17 ( V_65 , V_51 , 0 ) ;
if ( F_18 ( V_39 == NULL ) )
return - V_70 ;
}
V_40 = F_17 ( V_65 , V_71 , 1 ) ;
if ( V_40 == NULL ) {
V_40 = F_17 ( V_65 , V_51 , 1 ) ;
if ( F_18 ( V_40 == NULL ) )
return - V_70 ;
}
V_41 = F_17 ( V_65 , V_72 , 0 ) ;
if ( V_41 )
V_41 -> V_11 = V_67 ? V_67 -> V_50 : 0 ;
return F_5 ( & V_65 -> V_5 , V_39 , V_40 , V_41 ,
V_67 ? V_67 -> V_42 : 0 ,
V_57 ) ;
}
static int T_2 F_19 ( struct V_64 * V_65 )
{
return F_13 ( & V_65 -> V_5 ) ;
}
