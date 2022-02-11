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
F_10 ( V_21 -> V_25 , V_26 ) ;
if ( F_7 ( V_2 -> V_27 >= V_26 ) )
return;
F_11 ( V_2 -> V_27 , V_21 -> V_25 ) ;
F_6 ( V_21 , V_2 ) ;
}
struct V_1 *
F_12 ( struct V_20 * V_21 )
{
if ( F_13 ( V_21 ) == NULL )
return NULL ;
while ( F_14 ( V_21 ) < F_13 ( V_21 ) -> V_14 ) {
struct V_1 * V_2 = F_13 ( V_21 ) ;
struct V_7 * V_17 = & V_2 -> V_8 [ F_14 ( V_21 ) ] ;
struct V_1 * V_28 ;
if ( ! ( V_17 -> V_29 & V_30 ) ) {
F_14 ( V_21 ) ++ ;
continue;
}
V_28 = F_5 ( V_2 , V_17 ) ;
if ( F_7 ( V_28 -> V_27 >= V_26 ) )
return NULL ;
if ( F_15 ( V_28 -> V_27 , V_21 -> V_25 ) ) {
F_14 ( V_21 ) ++ ;
continue;
}
F_14 ( V_21 ) ++ ;
F_6 ( V_21 , V_28 ) ;
}
return F_8 ( V_21 ) ;
}
T_2 int F_16 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
struct V_20 V_21 ;
struct V_1 * V_36 = V_2 ;
int V_37 ;
F_17 ( & V_34 -> V_38 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_12 ( & V_21 ) ) ) {
unsigned int V_10 ;
V_2 -> V_39 ++ ;
F_7 ( V_2 -> V_32 && V_2 -> V_32 != V_32 ) ;
V_2 -> V_32 = V_32 ;
if ( V_2 -> V_39 > 1 )
continue;
if ( ! V_2 -> V_40 || ! V_2 -> V_40 -> V_41 )
continue;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_2 -> V_8 [ V_10 ] ;
if ( ! ( V_17 -> V_29 & V_30 ) )
continue;
if ( V_17 -> V_19 -> V_2 != V_2 )
continue;
V_37 = V_2 -> V_40 -> V_41 ( V_17 ) ;
if ( V_37 < 0 && V_37 != - V_42 )
goto error;
}
}
F_18 ( & V_34 -> V_38 ) ;
return 0 ;
error:
F_9 ( & V_21 , V_36 ) ;
while ( ( V_36 = F_12 ( & V_21 ) ) ) {
V_36 -> V_39 -- ;
if ( V_36 -> V_39 == 0 )
V_36 -> V_32 = NULL ;
if ( V_36 == V_2 )
break;
}
F_18 ( & V_34 -> V_38 ) ;
return V_37 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
struct V_20 V_21 ;
F_17 ( & V_34 -> V_38 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_12 ( & V_21 ) ) ) {
V_2 -> V_39 -- ;
if ( V_2 -> V_39 == 0 )
V_2 -> V_32 = NULL ;
}
F_18 ( & V_34 -> V_38 ) ;
}
struct V_1 * F_20 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
if ( V_2 -> V_35 -> V_43 &&
! F_21 ( V_2 -> V_35 -> V_43 -> V_44 -> V_45 ) )
return NULL ;
return V_2 ;
}
void F_22 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_35 -> V_43 )
F_23 ( V_2 -> V_35 -> V_43 -> V_44 -> V_45 ) ;
}
static struct V_7 * F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 >= V_2 -> V_9 ) {
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_9 = V_2 -> V_9 + 2 ;
unsigned int V_10 ;
V_8 = F_25 ( V_8 , V_9 * sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL )
return NULL ;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ )
V_8 [ V_10 ] . V_46 -> V_46 = & V_8 [ V_10 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_8 = V_8 ;
}
return & V_2 -> V_8 [ V_2 -> V_14 ++ ] ;
}
int
F_26 ( struct V_1 * V_18 , T_1 V_47 ,
struct V_1 * V_19 , T_1 V_48 , T_3 V_29 )
{
struct V_7 * V_17 ;
struct V_7 * V_49 ;
F_27 ( V_18 == NULL || V_19 == NULL ) ;
F_27 ( V_47 >= V_18 -> V_3 ) ;
F_27 ( V_48 >= V_19 -> V_3 ) ;
V_17 = F_24 ( V_18 ) ;
if ( V_17 == NULL )
return - V_12 ;
V_17 -> V_18 = & V_18 -> V_5 [ V_47 ] ;
V_17 -> V_19 = & V_19 -> V_5 [ V_48 ] ;
V_17 -> V_29 = V_29 ;
V_49 = F_24 ( V_19 ) ;
if ( V_49 == NULL ) {
V_18 -> V_14 -- ;
return - V_12 ;
}
V_49 -> V_18 = & V_18 -> V_5 [ V_47 ] ;
V_49 -> V_19 = & V_19 -> V_5 [ V_48 ] ;
V_49 -> V_29 = V_29 ;
V_17 -> V_46 = V_49 ;
V_49 -> V_46 = V_17 ;
V_19 -> V_15 ++ ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_2 -> V_8 [ V_10 ] ;
struct V_1 * V_50 ;
unsigned int V_51 = 0 ;
if ( V_17 -> V_18 -> V_2 == V_2 )
V_50 = V_17 -> V_19 -> V_2 ;
else
V_50 = V_17 -> V_18 -> V_2 ;
while ( V_51 < V_50 -> V_14 ) {
struct V_7 * V_52 = & V_50 -> V_8 [ V_51 ] ;
if ( V_52 != V_17 -> V_46 ) {
V_51 ++ ;
continue;
}
if ( V_17 -> V_18 -> V_2 == V_2 )
V_50 -> V_15 -- ;
if ( -- V_50 -> V_14 == 0 )
break;
* V_52 = V_50 -> V_8 [ V_50 -> V_14 ] ;
}
}
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 == NULL )
return;
F_17 ( & V_2 -> V_35 -> V_38 ) ;
F_28 ( V_2 ) ;
F_18 ( & V_2 -> V_35 -> V_38 ) ;
}
static int F_30 ( struct V_7 * V_17 , T_3 V_29 )
{
int V_37 ;
V_37 = F_31 ( V_17 -> V_18 -> V_2 , V_53 ,
V_17 -> V_18 , V_17 -> V_19 , V_29 ) ;
if ( V_37 < 0 && V_37 != - V_42 )
return V_37 ;
V_37 = F_31 ( V_17 -> V_19 -> V_2 , V_53 ,
V_17 -> V_19 , V_17 -> V_18 , V_29 ) ;
if ( V_37 < 0 && V_37 != - V_42 ) {
F_31 ( V_17 -> V_18 -> V_2 , V_53 ,
V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_29 ) ;
return V_37 ;
}
V_17 -> V_29 = V_29 ;
V_17 -> V_46 -> V_29 = V_17 -> V_29 ;
return 0 ;
}
int F_32 ( struct V_7 * V_17 , T_3 V_29 )
{
const T_3 V_54 = V_30 ;
struct V_33 * V_34 ;
struct V_1 * V_18 , * V_19 ;
int V_37 = - V_55 ;
if ( V_17 == NULL )
return - V_56 ;
if ( ( V_17 -> V_29 & ~ V_54 ) != ( V_29 & ~ V_54 ) )
return - V_56 ;
if ( V_17 -> V_29 & V_57 )
return V_17 -> V_29 == V_29 ? 0 : - V_56 ;
if ( V_17 -> V_29 == V_29 )
return 0 ;
V_18 = V_17 -> V_18 -> V_2 ;
V_19 = V_17 -> V_19 -> V_2 ;
if ( ! ( V_17 -> V_29 & V_58 ) &&
( V_18 -> V_39 || V_19 -> V_39 ) )
return - V_55 ;
V_34 = V_18 -> V_35 ;
if ( V_34 -> V_59 ) {
V_37 = V_34 -> V_59 ( V_17 , V_29 ,
V_60 ) ;
if ( V_37 < 0 )
return V_37 ;
}
V_37 = F_30 ( V_17 , V_29 ) ;
if ( V_34 -> V_59 )
V_34 -> V_59 ( V_17 , V_29 , V_61 ) ;
return V_37 ;
}
int F_33 ( struct V_7 * V_17 , T_3 V_29 )
{
int V_37 ;
F_17 ( & V_17 -> V_18 -> V_2 -> V_35 -> V_38 ) ;
V_37 = F_32 ( V_17 , V_29 ) ;
F_18 ( & V_17 -> V_18 -> V_2 -> V_35 -> V_38 ) ;
return V_37 ;
}
struct V_7 *
F_34 ( struct V_4 * V_18 , struct V_4 * V_19 )
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
struct V_4 * F_35 ( struct V_4 * V_62 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_62 -> V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_62 -> V_2 -> V_8 [ V_10 ] ;
if ( ! ( V_17 -> V_29 & V_30 ) )
continue;
if ( V_17 -> V_18 == V_62 )
return V_17 -> V_19 ;
if ( V_17 -> V_19 == V_62 )
return V_17 -> V_18 ;
}
return NULL ;
}
