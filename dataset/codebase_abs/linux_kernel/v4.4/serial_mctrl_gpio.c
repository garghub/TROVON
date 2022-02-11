void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
enum V_4 V_5 ;
struct V_6 * V_7 [ V_8 ] ;
int V_9 [ V_8 ] ;
unsigned int V_10 = 0 ;
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
struct V_1 * F_6 ( struct V_15 * V_16 , unsigned int V_17 )
{
struct V_1 * V_2 ;
enum V_4 V_5 ;
V_2 = F_7 ( V_16 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return F_8 ( - V_19 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
enum V_20 V_21 ;
if ( V_12 [ V_5 ] . V_13 )
V_21 = V_22 ;
else
V_21 = V_23 ;
V_2 -> V_11 [ V_5 ] =
F_9 ( V_16 ,
V_12 [ V_5 ] . V_24 ,
V_17 , V_21 ) ;
if ( F_10 ( V_2 -> V_11 [ V_5 ] ) )
return F_11 ( V_2 -> V_11 [ V_5 ] ) ;
}
return V_2 ;
}
static T_1 F_12 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_27 * V_28 = V_2 -> V_28 ;
T_2 V_3 = V_2 -> V_29 ;
T_2 V_30 ;
F_4 ( V_2 , & V_3 ) ;
V_30 = V_3 ^ V_2 -> V_29 ;
V_2 -> V_29 = V_3 ;
if ( V_30 & V_31 && V_28 -> V_32 != NULL ) {
if ( ( V_30 & V_3 ) & V_33 )
V_28 -> V_34 . V_35 ++ ;
if ( ( V_30 & V_3 ) & V_36 )
V_28 -> V_34 . V_37 ++ ;
if ( V_30 & V_38 )
F_13 ( V_28 , V_3 & V_38 ) ;
if ( V_30 & V_39 )
F_14 ( V_28 , V_3 & V_39 ) ;
F_15 ( & V_28 -> V_32 -> V_28 . V_40 ) ;
}
return V_41 ;
}
struct V_1 * F_16 ( struct V_27 * V_28 , unsigned int V_17 )
{
struct V_1 * V_2 ;
enum V_4 V_5 ;
V_2 = F_6 ( V_28 -> V_16 , V_17 ) ;
if ( F_10 ( V_2 ) )
return V_2 ;
V_2 -> V_28 = V_28 ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
int V_42 ;
if ( ! V_2 -> V_11 [ V_5 ] || V_12 [ V_5 ] . V_13 )
continue;
V_42 = F_17 ( V_2 -> V_11 [ V_5 ] ) ;
if ( V_42 <= 0 ) {
F_18 ( V_28 -> V_16 ,
L_1 ,
V_12 [ V_5 ] . V_24 , V_17 , V_42 ) ;
return F_8 ( V_42 ) ;
}
V_2 -> V_25 [ V_5 ] = V_42 ;
F_19 ( V_2 -> V_25 [ V_5 ] , V_43 ) ;
V_42 = F_20 ( V_28 -> V_16 , V_2 -> V_25 [ V_5 ] ,
F_12 ,
V_44 , F_21 ( V_28 -> V_16 ) ,
V_2 ) ;
if ( V_42 ) {
F_18 ( V_28 -> V_16 ,
L_2 ,
V_12 [ V_5 ] . V_24 , V_17 , V_42 ) ;
return F_8 ( V_42 ) ;
}
}
return V_2 ;
}
void F_22 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
enum V_4 V_5 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( V_2 -> V_25 [ V_5 ] )
F_23 ( V_2 -> V_28 -> V_16 , V_2 -> V_25 [ V_5 ] , V_2 ) ;
if ( V_2 -> V_11 [ V_5 ] )
F_24 ( V_16 , V_2 -> V_11 [ V_5 ] ) ;
}
F_25 ( V_16 , V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
enum V_4 V_5 ;
if ( V_2 -> V_45 )
return;
V_2 -> V_45 = true ;
F_4 ( V_2 , & V_2 -> V_29 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
if ( ! V_2 -> V_25 [ V_5 ] )
continue;
F_27 ( V_2 -> V_25 [ V_5 ] ) ;
}
}
void F_28 ( struct V_1 * V_2 )
{
enum V_4 V_5 ;
if ( ! V_2 -> V_45 )
return;
V_2 -> V_45 = false ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
if ( ! V_2 -> V_25 [ V_5 ] )
continue;
F_29 ( V_2 -> V_25 [ V_5 ] ) ;
}
}
