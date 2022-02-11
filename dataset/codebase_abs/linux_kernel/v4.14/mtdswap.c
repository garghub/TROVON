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
V_38 . V_40 = 2 * V_2 -> V_6 -> V_46 ;
V_38 . V_47 = V_2 -> V_48 ;
V_38 . V_49 = 0 ;
V_38 . V_50 = NULL ;
V_38 . V_51 = V_52 ;
V_25 = F_18 ( V_2 , V_26 , & V_38 ) ;
if ( V_25 && ! F_20 ( V_25 ) )
return V_25 ;
V_43 = (struct V_42 * ) V_2 -> V_48 ;
V_44 = (struct V_42 * )
( V_2 -> V_48 + V_2 -> V_6 -> V_46 ) ;
if ( F_23 ( V_43 -> V_53 ) == V_54 ) {
V_4 -> V_20 = F_24 ( V_43 -> V_13 ) ;
if ( F_20 ( V_25 ) )
V_25 = V_55 ;
else {
if ( F_23 ( V_44 -> V_53 ) == V_56 )
V_25 = V_57 ;
else
V_25 = V_58 ;
}
} else {
V_4 -> V_28 |= V_59 ;
V_25 = V_57 ;
}
return V_25 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_60 )
{
struct V_42 V_61 ;
int V_25 ;
T_1 V_26 ;
struct V_37 V_38 ;
V_38 . V_49 = 0 ;
V_38 . V_47 = ( V_62 * ) & V_61 ;
V_38 . V_51 = V_52 ;
V_38 . V_50 = NULL ;
if ( V_60 == V_63 ) {
V_61 . V_53 = F_26 ( V_54 ) ;
V_61 . V_13 = F_27 ( V_4 -> V_20 ) ;
V_38 . V_40 = V_64 ;
V_26 = F_1 ( V_2 , V_4 ) ;
} else {
V_61 . V_53 = F_26 ( V_56 ) ;
V_38 . V_40 = sizeof( V_61 . V_53 ) ;
V_26 = F_1 ( V_2 , V_4 ) + V_2 -> V_6 -> V_65 ;
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
struct V_15 V_66 = V_67 ;
struct V_16 * V_68 ;
struct V_3 * V_4 ;
unsigned int V_24 , V_69 , V_70 ;
V_69 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_71 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_59 | V_29 | V_72 ) )
continue;
F_5 ( & V_66 , V_4 ) ;
V_69 ++ ;
}
if ( V_69 == 0 )
return;
V_68 = F_10 ( & V_66 , V_69 / 2 ) ;
V_70 = F_6 ( V_68 , struct V_3 , V_14 ) -> V_20 ;
V_2 -> V_73 = F_31 ( & V_66 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_71 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & ( V_59 | V_72 ) )
V_4 -> V_20 = V_70 ;
if ( V_4 -> V_28 & ( V_59 | V_29 | V_72 ) )
continue;
F_4 ( & V_4 -> V_14 , & V_66 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
int V_74 ;
unsigned int V_24 , V_23 ;
struct V_3 * V_4 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_71 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
V_74 = F_21 ( V_2 , V_4 ) ;
if ( V_74 < 0 )
V_4 -> V_28 |= V_72 ;
else if ( V_74 == V_45 ) {
V_4 -> V_28 |= V_29 ;
continue;
}
switch ( V_74 ) {
case V_58 :
V_23 = V_75 ;
break;
case V_57 :
case V_55 :
V_23 = V_76 ;
break;
default:
V_23 = V_35 ;
}
V_4 -> V_28 |= ( V_23 << V_77 ) ;
}
F_30 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_71 ; V_24 ++ ) {
V_4 = V_2 -> V_5 + V_24 ;
if ( V_4 -> V_28 & V_29 )
continue;
V_23 = V_4 -> V_28 >> V_77 ;
F_9 ( V_2 , V_4 , V_23 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_78 = V_4 -> V_79 ;
unsigned int V_80 = V_2 -> V_81 ;
if ( V_4 == V_2 -> V_33 )
return;
if ( V_4 -> V_28 & V_82 )
F_9 ( V_2 , V_4 , V_83 ) ;
else if ( V_4 -> V_28 & ( V_72 | V_32 ) )
F_9 ( V_2 , V_4 , V_35 ) ;
if ( V_78 == V_80 )
F_9 ( V_2 , V_4 , V_84 ) ;
else if ( V_78 == 0 )
F_9 ( V_2 , V_4 , V_76 ) ;
else if ( V_78 > ( V_80 / 2 ) )
F_9 ( V_2 , V_4 , V_85 ) ;
else
F_9 ( V_2 , V_4 , V_86 ) ;
}
static void F_34 ( struct V_87 * V_88 )
{
T_3 * V_89 = ( T_3 * ) V_88 -> V_90 ;
F_35 ( V_89 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_91 * V_6 = V_2 -> V_6 ;
struct V_87 V_92 ;
T_3 V_93 ;
unsigned int V_94 = 0 ;
int V_25 ;
V_4 -> V_20 ++ ;
if ( V_4 -> V_20 > V_2 -> V_73 )
V_2 -> V_73 = V_4 -> V_20 ;
V_95:
F_37 ( & V_93 ) ;
memset ( & V_92 , 0 , sizeof( struct V_87 ) ) ;
V_92 . V_6 = V_6 ;
V_92 . V_96 = F_34 ;
V_92 . V_97 = F_1 ( V_2 , V_4 ) ;
V_92 . V_98 = V_6 -> V_7 ;
V_92 . V_90 = ( V_99 ) & V_93 ;
V_25 = F_38 ( V_6 , & V_92 ) ;
if ( V_25 ) {
if ( V_94 ++ < V_100 ) {
F_15 ( V_2 -> V_30 ,
L_10 ,
V_92 . V_97 , V_6 -> V_101 ) ;
F_39 () ;
goto V_95;
}
F_40 ( V_2 -> V_30 , L_11 ,
V_92 . V_97 , V_6 -> V_101 ) ;
F_13 ( V_2 , V_4 ) ;
return - V_41 ;
}
V_25 = F_41 ( V_93 , V_92 . V_102 == V_103 ||
V_92 . V_102 == V_104 ) ;
if ( V_25 ) {
F_40 ( V_2 -> V_30 , L_12 ,
V_92 . V_97 , V_6 -> V_101 ) ;
return - V_105 ;
}
if ( V_92 . V_102 == V_104 ) {
if ( V_94 ++ < V_100 ) {
F_15 ( V_2 -> V_30 ,
L_10 ,
V_92 . V_97 , V_6 -> V_101 ) ;
F_39 () ;
goto V_95;
}
F_13 ( V_2 , V_4 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_106 ,
unsigned int * V_107 )
{
int V_25 ;
struct V_3 * V_108 = V_2 -> V_33 ;
struct V_15 * V_109 ;
struct V_3 * V_4 ;
if ( V_108 == NULL || V_2 -> V_34 >= V_2 -> V_81 ) {
do {
if ( F_43 ( V_2 , V_110 ) )
return - V_111 ;
V_109 = F_44 ( V_2 , V_110 ) ;
V_4 = F_6 ( F_11 ( V_109 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_109 ) ;
V_4 -> V_11 = NULL ;
F_45 ( V_2 , V_110 ) -- ;
V_25 = F_25 ( V_2 , V_4 , V_112 ) ;
} while ( V_25 == - V_41 || F_29 ( V_25 ) );
if ( V_25 )
return V_25 ;
V_2 -> V_34 = 0 ;
V_2 -> V_33 = V_4 ;
if ( V_108 )
F_33 ( V_2 , V_108 ) ;
}
* V_107 = ( V_2 -> V_33 - V_2 -> V_5 ) * V_2 -> V_81 +
V_2 -> V_34 ;
V_2 -> V_33 -> V_79 ++ ;
V_2 -> V_113 [ * V_107 ] = V_106 ;
V_2 -> V_34 ++ ;
return 0 ;
}
static unsigned int F_46 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_110 ) * V_2 -> V_81 +
V_2 -> V_81 - V_2 -> V_34 ;
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) > V_2 -> V_81 ;
}
static int F_48 ( struct V_1 * V_2 , char * V_114 ,
unsigned int V_106 , unsigned int * V_115 , int V_116 )
{
struct V_91 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
T_4 V_117 ;
T_1 V_118 ;
int V_25 ;
V_95:
if ( ! V_116 )
while ( ! F_47 ( V_2 ) )
if ( F_49 ( V_2 , 0 ) > 0 )
return - V_111 ;
V_25 = F_42 ( V_2 , V_106 , V_115 ) ;
V_4 = V_2 -> V_5 + ( * V_115 / V_2 -> V_81 ) ;
if ( V_25 == - V_41 || F_29 ( V_25 ) ) {
V_2 -> V_33 = NULL ;
V_4 -> V_79 -- ;
V_2 -> V_113 [ * V_115 ] = V_119 ;
goto V_95;
}
if ( V_25 < 0 )
return V_25 ;
V_118 = ( T_1 ) * V_115 << V_120 ;
V_25 = F_50 ( V_6 , V_118 , V_121 , & V_117 , V_114 ) ;
if ( V_25 == - V_41 || F_29 ( V_25 ) ) {
V_2 -> V_34 -- ;
V_4 -> V_79 -- ;
V_2 -> V_113 [ * V_115 ] = V_119 ;
F_17 ( V_2 , V_4 ) ;
goto V_95;
}
if ( V_25 < 0 ) {
F_40 ( V_2 -> V_30 , L_13 ,
V_25 , V_117 ) ;
goto V_122;
}
if ( V_117 != V_121 ) {
F_40 ( V_2 -> V_30 , L_14 ,
V_117 ) ;
V_25 = - V_41 ;
goto V_122;
}
return V_25 ;
V_122:
V_2 -> V_34 -- ;
V_4 -> V_79 -- ;
V_2 -> V_113 [ * V_115 ] = V_119 ;
return V_25 ;
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_123 ,
unsigned int * V_124 )
{
struct V_91 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 , * V_125 ;
int V_25 ;
T_4 V_117 ;
unsigned int V_106 , V_94 ;
T_1 V_126 ;
V_106 = V_2 -> V_113 [ V_123 ] ;
V_126 = ( T_1 ) V_123 << V_120 ;
V_94 = 0 ;
V_95:
V_25 = F_52 ( V_6 , V_126 , V_121 , & V_117 , V_2 -> V_127 ) ;
if ( V_25 < 0 && ! F_20 ( V_25 ) ) {
V_125 = V_2 -> V_5 + V_123 / V_2 -> V_81 ;
V_125 -> V_28 |= V_72 ;
F_40 ( V_2 -> V_30 , L_15 , V_25 ,
V_123 ) ;
V_94 ++ ;
if ( V_94 < V_128 )
goto V_95;
goto V_129;
}
if ( V_117 != V_121 ) {
F_40 ( V_2 -> V_30 , L_16 , V_117 ,
V_123 ) ;
V_25 = - V_41 ;
goto V_129;
}
V_25 = F_48 ( V_2 , V_2 -> V_127 , V_106 , V_124 , 1 ) ;
if ( V_25 < 0 ) {
V_2 -> V_130 [ V_106 ] = V_131 ;
F_40 ( V_2 -> V_30 , L_17 , V_25 ) ;
return V_25 ;
}
V_4 = V_2 -> V_5 + * V_124 / V_2 -> V_81 ;
V_2 -> V_130 [ V_106 ] = * V_124 ;
V_2 -> V_113 [ V_123 ] = V_119 ;
V_4 = V_2 -> V_5 + V_123 / V_2 -> V_81 ;
V_4 -> V_79 -- ;
return 0 ;
V_129:
V_2 -> V_130 [ V_106 ] = V_131 ;
V_2 -> V_113 [ V_123 ] = V_119 ;
return V_25 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_24 , V_107 , V_132 , V_124 ;
int V_25 , V_133 ;
V_133 = 0 ;
V_132 = ( V_4 - V_2 -> V_5 ) * V_2 -> V_81 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_81 ; V_24 ++ ) {
if ( V_2 -> V_27 < V_134 )
return - V_111 ;
V_107 = V_132 + V_24 ;
if ( V_2 -> V_113 [ V_107 ] == V_119 )
continue;
V_25 = F_51 ( V_2 , V_107 , & V_124 ) ;
if ( V_25 < 0 && ! V_133 )
V_133 = V_25 ;
}
return V_133 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_23 , V_135 ;
if ( F_45 ( V_2 , V_110 ) < V_136 )
V_135 = V_85 ;
else
V_135 = V_86 ;
for ( V_23 = V_83 ; V_23 >= V_135 ; V_23 -- )
if ( V_2 -> V_12 [ V_23 ] . V_11 . V_16 != NULL )
return V_23 ;
return - 1 ;
}
static int F_55 ( unsigned int V_137 )
{
unsigned int V_138 , V_139 , V_140 , V_141 , V_142 ;
V_141 = V_137 - V_143 ;
if ( V_141 > V_144 )
V_141 = V_144 ;
V_138 = V_145 - V_146 ;
V_142 = V_144 ;
V_139 = V_141 - V_142 ;
V_140 = ( V_139 * V_138 + V_142 / 2 ) / V_142 ;
return V_146 + V_140 ;
}
static int F_56 ( struct V_1 * V_2 )
{
static unsigned int V_147 ;
unsigned int V_24 , V_23 = - 1 , V_148 , V_149 ;
struct V_15 * V_11 ;
V_149 = 0 ;
for ( V_24 = 0 ; V_24 <= V_76 ; V_24 ++ ) {
V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 == NULL )
continue;
V_148 = V_2 -> V_73 - F_57 ( V_11 ) ;
if ( V_148 > V_149 ) {
V_149 = V_148 ;
V_23 = V_24 ;
}
}
if ( V_149 > V_143 && V_147 >= F_55 ( V_149 ) - 1 ) {
V_147 = 0 ;
return V_23 ;
}
V_147 ++ ;
return - 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned int V_150 )
{
int V_23 ;
if ( F_59 ( V_2 , V_151 ) &&
( V_150 || ( F_43 ( V_2 , V_110 ) && F_43 ( V_2 , V_152 ) ) ) )
return V_35 ;
V_23 = F_56 ( V_2 ) ;
if ( V_23 >= V_75 )
return V_23 ;
return F_54 ( V_2 ) ;
}
static struct V_3 * F_60 ( struct V_1 * V_2 ,
unsigned int V_150 )
{
struct V_15 * V_153 = NULL ;
struct V_3 * V_4 = NULL ;
int V_23 ;
if ( V_150 && F_45 ( V_2 , V_110 ) > V_154 &&
F_43 ( V_2 , V_152 ) && F_43 ( V_2 , V_151 ) )
return NULL ;
V_23 = F_58 ( V_2 , V_150 ) ;
if ( V_23 < 0 )
return NULL ;
V_153 = & V_2 -> V_12 [ V_23 ] . V_11 ;
V_4 = F_6 ( F_11 ( V_153 ) , struct V_3 , V_14 ) ;
F_4 ( & V_4 -> V_14 , V_153 ) ;
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
struct V_91 * V_6 = V_2 -> V_6 ;
unsigned int V_155 , V_24 , V_156 , V_157 , V_158 ;
T_1 V_142 , V_159 ;
unsigned int * V_160 = ( unsigned int * ) V_2 -> V_127 ;
unsigned char * V_161 = ( unsigned char * ) V_2 -> V_48 ;
struct V_37 V_38 ;
int V_25 ;
V_38 . V_51 = V_52 ;
V_38 . V_98 = V_6 -> V_65 ;
V_38 . V_40 = V_6 -> V_46 ;
V_38 . V_49 = 0 ;
V_38 . V_50 = V_2 -> V_127 ;
V_38 . V_47 = V_2 -> V_48 ;
V_142 = F_1 ( V_2 , V_4 ) ;
V_158 = V_2 -> V_81 * V_121 / V_6 -> V_65 ;
for ( V_155 = 0 ; V_155 < 2 ; V_155 ++ ) {
V_159 = V_142 ;
for ( V_24 = 0 ; V_24 < V_158 ; V_24 ++ ) {
V_157 = F_61 ( V_155 + V_24 ) ;
memset ( V_2 -> V_127 , V_157 , V_6 -> V_65 ) ;
memset ( V_2 -> V_48 , V_157 , V_6 -> V_46 ) ;
V_25 = F_28 ( V_6 , V_159 , & V_38 ) ;
if ( V_25 )
goto error;
V_159 += V_6 -> V_65 ;
}
V_159 = V_142 ;
for ( V_24 = 0 ; V_24 < V_158 ; V_24 ++ ) {
V_25 = F_19 ( V_6 , V_159 , & V_38 ) ;
if ( V_25 )
goto error;
V_157 = F_61 ( V_155 + V_24 ) ;
for ( V_156 = 0 ; V_156 < V_6 -> V_65 / sizeof( int ) ; V_156 ++ )
if ( V_160 [ V_156 ] != V_157 )
goto error;
for ( V_156 = 0 ; V_156 < V_6 -> V_46 ; V_156 ++ )
if ( V_161 [ V_156 ] != ( unsigned char ) V_157 )
goto error;
V_159 += V_6 -> V_65 ;
}
V_25 = F_36 ( V_2 , V_4 ) ;
if ( V_25 )
goto error;
}
V_4 -> V_28 &= ~ V_72 ;
return 1 ;
error:
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , unsigned int V_150 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( V_2 -> V_27 < V_134 )
return 1 ;
V_4 = F_60 ( V_2 , V_150 ) ;
if ( ! V_4 )
return 1 ;
V_25 = F_53 ( V_2 , V_4 ) ;
if ( V_25 == - V_111 )
return 1 ;
if ( V_4 -> V_28 & V_32 ) {
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
V_4 -> V_28 &= ~ V_82 ;
V_25 = F_36 ( V_2 , V_4 ) ;
if ( ( V_4 -> V_28 & V_72 ) &&
( V_25 || ! F_62 ( V_2 , V_4 ) ) )
return 0 ;
if ( V_25 == 0 )
V_25 = F_25 ( V_2 , V_4 , V_63 ) ;
if ( V_25 == 0 )
F_9 ( V_2 , V_4 , V_75 ) ;
else if ( V_25 != - V_41 && ! F_29 ( V_25 ) )
F_9 ( V_2 , V_4 , V_76 ) ;
return 0 ;
}
static void F_63 ( struct V_162 * V_30 )
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
F_67 ( V_2 -> V_113 ) ;
F_67 ( V_2 -> V_130 ) ;
F_68 ( V_2 -> V_48 ) ;
F_68 ( V_2 -> V_127 ) ;
}
static int F_69 ( struct V_162 * V_30 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
F_70 ( V_2 -> V_6 ) ;
return 0 ;
}
static unsigned int F_71 ( struct V_91 * V_6 , T_5 V_163 )
{
T_1 V_26 ;
unsigned int V_164 ;
V_164 = 0 ;
if ( F_14 ( V_6 ) )
for ( V_26 = 0 ; V_26 < V_163 ; V_26 += V_6 -> V_7 )
if ( F_22 ( V_6 , V_26 ) )
V_164 ++ ;
return V_164 ;
}
static int F_72 ( struct V_162 * V_30 ,
unsigned long V_106 , char * V_114 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
unsigned int V_124 , V_165 ;
struct V_3 * V_4 ;
int V_25 ;
V_2 -> V_166 ++ ;
if ( V_2 -> V_27 < V_134 )
return - V_111 ;
if ( V_167 ) {
if ( F_73 ( V_106 == 0 ) )
return 0 ;
V_106 -- ;
}
V_165 = V_2 -> V_130 [ V_106 ] ;
if ( V_165 <= V_168 ) {
V_4 = V_2 -> V_5 + ( V_165 / V_2 -> V_81 ) ;
V_4 -> V_79 -- ;
F_33 ( V_2 , V_4 ) ;
V_2 -> V_130 [ V_106 ] = V_169 ;
V_2 -> V_113 [ V_165 ] = V_119 ;
}
V_25 = F_48 ( V_2 , V_114 , V_106 , & V_124 , 0 ) ;
V_2 -> V_170 ++ ;
if ( V_25 < 0 )
return V_25 ;
V_4 = V_2 -> V_5 + ( V_124 / V_2 -> V_81 ) ;
V_2 -> V_130 [ V_106 ] = V_124 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , char * V_114 )
{
union V_171 * V_172 = (union V_171 * ) ( V_114 ) ;
memset ( V_114 , 0 , V_121 - 10 ) ;
V_172 -> V_173 . V_174 = 1 ;
V_172 -> V_173 . V_175 = V_2 -> V_176 -> V_163 - 1 ;
V_172 -> V_173 . V_177 = 0 ;
memcpy ( V_114 + V_121 - 10 , L_18 , 10 ) ;
return 0 ;
}
static int F_75 ( struct V_162 * V_30 ,
unsigned long V_106 , char * V_114 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
struct V_91 * V_6 = V_2 -> V_6 ;
unsigned int V_178 , V_94 ;
T_1 V_126 ;
struct V_3 * V_4 ;
T_4 V_117 ;
int V_25 ;
V_2 -> V_179 ++ ;
if ( V_167 ) {
if ( F_73 ( V_106 == 0 ) )
return F_74 ( V_2 , V_114 ) ;
V_106 -- ;
}
V_178 = V_2 -> V_130 [ V_106 ] ;
if ( V_178 > V_168 ) {
memset ( V_114 , 0x0 , V_121 ) ;
if ( V_178 == V_169 )
return 0 ;
else
return - V_41 ;
}
V_4 = V_2 -> V_5 + ( V_178 / V_2 -> V_81 ) ;
F_76 ( V_2 -> V_113 [ V_178 ] == V_119 ) ;
V_126 = ( T_1 ) V_178 << V_120 ;
V_94 = 0 ;
V_95:
V_25 = F_52 ( V_6 , V_126 , V_121 , & V_117 , V_114 ) ;
V_2 -> V_180 ++ ;
if ( F_20 ( V_25 ) ) {
V_4 -> V_28 |= V_82 ;
F_9 ( V_2 , V_4 , V_83 ) ;
V_25 = 0 ;
}
if ( V_25 < 0 ) {
F_40 ( V_2 -> V_30 , L_19 , V_25 ) ;
V_4 -> V_28 |= V_72 ;
F_9 ( V_2 , V_4 , V_35 ) ;
V_94 ++ ;
if ( V_94 < V_128 )
goto V_95;
return V_25 ;
}
if ( V_117 != V_121 ) {
F_40 ( V_2 -> V_30 , L_20 , V_117 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_77 ( struct V_162 * V_30 , unsigned long V_181 ,
unsigned V_182 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
unsigned long V_106 ;
struct V_3 * V_4 ;
unsigned int V_165 ;
V_2 -> V_183 ++ ;
for ( V_106 = V_181 ; V_106 < V_181 + V_182 ; V_106 ++ ) {
V_165 = V_2 -> V_130 [ V_106 ] ;
if ( V_165 <= V_168 ) {
V_4 = V_2 -> V_5 + ( V_165 / V_2 -> V_81 ) ;
V_4 -> V_79 -- ;
F_33 ( V_2 , V_4 ) ;
V_2 -> V_130 [ V_106 ] = V_169 ;
V_2 -> V_113 [ V_165 ] = V_119 ;
V_2 -> V_184 ++ ;
} else if ( V_165 == V_131 ) {
V_2 -> V_130 [ V_106 ] = V_169 ;
V_2 -> V_184 ++ ;
}
}
return 0 ;
}
static int F_78 ( struct V_185 * V_186 , void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 -> V_187 ;
unsigned long V_188 ;
unsigned int V_13 [ V_189 ] ;
unsigned int V_190 [ V_189 ] ;
unsigned int V_149 [ V_189 ] ;
unsigned int V_24 , V_191 = 0 , V_192 = 0 , V_193 = 0 , V_194 , V_165 , V_195 ;
T_5 V_196 ;
char * V_101 [] = { L_21 , L_22 , L_23 , L_24 , L_25 , L_26 ,
L_27 } ;
F_79 ( & V_2 -> V_176 -> V_197 ) ;
for ( V_24 = 0 ; V_24 < V_189 ; V_24 ++ ) {
struct V_15 * V_11 = & V_2 -> V_12 [ V_24 ] . V_11 ;
if ( V_11 -> V_16 ) {
V_13 [ V_24 ] = V_2 -> V_12 [ V_24 ] . V_13 ;
V_190 [ V_24 ] = F_57 ( V_11 ) ;
V_149 [ V_24 ] = F_31 ( V_11 ) ;
} else
V_13 [ V_24 ] = 0 ;
}
if ( V_2 -> V_33 ) {
V_191 = 1 ;
V_192 = V_2 -> V_34 ;
V_193 = V_2 -> V_33 -> V_20 ;
}
V_188 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_71 ; V_24 ++ )
V_188 += V_2 -> V_5 [ V_24 ] . V_20 ;
V_196 = ( T_5 ) V_2 -> V_71 * V_2 -> V_6 -> V_7 ;
V_194 = F_71 ( V_2 -> V_6 , V_196 ) ;
V_165 = 0 ;
V_195 = V_2 -> V_176 -> V_163 ;
for ( V_24 = 0 ; V_24 < V_195 ; V_24 ++ )
if ( V_2 -> V_130 [ V_24 ] != V_169 )
V_165 ++ ;
F_80 ( & V_2 -> V_176 -> V_197 ) ;
for ( V_24 = 0 ; V_24 < V_189 ; V_24 ++ ) {
if ( ! V_13 [ V_24 ] )
continue;
if ( V_190 [ V_24 ] != V_149 [ V_24 ] )
F_81 ( V_186 , L_28
L_29 ,
V_101 [ V_24 ] , V_13 [ V_24 ] , V_190 [ V_24 ] , V_149 [ V_24 ] ) ;
else
F_81 ( V_186 , L_30
L_31 , V_101 [ V_24 ] , V_13 [ V_24 ] , V_190 [ V_24 ] ) ;
}
if ( V_194 )
F_81 ( V_186 , L_32 , V_194 ) ;
if ( V_191 )
F_81 ( V_186 , L_33
L_34 ,
V_192 , V_2 -> V_81 - V_192 , V_193 ) ;
F_81 ( V_186 , L_35 , V_188 ) ;
F_82 ( V_186 , L_36 ) ;
F_81 ( V_186 , L_37 , V_2 -> V_179 ) ;
F_81 ( V_186 , L_38 , V_2 -> V_166 ) ;
F_81 ( V_186 , L_39 , V_2 -> V_183 ) ;
F_81 ( V_186 , L_40 , V_2 -> V_180 ) ;
F_81 ( V_186 , L_41 , V_2 -> V_170 ) ;
F_81 ( V_186 , L_42 , V_2 -> V_184 ) ;
F_82 ( V_186 , L_36 ) ;
F_81 ( V_186 , L_43 , V_195 ) ;
F_81 ( V_186 , L_44 , V_165 ) ;
return 0 ;
}
static int F_83 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
return F_84 ( V_199 , F_78 , V_198 -> V_200 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_201 * V_11 = V_2 -> V_6 -> V_202 . V_203 ;
struct V_201 * V_204 ;
if ( ! F_86 ( V_205 ) )
return 0 ;
if ( F_87 ( V_11 ) )
return - 1 ;
V_204 = F_88 ( L_45 , V_206 , V_11 , V_2 ,
& V_207 ) ;
if ( ! V_204 ) {
F_40 ( V_2 -> V_30 , L_46 ) ;
return - 1 ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , unsigned int V_208 ,
unsigned int V_209 )
{
struct V_91 * V_6 = V_2 -> V_176 -> V_6 ;
unsigned int V_24 , V_210 , V_195 , V_211 ;
int V_25 = - V_212 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_71 = V_208 ;
V_2 -> V_27 = V_209 ;
V_2 -> V_81 = V_6 -> V_7 >> V_120 ;
V_195 = V_2 -> V_176 -> V_163 ;
V_211 = V_208 * V_2 -> V_81 ;
for ( V_24 = 0 ; V_24 < V_189 ; V_24 ++ )
V_2 -> V_12 [ V_24 ] . V_11 = V_67 ;
V_2 -> V_130 = F_90 ( sizeof( int ) * V_195 ) ;
if ( ! V_2 -> V_130 )
goto V_213;
V_2 -> V_113 = F_90 ( sizeof( int ) * V_211 ) ;
if ( ! V_2 -> V_113 )
goto V_214;
V_210 = sizeof( struct V_3 ) * V_2 -> V_71 ;
V_2 -> V_5 = F_91 ( V_210 ) ;
if ( ! V_2 -> V_5 )
goto V_215;
for ( V_24 = 0 ; V_24 < V_195 ; V_24 ++ )
V_2 -> V_130 [ V_24 ] = V_169 ;
for ( V_24 = 0 ; V_24 < V_211 ; V_24 ++ )
V_2 -> V_113 [ V_24 ] = V_119 ;
V_2 -> V_127 = F_92 ( V_121 , V_216 ) ;
if ( ! V_2 -> V_127 )
goto V_217;
V_2 -> V_48 = F_92 ( 2 * V_6 -> V_46 , V_216 ) ;
if ( ! V_2 -> V_48 )
goto V_218;
F_32 ( V_2 ) ;
return 0 ;
V_218:
F_68 ( V_2 -> V_127 ) ;
V_217:
F_67 ( V_2 -> V_5 ) ;
V_215:
F_67 ( V_2 -> V_113 ) ;
V_214:
F_67 ( V_2 -> V_130 ) ;
V_213:
F_93 ( V_219 L_47 , V_220 , V_25 ) ;
return V_25 ;
}
static void F_94 ( struct V_221 * V_222 , struct V_91 * V_6 )
{
struct V_1 * V_2 ;
struct V_162 * V_176 ;
char * V_223 ;
char * V_224 ;
unsigned long V_225 ;
unsigned int V_208 , V_226 , V_227 , V_209 ;
T_5 V_228 , V_196 , V_229 ;
int V_25 ;
V_223 = & V_230 [ 0 ] ;
if ( ! * V_223 )
return;
while ( ( V_224 = F_95 ( & V_223 , L_48 ) ) != NULL ) {
if ( F_96 ( V_224 , 0 , & V_225 ) < 0 )
return;
if ( V_6 -> V_231 == V_225 )
break;
}
if ( V_6 -> V_231 != V_225 )
return;
if ( V_6 -> V_7 < V_121 || V_6 -> V_7 % V_121 ) {
F_93 ( V_219 L_49
L_50 , V_220 , V_6 -> V_7 , V_121 ) ;
return;
}
if ( V_121 % V_6 -> V_65 || V_6 -> V_65 > V_121 ) {
F_93 ( V_219 L_51
L_52 , V_220 , V_121 , V_6 -> V_65 ) ;
return;
}
if ( ! V_6 -> V_232 || V_6 -> V_46 < V_64 ) {
F_93 ( V_219 L_53
L_54 ,
V_220 , V_6 -> V_46 , V_64 ) ;
return;
}
if ( V_233 > 100 )
V_233 = 100 ;
V_196 = V_6 -> V_163 ;
V_229 = ( T_5 ) V_168 * V_121 ;
if ( V_6 -> V_163 > V_229 ) {
F_93 ( V_234 L_55
L_56 , V_220 , V_229 ) ;
V_196 = V_229 ;
}
V_208 = F_97 ( V_196 , V_6 ) ;
V_196 = ( T_5 ) V_208 * V_6 -> V_7 ;
V_227 = F_71 ( V_6 , V_196 ) ;
V_226 = V_208 - V_227 ;
if ( V_226 < V_235 ) {
F_93 ( V_219 L_57
L_58 , V_220 , V_226 ,
V_235 ) ;
return;
}
V_209 = F_98 ( ( T_5 ) V_226 * V_233 , 100 ) ;
if ( V_209 < V_134 )
V_209 = V_134 ;
if ( V_209 > V_226 - 1 )
V_209 = V_226 - 1 ;
V_228 = ( T_5 ) ( V_226 - V_209 ) * V_6 -> V_7 +
( V_167 ? V_121 : 0 ) ;
F_93 ( V_236 L_59
L_60 ,
V_220 , V_225 , V_228 / 1024 , V_209 , V_227 ) ;
V_2 = F_99 ( sizeof( struct V_1 ) , V_216 ) ;
if ( ! V_2 )
return;
V_176 = F_99 ( sizeof( struct V_162 ) , V_216 ) ;
if ( ! V_176 ) {
F_68 ( V_2 ) ;
return;
}
V_2 -> V_176 = V_176 ;
V_176 -> V_90 = V_2 ;
V_176 -> V_6 = V_6 ;
V_176 -> V_237 = V_6 -> V_231 ;
V_176 -> V_163 = V_228 >> V_120 ;
V_176 -> V_222 = V_222 ;
if ( ! ( V_6 -> V_28 & V_238 ) )
V_176 -> V_239 = 1 ;
if ( F_89 ( V_2 , V_208 , V_209 ) < 0 )
goto V_240;
if ( F_100 ( V_176 ) < 0 )
goto V_241;
V_2 -> V_30 = F_101 ( V_176 -> V_242 ) ;
V_25 = F_85 ( V_2 ) ;
if ( V_25 < 0 )
goto V_243;
return;
V_243:
F_102 ( V_176 ) ;
V_241:
F_66 ( V_2 ) ;
V_240:
F_68 ( V_176 ) ;
F_68 ( V_2 ) ;
}
static void F_103 ( struct V_162 * V_30 )
{
struct V_1 * V_2 = F_64 ( V_30 ) ;
F_102 ( V_30 ) ;
F_66 ( V_2 ) ;
F_68 ( V_2 ) ;
}
static int T_6 F_104 ( void )
{
return F_105 ( & V_244 ) ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_244 ) ;
}
