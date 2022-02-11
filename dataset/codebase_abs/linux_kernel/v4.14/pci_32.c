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
L_3 , V_8 ) ;
V_14 [ V_9 ] = 0 ;
} else
V_14 [ V_9 ] = V_10 [ 0 ] ;
F_5 (node, node) {
struct V_1 * V_2 ;
const unsigned int * V_15 , * V_16 ;
V_15 = F_3 ( V_8 , L_4 , NULL ) ;
if ( ! V_15 || ( ( * V_15 >> 8 ) != V_17 &&
( * V_15 >> 8 ) != V_18 ) )
continue;
V_16 = F_3 ( V_8 , L_5 , NULL ) ;
if ( ! V_16 )
continue;
V_2 = F_6 ( V_9 , ( ( V_16 [ 0 ] >> 8 ) & 0xff ) ) ;
if ( ! V_2 || ! V_2 -> V_19 ) {
F_7 ( V_2 ) ;
continue;
}
F_2 ( V_8 , V_2 -> V_19 -> V_20 ) ;
F_7 ( V_2 ) ;
}
}
void
F_8 ( void )
{
int V_21 ;
struct V_22 * V_23 , * V_24 ;
struct V_25 * V_26 ;
struct V_7 * V_27 ;
V_14 = F_9 ( V_12 , V_28 ) ;
if ( ! V_14 ) {
F_4 ( V_29 L_6 ) ;
return;
}
for ( V_21 = 0 ; V_21 < V_12 ; V_21 ++ )
V_14 [ V_21 ] = 0xff ;
F_10 (hose, tmp, &hose_list, list_node) {
struct V_7 * V_8 = V_23 -> V_27 ;
if ( ! V_8 )
continue;
F_2 ( V_8 , V_23 -> V_30 ) ;
}
V_27 = F_11 ( L_7 ) ;
V_26 = F_12 ( V_27 , L_8 , NULL ) ;
if ( V_26 ) {
F_13 ( V_12 > V_26 -> V_31 ) ;
memcpy ( V_26 -> V_32 , V_14 , V_12 ) ;
}
F_14 ( V_27 ) ;
#ifdef F_15
F_4 ( L_9 ) ;
for ( V_21 = 0 ; V_21 < V_12 ; V_21 ++ ) {
if ( V_14 [ V_21 ] == 0xff )
continue;
F_4 ( L_10 , V_21 , V_14 [ V_21 ] ) ;
}
#endif
}
int F_16 ( struct V_7 * V_8 , T_1 * V_33 , T_1 * V_34 )
{
struct V_1 * V_2 = NULL ;
const T_2 * V_16 ;
int V_35 ;
if ( ! F_17 ( V_8 ) )
return - V_36 ;
V_16 = F_3 ( V_8 , L_5 , & V_35 ) ;
if ( ! V_16 || V_35 < 5 * sizeof( V_37 ) )
return - V_36 ;
* V_33 = ( F_18 ( & V_16 [ 0 ] ) >> 16 ) & 0xff ;
* V_34 = ( F_18 ( & V_16 [ 0 ] ) >> 8 ) & 0xff ;
if ( ! V_14 )
return 0 ;
F_19 (dev)
if ( V_14 [ V_2 -> V_33 -> V_20 ] == * V_33 &&
V_2 -> V_34 == * V_34 ) {
* V_33 = V_2 -> V_33 -> V_20 ;
F_7 ( V_2 ) ;
return 0 ;
}
return - V_36 ;
}
void T_3
F_20 ( void )
{
struct V_25 * V_38 ;
struct V_7 * V_27 ;
V_38 = F_21 ( sizeof( struct V_25 ) + 256 , 0 ) ;
V_27 = F_11 ( L_7 ) ;
if ( V_27 ) {
memset ( V_38 , - 1 , sizeof( struct V_25 ) + 256 ) ;
V_38 -> V_39 = L_8 ;
V_38 -> V_31 = 256 ;
V_38 -> V_32 = & V_38 [ 1 ] ;
F_22 ( V_27 , V_38 ) ;
F_14 ( V_27 ) ;
}
}
void F_23 ( struct V_22 * V_23 )
{
unsigned long V_40 ;
struct V_3 * V_41 = & V_23 -> V_42 ;
V_40 = F_24 ( V_23 ) ;
V_41 -> V_4 += V_40 ;
V_41 -> V_5 += V_40 ;
}
static int T_3 F_25 ( void )
{
struct V_22 * V_23 , * V_24 ;
int V_43 = 0 ;
F_4 ( V_44 L_11 ) ;
if ( F_26 ( V_45 ) )
V_46 = 1 ;
F_10 (hose, tmp, &hose_list, list_node) {
if ( V_46 )
V_23 -> V_30 = V_43 ;
V_23 -> V_47 = 0xff ;
F_27 ( V_23 ) ;
F_28 ( V_23 -> V_33 ) ;
if ( V_46 || V_43 <= V_23 -> V_47 )
V_43 = V_23 -> V_47 + V_48 ;
}
V_12 = V_43 ;
if ( V_46 )
F_8 () ;
F_29 () ;
if ( V_49 . V_50 )
V_49 . V_50 () ;
return 0 ;
}
static struct V_22 *
F_30 ( int V_33 )
{
struct V_22 * V_23 , * V_24 ;
F_10 (hose, tmp, &hose_list, list_node)
if ( V_33 >= V_23 -> V_30 && V_33 <= V_23 -> V_47 )
return V_23 ;
return NULL ;
}
long F_31 ( long V_51 , unsigned long V_33 , unsigned long V_34 )
{
struct V_22 * V_23 ;
long V_52 = - V_53 ;
V_23 = F_30 ( V_33 ) ;
if ( ! V_23 )
return - V_36 ;
switch ( V_51 ) {
case V_54 :
return ( long ) V_23 -> V_30 ;
case V_55 :
return ( long ) V_23 -> V_56 [ 0 ] ;
case V_57 :
return ( long ) V_23 -> V_58 ;
case V_59 :
return ( long ) V_60 ;
case V_61 :
return ( long ) V_62 ;
}
return V_52 ;
}
