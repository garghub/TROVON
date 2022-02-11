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
static bool F_9 ( struct V_13 * V_14 , struct V_13 * V_15 )
{
unsigned long V_16 , V_17 , V_18 , V_19 ;
V_16 = ( ( V_20 ) F_10 ( V_14 ) << 9 ) / V_21 ;
V_17 = ( ( ( V_20 ) F_10 ( V_14 ) << 9 ) +
F_11 ( V_14 ) - 1 ) / V_21 ;
V_18 = ( ( V_20 ) F_10 ( V_15 ) << 9 ) / V_21 ;
V_19 = ( ( ( V_20 ) F_10 ( V_15 ) << 9 ) +
F_11 ( V_15 ) - 1 ) / V_21 ;
return ( V_18 <= V_17 && V_16 <= V_19 ) ;
}
bool F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_22 = V_2 -> V_13 [ V_2 -> V_23 -> V_13 . V_24 ] ;
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_1 * V_27 ;
int V_28 , V_29 = 1 ;
if ( V_6 == 0 )
return true ;
F_13 ( & V_26 -> V_30 ) ;
F_14 (iter, &bdev->cluster_list, cluster.list) {
if ( V_27 == V_2 ) {
V_29 = 0 ;
continue;
}
for ( V_28 = 0 ; V_28 < V_27 -> V_23 -> V_13 . V_24 ; V_28 ++ ) {
if ( F_9 ( V_22 , V_27 -> V_13 [ V_28 ] ) &&
( F_15 ( V_22 ) == V_31 ||
F_15 ( V_27 -> V_13 [ V_28 ] ) == V_31 ) ) {
F_16 ( & V_26 -> V_30 ) ;
return false ;
}
}
}
if ( V_29 )
F_17 ( & V_2 -> V_4 . V_10 , & V_26 -> V_32 ) ;
F_16 ( & V_26 -> V_30 ) ;
return true ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned long V_33 ;
if ( V_6 == 0 )
return;
F_19 ( & V_26 -> V_30 , V_33 ) ;
F_20 ( & V_2 -> V_4 . V_10 ) ;
F_21 ( & V_26 -> V_30 , V_33 ) ;
}
void F_22 ( struct V_25 * V_26 )
{
F_7 ( & V_26 -> V_32 ) ;
F_23 ( V_26 -> V_34 , V_21 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_35 * V_36 = V_26 -> V_37 -> V_38 ;
struct V_13 * V_22 = V_2 -> V_13 [ 0 ] ;
struct V_39 * V_39 = & V_2 -> V_23 -> V_39 [ 0 ] ;
struct V_40 V_27 ;
struct V_41 * V_41 ;
struct V_42 V_43 ;
int V_3 = 0 ;
V_20 V_44 ;
switch ( V_2 -> V_4 . V_11 ) {
case V_12 :
V_2 -> V_4 . V_11 = V_45 ;
case V_45 :
V_39 -> V_46 = V_47 ;
V_39 -> V_48 = V_49 ;
V_39 -> V_33 = V_50 ;
V_39 -> V_51 = V_6 ;
V_44 = V_36 -> V_52 + ( ( V_20 ) F_10 ( V_22 ) << 9 ) ;
V_39 -> V_53 = F_25 ( V_44 , V_21 ) ;
if ( V_39 -> V_53 !=
F_25 ( V_44 + ( V_20 ) F_11 ( V_22 ) - 1 ,
V_21 ) )
V_39 -> V_51 = 2 * V_6 ;
V_41 = F_26 ( V_2 , V_39 -> V_51 * V_54 ) ;
if ( ! V_41 )
return - V_8 ;
V_2 -> V_23 -> V_13 . V_24 = 1 ;
V_39 -> V_55 = ( V_20 ) V_41 ;
for ( V_3 = 0 ; V_3 < V_39 -> V_51 ; V_3 ++ ) {
V_41 -> V_55 = ( V_20 ) V_2 -> V_4 . V_5 [ V_3 ] ;
V_41 ++ ;
}
break;
case V_56 :
V_41 = ( void * ) V_39 -> V_55 ;
V_39 -> V_48 = V_57 ;
for ( V_44 = V_39 -> V_53 ;
V_44 < V_36 -> V_52 + ( ( V_20 ) F_10 ( V_22 ) << 9 ) ;
V_44 += V_54 ) {
V_41 -> V_55 = ( V_20 ) V_2 -> V_4 . V_5 [ V_3 ] ;
V_41 ++ ;
V_3 ++ ;
}
F_27 (bv, req, iter) {
V_41 -> V_55 = ( V_20 ) F_28 ( V_43 . V_58 ) ;
V_41 ++ ;
V_3 ++ ;
}
for (; V_3 < V_39 -> V_51 ; V_3 ++ ) {
V_41 -> V_55 = ( V_20 ) V_2 -> V_4 . V_5 [ V_3 ] ;
V_41 ++ ;
}
break;
}
return 0 ;
}
bool F_29 ( struct V_1 * V_2 )
{
int V_28 = V_2 -> V_23 -> V_13 . V_24 ;
if ( F_15 ( V_2 -> V_13 [ V_28 ] ) == V_59 )
return false ;
return F_11 ( V_2 -> V_13 [ V_28 ] ) < V_21 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
goto V_60;
if ( F_31 ( V_2 -> V_23 ) )
goto V_60;
return;
V_60:
F_32 ( V_2 ) ;
}
bool F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_11 != V_12 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned long V_33 ;
switch ( V_2 -> V_4 . V_11 ) {
case V_12 :
F_35 () ;
break;
case V_45 :
if ( V_2 -> error ) {
F_36 ( V_2 ) ;
break;
}
V_2 -> V_4 . V_11 = V_56 ;
F_19 ( & V_26 -> V_61 , V_33 ) ;
F_30 ( V_2 ) ;
F_21 ( & V_26 -> V_61 , V_33 ) ;
break;
case V_56 :
F_36 ( V_2 ) ;
break;
}
}
bool F_37 ( void )
{
if ( V_6 == 1 || V_6 > 128 )
return false ;
return ! ( V_6 & ( V_6 - 1 ) ) ;
}
