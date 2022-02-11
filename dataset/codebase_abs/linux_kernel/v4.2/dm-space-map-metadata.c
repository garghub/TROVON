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
static void F_6 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
static bool F_7 ( struct V_9 * V_10 )
{
return V_10 -> V_11 == V_10 -> V_12 ;
}
static unsigned F_8 ( struct V_9 * V_10 , unsigned V_13 )
{
unsigned V_14 = V_13 + 1 ;
return ( V_14 >= ( sizeof( V_10 -> V_15 ) / sizeof( * V_10 -> V_15 ) ) ) ? 0 : V_14 ;
}
static int F_9 ( struct V_9 * V_10 ,
enum V_16 type , T_1 V_17 )
{
struct V_18 * V_19 ;
unsigned V_20 = F_8 ( V_10 , V_10 -> V_12 ) ;
if ( V_20 == V_10 -> V_11 )
return - V_21 ;
V_19 = V_10 -> V_15 + V_10 -> V_12 ;
V_19 -> type = type ;
V_19 -> V_22 = V_17 ;
V_10 -> V_12 = V_20 ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_18 * V_23 )
{
struct V_18 * V_19 ;
if ( F_7 ( V_10 ) )
return - V_24 ;
V_19 = V_10 -> V_15 + V_10 -> V_11 ;
V_23 -> type = V_19 -> type ;
V_23 -> V_22 = V_19 -> V_22 ;
V_10 -> V_11 = F_8 ( V_10 , V_10 -> V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_25 * V_26 , enum V_16 type , T_1 V_17 )
{
int V_14 = F_9 ( & V_26 -> V_27 , type , V_17 ) ;
if ( V_14 ) {
F_12 ( L_1 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_13 ( struct V_25 * V_26 , struct V_18 * V_28 )
{
int V_14 = 0 ;
enum V_29 V_30 ;
switch ( V_28 -> type ) {
case V_31 :
V_14 = F_14 ( & V_26 -> V_32 , V_28 -> V_22 , & V_30 ) ;
break;
case V_33 :
V_14 = F_15 ( & V_26 -> V_32 , V_28 -> V_22 , & V_30 ) ;
break;
}
return V_14 ;
}
static void F_16 ( struct V_25 * V_26 )
{
V_26 -> V_34 ++ ;
}
static int F_17 ( struct V_25 * V_26 )
{
int V_14 = 0 ;
while ( ! F_7 ( & V_26 -> V_27 ) ) {
struct V_18 V_19 ;
V_14 = F_10 ( & V_26 -> V_27 , & V_19 ) ;
if ( V_14 ) {
F_12 ( L_2 ) ;
break;
}
V_14 = F_13 ( V_26 , & V_19 ) ;
if ( V_14 )
break;
}
return V_14 ;
}
static int F_18 ( struct V_25 * V_26 )
{
int V_14 = 0 ;
if ( ! V_26 -> V_34 ) {
F_12 ( L_3 ) ;
return - V_21 ;
}
if ( V_26 -> V_34 == 1 )
F_17 ( V_26 ) ;
V_26 -> V_34 -- ;
return V_14 ;
}
static int F_19 ( int V_35 , int V_36 )
{
return V_35 ? V_35 : V_36 ;
}
static int F_20 ( struct V_25 * V_26 )
{
return V_26 -> V_34 ;
}
static void F_21 ( struct V_37 * V_38 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
F_23 ( V_26 ) ;
}
static int F_24 ( struct V_37 * V_38 , T_1 * V_39 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
* V_39 = V_26 -> V_32 . V_40 ;
return 0 ;
}
static int F_25 ( struct V_37 * V_38 , T_1 * V_39 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
* V_39 = V_26 -> V_41 . V_40 - V_26 -> V_41 . V_42 -
V_26 -> V_43 ;
return 0 ;
}
static int F_26 ( struct V_37 * V_38 , T_1 V_17 ,
T_3 * V_23 )
{
int V_14 ;
unsigned V_44 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
unsigned V_45 = 0 ;
for ( V_44 = V_26 -> V_27 . V_11 ;
V_44 != V_26 -> V_27 . V_12 ;
V_44 = F_8 ( & V_26 -> V_27 , V_44 ) ) {
struct V_18 * V_28 = V_26 -> V_27 . V_15 + V_44 ;
if ( V_28 -> V_22 != V_17 )
continue;
switch ( V_28 -> type ) {
case V_31 :
V_45 ++ ;
break;
case V_33 :
V_45 -- ;
break;
}
}
V_14 = F_27 ( & V_26 -> V_32 , V_17 , V_23 ) ;
if ( V_14 )
return V_14 ;
* V_23 += V_45 ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 ,
T_1 V_17 , int * V_23 )
{
int V_14 , V_45 = 0 ;
unsigned V_44 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
T_3 V_46 ;
for ( V_44 = V_26 -> V_27 . V_11 ;
V_44 != V_26 -> V_27 . V_12 ;
V_44 = F_8 ( & V_26 -> V_27 , V_44 ) ) {
struct V_18 * V_28 = V_26 -> V_27 . V_15 + V_44 ;
if ( V_28 -> V_22 != V_17 )
continue;
switch ( V_28 -> type ) {
case V_31 :
V_45 ++ ;
break;
case V_33 :
V_45 -- ;
break;
}
}
if ( V_45 > 1 ) {
* V_23 = 1 ;
return 0 ;
}
V_14 = F_29 ( & V_26 -> V_32 , V_17 , & V_46 ) ;
if ( V_14 )
return V_14 ;
if ( V_46 == 3 )
* V_23 = 1 ;
else
* V_23 = V_46 + V_45 > 1 ;
return 0 ;
}
static int F_30 ( struct V_37 * V_38 , T_1 V_17 ,
T_3 V_39 )
{
int V_14 , V_36 ;
enum V_29 V_30 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
if ( V_26 -> V_34 ) {
F_12 ( L_4 ) ;
return - V_47 ;
}
F_16 ( V_26 ) ;
V_14 = F_31 ( & V_26 -> V_32 , V_17 , V_39 , & V_30 ) ;
V_36 = F_18 ( V_26 ) ;
return F_19 ( V_14 , V_36 ) ;
}
static int F_32 ( struct V_37 * V_38 , T_1 V_17 )
{
int V_14 , V_36 = 0 ;
enum V_29 V_30 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
if ( F_20 ( V_26 ) )
V_14 = F_11 ( V_26 , V_31 , V_17 ) ;
else {
F_16 ( V_26 ) ;
V_14 = F_14 ( & V_26 -> V_32 , V_17 , & V_30 ) ;
V_36 = F_18 ( V_26 ) ;
}
return F_19 ( V_14 , V_36 ) ;
}
static int F_33 ( struct V_37 * V_38 , T_1 V_17 )
{
int V_14 , V_36 = 0 ;
enum V_29 V_30 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
if ( F_20 ( V_26 ) )
V_14 = F_11 ( V_26 , V_33 , V_17 ) ;
else {
F_16 ( V_26 ) ;
V_14 = F_15 ( & V_26 -> V_32 , V_17 , & V_30 ) ;
V_36 = F_18 ( V_26 ) ;
}
return F_19 ( V_14 , V_36 ) ;
}
static int F_34 ( struct V_37 * V_38 , T_1 * V_17 )
{
int V_14 , V_36 = 0 ;
enum V_29 V_30 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
V_14 = F_35 ( & V_26 -> V_41 , V_26 -> V_11 , V_26 -> V_41 . V_40 , V_17 ) ;
if ( V_14 )
return V_14 ;
V_26 -> V_11 = * V_17 + 1 ;
if ( F_20 ( V_26 ) )
V_14 = F_11 ( V_26 , V_31 , * V_17 ) ;
else {
F_16 ( V_26 ) ;
V_14 = F_14 ( & V_26 -> V_32 , * V_17 , & V_30 ) ;
V_36 = F_18 ( V_26 ) ;
}
if ( ! V_14 )
V_26 -> V_43 ++ ;
return F_19 ( V_14 , V_36 ) ;
}
static int F_36 ( struct V_37 * V_38 , T_1 * V_17 )
{
T_1 V_39 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
int V_14 = F_34 ( V_38 , V_17 ) ;
if ( V_14 ) {
F_37 ( L_5 ) ;
return V_14 ;
}
V_14 = F_25 ( V_38 , & V_39 ) ;
if ( V_14 ) {
F_37 ( L_6 ) ;
return V_14 ;
}
F_5 ( & V_26 -> V_1 , V_39 ) ;
return V_14 ;
}
static int F_38 ( struct V_37 * V_38 )
{
int V_14 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
V_14 = F_39 ( & V_26 -> V_32 ) ;
if ( V_14 )
return V_14 ;
memcpy ( & V_26 -> V_41 , & V_26 -> V_32 , sizeof( V_26 -> V_41 ) ) ;
V_26 -> V_11 = 0 ;
V_26 -> V_43 = 0 ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 ,
T_1 V_1 ,
T_2 V_6 ,
void * V_7 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
F_2 ( & V_26 -> V_1 , V_1 , V_6 , V_7 ) ;
return 0 ;
}
static int F_41 ( struct V_37 * V_38 , T_4 * V_23 )
{
* V_23 = sizeof( struct V_48 ) ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 , void * V_49 , T_4 V_50 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
struct V_48 V_51 ;
V_51 . V_40 = F_43 ( V_26 -> V_32 . V_40 ) ;
V_51 . V_42 = F_43 ( V_26 -> V_32 . V_42 ) ;
V_51 . V_52 = F_43 ( V_26 -> V_32 . V_52 ) ;
V_51 . V_53 = F_43 ( V_26 -> V_32 . V_53 ) ;
if ( V_50 < sizeof( V_51 ) )
return - V_54 ;
memcpy ( V_49 , & V_51 , sizeof( V_51 ) ) ;
return 0 ;
}
static void F_44 ( struct V_37 * V_38 )
{
}
static int F_45 ( struct V_37 * V_38 , T_1 V_55 )
{
F_12 ( L_7 ) ;
return - V_47 ;
}
static int F_46 ( struct V_37 * V_38 , T_1 * V_39 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
* V_39 = V_26 -> V_32 . V_40 ;
return 0 ;
}
static int F_47 ( struct V_37 * V_38 , T_1 * V_39 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
* V_39 = V_26 -> V_32 . V_40 - V_26 -> V_11 ;
return 0 ;
}
static int F_48 ( struct V_37 * V_38 , T_1 V_17 ,
T_3 * V_23 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
* V_23 = ( V_17 < V_26 -> V_11 ) ? 1 : 0 ;
return 0 ;
}
static int F_49 ( struct V_37 * V_38 ,
T_1 V_17 , int * V_23 )
{
* V_23 = 0 ;
return 0 ;
}
static int F_50 ( struct V_37 * V_38 , T_1 V_17 ,
T_3 V_39 )
{
F_12 ( L_8 ) ;
return - V_47 ;
}
static int F_51 ( struct V_37 * V_38 , T_1 * V_17 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
if ( V_26 -> V_11 == V_26 -> V_32 . V_40 )
return - V_54 ;
* V_17 = V_26 -> V_11 ++ ;
return 0 ;
}
static int F_52 ( struct V_37 * V_38 , T_1 V_17 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
return F_11 ( V_26 , V_31 , V_17 ) ;
}
static int F_53 ( struct V_37 * V_38 , T_1 V_17 )
{
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
return F_11 ( V_26 , V_33 , V_17 ) ;
}
static int F_54 ( struct V_37 * V_38 )
{
return 0 ;
}
static int F_55 ( struct V_37 * V_38 , T_4 * V_23 )
{
F_12 ( L_9 ) ;
return - V_47 ;
}
static int F_56 ( struct V_37 * V_38 , void * V_56 ,
T_4 V_50 )
{
F_12 ( L_10 ) ;
return - V_47 ;
}
static int F_57 ( struct V_37 * V_38 , T_1 V_55 )
{
int V_14 , V_44 ;
enum V_29 V_30 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
T_1 V_57 = V_26 -> V_32 . V_40 ;
V_26 -> V_11 = V_57 ;
memcpy ( V_38 , & V_58 , sizeof( * V_38 ) ) ;
V_14 = F_58 ( & V_26 -> V_32 , V_55 ) ;
if ( V_14 )
goto F_18;
do {
for ( V_44 = V_57 ; ! V_14 && V_44 < V_26 -> V_11 ; V_44 ++ ) {
V_14 = F_14 ( & V_26 -> V_32 , V_44 , & V_30 ) ;
if ( V_14 )
goto F_18;
}
V_57 = V_26 -> V_11 ;
V_14 = F_17 ( V_26 ) ;
if ( V_14 ) {
F_12 ( L_11 , V_59 ) ;
goto F_18;
}
V_14 = F_39 ( & V_26 -> V_32 ) ;
if ( V_14 )
goto F_18;
} while ( V_57 != V_26 -> V_11 );
F_18:
memcpy ( V_38 , & V_60 , sizeof( * V_38 ) ) ;
return V_14 ;
}
struct V_37 * F_59 ( void )
{
struct V_25 * V_26 ;
V_26 = F_60 ( sizeof( * V_26 ) , V_61 ) ;
if ( ! V_26 )
return F_61 ( - V_21 ) ;
memcpy ( & V_26 -> V_38 , & V_60 , sizeof( V_26 -> V_38 ) ) ;
return & V_26 -> V_38 ;
}
int F_62 ( struct V_37 * V_38 ,
struct V_62 * V_63 ,
T_1 V_40 ,
T_1 V_64 )
{
int V_14 ;
T_1 V_44 ;
enum V_29 V_30 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
V_26 -> V_11 = V_64 + 1 ;
V_26 -> V_34 = 0 ;
V_26 -> V_43 = 0 ;
F_6 ( & V_26 -> V_27 ) ;
F_1 ( & V_26 -> V_1 ) ;
memcpy ( & V_26 -> V_38 , & V_58 , sizeof( V_26 -> V_38 ) ) ;
V_14 = F_63 ( & V_26 -> V_32 , V_63 ) ;
if ( V_14 )
return V_14 ;
if ( V_40 > V_65 )
V_40 = V_65 ;
V_14 = F_58 ( & V_26 -> V_32 , V_40 ) ;
if ( V_14 )
return V_14 ;
memcpy ( & V_26 -> V_38 , & V_60 , sizeof( V_26 -> V_38 ) ) ;
for ( V_44 = V_64 ; ! V_14 && V_44 < V_26 -> V_11 ; V_44 ++ )
V_14 = F_14 ( & V_26 -> V_32 , V_44 , & V_30 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_17 ( V_26 ) ;
if ( V_14 ) {
F_12 ( L_11 , V_59 ) ;
return V_14 ;
}
return F_38 ( V_38 ) ;
}
int F_64 ( struct V_37 * V_38 ,
struct V_62 * V_63 ,
void * V_51 , T_4 V_66 )
{
int V_14 ;
struct V_25 * V_26 = F_22 ( V_38 , struct V_25 , V_38 ) ;
V_14 = F_65 ( & V_26 -> V_32 , V_63 , V_51 , V_66 ) ;
if ( V_14 )
return V_14 ;
V_26 -> V_11 = 0 ;
V_26 -> V_34 = 0 ;
V_26 -> V_43 = 0 ;
F_6 ( & V_26 -> V_27 ) ;
F_1 ( & V_26 -> V_1 ) ;
memcpy ( & V_26 -> V_41 , & V_26 -> V_32 , sizeof( V_26 -> V_41 ) ) ;
return 0 ;
}
