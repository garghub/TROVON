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
F_6 ( V_8 -> V_18 ,
L_2 ) ;
}
} else if ( ! ( V_11 & V_14 ) ) {
if ( V_8 -> V_15 == V_16 ) {
V_8 -> V_15 = V_19 ;
F_5 ( V_10 , V_17 , false ) ;
F_6 ( V_8 -> V_18 , L_3 ) ;
} else {
F_6 ( V_8 -> V_18 ,
L_4 ) ;
}
}
return V_20 ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
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
static void F_8 ( struct V_32 * V_33 )
{
int V_34 ;
struct V_8 * V_8 = F_9 ( F_10 ( V_33 ) ,
struct V_8 ,
V_35 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
if ( ! V_8 -> V_36 )
return;
V_34 = F_11 ( V_8 -> V_36 ) ;
if ( V_34 ) {
F_5 ( V_10 , V_29 , false ) ;
F_6 ( V_8 -> V_18 , L_6 ) ;
} else {
F_5 ( V_10 , V_29 , true ) ;
F_6 ( V_8 -> V_18 , L_5 ) ;
}
}
static T_1 F_12 ( int V_6 , void * V_7 )
{
struct V_8 * V_8 = V_7 ;
F_13 ( V_37 , & V_8 -> V_35 ,
V_8 -> V_38 ) ;
return V_20 ;
}
static void F_14 ( struct V_8 * V_8 )
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
F_15 ( 30 ) ;
F_7 ( V_8 -> V_49 , V_8 ) ;
}
}
static int F_16 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_17 ( V_51 -> V_18 . V_52 ) ;
struct V_53 * V_54 = F_18 ( & V_51 -> V_18 ) ;
struct V_55 * V_56 = V_51 -> V_18 . V_57 ;
struct V_8 * V_8 ;
int V_58 ;
if ( ! V_1 ) {
F_19 ( & V_51 -> V_18 , L_8 ) ;
return - V_59 ;
}
V_8 = F_20 ( & V_51 -> V_18 , sizeof( * V_8 ) , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
if ( V_56 && ! V_54 ) {
V_8 -> V_62 = F_21 ( V_56 , L_9 ) ;
V_8 -> V_41 = F_21 ( V_56 ,
L_10 ) ;
V_8 -> V_47 = F_21 ( V_56 ,
L_11 ) ;
} else {
V_8 -> V_62 = true ;
V_8 -> V_41 = true ;
V_8 -> V_47 = true ;
if ( V_54 )
V_8 -> V_62 = V_54 -> V_62 ;
}
V_8 -> V_36 = F_22 ( & V_51 -> V_18 , L_12 ,
V_63 ) ;
if ( F_23 ( V_8 -> V_36 ) ) {
F_19 ( & V_51 -> V_18 , L_13 ) ;
return F_24 ( V_8 -> V_36 ) ;
}
V_8 -> V_64 = F_22 ( & V_51 -> V_18 , L_14 ,
V_63 ) ;
if ( F_23 ( V_8 -> V_64 ) ) {
F_19 ( & V_51 -> V_18 , L_15 ) ;
return F_24 ( V_8 -> V_64 ) ;
}
if ( V_8 -> V_41 && V_8 -> V_36 ) {
V_8 -> V_41 = false ;
V_8 -> V_65 = true ;
}
if ( V_8 -> V_47 && V_8 -> V_64 ) {
V_8 -> V_47 = false ;
V_8 -> V_66 = true ;
}
if ( V_8 -> V_65 ) {
T_2 V_67 ;
if ( F_25 ( V_56 , L_16 , & V_67 ) )
V_67 = V_68 ;
V_58 = F_26 ( V_8 -> V_36 ,
V_67 * 1000 ) ;
if ( V_58 < 0 )
V_8 -> V_38 = F_27 ( V_67 ) ;
}
F_28 ( & V_8 -> V_35 , F_8 ) ;
V_1 -> V_69 = V_8 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_18 = & V_51 -> V_18 ;
F_1 ( V_1 , V_8 -> V_62 ) ;
F_29 ( V_51 , V_8 ) ;
V_8 -> V_10 = F_30 ( & V_51 -> V_18 ,
V_70 ) ;
if ( F_23 ( V_8 -> V_10 ) ) {
F_19 ( & V_51 -> V_18 , L_17 ) ;
return - V_61 ;
}
V_58 = F_31 ( & V_51 -> V_18 , V_8 -> V_10 ) ;
if ( V_58 ) {
F_19 ( & V_51 -> V_18 , L_18 ) ;
return V_58 ;
}
if ( V_8 -> V_41 ) {
V_8 -> V_71 = F_32 ( V_1 -> V_72 ,
V_73 ) ;
V_8 -> V_49 = F_32 ( V_1 -> V_72 ,
V_74 ) ;
V_58 = F_33 ( V_8 -> V_18 ,
V_8 -> V_49 ,
NULL , F_7 ,
V_75 | V_76 |
V_77 ,
L_19 , V_8 ) ;
if ( V_58 < 0 ) {
F_19 ( & V_51 -> V_18 , L_20 ,
V_8 -> V_49 , V_58 ) ;
return V_58 ;
}
} else if ( V_8 -> V_65 ) {
V_8 -> V_78 = F_34 ( V_8 -> V_36 ) ;
if ( V_8 -> V_78 < 0 ) {
F_19 ( & V_51 -> V_18 , L_21 ) ;
return V_8 -> V_78 ;
}
V_58 = F_33 ( & V_51 -> V_18 ,
V_8 -> V_78 ,
NULL ,
F_12 ,
V_76 |
V_75 |
V_77 ,
L_19 ,
V_8 ) ;
if ( V_58 < 0 ) {
F_19 ( & V_51 -> V_18 ,
L_22 ) ;
return V_58 ;
}
}
if ( V_8 -> V_47 ) {
V_8 -> V_79 = F_32 ( V_1 -> V_72 ,
V_80 ) ;
V_8 -> V_48 = F_32 ( V_1 -> V_72 ,
V_81 ) ;
V_58 = F_33 ( V_8 -> V_18 ,
V_8 -> V_48 , NULL ,
F_3 ,
V_75 | V_76 |
V_77 ,
L_23 , V_8 ) ;
if ( V_58 < 0 ) {
F_19 ( & V_51 -> V_18 , L_20 ,
V_8 -> V_48 , V_58 ) ;
return V_58 ;
}
} else if ( V_8 -> V_66 ) {
V_58 = F_35 ( V_1 ,
V_82 ,
V_83 ,
V_84 ,
( 1 << V_85 ) ) ;
if ( V_58 < 0 ) {
F_19 ( & V_51 -> V_18 , L_24 ) ;
return V_58 ;
}
V_8 -> V_79 = F_32 ( V_1 -> V_72 ,
V_80 ) ;
V_8 -> V_86 = F_34 ( V_8 -> V_64 ) ;
if ( V_8 -> V_86 < 0 ) {
F_19 ( & V_51 -> V_18 , L_25 ) ;
return V_8 -> V_86 ;
}
V_58 = F_33 ( & V_51 -> V_18 ,
V_8 -> V_86 ,
NULL ,
F_3 ,
V_75 |
V_76 |
V_77 ,
L_23 ,
V_8 ) ;
if ( V_58 < 0 ) {
F_19 ( & V_51 -> V_18 ,
L_26 ) ;
return V_58 ;
}
}
F_14 ( V_8 ) ;
if ( V_8 -> V_66 )
F_3 ( V_8 -> V_86 , V_8 ) ;
F_8 ( & V_8 -> V_35 . V_33 ) ;
F_36 ( & V_51 -> V_18 , true ) ;
return 0 ;
}
static int F_37 ( struct V_50 * V_51 )
{
struct V_8 * V_8 = F_38 ( V_51 ) ;
F_39 ( & V_8 -> V_35 ) ;
return 0 ;
}
static int F_40 ( struct V_87 * V_18 )
{
struct V_8 * V_8 = F_17 ( V_18 ) ;
if ( F_41 ( V_18 ) ) {
if ( V_8 -> V_47 )
F_42 ( V_8 -> V_48 ) ;
if ( V_8 -> V_66 )
F_42 ( V_8 -> V_86 ) ;
if ( V_8 -> V_41 )
F_42 ( V_8 -> V_49 ) ;
if ( V_8 -> V_65 )
F_42 ( V_8 -> V_78 ) ;
}
return 0 ;
}
static int F_43 ( struct V_87 * V_18 )
{
struct V_8 * V_8 = F_17 ( V_18 ) ;
if ( F_41 ( V_18 ) ) {
if ( V_8 -> V_47 )
F_44 ( V_8 -> V_48 ) ;
if ( V_8 -> V_66 )
F_44 ( V_8 -> V_86 ) ;
if ( V_8 -> V_41 )
F_44 ( V_8 -> V_49 ) ;
if ( V_8 -> V_65 )
F_44 ( V_8 -> V_78 ) ;
}
if ( V_8 -> V_66 )
F_3 ( V_8 -> V_86 , V_8 ) ;
F_8 ( & V_8 -> V_35 . V_33 ) ;
return 0 ;
}
