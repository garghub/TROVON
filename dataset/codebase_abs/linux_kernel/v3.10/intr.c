static void F_1 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 , struct V_2 , V_3 ) ) ;
}
static bool F_4 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_2 * V_7 ;
T_1 V_8 = V_4 -> V_8 ;
F_5 (pos, queue, list)
if ( ( V_9 ) ( V_7 -> V_8 - V_8 ) <= 0 ) {
F_6 ( & V_4 -> V_10 , & V_7 -> V_10 ) ;
return false ;
}
F_6 ( & V_4 -> V_10 , V_6 ) ;
return true ;
}
static void F_7 ( struct V_5 * V_11 , T_1 V_12 ,
struct V_5 V_13 [ V_14 ] )
{
struct V_5 * V_15 ;
struct V_2 * V_4 , * V_16 , * V_17 ;
F_8 (waiter, next, head, list) {
if ( ( V_9 ) ( V_4 -> V_8 - V_12 ) > 0 )
break;
V_15 = V_13 + V_4 -> V_18 ;
if ( V_4 -> V_18 == V_19 &&
! F_9 ( V_15 ) ) {
V_17 = F_10 ( V_15 -> V_17 ,
struct V_2 , V_10 ) ;
if ( V_17 -> V_20 == V_4 -> V_20 ) {
V_17 -> V_21 ++ ;
V_15 = NULL ;
}
}
if ( F_11 ( & V_4 -> V_22 ) == V_23 || ! V_15 ) {
F_12 ( & V_4 -> V_10 ) ;
F_13 ( & V_4 -> V_3 , F_1 ) ;
} else
F_14 ( & V_4 -> V_10 , V_15 ) ;
}
}
static void F_15 ( struct V_24 * V_25 ,
struct V_5 * V_11 ,
unsigned int V_26 )
{
T_1 V_8 =
F_16 ( V_11 , struct V_2 , V_10 ) -> V_8 ;
F_17 ( V_25 , V_26 , V_8 ) ;
F_18 ( V_25 , V_26 ) ;
}
static void F_19 ( struct V_2 * V_4 )
{
struct V_27 * V_28 = V_4 -> V_20 ;
F_20 ( & V_28 -> V_29 ) ;
F_21 ( F_22 ( V_28 -> V_30 ) ,
V_4 -> V_21 , V_4 -> V_8 ) ;
}
static void F_23 ( struct V_2 * V_4 )
{
T_2 * V_31 = V_4 -> V_20 ;
F_24 ( V_31 ) ;
}
static void F_25 ( struct V_2 * V_4 )
{
T_2 * V_31 = V_4 -> V_20 ;
F_26 ( V_31 ) ;
}
static void F_27 ( struct V_5 V_13 [ V_14 ] )
{
struct V_5 * V_11 = V_13 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_14 ; ++ V_32 , ++ V_11 ) {
T_3 V_33 = V_34 [ V_32 ] ;
struct V_2 * V_4 , * V_16 ;
F_8 (waiter, next, head, list) {
F_12 ( & V_4 -> V_10 ) ;
V_33 ( V_4 ) ;
F_28 ( F_29 ( & V_4 -> V_22 , V_23 ) !=
V_35 ) ;
F_13 ( & V_4 -> V_3 , F_1 ) ;
}
}
}
static int F_30 ( struct V_24 * V_25 ,
struct V_36 * V_37 ,
T_1 V_38 )
{
struct V_5 V_13 [ V_14 ] ;
unsigned int V_32 ;
int V_39 ;
for ( V_32 = 0 ; V_32 < V_14 ; ++ V_32 )
F_31 ( V_13 + V_32 ) ;
F_32 ( & V_37 -> V_40 . V_41 ) ;
F_7 ( & V_37 -> V_40 . V_42 , V_38 ,
V_13 ) ;
V_39 = F_9 ( & V_37 -> V_40 . V_42 ) ;
if ( V_39 )
F_33 ( V_25 , V_37 -> V_26 ) ;
else
F_15 ( V_25 , & V_37 -> V_40 . V_42 ,
V_37 -> V_26 ) ;
F_34 ( & V_37 -> V_40 . V_41 ) ;
F_27 ( V_13 ) ;
return V_39 ;
}
static void F_35 ( struct V_43 * V_44 )
{
struct V_45 * V_46 =
F_3 ( V_44 , struct V_45 , V_44 ) ;
struct V_36 * V_37 =
F_3 ( V_46 , struct V_36 , V_40 ) ;
unsigned int V_26 = V_37 -> V_26 ;
struct V_24 * V_25 = V_37 -> V_25 ;
( void ) F_30 ( V_25 , V_37 ,
F_36 ( V_25 -> V_37 + V_26 ) ) ;
}
int F_37 ( struct V_24 * V_25 , T_1 V_26 , T_1 V_8 ,
enum V_47 V_18 , void * V_20 ,
struct V_2 * V_4 , void * * V_48 )
{
struct V_36 * V_37 ;
int V_49 ;
if ( V_4 == NULL ) {
F_38 ( L_1 , V_50 ) ;
return - V_51 ;
}
F_31 ( & V_4 -> V_10 ) ;
F_39 ( & V_4 -> V_3 ) ;
if ( V_48 )
F_40 ( & V_4 -> V_3 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_18 = V_18 ;
F_41 ( & V_4 -> V_22 , V_52 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_21 = 1 ;
V_37 = V_25 -> V_37 + V_26 ;
F_32 ( & V_37 -> V_40 . V_41 ) ;
V_49 = F_9 ( & V_37 -> V_40 . V_42 ) ;
if ( F_4 ( V_4 , & V_37 -> V_40 . V_42 ) ) {
F_17 ( V_25 , V_26 , V_8 ) ;
if ( V_49 )
F_18 ( V_25 , V_26 ) ;
}
F_34 ( & V_37 -> V_40 . V_41 ) ;
if ( V_48 )
* V_48 = V_4 ;
return 0 ;
}
void F_42 ( struct V_24 * V_25 , T_1 V_26 , void * V_48 )
{
struct V_2 * V_4 = V_48 ;
struct V_36 * V_37 ;
while ( F_43 ( & V_4 -> V_22 , V_52 , V_53 ) ==
V_35 )
F_44 () ;
V_37 = V_25 -> V_37 + V_26 ;
( void ) F_30 ( V_25 , V_37 ,
F_36 ( V_25 -> V_37 + V_26 ) ) ;
F_13 ( & V_4 -> V_3 , F_1 ) ;
}
int F_45 ( struct V_24 * V_25 , unsigned int V_54 )
{
unsigned int V_26 ;
T_1 V_55 = F_46 ( V_25 ) ;
F_47 ( & V_25 -> V_56 ) ;
V_25 -> V_57 = V_54 ;
V_25 -> V_58 = F_48 ( L_2 ) ;
if ( ! V_25 -> V_58 )
return - V_59 ;
for ( V_26 = 0 ; V_26 < V_55 ; ++ V_26 ) {
struct V_36 * V_37 = V_25 -> V_37 + V_26 ;
F_49 ( & V_37 -> V_40 . V_41 ) ;
F_31 ( & V_37 -> V_40 . V_42 ) ;
snprintf ( V_37 -> V_40 . V_60 ,
sizeof( V_37 -> V_40 . V_60 ) ,
L_3 , V_26 ) ;
}
F_50 ( V_25 ) ;
return 0 ;
}
void F_51 ( struct V_24 * V_25 )
{
F_52 ( V_25 ) ;
F_53 ( V_25 -> V_58 ) ;
}
void F_50 ( struct V_24 * V_25 )
{
T_1 V_61 = F_54 ( V_25 -> V_62 ) ;
int V_63 ;
F_55 ( & V_25 -> V_56 ) ;
V_63 = F_56 ( V_25 , F_57 ( V_61 , 1000000 ) ,
F_35 ) ;
if ( V_63 ) {
F_58 ( & V_25 -> V_56 ) ;
return;
}
F_58 ( & V_25 -> V_56 ) ;
}
void F_52 ( struct V_24 * V_25 )
{
unsigned int V_26 ;
struct V_36 * V_37 = V_25 -> V_37 ;
T_1 V_55 = F_46 ( V_25 ) ;
F_55 ( & V_25 -> V_56 ) ;
F_59 ( V_25 ) ;
for ( V_26 = 0 ; V_26 < V_55 ; ++ V_26 ) {
struct V_2 * V_4 , * V_16 ;
F_8 (waiter, next,
&syncpt[id].intr.wait_head, list) {
if ( F_43 ( & V_4 -> V_22 ,
V_53 , V_23 ) == V_53 ) {
F_12 ( & V_4 -> V_10 ) ;
F_13 ( & V_4 -> V_3 , F_1 ) ;
}
}
if ( ! F_9 ( & V_37 [ V_26 ] . V_40 . V_42 ) ) {
F_58 ( & V_25 -> V_56 ) ;
F_38 ( L_4 ,
V_50 , V_26 ) ;
return;
}
}
F_60 ( V_25 ) ;
F_58 ( & V_25 -> V_56 ) ;
}
