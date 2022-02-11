static void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] . V_4 = V_2 -> V_3 [ 0 ] . V_5 = 0 ;
V_2 -> V_3 [ 0 ] . V_6 = 0 ;
V_2 -> V_3 [ 1 ] . V_4 = V_2 -> V_3 [ 1 ] . V_5 = 0 ;
V_2 -> V_3 [ 1 ] . V_6 = 0 ;
}
static void
F_2 ( struct V_7 * V_8 , T_1 V_9 )
{
const int * V_10 ;
int V_11 ;
if ( V_9 >= V_12 )
return;
V_10 = F_3 ( V_8 , L_1 , & V_11 ) ;
if ( V_10 == NULL || V_11 < 2 * sizeof( int ) ) {
F_4 ( V_13 L_2
L_3 , V_8 -> V_14 ) ;
V_15 [ V_9 ] = 0 ;
} else
V_15 [ V_9 ] = V_10 [ 0 ] ;
F_5 (node, node) {
struct V_1 * V_2 ;
const unsigned int * V_16 , * V_17 ;
V_16 = F_3 ( V_8 , L_4 , NULL ) ;
if ( ! V_16 || ( ( * V_16 >> 8 ) != V_18 &&
( * V_16 >> 8 ) != V_19 ) )
continue;
V_17 = F_3 ( V_8 , L_5 , NULL ) ;
if ( ! V_17 )
continue;
V_2 = F_6 ( V_9 , ( ( V_17 [ 0 ] >> 8 ) & 0xff ) ) ;
if ( ! V_2 || ! V_2 -> V_20 ) {
F_7 ( V_2 ) ;
continue;
}
F_2 ( V_8 , V_2 -> V_20 -> V_21 ) ;
F_7 ( V_2 ) ;
}
}
void
F_8 ( void )
{
int V_22 ;
struct V_23 * V_24 , * V_25 ;
struct V_26 * V_27 ;
struct V_7 * V_28 ;
V_15 = F_9 ( V_12 , V_29 ) ;
if ( ! V_15 ) {
F_4 ( V_30 L_6 ) ;
return;
}
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
V_15 [ V_22 ] = 0xff ;
F_10 (hose, tmp, &hose_list, list_node) {
struct V_7 * V_8 = V_24 -> V_28 ;
if ( ! V_8 )
continue;
F_2 ( V_8 , V_24 -> V_31 ) ;
}
V_28 = F_11 ( L_7 ) ;
V_27 = F_12 ( V_28 , L_8 , NULL ) ;
if ( V_27 ) {
F_13 ( V_12 > V_27 -> V_32 ) ;
memcpy ( V_27 -> V_33 , V_15 , V_12 ) ;
}
F_14 ( V_28 ) ;
#ifdef F_15
F_4 ( L_9 ) ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
if ( V_15 [ V_22 ] == 0xff )
continue;
F_4 ( L_10 , V_22 , V_15 [ V_22 ] ) ;
}
#endif
}
int F_16 ( struct V_7 * V_8 , T_1 * V_34 , T_1 * V_35 )
{
struct V_1 * V_2 = NULL ;
const T_2 * V_17 ;
int V_36 ;
if ( ! F_17 ( V_8 ) )
return - V_37 ;
V_17 = F_3 ( V_8 , L_5 , & V_36 ) ;
if ( ! V_17 || V_36 < 5 * sizeof( V_38 ) )
return - V_37 ;
* V_34 = ( F_18 ( & V_17 [ 0 ] ) >> 16 ) & 0xff ;
* V_35 = ( F_18 ( & V_17 [ 0 ] ) >> 8 ) & 0xff ;
if ( ! V_15 )
return 0 ;
F_19 (dev)
if ( V_15 [ V_2 -> V_34 -> V_21 ] == * V_34 &&
V_2 -> V_35 == * V_35 ) {
* V_34 = V_2 -> V_34 -> V_21 ;
F_7 ( V_2 ) ;
return 0 ;
}
return - V_37 ;
}
void T_3
F_20 ( void )
{
struct V_26 * V_39 ;
struct V_7 * V_28 ;
V_39 = (struct V_26 * ) F_21 ( sizeof( struct V_26 ) + 256 ) ;
if ( ! V_39 )
return;
V_28 = F_11 ( L_7 ) ;
if ( V_28 ) {
memset ( V_39 , - 1 , sizeof( struct V_26 ) + 256 ) ;
V_39 -> V_40 = L_8 ;
V_39 -> V_32 = 256 ;
V_39 -> V_33 = & V_39 [ 1 ] ;
F_22 ( V_28 , V_39 ) ;
F_14 ( V_28 ) ;
}
}
void F_23 ( struct V_23 * V_24 )
{
unsigned long V_41 ;
struct V_3 * V_42 = & V_24 -> V_43 ;
V_41 = F_24 ( V_24 ) ;
V_42 -> V_4 += V_41 ;
V_42 -> V_5 += V_41 ;
}
static int T_3 F_25 ( void )
{
struct V_23 * V_24 , * V_25 ;
int V_44 = 0 ;
F_4 ( V_45 L_11 ) ;
if ( F_26 ( V_46 ) )
V_47 = 1 ;
F_10 (hose, tmp, &hose_list, list_node) {
if ( V_47 )
V_24 -> V_31 = V_44 ;
V_24 -> V_48 = 0xff ;
F_27 ( V_24 ) ;
F_28 ( V_24 -> V_34 ) ;
if ( V_47 || V_44 <= V_24 -> V_48 )
V_44 = V_24 -> V_48 + V_49 ;
}
V_12 = V_44 ;
if ( V_47 )
F_8 () ;
F_29 () ;
if ( V_50 . V_51 )
V_50 . V_51 () ;
return 0 ;
}
static struct V_23 *
F_30 ( int V_34 )
{
struct V_23 * V_24 , * V_25 ;
F_10 (hose, tmp, &hose_list, list_node)
if ( V_34 >= V_24 -> V_31 && V_34 <= V_24 -> V_48 )
return V_24 ;
return NULL ;
}
long F_31 ( long V_52 , unsigned long V_34 , unsigned long V_35 )
{
struct V_23 * V_24 ;
long V_53 = - V_54 ;
V_24 = F_30 ( V_34 ) ;
if ( ! V_24 )
return - V_37 ;
switch ( V_52 ) {
case V_55 :
return ( long ) V_24 -> V_31 ;
case V_56 :
return ( long ) V_24 -> V_57 ;
case V_58 :
return ( long ) V_24 -> V_59 ;
case V_60 :
return ( long ) V_61 ;
case V_62 :
return ( long ) V_63 ;
}
return V_53 ;
}
