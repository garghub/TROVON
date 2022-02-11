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
struct V_18 * V_19 = F_9 ( V_7 -> V_20 ) ;
V_9 = F_10 ( sizeof( * V_9 ) , V_21 ) ;
if ( V_9 == NULL )
goto V_22;
F_11 ( & V_9 -> V_13 ) ;
V_9 -> V_16 = V_16 ;
V_17 = sizeof( V_9 -> V_11 ) * V_7 -> V_10 ;
V_9 -> V_11 = F_12 ( V_17 , V_21 ) ;
if ( V_9 -> V_11 == NULL )
goto V_22;
for ( V_4 = 0 ; V_4 < V_7 -> V_10 ; V_4 ++ ) {
const struct V_23 * V_24 = & V_7 -> V_25 [ V_4 ] ;
struct V_14 * V_15 = F_13 ( V_24 ) ;
if ( V_15 == NULL )
goto V_22;
V_9 -> V_11 [ V_4 ] = V_15 ;
}
F_14 ( & V_9 -> V_13 , & V_7 -> V_26 ) ;
return V_9 ;
V_22:
F_15 ( V_19 , V_27 ,
L_1 , V_16 ) ;
F_5 ( V_7 , V_9 ) ;
return NULL ;
}
static struct V_8 *
F_16 ( struct V_6 * V_7 , T_2 V_16 )
{
struct V_8 * V_9 ;
F_17 (cd, &dpd->channel_detectors, head) {
if ( V_9 -> V_16 == V_16 )
return V_9 ;
}
return F_8 ( V_7 , V_16 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
if ( ! F_19 ( & V_7 -> V_26 ) )
F_17 (cd, &dpd->channel_detectors, head)
F_3 ( V_7 , V_9 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_8 * V_9 , * V_28 ;
if ( ! F_19 ( & V_7 -> V_26 ) )
F_21 (cd, cd0, &dpd->channel_detectors, head)
F_5 ( V_7 , V_9 ) ;
F_7 ( V_7 ) ;
}
static bool
F_22 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
T_1 V_4 ;
struct V_8 * V_9 ;
if ( V_7 -> V_3 == V_31 )
return true ;
V_9 = F_16 ( V_7 , V_30 -> V_16 ) ;
if ( V_9 == NULL )
return false ;
V_7 -> V_12 = V_30 -> V_32 ;
if ( V_30 -> V_32 < V_7 -> V_12 )
F_18 ( V_7 ) ;
for ( V_4 = 0 ; V_4 < V_7 -> V_10 ; V_4 ++ ) {
struct V_14 * V_33 = V_9 -> V_11 [ V_4 ] ;
struct V_34 * V_35 = V_33 -> V_36 ( V_33 , V_30 ) ;
if ( V_35 != NULL ) {
F_15 ( F_9 ( V_7 -> V_20 ) , V_27 ,
L_2
L_3 ,
V_30 -> V_16 , V_33 -> V_24 -> V_37 ,
V_35 -> V_38 , V_35 -> V_39 , V_35 -> V_40 ) ;
F_3 ( V_7 , V_9 ) ;
return true ;
}
}
return false ;
}
static bool F_23 ( struct V_6 * V_7 ,
enum V_2 V_3 )
{
const struct V_1 * V_41 ;
struct V_8 * V_9 , * V_28 ;
if ( V_7 -> V_3 == V_3 )
return true ;
V_7 -> V_3 = V_31 ;
V_41 = F_1 ( V_3 ) ;
if ( V_41 == NULL )
return false ;
if ( ! F_19 ( & V_7 -> V_26 ) )
F_21 (cd, cd0, &dpd->channel_detectors, head)
F_5 ( V_7 , V_9 ) ;
V_7 -> V_25 = V_41 -> V_1 ;
V_7 -> V_10 = V_41 -> V_10 ;
V_7 -> V_3 = V_3 ;
return true ;
}
struct V_6 *
F_24 ( struct V_42 * V_20 , enum V_2 V_3 )
{
struct V_6 * V_7 ;
struct V_18 * V_19 = F_9 ( V_20 ) ;
V_7 = F_10 ( sizeof( * V_7 ) , V_43 ) ;
if ( V_7 == NULL )
return NULL ;
* V_7 = V_44 ;
F_11 ( & V_7 -> V_26 ) ;
V_7 -> V_20 = V_20 ;
if ( V_7 -> V_45 ( V_7 , V_3 ) )
return V_7 ;
F_15 ( V_19 , V_27 , L_4 , V_3 ) ;
F_7 ( V_7 ) ;
return NULL ;
}
