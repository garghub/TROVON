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
if ( V_8 -> V_9 & V_10 ) {
if ( ! F_8 ( V_8 ) )
V_13 = F_9 ( V_8 -> V_12 , V_15 ) ;
else
V_13 = F_9 ( V_8 -> V_12 , V_2 -> V_14 -> V_16 ) ;
return F_5 ( F_6 ( V_8 -> V_11 -> V_2 ) , V_13 ) ;
} else
return F_5 ( F_4 ( V_8 ) , V_2 -> V_17 ) ;
}
static void F_10 ( struct V_7 * V_8 , struct V_5 * V_2 )
{
if ( V_2 )
V_2 -> V_9 |= V_18 ;
else {
struct V_19 * V_20 ;
struct V_5 * V_21 ;
F_11 (tlink, ap, EDGE)
F_12 (tdev, tlink, ALL)
V_21 -> V_9 |= V_18 ;
}
F_13 ( V_8 ) ;
}
static void F_14 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_3 V_22 )
{
struct V_23 * V_24 = & V_8 -> V_14 . V_25 ;
int V_26 = 0 ;
unsigned long V_9 ;
F_15 ( V_8 -> V_27 , V_9 ) ;
switch ( V_22 ) {
case V_28 :
case V_29 :
F_16 ( V_24 , L_1 ) ;
F_17 ( V_24 ) ;
F_18 ( V_8 ) ;
break;
case V_30 :
F_16 ( V_24 , L_1 ) ;
F_10 ( V_8 , V_2 ) ;
V_26 = 1 ;
break;
}
F_19 ( V_8 -> V_27 , V_9 ) ;
if ( V_26 )
F_20 ( V_8 ) ;
}
static void F_21 ( T_1 V_31 , T_3 V_22 , void * V_32 )
{
struct V_5 * V_2 = V_32 ;
F_14 ( V_2 -> V_14 -> V_8 , V_2 , V_22 ) ;
}
static void F_22 ( T_1 V_31 , T_3 V_22 , void * V_32 )
{
struct V_7 * V_8 = V_32 ;
F_14 ( V_8 , NULL , V_22 ) ;
}
static void F_23 ( struct V_7 * V_8 , struct V_5 * V_2 ,
T_3 V_22 )
{
struct V_33 * V_34 = NULL ;
char V_35 [ 20 ] ;
char * V_36 [] = { V_35 , NULL } ;
if ( V_2 ) {
if ( V_2 -> V_37 )
V_34 = & V_2 -> V_37 -> V_38 . V_34 ;
} else
V_34 = & V_8 -> V_2 -> V_34 ;
if ( V_34 ) {
snprintf ( V_35 , 20 , L_2 , V_22 ) ;
F_24 ( V_34 , V_39 , V_36 ) ;
}
}
static void F_25 ( T_1 V_31 , T_3 V_22 , void * V_32 )
{
F_23 ( V_32 , NULL , V_22 ) ;
}
static void F_26 ( T_1 V_31 , T_3 V_22 , void * V_32 )
{
struct V_5 * V_2 = V_32 ;
F_23 ( V_2 -> V_14 -> V_8 , V_2 , V_22 ) ;
}
void F_27 ( struct V_40 * V_11 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_11 -> V_42 ; V_41 ++ ) {
struct V_7 * V_8 = V_11 -> V_43 [ V_41 ] ;
const struct V_44 * V_45 = F_28 ( V_8 ) ;
if ( F_4 ( V_8 ) && V_45 )
F_29 ( V_8 , V_45 ) ;
}
}
int V_44 ( struct V_7 * V_8 , struct V_44 * V_45 )
{
struct V_46 V_47 = { . V_48 = V_49 } ;
union V_50 * V_51 ;
T_4 V_52 ;
int V_53 = 0 ;
V_52 = F_30 ( F_4 ( V_8 ) , L_3 , NULL ,
& V_47 ) ;
V_53 = - V_54 ;
if ( V_52 == V_55 )
goto V_56;
V_53 = - V_57 ;
if ( F_31 ( V_52 ) ) {
F_32 ( V_8 , L_4 ,
V_52 ) ;
goto V_56;
}
V_51 = V_47 . V_58 ;
if ( V_51 -> type != V_59 ) {
F_33 ( V_8 , L_5 ,
V_51 -> type ) ;
goto V_56;
}
if ( V_51 -> V_60 . V_48 != sizeof( struct V_44 ) ) {
F_32 ( V_8 , L_6 ,
V_51 -> V_60 . V_48 ) ;
goto V_56;
}
memcpy ( V_45 , V_51 -> V_60 . V_58 , sizeof( struct V_44 ) ) ;
V_53 = 0 ;
V_56:
F_3 ( V_47 . V_58 ) ;
return V_53 ;
}
int F_29 ( struct V_7 * V_8 , const struct V_44 * V_61 )
{
T_4 V_52 ;
struct V_44 V_62 = * V_61 ;
struct V_63 V_64 ;
union V_50 V_65 [ 3 ] ;
V_65 [ 0 ] . type = V_59 ;
V_65 [ 0 ] . V_60 . V_48 = sizeof( struct V_44 ) ;
V_65 [ 0 ] . V_60 . V_58 = ( V_66 * ) & V_62 ;
V_65 [ 1 ] . type = V_59 ;
V_65 [ 1 ] . V_60 . V_48 = 512 ;
V_65 [ 1 ] . V_60 . V_58 = ( V_66 * ) V_8 -> V_14 . V_1 [ 0 ] . V_67 ;
V_65 [ 2 ] . type = V_59 ;
V_65 [ 2 ] . V_60 . V_48 = 512 ;
V_65 [ 2 ] . V_60 . V_58 = ( V_66 * ) V_8 -> V_14 . V_1 [ 1 ] . V_67 ;
V_64 . V_68 = 3 ;
V_64 . V_58 = V_65 ;
V_52 = F_30 ( F_4 ( V_8 ) , L_7 , & V_64 ,
NULL ) ;
if ( V_52 == V_55 )
return - V_54 ;
if ( F_31 ( V_52 ) ) {
F_32 ( V_8 , L_8 ,
V_52 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_2 , struct V_69 * * V_70 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_4 V_52 ;
struct V_46 V_47 ;
union V_50 * V_51 ;
int V_53 = 0 ;
if ( V_2 -> V_6 ) {
V_51 = V_2 -> V_6 ;
goto V_71;
}
V_47 . V_48 = V_49 ;
V_47 . V_58 = NULL ;
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_9 ,
V_72 , V_8 -> V_12 ) ;
V_52 = F_30 ( F_7 ( V_2 ) , L_10 , NULL ,
& V_47 ) ;
V_51 = V_2 -> V_6 = V_47 . V_58 ;
if ( F_31 ( V_52 ) ) {
if ( V_52 != V_55 ) {
F_37 ( V_2 , L_11 ,
V_52 ) ;
V_53 = - V_57 ;
}
goto V_56;
}
if ( ! V_47 . V_48 || ! V_47 . V_58 ) {
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_12 ,
V_72 ,
( unsigned long long ) V_47 . V_48 ,
V_47 . V_58 ) ;
V_53 = - V_57 ;
goto V_56;
}
if ( V_51 -> type != V_59 ) {
F_37 ( V_2 , L_13 ,
V_51 -> type ) ;
V_53 = - V_57 ;
goto V_56;
}
if ( V_51 -> V_60 . V_48 % V_73 ) {
F_37 ( V_2 , L_14 ,
V_51 -> V_60 . V_48 ) ;
V_53 = - V_57 ;
goto V_56;
}
V_71:
V_53 = V_51 -> V_60 . V_48 / V_73 ;
if ( V_70 ) {
* V_70 = ( void * ) V_51 -> V_60 . V_58 ;
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_15 ,
V_72 , * V_70 , V_53 ) ;
}
return V_53 ;
V_56:
F_2 ( V_2 ) ;
return V_53 ;
}
unsigned long F_38 ( struct V_5 * V_2 ,
const struct V_44 * V_45 )
{
unsigned long V_74 = 0 ;
unsigned int type ;
int V_75 ;
V_66 V_76 ;
V_75 = V_2 -> V_17 ;
if ( ! ( V_45 -> V_9 & 0x10 ) )
V_75 = 0 ;
V_76 = F_39 ( V_77 , V_45 -> V_78 [ V_75 ] . V_79 ) ;
V_74 |= F_40 ( V_76 ) ;
if ( ! ( V_45 -> V_9 & ( 1 << ( 2 * V_75 ) ) ) )
type = V_80 ;
else
type = V_81 ;
V_76 = F_39 ( type , V_45 -> V_78 [ V_75 ] . V_82 ) ;
V_74 |= F_40 ( V_76 ) ;
return V_74 ;
}
int F_41 ( struct V_7 * V_8 , const struct V_44 * V_45 )
{
struct V_5 * V_2 ;
F_12 (dev, &ap->link, ENABLED) {
unsigned long V_74 , V_83 ;
V_74 = F_38 ( V_2 , V_45 ) ;
F_42 ( V_74 , NULL , NULL , & V_83 ) ;
if ( V_83 & ~ V_84 )
return 1 ;
}
return 0 ;
}
static void F_43 ( struct V_5 * V_2 ,
const struct V_69 * V_70 ,
struct V_85 * V_86 )
{
F_44 ( V_2 , V_86 ) ;
V_86 -> V_9 |= V_87 | V_88 ;
V_86 -> V_89 = V_90 ;
V_86 -> V_91 = V_70 -> V_86 [ 0 ] ;
V_86 -> V_92 = V_70 -> V_86 [ 1 ] ;
V_86 -> V_93 = V_70 -> V_86 [ 2 ] ;
V_86 -> V_94 = V_70 -> V_86 [ 3 ] ;
V_86 -> V_95 = V_70 -> V_86 [ 4 ] ;
V_86 -> V_1 = V_70 -> V_86 [ 5 ] ;
V_86 -> V_96 = V_70 -> V_86 [ 6 ] ;
}
static int F_45 ( struct V_5 * V_2 ,
const struct V_85 * V_86 ,
const struct V_85 * V_97 )
{
if ( V_2 -> V_98 & V_99 ) {
if ( V_86 -> V_96 == V_100 &&
V_86 -> V_91 == V_101 )
return 1 ;
}
if ( V_2 -> V_98 & V_102 ) {
if ( V_86 -> V_96 == V_103 &&
V_86 -> V_91 == V_104 )
return 1 ;
if ( V_86 -> V_96 == V_105 )
return 1 ;
if ( ( ! V_97 || V_97 -> V_96 != V_106 ) &&
V_86 -> V_96 == V_107 &&
( V_86 -> V_91 == V_108 ||
V_86 -> V_91 == V_109 ) )
return 1 ;
}
if ( V_86 -> V_96 == V_100 &&
V_86 -> V_91 == V_110 ) {
if ( V_2 -> V_98 & V_111 &&
V_86 -> V_92 == V_112 )
return 1 ;
if ( V_2 -> V_98 & V_113 &&
( V_86 -> V_92 == V_114 ||
V_86 -> V_92 == V_115 ) )
return 1 ;
if ( V_2 -> V_98 & V_116 &&
V_86 -> V_92 == V_117 )
return 1 ;
}
return 0 ;
}
static int F_46 ( struct V_5 * V_2 ,
const struct V_69 * V_70 ,
const struct V_69 * V_118 )
{
struct V_85 * V_119 = NULL ;
struct V_85 V_86 , V_97 , V_120 ;
unsigned int V_121 ;
const char * V_122 ;
const char * V_123 ;
char V_124 [ 60 ] ;
int V_53 ;
if ( ( V_70 -> V_86 [ 0 ] == 0 ) && ( V_70 -> V_86 [ 1 ] == 0 ) && ( V_70 -> V_86 [ 2 ] == 0 )
&& ( V_70 -> V_86 [ 3 ] == 0 ) && ( V_70 -> V_86 [ 4 ] == 0 ) && ( V_70 -> V_86 [ 5 ] == 0 )
&& ( V_70 -> V_86 [ 6 ] == 0 ) )
return 0 ;
F_43 ( V_2 , V_70 , & V_86 ) ;
if ( V_118 ) {
F_43 ( V_2 , V_118 , & V_97 ) ;
V_119 = & V_97 ;
}
if ( ! F_45 ( V_2 , & V_86 , V_119 ) ) {
V_120 = V_86 ;
V_121 = F_47 ( V_2 , & V_120 , NULL ,
V_125 , NULL , 0 , 0 ) ;
switch ( V_121 ) {
case 0 :
V_122 = V_126 ;
snprintf ( V_124 , sizeof( V_124 ) , L_16 ) ;
V_53 = 1 ;
break;
case V_127 :
V_122 = V_128 ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_17 ,
V_120 . V_96 , V_120 . V_91 ) ;
V_53 = 0 ;
break;
default:
V_122 = V_129 ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_18 ,
V_121 , V_120 . V_96 , V_120 . V_91 ) ;
V_53 = - V_130 ;
break;
}
} else {
V_122 = V_128 ;
snprintf ( V_124 , sizeof( V_124 ) , L_19 ) ;
V_53 = 0 ;
}
V_123 = F_48 ( V_86 . V_96 ) ;
F_49 ( V_2 , V_122 ,
L_20 ,
V_86 . V_96 , V_86 . V_91 , V_86 . V_92 , V_86 . V_93 ,
V_86 . V_94 , V_86 . V_95 , V_86 . V_1 ,
( V_123 ? V_123 : L_21 ) , V_124 ) ;
return V_53 ;
}
static int F_50 ( struct V_5 * V_2 , int * V_131 )
{
struct V_69 * V_70 = NULL , * V_132 = NULL ;
int V_133 , V_41 , V_53 ;
V_53 = F_34 ( V_2 , & V_70 ) ;
if ( V_53 < 0 )
return V_53 ;
V_133 = V_53 ;
for ( V_41 = 0 ; V_41 < V_133 ; V_41 ++ , V_70 ++ ) {
V_53 = F_46 ( V_2 , V_70 , V_132 ) ;
if ( V_53 < 0 )
break;
if ( V_53 ) {
( * V_131 ) ++ ;
V_132 = V_70 ;
}
}
F_2 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
static int F_51 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
T_4 V_52 ;
struct V_63 V_64 ;
union V_50 V_65 [ 1 ] ;
if ( F_35 ( V_8 ) )
F_36 ( V_2 , L_22 ,
V_72 , V_2 -> V_17 , V_8 -> V_12 ) ;
V_64 . V_68 = 1 ;
V_64 . V_58 = V_65 ;
V_65 [ 0 ] . type = V_59 ;
V_65 [ 0 ] . V_60 . V_48 = sizeof( V_2 -> V_67 [ 0 ] ) * V_134 ;
V_65 [ 0 ] . V_60 . V_58 = ( V_66 * ) V_2 -> V_67 ;
F_52 ( V_2 -> V_67 , V_134 ) ;
V_52 = F_30 ( F_7 ( V_2 ) , L_23 , & V_64 ,
NULL ) ;
F_52 ( V_2 -> V_67 , V_134 ) ;
if ( V_52 == V_55 )
return - V_54 ;
if ( F_31 ( V_52 ) ) {
F_37 ( V_2 , L_24 , V_52 ) ;
return - V_130 ;
}
return 0 ;
}
int F_53 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_54 ( struct V_7 * V_8 )
{
const struct V_44 * V_45 = F_28 ( V_8 ) ;
struct V_5 * V_2 ;
if ( F_4 ( V_8 ) && V_45 ) {
F_29 ( V_8 , V_45 ) ;
F_12 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_55 ( V_2 ) &&
F_34 ( V_2 , NULL ) >= 0 )
V_2 -> V_9 |= V_135 ;
}
} else {
F_12 (dev, &ap->link, ALL) {
F_2 ( V_2 ) ;
if ( F_55 ( V_2 ) )
V_2 -> V_9 |= V_135 ;
}
}
}
void F_56 ( struct V_7 * V_8 , T_5 V_136 )
{
struct V_5 * V_2 ;
T_1 V_31 ;
int V_137 ;
V_31 = F_4 ( V_8 ) ;
if ( V_31 && V_136 . V_22 == V_138 )
F_57 ( V_31 , V_139 ) ;
F_12 (dev, &ap->link, ENABLED) {
V_31 = F_7 ( V_2 ) ;
if ( ! V_31 )
continue;
if ( V_136 . V_22 != V_138 ) {
V_137 = F_58 (
& V_2 -> V_37 -> V_38 , NULL , V_140 ) ;
if ( V_137 > 0 )
F_57 ( V_31 , V_137 ) ;
F_59 (
& V_2 -> V_37 -> V_38 , true ) ;
} else {
F_59 (
& V_2 -> V_37 -> V_38 , false ) ;
F_57 ( V_31 , V_139 ) ;
}
}
V_31 = F_4 ( V_8 ) ;
if ( V_31 && V_136 . V_22 != V_138 )
F_57 ( V_31 , V_140 ) ;
}
int F_60 ( struct V_5 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_14 -> V_8 ;
struct V_141 * V_142 = & V_8 -> V_14 . V_143 ;
int V_144 = V_8 -> V_9 & V_10 ;
int V_131 = 0 ;
int V_53 ;
if ( ! F_7 ( V_2 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_135 ) &&
! ( V_144 && ( V_142 -> V_41 . V_9 & V_145 ) ) )
return 0 ;
if ( V_144 ) {
V_53 = F_51 ( V_2 ) ;
if ( V_53 && V_53 != - V_54 )
goto V_146;
}
V_53 = F_50 ( V_2 , & V_131 ) ;
if ( V_53 )
goto V_146;
V_2 -> V_9 &= ~ V_135 ;
if ( V_131 ) {
V_53 = F_61 ( V_2 , 0 ) ;
if ( V_53 < 0 ) {
F_62 ( V_2 ,
L_25 ) ;
return V_53 ;
}
}
return 0 ;
V_146:
if ( V_53 == - V_57 && ! V_131 && ! ( V_8 -> V_147 & V_148 ) )
return 0 ;
if ( ! ( V_2 -> V_9 & V_149 ) ) {
V_2 -> V_9 |= V_149 ;
return V_53 ;
}
F_37 ( V_2 , L_26 ) ;
if ( ! V_131 && ! ( V_8 -> V_147 & V_148 ) )
return 0 ;
return V_53 ;
}
void F_63 ( struct V_5 * V_2 )
{
F_2 ( V_2 ) ;
}
static void F_64 ( T_1 V_31 , T_3 V_22 , void * V_150 )
{
struct V_5 * V_151 = V_150 ;
if ( V_22 == V_152 && V_151 &&
F_65 ( & V_151 -> V_37 -> V_38 ) )
F_66 ( V_151 -> V_37 ) ;
}
static void F_67 ( struct V_5 * V_2 )
{
struct V_153 * V_154 ;
T_1 V_31 ;
T_4 V_52 ;
V_31 = F_7 ( V_2 ) ;
if ( ! V_31 )
return;
V_52 = F_68 ( V_31 , & V_154 ) ;
if ( F_31 ( V_52 ) )
return;
if ( V_2 -> V_37 -> V_155 ) {
F_69 ( V_31 , V_156 ,
F_64 , V_2 ) ;
F_70 ( & V_2 -> V_37 -> V_38 , true ) ;
}
}
static void F_71 ( struct V_5 * V_2 )
{
struct V_153 * V_154 ;
T_1 V_31 ;
T_4 V_52 ;
V_31 = F_7 ( V_2 ) ;
if ( ! V_31 )
return;
V_52 = F_68 ( V_31 , & V_154 ) ;
if ( F_31 ( V_52 ) )
return;
if ( V_2 -> V_37 -> V_155 ) {
F_70 ( & V_2 -> V_37 -> V_38 , false ) ;
F_72 ( V_31 , V_156 ,
F_64 ) ;
}
}
static void F_73 ( struct V_5 * V_2 )
{
struct V_157 * V_37 = V_2 -> V_37 ;
T_1 V_31 ;
struct V_1 * V_1 ;
V_31 = F_7 ( V_2 ) ;
if ( ! V_31 )
return;
V_1 = & V_37 -> V_38 ;
F_74 ( V_1 , V_31 ) ;
}
static void F_75 ( struct V_5 * V_2 )
{
struct V_157 * V_37 = V_2 -> V_37 ;
T_1 V_31 ;
struct V_1 * V_1 ;
V_31 = F_7 ( V_2 ) ;
if ( ! V_31 )
return;
V_1 = & V_37 -> V_38 ;
F_76 ( V_1 , V_31 ) ;
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
struct V_1 * V_2 = V_8 -> V_21 . V_158 ;
struct V_159 * V_160 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_160 = F_80 ( V_2 ) ;
if ( ( V_160 -> V_161 >> 8 ) != V_162 &&
( V_160 -> V_161 >> 8 ) != V_163 )
return 0 ;
return 1 ;
}
static int F_81 ( struct V_7 * V_8 , T_1 * V_31 )
{
if ( V_8 -> V_9 & V_10 )
return - V_164 ;
* V_31 = F_5 ( F_6 ( V_8 -> V_21 . V_158 ) ,
V_8 -> V_12 ) ;
if ( ! * V_31 )
return - V_164 ;
if ( V_44 ( V_8 , & V_8 -> V_165 ) == 0 )
V_8 -> V_147 |= V_166 ;
return 0 ;
}
static int F_82 ( struct V_7 * V_8 , struct V_157 * V_37 ,
T_1 * V_31 )
{
struct V_5 * V_151 ;
T_4 V_52 ;
struct V_153 * V_154 ;
struct V_167 * V_168 ;
if ( V_8 -> V_9 & V_10 )
V_151 = & V_8 -> V_14 . V_1 [ V_37 -> V_169 ] ;
else
V_151 = & V_8 -> V_14 . V_1 [ V_37 -> V_67 ] ;
* V_31 = F_7 ( V_151 ) ;
if ( ! * V_31 )
return - V_164 ;
V_52 = F_68 ( * V_31 , & V_154 ) ;
if ( F_31 ( V_52 ) )
return 0 ;
V_168 = V_154 -> V_170 . V_168 ;
if ( ( V_168 [ V_171 ] . V_9 . V_172 ||
V_168 [ V_173 ] . V_9 . V_174 ) &&
V_151 -> V_9 & V_175 )
V_37 -> V_155 = 1 ;
return 0 ;
}
static int F_83 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_176 ;
}
static struct V_7 * F_84 ( struct V_1 * V_2 )
{
while ( ! F_83 ( V_2 ) ) {
if ( ! V_2 -> V_158 )
return NULL ;
V_2 = V_2 -> V_158 ;
}
return F_85 ( V_2 ) ;
}
static int F_86 ( struct V_1 * V_2 , T_1 * V_31 )
{
struct V_7 * V_8 = F_84 ( V_2 ) ;
if ( ! V_8 )
return - V_164 ;
if ( ! F_79 ( V_8 ) )
return - V_164 ;
if ( F_87 ( V_2 ) )
return F_81 ( V_8 , V_31 ) ;
else if ( F_88 ( V_2 ) ) {
struct V_157 * V_37 = F_89 ( V_2 ) ;
return F_82 ( V_8 , V_37 , V_31 ) ;
} else
return - V_164 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 * V_31 )
{
return - V_164 ;
}
int F_91 ( void )
{
return F_92 ( & V_177 ) ;
}
void F_93 ( void )
{
F_94 ( & V_177 ) ;
}
