static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_6 = V_4 -> V_7 -> V_6 ;
int V_8 = V_4 -> V_8 ;
F_2 ( & V_6 -> V_9 , L_1 , V_8 ) ;
V_6 -> V_10 -> V_11 ( V_6 , V_8 ) ;
return true ;
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
unsigned int V_16 ,
void (* F_7)( struct V_1 * V_2 ) ,
const char * V_17 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
struct V_19 * V_9 = & V_6 -> V_9 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
void * V_20 ;
int V_21 , V_22 ;
if ( V_16 >= F_10 ( V_7 -> V_23 ) )
return F_11 ( - V_24 ) ;
if ( ! V_17 )
return NULL ;
V_4 = & V_7 -> V_23 [ V_16 ] ;
V_20 = V_4 -> V_25 ;
V_21 = V_4 -> V_21 ;
V_22 = F_12 ( V_21 , V_4 -> V_26 ) ;
memset ( V_20 , 0 , V_22 ) ;
F_2 ( V_9 , L_3 ,
V_16 , V_20 , V_21 , V_4 -> V_8 ) ;
V_2 = F_13 ( V_16 , V_21 , V_4 -> V_26 , V_15 , false , V_20 ,
F_1 , F_7 , V_17 ) ;
if ( ! V_2 ) {
F_14 ( V_9 , L_4 , V_17 ) ;
F_15 ( V_4 ) ;
return F_11 ( - V_27 ) ;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
return V_2 ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_28 ;
struct V_3 * V_4 ;
F_17 (vq, n, &vdev->vqs, list) {
V_4 = V_2 -> V_5 ;
V_4 -> V_2 = NULL ;
F_18 ( V_2 ) ;
}
}
static void F_19 ( struct V_14 * V_15 )
{
F_16 ( V_15 ) ;
}
static int F_20 ( struct V_14 * V_15 , unsigned int V_29 ,
struct V_1 * V_30 [] ,
T_2 * V_31 [] ,
const char * const V_32 [] )
{
int V_33 , V_34 ;
for ( V_33 = 0 ; V_33 < V_29 ; ++ V_33 ) {
V_30 [ V_33 ] = F_6 ( V_15 , V_33 , V_31 [ V_33 ] , V_32 [ V_33 ] ) ;
if ( F_21 ( V_30 [ V_33 ] ) ) {
V_34 = F_22 ( V_30 [ V_33 ] ) ;
goto error;
}
}
return 0 ;
error:
F_16 ( V_15 ) ;
return V_34 ;
}
static T_3 F_23 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
return V_36 -> V_39 ;
}
static void F_24 ( struct V_14 * V_15 , T_3 V_39 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
V_36 -> V_39 = V_39 ;
F_2 ( & V_15 -> V_9 , L_5 , V_39 ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
V_36 -> V_39 = 0 ;
F_2 ( & V_15 -> V_9 , L_6 ) ;
}
static T_4 F_26 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
return V_36 -> V_40 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
F_28 ( V_15 ) ;
F_29 ( ( V_41 ) V_15 -> V_42 != V_15 -> V_42 ) ;
V_36 -> V_43 = V_15 -> V_42 ;
return 0 ;
}
static void F_30 ( struct V_14 * V_15 , unsigned int V_44 ,
void * V_45 , unsigned int V_21 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
void * V_46 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
V_46 = & V_36 -> V_23 [ V_36 -> V_47 ] ;
if ( V_44 + V_21 > V_36 -> V_48 || V_44 + V_21 < V_21 ) {
F_14 ( & V_15 -> V_9 , L_7 ) ;
return;
}
memcpy ( V_45 , V_46 + V_44 , V_21 ) ;
}
static void F_31 ( struct V_14 * V_15 , unsigned int V_44 ,
const void * V_45 , unsigned int V_21 )
{
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_35 * V_36 ;
void * V_46 ;
V_36 = ( void * ) V_7 -> V_6 -> V_37 + V_7 -> V_38 ;
V_46 = & V_36 -> V_23 [ V_36 -> V_47 ] ;
if ( V_44 + V_21 > V_36 -> V_48 || V_44 + V_21 < V_21 ) {
F_14 ( & V_15 -> V_9 , L_8 ) ;
return;
}
memcpy ( V_46 + V_44 , V_45 , V_21 ) ;
}
static void F_32 ( struct V_19 * V_9 )
{
struct V_14 * V_15 = F_33 ( V_9 ) ;
struct V_18 * V_7 = F_8 ( V_15 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
F_34 ( & V_7 -> V_49 , V_50 ) ;
F_35 ( & V_6 -> V_9 ) ;
}
int F_36 ( struct V_18 * V_7 , int V_16 )
{
struct V_6 * V_6 = V_7 -> V_6 ;
struct V_19 * V_9 = & V_6 -> V_9 ;
struct V_14 * V_15 = & V_7 -> V_15 ;
int V_34 ;
V_15 -> V_16 . V_19 = V_16 ,
V_15 -> V_51 = & V_52 ,
V_15 -> V_9 . V_53 = V_9 ;
V_15 -> V_9 . V_54 = F_32 ;
F_37 ( & V_6 -> V_9 ) ;
F_38 ( & V_7 -> V_49 ) ;
V_34 = F_39 ( V_15 ) ;
if ( V_34 ) {
F_35 ( & V_6 -> V_9 ) ;
F_14 ( V_9 , L_9 , V_34 ) ;
goto V_55;
}
F_40 ( V_9 , L_10 , F_41 ( & V_15 -> V_9 ) , V_16 ) ;
V_55:
return V_34 ;
}
void F_42 ( struct V_18 * V_7 )
{
F_43 ( & V_7 -> V_15 ) ;
}
