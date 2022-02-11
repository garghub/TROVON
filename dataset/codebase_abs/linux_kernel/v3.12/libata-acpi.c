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
T_1 V_31 = F_4 ( V_8 -> V_32 -> V_2 ) ;
if ( V_33 || V_8 -> V_4 & V_34 || ! V_31 )
return;
F_23 ( & V_8 -> V_6 , F_24 ( V_31 , V_8 -> V_35 ) ) ;
if ( F_25 ( V_8 , & V_8 -> V_36 ) == 0 )
V_8 -> V_37 |= V_38 ;
F_26 ( F_4 ( & V_8 -> V_6 ) ,
& V_39 , V_8 , NULL , NULL ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_1 V_40 = F_4 ( & V_8 -> V_6 ) ;
T_1 V_31 = F_4 ( V_8 -> V_32 -> V_2 ) ;
T_1 V_41 ;
T_3 V_42 ;
if ( V_33 || ! V_31 ||
( ! ( V_8 -> V_4 & V_34 ) && ! V_40 ) )
return;
if ( V_8 -> V_4 & V_34 ) {
if ( ! F_28 ( V_8 ) )
V_42 = F_29 ( V_8 -> V_35 , V_43 ) ;
else
V_42 = F_29 ( V_8 -> V_35 , V_2 -> V_15 -> V_44 ) ;
V_41 = V_31 ;
} else {
V_42 = V_2 -> V_45 ;
V_41 = V_40 ;
}
F_23 ( & V_2 -> V_6 , F_24 ( V_41 , V_42 ) ) ;
F_26 ( F_3 ( V_2 ) ,
& V_46 , V_2 , NULL , NULL ) ;
}
void F_30 ( struct V_47 * V_32 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_32 -> V_49 ; V_48 ++ ) {
struct V_7 * V_8 = V_32 -> V_50 [ V_48 ] ;
const struct F_25 * V_51 = F_31 ( V_8 ) ;
if ( F_4 ( & V_8 -> V_6 ) && V_51 )
F_32 ( V_8 , V_51 ) ;
}
}
int F_25 ( struct V_7 * V_8 , struct F_25 * V_51 )
{
struct V_52 V_53 = { . V_54 = V_55 } ;
union V_56 * V_57 ;
T_4 V_58 ;
int V_59 = 0 ;
T_1 V_22 = F_4 ( & V_8 -> V_6 ) ;
if ( ! V_22 )
return - V_60 ;
V_58 = F_33 ( V_22 , L_3 , NULL , & V_53 ) ;
V_59 = - V_61 ;
if ( V_58 == V_62 )
goto V_63;
V_59 = - V_60 ;
if ( F_34 ( V_58 ) ) {
F_35 ( V_8 , L_4 ,
V_58 ) ;
goto V_63;
}
V_57 = V_53 . V_64 ;
if ( V_57 -> type != V_65 ) {
F_36 ( V_8 , L_5 ,
V_57 -> type ) ;
goto V_63;
}
if ( V_57 -> V_66 . V_54 != sizeof( struct F_25 ) ) {
F_35 ( V_8 , L_6 ,
V_57 -> V_66 . V_54 ) ;
goto V_63;
}
memcpy ( V_51 , V_57 -> V_66 . V_64 , sizeof( struct F_25 ) ) ;
V_59 = 0 ;
V_63:
F_2 ( V_53 . V_64 ) ;
return V_59 ;
}
int F_32 ( struct V_7 * V_8 , const struct F_25 * V_67 )
{
T_4 V_58 ;
struct F_25 V_68 = * V_67 ;
struct V_69 V_70 ;
union V_56 V_71 [ 3 ] ;
V_71 [ 0 ] . type = V_65 ;
V_71 [ 0 ] . V_66 . V_54 = sizeof( struct F_25 ) ;
V_71 [ 0 ] . V_66 . V_64 = ( V_72 * ) & V_68 ;
V_71 [ 1 ] . type = V_65 ;
V_71 [ 1 ] . V_66 . V_54 = 512 ;
V_71 [ 1 ] . V_66 . V_64 = ( V_72 * ) V_8 -> V_15 . V_73 [ 0 ] . V_74 ;
V_71 [ 2 ] . type = V_65 ;
V_71 [ 2 ] . V_66 . V_54 = 512 ;
V_71 [ 2 ] . V_66 . V_64 = ( V_72 * ) V_8 -> V_15 . V_73 [ 1 ] . V_74 ;
V_70 . V_75 = 3 ;
V_70 . V_64 = V_71 ;
V_58 = F_33 ( F_4 ( & V_8 -> V_6 ) , L_7 ,
& V_70 , NULL ) ;
if ( V_58 == V_62 )
return - V_61 ;
if ( F_34 ( V_58 ) ) {
F_35 ( V_8 , L_8 ,
V_58 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_76 * * V_77 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_4 V_58 ;
struct V_52 V_53 ;
union V_56 * V_57 ;
int V_59 = 0 ;
if ( V_2 -> V_3 ) {
V_57 = V_2 -> V_3 ;
goto V_78;
}
V_53 . V_54 = V_55 ;
V_53 . V_64 = NULL ;
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_9 ,
V_79 , V_8 -> V_35 ) ;
V_58 = F_33 ( F_3 ( V_2 ) , L_10 , NULL ,
& V_53 ) ;
V_57 = V_2 -> V_3 = V_53 . V_64 ;
if ( F_34 ( V_58 ) ) {
if ( V_58 != V_62 ) {
F_40 ( V_2 , L_11 ,
V_58 ) ;
V_59 = - V_60 ;
}
goto V_63;
}
if ( ! V_53 . V_54 || ! V_53 . V_64 ) {
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_12 ,
V_79 ,
( unsigned long long ) V_53 . V_54 ,
V_53 . V_64 ) ;
V_59 = - V_60 ;
goto V_63;
}
if ( V_57 -> type != V_65 ) {
F_40 ( V_2 , L_13 ,
V_57 -> type ) ;
V_59 = - V_60 ;
goto V_63;
}
if ( V_57 -> V_66 . V_54 % V_80 ) {
F_40 ( V_2 , L_14 ,
V_57 -> V_66 . V_54 ) ;
V_59 = - V_60 ;
goto V_63;
}
V_78:
V_59 = V_57 -> V_66 . V_54 / V_80 ;
if ( V_77 ) {
* V_77 = ( void * ) V_57 -> V_66 . V_64 ;
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_15 ,
V_79 , * V_77 , V_59 ) ;
}
return V_59 ;
V_63:
F_1 ( V_2 ) ;
return V_59 ;
}
unsigned long F_41 ( struct V_1 * V_2 ,
const struct F_25 * V_51 )
{
unsigned long V_81 = 0 ;
unsigned int type ;
int V_82 ;
V_72 V_83 ;
V_82 = V_2 -> V_45 ;
if ( ! ( V_51 -> V_4 & 0x10 ) )
V_82 = 0 ;
V_83 = F_42 ( V_84 , V_51 -> V_85 [ V_82 ] . V_86 ) ;
V_81 |= F_43 ( V_83 ) ;
if ( ! ( V_51 -> V_4 & ( 1 << ( 2 * V_82 ) ) ) )
type = V_87 ;
else
type = V_88 ;
V_83 = F_42 ( type , V_51 -> V_85 [ V_82 ] . V_89 ) ;
V_81 |= F_43 ( V_83 ) ;
return V_81 ;
}
int F_44 ( struct V_7 * V_8 , const struct F_25 * V_51 )
{
struct V_1 * V_2 ;
F_7 (dev, &ap->link, ENABLED) {
unsigned long V_81 , V_90 ;
V_81 = F_41 ( V_2 , V_51 ) ;
F_45 ( V_81 , NULL , NULL , & V_90 ) ;
if ( V_90 & ~ V_91 )
return 1 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
const struct V_76 * V_77 ,
struct V_92 * V_93 )
{
F_47 ( V_2 , V_93 ) ;
V_93 -> V_4 |= V_94 | V_95 ;
V_93 -> V_96 = V_97 ;
V_93 -> V_98 = V_77 -> V_93 [ 0 ] ;
V_93 -> V_99 = V_77 -> V_93 [ 1 ] ;
V_93 -> V_100 = V_77 -> V_93 [ 2 ] ;
V_93 -> V_101 = V_77 -> V_93 [ 3 ] ;
V_93 -> V_102 = V_77 -> V_93 [ 4 ] ;
V_93 -> V_73 = V_77 -> V_93 [ 5 ] ;
V_93 -> V_103 = V_77 -> V_93 [ 6 ] ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_92 * V_93 ,
const struct V_92 * V_104 )
{
if ( V_2 -> V_105 & V_106 ) {
if ( V_93 -> V_103 == V_107 &&
V_93 -> V_98 == V_108 )
return 1 ;
}
if ( V_2 -> V_105 & V_109 ) {
if ( V_93 -> V_103 == V_110 &&
V_93 -> V_98 == V_111 )
return 1 ;
if ( V_93 -> V_103 == V_112 )
return 1 ;
if ( ( ! V_104 || V_104 -> V_103 != V_113 ) &&
V_93 -> V_103 == V_114 &&
( V_93 -> V_98 == V_115 ||
V_93 -> V_98 == V_116 ) )
return 1 ;
}
if ( V_93 -> V_103 == V_107 &&
V_93 -> V_98 == V_117 ) {
if ( V_2 -> V_105 & V_118 &&
V_93 -> V_99 == V_119 )
return 1 ;
if ( V_2 -> V_105 & V_120 &&
( V_93 -> V_99 == V_121 ||
V_93 -> V_99 == V_122 ) )
return 1 ;
if ( V_2 -> V_105 & V_123 &&
V_93 -> V_99 == V_124 )
return 1 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
const struct V_76 * V_77 ,
const struct V_76 * V_125 )
{
struct V_92 * V_126 = NULL ;
struct V_92 V_93 , V_104 , V_127 ;
unsigned int V_128 ;
const char * V_129 ;
const char * V_130 ;
char V_131 [ 60 ] ;
int V_59 ;
if ( ( V_77 -> V_93 [ 0 ] == 0 ) && ( V_77 -> V_93 [ 1 ] == 0 ) && ( V_77 -> V_93 [ 2 ] == 0 )
&& ( V_77 -> V_93 [ 3 ] == 0 ) && ( V_77 -> V_93 [ 4 ] == 0 ) && ( V_77 -> V_93 [ 5 ] == 0 )
&& ( V_77 -> V_93 [ 6 ] == 0 ) )
return 0 ;
F_46 ( V_2 , V_77 , & V_93 ) ;
if ( V_125 ) {
F_46 ( V_2 , V_125 , & V_104 ) ;
V_126 = & V_104 ;
}
if ( ! F_48 ( V_2 , & V_93 , V_126 ) ) {
V_127 = V_93 ;
V_128 = F_50 ( V_2 , & V_127 , NULL ,
V_132 , NULL , 0 , 0 ) ;
switch ( V_128 ) {
case 0 :
V_129 = V_133 ;
snprintf ( V_131 , sizeof( V_131 ) , L_16 ) ;
V_59 = 1 ;
break;
case V_134 :
V_129 = V_135 ;
snprintf ( V_131 , sizeof( V_131 ) ,
L_17 ,
V_127 . V_103 , V_127 . V_98 ) ;
V_59 = 0 ;
break;
default:
V_129 = V_136 ;
snprintf ( V_131 , sizeof( V_131 ) ,
L_18 ,
V_128 , V_127 . V_103 , V_127 . V_98 ) ;
V_59 = - V_137 ;
break;
}
} else {
V_129 = V_135 ;
snprintf ( V_131 , sizeof( V_131 ) , L_19 ) ;
V_59 = 0 ;
}
V_130 = F_51 ( V_93 . V_103 ) ;
F_52 ( V_2 , V_129 ,
L_20 ,
V_93 . V_103 , V_93 . V_98 , V_93 . V_99 , V_93 . V_100 ,
V_93 . V_101 , V_93 . V_102 , V_93 . V_73 ,
( V_130 ? V_130 : L_21 ) , V_131 ) ;
return V_59 ;
}
static int F_53 ( struct V_1 * V_2 , int * V_138 )
{
struct V_76 * V_77 = NULL , * V_139 = NULL ;
int V_140 , V_48 , V_59 ;
V_59 = F_37 ( V_2 , & V_77 ) ;
if ( V_59 < 0 )
return V_59 ;
V_140 = V_59 ;
for ( V_48 = 0 ; V_48 < V_140 ; V_48 ++ , V_77 ++ ) {
V_59 = F_49 ( V_2 , V_77 , V_139 ) ;
if ( V_59 < 0 )
break;
if ( V_59 ) {
( * V_138 ) ++ ;
V_139 = V_77 ;
}
}
F_1 ( V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
T_4 V_58 ;
struct V_69 V_70 ;
union V_56 V_71 [ 1 ] ;
if ( F_38 ( V_8 ) )
F_39 ( V_2 , L_22 ,
V_79 , V_2 -> V_45 , V_8 -> V_35 ) ;
V_70 . V_75 = 1 ;
V_70 . V_64 = V_71 ;
V_71 [ 0 ] . type = V_65 ;
V_71 [ 0 ] . V_66 . V_54 = sizeof( V_2 -> V_74 [ 0 ] ) * V_141 ;
V_71 [ 0 ] . V_66 . V_64 = ( V_72 * ) V_2 -> V_74 ;
F_55 ( V_2 -> V_74 , V_141 ) ;
V_58 = F_33 ( F_3 ( V_2 ) , L_23 , & V_70 ,
NULL ) ;
F_55 ( V_2 -> V_74 , V_141 ) ;
if ( V_58 == V_62 )
return - V_61 ;
if ( F_34 ( V_58 ) ) {
F_40 ( V_2 , L_24 , V_58 ) ;
return - V_137 ;
}
return 0 ;
}
int F_56 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_57 ( struct V_7 * V_8 )
{
const struct F_25 * V_51 = F_31 ( V_8 ) ;
struct V_1 * V_2 ;
if ( F_4 ( & V_8 -> V_6 ) && V_51 ) {
F_32 ( V_8 , V_51 ) ;
F_7 (dev, &ap->link, ALL) {
F_1 ( V_2 ) ;
if ( F_58 ( V_2 ) &&
F_37 ( V_2 , NULL ) >= 0 )
V_2 -> V_4 |= V_142 ;
}
} else {
F_7 (dev, &ap->link, ALL) {
F_1 ( V_2 ) ;
if ( F_58 ( V_2 ) )
V_2 -> V_4 |= V_142 ;
}
}
}
static int F_59 ( struct V_1 * V_2 , bool V_143 )
{
int V_144 = V_145 ;
if ( ! V_143 )
goto V_146;
if ( V_2 -> V_147 == V_148 &&
! ( F_60 ( V_2 ) && F_61 ( V_2 ) ) )
V_144 = V_149 ;
V_146:
return F_62 ( & V_2 -> V_6 , NULL , V_144 ) ;
}
static void F_63 ( struct V_7 * V_8 , T_5 V_150 )
{
bool V_143 = F_64 ( V_150 ) ;
struct V_1 * V_2 ;
T_1 V_22 ;
int V_151 ;
F_7 (dev, &ap->link, ENABLED) {
V_22 = F_3 ( V_2 ) ;
if ( ! V_22 )
continue;
if ( ! ( V_150 . V_12 & V_152 ) ) {
V_151 = F_59 ( V_2 , V_143 ) ;
if ( V_151 == V_153 )
continue;
if ( V_143 && F_60 ( V_2 ) &&
V_151 == V_145 )
F_65 ( V_2 ) ;
F_66 ( V_22 , V_151 ) ;
} else {
if ( V_143 && F_60 ( V_2 ) )
F_67 ( V_2 ) ;
F_66 ( V_22 , V_153 ) ;
}
}
}
static void F_68 ( struct V_7 * V_8 , T_5 V_150 )
{
struct V_1 * V_2 ;
T_1 V_40 ;
V_40 = F_4 ( & V_8 -> V_6 ) ;
if ( ! V_40 )
return;
if ( V_150 . V_12 & V_152 )
F_66 ( V_40 , V_153 ) ;
F_7 (dev, &ap->link, ENABLED) {
T_1 V_154 = F_3 ( V_2 ) ;
if ( ! V_154 )
continue;
F_66 ( V_154 , V_150 . V_12 & V_152 ?
V_153 : V_145 ) ;
}
if ( ! ( V_150 . V_12 & V_152 ) )
F_66 ( V_40 , V_145 ) ;
}
void F_69 ( struct V_7 * V_8 , T_5 V_150 )
{
if ( V_8 -> V_4 & V_34 )
F_63 ( V_8 , V_150 ) ;
else
F_68 ( V_8 , V_150 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_15 -> V_8 ;
struct V_155 * V_156 = & V_8 -> V_15 . V_157 ;
int V_158 = V_8 -> V_4 & V_34 ;
int V_138 = 0 ;
int V_59 ;
if ( ! F_3 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_4 & V_142 ) &&
! ( V_158 && ( V_156 -> V_48 . V_4 & V_159 ) ) )
return 0 ;
if ( V_158 ) {
V_59 = F_54 ( V_2 ) ;
if ( V_59 && V_59 != - V_61 )
goto V_160;
}
V_59 = F_53 ( V_2 , & V_138 ) ;
if ( V_59 )
goto V_160;
V_2 -> V_4 &= ~ V_142 ;
if ( V_138 ) {
V_59 = F_71 ( V_2 , 0 ) ;
if ( V_59 < 0 ) {
F_72 ( V_2 ,
L_25 ) ;
return V_59 ;
}
}
return 0 ;
V_160:
if ( V_59 == - V_60 && ! V_138 && ! ( V_8 -> V_37 & V_161 ) )
return 0 ;
if ( ! ( V_2 -> V_4 & V_162 ) ) {
V_2 -> V_4 |= V_162 ;
return V_59 ;
}
V_2 -> V_4 |= V_5 ;
F_40 ( V_2 , L_26 ) ;
if ( ! V_138 && ! ( V_8 -> V_37 & V_161 ) )
return 0 ;
return V_59 ;
}
void F_73 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
