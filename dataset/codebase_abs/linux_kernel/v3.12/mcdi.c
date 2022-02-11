static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( ! V_3 -> V_4 ) ;
return & V_3 -> V_4 -> V_5 ;
}
int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
bool V_6 ;
int V_7 ;
V_3 -> V_4 = F_4 ( sizeof( * V_3 -> V_4 ) , V_8 ) ;
if ( ! V_3 -> V_4 )
return - V_9 ;
V_4 = F_1 ( V_3 ) ;
V_4 -> V_3 = V_3 ;
F_5 ( & V_4 -> V_10 ) ;
F_6 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
F_6 ( & V_4 -> V_16 ) ;
F_7 ( & V_4 -> V_17 ) ;
F_8 ( & V_4 -> V_18 , V_19 ,
( unsigned long ) V_4 ) ;
( void ) F_9 ( V_3 ) ;
V_4 -> V_20 = true ;
V_7 = F_10 ( V_3 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_11 ( V_3 , true , & V_6 ) ;
if ( V_7 ) {
F_12 ( V_3 , V_21 , V_3 -> V_22 ,
L_1 ) ;
return V_7 ;
}
if ( V_6 )
F_12 ( V_3 , V_21 , V_3 -> V_22 ,
L_2 ) ;
return 0 ;
}
void F_13 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 )
return;
F_14 ( V_3 -> V_4 -> V_5 . V_12 != V_13 ) ;
F_11 ( V_3 , false , NULL ) ;
F_15 ( V_3 -> V_4 ) ;
}
static void F_16 ( struct V_2 * V_3 , unsigned V_23 ,
const T_1 * V_24 , T_2 V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_26 [ 2 ] ;
T_2 V_27 ;
T_3 V_28 , V_29 ;
F_14 ( V_4 -> V_12 == V_13 ) ;
F_17 ( & V_4 -> V_11 ) ;
++ V_4 -> V_29 ;
F_18 ( & V_4 -> V_11 ) ;
V_29 = V_4 -> V_29 & V_30 ;
V_28 = 0 ;
if ( V_4 -> V_14 == V_31 )
V_28 |= V_32 ;
if ( V_3 -> type -> V_33 == 1 ) {
F_19 ( V_26 [ 0 ] ,
V_34 , 0 ,
V_35 , 1 ,
V_36 , V_23 ,
V_37 , V_25 ,
V_38 , V_29 ,
V_39 , V_28 ,
V_40 , ! V_4 -> V_20 ) ;
V_27 = 4 ;
} else {
F_14 ( V_25 > V_41 ) ;
F_19 ( V_26 [ 0 ] ,
V_34 , 0 ,
V_35 , 1 ,
V_36 , V_42 ,
V_37 , 0 ,
V_38 , V_29 ,
V_39 , V_28 ,
V_40 , ! V_4 -> V_20 ) ;
F_20 ( V_26 [ 1 ] ,
V_43 , V_23 ,
V_44 , V_25 ) ;
V_27 = 8 ;
}
V_3 -> type -> V_45 ( V_3 , V_26 , V_27 , V_24 , V_25 ) ;
V_4 -> V_20 = false ;
}
static int F_21 ( unsigned int V_46 )
{
switch ( V_46 ) {
case 0 :
return 0 ;
#define F_22 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
return -name;
F_22 ( V_47 ) ;
F_22 ( V_48 ) ;
F_22 ( V_49 ) ;
F_22 ( V_50 ) ;
F_22 ( V_51 ) ;
F_22 ( V_52 ) ;
F_22 ( V_53 ) ;
F_22 ( V_54 ) ;
F_22 ( V_55 ) ;
F_22 ( V_56 ) ;
F_22 ( V_57 ) ;
F_22 ( V_58 ) ;
#undef F_22
case V_59 :
return - V_60 ;
case V_61 :
return - V_62 ;
default:
return - V_63 ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_64 , V_65 , error ;
T_1 V_26 ;
V_3 -> type -> V_66 ( V_3 , & V_26 , 0 , 4 ) ;
V_64 = F_24 ( V_26 , V_38 ) ;
V_65 = F_24 ( V_26 , V_36 ) ;
error = F_24 ( V_26 , V_67 ) ;
if ( V_65 != V_42 ) {
V_4 -> V_68 = 4 ;
V_4 -> V_69 = F_24 ( V_26 , V_37 ) ;
} else {
V_3 -> type -> V_66 ( V_3 , & V_26 , 4 , 4 ) ;
V_4 -> V_68 = 8 ;
V_4 -> V_69 =
F_24 ( V_26 , V_44 ) ;
}
if ( error && V_4 -> V_69 == 0 ) {
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_3 ) ;
V_4 -> V_71 = - V_72 ;
} else if ( ( V_64 ^ V_4 -> V_29 ) & V_30 ) {
F_12 ( V_3 , V_70 , V_3 -> V_22 ,
L_4 ,
V_64 , V_4 -> V_29 ) ;
V_4 -> V_71 = - V_72 ;
} else if ( error ) {
V_3 -> type -> V_66 ( V_3 , & V_26 , V_4 -> V_68 , 4 ) ;
V_4 -> V_71 =
F_21 ( F_24 ( V_26 , V_73 ) ) ;
} else {
V_4 -> V_71 = 0 ;
}
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long time , V_74 ;
unsigned int V_75 ;
int V_7 ;
V_7 = F_9 ( V_3 ) ;
if ( V_7 ) {
F_17 ( & V_4 -> V_11 ) ;
V_4 -> V_71 = V_7 ;
V_4 -> V_68 = 0 ;
V_4 -> V_69 = 0 ;
F_18 ( & V_4 -> V_11 ) ;
return 0 ;
}
V_75 = V_76 ;
V_74 = V_77 + V_78 ;
while ( 1 ) {
if ( V_75 != 0 ) {
-- V_75 ;
F_26 ( 1 ) ;
} else {
F_27 ( 1 ) ;
}
time = V_77 ;
F_28 () ;
if ( V_3 -> type -> V_79 ( V_3 ) )
break;
if ( F_29 ( time , V_74 ) )
return - V_80 ;
}
F_17 ( & V_4 -> V_11 ) ;
F_23 ( V_3 ) ;
F_18 ( & V_4 -> V_11 ) ;
return 0 ;
}
int F_9 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_4 )
return 0 ;
return V_3 -> type -> V_81 ( V_3 ) ;
}
static bool F_30 ( struct V_1 * V_4 )
{
return F_31 ( & V_4 -> V_12 ,
V_13 , V_82 ) ==
V_13 ;
}
static void F_32 ( struct V_1 * V_4 )
{
F_33 ( V_4 -> V_10 ,
F_31 ( & V_4 -> V_12 ,
V_13 , V_83 ) ==
V_13 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_35 ( V_4 -> V_10 , V_4 -> V_12 == V_84 ,
V_78 ) == 0 )
return - V_80 ;
if ( V_4 -> V_14 == V_15 )
return F_25 ( V_3 ) ;
return 0 ;
}
static bool F_36 ( struct V_1 * V_4 )
{
if ( F_31 ( & V_4 -> V_12 ,
V_83 , V_84 ) ==
V_83 ) {
F_37 ( & V_4 -> V_10 ) ;
return true ;
}
return false ;
}
static void F_38 ( struct V_1 * V_4 )
{
if ( V_4 -> V_14 == V_31 ) {
struct V_85 * V_86 ;
struct V_2 * V_3 = V_4 -> V_3 ;
F_17 ( & V_4 -> V_16 ) ;
V_86 = F_39 (
& V_4 -> V_17 , struct V_85 , V_87 ) ;
if ( V_86 ) {
V_4 -> V_12 = V_82 ;
F_16 ( V_3 , V_86 -> V_23 ,
( const T_1 * ) ( V_86 + 1 ) ,
V_86 -> V_25 ) ;
F_40 ( & V_4 -> V_18 ,
V_77 + V_78 ) ;
}
F_18 ( & V_4 -> V_16 ) ;
if ( V_86 )
return;
}
V_4 -> V_12 = V_13 ;
F_37 ( & V_4 -> V_10 ) ;
}
static bool F_41 ( struct V_1 * V_4 , bool V_88 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_85 * V_86 ;
T_2 V_27 , V_89 ;
T_1 * V_90 ;
int V_7 ;
if ( F_31 ( & V_4 -> V_12 ,
V_82 , V_84 ) !=
V_82 )
return false ;
F_42 ( & V_4 -> V_11 ) ;
if ( V_88 ) {
++ V_4 -> V_29 ;
++ V_4 -> V_91 ;
V_7 = - V_80 ;
V_27 = 0 ;
V_89 = 0 ;
} else {
V_7 = V_4 -> V_71 ;
V_27 = V_4 -> V_68 ;
V_89 = V_4 -> V_69 ;
}
F_43 ( & V_4 -> V_11 ) ;
if ( ! V_88 )
F_44 ( & V_4 -> V_18 ) ;
F_42 ( & V_4 -> V_16 ) ;
V_86 = F_45 ( & V_4 -> V_17 ,
struct V_85 , V_87 ) ;
F_46 ( & V_86 -> V_87 ) ;
F_43 ( & V_4 -> V_16 ) ;
V_90 = ( T_1 * ) ( V_86 + 1 ) ;
V_3 -> type -> V_66 ( V_3 , V_90 , V_27 ,
F_47 ( V_86 -> V_92 , V_89 ) ) ;
V_86 -> V_93 ( V_3 , V_86 -> V_94 , V_7 , V_90 , V_89 ) ;
F_15 ( V_86 ) ;
F_38 ( V_4 ) ;
return true ;
}
static void F_48 ( struct V_2 * V_3 , unsigned int V_29 ,
unsigned int V_95 , unsigned int V_46 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_96 = false ;
F_42 ( & V_4 -> V_11 ) ;
if ( ( V_29 ^ V_4 -> V_29 ) & V_30 ) {
if ( V_4 -> V_91 )
-- V_4 -> V_91 ;
else
F_12 ( V_3 , V_70 , V_3 -> V_22 ,
L_5
L_6 , V_29 , V_4 -> V_29 ) ;
} else {
if ( V_3 -> type -> V_33 >= 2 ) {
F_23 ( V_3 ) ;
} else {
V_4 -> V_71 = F_21 ( V_46 ) ;
V_4 -> V_68 = 4 ;
V_4 -> V_69 = V_95 ;
}
V_96 = true ;
}
F_43 ( & V_4 -> V_11 ) ;
if ( V_96 ) {
if ( ! F_41 ( V_4 , false ) )
( void ) F_36 ( V_4 ) ;
}
}
static void V_19 ( unsigned long V_97 )
{
struct V_1 * V_4 = (struct V_1 * ) V_97 ;
F_41 ( V_4 , true ) ;
}
static int
F_49 ( struct V_2 * V_3 , unsigned int V_23 , T_2 V_25 )
{
if ( V_3 -> type -> V_33 < 0 ||
( V_3 -> type -> V_33 < 2 &&
V_23 > V_98 ) )
return - V_53 ;
if ( V_25 > V_41 ||
( V_3 -> type -> V_33 < 2 &&
V_25 > V_99 ) )
return - V_100 ;
return 0 ;
}
int F_50 ( struct V_2 * V_3 , unsigned V_23 ,
const T_1 * V_24 , T_2 V_25 ,
T_1 * V_90 , T_2 V_92 ,
T_2 * V_101 )
{
int V_7 ;
V_7 = F_51 ( V_3 , V_23 , V_24 , V_25 ) ;
if ( V_7 )
return V_7 ;
return F_52 ( V_3 , V_23 , V_25 ,
V_90 , V_92 , V_101 ) ;
}
int F_51 ( struct V_2 * V_3 , unsigned V_23 ,
const T_1 * V_24 , T_2 V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
V_7 = F_49 ( V_3 , V_23 , V_25 ) ;
if ( V_7 )
return V_7 ;
F_32 ( V_4 ) ;
F_16 ( V_3 , V_23 , V_24 , V_25 ) ;
return 0 ;
}
int
F_53 ( struct V_2 * V_3 , unsigned int V_23 ,
const T_1 * V_24 , T_2 V_25 , T_2 V_92 ,
T_5 * V_93 , unsigned long V_94 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_85 * V_86 ;
int V_7 ;
V_7 = F_49 ( V_3 , V_23 , V_25 ) ;
if ( V_7 )
return V_7 ;
V_86 = F_54 ( sizeof( * V_86 ) + F_55 ( F_56 ( V_25 , V_92 ) , 4 ) ,
V_102 ) ;
if ( ! V_86 )
return - V_9 ;
V_86 -> V_23 = V_23 ;
V_86 -> V_25 = V_25 ;
V_86 -> V_92 = V_92 ;
V_86 -> V_93 = V_93 ;
V_86 -> V_94 = V_94 ;
memcpy ( V_86 + 1 , V_24 , V_25 ) ;
F_17 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_14 == V_31 ) {
F_57 ( & V_86 -> V_87 , & V_4 -> V_17 ) ;
if ( V_4 -> V_17 . V_103 == & V_86 -> V_87 &&
F_30 ( V_4 ) ) {
F_16 ( V_3 , V_23 , V_24 , V_25 ) ;
F_40 ( & V_4 -> V_18 ,
V_77 + V_78 ) ;
}
} else {
F_15 ( V_86 ) ;
V_7 = - V_104 ;
}
F_18 ( & V_4 -> V_16 ) ;
return V_7 ;
}
int F_52 ( struct V_2 * V_3 , unsigned V_23 , T_2 V_25 ,
T_1 * V_90 , T_2 V_92 ,
T_2 * V_101 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_7 ;
if ( V_4 -> V_14 == V_15 )
V_7 = F_25 ( V_3 ) ;
else
V_7 = F_34 ( V_3 ) ;
if ( V_7 != 0 ) {
F_17 ( & V_4 -> V_11 ) ;
++ V_4 -> V_29 ;
++ V_4 -> V_91 ;
F_18 ( & V_4 -> V_11 ) ;
F_12 ( V_3 , V_70 , V_3 -> V_22 ,
L_7 ,
V_23 , ( int ) V_25 , V_4 -> V_14 ) ;
} else {
T_2 V_27 , V_89 ;
F_17 ( & V_4 -> V_11 ) ;
V_7 = V_4 -> V_71 ;
V_27 = V_4 -> V_68 ;
V_89 = V_4 -> V_69 ;
F_18 ( & V_4 -> V_11 ) ;
F_14 ( V_7 > 0 ) ;
if ( V_7 == 0 ) {
V_3 -> type -> V_66 ( V_3 , V_90 , V_27 ,
F_47 ( V_92 , V_89 ) ) ;
if ( V_101 != NULL )
* V_101 = V_89 ;
} else if ( V_23 == V_105 && V_7 == - V_72 )
;
else if ( V_7 == - V_72 || V_7 == - V_49 ) {
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_8 ,
- V_7 ) ;
F_58 ( V_3 , V_106 ) ;
} else
F_59 ( V_3 , V_70 , V_3 -> V_22 ,
L_9 ,
V_23 , ( int ) V_25 , - V_7 ) ;
if ( V_7 == - V_72 || V_7 == - V_49 ) {
F_60 ( V_107 ) ;
F_9 ( V_3 ) ;
V_4 -> V_20 = true ;
}
}
F_38 ( V_4 ) ;
return V_7 ;
}
void F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 -> V_4 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_14 == V_15 )
return;
V_4 -> V_14 = V_15 ;
F_36 ( V_4 ) ;
}
void F_62 ( struct V_2 * V_3 )
{
struct V_85 * V_86 , * V_103 ;
struct V_1 * V_4 ;
if ( ! V_3 -> V_4 )
return;
V_4 = F_1 ( V_3 ) ;
F_14 ( V_4 -> V_14 != V_15 ) ;
F_44 ( & V_4 -> V_18 ) ;
if ( V_4 -> V_12 == V_82 ) {
F_25 ( V_3 ) ;
V_4 -> V_12 = V_13 ;
}
F_63 (async, next, &mcdi->async_list, list) {
V_86 -> V_93 ( V_3 , V_86 -> V_94 , - V_104 , NULL , 0 ) ;
F_46 ( & V_86 -> V_87 ) ;
F_15 ( V_86 ) ;
}
}
void F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 -> V_4 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_14 == V_31 )
return;
F_32 ( V_4 ) ;
V_4 -> V_14 = V_31 ;
F_38 ( V_4 ) ;
}
static void F_65 ( struct V_2 * V_3 , int V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_42 ( & V_4 -> V_11 ) ;
if ( F_36 ( V_4 ) ) {
if ( V_4 -> V_14 == V_31 ) {
V_4 -> V_71 = V_7 ;
V_4 -> V_68 = 0 ;
V_4 -> V_69 = 0 ;
++ V_4 -> V_91 ;
}
} else {
int V_108 ;
for ( V_108 = 0 ; V_108 < V_109 ; ++ V_108 ) {
if ( F_9 ( V_3 ) )
break;
F_26 ( V_110 ) ;
}
V_4 -> V_20 = true ;
F_58 ( V_3 , V_106 ) ;
}
F_43 ( & V_4 -> V_11 ) ;
}
void F_66 ( struct V_111 * V_112 ,
T_6 * V_113 )
{
struct V_2 * V_3 = V_112 -> V_3 ;
int V_114 = F_67 ( * V_113 , V_115 ) ;
T_3 V_116 = F_67 ( * V_113 , V_117 ) ;
switch ( V_114 ) {
case V_118 :
F_12 ( V_3 , V_70 , V_3 -> V_22 ,
L_10 , V_116 ) ;
F_65 ( V_3 , - V_49 ) ;
break;
case V_119 :
F_68 ( V_3 , V_120 , V_3 -> V_22 , L_11 ) ;
break;
case V_121 :
F_48 ( V_3 ,
F_69 ( * V_113 , V_122 ) ,
F_69 ( * V_113 , V_123 ) ,
F_69 ( * V_113 , V_124 ) ) ;
break;
case V_125 :
F_70 ( V_3 , V_113 ) ;
break;
case V_126 :
F_71 ( V_3 , V_113 ) ;
break;
case V_127 :
F_68 ( V_3 , V_70 , V_3 -> V_22 ,
L_12 , V_116 ) ;
break;
case V_128 :
case V_129 :
F_68 ( V_3 , V_70 , V_3 -> V_22 , L_13 ) ;
F_65 ( V_3 , - V_72 ) ;
break;
case V_130 :
break;
case V_131 :
F_72 ( V_3 , F_69 ( * V_113 , V_132 ) ) ;
break;
case V_133 :
case V_134 :
case V_135 :
F_73 ( V_3 , V_113 ) ;
break;
case V_136 :
case V_137 :
F_74 ( V_138 !=
V_139 ) ;
if ( ! F_69 ( * V_113 , V_140 ) )
F_75 ( V_3 ) ;
break;
case V_141 :
case V_142 :
F_12 ( V_3 , V_70 , V_3 -> V_22 ,
L_14 V_143 L_15 ,
V_114 == V_141 ? L_16 : L_17 ,
F_76 ( * V_113 ) ) ;
F_58 ( V_3 , V_144 ) ;
break;
default:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_18 ,
V_114 ) ;
}
}
void F_77 ( struct V_2 * V_3 , char * V_145 , T_2 V_146 )
{
F_78 ( V_90 ,
F_56 ( V_147 ,
V_148 ) ) ;
T_2 V_149 ;
const T_7 * V_150 ;
T_2 V_151 ;
int V_7 ;
F_74 ( V_152 != 0 ) ;
V_7 = F_50 ( V_3 , V_153 , NULL , 0 ,
V_90 , sizeof( V_90 ) , & V_149 ) ;
if ( V_7 )
goto V_154;
if ( V_149 < V_147 ) {
V_7 = - V_72 ;
goto V_154;
}
V_150 = ( T_7 * ) F_79 ( V_90 , V_155 ) ;
V_151 = snprintf ( V_145 , V_146 , L_19 ,
F_80 ( V_150 [ 0 ] ) , F_80 ( V_150 [ 1 ] ) ,
F_80 ( V_150 [ 2 ] ) , F_80 ( V_150 [ 3 ] ) ) ;
if ( F_81 ( V_3 ) >= V_156 ) {
F_74 ( V_157 != 0 ) ;
V_7 = F_50 ( V_3 , V_158 , NULL , 0 ,
V_90 , sizeof( V_90 ) , & V_149 ) ;
if ( V_7 || V_149 < V_148 )
V_151 += snprintf (
V_145 + V_151 , V_146 - V_151 , L_20 ) ;
else
V_151 += snprintf (
V_145 + V_151 , V_146 - V_151 , L_21 ,
F_82 ( V_90 ,
V_159 ) ,
F_82 ( V_90 ,
V_160 ) ) ;
if ( F_83 ( V_151 >= V_146 ) )
V_145 [ 0 ] = 0 ;
}
return;
V_154:
F_12 ( V_3 , V_21 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
V_145 [ 0 ] = 0 ;
}
static int F_11 ( struct V_2 * V_3 , bool V_162 ,
bool * V_163 )
{
F_78 ( V_24 , V_164 ) ;
F_78 ( V_90 , V_165 ) ;
T_2 V_92 ;
int V_7 ;
F_84 ( V_24 , V_166 ,
V_162 ? 1 : 0 ) ;
F_84 ( V_24 , V_167 , 1 ) ;
F_84 ( V_24 , V_168 , V_169 ) ;
V_7 = F_50 ( V_3 , V_170 , V_24 , sizeof( V_24 ) ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
if ( V_92 < V_171 ) {
V_7 = - V_72 ;
goto V_154;
}
if ( V_162 &&
V_92 >= V_165 &&
( F_85 ( V_90 , V_172 ) &
( 1 << V_173 |
1 << V_174 ) ) !=
( 1 << V_173 |
1 << V_174 ) ) {
F_12 ( V_3 , V_21 , V_3 -> V_22 ,
L_23 ) ;
return - V_175 ;
}
if ( V_163 != NULL )
* V_163 = F_85 ( V_90 , V_176 ) ;
return 0 ;
V_154:
F_12 ( V_3 , V_21 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int F_86 ( struct V_2 * V_3 , T_8 * V_177 ,
T_9 * V_178 , T_3 * V_179 )
{
F_78 ( V_90 , V_180 ) ;
T_2 V_92 , V_181 ;
int V_182 = F_87 ( V_3 ) ;
int V_7 ;
F_74 ( V_183 != 0 ) ;
V_7 = F_50 ( V_3 , V_184 , NULL , 0 ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
if ( V_92 < V_185 ) {
V_7 = - V_72 ;
goto V_154;
}
if ( V_177 )
memcpy ( V_177 ,
V_182 ?
F_79 ( V_90 , V_186 ) :
F_79 ( V_90 , V_187 ) ,
V_188 ) ;
if ( V_178 ) {
for ( V_181 = 0 ;
V_181 < F_88 ( V_92 ,
V_189 ) ;
V_181 ++ )
V_178 [ V_181 ] = F_89 (
V_90 , V_189 , V_181 ) ;
for (; V_181 < V_190 ; V_181 ++ )
V_178 [ V_181 ] = 0 ;
}
if ( V_179 ) {
if ( V_182 )
* V_179 = F_85 ( V_90 ,
V_191 ) ;
else
* V_179 = F_85 ( V_90 ,
V_192 ) ;
}
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_24 ,
V_161 , V_7 , ( int ) V_92 ) ;
return V_7 ;
}
int F_90 ( struct V_2 * V_3 , bool V_193 , bool V_194 , T_3 V_195 )
{
F_78 ( V_24 , V_196 ) ;
T_3 V_197 = 0 ;
int V_7 ;
if ( V_194 )
V_197 |= V_198 ;
if ( V_193 )
V_197 |= V_199 ;
F_84 ( V_24 , V_200 , V_197 ) ;
F_84 ( V_24 , V_201 , V_195 ) ;
F_74 ( V_202 != 0 ) ;
V_7 = F_50 ( V_3 , V_203 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int F_91 ( struct V_2 * V_3 , T_3 * V_204 )
{
F_78 ( V_90 , V_205 ) ;
T_2 V_92 ;
int V_7 ;
F_74 ( V_206 != 0 ) ;
V_7 = F_50 ( V_3 , V_207 , NULL , 0 ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
if ( V_92 < V_205 ) {
V_7 = - V_72 ;
goto V_154;
}
* V_204 = F_85 ( V_90 , V_208 ) ;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 ,
V_161 , V_7 ) ;
return V_7 ;
}
int F_92 ( struct V_2 * V_3 , unsigned int type ,
T_2 * V_209 , T_2 * V_210 ,
bool * V_211 )
{
F_78 ( V_24 , V_212 ) ;
F_78 ( V_90 , V_213 ) ;
T_2 V_92 ;
int V_7 ;
F_84 ( V_24 , V_214 , type ) ;
V_7 = F_50 ( V_3 , V_215 , V_24 , sizeof( V_24 ) ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
if ( V_92 < V_213 ) {
V_7 = - V_72 ;
goto V_154;
}
* V_209 = F_85 ( V_90 , V_216 ) ;
* V_210 = F_85 ( V_90 , V_217 ) ;
* V_211 = ! ! ( F_85 ( V_90 , V_218 ) &
( 1 << V_219 ) ) ;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
static int F_93 ( struct V_2 * V_3 , unsigned int type )
{
F_78 ( V_24 , V_220 ) ;
F_78 ( V_90 , V_221 ) ;
int V_7 ;
F_84 ( V_24 , V_222 , type ) ;
V_7 = F_50 ( V_3 , V_223 , V_24 , sizeof( V_24 ) ,
V_90 , sizeof( V_90 ) , NULL ) ;
if ( V_7 )
return V_7 ;
switch ( F_85 ( V_90 , V_224 ) ) {
case V_225 :
case V_226 :
return 0 ;
default:
return - V_72 ;
}
}
int F_94 ( struct V_2 * V_3 )
{
T_3 V_227 ;
unsigned int type ;
int V_7 ;
V_7 = F_91 ( V_3 , & V_227 ) ;
if ( V_7 )
goto V_228;
type = 0 ;
while ( V_227 != 0 ) {
if ( V_227 & 1 ) {
V_7 = F_93 ( V_3 , type ) ;
if ( V_7 )
goto V_229;
}
type ++ ;
V_227 >>= 1 ;
}
return 0 ;
V_229:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_25 ,
V_161 , type ) ;
V_228:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
static int F_95 ( struct V_2 * V_3 )
{
F_78 ( V_24 , V_230 ) ;
F_78 ( V_90 , V_231 ) ;
unsigned int V_232 , V_233 ;
const char * V_234 ;
T_2 V_92 ;
int V_235 ;
int V_7 ;
V_235 = 2 ;
do {
F_84 ( V_24 , V_236 , 1 ) ;
V_7 = F_50 ( V_3 , V_237 ,
V_24 , V_230 ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
} while ( ( V_7 == - V_49 || V_7 == - V_72 ) && V_235 -- > 0 );
if ( V_7 )
return V_7 ;
if ( V_92 < V_231 )
return - V_72 ;
V_232 = F_85 ( V_90 , V_238 ) ;
if ( V_232 == V_239 )
return 0 ;
V_234 = ( V_232 == V_240 )
? L_26
: ( V_232 == V_241 )
? L_27
: ( V_232 == V_242 )
? L_28
: L_29 ;
F_12 ( V_3 , V_70 , V_3 -> V_22 ,
L_30 , V_234 ,
F_85 ( V_90 , V_243 ) ,
F_85 ( V_90 , V_244 ) ) ;
for ( V_233 = 0 ;
V_233 < V_245 ;
V_233 ++ )
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_31 ,
1 + V_233 ,
F_96 ( V_90 , V_246 ,
V_233 ) ) ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
F_78 ( V_24 , V_247 ) ;
F_74 ( V_248 != 0 ) ;
F_84 ( V_24 , V_249 ,
V_250 ) ;
( void ) F_50 ( V_3 , V_105 , V_24 , V_247 ,
NULL , 0 , NULL ) ;
}
int F_10 ( struct V_2 * V_3 )
{
int V_7 ;
V_7 = F_95 ( V_3 ) ;
if ( V_7 )
return V_7 ;
F_97 ( V_3 ) ;
return 0 ;
}
void F_98 ( struct V_2 * V_3 , enum V_251 V_14 )
{
F_78 ( V_24 , V_252 ) ;
int V_7 ;
F_74 ( V_253 != V_254 ) ;
F_74 ( V_255 != V_256 ) ;
F_74 ( V_257 != V_258 ) ;
F_74 ( V_259 != 0 ) ;
F_84 ( V_24 , V_260 , V_14 ) ;
V_7 = F_50 ( V_3 , V_261 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 ,
V_161 , V_7 ) ;
}
static int F_99 ( struct V_2 * V_3 )
{
int V_7 = F_50 ( V_3 , V_262 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_7 )
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 ,
V_161 , V_7 ) ;
return V_7 ;
}
static int F_100 ( struct V_2 * V_3 )
{
F_78 ( V_24 , V_247 ) ;
int V_7 ;
F_74 ( V_248 != 0 ) ;
F_84 ( V_24 , V_249 , 0 ) ;
V_7 = F_50 ( V_3 , V_105 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 == - V_72 )
return 0 ;
if ( V_7 == 0 )
V_7 = - V_72 ;
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
enum V_263 F_101 ( enum V_263 V_234 )
{
return V_264 ;
}
int F_102 ( struct V_2 * V_3 , enum V_263 V_265 )
{
int V_7 ;
V_7 = F_10 ( V_3 ) ;
if ( V_7 )
return V_7 ;
if ( V_265 == V_266 )
return F_100 ( V_3 ) ;
else
return F_99 ( V_3 ) ;
}
static int F_103 ( struct V_2 * V_3 , T_3 type ,
const T_8 * V_267 , int * V_268 )
{
F_78 ( V_24 , V_269 ) ;
F_78 ( V_90 , V_270 ) ;
T_2 V_92 ;
int V_7 ;
F_84 ( V_24 , V_271 , type ) ;
F_84 ( V_24 , V_272 ,
V_273 ) ;
memcpy ( F_79 ( V_24 , V_274 ) , V_267 , V_188 ) ;
V_7 = F_50 ( V_3 , V_275 , V_24 , sizeof( V_24 ) ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
if ( V_92 < V_270 ) {
V_7 = - V_72 ;
goto V_154;
}
* V_268 = ( int ) F_85 ( V_90 , V_276 ) ;
return 0 ;
V_154:
* V_268 = - 1 ;
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int
F_104 ( struct V_2 * V_3 , const T_8 * V_267 , int * V_268 )
{
return F_103 ( V_3 , V_277 , V_267 , V_268 ) ;
}
int F_105 ( struct V_2 * V_3 , int * V_268 )
{
F_78 ( V_90 , V_278 ) ;
T_2 V_92 ;
int V_7 ;
V_7 = F_50 ( V_3 , V_279 , NULL , 0 ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
if ( V_92 < V_278 ) {
V_7 = - V_72 ;
goto V_154;
}
* V_268 = ( int ) F_85 ( V_90 , V_280 ) ;
return 0 ;
V_154:
* V_268 = - 1 ;
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int F_106 ( struct V_2 * V_3 , int V_281 )
{
F_78 ( V_24 , V_282 ) ;
int V_7 ;
F_84 ( V_24 , V_283 , ( T_3 ) V_281 ) ;
V_7 = F_50 ( V_3 , V_284 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int F_107 ( struct V_2 * V_3 )
{
struct V_111 * V_112 ;
struct V_285 * V_286 ;
F_78 ( V_24 ,
F_108 ( V_287 ) ) ;
int V_7 , V_108 ;
F_74 ( V_287 >
V_288 ) ;
V_108 = 0 ;
F_109 (channel, efx) {
F_110 (rx_queue, channel) {
if ( V_286 -> V_289 ) {
V_286 -> V_289 = false ;
F_111 ( & V_3 -> V_290 ) ;
F_112 (
V_24 , V_291 ,
V_108 , F_113 ( V_286 ) ) ;
V_108 ++ ;
}
}
}
V_7 = F_50 ( V_3 , V_292 , V_24 ,
F_108 ( V_108 ) , NULL , 0 , NULL ) ;
F_83 ( V_7 < 0 ) ;
return V_7 ;
}
int F_114 ( struct V_2 * V_3 )
{
int V_7 ;
V_7 = F_50 ( V_3 , V_293 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int F_115 ( struct V_2 * V_3 , T_3 type , bool V_294 )
{
F_78 ( V_24 , V_295 ) ;
F_74 ( V_296 != 0 ) ;
F_84 ( V_24 , V_297 , type ) ;
F_84 ( V_24 , V_298 , V_294 ) ;
return F_50 ( V_3 , V_299 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
}
static int F_116 ( struct V_2 * V_3 , unsigned int type )
{
F_78 ( V_24 , V_300 ) ;
int V_7 ;
F_84 ( V_24 , V_301 , type ) ;
F_74 ( V_302 != 0 ) ;
V_7 = F_50 ( V_3 , V_303 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
static int F_117 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_151 , T_8 * V_304 , T_2 V_305 )
{
F_78 ( V_24 , V_306 ) ;
F_78 ( V_90 ,
F_118 ( V_307 ) ) ;
T_2 V_92 ;
int V_7 ;
F_84 ( V_24 , V_308 , type ) ;
F_84 ( V_24 , V_309 , V_151 ) ;
F_84 ( V_24 , V_310 , V_305 ) ;
V_7 = F_50 ( V_3 , V_311 , V_24 , sizeof( V_24 ) ,
V_90 , sizeof( V_90 ) , & V_92 ) ;
if ( V_7 )
goto V_154;
memcpy ( V_304 , F_79 ( V_90 , V_312 ) , V_305 ) ;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
static int F_119 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_151 , const T_8 * V_304 , T_2 V_305 )
{
F_78 ( V_24 ,
F_120 ( V_307 ) ) ;
int V_7 ;
F_84 ( V_24 , V_313 , type ) ;
F_84 ( V_24 , V_314 , V_151 ) ;
F_84 ( V_24 , V_315 , V_305 ) ;
memcpy ( F_79 ( V_24 , V_316 ) , V_304 , V_305 ) ;
F_74 ( V_317 != 0 ) ;
V_7 = F_50 ( V_3 , V_318 , V_24 ,
F_55 ( F_120 ( V_305 ) , 4 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
static int F_121 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_151 , T_2 V_305 )
{
F_78 ( V_24 , V_319 ) ;
int V_7 ;
F_84 ( V_24 , V_320 , type ) ;
F_84 ( V_24 , V_321 , V_151 ) ;
F_84 ( V_24 , V_322 , V_305 ) ;
F_74 ( V_323 != 0 ) ;
V_7 = F_50 ( V_3 , V_324 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
static int F_122 ( struct V_2 * V_3 , unsigned int type )
{
F_78 ( V_24 , V_325 ) ;
int V_7 ;
F_84 ( V_24 , V_326 , type ) ;
F_74 ( V_327 != 0 ) ;
V_7 = F_50 ( V_3 , V_328 , V_24 , sizeof( V_24 ) ,
NULL , 0 , NULL ) ;
if ( V_7 )
goto V_154;
return 0 ;
V_154:
F_12 ( V_3 , V_70 , V_3 -> V_22 , L_22 , V_161 , V_7 ) ;
return V_7 ;
}
int F_123 ( struct V_329 * V_330 , T_10 V_331 ,
T_2 V_146 , T_2 * V_332 , T_8 * V_304 )
{
struct V_333 * V_334 = F_124 ( V_330 ) ;
struct V_2 * V_3 = V_330 -> V_335 ;
T_10 V_151 = V_331 ;
T_10 V_336 = F_125 ( T_10 , V_331 + V_146 , V_330 -> V_337 ) ;
T_2 V_338 ;
int V_7 = 0 ;
while ( V_151 < V_336 ) {
V_338 = F_125 ( T_2 , V_336 - V_151 , V_307 ) ;
V_7 = F_117 ( V_3 , V_334 -> V_339 , V_151 ,
V_304 , V_338 ) ;
if ( V_7 )
goto V_340;
V_151 += V_338 ;
V_304 += V_338 ;
}
V_340:
* V_332 = V_151 - V_331 ;
return V_7 ;
}
int F_126 ( struct V_329 * V_330 , T_10 V_331 , T_2 V_146 )
{
struct V_333 * V_334 = F_124 ( V_330 ) ;
struct V_2 * V_3 = V_330 -> V_335 ;
T_10 V_151 = V_331 & ~ ( ( T_10 ) ( V_330 -> V_341 - 1 ) ) ;
T_10 V_336 = F_125 ( T_10 , V_331 + V_146 , V_330 -> V_337 ) ;
T_2 V_338 = V_334 -> V_342 . V_330 . V_341 ;
int V_7 = 0 ;
if ( ! V_334 -> V_343 ) {
V_7 = F_116 ( V_3 , V_334 -> V_339 ) ;
if ( V_7 )
goto V_340;
V_334 -> V_343 = true ;
}
while ( V_151 < V_336 ) {
V_7 = F_121 ( V_3 , V_334 -> V_339 , V_151 ,
V_338 ) ;
if ( V_7 )
goto V_340;
V_151 += V_338 ;
}
V_340:
return V_7 ;
}
int F_127 ( struct V_329 * V_330 , T_10 V_331 ,
T_2 V_146 , T_2 * V_332 , const T_8 * V_304 )
{
struct V_333 * V_334 = F_124 ( V_330 ) ;
struct V_2 * V_3 = V_330 -> V_335 ;
T_10 V_151 = V_331 ;
T_10 V_336 = F_125 ( T_10 , V_331 + V_146 , V_330 -> V_337 ) ;
T_2 V_338 ;
int V_7 = 0 ;
if ( ! V_334 -> V_343 ) {
V_7 = F_116 ( V_3 , V_334 -> V_339 ) ;
if ( V_7 )
goto V_340;
V_334 -> V_343 = true ;
}
while ( V_151 < V_336 ) {
V_338 = F_125 ( T_2 , V_336 - V_151 , V_307 ) ;
V_7 = F_119 ( V_3 , V_334 -> V_339 , V_151 ,
V_304 , V_338 ) ;
if ( V_7 )
goto V_340;
V_151 += V_338 ;
V_304 += V_338 ;
}
V_340:
* V_332 = V_151 - V_331 ;
return V_7 ;
}
int F_128 ( struct V_329 * V_330 )
{
struct V_333 * V_334 = F_124 ( V_330 ) ;
struct V_2 * V_3 = V_330 -> V_335 ;
int V_7 = 0 ;
if ( V_334 -> V_343 ) {
V_334 -> V_343 = false ;
V_7 = F_122 ( V_3 , V_334 -> V_339 ) ;
}
return V_7 ;
}
void F_129 ( struct V_344 * V_334 )
{
struct V_333 * V_345 =
F_130 ( V_334 , struct V_333 , V_342 ) ;
struct V_2 * V_3 = V_334 -> V_330 . V_335 ;
snprintf ( V_334 -> T_4 , sizeof( V_334 -> T_4 ) , L_32 ,
V_3 -> T_4 , V_334 -> V_346 , V_345 -> V_347 ) ;
}
