void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
enum V_4 V_5 ;
struct V_6 * V_7 [ V_8 ] ;
int V_9 [ V_8 ] ;
unsigned int V_10 = 0 ;
if ( V_2 == NULL )
return;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
if ( V_2 -> V_11 [ V_5 ] && V_12 [ V_5 ] . V_13 ) {
V_7 [ V_10 ] = V_2 -> V_11 [ V_5 ] ;
V_9 [ V_10 ] = ! ! ( V_3 & V_12 [ V_5 ] . V_3 ) ;
V_10 ++ ;
}
F_2 ( V_10 , V_7 , V_9 ) ;
}
struct V_6 * F_3 ( struct V_1 * V_2 ,
enum V_4 V_14 )
{
return V_2 -> V_11 [ V_14 ] ;
}
unsigned int F_4 ( struct V_1 * V_2 , unsigned int * V_3 )
{
enum V_4 V_5 ;
if ( V_2 == NULL )
return * V_3 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( V_2 -> V_11 [ V_5 ] && ! V_12 [ V_5 ] . V_13 ) {
if ( F_5 ( V_2 -> V_11 [ V_5 ] ) )
* V_3 |= V_12 [ V_5 ] . V_3 ;
else
* V_3 &= ~ V_12 [ V_5 ] . V_3 ;
}
}
return * V_3 ;
}
unsigned int
F_6 ( struct V_1 * V_2 , unsigned int * V_3 )
{
enum V_4 V_5 ;
if ( V_2 == NULL )
return * V_3 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( V_2 -> V_11 [ V_5 ] && V_12 [ V_5 ] . V_13 ) {
if ( F_5 ( V_2 -> V_11 [ V_5 ] ) )
* V_3 |= V_12 [ V_5 ] . V_3 ;
else
* V_3 &= ~ V_12 [ V_5 ] . V_3 ;
}
}
return * V_3 ;
}
struct V_1 * F_7 ( struct V_15 * V_16 , unsigned int V_17 )
{
struct V_1 * V_2 ;
enum V_4 V_5 ;
V_2 = F_8 ( V_16 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return F_9 ( - V_19 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
enum V_20 V_21 ;
if ( V_12 [ V_5 ] . V_13 )
V_21 = V_22 ;
else
V_21 = V_23 ;
V_2 -> V_11 [ V_5 ] =
F_10 ( V_16 ,
V_12 [ V_5 ] . V_24 ,
V_17 , V_21 ) ;
if ( F_11 ( V_2 -> V_11 [ V_5 ] ) )
return F_12 ( V_2 -> V_11 [ V_5 ] ) ;
}
return V_2 ;
}
static T_1 F_13 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_27 * V_28 = V_2 -> V_28 ;
T_2 V_3 = V_2 -> V_29 ;
T_2 V_30 ;
unsigned long V_21 ;
F_4 ( V_2 , & V_3 ) ;
F_14 ( & V_28 -> V_31 , V_21 ) ;
V_30 = V_3 ^ V_2 -> V_29 ;
V_2 -> V_29 = V_3 ;
if ( V_30 & V_32 && V_28 -> V_33 != NULL ) {
if ( ( V_30 & V_3 ) & V_34 )
V_28 -> V_35 . V_36 ++ ;
if ( ( V_30 & V_3 ) & V_37 )
V_28 -> V_35 . V_38 ++ ;
if ( V_30 & V_39 )
F_15 ( V_28 , V_3 & V_39 ) ;
if ( V_30 & V_40 )
F_16 ( V_28 , V_3 & V_40 ) ;
F_17 ( & V_28 -> V_33 -> V_28 . V_41 ) ;
}
F_18 ( & V_28 -> V_31 , V_21 ) ;
return V_42 ;
}
struct V_1 * F_19 ( struct V_27 * V_28 , unsigned int V_17 )
{
struct V_1 * V_2 ;
enum V_4 V_5 ;
V_2 = F_7 ( V_28 -> V_16 , V_17 ) ;
if ( F_11 ( V_2 ) )
return V_2 ;
V_2 -> V_28 = V_28 ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
int V_43 ;
if ( ! V_2 -> V_11 [ V_5 ] || V_12 [ V_5 ] . V_13 )
continue;
V_43 = F_20 ( V_2 -> V_11 [ V_5 ] ) ;
if ( V_43 <= 0 ) {
F_21 ( V_28 -> V_16 ,
L_1 ,
V_12 [ V_5 ] . V_24 , V_17 , V_43 ) ;
return F_9 ( V_43 ) ;
}
V_2 -> V_25 [ V_5 ] = V_43 ;
F_22 ( V_2 -> V_25 [ V_5 ] , V_44 ) ;
V_43 = F_23 ( V_28 -> V_16 , V_2 -> V_25 [ V_5 ] ,
F_13 ,
V_45 , F_24 ( V_28 -> V_16 ) ,
V_2 ) ;
if ( V_43 ) {
F_21 ( V_28 -> V_16 ,
L_2 ,
V_12 [ V_5 ] . V_24 , V_17 , V_43 ) ;
return F_9 ( V_43 ) ;
}
}
return V_2 ;
}
void F_25 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
enum V_4 V_5 ;
if ( V_2 == NULL )
return;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( V_2 -> V_25 [ V_5 ] )
F_26 ( V_2 -> V_28 -> V_16 , V_2 -> V_25 [ V_5 ] , V_2 ) ;
if ( V_2 -> V_11 [ V_5 ] )
F_27 ( V_16 , V_2 -> V_11 [ V_5 ] ) ;
}
F_28 ( V_16 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
enum V_4 V_5 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_46 )
return;
V_2 -> V_46 = true ;
F_4 ( V_2 , & V_2 -> V_29 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
if ( ! V_2 -> V_25 [ V_5 ] )
continue;
F_30 ( V_2 -> V_25 [ V_5 ] ) ;
}
}
void F_31 ( struct V_1 * V_2 )
{
enum V_4 V_5 ;
if ( V_2 == NULL )
return;
if ( ! V_2 -> V_46 )
return;
V_2 -> V_46 = false ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
if ( ! V_2 -> V_25 [ V_5 ] )
continue;
F_32 ( V_2 -> V_25 [ V_5 ] ) ;
}
}
