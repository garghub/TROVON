static const struct V_1 *
F_1 ( enum V_2 V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] -> V_3 == V_3 )
return V_5 [ V_4 ] ;
}
return NULL ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_4 ;
if ( V_9 == NULL )
return;
for ( V_4 = 0 ; V_4 < V_7 -> V_10 ; V_4 ++ )
V_9 -> V_11 [ V_4 ] -> F_4 ( V_9 -> V_11 [ V_4 ] , V_7 -> V_12 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_4 ;
if ( V_9 == NULL )
return;
F_6 ( & V_9 -> V_13 ) ;
for ( V_4 = 0 ; V_4 < V_7 -> V_10 ; V_4 ++ ) {
struct V_14 * V_15 = V_9 -> V_11 [ V_4 ] ;
if ( V_15 != NULL )
V_15 -> exit ( V_15 ) ;
}
F_7 ( V_9 -> V_11 ) ;
F_7 ( V_9 ) ;
}
static struct V_8 *
F_8 ( struct V_6 * V_7 , T_2 V_16 )
{
T_1 V_17 , V_4 ;
struct V_8 * V_9 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_18 ) ;
if ( V_9 == NULL )
goto V_19;
F_10 ( & V_9 -> V_13 ) ;
V_9 -> V_16 = V_16 ;
V_17 = sizeof( V_9 -> V_11 ) * V_7 -> V_10 ;
V_9 -> V_11 = F_11 ( V_17 , V_18 ) ;
if ( V_9 -> V_11 == NULL )
goto V_19;
for ( V_4 = 0 ; V_4 < V_7 -> V_10 ; V_4 ++ ) {
const struct V_20 * V_21 = & V_7 -> V_22 [ V_4 ] ;
struct V_14 * V_15 = F_12 ( V_21 ) ;
if ( V_15 == NULL )
goto V_19;
V_9 -> V_11 [ V_4 ] = V_15 ;
}
F_13 ( & V_9 -> V_13 , & V_7 -> V_23 ) ;
return V_9 ;
V_19:
F_14 ( L_1 , V_16 ) ;
F_5 ( V_7 , V_9 ) ;
return NULL ;
}
static struct V_8 *
F_15 ( struct V_6 * V_7 , T_2 V_16 )
{
struct V_8 * V_9 ;
F_16 (cd, &dpd->channel_detectors, head) {
if ( V_9 -> V_16 == V_16 )
return V_9 ;
}
return F_8 ( V_7 , V_16 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
if ( ! F_18 ( & V_7 -> V_23 ) )
F_16 (cd, &dpd->channel_detectors, head)
F_3 ( V_7 , V_9 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_8 * V_9 , * V_24 ;
if ( ! F_18 ( & V_7 -> V_23 ) )
F_20 (cd, cd0, &dpd->channel_detectors, head)
F_5 ( V_7 , V_9 ) ;
F_7 ( V_7 ) ;
}
static bool
F_21 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
T_1 V_4 ;
bool V_27 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 == V_28 ) {
return true ;
}
V_9 = F_15 ( V_7 , V_26 -> V_16 ) ;
if ( V_9 == NULL )
return false ;
V_27 = ( V_26 -> V_29 < V_7 -> V_12 ) ;
V_7 -> V_12 = V_26 -> V_29 ;
if ( V_27 ) {
F_22 ( L_2 ) ;
F_17 ( V_7 ) ;
}
for ( V_4 = 0 ; V_4 < V_7 -> V_10 ; V_4 ++ ) {
if ( V_9 -> V_11 [ V_4 ] -> F_23 ( V_9 -> V_11 [ V_4 ] , V_26 ) != 0 ) {
F_3 ( V_7 , V_9 ) ;
return true ;
}
}
return false ;
}
static bool F_24 ( struct V_6 * V_7 ,
enum V_2 V_3 )
{
const struct V_1 * V_30 ;
struct V_8 * V_9 , * V_24 ;
if ( V_7 -> V_3 == V_3 )
return true ;
V_7 -> V_3 = V_28 ;
V_30 = F_1 ( V_3 ) ;
if ( V_30 == NULL )
return false ;
if ( ! F_18 ( & V_7 -> V_23 ) )
F_20 (cd, cd0, &dpd->channel_detectors, head)
F_5 ( V_7 , V_9 ) ;
V_7 -> V_22 = V_30 -> V_1 ;
V_7 -> V_10 = V_30 -> V_10 ;
V_7 -> V_3 = V_3 ;
return true ;
}
struct V_6 *
F_25 ( enum V_2 V_3 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( sizeof( * V_7 ) , V_18 ) ;
if ( V_7 == NULL ) {
F_14 ( L_3 ) ;
return NULL ;
}
* V_7 = V_31 ;
F_10 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_32 ( V_7 , V_3 ) )
return V_7 ;
F_14 ( L_4 , V_3 ) ;
return NULL ;
}
