static void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const int * V_4 ;
int V_5 ;
if ( V_3 >= V_6 )
return;
V_4 = F_2 ( V_2 , L_1 , & V_5 ) ;
if ( V_4 == NULL || V_5 < 2 * sizeof( int ) ) {
F_3 ( V_7 L_2
L_3 , V_2 -> V_8 ) ;
V_9 [ V_3 ] = 0 ;
} else
V_9 [ V_3 ] = V_4 [ 0 ] ;
F_4 (node, node) {
struct V_10 * V_11 ;
const unsigned int * V_12 , * V_13 ;
V_12 = F_2 ( V_2 , L_4 , NULL ) ;
if ( ! V_12 ||
( ( * V_12 >> 8 ) != V_14 &&
( * V_12 >> 8 ) != V_15 ) )
continue;
V_13 = F_2 ( V_2 , L_5 , NULL ) ;
if ( ! V_13 )
continue;
V_11 = F_5 ( V_3 , ( ( V_13 [ 0 ] >> 8 ) & 0xff ) ) ;
if ( ! V_11 || ! V_11 -> V_16 ) {
F_6 ( V_11 ) ;
continue;
}
F_1 ( V_2 , V_11 -> V_16 -> V_17 ) ;
F_6 ( V_11 ) ;
}
}
void
F_7 ( void )
{
int V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_24 ;
V_9 = F_8 ( V_6 , V_25 ) ;
if ( ! V_9 ) {
F_3 ( V_26 L_6 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ )
V_9 [ V_18 ] = 0xff ;
F_9 (hose, tmp, &hose_list, list_node) {
struct V_1 * V_2 = V_20 -> V_24 ;
if ( ! V_2 )
continue;
F_1 ( V_2 , V_20 -> V_27 ) ;
}
V_24 = F_10 ( L_7 ) ;
V_23 = F_11 ( V_24 , L_8 , NULL ) ;
if ( V_23 ) {
F_12 ( V_6 > V_23 -> V_28 ) ;
memcpy ( V_23 -> V_29 , V_9 , V_6 ) ;
}
F_13 ( V_24 ) ;
#ifdef F_14
F_3 ( V_30 L_9 ) ;
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
if ( V_9 [ V_18 ] == 0xff )
continue;
F_3 ( V_30 L_10 , V_18 , V_9 [ V_18 ] ) ;
}
#endif
}
static struct V_1 * F_15 ( struct V_1 * V_31 ,
T_2 V_32 , void * V_33 )
{
struct V_1 * V_2 ;
struct V_1 * V_34 ;
F_4 (parent, node) {
const unsigned int * V_12 ;
if ( V_32 ( V_2 , V_33 ) ) {
F_13 ( V_2 ) ;
return V_2 ;
}
V_12 = F_2 ( V_2 , L_4 , NULL ) ;
if ( ( ! V_12 ||
( ( * V_12 >> 8 ) != V_14 &&
( * V_12 >> 8 ) != V_15 ) ) &&
strcmp ( V_2 -> V_35 , L_11 ) )
continue;
V_34 = F_15 ( V_2 , V_32 , V_33 ) ;
if ( V_34 ) {
F_13 ( V_2 ) ;
return V_34 ;
}
}
return NULL ;
}
static struct V_1 * F_16 ( struct V_1 * V_31 ,
unsigned int V_36 )
{
struct V_1 * V_37 , * V_38 ;
const T_3 * V_13 ;
unsigned int V_39 ;
F_4 (parent, np) {
V_13 = F_2 ( V_37 , L_5 , & V_39 ) ;
if ( V_13 && V_39 >= 4 && ( ( V_13 [ 0 ] >> 8 ) & 0xff ) == V_36 )
return V_37 ;
if ( ! strcmp ( V_37 -> V_35 , L_11 ) ) {
V_38 = F_16 ( V_37 , V_36 ) ;
if ( V_38 )
return V_38 ;
}
}
return NULL ;
}
static struct V_1 * F_17 ( struct V_3 * V_40 )
{
struct V_1 * V_31 , * V_37 ;
if ( V_40 -> V_41 == NULL || V_40 -> V_31 == NULL ) {
struct V_19 * V_20 = F_18 ( V_40 ) ;
if ( V_20 == NULL )
return NULL ;
return F_19 ( V_20 -> V_24 ) ;
}
V_31 = F_17 ( V_40 -> V_31 ) ;
if ( V_31 == NULL )
return NULL ;
V_37 = F_16 ( V_31 , V_40 -> V_41 -> V_36 ) ;
F_13 ( V_31 ) ;
return V_37 ;
}
struct V_1 *
F_20 ( struct V_3 * V_40 , int V_36 )
{
struct V_1 * V_31 , * V_37 ;
F_21 ( L_12 , V_40 -> V_17 , V_36 ) ;
V_31 = F_17 ( V_40 ) ;
if ( V_31 == NULL )
return NULL ;
F_21 ( L_13 , V_31 ? V_31 -> V_8 : L_14 ) ;
V_37 = F_16 ( V_31 , V_36 ) ;
F_13 ( V_31 ) ;
F_21 ( L_15 , V_37 ? V_37 -> V_8 : L_14 ) ;
return V_37 ;
}
struct V_1 *
F_22 ( struct V_10 * V_11 )
{
return F_20 ( V_11 -> V_40 , V_11 -> V_36 ) ;
}
static int
F_23 ( struct V_1 * V_2 , void * V_33 )
{
return ( ( void * ) V_2 == V_33 ) ;
}
int
F_24 ( struct V_1 * V_2 , T_1 * V_40 , T_1 * V_36 )
{
const unsigned int * V_13 ;
struct V_19 * V_20 ;
struct V_10 * V_11 = NULL ;
V_20 = F_25 ( V_2 ) ;
if ( ! V_20 || ! V_20 -> V_24 )
return - V_42 ;
if ( ! F_15 ( V_20 -> V_24 ,
F_23 , ( void * ) V_2 ) )
return - V_42 ;
V_13 = F_2 ( V_2 , L_5 , NULL ) ;
if ( ! V_13 )
return - V_42 ;
* V_40 = ( V_13 [ 0 ] >> 16 ) & 0xff ;
* V_36 = ( ( V_13 [ 0 ] >> 8 ) & 0xff ) ;
if ( ! V_9 )
return 0 ;
F_26 (dev)
if ( V_9 [ V_11 -> V_40 -> V_17 ] == * V_40 &&
V_11 -> V_36 == * V_36 ) {
* V_40 = V_11 -> V_40 -> V_17 ;
F_6 ( V_11 ) ;
return 0 ;
}
return - V_42 ;
}
void T_4
F_27 ( void )
{
struct V_22 * V_43 ;
struct V_1 * V_24 ;
V_43 = (struct V_22 * ) F_28 ( sizeof( struct V_22 ) + \
256 ) ;
if ( ! V_43 )
return;
V_24 = F_10 ( L_7 ) ;
if ( V_24 ) {
memset ( V_43 , - 1 , sizeof( struct V_22 ) + 256 ) ;
V_43 -> V_35 = L_8 ;
V_43 -> V_28 = 256 ;
V_43 -> V_29 = & V_43 [ 1 ] ;
F_29 ( V_24 , V_43 ) ;
F_13 ( V_24 ) ;
}
}
static void T_5 F_30 ( struct V_19 * V_20 )
{
struct V_3 * V_40 ;
struct V_1 * V_2 = V_20 -> V_24 ;
unsigned long V_44 ;
struct V_45 * V_46 = & V_20 -> V_47 ;
F_21 ( L_16 ,
V_2 ? V_2 -> V_8 : L_17 ) ;
V_40 = F_31 ( V_20 -> V_31 , V_20 -> V_27 , V_20 -> V_48 , V_20 ) ;
if ( V_40 == NULL ) {
F_3 ( V_26 L_18 ,
V_20 -> V_49 ) ;
return;
}
V_40 . V_11 -> V_50 = F_19 ( V_2 ) ;
V_40 -> V_51 = V_20 -> V_27 ;
V_20 -> V_40 = V_40 ;
V_44 = ( unsigned long ) V_20 -> V_52 - V_53 ;
V_46 -> V_54 = ( V_46 -> V_54 + V_44 ) & 0xffffffffu ;
V_46 -> V_55 = ( V_46 -> V_55 + V_44 ) & 0xffffffffu ;
F_32 ( V_20 ) ;
V_20 -> V_56 = V_40 -> V_16 = F_33 ( V_40 ) ;
}
static int T_4 F_34 ( void )
{
struct V_19 * V_20 , * V_21 ;
int V_57 = 0 ;
F_3 ( V_30 L_19 ) ;
if ( V_58 & V_59 ) {
F_3 ( V_30 L_20 ) ;
V_60 = 1 ;
}
F_9 (hose, tmp, &hose_list, list_node) {
if ( V_60 )
V_20 -> V_27 = V_57 ;
V_20 -> V_56 = 0xff ;
F_30 ( V_20 ) ;
F_3 ( V_30 L_21 ) ;
F_35 ( V_20 -> V_40 ) ;
if ( V_60 || V_57 <= V_20 -> V_56 )
V_57 = V_20 -> V_56 + \
V_61 ;
}
V_6 = V_57 ;
if ( V_60 )
F_7 () ;
F_36 () ;
return 0 ;
}
static struct V_19 *
F_37 ( int V_40 )
{
struct V_19 * V_20 , * V_21 ;
F_9 (hose, tmp, &hose_list, list_node)
if ( V_40 >= V_20 -> V_27 && V_40 <= V_20 -> V_56 )
return V_20 ;
return NULL ;
}
long F_38 ( long V_62 , unsigned long V_40 , unsigned long V_36 )
{
struct V_19 * V_20 ;
long V_63 = - V_64 ;
V_20 = F_37 ( V_40 ) ;
if ( ! V_20 )
return - V_42 ;
switch ( V_62 ) {
case V_65 :
return ( long ) V_20 -> V_27 ;
case V_66 :
return ( long ) V_20 -> V_67 ;
case V_68 :
return ( long ) V_20 -> V_69 ;
case V_70 :
return ( long ) V_53 ;
case V_71 :
return ( long ) V_72 ;
}
return V_63 ;
}
