static T_1 F_1 ( const struct V_1 * V_2 ,
int V_3 )
{
int V_4 , V_5 , V_6 ;
unsigned long V_7 ;
unsigned int V_8 ;
T_1 error = V_2 -> V_9 ;
V_5 = 0 ;
V_4 = ( V_2 -> V_10 - 1 ) - 1 ;
V_6 = ( V_4 + V_5 ) / 2 ;
if ( V_3 < V_2 -> V_11 [ V_5 ] . V_3 || V_3 > V_2 -> V_11 [ V_4 ] . V_3 )
goto exit;
while ( V_5 <= V_4 ) {
if ( V_3 == V_2 -> V_11 [ V_6 ] . V_3 )
return V_2 -> V_11 [ V_6 ] . V_12 ;
else if ( V_3 < V_2 -> V_11 [ V_6 ] . V_3 )
V_4 = V_6 - 1 ;
else
V_5 = V_6 + 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
V_7 = abs ( V_2 -> V_11 [ V_6 + 1 ] . V_12 - V_2 -> V_11 [ V_6 ] . V_12 ) ;
V_7 *= V_3 - V_2 -> V_11 [ V_6 ] . V_3 ;
V_8 = V_2 -> V_11 [ V_6 + 1 ] . V_3 - V_2 -> V_11 [ V_6 ] . V_3 ;
switch ( V_2 -> V_13 ) {
case V_14 :
return V_2 -> V_11 [ V_6 ] . V_12 - ( V_7 / V_8 ) ;
case V_15 :
return V_2 -> V_11 [ V_6 ] . V_12 + ( V_7 / V_8 ) ;
default:
F_2 ( L_1 , V_16 , V_2 -> V_13 ) ;
return error ;
}
exit:
F_2 ( L_2 ,
V_16 , V_3 , error ) ;
return error ;
}
static int F_3 ( const struct V_1 * V_2 ,
T_1 V_12 , int * V_3 )
{
unsigned int V_5 = 1 ;
unsigned int V_4 = V_2 -> V_10 - 1 ;
unsigned int V_6 = ( V_5 + V_4 ) / 2 ;
unsigned int V_7 ;
unsigned long V_8 ;
F_4 ( V_2 -> V_10 < 2 ) ;
switch ( V_2 -> V_13 ) {
case V_14 :
V_12 &= V_2 -> V_9 ;
if ( V_12 <= V_2 -> V_11 [ V_4 ] . V_12 )
return - V_17 ;
while ( V_5 <= V_4 ) {
if ( V_12 >= V_2 -> V_11 [ V_6 ] . V_12 &&
V_12 < V_2 -> V_11 [ V_6 - 1 ] . V_12 )
break;
else if ( V_12 < V_2 -> V_11 [ V_6 ] . V_12 )
V_5 = V_6 + 1 ;
else
V_4 = V_6 - 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
break;
case V_15 :
V_12 &= V_2 -> V_9 ;
if ( V_12 < V_2 -> V_11 [ V_5 ] . V_12 )
return - V_17 ;
while ( V_5 <= V_4 ) {
if ( V_12 <= V_2 -> V_11 [ V_6 ] . V_12 &&
V_12 > V_2 -> V_11 [ V_6 - 1 ] . V_12 )
break;
else if ( V_12 > V_2 -> V_11 [ V_6 ] . V_12 )
V_5 = V_6 + 1 ;
else
V_4 = V_6 - 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
break;
default:
F_2 ( L_1 , V_16 , V_2 -> V_13 ) ;
return - V_18 ;
}
V_7 = V_2 -> V_11 [ V_6 ] . V_3 - V_2 -> V_11 [ V_6 - 1 ] . V_3 ;
V_7 *= abs ( V_2 -> V_11 [ V_6 - 1 ] . V_12 - V_12 ) ;
V_8 = abs ( V_2 -> V_11 [ V_6 - 1 ] . V_12 - V_2 -> V_11 [ V_6 ] . V_12 ) ;
* V_3 = V_2 -> V_11 [ V_6 - 1 ] . V_3 + ( V_7 / V_8 ) ;
return 0 ;
}
static void F_5 ( struct V_19 * V_20 , void T_2 * V_21 ,
enum V_22 V_22 )
{
if ( V_22 == V_23 )
F_6 ( 0U | V_24 ,
V_21 + V_25 ) ;
else
F_6 ( 0U & ~ V_24 ,
V_21 + V_25 ) ;
F_6 ( V_26 , V_21 + V_27 ) ;
F_6 ( V_28 ,
V_21 + V_29 ) ;
F_6 ( V_30 ,
V_21 + V_31 ) ;
F_6 ( V_32 ,
V_21 + V_33 ) ;
}
static void F_7 ( struct V_19 * V_20 , void T_2 * V_21 ,
enum V_22 V_22 )
{
if ( F_8 ( V_20 ) ) {
F_6 ( V_34 , V_21 +
V_35 ) ;
F_6 ( V_26 ,
V_21 + V_27 ) ;
F_6 ( V_28 ,
V_21 + V_29 ) ;
F_6 ( V_30 ,
V_21 + V_31 ) ;
F_6 ( V_32 ,
V_21 + V_33 ) ;
} else {
F_9 ( V_20 , V_36 , V_37 ) ;
F_9 ( V_20 , V_38 , V_39 ) ;
F_10 ( 15 , 100 ) ;
F_9 ( V_20 , V_40 , V_41 ) ;
F_9 ( V_20 , V_38 , V_42 ) ;
F_10 ( 90 , 200 ) ;
F_6 ( V_43 ,
V_21 + V_27 ) ;
F_6 ( V_28 ,
V_21 + V_29 ) ;
F_6 ( V_44 ,
V_21 + V_31 ) ;
F_6 ( V_32 ,
V_21 + V_33 ) ;
}
if ( V_22 == V_23 )
F_6 ( 0U | V_24 ,
V_21 + V_25 ) ;
else
F_6 ( 0U & ~ V_24 ,
V_21 + V_25 ) ;
}
static void F_11 ( void T_2 * V_21 )
{
T_1 V_45 ;
V_45 = F_12 ( V_21 + V_46 ) ;
F_6 ( V_45 & V_47 , V_21 + V_46 ) ;
}
static void F_13 ( void T_2 * V_21 )
{
T_1 V_45 ;
V_45 = F_12 ( V_21 + V_46 ) ;
F_6 ( V_45 & V_48 , V_21 + V_46 ) ;
}
static void F_14 ( void T_2 * V_21 , bool V_49 )
{
T_1 V_45 ;
V_45 = F_12 ( V_21 + V_25 ) ;
if ( V_49 )
V_45 |= V_50 ;
else
V_45 &= ~ V_50 ;
F_6 ( V_45 , V_21 + V_25 ) ;
}
static void F_15 ( void T_2 * V_21 , bool V_49 )
{
T_1 V_45 ;
V_45 = F_12 ( V_21 + V_25 ) ;
if ( V_49 )
V_45 |= V_50 | V_51 ;
else
V_45 &= ~ V_50 ;
F_6 ( V_45 , V_21 + V_25 ) ;
}
static int F_16 ( const struct V_1 * V_2 ,
int V_52 , void T_2 * V_21 , int * V_3 )
{
T_1 V_45 ;
V_45 = F_12 ( V_21 + F_17 ( V_52 ) ) ;
return F_3 ( V_2 , V_45 , V_3 ) ;
}
static int F_18 ( const struct V_1 * V_2 ,
int V_52 , void T_2 * V_21 , int V_3 )
{
T_1 V_53 ;
T_1 V_54 , V_55 ;
if ( V_3 == V_56 ) {
V_55 = F_12 ( V_21 + V_57 ) ;
V_55 &= ~ F_19 ( V_52 ) ;
F_6 ( V_55 , V_21 + V_57 ) ;
return 0 ;
}
V_53 = F_1 ( V_2 , V_3 ) ;
if ( V_53 == V_2 -> V_9 )
return - V_58 ;
F_6 ( V_53 & V_2 -> V_9 ,
V_21 + F_20 ( V_52 ) ) ;
V_54 = F_12 ( V_21 + V_57 ) ;
V_54 |= F_19 ( V_52 ) ;
F_6 ( V_54 , V_21 + V_57 ) ;
return 0 ;
}
static int F_21 ( const struct V_1 * V_2 ,
int V_52 , void T_2 * V_21 , int V_3 )
{
T_1 V_59 , V_45 ;
V_59 = F_1 ( V_2 , V_3 ) ;
if ( V_59 == V_2 -> V_9 )
return - V_58 ;
F_6 ( V_59 , V_21 + F_22 ( V_52 ) ) ;
V_45 = F_12 ( V_21 + V_25 ) ;
F_6 ( V_45 | F_23 ( V_52 ) , V_21 + V_25 ) ;
return 0 ;
}
static void F_24 ( int V_52 , void T_2 * V_21 ,
enum V_60 V_13 )
{
T_1 V_45 ;
V_45 = F_12 ( V_21 + V_57 ) ;
if ( V_13 == V_61 ) {
V_45 &= ~ F_25 ( V_52 ) ;
V_45 |= F_26 ( V_52 ) ;
} else {
V_45 &= ~ F_26 ( V_52 ) ;
V_45 |= F_25 ( V_52 ) ;
}
F_6 ( V_45 , V_21 + V_57 ) ;
}
static void
F_27 ( struct V_62 * V_63 , bool V_64 )
{
struct V_65 * V_66 = V_63 -> V_66 ;
V_66 -> V_67 -> V_68 ( V_66 ,
V_64 ? V_69 : V_70 ) ;
}
static T_3 F_28 ( int V_71 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
int V_75 ;
F_29 ( & V_74 -> V_76 -> V_72 , L_3 ) ;
V_74 -> V_77 -> V_78 ( V_74 -> V_21 ) ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ )
F_30 ( V_74 -> V_80 [ V_75 ] . V_66 ,
V_81 ) ;
return V_82 ;
}
static int F_31 ( void * V_83 , int V_5 , int V_4 )
{
struct V_62 * V_63 = V_83 ;
struct V_73 * V_74 = V_63 -> V_74 ;
const struct V_84 * V_85 = V_74 -> V_77 ;
F_29 ( & V_74 -> V_76 -> V_72 , L_4 ,
V_16 , V_63 -> V_11 , V_5 , V_4 ) ;
return V_85 -> V_86 ( & V_85 -> V_2 ,
V_63 -> V_11 , V_74 -> V_21 , V_4 ) ;
}
static int F_32 ( void * V_83 , int * V_87 )
{
struct V_62 * V_63 = V_83 ;
struct V_73 * V_74 = V_63 -> V_74 ;
const struct V_84 * V_85 = V_63 -> V_74 -> V_77 ;
int V_88 ;
V_88 = V_85 -> V_89 ( & V_85 -> V_2 ,
V_63 -> V_11 , V_74 -> V_21 , V_87 ) ;
F_29 ( & V_74 -> V_76 -> V_72 , L_5 ,
V_63 -> V_11 , * V_87 , V_88 ) ;
return V_88 ;
}
static int F_33 ( struct V_90 * V_72 ,
struct V_91 * V_92 ,
struct V_73 * V_74 )
{
T_1 V_93 , V_60 , V_22 ;
if ( F_34 ( V_92 , L_6 , & V_93 ) ) {
F_35 ( V_72 ,
L_7 ,
V_74 -> V_77 -> V_94 ) ;
V_74 -> V_94 = V_74 -> V_77 -> V_94 ;
} else {
if ( V_93 > V_56 ) {
F_36 ( V_72 , L_8 ,
V_93 ) ;
return - V_58 ;
}
V_74 -> V_94 = V_93 ;
}
if ( F_34 ( V_92 , L_9 , & V_60 ) ) {
F_35 ( V_72 ,
L_10 ,
V_74 -> V_77 -> V_60 == V_61 ?
L_11 : L_12 ) ;
V_74 -> V_60 = V_74 -> V_77 -> V_60 ;
} else {
V_74 -> V_60 = V_60 ;
}
if ( V_74 -> V_60 > 1 ) {
F_36 ( V_72 , L_13 ,
V_74 -> V_60 ) ;
return - V_18 ;
}
if ( F_34 ( V_92 , L_14 ,
& V_22 ) ) {
F_35 ( V_72 ,
L_15 ,
V_74 -> V_77 -> V_22 == V_95 ?
L_16 : L_17 ) ;
V_74 -> V_22 = V_74 -> V_77 -> V_22 ;
} else {
V_74 -> V_22 = V_22 ;
}
if ( V_74 -> V_22 > 1 ) {
F_36 ( V_72 , L_18 ,
V_74 -> V_22 ) ;
return - V_18 ;
}
V_74 -> V_20 = F_37 ( V_92 , L_19 ) ;
if ( F_8 ( V_74 -> V_20 ) )
F_35 ( V_72 , L_20 ) ;
return 0 ;
}
static int
F_38 ( struct V_96 * V_76 ,
struct V_73 * V_74 ,
struct V_62 * V_63 ,
int V_11 )
{
const struct V_84 * V_85 = V_74 -> V_77 ;
int error ;
V_85 -> V_97 ( V_11 , V_74 -> V_21 , V_74 -> V_60 ) ;
error = V_85 -> V_98 ( & V_85 -> V_2 , V_11 , V_74 -> V_21 ,
V_74 -> V_94 ) ;
if ( error )
F_36 ( & V_76 -> V_72 , L_21 ,
V_16 , V_74 -> V_94 , error ) ;
V_63 -> V_74 = V_74 ;
V_63 -> V_11 = V_11 ;
V_63 -> V_66 = F_39 ( & V_76 -> V_72 , V_11 ,
V_63 , & V_99 ) ;
if ( F_8 ( V_63 -> V_66 ) ) {
error = F_40 ( V_63 -> V_66 ) ;
F_36 ( & V_76 -> V_72 , L_22 ,
V_11 , error ) ;
return error ;
}
return 0 ;
}
static void F_41 ( struct V_100 * V_101 )
{
F_42 ( V_101 ) ;
F_10 ( 10 , 20 ) ;
F_43 ( V_101 ) ;
}
static int F_44 ( struct V_96 * V_76 )
{
struct V_91 * V_92 = V_76 -> V_72 . V_102 ;
struct V_73 * V_74 ;
const struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_71 ;
int V_75 ;
int error ;
V_104 = F_45 ( V_107 , V_92 ) ;
if ( ! V_104 )
return - V_108 ;
V_71 = F_46 ( V_76 , 0 ) ;
if ( V_71 < 0 ) {
F_36 ( & V_76 -> V_72 , L_23 ) ;
return - V_18 ;
}
V_74 = F_47 ( & V_76 -> V_72 , sizeof( struct V_73 ) ,
V_109 ) ;
if ( ! V_74 )
return - V_110 ;
V_74 -> V_76 = V_76 ;
V_74 -> V_77 = ( const struct V_84 * ) V_104 -> V_111 ;
if ( ! V_74 -> V_77 )
return - V_18 ;
V_106 = F_48 ( V_76 , V_112 , 0 ) ;
V_74 -> V_21 = F_49 ( & V_76 -> V_72 , V_106 ) ;
if ( F_8 ( V_74 -> V_21 ) )
return F_40 ( V_74 -> V_21 ) ;
V_74 -> V_101 = F_50 ( & V_76 -> V_72 , L_24 ) ;
if ( F_8 ( V_74 -> V_101 ) ) {
error = F_40 ( V_74 -> V_101 ) ;
F_36 ( & V_76 -> V_72 , L_25 , error ) ;
return error ;
}
V_74 -> V_113 = F_51 ( & V_76 -> V_72 , L_26 ) ;
if ( F_8 ( V_74 -> V_113 ) ) {
error = F_40 ( V_74 -> V_113 ) ;
F_36 ( & V_76 -> V_72 , L_27 , error ) ;
return error ;
}
V_74 -> V_114 = F_51 ( & V_76 -> V_72 , L_28 ) ;
if ( F_8 ( V_74 -> V_114 ) ) {
error = F_40 ( V_74 -> V_114 ) ;
F_36 ( & V_76 -> V_72 , L_29 ,
error ) ;
return error ;
}
error = F_52 ( V_74 -> V_113 ) ;
if ( error ) {
F_36 ( & V_76 -> V_72 , L_30 ,
error ) ;
return error ;
}
error = F_52 ( V_74 -> V_114 ) ;
if ( error ) {
F_36 ( & V_76 -> V_72 , L_31 , error ) ;
goto V_115;
}
F_41 ( V_74 -> V_101 ) ;
error = F_33 ( & V_76 -> V_72 , V_92 , V_74 ) ;
if ( error ) {
F_36 ( & V_76 -> V_72 , L_32 ,
error ) ;
goto V_116;
}
V_74 -> V_77 -> V_117 ( V_74 -> V_20 , V_74 -> V_21 ,
V_74 -> V_22 ) ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ ) {
error = F_38 ( V_76 , V_74 ,
& V_74 -> V_80 [ V_75 ] ,
V_74 -> V_77 -> V_118 [ V_75 ] ) ;
if ( error ) {
F_36 ( & V_76 -> V_72 ,
L_33 ,
V_75 , error ) ;
goto V_116;
}
}
error = F_53 ( & V_76 -> V_72 , V_71 , NULL ,
& F_28 ,
V_119 ,
L_34 , V_74 ) ;
if ( error ) {
F_36 ( & V_76 -> V_72 ,
L_35 , error ) ;
goto V_116;
}
V_74 -> V_77 -> V_120 ( V_74 -> V_21 , true ) ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ )
F_27 ( & V_74 -> V_80 [ V_75 ] , true ) ;
F_54 ( V_76 , V_74 ) ;
return 0 ;
V_116:
F_55 ( V_74 -> V_114 ) ;
V_115:
F_55 ( V_74 -> V_113 ) ;
return error ;
}
static int F_56 ( struct V_96 * V_76 )
{
struct V_73 * V_74 = F_57 ( V_76 ) ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ ) {
struct V_62 * V_63 = & V_74 -> V_80 [ V_75 ] ;
F_27 ( V_63 , false ) ;
}
V_74 -> V_77 -> V_120 ( V_74 -> V_21 , false ) ;
F_55 ( V_74 -> V_114 ) ;
F_55 ( V_74 -> V_113 ) ;
return 0 ;
}
static int T_4 F_58 ( struct V_90 * V_72 )
{
struct V_96 * V_76 = F_59 ( V_72 ) ;
struct V_73 * V_74 = F_57 ( V_76 ) ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ )
F_27 ( & V_74 -> V_80 [ V_75 ] , false ) ;
V_74 -> V_77 -> V_120 ( V_74 -> V_21 , false ) ;
F_60 ( V_74 -> V_114 ) ;
F_60 ( V_74 -> V_113 ) ;
F_61 ( V_72 ) ;
return 0 ;
}
static int T_4 F_62 ( struct V_90 * V_72 )
{
struct V_96 * V_76 = F_59 ( V_72 ) ;
struct V_73 * V_74 = F_57 ( V_76 ) ;
int V_75 ;
int error ;
error = F_63 ( V_74 -> V_113 ) ;
if ( error )
return error ;
error = F_63 ( V_74 -> V_114 ) ;
if ( error ) {
F_60 ( V_74 -> V_113 ) ;
return error ;
}
F_41 ( V_74 -> V_101 ) ;
V_74 -> V_77 -> V_117 ( V_74 -> V_20 , V_74 -> V_21 ,
V_74 -> V_22 ) ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ ) {
int V_11 = V_74 -> V_80 [ V_75 ] . V_11 ;
V_74 -> V_77 -> V_97 ( V_11 , V_74 -> V_21 ,
V_74 -> V_60 ) ;
error = V_74 -> V_77 -> V_98 ( & V_74 -> V_77 -> V_2 ,
V_11 , V_74 -> V_21 ,
V_74 -> V_94 ) ;
if ( error )
F_36 ( & V_76 -> V_72 , L_21 ,
V_16 , V_74 -> V_94 , error ) ;
}
V_74 -> V_77 -> V_120 ( V_74 -> V_21 , true ) ;
for ( V_75 = 0 ; V_75 < V_74 -> V_77 -> V_79 ; V_75 ++ )
F_27 ( & V_74 -> V_80 [ V_75 ] , true ) ;
F_64 ( V_72 ) ;
return 0 ;
}
