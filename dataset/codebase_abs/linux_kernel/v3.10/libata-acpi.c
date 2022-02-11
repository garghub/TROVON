static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == & V_4 ) ;
}
static void F_2 ( struct V_5 * V_2 )
{
F_3 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
T_1 F_4 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 & V_10 )
return NULL ;
return V_8 -> V_11 ?
F_5 ( & V_8 -> V_11 -> V_12 ) : NULL ;
}
T_1 F_6 ( struct V_5 * V_2 )
{
T_2 V_13 ;
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
if ( V_15 || V_2 -> V_9 & V_16 )
return NULL ;
if ( V_8 -> V_9 & V_10 ) {
if ( ! F_7 ( V_8 ) )
V_13 = F_8 ( V_8 -> V_17 , V_18 ) ;
else
V_13 = F_8 ( V_8 -> V_17 , V_2 -> V_14 -> V_19 ) ;
return F_9 ( F_5 ( V_8 -> V_20 -> V_2 ) , V_13 ) ;
} else
return F_9 ( F_4 ( V_8 ) , V_2 -> V_21 ) ;
}
static void F_10 ( struct V_7 * V_8 , struct V_5 * V_2 )
{
if ( V_2 )
V_2 -> V_9 |= V_22 ;
else {
struct V_23 * V_24 ;
struct V_5 * V_25 ;
F_11 (tlink, ap, EDGE)
F_12 (tdev, tlink, ALL)
V_25 -> V_9 |= V_22 ;
}
F_13 ( V_8 ) ;
}
static void F_14 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_3 V_26 )
{
struct V_27 * V_28 = & V_8 -> V_14 . V_29 ;
int V_30 = 0 ;
unsigned long V_9 ;
F_15 ( V_8 -> V_31 , V_9 ) ;
switch ( V_26 ) {
case V_32 :
case V_33 :
F_16 ( V_28 , L_1 ) ;
F_17 ( V_28 ) ;
F_18 ( V_8 ) ;
break;
case V_34 :
F_16 ( V_28 , L_1 ) ;
F_10 ( V_8 , V_2 ) ;
V_30 = 1 ;
break;
}
F_19 ( V_8 -> V_31 , V_9 ) ;
if ( V_30 ) {
F_20 ( V_8 ) ;
F_21 ( & V_8 -> V_35 . V_36 ) ;
}
}
static void F_22 ( T_1 V_37 , T_3 V_26 , void * V_38 )
{
struct V_5 * V_2 = V_38 ;
F_14 ( V_2 -> V_14 -> V_8 , V_2 , V_26 ) ;
}
static void F_23 ( T_1 V_37 , T_3 V_26 , void * V_38 )
{
struct V_7 * V_8 = V_38 ;
F_14 ( V_8 , NULL , V_26 ) ;
}
static void F_24 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_3 V_26 )
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
snprintf ( V_41 , 20 , L_2 , V_26 ) ;
F_25 ( V_40 , V_45 , V_42 ) ;
}
}
static void F_26 ( T_1 V_37 , T_3 V_26 , void * V_38 )
{
F_24 ( V_38 , NULL , V_26 ) ;
}
static void F_27 ( T_1 V_37 , T_3 V_26 , void * V_38 )
{
struct V_5 * V_2 = V_38 ;
F_24 ( V_2 -> V_14 -> V_8 , V_2 , V_26 ) ;
}
void F_28 ( struct V_46 * V_20 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_20 -> V_48 ; V_47 ++ ) {
struct V_7 * V_8 = V_20 -> V_49 [ V_47 ] ;
T_1 V_37 ;
struct V_5 * V_2 ;
if ( ! V_8 )
continue;
V_37 = F_4 ( V_8 ) ;
if ( V_37 ) {
F_29 ( V_37 ,
& V_50 , V_8 ,
NULL , NULL ) ;
}
F_12 (dev, &ap->link, ALL) {
V_37 = F_6 ( V_2 ) ;
if ( ! V_37 )
continue;
F_29 ( V_37 ,
& V_51 ,
V_2 , NULL , NULL ) ;
}
}
}
void F_30 ( struct V_46 * V_20 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_20 -> V_48 ; V_47 ++ ) {
struct V_7 * V_8 = V_20 -> V_49 [ V_47 ] ;
const struct V_52 * V_53 = F_31 ( V_8 ) ;
if ( F_4 ( V_8 ) && V_53 )
F_32 ( V_8 , V_53 ) ;
}
}
static int F_33 ( struct V_7 * V_8 , T_1 V_37 ,
struct V_52 * V_53 )
{
struct V_54 V_55 = { . V_56 = V_57 } ;
union V_58 * V_59 ;
T_4 V_60 ;
int V_61 = 0 ;
V_60 = F_34 ( V_37 , L_3 , NULL , & V_55 ) ;
V_61 = - V_62 ;
if ( V_60 == V_63 )
goto V_64;
V_61 = - V_65 ;
if ( F_35 ( V_60 ) ) {
F_36 ( V_8 , L_4 ,
V_60 ) ;
goto V_64;
}
V_59 = V_55 . V_66 ;
if ( V_59 -> type != V_67 ) {
F_37 ( V_8 , L_5 ,
V_59 -> type ) ;
goto V_64;
}
if ( V_59 -> V_68 . V_56 != sizeof( struct V_52 ) ) {
F_36 ( V_8 , L_6 ,
V_59 -> V_68 . V_56 ) ;
goto V_64;
}
memcpy ( V_53 , V_59 -> V_68 . V_66 , sizeof( struct V_52 ) ) ;
V_61 = 0 ;
V_64:
F_3 ( V_55 . V_66 ) ;
return V_61 ;
}
int V_52 ( struct V_7 * V_8 , struct V_52 * V_53 )
{
if ( F_4 ( V_8 ) )
return F_33 ( V_8 , F_4 ( V_8 ) , V_53 ) ;
else
return - V_65 ;
}
int F_32 ( struct V_7 * V_8 , const struct V_52 * V_69 )
{
T_4 V_60 ;
struct V_52 V_70 = * V_69 ;
struct V_71 V_72 ;
union V_58 V_73 [ 3 ] ;
V_73 [ 0 ] . type = V_67 ;
V_73 [ 0 ] . V_68 . V_56 = sizeof( struct V_52 ) ;
V_73 [ 0 ] . V_68 . V_66 = ( V_74 * ) & V_70 ;
V_73 [ 1 ] . type = V_67 ;
V_73 [ 1 ] . V_68 . V_56 = 512 ;
V_73 [ 1 ] . V_68 . V_66 = ( V_74 * ) V_8 -> V_14 . V_1 [ 0 ] . V_75 ;
V_73 [ 2 ] . type = V_67 ;
V_73 [ 2 ] . V_68 . V_56 = 512 ;
V_73 [ 2 ] . V_68 . V_66 = ( V_74 * ) V_8 -> V_14 . V_1 [ 1 ] . V_75 ;
V_72 . V_76 = 3 ;
V_72 . V_66 = V_73 ;
V_60 = F_34 ( F_4 ( V_8 ) , L_7 , & V_72 ,
NULL ) ;
if ( V_60 == V_63 )
return - V_62 ;
if ( F_35 ( V_60 ) ) {
F_36 ( V_8 , L_8 ,
V_60 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_38 ( struct V_5 * V_2 , struct V_77 * * V_78 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_4 V_60 ;
struct V_54 V_55 ;
union V_58 * V_59 ;
int V_61 = 0 ;
if ( V_2 -> V_6 ) {
V_59 = V_2 -> V_6 ;
goto V_79;
}
V_55 . V_56 = V_57 ;
V_55 . V_66 = NULL ;
if ( F_39 ( V_8 ) )
F_40 ( V_2 , L_9 ,
V_80 , V_8 -> V_17 ) ;
V_60 = F_34 ( F_6 ( V_2 ) , L_10 , NULL ,
& V_55 ) ;
V_59 = V_2 -> V_6 = V_55 . V_66 ;
if ( F_35 ( V_60 ) ) {
if ( V_60 != V_63 ) {
F_41 ( V_2 , L_11 ,
V_60 ) ;
V_61 = - V_65 ;
}
goto V_64;
}
if ( ! V_55 . V_56 || ! V_55 . V_66 ) {
if ( F_39 ( V_8 ) )
F_40 ( V_2 , L_12 ,
V_80 ,
( unsigned long long ) V_55 . V_56 ,
V_55 . V_66 ) ;
V_61 = - V_65 ;
goto V_64;
}
if ( V_59 -> type != V_67 ) {
F_41 ( V_2 , L_13 ,
V_59 -> type ) ;
V_61 = - V_65 ;
goto V_64;
}
if ( V_59 -> V_68 . V_56 % V_81 ) {
F_41 ( V_2 , L_14 ,
V_59 -> V_68 . V_56 ) ;
V_61 = - V_65 ;
goto V_64;
}
V_79:
V_61 = V_59 -> V_68 . V_56 / V_81 ;
if ( V_78 ) {
* V_78 = ( void * ) V_59 -> V_68 . V_66 ;
if ( F_39 ( V_8 ) )
F_40 ( V_2 , L_15 ,
V_80 , * V_78 , V_61 ) ;
}
return V_61 ;
V_64:
F_2 ( V_2 ) ;
return V_61 ;
}
unsigned long F_42 ( struct V_5 * V_2 ,
const struct V_52 * V_53 )
{
unsigned long V_82 = 0 ;
unsigned int type ;
int V_83 ;
V_74 V_84 ;
V_83 = V_2 -> V_21 ;
if ( ! ( V_53 -> V_9 & 0x10 ) )
V_83 = 0 ;
V_84 = F_43 ( V_85 , V_53 -> V_86 [ V_83 ] . V_87 ) ;
V_82 |= F_44 ( V_84 ) ;
if ( ! ( V_53 -> V_9 & ( 1 << ( 2 * V_83 ) ) ) )
type = V_88 ;
else
type = V_89 ;
V_84 = F_43 ( type , V_53 -> V_86 [ V_83 ] . V_90 ) ;
V_82 |= F_44 ( V_84 ) ;
return V_82 ;
}
int F_45 ( struct V_7 * V_8 , const struct V_52 * V_53 )
{
struct V_5 * V_2 ;
F_12 (dev, &ap->link, ENABLED) {
unsigned long V_82 , V_91 ;
V_82 = F_42 ( V_2 , V_53 ) ;
F_46 ( V_82 , NULL , NULL , & V_91 ) ;
if ( V_91 & ~ V_92 )
return 1 ;
}
return 0 ;
}
static void F_47 ( struct V_5 * V_2 ,
const struct V_77 * V_78 ,
struct V_93 * V_94 )
{
F_48 ( V_2 , V_94 ) ;
V_94 -> V_9 |= V_95 | V_96 ;
V_94 -> V_97 = V_98 ;
V_94 -> V_99 = V_78 -> V_94 [ 0 ] ;
V_94 -> V_100 = V_78 -> V_94 [ 1 ] ;
V_94 -> V_101 = V_78 -> V_94 [ 2 ] ;
V_94 -> V_102 = V_78 -> V_94 [ 3 ] ;
V_94 -> V_103 = V_78 -> V_94 [ 4 ] ;
V_94 -> V_1 = V_78 -> V_94 [ 5 ] ;
V_94 -> V_104 = V_78 -> V_94 [ 6 ] ;
}
static int F_49 ( struct V_5 * V_2 ,
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
static int F_50 ( struct V_5 * V_2 ,
const struct V_77 * V_78 ,
const struct V_77 * V_126 )
{
struct V_93 * V_127 = NULL ;
struct V_93 V_94 , V_105 , V_128 ;
unsigned int V_129 ;
const char * V_130 ;
const char * V_131 ;
char V_132 [ 60 ] ;
int V_61 ;
if ( ( V_78 -> V_94 [ 0 ] == 0 ) && ( V_78 -> V_94 [ 1 ] == 0 ) && ( V_78 -> V_94 [ 2 ] == 0 )
&& ( V_78 -> V_94 [ 3 ] == 0 ) && ( V_78 -> V_94 [ 4 ] == 0 ) && ( V_78 -> V_94 [ 5 ] == 0 )
&& ( V_78 -> V_94 [ 6 ] == 0 ) )
return 0 ;
F_47 ( V_2 , V_78 , & V_94 ) ;
if ( V_126 ) {
F_47 ( V_2 , V_126 , & V_105 ) ;
V_127 = & V_105 ;
}
if ( ! F_49 ( V_2 , & V_94 , V_127 ) ) {
V_128 = V_94 ;
V_129 = F_51 ( V_2 , & V_128 , NULL ,
V_133 , NULL , 0 , 0 ) ;
switch ( V_129 ) {
case 0 :
V_130 = V_134 ;
snprintf ( V_132 , sizeof( V_132 ) , L_16 ) ;
V_61 = 1 ;
break;
case V_135 :
V_130 = V_136 ;
snprintf ( V_132 , sizeof( V_132 ) ,
L_17 ,
V_128 . V_104 , V_128 . V_99 ) ;
V_61 = 0 ;
break;
default:
V_130 = V_137 ;
snprintf ( V_132 , sizeof( V_132 ) ,
L_18 ,
V_129 , V_128 . V_104 , V_128 . V_99 ) ;
V_61 = - V_138 ;
break;
}
} else {
V_130 = V_136 ;
snprintf ( V_132 , sizeof( V_132 ) , L_19 ) ;
V_61 = 0 ;
}
V_131 = F_52 ( V_94 . V_104 ) ;
F_53 ( V_2 , V_130 ,
L_20 ,
V_94 . V_104 , V_94 . V_99 , V_94 . V_100 , V_94 . V_101 ,
V_94 . V_102 , V_94 . V_103 , V_94 . V_1 ,
( V_131 ? V_131 : L_21 ) , V_132 ) ;
return V_61 ;
}
static int F_54 ( struct V_5 * V_2 , int * V_139 )
{
struct V_77 * V_78 = NULL , * V_140 = NULL ;
int V_141 , V_47 , V_61 ;
V_61 = F_38 ( V_2 , & V_78 ) ;
if ( V_61 < 0 )
return V_61 ;
V_141 = V_61 ;
for ( V_47 = 0 ; V_47 < V_141 ; V_47 ++ , V_78 ++ ) {
V_61 = F_50 ( V_2 , V_78 , V_140 ) ;
if ( V_61 < 0 )
break;
if ( V_61 ) {
( * V_139 ) ++ ;
V_140 = V_78 ;
}
}
F_2 ( V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_4 V_60 ;
struct V_71 V_72 ;
union V_58 V_73 [ 1 ] ;
if ( F_39 ( V_8 ) )
F_40 ( V_2 , L_22 ,
V_80 , V_2 -> V_21 , V_8 -> V_17 ) ;
V_72 . V_76 = 1 ;
V_72 . V_66 = V_73 ;
V_73 [ 0 ] . type = V_67 ;
V_73 [ 0 ] . V_68 . V_56 = sizeof( V_2 -> V_75 [ 0 ] ) * V_142 ;
V_73 [ 0 ] . V_68 . V_66 = ( V_74 * ) V_2 -> V_75 ;
F_56 ( V_2 -> V_75 , V_142 ) ;
V_60 = F_34 ( F_6 ( V_2 ) , L_23 , & V_72 ,
NULL ) ;
F_56 ( V_2 -> V_75 , V_142 ) ;
if ( V_60 == V_63 )
return - V_62 ;
if ( F_35 ( V_60 ) ) {
F_41 ( V_2 , L_24 , V_60 ) ;
return - V_138 ;
}
return 0 ;
}
int F_57 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_58 ( struct V_7 * V_8 )
{
const struct V_52 * V_53 = F_31 ( V_8 ) ;
struct V_5 * V_2 ;
if ( F_4 ( V_8 ) && V_53 ) {
F_32 ( V_8 , V_53 ) ;
F_12 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_59 ( V_2 ) &&
F_38 ( V_2 , NULL ) >= 0 )
V_2 -> V_9 |= V_143 ;
}
} else {
F_12 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_59 ( V_2 ) )
V_2 -> V_9 |= V_143 ;
}
}
}
static int F_60 ( struct V_5 * V_2 , bool V_144 )
{
int V_145 = V_146 ;
if ( ! V_144 )
goto V_147;
if ( V_2 -> V_148 == V_149 &&
! ( F_61 ( V_2 ) && F_62 ( V_2 ) ) )
V_145 = V_150 ;
V_147:
return F_63 ( & V_2 -> V_43 -> V_44 ,
NULL , V_145 ) ;
}
static void F_64 ( struct V_7 * V_8 , T_5 V_151 )
{
bool V_144 = F_65 ( V_151 ) ;
struct V_5 * V_2 ;
T_1 V_37 ;
int V_152 ;
F_12 (dev, &ap->link, ENABLED) {
V_37 = F_6 ( V_2 ) ;
if ( ! V_37 )
continue;
if ( ! ( V_151 . V_26 & V_153 ) ) {
V_152 = F_60 ( V_2 , V_144 ) ;
if ( V_152 == V_154 )
continue;
if ( V_144 && F_61 ( V_2 ) &&
V_152 == V_146 )
F_66 ( V_2 ) ;
F_67 ( V_37 , V_152 ) ;
} else {
if ( V_144 && F_61 ( V_2 ) )
F_68 ( V_2 ) ;
F_67 ( V_37 , V_154 ) ;
}
}
}
static void F_69 ( struct V_7 * V_8 , T_5 V_151 )
{
struct V_5 * V_2 ;
T_1 V_155 ;
V_155 = F_4 ( V_8 ) ;
if ( ! V_155 )
return;
if ( V_151 . V_26 & V_153 )
F_67 ( V_155 , V_154 ) ;
F_12 (dev, &ap->link, ENABLED) {
T_1 V_156 = F_6 ( V_2 ) ;
if ( ! V_156 )
continue;
F_67 ( V_156 , V_151 . V_26 & V_153 ?
V_154 : V_157 ) ;
}
if ( ! ( V_151 . V_26 & V_153 ) )
F_67 ( V_155 , V_157 ) ;
}
void F_70 ( struct V_7 * V_8 , T_5 V_151 )
{
if ( V_8 -> V_9 & V_10 )
F_64 ( V_8 , V_151 ) ;
else
F_69 ( V_8 , V_151 ) ;
}
int F_71 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
struct V_158 * V_159 = & V_8 -> V_14 . V_160 ;
int V_161 = V_8 -> V_9 & V_10 ;
int V_139 = 0 ;
int V_61 ;
if ( ! F_6 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_143 ) &&
! ( V_161 && ( V_159 -> V_47 . V_9 & V_162 ) ) )
return 0 ;
if ( V_161 ) {
V_61 = F_55 ( V_2 ) ;
if ( V_61 && V_61 != - V_62 )
goto V_163;
}
V_61 = F_54 ( V_2 , & V_139 ) ;
if ( V_61 )
goto V_163;
V_2 -> V_9 &= ~ V_143 ;
if ( V_139 ) {
V_61 = F_72 ( V_2 , 0 ) ;
if ( V_61 < 0 ) {
F_73 ( V_2 ,
L_25 ) ;
return V_61 ;
}
}
return 0 ;
V_163:
if ( V_61 == - V_65 && ! V_139 && ! ( V_8 -> V_164 & V_165 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_166 ) ) {
V_2 -> V_9 |= V_166 ;
return V_61 ;
}
V_2 -> V_9 |= V_16 ;
F_41 ( V_2 , L_26 ) ;
if ( ! V_139 && ! ( V_8 -> V_164 & V_165 ) )
return 0 ;
return V_61 ;
}
void F_74 ( struct V_5 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_75 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_25 . V_167 ;
struct V_168 * V_169 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_169 = F_76 ( V_2 ) ;
if ( ( V_169 -> V_148 >> 8 ) != V_170 &&
( V_169 -> V_148 >> 8 ) != V_171 )
return 0 ;
return 1 ;
}
static int F_77 ( struct V_7 * V_8 , T_1 * V_37 )
{
if ( V_15 || V_8 -> V_9 & V_10 )
return - V_172 ;
* V_37 = F_9 ( F_5 ( V_8 -> V_25 . V_167 ) ,
V_8 -> V_17 ) ;
if ( ! * V_37 )
return - V_172 ;
if ( F_33 ( V_8 , * V_37 , & V_8 -> V_173 ) == 0 )
V_8 -> V_164 |= V_174 ;
return 0 ;
}
static int F_78 ( struct V_7 * V_8 , struct V_175 * V_43 ,
T_1 * V_37 )
{
struct V_5 * V_176 ;
if ( V_8 -> V_9 & V_10 ) {
if ( ! F_7 ( V_8 ) )
V_176 = & V_8 -> V_14 . V_1 [ V_43 -> V_75 ] ;
else
V_176 = & V_8 -> V_177 [ V_43 -> V_178 ] . V_1 [ V_43 -> V_75 ] ;
}
else {
V_176 = & V_8 -> V_14 . V_1 [ V_43 -> V_75 ] ;
}
* V_37 = F_6 ( V_176 ) ;
if ( ! * V_37 )
return - V_172 ;
return 0 ;
}
static int F_79 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_179 ;
}
static struct V_7 * F_80 ( struct V_1 * V_2 )
{
while ( ! F_79 ( V_2 ) ) {
if ( ! V_2 -> V_167 )
return NULL ;
V_2 = V_2 -> V_167 ;
}
return F_81 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 , T_1 * V_37 )
{
struct V_7 * V_8 = F_80 ( V_2 ) ;
if ( ! V_8 )
return - V_172 ;
if ( ! F_75 ( V_8 ) )
return - V_172 ;
if ( F_83 ( V_2 ) )
return F_77 ( V_8 , V_37 ) ;
else if ( F_84 ( V_2 ) ) {
struct V_175 * V_43 = F_85 ( V_2 ) ;
return F_78 ( V_8 , V_43 , V_37 ) ;
} else
return - V_172 ;
}
int F_86 ( void )
{
return F_87 ( & V_180 ) ;
}
void F_88 ( void )
{
F_89 ( & V_180 ) ;
}
