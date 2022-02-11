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
static bool F_7 ( int V_33 ,
const struct V_34 * V_35 ,
int V_36 )
{
int V_20 ;
T_1 V_23 = 0 ;
bool V_21 = true ;
for ( V_20 = 0 ; V_20 < V_36 ; V_20 ++ ) {
T_1 V_28 = V_35 [ V_20 ] . V_37 ;
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
return F_7 ( V_16 -> V_32 , V_16 -> V_35 , V_16 -> V_36 ) &&
F_7 ( V_16 -> V_32 , V_16 -> V_38 ,
V_16 -> V_39 ) ;
}
static int F_9 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 , V_24 ;
F_10 ( V_16 -> V_40 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
const struct V_17 * V_22 = & V_18 [ V_20 ] ;
for ( V_24 = 0 ; V_24 < V_22 -> V_25 ; V_24 ++ ) {
const struct V_26 * V_27 =
& V_22 -> V_22 [ V_24 ] ;
struct V_41 * V_42 =
F_11 ( sizeof( * V_42 ) , V_43 ) ;
if ( ! V_42 )
return - V_44 ;
V_42 -> V_27 = V_27 ;
F_12 ( V_16 -> V_40 , & V_42 -> V_45 ,
V_27 -> V_29 . V_30 & V_46 ) ;
}
}
return 0 ;
}
static void F_13 ( struct V_15 * V_16 )
{
struct V_47 * V_48 ;
struct V_41 * V_42 ;
int V_20 ;
F_14 (ring->cmd_hash, i, tmp, desc_node, node) {
F_15 ( & V_42 -> V_45 ) ;
F_16 ( V_42 ) ;
}
}
int F_17 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
int V_19 ;
int V_21 ;
if ( ! F_18 ( V_16 -> V_49 ) )
return 0 ;
switch ( V_16 -> V_32 ) {
case V_50 :
if ( F_19 ( V_16 -> V_49 ) ) {
V_18 = V_51 ;
V_19 =
F_20 ( V_51 ) ;
} else {
V_18 = V_52 ;
V_19 = F_20 ( V_52 ) ;
}
V_16 -> V_35 = V_53 ;
V_16 -> V_36 = F_20 ( V_53 ) ;
if ( F_19 ( V_16 -> V_49 ) ) {
V_16 -> V_38 = V_54 ;
V_16 -> V_39 = F_20 ( V_54 ) ;
} else {
V_16 -> V_38 = V_55 ;
V_16 -> V_39 = F_20 ( V_55 ) ;
}
V_16 -> V_56 = F_1 ;
break;
case V_57 :
V_18 = V_58 ;
V_19 = F_20 ( V_58 ) ;
V_16 -> V_56 = F_3 ;
break;
case V_59 :
if ( F_19 ( V_16 -> V_49 ) ) {
V_18 = V_60 ;
V_19 = F_20 ( V_60 ) ;
} else {
V_18 = V_61 ;
V_19 = F_20 ( V_61 ) ;
}
V_16 -> V_35 = V_62 ;
V_16 -> V_36 = F_20 ( V_62 ) ;
if ( F_19 ( V_16 -> V_49 ) ) {
V_16 -> V_38 = V_54 ;
V_16 -> V_39 = F_20 ( V_54 ) ;
} else {
V_16 -> V_38 = V_55 ;
V_16 -> V_39 = F_20 ( V_55 ) ;
}
V_16 -> V_56 = F_4 ;
break;
case V_63 :
V_18 = V_64 ;
V_19 = F_20 ( V_64 ) ;
V_16 -> V_56 = F_3 ;
break;
default:
F_6 ( L_6 ,
V_16 -> V_32 ) ;
F_21 () ;
}
F_22 ( ! F_5 ( V_16 , V_18 , V_19 ) ) ;
F_22 ( ! F_8 ( V_16 ) ) ;
F_23 ( ! F_24 ( V_16 -> V_40 ) ) ;
V_21 = F_9 ( V_16 , V_18 , V_19 ) ;
if ( V_21 ) {
F_6 ( L_7 ) ;
F_13 ( V_16 ) ;
return V_21 ;
}
V_16 -> V_65 = true ;
return 0 ;
}
void F_25 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_65 )
return;
F_13 ( V_16 ) ;
}
static const struct V_26 *
F_26 ( struct V_15 * V_16 ,
T_1 V_1 )
{
struct V_41 * V_42 ;
F_27 (ring->cmd_hash, desc_node, node,
cmd_header & CMD_HASH_MASK) {
const struct V_26 * V_27 = V_42 -> V_27 ;
T_1 V_66 = V_27 -> V_29 . V_31 & V_1 ;
T_1 V_67 = V_27 -> V_29 . V_30 & V_27 -> V_29 . V_31 ;
if ( V_66 == V_67 )
return V_27 ;
}
return NULL ;
}
static const struct V_26 *
F_28 ( struct V_15 * V_16 ,
T_1 V_1 ,
struct V_26 * V_68 )
{
const struct V_26 * V_27 ;
T_1 V_31 ;
V_27 = F_26 ( V_16 , V_1 ) ;
if ( V_27 )
return V_27 ;
V_31 = V_16 -> V_56 ( V_1 ) ;
if ( ! V_31 )
return NULL ;
F_22 ( ! V_68 ) ;
V_68 -> V_69 = V_70 ;
V_68 -> V_71 . V_31 = V_31 ;
return V_68 ;
}
static const struct V_34 *
F_29 ( const struct V_34 * V_22 ,
int V_25 , T_1 V_37 )
{
if ( V_22 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( V_22 [ V_20 ] . V_37 == V_37 )
return & V_22 [ V_20 ] ;
}
}
return NULL ;
}
static T_1 * F_30 ( struct V_72 * V_73 ,
unsigned V_74 , unsigned V_75 )
{
int V_20 ;
void * V_37 = NULL ;
struct V_76 V_77 ;
int V_78 = V_74 >> V_79 ;
int V_80 = ( V_75 + V_74 + 4095 ) >> V_79 ;
int V_81 = V_80 - V_78 ;
struct V_82 * * V_83 ;
V_83 = F_31 ( V_81 , sizeof( * V_83 ) ) ;
if ( V_83 == NULL ) {
F_2 ( L_8 ) ;
goto V_84;
}
V_20 = 0 ;
F_32 (obj->pages->sgl, &sg_iter, obj->pages->nents, first_page) {
V_83 [ V_20 ++ ] = F_33 ( & V_77 ) ;
if ( V_20 == V_81 )
break;
}
V_37 = F_34 ( V_83 , V_20 , 0 , V_85 ) ;
if ( V_37 == NULL ) {
F_2 ( L_9 ) ;
goto V_84;
}
V_84:
if ( V_83 )
F_35 ( V_83 ) ;
return ( T_1 * ) V_37 ;
}
static T_1 * F_36 ( struct V_72 * V_86 ,
struct V_72 * V_87 ,
T_1 V_88 ,
T_1 V_89 )
{
int V_90 = 0 ;
void * V_91 , * V_92 ;
void * V_93 = NULL ;
int V_21 ;
if ( V_89 > V_86 -> V_94 . V_95 ||
V_89 + V_88 > V_87 -> V_94 . V_95 )
return F_37 ( - V_96 ) ;
if ( F_23 ( V_86 -> V_97 == 0 ) )
return F_37 ( - V_98 ) ;
V_21 = F_38 ( V_87 , & V_90 ) ;
if ( V_21 ) {
F_2 ( L_10 ) ;
return F_37 ( V_21 ) ;
}
V_91 = F_30 ( V_87 , V_88 , V_89 ) ;
if ( ! V_91 ) {
F_2 ( L_11 ) ;
V_21 = - V_44 ;
goto V_99;
}
V_21 = F_39 ( V_86 , true ) ;
if ( V_21 ) {
F_2 ( L_12 ) ;
goto V_100;
}
V_93 = F_30 ( V_86 , 0 , V_89 ) ;
if ( ! V_93 ) {
F_2 ( L_13 ) ;
V_21 = - V_44 ;
goto V_100;
}
V_92 = V_91 + F_40 ( V_88 ) ;
if ( V_90 )
F_41 ( V_92 , V_89 ) ;
memcpy ( V_93 , V_92 , V_89 ) ;
V_100:
F_42 ( V_91 ) ;
V_99:
F_43 ( V_87 ) ;
return V_21 ? F_37 ( V_21 ) : V_93 ;
}
bool F_44 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_65 )
return false ;
if ( ! F_45 ( V_16 -> V_49 ) )
return false ;
return ( V_101 . V_102 == 1 ) ;
}
static bool F_46 ( const struct V_15 * V_16 ,
const struct V_26 * V_27 ,
const T_1 * V_29 , T_1 V_71 ,
const bool V_103 ,
bool * V_104 )
{
if ( V_27 -> V_69 & V_105 ) {
F_2 ( L_14 , * V_29 ) ;
return false ;
}
if ( ( V_27 -> V_69 & V_106 ) && ! V_103 ) {
F_2 ( L_15 ,
* V_29 ) ;
return false ;
}
if ( V_27 -> V_69 & V_107 ) {
const T_1 V_108 = V_27 -> V_109 . V_108 ? V_27 -> V_109 . V_108 : V_71 ;
T_1 V_110 ;
for ( V_110 = V_27 -> V_109 . V_110 ; V_110 < V_71 ;
V_110 += V_108 ) {
const T_1 V_111 = V_29 [ V_110 ] & V_27 -> V_109 . V_31 ;
const struct V_34 * V_109 =
F_29 ( V_16 -> V_35 , V_16 -> V_36 ,
V_111 ) ;
if ( ! V_109 && V_103 )
V_109 = F_29 ( V_16 -> V_38 ,
V_16 -> V_39 ,
V_111 ) ;
if ( ! V_109 ) {
F_2 ( L_16 ,
V_111 , * V_29 , V_16 -> V_32 ) ;
return false ;
}
if ( V_111 == V_112 ) {
if ( V_27 -> V_29 . V_30 == V_113 ) {
F_2 ( L_17 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_47 ( 1 ) )
* V_104 = ( V_29 [ V_110 + 1 ] != 0 ) ;
}
if ( V_109 -> V_31 ) {
if ( V_27 -> V_29 . V_30 == V_113 ) {
F_2 ( L_18 ,
V_111 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_47 ( 1 ) &&
( V_110 + 2 > V_71 ||
( V_29 [ V_110 + 1 ] & V_109 -> V_31 ) != V_109 -> V_30 ) ) {
F_2 ( L_19 ,
V_111 ) ;
return false ;
}
}
}
}
if ( V_27 -> V_69 & V_114 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_115 ; V_20 ++ ) {
T_1 V_116 ;
if ( V_27 -> V_117 [ V_20 ] . V_31 == 0 )
break;
if ( V_27 -> V_117 [ V_20 ] . V_118 != 0 ) {
T_1 V_110 =
V_27 -> V_117 [ V_20 ] . V_119 ;
T_1 V_120 = V_29 [ V_110 ] &
V_27 -> V_117 [ V_20 ] . V_118 ;
if ( V_120 == 0 )
continue;
}
V_116 = V_29 [ V_27 -> V_117 [ V_20 ] . V_110 ] &
V_27 -> V_117 [ V_20 ] . V_31 ;
if ( V_116 != V_27 -> V_117 [ V_20 ] . V_121 ) {
F_2 ( L_20 ,
* V_29 ,
V_27 -> V_117 [ V_20 ] . V_31 ,
V_27 -> V_117 [ V_20 ] . V_121 ,
V_116 , V_16 -> V_32 ) ;
return false ;
}
}
}
return true ;
}
int F_48 ( struct V_15 * V_16 ,
struct V_72 * V_122 ,
struct V_72 * V_123 ,
T_1 V_88 ,
T_1 V_89 ,
bool V_103 )
{
T_1 * V_29 , * V_124 , * V_125 ;
struct V_26 V_68 = { 0 } ;
bool V_104 = false ;
int V_21 = 0 ;
V_124 = F_36 ( V_123 , V_122 ,
V_88 , V_89 ) ;
if ( F_49 ( V_124 ) ) {
F_2 ( L_21 ) ;
return F_50 ( V_124 ) ;
}
V_125 = V_124 + ( V_89 / sizeof( * V_125 ) ) ;
V_29 = V_124 ;
while ( V_29 < V_125 ) {
const struct V_26 * V_27 ;
T_1 V_71 ;
if ( * V_29 == V_126 )
break;
V_27 = F_28 ( V_16 , * V_29 , & V_68 ) ;
if ( ! V_27 ) {
F_2 ( L_22 ,
* V_29 ) ;
V_21 = - V_127 ;
break;
}
if ( V_27 -> V_29 . V_30 == V_128 ) {
V_21 = - V_129 ;
break;
}
if ( V_27 -> V_69 & V_130 )
V_71 = V_27 -> V_71 . V_131 ;
else
V_71 = ( ( * V_29 & V_27 -> V_71 . V_31 ) + V_132 ) ;
if ( ( V_125 - V_29 ) < V_71 ) {
F_2 ( L_23 ,
* V_29 ,
V_71 ,
V_125 - V_29 ) ;
V_21 = - V_127 ;
break;
}
if ( ! F_46 ( V_16 , V_27 , V_29 , V_71 , V_103 ,
& V_104 ) ) {
V_21 = - V_127 ;
break;
}
V_29 += V_71 ;
}
if ( V_104 ) {
F_2 ( L_24 ) ;
V_21 = - V_127 ;
}
if ( V_29 >= V_125 ) {
F_2 ( L_25 ) ;
V_21 = - V_127 ;
}
F_42 ( V_124 ) ;
return V_21 ;
}
int F_51 ( void )
{
return 3 ;
}
