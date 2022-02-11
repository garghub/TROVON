void
F_1 ( void )
{
F_2 () ;
F_3 () ;
F_4 () ;
F_5 () ;
F_6 () ;
F_7 () ;
}
void
F_8 ( void )
{
}
void
F_9 ( T_1 * type )
{
T_2 V_1 ;
V_1 = type -> V_2 ;
F_10 ( V_1 < V_3 ) ;
F_10 ( V_4 [ V_1 ] == NULL ) ;
V_4 [ V_1 ] = type ;
}
static T_1 *
F_11 ( T_2 V_1 )
{
T_1 * V_5 ;
F_10 ( V_1 < V_3 ) ;
V_5 = V_4 [ V_1 ] ;
F_10 ( V_5 != NULL ) ;
return V_5 ;
}
T_3 *
F_12 ( T_2 V_1 , T_4 V_6 )
{
T_1 * type ;
T_3 * V_7 ;
V_7 = F_13 ( T_3 , 1 ) ;
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = FALSE ;
if ( V_1 == V_12 ) {
V_7 -> type = NULL ;
V_7 -> V_6 = NULL ;
}
else {
type = F_11 ( V_1 ) ;
F_10 ( type ) ;
V_7 -> type = type ;
if ( type -> V_13 ) {
V_7 -> V_6 = type -> V_13 ( V_6 ) ;
}
else {
V_7 -> V_6 = V_6 ;
}
}
return V_7 ;
}
void
F_14 ( T_3 * V_7 , T_5 V_14 )
{
V_7 -> V_11 = V_14 ;
}
T_3 *
F_15 ( const T_3 * V_15 )
{
T_1 * type ;
T_3 * V_7 ;
if ( ! V_15 )
return NULL ;
type = V_15 -> type ;
V_7 = F_13 ( T_3 , 1 ) ;
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = NULL ;
V_7 -> type = type ;
if ( type && type -> V_16 )
V_7 -> V_6 = type -> V_16 ( V_15 -> V_6 ) ;
else
V_7 -> V_6 = V_15 -> V_6 ;
V_7 -> V_17 = V_15 -> V_17 ;
V_7 -> V_11 = V_15 -> V_11 ;
return V_7 ;
}
void
F_16 ( T_3 * V_7 , T_2 V_1 , T_4 V_6 )
{
T_1 * type ;
F_17 ( V_7 , V_9 ) ;
F_10 ( ! V_7 -> type ) ;
F_10 ( ! V_7 -> V_6 ) ;
type = F_11 ( V_1 ) ;
F_10 ( type ) ;
V_7 -> type = type ;
if ( type -> V_13 ) {
V_7 -> V_6 = type -> V_13 ( V_6 ) ;
}
else {
V_7 -> V_6 = V_6 ;
}
}
void
F_18 ( T_3 * V_7 , T_2 V_1 , T_6 V_17 )
{
F_16 ( V_7 , V_1 , NULL ) ;
V_7 -> V_17 = V_17 ;
}
void
F_19 ( T_3 * V_7 )
{
F_17 ( V_7 , V_9 ) ;
if ( V_7 -> type ) {
if ( V_7 -> type -> V_18 ) {
V_7 -> type -> V_18 ( V_7 -> V_6 ) ;
}
}
else {
F_10 ( ! V_7 -> V_6 ) ;
}
F_20 ( V_7 ) ;
}
const char *
F_21 ( T_3 * V_7 )
{
F_17 ( V_7 , V_9 ) ;
if ( V_7 -> type )
return V_7 -> type -> V_19 ;
else
return L_1 ;
}
T_2
F_22 ( T_3 * V_7 )
{
F_17 ( V_7 , V_9 ) ;
if ( V_7 -> type )
return V_7 -> type -> V_2 ;
else
return V_12 ;
}
T_4
F_23 ( T_3 * V_7 )
{
F_17 ( V_7 , V_9 ) ;
return V_7 -> V_6 ;
}
T_6
F_24 ( T_3 * V_7 )
{
F_17 ( V_7 , V_9 ) ;
return V_7 -> V_17 ;
}
const char *
F_25 ( T_3 * V_7 )
{
if ( ! V_7 ) {
return NULL ;
}
return V_7 -> V_10 ;
}
