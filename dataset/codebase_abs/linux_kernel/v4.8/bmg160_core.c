static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_3 ( V_2 -> V_6 , V_8 , V_3 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static int F_5 ( int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_11 ) ; ++ V_10 ) {
if ( V_11 [ V_10 ] . V_12 == V_9 )
return V_11 [ V_10 ] . V_13 ;
}
return - V_14 ;
}
static int F_7 ( struct V_1 * V_2 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_13 ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_7 = F_3 ( V_2 -> V_6 , V_15 , V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_10 ;
unsigned int V_13 ;
V_7 = F_9 ( V_2 -> V_6 , V_15 , & V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_3 ) ;
return V_7 ;
}
V_13 &= ~ V_16 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_11 ) ; ++ V_10 ) {
if ( V_11 [ V_10 ] . V_13 == V_13 )
break;
}
* V_9 = V_11 [ V_10 ] . V_17 ;
return V_7 ? V_7 : V_18 ;
}
static int F_10 ( struct V_1 * V_2 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_11 ) ; ++ V_10 ) {
if ( V_11 [ V_10 ] . V_17 == V_9 )
break;
}
V_7 = F_3 ( V_2 -> V_6 , V_15 ,
V_11 [ V_10 ] . V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
unsigned int V_9 ;
V_7 = F_9 ( V_2 -> V_6 , V_19 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_4 ) ;
return V_7 ;
}
F_12 ( V_5 , L_5 , V_9 ) ;
if ( V_9 != V_20 ) {
F_4 ( V_5 , L_6 , V_9 ) ;
return - V_21 ;
}
V_7 = F_1 ( V_2 , V_22 ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( 500 , 1000 ) ;
V_7 = F_7 ( V_2 , V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_2 -> V_6 , V_24 , V_25 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_7 ) ;
return V_7 ;
}
V_2 -> V_26 = V_25 ;
V_7 = F_9 ( V_2 -> V_6 , V_27 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_8 ) ;
return V_7 ;
}
V_2 -> V_28 = V_9 ;
V_7 = F_14 ( V_2 -> V_6 , V_29 ,
V_30 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_9 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_31 ,
V_32 |
V_33 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 ,
L_10 ) ;
return V_7 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , bool V_34 )
{
#ifdef F_16
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
if ( V_34 )
V_7 = F_17 ( V_5 ) ;
else {
F_18 ( V_5 ) ;
V_7 = F_19 ( V_5 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_11 , V_34 ) ;
if ( V_34 )
F_20 ( V_5 ) ;
return V_7 ;
}
#endif
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
bool V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_14 ( V_2 -> V_6 , V_36 ,
V_37 ,
( V_35 ? V_37 : 0 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_12 ) ;
return V_7 ;
}
if ( V_35 ) {
V_7 = F_3 ( V_2 -> V_6 , V_27 ,
V_2 -> V_28 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_13 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_38 ,
V_39 | V_40 |
V_41 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_10 ) ;
return V_7 ;
}
if ( ! V_2 -> V_42 ) {
V_7 = F_3 ( V_2 -> V_6 ,
V_31 ,
V_32 |
V_33 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
}
V_7 = F_3 ( V_2 -> V_6 , V_43 ,
V_44 ) ;
} else {
V_7 = F_3 ( V_2 -> V_6 , V_43 , 0 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_15 ) ;
return V_7 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
bool V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_14 ( V_2 -> V_6 , V_45 ,
V_46 ,
( V_35 ? V_46 : 0 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_16 ) ;
return V_7 ;
}
if ( V_35 ) {
V_7 = F_3 ( V_2 -> V_6 , V_31 ,
V_47 |
V_33 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_43 ,
V_44 ) ;
} else {
V_7 = F_3 ( V_2 -> V_6 , V_31 ,
V_32 |
V_33 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_43 , 0 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_15 ) ;
return V_7 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 ;
unsigned int V_13 ;
int V_7 ;
V_7 = F_9 ( V_2 -> V_6 , V_15 , & V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_3 ) ;
return V_7 ;
}
V_13 &= ~ V_16 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_11 ) ; ++ V_10 ) {
if ( V_11 [ V_10 ] . V_13 == V_13 ) {
* V_9 = V_11 [ V_10 ] . V_12 ;
return V_18 ;
}
}
return - V_14 ;
}
static int F_24 ( struct V_1 * V_2 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 , V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_48 ) ; ++ V_10 ) {
if ( V_48 [ V_10 ] . V_49 == V_9 ) {
V_7 = F_3 ( V_2 -> V_6 , V_24 ,
V_48 [ V_10 ] . V_26 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_7 ) ;
return V_7 ;
}
V_2 -> V_26 = V_48 [ V_10 ] . V_26 ;
return 0 ;
}
}
return - V_14 ;
}
static int F_25 ( struct V_1 * V_2 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
unsigned int V_50 ;
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_9 ( V_2 -> V_6 , V_52 , & V_50 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_17 ) ;
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
* V_9 = F_28 ( V_50 , 7 ) ;
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_18 ;
}
static int F_29 ( struct V_1 * V_2 , int V_53 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
T_2 V_50 ;
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_30 ( V_2 -> V_6 , F_31 ( V_53 ) , & V_50 ,
sizeof( V_50 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_18 , V_53 ) ;
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
* V_9 = F_28 ( F_32 ( V_50 ) , 15 ) ;
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_18 ;
}
static int F_33 ( struct V_54 * V_55 ,
struct V_56 const * V_57 ,
int * V_9 , int * V_58 , long V_59 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
switch ( V_59 ) {
case V_60 :
switch ( V_57 -> type ) {
case V_61 :
return F_25 ( V_2 , V_9 ) ;
case V_62 :
if ( F_35 ( V_55 ) )
return - V_63 ;
else
return F_29 ( V_2 , V_57 -> V_64 ,
V_9 ) ;
default:
return - V_14 ;
}
case V_65 :
if ( V_57 -> type == V_61 ) {
* V_9 = V_66 ;
return V_18 ;
} else
return - V_14 ;
case V_67 :
return F_8 ( V_2 , V_9 ) ;
case V_68 :
* V_9 = 0 ;
switch ( V_57 -> type ) {
case V_61 :
* V_58 = 500000 ;
return V_69 ;
case V_62 :
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_48 ) ; ++ V_10 ) {
if ( V_48 [ V_10 ] . V_26 ==
V_2 -> V_26 ) {
* V_58 = V_48 [ V_10 ] . V_49 ;
return V_69 ;
}
}
return - V_14 ;
}
default:
return - V_14 ;
}
case V_70 :
* V_58 = 0 ;
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_23 ( V_2 , V_9 ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
default:
return - V_14 ;
}
}
static int F_36 ( struct V_54 * V_55 ,
struct V_56 const * V_57 ,
int V_9 , int V_58 , long V_59 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
switch ( V_59 ) {
case V_70 :
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_7 ( V_2 , V_9 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
case V_67 :
if ( V_58 )
return - V_14 ;
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_10 ( V_2 , V_9 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
case V_68 :
if ( V_9 )
return - V_14 ;
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_24 ( V_2 , V_58 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
default:
return - V_14 ;
}
return - V_14 ;
}
static int F_37 ( struct V_54 * V_55 ,
const struct V_56 * V_57 ,
enum V_71 type ,
enum V_72 V_73 ,
enum V_74 V_75 ,
int * V_9 , int * V_58 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
* V_58 = 0 ;
switch ( V_75 ) {
case V_76 :
* V_9 = V_2 -> V_28 & V_77 ;
break;
default:
return - V_14 ;
}
return V_18 ;
}
static int F_38 ( struct V_54 * V_55 ,
const struct V_56 * V_57 ,
enum V_71 type ,
enum V_72 V_73 ,
enum V_74 V_75 ,
int V_9 , int V_58 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
switch ( V_75 ) {
case V_76 :
if ( V_2 -> V_78 )
return - V_63 ;
V_2 -> V_28 &= ~ V_77 ;
V_2 -> V_28 |= ( V_9 & V_77 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_39 ( struct V_54 * V_55 ,
const struct V_56 * V_57 ,
enum V_71 type ,
enum V_72 V_73 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
return V_2 -> V_78 ;
}
static int F_40 ( struct V_54 * V_55 ,
const struct V_56 * V_57 ,
enum V_71 type ,
enum V_72 V_73 ,
int V_79 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
if ( V_79 && V_2 -> V_78 )
return 0 ;
F_26 ( & V_2 -> V_51 ) ;
if ( ! V_79 && V_2 -> V_80 ) {
V_2 -> V_78 = 0 ;
F_27 ( & V_2 -> V_51 ) ;
return 0 ;
}
V_7 = F_15 ( V_2 , V_79 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_7 = F_21 ( V_2 , V_79 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
V_2 -> V_78 = V_79 ;
F_27 ( & V_2 -> V_51 ) ;
return 0 ;
}
static T_3 F_41 ( int V_81 , void * V_82 )
{
struct V_83 * V_84 = V_82 ;
struct V_54 * V_55 = V_84 -> V_55 ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
F_26 ( & V_2 -> V_51 ) ;
V_7 = F_30 ( V_2 -> V_6 , V_85 ,
V_2 -> V_86 , V_87 * 2 ) ;
F_27 ( & V_2 -> V_51 ) ;
if ( V_7 < 0 )
goto V_88;
F_42 ( V_55 , V_2 -> V_86 ,
V_84 -> V_89 ) ;
V_88:
F_43 ( V_55 -> V_90 ) ;
return V_91 ;
}
static int F_44 ( struct V_92 * V_90 )
{
struct V_54 * V_55 = F_45 ( V_90 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
if ( V_2 -> V_42 )
return 0 ;
V_7 = F_3 ( V_2 -> V_6 , V_31 ,
V_32 |
V_33 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
return 0 ;
}
static int F_46 ( struct V_92 * V_90 ,
bool V_79 )
{
struct V_54 * V_55 = F_45 ( V_90 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
F_26 ( & V_2 -> V_51 ) ;
if ( ! V_79 && V_2 -> V_78 && V_2 -> V_80 ) {
V_2 -> V_80 = false ;
F_27 ( & V_2 -> V_51 ) ;
return 0 ;
}
V_7 = F_15 ( V_2 , V_79 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
if ( V_2 -> V_93 == V_90 )
V_7 = F_21 ( V_2 , V_79 ) ;
else
V_7 = F_22 ( V_2 , V_79 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_51 ) ;
return V_7 ;
}
if ( V_2 -> V_93 == V_90 )
V_2 -> V_80 = V_79 ;
else
V_2 -> V_42 = V_79 ;
F_27 ( & V_2 -> V_51 ) ;
return 0 ;
}
static T_3 F_47 ( int V_81 , void * V_94 )
{
struct V_54 * V_55 = V_94 ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_73 ;
unsigned int V_9 ;
V_7 = F_9 ( V_2 -> V_6 , V_95 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_19 ) ;
goto V_96;
}
if ( V_9 & 0x08 )
V_73 = V_97 ;
else
V_73 = V_98 ;
if ( V_9 & V_99 )
F_48 ( V_55 , F_49 ( V_62 ,
0 ,
V_100 ,
V_101 ,
V_73 ) ,
F_50 ( V_55 ) ) ;
if ( V_9 & V_102 )
F_48 ( V_55 , F_49 ( V_62 ,
0 ,
V_103 ,
V_101 ,
V_73 ) ,
F_50 ( V_55 ) ) ;
if ( V_9 & V_104 )
F_48 ( V_55 , F_49 ( V_62 ,
0 ,
V_105 ,
V_101 ,
V_73 ) ,
F_50 ( V_55 ) ) ;
V_96:
if ( ! V_2 -> V_42 ) {
V_7 = F_3 ( V_2 -> V_6 , V_31 ,
V_32 |
V_33 ) ;
if ( V_7 < 0 )
F_4 ( V_5 , L_14 ) ;
}
return V_91 ;
}
static T_3 F_51 ( int V_81 , void * V_94 )
{
struct V_54 * V_55 = V_94 ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
if ( V_2 -> V_42 )
F_52 ( V_2 -> V_106 ) ;
else if ( V_2 -> V_80 )
F_52 ( V_2 -> V_93 ) ;
if ( V_2 -> V_78 )
return V_107 ;
else
return V_91 ;
}
static int F_53 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
return F_15 ( V_2 , true ) ;
}
static int F_54 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_34 ( V_55 ) ;
return F_15 ( V_2 , false ) ;
}
static const char * F_55 ( struct V_4 * V_5 )
{
const struct V_108 * V_109 ;
V_109 = F_56 ( V_5 -> V_110 -> V_111 , V_5 ) ;
if ( ! V_109 )
return NULL ;
return F_57 ( V_5 ) ;
}
int F_58 ( struct V_4 * V_5 , struct V_6 * V_6 , int V_81 ,
const char * V_112 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
int V_7 ;
V_55 = F_59 ( V_5 , sizeof( * V_2 ) ) ;
if ( ! V_55 )
return - V_113 ;
V_2 = F_34 ( V_55 ) ;
F_60 ( V_5 , V_55 ) ;
V_2 -> V_81 = V_81 ;
V_2 -> V_6 = V_6 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_61 ( & V_2 -> V_51 ) ;
if ( F_62 ( V_5 ) )
V_112 = F_55 ( V_5 ) ;
V_55 -> V_5 . V_114 = V_5 ;
V_55 -> V_115 = V_116 ;
V_55 -> V_117 = F_6 ( V_116 ) ;
V_55 -> V_112 = V_112 ;
V_55 -> V_118 = V_119 ;
V_55 -> V_120 = V_121 ;
V_55 -> V_75 = & V_122 ;
if ( V_2 -> V_81 > 0 ) {
V_7 = F_63 ( V_5 ,
V_2 -> V_81 ,
F_51 ,
F_47 ,
V_123 ,
V_124 ,
V_55 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_106 = F_64 ( V_5 ,
L_20 ,
V_55 -> V_112 ,
V_55 -> V_109 ) ;
if ( ! V_2 -> V_106 )
return - V_113 ;
V_2 -> V_93 = F_64 ( V_5 ,
L_21 ,
V_55 -> V_112 ,
V_55 -> V_109 ) ;
if ( ! V_2 -> V_93 )
return - V_113 ;
V_2 -> V_106 -> V_5 . V_114 = V_5 ;
V_2 -> V_106 -> V_125 = & V_126 ;
F_65 ( V_2 -> V_106 , V_55 ) ;
V_7 = F_66 ( V_2 -> V_106 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_93 -> V_5 . V_114 = V_5 ;
V_2 -> V_93 -> V_125 = & V_126 ;
F_65 ( V_2 -> V_93 , V_55 ) ;
V_7 = F_66 ( V_2 -> V_93 ) ;
if ( V_7 ) {
V_2 -> V_93 = NULL ;
goto V_127;
}
}
V_7 = F_67 ( V_55 ,
V_128 ,
F_41 ,
& V_129 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 ,
L_22 ) ;
goto V_127;
}
V_7 = F_68 ( V_5 ) ;
if ( V_7 )
goto V_130;
F_69 ( V_5 ) ;
F_70 ( V_5 ,
V_131 ) ;
F_71 ( V_5 ) ;
V_7 = F_72 ( V_55 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_23 ) ;
goto V_130;
}
return 0 ;
V_130:
F_73 ( V_55 ) ;
V_127:
if ( V_2 -> V_106 )
F_74 ( V_2 -> V_106 ) ;
if ( V_2 -> V_93 )
F_74 ( V_2 -> V_93 ) ;
return V_7 ;
}
void F_75 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
F_77 ( V_55 ) ;
F_78 ( V_5 ) ;
F_79 ( V_5 ) ;
F_20 ( V_5 ) ;
F_73 ( V_55 ) ;
if ( V_2 -> V_106 ) {
F_74 ( V_2 -> V_106 ) ;
F_74 ( V_2 -> V_93 ) ;
}
F_26 ( & V_2 -> V_51 ) ;
F_1 ( V_2 , V_132 ) ;
F_27 ( & V_2 -> V_51 ) ;
}
static int F_80 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
F_26 ( & V_2 -> V_51 ) ;
F_1 ( V_2 , V_133 ) ;
F_27 ( & V_2 -> V_51 ) ;
return 0 ;
}
static int F_81 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
F_26 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_42 || V_2 -> V_80 ||
V_2 -> V_78 )
F_1 ( V_2 , V_22 ) ;
F_27 ( & V_2 -> V_51 ) ;
return 0 ;
}
static int F_82 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_133 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_24 ) ;
return - V_134 ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_55 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_22 ) ;
if ( V_7 < 0 )
return V_7 ;
F_84 ( V_135 ) ;
return 0 ;
}
