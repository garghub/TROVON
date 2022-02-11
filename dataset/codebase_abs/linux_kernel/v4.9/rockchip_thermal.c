static T_1 F_1 ( struct V_1 V_2 ,
int V_3 )
{
int V_4 , V_5 , V_6 ;
T_1 error = 0 ;
V_5 = 0 ;
V_4 = V_2 . V_7 - 1 ;
V_6 = ( V_4 + V_5 ) / 2 ;
if ( V_3 < V_2 . V_8 [ V_5 ] . V_3 || V_3 > V_2 . V_8 [ V_4 ] . V_3 ) {
error = V_2 . V_9 ;
goto exit;
}
while ( V_5 <= V_4 ) {
if ( V_3 == V_2 . V_8 [ V_6 ] . V_3 )
return V_2 . V_8 [ V_6 ] . V_10 ;
else if ( V_3 < V_2 . V_8 [ V_6 ] . V_3 )
V_4 = V_6 - 1 ;
else
V_5 = V_6 + 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
exit:
F_2 ( L_1 , error ) ;
return error ;
}
static int F_3 ( struct V_1 V_2 , T_1 V_10 ,
int * V_3 )
{
unsigned int V_5 = 1 ;
unsigned int V_4 = V_2 . V_7 - 1 ;
unsigned int V_6 = ( V_5 + V_4 ) / 2 ;
unsigned int V_11 ;
unsigned long V_12 ;
F_4 ( V_2 . V_7 < 2 ) ;
switch ( V_2 . V_13 ) {
case V_14 :
V_10 &= V_2 . V_9 ;
if ( V_10 < V_2 . V_8 [ V_4 ] . V_10 )
return - V_15 ;
while ( V_5 <= V_4 ) {
if ( V_10 >= V_2 . V_8 [ V_6 ] . V_10 &&
V_10 < V_2 . V_8 [ V_6 - 1 ] . V_10 )
break;
else if ( V_10 < V_2 . V_8 [ V_6 ] . V_10 )
V_5 = V_6 + 1 ;
else
V_4 = V_6 - 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
break;
case V_16 :
V_10 &= V_2 . V_9 ;
if ( V_10 < V_2 . V_8 [ V_5 ] . V_10 )
return - V_15 ;
while ( V_5 <= V_4 ) {
if ( V_10 <= V_2 . V_8 [ V_6 ] . V_10 &&
V_10 > V_2 . V_8 [ V_6 - 1 ] . V_10 )
break;
else if ( V_10 > V_2 . V_8 [ V_6 ] . V_10 )
V_5 = V_6 + 1 ;
else
V_4 = V_6 - 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
break;
default:
F_2 ( L_2 ) ;
}
V_11 = V_2 . V_8 [ V_6 ] . V_3 - V_2 . V_8 [ V_6 - 1 ] . V_3 ;
V_11 *= abs ( V_2 . V_8 [ V_6 - 1 ] . V_10 - V_10 ) ;
V_12 = abs ( V_2 . V_8 [ V_6 - 1 ] . V_10 - V_2 . V_8 [ V_6 ] . V_10 ) ;
* V_3 = V_2 . V_8 [ V_6 - 1 ] . V_3 + ( V_11 / V_12 ) ;
return 0 ;
}
static void F_5 ( struct V_17 * V_18 , void T_2 * V_19 ,
enum V_20 V_20 )
{
if ( V_20 == V_21 )
F_6 ( 0U | V_22 ,
V_19 + V_23 ) ;
else
F_6 ( 0U & ~ V_22 ,
V_19 + V_23 ) ;
F_6 ( V_24 , V_19 + V_25 ) ;
F_6 ( V_26 ,
V_19 + V_27 ) ;
F_6 ( V_28 ,
V_19 + V_29 ) ;
F_6 ( V_30 ,
V_19 + V_31 ) ;
if ( F_7 ( V_18 ) ) {
F_8 ( L_3 , V_32 ) ;
return;
}
}
static void F_9 ( struct V_17 * V_18 , void T_2 * V_19 ,
enum V_20 V_20 )
{
if ( F_7 ( V_18 ) ) {
F_6 ( V_33 , V_19 +
V_34 ) ;
F_6 ( V_24 ,
V_19 + V_25 ) ;
F_6 ( V_26 ,
V_19 + V_27 ) ;
F_6 ( V_28 ,
V_19 + V_29 ) ;
F_6 ( V_30 ,
V_19 + V_31 ) ;
} else {
F_10 ( V_18 , V_35 , V_36 ) ;
F_10 ( V_18 , V_37 , V_38 ) ;
F_11 ( 15 , 100 ) ;
F_10 ( V_18 , V_39 , V_40 ) ;
F_10 ( V_18 , V_37 , V_41 ) ;
F_11 ( 90 , 200 ) ;
F_6 ( V_42 ,
V_19 + V_25 ) ;
F_6 ( V_26 ,
V_19 + V_27 ) ;
F_6 ( V_43 ,
V_19 + V_29 ) ;
F_6 ( V_30 ,
V_19 + V_31 ) ;
}
if ( V_20 == V_21 )
F_6 ( 0U | V_22 ,
V_19 + V_23 ) ;
else
F_6 ( 0U & ~ V_22 ,
V_19 + V_23 ) ;
}
static void F_12 ( void T_2 * V_19 )
{
T_1 V_44 ;
V_44 = F_13 ( V_19 + V_45 ) ;
F_6 ( V_44 & V_46 , V_19 + V_45 ) ;
}
static void F_14 ( void T_2 * V_19 )
{
T_1 V_44 ;
V_44 = F_13 ( V_19 + V_45 ) ;
F_6 ( V_44 & V_47 , V_19 + V_45 ) ;
}
static void F_15 ( void T_2 * V_19 , bool V_48 )
{
T_1 V_44 ;
V_44 = F_13 ( V_19 + V_23 ) ;
if ( V_48 )
V_44 |= V_49 ;
else
V_44 &= ~ V_49 ;
F_6 ( V_44 , V_19 + V_23 ) ;
}
static void F_16 ( void T_2 * V_19 , bool V_48 )
{
T_1 V_44 ;
V_44 = F_13 ( V_19 + V_23 ) ;
if ( V_48 )
V_44 |= V_49 | V_50 ;
else
V_44 &= ~ V_49 ;
F_6 ( V_44 , V_19 + V_23 ) ;
}
static int F_17 ( struct V_1 V_2 ,
int V_51 , void T_2 * V_19 , int * V_3 )
{
T_1 V_44 ;
V_44 = F_13 ( V_19 + F_18 ( V_51 ) ) ;
return F_3 ( V_2 , V_44 , V_3 ) ;
}
static void F_19 ( struct V_1 V_2 ,
int V_51 , void T_2 * V_19 , int V_3 )
{
T_1 V_52 , V_53 ;
V_52 = F_1 ( V_2 , V_3 ) ;
if ( V_52 == V_2 . V_9 )
return;
F_6 ( V_52 & V_2 . V_9 ,
V_19 + F_20 ( V_51 ) ) ;
V_53 = F_13 ( V_19 + V_54 ) ;
V_53 |= F_21 ( V_51 ) ;
F_6 ( V_53 , V_19 + V_54 ) ;
}
static void F_22 ( struct V_1 V_2 ,
int V_51 , void T_2 * V_19 , int V_3 )
{
T_1 V_55 , V_44 ;
V_55 = F_1 ( V_2 , V_3 ) ;
if ( V_55 == V_2 . V_9 )
return;
F_6 ( V_55 , V_19 + F_23 ( V_51 ) ) ;
V_44 = F_13 ( V_19 + V_23 ) ;
F_6 ( V_44 | F_24 ( V_51 ) , V_19 + V_23 ) ;
}
static void F_25 ( int V_51 , void T_2 * V_19 ,
enum V_56 V_13 )
{
T_1 V_44 ;
V_44 = F_13 ( V_19 + V_54 ) ;
if ( V_13 == V_57 ) {
V_44 &= ~ F_26 ( V_51 ) ;
V_44 |= F_27 ( V_51 ) ;
} else {
V_44 &= ~ F_27 ( V_51 ) ;
V_44 |= F_26 ( V_51 ) ;
}
F_6 ( V_44 , V_19 + V_54 ) ;
}
static void
F_28 ( struct V_58 * V_59 , bool V_60 )
{
struct V_61 * V_62 = V_59 -> V_62 ;
V_62 -> V_63 -> V_64 ( V_62 ,
V_60 ? V_65 : V_66 ) ;
}
static T_3 F_29 ( int V_67 , void * V_68 )
{
struct V_69 * V_70 = V_68 ;
int V_71 ;
F_30 ( & V_70 -> V_72 -> V_68 , L_4 ) ;
V_70 -> V_73 -> V_74 ( V_70 -> V_19 ) ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ )
F_31 ( V_70 -> V_76 [ V_71 ] . V_62 ,
V_77 ) ;
return V_78 ;
}
static int F_32 ( void * V_79 , int V_5 , int V_4 )
{
struct V_58 * V_59 = V_79 ;
struct V_69 * V_70 = V_59 -> V_70 ;
const struct V_80 * V_81 = V_70 -> V_73 ;
F_30 ( & V_70 -> V_72 -> V_68 , L_5 ,
V_32 , V_59 -> V_8 , V_5 , V_4 ) ;
V_81 -> V_82 ( V_81 -> V_2 ,
V_59 -> V_8 , V_70 -> V_19 , V_4 ) ;
return 0 ;
}
static int F_33 ( void * V_79 , int * V_83 )
{
struct V_58 * V_59 = V_79 ;
struct V_69 * V_70 = V_59 -> V_70 ;
const struct V_80 * V_81 = V_59 -> V_70 -> V_73 ;
int V_84 ;
V_84 = V_81 -> V_85 ( V_81 -> V_2 ,
V_59 -> V_8 , V_70 -> V_19 , V_83 ) ;
F_30 ( & V_70 -> V_72 -> V_68 , L_6 ,
V_59 -> V_8 , * V_83 , V_84 ) ;
return V_84 ;
}
static int F_34 ( struct V_86 * V_68 ,
struct V_87 * V_88 ,
struct V_69 * V_70 )
{
T_1 V_89 , V_56 , V_20 ;
if ( F_35 ( V_88 , L_7 , & V_89 ) ) {
F_36 ( V_68 ,
L_8 ,
V_70 -> V_73 -> V_90 ) ;
V_70 -> V_90 = V_70 -> V_73 -> V_90 ;
} else {
if ( V_89 > V_91 ) {
F_37 ( V_68 , L_9 ,
V_89 ) ;
return - V_92 ;
}
V_70 -> V_90 = V_89 ;
}
if ( F_35 ( V_88 , L_10 , & V_56 ) ) {
F_36 ( V_68 ,
L_11 ,
V_70 -> V_73 -> V_56 == V_57 ?
L_12 : L_13 ) ;
V_70 -> V_56 = V_70 -> V_73 -> V_56 ;
} else {
V_70 -> V_56 = V_56 ;
}
if ( V_70 -> V_56 > 1 ) {
F_37 ( V_68 , L_14 ,
V_70 -> V_56 ) ;
return - V_93 ;
}
if ( F_35 ( V_88 , L_15 ,
& V_20 ) ) {
F_36 ( V_68 ,
L_16 ,
V_70 -> V_73 -> V_20 == V_94 ?
L_17 : L_18 ) ;
V_70 -> V_20 = V_70 -> V_73 -> V_20 ;
} else {
V_70 -> V_20 = V_20 ;
}
if ( V_70 -> V_20 > 1 ) {
F_37 ( V_68 , L_19 ,
V_70 -> V_20 ) ;
return - V_93 ;
}
V_70 -> V_18 = F_38 ( V_88 , L_20 ) ;
return 0 ;
}
static int
F_39 ( struct V_95 * V_72 ,
struct V_69 * V_70 ,
struct V_58 * V_59 ,
int V_8 )
{
const struct V_80 * V_81 = V_70 -> V_73 ;
int error ;
V_81 -> V_96 ( V_8 , V_70 -> V_19 , V_70 -> V_56 ) ;
V_81 -> V_97 ( V_81 -> V_2 , V_8 , V_70 -> V_19 ,
V_70 -> V_90 ) ;
V_59 -> V_70 = V_70 ;
V_59 -> V_8 = V_8 ;
V_59 -> V_62 = F_40 ( & V_72 -> V_68 , V_8 ,
V_59 , & V_98 ) ;
if ( F_7 ( V_59 -> V_62 ) ) {
error = F_41 ( V_59 -> V_62 ) ;
F_37 ( & V_72 -> V_68 , L_21 ,
V_8 , error ) ;
return error ;
}
return 0 ;
}
static void F_42 ( struct V_99 * V_100 )
{
F_43 ( V_100 ) ;
F_11 ( 10 , 20 ) ;
F_44 ( V_100 ) ;
}
static int F_45 ( struct V_95 * V_72 )
{
struct V_87 * V_88 = V_72 -> V_68 . V_101 ;
struct V_69 * V_70 ;
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
int V_67 ;
int V_71 ;
int error ;
V_103 = F_46 ( V_106 , V_88 ) ;
if ( ! V_103 )
return - V_107 ;
V_67 = F_47 ( V_72 , 0 ) ;
if ( V_67 < 0 ) {
F_37 ( & V_72 -> V_68 , L_22 ) ;
return - V_93 ;
}
V_70 = F_48 ( & V_72 -> V_68 , sizeof( struct V_69 ) ,
V_108 ) ;
if ( ! V_70 )
return - V_109 ;
V_70 -> V_72 = V_72 ;
V_70 -> V_73 = ( const struct V_80 * ) V_103 -> V_110 ;
if ( ! V_70 -> V_73 )
return - V_93 ;
V_105 = F_49 ( V_72 , V_111 , 0 ) ;
V_70 -> V_19 = F_50 ( & V_72 -> V_68 , V_105 ) ;
if ( F_7 ( V_70 -> V_19 ) )
return F_41 ( V_70 -> V_19 ) ;
V_70 -> V_100 = F_51 ( & V_72 -> V_68 , L_23 ) ;
if ( F_7 ( V_70 -> V_100 ) ) {
error = F_41 ( V_70 -> V_100 ) ;
F_37 ( & V_72 -> V_68 , L_24 , error ) ;
return error ;
}
V_70 -> V_112 = F_52 ( & V_72 -> V_68 , L_25 ) ;
if ( F_7 ( V_70 -> V_112 ) ) {
error = F_41 ( V_70 -> V_112 ) ;
F_37 ( & V_72 -> V_68 , L_26 , error ) ;
return error ;
}
V_70 -> V_113 = F_52 ( & V_72 -> V_68 , L_27 ) ;
if ( F_7 ( V_70 -> V_113 ) ) {
error = F_41 ( V_70 -> V_113 ) ;
F_37 ( & V_72 -> V_68 , L_28 ,
error ) ;
return error ;
}
error = F_53 ( V_70 -> V_112 ) ;
if ( error ) {
F_37 ( & V_72 -> V_68 , L_29 ,
error ) ;
return error ;
}
error = F_53 ( V_70 -> V_113 ) ;
if ( error ) {
F_37 ( & V_72 -> V_68 , L_30 , error ) ;
goto V_114;
}
F_42 ( V_70 -> V_100 ) ;
error = F_34 ( & V_72 -> V_68 , V_88 , V_70 ) ;
if ( error ) {
F_37 ( & V_72 -> V_68 , L_31 ,
error ) ;
goto V_115;
}
V_70 -> V_73 -> V_116 ( V_70 -> V_18 , V_70 -> V_19 ,
V_70 -> V_20 ) ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ ) {
error = F_39 ( V_72 , V_70 ,
& V_70 -> V_76 [ V_71 ] ,
V_70 -> V_73 -> V_117 [ V_71 ] ) ;
if ( error ) {
F_37 ( & V_72 -> V_68 ,
L_32 ,
V_71 , error ) ;
goto V_115;
}
}
error = F_54 ( & V_72 -> V_68 , V_67 , NULL ,
& F_29 ,
V_118 ,
L_33 , V_70 ) ;
if ( error ) {
F_37 ( & V_72 -> V_68 ,
L_34 , error ) ;
goto V_115;
}
V_70 -> V_73 -> V_119 ( V_70 -> V_19 , true ) ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ )
F_28 ( & V_70 -> V_76 [ V_71 ] , true ) ;
F_55 ( V_72 , V_70 ) ;
return 0 ;
V_115:
F_56 ( V_70 -> V_113 ) ;
V_114:
F_56 ( V_70 -> V_112 ) ;
return error ;
}
static int F_57 ( struct V_95 * V_72 )
{
struct V_69 * V_70 = F_58 ( V_72 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ ) {
struct V_58 * V_59 = & V_70 -> V_76 [ V_71 ] ;
F_28 ( V_59 , false ) ;
}
V_70 -> V_73 -> V_119 ( V_70 -> V_19 , false ) ;
F_56 ( V_70 -> V_113 ) ;
F_56 ( V_70 -> V_112 ) ;
return 0 ;
}
static int T_4 F_59 ( struct V_86 * V_68 )
{
struct V_95 * V_72 = F_60 ( V_68 ) ;
struct V_69 * V_70 = F_58 ( V_72 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ )
F_28 ( & V_70 -> V_76 [ V_71 ] , false ) ;
V_70 -> V_73 -> V_119 ( V_70 -> V_19 , false ) ;
F_61 ( V_70 -> V_113 ) ;
F_61 ( V_70 -> V_112 ) ;
F_62 ( V_68 ) ;
return 0 ;
}
static int T_4 F_63 ( struct V_86 * V_68 )
{
struct V_95 * V_72 = F_60 ( V_68 ) ;
struct V_69 * V_70 = F_58 ( V_72 ) ;
int V_71 ;
int error ;
error = F_64 ( V_70 -> V_112 ) ;
if ( error )
return error ;
error = F_64 ( V_70 -> V_113 ) ;
if ( error ) {
F_61 ( V_70 -> V_112 ) ;
return error ;
}
F_42 ( V_70 -> V_100 ) ;
V_70 -> V_73 -> V_116 ( V_70 -> V_18 , V_70 -> V_19 ,
V_70 -> V_20 ) ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ ) {
int V_8 = V_70 -> V_76 [ V_71 ] . V_8 ;
V_70 -> V_73 -> V_96 ( V_8 , V_70 -> V_19 ,
V_70 -> V_56 ) ;
V_70 -> V_73 -> V_97 ( V_70 -> V_73 -> V_2 ,
V_8 , V_70 -> V_19 ,
V_70 -> V_90 ) ;
}
V_70 -> V_73 -> V_119 ( V_70 -> V_19 , true ) ;
for ( V_71 = 0 ; V_71 < V_70 -> V_73 -> V_75 ; V_71 ++ )
F_28 ( & V_70 -> V_76 [ V_71 ] , true ) ;
F_65 ( V_68 ) ;
return 0 ;
}
