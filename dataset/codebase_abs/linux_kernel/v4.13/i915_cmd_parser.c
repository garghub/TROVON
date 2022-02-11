static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = V_1 >> V_3 ;
T_1 V_4 =
( V_1 & V_5 ) >> V_6 ;
if ( V_2 == V_7 )
return 0x3F ;
else if ( V_2 == V_8 ) {
if ( V_4 == V_9 )
return 0xFFFF ;
else
return 0xFF ;
}
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
static T_1 F_3 ( T_1 V_1 )
{
T_1 V_2 = V_1 >> V_3 ;
T_1 V_4 =
( V_1 & V_5 ) >> V_6 ;
T_1 V_10 = ( V_1 & V_11 ) >> V_12 ;
if ( V_2 == V_7 )
return 0x3F ;
else if ( V_2 == V_8 ) {
if ( V_4 == V_9 ) {
if ( V_10 == 6 )
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
T_1 V_2 = V_1 >> V_3 ;
if ( V_2 == V_7 )
return 0x3F ;
else if ( V_2 == V_13 )
return 0xFF ;
F_2 ( L_3 , V_1 ) ;
return 0 ;
}
static bool F_5 ( const struct V_14 * V_15 ,
const struct V_16 * V_17 ,
int V_18 )
{
int V_19 ;
bool V_20 = true ;
if ( ! V_17 || V_18 == 0 )
return true ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
const struct V_16 * V_21 = & V_17 [ V_19 ] ;
T_1 V_22 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_21 -> V_24 ; V_23 ++ ) {
const struct V_25 * V_26 =
& V_21 -> V_21 [ V_23 ] ;
T_1 V_27 = V_26 -> V_28 . V_29 & V_26 -> V_28 . V_30 ;
if ( V_27 < V_22 ) {
F_6 ( L_4
L_5 ,
V_15 -> V_31 , V_15 -> V_32 ,
V_19 , V_23 , V_27 , V_22 ) ;
V_20 = false ;
}
V_22 = V_27 ;
}
}
return V_20 ;
}
static bool F_7 ( const struct V_14 * V_15 ,
const struct V_33 * V_34 ,
int V_35 )
{
int V_19 ;
T_1 V_22 = 0 ;
bool V_20 = true ;
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ ) {
T_1 V_27 = F_8 ( V_34 [ V_19 ] . V_36 ) ;
if ( V_27 < V_22 ) {
F_6 ( L_6
L_7 ,
V_15 -> V_31 , V_15 -> V_32 ,
V_19 , V_27 , V_22 ) ;
V_20 = false ;
}
V_22 = V_27 ;
}
return V_20 ;
}
static bool F_9 ( struct V_14 * V_15 )
{
int V_19 ;
const struct V_37 * V_21 ;
for ( V_19 = 0 ; V_19 < V_15 -> V_38 ; V_19 ++ ) {
V_21 = & V_15 -> V_39 [ V_19 ] ;
if ( ! F_7 ( V_15 , V_21 -> V_40 , V_21 -> V_41 ) )
return false ;
}
return true ;
}
static inline T_1 F_10 ( T_1 V_42 )
{
T_1 V_43 ;
switch ( V_42 >> V_3 ) {
default:
case V_7 :
V_43 = V_44 ;
break;
case V_8 :
V_43 = V_45 ;
break;
case V_13 :
V_43 = V_46 ;
break;
}
return V_42 >> V_43 ;
}
static int F_11 ( struct V_14 * V_15 ,
const struct V_16 * V_17 ,
int V_18 )
{
int V_19 , V_23 ;
F_12 ( V_15 -> V_47 ) ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
const struct V_16 * V_21 = & V_17 [ V_19 ] ;
for ( V_23 = 0 ; V_23 < V_21 -> V_24 ; V_23 ++ ) {
const struct V_25 * V_26 =
& V_21 -> V_21 [ V_23 ] ;
struct V_48 * V_49 =
F_13 ( sizeof( * V_49 ) , V_50 ) ;
if ( ! V_49 )
return - V_51 ;
V_49 -> V_26 = V_26 ;
F_14 ( V_15 -> V_47 , & V_49 -> V_52 ,
F_10 ( V_26 -> V_28 . V_29 ) ) ;
}
}
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_53 * V_54 ;
struct V_48 * V_49 ;
int V_19 ;
F_16 (engine->cmd_hash, i, tmp, desc_node, node) {
F_17 ( & V_49 -> V_52 ) ;
F_18 ( V_49 ) ;
}
}
void F_19 ( struct V_14 * V_15 )
{
const struct V_16 * V_17 ;
int V_18 ;
int V_20 ;
if ( ! F_20 ( V_15 -> V_55 ) )
return;
switch ( V_15 -> V_32 ) {
case V_56 :
if ( F_21 ( V_15 -> V_55 ) ) {
V_17 = V_57 ;
V_18 =
F_22 ( V_57 ) ;
} else {
V_17 = V_58 ;
V_18 = F_22 ( V_58 ) ;
}
if ( F_21 ( V_15 -> V_55 ) ) {
V_15 -> V_39 = V_59 ;
V_15 -> V_38 = F_22 ( V_59 ) ;
} else {
V_15 -> V_39 = V_60 ;
V_15 -> V_38 = F_22 ( V_60 ) ;
}
V_15 -> V_61 = F_1 ;
break;
case V_62 :
V_17 = V_63 ;
V_18 = F_22 ( V_63 ) ;
V_15 -> V_61 = F_3 ;
break;
case V_64 :
if ( F_21 ( V_15 -> V_55 ) ) {
V_17 = V_65 ;
V_18 = F_22 ( V_65 ) ;
} else {
V_17 = V_66 ;
V_18 = F_22 ( V_66 ) ;
}
if ( F_21 ( V_15 -> V_55 ) ) {
V_15 -> V_39 = V_67 ;
V_15 -> V_38 = F_22 ( V_67 ) ;
} else {
V_15 -> V_39 = V_68 ;
V_15 -> V_38 = F_22 ( V_68 ) ;
}
V_15 -> V_61 = F_4 ;
break;
case V_69 :
V_17 = V_70 ;
V_18 = F_22 ( V_70 ) ;
V_15 -> V_61 = F_3 ;
break;
default:
F_23 ( V_15 -> V_32 ) ;
return;
}
if ( ! F_5 ( V_15 , V_17 , V_18 ) ) {
F_6 ( L_8 ,
V_15 -> V_31 ) ;
return;
}
if ( ! F_9 ( V_15 ) ) {
F_6 ( L_9 , V_15 -> V_31 ) ;
return;
}
V_20 = F_11 ( V_15 , V_17 , V_18 ) ;
if ( V_20 ) {
F_6 ( L_10 , V_15 -> V_31 ) ;
F_15 ( V_15 ) ;
return;
}
V_15 -> V_71 = true ;
}
void F_24 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_71 )
return;
F_15 ( V_15 ) ;
}
static const struct V_25 *
F_25 ( struct V_14 * V_15 ,
T_1 V_1 )
{
struct V_48 * V_49 ;
F_26 (engine->cmd_hash, desc_node, node,
cmd_header_key(cmd_header)) {
const struct V_25 * V_26 = V_49 -> V_26 ;
if ( ( ( V_1 ^ V_26 -> V_28 . V_29 ) & V_26 -> V_28 . V_30 ) == 0 )
return V_26 ;
}
return NULL ;
}
static const struct V_25 *
F_27 ( struct V_14 * V_15 ,
T_1 V_1 ,
const struct V_25 * V_26 ,
struct V_25 * V_72 )
{
T_1 V_30 ;
if ( ( ( V_1 ^ V_26 -> V_28 . V_29 ) & V_26 -> V_28 . V_30 ) == 0 )
return V_26 ;
V_26 = F_25 ( V_15 , V_1 ) ;
if ( V_26 )
return V_26 ;
V_30 = V_15 -> V_61 ( V_1 ) ;
if ( ! V_30 )
return NULL ;
V_72 -> V_28 . V_29 = V_1 ;
V_72 -> V_28 . V_30 = ~ 0u << V_73 ;
V_72 -> V_74 . V_30 = V_30 ;
V_72 -> V_75 = V_76 ;
return V_72 ;
}
static const struct V_33 *
F_28 ( const struct V_33 * V_21 , int V_24 , T_1 V_36 )
{
int V_77 = 0 , V_78 = V_24 ;
while ( V_77 < V_78 ) {
int V_79 = V_77 + ( V_78 - V_77 ) / 2 ;
int V_20 = V_36 - F_8 ( V_21 [ V_79 ] . V_36 ) ;
if ( V_20 < 0 )
V_78 = V_79 ;
else if ( V_20 > 0 )
V_77 = V_79 + 1 ;
else
return & V_21 [ V_79 ] ;
}
return NULL ;
}
static const struct V_33 *
F_29 ( const struct V_14 * V_15 , bool V_80 , T_1 V_36 )
{
const struct V_37 * V_21 = V_15 -> V_39 ;
int V_24 = V_15 -> V_38 ;
do {
if ( ! V_21 -> V_81 || V_80 ) {
const struct V_33 * V_82 ;
V_82 = F_28 ( V_21 -> V_40 , V_21 -> V_41 , V_36 ) ;
if ( V_82 != NULL )
return V_82 ;
}
} while ( V_21 ++ , -- V_24 );
return NULL ;
}
static T_1 * F_30 ( struct V_83 * V_84 ,
struct V_83 * V_85 ,
T_1 V_86 ,
T_1 V_87 ,
bool * V_88 )
{
unsigned int V_89 ;
unsigned int V_90 ;
void * V_91 , * V_92 ;
int V_20 ;
V_20 = F_31 ( V_85 , & V_89 ) ;
if ( V_20 )
return F_32 ( V_20 ) ;
V_20 = F_33 ( V_84 , & V_90 ) ;
if ( V_20 ) {
V_91 = F_32 ( V_20 ) ;
goto V_93;
}
V_91 = F_34 ( V_84 , V_94 ) ;
if ( F_35 ( V_91 ) )
goto V_95;
V_92 = F_32 ( - V_96 ) ;
if ( V_89 &&
F_36 ( NULL , V_86 , 0 ) ) {
V_92 = F_34 ( V_85 , V_97 ) ;
if ( ! F_35 ( V_92 ) ) {
F_37 ( V_91 ,
V_92 + V_86 ,
F_38 ( V_87 , 16 ) ) ;
F_39 ( V_85 ) ;
}
}
if ( F_35 ( V_92 ) ) {
void * V_98 ;
int V_99 , V_100 ;
V_99 = F_40 ( V_86 ) ;
if ( V_90 & V_101 )
V_87 = F_41 ( V_87 ,
V_102 . V_103 ) ;
V_98 = V_91 ;
for ( V_100 = V_86 >> V_104 ; V_87 ; V_100 ++ ) {
int V_105 = F_42 ( int , V_87 , V_106 - V_99 ) ;
V_92 = F_43 ( F_44 ( V_85 , V_100 ) ) ;
if ( V_89 )
F_45 ( V_92 + V_99 , V_105 ) ;
memcpy ( V_98 , V_92 + V_99 , V_105 ) ;
F_46 ( V_92 ) ;
V_98 += V_105 ;
V_87 -= V_105 ;
V_99 = 0 ;
}
}
* V_88 = V_90 & V_107 ;
V_95:
F_47 ( V_84 ) ;
V_93:
F_47 ( V_85 ) ;
return V_91 ;
}
static bool F_48 ( const struct V_14 * V_15 ,
const struct V_25 * V_26 ,
const T_1 * V_28 , T_1 V_74 ,
const bool V_80 )
{
if ( V_26 -> V_75 & V_76 )
return true ;
if ( V_26 -> V_75 & V_108 ) {
F_2 ( L_11 , * V_28 ) ;
return false ;
}
if ( ( V_26 -> V_75 & V_109 ) && ! V_80 ) {
F_2 ( L_12 ,
* V_28 ) ;
return false ;
}
if ( V_26 -> V_75 & V_110 ) {
const T_1 V_111 = V_26 -> V_82 . V_111 ? V_26 -> V_82 . V_111 : V_74 ;
T_1 V_99 ;
for ( V_99 = V_26 -> V_82 . V_99 ; V_99 < V_74 ;
V_99 += V_111 ) {
const T_1 V_112 = V_28 [ V_99 ] & V_26 -> V_82 . V_30 ;
const struct V_33 * V_82 =
F_29 ( V_15 , V_80 , V_112 ) ;
if ( ! V_82 ) {
F_2 ( L_13 ,
V_112 , * V_28 , V_15 -> V_31 ) ;
return false ;
}
if ( V_82 -> V_30 ) {
if ( V_26 -> V_28 . V_29 == V_113 ) {
F_2 ( L_14 ,
V_112 ) ;
return false ;
}
if ( V_26 -> V_28 . V_29 == V_114 ) {
F_2 ( L_15 ,
V_112 ) ;
return false ;
}
if ( V_26 -> V_28 . V_29 == F_49 ( 1 ) &&
( V_99 + 2 > V_74 ||
( V_28 [ V_99 + 1 ] & V_82 -> V_30 ) != V_82 -> V_29 ) ) {
F_2 ( L_16 ,
V_112 ) ;
return false ;
}
}
}
}
if ( V_26 -> V_75 & V_115 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_116 ; V_19 ++ ) {
T_1 V_117 ;
if ( V_26 -> V_118 [ V_19 ] . V_30 == 0 )
break;
if ( V_26 -> V_118 [ V_19 ] . V_119 != 0 ) {
T_1 V_99 =
V_26 -> V_118 [ V_19 ] . V_120 ;
T_1 V_121 = V_28 [ V_99 ] &
V_26 -> V_118 [ V_19 ] . V_119 ;
if ( V_121 == 0 )
continue;
}
V_117 = V_28 [ V_26 -> V_118 [ V_19 ] . V_99 ] &
V_26 -> V_118 [ V_19 ] . V_30 ;
if ( V_117 != V_26 -> V_118 [ V_19 ] . V_122 ) {
F_2 ( L_17 ,
* V_28 ,
V_26 -> V_118 [ V_19 ] . V_30 ,
V_26 -> V_118 [ V_19 ] . V_122 ,
V_117 , V_15 -> V_31 ) ;
return false ;
}
}
}
return true ;
}
int F_50 ( struct V_14 * V_15 ,
struct V_83 * V_123 ,
struct V_83 * V_124 ,
T_1 V_86 ,
T_1 V_87 ,
bool V_80 )
{
T_1 * V_28 , * V_125 ;
struct V_25 V_72 = V_126 ;
const struct V_25 * V_26 = & V_72 ;
bool V_88 = false ;
int V_20 = 0 ;
V_28 = F_30 ( V_124 , V_123 ,
V_86 , V_87 ,
& V_88 ) ;
if ( F_35 ( V_28 ) ) {
F_2 ( L_18 ) ;
return F_51 ( V_28 ) ;
}
V_125 = V_28 + ( V_87 / sizeof( * V_125 ) ) ;
do {
T_1 V_74 ;
if ( * V_28 == V_127 ) {
if ( V_88 ) {
void * V_98 = F_52 ( V_124 -> V_128 . V_129 ) ;
F_45 ( V_98 ,
( void * ) ( V_28 + 1 ) - V_98 ) ;
}
break;
}
V_26 = F_27 ( V_15 , * V_28 , V_26 , & V_72 ) ;
if ( ! V_26 ) {
F_2 ( L_19 ,
* V_28 ) ;
V_20 = - V_130 ;
break;
}
if ( V_26 -> V_28 . V_29 == V_131 ) {
V_20 = - V_132 ;
break;
}
if ( V_26 -> V_75 & V_133 )
V_74 = V_26 -> V_74 . V_134 ;
else
V_74 = ( ( * V_28 & V_26 -> V_74 . V_30 ) + V_135 ) ;
if ( ( V_125 - V_28 ) < V_74 ) {
F_2 ( L_20 ,
* V_28 ,
V_74 ,
V_125 - V_28 ) ;
V_20 = - V_130 ;
break;
}
if ( ! F_48 ( V_15 , V_26 , V_28 , V_74 , V_80 ) ) {
V_20 = - V_132 ;
break;
}
V_28 += V_74 ;
if ( V_28 >= V_125 ) {
F_2 ( L_21 ) ;
V_20 = - V_130 ;
break;
}
} while ( 1 );
F_39 ( V_124 ) ;
return V_20 ;
}
int F_53 ( struct V_136 * V_137 )
{
struct V_14 * V_15 ;
enum V_138 V_32 ;
bool V_139 = false ;
F_54 (engine, dev_priv, id) {
if ( V_15 -> V_71 ) {
V_139 = true ;
break;
}
}
if ( ! V_139 )
return 0 ;
return 9 ;
}
