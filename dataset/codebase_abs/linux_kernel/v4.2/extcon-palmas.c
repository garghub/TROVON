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
struct V_9 * V_10 = V_8 -> V_10 ;
unsigned int V_11 ;
F_4 ( V_8 -> V_1 , V_12 ,
V_13 , & V_11 ) ;
if ( V_11 & V_14 ) {
if ( V_8 -> V_15 != V_16 ) {
V_8 -> V_15 = V_16 ;
F_5 ( V_10 , V_17 , true ) ;
F_6 ( V_8 -> V_18 , L_1 ) ;
} else {
F_7 ( V_8 -> V_18 ,
L_2 ) ;
}
} else if ( ! ( V_11 & V_14 ) ) {
if ( V_8 -> V_15 == V_16 ) {
V_8 -> V_15 = V_19 ;
F_5 ( V_10 , V_17 , false ) ;
F_6 ( V_8 -> V_18 , L_3 ) ;
} else {
F_7 ( V_8 -> V_18 ,
L_4 ) ;
}
}
return V_20 ;
}
static T_1 F_8 ( int V_6 , void * V_7 )
{
unsigned int V_21 , V_22 ;
struct V_8 * V_8 = V_7 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_4 ( V_8 -> V_1 , V_3 ,
V_23 , & V_21 ) ;
F_4 ( V_8 -> V_1 , V_3 ,
V_24 , & V_22 ) ;
if ( ( V_21 & V_25 ) &&
( V_22 & V_25 ) ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_26 ,
V_27 ) ;
V_8 -> V_15 = V_28 ;
F_5 ( V_10 , V_29 , true ) ;
F_6 ( V_8 -> V_18 , L_5 ) ;
} else if ( ( V_21 & V_30 ) &&
( V_22 & V_30 ) ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_26 ,
V_31 ) ;
V_8 -> V_15 = V_19 ;
F_5 ( V_10 , V_29 , false ) ;
F_6 ( V_8 -> V_18 , L_6 ) ;
} else if ( ( V_8 -> V_15 == V_28 ) &&
( ! ( V_21 & V_25 ) ) ) {
V_8 -> V_15 = V_19 ;
F_5 ( V_10 , V_29 , false ) ;
F_6 ( V_8 -> V_18 , L_6 ) ;
} else if ( ( V_8 -> V_15 == V_19 ) &&
( V_22 & V_25 ) ) {
V_8 -> V_15 = V_28 ;
F_5 ( V_10 , V_29 , true ) ;
F_6 ( V_8 -> V_18 , L_7 ) ;
}
return V_20 ;
}
static void F_9 ( struct V_8 * V_8 )
{
F_2 ( V_8 -> V_1 , V_3 ,
V_32 ,
V_33 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_34 , V_35 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_36 ,
V_37 |
V_38 ) ;
if ( V_8 -> V_39 )
F_3 ( V_8 -> V_40 , V_8 ) ;
if ( V_8 -> V_41 ) {
F_10 ( 30 ) ;
F_8 ( V_8 -> V_42 , V_8 ) ;
}
}
static int F_11 ( struct V_43 * V_44 )
{
struct V_1 * V_1 = F_12 ( V_44 -> V_18 . V_45 ) ;
struct V_46 * V_47 = F_13 ( & V_44 -> V_18 ) ;
struct V_48 * V_49 = V_44 -> V_18 . V_50 ;
struct V_8 * V_8 ;
int V_51 ;
V_8 = F_14 ( & V_44 -> V_18 , sizeof( * V_8 ) , V_52 ) ;
if ( ! V_8 )
return - V_53 ;
if ( V_49 && ! V_47 ) {
V_8 -> V_54 = F_15 ( V_49 , L_8 ) ;
V_8 -> V_41 = F_15 ( V_49 ,
L_9 ) ;
V_8 -> V_39 = F_15 ( V_49 ,
L_10 ) ;
} else {
V_8 -> V_54 = true ;
V_8 -> V_41 = true ;
V_8 -> V_39 = true ;
if ( V_47 )
V_8 -> V_54 = V_47 -> V_54 ;
}
V_1 -> V_55 = V_8 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_18 = & V_44 -> V_18 ;
V_8 -> V_56 = F_16 ( V_1 -> V_57 ,
V_58 ) ;
V_8 -> V_42 = F_16 ( V_1 -> V_57 ,
V_59 ) ;
V_8 -> V_60 = F_16 ( V_1 -> V_57 ,
V_61 ) ;
V_8 -> V_40 = F_16 ( V_1 -> V_57 ,
V_62 ) ;
F_1 ( V_1 , V_8 -> V_54 ) ;
F_17 ( V_44 , V_8 ) ;
V_8 -> V_10 = F_18 ( & V_44 -> V_18 ,
V_63 ) ;
if ( F_19 ( V_8 -> V_10 ) ) {
F_20 ( & V_44 -> V_18 , L_11 ) ;
return - V_53 ;
}
V_8 -> V_10 -> V_64 = V_64 ;
V_51 = F_21 ( & V_44 -> V_18 , V_8 -> V_10 ) ;
if ( V_51 ) {
F_20 ( & V_44 -> V_18 , L_12 ) ;
return V_51 ;
}
if ( V_8 -> V_41 ) {
V_51 = F_22 ( V_8 -> V_18 ,
V_8 -> V_42 ,
NULL , F_8 ,
V_65 | V_66 |
V_67 | V_68 ,
L_13 , V_8 ) ;
if ( V_51 < 0 ) {
F_20 ( & V_44 -> V_18 , L_14 ,
V_8 -> V_42 , V_51 ) ;
return V_51 ;
}
}
if ( V_8 -> V_39 ) {
V_51 = F_22 ( V_8 -> V_18 ,
V_8 -> V_40 , NULL ,
F_3 ,
V_65 | V_66 |
V_67 | V_68 ,
L_15 , V_8 ) ;
if ( V_51 < 0 ) {
F_20 ( & V_44 -> V_18 , L_14 ,
V_8 -> V_40 , V_51 ) ;
return V_51 ;
}
}
F_9 ( V_8 ) ;
F_23 ( & V_44 -> V_18 , true ) ;
return 0 ;
}
static int F_24 ( struct V_69 * V_18 )
{
struct V_8 * V_8 = F_12 ( V_18 ) ;
if ( F_25 ( V_18 ) ) {
if ( V_8 -> V_39 )
F_26 ( V_8 -> V_40 ) ;
if ( V_8 -> V_41 )
F_26 ( V_8 -> V_42 ) ;
}
return 0 ;
}
static int F_27 ( struct V_69 * V_18 )
{
struct V_8 * V_8 = F_12 ( V_18 ) ;
if ( F_25 ( V_18 ) ) {
if ( V_8 -> V_39 )
F_28 ( V_8 -> V_40 ) ;
if ( V_8 -> V_41 )
F_28 ( V_8 -> V_42 ) ;
}
return 0 ;
}
