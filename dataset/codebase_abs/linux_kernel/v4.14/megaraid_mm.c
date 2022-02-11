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
if ( ! V_8 )
return - V_24 ;
if ( ( V_11 = F_10 ( V_15 , V_12 , V_8 ) ) ) {
F_11 ( V_12 , V_8 ) ;
return V_11 ;
}
V_8 -> V_25 = V_26 ;
if ( ( V_11 = F_12 ( V_12 , V_8 ) ) ) {
if ( ! V_8 -> V_27 )
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
int V_28 ;
F_15 ( & V_29 ) ;
V_28 = F_3 ( V_3 , V_6 , V_7 ) ;
F_16 ( & V_29 ) ;
return V_28 ;
}
static T_2 *
F_8 ( T_5 T_4 * V_30 , int * V_11 )
{
T_2 * V_31 ;
T_5 V_32 ;
T_6 V_33 ;
int V_34 ;
if ( F_5 ( & V_32 , V_30 , sizeof( T_5 ) ) ) {
* V_11 = - V_21 ;
return NULL ;
}
V_33 = F_17 ( V_32 . V_35 . V_36 . V_33 ) ;
if ( V_33 >= V_37 ) {
* V_11 = - V_38 ;
return NULL ;
}
V_31 = NULL ;
V_34 = 0 ;
F_18 (adapter, &adapters_list_g, list) {
if ( V_34 ++ == V_33 ) break;
}
if ( ! V_31 ) {
* V_11 = - V_38 ;
return NULL ;
}
return V_31 ;
}
static int
F_7 ( void T_4 * V_7 , T_3 V_13 , int * V_11 )
{
T_5 T_4 * V_30 ;
T_5 V_39 ;
T_3 V_40 ;
T_3 V_41 ;
if ( V_13 )
goto V_42;
else
goto V_43;
V_43:
return ( - V_44 ) ;
V_42:
* V_11 = 0 ;
V_30 = V_7 ;
if ( F_5 ( & V_39 , V_30 , sizeof( T_5 ) ) )
return ( - V_21 ) ;
V_40 = V_39 . V_35 . V_36 . V_40 ;
V_41 = V_39 . V_35 . V_36 . V_41 ;
if ( V_40 != 0x82 )
return 1 ;
switch ( V_41 ) {
case V_45 :
if ( F_19 ( V_39 . V_46 , & V_47 , sizeof( T_6 ) ) )
return ( - V_21 ) ;
return 0 ;
case V_48 :
* V_11 = V_37 ;
if ( F_19 ( V_39 . V_46 , & V_37 ,
sizeof( T_6 ) ) )
return ( - V_21 ) ;
return 0 ;
default:
return 1 ;
}
return 0 ;
}
static int
F_10 ( T_5 T_4 * V_30 , T_2 * V_12 , T_1 * V_8 )
{
T_7 * V_49 ;
T_8 * V_50 ;
T_9 * V_51 ;
T_6 V_33 ;
T_3 V_40 ;
T_3 V_41 ;
T_5 V_32 ;
if ( F_5 ( & V_32 , V_30 , sizeof( T_5 ) ) )
return ( - V_21 ) ;
if ( ( V_32 . V_50 [ 0 ] == V_52 ) ||
( V_32 . V_50 [ 0 ] == V_53 ) )
return ( - V_18 ) ;
V_40 = V_32 . V_35 . V_36 . V_40 ;
V_41 = V_32 . V_35 . V_36 . V_41 ;
V_33 = F_17 ( V_32 . V_35 . V_36 . V_33 ) ;
if ( V_33 >= V_37 )
return ( - V_38 ) ;
V_8 -> V_33 = V_33 ;
V_8 -> V_54 = V_55 ;
V_8 -> V_56 = V_57 ;
switch ( V_40 ) {
case 0x82 :
if ( V_41 == V_58 ) {
V_8 -> V_40 = V_59 ;
V_8 -> V_60 = V_61 ;
V_8 -> V_62 = sizeof( V_63 ) ;
if ( F_20 ( V_12 , V_8 , V_8 -> V_62 ) )
return ( - V_64 ) ;
}
else {
F_6 ( V_19 , ( V_20
L_4 ) ) ;
return ( - V_18 ) ;
}
break;
case 0x81 :
V_8 -> V_40 = V_65 ;
V_8 -> V_62 = V_32 . V_35 . V_36 . V_66 ;
V_8 -> V_67 = V_8 -> V_62 ;
V_8 -> V_68 = V_32 . V_35 . V_36 . V_69 ;
if ( F_20 ( V_12 , V_8 , V_8 -> V_62 ) )
return ( - V_64 ) ;
if ( V_32 . V_70 ) V_8 -> V_60 = V_61 ;
if ( V_32 . V_71 ) V_8 -> V_60 |= V_72 ;
break;
case 0x80 :
V_8 -> V_40 = V_65 ;
V_8 -> V_62 = ( V_32 . V_70 > V_32 . V_71 ) ?
V_32 . V_70 : V_32 . V_71 ;
V_8 -> V_67 = V_8 -> V_62 ;
V_8 -> V_68 = V_32 . V_46 ;
if ( F_20 ( V_12 , V_8 , V_8 -> V_62 ) )
return ( - V_64 ) ;
if ( V_32 . V_70 ) V_8 -> V_60 = V_61 ;
if ( V_32 . V_71 ) V_8 -> V_60 |= V_72 ;
break;
default:
return ( - V_18 ) ;
}
if ( V_40 == 0x82 )
return 0 ;
V_49 = ( T_7 * ) ( ( unsigned long ) V_8 -> V_73 ) ;
V_50 = & V_49 -> V_74 ;
memcpy ( V_50 , V_32 . V_50 , 14 ) ;
if ( V_50 -> V_6 != V_75 ) {
V_50 -> V_76 = ( T_6 ) V_8 -> V_77 ;
if ( V_8 -> V_60 & V_72 ) {
if ( F_5 ( V_8 -> V_78 , V_8 -> V_68 ,
V_8 -> V_62 ) ) {
return ( - V_21 ) ;
}
}
return 0 ;
}
V_51 = V_8 -> V_51 ;
V_8 -> V_79 = & V_30 -> V_80 ;
V_50 -> V_76 = ( T_6 ) V_8 -> V_81 ;
if ( F_5 ( V_51 , V_8 -> V_79 ,
sizeof( T_9 ) ) ) {
return ( - V_21 ) ;
}
V_51 -> V_82 = V_8 -> V_77 ;
if ( V_8 -> V_60 & V_72 ) {
if ( V_51 -> V_83 > V_8 -> V_62 )
return - V_18 ;
if ( F_5 ( V_8 -> V_78 , V_8 -> V_68 ,
V_51 -> V_83 ) ) {
return ( - V_21 ) ;
}
}
return 0 ;
}
static int
F_20 ( T_2 * V_12 , T_1 * V_8 , int V_62 )
{
T_10 * V_84 ;
int V_85 = - 1 ;
unsigned long V_86 ;
int V_87 ;
V_8 -> V_88 = - 1 ;
V_8 -> V_78 = NULL ;
V_8 -> V_77 = 0 ;
V_8 -> V_89 = 0 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
V_84 = & V_12 -> V_91 [ V_87 ] ;
if ( V_62 > V_84 -> V_92 )
continue;
if ( V_85 == - 1 )
V_85 = V_87 ;
F_21 ( & V_84 -> V_93 , V_86 ) ;
if ( ! V_84 -> V_94 ) {
V_84 -> V_94 = 1 ;
V_8 -> V_88 = V_87 ;
V_8 -> V_78 = V_84 -> V_95 ;
V_8 -> V_77 = V_84 -> V_96 ;
F_22 ( & V_84 -> V_93 , V_86 ) ;
return 0 ;
}
else {
F_22 ( & V_84 -> V_93 , V_86 ) ;
continue;
}
}
if ( V_85 == - 1 )
return - V_18 ;
V_84 = & V_12 -> V_91 [ V_85 ] ;
F_21 ( & V_84 -> V_93 , V_86 ) ;
V_8 -> V_88 = V_85 ;
V_8 -> V_89 = 1 ;
V_8 -> V_78 = F_23 ( V_84 -> V_97 , V_98 ,
& V_8 -> V_77 ) ;
F_22 ( & V_84 -> V_93 , V_86 ) ;
if ( ! V_8 -> V_78 )
return - V_64 ;
return 0 ;
}
static T_1 *
F_9 ( T_2 * V_12 )
{
T_1 * V_8 ;
struct V_99 * V_100 ;
unsigned long V_86 ;
F_24 ( & V_12 -> V_101 ) ;
F_21 ( & V_12 -> V_102 , V_86 ) ;
V_100 = & V_12 -> V_103 ;
if ( F_25 ( V_100 ) ) {
F_26 ( & V_12 -> V_101 ) ;
F_22 ( & V_12 -> V_102 , V_86 ) ;
F_6 ( V_19 , ( L_5 ) ) ;
return NULL ;
}
V_8 = F_27 ( V_100 -> V_104 , T_1 , V_105 ) ;
F_28 ( & V_8 -> V_105 ) ;
F_22 ( & V_12 -> V_102 , V_86 ) ;
memset ( ( V_106 ) ( unsigned long ) V_8 -> V_73 , 0 , sizeof( T_7 ) ) ;
memset ( ( V_106 ) V_8 -> V_51 , 0 , sizeof( T_9 ) ) ;
V_8 -> V_78 = NULL ;
V_8 -> V_77 = 0 ;
V_8 -> V_88 = - 1 ;
V_8 -> V_89 = 0 ;
V_8 -> V_68 = NULL ;
V_8 -> V_67 = 0 ;
V_8 -> V_79 = NULL ;
V_8 -> V_27 = 0 ;
return V_8 ;
}
static void
F_11 ( T_2 * V_12 , T_1 * V_8 )
{
T_10 * V_84 ;
unsigned long V_86 ;
if ( V_8 -> V_88 != - 1 ) {
V_84 = & V_12 -> V_91 [ V_8 -> V_88 ] ;
F_21 ( & V_84 -> V_93 , V_86 ) ;
if ( V_8 -> V_89 == 1 )
F_29 ( V_84 -> V_97 , V_8 -> V_78 ,
V_8 -> V_77 ) ;
else
V_84 -> V_94 = 0 ;
F_22 ( & V_84 -> V_93 , V_86 ) ;
}
F_21 ( & V_12 -> V_102 , V_86 ) ;
F_30 ( & V_8 -> V_105 , & V_12 -> V_103 ) ;
F_22 ( & V_12 -> V_102 , V_86 ) ;
F_26 ( & V_12 -> V_101 ) ;
return;
}
static int
F_12 ( T_2 * V_12 , T_1 * V_8 )
{
int V_11 ;
struct V_107 V_108 ;
struct V_107 * V_109 = NULL ;
V_8 -> V_110 = - V_111 ;
V_11 = V_12 -> V_112 ( V_12 -> V_113 , V_8 , V_114 ) ;
if ( V_11 ) return V_11 ;
if ( V_12 -> V_115 > 0 ) {
V_109 = & V_108 ;
F_31 ( V_109 ) ;
V_109 -> V_116 = V_117 ;
V_109 -> V_46 = ( unsigned long ) V_8 ;
V_109 -> V_118 = V_119 + V_12 -> V_115 * V_120 ;
F_32 ( V_109 ) ;
}
F_33 ( V_121 , ( V_8 -> V_110 != - V_111 ) ) ;
if ( V_109 ) {
F_34 ( V_109 ) ;
}
if ( V_8 -> V_27 ) {
V_12 -> V_23 = 0 ;
}
return V_8 -> V_110 ;
}
static void
V_26 ( T_1 * V_8 )
{
T_6 V_33 ;
int V_34 ;
T_2 * V_31 ;
if ( V_8 -> V_110 == - V_111 ) {
F_6 ( V_19 , ( V_20
L_6 ) ) ;
V_8 -> V_110 = - V_18 ;
}
if ( V_8 -> V_27 ) {
V_34 = 0 ;
V_31 = NULL ;
V_33 = V_8 -> V_33 ;
F_6 ( V_19 , ( V_20 L_7
L_8 ) ) ;
F_18 (adapter, &adapters_list_g, list) {
if ( V_34 ++ == V_33 ) break;
}
V_8 -> V_27 = 0 ;
if ( V_31 ) {
F_11 ( V_31 , V_8 ) ;
}
}
else {
F_35 ( & V_121 ) ;
}
}
static void
V_117 ( unsigned long V_122 )
{
T_1 * V_8 = ( T_1 * ) V_122 ;
V_8 -> V_110 = - V_123 ;
V_8 -> V_27 = 1 ;
F_6 ( V_19 , ( V_20 L_9 ) ) ;
F_35 ( & V_121 ) ;
}
static int
F_13 ( T_1 * V_8 , T_5 T_4 * V_32 )
{
T_5 V_39 ;
T_3 V_40 ;
T_3 V_41 ;
T_7 * V_49 ;
T_9 T_4 * V_124 ;
T_9 * V_125 ;
T_11 V_126 ;
V_63 * V_127 ;
if ( F_5 ( & V_39 , V_32 , sizeof( T_5 ) ) )
return ( - V_21 ) ;
V_40 = V_39 . V_35 . V_36 . V_40 ;
V_41 = V_39 . V_35 . V_36 . V_41 ;
if ( V_40 == 0x82 ) {
switch ( V_41 ) {
case V_58 :
V_127 = ( V_63 * ) ( unsigned long )
V_8 -> V_78 ;
F_36 ( V_127 , & V_126 ) ;
if ( F_19 ( V_39 . V_46 , & V_126 , sizeof( V_126 ) ) )
return ( - V_21 ) ;
return 0 ;
default:
return ( - V_18 ) ;
}
return 0 ;
}
V_49 = ( T_7 * ) ( unsigned long ) V_8 -> V_73 ;
if ( V_8 -> V_79 ) {
V_124 = V_8 -> V_79 ;
V_125 = V_8 -> V_51 ;
if ( F_19 ( & V_124 -> V_128 ,
& V_125 -> V_128 ,
sizeof( T_3 ) ) ) {
return ( - V_21 ) ;
}
}
if ( V_8 -> V_68 ) {
if ( F_19 ( V_8 -> V_68 , V_8 -> V_78 ,
V_8 -> V_67 ) ) {
return ( - V_21 ) ;
}
}
if ( F_19 ( & V_32 -> V_50 [ 17 ] ,
& V_49 -> V_74 . V_110 , sizeof( T_3 ) ) ) {
return ( - V_21 ) ;
}
return 0 ;
}
static void
F_36 ( V_63 * V_127 , T_11 * V_126 )
{
if ( ! V_127 || ! V_126 )
return;
V_126 -> V_129 = V_127 -> V_130 ;
V_126 -> V_131 = V_127 -> V_131 ;
V_126 -> V_132 = V_127 -> V_133 ;
V_126 -> V_134 = V_127 -> V_135 ;
V_126 -> V_136 = V_127 -> V_137 ;
V_126 -> V_138 = F_37 ( V_127 -> V_139 ) ;
V_126 -> V_140 = V_127 -> V_141 ;
V_126 -> V_142 = V_127 -> V_143 ;
V_126 -> V_144 = V_127 -> V_137 ;
V_126 -> V_145 = V_127 -> V_146 ;
}
int
F_38 ( T_2 * V_147 )
{
T_2 * V_31 ;
T_7 * V_148 ;
T_1 * V_8 ;
T_6 V_11 ;
int V_87 ;
if ( V_147 -> V_149 != V_150 )
return ( - V_18 ) ;
V_31 = F_39 ( sizeof( T_2 ) , V_151 ) ;
if ( ! V_31 )
return - V_64 ;
V_31 -> V_146 = V_147 -> V_146 ;
V_31 -> V_149 = V_147 -> V_149 ;
V_31 -> V_113 = V_147 -> V_113 ;
V_31 -> V_152 = V_147 -> V_152 ;
V_31 -> V_112 = V_147 -> V_112 ;
V_31 -> V_115 = V_147 -> V_115 ;
V_31 -> V_153 = V_147 -> V_153 ;
V_31 -> V_23 = 1 ;
V_31 -> V_154 = F_40 ( sizeof( T_1 ) * V_147 -> V_153 ,
V_151 ) ;
V_31 -> V_148 = F_40 ( sizeof( T_7 ) * V_147 -> V_153 ,
V_151 ) ;
V_31 -> V_155 = F_41 ( L_10 ,
& V_31 -> V_152 -> V_156 ,
sizeof( T_9 ) ,
16 , 0 ) ;
if ( ! V_31 -> V_154 || ! V_31 -> V_148 ||
! V_31 -> V_155 ) {
F_6 ( V_19 , ( V_20
L_11 , V_157 ,
__LINE__ ) ) ;
V_11 = ( - V_64 ) ;
goto V_158;
}
F_42 ( & V_31 -> V_103 ) ;
F_43 ( & V_31 -> V_102 ) ;
F_44 ( & V_31 -> V_101 , V_147 -> V_153 ) ;
V_148 = ( T_7 * ) V_31 -> V_148 ;
for ( V_87 = 0 ; V_87 < V_147 -> V_153 ; V_87 ++ ) {
V_8 = V_31 -> V_154 + V_87 ;
V_8 -> V_73 = ( V_159 ) ( unsigned long ) ( V_148 + V_87 ) ;
V_8 -> V_51 = F_23 ( V_31 -> V_155 ,
V_151 , & V_8 -> V_81 ) ;
if ( ! V_8 -> V_51 ) {
F_6 ( V_19 , ( V_20
L_11 ,
V_157 , __LINE__ ) ) ;
V_11 = ( - V_64 ) ;
goto V_160;
}
F_45 ( & V_8 -> V_105 , & V_31 -> V_103 ) ;
}
if ( ( V_11 = F_46 ( V_31 ) ) != 0 ) {
goto V_161;
}
F_45 ( & V_31 -> V_105 , & V_162 ) ;
V_37 ++ ;
return 0 ;
V_161:
V_160:
for ( V_87 = 0 ; V_87 < V_147 -> V_153 ; V_87 ++ ) {
V_8 = V_31 -> V_154 + V_87 ;
if ( V_8 -> V_51 ) {
F_29 ( V_31 -> V_155 , V_8 -> V_51 ,
V_8 -> V_81 ) ;
}
}
V_158:
F_47 ( V_31 -> V_154 ) ;
F_47 ( V_31 -> V_148 ) ;
if ( V_31 -> V_155 )
F_48 ( V_31 -> V_155 ) ;
F_47 ( V_31 ) ;
return V_11 ;
}
T_6
F_49 ( T_6 V_146 )
{
T_2 * V_31 ;
T_2 * V_163 ;
int V_164 = 0 ;
F_50 (adapter, tmp, &adapters_list_g, list) {
if ( V_31 -> V_146 == V_146 ) {
return F_51 ( V_164 ) ;
}
V_164 ++ ;
}
return 0 ;
}
static int
F_46 ( T_2 * V_12 )
{
T_10 * V_84 ;
int V_165 ;
int V_87 ;
V_165 = V_166 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
V_84 = & V_12 -> V_91 [ V_87 ] ;
V_84 -> V_92 = V_165 ;
F_43 ( & V_84 -> V_93 ) ;
V_84 -> V_97 = F_41 ( L_12 ,
& V_12 -> V_152 -> V_156 , V_165 ,
16 , 0 ) ;
if ( ! V_84 -> V_97 ) {
goto V_167;
}
V_84 -> V_95 = F_23 ( V_84 -> V_97 , V_151 ,
& V_84 -> V_96 ) ;
if ( ! V_84 -> V_95 )
goto V_167;
V_165 = V_165 * 2 ;
}
return 0 ;
V_167:
F_52 ( V_12 ) ;
return ( - V_64 ) ;
}
int
F_53 ( T_6 V_146 )
{
T_2 * V_31 ;
T_2 * V_163 ;
F_50 (adapter, tmp, &adapters_list_g, list) {
if ( V_31 -> V_146 == V_146 ) {
V_37 -- ;
F_28 ( & V_31 -> V_105 ) ;
F_54 ( V_31 ) ;
F_47 ( V_31 ) ;
F_6 ( V_19 , (
L_13 ,
V_146 ) ) ;
return 0 ;
}
}
return ( - V_38 ) ;
}
static void
F_54 ( T_2 * V_12 )
{
T_1 * V_8 ;
int V_87 ;
F_52 ( V_12 ) ;
for ( V_87 = 0 ; V_87 < V_12 -> V_153 ; V_87 ++ ) {
V_8 = V_12 -> V_154 + V_87 ;
F_29 ( V_12 -> V_155 , V_8 -> V_51 ,
V_8 -> V_81 ) ;
}
F_47 ( V_12 -> V_154 ) ;
F_47 ( V_12 -> V_148 ) ;
F_48 ( V_12 -> V_155 ) ;
return;
}
static void
F_52 ( T_2 * V_12 )
{
int V_87 ;
T_10 * V_84 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
V_84 = & V_12 -> V_91 [ V_87 ] ;
if ( V_84 -> V_97 ) {
if ( V_84 -> V_95 )
F_29 ( V_84 -> V_97 , V_84 -> V_95 ,
V_84 -> V_96 ) ;
F_48 ( V_84 -> V_97 ) ;
V_84 -> V_97 = NULL ;
}
}
return;
}
static int T_12
F_55 ( void )
{
int V_28 ;
F_6 ( V_19 , ( V_168 L_14 ,
V_169 , V_170 ) ) ;
V_28 = F_56 ( & V_171 ) ;
if ( V_28 < 0 ) {
F_6 ( V_19 , ( L_15 ) ) ;
return V_28 ;
}
F_57 ( & V_121 ) ;
F_42 ( & V_162 ) ;
return 0 ;
}
static long
F_58 ( struct V_2 * V_3 , unsigned int V_6 ,
unsigned long V_7 )
{
int V_28 ;
V_28 = F_3 ( V_3 , V_6 , V_7 ) ;
return V_28 ;
}
static void T_13
F_59 ( void )
{
F_6 ( V_172 , ( L_16 ) ) ;
F_60 ( & V_171 ) ;
}
