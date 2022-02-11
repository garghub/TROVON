static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 & V_5 ?
NULL : F_4 ( & V_2 -> V_6 ) ;
}
static void F_5 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( V_2 )
V_2 -> V_4 |= V_9 ;
else {
struct V_10 * V_11 ;
struct V_1 * V_6 ;
F_6 (tlink, ap, EDGE)
F_7 (tdev, tlink, ALL)
V_6 -> V_4 |= V_9 ;
}
F_8 ( V_8 ) ;
}
static void F_9 ( struct V_7 * V_8 , struct V_1 * V_2 ,
T_2 V_12 )
{
struct V_13 * V_14 = & V_8 -> V_15 . V_16 ;
int V_17 = 0 ;
unsigned long V_4 ;
F_10 ( V_8 -> V_18 , V_4 ) ;
switch ( V_12 ) {
case V_19 :
case V_20 :
F_11 ( V_14 , L_1 ) ;
F_12 ( V_14 ) ;
F_13 ( V_8 ) ;
break;
case V_21 :
F_11 ( V_14 , L_1 ) ;
F_5 ( V_8 , V_2 ) ;
V_17 = 1 ;
break;
}
F_14 ( V_8 -> V_18 , V_4 ) ;
if ( V_17 )
F_15 ( V_8 ) ;
}
static void F_16 ( T_1 V_22 , T_2 V_12 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
F_9 ( V_2 -> V_15 -> V_8 , V_2 , V_12 ) ;
}
static void F_17 ( T_1 V_22 , T_2 V_12 , void * V_23 )
{
struct V_7 * V_8 = V_23 ;
F_9 ( V_8 , NULL , V_12 ) ;
}
static void F_18 ( struct V_7 * V_8 , struct V_1 * V_2 ,
T_2 V_12 )
{
struct V_24 * V_25 = NULL ;
char V_26 [ 20 ] ;
char * V_27 [] = { V_26 , NULL } ;
if ( V_2 ) {
if ( V_2 -> V_28 )
V_25 = & V_2 -> V_28 -> V_29 . V_25 ;
} else
V_25 = & V_8 -> V_2 -> V_25 ;
if ( V_25 ) {
snprintf ( V_26 , 20 , L_2 , V_12 ) ;
F_19 ( V_25 , V_30 , V_27 ) ;
}
}
static void F_20 ( T_1 V_22 , T_2 V_12 , void * V_23 )
{
F_18 ( V_23 , NULL , V_12 ) ;
}
static void F_21 ( T_1 V_22 , T_2 V_12 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
F_18 ( V_2 -> V_15 -> V_8 , V_2 , V_12 ) ;
}
void F_22 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_23 ( V_8 -> V_33 -> V_2 ) ;
if ( V_34 || V_8 -> V_4 & V_35 || ! V_32 )
return;
F_24 ( & V_8 -> V_6 , V_32 , V_8 -> V_36 ) ;
if ( F_25 ( V_8 , & V_8 -> V_37 ) == 0 )
V_8 -> V_38 |= V_39 ;
F_26 ( F_4 ( & V_8 -> V_6 ) ,
& V_40 , V_8 , NULL , NULL ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
struct V_31 * V_41 = F_23 ( & V_8 -> V_6 ) ;
struct V_31 * V_32 = F_23 ( V_8 -> V_33 -> V_2 ) ;
struct V_31 * V_42 ;
T_3 V_43 ;
if ( V_34 || ! V_32 ||
( ! ( V_8 -> V_4 & V_35 ) && ! V_41 ) )
return;
if ( V_8 -> V_4 & V_35 ) {
if ( ! F_28 ( V_8 ) )
V_43 = F_29 ( V_8 -> V_36 , V_44 ) ;
else
V_43 = F_29 ( V_8 -> V_36 , V_2 -> V_15 -> V_45 ) ;
V_42 = V_32 ;
} else {
V_43 = V_2 -> V_46 ;
V_42 = V_41 ;
}
F_24 ( & V_2 -> V_6 , V_42 , V_43 ) ;
F_26 ( F_3 ( V_2 ) ,
& V_47 , V_2 , NULL , NULL ) ;
}
void F_30 ( struct V_48 * V_33 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_33 -> V_50 ; V_49 ++ ) {
struct V_7 * V_8 = V_33 -> V_51 [ V_49 ] ;
const struct F_25 * V_52 = F_31 ( V_8 ) ;
if ( F_4 ( & V_8 -> V_6 ) && V_52 )
F_32 ( V_8 , V_52 ) ;
}
}
int F_25 ( struct V_7 * V_8 , struct F_25 * V_52 )
{
struct V_53 V_54 = { . V_55 = V_56 } ;
union V_57 * V_58 ;
T_4 V_59 ;
int V_60 = 0 ;
T_1 V_22 = F_4 ( & V_8 -> V_6 ) ;
if ( ! V_22 )
return - V_61 ;
V_59 = F_33 ( V_22 , L_3 , NULL , & V_54 ) ;
V_60 = - V_62 ;
if ( V_59 == V_63 )
goto V_64;
V_60 = - V_61 ;
if ( F_34 ( V_59 ) ) {
F_35 ( V_8 , L_4 ,
V_59 ) ;
goto V_64;
}
V_58 = V_54 . V_65 ;
if ( V_58 -> type != V_66 ) {
F_36 ( V_8 , L_5 ,
V_58 -> type ) ;
goto V_64;
}
if ( V_58 -> V_67 . V_55 != sizeof( struct F_25 ) ) {
F_35 ( V_8 , L_6 ,
V_58 -> V_67 . V_55 ) ;
goto V_64;
}
memcpy ( V_52 , V_58 -> V_67 . V_65 , sizeof( struct F_25 ) ) ;
V_60 = 0 ;
V_64:
F_2 ( V_54 . V_65 ) ;
return V_60 ;
}
int F_32 ( struct V_7 * V_8 , const struct F_25 * V_68 )
{
T_4 V_59 ;
struct F_25 V_69 = * V_68 ;
struct V_70 V_71 ;
union V_57 V_72 [ 3 ] ;
V_72 [ 0 ] . type = V_66 ;
V_72 [ 0 ] . V_67 . V_55 = sizeof( struct F_25 ) ;
V_72 [ 0 ] . V_67 . V_65 = ( V_73 * ) & V_69 ;
V_72 [ 1 ] . type = V_66 ;
V_72 [ 1 ] . V_67 . V_55 = 512 ;
V_72 [ 1 ] . V_67 . V_65 = ( V_73 * ) V_8 -> V_15 . V_74 [ 0 ] . V_75 ;
V_72 [ 2 ] . type = V_66 ;
V_72 [ 2 ] . V_67 . V_55 = 512 ;
V_72 [ 2 ] . V_67 . V_65 = ( V_73 * ) V_8 -> V_15 . V_74 [ 1 ] . V_75 ;
V_71 . V_76 = 3 ;
V_71 . V_65 = V_72 ;
V_59 = F_33 ( F_4 ( & V_8 -> V_6 ) , L_7 ,
& V_71 , NULL ) ;
if ( V_59 == V_63 )
return - V_62 ;
if ( F_34 ( V_59 ) ) {
F_35 ( V_8 , L_8 ,
V_59 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_77 * * V_78 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_4 V_59 ;
struct V_53 V_54 ;
union V_57 * V_58 ;
int V_60 = 0 ;
if ( V_2 -> V_3 ) {
V_58 = V_2 -> V_3 ;
goto V_79;
}
V_54 . V_55 = V_56 ;
V_54 . V_65 = NULL ;
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_9 ,
V_80 , V_8 -> V_36 ) ;
V_59 = F_33 ( F_3 ( V_2 ) , L_10 , NULL ,
& V_54 ) ;
V_58 = V_2 -> V_3 = V_54 . V_65 ;
if ( F_34 ( V_59 ) ) {
if ( V_59 != V_63 ) {
F_40 ( V_2 , L_11 ,
V_59 ) ;
V_60 = - V_61 ;
}
goto V_64;
}
if ( ! V_54 . V_55 || ! V_54 . V_65 ) {
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_12 ,
V_80 ,
( unsigned long long ) V_54 . V_55 ,
V_54 . V_65 ) ;
V_60 = - V_61 ;
goto V_64;
}
if ( V_58 -> type != V_66 ) {
F_40 ( V_2 , L_13 ,
V_58 -> type ) ;
V_60 = - V_61 ;
goto V_64;
}
if ( V_58 -> V_67 . V_55 % V_81 ) {
F_40 ( V_2 , L_14 ,
V_58 -> V_67 . V_55 ) ;
V_60 = - V_61 ;
goto V_64;
}
V_79:
V_60 = V_58 -> V_67 . V_55 / V_81 ;
if ( V_78 ) {
* V_78 = ( void * ) V_58 -> V_67 . V_65 ;
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_15 ,
V_80 , * V_78 , V_60 ) ;
}
return V_60 ;
V_64:
F_1 ( V_2 ) ;
return V_60 ;
}
unsigned long F_41 ( struct V_1 * V_2 ,
const struct F_25 * V_52 )
{
unsigned long V_82 = 0 ;
unsigned int type ;
int V_83 ;
V_73 V_84 ;
V_83 = V_2 -> V_46 ;
if ( ! ( V_52 -> V_4 & 0x10 ) )
V_83 = 0 ;
V_84 = F_42 ( V_85 , V_52 -> V_86 [ V_83 ] . V_87 ) ;
V_82 |= F_43 ( V_84 ) ;
if ( ! ( V_52 -> V_4 & ( 1 << ( 2 * V_83 ) ) ) )
type = V_88 ;
else
type = V_89 ;
V_84 = F_42 ( type , V_52 -> V_86 [ V_83 ] . V_90 ) ;
V_82 |= F_43 ( V_84 ) ;
return V_82 ;
}
int F_44 ( struct V_7 * V_8 , const struct F_25 * V_52 )
{
struct V_1 * V_2 ;
F_7 (dev, &ap->link, ENABLED) {
unsigned long V_82 , V_91 ;
V_82 = F_41 ( V_2 , V_52 ) ;
F_45 ( V_82 , NULL , NULL , & V_91 ) ;
if ( V_91 & ~ V_92 )
return 1 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
const struct V_77 * V_78 ,
struct V_93 * V_94 )
{
F_47 ( V_2 , V_94 ) ;
V_94 -> V_4 |= V_95 | V_96 ;
V_94 -> V_97 = V_98 ;
V_94 -> V_99 = V_78 -> V_94 [ 0 ] ;
V_94 -> V_100 = V_78 -> V_94 [ 1 ] ;
V_94 -> V_101 = V_78 -> V_94 [ 2 ] ;
V_94 -> V_102 = V_78 -> V_94 [ 3 ] ;
V_94 -> V_103 = V_78 -> V_94 [ 4 ] ;
V_94 -> V_74 = V_78 -> V_94 [ 5 ] ;
V_94 -> V_104 = V_78 -> V_94 [ 6 ] ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
const struct V_93 * V_105 )
{
if ( V_2 -> V_106 & V_107 ) {
if ( V_94 -> V_104 == V_108 &&
V_94 -> V_99 == V_109 )
return 1 ;
}
if ( V_2 -> V_106 & V_110 ) {
if ( V_94 -> V_104 == V_111 &&
V_94 -> V_99 == V_112 )
return 1 ;
if ( V_94 -> V_104 == V_113 )
return 1 ;
if ( ( ! V_105 || V_105 -> V_104 != V_114 ) &&
V_94 -> V_104 == V_115 &&
( V_94 -> V_99 == V_116 ||
V_94 -> V_99 == V_117 ) )
return 1 ;
}
if ( V_94 -> V_104 == V_108 &&
V_94 -> V_99 == V_118 ) {
if ( V_2 -> V_106 & V_119 &&
V_94 -> V_100 == V_120 )
return 1 ;
if ( V_2 -> V_106 & V_121 &&
( V_94 -> V_100 == V_122 ||
V_94 -> V_100 == V_123 ) )
return 1 ;
if ( V_2 -> V_106 & V_124 &&
V_94 -> V_100 == V_125 )
return 1 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
const struct V_77 * V_78 ,
const struct V_77 * V_126 )
{
struct V_93 * V_127 = NULL ;
struct V_93 V_94 , V_105 , V_128 ;
unsigned int V_129 ;
const char * V_130 ;
const char * V_131 ;
char V_132 [ 60 ] ;
int V_60 ;
if ( ( V_78 -> V_94 [ 0 ] == 0 ) && ( V_78 -> V_94 [ 1 ] == 0 ) && ( V_78 -> V_94 [ 2 ] == 0 )
&& ( V_78 -> V_94 [ 3 ] == 0 ) && ( V_78 -> V_94 [ 4 ] == 0 ) && ( V_78 -> V_94 [ 5 ] == 0 )
&& ( V_78 -> V_94 [ 6 ] == 0 ) )
return 0 ;
F_46 ( V_2 , V_78 , & V_94 ) ;
if ( V_126 ) {
F_46 ( V_2 , V_126 , & V_105 ) ;
V_127 = & V_105 ;
}
if ( ! F_48 ( V_2 , & V_94 , V_127 ) ) {
V_128 = V_94 ;
V_129 = F_50 ( V_2 , & V_128 , NULL ,
V_133 , NULL , 0 , 0 ) ;
switch ( V_129 ) {
case 0 :
V_130 = V_134 ;
snprintf ( V_132 , sizeof( V_132 ) , L_16 ) ;
V_60 = 1 ;
break;
case V_135 :
V_130 = V_136 ;
snprintf ( V_132 , sizeof( V_132 ) ,
L_17 ,
V_128 . V_104 , V_128 . V_99 ) ;
V_60 = 0 ;
break;
default:
V_130 = V_137 ;
snprintf ( V_132 , sizeof( V_132 ) ,
L_18 ,
V_129 , V_128 . V_104 , V_128 . V_99 ) ;
V_60 = - V_138 ;
break;
}
} else {
V_130 = V_136 ;
snprintf ( V_132 , sizeof( V_132 ) , L_19 ) ;
V_60 = 0 ;
}
V_131 = F_51 ( V_94 . V_104 ) ;
F_52 ( V_2 , V_130 ,
L_20 ,
V_94 . V_104 , V_94 . V_99 , V_94 . V_100 , V_94 . V_101 ,
V_94 . V_102 , V_94 . V_103 , V_94 . V_74 ,
( V_131 ? V_131 : L_21 ) , V_132 ) ;
return V_60 ;
}
static int F_53 ( struct V_1 * V_2 , int * V_139 )
{
struct V_77 * V_78 = NULL , * V_140 = NULL ;
int V_141 , V_49 , V_60 ;
V_60 = F_37 ( V_2 , & V_78 ) ;
if ( V_60 < 0 )
return V_60 ;
V_141 = V_60 ;
for ( V_49 = 0 ; V_49 < V_141 ; V_49 ++ , V_78 ++ ) {
V_60 = F_49 ( V_2 , V_78 , V_140 ) ;
if ( V_60 < 0 )
break;
if ( V_60 ) {
( * V_139 ) ++ ;
V_140 = V_78 ;
}
}
F_1 ( V_2 ) ;
if ( V_60 < 0 )
return V_60 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_4 V_59 ;
struct V_70 V_71 ;
union V_57 V_72 [ 1 ] ;
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_22 ,
V_80 , V_2 -> V_46 , V_8 -> V_36 ) ;
V_71 . V_76 = 1 ;
V_71 . V_65 = V_72 ;
V_72 [ 0 ] . type = V_66 ;
V_72 [ 0 ] . V_67 . V_55 = sizeof( V_2 -> V_75 [ 0 ] ) * V_142 ;
V_72 [ 0 ] . V_67 . V_65 = ( V_73 * ) V_2 -> V_75 ;
F_55 ( V_2 -> V_75 , V_142 ) ;
V_59 = F_33 ( F_3 ( V_2 ) , L_23 , & V_71 ,
NULL ) ;
F_55 ( V_2 -> V_75 , V_142 ) ;
if ( V_59 == V_63 )
return - V_62 ;
if ( F_34 ( V_59 ) ) {
F_40 ( V_2 , L_24 , V_59 ) ;
return - V_138 ;
}
return 0 ;
}
int F_56 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_57 ( struct V_7 * V_8 )
{
const struct F_25 * V_52 = F_31 ( V_8 ) ;
struct V_1 * V_2 ;
if ( F_4 ( & V_8 -> V_6 ) && V_52 ) {
F_32 ( V_8 , V_52 ) ;
F_7 (dev, &ap->link, ALL) {
F_1 ( V_2 ) ;
if ( F_58 ( V_2 ) &&
F_37 ( V_2 , NULL ) >= 0 )
V_2 -> V_4 |= V_143 ;
}
} else {
F_7 (dev, &ap->link, ALL) {
F_1 ( V_2 ) ;
if ( F_58 ( V_2 ) )
V_2 -> V_4 |= V_143 ;
}
}
}
static int F_59 ( struct V_1 * V_2 , bool V_144 )
{
int V_145 = V_146 ;
if ( ! V_144 )
goto V_147;
if ( V_2 -> V_148 == V_149 &&
! ( F_60 ( V_2 ) && F_61 ( V_2 ) ) )
V_145 = V_150 ;
V_147:
return F_62 ( & V_2 -> V_6 , NULL , V_145 ) ;
}
static void F_63 ( struct V_7 * V_8 , T_5 V_151 )
{
bool V_144 = F_64 ( V_151 ) ;
struct V_1 * V_2 ;
T_1 V_22 ;
int V_152 ;
F_7 (dev, &ap->link, ENABLED) {
V_22 = F_3 ( V_2 ) ;
if ( ! V_22 )
continue;
if ( ! ( V_151 . V_12 & V_153 ) ) {
V_152 = F_59 ( V_2 , V_144 ) ;
if ( V_152 == V_154 )
continue;
if ( V_144 && F_60 ( V_2 ) &&
V_152 == V_146 )
F_65 ( V_2 ) ;
F_66 ( V_22 , V_152 ) ;
} else {
if ( V_144 && F_60 ( V_2 ) )
F_67 ( V_2 ) ;
F_66 ( V_22 , V_154 ) ;
}
}
}
static void F_68 ( struct V_7 * V_8 , T_5 V_151 )
{
struct V_1 * V_2 ;
T_1 V_155 ;
V_155 = F_4 ( & V_8 -> V_6 ) ;
if ( ! V_155 )
return;
if ( V_151 . V_12 & V_153 )
F_66 ( V_155 , V_154 ) ;
F_7 (dev, &ap->link, ENABLED) {
T_1 V_156 = F_3 ( V_2 ) ;
if ( ! V_156 )
continue;
F_66 ( V_156 , V_151 . V_12 & V_153 ?
V_154 : V_146 ) ;
}
if ( ! ( V_151 . V_12 & V_153 ) )
F_66 ( V_155 , V_146 ) ;
}
void F_69 ( struct V_7 * V_8 , T_5 V_151 )
{
if ( V_8 -> V_4 & V_35 )
F_63 ( V_8 , V_151 ) ;
else
F_68 ( V_8 , V_151 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
struct V_157 * V_158 = & V_8 -> V_15 . V_159 ;
int V_160 = V_8 -> V_4 & V_35 ;
int V_139 = 0 ;
int V_60 ;
if ( ! F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_4 & V_143 ) &&
! ( V_160 && ( V_158 -> V_49 . V_4 & V_161 ) ) )
return 0 ;
if ( V_160 ) {
V_60 = F_54 ( V_2 ) ;
if ( V_60 && V_60 != - V_62 )
goto V_162;
}
V_60 = F_53 ( V_2 , & V_139 ) ;
if ( V_60 )
goto V_162;
V_2 -> V_4 &= ~ V_143 ;
if ( V_139 ) {
V_60 = F_71 ( V_2 , 0 ) ;
if ( V_60 < 0 ) {
F_72 ( V_2 ,
L_25 ) ;
return V_60 ;
}
}
return 0 ;
V_162:
if ( V_60 == - V_61 && ! V_139 && ! ( V_8 -> V_38 & V_163 ) )
return 0 ;
if ( ! ( V_2 -> V_4 & V_164 ) ) {
V_2 -> V_4 |= V_164 ;
return V_60 ;
}
V_2 -> V_4 |= V_5 ;
F_40 ( V_2 , L_26 ) ;
if ( ! V_139 && ! ( V_8 -> V_38 & V_163 ) )
return 0 ;
return V_60 ;
}
void F_73 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
