static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
T_1 V_6 )
{
T_1 V_7 = V_5 * sizeof( * V_4 -> V_8 ) + V_6 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = F_2 ( V_2 -> V_9 , V_4 -> V_7 , & V_4 -> V_10 ,
V_11 ) ;
if ( ! V_4 -> V_8 )
return - V_12 ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 -> V_2 -> V_9 , V_4 -> V_7 , V_4 -> V_8 , V_4 -> V_10 ) ;
}
struct V_3 * F_5 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
struct V_3 * V_4 ;
int V_13 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 )
return NULL ;
V_13 = F_1 ( V_2 , V_4 , V_5 , 0 ) ;
if ( V_13 < 0 ) {
F_7 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_8 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_3 ( V_4 ) ;
F_7 ( V_4 ) ;
}
void F_9 ( struct V_3 * V_4 , T_2 V_14 , T_2 V_15 )
{
V_4 -> V_8 [ V_4 -> V_5 ] . V_16 = V_14 ;
V_4 -> V_8 [ V_4 -> V_5 ] . V_15 = V_15 ;
V_4 -> V_5 ++ ;
}
static struct V_17 * F_10 ( struct V_18 * V_19 )
{
struct V_17 * V_20 ;
T_1 V_21 ;
int V_13 ;
V_20 = F_6 ( sizeof( * V_20 ) , V_11 ) ;
if ( ! V_20 )
return NULL ;
F_11 ( & V_20 -> V_22 ) ;
V_20 -> V_19 = V_19 ;
V_21 = V_19 -> V_23 == V_24
? F_12 ( sizeof( struct V_25 ) , 8 )
: 0 ;
V_13 = F_1 ( V_19 -> V_2 , & V_20 -> V_26 , V_27 ,
V_21 ) ;
if ( V_13 < 0 ) {
F_7 ( V_20 ) ;
return NULL ;
}
if ( V_19 -> V_23 == V_24 ) {
T_1 V_28 = V_27
* sizeof( * V_20 -> V_26 . V_8 ) ;
V_20 -> V_29 = ( ( void * ) V_20 -> V_26 . V_8 ) + V_28 ;
V_20 -> V_10 = V_20 -> V_26 . V_10 + V_28 ;
memset ( V_20 -> V_29 , 0 , sizeof( * V_20 -> V_29 ) ) ;
V_20 -> V_29 -> V_30 [ 0 ] . V_16 = V_20 -> V_26 . V_10 ;
V_20 -> V_29 -> V_31 = V_32 ;
}
return V_20 ;
}
static void F_13 ( struct V_17 * V_20 )
{
struct V_3 * V_4 , * V_33 ;
F_14 (dlb, next, &dl->fragments, list) {
F_15 ( & V_4 -> V_34 ) ;
F_3 ( V_4 ) ;
F_7 ( V_4 ) ;
}
}
static void F_16 ( struct V_17 * V_20 )
{
F_3 ( & V_20 -> V_26 ) ;
F_13 ( V_20 ) ;
F_7 ( V_20 ) ;
}
struct V_17 * F_17 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = NULL ;
unsigned long V_31 ;
F_18 ( & V_19 -> V_35 , V_31 ) ;
if ( ! F_19 ( & V_19 -> free ) ) {
V_20 = F_20 ( & V_19 -> free , struct V_17 , V_34 ) ;
F_15 ( & V_20 -> V_34 ) ;
}
F_21 ( & V_19 -> V_35 , V_31 ) ;
return V_20 ;
}
static void F_22 ( struct V_17 * V_20 )
{
if ( ! V_20 )
return;
F_13 ( V_20 ) ;
V_20 -> V_26 . V_5 = 0 ;
F_23 ( & V_20 -> V_34 , & V_20 -> V_19 -> free ) ;
}
void F_24 ( struct V_17 * V_20 )
{
unsigned long V_31 ;
if ( ! V_20 )
return;
F_18 ( & V_20 -> V_19 -> V_35 , V_31 ) ;
F_22 ( V_20 ) ;
F_21 ( & V_20 -> V_19 -> V_35 , V_31 ) ;
}
void F_25 ( struct V_17 * V_20 , T_2 V_14 , T_2 V_15 )
{
F_9 ( & V_20 -> V_26 , V_14 , V_15 ) ;
}
int F_26 ( struct V_17 * V_20 ,
struct V_3 * V_4 )
{
if ( V_20 -> V_19 -> V_23 != V_24 )
return - V_36 ;
F_23 ( & V_4 -> V_34 , & V_20 -> V_22 ) ;
return 0 ;
}
void F_27 ( struct V_17 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_31 ;
bool V_37 ;
F_18 ( & V_19 -> V_35 , V_31 ) ;
if ( V_20 -> V_19 -> V_23 == V_24 ) {
struct V_38 * V_39 = V_20 -> V_29 -> V_30 ;
struct V_3 * V_4 ;
unsigned int V_40 = 0 ;
V_39 -> V_41 = V_20 -> V_26 . V_5
* sizeof( * V_20 -> V_29 -> V_30 ) ;
F_28 (dlb, &dl->fragments, list) {
V_40 ++ ;
V_39 ++ ;
V_39 -> V_16 = V_4 -> V_10 ;
V_39 -> V_41 = V_4 -> V_5
* sizeof( * V_20 -> V_29 -> V_30 ) ;
}
V_20 -> V_29 -> V_40 = V_40 ;
F_29 ( V_2 , F_30 ( V_19 -> V_42 ) , V_20 -> V_10 ) ;
V_19 -> V_43 = V_20 ;
goto V_44;
}
V_37 = ! ! ( F_31 ( V_2 , V_45 ) & V_46 ) ;
if ( V_37 ) {
F_22 ( V_19 -> V_47 ) ;
V_19 -> V_47 = V_20 ;
goto V_44;
}
F_29 ( V_2 , F_30 ( 0 ) , V_20 -> V_26 . V_10 ) ;
F_29 ( V_2 , V_45 , V_46 |
( V_20 -> V_26 . V_5 * sizeof( * V_20 -> V_29 -> V_30 ) ) ) ;
F_22 ( V_19 -> V_48 ) ;
V_19 -> V_48 = V_20 ;
V_44:
F_21 ( & V_19 -> V_35 , V_31 ) ;
}
void F_32 ( struct V_18 * V_19 )
{
F_33 ( & V_19 -> V_35 ) ;
F_22 ( V_19 -> V_43 ) ;
V_19 -> V_43 = NULL ;
F_34 ( & V_19 -> V_35 ) ;
}
void F_35 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_33 ( & V_19 -> V_35 ) ;
F_22 ( V_19 -> V_43 ) ;
V_19 -> V_43 = NULL ;
if ( V_19 -> V_23 == V_24 )
goto V_44;
if ( F_31 ( V_2 , V_45 ) & V_46 )
goto V_44;
if ( V_19 -> V_48 ) {
V_19 -> V_43 = V_19 -> V_48 ;
V_19 -> V_48 = NULL ;
}
if ( V_19 -> V_47 ) {
struct V_17 * V_20 = V_19 -> V_47 ;
F_29 ( V_2 , F_30 ( 0 ) , V_20 -> V_26 . V_10 ) ;
F_29 ( V_2 , V_45 , V_46 |
( V_20 -> V_26 . V_5 *
sizeof( * V_20 -> V_29 -> V_30 ) ) ) ;
V_19 -> V_48 = V_20 ;
V_19 -> V_47 = NULL ;
}
V_44:
F_34 ( & V_19 -> V_35 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
T_2 V_49 = ( 256 << V_50 )
| V_51 | V_52 | V_53
| V_54 ;
if ( V_2 -> V_55 )
V_49 |= V_56 | V_57 ;
F_29 ( V_2 , V_58 , V_49 ) ;
F_29 ( V_2 , V_59 , V_60 ) ;
}
void F_37 ( struct V_18 * V_19 )
{
unsigned long V_31 ;
F_18 ( & V_19 -> V_35 , V_31 ) ;
F_22 ( V_19 -> V_43 ) ;
F_22 ( V_19 -> V_48 ) ;
F_22 ( V_19 -> V_47 ) ;
F_21 ( & V_19 -> V_35 , V_31 ) ;
V_19 -> V_43 = NULL ;
V_19 -> V_48 = NULL ;
V_19 -> V_47 = NULL ;
}
struct V_18 * F_38 ( struct V_1 * V_2 ,
unsigned int V_42 ,
unsigned int V_61 )
{
struct V_18 * V_19 ;
unsigned int V_62 ;
V_19 = F_39 ( V_2 -> V_9 , sizeof( * V_19 ) , V_11 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_42 = V_42 ;
V_19 -> V_23 = V_42 == 0 && ! V_2 -> V_63 -> V_64
? V_65 : V_24 ;
V_19 -> V_2 = V_2 ;
F_40 ( & V_19 -> V_35 ) ;
F_11 ( & V_19 -> free ) ;
for ( V_62 = 0 ; V_62 < V_61 ; ++ V_62 ) {
struct V_17 * V_20 ;
V_20 = F_10 ( V_19 ) ;
if ( ! V_20 )
return NULL ;
F_23 ( & V_20 -> V_34 , & V_19 -> free ) ;
}
return V_19 ;
}
void F_41 ( struct V_18 * V_19 )
{
struct V_17 * V_20 , * V_33 ;
if ( ! V_19 )
return;
F_14 (dl, next, &dlm->free, list) {
F_15 ( & V_20 -> V_34 ) ;
F_16 ( V_20 ) ;
}
}
