static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
if ( V_2 -> V_3 != V_3 ) {
F_2 ( L_1 ,
V_2 -> V_3 , V_3 ) ;
if ( V_2 -> V_3 == V_5 )
V_4 = F_3 ( V_2 , 0 ) ;
else if ( V_2 -> V_3 == V_6 )
V_4 = F_4 ( V_2 , 0 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 == V_5 )
V_4 = F_3 ( V_2 , 1 ) ;
else if ( V_3 == V_6 )
V_4 = F_4 ( V_2 , 1 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_3 = V_3 ;
return 0 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , enum V_7 V_8 )
{
switch ( V_8 ) {
case V_9 :
F_6 ( V_2 , V_10 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
break;
case V_14 :
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
break;
case V_17 :
if ( V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 -> V_20 = 0 ;
break;
case V_21 :
F_6 ( V_2 , V_22 ) ;
V_2 -> V_23 = 0 ;
break;
case V_24 :
break;
case V_25 :
V_2 -> V_13 = 0 ;
break;
case V_26 :
F_6 ( V_2 , V_27 ) ;
V_2 -> V_28 = 0 ;
break;
case V_29 :
F_6 ( V_2 , V_30 ) ;
V_2 -> V_31 = 0 ;
break;
case V_32 :
F_6 ( V_2 , V_33 ) ;
break;
case V_34 :
F_6 ( V_2 , V_35 ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
break;
case V_38 :
F_6 ( V_2 , V_39 ) ;
V_2 -> V_40 = 0 ;
if ( V_2 -> V_18 -> V_19 )
V_2 -> V_18 -> V_19 -> V_20 = 0 ;
break;
case V_41 :
F_6 ( V_2 , V_42 ) ;
V_2 -> V_43 = 0 ;
F_6 ( V_2 , V_27 ) ;
break;
case V_44 :
break;
default:
break;
}
}
static void F_7 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_8 ( F_9 ( V_46 ) ,
struct V_1 , V_47 ) ;
struct V_48 * V_49 ;
enum V_7 V_50 = V_2 -> V_18 -> V_50 ;
T_1 V_51 ;
int V_52 ;
if ( V_50 != V_32 && V_50 != V_24 )
return;
V_49 = F_10 ( V_2 -> V_18 -> V_53 -> V_54 , 1 ) ;
if ( ! V_49 ) {
F_11 ( V_2 -> V_18 -> V_53 -> V_55 ,
L_2 ) ;
return;
}
* V_2 -> V_56 = 0 ;
V_52 = F_12 ( V_49 ,
F_13 ( V_49 , 0 ) ,
V_57 ,
V_58 | V_59 ,
0 ,
V_60 ,
V_2 -> V_56 ,
1 ,
V_61 ) ;
if ( V_52 != 1 ) {
F_11 ( & V_49 -> V_62 , L_3 ) ;
return;
}
V_51 = * V_2 -> V_56 ;
if ( V_51 == 0 ) {
F_14 ( & V_2 -> V_47 ,
F_15 ( V_63 ) ) ;
return;
} else if ( V_51 != V_64 ) {
F_11 ( & V_49 -> V_62 , L_4 , V_51 ) ;
return;
}
if ( V_50 == V_32 ) {
if ( ! V_2 -> V_18 -> V_53 -> V_65 ) {
V_52 = F_12 ( V_49 ,
F_16 ( V_49 , 0 ) ,
V_66 , 0 ,
V_67 ,
0 , NULL , 0 ,
V_68 ) ;
if ( V_52 >= 0 )
V_2 -> V_18 -> V_53 -> V_65 = 1 ;
}
V_2 -> V_69 = 0 ;
} else if ( V_50 == V_24 ) {
V_2 -> V_70 = 0 ;
}
F_17 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_56 )
return;
F_19 ( & V_2 -> V_47 , F_7 ) ;
F_14 ( & V_2 -> V_47 ,
F_15 ( V_63 ) ) ;
}
static int F_20 ( struct V_1 * V_2 , enum V_7 V_71 )
{
V_72 = 1 ;
if ( V_2 -> V_18 -> V_50 == V_71 )
return 0 ;
F_2 ( L_5 , F_21 ( V_71 ) ) ;
F_5 ( V_2 , V_2 -> V_18 -> V_50 ) ;
switch ( V_71 ) {
case V_9 :
F_22 ( V_2 , 0 ) ;
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 ) ;
F_1 ( V_2 , V_73 ) ;
F_27 ( V_2 , V_10 ) ;
break;
case V_14 :
F_28 ( V_2 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_73 ) ;
F_27 ( V_2 , V_74 ) ;
break;
case V_17 :
F_23 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_6 ) ;
F_24 ( V_2 , 1 ) ;
break;
case V_21 :
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_27 ( V_2 , V_22 ) ;
V_2 -> V_75 = 0 ;
break;
case V_24 :
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 1 ) ;
F_1 ( V_2 , V_5 ) ;
F_29 ( V_2 -> V_18 -> V_53 ,
V_2 -> V_18 -> V_53 -> V_76 ) ;
F_18 ( V_2 ) ;
break;
case V_25 :
F_22 ( V_2 , 0 ) ;
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_30 ( V_2 ) ;
F_1 ( V_2 , V_5 ) ;
break;
case V_26 :
F_22 ( V_2 , 1 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_27 ( V_2 , V_27 ) ;
break;
case V_29 :
F_22 ( V_2 , 1 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_27 ( V_2 , V_30 ) ;
break;
case V_32 :
F_22 ( V_2 , 1 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 1 ) ;
F_1 ( V_2 , V_5 ) ;
if ( ! V_2 -> V_69 || V_2 -> V_37 )
F_27 ( V_2 , V_33 ) ;
F_18 ( V_2 ) ;
break;
case V_34 :
F_22 ( V_2 , 1 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_27 ( V_2 , V_35 ) ;
break;
case V_38 :
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_6 ) ;
F_22 ( V_2 , 1 ) ;
F_24 ( V_2 , 1 ) ;
F_27 ( V_2 , V_39 ) ;
break;
case V_41 :
F_22 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_27 ( V_2 , V_42 ) ;
break;
case V_44 :
F_22 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_1 ( V_2 , V_73 ) ;
break;
default:
break;
}
V_2 -> V_18 -> V_50 = V_71 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
enum V_7 V_50 ;
F_31 ( & V_2 -> V_77 ) ;
V_50 = V_2 -> V_18 -> V_50 ;
V_72 = 0 ;
switch ( V_50 ) {
case V_78 :
F_2 ( L_6 , V_2 -> V_79 ) ;
if ( V_2 -> V_79 )
F_20 ( V_2 , V_9 ) ;
else
F_20 ( V_2 , V_25 ) ;
break;
case V_9 :
if ( ! V_2 -> V_79 )
F_20 ( V_2 , V_25 ) ;
else if ( V_2 -> V_80 && V_2 -> V_18 -> V_19 )
F_20 ( V_2 , V_17 ) ;
else if ( ( V_2 -> V_70 || V_2 -> V_81 || V_2 -> V_82 ) &&
V_2 -> V_83 && V_2 -> V_11 )
F_20 ( V_2 , V_14 ) ;
break;
case V_14 :
if ( ! V_2 -> V_79 || V_2 -> V_16 )
F_20 ( V_2 , V_9 ) ;
break;
case V_17 :
if ( ! V_2 -> V_79 || ! V_2 -> V_80 )
F_20 ( V_2 , V_9 ) ;
else if ( V_2 -> V_70 && V_2 -> V_18 ->
V_19 -> V_65 && V_2 -> V_75 )
F_20 ( V_2 , V_21 ) ;
break;
case V_21 :
if ( V_2 -> V_84 )
F_20 ( V_2 , V_24 ) ;
else if ( ! V_2 -> V_79 || ! V_2 -> V_80 )
F_20 ( V_2 , V_9 ) ;
else if ( V_2 -> V_85 || V_2 -> V_23 ) {
V_2 -> V_23 = 0 ;
F_20 ( V_2 , V_17 ) ;
}
break;
case V_24 :
if ( ! V_2 -> V_79 || ! V_2 -> V_80 )
F_20 ( V_2 , V_9 ) ;
else if ( ! V_2 -> V_70 || ! V_2 -> V_84 || V_2 -> V_86 )
F_20 ( V_2 , V_17 ) ;
break;
case V_25 :
if ( V_2 -> V_79 )
F_20 ( V_2 , V_9 ) ;
else if ( ! V_2 -> V_87 && ( V_2 -> V_69 ||
V_2 -> V_88 || V_2 -> V_81 || V_2 -> V_82 ) )
F_20 ( V_2 , V_26 ) ;
break;
case V_26 :
if ( V_2 -> V_89 )
F_20 ( V_2 , V_29 ) ;
else if ( V_2 -> V_79 || V_2 -> V_87 ||
V_2 -> V_28 )
F_20 ( V_2 , V_41 ) ;
break;
case V_29 :
if ( ! V_2 -> V_89 )
F_20 ( V_2 , V_44 ) ;
else if ( V_2 -> V_90 )
F_20 ( V_2 , V_32 ) ;
else if ( V_2 -> V_79 || V_2 -> V_87 || V_2 -> V_31 )
F_20 ( V_2 , V_41 ) ;
break;
case V_32 :
if ( V_2 -> V_79 || V_2 -> V_87 )
F_20 ( V_2 , V_41 ) ;
else if ( ( ! V_2 -> V_69 || V_2 -> V_37 ) &&
V_2 -> V_18 -> V_53 -> V_65 )
F_20 ( V_2 , V_34 ) ;
else if ( ! V_2 -> V_90 )
F_20 ( V_2 , V_29 ) ;
else if ( ! V_2 -> V_89 )
F_20 ( V_2 , V_44 ) ;
break;
case V_34 :
if ( ! V_2 -> V_90 && V_2 -> V_18 -> V_53 -> V_65 )
F_20 ( V_2 , V_38 ) ;
else if ( ! V_2 -> V_90 && ! V_2 -> V_18 -> V_53 -> V_65 )
F_20 ( V_2 , V_29 ) ;
else if ( V_2 -> V_69 || V_2 -> V_91 )
F_20 ( V_2 , V_32 ) ;
else if ( V_2 -> V_79 || V_2 -> V_87 || V_2 -> V_36 )
F_20 ( V_2 , V_41 ) ;
else if ( ! V_2 -> V_89 )
F_20 ( V_2 , V_44 ) ;
break;
case V_38 :
if ( V_2 -> V_79 || V_2 -> V_87 )
F_20 ( V_2 , V_41 ) ;
else if ( V_2 -> V_40 || V_2 -> V_92 )
F_20 ( V_2 , V_29 ) ;
else if ( ! V_2 -> V_89 )
F_20 ( V_2 , V_44 ) ;
break;
case V_41 :
if ( V_2 -> V_43 )
F_20 ( V_2 , V_25 ) ;
break;
case V_44 :
if ( V_2 -> V_79 || V_2 -> V_87 || V_2 -> V_93 )
F_20 ( V_2 , V_41 ) ;
break;
default:
break;
}
F_32 ( & V_2 -> V_77 ) ;
F_2 ( L_7 , V_72 ) ;
return V_72 ;
}
