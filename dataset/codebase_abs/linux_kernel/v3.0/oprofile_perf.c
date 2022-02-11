static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_8 ;
T_1 V_9 = F_2 () ;
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 )
if ( V_11 [ V_9 ] [ V_8 ] == V_2 )
break;
if ( V_8 != V_10 )
F_3 ( V_7 , V_8 ) ;
else
F_4 ( L_1
L_2 , V_9 ) ;
}
static void F_5 ( void )
{
int V_12 ;
T_1 V_13 = sizeof( struct V_14 ) ;
struct V_14 * V_15 ;
for ( V_12 = 0 ; V_12 < V_10 ; ++ V_12 ) {
V_15 = & V_16 [ V_12 ] . V_15 ;
memset ( V_15 , 0 , V_13 ) ;
V_15 -> type = V_17 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_18 = V_16 [ V_12 ] . V_2 ;
V_15 -> V_19 = V_16 [ V_12 ] . V_20 ;
V_15 -> V_21 = 1 ;
}
}
static int F_6 ( int V_9 , int V_2 )
{
struct V_1 * V_22 ;
if ( ! V_16 [ V_2 ] . V_23 || V_11 [ V_9 ] [ V_2 ] )
return 0 ;
V_22 = F_7 ( & V_16 [ V_2 ] . V_15 ,
V_9 , NULL ,
F_1 ) ;
if ( F_8 ( V_22 ) )
return F_9 ( V_22 ) ;
if ( V_22 -> V_24 != V_25 ) {
F_10 ( V_22 ) ;
F_4 ( L_3
L_4 , V_2 , V_9 ) ;
return - V_26 ;
}
V_11 [ V_9 ] [ V_2 ] = V_22 ;
return 0 ;
}
static void F_11 ( int V_9 , int V_2 )
{
struct V_1 * V_22 = V_11 [ V_9 ] [ V_2 ] ;
if ( V_22 ) {
F_10 ( V_22 ) ;
V_11 [ V_9 ] [ V_2 ] = NULL ;
}
}
static int F_12 ( void )
{
int V_9 , V_2 , V_27 = 0 ;
F_13 (cpu) {
for ( V_2 = 0 ; V_2 < V_10 ; ++ V_2 ) {
V_27 = F_6 ( V_9 , V_2 ) ;
if ( V_27 )
return V_27 ;
}
}
return V_27 ;
}
static void F_14 ( void )
{
int V_9 , V_2 ;
F_13 (cpu)
for ( V_2 = 0 ; V_2 < V_10 ; ++ V_2 )
F_11 ( V_9 , V_2 ) ;
}
static int F_15 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ ) {
struct V_30 * V_32 ;
char V_33 [ 4 ] ;
snprintf ( V_33 , sizeof V_33 , L_5 , V_12 ) ;
V_32 = F_16 ( V_29 , V_31 , V_33 ) ;
F_17 ( V_29 , V_32 , L_6 , & V_16 [ V_12 ] . V_23 ) ;
F_17 ( V_29 , V_32 , L_7 , & V_16 [ V_12 ] . V_2 ) ;
F_17 ( V_29 , V_32 , L_8 , & V_16 [ V_12 ] . V_20 ) ;
F_17 ( V_29 , V_32 , L_9 , & V_16 [ V_12 ] . V_34 ) ;
F_17 ( V_29 , V_32 , L_10 , & V_16 [ V_12 ] . V_35 ) ;
F_17 ( V_29 , V_32 , L_11 , & V_16 [ V_12 ] . V_36 ) ;
}
return 0 ;
}
static int F_18 ( void )
{
F_19 ( & V_37 ) ;
F_5 () ;
F_20 ( & V_37 ) ;
return 0 ;
}
static int F_21 ( void )
{
int V_27 = - V_26 ;
F_22 ( & V_38 ) ;
if ( ! V_39 ) {
V_27 = 0 ;
F_12 () ;
V_39 = 1 ;
}
F_23 ( & V_38 ) ;
return V_27 ;
}
static void F_24 ( void )
{
F_22 ( & V_38 ) ;
if ( V_39 )
F_14 () ;
V_39 = 0 ;
F_23 ( & V_38 ) ;
}
static int F_25 ( struct V_40 * V_41 , T_2 V_24 )
{
F_22 ( & V_38 ) ;
if ( V_39 )
F_14 () ;
F_23 ( & V_38 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 )
{
F_22 ( & V_38 ) ;
if ( V_39 && F_12 () )
V_39 = 0 ;
F_23 ( & V_38 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
int V_27 ;
V_27 = F_28 ( & V_42 ) ;
if ( V_27 )
return V_27 ;
V_43 = F_29 (
V_42 . V_44 . V_45 , 0 , NULL , 0 ) ;
if ( F_8 ( V_43 ) ) {
V_27 = F_9 ( V_43 ) ;
F_30 ( & V_42 ) ;
}
return V_27 ;
}
static void F_31 ( void )
{
F_32 ( V_43 ) ;
F_30 ( & V_42 ) ;
}
static inline int F_27 ( void ) { return 0 ; }
static inline void F_31 ( void ) { }
void F_33 ( void )
{
int V_9 , V_8 ;
struct V_1 * V_2 ;
F_34 (cpu) {
for ( V_8 = 0 ; V_8 < V_10 ; ++ V_8 ) {
V_2 = V_11 [ V_9 ] [ V_8 ] ;
if ( V_2 )
F_10 ( V_2 ) ;
}
F_35 ( V_11 [ V_9 ] ) ;
}
F_35 ( V_16 ) ;
F_31 () ;
}
int T_3 F_36 ( struct V_46 * V_47 )
{
int V_9 , V_27 = 0 ;
V_27 = F_27 () ;
if ( V_27 )
return V_27 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_10 = F_37 () ;
if ( V_10 <= 0 ) {
F_38 ( L_12 ) ;
V_27 = - V_48 ;
goto V_49;
}
V_16 = F_39 ( V_10 ,
sizeof( struct V_50 ) , V_51 ) ;
if ( ! V_16 ) {
F_38 ( L_13
L_14 , V_10 ) ;
V_27 = - V_52 ;
V_10 = 0 ;
goto V_49;
}
F_34 (cpu) {
V_11 [ V_9 ] = F_39 ( V_10 ,
sizeof( struct V_1 * ) , V_51 ) ;
if ( ! V_11 [ V_9 ] ) {
F_38 ( L_15
L_16 , V_10 , V_9 ) ;
V_27 = - V_52 ;
goto V_49;
}
}
V_47 -> V_53 = F_15 ;
V_47 -> V_54 = F_18 ;
V_47 -> V_55 = F_21 ;
V_47 -> V_56 = F_24 ;
V_47 -> V_57 = F_24 ;
V_47 -> V_58 = F_40 () ;
if ( ! V_47 -> V_58 )
V_27 = - V_48 ;
else
F_38 ( L_17 , V_47 -> V_58 ) ;
V_49:
if ( V_27 )
F_33 () ;
return V_27 ;
}
