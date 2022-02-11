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
T_1 V_11 = ( V_1 & V_12 ) >> V_13 ;
if ( V_2 == V_8 )
return 0x3F ;
else if ( V_2 == V_9 ) {
if ( V_5 == V_10 ) {
if ( V_11 == 6 )
return 0xFFFF ;
else
return 0xFFF ;
} else
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
else if ( V_2 == V_14 )
return 0xFF ;
F_2 ( L_3 , V_1 ) ;
return 0 ;
}
static bool F_5 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 ;
bool V_21 = true ;
if ( ! V_18 || V_19 == 0 )
return true ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
const struct V_17 * V_22 = & V_18 [ V_20 ] ;
T_1 V_23 = 0 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 -> V_25 ; V_24 ++ ) {
const struct V_26 * V_27 =
& V_22 -> V_22 [ V_20 ] ;
T_1 V_28 = V_27 -> V_29 . V_30 & V_27 -> V_29 . V_31 ;
if ( V_28 < V_23 ) {
F_6 ( L_4 ,
V_16 -> V_32 , V_20 , V_24 , V_28 , V_23 ) ;
V_21 = false ;
}
V_23 = V_28 ;
}
}
return V_21 ;
}
static bool F_7 ( int V_33 , const T_1 * V_34 , int V_35 )
{
int V_20 ;
T_1 V_23 = 0 ;
bool V_21 = true ;
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
T_1 V_28 = V_34 [ V_20 ] ;
if ( V_28 < V_23 ) {
F_6 ( L_5 ,
V_33 , V_20 , V_28 , V_23 ) ;
V_21 = false ;
}
V_23 = V_28 ;
}
return V_21 ;
}
static bool F_8 ( struct V_15 * V_16 )
{
return F_7 ( V_16 -> V_32 , V_16 -> V_34 , V_16 -> V_35 ) &&
F_7 ( V_16 -> V_32 , V_16 -> V_36 ,
V_16 -> V_37 ) ;
}
static int F_9 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 , V_24 ;
F_10 ( V_16 -> V_38 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
const struct V_17 * V_22 = & V_18 [ V_20 ] ;
for ( V_24 = 0 ; V_24 < V_22 -> V_25 ; V_24 ++ ) {
const struct V_26 * V_27 =
& V_22 -> V_22 [ V_24 ] ;
struct V_39 * V_40 =
F_11 ( sizeof( * V_40 ) , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
V_40 -> V_27 = V_27 ;
F_12 ( V_16 -> V_38 , & V_40 -> V_43 ,
V_27 -> V_29 . V_30 & V_44 ) ;
}
}
return 0 ;
}
static void F_13 ( struct V_15 * V_16 )
{
struct V_45 * V_46 ;
struct V_39 * V_40 ;
int V_20 ;
F_14 (ring->cmd_hash, i, tmp, desc_node, node) {
F_15 ( & V_40 -> V_43 ) ;
F_16 ( V_40 ) ;
}
}
int F_17 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
int V_19 ;
int V_21 ;
if ( ! F_18 ( V_16 -> V_47 ) )
return 0 ;
switch ( V_16 -> V_32 ) {
case V_48 :
if ( F_19 ( V_16 -> V_47 ) ) {
V_18 = V_49 ;
V_19 =
F_20 ( V_49 ) ;
} else {
V_18 = V_50 ;
V_19 = F_20 ( V_50 ) ;
}
V_16 -> V_34 = V_51 ;
V_16 -> V_35 = F_20 ( V_51 ) ;
if ( F_19 ( V_16 -> V_47 ) ) {
V_16 -> V_36 = V_52 ;
V_16 -> V_37 = F_20 ( V_52 ) ;
} else {
V_16 -> V_36 = V_53 ;
V_16 -> V_37 = F_20 ( V_53 ) ;
}
V_16 -> V_54 = F_1 ;
break;
case V_55 :
V_18 = V_56 ;
V_19 = F_20 ( V_56 ) ;
V_16 -> V_54 = F_3 ;
break;
case V_57 :
if ( F_19 ( V_16 -> V_47 ) ) {
V_18 = V_58 ;
V_19 = F_20 ( V_58 ) ;
} else {
V_18 = V_59 ;
V_19 = F_20 ( V_59 ) ;
}
V_16 -> V_34 = V_60 ;
V_16 -> V_35 = F_20 ( V_60 ) ;
if ( F_19 ( V_16 -> V_47 ) ) {
V_16 -> V_36 = V_52 ;
V_16 -> V_37 = F_20 ( V_52 ) ;
} else {
V_16 -> V_36 = V_53 ;
V_16 -> V_37 = F_20 ( V_53 ) ;
}
V_16 -> V_54 = F_4 ;
break;
case V_61 :
V_18 = V_62 ;
V_19 = F_20 ( V_62 ) ;
V_16 -> V_54 = F_3 ;
break;
default:
F_6 ( L_6 ,
V_16 -> V_32 ) ;
F_21 () ;
}
F_22 ( ! F_5 ( V_16 , V_18 , V_19 ) ) ;
F_22 ( ! F_8 ( V_16 ) ) ;
F_23 ( ! F_24 ( V_16 -> V_38 ) ) ;
V_21 = F_9 ( V_16 , V_18 , V_19 ) ;
if ( V_21 ) {
F_6 ( L_7 ) ;
F_13 ( V_16 ) ;
return V_21 ;
}
V_16 -> V_63 = true ;
return 0 ;
}
void F_25 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_63 )
return;
F_13 ( V_16 ) ;
}
static const struct V_26 *
F_26 ( struct V_15 * V_16 ,
T_1 V_1 )
{
struct V_39 * V_40 ;
F_27 (ring->cmd_hash, desc_node, node,
cmd_header & CMD_HASH_MASK) {
const struct V_26 * V_27 = V_40 -> V_27 ;
T_1 V_64 = V_27 -> V_29 . V_31 & V_1 ;
T_1 V_65 = V_27 -> V_29 . V_30 & V_27 -> V_29 . V_31 ;
if ( V_64 == V_65 )
return V_27 ;
}
return NULL ;
}
static const struct V_26 *
F_28 ( struct V_15 * V_16 ,
T_1 V_1 ,
struct V_26 * V_66 )
{
const struct V_26 * V_27 ;
T_1 V_31 ;
V_27 = F_26 ( V_16 , V_1 ) ;
if ( V_27 )
return V_27 ;
V_31 = V_16 -> V_54 ( V_1 ) ;
if ( ! V_31 )
return NULL ;
F_22 ( ! V_66 ) ;
V_66 -> V_67 = V_68 ;
V_66 -> V_69 . V_31 = V_31 ;
return V_66 ;
}
static bool F_29 ( const T_1 * V_22 , int V_25 , T_1 V_70 )
{
if ( V_22 && V_25 != 0 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_22 [ V_20 ] == V_70 )
return true ;
}
}
return false ;
}
static T_1 * F_30 ( struct V_71 * V_72 ,
unsigned V_73 , unsigned V_74 )
{
int V_20 ;
void * V_70 = NULL ;
struct V_75 V_76 ;
int V_77 = V_73 >> V_78 ;
int V_79 = ( V_74 + V_73 + 4095 ) >> V_78 ;
int V_80 = V_79 - V_77 ;
struct V_81 * * V_82 ;
V_82 = F_31 ( V_80 , sizeof( * V_82 ) ) ;
if ( V_82 == NULL ) {
F_2 ( L_8 ) ;
goto V_83;
}
V_20 = 0 ;
F_32 (obj->pages->sgl, &sg_iter, obj->pages->nents, first_page) {
V_82 [ V_20 ++ ] = F_33 ( & V_76 ) ;
if ( V_20 == V_80 )
break;
}
V_70 = F_34 ( V_82 , V_20 , 0 , V_84 ) ;
if ( V_70 == NULL ) {
F_2 ( L_9 ) ;
goto V_83;
}
V_83:
if ( V_82 )
F_35 ( V_82 ) ;
return ( T_1 * ) V_70 ;
}
static T_1 * F_36 ( struct V_71 * V_85 ,
struct V_71 * V_86 ,
T_1 V_87 ,
T_1 V_88 )
{
int V_89 = 0 ;
void * V_90 , * V_91 ;
void * V_92 = NULL ;
int V_21 ;
if ( V_88 > V_85 -> V_93 . V_94 ||
V_88 + V_87 > V_86 -> V_93 . V_94 )
return F_37 ( - V_95 ) ;
V_21 = F_38 ( V_86 , & V_89 ) ;
if ( V_21 ) {
F_2 ( L_10 ) ;
return F_37 ( V_21 ) ;
}
V_90 = F_30 ( V_86 , V_87 , V_88 ) ;
if ( ! V_90 ) {
F_2 ( L_11 ) ;
V_21 = - V_42 ;
goto V_96;
}
V_21 = F_39 ( V_85 ) ;
if ( V_21 ) {
F_2 ( L_12 ) ;
goto V_97;
}
F_40 ( V_85 ) ;
V_21 = F_41 ( V_85 , true ) ;
if ( V_21 ) {
F_2 ( L_13 ) ;
goto V_97;
}
V_92 = F_30 ( V_85 , 0 , V_88 ) ;
if ( ! V_92 ) {
F_2 ( L_14 ) ;
F_42 ( V_85 ) ;
V_21 = - V_42 ;
goto V_97;
}
V_91 = V_90 + F_43 ( V_87 ) ;
if ( V_89 )
F_44 ( V_91 , V_88 ) ;
memcpy ( V_92 , V_91 , V_88 ) ;
V_97:
F_45 ( V_90 ) ;
V_96:
F_42 ( V_86 ) ;
return V_21 ? F_37 ( V_21 ) : V_92 ;
}
bool F_46 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_63 )
return false ;
if ( ! F_47 ( V_16 -> V_47 ) )
return false ;
return ( V_98 . V_99 == 1 ) ;
}
static bool F_48 ( const struct V_15 * V_16 ,
const struct V_26 * V_27 ,
const T_1 * V_29 ,
const bool V_100 ,
bool * V_101 )
{
if ( V_27 -> V_67 & V_102 ) {
F_2 ( L_15 , * V_29 ) ;
return false ;
}
if ( ( V_27 -> V_67 & V_103 ) && ! V_100 ) {
F_2 ( L_16 ,
* V_29 ) ;
return false ;
}
if ( V_27 -> V_67 & V_104 ) {
T_1 V_105 = V_29 [ V_27 -> V_106 . V_107 ] & V_27 -> V_106 . V_31 ;
if ( V_105 == V_108 ) {
if ( V_27 -> V_29 . V_30 == V_109 ) {
F_2 ( L_17 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_49 ( 1 ) )
* V_101 = ( V_29 [ 2 ] != 0 ) ;
}
if ( ! F_29 ( V_16 -> V_34 ,
V_16 -> V_35 , V_105 ) ) {
if ( ! V_100 ||
! F_29 ( V_16 -> V_36 ,
V_16 -> V_37 ,
V_105 ) ) {
F_2 ( L_18 ,
V_105 ,
* V_29 ,
V_16 -> V_32 ) ;
return false ;
}
}
}
if ( V_27 -> V_67 & V_110 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_111 ; V_20 ++ ) {
T_1 V_112 ;
if ( V_27 -> V_113 [ V_20 ] . V_31 == 0 )
break;
if ( V_27 -> V_113 [ V_20 ] . V_114 != 0 ) {
T_1 V_107 =
V_27 -> V_113 [ V_20 ] . V_115 ;
T_1 V_116 = V_29 [ V_107 ] &
V_27 -> V_113 [ V_20 ] . V_114 ;
if ( V_116 == 0 )
continue;
}
V_112 = V_29 [ V_27 -> V_113 [ V_20 ] . V_107 ] &
V_27 -> V_113 [ V_20 ] . V_31 ;
if ( V_112 != V_27 -> V_113 [ V_20 ] . V_117 ) {
F_2 ( L_19 ,
* V_29 ,
V_27 -> V_113 [ V_20 ] . V_31 ,
V_27 -> V_113 [ V_20 ] . V_117 ,
V_112 , V_16 -> V_32 ) ;
return false ;
}
}
}
return true ;
}
int F_50 ( struct V_15 * V_16 ,
struct V_71 * V_118 ,
struct V_71 * V_119 ,
T_1 V_87 ,
T_1 V_88 ,
bool V_100 )
{
T_1 * V_29 , * V_120 , * V_121 ;
struct V_26 V_66 = { 0 } ;
bool V_101 = false ;
int V_21 = 0 ;
V_120 = F_36 ( V_119 , V_118 ,
V_87 , V_88 ) ;
if ( F_51 ( V_120 ) ) {
F_2 ( L_20 ) ;
return F_52 ( V_120 ) ;
}
V_121 = V_120 + ( V_88 / sizeof( * V_121 ) ) ;
V_29 = V_120 ;
while ( V_29 < V_121 ) {
const struct V_26 * V_27 ;
T_1 V_69 ;
if ( * V_29 == V_122 )
break;
V_27 = F_28 ( V_16 , * V_29 , & V_66 ) ;
if ( ! V_27 ) {
F_2 ( L_21 ,
* V_29 ) ;
V_21 = - V_123 ;
break;
}
if ( V_27 -> V_29 . V_30 == V_124 ) {
V_21 = - V_125 ;
break;
}
if ( V_27 -> V_67 & V_126 )
V_69 = V_27 -> V_69 . V_127 ;
else
V_69 = ( ( * V_29 & V_27 -> V_69 . V_31 ) + V_128 ) ;
if ( ( V_121 - V_29 ) < V_69 ) {
F_2 ( L_22 ,
* V_29 ,
V_69 ,
V_121 - V_29 ) ;
V_21 = - V_123 ;
break;
}
if ( ! F_48 ( V_16 , V_27 , V_29 , V_100 , & V_101 ) ) {
V_21 = - V_123 ;
break;
}
V_29 += V_69 ;
}
if ( V_101 ) {
F_2 ( L_23 ) ;
V_21 = - V_123 ;
}
if ( V_29 >= V_121 ) {
F_2 ( L_24 ) ;
V_21 = - V_123 ;
}
F_45 ( V_120 ) ;
F_42 ( V_119 ) ;
return V_21 ;
}
int F_53 ( void )
{
return 3 ;
}
