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
static bool F_5 ( const struct V_15 * V_16 ,
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
F_6 ( L_4
L_5 ,
V_16 -> V_32 , V_16 -> V_33 ,
V_20 , V_24 , V_28 , V_23 ) ;
V_21 = false ;
}
V_23 = V_28 ;
}
}
return V_21 ;
}
static bool F_7 ( const struct V_15 * V_16 ,
const struct V_34 * V_35 ,
int V_36 )
{
int V_20 ;
T_1 V_23 = 0 ;
bool V_21 = true ;
for ( V_20 = 0 ; V_20 < V_36 ; V_20 ++ ) {
T_1 V_28 = F_8 ( V_35 [ V_20 ] . V_37 ) ;
if ( V_28 < V_23 ) {
F_6 ( L_6
L_7 ,
V_16 -> V_32 , V_16 -> V_33 ,
V_20 , V_28 , V_23 ) ;
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
if ( ! F_7 ( V_16 , V_22 -> V_41 , V_22 -> V_42 ) )
return false ;
}
return true ;
}
static inline T_1 F_10 ( T_1 V_43 )
{
T_1 V_44 ;
switch ( V_43 >> V_4 ) {
default:
case V_8 :
V_44 = V_45 ;
break;
case V_9 :
V_44 = V_46 ;
break;
case V_14 :
V_44 = V_47 ;
break;
}
return V_43 >> V_44 ;
}
static int F_11 ( struct V_15 * V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 , V_24 ;
F_12 ( V_16 -> V_48 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
const struct V_17 * V_22 = & V_18 [ V_20 ] ;
for ( V_24 = 0 ; V_24 < V_22 -> V_25 ; V_24 ++ ) {
const struct V_26 * V_27 =
& V_22 -> V_22 [ V_24 ] ;
struct V_49 * V_50 =
F_13 ( sizeof( * V_50 ) , V_51 ) ;
if ( ! V_50 )
return - V_52 ;
V_50 -> V_27 = V_27 ;
F_14 ( V_16 -> V_48 , & V_50 -> V_53 ,
F_10 ( V_27 -> V_29 . V_30 ) ) ;
}
}
return 0 ;
}
static void F_15 ( struct V_15 * V_16 )
{
struct V_54 * V_55 ;
struct V_49 * V_50 ;
int V_20 ;
F_16 (engine->cmd_hash, i, tmp, desc_node, node) {
F_17 ( & V_50 -> V_53 ) ;
F_18 ( V_50 ) ;
}
}
void F_19 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
int V_19 ;
int V_21 ;
if ( ! F_20 ( V_16 -> V_56 ) )
return;
switch ( V_16 -> V_33 ) {
case V_57 :
if ( F_21 ( V_16 -> V_56 ) ) {
V_18 = V_58 ;
V_19 =
F_22 ( V_58 ) ;
} else {
V_18 = V_59 ;
V_19 = F_22 ( V_59 ) ;
}
if ( F_21 ( V_16 -> V_56 ) ) {
V_16 -> V_40 = V_60 ;
V_16 -> V_39 = F_22 ( V_60 ) ;
} else {
V_16 -> V_40 = V_61 ;
V_16 -> V_39 = F_22 ( V_61 ) ;
}
V_16 -> V_62 = F_1 ;
break;
case V_63 :
V_18 = V_64 ;
V_19 = F_22 ( V_64 ) ;
V_16 -> V_62 = F_3 ;
break;
case V_65 :
if ( F_21 ( V_16 -> V_56 ) ) {
V_18 = V_66 ;
V_19 = F_22 ( V_66 ) ;
} else {
V_18 = V_67 ;
V_19 = F_22 ( V_67 ) ;
}
if ( F_21 ( V_16 -> V_56 ) ) {
V_16 -> V_40 = V_68 ;
V_16 -> V_39 = F_22 ( V_68 ) ;
} else {
V_16 -> V_40 = V_69 ;
V_16 -> V_39 = F_22 ( V_69 ) ;
}
V_16 -> V_62 = F_4 ;
break;
case V_70 :
V_18 = V_71 ;
V_19 = F_22 ( V_71 ) ;
V_16 -> V_62 = F_3 ;
break;
default:
F_23 ( V_16 -> V_33 ) ;
return;
}
if ( ! F_5 ( V_16 , V_18 , V_19 ) ) {
F_6 ( L_8 ,
V_16 -> V_32 ) ;
return;
}
if ( ! F_9 ( V_16 ) ) {
F_6 ( L_9 , V_16 -> V_32 ) ;
return;
}
V_21 = F_11 ( V_16 , V_18 , V_19 ) ;
if ( V_21 ) {
F_6 ( L_10 , V_16 -> V_32 ) ;
F_15 ( V_16 ) ;
return;
}
V_16 -> V_72 = true ;
}
void F_24 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_72 )
return;
F_15 ( V_16 ) ;
}
static const struct V_26 *
F_25 ( struct V_15 * V_16 ,
T_1 V_1 )
{
struct V_49 * V_50 ;
F_26 (engine->cmd_hash, desc_node, node,
cmd_header_key(cmd_header)) {
const struct V_26 * V_27 = V_50 -> V_27 ;
if ( ( ( V_1 ^ V_27 -> V_29 . V_30 ) & V_27 -> V_29 . V_31 ) == 0 )
return V_27 ;
}
return NULL ;
}
static const struct V_26 *
F_27 ( struct V_15 * V_16 ,
T_1 V_1 ,
const struct V_26 * V_27 ,
struct V_26 * V_73 )
{
T_1 V_31 ;
if ( ( ( V_1 ^ V_27 -> V_29 . V_30 ) & V_27 -> V_29 . V_31 ) == 0 )
return V_27 ;
V_27 = F_25 ( V_16 , V_1 ) ;
if ( V_27 )
return V_27 ;
V_31 = V_16 -> V_62 ( V_1 ) ;
if ( ! V_31 )
return NULL ;
V_73 -> V_29 . V_30 = V_1 ;
V_73 -> V_29 . V_31 = ~ 0u << V_74 ;
V_73 -> V_75 . V_31 = V_31 ;
V_73 -> V_76 = V_77 ;
return V_73 ;
}
static const struct V_34 *
F_28 ( const struct V_34 * V_22 , int V_25 , T_1 V_37 )
{
int V_78 = 0 , V_79 = V_25 ;
while ( V_78 < V_79 ) {
int V_80 = V_78 + ( V_79 - V_78 ) / 2 ;
int V_21 = V_37 - F_8 ( V_22 [ V_80 ] . V_37 ) ;
if ( V_21 < 0 )
V_79 = V_80 ;
else if ( V_21 > 0 )
V_78 = V_80 + 1 ;
else
return & V_22 [ V_80 ] ;
}
return NULL ;
}
static const struct V_34 *
F_29 ( const struct V_15 * V_16 , bool V_81 , T_1 V_37 )
{
const struct V_38 * V_22 = V_16 -> V_40 ;
int V_25 = V_16 -> V_39 ;
do {
if ( ! V_22 -> V_82 || V_81 ) {
const struct V_34 * V_83 ;
V_83 = F_28 ( V_22 -> V_41 , V_22 -> V_42 , V_37 ) ;
if ( V_83 != NULL )
return V_83 ;
}
} while ( V_22 ++ , -- V_25 );
return NULL ;
}
static T_1 * F_30 ( struct V_84 * V_85 ,
struct V_84 * V_86 ,
T_1 V_87 ,
T_1 V_88 ,
bool * V_89 )
{
unsigned int V_90 ;
unsigned int V_91 ;
void * V_92 , * V_93 ;
int V_21 ;
V_21 = F_31 ( V_86 , & V_90 ) ;
if ( V_21 )
return F_32 ( V_21 ) ;
V_21 = F_33 ( V_85 , & V_91 ) ;
if ( V_21 ) {
V_92 = F_32 ( V_21 ) ;
goto V_94;
}
V_92 = F_34 ( V_85 , V_95 ) ;
if ( F_35 ( V_92 ) )
goto V_96;
V_93 = F_32 ( - V_97 ) ;
if ( V_90 &&
F_36 ( ( void * ) ( V_98 ) V_87 , NULL , 0 ) ) {
V_93 = F_34 ( V_86 , V_99 ) ;
if ( ! F_35 ( V_93 ) ) {
F_36 ( V_92 ,
V_93 + V_87 ,
F_37 ( V_88 , 16 ) ) ;
F_38 ( V_86 ) ;
}
}
if ( F_35 ( V_93 ) ) {
void * V_100 ;
int V_101 , V_102 ;
V_101 = F_39 ( V_87 ) ;
if ( V_91 & V_103 )
V_88 = F_40 ( V_88 ,
V_104 . V_105 ) ;
V_100 = V_92 ;
for ( V_102 = V_87 >> V_106 ; V_88 ; V_102 ++ ) {
int V_107 = F_41 ( int , V_88 , V_108 - V_101 ) ;
V_93 = F_42 ( F_43 ( V_86 , V_102 ) ) ;
if ( V_90 )
F_44 ( V_93 + V_101 , V_107 ) ;
memcpy ( V_100 , V_93 + V_101 , V_107 ) ;
F_45 ( V_93 ) ;
V_100 += V_107 ;
V_88 -= V_107 ;
V_101 = 0 ;
}
}
* V_89 = V_91 & V_109 ;
V_96:
F_46 ( V_85 ) ;
V_94:
F_46 ( V_86 ) ;
return V_92 ;
}
bool F_47 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_72 )
return false ;
if ( ! F_48 ( V_16 -> V_56 ) )
return false ;
return ( V_56 . V_110 == 1 ) ;
}
static bool F_49 ( const struct V_15 * V_16 ,
const struct V_26 * V_27 ,
const T_1 * V_29 , T_1 V_75 ,
const bool V_81 ,
bool * V_111 )
{
if ( V_27 -> V_76 & V_77 )
return true ;
if ( V_27 -> V_76 & V_112 ) {
F_2 ( L_11 , * V_29 ) ;
return false ;
}
if ( ( V_27 -> V_76 & V_113 ) && ! V_81 ) {
F_2 ( L_12 ,
* V_29 ) ;
return false ;
}
if ( V_27 -> V_76 & V_114 ) {
const T_1 V_115 = V_27 -> V_83 . V_115 ? V_27 -> V_83 . V_115 : V_75 ;
T_1 V_101 ;
for ( V_101 = V_27 -> V_83 . V_101 ; V_101 < V_75 ;
V_101 += V_115 ) {
const T_1 V_116 = V_29 [ V_101 ] & V_27 -> V_83 . V_31 ;
const struct V_34 * V_83 =
F_29 ( V_16 , V_81 , V_116 ) ;
if ( ! V_83 ) {
F_2 ( L_13 ,
V_116 , * V_29 , V_16 -> V_117 ) ;
return false ;
}
if ( V_116 == F_8 ( V_118 ) ) {
if ( V_27 -> V_29 . V_30 == V_119 ) {
F_2 ( L_14 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == V_120 ) {
F_2 ( L_15 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_50 ( 1 ) )
* V_111 = ( V_29 [ V_101 + 1 ] != 0 ) ;
}
if ( V_83 -> V_31 ) {
if ( V_27 -> V_29 . V_30 == V_119 ) {
F_2 ( L_16 ,
V_116 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == V_120 ) {
F_2 ( L_17 ,
V_116 ) ;
return false ;
}
if ( V_27 -> V_29 . V_30 == F_50 ( 1 ) &&
( V_101 + 2 > V_75 ||
( V_29 [ V_101 + 1 ] & V_83 -> V_31 ) != V_83 -> V_30 ) ) {
F_2 ( L_18 ,
V_116 ) ;
return false ;
}
}
}
}
if ( V_27 -> V_76 & V_121 ) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_122 ; V_20 ++ ) {
T_1 V_123 ;
if ( V_27 -> V_124 [ V_20 ] . V_31 == 0 )
break;
if ( V_27 -> V_124 [ V_20 ] . V_125 != 0 ) {
T_1 V_101 =
V_27 -> V_124 [ V_20 ] . V_126 ;
T_1 V_127 = V_29 [ V_101 ] &
V_27 -> V_124 [ V_20 ] . V_125 ;
if ( V_127 == 0 )
continue;
}
V_123 = V_29 [ V_27 -> V_124 [ V_20 ] . V_101 ] &
V_27 -> V_124 [ V_20 ] . V_31 ;
if ( V_123 != V_27 -> V_124 [ V_20 ] . V_128 ) {
F_2 ( L_19 ,
* V_29 ,
V_27 -> V_124 [ V_20 ] . V_31 ,
V_27 -> V_124 [ V_20 ] . V_128 ,
V_123 , V_16 -> V_117 ) ;
return false ;
}
}
}
return true ;
}
int F_51 ( struct V_15 * V_16 ,
struct V_84 * V_129 ,
struct V_84 * V_130 ,
T_1 V_87 ,
T_1 V_88 ,
bool V_81 )
{
T_1 * V_29 , * V_131 ;
struct V_26 V_73 = V_132 ;
const struct V_26 * V_27 = & V_73 ;
bool V_111 = false ;
bool V_89 = false ;
int V_21 = 0 ;
V_29 = F_30 ( V_130 , V_129 ,
V_87 , V_88 ,
& V_89 ) ;
if ( F_35 ( V_29 ) ) {
F_2 ( L_20 ) ;
return F_52 ( V_29 ) ;
}
V_131 = V_29 + ( V_88 / sizeof( * V_131 ) ) ;
while ( V_29 < V_131 ) {
T_1 V_75 ;
if ( * V_29 == V_133 )
break;
V_27 = F_27 ( V_16 , * V_29 , V_27 , & V_73 ) ;
if ( ! V_27 ) {
F_2 ( L_21 ,
* V_29 ) ;
V_21 = - V_134 ;
break;
}
if ( V_27 -> V_29 . V_30 == V_135 ) {
V_21 = - V_136 ;
break;
}
if ( V_27 -> V_76 & V_137 )
V_75 = V_27 -> V_75 . V_138 ;
else
V_75 = ( ( * V_29 & V_27 -> V_75 . V_31 ) + V_139 ) ;
if ( ( V_131 - V_29 ) < V_75 ) {
F_2 ( L_22 ,
* V_29 ,
V_75 ,
V_131 - V_29 ) ;
V_21 = - V_134 ;
break;
}
if ( ! F_49 ( V_16 , V_27 , V_29 , V_75 , V_81 ,
& V_111 ) ) {
V_21 = - V_134 ;
break;
}
V_29 += V_75 ;
}
if ( V_111 ) {
F_2 ( L_23 ) ;
V_21 = - V_134 ;
}
if ( V_29 >= V_131 ) {
F_2 ( L_24 ) ;
V_21 = - V_134 ;
}
if ( V_21 == 0 && V_89 )
F_44 ( V_130 -> V_140 . V_141 , V_88 ) ;
F_38 ( V_130 ) ;
return V_21 ;
}
int F_53 ( struct V_142 * V_143 )
{
struct V_15 * V_16 ;
enum V_144 V_33 ;
bool V_145 = false ;
F_54 (engine, dev_priv, id) {
if ( F_47 ( V_16 ) ) {
V_145 = true ;
break;
}
}
if ( ! V_145 )
return 0 ;
return 7 ;
}
