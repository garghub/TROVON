static bool F_1 ( struct V_1 * V_1 )
{
int V_2 ;
int V_3 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_4 ; V_2 ++ ) {
const struct V_5 * V_6 = & V_1 -> V_7 [ V_2 ] ;
for ( V_3 = 0 ; V_3 < V_6 -> V_8 ; V_3 ++ ) {
struct V_9 * V_10 ;
V_10 = & V_6 -> V_11 [ V_3 ] ;
if ( V_10 -> type != V_10 -> V_12 -> type ||
V_10 -> V_13 . V_14 . V_15 !=
V_10 -> V_12 -> V_13 . V_14 . V_15 )
return false ;
}
}
return true ;
}
struct V_1 * F_2 ( unsigned int V_16 ,
const struct V_5 * V_7 ,
unsigned int V_4 )
{
struct V_1 * V_1 ;
V_1 = F_3 ( sizeof( * V_1 ) , V_17 ) ;
if ( ! V_1 )
return NULL ;
F_4 ( & V_1 -> V_18 ) ;
V_1 -> V_16 = V_16 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_4 = V_4 ;
F_5 ( ! F_1 ( V_1 ) ) ;
return V_1 ;
}
void F_6 ( struct V_1 * V_1 )
{
F_5 ( ! F_7 ( & V_1 -> V_18 ) ) ;
F_8 ( V_1 ) ;
}
static bool
F_9 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
return memcmp ( & V_20 -> V_22 , V_22 , sizeof( * V_22 ) ) == 0 ;
}
static struct V_19 *
F_10 ( struct V_1 * V_1 ,
struct V_21 * V_22 )
{
struct V_19 * V_20 ;
F_11 (key_info, &mlxsw_afk->key_info_list, list) {
if ( F_9 ( V_20 , V_22 ) )
return V_20 ;
}
return NULL ;
}
static void F_12 ( struct V_1 * V_1 ,
struct V_23 * V_24 ,
enum V_25 V_26 )
{
int V_2 ;
int V_3 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_4 ; V_2 ++ ) {
const struct V_5 * V_6 = & V_1 -> V_7 [ V_2 ] ;
for ( V_3 = 0 ; V_3 < V_6 -> V_8 ; V_3 ++ ) {
struct V_9 * V_10 ;
V_10 = & V_6 -> V_11 [ V_3 ] ;
if ( V_10 -> V_12 -> V_26 == V_26 ) {
F_13 ( V_26 , V_24 -> V_27 [ V_2 ] . V_26 ) ;
V_24 -> V_27 [ V_2 ] . V_28 ++ ;
}
}
}
}
static void F_14 ( struct V_1 * V_1 ,
struct V_23 * V_24 ,
int V_29 )
{
F_15 ( V_30 , V_31 ) ;
int V_2 ;
int V_3 ;
memcpy ( & V_30 , & V_24 -> V_27 [ V_29 ] . V_26 ,
sizeof( V_30 ) ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_4 ; V_2 ++ ) {
F_16 (j, hits_element, MLXSW_AFK_ELEMENT_MAX) {
if ( F_17 ( V_3 , V_24 -> V_27 [ V_2 ] . V_26 ) )
V_24 -> V_27 [ V_2 ] . V_28 -- ;
}
}
}
static int F_18 ( struct V_1 * V_1 ,
struct V_23 * V_24 )
{
int V_32 = - V_33 ;
int V_34 = 0 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_4 ; V_2 ++ ) {
if ( V_24 -> V_27 [ V_2 ] . V_28 > V_34 ) {
V_34 = V_24 -> V_27 [ V_2 ] . V_28 ;
V_32 = V_2 ;
}
}
return V_32 ;
}
static int F_19 ( struct V_1 * V_1 ,
struct V_23 * V_24 ,
int V_29 ,
struct V_19 * V_20 )
{
enum V_25 V_26 ;
if ( V_20 -> V_4 == V_1 -> V_16 )
return - V_33 ;
F_16 (element, picker->hits[block_index].element,
MLXSW_AFK_ELEMENT_MAX) {
V_20 -> V_35 [ V_26 ] = V_20 -> V_4 ;
F_20 ( & V_20 -> V_22 , V_26 ) ;
}
V_20 -> V_7 [ V_20 -> V_4 ] =
& V_1 -> V_7 [ V_29 ] ;
V_20 -> V_4 ++ ;
return 0 ;
}
static int V_23 ( struct V_1 * V_1 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
enum V_25 V_26 ;
T_1 V_36 ;
int V_37 ;
V_36 = sizeof( V_24 -> V_27 [ 0 ] ) * V_1 -> V_4 ;
V_24 = F_3 ( V_36 , V_17 ) ;
if ( ! V_24 )
return - V_38 ;
F_21 (element, elusage)
F_12 ( V_1 , V_24 , V_26 ) ;
do {
int V_29 ;
V_29 = F_18 ( V_1 , V_24 ) ;
if ( V_29 < 0 ) {
V_37 = V_29 ;
goto V_39;
}
V_37 = F_19 ( V_1 , V_24 ,
V_29 , V_20 ) ;
if ( V_37 )
goto V_39;
F_14 ( V_1 , V_24 , V_29 ) ;
} while ( ! F_9 ( V_20 , V_22 ) );
V_37 = 0 ;
V_39:
F_8 ( V_24 ) ;
return V_37 ;
}
static struct V_19 *
F_22 ( struct V_1 * V_1 ,
struct V_21 * V_22 )
{
struct V_19 * V_20 ;
T_1 V_36 ;
int V_37 ;
V_36 = sizeof( * V_20 ) +
sizeof( V_20 -> V_7 [ 0 ] ) * V_1 -> V_16 ;
V_20 = F_3 ( V_36 , V_17 ) ;
if ( ! V_20 )
return F_23 ( - V_38 ) ;
V_37 = V_23 ( V_1 , V_20 , V_22 ) ;
if ( V_37 )
goto V_40;
F_24 ( & V_20 -> V_41 , & V_1 -> V_18 ) ;
V_20 -> V_42 = 1 ;
return V_20 ;
V_40:
F_8 ( V_20 ) ;
return F_23 ( V_37 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
F_26 ( & V_20 -> V_41 ) ;
F_8 ( V_20 ) ;
}
struct V_19 *
F_27 ( struct V_1 * V_1 ,
struct V_21 * V_22 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( V_1 , V_22 ) ;
if ( V_20 ) {
V_20 -> V_42 ++ ;
return V_20 ;
}
return F_22 ( V_1 , V_22 ) ;
}
void F_28 ( struct V_19 * V_20 )
{
if ( -- V_20 -> V_42 )
return;
F_25 ( V_20 ) ;
}
bool F_29 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
return F_30 ( V_22 , & V_20 -> V_22 ) ;
}
static const struct V_9 *
F_31 ( const struct V_5 * V_6 ,
enum V_25 V_26 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_6 -> V_8 ; V_2 ++ ) {
struct V_9 * V_10 ;
V_10 = & V_6 -> V_11 [ V_2 ] ;
if ( V_10 -> V_12 -> V_26 == V_26 )
return V_10 ;
}
return NULL ;
}
static const struct V_9 *
F_32 ( struct V_19 * V_20 ,
enum V_25 V_26 ,
int * V_43 )
{
const struct V_9 * V_10 ;
const struct V_5 * V_6 ;
int V_29 ;
if ( F_5 ( ! F_33 ( V_26 , V_20 -> V_22 . V_44 ) ) )
return NULL ;
V_29 = V_20 -> V_35 [ V_26 ] ;
V_6 = V_20 -> V_7 [ V_29 ] ;
V_10 = F_31 ( V_6 , V_26 ) ;
if ( F_5 ( ! V_10 ) )
return NULL ;
* V_43 = V_29 ;
return V_10 ;
}
T_2
F_34 ( const struct V_19 * V_20 ,
int V_29 )
{
return V_20 -> V_7 [ V_29 ] -> V_45 ;
}
unsigned int
F_35 ( const struct V_19 * V_20 )
{
return V_20 -> V_4 ;
}
void F_36 ( struct V_46 * V_47 ,
enum V_25 V_26 ,
T_3 V_48 , T_3 V_49 )
{
const struct V_50 * V_51 =
& V_52 [ V_26 ] ;
const struct V_53 * V_54 = & V_51 -> V_13 ;
if ( ! V_49 )
return;
if ( F_5 ( V_51 -> type != V_55 ) )
return;
F_37 ( V_47 -> V_56 . V_57 , V_54 , 0 , V_48 ) ;
F_37 ( V_47 -> V_56 . V_58 , V_54 , 0 , V_49 ) ;
F_20 ( & V_47 -> V_22 , V_26 ) ;
}
void F_38 ( struct V_46 * V_47 ,
enum V_25 V_26 ,
const char * V_48 , const char * V_49 ,
unsigned int V_59 )
{
const struct V_50 * V_51 =
& V_52 [ V_26 ] ;
const struct V_53 * V_54 = & V_51 -> V_13 ;
if ( ! F_39 ( V_49 , 0 , V_59 ) )
return;
if ( F_5 ( V_51 -> type != V_60 ) ||
F_5 ( V_51 -> V_13 . V_14 . V_61 != V_59 ) )
return;
F_40 ( V_47 -> V_56 . V_57 , V_48 ,
V_54 , 0 ) ;
F_40 ( V_47 -> V_56 . V_58 , V_49 ,
V_54 , 0 ) ;
F_20 ( & V_47 -> V_22 , V_26 ) ;
}
static void F_41 ( const struct V_53 * V_54 ,
const struct V_53 * V_62 ,
char * V_56 , char * V_63 )
{
T_3 V_64 ;
V_64 = F_42 ( V_56 , V_54 , 0 ) ;
F_37 ( V_63 , V_62 , 0 , V_64 ) ;
}
static void F_43 ( const struct V_53 * V_54 ,
const struct V_53 * V_62 ,
char * V_56 , char * V_63 )
{
char * V_65 = F_44 ( V_56 , V_54 , 0 ) ;
char * V_66 = F_44 ( V_63 , V_62 , 0 ) ;
T_1 V_59 = V_62 -> V_14 . V_61 ;
memcpy ( V_66 , V_65 , V_59 ) ;
}
static void F_45 ( const struct V_9 * V_10 ,
int V_29 , char * V_56 , char * V_67 )
{
char * V_63 = V_67 + V_29 * V_68 ;
const struct V_53 * V_54 = & V_10 -> V_12 -> V_13 ;
const struct V_53 * V_62 = & V_10 -> V_13 ;
if ( V_10 -> type == V_55 )
F_41 ( V_54 , V_62 ,
V_56 , V_63 ) ;
else if ( V_10 -> type == V_60 )
F_43 ( V_54 , V_62 ,
V_56 , V_63 ) ;
}
void F_46 ( struct V_19 * V_20 ,
struct V_46 * V_47 ,
char * V_57 , char * V_58 )
{
const struct V_9 * V_10 ;
enum V_25 V_26 ;
int V_29 ;
F_21 (element, &values->elusage) {
V_10 = F_32 ( V_20 , V_26 ,
& V_29 ) ;
if ( ! V_10 )
continue;
F_45 ( V_10 , V_29 ,
V_47 -> V_56 . V_57 , V_57 ) ;
F_45 ( V_10 , V_29 ,
V_47 -> V_56 . V_58 , V_58 ) ;
}
}
