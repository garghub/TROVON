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
F_6 ( V_8 -> V_16 , L_2 ) ;
} else {
F_7 ( V_8 -> V_16 ,
L_3 ) ;
}
} else if ( ! ( V_9 & V_12 ) ) {
if ( V_8 -> V_13 == V_14 ) {
V_8 -> V_13 = V_17 ;
F_5 ( & V_8 -> V_15 , L_1 , false ) ;
F_6 ( V_8 -> V_16 , L_4 ) ;
} else {
F_7 ( V_8 -> V_16 ,
L_5 ) ;
}
}
return V_18 ;
}
static T_1 F_8 ( int V_6 , void * V_7 )
{
unsigned int V_19 ;
struct V_8 * V_8 = V_7 ;
F_4 ( V_8 -> V_1 , V_3 ,
V_20 , & V_19 ) ;
if ( V_19 & V_21 ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_22 ,
V_23 ) ;
V_8 -> V_13 = V_24 ;
F_5 ( & V_8 -> V_15 , L_6 , true ) ;
F_6 ( V_8 -> V_16 , L_7 ) ;
} else if ( V_19 & V_25 ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_22 ,
V_26 ) ;
V_8 -> V_13 = V_17 ;
F_5 ( & V_8 -> V_15 , L_6 , false ) ;
F_6 ( V_8 -> V_16 , L_8 ) ;
} else if ( ( V_8 -> V_13 == V_24 ) &&
( ! ( V_19 & V_21 ) ) ) {
V_8 -> V_13 = V_17 ;
F_5 ( & V_8 -> V_15 , L_6 , false ) ;
F_6 ( V_8 -> V_16 , L_8 ) ;
}
return V_18 ;
}
static void F_9 ( struct V_8 * V_8 )
{
F_2 ( V_8 -> V_1 , V_3 ,
V_27 ,
V_28 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_29 , V_30 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_31 ,
V_32 |
V_33 ) ;
if ( V_8 -> V_34 )
F_3 ( V_8 -> V_35 , V_8 ) ;
if ( V_8 -> V_36 ) {
F_10 ( 30 ) ;
F_8 ( V_8 -> V_37 , V_8 ) ;
}
}
static int F_11 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_12 ( V_39 -> V_16 . V_40 ) ;
struct V_41 * V_42 = F_13 ( & V_39 -> V_16 ) ;
struct V_43 * V_44 = V_39 -> V_16 . V_45 ;
struct V_8 * V_8 ;
int V_46 ;
V_8 = F_14 ( & V_39 -> V_16 , sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 )
return - V_48 ;
if ( V_44 && ! V_42 ) {
V_8 -> V_49 = F_15 ( V_44 , L_9 ) ;
V_8 -> V_36 = F_15 ( V_44 ,
L_10 ) ;
V_8 -> V_34 = F_15 ( V_44 ,
L_11 ) ;
} else {
V_8 -> V_49 = true ;
V_8 -> V_36 = true ;
V_8 -> V_34 = true ;
if ( V_42 )
V_8 -> V_49 = V_42 -> V_49 ;
}
V_1 -> V_50 = V_8 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_16 = & V_39 -> V_16 ;
V_8 -> V_51 = F_16 ( V_1 -> V_52 ,
V_53 ) ;
V_8 -> V_37 = F_16 ( V_1 -> V_52 ,
V_54 ) ;
V_8 -> V_55 = F_16 ( V_1 -> V_52 ,
V_56 ) ;
V_8 -> V_35 = F_16 ( V_1 -> V_52 ,
V_57 ) ;
F_1 ( V_1 , V_8 -> V_49 ) ;
F_17 ( V_39 , V_8 ) ;
V_8 -> V_15 . V_58 = V_59 ;
V_8 -> V_15 . V_16 . V_40 = V_8 -> V_16 ;
V_8 -> V_15 . V_60 = V_60 ;
V_46 = F_18 ( & V_8 -> V_15 ) ;
if ( V_46 ) {
F_19 ( & V_39 -> V_16 , L_12 ) ;
return V_46 ;
}
if ( V_8 -> V_36 ) {
V_46 = F_20 ( V_8 -> V_16 ,
V_8 -> V_37 ,
NULL , F_8 ,
V_61 | V_62 |
V_63 | V_64 ,
L_13 , V_8 ) ;
if ( V_46 < 0 ) {
F_19 ( & V_39 -> V_16 , L_14 ,
V_8 -> V_37 , V_46 ) ;
goto V_65;
}
}
if ( V_8 -> V_34 ) {
V_46 = F_20 ( V_8 -> V_16 ,
V_8 -> V_35 , NULL ,
F_3 ,
V_61 | V_62 |
V_63 | V_64 ,
L_15 , V_8 ) ;
if ( V_46 < 0 ) {
F_19 ( & V_39 -> V_16 , L_14 ,
V_8 -> V_35 , V_46 ) ;
goto V_65;
}
}
F_9 ( V_8 ) ;
F_21 ( & V_39 -> V_16 , true ) ;
return 0 ;
V_65:
F_22 ( & V_8 -> V_15 ) ;
return V_46 ;
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_8 * V_8 = F_24 ( V_39 ) ;
F_22 ( & V_8 -> V_15 ) ;
return 0 ;
}
static int F_25 ( struct V_66 * V_16 )
{
struct V_8 * V_8 = F_12 ( V_16 ) ;
if ( F_26 ( V_16 ) ) {
if ( V_8 -> V_34 )
F_27 ( V_8 -> V_35 ) ;
if ( V_8 -> V_36 )
F_27 ( V_8 -> V_37 ) ;
}
return 0 ;
}
static int F_28 ( struct V_66 * V_16 )
{
struct V_8 * V_8 = F_12 ( V_16 ) ;
if ( F_26 ( V_16 ) ) {
if ( V_8 -> V_34 )
F_29 ( V_8 -> V_35 ) ;
if ( V_8 -> V_36 )
F_29 ( V_8 -> V_37 ) ;
}
return 0 ;
}
