static int T_1 F_1 ( const struct V_1 * V_2 )
{
const char * V_3 = V_2 -> V_4 ;
int V_5 = 0 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_6 < V_2 -> V_8 ; V_6 += V_5 , V_3 += V_5 , V_7 ++ )
V_5 = strlen ( V_3 ) + 1 ;
return V_7 ;
}
static void T_1 F_2 ( struct V_9 * V_10 , char * V_11 ,
int V_12 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return;
V_2 -> V_14 = L_1 ;
V_2 -> V_4 = V_11 ;
V_2 -> V_8 = V_12 ;
F_4 ( V_10 , V_2 ) ;
}
static void T_1 F_5 ( char * V_15 , int V_16 ,
const char * V_17 , int V_18 )
{
T_2 V_6 = 0 ;
while ( V_6 < V_18 ) {
T_2 V_5 = strlen ( V_17 ) + 1 ;
strcpy ( V_15 , V_19 ) ;
V_15 += strlen ( V_19 ) ;
strcpy ( V_15 , V_17 ) ;
V_15 += V_5 ;
V_17 += V_5 ;
V_6 += V_5 ;
}
}
static void T_1 F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
char * V_20 ;
int V_21 ;
int V_22 ;
V_2 = F_7 ( V_10 , L_1 , NULL ) ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
if ( F_8 ( V_2 -> V_4 , V_2 -> V_8 ) >= V_2 -> V_8 )
return;
if ( strncmp ( V_19 , V_2 -> V_4 , strlen ( V_19 ) ) == 0 )
return;
V_21 = F_1 ( V_2 ) ;
V_22 = V_2 -> V_8 + strlen ( V_19 ) * V_21 ;
V_20 = F_9 ( V_22 , V_13 ) ;
F_5 ( V_20 , V_22 , V_2 -> V_4 , V_2 -> V_8 ) ;
F_2 ( V_10 , V_20 , V_22 ) ;
}
static void T_1 F_10 ( struct V_9 * V_10 , bool V_23 )
{
struct V_24 * V_25 = F_9 ( sizeof( struct V_24 ) ,
V_13 ) ;
if ( V_25 ) {
V_25 -> V_10 = V_10 ;
V_25 -> V_23 = V_23 ;
F_11 ( & V_25 -> V_26 , & V_27 ) ;
}
}
static bool T_1 F_12 ( const struct V_9 * V_10 )
{
struct V_24 * V_25 ;
F_13 (n, &dss_conv_list, list) {
if ( V_25 -> V_10 == V_10 )
return true ;
}
return false ;
}
static void T_1 F_14 ( struct V_9 * V_10 , bool V_23 )
{
struct V_9 * V_25 ;
F_10 ( V_10 , V_23 ) ;
V_25 = F_15 ( V_10 , L_2 ) ;
if ( ! V_25 )
V_25 = F_15 ( V_10 , L_3 ) ;
if ( ! V_25 )
return;
F_16 ( V_25 ) ;
V_25 = NULL ;
while ( ( V_25 = F_17 ( V_10 , V_25 ) ) != NULL ) {
struct V_9 * V_28 ;
V_28 = F_18 ( V_25 ) ;
if ( ! V_28 ) {
F_16 ( V_25 ) ;
continue;
}
if ( ! F_19 ( V_28 ) || F_12 ( V_28 ) ) {
F_16 ( V_28 ) ;
F_16 ( V_25 ) ;
continue;
}
F_14 ( V_28 , false ) ;
F_16 ( V_25 ) ;
}
}
static int T_1 F_20 ( void )
{
struct V_9 * V_29 , * V_30 ;
F_21 ( & V_27 ) ;
V_29 = F_22 ( NULL , V_31 ) ;
if ( V_29 == NULL || ! F_19 ( V_29 ) )
return 0 ;
F_14 ( V_29 , true ) ;
F_23 (dss, child) {
if ( ! F_7 ( V_30 , L_1 , NULL ) ) {
F_16 ( V_30 ) ;
continue;
}
F_14 ( V_30 , true ) ;
}
while ( ! F_24 ( & V_27 ) ) {
struct V_24 * V_25 ;
V_25 = F_25 ( & V_27 , struct V_24 ,
V_26 ) ;
if ( ! V_25 -> V_23 )
F_6 ( V_25 -> V_10 ) ;
F_26 ( & V_25 -> V_26 ) ;
F_16 ( V_25 -> V_10 ) ;
F_27 ( V_25 ) ;
}
return 0 ;
}
