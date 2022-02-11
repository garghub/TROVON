static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 ,
unsigned int V_5 )
{
if ( V_3 < 0 )
return 0 ;
return F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , unsigned int V_5 )
{
if ( V_3 < 0 )
return 0 ;
return F_4 ( V_2 , V_3 , V_5 ) ;
}
int F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_11 -> V_15 ) ;
struct V_16 * V_17 = V_7 -> V_17 ;
int V_18 = V_11 -> V_19 -> V_20 ;
struct V_21 * V_22 = & V_14 -> V_22 [ V_18 ] ;
const struct V_23 * V_24 = V_14 -> V_24 ;
int V_25 ;
V_22 -> V_7 = V_7 ;
F_7 ( V_7 -> V_17 , 0 ,
V_26 , 16 ) ;
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_28 ,
1 << V_22 -> V_27 -> V_29 ,
0 << V_22 -> V_27 -> V_29 ) ;
F_8 ( V_7 , V_24 ) ;
if ( V_7 -> V_30 == V_31 ) {
int V_32 = V_24 -> V_32 ;
V_25 = F_9 ( V_17 ,
V_33 ,
3 , V_32 ) ;
if ( V_25 < 0 ) {
F_10 ( V_14 -> V_34 , L_1 ) ;
return V_25 ;
}
}
V_25 = F_11 ( V_17 ,
V_33 ) ;
if ( V_25 < 0 )
F_10 ( V_14 -> V_34 , L_2 ) ;
if ( V_22 -> V_35 < 0 ) {
int V_36 = F_12 ( V_14 ) ;
if ( V_36 != V_14 -> V_37 ) {
V_22 -> V_35 = V_36 ;
} else {
F_10 ( V_14 -> V_34 , L_3 ,
V_38 ) ;
V_25 = - V_39 ;
}
}
return V_25 ;
}
void F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_11 -> V_15 ) ;
struct V_21 * V_22 = & V_14 -> V_22 [ V_11 -> V_19 -> V_20 ] ;
int V_36 ;
V_36 = V_22 -> V_35 ;
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_28 ,
1 << V_22 -> V_27 -> V_29 ,
1 << V_22 -> V_27 -> V_29 ) ;
if ( ! V_22 -> V_40 ) {
F_14 ( V_14 , V_36 ) ;
V_22 -> V_35 = - 1 ;
V_22 -> V_7 = NULL ;
}
}
int F_15 ( struct V_6 * V_7 ,
struct V_41 * V_42 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_11 -> V_15 ) ;
struct V_21 * V_22 = & V_14 -> V_22 [ V_11 -> V_19 -> V_20 ] ;
int V_43 = 0 ;
int V_25 , V_44 = 0 ;
V_25 = F_16 ( V_7 , F_17 ( V_42 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_43 = F_18 ( V_7 -> V_17 -> V_45 ) ? 1 : 0 ;
V_22 -> V_46 = F_19 ( V_7 -> V_17 -> V_45 ) ;
V_22 -> V_47 = V_7 -> V_17 -> V_48 ;
F_3 ( V_14 -> V_1 , V_22 -> V_27 -> V_49 ,
V_22 -> V_46 ) ;
F_3 ( V_14 -> V_1 ,
V_22 -> V_27 -> V_49 + V_50 ,
V_22 -> V_46 + V_22 -> V_47 - 1 ) ;
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_51 ,
1 << V_22 -> V_27 -> V_52 ,
V_43 << V_22 -> V_27 -> V_52 ) ;
if ( V_22 -> V_27 -> V_53 >= 0 ) {
unsigned int V_54 = ( F_20 ( V_42 ) == 1 ) ? 1 : 0 ;
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_55 ,
1 << V_22 -> V_27 -> V_53 ,
V_54 << V_22 -> V_27 -> V_53 ) ;
}
if ( V_22 -> V_27 -> V_56 < 0 )
return 0 ;
V_44 = V_14 -> V_57 ( V_7 , F_21 ( V_42 ) ) ;
if ( V_44 < 0 )
return - V_58 ;
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_59 ,
V_22 -> V_27 -> V_60 << V_22 -> V_27 -> V_56 ,
V_44 << V_22 -> V_27 -> V_56 ) ;
return 0 ;
}
int F_22 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
return F_23 ( V_7 ) ;
}
int F_24 ( struct V_6 * V_7 , int V_61 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_16 * const V_17 = V_7 -> V_17 ;
struct V_13 * V_14 = F_6 ( V_11 -> V_15 ) ;
struct V_21 * V_22 = & V_14 -> V_22 [ V_11 -> V_19 -> V_20 ] ;
struct V_62 * V_63 = & V_14 -> V_63 [ V_22 -> V_35 ] ;
const struct V_64 * V_65 = V_63 -> V_65 ;
unsigned int V_66 = V_17 -> V_67 ;
int V_44 ;
F_25 ( V_14 -> V_34 , L_4 , V_38 , V_22 -> V_27 -> V_68 , V_61 ) ;
switch ( V_61 ) {
case V_69 :
case V_70 :
if ( V_22 -> V_27 -> V_71 >= 0 )
F_1 ( V_14 -> V_1 ,
V_22 -> V_27 -> V_72 ,
1 << V_22 -> V_27 -> V_71 ,
1 << V_22 -> V_27 -> V_71 ) ;
F_1 ( V_14 -> V_1 , V_65 -> V_73 ,
V_65 -> V_74
<< V_65 -> V_75 ,
V_66 << V_65 -> V_75 ) ;
V_44 = V_14 -> V_76 ( V_7 , V_17 -> V_77 ) ;
if ( V_44 < 0 )
return - V_58 ;
F_1 ( V_14 -> V_1 , V_65 -> V_78 ,
V_65 -> V_79
<< V_65 -> V_80 ,
V_44 << V_65 -> V_80 ) ;
F_1 ( V_14 -> V_1 , V_65 -> V_81 ,
1 << V_65 -> V_82 ,
1 << V_65 -> V_82 ) ;
return 0 ;
case V_83 :
case V_84 :
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_72 ,
1 << V_22 -> V_27 -> V_71 , 0 ) ;
F_1 ( V_14 -> V_1 , V_65 -> V_81 ,
1 << V_65 -> V_82 ,
0 << V_65 -> V_82 ) ;
F_3 ( V_14 -> V_1 , V_65 -> V_85 ,
1 << V_65 -> V_86 ) ;
return 0 ;
default:
return - V_58 ;
}
}
int F_26 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_11 -> V_15 ) ;
struct V_21 * V_22 = & V_14 -> V_22 [ V_11 -> V_19 -> V_20 ] ;
int V_87 = 0 ;
switch ( V_7 -> V_17 -> V_88 ) {
case V_89 :
V_87 = 0 ;
break;
case V_90 :
V_87 = 1 ;
break;
case V_91 :
V_87 = 1 ;
break;
default:
F_10 ( V_14 -> V_34 , L_5 ,
V_38 , V_7 -> V_17 -> V_88 ) ;
break;
}
F_1 ( V_14 -> V_1 , V_22 -> V_27 -> V_92 ,
1 << V_22 -> V_27 -> V_93 ,
V_87 << V_22 -> V_27 -> V_93 ) ;
return 0 ;
}
int F_12 ( struct V_13 * V_14 )
{
int V_94 ;
F_27 ( & V_14 -> V_95 ) ;
for ( V_94 = 0 ; V_94 < V_14 -> V_37 ; ++ V_94 ) {
if ( V_14 -> V_63 [ V_94 ] . V_96 == 0 ) {
V_14 -> V_63 [ V_94 ] . V_96 = 1 ;
F_28 ( & V_14 -> V_95 ) ;
return V_94 ;
}
}
F_28 ( & V_14 -> V_95 ) ;
return V_14 -> V_37 ;
}
int F_14 ( struct V_13 * V_14 , int V_36 )
{
F_27 ( & V_14 -> V_95 ) ;
if ( V_36 >= 0 && V_36 < V_14 -> V_37 ) {
V_14 -> V_63 [ V_36 ] . V_96 = 0 ;
F_28 ( & V_14 -> V_95 ) ;
return 0 ;
}
F_28 ( & V_14 -> V_95 ) ;
return - V_58 ;
}
int F_29 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_30 ( V_9 -> V_34 ) ;
struct V_97 * V_34 = V_14 -> V_34 ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_94 ;
if ( F_31 ( V_34 ) || V_14 -> V_98 )
return 0 ;
if ( ! V_14 -> V_99 )
V_14 -> V_99 =
F_32 ( V_34 , V_14 -> V_100 ,
sizeof( unsigned int ) , V_101 ) ;
for ( V_94 = 0 ; V_94 < V_14 -> V_100 ; V_94 ++ )
F_33 ( V_1 , V_14 -> V_102 [ V_94 ] ,
& V_14 -> V_99 [ V_94 ] ) ;
V_14 -> V_98 = true ;
V_14 -> V_103 ( V_34 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_30 ( V_9 -> V_34 ) ;
struct V_97 * V_34 = V_14 -> V_34 ;
struct V_1 * V_1 = V_14 -> V_1 ;
int V_94 = 0 ;
if ( F_31 ( V_34 ) || ! V_14 -> V_98 )
return 0 ;
V_14 -> V_104 ( V_34 ) ;
if ( ! V_14 -> V_99 )
F_25 ( V_34 , L_6 , V_38 ) ;
for ( V_94 = 0 ; V_94 < V_14 -> V_100 ; V_94 ++ )
F_3 ( V_1 , V_14 -> V_102 [ V_94 ] ,
V_14 -> V_99 [ V_94 ] ) ;
V_14 -> V_98 = false ;
return 0 ;
}
