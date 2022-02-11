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
F_5 ( V_8 -> V_15 , L_1 , true ) ;
F_6 ( V_8 -> V_16 , L_2 ) ;
} else {
F_7 ( V_8 -> V_16 ,
L_3 ) ;
}
} else if ( ! ( V_9 & V_12 ) ) {
if ( V_8 -> V_13 == V_14 ) {
V_8 -> V_13 = V_17 ;
F_5 ( V_8 -> V_15 , L_1 , false ) ;
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
unsigned int V_19 , V_20 ;
struct V_8 * V_8 = V_7 ;
F_4 ( V_8 -> V_1 , V_3 ,
V_21 , & V_19 ) ;
F_4 ( V_8 -> V_1 , V_3 ,
V_22 , & V_20 ) ;
if ( ( V_19 & V_23 ) &&
( V_20 & V_23 ) ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_24 ,
V_25 ) ;
V_8 -> V_13 = V_26 ;
F_5 ( V_8 -> V_15 , L_6 , true ) ;
F_6 ( V_8 -> V_16 , L_7 ) ;
} else if ( ( V_19 & V_27 ) &&
( V_20 & V_27 ) ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_24 ,
V_28 ) ;
V_8 -> V_13 = V_17 ;
F_5 ( V_8 -> V_15 , L_6 , false ) ;
F_6 ( V_8 -> V_16 , L_8 ) ;
} else if ( ( V_8 -> V_13 == V_26 ) &&
( ! ( V_19 & V_23 ) ) ) {
V_8 -> V_13 = V_17 ;
F_5 ( V_8 -> V_15 , L_6 , false ) ;
F_6 ( V_8 -> V_16 , L_8 ) ;
} else if ( ( V_8 -> V_13 == V_17 ) &&
( V_20 & V_23 ) ) {
V_8 -> V_13 = V_26 ;
F_5 ( V_8 -> V_15 , L_6 , true ) ;
F_6 ( V_8 -> V_16 , L_9 ) ;
}
return V_18 ;
}
static void F_9 ( struct V_8 * V_8 )
{
F_2 ( V_8 -> V_1 , V_3 ,
V_29 ,
V_30 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_31 , V_32 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_33 ,
V_34 |
V_35 ) ;
if ( V_8 -> V_36 )
F_3 ( V_8 -> V_37 , V_8 ) ;
if ( V_8 -> V_38 ) {
F_10 ( 30 ) ;
F_8 ( V_8 -> V_39 , V_8 ) ;
}
}
static int F_11 ( struct V_40 * V_41 )
{
struct V_1 * V_1 = F_12 ( V_41 -> V_16 . V_42 ) ;
struct V_43 * V_44 = F_13 ( & V_41 -> V_16 ) ;
struct V_45 * V_46 = V_41 -> V_16 . V_47 ;
struct V_8 * V_8 ;
int V_48 ;
V_8 = F_14 ( & V_41 -> V_16 , sizeof( * V_8 ) , V_49 ) ;
if ( ! V_8 )
return - V_50 ;
if ( V_46 && ! V_44 ) {
V_8 -> V_51 = F_15 ( V_46 , L_10 ) ;
V_8 -> V_38 = F_15 ( V_46 ,
L_11 ) ;
V_8 -> V_36 = F_15 ( V_46 ,
L_12 ) ;
} else {
V_8 -> V_51 = true ;
V_8 -> V_38 = true ;
V_8 -> V_36 = true ;
if ( V_44 )
V_8 -> V_51 = V_44 -> V_51 ;
}
V_1 -> V_52 = V_8 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_16 = & V_41 -> V_16 ;
V_8 -> V_53 = F_16 ( V_1 -> V_54 ,
V_55 ) ;
V_8 -> V_39 = F_16 ( V_1 -> V_54 ,
V_56 ) ;
V_8 -> V_57 = F_16 ( V_1 -> V_54 ,
V_58 ) ;
V_8 -> V_37 = F_16 ( V_1 -> V_54 ,
V_59 ) ;
F_1 ( V_1 , V_8 -> V_51 ) ;
F_17 ( V_41 , V_8 ) ;
V_8 -> V_15 = F_18 ( & V_41 -> V_16 ,
V_60 ) ;
if ( F_19 ( V_8 -> V_15 ) ) {
F_20 ( & V_41 -> V_16 , L_13 ) ;
return - V_50 ;
}
V_8 -> V_15 -> V_61 = F_21 ( V_46 -> V_61 , V_49 ) ;
V_8 -> V_15 -> V_62 = V_62 ;
V_48 = F_22 ( & V_41 -> V_16 , V_8 -> V_15 ) ;
if ( V_48 ) {
F_20 ( & V_41 -> V_16 , L_14 ) ;
F_23 ( V_8 -> V_15 -> V_61 ) ;
return V_48 ;
}
if ( V_8 -> V_38 ) {
V_48 = F_24 ( V_8 -> V_16 ,
V_8 -> V_39 ,
NULL , F_8 ,
V_63 | V_64 |
V_65 | V_66 ,
L_15 , V_8 ) ;
if ( V_48 < 0 ) {
F_20 ( & V_41 -> V_16 , L_16 ,
V_8 -> V_39 , V_48 ) ;
F_23 ( V_8 -> V_15 -> V_61 ) ;
return V_48 ;
}
}
if ( V_8 -> V_36 ) {
V_48 = F_24 ( V_8 -> V_16 ,
V_8 -> V_37 , NULL ,
F_3 ,
V_63 | V_64 |
V_65 | V_66 ,
L_17 , V_8 ) ;
if ( V_48 < 0 ) {
F_20 ( & V_41 -> V_16 , L_16 ,
V_8 -> V_37 , V_48 ) ;
F_23 ( V_8 -> V_15 -> V_61 ) ;
return V_48 ;
}
}
F_9 ( V_8 ) ;
F_25 ( & V_41 -> V_16 , true ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_8 * V_8 = F_27 ( V_41 ) ;
F_23 ( V_8 -> V_15 -> V_61 ) ;
return 0 ;
}
static int F_28 ( struct V_67 * V_16 )
{
struct V_8 * V_8 = F_12 ( V_16 ) ;
if ( F_29 ( V_16 ) ) {
if ( V_8 -> V_36 )
F_30 ( V_8 -> V_37 ) ;
if ( V_8 -> V_38 )
F_30 ( V_8 -> V_39 ) ;
}
return 0 ;
}
static int F_31 ( struct V_67 * V_16 )
{
struct V_8 * V_8 = F_12 ( V_16 ) ;
if ( F_29 ( V_16 ) ) {
if ( V_8 -> V_36 )
F_32 ( V_8 -> V_37 ) ;
if ( V_8 -> V_38 )
F_32 ( V_8 -> V_39 ) ;
}
return 0 ;
}
