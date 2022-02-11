static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( 0 , V_2 -> V_4 + V_6 ) ;
F_2 ( V_7 , V_2 -> V_4 + V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + F_4 ( 1000 ) ;
F_2 ( V_11 , V_2 -> V_4 + V_8 ) ;
while ( F_5 ( V_2 -> V_4 + V_12 ) != V_13 ) {
if ( F_6 ( V_10 , V_9 ) ) {
F_1 ( V_2 ) ;
return - V_14 ;
}
F_7 () ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned char V_15 ;
T_1 V_16 ;
V_16 = F_5 ( V_2 -> V_4 + V_12 ) ;
switch ( V_16 ) {
case V_17 :
case V_18 :
V_15 = F_9 ( V_2 -> V_19 ) ;
F_2 ( V_15 , V_2 -> V_4 + V_20 ) ;
F_2 ( V_21 , V_2 -> V_4 + V_5 ) ;
break;
case V_22 :
case V_23 :
if ( V_2 -> V_24 < V_2 -> V_19 -> V_25 ) {
F_2 ( V_2 -> V_19 -> V_26 [ V_2 -> V_24 ] ,
V_2 -> V_4 + V_20 ) ;
} else if ( V_2 -> V_27 ) {
F_2 ( V_28 , V_2 -> V_4 + V_8 ) ;
F_2 ( V_29 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_30 = 0 ;
F_10 ( V_2 -> V_31 ) ;
} else {
V_2 -> V_30 = 0 ;
F_10 ( V_2 -> V_31 ) ;
}
V_2 -> V_24 ++ ;
break;
case V_32 :
if ( V_2 -> V_19 -> V_25 == 1 ) {
F_2 ( V_33 , V_2 -> V_4 + V_5 ) ;
} else {
F_2 ( V_33 , V_2 -> V_4 + V_8 ) ;
}
F_2 ( V_21 , V_2 -> V_4 + V_5 ) ;
break;
case V_34 :
case V_35 :
if ( V_2 -> V_24 < V_2 -> V_19 -> V_25 ) {
V_2 -> V_19 -> V_26 [ V_2 -> V_24 ] =
F_5 ( V_2 -> V_4 + V_20 ) ;
}
if ( V_2 -> V_24 >= V_2 -> V_19 -> V_25 - 1 && V_2 -> V_27 ) {
F_2 ( V_28 , V_2 -> V_4 + V_8 ) ;
F_2 ( V_29 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_30 = 0 ;
}
if ( V_2 -> V_24 >= V_2 -> V_19 -> V_25 - 1 ) {
V_2 -> V_30 = 0 ;
F_10 ( V_2 -> V_31 ) ;
}
if ( V_2 -> V_24 >= V_2 -> V_19 -> V_25 - 2 ) {
F_2 ( V_33 , V_2 -> V_4 + V_5 ) ;
} else {
F_2 ( V_33 , V_2 -> V_4 + V_8 ) ;
}
F_2 ( V_21 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_24 ++ ;
break;
case V_36 :
case V_37 :
case V_38 :
F_2 ( V_28 , V_2 -> V_4 + V_8 ) ;
V_2 -> V_30 = - V_39 ;
F_10 ( V_2 -> V_31 ) ;
break;
case V_40 :
V_2 -> V_30 = - V_41 ;
F_2 ( V_21 | V_11 , V_2 -> V_4 + V_5 ) ;
F_10 ( V_2 -> V_31 ) ;
break;
default:
V_2 -> V_30 = - V_42 ;
F_10 ( V_2 -> V_31 ) ;
break;
}
if ( V_2 -> V_30 != - V_14 )
F_11 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_30 != 0 )
F_2 ( V_29 , V_2 -> V_4 + V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_44 )
{
if ( ! V_44 ) {
F_2 ( V_21 , V_2 -> V_4 + V_8 ) ;
} else {
if ( F_13 ( V_2 -> V_19 -> V_45 & V_46 ) ) {
F_14 ( V_2 -> V_19 -> V_25 == 0 ) ;
if ( ! ( V_2 -> V_19 -> V_45 & V_47 ) ) {
F_2 ( V_2 -> V_19 -> V_26 [ 0 ] ,
V_2 -> V_4 + V_20 ) ;
V_2 -> V_24 ++ ;
}
} else {
F_2 ( V_21 , V_2 -> V_4 + V_8 ) ;
}
F_2 ( V_29 , V_2 -> V_4 + V_5 ) ;
}
F_15 ( V_2 -> V_31 ) ;
if ( F_16 ( V_2 -> V_43 , V_2 -> V_30 != - V_14 ,
F_4 ( 1000 ) ) == 0 ) {
F_10 ( V_2 -> V_31 ) ;
return - V_48 ;
}
return V_2 -> V_30 ;
}
static int F_17 ( struct V_49 * V_50 , struct V_51 * V_52 ,
int V_53 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
int V_54 , V_55 ;
T_1 V_56 ;
V_56 = F_5 ( V_2 -> V_4 + V_12 ) ;
if ( V_56 != V_13 ) {
return F_3 ( V_2 ) ;
}
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
V_2 -> V_19 = & V_52 [ V_55 ] ;
V_2 -> V_24 = 0 ;
V_2 -> V_30 = - V_14 ;
V_2 -> V_27 = ( V_55 == ( V_53 - 1 ) ) ;
V_54 = F_12 ( V_2 , V_55 ) ;
if ( V_54 )
return V_54 ;
}
return V_53 ;
}
static T_2 F_19 ( int V_31 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
if ( F_5 ( V_2 -> V_4 + V_8 ) & V_29 ) {
F_8 ( V_2 ) ;
return V_58 ;
}
return V_59 ;
}
static T_1 F_20 ( struct V_49 * V_50 )
{
return V_60 | V_61 ;
}
static int F_21 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 ;
int V_54 ;
V_2 = F_22 ( & V_63 -> V_69 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_65 = F_23 ( V_63 , V_72 , 0 ) ;
V_2 -> V_4 = F_24 ( & V_63 -> V_69 , V_65 ) ;
if ( F_25 ( V_2 -> V_4 ) )
return F_26 ( V_2 -> V_4 ) ;
V_2 -> V_31 = F_27 ( V_63 , 0 ) ;
if ( V_2 -> V_31 < 0 ) {
F_28 ( & V_63 -> V_69 , L_1 ) ;
return V_2 -> V_31 ;
}
F_29 ( & V_2 -> V_43 ) ;
V_2 -> V_73 = F_30 ( & V_63 -> V_69 , NULL ) ;
if ( F_25 ( V_2 -> V_73 ) ) {
F_28 ( & V_63 -> V_69 , L_2 ) ;
return F_26 ( V_2 -> V_73 ) ;
}
V_54 = F_31 ( V_2 -> V_73 ) ;
if ( V_54 ) {
F_28 ( & V_63 -> V_69 , L_3 ) ;
return V_54 ;
}
V_54 = F_32 ( & V_63 -> V_69 , V_2 -> V_31 , F_19 , 0 ,
F_33 ( & V_63 -> V_69 ) , V_2 ) ;
if ( V_54 < 0 ) {
F_28 ( & V_63 -> V_69 , L_4 ) ;
goto V_74;
}
F_10 ( V_2 -> V_31 ) ;
F_1 ( V_2 ) ;
V_54 = F_34 ( V_63 -> V_69 . V_75 , L_5 ,
& V_66 ) ;
if ( V_54 )
V_66 = 100000 ;
V_68 = F_35 ( V_2 -> V_73 ) ;
if ( V_68 == 0 ) {
F_28 ( & V_63 -> V_69 , L_6 ) ;
V_54 = - V_76 ;
goto V_74;
}
V_68 = V_68 / V_66 ;
if ( V_66 <= 100000 )
V_67 = ( V_68 * V_77 ) / 100 ;
else if ( V_66 <= 400000 )
V_67 = ( V_68 * V_78 ) / 100 ;
else
V_67 = ( V_68 * V_79 ) / 100 ;
F_2 ( V_67 , V_2 -> V_4 + V_80 ) ;
F_2 ( V_68 - V_67 , V_2 -> V_4 + V_81 ) ;
F_36 ( V_63 , V_2 ) ;
F_37 ( & V_2 -> V_50 , V_2 ) ;
V_2 -> V_50 . V_82 = V_83 ;
F_38 ( V_2 -> V_50 . V_84 , L_7 , sizeof( V_2 -> V_50 . V_84 ) ) ;
V_2 -> V_50 . V_85 = & V_86 ;
V_2 -> V_50 . V_69 . V_87 = & V_63 -> V_69 ;
V_2 -> V_50 . V_69 . V_75 = V_63 -> V_69 . V_75 ;
V_54 = F_39 ( & V_2 -> V_50 ) ;
if ( V_54 < 0 )
goto V_74;
F_40 ( & V_63 -> V_69 , L_8 ) ;
return 0 ;
V_74:
F_41 ( V_2 -> V_73 ) ;
return V_54 ;
}
static int F_42 ( struct V_62 * V_69 )
{
struct V_1 * V_2 = F_43 ( V_69 ) ;
F_44 ( & V_2 -> V_50 ) ;
F_41 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_45 ( struct V_88 * V_69 )
{
struct V_1 * V_2 = F_46 ( V_69 ) ;
F_47 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_48 ( struct V_88 * V_69 )
{
struct V_1 * V_2 = F_46 ( V_69 ) ;
F_49 ( V_2 -> V_73 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
