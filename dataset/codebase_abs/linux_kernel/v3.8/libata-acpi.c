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
return F_5 ( F_6 ( V_8 -> V_11 -> V_2 ) , V_8 -> V_12 ) ;
}
T_1 F_7 ( struct V_5 * V_2 )
{
T_2 V_13 ;
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
if ( V_2 -> V_9 & V_15 )
return NULL ;
if ( V_8 -> V_9 & V_10 ) {
if ( ! F_8 ( V_8 ) )
V_13 = F_9 ( V_8 -> V_12 , V_16 ) ;
else
V_13 = F_9 ( V_8 -> V_12 , V_2 -> V_14 -> V_17 ) ;
return F_5 ( F_6 ( V_8 -> V_11 -> V_2 ) , V_13 ) ;
} else
return F_5 ( F_4 ( V_8 ) , V_2 -> V_18 ) ;
}
static void F_10 ( struct V_7 * V_8 , struct V_5 * V_2 )
{
if ( V_2 )
V_2 -> V_9 |= V_19 ;
else {
struct V_20 * V_21 ;
struct V_5 * V_22 ;
F_11 (tlink, ap, EDGE)
F_12 (tdev, tlink, ALL)
V_22 -> V_9 |= V_19 ;
}
F_13 ( V_8 ) ;
}
static void F_14 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_3 V_23 )
{
struct V_24 * V_25 = & V_8 -> V_14 . V_26 ;
int V_27 = 0 ;
unsigned long V_9 ;
F_15 ( V_8 -> V_28 , V_9 ) ;
switch ( V_23 ) {
case V_29 :
case V_30 :
F_16 ( V_25 , L_1 ) ;
F_17 ( V_25 ) ;
F_18 ( V_8 ) ;
break;
case V_31 :
F_16 ( V_25 , L_1 ) ;
F_10 ( V_8 , V_2 ) ;
V_27 = 1 ;
break;
}
F_19 ( V_8 -> V_28 , V_9 ) ;
if ( V_27 )
F_20 ( V_8 ) ;
}
static void F_21 ( T_1 V_32 , T_3 V_23 , void * V_33 )
{
struct V_5 * V_2 = V_33 ;
F_14 ( V_2 -> V_14 -> V_8 , V_2 , V_23 ) ;
}
static void F_22 ( T_1 V_32 , T_3 V_23 , void * V_33 )
{
struct V_7 * V_8 = V_33 ;
F_14 ( V_8 , NULL , V_23 ) ;
}
static void F_23 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_3 V_23 )
{
struct V_34 * V_35 = NULL ;
char V_36 [ 20 ] ;
char * V_37 [] = { V_36 , NULL } ;
if ( V_2 ) {
if ( V_2 -> V_38 )
V_35 = & V_2 -> V_38 -> V_39 . V_35 ;
} else
V_35 = & V_8 -> V_2 -> V_35 ;
if ( V_35 ) {
snprintf ( V_36 , 20 , L_2 , V_23 ) ;
F_24 ( V_35 , V_40 , V_37 ) ;
}
}
static void F_25 ( T_1 V_32 , T_3 V_23 , void * V_33 )
{
F_23 ( V_33 , NULL , V_23 ) ;
}
static void F_26 ( T_1 V_32 , T_3 V_23 , void * V_33 )
{
struct V_5 * V_2 = V_33 ;
F_23 ( V_2 -> V_14 -> V_8 , V_2 , V_23 ) ;
}
void F_27 ( struct V_41 * V_11 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_11 -> V_43 ; V_42 ++ ) {
struct V_7 * V_8 = V_11 -> V_44 [ V_42 ] ;
const struct V_45 * V_46 = F_28 ( V_8 ) ;
if ( F_4 ( V_8 ) && V_46 )
F_29 ( V_8 , V_46 ) ;
}
}
int V_45 ( struct V_7 * V_8 , struct V_45 * V_46 )
{
struct V_47 V_48 = { . V_49 = V_50 } ;
union V_51 * V_52 ;
T_4 V_53 ;
int V_54 = 0 ;
V_53 = F_30 ( F_4 ( V_8 ) , L_3 , NULL ,
& V_48 ) ;
V_54 = - V_55 ;
if ( V_53 == V_56 )
goto V_57;
V_54 = - V_58 ;
if ( F_31 ( V_53 ) ) {
F_32 ( V_8 , L_4 ,
V_53 ) ;
goto V_57;
}
V_52 = V_48 . V_59 ;
if ( V_52 -> type != V_60 ) {
F_33 ( V_8 , L_5 ,
V_52 -> type ) ;
goto V_57;
}
if ( V_52 -> V_61 . V_49 != sizeof( struct V_45 ) ) {
F_32 ( V_8 , L_6 ,
V_52 -> V_61 . V_49 ) ;
goto V_57;
}
memcpy ( V_46 , V_52 -> V_61 . V_59 , sizeof( struct V_45 ) ) ;
V_54 = 0 ;
V_57:
F_3 ( V_48 . V_59 ) ;
return V_54 ;
}
int F_29 ( struct V_7 * V_8 , const struct V_45 * V_62 )
{
T_4 V_53 ;
struct V_45 V_63 = * V_62 ;
struct V_64 V_65 ;
union V_51 V_66 [ 3 ] ;
V_66 [ 0 ] . type = V_60 ;
V_66 [ 0 ] . V_61 . V_49 = sizeof( struct V_45 ) ;
V_66 [ 0 ] . V_61 . V_59 = ( V_67 * ) & V_63 ;
V_66 [ 1 ] . type = V_60 ;
V_66 [ 1 ] . V_61 . V_49 = 512 ;
V_66 [ 1 ] . V_61 . V_59 = ( V_67 * ) V_8 -> V_14 . V_1 [ 0 ] . V_68 ;
V_66 [ 2 ] . type = V_60 ;
V_66 [ 2 ] . V_61 . V_49 = 512 ;
V_66 [ 2 ] . V_61 . V_59 = ( V_67 * ) V_8 -> V_14 . V_1 [ 1 ] . V_68 ;
V_65 . V_69 = 3 ;
V_65 . V_59 = V_66 ;
V_53 = F_30 ( F_4 ( V_8 ) , L_7 , & V_65 ,
NULL ) ;
if ( V_53 == V_56 )
return - V_55 ;
if ( F_31 ( V_53 ) ) {
F_32 ( V_8 , L_8 ,
V_53 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_2 , struct V_70 * * V_71 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_4 V_53 ;
struct V_47 V_48 ;
union V_51 * V_52 ;
int V_54 = 0 ;
if ( V_2 -> V_6 ) {
V_52 = V_2 -> V_6 ;
goto V_72;
}
V_48 . V_49 = V_50 ;
V_48 . V_59 = NULL ;
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_9 ,
V_73 , V_8 -> V_12 ) ;
V_53 = F_30 ( F_7 ( V_2 ) , L_10 , NULL ,
& V_48 ) ;
V_52 = V_2 -> V_6 = V_48 . V_59 ;
if ( F_31 ( V_53 ) ) {
if ( V_53 != V_56 ) {
F_37 ( V_2 , L_11 ,
V_53 ) ;
V_54 = - V_58 ;
}
goto V_57;
}
if ( ! V_48 . V_49 || ! V_48 . V_59 ) {
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_12 ,
V_73 ,
( unsigned long long ) V_48 . V_49 ,
V_48 . V_59 ) ;
V_54 = - V_58 ;
goto V_57;
}
if ( V_52 -> type != V_60 ) {
F_37 ( V_2 , L_13 ,
V_52 -> type ) ;
V_54 = - V_58 ;
goto V_57;
}
if ( V_52 -> V_61 . V_49 % V_74 ) {
F_37 ( V_2 , L_14 ,
V_52 -> V_61 . V_49 ) ;
V_54 = - V_58 ;
goto V_57;
}
V_72:
V_54 = V_52 -> V_61 . V_49 / V_74 ;
if ( V_71 ) {
* V_71 = ( void * ) V_52 -> V_61 . V_59 ;
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_15 ,
V_73 , * V_71 , V_54 ) ;
}
return V_54 ;
V_57:
F_2 ( V_2 ) ;
return V_54 ;
}
unsigned long F_38 ( struct V_5 * V_2 ,
const struct V_45 * V_46 )
{
unsigned long V_75 = 0 ;
unsigned int type ;
int V_76 ;
V_67 V_77 ;
V_76 = V_2 -> V_18 ;
if ( ! ( V_46 -> V_9 & 0x10 ) )
V_76 = 0 ;
V_77 = F_39 ( V_78 , V_46 -> V_79 [ V_76 ] . V_80 ) ;
V_75 |= F_40 ( V_77 ) ;
if ( ! ( V_46 -> V_9 & ( 1 << ( 2 * V_76 ) ) ) )
type = V_81 ;
else
type = V_82 ;
V_77 = F_39 ( type , V_46 -> V_79 [ V_76 ] . V_83 ) ;
V_75 |= F_40 ( V_77 ) ;
return V_75 ;
}
int F_41 ( struct V_7 * V_8 , const struct V_45 * V_46 )
{
struct V_5 * V_2 ;
F_12 (dev, &ap->link, ENABLED) {
unsigned long V_75 , V_84 ;
V_75 = F_38 ( V_2 , V_46 ) ;
F_42 ( V_75 , NULL , NULL , & V_84 ) ;
if ( V_84 & ~ V_85 )
return 1 ;
}
return 0 ;
}
static void F_43 ( struct V_5 * V_2 ,
const struct V_70 * V_71 ,
struct V_86 * V_87 )
{
F_44 ( V_2 , V_87 ) ;
V_87 -> V_9 |= V_88 | V_89 ;
V_87 -> V_90 = V_91 ;
V_87 -> V_92 = V_71 -> V_87 [ 0 ] ;
V_87 -> V_93 = V_71 -> V_87 [ 1 ] ;
V_87 -> V_94 = V_71 -> V_87 [ 2 ] ;
V_87 -> V_95 = V_71 -> V_87 [ 3 ] ;
V_87 -> V_96 = V_71 -> V_87 [ 4 ] ;
V_87 -> V_1 = V_71 -> V_87 [ 5 ] ;
V_87 -> V_97 = V_71 -> V_87 [ 6 ] ;
}
static int F_45 ( struct V_5 * V_2 ,
const struct V_86 * V_87 ,
const struct V_86 * V_98 )
{
if ( V_2 -> V_99 & V_100 ) {
if ( V_87 -> V_97 == V_101 &&
V_87 -> V_92 == V_102 )
return 1 ;
}
if ( V_2 -> V_99 & V_103 ) {
if ( V_87 -> V_97 == V_104 &&
V_87 -> V_92 == V_105 )
return 1 ;
if ( V_87 -> V_97 == V_106 )
return 1 ;
if ( ( ! V_98 || V_98 -> V_97 != V_107 ) &&
V_87 -> V_97 == V_108 &&
( V_87 -> V_92 == V_109 ||
V_87 -> V_92 == V_110 ) )
return 1 ;
}
if ( V_87 -> V_97 == V_101 &&
V_87 -> V_92 == V_111 ) {
if ( V_2 -> V_99 & V_112 &&
V_87 -> V_93 == V_113 )
return 1 ;
if ( V_2 -> V_99 & V_114 &&
( V_87 -> V_93 == V_115 ||
V_87 -> V_93 == V_116 ) )
return 1 ;
if ( V_2 -> V_99 & V_117 &&
V_87 -> V_93 == V_118 )
return 1 ;
}
return 0 ;
}
static int F_46 ( struct V_5 * V_2 ,
const struct V_70 * V_71 ,
const struct V_70 * V_119 )
{
struct V_86 * V_120 = NULL ;
struct V_86 V_87 , V_98 , V_121 ;
unsigned int V_122 ;
const char * V_123 ;
const char * V_124 ;
char V_125 [ 60 ] ;
int V_54 ;
if ( ( V_71 -> V_87 [ 0 ] == 0 ) && ( V_71 -> V_87 [ 1 ] == 0 ) && ( V_71 -> V_87 [ 2 ] == 0 )
&& ( V_71 -> V_87 [ 3 ] == 0 ) && ( V_71 -> V_87 [ 4 ] == 0 ) && ( V_71 -> V_87 [ 5 ] == 0 )
&& ( V_71 -> V_87 [ 6 ] == 0 ) )
return 0 ;
F_43 ( V_2 , V_71 , & V_87 ) ;
if ( V_119 ) {
F_43 ( V_2 , V_119 , & V_98 ) ;
V_120 = & V_98 ;
}
if ( ! F_45 ( V_2 , & V_87 , V_120 ) ) {
V_121 = V_87 ;
V_122 = F_47 ( V_2 , & V_121 , NULL ,
V_126 , NULL , 0 , 0 ) ;
switch ( V_122 ) {
case 0 :
V_123 = V_127 ;
snprintf ( V_125 , sizeof( V_125 ) , L_16 ) ;
V_54 = 1 ;
break;
case V_128 :
V_123 = V_129 ;
snprintf ( V_125 , sizeof( V_125 ) ,
L_17 ,
V_121 . V_97 , V_121 . V_92 ) ;
V_54 = 0 ;
break;
default:
V_123 = V_130 ;
snprintf ( V_125 , sizeof( V_125 ) ,
L_18 ,
V_122 , V_121 . V_97 , V_121 . V_92 ) ;
V_54 = - V_131 ;
break;
}
} else {
V_123 = V_129 ;
snprintf ( V_125 , sizeof( V_125 ) , L_19 ) ;
V_54 = 0 ;
}
V_124 = F_48 ( V_87 . V_97 ) ;
F_49 ( V_2 , V_123 ,
L_20 ,
V_87 . V_97 , V_87 . V_92 , V_87 . V_93 , V_87 . V_94 ,
V_87 . V_95 , V_87 . V_96 , V_87 . V_1 ,
( V_124 ? V_124 : L_21 ) , V_125 ) ;
return V_54 ;
}
static int F_50 ( struct V_5 * V_2 , int * V_132 )
{
struct V_70 * V_71 = NULL , * V_133 = NULL ;
int V_134 , V_42 , V_54 ;
V_54 = F_34 ( V_2 , & V_71 ) ;
if ( V_54 < 0 )
return V_54 ;
V_134 = V_54 ;
for ( V_42 = 0 ; V_42 < V_134 ; V_42 ++ , V_71 ++ ) {
V_54 = F_46 ( V_2 , V_71 , V_133 ) ;
if ( V_54 < 0 )
break;
if ( V_54 ) {
( * V_132 ) ++ ;
V_133 = V_71 ;
}
}
F_2 ( V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
return 0 ;
}
static int F_51 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_4 V_53 ;
struct V_64 V_65 ;
union V_51 V_66 [ 1 ] ;
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_22 ,
V_73 , V_2 -> V_18 , V_8 -> V_12 ) ;
V_65 . V_69 = 1 ;
V_65 . V_59 = V_66 ;
V_66 [ 0 ] . type = V_60 ;
V_66 [ 0 ] . V_61 . V_49 = sizeof( V_2 -> V_68 [ 0 ] ) * V_135 ;
V_66 [ 0 ] . V_61 . V_59 = ( V_67 * ) V_2 -> V_68 ;
F_52 ( V_2 -> V_68 , V_135 ) ;
V_53 = F_30 ( F_7 ( V_2 ) , L_23 , & V_65 ,
NULL ) ;
F_52 ( V_2 -> V_68 , V_135 ) ;
if ( V_53 == V_56 )
return - V_55 ;
if ( F_31 ( V_53 ) ) {
F_37 ( V_2 , L_24 , V_53 ) ;
return - V_131 ;
}
return 0 ;
}
int F_53 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_54 ( struct V_7 * V_8 )
{
const struct V_45 * V_46 = F_28 ( V_8 ) ;
struct V_5 * V_2 ;
if ( F_4 ( V_8 ) && V_46 ) {
F_29 ( V_8 , V_46 ) ;
F_12 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_55 ( V_2 ) &&
F_34 ( V_2 , NULL ) >= 0 )
V_2 -> V_9 |= V_136 ;
}
} else {
F_12 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_55 ( V_2 ) )
V_2 -> V_9 |= V_136 ;
}
}
}
void F_56 ( struct V_7 * V_8 , T_5 V_137 )
{
struct V_5 * V_2 ;
T_1 V_32 ;
int V_138 ;
V_32 = F_4 ( V_8 ) ;
if ( V_32 && V_137 . V_23 == V_139 )
F_57 ( V_32 , V_140 ) ;
F_12 (dev, &ap->link, ENABLED) {
V_32 = F_7 ( V_2 ) ;
if ( ! V_32 )
continue;
if ( V_137 . V_23 != V_139 ) {
V_138 = F_58 (
& V_2 -> V_38 -> V_39 , NULL , V_141 ) ;
if ( V_138 > 0 )
F_57 ( V_32 , V_138 ) ;
F_59 (
& V_2 -> V_38 -> V_39 , true ) ;
} else {
F_59 (
& V_2 -> V_38 -> V_39 , false ) ;
F_57 ( V_32 , V_140 ) ;
}
}
V_32 = F_4 ( V_8 ) ;
if ( V_32 && V_137 . V_23 != V_139 )
F_57 ( V_32 , V_141 ) ;
}
int F_60 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
struct V_142 * V_143 = & V_8 -> V_14 . V_144 ;
int V_145 = V_8 -> V_9 & V_10 ;
int V_132 = 0 ;
int V_54 ;
if ( ! F_7 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_136 ) &&
! ( V_145 && ( V_143 -> V_42 . V_9 & V_146 ) ) )
return 0 ;
if ( V_145 ) {
V_54 = F_51 ( V_2 ) ;
if ( V_54 && V_54 != - V_55 )
goto V_147;
}
V_54 = F_50 ( V_2 , & V_132 ) ;
if ( V_54 )
goto V_147;
V_2 -> V_9 &= ~ V_136 ;
if ( V_132 ) {
V_54 = F_61 ( V_2 , 0 ) ;
if ( V_54 < 0 ) {
F_62 ( V_2 ,
L_25 ) ;
return V_54 ;
}
}
return 0 ;
V_147:
if ( V_54 == - V_58 && ! V_132 && ! ( V_8 -> V_148 & V_149 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_150 ) ) {
V_2 -> V_9 |= V_150 ;
return V_54 ;
}
V_2 -> V_9 |= V_15 ;
F_37 ( V_2 , L_26 ) ;
if ( ! V_132 && ! ( V_8 -> V_148 & V_149 ) )
return 0 ;
return V_54 ;
}
void F_63 ( struct V_5 * V_2 )
{
F_2 ( V_2 ) ;
}
static void F_64 ( T_1 V_32 , T_3 V_23 , void * V_151 )
{
struct V_5 * V_152 = V_151 ;
if ( V_23 == V_153 && V_152 &&
F_65 ( & V_152 -> V_38 -> V_39 ) )
F_66 ( V_152 -> V_38 ) ;
}
static void F_67 ( struct V_5 * V_2 )
{
struct V_154 * V_155 ;
T_1 V_32 ;
T_4 V_53 ;
V_32 = F_7 ( V_2 ) ;
if ( ! V_32 )
return;
V_53 = F_68 ( V_32 , & V_155 ) ;
if ( F_31 ( V_53 ) )
return;
if ( V_2 -> V_38 -> V_156 ) {
F_69 ( V_32 , V_157 ,
F_64 , V_2 ) ;
F_70 ( & V_2 -> V_38 -> V_39 , true ) ;
}
}
static void F_71 ( struct V_5 * V_2 )
{
struct V_154 * V_155 ;
T_1 V_32 ;
T_4 V_53 ;
V_32 = F_7 ( V_2 ) ;
if ( ! V_32 )
return;
V_53 = F_68 ( V_32 , & V_155 ) ;
if ( F_31 ( V_53 ) )
return;
if ( V_2 -> V_38 -> V_156 ) {
F_70 ( & V_2 -> V_38 -> V_39 , false ) ;
F_72 ( V_32 , V_157 ,
F_64 ) ;
}
}
static void F_73 ( struct V_5 * V_2 )
{
struct V_158 * V_38 = V_2 -> V_38 ;
T_1 V_32 ;
struct V_1 * V_1 ;
V_32 = F_7 ( V_2 ) ;
if ( ! V_32 )
return;
V_1 = & V_38 -> V_39 ;
F_74 ( V_1 , V_32 ) ;
}
static void F_75 ( struct V_5 * V_2 )
{
struct V_158 * V_38 = V_2 -> V_38 ;
T_1 V_32 ;
struct V_1 * V_1 ;
V_32 = F_7 ( V_2 ) ;
if ( ! V_32 )
return;
V_1 = & V_38 -> V_39 ;
F_76 ( V_1 , V_32 ) ;
}
void F_77 ( struct V_5 * V_2 )
{
F_67 ( V_2 ) ;
F_73 ( V_2 ) ;
}
void F_78 ( struct V_5 * V_2 )
{
F_71 ( V_2 ) ;
F_75 ( V_2 ) ;
}
static int F_79 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_22 . V_159 ;
struct V_160 * V_161 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_161 = F_80 ( V_2 ) ;
if ( ( V_161 -> V_162 >> 8 ) != V_163 &&
( V_161 -> V_162 >> 8 ) != V_164 )
return 0 ;
return 1 ;
}
static int F_81 ( struct V_7 * V_8 , T_1 * V_32 )
{
if ( V_8 -> V_9 & V_10 )
return - V_165 ;
* V_32 = F_5 ( F_6 ( V_8 -> V_22 . V_159 ) ,
V_8 -> V_12 ) ;
if ( ! * V_32 )
return - V_165 ;
if ( V_45 ( V_8 , & V_8 -> V_166 ) == 0 )
V_8 -> V_148 |= V_167 ;
return 0 ;
}
static int F_82 ( struct V_7 * V_8 , struct V_158 * V_38 ,
T_1 * V_32 )
{
struct V_5 * V_152 ;
T_4 V_53 ;
struct V_154 * V_155 ;
struct V_168 * V_169 ;
if ( V_8 -> V_9 & V_10 ) {
if ( ! F_8 ( V_8 ) )
V_152 = & V_8 -> V_14 . V_1 [ V_38 -> V_68 ] ;
else
V_152 = & V_8 -> V_170 [ V_38 -> V_171 ] . V_1 [ V_38 -> V_68 ] ;
}
else {
V_152 = & V_8 -> V_14 . V_1 [ V_38 -> V_68 ] ;
}
* V_32 = F_7 ( V_152 ) ;
if ( ! * V_32 )
return - V_165 ;
V_53 = F_68 ( * V_32 , & V_155 ) ;
if ( F_31 ( V_53 ) )
return 0 ;
V_169 = V_155 -> V_172 . V_169 ;
if ( ( V_169 [ V_173 ] . V_9 . V_174 ||
V_169 [ V_175 ] . V_9 . V_176 ) &&
V_152 -> V_9 & V_177 )
V_38 -> V_156 = 1 ;
return 0 ;
}
static int F_83 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_178 ;
}
static struct V_7 * F_84 ( struct V_1 * V_2 )
{
while ( ! F_83 ( V_2 ) ) {
if ( ! V_2 -> V_159 )
return NULL ;
V_2 = V_2 -> V_159 ;
}
return F_85 ( V_2 ) ;
}
static int F_86 ( struct V_1 * V_2 , T_1 * V_32 )
{
struct V_7 * V_8 = F_84 ( V_2 ) ;
if ( ! V_8 )
return - V_165 ;
if ( ! F_79 ( V_8 ) )
return - V_165 ;
if ( F_87 ( V_2 ) )
return F_81 ( V_8 , V_32 ) ;
else if ( F_88 ( V_2 ) ) {
struct V_158 * V_38 = F_89 ( V_2 ) ;
return F_82 ( V_8 , V_38 , V_32 ) ;
} else
return - V_165 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 * V_32 )
{
return - V_165 ;
}
int F_91 ( void )
{
return F_92 ( & V_179 ) ;
}
void F_93 ( void )
{
F_94 ( & V_179 ) ;
}
