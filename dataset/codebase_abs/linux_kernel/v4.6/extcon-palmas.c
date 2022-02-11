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
static void F_9 ( struct V_32 * V_33 )
{
int V_34 ;
struct V_8 * V_8 = F_10 ( F_11 ( V_33 ) ,
struct V_8 ,
V_35 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
if ( ! V_8 -> V_36 )
return;
V_34 = F_12 ( V_8 -> V_36 ) ;
if ( V_34 ) {
F_5 ( V_10 , V_29 , false ) ;
F_6 ( V_8 -> V_18 , L_6 ) ;
} else {
F_5 ( V_10 , V_29 , true ) ;
F_6 ( V_8 -> V_18 , L_5 ) ;
}
}
static T_1 F_13 ( int V_6 , void * V_7 )
{
struct V_8 * V_8 = V_7 ;
F_14 ( V_37 , & V_8 -> V_35 ,
V_8 -> V_38 ) ;
return V_20 ;
}
static void F_15 ( struct V_8 * V_8 )
{
F_2 ( V_8 -> V_1 , V_3 ,
V_39 ,
V_40 ) ;
if ( V_8 -> V_41 ) {
F_2 ( V_8 -> V_1 , V_3 ,
V_42 ,
V_43 ) ;
F_2 ( V_8 -> V_1 , V_3 ,
V_44 ,
V_45 |
V_46 ) ;
}
if ( V_8 -> V_47 )
F_3 ( V_8 -> V_48 , V_8 ) ;
if ( V_8 -> V_41 ) {
F_16 ( 30 ) ;
F_8 ( V_8 -> V_49 , V_8 ) ;
}
}
static int F_17 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_18 ( V_51 -> V_18 . V_52 ) ;
struct V_53 * V_54 = F_19 ( & V_51 -> V_18 ) ;
struct V_55 * V_56 = V_51 -> V_18 . V_57 ;
struct V_8 * V_8 ;
int V_58 ;
V_8 = F_20 ( & V_51 -> V_18 , sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
if ( V_56 && ! V_54 ) {
V_8 -> V_61 = F_21 ( V_56 , L_8 ) ;
V_8 -> V_41 = F_21 ( V_56 ,
L_9 ) ;
V_8 -> V_47 = F_21 ( V_56 ,
L_10 ) ;
} else {
V_8 -> V_61 = true ;
V_8 -> V_41 = true ;
V_8 -> V_47 = true ;
if ( V_54 )
V_8 -> V_61 = V_54 -> V_61 ;
}
V_8 -> V_36 = F_22 ( & V_51 -> V_18 , L_11 ,
V_62 ) ;
if ( F_23 ( V_8 -> V_36 ) ) {
F_24 ( & V_51 -> V_18 , L_12 ) ;
return F_25 ( V_8 -> V_36 ) ;
}
V_8 -> V_63 = F_22 ( & V_51 -> V_18 , L_13 ,
V_62 ) ;
if ( F_23 ( V_8 -> V_63 ) ) {
F_24 ( & V_51 -> V_18 , L_14 ) ;
return F_25 ( V_8 -> V_63 ) ;
}
if ( V_8 -> V_41 && V_8 -> V_36 ) {
V_8 -> V_41 = false ;
V_8 -> V_64 = true ;
}
if ( V_8 -> V_47 && V_8 -> V_63 ) {
V_8 -> V_47 = false ;
V_8 -> V_65 = true ;
}
if ( V_8 -> V_64 ) {
T_2 V_66 ;
if ( F_26 ( V_56 , L_15 , & V_66 ) )
V_66 = V_67 ;
V_58 = F_27 ( V_8 -> V_36 ,
V_66 * 1000 ) ;
if ( V_58 < 0 )
V_8 -> V_38 = F_28 ( V_66 ) ;
}
F_29 ( & V_8 -> V_35 , F_9 ) ;
V_1 -> V_68 = V_8 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_18 = & V_51 -> V_18 ;
F_1 ( V_1 , V_8 -> V_61 ) ;
F_30 ( V_51 , V_8 ) ;
V_8 -> V_10 = F_31 ( & V_51 -> V_18 ,
V_69 ) ;
if ( F_23 ( V_8 -> V_10 ) ) {
F_24 ( & V_51 -> V_18 , L_16 ) ;
return - V_60 ;
}
V_58 = F_32 ( & V_51 -> V_18 , V_8 -> V_10 ) ;
if ( V_58 ) {
F_24 ( & V_51 -> V_18 , L_17 ) ;
return V_58 ;
}
if ( V_8 -> V_41 ) {
V_8 -> V_70 = F_33 ( V_1 -> V_71 ,
V_72 ) ;
V_8 -> V_49 = F_33 ( V_1 -> V_71 ,
V_73 ) ;
V_58 = F_34 ( V_8 -> V_18 ,
V_8 -> V_49 ,
NULL , F_8 ,
V_74 | V_75 |
V_76 ,
L_18 , V_8 ) ;
if ( V_58 < 0 ) {
F_24 ( & V_51 -> V_18 , L_19 ,
V_8 -> V_49 , V_58 ) ;
return V_58 ;
}
} else if ( V_8 -> V_64 ) {
V_8 -> V_77 = F_35 ( V_8 -> V_36 ) ;
if ( V_8 -> V_77 < 0 ) {
F_24 ( & V_51 -> V_18 , L_20 ) ;
return V_8 -> V_77 ;
}
V_58 = F_34 ( & V_51 -> V_18 ,
V_8 -> V_77 ,
NULL ,
F_13 ,
V_75 |
V_74 |
V_76 ,
L_18 ,
V_8 ) ;
if ( V_58 < 0 ) {
F_24 ( & V_51 -> V_18 ,
L_21 ) ;
return V_58 ;
}
}
if ( V_8 -> V_47 ) {
V_8 -> V_78 = F_33 ( V_1 -> V_71 ,
V_79 ) ;
V_8 -> V_48 = F_33 ( V_1 -> V_71 ,
V_80 ) ;
V_58 = F_34 ( V_8 -> V_18 ,
V_8 -> V_48 , NULL ,
F_3 ,
V_74 | V_75 |
V_76 ,
L_22 , V_8 ) ;
if ( V_58 < 0 ) {
F_24 ( & V_51 -> V_18 , L_19 ,
V_8 -> V_48 , V_58 ) ;
return V_58 ;
}
} else if ( V_8 -> V_65 ) {
V_58 = F_36 ( V_1 ,
V_81 ,
V_82 ,
V_83 ,
( 1 << V_84 ) ) ;
if ( V_58 < 0 ) {
F_24 ( & V_51 -> V_18 , L_23 ) ;
return V_58 ;
}
V_8 -> V_78 = F_33 ( V_1 -> V_71 ,
V_79 ) ;
V_8 -> V_85 = F_35 ( V_8 -> V_63 ) ;
if ( V_8 -> V_85 < 0 ) {
F_24 ( & V_51 -> V_18 , L_24 ) ;
return V_8 -> V_85 ;
}
V_58 = F_34 ( & V_51 -> V_18 ,
V_8 -> V_85 ,
NULL ,
F_3 ,
V_74 |
V_75 |
V_76 ,
L_22 ,
V_8 ) ;
if ( V_58 < 0 ) {
F_24 ( & V_51 -> V_18 ,
L_25 ) ;
return V_58 ;
}
}
F_15 ( V_8 ) ;
F_9 ( & V_8 -> V_35 . V_33 ) ;
F_37 ( & V_51 -> V_18 , true ) ;
return 0 ;
}
static int F_38 ( struct V_50 * V_51 )
{
struct V_8 * V_8 = F_39 ( V_51 ) ;
F_40 ( & V_8 -> V_35 ) ;
return 0 ;
}
static int F_41 ( struct V_86 * V_18 )
{
struct V_8 * V_8 = F_18 ( V_18 ) ;
if ( F_42 ( V_18 ) ) {
if ( V_8 -> V_47 )
F_43 ( V_8 -> V_48 ) ;
if ( V_8 -> V_65 )
F_43 ( V_8 -> V_85 ) ;
if ( V_8 -> V_41 )
F_43 ( V_8 -> V_49 ) ;
if ( V_8 -> V_64 )
F_43 ( V_8 -> V_77 ) ;
}
return 0 ;
}
static int F_44 ( struct V_86 * V_18 )
{
struct V_8 * V_8 = F_18 ( V_18 ) ;
if ( F_42 ( V_18 ) ) {
if ( V_8 -> V_47 )
F_45 ( V_8 -> V_48 ) ;
if ( V_8 -> V_65 )
F_45 ( V_8 -> V_85 ) ;
if ( V_8 -> V_41 )
F_45 ( V_8 -> V_49 ) ;
if ( V_8 -> V_64 )
F_45 ( V_8 -> V_77 ) ;
}
return 0 ;
}
