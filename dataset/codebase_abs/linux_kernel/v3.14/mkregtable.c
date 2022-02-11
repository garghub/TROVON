static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 ;
V_2 -> V_4 = V_2 ;
}
static inline void F_2 ( struct V_1 * V_5 ,
struct V_1 * V_4 , struct V_1 * V_3 )
{
V_3 -> V_4 = V_5 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
V_4 -> V_3 = V_5 ;
}
static inline void F_3 ( struct V_1 * V_5 , struct V_1 * V_6 )
{
F_2 ( V_5 , V_6 , V_6 -> V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_5 , struct V_1 * V_6 )
{
F_2 ( V_5 , V_6 -> V_4 , V_6 ) ;
}
static inline void F_5 ( struct V_1 * V_4 , struct V_1 * V_3 )
{
V_3 -> V_4 = V_4 ;
V_4 -> V_3 = V_3 ;
}
static inline void F_6 ( struct V_1 * V_7 )
{
F_5 ( V_7 -> V_4 , V_7 -> V_3 ) ;
V_7 -> V_3 = ( void * ) 0xDEADBEEF ;
V_7 -> V_4 = ( void * ) 0xBEEFDEAD ;
}
static inline void F_7 ( struct V_1 * V_8 , struct V_1 * V_5 )
{
V_5 -> V_3 = V_8 -> V_3 ;
V_5 -> V_3 -> V_4 = V_5 ;
V_5 -> V_4 = V_8 -> V_4 ;
V_5 -> V_4 -> V_3 = V_5 ;
}
static inline void F_8 ( struct V_1 * V_8 ,
struct V_1 * V_5 )
{
F_7 ( V_8 , V_5 ) ;
F_1 ( V_8 ) ;
}
static inline void F_9 ( struct V_1 * V_7 )
{
F_5 ( V_7 -> V_4 , V_7 -> V_3 ) ;
F_1 ( V_7 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , struct V_1 * V_6 )
{
F_5 ( V_2 -> V_4 , V_2 -> V_3 ) ;
F_3 ( V_2 , V_6 ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
struct V_1 * V_6 )
{
F_5 ( V_2 -> V_4 , V_2 -> V_3 ) ;
F_4 ( V_2 , V_6 ) ;
}
static inline int F_12 ( const struct V_1 * V_2 ,
const struct V_1 * V_6 )
{
return V_2 -> V_3 == V_6 ;
}
static inline int F_13 ( const struct V_1 * V_6 )
{
return V_6 -> V_3 == V_6 ;
}
static inline int F_14 ( const struct V_1 * V_6 )
{
struct V_1 * V_3 = V_6 -> V_3 ;
return ( V_3 == V_6 ) && ( V_3 == V_6 -> V_4 ) ;
}
static inline int F_15 ( const struct V_1 * V_6 )
{
return ! F_13 ( V_6 ) && ( V_6 -> V_3 == V_6 -> V_4 ) ;
}
static inline void F_16 ( struct V_1 * V_2 ,
struct V_1 * V_6 ,
struct V_1 * V_7 )
{
struct V_1 * V_9 = V_7 -> V_3 ;
V_2 -> V_3 = V_6 -> V_3 ;
V_2 -> V_3 -> V_4 = V_2 ;
V_2 -> V_4 = V_7 ;
V_7 -> V_3 = V_2 ;
V_6 -> V_3 = V_9 ;
V_9 -> V_4 = V_6 ;
}
static inline void F_17 ( struct V_1 * V_2 ,
struct V_1 * V_6 ,
struct V_1 * V_7 )
{
if ( F_13 ( V_6 ) )
return;
if ( F_15 ( V_6 ) && ( V_6 -> V_3 != V_7 && V_6 != V_7 ) )
return;
if ( V_7 == V_6 )
F_1 ( V_2 ) ;
else
F_16 ( V_2 , V_6 , V_7 ) ;
}
static inline void F_18 ( const struct V_1 * V_2 ,
struct V_1 * V_4 , struct V_1 * V_3 )
{
struct V_1 * V_10 = V_2 -> V_3 ;
struct V_1 * V_11 = V_2 -> V_4 ;
V_10 -> V_4 = V_4 ;
V_4 -> V_3 = V_10 ;
V_11 -> V_3 = V_3 ;
V_3 -> V_4 = V_11 ;
}
static inline void F_19 ( const struct V_1 * V_2 ,
struct V_1 * V_6 )
{
if ( ! F_13 ( V_2 ) )
F_18 ( V_2 , V_6 , V_6 -> V_3 ) ;
}
static inline void F_20 ( struct V_1 * V_2 ,
struct V_1 * V_6 )
{
if ( ! F_13 ( V_2 ) )
F_18 ( V_2 , V_6 -> V_4 , V_6 ) ;
}
static inline void F_21 ( struct V_1 * V_2 ,
struct V_1 * V_6 )
{
if ( ! F_13 ( V_2 ) ) {
F_18 ( V_2 , V_6 , V_6 -> V_3 ) ;
F_1 ( V_2 ) ;
}
}
static inline void F_22 ( struct V_1 * V_2 ,
struct V_1 * V_6 )
{
if ( ! F_13 ( V_2 ) ) {
F_18 ( V_2 , V_6 -> V_4 , V_6 ) ;
F_1 ( V_2 ) ;
}
}
static struct V_12 * F_23 ( unsigned V_13 )
{
struct V_12 * V_12 ;
V_12 = (struct V_12 * ) malloc ( sizeof( struct V_12 ) ) ;
if ( V_12 ) {
F_1 ( & V_12 -> V_2 ) ;
V_12 -> V_12 = V_13 ;
}
return V_12 ;
}
static void F_24 ( struct V_14 * V_15 , struct V_12 * V_12 )
{
F_4 ( & V_12 -> V_2 , & V_15 -> V_16 ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
F_1 ( & V_15 -> V_16 ) ;
V_15 -> V_17 = 0 ;
V_15 -> V_18 = 0 ;
V_15 -> V_14 = NULL ;
}
static void F_26 ( struct V_14 * V_15 )
{
unsigned V_19 , V_20 , V_21 , V_22 , V_23 , V_24 ;
V_19 = ( V_15 -> V_18 + 3 ) / 4 ;
V_23 = V_15 -> V_18 ;
printf ( L_1 , V_15 -> V_25 ,
V_15 -> V_18 ) ;
for ( V_20 = 0 , V_24 = 0 ; V_20 < V_19 ; V_20 ++ ) {
V_22 = 4 ;
if ( V_22 > V_23 )
V_22 = V_23 ;
V_23 -= V_22 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_21 == 0 )
printf ( L_2 ) ;
else
printf ( L_3 ) ;
printf ( L_4 , V_15 -> V_14 [ V_24 ++ ] ) ;
}
printf ( L_5 ) ;
}
printf ( L_6 ) ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_12 * V_12 ;
unsigned V_20 , V_26 ;
V_15 -> V_18 = ( ( V_15 -> V_17 >> 2 ) + 31 ) / 32 ;
V_15 -> V_14 = ( unsigned * ) malloc ( sizeof( unsigned ) * V_15 -> V_18 ) ;
if ( V_15 -> V_14 == NULL )
return - 1 ;
memset ( V_15 -> V_14 , 0xff , sizeof( unsigned ) * V_15 -> V_18 ) ;
F_28 (offset, &t->offsets, list) {
V_20 = ( V_12 -> V_12 >> 2 ) / 32 ;
V_26 = ( V_12 -> V_12 >> 2 ) & 31 ;
V_26 = 1 << V_26 ;
V_15 -> V_14 [ V_20 ] ^= V_26 ;
}
return 0 ;
}
static int F_29 ( struct V_14 * V_15 , const char * V_27 )
{
T_1 * V_28 ;
T_2 V_29 ;
T_3 V_30 [ 4 ] ;
char V_31 [ 1024 ] ;
T_4 V_32 ;
int V_33 ;
int V_34 = 0 ;
int V_35 ;
unsigned V_13 ;
struct V_12 * V_12 ;
char V_36 [ 10 ] ;
int V_37 ;
if ( regcomp
( & V_29 , L_7 , V_38 ) ) {
fprintf ( V_39 , L_8 ) ;
return - 1 ;
}
V_28 = fopen ( V_27 , L_9 ) ;
if ( V_28 == NULL ) {
fprintf ( V_39 , L_10 , V_27 ) ;
return - 1 ;
}
fseek ( V_28 , 0 , V_40 ) ;
V_32 = ftell ( V_28 ) ;
fseek ( V_28 , 0 , V_41 ) ;
if ( fgets ( V_31 , 1024 , V_28 ) == NULL ) {
fclose ( V_28 ) ;
return - 1 ;
}
sscanf ( V_31 , L_11 , V_42 , V_36 ) ;
V_15 -> V_25 = V_42 ;
V_37 = strtol ( V_36 , NULL , 16 ) ;
do {
if ( fgets ( V_31 , 1024 , V_28 ) == NULL ) {
fclose ( V_28 ) ;
return - 1 ;
}
V_33 = strlen ( V_31 ) ;
if ( ftell ( V_28 ) == V_32 )
V_34 = 1 ;
if ( V_33 ) {
V_35 = regexec ( & V_29 , V_31 , 4 , V_30 , 0 ) ;
if ( V_35 == V_43 ) {
} else if ( V_35 ) {
fprintf ( V_39 ,
L_12 ,
V_35 , V_27 ) ;
fclose ( V_28 ) ;
return - 1 ;
} else {
V_31 [ V_30 [ 0 ] . V_44 ] = 0 ;
V_31 [ V_30 [ 1 ] . V_44 ] = 0 ;
V_31 [ V_30 [ 2 ] . V_44 ] = 0 ;
V_13 = strtol ( & V_31 [ V_30 [ 1 ] . V_45 ] , NULL , 16 ) ;
V_12 = F_23 ( V_13 ) ;
F_24 ( V_15 , V_12 ) ;
if ( V_13 > V_15 -> V_17 )
V_15 -> V_17 = V_13 ;
}
}
} while ( ! V_34 );
fclose ( V_28 ) ;
if ( V_15 -> V_17 < V_37 )
V_15 -> V_17 = V_37 ;
return F_27 ( V_15 ) ;
}
int main ( int V_46 , char * V_47 [] )
{
struct V_14 V_15 ;
if ( V_46 != 2 ) {
fprintf ( V_39 , L_13 , V_47 [ 0 ] ) ;
exit ( 1 ) ;
}
F_25 ( & V_15 ) ;
if ( F_29 ( & V_15 , V_47 [ 1 ] ) ) {
fprintf ( V_39 , L_14 , V_47 [ 1 ] ) ;
return - 1 ;
}
F_26 ( & V_15 ) ;
return 0 ;
}
