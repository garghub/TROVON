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
const char * V_17 , bool V_18 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
struct V_20 * V_9 = & V_6 -> V_9 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
void * V_21 ;
int V_22 , V_23 ;
if ( V_16 >= F_10 ( V_7 -> V_24 ) )
return F_11 ( - V_25 ) ;
if ( ! V_17 )
return NULL ;
V_4 = & V_7 -> V_24 [ V_16 ] ;
V_21 = V_4 -> V_26 ;
V_22 = V_4 -> V_22 ;
V_23 = F_12 ( V_22 , V_4 -> V_27 ) ;
memset ( V_21 , 0 , V_23 ) ;
F_2 ( V_9 , L_3 ,
V_16 , V_21 , V_22 , V_4 -> V_8 ) ;
V_2 = F_13 ( V_16 , V_22 , V_4 -> V_27 , V_15 , false , V_18 ,
V_21 , F_1 , F_7 , V_17 ) ;
if ( ! V_2 ) {
F_14 ( V_9 , L_4 , V_17 ) ;
F_15 ( V_4 ) ;
return F_11 ( - V_28 ) ;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
return V_2 ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_29 ;
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
static int F_20 ( struct V_14 * V_15 , unsigned int V_30 ,
struct V_1 * V_31 [] ,
T_2 * V_32 [] ,
const char * const V_33 [] ,
const bool * V_18 ,
struct V_34 * V_35 )
{
int V_36 , V_37 ;
for ( V_36 = 0 ; V_36 < V_30 ; ++ V_36 ) {
V_31 [ V_36 ] = F_6 ( V_15 , V_36 , V_32 [ V_36 ] , V_33 [ V_36 ] ,
V_18 ? V_18 [ V_36 ] : false ) ;
if ( F_21 ( V_31 [ V_36 ] ) ) {
V_37 = F_22 ( V_31 [ V_36 ] ) ;
goto error;
}
}
return 0 ;
error:
F_16 ( V_15 ) ;
return V_37 ;
}
static T_3 F_23 ( struct V_14 * V_15 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
return V_39 -> V_42 ;
}
static void F_24 ( struct V_14 * V_15 , T_3 V_42 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
V_39 -> V_42 = V_42 ;
F_2 ( & V_15 -> V_9 , L_5 , V_42 ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
V_39 -> V_42 = 0 ;
F_2 ( & V_15 -> V_9 , L_6 ) ;
}
static T_4 F_26 ( struct V_14 * V_15 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
return V_39 -> V_43 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
F_28 ( V_15 ) ;
F_29 ( ( V_44 ) V_15 -> V_45 != V_15 -> V_45 ) ;
V_39 -> V_46 = V_15 -> V_45 ;
return 0 ;
}
static void F_30 ( struct V_14 * V_15 , unsigned int V_47 ,
void * V_48 , unsigned int V_22 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
void * V_49 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
V_49 = & V_39 -> V_24 [ V_39 -> V_50 ] ;
if ( V_47 + V_22 > V_39 -> V_51 || V_47 + V_22 < V_22 ) {
F_14 ( & V_15 -> V_9 , L_7 ) ;
return;
}
memcpy ( V_48 , V_49 + V_47 , V_22 ) ;
}
static void F_31 ( struct V_14 * V_15 , unsigned int V_47 ,
const void * V_48 , unsigned int V_22 )
{
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_38 * V_39 ;
void * V_49 ;
V_39 = ( void * ) V_7 -> V_6 -> V_40 + V_7 -> V_41 ;
V_49 = & V_39 -> V_24 [ V_39 -> V_50 ] ;
if ( V_47 + V_22 > V_39 -> V_51 || V_47 + V_22 < V_22 ) {
F_14 ( & V_15 -> V_9 , L_8 ) ;
return;
}
memcpy ( V_49 + V_47 , V_48 , V_22 ) ;
}
static void F_32 ( struct V_20 * V_9 )
{
struct V_14 * V_15 = F_33 ( V_9 ) ;
struct V_19 * V_7 = F_8 ( V_15 ) ;
struct V_6 * V_6 = F_9 ( V_15 ) ;
F_34 ( & V_7 -> V_52 , V_53 ) ;
F_35 ( & V_6 -> V_9 ) ;
}
int F_36 ( struct V_19 * V_7 , int V_16 )
{
struct V_6 * V_6 = V_7 -> V_6 ;
struct V_20 * V_9 = & V_6 -> V_9 ;
struct V_14 * V_15 = & V_7 -> V_15 ;
int V_37 ;
V_15 -> V_16 . V_20 = V_16 ,
V_15 -> V_54 = & V_55 ,
V_15 -> V_9 . V_56 = V_9 ;
V_15 -> V_9 . V_57 = F_32 ;
F_37 ( & V_6 -> V_9 ) ;
F_38 ( & V_7 -> V_52 ) ;
V_37 = F_39 ( V_15 ) ;
if ( V_37 ) {
F_35 ( & V_6 -> V_9 ) ;
F_14 ( V_9 , L_9 , V_37 ) ;
goto V_58;
}
F_40 ( V_9 , L_10 , F_41 ( & V_15 -> V_9 ) , V_16 ) ;
V_58:
return V_37 ;
}
void F_42 ( struct V_19 * V_7 )
{
F_43 ( & V_7 -> V_15 ) ;
}
