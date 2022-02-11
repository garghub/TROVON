static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 * V_7 ;
const char * V_8 ;
int V_9 ;
if ( ! V_5 ) {
F_2 ( V_3 , L_1 ) ;
return F_3 ( - V_10 ) ;
}
V_7 = F_4 ( V_3 , sizeof( * V_7 ) , V_11 ) ;
if ( ! V_7 )
return F_3 ( - V_12 ) ;
V_9 = F_5 ( V_5 , L_2 , & V_8 ) ;
if ( ( V_9 == 0 ) && ( strcmp ( V_8 , L_3 ) == 0 ) )
V_7 -> V_8 = V_13 ;
else
V_7 -> V_8 = V_14 ;
V_9 = F_6 ( V_5 ,
L_4 , & V_7 -> V_15 ) ;
if ( V_9 )
V_7 -> V_16 = false ;
else
V_7 -> V_16 = true ;
V_9 = F_5 ( V_5 , L_5 , & V_7 -> V_17 ) ;
if ( V_9 )
V_7 -> V_17 = L_6 ;
return V_7 ;
}
static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_3 ( - V_10 ) ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 = F_8 ( V_23 -> V_27 ) ;
F_9 ( V_26 -> V_28 , V_29 , 0x0 ) ;
return F_10 ( V_26 -> V_30 ) ;
}
static void F_11 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 = F_8 ( V_23 -> V_27 ) ;
F_12 ( V_26 -> V_30 ) ;
}
static int
F_13 ( struct V_18 * V_19 ,
struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 = F_8 ( V_23 -> V_27 ) ;
if ( F_14 ( V_32 ) != 16 ) {
F_2 ( V_23 -> V_35 -> V_3 ,
L_7 ) ;
return - V_10 ;
}
if ( F_15 ( V_32 ) == 1 )
V_34 -> V_36 = V_37 ;
else
V_34 -> V_36 = V_38 ;
V_34 -> V_39 = V_40 ;
V_34 -> V_41 = V_26 -> V_42 + V_29 ;
V_34 -> V_43 = 1 ;
V_34 -> V_44 = 1 ;
V_34 -> V_45 = false ;
return 0 ;
}
static int F_16 ( struct V_46 * V_47 )
{
struct V_48 * V_27 = F_17 ( V_47 ) ;
struct V_25 * V_26 = F_8 ( V_27 ) ;
const struct V_1 * V_7 = V_26 -> V_7 ;
T_1 V_49 , V_50 ;
V_49 = V_51 ;
V_50 = V_7 -> V_8 << V_52 ;
V_49 |= V_53 ;
if ( V_7 -> V_16 ) {
V_50 |= ( V_54
<< V_55 ) ;
V_49 |= V_56 ;
switch ( V_7 -> V_15 ) {
case 5 :
V_50 |= ( V_57
<< V_58 ) ;
break;
case 10 :
V_50 |= ( V_59
<< V_58 ) ;
break;
case 15 :
V_50 |= ( V_60
<< V_58 ) ;
break;
case 20 :
V_50 |= ( V_61
<< V_58 ) ;
break;
default:
V_50 |= ( V_59
<< V_58 ) ;
F_18 ( V_47 -> V_3 ,
L_8 ,
V_7 -> V_15 ) ;
break;
}
}
F_19 ( V_47 , V_62 , V_49 , V_50 ) ;
F_20 ( V_47 -> V_3 ,
L_9 ,
V_8 [ V_7 -> V_8 ] ,
V_7 -> V_16 ? L_10 : L_11 ) ;
return 0 ;
}
static int F_21 ( struct V_46 * V_47 )
{
struct V_48 * V_27 = F_17 ( V_47 ) ;
struct V_25 * V_26 = F_8 ( V_27 ) ;
return F_22 ( V_26 -> V_28 ) ;
}
static struct V_28 * F_23 ( struct V_2 * V_3 )
{
return F_24 ( V_3 , NULL ) ;
}
static int F_25 ( struct V_18 * V_19 ,
struct V_20 * V_63 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 = F_8 ( V_23 -> V_27 ) ;
return F_10 ( V_26 -> V_64 ) ;
}
static int F_26 ( struct V_20 * V_63 ,
int V_65 )
{
struct V_46 * V_47 = V_63 -> V_47 ;
T_1 V_49 , V_50 ;
V_49 = V_66 | V_67 ;
if ( V_65 )
V_50 = V_49 ;
else
V_50 = 0 ;
F_19 ( V_47 , V_62 , V_49 , V_50 ) ;
return 0 ;
}
static int
F_27 ( struct V_18 * V_19 ,
struct V_31 * V_32 ,
struct V_20 * V_63 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 = F_8 ( V_23 -> V_27 ) ;
struct V_46 * V_47 = V_63 -> V_47 ;
int V_68 ;
int V_69 , V_70 , V_71 , V_72 , V_9 ;
T_1 V_49 , V_50 ;
V_68 = F_28 ( V_32 ) ;
V_70 = 0 ;
V_71 = abs ( V_68 - V_73 [ 0 ] . V_74 ) ;
for ( V_69 = 1 ; V_69 < F_29 ( V_73 ) ; V_69 ++ ) {
V_72 = abs ( V_68 - V_73 [ V_69 ] . V_74 ) ;
if ( V_72 < V_71 ) {
V_70 = V_69 ;
V_71 = V_72 ;
}
}
F_30 ( V_47 -> V_3 ,
L_12 ,
V_73 [ V_70 ] . V_74 , V_73 [ V_70 ] . V_75 ) ;
F_12 ( V_26 -> V_64 ) ;
V_9 = F_31 ( V_26 -> V_64 , V_73 [ V_70 ] . V_75 ) ;
if ( V_9 )
return V_9 ;
V_49 = V_76 | V_77 ;
V_50 = ( V_73 [ V_70 ] . V_78 << V_79 )
| ( V_73 [ V_70 ] . V_80 << V_81 ) ;
F_19 ( V_47 , V_82 , V_49 , V_50 ) ;
return F_10 ( V_26 -> V_64 ) ;
}
static void
F_32 ( struct V_18 * V_19 ,
struct V_20 * V_63 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 = F_8 ( V_23 -> V_27 ) ;
F_12 ( V_26 -> V_64 ) ;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_20 * V_63 )
{
struct V_46 * V_47 = V_63 -> V_47 ;
F_19 ( V_47 , V_62 ,
V_83 | V_84 ,
( V_85 << V_86 )
| ( V_87 << V_88 ) ) ;
return 0 ;
}
static int F_34 ( struct V_18 * V_19 ,
int V_89 , struct V_20 * V_63 )
{
struct V_46 * V_47 = V_63 -> V_47 ;
T_1 V_49 , V_50 ;
V_49 = V_83 | V_84 ;
switch ( V_89 ) {
case V_90 :
case V_91 :
case V_92 :
V_50 = V_49 ;
break;
case V_93 :
case V_94 :
case V_95 :
V_50 = ( V_85 << V_86 )
| ( V_87 << V_88 ) ;
break;
default:
return - V_10 ;
}
F_19 ( V_47 , V_62 , V_49 , V_50 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_48 * V_27 )
{
struct V_96 * V_97 ;
struct V_25 * V_26 = F_8 ( V_27 ) ;
V_97 = F_4 ( V_3 , sizeof( * V_97 ) , V_11 ) ;
if ( ! V_97 )
return - V_12 ;
V_97 -> V_98 = L_6 ;
V_97 -> V_99 = L_13 ;
V_97 -> V_100 = V_101 ;
V_97 -> V_102 = F_36 ( V_3 ) ;
V_97 -> V_103 = F_36 ( V_3 ) ;
V_97 -> V_104 = F_36 ( V_3 ) ;
V_27 -> V_97 = V_97 ;
V_27 -> V_105 = 1 ;
V_27 -> V_98 = V_26 -> V_7 -> V_17 ;
V_27 -> V_3 = V_3 ;
return 0 ;
}
static int F_37 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = & V_107 -> V_3 ;
struct V_25 * V_26 ;
struct V_108 * V_109 ;
void T_2 * V_110 ;
const struct V_1 * V_7 ;
struct V_48 * V_27 ;
int V_9 ;
V_7 = F_38 ( V_3 ) ;
if ( ! V_7 ) {
V_7 = F_1 ( V_3 ) ;
if ( F_39 ( V_7 ) )
return F_40 ( V_7 ) ;
}
V_26 = F_4 ( V_3 , sizeof( * V_26 ) , V_11 ) ;
if ( ! V_26 )
return - V_12 ;
V_26 -> V_7 = V_7 ;
V_26 -> V_111 = F_41 ( V_107 , 0 ) ;
if ( V_26 -> V_111 < 0 ) {
V_9 = V_26 -> V_111 ;
F_2 ( V_3 , L_14 , V_9 ) ;
return V_9 ;
}
V_26 -> V_30 = F_42 ( V_3 , L_15 ) ;
if ( F_39 ( V_26 -> V_30 ) ) {
V_9 = F_40 ( V_26 -> V_30 ) ;
F_2 ( V_3 , L_16 , V_9 ) ;
return V_9 ;
}
V_26 -> V_64 = F_42 ( V_3 , L_17 ) ;
if ( F_39 ( V_26 -> V_64 ) ) {
V_9 = F_40 ( V_26 -> V_64 ) ;
F_2 ( V_3 , L_18 , V_9 ) ;
return V_9 ;
}
V_109 = F_43 ( V_107 , V_112 , 0 ) ;
V_110 = F_44 ( V_3 , V_109 ) ;
if ( F_39 ( V_110 ) ) {
V_9 = F_40 ( V_110 ) ;
F_2 ( V_3 , L_19 , V_9 ) ;
return V_9 ;
}
V_26 -> V_42 = V_109 -> V_113 ;
V_26 -> V_28 = F_45 ( V_3 , V_110 ,
& V_114 ) ;
if ( F_39 ( V_26 -> V_28 ) ) {
V_9 = F_40 ( V_26 -> V_28 ) ;
F_2 ( V_3 , L_20 , V_9 ) ;
return V_9 ;
}
V_9 = F_46 ( V_3 ,
& V_115 ,
& V_116 , 1 ) ;
if ( V_9 ) {
F_2 ( V_3 , L_21 , V_9 ) ;
return V_9 ;
}
V_9 = F_47 ( V_3 ,
& V_117 ,
0 ) ;
if ( V_9 ) {
F_2 ( V_3 , L_22 , V_9 ) ;
return V_9 ;
}
V_9 = F_48 ( V_3 , & V_118 ,
& V_119 , 1 ) ;
if ( V_9 ) {
F_2 ( V_3 , L_23 , V_9 ) ;
return V_9 ;
}
V_27 = F_4 ( V_3 , sizeof( * V_27 ) , V_11 ) ;
if ( ! V_27 ) {
V_9 = - V_12 ;
goto V_120;
}
F_49 ( V_27 , V_26 ) ;
V_9 = F_35 ( V_3 , V_27 ) ;
if ( V_9 ) {
F_2 ( V_3 , L_24 ) ;
goto V_120;
}
V_9 = F_50 ( V_3 , V_27 ) ;
if ( V_9 ) {
F_2 ( V_3 , L_25 , V_9 ) ;
goto V_120;
}
return 0 ;
V_120:
F_51 ( V_3 ) ;
return V_9 ;
}
static int F_52 ( struct V_106 * V_107 )
{
F_51 ( & V_107 -> V_3 ) ;
return 0 ;
}
