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
unsigned int V_3 = 0 ;
unsigned int V_2 = F_2 ( V_5 ) - 1 ;
unsigned int V_4 = ( V_3 + V_2 ) / 2 ;
unsigned int V_7 ;
unsigned long V_8 ;
if ( V_6 > V_9 )
return - V_10 ;
while ( V_3 <= V_2 && V_4 ) {
if ( V_6 >= V_5 [ V_4 ] . V_6 &&
V_6 < V_5 [ V_4 - 1 ] . V_6 )
break;
else if ( V_6 < V_5 [ V_4 ] . V_6 )
V_3 = V_4 + 1 ;
else
V_2 = V_4 - 1 ;
V_4 = ( V_3 + V_2 ) / 2 ;
}
V_7 = V_5 [ V_4 ] . V_1 - V_5 [ V_4 - 1 ] . V_1 ;
V_7 *= V_5 [ V_4 - 1 ] . V_6 - V_6 ;
V_8 = V_5 [ V_4 - 1 ] . V_6 - V_5 [ V_4 ] . V_6 ;
return V_5 [ V_4 - 1 ] . V_1 + ( V_7 / V_8 ) ;
}
static void F_4 ( void T_2 * V_11 ,
enum V_12 V_12 )
{
if ( V_12 == V_13 )
F_5 ( 0 | ( V_14 ) ,
V_11 + V_15 ) ;
else
F_5 ( 0 | ( V_16 ) ,
V_11 + V_15 ) ;
F_5 ( V_17 , V_11 + V_18 ) ;
F_5 ( V_19 ,
V_11 + V_20 ) ;
F_5 ( V_21 ,
V_11 + V_22 ) ;
F_5 ( V_23 ,
V_11 + V_24 ) ;
}
static void F_6 ( void T_2 * V_11 )
{
T_1 V_25 ;
V_25 = F_7 ( V_11 + V_26 ) ;
F_5 ( V_25 & V_27 , V_11 + V_26 ) ;
}
static void F_8 ( void T_2 * V_11 , bool V_28 )
{
T_1 V_25 ;
V_25 = F_7 ( V_11 + V_15 ) ;
if ( V_28 )
V_25 |= V_29 ;
else
V_25 &= ~ V_29 ;
F_5 ( V_25 , V_11 + V_15 ) ;
}
static int F_9 ( int V_30 , void T_2 * V_11 , long * V_1 )
{
T_1 V_25 ;
V_25 = F_7 ( V_11 + F_10 ( V_30 ) ) ;
if ( V_25 == 0 )
return - V_10 ;
* V_1 = F_3 ( V_25 ) ;
return 0 ;
}
static void F_11 ( int V_30 , void T_2 * V_11 , long V_1 )
{
T_1 V_31 , V_25 ;
V_31 = F_1 ( V_1 ) ;
F_5 ( V_31 , V_11 + F_12 ( V_30 ) ) ;
V_25 = F_7 ( V_11 + V_15 ) ;
F_5 ( V_25 | F_13 ( V_30 ) , V_11 + V_15 ) ;
}
static void F_14 ( int V_30 , void T_2 * V_11 ,
enum V_32 V_33 )
{
T_1 V_25 ;
V_25 = F_7 ( V_11 + V_34 ) ;
if ( V_33 == V_35 ) {
V_25 &= ~ F_15 ( V_30 ) ;
V_25 |= F_16 ( V_30 ) ;
} else {
V_25 &= ~ F_16 ( V_30 ) ;
V_25 |= F_15 ( V_30 ) ;
}
F_5 ( V_25 , V_11 + V_34 ) ;
}
static void
F_17 ( struct V_36 * V_37 , bool V_38 )
{
struct V_39 * V_40 = V_37 -> V_40 ;
V_40 -> V_41 -> V_42 ( V_40 ,
V_38 ? V_43 : V_44 ) ;
}
static T_3 F_18 ( int V_45 , void * V_46 )
{
struct V_47 * V_48 = V_46 ;
int V_49 ;
F_19 ( & V_48 -> V_50 -> V_46 , L_1 ) ;
V_48 -> V_51 -> V_52 ( V_48 -> V_11 ) ;
for ( V_49 = 0 ; V_49 < F_2 ( V_48 -> V_53 ) ; V_49 ++ )
F_20 ( V_48 -> V_53 [ V_49 ] . V_40 ) ;
return V_54 ;
}
static int F_21 ( void * V_55 , long * V_56 )
{
struct V_36 * V_37 = V_55 ;
struct V_47 * V_48 = V_37 -> V_48 ;
const struct V_57 * V_58 = V_37 -> V_48 -> V_51 ;
int V_59 ;
V_59 = V_58 -> V_60 ( V_37 -> V_61 , V_48 -> V_11 , V_56 ) ;
F_19 ( & V_48 -> V_50 -> V_46 , L_2 ,
V_37 -> V_61 , * V_56 , V_59 ) ;
return V_59 ;
}
static int F_22 ( struct V_62 * V_46 ,
struct V_63 * V_64 ,
struct V_47 * V_48 )
{
T_1 V_65 , V_32 , V_12 ;
if ( F_23 ( V_64 , L_3 , & V_65 ) ) {
F_24 ( V_46 ,
L_4 ,
V_48 -> V_51 -> V_66 ) ;
V_48 -> V_66 = V_48 -> V_51 -> V_66 ;
} else {
V_48 -> V_66 = V_65 ;
}
if ( V_48 -> V_66 > V_67 ) {
F_25 ( V_46 , L_5 ,
V_48 -> V_66 ) ;
return - V_68 ;
}
if ( F_23 ( V_64 , L_6 , & V_32 ) ) {
F_24 ( V_46 ,
L_7 ,
V_48 -> V_51 -> V_32 == V_35 ?
L_8 : L_9 ) ;
V_48 -> V_32 = V_48 -> V_51 -> V_32 ;
} else {
V_48 -> V_32 = V_32 ;
}
if ( V_48 -> V_32 > 1 ) {
F_25 ( V_46 , L_10 ,
V_48 -> V_32 ) ;
return - V_69 ;
}
if ( F_23 ( V_64 , L_11 ,
& V_12 ) ) {
F_24 ( V_46 ,
L_12 ,
V_48 -> V_51 -> V_12 == V_70 ?
L_13 : L_14 ) ;
V_48 -> V_12 = V_48 -> V_51 -> V_12 ;
} else {
V_48 -> V_12 = V_12 ;
}
if ( V_48 -> V_12 > 1 ) {
F_25 ( V_46 , L_15 ,
V_48 -> V_12 ) ;
return - V_69 ;
}
return 0 ;
}
static int
F_26 ( struct V_71 * V_50 ,
struct V_47 * V_48 ,
struct V_36 * V_37 ,
enum V_72 V_61 )
{
const struct V_57 * V_58 = V_48 -> V_51 ;
int error ;
V_58 -> V_73 ( V_61 , V_48 -> V_11 , V_48 -> V_32 ) ;
V_58 -> V_74 ( V_61 , V_48 -> V_11 , V_48 -> V_66 ) ;
V_37 -> V_48 = V_48 ;
V_37 -> V_61 = V_61 ;
V_37 -> V_40 = F_27 ( & V_50 -> V_46 , V_61 , V_37 ,
& V_75 ) ;
if ( F_28 ( V_37 -> V_40 ) ) {
error = F_29 ( V_37 -> V_40 ) ;
F_25 ( & V_50 -> V_46 , L_16 ,
V_61 , error ) ;
return error ;
}
return 0 ;
}
static void F_30 ( struct V_76 * V_77 )
{
F_31 ( V_77 ) ;
F_32 ( 10 , 20 ) ;
F_33 ( V_77 ) ;
}
static int F_34 ( struct V_71 * V_50 )
{
struct V_63 * V_64 = V_50 -> V_46 . V_78 ;
struct V_47 * V_48 ;
const struct V_79 * V_80 ;
struct V_81 * V_82 ;
int V_45 ;
int V_49 ;
int error ;
V_80 = F_35 ( V_83 , V_64 ) ;
if ( ! V_80 )
return - V_84 ;
V_45 = F_36 ( V_50 , 0 ) ;
if ( V_45 < 0 ) {
F_25 ( & V_50 -> V_46 , L_17 ) ;
return - V_69 ;
}
V_48 = F_37 ( & V_50 -> V_46 , sizeof( struct V_47 ) ,
V_85 ) ;
if ( ! V_48 )
return - V_86 ;
V_48 -> V_50 = V_50 ;
V_48 -> V_51 = ( const struct V_57 * ) V_80 -> V_87 ;
if ( ! V_48 -> V_51 )
return - V_69 ;
V_82 = F_38 ( V_50 , V_88 , 0 ) ;
V_48 -> V_11 = F_39 ( & V_50 -> V_46 , V_82 ) ;
if ( F_28 ( V_48 -> V_11 ) )
return F_29 ( V_48 -> V_11 ) ;
V_48 -> V_77 = F_40 ( & V_50 -> V_46 , L_18 ) ;
if ( F_28 ( V_48 -> V_77 ) ) {
error = F_29 ( V_48 -> V_77 ) ;
F_25 ( & V_50 -> V_46 , L_19 , error ) ;
return error ;
}
V_48 -> V_89 = F_41 ( & V_50 -> V_46 , L_20 ) ;
if ( F_28 ( V_48 -> V_89 ) ) {
error = F_29 ( V_48 -> V_89 ) ;
F_25 ( & V_50 -> V_46 , L_21 , error ) ;
return error ;
}
V_48 -> V_90 = F_41 ( & V_50 -> V_46 , L_22 ) ;
if ( F_28 ( V_48 -> V_90 ) ) {
error = F_29 ( V_48 -> V_90 ) ;
F_25 ( & V_50 -> V_46 , L_23 ,
error ) ;
return error ;
}
error = F_42 ( V_48 -> V_89 ) ;
if ( error ) {
F_25 ( & V_50 -> V_46 , L_24 ,
error ) ;
return error ;
}
error = F_42 ( V_48 -> V_90 ) ;
if ( error ) {
F_25 ( & V_50 -> V_46 , L_25 , error ) ;
goto V_91;
}
F_30 ( V_48 -> V_77 ) ;
error = F_22 ( & V_50 -> V_46 , V_64 , V_48 ) ;
if ( error ) {
F_25 ( & V_50 -> V_46 , L_26 ,
error ) ;
goto V_92;
}
V_48 -> V_51 -> V_93 ( V_48 -> V_11 , V_48 -> V_12 ) ;
error = F_26 ( V_50 , V_48 ,
& V_48 -> V_53 [ 0 ] ,
V_94 ) ;
if ( error ) {
F_25 ( & V_50 -> V_46 ,
L_27 , error ) ;
goto V_92;
}
error = F_26 ( V_50 , V_48 ,
& V_48 -> V_53 [ 1 ] ,
V_95 ) ;
if ( error ) {
F_25 ( & V_50 -> V_46 ,
L_28 , error ) ;
goto V_96;
}
error = F_43 ( & V_50 -> V_46 , V_45 , NULL ,
& F_18 ,
V_97 ,
L_29 , V_48 ) ;
if ( error ) {
F_25 ( & V_50 -> V_46 ,
L_30 , error ) ;
goto V_98;
}
V_48 -> V_51 -> V_99 ( V_48 -> V_11 , true ) ;
for ( V_49 = 0 ; V_49 < F_2 ( V_48 -> V_53 ) ; V_49 ++ )
F_17 ( & V_48 -> V_53 [ V_49 ] , true ) ;
F_44 ( V_50 , V_48 ) ;
return 0 ;
V_98:
F_45 ( & V_50 -> V_46 , V_48 -> V_53 [ 1 ] . V_40 ) ;
V_96:
F_45 ( & V_50 -> V_46 , V_48 -> V_53 [ 0 ] . V_40 ) ;
V_92:
F_46 ( V_48 -> V_90 ) ;
V_91:
F_46 ( V_48 -> V_89 ) ;
return error ;
}
static int F_47 ( struct V_71 * V_50 )
{
struct V_47 * V_48 = F_48 ( V_50 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_2 ( V_48 -> V_53 ) ; V_49 ++ ) {
struct V_36 * V_37 = & V_48 -> V_53 [ V_49 ] ;
F_17 ( V_37 , false ) ;
F_45 ( & V_50 -> V_46 , V_37 -> V_40 ) ;
}
V_48 -> V_51 -> V_99 ( V_48 -> V_11 , false ) ;
F_46 ( V_48 -> V_90 ) ;
F_46 ( V_48 -> V_89 ) ;
return 0 ;
}
static int T_4 F_49 ( struct V_62 * V_46 )
{
struct V_71 * V_50 = F_50 ( V_46 ) ;
struct V_47 * V_48 = F_48 ( V_50 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_2 ( V_48 -> V_53 ) ; V_49 ++ )
F_17 ( & V_48 -> V_53 [ V_49 ] , false ) ;
V_48 -> V_51 -> V_99 ( V_48 -> V_11 , false ) ;
F_51 ( V_48 -> V_90 ) ;
F_51 ( V_48 -> V_89 ) ;
return 0 ;
}
static int T_4 F_52 ( struct V_62 * V_46 )
{
struct V_71 * V_50 = F_50 ( V_46 ) ;
struct V_47 * V_48 = F_48 ( V_50 ) ;
int V_49 ;
int error ;
error = F_53 ( V_48 -> V_89 ) ;
if ( error )
return error ;
error = F_53 ( V_48 -> V_90 ) ;
if ( error )
return error ;
F_30 ( V_48 -> V_77 ) ;
V_48 -> V_51 -> V_93 ( V_48 -> V_11 , V_48 -> V_12 ) ;
for ( V_49 = 0 ; V_49 < F_2 ( V_48 -> V_53 ) ; V_49 ++ ) {
enum V_72 V_61 = V_48 -> V_53 [ V_49 ] . V_61 ;
V_48 -> V_51 -> V_73 ( V_61 , V_48 -> V_11 ,
V_48 -> V_32 ) ;
V_48 -> V_51 -> V_74 ( V_61 , V_48 -> V_11 ,
V_48 -> V_66 ) ;
}
V_48 -> V_51 -> V_99 ( V_48 -> V_11 , true ) ;
for ( V_49 = 0 ; V_49 < F_2 ( V_48 -> V_53 ) ; V_49 ++ )
F_17 ( & V_48 -> V_53 [ V_49 ] , true ) ;
return 0 ;
}
