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
static void T_1 F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_19 * V_19 ;
struct V_18 * V_22 = F_10 ( V_2 ) ;
struct V_16 * V_17 ;
int V_23 = 0 ;
const char * * V_24 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
if ( ! V_22 -> V_26 [ V_11 ] )
continue;
V_17 = F_6 ( V_22 -> V_26 [ V_11 ] ) ;
if ( ! V_17 ) {
F_11 ( L_3 ,
V_22 -> V_26 [ V_11 ] -> V_27 , V_10 -> V_27 ) ;
if ( ! F_12 ( V_10 , V_2 ,
F_9 ) )
return;
goto V_28;
}
if ( V_22 -> V_21 [ V_17 -> type ] != NULL ) {
F_13 ( L_4 ,
V_10 -> V_27 , V_29 [ V_17 -> type ] ) ;
goto V_28;
}
V_22 -> V_21 [ V_17 -> type ] = V_17 ;
V_22 -> V_26 [ V_11 ] = NULL ;
}
for ( V_11 = V_25 - 1 ; V_11 >= 0 ; V_11 -- ) {
V_17 = V_22 -> V_21 [ V_11 ] ;
if ( ! V_17 )
continue;
if ( V_17 -> V_23 ) {
V_23 = V_17 -> V_23 ;
V_24 = V_17 -> V_24 ;
break;
}
}
if ( ! V_23 ) {
F_13 ( L_5 , V_30 , V_10 -> V_27 ) ;
goto V_28;
}
V_19 = F_14 ( NULL , V_10 -> V_27 ,
V_24 , V_23 ,
F_8 ( V_22 , V_31 ) ,
& V_32 ,
F_8 ( V_22 , V_33 ) ,
& V_34 ,
F_8 ( V_22 , V_35 ) ,
& V_36 , 0 ) ;
if ( ! F_15 ( V_19 ) )
F_16 ( V_10 , V_37 , V_19 ) ;
V_28:
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
if ( ! V_22 -> V_21 [ V_11 ] )
continue;
F_17 ( & V_22 -> V_21 [ V_11 ] -> V_38 ) ;
F_18 ( V_22 -> V_21 [ V_11 ] ) ;
}
F_18 ( V_22 ) ;
}
static void T_1 F_19 ( struct V_9 * V_10 )
{
int V_39 ;
int V_11 ;
struct V_18 * V_22 ;
V_39 = F_20 ( V_10 ) ;
if ( V_39 < 1 ) {
F_13 ( L_6 , V_10 -> V_27 ) ;
return;
}
V_22 = F_21 ( sizeof( * V_22 ) , V_40 ) ;
if ( ! V_22 )
return;
for ( V_11 = 0 ; V_11 < V_39 ; V_11 ++ )
V_22 -> V_26 [ V_11 ] = F_4 ( V_10 , V_11 ) ;
F_9 ( & V_22 -> V_2 , V_10 ) ;
}
int T_1 F_22 ( struct V_9 * V_10 , struct V_1 * V_2 ,
int type )
{
int V_23 ;
const char * * V_24 ;
struct V_16 * V_19 ;
int V_11 ;
V_23 = F_20 ( V_10 ) ;
if ( V_23 < 1 ) {
F_13 ( L_7 , V_10 -> V_27 ) ;
return - V_8 ;
}
V_24 = F_21 ( ( sizeof( char * ) * V_23 ) , V_40 ) ;
if ( ! V_24 )
return - V_41 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ )
V_24 [ V_11 ] = F_23 ( V_10 , V_11 ) ;
V_19 = F_21 ( sizeof( * V_19 ) , V_40 ) ;
if ( ! V_19 ) {
F_18 ( V_24 ) ;
return - V_41 ;
}
V_19 -> V_23 = V_23 ;
V_19 -> V_24 = V_24 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_10 = V_10 ;
V_19 -> type = type ;
F_24 ( & V_19 -> V_38 , & V_42 ) ;
return 0 ;
}
