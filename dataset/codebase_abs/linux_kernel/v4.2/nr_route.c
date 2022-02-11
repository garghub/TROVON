static struct V_1 * F_1 ( T_1 * V_2 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_1 ;
F_2 ( & V_4 ) ;
F_3 (nr_node, &nr_node_list)
if ( F_4 ( V_2 , & V_1 -> V_2 ) == 0 ) {
F_5 ( V_1 ) ;
V_3 = V_1 ;
break;
}
F_6 ( & V_4 ) ;
return V_3 ;
}
static struct V_5 * F_7 ( T_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_5 * V_3 = NULL ;
struct V_5 * V_5 ;
F_2 ( & V_8 ) ;
F_8 (nr_neigh, &nr_neigh_list)
if ( F_4 ( V_2 , & V_5 -> V_2 ) == 0 &&
V_5 -> V_7 == V_7 ) {
F_9 ( V_5 ) ;
V_3 = V_5 ;
break;
}
F_6 ( & V_8 ) ;
return V_3 ;
}
static int T_2 F_10 ( T_1 * V_9 , const char * V_10 ,
T_1 * V_11 , T_3 * T_3 , struct V_6 * V_7 ,
int V_12 , int V_13 )
{
struct V_1 * V_1 ;
struct V_5 * V_5 ;
struct V_14 V_14 ;
int V_15 , V_3 ;
struct V_6 * V_16 ;
if ( ( V_16 = F_11 ( V_9 ) ) != NULL ) {
F_12 ( V_16 ) ;
return - V_17 ;
}
V_1 = F_1 ( V_9 ) ;
V_5 = F_7 ( V_11 , V_7 ) ;
if ( V_5 != NULL && V_5 -> V_18 != 0 && V_12 == 0 ) {
struct V_1 * V_19 ;
F_2 ( & V_4 ) ;
F_3 (nr_nodet, &nr_node_list) {
F_13 ( V_19 ) ;
for ( V_15 = 0 ; V_15 < V_19 -> V_20 ; V_15 ++ )
if ( V_19 -> V_21 [ V_15 ] . V_22 == V_5 )
if ( V_15 < V_19 -> V_23 )
V_19 -> V_23 = V_15 ;
F_14 ( V_19 ) ;
}
F_6 ( & V_4 ) ;
}
if ( V_5 != NULL )
V_5 -> V_18 = 0 ;
if ( V_12 == 0 && V_5 != NULL && V_1 != NULL ) {
F_15 ( V_5 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
if ( V_5 == NULL ) {
if ( ( V_5 = F_17 ( sizeof( * V_5 ) , V_24 ) ) == NULL ) {
if ( V_1 )
F_16 ( V_1 ) ;
return - V_25 ;
}
V_5 -> V_2 = * V_11 ;
V_5 -> V_26 = NULL ;
V_5 -> V_11 = NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_12 = V_27 ;
V_5 -> V_28 = 0 ;
V_5 -> V_20 = 0 ;
V_5 -> V_29 = V_30 ++ ;
V_5 -> V_18 = 0 ;
F_18 ( & V_5 -> V_31 , 1 ) ;
if ( T_3 != NULL && T_3 -> V_32 > 0 ) {
V_5 -> V_26 = F_19 ( T_3 ,
sizeof( * T_3 ) ,
V_33 ) ;
if ( V_5 -> V_26 == NULL ) {
F_20 ( V_5 ) ;
if ( V_1 )
F_16 ( V_1 ) ;
return - V_25 ;
}
}
F_2 ( & V_8 ) ;
F_21 ( & V_5 -> V_34 , & V_35 ) ;
F_9 ( V_5 ) ;
F_6 ( & V_8 ) ;
}
if ( V_12 != 0 && F_4 ( V_9 , V_11 ) == 0 && ! V_5 -> V_28 )
V_5 -> V_12 = V_12 ;
if ( V_1 == NULL ) {
if ( ( V_1 = F_17 ( sizeof( * V_1 ) , V_24 ) ) == NULL ) {
if ( V_5 )
F_15 ( V_5 ) ;
return - V_25 ;
}
V_1 -> V_2 = * V_9 ;
strcpy ( V_1 -> V_10 , V_10 ) ;
V_1 -> V_23 = 0 ;
V_1 -> V_20 = 1 ;
F_18 ( & V_1 -> V_31 , 1 ) ;
F_22 ( & V_1 -> V_36 ) ;
V_1 -> V_21 [ 0 ] . V_12 = V_12 ;
V_1 -> V_21 [ 0 ] . V_13 = V_13 ;
V_1 -> V_21 [ 0 ] . V_22 = V_5 ;
F_9 ( V_5 ) ;
V_5 -> V_20 ++ ;
F_2 ( & V_4 ) ;
F_21 ( & V_1 -> V_37 , & V_38 ) ;
F_6 ( & V_4 ) ;
return 0 ;
}
F_13 ( V_1 ) ;
if ( V_12 != 0 )
strcpy ( V_1 -> V_10 , V_10 ) ;
for ( V_3 = 0 , V_15 = 0 ; V_15 < V_1 -> V_20 ; V_15 ++ ) {
if ( V_1 -> V_21 [ V_15 ] . V_22 == V_5 ) {
V_1 -> V_21 [ V_15 ] . V_12 = V_12 ;
V_1 -> V_21 [ V_15 ] . V_13 = V_13 ;
V_3 = 1 ;
break;
}
}
if ( ! V_3 ) {
if ( V_1 -> V_20 < 3 ) {
V_1 -> V_21 [ 2 ] = V_1 -> V_21 [ 1 ] ;
V_1 -> V_21 [ 1 ] = V_1 -> V_21 [ 0 ] ;
V_1 -> V_21 [ 0 ] . V_12 = V_12 ;
V_1 -> V_21 [ 0 ] . V_13 = V_13 ;
V_1 -> V_21 [ 0 ] . V_22 = V_5 ;
V_1 -> V_23 ++ ;
V_1 -> V_20 ++ ;
F_9 ( V_5 ) ;
V_5 -> V_20 ++ ;
} else {
if ( V_12 > V_1 -> V_21 [ 2 ] . V_12 ) {
V_1 -> V_21 [ 2 ] . V_22 -> V_20 -- ;
F_15 ( V_1 -> V_21 [ 2 ] . V_22 ) ;
if ( V_1 -> V_21 [ 2 ] . V_22 -> V_20 == 0 && ! V_1 -> V_21 [ 2 ] . V_22 -> V_28 )
F_23 ( V_1 -> V_21 [ 2 ] . V_22 ) ;
V_1 -> V_21 [ 2 ] . V_12 = V_12 ;
V_1 -> V_21 [ 2 ] . V_13 = V_13 ;
V_1 -> V_21 [ 2 ] . V_22 = V_5 ;
F_9 ( V_5 ) ;
V_5 -> V_20 ++ ;
}
}
}
switch ( V_1 -> V_20 ) {
case 3 :
if ( V_1 -> V_21 [ 1 ] . V_12 > V_1 -> V_21 [ 0 ] . V_12 ) {
switch ( V_1 -> V_23 ) {
case 0 :
V_1 -> V_23 = 1 ;
break;
case 1 :
V_1 -> V_23 = 0 ;
break;
}
V_14 = V_1 -> V_21 [ 0 ] ;
V_1 -> V_21 [ 0 ] = V_1 -> V_21 [ 1 ] ;
V_1 -> V_21 [ 1 ] = V_14 ;
}
if ( V_1 -> V_21 [ 2 ] . V_12 > V_1 -> V_21 [ 1 ] . V_12 ) {
switch ( V_1 -> V_23 ) {
case 1 : V_1 -> V_23 = 2 ;
break;
case 2 : V_1 -> V_23 = 1 ;
break;
default:
break;
}
V_14 = V_1 -> V_21 [ 1 ] ;
V_1 -> V_21 [ 1 ] = V_1 -> V_21 [ 2 ] ;
V_1 -> V_21 [ 2 ] = V_14 ;
}
case 2 :
if ( V_1 -> V_21 [ 1 ] . V_12 > V_1 -> V_21 [ 0 ] . V_12 ) {
switch ( V_1 -> V_23 ) {
case 0 : V_1 -> V_23 = 1 ;
break;
case 1 : V_1 -> V_23 = 0 ;
break;
default: break;
}
V_14 = V_1 -> V_21 [ 0 ] ;
V_1 -> V_21 [ 0 ] = V_1 -> V_21 [ 1 ] ;
V_1 -> V_21 [ 1 ] = V_14 ;
}
case 1 :
break;
}
for ( V_15 = 0 ; V_15 < V_1 -> V_20 ; V_15 ++ ) {
if ( V_1 -> V_21 [ V_15 ] . V_22 == V_5 ) {
if ( V_15 < V_1 -> V_23 )
V_1 -> V_23 = V_15 ;
break;
}
}
F_15 ( V_5 ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
static inline void F_24 ( struct V_1 * V_1 )
{
F_25 ( & V_1 -> V_37 ) ;
F_16 ( V_1 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_2 ( & V_4 ) ;
F_24 ( V_1 ) ;
F_6 ( & V_4 ) ;
}
static inline void F_27 ( struct V_5 * V_5 )
{
F_25 ( & V_5 -> V_34 ) ;
F_15 ( V_5 ) ;
}
static void F_23 ( struct V_5 * V_5 )
{
F_2 ( & V_8 ) ;
F_27 ( V_5 ) ;
F_6 ( & V_8 ) ;
}
static int F_28 ( T_1 * V_2 , T_1 * V_22 , struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_5 * V_5 ;
int V_15 ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 == NULL )
return - V_17 ;
V_5 = F_7 ( V_22 , V_7 ) ;
if ( V_5 == NULL ) {
F_16 ( V_1 ) ;
return - V_17 ;
}
F_13 ( V_1 ) ;
for ( V_15 = 0 ; V_15 < V_1 -> V_20 ; V_15 ++ ) {
if ( V_1 -> V_21 [ V_15 ] . V_22 == V_5 ) {
V_5 -> V_20 -- ;
F_15 ( V_5 ) ;
if ( V_5 -> V_20 == 0 && ! V_5 -> V_28 )
F_23 ( V_5 ) ;
F_15 ( V_5 ) ;
V_1 -> V_20 -- ;
if ( V_1 -> V_20 == 0 ) {
F_26 ( V_1 ) ;
} else {
switch ( V_15 ) {
case 0 :
V_1 -> V_21 [ 0 ] = V_1 -> V_21 [ 1 ] ;
case 1 :
V_1 -> V_21 [ 1 ] = V_1 -> V_21 [ 2 ] ;
case 2 :
break;
}
F_16 ( V_1 ) ;
}
F_14 ( V_1 ) ;
return 0 ;
}
}
F_15 ( V_5 ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return - V_17 ;
}
static int T_2 F_29 ( T_1 * V_2 ,
T_3 * T_3 , struct V_6 * V_7 , unsigned int V_12 )
{
struct V_5 * V_5 ;
V_5 = F_7 ( V_2 , V_7 ) ;
if ( V_5 ) {
V_5 -> V_12 = V_12 ;
V_5 -> V_28 = 1 ;
F_15 ( V_5 ) ;
return 0 ;
}
if ( ( V_5 = F_17 ( sizeof( * V_5 ) , V_24 ) ) == NULL )
return - V_25 ;
V_5 -> V_2 = * V_2 ;
V_5 -> V_26 = NULL ;
V_5 -> V_11 = NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_28 = 1 ;
V_5 -> V_20 = 0 ;
V_5 -> V_29 = V_30 ++ ;
V_5 -> V_18 = 0 ;
F_18 ( & V_5 -> V_31 , 1 ) ;
if ( T_3 != NULL && T_3 -> V_32 > 0 ) {
V_5 -> V_26 = F_19 ( T_3 , sizeof( * T_3 ) ,
V_33 ) ;
if ( V_5 -> V_26 == NULL ) {
F_20 ( V_5 ) ;
return - V_25 ;
}
}
F_2 ( & V_8 ) ;
F_21 ( & V_5 -> V_34 , & V_35 ) ;
F_6 ( & V_8 ) ;
return 0 ;
}
static int F_30 ( T_1 * V_2 , struct V_6 * V_7 , unsigned int V_12 )
{
struct V_5 * V_5 ;
V_5 = F_7 ( V_2 , V_7 ) ;
if ( V_5 == NULL ) return - V_17 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_28 = 0 ;
if ( V_5 -> V_20 == 0 )
F_23 ( V_5 ) ;
F_15 ( V_5 ) ;
return 0 ;
}
static int F_31 ( void )
{
struct V_5 * V_5 ;
struct V_1 * V_39 ;
struct V_40 * V_41 ;
int V_15 ;
F_2 ( & V_4 ) ;
F_32 (s, nodet, &nr_node_list) {
F_13 ( V_39 ) ;
for ( V_15 = 0 ; V_15 < V_39 -> V_20 ; V_15 ++ ) {
switch ( V_39 -> V_21 [ V_15 ] . V_13 ) {
case 0 :
break;
case 1 :
V_5 = V_39 -> V_21 [ V_15 ] . V_22 ;
V_5 -> V_20 -- ;
F_15 ( V_5 ) ;
if ( V_5 -> V_20 == 0 && ! V_5 -> V_28 )
F_23 ( V_5 ) ;
V_39 -> V_20 -- ;
switch ( V_15 ) {
case 0 :
V_39 -> V_21 [ 0 ] = V_39 -> V_21 [ 1 ] ;
case 1 :
V_39 -> V_21 [ 1 ] = V_39 -> V_21 [ 2 ] ;
case 2 :
break;
}
break;
default:
V_39 -> V_21 [ V_15 ] . V_13 -- ;
break;
}
}
if ( V_39 -> V_20 <= 0 )
F_33 ( V_39 ) ;
F_14 ( V_39 ) ;
}
F_6 ( & V_4 ) ;
return 0 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_5 * V_39 ;
struct V_40 * V_41 , * V_42 ;
struct V_1 * V_43 ;
int V_15 ;
F_2 ( & V_8 ) ;
F_35 (s, nodet, &nr_neigh_list) {
if ( V_39 -> V_7 == V_7 ) {
F_2 ( & V_4 ) ;
F_32 (t, node2t, &nr_node_list) {
F_13 ( V_43 ) ;
for ( V_15 = 0 ; V_15 < V_43 -> V_20 ; V_15 ++ ) {
if ( V_43 -> V_21 [ V_15 ] . V_22 == V_39 ) {
V_43 -> V_20 -- ;
switch ( V_15 ) {
case 0 :
V_43 -> V_21 [ 0 ] = V_43 -> V_21 [ 1 ] ;
case 1 :
V_43 -> V_21 [ 1 ] = V_43 -> V_21 [ 2 ] ;
case 2 :
break;
}
}
}
if ( V_43 -> V_20 <= 0 )
F_33 ( V_43 ) ;
F_14 ( V_43 ) ;
}
F_6 ( & V_4 ) ;
F_36 ( V_39 ) ;
}
}
F_6 ( & V_8 ) ;
}
static struct V_6 * F_37 ( char * V_44 )
{
struct V_6 * V_7 ;
if ( ( V_7 = F_38 ( & V_45 , V_44 ) ) == NULL )
return NULL ;
if ( ( V_7 -> V_46 & V_47 ) && V_7 -> type == V_48 )
return V_7 ;
F_12 ( V_7 ) ;
return NULL ;
}
struct V_6 * F_39 ( void )
{
struct V_6 * V_7 , * V_49 = NULL ;
F_40 () ;
F_41 (&init_net, dev) {
if ( ( V_7 -> V_46 & V_47 ) && V_7 -> type == V_50 )
if ( V_49 == NULL || strncmp ( V_7 -> V_51 , V_49 -> V_51 , 3 ) < 0 )
V_49 = V_7 ;
}
if ( V_49 )
F_42 ( V_49 ) ;
F_43 () ;
return V_49 ;
}
struct V_6 * F_11 ( T_1 * V_52 )
{
struct V_6 * V_7 ;
F_40 () ;
F_41 (&init_net, dev) {
if ( ( V_7 -> V_46 & V_47 ) && V_7 -> type == V_50 &&
F_4 ( V_52 , ( T_1 * ) V_7 -> V_53 ) == 0 ) {
F_42 ( V_7 ) ;
goto V_54;
}
}
V_7 = NULL ;
V_54:
F_43 () ;
return V_7 ;
}
static T_3 * F_44 ( T_3 * V_55 , int V_56 ,
T_1 * V_57 )
{
int V_15 ;
if ( V_56 == 0 )
return NULL ;
for ( V_15 = 0 ; V_15 < V_56 ; V_15 ++ ) {
V_55 -> V_58 [ V_15 ] = V_57 [ V_15 ] ;
V_55 -> V_59 [ V_15 ] = 0 ;
}
V_55 -> V_32 = V_56 ;
V_55 -> V_60 = - 1 ;
return V_55 ;
}
int F_45 ( unsigned int V_61 , void T_4 * V_62 )
{
struct V_63 V_14 ;
struct V_6 * V_7 ;
T_3 V_55 ;
int V_64 ;
switch ( V_61 ) {
case V_65 :
if ( F_46 ( & V_14 , V_62 , sizeof( struct V_63 ) ) )
return - V_66 ;
if ( V_14 . V_56 > V_67 )
return - V_17 ;
if ( ( V_7 = F_37 ( V_14 . V_68 ) ) == NULL )
return - V_17 ;
switch ( V_14 . type ) {
case V_69 :
if ( F_47 ( V_14 . V_10 , 7 ) == 7 ) {
V_64 = - V_17 ;
break;
}
V_64 = F_10 ( & V_14 . V_2 ,
V_14 . V_10 ,
& V_14 . V_22 ,
F_44 ( & V_55 , V_14 . V_56 ,
V_14 . V_57 ) ,
V_7 , V_14 . V_12 ,
V_14 . V_13 ) ;
break;
case V_70 :
V_64 = F_29 ( & V_14 . V_2 ,
F_44 ( & V_55 , V_14 . V_56 ,
V_14 . V_57 ) ,
V_7 , V_14 . V_12 ) ;
break;
default:
V_64 = - V_17 ;
}
F_12 ( V_7 ) ;
return V_64 ;
case V_71 :
if ( F_46 ( & V_14 , V_62 , sizeof( struct V_63 ) ) )
return - V_66 ;
if ( ( V_7 = F_37 ( V_14 . V_68 ) ) == NULL )
return - V_17 ;
switch ( V_14 . type ) {
case V_69 :
V_64 = F_28 ( & V_14 . V_2 ,
& V_14 . V_22 , V_7 ) ;
break;
case V_70 :
V_64 = F_30 ( & V_14 . V_2 ,
V_7 , V_14 . V_12 ) ;
break;
default:
V_64 = - V_17 ;
}
F_12 ( V_7 ) ;
return V_64 ;
case V_72 :
return F_31 () ;
default:
return - V_17 ;
}
return 0 ;
}
void F_48 ( T_5 * V_11 , int V_73 )
{
struct V_5 * V_39 , * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
F_2 ( & V_8 ) ;
F_8 (s, &nr_neigh_list) {
if ( V_39 -> V_11 == V_11 ) {
F_9 ( V_39 ) ;
V_5 = V_39 ;
break;
}
}
F_6 ( & V_8 ) ;
if ( V_5 == NULL )
return;
V_5 -> V_11 = NULL ;
F_49 ( V_11 ) ;
if ( ++ V_5 -> V_18 < V_74 ) {
F_15 ( V_5 ) ;
return;
}
F_2 ( & V_4 ) ;
F_3 (nr_node, &nr_node_list) {
F_13 ( V_1 ) ;
if ( V_1 -> V_23 < V_1 -> V_20 &&
V_1 -> V_21 [ V_1 -> V_23 ] . V_22 == V_5 )
V_1 -> V_23 ++ ;
F_14 ( V_1 ) ;
}
F_6 ( & V_4 ) ;
F_15 ( V_5 ) ;
}
int F_50 ( struct V_75 * V_76 , T_5 * V_11 )
{
T_1 * V_77 , * V_78 ;
struct V_5 * V_5 ;
struct V_1 * V_1 ;
struct V_6 * V_7 ;
unsigned char * V_79 ;
T_5 * V_80 ;
int V_64 ;
struct V_75 * V_81 ;
V_77 = ( T_1 * ) ( V_76 -> V_82 + 0 ) ;
V_78 = ( T_1 * ) ( V_76 -> V_82 + 7 ) ;
if ( V_11 != NULL ) {
V_64 = F_10 ( V_77 , L_1 , & V_11 -> V_83 , V_11 -> V_26 ,
V_11 -> V_84 -> V_7 , 0 ,
V_85 ) ;
if ( V_64 )
return V_64 ;
}
if ( ( V_7 = F_11 ( V_78 ) ) != NULL ) {
if ( V_11 == NULL )
V_64 = F_51 ( V_76 ) ;
else
V_64 = F_52 ( V_76 , V_7 ) ;
F_12 ( V_7 ) ;
return V_64 ;
}
if ( ! V_86 && V_11 != NULL )
return 0 ;
if ( V_76 -> V_82 [ 14 ] == 1 ) {
return 0 ;
}
V_1 = F_1 ( V_78 ) ;
if ( V_1 == NULL )
return 0 ;
F_13 ( V_1 ) ;
if ( V_1 -> V_23 >= V_1 -> V_20 ) {
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
V_5 = V_1 -> V_21 [ V_1 -> V_23 ] . V_22 ;
if ( ( V_7 = F_39 () ) == NULL ) {
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
if ( ( V_81 = F_53 ( V_76 , V_7 -> V_87 , 0 , V_24 ) ) == NULL ) {
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
F_12 ( V_7 ) ;
return 0 ;
}
F_54 ( V_76 ) ;
V_76 = V_81 ;
V_76 -> V_82 [ 14 ] -- ;
V_79 = F_55 ( V_76 , 1 ) ;
* V_79 = V_88 ;
V_80 = V_5 -> V_11 ;
V_5 -> V_11 = F_56 ( V_76 , 256 ,
( T_1 * ) V_7 -> V_53 ,
& V_5 -> V_2 ,
V_5 -> V_26 , V_5 -> V_7 ) ;
if ( V_80 )
F_49 ( V_80 ) ;
F_12 ( V_7 ) ;
V_64 = ( V_5 -> V_11 != NULL ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return V_64 ;
}
static void * F_57 ( struct V_89 * V_90 , T_6 * V_91 )
{
F_2 ( & V_4 ) ;
return F_58 ( & V_38 , * V_91 ) ;
}
static void * F_59 ( struct V_89 * V_90 , void * V_92 , T_6 * V_91 )
{
return F_60 ( V_92 , & V_38 , V_91 ) ;
}
static void F_61 ( struct V_89 * V_90 , void * V_92 )
{
F_6 ( & V_4 ) ;
}
static int F_62 ( struct V_89 * V_90 , void * V_92 )
{
char V_93 [ 11 ] ;
int V_15 ;
if ( V_92 == V_94 )
F_63 ( V_90 ,
L_2 ) ;
else {
struct V_1 * V_1 = F_64 ( V_92 , struct V_1 ,
V_37 ) ;
F_13 ( V_1 ) ;
F_65 ( V_90 , L_3 ,
F_66 ( V_93 , & V_1 -> V_2 ) ,
( V_1 -> V_10 [ 0 ] == '\0' ) ? L_4 : V_1 -> V_10 ,
V_1 -> V_23 + 1 ,
V_1 -> V_20 ) ;
for ( V_15 = 0 ; V_15 < V_1 -> V_20 ; V_15 ++ ) {
F_65 ( V_90 , L_5 ,
V_1 -> V_21 [ V_15 ] . V_12 ,
V_1 -> V_21 [ V_15 ] . V_13 ,
V_1 -> V_21 [ V_15 ] . V_22 -> V_29 ) ;
}
F_14 ( V_1 ) ;
F_63 ( V_90 , L_6 ) ;
}
return 0 ;
}
static int F_67 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
return F_68 ( V_96 , & V_97 ) ;
}
static void * F_69 ( struct V_89 * V_90 , T_6 * V_91 )
{
F_2 ( & V_8 ) ;
return F_58 ( & V_35 , * V_91 ) ;
}
static void * F_70 ( struct V_89 * V_90 , void * V_92 , T_6 * V_91 )
{
return F_60 ( V_92 , & V_35 , V_91 ) ;
}
static void F_71 ( struct V_89 * V_90 , void * V_92 )
{
F_6 ( & V_8 ) ;
}
static int F_72 ( struct V_89 * V_90 , void * V_92 )
{
char V_93 [ 11 ] ;
int V_15 ;
if ( V_92 == V_94 )
F_63 ( V_90 , L_7 ) ;
else {
struct V_5 * V_5 ;
V_5 = F_64 ( V_92 , struct V_5 , V_34 ) ;
F_65 ( V_90 , L_8 ,
V_5 -> V_29 ,
F_66 ( V_93 , & V_5 -> V_2 ) ,
V_5 -> V_7 ? V_5 -> V_7 -> V_51 : L_9 ,
V_5 -> V_12 ,
V_5 -> V_28 ,
V_5 -> V_20 ,
V_5 -> V_18 ) ;
if ( V_5 -> V_26 != NULL ) {
for ( V_15 = 0 ; V_15 < V_5 -> V_26 -> V_32 ; V_15 ++ )
F_65 ( V_90 , L_10 ,
F_66 ( V_93 , & V_5 -> V_26 -> V_58 [ V_15 ] ) ) ;
}
F_63 ( V_90 , L_6 ) ;
}
return 0 ;
}
static int F_73 ( struct V_95 * V_95 , struct V_96 * V_96 )
{
return F_68 ( V_96 , & V_98 ) ;
}
void T_7 F_74 ( void )
{
struct V_5 * V_39 = NULL ;
struct V_1 * V_43 = NULL ;
struct V_40 * V_41 ;
F_2 ( & V_8 ) ;
F_2 ( & V_4 ) ;
F_32 (t, nodet, &nr_node_list) {
F_13 ( V_43 ) ;
F_33 ( V_43 ) ;
F_14 ( V_43 ) ;
}
F_35 (s, nodet, &nr_neigh_list) {
while( V_39 -> V_20 ) {
V_39 -> V_20 -- ;
F_15 ( V_39 ) ;
}
F_36 ( V_39 ) ;
}
F_6 ( & V_4 ) ;
F_6 ( & V_8 ) ;
}
