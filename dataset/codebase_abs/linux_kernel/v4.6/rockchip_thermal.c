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
V_10 = V_2 . V_8 [ V_6 ] . V_3 - V_2 . V_8 [ V_6 - 1 ] . V_3 ;
V_10 *= abs ( V_2 . V_8 [ V_6 - 1 ] . V_9 - V_9 ) ;
V_11 = abs ( V_2 . V_8 [ V_6 - 1 ] . V_9 - V_2 . V_8 [ V_6 ] . V_9 ) ;
* V_3 = V_2 . V_8 [ V_6 - 1 ] . V_3 + ( V_10 / V_11 ) ;
return 0 ;
}
static void F_5 ( void T_2 * V_17 ,
enum V_18 V_18 )
{
if ( V_18 == V_19 )
F_6 ( 0U | V_20 ,
V_17 + V_21 ) ;
else
F_6 ( 0U & ~ V_20 ,
V_17 + V_21 ) ;
F_6 ( V_22 , V_17 + V_23 ) ;
F_6 ( V_24 ,
V_17 + V_25 ) ;
F_6 ( V_26 ,
V_17 + V_27 ) ;
F_6 ( V_28 ,
V_17 + V_29 ) ;
}
static void F_7 ( void T_2 * V_17 )
{
T_1 V_30 ;
V_30 = F_8 ( V_17 + V_31 ) ;
F_6 ( V_30 & V_32 , V_17 + V_31 ) ;
}
static void F_9 ( void T_2 * V_17 )
{
T_1 V_30 ;
V_30 = F_8 ( V_17 + V_31 ) ;
F_6 ( V_30 & V_33 , V_17 + V_31 ) ;
}
static void F_10 ( void T_2 * V_17 , bool V_34 )
{
T_1 V_30 ;
V_30 = F_8 ( V_17 + V_21 ) ;
if ( V_34 )
V_30 |= V_35 ;
else
V_30 &= ~ V_35 ;
F_6 ( V_30 , V_17 + V_21 ) ;
}
static void F_11 ( void T_2 * V_17 , bool V_34 )
{
T_1 V_30 ;
V_30 = F_8 ( V_17 + V_21 ) ;
if ( V_34 )
V_30 |= V_35 | V_36 ;
else
V_30 &= ~ V_35 ;
F_6 ( V_30 , V_17 + V_21 ) ;
}
static int F_12 ( struct V_1 V_2 ,
int V_37 , void T_2 * V_17 , int * V_3 )
{
T_1 V_30 ;
V_30 = F_8 ( V_17 + F_13 ( V_37 ) ) ;
return F_2 ( V_2 , V_30 , V_3 ) ;
}
static void F_14 ( struct V_1 V_2 ,
int V_37 , void T_2 * V_17 , int V_3 )
{
T_1 V_38 , V_30 ;
V_38 = F_1 ( V_2 , V_3 ) ;
F_6 ( V_38 , V_17 + F_15 ( V_37 ) ) ;
V_30 = F_8 ( V_17 + V_21 ) ;
F_6 ( V_30 | F_16 ( V_37 ) , V_17 + V_21 ) ;
}
static void F_17 ( int V_37 , void T_2 * V_17 ,
enum V_39 V_12 )
{
T_1 V_30 ;
V_30 = F_8 ( V_17 + V_40 ) ;
if ( V_12 == V_41 ) {
V_30 &= ~ F_18 ( V_37 ) ;
V_30 |= F_19 ( V_37 ) ;
} else {
V_30 &= ~ F_19 ( V_37 ) ;
V_30 |= F_18 ( V_37 ) ;
}
F_6 ( V_30 , V_17 + V_40 ) ;
}
static void
F_20 ( struct V_42 * V_43 , bool V_44 )
{
struct V_45 * V_46 = V_43 -> V_46 ;
V_46 -> V_47 -> V_48 ( V_46 ,
V_44 ? V_49 : V_50 ) ;
}
static T_3 F_21 ( int V_51 , void * V_52 )
{
struct V_53 * V_54 = V_52 ;
int V_55 ;
F_22 ( & V_54 -> V_56 -> V_52 , L_2 ) ;
V_54 -> V_57 -> V_58 ( V_54 -> V_17 ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ )
F_23 ( V_54 -> V_60 [ V_55 ] . V_46 ) ;
return V_61 ;
}
static int F_24 ( void * V_62 , int * V_63 )
{
struct V_42 * V_43 = V_62 ;
struct V_53 * V_54 = V_43 -> V_54 ;
const struct V_64 * V_65 = V_43 -> V_54 -> V_57 ;
int V_66 ;
V_66 = V_65 -> V_67 ( V_65 -> V_2 ,
V_43 -> V_8 , V_54 -> V_17 , V_63 ) ;
F_22 ( & V_54 -> V_56 -> V_52 , L_3 ,
V_43 -> V_8 , * V_63 , V_66 ) ;
return V_66 ;
}
static int F_25 ( struct V_68 * V_52 ,
struct V_69 * V_70 ,
struct V_53 * V_54 )
{
T_1 V_71 , V_39 , V_18 ;
if ( F_26 ( V_70 , L_4 , & V_71 ) ) {
F_27 ( V_52 ,
L_5 ,
V_54 -> V_57 -> V_72 ) ;
V_54 -> V_72 = V_54 -> V_57 -> V_72 ;
} else {
if ( V_71 > V_73 ) {
F_28 ( V_52 , L_6 ,
V_71 ) ;
return - V_74 ;
}
V_54 -> V_72 = V_71 ;
}
if ( F_26 ( V_70 , L_7 , & V_39 ) ) {
F_27 ( V_52 ,
L_8 ,
V_54 -> V_57 -> V_39 == V_41 ?
L_9 : L_10 ) ;
V_54 -> V_39 = V_54 -> V_57 -> V_39 ;
} else {
V_54 -> V_39 = V_39 ;
}
if ( V_54 -> V_39 > 1 ) {
F_28 ( V_52 , L_11 ,
V_54 -> V_39 ) ;
return - V_75 ;
}
if ( F_26 ( V_70 , L_12 ,
& V_18 ) ) {
F_27 ( V_52 ,
L_13 ,
V_54 -> V_57 -> V_18 == V_76 ?
L_14 : L_15 ) ;
V_54 -> V_18 = V_54 -> V_57 -> V_18 ;
} else {
V_54 -> V_18 = V_18 ;
}
if ( V_54 -> V_18 > 1 ) {
F_28 ( V_52 , L_16 ,
V_54 -> V_18 ) ;
return - V_75 ;
}
return 0 ;
}
static int
F_29 ( struct V_77 * V_56 ,
struct V_53 * V_54 ,
struct V_42 * V_43 ,
int V_8 )
{
const struct V_64 * V_65 = V_54 -> V_57 ;
int error ;
V_65 -> V_78 ( V_8 , V_54 -> V_17 , V_54 -> V_39 ) ;
V_65 -> V_79 ( V_65 -> V_2 , V_8 , V_54 -> V_17 ,
V_54 -> V_72 ) ;
V_43 -> V_54 = V_54 ;
V_43 -> V_8 = V_8 ;
V_43 -> V_46 = F_30 ( & V_56 -> V_52 , V_8 , V_43 ,
& V_80 ) ;
if ( F_31 ( V_43 -> V_46 ) ) {
error = F_32 ( V_43 -> V_46 ) ;
F_28 ( & V_56 -> V_52 , L_17 ,
V_8 , error ) ;
return error ;
}
return 0 ;
}
static void F_33 ( struct V_81 * V_82 )
{
F_34 ( V_82 ) ;
F_35 ( 10 , 20 ) ;
F_36 ( V_82 ) ;
}
static int F_37 ( struct V_77 * V_56 )
{
struct V_69 * V_70 = V_56 -> V_52 . V_83 ;
struct V_53 * V_54 ;
const struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_51 ;
int V_55 , V_88 ;
int error ;
V_85 = F_38 ( V_89 , V_70 ) ;
if ( ! V_85 )
return - V_90 ;
V_51 = F_39 ( V_56 , 0 ) ;
if ( V_51 < 0 ) {
F_28 ( & V_56 -> V_52 , L_18 ) ;
return - V_75 ;
}
V_54 = F_40 ( & V_56 -> V_52 , sizeof( struct V_53 ) ,
V_91 ) ;
if ( ! V_54 )
return - V_92 ;
V_54 -> V_56 = V_56 ;
V_54 -> V_57 = ( const struct V_64 * ) V_85 -> V_93 ;
if ( ! V_54 -> V_57 )
return - V_75 ;
V_87 = F_41 ( V_56 , V_94 , 0 ) ;
V_54 -> V_17 = F_42 ( & V_56 -> V_52 , V_87 ) ;
if ( F_31 ( V_54 -> V_17 ) )
return F_32 ( V_54 -> V_17 ) ;
V_54 -> V_82 = F_43 ( & V_56 -> V_52 , L_19 ) ;
if ( F_31 ( V_54 -> V_82 ) ) {
error = F_32 ( V_54 -> V_82 ) ;
F_28 ( & V_56 -> V_52 , L_20 , error ) ;
return error ;
}
V_54 -> V_95 = F_44 ( & V_56 -> V_52 , L_21 ) ;
if ( F_31 ( V_54 -> V_95 ) ) {
error = F_32 ( V_54 -> V_95 ) ;
F_28 ( & V_56 -> V_52 , L_22 , error ) ;
return error ;
}
V_54 -> V_96 = F_44 ( & V_56 -> V_52 , L_23 ) ;
if ( F_31 ( V_54 -> V_96 ) ) {
error = F_32 ( V_54 -> V_96 ) ;
F_28 ( & V_56 -> V_52 , L_24 ,
error ) ;
return error ;
}
error = F_45 ( V_54 -> V_95 ) ;
if ( error ) {
F_28 ( & V_56 -> V_52 , L_25 ,
error ) ;
return error ;
}
error = F_45 ( V_54 -> V_96 ) ;
if ( error ) {
F_28 ( & V_56 -> V_52 , L_26 , error ) ;
goto V_97;
}
F_33 ( V_54 -> V_82 ) ;
error = F_25 ( & V_56 -> V_52 , V_70 , V_54 ) ;
if ( error ) {
F_28 ( & V_56 -> V_52 , L_27 ,
error ) ;
goto V_98;
}
V_54 -> V_57 -> V_99 ( V_54 -> V_17 , V_54 -> V_18 ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ ) {
error = F_29 ( V_56 , V_54 ,
& V_54 -> V_60 [ V_55 ] ,
V_54 -> V_57 -> V_100 [ V_55 ] ) ;
if ( error ) {
F_28 ( & V_56 -> V_52 ,
L_28 ,
V_55 , error ) ;
for ( V_88 = 0 ; V_88 < V_55 ; V_88 ++ )
F_46 ( & V_56 -> V_52 ,
V_54 -> V_60 [ V_88 ] . V_46 ) ;
goto V_98;
}
}
error = F_47 ( & V_56 -> V_52 , V_51 , NULL ,
& F_21 ,
V_101 ,
L_29 , V_54 ) ;
if ( error ) {
F_28 ( & V_56 -> V_52 ,
L_30 , error ) ;
goto V_102;
}
V_54 -> V_57 -> V_103 ( V_54 -> V_17 , true ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ )
F_20 ( & V_54 -> V_60 [ V_55 ] , true ) ;
F_48 ( V_56 , V_54 ) ;
return 0 ;
V_102:
while ( V_55 -- )
F_46 ( & V_56 -> V_52 ,
V_54 -> V_60 [ V_55 ] . V_46 ) ;
V_98:
F_49 ( V_54 -> V_96 ) ;
V_97:
F_49 ( V_54 -> V_95 ) ;
return error ;
}
static int F_50 ( struct V_77 * V_56 )
{
struct V_53 * V_54 = F_51 ( V_56 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ ) {
struct V_42 * V_43 = & V_54 -> V_60 [ V_55 ] ;
F_20 ( V_43 , false ) ;
F_46 ( & V_56 -> V_52 , V_43 -> V_46 ) ;
}
V_54 -> V_57 -> V_103 ( V_54 -> V_17 , false ) ;
F_49 ( V_54 -> V_96 ) ;
F_49 ( V_54 -> V_95 ) ;
return 0 ;
}
static int T_4 F_52 ( struct V_68 * V_52 )
{
struct V_77 * V_56 = F_53 ( V_52 ) ;
struct V_53 * V_54 = F_51 ( V_56 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ )
F_20 ( & V_54 -> V_60 [ V_55 ] , false ) ;
V_54 -> V_57 -> V_103 ( V_54 -> V_17 , false ) ;
F_54 ( V_54 -> V_96 ) ;
F_54 ( V_54 -> V_95 ) ;
F_55 ( V_52 ) ;
return 0 ;
}
static int T_4 F_56 ( struct V_68 * V_52 )
{
struct V_77 * V_56 = F_53 ( V_52 ) ;
struct V_53 * V_54 = F_51 ( V_56 ) ;
int V_55 ;
int error ;
error = F_57 ( V_54 -> V_95 ) ;
if ( error )
return error ;
error = F_57 ( V_54 -> V_96 ) ;
if ( error )
return error ;
F_33 ( V_54 -> V_82 ) ;
V_54 -> V_57 -> V_99 ( V_54 -> V_17 , V_54 -> V_18 ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ ) {
int V_8 = V_54 -> V_60 [ V_55 ] . V_8 ;
V_54 -> V_57 -> V_78 ( V_8 , V_54 -> V_17 ,
V_54 -> V_39 ) ;
V_54 -> V_57 -> V_79 ( V_54 -> V_57 -> V_2 ,
V_8 , V_54 -> V_17 ,
V_54 -> V_72 ) ;
}
V_54 -> V_57 -> V_103 ( V_54 -> V_17 , true ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 -> V_59 ; V_55 ++ )
F_20 ( & V_54 -> V_60 [ V_55 ] , true ) ;
F_58 ( V_52 ) ;
return 0 ;
}
