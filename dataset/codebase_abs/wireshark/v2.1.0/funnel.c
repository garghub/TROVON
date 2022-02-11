const T_1 * F_1 ( void ) { return V_1 ; }
void F_2 ( const T_1 * V_2 ) { V_1 = V_2 ; }
static void F_3 ( T_2 * * V_3 , T_2 * V_4 )
{
if ( ! ( * V_3 ) ) {
* V_3 = V_4 ;
} else {
T_2 * V_5 ;
for ( V_5 = * V_3 ; V_5 -> V_6 ; V_5 = V_5 -> V_6 ) ;
V_5 -> V_6 = V_4 ;
}
}
static void F_4 ( T_2 * * V_3 , T_2 * V_4 )
{
T_2 * V_7 = * V_3 , * V_8 = NULL ;
while ( V_7 ) {
if ( V_7 -> V_9 == V_4 -> V_9 ) {
if ( V_8 ) {
V_8 -> V_6 = V_7 -> V_6 ;
} else {
* V_3 = V_7 -> V_6 ;
}
F_5 ( V_7 -> V_10 ) ;
F_5 ( V_7 ) ;
if ( V_8 ) {
V_7 = V_8 -> V_6 ;
} else {
V_7 = * V_3 ? ( * V_3 ) -> V_6 : NULL ;
}
} else {
V_8 = V_7 ;
V_7 = V_7 -> V_6 ;
}
}
}
static void F_6 ( T_2 * * V_3 )
{
T_2 * V_7 ;
while ( * V_3 ) {
V_7 = * V_3 ;
* V_3 = V_7 -> V_6 ;
F_5 ( V_7 -> V_10 ) ;
F_5 ( V_7 ) ;
}
* V_3 = NULL ;
}
void F_7 ( const char * V_10 ,
T_3 V_11 ,
T_4 V_9 ,
T_5 V_12 ,
T_6 V_13 )
{
T_2 * V_7 = ( T_2 * ) F_8 ( sizeof( T_2 ) ) ;
V_7 -> V_10 = F_9 ( V_10 ) ;
V_7 -> V_11 = V_11 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_6 = NULL ;
F_3 ( & V_14 , V_7 ) ;
if ( V_15 ) {
T_2 * V_16 = ( T_2 * ) F_10 ( V_7 , sizeof *V_7 ) ;
V_16 -> V_10 = F_9 ( V_10 ) ;
F_3 ( & V_17 , V_16 ) ;
}
}
void F_11 ( T_4 V_9 )
{
T_2 * V_7 = ( T_2 * ) F_12 ( sizeof( T_2 ) ) ;
V_7 -> V_9 = V_9 ;
F_4 ( & V_14 , V_7 ) ;
F_3 ( & V_18 , V_7 ) ;
}
void F_13 ( T_7 V_19 )
{
T_2 * V_5 ;
for ( V_5 = V_14 ; V_5 ; V_5 = V_5 -> V_6 ) {
V_19 ( V_5 -> V_10 , V_5 -> V_11 , V_5 -> V_9 , V_5 -> V_12 , V_5 -> V_13 ) ;
}
V_15 = TRUE ;
}
void F_14 ( T_8 V_20 ,
T_7 V_19 )
{
T_2 * V_5 ;
for ( V_5 = V_18 ; V_5 ; V_5 = V_5 -> V_6 ) {
V_20 ( V_5 -> V_9 ) ;
}
for ( V_5 = V_17 ; V_5 ; V_5 = V_5 -> V_6 ) {
V_19 ( V_5 -> V_10 , V_5 -> V_11 , V_5 -> V_9 , V_5 -> V_12 , V_5 -> V_13 ) ;
}
F_6 ( & V_18 ) ;
F_6 ( & V_17 ) ;
}
