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
T_2 int F_14 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_20 V_21 ;
struct V_1 * V_33 = V_2 ;
int V_34 ;
F_15 ( & V_31 -> V_35 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_10 ( & V_21 ) ) ) {
unsigned int V_10 ;
V_2 -> V_36 ++ ;
F_7 ( V_2 -> V_29 && V_2 -> V_29 != V_29 ) ;
V_2 -> V_29 = V_29 ;
if ( V_2 -> V_36 > 1 )
continue;
if ( ! V_2 -> V_37 || ! V_2 -> V_37 -> V_38 )
continue;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_2 -> V_8 [ V_10 ] ;
if ( ! ( V_17 -> V_26 & V_27 ) )
continue;
if ( V_17 -> V_19 -> V_2 != V_2 )
continue;
V_34 = V_2 -> V_37 -> V_38 ( V_17 ) ;
if ( V_34 < 0 && V_34 != - V_39 )
goto error;
}
}
F_16 ( & V_31 -> V_35 ) ;
return 0 ;
error:
F_9 ( & V_21 , V_33 ) ;
while ( ( V_33 = F_10 ( & V_21 ) ) ) {
V_33 -> V_36 -- ;
if ( V_33 -> V_36 == 0 )
V_33 -> V_29 = NULL ;
if ( V_33 == V_2 )
break;
}
F_16 ( & V_31 -> V_35 ) ;
return V_34 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_20 V_21 ;
F_15 ( & V_31 -> V_35 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_10 ( & V_21 ) ) ) {
V_2 -> V_36 -- ;
if ( V_2 -> V_36 == 0 )
V_2 -> V_29 = NULL ;
}
F_16 ( & V_31 -> V_35 ) ;
}
struct V_1 * F_18 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
if ( V_2 -> V_32 -> V_40 &&
! F_19 ( V_2 -> V_32 -> V_40 -> V_41 -> V_42 ) )
return NULL ;
return V_2 ;
}
void F_20 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_32 -> V_40 )
F_21 ( V_2 -> V_32 -> V_40 -> V_41 -> V_42 ) ;
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
V_8 [ V_10 ] . V_43 -> V_43 = & V_8 [ V_10 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_8 = V_8 ;
}
return & V_2 -> V_8 [ V_2 -> V_14 ++ ] ;
}
int
F_24 ( struct V_1 * V_18 , T_1 V_44 ,
struct V_1 * V_19 , T_1 V_45 , T_3 V_26 )
{
struct V_7 * V_17 ;
struct V_7 * V_46 ;
F_25 ( V_18 == NULL || V_19 == NULL ) ;
F_25 ( V_44 >= V_18 -> V_3 ) ;
F_25 ( V_45 >= V_19 -> V_3 ) ;
V_17 = F_22 ( V_18 ) ;
if ( V_17 == NULL )
return - V_12 ;
V_17 -> V_18 = & V_18 -> V_5 [ V_44 ] ;
V_17 -> V_19 = & V_19 -> V_5 [ V_45 ] ;
V_17 -> V_26 = V_26 ;
V_46 = F_22 ( V_19 ) ;
if ( V_46 == NULL ) {
V_18 -> V_14 -- ;
return - V_12 ;
}
V_46 -> V_18 = & V_18 -> V_5 [ V_44 ] ;
V_46 -> V_19 = & V_19 -> V_5 [ V_45 ] ;
V_46 -> V_26 = V_26 ;
V_17 -> V_43 = V_46 ;
V_46 -> V_43 = V_17 ;
V_19 -> V_15 ++ ;
return 0 ;
}
static int F_26 ( struct V_7 * V_17 , T_3 V_26 )
{
int V_34 ;
V_34 = F_27 ( V_17 -> V_18 -> V_2 , V_47 ,
V_17 -> V_18 , V_17 -> V_19 , V_26 ) ;
if ( V_34 < 0 && V_34 != - V_39 )
return V_34 ;
V_34 = F_27 ( V_17 -> V_19 -> V_2 , V_47 ,
V_17 -> V_19 , V_17 -> V_18 , V_26 ) ;
if ( V_34 < 0 && V_34 != - V_39 ) {
F_27 ( V_17 -> V_18 -> V_2 , V_47 ,
V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_26 ) ;
return V_34 ;
}
V_17 -> V_26 = V_26 ;
V_17 -> V_43 -> V_26 = V_17 -> V_26 ;
return 0 ;
}
int F_28 ( struct V_7 * V_17 , T_3 V_26 )
{
const T_3 V_48 = V_27 ;
struct V_30 * V_31 ;
struct V_1 * V_18 , * V_19 ;
int V_34 = - V_49 ;
if ( V_17 == NULL )
return - V_50 ;
if ( ( V_17 -> V_26 & ~ V_48 ) != ( V_26 & ~ V_48 ) )
return - V_50 ;
if ( V_17 -> V_26 & V_51 )
return V_17 -> V_26 == V_26 ? 0 : - V_50 ;
if ( V_17 -> V_26 == V_26 )
return 0 ;
V_18 = V_17 -> V_18 -> V_2 ;
V_19 = V_17 -> V_19 -> V_2 ;
if ( ! ( V_17 -> V_26 & V_52 ) &&
( V_18 -> V_36 || V_19 -> V_36 ) )
return - V_49 ;
V_31 = V_18 -> V_32 ;
if ( ( V_26 & V_27 ) && V_31 -> V_53 ) {
V_34 = V_31 -> V_53 ( V_17 -> V_18 , V_17 -> V_19 ,
V_27 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_34 = F_26 ( V_17 , V_26 ) ;
if ( V_34 < 0 )
goto V_54;
if ( ! ( V_26 & V_27 ) && V_31 -> V_53 )
V_31 -> V_53 ( V_17 -> V_18 , V_17 -> V_19 , 0 ) ;
return 0 ;
V_54:
if ( ( V_26 & V_27 ) && V_31 -> V_53 )
V_31 -> V_53 ( V_17 -> V_18 , V_17 -> V_19 , 0 ) ;
return V_34 ;
}
int F_29 ( struct V_7 * V_17 , T_3 V_26 )
{
int V_34 ;
F_15 ( & V_17 -> V_18 -> V_2 -> V_32 -> V_35 ) ;
V_34 = F_28 ( V_17 , V_26 ) ;
F_16 ( & V_17 -> V_18 -> V_2 -> V_32 -> V_35 ) ;
return V_34 ;
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
struct V_4 * F_31 ( struct V_4 * V_55 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_55 -> V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_55 -> V_2 -> V_8 [ V_10 ] ;
if ( ! ( V_17 -> V_26 & V_27 ) )
continue;
if ( V_17 -> V_18 == V_55 )
return V_17 -> V_19 ;
if ( V_17 -> V_19 == V_55 )
return V_17 -> V_18 ;
}
return NULL ;
}
