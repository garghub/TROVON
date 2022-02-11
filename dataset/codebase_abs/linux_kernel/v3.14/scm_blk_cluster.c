void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 -> V_4 . V_5 )
return;
for ( V_3 = 0 ; V_3 < 2 * V_6 ; V_3 ++ )
F_2 ( ( unsigned long ) V_2 -> V_4 . V_5 [ V_3 ] ) ;
F_3 ( V_2 -> V_4 . V_5 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 . V_5 = F_5 ( sizeof( void * ) * 2 * V_6 ,
V_7 ) ;
if ( ! V_2 -> V_4 . V_5 )
return - V_8 ;
for ( V_3 = 0 ; V_3 < 2 * V_6 ; V_3 ++ ) {
V_2 -> V_4 . V_5 [ V_3 ] = ( void * ) F_6 ( V_9 ) ;
if ( ! V_2 -> V_4 . V_5 [ V_3 ] )
return - V_8 ;
}
F_7 ( & V_2 -> V_4 . V_10 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_11 = V_12 ;
}
static bool F_9 ( struct V_1 * V_13 , struct V_1 * V_14 )
{
unsigned long V_15 , V_16 , V_17 , V_18 ;
V_15 = ( ( V_19 ) F_10 ( V_13 -> V_20 ) << 9 ) / V_21 ;
V_16 = ( ( ( V_19 ) F_10 ( V_13 -> V_20 ) << 9 ) +
F_11 ( V_13 -> V_20 ) - 1 ) / V_21 ;
V_17 = ( ( V_19 ) F_10 ( V_14 -> V_20 ) << 9 ) / V_21 ;
V_18 = ( ( ( V_19 ) F_10 ( V_14 -> V_20 ) << 9 ) +
F_11 ( V_14 -> V_20 ) - 1 ) / V_21 ;
return ( V_17 <= V_16 && V_15 <= V_18 ) ;
}
bool F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_1 * V_24 ;
if ( V_6 == 0 )
return true ;
F_13 ( & V_23 -> V_25 ) ;
F_14 (iter, &bdev->cluster_list, cluster.list) {
if ( F_9 ( V_2 , V_24 ) &&
( F_15 ( V_2 -> V_20 ) == V_26 ||
F_15 ( V_24 -> V_20 ) == V_26 ) ) {
F_16 ( & V_23 -> V_25 ) ;
return false ;
}
}
F_17 ( & V_2 -> V_4 . V_10 , & V_23 -> V_27 ) ;
F_16 ( & V_23 -> V_25 ) ;
return true ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned long V_28 ;
if ( V_6 == 0 )
return;
F_19 ( & V_23 -> V_25 , V_28 ) ;
F_20 ( & V_2 -> V_4 . V_10 ) ;
F_21 ( & V_23 -> V_25 , V_28 ) ;
}
void F_22 ( struct V_22 * V_23 )
{
F_7 ( & V_23 -> V_27 ) ;
F_23 ( V_23 -> V_29 , V_21 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_30 * V_31 = V_23 -> V_32 -> V_33 ;
struct V_20 * V_34 = V_2 -> V_20 ;
struct V_35 * V_35 = V_2 -> V_35 ;
struct V_36 * V_36 = & V_2 -> V_37 -> V_36 [ 0 ] ;
struct V_38 V_24 ;
struct V_39 V_40 ;
int V_3 = 0 ;
V_19 V_41 ;
switch ( V_2 -> V_4 . V_11 ) {
case V_12 :
V_2 -> V_4 . V_11 = V_42 ;
case V_42 :
V_2 -> V_37 -> V_20 . V_43 = 1 ;
V_36 -> V_44 = V_45 ;
V_36 -> V_46 = V_47 ;
V_36 -> V_28 = V_48 ;
V_36 -> V_49 = ( V_19 ) V_35 ;
V_36 -> V_50 = V_6 ;
V_41 = V_31 -> V_51 + ( ( V_19 ) F_10 ( V_34 ) << 9 ) ;
V_36 -> V_52 = F_25 ( V_41 , V_21 ) ;
if ( V_36 -> V_52 !=
F_25 ( V_41 + ( V_19 ) F_11 ( V_34 ) - 1 ,
V_21 ) )
V_36 -> V_50 = 2 * V_6 ;
for ( V_3 = 0 ; V_3 < V_36 -> V_50 ; V_3 ++ ) {
V_35 -> V_49 = ( V_19 ) V_2 -> V_4 . V_5 [ V_3 ] ;
V_35 ++ ;
}
break;
case V_53 :
V_36 -> V_46 = V_54 ;
for ( V_41 = V_36 -> V_52 ;
V_41 < V_31 -> V_51 + ( ( V_19 ) F_10 ( V_34 ) << 9 ) ;
V_41 += V_55 ) {
V_35 -> V_49 = ( V_19 ) V_2 -> V_4 . V_5 [ V_3 ] ;
V_35 ++ ;
V_3 ++ ;
}
F_26 (bv, req, iter) {
V_35 -> V_49 = ( V_19 ) F_27 ( V_40 . V_56 ) ;
V_35 ++ ;
V_3 ++ ;
}
for (; V_3 < V_36 -> V_50 ; V_3 ++ ) {
V_35 -> V_49 = ( V_19 ) V_2 -> V_4 . V_5 [ V_3 ] ;
V_35 ++ ;
}
break;
}
}
bool F_28 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 -> V_20 ) == V_57 )
return false ;
return F_11 ( V_2 -> V_20 ) < V_21 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
if ( F_30 ( V_2 -> V_37 ) )
F_31 ( V_2 ) ;
}
bool F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_11 != V_12 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
unsigned long V_28 ;
switch ( V_2 -> V_4 . V_11 ) {
case V_12 :
F_34 () ;
break;
case V_42 :
if ( V_2 -> error ) {
F_35 ( V_2 ) ;
break;
}
V_2 -> V_4 . V_11 = V_53 ;
F_19 ( & V_23 -> V_58 , V_28 ) ;
F_29 ( V_2 ) ;
F_21 ( & V_23 -> V_58 , V_28 ) ;
break;
case V_53 :
F_35 ( V_2 ) ;
break;
}
}
bool F_36 ( void )
{
if ( V_6 == 1 || V_6 > 128 )
return false ;
return ! ( V_6 & ( V_6 - 1 ) ) ;
}
