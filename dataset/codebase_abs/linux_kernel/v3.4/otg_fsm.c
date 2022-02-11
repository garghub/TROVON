static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
if ( V_2 -> V_3 != V_3 ) {
F_2 ( L_1 ,
V_2 -> V_3 , V_3 ) ;
if ( V_2 -> V_3 == V_5 )
V_4 = V_2 -> V_6 -> V_7 ( V_2 , 0 ) ;
else if ( V_2 -> V_3 == V_8 )
V_4 = V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 == V_5 )
V_4 = V_2 -> V_6 -> V_7 ( V_2 , 1 ) ;
else if ( V_3 == V_8 )
V_4 = V_2 -> V_6 -> V_9 ( V_2 , 1 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_3 = V_3 ;
return 0 ;
}
return 0 ;
}
void F_3 ( struct V_1 * V_2 , enum V_10 V_11 )
{
switch ( V_11 ) {
case V_12 :
F_4 ( V_2 , V_13 ) ;
V_2 -> V_14 = 0 ;
break;
case V_15 :
V_2 -> V_16 = 0 ;
break;
case V_17 :
break;
case V_18 :
F_4 ( V_2 , V_19 ) ;
V_2 -> V_20 = 0 ;
break;
case V_21 :
break;
case V_22 :
break;
case V_23 :
F_4 ( V_2 , V_24 ) ;
V_2 -> V_25 = 0 ;
break;
case V_26 :
F_4 ( V_2 , V_27 ) ;
V_2 -> V_28 = 0 ;
break;
case V_29 :
F_4 ( V_2 , V_30 ) ;
break;
case V_31 :
F_4 ( V_2 , V_32 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
break;
case V_35 :
break;
case V_36 :
F_4 ( V_2 , V_24 ) ;
break;
case V_37 :
break;
default:
break;
}
}
int F_5 ( struct V_1 * V_2 , enum V_10 V_38 )
{
V_39 = 1 ;
if ( V_2 -> V_40 -> V_41 -> V_42 == V_38 )
return 0 ;
F_2 ( L_2 , F_6 ( V_38 ) ) ;
F_3 ( V_2 , V_2 -> V_40 -> V_41 -> V_42 ) ;
switch ( V_38 ) {
case V_12 :
F_7 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_43 ) ;
F_11 ( V_2 , V_13 ) ;
break;
case V_15 :
F_12 ( V_2 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_43 ) ;
F_11 ( V_2 , V_44 ) ;
break;
case V_17 :
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 , 1 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_8 ) ;
break;
case V_18 :
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_11 ( V_2 , V_19 ) ;
V_2 -> V_45 = 0 ;
break;
case V_21 :
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 1 ) ;
F_1 ( V_2 , V_5 ) ;
F_13 ( V_2 -> V_40 -> V_46 ,
V_2 -> V_40 -> V_46 -> V_47 ) ;
break;
case V_22 :
F_7 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
break;
case V_23 :
F_7 ( V_2 , 1 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_11 ( V_2 , V_24 ) ;
break;
case V_26 :
F_7 ( V_2 , 1 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_11 ( V_2 , V_27 ) ;
break;
case V_29 :
F_7 ( V_2 , 1 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 1 ) ;
F_1 ( V_2 , V_5 ) ;
if ( ! V_2 -> V_48 || V_2 -> V_34 )
F_11 ( V_2 , V_30 ) ;
break;
case V_31 :
F_7 ( V_2 , 1 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
F_11 ( V_2 , V_32 ) ;
break;
case V_35 :
F_9 ( V_2 , 1 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_8 ) ;
F_7 ( V_2 , 1 ) ;
break;
case V_36 :
F_7 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_5 ) ;
break;
case V_37 :
F_7 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_1 ( V_2 , V_43 ) ;
break;
default:
break;
}
V_2 -> V_40 -> V_41 -> V_42 = V_38 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
enum V_10 V_42 ;
unsigned long V_49 ;
F_15 ( & V_2 -> V_50 , V_49 ) ;
V_42 = V_2 -> V_40 -> V_41 -> V_42 ;
V_39 = 0 ;
switch ( V_42 ) {
case V_51 :
F_2 ( L_3 , V_2 -> V_52 ) ;
if ( V_2 -> V_52 )
F_5 ( V_2 , V_12 ) ;
else
F_5 ( V_2 , V_22 ) ;
break;
case V_12 :
if ( ! V_2 -> V_52 )
F_5 ( V_2 , V_22 ) ;
else if ( V_2 -> V_53 && V_2 -> V_40 -> V_54 )
F_5 ( V_2 , V_17 ) ;
else if ( V_2 -> V_55 && V_2 -> V_56 && V_2 -> V_14 )
F_5 ( V_2 , V_15 ) ;
break;
case V_15 :
if ( ! V_2 -> V_52 || V_2 -> V_16 )
F_5 ( V_2 , V_12 ) ;
break;
case V_17 :
if ( ! V_2 -> V_52 || ! V_2 -> V_53 )
F_5 ( V_2 , V_12 ) ;
else if ( V_2 -> V_55 && V_2 -> V_40 ->
V_54 -> V_57 && V_2 -> V_45 )
F_5 ( V_2 , V_18 ) ;
break;
case V_18 :
if ( V_2 -> V_58 )
F_5 ( V_2 , V_21 ) ;
else if ( ! V_2 -> V_52 || ! V_2 -> V_53 )
F_5 ( V_2 , V_12 ) ;
else if ( V_2 -> V_59 || V_2 -> V_20 ) {
V_2 -> V_20 = 0 ;
F_5 ( V_2 , V_17 ) ;
}
break;
case V_21 :
if ( ! V_2 -> V_52 || ! V_2 -> V_53 )
F_5 ( V_2 , V_12 ) ;
else if ( ! V_2 -> V_55 || ! V_2 -> V_58 )
F_5 ( V_2 , V_17 ) ;
break;
case V_22 :
if ( V_2 -> V_52 )
F_5 ( V_2 , V_12 ) ;
else if ( ! V_2 -> V_60 && ( V_2 -> V_48 || V_2 -> V_61 ) )
F_5 ( V_2 , V_23 ) ;
break;
case V_23 :
if ( V_2 -> V_52 || V_2 -> V_60 || V_2 -> V_62 ||
V_2 -> V_25 ) {
F_5 ( V_2 , V_26 ) ;
}
break;
case V_26 :
if ( ! V_2 -> V_62 )
F_5 ( V_2 , V_37 ) ;
else if ( V_2 -> V_63 )
F_5 ( V_2 , V_29 ) ;
else if ( V_2 -> V_52 | V_2 -> V_60 | V_2 -> V_28 )
F_5 ( V_2 , V_36 ) ;
break;
case V_29 :
if ( ( ! V_2 -> V_48 || V_2 -> V_34 ) &&
V_2 -> V_40 -> V_46 -> V_57 )
F_5 ( V_2 , V_31 ) ;
else if ( V_2 -> V_52 || ! V_2 -> V_63 || V_2 -> V_60 )
F_5 ( V_2 , V_26 ) ;
else if ( ! V_2 -> V_62 )
F_5 ( V_2 , V_37 ) ;
break;
case V_31 :
if ( ! V_2 -> V_63 && V_2 -> V_40 -> V_46 -> V_57 )
F_5 ( V_2 , V_35 ) ;
else if ( ! V_2 -> V_63 && ! V_2 -> V_40 -> V_46 -> V_57 )
F_5 ( V_2 , V_26 ) ;
else if ( V_2 -> V_48 || V_2 -> V_64 )
F_5 ( V_2 , V_29 ) ;
else if ( V_2 -> V_52 || V_2 -> V_60 || V_2 -> V_33 )
F_5 ( V_2 , V_36 ) ;
else if ( ! V_2 -> V_62 )
F_5 ( V_2 , V_37 ) ;
break;
case V_35 :
if ( V_2 -> V_52 || V_2 -> V_60 )
F_5 ( V_2 , V_36 ) ;
else if ( V_2 -> V_65 )
F_5 ( V_2 , V_26 ) ;
else if ( ! V_2 -> V_62 )
F_5 ( V_2 , V_37 ) ;
break;
case V_36 :
if ( V_2 -> V_52 || V_2 -> V_48 || ( ! V_2 -> V_66 &&
! V_2 -> V_63 ) )
F_5 ( V_2 , V_22 ) ;
break;
case V_37 :
if ( V_2 -> V_52 || V_2 -> V_60 || V_2 -> V_67 )
F_5 ( V_2 , V_36 ) ;
break;
default:
break;
}
F_16 ( & V_2 -> V_50 , V_49 ) ;
F_2 ( L_4 , V_39 ) ;
return V_39 ;
}
