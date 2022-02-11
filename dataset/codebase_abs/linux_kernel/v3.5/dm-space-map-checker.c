static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
if ( V_3 >= V_2 -> V_5 )
return - V_6 ;
* V_4 = V_2 -> V_7 [ V_3 ] ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 , int * V_8 )
{
if ( V_3 >= V_2 -> V_5 )
return - V_6 ;
* V_8 = V_2 -> V_7 [ V_3 ] > 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_2 V_9 ;
if ( V_3 >= V_2 -> V_5 )
return - V_6 ;
V_9 = V_2 -> V_7 [ V_3 ] ;
if ( ! V_4 && V_9 )
V_2 -> V_10 ++ ;
else if ( V_4 && ! V_9 )
V_2 -> V_10 -- ;
V_2 -> V_7 [ V_3 ] = V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_2 -> V_5 )
return - V_6 ;
F_3 ( V_2 , V_3 , V_2 -> V_7 [ V_3 ] + 1 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_2 -> V_5 )
return - V_6 ;
F_6 ( V_2 -> V_7 [ V_3 ] == 0 ) ;
F_3 ( V_2 , V_3 , V_2 -> V_7 [ V_3 ] - 1 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_8 ;
T_1 V_13 ;
V_8 = F_8 ( V_12 , & V_13 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_5 = V_13 ;
V_2 -> V_10 = V_13 ;
if ( ! V_13 )
V_2 -> V_7 = NULL ;
else {
V_2 -> V_7 = F_9 ( sizeof( * V_2 -> V_7 ) * V_13 ) ;
if ( ! V_2 -> V_7 )
return - V_14 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_7 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_8 ;
T_2 V_4 ;
T_1 V_13 , V_15 ;
V_8 = F_8 ( V_12 , & V_13 ) ;
if ( V_8 )
return V_8 ;
F_6 ( V_2 -> V_5 != V_13 ) ;
F_13 ( L_1 ) ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ ) {
V_8 = F_14 ( V_12 , V_15 , & V_4 ) ;
if ( V_8 ) {
F_15 ( L_2 ) ;
return V_8 ;
}
F_3 ( V_2 , V_15 , V_4 ) ;
}
F_13 ( L_3 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_16 )
{
T_1 V_13 = V_2 -> V_5 + V_16 ;
T_2 * V_7 = F_9 ( sizeof( * V_7 ) * V_13 ) ;
if ( ! V_7 )
return - V_14 ;
if ( V_2 -> V_7 ) {
memcpy ( V_7 , V_2 -> V_7 , sizeof( * V_7 ) * V_2 -> V_5 ) ;
F_10 ( V_2 ) ;
}
V_2 -> V_5 = V_13 ;
V_2 -> V_10 += V_16 ;
V_2 -> V_7 = V_7 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_17 , struct V_1 * V_18 )
{
if ( V_17 -> V_5 != V_18 -> V_5 ) {
F_6 ( V_17 -> V_5 > V_18 -> V_5 ) ;
F_16 ( V_17 , V_18 -> V_5 - V_17 -> V_5 ) ;
}
F_6 ( V_17 -> V_5 != V_18 -> V_5 ) ;
V_17 -> V_10 = V_18 -> V_10 ;
memcpy ( V_17 -> V_7 , V_18 -> V_7 , sizeof( * V_17 -> V_7 ) * V_17 -> V_5 ) ;
return 0 ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
F_20 ( V_20 -> V_21 ) ;
F_10 ( & V_20 -> V_22 ) ;
F_10 ( & V_20 -> V_7 ) ;
F_21 ( V_20 ) ;
}
static int F_22 ( struct V_11 * V_12 , T_1 * V_4 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 = F_8 ( V_20 -> V_21 , V_4 ) ;
if ( ! V_8 )
F_6 ( V_20 -> V_22 . V_5 != * V_4 ) ;
return V_8 ;
}
static int F_23 ( struct V_11 * V_12 , T_1 * V_4 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 = F_24 ( V_20 -> V_21 , V_4 ) ;
if ( ! V_8 ) {
T_1 V_3 , V_23 = 0 ;
for ( V_3 = 0 ; V_3 < V_20 -> V_22 . V_5 ; V_3 ++ )
if ( V_20 -> V_22 . V_7 [ V_3 ] == 0 &&
V_20 -> V_7 . V_7 [ V_3 ] == 0 )
V_23 ++ ;
if ( V_23 != * V_4 )
F_15 ( L_4 ,
( unsigned ) V_23 , ( unsigned ) * V_4 ) ;
}
return V_8 ;
}
static int F_25 ( struct V_11 * V_12 , T_1 * V_3 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 = F_26 ( V_20 -> V_21 , V_3 ) ;
if ( ! V_8 ) {
F_6 ( * V_3 >= V_20 -> V_22 . V_5 ) ;
F_6 ( V_20 -> V_22 . V_7 [ * V_3 ] != 0 ) ;
F_6 ( * V_3 >= V_20 -> V_7 . V_5 ) ;
F_6 ( V_20 -> V_7 . V_7 [ * V_3 ] != 0 ) ;
F_3 ( & V_20 -> V_7 , * V_3 , 1 ) ;
}
return V_8 ;
}
static int F_27 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 = F_28 ( V_20 -> V_21 , V_3 ) ;
int V_24 = F_4 ( & V_20 -> V_7 , V_3 ) ;
F_6 ( V_8 != V_24 ) ;
return V_8 ;
}
static int F_29 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 = F_30 ( V_20 -> V_21 , V_3 ) ;
int V_24 = F_5 ( & V_20 -> V_7 , V_3 ) ;
F_6 ( V_8 != V_24 ) ;
return V_8 ;
}
static int F_31 ( struct V_11 * V_12 , T_1 V_3 , T_2 * V_25 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
T_2 V_26 = 0 ;
int V_8 = F_14 ( V_20 -> V_21 , V_3 , V_25 ) ;
int V_24 = F_1 ( & V_20 -> V_7 , V_3 , & V_26 ) ;
F_6 ( V_8 != V_24 ) ;
if ( ! V_8 )
F_6 ( * V_25 != V_26 ) ;
return V_8 ;
}
static int F_32 ( struct V_11 * V_12 , T_1 V_3 , int * V_25 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_26 = 0 ;
int V_8 = F_33 ( V_20 -> V_21 , V_3 , V_25 ) ;
int V_24 = F_2 ( & V_20 -> V_7 , V_3 , & V_26 ) ;
F_6 ( V_8 != V_24 ) ;
if ( ! V_8 )
F_6 ( ! ( * V_25 ) && V_26 ) ;
return V_8 ;
}
static int F_34 ( struct V_11 * V_12 , T_1 V_3 , T_2 V_4 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
T_2 V_27 ;
int V_8 = F_35 ( V_20 -> V_21 , V_3 , V_4 ) ;
int V_24 ;
F_6 ( V_3 >= V_20 -> V_7 . V_5 ) ;
V_27 = V_20 -> V_7 . V_7 [ V_3 ] ;
V_24 = F_3 ( & V_20 -> V_7 , V_3 , V_4 ) ;
F_6 ( V_8 != V_24 ) ;
return V_8 ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 ;
V_8 = F_37 ( V_20 -> V_21 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( & V_20 -> V_22 , & V_20 -> V_7 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 , T_1 V_16 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
int V_8 = F_39 ( V_20 -> V_21 , V_16 ) ;
if ( V_8 )
return V_8 ;
return F_16 ( & V_20 -> V_7 , V_16 ) ;
}
static int F_40 ( struct V_11 * V_12 , T_3 * V_25 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
return F_41 ( V_20 -> V_21 , V_25 ) ;
}
static int F_42 ( struct V_11 * V_12 , void * V_28 , T_3 V_29 )
{
struct V_19 * V_20 = F_19 ( V_12 , struct V_19 , V_12 ) ;
return F_43 ( V_20 -> V_21 , V_28 , V_29 ) ;
}
struct V_11 * F_44 ( struct V_11 * V_12 )
{
int V_8 ;
struct V_19 * V_20 ;
if ( F_45 ( V_12 ) )
return F_46 ( - V_6 ) ;
V_20 = F_47 ( sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return F_46 ( - V_14 ) ;
memcpy ( & V_20 -> V_12 , & V_31 , sizeof( V_20 -> V_12 ) ) ;
V_8 = F_7 ( & V_20 -> V_22 , V_12 ) ;
if ( V_8 ) {
F_21 ( V_20 ) ;
return F_46 ( V_8 ) ;
}
V_8 = F_7 ( & V_20 -> V_7 , V_12 ) ;
if ( V_8 ) {
F_10 ( & V_20 -> V_22 ) ;
F_21 ( V_20 ) ;
return F_46 ( V_8 ) ;
}
V_20 -> V_21 = V_12 ;
V_8 = F_12 ( & V_20 -> V_7 , V_12 ) ;
if ( V_8 ) {
F_10 ( & V_20 -> V_7 ) ;
F_10 ( & V_20 -> V_22 ) ;
F_21 ( V_20 ) ;
return F_46 ( V_8 ) ;
}
V_8 = F_17 ( & V_20 -> V_22 , & V_20 -> V_7 ) ;
if ( V_8 ) {
F_10 ( & V_20 -> V_7 ) ;
F_10 ( & V_20 -> V_22 ) ;
F_21 ( V_20 ) ;
return F_46 ( V_8 ) ;
}
return & V_20 -> V_12 ;
}
struct V_11 * F_48 ( struct V_11 * V_12 )
{
int V_8 ;
struct V_19 * V_20 ;
if ( F_45 ( V_12 ) )
return F_46 ( - V_6 ) ;
V_20 = F_47 ( sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return F_46 ( - V_14 ) ;
memcpy ( & V_20 -> V_12 , & V_31 , sizeof( V_20 -> V_12 ) ) ;
V_8 = F_7 ( & V_20 -> V_22 , V_12 ) ;
if ( V_8 ) {
F_21 ( V_20 ) ;
return F_46 ( V_8 ) ;
}
V_8 = F_7 ( & V_20 -> V_7 , V_12 ) ;
if ( V_8 ) {
F_10 ( & V_20 -> V_22 ) ;
F_21 ( V_20 ) ;
return F_46 ( V_8 ) ;
}
V_20 -> V_21 = V_12 ;
return & V_20 -> V_12 ;
}
struct V_11 * F_44 ( struct V_11 * V_12 )
{
return V_12 ;
}
struct V_11 * F_48 ( struct V_11 * V_12 )
{
return V_12 ;
}
