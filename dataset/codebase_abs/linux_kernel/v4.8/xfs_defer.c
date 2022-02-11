STATIC void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 (dfp, &dop->dop_intake, dfp_list) {
F_3 ( V_2 -> V_9 , V_8 ) ;
V_8 -> V_10 = V_8 -> V_11 -> V_12 ( V_2 ,
V_8 -> V_13 ) ;
F_4 ( V_2 -> V_9 , & V_8 -> V_14 ,
V_8 -> V_11 -> V_15 ) ;
F_5 (li, &dfp->dfp_work)
V_8 -> V_11 -> V_16 ( V_2 , V_8 -> V_10 , V_6 ) ;
}
F_6 ( & V_4 -> V_17 , & V_4 -> V_18 ) ;
}
STATIC void
F_7 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int error )
{
struct V_7 * V_8 ;
F_8 ( V_2 -> V_9 , V_4 ) ;
if ( ! V_4 -> V_19 )
return;
F_2 (dfp, &dop->dop_pending, dfp_list) {
F_9 ( V_2 -> V_9 , V_8 ) ;
if ( ! V_8 -> V_20 )
V_8 -> V_11 -> V_21 ( V_8 -> V_10 ) ;
}
F_10 ( V_2 -> V_9 , ( error == - V_22 ) ?
V_23 : V_24 ) ;
}
STATIC int
F_11 (
struct V_1 * * V_2 ,
struct V_3 * V_4 ,
struct V_25 * V_26 )
{
int V_27 ;
int error ;
for ( V_27 = 0 ; V_27 < V_28 && V_4 -> V_29 [ V_27 ] ; V_27 ++ ) {
if ( V_4 -> V_29 [ V_27 ] == V_26 )
continue;
F_12 ( * V_2 , V_4 -> V_29 [ V_27 ] , V_30 ) ;
}
F_13 ( ( * V_2 ) -> V_9 , V_4 ) ;
error = F_14 ( V_2 , V_26 ) ;
if ( error ) {
F_15 ( ( * V_2 ) -> V_9 , V_4 , error ) ;
F_7 ( * V_2 , V_4 , error ) ;
return error ;
}
V_4 -> V_19 = true ;
for ( V_27 = 0 ; V_27 < V_28 && V_4 -> V_29 [ V_27 ] ; V_27 ++ ) {
if ( V_4 -> V_29 [ V_27 ] == V_26 )
continue;
F_16 ( * V_2 , V_4 -> V_29 [ V_27 ] , 0 ) ;
}
return error ;
}
bool
F_17 (
struct V_3 * V_4 )
{
return ! F_18 ( & V_4 -> V_18 ) || ! F_18 ( & V_4 -> V_17 ) ;
}
int
F_19 (
struct V_3 * V_4 ,
struct V_25 * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( V_4 -> V_29 [ V_27 ] == V_26 )
return 0 ;
else if ( V_4 -> V_29 [ V_27 ] == NULL ) {
V_4 -> V_29 [ V_27 ] = V_26 ;
return 0 ;
}
}
return - V_22 ;
}
int
F_20 (
struct V_1 * * V_2 ,
struct V_3 * V_4 ,
struct V_25 * V_26 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_5 * V_31 ;
void * V_32 ;
int error = 0 ;
void (* F_21)( struct V_1 * , void * , int );
ASSERT ( ( * V_2 ) -> V_33 & V_34 ) ;
F_22 ( ( * V_2 ) -> V_9 , V_4 ) ;
while ( F_17 ( V_4 ) ) {
F_1 ( * V_2 , V_4 ) ;
error = F_11 ( V_2 , V_4 , V_26 ) ;
if ( error )
goto V_35;
V_8 = F_23 ( & V_4 -> V_18 ,
struct V_7 , V_36 ) ;
F_24 ( ( * V_2 ) -> V_9 , V_8 ) ;
V_8 -> V_20 = V_8 -> V_11 -> V_37 ( * V_2 , V_8 -> V_10 ,
V_8 -> V_13 ) ;
F_21 = V_8 -> V_11 -> V_38 ;
V_32 = NULL ;
F_25 (li, n, &dfp->dfp_work) {
F_26 ( V_6 ) ;
V_8 -> V_13 -- ;
error = V_8 -> V_11 -> V_39 ( * V_2 , V_4 , V_6 ,
V_8 -> V_20 , & V_32 ) ;
if ( error ) {
if ( F_21 )
F_21 ( * V_2 , V_32 , error ) ;
F_7 ( * V_2 , V_4 , error ) ;
goto V_35;
}
}
F_26 ( & V_8 -> V_36 ) ;
F_27 ( V_8 ) ;
if ( F_21 )
F_21 ( * V_2 , V_32 , error ) ;
}
V_35:
if ( error )
F_28 ( ( * V_2 ) -> V_9 , V_4 , error ) ;
else
F_29 ( ( * V_2 ) -> V_9 , V_4 ) ;
return error ;
}
void
F_30 (
struct V_3 * V_4 )
{
struct V_7 * V_8 ;
struct V_7 * V_40 ;
struct V_5 * V_41 ;
struct V_5 * V_31 ;
F_31 ( NULL , V_4 ) ;
F_32 (dfp, pli, &dop->dop_intake, dfp_list) {
F_33 ( NULL , V_8 ) ;
F_26 ( & V_8 -> V_36 ) ;
F_25 (pwi, n, &dfp->dfp_work) {
F_26 ( V_41 ) ;
V_8 -> V_13 -- ;
V_8 -> V_11 -> V_42 ( V_41 ) ;
}
ASSERT ( V_8 -> V_13 == 0 ) ;
F_27 ( V_8 ) ;
}
F_32 (dfp, pli, &dop->dop_pending, dfp_list) {
F_34 ( NULL , V_8 ) ;
F_26 ( & V_8 -> V_36 ) ;
F_25 (pwi, n, &dfp->dfp_work) {
F_26 ( V_41 ) ;
V_8 -> V_13 -- ;
V_8 -> V_11 -> V_42 ( V_41 ) ;
}
ASSERT ( V_8 -> V_13 == 0 ) ;
F_27 ( V_8 ) ;
}
}
void
F_35 (
struct V_3 * V_4 ,
enum V_43 type ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = NULL ;
if ( ! F_18 ( & V_4 -> V_17 ) ) {
V_8 = F_36 ( & V_4 -> V_17 ,
struct V_7 , V_36 ) ;
if ( V_8 -> V_11 -> type != type ||
( V_8 -> V_11 -> V_44 &&
V_8 -> V_13 >= V_8 -> V_11 -> V_44 ) )
V_8 = NULL ;
}
if ( ! V_8 ) {
V_8 = F_37 ( sizeof( struct V_7 ) ,
V_45 | V_46 ) ;
V_8 -> V_11 = V_47 [ type ] ;
V_8 -> V_10 = NULL ;
V_8 -> V_20 = NULL ;
V_8 -> V_13 = 0 ;
F_38 ( & V_8 -> V_14 ) ;
F_39 ( & V_8 -> V_36 , & V_4 -> V_17 ) ;
}
F_39 ( V_6 , & V_8 -> V_14 ) ;
V_8 -> V_13 ++ ;
}
void
F_40 (
const struct V_48 * type )
{
V_47 [ type -> type ] = type ;
}
void
F_41 (
struct V_3 * V_4 ,
T_1 * V_49 )
{
V_4 -> V_19 = false ;
V_4 -> V_50 = false ;
memset ( & V_4 -> V_29 , 0 , sizeof( V_4 -> V_29 ) ) ;
* V_49 = V_51 ;
F_38 ( & V_4 -> V_17 ) ;
F_38 ( & V_4 -> V_18 ) ;
F_42 ( NULL , V_4 ) ;
}
