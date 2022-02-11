static int F_1 ( struct V_1 * V_2 , enum V_3 type , T_1 V_4 )
{
struct V_5 * V_6 ;
if ( V_2 -> V_7 == V_8 ) {
F_2 ( L_1 ) ;
return - V_9 ;
}
V_6 = V_2 -> V_10 + V_2 -> V_7 ++ ;
V_6 -> type = type ;
V_6 -> V_11 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_12 = 0 ;
enum V_13 V_14 ;
switch ( V_6 -> type ) {
case V_15 :
V_12 = F_4 ( & V_2 -> V_16 , V_6 -> V_11 , & V_14 ) ;
break;
case V_17 :
V_12 = F_5 ( & V_2 -> V_16 , V_6 -> V_11 , & V_14 ) ;
break;
}
return V_12 ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_18 ++ ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
if ( ! V_2 -> V_18 ) {
F_2 ( L_2 ) ;
return - V_9 ;
}
if ( V_2 -> V_18 == 1 && V_2 -> V_7 ) {
while ( V_2 -> V_7 && ! V_12 ) {
V_2 -> V_7 -- ;
V_12 = F_3 ( V_2 , V_2 -> V_10 +
V_2 -> V_7 ) ;
if ( V_12 )
break;
}
}
V_2 -> V_18 -- ;
return V_12 ;
}
static int F_8 ( int V_19 , int V_20 )
{
return V_19 ? V_19 : V_20 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_18 ;
}
static void F_10 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_21 * V_22 , T_1 V_23 )
{
F_2 ( L_3 ) ;
return - V_24 ;
}
static int F_14 ( struct V_21 * V_22 , T_1 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
* V_25 = V_2 -> V_16 . V_26 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , T_1 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
* V_25 = V_2 -> V_27 . V_26 - V_2 -> V_27 . V_28 -
V_2 -> V_29 ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 , T_1 V_4 ,
T_2 * V_30 )
{
int V_12 , V_31 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
unsigned V_32 = 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; V_31 ++ ) {
struct V_5 * V_6 = V_2 -> V_10 + V_31 ;
if ( V_6 -> V_11 != V_4 )
continue;
switch ( V_6 -> type ) {
case V_15 :
V_32 ++ ;
break;
case V_17 :
V_32 -- ;
break;
}
}
V_12 = F_17 ( & V_2 -> V_16 , V_4 , V_30 ) ;
if ( V_12 )
return V_12 ;
* V_30 += V_32 ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
T_1 V_4 , int * V_30 )
{
int V_12 , V_31 , V_32 = 0 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
T_2 V_33 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; V_31 ++ ) {
struct V_5 * V_6 = V_2 -> V_10 + V_31 ;
if ( V_6 -> V_11 != V_4 )
continue;
switch ( V_6 -> type ) {
case V_15 :
V_32 ++ ;
break;
case V_17 :
V_32 -- ;
break;
}
}
if ( V_32 > 1 ) {
* V_30 = 1 ;
return 0 ;
}
V_12 = F_19 ( & V_2 -> V_16 , V_4 , & V_33 ) ;
if ( V_12 )
return V_12 ;
if ( V_33 == 3 )
* V_30 = 1 ;
else
* V_30 = V_33 + V_32 > 1 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 , T_1 V_4 ,
T_2 V_25 )
{
int V_12 , V_20 ;
enum V_13 V_14 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
if ( V_2 -> V_18 ) {
F_2 ( L_4 ) ;
return - V_24 ;
}
F_6 ( V_2 ) ;
V_12 = F_21 ( & V_2 -> V_16 , V_4 , V_25 , & V_14 ) ;
V_20 = F_7 ( V_2 ) ;
return F_8 ( V_12 , V_20 ) ;
}
static int F_22 ( struct V_21 * V_22 , T_1 V_4 )
{
int V_12 , V_20 = 0 ;
enum V_13 V_14 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
if ( F_9 ( V_2 ) )
V_12 = F_1 ( V_2 , V_15 , V_4 ) ;
else {
F_6 ( V_2 ) ;
V_12 = F_4 ( & V_2 -> V_16 , V_4 , & V_14 ) ;
V_20 = F_7 ( V_2 ) ;
}
return F_8 ( V_12 , V_20 ) ;
}
static int F_23 ( struct V_21 * V_22 , T_1 V_4 )
{
int V_12 , V_20 = 0 ;
enum V_13 V_14 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
if ( F_9 ( V_2 ) )
V_12 = F_1 ( V_2 , V_17 , V_4 ) ;
else {
F_6 ( V_2 ) ;
V_12 = F_5 ( & V_2 -> V_16 , V_4 , & V_14 ) ;
V_20 = F_7 ( V_2 ) ;
}
return F_8 ( V_12 , V_20 ) ;
}
static int F_24 ( struct V_21 * V_22 , T_1 * V_4 )
{
int V_12 , V_20 = 0 ;
enum V_13 V_14 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
V_12 = F_25 ( & V_2 -> V_27 , V_2 -> V_34 , V_2 -> V_27 . V_26 , V_4 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_34 = * V_4 + 1 ;
if ( F_9 ( V_2 ) )
V_12 = F_1 ( V_2 , V_15 , * V_4 ) ;
else {
F_6 ( V_2 ) ;
V_12 = F_4 ( & V_2 -> V_16 , * V_4 , & V_14 ) ;
V_20 = F_7 ( V_2 ) ;
}
if ( ! V_12 )
V_2 -> V_29 ++ ;
return F_8 ( V_12 , V_20 ) ;
}
static int F_26 ( struct V_21 * V_22 , T_1 * V_4 )
{
int V_12 = F_24 ( V_22 , V_4 ) ;
if ( V_12 )
F_2 ( L_5 ) ;
return V_12 ;
}
static int F_27 ( struct V_21 * V_22 )
{
int V_12 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
V_12 = F_28 ( & V_2 -> V_16 ) ;
if ( V_12 )
return V_12 ;
memcpy ( & V_2 -> V_27 , & V_2 -> V_16 , sizeof( V_2 -> V_27 ) ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_29 = 0 ;
return 0 ;
}
static int F_29 ( struct V_21 * V_22 , T_3 * V_30 )
{
* V_30 = sizeof( struct V_35 ) ;
return 0 ;
}
static int F_30 ( struct V_21 * V_22 , void * V_36 , T_3 V_37 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
struct V_35 V_38 ;
V_38 . V_26 = F_31 ( V_2 -> V_16 . V_26 ) ;
V_38 . V_28 = F_31 ( V_2 -> V_16 . V_28 ) ;
V_38 . V_39 = F_31 ( V_2 -> V_16 . V_39 ) ;
V_38 . V_40 = F_31 ( V_2 -> V_16 . V_40 ) ;
if ( V_37 < sizeof( V_38 ) )
return - V_41 ;
memcpy ( V_36 , & V_38 , sizeof( V_38 ) ) ;
return 0 ;
}
static void F_32 ( struct V_21 * V_22 )
{
}
static int F_33 ( struct V_21 * V_22 , T_1 V_23 )
{
F_2 ( L_6 ) ;
return - V_24 ;
}
static int F_34 ( struct V_21 * V_22 , T_1 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
return V_2 -> V_16 . V_26 ;
}
static int F_35 ( struct V_21 * V_22 , T_1 * V_25 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
* V_25 = V_2 -> V_16 . V_26 - V_2 -> V_34 ;
return 0 ;
}
static int F_36 ( struct V_21 * V_22 , T_1 V_4 ,
T_2 * V_30 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
return V_4 < V_2 -> V_34 ? 1 : 0 ;
}
static int F_37 ( struct V_21 * V_22 ,
T_1 V_4 , int * V_30 )
{
* V_30 = 0 ;
return 0 ;
}
static int F_38 ( struct V_21 * V_22 , T_1 V_4 ,
T_2 V_25 )
{
F_2 ( L_7 ) ;
return - V_24 ;
}
static int F_39 ( struct V_21 * V_22 , T_1 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
if ( V_2 -> V_34 == V_2 -> V_16 . V_26 )
return - V_41 ;
* V_4 = V_2 -> V_34 ++ ;
return 0 ;
}
static int F_40 ( struct V_21 * V_22 , T_1 V_4 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
return F_1 ( V_2 , V_15 , V_4 ) ;
}
static int F_41 ( struct V_21 * V_22 , T_1 V_4 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
return F_1 ( V_2 , V_17 , V_4 ) ;
}
static int F_42 ( struct V_21 * V_22 )
{
return 0 ;
}
static int F_43 ( struct V_21 * V_22 , T_3 * V_30 )
{
F_2 ( L_8 ) ;
return - V_24 ;
}
static int F_44 ( struct V_21 * V_22 , void * V_42 ,
T_3 V_37 )
{
F_2 ( L_9 ) ;
return - V_24 ;
}
struct V_21 * F_45 ( void )
{
struct V_1 * V_2 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return F_47 ( - V_9 ) ;
memcpy ( & V_2 -> V_22 , & V_44 , sizeof( V_2 -> V_22 ) ) ;
return & V_2 -> V_22 ;
}
int F_48 ( struct V_21 * V_22 ,
struct V_45 * V_46 ,
T_1 V_26 ,
T_1 V_47 )
{
int V_12 ;
T_1 V_31 ;
enum V_13 V_14 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
V_2 -> V_34 = V_47 + 1 ;
V_2 -> V_18 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_7 = 0 ;
memcpy ( & V_2 -> V_22 , & V_48 , sizeof( V_2 -> V_22 ) ) ;
V_12 = F_49 ( & V_2 -> V_16 , V_46 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_50 ( & V_2 -> V_16 , V_26 ) ;
if ( V_12 )
return V_12 ;
memcpy ( & V_2 -> V_22 , & V_44 , sizeof( V_2 -> V_22 ) ) ;
for ( V_31 = V_47 ; ! V_12 && V_31 < V_2 -> V_34 ; V_31 ++ )
V_12 = F_4 ( & V_2 -> V_16 , V_31 , & V_14 ) ;
if ( V_12 )
return V_12 ;
return F_27 ( V_22 ) ;
}
int F_51 ( struct V_21 * V_22 ,
struct V_45 * V_46 ,
void * V_38 , T_3 V_49 )
{
int V_12 ;
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_22 ) ;
V_12 = F_52 ( & V_2 -> V_16 , V_46 , V_38 , V_49 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_34 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_7 = 0 ;
memcpy ( & V_2 -> V_27 , & V_2 -> V_16 , sizeof( V_2 -> V_27 ) ) ;
return 0 ;
}
