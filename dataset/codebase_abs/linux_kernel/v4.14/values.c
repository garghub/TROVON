int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 16 ;
V_2 -> V_4 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_4 ) ) ;
V_2 -> V_5 = malloc ( V_2 -> V_3 * sizeof( * V_2 -> V_5 ) ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_3 * sizeof( * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_5 || ! V_2 -> V_6 ) {
F_3 ( L_1 ) ;
goto V_7;
}
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 16 ;
V_2 -> V_10 = malloc ( V_2 -> V_9
* sizeof( * V_2 -> V_10 ) ) ;
V_2 -> V_11 = malloc ( V_2 -> V_9
* sizeof( * V_2 -> V_11 ) ) ;
if ( ! V_2 -> V_10 || ! V_2 -> V_11 ) {
F_3 ( L_2 ) ;
goto V_12;
}
V_2 -> V_13 = 0 ;
return 0 ;
V_12:
F_4 ( & V_2 -> V_10 ) ;
F_4 ( & V_2 -> V_11 ) ;
V_7:
F_4 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
return - V_14 ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_15 ;
if ( ! V_2 -> V_3 || ! V_2 -> V_9 )
return;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ )
F_4 ( & V_2 -> V_6 [ V_15 ] ) ;
F_4 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_10 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_13 ; V_15 ++ )
F_4 ( & V_2 -> V_11 [ V_15 ] ) ;
F_4 ( & V_2 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
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
F_3 ( L_3 ) ;
return - V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_4 , T_1 V_5 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ )
if ( V_2 -> V_4 [ V_15 ] == V_4 && V_2 -> V_5 [ V_15 ] == V_5 )
return V_15 ;
if ( V_2 -> V_8 == V_2 -> V_3 ) {
V_15 = F_6 ( V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_15 = V_2 -> V_8 ;
V_2 -> V_6 [ V_15 ] = F_2 ( V_2 -> V_9 * sizeof( * * V_2 -> V_6 ) ) ;
if ( ! V_2 -> V_6 [ V_15 ] ) {
F_3 ( L_4 ) ;
return - V_14 ;
}
V_2 -> V_4 [ V_15 ] = V_4 ;
V_2 -> V_5 [ V_15 ] = V_5 ;
V_2 -> V_8 = V_15 + 1 ;
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 )
{
char * * V_11 ;
int V_15 , V_9 = V_2 -> V_9 * 2 ;
T_2 * V_10 = realloc ( V_2 -> V_10 , V_9 * sizeof( * V_2 -> V_10 ) ) ;
if ( ! V_10 ) {
F_3 ( L_5 ) ;
goto V_21;
}
V_11 = realloc ( V_2 -> V_11 , V_9 * sizeof( * V_2 -> V_11 ) ) ;
if ( ! V_11 ) {
F_3 ( L_5 ) ;
goto V_22;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
T_2 * V_6 = realloc ( V_2 -> V_6 [ V_15 ] , V_9 * sizeof( * * V_2 -> V_6 ) ) ;
int V_23 ;
if ( ! V_6 ) {
F_3 ( L_6 ) ;
goto V_24;
}
for ( V_23 = V_2 -> V_9 ; V_23 < V_9 ; V_23 ++ )
V_6 [ V_23 ] = 0 ;
V_2 -> V_6 [ V_15 ] = V_6 ;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
return 0 ;
V_24:
free ( V_11 ) ;
V_22:
free ( V_10 ) ;
V_21:
return - V_14 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 V_25 , const char * V_26 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_13 ; V_15 ++ )
if ( V_2 -> V_10 [ V_15 ] == V_25 )
return V_15 ;
if ( V_2 -> V_13 == V_2 -> V_9 ) {
V_15 = F_8 ( V_2 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = V_2 -> V_13 ++ ;
V_2 -> V_10 [ V_15 ] = V_25 ;
V_2 -> V_11 [ V_15 ] = F_10 ( V_26 ) ;
return V_15 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_4 , T_1 V_5 ,
T_2 V_25 , const char * V_26 , T_2 V_6 )
{
int V_27 , V_28 ;
V_27 = F_7 ( V_2 , V_4 , V_5 ) ;
if ( V_27 < 0 )
return V_27 ;
V_28 = F_9 ( V_2 , V_25 , V_26 ) ;
if ( V_28 < 0 )
return V_28 ;
V_2 -> V_6 [ V_27 ] [ V_28 ] += V_6 ;
return 0 ;
}
static void F_12 ( T_3 * V_29 ,
struct V_1 * V_2 )
{
int V_15 , V_23 ;
int V_30 , V_31 ;
int * V_32 ;
V_32 = malloc ( V_2 -> V_13 * sizeof( * V_32 ) ) ;
if ( ! V_32 ) {
fprintf ( V_29 , L_7 ) ;
return;
}
V_31 = 3 ;
V_30 = 3 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ )
V_32 [ V_23 ] = strlen ( V_2 -> V_11 [ V_23 ] ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
int V_33 ;
V_33 = snprintf ( NULL , 0 , L_8 , V_2 -> V_4 [ V_15 ] ) ;
if ( V_33 > V_30 )
V_30 = V_33 ;
V_33 = snprintf ( NULL , 0 , L_8 , V_2 -> V_5 [ V_15 ] ) ;
if ( V_33 > V_31 )
V_31 = V_33 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ ) {
V_33 = snprintf ( NULL , 0 , L_9 V_34 , V_2 -> V_6 [ V_15 ] [ V_23 ] ) ;
if ( V_33 > V_32 [ V_23 ] )
V_32 [ V_23 ] = V_33 ;
}
}
fprintf ( V_29 , L_10 , V_30 , L_11 , V_31 , L_12 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ )
fprintf ( V_29 , L_13 , V_32 [ V_23 ] , V_2 -> V_11 [ V_23 ] ) ;
fprintf ( V_29 , L_14 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
fprintf ( V_29 , L_15 , V_30 , V_2 -> V_4 [ V_15 ] ,
V_31 , V_2 -> V_5 [ V_15 ] ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ )
fprintf ( V_29 , L_16 V_34 ,
V_32 [ V_23 ] , V_2 -> V_6 [ V_15 ] [ V_23 ] ) ;
fprintf ( V_29 , L_14 ) ;
}
free ( V_32 ) ;
}
static void F_13 ( T_3 * V_29 ,
struct V_1 * V_2 )
{
int V_33 , V_30 , V_31 , V_35 , V_36 , V_37 ;
int V_15 , V_23 ;
V_31 = 3 ;
V_30 = 3 ;
V_35 = 4 ;
V_36 = 3 ;
V_37 = 5 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
V_33 = snprintf ( NULL , 0 , L_8 , V_2 -> V_4 [ V_15 ] ) ;
if ( V_33 > V_30 )
V_30 = V_33 ;
V_33 = snprintf ( NULL , 0 , L_8 , V_2 -> V_5 [ V_15 ] ) ;
if ( V_33 > V_31 )
V_31 = V_33 ;
}
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ ) {
V_33 = strlen ( V_2 -> V_11 [ V_23 ] ) ;
if ( V_33 > V_35 )
V_35 = V_33 ;
V_33 = snprintf ( NULL , 0 , L_9 V_38 , V_2 -> V_10 [ V_23 ] ) ;
if ( V_33 > V_36 )
V_36 = V_33 ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ ) {
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ ) {
V_33 = snprintf ( NULL , 0 , L_9 V_34 , V_2 -> V_6 [ V_15 ] [ V_23 ] ) ;
if ( V_33 > V_37 )
V_37 = V_33 ;
}
}
fprintf ( V_29 , L_17 ,
V_30 , L_11 , V_31 , L_12 ,
V_35 , L_18 , V_36 , L_19 ,
V_37 , L_20 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_8 ; V_15 ++ )
for ( V_23 = 0 ; V_23 < V_2 -> V_13 ; V_23 ++ )
fprintf ( V_29 , L_21 V_38 L_16 V_34 ,
V_30 , V_2 -> V_4 [ V_15 ] ,
V_31 , V_2 -> V_5 [ V_15 ] ,
V_35 , V_2 -> V_11 [ V_23 ] ,
V_36 , V_2 -> V_10 [ V_23 ] ,
V_37 , V_2 -> V_6 [ V_15 ] [ V_23 ] ) ;
}
void F_14 ( T_3 * V_29 , struct V_1 * V_2 , int V_39 )
{
if ( V_39 )
F_13 ( V_29 , V_2 ) ;
else
F_12 ( V_29 , V_2 ) ;
}
