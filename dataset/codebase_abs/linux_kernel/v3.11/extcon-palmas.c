static void F_1 ( struct V_1 * V_1 , int V_2 )
{
if ( V_2 )
F_2 ( V_1 , V_3 , V_4 ,
V_5 ) ;
else
F_2 ( V_1 , V_3 , V_4 , 0 ) ;
}
static T_1 F_3 ( int V_6 , void * V_7 )
{
struct V_8 * V_8 = V_7 ;
unsigned int V_9 ;
F_4 ( V_8 -> V_1 , V_10 ,
V_11 , & V_9 ) ;
if ( V_9 & V_12 ) {
if ( V_8 -> V_13 != V_14 ) {
V_8 -> V_13 = V_14 ;
F_5 ( & V_8 -> V_15 , L_1 , true ) ;
} else {
F_6 ( V_8 -> V_16 ,
L_2 ) ;
}
} else if ( ! ( V_9 & V_12 ) ) {
if ( V_8 -> V_13 == V_14 ) {
V_8 -> V_13 = V_17 ;
F_5 ( & V_8 -> V_15 , L_1 , false ) ;
} else {
F_6 ( V_8 -> V_16 ,
L_3 ) ;
}
}
return V_18 ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
{
unsigned int V_19 ;
struct V_8 * V_8 = V_7 ;
F_4 ( V_8 -> V_1 , V_3 ,
V_20 , & V_19 ) ;
if ( V_19 & V_21 ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_22 ,
V_23 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_24 ,
V_25 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_26 ,
V_25 ) ;
V_8 -> V_13 = V_27 ;
F_5 ( & V_8 -> V_15 , L_4 , true ) ;
} else if ( V_19 & V_28 ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_22 ,
V_29 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_24 ,
V_30 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_26 ,
V_30 ) ;
V_8 -> V_13 = V_17 ;
F_5 ( & V_8 -> V_15 , L_4 , false ) ;
}
return V_18 ;
}
static void F_8 ( struct V_8 * V_8 )
{
F_2 ( V_8 -> V_1 , V_3 ,
V_31 ,
V_32 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_33 , V_34 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_22 ,
V_29 ) ;
F_3 ( V_8 -> V_35 , V_8 ) ;
F_9 ( 30 ) ;
F_7 ( V_8 -> V_36 , V_8 ) ;
}
static int F_10 ( struct V_37 * V_38 )
{
struct V_1 * V_1 = F_11 ( V_38 -> V_16 . V_39 ) ;
struct V_40 * V_41 = V_38 -> V_16 . V_42 ;
struct V_43 * V_44 = V_38 -> V_16 . V_45 ;
struct V_8 * V_8 ;
int V_46 ;
if ( V_44 && ! V_41 ) {
V_41 = F_12 ( & V_38 -> V_16 , sizeof( * V_41 ) , V_47 ) ;
if ( ! V_41 )
return - V_48 ;
V_41 -> V_49 = F_13 ( V_44 , L_5 ) ;
} else if ( ! V_41 ) {
return - V_50 ;
}
V_8 = F_12 ( & V_38 -> V_16 , sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 )
return - V_48 ;
V_1 -> V_51 = V_8 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_16 = & V_38 -> V_16 ;
V_8 -> V_52 = F_14 ( V_1 -> V_53 ,
V_54 ) ;
V_8 -> V_36 = F_14 ( V_1 -> V_53 ,
V_55 ) ;
V_8 -> V_56 = F_14 ( V_1 -> V_53 ,
V_57 ) ;
V_8 -> V_35 = F_14 ( V_1 -> V_53 ,
V_58 ) ;
F_1 ( V_1 , V_41 -> V_49 ) ;
F_15 ( V_38 , V_8 ) ;
V_8 -> V_15 . V_59 = L_6 ;
V_8 -> V_15 . V_60 = V_61 ;
V_8 -> V_15 . V_62 = V_62 ;
V_46 = F_16 ( & V_8 -> V_15 , V_8 -> V_16 ) ;
if ( V_46 ) {
F_17 ( & V_38 -> V_16 , L_7 ) ;
return V_46 ;
}
V_46 = F_18 ( V_8 -> V_16 , V_8 -> V_36 ,
NULL , F_7 ,
V_63 | V_64 ,
L_8 , V_8 ) ;
if ( V_46 < 0 ) {
F_17 ( & V_38 -> V_16 , L_9 ,
V_8 -> V_36 , V_46 ) ;
goto V_65;
}
V_46 = F_18 ( V_8 -> V_16 ,
V_8 -> V_35 , NULL , F_3 ,
V_63 | V_64 ,
L_10 , V_8 ) ;
if ( V_46 < 0 ) {
F_17 ( & V_38 -> V_16 , L_9 ,
V_8 -> V_35 , V_46 ) ;
goto V_65;
}
F_8 ( V_8 ) ;
return 0 ;
V_65:
F_19 ( & V_8 -> V_15 ) ;
return V_46 ;
}
static int F_20 ( struct V_37 * V_38 )
{
struct V_8 * V_8 = F_21 ( V_38 ) ;
F_19 ( & V_8 -> V_15 ) ;
return 0 ;
}
