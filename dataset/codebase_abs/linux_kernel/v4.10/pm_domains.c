static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_10 , & V_8 ) ;
return ( V_8 & V_6 -> V_11 ) == V_6 -> V_11 ;
}
static unsigned int F_3 ( struct V_3 * V_4 )
{
unsigned int V_8 ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_12 , & V_8 ) ;
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
bool V_13 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_16 ;
unsigned int V_8 ;
bool V_17 ;
int V_18 ;
if ( V_6 -> V_19 == 0 )
return 0 ;
F_5 ( V_4 -> V_9 , V_4 -> V_7 -> V_20 ,
V_6 -> V_19 , V_13 ? - 1U : 0 ) ;
F_6 ( V_21 ) ;
V_16 = V_13 ? V_6 -> V_22 : 0 ;
V_18 = F_7 ( F_3 , V_4 , V_8 ,
( V_8 & V_6 -> V_22 ) == V_16 ,
0 , 10000 ) ;
if ( V_18 ) {
F_8 ( V_4 -> V_23 ,
L_1 ,
V_15 -> V_24 , V_8 ) ;
return V_18 ;
}
V_18 = F_7 ( F_1 , V_2 ,
V_17 , V_17 == V_13 , 0 , 10000 ) ;
if ( V_18 ) {
F_8 ( V_4 -> V_23 ,
L_2 ,
V_15 -> V_24 , V_17 ) ;
return V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_26 ; V_25 ++ ) {
F_2 ( V_2 -> V_27 [ V_25 ] ,
V_28 ,
& V_2 -> V_29 [ 0 ] [ V_25 ] ) ;
F_2 ( V_2 -> V_27 [ V_25 ] ,
V_30 ,
& V_2 -> V_29 [ 1 ] [ V_25 ] ) ;
F_2 ( V_2 -> V_27 [ V_25 ] ,
V_31 ,
& V_2 -> V_29 [ 2 ] [ V_25 ] ) ;
F_2 ( V_2 -> V_27 [ V_25 ] ,
V_32 ,
& V_2 -> V_29 [ 3 ] [ V_25 ] ) ;
F_2 ( V_2 -> V_27 [ V_25 ] ,
V_33 ,
& V_2 -> V_29 [ 4 ] [ V_25 ] ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_26 ; V_25 ++ ) {
F_11 ( V_2 -> V_27 [ V_25 ] ,
V_28 ,
V_2 -> V_29 [ 0 ] [ V_25 ] ) ;
F_11 ( V_2 -> V_27 [ V_25 ] ,
V_30 ,
V_2 -> V_29 [ 1 ] [ V_25 ] ) ;
F_11 ( V_2 -> V_27 [ V_25 ] ,
V_31 ,
V_2 -> V_29 [ 2 ] [ V_25 ] ) ;
F_11 ( V_2 -> V_27 [ V_25 ] ,
V_32 ,
V_2 -> V_29 [ 3 ] [ V_25 ] ) ;
F_11 ( V_2 -> V_27 [ V_25 ] ,
V_33 ,
V_2 -> V_29 [ 4 ] [ V_25 ] ) ;
}
return 0 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_8 ;
if ( V_2 -> V_7 -> V_34 == 0 )
return ! F_1 ( V_2 ) ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_35 , & V_8 ) ;
return ! ( V_8 & V_2 -> V_7 -> V_34 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
bool V_36 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
bool V_37 ;
if ( V_2 -> V_7 -> V_38 == 0 )
return;
F_5 ( V_4 -> V_9 , V_4 -> V_7 -> V_39 ,
V_2 -> V_7 -> V_38 , V_36 ? 0 : - 1U ) ;
F_6 ( V_21 ) ;
if ( F_7 ( F_12 , V_2 , V_37 ,
V_37 == V_36 , 0 , 10000 ) ) {
F_8 ( V_4 -> V_23 ,
L_3 ,
V_15 -> V_24 , V_37 ) ;
return;
}
}
static int F_14 ( struct V_1 * V_2 , bool V_40 )
{
int V_25 ;
F_15 ( & V_2 -> V_4 -> V_41 ) ;
if ( F_12 ( V_2 ) != V_40 ) {
for ( V_25 = 0 ; V_25 < V_2 -> V_42 ; V_25 ++ )
F_16 ( V_2 -> V_43 [ V_25 ] ) ;
if ( ! V_40 ) {
F_9 ( V_2 ) ;
F_4 ( V_2 , true ) ;
}
F_13 ( V_2 , V_40 ) ;
if ( V_40 ) {
F_4 ( V_2 , false ) ;
F_10 ( V_2 ) ;
}
for ( V_25 = V_2 -> V_42 - 1 ; V_25 >= 0 ; V_25 -- )
F_17 ( V_2 -> V_43 [ V_25 ] ) ;
}
F_18 ( & V_2 -> V_4 -> V_41 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_14 ( V_2 , true ) ;
}
static int F_21 ( struct V_14 * V_44 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
return F_14 ( V_2 , false ) ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_45 * V_23 )
{
struct V_46 * V_46 ;
int V_25 ;
int error ;
F_23 ( V_23 , L_4 , V_15 -> V_24 ) ;
error = F_24 ( V_23 ) ;
if ( error ) {
F_8 ( V_23 , L_5 , error ) ;
return error ;
}
V_25 = 0 ;
while ( ( V_46 = F_25 ( V_23 -> V_47 , V_25 ++ ) ) && ! F_26 ( V_46 ) ) {
F_23 ( V_23 , L_6 , V_46 ) ;
error = F_27 ( V_23 , V_46 ) ;
if ( error ) {
F_8 ( V_23 , L_7 , error ) ;
F_28 ( V_46 ) ;
F_29 ( V_23 ) ;
return error ;
}
}
return 0 ;
}
static void F_30 ( struct V_14 * V_15 ,
struct V_45 * V_23 )
{
F_23 ( V_23 , L_8 , V_15 -> V_24 ) ;
F_29 ( V_23 ) ;
}
static bool F_31 ( struct V_45 * V_23 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_15 = F_32 ( V_23 -> V_48 ) ;
V_2 = F_33 ( V_15 , struct V_1 , V_15 ) ;
return V_2 -> V_7 -> V_49 ;
}
static int F_34 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
const struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_50 * V_52 ;
struct V_46 * V_46 ;
int V_53 ;
int V_25 , V_54 ;
T_1 V_55 ;
int error ;
error = F_35 ( V_51 , L_9 , & V_55 ) ;
if ( error ) {
F_8 ( V_4 -> V_23 ,
L_10 ,
V_51 -> V_24 , error ) ;
return - V_56 ;
}
if ( V_55 >= V_4 -> V_7 -> V_57 ) {
F_8 ( V_4 -> V_23 , L_11 ,
V_51 -> V_24 , V_55 ) ;
return - V_56 ;
}
V_6 = & V_4 -> V_7 -> V_58 [ V_55 ] ;
if ( ! V_6 ) {
F_8 ( V_4 -> V_23 , L_12 ,
V_51 -> V_24 , V_55 ) ;
return - V_56 ;
}
V_53 = F_36 ( V_51 , L_13 , L_14 ) ;
V_2 = F_37 ( V_4 -> V_23 ,
sizeof( * V_2 ) + V_53 * sizeof( V_2 -> V_43 [ 0 ] ) ,
V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_25 = 0 ; V_25 < V_53 ; V_25 ++ ) {
V_46 = F_25 ( V_51 , V_25 ) ;
if ( F_26 ( V_46 ) ) {
error = F_38 ( V_46 ) ;
F_8 ( V_4 -> V_23 ,
L_15 ,
V_51 -> V_24 , V_25 , error ) ;
goto V_61;
}
error = F_39 ( V_46 ) ;
if ( error ) {
F_8 ( V_4 -> V_23 ,
L_16 ,
V_51 -> V_24 , V_46 , V_25 , error ) ;
F_28 ( V_46 ) ;
goto V_61;
}
V_2 -> V_43 [ V_2 -> V_42 ++ ] = V_46 ;
F_23 ( V_4 -> V_23 , L_17 ,
V_46 , V_51 -> V_24 ) ;
}
V_2 -> V_26 = F_36 ( V_51 , L_18 ,
NULL ) ;
if ( V_2 -> V_26 > 0 ) {
V_2 -> V_27 = F_40 ( V_4 -> V_23 , V_2 -> V_26 ,
sizeof( * V_2 -> V_27 ) ,
V_59 ) ;
if ( ! V_2 -> V_27 ) {
error = - V_60 ;
goto V_61;
}
for ( V_54 = 0 ; V_54 < V_62 ; V_54 ++ ) {
V_2 -> V_29 [ V_54 ] = F_40 ( V_4 -> V_23 ,
V_2 -> V_26 ,
sizeof( T_1 ) ,
V_59 ) ;
if ( ! V_2 -> V_29 [ V_54 ] ) {
error = - V_60 ;
goto V_61;
}
}
for ( V_54 = 0 ; V_54 < V_2 -> V_26 ; V_54 ++ ) {
V_52 = F_41 ( V_51 , L_18 , V_54 ) ;
if ( ! V_52 ) {
error = - V_63 ;
goto V_61;
}
V_2 -> V_27 [ V_54 ] = F_42 ( V_52 ) ;
if ( F_26 ( V_2 -> V_27 [ V_54 ] ) ) {
error = - V_63 ;
F_43 ( V_52 ) ;
goto V_61;
}
F_43 ( V_52 ) ;
}
}
error = F_14 ( V_2 , true ) ;
if ( error ) {
F_8 ( V_4 -> V_23 ,
L_19 ,
V_51 -> V_24 , error ) ;
goto V_61;
}
V_2 -> V_15 . V_24 = V_51 -> V_24 ;
V_2 -> V_15 . V_64 = F_21 ;
V_2 -> V_15 . V_40 = F_19 ;
V_2 -> V_15 . V_65 = F_22 ;
V_2 -> V_15 . V_66 = F_30 ;
V_2 -> V_15 . V_67 . V_49 = F_31 ;
V_2 -> V_15 . V_68 = V_69 ;
F_44 ( & V_2 -> V_15 , NULL , false ) ;
V_4 -> V_70 . V_71 [ V_55 ] = & V_2 -> V_15 ;
return 0 ;
V_61:
while ( -- V_25 >= 0 ) {
F_45 ( V_2 -> V_43 [ V_25 ] ) ;
F_28 ( V_2 -> V_43 [ V_25 ] ) ;
}
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_25 , V_18 ;
V_18 = F_47 ( & V_2 -> V_15 ) ;
if ( V_18 < 0 )
F_8 ( V_2 -> V_4 -> V_23 , L_20 ,
V_2 -> V_15 . V_24 , V_18 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_42 ; V_25 ++ ) {
F_45 ( V_2 -> V_43 [ V_25 ] ) ;
F_28 ( V_2 -> V_43 [ V_25 ] ) ;
}
F_15 ( & V_2 -> V_4 -> V_41 ) ;
V_2 -> V_42 = 0 ;
F_18 ( & V_2 -> V_4 -> V_41 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_4 -> V_70 . V_57 ; V_25 ++ ) {
V_15 = V_4 -> V_70 . V_71 [ V_25 ] ;
if ( V_15 ) {
V_2 = F_20 ( V_15 ) ;
F_46 ( V_2 ) ;
}
}
}
static void F_49 ( struct V_3 * V_4 ,
T_1 V_72 ,
unsigned int V_73 )
{
F_11 ( V_4 -> V_9 , V_72 , V_73 ) ;
F_11 ( V_4 -> V_9 , V_72 + 4 , V_73 ) ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_50 * V_74 )
{
struct V_50 * V_75 ;
struct V_14 * V_76 , * V_77 ;
int error ;
F_51 (parent, np) {
T_1 V_78 ;
error = F_35 ( V_74 , L_9 , & V_78 ) ;
if ( error ) {
F_8 ( V_4 -> V_23 ,
L_10 ,
V_74 -> V_24 , error ) ;
goto V_61;
}
V_77 = V_4 -> V_70 . V_71 [ V_78 ] ;
error = F_34 ( V_4 , V_75 ) ;
if ( error ) {
F_8 ( V_4 -> V_23 , L_21 ,
V_75 -> V_24 , error ) ;
goto V_61;
}
error = F_35 ( V_75 , L_9 , & V_78 ) ;
if ( error ) {
F_8 ( V_4 -> V_23 ,
L_10 ,
V_75 -> V_24 , error ) ;
goto V_61;
}
V_76 = V_4 -> V_70 . V_71 [ V_78 ] ;
error = F_52 ( V_77 , V_76 ) ;
if ( error ) {
F_8 ( V_4 -> V_23 , L_22 ,
V_77 -> V_24 , V_76 -> V_24 , error ) ;
goto V_61;
} else {
F_23 ( V_4 -> V_23 , L_23 ,
V_77 -> V_24 , V_76 -> V_24 ) ;
}
F_50 ( V_4 , V_75 ) ;
}
return 0 ;
V_61:
F_43 ( V_75 ) ;
return error ;
}
static int F_53 ( struct V_79 * V_80 )
{
struct V_45 * V_23 = & V_80 -> V_23 ;
struct V_50 * V_75 = V_23 -> V_47 ;
struct V_50 * V_51 ;
struct V_45 * V_74 ;
struct V_3 * V_4 ;
const struct V_81 * V_82 ;
const struct V_83 * V_84 ;
int error ;
if ( ! V_75 ) {
F_8 ( V_23 , L_24 ) ;
return - V_63 ;
}
V_82 = F_54 ( V_23 -> V_85 -> V_86 , V_23 ) ;
if ( ! V_82 || ! V_82 -> V_87 ) {
F_8 ( V_23 , L_25 ) ;
return - V_56 ;
}
V_84 = V_82 -> V_87 ;
V_4 = F_37 ( V_23 ,
sizeof( * V_4 ) +
V_84 -> V_57 * sizeof( V_4 -> V_71 [ 0 ] ) ,
V_59 ) ;
if ( ! V_4 )
return - V_60 ;
V_4 -> V_23 = & V_80 -> V_23 ;
F_55 ( & V_4 -> V_41 ) ;
V_4 -> V_7 = V_84 ;
V_4 -> V_70 . V_71 = V_4 -> V_71 ;
V_4 -> V_70 . V_57 = V_84 -> V_57 ;
V_74 = V_23 -> V_74 ;
if ( ! V_74 ) {
F_8 ( V_23 , L_26 ) ;
return - V_63 ;
}
V_4 -> V_9 = F_42 ( V_74 -> V_47 ) ;
if ( F_26 ( V_4 -> V_9 ) ) {
F_8 ( V_23 , L_27 ) ;
return F_38 ( V_4 -> V_9 ) ;
}
if ( V_84 -> V_88 )
F_49 ( V_4 , V_84 -> V_89 ,
V_84 -> V_88 ) ;
if ( V_84 -> V_90 )
F_49 ( V_4 , V_84 -> V_90 ,
V_84 -> V_91 ) ;
error = - V_63 ;
F_56 (np, node) {
error = F_34 ( V_4 , V_51 ) ;
if ( error ) {
F_8 ( V_23 , L_21 ,
V_51 -> V_24 , error ) ;
F_43 ( V_51 ) ;
goto V_61;
}
error = F_50 ( V_4 , V_51 ) ;
if ( error < 0 ) {
F_8 ( V_23 , L_28 ,
V_51 -> V_24 , error ) ;
F_43 ( V_51 ) ;
goto V_61;
}
}
if ( error ) {
F_23 ( V_23 , L_29 ) ;
goto V_61;
}
error = F_57 ( V_75 , & V_4 -> V_70 ) ;
if ( error ) {
F_8 ( V_23 , L_30 , error ) ;
goto V_61;
}
return 0 ;
V_61:
F_48 ( V_4 ) ;
return error ;
}
static int T_2 F_58 ( void )
{
return F_59 ( & V_92 ) ;
}
