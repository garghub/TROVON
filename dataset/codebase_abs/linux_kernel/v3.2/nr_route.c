static struct V_1 * F_1 ( T_1 * V_2 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (nr_node, node, &nr_node_list)
if ( F_4 ( V_2 , & V_1 -> V_2 ) == 0 ) {
F_5 ( V_1 ) ;
V_3 = V_1 ;
break;
}
F_6 ( & V_6 ) ;
return V_3 ;
}
static struct V_7 * F_7 ( T_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_7 * V_3 = NULL ;
struct V_7 * V_7 ;
struct V_4 * V_5 ;
F_2 ( & V_10 ) ;
F_8 (nr_neigh, node, &nr_neigh_list)
if ( F_4 ( V_2 , & V_7 -> V_2 ) == 0 &&
V_7 -> V_9 == V_9 ) {
F_9 ( V_7 ) ;
V_3 = V_7 ;
break;
}
F_6 ( & V_10 ) ;
return V_3 ;
}
static int T_2 F_10 ( T_1 * V_11 , const char * V_12 ,
T_1 * V_13 , T_3 * T_3 , struct V_8 * V_9 ,
int V_14 , int V_15 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 ;
struct V_16 V_16 ;
int V_17 , V_3 ;
struct V_8 * V_18 ;
if ( ( V_18 = F_11 ( V_11 ) ) != NULL ) {
F_12 ( V_18 ) ;
return - V_19 ;
}
V_1 = F_1 ( V_11 ) ;
V_7 = F_7 ( V_13 , V_9 ) ;
if ( V_7 != NULL && V_7 -> V_20 != 0 && V_14 == 0 ) {
struct V_1 * V_21 ;
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (nr_nodet, node, &nr_node_list) {
F_13 ( V_21 ) ;
for ( V_17 = 0 ; V_17 < V_21 -> V_22 ; V_17 ++ )
if ( V_21 -> V_23 [ V_17 ] . V_24 == V_7 )
if ( V_17 < V_21 -> V_25 )
V_21 -> V_25 = V_17 ;
F_14 ( V_21 ) ;
}
F_6 ( & V_6 ) ;
}
if ( V_7 != NULL )
V_7 -> V_20 = 0 ;
if ( V_14 == 0 && V_7 != NULL && V_1 != NULL ) {
F_15 ( V_7 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
if ( V_7 == NULL ) {
if ( ( V_7 = F_17 ( sizeof( * V_7 ) , V_26 ) ) == NULL ) {
if ( V_1 )
F_16 ( V_1 ) ;
return - V_27 ;
}
V_7 -> V_2 = * V_13 ;
V_7 -> V_28 = NULL ;
V_7 -> V_13 = NULL ;
V_7 -> V_9 = V_9 ;
V_7 -> V_14 = V_29 ;
V_7 -> V_30 = 0 ;
V_7 -> V_22 = 0 ;
V_7 -> V_31 = V_32 ++ ;
V_7 -> V_20 = 0 ;
F_18 ( & V_7 -> V_33 , 1 ) ;
if ( T_3 != NULL && T_3 -> V_34 > 0 ) {
V_7 -> V_28 = F_19 ( T_3 ,
sizeof( * T_3 ) ,
V_35 ) ;
if ( V_7 -> V_28 == NULL ) {
F_20 ( V_7 ) ;
if ( V_1 )
F_16 ( V_1 ) ;
return - V_27 ;
}
}
F_2 ( & V_10 ) ;
F_21 ( & V_7 -> V_36 , & V_37 ) ;
F_9 ( V_7 ) ;
F_6 ( & V_10 ) ;
}
if ( V_14 != 0 && F_4 ( V_11 , V_13 ) == 0 && ! V_7 -> V_30 )
V_7 -> V_14 = V_14 ;
if ( V_1 == NULL ) {
if ( ( V_1 = F_17 ( sizeof( * V_1 ) , V_26 ) ) == NULL ) {
if ( V_7 )
F_15 ( V_7 ) ;
return - V_27 ;
}
V_1 -> V_2 = * V_11 ;
strcpy ( V_1 -> V_12 , V_12 ) ;
V_1 -> V_25 = 0 ;
V_1 -> V_22 = 1 ;
F_18 ( & V_1 -> V_33 , 1 ) ;
F_22 ( & V_1 -> V_38 ) ;
V_1 -> V_23 [ 0 ] . V_14 = V_14 ;
V_1 -> V_23 [ 0 ] . V_15 = V_15 ;
V_1 -> V_23 [ 0 ] . V_24 = V_7 ;
F_9 ( V_7 ) ;
V_7 -> V_22 ++ ;
F_2 ( & V_6 ) ;
F_21 ( & V_1 -> V_39 , & V_40 ) ;
F_6 ( & V_6 ) ;
return 0 ;
}
F_13 ( V_1 ) ;
if ( V_14 != 0 )
strcpy ( V_1 -> V_12 , V_12 ) ;
for ( V_3 = 0 , V_17 = 0 ; V_17 < V_1 -> V_22 ; V_17 ++ ) {
if ( V_1 -> V_23 [ V_17 ] . V_24 == V_7 ) {
V_1 -> V_23 [ V_17 ] . V_14 = V_14 ;
V_1 -> V_23 [ V_17 ] . V_15 = V_15 ;
V_3 = 1 ;
break;
}
}
if ( ! V_3 ) {
if ( V_1 -> V_22 < 3 ) {
V_1 -> V_23 [ 2 ] = V_1 -> V_23 [ 1 ] ;
V_1 -> V_23 [ 1 ] = V_1 -> V_23 [ 0 ] ;
V_1 -> V_23 [ 0 ] . V_14 = V_14 ;
V_1 -> V_23 [ 0 ] . V_15 = V_15 ;
V_1 -> V_23 [ 0 ] . V_24 = V_7 ;
V_1 -> V_25 ++ ;
V_1 -> V_22 ++ ;
F_9 ( V_7 ) ;
V_7 -> V_22 ++ ;
} else {
if ( V_14 > V_1 -> V_23 [ 2 ] . V_14 ) {
V_1 -> V_23 [ 2 ] . V_24 -> V_22 -- ;
F_15 ( V_1 -> V_23 [ 2 ] . V_24 ) ;
if ( V_1 -> V_23 [ 2 ] . V_24 -> V_22 == 0 && ! V_1 -> V_23 [ 2 ] . V_24 -> V_30 )
F_23 ( V_1 -> V_23 [ 2 ] . V_24 ) ;
V_1 -> V_23 [ 2 ] . V_14 = V_14 ;
V_1 -> V_23 [ 2 ] . V_15 = V_15 ;
V_1 -> V_23 [ 2 ] . V_24 = V_7 ;
F_9 ( V_7 ) ;
V_7 -> V_22 ++ ;
}
}
}
switch ( V_1 -> V_22 ) {
case 3 :
if ( V_1 -> V_23 [ 1 ] . V_14 > V_1 -> V_23 [ 0 ] . V_14 ) {
switch ( V_1 -> V_25 ) {
case 0 :
V_1 -> V_25 = 1 ;
break;
case 1 :
V_1 -> V_25 = 0 ;
break;
}
V_16 = V_1 -> V_23 [ 0 ] ;
V_1 -> V_23 [ 0 ] = V_1 -> V_23 [ 1 ] ;
V_1 -> V_23 [ 1 ] = V_16 ;
}
if ( V_1 -> V_23 [ 2 ] . V_14 > V_1 -> V_23 [ 1 ] . V_14 ) {
switch ( V_1 -> V_25 ) {
case 1 : V_1 -> V_25 = 2 ;
break;
case 2 : V_1 -> V_25 = 1 ;
break;
default:
break;
}
V_16 = V_1 -> V_23 [ 1 ] ;
V_1 -> V_23 [ 1 ] = V_1 -> V_23 [ 2 ] ;
V_1 -> V_23 [ 2 ] = V_16 ;
}
case 2 :
if ( V_1 -> V_23 [ 1 ] . V_14 > V_1 -> V_23 [ 0 ] . V_14 ) {
switch ( V_1 -> V_25 ) {
case 0 : V_1 -> V_25 = 1 ;
break;
case 1 : V_1 -> V_25 = 0 ;
break;
default: break;
}
V_16 = V_1 -> V_23 [ 0 ] ;
V_1 -> V_23 [ 0 ] = V_1 -> V_23 [ 1 ] ;
V_1 -> V_23 [ 1 ] = V_16 ;
}
case 1 :
break;
}
for ( V_17 = 0 ; V_17 < V_1 -> V_22 ; V_17 ++ ) {
if ( V_1 -> V_23 [ V_17 ] . V_24 == V_7 ) {
if ( V_17 < V_1 -> V_25 )
V_1 -> V_25 = V_17 ;
break;
}
}
F_15 ( V_7 ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
static inline void F_24 ( struct V_1 * V_1 )
{
F_25 ( & V_1 -> V_39 ) ;
F_16 ( V_1 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_2 ( & V_6 ) ;
F_24 ( V_1 ) ;
F_6 ( & V_6 ) ;
}
static inline void F_27 ( struct V_7 * V_7 )
{
F_25 ( & V_7 -> V_36 ) ;
F_15 ( V_7 ) ;
}
static void F_23 ( struct V_7 * V_7 )
{
F_2 ( & V_10 ) ;
F_27 ( V_7 ) ;
F_6 ( & V_10 ) ;
}
static int F_28 ( T_1 * V_2 , T_1 * V_24 , struct V_8 * V_9 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 ;
int V_17 ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 == NULL )
return - V_19 ;
V_7 = F_7 ( V_24 , V_9 ) ;
if ( V_7 == NULL ) {
F_16 ( V_1 ) ;
return - V_19 ;
}
F_13 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < V_1 -> V_22 ; V_17 ++ ) {
if ( V_1 -> V_23 [ V_17 ] . V_24 == V_7 ) {
V_7 -> V_22 -- ;
F_15 ( V_7 ) ;
if ( V_7 -> V_22 == 0 && ! V_7 -> V_30 )
F_23 ( V_7 ) ;
F_15 ( V_7 ) ;
V_1 -> V_22 -- ;
if ( V_1 -> V_22 == 0 ) {
F_26 ( V_1 ) ;
} else {
switch ( V_17 ) {
case 0 :
V_1 -> V_23 [ 0 ] = V_1 -> V_23 [ 1 ] ;
case 1 :
V_1 -> V_23 [ 1 ] = V_1 -> V_23 [ 2 ] ;
case 2 :
break;
}
F_16 ( V_1 ) ;
}
F_14 ( V_1 ) ;
return 0 ;
}
}
F_15 ( V_7 ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return - V_19 ;
}
static int T_2 F_29 ( T_1 * V_2 ,
T_3 * T_3 , struct V_8 * V_9 , unsigned int V_14 )
{
struct V_7 * V_7 ;
V_7 = F_7 ( V_2 , V_9 ) ;
if ( V_7 ) {
V_7 -> V_14 = V_14 ;
V_7 -> V_30 = 1 ;
F_15 ( V_7 ) ;
return 0 ;
}
if ( ( V_7 = F_17 ( sizeof( * V_7 ) , V_26 ) ) == NULL )
return - V_27 ;
V_7 -> V_2 = * V_2 ;
V_7 -> V_28 = NULL ;
V_7 -> V_13 = NULL ;
V_7 -> V_9 = V_9 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_30 = 1 ;
V_7 -> V_22 = 0 ;
V_7 -> V_31 = V_32 ++ ;
V_7 -> V_20 = 0 ;
F_18 ( & V_7 -> V_33 , 1 ) ;
if ( T_3 != NULL && T_3 -> V_34 > 0 ) {
V_7 -> V_28 = F_19 ( T_3 , sizeof( * T_3 ) ,
V_35 ) ;
if ( V_7 -> V_28 == NULL ) {
F_20 ( V_7 ) ;
return - V_27 ;
}
}
F_2 ( & V_10 ) ;
F_21 ( & V_7 -> V_36 , & V_37 ) ;
F_6 ( & V_10 ) ;
return 0 ;
}
static int F_30 ( T_1 * V_2 , struct V_8 * V_9 , unsigned int V_14 )
{
struct V_7 * V_7 ;
V_7 = F_7 ( V_2 , V_9 ) ;
if ( V_7 == NULL ) return - V_19 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_30 = 0 ;
if ( V_7 -> V_22 == 0 )
F_23 ( V_7 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
static int F_31 ( void )
{
struct V_7 * V_7 ;
struct V_1 * V_41 ;
struct V_4 * V_5 , * V_42 ;
int V_17 ;
F_2 ( & V_6 ) ;
F_32 (s, node, nodet, &nr_node_list) {
F_13 ( V_41 ) ;
for ( V_17 = 0 ; V_17 < V_41 -> V_22 ; V_17 ++ ) {
switch ( V_41 -> V_23 [ V_17 ] . V_15 ) {
case 0 :
break;
case 1 :
V_7 = V_41 -> V_23 [ V_17 ] . V_24 ;
V_7 -> V_22 -- ;
F_15 ( V_7 ) ;
if ( V_7 -> V_22 == 0 && ! V_7 -> V_30 )
F_23 ( V_7 ) ;
V_41 -> V_22 -- ;
switch ( V_17 ) {
case 0 :
V_41 -> V_23 [ 0 ] = V_41 -> V_23 [ 1 ] ;
case 1 :
V_41 -> V_23 [ 1 ] = V_41 -> V_23 [ 2 ] ;
case 2 :
break;
}
break;
default:
V_41 -> V_23 [ V_17 ] . V_15 -- ;
break;
}
}
if ( V_41 -> V_22 <= 0 )
F_33 ( V_41 ) ;
F_14 ( V_41 ) ;
}
F_6 ( & V_6 ) ;
return 0 ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_7 * V_41 ;
struct V_4 * V_5 , * V_42 , * V_43 , * V_44 ;
struct V_1 * V_45 ;
int V_17 ;
F_2 ( & V_10 ) ;
F_35 (s, node, nodet, &nr_neigh_list) {
if ( V_41 -> V_9 == V_9 ) {
F_2 ( & V_6 ) ;
F_32 (t, node2, node2t, &nr_node_list) {
F_13 ( V_45 ) ;
for ( V_17 = 0 ; V_17 < V_45 -> V_22 ; V_17 ++ ) {
if ( V_45 -> V_23 [ V_17 ] . V_24 == V_41 ) {
V_45 -> V_22 -- ;
switch ( V_17 ) {
case 0 :
V_45 -> V_23 [ 0 ] = V_45 -> V_23 [ 1 ] ;
case 1 :
V_45 -> V_23 [ 1 ] = V_45 -> V_23 [ 2 ] ;
case 2 :
break;
}
}
}
if ( V_45 -> V_22 <= 0 )
F_33 ( V_45 ) ;
F_14 ( V_45 ) ;
}
F_6 ( & V_6 ) ;
F_36 ( V_41 ) ;
}
}
F_6 ( & V_10 ) ;
}
static struct V_8 * F_37 ( char * V_46 )
{
struct V_8 * V_9 ;
if ( ( V_9 = F_38 ( & V_47 , V_46 ) ) == NULL )
return NULL ;
if ( ( V_9 -> V_48 & V_49 ) && V_9 -> type == V_50 )
return V_9 ;
F_12 ( V_9 ) ;
return NULL ;
}
struct V_8 * F_39 ( void )
{
struct V_8 * V_9 , * V_51 = NULL ;
F_40 () ;
F_41 (&init_net, dev) {
if ( ( V_9 -> V_48 & V_49 ) && V_9 -> type == V_52 )
if ( V_51 == NULL || strncmp ( V_9 -> V_53 , V_51 -> V_53 , 3 ) < 0 )
V_51 = V_9 ;
}
if ( V_51 )
F_42 ( V_51 ) ;
F_43 () ;
return V_51 ;
}
struct V_8 * F_11 ( T_1 * V_54 )
{
struct V_8 * V_9 ;
F_40 () ;
F_41 (&init_net, dev) {
if ( ( V_9 -> V_48 & V_49 ) && V_9 -> type == V_52 &&
F_4 ( V_54 , ( T_1 * ) V_9 -> V_55 ) == 0 ) {
F_42 ( V_9 ) ;
goto V_56;
}
}
V_9 = NULL ;
V_56:
F_43 () ;
return V_9 ;
}
static T_3 * F_44 ( T_3 * V_57 , int V_58 ,
T_1 * V_59 )
{
int V_17 ;
if ( V_58 == 0 )
return NULL ;
for ( V_17 = 0 ; V_17 < V_58 ; V_17 ++ ) {
V_57 -> V_60 [ V_17 ] = V_59 [ V_17 ] ;
V_57 -> V_61 [ V_17 ] = 0 ;
}
V_57 -> V_34 = V_58 ;
V_57 -> V_62 = - 1 ;
return V_57 ;
}
int F_45 ( unsigned int V_63 , void T_4 * V_64 )
{
struct V_65 V_16 ;
struct V_8 * V_9 ;
T_3 V_57 ;
int V_66 ;
switch ( V_63 ) {
case V_67 :
if ( F_46 ( & V_16 , V_64 , sizeof( struct V_65 ) ) )
return - V_68 ;
if ( ( V_9 = F_37 ( V_16 . V_69 ) ) == NULL )
return - V_19 ;
if ( V_16 . V_58 < 0 || V_16 . V_58 > V_70 ) {
F_12 ( V_9 ) ;
return - V_19 ;
}
switch ( V_16 . type ) {
case V_71 :
V_66 = F_10 ( & V_16 . V_2 ,
V_16 . V_12 ,
& V_16 . V_24 ,
F_44 ( & V_57 , V_16 . V_58 ,
V_16 . V_59 ) ,
V_9 , V_16 . V_14 ,
V_16 . V_15 ) ;
break;
case V_72 :
V_66 = F_29 ( & V_16 . V_2 ,
F_44 ( & V_57 , V_16 . V_58 ,
V_16 . V_59 ) ,
V_9 , V_16 . V_14 ) ;
break;
default:
V_66 = - V_19 ;
}
F_12 ( V_9 ) ;
return V_66 ;
case V_73 :
if ( F_46 ( & V_16 , V_64 , sizeof( struct V_65 ) ) )
return - V_68 ;
if ( ( V_9 = F_37 ( V_16 . V_69 ) ) == NULL )
return - V_19 ;
switch ( V_16 . type ) {
case V_71 :
V_66 = F_28 ( & V_16 . V_2 ,
& V_16 . V_24 , V_9 ) ;
break;
case V_72 :
V_66 = F_30 ( & V_16 . V_2 ,
V_9 , V_16 . V_14 ) ;
break;
default:
V_66 = - V_19 ;
}
F_12 ( V_9 ) ;
return V_66 ;
case V_74 :
return F_31 () ;
default:
return - V_19 ;
}
return 0 ;
}
void F_47 ( T_5 * V_13 , int V_75 )
{
struct V_7 * V_41 , * V_7 = NULL ;
struct V_4 * V_5 ;
struct V_1 * V_1 = NULL ;
F_2 ( & V_10 ) ;
F_8 (s, node, &nr_neigh_list) {
if ( V_41 -> V_13 == V_13 ) {
F_9 ( V_41 ) ;
V_7 = V_41 ;
break;
}
}
F_6 ( & V_10 ) ;
if ( V_7 == NULL )
return;
V_7 -> V_13 = NULL ;
F_48 ( V_13 ) ;
if ( ++ V_7 -> V_20 < V_76 ) {
F_15 ( V_7 ) ;
return;
}
F_2 ( & V_6 ) ;
F_3 (nr_node, node, &nr_node_list) {
F_13 ( V_1 ) ;
if ( V_1 -> V_25 < V_1 -> V_22 &&
V_1 -> V_23 [ V_1 -> V_25 ] . V_24 == V_7 )
V_1 -> V_25 ++ ;
F_14 ( V_1 ) ;
}
F_6 ( & V_6 ) ;
F_15 ( V_7 ) ;
}
int F_49 ( struct V_77 * V_78 , T_5 * V_13 )
{
T_1 * V_79 , * V_80 ;
struct V_7 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_9 ;
unsigned char * V_81 ;
T_5 * V_82 ;
int V_66 ;
struct V_77 * V_83 ;
V_79 = ( T_1 * ) ( V_78 -> V_84 + 0 ) ;
V_80 = ( T_1 * ) ( V_78 -> V_84 + 7 ) ;
if ( V_13 != NULL ) {
V_66 = F_10 ( V_79 , L_1 , & V_13 -> V_85 , V_13 -> V_28 ,
V_13 -> V_86 -> V_9 , 0 ,
V_87 ) ;
if ( V_66 )
return V_66 ;
}
if ( ( V_9 = F_11 ( V_80 ) ) != NULL ) {
if ( V_13 == NULL )
V_66 = F_50 ( V_78 ) ;
else
V_66 = F_51 ( V_78 , V_9 ) ;
F_12 ( V_9 ) ;
return V_66 ;
}
if ( ! V_88 && V_13 != NULL )
return 0 ;
if ( V_78 -> V_84 [ 14 ] == 1 ) {
return 0 ;
}
V_1 = F_1 ( V_80 ) ;
if ( V_1 == NULL )
return 0 ;
F_13 ( V_1 ) ;
if ( V_1 -> V_25 >= V_1 -> V_22 ) {
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
V_7 = V_1 -> V_23 [ V_1 -> V_25 ] . V_24 ;
if ( ( V_9 = F_39 () ) == NULL ) {
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return 0 ;
}
if ( ( V_83 = F_52 ( V_78 , V_9 -> V_89 , 0 , V_26 ) ) == NULL ) {
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
F_12 ( V_9 ) ;
return 0 ;
}
F_53 ( V_78 ) ;
V_78 = V_83 ;
V_78 -> V_84 [ 14 ] -- ;
V_81 = F_54 ( V_78 , 1 ) ;
* V_81 = V_90 ;
V_82 = V_7 -> V_13 ;
V_7 -> V_13 = F_55 ( V_78 , 256 ,
( T_1 * ) V_9 -> V_55 ,
& V_7 -> V_2 ,
V_7 -> V_28 , V_7 -> V_9 ) ;
if ( V_82 )
F_48 ( V_82 ) ;
F_12 ( V_9 ) ;
V_66 = ( V_7 -> V_13 != NULL ) ;
F_14 ( V_1 ) ;
F_16 ( V_1 ) ;
return V_66 ;
}
static void * F_56 ( struct V_91 * V_92 , T_6 * V_93 )
{
F_2 ( & V_6 ) ;
return F_57 ( & V_40 , * V_93 ) ;
}
static void * F_58 ( struct V_91 * V_92 , void * V_94 , T_6 * V_93 )
{
return F_59 ( V_94 , & V_40 , V_93 ) ;
}
static void F_60 ( struct V_91 * V_92 , void * V_94 )
{
F_6 ( & V_6 ) ;
}
static int F_61 ( struct V_91 * V_92 , void * V_94 )
{
char V_95 [ 11 ] ;
int V_17 ;
if ( V_94 == V_96 )
F_62 ( V_92 ,
L_2 ) ;
else {
struct V_1 * V_1 = F_63 ( V_94 , struct V_1 ,
V_39 ) ;
F_13 ( V_1 ) ;
F_64 ( V_92 , L_3 ,
F_65 ( V_95 , & V_1 -> V_2 ) ,
( V_1 -> V_12 [ 0 ] == '\0' ) ? L_4 : V_1 -> V_12 ,
V_1 -> V_25 + 1 ,
V_1 -> V_22 ) ;
for ( V_17 = 0 ; V_17 < V_1 -> V_22 ; V_17 ++ ) {
F_64 ( V_92 , L_5 ,
V_1 -> V_23 [ V_17 ] . V_14 ,
V_1 -> V_23 [ V_17 ] . V_15 ,
V_1 -> V_23 [ V_17 ] . V_24 -> V_31 ) ;
}
F_14 ( V_1 ) ;
F_62 ( V_92 , L_6 ) ;
}
return 0 ;
}
static int F_66 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_67 ( V_98 , & V_99 ) ;
}
static void * F_68 ( struct V_91 * V_92 , T_6 * V_93 )
{
F_2 ( & V_10 ) ;
return F_57 ( & V_37 , * V_93 ) ;
}
static void * F_69 ( struct V_91 * V_92 , void * V_94 , T_6 * V_93 )
{
return F_59 ( V_94 , & V_37 , V_93 ) ;
}
static void F_70 ( struct V_91 * V_92 , void * V_94 )
{
F_6 ( & V_10 ) ;
}
static int F_71 ( struct V_91 * V_92 , void * V_94 )
{
char V_95 [ 11 ] ;
int V_17 ;
if ( V_94 == V_96 )
F_62 ( V_92 , L_7 ) ;
else {
struct V_7 * V_7 ;
V_7 = F_63 ( V_94 , struct V_7 , V_36 ) ;
F_64 ( V_92 , L_8 ,
V_7 -> V_31 ,
F_65 ( V_95 , & V_7 -> V_2 ) ,
V_7 -> V_9 ? V_7 -> V_9 -> V_53 : L_9 ,
V_7 -> V_14 ,
V_7 -> V_30 ,
V_7 -> V_22 ,
V_7 -> V_20 ) ;
if ( V_7 -> V_28 != NULL ) {
for ( V_17 = 0 ; V_17 < V_7 -> V_28 -> V_34 ; V_17 ++ )
F_64 ( V_92 , L_10 ,
F_65 ( V_95 , & V_7 -> V_28 -> V_60 [ V_17 ] ) ) ;
}
F_62 ( V_92 , L_6 ) ;
}
return 0 ;
}
static int F_72 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_67 ( V_98 , & V_100 ) ;
}
void T_7 F_73 ( void )
{
struct V_7 * V_41 = NULL ;
struct V_1 * V_45 = NULL ;
struct V_4 * V_5 , * V_42 ;
F_2 ( & V_10 ) ;
F_2 ( & V_6 ) ;
F_32 (t, node, nodet, &nr_node_list) {
F_13 ( V_45 ) ;
F_33 ( V_45 ) ;
F_14 ( V_45 ) ;
}
F_35 (s, node, nodet, &nr_neigh_list) {
while( V_41 -> V_22 ) {
V_41 -> V_22 -- ;
F_15 ( V_41 ) ;
}
F_36 ( V_41 ) ;
}
F_6 ( & V_6 ) ;
F_6 ( & V_10 ) ;
}
