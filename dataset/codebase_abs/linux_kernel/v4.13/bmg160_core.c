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
F_3 ( V_2 -> V_6 , V_19 ,
V_20 ) ;
F_12 ( 30000 , 30700 ) ;
V_7 = F_9 ( V_2 -> V_6 , V_21 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_4 ) ;
return V_7 ;
}
F_13 ( V_5 , L_5 , V_9 ) ;
if ( V_9 != V_22 ) {
F_4 ( V_5 , L_6 , V_9 ) ;
return - V_23 ;
}
V_7 = F_1 ( V_2 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
F_12 ( 500 , 1000 ) ;
V_7 = F_7 ( V_2 , V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_2 -> V_6 , V_26 , V_27 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_7 ) ;
return V_7 ;
}
V_2 -> V_28 = V_27 ;
V_7 = F_9 ( V_2 -> V_6 , V_29 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_8 ) ;
return V_7 ;
}
V_2 -> V_30 = V_9 ;
V_7 = F_14 ( V_2 -> V_6 , V_31 ,
V_32 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_9 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_33 ,
V_34 |
V_35 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 ,
L_10 ) ;
return V_7 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , bool V_36 )
{
#ifdef F_16
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
if ( V_36 )
V_7 = F_17 ( V_5 ) ;
else {
F_18 ( V_5 ) ;
V_7 = F_19 ( V_5 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_11 , V_36 ) ;
if ( V_36 )
F_20 ( V_5 ) ;
return V_7 ;
}
#endif
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
bool V_37 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_14 ( V_2 -> V_6 , V_38 ,
V_39 ,
( V_37 ? V_39 : 0 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_12 ) ;
return V_7 ;
}
if ( V_37 ) {
V_7 = F_3 ( V_2 -> V_6 , V_29 ,
V_2 -> V_30 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_13 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_40 ,
V_41 | V_42 |
V_43 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_10 ) ;
return V_7 ;
}
if ( ! V_2 -> V_44 ) {
V_7 = F_3 ( V_2 -> V_6 ,
V_33 ,
V_34 |
V_35 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
}
V_7 = F_3 ( V_2 -> V_6 , V_45 ,
V_46 ) ;
} else {
V_7 = F_3 ( V_2 -> V_6 , V_45 , 0 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_15 ) ;
return V_7 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
bool V_37 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_14 ( V_2 -> V_6 , V_47 ,
V_48 ,
( V_37 ? V_48 : 0 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_16 ) ;
return V_7 ;
}
if ( V_37 ) {
V_7 = F_3 ( V_2 -> V_6 , V_33 ,
V_49 |
V_35 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_45 ,
V_46 ) ;
} else {
V_7 = F_3 ( V_2 -> V_6 , V_33 ,
V_34 |
V_35 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_45 , 0 ) ;
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
for ( V_10 = 0 ; V_10 < F_6 ( V_50 ) ; ++ V_10 ) {
if ( V_50 [ V_10 ] . V_51 == V_9 ) {
V_7 = F_3 ( V_2 -> V_6 , V_26 ,
V_50 [ V_10 ] . V_28 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_7 ) ;
return V_7 ;
}
V_2 -> V_28 = V_50 [ V_10 ] . V_28 ;
return 0 ;
}
}
return - V_14 ;
}
static int F_25 ( struct V_1 * V_2 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
unsigned int V_52 ;
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_9 ( V_2 -> V_6 , V_54 , & V_52 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_17 ) ;
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
* V_9 = F_28 ( V_52 , 7 ) ;
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_18 ;
}
static int F_29 ( struct V_1 * V_2 , int V_55 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
T_2 V_52 ;
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_30 ( V_2 -> V_6 , F_31 ( V_55 ) , & V_52 ,
sizeof( V_52 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_18 , V_55 ) ;
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
* V_9 = F_28 ( F_32 ( V_52 ) , 15 ) ;
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_18 ;
}
static int F_33 ( struct V_56 * V_57 ,
struct V_58 const * V_59 ,
int * V_9 , int * V_60 , long V_61 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
switch ( V_61 ) {
case V_62 :
switch ( V_59 -> type ) {
case V_63 :
return F_25 ( V_2 , V_9 ) ;
case V_64 :
if ( F_35 ( V_57 ) )
return - V_65 ;
else
return F_29 ( V_2 , V_59 -> V_66 ,
V_9 ) ;
default:
return - V_14 ;
}
case V_67 :
if ( V_59 -> type == V_63 ) {
* V_9 = V_68 ;
return V_18 ;
} else
return - V_14 ;
case V_69 :
return F_8 ( V_2 , V_9 ) ;
case V_70 :
* V_9 = 0 ;
switch ( V_59 -> type ) {
case V_63 :
* V_60 = 500000 ;
return V_71 ;
case V_64 :
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_50 ) ; ++ V_10 ) {
if ( V_50 [ V_10 ] . V_28 ==
V_2 -> V_28 ) {
* V_60 = V_50 [ V_10 ] . V_51 ;
return V_71 ;
}
}
return - V_14 ;
}
default:
return - V_14 ;
}
case V_72 :
* V_60 = 0 ;
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_23 ( V_2 , V_9 ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
default:
return - V_14 ;
}
}
static int F_36 ( struct V_56 * V_57 ,
struct V_58 const * V_59 ,
int V_9 , int V_60 , long V_61 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
switch ( V_61 ) {
case V_72 :
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_7 ( V_2 , V_9 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
case V_69 :
if ( V_60 )
return - V_14 ;
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_10 ( V_2 , V_9 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
case V_70 :
if ( V_9 )
return - V_14 ;
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_15 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_24 ( V_2 , V_60 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
default:
return - V_14 ;
}
return - V_14 ;
}
static int F_37 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_73 type ,
enum V_74 V_75 ,
enum V_76 V_77 ,
int * V_9 , int * V_60 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
* V_60 = 0 ;
switch ( V_77 ) {
case V_78 :
* V_9 = V_2 -> V_30 & V_79 ;
break;
default:
return - V_14 ;
}
return V_18 ;
}
static int F_38 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_73 type ,
enum V_74 V_75 ,
enum V_76 V_77 ,
int V_9 , int V_60 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
switch ( V_77 ) {
case V_78 :
if ( V_2 -> V_80 )
return - V_65 ;
V_2 -> V_30 &= ~ V_79 ;
V_2 -> V_30 |= ( V_9 & V_79 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_39 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_73 type ,
enum V_74 V_75 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
return V_2 -> V_80 ;
}
static int F_40 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_73 type ,
enum V_74 V_75 ,
int V_81 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
if ( V_81 && V_2 -> V_80 )
return 0 ;
F_26 ( & V_2 -> V_53 ) ;
if ( ! V_81 && V_2 -> V_82 ) {
V_2 -> V_80 = 0 ;
F_27 ( & V_2 -> V_53 ) ;
return 0 ;
}
V_7 = F_15 ( V_2 , V_81 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_7 = F_21 ( V_2 , V_81 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
V_2 -> V_80 = V_81 ;
F_27 ( & V_2 -> V_53 ) ;
return 0 ;
}
static T_3 F_41 ( int V_83 , void * V_84 )
{
struct V_85 * V_86 = V_84 ;
struct V_56 * V_57 = V_86 -> V_57 ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
F_26 ( & V_2 -> V_53 ) ;
V_7 = F_30 ( V_2 -> V_6 , V_87 ,
V_2 -> V_88 , V_89 * 2 ) ;
F_27 ( & V_2 -> V_53 ) ;
if ( V_7 < 0 )
goto V_90;
F_42 ( V_57 , V_2 -> V_88 ,
V_86 -> V_91 ) ;
V_90:
F_43 ( V_57 -> V_92 ) ;
return V_93 ;
}
static int F_44 ( struct V_94 * V_92 )
{
struct V_56 * V_57 = F_45 ( V_92 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
if ( V_2 -> V_44 )
return 0 ;
V_7 = F_3 ( V_2 -> V_6 , V_33 ,
V_34 |
V_35 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
return 0 ;
}
static int F_46 ( struct V_94 * V_92 ,
bool V_81 )
{
struct V_56 * V_57 = F_45 ( V_92 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
F_26 ( & V_2 -> V_53 ) ;
if ( ! V_81 && V_2 -> V_80 && V_2 -> V_82 ) {
V_2 -> V_82 = false ;
F_27 ( & V_2 -> V_53 ) ;
return 0 ;
}
V_7 = F_15 ( V_2 , V_81 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
if ( V_2 -> V_95 == V_92 )
V_7 = F_21 ( V_2 , V_81 ) ;
else
V_7 = F_22 ( V_2 , V_81 ) ;
if ( V_7 < 0 ) {
F_15 ( V_2 , false ) ;
F_27 ( & V_2 -> V_53 ) ;
return V_7 ;
}
if ( V_2 -> V_95 == V_92 )
V_2 -> V_82 = V_81 ;
else
V_2 -> V_44 = V_81 ;
F_27 ( & V_2 -> V_53 ) ;
return 0 ;
}
static T_3 F_47 ( int V_83 , void * V_96 )
{
struct V_56 * V_57 = V_96 ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_75 ;
unsigned int V_9 ;
V_7 = F_9 ( V_2 -> V_6 , V_97 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_19 ) ;
goto V_98;
}
if ( V_9 & 0x08 )
V_75 = V_99 ;
else
V_75 = V_100 ;
if ( V_9 & V_101 )
F_48 ( V_57 , F_49 ( V_64 ,
0 ,
V_102 ,
V_103 ,
V_75 ) ,
F_50 ( V_57 ) ) ;
if ( V_9 & V_104 )
F_48 ( V_57 , F_49 ( V_64 ,
0 ,
V_105 ,
V_103 ,
V_75 ) ,
F_50 ( V_57 ) ) ;
if ( V_9 & V_106 )
F_48 ( V_57 , F_49 ( V_64 ,
0 ,
V_107 ,
V_103 ,
V_75 ) ,
F_50 ( V_57 ) ) ;
V_98:
if ( ! V_2 -> V_44 ) {
V_7 = F_3 ( V_2 -> V_6 , V_33 ,
V_34 |
V_35 ) ;
if ( V_7 < 0 )
F_4 ( V_5 , L_14 ) ;
}
return V_93 ;
}
static T_3 F_51 ( int V_83 , void * V_96 )
{
struct V_56 * V_57 = V_96 ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
if ( V_2 -> V_44 )
F_52 ( V_2 -> V_108 ) ;
else if ( V_2 -> V_82 )
F_52 ( V_2 -> V_95 ) ;
if ( V_2 -> V_80 )
return V_109 ;
else
return V_93 ;
}
static int F_53 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
return F_15 ( V_2 , true ) ;
}
static int F_54 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_34 ( V_57 ) ;
return F_15 ( V_2 , false ) ;
}
static const char * F_55 ( struct V_4 * V_5 )
{
const struct V_110 * V_111 ;
V_111 = F_56 ( V_5 -> V_112 -> V_113 , V_5 ) ;
if ( ! V_111 )
return NULL ;
return F_57 ( V_5 ) ;
}
int F_58 ( struct V_4 * V_5 , struct V_6 * V_6 , int V_83 ,
const char * V_114 )
{
struct V_1 * V_2 ;
struct V_56 * V_57 ;
int V_7 ;
V_57 = F_59 ( V_5 , sizeof( * V_2 ) ) ;
if ( ! V_57 )
return - V_115 ;
V_2 = F_34 ( V_57 ) ;
F_60 ( V_5 , V_57 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_6 = V_6 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_61 ( & V_2 -> V_53 ) ;
if ( F_62 ( V_5 ) )
V_114 = F_55 ( V_5 ) ;
V_57 -> V_5 . V_116 = V_5 ;
V_57 -> V_117 = V_118 ;
V_57 -> V_119 = F_6 ( V_118 ) ;
V_57 -> V_114 = V_114 ;
V_57 -> V_120 = V_121 ;
V_57 -> V_122 = V_123 ;
V_57 -> V_77 = & V_124 ;
if ( V_2 -> V_83 > 0 ) {
V_7 = F_63 ( V_5 ,
V_2 -> V_83 ,
F_51 ,
F_47 ,
V_125 ,
V_126 ,
V_57 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_108 = F_64 ( V_5 ,
L_20 ,
V_57 -> V_114 ,
V_57 -> V_111 ) ;
if ( ! V_2 -> V_108 )
return - V_115 ;
V_2 -> V_95 = F_64 ( V_5 ,
L_21 ,
V_57 -> V_114 ,
V_57 -> V_111 ) ;
if ( ! V_2 -> V_95 )
return - V_115 ;
V_2 -> V_108 -> V_5 . V_116 = V_5 ;
V_2 -> V_108 -> V_127 = & V_128 ;
F_65 ( V_2 -> V_108 , V_57 ) ;
V_7 = F_66 ( V_2 -> V_108 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_95 -> V_5 . V_116 = V_5 ;
V_2 -> V_95 -> V_127 = & V_128 ;
F_65 ( V_2 -> V_95 , V_57 ) ;
V_7 = F_66 ( V_2 -> V_95 ) ;
if ( V_7 ) {
V_2 -> V_95 = NULL ;
goto V_129;
}
}
V_7 = F_67 ( V_57 ,
V_130 ,
F_41 ,
& V_131 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 ,
L_22 ) ;
goto V_129;
}
V_7 = F_68 ( V_5 ) ;
if ( V_7 )
goto V_132;
F_69 ( V_5 ) ;
F_70 ( V_5 ,
V_133 ) ;
F_71 ( V_5 ) ;
V_7 = F_72 ( V_57 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_23 ) ;
goto V_132;
}
return 0 ;
V_132:
F_73 ( V_57 ) ;
V_129:
if ( V_2 -> V_108 )
F_74 ( V_2 -> V_108 ) ;
if ( V_2 -> V_95 )
F_74 ( V_2 -> V_95 ) ;
return V_7 ;
}
void F_75 ( struct V_4 * V_5 )
{
struct V_56 * V_57 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
F_77 ( V_57 ) ;
F_78 ( V_5 ) ;
F_79 ( V_5 ) ;
F_20 ( V_5 ) ;
F_73 ( V_57 ) ;
if ( V_2 -> V_108 ) {
F_74 ( V_2 -> V_108 ) ;
F_74 ( V_2 -> V_95 ) ;
}
F_26 ( & V_2 -> V_53 ) ;
F_1 ( V_2 , V_134 ) ;
F_27 ( & V_2 -> V_53 ) ;
}
static int F_80 ( struct V_4 * V_5 )
{
struct V_56 * V_57 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
F_26 ( & V_2 -> V_53 ) ;
F_1 ( V_2 , V_135 ) ;
F_27 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_81 ( struct V_4 * V_5 )
{
struct V_56 * V_57 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
F_26 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_44 || V_2 -> V_82 ||
V_2 -> V_80 )
F_1 ( V_2 , V_24 ) ;
F_27 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_82 ( struct V_4 * V_5 )
{
struct V_56 * V_57 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_135 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_24 ) ;
return - V_136 ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_5 )
{
struct V_56 * V_57 = F_76 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_57 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
F_84 ( V_137 ) ;
return 0 ;
}
