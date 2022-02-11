static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 -> V_11 ) ;
return F_4 ( V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 -> V_11 ) ;
F_6 ( V_10 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
int V_11 = V_4 -> V_11 ;
V_15 = F_8 ( V_7 , V_11 ) ;
V_10 = F_3 ( V_7 , V_11 ) ;
V_13 = V_15 -> V_16 ?
V_4 -> V_17 :
V_4 -> V_18 ;
return F_9 ( V_13 , V_10 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_11 ( & V_7 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_6 * V_7 ,
unsigned int V_24 ,
int V_25 , bool V_26 )
{
struct V_27 * V_28 = F_13 ( V_7 ) ;
struct V_14 * V_15 = F_8 ( V_7 , V_25 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_25 ) ;
struct V_29 * V_8 = F_14 ( V_7 ) ;
int V_30 ;
if ( V_26 ) {
int V_31 = 0 ;
V_15 -> V_32 = NULL ;
V_15 -> V_33 = L_1 ;
V_15 -> V_34 = L_2 ;
V_15 -> V_16 = 1 ;
V_15 -> V_35 = 1 ;
V_30 = F_15 ( V_23 , V_15 , V_36 , V_37 ,
& V_31 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_16 ( V_28 , V_23 , V_15 , V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_17 ( V_28 , V_15 ,
L_3 ,
V_15 -> V_38 ) ;
if ( V_30 < 0 )
return V_30 ;
F_18 ( V_15 , V_31 ) ;
} else {
V_15 -> V_39 = NULL ;
V_15 -> V_38 = L_1 ;
V_15 -> V_40 = L_2 ;
V_15 -> V_41 = 1 ;
V_15 -> V_42 = F_10 ;
V_30 = F_19 ( V_23 , V_15 , V_36 , V_37 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_20 ( V_28 , V_23 , V_15 , V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_17 ( V_28 , V_15 ,
L_4 ,
V_15 -> V_33 ) ;
if ( V_30 < 0 )
return V_30 ;
F_21 ( V_8 ,
& V_7 -> V_43 ,
V_15 -> V_32 ,
V_44 L_5 ) ;
}
V_30 = F_22 ( V_23 , V_10 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_23 ( V_15 ) ;
if ( V_30 < 0 )
return V_30 ;
V_15 -> V_45 = V_24 ;
V_15 -> V_46 = 1 ;
V_15 -> V_47 = 1 ;
V_15 -> V_48 = & V_49 ;
V_15 -> V_50 = F_7 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = F_13 ( V_7 ) ;
struct V_22 * V_23 ;
struct V_29 * V_8 = F_14 ( V_7 ) ;
struct V_22 * V_51 = V_28 -> V_52 ;
unsigned int V_24 = 0 ;
bool V_26 ;
int V_30 , V_53 ;
if ( ! V_51 )
return - V_54 ;
V_30 = F_25 ( V_8 , V_44 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
F_26 ( V_28 , V_44 , & V_7 -> V_21 ) ;
V_23 = F_27 ( V_51 , V_44 L_6 ) ;
if ( ! V_23 )
return - V_55 ;
V_30 = F_28 ( V_28 , V_51 , V_23 , V_44 , & V_24 ) ;
if ( V_30 < 0 )
return V_30 ;
V_53 = 0 ;
F_29 (node, np) {
V_26 = false ;
if ( strcmp ( V_23 -> V_56 , V_44 L_7 ) == 0 )
V_26 = true ;
V_30 = F_12 ( V_23 , V_7 , V_24 , V_53 , V_26 ) ;
if ( V_30 < 0 )
return V_30 ;
V_53 ++ ;
}
V_30 = F_30 ( V_8 , V_44 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static int F_31 ( struct V_57 * V_58 )
{
struct V_6 * V_7 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
struct V_29 * V_8 ;
struct V_27 * V_28 = & V_58 -> V_28 ;
struct V_22 * V_23 = V_28 -> V_52 ;
int V_11 , V_30 ;
V_7 = F_32 ( V_28 , sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 )
return - V_60 ;
V_11 = F_33 ( V_23 ) ;
V_10 = F_32 ( V_28 , sizeof( * V_10 ) * V_11 , V_59 ) ;
V_15 = F_32 ( V_28 , sizeof( * V_15 ) * V_11 , V_59 ) ;
if ( ! V_10 || ! V_15 )
return - V_60 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_15 = V_15 ;
V_8 = F_14 ( V_7 ) ;
V_8 -> V_61 = V_62 ;
V_8 -> V_28 = V_28 ;
V_8 -> V_15 = V_7 -> V_15 ;
V_8 -> V_63 = V_11 ;
V_8 -> V_43 = & V_7 -> V_43 ;
V_8 -> V_64 = 1 ;
V_30 = F_24 ( V_7 ) ;
if ( V_30 < 0 ) {
if ( V_30 != - V_65 )
F_34 ( V_28 , L_8 , V_30 ) ;
goto V_66;
}
F_35 ( V_8 , V_7 ) ;
V_30 = F_36 ( V_28 , V_8 ) ;
if ( V_30 < 0 )
goto V_66;
return 0 ;
V_66:
F_37 ( V_8 ) ;
return V_30 ;
}
static int F_38 ( struct V_57 * V_58 )
{
struct V_29 * V_8 = F_39 ( V_58 ) ;
return F_37 ( V_8 ) ;
}
