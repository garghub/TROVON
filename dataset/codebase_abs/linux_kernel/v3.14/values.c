void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 16 ;
V_2 -> V_4 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_4 ) ) ;
V_2 -> V_5 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_5 ) ) ;
V_2 -> V_6 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_5 || ! V_2 -> V_6 )
F_2 ( L_1 ) ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 16 ;
V_2 -> V_9 = malloc ( V_2 -> V_8
* sizeof( * V_2 -> V_9 ) ) ;
V_2 -> V_10 = malloc ( V_2 -> V_8
* sizeof( * V_2 -> V_10 ) ) ;
if ( ! V_2 -> V_9 || ! V_2 -> V_10 )
F_2 ( L_2 ) ;
V_2 -> V_11 = 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_3 || ! V_2 -> V_8 )
return;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ )
F_4 ( & V_2 -> V_6 [ V_12 ] ) ;
F_4 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_11 ; V_12 ++ )
F_4 ( & V_2 -> V_10 [ V_12 ] ) ;
F_4 ( & V_2 -> V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_3 *= 2 ;
V_2 -> V_4 = realloc ( V_2 -> V_4 ,
V_2 -> V_3 * sizeof( * V_2 -> V_4 ) ) ;
V_2 -> V_5 = realloc ( V_2 -> V_5 ,
V_2 -> V_3 * sizeof( * V_2 -> V_5 ) ) ;
V_2 -> V_6 = realloc ( V_2 -> V_6 ,
V_2 -> V_3 * sizeof( * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_5 || ! V_2 -> V_6 )
F_2 ( L_3 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_4 , T_1 V_5 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ )
if ( V_2 -> V_4 [ V_12 ] == V_4 && V_2 -> V_5 [ V_12 ] == V_5 )
return V_12 ;
if ( V_2 -> V_7 == V_2 -> V_3 )
F_5 ( V_2 ) ;
V_12 = V_2 -> V_7 ++ ;
V_2 -> V_4 [ V_12 ] = V_4 ;
V_2 -> V_5 [ V_12 ] = V_5 ;
V_2 -> V_6 [ V_12 ] = malloc ( V_2 -> V_8 * sizeof( * * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_6 [ V_12 ] )
F_2 ( L_4 ) ;
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_8 *= 2 ;
V_2 -> V_9 = realloc ( V_2 -> V_9 ,
V_2 -> V_8 * sizeof( * V_2 -> V_9 ) ) ;
V_2 -> V_10 = realloc ( V_2 -> V_10 ,
V_2 -> V_8 * sizeof( * V_2 -> V_10 ) ) ;
if ( ! V_2 -> V_9 || ! V_2 -> V_10 )
F_2 ( L_5 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ ) {
V_2 -> V_6 [ V_12 ] = realloc ( V_2 -> V_6 [ V_12 ] ,
V_2 -> V_8 * sizeof( * * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_6 [ V_12 ] )
F_2 ( L_5 ) ;
}
}
static int F_8 ( struct V_1 * V_2 ,
T_2 V_13 , const char * V_14 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_11 ; V_12 ++ )
if ( V_2 -> V_9 [ V_12 ] == V_13 )
return V_12 ;
if ( V_2 -> V_11 == V_2 -> V_8 )
F_7 ( V_2 ) ;
V_12 = V_2 -> V_11 ++ ;
V_2 -> V_9 [ V_12 ] = V_13 ;
V_2 -> V_10 [ V_12 ] = F_9 ( V_14 ) ;
return V_12 ;
}
void F_10 ( struct V_1 * V_2 ,
T_1 V_4 , T_1 V_5 ,
T_2 V_13 , const char * V_14 , T_2 V_6 )
{
int V_15 , V_16 ;
V_15 = F_6 ( V_2 , V_4 , V_5 ) ;
V_16 = F_8 ( V_2 , V_13 , V_14 ) ;
V_2 -> V_6 [ V_15 ] [ V_16 ] = V_6 ;
}
static void F_11 ( T_3 * V_17 ,
struct V_1 * V_2 )
{
int V_12 , V_18 ;
int V_19 , V_20 ;
int * V_21 ;
V_21 = malloc ( V_2 -> V_11 * sizeof( * V_21 ) ) ;
if ( ! V_21 )
F_2 ( L_6 ) ;
V_20 = 3 ;
V_19 = 3 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ )
V_21 [ V_18 ] = strlen ( V_2 -> V_10 [ V_18 ] ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ ) {
int V_22 ;
V_22 = snprintf ( NULL , 0 , L_7 , V_2 -> V_4 [ V_12 ] ) ;
if ( V_22 > V_19 )
V_19 = V_22 ;
V_22 = snprintf ( NULL , 0 , L_7 , V_2 -> V_5 [ V_12 ] ) ;
if ( V_22 > V_20 )
V_20 = V_22 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ ) {
V_22 = snprintf ( NULL , 0 , L_8 V_23 , V_2 -> V_6 [ V_12 ] [ V_18 ] ) ;
if ( V_22 > V_21 [ V_18 ] )
V_21 [ V_18 ] = V_22 ;
}
}
fprintf ( V_17 , L_9 , V_19 , L_10 , V_20 , L_11 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ )
fprintf ( V_17 , L_12 , V_21 [ V_18 ] , V_2 -> V_10 [ V_18 ] ) ;
fprintf ( V_17 , L_13 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ ) {
fprintf ( V_17 , L_14 , V_19 , V_2 -> V_4 [ V_12 ] ,
V_20 , V_2 -> V_5 [ V_12 ] ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ )
fprintf ( V_17 , L_15 V_23 ,
V_21 [ V_18 ] , V_2 -> V_6 [ V_12 ] [ V_18 ] ) ;
fprintf ( V_17 , L_13 ) ;
}
free ( V_21 ) ;
}
static void F_12 ( T_3 * V_17 ,
struct V_1 * V_2 )
{
int V_22 , V_19 , V_20 , V_24 , V_25 , V_26 ;
int V_12 , V_18 ;
V_20 = 3 ;
V_19 = 3 ;
V_24 = 4 ;
V_25 = 3 ;
V_26 = 5 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ ) {
V_22 = snprintf ( NULL , 0 , L_7 , V_2 -> V_4 [ V_12 ] ) ;
if ( V_22 > V_19 )
V_19 = V_22 ;
V_22 = snprintf ( NULL , 0 , L_7 , V_2 -> V_5 [ V_12 ] ) ;
if ( V_22 > V_20 )
V_20 = V_22 ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ ) {
V_22 = strlen ( V_2 -> V_10 [ V_18 ] ) ;
if ( V_22 > V_24 )
V_24 = V_22 ;
V_22 = snprintf ( NULL , 0 , L_8 V_27 , V_2 -> V_9 [ V_18 ] ) ;
if ( V_22 > V_25 )
V_25 = V_22 ;
}
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ ) {
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ ) {
V_22 = snprintf ( NULL , 0 , L_8 V_23 , V_2 -> V_6 [ V_12 ] [ V_18 ] ) ;
if ( V_22 > V_26 )
V_26 = V_22 ;
}
}
fprintf ( V_17 , L_16 ,
V_19 , L_10 , V_20 , L_11 ,
V_24 , L_17 , V_25 , L_18 ,
V_26 , L_19 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_7 ; V_12 ++ )
for ( V_18 = 0 ; V_18 < V_2 -> V_11 ; V_18 ++ )
fprintf ( V_17 , L_20 V_27 L_15 V_23 ,
V_19 , V_2 -> V_4 [ V_12 ] ,
V_20 , V_2 -> V_5 [ V_12 ] ,
V_24 , V_2 -> V_10 [ V_18 ] ,
V_25 , V_2 -> V_9 [ V_18 ] ,
V_26 , V_2 -> V_6 [ V_12 ] [ V_18 ] ) ;
}
void F_13 ( T_3 * V_17 , struct V_1 * V_2 , int V_28 )
{
if ( V_28 )
F_12 ( V_17 , V_2 ) ;
else
F_11 ( V_17 , V_2 ) ;
}
