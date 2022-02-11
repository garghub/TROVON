static void F_1 ( const struct V_1 * V_2 ,
int V_3 , bool V_4 )
{
bool V_5 = ! V_2 -> V_6 ;
if ( V_4 ) {
F_2 ( V_2 -> V_7 [ V_3 ] , V_5 ) ;
} else {
F_3 ( V_2 -> V_7 [ V_3 ] , ! V_5 ) ;
if ( ! V_2 -> V_8 )
F_4 ( V_2 -> V_7 [ V_3 ] ) ;
}
}
static void F_5 ( const struct V_1 * V_2 ,
int V_3 , bool V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_4 && V_2 -> V_9 )
F_6 ( V_2 -> V_9 ) ;
}
static void F_7 ( const struct V_1 * V_2 ,
bool V_4 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ )
F_1 ( V_2 , V_3 , V_4 ) ;
}
static bool F_8 ( const struct V_1 * V_2 ,
int V_11 )
{
return F_9 ( V_2 -> V_12 [ V_11 ] ) ?
! V_2 -> V_6 : V_2 -> V_6 ;
}
static void F_10 ( struct V_13 * V_14 )
{
const struct V_1 * V_2 = V_14 -> V_2 ;
int V_15 ;
if ( V_2 -> V_16 > 0 )
F_11 ( V_2 -> V_16 ) ;
else {
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ )
F_11 ( F_12 ( V_2 -> V_12 [ V_15 ] ) ) ;
}
}
static void F_13 ( struct V_13 * V_14 )
{
const struct V_1 * V_2 = V_14 -> V_2 ;
int V_15 ;
if ( V_2 -> V_16 > 0 )
F_14 ( V_2 -> V_16 ) ;
else {
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ )
F_14 ( F_12 ( V_2 -> V_12 [ V_15 ] ) ) ;
}
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_13 * V_14 =
F_16 ( V_19 , struct V_13 , V_19 . V_19 ) ;
struct V_20 * V_20 = V_14 -> V_20 ;
const unsigned short * V_21 = V_20 -> V_22 ;
const struct V_1 * V_2 = V_14 -> V_2 ;
T_1 V_23 [ V_24 ] ;
int V_11 , V_3 , V_25 ;
F_7 ( V_2 , false ) ;
memset ( V_23 , 0 , sizeof( V_23 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
F_5 ( V_2 , V_3 , true ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_17 ; V_11 ++ )
V_23 [ V_3 ] |=
F_8 ( V_2 , V_11 ) ? ( 1 << V_11 ) : 0 ;
F_5 ( V_2 , V_3 , false ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
T_1 V_26 ;
V_26 = V_14 -> V_27 [ V_3 ] ^ V_23 [ V_3 ] ;
if ( V_26 == 0 )
continue;
for ( V_11 = 0 ; V_11 < V_2 -> V_17 ; V_11 ++ ) {
if ( ( V_26 & ( 1 << V_11 ) ) == 0 )
continue;
V_25 = F_17 ( V_11 , V_3 , V_14 -> V_28 ) ;
F_18 ( V_20 , V_29 , V_30 , V_25 ) ;
F_19 ( V_20 ,
V_21 [ V_25 ] ,
V_23 [ V_3 ] & ( 1 << V_11 ) ) ;
}
}
F_20 ( V_20 ) ;
memcpy ( V_14 -> V_27 , V_23 , sizeof( V_23 ) ) ;
F_7 ( V_2 , true ) ;
F_21 ( & V_14 -> V_31 ) ;
V_14 -> V_32 = false ;
F_10 ( V_14 ) ;
F_22 ( & V_14 -> V_31 ) ;
}
static T_2 F_23 ( int V_33 , void * V_34 )
{
struct V_13 * V_14 = V_34 ;
unsigned long V_35 ;
F_24 ( & V_14 -> V_31 , V_35 ) ;
if ( F_25 ( V_14 -> V_32 || V_14 -> V_36 ) )
goto V_37;
F_13 ( V_14 ) ;
V_14 -> V_32 = true ;
F_26 ( & V_14 -> V_19 ,
F_27 ( V_14 -> V_2 -> V_38 ) ) ;
V_37:
F_28 ( & V_14 -> V_31 , V_35 ) ;
return V_39 ;
}
static int F_29 ( struct V_20 * V_40 )
{
struct V_13 * V_14 = F_30 ( V_40 ) ;
V_14 -> V_36 = false ;
F_31 () ;
F_26 ( & V_14 -> V_19 , 0 ) ;
return 0 ;
}
static void F_32 ( struct V_20 * V_40 )
{
struct V_13 * V_14 = F_30 ( V_40 ) ;
V_14 -> V_36 = true ;
F_31 () ;
F_33 ( & V_14 -> V_19 . V_19 ) ;
F_13 ( V_14 ) ;
}
static void F_34 ( struct V_13 * V_14 )
{
const struct V_1 * V_2 = V_14 -> V_2 ;
unsigned int V_41 ;
int V_15 ;
if ( V_2 -> V_16 > 0 ) {
if ( F_35 ( V_2 -> V_16 ) == 0 )
V_14 -> V_42 = true ;
} else {
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ ) {
if ( ! F_36 ( V_15 , V_14 -> V_43 ) ) {
V_41 = V_2 -> V_12 [ V_15 ] ;
if ( F_35 ( F_12 ( V_41 ) ) == 0 )
F_37 ( V_15 , V_14 -> V_43 ) ;
}
}
}
}
static void F_38 ( struct V_13 * V_14 )
{
const struct V_1 * V_2 = V_14 -> V_2 ;
unsigned int V_41 ;
int V_15 ;
if ( V_2 -> V_16 > 0 ) {
if ( V_14 -> V_42 ) {
F_39 ( V_2 -> V_16 ) ;
V_14 -> V_42 = false ;
}
} else {
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ ) {
if ( F_40 ( V_15 , V_14 -> V_43 ) ) {
V_41 = V_2 -> V_12 [ V_15 ] ;
F_39 ( F_12 ( V_41 ) ) ;
}
}
}
}
static int F_41 ( struct V_44 * V_40 )
{
struct V_45 * V_46 = F_42 ( V_40 ) ;
struct V_13 * V_14 = F_43 ( V_46 ) ;
F_32 ( V_14 -> V_20 ) ;
if ( F_44 ( & V_46 -> V_40 ) )
F_34 ( V_14 ) ;
return 0 ;
}
static int F_45 ( struct V_44 * V_40 )
{
struct V_45 * V_46 = F_42 ( V_40 ) ;
struct V_13 * V_14 = F_43 ( V_46 ) ;
if ( F_44 ( & V_46 -> V_40 ) )
F_38 ( V_14 ) ;
F_29 ( V_14 -> V_20 ) ;
return 0 ;
}
static int F_46 ( struct V_45 * V_46 ,
struct V_13 * V_14 )
{
const struct V_1 * V_2 = V_14 -> V_2 ;
int V_15 , V_47 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_10 ; V_15 ++ ) {
V_47 = F_47 ( V_2 -> V_7 [ V_15 ] , L_1 ) ;
if ( V_47 ) {
F_48 ( & V_46 -> V_40 ,
L_2 ,
V_2 -> V_7 [ V_15 ] , V_15 ) ;
goto V_48;
}
F_2 ( V_2 -> V_7 [ V_15 ] , ! V_2 -> V_6 ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ ) {
V_47 = F_47 ( V_2 -> V_12 [ V_15 ] , L_3 ) ;
if ( V_47 ) {
F_48 ( & V_46 -> V_40 ,
L_4 ,
V_2 -> V_12 [ V_15 ] , V_15 ) ;
goto V_49;
}
F_4 ( V_2 -> V_12 [ V_15 ] ) ;
}
if ( V_2 -> V_16 > 0 ) {
V_47 = F_49 ( V_2 -> V_16 ,
F_23 ,
V_2 -> V_50 ,
L_5 , V_14 ) ;
if ( V_47 < 0 ) {
F_48 ( & V_46 -> V_40 ,
L_6 ) ;
goto V_49;
}
} else {
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ ) {
V_47 = F_49 (
F_12 ( V_2 -> V_12 [ V_15 ] ) ,
F_23 ,
V_51 |
V_52 ,
L_5 , V_14 ) ;
if ( V_47 < 0 ) {
F_48 ( & V_46 -> V_40 ,
L_7 ,
V_2 -> V_12 [ V_15 ] ) ;
goto V_53;
}
}
}
F_13 ( V_14 ) ;
return 0 ;
V_53:
while ( -- V_15 >= 0 )
F_50 ( F_12 ( V_2 -> V_12 [ V_15 ] ) , V_14 ) ;
V_15 = V_2 -> V_17 ;
V_49:
while ( -- V_15 >= 0 )
F_51 ( V_2 -> V_12 [ V_15 ] ) ;
V_15 = V_2 -> V_10 ;
V_48:
while ( -- V_15 >= 0 )
F_51 ( V_2 -> V_7 [ V_15 ] ) ;
return V_47 ;
}
static void F_52 ( struct V_13 * V_14 )
{
const struct V_1 * V_2 = V_14 -> V_2 ;
int V_15 ;
if ( V_2 -> V_16 > 0 ) {
F_50 ( V_2 -> V_16 , V_14 ) ;
} else {
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ )
F_50 ( F_12 ( V_2 -> V_12 [ V_15 ] ) , V_14 ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ )
F_51 ( V_2 -> V_12 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_10 ; V_15 ++ )
F_51 ( V_2 -> V_7 [ V_15 ] ) ;
}
static struct V_1 *
F_53 ( struct V_44 * V_40 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 = V_40 -> V_56 ;
unsigned int * V_57 ;
int V_15 , V_58 , V_59 ;
if ( ! V_55 ) {
F_48 ( V_40 , L_8 ) ;
return F_54 ( - V_60 ) ;
}
V_2 = F_55 ( V_40 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 ) {
F_48 ( V_40 , L_9 ) ;
return F_54 ( - V_62 ) ;
}
V_2 -> V_17 = V_58 = F_56 ( V_55 , L_10 ) ;
V_2 -> V_10 = V_59 = F_56 ( V_55 , L_11 ) ;
if ( V_58 <= 0 || V_59 <= 0 ) {
F_48 ( V_40 , L_12 ) ;
return F_54 ( - V_63 ) ;
}
if ( F_57 ( V_55 , L_13 , NULL ) )
V_2 -> V_64 = true ;
V_2 -> V_65 = F_58 ( V_55 , L_14 ) ||
F_58 ( V_55 , L_15 ) ;
if ( F_57 ( V_55 , L_16 , NULL ) )
V_2 -> V_6 = true ;
V_2 -> V_8 =
F_58 ( V_55 , L_17 ) ;
F_59 ( V_55 , L_18 , & V_2 -> V_38 ) ;
F_59 ( V_55 , L_19 ,
& V_2 -> V_9 ) ;
V_57 = F_55 ( V_40 ,
sizeof( unsigned int ) *
( V_2 -> V_17 + V_2 -> V_10 ) ,
V_61 ) ;
if ( ! V_57 ) {
F_48 ( V_40 , L_20 ) ;
return F_54 ( - V_62 ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_17 ; V_15 ++ )
V_57 [ V_15 ] = F_60 ( V_55 , L_10 , V_15 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_10 ; V_15 ++ )
V_57 [ V_2 -> V_17 + V_15 ] =
F_60 ( V_55 , L_11 , V_15 ) ;
V_2 -> V_12 = V_57 ;
V_2 -> V_7 = & V_57 [ V_2 -> V_17 ] ;
return V_2 ;
}
static inline struct V_1 *
F_53 ( struct V_44 * V_40 )
{
F_48 ( V_40 , L_21 ) ;
return F_54 ( - V_63 ) ;
}
static int F_61 ( struct V_45 * V_46 )
{
const struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_20 * V_20 ;
int V_47 ;
V_2 = F_62 ( & V_46 -> V_40 ) ;
if ( ! V_2 ) {
V_2 = F_53 ( & V_46 -> V_40 ) ;
if ( F_63 ( V_2 ) ) {
F_48 ( & V_46 -> V_40 , L_21 ) ;
return F_64 ( V_2 ) ;
}
} else if ( ! V_2 -> V_66 ) {
F_48 ( & V_46 -> V_40 , L_22 ) ;
return - V_63 ;
}
V_14 = F_65 ( sizeof( struct V_13 ) , V_61 ) ;
V_20 = F_66 () ;
if ( ! V_14 || ! V_20 ) {
V_47 = - V_62 ;
goto V_67;
}
V_14 -> V_20 = V_20 ;
V_14 -> V_2 = V_2 ;
V_14 -> V_28 = F_67 ( V_2 -> V_10 ) ;
V_14 -> V_36 = true ;
F_68 ( & V_14 -> V_19 , F_15 ) ;
F_69 ( & V_14 -> V_31 ) ;
V_20 -> V_68 = V_46 -> V_68 ;
V_20 -> V_34 . V_69 = V_70 ;
V_20 -> V_40 . V_71 = & V_46 -> V_40 ;
V_20 -> V_72 = F_29 ;
V_20 -> V_73 = F_32 ;
V_47 = F_70 ( V_2 -> V_66 , NULL ,
V_2 -> V_17 ,
V_2 -> V_10 ,
NULL , V_20 ) ;
if ( V_47 ) {
F_48 ( & V_46 -> V_40 , L_23 ) ;
goto V_67;
}
if ( ! V_2 -> V_64 )
F_37 ( V_74 , V_20 -> V_75 ) ;
F_71 ( V_20 , V_29 , V_30 ) ;
F_72 ( V_20 , V_14 ) ;
V_47 = F_46 ( V_46 , V_14 ) ;
if ( V_47 )
goto V_67;
V_47 = F_73 ( V_14 -> V_20 ) ;
if ( V_47 )
goto V_76;
F_74 ( & V_46 -> V_40 , V_2 -> V_65 ) ;
F_75 ( V_46 , V_14 ) ;
return 0 ;
V_76:
F_52 ( V_14 ) ;
V_67:
F_76 ( V_20 ) ;
F_77 ( V_14 ) ;
return V_47 ;
}
static int F_78 ( struct V_45 * V_46 )
{
struct V_13 * V_14 = F_43 ( V_46 ) ;
F_52 ( V_14 ) ;
F_79 ( V_14 -> V_20 ) ;
F_77 ( V_14 ) ;
return 0 ;
}
