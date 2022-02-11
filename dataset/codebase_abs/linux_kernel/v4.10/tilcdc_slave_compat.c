static int T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 32 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_3 * sizeof( * V_2 -> V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_5 )
return - V_7 ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 , void * V_8 )
{
if ( V_2 -> V_4 == V_2 -> V_3 ) {
void * * V_9 = V_2 -> V_5 ;
V_2 -> V_3 *= 2 ;
V_2 -> V_5 = F_4 ( V_9 , V_2 -> V_3 * sizeof( * V_2 -> V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = V_9 ;
F_5 ( V_8 ) ;
return - V_7 ;
}
}
V_2 -> V_5 [ V_2 -> V_4 ++ ] = V_8 ;
return 0 ;
}
static void T_1 F_6 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_4 ; V_10 ++ )
F_5 ( V_2 -> V_5 [ V_10 ] ) ;
F_5 ( V_2 -> V_5 ) ;
}
static
struct V_11 * T_1 F_7 ( const struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_11 * V_13 ;
V_13 = F_8 ( sizeof( * V_13 ) , V_6 ) ;
if ( ! V_13 || F_3 ( V_2 , V_13 ) )
return NULL ;
V_13 -> V_14 = F_9 ( V_12 -> V_14 , V_6 ) ;
if ( ! V_13 -> V_14 || F_3 ( V_2 , V_13 -> V_14 ) )
return NULL ;
V_13 -> V_15 = F_10 ( V_12 -> V_15 , V_12 -> V_16 , V_6 ) ;
if ( ! V_13 -> V_15 || F_3 ( V_2 , V_13 -> V_15 ) )
return NULL ;
V_13 -> V_16 = V_12 -> V_16 ;
return V_13 ;
}
static void T_1 F_11 ( struct V_17 * V_18 ,
struct V_17 * V_19 ,
const char * const V_20 [] ,
struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_10 ;
for ( V_10 = 0 ; V_20 [ V_10 ] ; V_10 ++ ) {
V_12 = F_12 ( V_18 , V_20 [ V_10 ] , NULL ) ;
if ( ! V_12 )
continue;
V_12 = F_7 ( V_12 , V_2 ) ;
if ( ! V_12 )
continue;
V_12 -> V_21 = V_19 -> V_22 ;
V_19 -> V_22 = V_12 ;
}
}
static int T_1 F_13 ( struct V_11 * V_12 ,
const char * V_23 ,
struct V_1 * V_2 )
{
V_12 -> V_15 = F_9 ( V_23 , V_6 ) ;
if ( F_3 ( V_2 , V_12 -> V_15 ) || ! V_12 -> V_15 )
return - V_7 ;
V_12 -> V_16 = strlen ( V_23 ) + 1 ;
return 0 ;
}
static void T_1 F_14 ( struct V_17 * V_24 )
{
struct V_11 * V_12 ;
V_12 = F_8 ( sizeof( * V_12 ) , V_6 ) ;
if ( ! V_12 )
return;
V_12 -> V_14 = L_1 ;
V_12 -> V_15 = L_2 ;
V_12 -> V_16 = strlen ( ( char * ) V_12 -> V_15 ) + 1 ;
F_15 ( V_24 , V_12 ) ;
}
static struct V_17 * T_1 F_16 ( struct V_1 * V_2 )
{
const int V_25 = V_26 -
V_27 ;
static void * V_28 ;
struct V_17 * V_29 ;
int V_30 ;
if ( ! V_25 ) {
F_17 ( L_3 , V_31 ) ;
return NULL ;
}
V_28 = F_10 ( V_27 ,
V_25 , V_6 ) ;
if ( ! V_28 || F_3 ( V_2 , V_28 ) )
return NULL ;
F_18 ( V_28 , NULL , & V_29 ) ;
if ( ! V_29 ) {
F_17 ( L_4 , V_31 ) ;
return NULL ;
}
F_19 ( V_29 , V_32 ) ;
V_30 = F_20 ( V_29 ) ;
if ( V_30 ) {
F_21 ( L_5 , V_31 , V_30 ) ;
return NULL ;
}
return V_29 ;
}
static void T_1 F_22 ( void )
{
struct V_17 * V_33 = NULL , * V_34 = NULL ;
struct V_17 * V_35 = NULL , * V_36 = NULL ;
struct V_17 * V_29 , * V_37 ;
struct V_11 * V_12 ;
struct V_1 V_2 ;
int V_30 ;
if ( F_1 ( & V_2 ) )
return;
V_34 = F_23 ( NULL , V_38 ) ;
V_33 = F_23 ( NULL , V_39 ) ;
if ( ! V_33 || ! F_24 ( V_34 ) )
goto V_40;
V_35 = F_25 ( V_33 , L_6 , 0 ) ;
if ( ! V_35 ) {
F_21 ( L_7 , V_31 ) ;
goto V_40;
}
V_29 = F_16 ( & V_2 ) ;
if ( ! V_29 )
goto V_40;
V_37 = F_23 ( V_29 , V_41 ) ;
if ( ! V_37 ) {
F_21 ( L_8 , V_31 ) ;
goto V_40;
}
F_11 ( V_33 , V_37 , V_42 , & V_2 ) ;
F_26 (overlay, fragment) {
V_12 = F_12 ( V_36 , L_9 , NULL ) ;
if ( ! V_12 )
continue;
if ( ! strncmp ( L_6 , ( char * ) V_12 -> V_15 , V_12 -> V_16 ) )
if ( F_13 ( V_12 , V_35 -> V_43 , & V_2 ) )
goto V_40;
if ( ! strncmp ( L_10 , ( char * ) V_12 -> V_15 , V_12 -> V_16 ) )
if ( F_13 ( V_12 , V_34 -> V_43 , & V_2 ) )
goto V_40;
}
F_14 ( V_33 ) ;
V_30 = F_27 ( V_29 ) ;
if ( V_30 )
F_21 ( L_11 , V_31 , V_30 ) ;
else
F_28 ( L_12 ,
V_31 ) ;
V_40:
F_6 ( & V_2 ) ;
F_29 ( V_35 ) ;
F_29 ( V_33 ) ;
F_29 ( V_34 ) ;
F_29 ( V_36 ) ;
}
static int T_1 F_30 ( void )
{
F_22 () ;
return 0 ;
}
