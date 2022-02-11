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
& V_22 -> V_22 [ V_24 ] ;
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
T_1 V_28 = F_8 ( V_35 [ V_20 ] . V_37 ) ;
if ( V_28 < V_23 ) {
F_6 ( L_5 ,
V_33 , V_20 , V_28 , V_23 ) ;
V_21 = false ;
}
V_23 = V_28 ;
}
return V_21 ;
}
static bool F_9 ( struct V_15 * V_16 )
{
int V_20 ;
const struct V_38 * V_22 ;
for ( V_20 = 0 ; V_20 < V_16 -> V_39 ; V_20 ++ ) {
V_22 = & V_16 -> V_40 [ V_20 ] ;
if ( ! F_7 ( V_16 -> V_32 , V_22 -> V_41 , V_22 -> V_42 ) )
return false ;
}
return true ;
}
static int F_10 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 , V_24 ;
F_11 ( V_16 -> V_43 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
const struct V_17 * V_22 = & V_18 [ V_20 ] ;
for ( V_24 = 0 ; V_24 < V_22 -> V_25 ; V_24 ++ ) {
const struct V_26 * V_27 =
& V_22 -> V_22 [ V_24 ] ;
struct V_44 * V_45 =
F_12 ( sizeof( * V_45 ) , V_46 ) ;
if ( ! V_45 )
return - V_47 ;
V_45 -> V_27 = V_27 ;
F_13 ( V_16 -> V_43 , & V_45 -> V_48 ,
V_27 -> V_29 . V_30 & V_49 ) ;
}
}
return 0 ;
}
static void F_14 ( struct V_15 * V_16 )
{
struct V_50 * V_51 ;
struct V_44 * V_45 ;
int V_20 ;
F_15 (engine->cmd_hash, i, tmp, desc_node, node) {
F_16 ( & V_45 -> V_48 ) ;
F_17 ( V_45 ) ;
}
}
int F_18 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
int V_19 ;
int V_21 ;
if ( ! F_19 ( V_16 -> V_52 ) )
return 0 ;
switch ( V_16 -> V_32 ) {
case V_53 :
if ( F_20 ( V_16 -> V_52 ) ) {
V_18 = V_54 ;
V_19 =
F_21 ( V_54 ) ;
} else {
V_18 = V_55 ;
V_19 = F_21 ( V_55 ) ;
}
if ( F_20 ( V_16 -> V_52 ) ) {
V_16 -> V_40 = V_56 ;
V_16 -> V_39 = F_21 ( V_56 ) ;
} else {
V_16 -> V_40 = V_57 ;
V_16 -> V_39 = F_21 ( V_57 ) ;
}
V_16 -> V_58 = F_1 ;
break;
case V_59 :
V_18 = V_60 ;
V_19 = F_21 ( V_60 ) ;
V_16 -> V_58 = F_3 ;
break;
case V_61 :
if ( F_20 ( V_16 -> V_52 ) ) {
V_18 = V_62 ;
V_19 = F_21 ( V_62 ) ;
} else {
V_18 = V_63 ;
V_19 = F_21 ( V_63 ) ;
}
if ( F_20 ( V_16 -> V_52 ) ) {
V_16 -> V_40 = V_64 ;
V_16 -> V_39 = F_21 ( V_64 ) ;
} else {
V_16 -> V_40 = V_65 ;
V_16 -> V_39 = F_21 ( V_65 ) ;
}
V_16 -> V_58 = F_4 ;
break;
case V_66 :
V_18 = V_67 ;
V_19 = F_21 ( V_67 ) ;
V_16 -> V_58 = F_3 ;
break;
default:
F_6 ( L_6 ,
V_16 -> V_32 ) ;
F_22 () ;
}
F_23 ( ! F_5 ( V_16 , V_18 , V_19 ) ) ;
F_23 ( ! F_9 ( V_16 ) ) ;
F_24 ( ! F_25 ( V_16 -> V_43 ) ) ;
V_21 = F_10 ( V_16 , V_18 , V_19 ) ;
if ( V_21 ) {
F_6 ( L_7 ) ;
F_14 ( V_16 ) ;
return V_21 ;
}
V_16 -> V_68 = true ;
return 0 ;
}
void F_26 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_68 )
return;
F_14 ( V_16 ) ;
}
static const struct V_26 *
F_27 ( struct V_15 * V_16 ,
T_1 V_1 )
{
struct V_44 * V_45 ;
F_28 (engine->cmd_hash, desc_node, node,
cmd_header & CMD_HASH_MASK) {
const struct V_26 * V_27 = V_45 -> V_27 ;
T_1 V_69 = V_27 -> V_29 . V_31 & V_1 ;
T_1 V_70 = V_27 -> V_29 . V_30 & V_27 -> V_29 . V_31 ;
if ( V_69 == V_70 )
return V_27 ;
}
return NULL ;
}
static const struct V_26 *
F_29 ( struct V_15 * V_16 ,
T_1 V_1 ,
struct V_26 * V_71 )
{
const struct V_26 * V_27 ;
T_1 V_31 ;
V_27 = F_27 ( V_16 , V_1 ) ;
if ( V_27 )
return V_27 ;
V_31 = V_16 -> V_58 ( V_1 ) ;
if ( ! V_31 )
return NULL ;
F_23 ( ! V_71 ) ;
V_71 -> V_72 = V_73 ;
V_71 -> V_74 . V_31 = V_31 ;
return V_71 ;
}
static const struct V_34 *
F_30 ( const struct V_34 * V_22 ,
int V_25 , T_1 V_37 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
if ( F_8 ( V_22 [ V_20 ] . V_37 ) == V_37 )
return & V_22 [ V_20 ] ;
}
return NULL ;
}
static const struct V_34 *
F_31 ( const struct V_38 * V_75 ,
int V_25 , bool V_76 , T_1 V_37 )
{
int V_20 ;
const struct V_38 * V_22 ;
const struct V_34 * V_77 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
V_22 = & V_75 [ V_20 ] ;
if ( ! V_22 -> V_78 || V_76 ) {
V_77 = F_30 ( V_22 -> V_41 , V_22 -> V_42 ,
V_37 ) ;
if ( V_77 != NULL )
return V_77 ;
}
}
return NULL ;
}
static T_1 * F_32 ( struct V_79 * V_80 ,
unsigned V_81 , unsigned V_82 )
{
int V_20 ;
void * V_37 = NULL ;
struct V_83 V_84 ;
int V_85 = V_81 >> V_86 ;
int V_87 = ( V_82 + V_81 + 4095 ) >> V_86 ;
int V_88 = V_87 - V_85 ;
struct V_89 * * V_90 ;
V_90 = F_33 ( V_88 , sizeof( * V_90 ) ) ;
if ( V_90 == NULL ) {
F_2 ( L_8 ) ;
goto V_91;
}
V_20 = 0 ;
F_34 (obj->pages->sgl, &sg_iter, obj->pages->nents, first_page) {
V_90 [ V_20 ++ ] = F_35 ( & V_84 ) ;
if ( V_20 == V_88 )
break;
}
V_37 = F_36 ( V_90 , V_20 , 0 , V_92 ) ;
if ( V_37 == NULL ) {
F_2 ( L_9 ) ;
goto V_91;
}
V_91:
if ( V_90 )
F_37 ( V_90 ) ;
return ( T_1 * ) V_37 ;
}
static T_1 * F_38 ( struct V_79 * V_93 ,
struct V_79 * V_94 ,
T_1 V_95 ,
T_1 V_96 )
{
int V_97 = 0 ;
void * V_98 , * V_99 ;
void * V_100 = NULL ;
int V_21 ;
if ( V_96 > V_93 -> V_101 . V_102 ||
V_96 + V_95 > V_94 -> V_101 . V_102 )
return F_39 ( - V_103 ) ;
if ( F_24 ( V_93 -> V_104 == 0 ) )
return F_39 ( - V_105 ) ;
V_21 = F_40 ( V_94 , & V_97 ) ;
if ( V_21 ) {
F_2 ( L_10 ) ;
return F_39 ( V_21 ) ;
}
V_98 = F_32 ( V_94 , V_95 , V_96 ) ;
if ( ! V_98 ) {
F_2 ( L_11 ) ;
V_21 = - V_47 ;
goto V_106;
}
V_21 = F_41 ( V_93 , true ) ;
if ( V_21 ) {
F_2 ( L_12 ) ;
goto V_107;
}
V_100 = F_32 ( V_93 , 0 , V_96 ) ;
if ( ! V_100 ) {
F_2 ( L_13 ) ;
V_21 = - V_47 ;
goto V_107;
}
V_99 = V_98 + F_42 ( V_95 ) ;
if ( V_97 )
F_43 ( V_99 , V_96 ) ;
memcpy ( V_100 , V_99 , V_96 ) ;
V_107:
F_44 ( V_98 ) ;
V_106:
F_45 ( V_94 ) ;
return V_21 ? F_39 ( V_21 ) : V_100 ;
}
bool F_46 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_68 )
return false ;
if ( ! F_47 ( V_16 -> V_52 ) )
return false ;
return ( V_108 . V_109 == 1 ) ;
}
static bool F_48 ( const struct V_15 * V_16 ,
const struct V_26 * V_27 ,
const T_1 * V_29 , T_1 V_74 ,
const bool V_76 ,
bool * V_110 )
{
if ( V_27 -> V_72 & V_111 ) {
F_2 ( L_14 , * V_29 ) ;
return false ;
}
if ( ( V_27 -> V_72 & V_112 ) && ! V_76 ) {
F_2 ( L_15 ,
* V_29 ) ;
return false ;
}
if ( V_27 -> V_72 & V_113 ) {
const T_1 V_114 = V_27 -> V_77 . V_114 ? V_27 -> V_77 . V_114 : V_74 ;
T_1 V_115 ;
for ( V_115 = V_27 -> V_77 . V_115 ; V_115 < V_74 ;
V_115 += V_114 ) {
const T_1 V_116 = V_29 [ V_115 ] & V_27 -> V_77 . V_31 ;
const struct V_34 * V_77 =
F_31 ( V_16 -> V_40 ,
V_16 -> V_39 ,
V_76 ,
V_116 ) ;
if ( ! V_77 ) {
F_2 ( L_16 ,
V_116 , * V_29 , V_16 -> V_32 ) ;
return false ;
}
if ( V_116 == F_8 ( V_117 ) ) {
if ( V_27 -> V_29 . V_30 == V_118 ) {
F_2 ( L_17 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_49 ( 1 ) )
* V_110 = ( V_29 [ V_115 + 1 ] != 0 ) ;
}
if ( V_77 -> V_31 ) {
if ( V_27 -> V_29 . V_30 == V_118 ) {
F_2 ( L_18 ,
V_116 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_49 ( 1 ) &&
( V_115 + 2 > V_74 ||
( V_29 [ V_115 + 1 ] & V_77 -> V_31 ) != V_77 -> V_30 ) ) {
F_2 ( L_19 ,
V_116 ) ;
return false ;
}
}
}
}
if ( V_27 -> V_72 & V_119 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_120 ; V_20 ++ ) {
T_1 V_121 ;
if ( V_27 -> V_122 [ V_20 ] . V_31 == 0 )
break;
if ( V_27 -> V_122 [ V_20 ] . V_123 != 0 ) {
T_1 V_115 =
V_27 -> V_122 [ V_20 ] . V_124 ;
T_1 V_125 = V_29 [ V_115 ] &
V_27 -> V_122 [ V_20 ] . V_123 ;
if ( V_125 == 0 )
continue;
}
V_121 = V_29 [ V_27 -> V_122 [ V_20 ] . V_115 ] &
V_27 -> V_122 [ V_20 ] . V_31 ;
if ( V_121 != V_27 -> V_122 [ V_20 ] . V_126 ) {
F_2 ( L_20 ,
* V_29 ,
V_27 -> V_122 [ V_20 ] . V_31 ,
V_27 -> V_122 [ V_20 ] . V_126 ,
V_121 , V_16 -> V_32 ) ;
return false ;
}
}
}
return true ;
}
int F_50 ( struct V_15 * V_16 ,
struct V_79 * V_127 ,
struct V_79 * V_128 ,
T_1 V_95 ,
T_1 V_96 ,
bool V_76 )
{
T_1 * V_29 , * V_129 , * V_130 ;
struct V_26 V_71 = { 0 } ;
bool V_110 = false ;
int V_21 = 0 ;
V_129 = F_38 ( V_128 , V_127 ,
V_95 , V_96 ) ;
if ( F_51 ( V_129 ) ) {
F_2 ( L_21 ) ;
return F_52 ( V_129 ) ;
}
V_130 = V_129 + ( V_96 / sizeof( * V_130 ) ) ;
V_29 = V_129 ;
while ( V_29 < V_130 ) {
const struct V_26 * V_27 ;
T_1 V_74 ;
if ( * V_29 == V_131 )
break;
V_27 = F_29 ( V_16 , * V_29 , & V_71 ) ;
if ( ! V_27 ) {
F_2 ( L_22 ,
* V_29 ) ;
V_21 = - V_132 ;
break;
}
if ( V_27 -> V_29 . V_30 == V_133 ) {
V_21 = - V_134 ;
break;
}
if ( V_27 -> V_72 & V_135 )
V_74 = V_27 -> V_74 . V_136 ;
else
V_74 = ( ( * V_29 & V_27 -> V_74 . V_31 ) + V_137 ) ;
if ( ( V_130 - V_29 ) < V_74 ) {
F_2 ( L_23 ,
* V_29 ,
V_74 ,
V_130 - V_29 ) ;
V_21 = - V_132 ;
break;
}
if ( ! F_48 ( V_16 , V_27 , V_29 , V_74 , V_76 ,
& V_110 ) ) {
V_21 = - V_132 ;
break;
}
V_29 += V_74 ;
}
if ( V_110 ) {
F_2 ( L_24 ) ;
V_21 = - V_132 ;
}
if ( V_29 >= V_130 ) {
F_2 ( L_25 ) ;
V_21 = - V_132 ;
}
F_44 ( V_129 ) ;
return V_21 ;
}
int F_53 ( void )
{
return 6 ;
}
