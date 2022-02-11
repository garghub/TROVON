static struct V_1 * F_1 ( struct V_2 * V_3 ,
const unsigned char V_4 [ V_5 ] )
{
struct V_1 * V_6 ;
F_2 (node, node_db, mac_list) {
if ( F_3 ( V_6 -> V_7 , V_4 ) )
return V_6 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 ,
const unsigned char V_4 [ V_5 ] )
{
struct V_1 * V_6 ;
F_2 (node, node_db, mac_list) {
if ( F_3 ( V_6 -> V_8 , V_4 ) )
return V_6 ;
}
return NULL ;
}
struct V_1 * F_5 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
struct V_1 * V_6 ;
struct V_11 * V_11 ;
if ( ! F_6 ( V_10 ) )
return NULL ;
V_11 = (struct V_11 * ) F_7 ( V_10 ) ;
F_2 (node, node_db, mac_list) {
if ( F_3 ( V_6 -> V_7 , V_11 -> V_12 ) )
return V_6 ;
if ( F_3 ( V_6 -> V_8 , V_11 -> V_12 ) )
return V_6 ;
}
return NULL ;
}
int F_8 ( struct V_2 * V_13 ,
unsigned char V_14 [ V_5 ] ,
unsigned char V_15 [ V_5 ] )
{
struct V_1 * V_6 , * V_16 ;
V_6 = F_9 ( sizeof( * V_6 ) , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
memcpy ( V_6 -> V_7 , V_14 , V_5 ) ;
memcpy ( V_6 -> V_8 , V_15 , V_5 ) ;
F_10 () ;
V_16 = F_11 ( V_13 ,
struct V_1 , V_19 ) ;
if ( V_16 ) {
F_12 ( & V_16 -> V_19 , & V_6 -> V_19 ) ;
F_13 () ;
F_14 () ;
F_15 ( V_16 ) ;
} else {
F_13 () ;
F_16 ( & V_6 -> V_19 , V_13 ) ;
}
return 0 ;
}
struct V_1 * F_17 ( struct V_20 * V_20 ,
struct V_1 * V_6 ,
struct V_9 * V_10 ,
enum V_21 V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_27 ;
unsigned long V_28 ;
V_26 = (struct V_25 * ) F_7 ( V_10 ) ;
V_24 = (struct V_23 * ) V_10 -> V_29 ;
if ( V_6 && ! F_3 ( V_6 -> V_7 , V_24 -> V_7 ) ) {
F_18 ( & V_6 -> V_19 ) ;
F_19 ( V_6 , V_30 ) ;
V_6 = NULL ;
}
if ( V_6 && ( V_22 == V_6 -> V_31 ) &&
! F_3 ( V_6 -> V_8 , V_26 -> V_11 . V_12 ) ) {
F_18 ( & V_6 -> V_19 ) ;
F_19 ( V_6 , V_30 ) ;
V_6 = NULL ;
}
if ( V_6 && ( V_22 != V_6 -> V_31 ) &&
( V_6 -> V_31 != V_32 ) &&
! F_3 ( V_6 -> V_7 , V_26 -> V_11 . V_12 ) ) {
F_18 ( & V_6 -> V_19 ) ;
F_19 ( V_6 , V_30 ) ;
V_6 = NULL ;
}
if ( V_6 )
return V_6 ;
V_6 = F_1 ( & V_20 -> V_3 , V_24 -> V_7 ) ;
if ( V_6 ) {
memcpy ( V_6 -> V_8 , V_26 -> V_11 . V_12 , V_5 ) ;
V_6 -> V_31 = V_22 ;
return V_6 ;
}
V_6 = F_20 ( sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 )
return NULL ;
memcpy ( V_6 -> V_7 , V_24 -> V_7 , V_5 ) ;
memcpy ( V_6 -> V_8 , V_26 -> V_11 . V_12 , V_5 ) ;
if ( ! F_3 ( V_24 -> V_7 , V_26 -> V_11 . V_12 ) )
V_6 -> V_31 = V_22 ;
else
V_6 -> V_31 = V_32 ;
V_28 = V_34 ;
for ( V_27 = 0 ; V_27 < V_35 ; V_27 ++ )
V_6 -> V_36 [ V_27 ] = V_28 ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ )
V_6 -> V_38 [ V_27 ] = F_21 ( V_26 -> V_39 . V_40 ) - 1 ;
F_16 ( & V_6 -> V_19 , & V_20 -> V_3 ) ;
return V_6 ;
}
void F_22 ( struct V_20 * V_20 , struct V_9 * V_10 )
{
struct V_11 * V_11 ;
struct V_1 * V_6 ;
if ( ! F_6 ( V_10 ) ) {
F_23 ( 1 , L_1 , V_41 ) ;
return;
}
V_11 = (struct V_11 * ) F_7 ( V_10 ) ;
F_10 () ;
V_6 = F_4 ( & V_20 -> V_3 , V_11 -> V_12 ) ;
if ( V_6 )
memcpy ( V_11 -> V_12 , V_6 -> V_7 , V_5 ) ;
F_13 () ;
}
void F_24 ( struct V_20 * V_20 , struct V_11 * V_11 ,
enum V_21 V_22 )
{
struct V_1 * V_6 ;
F_10 () ;
V_6 = F_1 ( & V_20 -> V_3 , V_11 -> V_42 ) ;
if ( V_6 && ( V_6 -> V_31 == V_22 ) )
memcpy ( V_11 -> V_42 , V_6 -> V_8 , V_5 ) ;
F_13 () ;
}
static bool F_25 ( T_1 V_43 , T_1 V_44 )
{
if ( ( int ) V_44 - V_43 == 32768 )
return false ;
return ( ( ( V_45 ) ( V_44 - V_43 ) ) < 0 ) ;
}
void F_26 ( struct V_1 * V_6 , enum V_21 V_22 )
{
if ( ( V_22 < 0 ) || ( V_22 >= V_35 ) ) {
F_23 ( 1 , L_2 , V_41 , V_22 ) ;
return;
}
V_6 -> V_36 [ V_22 ] = V_34 ;
V_6 -> V_46 [ V_22 ] = false ;
}
int F_27 ( struct V_1 * V_6 , enum V_21 V_22 ,
struct V_9 * V_10 )
{
struct V_47 * V_47 ;
T_1 V_40 ;
if ( ( V_22 < 0 ) || ( V_22 >= V_37 ) ) {
F_23 ( 1 , L_2 , V_41 , V_22 ) ;
return - V_48 ;
}
if ( ! F_6 ( V_10 ) ) {
F_23 ( 1 , L_1 , V_41 ) ;
return - V_48 ;
}
V_47 = (struct V_47 * ) F_7 ( V_10 ) ;
V_40 = F_21 ( V_47 -> V_49 . V_40 ) ;
if ( F_28 ( V_40 , V_6 -> V_38 [ V_22 ] ) )
return 1 ;
V_6 -> V_38 [ V_22 ] = V_40 ;
return 0 ;
}
static bool F_29 ( struct V_1 * V_6 , enum V_21 V_22 )
{
enum V_21 V_50 ;
if ( V_6 -> V_46 [ V_22 ] )
return true ;
if ( V_22 == V_51 )
V_50 = V_52 ;
else
V_50 = V_51 ;
if ( V_6 -> V_46 [ V_50 ] )
return false ;
if ( F_30 ( V_6 -> V_36 [ V_50 ] , V_6 -> V_36 [ V_22 ] +
F_31 ( V_53 ) ) )
return true ;
return false ;
}
void F_32 ( struct V_20 * V_20 )
{
struct V_1 * V_6 ;
unsigned long V_54 ;
unsigned long V_55 , V_56 ;
F_10 () ;
F_2 (node, &hsr_priv->node_db, mac_list) {
V_55 = V_6 -> V_36 [ V_51 ] ;
V_56 = V_6 -> V_36 [ V_52 ] ;
if ( F_30 ( V_34 , V_55 + V_57 / 2 ) )
V_6 -> V_46 [ V_51 ] = true ;
if ( F_30 ( V_34 , V_56 + V_57 / 2 ) )
V_6 -> V_46 [ V_52 ] = true ;
V_54 = V_55 ;
if ( V_6 -> V_46 [ V_51 ] ||
( ! V_6 -> V_46 [ V_52 ] &&
F_30 ( V_56 , V_55 ) ) )
V_54 = V_56 ;
if ( F_33 ( V_54 +
F_31 ( 1.5 * V_53 ) ) ) {
if ( F_29 ( V_6 , V_51 ) )
F_34 ( V_20 , V_6 -> V_7 ,
V_51 ) ;
else if ( F_29 ( V_6 , V_52 ) )
F_34 ( V_20 , V_6 -> V_7 ,
V_52 ) ;
}
if ( F_35 ( V_54 +
F_31 ( V_58 ) ) ) {
F_36 ( V_20 , V_6 -> V_7 ) ;
F_18 ( & V_6 -> V_19 ) ;
F_19 ( V_6 , V_30 ) ;
}
}
F_13 () ;
}
void * F_37 ( struct V_20 * V_20 , void * V_59 ,
unsigned char V_4 [ V_5 ] )
{
struct V_1 * V_6 ;
if ( ! V_59 ) {
V_6 = F_11 ( & V_20 -> V_3 ,
struct V_1 , V_19 ) ;
if ( V_6 )
memcpy ( V_4 , V_6 -> V_7 , V_5 ) ;
return V_6 ;
}
V_6 = V_59 ;
F_38 (node, &hsr_priv->node_db, mac_list) {
memcpy ( V_4 , V_6 -> V_7 , V_5 ) ;
return V_6 ;
}
return NULL ;
}
int F_39 ( struct V_20 * V_20 ,
const unsigned char * V_4 ,
unsigned char V_15 [ V_5 ] ,
unsigned int * V_60 ,
int * V_61 ,
T_1 * V_62 ,
int * V_63 ,
T_1 * V_64 )
{
struct V_1 * V_6 ;
unsigned long V_65 ;
F_10 () ;
V_6 = F_1 ( & V_20 -> V_3 , V_4 ) ;
if ( ! V_6 ) {
F_13 () ;
return - V_66 ;
}
memcpy ( V_15 , V_6 -> V_8 , V_5 ) ;
V_65 = V_34 - V_6 -> V_36 [ V_51 ] ;
if ( V_6 -> V_46 [ V_51 ] )
* V_61 = V_67 ;
#if V_68 <= V_69
else if ( V_65 > F_31 ( V_67 ) )
* V_61 = V_67 ;
#endif
else
* V_61 = F_40 ( V_65 ) ;
V_65 = V_34 - V_6 -> V_36 [ V_52 ] ;
if ( V_6 -> V_46 [ V_52 ] )
* V_63 = V_67 ;
#if V_68 <= V_69
else if ( V_65 > F_31 ( V_67 ) )
* V_63 = V_67 ;
#endif
else
* V_63 = F_40 ( V_65 ) ;
* V_62 = V_6 -> V_38 [ V_52 ] ;
* V_64 = V_6 -> V_38 [ V_51 ] ;
if ( ( V_6 -> V_31 != V_32 ) && V_20 -> V_70 [ V_6 -> V_31 ] )
* V_60 = V_20 -> V_70 [ V_6 -> V_31 ] -> V_71 ;
else
* V_60 = - 1 ;
F_13 () ;
return 0 ;
}
