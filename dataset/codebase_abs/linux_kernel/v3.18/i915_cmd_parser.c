static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = ( V_1 & V_3 ) >> V_4 ;
T_1 V_5 =
( V_1 & V_6 ) >> V_7 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_9 ) {
if ( V_5 == V_10 )
return 0xFFFF ;
else
return 0xFF ;
}
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
static T_1 F_3 ( T_1 V_1 )
{
T_1 V_2 = ( V_1 & V_3 ) >> V_4 ;
T_1 V_5 =
( V_1 & V_6 ) >> V_7 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_9 ) {
if ( V_5 == V_10 )
return 0xFFF ;
else
return 0xFF ;
}
F_2 ( L_2 , V_1 ) ;
return 0 ;
}
static T_1 F_4 ( T_1 V_1 )
{
T_1 V_2 = ( V_1 & V_3 ) >> V_4 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_11 )
return 0xFF ;
F_2 ( L_3 , V_1 ) ;
return 0 ;
}
static bool F_5 ( struct V_12 * V_13 ,
const struct V_14 * V_15 ,
int V_16 )
{
int V_17 ;
bool V_18 = true ;
if ( ! V_15 || V_16 == 0 )
return true ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
const struct V_14 * V_19 = & V_15 [ V_17 ] ;
T_1 V_20 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_22 ; V_21 ++ ) {
const struct V_23 * V_24 =
& V_19 -> V_19 [ V_17 ] ;
T_1 V_25 = V_24 -> V_26 . V_27 & V_24 -> V_26 . V_28 ;
if ( V_25 < V_20 ) {
F_6 ( L_4 ,
V_13 -> V_29 , V_17 , V_21 , V_25 , V_20 ) ;
V_18 = false ;
}
V_20 = V_25 ;
}
}
return V_18 ;
}
static bool F_7 ( int V_30 , const T_1 * V_31 , int V_32 )
{
int V_17 ;
T_1 V_20 = 0 ;
bool V_18 = true ;
for ( V_17 = 0 ; V_17 < V_32 ; V_17 ++ ) {
T_1 V_25 = V_31 [ V_17 ] ;
if ( V_25 < V_20 ) {
F_6 ( L_5 ,
V_30 , V_17 , V_25 , V_20 ) ;
V_18 = false ;
}
V_20 = V_25 ;
}
return V_18 ;
}
static bool F_8 ( struct V_12 * V_13 )
{
return F_7 ( V_13 -> V_29 , V_13 -> V_31 , V_13 -> V_32 ) &&
F_7 ( V_13 -> V_29 , V_13 -> V_33 ,
V_13 -> V_34 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
const struct V_14 * V_15 ,
int V_16 )
{
int V_17 , V_21 ;
F_10 ( V_13 -> V_35 ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
const struct V_14 * V_19 = & V_15 [ V_17 ] ;
for ( V_21 = 0 ; V_21 < V_19 -> V_22 ; V_21 ++ ) {
const struct V_23 * V_24 =
& V_19 -> V_19 [ V_21 ] ;
struct V_36 * V_37 =
F_11 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return - V_39 ;
V_37 -> V_24 = V_24 ;
F_12 ( V_13 -> V_35 , & V_37 -> V_40 ,
V_24 -> V_26 . V_27 & V_41 ) ;
}
}
return 0 ;
}
static void F_13 ( struct V_12 * V_13 )
{
struct V_42 * V_43 ;
struct V_36 * V_37 ;
int V_17 ;
F_14 (ring->cmd_hash, i, tmp, desc_node, node) {
F_15 ( & V_37 -> V_40 ) ;
F_16 ( V_37 ) ;
}
}
int F_17 ( struct V_12 * V_13 )
{
const struct V_14 * V_15 ;
int V_16 ;
int V_18 ;
if ( ! F_18 ( V_13 -> V_44 ) )
return 0 ;
switch ( V_13 -> V_29 ) {
case V_45 :
if ( F_19 ( V_13 -> V_44 ) ) {
V_15 = V_46 ;
V_16 =
F_20 ( V_46 ) ;
} else {
V_15 = V_47 ;
V_16 = F_20 ( V_47 ) ;
}
V_13 -> V_31 = V_48 ;
V_13 -> V_32 = F_20 ( V_48 ) ;
if ( F_19 ( V_13 -> V_44 ) ) {
V_13 -> V_33 = V_49 ;
V_13 -> V_34 = F_20 ( V_49 ) ;
} else {
V_13 -> V_33 = V_50 ;
V_13 -> V_34 = F_20 ( V_50 ) ;
}
V_13 -> V_51 = F_1 ;
break;
case V_52 :
V_15 = V_53 ;
V_16 = F_20 ( V_53 ) ;
V_13 -> V_51 = F_3 ;
break;
case V_54 :
if ( F_19 ( V_13 -> V_44 ) ) {
V_15 = V_55 ;
V_16 = F_20 ( V_55 ) ;
} else {
V_15 = V_56 ;
V_16 = F_20 ( V_56 ) ;
}
V_13 -> V_31 = V_57 ;
V_13 -> V_32 = F_20 ( V_57 ) ;
if ( F_19 ( V_13 -> V_44 ) ) {
V_13 -> V_33 = V_49 ;
V_13 -> V_34 = F_20 ( V_49 ) ;
} else {
V_13 -> V_33 = V_50 ;
V_13 -> V_34 = F_20 ( V_50 ) ;
}
V_13 -> V_51 = F_4 ;
break;
case V_58 :
V_15 = V_59 ;
V_16 = F_20 ( V_59 ) ;
V_13 -> V_51 = F_3 ;
break;
default:
F_6 ( L_6 ,
V_13 -> V_29 ) ;
F_21 () ;
}
F_22 ( ! F_5 ( V_13 , V_15 , V_16 ) ) ;
F_22 ( ! F_8 ( V_13 ) ) ;
if ( F_23 ( V_13 -> V_35 ) ) {
V_18 = F_9 ( V_13 , V_15 , V_16 ) ;
if ( V_18 ) {
F_6 ( L_7 ) ;
F_13 ( V_13 ) ;
return V_18 ;
}
}
V_13 -> V_60 = true ;
return 0 ;
}
void F_24 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_60 )
return;
F_13 ( V_13 ) ;
}
static const struct V_23 *
F_25 ( struct V_12 * V_13 ,
T_1 V_1 )
{
struct V_36 * V_37 ;
F_26 (ring->cmd_hash, desc_node, node,
cmd_header & CMD_HASH_MASK) {
const struct V_23 * V_24 = V_37 -> V_24 ;
T_1 V_61 = V_24 -> V_26 . V_28 & V_1 ;
T_1 V_62 = V_24 -> V_26 . V_27 & V_24 -> V_26 . V_28 ;
if ( V_61 == V_62 )
return V_24 ;
}
return NULL ;
}
static const struct V_23 *
F_27 ( struct V_12 * V_13 ,
T_1 V_1 ,
struct V_23 * V_63 )
{
const struct V_23 * V_24 ;
T_1 V_28 ;
V_24 = F_25 ( V_13 , V_1 ) ;
if ( V_24 )
return V_24 ;
V_28 = V_13 -> V_51 ( V_1 ) ;
if ( ! V_28 )
return NULL ;
F_22 ( ! V_63 ) ;
V_63 -> V_64 = V_65 ;
V_63 -> V_66 . V_28 = V_28 ;
return V_63 ;
}
static bool F_28 ( const T_1 * V_19 , int V_22 , T_1 V_67 )
{
if ( V_19 && V_22 != 0 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
if ( V_19 [ V_17 ] == V_67 )
return true ;
}
}
return false ;
}
static T_1 * F_29 ( struct V_68 * V_69 )
{
int V_17 ;
void * V_67 = NULL ;
struct V_70 V_71 ;
struct V_72 * * V_73 ;
V_73 = F_30 ( V_69 -> V_74 . V_75 >> V_76 , sizeof( * V_73 ) ) ;
if ( V_73 == NULL ) {
F_2 ( L_8 ) ;
goto V_77;
}
V_17 = 0 ;
F_31 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_73 [ V_17 ] = F_32 ( & V_71 ) ;
V_17 ++ ;
}
V_67 = F_33 ( V_73 , V_17 , 0 , V_78 ) ;
if ( V_67 == NULL ) {
F_2 ( L_9 ) ;
goto V_77;
}
V_77:
if ( V_73 )
F_34 ( V_73 ) ;
return ( T_1 * ) V_67 ;
}
bool F_35 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_60 )
return false ;
if ( F_36 ( V_13 -> V_44 ) )
return false ;
return ( V_79 . V_80 == 1 ) ;
}
static bool F_37 ( const struct V_12 * V_13 ,
const struct V_23 * V_24 ,
const T_1 * V_26 ,
const bool V_81 ,
bool * V_82 )
{
if ( V_24 -> V_64 & V_83 ) {
F_2 ( L_10 , * V_26 ) ;
return false ;
}
if ( ( V_24 -> V_64 & V_84 ) && ! V_81 ) {
F_2 ( L_11 ,
* V_26 ) ;
return false ;
}
if ( V_24 -> V_64 & V_85 ) {
T_1 V_86 = V_26 [ V_24 -> V_87 . V_88 ] & V_24 -> V_87 . V_28 ;
if ( V_86 == V_89 ) {
if ( V_24 -> V_26 . V_27 == V_90 )
return false ;
if ( V_24 -> V_26 . V_27 == F_38 ( 1 ) )
* V_82 = ( V_26 [ 2 ] != 0 ) ;
}
if ( ! F_28 ( V_13 -> V_31 ,
V_13 -> V_32 , V_86 ) ) {
if ( ! V_81 ||
! F_28 ( V_13 -> V_33 ,
V_13 -> V_34 ,
V_86 ) ) {
F_2 ( L_12 ,
V_86 ,
* V_26 ,
V_13 -> V_29 ) ;
return false ;
}
}
}
if ( V_24 -> V_64 & V_91 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_92 ; V_17 ++ ) {
T_1 V_93 ;
if ( V_24 -> V_94 [ V_17 ] . V_28 == 0 )
break;
if ( V_24 -> V_94 [ V_17 ] . V_95 != 0 ) {
T_1 V_88 =
V_24 -> V_94 [ V_17 ] . V_96 ;
T_1 V_97 = V_26 [ V_88 ] &
V_24 -> V_94 [ V_17 ] . V_95 ;
if ( V_97 == 0 )
continue;
}
V_93 = V_26 [ V_24 -> V_94 [ V_17 ] . V_88 ] &
V_24 -> V_94 [ V_17 ] . V_28 ;
if ( V_93 != V_24 -> V_94 [ V_17 ] . V_98 ) {
F_2 ( L_13 ,
* V_26 ,
V_24 -> V_94 [ V_17 ] . V_28 ,
V_24 -> V_94 [ V_17 ] . V_98 ,
V_93 , V_13 -> V_29 ) ;
return false ;
}
}
}
return true ;
}
int F_39 ( struct V_12 * V_13 ,
struct V_68 * V_99 ,
T_1 V_100 ,
bool V_81 )
{
int V_18 = 0 ;
T_1 * V_26 , * V_101 , * V_102 ;
struct V_23 V_63 = { 0 } ;
int V_103 = 0 ;
bool V_82 = false ;
V_18 = F_40 ( V_99 , & V_103 ) ;
if ( V_18 ) {
F_2 ( L_14 ) ;
return V_18 ;
}
V_101 = F_29 ( V_99 ) ;
if ( ! V_101 ) {
F_2 ( L_15 ) ;
F_41 ( V_99 ) ;
return - V_39 ;
}
if ( V_103 )
F_42 ( ( char * ) V_101 , V_99 -> V_74 . V_75 ) ;
V_26 = V_101 + ( V_100 / sizeof( * V_26 ) ) ;
V_102 = V_26 + ( V_99 -> V_74 . V_75 / sizeof( * V_102 ) ) ;
while ( V_26 < V_102 ) {
const struct V_23 * V_24 ;
T_1 V_66 ;
if ( * V_26 == V_104 )
break;
V_24 = F_27 ( V_13 , * V_26 , & V_63 ) ;
if ( ! V_24 ) {
F_2 ( L_16 ,
* V_26 ) ;
V_18 = - V_105 ;
break;
}
if ( V_24 -> V_64 & V_106 )
V_66 = V_24 -> V_66 . V_107 ;
else
V_66 = ( ( * V_26 & V_24 -> V_66 . V_28 ) + V_108 ) ;
if ( ( V_102 - V_26 ) < V_66 ) {
F_2 ( L_17 ,
* V_26 ,
V_66 ,
V_102 - V_26 ) ;
V_18 = - V_105 ;
break;
}
if ( ! F_37 ( V_13 , V_24 , V_26 , V_81 , & V_82 ) ) {
V_18 = - V_105 ;
break;
}
V_26 += V_66 ;
}
if ( V_82 ) {
F_2 ( L_18 ) ;
V_18 = - V_105 ;
}
if ( V_26 >= V_102 ) {
F_2 ( L_19 ) ;
V_18 = - V_105 ;
}
F_43 ( V_101 ) ;
F_41 ( V_99 ) ;
return V_18 ;
}
int F_44 ( void )
{
return 1 ;
}
