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
int F_5 ( struct V_37 * V_5 , struct V_38 * V_39 ,
struct V_38 * V_40 , struct V_38 * V_41 ,
unsigned int V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
unsigned int V_50 ;
int V_51 = 0 ;
int V_52 = 0 ;
V_50 = ( ( V_39 -> V_11 == V_53 ) &&
( V_40 -> V_11 == V_53 ) ) ;
if ( V_41 && V_41 -> V_54 > 0 ) {
V_51 = V_41 -> V_54 ;
V_52 = V_41 -> V_11 & V_55 ;
}
V_47 = F_6 ( V_5 , 1 ) ;
if ( ! V_47 )
return - V_56 ;
V_49 = V_47 -> V_57 [ 0 ] ;
V_49 -> V_58 = & V_59 ;
V_49 -> V_60 = V_43 ;
V_49 -> V_11 |= V_61 ;
if ( ! V_51 ) {
V_49 -> V_11 |= V_62 ;
F_7 ( V_49 , L_2 ) ;
}
if ( V_50 ) {
V_49 -> V_14 . V_17 = F_8 ( V_5 , V_39 -> V_54 ,
F_9 ( V_39 ) ) ;
V_49 -> V_14 . V_63 = F_8 ( V_5 , V_40 -> V_54 ,
F_9 ( V_40 ) ) ;
} else {
V_49 -> V_14 . V_17 = F_10 ( V_5 , V_39 -> V_54 ,
F_9 ( V_39 ) ) ;
V_49 -> V_14 . V_63 = F_10 ( V_5 , V_40 -> V_54 ,
F_9 ( V_40 ) ) ;
}
if ( ! V_49 -> V_14 . V_17 || ! V_49 -> V_14 . V_63 ) {
F_11 ( V_5 , L_3 ) ;
return - V_56 ;
}
V_49 -> V_14 . V_64 = V_49 -> V_14 . V_63 ;
F_4 ( & V_49 -> V_14 , V_42 ) ;
F_7 ( V_49 , L_4 , V_50 ? L_5 : L_6 ,
( unsigned long long ) V_39 -> V_54 ,
( unsigned long long ) V_40 -> V_54 ) ;
return F_12 ( V_47 , V_51 , V_51 ? V_65 : NULL ,
V_52 , V_45 ) ;
}
static int F_13 ( struct V_66 * V_67 )
{
struct V_38 * V_39 ;
struct V_38 * V_40 ;
struct V_38 * V_41 ;
struct V_68 * V_69 = F_14 ( & V_67 -> V_5 ) ;
if ( ( V_67 -> V_70 != 3 ) && ( V_67 -> V_70 != 2 ) ) {
F_11 ( & V_67 -> V_5 , L_7 ) ;
return - V_71 ;
}
V_39 = F_15 ( V_67 , V_72 , 0 ) ;
if ( V_39 == NULL ) {
V_39 = F_15 ( V_67 , V_53 , 0 ) ;
if ( F_16 ( V_39 == NULL ) )
return - V_71 ;
}
V_40 = F_15 ( V_67 , V_72 , 1 ) ;
if ( V_40 == NULL ) {
V_40 = F_15 ( V_67 , V_53 , 1 ) ;
if ( F_16 ( V_40 == NULL ) )
return - V_71 ;
}
V_41 = F_15 ( V_67 , V_73 , 0 ) ;
return F_5 ( & V_67 -> V_5 , V_39 , V_40 , V_41 ,
V_69 ? V_69 -> V_42 : 0 ,
V_60 , & V_74 ) ;
}
