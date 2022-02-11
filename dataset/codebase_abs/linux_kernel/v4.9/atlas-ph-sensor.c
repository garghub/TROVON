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
T_1 V_14 ;
V_6 = F_5 ( V_2 -> V_8 , V_15 , & V_14 , 2 ) ;
if ( V_6 )
return V_6 ;
V_7 = F_6 ( V_14 ) ;
F_7 ( V_4 , L_5 , V_7 / 100 , V_7 % 100 ) ;
V_6 = F_2 ( V_2 -> V_8 , V_16 , & V_7 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_7 & V_17 ) ) {
F_3 ( V_4 , L_1 ) ;
return 0 ;
}
if ( ! ( V_7 & V_18 ) )
F_3 ( V_4 , L_6 ) ;
if ( V_7 & V_19 ) {
F_3 ( V_4 , L_7 ) ;
} else {
if ( ! ( V_7 & V_20 ) )
F_3 ( V_4 , L_2 ) ;
if ( ! ( V_7 & V_21 ) )
F_3 ( V_4 , L_4 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_6 ;
unsigned int V_7 ;
V_6 = F_2 ( V_2 -> V_8 , V_22 , & V_7 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_7 )
F_3 ( V_4 , L_1 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_23 )
{
return F_10 ( V_2 -> V_8 , V_24 , V_23 ) ;
}
static int F_11 ( struct V_1 * V_2 , bool V_25 )
{
return F_12 ( V_2 -> V_8 , V_26 ,
V_27 ,
V_25 ? V_27 : 0 ) ;
}
static int F_13 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
int V_6 ;
V_6 = F_15 ( V_29 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_16 ( & V_2 -> V_5 -> V_4 ) ;
if ( V_6 < 0 ) {
F_17 ( & V_2 -> V_5 -> V_4 ) ;
return V_6 ;
}
return F_11 ( V_2 , true ) ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
int V_6 ;
V_6 = F_19 ( V_29 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_2 , false ) ;
if ( V_6 )
return V_6 ;
F_20 ( & V_2 -> V_5 -> V_4 ) ;
return F_21 ( & V_2 -> V_5 -> V_4 ) ;
}
static void F_22 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_23 ( V_31 , struct V_1 , V_31 ) ;
F_24 ( V_2 -> V_32 ) ;
}
static T_2 F_25 ( int V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_28 * V_29 = V_36 -> V_29 ;
struct V_1 * V_2 = F_14 ( V_29 ) ;
int V_6 ;
V_6 = F_5 ( V_2 -> V_8 , V_2 -> V_37 -> V_38 ,
( V_39 * ) & V_2 -> V_40 ,
sizeof( V_41 ) * ( V_2 -> V_37 -> V_42 - 2 ) ) ;
if ( ! V_6 )
F_26 ( V_29 , V_2 -> V_40 ,
F_27 ( V_29 ) ) ;
F_28 ( V_29 -> V_32 ) ;
return V_43 ;
}
static T_2 F_29 ( int V_33 , void * V_34 )
{
struct V_28 * V_29 = V_34 ;
struct V_1 * V_2 = F_14 ( V_29 ) ;
F_30 ( & V_2 -> V_31 ) ;
return V_43 ;
}
static int F_31 ( struct V_1 * V_2 , int V_44 , V_41 * V_7 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_45 = F_32 ( V_4 ) ;
int V_6 ;
V_6 = F_16 ( V_4 ) ;
if ( V_6 < 0 ) {
F_17 ( V_4 ) ;
return V_6 ;
}
if ( V_45 )
F_33 ( V_2 -> V_37 -> V_46 , V_2 -> V_37 -> V_46 + 100000 ) ;
V_6 = F_5 ( V_2 -> V_8 , V_44 , ( V_39 * ) V_7 , sizeof( * V_7 ) ) ;
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
return V_6 ;
}
static int F_34 ( struct V_28 * V_29 ,
struct V_47 const * V_48 ,
int * V_7 , int * V_49 , long V_50 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
switch ( V_50 ) {
case V_51 : {
int V_6 ;
V_41 V_44 ;
switch ( V_48 -> type ) {
case V_52 :
V_6 = F_5 ( V_2 -> V_8 , V_48 -> V_53 ,
( V_39 * ) & V_44 , sizeof( V_44 ) ) ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_6 = F_35 ( V_29 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_31 ( V_2 , V_48 -> V_53 , & V_44 ) ;
F_36 ( V_29 ) ;
break;
default:
V_6 = - V_58 ;
}
if ( ! V_6 ) {
* V_7 = F_37 ( V_44 ) ;
V_6 = V_59 ;
}
return V_6 ;
}
case V_60 :
switch ( V_48 -> type ) {
case V_52 :
* V_7 = 1 ;
* V_49 = 100 ;
break;
case V_54 :
* V_7 = 1 ;
* V_49 = 1000 ;
break;
case V_56 :
* V_7 = 1 ;
* V_49 = 100000 ;
break;
case V_55 :
* V_7 = 0 ;
* V_49 = 1000 ;
return V_61 ;
case V_57 :
* V_7 = 1 ;
* V_49 = 10 ;
break;
default:
return - V_58 ;
}
return V_62 ;
}
return - V_58 ;
}
static int F_38 ( struct V_28 * V_29 ,
struct V_47 const * V_48 ,
int V_7 , int V_49 , long V_50 )
{
struct V_1 * V_2 = F_14 ( V_29 ) ;
V_41 V_44 = F_39 ( V_7 ) ;
if ( V_49 != 0 || V_7 < 0 || V_7 > 20000 )
return - V_58 ;
if ( V_50 != V_51 || V_48 -> type != V_52 )
return - V_58 ;
return F_40 ( V_2 -> V_8 , V_48 -> V_53 ,
& V_44 , sizeof( V_44 ) ) ;
}
static int F_41 ( struct V_63 * V_5 ,
const struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_66 * V_37 ;
const struct V_67 * V_68 ;
struct V_69 * V_32 ;
struct V_28 * V_29 ;
int V_6 ;
V_29 = F_42 ( & V_5 -> V_4 , sizeof( * V_2 ) ) ;
if ( ! V_29 )
return - V_70 ;
V_68 = F_43 ( V_71 , & V_5 -> V_4 ) ;
if ( ! V_68 )
V_37 = & V_72 [ V_65 -> V_73 ] ;
else
V_37 = & V_72 [ ( unsigned long ) V_68 -> V_2 ] ;
V_29 -> V_74 = & V_75 ;
V_29 -> V_76 = V_77 ;
V_29 -> V_78 = V_37 -> V_78 ;
V_29 -> V_42 = V_37 -> V_42 ;
V_29 -> V_79 = V_80 | V_81 ;
V_29 -> V_4 . V_82 = & V_5 -> V_4 ;
V_32 = F_44 ( & V_5 -> V_4 , L_8 ,
V_29 -> V_76 , V_29 -> V_65 ) ;
if ( ! V_32 )
return - V_70 ;
V_2 = F_14 ( V_29 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_37 = V_37 ;
V_32 -> V_4 . V_82 = V_29 -> V_4 . V_82 ;
V_32 -> V_83 = & V_84 ;
F_45 ( V_32 , V_29 ) ;
F_46 ( V_5 , V_29 ) ;
V_2 -> V_8 = F_47 ( V_5 , & V_85 ) ;
if ( F_48 ( V_2 -> V_8 ) ) {
F_49 ( & V_5 -> V_4 , L_9 ) ;
return F_50 ( V_2 -> V_8 ) ;
}
V_6 = F_51 ( & V_5 -> V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_5 -> V_33 <= 0 ) {
F_49 ( & V_5 -> V_4 , L_10 ) ;
return - V_58 ;
}
V_6 = V_37 -> V_86 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_52 ( V_32 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_11 ) ;
return V_6 ;
}
V_6 = F_53 ( V_29 , & V_87 ,
& F_25 , & V_88 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_12 ) ;
goto V_89;
}
F_54 ( & V_2 -> V_31 , F_22 ) ;
V_6 = F_55 ( & V_5 -> V_4 , V_5 -> V_33 ,
NULL , F_29 ,
V_90 |
V_91 | V_92 ,
L_13 ,
V_29 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_14 , V_5 -> V_33 ) ;
goto V_93;
}
V_6 = F_9 ( V_2 , 1 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_15 ) ;
goto V_93;
}
F_56 ( & V_5 -> V_4 ) ;
F_57 ( & V_5 -> V_4 , 2500 ) ;
F_58 ( & V_5 -> V_4 ) ;
V_6 = F_59 ( V_29 ) ;
if ( V_6 ) {
F_49 ( & V_5 -> V_4 , L_16 ) ;
goto V_94;
}
return 0 ;
V_94:
F_60 ( & V_5 -> V_4 ) ;
F_9 ( V_2 , 0 ) ;
V_93:
F_61 ( V_29 ) ;
V_89:
F_62 ( V_2 -> V_32 ) ;
return V_6 ;
}
static int F_63 ( struct V_63 * V_5 )
{
struct V_28 * V_29 = F_64 ( V_5 ) ;
struct V_1 * V_2 = F_14 ( V_29 ) ;
F_65 ( V_29 ) ;
F_61 ( V_29 ) ;
F_62 ( V_2 -> V_32 ) ;
F_60 ( & V_5 -> V_4 ) ;
F_66 ( & V_5 -> V_4 ) ;
F_17 ( & V_5 -> V_4 ) ;
return F_9 ( V_2 , 0 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
F_14 ( F_64 ( F_68 ( V_4 ) ) ) ;
return F_9 ( V_2 , 0 ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
F_14 ( F_64 ( F_68 ( V_4 ) ) ) ;
return F_9 ( V_2 , 1 ) ;
}
