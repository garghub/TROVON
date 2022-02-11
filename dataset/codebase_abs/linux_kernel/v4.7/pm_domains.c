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
static int F_30 ( struct V_3 * V_4 ,
struct V_44 * V_45 )
{
const struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_44 * V_46 ;
struct V_41 * V_41 ;
int V_47 ;
int V_18 , V_48 ;
T_1 V_49 ;
int error ;
error = F_31 ( V_45 , L_6 , & V_49 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_7 ,
V_45 -> V_42 , error ) ;
return - V_50 ;
}
if ( V_49 >= V_4 -> V_7 -> V_51 ) {
F_23 ( V_4 -> V_40 , L_8 ,
V_45 -> V_42 , V_49 ) ;
return - V_50 ;
}
V_6 = & V_4 -> V_7 -> V_52 [ V_49 ] ;
if ( ! V_6 ) {
F_23 ( V_4 -> V_40 , L_9 ,
V_45 -> V_42 , V_49 ) ;
return - V_50 ;
}
V_47 = F_32 ( V_45 , L_10 , L_11 ) ;
V_2 = F_33 ( V_4 -> V_40 ,
sizeof( * V_2 ) + V_47 * sizeof( V_2 -> V_35 [ 0 ] ) ,
V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_18 = 0 ; V_18 < V_47 ; V_18 ++ ) {
V_41 = F_24 ( V_45 , V_18 ) ;
if ( F_25 ( V_41 ) ) {
error = F_34 ( V_41 ) ;
F_23 ( V_4 -> V_40 ,
L_12 ,
V_45 -> V_42 , V_18 , error ) ;
goto V_55;
}
error = F_35 ( V_41 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_13 ,
V_45 -> V_42 , V_41 , V_18 , error ) ;
F_27 ( V_41 ) ;
goto V_55;
}
V_2 -> V_35 [ V_2 -> V_34 ++ ] = V_41 ;
F_21 ( V_4 -> V_40 , L_14 ,
V_41 , V_45 -> V_42 ) ;
}
V_2 -> V_19 = F_32 ( V_45 , L_15 ,
NULL ) ;
if ( V_2 -> V_19 > 0 ) {
V_2 -> V_20 = F_36 ( V_4 -> V_40 , V_2 -> V_19 ,
sizeof( * V_2 -> V_20 ) ,
V_53 ) ;
if ( ! V_2 -> V_20 ) {
error = - V_54 ;
goto V_55;
}
for ( V_48 = 0 ; V_48 < V_56 ; V_48 ++ ) {
V_2 -> V_22 [ V_48 ] = F_36 ( V_4 -> V_40 ,
V_2 -> V_19 ,
sizeof( T_1 ) ,
V_53 ) ;
if ( ! V_2 -> V_22 [ V_48 ] ) {
error = - V_54 ;
goto V_55;
}
}
for ( V_48 = 0 ; V_48 < V_2 -> V_19 ; V_48 ++ ) {
V_46 = F_37 ( V_45 , L_15 , V_48 ) ;
if ( ! V_46 ) {
error = - V_57 ;
goto V_55;
}
V_2 -> V_20 [ V_48 ] = F_38 ( V_46 ) ;
if ( F_25 ( V_2 -> V_20 [ V_48 ] ) ) {
error = - V_57 ;
F_39 ( V_46 ) ;
goto V_55;
}
F_39 ( V_46 ) ;
}
}
error = F_12 ( V_2 , true ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_16 ,
V_45 -> V_42 , error ) ;
goto V_55;
}
V_2 -> V_38 . V_42 = V_45 -> V_42 ;
V_2 -> V_38 . V_58 = F_19 ;
V_2 -> V_38 . V_32 = F_17 ;
V_2 -> V_38 . V_59 = F_20 ;
V_2 -> V_38 . V_60 = F_29 ;
V_2 -> V_38 . V_61 = V_62 ;
F_40 ( & V_2 -> V_38 , NULL , false ) ;
V_4 -> V_63 . V_64 [ V_49 ] = & V_2 -> V_38 ;
return 0 ;
V_55:
while ( -- V_18 >= 0 ) {
F_41 ( V_2 -> V_35 [ V_18 ] ) ;
F_27 ( V_2 -> V_35 [ V_18 ] ) ;
}
return error ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_34 ; V_18 ++ ) {
F_41 ( V_2 -> V_35 [ V_18 ] ) ;
F_27 ( V_2 -> V_35 [ V_18 ] ) ;
}
F_13 ( & V_2 -> V_4 -> V_33 ) ;
V_2 -> V_34 = 0 ;
F_16 ( & V_2 -> V_4 -> V_33 ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_36 * V_38 ;
struct V_1 * V_2 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_63 . V_51 ; V_18 ++ ) {
V_38 = V_4 -> V_63 . V_64 [ V_18 ] ;
if ( V_38 ) {
V_2 = F_18 ( V_38 ) ;
F_42 ( V_2 ) ;
}
}
}
static void F_44 ( struct V_3 * V_4 ,
T_1 V_65 ,
unsigned int V_66 )
{
F_9 ( V_4 -> V_9 , V_65 , V_66 ) ;
F_9 ( V_4 -> V_9 , V_65 + 4 , V_66 ) ;
}
static int F_45 ( struct V_3 * V_4 ,
struct V_44 * V_67 )
{
struct V_44 * V_68 ;
struct V_36 * V_69 , * V_70 ;
int error ;
F_46 (parent, np) {
T_1 V_71 ;
error = F_31 ( V_67 , L_6 , & V_71 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_7 ,
V_67 -> V_42 , error ) ;
goto V_55;
}
V_70 = V_4 -> V_63 . V_64 [ V_71 ] ;
error = F_30 ( V_4 , V_68 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 , L_17 ,
V_68 -> V_42 , error ) ;
goto V_55;
}
error = F_31 ( V_68 , L_6 , & V_71 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 ,
L_7 ,
V_68 -> V_42 , error ) ;
goto V_55;
}
V_69 = V_4 -> V_63 . V_64 [ V_71 ] ;
error = F_47 ( V_70 , V_69 ) ;
if ( error ) {
F_23 ( V_4 -> V_40 , L_18 ,
V_70 -> V_42 , V_69 -> V_42 , error ) ;
goto V_55;
} else {
F_21 ( V_4 -> V_40 , L_19 ,
V_70 -> V_42 , V_69 -> V_42 ) ;
}
F_45 ( V_4 , V_68 ) ;
}
return 0 ;
V_55:
F_39 ( V_68 ) ;
return error ;
}
static int F_48 ( struct V_72 * V_73 )
{
struct V_39 * V_40 = & V_73 -> V_40 ;
struct V_44 * V_68 = V_40 -> V_43 ;
struct V_44 * V_45 ;
struct V_39 * V_67 ;
struct V_3 * V_4 ;
const struct V_74 * V_75 ;
const struct V_76 * V_77 ;
int error ;
if ( ! V_68 ) {
F_23 ( V_40 , L_20 ) ;
return - V_57 ;
}
V_75 = F_49 ( V_40 -> V_78 -> V_79 , V_40 ) ;
if ( ! V_75 || ! V_75 -> V_80 ) {
F_23 ( V_40 , L_21 ) ;
return - V_50 ;
}
V_77 = V_75 -> V_80 ;
V_4 = F_33 ( V_40 ,
sizeof( * V_4 ) +
V_77 -> V_51 * sizeof( V_4 -> V_64 [ 0 ] ) ,
V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_4 -> V_40 = & V_73 -> V_40 ;
F_50 ( & V_4 -> V_33 ) ;
V_4 -> V_7 = V_77 ;
V_4 -> V_63 . V_64 = V_4 -> V_64 ;
V_4 -> V_63 . V_51 = V_77 -> V_51 ;
V_67 = V_40 -> V_67 ;
if ( ! V_67 ) {
F_23 ( V_40 , L_22 ) ;
return - V_57 ;
}
V_4 -> V_9 = F_38 ( V_67 -> V_43 ) ;
if ( F_25 ( V_4 -> V_9 ) ) {
F_23 ( V_40 , L_23 ) ;
return F_34 ( V_4 -> V_9 ) ;
}
F_44 ( V_4 , V_77 -> V_81 ,
V_77 -> V_82 ) ;
F_44 ( V_4 , V_77 -> V_83 ,
V_77 -> V_84 ) ;
error = - V_57 ;
F_51 (np, node) {
error = F_30 ( V_4 , V_45 ) ;
if ( error ) {
F_23 ( V_40 , L_17 ,
V_45 -> V_42 , error ) ;
F_39 ( V_45 ) ;
goto V_55;
}
error = F_45 ( V_4 , V_45 ) ;
if ( error < 0 ) {
F_23 ( V_40 , L_24 ,
V_45 -> V_42 , error ) ;
F_39 ( V_45 ) ;
goto V_55;
}
}
if ( error ) {
F_21 ( V_40 , L_25 ) ;
goto V_55;
}
F_52 ( V_68 , & V_4 -> V_63 ) ;
return 0 ;
V_55:
F_43 ( V_4 ) ;
return error ;
}
static int T_2 F_53 ( void )
{
return F_54 ( & V_85 ) ;
}
