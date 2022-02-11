static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
T_1 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 -> V_11 -> V_12 ;
T_2 * V_13 = V_9 -> V_13 ;
struct V_14 * V_15 ;
unsigned V_16 , V_17 ;
unsigned V_18 ;
unsigned V_19 ;
unsigned V_20 ;
int V_21 ;
V_16 = V_6 -> V_22 ;
V_17 = V_23 ;
V_18 = V_4 -> V_18 >> V_16 ;
V_19 = ( V_4 -> V_18 + V_4 -> V_24 - 1 ) >> V_16 ;
V_21 = ++ V_13 -> V_25 ;
V_15 = V_13 -> V_26 ;
for ( V_20 = V_18 ; V_20 <= V_19 ; V_20 ++ ) {
V_15 [ V_20 ] . V_5 = V_5 ;
V_15 [ V_20 ] . V_21 = V_21 ;
V_15 [ ( unsigned ) V_15 [ V_20 ] . V_27 ] . V_28 = V_15 [ V_20 ] . V_28 ;
V_15 [ ( unsigned ) V_15 [ V_20 ] . V_28 ] . V_27 = V_15 [ V_20 ] . V_27 ;
V_15 [ V_20 ] . V_28 = V_17 ;
V_15 [ V_20 ] . V_27 = V_15 [ V_17 ] . V_27 ;
V_15 [ ( unsigned ) V_15 [ V_17 ] . V_27 ] . V_28 = V_20 ;
V_15 [ V_17 ] . V_27 = V_20 ;
}
}
static struct V_3 * F_2 ( struct V_3 * V_4 , int V_18 , int V_24 ,
struct V_29 * V_30 )
{
if ( V_18 > V_4 -> V_18 ) {
struct V_3 * V_31 = F_3 ( sizeof( * V_31 ) ,
V_32 ) ;
if ( ! V_31 )
goto V_33;
V_31 -> V_18 = V_18 ;
V_31 -> V_24 = V_4 -> V_24 - ( V_18 - V_4 -> V_18 ) ;
V_31 -> V_30 = NULL ;
V_31 -> V_27 = V_4 -> V_27 ;
V_31 -> V_28 = V_4 ;
V_4 -> V_27 -> V_28 = V_31 ;
V_4 -> V_27 = V_31 ;
V_4 -> V_24 -= V_31 -> V_24 ;
V_4 = V_31 ;
}
if ( V_24 < V_4 -> V_24 ) {
struct V_3 * V_31 = F_3 ( sizeof( * V_31 ) ,
V_32 ) ;
if ( ! V_31 )
goto V_33;
V_31 -> V_18 = V_18 + V_24 ;
V_31 -> V_24 = V_4 -> V_24 - V_24 ;
V_31 -> V_30 = NULL ;
V_31 -> V_27 = V_4 -> V_27 ;
V_31 -> V_28 = V_4 ;
V_4 -> V_27 -> V_28 = V_31 ;
V_4 -> V_27 = V_31 ;
V_4 -> V_24 = V_24 ;
}
V_33:
V_4 -> V_30 = V_30 ;
return V_4 ;
}
static struct V_3 * F_4 ( struct V_3 * V_34 , int V_24 ,
int V_35 , struct V_29 * V_30 )
{
struct V_3 * V_4 ;
int V_36 = ( 1 << V_35 ) - 1 ;
for ( V_4 = V_34 -> V_27 ; V_4 != V_34 ; V_4 = V_4 -> V_27 ) {
int V_18 = ( V_4 -> V_18 + V_36 ) & ~ V_36 ;
if ( V_4 -> V_30 == NULL && V_18 + V_24 <= V_4 -> V_18 + V_4 -> V_24 )
return F_2 ( V_4 , V_18 , V_24 , V_30 ) ;
}
return NULL ;
}
static struct V_3 * F_5 ( struct V_3 * V_34 , int V_18 )
{
struct V_3 * V_4 ;
for ( V_4 = V_34 -> V_27 ; V_4 != V_34 ; V_4 = V_4 -> V_27 )
if ( V_4 -> V_18 == V_18 )
return V_4 ;
return NULL ;
}
static void F_6 ( struct V_3 * V_4 )
{
V_4 -> V_30 = NULL ;
if ( V_4 -> V_27 -> V_30 == NULL ) {
struct V_3 * V_37 = V_4 -> V_27 ;
V_4 -> V_24 += V_37 -> V_24 ;
V_4 -> V_27 = V_37 -> V_27 ;
V_4 -> V_27 -> V_28 = V_4 ;
F_7 ( V_37 ) ;
}
if ( V_4 -> V_28 -> V_30 == NULL ) {
struct V_3 * V_37 = V_4 -> V_28 ;
V_37 -> V_24 += V_4 -> V_24 ;
V_37 -> V_27 = V_4 -> V_27 ;
V_37 -> V_27 -> V_28 = V_37 ;
F_7 ( V_4 ) ;
}
}
static int F_8 ( struct V_3 * * V_34 , int V_18 , int V_24 )
{
struct V_3 * V_38 = F_3 ( sizeof( * V_38 ) , V_32 ) ;
if ( ! V_38 )
return - V_39 ;
* V_34 = F_3 ( sizeof( * * V_34 ) , V_32 ) ;
if ( ! * V_34 ) {
F_7 ( V_38 ) ;
return - V_39 ;
}
V_38 -> V_18 = V_18 ;
V_38 -> V_24 = V_24 ;
V_38 -> V_30 = NULL ;
V_38 -> V_27 = V_38 -> V_28 = * V_34 ;
memset ( * V_34 , 0 , sizeof( * * V_34 ) ) ;
( * V_34 ) -> V_30 = (struct V_29 * ) - 1 ;
( * V_34 ) -> V_27 = ( * V_34 ) -> V_28 = V_38 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_3 * V_34 )
{
struct V_3 * V_4 ;
if ( ! V_34 || ! V_34 -> V_27 )
return;
for ( V_4 = V_34 -> V_27 ; V_4 != V_34 ; V_4 = V_4 -> V_27 ) {
if ( V_4 -> V_30 == V_30 ) {
V_4 -> V_30 = NULL ;
F_1 ( V_2 , V_4 , 0 ) ;
}
}
for ( V_4 = V_34 -> V_27 ; V_4 != V_34 ; V_4 = V_4 -> V_27 ) {
while ( V_4 -> V_30 == NULL && V_4 -> V_27 -> V_30 == NULL ) {
struct V_3 * V_37 = V_4 -> V_27 ;
V_4 -> V_24 += V_37 -> V_24 ;
V_4 -> V_27 = V_37 -> V_27 ;
V_4 -> V_27 -> V_28 = V_4 ;
F_7 ( V_37 ) ;
}
}
}
void F_10 ( struct V_3 * * V_34 )
{
struct V_3 * V_4 ;
if ( ! * V_34 )
return;
for ( V_4 = ( * V_34 ) -> V_27 ; V_4 != * V_34 ; ) {
struct V_3 * V_37 = V_4 ;
V_4 = V_4 -> V_27 ;
F_7 ( V_37 ) ;
}
F_7 ( * V_34 ) ;
* V_34 = NULL ;
}
static struct V_3 * * F_11 ( T_1 * V_6 , int V_40 )
{
switch ( V_40 ) {
case V_41 :
return & V_6 -> V_42 ;
default:
return NULL ;
}
}
int F_12 ( struct V_1 * V_2 , void * V_43 ,
struct V_29 * V_30 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_3 * V_44 = V_43 ;
struct V_3 * V_45 , * * V_34 ;
if ( ! V_6 ) {
F_13 ( L_1 ) ;
return - V_46 ;
}
V_34 = F_11 ( V_6 , V_44 -> V_40 ) ;
if ( ! V_34 || ! * V_34 )
return - V_47 ;
if ( V_44 -> V_48 < 12 )
V_44 -> V_48 = 12 ;
V_45 = F_4 ( * V_34 , V_44 -> V_24 , V_44 -> V_48 , V_30 ) ;
if ( ! V_45 )
return - V_39 ;
F_1 ( V_2 , V_45 , 1 ) ;
if ( F_14 ( V_44 -> V_49 , & V_45 -> V_18 ,
sizeof( int ) ) ) {
F_13 ( L_2 ) ;
return - V_47 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , void * V_43 ,
struct V_29 * V_30 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_4 * V_50 = V_43 ;
struct V_3 * V_45 , * * V_34 ;
if ( ! V_6 ) {
F_13 ( L_1 ) ;
return - V_46 ;
}
V_34 = F_11 ( V_6 , V_50 -> V_40 ) ;
if ( ! V_34 || ! * V_34 )
return - V_47 ;
V_45 = F_5 ( * V_34 , V_50 -> V_49 ) ;
if ( ! V_45 )
return - V_47 ;
if ( V_45 -> V_30 != V_30 )
return - V_51 ;
F_1 ( V_2 , V_45 , 0 ) ;
F_6 ( V_45 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , void * V_43 ,
struct V_29 * V_30 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_5 * V_52 = V_43 ;
struct V_3 * * V_34 ;
if ( ! V_6 ) {
F_13 ( L_1 ) ;
return - V_46 ;
}
V_34 = F_11 ( V_6 , V_52 -> V_40 ) ;
if ( ! V_34 )
return - V_47 ;
if ( * V_34 ) {
F_13 ( L_3 ) ;
return - V_47 ;
}
return F_8 ( V_34 , V_52 -> V_18 , V_52 -> V_24 ) ;
}
int F_17 ( struct V_1 * V_2 , void * V_43 ,
struct V_29 * V_30 )
{
T_1 * V_6 = V_2 -> V_7 ;
T_6 * V_53 = V_43 ;
struct V_3 * * V_34 ;
if ( ! V_6 ) {
F_13 ( L_1 ) ;
return - V_46 ;
}
V_34 = F_11 ( V_6 , V_53 -> V_40 ) ;
if ( ! V_34 ) {
F_13 ( L_4 ) ;
return - V_47 ;
}
if ( ! * V_34 ) {
F_13 ( L_5 ) ;
return - V_47 ;
}
F_10 ( V_34 ) ;
return 0 ;
}
