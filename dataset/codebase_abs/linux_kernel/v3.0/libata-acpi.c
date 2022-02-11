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
F_37 ( V_8 , V_66 ,
L_4 ,
V_60 ) ;
goto V_64;
}
V_59 = V_55 . V_67 ;
if ( V_59 -> type != V_68 ) {
F_37 ( V_8 , V_69 ,
L_5 ,
V_59 -> type ) ;
goto V_64;
}
if ( V_59 -> V_70 . V_56 != sizeof( struct F_11 ) ) {
F_37 ( V_8 , V_66 ,
L_6 ,
V_59 -> V_70 . V_56 ) ;
goto V_64;
}
memcpy ( V_53 , V_59 -> V_70 . V_67 , sizeof( struct F_11 ) ) ;
V_61 = 0 ;
V_64:
F_3 ( V_55 . V_67 ) ;
return V_61 ;
}
int F_34 ( struct V_7 * V_8 , const struct F_11 * V_71 )
{
T_3 V_60 ;
struct F_11 V_72 = * V_71 ;
struct V_73 V_74 ;
union V_58 V_75 [ 3 ] ;
V_75 [ 0 ] . type = V_68 ;
V_75 [ 0 ] . V_70 . V_56 = sizeof( struct F_11 ) ;
V_75 [ 0 ] . V_70 . V_67 = ( V_76 * ) & V_72 ;
V_75 [ 1 ] . type = V_68 ;
V_75 [ 1 ] . V_70 . V_56 = 512 ;
V_75 [ 1 ] . V_70 . V_67 = ( V_76 * ) V_8 -> V_14 . V_1 [ 0 ] . V_77 ;
V_75 [ 2 ] . type = V_68 ;
V_75 [ 2 ] . V_70 . V_56 = 512 ;
V_75 [ 2 ] . V_70 . V_67 = ( V_76 * ) V_8 -> V_14 . V_1 [ 1 ] . V_77 ;
V_74 . V_78 = 3 ;
V_74 . V_67 = V_75 ;
V_60 = F_35 ( V_8 -> V_15 , L_7 , & V_74 , NULL ) ;
if ( V_60 == V_63 )
return - V_62 ;
if ( F_36 ( V_60 ) ) {
F_37 ( V_8 , V_66 ,
L_8 , V_60 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_38 ( struct V_5 * V_2 , struct V_79 * * V_80 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_3 V_60 ;
struct V_54 V_55 ;
union V_58 * V_59 ;
int V_61 = 0 ;
if ( V_2 -> V_6 ) {
V_59 = V_2 -> V_6 ;
goto V_81;
}
V_55 . V_56 = V_57 ;
V_55 . V_67 = NULL ;
if ( F_39 ( V_8 ) )
F_40 ( V_2 , V_82 , L_9 ,
V_83 , V_8 -> V_12 ) ;
V_60 = F_35 ( V_2 -> V_15 , L_10 , NULL , & V_55 ) ;
V_59 = V_2 -> V_6 = V_55 . V_67 ;
if ( F_36 ( V_60 ) ) {
if ( V_60 != V_63 ) {
F_40 ( V_2 , V_69 ,
L_11 ,
V_60 ) ;
V_61 = - V_65 ;
}
goto V_64;
}
if ( ! V_55 . V_56 || ! V_55 . V_67 ) {
if ( F_39 ( V_8 ) )
F_40 ( V_2 , V_82 , L_12
L_13 ,
V_83 ,
( unsigned long long ) V_55 . V_56 ,
V_55 . V_67 ) ;
V_61 = - V_65 ;
goto V_64;
}
if ( V_59 -> type != V_68 ) {
F_40 ( V_2 , V_69 ,
L_14 ,
V_59 -> type ) ;
V_61 = - V_65 ;
goto V_64;
}
if ( V_59 -> V_70 . V_56 % V_84 ) {
F_40 ( V_2 , V_69 ,
L_15 ,
V_59 -> V_70 . V_56 ) ;
V_61 = - V_65 ;
goto V_64;
}
V_81:
V_61 = V_59 -> V_70 . V_56 / V_84 ;
if ( V_80 ) {
* V_80 = ( void * ) V_59 -> V_70 . V_67 ;
if ( F_39 ( V_8 ) )
F_40 ( V_2 , V_82 ,
L_16 ,
V_83 , * V_80 , V_61 ) ;
}
return V_61 ;
V_64:
F_2 ( V_2 ) ;
return V_61 ;
}
unsigned long F_41 ( struct V_5 * V_2 ,
const struct F_11 * V_53 )
{
unsigned long V_85 = 0 ;
unsigned int type ;
int V_86 ;
V_76 V_87 ;
V_86 = V_2 -> V_88 ;
if ( ! ( V_53 -> V_9 & 0x10 ) )
V_86 = 0 ;
V_87 = F_42 ( V_89 , V_53 -> V_90 [ V_86 ] . V_91 ) ;
V_85 |= F_43 ( V_87 ) ;
if ( ! ( V_53 -> V_9 & ( 1 << ( 2 * V_86 ) ) ) )
type = V_92 ;
else
type = V_93 ;
V_87 = F_42 ( type , V_53 -> V_90 [ V_86 ] . V_94 ) ;
V_85 |= F_43 ( V_87 ) ;
return V_85 ;
}
int F_44 ( struct V_7 * V_8 , const struct F_11 * V_53 )
{
struct V_5 * V_2 ;
F_13 (dev, &ap->link, ENABLED) {
unsigned long V_85 , V_95 ;
V_85 = F_41 ( V_2 , V_53 ) ;
F_45 ( V_85 , NULL , NULL , & V_95 ) ;
if ( V_95 & ~ V_96 )
return 1 ;
}
return 0 ;
}
static void F_46 ( struct V_5 * V_2 ,
const struct V_79 * V_80 ,
struct V_97 * V_98 )
{
F_47 ( V_2 , V_98 ) ;
V_98 -> V_9 |= V_99 | V_100 ;
V_98 -> V_101 = V_102 ;
V_98 -> V_103 = V_80 -> V_98 [ 0 ] ;
V_98 -> V_104 = V_80 -> V_98 [ 1 ] ;
V_98 -> V_105 = V_80 -> V_98 [ 2 ] ;
V_98 -> V_106 = V_80 -> V_98 [ 3 ] ;
V_98 -> V_107 = V_80 -> V_98 [ 4 ] ;
V_98 -> V_1 = V_80 -> V_98 [ 5 ] ;
V_98 -> V_108 = V_80 -> V_98 [ 6 ] ;
}
static int F_48 ( struct V_5 * V_2 ,
const struct V_97 * V_98 ,
const struct V_97 * V_109 )
{
if ( V_2 -> V_110 & V_111 ) {
if ( V_98 -> V_108 == V_112 &&
V_98 -> V_103 == V_113 )
return 1 ;
}
if ( V_2 -> V_110 & V_114 ) {
if ( V_98 -> V_108 == V_115 &&
V_98 -> V_103 == V_116 )
return 1 ;
if ( V_98 -> V_108 == V_117 )
return 1 ;
if ( ( ! V_109 || V_109 -> V_108 != V_118 ) &&
V_98 -> V_108 == V_119 &&
( V_98 -> V_103 == V_120 ||
V_98 -> V_103 == V_121 ) )
return 1 ;
}
if ( V_98 -> V_108 == V_112 &&
V_98 -> V_103 == V_122 ) {
if ( V_2 -> V_110 & V_123 &&
V_98 -> V_104 == V_124 )
return 1 ;
if ( V_2 -> V_110 & V_125 &&
( V_98 -> V_104 == V_126 ||
V_98 -> V_104 == V_127 ) )
return 1 ;
if ( V_2 -> V_110 & V_128 &&
V_98 -> V_104 == V_129 )
return 1 ;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_2 ,
const struct V_79 * V_80 ,
const struct V_79 * V_130 )
{
struct V_97 * V_131 = NULL ;
struct V_97 V_98 , V_109 , V_132 ;
unsigned int V_133 ;
const char * V_134 ;
const char * V_135 ;
char V_136 [ 60 ] ;
int V_61 ;
if ( ( V_80 -> V_98 [ 0 ] == 0 ) && ( V_80 -> V_98 [ 1 ] == 0 ) && ( V_80 -> V_98 [ 2 ] == 0 )
&& ( V_80 -> V_98 [ 3 ] == 0 ) && ( V_80 -> V_98 [ 4 ] == 0 ) && ( V_80 -> V_98 [ 5 ] == 0 )
&& ( V_80 -> V_98 [ 6 ] == 0 ) )
return 0 ;
F_46 ( V_2 , V_80 , & V_98 ) ;
if ( V_130 ) {
F_46 ( V_2 , V_130 , & V_109 ) ;
V_131 = & V_109 ;
}
if ( ! F_48 ( V_2 , & V_98 , V_131 ) ) {
V_132 = V_98 ;
V_133 = F_50 ( V_2 , & V_132 , NULL ,
V_137 , NULL , 0 , 0 ) ;
switch ( V_133 ) {
case 0 :
V_134 = V_82 ;
snprintf ( V_136 , sizeof( V_136 ) , L_17 ) ;
V_61 = 1 ;
break;
case V_138 :
V_134 = V_139 ;
snprintf ( V_136 , sizeof( V_136 ) ,
L_18 ,
V_132 . V_108 , V_132 . V_103 ) ;
V_61 = 0 ;
break;
default:
V_134 = V_66 ;
snprintf ( V_136 , sizeof( V_136 ) ,
L_19 ,
V_133 , V_132 . V_108 , V_132 . V_103 ) ;
V_61 = - V_140 ;
break;
}
} else {
V_134 = V_139 ;
snprintf ( V_136 , sizeof( V_136 ) , L_20 ) ;
V_61 = 0 ;
}
V_135 = F_51 ( V_98 . V_108 ) ;
F_40 ( V_2 , V_134 ,
L_21 ,
V_98 . V_108 , V_98 . V_103 , V_98 . V_104 , V_98 . V_105 ,
V_98 . V_106 , V_98 . V_107 , V_98 . V_1 ,
( V_135 ? V_135 : L_22 ) , V_136 ) ;
return V_61 ;
}
static int F_52 ( struct V_5 * V_2 , int * V_141 )
{
struct V_79 * V_80 = NULL , * V_142 = NULL ;
int V_143 , V_20 , V_61 ;
V_61 = F_38 ( V_2 , & V_80 ) ;
if ( V_61 < 0 )
return V_61 ;
V_143 = V_61 ;
for ( V_20 = 0 ; V_20 < V_143 ; V_20 ++ , V_80 ++ ) {
V_61 = F_49 ( V_2 , V_80 , V_142 ) ;
if ( V_61 < 0 )
break;
if ( V_61 ) {
( * V_141 ) ++ ;
V_142 = V_80 ;
}
}
F_2 ( V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static int F_53 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_3 V_60 ;
struct V_73 V_74 ;
union V_58 V_75 [ 1 ] ;
if ( F_39 ( V_8 ) )
F_40 ( V_2 , V_82 , L_23 ,
V_83 , V_2 -> V_88 , V_8 -> V_12 ) ;
V_74 . V_78 = 1 ;
V_74 . V_67 = V_75 ;
V_75 [ 0 ] . type = V_68 ;
V_75 [ 0 ] . V_70 . V_56 = sizeof( V_2 -> V_77 [ 0 ] ) * V_144 ;
V_75 [ 0 ] . V_70 . V_67 = ( V_76 * ) V_2 -> V_77 ;
F_54 ( V_2 -> V_77 , V_144 ) ;
V_60 = F_35 ( V_2 -> V_15 , L_24 , & V_74 , NULL ) ;
F_54 ( V_2 -> V_77 , V_144 ) ;
if ( V_60 == V_63 )
return - V_62 ;
if ( F_36 ( V_60 ) ) {
F_40 ( V_2 , V_69 ,
L_25 , V_60 ) ;
return - V_140 ;
}
return 0 ;
}
int F_55 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_56 ( struct V_7 * V_8 )
{
const struct F_11 * V_53 = F_33 ( V_8 ) ;
struct V_5 * V_2 ;
if ( V_8 -> V_15 && V_53 ) {
F_34 ( V_8 , V_53 ) ;
F_13 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_57 ( V_2 ) &&
F_38 ( V_2 , NULL ) >= 0 )
V_2 -> V_9 |= V_145 ;
}
} else {
F_13 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_57 ( V_2 ) )
V_2 -> V_9 |= V_145 ;
}
}
}
void F_58 ( struct V_7 * V_8 , T_4 V_146 )
{
struct V_5 * V_2 ;
if ( ! V_8 -> V_15 || ( V_8 -> V_9 & V_10 ) )
return;
if ( V_146 . V_28 == V_147 )
F_59 ( V_8 -> V_15 , V_148 ) ;
F_13 (dev, &ap->link, ENABLED) {
if ( V_2 -> V_15 )
F_59 ( V_2 -> V_15 ,
V_146 . V_28 == V_147 ?
V_148 : V_149 ) ;
}
if ( V_146 . V_28 != V_147 )
F_59 ( V_8 -> V_15 , V_149 ) ;
}
int F_60 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
struct V_150 * V_151 = & V_8 -> V_14 . V_152 ;
int V_153 = V_8 -> V_9 & V_10 ;
int V_141 = 0 ;
int V_61 ;
if ( ! V_2 -> V_15 )
return 0 ;
if ( ! ( V_2 -> V_9 & V_145 ) &&
! ( V_153 && ( V_151 -> V_20 . V_9 & V_154 ) ) )
return 0 ;
if ( V_153 ) {
V_61 = F_53 ( V_2 ) ;
if ( V_61 && V_61 != - V_62 )
goto V_155;
}
V_61 = F_52 ( V_2 , & V_141 ) ;
if ( V_61 )
goto V_155;
V_2 -> V_9 &= ~ V_145 ;
if ( V_141 ) {
V_61 = F_61 ( V_2 , 0 ) ;
if ( V_61 < 0 ) {
F_40 ( V_2 , V_66 , L_26
L_27 ) ;
return V_61 ;
}
}
return 0 ;
V_155:
if ( V_61 == - V_65 && ! V_141 && ! ( V_8 -> V_23 & V_156 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_157 ) ) {
V_2 -> V_9 |= V_157 ;
return V_61 ;
}
F_40 ( V_2 , V_69 ,
L_28 ) ;
V_2 -> V_15 = NULL ;
if ( ! V_141 && ! ( V_8 -> V_23 & V_156 ) )
return 0 ;
return V_61 ;
}
void F_62 ( struct V_5 * V_2 )
{
F_2 ( V_2 ) ;
}
