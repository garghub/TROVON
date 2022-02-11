static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
T_1 V_8 = F_2 () ;
for ( V_7 = 0 ; V_7 < V_9 ; ++ V_7 )
if ( V_10 [ V_8 ] [ V_7 ] == V_2 )
break;
if ( V_7 != V_9 )
F_3 ( V_6 , V_7 ) ;
else
F_4 ( L_1
L_2 , V_8 ) ;
}
static void F_5 ( void )
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
static int F_6 ( int V_8 , int V_2 )
{
struct V_1 * V_21 ;
if ( ! V_15 [ V_2 ] . V_22 || V_10 [ V_8 ] [ V_2 ] )
return 0 ;
V_21 = F_7 ( & V_15 [ V_2 ] . V_14 ,
V_8 , NULL ,
F_1 , NULL ) ;
if ( F_8 ( V_21 ) )
return F_9 ( V_21 ) ;
if ( V_21 -> V_23 != V_24 ) {
F_10 ( V_21 ) ;
F_4 ( L_3
L_4 , V_2 , V_8 ) ;
return - V_25 ;
}
V_10 [ V_8 ] [ V_2 ] = V_21 ;
return 0 ;
}
static void F_11 ( int V_8 , int V_2 )
{
struct V_1 * V_21 = V_10 [ V_8 ] [ V_2 ] ;
if ( V_21 ) {
F_10 ( V_21 ) ;
V_10 [ V_8 ] [ V_2 ] = NULL ;
}
}
static int F_12 ( void )
{
int V_8 , V_2 , V_26 = 0 ;
F_13 (cpu) {
for ( V_2 = 0 ; V_2 < V_9 ; ++ V_2 ) {
V_26 = F_6 ( V_8 , V_2 ) ;
if ( V_26 )
return V_26 ;
}
}
return V_26 ;
}
static void F_14 ( void )
{
int V_8 , V_2 ;
F_13 (cpu)
for ( V_2 = 0 ; V_2 < V_9 ; ++ V_2 )
F_11 ( V_8 , V_2 ) ;
}
static int F_15 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
struct V_29 * V_31 ;
char V_32 [ 4 ] ;
snprintf ( V_32 , sizeof V_32 , L_5 , V_11 ) ;
V_31 = F_16 ( V_28 , V_30 , V_32 ) ;
F_17 ( V_28 , V_31 , L_6 , & V_15 [ V_11 ] . V_22 ) ;
F_17 ( V_28 , V_31 , L_7 , & V_15 [ V_11 ] . V_2 ) ;
F_17 ( V_28 , V_31 , L_8 , & V_15 [ V_11 ] . V_19 ) ;
F_17 ( V_28 , V_31 , L_9 , & V_15 [ V_11 ] . V_33 ) ;
F_17 ( V_28 , V_31 , L_10 , & V_15 [ V_11 ] . V_34 ) ;
F_17 ( V_28 , V_31 , L_11 , & V_15 [ V_11 ] . V_35 ) ;
}
return 0 ;
}
static int F_18 ( void )
{
F_19 ( & V_36 ) ;
F_5 () ;
F_20 ( & V_36 ) ;
return 0 ;
}
static int F_21 ( void )
{
int V_26 = - V_25 ;
F_22 ( & V_37 ) ;
if ( ! V_38 ) {
V_26 = 0 ;
F_12 () ;
V_38 = 1 ;
}
F_23 ( & V_37 ) ;
return V_26 ;
}
static void F_24 ( void )
{
F_22 ( & V_37 ) ;
if ( V_38 )
F_14 () ;
V_38 = 0 ;
F_23 ( & V_37 ) ;
}
static int F_25 ( struct V_39 * V_40 , T_2 V_23 )
{
F_22 ( & V_37 ) ;
if ( V_38 )
F_14 () ;
F_23 ( & V_37 ) ;
return 0 ;
}
static int F_26 ( struct V_39 * V_40 )
{
F_22 ( & V_37 ) ;
if ( V_38 && F_12 () )
V_38 = 0 ;
F_23 ( & V_37 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
int V_26 ;
V_26 = F_28 ( & V_41 ) ;
if ( V_26 )
return V_26 ;
V_42 = F_29 (
V_41 . V_43 . V_44 , 0 , NULL , 0 ) ;
if ( F_8 ( V_42 ) ) {
V_26 = F_9 ( V_42 ) ;
F_30 ( & V_41 ) ;
}
return V_26 ;
}
static void F_31 ( void )
{
F_32 ( V_42 ) ;
F_30 ( & V_41 ) ;
}
static inline int F_27 ( void ) { return 0 ; }
static inline void F_31 ( void ) { }
void F_33 ( void )
{
int V_8 , V_7 ;
struct V_1 * V_2 ;
F_34 (cpu) {
for ( V_7 = 0 ; V_7 < V_9 ; ++ V_7 ) {
V_2 = V_10 [ V_8 ] [ V_7 ] ;
if ( V_2 )
F_10 ( V_2 ) ;
}
F_35 ( V_10 [ V_8 ] ) ;
}
F_35 ( V_15 ) ;
F_31 () ;
}
int T_3 F_36 ( struct V_45 * V_46 )
{
int V_8 , V_26 = 0 ;
V_26 = F_27 () ;
if ( V_26 )
return V_26 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_9 = F_37 () ;
if ( V_9 <= 0 ) {
F_38 ( L_12 ) ;
V_26 = - V_47 ;
goto V_48;
}
V_15 = F_39 ( V_9 ,
sizeof( struct V_49 ) , V_50 ) ;
if ( ! V_15 ) {
F_38 ( L_13
L_14 , V_9 ) ;
V_26 = - V_51 ;
V_9 = 0 ;
goto V_48;
}
F_34 (cpu) {
V_10 [ V_8 ] = F_39 ( V_9 ,
sizeof( struct V_1 * ) , V_50 ) ;
if ( ! V_10 [ V_8 ] ) {
F_38 ( L_15
L_16 , V_9 , V_8 ) ;
V_26 = - V_51 ;
goto V_48;
}
}
V_46 -> V_52 = F_15 ;
V_46 -> V_53 = F_18 ;
V_46 -> V_54 = F_21 ;
V_46 -> V_55 = F_24 ;
V_46 -> V_56 = F_24 ;
V_46 -> V_57 = F_40 () ;
if ( ! V_46 -> V_57 )
V_26 = - V_47 ;
else
F_38 ( L_17 , V_46 -> V_57 ) ;
V_48:
if ( V_26 )
F_33 () ;
return V_26 ;
}
