static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_10 , & V_8 ) ;
return ( V_8 & V_6 -> V_11 ) == V_6 -> V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
bool V_12 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_8 ;
if ( V_6 -> V_13 == 0 )
return 0 ;
F_4 ( V_4 -> V_9 , V_4 -> V_7 -> V_14 ,
V_6 -> V_13 , V_12 ? - 1U : 0 ) ;
F_5 ( V_15 ) ;
do {
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_16 , & V_8 ) ;
} while ( ( V_8 & V_6 -> V_17 ) != ( V_12 ? V_6 -> V_17 : 0 ) );
while ( F_1 ( V_2 ) != V_12 )
F_6 () ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 ; V_18 ++ ) {
F_2 ( V_2 -> V_20 [ V_18 ] ,
V_21 ,
& V_2 -> V_22 [ 0 ] [ V_18 ] ) ;
F_2 ( V_2 -> V_20 [ V_18 ] ,
V_23 ,
& V_2 -> V_22 [ 1 ] [ V_18 ] ) ;
F_2 ( V_2 -> V_20 [ V_18 ] ,
V_24 ,
& V_2 -> V_22 [ 2 ] [ V_18 ] ) ;
F_2 ( V_2 -> V_20 [ V_18 ] ,
V_25 ,
& V_2 -> V_22 [ 3 ] [ V_18 ] ) ;
F_2 ( V_2 -> V_20 [ V_18 ] ,
V_26 ,
& V_2 -> V_22 [ 4 ] [ V_18 ] ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_19 ; V_18 ++ ) {
F_9 ( V_2 -> V_20 [ V_18 ] ,
V_21 ,
V_2 -> V_22 [ 0 ] [ V_18 ] ) ;
F_9 ( V_2 -> V_20 [ V_18 ] ,
V_23 ,
V_2 -> V_22 [ 1 ] [ V_18 ] ) ;
F_9 ( V_2 -> V_20 [ V_18 ] ,
V_24 ,
V_2 -> V_22 [ 2 ] [ V_18 ] ) ;
F_9 ( V_2 -> V_20 [ V_18 ] ,
V_25 ,
V_2 -> V_22 [ 3 ] [ V_18 ] ) ;
F_9 ( V_2 -> V_20 [ V_18 ] ,
V_26 ,
V_2 -> V_22 [ 4 ] [ V_18 ] ) ;
}
return 0 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_8 ;
if ( V_2 -> V_7 -> V_27 == 0 )
return ! F_1 ( V_2 ) ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_28 , & V_8 ) ;
return ! ( V_8 & V_2 -> V_7 -> V_27 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
bool V_29 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_7 -> V_30 == 0 )
return;
F_4 ( V_4 -> V_9 , V_4 -> V_7 -> V_31 ,
V_2 -> V_7 -> V_30 , V_29 ? 0 : - 1U ) ;
F_5 ( V_15 ) ;
while ( F_10 ( V_2 ) != V_29 )
F_6 () ;
}
static int F_12 ( struct V_1 * V_2 , bool V_32 )
{
int V_18 ;
F_13 ( & V_2 -> V_4 -> V_33 ) ;
if ( F_10 ( V_2 ) != V_32 ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_34 ; V_18 ++ )
F_14 ( V_2 -> V_35 [ V_18 ] ) ;
if ( ! V_32 ) {
F_7 ( V_2 ) ;
F_3 ( V_2 , true ) ;
}
F_11 ( V_2 , V_32 ) ;
if ( V_32 ) {
F_3 ( V_2 , false ) ;
F_8 ( V_2 ) ;
}
for ( V_18 = V_2 -> V_34 - 1 ; V_18 >= 0 ; V_18 -- )
F_15 ( V_2 -> V_35 [ V_18 ] ) ;
}
F_16 ( & V_2 -> V_4 -> V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_18 ( V_37 ) ;
return F_12 ( V_2 , true ) ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_18 ( V_37 ) ;
return F_12 ( V_2 , false ) ;
}
static int F_20 ( struct V_36 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_41 ;
int V_18 ;
int error ;
F_21 ( V_40 , L_1 , V_38 -> V_42 ) ;
error = F_22 ( V_40 ) ;
if ( error ) {
F_23 ( V_40 , L_2 , error ) ;
return error ;
}
V_18 = 0 ;
while ( ( V_41 = F_24 ( V_40 -> V_43 , V_18 ++ ) ) && ! F_25 ( V_41 ) ) {
F_21 ( V_40 , L_3 , V_41 ) ;
error = F_26 ( V_40 , V_41 ) ;
if ( error ) {
F_23 ( V_40 , L_4 , error ) ;
F_27 ( V_41 ) ;
F_28 ( V_40 ) ;
return error ;
}
}
return 0 ;
}
static void F_29 ( struct V_36 * V_38 ,
struct V_39 * V_40 )
{
F_21 ( V_40 , L_5 , V_38 -> V_42 ) ;
F_28 ( V_40 ) ;
}
static bool F_30 ( struct V_39 * V_40 )
{
struct V_36 * V_38 ;
struct V_1 * V_2 ;
V_38 = F_31 ( V_40 -> V_44 ) ;
V_2 = F_32 ( V_38 , struct V_1 , V_38 ) ;
return V_2 -> V_7 -> V_45 ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
const struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_46 * V_48 ;
struct V_41 * V_41 ;
int V_49 ;
int V_18 , V_50 ;
T_1 V_51 ;
int error ;
error = F_34 ( V_47 , L_6 , & V_51 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_7 ,
V_47 -> V_42 , error ) ;
return - V_52 ;
}
if ( V_51 >= V_4 -> V_7 -> V_53 ) {
F_23 ( V_4 -> V_40 , L_8 ,
V_47 -> V_42 , V_51 ) ;
return - V_52 ;
}
V_6 = & V_4 -> V_7 -> V_54 [ V_51 ] ;
if ( ! V_6 ) {
F_23 ( V_4 -> V_40 , L_9 ,
V_47 -> V_42 , V_51 ) ;
return - V_52 ;
}
V_49 = F_35 ( V_47 , L_10 , L_11 ) ;
V_2 = F_36 ( V_4 -> V_40 ,
sizeof( * V_2 ) + V_49 * sizeof( V_2 -> V_35 [ 0 ] ) ,
V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ ) {
V_41 = F_24 ( V_47 , V_18 ) ;
if ( F_25 ( V_41 ) ) {
error = F_37 ( V_41 ) ;
F_23 ( V_4 -> V_40 ,
L_12 ,
V_47 -> V_42 , V_18 , error ) ;
goto V_57;
}
error = F_38 ( V_41 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_13 ,
V_47 -> V_42 , V_41 , V_18 , error ) ;
F_27 ( V_41 ) ;
goto V_57;
}
V_2 -> V_35 [ V_2 -> V_34 ++ ] = V_41 ;
F_21 ( V_4 -> V_40 , L_14 ,
V_41 , V_47 -> V_42 ) ;
}
V_2 -> V_19 = F_35 ( V_47 , L_15 ,
NULL ) ;
if ( V_2 -> V_19 > 0 ) {
V_2 -> V_20 = F_39 ( V_4 -> V_40 , V_2 -> V_19 ,
sizeof( * V_2 -> V_20 ) ,
V_55 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_56 ;
goto V_57;
}
for ( V_50 = 0 ; V_50 < V_58 ; V_50 ++ ) {
V_2 -> V_22 [ V_50 ] = F_39 ( V_4 -> V_40 ,
V_2 -> V_19 ,
sizeof( T_1 ) ,
V_55 ) ;
if ( ! V_2 -> V_22 [ V_50 ] ) {
error = - V_56 ;
goto V_57;
}
}
for ( V_50 = 0 ; V_50 < V_2 -> V_19 ; V_50 ++ ) {
V_48 = F_40 ( V_47 , L_15 , V_50 ) ;
if ( ! V_48 ) {
error = - V_59 ;
goto V_57;
}
V_2 -> V_20 [ V_50 ] = F_41 ( V_48 ) ;
if ( F_25 ( V_2 -> V_20 [ V_50 ] ) ) {
error = - V_59 ;
F_42 ( V_48 ) ;
goto V_57;
}
F_42 ( V_48 ) ;
}
}
error = F_12 ( V_2 , true ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_16 ,
V_47 -> V_42 , error ) ;
goto V_57;
}
V_2 -> V_38 . V_42 = V_47 -> V_42 ;
V_2 -> V_38 . V_60 = F_19 ;
V_2 -> V_38 . V_32 = F_17 ;
V_2 -> V_38 . V_61 = F_20 ;
V_2 -> V_38 . V_62 = F_29 ;
V_2 -> V_38 . V_63 . V_45 = F_30 ;
V_2 -> V_38 . V_64 = V_65 ;
F_43 ( & V_2 -> V_38 , NULL , false ) ;
V_4 -> V_66 . V_67 [ V_51 ] = & V_2 -> V_38 ;
return 0 ;
V_57:
while ( -- V_18 >= 0 ) {
F_44 ( V_2 -> V_35 [ V_18 ] ) ;
F_27 ( V_2 -> V_35 [ V_18 ] ) ;
}
return error ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_34 ; V_18 ++ ) {
F_44 ( V_2 -> V_35 [ V_18 ] ) ;
F_27 ( V_2 -> V_35 [ V_18 ] ) ;
}
F_13 ( & V_2 -> V_4 -> V_33 ) ;
V_2 -> V_34 = 0 ;
F_16 ( & V_2 -> V_4 -> V_33 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_36 * V_38 ;
struct V_1 * V_2 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_66 . V_53 ; V_18 ++ ) {
V_38 = V_4 -> V_66 . V_67 [ V_18 ] ;
if ( V_38 ) {
V_2 = F_18 ( V_38 ) ;
F_45 ( V_2 ) ;
}
}
}
static void F_47 ( struct V_3 * V_4 ,
T_1 V_68 ,
unsigned int V_69 )
{
F_9 ( V_4 -> V_9 , V_68 , V_69 ) ;
F_9 ( V_4 -> V_9 , V_68 + 4 , V_69 ) ;
}
static int F_48 ( struct V_3 * V_4 ,
struct V_46 * V_70 )
{
struct V_46 * V_71 ;
struct V_36 * V_72 , * V_73 ;
int error ;
F_49 (parent, np) {
T_1 V_74 ;
error = F_34 ( V_70 , L_6 , & V_74 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_7 ,
V_70 -> V_42 , error ) ;
goto V_57;
}
V_73 = V_4 -> V_66 . V_67 [ V_74 ] ;
error = F_33 ( V_4 , V_71 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 , L_17 ,
V_71 -> V_42 , error ) ;
goto V_57;
}
error = F_34 ( V_71 , L_6 , & V_74 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_7 ,
V_71 -> V_42 , error ) ;
goto V_57;
}
V_72 = V_4 -> V_66 . V_67 [ V_74 ] ;
error = F_50 ( V_73 , V_72 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 , L_18 ,
V_73 -> V_42 , V_72 -> V_42 , error ) ;
goto V_57;
} else {
F_21 ( V_4 -> V_40 , L_19 ,
V_73 -> V_42 , V_72 -> V_42 ) ;
}
F_48 ( V_4 , V_71 ) ;
}
return 0 ;
V_57:
F_42 ( V_71 ) ;
return error ;
}
static int F_51 ( struct V_75 * V_76 )
{
struct V_39 * V_40 = & V_76 -> V_40 ;
struct V_46 * V_71 = V_40 -> V_43 ;
struct V_46 * V_47 ;
struct V_39 * V_70 ;
struct V_3 * V_4 ;
const struct V_77 * V_78 ;
const struct V_79 * V_80 ;
int error ;
if ( ! V_71 ) {
F_23 ( V_40 , L_20 ) ;
return - V_59 ;
}
V_78 = F_52 ( V_40 -> V_81 -> V_82 , V_40 ) ;
if ( ! V_78 || ! V_78 -> V_83 ) {
F_23 ( V_40 , L_21 ) ;
return - V_52 ;
}
V_80 = V_78 -> V_83 ;
V_4 = F_36 ( V_40 ,
sizeof( * V_4 ) +
V_80 -> V_53 * sizeof( V_4 -> V_67 [ 0 ] ) ,
V_55 ) ;
if ( ! V_4 )
return - V_56 ;
V_4 -> V_40 = & V_76 -> V_40 ;
F_53 ( & V_4 -> V_33 ) ;
V_4 -> V_7 = V_80 ;
V_4 -> V_66 . V_67 = V_4 -> V_67 ;
V_4 -> V_66 . V_53 = V_80 -> V_53 ;
V_70 = V_40 -> V_70 ;
if ( ! V_70 ) {
F_23 ( V_40 , L_22 ) ;
return - V_59 ;
}
V_4 -> V_9 = F_41 ( V_70 -> V_43 ) ;
if ( F_25 ( V_4 -> V_9 ) ) {
F_23 ( V_40 , L_23 ) ;
return F_37 ( V_4 -> V_9 ) ;
}
F_47 ( V_4 , V_80 -> V_84 ,
V_80 -> V_85 ) ;
F_47 ( V_4 , V_80 -> V_86 ,
V_80 -> V_87 ) ;
error = - V_59 ;
F_54 (np, node) {
error = F_33 ( V_4 , V_47 ) ;
if ( error ) {
F_23 ( V_40 , L_17 ,
V_47 -> V_42 , error ) ;
F_42 ( V_47 ) ;
goto V_57;
}
error = F_48 ( V_4 , V_47 ) ;
if ( error < 0 ) {
F_23 ( V_40 , L_24 ,
V_47 -> V_42 , error ) ;
F_42 ( V_47 ) ;
goto V_57;
}
}
if ( error ) {
F_21 ( V_40 , L_25 ) ;
goto V_57;
}
F_55 ( V_71 , & V_4 -> V_66 ) ;
return 0 ;
V_57:
F_46 ( V_4 ) ;
return error ;
}
static int T_2 F_56 ( void )
{
return F_57 ( & V_88 ) ;
}
