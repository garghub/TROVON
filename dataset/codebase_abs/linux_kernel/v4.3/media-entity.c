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
F_18 ( V_39 , V_2 -> V_3 ) ;
F_18 ( V_40 , V_2 -> V_3 ) ;
unsigned int V_10 ;
V_2 -> V_41 ++ ;
F_7 ( V_2 -> V_32 && V_2 -> V_32 != V_32 ) ;
V_2 -> V_32 = V_32 ;
if ( V_2 -> V_41 > 1 )
continue;
if ( ! V_2 -> V_42 || ! V_2 -> V_42 -> V_43 )
continue;
F_10 ( V_39 , V_2 -> V_3 ) ;
F_19 ( V_40 , V_2 -> V_3 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_2 -> V_8 [ V_10 ] ;
struct V_4 * V_44 = V_17 -> V_19 -> V_2 == V_2
? V_17 -> V_19 : V_17 -> V_18 ;
F_20 ( V_40 , V_44 -> V_16 , 1 ) ;
if ( ! ( V_44 -> V_29 & V_45 ) ||
V_17 -> V_29 & V_30 )
F_21 ( V_39 , V_44 -> V_16 , 1 ) ;
if ( V_17 -> V_19 != V_44 ||
! ( V_17 -> V_29 & V_30 ) )
continue;
V_37 = V_2 -> V_42 -> V_43 ( V_17 ) ;
if ( V_37 < 0 && V_37 != - V_46 ) {
F_22 ( V_2 -> V_35 -> V_47 ,
L_1 ,
V_17 -> V_18 -> V_2 -> V_48 ,
V_17 -> V_18 -> V_16 ,
V_2 -> V_48 , V_17 -> V_19 -> V_16 , V_37 ) ;
goto error;
}
}
F_23 ( V_39 , V_39 , V_40 , V_2 -> V_3 ) ;
if ( ! F_24 ( V_39 , V_2 -> V_3 ) ) {
V_37 = - V_49 ;
F_22 ( V_2 -> V_35 -> V_47 ,
L_2 ,
V_2 -> V_48 ,
( unsigned ) F_25 (
V_39 , V_2 -> V_3 ) ) ;
goto error;
}
}
F_26 ( & V_34 -> V_38 ) ;
return 0 ;
error:
F_9 ( & V_21 , V_36 ) ;
while ( ( V_36 = F_12 ( & V_21 ) ) ) {
V_36 -> V_41 -- ;
if ( V_36 -> V_41 == 0 )
V_36 -> V_32 = NULL ;
if ( V_36 == V_2 )
break;
}
F_26 ( & V_34 -> V_38 ) ;
return V_37 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
struct V_20 V_21 ;
F_17 ( & V_34 -> V_38 ) ;
F_9 ( & V_21 , V_2 ) ;
while ( ( V_2 = F_12 ( & V_21 ) ) ) {
V_2 -> V_41 -- ;
if ( V_2 -> V_41 == 0 )
V_2 -> V_32 = NULL ;
}
F_26 ( & V_34 -> V_38 ) ;
}
struct V_1 * F_28 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return NULL ;
if ( V_2 -> V_35 -> V_47 &&
! F_29 ( V_2 -> V_35 -> V_47 -> V_50 -> V_51 ) )
return NULL ;
return V_2 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_35 -> V_47 )
F_31 ( V_2 -> V_35 -> V_47 -> V_50 -> V_51 ) ;
}
static struct V_7 * F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 >= V_2 -> V_9 ) {
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_9 = V_2 -> V_9 + 2 ;
unsigned int V_10 ;
V_8 = F_33 ( V_8 , V_9 * sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL )
return NULL ;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ )
V_8 [ V_10 ] . V_52 -> V_52 = & V_8 [ V_10 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_8 = V_8 ;
}
return & V_2 -> V_8 [ V_2 -> V_14 ++ ] ;
}
int
F_34 ( struct V_1 * V_18 , T_1 V_53 ,
struct V_1 * V_19 , T_1 V_54 , T_3 V_29 )
{
struct V_7 * V_17 ;
struct V_7 * V_55 ;
F_35 ( V_18 == NULL || V_19 == NULL ) ;
F_35 ( V_53 >= V_18 -> V_3 ) ;
F_35 ( V_54 >= V_19 -> V_3 ) ;
V_17 = F_32 ( V_18 ) ;
if ( V_17 == NULL )
return - V_12 ;
V_17 -> V_18 = & V_18 -> V_5 [ V_53 ] ;
V_17 -> V_19 = & V_19 -> V_5 [ V_54 ] ;
V_17 -> V_29 = V_29 ;
V_55 = F_32 ( V_19 ) ;
if ( V_55 == NULL ) {
V_18 -> V_14 -- ;
return - V_12 ;
}
V_55 -> V_18 = & V_18 -> V_5 [ V_53 ] ;
V_55 -> V_19 = & V_19 -> V_5 [ V_54 ] ;
V_55 -> V_29 = V_29 ;
V_17 -> V_52 = V_55 ;
V_55 -> V_52 = V_17 ;
V_19 -> V_15 ++ ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_2 -> V_8 [ V_10 ] ;
struct V_1 * V_56 ;
unsigned int V_57 = 0 ;
if ( V_17 -> V_18 -> V_2 == V_2 )
V_56 = V_17 -> V_19 -> V_2 ;
else
V_56 = V_17 -> V_18 -> V_2 ;
while ( V_57 < V_56 -> V_14 ) {
struct V_7 * V_58 = & V_56 -> V_8 [ V_57 ] ;
if ( V_58 != V_17 -> V_52 ) {
V_57 ++ ;
continue;
}
if ( V_17 -> V_18 -> V_2 == V_2 )
V_56 -> V_15 -- ;
if ( -- V_56 -> V_14 == 0 )
break;
* V_58 = V_56 -> V_8 [ V_56 -> V_14 ] ;
}
}
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 == NULL )
return;
F_17 ( & V_2 -> V_35 -> V_38 ) ;
F_36 ( V_2 ) ;
F_26 ( & V_2 -> V_35 -> V_38 ) ;
}
static int F_38 ( struct V_7 * V_17 , T_3 V_29 )
{
int V_37 ;
V_37 = F_39 ( V_17 -> V_18 -> V_2 , V_59 ,
V_17 -> V_18 , V_17 -> V_19 , V_29 ) ;
if ( V_37 < 0 && V_37 != - V_46 )
return V_37 ;
V_37 = F_39 ( V_17 -> V_19 -> V_2 , V_59 ,
V_17 -> V_19 , V_17 -> V_18 , V_29 ) ;
if ( V_37 < 0 && V_37 != - V_46 ) {
F_39 ( V_17 -> V_18 -> V_2 , V_59 ,
V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_29 ) ;
return V_37 ;
}
V_17 -> V_29 = V_29 ;
V_17 -> V_52 -> V_29 = V_17 -> V_29 ;
return 0 ;
}
int F_40 ( struct V_7 * V_17 , T_3 V_29 )
{
const T_3 V_60 = V_30 ;
struct V_33 * V_34 ;
struct V_1 * V_18 , * V_19 ;
int V_37 = - V_61 ;
if ( V_17 == NULL )
return - V_62 ;
if ( ( V_17 -> V_29 & ~ V_60 ) != ( V_29 & ~ V_60 ) )
return - V_62 ;
if ( V_17 -> V_29 & V_63 )
return V_17 -> V_29 == V_29 ? 0 : - V_62 ;
if ( V_17 -> V_29 == V_29 )
return 0 ;
V_18 = V_17 -> V_18 -> V_2 ;
V_19 = V_17 -> V_19 -> V_2 ;
if ( ! ( V_17 -> V_29 & V_64 ) &&
( V_18 -> V_41 || V_19 -> V_41 ) )
return - V_61 ;
V_34 = V_18 -> V_35 ;
if ( V_34 -> V_65 ) {
V_37 = V_34 -> V_65 ( V_17 , V_29 ,
V_66 ) ;
if ( V_37 < 0 )
return V_37 ;
}
V_37 = F_38 ( V_17 , V_29 ) ;
if ( V_34 -> V_65 )
V_34 -> V_65 ( V_17 , V_29 , V_67 ) ;
return V_37 ;
}
int F_41 ( struct V_7 * V_17 , T_3 V_29 )
{
int V_37 ;
F_17 ( & V_17 -> V_18 -> V_2 -> V_35 -> V_38 ) ;
V_37 = F_40 ( V_17 , V_29 ) ;
F_26 ( & V_17 -> V_18 -> V_2 -> V_35 -> V_38 ) ;
return V_37 ;
}
struct V_7 *
F_42 ( struct V_4 * V_18 , struct V_4 * V_19 )
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
struct V_4 * F_43 ( struct V_4 * V_44 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_44 -> V_2 -> V_14 ; V_10 ++ ) {
struct V_7 * V_17 = & V_44 -> V_2 -> V_8 [ V_10 ] ;
if ( ! ( V_17 -> V_29 & V_30 ) )
continue;
if ( V_17 -> V_18 == V_44 )
return V_17 -> V_19 ;
if ( V_17 -> V_19 == V_44 )
return V_17 -> V_18 ;
}
return NULL ;
}
