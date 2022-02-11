static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_7 ;
int V_8 ;
if ( ! V_6 )
return 0 ;
for ( V_8 = 0 ; V_6 [ V_8 ] . V_9 ; V_8 ++ ) {
V_4 [ V_8 ] . V_10 = F_2 ( V_2 , V_6 [ V_8 ] . V_9 ) ;
if ( F_3 ( V_4 [ V_8 ] . V_10 ) ) {
V_7 = F_4 ( V_4 [ V_8 ] . V_10 ) ;
if ( V_7 != - V_11 )
F_5 ( V_2 , L_1 ,
V_6 [ V_8 ] . V_9 ) ;
return V_7 ;
}
V_4 [ V_8 ] . V_12 = V_6 [ V_8 ] . V_12 ;
V_4 [ V_8 ] . V_13 = V_6 [ V_8 ] . V_13 ;
}
return V_8 ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_3 * V_4 , int V_16 )
{
int V_17 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ ) {
if ( V_4 [ V_8 ] . V_12 > 0 ) {
V_17 = F_7 ( V_4 [ V_8 ] . V_10 ,
V_4 [ V_8 ] . V_12 , V_18 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 ,
L_2 ,
V_8 ) ;
goto V_19;
}
}
if ( V_4 [ V_8 ] . V_13 > 0 ) {
V_17 = F_8 ( V_4 [ V_8 ] . V_10 ,
V_4 [ V_8 ] . V_13 ) ;
if ( V_17 < 0 ) {
F_5 ( V_15 -> V_2 ,
L_3 ) ;
goto V_19;
}
}
V_17 = F_9 ( V_4 [ V_8 ] . V_10 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_4 ) ;
goto V_19;
}
}
return 0 ;
V_19:
for (; V_8 >= 0 ; V_8 -- ) {
if ( V_4 [ V_8 ] . V_12 > 0 )
F_7 ( V_4 [ V_8 ] . V_10 , 0 , V_18 ) ;
if ( V_4 [ V_8 ] . V_13 > 0 )
F_8 ( V_4 [ V_8 ] . V_10 , 0 ) ;
F_10 ( V_4 [ V_8 ] . V_10 ) ;
}
return V_17 ;
}
static void F_11 ( struct V_14 * V_15 ,
struct V_3 * V_4 , int V_16 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ ) {
if ( V_4 [ V_8 ] . V_12 > 0 )
F_7 ( V_4 [ V_8 ] . V_10 , 0 , V_18 ) ;
if ( V_4 [ V_8 ] . V_13 > 0 )
F_8 ( V_4 [ V_8 ] . V_10 , 0 ) ;
F_10 ( V_4 [ V_8 ] . V_10 ) ;
}
}
static int F_12 ( struct V_1 * V_2 ,
struct V_20 * * V_21 , int V_16 )
{
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ ) {
V_7 = F_13 ( V_21 [ V_8 ] ) ;
if ( V_7 ) {
F_5 ( V_2 , L_5 ) ;
goto V_19;
}
}
return 0 ;
V_19:
for ( V_8 -- ; V_8 >= 0 ; V_8 -- )
F_14 ( V_21 [ V_8 ] ) ;
return V_7 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_20 * * V_21 , int V_16 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ )
F_14 ( V_21 [ V_8 ] ) ;
}
static struct V_22 * F_16 ( struct V_23 * V_23 ,
const struct V_24 * V_25 ,
int * V_26 )
{
static struct V_22 V_27 = { . V_28 = 1 , } ;
* V_26 = sizeof( V_27 ) ;
return & V_27 ;
}
static int F_17 ( struct V_23 * V_23 , const struct V_24 * V_25 )
{
struct V_14 * V_15 = V_23 -> V_29 ;
memcpy ( V_15 -> V_30 , V_25 -> V_31 , V_25 -> V_32 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 , int V_33 )
{
unsigned long V_34 ;
T_1 V_35 ;
V_34 = V_36 + F_19 ( V_33 ) ;
for (; ; ) {
V_35 = F_20 ( V_15 -> V_37 + V_38 ) ;
if ( V_35 )
break;
if ( F_21 ( V_36 , V_34 ) )
return - V_39 ;
F_22 ( 1 ) ;
}
return V_35 ;
}
static int F_23 ( struct V_14 * V_15 , T_2 V_40 , int V_33 )
{
unsigned long V_34 ;
T_1 V_35 ;
V_34 = V_36 + F_19 ( V_33 ) ;
for (; ; ) {
V_35 = F_20 ( V_15 -> V_37 + V_41 ) ;
if ( V_35 < 0 )
break;
if ( ! V_40 && V_35 )
break;
else if ( V_40 && V_35 == V_40 )
break;
if ( F_21 ( V_36 , V_34 ) )
return - V_39 ;
F_22 ( 1 ) ;
}
return V_35 ;
}
static int F_24 ( struct V_14 * V_15 )
{
T_2 V_35 ;
int V_17 ;
V_35 = F_20 ( V_15 -> V_42 + V_43 ) ;
V_35 |= ( V_44 | V_45 | V_46 ) ;
F_25 ( V_35 , V_15 -> V_42 + V_43 ) ;
V_35 = F_20 ( V_15 -> V_42 + V_47 ) ;
V_35 |= V_48 | V_49 ;
F_25 ( V_35 , V_15 -> V_42 + V_47 ) ;
F_26 ( 1 ) ;
V_35 = F_20 ( V_15 -> V_42 + V_47 ) ;
V_35 |= V_50 | V_51 |
V_52 | V_53 ;
F_25 ( V_35 , V_15 -> V_42 + V_47 ) ;
V_35 |= V_54 ;
F_25 ( V_35 , V_15 -> V_42 + V_47 ) ;
V_35 |= V_55 ;
F_25 ( V_35 , V_15 -> V_42 + V_47 ) ;
V_35 |= V_56 ;
F_25 ( V_35 , V_15 -> V_42 + V_47 ) ;
V_35 &= ~ V_57 ;
F_25 ( V_35 , V_15 -> V_42 + V_47 ) ;
V_35 = F_20 ( V_15 -> V_42 + V_43 ) ;
V_35 &= ~ V_44 ;
F_25 ( V_35 , V_15 -> V_42 + V_43 ) ;
V_35 = F_20 ( V_15 -> V_42 + V_58 ) ;
V_35 |= V_59 ;
F_25 ( V_35 , V_15 -> V_42 + V_58 ) ;
V_35 = F_20 ( V_15 -> V_42 + V_43 ) ;
V_35 &= ~ V_46 ;
F_25 ( V_35 , V_15 -> V_42 + V_43 ) ;
V_17 = F_18 ( V_15 , 1000 ) ;
if ( V_17 == - V_39 ) {
F_5 ( V_15 -> V_2 , L_6 ) ;
} else if ( V_17 != V_60 ) {
F_5 ( V_15 -> V_2 , L_7 , V_17 ) ;
V_17 = - V_61 ;
} else {
V_17 = 0 ;
}
return V_17 ;
}
static void F_27 ( struct V_14 * V_15 ,
struct V_62 * V_63 ,
T_2 V_64 )
{
unsigned long V_34 ;
unsigned int V_35 ;
int V_17 ;
V_17 = F_28 ( V_63 , V_64 + V_65 , & V_35 ) ;
if ( ! V_17 && V_35 )
return;
F_29 ( V_63 , V_64 + V_66 , 1 ) ;
V_34 = V_36 + F_19 ( V_67 ) ;
for (; ; ) {
V_17 = F_28 ( V_63 , V_64 + V_68 , & V_35 ) ;
if ( V_17 || V_35 || F_21 ( V_36 , V_34 ) )
break;
F_22 ( 1 ) ;
}
V_17 = F_28 ( V_63 , V_64 + V_65 , & V_35 ) ;
if ( V_17 || ! V_35 )
F_5 ( V_15 -> V_2 , L_8 ) ;
F_29 ( V_63 , V_64 + V_66 , 0 ) ;
}
static int F_30 ( struct V_14 * V_15 , const struct V_24 * V_25 )
{
unsigned long V_69 = V_70 ;
T_3 V_71 ;
void * V_72 ;
int V_17 ;
V_72 = F_31 ( V_15 -> V_2 , V_25 -> V_32 , & V_71 , V_73 , V_69 ) ;
if ( ! V_72 ) {
F_5 ( V_15 -> V_2 , L_9 ) ;
return - V_74 ;
}
memcpy ( V_72 , V_25 -> V_31 , V_25 -> V_32 ) ;
F_25 ( V_71 , V_15 -> V_37 + V_75 ) ;
F_25 ( V_76 , V_15 -> V_37 + V_77 ) ;
V_17 = F_23 ( V_15 , V_78 , 1000 ) ;
if ( V_17 == - V_39 )
F_5 ( V_15 -> V_2 , L_10 ) ;
else if ( V_17 < 0 )
F_5 ( V_15 -> V_2 , L_11 , V_17 ) ;
F_32 ( V_15 -> V_2 , V_25 -> V_32 , V_72 , V_71 , V_69 ) ;
return V_17 < 0 ? V_17 : 0 ;
}
static bool F_33 ( const struct V_79 * V_80 )
{
if ( V_80 -> V_81 != V_82 )
return false ;
if ( ( V_80 -> V_83 & V_84 ) == V_85 )
return false ;
if ( ! V_80 -> V_86 )
return false ;
return true ;
}
static int F_34 ( struct V_14 * V_15 )
{
const struct V_79 * V_87 ;
const struct V_79 * V_80 ;
const struct V_24 * V_88 ;
const struct V_24 * V_25 ;
struct V_89 * V_90 ;
T_4 V_91 ;
T_4 V_92 ;
T_4 V_93 = ( T_4 ) V_94 ;
T_4 V_95 = 0 ;
bool V_96 = false ;
char V_97 [ 10 ] ;
T_5 V_64 ;
T_6 V_32 ;
void * V_72 ;
int V_17 ;
int V_8 ;
V_17 = F_35 ( & V_25 , L_12 , V_15 -> V_2 ) ;
if ( V_17 < 0 ) {
F_5 ( V_15 -> V_2 , L_13 ) ;
return V_17 ;
}
F_25 ( 0 , V_15 -> V_37 + V_98 ) ;
V_17 = F_30 ( V_15 , V_25 ) ;
if ( V_17 )
goto V_99;
V_90 = (struct V_89 * ) V_25 -> V_31 ;
V_87 = (struct V_79 * ) ( V_90 + 1 ) ;
for ( V_8 = 0 ; V_8 < V_90 -> V_100 ; V_8 ++ ) {
V_80 = & V_87 [ V_8 ] ;
if ( ! F_33 ( V_80 ) )
continue;
if ( V_80 -> V_83 & V_101 )
V_96 = true ;
if ( V_80 -> V_102 < V_93 )
V_93 = V_80 -> V_102 ;
if ( V_80 -> V_102 + V_80 -> V_86 > V_95 )
V_95 = F_36 ( V_80 -> V_102 + V_80 -> V_86 , V_103 ) ;
}
V_91 = V_96 ? V_93 : V_15 -> V_104 ;
for ( V_8 = 0 ; V_8 < V_90 -> V_100 ; V_8 ++ ) {
V_80 = & V_87 [ V_8 ] ;
if ( ! F_33 ( V_80 ) )
continue;
V_64 = V_80 -> V_102 - V_91 ;
if ( V_64 < 0 || V_64 + V_80 -> V_86 > V_15 -> V_105 ) {
F_5 ( V_15 -> V_2 , L_14 ) ;
V_17 = - V_61 ;
goto V_99;
}
V_72 = V_15 -> V_106 + V_64 ;
if ( V_80 -> V_107 ) {
snprintf ( V_97 , sizeof( V_97 ) , L_15 , V_8 ) ;
V_17 = F_35 ( & V_88 , V_97 , V_15 -> V_2 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_16 , V_97 ) ;
goto V_99;
}
memcpy ( V_72 , V_88 -> V_31 , V_88 -> V_32 ) ;
V_99 ( V_88 ) ;
}
if ( V_80 -> V_86 > V_80 -> V_107 ) {
memset ( V_72 + V_80 -> V_107 , 0 ,
V_80 -> V_86 - V_80 -> V_107 ) ;
}
V_32 = F_20 ( V_15 -> V_37 + V_98 ) ;
if ( ! V_32 ) {
V_92 = V_96 ? V_15 -> V_104 : V_93 ;
F_25 ( V_92 , V_15 -> V_37 + V_108 ) ;
F_25 ( V_109 , V_15 -> V_37 + V_77 ) ;
}
V_32 += V_80 -> V_86 ;
F_25 ( V_32 , V_15 -> V_37 + V_98 ) ;
}
V_17 = F_23 ( V_15 , V_110 , 10000 ) ;
if ( V_17 == - V_39 )
F_5 ( V_15 -> V_2 , L_17 ) ;
else if ( V_17 < 0 )
F_5 ( V_15 -> V_2 , L_18 , V_17 ) ;
V_99:
V_99 ( V_25 ) ;
return V_17 < 0 ? V_17 : 0 ;
}
static int F_37 ( struct V_23 * V_23 )
{
struct V_14 * V_15 = (struct V_14 * ) V_23 -> V_29 ;
int V_17 ;
V_17 = F_6 ( V_15 , V_15 -> V_111 ,
V_15 -> V_112 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_19 ) ;
return V_17 ;
}
V_17 = F_12 ( V_15 -> V_2 , V_15 -> V_113 ,
V_15 -> V_114 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_20 ) ;
goto V_115;
}
V_17 = F_6 ( V_15 , V_15 -> V_116 ,
V_15 -> V_117 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_21 ) ;
goto V_118;
}
V_17 = F_38 ( V_15 -> V_119 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_22 ) ;
goto V_120;
}
V_17 = F_12 ( V_15 -> V_2 , V_15 -> V_121 ,
V_15 -> V_122 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_23 ) ;
goto V_123;
}
F_25 ( V_15 -> V_124 , V_15 -> V_37 + V_125 ) ;
V_17 = F_24 ( V_15 ) ;
if ( V_17 )
goto V_126;
V_17 = F_23 ( V_15 , 0 , 5000 ) ;
if ( V_17 == - V_39 ) {
F_5 ( V_15 -> V_2 , L_24 ) ;
goto V_126;
} else if ( V_17 != V_127 &&
V_17 != V_128 ) {
F_5 ( V_15 -> V_2 , L_25 , V_17 ) ;
V_17 = - V_61 ;
goto V_126;
}
F_39 ( V_15 -> V_2 , L_26 ) ;
V_17 = F_34 ( V_15 ) ;
if ( V_17 )
goto V_126;
V_17 = F_40 ( & V_15 -> V_129 ,
F_19 ( 5000 ) ) ;
if ( V_17 == 0 ) {
F_5 ( V_15 -> V_2 , L_27 ) ;
V_17 = - V_39 ;
goto V_126;
}
V_15 -> V_130 = true ;
F_15 ( V_15 -> V_2 , V_15 -> V_113 ,
V_15 -> V_114 ) ;
F_11 ( V_15 , V_15 -> V_111 ,
V_15 -> V_112 ) ;
return 0 ;
V_126:
F_27 ( V_15 , V_15 -> V_63 , V_15 -> V_131 ) ;
F_27 ( V_15 , V_15 -> V_63 , V_15 -> V_132 ) ;
F_27 ( V_15 , V_15 -> V_63 , V_15 -> V_133 ) ;
F_15 ( V_15 -> V_2 , V_15 -> V_121 ,
V_15 -> V_122 ) ;
V_123:
F_41 ( V_15 -> V_119 ) ;
V_120:
F_11 ( V_15 , V_15 -> V_116 ,
V_15 -> V_117 ) ;
V_118:
F_15 ( V_15 -> V_2 , V_15 -> V_113 ,
V_15 -> V_114 ) ;
V_115:
F_11 ( V_15 , V_15 -> V_111 ,
V_15 -> V_112 ) ;
return V_17 ;
}
static int F_42 ( struct V_23 * V_23 )
{
struct V_14 * V_15 = (struct V_14 * ) V_23 -> V_29 ;
int V_17 ;
V_15 -> V_130 = false ;
F_43 ( V_15 -> V_134 ,
F_44 ( V_15 -> V_135 ) , F_44 ( V_15 -> V_135 ) ) ;
V_17 = F_40 ( & V_15 -> V_136 ,
F_19 ( 5000 ) ) ;
if ( V_17 == 0 )
F_5 ( V_15 -> V_2 , L_28 ) ;
F_43 ( V_15 -> V_134 , F_44 ( V_15 -> V_135 ) , 0 ) ;
F_27 ( V_15 , V_15 -> V_63 , V_15 -> V_131 ) ;
F_27 ( V_15 , V_15 -> V_63 , V_15 -> V_132 ) ;
F_27 ( V_15 , V_15 -> V_63 , V_15 -> V_133 ) ;
F_41 ( V_15 -> V_119 ) ;
F_15 ( V_15 -> V_2 , V_15 -> V_121 ,
V_15 -> V_122 ) ;
F_11 ( V_15 , V_15 -> V_116 ,
V_15 -> V_117 ) ;
return 0 ;
}
static void * F_45 ( struct V_23 * V_23 , T_7 V_137 , int V_138 )
{
struct V_14 * V_15 = V_23 -> V_29 ;
int V_64 ;
V_64 = V_137 - V_15 -> V_91 ;
if ( V_64 < 0 || V_64 + V_138 > V_15 -> V_105 )
return NULL ;
return V_15 -> V_106 + V_64 ;
}
static T_8 F_46 ( int V_139 , void * V_2 )
{
struct V_14 * V_15 = V_2 ;
T_6 V_138 ;
char * V_140 ;
if ( ! V_15 -> V_130 ) {
F_47 ( & V_15 -> V_136 ) ;
return V_141 ;
}
V_140 = F_48 ( V_142 , V_143 , & V_138 ) ;
if ( ! F_3 ( V_140 ) && V_138 > 0 && V_140 [ 0 ] )
F_5 ( V_15 -> V_2 , L_29 , V_140 ) ;
else
F_5 ( V_15 -> V_2 , L_30 ) ;
F_49 ( V_15 -> V_23 , V_144 ) ;
if ( ! F_3 ( V_140 ) )
V_140 [ 0 ] = '\0' ;
return V_141 ;
}
static T_8 F_50 ( int V_139 , void * V_2 )
{
struct V_14 * V_15 = V_2 ;
T_6 V_138 ;
char * V_140 ;
V_140 = F_48 ( V_142 , V_143 , & V_138 ) ;
if ( ! F_3 ( V_140 ) && V_138 > 0 && V_140 [ 0 ] )
F_5 ( V_15 -> V_2 , L_31 , V_140 ) ;
else
F_5 ( V_15 -> V_2 , L_32 ) ;
F_49 ( V_15 -> V_23 , V_145 ) ;
if ( ! F_3 ( V_140 ) )
V_140 [ 0 ] = '\0' ;
return V_141 ;
}
static T_8 F_51 ( int V_139 , void * V_2 )
{
struct V_14 * V_15 = V_2 ;
F_47 ( & V_15 -> V_129 ) ;
return V_141 ;
}
static T_8 F_52 ( int V_139 , void * V_2 )
{
struct V_14 * V_15 = V_2 ;
F_47 ( & V_15 -> V_136 ) ;
return V_141 ;
}
static int F_53 ( struct V_14 * V_15 , struct V_146 * V_147 )
{
struct V_148 args ;
struct V_149 * V_150 ;
int V_17 ;
V_150 = F_54 ( V_147 , V_151 , L_33 ) ;
V_15 -> V_42 = F_55 ( & V_147 -> V_2 , V_150 ) ;
if ( F_3 ( V_15 -> V_42 ) )
return F_4 ( V_15 -> V_42 ) ;
V_150 = F_54 ( V_147 , V_151 , L_34 ) ;
V_15 -> V_37 = F_55 ( & V_147 -> V_2 , V_150 ) ;
if ( F_3 ( V_15 -> V_37 ) )
return F_4 ( V_15 -> V_37 ) ;
V_17 = F_56 ( V_147 -> V_2 . V_152 ,
L_35 , 3 , 0 , & args ) ;
if ( V_17 < 0 ) {
F_5 ( & V_147 -> V_2 , L_36 ) ;
return - V_61 ;
}
V_15 -> V_63 = F_57 ( args . V_153 ) ;
F_58 ( args . V_153 ) ;
if ( F_3 ( V_15 -> V_63 ) )
return F_4 ( V_15 -> V_63 ) ;
V_15 -> V_131 = args . args [ 0 ] ;
V_15 -> V_132 = args . args [ 1 ] ;
V_15 -> V_133 = args . args [ 2 ] ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_20 * * V_21 ,
char * * V_154 )
{
int V_8 ;
if ( ! V_154 )
return 0 ;
for ( V_8 = 0 ; V_154 [ V_8 ] ; V_8 ++ ) {
V_21 [ V_8 ] = F_60 ( V_2 , V_154 [ V_8 ] ) ;
if ( F_3 ( V_21 [ V_8 ] ) ) {
int V_7 = F_4 ( V_21 [ V_8 ] ) ;
if ( V_7 != - V_11 )
F_5 ( V_2 , L_37 ,
V_154 [ V_8 ] ) ;
return V_7 ;
}
}
return V_8 ;
}
static int F_61 ( struct V_14 * V_15 )
{
V_15 -> V_119 = F_62 ( V_15 -> V_2 , NULL ) ;
if ( F_3 ( V_15 -> V_119 ) ) {
F_5 ( V_15 -> V_2 , L_38 ) ;
return F_4 ( V_15 -> V_119 ) ;
}
return 0 ;
}
static int F_63 ( struct V_14 * V_15 ,
struct V_146 * V_147 ,
const char * V_155 ,
T_9 V_156 )
{
int V_17 ;
V_17 = F_64 ( V_147 , V_155 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_147 -> V_2 , L_39 , V_155 ) ;
return V_17 ;
}
V_17 = F_65 ( & V_147 -> V_2 , V_17 ,
NULL , V_156 ,
V_157 | V_158 ,
L_40 , V_15 ) ;
if ( V_17 )
F_5 ( & V_147 -> V_2 , L_41 , V_155 ) ;
return V_17 ;
}
static int F_66 ( struct V_14 * V_15 )
{
struct V_159 * V_160 ;
struct V_159 * V_161 ;
struct V_149 V_162 ;
int V_17 ;
V_160 = F_67 ( V_15 -> V_2 -> V_152 , L_42 ) ;
V_161 = F_68 ( V_160 , L_43 , 0 ) ;
V_17 = F_69 ( V_161 , 0 , & V_162 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_44 ) ;
return V_17 ;
}
V_15 -> V_124 = V_162 . V_163 ;
V_15 -> V_164 = F_70 ( & V_162 ) ;
V_15 -> V_30 = F_71 ( V_15 -> V_2 , V_15 -> V_124 , V_15 -> V_164 ) ;
if ( ! V_15 -> V_30 ) {
F_5 ( V_15 -> V_2 , L_45 ,
& V_162 . V_163 , V_15 -> V_164 ) ;
return - V_165 ;
}
V_160 = F_67 ( V_15 -> V_2 -> V_152 , L_46 ) ;
V_161 = F_68 ( V_160 , L_43 , 0 ) ;
V_17 = F_69 ( V_161 , 0 , & V_162 ) ;
if ( V_17 ) {
F_5 ( V_15 -> V_2 , L_47 ) ;
return V_17 ;
}
V_15 -> V_104 = V_15 -> V_91 = V_162 . V_163 ;
V_15 -> V_105 = F_70 ( & V_162 ) ;
V_15 -> V_106 = F_71 ( V_15 -> V_2 , V_15 -> V_104 , V_15 -> V_105 ) ;
if ( ! V_15 -> V_106 ) {
F_5 ( V_15 -> V_2 , L_45 ,
& V_162 . V_163 , V_15 -> V_105 ) ;
return - V_165 ;
}
return 0 ;
}
static int F_72 ( struct V_146 * V_147 )
{
const struct V_166 * V_167 ;
struct V_14 * V_15 ;
struct V_23 * V_23 ;
int V_17 ;
V_167 = F_73 ( & V_147 -> V_2 ) ;
if ( ! V_167 )
return - V_61 ;
V_23 = F_74 ( & V_147 -> V_2 , V_147 -> V_155 , & V_168 ,
V_167 -> V_169 , sizeof( * V_15 ) ) ;
if ( ! V_23 ) {
F_5 ( & V_147 -> V_2 , L_48 ) ;
return - V_74 ;
}
V_23 -> V_170 = & V_171 ;
V_15 = (struct V_14 * ) V_23 -> V_29 ;
V_15 -> V_2 = & V_147 -> V_2 ;
V_15 -> V_23 = V_23 ;
F_75 ( V_147 , V_15 ) ;
F_76 ( & V_15 -> V_129 ) ;
F_76 ( & V_15 -> V_136 ) ;
V_17 = F_53 ( V_15 , V_147 ) ;
if ( V_17 )
goto V_172;
V_17 = F_66 ( V_15 ) ;
if ( V_17 )
goto V_172;
V_17 = F_59 ( & V_147 -> V_2 , V_15 -> V_113 ,
V_167 -> V_173 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_147 -> V_2 , L_49 ) ;
goto V_172;
}
V_15 -> V_114 = V_17 ;
V_17 = F_59 ( & V_147 -> V_2 , V_15 -> V_121 ,
V_167 -> V_174 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_147 -> V_2 , L_50 ) ;
goto V_172;
}
V_15 -> V_122 = V_17 ;
V_17 = F_1 ( & V_147 -> V_2 , V_15 -> V_111 ,
V_167 -> V_175 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_147 -> V_2 , L_51 ) ;
goto V_172;
}
V_15 -> V_112 = V_17 ;
V_17 = F_1 ( & V_147 -> V_2 , V_15 -> V_116 ,
V_167 -> V_176 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_147 -> V_2 , L_52 ) ;
goto V_172;
}
V_15 -> V_117 = V_17 ;
V_17 = F_61 ( V_15 ) ;
if ( V_17 )
goto V_172;
V_17 = F_63 ( V_15 , V_147 , L_53 , F_46 ) ;
if ( V_17 < 0 )
goto V_172;
V_17 = F_63 ( V_15 , V_147 , L_54 , F_50 ) ;
if ( V_17 < 0 )
goto V_172;
V_17 = F_63 ( V_15 , V_147 , L_55 , F_51 ) ;
if ( V_17 < 0 )
goto V_172;
V_17 = F_63 ( V_15 , V_147 , L_56 , F_52 ) ;
if ( V_17 < 0 )
goto V_172;
V_15 -> V_134 = F_77 ( & V_147 -> V_2 , L_57 , & V_15 -> V_135 ) ;
if ( F_3 ( V_15 -> V_134 ) ) {
V_17 = F_4 ( V_15 -> V_134 ) ;
goto V_172;
}
F_78 ( V_23 , & V_15 -> V_177 ) ;
V_17 = F_79 ( V_23 ) ;
if ( V_17 )
goto V_172;
return 0 ;
V_172:
F_80 ( V_23 ) ;
return V_17 ;
}
static int F_81 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_82 ( V_147 ) ;
F_83 ( V_15 -> V_23 ) ;
F_84 ( V_15 -> V_23 , & V_15 -> V_177 ) ;
F_80 ( V_15 -> V_23 ) ;
return 0 ;
}
