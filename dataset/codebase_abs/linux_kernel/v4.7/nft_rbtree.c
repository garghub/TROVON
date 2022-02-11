static bool F_1 ( const struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 , V_4 ) &&
( * F_3 ( & V_2 -> V_3 ) & V_5 ) ;
}
static bool F_4 ( const struct V_6 * V_7 , const void * V_8 ,
const struct V_1 * V_9 )
{
return memcmp ( V_8 , F_5 ( & V_9 -> V_3 ) , V_7 -> V_10 ) == 0 ;
}
static bool F_6 ( const struct V_6 * V_7 , const T_1 * V_11 ,
const struct V_12 * * V_3 )
{
const struct V_13 * V_14 = F_7 ( V_7 ) ;
const struct V_1 * V_2 , * V_9 = NULL ;
const struct V_15 * V_16 ;
T_2 V_17 = F_8 ( F_9 ( & V_7 -> V_18 ) ) ;
const void * V_8 ;
int V_19 ;
F_10 ( & V_20 ) ;
V_16 = V_14 -> V_21 . V_15 ;
while ( V_16 != NULL ) {
V_2 = F_11 ( V_16 , struct V_1 , V_22 ) ;
V_8 = F_5 ( & V_2 -> V_3 ) ;
V_19 = memcmp ( V_8 , V_11 , V_7 -> V_10 ) ;
if ( V_19 < 0 ) {
V_16 = V_16 -> V_23 ;
if ( V_9 && F_4 ( V_7 , V_8 , V_9 ) )
continue;
V_9 = V_2 ;
} else if ( V_19 > 0 )
V_16 = V_16 -> V_24 ;
else {
V_25:
if ( ! F_12 ( & V_2 -> V_3 , V_17 ) ) {
V_16 = V_16 -> V_23 ;
continue;
}
if ( F_1 ( V_2 ) )
goto V_26;
F_13 ( & V_20 ) ;
* V_3 = & V_2 -> V_3 ;
return true ;
}
}
if ( V_7 -> V_27 & V_28 && V_9 != NULL ) {
V_2 = V_9 ;
goto V_25;
}
V_26:
F_13 ( & V_20 ) ;
return false ;
}
static int F_14 ( const struct V_6 * V_7 ,
struct V_1 * V_29 )
{
struct V_13 * V_14 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_15 * V_16 , * * V_30 ;
T_2 V_17 = F_15 ( F_9 ( & V_7 -> V_18 ) ) ;
int V_19 ;
V_16 = NULL ;
V_30 = & V_14 -> V_21 . V_15 ;
while ( * V_30 != NULL ) {
V_16 = * V_30 ;
V_2 = F_11 ( V_16 , struct V_1 , V_22 ) ;
V_19 = memcmp ( F_5 ( & V_2 -> V_3 ) ,
F_5 ( & V_29 -> V_3 ) ,
V_7 -> V_10 ) ;
if ( V_19 < 0 )
V_30 = & V_16 -> V_23 ;
else if ( V_19 > 0 )
V_30 = & V_16 -> V_24 ;
else {
if ( F_12 ( & V_2 -> V_3 , V_17 ) ) {
if ( F_1 ( V_2 ) &&
! F_1 ( V_29 ) )
V_30 = & V_16 -> V_23 ;
else if ( ! F_1 ( V_2 ) &&
F_1 ( V_29 ) )
V_30 = & V_16 -> V_24 ;
else
return - V_31 ;
}
}
}
F_16 ( & V_29 -> V_22 , V_16 , V_30 ) ;
F_17 ( & V_29 -> V_22 , & V_14 -> V_21 ) ;
return 0 ;
}
static int F_18 ( const struct V_6 * V_7 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_14 ;
int V_34 ;
F_10 ( & V_20 ) ;
V_34 = F_14 ( V_7 , V_2 ) ;
F_13 ( & V_20 ) ;
return V_34 ;
}
static void F_19 ( const struct V_6 * V_7 ,
const struct V_32 * V_33 )
{
struct V_13 * V_14 = F_7 ( V_7 ) ;
struct V_1 * V_2 = V_33 -> V_14 ;
F_10 ( & V_20 ) ;
F_20 ( & V_2 -> V_22 , & V_14 -> V_21 ) ;
F_13 ( & V_20 ) ;
}
static void F_21 ( const struct V_6 * V_7 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_14 ;
F_22 ( V_7 , & V_2 -> V_3 ) ;
}
static void * F_23 ( const struct V_6 * V_7 ,
const struct V_32 * V_33 )
{
const struct V_13 * V_14 = F_7 ( V_7 ) ;
const struct V_15 * V_16 = V_14 -> V_21 . V_15 ;
struct V_1 * V_2 , * V_8 = V_33 -> V_14 ;
T_2 V_17 = F_8 ( F_9 ( & V_7 -> V_18 ) ) ;
int V_19 ;
while ( V_16 != NULL ) {
V_2 = F_11 ( V_16 , struct V_1 , V_22 ) ;
V_19 = memcmp ( F_5 ( & V_2 -> V_3 ) , & V_33 -> V_11 . V_35 ,
V_7 -> V_10 ) ;
if ( V_19 < 0 )
V_16 = V_16 -> V_23 ;
else if ( V_19 > 0 )
V_16 = V_16 -> V_24 ;
else {
if ( ! F_12 ( & V_2 -> V_3 , V_17 ) ) {
V_16 = V_16 -> V_23 ;
continue;
}
if ( F_1 ( V_2 ) &&
! F_1 ( V_8 ) ) {
V_16 = V_16 -> V_23 ;
continue;
} else if ( ! F_1 ( V_2 ) &&
F_1 ( V_8 ) ) {
V_16 = V_16 -> V_24 ;
continue;
}
F_22 ( V_7 , & V_2 -> V_3 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_24 ( const struct V_36 * V_37 ,
const struct V_6 * V_7 ,
struct V_38 * V_39 )
{
const struct V_13 * V_14 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_32 V_33 ;
struct V_15 * V_22 ;
F_10 ( & V_20 ) ;
for ( V_22 = F_25 ( & V_14 -> V_21 ) ; V_22 != NULL ; V_22 = F_26 ( V_22 ) ) {
V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
if ( V_39 -> V_40 < V_39 -> V_41 )
goto V_42;
if ( ! F_12 ( & V_2 -> V_3 , V_39 -> V_17 ) )
goto V_42;
V_33 . V_14 = V_2 ;
V_39 -> V_34 = V_39 -> V_43 ( V_37 , V_7 , V_39 , & V_33 ) ;
if ( V_39 -> V_34 < 0 ) {
F_13 ( & V_20 ) ;
return;
}
V_42:
V_39 -> V_40 ++ ;
}
F_13 ( & V_20 ) ;
}
static unsigned int F_27 ( const struct V_44 * const V_45 [] )
{
return sizeof( struct V_13 ) ;
}
static int F_28 ( const struct V_6 * V_7 ,
const struct V_46 * V_47 ,
const struct V_44 * const V_45 [] )
{
struct V_13 * V_14 = F_7 ( V_7 ) ;
V_14 -> V_21 = V_48 ;
return 0 ;
}
static void F_29 ( const struct V_6 * V_7 )
{
struct V_13 * V_14 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_15 * V_22 ;
while ( ( V_22 = V_14 -> V_21 . V_15 ) != NULL ) {
F_20 ( V_22 , & V_14 -> V_21 ) ;
V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
F_30 ( V_7 , V_2 ) ;
}
}
static bool F_31 ( const struct V_46 * V_47 , T_1 V_49 ,
struct V_50 * V_51 )
{
unsigned int V_52 ;
V_52 = sizeof( struct V_1 ) ;
if ( V_47 -> V_53 )
V_51 -> V_53 = sizeof( struct V_13 ) + V_47 -> V_53 * V_52 ;
else
V_51 -> V_53 = V_52 ;
V_51 -> V_54 = V_55 ;
return true ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_56 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_56 ) ;
}
