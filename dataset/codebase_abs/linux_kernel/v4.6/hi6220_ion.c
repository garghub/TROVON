static int F_1 ( const char * V_1 , enum V_2 * type )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( strncmp ( V_1 , V_4 [ V_3 ] . V_1 , strlen ( V_1 ) ) )
continue;
* type = V_4 [ V_3 ] . type ;
return 0 ;
}
return - V_5 ;
}
static int F_3 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
const char * V_11 ;
const char * V_12 ;
enum V_2 type ;
int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
const struct V_14 * V_18 = V_7 -> V_19 . V_20 ;
int V_21 = 0 ;
F_4 (dt_node, np)
V_22 ++ ;
V_23 = F_5 ( & V_7 -> V_19 ,
sizeof( struct V_16 * ) *
V_22 ,
V_24 ) ;
if ( ! V_23 )
return - V_25 ;
F_4 (dt_node, np) {
V_13 = F_6 ( V_15 , L_1 , & V_11 ) ;
if ( V_13 < 0 ) {
F_7 ( L_2 , V_15 -> V_1 ) ;
continue;
}
V_13 = F_8 ( V_15 , L_3 , & V_10 ) ;
if ( V_13 < 0 ) {
F_7 ( L_4 , V_15 -> V_1 ) ;
continue;
}
V_13 = F_8 ( V_15 , L_5 , & V_8 ) ;
if ( V_13 < 0 ) {
F_7 ( L_6 , V_15 -> V_1 ) ;
continue;
}
V_13 = F_8 ( V_15 , L_7 , & V_9 ) ;
if ( V_13 < 0 ) {
F_7 ( L_8 , V_15 -> V_1 ) ;
continue;
}
V_13 = F_6 ( V_15 , L_9 , & V_12 ) ;
if ( V_13 < 0 ) {
F_7 ( L_10 , V_15 -> V_1 ) ;
continue;
}
V_13 = F_1 ( V_12 , & type ) ;
if ( V_13 < 0 ) {
F_7 ( L_11 , V_12 ) ;
continue;
}
F_9 ( L_12 ,
V_21 , V_11 , V_8 , V_9 , V_10 , type ) ;
V_17 = F_5 ( & V_7 -> V_19 ,
sizeof( struct V_16 ) ,
V_24 ) ;
if ( ! V_17 )
return - V_25 ;
V_17 -> V_1 = V_11 ;
V_17 -> V_8 = V_8 ;
V_17 -> V_9 = V_9 ;
V_17 -> V_10 = V_10 ;
V_17 -> type = type ;
V_23 [ V_21 ] = V_17 ;
V_21 ++ ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
int V_3 ;
int V_26 ;
static struct V_16 * V_27 ;
V_28 = F_11 ( NULL ) ;
V_26 = F_3 ( V_7 ) ;
if ( V_26 ) {
F_7 ( L_13 ) ;
goto V_29;
}
V_30 = F_5 ( & V_7 -> V_19 ,
sizeof( struct V_31 * ) * V_22 ,
V_24 ) ;
if ( ! V_30 ) {
V_26 = - V_25 ;
goto V_29;
}
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
V_27 = V_23 [ V_3 ] ;
V_30 [ V_3 ] = F_12 ( V_27 ) ;
if ( F_13 ( V_30 [ V_3 ] ) ) {
V_26 = F_14 ( V_30 [ V_3 ] ) ;
goto V_32;
}
F_15 ( V_28 , V_30 [ V_3 ] ) ;
F_9 ( L_14 ,
V_33 , V_27 -> V_1 , V_27 -> type ,
V_27 -> V_8 , ( unsigned long ) V_27 -> V_9 ) ;
}
return V_26 ;
V_32:
for ( V_3 = 0 ; V_3 < V_22 ; ++ V_3 ) {
F_16 ( V_30 [ V_3 ] ) ;
V_30 [ V_3 ] = NULL ;
}
V_29:
F_17 ( V_28 ) ;
return V_26 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
F_16 ( V_30 [ V_3 ] ) ;
V_30 [ V_3 ] = NULL ;
}
F_17 ( V_28 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_34 ) ;
}
