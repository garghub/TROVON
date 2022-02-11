static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( ! F_2 ( V_4 ) ) return ( - V_5 ) ;
return 0 ;
}
static int
F_3 ( struct V_2 * V_3 , unsigned int V_6 , unsigned long V_7 )
{
T_1 * V_8 ;
char V_9 [ V_10 ] = { 0 } ;
int V_11 ;
T_2 * V_12 ;
T_3 V_13 ;
int V_14 ;
void T_4 * V_15 = ( void T_4 * ) V_7 ;
if ( ( F_4 ( V_6 ) != V_16 ) && ( V_6 != V_17 ) ) {
return ( - V_18 ) ;
}
if ( F_5 ( V_9 , V_15 , V_10 ) ) {
F_6 ( V_19 , ( V_20
L_1 ) ) ;
return ( - V_21 ) ;
}
if ( memcmp ( V_9 , V_22 , V_10 ) == 0 )
V_13 = 0 ;
else
V_13 = 1 ;
if ( ! V_13 )
return ( - V_18 ) ;
V_11 = F_7 ( V_15 , V_13 , & V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
else if ( V_11 == 0 )
return V_14 ;
V_11 = 0 ;
if ( ( V_12 = F_8 ( V_15 , & V_11 ) ) == NULL ) {
return V_11 ;
}
if ( ! V_12 -> V_23 ) {
F_6 ( V_19 , ( V_20
L_2
L_3 ) ) ;
return - V_21 ;
}
V_8 = F_9 ( V_12 ) ;
if ( ( V_11 = F_10 ( V_15 , V_12 , V_8 ) ) ) {
F_11 ( V_12 , V_8 ) ;
return V_11 ;
}
V_8 -> V_24 = V_25 ;
if ( ( V_11 = F_12 ( V_12 , V_8 ) ) ) {
if ( ! V_8 -> V_26 )
F_11 ( V_12 , V_8 ) ;
return V_11 ;
}
V_11 = F_13 ( V_8 , V_15 ) ;
F_11 ( V_12 , V_8 ) ;
return V_11 ;
}
static long
F_14 ( struct V_2 * V_3 , unsigned int V_6 ,
unsigned long V_7 )
{
int V_27 ;
F_15 ( & V_28 ) ;
V_27 = F_3 ( V_3 , V_6 , V_7 ) ;
F_16 ( & V_28 ) ;
return V_27 ;
}
static T_2 *
F_8 ( T_5 T_4 * V_29 , int * V_11 )
{
T_2 * V_30 ;
T_5 V_31 ;
T_6 V_32 ;
int V_33 ;
if ( F_5 ( & V_31 , V_29 , sizeof( T_5 ) ) ) {
* V_11 = - V_21 ;
return NULL ;
}
V_32 = F_17 ( V_31 . V_34 . V_35 . V_32 ) ;
if ( V_32 >= V_36 ) {
* V_11 = - V_37 ;
return NULL ;
}
V_30 = NULL ;
V_33 = 0 ;
F_18 (adapter, &adapters_list_g, list) {
if ( V_33 ++ == V_32 ) break;
}
if ( ! V_30 ) {
* V_11 = - V_37 ;
return NULL ;
}
return V_30 ;
}
static int
F_7 ( void T_4 * V_7 , T_3 V_13 , int * V_11 )
{
T_5 T_4 * V_29 ;
T_5 V_38 ;
T_3 V_39 ;
T_3 V_40 ;
if ( V_13 )
goto V_41;
else
goto V_42;
V_42:
return ( - V_43 ) ;
V_41:
* V_11 = 0 ;
V_29 = V_7 ;
if ( F_5 ( & V_38 , V_29 , sizeof( T_5 ) ) )
return ( - V_21 ) ;
V_39 = V_38 . V_34 . V_35 . V_39 ;
V_40 = V_38 . V_34 . V_35 . V_40 ;
if ( V_39 != 0x82 )
return 1 ;
switch ( V_40 ) {
case V_44 :
if ( F_19 ( V_38 . V_45 , & V_46 , sizeof( T_6 ) ) )
return ( - V_21 ) ;
return 0 ;
case V_47 :
* V_11 = V_36 ;
if ( F_19 ( V_38 . V_45 , & V_36 ,
sizeof( T_6 ) ) )
return ( - V_21 ) ;
return 0 ;
default:
return 1 ;
}
return 0 ;
}
static int
F_10 ( T_5 T_4 * V_29 , T_2 * V_12 , T_1 * V_8 )
{
T_7 * V_48 ;
T_8 * V_49 ;
T_9 * V_50 ;
T_6 V_32 ;
T_3 V_39 ;
T_3 V_40 ;
T_5 V_31 ;
if ( F_5 ( & V_31 , V_29 , sizeof( T_5 ) ) )
return ( - V_21 ) ;
if ( ( V_31 . V_49 [ 0 ] == V_51 ) ||
( V_31 . V_49 [ 0 ] == V_52 ) )
return ( - V_18 ) ;
V_39 = V_31 . V_34 . V_35 . V_39 ;
V_40 = V_31 . V_34 . V_35 . V_40 ;
V_32 = F_17 ( V_31 . V_34 . V_35 . V_32 ) ;
if ( V_32 >= V_36 )
return ( - V_37 ) ;
V_8 -> V_32 = V_32 ;
V_8 -> V_53 = V_54 ;
V_8 -> V_55 = V_56 ;
switch ( V_39 ) {
case 0x82 :
if ( V_40 == V_57 ) {
V_8 -> V_39 = V_58 ;
V_8 -> V_59 = V_60 ;
V_8 -> V_61 = sizeof( V_62 ) ;
if ( F_20 ( V_12 , V_8 , V_8 -> V_61 ) )
return ( - V_63 ) ;
}
else {
F_6 ( V_19 , ( V_20
L_4 ) ) ;
return ( - V_18 ) ;
}
break;
case 0x81 :
V_8 -> V_39 = V_64 ;
V_8 -> V_61 = V_31 . V_34 . V_35 . V_65 ;
V_8 -> V_66 = V_8 -> V_61 ;
V_8 -> V_67 = V_31 . V_34 . V_35 . V_68 ;
if ( F_20 ( V_12 , V_8 , V_8 -> V_61 ) )
return ( - V_63 ) ;
if ( V_31 . V_69 ) V_8 -> V_59 = V_60 ;
if ( V_31 . V_70 ) V_8 -> V_59 |= V_71 ;
break;
case 0x80 :
V_8 -> V_39 = V_64 ;
V_8 -> V_61 = ( V_31 . V_69 > V_31 . V_70 ) ?
V_31 . V_69 : V_31 . V_70 ;
V_8 -> V_66 = V_8 -> V_61 ;
V_8 -> V_67 = V_31 . V_45 ;
if ( F_20 ( V_12 , V_8 , V_8 -> V_61 ) )
return ( - V_63 ) ;
if ( V_31 . V_69 ) V_8 -> V_59 = V_60 ;
if ( V_31 . V_70 ) V_8 -> V_59 |= V_71 ;
break;
default:
return ( - V_18 ) ;
}
if ( V_39 == 0x82 )
return 0 ;
V_48 = ( T_7 * ) ( ( unsigned long ) V_8 -> V_72 ) ;
V_49 = & V_48 -> V_73 ;
memcpy ( V_49 , V_31 . V_49 , 14 ) ;
if ( V_49 -> V_6 != V_74 ) {
V_49 -> V_75 = ( T_6 ) V_8 -> V_76 ;
if ( V_8 -> V_59 & V_71 ) {
if ( F_5 ( V_8 -> V_77 , V_8 -> V_67 ,
V_8 -> V_61 ) ) {
return ( - V_21 ) ;
}
}
return 0 ;
}
V_50 = V_8 -> V_50 ;
V_8 -> V_78 = & V_29 -> V_79 ;
V_49 -> V_75 = ( T_6 ) V_8 -> V_80 ;
if ( F_5 ( V_50 , V_8 -> V_78 ,
sizeof( T_9 ) ) ) {
return ( - V_21 ) ;
}
V_50 -> V_81 = V_8 -> V_76 ;
if ( V_8 -> V_59 & V_71 ) {
if ( F_5 ( V_8 -> V_77 , V_8 -> V_67 ,
V_50 -> V_82 ) ) {
return ( - V_21 ) ;
}
}
return 0 ;
}
static int
F_20 ( T_2 * V_12 , T_1 * V_8 , int V_61 )
{
T_10 * V_83 ;
int V_84 = - 1 ;
unsigned long V_85 ;
int V_86 ;
V_8 -> V_87 = - 1 ;
V_8 -> V_77 = NULL ;
V_8 -> V_76 = 0 ;
V_8 -> V_88 = 0 ;
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
V_83 = & V_12 -> V_90 [ V_86 ] ;
if ( V_61 > V_83 -> V_91 )
continue;
if ( V_84 == - 1 )
V_84 = V_86 ;
F_21 ( & V_83 -> V_92 , V_85 ) ;
if ( ! V_83 -> V_93 ) {
V_83 -> V_93 = 1 ;
V_8 -> V_87 = V_86 ;
V_8 -> V_77 = V_83 -> V_94 ;
V_8 -> V_76 = V_83 -> V_95 ;
F_22 ( & V_83 -> V_92 , V_85 ) ;
return 0 ;
}
else {
F_22 ( & V_83 -> V_92 , V_85 ) ;
continue;
}
}
if ( V_84 == - 1 )
return - V_18 ;
V_83 = & V_12 -> V_90 [ V_84 ] ;
F_21 ( & V_83 -> V_92 , V_85 ) ;
V_8 -> V_87 = V_84 ;
V_8 -> V_88 = 1 ;
V_8 -> V_77 = F_23 ( V_83 -> V_96 , V_97 ,
& V_8 -> V_76 ) ;
F_22 ( & V_83 -> V_92 , V_85 ) ;
if ( ! V_8 -> V_77 )
return - V_63 ;
return 0 ;
}
static T_1 *
F_9 ( T_2 * V_12 )
{
T_1 * V_8 ;
struct V_98 * V_99 ;
unsigned long V_85 ;
F_24 ( & V_12 -> V_100 ) ;
F_21 ( & V_12 -> V_101 , V_85 ) ;
V_99 = & V_12 -> V_102 ;
if ( F_25 ( V_99 ) ) {
F_26 ( & V_12 -> V_100 ) ;
F_22 ( & V_12 -> V_101 , V_85 ) ;
F_6 ( V_19 , ( L_5 ) ) ;
return NULL ;
}
V_8 = F_27 ( V_99 -> V_103 , T_1 , V_104 ) ;
F_28 ( & V_8 -> V_104 ) ;
F_22 ( & V_12 -> V_101 , V_85 ) ;
memset ( ( V_105 ) ( unsigned long ) V_8 -> V_72 , 0 , sizeof( T_7 ) ) ;
memset ( ( V_105 ) V_8 -> V_50 , 0 , sizeof( T_9 ) ) ;
V_8 -> V_77 = NULL ;
V_8 -> V_76 = 0 ;
V_8 -> V_87 = - 1 ;
V_8 -> V_88 = 0 ;
V_8 -> V_67 = NULL ;
V_8 -> V_66 = 0 ;
V_8 -> V_78 = NULL ;
V_8 -> V_26 = 0 ;
return V_8 ;
}
static void
F_11 ( T_2 * V_12 , T_1 * V_8 )
{
T_10 * V_83 ;
unsigned long V_85 ;
if ( V_8 -> V_87 != - 1 ) {
V_83 = & V_12 -> V_90 [ V_8 -> V_87 ] ;
F_21 ( & V_83 -> V_92 , V_85 ) ;
if ( V_8 -> V_88 == 1 )
F_29 ( V_83 -> V_96 , V_8 -> V_77 ,
V_8 -> V_76 ) ;
else
V_83 -> V_93 = 0 ;
F_22 ( & V_83 -> V_92 , V_85 ) ;
}
F_21 ( & V_12 -> V_101 , V_85 ) ;
F_30 ( & V_8 -> V_104 , & V_12 -> V_102 ) ;
F_22 ( & V_12 -> V_101 , V_85 ) ;
F_26 ( & V_12 -> V_100 ) ;
return;
}
static int
F_12 ( T_2 * V_12 , T_1 * V_8 )
{
int V_11 ;
struct V_106 V_107 ;
struct V_106 * V_108 = NULL ;
V_8 -> V_109 = - V_110 ;
V_11 = V_12 -> V_111 ( V_12 -> V_112 , V_8 , V_113 ) ;
if ( V_11 ) return V_11 ;
if ( V_12 -> V_114 > 0 ) {
V_108 = & V_107 ;
F_31 ( V_108 ) ;
V_108 -> V_115 = V_116 ;
V_108 -> V_45 = ( unsigned long ) V_8 ;
V_108 -> V_117 = V_118 + V_12 -> V_114 * V_119 ;
F_32 ( V_108 ) ;
}
F_33 ( V_120 , ( V_8 -> V_109 != - V_110 ) ) ;
if ( V_108 ) {
F_34 ( V_108 ) ;
}
if ( V_8 -> V_26 ) {
V_12 -> V_23 = 0 ;
}
return V_8 -> V_109 ;
}
static void
V_25 ( T_1 * V_8 )
{
T_6 V_32 ;
int V_33 ;
T_2 * V_30 ;
if ( V_8 -> V_109 == - V_110 ) {
F_6 ( V_19 , ( V_20
L_6 ) ) ;
V_8 -> V_109 = - V_18 ;
}
if ( V_8 -> V_26 ) {
V_33 = 0 ;
V_30 = NULL ;
V_32 = V_8 -> V_32 ;
F_6 ( V_19 , ( V_20 L_7
L_8 ) ) ;
F_18 (adapter, &adapters_list_g, list) {
if ( V_33 ++ == V_32 ) break;
}
V_8 -> V_26 = 0 ;
if ( V_30 ) {
F_11 ( V_30 , V_8 ) ;
}
}
else {
F_35 ( & V_120 ) ;
}
}
static void
V_116 ( unsigned long V_121 )
{
T_1 * V_8 = ( T_1 * ) V_121 ;
V_8 -> V_109 = - V_122 ;
V_8 -> V_26 = 1 ;
F_6 ( V_19 , ( V_20 L_9 ) ) ;
F_35 ( & V_120 ) ;
}
static int
F_13 ( T_1 * V_8 , T_5 T_4 * V_31 )
{
T_5 V_38 ;
T_3 V_39 ;
T_3 V_40 ;
T_7 * V_48 ;
T_9 T_4 * V_123 ;
T_9 * V_124 ;
T_11 V_125 ;
V_62 * V_126 ;
if ( F_5 ( & V_38 , V_31 , sizeof( T_5 ) ) )
return ( - V_21 ) ;
V_39 = V_38 . V_34 . V_35 . V_39 ;
V_40 = V_38 . V_34 . V_35 . V_40 ;
if ( V_39 == 0x82 ) {
switch ( V_40 ) {
case V_57 :
V_126 = ( V_62 * ) ( unsigned long )
V_8 -> V_77 ;
F_36 ( V_126 , & V_125 ) ;
if ( F_19 ( V_38 . V_45 , & V_125 , sizeof( V_125 ) ) )
return ( - V_21 ) ;
return 0 ;
default:
return ( - V_18 ) ;
}
return 0 ;
}
V_48 = ( T_7 * ) ( unsigned long ) V_8 -> V_72 ;
if ( V_8 -> V_78 ) {
V_123 = V_8 -> V_78 ;
V_124 = V_8 -> V_50 ;
if ( F_19 ( & V_123 -> V_127 ,
& V_124 -> V_127 ,
sizeof( T_3 ) ) ) {
return ( - V_21 ) ;
}
}
if ( V_8 -> V_67 ) {
if ( F_19 ( V_8 -> V_67 , V_8 -> V_77 ,
V_8 -> V_66 ) ) {
return ( - V_21 ) ;
}
}
if ( F_19 ( & V_31 -> V_49 [ 17 ] ,
& V_48 -> V_73 . V_109 , sizeof( T_3 ) ) ) {
return ( - V_21 ) ;
}
return 0 ;
}
static void
F_36 ( V_62 * V_126 , T_11 * V_125 )
{
if ( ! V_126 || ! V_125 )
return;
V_125 -> V_128 = V_126 -> V_129 ;
V_125 -> V_130 = V_126 -> V_130 ;
V_125 -> V_131 = V_126 -> V_132 ;
V_125 -> V_133 = V_126 -> V_134 ;
V_125 -> V_135 = V_126 -> V_136 ;
V_125 -> V_137 = F_37 ( V_126 -> V_138 ) ;
V_125 -> V_139 = V_126 -> V_140 ;
V_125 -> V_141 = V_126 -> V_142 ;
V_125 -> V_143 = V_126 -> V_136 ;
V_125 -> V_144 = V_126 -> V_145 ;
}
int
F_38 ( T_2 * V_146 )
{
T_2 * V_30 ;
T_7 * V_147 ;
T_1 * V_8 ;
T_6 V_11 ;
int V_86 ;
if ( V_146 -> V_148 != V_149 )
return ( - V_18 ) ;
V_30 = F_39 ( sizeof( T_2 ) , V_97 ) ;
if ( ! V_30 )
return - V_63 ;
V_30 -> V_145 = V_146 -> V_145 ;
V_30 -> V_148 = V_146 -> V_148 ;
V_30 -> V_112 = V_146 -> V_112 ;
V_30 -> V_150 = V_146 -> V_150 ;
V_30 -> V_111 = V_146 -> V_111 ;
V_30 -> V_114 = V_146 -> V_114 ;
V_30 -> V_151 = V_146 -> V_151 ;
V_30 -> V_23 = 1 ;
V_30 -> V_152 = F_40 ( sizeof( T_1 ) * V_146 -> V_151 ,
V_97 ) ;
V_30 -> V_147 = F_40 ( sizeof( T_7 ) * V_146 -> V_151 ,
V_97 ) ;
V_30 -> V_153 = F_41 ( L_10 ,
V_30 -> V_150 ,
sizeof( T_9 ) ,
16 , 0 ) ;
if ( ! V_30 -> V_152 || ! V_30 -> V_147 ||
! V_30 -> V_153 ) {
F_6 ( V_19 , ( V_20
L_11 , V_154 ,
__LINE__ ) ) ;
V_11 = ( - V_63 ) ;
goto V_155;
}
F_42 ( & V_30 -> V_102 ) ;
F_43 ( & V_30 -> V_101 ) ;
F_44 ( & V_30 -> V_100 , V_146 -> V_151 ) ;
V_147 = ( T_7 * ) V_30 -> V_147 ;
for ( V_86 = 0 ; V_86 < V_146 -> V_151 ; V_86 ++ ) {
V_8 = V_30 -> V_152 + V_86 ;
V_8 -> V_72 = ( V_156 ) ( unsigned long ) ( V_147 + V_86 ) ;
V_8 -> V_50 = F_23 ( V_30 -> V_153 ,
V_97 , & V_8 -> V_80 ) ;
if ( ! V_8 -> V_50 ) {
F_6 ( V_19 , ( V_20
L_11 ,
V_154 , __LINE__ ) ) ;
V_11 = ( - V_63 ) ;
goto V_157;
}
F_45 ( & V_8 -> V_104 , & V_30 -> V_102 ) ;
}
if ( ( V_11 = F_46 ( V_30 ) ) != 0 ) {
goto V_158;
}
F_45 ( & V_30 -> V_104 , & V_159 ) ;
V_36 ++ ;
return 0 ;
V_158:
V_157:
for ( V_86 = 0 ; V_86 < V_146 -> V_151 ; V_86 ++ ) {
V_8 = V_30 -> V_152 + V_86 ;
if ( V_8 -> V_50 ) {
F_29 ( V_30 -> V_153 , V_8 -> V_50 ,
V_8 -> V_80 ) ;
}
}
V_155:
F_47 ( V_30 -> V_152 ) ;
F_47 ( V_30 -> V_147 ) ;
if ( V_30 -> V_153 )
F_48 ( V_30 -> V_153 ) ;
F_47 ( V_30 ) ;
return V_11 ;
}
T_6
F_49 ( T_6 V_145 )
{
T_2 * V_30 ;
T_2 * V_160 ;
int V_161 = 0 ;
F_50 (adapter, tmp, &adapters_list_g, list) {
if ( V_30 -> V_145 == V_145 ) {
return F_51 ( V_161 ) ;
}
V_161 ++ ;
}
return 0 ;
}
static int
F_46 ( T_2 * V_12 )
{
T_10 * V_83 ;
int V_162 ;
int V_86 ;
V_162 = V_163 ;
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
V_83 = & V_12 -> V_90 [ V_86 ] ;
V_83 -> V_91 = V_162 ;
F_43 ( & V_83 -> V_92 ) ;
V_83 -> V_96 = F_41 ( L_12 ,
V_12 -> V_150 , V_162 , 16 , 0 ) ;
if ( ! V_83 -> V_96 ) {
goto V_164;
}
V_83 -> V_94 = F_23 ( V_83 -> V_96 , V_97 ,
& V_83 -> V_95 ) ;
if ( ! V_83 -> V_94 )
goto V_164;
V_162 = V_162 * 2 ;
}
return 0 ;
V_164:
F_52 ( V_12 ) ;
return ( - V_63 ) ;
}
int
F_53 ( T_6 V_145 )
{
T_2 * V_30 ;
T_2 * V_160 ;
F_50 (adapter, tmp, &adapters_list_g, list) {
if ( V_30 -> V_145 == V_145 ) {
V_36 -- ;
F_28 ( & V_30 -> V_104 ) ;
F_54 ( V_30 ) ;
F_47 ( V_30 ) ;
F_6 ( V_19 , (
L_13 ,
V_145 ) ) ;
return 0 ;
}
}
return ( - V_37 ) ;
}
static void
F_54 ( T_2 * V_12 )
{
T_1 * V_8 ;
int V_86 ;
F_52 ( V_12 ) ;
for ( V_86 = 0 ; V_86 < V_12 -> V_151 ; V_86 ++ ) {
V_8 = V_12 -> V_152 + V_86 ;
F_29 ( V_12 -> V_153 , V_8 -> V_50 ,
V_8 -> V_80 ) ;
}
F_47 ( V_12 -> V_152 ) ;
F_47 ( V_12 -> V_147 ) ;
F_48 ( V_12 -> V_153 ) ;
return;
}
static void
F_52 ( T_2 * V_12 )
{
int V_86 ;
T_10 * V_83 ;
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
V_83 = & V_12 -> V_90 [ V_86 ] ;
if ( V_83 -> V_96 ) {
if ( V_83 -> V_94 )
F_29 ( V_83 -> V_96 , V_83 -> V_94 ,
V_83 -> V_95 ) ;
F_48 ( V_83 -> V_96 ) ;
V_83 -> V_96 = NULL ;
}
}
return;
}
static int T_12
F_55 ( void )
{
int V_27 ;
F_6 ( V_19 , ( V_165 L_14 ,
V_166 , V_167 ) ) ;
V_27 = F_56 ( & V_168 ) ;
if ( V_27 < 0 ) {
F_6 ( V_19 , ( L_15 ) ) ;
return V_27 ;
}
F_57 ( & V_120 ) ;
F_42 ( & V_159 ) ;
return 0 ;
}
static long
F_58 ( struct V_2 * V_3 , unsigned int V_6 ,
unsigned long V_7 )
{
int V_27 ;
V_27 = F_3 ( V_3 , V_6 , V_7 ) ;
return V_27 ;
}
static void T_13
F_59 ( void )
{
F_6 ( V_169 , ( L_16 ) ) ;
F_60 ( & V_168 ) ;
}
