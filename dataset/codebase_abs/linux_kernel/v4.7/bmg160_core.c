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
if ( V_11 [ V_10 ] . V_9 == V_9 )
return V_11 [ V_10 ] . V_12 ;
}
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_12 ;
V_12 = F_5 ( V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 = F_3 ( V_2 -> V_6 , V_14 , V_12 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_2 ) ;
return V_7 ;
}
V_2 -> V_12 = V_12 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
unsigned int V_9 ;
V_7 = F_9 ( V_2 -> V_6 , V_15 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_3 ) ;
return V_7 ;
}
F_10 ( V_5 , L_4 , V_9 ) ;
if ( V_9 != V_16 ) {
F_4 ( V_5 , L_5 , V_9 ) ;
return - V_17 ;
}
V_7 = F_1 ( V_2 , V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
F_11 ( 500 , 1000 ) ;
V_7 = F_7 ( V_2 , V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_2 -> V_6 , V_20 , V_21 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_6 ) ;
return V_7 ;
}
V_2 -> V_22 = V_21 ;
V_7 = F_9 ( V_2 -> V_6 , V_23 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_7 ) ;
return V_7 ;
}
V_2 -> V_24 = V_9 ;
V_7 = F_12 ( V_2 -> V_6 , V_25 ,
V_26 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_8 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_27 ,
V_28 |
V_29 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 ,
L_9 ) ;
return V_7 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_30 )
{
#ifdef F_14
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
if ( V_30 )
V_7 = F_15 ( V_5 ) ;
else {
F_16 ( V_5 ) ;
V_7 = F_17 ( V_5 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_10 , V_30 ) ;
if ( V_30 )
F_18 ( V_5 ) ;
return V_7 ;
}
#endif
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
bool V_31 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_12 ( V_2 -> V_6 , V_32 ,
V_33 ,
( V_31 ? V_33 : 0 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_11 ) ;
return V_7 ;
}
if ( V_31 ) {
V_7 = F_3 ( V_2 -> V_6 , V_23 ,
V_2 -> V_24 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_12 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_34 ,
V_35 | V_36 |
V_37 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_9 ) ;
return V_7 ;
}
if ( ! V_2 -> V_38 ) {
V_7 = F_3 ( V_2 -> V_6 ,
V_27 ,
V_28 |
V_29 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_13 ) ;
return V_7 ;
}
}
V_7 = F_3 ( V_2 -> V_6 , V_39 ,
V_40 ) ;
} else {
V_7 = F_3 ( V_2 -> V_6 , V_39 , 0 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
bool V_31 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = F_12 ( V_2 -> V_6 , V_41 ,
V_42 ,
( V_31 ? V_42 : 0 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_15 ) ;
return V_7 ;
}
if ( V_31 ) {
V_7 = F_3 ( V_2 -> V_6 , V_27 ,
V_43 |
V_29 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_13 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_39 ,
V_40 ) ;
} else {
V_7 = F_3 ( V_2 -> V_6 , V_27 ,
V_28 |
V_29 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_13 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_6 , V_39 , 0 ) ;
}
if ( V_7 < 0 ) {
F_4 ( V_5 , L_14 ) ;
return V_7 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int * V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_11 ) ; ++ V_10 ) {
if ( V_11 [ V_10 ] . V_12 == V_2 -> V_12 ) {
* V_9 = V_11 [ V_10 ] . V_9 ;
return V_44 ;
}
}
return - V_13 ;
}
static int F_22 ( struct V_1 * V_2 , int V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 , V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_45 ) ; ++ V_10 ) {
if ( V_45 [ V_10 ] . V_46 == V_9 ) {
V_7 = F_3 ( V_2 -> V_6 , V_20 ,
V_45 [ V_10 ] . V_22 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_6 ) ;
return V_7 ;
}
V_2 -> V_22 = V_45 [ V_10 ] . V_22 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_23 ( struct V_1 * V_2 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
unsigned int V_47 ;
F_24 ( & V_2 -> V_48 ) ;
V_7 = F_13 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_9 ( V_2 -> V_6 , V_49 , & V_47 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_16 ) ;
F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
* V_9 = F_26 ( V_47 , 7 ) ;
V_7 = F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_44 ;
}
static int F_27 ( struct V_1 * V_2 , int V_50 , int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
T_2 V_47 ;
F_24 ( & V_2 -> V_48 ) ;
V_7 = F_13 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_28 ( V_2 -> V_6 , F_29 ( V_50 ) , & V_47 ,
sizeof( V_47 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_17 , V_50 ) ;
F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
* V_9 = F_26 ( F_30 ( V_47 ) , 15 ) ;
V_7 = F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_44 ;
}
static int F_31 ( struct V_51 * V_52 ,
struct V_53 const * V_54 ,
int * V_9 , int * V_55 , long V_56 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
switch ( V_56 ) {
case V_57 :
switch ( V_54 -> type ) {
case V_58 :
return F_23 ( V_2 , V_9 ) ;
case V_59 :
if ( F_33 ( V_52 ) )
return - V_60 ;
else
return F_27 ( V_2 , V_54 -> V_61 ,
V_9 ) ;
default:
return - V_13 ;
}
case V_62 :
if ( V_54 -> type == V_58 ) {
* V_9 = V_63 ;
return V_44 ;
} else
return - V_13 ;
case V_64 :
* V_9 = 0 ;
switch ( V_54 -> type ) {
case V_58 :
* V_55 = 500000 ;
return V_65 ;
case V_59 :
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_45 ) ; ++ V_10 ) {
if ( V_45 [ V_10 ] . V_22 ==
V_2 -> V_22 ) {
* V_55 = V_45 [ V_10 ] . V_46 ;
return V_65 ;
}
}
return - V_13 ;
}
default:
return - V_13 ;
}
case V_66 :
* V_55 = 0 ;
F_24 ( & V_2 -> V_48 ) ;
V_7 = F_21 ( V_2 , V_9 ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
default:
return - V_13 ;
}
}
static int F_34 ( struct V_51 * V_52 ,
struct V_53 const * V_54 ,
int V_9 , int V_55 , long V_56 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
switch ( V_56 ) {
case V_66 :
F_24 ( & V_2 -> V_48 ) ;
V_7 = F_13 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_7 ( V_2 , V_9 ) ;
if ( V_7 < 0 ) {
F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
case V_64 :
if ( V_9 )
return - V_13 ;
F_24 ( & V_2 -> V_48 ) ;
V_7 = F_13 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_22 ( V_2 , V_55 ) ;
if ( V_7 < 0 ) {
F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
default:
return - V_13 ;
}
return - V_13 ;
}
static int F_35 ( struct V_51 * V_52 ,
const struct V_53 * V_54 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_70 V_71 ,
int * V_9 , int * V_55 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
* V_55 = 0 ;
switch ( V_71 ) {
case V_72 :
* V_9 = V_2 -> V_24 & V_73 ;
break;
default:
return - V_13 ;
}
return V_44 ;
}
static int F_36 ( struct V_51 * V_52 ,
const struct V_53 * V_54 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_70 V_71 ,
int V_9 , int V_55 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
switch ( V_71 ) {
case V_72 :
if ( V_2 -> V_74 )
return - V_60 ;
V_2 -> V_24 &= ~ V_73 ;
V_2 -> V_24 |= ( V_9 & V_73 ) ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_37 ( struct V_51 * V_52 ,
const struct V_53 * V_54 ,
enum V_67 type ,
enum V_68 V_69 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
return V_2 -> V_74 ;
}
static int F_38 ( struct V_51 * V_52 ,
const struct V_53 * V_54 ,
enum V_67 type ,
enum V_68 V_69 ,
int V_75 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
if ( V_75 && V_2 -> V_74 )
return 0 ;
F_24 ( & V_2 -> V_48 ) ;
if ( ! V_75 && V_2 -> V_76 ) {
V_2 -> V_74 = 0 ;
F_25 ( & V_2 -> V_48 ) ;
return 0 ;
}
V_7 = F_13 ( V_2 , V_75 ) ;
if ( V_7 < 0 ) {
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_19 ( V_2 , V_75 ) ;
if ( V_7 < 0 ) {
F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_2 -> V_74 = V_75 ;
F_25 ( & V_2 -> V_48 ) ;
return 0 ;
}
static T_3 F_39 ( int V_77 , void * V_78 )
{
struct V_79 * V_80 = V_78 ;
struct V_51 * V_52 = V_80 -> V_52 ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
F_24 ( & V_2 -> V_48 ) ;
V_7 = F_28 ( V_2 -> V_6 , V_81 ,
V_2 -> V_82 , V_83 * 2 ) ;
F_25 ( & V_2 -> V_48 ) ;
if ( V_7 < 0 )
goto V_84;
F_40 ( V_52 , V_2 -> V_82 ,
V_80 -> V_85 ) ;
V_84:
F_41 ( V_52 -> V_86 ) ;
return V_87 ;
}
static int F_42 ( struct V_88 * V_86 )
{
struct V_51 * V_52 = F_43 ( V_86 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
if ( V_2 -> V_38 )
return 0 ;
V_7 = F_3 ( V_2 -> V_6 , V_27 ,
V_28 |
V_29 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_13 ) ;
return V_7 ;
}
return 0 ;
}
static int F_44 ( struct V_88 * V_86 ,
bool V_75 )
{
struct V_51 * V_52 = F_43 ( V_86 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
F_24 ( & V_2 -> V_48 ) ;
if ( ! V_75 && V_2 -> V_74 && V_2 -> V_76 ) {
V_2 -> V_76 = false ;
F_25 ( & V_2 -> V_48 ) ;
return 0 ;
}
V_7 = F_13 ( V_2 , V_75 ) ;
if ( V_7 < 0 ) {
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
if ( V_2 -> V_89 == V_86 )
V_7 = F_19 ( V_2 , V_75 ) ;
else
V_7 = F_20 ( V_2 , V_75 ) ;
if ( V_7 < 0 ) {
F_13 ( V_2 , false ) ;
F_25 ( & V_2 -> V_48 ) ;
return V_7 ;
}
if ( V_2 -> V_89 == V_86 )
V_2 -> V_76 = V_75 ;
else
V_2 -> V_38 = V_75 ;
F_25 ( & V_2 -> V_48 ) ;
return 0 ;
}
static T_3 F_45 ( int V_77 , void * V_90 )
{
struct V_51 * V_52 = V_90 ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
int V_69 ;
unsigned int V_9 ;
V_7 = F_9 ( V_2 -> V_6 , V_91 , & V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_18 ) ;
goto V_92;
}
if ( V_9 & 0x08 )
V_69 = V_93 ;
else
V_69 = V_94 ;
if ( V_9 & V_95 )
F_46 ( V_52 , F_47 ( V_59 ,
0 ,
V_96 ,
V_97 ,
V_69 ) ,
F_48 () ) ;
if ( V_9 & V_98 )
F_46 ( V_52 , F_47 ( V_59 ,
0 ,
V_99 ,
V_97 ,
V_69 ) ,
F_48 () ) ;
if ( V_9 & V_100 )
F_46 ( V_52 , F_47 ( V_59 ,
0 ,
V_101 ,
V_97 ,
V_69 ) ,
F_48 () ) ;
V_92:
if ( ! V_2 -> V_38 ) {
V_7 = F_3 ( V_2 -> V_6 , V_27 ,
V_28 |
V_29 ) ;
if ( V_7 < 0 )
F_4 ( V_5 , L_13 ) ;
}
return V_87 ;
}
static T_3 F_49 ( int V_77 , void * V_90 )
{
struct V_51 * V_52 = V_90 ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
if ( V_2 -> V_38 )
F_50 ( V_2 -> V_102 ) ;
else if ( V_2 -> V_76 )
F_50 ( V_2 -> V_89 ) ;
if ( V_2 -> V_74 )
return V_103 ;
else
return V_87 ;
}
static int F_51 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
return F_13 ( V_2 , true ) ;
}
static int F_52 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_32 ( V_52 ) ;
return F_13 ( V_2 , false ) ;
}
static const char * F_53 ( struct V_4 * V_5 )
{
const struct V_104 * V_105 ;
V_105 = F_54 ( V_5 -> V_106 -> V_107 , V_5 ) ;
if ( ! V_105 )
return NULL ;
return F_55 ( V_5 ) ;
}
int F_56 ( struct V_4 * V_5 , struct V_6 * V_6 , int V_77 ,
const char * V_108 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_7 ;
V_52 = F_57 ( V_5 , sizeof( * V_2 ) ) ;
if ( ! V_52 )
return - V_109 ;
V_2 = F_32 ( V_52 ) ;
F_58 ( V_5 , V_52 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_6 = V_6 ;
V_7 = F_8 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_59 ( & V_2 -> V_48 ) ;
if ( F_60 ( V_5 ) )
V_108 = F_53 ( V_5 ) ;
V_52 -> V_5 . V_110 = V_5 ;
V_52 -> V_111 = V_112 ;
V_52 -> V_113 = F_6 ( V_112 ) ;
V_52 -> V_108 = V_108 ;
V_52 -> V_114 = V_115 ;
V_52 -> V_116 = V_117 ;
V_52 -> V_71 = & V_118 ;
if ( V_2 -> V_77 > 0 ) {
V_7 = F_61 ( V_5 ,
V_2 -> V_77 ,
F_49 ,
F_45 ,
V_119 ,
V_120 ,
V_52 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_102 = F_62 ( V_5 ,
L_19 ,
V_52 -> V_108 ,
V_52 -> V_105 ) ;
if ( ! V_2 -> V_102 )
return - V_109 ;
V_2 -> V_89 = F_62 ( V_5 ,
L_20 ,
V_52 -> V_108 ,
V_52 -> V_105 ) ;
if ( ! V_2 -> V_89 )
return - V_109 ;
V_2 -> V_102 -> V_5 . V_110 = V_5 ;
V_2 -> V_102 -> V_121 = & V_122 ;
F_63 ( V_2 -> V_102 , V_52 ) ;
V_7 = F_64 ( V_2 -> V_102 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_89 -> V_5 . V_110 = V_5 ;
V_2 -> V_89 -> V_121 = & V_122 ;
F_63 ( V_2 -> V_89 , V_52 ) ;
V_7 = F_64 ( V_2 -> V_89 ) ;
if ( V_7 ) {
V_2 -> V_89 = NULL ;
goto V_123;
}
}
V_7 = F_65 ( V_52 ,
V_124 ,
F_39 ,
& V_125 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 ,
L_21 ) ;
goto V_123;
}
V_7 = F_66 ( V_5 ) ;
if ( V_7 )
goto V_126;
F_67 ( V_5 ) ;
F_68 ( V_5 ,
V_127 ) ;
F_69 ( V_5 ) ;
V_7 = F_70 ( V_52 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_22 ) ;
goto V_126;
}
return 0 ;
V_126:
F_71 ( V_52 ) ;
V_123:
if ( V_2 -> V_102 )
F_72 ( V_2 -> V_102 ) ;
if ( V_2 -> V_89 )
F_72 ( V_2 -> V_89 ) ;
return V_7 ;
}
void F_73 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = F_74 ( V_5 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
F_75 ( V_52 ) ;
F_76 ( V_5 ) ;
F_77 ( V_5 ) ;
F_18 ( V_5 ) ;
F_71 ( V_52 ) ;
if ( V_2 -> V_102 ) {
F_72 ( V_2 -> V_102 ) ;
F_72 ( V_2 -> V_89 ) ;
}
F_24 ( & V_2 -> V_48 ) ;
F_1 ( V_2 , V_128 ) ;
F_25 ( & V_2 -> V_48 ) ;
}
static int F_78 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = F_74 ( V_5 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
F_24 ( & V_2 -> V_48 ) ;
F_1 ( V_2 , V_129 ) ;
F_25 ( & V_2 -> V_48 ) ;
return 0 ;
}
static int F_79 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = F_74 ( V_5 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
F_24 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_38 || V_2 -> V_76 ||
V_2 -> V_74 )
F_1 ( V_2 , V_18 ) ;
F_25 ( & V_2 -> V_48 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = F_74 ( V_5 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_129 ) ;
if ( V_7 < 0 ) {
F_4 ( V_5 , L_23 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_81 ( struct V_4 * V_5 )
{
struct V_51 * V_52 = F_74 ( V_5 ) ;
struct V_1 * V_2 = F_32 ( V_52 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
F_82 ( V_131 ) ;
return 0 ;
}
