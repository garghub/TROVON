static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_7 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
V_13 = & V_10 -> V_15 [ V_4 -> V_16 . V_17 . V_18 ] ;
switch ( V_6 ) {
case V_19 :
V_14 = F_2 ( V_8 , V_4 -> type ,
V_4 -> V_16 . V_17 . V_20 , V_4 -> V_16 . V_17 . V_21 ,
V_4 -> V_16 . V_17 . V_22 ,
V_4 -> V_16 . V_17 . V_23 ,
V_4 -> V_16 . V_17 . V_24 , V_13 -> V_25 ,
V_4 -> V_16 . V_17 . V_26 , V_4 -> V_16 . V_17 . V_27 ,
V_4 -> V_16 . V_17 . V_28 , V_4 -> V_16 . V_17 . V_29 ) ;
break;
default:
V_14 = - V_30 ;
break;
}
return V_14 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_31 ,
enum V_32 type , bool V_33 )
{
struct V_7 * V_8 = V_2 -> V_7 ;
T_1 V_34 , V_35 , V_36 ;
unsigned int V_37 = V_8 -> V_37 ;
unsigned int V_38 = 0 ;
int V_14 = 0 ;
switch ( type ) {
case V_39 : {
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_31 ;
V_34 = ( F_4 ( V_42 ) |
F_5 (
V_43 ) ) ;
V_35 = V_33 ? V_41 -> V_44 . V_18 : V_45 ;
V_36 = ( V_34 | F_6 ( V_41 -> V_46 ) ) ;
V_37 = V_8 -> V_37 ;
V_38 = 0 ;
break;
}
default:
V_14 = - V_30 ;
goto V_47;
}
V_14 = F_7 ( V_8 , V_8 -> V_48 , V_37 , V_38 , 1 , & V_36 , & V_35 ) ;
V_47:
return V_14 ;
}
static struct V_12 * F_8 ( struct V_1 * V_2 ,
const unsigned int V_49 ,
int * V_50 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 , * V_51 ;
struct V_12 * V_52 = NULL ;
int V_53 ;
V_51 = & V_10 -> V_15 [ V_10 -> V_54 ] ;
for ( V_13 = & V_10 -> V_15 [ 0 ] ; V_13 != V_51 ; ++ V_13 ) {
struct V_40 * V_41 ;
V_53 = 0 ;
if ( V_13 -> V_55 == V_56 )
continue;
F_9 (qe, &e->queue_list, list) {
if ( V_41 -> V_46 == V_49 ) {
V_52 = V_13 ;
if ( V_50 )
* V_50 = V_53 ;
break;
}
V_53 ++ ;
}
if ( V_52 )
break;
}
return V_52 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_57 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_7 ;
struct V_12 * V_13 ;
struct V_40 * V_41 = NULL ;
struct V_58 * V_59 ;
unsigned int V_49 ;
int V_50 = - 1 ;
int V_14 = 0 ;
if ( V_4 -> V_60 < 0 || V_4 -> V_60 >= V_2 -> V_61 )
return - V_62 ;
V_59 = & V_8 -> V_63 . V_64 [ V_2 -> V_65 + V_4 -> V_60 ] ;
V_49 = V_59 -> V_66 . V_46 ;
V_13 = F_8 ( V_2 , V_49 , & V_50 ) ;
if ( V_13 && V_50 >= 0 ) {
int V_53 = 0 ;
F_11 ( & V_13 -> V_67 ) ;
F_9 (qe, &e->queue_list, list) {
if ( V_53 == V_50 )
break;
V_53 ++ ;
}
V_14 = F_3 ( V_2 , ( void * ) V_41 , V_39 ,
false ) ;
if ( V_14 ) {
F_12 ( & V_13 -> V_67 ) ;
goto V_47;
}
F_13 ( & V_41 -> V_68 ) ;
F_14 ( V_41 ) ;
if ( F_15 ( & V_13 -> V_69 ) ) {
V_13 -> V_55 = V_56 ;
memset ( & V_13 -> V_70 , 0 , sizeof( V_13 -> V_70 ) ) ;
}
F_12 ( & V_13 -> V_67 ) ;
}
V_47:
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_57 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_7 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 ;
struct V_40 * V_41 = NULL ;
struct V_58 * V_59 ;
unsigned int V_49 ;
int V_14 = 0 ;
if ( V_4 -> V_60 < 0 || V_4 -> V_60 >= V_2 -> V_61 )
return - V_62 ;
V_41 = F_17 ( sizeof( struct V_40 ) ) ;
if ( ! V_41 )
return - V_71 ;
V_59 = & V_8 -> V_63 . V_64 [ V_2 -> V_65 + V_4 -> V_60 ] ;
V_49 = V_59 -> V_66 . V_46 ;
V_14 = F_10 ( V_2 , V_4 ) ;
if ( V_14 ) {
F_14 ( V_41 ) ;
goto V_47;
}
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_46 = V_49 ;
memcpy ( & V_41 -> V_44 , V_4 , sizeof( V_41 -> V_44 ) ) ;
V_13 = & V_10 -> V_15 [ V_41 -> V_44 . V_18 ] ;
F_11 ( & V_13 -> V_67 ) ;
V_14 = F_3 ( V_2 , ( void * ) V_41 , V_39 , true ) ;
if ( V_14 ) {
F_14 ( V_41 ) ;
F_12 ( & V_13 -> V_67 ) ;
goto V_47;
}
F_18 ( & V_41 -> V_68 , & V_13 -> V_72 ) ;
F_19 ( & V_13 -> V_69 ) ;
F_12 ( & V_13 -> V_67 ) ;
V_47:
return V_14 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
enum V_32 type )
{
if ( ! V_13 )
return;
switch ( type ) {
case V_39 : {
struct V_40 * V_41 ;
F_9 (qe, &e->queue_list, list)
F_10 ( V_2 , & V_41 -> V_44 ) ;
break;
}
default:
break;
}
}
static int F_21 ( struct V_1 * V_2 , void * V_31 ,
enum V_32 type , bool V_33 )
{
int V_14 = 0 ;
if ( ! V_31 )
return - V_73 ;
switch ( type ) {
case V_39 : {
struct V_57 * V_41 = (struct V_57 * ) V_31 ;
if ( V_33 )
V_14 = F_16 ( V_2 , V_41 ) ;
else
V_14 = F_10 ( V_2 , V_41 ) ;
break;
}
default:
V_14 = - V_30 ;
break;
}
return V_14 ;
}
int F_22 ( struct V_74 * V_75 , void * V_31 ,
enum V_32 type )
{
struct V_1 * V_2 = F_23 ( V_75 ) ;
struct V_9 * V_10 ;
int V_14 = 0 ;
T_2 V_76 ;
if ( ! F_24 ( V_75 ) )
return - V_30 ;
if ( ! V_31 )
return - V_73 ;
switch ( type ) {
case V_39 : {
struct V_57 * V_41 = (struct V_57 * ) V_31 ;
V_76 = V_41 -> V_18 ;
break;
}
default:
return - V_30 ;
}
if ( ! F_25 ( V_75 , V_76 ) )
return - V_73 ;
if ( V_76 == V_77 )
return - V_30 ;
V_10 = V_2 -> V_11 ;
F_26 ( & V_10 -> V_78 ) ;
V_14 = F_21 ( V_2 , V_31 , type , true ) ;
F_27 ( & V_10 -> V_78 ) ;
return V_14 ;
}
int F_28 ( struct V_74 * V_75 , void * V_31 ,
enum V_32 type )
{
struct V_1 * V_2 = F_23 ( V_75 ) ;
struct V_9 * V_10 ;
int V_14 = 0 ;
T_2 V_76 ;
if ( ! F_24 ( V_75 ) )
return - V_30 ;
if ( ! V_31 )
return - V_73 ;
switch ( type ) {
case V_39 : {
struct V_57 * V_41 = (struct V_57 * ) V_31 ;
V_76 = V_41 -> V_18 ;
break;
}
default:
return - V_30 ;
}
if ( ! F_25 ( V_75 , V_76 ) )
return - V_73 ;
V_10 = V_2 -> V_11 ;
F_26 ( & V_10 -> V_78 ) ;
V_14 = F_21 ( V_2 , V_31 , type , false ) ;
F_27 ( & V_10 -> V_78 ) ;
return V_14 ;
}
static struct V_12 * F_29 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 , * V_51 ;
struct V_12 * V_52 = NULL ;
if ( ! V_4 ) {
V_51 = & V_10 -> V_15 [ V_10 -> V_54 ] ;
for ( V_13 = & V_10 -> V_15 [ 0 ] ; V_13 != V_51 ; ++ V_13 ) {
if ( V_13 -> V_55 == V_56 ) {
V_52 = V_13 ;
break;
}
}
} else {
struct V_3 V_70 ;
struct V_3 V_79 ;
memcpy ( & V_79 , V_4 , sizeof( V_79 ) ) ;
V_79 . V_16 . V_17 . V_18 = V_77 ;
V_51 = & V_10 -> V_15 [ V_10 -> V_54 ] ;
for ( V_13 = & V_10 -> V_15 [ 0 ] ; V_13 != V_51 ; ++ V_13 ) {
if ( V_13 -> V_55 == V_56 )
continue;
memcpy ( & V_70 , & V_13 -> V_70 , sizeof( V_70 ) ) ;
V_70 . V_16 . V_17 . V_18 = V_77 ;
if ( ( V_70 . type == V_79 . type ) &&
( ! memcmp ( & V_70 . V_16 . V_17 , & V_79 . V_16 . V_17 ,
sizeof( V_70 . V_16 . V_17 ) ) ) ) {
V_52 = V_13 ;
break;
}
}
}
return V_52 ;
}
static struct V_12 * F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 ;
T_2 V_76 ;
int V_14 ;
if ( ! V_4 )
return NULL ;
V_76 = V_4 -> V_16 . V_17 . V_18 ;
if ( V_76 != V_77 )
return NULL ;
F_26 ( & V_10 -> V_78 ) ;
V_13 = F_29 ( V_2 , V_4 ) ;
if ( ! V_13 ) {
struct V_3 V_80 ;
V_13 = F_29 ( V_2 , NULL ) ;
if ( ! V_13 )
goto V_47;
memcpy ( & V_80 , V_4 , sizeof( V_80 ) ) ;
V_80 . V_16 . V_17 . V_18 = V_13 -> V_25 ;
F_11 ( & V_13 -> V_67 ) ;
V_14 = F_1 ( V_2 , & V_80 , V_19 ) ;
if ( V_14 ) {
F_12 ( & V_13 -> V_67 ) ;
V_13 = NULL ;
goto V_47;
}
memcpy ( & V_13 -> V_70 , & V_80 , sizeof( V_13 -> V_70 ) ) ;
F_31 ( & V_13 -> V_69 , 0 ) ;
V_13 -> V_55 = V_81 ;
F_12 ( & V_13 -> V_67 ) ;
}
V_47:
F_27 ( & V_10 -> V_78 ) ;
return V_13 ;
}
struct V_12 * F_32 ( struct V_74 * V_75 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_23 ( V_75 ) ;
T_2 V_76 ;
if ( ! F_24 ( V_75 ) )
return NULL ;
V_76 = V_4 -> V_16 . V_17 . V_18 ;
if ( ! F_25 ( V_75 , V_76 ) )
return NULL ;
return F_30 ( V_2 , V_4 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_20 ( V_2 , V_13 , V_39 ) ;
}
struct V_9 * F_34 ( unsigned int V_54 )
{
struct V_9 * V_10 ;
unsigned int V_53 ;
V_10 = F_17 ( sizeof( * V_10 ) + V_54 * sizeof( struct V_12 ) ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_54 = V_54 ;
F_35 ( & V_10 -> V_78 ) ;
for ( V_53 = 0 ; V_53 < V_10 -> V_54 ; V_53 ++ ) {
memset ( & V_10 -> V_15 [ V_53 ] , 0 , sizeof( struct V_12 ) ) ;
V_10 -> V_15 [ V_53 ] . V_25 = V_53 ;
V_10 -> V_15 [ V_53 ] . V_55 = V_56 ;
F_36 ( & V_10 -> V_15 [ V_53 ] . V_72 ) ;
F_37 ( & V_10 -> V_15 [ V_53 ] . V_67 ) ;
F_31 ( & V_10 -> V_15 [ V_53 ] . V_69 , 0 ) ;
}
return V_10 ;
}
void F_38 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned int V_53 ;
F_39 (adap, i) {
struct V_1 * V_2 = F_23 ( V_8 -> V_82 [ V_53 ] ) ;
V_10 = V_2 -> V_11 ;
for ( V_53 = 0 ; V_53 < V_10 -> V_54 ; V_53 ++ ) {
struct V_12 * V_13 ;
F_26 ( & V_10 -> V_78 ) ;
V_13 = & V_10 -> V_15 [ V_53 ] ;
if ( V_13 -> V_55 == V_81 )
F_33 ( V_2 , V_13 ) ;
F_27 ( & V_10 -> V_78 ) ;
}
F_14 ( V_10 ) ;
}
}
