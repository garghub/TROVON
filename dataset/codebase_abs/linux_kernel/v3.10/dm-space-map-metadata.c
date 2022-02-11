static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
V_2 -> V_4 = false ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_5 ,
T_2 V_6 , void * V_7 )
{
V_2 -> V_3 = true ;
V_2 -> V_1 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
}
static bool F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
return V_2 -> V_3 && V_5 <= V_2 -> V_1 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_4 && F_3 ( V_2 , V_2 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( F_3 ( V_2 , V_5 ) &&
! F_4 ( V_2 ) )
V_2 -> V_6 ( V_2 -> V_7 ) ;
V_2 -> V_4 = true ;
V_2 -> V_8 = V_5 ;
}
static int F_6 ( struct V_9 * V_10 , enum V_11 type , T_1 V_12 )
{
struct V_13 * V_14 ;
if ( V_10 -> V_15 == V_16 ) {
F_7 ( L_1 ) ;
return - V_17 ;
}
V_14 = V_10 -> V_18 + V_10 -> V_15 ++ ;
V_14 -> type = type ;
V_14 -> V_19 = V_12 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 , struct V_13 * V_14 )
{
int V_20 = 0 ;
enum V_21 V_22 ;
switch ( V_14 -> type ) {
case V_23 :
V_20 = F_9 ( & V_10 -> V_24 , V_14 -> V_19 , & V_22 ) ;
break;
case V_25 :
V_20 = F_10 ( & V_10 -> V_24 , V_14 -> V_19 , & V_22 ) ;
break;
}
return V_20 ;
}
static void F_11 ( struct V_9 * V_10 )
{
V_10 -> V_26 ++ ;
}
static int F_12 ( struct V_9 * V_10 )
{
int V_20 = 0 ;
if ( ! V_10 -> V_26 ) {
F_7 ( L_2 ) ;
return - V_17 ;
}
if ( V_10 -> V_26 == 1 && V_10 -> V_15 ) {
while ( V_10 -> V_15 && ! V_20 ) {
V_10 -> V_15 -- ;
V_20 = F_8 ( V_10 , V_10 -> V_18 +
V_10 -> V_15 ) ;
if ( V_20 )
break;
}
}
V_10 -> V_26 -- ;
return V_20 ;
}
static int F_13 ( int V_27 , int V_28 )
{
return V_27 ? V_27 : V_28 ;
}
static int F_14 ( struct V_9 * V_10 )
{
return V_10 -> V_26 ;
}
static void F_15 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
F_17 ( V_10 ) ;
}
static int F_18 ( struct V_29 * V_30 , T_1 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
* V_31 = V_10 -> V_24 . V_32 ;
return 0 ;
}
static int F_19 ( struct V_29 * V_30 , T_1 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
* V_31 = V_10 -> V_33 . V_32 - V_10 -> V_33 . V_34 -
V_10 -> V_35 ;
return 0 ;
}
static int F_20 ( struct V_29 * V_30 , T_1 V_12 ,
T_3 * V_36 )
{
int V_20 , V_37 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
unsigned V_38 = 0 ;
for ( V_37 = 0 ; V_37 < V_10 -> V_15 ; V_37 ++ ) {
struct V_13 * V_14 = V_10 -> V_18 + V_37 ;
if ( V_14 -> V_19 != V_12 )
continue;
switch ( V_14 -> type ) {
case V_23 :
V_38 ++ ;
break;
case V_25 :
V_38 -- ;
break;
}
}
V_20 = F_21 ( & V_10 -> V_24 , V_12 , V_36 ) ;
if ( V_20 )
return V_20 ;
* V_36 += V_38 ;
return 0 ;
}
static int F_22 ( struct V_29 * V_30 ,
T_1 V_12 , int * V_36 )
{
int V_20 , V_37 , V_38 = 0 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
T_3 V_39 ;
for ( V_37 = 0 ; V_37 < V_10 -> V_15 ; V_37 ++ ) {
struct V_13 * V_14 = V_10 -> V_18 + V_37 ;
if ( V_14 -> V_19 != V_12 )
continue;
switch ( V_14 -> type ) {
case V_23 :
V_38 ++ ;
break;
case V_25 :
V_38 -- ;
break;
}
}
if ( V_38 > 1 ) {
* V_36 = 1 ;
return 0 ;
}
V_20 = F_23 ( & V_10 -> V_24 , V_12 , & V_39 ) ;
if ( V_20 )
return V_20 ;
if ( V_39 == 3 )
* V_36 = 1 ;
else
* V_36 = V_39 + V_38 > 1 ;
return 0 ;
}
static int F_24 ( struct V_29 * V_30 , T_1 V_12 ,
T_3 V_31 )
{
int V_20 , V_28 ;
enum V_21 V_22 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
if ( V_10 -> V_26 ) {
F_7 ( L_3 ) ;
return - V_40 ;
}
F_11 ( V_10 ) ;
V_20 = F_25 ( & V_10 -> V_24 , V_12 , V_31 , & V_22 ) ;
V_28 = F_12 ( V_10 ) ;
return F_13 ( V_20 , V_28 ) ;
}
static int F_26 ( struct V_29 * V_30 , T_1 V_12 )
{
int V_20 , V_28 = 0 ;
enum V_21 V_22 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
if ( F_14 ( V_10 ) )
V_20 = F_6 ( V_10 , V_23 , V_12 ) ;
else {
F_11 ( V_10 ) ;
V_20 = F_9 ( & V_10 -> V_24 , V_12 , & V_22 ) ;
V_28 = F_12 ( V_10 ) ;
}
return F_13 ( V_20 , V_28 ) ;
}
static int F_27 ( struct V_29 * V_30 , T_1 V_12 )
{
int V_20 , V_28 = 0 ;
enum V_21 V_22 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
if ( F_14 ( V_10 ) )
V_20 = F_6 ( V_10 , V_25 , V_12 ) ;
else {
F_11 ( V_10 ) ;
V_20 = F_10 ( & V_10 -> V_24 , V_12 , & V_22 ) ;
V_28 = F_12 ( V_10 ) ;
}
return F_13 ( V_20 , V_28 ) ;
}
static int F_28 ( struct V_29 * V_30 , T_1 * V_12 )
{
int V_20 , V_28 = 0 ;
enum V_21 V_22 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
V_20 = F_29 ( & V_10 -> V_33 , V_10 -> V_41 , V_10 -> V_33 . V_32 , V_12 ) ;
if ( V_20 )
return V_20 ;
V_10 -> V_41 = * V_12 + 1 ;
if ( F_14 ( V_10 ) )
V_20 = F_6 ( V_10 , V_23 , * V_12 ) ;
else {
F_11 ( V_10 ) ;
V_20 = F_9 ( & V_10 -> V_24 , * V_12 , & V_22 ) ;
V_28 = F_12 ( V_10 ) ;
}
if ( ! V_20 )
V_10 -> V_35 ++ ;
return F_13 ( V_20 , V_28 ) ;
}
static int F_30 ( struct V_29 * V_30 , T_1 * V_12 )
{
T_1 V_31 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
int V_20 = F_28 ( V_30 , V_12 ) ;
if ( V_20 )
F_7 ( L_4 ) ;
V_20 = F_19 ( V_30 , & V_31 ) ;
if ( V_20 )
F_7 ( L_5 ) ;
F_5 ( & V_10 -> V_1 , V_31 ) ;
return V_20 ;
}
static int F_31 ( struct V_29 * V_30 )
{
int V_20 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
V_20 = F_32 ( & V_10 -> V_24 ) ;
if ( V_20 )
return V_20 ;
memcpy ( & V_10 -> V_33 , & V_10 -> V_24 , sizeof( V_10 -> V_33 ) ) ;
V_10 -> V_41 = 0 ;
V_10 -> V_35 = 0 ;
return 0 ;
}
static int F_33 ( struct V_29 * V_30 ,
T_1 V_1 ,
T_2 V_6 ,
void * V_7 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
F_2 ( & V_10 -> V_1 , V_1 , V_6 , V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_29 * V_30 , T_4 * V_36 )
{
* V_36 = sizeof( struct V_42 ) ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , void * V_43 , T_4 V_44 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
struct V_42 V_45 ;
V_45 . V_32 = F_36 ( V_10 -> V_24 . V_32 ) ;
V_45 . V_34 = F_36 ( V_10 -> V_24 . V_34 ) ;
V_45 . V_46 = F_36 ( V_10 -> V_24 . V_46 ) ;
V_45 . V_47 = F_36 ( V_10 -> V_24 . V_47 ) ;
if ( V_44 < sizeof( V_45 ) )
return - V_48 ;
memcpy ( V_43 , & V_45 , sizeof( V_45 ) ) ;
return 0 ;
}
static void F_37 ( struct V_29 * V_30 )
{
}
static int F_38 ( struct V_29 * V_30 , T_1 V_49 )
{
F_7 ( L_6 ) ;
return - V_40 ;
}
static int F_39 ( struct V_29 * V_30 , T_1 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
return V_10 -> V_24 . V_32 ;
}
static int F_40 ( struct V_29 * V_30 , T_1 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
* V_31 = V_10 -> V_24 . V_32 - V_10 -> V_41 ;
return 0 ;
}
static int F_41 ( struct V_29 * V_30 , T_1 V_12 ,
T_3 * V_36 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
return V_12 < V_10 -> V_41 ? 1 : 0 ;
}
static int F_42 ( struct V_29 * V_30 ,
T_1 V_12 , int * V_36 )
{
* V_36 = 0 ;
return 0 ;
}
static int F_43 ( struct V_29 * V_30 , T_1 V_12 ,
T_3 V_31 )
{
F_7 ( L_7 ) ;
return - V_40 ;
}
static int F_44 ( struct V_29 * V_30 , T_1 * V_12 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
if ( V_10 -> V_41 == V_10 -> V_24 . V_32 )
return - V_48 ;
* V_12 = V_10 -> V_41 ++ ;
return 0 ;
}
static int F_45 ( struct V_29 * V_30 , T_1 V_12 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
return F_6 ( V_10 , V_23 , V_12 ) ;
}
static int F_46 ( struct V_29 * V_30 , T_1 V_12 )
{
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
return F_6 ( V_10 , V_25 , V_12 ) ;
}
static int F_47 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_48 ( struct V_29 * V_30 , T_4 * V_36 )
{
F_7 ( L_8 ) ;
return - V_40 ;
}
static int F_49 ( struct V_29 * V_30 , void * V_50 ,
T_4 V_44 )
{
F_7 ( L_9 ) ;
return - V_40 ;
}
static int F_50 ( struct V_29 * V_30 , T_1 V_49 )
{
int V_20 , V_37 ;
enum V_21 V_22 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
T_1 V_51 = V_10 -> V_24 . V_32 ;
V_10 -> V_41 = V_51 ;
memcpy ( & V_10 -> V_30 , & V_52 , sizeof( V_10 -> V_30 ) ) ;
V_20 = F_51 ( & V_10 -> V_24 , V_49 ) ;
memcpy ( & V_10 -> V_30 , & V_53 , sizeof( V_10 -> V_30 ) ) ;
for ( V_37 = V_51 ; ! V_20 && V_37 < V_10 -> V_41 ; V_37 ++ )
V_20 = F_9 ( & V_10 -> V_24 , V_37 , & V_22 ) ;
return V_20 ;
}
struct V_29 * F_52 ( void )
{
struct V_9 * V_10 ;
V_10 = F_53 ( sizeof( * V_10 ) , V_54 ) ;
if ( ! V_10 )
return F_54 ( - V_17 ) ;
memcpy ( & V_10 -> V_30 , & V_53 , sizeof( V_10 -> V_30 ) ) ;
return & V_10 -> V_30 ;
}
int F_55 ( struct V_29 * V_30 ,
struct V_55 * V_56 ,
T_1 V_32 ,
T_1 V_57 )
{
int V_20 ;
T_1 V_37 ;
enum V_21 V_22 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
V_10 -> V_41 = V_57 + 1 ;
V_10 -> V_26 = 0 ;
V_10 -> V_35 = 0 ;
V_10 -> V_15 = 0 ;
F_1 ( & V_10 -> V_1 ) ;
memcpy ( & V_10 -> V_30 , & V_52 , sizeof( V_10 -> V_30 ) ) ;
V_20 = F_56 ( & V_10 -> V_24 , V_56 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_51 ( & V_10 -> V_24 , V_32 ) ;
if ( V_20 )
return V_20 ;
memcpy ( & V_10 -> V_30 , & V_53 , sizeof( V_10 -> V_30 ) ) ;
for ( V_37 = V_57 ; ! V_20 && V_37 < V_10 -> V_41 ; V_37 ++ )
V_20 = F_9 ( & V_10 -> V_24 , V_37 , & V_22 ) ;
if ( V_20 )
return V_20 ;
return F_31 ( V_30 ) ;
}
int F_57 ( struct V_29 * V_30 ,
struct V_55 * V_56 ,
void * V_45 , T_4 V_58 )
{
int V_20 ;
struct V_9 * V_10 = F_16 ( V_30 , struct V_9 , V_30 ) ;
V_20 = F_58 ( & V_10 -> V_24 , V_56 , V_45 , V_58 ) ;
if ( V_20 )
return V_20 ;
V_10 -> V_41 = 0 ;
V_10 -> V_26 = 0 ;
V_10 -> V_35 = 0 ;
V_10 -> V_15 = 0 ;
F_1 ( & V_10 -> V_1 ) ;
memcpy ( & V_10 -> V_33 , & V_10 -> V_24 , sizeof( V_10 -> V_33 ) ) ;
return 0 ;
}
