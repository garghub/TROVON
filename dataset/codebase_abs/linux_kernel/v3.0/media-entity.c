int
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
unsigned int V_9 = V_3 + V_6 ;
unsigned int V_10 ;
V_8 = F_2 ( V_9 * sizeof( V_8 [ 0 ] ) , V_11 ) ;
if ( V_8 == NULL )
return - V_12 ;
V_2 -> V_13 = 0 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_8 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
V_5 [ V_10 ] . V_2 = V_2 ;
V_5 [ V_10 ] . V_16 = V_10 ;
}
return 0 ;
}
void
F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_8 ) ;
}
static struct V_1 *
F_5 ( struct V_1 * V_2 , struct V_7 * V_17 )
{
if ( V_17 -> V_18 -> V_2 == V_2 )
return V_17 -> V_19 -> V_2 ;
else
return V_17 -> V_18 -> V_2 ;
}
static void F_6 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
if ( V_21 -> V_22 == V_23 - 1 ) {
F_7 ( 1 ) ;
return;
}
V_21 -> V_22 ++ ;
V_21 -> V_24 [ V_21 -> V_22 ] . V_17 = 0 ;
V_21 -> V_24 [ V_21 -> V_22 ] . V_2 = V_2 ;
}
static struct V_1 * F_8 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
V_2 = V_21 -> V_24 [ V_21 -> V_22 ] . V_2 ;
V_21 -> V_22 -- ;
return V_2 ;
}
void F_9 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
V_21 -> V_22 = 0 ;
V_21 -> V_24 [ V_21 -> V_22 ] . V_2 = NULL ;
F_6 ( V_21 , V_2 ) ;
}
struct V_1 *
F_10 ( struct V_20 * V_21 )
{
if ( F_11 ( V_21 ) == NULL )
return NULL ;
while ( F_12 ( V_21 ) < F_11 ( V_21 ) -> V_14 ) {
struct V_1 * V_2 = F_11 ( V_21 ) ;
struct V_7 * V_17 = & V_2 -> V_8 [ F_12 ( V_21 ) ] ;
struct V_1 * V_25 ;
if ( ! ( V_17 -> V_26 & V_27 ) ) {
F_12 ( V_21 ) ++ ;
continue;
}
V_25 = F_5 ( V_2 , V_17 ) ;
if ( V_25 == F_13 ( V_21 ) ) {
F_12 ( V_21 ) ++ ;
continue;
}
F_12 ( V_21 ) ++ ;
F_6 ( V_21 , V_25 ) ;
}
return F_8 ( V_21 ) ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_20 V_21 ;
F_15 ( & V_31 -> V_33 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_10 ( & V_21 ) ) ) {
V_2 -> V_34 ++ ;
F_7 ( V_2 -> V_29 && V_2 -> V_29 != V_29 ) ;
V_2 -> V_29 = V_29 ;
}
F_16 ( & V_31 -> V_33 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_20 V_21 ;
F_15 ( & V_31 -> V_33 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_10 ( & V_21 ) ) ) {
V_2 -> V_34 -- ;
if ( V_2 -> V_34 == 0 )
V_2 -> V_29 = NULL ;
}
F_16 ( & V_31 -> V_33 ) ;
}
struct V_1 * F_18 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
if ( V_2 -> V_32 -> V_35 &&
! F_19 ( V_2 -> V_32 -> V_35 -> V_36 -> V_37 ) )
return NULL ;
return V_2 ;
}
void F_20 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_32 -> V_35 )
F_21 ( V_2 -> V_32 -> V_35 -> V_36 -> V_37 ) ;
}
static struct V_7 * F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 >= V_2 -> V_9 ) {
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_9 = V_2 -> V_9 + 2 ;
unsigned int V_10 ;
V_8 = F_23 ( V_8 , V_9 * sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL )
return NULL ;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ )
V_8 [ V_10 ] . V_38 -> V_38 = & V_8 [ V_10 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_8 = V_8 ;
}
return & V_2 -> V_8 [ V_2 -> V_14 ++ ] ;
}
int
F_24 ( struct V_1 * V_18 , T_1 V_39 ,
struct V_1 * V_19 , T_1 V_40 , T_2 V_26 )
{
struct V_7 * V_17 ;
struct V_7 * V_41 ;
F_25 ( V_18 == NULL || V_19 == NULL ) ;
F_25 ( V_39 >= V_18 -> V_3 ) ;
F_25 ( V_40 >= V_19 -> V_3 ) ;
V_17 = F_22 ( V_18 ) ;
if ( V_17 == NULL )
return - V_12 ;
V_17 -> V_18 = & V_18 -> V_5 [ V_39 ] ;
V_17 -> V_19 = & V_19 -> V_5 [ V_40 ] ;
V_17 -> V_26 = V_26 ;
V_41 = F_22 ( V_19 ) ;
if ( V_41 == NULL ) {
V_18 -> V_14 -- ;
return - V_12 ;
}
V_41 -> V_18 = & V_18 -> V_5 [ V_39 ] ;
V_41 -> V_19 = & V_19 -> V_5 [ V_40 ] ;
V_41 -> V_26 = V_26 ;
V_17 -> V_38 = V_41 ;
V_41 -> V_38 = V_17 ;
V_19 -> V_15 ++ ;
return 0 ;
}
static int F_26 ( struct V_7 * V_17 , T_2 V_26 )
{
int V_42 ;
V_42 = F_27 ( V_17 -> V_18 -> V_2 , V_43 ,
V_17 -> V_18 , V_17 -> V_19 , V_26 ) ;
if ( V_42 < 0 && V_42 != - V_44 )
return V_42 ;
V_42 = F_27 ( V_17 -> V_19 -> V_2 , V_43 ,
V_17 -> V_19 , V_17 -> V_18 , V_26 ) ;
if ( V_42 < 0 && V_42 != - V_44 ) {
F_27 ( V_17 -> V_18 -> V_2 , V_43 ,
V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_26 ) ;
return V_42 ;
}
V_17 -> V_26 = V_26 ;
V_17 -> V_38 -> V_26 = V_17 -> V_26 ;
return 0 ;
}
int F_28 ( struct V_7 * V_17 , T_2 V_26 )
{
const T_2 V_45 = V_27 ;
struct V_30 * V_31 ;
struct V_1 * V_18 , * V_19 ;
int V_42 = - V_46 ;
if ( V_17 == NULL )
return - V_47 ;
if ( ( V_17 -> V_26 & ~ V_45 ) != ( V_26 & ~ V_45 ) )
return - V_47 ;
if ( V_17 -> V_26 & V_48 )
return V_17 -> V_26 == V_26 ? 0 : - V_47 ;
if ( V_17 -> V_26 == V_26 )
return 0 ;
V_18 = V_17 -> V_18 -> V_2 ;
V_19 = V_17 -> V_19 -> V_2 ;
if ( ! ( V_17 -> V_26 & V_49 ) &&
( V_18 -> V_34 || V_19 -> V_34 ) )
return - V_46 ;
V_31 = V_18 -> V_32 ;
if ( ( V_26 & V_27 ) && V_31 -> V_50 ) {
V_42 = V_31 -> V_50 ( V_17 -> V_18 , V_17 -> V_19 ,
V_27 ) ;
if ( V_42 < 0 )
return V_42 ;
}
V_42 = F_26 ( V_17 , V_26 ) ;
if ( V_42 < 0 )
goto V_51;
if ( ! ( V_26 & V_27 ) && V_31 -> V_50 )
V_31 -> V_50 ( V_17 -> V_18 , V_17 -> V_19 , 0 ) ;
return 0 ;
V_51:
if ( ( V_26 & V_27 ) && V_31 -> V_50 )
V_31 -> V_50 ( V_17 -> V_18 , V_17 -> V_19 , 0 ) ;
return V_42 ;
}
int F_29 ( struct V_7 * V_17 , T_2 V_26 )
{
int V_42 ;
F_15 ( & V_17 -> V_18 -> V_2 -> V_32 -> V_33 ) ;
V_42 = F_28 ( V_17 , V_26 ) ;
F_16 ( & V_17 -> V_18 -> V_2 -> V_32 -> V_33 ) ;
return V_42 ;
}
struct V_7 *
F_30 ( struct V_4 * V_18 , struct V_4 * V_19 )
{
struct V_7 * V_17 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_18 -> V_2 -> V_14 ; ++ V_10 ) {
V_17 = & V_18 -> V_2 -> V_8 [ V_10 ] ;
if ( V_17 -> V_18 -> V_2 == V_18 -> V_2 &&
V_17 -> V_18 -> V_16 == V_18 -> V_16 &&
V_17 -> V_19 -> V_2 == V_19 -> V_2 &&
V_17 -> V_19 -> V_16 == V_19 -> V_16 )
return V_17 ;
}
return NULL ;
}
struct V_4 * F_31 ( struct V_4 * V_52 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_52 -> V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_52 -> V_2 -> V_8 [ V_10 ] ;
if ( ! ( V_17 -> V_26 & V_27 ) )
continue;
if ( V_17 -> V_18 == V_52 )
return V_17 -> V_19 ;
if ( V_17 -> V_19 == V_52 )
return V_17 -> V_18 ;
}
return NULL ;
}
