static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
T_1 V_8 = F_2 () ;
for ( V_7 = 0 ; V_7 < V_9 ; ++ V_7 )
if ( F_3 ( V_10 , V_8 ) [ V_7 ] == V_2 )
break;
if ( V_7 != V_9 )
F_4 ( V_6 , V_7 ) ;
else
F_5 ( L_1
L_2 , V_8 ) ;
}
static void F_6 ( void )
{
int V_11 ;
T_1 V_12 = sizeof( struct V_13 ) ;
struct V_13 * V_14 ;
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 ) {
V_14 = & V_15 [ V_11 ] . V_14 ;
memset ( V_14 , 0 , V_12 ) ;
V_14 -> type = V_16 ;
V_14 -> V_12 = V_12 ;
V_14 -> V_17 = V_15 [ V_11 ] . V_2 ;
V_14 -> V_18 = V_15 [ V_11 ] . V_19 ;
V_14 -> V_20 = 1 ;
}
}
static int F_7 ( int V_8 , int V_2 )
{
struct V_1 * V_21 ;
if ( ! V_15 [ V_2 ] . V_22 || F_3 ( V_10 , V_8 ) [ V_2 ] )
return 0 ;
V_21 = F_8 ( & V_15 [ V_2 ] . V_14 ,
V_8 , NULL ,
F_1 , NULL ) ;
if ( F_9 ( V_21 ) )
return F_10 ( V_21 ) ;
if ( V_21 -> V_23 != V_24 ) {
F_11 ( V_21 ) ;
F_5 ( L_3
L_4 , V_2 , V_8 ) ;
return - V_25 ;
}
F_3 ( V_10 , V_8 ) [ V_2 ] = V_21 ;
return 0 ;
}
static void F_12 ( int V_8 , int V_2 )
{
struct V_1 * V_21 = F_3 ( V_10 , V_8 ) [ V_2 ] ;
if ( V_21 ) {
F_11 ( V_21 ) ;
F_3 ( V_10 , V_8 ) [ V_2 ] = NULL ;
}
}
static int F_13 ( void )
{
int V_8 , V_2 , V_26 = 0 ;
F_14 (cpu) {
for ( V_2 = 0 ; V_2 < V_9 ; ++ V_2 ) {
V_26 = F_7 ( V_8 , V_2 ) ;
if ( V_26 )
return V_26 ;
}
}
return V_26 ;
}
static void F_15 ( void )
{
int V_8 , V_2 ;
F_14 (cpu)
for ( V_2 = 0 ; V_2 < V_9 ; ++ V_2 )
F_12 ( V_8 , V_2 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
struct V_27 * V_29 ;
char V_30 [ 4 ] ;
snprintf ( V_30 , sizeof V_30 , L_5 , V_11 ) ;
V_29 = F_17 ( V_28 , V_30 ) ;
F_18 ( V_29 , L_6 , & V_15 [ V_11 ] . V_22 ) ;
F_18 ( V_29 , L_7 , & V_15 [ V_11 ] . V_2 ) ;
F_18 ( V_29 , L_8 , & V_15 [ V_11 ] . V_19 ) ;
F_18 ( V_29 , L_9 , & V_15 [ V_11 ] . V_31 ) ;
F_18 ( V_29 , L_10 , & V_15 [ V_11 ] . V_32 ) ;
F_18 ( V_29 , L_11 , & V_15 [ V_11 ] . V_33 ) ;
}
return 0 ;
}
static int F_19 ( void )
{
F_20 ( & V_34 ) ;
F_6 () ;
F_21 ( & V_34 ) ;
return 0 ;
}
static int F_22 ( void )
{
int V_26 = - V_25 ;
F_23 ( & V_35 ) ;
if ( ! V_36 ) {
V_26 = 0 ;
F_13 () ;
V_36 = 1 ;
}
F_24 ( & V_35 ) ;
return V_26 ;
}
static void F_25 ( void )
{
F_23 ( & V_35 ) ;
if ( V_36 )
F_15 () ;
V_36 = 0 ;
F_24 ( & V_35 ) ;
}
static int F_26 ( struct V_37 * V_38 , T_2 V_23 )
{
F_23 ( & V_35 ) ;
if ( V_36 )
F_15 () ;
F_24 ( & V_35 ) ;
return 0 ;
}
static int F_27 ( struct V_37 * V_38 )
{
F_23 ( & V_35 ) ;
if ( V_36 && F_13 () )
V_36 = 0 ;
F_24 ( & V_35 ) ;
return 0 ;
}
static int T_3 F_28 ( void )
{
int V_26 ;
V_26 = F_29 ( & V_39 ) ;
if ( V_26 )
return V_26 ;
V_40 = F_30 (
V_39 . V_41 . V_42 , 0 , NULL , 0 ) ;
if ( F_9 ( V_40 ) ) {
V_26 = F_10 ( V_40 ) ;
F_31 ( & V_39 ) ;
}
return V_26 ;
}
static void F_32 ( void )
{
F_33 ( V_40 ) ;
F_31 ( & V_39 ) ;
}
static inline int F_28 ( void ) { return 0 ; }
static inline void F_32 ( void ) { }
void F_34 ( void )
{
int V_8 , V_7 ;
struct V_1 * V_2 ;
F_35 (cpu) {
for ( V_7 = 0 ; V_7 < V_9 ; ++ V_7 ) {
V_2 = F_3 ( V_10 , V_8 ) [ V_7 ] ;
if ( V_2 )
F_11 ( V_2 ) ;
}
F_36 ( F_3 ( V_10 , V_8 ) ) ;
}
F_36 ( V_15 ) ;
F_32 () ;
}
int T_3 F_37 ( struct V_43 * V_44 )
{
int V_8 , V_26 = 0 ;
V_26 = F_28 () ;
if ( V_26 )
return V_26 ;
V_9 = F_38 () ;
if ( V_9 <= 0 ) {
F_39 ( L_12 ) ;
V_26 = - V_45 ;
goto V_46;
}
V_15 = F_40 ( V_9 ,
sizeof( struct V_47 ) , V_48 ) ;
if ( ! V_15 ) {
F_39 ( L_13
L_14 , V_9 ) ;
V_26 = - V_49 ;
V_9 = 0 ;
goto V_46;
}
F_35 (cpu) {
F_3 ( V_10 , V_8 ) = F_40 ( V_9 ,
sizeof( struct V_1 * ) , V_48 ) ;
if ( ! F_3 ( V_10 , V_8 ) ) {
F_39 ( L_15
L_16 , V_9 , V_8 ) ;
V_26 = - V_49 ;
goto V_46;
}
}
V_44 -> V_50 = F_16 ;
V_44 -> V_51 = F_19 ;
V_44 -> V_52 = F_22 ;
V_44 -> V_53 = F_25 ;
V_44 -> V_54 = F_25 ;
V_44 -> V_55 = F_41 () ;
if ( ! V_44 -> V_55 )
V_26 = - V_45 ;
else
F_39 ( L_17 , V_44 -> V_55 ) ;
V_46:
if ( V_26 )
F_34 () ;
return V_26 ;
}
