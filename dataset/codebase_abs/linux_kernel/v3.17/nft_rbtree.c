static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 , * V_10 = NULL ;
const struct V_11 * V_12 = V_7 -> V_13 . V_11 ;
int V_14 ;
F_3 ( & V_15 ) ;
while ( V_12 != NULL ) {
V_9 = F_4 ( V_12 , struct V_8 , V_16 ) ;
V_14 = F_5 ( & V_9 -> V_4 , V_4 , V_2 -> V_17 ) ;
if ( V_14 < 0 ) {
V_12 = V_12 -> V_18 ;
V_10 = V_9 ;
} else if ( V_14 > 0 )
V_12 = V_12 -> V_19 ;
else {
V_20:
if ( V_9 -> V_21 & V_22 )
goto V_23;
if ( V_2 -> V_21 & V_24 )
F_6 ( V_5 , V_9 -> V_5 ) ;
F_7 ( & V_15 ) ;
return true ;
}
}
if ( V_2 -> V_21 & V_25 && V_10 != NULL ) {
V_9 = V_10 ;
goto V_20;
}
V_23:
F_7 ( & V_15 ) ;
return false ;
}
static void F_8 ( const struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_9 ( & V_9 -> V_4 , V_26 ) ;
if ( V_2 -> V_21 & V_24 &&
! ( V_9 -> V_21 & V_22 ) )
F_9 ( V_9 -> V_5 , V_2 -> V_27 ) ;
F_10 ( V_9 ) ;
}
static int F_11 ( const struct V_1 * V_2 ,
struct V_8 * V_28 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_11 * V_12 , * * V_29 ;
int V_14 ;
V_12 = NULL ;
V_29 = & V_7 -> V_13 . V_11 ;
while ( * V_29 != NULL ) {
V_12 = * V_29 ;
V_9 = F_4 ( V_12 , struct V_8 , V_16 ) ;
V_14 = F_5 ( & V_9 -> V_4 , & V_28 -> V_4 , V_2 -> V_17 ) ;
if ( V_14 < 0 )
V_29 = & V_12 -> V_18 ;
else if ( V_14 > 0 )
V_29 = & V_12 -> V_19 ;
else
return - V_30 ;
}
F_12 ( & V_28 -> V_16 , V_12 , V_29 ) ;
F_13 ( & V_28 -> V_16 , & V_7 -> V_13 ) ;
return 0 ;
}
static int F_14 ( const struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
struct V_8 * V_9 ;
unsigned int V_33 ;
int V_34 ;
V_33 = sizeof( * V_9 ) ;
if ( V_2 -> V_21 & V_24 &&
! ( V_32 -> V_21 & V_22 ) )
V_33 += sizeof( V_9 -> V_5 [ 0 ] ) ;
V_9 = F_15 ( V_33 , V_35 ) ;
if ( V_9 == NULL )
return - V_36 ;
V_9 -> V_21 = V_32 -> V_21 ;
F_6 ( & V_9 -> V_4 , & V_32 -> V_4 ) ;
if ( V_2 -> V_21 & V_24 &&
! ( V_9 -> V_21 & V_22 ) )
F_6 ( V_9 -> V_5 , & V_32 -> V_5 ) ;
F_3 ( & V_15 ) ;
V_34 = F_11 ( V_2 , V_9 ) ;
if ( V_34 < 0 )
F_10 ( V_9 ) ;
F_7 ( & V_15 ) ;
return V_34 ;
}
static void F_16 ( const struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_32 -> V_37 ;
F_3 ( & V_15 ) ;
F_17 ( & V_9 -> V_16 , & V_7 -> V_13 ) ;
F_7 ( & V_15 ) ;
F_10 ( V_9 ) ;
}
static int F_18 ( const struct V_1 * V_2 , struct V_31 * V_32 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_11 * V_12 = V_7 -> V_13 . V_11 ;
struct V_8 * V_9 ;
int V_14 ;
F_3 ( & V_15 ) ;
while ( V_12 != NULL ) {
V_9 = F_4 ( V_12 , struct V_8 , V_16 ) ;
V_14 = F_5 ( & V_9 -> V_4 , & V_32 -> V_4 , V_2 -> V_17 ) ;
if ( V_14 < 0 )
V_12 = V_12 -> V_18 ;
else if ( V_14 > 0 )
V_12 = V_12 -> V_19 ;
else {
V_32 -> V_37 = V_9 ;
if ( V_2 -> V_21 & V_24 &&
! ( V_9 -> V_21 & V_22 ) )
F_6 ( & V_32 -> V_5 , V_9 -> V_5 ) ;
V_32 -> V_21 = V_9 -> V_21 ;
F_7 ( & V_15 ) ;
return 0 ;
}
}
F_7 ( & V_15 ) ;
return - V_38 ;
}
static void F_19 ( const struct V_39 * V_40 ,
const struct V_1 * V_2 ,
struct V_41 * V_42 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 ;
struct V_31 V_32 ;
struct V_11 * V_16 ;
F_3 ( & V_15 ) ;
for ( V_16 = F_20 ( & V_7 -> V_13 ) ; V_16 != NULL ; V_16 = F_21 ( V_16 ) ) {
if ( V_42 -> V_43 < V_42 -> V_44 )
goto V_45;
V_9 = F_4 ( V_16 , struct V_8 , V_16 ) ;
F_6 ( & V_32 . V_4 , & V_9 -> V_4 ) ;
if ( V_2 -> V_21 & V_24 &&
! ( V_9 -> V_21 & V_22 ) )
F_6 ( & V_32 . V_5 , V_9 -> V_5 ) ;
V_32 . V_21 = V_9 -> V_21 ;
V_42 -> V_34 = V_42 -> V_46 ( V_40 , V_2 , V_42 , & V_32 ) ;
if ( V_42 -> V_34 < 0 ) {
F_7 ( & V_15 ) ;
return;
}
V_45:
V_42 -> V_43 ++ ;
}
F_7 ( & V_15 ) ;
}
static unsigned int F_22 ( const struct V_47 * const V_48 [] )
{
return sizeof( struct V_6 ) ;
}
static int F_23 ( const struct V_1 * V_2 ,
const struct V_49 * V_50 ,
const struct V_47 * const V_48 [] )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_13 = V_51 ;
return 0 ;
}
static void F_24 ( const struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_11 * V_16 ;
while ( ( V_16 = V_7 -> V_13 . V_11 ) != NULL ) {
F_17 ( V_16 , & V_7 -> V_13 ) ;
V_9 = F_4 ( V_16 , struct V_8 , V_16 ) ;
F_8 ( V_2 , V_9 ) ;
}
}
static bool F_25 ( const struct V_49 * V_50 , T_1 V_52 ,
struct V_53 * V_54 )
{
unsigned int V_55 ;
V_55 = sizeof( struct V_8 ) ;
if ( V_52 & V_24 )
V_55 += F_26 ( struct V_8 , V_5 [ 0 ] ) ;
if ( V_50 -> V_33 )
V_54 -> V_33 = sizeof( struct V_6 ) + V_50 -> V_33 * V_55 ;
else
V_54 -> V_33 = V_55 ;
V_54 -> V_56 = V_57 ;
return true ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_58 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_58 ) ;
}
