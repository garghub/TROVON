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
static int F_16 ( struct V_22 * V_23 , T_2 V_12 )
{
struct V_1 * V_2 = F_17 ( V_23 -> V_24 ) . V_2 ;
F_9 ( V_2 -> V_15 -> V_8 , V_2 , V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 , T_2 V_12 )
{
F_9 ( F_17 ( V_23 -> V_24 ) . V_8 , NULL , V_12 ) ;
return 0 ;
}
static void F_19 ( struct V_7 * V_8 , struct V_1 * V_2 ,
T_2 V_12 )
{
struct V_25 * V_26 = NULL ;
char V_27 [ 20 ] ;
char * V_28 [] = { V_27 , NULL } ;
if ( V_2 ) {
if ( V_2 -> V_29 )
V_26 = & V_2 -> V_29 -> V_30 . V_26 ;
} else
V_26 = & V_8 -> V_2 -> V_26 ;
if ( V_26 ) {
snprintf ( V_27 , 20 , L_2 , V_12 ) ;
F_20 ( V_26 , V_31 , V_28 ) ;
}
}
static void F_21 ( struct V_22 * V_23 , T_2 V_12 )
{
F_19 ( F_17 ( V_23 -> V_24 ) . V_8 , NULL , V_12 ) ;
}
static void F_22 ( struct V_22 * V_23 , T_2 V_12 )
{
struct V_1 * V_2 = F_17 ( V_23 -> V_24 ) . V_2 ;
F_19 ( V_2 -> V_15 -> V_8 , V_2 , V_12 ) ;
}
void F_23 ( struct V_7 * V_8 )
{
struct V_22 * V_32 = F_24 ( V_8 -> V_33 -> V_2 ) ;
struct V_22 * V_23 ;
struct V_34 * V_35 ;
if ( V_36 || V_8 -> V_4 & V_37 || ! V_32 )
return;
F_25 ( & V_8 -> V_6 , V_32 , V_8 -> V_38 ) ;
if ( F_26 ( V_8 , & V_8 -> V_39 ) == 0 )
V_8 -> V_40 |= V_41 ;
V_23 = F_24 ( & V_8 -> V_6 ) ;
if ( ! V_23 || V_23 -> V_24 )
return;
V_35 = F_27 ( sizeof( * V_35 ) , V_42 ) ;
if ( ! V_35 )
return;
V_35 -> V_43 . V_8 = V_8 ;
F_28 ( V_23 , & V_35 -> V_24 , F_18 ,
F_21 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
struct V_22 * V_44 = F_24 ( & V_8 -> V_6 ) ;
struct V_22 * V_32 = F_24 ( V_8 -> V_33 -> V_2 ) ;
struct V_22 * V_45 , * V_23 ;
struct V_34 * V_35 ;
T_3 V_46 ;
if ( V_36 || ! V_32 ||
( ! ( V_8 -> V_4 & V_37 ) && ! V_44 ) )
return;
if ( V_8 -> V_4 & V_37 ) {
if ( ! F_30 ( V_8 ) )
V_46 = F_31 ( V_8 -> V_38 , V_47 ) ;
else
V_46 = F_31 ( V_8 -> V_38 , V_2 -> V_15 -> V_48 ) ;
V_45 = V_32 ;
} else {
V_46 = V_2 -> V_49 ;
V_45 = V_44 ;
}
F_25 ( & V_2 -> V_6 , V_45 , V_46 ) ;
V_23 = F_24 ( & V_2 -> V_6 ) ;
if ( ! V_23 || V_23 -> V_24 )
return;
V_35 = F_27 ( sizeof( * V_35 ) , V_42 ) ;
if ( ! V_35 )
return;
V_35 -> V_43 . V_2 = V_2 ;
F_28 ( V_23 , & V_35 -> V_24 , F_16 ,
F_22 ) ;
}
void F_32 ( struct V_50 * V_33 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_33 -> V_52 ; V_51 ++ ) {
struct V_7 * V_8 = V_33 -> V_53 [ V_51 ] ;
const struct F_26 * V_54 = F_33 ( V_8 ) ;
if ( F_4 ( & V_8 -> V_6 ) && V_54 )
F_34 ( V_8 , V_54 ) ;
}
}
int F_26 ( struct V_7 * V_8 , struct F_26 * V_54 )
{
struct V_55 V_56 = { . V_57 = V_58 } ;
union V_59 * V_60 ;
T_4 V_61 ;
int V_62 = 0 ;
T_1 V_63 = F_4 ( & V_8 -> V_6 ) ;
if ( ! V_63 )
return - V_64 ;
V_61 = F_35 ( V_63 , L_3 , NULL , & V_56 ) ;
V_62 = - V_65 ;
if ( V_61 == V_66 )
goto V_67;
V_62 = - V_64 ;
if ( F_36 ( V_61 ) ) {
F_37 ( V_8 , L_4 ,
V_61 ) ;
goto V_67;
}
V_60 = V_56 . V_68 ;
if ( V_60 -> type != V_69 ) {
F_38 ( V_8 , L_5 ,
V_60 -> type ) ;
goto V_67;
}
if ( V_60 -> V_70 . V_57 != sizeof( struct F_26 ) ) {
F_37 ( V_8 , L_6 ,
V_60 -> V_70 . V_57 ) ;
goto V_67;
}
memcpy ( V_54 , V_60 -> V_70 . V_68 , sizeof( struct F_26 ) ) ;
V_62 = 0 ;
V_67:
F_2 ( V_56 . V_68 ) ;
return V_62 ;
}
int F_34 ( struct V_7 * V_8 , const struct F_26 * V_71 )
{
T_4 V_61 ;
struct F_26 V_72 = * V_71 ;
struct V_73 V_74 ;
union V_59 V_75 [ 3 ] ;
V_75 [ 0 ] . type = V_69 ;
V_75 [ 0 ] . V_70 . V_57 = sizeof( struct F_26 ) ;
V_75 [ 0 ] . V_70 . V_68 = ( V_76 * ) & V_72 ;
V_75 [ 1 ] . type = V_69 ;
V_75 [ 1 ] . V_70 . V_57 = 512 ;
V_75 [ 1 ] . V_70 . V_68 = ( V_76 * ) V_8 -> V_15 . V_77 [ 0 ] . V_78 ;
V_75 [ 2 ] . type = V_69 ;
V_75 [ 2 ] . V_70 . V_57 = 512 ;
V_75 [ 2 ] . V_70 . V_68 = ( V_76 * ) V_8 -> V_15 . V_77 [ 1 ] . V_78 ;
V_74 . V_79 = 3 ;
V_74 . V_68 = V_75 ;
V_61 = F_35 ( F_4 ( & V_8 -> V_6 ) , L_7 ,
& V_74 , NULL ) ;
if ( V_61 == V_66 )
return - V_65 ;
if ( F_36 ( V_61 ) ) {
F_37 ( V_8 , L_8 ,
V_61 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_80 * * V_81 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_4 V_61 ;
struct V_55 V_56 ;
union V_59 * V_60 ;
int V_62 = 0 ;
if ( V_2 -> V_3 ) {
V_60 = V_2 -> V_3 ;
goto V_82;
}
V_56 . V_57 = V_58 ;
V_56 . V_68 = NULL ;
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_9 ,
V_83 , V_8 -> V_38 ) ;
V_61 = F_35 ( F_3 ( V_2 ) , L_10 , NULL ,
& V_56 ) ;
V_60 = V_2 -> V_3 = V_56 . V_68 ;
if ( F_36 ( V_61 ) ) {
if ( V_61 != V_66 ) {
F_42 ( V_2 , L_11 ,
V_61 ) ;
V_62 = - V_64 ;
}
goto V_67;
}
if ( ! V_56 . V_57 || ! V_56 . V_68 ) {
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_12 ,
V_83 ,
( unsigned long long ) V_56 . V_57 ,
V_56 . V_68 ) ;
V_62 = - V_64 ;
goto V_67;
}
if ( V_60 -> type != V_69 ) {
F_42 ( V_2 , L_13 ,
V_60 -> type ) ;
V_62 = - V_64 ;
goto V_67;
}
if ( V_60 -> V_70 . V_57 % V_84 ) {
F_42 ( V_2 , L_14 ,
V_60 -> V_70 . V_57 ) ;
V_62 = - V_64 ;
goto V_67;
}
V_82:
V_62 = V_60 -> V_70 . V_57 / V_84 ;
if ( V_81 ) {
* V_81 = ( void * ) V_60 -> V_70 . V_68 ;
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_15 ,
V_83 , * V_81 , V_62 ) ;
}
return V_62 ;
V_67:
F_1 ( V_2 ) ;
return V_62 ;
}
unsigned long F_43 ( struct V_1 * V_2 ,
const struct F_26 * V_54 )
{
unsigned long V_85 = 0 ;
unsigned int type ;
int V_86 ;
V_76 V_87 ;
V_86 = V_2 -> V_49 ;
if ( ! ( V_54 -> V_4 & 0x10 ) )
V_86 = 0 ;
V_87 = F_44 ( V_88 , V_54 -> V_89 [ V_86 ] . V_90 ) ;
V_85 |= F_45 ( V_87 ) ;
if ( ! ( V_54 -> V_4 & ( 1 << ( 2 * V_86 ) ) ) )
type = V_91 ;
else
type = V_92 ;
V_87 = F_44 ( type , V_54 -> V_89 [ V_86 ] . V_93 ) ;
V_85 |= F_45 ( V_87 ) ;
return V_85 ;
}
int F_46 ( struct V_7 * V_8 , const struct F_26 * V_54 )
{
struct V_1 * V_2 ;
F_7 (dev, &ap->link, ENABLED) {
unsigned long V_85 , V_94 ;
V_85 = F_43 ( V_2 , V_54 ) ;
F_47 ( V_85 , NULL , NULL , & V_94 ) ;
if ( V_94 & ~ V_95 )
return 1 ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_80 * V_81 ,
struct V_96 * V_97 )
{
F_49 ( V_2 , V_97 ) ;
V_97 -> V_4 |= V_98 | V_99 ;
V_97 -> V_100 = V_101 ;
V_97 -> V_102 = V_81 -> V_97 [ 0 ] ;
V_97 -> V_103 = V_81 -> V_97 [ 1 ] ;
V_97 -> V_104 = V_81 -> V_97 [ 2 ] ;
V_97 -> V_105 = V_81 -> V_97 [ 3 ] ;
V_97 -> V_106 = V_81 -> V_97 [ 4 ] ;
V_97 -> V_77 = V_81 -> V_97 [ 5 ] ;
V_97 -> V_107 = V_81 -> V_97 [ 6 ] ;
}
static int F_50 ( struct V_1 * V_2 ,
const struct V_96 * V_97 ,
const struct V_96 * V_108 )
{
if ( V_2 -> V_109 & V_110 ) {
if ( V_97 -> V_107 == V_111 &&
V_97 -> V_102 == V_112 )
return 1 ;
}
if ( V_2 -> V_109 & V_113 ) {
if ( V_97 -> V_107 == V_114 &&
V_97 -> V_102 == V_115 )
return 1 ;
if ( V_97 -> V_107 == V_116 )
return 1 ;
if ( ( ! V_108 || V_108 -> V_107 != V_117 ) &&
V_97 -> V_107 == V_118 &&
( V_97 -> V_102 == V_119 ||
V_97 -> V_102 == V_120 ) )
return 1 ;
}
if ( V_97 -> V_107 == V_111 &&
V_97 -> V_102 == V_121 ) {
if ( V_2 -> V_109 & V_122 &&
V_97 -> V_103 == V_123 )
return 1 ;
if ( V_2 -> V_109 & V_124 &&
( V_97 -> V_103 == V_125 ||
V_97 -> V_103 == V_126 ) )
return 1 ;
if ( V_2 -> V_109 & V_127 &&
V_97 -> V_103 == V_128 )
return 1 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_80 * V_81 ,
const struct V_80 * V_129 )
{
struct V_96 * V_130 = NULL ;
struct V_96 V_97 , V_108 , V_131 ;
unsigned int V_132 ;
const char * V_133 ;
const char * V_134 ;
char V_135 [ 60 ] ;
int V_62 ;
if ( ( V_81 -> V_97 [ 0 ] == 0 ) && ( V_81 -> V_97 [ 1 ] == 0 ) && ( V_81 -> V_97 [ 2 ] == 0 )
&& ( V_81 -> V_97 [ 3 ] == 0 ) && ( V_81 -> V_97 [ 4 ] == 0 ) && ( V_81 -> V_97 [ 5 ] == 0 )
&& ( V_81 -> V_97 [ 6 ] == 0 ) )
return 0 ;
F_48 ( V_2 , V_81 , & V_97 ) ;
if ( V_129 ) {
F_48 ( V_2 , V_129 , & V_108 ) ;
V_130 = & V_108 ;
}
if ( ! F_50 ( V_2 , & V_97 , V_130 ) ) {
V_131 = V_97 ;
V_132 = F_52 ( V_2 , & V_131 , NULL ,
V_136 , NULL , 0 , 0 ) ;
switch ( V_132 ) {
case 0 :
V_133 = V_137 ;
snprintf ( V_135 , sizeof( V_135 ) , L_16 ) ;
V_62 = 1 ;
break;
case V_138 :
V_133 = V_139 ;
snprintf ( V_135 , sizeof( V_135 ) ,
L_17 ,
V_131 . V_107 , V_131 . V_102 ) ;
V_62 = 0 ;
break;
default:
V_133 = V_140 ;
snprintf ( V_135 , sizeof( V_135 ) ,
L_18 ,
V_132 , V_131 . V_107 , V_131 . V_102 ) ;
V_62 = - V_141 ;
break;
}
} else {
V_133 = V_139 ;
snprintf ( V_135 , sizeof( V_135 ) , L_19 ) ;
V_62 = 0 ;
}
V_134 = F_53 ( V_97 . V_107 ) ;
F_54 ( V_2 , V_133 ,
L_20 ,
V_97 . V_107 , V_97 . V_102 , V_97 . V_103 , V_97 . V_104 ,
V_97 . V_105 , V_97 . V_106 , V_97 . V_77 ,
( V_134 ? V_134 : L_21 ) , V_135 ) ;
return V_62 ;
}
static int F_55 ( struct V_1 * V_2 , int * V_142 )
{
struct V_80 * V_81 = NULL , * V_143 = NULL ;
int V_144 , V_51 , V_62 ;
V_62 = F_39 ( V_2 , & V_81 ) ;
if ( V_62 < 0 )
return V_62 ;
V_144 = V_62 ;
for ( V_51 = 0 ; V_51 < V_144 ; V_51 ++ , V_81 ++ ) {
V_62 = F_51 ( V_2 , V_81 , V_143 ) ;
if ( V_62 < 0 )
break;
if ( V_62 ) {
( * V_142 ) ++ ;
V_143 = V_81 ;
}
}
F_1 ( V_2 ) ;
if ( V_62 < 0 )
return V_62 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_4 V_61 ;
struct V_73 V_74 ;
union V_59 V_75 [ 1 ] ;
if ( F_40 ( V_8 ) )
F_41 ( V_2 , L_22 ,
V_83 , V_2 -> V_49 , V_8 -> V_38 ) ;
V_74 . V_79 = 1 ;
V_74 . V_68 = V_75 ;
V_75 [ 0 ] . type = V_69 ;
V_75 [ 0 ] . V_70 . V_57 = sizeof( V_2 -> V_78 [ 0 ] ) * V_145 ;
V_75 [ 0 ] . V_70 . V_68 = ( V_76 * ) V_2 -> V_78 ;
F_57 ( V_2 -> V_78 , V_145 ) ;
V_61 = F_35 ( F_3 ( V_2 ) , L_23 , & V_74 ,
NULL ) ;
F_57 ( V_2 -> V_78 , V_145 ) ;
if ( V_61 == V_66 )
return - V_65 ;
if ( F_36 ( V_61 ) ) {
F_42 ( V_2 , L_24 , V_61 ) ;
return - V_141 ;
}
return 0 ;
}
int F_58 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_59 ( struct V_7 * V_8 )
{
const struct F_26 * V_54 = F_33 ( V_8 ) ;
struct V_1 * V_2 ;
if ( F_4 ( & V_8 -> V_6 ) && V_54 ) {
F_34 ( V_8 , V_54 ) ;
F_7 (dev, &ap->link, ALL) {
F_1 ( V_2 ) ;
if ( F_60 ( V_2 ) &&
F_3 ( V_2 ) &&
F_39 ( V_2 , NULL ) >= 0 )
V_2 -> V_4 |= V_146 ;
}
} else {
F_7 (dev, &ap->link, ALL) {
F_1 ( V_2 ) ;
if ( F_60 ( V_2 ) )
V_2 -> V_4 |= V_146 ;
}
}
}
static int F_61 ( struct V_1 * V_2 , bool V_147 )
{
int V_148 = V_149 ;
if ( ! V_147 )
goto V_150;
if ( V_2 -> V_151 == V_152 &&
! ( F_62 ( V_2 ) && F_63 ( V_2 ) ) )
V_148 = V_153 ;
V_150:
return F_64 ( & V_2 -> V_6 , NULL , V_148 ) ;
}
static void F_65 ( struct V_7 * V_8 , T_5 V_154 )
{
bool V_147 = F_66 ( V_154 ) ;
struct V_1 * V_2 ;
T_1 V_63 ;
int V_155 ;
F_7 (dev, &ap->link, ENABLED) {
V_63 = F_3 ( V_2 ) ;
if ( ! V_63 )
continue;
if ( ! ( V_154 . V_12 & V_156 ) ) {
V_155 = F_61 ( V_2 , V_147 ) ;
if ( V_155 == V_157 )
continue;
if ( V_147 && F_62 ( V_2 ) &&
V_155 == V_149 )
F_67 ( V_2 ) ;
F_68 ( V_63 , V_155 ) ;
} else {
if ( V_147 && F_62 ( V_2 ) )
F_69 ( V_2 ) ;
F_68 ( V_63 , V_157 ) ;
}
}
}
static void F_70 ( struct V_7 * V_8 , T_5 V_154 )
{
struct V_1 * V_2 ;
T_1 V_158 ;
V_158 = F_4 ( & V_8 -> V_6 ) ;
if ( ! V_158 )
return;
if ( V_154 . V_12 & V_156 )
F_68 ( V_158 , V_157 ) ;
F_7 (dev, &ap->link, ENABLED) {
T_1 V_159 = F_3 ( V_2 ) ;
if ( ! V_159 )
continue;
F_68 ( V_159 , V_154 . V_12 & V_156 ?
V_157 : V_149 ) ;
}
if ( ! ( V_154 . V_12 & V_156 ) )
F_68 ( V_158 , V_149 ) ;
}
void F_71 ( struct V_7 * V_8 , T_5 V_154 )
{
if ( V_8 -> V_4 & V_37 )
F_65 ( V_8 , V_154 ) ;
else
F_70 ( V_8 , V_154 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
struct V_160 * V_161 = & V_8 -> V_15 . V_162 ;
int V_163 = V_8 -> V_4 & V_37 ;
int V_142 = 0 ;
int V_62 ;
if ( ! F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_4 & V_146 ) &&
! ( V_163 && ( V_161 -> V_51 . V_4 & V_164 ) ) )
return 0 ;
if ( V_163 ) {
V_62 = F_56 ( V_2 ) ;
if ( V_62 && V_62 != - V_65 )
goto V_165;
}
V_62 = F_55 ( V_2 , & V_142 ) ;
if ( V_62 )
goto V_165;
V_2 -> V_4 &= ~ V_146 ;
if ( V_142 ) {
V_62 = F_73 ( V_2 , 0 ) ;
if ( V_62 < 0 ) {
F_74 ( V_2 ,
L_25 ) ;
return V_62 ;
}
}
return 0 ;
V_165:
if ( V_62 == - V_64 && ! V_142 && ! ( V_8 -> V_40 & V_166 ) )
return 0 ;
if ( ! ( V_2 -> V_4 & V_167 ) ) {
V_2 -> V_4 |= V_167 ;
return V_62 ;
}
V_2 -> V_4 |= V_5 ;
F_42 ( V_2 , L_26 ) ;
if ( ! V_142 && ! ( V_8 -> V_40 & V_166 ) )
return 0 ;
return V_62 ;
}
void F_75 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
