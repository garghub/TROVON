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
const T_1 * V_12 , const struct V_13 * * V_3 ,
unsigned int V_14 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
const struct V_1 * V_2 , * V_9 = NULL ;
T_2 V_17 = F_8 ( V_11 ) ;
const struct V_18 * V_19 ;
const void * V_8 ;
int V_20 ;
V_19 = F_9 ( V_16 -> V_21 . V_18 ) ;
while ( V_19 != NULL ) {
if ( F_10 ( & V_16 -> V_22 , V_14 ) )
return false ;
V_2 = F_11 ( V_19 , struct V_1 , V_23 ) ;
V_8 = F_5 ( & V_2 -> V_3 ) ;
V_20 = memcmp ( V_8 , V_12 , V_7 -> V_10 ) ;
if ( V_20 < 0 ) {
V_19 = F_9 ( V_19 -> V_24 ) ;
if ( V_9 &&
F_4 ( V_7 , V_8 , V_9 ) &&
F_1 ( V_8 ) &&
! F_1 ( V_9 ) )
continue;
V_9 = V_2 ;
} else if ( V_20 > 0 )
V_19 = F_9 ( V_19 -> V_25 ) ;
else {
if ( ! F_12 ( & V_2 -> V_3 , V_17 ) ) {
V_19 = F_9 ( V_19 -> V_24 ) ;
continue;
}
if ( F_1 ( V_2 ) )
goto V_26;
* V_3 = & V_2 -> V_3 ;
return true ;
}
}
if ( V_7 -> V_27 & V_28 && V_9 != NULL &&
F_12 ( & V_9 -> V_3 , V_17 ) &&
! F_1 ( V_9 ) ) {
* V_3 = & V_9 -> V_3 ;
return true ;
}
V_26:
return false ;
}
static bool F_13 ( const struct V_11 * V_11 , const struct V_6 * V_7 ,
const T_1 * V_12 , const struct V_13 * * V_3 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
unsigned int V_14 = F_14 ( & V_16 -> V_22 ) ;
bool V_29 ;
V_29 = F_6 ( V_11 , V_7 , V_12 , V_3 , V_14 ) ;
if ( V_29 || ! F_10 ( & V_16 -> V_22 , V_14 ) )
return V_29 ;
F_15 ( & V_16 -> V_30 ) ;
V_14 = F_14 ( & V_16 -> V_22 ) ;
V_29 = F_6 ( V_11 , V_7 , V_12 , V_3 , V_14 ) ;
F_16 ( & V_16 -> V_30 ) ;
return V_29 ;
}
static int F_17 ( const struct V_11 * V_11 , const struct V_6 * V_7 ,
struct V_1 * V_31 ,
struct V_13 * * V_3 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
T_2 V_17 = F_18 ( V_11 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 , * * V_32 ;
int V_20 ;
V_19 = NULL ;
V_32 = & V_16 -> V_21 . V_18 ;
while ( * V_32 != NULL ) {
V_19 = * V_32 ;
V_2 = F_11 ( V_19 , struct V_1 , V_23 ) ;
V_20 = memcmp ( F_5 ( & V_2 -> V_3 ) ,
F_5 ( & V_31 -> V_3 ) ,
V_7 -> V_10 ) ;
if ( V_20 < 0 )
V_32 = & V_19 -> V_24 ;
else if ( V_20 > 0 )
V_32 = & V_19 -> V_25 ;
else {
if ( F_1 ( V_2 ) &&
! F_1 ( V_31 ) ) {
V_32 = & V_19 -> V_24 ;
} else if ( ! F_1 ( V_2 ) &&
F_1 ( V_31 ) ) {
V_32 = & V_19 -> V_25 ;
} else if ( F_12 ( & V_2 -> V_3 , V_17 ) ) {
* V_3 = & V_2 -> V_3 ;
return - V_33 ;
} else {
V_32 = & V_19 -> V_24 ;
}
}
}
F_19 ( & V_31 -> V_23 , V_19 , V_32 ) ;
F_20 ( & V_31 -> V_23 , & V_16 -> V_21 ) ;
return 0 ;
}
static int F_21 ( const struct V_11 * V_11 , const struct V_6 * V_7 ,
const struct V_34 * V_35 ,
struct V_13 * * V_3 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
struct V_1 * V_2 = V_35 -> V_16 ;
int V_36 ;
F_22 ( & V_16 -> V_30 ) ;
F_23 ( & V_16 -> V_22 ) ;
V_36 = F_17 ( V_11 , V_7 , V_2 , V_3 ) ;
F_24 ( & V_16 -> V_22 ) ;
F_25 ( & V_16 -> V_30 ) ;
return V_36 ;
}
static void F_26 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 ,
const struct V_34 * V_35 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
struct V_1 * V_2 = V_35 -> V_16 ;
F_22 ( & V_16 -> V_30 ) ;
F_23 ( & V_16 -> V_22 ) ;
F_27 ( & V_2 -> V_23 , & V_16 -> V_21 ) ;
F_24 ( & V_16 -> V_22 ) ;
F_25 ( & V_16 -> V_30 ) ;
}
static void F_28 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_16 ;
F_29 ( V_11 , V_7 , & V_2 -> V_3 ) ;
}
static bool F_30 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 , void * V_16 )
{
struct V_1 * V_2 = V_16 ;
F_29 ( V_11 , V_7 , & V_2 -> V_3 ) ;
return true ;
}
static void * F_31 ( const struct V_11 * V_11 ,
const struct V_6 * V_7 ,
const struct V_34 * V_35 )
{
const struct V_15 * V_16 = F_7 ( V_7 ) ;
const struct V_18 * V_19 = V_16 -> V_21 . V_18 ;
struct V_1 * V_2 , * V_8 = V_35 -> V_16 ;
T_2 V_17 = F_18 ( V_11 ) ;
int V_20 ;
while ( V_19 != NULL ) {
V_2 = F_11 ( V_19 , struct V_1 , V_23 ) ;
V_20 = memcmp ( F_5 ( & V_2 -> V_3 ) , & V_35 -> V_12 . V_37 ,
V_7 -> V_10 ) ;
if ( V_20 < 0 )
V_19 = V_19 -> V_24 ;
else if ( V_20 > 0 )
V_19 = V_19 -> V_25 ;
else {
if ( ! F_12 ( & V_2 -> V_3 , V_17 ) ) {
V_19 = V_19 -> V_24 ;
continue;
}
if ( F_1 ( V_2 ) &&
! F_1 ( V_8 ) ) {
V_19 = V_19 -> V_24 ;
continue;
} else if ( ! F_1 ( V_2 ) &&
F_1 ( V_8 ) ) {
V_19 = V_19 -> V_25 ;
continue;
}
F_30 ( V_11 , V_7 , V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_32 ( const struct V_38 * V_39 ,
struct V_6 * V_7 ,
struct V_40 * V_41 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_34 V_35 ;
struct V_18 * V_23 ;
F_15 ( & V_16 -> V_30 ) ;
for ( V_23 = F_33 ( & V_16 -> V_21 ) ; V_23 != NULL ; V_23 = F_34 ( V_23 ) ) {
V_2 = F_11 ( V_23 , struct V_1 , V_23 ) ;
if ( V_41 -> V_22 < V_41 -> V_42 )
goto V_43;
if ( ! F_12 ( & V_2 -> V_3 , V_41 -> V_17 ) )
goto V_43;
V_35 . V_16 = V_2 ;
V_41 -> V_36 = V_41 -> V_44 ( V_39 , V_7 , V_41 , & V_35 ) ;
if ( V_41 -> V_36 < 0 ) {
F_16 ( & V_16 -> V_30 ) ;
return;
}
V_43:
V_41 -> V_22 ++ ;
}
F_16 ( & V_16 -> V_30 ) ;
}
static unsigned int F_35 ( const struct V_45 * const V_46 [] ,
const struct V_47 * V_48 )
{
return sizeof( struct V_15 ) ;
}
static int F_36 ( const struct V_6 * V_7 ,
const struct V_47 * V_48 ,
const struct V_45 * const V_46 [] )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
F_37 ( & V_16 -> V_30 ) ;
F_38 ( & V_16 -> V_22 ) ;
V_16 -> V_21 = V_49 ;
return 0 ;
}
static void F_39 ( const struct V_6 * V_7 )
{
struct V_15 * V_16 = F_7 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_18 * V_23 ;
while ( ( V_23 = V_16 -> V_21 . V_18 ) != NULL ) {
F_27 ( V_23 , & V_16 -> V_21 ) ;
V_2 = F_11 ( V_23 , struct V_1 , V_23 ) ;
F_40 ( V_7 , V_2 , true ) ;
}
}
static bool F_41 ( const struct V_47 * V_48 , T_1 V_50 ,
struct V_51 * V_52 )
{
if ( V_48 -> V_53 )
V_52 -> V_53 = sizeof( struct V_15 ) +
V_48 -> V_53 * sizeof( struct V_1 ) ;
else
V_52 -> V_53 = ~ 0 ;
V_52 -> V_54 = V_55 ;
V_52 -> V_56 = V_57 ;
return true ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_58 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_58 ) ;
}
