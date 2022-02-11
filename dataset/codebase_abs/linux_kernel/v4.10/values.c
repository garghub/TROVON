int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 16 ;
V_2 -> V_4 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_4 ) ) ;
V_2 -> V_5 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_5 ) ) ;
V_2 -> V_6 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_5 || ! V_2 -> V_6 ) {
F_2 ( L_1 ) ;
goto V_7;
}
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 16 ;
V_2 -> V_10 = malloc ( V_2 -> V_9
* sizeof( * V_2 -> V_10 ) ) ;
V_2 -> V_11 = malloc ( V_2 -> V_9
* sizeof( * V_2 -> V_11 ) ) ;
if ( ! V_2 -> V_10 || ! V_2 -> V_11 ) {
F_2 ( L_2 ) ;
goto V_12;
}
V_2 -> V_13 = 0 ;
return 0 ;
V_12:
F_3 ( & V_2 -> V_10 ) ;
F_3 ( & V_2 -> V_11 ) ;
V_7:
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
return - V_14 ;
}
void F_4 ( struct V_1 * V_2 )
{
int V_15 ;
if ( ! V_2 -> V_3 || ! V_2 -> V_9 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ )
F_3 ( & V_2 -> V_6 [ V_15 ] ) ;
F_3 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_10 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_13 ; V_15 ++ )
F_3 ( & V_2 -> V_11 [ V_15 ] ) ;
F_3 ( & V_2 -> V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_16 = V_2 -> V_3 * 2 ;
void * V_17 = realloc ( V_2 -> V_4 , V_16 * sizeof( * V_2 -> V_4 ) ) ,
* V_18 = realloc ( V_2 -> V_5 , V_16 * sizeof( * V_2 -> V_5 ) ) ,
* V_19 = realloc ( V_2 -> V_6 , V_16 * sizeof( * V_2 -> V_6 ) ) ;
if ( ! V_17 || ! V_18 || ! V_19 )
goto V_20;
V_2 -> V_3 = V_16 ;
V_2 -> V_4 = V_17 ;
V_2 -> V_5 = V_18 ;
V_2 -> V_6 = V_19 ;
return 0 ;
V_20:
free ( V_17 ) ;
free ( V_18 ) ;
free ( V_19 ) ;
F_2 ( L_3 ) ;
return - V_14 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_4 , T_1 V_5 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ )
if ( V_2 -> V_4 [ V_15 ] == V_4 && V_2 -> V_5 [ V_15 ] == V_5 )
return V_15 ;
if ( V_2 -> V_8 == V_2 -> V_3 ) {
V_15 = F_5 ( V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_15 = V_2 -> V_8 + 1 ;
V_2 -> V_6 [ V_15 ] = malloc ( V_2 -> V_9 * sizeof( * * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_6 [ V_15 ] ) {
F_2 ( L_4 ) ;
return - V_14 ;
}
V_2 -> V_4 [ V_15 ] = V_4 ;
V_2 -> V_5 [ V_15 ] = V_5 ;
V_2 -> V_8 = V_15 ;
return V_15 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_9 *= 2 ;
V_2 -> V_10 = realloc ( V_2 -> V_10 ,
V_2 -> V_9 * sizeof( * V_2 -> V_10 ) ) ;
V_2 -> V_11 = realloc ( V_2 -> V_11 ,
V_2 -> V_9 * sizeof( * V_2 -> V_11 ) ) ;
if ( ! V_2 -> V_10 || ! V_2 -> V_11 )
F_8 ( L_5 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
V_2 -> V_6 [ V_15 ] = realloc ( V_2 -> V_6 [ V_15 ] ,
V_2 -> V_9 * sizeof( * * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_6 [ V_15 ] )
F_8 ( L_5 ) ;
}
}
static int F_9 ( struct V_1 * V_2 ,
T_2 V_21 , const char * V_22 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_13 ; V_15 ++ )
if ( V_2 -> V_10 [ V_15 ] == V_21 )
return V_15 ;
if ( V_2 -> V_13 == V_2 -> V_9 )
F_7 ( V_2 ) ;
V_15 = V_2 -> V_13 ++ ;
V_2 -> V_10 [ V_15 ] = V_21 ;
V_2 -> V_11 [ V_15 ] = F_10 ( V_22 ) ;
return V_15 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_4 , T_1 V_5 ,
T_2 V_21 , const char * V_22 , T_2 V_6 )
{
int V_23 , V_24 ;
V_23 = F_6 ( V_2 , V_4 , V_5 ) ;
if ( V_23 < 0 )
return V_23 ;
V_24 = F_9 ( V_2 , V_21 , V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_6 [ V_23 ] [ V_24 ] = V_6 ;
return 0 ;
}
static void F_12 ( T_3 * V_25 ,
struct V_1 * V_2 )
{
int V_15 , V_26 ;
int V_27 , V_28 ;
int * V_29 ;
V_29 = malloc ( V_2 -> V_13 * sizeof( * V_29 ) ) ;
if ( ! V_29 )
F_8 ( L_6 ) ;
V_28 = 3 ;
V_27 = 3 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ )
V_29 [ V_26 ] = strlen ( V_2 -> V_11 [ V_26 ] ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
int V_30 ;
V_30 = snprintf ( NULL , 0 , L_7 , V_2 -> V_4 [ V_15 ] ) ;
if ( V_30 > V_27 )
V_27 = V_30 ;
V_30 = snprintf ( NULL , 0 , L_7 , V_2 -> V_5 [ V_15 ] ) ;
if ( V_30 > V_28 )
V_28 = V_30 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ ) {
V_30 = snprintf ( NULL , 0 , L_8 V_31 , V_2 -> V_6 [ V_15 ] [ V_26 ] ) ;
if ( V_30 > V_29 [ V_26 ] )
V_29 [ V_26 ] = V_30 ;
}
}
fprintf ( V_25 , L_9 , V_27 , L_10 , V_28 , L_11 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ )
fprintf ( V_25 , L_12 , V_29 [ V_26 ] , V_2 -> V_11 [ V_26 ] ) ;
fprintf ( V_25 , L_13 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
fprintf ( V_25 , L_14 , V_27 , V_2 -> V_4 [ V_15 ] ,
V_28 , V_2 -> V_5 [ V_15 ] ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ )
fprintf ( V_25 , L_15 V_31 ,
V_29 [ V_26 ] , V_2 -> V_6 [ V_15 ] [ V_26 ] ) ;
fprintf ( V_25 , L_13 ) ;
}
free ( V_29 ) ;
}
static void F_13 ( T_3 * V_25 ,
struct V_1 * V_2 )
{
int V_30 , V_27 , V_28 , V_32 , V_33 , V_34 ;
int V_15 , V_26 ;
V_28 = 3 ;
V_27 = 3 ;
V_32 = 4 ;
V_33 = 3 ;
V_34 = 5 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
V_30 = snprintf ( NULL , 0 , L_7 , V_2 -> V_4 [ V_15 ] ) ;
if ( V_30 > V_27 )
V_27 = V_30 ;
V_30 = snprintf ( NULL , 0 , L_7 , V_2 -> V_5 [ V_15 ] ) ;
if ( V_30 > V_28 )
V_28 = V_30 ;
}
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ ) {
V_30 = strlen ( V_2 -> V_11 [ V_26 ] ) ;
if ( V_30 > V_32 )
V_32 = V_30 ;
V_30 = snprintf ( NULL , 0 , L_8 V_35 , V_2 -> V_10 [ V_26 ] ) ;
if ( V_30 > V_33 )
V_33 = V_30 ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ ) {
V_30 = snprintf ( NULL , 0 , L_8 V_31 , V_2 -> V_6 [ V_15 ] [ V_26 ] ) ;
if ( V_30 > V_34 )
V_34 = V_30 ;
}
}
fprintf ( V_25 , L_16 ,
V_27 , L_10 , V_28 , L_11 ,
V_32 , L_17 , V_33 , L_18 ,
V_34 , L_19 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ )
for ( V_26 = 0 ; V_26 < V_2 -> V_13 ; V_26 ++ )
fprintf ( V_25 , L_20 V_35 L_15 V_31 ,
V_27 , V_2 -> V_4 [ V_15 ] ,
V_28 , V_2 -> V_5 [ V_15 ] ,
V_32 , V_2 -> V_11 [ V_26 ] ,
V_33 , V_2 -> V_10 [ V_26 ] ,
V_34 , V_2 -> V_6 [ V_15 ] [ V_26 ] ) ;
}
void F_14 ( T_3 * V_25 , struct V_1 * V_2 , int V_36 )
{
if ( V_36 )
F_13 ( V_25 , V_2 ) ;
else
F_12 ( V_25 , V_2 ) ;
}
