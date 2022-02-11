static void F_1 ( const struct V_1 * V_2 ,
int V_3 , bool V_4 )
{
bool V_5 = ! V_2 -> V_6 ;
if ( V_4 ) {
F_2 ( V_2 -> V_7 [ V_3 ] , V_5 ) ;
} else {
F_3 ( V_2 -> V_7 [ V_3 ] , ! V_5 ) ;
F_4 ( V_2 -> V_7 [ V_3 ] ) ;
}
}
static void F_5 ( const struct V_1 * V_2 ,
int V_3 , bool V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_4 && V_2 -> V_8 )
F_6 ( V_2 -> V_8 ) ;
}
static void F_7 ( const struct V_1 * V_2 ,
bool V_4 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ )
F_1 ( V_2 , V_3 , V_4 ) ;
}
static bool F_8 ( const struct V_1 * V_2 ,
int V_10 )
{
return F_9 ( V_2 -> V_11 [ V_10 ] ) ?
! V_2 -> V_6 : V_2 -> V_6 ;
}
static void F_10 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_14 ;
if ( V_2 -> V_15 > 0 )
F_11 ( V_2 -> V_15 ) ;
else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ )
F_11 ( F_12 ( V_2 -> V_11 [ V_14 ] ) ) ;
}
}
static void F_13 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_14 ;
if ( V_2 -> V_15 > 0 )
F_14 ( V_2 -> V_15 ) ;
else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ )
F_14 ( F_12 ( V_2 -> V_11 [ V_14 ] ) ) ;
}
}
static void F_15 ( struct V_17 * V_18 )
{
struct V_12 * V_13 =
F_16 ( V_18 , struct V_12 , V_18 . V_18 ) ;
struct V_19 * V_19 = V_13 -> V_19 ;
const unsigned short * V_20 = V_19 -> V_21 ;
const struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_22 [ V_23 ] ;
int V_10 , V_3 , V_24 ;
F_7 ( V_2 , false ) ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
F_5 ( V_2 , V_3 , true ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_16 ; V_10 ++ )
V_22 [ V_3 ] |=
F_8 ( V_2 , V_10 ) ? ( 1 << V_10 ) : 0 ;
F_5 ( V_2 , V_3 , false ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
T_1 V_25 ;
V_25 = V_13 -> V_26 [ V_3 ] ^ V_22 [ V_3 ] ;
if ( V_25 == 0 )
continue;
for ( V_10 = 0 ; V_10 < V_2 -> V_16 ; V_10 ++ ) {
if ( ( V_25 & ( 1 << V_10 ) ) == 0 )
continue;
V_24 = F_17 ( V_10 , V_3 , V_13 -> V_27 ) ;
F_18 ( V_19 , V_28 , V_29 , V_24 ) ;
F_19 ( V_19 ,
V_20 [ V_24 ] ,
V_22 [ V_3 ] & ( 1 << V_10 ) ) ;
}
}
F_20 ( V_19 ) ;
memcpy ( V_13 -> V_26 , V_22 , sizeof( V_22 ) ) ;
F_7 ( V_2 , true ) ;
F_21 ( & V_13 -> V_30 ) ;
V_13 -> V_31 = false ;
F_10 ( V_13 ) ;
F_22 ( & V_13 -> V_30 ) ;
}
static T_2 F_23 ( int V_32 , void * V_33 )
{
struct V_12 * V_13 = V_33 ;
unsigned long V_34 ;
F_24 ( & V_13 -> V_30 , V_34 ) ;
if ( F_25 ( V_13 -> V_31 || V_13 -> V_35 ) )
goto V_36;
F_13 ( V_13 ) ;
V_13 -> V_31 = true ;
F_26 ( & V_13 -> V_18 ,
F_27 ( V_13 -> V_2 -> V_37 ) ) ;
V_36:
F_28 ( & V_13 -> V_30 , V_34 ) ;
return V_38 ;
}
static int F_29 ( struct V_19 * V_39 )
{
struct V_12 * V_13 = F_30 ( V_39 ) ;
V_13 -> V_35 = false ;
F_31 () ;
F_26 ( & V_13 -> V_18 , 0 ) ;
return 0 ;
}
static void F_32 ( struct V_19 * V_39 )
{
struct V_12 * V_13 = F_30 ( V_39 ) ;
V_13 -> V_35 = true ;
F_31 () ;
F_33 ( & V_13 -> V_18 . V_18 ) ;
F_13 ( V_13 ) ;
}
static void F_34 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
unsigned int V_40 ;
int V_14 ;
if ( V_2 -> V_15 > 0 ) {
if ( F_35 ( V_2 -> V_15 ) == 0 )
V_13 -> V_41 = true ;
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
if ( ! F_36 ( V_14 , V_13 -> V_42 ) ) {
V_40 = V_2 -> V_11 [ V_14 ] ;
if ( F_35 ( F_12 ( V_40 ) ) == 0 )
F_37 ( V_14 , V_13 -> V_42 ) ;
}
}
}
}
static void F_38 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
unsigned int V_40 ;
int V_14 ;
if ( V_2 -> V_15 > 0 ) {
if ( V_13 -> V_41 ) {
F_39 ( V_2 -> V_15 ) ;
V_13 -> V_41 = false ;
}
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
if ( F_40 ( V_14 , V_13 -> V_42 ) ) {
V_40 = V_2 -> V_11 [ V_14 ] ;
F_39 ( F_12 ( V_40 ) ) ;
}
}
}
}
static int F_41 ( struct V_43 * V_39 )
{
struct V_44 * V_45 = F_42 ( V_39 ) ;
struct V_12 * V_13 = F_43 ( V_45 ) ;
F_32 ( V_13 -> V_19 ) ;
if ( F_44 ( & V_45 -> V_39 ) )
F_34 ( V_13 ) ;
return 0 ;
}
static int F_45 ( struct V_43 * V_39 )
{
struct V_44 * V_45 = F_42 ( V_39 ) ;
struct V_12 * V_13 = F_43 ( V_45 ) ;
if ( F_44 ( & V_45 -> V_39 ) )
F_38 ( V_13 ) ;
F_29 ( V_13 -> V_19 ) ;
return 0 ;
}
static int F_46 ( struct V_44 * V_45 ,
struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_14 , V_46 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_9 ; V_14 ++ ) {
V_46 = F_47 ( V_2 -> V_7 [ V_14 ] , L_1 ) ;
if ( V_46 ) {
F_48 ( & V_45 -> V_39 ,
L_2 ,
V_2 -> V_7 [ V_14 ] , V_14 ) ;
goto V_47;
}
F_2 ( V_2 -> V_7 [ V_14 ] , ! V_2 -> V_6 ) ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_46 = F_47 ( V_2 -> V_11 [ V_14 ] , L_3 ) ;
if ( V_46 ) {
F_48 ( & V_45 -> V_39 ,
L_4 ,
V_2 -> V_11 [ V_14 ] , V_14 ) ;
goto V_48;
}
F_4 ( V_2 -> V_11 [ V_14 ] ) ;
}
if ( V_2 -> V_15 > 0 ) {
V_46 = F_49 ( V_2 -> V_15 ,
F_23 ,
V_2 -> V_49 ,
L_5 , V_13 ) ;
if ( V_46 ) {
F_48 ( & V_45 -> V_39 ,
L_6 ) ;
goto V_48;
}
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_46 = F_49 ( F_12 ( V_2 -> V_11 [ V_14 ] ) ,
F_23 ,
V_50 |
V_51 ,
L_5 , V_13 ) ;
if ( V_46 ) {
F_48 ( & V_45 -> V_39 ,
L_7 ,
V_2 -> V_11 [ V_14 ] ) ;
goto V_52;
}
}
}
F_13 ( V_13 ) ;
return 0 ;
V_52:
while ( -- V_14 >= 0 )
F_50 ( F_12 ( V_2 -> V_11 [ V_14 ] ) , V_13 ) ;
V_14 = V_2 -> V_16 ;
V_48:
while ( -- V_14 >= 0 )
F_51 ( V_2 -> V_11 [ V_14 ] ) ;
V_14 = V_2 -> V_9 ;
V_47:
while ( -- V_14 >= 0 )
F_51 ( V_2 -> V_7 [ V_14 ] ) ;
return V_46 ;
}
static void F_52 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_14 ;
if ( V_2 -> V_15 > 0 ) {
F_50 ( V_2 -> V_15 , V_13 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ )
F_50 ( F_12 ( V_2 -> V_11 [ V_14 ] ) , V_13 ) ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ )
F_51 ( V_2 -> V_11 [ V_14 ] ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_9 ; V_14 ++ )
F_51 ( V_2 -> V_7 [ V_14 ] ) ;
}
static struct V_1 *
F_53 ( struct V_43 * V_39 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 = V_39 -> V_55 ;
unsigned int * V_56 ;
int V_14 , V_57 , V_58 ;
if ( ! V_54 ) {
F_48 ( V_39 , L_8 ) ;
return F_54 ( - V_59 ) ;
}
V_2 = F_55 ( V_39 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 ) {
F_48 ( V_39 , L_9 ) ;
return F_54 ( - V_61 ) ;
}
V_2 -> V_16 = V_57 = F_56 ( V_54 , L_10 ) ;
V_2 -> V_9 = V_58 = F_56 ( V_54 , L_11 ) ;
if ( V_57 <= 0 || V_58 <= 0 ) {
F_48 ( V_39 , L_12 ) ;
return F_54 ( - V_62 ) ;
}
if ( F_57 ( V_54 , L_13 , NULL ) )
V_2 -> V_63 = true ;
if ( F_57 ( V_54 , L_14 , NULL ) )
V_2 -> V_64 = true ;
if ( F_57 ( V_54 , L_15 , NULL ) )
V_2 -> V_6 = true ;
F_58 ( V_54 , L_16 , & V_2 -> V_37 ) ;
F_58 ( V_54 , L_17 ,
& V_2 -> V_8 ) ;
V_56 = F_55 ( V_39 ,
sizeof( unsigned int ) *
( V_2 -> V_16 + V_2 -> V_9 ) ,
V_60 ) ;
if ( ! V_56 ) {
F_48 ( V_39 , L_18 ) ;
return F_54 ( - V_61 ) ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ )
V_56 [ V_14 ] = F_59 ( V_54 , L_10 , V_14 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_9 ; V_14 ++ )
V_56 [ V_2 -> V_16 + V_14 ] =
F_59 ( V_54 , L_11 , V_14 ) ;
V_2 -> V_11 = V_56 ;
V_2 -> V_7 = & V_56 [ V_2 -> V_16 ] ;
return V_2 ;
}
static inline struct V_1 *
F_53 ( struct V_43 * V_39 )
{
F_48 ( V_39 , L_19 ) ;
return F_54 ( - V_62 ) ;
}
static int F_60 ( struct V_44 * V_45 )
{
const struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_19 * V_19 ;
int V_46 ;
V_2 = F_61 ( & V_45 -> V_39 ) ;
if ( ! V_2 ) {
V_2 = F_53 ( & V_45 -> V_39 ) ;
if ( F_62 ( V_2 ) ) {
F_48 ( & V_45 -> V_39 , L_19 ) ;
return F_63 ( V_2 ) ;
}
} else if ( ! V_2 -> V_65 ) {
F_48 ( & V_45 -> V_39 , L_20 ) ;
return - V_62 ;
}
V_13 = F_64 ( sizeof( struct V_12 ) , V_60 ) ;
V_19 = F_65 () ;
if ( ! V_13 || ! V_19 ) {
V_46 = - V_61 ;
goto V_66;
}
V_13 -> V_19 = V_19 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_27 = F_66 ( V_2 -> V_9 ) ;
V_13 -> V_35 = true ;
F_67 ( & V_13 -> V_18 , F_15 ) ;
F_68 ( & V_13 -> V_30 ) ;
V_19 -> V_67 = V_45 -> V_67 ;
V_19 -> V_33 . V_68 = V_69 ;
V_19 -> V_39 . V_70 = & V_45 -> V_39 ;
V_19 -> V_71 = F_29 ;
V_19 -> V_72 = F_32 ;
V_46 = F_69 ( V_2 -> V_65 , NULL ,
V_2 -> V_16 ,
V_2 -> V_9 ,
NULL , V_19 ) ;
if ( V_46 ) {
F_48 ( & V_45 -> V_39 , L_21 ) ;
goto V_66;
}
if ( ! V_2 -> V_63 )
F_37 ( V_73 , V_19 -> V_74 ) ;
F_70 ( V_19 , V_28 , V_29 ) ;
F_71 ( V_19 , V_13 ) ;
V_46 = F_46 ( V_45 , V_13 ) ;
if ( V_46 )
goto V_66;
V_46 = F_72 ( V_13 -> V_19 ) ;
if ( V_46 )
goto V_75;
F_73 ( & V_45 -> V_39 , V_2 -> V_64 ) ;
F_74 ( V_45 , V_13 ) ;
return 0 ;
V_75:
F_52 ( V_13 ) ;
V_66:
F_75 ( V_19 ) ;
F_76 ( V_13 ) ;
return V_46 ;
}
static int F_77 ( struct V_44 * V_45 )
{
struct V_12 * V_13 = F_43 ( V_45 ) ;
F_73 ( & V_45 -> V_39 , 0 ) ;
F_52 ( V_13 ) ;
F_78 ( V_13 -> V_19 ) ;
F_76 ( V_13 ) ;
F_74 ( V_45 , NULL ) ;
return 0 ;
}
