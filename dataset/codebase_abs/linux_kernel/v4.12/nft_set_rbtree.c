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
static bool F_6 ( const struct V_11 * V_11 , const struct V_6 * V_7 ,
const T_1 * V_12 , const struct V_13 * * V_3 )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
const struct V_1 * V_2 , * V_9 = NULL ;
T_2 V_16 = F_8 ( V_11 ) ;
const struct V_17 * V_18 ;
const void * V_8 ;
int V_19 ;
F_9 ( & V_15 -> V_20 ) ;
V_18 = V_15 -> V_21 . V_17 ;
while ( V_18 != NULL ) {
V_2 = F_10 ( V_18 , struct V_1 , V_22 ) ;
V_8 = F_5 ( & V_2 -> V_3 ) ;
V_19 = memcmp ( V_8 , V_12 , V_7 -> V_10 ) ;
if ( V_19 < 0 ) {
V_18 = V_18 -> V_23 ;
if ( V_9 &&
F_4 ( V_7 , V_8 , V_9 ) &&
F_1 ( V_8 ) &&
! F_1 ( V_9 ) )
continue;
V_9 = V_2 ;
} else if ( V_19 > 0 )
V_18 = V_18 -> V_24 ;
else {
if ( ! F_11 ( & V_2 -> V_3 , V_16 ) ) {
V_18 = V_18 -> V_23 ;
continue;
}
if ( F_1 ( V_2 ) )
goto V_25;
F_12 ( & V_15 -> V_20 ) ;
* V_3 = & V_2 -> V_3 ;
return true ;
}
}
if ( V_7 -> V_26 & V_27 && V_9 != NULL &&
F_11 ( & V_9 -> V_3 , V_16 ) &&
! F_1 ( V_9 ) ) {
F_12 ( & V_15 -> V_20 ) ;
* V_3 = & V_9 -> V_3 ;
return true ;
}
V_25:
F_12 ( & V_15 -> V_20 ) ;
return false ;
}
static int F_13 ( const struct V_11 * V_11 , const struct V_6 * V_7 ,
struct V_1 * V_28 ,
struct V_13 * * V_3 )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
T_2 V_16 = F_14 ( V_11 ) ;
struct V_1 * V_2 ;
struct V_17 * V_18 , * * V_29 ;
int V_19 ;
V_18 = NULL ;
V_29 = & V_15 -> V_21 . V_17 ;
while ( * V_29 != NULL ) {
V_18 = * V_29 ;
V_2 = F_10 ( V_18 , struct V_1 , V_22 ) ;
V_19 = memcmp ( F_5 ( & V_2 -> V_3 ) ,
F_5 ( & V_28 -> V_3 ) ,
V_7 -> V_10 ) ;
if ( V_19 < 0 )
V_29 = & V_18 -> V_23 ;
else if ( V_19 > 0 )
V_29 = & V_18 -> V_24 ;
else {
if ( F_1 ( V_2 ) &&
! F_1 ( V_28 ) ) {
V_29 = & V_18 -> V_23 ;
} else if ( ! F_1 ( V_2 ) &&
F_1 ( V_28 ) ) {
V_29 = & V_18 -> V_24 ;
} else if ( F_11 ( & V_2 -> V_3 , V_16 ) ) {
* V_3 = & V_2 -> V_3 ;
return - V_30 ;
} else {
V_29 = & V_18 -> V_23 ;
}
}
}
F_15 ( & V_28 -> V_22 , V_18 , V_29 ) ;
F_16 ( & V_28 -> V_22 , & V_15 -> V_21 ) ;
return 0 ;
}
static int F_17 ( const struct V_11 * V_11 , const struct V_6 * V_7 ,
const struct V_31 * V_32 ,
struct V_13 * * V_3 )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
struct V_1 * V_2 = V_32 -> V_15 ;
int V_33 ;
F_18 ( & V_15 -> V_20 ) ;
V_33 = F_13 ( V_11 , V_7 , V_2 , V_3 ) ;
F_19 ( & V_15 -> V_20 ) ;
return V_33 ;
}
static void F_20 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 ,
const struct V_31 * V_32 )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
struct V_1 * V_2 = V_32 -> V_15 ;
F_18 ( & V_15 -> V_20 ) ;
F_21 ( & V_2 -> V_22 , & V_15 -> V_21 ) ;
F_19 ( & V_15 -> V_20 ) ;
}
static void F_22 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 ,
const struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_15 ;
F_23 ( V_11 , V_7 , & V_2 -> V_3 ) ;
}
static bool F_24 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
F_23 ( V_11 , V_7 , & V_2 -> V_3 ) ;
return true ;
}
static void * F_25 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 ,
const struct V_31 * V_32 )
{
const struct V_14 * V_15 = F_7 ( V_7 ) ;
const struct V_17 * V_18 = V_15 -> V_21 . V_17 ;
struct V_1 * V_2 , * V_8 = V_32 -> V_15 ;
T_2 V_16 = F_14 ( V_11 ) ;
int V_19 ;
while ( V_18 != NULL ) {
V_2 = F_10 ( V_18 , struct V_1 , V_22 ) ;
V_19 = memcmp ( F_5 ( & V_2 -> V_3 ) , & V_32 -> V_12 . V_34 ,
V_7 -> V_10 ) ;
if ( V_19 < 0 )
V_18 = V_18 -> V_23 ;
else if ( V_19 > 0 )
V_18 = V_18 -> V_24 ;
else {
if ( ! F_11 ( & V_2 -> V_3 , V_16 ) ) {
V_18 = V_18 -> V_23 ;
continue;
}
if ( F_1 ( V_2 ) &&
! F_1 ( V_8 ) ) {
V_18 = V_18 -> V_23 ;
continue;
} else if ( ! F_1 ( V_2 ) &&
F_1 ( V_8 ) ) {
V_18 = V_18 -> V_24 ;
continue;
}
F_24 ( V_11 , V_7 , V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_26 ( const struct V_35 * V_36 ,
struct V_6 * V_7 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_31 V_32 ;
struct V_17 * V_22 ;
F_9 ( & V_15 -> V_20 ) ;
for ( V_22 = F_27 ( & V_15 -> V_21 ) ; V_22 != NULL ; V_22 = F_28 ( V_22 ) ) {
V_2 = F_10 ( V_22 , struct V_1 , V_22 ) ;
if ( V_38 -> V_39 < V_38 -> V_40 )
goto V_41;
if ( ! F_11 ( & V_2 -> V_3 , V_38 -> V_16 ) )
goto V_41;
V_32 . V_15 = V_2 ;
V_38 -> V_33 = V_38 -> V_42 ( V_36 , V_7 , V_38 , & V_32 ) ;
if ( V_38 -> V_33 < 0 ) {
F_12 ( & V_15 -> V_20 ) ;
return;
}
V_41:
V_38 -> V_39 ++ ;
}
F_12 ( & V_15 -> V_20 ) ;
}
static unsigned int F_29 ( const struct V_43 * const V_44 [] )
{
return sizeof( struct V_14 ) ;
}
static int F_30 ( const struct V_6 * V_7 ,
const struct V_45 * V_46 ,
const struct V_43 * const V_44 [] )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
F_31 ( & V_15 -> V_20 ) ;
V_15 -> V_21 = V_47 ;
return 0 ;
}
static void F_32 ( const struct V_6 * V_7 )
{
struct V_14 * V_15 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_17 * V_22 ;
while ( ( V_22 = V_15 -> V_21 . V_17 ) != NULL ) {
F_21 ( V_22 , & V_15 -> V_21 ) ;
V_2 = F_10 ( V_22 , struct V_1 , V_22 ) ;
F_33 ( V_7 , V_2 , true ) ;
}
}
static bool F_34 ( const struct V_45 * V_46 , T_1 V_48 ,
struct V_49 * V_50 )
{
unsigned int V_51 ;
V_51 = sizeof( struct V_1 ) ;
if ( V_46 -> V_52 )
V_50 -> V_52 = sizeof( struct V_14 ) + V_46 -> V_52 * V_51 ;
else
V_50 -> V_52 = V_51 ;
V_50 -> V_53 = V_54 ;
V_50 -> V_55 = V_56 ;
return true ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_57 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_57 ) ;
}
