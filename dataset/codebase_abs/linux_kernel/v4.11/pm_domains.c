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
else if ( V_6 -> V_20 )
F_5 ( V_4 -> V_9 , V_4 -> V_7 -> V_21 ,
V_13 ? ( V_6 -> V_19 | V_6 -> V_20 ) :
V_6 -> V_20 ) ;
else
F_6 ( V_4 -> V_9 , V_4 -> V_7 -> V_21 ,
V_6 -> V_19 , V_13 ? - 1U : 0 ) ;
F_7 ( V_22 ) ;
V_16 = V_13 ? V_6 -> V_23 : 0 ;
V_18 = F_8 ( F_3 , V_4 , V_8 ,
( V_8 & V_6 -> V_23 ) == V_16 ,
0 , 10000 ) ;
if ( V_18 ) {
F_9 ( V_4 -> V_24 ,
L_1 ,
V_15 -> V_25 , V_8 ) ;
return V_18 ;
}
V_18 = F_8 ( F_1 , V_2 ,
V_17 , V_17 == V_13 , 0 , 10000 ) ;
if ( V_18 ) {
F_9 ( V_4 -> V_24 ,
L_2 ,
V_15 -> V_25 , V_17 ) ;
return V_18 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 ; V_26 ++ ) {
F_2 ( V_2 -> V_28 [ V_26 ] ,
V_29 ,
& V_2 -> V_30 [ 0 ] [ V_26 ] ) ;
F_2 ( V_2 -> V_28 [ V_26 ] ,
V_31 ,
& V_2 -> V_30 [ 1 ] [ V_26 ] ) ;
F_2 ( V_2 -> V_28 [ V_26 ] ,
V_32 ,
& V_2 -> V_30 [ 2 ] [ V_26 ] ) ;
F_2 ( V_2 -> V_28 [ V_26 ] ,
V_33 ,
& V_2 -> V_30 [ 3 ] [ V_26 ] ) ;
F_2 ( V_2 -> V_28 [ V_26 ] ,
V_34 ,
& V_2 -> V_30 [ 4 ] [ V_26 ] ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 ; V_26 ++ ) {
F_5 ( V_2 -> V_28 [ V_26 ] ,
V_29 ,
V_2 -> V_30 [ 0 ] [ V_26 ] ) ;
F_5 ( V_2 -> V_28 [ V_26 ] ,
V_31 ,
V_2 -> V_30 [ 1 ] [ V_26 ] ) ;
F_5 ( V_2 -> V_28 [ V_26 ] ,
V_32 ,
V_2 -> V_30 [ 2 ] [ V_26 ] ) ;
F_5 ( V_2 -> V_28 [ V_26 ] ,
V_33 ,
V_2 -> V_30 [ 3 ] [ V_26 ] ) ;
F_5 ( V_2 -> V_28 [ V_26 ] ,
V_34 ,
V_2 -> V_30 [ 4 ] [ V_26 ] ) ;
}
return 0 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_8 ;
if ( V_2 -> V_7 -> V_35 == 0 )
return ! F_1 ( V_2 ) ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_36 , & V_8 ) ;
return ! ( V_8 & V_2 -> V_7 -> V_35 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
bool V_37 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
bool V_38 ;
if ( V_2 -> V_7 -> V_39 == 0 )
return;
else if ( V_2 -> V_7 -> V_40 )
F_5 ( V_4 -> V_9 , V_4 -> V_7 -> V_41 ,
V_37 ? V_2 -> V_7 -> V_39 :
( V_2 -> V_7 -> V_39 | V_2 -> V_7 -> V_40 ) ) ;
else
F_6 ( V_4 -> V_9 , V_4 -> V_7 -> V_41 ,
V_2 -> V_7 -> V_39 , V_37 ? 0 : - 1U ) ;
F_7 ( V_22 ) ;
if ( F_8 ( F_12 , V_2 , V_38 ,
V_38 == V_37 , 0 , 10000 ) ) {
F_9 ( V_4 -> V_24 ,
L_3 ,
V_15 -> V_25 , V_38 ) ;
return;
}
}
static int F_14 ( struct V_1 * V_2 , bool V_42 )
{
int V_26 ;
F_15 ( & V_2 -> V_4 -> V_43 ) ;
if ( F_12 ( V_2 ) != V_42 ) {
for ( V_26 = 0 ; V_26 < V_2 -> V_44 ; V_26 ++ )
F_16 ( V_2 -> V_45 [ V_26 ] ) ;
if ( ! V_42 ) {
F_10 ( V_2 ) ;
F_4 ( V_2 , true ) ;
}
F_13 ( V_2 , V_42 ) ;
if ( V_42 ) {
F_4 ( V_2 , false ) ;
F_11 ( V_2 ) ;
}
for ( V_26 = V_2 -> V_44 - 1 ; V_26 >= 0 ; V_26 -- )
F_17 ( V_2 -> V_45 [ V_26 ] ) ;
}
F_18 ( & V_2 -> V_4 -> V_43 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_46 )
{
struct V_1 * V_2 = F_20 ( V_46 ) ;
return F_14 ( V_2 , true ) ;
}
static int F_21 ( struct V_14 * V_46 )
{
struct V_1 * V_2 = F_20 ( V_46 ) ;
return F_14 ( V_2 , false ) ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_47 * V_24 )
{
struct V_48 * V_48 ;
int V_26 ;
int error ;
F_23 ( V_24 , L_4 , V_15 -> V_25 ) ;
error = F_24 ( V_24 ) ;
if ( error ) {
F_9 ( V_24 , L_5 , error ) ;
return error ;
}
V_26 = 0 ;
while ( ( V_48 = F_25 ( V_24 -> V_49 , V_26 ++ ) ) && ! F_26 ( V_48 ) ) {
F_23 ( V_24 , L_6 , V_48 ) ;
error = F_27 ( V_24 , V_48 ) ;
if ( error ) {
F_9 ( V_24 , L_7 , error ) ;
F_28 ( V_48 ) ;
F_29 ( V_24 ) ;
return error ;
}
}
return 0 ;
}
static void F_30 ( struct V_14 * V_15 ,
struct V_47 * V_24 )
{
F_23 ( V_24 , L_8 , V_15 -> V_25 ) ;
F_29 ( V_24 ) ;
}
static bool F_31 ( struct V_47 * V_24 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_15 = F_32 ( V_24 -> V_50 ) ;
V_2 = F_33 ( V_15 , struct V_1 , V_15 ) ;
return V_2 -> V_7 -> V_51 ;
}
static int F_34 ( struct V_3 * V_4 ,
struct V_52 * V_53 )
{
const struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_52 * V_54 ;
struct V_48 * V_48 ;
int V_55 ;
int V_26 , V_56 ;
T_1 V_57 ;
int error ;
error = F_35 ( V_53 , L_9 , & V_57 ) ;
if ( error ) {
F_9 ( V_4 -> V_24 ,
L_10 ,
V_53 -> V_25 , error ) ;
return - V_58 ;
}
if ( V_57 >= V_4 -> V_7 -> V_59 ) {
F_9 ( V_4 -> V_24 , L_11 ,
V_53 -> V_25 , V_57 ) ;
return - V_58 ;
}
V_6 = & V_4 -> V_7 -> V_60 [ V_57 ] ;
if ( ! V_6 ) {
F_9 ( V_4 -> V_24 , L_12 ,
V_53 -> V_25 , V_57 ) ;
return - V_58 ;
}
V_55 = F_36 ( V_53 , L_13 , L_14 ) ;
V_2 = F_37 ( V_4 -> V_24 ,
sizeof( * V_2 ) + V_55 * sizeof( V_2 -> V_45 [ 0 ] ) ,
V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
V_48 = F_25 ( V_53 , V_26 ) ;
if ( F_26 ( V_48 ) ) {
error = F_38 ( V_48 ) ;
F_9 ( V_4 -> V_24 ,
L_15 ,
V_53 -> V_25 , V_26 , error ) ;
goto V_63;
}
error = F_39 ( V_48 ) ;
if ( error ) {
F_9 ( V_4 -> V_24 ,
L_16 ,
V_53 -> V_25 , V_48 , V_26 , error ) ;
F_28 ( V_48 ) ;
goto V_63;
}
V_2 -> V_45 [ V_2 -> V_44 ++ ] = V_48 ;
F_23 ( V_4 -> V_24 , L_17 ,
V_48 , V_53 -> V_25 ) ;
}
V_2 -> V_27 = F_36 ( V_53 , L_18 ,
NULL ) ;
if ( V_2 -> V_27 > 0 ) {
V_2 -> V_28 = F_40 ( V_4 -> V_24 , V_2 -> V_27 ,
sizeof( * V_2 -> V_28 ) ,
V_61 ) ;
if ( ! V_2 -> V_28 ) {
error = - V_62 ;
goto V_63;
}
for ( V_56 = 0 ; V_56 < V_64 ; V_56 ++ ) {
V_2 -> V_30 [ V_56 ] = F_40 ( V_4 -> V_24 ,
V_2 -> V_27 ,
sizeof( T_1 ) ,
V_61 ) ;
if ( ! V_2 -> V_30 [ V_56 ] ) {
error = - V_62 ;
goto V_63;
}
}
for ( V_56 = 0 ; V_56 < V_2 -> V_27 ; V_56 ++ ) {
V_54 = F_41 ( V_53 , L_18 , V_56 ) ;
if ( ! V_54 ) {
error = - V_65 ;
goto V_63;
}
V_2 -> V_28 [ V_56 ] = F_42 ( V_54 ) ;
if ( F_26 ( V_2 -> V_28 [ V_56 ] ) ) {
error = - V_65 ;
F_43 ( V_54 ) ;
goto V_63;
}
F_43 ( V_54 ) ;
}
}
error = F_14 ( V_2 , true ) ;
if ( error ) {
F_9 ( V_4 -> V_24 ,
L_19 ,
V_53 -> V_25 , error ) ;
goto V_63;
}
V_2 -> V_15 . V_25 = V_53 -> V_25 ;
V_2 -> V_15 . V_66 = F_21 ;
V_2 -> V_15 . V_42 = F_19 ;
V_2 -> V_15 . V_67 = F_22 ;
V_2 -> V_15 . V_68 = F_30 ;
V_2 -> V_15 . V_69 . V_51 = F_31 ;
V_2 -> V_15 . V_70 = V_71 ;
F_44 ( & V_2 -> V_15 , NULL , false ) ;
V_4 -> V_72 . V_73 [ V_57 ] = & V_2 -> V_15 ;
return 0 ;
V_63:
while ( -- V_26 >= 0 ) {
F_45 ( V_2 -> V_45 [ V_26 ] ) ;
F_28 ( V_2 -> V_45 [ V_26 ] ) ;
}
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_26 , V_18 ;
V_18 = F_47 ( & V_2 -> V_15 ) ;
if ( V_18 < 0 )
F_9 ( V_2 -> V_4 -> V_24 , L_20 ,
V_2 -> V_15 . V_25 , V_18 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_44 ; V_26 ++ ) {
F_45 ( V_2 -> V_45 [ V_26 ] ) ;
F_28 ( V_2 -> V_45 [ V_26 ] ) ;
}
F_15 ( & V_2 -> V_4 -> V_43 ) ;
V_2 -> V_44 = 0 ;
F_18 ( & V_2 -> V_4 -> V_43 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_72 . V_59 ; V_26 ++ ) {
V_15 = V_4 -> V_72 . V_73 [ V_26 ] ;
if ( V_15 ) {
V_2 = F_20 ( V_15 ) ;
F_46 ( V_2 ) ;
}
}
}
static void F_49 ( struct V_3 * V_4 ,
T_1 V_74 ,
unsigned int V_75 )
{
F_5 ( V_4 -> V_9 , V_74 , V_75 ) ;
F_5 ( V_4 -> V_9 , V_74 + 4 , V_75 ) ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_52 * V_76 )
{
struct V_52 * V_77 ;
struct V_14 * V_78 , * V_79 ;
int error ;
F_51 (parent, np) {
T_1 V_80 ;
error = F_35 ( V_76 , L_9 , & V_80 ) ;
if ( error ) {
F_9 ( V_4 -> V_24 ,
L_10 ,
V_76 -> V_25 , error ) ;
goto V_63;
}
V_79 = V_4 -> V_72 . V_73 [ V_80 ] ;
error = F_34 ( V_4 , V_77 ) ;
if ( error ) {
F_9 ( V_4 -> V_24 , L_21 ,
V_77 -> V_25 , error ) ;
goto V_63;
}
error = F_35 ( V_77 , L_9 , & V_80 ) ;
if ( error ) {
F_9 ( V_4 -> V_24 ,
L_10 ,
V_77 -> V_25 , error ) ;
goto V_63;
}
V_78 = V_4 -> V_72 . V_73 [ V_80 ] ;
error = F_52 ( V_79 , V_78 ) ;
if ( error ) {
F_9 ( V_4 -> V_24 , L_22 ,
V_79 -> V_25 , V_78 -> V_25 , error ) ;
goto V_63;
} else {
F_23 ( V_4 -> V_24 , L_23 ,
V_79 -> V_25 , V_78 -> V_25 ) ;
}
F_50 ( V_4 , V_77 ) ;
}
return 0 ;
V_63:
F_43 ( V_77 ) ;
return error ;
}
static int F_53 ( struct V_81 * V_82 )
{
struct V_47 * V_24 = & V_82 -> V_24 ;
struct V_52 * V_77 = V_24 -> V_49 ;
struct V_52 * V_53 ;
struct V_47 * V_76 ;
struct V_3 * V_4 ;
const struct V_83 * V_84 ;
const struct V_85 * V_86 ;
int error ;
if ( ! V_77 ) {
F_9 ( V_24 , L_24 ) ;
return - V_65 ;
}
V_84 = F_54 ( V_24 -> V_87 -> V_88 , V_24 ) ;
if ( ! V_84 || ! V_84 -> V_89 ) {
F_9 ( V_24 , L_25 ) ;
return - V_58 ;
}
V_86 = V_84 -> V_89 ;
V_4 = F_37 ( V_24 ,
sizeof( * V_4 ) +
V_86 -> V_59 * sizeof( V_4 -> V_73 [ 0 ] ) ,
V_61 ) ;
if ( ! V_4 )
return - V_62 ;
V_4 -> V_24 = & V_82 -> V_24 ;
F_55 ( & V_4 -> V_43 ) ;
V_4 -> V_7 = V_86 ;
V_4 -> V_72 . V_73 = V_4 -> V_73 ;
V_4 -> V_72 . V_59 = V_86 -> V_59 ;
V_76 = V_24 -> V_76 ;
if ( ! V_76 ) {
F_9 ( V_24 , L_26 ) ;
return - V_65 ;
}
V_4 -> V_9 = F_42 ( V_76 -> V_49 ) ;
if ( F_26 ( V_4 -> V_9 ) ) {
F_9 ( V_24 , L_27 ) ;
return F_38 ( V_4 -> V_9 ) ;
}
if ( V_86 -> V_90 )
F_49 ( V_4 , V_86 -> V_91 ,
V_86 -> V_90 ) ;
if ( V_86 -> V_92 )
F_49 ( V_4 , V_86 -> V_92 ,
V_86 -> V_93 ) ;
error = - V_65 ;
F_56 (np, node) {
error = F_34 ( V_4 , V_53 ) ;
if ( error ) {
F_9 ( V_24 , L_21 ,
V_53 -> V_25 , error ) ;
F_43 ( V_53 ) ;
goto V_63;
}
error = F_50 ( V_4 , V_53 ) ;
if ( error < 0 ) {
F_9 ( V_24 , L_28 ,
V_53 -> V_25 , error ) ;
F_43 ( V_53 ) ;
goto V_63;
}
}
if ( error ) {
F_23 ( V_24 , L_29 ) ;
goto V_63;
}
error = F_57 ( V_77 , & V_4 -> V_72 ) ;
if ( error ) {
F_9 ( V_24 , L_30 , error ) ;
goto V_63;
}
return 0 ;
V_63:
F_48 ( V_4 ) ;
return error ;
}
static int T_2 F_58 ( void )
{
return F_59 ( & V_94 ) ;
}
