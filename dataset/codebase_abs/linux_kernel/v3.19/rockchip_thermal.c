static T_1 F_1 ( long V_1 )
{
int V_2 , V_3 , V_4 ;
V_3 = 0 ;
V_2 = F_2 ( V_5 ) - 1 ;
V_4 = ( V_2 + V_3 ) / 2 ;
if ( V_1 < V_5 [ V_3 ] . V_1 || V_1 > V_5 [ V_2 ] . V_1 )
return 0 ;
while ( V_3 <= V_2 ) {
if ( V_1 == V_5 [ V_4 ] . V_1 )
return V_5 [ V_4 ] . V_6 ;
else if ( V_1 < V_5 [ V_4 ] . V_1 )
V_2 = V_4 - 1 ;
else
V_3 = V_4 + 1 ;
V_4 = ( V_3 + V_2 ) / 2 ;
}
return 0 ;
}
static long F_3 ( T_1 V_6 )
{
int V_2 , V_3 , V_4 ;
V_3 = 0 ;
V_2 = F_2 ( V_5 ) - 1 ;
V_4 = ( V_2 + V_3 ) / 2 ;
if ( V_6 > V_5 [ V_3 ] . V_6 || V_6 < V_5 [ V_2 ] . V_6 )
return 125000 ;
while ( V_3 <= V_2 ) {
if ( V_6 >= V_5 [ V_4 ] . V_6 && V_6 <
V_5 [ V_4 - 1 ] . V_6 )
return V_5 [ V_4 ] . V_1 ;
else if ( V_6 < V_5 [ V_4 ] . V_6 )
V_3 = V_4 + 1 ;
else
V_2 = V_4 - 1 ;
V_4 = ( V_3 + V_2 ) / 2 ;
}
return 125000 ;
}
static void F_4 ( void T_2 * V_7 ,
enum V_8 V_8 )
{
if ( V_8 == V_9 )
F_5 ( 0 | ( V_10 ) ,
V_7 + V_11 ) ;
else
F_5 ( 0 | ( V_12 ) ,
V_7 + V_11 ) ;
F_5 ( V_13 , V_7 + V_14 ) ;
F_5 ( V_15 ,
V_7 + V_16 ) ;
F_5 ( V_17 ,
V_7 + V_18 ) ;
F_5 ( V_19 ,
V_7 + V_20 ) ;
}
static void F_6 ( void T_2 * V_7 )
{
T_1 V_21 ;
V_21 = F_7 ( V_7 + V_22 ) ;
F_5 ( V_21 & V_23 , V_7 + V_22 ) ;
}
static void F_8 ( void T_2 * V_7 , bool V_24 )
{
T_1 V_21 ;
V_21 = F_7 ( V_7 + V_11 ) ;
if ( V_24 )
V_21 |= V_25 ;
else
V_21 &= ~ V_25 ;
F_5 ( V_21 , V_7 + V_11 ) ;
}
static int F_9 ( int V_26 , void T_2 * V_7 , long * V_1 )
{
T_1 V_21 ;
V_21 = F_7 ( V_7 + F_10 ( V_26 ) ) ;
if ( V_21 == 0 )
return - V_27 ;
* V_1 = F_3 ( V_21 ) ;
return 0 ;
}
static void F_11 ( int V_26 , void T_2 * V_7 , long V_1 )
{
T_1 V_28 , V_21 ;
V_28 = F_1 ( V_1 ) ;
F_5 ( V_28 , V_7 + F_12 ( V_26 ) ) ;
V_21 = F_7 ( V_7 + V_11 ) ;
F_5 ( V_21 | F_13 ( V_26 ) , V_7 + V_11 ) ;
}
static void F_14 ( int V_26 , void T_2 * V_7 ,
enum V_29 V_30 )
{
T_1 V_21 ;
V_21 = F_7 ( V_7 + V_31 ) ;
if ( V_30 == V_32 ) {
V_21 &= ~ F_15 ( V_26 ) ;
V_21 |= F_16 ( V_26 ) ;
} else {
V_21 &= ~ F_16 ( V_26 ) ;
V_21 |= F_15 ( V_26 ) ;
}
F_5 ( V_21 , V_7 + V_31 ) ;
}
static void
F_17 ( struct V_33 * V_34 , bool V_35 )
{
struct V_36 * V_37 = V_34 -> V_37 ;
V_37 -> V_38 -> V_39 ( V_37 ,
V_35 ? V_40 : V_41 ) ;
}
static T_3 F_18 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
int V_46 ;
F_19 ( & V_45 -> V_47 -> V_43 , L_1 ) ;
V_45 -> V_48 -> V_49 ( V_45 -> V_7 ) ;
for ( V_46 = 0 ; V_46 < F_2 ( V_45 -> V_50 ) ; V_46 ++ )
F_20 ( V_45 -> V_50 [ V_46 ] . V_37 ) ;
return V_51 ;
}
static int F_21 ( void * V_52 , long * V_53 )
{
struct V_33 * V_34 = V_52 ;
struct V_44 * V_45 = V_34 -> V_45 ;
const struct V_54 * V_55 = V_34 -> V_45 -> V_48 ;
int V_56 ;
V_56 = V_55 -> V_57 ( V_34 -> V_58 , V_45 -> V_7 , V_53 ) ;
F_19 ( & V_45 -> V_47 -> V_43 , L_2 ,
V_34 -> V_58 , * V_53 , V_56 ) ;
return V_56 ;
}
static int F_22 ( struct V_59 * V_43 ,
struct V_60 * V_61 ,
struct V_44 * V_45 )
{
T_1 V_62 , V_29 , V_8 ;
if ( F_23 ( V_61 , L_3 , & V_62 ) ) {
F_24 ( V_43 ,
L_4 ,
V_45 -> V_48 -> V_63 ) ;
V_45 -> V_63 = V_45 -> V_48 -> V_63 ;
} else {
V_45 -> V_63 = V_62 ;
}
if ( V_45 -> V_63 > V_64 ) {
F_25 ( V_43 , L_5 ,
V_45 -> V_63 ) ;
return - V_65 ;
}
if ( F_23 ( V_61 , L_6 , & V_29 ) ) {
F_24 ( V_43 ,
L_7 ,
V_45 -> V_48 -> V_29 == V_32 ?
L_8 : L_9 ) ;
V_45 -> V_29 = V_45 -> V_48 -> V_29 ;
} else {
V_45 -> V_29 = V_29 ;
}
if ( V_45 -> V_29 > 1 ) {
F_25 ( V_43 , L_10 ,
V_45 -> V_29 ) ;
return - V_66 ;
}
if ( F_23 ( V_61 , L_11 ,
& V_8 ) ) {
F_24 ( V_43 ,
L_12 ,
V_45 -> V_48 -> V_8 == V_67 ?
L_13 : L_14 ) ;
V_45 -> V_8 = V_45 -> V_48 -> V_8 ;
} else {
V_45 -> V_8 = V_8 ;
}
if ( V_45 -> V_8 > 1 ) {
F_25 ( V_43 , L_15 ,
V_45 -> V_8 ) ;
return - V_66 ;
}
return 0 ;
}
static int
F_26 ( struct V_68 * V_47 ,
struct V_44 * V_45 ,
struct V_33 * V_34 ,
enum V_69 V_58 )
{
const struct V_54 * V_55 = V_45 -> V_48 ;
int error ;
V_55 -> V_70 ( V_58 , V_45 -> V_7 , V_45 -> V_29 ) ;
V_55 -> V_71 ( V_58 , V_45 -> V_7 , V_45 -> V_63 ) ;
V_34 -> V_45 = V_45 ;
V_34 -> V_58 = V_58 ;
V_34 -> V_37 = F_27 ( & V_47 -> V_43 , V_58 , V_34 ,
& V_72 ) ;
if ( F_28 ( V_34 -> V_37 ) ) {
error = F_29 ( V_34 -> V_37 ) ;
F_25 ( & V_47 -> V_43 , L_16 ,
V_58 , error ) ;
return error ;
}
return 0 ;
}
static void F_30 ( struct V_73 * V_74 )
{
F_31 ( V_74 ) ;
F_32 ( 10 , 20 ) ;
F_33 ( V_74 ) ;
}
static int F_34 ( struct V_68 * V_47 )
{
struct V_60 * V_61 = V_47 -> V_43 . V_75 ;
struct V_44 * V_45 ;
const struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_42 ;
int V_46 ;
int error ;
V_77 = F_35 ( V_80 , V_61 ) ;
if ( ! V_77 )
return - V_81 ;
V_42 = F_36 ( V_47 , 0 ) ;
if ( V_42 < 0 ) {
F_25 ( & V_47 -> V_43 , L_17 ) ;
return - V_66 ;
}
V_45 = F_37 ( & V_47 -> V_43 , sizeof( struct V_44 ) ,
V_82 ) ;
if ( ! V_45 )
return - V_83 ;
V_45 -> V_47 = V_47 ;
V_45 -> V_48 = ( const struct V_54 * ) V_77 -> V_84 ;
if ( ! V_45 -> V_48 )
return - V_66 ;
V_79 = F_38 ( V_47 , V_85 , 0 ) ;
V_45 -> V_7 = F_39 ( & V_47 -> V_43 , V_79 ) ;
if ( F_28 ( V_45 -> V_7 ) )
return F_29 ( V_45 -> V_7 ) ;
V_45 -> V_74 = F_40 ( & V_47 -> V_43 , L_18 ) ;
if ( F_28 ( V_45 -> V_74 ) ) {
error = F_29 ( V_45 -> V_74 ) ;
F_25 ( & V_47 -> V_43 , L_19 , error ) ;
return error ;
}
V_45 -> V_86 = F_41 ( & V_47 -> V_43 , L_20 ) ;
if ( F_28 ( V_45 -> V_86 ) ) {
error = F_29 ( V_45 -> V_86 ) ;
F_25 ( & V_47 -> V_43 , L_21 , error ) ;
return error ;
}
V_45 -> V_87 = F_41 ( & V_47 -> V_43 , L_22 ) ;
if ( F_28 ( V_45 -> V_87 ) ) {
error = F_29 ( V_45 -> V_86 ) ;
F_25 ( & V_47 -> V_43 , L_23 ,
error ) ;
return error ;
}
error = F_42 ( V_45 -> V_86 ) ;
if ( error ) {
F_25 ( & V_47 -> V_43 , L_24 ,
error ) ;
return error ;
}
error = F_42 ( V_45 -> V_87 ) ;
if ( error ) {
F_25 ( & V_47 -> V_43 , L_25 , error ) ;
goto V_88;
}
F_30 ( V_45 -> V_74 ) ;
error = F_22 ( & V_47 -> V_43 , V_61 , V_45 ) ;
if ( error ) {
F_25 ( & V_47 -> V_43 , L_26 ,
error ) ;
goto V_89;
}
V_45 -> V_48 -> V_90 ( V_45 -> V_7 , V_45 -> V_8 ) ;
error = F_26 ( V_47 , V_45 ,
& V_45 -> V_50 [ 0 ] ,
V_91 ) ;
if ( error ) {
F_25 ( & V_47 -> V_43 ,
L_27 , error ) ;
goto V_89;
}
error = F_26 ( V_47 , V_45 ,
& V_45 -> V_50 [ 1 ] ,
V_92 ) ;
if ( error ) {
F_25 ( & V_47 -> V_43 ,
L_28 , error ) ;
goto V_93;
}
error = F_43 ( & V_47 -> V_43 , V_42 , NULL ,
& F_18 ,
V_94 ,
L_29 , V_45 ) ;
if ( error ) {
F_25 ( & V_47 -> V_43 ,
L_30 , error ) ;
goto V_95;
}
V_45 -> V_48 -> V_96 ( V_45 -> V_7 , true ) ;
for ( V_46 = 0 ; V_46 < F_2 ( V_45 -> V_50 ) ; V_46 ++ )
F_17 ( & V_45 -> V_50 [ V_46 ] , true ) ;
F_44 ( V_47 , V_45 ) ;
return 0 ;
V_95:
F_45 ( & V_47 -> V_43 , V_45 -> V_50 [ 1 ] . V_37 ) ;
V_93:
F_45 ( & V_47 -> V_43 , V_45 -> V_50 [ 0 ] . V_37 ) ;
V_89:
F_46 ( V_45 -> V_87 ) ;
V_88:
F_46 ( V_45 -> V_86 ) ;
return error ;
}
static int F_47 ( struct V_68 * V_47 )
{
struct V_44 * V_45 = F_48 ( V_47 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_2 ( V_45 -> V_50 ) ; V_46 ++ ) {
struct V_33 * V_34 = & V_45 -> V_50 [ V_46 ] ;
F_17 ( V_34 , false ) ;
F_45 ( & V_47 -> V_43 , V_34 -> V_37 ) ;
}
V_45 -> V_48 -> V_96 ( V_45 -> V_7 , false ) ;
F_46 ( V_45 -> V_87 ) ;
F_46 ( V_45 -> V_86 ) ;
return 0 ;
}
static int T_4 F_49 ( struct V_59 * V_43 )
{
struct V_68 * V_47 = F_50 ( V_43 ) ;
struct V_44 * V_45 = F_48 ( V_47 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_2 ( V_45 -> V_50 ) ; V_46 ++ )
F_17 ( & V_45 -> V_50 [ V_46 ] , false ) ;
V_45 -> V_48 -> V_96 ( V_45 -> V_7 , false ) ;
F_51 ( V_45 -> V_87 ) ;
F_51 ( V_45 -> V_86 ) ;
return 0 ;
}
static int T_4 F_52 ( struct V_59 * V_43 )
{
struct V_68 * V_47 = F_50 ( V_43 ) ;
struct V_44 * V_45 = F_48 ( V_47 ) ;
int V_46 ;
int error ;
error = F_53 ( V_45 -> V_86 ) ;
if ( error )
return error ;
error = F_53 ( V_45 -> V_87 ) ;
if ( error )
return error ;
F_30 ( V_45 -> V_74 ) ;
V_45 -> V_48 -> V_90 ( V_45 -> V_7 , V_45 -> V_8 ) ;
for ( V_46 = 0 ; V_46 < F_2 ( V_45 -> V_50 ) ; V_46 ++ ) {
enum V_69 V_58 = V_45 -> V_50 [ V_46 ] . V_58 ;
V_45 -> V_48 -> V_70 ( V_58 , V_45 -> V_7 ,
V_45 -> V_29 ) ;
V_45 -> V_48 -> V_71 ( V_58 , V_45 -> V_7 ,
V_45 -> V_63 ) ;
}
V_45 -> V_48 -> V_96 ( V_45 -> V_7 , true ) ;
for ( V_46 = 0 ; V_46 < F_2 ( V_45 -> V_50 ) ; V_46 ++ )
F_17 ( & V_45 -> V_50 [ V_46 ] , true ) ;
return 0 ;
}
