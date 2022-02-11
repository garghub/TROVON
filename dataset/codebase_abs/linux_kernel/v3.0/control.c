static
T_1 F_1 ( const struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_5 )
{
if ( F_2 ( V_2 -> type ) != V_4 )
return - 1 ;
if ( V_5 != - 1
&& F_2 ( V_2 -> V_6 ) + sizeof( * V_2 ) != V_5 ) {
T_2 V_7 = F_2 ( V_2 -> V_6 ) + sizeof( * V_2 ) ;
F_3 ( V_8 L_1
L_2 ,
V_4 , V_7 , V_5 ) ;
return V_7 ;
}
return 0 ;
}
static
const struct V_1 * F_4 (
struct V_9 * V_9 ,
const void * V_10 , T_2 V_11 ,
const struct V_1 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
const struct V_1 * V_15 = V_10 + V_11 ;
T_2 V_16 , V_6 , V_17 ;
unsigned type ;
if ( V_12 == NULL )
V_12 = V_10 ;
else
V_12 = ( void * ) V_12
+ F_2 ( V_12 -> V_6 ) + sizeof( * V_12 ) ;
if ( V_12 == V_15 ) {
V_12 = NULL ;
goto V_18;
}
if ( V_12 > V_15 ) {
V_12 = NULL ;
F_6 ( 1 ) ;
goto V_18;
}
V_16 = ( void * ) V_12 - ( void * ) V_10 ;
V_17 = V_11 - V_16 ;
if ( V_17 < sizeof( * V_12 ) ) {
F_7 ( V_14 , L_3
L_4 , V_10 , V_11 , V_16 ) ;
goto V_19;
}
type = F_2 ( V_12 -> type ) ;
V_6 = F_2 ( V_12 -> V_6 ) ;
if ( V_17 < sizeof( * V_12 ) + V_6 ) {
F_7 ( V_14 , L_5
L_6
L_7 ,
V_10 , V_11 , type , V_16 , V_17 ,
sizeof( * V_12 ) + V_6 ) ;
goto V_19;
}
V_19:
V_18:
return V_12 ;
}
static
const struct V_1 * F_8 (
struct V_9 * V_9 ,
const struct V_1 * V_20 , T_2 V_7 ,
enum V_3 V_4 , T_1 V_5 )
{
T_1 V_21 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
const struct V_1 * V_2 = NULL ;
while ( ( V_2 = F_4 ( V_9 , V_20 , V_7 , V_2 ) ) ) {
V_21 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_21 == 0 )
break;
if ( V_21 > 0 )
F_9 ( V_14 , L_8
L_9 ,
V_4 , V_21 , V_5 ) ;
}
return V_2 ;
}
int F_10 ( const struct V_22 * V_23 ,
char * V_24 , T_2 V_25 )
{
int V_26 ;
enum V_27 V_28 = F_2 ( V_23 -> V_28 ) ;
const char * V_29 ;
if ( V_28 == 0 )
return 0 ;
if ( V_28 >= F_11 ( V_30 ) ) {
V_29 = L_10 ;
V_26 = - V_31 ;
} else {
V_29 = V_30 [ V_28 ] . V_32 ;
V_26 = V_30 [ V_28 ] . V_33 ;
}
if ( V_24 )
snprintf ( V_24 , V_25 , L_11 , V_29 , V_28 ) ;
return V_26 ;
}
static
void F_12 ( struct V_9 * V_9 ,
const struct V_34 * V_35 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_36 * V_36 = & V_9 -> V_36 ;
enum V_37 V_38 = F_13 ( V_35 -> V_39 ) ;
F_14 ( 3 , V_14 , L_12 , V_9 , V_35 , V_38 ) ;
if ( V_9 -> V_39 != V_38 ) {
V_9 -> V_39 = V_38 ;
F_15 ( & V_9 -> V_40 ) ;
}
switch ( V_38 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
F_16 ( V_36 , V_45 ) ;
break;
case V_46 :
case V_47 :
F_16 ( V_36 , V_48 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
F_16 ( V_36 , V_52 ) ;
break;
case V_53 :
case V_54 :
F_16 ( V_36 , V_52 ) ;
break;
case V_55 :
case V_56 :
F_16 ( V_36 , V_57 ) ;
break;
case V_58 :
F_17 ( 1 , V_14 , L_13 ) ;
case V_59 :
case V_60 :
F_16 ( V_36 , V_61 ) ;
break;
default:
F_7 ( V_14 , L_14 ,
V_38 ) ;
F_18 ( V_9 , V_62 ) ;
break;
}
F_19 ( 3 , V_14 , L_15 ,
V_9 , V_35 , V_38 ) ;
}
static
void F_20 ( struct V_9 * V_9 ,
const struct V_63 * V_64 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_36 * V_36 = & V_9 -> V_36 ;
struct V_65 * V_66 = V_36 -> V_66 ;
enum V_67 V_28 = F_13 ( V_64 -> V_68 ) ;
F_14 ( 3 , V_14 , L_16 , V_9 , V_64 , V_28 ) ;
switch ( V_28 ) {
case V_69 :
F_21 ( V_66 ) ;
break;
case V_70 :
F_22 ( V_66 ) ;
break;
case V_71 :
F_21 ( V_66 ) ;
break;
default:
F_7 ( V_14 , L_17 ,
V_28 ) ;
}
F_19 ( 3 , V_14 , L_18 ,
V_9 , V_64 , V_28 ) ;
}
static
void F_23 ( struct V_9 * V_9 ,
const struct V_1 * V_2 ,
const char * V_72 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
const struct V_63 * V_64 ;
const struct V_34 * V_35 ;
const struct V_73 * V_74 ;
if ( 0 == F_1 ( V_2 , V_75 , sizeof( * V_35 ) ) ) {
V_35 = F_24 ( V_2 , F_25 ( * V_35 ) , V_76 ) ;
F_17 ( 2 , V_14 , L_19
L_20 ,
V_72 , V_75 ,
F_13 ( V_35 -> V_39 ) ) ;
F_12 ( V_9 , V_35 ) ;
}
if ( 0 == F_1 ( V_2 , V_77 , sizeof( * V_74 ) ) ) {
V_74 = F_24 ( V_2 , F_25 ( * V_74 ) , V_76 ) ;
F_17 ( 2 , V_14 , L_21
L_22 ,
V_72 , V_77 ,
F_13 ( V_74 -> V_78 ) ,
F_13 ( V_74 -> V_79 ) ) ;
F_26 ( V_9 , V_74 ) ;
}
if ( 0 == F_1 ( V_2 , V_80 , sizeof( * V_64 ) ) ) {
V_64 = F_24 ( V_2 , F_25 ( * V_64 ) , V_76 ) ;
F_17 ( 2 , V_14 , L_23 ,
V_72 , F_13 ( V_64 -> V_68 ) ) ;
F_20 ( V_9 , V_64 ) ;
}
}
static
void F_27 ( struct V_9 * V_9 ,
const struct V_22 * V_23 ,
T_2 V_7 , const char * V_72 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
const struct V_1 * V_2 ;
T_2 V_5 = F_2 ( V_23 -> V_6 ) ;
F_14 ( 4 , V_14 , L_24 ,
V_9 , V_23 , V_7 , V_72 ) ;
V_2 = NULL ;
while ( ( V_2 = F_4 ( V_9 , & V_23 -> V_81 ,
V_5 , V_2 ) ) )
F_23 ( V_9 , V_2 , V_72 ) ;
F_19 ( 4 , V_14 , L_25 ,
V_9 , V_23 , V_7 , V_72 ) ;
}
void F_28 ( struct V_9 * V_9 ,
const struct V_22 * V_23 , T_2 V_7 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
unsigned V_82 ;
F_14 ( 3 , V_14 , L_26 ,
V_9 , V_23 , V_7 ) ;
V_82 = F_2 ( V_23 -> type ) ;
switch ( V_82 ) {
case V_83 :
F_27 ( V_9 ,
V_23 , V_7 , L_27 ) ;
break;
case V_84 :
if ( V_23 -> V_28 == F_29 ( V_85 ) ) {
if ( V_86 )
F_17 ( 1 , V_14 , L_28
L_29
L_30 ) ;
else {
F_17 ( 1 , V_14 , L_28
L_31 ) ;
F_30 ( V_9 ) ;
}
}
break;
}
F_19 ( 3 , V_14 , L_32 ,
V_9 , V_23 , V_7 ) ;
}
static void F_31 ( struct V_9 * V_9 ,
const struct V_22 * V_23 ,
T_2 V_7 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
unsigned V_87 , V_88 ;
char V_89 [ 32 ] ;
V_87 = F_2 ( V_23 -> type ) ;
V_88 = F_2 ( V_23 -> V_28 ) ;
switch ( V_87 ) {
case V_90 :
if ( 0 ) {
V_26 = F_10 (
V_23 , V_89 , sizeof( V_89 ) ) ;
if ( V_26 >= 0 )
F_17 ( 1 , V_14 , L_33 ,
V_7 ) ;
}
break;
}
}
int F_32 ( struct V_9 * V_9 ,
const struct V_22 * V_23 ,
T_2 V_91 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
T_2 V_92 ;
F_14 ( 4 , V_14 , L_34 ,
V_9 , V_23 , V_91 ) ;
if ( V_91 < sizeof( * V_23 ) ) {
F_7 ( V_14 , L_35
L_36 ,
( T_2 ) sizeof( * V_23 ) , V_91 ) ;
V_26 = - V_93 ;
goto V_94;
}
V_92 = F_2 ( V_23 -> V_6 ) + sizeof( * V_23 ) ;
if ( V_91 < V_92 ) {
F_7 ( V_14 , L_37
L_38 , F_2 ( V_23 -> type ) ,
V_92 , V_91 ) ;
V_26 = - V_93 ;
} else
V_26 = 0 ;
V_94:
F_19 ( 4 , V_14 ,
L_39 ,
V_9 , V_23 , V_91 , V_26 ) ;
return V_26 ;
}
void F_33 ( struct V_9 * V_9 , int V_95 )
{
struct V_96 * V_97 ;
unsigned long V_98 ;
F_34 ( & V_9 -> V_99 , V_98 ) ;
V_97 = V_9 -> V_97 ;
if ( V_97 && ! F_35 ( V_97 ) )
F_36 ( V_97 ) ;
V_9 -> V_97 = F_37 ( V_95 ) ;
F_38 ( & V_9 -> V_99 , V_98 ) ;
}
struct V_96 * F_39 ( struct V_9 * V_9 ,
const void * V_100 , T_2 V_101 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
const struct V_22 * V_102 ;
struct V_96 * V_97 ;
const struct V_22 * V_103 ;
T_2 V_104 ;
int V_105 ;
unsigned V_82 ;
unsigned long V_98 ;
F_14 ( 3 , V_14 , L_40 ,
V_9 , V_100 , V_101 ) ;
F_40 () ;
if ( V_9 -> V_106 )
return F_37 ( - V_107 ) ;
V_102 = V_100 ;
V_26 = F_32 ( V_9 , V_102 , V_101 ) ;
if ( V_26 < 0 )
goto V_108;
V_82 = F_2 ( V_102 -> type ) ;
F_17 ( 1 , V_14 , L_41 ,
V_82 , V_101 ) ;
F_41 ( 2 , V_14 , V_100 , V_101 ) ;
F_42 ( & V_9 -> V_109 ) ;
F_34 ( & V_9 -> V_99 , V_98 ) ;
V_9 -> V_97 = F_37 ( - V_110 ) ;
F_38 ( & V_9 -> V_99 , V_98 ) ;
F_43 ( & V_9 -> V_111 ) ;
V_26 = F_44 ( V_9 , V_100 , V_101 , V_112 ) ;
if ( V_26 < 0 ) {
F_7 ( V_14 , L_42 ,
F_2 ( V_102 -> type ) , V_26 ) ;
goto V_113;
}
switch ( V_82 ) {
case V_114 :
case V_115 :
V_105 = 5 * V_116 ;
break;
default:
V_105 = V_116 ;
}
if ( F_45 ( V_9 -> V_117 ) )
F_46 ( & V_9 -> V_36 , L_43 , V_100 , V_101 , V_118 ) ;
V_26 = F_47 (
& V_9 -> V_111 , V_105 ) ;
if ( V_26 == 0 ) {
F_7 ( V_14 , L_44 ,
V_82 ) ;
V_26 = - V_119 ;
F_33 ( V_9 , V_26 ) ;
goto V_120;
} else if ( V_26 < 0 ) {
F_7 ( V_14 , L_45 ,
V_82 , V_26 ) ;
F_33 ( V_9 , V_26 ) ;
goto V_120;
}
F_34 ( & V_9 -> V_99 , V_98 ) ;
V_97 = V_9 -> V_97 ;
if ( F_35 ( V_97 ) )
V_26 = F_48 ( V_97 ) ;
else
V_26 = 0 ;
V_9 -> V_97 = NULL ;
F_38 ( & V_9 -> V_99 , V_98 ) ;
if ( V_26 < 0 )
goto V_121;
V_103 = F_49 ( V_97 , & V_104 ) ;
if ( F_45 ( V_9 -> V_117 ) )
F_46 ( & V_9 -> V_36 , L_43 ,
V_103 , V_104 , V_118 ) ;
V_26 = F_32 ( V_9 , V_103 , V_104 ) ;
if ( V_26 < 0 ) {
F_7 ( V_14 , L_46 ,
V_82 , V_26 ) ;
goto V_122;
}
if ( V_82 != F_2 ( V_103 -> type ) ) {
F_7 ( V_14 , L_47 ,
F_2 ( V_103 -> type ) , V_82 ) ;
V_26 = - V_93 ;
goto V_123;
}
F_31 ( V_9 , V_103 , V_104 ) ;
F_50 ( & V_9 -> V_109 ) ;
F_19 ( 3 , V_14 , L_48 ,
V_9 , V_100 , V_101 , V_97 ) ;
return V_97 ;
V_123:
V_122:
F_36 ( V_97 ) ;
V_121:
V_120:
V_113:
F_50 ( & V_9 -> V_109 ) ;
V_108:
F_19 ( 3 , V_14 , L_49 ,
V_9 , V_100 , V_101 , V_26 ) ;
return F_37 ( V_26 ) ;
}
int F_30 ( struct V_9 * V_9 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct V_124 * V_125 ;
char V_89 [ 32 ] ;
V_26 = - V_126 ;
V_125 = F_51 ( sizeof( * V_125 ) , V_118 ) ;
if ( V_125 == NULL )
goto V_127;
V_125 -> V_76 . type = F_29 ( V_90 ) ;
V_125 -> V_76 . V_6 = F_29 ( sizeof( * V_125 ) - sizeof( V_125 -> V_76 ) ) ;
V_125 -> V_76 . V_128 = F_29 ( V_129 ) ;
V_125 -> V_2 . type = F_29 ( V_130 ) ;
V_125 -> V_2 . V_6 = F_29 ( sizeof( V_125 -> V_131 ) ) ;
V_125 -> V_131 = F_52 ( V_132 ) ;
V_97 = F_39 ( V_9 , V_125 , sizeof( * V_125 ) ) ;
V_26 = F_48 ( V_97 ) ;
if ( F_35 ( V_97 ) ) {
F_7 ( V_14 , L_50 ,
V_26 ) ;
goto V_133;
}
V_26 = F_10 ( F_53 ( V_97 ) ,
V_89 , sizeof( V_89 ) ) ;
if ( V_26 == - V_134 )
F_17 ( 1 , V_14 , L_51 ) ;
else if ( V_26 < 0 )
F_7 ( V_14 , L_52
L_53 , V_90 ,
V_26 , V_89 ) ;
else
F_17 ( 1 , V_14 , L_54 ) ;
F_36 ( V_97 ) ;
V_133:
F_54 ( V_125 ) ;
V_127:
return V_26 ;
}
struct V_96 * F_55 ( struct V_9 * V_9 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct V_22 * V_125 ;
const struct V_22 * V_135 ;
T_2 V_104 ;
const struct V_1 * V_2 ;
const struct V_136 * V_137 ;
char V_89 [ 32 ] ;
V_97 = F_37 ( - V_126 ) ;
V_125 = F_51 ( sizeof( * V_125 ) , V_118 ) ;
if ( V_125 == NULL )
goto V_127;
V_125 -> type = F_29 ( V_138 ) ;
V_125 -> V_6 = 0 ;
V_125 -> V_128 = F_29 ( V_129 ) ;
V_97 = F_39 ( V_9 , V_125 , sizeof( * V_125 ) ) ;
if ( F_35 ( V_97 ) ) {
F_7 ( V_14 , L_55 ,
F_48 ( V_97 ) ) ;
goto V_133;
}
V_135 = F_49 ( V_97 , & V_104 ) ;
V_26 = F_10 ( V_135 , V_89 , sizeof( V_89 ) ) ;
if ( V_26 < 0 ) {
F_7 ( V_14 , L_56
L_53 , V_138 , V_26 ,
V_89 ) ;
goto V_139;
}
V_2 = F_8 ( V_9 , V_135 -> V_81 , V_104 - sizeof( * V_135 ) ,
V_140 , sizeof( * V_137 ) ) ;
if ( V_2 == NULL ) {
F_7 ( V_14 , L_57
L_58 ,
V_140 ) ;
V_26 = - V_93 ;
goto V_141;
}
F_56 ( V_97 , ( void * ) V_2 - ( void * ) V_97 -> V_142 ) ;
V_133:
F_54 ( V_125 ) ;
V_127:
return V_97 ;
V_141:
V_139:
F_36 ( V_97 ) ;
F_54 ( V_125 ) ;
return F_37 ( V_26 ) ;
}
int F_57 ( struct V_9 * V_9 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct V_22 * V_125 ;
const struct V_22 * V_135 ;
T_2 V_104 ;
const struct V_1 * V_2 ;
const struct V_143 * V_144 ;
char V_89 [ 32 ] ;
unsigned V_145 , V_146 , V_147 ;
V_26 = - V_126 ;
V_125 = F_51 ( sizeof( * V_125 ) , V_118 ) ;
if ( V_125 == NULL )
goto V_127;
V_125 -> type = F_29 ( V_148 ) ;
V_125 -> V_6 = 0 ;
V_125 -> V_128 = F_29 ( V_129 ) ;
V_97 = F_39 ( V_9 , V_125 , sizeof( * V_125 ) ) ;
if ( F_35 ( V_97 ) ) {
V_26 = F_48 ( V_97 ) ;
F_7 ( V_14 , L_59 ,
V_26 ) ;
goto V_133;
}
V_135 = F_49 ( V_97 , & V_104 ) ;
V_26 = F_10 ( V_135 , V_89 , sizeof( V_89 ) ) ;
if ( V_26 < 0 ) {
F_7 ( V_14 , L_60
L_53 , V_148 , V_26 ,
V_89 ) ;
goto V_139;
}
V_2 = F_8 ( V_9 , V_135 -> V_81 , V_104 - sizeof( * V_135 ) ,
V_149 , sizeof( * V_144 ) ) ;
if ( V_2 == NULL ) {
F_7 ( V_14 , L_61 ,
V_149 ) ;
V_26 = - V_93 ;
goto V_141;
}
V_144 = F_24 ( V_2 , F_25 ( * V_144 ) , V_76 ) ;
V_145 = F_2 ( V_144 -> V_145 ) ;
V_146 = F_2 ( V_144 -> V_146 ) ;
V_147 = F_2 ( V_144 -> V_147 ) ;
V_26 = - V_150 ;
if ( V_145 != V_151 ) {
F_7 ( V_14 , L_62
L_63 , V_145 , V_146 , V_147 ) ;
goto V_152;
}
V_26 = 0 ;
if ( V_146 < V_153 && V_146 > V_154 )
F_9 ( V_14 , L_64 ,
V_145 , V_146 , V_147 ) ;
V_9 -> V_155 = V_145 << 16 | V_146 ;
F_58 ( V_14 , L_65 ,
V_145 , V_146 , V_147 ) ;
V_152:
V_141:
V_139:
F_36 ( V_97 ) ;
V_133:
F_54 ( V_125 ) ;
V_127:
return V_26 ;
}
int F_59 ( struct V_9 * V_9 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct V_22 * V_125 ;
char V_89 [ 32 ] ;
V_26 = - V_126 ;
V_125 = F_51 ( sizeof( * V_125 ) , V_118 ) ;
if ( V_125 == NULL )
goto V_127;
V_125 -> type = F_29 ( V_156 ) ;
V_125 -> V_6 = 0 ;
V_125 -> V_128 = F_29 ( V_129 ) ;
V_97 = F_39 ( V_9 , V_125 , sizeof( * V_125 ) ) ;
V_26 = F_48 ( V_97 ) ;
if ( F_35 ( V_97 ) ) {
F_7 ( V_14 , L_66 ,
V_26 ) ;
goto V_133;
}
V_26 = F_10 ( F_53 ( V_97 ) ,
V_89 , sizeof( V_89 ) ) ;
F_36 ( V_97 ) ;
V_133:
F_54 ( V_125 ) ;
V_127:
return V_26 ;
}
static int F_60 ( struct V_9 * V_9 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct V_22 * V_125 ;
const struct V_22 * V_135 ;
T_2 V_104 ;
char V_89 [ 32 ] ;
V_26 = - V_126 ;
V_125 = F_51 ( sizeof( * V_125 ) , V_118 ) ;
if ( V_125 == NULL )
goto V_127;
V_125 -> type = F_29 ( V_157 ) ;
V_125 -> V_6 = 0 ;
V_125 -> V_128 = F_29 ( V_129 ) ;
V_97 = F_39 ( V_9 , V_125 , sizeof( * V_125 ) ) ;
if ( F_35 ( V_97 ) ) {
F_7 ( V_14 , L_67 ,
F_48 ( V_97 ) ) ;
V_26 = F_48 ( V_97 ) ;
goto V_133;
}
V_135 = F_49 ( V_97 , & V_104 ) ;
V_26 = F_10 ( V_135 , V_89 , sizeof( V_89 ) ) ;
if ( V_26 < 0 ) {
F_7 ( V_14 , L_68
L_53 , V_157 , V_26 , V_89 ) ;
goto V_139;
}
F_27 ( V_9 , V_135 , V_104 - sizeof( * V_135 ) ,
L_69 ) ;
V_26 = 0 ;
F_36 ( V_97 ) ;
V_139:
V_133:
F_54 ( V_125 ) ;
V_127:
return V_26 ;
}
static int F_61 ( struct V_9 * V_9 ,
const struct V_1 * * V_158 ,
T_2 args )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct V_22 * V_125 ;
char V_89 [ 32 ] ;
unsigned V_159 , V_160 , V_5 ;
const struct V_1 * V_20 ;
void * V_100 , * V_161 ;
F_14 ( 3 , V_14 , L_70 , V_9 , V_158 , args ) ;
V_26 = 0 ;
if ( args == 0 )
goto V_162;
V_160 = 0 ;
for ( V_159 = 0 ; V_159 < args ; V_159 ++ ) {
V_20 = V_158 [ V_159 ] ;
V_160 += sizeof( * V_20 ) + F_2 ( V_20 -> V_6 ) ;
}
F_6 ( V_159 >= 9 ) ;
V_26 = - V_126 ;
V_100 = F_51 ( sizeof( * V_125 ) + V_160 , V_118 ) ;
if ( V_100 == NULL )
goto V_127;
V_125 = V_100 ;
V_125 -> type = F_29 ( V_163 ) ;
V_125 -> V_6 = F_29 ( V_160 ) ;
V_125 -> V_128 = F_29 ( V_129 ) ;
V_161 = V_100 + sizeof( * V_125 ) ;
for ( V_159 = 0 ; V_159 < args ; V_159 ++ ) {
V_20 = V_158 [ V_159 ] ;
V_5 = sizeof( * V_20 ) + F_2 ( V_20 -> V_6 ) ;
memcpy ( V_161 , V_20 , V_5 ) ;
V_161 += V_5 ;
}
V_97 = F_39 ( V_9 , V_100 , sizeof( * V_125 ) + V_160 ) ;
V_26 = F_48 ( V_97 ) ;
if ( F_35 ( V_97 ) ) {
F_7 ( V_14 , L_71 ,
V_26 ) ;
goto V_133;
}
V_26 = F_10 ( F_53 ( V_97 ) ,
V_89 , sizeof( V_89 ) ) ;
if ( V_26 < 0 )
F_7 ( V_14 , L_72 ,
V_163 , V_26 , V_89 ) ;
F_36 ( V_97 ) ;
V_133:
F_54 ( V_100 ) ;
V_127:
V_162:
F_19 ( 3 , V_14 , L_73 ,
V_9 , V_158 , args , V_26 ) ;
return V_26 ;
}
int F_62 ( struct V_9 * V_9 , unsigned V_164 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_96 * V_97 ;
struct {
struct V_22 V_76 ;
struct V_165 V_166 ;
} * V_125 ;
const struct V_22 * V_135 ;
T_2 V_104 ;
char V_89 [ 32 ] ;
V_26 = - V_167 ;
if ( F_63 ( V_9 ) )
goto V_127;
V_26 = - V_126 ;
V_125 = F_51 ( sizeof( * V_125 ) , V_118 ) ;
if ( V_125 == NULL )
goto V_127;
V_125 -> V_76 . type = F_29 ( V_157 ) ;
V_125 -> V_76 . V_6 = F_29 ( sizeof( * V_125 ) - sizeof( V_125 -> V_76 ) ) ;
V_125 -> V_76 . V_128 = F_29 ( V_129 ) ;
V_125 -> V_166 . V_76 . type =
F_29 ( V_168 ) ;
V_125 -> V_166 . V_76 . V_6 = F_29 ( sizeof( V_125 -> V_166 . V_169 ) ) ;
V_125 -> V_166 . V_169 = F_52 ( V_164 ) ;
V_97 = F_39 ( V_9 , V_125 , sizeof( * V_125 ) ) ;
if ( F_35 ( V_97 ) ) {
F_7 ( V_14 , L_74
L_75 , F_48 ( V_97 ) ) ;
V_26 = F_48 ( V_97 ) ;
goto V_133;
}
V_135 = F_49 ( V_97 , & V_104 ) ;
V_26 = F_10 ( V_135 , V_89 , sizeof( V_89 ) ) ;
if ( V_26 < 0 ) {
F_7 ( V_14 , L_76
L_53 , V_157 , V_26 , V_89 ) ;
goto V_139;
}
V_26 = 0 ;
F_36 ( V_97 ) ;
V_139:
V_133:
F_54 ( V_125 ) ;
V_127:
return V_26 ;
}
int F_64 ( struct V_9 * V_9 )
{
int V_26 ;
struct V_13 * V_14 = F_5 ( V_9 ) ;
struct V_170 V_171 ;
struct V_165 V_172 ;
struct V_173 V_174 ;
struct V_175 V_176 ;
const struct V_1 * args [ 9 ] ;
unsigned V_159 = 0 ;
F_14 ( 3 , V_14 , L_77 , V_9 ) ;
if ( V_177 )
goto V_178;
if ( V_179 ) {
if ( F_63 ( V_9 ) ) {
V_171 . V_76 . type =
F_29 ( V_180 ) ;
V_171 . V_76 . V_6 = F_29 (
sizeof( V_171 ) - sizeof( V_171 . V_76 ) ) ;
V_171 . V_172 = 0 ;
V_171 . V_181 = 0 ;
args [ V_159 ++ ] = & V_171 . V_76 ;
} else {
V_172 . V_76 . type =
F_29 ( V_168 ) ;
V_172 . V_76 . V_6 = F_29 (
sizeof( V_172 ) - sizeof( V_172 . V_76 ) ) ;
V_172 . V_169 = 0 ;
args [ V_159 ++ ] = & V_172 . V_76 ;
}
}
if ( F_65 ( V_9 ) ) {
V_174 . V_76 . type =
F_29 ( V_182 ) ;
V_174 . V_76 . V_6 = F_29 (
sizeof( V_174 ) - sizeof( V_174 . V_76 ) ) ;
V_174 . V_183 = 1 ;
args [ V_159 ++ ] = & V_174 . V_76 ;
if ( V_9 -> V_184 ) {
V_176 . V_76 . type =
F_29 ( V_185 ) ;
V_176 . V_76 . V_6 = F_29 (
sizeof( V_176 ) - sizeof( V_176 . V_76 ) ) ;
V_176 . V_186 = 1 ;
args [ V_159 ++ ] = & V_176 . V_76 ;
}
}
V_26 = F_61 ( V_9 , args , V_159 ) ;
if ( V_26 < 0 )
goto error;
V_178:
V_26 = F_60 ( V_9 ) ;
error:
if ( V_26 < 0 )
F_7 ( V_14 , L_78 , V_26 ) ;
F_19 ( 3 , V_14 , L_79 , V_9 , V_26 ) ;
return V_26 ;
}
void F_66 ( struct V_9 * V_9 )
{
struct V_13 * V_14 = F_5 ( V_9 ) ;
F_14 ( 3 , V_14 , L_77 , V_9 ) ;
F_19 ( 3 , V_14 , L_80 , V_9 ) ;
}
