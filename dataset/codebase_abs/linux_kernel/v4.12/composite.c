static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return V_4 . V_5 ( V_2 , V_3 ) ;
}
static long F_2 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long * V_7 )
{
return - V_8 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
return - V_8 ;
}
static struct V_9 * F_4 ( struct V_9 * V_10 , int V_11 )
{
int V_12 ;
struct V_13 V_14 ;
V_12 = F_5 ( V_10 , L_1 , L_2 , V_11 ,
& V_14 ) ;
if ( V_12 )
return NULL ;
return V_14 . V_15 ;
}
static struct V_16 * F_6 ( struct V_9 * V_10 )
{
struct V_16 * V_17 ;
F_7 (comp, &component_clks, link) {
if ( V_17 -> V_10 == V_10 )
return V_17 ;
}
return NULL ;
}
static inline struct V_1 * F_8 ( struct V_18 * V_19 , int V_20 )
{
if ( ! V_19 )
return NULL ;
if ( ! V_19 -> V_21 [ V_20 ] )
return NULL ;
return V_19 -> V_21 [ V_20 ] -> V_2 ;
}
struct V_19 * F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_17 ;
struct V_1 * V_25 ;
struct V_1 * V_26 ;
struct V_1 * div ;
int V_27 = 1 ;
const char * const * V_28 = NULL ;
struct V_19 * V_19 ;
int V_29 ;
V_17 = V_23 -> V_30 ;
div = F_10 ( V_17 -> V_31 ) ;
V_25 = F_11 ( V_17 -> V_25 ) ;
V_26 = F_12 ( V_17 -> V_26 ) ;
if ( div )
V_28 = & V_17 -> V_31 -> V_32 ;
if ( V_25 )
V_28 = & V_17 -> V_25 -> V_32 ;
if ( V_26 ) {
V_27 = V_17 -> V_26 -> V_27 ;
V_28 = V_17 -> V_26 -> V_33 ;
}
V_19 = F_13 ( NULL , V_23 -> V_34 ,
V_28 , V_27 , V_26 ,
& V_35 , div ,
& V_36 , V_25 ,
& V_37 , 0 ) ;
V_29 = F_14 ( NULL , V_19 , V_23 -> V_34 ) ;
if ( V_29 ) {
F_15 ( V_19 ) ;
return F_16 ( V_29 ) ;
}
return V_19 ;
}
static void T_1 F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_19 * V_19 ;
struct V_18 * V_38 = F_18 ( V_2 ) ;
struct V_16 * V_17 ;
int V_27 = 0 ;
const char * * V_28 = NULL ;
int V_11 ;
int V_29 ;
for ( V_11 = 0 ; V_11 < V_39 ; V_11 ++ ) {
if ( ! V_38 -> V_40 [ V_11 ] )
continue;
V_17 = F_6 ( V_38 -> V_40 [ V_11 ] ) ;
if ( ! V_17 ) {
F_19 ( L_3 ,
V_38 -> V_40 [ V_11 ] -> V_34 , V_10 -> V_34 ) ;
if ( ! F_20 ( V_10 , V_2 ,
F_17 ) )
return;
goto V_41;
}
if ( V_38 -> V_21 [ V_17 -> type ] != NULL ) {
F_21 ( L_4 ,
V_10 -> V_34 , V_42 [ V_17 -> type ] ) ;
goto V_41;
}
V_38 -> V_21 [ V_17 -> type ] = V_17 ;
V_38 -> V_40 [ V_11 ] = NULL ;
}
for ( V_11 = V_39 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_17 = V_38 -> V_21 [ V_11 ] ;
if ( ! V_17 )
continue;
if ( V_17 -> V_27 ) {
V_27 = V_17 -> V_27 ;
V_28 = V_17 -> V_28 ;
break;
}
}
if ( ! V_27 ) {
F_21 ( L_5 , V_43 , V_10 -> V_34 ) ;
goto V_41;
}
V_19 = F_13 ( NULL , V_10 -> V_34 ,
V_28 , V_27 ,
F_8 ( V_38 , V_44 ) ,
& V_35 ,
F_8 ( V_38 , V_45 ) ,
& V_36 ,
F_8 ( V_38 , V_46 ) ,
& V_37 , 0 ) ;
if ( ! F_22 ( V_19 ) ) {
V_29 = F_14 ( NULL , V_19 , V_10 -> V_34 ) ;
if ( V_29 ) {
F_15 ( V_19 ) ;
goto V_41;
}
F_23 ( V_10 , V_47 , V_19 ) ;
}
V_41:
for ( V_11 = 0 ; V_11 < V_39 ; V_11 ++ ) {
if ( ! V_38 -> V_21 [ V_11 ] )
continue;
F_24 ( & V_38 -> V_21 [ V_11 ] -> V_48 ) ;
F_25 ( V_38 -> V_21 [ V_11 ] ) ;
}
F_25 ( V_38 ) ;
}
static void T_1 F_26 ( struct V_9 * V_10 )
{
unsigned int V_49 ;
int V_11 ;
struct V_18 * V_38 ;
V_49 = F_27 ( V_10 ) ;
if ( ! V_49 ) {
F_21 ( L_6 , V_10 -> V_34 ) ;
return;
}
V_38 = F_28 ( sizeof( * V_38 ) , V_50 ) ;
if ( ! V_38 )
return;
for ( V_11 = 0 ; V_11 < V_49 ; V_11 ++ )
V_38 -> V_40 [ V_11 ] = F_4 ( V_10 , V_11 ) ;
F_17 ( & V_38 -> V_2 , V_10 ) ;
}
int T_1 F_29 ( struct V_9 * V_10 , struct V_1 * V_2 ,
int type )
{
unsigned int V_27 ;
const char * * V_28 ;
struct V_16 * V_19 ;
V_27 = F_27 ( V_10 ) ;
if ( ! V_27 ) {
F_21 ( L_7 , V_10 -> V_34 ) ;
return - V_8 ;
}
V_28 = F_28 ( ( sizeof( char * ) * V_27 ) , V_50 ) ;
if ( ! V_28 )
return - V_51 ;
F_30 ( V_10 , V_28 , V_27 ) ;
V_19 = F_28 ( sizeof( * V_19 ) , V_50 ) ;
if ( ! V_19 ) {
F_25 ( V_28 ) ;
return - V_51 ;
}
V_19 -> V_27 = V_27 ;
V_19 -> V_28 = V_28 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_10 = V_10 ;
V_19 -> type = type ;
F_31 ( & V_19 -> V_48 , & V_52 ) ;
return 0 ;
}
