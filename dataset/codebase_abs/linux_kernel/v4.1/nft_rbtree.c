static bool F_1 ( const struct V_1 * V_2 , const T_1 * V_3 ,
const struct V_4 * * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 , * V_10 = NULL ;
const struct V_11 * V_12 ;
T_2 V_13 = F_3 ( F_4 ( & V_2 -> V_14 ) ) ;
int V_15 ;
F_5 ( & V_16 ) ;
V_12 = V_7 -> V_17 . V_11 ;
while ( V_12 != NULL ) {
V_9 = F_6 ( V_12 , struct V_8 , V_18 ) ;
V_15 = memcmp ( F_7 ( & V_9 -> V_5 ) , V_3 , V_2 -> V_19 ) ;
if ( V_15 < 0 ) {
V_12 = V_12 -> V_20 ;
V_10 = V_9 ;
} else if ( V_15 > 0 )
V_12 = V_12 -> V_21 ;
else {
V_22:
if ( ! F_8 ( & V_9 -> V_5 , V_13 ) ) {
V_12 = V_12 -> V_20 ;
continue;
}
if ( F_9 ( & V_9 -> V_5 , V_23 ) &&
* F_10 ( & V_9 -> V_5 ) &
V_24 )
goto V_25;
F_11 ( & V_16 ) ;
* V_5 = & V_9 -> V_5 ;
return true ;
}
}
if ( V_2 -> V_26 & V_27 && V_10 != NULL ) {
V_9 = V_10 ;
goto V_22;
}
V_25:
F_11 ( & V_16 ) ;
return false ;
}
static int F_12 ( const struct V_1 * V_2 ,
struct V_8 * V_28 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_11 * V_12 , * * V_29 ;
T_2 V_13 = F_13 ( F_4 ( & V_2 -> V_14 ) ) ;
int V_15 ;
V_12 = NULL ;
V_29 = & V_7 -> V_17 . V_11 ;
while ( * V_29 != NULL ) {
V_12 = * V_29 ;
V_9 = F_6 ( V_12 , struct V_8 , V_18 ) ;
V_15 = memcmp ( F_7 ( & V_9 -> V_5 ) ,
F_7 ( & V_28 -> V_5 ) ,
V_2 -> V_19 ) ;
if ( V_15 < 0 )
V_29 = & V_12 -> V_20 ;
else if ( V_15 > 0 )
V_29 = & V_12 -> V_21 ;
else {
if ( F_8 ( & V_9 -> V_5 , V_13 ) )
return - V_30 ;
V_29 = & V_12 -> V_20 ;
}
}
F_14 ( & V_28 -> V_18 , V_12 , V_29 ) ;
F_15 ( & V_28 -> V_18 , & V_7 -> V_17 ) ;
return 0 ;
}
static int F_16 ( const struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
struct V_8 * V_9 = V_32 -> V_7 ;
int V_33 ;
F_5 ( & V_16 ) ;
V_33 = F_12 ( V_2 , V_9 ) ;
F_11 ( & V_16 ) ;
return V_33 ;
}
static void F_17 ( const struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_32 -> V_7 ;
F_5 ( & V_16 ) ;
F_18 ( & V_9 -> V_18 , & V_7 -> V_17 ) ;
F_11 ( & V_16 ) ;
}
static void F_19 ( const struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
struct V_8 * V_9 = V_32 -> V_7 ;
F_20 ( V_2 , & V_9 -> V_5 ) ;
}
static void * F_21 ( const struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_11 * V_12 = V_7 -> V_17 . V_11 ;
struct V_8 * V_9 ;
T_2 V_13 = F_3 ( F_4 ( & V_2 -> V_14 ) ) ;
int V_15 ;
while ( V_12 != NULL ) {
V_9 = F_6 ( V_12 , struct V_8 , V_18 ) ;
V_15 = memcmp ( F_7 ( & V_9 -> V_5 ) , & V_32 -> V_3 . V_34 ,
V_2 -> V_19 ) ;
if ( V_15 < 0 )
V_12 = V_12 -> V_20 ;
else if ( V_15 > 0 )
V_12 = V_12 -> V_21 ;
else {
if ( ! F_8 ( & V_9 -> V_5 , V_13 ) ) {
V_12 = V_12 -> V_20 ;
continue;
}
F_20 ( V_2 , & V_9 -> V_5 ) ;
return V_9 ;
}
}
return NULL ;
}
static void F_22 ( const struct V_35 * V_36 ,
const struct V_1 * V_2 ,
struct V_37 * V_38 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_31 V_32 ;
struct V_11 * V_18 ;
T_2 V_13 = F_3 ( F_4 ( & V_2 -> V_14 ) ) ;
F_5 ( & V_16 ) ;
for ( V_18 = F_23 ( & V_7 -> V_17 ) ; V_18 != NULL ; V_18 = F_24 ( V_18 ) ) {
V_9 = F_6 ( V_18 , struct V_8 , V_18 ) ;
if ( V_38 -> V_39 < V_38 -> V_40 )
goto V_41;
if ( ! F_8 ( & V_9 -> V_5 , V_13 ) )
goto V_41;
V_32 . V_7 = V_9 ;
V_38 -> V_33 = V_38 -> V_42 ( V_36 , V_2 , V_38 , & V_32 ) ;
if ( V_38 -> V_33 < 0 ) {
F_11 ( & V_16 ) ;
return;
}
V_41:
V_38 -> V_39 ++ ;
}
F_11 ( & V_16 ) ;
}
static unsigned int F_25 ( const struct V_43 * const V_44 [] )
{
return sizeof( struct V_6 ) ;
}
static int F_26 ( const struct V_1 * V_2 ,
const struct V_45 * V_46 ,
const struct V_43 * const V_44 [] )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_17 = V_47 ;
return 0 ;
}
static void F_27 ( const struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_11 * V_18 ;
while ( ( V_18 = V_7 -> V_17 . V_11 ) != NULL ) {
F_18 ( V_18 , & V_7 -> V_17 ) ;
V_9 = F_6 ( V_18 , struct V_8 , V_18 ) ;
F_28 ( V_2 , V_9 ) ;
}
}
static bool F_29 ( const struct V_45 * V_46 , T_1 V_48 ,
struct V_49 * V_50 )
{
unsigned int V_51 ;
V_51 = sizeof( struct V_8 ) ;
if ( V_46 -> V_52 )
V_50 -> V_52 = sizeof( struct V_6 ) + V_46 -> V_52 * V_51 ;
else
V_50 -> V_52 = V_51 ;
V_50 -> V_53 = V_54 ;
return true ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_55 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_55 ) ;
}
