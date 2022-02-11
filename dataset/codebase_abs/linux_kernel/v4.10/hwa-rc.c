static
int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
const T_1 V_5 ,
T_1 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 , V_12 ;
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
V_8 = F_2 ( * V_4 , struct V_7 , V_16 ) ;
V_11 = V_5 ;
if ( V_11 < sizeof( * V_8 ) ) {
F_3 ( V_14 , L_1
L_2 ,
V_11 , sizeof( * V_8 ) ) ;
return - V_17 ;
}
V_11 -= sizeof( * V_8 ) ;
V_12 = F_4 ( V_8 -> V_18 ) ;
if ( V_11 < V_12 ) {
F_3 ( V_14 , L_1
L_3 ,
V_11 , V_12 ) ;
return - V_17 ;
}
V_10 = F_5 ( sizeof( * V_10 ) + V_12 , V_19 ) ;
if ( V_10 == NULL )
return - V_20 ;
V_10 -> V_16 = V_8 -> V_16 ;
V_10 -> V_21 = V_8 -> V_21 ;
V_10 -> V_22 = V_23 ;
V_10 -> V_24 = V_8 -> V_24 ;
V_10 -> V_25 = V_8 -> V_25 ;
V_10 -> V_26 = V_8 -> V_26 ;
V_10 -> V_18 = V_8 -> V_18 ;
memcpy ( V_10 -> V_27 , V_8 -> V_27 , V_12 ) ;
* V_4 = & V_10 -> V_16 ;
* V_6 = sizeof( * V_10 ) + V_12 ;
return 1 ;
}
static
int F_6 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
const T_1 V_5 ,
T_1 * V_6 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_1 V_11 , V_12 ;
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
V_29 = F_2 ( * V_4 , struct V_28 , V_16 ) ;
V_11 = V_5 ;
if ( V_11 < sizeof( * V_29 ) ) {
F_3 ( V_14 , L_4
L_5
L_6 , ( T_1 ) sizeof( * V_29 ) , V_11 ) ;
return - V_17 ;
}
V_11 -= sizeof( * V_29 ) ;
V_12 = F_4 ( V_29 -> V_34 ) ;
if ( V_11 < V_12 ) {
F_3 ( V_14 , L_7
L_8
L_9 , V_12 , V_11 ) ;
return - V_17 ;
}
if ( V_12 < sizeof( * V_33 ) ) {
F_3 ( V_14 , L_10
L_11 ,
V_12 , sizeof( * V_33 ) ) ;
return - V_17 ;
}
V_33 = ( void * ) V_29 -> V_35 ;
if ( V_33 -> V_36 > 32 ) {
F_3 ( V_14 , L_12
L_13
L_14 , ( T_1 ) V_33 -> V_36 ) ;
return - V_17 ;
}
V_31 = F_5 ( sizeof( * V_31 ) , V_19 ) ;
if ( V_31 == NULL )
return - V_20 ;
V_31 -> V_16 = V_29 -> V_16 ;
memcpy ( V_31 -> V_37 , ( V_38 * ) V_33 + sizeof( * V_33 ) , V_33 -> V_36 ) ;
* V_4 = & V_31 -> V_16 ;
* V_6 = sizeof( * V_31 ) ;
return 1 ;
}
static
int F_7 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
const T_1 V_5 ,
T_1 * V_6 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
T_1 V_11 , V_12 ;
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
V_40 = F_2 ( * V_4 , struct V_39 , V_16 ) ;
V_11 = V_5 ;
if ( V_11 < sizeof( * V_40 ) ) {
F_3 ( V_14 , L_15
L_16 ,
( T_1 ) sizeof( * V_40 ) , V_11 ) ;
return - V_17 ;
}
V_12 = F_4 ( V_40 -> V_34 ) ;
V_11 -= sizeof( * V_40 ) ;
if ( V_11 < V_12 ) {
F_3 ( V_14 , L_17
L_18
L_19 , V_12 , V_11 ) ;
return - V_17 ;
}
V_42 = F_5 ( sizeof( * V_42 ) + V_12 , V_19 ) ;
if ( V_42 == NULL )
return - V_20 ;
V_42 -> V_16 = V_40 -> V_16 ;
V_42 -> V_43 = V_40 -> V_44 ;
V_42 -> V_45 = V_46 ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = V_40 -> V_34 ;
memcpy ( V_42 -> V_49 , V_40 -> V_35 , V_12 ) ;
* V_4 = & V_42 -> V_16 ;
* V_6 = sizeof( * V_42 ) + V_12 ;
return 1 ;
}
static
int F_8 ( struct V_1 * V_2 ,
struct V_50 * * V_4 ,
T_1 * V_51 )
{
struct V_52 * V_53 ;
V_53 = F_2 ( * V_4 , struct V_52 , V_54 ) ;
if ( V_53 -> V_55 == V_56 )
V_53 -> V_55 = V_57 ;
* V_51 -= 2 ;
return 0 ;
}
static
int F_9 ( struct V_1 * V_2 ,
struct V_50 * * V_4 ,
T_1 * V_51 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_1 V_12 ;
V_59 = F_2 ( * V_4 , struct V_58 , V_54 ) ;
V_12 = F_4 ( V_59 -> V_34 ) ;
V_61 = F_5 ( sizeof( * V_61 ) + V_12 , V_62 ) ;
if ( V_61 == NULL )
return - V_20 ;
V_61 -> V_54 = V_59 -> V_54 ;
V_61 -> V_63 = 0 ;
V_61 -> V_34 = V_59 -> V_34 ;
memcpy ( V_61 -> V_35 , V_59 -> V_35 , V_12 ) ;
* V_4 = & V_61 -> V_54 ;
* V_51 = sizeof( * V_61 ) + V_12 ;
return 1 ;
}
static
int F_10 ( struct V_1 * V_2 , struct V_50 * * V_4 ,
T_1 * V_51 )
{
int V_64 ;
struct V_50 * V_54 = * V_4 ;
int V_61 = F_4 ( V_54 -> V_65 ) ;
switch ( V_61 ) {
case V_66 :
V_64 = F_8 ( V_2 , V_4 , V_51 ) ;
break;
case V_67 :
V_64 = F_9 ( V_2 , V_4 , V_51 ) ;
break;
default:
V_64 = - V_68 ;
break;
}
return V_64 ;
}
static
int F_11 ( struct V_1 * V_2 , struct V_50 * * V_4 ,
T_1 * V_51 )
{
int V_64 = - V_68 ;
if ( V_2 -> V_69 == 0x0100 )
V_64 = F_10 ( V_2 , V_4 , V_51 ) ;
return V_64 ;
}
static
T_2 F_12 ( struct V_1 * V_2 , const struct V_3 * V_16 ,
T_1 V_70 , T_1 V_71 ,
const T_1 V_5 )
{
T_2 V_51 = - V_72 ;
const void * V_73 = V_16 ;
T_1 V_74 = sizeof( V_75 ) ;
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
if ( V_71 + V_74 >= V_5 ) {
F_3 ( V_14 , L_20
L_21 ,
V_16 -> V_76 , F_4 ( V_16 -> V_77 ) ,
V_16 -> V_78 , V_5 ) ;
goto V_79;
}
V_73 += V_71 ;
V_51 = V_70 + F_4 ( * ( V_75 * ) V_73 ) ;
V_79:
return V_51 ;
}
static
int F_13 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
const T_1 V_5 , T_1 * V_80 ,
T_1 * V_81 )
{
int V_64 = - V_68 ;
struct V_3 * V_16 = * V_4 ;
int V_82 = F_4 ( V_16 -> V_77 ) ;
T_2 V_83 ;
T_1 V_70 , V_71 ;
if ( V_16 -> V_76 != V_84 )
goto V_79;
switch ( V_82 ) {
case V_85 :
V_70 = sizeof( struct V_7 ) ;
V_71 = F_14 ( struct V_7 ,
V_18 ) ;
V_83 = F_12 ( V_2 , V_16 , V_70 ,
V_71 , V_5 ) ;
if ( V_83 < 0 )
goto V_79;
* V_80 = V_83 ;
V_64 = F_1 ( V_2 , V_4 ,
V_5 , V_81 ) ;
break;
case V_86 :
* V_81 = * V_80 =
sizeof( struct V_87 ) ;
V_64 = 0 ;
break;
case V_88 :
V_70 = sizeof( struct V_28 ) ;
V_71 = F_14 ( struct V_28 ,
V_34 ) ;
V_83 = F_12 ( V_2 , V_16 , V_70 ,
V_71 , V_5 ) ;
if ( V_83 < 0 )
goto V_79;
* V_80 = V_83 ;
V_64 = F_6 (
V_2 , V_4 , V_5 , V_81 ) ;
break;
case V_89 :
V_70 = sizeof( struct V_39 ) ;
V_71 = F_14 ( struct V_39 , V_34 ) ;
V_83 = F_12 ( V_2 , V_16 , V_70 ,
V_71 , V_5 ) ;
if ( V_83 < 0 )
goto V_79;
* V_80 = V_83 ;
V_64 = F_7 ( V_2 , V_4 ,
V_5 , V_81 ) ;
break;
default:
break;
}
V_79:
return V_64 ;
}
static
int F_15 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
const T_1 V_5 , T_1 * V_80 ,
T_1 * V_81 )
{
int V_64 = - V_68 ;
if ( V_2 -> V_69 == 0x0100 )
V_64 = F_13 (
V_2 , V_4 , V_5 , V_80 , V_81 ) ;
return V_64 ;
}
static
int F_16 ( struct V_1 * V_1 , const struct V_50 * V_61 , T_1 V_90 )
{
struct V_91 * V_91 = V_1 -> V_92 ;
return F_17 (
V_91 -> V_93 , F_18 ( V_91 -> V_93 , 0 ) ,
V_94 , V_95 | V_96 | V_97 ,
0 , V_91 -> V_98 -> V_99 -> V_100 . V_101 ,
( void * ) V_61 , V_90 , 100 ) ;
}
static
int F_19 ( struct V_1 * V_1 )
{
struct V_91 * V_91 = V_1 -> V_92 ;
int V_64 ;
V_64 = F_20 ( V_91 -> V_93 , NULL ) ;
if ( V_64 >= 0 ) {
V_64 = F_21 ( V_91 -> V_93 ) ;
F_22 ( V_91 -> V_93 ) ;
}
return V_64 ;
}
static
void F_23 ( struct V_102 * V_102 )
{
struct V_91 * V_91 = V_102 -> V_103 ;
struct V_104 * V_98 = V_91 -> V_98 ;
struct V_13 * V_14 = & V_98 -> V_14 ;
int V_64 ;
switch ( V_64 = V_102 -> V_105 ) {
case 0 :
F_24 ( V_91 -> V_1 , V_102 -> V_106 ,
V_102 -> V_107 ) ;
break;
case - V_108 :
case - V_109 :
goto V_79;
case - V_110 :
goto V_79;
default:
if ( F_25 ( & V_91 -> V_111 , V_112 ,
V_113 ) )
goto V_114;
F_3 ( V_14 , L_22 , V_102 -> V_105 ) ;
}
V_64 = F_26 ( V_102 , V_19 ) ;
if ( V_64 < 0 && V_64 != - V_115 && V_64 != - V_116 ) {
F_3 ( V_14 , L_23 ,
V_64 ) ;
goto error;
}
V_79:
return;
V_114:
F_3 ( V_14 , L_24
L_25 ) ;
error:
F_27 ( V_91 -> V_1 , V_64 ) ;
F_28 ( V_91 -> V_1 ) ;
return;
}
static void F_29 ( struct V_91 * V_91 )
{
F_30 ( & V_91 -> V_111 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_91 * V_91 = V_2 -> V_92 ;
struct V_104 * V_117 = V_91 -> V_98 ;
struct V_118 * V_93 = F_32 ( V_117 ) ;
struct V_13 * V_14 = & V_117 -> V_14 ;
int V_64 ;
struct V_119 * V_120 ;
V_120 = & V_117 -> V_99 -> V_121 [ 0 ] . V_100 ;
V_91 -> V_122 = ( void * ) F_33 ( V_62 ) ;
if ( V_91 -> V_122 == NULL ) {
F_3 ( V_14 , L_26 ) ;
goto V_123;
}
V_91 -> V_124 = F_34 ( 0 , V_62 ) ;
if ( V_91 -> V_124 == NULL )
goto V_125;
F_35 ( V_91 -> V_124 , V_93 ,
F_36 ( V_93 , V_120 -> V_126 ) ,
V_91 -> V_122 , V_127 ,
F_23 , V_91 , V_120 -> V_128 ) ;
V_64 = F_26 ( V_91 -> V_124 , V_19 ) ;
if ( V_64 < 0 ) {
F_3 ( V_14 , L_27 , V_64 ) ;
goto V_129;
}
return 0 ;
V_129:
F_37 ( V_91 -> V_124 ) ;
V_91 -> V_124 = NULL ;
V_125:
F_38 ( ( unsigned long ) V_91 -> V_122 ) ;
V_91 -> V_122 = NULL ;
V_123:
return - V_20 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_91 * V_91 = V_2 -> V_92 ;
F_40 ( V_91 -> V_124 ) ;
F_37 ( V_91 -> V_124 ) ;
V_91 -> V_124 = NULL ;
F_38 ( ( unsigned long ) V_91 -> V_122 ) ;
V_91 -> V_122 = NULL ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_64 ;
struct V_91 * V_91 = V_2 -> V_92 ;
struct V_130 * V_131 ;
struct V_13 * V_14 = & V_2 -> V_15 . V_14 ;
struct V_118 * V_93 = V_91 -> V_93 ;
char * V_132 ;
struct V_133 * V_134 ;
T_1 V_135 , V_136 ;
T_3 V_69 ;
V_136 = ( V_93 -> V_137 - V_93 -> V_138 ) /
sizeof( V_93 -> V_138 [ 0 ] ) ;
V_132 = V_93 -> V_139 [ V_136 ] ;
V_135 = F_4 ( V_93 -> V_137 -> V_100 . V_140 ) ;
while ( V_135 >= sizeof( * V_134 ) ) {
V_134 = (struct V_133 * ) V_132 ;
F_42 ( V_14 , L_28
L_29 ,
V_134 -> V_141 , V_134 -> V_142 ,
( V_132 - V_93 -> V_139 [ V_136 ] ) ,
V_135 ) ;
if ( V_134 -> V_141 == V_143 )
goto V_144;
V_132 += V_134 -> V_142 ;
V_135 -= V_134 -> V_142 ;
}
F_3 ( V_14 , L_30 ) ;
return - V_115 ;
V_144:
V_64 = - V_17 ;
if ( V_134 -> V_142 > V_135 ) {
F_3 ( V_14 , L_31
L_32 ,
V_135 , V_134 -> V_142 ) ;
goto error;
}
if ( V_134 -> V_142 < sizeof( * V_131 ) ) {
F_3 ( V_14 , L_33
L_34 ) ;
goto error;
}
V_131 = (struct V_130 * ) V_134 ;
V_69 = F_43 ( V_131 -> V_145 ) ;
if ( V_69 != 0x0100 ) {
F_3 ( V_14 , L_35
L_36 , V_69 ) ;
V_64 = - V_17 ;
goto error;
}
V_2 -> V_69 = V_69 ;
F_42 ( V_14 , L_37 , V_2 -> V_69 ) ;
V_64 = 0 ;
error:
return V_64 ;
}
static int F_44 ( struct V_104 * V_117 ,
const struct V_146 * V_147 )
{
int V_64 ;
struct V_1 * V_1 ;
struct V_91 * V_91 ;
struct V_13 * V_14 = & V_117 -> V_14 ;
V_64 = - V_20 ;
V_1 = F_45 () ;
if ( V_1 == NULL ) {
F_3 ( V_14 , L_38 ) ;
goto V_148;
}
V_91 = F_5 ( sizeof( * V_91 ) , V_62 ) ;
if ( V_91 == NULL ) {
F_3 ( V_14 , L_39 ) ;
goto V_149;
}
F_29 ( V_91 ) ;
V_91 -> V_93 = F_46 ( F_32 ( V_117 ) ) ;
V_91 -> V_98 = F_47 ( V_117 ) ;
V_91 -> V_1 = V_1 ;
V_1 -> V_150 = V_151 ;
V_1 -> V_152 = F_31 ;
V_1 -> V_153 = F_39 ;
V_1 -> V_61 = F_16 ;
V_1 -> V_154 = F_19 ;
if ( V_147 -> V_155 & V_156 ) {
V_1 -> V_157 = NULL ;
V_1 -> V_158 = NULL ;
} else {
V_1 -> V_157 = F_11 ;
V_1 -> V_158 = F_15 ;
}
V_64 = F_48 ( V_1 , V_14 , V_91 ) ;
if ( V_64 < 0 )
goto V_159;
V_64 = F_41 ( V_1 ) ;
if ( V_64 < 0 ) {
F_3 ( V_14 , L_40 ) ;
goto V_160;
}
F_49 ( V_117 , V_91 ) ;
return 0 ;
V_160:
F_50 ( V_1 ) ;
V_159:
F_51 ( V_117 ) ;
F_52 ( V_91 -> V_93 ) ;
V_149:
F_53 ( V_1 ) ;
V_148:
return V_64 ;
}
static void F_54 ( struct V_104 * V_117 )
{
struct V_91 * V_91 = F_55 ( V_117 ) ;
struct V_1 * V_1 = V_91 -> V_1 ;
F_49 ( V_91 -> V_98 , NULL ) ;
F_50 ( V_1 ) ;
F_51 ( V_91 -> V_98 ) ;
F_52 ( V_91 -> V_93 ) ;
F_56 ( V_91 ) ;
F_53 ( V_1 ) ;
}
static int F_57 ( struct V_104 * V_117 )
{
struct V_91 * V_91 = F_55 ( V_117 ) ;
struct V_1 * V_1 = V_91 -> V_1 ;
F_58 ( V_1 ) ;
return 0 ;
}
static int F_59 ( struct V_104 * V_117 )
{
struct V_91 * V_91 = F_55 ( V_117 ) ;
struct V_1 * V_1 = V_91 -> V_1 ;
return F_60 ( V_1 ) ;
}
