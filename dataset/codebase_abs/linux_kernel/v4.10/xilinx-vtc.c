static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( & V_2 -> V_5 , V_6 + V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 ,
const struct V_7 * V_8 )
{
int V_9 ;
if ( ! V_2 -> V_10 )
return - V_11 ;
V_9 = F_4 ( V_2 -> V_5 . V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
F_1 ( V_2 , V_13 ,
V_14 |
V_15 |
V_16 | V_17 |
V_18 | V_19 ) ;
F_1 ( V_2 , V_20 , 0 ) ;
F_1 ( V_2 , V_21 ,
( V_8 -> V_22 << V_23 ) |
( V_8 -> V_24 << V_25 ) ) ;
F_1 ( V_2 , V_26 , V_8 -> V_27 ) ;
F_1 ( V_2 , V_28 , V_8 -> V_29 ) ;
F_1 ( V_2 , V_30 ,
( V_8 -> V_31 << V_32 ) |
( V_8 -> V_33 << V_34 ) ) ;
F_1 ( V_2 , V_35 , 0 ) ;
F_1 ( V_2 , V_36 ,
( V_8 -> V_37 << V_38 ) |
( V_8 -> V_39 << V_40 ) ) ;
F_1 ( V_2 , V_41 , 0 ) ;
F_2 ( & V_2 -> V_5 , V_42 ,
V_43 |
V_44 |
V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 |
V_51 | V_52 |
V_53 |
V_54 | V_55 |
V_56 |
V_57 |
V_58 | V_59 |
V_60 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_10 )
return - V_11 ;
F_2 ( & V_2 -> V_5 , V_42 , 0 ) ;
F_6 ( V_2 -> V_5 . V_12 ) ;
return 0 ;
}
struct V_1 * F_7 ( struct V_61 * V_62 )
{
struct V_61 * V_63 ;
struct V_1 * V_64 = NULL ;
struct V_1 * V_2 ;
if ( ! F_8 ( V_62 , L_1 , NULL ) )
return NULL ;
V_63 = F_9 ( V_62 , L_1 , 0 ) ;
if ( V_63 == NULL )
return F_10 ( - V_65 ) ;
F_11 ( & V_66 ) ;
F_12 (xvtc, &xvtc_list, list) {
if ( V_2 -> V_5 . V_67 -> V_68 == V_63 ) {
V_64 = V_2 ;
break;
}
}
F_13 ( & V_66 ) ;
F_14 ( V_63 ) ;
if ( ! V_64 )
return F_10 ( - V_69 ) ;
return V_64 ;
}
void F_15 ( struct V_1 * V_2 )
{
}
static void F_16 ( struct V_1 * V_2 )
{
F_11 ( & V_66 ) ;
F_17 ( & V_2 -> V_70 , & V_71 ) ;
F_13 ( & V_66 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_11 ( & V_66 ) ;
F_19 ( & V_2 -> V_70 ) ;
F_13 ( & V_66 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_61 * V_72 = V_2 -> V_5 . V_67 -> V_68 ;
V_2 -> V_73 = F_21 ( V_72 , L_2 ) ;
V_2 -> V_10 = F_21 ( V_72 , L_3 ) ;
return 0 ;
}
static int F_22 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_23 ( & V_75 -> V_67 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
V_2 -> V_5 . V_67 = & V_75 -> V_67 ;
V_9 = F_20 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_24 ( & V_2 -> V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
F_25 ( V_75 , V_2 ) ;
F_26 ( & V_2 -> V_5 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_28 ( V_75 ) ;
F_18 ( V_2 ) ;
F_29 ( & V_2 -> V_5 ) ;
return 0 ;
}
