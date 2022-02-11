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
if ( V_9 >= V_2 . V_8 [ V_6 - 1 ] . V_9 &&
V_9 < V_2 . V_8 [ V_6 ] . V_9 )
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
V_10 = V_2 . V_8 [ V_6 ] . V_3 - V_17 [ V_6 - 1 ] . V_3 ;
V_10 *= abs ( V_2 . V_8 [ V_6 - 1 ] . V_9 - V_9 ) ;
V_11 = abs ( V_2 . V_8 [ V_6 - 1 ] . V_9 - V_2 . V_8 [ V_6 ] . V_9 ) ;
* V_3 = V_2 . V_8 [ V_6 - 1 ] . V_3 + ( V_10 / V_11 ) ;
return 0 ;
}
static void F_5 ( void T_2 * V_18 ,
enum V_19 V_19 )
{
if ( V_19 == V_20 )
F_6 ( 0U | V_21 ,
V_18 + V_22 ) ;
else
F_6 ( 0U & ~ V_21 ,
V_18 + V_22 ) ;
F_6 ( V_23 , V_18 + V_24 ) ;
F_6 ( V_25 ,
V_18 + V_26 ) ;
F_6 ( V_27 ,
V_18 + V_28 ) ;
F_6 ( V_29 ,
V_18 + V_30 ) ;
}
static void F_7 ( void T_2 * V_18 )
{
T_1 V_31 ;
V_31 = F_8 ( V_18 + V_32 ) ;
F_6 ( V_31 & V_33 , V_18 + V_32 ) ;
}
static void F_9 ( void T_2 * V_18 , bool V_34 )
{
T_1 V_31 ;
V_31 = F_8 ( V_18 + V_22 ) ;
if ( V_34 )
V_31 |= V_35 ;
else
V_31 &= ~ V_35 ;
F_6 ( V_31 , V_18 + V_22 ) ;
}
static int F_10 ( struct V_1 V_2 ,
int V_36 , void T_2 * V_18 , int * V_3 )
{
T_1 V_31 ;
V_31 = F_8 ( V_18 + F_11 ( V_36 ) ) ;
return F_2 ( V_2 , V_31 , V_3 ) ;
}
static void F_12 ( struct V_1 V_2 ,
int V_36 , void T_2 * V_18 , int V_3 )
{
T_1 V_37 , V_31 ;
V_37 = F_1 ( V_2 , V_3 ) ;
F_6 ( V_37 , V_18 + F_13 ( V_36 ) ) ;
V_31 = F_8 ( V_18 + V_22 ) ;
F_6 ( V_31 | F_14 ( V_36 ) , V_18 + V_22 ) ;
}
static void F_15 ( int V_36 , void T_2 * V_18 ,
enum V_38 V_12 )
{
T_1 V_31 ;
V_31 = F_8 ( V_18 + V_39 ) ;
if ( V_12 == V_40 ) {
V_31 &= ~ F_16 ( V_36 ) ;
V_31 |= F_17 ( V_36 ) ;
} else {
V_31 &= ~ F_17 ( V_36 ) ;
V_31 |= F_16 ( V_36 ) ;
}
F_6 ( V_31 , V_18 + V_39 ) ;
}
static void
F_18 ( struct V_41 * V_42 , bool V_43 )
{
struct V_44 * V_45 = V_42 -> V_45 ;
V_45 -> V_46 -> V_47 ( V_45 ,
V_43 ? V_48 : V_49 ) ;
}
static T_3 F_19 ( int V_50 , void * V_51 )
{
struct V_52 * V_53 = V_51 ;
int V_54 ;
F_20 ( & V_53 -> V_55 -> V_51 , L_2 ) ;
V_53 -> V_56 -> V_57 ( V_53 -> V_18 ) ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ )
F_21 ( V_53 -> V_59 [ V_54 ] . V_45 ) ;
return V_60 ;
}
static int F_22 ( void * V_61 , int * V_62 )
{
struct V_41 * V_42 = V_61 ;
struct V_52 * V_53 = V_42 -> V_53 ;
const struct V_63 * V_64 = V_42 -> V_53 -> V_56 ;
int V_65 ;
V_65 = V_64 -> V_66 ( V_64 -> V_2 ,
V_42 -> V_8 , V_53 -> V_18 , V_62 ) ;
F_20 ( & V_53 -> V_55 -> V_51 , L_3 ,
V_42 -> V_8 , * V_62 , V_65 ) ;
return V_65 ;
}
static int F_23 ( struct V_67 * V_51 ,
struct V_68 * V_69 ,
struct V_52 * V_53 )
{
T_1 V_70 , V_38 , V_19 ;
if ( F_24 ( V_69 , L_4 , & V_70 ) ) {
F_25 ( V_51 ,
L_5 ,
V_53 -> V_56 -> V_71 ) ;
V_53 -> V_71 = V_53 -> V_56 -> V_71 ;
} else {
V_53 -> V_71 = V_70 ;
}
if ( V_53 -> V_71 > V_72 ) {
F_26 ( V_51 , L_6 ,
V_53 -> V_71 ) ;
return - V_73 ;
}
if ( F_24 ( V_69 , L_7 , & V_38 ) ) {
F_25 ( V_51 ,
L_8 ,
V_53 -> V_56 -> V_38 == V_40 ?
L_9 : L_10 ) ;
V_53 -> V_38 = V_53 -> V_56 -> V_38 ;
} else {
V_53 -> V_38 = V_38 ;
}
if ( V_53 -> V_38 > 1 ) {
F_26 ( V_51 , L_11 ,
V_53 -> V_38 ) ;
return - V_74 ;
}
if ( F_24 ( V_69 , L_12 ,
& V_19 ) ) {
F_25 ( V_51 ,
L_13 ,
V_53 -> V_56 -> V_19 == V_75 ?
L_14 : L_15 ) ;
V_53 -> V_19 = V_53 -> V_56 -> V_19 ;
} else {
V_53 -> V_19 = V_19 ;
}
if ( V_53 -> V_19 > 1 ) {
F_26 ( V_51 , L_16 ,
V_53 -> V_19 ) ;
return - V_74 ;
}
return 0 ;
}
static int
F_27 ( struct V_76 * V_55 ,
struct V_52 * V_53 ,
struct V_41 * V_42 ,
int V_8 )
{
const struct V_63 * V_64 = V_53 -> V_56 ;
int error ;
V_64 -> V_77 ( V_8 , V_53 -> V_18 , V_53 -> V_38 ) ;
V_64 -> V_78 ( V_64 -> V_2 , V_8 , V_53 -> V_18 ,
V_53 -> V_71 ) ;
V_42 -> V_53 = V_53 ;
V_42 -> V_8 = V_8 ;
V_42 -> V_45 = F_28 ( & V_55 -> V_51 , V_8 , V_42 ,
& V_79 ) ;
if ( F_29 ( V_42 -> V_45 ) ) {
error = F_30 ( V_42 -> V_45 ) ;
F_26 ( & V_55 -> V_51 , L_17 ,
V_8 , error ) ;
return error ;
}
return 0 ;
}
static void F_31 ( struct V_80 * V_81 )
{
F_32 ( V_81 ) ;
F_33 ( 10 , 20 ) ;
F_34 ( V_81 ) ;
}
static int F_35 ( struct V_76 * V_55 )
{
struct V_68 * V_69 = V_55 -> V_51 . V_82 ;
struct V_52 * V_53 ;
const struct V_83 * V_84 ;
struct V_85 * V_86 ;
int V_50 ;
int V_54 , V_87 ;
int error ;
V_84 = F_36 ( V_88 , V_69 ) ;
if ( ! V_84 )
return - V_89 ;
V_50 = F_37 ( V_55 , 0 ) ;
if ( V_50 < 0 ) {
F_26 ( & V_55 -> V_51 , L_18 ) ;
return - V_74 ;
}
V_53 = F_38 ( & V_55 -> V_51 , sizeof( struct V_52 ) ,
V_90 ) ;
if ( ! V_53 )
return - V_91 ;
V_53 -> V_55 = V_55 ;
V_53 -> V_56 = ( const struct V_63 * ) V_84 -> V_92 ;
if ( ! V_53 -> V_56 )
return - V_74 ;
V_86 = F_39 ( V_55 , V_93 , 0 ) ;
V_53 -> V_18 = F_40 ( & V_55 -> V_51 , V_86 ) ;
if ( F_29 ( V_53 -> V_18 ) )
return F_30 ( V_53 -> V_18 ) ;
V_53 -> V_81 = F_41 ( & V_55 -> V_51 , L_19 ) ;
if ( F_29 ( V_53 -> V_81 ) ) {
error = F_30 ( V_53 -> V_81 ) ;
F_26 ( & V_55 -> V_51 , L_20 , error ) ;
return error ;
}
V_53 -> V_94 = F_42 ( & V_55 -> V_51 , L_21 ) ;
if ( F_29 ( V_53 -> V_94 ) ) {
error = F_30 ( V_53 -> V_94 ) ;
F_26 ( & V_55 -> V_51 , L_22 , error ) ;
return error ;
}
V_53 -> V_95 = F_42 ( & V_55 -> V_51 , L_23 ) ;
if ( F_29 ( V_53 -> V_95 ) ) {
error = F_30 ( V_53 -> V_95 ) ;
F_26 ( & V_55 -> V_51 , L_24 ,
error ) ;
return error ;
}
error = F_43 ( V_53 -> V_94 ) ;
if ( error ) {
F_26 ( & V_55 -> V_51 , L_25 ,
error ) ;
return error ;
}
error = F_43 ( V_53 -> V_95 ) ;
if ( error ) {
F_26 ( & V_55 -> V_51 , L_26 , error ) ;
goto V_96;
}
F_31 ( V_53 -> V_81 ) ;
error = F_23 ( & V_55 -> V_51 , V_69 , V_53 ) ;
if ( error ) {
F_26 ( & V_55 -> V_51 , L_27 ,
error ) ;
goto V_97;
}
V_53 -> V_56 -> V_98 ( V_53 -> V_18 , V_53 -> V_19 ) ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ ) {
error = F_27 ( V_55 , V_53 ,
& V_53 -> V_59 [ V_54 ] ,
V_53 -> V_56 -> V_99 [ V_54 ] ) ;
if ( error ) {
F_26 ( & V_55 -> V_51 ,
L_28 ,
V_54 , error ) ;
for ( V_87 = 0 ; V_87 < V_54 ; V_87 ++ )
F_44 ( & V_55 -> V_51 ,
V_53 -> V_59 [ V_87 ] . V_45 ) ;
goto V_97;
}
}
error = F_45 ( & V_55 -> V_51 , V_50 , NULL ,
& F_19 ,
V_100 ,
L_29 , V_53 ) ;
if ( error ) {
F_26 ( & V_55 -> V_51 ,
L_30 , error ) ;
goto V_101;
}
V_53 -> V_56 -> V_102 ( V_53 -> V_18 , true ) ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ )
F_18 ( & V_53 -> V_59 [ V_54 ] , true ) ;
F_46 ( V_55 , V_53 ) ;
return 0 ;
V_101:
while ( V_54 -- )
F_44 ( & V_55 -> V_51 ,
V_53 -> V_59 [ V_54 ] . V_45 ) ;
V_97:
F_47 ( V_53 -> V_95 ) ;
V_96:
F_47 ( V_53 -> V_94 ) ;
return error ;
}
static int F_48 ( struct V_76 * V_55 )
{
struct V_52 * V_53 = F_49 ( V_55 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ ) {
struct V_41 * V_42 = & V_53 -> V_59 [ V_54 ] ;
F_18 ( V_42 , false ) ;
F_44 ( & V_55 -> V_51 , V_42 -> V_45 ) ;
}
V_53 -> V_56 -> V_102 ( V_53 -> V_18 , false ) ;
F_47 ( V_53 -> V_95 ) ;
F_47 ( V_53 -> V_94 ) ;
return 0 ;
}
static int T_4 F_50 ( struct V_67 * V_51 )
{
struct V_76 * V_55 = F_51 ( V_51 ) ;
struct V_52 * V_53 = F_49 ( V_55 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ )
F_18 ( & V_53 -> V_59 [ V_54 ] , false ) ;
V_53 -> V_56 -> V_102 ( V_53 -> V_18 , false ) ;
F_52 ( V_53 -> V_95 ) ;
F_52 ( V_53 -> V_94 ) ;
F_53 ( V_51 ) ;
return 0 ;
}
static int T_4 F_54 ( struct V_67 * V_51 )
{
struct V_76 * V_55 = F_51 ( V_51 ) ;
struct V_52 * V_53 = F_49 ( V_55 ) ;
int V_54 ;
int error ;
error = F_55 ( V_53 -> V_94 ) ;
if ( error )
return error ;
error = F_55 ( V_53 -> V_95 ) ;
if ( error )
return error ;
F_31 ( V_53 -> V_81 ) ;
V_53 -> V_56 -> V_98 ( V_53 -> V_18 , V_53 -> V_19 ) ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ ) {
int V_8 = V_53 -> V_59 [ V_54 ] . V_8 ;
V_53 -> V_56 -> V_77 ( V_8 , V_53 -> V_18 ,
V_53 -> V_38 ) ;
V_53 -> V_56 -> V_78 ( V_53 -> V_56 -> V_2 ,
V_8 , V_53 -> V_18 ,
V_53 -> V_71 ) ;
}
V_53 -> V_56 -> V_102 ( V_53 -> V_18 , true ) ;
for ( V_54 = 0 ; V_54 < V_53 -> V_56 -> V_58 ; V_54 ++ )
F_18 ( & V_53 -> V_59 [ V_54 ] , true ) ;
F_56 ( V_51 ) ;
return 0 ;
}
