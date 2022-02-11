static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
return true ;
default:
return false ;
}
}
T_1 F_2 ( struct V_55 * V_55 , T_2 V_3 )
{
int V_56 , V_57 ;
V_57 = F_3 ( V_55 -> V_58 , V_3 , & V_56 ) ;
if ( V_57 )
F_4 ( V_55 -> V_2 , L_1 ,
V_3 , V_57 ) ;
return ( T_1 ) V_56 ;
}
void F_5 ( struct V_55 * V_55 , T_2 V_3 , T_1 V_56 )
{
int V_57 ;
V_57 = F_6 ( V_55 -> V_58 , V_3 , V_56 ) ;
if ( V_57 )
F_4 ( V_55 -> V_2 , L_2 ,
V_3 , V_57 ) ;
}
void F_7 ( struct V_55 * V_55 , T_2 V_3 , T_1 V_59 , T_1 V_56 )
{
int V_57 ;
V_57 = F_8 ( V_55 -> V_58 , V_3 , V_59 , V_56 ) ;
if ( V_57 )
F_4 ( V_55 -> V_2 , L_3 ,
V_3 , V_57 ) ;
}
void F_9 ( struct V_55 * V_55 , T_2 V_3 , int V_60 , T_1 * V_61 )
{
int V_57 ;
V_57 = F_10 ( V_55 -> V_58 , V_3 , V_61 , V_60 ) ;
if ( V_57 )
F_4 ( V_55 -> V_2 , L_4 ,
V_3 , V_57 ) ;
}
void F_11 ( struct V_55 * V_55 , T_2 V_3 , int V_60 , const T_1 * V_61 )
{
int V_57 ;
V_57 = F_12 ( V_55 -> V_58 , V_3 , V_61 , V_60 ) ;
if ( V_57 )
F_4 ( V_55 -> V_2 , L_5 ,
V_3 , V_57 ) ;
}
static int F_13 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_55 * V_55 ;
struct V_66 * V_67 = F_14 ( & V_63 -> V_2 ) ;
int V_57 ;
V_55 = F_15 ( & V_63 -> V_2 , sizeof( * V_55 ) , V_68 ) ;
if ( ! V_55 )
return - V_69 ;
V_55 -> V_2 = & V_63 -> V_2 ;
V_55 -> V_70 = V_63 -> V_70 ;
F_16 ( V_63 , V_55 ) ;
V_55 -> V_58 = F_17 ( V_63 , & V_71 ) ;
if ( F_18 ( V_55 -> V_58 ) ) {
V_57 = F_19 ( V_55 -> V_58 ) ;
F_4 ( V_55 -> V_2 , L_6 ,
V_57 ) ;
return V_57 ;
}
V_55 -> V_72 = V_67 ? V_67 -> V_72 : - 1 ;
V_57 = F_20 ( V_55 -> V_58 , V_55 -> V_70 ,
V_73 | V_74 ,
V_55 -> V_72 , & V_75 ,
& V_55 -> V_76 ) ;
if ( V_57 )
return V_57 ;
V_55 -> V_72 = F_21 ( V_55 -> V_76 ) ;
F_22 ( V_55 -> V_70 ) ;
V_57 = F_23 ( V_55 -> V_2 , - 1 , V_77 ,
F_24 ( V_77 ) , NULL ,
V_55 -> V_72 , NULL ) ;
if ( V_57 ) {
F_4 ( V_55 -> V_2 , L_7 , V_57 ) ;
F_25 ( V_55 -> V_70 , V_55 -> V_76 ) ;
return V_57 ;
}
return 0 ;
}
static int F_26 ( struct V_62 * V_63 )
{
struct V_55 * V_55 = F_27 ( V_63 ) ;
F_25 ( V_55 -> V_70 , V_55 -> V_76 ) ;
F_28 ( V_55 -> V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_62 * V_63 )
{
struct V_55 * V_55 = F_27 ( V_63 ) ;
F_7 ( V_55 , V_78 ,
V_79 ,
V_79 ) ;
F_7 ( V_55 , V_25 ,
V_80 , V_80 ) ;
}
