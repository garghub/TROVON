static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_6 = V_4 -> V_7 -> V_6 ;
int V_8 = V_4 -> V_8 ;
F_2 ( V_6 -> V_9 , L_1 , V_8 ) ;
V_6 -> V_10 -> V_11 ( V_6 , V_8 ) ;
}
T_1 F_3 ( struct V_6 * V_6 , int V_8 )
{
struct V_3 * V_4 ;
F_2 ( V_6 -> V_9 , L_2 , V_8 ) ;
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
struct V_3 * V_4 ;
struct V_1 * V_2 ;
void * V_19 ;
int V_20 , V_21 ;
if ( V_16 >= F_10 ( V_7 -> V_22 ) )
return F_11 ( - V_23 ) ;
V_4 = & V_7 -> V_22 [ V_16 ] ;
V_19 = V_4 -> V_24 ;
V_20 = V_4 -> V_20 ;
V_21 = F_12 ( V_20 , V_4 -> V_25 ) ;
memset ( V_19 , 0 , V_21 ) ;
F_2 ( V_6 -> V_9 , L_3 ,
V_16 , V_19 , V_20 , V_4 -> V_8 ) ;
V_2 = F_13 ( V_20 , V_4 -> V_25 , V_15 , false , V_19 ,
F_1 , F_7 , V_17 ) ;
if ( ! V_2 ) {
F_14 ( V_6 -> V_9 , L_4 , V_17 ) ;
return F_11 ( - V_26 ) ;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
return V_2 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_27 ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
struct V_3 * V_4 ;
F_16 ( V_6 ) ;
F_17 (vq, n, &vdev->vqs, list) {
V_4 = V_2 -> V_5 ;
V_4 -> V_2 = NULL ;
F_18 ( V_2 ) ;
}
}
static int F_19 ( struct V_14 * V_15 , unsigned V_28 ,
struct V_1 * V_29 [] ,
T_2 * V_30 [] ,
const char * V_31 [] )
{
struct V_6 * V_6 = F_9 ( V_15 ) ;
int V_32 , V_33 ;
for ( V_32 = 0 ; V_32 < V_28 ; ++ V_32 ) {
V_29 [ V_32 ] = F_6 ( V_15 , V_32 , V_30 [ V_32 ] , V_31 [ V_32 ] ) ;
if ( F_20 ( V_29 [ V_32 ] ) ) {
V_33 = F_21 ( V_29 [ V_32 ] ) ;
goto error;
}
}
V_33 = F_22 ( V_6 ) ;
if ( V_33 ) {
F_14 ( V_6 -> V_9 , L_5 , V_33 ) ;
goto error;
}
return 0 ;
error:
F_15 ( V_15 ) ;
return V_33 ;
}
static T_3 F_23 ( struct V_14 * V_15 )
{
return 0 ;
}
static void F_24 ( struct V_14 * V_15 , T_3 V_34 )
{
F_2 ( & V_15 -> V_9 , L_6 , V_34 ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
F_2 ( & V_15 -> V_9 , L_7 ) ;
}
static T_4 F_26 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
return V_7 -> V_35 ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
F_28 ( V_15 ) ;
V_7 -> V_36 = V_15 -> V_37 [ 0 ] ;
}
static void F_29 ( struct V_38 * V_9 )
{
struct V_14 * V_15 = F_30 ( V_9 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
F_31 ( & V_6 -> V_39 , V_40 ) ;
}
int F_32 ( struct V_18 * V_7 , int V_16 )
{
struct V_6 * V_6 = V_7 -> V_6 ;
struct V_38 * V_9 = V_6 -> V_9 ;
struct V_14 * V_15 = & V_7 -> V_15 ;
int V_33 ;
V_15 -> V_16 . V_38 = V_16 ,
V_15 -> V_41 = & V_42 ,
V_15 -> V_9 . V_43 = V_9 ;
V_15 -> V_9 . V_44 = F_29 ;
F_33 ( & V_6 -> V_39 ) ;
V_33 = F_34 ( V_15 ) ;
if ( V_33 ) {
F_31 ( & V_6 -> V_39 , V_40 ) ;
F_14 ( V_9 , L_8 , V_33 ) ;
goto V_45;
}
F_35 ( V_9 , L_9 , F_36 ( & V_15 -> V_9 ) , V_16 ) ;
V_45:
return V_33 ;
}
void F_37 ( struct V_18 * V_7 )
{
F_38 ( & V_7 -> V_15 ) ;
}
