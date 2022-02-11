static int T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
return F_3 ( & V_2 ) ;
}
static void T_2 F_4 ( void )
{
F_5 ( & V_2 ) ;
F_6 ( & V_1 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = F_8 ( V_4 ) ;
F_9 ( & V_1 , V_5 -> V_6 ) ;
F_10 ( V_5 ) ;
}
struct V_5 * F_11 ( struct V_3 * V_4 ,
unsigned int V_7 , T_3 V_8 )
{
struct V_5 * V_5 ;
int V_9 ;
if ( F_12 ( ! V_4 || ! V_7 ) )
return F_13 ( - V_10 ) ;
V_5 = F_14 ( sizeof( * V_5 ) +
V_7 * sizeof( * V_5 -> V_11 ) +
V_8 , V_12 ) ;
if ( ! V_5 )
return F_13 ( - V_13 ) ;
V_5 -> V_11 = (struct V_14 * ) ( V_5 + 1 ) ;
V_5 -> V_4 . V_15 = & V_2 ;
V_5 -> V_4 . type = & V_16 ;
V_5 -> V_4 . V_17 = V_4 ;
V_5 -> V_4 . V_18 = V_4 -> V_18 ;
F_15 ( & V_5 -> V_4 , V_5 ) ;
V_5 -> V_6 = F_16 ( & V_1 , 0 , 0 , V_12 ) ;
if ( V_5 -> V_6 < 0 ) {
int V_19 = V_5 -> V_6 ;
F_17 ( L_1 ) ;
F_10 ( V_5 ) ;
return F_13 ( V_19 ) ;
}
F_18 ( & V_5 -> V_4 , L_2 , V_5 -> V_6 ) ;
V_5 -> V_7 = V_7 ;
for ( V_9 = 0 ; V_9 < V_7 ; ++ V_9 ) {
struct V_14 * V_11 = & V_5 -> V_11 [ V_9 ] ;
V_11 -> V_20 = V_5 ;
F_19 ( & V_11 -> V_21 , 1 ) ;
V_11 -> V_22 = V_23 ;
V_11 -> V_24 = V_25 ;
}
F_20 ( & V_5 -> V_4 ) ;
return V_5 ;
}
static int F_21 ( struct V_14 * V_11 , int V_26 )
{
int V_27 = V_11 -> V_20 -> V_28 -> V_29 ( V_11 , V_26 ) ;
V_11 -> V_22 = V_27 < 0 ? V_23 : V_26 ;
return V_27 ;
}
int F_22 ( struct V_5 * V_5 )
{
int V_9 ;
int V_27 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_7 ; ++ V_9 ) {
struct V_14 * V_11 = & V_5 -> V_11 [ V_9 ] ;
if ( V_11 -> V_24 == V_11 -> V_22 )
continue;
V_27 = F_21 ( V_11 , V_11 -> V_24 ) ;
if ( V_27 < 0 ) {
F_23 ( & V_5 -> V_4 , L_3 ) ;
return V_27 ;
}
}
V_27 = F_24 ( & V_5 -> V_4 ) ;
if ( V_27 < 0 )
F_23 ( & V_5 -> V_4 ,
L_4 , V_30 , V_27 ) ;
return V_27 ;
}
void F_25 ( struct V_5 * V_5 )
{
F_26 ( & V_5 -> V_4 ) ;
}
void F_27 ( struct V_5 * V_5 )
{
if ( ! V_5 )
return;
F_28 ( & V_5 -> V_4 ) ;
}
static void F_29 ( struct V_3 * V_4 , void * V_31 )
{
struct V_5 * V_5 = * (struct V_5 * * ) V_31 ;
F_27 ( V_5 ) ;
}
struct V_5 * F_30 ( struct V_3 * V_4 ,
unsigned int V_7 ,
T_3 V_8 )
{
struct V_5 * * V_32 , * V_5 ;
V_32 = F_31 ( F_29 , sizeof( * V_32 ) , V_12 ) ;
if ( ! V_32 )
return F_13 ( - V_13 ) ;
V_5 = F_11 ( V_4 , V_7 , V_8 ) ;
if ( F_32 ( V_5 ) ) {
F_33 ( V_32 ) ;
return V_5 ;
}
* V_32 = V_5 ;
F_34 ( V_4 , V_32 ) ;
return V_5 ;
}
static void F_35 ( struct V_3 * V_4 , void * V_31 )
{
struct V_5 * V_5 = * (struct V_5 * * ) V_31 ;
F_25 ( V_5 ) ;
}
int F_36 ( struct V_3 * V_4 ,
struct V_5 * V_5 )
{
struct V_5 * * V_32 ;
int V_31 ;
V_32 = F_31 ( F_35 , sizeof( * V_32 ) , V_12 ) ;
if ( ! V_32 )
return - V_13 ;
V_31 = F_22 ( V_5 ) ;
if ( V_31 ) {
F_33 ( V_32 ) ;
return V_31 ;
}
* V_32 = V_5 ;
F_34 ( V_4 , V_32 ) ;
return V_31 ;
}
unsigned int F_37 ( struct V_14 * V_11 )
{
return V_11 -> V_33 ;
}
static int F_38 ( struct V_14 * V_11 , int V_26 )
{
int V_27 ;
if ( F_12 ( V_26 < 0 || V_26 >= V_11 -> V_33 ) )
return - V_10 ;
if ( V_11 -> V_22 == V_26 )
return 0 ;
V_27 = F_21 ( V_11 , V_26 ) ;
if ( V_27 >= 0 )
return 0 ;
if ( V_11 -> V_24 != V_25 )
F_21 ( V_11 , V_11 -> V_24 ) ;
return V_27 ;
}
int F_39 ( struct V_14 * V_11 , unsigned int V_26 )
{
int V_27 ;
V_27 = F_40 ( & V_11 -> V_21 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_38 ( V_11 , V_26 ) ;
if ( V_27 < 0 )
F_41 ( & V_11 -> V_21 ) ;
return V_27 ;
}
int F_42 ( struct V_14 * V_11 , unsigned int V_26 )
{
int V_27 ;
if ( F_43 ( & V_11 -> V_21 ) )
return - V_34 ;
V_27 = F_38 ( V_11 , V_26 ) ;
if ( V_27 < 0 )
F_41 ( & V_11 -> V_21 ) ;
return V_27 ;
}
int F_44 ( struct V_14 * V_11 )
{
int V_27 = 0 ;
if ( V_11 -> V_24 != V_25 &&
V_11 -> V_24 != V_11 -> V_22 )
V_27 = F_21 ( V_11 , V_11 -> V_24 ) ;
F_41 ( & V_11 -> V_21 ) ;
return V_27 ;
}
static int F_45 ( struct V_3 * V_4 , const void * V_35 )
{
return V_4 -> V_18 == V_35 ;
}
static struct V_5 * F_46 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
V_4 = F_47 ( & V_2 , NULL , V_37 , F_45 ) ;
return V_4 ? F_8 ( V_4 ) : NULL ;
}
struct V_14 * F_48 ( struct V_3 * V_4 , const char * V_38 )
{
struct V_36 * V_37 = V_4 -> V_18 ;
struct V_39 args ;
struct V_5 * V_5 ;
unsigned int V_40 ;
int V_41 = 0 ;
int V_27 ;
if ( V_38 ) {
V_41 = F_49 ( V_37 , L_5 ,
V_38 ) ;
if ( V_41 < 0 ) {
F_23 ( V_4 , L_6 ,
V_38 ) ;
return F_13 ( V_41 ) ;
}
}
V_27 = F_50 ( V_37 ,
L_7 , L_8 ,
V_41 , & args ) ;
if ( V_27 ) {
F_23 ( V_4 , L_9 ,
V_37 -> V_42 , V_38 ? : L_10 , V_41 ) ;
return F_13 ( V_27 ) ;
}
V_5 = F_46 ( args . V_37 ) ;
F_51 ( args . V_37 ) ;
if ( ! V_5 )
return F_13 ( - V_43 ) ;
if ( args . V_44 > 1 ||
( ! args . V_44 && ( V_5 -> V_7 > 1 ) ) ) {
F_23 ( V_4 , L_11 ,
V_37 -> V_42 , args . V_37 -> V_42 ) ;
return F_13 ( - V_10 ) ;
}
V_40 = 0 ;
if ( args . V_44 )
V_40 = args . args [ 0 ] ;
if ( V_40 >= V_5 -> V_7 ) {
F_23 ( V_4 , L_12 ,
V_37 -> V_42 , V_40 , args . V_37 -> V_42 ) ;
return F_13 ( - V_10 ) ;
}
F_52 ( & V_5 -> V_4 ) ;
return & V_5 -> V_11 [ V_40 ] ;
}
void F_53 ( struct V_14 * V_11 )
{
F_28 ( & V_11 -> V_20 -> V_4 ) ;
}
static void F_54 ( struct V_3 * V_4 , void * V_31 )
{
struct V_14 * V_11 = * (struct V_14 * * ) V_31 ;
F_53 ( V_11 ) ;
}
struct V_14 * F_55 ( struct V_3 * V_4 ,
const char * V_38 )
{
struct V_14 * * V_32 , * V_11 ;
V_32 = F_31 ( F_54 , sizeof( * V_32 ) , V_12 ) ;
if ( ! V_32 )
return F_13 ( - V_13 ) ;
V_11 = F_48 ( V_4 , V_38 ) ;
if ( F_32 ( V_11 ) ) {
F_33 ( V_32 ) ;
return V_11 ;
}
* V_32 = V_11 ;
F_34 ( V_4 , V_32 ) ;
return V_11 ;
}
