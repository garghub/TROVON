static void F_1 ( const struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_5 ) ;
struct V_10 * V_10 = & V_9 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_14 = V_9 -> V_14 ;
V_10 -> V_2 = V_2 ;
if ( ! V_2 ) {
F_3 ( V_7 , L_1 , V_14 -> V_15 ) ;
return;
}
V_9 -> V_16 =
F_4 ( V_7 , V_12 -> V_17 , - 1 ,
V_10 , sizeof( * V_10 ) ) ;
if ( F_5 ( V_9 -> V_16 ) ) {
F_3 ( V_7 , L_2 ,
V_12 -> V_17 , ( int ) F_6 ( V_9 -> V_16 ) ) ;
}
return;
}
static T_1 F_7 ( T_2 V_18 , T_3 V_19 ,
void * V_3 , void * * V_20 )
{
* ( bool * ) V_3 = true ;
return V_21 ;
}
static struct V_13 * F_8 (
struct V_13 * V_22 )
{
struct V_13 * V_14 ;
bool V_23 = false ;
for ( V_14 = V_22 ; V_14 -> V_24 [ 0 ] ; V_14 ++ )
if ( F_9 ( F_10 ( V_14 -> V_24 ,
F_7 ,
& V_23 , NULL ) ) && V_23 )
return V_14 ;
return NULL ;
}
static int F_11 ( struct V_4 * V_5 )
{
const struct V_25 * V_24 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
struct V_26 * V_27 ;
int V_20 = 0 ;
V_9 = F_12 ( V_7 , sizeof( * V_9 ) , V_28 ) ;
if ( V_9 == NULL )
return - V_29 ;
V_24 = F_13 ( V_7 -> V_30 -> V_31 , V_7 ) ;
if ( ! V_24 )
return - V_32 ;
V_12 = (struct V_11 * ) V_24 -> V_33 ;
V_14 = F_8 ( V_12 -> V_22 ) ;
if ( V_14 == NULL ) {
F_3 ( V_7 , L_3 ) ;
return - V_32 ;
}
V_10 = & V_9 -> V_10 ;
V_10 -> V_24 = V_12 -> V_34 ;
V_10 -> V_35 = V_7 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_14 = V_14 ;
if ( V_12 -> V_36 >= 0 ) {
V_10 -> V_37 = V_12 -> V_37 ;
V_10 -> V_38 = V_12 -> V_36 ;
V_10 -> V_39 = V_12 -> V_39 ;
}
if ( V_12 -> V_40 >= 0 )
V_10 -> V_41 = F_14 ( V_5 , V_12 -> V_40 ) ;
if ( V_12 -> V_42 >= 0 ) {
V_27 = F_15 ( V_5 , V_43 ,
V_12 -> V_42 ) ;
if ( V_27 ) {
V_10 -> V_44 = V_27 -> V_45 ;
V_10 -> V_46 = F_16 ( V_27 ) ;
}
}
if ( V_12 -> V_47 >= 0 ) {
V_27 = F_15 ( V_5 , V_43 ,
V_12 -> V_47 ) ;
if ( V_27 ) {
V_10 -> V_48 = V_27 -> V_45 ;
V_10 -> V_49 = F_16 ( V_27 ) ;
}
}
if ( V_12 -> V_50 >= 0 ) {
V_27 = F_15 ( V_5 , V_43 ,
V_12 -> V_50 ) ;
if ( V_27 ) {
V_10 -> V_51 = V_27 -> V_45 ;
V_10 -> V_52 = F_16 ( V_27 ) ;
}
}
F_17 ( V_5 , V_9 ) ;
V_9 -> V_53 =
F_4 ( V_7 , V_14 -> V_17 , - 1 ,
V_10 , sizeof( * V_10 ) ) ;
if ( F_5 ( V_9 -> V_53 ) )
return F_6 ( V_9 -> V_53 ) ;
V_20 = F_18 ( V_54 , true , V_14 -> V_15 ,
V_7 , V_28 , V_5 , F_1 ) ;
if ( V_20 )
F_19 ( V_9 -> V_53 ) ;
return V_20 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) ;
struct V_10 * V_10 = & V_9 -> V_10 ;
F_19 ( V_9 -> V_53 ) ;
if ( ! F_21 ( V_9 -> V_16 ) )
F_19 ( V_9 -> V_16 ) ;
F_22 ( V_10 -> V_2 ) ;
return 0 ;
}
