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
static void F_17 ( struct V_20 * V_21 )
{
F_15 ( F_18 ( V_21 , struct V_1 , V_20 ) ) ;
}
struct V_1 * F_19 ( struct V_22 * V_22 ,
struct V_1 * V_6 ,
struct V_9 * V_10 ,
enum V_23 V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 ;
unsigned long V_30 ;
V_28 = (struct V_27 * ) F_7 ( V_10 ) ;
V_26 = (struct V_25 * ) V_10 -> V_31 ;
if ( V_6 && ! F_3 ( V_6 -> V_7 , V_26 -> V_7 ) ) {
F_20 ( & V_6 -> V_19 ) ;
F_21 ( & V_6 -> V_20 , F_17 ) ;
V_6 = NULL ;
}
if ( V_6 && ( V_24 == V_6 -> V_32 ) &&
! F_3 ( V_6 -> V_8 , V_28 -> V_11 . V_12 ) ) {
F_20 ( & V_6 -> V_19 ) ;
F_21 ( & V_6 -> V_20 , F_17 ) ;
V_6 = NULL ;
}
if ( V_6 && ( V_24 != V_6 -> V_32 ) &&
( V_6 -> V_32 != V_33 ) &&
! F_3 ( V_6 -> V_7 , V_28 -> V_11 . V_12 ) ) {
F_20 ( & V_6 -> V_19 ) ;
F_21 ( & V_6 -> V_20 , F_17 ) ;
V_6 = NULL ;
}
if ( V_6 )
return V_6 ;
V_6 = F_1 ( & V_22 -> V_3 , V_26 -> V_7 ) ;
if ( V_6 ) {
memcpy ( V_6 -> V_8 , V_28 -> V_11 . V_12 , V_5 ) ;
V_6 -> V_32 = V_24 ;
return V_6 ;
}
V_6 = F_22 ( sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 )
return NULL ;
memcpy ( V_6 -> V_7 , V_26 -> V_7 , V_5 ) ;
memcpy ( V_6 -> V_8 , V_28 -> V_11 . V_12 , V_5 ) ;
if ( ! F_3 ( V_26 -> V_7 , V_28 -> V_11 . V_12 ) )
V_6 -> V_32 = V_24 ;
else
V_6 -> V_32 = V_33 ;
V_30 = V_35 ;
for ( V_29 = 0 ; V_29 < V_36 ; V_29 ++ )
V_6 -> V_37 [ V_29 ] = V_30 ;
for ( V_29 = 0 ; V_29 < V_38 ; V_29 ++ )
V_6 -> V_39 [ V_29 ] = F_23 ( V_28 -> V_40 . V_41 ) - 1 ;
F_16 ( & V_6 -> V_19 , & V_22 -> V_3 ) ;
return V_6 ;
}
void F_24 ( struct V_22 * V_22 , struct V_9 * V_10 )
{
struct V_11 * V_11 ;
struct V_1 * V_6 ;
if ( ! F_6 ( V_10 ) ) {
F_25 ( 1 , L_1 , V_42 ) ;
return;
}
V_11 = (struct V_11 * ) F_7 ( V_10 ) ;
F_10 () ;
V_6 = F_4 ( & V_22 -> V_3 , V_11 -> V_12 ) ;
if ( V_6 )
memcpy ( V_11 -> V_12 , V_6 -> V_7 , V_5 ) ;
F_13 () ;
}
void F_26 ( struct V_22 * V_22 , struct V_11 * V_11 ,
enum V_23 V_24 )
{
struct V_1 * V_6 ;
F_10 () ;
V_6 = F_1 ( & V_22 -> V_3 , V_11 -> V_43 ) ;
if ( V_6 && ( V_6 -> V_32 == V_24 ) )
memcpy ( V_11 -> V_43 , V_6 -> V_8 , V_5 ) ;
F_13 () ;
}
static bool F_27 ( T_1 V_44 , T_1 V_45 )
{
if ( ( int ) V_45 - V_44 == 32768 )
return false ;
return ( ( ( V_46 ) ( V_45 - V_44 ) ) < 0 ) ;
}
void F_28 ( struct V_1 * V_6 , enum V_23 V_24 )
{
if ( ( V_24 < 0 ) || ( V_24 >= V_38 ) ) {
F_25 ( 1 , L_2 , V_42 , V_24 ) ;
return;
}
V_6 -> V_37 [ V_24 ] = V_35 ;
V_6 -> V_47 [ V_24 ] = false ;
}
int F_29 ( struct V_1 * V_6 , enum V_23 V_24 ,
struct V_9 * V_10 )
{
struct V_48 * V_48 ;
T_1 V_41 ;
if ( ( V_24 < 0 ) || ( V_24 >= V_38 ) ) {
F_25 ( 1 , L_2 , V_42 , V_24 ) ;
return - V_49 ;
}
if ( ! F_6 ( V_10 ) ) {
F_25 ( 1 , L_1 , V_42 ) ;
return - V_49 ;
}
V_48 = (struct V_48 * ) F_7 ( V_10 ) ;
V_41 = F_23 ( V_48 -> V_50 . V_41 ) ;
if ( F_30 ( V_41 , V_6 -> V_39 [ V_24 ] ) )
return 1 ;
V_6 -> V_39 [ V_24 ] = V_41 ;
return 0 ;
}
static bool F_31 ( struct V_1 * V_6 , enum V_23 V_24 )
{
enum V_23 V_51 ;
if ( V_6 -> V_47 [ V_24 ] )
return true ;
if ( V_24 == V_52 )
V_51 = V_53 ;
else
V_51 = V_52 ;
if ( V_6 -> V_47 [ V_51 ] )
return false ;
if ( F_32 ( V_6 -> V_37 [ V_51 ] , V_6 -> V_37 [ V_24 ] +
F_33 ( V_54 ) ) )
return true ;
return false ;
}
void F_34 ( struct V_22 * V_22 )
{
struct V_1 * V_6 ;
unsigned long V_55 ;
unsigned long V_56 , V_57 ;
F_10 () ;
F_2 (node, &hsr_priv->node_db, mac_list) {
V_56 = V_6 -> V_37 [ V_52 ] ;
V_57 = V_6 -> V_37 [ V_53 ] ;
if ( F_32 ( V_35 , V_56 + V_58 / 2 ) )
V_6 -> V_47 [ V_52 ] = true ;
if ( F_32 ( V_35 , V_57 + V_58 / 2 ) )
V_6 -> V_47 [ V_53 ] = true ;
V_55 = V_56 ;
if ( V_6 -> V_47 [ V_52 ] ||
( ! V_6 -> V_47 [ V_53 ] &&
F_32 ( V_57 , V_56 ) ) )
V_55 = V_57 ;
if ( F_35 ( V_55 +
F_33 ( 1.5 * V_54 ) ) ) {
if ( F_31 ( V_6 , V_52 ) )
F_36 ( V_22 , V_6 -> V_7 ,
V_52 ) ;
else if ( F_31 ( V_6 , V_53 ) )
F_36 ( V_22 , V_6 -> V_7 ,
V_53 ) ;
}
if ( F_37 ( V_55 +
F_33 ( V_59 ) ) ) {
F_38 ( V_22 , V_6 -> V_7 ) ;
F_20 ( & V_6 -> V_19 ) ;
F_21 ( & V_6 -> V_20 , F_17 ) ;
}
}
F_13 () ;
}
void * F_39 ( struct V_22 * V_22 , void * V_60 ,
unsigned char V_4 [ V_5 ] )
{
struct V_1 * V_6 ;
if ( ! V_60 ) {
V_6 = F_11 ( & V_22 -> V_3 ,
struct V_1 , V_19 ) ;
if ( V_6 )
memcpy ( V_4 , V_6 -> V_7 , V_5 ) ;
return V_6 ;
}
V_6 = V_60 ;
F_40 (node, &hsr_priv->node_db, mac_list) {
memcpy ( V_4 , V_6 -> V_7 , V_5 ) ;
return V_6 ;
}
return NULL ;
}
int F_41 ( struct V_22 * V_22 ,
const unsigned char * V_4 ,
unsigned char V_15 [ V_5 ] ,
unsigned int * V_61 ,
int * V_62 ,
T_1 * V_63 ,
int * V_64 ,
T_1 * V_65 )
{
struct V_1 * V_6 ;
unsigned long V_66 ;
F_10 () ;
V_6 = F_1 ( & V_22 -> V_3 , V_4 ) ;
if ( ! V_6 ) {
F_13 () ;
return - V_67 ;
}
memcpy ( V_15 , V_6 -> V_8 , V_5 ) ;
V_66 = V_35 - V_6 -> V_37 [ V_52 ] ;
if ( V_6 -> V_47 [ V_52 ] )
* V_62 = V_68 ;
#if V_69 <= V_70
else if ( V_66 > F_33 ( V_68 ) )
* V_62 = V_68 ;
#endif
else
* V_62 = F_42 ( V_66 ) ;
V_66 = V_35 - V_6 -> V_37 [ V_53 ] ;
if ( V_6 -> V_47 [ V_53 ] )
* V_64 = V_68 ;
#if V_69 <= V_70
else if ( V_66 > F_33 ( V_68 ) )
* V_64 = V_68 ;
#endif
else
* V_64 = F_42 ( V_66 ) ;
* V_63 = V_6 -> V_39 [ V_53 ] ;
* V_65 = V_6 -> V_39 [ V_52 ] ;
if ( ( V_6 -> V_32 != V_33 ) && V_22 -> V_71 [ V_6 -> V_32 ] )
* V_61 = V_22 -> V_71 [ V_6 -> V_32 ] -> V_72 ;
else
* V_61 = - 1 ;
F_13 () ;
return 0 ;
}
