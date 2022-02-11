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
int
F_7 ( struct V_1 * V_2 )
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
void
F_12 ( struct V_1 * V_2 )
{
F_8 ( & V_17 ) ;
F_13 ( & V_2 -> V_18 ) ;
F_10 ( & V_17 ) ;
F_11 ( L_3 , V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
}
struct V_1 *
F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_21 ) ;
return V_2 ;
}
struct V_1 *
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
struct V_1 *
F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_22 , * V_2 = NULL ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
if ( V_24 -> V_25 == V_22 -> V_26 . V_25 ) {
if ( 0 == memcmp ( V_24 -> V_27 , V_22 -> V_26 . V_27 , V_24 -> V_25 ) ) {
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
F_22 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_16 == V_16 )
return 1 ;
}
return 0 ;
}
struct V_1 * F_23 ( T_1 V_16 )
{
struct V_1 * V_2 = NULL , * V_22 ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
if ( ! F_22 ( V_22 , V_16 ) ) {
F_24 ( V_22 -> V_21 ) ;
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
F_25 ( T_1 V_16 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_16 ) ;
if ( ! V_2 ) {
F_20 ( L_5 , V_16 ) ;
V_2 = F_23 ( V_16 ) ;
}
return V_2 ;
}
int F_26 ( T_2 * V_28 )
{
struct V_1 * V_22 = NULL ;
int V_5 = 0 ;
F_8 ( & V_17 ) ;
F_17 (pos, &registered_mechs, gm_list) {
V_28 [ V_5 ] = V_22 -> V_7 -> V_16 ;
V_5 ++ ;
}
F_10 ( & V_17 ) ;
return V_5 ;
}
T_1
F_27 ( struct V_1 * V_2 , T_1 V_29 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_29 == V_29 ) {
return V_2 -> V_7 [ V_5 ] . V_16 ;
}
}
return V_30 ;
}
T_1
F_28 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_16 == V_16 )
return V_2 -> V_7 [ V_5 ] . V_29 ;
}
return 0 ;
}
char *
F_29 ( struct V_1 * V_2 , T_1 V_29 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_29 == V_29 )
return V_2 -> V_7 [ V_5 ] . V_8 ;
}
return NULL ;
}
void
F_30 ( struct V_1 * V_2 )
{
if ( V_2 )
F_24 ( V_2 -> V_21 ) ;
}
int
F_31 ( const void * V_31 , T_3 V_32 ,
struct V_1 * V_33 ,
struct V_34 * * V_35 ,
T_4 V_36 )
{
if ( ! ( * V_35 = F_32 ( sizeof( * * V_35 ) , V_36 ) ) )
return - V_14 ;
( * V_35 ) -> V_37 = F_14 ( V_33 ) ;
return V_33 -> V_38
-> F_31 ( V_31 , V_32 , * V_35 , V_36 ) ;
}
T_1
F_33 ( struct V_34 * V_39 ,
struct V_40 * V_41 ,
struct V_23 * V_42 )
{
return V_39 -> V_37 -> V_38
-> F_33 ( V_39 ,
V_41 ,
V_42 ) ;
}
T_1
F_34 ( struct V_34 * V_39 ,
struct V_40 * V_41 ,
struct V_23 * V_42 )
{
return V_39 -> V_37 -> V_38
-> F_34 ( V_39 ,
V_41 ,
V_42 ) ;
}
T_1
F_35 ( struct V_34 * V_35 ,
int V_43 ,
struct V_40 * V_44 ,
struct V_45 * * V_46 )
{
return V_35 -> V_37 -> V_38
-> F_35 ( V_35 , V_43 , V_44 , V_46 ) ;
}
T_1
F_36 ( struct V_34 * V_35 ,
int V_43 ,
struct V_40 * V_44 )
{
return V_35 -> V_37 -> V_38
-> F_36 ( V_35 , V_43 , V_44 ) ;
}
T_1
F_37 ( struct V_34 * * V_39 )
{
F_11 ( L_6 ,
* V_39 ) ;
if ( ! * V_39 )
return V_47 ;
if ( ( * V_39 ) -> V_48 )
( * V_39 ) -> V_37 -> V_38
-> F_37 ( ( * V_39 )
-> V_48 ) ;
F_30 ( ( * V_39 ) -> V_37 ) ;
F_2 ( * V_39 ) ;
* V_39 = NULL ;
return V_49 ;
}
