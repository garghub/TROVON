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
if ( F_17 ( V_25 ) )
return V_25 ;
if ( V_25 ) {
F_14 ( V_2 -> V_31 , L_4 ,
V_25 , V_37 ) ;
return V_25 ;
}
if ( V_39 -> V_41 < V_39 -> V_42 ) {
F_14 ( V_2 -> V_31 , L_5
L_6 ,
V_39 -> V_41 , V_39 -> V_42 , V_37 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_45 , * V_46 ;
int V_25 ;
T_1 V_26 ;
struct V_38 V_39 ;
V_26 = F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_6 -> V_47 && V_2 -> V_6 -> V_47 ( V_2 -> V_6 , V_26 ) )
return V_48 ;
V_39 . V_42 = 2 * V_2 -> V_6 -> V_49 -> V_50 ;
V_39 . V_51 = V_2 -> V_52 ;
V_39 . V_53 = 0 ;
V_39 . V_54 = NULL ;
V_39 . V_55 = V_56 ;
V_25 = F_16 ( V_2 , V_26 , & V_39 ) ;
if ( V_25 && ! F_17 ( V_25 ) )
return V_25 ;
V_45 = (struct V_44 * ) V_2 -> V_52 ;
V_46 = (struct V_44 * )
( V_2 -> V_52 + V_2 -> V_6 -> V_49 -> V_50 ) ;
if ( F_19 ( V_45 -> V_57 ) == V_58 ) {
V_4 -> V_20 = F_20 ( V_45 -> V_13 ) ;
if ( F_17 ( V_25 ) )
V_25 = V_59 ;
else {
if ( F_19 ( V_46 -> V_57 ) == V_60 )
V_25 = V_61 ;
else
V_25 = V_62 ;
}
} else {
V_4 -> V_28 |= V_63 ;
V_25 = V_61 ;
}
return V_25 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_64 )
{
struct V_44 V_65 ;
int V_25 ;
T_1 V_26 ;
struct V_38 V_39 ;
V_39 . V_53 = 0 ;
V_39 . V_51 = ( V_66 * ) & V_65 ;
V_39 . V_55 = V_56 ;
V_39 . V_54 = NULL ;
if ( V_64 == V_67 ) {
V_65 . V_57 = F_22 ( V_58 ) ;
V_65 . V_13 = F_23 ( V_4 -> V_20 ) ;
V_39 . V_42 = V_68 ;
V_26 = F_1 ( V_2 , V_4 ) ;
} else {
V_65 . V_57 = F_22 ( V_60 ) ;
V_39 . V_42 = sizeof( V_65 . V_57 ) ;
V_26 = F_1 ( V_2 , V_4 ) + V_2 -> V_6 -> V_69 ;
}
V_25 = V_2 -> V_6 -> V_70 ( V_2 -> V_6 , V_26 , & V_39 ) ;
if ( V_25 ) {
F_14 ( V_2 -> V_31 , L_7
L_3 , V_26 , V_25 ) ;
if ( V_25 == - V_43 || F_24 ( V_25 ) )
F_15 ( V_2 , V_4 ) ;
return V_25 ;
}
if ( V_39 . V_41 != V_39 . V_42 ) {
F_14 ( V_2 -> V_31 , L_8
L_9 ,
V_26 , V_39 . V_41 , V_39 . V_42 ) ;
return V_25 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_15 V_71 = V_72 ;
struct V_16 * V_73 ;
struct V_3 * V_4 ;
unsigned int V_24 , V_74 , V_75 ;
V_74 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_76 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_63 | V_29 | V_77 ) )
continue;
F_5 ( & V_71 , V_4 ) ;
V_74 ++ ;
}
if ( V_74 == 0 )
return;
V_73 = F_10 ( & V_71 , V_74 / 2 ) ;
V_75 = F_6 ( V_73 , struct V_3 , V_14 ) -> V_20 ;
V_2 -> V_78 = F_26 ( & V_71 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_76 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_63 | V_77 ) )
V_4 -> V_20 = V_75 ;
if ( V_4 -> V_28 & ( V_63 | V_29 | V_77 ) )
continue;
F_4 ( & V_4 -> V_14 , & V_71 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
int V_79 ;
unsigned int V_24 , V_23 ;
struct V_3 * V_4 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_76 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
V_79 = F_18 ( V_2 , V_4 ) ;
if ( V_79 < 0 )
V_4 -> V_28 |= V_77 ;
else if ( V_79 == V_48 ) {
V_4 -> V_28 |= V_29 ;
continue;
}
switch ( V_79 ) {
case V_62 :
V_23 = V_80 ;
break;
case V_61 :
case V_59 :
V_23 = V_81 ;
break;
default:
V_23 = V_36 ;
}
V_4 -> V_28 |= ( V_23 << V_82 ) ;
}
F_25 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_76 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & V_29 )
continue;
V_23 = V_4 -> V_28 >> V_82 ;
F_9 ( V_2 , V_4 , V_23 ) ;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_83 = V_4 -> V_84 ;
unsigned int V_85 = V_2 -> V_86 ;
if ( V_4 == V_2 -> V_34 )
return;
if ( V_4 -> V_28 & V_87 )
F_9 ( V_2 , V_4 , V_88 ) ;
else if ( V_4 -> V_28 & ( V_77 | V_33 ) )
F_9 ( V_2 , V_4 , V_36 ) ;
if ( V_83 == V_85 )
F_9 ( V_2 , V_4 , V_89 ) ;
else if ( V_83 == 0 )
F_9 ( V_2 , V_4 , V_81 ) ;
else if ( V_83 > ( V_85 / 2 ) )
F_9 ( V_2 , V_4 , V_90 ) ;
else
F_9 ( V_2 , V_4 , V_91 ) ;
}
static void F_29 ( struct V_92 * V_93 )
{
T_3 * V_94 = ( T_3 * ) V_93 -> V_95 ;
F_30 ( V_94 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_96 * V_6 = V_2 -> V_6 ;
struct V_92 V_97 ;
T_3 V_98 ;
unsigned int V_99 = 0 ;
int V_25 ;
V_4 -> V_20 ++ ;
if ( V_4 -> V_20 > V_2 -> V_78 )
V_2 -> V_78 = V_4 -> V_20 ;
V_100:
F_32 ( & V_98 ) ;
memset ( & V_97 , 0 , sizeof( struct V_92 ) ) ;
V_97 . V_6 = V_6 ;
V_97 . V_101 = F_29 ;
V_97 . V_102 = F_1 ( V_2 , V_4 ) ;
V_97 . V_103 = V_6 -> V_7 ;
V_97 . V_95 = ( V_104 ) & V_98 ;
V_25 = V_6 -> V_97 ( V_6 , & V_97 ) ;
if ( V_25 ) {
if ( V_99 ++ < V_105 ) {
F_14 ( V_2 -> V_31 ,
L_10 ,
V_97 . V_102 , V_6 -> V_106 ) ;
F_33 () ;
goto V_100;
}
F_34 ( V_2 -> V_31 , L_11 ,
V_97 . V_102 , V_6 -> V_106 ) ;
F_13 ( V_2 , V_4 ) ;
return - V_43 ;
}
V_25 = F_35 ( V_98 , V_97 . V_107 == V_108 ||
V_97 . V_107 == V_109 ) ;
if ( V_25 ) {
F_34 ( V_2 -> V_31 , L_12 ,
V_97 . V_102 , V_6 -> V_106 ) ;
return - V_110 ;
}
if ( V_97 . V_107 == V_109 ) {
if ( V_99 ++ < V_105 ) {
F_14 ( V_2 -> V_31 ,
L_10 ,
V_97 . V_102 , V_6 -> V_106 ) ;
F_33 () ;
goto V_100;
}
F_13 ( V_2 , V_4 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_111 ,
unsigned int * V_112 )
{
int V_25 ;
struct V_3 * V_113 = V_2 -> V_34 ;
struct V_15 * V_114 ;
struct V_3 * V_4 ;
if ( V_113 == NULL || V_2 -> V_35 >= V_2 -> V_86 ) {
do {
if ( F_37 ( V_2 , V_115 ) )
return - V_116 ;
V_114 = F_38 ( V_2 , V_115 ) ;
V_4 = F_6 ( F_11 ( V_114 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_114 ) ;
V_4 -> V_11 = NULL ;
F_39 ( V_2 , V_115 ) -- ;
V_25 = F_21 ( V_2 , V_4 , V_117 ) ;
} while ( V_25 == - V_43 || F_24 ( V_25 ) );
if ( V_25 )
return V_25 ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = V_4 ;
if ( V_113 )
F_28 ( V_2 , V_113 ) ;
}
* V_112 = ( V_2 -> V_34 - V_2 -> V_5 ) * V_2 -> V_86 +
V_2 -> V_35 ;
V_2 -> V_34 -> V_84 ++ ;
V_2 -> V_118 [ * V_112 ] = V_111 ;
V_2 -> V_35 ++ ;
return 0 ;
}
static unsigned int F_40 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_115 ) * V_2 -> V_86 +
V_2 -> V_86 - V_2 -> V_35 ;
}
static unsigned int F_41 ( struct V_1 * V_2 )
{
return F_40 ( V_2 ) > V_2 -> V_86 ;
}
static int F_42 ( struct V_1 * V_2 , char * V_119 ,
unsigned int V_111 , unsigned int * V_120 , int V_121 )
{
struct V_96 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
T_4 V_122 ;
T_1 V_123 ;
int V_25 ;
V_100:
if ( ! V_121 )
while ( ! F_41 ( V_2 ) )
if ( F_43 ( V_2 , 0 ) > 0 )
return - V_116 ;
V_25 = F_36 ( V_2 , V_111 , V_120 ) ;
V_4 = V_2 -> V_5 + ( * V_120 / V_2 -> V_86 ) ;
if ( V_25 == - V_43 || F_24 ( V_25 ) ) {
V_2 -> V_34 = NULL ;
V_4 -> V_84 -- ;
V_2 -> V_118 [ * V_120 ] = V_124 ;
goto V_100;
}
if ( V_25 < 0 )
return V_25 ;
V_123 = ( T_1 ) * V_120 << V_125 ;
V_25 = V_6 -> V_126 ( V_6 , V_123 , V_127 , & V_122 , V_119 ) ;
if ( V_25 == - V_43 || F_24 ( V_25 ) ) {
V_2 -> V_35 -- ;
V_4 -> V_84 -- ;
V_2 -> V_118 [ * V_120 ] = V_124 ;
F_15 ( V_2 , V_4 ) ;
goto V_100;
}
if ( V_25 < 0 ) {
F_34 ( V_2 -> V_31 , L_13 ,
V_25 , V_122 ) ;
goto V_128;
}
if ( V_122 != V_127 ) {
F_34 ( V_2 -> V_31 , L_14 ,
V_122 ) ;
V_25 = - V_43 ;
goto V_128;
}
return V_25 ;
V_128:
V_2 -> V_35 -- ;
V_4 -> V_84 -- ;
V_2 -> V_118 [ * V_120 ] = V_124 ;
return V_25 ;
}
static int F_44 ( struct V_1 * V_2 , unsigned int V_129 ,
unsigned int * V_130 )
{
struct V_96 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 , * V_131 ;
int V_25 ;
T_4 V_122 ;
unsigned int V_111 , V_99 ;
T_1 V_132 ;
V_111 = V_2 -> V_118 [ V_129 ] ;
V_132 = ( T_1 ) V_129 << V_125 ;
V_99 = 0 ;
V_100:
V_25 = V_6 -> V_133 ( V_6 , V_132 , V_127 , & V_122 , V_2 -> V_134 ) ;
if ( V_25 < 0 && ! F_17 ( V_25 ) ) {
V_131 = V_2 -> V_5 + V_129 / V_2 -> V_86 ;
V_131 -> V_28 |= V_77 ;
F_34 ( V_2 -> V_31 , L_15 , V_25 ,
V_129 ) ;
V_99 ++ ;
if ( V_99 < V_135 )
goto V_100;
goto V_136;
}
if ( V_122 != V_127 ) {
F_34 ( V_2 -> V_31 , L_16 , V_122 ,
V_129 ) ;
V_25 = - V_43 ;
goto V_136;
}
V_25 = F_42 ( V_2 , V_2 -> V_134 , V_111 , V_130 , 1 ) ;
if ( V_25 < 0 ) {
V_2 -> V_137 [ V_111 ] = V_138 ;
F_34 ( V_2 -> V_31 , L_17 , V_25 ) ;
return V_25 ;
}
V_4 = V_2 -> V_5 + * V_130 / V_2 -> V_86 ;
V_2 -> V_137 [ V_111 ] = * V_130 ;
V_2 -> V_118 [ V_129 ] = V_124 ;
V_4 = V_2 -> V_5 + V_129 / V_2 -> V_86 ;
V_4 -> V_84 -- ;
return 0 ;
V_136:
V_2 -> V_137 [ V_111 ] = V_138 ;
V_2 -> V_118 [ V_129 ] = V_124 ;
return V_25 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_24 , V_112 , V_139 , V_130 ;
int V_25 , V_140 ;
V_140 = 0 ;
V_139 = ( V_4 - V_2 -> V_5 ) * V_2 -> V_86 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_86 ; V_24 ++ ) {
if ( V_2 -> V_27 < V_141 )
return - V_116 ;
V_112 = V_139 + V_24 ;
if ( V_2 -> V_118 [ V_112 ] == V_124 )
continue;
V_25 = F_44 ( V_2 , V_112 , & V_130 ) ;
if ( V_25 < 0 && ! V_140 )
V_140 = V_25 ;
}
return V_140 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_23 , V_142 ;
if ( F_39 ( V_2 , V_115 ) < V_143 )
V_142 = V_90 ;
else
V_142 = V_91 ;
for ( V_23 = V_88 ; V_23 >= V_142 ; V_23 -- )
if ( V_2 -> V_12 [ V_23 ] . V_11 . V_16 != NULL )
return V_23 ;
return - 1 ;
}
static int F_47 ( unsigned int V_144 )
{
unsigned int V_145 , V_146 , V_147 , V_148 , V_149 ;
V_148 = V_144 - V_150 ;
if ( V_148 > V_151 )
V_148 = V_151 ;
V_145 = V_152 - V_153 ;
V_149 = V_151 ;
V_146 = V_148 - V_149 ;
V_147 = ( V_146 * V_145 + V_149 / 2 ) / V_149 ;
return V_153 + V_147 ;
}
static int F_48 ( struct V_1 * V_2 )
{
static unsigned int V_154 ;
unsigned int V_24 , V_23 = - 1 , V_155 , V_156 ;
struct V_15 * V_11 ;
V_156 = 0 ;
for ( V_24 = 0 ; V_24 <= V_81 ; V_24 ++ ) {
V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 == NULL )
continue;
V_155 = V_2 -> V_78 - F_49 ( V_11 ) ;
if ( V_155 > V_156 ) {
V_156 = V_155 ;
V_23 = V_24 ;
}
}
if ( V_156 > V_150 && V_154 >= F_47 ( V_156 ) - 1 ) {
V_154 = 0 ;
return V_23 ;
}
V_154 ++ ;
return - 1 ;
}
static int F_50 ( struct V_1 * V_2 ,
unsigned int V_157 )
{
int V_23 ;
if ( F_51 ( V_2 , V_158 ) &&
( V_157 || ( F_37 ( V_2 , V_115 ) && F_37 ( V_2 , V_159 ) ) ) )
return V_36 ;
V_23 = F_48 ( V_2 ) ;
if ( V_23 >= V_80 )
return V_23 ;
return F_46 ( V_2 ) ;
}
static struct V_3 * F_52 ( struct V_1 * V_2 ,
unsigned int V_157 )
{
struct V_15 * V_160 = NULL ;
struct V_3 * V_4 = NULL ;
int V_23 ;
if ( V_157 && F_39 ( V_2 , V_115 ) > V_161 &&
F_37 ( V_2 , V_159 ) && F_37 ( V_2 , V_158 ) )
return NULL ;
V_23 = F_50 ( V_2 , V_157 ) ;
if ( V_23 < 0 )
return NULL ;
V_160 = & V_2 -> V_12 [ V_23 ] . V_11 ;
V_4 = F_6 ( F_11 ( V_160 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_160 ) ;
V_4 -> V_11 = NULL ;
V_2 -> V_12 [ V_23 ] . V_13 -- ;
return V_4 ;
}
static unsigned int F_53 ( unsigned int V_24 )
{
return V_24 % 2 ? 0x55555555 : 0xAAAAAAAA ;
}
static unsigned int F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_96 * V_6 = V_2 -> V_6 ;
unsigned int V_162 , V_24 , V_163 , V_164 , V_165 ;
T_1 V_149 , V_166 ;
unsigned int * V_167 = ( unsigned int * ) V_2 -> V_134 ;
unsigned char * V_168 = ( unsigned char * ) V_2 -> V_52 ;
struct V_38 V_39 ;
int V_25 ;
V_39 . V_55 = V_56 ;
V_39 . V_103 = V_6 -> V_69 ;
V_39 . V_42 = V_6 -> V_49 -> V_50 ;
V_39 . V_53 = 0 ;
V_39 . V_54 = V_2 -> V_134 ;
V_39 . V_51 = V_2 -> V_52 ;
V_149 = F_1 ( V_2 , V_4 ) ;
V_165 = V_2 -> V_86 * V_127 / V_6 -> V_69 ;
for ( V_162 = 0 ; V_162 < 2 ; V_162 ++ ) {
V_166 = V_149 ;
for ( V_24 = 0 ; V_24 < V_165 ; V_24 ++ ) {
V_164 = F_53 ( V_162 + V_24 ) ;
memset ( V_2 -> V_134 , V_164 , V_6 -> V_69 ) ;
memset ( V_2 -> V_52 , V_164 , V_6 -> V_49 -> V_50 ) ;
V_25 = V_6 -> V_70 ( V_6 , V_166 , & V_39 ) ;
if ( V_25 )
goto error;
V_166 += V_6 -> V_69 ;
}
V_166 = V_149 ;
for ( V_24 = 0 ; V_24 < V_165 ; V_24 ++ ) {
V_25 = V_6 -> V_40 ( V_6 , V_166 , & V_39 ) ;
if ( V_25 )
goto error;
V_164 = F_53 ( V_162 + V_24 ) ;
for ( V_163 = 0 ; V_163 < V_6 -> V_69 / sizeof( int ) ; V_163 ++ )
if ( V_167 [ V_163 ] != V_164 )
goto error;
for ( V_163 = 0 ; V_163 < V_6 -> V_49 -> V_50 ; V_163 ++ )
if ( V_168 [ V_163 ] != ( unsigned char ) V_164 )
goto error;
V_166 += V_6 -> V_69 ;
}
V_25 = F_31 ( V_2 , V_4 ) ;
if ( V_25 )
goto error;
}
V_4 -> V_28 &= ~ V_77 ;
return 1 ;
error:
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , unsigned int V_157 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( V_2 -> V_27 < V_141 )
return 1 ;
V_4 = F_52 ( V_2 , V_157 ) ;
if ( ! V_4 )
return 1 ;
V_25 = F_45 ( V_2 , V_4 ) ;
if ( V_25 == - V_116 )
return 1 ;
if ( V_4 -> V_28 & V_33 ) {
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
V_4 -> V_28 &= ~ V_87 ;
V_25 = F_31 ( V_2 , V_4 ) ;
if ( ( V_4 -> V_28 & V_77 ) &&
( V_25 || ! F_54 ( V_2 , V_4 ) ) )
return 0 ;
if ( V_25 == 0 )
V_25 = F_21 ( V_2 , V_4 , V_67 ) ;
if ( V_25 == 0 )
F_9 ( V_2 , V_4 , V_80 ) ;
else if ( V_25 != - V_43 && ! F_24 ( V_25 ) )
F_9 ( V_2 , V_4 , V_81 ) ;
return 0 ;
}
static void F_55 ( struct V_169 * V_31 )
{
struct V_1 * V_2 = F_56 ( V_31 ) ;
int V_25 ;
while ( 1 ) {
V_25 = F_43 ( V_2 , 1 ) ;
if ( V_25 || F_57 ( V_31 ) )
return;
}
}
static void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 -> V_5 ) ;
F_59 ( V_2 -> V_118 ) ;
F_59 ( V_2 -> V_137 ) ;
F_60 ( V_2 -> V_52 ) ;
F_60 ( V_2 -> V_134 ) ;
}
static int F_61 ( struct V_169 * V_31 )
{
struct V_1 * V_2 = F_56 ( V_31 ) ;
if ( V_2 -> V_6 -> V_170 )
V_2 -> V_6 -> V_170 ( V_2 -> V_6 ) ;
return 0 ;
}
static unsigned int F_62 ( struct V_96 * V_6 , T_5 V_171 )
{
T_1 V_26 ;
unsigned int V_172 ;
V_172 = 0 ;
if ( V_6 -> V_47 )
for ( V_26 = 0 ; V_26 < V_171 ; V_26 += V_6 -> V_7 )
if ( V_6 -> V_47 ( V_6 , V_26 ) )
V_172 ++ ;
return V_172 ;
}
static int F_63 ( struct V_169 * V_31 ,
unsigned long V_111 , char * V_119 )
{
struct V_1 * V_2 = F_56 ( V_31 ) ;
unsigned int V_130 , V_173 ;
struct V_3 * V_4 ;
int V_25 ;
V_2 -> V_174 ++ ;
if ( V_2 -> V_27 < V_141 )
return - V_116 ;
if ( V_175 ) {
if ( F_64 ( V_111 == 0 ) )
return 0 ;
V_111 -- ;
}
V_173 = V_2 -> V_137 [ V_111 ] ;
if ( V_173 <= V_176 ) {
V_4 = V_2 -> V_5 + ( V_173 / V_2 -> V_86 ) ;
V_4 -> V_84 -- ;
F_28 ( V_2 , V_4 ) ;
V_2 -> V_137 [ V_111 ] = V_177 ;
V_2 -> V_118 [ V_173 ] = V_124 ;
}
V_25 = F_42 ( V_2 , V_119 , V_111 , & V_130 , 0 ) ;
V_2 -> V_178 ++ ;
if ( V_25 < 0 )
return V_25 ;
V_4 = V_2 -> V_5 + ( V_130 / V_2 -> V_86 ) ;
V_2 -> V_137 [ V_111 ] = V_130 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , char * V_119 )
{
union V_179 * V_180 = (union V_179 * ) ( V_119 ) ;
memset ( V_119 , 0 , V_127 - 10 ) ;
V_180 -> V_181 . V_182 = 1 ;
V_180 -> V_181 . V_183 = V_2 -> V_184 -> V_171 - 1 ;
V_180 -> V_181 . V_185 = 0 ;
memcpy ( V_119 + V_127 - 10 , L_18 , 10 ) ;
return 0 ;
}
static int F_66 ( struct V_169 * V_31 ,
unsigned long V_111 , char * V_119 )
{
struct V_1 * V_2 = F_56 ( V_31 ) ;
struct V_96 * V_6 = V_2 -> V_6 ;
unsigned int V_186 , V_99 ;
T_1 V_132 ;
struct V_3 * V_4 ;
T_4 V_122 ;
int V_25 ;
V_2 -> V_187 ++ ;
if ( V_175 ) {
if ( F_64 ( V_111 == 0 ) )
return F_65 ( V_2 , V_119 ) ;
V_111 -- ;
}
V_186 = V_2 -> V_137 [ V_111 ] ;
if ( V_186 > V_176 ) {
memset ( V_119 , 0x0 , V_127 ) ;
if ( V_186 == V_177 )
return 0 ;
else
return - V_43 ;
}
V_4 = V_2 -> V_5 + ( V_186 / V_2 -> V_86 ) ;
F_67 ( V_2 -> V_118 [ V_186 ] == V_124 ) ;
V_132 = ( T_1 ) V_186 << V_125 ;
V_99 = 0 ;
V_100:
V_25 = V_6 -> V_133 ( V_6 , V_132 , V_127 , & V_122 , V_119 ) ;
V_2 -> V_188 ++ ;
if ( F_17 ( V_25 ) ) {
V_4 -> V_28 |= V_87 ;
F_9 ( V_2 , V_4 , V_88 ) ;
V_25 = 0 ;
}
if ( V_25 < 0 ) {
F_34 ( V_2 -> V_31 , L_19 , V_25 ) ;
V_4 -> V_28 |= V_77 ;
F_9 ( V_2 , V_4 , V_36 ) ;
V_99 ++ ;
if ( V_99 < V_135 )
goto V_100;
return V_25 ;
}
if ( V_122 != V_127 ) {
F_34 ( V_2 -> V_31 , L_20 , V_122 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_68 ( struct V_169 * V_31 , unsigned long V_189 ,
unsigned V_190 )
{
struct V_1 * V_2 = F_56 ( V_31 ) ;
unsigned long V_111 ;
struct V_3 * V_4 ;
unsigned int V_173 ;
V_2 -> V_191 ++ ;
for ( V_111 = V_189 ; V_111 < V_189 + V_190 ; V_111 ++ ) {
V_173 = V_2 -> V_137 [ V_111 ] ;
if ( V_173 <= V_176 ) {
V_4 = V_2 -> V_5 + ( V_173 / V_2 -> V_86 ) ;
V_4 -> V_84 -- ;
F_28 ( V_2 , V_4 ) ;
V_2 -> V_137 [ V_111 ] = V_177 ;
V_2 -> V_118 [ V_173 ] = V_124 ;
V_2 -> V_192 ++ ;
} else if ( V_173 == V_138 ) {
V_2 -> V_137 [ V_111 ] = V_177 ;
V_2 -> V_192 ++ ;
}
}
return 0 ;
}
static int F_69 ( struct V_193 * V_194 , void * V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_194 -> V_195 ;
unsigned long V_196 ;
unsigned int V_13 [ V_197 ] ;
unsigned int V_198 [ V_197 ] ;
unsigned int V_156 [ V_197 ] ;
unsigned int V_24 , V_199 = 0 , V_200 = 0 , V_201 = 0 , V_202 , V_173 , V_203 ;
T_5 V_204 ;
char * V_106 [] = { L_21 , L_22 , L_23 , L_24 , L_25 , L_26 ,
L_27 } ;
F_70 ( & V_2 -> V_184 -> V_205 ) ;
for ( V_24 = 0 ; V_24 < V_197 ; V_24 ++ ) {
struct V_15 * V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 ) {
V_13 [ V_24 ] = V_2 -> V_12 [ V_24 ] . V_13 ;
V_198 [ V_24 ] = F_6 ( F_11 ( V_11 ) , struct V_3 ,
V_14 ) -> V_20 ;
V_156 [ V_24 ] = F_6 ( F_71 ( V_11 ) , struct V_3 ,
V_14 ) -> V_20 ;
} else
V_13 [ V_24 ] = 0 ;
}
if ( V_2 -> V_34 ) {
V_199 = 1 ;
V_200 = V_2 -> V_35 ;
V_201 = V_2 -> V_34 -> V_20 ;
}
V_196 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_76 ; V_24 ++ )
V_196 += V_2 -> V_5 [ V_24 ] . V_20 ;
V_204 = ( T_5 ) V_2 -> V_76 * V_2 -> V_6 -> V_7 ;
V_202 = F_62 ( V_2 -> V_6 , V_204 ) ;
V_173 = 0 ;
V_203 = V_2 -> V_184 -> V_171 ;
for ( V_24 = 0 ; V_24 < V_203 ; V_24 ++ )
if ( V_2 -> V_137 [ V_24 ] != V_177 )
V_173 ++ ;
F_72 ( & V_2 -> V_184 -> V_205 ) ;
for ( V_24 = 0 ; V_24 < V_197 ; V_24 ++ ) {
if ( ! V_13 [ V_24 ] )
continue;
if ( V_198 [ V_24 ] != V_156 [ V_24 ] )
F_73 ( V_194 , L_28
L_29 ,
V_106 [ V_24 ] , V_13 [ V_24 ] , V_198 [ V_24 ] , V_156 [ V_24 ] ) ;
else
F_73 ( V_194 , L_30
L_31 , V_106 [ V_24 ] , V_13 [ V_24 ] , V_198 [ V_24 ] ) ;
}
if ( V_202 )
F_73 ( V_194 , L_32 , V_202 ) ;
if ( V_199 )
F_73 ( V_194 , L_33
L_34 ,
V_200 , V_2 -> V_86 - V_200 , V_201 ) ;
F_73 ( V_194 , L_35 , V_196 ) ;
F_73 ( V_194 , L_36 ) ;
F_73 ( V_194 , L_37 , V_2 -> V_187 ) ;
F_73 ( V_194 , L_38 , V_2 -> V_174 ) ;
F_73 ( V_194 , L_39 , V_2 -> V_191 ) ;
F_73 ( V_194 , L_40 , V_2 -> V_188 ) ;
F_73 ( V_194 , L_41 , V_2 -> V_178 ) ;
F_73 ( V_194 , L_42 , V_2 -> V_192 ) ;
F_73 ( V_194 , L_36 ) ;
F_73 ( V_194 , L_43 , V_203 ) ;
F_73 ( V_194 , L_44 , V_173 ) ;
return 0 ;
}
static int F_74 ( struct V_206 * V_206 , struct V_207 * V_207 )
{
return F_75 ( V_207 , F_69 , V_206 -> V_208 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_209 * V_210 = V_2 -> V_184 -> V_211 ;
struct V_212 * V_31 = F_77 ( V_210 ) ;
struct V_213 * V_11 ;
struct V_213 * V_214 ;
V_11 = F_78 ( V_210 -> V_215 , NULL ) ;
if ( F_79 ( V_11 ) )
return 0 ;
if ( ! V_11 ) {
F_34 ( V_31 , L_45 ) ;
return - 1 ;
}
V_2 -> V_216 = V_11 ;
V_214 = F_80 ( L_46 , V_217 , V_11 , V_2 ,
& V_218 ) ;
if ( ! V_214 ) {
F_34 ( V_2 -> V_31 , L_47 ) ;
F_81 ( V_11 ) ;
V_2 -> V_216 = NULL ;
return - 1 ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , unsigned int V_219 ,
unsigned int V_220 )
{
struct V_96 * V_6 = V_2 -> V_184 -> V_6 ;
unsigned int V_24 , V_221 , V_203 , V_222 ;
int V_25 = - V_223 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_76 = V_219 ;
V_2 -> V_27 = V_220 ;
V_2 -> V_86 = V_6 -> V_7 >> V_125 ;
V_203 = V_2 -> V_184 -> V_171 ;
V_222 = V_219 * V_2 -> V_86 ;
for ( V_24 = 0 ; V_24 < V_197 ; V_24 ++ )
V_2 -> V_12 [ V_24 ] . V_11 = V_72 ;
V_2 -> V_137 = F_83 ( sizeof( int ) * V_203 ) ;
if ( ! V_2 -> V_137 )
goto V_224;
V_2 -> V_118 = F_83 ( sizeof( int ) * V_222 ) ;
if ( ! V_2 -> V_118 )
goto V_225;
V_221 = sizeof( struct V_3 ) * V_2 -> V_76 ;
V_2 -> V_5 = F_84 ( V_221 ) ;
if ( ! V_2 -> V_5 )
goto V_226;
for ( V_24 = 0 ; V_24 < V_203 ; V_24 ++ )
V_2 -> V_137 [ V_24 ] = V_177 ;
for ( V_24 = 0 ; V_24 < V_222 ; V_24 ++ )
V_2 -> V_118 [ V_24 ] = V_124 ;
V_2 -> V_134 = F_85 ( V_127 , V_227 ) ;
if ( ! V_2 -> V_134 )
goto V_228;
V_2 -> V_52 = F_85 ( 2 * V_6 -> V_49 -> V_50 , V_227 ) ;
if ( ! V_2 -> V_52 )
goto V_229;
F_27 ( V_2 ) ;
return 0 ;
V_229:
F_60 ( V_2 -> V_134 ) ;
V_228:
F_59 ( V_2 -> V_5 ) ;
V_226:
F_59 ( V_2 -> V_118 ) ;
V_225:
F_59 ( V_2 -> V_137 ) ;
V_224:
F_86 ( V_230 L_48 , V_231 , V_25 ) ;
return V_25 ;
}
static void F_87 ( struct V_232 * V_233 , struct V_96 * V_6 )
{
struct V_1 * V_2 ;
struct V_169 * V_184 ;
char * V_234 ;
char * V_235 ;
unsigned long V_236 ;
unsigned int V_219 , V_237 , V_238 , V_220 ;
T_5 V_239 , V_204 , V_240 ;
struct V_241 * V_242 ;
int V_25 ;
V_234 = & V_243 [ 0 ] ;
if ( ! * V_234 )
return;
while ( ( V_235 = F_88 ( & V_234 , L_49 ) ) != NULL ) {
if ( F_89 ( V_235 , 0 , & V_236 ) < 0 )
return;
if ( V_6 -> V_244 == V_236 )
break;
}
if ( V_6 -> V_244 != V_236 )
return;
if ( V_6 -> V_7 < V_127 || V_6 -> V_7 % V_127 ) {
F_86 ( V_230 L_50
L_51 , V_231 , V_6 -> V_7 , V_127 ) ;
return;
}
if ( V_127 % V_6 -> V_69 || V_6 -> V_69 > V_127 ) {
F_86 ( V_230 L_52
L_53 , V_231 , V_127 , V_6 -> V_69 ) ;
return;
}
V_242 = V_6 -> V_49 ;
if ( ! V_242 ) {
F_86 ( V_230 L_54 ,
V_231 , V_6 -> V_244 ) ;
return;
}
if ( ! V_6 -> V_245 || V_242 -> V_50 < V_68 ) {
F_86 ( V_230 L_55
L_56 ,
V_231 , V_242 -> V_50 , V_68 ) ;
return;
}
if ( V_246 > 100 )
V_246 = 100 ;
V_204 = V_6 -> V_171 ;
V_240 = ( T_5 ) V_176 * V_127 ;
if ( V_6 -> V_171 > V_240 ) {
F_86 ( V_247 L_57
L_58 , V_231 , V_240 ) ;
V_204 = V_240 ;
}
V_219 = F_90 ( V_204 , V_6 ) ;
V_204 = V_219 * V_6 -> V_7 ;
V_238 = F_62 ( V_6 , V_204 ) ;
V_237 = V_219 - V_238 ;
if ( V_237 < V_248 ) {
F_86 ( V_230 L_59
L_60 , V_231 , V_237 ,
V_248 ) ;
return;
}
V_220 = F_91 ( ( T_5 ) V_237 * V_246 , 100 ) ;
if ( V_220 < V_141 )
V_220 = V_141 ;
if ( V_220 > V_237 - 1 )
V_220 = V_237 - 1 ;
V_239 = ( T_5 ) ( V_237 - V_220 ) * V_6 -> V_7 +
( V_175 ? V_127 : 0 ) ;
F_86 ( V_249 L_61
L_62 ,
V_231 , V_236 , V_239 / 1024 , V_220 , V_238 ) ;
V_2 = F_92 ( sizeof( struct V_1 ) , V_227 ) ;
if ( ! V_2 )
return;
V_184 = F_92 ( sizeof( struct V_169 ) , V_227 ) ;
if ( ! V_184 ) {
F_60 ( V_2 ) ;
return;
}
V_2 -> V_184 = V_184 ;
V_184 -> V_95 = V_2 ;
V_184 -> V_6 = V_6 ;
V_184 -> V_250 = V_6 -> V_244 ;
V_184 -> V_171 = V_239 >> V_125 ;
V_184 -> V_233 = V_233 ;
if ( ! ( V_6 -> V_28 & V_251 ) )
V_184 -> V_252 = 1 ;
if ( F_82 ( V_2 , V_219 , V_220 ) < 0 )
goto V_253;
if ( F_93 ( V_184 ) < 0 )
goto V_254;
V_2 -> V_31 = F_77 ( V_184 -> V_211 ) ;
V_25 = F_76 ( V_2 ) ;
if ( V_25 < 0 )
goto V_255;
return;
V_255:
F_94 ( V_184 ) ;
V_254:
F_58 ( V_2 ) ;
V_253:
F_60 ( V_184 ) ;
F_60 ( V_2 ) ;
}
static void F_95 ( struct V_169 * V_31 )
{
struct V_1 * V_2 = F_56 ( V_31 ) ;
F_81 ( V_2 -> V_216 ) ;
F_94 ( V_31 ) ;
F_58 ( V_2 ) ;
F_60 ( V_2 ) ;
}
static int T_6 F_96 ( void )
{
return F_97 ( & V_256 ) ;
}
static void T_7 F_98 ( void )
{
F_99 ( & V_256 ) ;
}
