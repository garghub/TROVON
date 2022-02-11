void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_2 V_6 , T_3 V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 ;
T_3 V_13 ;
V_13 = V_4 -> V_14 ;
V_9 = & V_4 -> V_15 [ V_13 ] ;
V_9 -> V_7 = V_7 ;
V_11 = & V_4 -> V_16 [ F_2 ( V_13 ) ] [ F_3 ( V_13 ) ] ;
V_12 = ( V_6 << V_17 ) | ( 1 << V_18 ) |
V_19 | V_20 [ V_6 >> 9 ] ;
V_11 -> V_21 = F_4 ( V_12 ) ;
V_11 -> V_22 = V_13 ;
V_11 -> V_23 = F_5 ( V_5 ) ;
V_13 = F_6 ( V_13 ) ;
V_4 -> V_14 = V_13 ;
}
void F_7 ( struct V_1 * V_2 , struct V_24 * V_25 , int V_26 )
{
struct V_3 * V_4 = V_25 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 ;
struct V_8 * V_9 ;
T_3 V_31 = V_4 -> V_31 ;
T_3 V_32 = V_31 ;
T_3 V_7 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_26 ; V_33 ++ ) {
V_32 = V_31 ;
V_31 = F_6 ( V_31 ) ;
}
V_4 -> V_31 = V_31 ;
if ( F_8 ( V_2 , V_4 ) == V_2 -> V_34 ) {
V_7 = V_29 -> V_7 ;
} else {
V_9 = & V_4 -> V_15 [ V_32 ] ;
V_7 = V_9 -> V_7 ;
}
F_9 ( V_2 , V_29 -> V_35 , V_36 | V_7 ) ;
}
bool F_10 ( struct V_1 * V_2 , struct V_28 * V_29 , T_3 V_37 ,
struct V_38 * V_38 , T_4 * * V_39 , unsigned int * V_6 , T_4 * V_40 )
{
struct V_41 * V_42 = F_11 ( V_29 -> V_42 ) ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
T_1 V_5 ;
void * V_49 ;
T_2 V_50 ;
T_2 V_51 ;
T_2 V_52 ;
if ( ! V_42 )
return false ;
V_46 = V_2 -> V_46 ;
V_4 = V_29 -> V_25 -> V_27 ;
V_44 = & V_29 -> V_53 [ V_37 ] ;
V_51 = V_2 -> V_54 ;
V_48 . V_55 = * V_39 - V_51 ;
V_48 . V_56 = * V_39 ;
V_48 . V_57 = * V_39 + * V_6 ;
V_49 = V_48 . V_56 ;
V_5 = V_44 -> V_5 - V_2 -> V_58 ;
F_12 ( & V_46 -> V_59 , V_5 + V_51 , * V_6 , V_2 -> V_60 ) ;
F_13 () ;
V_52 = F_14 ( V_42 , & V_48 ) ;
F_15 () ;
V_50 = F_8 ( V_2 , V_4 ) ;
if ( V_50 != V_2 -> V_34 )
* V_40 &= ~ V_61 ;
if ( V_49 != V_48 . V_56 ) {
V_51 = V_48 . V_56 - V_48 . V_55 ;
* V_39 = V_48 . V_55 + V_51 ;
* V_6 = V_48 . V_57 - V_48 . V_56 ;
}
switch ( V_52 ) {
case V_62 :
return false ;
case V_63 :
if ( V_50 < 1 ) {
F_16 ( V_2 -> V_59 , V_42 , V_52 ) ;
F_17 ( V_29 , V_37 , V_38 ) ;
return true ;
}
* V_40 = V_64 ;
F_18 ( & V_46 -> V_59 , V_5 + V_51 , * V_6 ,
V_2 -> V_60 ) ;
F_1 ( V_2 , V_4 , V_5 + V_51 , * V_6 ,
F_19 ( V_29 -> V_7 ) ) ;
F_17 ( V_29 , V_37 , V_38 ) ;
return true ;
default:
F_20 ( V_52 ) ;
case V_65 :
F_16 ( V_2 -> V_59 , V_42 , V_52 ) ;
case V_66 :
F_17 ( V_29 , V_37 , V_38 ) ;
break;
}
return true ;
}
static int F_21 ( struct V_1 * V_2 , struct V_41 * V_67 )
{
struct V_68 * V_59 = V_2 -> V_59 ;
int V_69 = 0 , V_70 , V_71 ;
struct V_41 * V_72 ;
if ( V_67 && V_2 -> V_59 -> V_73 > V_74 ) {
F_22 ( V_59 , L_1 ,
V_2 -> V_59 -> V_73 , V_74 ) ;
return - V_75 ;
}
if ( ! ( V_2 -> V_12 & V_76 ) ) {
F_22 ( V_59 , L_2 ) ;
return - V_75 ;
}
if ( V_67 )
V_69 = V_2 -> V_77 ;
V_71 = F_23 ( V_59 ) ;
if ( ! V_71 )
V_71 = 1 ;
V_70 = F_24 ( V_2 , V_2 -> V_78 , V_2 -> V_77 ,
true , V_71 , V_69 ) ;
if ( V_70 ) {
F_22 ( V_59 , L_3 ) ;
return V_70 ;
}
if ( F_25 ( V_59 ) )
F_26 ( V_2 , true , false ) ;
V_72 = F_27 ( & V_2 -> V_42 , V_67 ) ;
if ( V_72 )
F_28 ( V_72 ) ;
if ( V_67 ) {
F_29 ( V_2 , true ) ;
} else {
int V_79 , V_80 ;
F_29 ( V_2 , false ) ;
F_30 ( V_2 , & V_79 , & V_80 , true ) ;
if ( V_79 > 1 ) {
V_2 -> V_12 &= ~ V_81 ;
V_2 -> V_59 -> V_82 |= V_83 ;
}
}
V_2 -> V_84 = V_69 ;
V_2 -> V_85 = V_2 -> V_78 * V_71 + V_69 ;
V_2 -> V_86 = F_31 ( int , V_2 -> V_85 , V_2 -> V_77 ) ;
V_2 -> V_87 = V_2 -> V_86 ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( F_25 ( V_59 ) )
return F_34 ( V_2 , true , false ) ;
return 0 ;
}
int F_35 ( struct V_68 * V_59 , struct V_88 * V_48 )
{
struct V_1 * V_2 = F_36 ( V_59 ) ;
int V_70 ;
switch ( V_48 -> V_89 ) {
case V_90 :
V_70 = F_21 ( V_2 , V_48 -> V_67 ) ;
break;
case V_91 :
V_48 -> V_92 = ! ! V_2 -> V_42 ;
V_48 -> V_93 = V_2 -> V_42 ? V_2 -> V_42 -> V_94 -> V_95 : 0 ;
V_70 = 0 ;
break;
default:
V_70 = - V_96 ;
break;
}
return V_70 ;
}
