static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( T_1 ) ( V_4 - V_2 -> V_5 ) * V_2 -> V_6 -> V_7 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_8 ;
struct V_9 * V_10 ;
if ( V_4 -> V_11 ) {
V_10 = F_3 ( V_4 -> V_11 , struct V_9 , V_11 ) ;
V_8 = V_10 - & V_2 -> V_12 [ 0 ] ;
V_2 -> V_12 [ V_8 ] . V_13 -- ;
F_4 ( & V_4 -> V_14 , V_4 -> V_11 ) ;
}
}
static void F_5 ( struct V_15 * V_11 , struct V_3 * V_4 )
{
struct V_16 * * V_17 , * V_18 = NULL ;
struct V_3 * V_19 ;
V_17 = & V_11 -> V_16 ;
while ( * V_17 ) {
V_18 = * V_17 ;
V_19 = F_6 ( V_18 , struct V_3 , V_14 ) ;
if ( V_4 -> V_20 > V_19 -> V_20 )
V_17 = & ( * V_17 ) -> V_21 ;
else
V_17 = & ( * V_17 ) -> V_22 ;
}
F_7 ( & V_4 -> V_14 , V_18 , V_17 ) ;
F_8 ( & V_4 -> V_14 , V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_23 )
{
struct V_15 * V_11 ;
if ( V_4 -> V_11 == & V_2 -> V_12 [ V_23 ] . V_11 )
return;
F_2 ( V_2 , V_4 ) ;
V_11 = & V_2 -> V_12 [ V_23 ] . V_11 ;
F_5 ( V_11 , V_4 ) ;
V_4 -> V_11 = V_11 ;
V_2 -> V_12 [ V_23 ] . V_13 ++ ;
}
static struct V_16 * F_10 ( struct V_15 * V_11 , unsigned int V_23 )
{
struct V_16 * V_17 ;
unsigned int V_24 ;
V_17 = F_11 ( V_11 ) ;
V_24 = 0 ;
while ( V_24 < V_23 && V_17 ) {
V_17 = F_12 ( V_17 ) ;
V_24 ++ ;
}
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_25 ;
T_1 V_26 ;
V_2 -> V_27 -- ;
V_4 -> V_28 |= V_29 ;
F_2 ( V_2 , V_4 ) ;
V_4 -> V_11 = NULL ;
if ( ! V_2 -> V_6 -> V_30 )
return 1 ;
V_26 = F_1 ( V_2 , V_4 ) ;
F_14 ( V_2 -> V_31 , L_1 , V_26 ) ;
V_25 = V_2 -> V_6 -> V_30 ( V_2 -> V_6 , V_26 ) ;
if ( V_25 ) {
F_14 ( V_2 -> V_31 , L_2
L_3 , V_26 , V_25 ) ;
return V_25 ;
}
return 1 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_32 = V_4 -> V_28 & V_33 ;
struct V_3 * V_34 = V_2 -> V_34 ;
V_4 -> V_28 |= V_33 ;
if ( V_34 == V_4 ) {
V_2 -> V_34 = NULL ;
if ( ! V_32 && V_2 -> V_35 != 0 ) {
F_9 ( V_2 , V_4 , V_36 ) ;
return 0 ;
}
}
return F_13 ( V_2 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_37 ,
struct V_38 * V_39 )
{
int V_25 = V_2 -> V_6 -> V_40 ( V_2 -> V_6 , V_37 , V_39 ) ;
if ( V_25 == - V_41 )
return V_25 ;
if ( V_25 ) {
F_14 ( V_2 -> V_31 , L_4 ,
V_25 , V_37 ) ;
return V_25 ;
}
if ( V_39 -> V_42 < V_39 -> V_43 ) {
F_14 ( V_2 -> V_31 , L_5
L_6 ,
V_39 -> V_42 , V_39 -> V_43 , V_37 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_45 * V_46 , * V_47 ;
int V_25 ;
T_1 V_26 ;
struct V_38 V_39 ;
V_26 = F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_6 -> V_48 && V_2 -> V_6 -> V_48 ( V_2 -> V_6 , V_26 ) )
return V_49 ;
V_39 . V_43 = 2 * V_2 -> V_6 -> V_50 -> V_51 ;
V_39 . V_52 = V_2 -> V_53 ;
V_39 . V_54 = 0 ;
V_39 . V_55 = NULL ;
V_39 . V_56 = V_57 ;
V_25 = F_16 ( V_2 , V_26 , & V_39 ) ;
if ( V_25 && V_25 != - V_41 )
return V_25 ;
V_46 = (struct V_45 * ) V_2 -> V_53 ;
V_47 = (struct V_45 * )
( V_2 -> V_53 + V_2 -> V_6 -> V_50 -> V_51 ) ;
if ( F_18 ( V_46 -> V_58 ) == V_59 ) {
V_4 -> V_20 = F_19 ( V_46 -> V_13 ) ;
if ( V_25 == - V_41 )
V_25 = V_60 ;
else {
if ( F_18 ( V_47 -> V_58 ) == V_61 )
V_25 = V_62 ;
else
V_25 = V_63 ;
}
} else {
V_4 -> V_28 |= V_64 ;
V_25 = V_62 ;
}
return V_25 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_65 )
{
struct V_45 V_66 ;
int V_25 ;
T_1 V_26 ;
struct V_38 V_39 ;
V_39 . V_54 = 0 ;
V_39 . V_52 = ( V_67 * ) & V_66 ;
V_39 . V_56 = V_57 ;
V_39 . V_55 = NULL ;
if ( V_65 == V_68 ) {
V_66 . V_58 = F_21 ( V_59 ) ;
V_66 . V_13 = F_22 ( V_4 -> V_20 ) ;
V_39 . V_43 = V_69 ;
V_26 = F_1 ( V_2 , V_4 ) ;
} else {
V_66 . V_58 = F_21 ( V_61 ) ;
V_39 . V_43 = sizeof( V_66 . V_58 ) ;
V_26 = F_1 ( V_2 , V_4 ) + V_2 -> V_6 -> V_70 ;
}
V_25 = V_2 -> V_6 -> V_71 ( V_2 -> V_6 , V_26 , & V_39 ) ;
if ( V_25 ) {
F_14 ( V_2 -> V_31 , L_7
L_3 , V_26 , V_25 ) ;
if ( V_25 == - V_44 || V_25 == - V_72 )
F_15 ( V_2 , V_4 ) ;
return V_25 ;
}
if ( V_39 . V_42 != V_39 . V_43 ) {
F_14 ( V_2 -> V_31 , L_8
L_9 ,
V_26 , V_39 . V_42 , V_39 . V_43 ) ;
return V_25 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_15 V_73 = V_74 ;
struct V_16 * V_75 ;
struct V_3 * V_4 ;
unsigned int V_24 , V_76 , V_77 ;
V_76 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_78 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_64 | V_29 | V_79 ) )
continue;
F_5 ( & V_73 , V_4 ) ;
V_76 ++ ;
}
if ( V_76 == 0 )
return;
V_75 = F_10 ( & V_73 , V_76 / 2 ) ;
V_77 = F_6 ( V_75 , struct V_3 , V_14 ) -> V_20 ;
V_2 -> V_80 = F_24 ( & V_73 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_78 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_64 | V_79 ) )
V_4 -> V_20 = V_77 ;
if ( V_4 -> V_28 & ( V_64 | V_29 | V_79 ) )
continue;
F_4 ( & V_4 -> V_14 , & V_73 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
int V_81 ;
unsigned int V_24 , V_23 ;
struct V_3 * V_4 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_78 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
V_81 = F_17 ( V_2 , V_4 ) ;
if ( V_81 < 0 )
V_4 -> V_28 |= V_79 ;
else if ( V_81 == V_49 ) {
V_4 -> V_28 |= V_29 ;
continue;
}
switch ( V_81 ) {
case V_63 :
V_23 = V_82 ;
break;
case V_62 :
case V_60 :
V_23 = V_83 ;
break;
default:
V_23 = V_36 ;
}
V_4 -> V_28 |= ( V_23 << V_84 ) ;
}
F_23 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_78 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & V_29 )
continue;
V_23 = V_4 -> V_28 >> V_84 ;
F_9 ( V_2 , V_4 , V_23 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_85 = V_4 -> V_86 ;
unsigned int V_87 = V_2 -> V_88 ;
if ( V_4 == V_2 -> V_34 )
return;
if ( V_4 -> V_28 & V_89 )
F_9 ( V_2 , V_4 , V_90 ) ;
else if ( V_4 -> V_28 & ( V_79 | V_33 ) )
F_9 ( V_2 , V_4 , V_36 ) ;
if ( V_85 == V_87 )
F_9 ( V_2 , V_4 , V_91 ) ;
else if ( V_85 == 0 )
F_9 ( V_2 , V_4 , V_83 ) ;
else if ( V_85 > ( V_87 / 2 ) )
F_9 ( V_2 , V_4 , V_92 ) ;
else
F_9 ( V_2 , V_4 , V_93 ) ;
}
static void F_27 ( struct V_94 * V_95 )
{
T_3 * V_96 = ( T_3 * ) V_95 -> V_97 ;
F_28 ( V_96 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
struct V_94 V_99 ;
T_3 V_100 ;
unsigned int V_101 = 0 ;
int V_25 ;
V_4 -> V_20 ++ ;
if ( V_4 -> V_20 > V_2 -> V_80 )
V_2 -> V_80 = V_4 -> V_20 ;
V_102:
F_30 ( & V_100 ) ;
memset ( & V_99 , 0 , sizeof( struct V_94 ) ) ;
V_99 . V_6 = V_6 ;
V_99 . V_103 = F_27 ;
V_99 . V_104 = F_1 ( V_2 , V_4 ) ;
V_99 . V_105 = V_6 -> V_7 ;
V_99 . V_97 = ( V_106 ) & V_100 ;
V_25 = V_6 -> V_99 ( V_6 , & V_99 ) ;
if ( V_25 ) {
if ( V_101 ++ < V_107 ) {
F_14 ( V_2 -> V_31 ,
L_10 ,
V_99 . V_104 , V_6 -> V_108 ) ;
F_31 () ;
goto V_102;
}
F_32 ( V_2 -> V_31 , L_11 ,
V_99 . V_104 , V_6 -> V_108 ) ;
F_13 ( V_2 , V_4 ) ;
return - V_44 ;
}
V_25 = F_33 ( V_100 , V_99 . V_109 == V_110 ||
V_99 . V_109 == V_111 ) ;
if ( V_25 ) {
F_32 ( V_2 -> V_31 , L_12 ,
V_99 . V_104 , V_6 -> V_108 ) ;
return - V_112 ;
}
if ( V_99 . V_109 == V_111 ) {
if ( V_101 ++ < V_107 ) {
F_14 ( V_2 -> V_31 ,
L_10 ,
V_99 . V_104 , V_6 -> V_108 ) ;
F_31 () ;
goto V_102;
}
F_13 ( V_2 , V_4 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_113 ,
unsigned int * V_114 )
{
int V_25 ;
struct V_3 * V_115 = V_2 -> V_34 ;
struct V_15 * V_116 ;
struct V_3 * V_4 ;
if ( V_115 == NULL || V_2 -> V_35 >= V_2 -> V_88 ) {
do {
if ( F_35 ( V_2 , V_117 ) )
return - V_118 ;
V_116 = F_36 ( V_2 , V_117 ) ;
V_4 = F_6 ( F_11 ( V_116 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_116 ) ;
V_4 -> V_11 = NULL ;
F_37 ( V_2 , V_117 ) -- ;
V_25 = F_20 ( V_2 , V_4 , V_119 ) ;
} while ( V_25 == - V_44 || V_25 == - V_72 );
if ( V_25 )
return V_25 ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = V_4 ;
if ( V_115 )
F_26 ( V_2 , V_115 ) ;
}
* V_114 = ( V_2 -> V_34 - V_2 -> V_5 ) * V_2 -> V_88 +
V_2 -> V_35 ;
V_2 -> V_34 -> V_86 ++ ;
V_2 -> V_120 [ * V_114 ] = V_113 ;
V_2 -> V_35 ++ ;
return 0 ;
}
static unsigned int F_38 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_117 ) * V_2 -> V_88 +
V_2 -> V_88 - V_2 -> V_35 ;
}
static unsigned int F_39 ( struct V_1 * V_2 )
{
return F_38 ( V_2 ) > V_2 -> V_88 ;
}
static int F_40 ( struct V_1 * V_2 , char * V_121 ,
unsigned int V_113 , unsigned int * V_122 , int V_123 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
T_4 V_124 ;
T_1 V_125 ;
int V_25 ;
V_102:
if ( ! V_123 )
while ( ! F_39 ( V_2 ) )
if ( F_41 ( V_2 , 0 ) > 0 )
return - V_118 ;
V_25 = F_34 ( V_2 , V_113 , V_122 ) ;
V_4 = V_2 -> V_5 + ( * V_122 / V_2 -> V_88 ) ;
if ( V_25 == - V_44 || V_25 == - V_72 ) {
V_2 -> V_34 = NULL ;
V_4 -> V_86 -- ;
V_2 -> V_120 [ * V_122 ] = V_126 ;
goto V_102;
}
if ( V_25 < 0 )
return V_25 ;
V_125 = ( T_1 ) * V_122 << V_127 ;
V_25 = V_6 -> V_128 ( V_6 , V_125 , V_129 , & V_124 , V_121 ) ;
if ( V_25 == - V_44 || V_25 == - V_72 ) {
V_2 -> V_35 -- ;
V_4 -> V_86 -- ;
V_2 -> V_120 [ * V_122 ] = V_126 ;
F_15 ( V_2 , V_4 ) ;
goto V_102;
}
if ( V_25 < 0 ) {
F_32 ( V_2 -> V_31 , L_13 ,
V_25 , V_124 ) ;
goto V_130;
}
if ( V_124 != V_129 ) {
F_32 ( V_2 -> V_31 , L_14 ,
V_124 ) ;
V_25 = - V_44 ;
goto V_130;
}
return V_25 ;
V_130:
V_2 -> V_35 -- ;
V_4 -> V_86 -- ;
V_2 -> V_120 [ * V_122 ] = V_126 ;
return V_25 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_131 ,
unsigned int * V_132 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 , * V_133 ;
int V_25 ;
T_4 V_124 ;
unsigned int V_113 , V_101 ;
T_1 V_134 ;
V_113 = V_2 -> V_120 [ V_131 ] ;
V_134 = ( T_1 ) V_131 << V_127 ;
V_101 = 0 ;
V_102:
V_25 = V_6 -> V_135 ( V_6 , V_134 , V_129 , & V_124 , V_2 -> V_136 ) ;
if ( V_25 < 0 && V_25 != - V_41 ) {
V_133 = V_2 -> V_5 + V_131 / V_2 -> V_88 ;
V_133 -> V_28 |= V_79 ;
F_32 ( V_2 -> V_31 , L_15 , V_25 ,
V_131 ) ;
V_101 ++ ;
if ( V_101 < V_137 )
goto V_102;
goto V_138;
}
if ( V_124 != V_129 ) {
F_32 ( V_2 -> V_31 , L_16 , V_124 ,
V_131 ) ;
V_25 = - V_44 ;
goto V_138;
}
V_25 = F_40 ( V_2 , V_2 -> V_136 , V_113 , V_132 , 1 ) ;
if ( V_25 < 0 ) {
V_2 -> V_139 [ V_113 ] = V_140 ;
F_32 ( V_2 -> V_31 , L_17 , V_25 ) ;
return V_25 ;
}
V_4 = V_2 -> V_5 + * V_132 / V_2 -> V_88 ;
V_2 -> V_139 [ V_113 ] = * V_132 ;
V_2 -> V_120 [ V_131 ] = V_126 ;
V_4 = V_2 -> V_5 + V_131 / V_2 -> V_88 ;
V_4 -> V_86 -- ;
return 0 ;
V_138:
V_2 -> V_139 [ V_113 ] = V_140 ;
V_2 -> V_120 [ V_131 ] = V_126 ;
return V_25 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_24 , V_114 , V_141 , V_132 ;
int V_25 , V_142 ;
V_142 = 0 ;
V_141 = ( V_4 - V_2 -> V_5 ) * V_2 -> V_88 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_88 ; V_24 ++ ) {
if ( V_2 -> V_27 < V_143 )
return - V_118 ;
V_114 = V_141 + V_24 ;
if ( V_2 -> V_120 [ V_114 ] == V_126 )
continue;
V_25 = F_42 ( V_2 , V_114 , & V_132 ) ;
if ( V_25 < 0 && ! V_142 )
V_142 = V_25 ;
}
return V_142 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_23 , V_144 ;
if ( F_37 ( V_2 , V_117 ) < V_145 )
V_144 = V_92 ;
else
V_144 = V_93 ;
for ( V_23 = V_90 ; V_23 >= V_144 ; V_23 -- )
if ( V_2 -> V_12 [ V_23 ] . V_11 . V_16 != NULL )
return V_23 ;
return - 1 ;
}
static int F_45 ( unsigned int V_146 )
{
unsigned int V_147 , V_148 , V_149 , V_150 , V_151 ;
V_150 = V_146 - V_152 ;
if ( V_150 > V_153 )
V_150 = V_153 ;
V_147 = V_154 - V_155 ;
V_151 = V_153 ;
V_148 = V_150 - V_151 ;
V_149 = ( V_148 * V_147 + V_151 / 2 ) / V_151 ;
return V_155 + V_149 ;
}
static int F_46 ( struct V_1 * V_2 )
{
static unsigned int V_156 ;
unsigned int V_24 , V_23 = - 1 , V_157 , V_158 ;
struct V_15 * V_11 ;
V_158 = 0 ;
for ( V_24 = 0 ; V_24 <= V_83 ; V_24 ++ ) {
V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 == NULL )
continue;
V_157 = V_2 -> V_80 - F_47 ( V_11 ) ;
if ( V_157 > V_158 ) {
V_158 = V_157 ;
V_23 = V_24 ;
}
}
if ( V_158 > V_152 && V_156 >= F_45 ( V_158 ) - 1 ) {
V_156 = 0 ;
return V_23 ;
}
V_156 ++ ;
return - 1 ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned int V_159 )
{
int V_23 ;
if ( F_49 ( V_2 , V_160 ) &&
( V_159 || ( F_35 ( V_2 , V_117 ) && F_35 ( V_2 , V_161 ) ) ) )
return V_36 ;
V_23 = F_46 ( V_2 ) ;
if ( V_23 >= V_82 )
return V_23 ;
return F_44 ( V_2 ) ;
}
static struct V_3 * F_50 ( struct V_1 * V_2 ,
unsigned int V_159 )
{
struct V_15 * V_162 = NULL ;
struct V_3 * V_4 = NULL ;
int V_23 ;
if ( V_159 && F_37 ( V_2 , V_117 ) > V_163 &&
F_35 ( V_2 , V_161 ) && F_35 ( V_2 , V_160 ) )
return NULL ;
V_23 = F_48 ( V_2 , V_159 ) ;
if ( V_23 < 0 )
return NULL ;
V_162 = & V_2 -> V_12 [ V_23 ] . V_11 ;
V_4 = F_6 ( F_11 ( V_162 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_162 ) ;
V_4 -> V_11 = NULL ;
V_2 -> V_12 [ V_23 ] . V_13 -- ;
return V_4 ;
}
static unsigned int F_51 ( unsigned int V_24 )
{
return V_24 % 2 ? 0x55555555 : 0xAAAAAAAA ;
}
static unsigned int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_98 * V_6 = V_2 -> V_6 ;
unsigned int V_164 , V_24 , V_165 , V_166 , V_167 ;
T_1 V_151 , V_168 ;
unsigned int * V_169 = ( unsigned int * ) V_2 -> V_136 ;
unsigned char * V_170 = ( unsigned char * ) V_2 -> V_53 ;
struct V_38 V_39 ;
int V_25 ;
V_39 . V_56 = V_57 ;
V_39 . V_105 = V_6 -> V_70 ;
V_39 . V_43 = V_6 -> V_50 -> V_51 ;
V_39 . V_54 = 0 ;
V_39 . V_55 = V_2 -> V_136 ;
V_39 . V_52 = V_2 -> V_53 ;
V_151 = F_1 ( V_2 , V_4 ) ;
V_167 = V_2 -> V_88 * V_129 / V_6 -> V_70 ;
for ( V_164 = 0 ; V_164 < 2 ; V_164 ++ ) {
V_168 = V_151 ;
for ( V_24 = 0 ; V_24 < V_167 ; V_24 ++ ) {
V_166 = F_51 ( V_164 + V_24 ) ;
memset ( V_2 -> V_136 , V_166 , V_6 -> V_70 ) ;
memset ( V_2 -> V_53 , V_166 , V_6 -> V_50 -> V_51 ) ;
V_25 = V_6 -> V_71 ( V_6 , V_168 , & V_39 ) ;
if ( V_25 )
goto error;
V_168 += V_6 -> V_70 ;
}
V_168 = V_151 ;
for ( V_24 = 0 ; V_24 < V_167 ; V_24 ++ ) {
V_25 = V_6 -> V_40 ( V_6 , V_168 , & V_39 ) ;
if ( V_25 )
goto error;
V_166 = F_51 ( V_164 + V_24 ) ;
for ( V_165 = 0 ; V_165 < V_6 -> V_70 / sizeof( int ) ; V_165 ++ )
if ( V_169 [ V_165 ] != V_166 )
goto error;
for ( V_165 = 0 ; V_165 < V_6 -> V_50 -> V_51 ; V_165 ++ )
if ( V_170 [ V_165 ] != ( unsigned char ) V_166 )
goto error;
V_168 += V_6 -> V_70 ;
}
V_25 = F_29 ( V_2 , V_4 ) ;
if ( V_25 )
goto error;
}
V_4 -> V_28 &= ~ V_79 ;
return 1 ;
error:
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_159 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( V_2 -> V_27 < V_143 )
return 1 ;
V_4 = F_50 ( V_2 , V_159 ) ;
if ( ! V_4 )
return 1 ;
V_25 = F_43 ( V_2 , V_4 ) ;
if ( V_25 == - V_118 )
return 1 ;
if ( V_4 -> V_28 & V_33 ) {
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
V_4 -> V_28 &= ~ V_89 ;
V_25 = F_29 ( V_2 , V_4 ) ;
if ( ( V_4 -> V_28 & V_79 ) &&
( V_25 || ! F_52 ( V_2 , V_4 ) ) )
return 0 ;
if ( V_25 == 0 )
V_25 = F_20 ( V_2 , V_4 , V_68 ) ;
if ( V_25 == 0 )
F_9 ( V_2 , V_4 , V_82 ) ;
else if ( V_25 != - V_44 && V_25 != - V_72 )
F_9 ( V_2 , V_4 , V_83 ) ;
return 0 ;
}
static void F_53 ( struct V_171 * V_31 )
{
struct V_1 * V_2 = F_54 ( V_31 ) ;
int V_25 ;
while ( 1 ) {
V_25 = F_41 ( V_2 , 1 ) ;
if ( V_25 || F_55 ( V_31 ) )
return;
}
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( V_2 -> V_5 ) ;
F_57 ( V_2 -> V_120 ) ;
F_57 ( V_2 -> V_139 ) ;
F_58 ( V_2 -> V_53 ) ;
F_58 ( V_2 -> V_136 ) ;
}
static int F_59 ( struct V_171 * V_31 )
{
struct V_1 * V_2 = F_54 ( V_31 ) ;
if ( V_2 -> V_6 -> V_172 )
V_2 -> V_6 -> V_172 ( V_2 -> V_6 ) ;
return 0 ;
}
static unsigned int F_60 ( struct V_98 * V_6 , T_5 V_173 )
{
T_1 V_26 ;
unsigned int V_174 ;
V_174 = 0 ;
if ( V_6 -> V_48 )
for ( V_26 = 0 ; V_26 < V_173 ; V_26 += V_6 -> V_7 )
if ( V_6 -> V_48 ( V_6 , V_26 ) )
V_174 ++ ;
return V_174 ;
}
static int F_61 ( struct V_171 * V_31 ,
unsigned long V_113 , char * V_121 )
{
struct V_1 * V_2 = F_54 ( V_31 ) ;
unsigned int V_132 , V_175 ;
struct V_3 * V_4 ;
int V_25 ;
V_2 -> V_176 ++ ;
if ( V_2 -> V_27 < V_143 )
return - V_118 ;
if ( V_177 ) {
if ( F_62 ( V_113 == 0 ) )
return 0 ;
V_113 -- ;
}
V_175 = V_2 -> V_139 [ V_113 ] ;
if ( V_175 <= V_178 ) {
V_4 = V_2 -> V_5 + ( V_175 / V_2 -> V_88 ) ;
V_4 -> V_86 -- ;
F_26 ( V_2 , V_4 ) ;
V_2 -> V_139 [ V_113 ] = V_179 ;
V_2 -> V_120 [ V_175 ] = V_126 ;
}
V_25 = F_40 ( V_2 , V_121 , V_113 , & V_132 , 0 ) ;
V_2 -> V_180 ++ ;
if ( V_25 < 0 )
return V_25 ;
V_4 = V_2 -> V_5 + ( V_132 / V_2 -> V_88 ) ;
V_2 -> V_139 [ V_113 ] = V_132 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , char * V_121 )
{
union V_181 * V_182 = (union V_181 * ) ( V_121 ) ;
memset ( V_121 , 0 , V_129 - 10 ) ;
V_182 -> V_183 . V_184 = 1 ;
V_182 -> V_183 . V_185 = V_2 -> V_186 -> V_173 - 1 ;
V_182 -> V_183 . V_187 = 0 ;
memcpy ( V_121 + V_129 - 10 , L_18 , 10 ) ;
return 0 ;
}
static int F_64 ( struct V_171 * V_31 ,
unsigned long V_113 , char * V_121 )
{
struct V_1 * V_2 = F_54 ( V_31 ) ;
struct V_98 * V_6 = V_2 -> V_6 ;
unsigned int V_188 , V_101 ;
T_1 V_134 ;
struct V_3 * V_4 ;
T_4 V_124 ;
int V_25 ;
V_2 -> V_189 ++ ;
if ( V_177 ) {
if ( F_62 ( V_113 == 0 ) )
return F_63 ( V_2 , V_121 ) ;
V_113 -- ;
}
V_188 = V_2 -> V_139 [ V_113 ] ;
if ( V_188 > V_178 ) {
memset ( V_121 , 0x0 , V_129 ) ;
if ( V_188 == V_179 )
return 0 ;
else
return - V_44 ;
}
V_4 = V_2 -> V_5 + ( V_188 / V_2 -> V_88 ) ;
F_65 ( V_2 -> V_120 [ V_188 ] == V_126 ) ;
V_134 = ( T_1 ) V_188 << V_127 ;
V_101 = 0 ;
V_102:
V_25 = V_6 -> V_135 ( V_6 , V_134 , V_129 , & V_124 , V_121 ) ;
V_2 -> V_190 ++ ;
if ( V_25 == - V_41 ) {
V_4 -> V_28 |= V_89 ;
F_9 ( V_2 , V_4 , V_90 ) ;
V_25 = 0 ;
}
if ( V_25 < 0 ) {
F_32 ( V_2 -> V_31 , L_19 , V_25 ) ;
V_4 -> V_28 |= V_79 ;
F_9 ( V_2 , V_4 , V_36 ) ;
V_101 ++ ;
if ( V_101 < V_137 )
goto V_102;
return V_25 ;
}
if ( V_124 != V_129 ) {
F_32 ( V_2 -> V_31 , L_20 , V_124 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_66 ( struct V_171 * V_31 , unsigned long V_191 ,
unsigned V_192 )
{
struct V_1 * V_2 = F_54 ( V_31 ) ;
unsigned long V_113 ;
struct V_3 * V_4 ;
unsigned int V_175 ;
V_2 -> V_193 ++ ;
for ( V_113 = V_191 ; V_113 < V_191 + V_192 ; V_113 ++ ) {
V_175 = V_2 -> V_139 [ V_113 ] ;
if ( V_175 <= V_178 ) {
V_4 = V_2 -> V_5 + ( V_175 / V_2 -> V_88 ) ;
V_4 -> V_86 -- ;
F_26 ( V_2 , V_4 ) ;
V_2 -> V_139 [ V_113 ] = V_179 ;
V_2 -> V_120 [ V_175 ] = V_126 ;
V_2 -> V_194 ++ ;
} else if ( V_175 == V_140 ) {
V_2 -> V_139 [ V_113 ] = V_179 ;
V_2 -> V_194 ++ ;
}
}
return 0 ;
}
static int F_67 ( struct V_195 * V_196 , void * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 -> V_197 ;
unsigned long V_198 ;
unsigned int V_13 [ V_199 ] ;
unsigned int V_200 [ V_199 ] ;
unsigned int V_158 [ V_199 ] ;
unsigned int V_24 , V_201 = 0 , V_202 = 0 , V_203 = 0 , V_204 , V_175 , V_205 ;
T_5 V_206 ;
char * V_108 [] = { L_21 , L_22 , L_23 , L_24 , L_25 , L_26 ,
L_27 } ;
F_68 ( & V_2 -> V_186 -> V_207 ) ;
for ( V_24 = 0 ; V_24 < V_199 ; V_24 ++ ) {
struct V_15 * V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 ) {
V_13 [ V_24 ] = V_2 -> V_12 [ V_24 ] . V_13 ;
V_200 [ V_24 ] = F_6 ( F_11 ( V_11 ) , struct V_3 ,
V_14 ) -> V_20 ;
V_158 [ V_24 ] = F_6 ( F_69 ( V_11 ) , struct V_3 ,
V_14 ) -> V_20 ;
} else
V_13 [ V_24 ] = 0 ;
}
if ( V_2 -> V_34 ) {
V_201 = 1 ;
V_202 = V_2 -> V_35 ;
V_203 = V_2 -> V_34 -> V_20 ;
}
V_198 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_78 ; V_24 ++ )
V_198 += V_2 -> V_5 [ V_24 ] . V_20 ;
V_206 = ( T_5 ) V_2 -> V_78 * V_2 -> V_6 -> V_7 ;
V_204 = F_60 ( V_2 -> V_6 , V_206 ) ;
V_175 = 0 ;
V_205 = V_2 -> V_186 -> V_173 ;
for ( V_24 = 0 ; V_24 < V_205 ; V_24 ++ )
if ( V_2 -> V_139 [ V_24 ] != V_179 )
V_175 ++ ;
F_70 ( & V_2 -> V_186 -> V_207 ) ;
for ( V_24 = 0 ; V_24 < V_199 ; V_24 ++ ) {
if ( ! V_13 [ V_24 ] )
continue;
if ( V_200 [ V_24 ] != V_158 [ V_24 ] )
F_71 ( V_196 , L_28
L_29 ,
V_108 [ V_24 ] , V_13 [ V_24 ] , V_200 [ V_24 ] , V_158 [ V_24 ] ) ;
else
F_71 ( V_196 , L_30
L_31 , V_108 [ V_24 ] , V_13 [ V_24 ] , V_200 [ V_24 ] ) ;
}
if ( V_204 )
F_71 ( V_196 , L_32 , V_204 ) ;
if ( V_201 )
F_71 ( V_196 , L_33
L_34 ,
V_202 , V_2 -> V_88 - V_202 , V_203 ) ;
F_71 ( V_196 , L_35 , V_198 ) ;
F_71 ( V_196 , L_36 ) ;
F_71 ( V_196 , L_37 , V_2 -> V_189 ) ;
F_71 ( V_196 , L_38 , V_2 -> V_176 ) ;
F_71 ( V_196 , L_39 , V_2 -> V_193 ) ;
F_71 ( V_196 , L_40 , V_2 -> V_190 ) ;
F_71 ( V_196 , L_41 , V_2 -> V_180 ) ;
F_71 ( V_196 , L_42 , V_2 -> V_194 ) ;
F_71 ( V_196 , L_36 ) ;
F_71 ( V_196 , L_43 , V_205 ) ;
F_71 ( V_196 , L_44 , V_175 ) ;
return 0 ;
}
static int F_72 ( struct V_208 * V_208 , struct V_209 * V_209 )
{
return F_73 ( V_209 , F_67 , V_208 -> V_210 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_211 * V_212 = V_2 -> V_186 -> V_213 ;
struct V_214 * V_31 = F_75 ( V_212 ) ;
struct V_215 * V_11 ;
struct V_215 * V_216 ;
V_11 = F_76 ( V_212 -> V_217 , NULL ) ;
if ( F_77 ( V_11 ) )
return 0 ;
if ( ! V_11 ) {
F_32 ( V_31 , L_45 ) ;
return - 1 ;
}
V_2 -> V_218 = V_11 ;
V_216 = F_78 ( L_46 , V_219 , V_11 , V_2 ,
& V_220 ) ;
if ( ! V_216 ) {
F_32 ( V_2 -> V_31 , L_47 ) ;
F_79 ( V_11 ) ;
V_2 -> V_218 = NULL ;
return - 1 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned int V_221 ,
unsigned int V_222 )
{
struct V_98 * V_6 = V_2 -> V_186 -> V_6 ;
unsigned int V_24 , V_223 , V_205 , V_224 ;
int V_25 = - V_225 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_78 = V_221 ;
V_2 -> V_27 = V_222 ;
V_2 -> V_88 = V_6 -> V_7 >> V_127 ;
V_205 = V_2 -> V_186 -> V_173 ;
V_224 = V_221 * V_2 -> V_88 ;
for ( V_24 = 0 ; V_24 < V_199 ; V_24 ++ )
V_2 -> V_12 [ V_24 ] . V_11 = V_74 ;
V_2 -> V_139 = F_81 ( sizeof( int ) * V_205 ) ;
if ( ! V_2 -> V_139 )
goto V_226;
V_2 -> V_120 = F_81 ( sizeof( int ) * V_224 ) ;
if ( ! V_2 -> V_120 )
goto V_227;
V_223 = sizeof( struct V_3 ) * V_2 -> V_78 ;
V_2 -> V_5 = F_81 ( V_223 ) ;
if ( ! V_2 -> V_5 )
goto V_228;
memset ( V_2 -> V_5 , 0 , V_223 ) ;
for ( V_24 = 0 ; V_24 < V_205 ; V_24 ++ )
V_2 -> V_139 [ V_24 ] = V_179 ;
for ( V_24 = 0 ; V_24 < V_224 ; V_24 ++ )
V_2 -> V_120 [ V_24 ] = V_126 ;
V_2 -> V_136 = F_82 ( V_129 , V_229 ) ;
if ( ! V_2 -> V_136 )
goto V_230;
V_2 -> V_53 = F_82 ( 2 * V_6 -> V_50 -> V_51 , V_229 ) ;
if ( ! V_2 -> V_53 )
goto V_231;
F_25 ( V_2 ) ;
return 0 ;
V_231:
F_58 ( V_2 -> V_136 ) ;
V_230:
F_57 ( V_2 -> V_5 ) ;
V_228:
F_57 ( V_2 -> V_120 ) ;
V_227:
F_57 ( V_2 -> V_139 ) ;
V_226:
F_83 ( V_232 L_48 , V_233 , V_25 ) ;
return V_25 ;
}
static void F_84 ( struct V_234 * V_235 , struct V_98 * V_6 )
{
struct V_1 * V_2 ;
struct V_171 * V_186 ;
char * V_236 ;
char * V_237 ;
unsigned long V_238 ;
unsigned int V_221 , V_239 , V_240 , V_222 ;
T_5 V_241 , V_206 , V_242 ;
struct V_243 * V_244 ;
int V_25 ;
V_236 = & V_245 [ 0 ] ;
if ( ! * V_236 )
return;
while ( ( V_237 = F_85 ( & V_236 , L_49 ) ) != NULL ) {
if ( F_86 ( V_237 , 0 , & V_238 ) < 0 )
return;
if ( V_6 -> V_246 == V_238 )
break;
}
if ( V_6 -> V_246 != V_238 )
return;
if ( V_6 -> V_7 < V_129 || V_6 -> V_7 % V_129 ) {
F_83 ( V_232 L_50
L_51 , V_233 , V_6 -> V_7 , V_129 ) ;
return;
}
if ( V_129 % V_6 -> V_70 || V_6 -> V_70 > V_129 ) {
F_83 ( V_232 L_52
L_53 , V_233 , V_129 , V_6 -> V_70 ) ;
return;
}
V_244 = V_6 -> V_50 ;
if ( ! V_244 ) {
F_83 ( V_232 L_54 ,
V_233 , V_6 -> V_246 ) ;
return;
}
if ( ! V_6 -> V_247 || V_244 -> V_51 < V_69 ) {
F_83 ( V_232 L_55
L_56 ,
V_233 , V_244 -> V_51 , V_69 ) ;
return;
}
if ( V_248 > 100 )
V_248 = 100 ;
V_206 = V_6 -> V_173 ;
V_242 = ( T_5 ) V_178 * V_129 ;
if ( V_6 -> V_173 > V_242 ) {
F_83 ( V_249 L_57
L_58 , V_233 , V_242 ) ;
V_206 = V_242 ;
}
V_221 = F_87 ( V_206 , V_6 ) ;
V_206 = V_221 * V_6 -> V_7 ;
V_240 = F_60 ( V_6 , V_206 ) ;
V_239 = V_221 - V_240 ;
if ( V_239 < V_250 ) {
F_83 ( V_232 L_59
L_60 , V_233 , V_239 ,
V_250 ) ;
return;
}
V_222 = F_88 ( ( T_5 ) V_239 * V_248 , 100 ) ;
if ( V_222 < V_143 )
V_222 = V_143 ;
if ( V_222 > V_239 - 1 )
V_222 = V_239 - 1 ;
V_241 = ( T_5 ) ( V_239 - V_222 ) * V_6 -> V_7 +
( V_177 ? V_129 : 0 ) ;
F_83 ( V_251 L_61
L_62 ,
V_233 , V_238 , V_241 / 1024 , V_222 , V_240 ) ;
V_2 = F_89 ( sizeof( struct V_1 ) , V_229 ) ;
if ( ! V_2 )
return;
V_186 = F_89 ( sizeof( struct V_171 ) , V_229 ) ;
if ( ! V_186 ) {
F_58 ( V_2 ) ;
return;
}
V_2 -> V_186 = V_186 ;
V_186 -> V_97 = V_2 ;
V_186 -> V_6 = V_6 ;
V_186 -> V_252 = V_6 -> V_246 ;
V_186 -> V_173 = V_241 >> V_127 ;
V_186 -> V_235 = V_235 ;
if ( ! ( V_6 -> V_28 & V_253 ) )
V_186 -> V_254 = 1 ;
if ( F_80 ( V_2 , V_221 , V_222 ) < 0 )
goto V_255;
if ( F_90 ( V_186 ) < 0 )
goto V_256;
V_2 -> V_31 = F_75 ( V_186 -> V_213 ) ;
V_25 = F_74 ( V_2 ) ;
if ( V_25 < 0 )
goto V_257;
return;
V_257:
F_91 ( V_186 ) ;
V_256:
F_56 ( V_2 ) ;
V_255:
F_58 ( V_186 ) ;
F_58 ( V_2 ) ;
}
static void F_92 ( struct V_171 * V_31 )
{
struct V_1 * V_2 = F_54 ( V_31 ) ;
F_79 ( V_2 -> V_218 ) ;
F_91 ( V_31 ) ;
F_56 ( V_2 ) ;
F_58 ( V_2 ) ;
}
static int T_6 F_93 ( void )
{
return F_94 ( & V_258 ) ;
}
static void T_7 F_95 ( void )
{
F_96 ( & V_258 ) ;
}
