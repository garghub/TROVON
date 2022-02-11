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
break;
case V_18 :
F_6 ( V_2 , V_19 ) ;
V_2 -> V_20 = 0 ;
break;
case V_21 :
break;
case V_22 :
V_2 -> V_13 = 0 ;
break;
case V_23 :
F_6 ( V_2 , V_24 ) ;
V_2 -> V_25 = 0 ;
break;
case V_26 :
F_6 ( V_2 , V_27 ) ;
V_2 -> V_28 = 0 ;
break;
case V_29 :
F_6 ( V_2 , V_30 ) ;
break;
case V_31 :
F_6 ( V_2 , V_32 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
break;
case V_35 :
F_6 ( V_2 , V_36 ) ;
V_2 -> V_37 = 0 ;
break;
case V_38 :
F_6 ( V_2 , V_39 ) ;
V_2 -> V_40 = 0 ;
F_6 ( V_2 , V_24 ) ;
break;
case V_41 :
break;
default:
break;
}
}
static int F_7 ( struct V_1 * V_2 , enum V_7 V_42 )
{
V_43 = 1 ;
if ( V_2 -> V_44 -> V_45 -> V_46 == V_42 )
return 0 ;
F_2 ( L_2 , F_8 ( V_42 ) ) ;
F_5 ( V_2 , V_2 -> V_44 -> V_45 -> V_46 ) ;
switch ( V_42 ) {
case V_9 :
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_13 ( V_2 ) ;
F_1 ( V_2 , V_47 ) ;
F_14 ( V_2 , V_10 ) ;
break;
case V_14 :
F_15 ( V_2 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_47 ) ;
F_14 ( V_2 , V_48 ) ;
break;
case V_17 :
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 , 1 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_6 ) ;
break;
case V_18 :
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_14 ( V_2 , V_19 ) ;
V_2 -> V_49 = 0 ;
break;
case V_21 :
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 1 ) ;
F_1 ( V_2 , V_5 ) ;
F_16 ( V_2 -> V_44 -> V_50 ,
V_2 -> V_44 -> V_50 -> V_51 ) ;
break;
case V_22 :
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_17 ( V_2 ) ;
F_1 ( V_2 , V_5 ) ;
break;
case V_23 :
F_9 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_14 ( V_2 , V_24 ) ;
break;
case V_26 :
F_9 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_14 ( V_2 , V_27 ) ;
break;
case V_29 :
F_9 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 1 ) ;
F_1 ( V_2 , V_5 ) ;
if ( ! V_2 -> V_52 || V_2 -> V_34 )
F_14 ( V_2 , V_30 ) ;
break;
case V_31 :
F_9 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_14 ( V_2 , V_32 ) ;
break;
case V_35 :
F_11 ( V_2 , 1 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_6 ) ;
F_9 ( V_2 , 1 ) ;
F_14 ( V_2 , V_36 ) ;
break;
case V_38 :
F_9 ( V_2 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_14 ( V_2 , V_39 ) ;
break;
case V_41 :
F_9 ( V_2 , 0 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_1 ( V_2 , V_47 ) ;
break;
default:
break;
}
V_2 -> V_44 -> V_45 -> V_46 = V_42 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
enum V_7 V_46 ;
F_19 ( & V_2 -> V_53 ) ;
V_46 = V_2 -> V_44 -> V_45 -> V_46 ;
V_43 = 0 ;
switch ( V_46 ) {
case V_54 :
F_2 ( L_3 , V_2 -> V_55 ) ;
if ( V_2 -> V_55 )
F_7 ( V_2 , V_9 ) ;
else
F_7 ( V_2 , V_22 ) ;
break;
case V_9 :
if ( ! V_2 -> V_55 )
F_7 ( V_2 , V_22 ) ;
else if ( V_2 -> V_56 && V_2 -> V_44 -> V_57 )
F_7 ( V_2 , V_17 ) ;
else if ( ( V_2 -> V_58 || V_2 -> V_59 || V_2 -> V_60 ) &&
V_2 -> V_61 && V_2 -> V_11 )
F_7 ( V_2 , V_14 ) ;
break;
case V_14 :
if ( ! V_2 -> V_55 || V_2 -> V_16 )
F_7 ( V_2 , V_9 ) ;
break;
case V_17 :
if ( ! V_2 -> V_55 || ! V_2 -> V_56 )
F_7 ( V_2 , V_9 ) ;
else if ( V_2 -> V_58 && V_2 -> V_44 ->
V_57 -> V_62 && V_2 -> V_49 )
F_7 ( V_2 , V_18 ) ;
break;
case V_18 :
if ( V_2 -> V_63 )
F_7 ( V_2 , V_21 ) ;
else if ( ! V_2 -> V_55 || ! V_2 -> V_56 )
F_7 ( V_2 , V_9 ) ;
else if ( V_2 -> V_64 || V_2 -> V_20 ) {
V_2 -> V_20 = 0 ;
F_7 ( V_2 , V_17 ) ;
}
break;
case V_21 :
if ( ! V_2 -> V_55 || ! V_2 -> V_56 )
F_7 ( V_2 , V_9 ) ;
else if ( ! V_2 -> V_58 || ! V_2 -> V_63 || V_2 -> V_65 )
F_7 ( V_2 , V_17 ) ;
break;
case V_22 :
if ( V_2 -> V_55 )
F_7 ( V_2 , V_9 ) ;
else if ( ! V_2 -> V_66 && ( V_2 -> V_52 ||
V_2 -> V_67 || V_2 -> V_59 || V_2 -> V_60 ) )
F_7 ( V_2 , V_23 ) ;
break;
case V_23 :
if ( V_2 -> V_68 )
F_7 ( V_2 , V_26 ) ;
else if ( V_2 -> V_55 || V_2 -> V_66 ||
V_2 -> V_25 )
F_7 ( V_2 , V_38 ) ;
break;
case V_26 :
if ( ! V_2 -> V_68 )
F_7 ( V_2 , V_41 ) ;
else if ( V_2 -> V_69 )
F_7 ( V_2 , V_29 ) ;
else if ( V_2 -> V_55 || V_2 -> V_66 || V_2 -> V_28 )
F_7 ( V_2 , V_38 ) ;
break;
case V_29 :
if ( V_2 -> V_55 || V_2 -> V_66 )
F_7 ( V_2 , V_38 ) ;
else if ( ( ! V_2 -> V_52 || V_2 -> V_34 ) &&
V_2 -> V_44 -> V_50 -> V_62 )
F_7 ( V_2 , V_31 ) ;
else if ( ! V_2 -> V_69 )
F_7 ( V_2 , V_26 ) ;
else if ( ! V_2 -> V_68 )
F_7 ( V_2 , V_41 ) ;
break;
case V_31 :
if ( ! V_2 -> V_69 && V_2 -> V_44 -> V_50 -> V_62 )
F_7 ( V_2 , V_35 ) ;
else if ( ! V_2 -> V_69 && ! V_2 -> V_44 -> V_50 -> V_62 )
F_7 ( V_2 , V_26 ) ;
else if ( V_2 -> V_52 || V_2 -> V_70 )
F_7 ( V_2 , V_29 ) ;
else if ( V_2 -> V_55 || V_2 -> V_66 || V_2 -> V_33 )
F_7 ( V_2 , V_38 ) ;
else if ( ! V_2 -> V_68 )
F_7 ( V_2 , V_41 ) ;
break;
case V_35 :
if ( V_2 -> V_55 || V_2 -> V_66 )
F_7 ( V_2 , V_38 ) ;
else if ( V_2 -> V_37 || V_2 -> V_71 )
F_7 ( V_2 , V_26 ) ;
else if ( ! V_2 -> V_68 )
F_7 ( V_2 , V_41 ) ;
break;
case V_38 :
if ( V_2 -> V_40 )
F_7 ( V_2 , V_22 ) ;
break;
case V_41 :
if ( V_2 -> V_55 || V_2 -> V_66 || V_2 -> V_72 )
F_7 ( V_2 , V_38 ) ;
break;
default:
break;
}
F_20 ( & V_2 -> V_53 ) ;
F_2 ( L_4 , V_43 ) ;
return V_43 ;
}
