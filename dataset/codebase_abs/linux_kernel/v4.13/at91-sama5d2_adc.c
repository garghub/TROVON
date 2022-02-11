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
unsigned V_11 , V_12 , V_13 , V_14 ;
V_11 = F_5 ( V_7 -> V_15 ) ;
V_12 = ( V_11 / ( 2 * V_8 ) ) - 1 ;
V_13 = F_1 ( V_7 -> V_16 . V_17 ,
V_8 / 1000 ) ;
V_14 = F_6 ( V_7 , V_18 ) ;
V_14 &= ~ ( V_19 | V_20 ) ;
V_14 |= F_7 ( V_13 ) ;
V_14 |= F_8 ( V_12 ) ;
F_9 ( V_7 , V_18 , V_14 ) ;
F_10 ( & V_10 -> V_21 , L_1 ,
V_8 , V_13 , V_12 ) ;
}
static unsigned F_11 ( struct V_6 * V_7 )
{
unsigned V_22 , V_11 = F_5 ( V_7 -> V_15 ) ;
unsigned V_14 , V_12 ;
V_14 = F_6 ( V_7 , V_18 ) ;
V_12 = ( V_14 >> V_23 )
& V_24 ;
V_22 = V_11 / ( 2 * ( V_12 + 1 ) ) ;
return V_22 ;
}
static T_1 F_12 ( int V_25 , void * V_26 )
{
struct V_9 * V_27 = V_26 ;
struct V_6 * V_7 = F_13 ( V_27 ) ;
T_2 V_28 = F_6 ( V_7 , V_29 ) ;
T_2 V_30 = F_6 ( V_7 , V_31 ) ;
if ( V_28 & V_30 ) {
V_7 -> V_32 = F_6 ( V_7 , V_7 -> V_33 -> V_34 ) ;
V_7 -> V_35 = true ;
F_14 ( & V_7 -> V_36 ) ;
return V_37 ;
}
return V_38 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_39 const * V_33 ,
int * V_40 , int * V_41 , long V_42 )
{
struct V_6 * V_7 = F_13 ( V_10 ) ;
T_2 V_43 = 0 ;
int V_44 ;
switch ( V_42 ) {
case V_45 :
F_16 ( & V_7 -> V_46 ) ;
V_7 -> V_33 = V_33 ;
if ( V_33 -> V_47 )
V_43 = ( F_17 ( V_33 -> V_48 ) | F_17 ( V_33 -> V_49 ) ) <<
V_50 ;
F_9 ( V_7 , V_51 , V_43 ) ;
F_9 ( V_7 , V_52 , F_17 ( V_33 -> V_48 ) ) ;
F_9 ( V_7 , V_53 , F_17 ( V_33 -> V_48 ) ) ;
F_9 ( V_7 , V_54 , V_55 ) ;
V_44 = F_18 ( V_7 -> V_36 ,
V_7 -> V_35 ,
F_19 ( 1000 ) ) ;
if ( V_44 == 0 )
V_44 = - V_56 ;
if ( V_44 > 0 ) {
* V_40 = V_7 -> V_32 ;
if ( V_33 -> V_57 . V_58 == 's' )
* V_40 = F_20 ( * V_40 , 11 ) ;
V_44 = V_59 ;
V_7 -> V_35 = false ;
}
F_9 ( V_7 , V_60 , F_17 ( V_33 -> V_48 ) ) ;
F_9 ( V_7 , V_61 , F_17 ( V_33 -> V_48 ) ) ;
F_21 ( & V_7 -> V_46 ) ;
return V_44 ;
case V_62 :
* V_40 = V_7 -> V_63 / 1000 ;
if ( V_33 -> V_47 )
* V_40 *= 2 ;
* V_41 = V_33 -> V_57 . V_64 ;
return V_65 ;
case V_66 :
* V_40 = F_11 ( V_7 ) ;
return V_59 ;
default:
return - V_67 ;
}
}
static int F_22 ( struct V_9 * V_10 ,
struct V_39 const * V_33 ,
int V_40 , int V_41 , long V_42 )
{
struct V_6 * V_7 = F_13 ( V_10 ) ;
if ( V_42 != V_66 )
return - V_67 ;
if ( V_40 < V_7 -> V_16 . V_68 ||
V_40 > V_7 -> V_16 . V_69 )
return - V_67 ;
F_3 ( V_7 , V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_70 * V_71 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
struct V_72 * V_73 ;
int V_44 ;
V_10 = F_24 ( & V_71 -> V_21 , sizeof( * V_7 ) ) ;
if ( ! V_10 )
return - V_74 ;
V_10 -> V_21 . V_75 = & V_71 -> V_21 ;
V_10 -> V_76 = F_25 ( & V_71 -> V_21 ) ;
V_10 -> V_77 = V_78 ;
V_10 -> V_79 = & V_80 ;
V_10 -> V_81 = V_82 ;
V_10 -> V_83 = F_2 ( V_82 ) ;
V_7 = F_13 ( V_10 ) ;
V_44 = F_26 ( V_71 -> V_21 . V_84 ,
L_2 ,
& V_7 -> V_16 . V_68 ) ;
if ( V_44 ) {
F_27 ( & V_71 -> V_21 ,
L_3 ) ;
return V_44 ;
}
V_44 = F_26 ( V_71 -> V_21 . V_84 ,
L_4 ,
& V_7 -> V_16 . V_69 ) ;
if ( V_44 ) {
F_27 ( & V_71 -> V_21 ,
L_5 ) ;
return V_44 ;
}
V_44 = F_26 ( V_71 -> V_21 . V_84 , L_6 ,
& V_7 -> V_16 . V_17 ) ;
if ( V_44 ) {
F_27 ( & V_71 -> V_21 ,
L_7 ) ;
return V_44 ;
}
F_28 ( & V_7 -> V_36 ) ;
F_29 ( & V_7 -> V_46 ) ;
V_73 = F_30 ( V_71 , V_85 , 0 ) ;
if ( ! V_73 )
return - V_67 ;
V_7 -> V_86 = F_31 ( & V_71 -> V_21 , V_73 ) ;
if ( F_32 ( V_7 -> V_86 ) )
return F_33 ( V_7 -> V_86 ) ;
V_7 -> V_25 = F_34 ( V_71 , 0 ) ;
if ( V_7 -> V_25 <= 0 ) {
if ( ! V_7 -> V_25 )
V_7 -> V_25 = - V_87 ;
return V_7 -> V_25 ;
}
V_7 -> V_15 = F_35 ( & V_71 -> V_21 , L_8 ) ;
if ( F_32 ( V_7 -> V_15 ) )
return F_33 ( V_7 -> V_15 ) ;
V_7 -> V_88 = F_36 ( & V_71 -> V_21 , L_9 ) ;
if ( F_32 ( V_7 -> V_88 ) )
return F_33 ( V_7 -> V_88 ) ;
V_7 -> V_89 = F_36 ( & V_71 -> V_21 , L_10 ) ;
if ( F_32 ( V_7 -> V_89 ) )
return F_33 ( V_7 -> V_89 ) ;
V_44 = F_37 ( & V_71 -> V_21 , V_7 -> V_25 , F_12 , 0 ,
V_71 -> V_21 . V_90 -> V_76 , V_10 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_38 ( V_7 -> V_88 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_38 ( V_7 -> V_89 ) ;
if ( V_44 )
goto V_91;
V_7 -> V_63 = F_39 ( V_7 -> V_89 ) ;
if ( V_7 -> V_63 <= 0 ) {
V_44 = - V_67 ;
goto V_92;
}
F_9 ( V_7 , V_54 , V_93 ) ;
F_9 ( V_7 , V_60 , 0xffffffff ) ;
F_9 ( V_7 , V_18 ,
F_40 ( 2 ) | V_94 ) ;
F_3 ( V_7 , V_7 -> V_16 . V_68 ) ;
V_44 = F_41 ( V_7 -> V_15 ) ;
if ( V_44 )
goto V_92;
F_42 ( V_71 , V_10 ) ;
V_44 = F_43 ( V_10 ) ;
if ( V_44 < 0 )
goto V_95;
F_44 ( & V_71 -> V_21 , L_11 ,
F_45 ( V_7 -> V_86 + V_96 ) ) ;
return 0 ;
V_95:
F_46 ( V_7 -> V_15 ) ;
V_92:
F_47 ( V_7 -> V_89 ) ;
V_91:
F_47 ( V_7 -> V_88 ) ;
return V_44 ;
}
static int F_48 ( struct V_70 * V_71 )
{
struct V_9 * V_10 = F_49 ( V_71 ) ;
struct V_6 * V_7 = F_13 ( V_10 ) ;
F_50 ( V_10 ) ;
F_46 ( V_7 -> V_15 ) ;
F_47 ( V_7 -> V_89 ) ;
F_47 ( V_7 -> V_88 ) ;
return 0 ;
}
