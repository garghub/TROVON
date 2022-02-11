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
V_2 -> V_7 = F_9 ( sizeof( * V_2 -> V_7 ) * V_13 , V_14 ) ;
if ( ! V_2 -> V_7 )
return - V_15 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_8 ;
T_2 V_4 ;
T_1 V_13 , V_16 ;
V_8 = F_8 ( V_12 , & V_13 ) ;
if ( V_8 )
return V_8 ;
F_6 ( V_2 -> V_5 != V_13 ) ;
F_11 ( L_1 ) ;
for ( V_16 = 0 ; V_16 < V_13 ; V_16 ++ ) {
V_8 = F_12 ( V_12 , V_16 , & V_4 ) ;
if ( V_8 ) {
F_13 ( L_2 ) ;
return V_8 ;
}
F_3 ( V_2 , V_16 , V_4 ) ;
}
F_11 ( L_3 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_17 )
{
T_1 V_13 = V_2 -> V_5 + V_17 ;
T_2 * V_7 = F_9 ( sizeof( * V_7 ) * V_13 , V_14 ) ;
if ( ! V_7 )
return - V_15 ;
memcpy ( V_7 , V_2 -> V_7 , sizeof( * V_7 ) * V_2 -> V_5 ) ;
F_15 ( V_2 -> V_7 ) ;
V_2 -> V_5 = V_13 ;
V_2 -> V_10 += V_17 ;
V_2 -> V_7 = V_7 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_18 , struct V_1 * V_19 )
{
if ( V_18 -> V_5 != V_19 -> V_5 ) {
F_6 ( V_18 -> V_5 > V_19 -> V_5 ) ;
F_14 ( V_18 , V_19 -> V_5 - V_18 -> V_5 ) ;
}
F_6 ( V_18 -> V_5 != V_19 -> V_5 ) ;
V_18 -> V_10 = V_19 -> V_10 ;
memcpy ( V_18 -> V_7 , V_19 -> V_7 , sizeof( * V_18 -> V_7 ) * V_18 -> V_5 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_7 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
F_20 ( V_21 -> V_22 ) ;
F_17 ( & V_21 -> V_23 ) ;
F_17 ( & V_21 -> V_7 ) ;
F_15 ( V_21 ) ;
}
static int F_21 ( struct V_11 * V_12 , T_1 * V_4 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 = F_8 ( V_21 -> V_22 , V_4 ) ;
if ( ! V_8 )
F_6 ( V_21 -> V_23 . V_5 != * V_4 ) ;
return V_8 ;
}
static int F_22 ( struct V_11 * V_12 , T_1 * V_4 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 = F_23 ( V_21 -> V_22 , V_4 ) ;
if ( ! V_8 ) {
T_1 V_3 , V_24 = 0 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_23 . V_5 ; V_3 ++ )
if ( V_21 -> V_23 . V_7 [ V_3 ] == 0 &&
V_21 -> V_7 . V_7 [ V_3 ] == 0 )
V_24 ++ ;
if ( V_24 != * V_4 )
F_13 ( L_4 ,
( unsigned ) V_24 , ( unsigned ) * V_4 ) ;
}
return V_8 ;
}
static int F_24 ( struct V_11 * V_12 , T_1 * V_3 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 = F_25 ( V_21 -> V_22 , V_3 ) ;
if ( ! V_8 ) {
F_6 ( * V_3 >= V_21 -> V_23 . V_5 ) ;
F_6 ( V_21 -> V_23 . V_7 [ * V_3 ] != 0 ) ;
F_6 ( * V_3 >= V_21 -> V_7 . V_5 ) ;
F_6 ( V_21 -> V_7 . V_7 [ * V_3 ] != 0 ) ;
F_3 ( & V_21 -> V_7 , * V_3 , 1 ) ;
}
return V_8 ;
}
static int F_26 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 = F_27 ( V_21 -> V_22 , V_3 ) ;
int V_25 = F_4 ( & V_21 -> V_7 , V_3 ) ;
F_6 ( V_8 != V_25 ) ;
return V_8 ;
}
static int F_28 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 = F_29 ( V_21 -> V_22 , V_3 ) ;
int V_25 = F_5 ( & V_21 -> V_7 , V_3 ) ;
F_6 ( V_8 != V_25 ) ;
return V_8 ;
}
static int F_30 ( struct V_11 * V_12 , T_1 V_3 , T_2 * V_26 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
T_2 V_27 = 0 ;
int V_8 = F_12 ( V_21 -> V_22 , V_3 , V_26 ) ;
int V_25 = F_1 ( & V_21 -> V_7 , V_3 , & V_27 ) ;
F_6 ( V_8 != V_25 ) ;
if ( ! V_8 )
F_6 ( * V_26 != V_27 ) ;
return V_8 ;
}
static int F_31 ( struct V_11 * V_12 , T_1 V_3 , int * V_26 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_27 = 0 ;
int V_8 = F_32 ( V_21 -> V_22 , V_3 , V_26 ) ;
int V_25 = F_2 ( & V_21 -> V_7 , V_3 , & V_27 ) ;
F_6 ( V_8 != V_25 ) ;
if ( ! V_8 )
F_6 ( ! ( * V_26 ) && V_27 ) ;
return V_8 ;
}
static int F_33 ( struct V_11 * V_12 , T_1 V_3 , T_2 V_4 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
T_2 V_28 ;
int V_8 = F_34 ( V_21 -> V_22 , V_3 , V_4 ) ;
int V_25 ;
F_6 ( V_3 >= V_21 -> V_7 . V_5 ) ;
V_28 = V_21 -> V_7 . V_7 [ V_3 ] ;
V_25 = F_3 ( & V_21 -> V_7 , V_3 , V_4 ) ;
F_6 ( V_8 != V_25 ) ;
return V_8 ;
}
static int F_35 ( struct V_11 * V_12 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 ;
V_8 = F_36 ( V_21 -> V_22 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( & V_21 -> V_23 , & V_21 -> V_7 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 , T_1 V_17 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
int V_8 = F_38 ( V_21 -> V_22 , V_17 ) ;
if ( V_8 )
return V_8 ;
return F_14 ( & V_21 -> V_7 , V_17 ) ;
}
static int F_39 ( struct V_11 * V_12 , T_3 * V_26 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
return F_40 ( V_21 -> V_22 , V_26 ) ;
}
static int F_41 ( struct V_11 * V_12 , void * V_29 , T_3 V_30 )
{
struct V_20 * V_21 = F_19 ( V_12 , struct V_20 , V_12 ) ;
return F_42 ( V_21 -> V_22 , V_29 , V_30 ) ;
}
struct V_11 * F_43 ( struct V_11 * V_12 )
{
int V_8 ;
struct V_20 * V_21 ;
if ( ! V_12 )
return NULL ;
V_21 = F_44 ( sizeof( * V_21 ) , V_14 ) ;
if ( ! V_21 )
return NULL ;
memcpy ( & V_21 -> V_12 , & V_31 , sizeof( V_21 -> V_12 ) ) ;
V_8 = F_7 ( & V_21 -> V_23 , V_12 ) ;
if ( V_8 ) {
F_15 ( V_21 ) ;
return NULL ;
}
V_8 = F_7 ( & V_21 -> V_7 , V_12 ) ;
if ( V_8 ) {
F_17 ( & V_21 -> V_23 ) ;
F_15 ( V_21 ) ;
return NULL ;
}
V_21 -> V_22 = V_12 ;
V_8 = F_10 ( & V_21 -> V_7 , V_12 ) ;
if ( V_8 ) {
F_17 ( & V_21 -> V_7 ) ;
F_17 ( & V_21 -> V_23 ) ;
F_15 ( V_21 ) ;
return NULL ;
}
V_8 = F_16 ( & V_21 -> V_23 , & V_21 -> V_7 ) ;
if ( V_8 ) {
F_17 ( & V_21 -> V_7 ) ;
F_17 ( & V_21 -> V_23 ) ;
F_15 ( V_21 ) ;
return NULL ;
}
return & V_21 -> V_12 ;
}
struct V_11 * F_45 ( struct V_11 * V_12 )
{
int V_8 ;
struct V_20 * V_21 ;
if ( ! V_12 )
return NULL ;
V_21 = F_44 ( sizeof( * V_21 ) , V_14 ) ;
if ( ! V_21 )
return NULL ;
memcpy ( & V_21 -> V_12 , & V_31 , sizeof( V_21 -> V_12 ) ) ;
V_8 = F_7 ( & V_21 -> V_23 , V_12 ) ;
if ( V_8 ) {
F_15 ( V_21 ) ;
return NULL ;
}
V_8 = F_7 ( & V_21 -> V_7 , V_12 ) ;
if ( V_8 ) {
F_17 ( & V_21 -> V_23 ) ;
F_15 ( V_21 ) ;
return NULL ;
}
V_21 -> V_22 = V_12 ;
return & V_21 -> V_12 ;
}
struct V_11 * F_43 ( struct V_11 * V_12 )
{
return V_12 ;
}
struct V_11 * F_45 ( struct V_11 * V_12 )
{
return V_12 ;
}
