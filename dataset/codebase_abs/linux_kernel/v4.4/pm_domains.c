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
F_4 ( V_4 -> V_9 , V_4 -> V_7 -> V_13 ,
V_6 -> V_14 , V_12 ? - 1U : 0 ) ;
F_5 ( V_15 ) ;
do {
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_16 , & V_8 ) ;
} while ( ( V_8 & V_6 -> V_17 ) != ( V_12 ? V_6 -> V_17 : 0 ) );
while ( F_1 ( V_2 ) != V_12 )
F_6 () ;
return 0 ;
}
static bool F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_8 ;
F_2 ( V_4 -> V_9 , V_4 -> V_7 -> V_18 , & V_8 ) ;
return ! ( V_8 & V_2 -> V_7 -> V_19 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
bool V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 -> V_9 , V_4 -> V_7 -> V_21 ,
V_2 -> V_7 -> V_22 , V_20 ? 0 : - 1U ) ;
F_5 ( V_15 ) ;
while ( F_7 ( V_2 ) != V_20 )
F_6 () ;
}
static int F_9 ( struct V_1 * V_2 , bool V_23 )
{
int V_24 ;
F_10 ( & V_2 -> V_4 -> V_25 ) ;
if ( F_7 ( V_2 ) != V_23 ) {
for ( V_24 = 0 ; V_24 < V_2 -> V_26 ; V_24 ++ )
F_11 ( V_2 -> V_27 [ V_24 ] ) ;
if ( ! V_23 ) {
F_3 ( V_2 , true ) ;
}
F_8 ( V_2 , V_23 ) ;
if ( V_23 ) {
F_3 ( V_2 , false ) ;
}
for ( V_24 = V_2 -> V_26 - 1 ; V_24 >= 0 ; V_24 -- )
F_12 ( V_2 -> V_27 [ V_24 ] ) ;
}
F_13 ( & V_2 -> V_4 -> V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
return F_9 ( V_2 , true ) ;
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
return F_9 ( V_2 , false ) ;
}
static int F_17 ( struct V_28 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_33 ;
int V_24 ;
int error ;
F_18 ( V_32 , L_1 , V_30 -> V_34 ) ;
error = F_19 ( V_32 ) ;
if ( error ) {
F_20 ( V_32 , L_2 , error ) ;
return error ;
}
V_24 = 0 ;
while ( ( V_33 = F_21 ( V_32 -> V_35 , V_24 ++ ) ) && ! F_22 ( V_33 ) ) {
F_18 ( V_32 , L_3 , V_33 ) ;
error = F_23 ( V_32 , V_33 ) ;
if ( error ) {
F_20 ( V_32 , L_4 , error ) ;
F_24 ( V_33 ) ;
F_25 ( V_32 ) ;
return error ;
}
}
return 0 ;
}
static void F_26 ( struct V_28 * V_30 ,
struct V_31 * V_32 )
{
F_18 ( V_32 , L_5 , V_30 -> V_34 ) ;
F_25 ( V_32 ) ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
const struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_33 * V_33 ;
int V_38 ;
int V_24 ;
T_1 V_39 ;
int error ;
error = F_28 ( V_37 , L_6 , & V_39 ) ;
if ( error ) {
F_20 ( V_4 -> V_32 ,
L_7 ,
V_37 -> V_34 , error ) ;
return - V_40 ;
}
if ( V_39 >= V_4 -> V_7 -> V_41 ) {
F_20 ( V_4 -> V_32 , L_8 ,
V_37 -> V_34 , V_39 ) ;
return - V_40 ;
}
V_6 = & V_4 -> V_7 -> V_42 [ V_39 ] ;
if ( ! V_6 ) {
F_20 ( V_4 -> V_32 , L_9 ,
V_37 -> V_34 , V_39 ) ;
return - V_40 ;
}
V_38 = F_29 ( V_37 , L_10 , L_11 ) ;
V_2 = F_30 ( V_4 -> V_32 ,
sizeof( * V_2 ) + V_38 * sizeof( V_2 -> V_27 [ 0 ] ) ,
V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_4 = V_4 ;
for ( V_24 = 0 ; V_24 < V_38 ; V_24 ++ ) {
V_33 = F_21 ( V_37 , V_24 ) ;
if ( F_22 ( V_33 ) ) {
error = F_31 ( V_33 ) ;
F_20 ( V_4 -> V_32 ,
L_12 ,
V_37 -> V_34 , V_24 , error ) ;
goto V_45;
}
error = F_32 ( V_33 ) ;
if ( error ) {
F_20 ( V_4 -> V_32 ,
L_13 ,
V_37 -> V_34 , V_33 , V_24 , error ) ;
F_24 ( V_33 ) ;
goto V_45;
}
V_2 -> V_27 [ V_2 -> V_26 ++ ] = V_33 ;
F_18 ( V_4 -> V_32 , L_14 ,
V_33 , V_37 -> V_34 ) ;
}
error = F_9 ( V_2 , true ) ;
if ( error ) {
F_20 ( V_4 -> V_32 ,
L_15 ,
V_37 -> V_34 , error ) ;
goto V_45;
}
V_2 -> V_30 . V_34 = V_37 -> V_34 ;
V_2 -> V_30 . V_46 = F_16 ;
V_2 -> V_30 . V_23 = F_14 ;
V_2 -> V_30 . V_47 = F_17 ;
V_2 -> V_30 . V_48 = F_26 ;
V_2 -> V_30 . V_49 = V_50 ;
F_33 ( & V_2 -> V_30 , NULL , false ) ;
V_4 -> V_51 . V_52 [ V_39 ] = & V_2 -> V_30 ;
return 0 ;
V_45:
while ( -- V_24 >= 0 ) {
F_34 ( V_2 -> V_27 [ V_24 ] ) ;
F_24 ( V_2 -> V_27 [ V_24 ] ) ;
}
return error ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_26 ; V_24 ++ ) {
F_34 ( V_2 -> V_27 [ V_24 ] ) ;
F_24 ( V_2 -> V_27 [ V_24 ] ) ;
}
F_10 ( & V_2 -> V_4 -> V_25 ) ;
V_2 -> V_26 = 0 ;
F_13 ( & V_2 -> V_4 -> V_25 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_28 * V_30 ;
struct V_1 * V_2 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_51 . V_41 ; V_24 ++ ) {
V_30 = V_4 -> V_51 . V_52 [ V_24 ] ;
if ( V_30 ) {
V_2 = F_15 ( V_30 ) ;
F_35 ( V_2 ) ;
}
}
}
static void F_37 ( struct V_3 * V_4 ,
T_1 V_53 ,
unsigned int V_54 )
{
F_38 ( V_4 -> V_9 , V_53 , V_54 ) ;
F_38 ( V_4 -> V_9 , V_53 + 4 , V_54 ) ;
}
static int F_39 ( struct V_55 * V_56 )
{
struct V_31 * V_32 = & V_56 -> V_32 ;
struct V_36 * V_57 = V_32 -> V_35 ;
struct V_36 * V_37 ;
struct V_31 * V_58 ;
struct V_3 * V_4 ;
const struct V_59 * V_60 ;
const struct V_61 * V_62 ;
int error ;
if ( ! V_57 ) {
F_20 ( V_32 , L_16 ) ;
return - V_63 ;
}
V_60 = F_40 ( V_32 -> V_64 -> V_65 , V_32 ) ;
if ( ! V_60 || ! V_60 -> V_66 ) {
F_20 ( V_32 , L_17 ) ;
return - V_40 ;
}
V_62 = V_60 -> V_66 ;
V_4 = F_30 ( V_32 ,
sizeof( * V_4 ) +
V_62 -> V_41 * sizeof( V_4 -> V_52 [ 0 ] ) ,
V_43 ) ;
if ( ! V_4 )
return - V_44 ;
V_4 -> V_32 = & V_56 -> V_32 ;
F_41 ( & V_4 -> V_25 ) ;
V_4 -> V_7 = V_62 ;
V_4 -> V_51 . V_52 = V_4 -> V_52 ;
V_4 -> V_51 . V_41 = V_62 -> V_41 ;
V_58 = V_32 -> V_58 ;
if ( ! V_58 ) {
F_20 ( V_32 , L_18 ) ;
return - V_63 ;
}
V_4 -> V_9 = F_42 ( V_58 -> V_35 ) ;
F_37 ( V_4 , V_62 -> V_67 ,
V_62 -> V_68 ) ;
F_37 ( V_4 , V_62 -> V_69 ,
V_62 -> V_70 ) ;
error = - V_63 ;
F_43 (np, node) {
error = F_27 ( V_4 , V_37 ) ;
if ( error ) {
F_20 ( V_32 , L_19 ,
V_37 -> V_34 , error ) ;
goto V_45;
}
}
if ( error ) {
F_18 ( V_32 , L_20 ) ;
goto V_45;
}
F_44 ( V_57 , & V_4 -> V_51 ) ;
return 0 ;
V_45:
F_36 ( V_4 ) ;
return error ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_71 ) ;
}
