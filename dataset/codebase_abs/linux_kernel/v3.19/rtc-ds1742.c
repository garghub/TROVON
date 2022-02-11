static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_10 ;
T_2 V_11 ;
V_11 = F_4 ( ( V_4 -> V_12 + 1900 ) / 100 ) ;
F_5 ( V_13 , V_9 + V_14 ) ;
F_5 ( F_4 ( V_4 -> V_12 % 100 ) , V_9 + V_15 ) ;
F_5 ( F_4 ( V_4 -> V_16 + 1 ) , V_9 + V_17 ) ;
F_5 ( F_4 ( V_4 -> V_18 ) & V_19 , V_9 + V_20 ) ;
F_5 ( F_4 ( V_4 -> V_21 ) , V_9 + V_22 ) ;
F_5 ( F_4 ( V_4 -> V_23 ) , V_9 + V_24 ) ;
F_5 ( F_4 ( V_4 -> V_25 ) , V_9 + V_26 ) ;
F_5 ( F_4 ( V_4 -> V_27 ) & V_28 , V_9 + V_29 ) ;
F_5 ( V_13 | ( V_11 & V_30 ) , V_9 + V_31 ) ;
F_5 ( V_11 & V_30 , V_9 + V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_10 ;
unsigned int V_32 , V_33 , V_34 , V_35 , V_36 , V_37 , V_38 ;
unsigned int V_11 ;
if ( V_8 -> V_39 == V_40 )
F_7 ( 1 ) ;
V_8 -> V_39 = V_40 ;
F_5 ( V_41 , V_9 + V_14 ) ;
V_37 = F_8 ( V_9 + V_29 ) & V_28 ;
V_36 = F_8 ( V_9 + V_26 ) ;
V_35 = F_8 ( V_9 + V_24 ) ;
V_34 = F_8 ( V_9 + V_22 ) ;
V_38 = F_8 ( V_9 + V_20 ) & V_19 ;
V_33 = F_8 ( V_9 + V_17 ) ;
V_32 = F_8 ( V_9 + V_15 ) ;
V_11 = F_8 ( V_9 + V_31 ) & V_30 ;
F_5 ( 0 , V_9 + V_14 ) ;
V_4 -> V_27 = F_9 ( V_37 ) ;
V_4 -> V_25 = F_9 ( V_36 ) ;
V_4 -> V_23 = F_9 ( V_35 ) ;
V_4 -> V_21 = F_9 ( V_34 ) ;
V_4 -> V_18 = F_9 ( V_38 ) ;
V_4 -> V_16 = F_9 ( V_33 ) - 1 ;
V_4 -> V_12 = F_9 ( V_32 ) + F_9 ( V_11 ) * 100 - 1900 ;
return F_10 ( V_4 ) ;
}
static T_3 F_11 ( struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 , T_4 V_49 , T_5 V_50 )
{
struct V_1 * V_2 = F_12 ( V_45 , struct V_1 , V_45 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_51 ;
T_3 V_52 ;
for ( V_52 = 0 ; V_50 > 0 && V_49 < V_8 -> V_53 ; V_52 ++ , V_50 -- )
* V_48 ++ = F_8 ( V_9 + V_49 ++ ) ;
return V_52 ;
}
static T_3 F_13 ( struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 , T_4 V_49 , T_5 V_50 )
{
struct V_1 * V_2 = F_12 ( V_45 , struct V_1 , V_45 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_51 ;
T_3 V_52 ;
for ( V_52 = 0 ; V_50 > 0 && V_49 < V_8 -> V_53 ; V_52 ++ , V_50 -- )
F_5 ( * V_48 ++ , V_9 + V_49 ++ ) ;
return V_52 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned int V_58 , V_59 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_60 = 0 ;
V_8 = F_15 ( & V_6 -> V_2 , sizeof( * V_8 ) , V_61 ) ;
if ( ! V_8 )
return - V_62 ;
V_57 = F_16 ( V_6 , V_63 , 0 ) ;
V_9 = F_17 ( & V_6 -> V_2 , V_57 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
V_8 -> V_51 = V_9 ;
V_8 -> V_53 = F_20 ( V_57 ) - V_64 ;
V_8 -> V_10 = V_9 + V_8 -> V_53 ;
F_21 ( & V_8 -> V_65 ) ;
V_8 -> V_65 . V_66 . V_67 = L_1 ;
V_8 -> V_65 . V_66 . V_68 = V_69 | V_70 ;
V_8 -> V_65 . V_71 = F_11 ;
V_8 -> V_65 . V_72 = F_13 ;
V_8 -> V_65 . V_50 = V_8 -> V_53 ;
V_9 = V_8 -> V_10 ;
V_59 = F_8 ( V_9 + V_29 ) ;
if ( V_59 & V_73 ) {
V_59 &= V_28 ;
V_58 = F_8 ( V_9 + V_31 ) & V_30 ;
F_5 ( V_13 , V_9 + V_14 ) ;
F_5 ( V_59 , V_9 + V_29 ) ;
F_5 ( V_58 & V_30 , V_9 + V_14 ) ;
}
if ( ! ( F_8 ( V_9 + V_20 ) & V_74 ) )
F_22 ( & V_6 -> V_2 , L_2 ) ;
V_8 -> V_39 = V_40 ;
F_23 ( V_6 , V_8 ) ;
V_55 = F_24 ( & V_6 -> V_2 , V_6 -> V_67 ,
& V_75 , V_76 ) ;
if ( F_18 ( V_55 ) )
return F_19 ( V_55 ) ;
V_60 = F_25 ( & V_6 -> V_2 . V_45 , & V_8 -> V_65 ) ;
if ( V_60 )
F_26 ( & V_6 -> V_2 , L_3 ,
V_8 -> V_65 . V_66 . V_67 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_28 ( & V_6 -> V_2 . V_45 , & V_8 -> V_65 ) ;
return 0 ;
}
