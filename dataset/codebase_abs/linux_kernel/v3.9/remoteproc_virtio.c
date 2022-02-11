static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_6 = V_4 -> V_7 -> V_6 ;
int V_8 = V_4 -> V_8 ;
F_2 ( & V_6 -> V_9 , L_1 , V_8 ) ;
V_6 -> V_10 -> V_11 ( V_6 , V_8 ) ;
}
T_1 F_3 ( struct V_6 * V_6 , int V_8 )
{
struct V_3 * V_4 ;
F_2 ( & V_6 -> V_9 , L_2 , V_8 ) ;
V_4 = F_4 ( & V_6 -> V_12 , V_8 ) ;
if ( ! V_4 || ! V_4 -> V_2 )
return V_13 ;
return F_5 ( 0 , V_4 -> V_2 ) ;
}
static struct V_1 * F_6 ( struct V_14 * V_15 ,
unsigned V_16 ,
void (* F_7)( struct V_1 * V_2 ) ,
const char * V_17 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
struct V_19 * V_9 = & V_6 -> V_9 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
void * V_20 ;
int V_21 , V_22 , V_23 ;
if ( V_16 >= F_10 ( V_7 -> V_24 ) )
return F_11 ( - V_25 ) ;
if ( ! V_17 )
return NULL ;
V_23 = F_12 ( V_7 , V_16 ) ;
if ( V_23 )
return F_11 ( V_23 ) ;
V_4 = & V_7 -> V_24 [ V_16 ] ;
V_20 = V_4 -> V_26 ;
V_21 = V_4 -> V_21 ;
V_22 = F_13 ( V_21 , V_4 -> V_27 ) ;
memset ( V_20 , 0 , V_22 ) ;
F_2 ( V_9 , L_3 ,
V_16 , V_20 , V_21 , V_4 -> V_8 ) ;
V_2 = F_14 ( V_16 , V_21 , V_4 -> V_27 , V_15 , false , V_20 ,
F_1 , F_7 , V_17 ) ;
if ( ! V_2 ) {
F_15 ( V_9 , L_4 , V_17 ) ;
F_16 ( V_4 ) ;
return F_11 ( - V_28 ) ;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
return V_2 ;
}
static void F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_29 ;
struct V_3 * V_4 ;
F_18 (vq, n, &vdev->vqs, list) {
V_4 = V_2 -> V_5 ;
V_4 -> V_2 = NULL ;
F_19 ( V_2 ) ;
F_16 ( V_4 ) ;
}
}
static void F_20 ( struct V_14 * V_15 )
{
struct V_6 * V_6 = F_9 ( V_15 ) ;
F_21 ( V_6 ) ;
F_17 ( V_15 ) ;
}
static int F_22 ( struct V_14 * V_15 , unsigned V_30 ,
struct V_1 * V_31 [] ,
T_2 * V_32 [] ,
const char * V_33 [] )
{
struct V_6 * V_6 = F_9 ( V_15 ) ;
int V_34 , V_23 ;
for ( V_34 = 0 ; V_34 < V_30 ; ++ V_34 ) {
V_31 [ V_34 ] = F_6 ( V_15 , V_34 , V_32 [ V_34 ] , V_33 [ V_34 ] ) ;
if ( F_23 ( V_31 [ V_34 ] ) ) {
V_23 = F_24 ( V_31 [ V_34 ] ) ;
goto error;
}
}
V_23 = F_25 ( V_6 ) ;
if ( V_23 ) {
F_15 ( & V_6 -> V_9 , L_5 , V_23 ) ;
goto error;
}
return 0 ;
error:
F_17 ( V_15 ) ;
return V_23 ;
}
static T_3 F_26 ( struct V_14 * V_15 )
{
return 0 ;
}
static void F_27 ( struct V_14 * V_15 , T_3 V_35 )
{
F_2 ( & V_15 -> V_9 , L_6 , V_35 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
F_2 ( & V_15 -> V_9 , L_7 ) ;
}
static T_4 F_29 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
return V_7 -> V_36 ;
}
static void F_30 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
F_31 ( V_15 ) ;
V_7 -> V_37 = V_15 -> V_38 [ 0 ] ;
}
static void F_32 ( struct V_19 * V_9 )
{
struct V_14 * V_15 = F_33 ( V_9 ) ;
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
F_34 ( & V_7 -> V_39 ) ;
F_35 ( V_7 ) ;
F_36 ( & V_6 -> V_9 ) ;
}
int F_37 ( struct V_18 * V_7 , int V_16 )
{
struct V_6 * V_6 = V_7 -> V_6 ;
struct V_19 * V_9 = & V_6 -> V_9 ;
struct V_14 * V_15 = & V_7 -> V_15 ;
int V_23 ;
V_15 -> V_16 . V_19 = V_16 ,
V_15 -> V_40 = & V_41 ,
V_15 -> V_9 . V_42 = V_9 ;
V_15 -> V_9 . V_43 = F_32 ;
F_38 ( & V_6 -> V_9 ) ;
V_23 = F_39 ( V_15 ) ;
if ( V_23 ) {
F_36 ( & V_6 -> V_9 ) ;
F_15 ( V_9 , L_8 , V_23 ) ;
goto V_44;
}
F_40 ( V_9 , L_9 , F_41 ( & V_15 -> V_9 ) , V_16 ) ;
V_44:
return V_23 ;
}
void F_42 ( struct V_18 * V_7 )
{
F_43 ( & V_7 -> V_15 ) ;
}
