static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_5 ] ;
F_2 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
}
static inline char *
F_3 ( char * V_9 )
{
static char * V_10 = L_1 ;
char * V_11 ;
V_11 = F_4 ( strlen ( V_9 ) + strlen ( V_10 ) + 1 , V_12 ) ;
if ( V_11 ) {
strcpy ( V_11 , V_10 ) ;
strcat ( V_11 , V_9 ) ;
}
return V_11 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_13 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_5 ] ;
V_4 -> V_8 = F_3 ( V_4 -> V_9 ) ;
V_13 = - V_14 ;
if ( V_4 -> V_8 == NULL )
goto V_15;
V_13 = F_6 ( V_4 -> V_16 ,
V_4 -> V_8 ) ;
if ( V_13 )
goto V_15;
}
return 0 ;
V_15:
F_1 ( V_2 ) ;
return V_13 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_5 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_8 ( & V_17 ) ;
F_9 ( & V_2 -> V_18 , & V_19 ) ;
F_10 ( & V_17 ) ;
F_11 ( L_2 , V_2 -> V_20 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_8 ( & V_17 ) ;
F_13 ( & V_2 -> V_18 ) ;
F_10 ( & V_17 ) ;
F_11 ( L_3 , V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
}
static struct V_1 * F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_21 ) ;
return V_2 ;
}
static struct V_1 *
F_16 ( const char * V_9 )
{
struct V_1 * V_22 , * V_2 = NULL ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
if ( 0 == strcmp ( V_9 , V_22 -> V_20 ) ) {
if ( F_18 ( V_22 -> V_21 ) )
V_2 = V_22 ;
break;
}
}
F_10 ( & V_17 ) ;
return V_2 ;
}
struct V_1 * F_19 ( const char * V_9 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_16 ( V_9 ) ;
if ( ! V_2 ) {
F_20 ( L_4 , V_9 ) ;
V_2 = F_16 ( V_9 ) ;
}
return V_2 ;
}
struct V_1 * F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_22 , * V_2 = NULL ;
char V_25 [ 32 ] ;
if ( F_22 ( V_24 -> V_26 , V_24 -> V_27 , V_25 , sizeof( V_25 ) ) < 0 )
return NULL ;
F_11 ( L_5 , V_28 , V_25 ) ;
F_20 ( L_4 , V_25 ) ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
if ( V_24 -> V_27 == V_22 -> V_29 . V_27 ) {
if ( 0 == memcmp ( V_24 -> V_26 , V_22 -> V_29 . V_26 , V_24 -> V_27 ) ) {
if ( F_18 ( V_22 -> V_21 ) )
V_2 = V_22 ;
break;
}
}
}
F_10 ( & V_17 ) ;
return V_2 ;
}
static inline int
F_23 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_16 == V_16 )
return 1 ;
}
return 0 ;
}
static struct V_1 * F_24 ( T_1 V_16 )
{
struct V_1 * V_2 = NULL , * V_22 ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
if ( ! F_23 ( V_22 , V_16 ) ) {
F_25 ( V_22 -> V_21 ) ;
continue;
}
if ( F_18 ( V_22 -> V_21 ) )
V_2 = V_22 ;
break;
}
F_10 ( & V_17 ) ;
return V_2 ;
}
struct V_1 *
F_26 ( T_1 V_16 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_16 ) ;
if ( ! V_2 ) {
F_20 ( L_6 , V_16 ) ;
V_2 = F_24 ( V_16 ) ;
}
return V_2 ;
}
int F_27 ( T_2 * V_30 , int V_31 )
{
struct V_1 * V_22 = NULL ;
int V_32 , V_5 = 0 ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
for ( V_32 = 0 ; V_32 < V_22 -> V_6 ; V_32 ++ ) {
if ( V_5 >= V_31 ) {
F_10 ( & V_17 ) ;
return - V_14 ;
}
V_30 [ V_5 ++ ] = V_22 -> V_7 [ V_32 ] . V_16 ;
}
}
F_10 ( & V_17 ) ;
return V_5 ;
}
T_2 F_28 ( struct V_1 * V_2 , T_1 V_33 ,
T_1 V_34 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_33 == V_33 &&
V_2 -> V_7 [ V_5 ] . V_34 == V_34 ) {
return V_2 -> V_7 [ V_5 ] . V_16 ;
}
}
return V_35 ;
}
T_2 F_29 ( struct V_36 * V_37 )
{
T_2 V_16 ;
struct V_1 * V_2 ;
V_2 = F_21 ( & V_37 -> V_38 ) ;
if ( V_2 == NULL )
return V_35 ;
V_16 = F_28 ( V_2 , V_37 -> V_33 , V_37 -> V_34 ) ;
F_30 ( V_2 ) ;
return V_16 ;
}
int F_31 ( T_2 V_16 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_26 ( V_16 ) ;
if ( V_2 == NULL )
return - V_39 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_16 == V_16 ) {
memcpy ( V_37 -> V_38 . V_26 , V_2 -> V_29 . V_26 , V_2 -> V_29 . V_27 ) ;
V_37 -> V_38 . V_27 = V_2 -> V_29 . V_27 ;
V_37 -> V_33 = V_2 -> V_7 [ V_5 ] . V_33 ;
V_37 -> V_34 = V_2 -> V_7 [ V_5 ] . V_34 ;
F_30 ( V_2 ) ;
return 0 ;
}
}
F_30 ( V_2 ) ;
return - V_39 ;
}
T_1
F_32 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_16 == V_16 )
return V_2 -> V_7 [ V_5 ] . V_34 ;
}
return 0 ;
}
char *
F_33 ( struct V_1 * V_2 , T_1 V_34 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_34 == V_34 )
return V_2 -> V_7 [ V_5 ] . V_8 ;
}
return NULL ;
}
void
F_30 ( struct V_1 * V_2 )
{
if ( V_2 )
F_25 ( V_2 -> V_21 ) ;
}
int
F_34 ( const void * V_40 , T_3 V_41 ,
struct V_1 * V_42 ,
struct V_43 * * V_44 ,
T_4 * V_45 ,
T_5 V_46 )
{
if ( ! ( * V_44 = F_35 ( sizeof( * * V_44 ) , V_46 ) ) )
return - V_14 ;
( * V_44 ) -> V_47 = F_14 ( V_42 ) ;
return V_42 -> V_48 -> F_34 ( V_40 , V_41 ,
* V_44 , V_45 , V_46 ) ;
}
T_1
F_36 ( struct V_43 * V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
return V_49 -> V_47 -> V_48
-> F_36 ( V_49 ,
V_51 ,
V_53 ) ;
}
T_1
F_37 ( struct V_43 * V_49 ,
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
return V_49 -> V_47 -> V_48
-> F_37 ( V_49 ,
V_51 ,
V_53 ) ;
}
T_1
F_38 ( struct V_43 * V_44 ,
int V_54 ,
struct V_50 * V_25 ,
struct V_55 * * V_56 )
{
return V_44 -> V_47 -> V_48
-> F_38 ( V_44 , V_54 , V_25 , V_56 ) ;
}
T_1
F_39 ( struct V_43 * V_44 ,
int V_54 ,
struct V_50 * V_25 )
{
return V_44 -> V_47 -> V_48
-> F_39 ( V_44 , V_54 , V_25 ) ;
}
T_1
F_40 ( struct V_43 * * V_49 )
{
F_11 ( L_7 ,
* V_49 ) ;
if ( ! * V_49 )
return V_57 ;
if ( ( * V_49 ) -> V_58 )
( * V_49 ) -> V_47 -> V_48
-> F_40 ( ( * V_49 )
-> V_58 ) ;
F_30 ( ( * V_49 ) -> V_47 ) ;
F_2 ( * V_49 ) ;
* V_49 = NULL ;
return V_59 ;
}
