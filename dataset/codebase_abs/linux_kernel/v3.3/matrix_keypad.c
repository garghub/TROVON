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
const struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_20 [ V_21 ] ;
int V_10 , V_3 , V_22 ;
F_7 ( V_2 , false ) ;
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
F_5 ( V_2 , V_3 , true ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_16 ; V_10 ++ )
V_20 [ V_3 ] |=
F_8 ( V_2 , V_10 ) ? ( 1 << V_10 ) : 0 ;
F_5 ( V_2 , V_3 , false ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
T_1 V_23 ;
V_23 = V_13 -> V_24 [ V_3 ] ^ V_20 [ V_3 ] ;
if ( V_23 == 0 )
continue;
for ( V_10 = 0 ; V_10 < V_2 -> V_16 ; V_10 ++ ) {
if ( ( V_23 & ( 1 << V_10 ) ) == 0 )
continue;
V_22 = F_17 ( V_10 , V_3 , V_13 -> V_25 ) ;
F_18 ( V_19 , V_26 , V_27 , V_22 ) ;
F_19 ( V_19 ,
V_13 -> V_28 [ V_22 ] ,
V_20 [ V_3 ] & ( 1 << V_10 ) ) ;
}
}
F_20 ( V_19 ) ;
memcpy ( V_13 -> V_24 , V_20 , sizeof( V_20 ) ) ;
F_7 ( V_2 , true ) ;
F_21 ( & V_13 -> V_29 ) ;
V_13 -> V_30 = false ;
F_10 ( V_13 ) ;
F_22 ( & V_13 -> V_29 ) ;
}
static T_2 F_23 ( int V_31 , void * V_32 )
{
struct V_12 * V_13 = V_32 ;
unsigned long V_33 ;
F_24 ( & V_13 -> V_29 , V_33 ) ;
if ( F_25 ( V_13 -> V_30 || V_13 -> V_34 ) )
goto V_35;
F_13 ( V_13 ) ;
V_13 -> V_30 = true ;
F_26 ( & V_13 -> V_18 ,
F_27 ( V_13 -> V_2 -> V_36 ) ) ;
V_35:
F_28 ( & V_13 -> V_29 , V_33 ) ;
return V_37 ;
}
static int F_29 ( struct V_19 * V_38 )
{
struct V_12 * V_13 = F_30 ( V_38 ) ;
V_13 -> V_34 = false ;
F_31 () ;
F_26 ( & V_13 -> V_18 , 0 ) ;
return 0 ;
}
static void F_32 ( struct V_19 * V_38 )
{
struct V_12 * V_13 = F_30 ( V_38 ) ;
V_13 -> V_34 = true ;
F_31 () ;
F_33 ( & V_13 -> V_18 . V_18 ) ;
F_13 ( V_13 ) ;
}
static void F_34 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
unsigned int V_39 ;
int V_14 ;
if ( V_2 -> V_15 > 0 ) {
if ( F_35 ( V_2 -> V_15 ) == 0 )
V_13 -> V_40 = true ;
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
if ( ! F_36 ( V_14 , V_13 -> V_41 ) ) {
V_39 = V_2 -> V_11 [ V_14 ] ;
if ( F_35 ( F_12 ( V_39 ) ) == 0 )
F_37 ( V_14 , V_13 -> V_41 ) ;
}
}
}
}
static void F_38 ( struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
unsigned int V_39 ;
int V_14 ;
if ( V_2 -> V_15 > 0 ) {
if ( V_13 -> V_40 ) {
F_39 ( V_2 -> V_15 ) ;
V_13 -> V_40 = false ;
}
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
if ( F_40 ( V_14 , V_13 -> V_41 ) ) {
V_39 = V_2 -> V_11 [ V_14 ] ;
F_39 ( F_12 ( V_39 ) ) ;
}
}
}
}
static int F_41 ( struct V_42 * V_38 )
{
struct V_43 * V_44 = F_42 ( V_38 ) ;
struct V_12 * V_13 = F_43 ( V_44 ) ;
F_32 ( V_13 -> V_19 ) ;
if ( F_44 ( & V_44 -> V_38 ) )
F_34 ( V_13 ) ;
return 0 ;
}
static int F_45 ( struct V_42 * V_38 )
{
struct V_43 * V_44 = F_42 ( V_38 ) ;
struct V_12 * V_13 = F_43 ( V_44 ) ;
if ( F_44 ( & V_44 -> V_38 ) )
F_38 ( V_13 ) ;
F_29 ( V_13 -> V_19 ) ;
return 0 ;
}
static int T_3 F_46 ( struct V_43 * V_44 ,
struct V_12 * V_13 )
{
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_14 , V_45 = - V_46 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_9 ; V_14 ++ ) {
V_45 = F_47 ( V_2 -> V_7 [ V_14 ] , L_1 ) ;
if ( V_45 ) {
F_48 ( & V_44 -> V_38 ,
L_2 ,
V_2 -> V_7 [ V_14 ] , V_14 ) ;
goto V_47;
}
F_2 ( V_2 -> V_7 [ V_14 ] , ! V_2 -> V_6 ) ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_45 = F_47 ( V_2 -> V_11 [ V_14 ] , L_3 ) ;
if ( V_45 ) {
F_48 ( & V_44 -> V_38 ,
L_4 ,
V_2 -> V_11 [ V_14 ] , V_14 ) ;
goto V_48;
}
F_4 ( V_2 -> V_11 [ V_14 ] ) ;
}
if ( V_2 -> V_15 > 0 ) {
V_45 = F_49 ( V_2 -> V_15 ,
F_23 ,
V_2 -> V_49 ,
L_5 , V_13 ) ;
if ( V_45 ) {
F_48 ( & V_44 -> V_38 ,
L_6 ) ;
goto V_48;
}
} else {
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
V_45 = F_49 ( F_12 ( V_2 -> V_11 [ V_14 ] ) ,
F_23 ,
V_50 |
V_51 ,
L_5 , V_13 ) ;
if ( V_45 ) {
F_48 ( & V_44 -> V_38 ,
L_7
L_8 ,
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
return V_45 ;
}
static int T_3 F_52 ( struct V_43 * V_44 )
{
const struct V_1 * V_2 ;
const struct V_53 * V_54 ;
struct V_12 * V_13 ;
struct V_19 * V_19 ;
unsigned short * V_28 ;
unsigned int V_25 ;
int V_45 ;
V_2 = V_44 -> V_38 . V_55 ;
if ( ! V_2 ) {
F_48 ( & V_44 -> V_38 , L_9 ) ;
return - V_46 ;
}
V_54 = V_2 -> V_54 ;
if ( ! V_54 ) {
F_48 ( & V_44 -> V_38 , L_10 ) ;
return - V_46 ;
}
V_25 = F_53 ( V_2 -> V_9 ) ;
V_13 = F_54 ( sizeof( struct V_12 ) , V_56 ) ;
V_28 = F_54 ( ( V_2 -> V_16 << V_25 ) *
sizeof( * V_28 ) ,
V_56 ) ;
V_19 = F_55 () ;
if ( ! V_13 || ! V_28 || ! V_19 ) {
V_45 = - V_57 ;
goto V_58;
}
V_13 -> V_19 = V_19 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_28 = V_28 ;
V_13 -> V_25 = V_25 ;
V_13 -> V_34 = true ;
F_56 ( & V_13 -> V_18 , F_15 ) ;
F_57 ( & V_13 -> V_29 ) ;
V_19 -> V_59 = V_44 -> V_59 ;
V_19 -> V_32 . V_60 = V_61 ;
V_19 -> V_38 . V_62 = & V_44 -> V_38 ;
V_19 -> V_63 [ 0 ] = F_58 ( V_64 ) ;
if ( ! V_2 -> V_65 )
V_19 -> V_63 [ 0 ] |= F_58 ( V_66 ) ;
V_19 -> V_67 = F_29 ;
V_19 -> V_68 = F_32 ;
V_19 -> V_69 = V_28 ;
V_19 -> V_70 = sizeof( * V_28 ) ;
V_19 -> V_71 = V_2 -> V_16 << V_25 ;
F_59 ( V_54 , V_25 ,
V_19 -> V_69 , V_19 -> V_72 ) ;
F_60 ( V_19 , V_26 , V_27 ) ;
F_61 ( V_19 , V_13 ) ;
V_45 = F_46 ( V_44 , V_13 ) ;
if ( V_45 )
goto V_58;
V_45 = F_62 ( V_13 -> V_19 ) ;
if ( V_45 )
goto V_58;
F_63 ( & V_44 -> V_38 , V_2 -> V_73 ) ;
F_64 ( V_44 , V_13 ) ;
return 0 ;
V_58:
F_65 ( V_19 ) ;
F_66 ( V_28 ) ;
F_66 ( V_13 ) ;
return V_45 ;
}
static int T_4 F_67 ( struct V_43 * V_44 )
{
struct V_12 * V_13 = F_43 ( V_44 ) ;
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_14 ;
F_63 ( & V_44 -> V_38 , 0 ) ;
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
F_68 ( V_13 -> V_19 ) ;
F_64 ( V_44 , NULL ) ;
F_66 ( V_13 -> V_28 ) ;
F_66 ( V_13 ) ;
return 0 ;
}
