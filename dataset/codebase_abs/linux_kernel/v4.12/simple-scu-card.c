static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 -> V_11 ) ;
return F_4 ( V_10 -> V_12 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 -> V_11 ) ;
F_6 ( V_10 -> V_12 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_11 = V_4 -> V_11 ;
V_16 = F_8 ( V_7 , V_11 ) ;
V_10 = F_3 ( V_7 , V_11 ) ;
V_14 = V_16 -> V_17 ?
V_4 -> V_18 :
V_4 -> V_19 ;
return F_9 ( V_14 , V_10 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_22 * V_23 = F_11 ( V_21 ,
V_24 ) ;
struct V_22 * V_25 = F_11 ( V_21 ,
V_26 ) ;
if ( V_7 -> V_27 )
V_23 -> V_28 =
V_23 -> V_29 = V_7 -> V_27 ;
if ( V_7 -> V_30 )
V_25 -> V_28 =
V_25 -> V_29 = V_7 -> V_30 ;
return 0 ;
}
static int F_12 ( struct V_31 * V_32 ,
struct V_6 * V_7 ,
unsigned int V_33 ,
int V_34 , bool V_35 )
{
struct V_36 * V_37 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_8 ( V_7 , V_34 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_34 ) ;
struct V_38 * V_8 = F_14 ( V_7 ) ;
int V_39 ;
if ( V_35 ) {
int V_40 = 0 ;
V_16 -> V_41 = NULL ;
V_16 -> V_42 = L_1 ;
V_16 -> V_43 = L_2 ;
V_16 -> V_17 = 1 ;
V_16 -> V_44 = 1 ;
V_39 = F_15 ( V_32 , V_16 , V_45 , V_46 ,
& V_40 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_16 ( V_37 , V_32 , V_16 , V_10 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_17 ( V_37 , V_16 ,
L_3 ,
V_16 -> V_47 ) ;
if ( V_39 < 0 )
return V_39 ;
F_18 ( V_16 , V_40 ) ;
} else {
V_16 -> V_48 = NULL ;
V_16 -> V_47 = L_1 ;
V_16 -> V_49 = L_2 ;
V_16 -> V_50 = 1 ;
V_16 -> V_51 = F_10 ;
V_39 = F_19 ( V_32 , V_16 , V_45 , V_46 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_20 ( V_37 , V_32 , V_16 , V_10 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_17 ( V_37 , V_16 ,
L_4 ,
V_16 -> V_42 ) ;
if ( V_39 < 0 )
return V_39 ;
F_21 ( V_8 ,
& V_7 -> V_52 ,
V_16 -> V_41 ,
V_53 L_5 ) ;
}
V_39 = F_22 ( V_32 ,
& V_10 -> V_54 ,
& V_10 -> V_55 ,
& V_10 -> V_56 ,
& V_10 -> V_57 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_23 ( V_16 ) ;
if ( V_39 < 0 )
return V_39 ;
V_16 -> V_58 = V_33 ;
V_16 -> V_59 = 1 ;
V_16 -> V_60 = 1 ;
V_16 -> V_61 = & V_62 ;
V_16 -> V_63 = F_7 ;
F_24 ( V_37 , L_6 ,
V_16 -> V_64 ,
V_16 -> V_58 ,
V_10 -> V_65 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_66 ,
struct V_6 * V_7 )
{
struct V_36 * V_37 = F_13 ( V_7 ) ;
struct V_31 * V_32 ;
struct V_38 * V_8 = F_14 ( V_7 ) ;
unsigned int V_33 = 0 ;
bool V_35 ;
int V_39 , V_67 ;
if ( ! V_66 )
return - V_68 ;
V_39 = F_26 ( V_8 , V_53 L_7 ) ;
if ( V_39 < 0 )
return V_39 ;
F_27 ( V_66 , V_53 L_8 , & V_7 -> V_27 ) ;
F_27 ( V_66 , V_53 L_9 , & V_7 -> V_30 ) ;
V_32 = F_28 ( V_66 , V_53 L_10 ) ;
if ( ! V_32 )
return - V_69 ;
V_39 = F_29 ( V_37 , V_66 , V_32 , V_53 , & V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
V_67 = 0 ;
F_30 (node, np) {
V_35 = false ;
if ( strcmp ( V_32 -> V_64 , V_53 L_11 ) == 0 )
V_35 = true ;
V_39 = F_12 ( V_32 , V_7 , V_33 , V_67 , V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
V_67 ++ ;
}
V_39 = F_31 ( V_8 , V_53 ) ;
if ( V_39 < 0 )
return V_39 ;
F_24 ( V_37 , L_12 ,
V_8 -> V_64 ? V_8 -> V_64 : L_13 ) ;
F_24 ( V_37 , L_14 , V_7 -> V_27 ) ;
F_24 ( V_37 , L_15 , V_7 -> V_30 ) ;
return 0 ;
}
static int F_32 ( struct V_70 * V_71 )
{
struct V_6 * V_7 ;
struct V_15 * V_16 ;
struct V_9 * V_10 ;
struct V_38 * V_8 ;
struct V_36 * V_37 = & V_71 -> V_37 ;
struct V_31 * V_32 = V_37 -> V_72 ;
int V_11 , V_39 ;
V_7 = F_33 ( V_37 , sizeof( * V_7 ) , V_73 ) ;
if ( ! V_7 )
return - V_74 ;
V_11 = F_34 ( V_32 ) ;
V_10 = F_33 ( V_37 , sizeof( * V_10 ) * V_11 , V_73 ) ;
V_16 = F_33 ( V_37 , sizeof( * V_16 ) * V_11 , V_73 ) ;
if ( ! V_10 || ! V_16 )
return - V_74 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_16 = V_16 ;
V_8 = F_14 ( V_7 ) ;
V_8 -> V_75 = V_76 ;
V_8 -> V_37 = V_37 ;
V_8 -> V_16 = V_7 -> V_16 ;
V_8 -> V_77 = V_11 ;
V_8 -> V_52 = & V_7 -> V_52 ;
V_8 -> V_78 = 1 ;
V_39 = F_25 ( V_32 , V_7 ) ;
if ( V_39 < 0 ) {
if ( V_39 != - V_79 )
F_35 ( V_37 , L_16 , V_39 ) ;
goto V_80;
}
F_36 ( V_8 , V_7 ) ;
V_39 = F_37 ( V_37 , V_8 ) ;
if ( V_39 >= 0 )
return V_39 ;
V_80:
F_38 ( V_8 ) ;
return V_39 ;
}
static int F_39 ( struct V_70 * V_71 )
{
struct V_38 * V_8 = F_40 ( V_71 ) ;
return F_38 ( V_8 ) ;
}
