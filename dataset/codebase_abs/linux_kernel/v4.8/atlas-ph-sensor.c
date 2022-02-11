static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_6 ;
unsigned int V_7 ;
V_6 = F_2 ( V_2 -> V_8 , V_9 , & V_7 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_7 & V_10 ) ) {
F_3 ( V_4 , L_1 ) ;
return 0 ;
}
if ( ! ( V_7 & V_11 ) )
F_3 ( V_4 , L_2 ) ;
if ( ! ( V_7 & V_12 ) )
F_3 ( V_4 , L_3 ) ;
if ( ! ( V_7 & V_13 ) )
F_3 ( V_4 , L_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_6 ;
unsigned int V_7 ;
V_6 = F_5 ( V_2 -> V_8 , V_14 , & V_7 , 2 ) ;
if ( V_6 )
return V_6 ;
F_6 ( V_4 , L_5 , F_7 ( V_7 ) / 100 ,
F_7 ( V_7 ) % 100 ) ;
V_6 = F_2 ( V_2 -> V_8 , V_15 , & V_7 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_7 & V_16 ) ) {
F_3 ( V_4 , L_1 ) ;
return 0 ;
}
if ( ! ( V_7 & V_17 ) )
F_3 ( V_4 , L_6 ) ;
if ( V_7 & V_18 ) {
F_3 ( V_4 , L_7 ) ;
} else {
if ( ! ( V_7 & V_19 ) )
F_3 ( V_4 , L_2 ) ;
if ( ! ( V_7 & V_20 ) )
F_3 ( V_4 , L_4 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_21 )
{
return F_9 ( V_2 -> V_8 , V_22 , V_21 ) ;
}
static int F_10 ( struct V_1 * V_2 , bool V_23 )
{
return F_11 ( V_2 -> V_8 , V_24 ,
V_25 ,
V_23 ? V_25 : 0 ) ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_6 ;
V_6 = F_14 ( V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_2 -> V_5 -> V_4 ) ;
if ( V_6 < 0 ) {
F_16 ( & V_2 -> V_5 -> V_4 ) ;
return V_6 ;
}
return F_10 ( V_2 , true ) ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_6 ;
V_6 = F_18 ( V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( V_2 , false ) ;
if ( V_6 )
return V_6 ;
F_19 ( & V_2 -> V_5 -> V_4 ) ;
return F_20 ( & V_2 -> V_5 -> V_4 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_22 ( V_29 , struct V_1 , V_29 ) ;
F_23 ( V_2 -> V_30 ) ;
}
static T_1 F_24 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_26 * V_27 = V_34 -> V_27 ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_6 ;
V_6 = F_5 ( V_2 -> V_8 , V_2 -> V_35 -> V_36 ,
( V_37 * ) & V_2 -> V_38 ,
sizeof( V_39 ) * ( V_2 -> V_35 -> V_40 - 2 ) ) ;
if ( ! V_6 )
F_25 ( V_27 , V_2 -> V_38 ,
F_26 ( V_27 ) ) ;
F_27 ( V_27 -> V_30 ) ;
return V_41 ;
}
static T_1 F_28 ( int V_31 , void * V_32 )
{
struct V_26 * V_27 = V_32 ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_29 ( & V_2 -> V_29 ) ;
return V_41 ;
}
static int F_30 ( struct V_1 * V_2 , int V_42 , V_39 * V_7 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_43 = F_31 ( V_4 ) ;
int V_6 ;
V_6 = F_15 ( V_4 ) ;
if ( V_6 < 0 ) {
F_16 ( V_4 ) ;
return V_6 ;
}
if ( V_43 )
F_32 ( V_2 -> V_35 -> V_44 , V_2 -> V_35 -> V_44 + 100000 ) ;
V_6 = F_5 ( V_2 -> V_8 , V_42 , ( V_37 * ) V_7 , sizeof( * V_7 ) ) ;
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
return V_6 ;
}
static int F_33 ( struct V_26 * V_27 ,
struct V_45 const * V_46 ,
int * V_7 , int * V_47 , long V_48 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
switch ( V_48 ) {
case V_49 : {
int V_6 ;
V_39 V_42 ;
switch ( V_46 -> type ) {
case V_50 :
V_6 = F_5 ( V_2 -> V_8 , V_46 -> V_51 ,
( V_37 * ) & V_42 , sizeof( V_42 ) ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_34 ( & V_27 -> V_55 ) ;
if ( F_35 ( V_27 ) )
V_6 = - V_56 ;
else
V_6 = F_30 ( V_2 ,
V_46 -> V_51 , & V_42 ) ;
F_36 ( & V_27 -> V_55 ) ;
break;
default:
V_6 = - V_57 ;
}
if ( ! V_6 ) {
* V_7 = F_37 ( V_42 ) ;
V_6 = V_58 ;
}
return V_6 ;
}
case V_59 :
switch ( V_46 -> type ) {
case V_50 :
* V_7 = 1 ;
* V_47 = 100 ;
break;
case V_52 :
* V_7 = 1 ;
* V_47 = 1000 ;
break;
case V_54 :
* V_7 = 1 ;
* V_47 = 100000 ;
break;
case V_53 :
* V_7 = 0 ;
* V_47 = 1000 ;
return V_60 ;
default:
return - V_57 ;
}
return V_61 ;
}
return - V_57 ;
}
static int F_38 ( struct V_26 * V_27 ,
struct V_45 const * V_46 ,
int V_7 , int V_47 , long V_48 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
V_39 V_42 = F_39 ( V_7 ) ;
if ( V_47 != 0 || V_7 < 0 || V_7 > 20000 )
return - V_57 ;
if ( V_48 != V_49 || V_46 -> type != V_50 )
return - V_57 ;
return F_40 ( V_2 -> V_8 , V_46 -> V_51 ,
& V_42 , sizeof( V_42 ) ) ;
}
static int F_41 ( struct V_62 * V_5 ,
const struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 * V_35 ;
const struct V_66 * V_67 ;
struct V_68 * V_30 ;
struct V_26 * V_27 ;
int V_6 ;
V_27 = F_42 ( & V_5 -> V_4 , sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_69 ;
V_67 = F_43 ( V_70 , & V_5 -> V_4 ) ;
if ( ! V_67 )
V_35 = & V_71 [ V_64 -> V_72 ] ;
else
V_35 = & V_71 [ ( unsigned long ) V_67 -> V_2 ] ;
V_27 -> V_73 = & V_74 ;
V_27 -> V_75 = V_76 ;
V_27 -> V_77 = V_35 -> V_77 ;
V_27 -> V_40 = V_35 -> V_40 ;
V_27 -> V_78 = V_79 | V_80 ;
V_27 -> V_4 . V_81 = & V_5 -> V_4 ;
V_30 = F_44 ( & V_5 -> V_4 , L_8 ,
V_27 -> V_75 , V_27 -> V_64 ) ;
if ( ! V_30 )
return - V_69 ;
V_2 = F_13 ( V_27 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_35 = V_35 ;
V_30 -> V_4 . V_81 = V_27 -> V_4 . V_81 ;
V_30 -> V_82 = & V_83 ;
F_45 ( V_30 , V_27 ) ;
F_46 ( V_5 , V_27 ) ;
V_2 -> V_8 = F_47 ( V_5 , & V_84 ) ;
if ( F_48 ( V_2 -> V_8 ) ) {
F_49 ( & V_5 -> V_4 , L_9 ) ;
return F_50 ( V_2 -> V_8 ) ;
}
V_6 = F_51 ( & V_5 -> V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_5 -> V_31 <= 0 ) {
F_49 ( & V_5 -> V_4 , L_10 ) ;
return - V_57 ;
}
V_6 = V_35 -> V_85 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_52 ( V_30 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_11 ) ;
return V_6 ;
}
V_6 = F_53 ( V_27 , & V_86 ,
& F_24 , & V_87 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_12 ) ;
goto V_88;
}
F_54 ( & V_2 -> V_29 , F_21 ) ;
V_6 = F_55 ( & V_5 -> V_4 , V_5 -> V_31 ,
NULL , F_28 ,
V_89 |
V_90 | V_91 ,
L_13 ,
V_27 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_14 , V_5 -> V_31 ) ;
goto V_92;
}
V_6 = F_8 ( V_2 , 1 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_15 ) ;
goto V_92;
}
F_56 ( & V_5 -> V_4 ) ;
F_57 ( & V_5 -> V_4 , 2500 ) ;
F_58 ( & V_5 -> V_4 ) ;
V_6 = F_59 ( V_27 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_16 ) ;
goto V_93;
}
return 0 ;
V_93:
F_60 ( & V_5 -> V_4 ) ;
F_8 ( V_2 , 0 ) ;
V_92:
F_61 ( V_27 ) ;
V_88:
F_62 ( V_2 -> V_30 ) ;
return V_6 ;
}
static int F_63 ( struct V_62 * V_5 )
{
struct V_26 * V_27 = F_64 ( V_5 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_65 ( V_27 ) ;
F_61 ( V_27 ) ;
F_62 ( V_2 -> V_30 ) ;
F_60 ( & V_5 -> V_4 ) ;
F_66 ( & V_5 -> V_4 ) ;
F_16 ( & V_5 -> V_4 ) ;
return F_8 ( V_2 , 0 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
F_13 ( F_64 ( F_68 ( V_4 ) ) ) ;
return F_8 ( V_2 , 0 ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
F_13 ( F_64 ( F_68 ( V_4 ) ) ) ;
return F_8 ( V_2 , 1 ) ;
}
