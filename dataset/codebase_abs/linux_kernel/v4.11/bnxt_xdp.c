static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_2 V_6 , T_3 V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_2 V_14 ;
T_3 V_15 ;
V_15 = V_4 -> V_16 ;
V_9 = & V_4 -> V_17 [ V_15 ] ;
V_9 -> V_7 = V_7 ;
V_13 = & V_4 -> V_18 [ F_2 ( V_15 ) ] [ F_3 ( V_15 ) ] ;
V_14 = ( V_6 << V_19 ) | V_20 |
( 2 << V_21 ) | V_22 |
V_23 | V_24 [ V_6 >> 9 ] ;
V_13 -> V_25 = F_4 ( V_14 ) ;
V_13 -> V_26 = V_15 ;
V_13 -> V_27 = F_5 ( V_5 ) ;
V_15 = F_6 ( V_15 ) ;
V_11 = (struct V_10 * )
& V_4 -> V_18 [ F_2 ( V_15 ) ] [ F_3 ( V_15 ) ] ;
V_11 -> V_28 = F_4 ( 0 ) ;
V_11 -> V_29 = F_4 ( 0 ) ;
V_11 -> V_30 = F_4 ( 0 ) ;
V_11 -> V_31 = F_4 ( 0 ) ;
V_15 = F_6 ( V_15 ) ;
V_4 -> V_16 = V_15 ;
}
void F_7 ( struct V_1 * V_2 , struct V_32 * V_33 , int V_34 )
{
struct V_3 * V_4 = V_33 -> V_35 ;
struct V_36 * V_37 = V_33 -> V_38 ;
struct V_8 * V_9 ;
T_3 V_39 = V_4 -> V_39 ;
T_3 V_40 = V_39 ;
T_3 V_7 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_34 ; V_41 ++ ) {
V_40 = V_39 ;
V_39 = F_6 ( V_39 ) ;
V_39 = F_6 ( V_39 ) ;
}
V_4 -> V_39 = V_39 ;
if ( F_8 ( V_2 , V_4 ) == V_2 -> V_42 ) {
V_7 = V_37 -> V_7 ;
} else {
V_9 = & V_4 -> V_17 [ V_40 ] ;
V_7 = V_9 -> V_7 ;
}
F_9 ( V_43 | V_7 , V_37 -> V_44 ) ;
}
bool F_10 ( struct V_1 * V_2 , struct V_36 * V_37 , T_3 V_45 ,
struct V_46 * V_46 , T_4 * * V_47 , unsigned int * V_6 , T_4 * V_48 )
{
struct V_49 * V_50 = F_11 ( V_37 -> V_50 ) ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 ;
T_1 V_5 ;
void * V_57 ;
T_2 V_58 ;
T_2 V_59 ;
T_2 V_60 ;
if ( ! V_50 )
return false ;
V_54 = V_2 -> V_54 ;
V_4 = V_37 -> V_33 -> V_35 ;
V_52 = & V_37 -> V_61 [ V_45 ] ;
V_59 = V_2 -> V_62 ;
V_56 . V_63 = * V_47 - V_59 ;
V_56 . V_64 = * V_47 ;
V_56 . V_65 = * V_47 + * V_6 ;
V_57 = V_56 . V_64 ;
V_5 = V_52 -> V_5 - V_2 -> V_66 ;
F_12 ( & V_54 -> V_67 , V_5 + V_59 , * V_6 , V_2 -> V_68 ) ;
F_13 () ;
V_60 = F_14 ( V_50 , & V_56 ) ;
F_15 () ;
V_58 = F_8 ( V_2 , V_4 ) ;
if ( V_58 != V_2 -> V_42 )
* V_48 &= ~ V_69 ;
if ( V_57 != V_56 . V_64 ) {
V_59 = V_56 . V_64 - V_56 . V_63 ;
* V_47 = V_56 . V_63 + V_59 ;
* V_6 = V_56 . V_65 - V_56 . V_64 ;
}
switch ( V_60 ) {
case V_70 :
return false ;
case V_71 :
if ( V_58 < 2 ) {
F_16 ( V_2 -> V_67 , V_50 , V_60 ) ;
F_17 ( V_37 , V_45 , V_46 ) ;
return true ;
}
* V_48 = V_72 ;
F_18 ( & V_54 -> V_67 , V_5 + V_59 , * V_6 ,
V_2 -> V_68 ) ;
F_1 ( V_2 , V_4 , V_5 + V_59 , * V_6 ,
F_19 ( V_37 -> V_7 ) ) ;
F_17 ( V_37 , V_45 , V_46 ) ;
return true ;
default:
F_20 ( V_60 ) ;
case V_73 :
F_16 ( V_2 -> V_67 , V_50 , V_60 ) ;
case V_74 :
F_17 ( V_37 , V_45 , V_46 ) ;
break;
}
return true ;
}
static int F_21 ( struct V_1 * V_2 , struct V_49 * V_75 )
{
struct V_76 * V_67 = V_2 -> V_67 ;
int V_77 = 0 , V_78 , V_79 ;
struct V_49 * V_80 ;
if ( V_75 && V_2 -> V_67 -> V_81 > V_82 ) {
F_22 ( V_67 , L_1 ,
V_2 -> V_67 -> V_81 , V_82 ) ;
return - V_83 ;
}
if ( ! ( V_2 -> V_14 & V_84 ) ) {
F_22 ( V_67 , L_2 ) ;
return - V_83 ;
}
if ( V_75 )
V_77 = V_2 -> V_85 ;
V_79 = F_23 ( V_67 ) ;
if ( ! V_79 )
V_79 = 1 ;
V_78 = F_24 ( V_2 , V_2 -> V_86 , V_2 -> V_85 ,
V_79 , V_77 ) ;
if ( V_78 ) {
F_22 ( V_67 , L_3 ) ;
return V_78 ;
}
if ( F_25 ( V_67 ) )
F_26 ( V_2 , true , false ) ;
V_80 = F_27 ( & V_2 -> V_50 , V_75 ) ;
if ( V_80 )
F_28 ( V_80 ) ;
if ( V_75 ) {
F_29 ( V_2 , true ) ;
} else {
int V_87 , V_88 ;
F_29 ( V_2 , false ) ;
F_30 ( V_2 , & V_87 , & V_88 , true ) ;
if ( V_87 > 1 ) {
V_2 -> V_14 &= ~ V_89 ;
V_2 -> V_67 -> V_90 |= V_91 ;
}
}
V_2 -> V_92 = V_77 ;
V_2 -> V_93 = V_2 -> V_86 * V_79 + V_77 ;
V_2 -> V_94 = F_31 ( int , V_2 -> V_93 , V_2 -> V_85 ) ;
V_2 -> V_95 = V_2 -> V_94 ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( F_25 ( V_67 ) )
return F_34 ( V_2 , true , false ) ;
return 0 ;
}
int F_35 ( struct V_76 * V_67 , struct V_96 * V_56 )
{
struct V_1 * V_2 = F_36 ( V_67 ) ;
int V_78 ;
switch ( V_56 -> V_97 ) {
case V_98 :
V_78 = F_21 ( V_2 , V_56 -> V_75 ) ;
break;
case V_99 :
V_56 -> V_100 = ! ! V_2 -> V_50 ;
V_78 = 0 ;
break;
default:
V_78 = - V_101 ;
break;
}
return V_78 ;
}
