static T_1 F_1 ( struct V_1 V_2 ,
int V_3 )
{
int V_4 , V_5 , V_6 ;
V_5 = 0 ;
V_4 = V_2 . V_7 - 1 ;
V_6 = ( V_4 + V_5 ) / 2 ;
if ( V_3 < V_2 . V_8 [ V_5 ] . V_3 || V_3 > V_2 . V_8 [ V_4 ] . V_3 )
return 0 ;
while ( V_5 <= V_4 ) {
if ( V_3 == V_2 . V_8 [ V_6 ] . V_3 )
return V_2 . V_8 [ V_6 ] . V_9 ;
else if ( V_3 < V_2 . V_8 [ V_6 ] . V_3 )
V_4 = V_6 - 1 ;
else
V_5 = V_6 + 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
return 0 ;
}
static int F_2 ( struct V_1 V_2 , T_1 V_9 ,
int * V_3 )
{
unsigned int V_5 = 1 ;
unsigned int V_4 = V_2 . V_7 - 1 ;
unsigned int V_6 = ( V_5 + V_4 ) / 2 ;
unsigned int V_10 ;
unsigned long V_11 ;
F_3 ( V_2 . V_7 < 2 ) ;
switch ( V_2 . V_12 ) {
case V_13 :
V_9 &= V_2 . V_14 ;
if ( V_9 < V_2 . V_8 [ V_4 ] . V_9 )
return - V_15 ;
while ( V_5 <= V_4 ) {
if ( V_9 >= V_2 . V_8 [ V_6 ] . V_9 &&
V_9 < V_2 . V_8 [ V_6 - 1 ] . V_9 )
break;
else if ( V_9 < V_2 . V_8 [ V_6 ] . V_9 )
V_5 = V_6 + 1 ;
else
V_4 = V_6 - 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
break;
case V_16 :
V_9 &= V_2 . V_14 ;
if ( V_9 < V_2 . V_8 [ V_5 ] . V_9 )
return - V_15 ;
while ( V_5 <= V_4 ) {
if ( V_9 <= V_2 . V_8 [ V_6 ] . V_9 &&
V_9 > V_2 . V_8 [ V_6 - 1 ] . V_9 )
break;
else if ( V_9 > V_2 . V_8 [ V_6 ] . V_9 )
V_5 = V_6 + 1 ;
else
V_4 = V_6 - 1 ;
V_6 = ( V_5 + V_4 ) / 2 ;
}
break;
default:
F_4 ( L_1 ) ;
}
V_10 = V_2 . V_8 [ V_6 ] . V_3 - V_2 . V_8 [ V_6 - 1 ] . V_3 ;
V_10 *= abs ( V_2 . V_8 [ V_6 - 1 ] . V_9 - V_9 ) ;
V_11 = abs ( V_2 . V_8 [ V_6 - 1 ] . V_9 - V_2 . V_8 [ V_6 ] . V_9 ) ;
* V_3 = V_2 . V_8 [ V_6 - 1 ] . V_3 + ( V_10 / V_11 ) ;
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
F_8 ( L_2 , V_32 ) ;
return;
}
}
static void F_9 ( struct V_17 * V_18 , void T_2 * V_19 ,
enum V_20 V_20 )
{
if ( F_7 ( V_18 ) ) {
F_6 ( V_33 , V_19 +
V_34 ) ;
} else {
F_10 ( V_18 , V_35 , V_36 ) ;
F_11 ( 10 ) ;
F_10 ( V_18 , V_35 , V_37 ) ;
F_12 ( 15 , 100 ) ;
F_10 ( V_18 , V_38 , V_39 ) ;
F_10 ( V_18 , V_40 , V_41 ) ;
F_12 ( 90 , 200 ) ;
}
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
}
static void F_13 ( void T_2 * V_19 )
{
T_1 V_42 ;
V_42 = F_14 ( V_19 + V_43 ) ;
F_6 ( V_42 & V_44 , V_19 + V_43 ) ;
}
static void F_15 ( void T_2 * V_19 )
{
T_1 V_42 ;
V_42 = F_14 ( V_19 + V_43 ) ;
F_6 ( V_42 & V_45 , V_19 + V_43 ) ;
}
static void F_16 ( void T_2 * V_19 , bool V_46 )
{
T_1 V_42 ;
V_42 = F_14 ( V_19 + V_23 ) ;
if ( V_46 )
V_42 |= V_47 ;
else
V_42 &= ~ V_47 ;
F_6 ( V_42 , V_19 + V_23 ) ;
}
static void F_17 ( void T_2 * V_19 , bool V_46 )
{
T_1 V_42 ;
V_42 = F_14 ( V_19 + V_23 ) ;
if ( V_46 )
V_42 |= V_47 | V_48 ;
else
V_42 &= ~ V_47 ;
F_6 ( V_42 , V_19 + V_23 ) ;
}
static int F_18 ( struct V_1 V_2 ,
int V_49 , void T_2 * V_19 , int * V_3 )
{
T_1 V_42 ;
V_42 = F_14 ( V_19 + F_19 ( V_49 ) ) ;
return F_2 ( V_2 , V_42 , V_3 ) ;
}
static void F_20 ( struct V_1 V_2 ,
int V_49 , void T_2 * V_19 , int V_3 )
{
T_1 V_50 , V_42 ;
V_50 = F_1 ( V_2 , V_3 ) ;
F_6 ( V_50 , V_19 + F_21 ( V_49 ) ) ;
V_42 = F_14 ( V_19 + V_23 ) ;
F_6 ( V_42 | F_22 ( V_49 ) , V_19 + V_23 ) ;
}
static void F_23 ( int V_49 , void T_2 * V_19 ,
enum V_51 V_12 )
{
T_1 V_42 ;
V_42 = F_14 ( V_19 + V_52 ) ;
if ( V_12 == V_53 ) {
V_42 &= ~ F_24 ( V_49 ) ;
V_42 |= F_25 ( V_49 ) ;
} else {
V_42 &= ~ F_25 ( V_49 ) ;
V_42 |= F_24 ( V_49 ) ;
}
F_6 ( V_42 , V_19 + V_52 ) ;
}
static void
F_26 ( struct V_54 * V_55 , bool V_56 )
{
struct V_57 * V_58 = V_55 -> V_58 ;
V_58 -> V_59 -> V_60 ( V_58 ,
V_56 ? V_61 : V_62 ) ;
}
static T_3 F_27 ( int V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
int V_67 ;
F_28 ( & V_66 -> V_68 -> V_64 , L_3 ) ;
V_66 -> V_69 -> V_70 ( V_66 -> V_19 ) ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ )
F_29 ( V_66 -> V_72 [ V_67 ] . V_58 ) ;
return V_73 ;
}
static int F_30 ( void * V_74 , int * V_75 )
{
struct V_54 * V_55 = V_74 ;
struct V_65 * V_66 = V_55 -> V_66 ;
const struct V_76 * V_77 = V_55 -> V_66 -> V_69 ;
int V_78 ;
V_78 = V_77 -> V_79 ( V_77 -> V_2 ,
V_55 -> V_8 , V_66 -> V_19 , V_75 ) ;
F_28 ( & V_66 -> V_68 -> V_64 , L_4 ,
V_55 -> V_8 , * V_75 , V_78 ) ;
return V_78 ;
}
static int F_31 ( struct V_80 * V_64 ,
struct V_81 * V_82 ,
struct V_65 * V_66 )
{
T_1 V_83 , V_51 , V_20 ;
if ( F_32 ( V_82 , L_5 , & V_83 ) ) {
F_33 ( V_64 ,
L_6 ,
V_66 -> V_69 -> V_84 ) ;
V_66 -> V_84 = V_66 -> V_69 -> V_84 ;
} else {
if ( V_83 > V_85 ) {
F_34 ( V_64 , L_7 ,
V_83 ) ;
return - V_86 ;
}
V_66 -> V_84 = V_83 ;
}
if ( F_32 ( V_82 , L_8 , & V_51 ) ) {
F_33 ( V_64 ,
L_9 ,
V_66 -> V_69 -> V_51 == V_53 ?
L_10 : L_11 ) ;
V_66 -> V_51 = V_66 -> V_69 -> V_51 ;
} else {
V_66 -> V_51 = V_51 ;
}
if ( V_66 -> V_51 > 1 ) {
F_34 ( V_64 , L_12 ,
V_66 -> V_51 ) ;
return - V_87 ;
}
if ( F_32 ( V_82 , L_13 ,
& V_20 ) ) {
F_33 ( V_64 ,
L_14 ,
V_66 -> V_69 -> V_20 == V_88 ?
L_15 : L_16 ) ;
V_66 -> V_20 = V_66 -> V_69 -> V_20 ;
} else {
V_66 -> V_20 = V_20 ;
}
if ( V_66 -> V_20 > 1 ) {
F_34 ( V_64 , L_17 ,
V_66 -> V_20 ) ;
return - V_87 ;
}
V_66 -> V_18 = F_35 ( V_82 , L_18 ) ;
return 0 ;
}
static int
F_36 ( struct V_89 * V_68 ,
struct V_65 * V_66 ,
struct V_54 * V_55 ,
int V_8 )
{
const struct V_76 * V_77 = V_66 -> V_69 ;
int error ;
V_77 -> V_90 ( V_8 , V_66 -> V_19 , V_66 -> V_51 ) ;
V_77 -> V_91 ( V_77 -> V_2 , V_8 , V_66 -> V_19 ,
V_66 -> V_84 ) ;
V_55 -> V_66 = V_66 ;
V_55 -> V_8 = V_8 ;
V_55 -> V_58 = F_37 ( & V_68 -> V_64 , V_8 ,
V_55 , & V_92 ) ;
if ( F_7 ( V_55 -> V_58 ) ) {
error = F_38 ( V_55 -> V_58 ) ;
F_34 ( & V_68 -> V_64 , L_19 ,
V_8 , error ) ;
return error ;
}
return 0 ;
}
static void F_39 ( struct V_93 * V_94 )
{
F_40 ( V_94 ) ;
F_12 ( 10 , 20 ) ;
F_41 ( V_94 ) ;
}
static int F_42 ( struct V_89 * V_68 )
{
struct V_81 * V_82 = V_68 -> V_64 . V_95 ;
struct V_65 * V_66 ;
const struct V_96 * V_97 ;
struct V_98 * V_99 ;
int V_63 ;
int V_67 ;
int error ;
V_97 = F_43 ( V_100 , V_82 ) ;
if ( ! V_97 )
return - V_101 ;
V_63 = F_44 ( V_68 , 0 ) ;
if ( V_63 < 0 ) {
F_34 ( & V_68 -> V_64 , L_20 ) ;
return - V_87 ;
}
V_66 = F_45 ( & V_68 -> V_64 , sizeof( struct V_65 ) ,
V_102 ) ;
if ( ! V_66 )
return - V_103 ;
V_66 -> V_68 = V_68 ;
V_66 -> V_69 = ( const struct V_76 * ) V_97 -> V_104 ;
if ( ! V_66 -> V_69 )
return - V_87 ;
V_99 = F_46 ( V_68 , V_105 , 0 ) ;
V_66 -> V_19 = F_47 ( & V_68 -> V_64 , V_99 ) ;
if ( F_7 ( V_66 -> V_19 ) )
return F_38 ( V_66 -> V_19 ) ;
V_66 -> V_94 = F_48 ( & V_68 -> V_64 , L_21 ) ;
if ( F_7 ( V_66 -> V_94 ) ) {
error = F_38 ( V_66 -> V_94 ) ;
F_34 ( & V_68 -> V_64 , L_22 , error ) ;
return error ;
}
V_66 -> V_106 = F_49 ( & V_68 -> V_64 , L_23 ) ;
if ( F_7 ( V_66 -> V_106 ) ) {
error = F_38 ( V_66 -> V_106 ) ;
F_34 ( & V_68 -> V_64 , L_24 , error ) ;
return error ;
}
V_66 -> V_107 = F_49 ( & V_68 -> V_64 , L_25 ) ;
if ( F_7 ( V_66 -> V_107 ) ) {
error = F_38 ( V_66 -> V_107 ) ;
F_34 ( & V_68 -> V_64 , L_26 ,
error ) ;
return error ;
}
error = F_50 ( V_66 -> V_106 ) ;
if ( error ) {
F_34 ( & V_68 -> V_64 , L_27 ,
error ) ;
return error ;
}
error = F_50 ( V_66 -> V_107 ) ;
if ( error ) {
F_34 ( & V_68 -> V_64 , L_28 , error ) ;
goto V_108;
}
F_39 ( V_66 -> V_94 ) ;
error = F_31 ( & V_68 -> V_64 , V_82 , V_66 ) ;
if ( error ) {
F_34 ( & V_68 -> V_64 , L_29 ,
error ) ;
goto V_109;
}
V_66 -> V_69 -> V_110 ( V_66 -> V_18 , V_66 -> V_19 ,
V_66 -> V_20 ) ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ ) {
error = F_36 ( V_68 , V_66 ,
& V_66 -> V_72 [ V_67 ] ,
V_66 -> V_69 -> V_111 [ V_67 ] ) ;
if ( error ) {
F_34 ( & V_68 -> V_64 ,
L_30 ,
V_67 , error ) ;
goto V_109;
}
}
error = F_51 ( & V_68 -> V_64 , V_63 , NULL ,
& F_27 ,
V_112 ,
L_31 , V_66 ) ;
if ( error ) {
F_34 ( & V_68 -> V_64 ,
L_32 , error ) ;
goto V_109;
}
V_66 -> V_69 -> V_113 ( V_66 -> V_19 , true ) ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ )
F_26 ( & V_66 -> V_72 [ V_67 ] , true ) ;
F_52 ( V_68 , V_66 ) ;
return 0 ;
V_109:
F_53 ( V_66 -> V_107 ) ;
V_108:
F_53 ( V_66 -> V_106 ) ;
return error ;
}
static int F_54 ( struct V_89 * V_68 )
{
struct V_65 * V_66 = F_55 ( V_68 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ ) {
struct V_54 * V_55 = & V_66 -> V_72 [ V_67 ] ;
F_26 ( V_55 , false ) ;
}
V_66 -> V_69 -> V_113 ( V_66 -> V_19 , false ) ;
F_53 ( V_66 -> V_107 ) ;
F_53 ( V_66 -> V_106 ) ;
return 0 ;
}
static int T_4 F_56 ( struct V_80 * V_64 )
{
struct V_89 * V_68 = F_57 ( V_64 ) ;
struct V_65 * V_66 = F_55 ( V_68 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ )
F_26 ( & V_66 -> V_72 [ V_67 ] , false ) ;
V_66 -> V_69 -> V_113 ( V_66 -> V_19 , false ) ;
F_58 ( V_66 -> V_107 ) ;
F_58 ( V_66 -> V_106 ) ;
F_59 ( V_64 ) ;
return 0 ;
}
static int T_4 F_60 ( struct V_80 * V_64 )
{
struct V_89 * V_68 = F_57 ( V_64 ) ;
struct V_65 * V_66 = F_55 ( V_68 ) ;
int V_67 ;
int error ;
error = F_61 ( V_66 -> V_106 ) ;
if ( error )
return error ;
error = F_61 ( V_66 -> V_107 ) ;
if ( error ) {
F_58 ( V_66 -> V_106 ) ;
return error ;
}
F_39 ( V_66 -> V_94 ) ;
V_66 -> V_69 -> V_110 ( V_66 -> V_18 , V_66 -> V_19 ,
V_66 -> V_20 ) ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ ) {
int V_8 = V_66 -> V_72 [ V_67 ] . V_8 ;
V_66 -> V_69 -> V_90 ( V_8 , V_66 -> V_19 ,
V_66 -> V_51 ) ;
V_66 -> V_69 -> V_91 ( V_66 -> V_69 -> V_2 ,
V_8 , V_66 -> V_19 ,
V_66 -> V_84 ) ;
}
V_66 -> V_69 -> V_113 ( V_66 -> V_19 , true ) ;
for ( V_67 = 0 ; V_67 < V_66 -> V_69 -> V_71 ; V_67 ++ )
F_26 ( & V_66 -> V_72 [ V_67 ] , true ) ;
F_62 ( V_64 ) ;
return 0 ;
}
