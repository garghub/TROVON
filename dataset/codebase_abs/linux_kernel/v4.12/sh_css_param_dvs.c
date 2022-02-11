static struct V_1 *
F_1 ( const struct V_2 * V_3 , struct V_1 * V_4 )
{
unsigned int V_5 = 0 ;
unsigned int V_6 = 0 ;
unsigned int V_7 = 0 ;
unsigned int V_8 = 0 ;
enum V_9 V_10 = V_11 ;
struct V_1 * V_12 = NULL ;
V_12 = (struct V_1 * ) F_2 ( sizeof( struct V_1 ) ) ;
if ( V_12 == NULL ) {
F_3 ( L_1 ) ;
V_10 = V_13 ;
}
else
{
if ( NULL != V_4 ) {
V_12 -> V_5 = V_5 = V_4 -> V_5 ;
V_12 -> V_6 = V_6 = V_4 -> V_6 ;
V_12 -> V_7 = V_7 = V_4 -> V_7 ;
V_12 -> V_8 = V_8 = V_4 -> V_8 ;
F_4 ( L_2 , V_5 , V_6 ) ;
}
else if ( NULL != V_3 ) {
V_12 -> V_5 = V_5 = F_5 ( V_3 -> V_14 ) ;
V_12 -> V_6 = V_6 = F_6 ( V_3 -> V_15 ) ;
V_12 -> V_7 = V_7 = F_7 ( V_3 -> V_14 / 2 ) ;
V_12 -> V_8 = V_8 = F_8 ( V_3 -> V_15 / 2 ) ;
F_4 ( L_2 , V_5 , V_6 ) ;
}
V_12 -> V_16 = ( V_17 * ) F_2 ( V_5 * V_6 * sizeof( V_17 ) ) ;
if ( V_12 -> V_16 == NULL ) {
F_3 ( L_1 ) ;
V_10 = V_13 ;
goto exit;
}
V_12 -> V_18 = ( V_17 * ) F_2 ( V_5 * V_6 * sizeof( V_17 ) ) ;
if ( V_12 -> V_18 == NULL ) {
F_3 ( L_1 ) ;
V_10 = V_13 ;
goto exit;
}
F_4 ( L_3 , V_7 , V_8 ) ;
V_12 -> V_19 = ( V_17 * ) F_2 ( V_7 * V_8 * sizeof( V_17 ) ) ;
if ( V_12 -> V_19 == NULL ) {
F_3 ( L_1 ) ;
V_10 = V_13 ;
goto exit;
}
V_12 -> V_20 = ( V_17 * ) F_2 ( V_7 * V_8 * sizeof( V_17 ) ) ;
if ( V_12 -> V_20 == NULL ) {
F_3 ( L_1 ) ;
V_10 = V_13 ;
}
exit:
if ( V_10 != V_11 ) {
F_9 ( & V_12 ) ;
V_12 = NULL ;
}
}
F_10 ( L_4 , V_12 ) ;
return V_12 ;
}
static void
F_11 ( struct V_1 * V_12 , const struct V_2 * V_21 )
{
unsigned int V_22 , V_23 ;
unsigned int V_5 = V_12 -> V_5 ;
unsigned int V_6 = V_12 -> V_6 ;
unsigned int V_7 = V_12 -> V_7 ;
unsigned int V_8 = V_12 -> V_8 ;
F_4 ( L_5 ,
V_21 -> V_14 , V_21 -> V_15 , V_5 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_6 ; V_23 ++ ) {
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_12 -> V_16 [ V_23 * V_5 + V_22 ] = ( V_21 -> V_14 + V_22 * V_24 ) << V_25 ;
}
}
for ( V_23 = 0 ; V_23 < V_6 ; V_23 ++ ) {
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_12 -> V_18 [ V_23 * V_5 + V_22 ] = ( V_21 -> V_15 + V_23 * V_26 ) << V_25 ;
}
}
for ( V_23 = 0 ; V_23 < V_8 ; V_23 ++ ) {
for ( V_22 = 0 ; V_22 < V_7 ; V_22 ++ ) {
V_12 -> V_19 [ V_23 * V_7 + V_22 ] = ( ( V_21 -> V_14 / 2 ) + V_22 * V_24 ) << V_25 ;
}
}
for ( V_23 = 0 ; V_23 < V_8 ; V_23 ++ ) {
for ( V_22 = 0 ; V_22 < V_7 ; V_22 ++ ) {
V_12 -> V_20 [ V_23 * V_7 + V_22 ] = ( ( V_21 -> V_15 / 2 ) + V_23 * V_27 ) << V_25 ;
}
}
}
static void
F_12 ( struct V_1 * V_12 , struct V_1 * V_4 )
{
unsigned int V_5 = V_12 -> V_5 ;
unsigned int V_6 = V_12 -> V_6 ;
unsigned int V_7 = V_12 -> V_7 ;
unsigned int V_8 = V_12 -> V_8 ;
memcpy ( V_12 -> V_16 , V_4 -> V_16 , ( V_5 * V_6 * sizeof( V_17 ) ) ) ;
memcpy ( V_12 -> V_18 , V_4 -> V_18 , ( V_5 * V_6 * sizeof( V_17 ) ) ) ;
memcpy ( V_12 -> V_19 , V_4 -> V_19 , ( V_7 * V_8 * sizeof( V_17 ) ) ) ;
memcpy ( V_12 -> V_20 , V_4 -> V_20 , ( V_7 * V_8 * sizeof( V_17 ) ) ) ;
}
struct V_1 *
F_13 ( const struct V_2 * V_3 , const struct V_2 * V_21 )
{
struct V_1 * V_28 ;
assert ( V_3 != NULL ) ;
assert ( V_21 != NULL ) ;
V_28 = F_1 ( V_3 , NULL ) ;
if ( V_28 ) {
F_11 ( V_28 , V_21 ) ;
return V_28 ;
}
return NULL ;
}
struct V_1 *
F_14 ( struct V_1 * V_4 )
{
struct V_1 * V_28 ;
assert ( NULL != V_4 ) ;
V_28 = F_1 ( NULL , V_4 ) ;
if ( V_28 ) {
F_12 ( V_28 , V_4 ) ;
return V_28 ;
}
return NULL ;
}
void
F_9 ( struct V_1 * * V_29 )
{
assert ( V_29 != NULL ) ;
assert ( * V_29 != NULL ) ;
if ( ( V_29 != NULL ) && ( * V_29 != NULL ) )
{
F_15 ( L_6 , ( * V_29 ) ) ;
if ( ( * V_29 ) -> V_16 != NULL )
{
F_16 ( ( * V_29 ) -> V_16 ) ;
( * V_29 ) -> V_16 = NULL ;
}
if ( ( * V_29 ) -> V_18 != NULL )
{
F_16 ( ( * V_29 ) -> V_18 ) ;
( * V_29 ) -> V_18 = NULL ;
}
if ( ( * V_29 ) -> V_19 != NULL )
{
F_16 ( ( * V_29 ) -> V_19 ) ;
( * V_29 ) -> V_19 = NULL ;
}
if ( ( * V_29 ) -> V_20 != NULL )
{
F_16 ( ( * V_29 ) -> V_20 ) ;
( * V_29 ) -> V_20 = NULL ;
}
F_17 ( L_6 , ( * V_29 ) ) ;
F_16 ( * V_29 ) ;
* V_29 = NULL ;
}
}
void F_18 ( struct V_1 * V_30 ,
const struct V_1 * V_4 )
{
unsigned int V_5 ;
unsigned int V_6 ;
unsigned int V_7 ;
unsigned int V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_30 != NULL ) ;
assert ( V_4 -> V_16 != NULL ) ;
assert ( V_4 -> V_19 != NULL ) ;
assert ( V_4 -> V_18 != NULL ) ;
assert ( V_4 -> V_20 != NULL ) ;
assert ( V_4 -> V_5 == V_30 -> V_5 ) ;
assert ( V_4 -> V_7 == V_30 -> V_7 ) ;
assert ( V_4 -> V_6 == V_30 -> V_6 ) ;
assert ( V_4 -> V_8 == V_30 -> V_8 ) ;
V_5 = V_4 -> V_5 ;
V_6 = V_4 -> V_6 ;
V_7 = V_4 -> V_7 ;
V_8 = V_4 -> V_8 ;
memcpy ( V_30 -> V_16 , V_4 -> V_16 , ( V_5 * V_6 * sizeof( V_17 ) ) ) ;
memcpy ( V_30 -> V_18 , V_4 -> V_18 , ( V_5 * V_6 * sizeof( V_17 ) ) ) ;
memcpy ( V_30 -> V_19 , V_4 -> V_19 , ( V_7 * V_8 * sizeof( V_17 ) ) ) ;
memcpy ( V_30 -> V_20 , V_4 -> V_20 , ( V_7 * V_8 * sizeof( V_17 ) ) ) ;
}
void
F_19 ( enum V_31 type ,
union V_32 * V_33 ,
const union V_34 * V_35 )
{
if ( V_36 == type )
{
F_20 ( V_33 -> V_37 ,
V_35 -> V_38 ) ;
} else if ( V_39 == type )
{
F_21 ( V_33 -> V_40 ,
V_35 -> V_38 ) ;
}
return;
}
