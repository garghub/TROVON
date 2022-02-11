static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_10 ) ;
int V_13 , V_14 ;
switch ( V_4 -> V_15 ) {
case V_16 :
F_3 ( F_4 ( V_12 -> V_17 ) | V_18 ,
V_12 -> V_17 ) ;
break;
case V_19 :
F_3 ( F_4 ( V_12 -> V_20 ) | V_21 |
V_22 ,
V_12 -> V_20 ) ;
break;
case V_23 :
F_3 ( F_4 ( V_12 -> V_20 ) | V_24 |
V_22 ,
V_12 -> V_20 ) ;
break;
default:
F_5 ( V_10 -> V_25 , L_1 ) ;
return - V_26 ;
}
if ( ! V_12 -> V_27 ) {
struct V_28 * V_29 ;
V_14 = F_6 ( V_10 , L_2 ,
V_30 |
V_31 |
V_32 | V_33 |
V_34 | V_35 |
V_36 ,
& V_12 -> V_29 , NULL , 0 ) ;
if ( V_14 < 0 ) {
F_5 ( V_10 -> V_25 , L_3 ) ;
return V_14 ;
}
V_29 = V_12 -> V_29 . V_29 ;
F_7 ( V_29 , V_32 , V_37 ) ;
F_7 ( V_29 , V_33 , V_38 ) ;
F_7 ( V_29 , V_34 , V_39 ) ;
F_7 ( V_29 , V_35 , V_40 ) ;
V_12 -> V_27 = true ;
}
for ( V_13 = 0 ; V_13 < V_8 -> V_41 ; V_13 ++ ) {
struct V_3 * V_42 = V_2 -> V_43 [ V_13 ] ;
V_6 = V_42 -> V_6 ;
V_14 = F_8 ( V_6 , 0 , 0 , V_44 ,
V_45 ) ;
if ( V_14 != 0 && V_14 != - V_46 ) {
F_9 ( V_10 -> V_25 , L_4 , V_14 ) ;
return V_14 ;
}
V_14 = F_10 ( V_6 , & V_12 -> V_29 , NULL ) ;
if ( V_14 != 0 && V_14 != - V_46 ) {
F_9 ( V_10 -> V_25 , L_5 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static struct V_11 * F_11 ( struct V_9 * V_10 )
{
struct V_47 * V_25 = V_10 -> V_25 ;
struct V_7 * V_48 ;
struct V_49 * V_50 , * V_6 , * V_51 , * V_52 = V_25 -> V_53 ;
struct V_11 * V_54 ;
int V_55 , V_56 ;
V_55 = F_12 ( V_10 , L_6 ) ;
if ( V_55 ) {
F_5 ( V_25 , L_7 , V_55 ) ;
return F_13 ( V_55 ) ;
}
if ( F_14 ( V_52 , L_8 ) ) {
V_55 = F_15 ( V_10 ,
L_8 ) ;
if ( V_55 )
return F_13 ( V_55 ) ;
}
V_56 = F_16 ( V_52 ) ;
V_54 = F_17 ( V_25 , sizeof( * V_54 ) + sizeof( * V_48 ) * V_56 ,
V_57 ) ;
if ( ! V_54 )
return F_13 ( - V_58 ) ;
V_10 -> V_8 = & V_54 -> V_8 [ 0 ] ;
V_10 -> V_56 = V_56 ;
V_48 = V_54 -> V_8 ;
F_18 (node, np) {
V_51 = F_19 ( V_50 , L_9 ) ;
V_6 = F_19 ( V_50 , L_10 ) ;
if ( ! V_51 || ! V_6 ) {
F_5 ( V_25 , L_11 ) ;
return F_13 ( - V_26 ) ;
}
V_48 -> V_59 = F_20 ( V_51 , L_12 , 0 ) ;
if ( ! V_48 -> V_59 ) {
F_5 ( V_10 -> V_25 , L_13 ) ;
return F_13 ( - V_26 ) ;
}
V_55 = F_21 ( V_51 , & V_48 -> V_60 ) ;
if ( V_55 ) {
F_5 ( V_10 -> V_25 , L_14 ) ;
return F_13 ( V_55 ) ;
}
V_55 = F_22 ( V_25 , V_6 , V_48 ) ;
if ( V_55 < 0 ) {
F_5 ( V_10 -> V_25 , L_15 ) ;
return F_13 ( V_55 ) ;
}
V_48 -> V_61 = V_48 -> V_59 ;
V_55 = F_23 ( V_50 , L_16 , & V_48 -> V_62 ) ;
if ( V_55 ) {
F_5 ( V_10 -> V_25 , L_17 ) ;
return F_13 ( V_55 ) ;
}
V_48 -> V_63 = V_48 -> V_62 ;
V_48 -> V_64 = F_1 ;
V_48 ++ ;
}
return V_54 ;
}
static int F_24 ( struct V_65 * V_66 )
{
struct V_47 * V_25 = & V_66 -> V_25 ;
struct V_9 * V_10 ;
struct V_11 * V_54 ;
struct V_67 * V_68 ;
V_10 = F_17 ( V_25 , sizeof( * V_10 ) , V_57 ) ;
if ( ! V_10 )
return - V_58 ;
V_10 -> V_25 = V_25 ;
V_10 -> V_69 = V_70 ;
V_10 -> V_71 = F_25 ( V_70 ) ;
V_54 = F_11 ( V_10 ) ;
if ( F_26 ( V_54 ) ) {
F_5 ( & V_66 -> V_25 , L_18 ,
F_27 ( V_54 ) ) ;
return F_27 ( V_54 ) ;
}
V_68 = F_28 ( V_66 , V_72 , L_19 ) ;
V_54 -> V_20 = F_29 ( V_25 , V_68 ) ;
if ( F_26 ( V_54 -> V_20 ) )
return F_27 ( V_54 -> V_20 ) ;
V_68 = F_28 ( V_66 , V_72 , L_20 ) ;
V_54 -> V_17 = F_29 ( V_25 , V_68 ) ;
if ( F_26 ( V_54 -> V_17 ) )
return F_27 ( V_54 -> V_17 ) ;
F_30 ( V_10 , V_54 ) ;
return F_31 ( & V_66 -> V_25 , V_10 ) ;
}
