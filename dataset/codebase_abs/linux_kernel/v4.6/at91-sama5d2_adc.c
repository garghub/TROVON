static unsigned F_1 ( unsigned V_1 ,
unsigned V_2 )
{
const unsigned V_3 [] = {
0 , 8 , 16 , 24 ,
64 , 80 , 96 , 112 ,
512 , 576 , 640 , 704 ,
768 , 832 , 896 , 960
} ;
unsigned V_4 , V_5 ;
V_4 = V_1 * V_2 / 1000 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_3 ) ; V_5 ++ )
if ( V_3 [ V_5 ] > V_4 )
break;
return V_5 ;
}
static void F_3 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
unsigned V_11 , V_12 , V_13 ;
V_11 = F_5 ( V_7 -> V_14 ) ;
V_12 = ( V_11 / ( 2 * V_8 ) ) - 1 ;
V_13 = F_1 ( V_7 -> V_15 . V_16 ,
V_8 / 1000 ) ;
F_6 ( V_7 , V_17 ,
F_7 ( 2 )
| F_8 ( V_13 )
| F_9 ( V_12 ) ) ;
F_10 ( & V_10 -> V_18 , L_1 ,
V_8 , V_13 , V_12 ) ;
}
static unsigned F_11 ( struct V_6 * V_7 )
{
unsigned V_19 , V_11 = F_5 ( V_7 -> V_14 ) ;
unsigned V_20 , V_12 ;
V_20 = F_12 ( V_7 , V_17 ) ;
V_12 = ( V_20 >> V_21 )
& V_22 ;
V_19 = V_11 / ( 2 * ( V_12 + 1 ) ) ;
return V_19 ;
}
static T_1 F_13 ( int V_23 , void * V_24 )
{
struct V_9 * V_25 = V_24 ;
struct V_6 * V_7 = F_14 ( V_25 ) ;
T_2 V_26 = F_12 ( V_7 , V_27 ) ;
T_2 V_28 = F_12 ( V_7 , V_29 ) ;
if ( V_26 & V_28 ) {
V_7 -> V_30 = F_12 ( V_7 , V_7 -> V_31 -> V_32 ) ;
V_7 -> V_33 = true ;
F_15 ( & V_7 -> V_34 ) ;
return V_35 ;
}
return V_36 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_37 const * V_31 ,
int * V_38 , int * V_39 , long V_40 )
{
struct V_6 * V_7 = F_14 ( V_10 ) ;
int V_41 ;
switch ( V_40 ) {
case V_42 :
F_17 ( & V_7 -> V_43 ) ;
V_7 -> V_31 = V_31 ;
F_6 ( V_7 , V_44 , F_18 ( V_31 -> V_45 ) ) ;
F_6 ( V_7 , V_46 , F_18 ( V_31 -> V_45 ) ) ;
F_6 ( V_7 , V_47 , V_48 ) ;
V_41 = F_19 ( V_7 -> V_34 ,
V_7 -> V_33 ,
F_20 ( 1000 ) ) ;
if ( V_41 == 0 )
V_41 = - V_49 ;
if ( V_41 > 0 ) {
* V_38 = V_7 -> V_30 ;
V_41 = V_50 ;
V_7 -> V_33 = false ;
}
F_6 ( V_7 , V_51 , F_18 ( V_31 -> V_45 ) ) ;
F_6 ( V_7 , V_52 , F_18 ( V_31 -> V_45 ) ) ;
F_21 ( & V_7 -> V_43 ) ;
return V_41 ;
case V_53 :
* V_38 = V_7 -> V_54 / 1000 ;
* V_39 = V_31 -> V_55 . V_56 ;
return V_57 ;
case V_58 :
* V_38 = F_11 ( V_7 ) ;
return V_50 ;
default:
return - V_59 ;
}
}
static int F_22 ( struct V_9 * V_10 ,
struct V_37 const * V_31 ,
int V_38 , int V_39 , long V_40 )
{
struct V_6 * V_7 = F_14 ( V_10 ) ;
if ( V_40 != V_58 )
return - V_59 ;
if ( V_38 < V_7 -> V_15 . V_60 ||
V_38 > V_7 -> V_15 . V_61 )
return - V_59 ;
F_3 ( V_7 , V_38 ) ;
return 0 ;
}
static int F_23 ( struct V_62 * V_63 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
struct V_64 * V_65 ;
int V_41 ;
V_10 = F_24 ( & V_63 -> V_18 , sizeof( * V_7 ) ) ;
if ( ! V_10 )
return - V_66 ;
V_10 -> V_18 . V_67 = & V_63 -> V_18 ;
V_10 -> V_68 = F_25 ( & V_63 -> V_18 ) ;
V_10 -> V_69 = V_70 ;
V_10 -> V_71 = & V_72 ;
V_10 -> V_73 = V_74 ;
V_10 -> V_75 = F_2 ( V_74 ) ;
V_7 = F_14 ( V_10 ) ;
V_41 = F_26 ( V_63 -> V_18 . V_76 ,
L_2 ,
& V_7 -> V_15 . V_60 ) ;
if ( V_41 ) {
F_27 ( & V_63 -> V_18 ,
L_3 ) ;
return V_41 ;
}
V_41 = F_26 ( V_63 -> V_18 . V_76 ,
L_4 ,
& V_7 -> V_15 . V_61 ) ;
if ( V_41 ) {
F_27 ( & V_63 -> V_18 ,
L_5 ) ;
return V_41 ;
}
V_41 = F_26 ( V_63 -> V_18 . V_76 , L_6 ,
& V_7 -> V_15 . V_16 ) ;
if ( V_41 ) {
F_27 ( & V_63 -> V_18 ,
L_7 ) ;
return V_41 ;
}
F_28 ( & V_7 -> V_34 ) ;
F_29 ( & V_7 -> V_43 ) ;
V_65 = F_30 ( V_63 , V_77 , 0 ) ;
if ( ! V_65 )
return - V_59 ;
V_7 -> V_78 = F_31 ( & V_63 -> V_18 , V_65 ) ;
if ( F_32 ( V_7 -> V_78 ) )
return F_33 ( V_7 -> V_78 ) ;
V_7 -> V_23 = F_34 ( V_63 , 0 ) ;
if ( V_7 -> V_23 <= 0 ) {
if ( ! V_7 -> V_23 )
V_7 -> V_23 = - V_79 ;
return V_7 -> V_23 ;
}
V_7 -> V_14 = F_35 ( & V_63 -> V_18 , L_8 ) ;
if ( F_32 ( V_7 -> V_14 ) )
return F_33 ( V_7 -> V_14 ) ;
V_7 -> V_80 = F_36 ( & V_63 -> V_18 , L_9 ) ;
if ( F_32 ( V_7 -> V_80 ) )
return F_33 ( V_7 -> V_80 ) ;
V_7 -> V_81 = F_36 ( & V_63 -> V_18 , L_10 ) ;
if ( F_32 ( V_7 -> V_81 ) )
return F_33 ( V_7 -> V_81 ) ;
V_41 = F_37 ( & V_63 -> V_18 , V_7 -> V_23 , F_13 , 0 ,
V_63 -> V_18 . V_82 -> V_68 , V_10 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_38 ( V_7 -> V_80 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_38 ( V_7 -> V_81 ) ;
if ( V_41 )
goto V_83;
V_7 -> V_54 = F_39 ( V_7 -> V_81 ) ;
if ( V_7 -> V_54 <= 0 ) {
V_41 = - V_59 ;
goto V_84;
}
F_6 ( V_7 , V_47 , V_85 ) ;
F_6 ( V_7 , V_51 , 0xffffffff ) ;
F_3 ( V_7 , V_7 -> V_15 . V_60 ) ;
V_41 = F_40 ( V_7 -> V_14 ) ;
if ( V_41 )
goto V_84;
F_41 ( V_63 , V_10 ) ;
V_41 = F_42 ( V_10 ) ;
if ( V_41 < 0 )
goto V_86;
F_43 ( & V_63 -> V_18 , L_11 ,
F_44 ( V_7 -> V_78 + V_87 ) ) ;
return 0 ;
V_86:
F_45 ( V_7 -> V_14 ) ;
V_84:
F_46 ( V_7 -> V_81 ) ;
V_83:
F_46 ( V_7 -> V_80 ) ;
return V_41 ;
}
static int F_47 ( struct V_62 * V_63 )
{
struct V_9 * V_10 = F_48 ( V_63 ) ;
struct V_6 * V_7 = F_14 ( V_10 ) ;
F_49 ( V_10 ) ;
F_45 ( V_7 -> V_14 ) ;
F_46 ( V_7 -> V_81 ) ;
F_46 ( V_7 -> V_80 ) ;
return 0 ;
}
