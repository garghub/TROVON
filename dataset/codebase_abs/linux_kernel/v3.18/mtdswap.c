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
if ( ! F_14 ( V_2 -> V_6 ) )
return 1 ;
V_26 = F_1 ( V_2 , V_4 ) ;
F_15 ( V_2 -> V_30 , L_1 , V_26 ) ;
V_25 = F_16 ( V_2 -> V_6 , V_26 ) ;
if ( V_25 ) {
F_15 ( V_2 -> V_30 , L_2
L_3 , V_26 , V_25 ) ;
return V_25 ;
}
return 1 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_31 = V_4 -> V_28 & V_32 ;
struct V_3 * V_33 = V_2 -> V_33 ;
V_4 -> V_28 |= V_32 ;
if ( V_33 == V_4 ) {
V_2 -> V_33 = NULL ;
if ( ! V_31 && V_2 -> V_34 != 0 ) {
F_9 ( V_2 , V_4 , V_35 ) ;
return 0 ;
}
}
return F_13 ( V_2 , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_36 ,
struct V_37 * V_38 )
{
int V_25 = F_19 ( V_2 -> V_6 , V_36 , V_38 ) ;
if ( F_20 ( V_25 ) )
return V_25 ;
if ( V_25 ) {
F_15 ( V_2 -> V_30 , L_4 ,
V_25 , V_36 ) ;
return V_25 ;
}
if ( V_38 -> V_39 < V_38 -> V_40 ) {
F_15 ( V_2 -> V_30 , L_5
L_6 ,
V_38 -> V_39 , V_38 -> V_40 , V_36 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_43 , * V_44 ;
int V_25 ;
T_1 V_26 ;
struct V_37 V_38 ;
V_26 = F_1 ( V_2 , V_4 ) ;
if ( F_14 ( V_2 -> V_6 ) && F_22 ( V_2 -> V_6 , V_26 ) )
return V_45 ;
V_38 . V_40 = 2 * V_2 -> V_6 -> V_46 -> V_47 ;
V_38 . V_48 = V_2 -> V_49 ;
V_38 . V_50 = 0 ;
V_38 . V_51 = NULL ;
V_38 . V_52 = V_53 ;
V_25 = F_18 ( V_2 , V_26 , & V_38 ) ;
if ( V_25 && ! F_20 ( V_25 ) )
return V_25 ;
V_43 = (struct V_42 * ) V_2 -> V_49 ;
V_44 = (struct V_42 * )
( V_2 -> V_49 + V_2 -> V_6 -> V_46 -> V_47 ) ;
if ( F_23 ( V_43 -> V_54 ) == V_55 ) {
V_4 -> V_20 = F_24 ( V_43 -> V_13 ) ;
if ( F_20 ( V_25 ) )
V_25 = V_56 ;
else {
if ( F_23 ( V_44 -> V_54 ) == V_57 )
V_25 = V_58 ;
else
V_25 = V_59 ;
}
} else {
V_4 -> V_28 |= V_60 ;
V_25 = V_58 ;
}
return V_25 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_61 )
{
struct V_42 V_62 ;
int V_25 ;
T_1 V_26 ;
struct V_37 V_38 ;
V_38 . V_50 = 0 ;
V_38 . V_48 = ( V_63 * ) & V_62 ;
V_38 . V_52 = V_53 ;
V_38 . V_51 = NULL ;
if ( V_61 == V_64 ) {
V_62 . V_54 = F_26 ( V_55 ) ;
V_62 . V_13 = F_27 ( V_4 -> V_20 ) ;
V_38 . V_40 = V_65 ;
V_26 = F_1 ( V_2 , V_4 ) ;
} else {
V_62 . V_54 = F_26 ( V_57 ) ;
V_38 . V_40 = sizeof( V_62 . V_54 ) ;
V_26 = F_1 ( V_2 , V_4 ) + V_2 -> V_6 -> V_66 ;
}
V_25 = F_28 ( V_2 -> V_6 , V_26 , & V_38 ) ;
if ( V_25 ) {
F_15 ( V_2 -> V_30 , L_7
L_3 , V_26 , V_25 ) ;
if ( V_25 == - V_41 || F_29 ( V_25 ) )
F_17 ( V_2 , V_4 ) ;
return V_25 ;
}
if ( V_38 . V_39 != V_38 . V_40 ) {
F_15 ( V_2 -> V_30 , L_8
L_9 ,
V_26 , V_38 . V_39 , V_38 . V_40 ) ;
return V_25 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_15 V_67 = V_68 ;
struct V_16 * V_69 ;
struct V_3 * V_4 ;
unsigned int V_24 , V_70 , V_71 ;
V_70 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_72 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_60 | V_29 | V_73 ) )
continue;
F_5 ( & V_67 , V_4 ) ;
V_70 ++ ;
}
if ( V_70 == 0 )
return;
V_69 = F_10 ( & V_67 , V_70 / 2 ) ;
V_71 = F_6 ( V_69 , struct V_3 , V_14 ) -> V_20 ;
V_2 -> V_74 = F_31 ( & V_67 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_72 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_60 | V_73 ) )
V_4 -> V_20 = V_71 ;
if ( V_4 -> V_28 & ( V_60 | V_29 | V_73 ) )
continue;
F_4 ( & V_4 -> V_14 , & V_67 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
int V_75 ;
unsigned int V_24 , V_23 ;
struct V_3 * V_4 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_72 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
V_75 = F_21 ( V_2 , V_4 ) ;
if ( V_75 < 0 )
V_4 -> V_28 |= V_73 ;
else if ( V_75 == V_45 ) {
V_4 -> V_28 |= V_29 ;
continue;
}
switch ( V_75 ) {
case V_59 :
V_23 = V_76 ;
break;
case V_58 :
case V_56 :
V_23 = V_77 ;
break;
default:
V_23 = V_35 ;
}
V_4 -> V_28 |= ( V_23 << V_78 ) ;
}
F_30 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_72 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & V_29 )
continue;
V_23 = V_4 -> V_28 >> V_78 ;
F_9 ( V_2 , V_4 , V_23 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_79 = V_4 -> V_80 ;
unsigned int V_81 = V_2 -> V_82 ;
if ( V_4 == V_2 -> V_33 )
return;
if ( V_4 -> V_28 & V_83 )
F_9 ( V_2 , V_4 , V_84 ) ;
else if ( V_4 -> V_28 & ( V_73 | V_32 ) )
F_9 ( V_2 , V_4 , V_35 ) ;
if ( V_79 == V_81 )
F_9 ( V_2 , V_4 , V_85 ) ;
else if ( V_79 == 0 )
F_9 ( V_2 , V_4 , V_77 ) ;
else if ( V_79 > ( V_81 / 2 ) )
F_9 ( V_2 , V_4 , V_86 ) ;
else
F_9 ( V_2 , V_4 , V_87 ) ;
}
static void F_34 ( struct V_88 * V_89 )
{
T_3 * V_90 = ( T_3 * ) V_89 -> V_91 ;
F_35 ( V_90 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_92 * V_6 = V_2 -> V_6 ;
struct V_88 V_93 ;
T_3 V_94 ;
unsigned int V_95 = 0 ;
int V_25 ;
V_4 -> V_20 ++ ;
if ( V_4 -> V_20 > V_2 -> V_74 )
V_2 -> V_74 = V_4 -> V_20 ;
V_96:
F_37 ( & V_94 ) ;
memset ( & V_93 , 0 , sizeof( struct V_88 ) ) ;
V_93 . V_6 = V_6 ;
V_93 . V_97 = F_34 ;
V_93 . V_98 = F_1 ( V_2 , V_4 ) ;
V_93 . V_99 = V_6 -> V_7 ;
V_93 . V_91 = ( V_100 ) & V_94 ;
V_25 = F_38 ( V_6 , & V_93 ) ;
if ( V_25 ) {
if ( V_95 ++ < V_101 ) {
F_15 ( V_2 -> V_30 ,
L_10 ,
V_93 . V_98 , V_6 -> V_102 ) ;
F_39 () ;
goto V_96;
}
F_40 ( V_2 -> V_30 , L_11 ,
V_93 . V_98 , V_6 -> V_102 ) ;
F_13 ( V_2 , V_4 ) ;
return - V_41 ;
}
V_25 = F_41 ( V_94 , V_93 . V_103 == V_104 ||
V_93 . V_103 == V_105 ) ;
if ( V_25 ) {
F_40 ( V_2 -> V_30 , L_12 ,
V_93 . V_98 , V_6 -> V_102 ) ;
return - V_106 ;
}
if ( V_93 . V_103 == V_105 ) {
if ( V_95 ++ < V_101 ) {
F_15 ( V_2 -> V_30 ,
L_10 ,
V_93 . V_98 , V_6 -> V_102 ) ;
F_39 () ;
goto V_96;
}
F_13 ( V_2 , V_4 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_107 ,
unsigned int * V_108 )
{
int V_25 ;
struct V_3 * V_109 = V_2 -> V_33 ;
struct V_15 * V_110 ;
struct V_3 * V_4 ;
if ( V_109 == NULL || V_2 -> V_34 >= V_2 -> V_82 ) {
do {
if ( F_43 ( V_2 , V_111 ) )
return - V_112 ;
V_110 = F_44 ( V_2 , V_111 ) ;
V_4 = F_6 ( F_11 ( V_110 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_110 ) ;
V_4 -> V_11 = NULL ;
F_45 ( V_2 , V_111 ) -- ;
V_25 = F_25 ( V_2 , V_4 , V_113 ) ;
} while ( V_25 == - V_41 || F_29 ( V_25 ) );
if ( V_25 )
return V_25 ;
V_2 -> V_34 = 0 ;
V_2 -> V_33 = V_4 ;
if ( V_109 )
F_33 ( V_2 , V_109 ) ;
}
* V_108 = ( V_2 -> V_33 - V_2 -> V_5 ) * V_2 -> V_82 +
V_2 -> V_34 ;
V_2 -> V_33 -> V_80 ++ ;
V_2 -> V_114 [ * V_108 ] = V_107 ;
V_2 -> V_34 ++ ;
return 0 ;
}
static unsigned int F_46 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_111 ) * V_2 -> V_82 +
V_2 -> V_82 - V_2 -> V_34 ;
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) > V_2 -> V_82 ;
}
static int F_48 ( struct V_1 * V_2 , char * V_115 ,
unsigned int V_107 , unsigned int * V_116 , int V_117 )
{
struct V_92 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
T_4 V_118 ;
T_1 V_119 ;
int V_25 ;
V_96:
if ( ! V_117 )
while ( ! F_47 ( V_2 ) )
if ( F_49 ( V_2 , 0 ) > 0 )
return - V_112 ;
V_25 = F_42 ( V_2 , V_107 , V_116 ) ;
V_4 = V_2 -> V_5 + ( * V_116 / V_2 -> V_82 ) ;
if ( V_25 == - V_41 || F_29 ( V_25 ) ) {
V_2 -> V_33 = NULL ;
V_4 -> V_80 -- ;
V_2 -> V_114 [ * V_116 ] = V_120 ;
goto V_96;
}
if ( V_25 < 0 )
return V_25 ;
V_119 = ( T_1 ) * V_116 << V_121 ;
V_25 = F_50 ( V_6 , V_119 , V_122 , & V_118 , V_115 ) ;
if ( V_25 == - V_41 || F_29 ( V_25 ) ) {
V_2 -> V_34 -- ;
V_4 -> V_80 -- ;
V_2 -> V_114 [ * V_116 ] = V_120 ;
F_17 ( V_2 , V_4 ) ;
goto V_96;
}
if ( V_25 < 0 ) {
F_40 ( V_2 -> V_30 , L_13 ,
V_25 , V_118 ) ;
goto V_123;
}
if ( V_118 != V_122 ) {
F_40 ( V_2 -> V_30 , L_14 ,
V_118 ) ;
V_25 = - V_41 ;
goto V_123;
}
return V_25 ;
V_123:
V_2 -> V_34 -- ;
V_4 -> V_80 -- ;
V_2 -> V_114 [ * V_116 ] = V_120 ;
return V_25 ;
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_124 ,
unsigned int * V_125 )
{
struct V_92 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 , * V_126 ;
int V_25 ;
T_4 V_118 ;
unsigned int V_107 , V_95 ;
T_1 V_127 ;
V_107 = V_2 -> V_114 [ V_124 ] ;
V_127 = ( T_1 ) V_124 << V_121 ;
V_95 = 0 ;
V_96:
V_25 = F_52 ( V_6 , V_127 , V_122 , & V_118 , V_2 -> V_128 ) ;
if ( V_25 < 0 && ! F_20 ( V_25 ) ) {
V_126 = V_2 -> V_5 + V_124 / V_2 -> V_82 ;
V_126 -> V_28 |= V_73 ;
F_40 ( V_2 -> V_30 , L_15 , V_25 ,
V_124 ) ;
V_95 ++ ;
if ( V_95 < V_129 )
goto V_96;
goto V_130;
}
if ( V_118 != V_122 ) {
F_40 ( V_2 -> V_30 , L_16 , V_118 ,
V_124 ) ;
V_25 = - V_41 ;
goto V_130;
}
V_25 = F_48 ( V_2 , V_2 -> V_128 , V_107 , V_125 , 1 ) ;
if ( V_25 < 0 ) {
V_2 -> V_131 [ V_107 ] = V_132 ;
F_40 ( V_2 -> V_30 , L_17 , V_25 ) ;
return V_25 ;
}
V_4 = V_2 -> V_5 + * V_125 / V_2 -> V_82 ;
V_2 -> V_131 [ V_107 ] = * V_125 ;
V_2 -> V_114 [ V_124 ] = V_120 ;
V_4 = V_2 -> V_5 + V_124 / V_2 -> V_82 ;
V_4 -> V_80 -- ;
return 0 ;
V_130:
V_2 -> V_131 [ V_107 ] = V_132 ;
V_2 -> V_114 [ V_124 ] = V_120 ;
return V_25 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_24 , V_108 , V_133 , V_125 ;
int V_25 , V_134 ;
V_134 = 0 ;
V_133 = ( V_4 - V_2 -> V_5 ) * V_2 -> V_82 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_82 ; V_24 ++ ) {
if ( V_2 -> V_27 < V_135 )
return - V_112 ;
V_108 = V_133 + V_24 ;
if ( V_2 -> V_114 [ V_108 ] == V_120 )
continue;
V_25 = F_51 ( V_2 , V_108 , & V_125 ) ;
if ( V_25 < 0 && ! V_134 )
V_134 = V_25 ;
}
return V_134 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_23 , V_136 ;
if ( F_45 ( V_2 , V_111 ) < V_137 )
V_136 = V_86 ;
else
V_136 = V_87 ;
for ( V_23 = V_84 ; V_23 >= V_136 ; V_23 -- )
if ( V_2 -> V_12 [ V_23 ] . V_11 . V_16 != NULL )
return V_23 ;
return - 1 ;
}
static int F_55 ( unsigned int V_138 )
{
unsigned int V_139 , V_140 , V_141 , V_142 , V_143 ;
V_142 = V_138 - V_144 ;
if ( V_142 > V_145 )
V_142 = V_145 ;
V_139 = V_146 - V_147 ;
V_143 = V_145 ;
V_140 = V_142 - V_143 ;
V_141 = ( V_140 * V_139 + V_143 / 2 ) / V_143 ;
return V_147 + V_141 ;
}
static int F_56 ( struct V_1 * V_2 )
{
static unsigned int V_148 ;
unsigned int V_24 , V_23 = - 1 , V_149 , V_150 ;
struct V_15 * V_11 ;
V_150 = 0 ;
for ( V_24 = 0 ; V_24 <= V_77 ; V_24 ++ ) {
V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 == NULL )
continue;
V_149 = V_2 -> V_74 - F_57 ( V_11 ) ;
if ( V_149 > V_150 ) {
V_150 = V_149 ;
V_23 = V_24 ;
}
}
if ( V_150 > V_144 && V_148 >= F_55 ( V_150 ) - 1 ) {
V_148 = 0 ;
return V_23 ;
}
V_148 ++ ;
return - 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned int V_151 )
{
int V_23 ;
if ( F_59 ( V_2 , V_152 ) &&
( V_151 || ( F_43 ( V_2 , V_111 ) && F_43 ( V_2 , V_153 ) ) ) )
return V_35 ;
V_23 = F_56 ( V_2 ) ;
if ( V_23 >= V_76 )
return V_23 ;
return F_54 ( V_2 ) ;
}
static struct V_3 * F_60 ( struct V_1 * V_2 ,
unsigned int V_151 )
{
struct V_15 * V_154 = NULL ;
struct V_3 * V_4 = NULL ;
int V_23 ;
if ( V_151 && F_45 ( V_2 , V_111 ) > V_155 &&
F_43 ( V_2 , V_153 ) && F_43 ( V_2 , V_152 ) )
return NULL ;
V_23 = F_58 ( V_2 , V_151 ) ;
if ( V_23 < 0 )
return NULL ;
V_154 = & V_2 -> V_12 [ V_23 ] . V_11 ;
V_4 = F_6 ( F_11 ( V_154 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_154 ) ;
V_4 -> V_11 = NULL ;
V_2 -> V_12 [ V_23 ] . V_13 -- ;
return V_4 ;
}
static unsigned int F_61 ( unsigned int V_24 )
{
return V_24 % 2 ? 0x55555555 : 0xAAAAAAAA ;
}
static unsigned int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_92 * V_6 = V_2 -> V_6 ;
unsigned int V_156 , V_24 , V_157 , V_158 , V_159 ;
T_1 V_143 , V_160 ;
unsigned int * V_161 = ( unsigned int * ) V_2 -> V_128 ;
unsigned char * V_162 = ( unsigned char * ) V_2 -> V_49 ;
struct V_37 V_38 ;
int V_25 ;
V_38 . V_52 = V_53 ;
V_38 . V_99 = V_6 -> V_66 ;
V_38 . V_40 = V_6 -> V_46 -> V_47 ;
V_38 . V_50 = 0 ;
V_38 . V_51 = V_2 -> V_128 ;
V_38 . V_48 = V_2 -> V_49 ;
V_143 = F_1 ( V_2 , V_4 ) ;
V_159 = V_2 -> V_82 * V_122 / V_6 -> V_66 ;
for ( V_156 = 0 ; V_156 < 2 ; V_156 ++ ) {
V_160 = V_143 ;
for ( V_24 = 0 ; V_24 < V_159 ; V_24 ++ ) {
V_158 = F_61 ( V_156 + V_24 ) ;
memset ( V_2 -> V_128 , V_158 , V_6 -> V_66 ) ;
memset ( V_2 -> V_49 , V_158 , V_6 -> V_46 -> V_47 ) ;
V_25 = F_28 ( V_6 , V_160 , & V_38 ) ;
if ( V_25 )
goto error;
V_160 += V_6 -> V_66 ;
}
V_160 = V_143 ;
for ( V_24 = 0 ; V_24 < V_159 ; V_24 ++ ) {
V_25 = F_19 ( V_6 , V_160 , & V_38 ) ;
if ( V_25 )
goto error;
V_158 = F_61 ( V_156 + V_24 ) ;
for ( V_157 = 0 ; V_157 < V_6 -> V_66 / sizeof( int ) ; V_157 ++ )
if ( V_161 [ V_157 ] != V_158 )
goto error;
for ( V_157 = 0 ; V_157 < V_6 -> V_46 -> V_47 ; V_157 ++ )
if ( V_162 [ V_157 ] != ( unsigned char ) V_158 )
goto error;
V_160 += V_6 -> V_66 ;
}
V_25 = F_36 ( V_2 , V_4 ) ;
if ( V_25 )
goto error;
}
V_4 -> V_28 &= ~ V_73 ;
return 1 ;
error:
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , unsigned int V_151 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( V_2 -> V_27 < V_135 )
return 1 ;
V_4 = F_60 ( V_2 , V_151 ) ;
if ( ! V_4 )
return 1 ;
V_25 = F_53 ( V_2 , V_4 ) ;
if ( V_25 == - V_112 )
return 1 ;
if ( V_4 -> V_28 & V_32 ) {
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
V_4 -> V_28 &= ~ V_83 ;
V_25 = F_36 ( V_2 , V_4 ) ;
if ( ( V_4 -> V_28 & V_73 ) &&
( V_25 || ! F_62 ( V_2 , V_4 ) ) )
return 0 ;
if ( V_25 == 0 )
V_25 = F_25 ( V_2 , V_4 , V_64 ) ;
if ( V_25 == 0 )
F_9 ( V_2 , V_4 , V_76 ) ;
else if ( V_25 != - V_41 && ! F_29 ( V_25 ) )
F_9 ( V_2 , V_4 , V_77 ) ;
return 0 ;
}
static void F_63 ( struct V_163 * V_30 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
int V_25 ;
while ( 1 ) {
V_25 = F_49 ( V_2 , 1 ) ;
if ( V_25 || F_65 ( V_30 ) )
return;
}
}
static void F_66 ( struct V_1 * V_2 )
{
F_67 ( V_2 -> V_5 ) ;
F_67 ( V_2 -> V_114 ) ;
F_67 ( V_2 -> V_131 ) ;
F_68 ( V_2 -> V_49 ) ;
F_68 ( V_2 -> V_128 ) ;
}
static int F_69 ( struct V_163 * V_30 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
F_70 ( V_2 -> V_6 ) ;
return 0 ;
}
static unsigned int F_71 ( struct V_92 * V_6 , T_5 V_164 )
{
T_1 V_26 ;
unsigned int V_165 ;
V_165 = 0 ;
if ( F_14 ( V_6 ) )
for ( V_26 = 0 ; V_26 < V_164 ; V_26 += V_6 -> V_7 )
if ( F_22 ( V_6 , V_26 ) )
V_165 ++ ;
return V_165 ;
}
static int F_72 ( struct V_163 * V_30 ,
unsigned long V_107 , char * V_115 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
unsigned int V_125 , V_166 ;
struct V_3 * V_4 ;
int V_25 ;
V_2 -> V_167 ++ ;
if ( V_2 -> V_27 < V_135 )
return - V_112 ;
if ( V_168 ) {
if ( F_73 ( V_107 == 0 ) )
return 0 ;
V_107 -- ;
}
V_166 = V_2 -> V_131 [ V_107 ] ;
if ( V_166 <= V_169 ) {
V_4 = V_2 -> V_5 + ( V_166 / V_2 -> V_82 ) ;
V_4 -> V_80 -- ;
F_33 ( V_2 , V_4 ) ;
V_2 -> V_131 [ V_107 ] = V_170 ;
V_2 -> V_114 [ V_166 ] = V_120 ;
}
V_25 = F_48 ( V_2 , V_115 , V_107 , & V_125 , 0 ) ;
V_2 -> V_171 ++ ;
if ( V_25 < 0 )
return V_25 ;
V_4 = V_2 -> V_5 + ( V_125 / V_2 -> V_82 ) ;
V_2 -> V_131 [ V_107 ] = V_125 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , char * V_115 )
{
union V_172 * V_173 = (union V_172 * ) ( V_115 ) ;
memset ( V_115 , 0 , V_122 - 10 ) ;
V_173 -> V_174 . V_175 = 1 ;
V_173 -> V_174 . V_176 = V_2 -> V_177 -> V_164 - 1 ;
V_173 -> V_174 . V_178 = 0 ;
memcpy ( V_115 + V_122 - 10 , L_18 , 10 ) ;
return 0 ;
}
static int F_75 ( struct V_163 * V_30 ,
unsigned long V_107 , char * V_115 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
struct V_92 * V_6 = V_2 -> V_6 ;
unsigned int V_179 , V_95 ;
T_1 V_127 ;
struct V_3 * V_4 ;
T_4 V_118 ;
int V_25 ;
V_2 -> V_180 ++ ;
if ( V_168 ) {
if ( F_73 ( V_107 == 0 ) )
return F_74 ( V_2 , V_115 ) ;
V_107 -- ;
}
V_179 = V_2 -> V_131 [ V_107 ] ;
if ( V_179 > V_169 ) {
memset ( V_115 , 0x0 , V_122 ) ;
if ( V_179 == V_170 )
return 0 ;
else
return - V_41 ;
}
V_4 = V_2 -> V_5 + ( V_179 / V_2 -> V_82 ) ;
F_76 ( V_2 -> V_114 [ V_179 ] == V_120 ) ;
V_127 = ( T_1 ) V_179 << V_121 ;
V_95 = 0 ;
V_96:
V_25 = F_52 ( V_6 , V_127 , V_122 , & V_118 , V_115 ) ;
V_2 -> V_181 ++ ;
if ( F_20 ( V_25 ) ) {
V_4 -> V_28 |= V_83 ;
F_9 ( V_2 , V_4 , V_84 ) ;
V_25 = 0 ;
}
if ( V_25 < 0 ) {
F_40 ( V_2 -> V_30 , L_19 , V_25 ) ;
V_4 -> V_28 |= V_73 ;
F_9 ( V_2 , V_4 , V_35 ) ;
V_95 ++ ;
if ( V_95 < V_129 )
goto V_96;
return V_25 ;
}
if ( V_118 != V_122 ) {
F_40 ( V_2 -> V_30 , L_20 , V_118 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_77 ( struct V_163 * V_30 , unsigned long V_182 ,
unsigned V_183 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
unsigned long V_107 ;
struct V_3 * V_4 ;
unsigned int V_166 ;
V_2 -> V_184 ++ ;
for ( V_107 = V_182 ; V_107 < V_182 + V_183 ; V_107 ++ ) {
V_166 = V_2 -> V_131 [ V_107 ] ;
if ( V_166 <= V_169 ) {
V_4 = V_2 -> V_5 + ( V_166 / V_2 -> V_82 ) ;
V_4 -> V_80 -- ;
F_33 ( V_2 , V_4 ) ;
V_2 -> V_131 [ V_107 ] = V_170 ;
V_2 -> V_114 [ V_166 ] = V_120 ;
V_2 -> V_185 ++ ;
} else if ( V_166 == V_132 ) {
V_2 -> V_131 [ V_107 ] = V_170 ;
V_2 -> V_185 ++ ;
}
}
return 0 ;
}
static int F_78 ( struct V_186 * V_187 , void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_187 -> V_188 ;
unsigned long V_189 ;
unsigned int V_13 [ V_190 ] ;
unsigned int V_191 [ V_190 ] ;
unsigned int V_150 [ V_190 ] ;
unsigned int V_24 , V_192 = 0 , V_193 = 0 , V_194 = 0 , V_195 , V_166 , V_196 ;
T_5 V_197 ;
char * V_102 [] = { L_21 , L_22 , L_23 , L_24 , L_25 , L_26 ,
L_27 } ;
F_79 ( & V_2 -> V_177 -> V_198 ) ;
for ( V_24 = 0 ; V_24 < V_190 ; V_24 ++ ) {
struct V_15 * V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 ) {
V_13 [ V_24 ] = V_2 -> V_12 [ V_24 ] . V_13 ;
V_191 [ V_24 ] = F_6 ( F_11 ( V_11 ) , struct V_3 ,
V_14 ) -> V_20 ;
V_150 [ V_24 ] = F_6 ( F_80 ( V_11 ) , struct V_3 ,
V_14 ) -> V_20 ;
} else
V_13 [ V_24 ] = 0 ;
}
if ( V_2 -> V_33 ) {
V_192 = 1 ;
V_193 = V_2 -> V_34 ;
V_194 = V_2 -> V_33 -> V_20 ;
}
V_189 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_72 ; V_24 ++ )
V_189 += V_2 -> V_5 [ V_24 ] . V_20 ;
V_197 = ( T_5 ) V_2 -> V_72 * V_2 -> V_6 -> V_7 ;
V_195 = F_71 ( V_2 -> V_6 , V_197 ) ;
V_166 = 0 ;
V_196 = V_2 -> V_177 -> V_164 ;
for ( V_24 = 0 ; V_24 < V_196 ; V_24 ++ )
if ( V_2 -> V_131 [ V_24 ] != V_170 )
V_166 ++ ;
F_81 ( & V_2 -> V_177 -> V_198 ) ;
for ( V_24 = 0 ; V_24 < V_190 ; V_24 ++ ) {
if ( ! V_13 [ V_24 ] )
continue;
if ( V_191 [ V_24 ] != V_150 [ V_24 ] )
F_82 ( V_187 , L_28
L_29 ,
V_102 [ V_24 ] , V_13 [ V_24 ] , V_191 [ V_24 ] , V_150 [ V_24 ] ) ;
else
F_82 ( V_187 , L_30
L_31 , V_102 [ V_24 ] , V_13 [ V_24 ] , V_191 [ V_24 ] ) ;
}
if ( V_195 )
F_82 ( V_187 , L_32 , V_195 ) ;
if ( V_192 )
F_82 ( V_187 , L_33
L_34 ,
V_193 , V_2 -> V_82 - V_193 , V_194 ) ;
F_82 ( V_187 , L_35 , V_189 ) ;
F_83 ( V_187 , L_36 ) ;
F_82 ( V_187 , L_37 , V_2 -> V_180 ) ;
F_82 ( V_187 , L_38 , V_2 -> V_167 ) ;
F_82 ( V_187 , L_39 , V_2 -> V_184 ) ;
F_82 ( V_187 , L_40 , V_2 -> V_181 ) ;
F_82 ( V_187 , L_41 , V_2 -> V_171 ) ;
F_82 ( V_187 , L_42 , V_2 -> V_185 ) ;
F_83 ( V_187 , L_36 ) ;
F_82 ( V_187 , L_43 , V_196 ) ;
F_82 ( V_187 , L_44 , V_166 ) ;
return 0 ;
}
static int F_84 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_85 ( V_200 , F_78 , V_199 -> V_201 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_202 * V_203 = V_2 -> V_177 -> V_204 ;
struct V_205 * V_30 = F_87 ( V_203 ) ;
struct V_206 * V_11 ;
struct V_206 * V_207 ;
V_11 = F_88 ( V_203 -> V_208 , NULL ) ;
if ( F_89 ( V_11 ) )
return 0 ;
if ( ! V_11 ) {
F_40 ( V_30 , L_45 ) ;
return - 1 ;
}
V_2 -> V_209 = V_11 ;
V_207 = F_90 ( L_46 , V_210 , V_11 , V_2 ,
& V_211 ) ;
if ( ! V_207 ) {
F_40 ( V_2 -> V_30 , L_47 ) ;
F_91 ( V_11 ) ;
V_2 -> V_209 = NULL ;
return - 1 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , unsigned int V_212 ,
unsigned int V_213 )
{
struct V_92 * V_6 = V_2 -> V_177 -> V_6 ;
unsigned int V_24 , V_214 , V_196 , V_215 ;
int V_25 = - V_216 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_72 = V_212 ;
V_2 -> V_27 = V_213 ;
V_2 -> V_82 = V_6 -> V_7 >> V_121 ;
V_196 = V_2 -> V_177 -> V_164 ;
V_215 = V_212 * V_2 -> V_82 ;
for ( V_24 = 0 ; V_24 < V_190 ; V_24 ++ )
V_2 -> V_12 [ V_24 ] . V_11 = V_68 ;
V_2 -> V_131 = F_93 ( sizeof( int ) * V_196 ) ;
if ( ! V_2 -> V_131 )
goto V_217;
V_2 -> V_114 = F_93 ( sizeof( int ) * V_215 ) ;
if ( ! V_2 -> V_114 )
goto V_218;
V_214 = sizeof( struct V_3 ) * V_2 -> V_72 ;
V_2 -> V_5 = F_94 ( V_214 ) ;
if ( ! V_2 -> V_5 )
goto V_219;
for ( V_24 = 0 ; V_24 < V_196 ; V_24 ++ )
V_2 -> V_131 [ V_24 ] = V_170 ;
for ( V_24 = 0 ; V_24 < V_215 ; V_24 ++ )
V_2 -> V_114 [ V_24 ] = V_120 ;
V_2 -> V_128 = F_95 ( V_122 , V_220 ) ;
if ( ! V_2 -> V_128 )
goto V_221;
V_2 -> V_49 = F_95 ( 2 * V_6 -> V_46 -> V_47 , V_220 ) ;
if ( ! V_2 -> V_49 )
goto V_222;
F_32 ( V_2 ) ;
return 0 ;
V_222:
F_68 ( V_2 -> V_128 ) ;
V_221:
F_67 ( V_2 -> V_5 ) ;
V_219:
F_67 ( V_2 -> V_114 ) ;
V_218:
F_67 ( V_2 -> V_131 ) ;
V_217:
F_96 ( V_223 L_48 , V_224 , V_25 ) ;
return V_25 ;
}
static void F_97 ( struct V_225 * V_226 , struct V_92 * V_6 )
{
struct V_1 * V_2 ;
struct V_163 * V_177 ;
char * V_227 ;
char * V_228 ;
unsigned long V_229 ;
unsigned int V_212 , V_230 , V_231 , V_213 ;
T_5 V_232 , V_197 , V_233 ;
struct V_234 * V_235 ;
int V_25 ;
V_227 = & V_236 [ 0 ] ;
if ( ! * V_227 )
return;
while ( ( V_228 = F_98 ( & V_227 , L_49 ) ) != NULL ) {
if ( F_99 ( V_228 , 0 , & V_229 ) < 0 )
return;
if ( V_6 -> V_237 == V_229 )
break;
}
if ( V_6 -> V_237 != V_229 )
return;
if ( V_6 -> V_7 < V_122 || V_6 -> V_7 % V_122 ) {
F_96 ( V_223 L_50
L_51 , V_224 , V_6 -> V_7 , V_122 ) ;
return;
}
if ( V_122 % V_6 -> V_66 || V_6 -> V_66 > V_122 ) {
F_96 ( V_223 L_52
L_53 , V_224 , V_122 , V_6 -> V_66 ) ;
return;
}
V_235 = V_6 -> V_46 ;
if ( ! V_235 ) {
F_96 ( V_223 L_54 ,
V_224 , V_6 -> V_237 ) ;
return;
}
if ( ! V_6 -> V_238 || V_235 -> V_47 < V_65 ) {
F_96 ( V_223 L_55
L_56 ,
V_224 , V_235 -> V_47 , V_65 ) ;
return;
}
if ( V_239 > 100 )
V_239 = 100 ;
V_197 = V_6 -> V_164 ;
V_233 = ( T_5 ) V_169 * V_122 ;
if ( V_6 -> V_164 > V_233 ) {
F_96 ( V_240 L_57
L_58 , V_224 , V_233 ) ;
V_197 = V_233 ;
}
V_212 = F_100 ( V_197 , V_6 ) ;
V_197 = ( T_5 ) V_212 * V_6 -> V_7 ;
V_231 = F_71 ( V_6 , V_197 ) ;
V_230 = V_212 - V_231 ;
if ( V_230 < V_241 ) {
F_96 ( V_223 L_59
L_60 , V_224 , V_230 ,
V_241 ) ;
return;
}
V_213 = F_101 ( ( T_5 ) V_230 * V_239 , 100 ) ;
if ( V_213 < V_135 )
V_213 = V_135 ;
if ( V_213 > V_230 - 1 )
V_213 = V_230 - 1 ;
V_232 = ( T_5 ) ( V_230 - V_213 ) * V_6 -> V_7 +
( V_168 ? V_122 : 0 ) ;
F_96 ( V_242 L_61
L_62 ,
V_224 , V_229 , V_232 / 1024 , V_213 , V_231 ) ;
V_2 = F_102 ( sizeof( struct V_1 ) , V_220 ) ;
if ( ! V_2 )
return;
V_177 = F_102 ( sizeof( struct V_163 ) , V_220 ) ;
if ( ! V_177 ) {
F_68 ( V_2 ) ;
return;
}
V_2 -> V_177 = V_177 ;
V_177 -> V_91 = V_2 ;
V_177 -> V_6 = V_6 ;
V_177 -> V_243 = V_6 -> V_237 ;
V_177 -> V_164 = V_232 >> V_121 ;
V_177 -> V_226 = V_226 ;
if ( ! ( V_6 -> V_28 & V_244 ) )
V_177 -> V_245 = 1 ;
if ( F_92 ( V_2 , V_212 , V_213 ) < 0 )
goto V_246;
if ( F_103 ( V_177 ) < 0 )
goto V_247;
V_2 -> V_30 = F_87 ( V_177 -> V_204 ) ;
V_25 = F_86 ( V_2 ) ;
if ( V_25 < 0 )
goto V_248;
return;
V_248:
F_104 ( V_177 ) ;
V_247:
F_66 ( V_2 ) ;
V_246:
F_68 ( V_177 ) ;
F_68 ( V_2 ) ;
}
static void F_105 ( struct V_163 * V_30 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
F_91 ( V_2 -> V_209 ) ;
F_104 ( V_30 ) ;
F_66 ( V_2 ) ;
F_68 ( V_2 ) ;
}
static int T_6 F_106 ( void )
{
return F_107 ( & V_249 ) ;
}
static void T_7 F_108 ( void )
{
F_109 ( & V_249 ) ;
}
