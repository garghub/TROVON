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
V_15 = V_2 -> V_19 -> V_20 << 1 ;
if ( V_2 -> V_19 -> V_21 & V_22 )
V_15 |= 1 ;
F_2 ( V_15 , V_2 -> V_4 + V_23 ) ;
F_2 ( V_24 , V_2 -> V_4 + V_5 ) ;
break;
case V_25 :
case V_26 :
if ( V_2 -> V_27 < V_2 -> V_19 -> V_28 ) {
F_2 ( V_2 -> V_19 -> V_29 [ V_2 -> V_27 ] ,
V_2 -> V_4 + V_23 ) ;
} else if ( V_2 -> V_30 ) {
F_2 ( V_31 , V_2 -> V_4 + V_8 ) ;
F_2 ( V_32 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_33 = 0 ;
F_9 ( V_2 -> V_34 ) ;
} else {
V_2 -> V_33 = 0 ;
F_9 ( V_2 -> V_34 ) ;
}
V_2 -> V_27 ++ ;
break;
case V_35 :
if ( V_2 -> V_19 -> V_28 == 1 ) {
F_2 ( V_36 , V_2 -> V_4 + V_5 ) ;
} else {
F_2 ( V_36 , V_2 -> V_4 + V_8 ) ;
}
F_2 ( V_24 , V_2 -> V_4 + V_5 ) ;
break;
case V_37 :
case V_38 :
if ( V_2 -> V_27 < V_2 -> V_19 -> V_28 ) {
V_2 -> V_19 -> V_29 [ V_2 -> V_27 ] =
F_5 ( V_2 -> V_4 + V_23 ) ;
}
if ( V_2 -> V_27 >= V_2 -> V_19 -> V_28 - 1 && V_2 -> V_30 ) {
F_2 ( V_31 , V_2 -> V_4 + V_8 ) ;
F_2 ( V_32 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_33 = 0 ;
}
if ( V_2 -> V_27 >= V_2 -> V_19 -> V_28 - 1 ) {
V_2 -> V_33 = 0 ;
F_9 ( V_2 -> V_34 ) ;
}
if ( V_2 -> V_27 >= V_2 -> V_19 -> V_28 - 2 ) {
F_2 ( V_36 , V_2 -> V_4 + V_5 ) ;
} else {
F_2 ( V_36 , V_2 -> V_4 + V_8 ) ;
}
F_2 ( V_24 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_27 ++ ;
break;
case V_39 :
case V_40 :
case V_41 :
F_2 ( V_31 , V_2 -> V_4 + V_8 ) ;
V_2 -> V_33 = - V_42 ;
F_9 ( V_2 -> V_34 ) ;
break;
case V_43 :
V_2 -> V_33 = - V_44 ;
F_2 ( V_24 | V_11 , V_2 -> V_4 + V_5 ) ;
F_9 ( V_2 -> V_34 ) ;
break;
default:
V_2 -> V_33 = - V_45 ;
F_9 ( V_2 -> V_34 ) ;
break;
}
if ( V_2 -> V_33 != - V_14 )
F_10 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_33 != 0 )
F_2 ( V_32 , V_2 -> V_4 + V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_47 )
{
if ( ! V_47 ) {
F_2 ( V_24 , V_2 -> V_4 + V_8 ) ;
} else {
if ( F_12 ( V_2 -> V_19 -> V_21 & V_48 ) ) {
F_13 ( V_2 -> V_19 -> V_28 == 0 ) ;
if ( ! ( V_2 -> V_19 -> V_21 & V_22 ) ) {
F_2 ( V_2 -> V_19 -> V_29 [ 0 ] ,
V_2 -> V_4 + V_23 ) ;
V_2 -> V_27 ++ ;
}
} else {
F_2 ( V_24 , V_2 -> V_4 + V_8 ) ;
}
F_2 ( V_32 , V_2 -> V_4 + V_5 ) ;
}
F_14 ( V_2 -> V_34 ) ;
if ( F_15 ( V_2 -> V_46 , V_2 -> V_33 != - V_14 ,
F_4 ( 1000 ) ) == 0 ) {
F_9 ( V_2 -> V_34 ) ;
return - V_49 ;
}
return V_2 -> V_33 ;
}
static int F_16 ( struct V_50 * V_51 , struct V_52 * V_53 ,
int V_54 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_55 , V_56 ;
T_1 V_57 ;
V_57 = F_5 ( V_2 -> V_4 + V_12 ) ;
if ( V_57 != V_13 ) {
return F_3 ( V_2 ) ;
}
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
V_2 -> V_19 = & V_53 [ V_56 ] ;
V_2 -> V_27 = 0 ;
V_2 -> V_33 = - V_14 ;
V_2 -> V_30 = ( V_56 == ( V_54 - 1 ) ) ;
V_55 = F_11 ( V_2 , V_56 ) ;
if ( V_55 )
return V_55 ;
}
return V_54 ;
}
static T_2 F_18 ( int V_34 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
if ( F_5 ( V_2 -> V_4 + V_8 ) & V_32 ) {
F_8 ( V_2 ) ;
return V_59 ;
}
return V_60 ;
}
static T_1 F_19 ( struct V_50 * V_51 )
{
return V_61 | V_62 ;
}
static int F_20 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
int V_55 ;
V_2 = F_21 ( & V_64 -> V_70 , sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
return - V_72 ;
V_66 = F_22 ( V_64 , V_73 , 0 ) ;
V_2 -> V_4 = F_23 ( & V_64 -> V_70 , V_66 ) ;
if ( F_24 ( V_2 -> V_4 ) )
return F_25 ( V_2 -> V_4 ) ;
V_2 -> V_34 = F_26 ( V_64 , 0 ) ;
if ( V_2 -> V_34 < 0 ) {
F_27 ( & V_64 -> V_70 , L_1 ) ;
return V_2 -> V_34 ;
}
F_28 ( & V_2 -> V_46 ) ;
V_2 -> V_74 = F_29 ( & V_64 -> V_70 , NULL ) ;
if ( F_24 ( V_2 -> V_74 ) ) {
F_27 ( & V_64 -> V_70 , L_2 ) ;
return F_25 ( V_2 -> V_74 ) ;
}
V_55 = F_30 ( V_2 -> V_74 ) ;
if ( V_55 ) {
F_27 ( & V_64 -> V_70 , L_3 ) ;
return V_55 ;
}
V_55 = F_31 ( & V_64 -> V_70 , V_2 -> V_34 , F_18 , 0 ,
F_32 ( & V_64 -> V_70 ) , V_2 ) ;
if ( V_55 < 0 ) {
F_27 ( & V_64 -> V_70 , L_4 ) ;
goto V_75;
}
F_9 ( V_2 -> V_34 ) ;
F_1 ( V_2 ) ;
V_55 = F_33 ( V_64 -> V_70 . V_76 , L_5 ,
& V_67 ) ;
if ( V_55 )
V_67 = 100000 ;
V_69 = F_34 ( V_2 -> V_74 ) ;
if ( V_69 == 0 ) {
F_27 ( & V_64 -> V_70 , L_6 ) ;
V_55 = - V_77 ;
goto V_75;
}
V_69 = V_69 / V_67 ;
if ( V_67 <= 100000 )
V_68 = ( V_69 * V_78 ) / 100 ;
else if ( V_67 <= 400000 )
V_68 = ( V_69 * V_79 ) / 100 ;
else
V_68 = ( V_69 * V_80 ) / 100 ;
F_2 ( V_68 , V_2 -> V_4 + V_81 ) ;
F_2 ( V_69 - V_68 , V_2 -> V_4 + V_82 ) ;
F_35 ( V_64 , V_2 ) ;
F_36 ( & V_2 -> V_51 , V_2 ) ;
V_2 -> V_51 . V_83 = V_84 ;
F_37 ( V_2 -> V_51 . V_85 , L_7 , sizeof( V_2 -> V_51 . V_85 ) ) ;
V_2 -> V_51 . V_86 = & V_87 ;
V_2 -> V_51 . V_70 . V_88 = & V_64 -> V_70 ;
V_2 -> V_51 . V_70 . V_76 = V_64 -> V_70 . V_76 ;
V_55 = F_38 ( & V_2 -> V_51 ) ;
if ( V_55 < 0 ) {
F_27 ( & V_64 -> V_70 , L_8 ) ;
goto V_75;
}
F_39 ( & V_64 -> V_70 , L_9 ) ;
return 0 ;
V_75:
F_40 ( V_2 -> V_74 ) ;
return V_55 ;
}
static int F_41 ( struct V_63 * V_70 )
{
struct V_1 * V_2 = F_42 ( V_70 ) ;
F_43 ( & V_2 -> V_51 ) ;
F_40 ( V_2 -> V_74 ) ;
return 0 ;
}
static int F_44 ( struct V_89 * V_70 )
{
struct V_63 * V_64 = F_45 ( V_70 ) ;
struct V_1 * V_2 = F_42 ( V_64 ) ;
F_46 ( V_2 -> V_74 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_70 )
{
struct V_63 * V_64 = F_45 ( V_70 ) ;
struct V_1 * V_2 = F_42 ( V_64 ) ;
F_48 ( V_2 -> V_74 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
