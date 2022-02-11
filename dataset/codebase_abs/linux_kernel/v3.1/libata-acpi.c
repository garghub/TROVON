static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == & V_4 ) ;
}
static void F_2 ( struct V_5 * V_2 )
{
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
void F_4 ( struct V_7 * V_8 )
{
F_5 ( ! ( V_8 -> V_9 & V_10 ) ) ;
if ( ! F_6 ( V_8 ) ) {
T_1 V_11 = F_7 ( V_8 -> V_12 , V_13 ) ;
V_8 -> V_14 . V_1 -> V_15 =
F_8 ( V_8 -> V_16 -> V_15 , V_11 ) ;
} else {
struct V_17 * V_14 ;
V_8 -> V_14 . V_1 -> V_15 = NULL ;
F_9 (link, ap, EDGE) {
T_1 V_11 = F_7 ( V_8 -> V_12 , V_14 -> V_18 ) ;
V_14 -> V_1 -> V_15 =
F_8 ( V_8 -> V_16 -> V_15 , V_11 ) ;
}
}
}
static void F_10 ( struct V_7 * V_8 )
{
int V_19 , V_20 ;
V_8 -> V_15 = F_8 ( V_8 -> V_16 -> V_15 , V_8 -> V_12 ) ;
if ( ! V_8 -> V_15 )
return;
V_19 = 1 ;
if ( V_8 -> V_9 & V_21 )
V_19 ++ ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
struct V_5 * V_2 = & V_8 -> V_14 . V_1 [ V_20 ] ;
V_2 -> V_15 = F_8 ( V_8 -> V_15 , V_20 ) ;
}
if ( F_11 ( V_8 , & V_8 -> V_22 ) == 0 )
V_8 -> V_23 |= V_24 ;
}
static void F_12 ( struct V_7 * V_8 , struct V_5 * V_2 )
{
if ( V_2 )
V_2 -> V_9 |= V_25 ;
else {
struct V_17 * V_26 ;
struct V_5 * V_27 ;
F_9 (tlink, ap, EDGE)
F_13 (tdev, tlink, ALL)
V_27 -> V_9 |= V_25 ;
}
F_14 ( V_8 ) ;
}
static void F_15 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_2 V_28 )
{
struct V_29 * V_30 = & V_8 -> V_14 . V_31 ;
int V_32 = 0 ;
unsigned long V_9 ;
F_16 ( V_8 -> V_33 , V_9 ) ;
switch ( V_28 ) {
case V_34 :
case V_35 :
F_17 ( V_30 , L_1 ) ;
F_18 ( V_30 ) ;
F_19 ( V_8 ) ;
break;
case V_36 :
F_17 ( V_30 , L_1 ) ;
F_12 ( V_8 , V_2 ) ;
V_32 = 1 ;
break;
}
F_20 ( V_8 -> V_33 , V_9 ) ;
if ( V_32 )
F_21 ( V_8 ) ;
}
static void F_22 ( V_15 V_37 , T_2 V_28 , void * V_38 )
{
struct V_5 * V_2 = V_38 ;
F_15 ( V_2 -> V_14 -> V_8 , V_2 , V_28 ) ;
}
static void F_23 ( V_15 V_37 , T_2 V_28 , void * V_38 )
{
struct V_7 * V_8 = V_38 ;
F_15 ( V_8 , NULL , V_28 ) ;
}
static void F_24 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_2 V_28 )
{
struct V_39 * V_40 = NULL ;
char V_41 [ 20 ] ;
char * V_42 [] = { V_41 , NULL } ;
if ( V_2 ) {
if ( V_2 -> V_43 )
V_40 = & V_2 -> V_43 -> V_44 . V_40 ;
} else
V_40 = & V_8 -> V_2 -> V_40 ;
if ( V_40 ) {
snprintf ( V_41 , 20 , L_2 , V_28 ) ;
F_25 ( V_40 , V_45 , V_42 ) ;
}
}
static void F_26 ( V_15 V_37 , T_2 V_28 , void * V_38 )
{
F_24 ( V_38 , NULL , V_28 ) ;
}
static void F_27 ( V_15 V_37 , T_2 V_28 , void * V_38 )
{
struct V_5 * V_2 = V_38 ;
F_24 ( V_2 -> V_14 -> V_8 , V_2 , V_28 ) ;
}
void F_28 ( struct V_46 * V_16 )
{
int V_20 , V_47 ;
if ( ! F_1 ( V_16 -> V_2 ) || V_48 )
return;
V_16 -> V_15 = F_29 ( V_16 -> V_2 ) ;
if ( ! V_16 -> V_15 )
return;
for ( V_20 = 0 ; V_20 < V_16 -> V_49 ; V_20 ++ ) {
struct V_7 * V_8 = V_16 -> V_50 [ V_20 ] ;
if ( V_16 -> V_50 [ 0 ] -> V_9 & V_10 )
F_4 ( V_8 ) ;
else
F_10 ( V_8 ) ;
if ( V_8 -> V_15 ) {
F_30 ( V_8 -> V_15 ,
& V_51 , V_8 ) ;
}
for ( V_47 = 0 ; V_47 < F_31 ( & V_8 -> V_14 ) ; V_47 ++ ) {
struct V_5 * V_2 = & V_8 -> V_14 . V_1 [ V_47 ] ;
if ( V_2 -> V_15 ) {
F_30 ( V_2 -> V_15 ,
& V_52 , V_2 ) ;
}
}
}
}
void F_32 ( struct V_46 * V_16 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_16 -> V_49 ; V_20 ++ ) {
struct V_7 * V_8 = V_16 -> V_50 [ V_20 ] ;
const struct F_11 * V_53 = F_33 ( V_8 ) ;
if ( V_8 -> V_15 && V_53 )
F_34 ( V_8 , V_53 ) ;
}
}
int F_11 ( struct V_7 * V_8 , struct F_11 * V_53 )
{
struct V_54 V_55 = { . V_56 = V_57 } ;
union V_58 * V_59 ;
T_3 V_60 ;
int V_61 = 0 ;
V_60 = F_35 ( V_8 -> V_15 , L_3 , NULL , & V_55 ) ;
V_61 = - V_62 ;
if ( V_60 == V_63 )
goto V_64;
V_61 = - V_65 ;
if ( F_36 ( V_60 ) ) {
F_37 ( V_8 , L_4 ,
V_60 ) ;
goto V_64;
}
V_59 = V_55 . V_66 ;
if ( V_59 -> type != V_67 ) {
F_38 ( V_8 , L_5 ,
V_59 -> type ) ;
goto V_64;
}
if ( V_59 -> V_68 . V_56 != sizeof( struct F_11 ) ) {
F_37 ( V_8 , L_6 ,
V_59 -> V_68 . V_56 ) ;
goto V_64;
}
memcpy ( V_53 , V_59 -> V_68 . V_66 , sizeof( struct F_11 ) ) ;
V_61 = 0 ;
V_64:
F_3 ( V_55 . V_66 ) ;
return V_61 ;
}
int F_34 ( struct V_7 * V_8 , const struct F_11 * V_69 )
{
T_3 V_60 ;
struct F_11 V_70 = * V_69 ;
struct V_71 V_72 ;
union V_58 V_73 [ 3 ] ;
V_73 [ 0 ] . type = V_67 ;
V_73 [ 0 ] . V_68 . V_56 = sizeof( struct F_11 ) ;
V_73 [ 0 ] . V_68 . V_66 = ( V_74 * ) & V_70 ;
V_73 [ 1 ] . type = V_67 ;
V_73 [ 1 ] . V_68 . V_56 = 512 ;
V_73 [ 1 ] . V_68 . V_66 = ( V_74 * ) V_8 -> V_14 . V_1 [ 0 ] . V_75 ;
V_73 [ 2 ] . type = V_67 ;
V_73 [ 2 ] . V_68 . V_56 = 512 ;
V_73 [ 2 ] . V_68 . V_66 = ( V_74 * ) V_8 -> V_14 . V_1 [ 1 ] . V_75 ;
V_72 . V_76 = 3 ;
V_72 . V_66 = V_73 ;
V_60 = F_35 ( V_8 -> V_15 , L_7 , & V_72 , NULL ) ;
if ( V_60 == V_63 )
return - V_62 ;
if ( F_36 ( V_60 ) ) {
F_37 ( V_8 , L_8 ,
V_60 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_39 ( struct V_5 * V_2 , struct V_77 * * V_78 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_3 V_60 ;
struct V_54 V_55 ;
union V_58 * V_59 ;
int V_61 = 0 ;
if ( V_2 -> V_6 ) {
V_59 = V_2 -> V_6 ;
goto V_79;
}
V_55 . V_56 = V_57 ;
V_55 . V_66 = NULL ;
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_9 ,
V_80 , V_8 -> V_12 ) ;
V_60 = F_35 ( V_2 -> V_15 , L_10 , NULL , & V_55 ) ;
V_59 = V_2 -> V_6 = V_55 . V_66 ;
if ( F_36 ( V_60 ) ) {
if ( V_60 != V_63 ) {
F_42 ( V_2 , L_11 ,
V_60 ) ;
V_61 = - V_65 ;
}
goto V_64;
}
if ( ! V_55 . V_56 || ! V_55 . V_66 ) {
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_12 ,
V_80 ,
( unsigned long long ) V_55 . V_56 ,
V_55 . V_66 ) ;
V_61 = - V_65 ;
goto V_64;
}
if ( V_59 -> type != V_67 ) {
F_42 ( V_2 , L_13 ,
V_59 -> type ) ;
V_61 = - V_65 ;
goto V_64;
}
if ( V_59 -> V_68 . V_56 % V_81 ) {
F_42 ( V_2 , L_14 ,
V_59 -> V_68 . V_56 ) ;
V_61 = - V_65 ;
goto V_64;
}
V_79:
V_61 = V_59 -> V_68 . V_56 / V_81 ;
if ( V_78 ) {
* V_78 = ( void * ) V_59 -> V_68 . V_66 ;
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_15 ,
V_80 , * V_78 , V_61 ) ;
}
return V_61 ;
V_64:
F_2 ( V_2 ) ;
return V_61 ;
}
unsigned long F_43 ( struct V_5 * V_2 ,
const struct F_11 * V_53 )
{
unsigned long V_82 = 0 ;
unsigned int type ;
int V_83 ;
V_74 V_84 ;
V_83 = V_2 -> V_85 ;
if ( ! ( V_53 -> V_9 & 0x10 ) )
V_83 = 0 ;
V_84 = F_44 ( V_86 , V_53 -> V_87 [ V_83 ] . V_88 ) ;
V_82 |= F_45 ( V_84 ) ;
if ( ! ( V_53 -> V_9 & ( 1 << ( 2 * V_83 ) ) ) )
type = V_89 ;
else
type = V_90 ;
V_84 = F_44 ( type , V_53 -> V_87 [ V_83 ] . V_91 ) ;
V_82 |= F_45 ( V_84 ) ;
return V_82 ;
}
int F_46 ( struct V_7 * V_8 , const struct F_11 * V_53 )
{
struct V_5 * V_2 ;
F_13 (dev, &ap->link, ENABLED) {
unsigned long V_82 , V_92 ;
V_82 = F_43 ( V_2 , V_53 ) ;
F_47 ( V_82 , NULL , NULL , & V_92 ) ;
if ( V_92 & ~ V_93 )
return 1 ;
}
return 0 ;
}
static void F_48 ( struct V_5 * V_2 ,
const struct V_77 * V_78 ,
struct V_94 * V_95 )
{
F_49 ( V_2 , V_95 ) ;
V_95 -> V_9 |= V_96 | V_97 ;
V_95 -> V_98 = V_99 ;
V_95 -> V_100 = V_78 -> V_95 [ 0 ] ;
V_95 -> V_101 = V_78 -> V_95 [ 1 ] ;
V_95 -> V_102 = V_78 -> V_95 [ 2 ] ;
V_95 -> V_103 = V_78 -> V_95 [ 3 ] ;
V_95 -> V_104 = V_78 -> V_95 [ 4 ] ;
V_95 -> V_1 = V_78 -> V_95 [ 5 ] ;
V_95 -> V_105 = V_78 -> V_95 [ 6 ] ;
}
static int F_50 ( struct V_5 * V_2 ,
const struct V_94 * V_95 ,
const struct V_94 * V_106 )
{
if ( V_2 -> V_107 & V_108 ) {
if ( V_95 -> V_105 == V_109 &&
V_95 -> V_100 == V_110 )
return 1 ;
}
if ( V_2 -> V_107 & V_111 ) {
if ( V_95 -> V_105 == V_112 &&
V_95 -> V_100 == V_113 )
return 1 ;
if ( V_95 -> V_105 == V_114 )
return 1 ;
if ( ( ! V_106 || V_106 -> V_105 != V_115 ) &&
V_95 -> V_105 == V_116 &&
( V_95 -> V_100 == V_117 ||
V_95 -> V_100 == V_118 ) )
return 1 ;
}
if ( V_95 -> V_105 == V_109 &&
V_95 -> V_100 == V_119 ) {
if ( V_2 -> V_107 & V_120 &&
V_95 -> V_101 == V_121 )
return 1 ;
if ( V_2 -> V_107 & V_122 &&
( V_95 -> V_101 == V_123 ||
V_95 -> V_101 == V_124 ) )
return 1 ;
if ( V_2 -> V_107 & V_125 &&
V_95 -> V_101 == V_126 )
return 1 ;
}
return 0 ;
}
static int F_51 ( struct V_5 * V_2 ,
const struct V_77 * V_78 ,
const struct V_77 * V_127 )
{
struct V_94 * V_128 = NULL ;
struct V_94 V_95 , V_106 , V_129 ;
unsigned int V_130 ;
const char * V_131 ;
const char * V_132 ;
char V_133 [ 60 ] ;
int V_61 ;
if ( ( V_78 -> V_95 [ 0 ] == 0 ) && ( V_78 -> V_95 [ 1 ] == 0 ) && ( V_78 -> V_95 [ 2 ] == 0 )
&& ( V_78 -> V_95 [ 3 ] == 0 ) && ( V_78 -> V_95 [ 4 ] == 0 ) && ( V_78 -> V_95 [ 5 ] == 0 )
&& ( V_78 -> V_95 [ 6 ] == 0 ) )
return 0 ;
F_48 ( V_2 , V_78 , & V_95 ) ;
if ( V_127 ) {
F_48 ( V_2 , V_127 , & V_106 ) ;
V_128 = & V_106 ;
}
if ( ! F_50 ( V_2 , & V_95 , V_128 ) ) {
V_129 = V_95 ;
V_130 = F_52 ( V_2 , & V_129 , NULL ,
V_134 , NULL , 0 , 0 ) ;
switch ( V_130 ) {
case 0 :
V_131 = V_135 ;
snprintf ( V_133 , sizeof( V_133 ) , L_16 ) ;
V_61 = 1 ;
break;
case V_136 :
V_131 = V_137 ;
snprintf ( V_133 , sizeof( V_133 ) ,
L_17 ,
V_129 . V_105 , V_129 . V_100 ) ;
V_61 = 0 ;
break;
default:
V_131 = V_138 ;
snprintf ( V_133 , sizeof( V_133 ) ,
L_18 ,
V_130 , V_129 . V_105 , V_129 . V_100 ) ;
V_61 = - V_139 ;
break;
}
} else {
V_131 = V_137 ;
snprintf ( V_133 , sizeof( V_133 ) , L_19 ) ;
V_61 = 0 ;
}
V_132 = F_53 ( V_95 . V_105 ) ;
F_54 ( V_2 , V_131 ,
L_20 ,
V_95 . V_105 , V_95 . V_100 , V_95 . V_101 , V_95 . V_102 ,
V_95 . V_103 , V_95 . V_104 , V_95 . V_1 ,
( V_132 ? V_132 : L_21 ) , V_133 ) ;
return V_61 ;
}
static int F_55 ( struct V_5 * V_2 , int * V_140 )
{
struct V_77 * V_78 = NULL , * V_141 = NULL ;
int V_142 , V_20 , V_61 ;
V_61 = F_39 ( V_2 , & V_78 ) ;
if ( V_61 < 0 )
return V_61 ;
V_142 = V_61 ;
for ( V_20 = 0 ; V_20 < V_142 ; V_20 ++ , V_78 ++ ) {
V_61 = F_51 ( V_2 , V_78 , V_141 ) ;
if ( V_61 < 0 )
break;
if ( V_61 ) {
( * V_140 ) ++ ;
V_141 = V_78 ;
}
}
F_2 ( V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_3 V_60 ;
struct V_71 V_72 ;
union V_58 V_73 [ 1 ] ;
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_22 ,
V_80 , V_2 -> V_85 , V_8 -> V_12 ) ;
V_72 . V_76 = 1 ;
V_72 . V_66 = V_73 ;
V_73 [ 0 ] . type = V_67 ;
V_73 [ 0 ] . V_68 . V_56 = sizeof( V_2 -> V_75 [ 0 ] ) * V_143 ;
V_73 [ 0 ] . V_68 . V_66 = ( V_74 * ) V_2 -> V_75 ;
F_57 ( V_2 -> V_75 , V_143 ) ;
V_60 = F_35 ( V_2 -> V_15 , L_23 , & V_72 , NULL ) ;
F_57 ( V_2 -> V_75 , V_143 ) ;
if ( V_60 == V_63 )
return - V_62 ;
if ( F_36 ( V_60 ) ) {
F_42 ( V_2 , L_24 , V_60 ) ;
return - V_139 ;
}
return 0 ;
}
int F_58 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_59 ( struct V_7 * V_8 )
{
const struct F_11 * V_53 = F_33 ( V_8 ) ;
struct V_5 * V_2 ;
if ( V_8 -> V_15 && V_53 ) {
F_34 ( V_8 , V_53 ) ;
F_13 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_60 ( V_2 ) &&
F_39 ( V_2 , NULL ) >= 0 )
V_2 -> V_9 |= V_144 ;
}
} else {
F_13 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_60 ( V_2 ) )
V_2 -> V_9 |= V_144 ;
}
}
}
void F_61 ( struct V_7 * V_8 , T_4 V_145 )
{
struct V_5 * V_2 ;
if ( ! V_8 -> V_15 || ( V_8 -> V_9 & V_10 ) )
return;
if ( V_145 . V_28 == V_146 )
F_62 ( V_8 -> V_15 , V_147 ) ;
F_13 (dev, &ap->link, ENABLED) {
if ( V_2 -> V_15 )
F_62 ( V_2 -> V_15 ,
V_145 . V_28 == V_146 ?
V_147 : V_148 ) ;
}
if ( V_145 . V_28 != V_146 )
F_62 ( V_8 -> V_15 , V_148 ) ;
}
int F_63 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
struct V_149 * V_150 = & V_8 -> V_14 . V_151 ;
int V_152 = V_8 -> V_9 & V_10 ;
int V_140 = 0 ;
int V_61 ;
if ( ! V_2 -> V_15 )
return 0 ;
if ( ! ( V_2 -> V_9 & V_144 ) &&
! ( V_152 && ( V_150 -> V_20 . V_9 & V_153 ) ) )
return 0 ;
if ( V_152 ) {
V_61 = F_56 ( V_2 ) ;
if ( V_61 && V_61 != - V_62 )
goto V_154;
}
V_61 = F_55 ( V_2 , & V_140 ) ;
if ( V_61 )
goto V_154;
V_2 -> V_9 &= ~ V_144 ;
if ( V_140 ) {
V_61 = F_64 ( V_2 , 0 ) ;
if ( V_61 < 0 ) {
F_65 ( V_2 ,
L_25 ) ;
return V_61 ;
}
}
return 0 ;
V_154:
if ( V_61 == - V_65 && ! V_140 && ! ( V_8 -> V_23 & V_155 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_156 ) ) {
V_2 -> V_9 |= V_156 ;
return V_61 ;
}
F_42 ( V_2 , L_26 ) ;
V_2 -> V_15 = NULL ;
if ( ! V_140 && ! ( V_8 -> V_23 & V_155 ) )
return 0 ;
return V_61 ;
}
void F_66 ( struct V_5 * V_2 )
{
F_2 ( V_2 ) ;
}
