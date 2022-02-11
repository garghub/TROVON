T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_5 , T_3 V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
if ( ! V_4 )
return V_10 ;
V_4 -> V_5 = F_2 ( V_5 , V_6 ) ;
V_4 -> V_11 = F_3 ( & V_8 -> V_12 -> V_13 , V_4 -> V_5 ,
( V_14 * ) & V_4 -> V_15 , V_16 ) ;
if ( V_4 -> V_11 )
return 0 ;
else
return V_17 ;
}
T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
if ( ! V_4 || ! V_4 -> V_11 )
return V_10 ;
F_5 ( & V_8 -> V_12 -> V_13 , V_4 -> V_5 ,
V_4 -> V_11 , ( V_14 ) V_4 -> V_15 ) ;
return 0 ;
}
T_1 F_6 ( struct V_1 * V_2 ,
struct V_18 * V_4 , T_3 V_5 )
{
if ( ! V_4 )
return V_10 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_11 = F_7 ( V_5 , V_16 ) ;
if ( V_4 -> V_11 )
return 0 ;
else
return V_17 ;
}
T_1 F_8 ( struct V_1 * V_2 ,
struct V_18 * V_4 )
{
if ( ! V_4 )
return V_10 ;
F_9 ( V_4 -> V_11 ) ;
return 0 ;
}
void F_10 ( void * V_2 , T_3 V_19 , char * V_20 , ... )
{
char V_21 [ 512 ] ;
T_4 V_22 ;
if ( ! ( V_19 & ( (struct V_1 * ) V_2 ) -> V_23 ) )
return;
va_start ( V_22 , V_20 ) ;
vsnprintf ( V_21 , sizeof( V_21 ) , V_20 , V_22 ) ;
va_end ( V_22 ) ;
F_11 ( L_1 , V_21 ) ;
}
static void F_12 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
V_8 -> V_26 ++ ;
if ( ! ( V_8 -> V_27 & V_28 ) ) {
V_8 -> V_27 |= V_29 ;
F_14 ( & V_8 -> V_30 ) ;
}
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_16 ( V_2 , V_31 , 0 ) ;
F_17 ( V_2 , V_32 ) ;
F_18 ( V_8 -> V_33 [ 0 ] . V_34 ) ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_16 ( V_2 , V_31 , V_35 |
V_36 ) ;
F_16 ( V_2 , V_37 , V_38 ) ;
F_17 ( V_2 , V_32 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
int V_39 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( ! V_8 -> V_33 )
return;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
F_16 ( V_2 , F_21 ( V_39 - 1 ) , 0 ) ;
F_18 ( V_8 -> V_33 [ V_39 ] . V_34 ) ;
}
F_17 ( V_2 , V_32 ) ;
}
void F_22 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & ( 1 << ( V_39 - 1 ) ) ) {
F_16 ( V_2 , F_21 ( V_39 - 1 ) ,
V_41 |
V_42 ) ;
}
}
}
static void F_23 ( struct V_7 * V_8 ,
T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
T_5 V_43 ;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & ( 1 << V_39 ) ) {
V_43 = F_17 ( V_2 , F_21 ( V_39 - 1 ) ) ;
V_43 |= V_44 |
V_42 ;
F_16 ( V_2 , F_21 ( V_39 - 1 ) , V_43 ) ;
}
}
}
void F_24 ( struct V_7 * V_8 , bool V_45 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_22 ( V_8 , ~ 0 ) ;
if ( V_45 )
F_17 ( V_2 , V_32 ) ;
}
static T_6 F_25 ( int V_46 , void * V_47 )
{
struct V_24 * V_25 = V_47 ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_48 ;
T_3 V_49 ;
V_48 = F_17 ( V_2 , V_50 ) ;
V_49 = F_17 ( V_2 , V_37 ) ;
V_48 = F_17 ( V_2 , V_31 ) ;
V_48 = V_48 | V_51 ;
F_16 ( V_2 , V_31 , V_48 ) ;
F_16 ( V_2 , V_37 , V_49 ) ;
F_16 ( V_2 , V_31 , V_35 ) ;
F_14 ( & V_8 -> V_52 ) ;
return V_53 ;
}
static T_6 F_26 ( int V_46 , void * V_47 )
{
struct V_54 * V_55 = V_47 ;
if ( ! V_55 -> V_56 . V_57 && ! V_55 -> V_58 . V_57 )
return V_53 ;
F_27 ( & V_55 -> V_59 ) ;
return V_53 ;
}
static void
F_28 ( struct V_7 * V_8 , int V_60 , int V_61 )
{
struct V_54 * V_55 = V_8 -> V_55 [ V_60 ] ;
struct V_62 * V_63 = V_8 -> V_64 [ V_61 ] ;
V_63 -> V_55 = V_55 ;
V_63 -> V_65 = V_55 -> V_58 . V_57 ;
V_63 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_58 . V_57 = V_63 ;
V_55 -> V_58 . V_67 ++ ;
V_55 -> V_58 . V_68 = V_69 ;
}
static void
F_29 ( struct V_7 * V_8 , int V_60 , int V_70 )
{
struct V_54 * V_55 = V_8 -> V_55 [ V_60 ] ;
struct V_62 * V_71 = V_8 -> V_72 [ V_70 ] ;
V_71 -> V_55 = V_55 ;
V_71 -> V_65 = V_55 -> V_56 . V_57 ;
V_71 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_56 . V_57 = V_71 ;
V_55 -> V_56 . V_67 ++ ;
V_55 -> V_56 . V_68 = V_69 ;
V_55 -> V_73 ++ ;
V_55 -> V_74 |= ( 1 << V_70 ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
int V_75 ;
int V_76 = 0 ;
int V_77 = 0 , V_78 = 0 ;
int V_79 = V_8 -> V_80 -> V_81 ;
int V_82 = V_8 -> V_80 -> V_81 ;
int V_39 , V_83 ;
int V_84 , V_85 ;
int V_86 = 0 ;
V_75 = V_8 -> V_40 - V_87 ;
if ( V_75 == ( V_79 * 2 ) ) {
for (; V_77 < V_79 ; V_76 ++ , V_77 ++ )
F_28 ( V_8 , V_76 , V_77 ) ;
for (; V_78 < V_82 ; V_76 ++ , V_78 ++ )
F_29 ( V_8 , V_76 , V_78 ) ;
goto V_88;
}
for ( V_39 = V_76 ; V_39 < V_75 ; V_39 ++ ) {
V_84 = F_31 ( V_79 , V_75 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
F_28 ( V_8 , V_39 , V_77 ) ;
V_77 ++ ;
V_79 -- ;
}
}
for ( V_39 = V_76 ; V_39 < V_75 ; V_39 ++ ) {
V_85 = F_31 ( V_82 , V_75 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
F_29 ( V_8 , V_39 , V_78 ) ;
V_78 ++ ;
V_82 -- ;
}
}
V_88:
V_8 -> V_89 |= V_90 ;
return V_86 ;
}
static int
F_32 ( struct V_7 * V_8 , char * V_91 )
{
int V_34 , V_86 , V_75 ;
int V_92 = 0 , V_93 = 0 ;
F_20 ( V_8 ) ;
V_75 = V_8 -> V_40 - V_87 ;
for ( V_34 = 0 ; V_34 < V_75 ; V_34 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_34 ] ;
if ( V_55 -> V_56 . V_57 && V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_94 , sizeof( V_55 -> V_94 ) - 1 ,
L_2 , V_91 ,
L_3 , V_92 ++ ) ;
V_93 ++ ;
} else if ( V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_94 , sizeof( V_55 -> V_94 ) - 1 ,
L_2 , V_91 ,
L_4 , V_92 ++ ) ;
} else if ( V_55 -> V_56 . V_57 ) {
snprintf ( V_55 -> V_94 , sizeof( V_55 -> V_94 ) - 1 ,
L_2 , V_91 ,
L_5 , V_93 ++ ) ;
} else {
continue;
}
V_86 = F_33 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
F_26 ,
0 ,
V_55 -> V_94 ,
V_55 ) ;
if ( V_86 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_6 ,
V_95 , V_86 ) ;
goto V_96;
}
F_35 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
V_55 -> V_97 ) ;
}
return 0 ;
V_96:
while ( V_34 ) {
V_34 -- ;
F_35 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
NULL ) ;
F_36 ( V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
V_8 -> V_55 [ V_34 ] ) ;
}
return V_86 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_86 ;
sprintf ( V_8 -> V_98 , L_7 ) ;
V_86 = F_33 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_25 , 0 ,
V_8 -> V_98 , V_25 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_98 , V_86 ) ;
F_36 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
return V_86 ;
}
static void F_39 ( struct V_7 * V_8 )
{
int V_39 ;
int V_75 ;
V_75 = V_8 -> V_40 - V_87 ;
for ( V_39 = 0 ; V_39 < V_75 ; V_39 ++ ) {
F_35 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_36 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
V_8 -> V_55 [ V_39 ] ) ;
}
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
F_36 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
V_8 -> V_72 [ V_39 ] -> V_99 = V_2 -> V_100 + F_42 ( V_39 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_24 * V_25 = V_8 -> V_25 ;
int V_101 = V_25 -> V_102 + V_103 + V_104 ;
int V_39 ;
int V_105 ;
V_8 -> V_27 &= ~ V_106 ;
V_8 -> V_27 |= V_107 ;
if ( V_25 -> V_102 > V_108 ) {
if ( V_8 -> V_27 & V_106 )
V_8 -> V_27 |= V_109 ;
else
V_8 -> V_27 &= ~ V_109 ;
} else {
if ( V_8 -> V_27 & V_107 )
V_8 -> V_27 &= ~ V_109 ;
else
V_8 -> V_27 |= V_109 ;
}
if ( V_8 -> V_27 & V_109 ) {
V_105 = V_110 ;
} else {
if ( V_25 -> V_102 <= V_108 )
V_105 = V_111 ;
else
V_105 = F_2 ( V_101 , 1024 ) ;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
V_8 -> V_64 [ V_39 ] -> V_99 = V_2 -> V_100 + F_44 ( V_39 ) ;
V_8 -> V_64 [ V_39 ] -> V_105 = V_105 ;
}
}
static struct
V_112 * F_45 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
F_46 (f, &adapter->vlan_filter_list, list) {
if ( V_113 == V_114 -> V_113 )
return V_114 ;
}
return NULL ;
}
static struct
V_112 * F_47 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
V_114 = F_45 ( V_8 , V_113 ) ;
if ( NULL == V_114 ) {
V_114 = F_7 ( sizeof( * V_114 ) , V_115 ) ;
if ( NULL == V_114 )
return NULL ;
V_114 -> V_113 = V_113 ;
F_48 ( & V_114 -> V_116 ) ;
F_49 ( & V_114 -> V_116 , & V_8 -> V_117 ) ;
V_114 -> V_118 = true ;
V_8 -> V_89 |= V_119 ;
}
return V_114 ;
}
static void F_50 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
V_114 = F_45 ( V_8 , V_113 ) ;
if ( V_114 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_120 ;
}
}
static int F_51 ( struct V_24 * V_25 ,
T_8 T_9 V_121 , T_7 V_122 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( F_47 ( V_8 , V_122 ) == NULL )
return - V_123 ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 ,
T_8 T_9 V_121 , T_7 V_122 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_50 ( V_8 , V_122 ) ;
return 0 ;
}
static struct
V_124 * F_53 ( struct V_7 * V_8 ,
T_10 * V_125 )
{
struct V_124 * V_114 ;
if ( ! V_125 )
return NULL ;
F_46 (f, &adapter->mac_filter_list, list) {
if ( F_54 ( V_125 , V_114 -> V_125 ) )
return V_114 ;
}
return NULL ;
}
static struct
V_124 * F_55 ( struct V_7 * V_8 ,
T_10 * V_125 )
{
struct V_124 * V_114 ;
if ( ! V_125 )
return NULL ;
while ( F_56 ( V_126 ,
& V_8 -> V_127 ) )
F_57 ( 1 ) ;
V_114 = F_53 ( V_8 , V_125 ) ;
if ( NULL == V_114 ) {
V_114 = F_7 ( sizeof( * V_114 ) , V_115 ) ;
if ( NULL == V_114 ) {
F_58 ( V_126 ,
& V_8 -> V_127 ) ;
return NULL ;
}
F_59 ( V_114 -> V_125 , V_125 ) ;
F_49 ( & V_114 -> V_116 , & V_8 -> V_128 ) ;
V_114 -> V_118 = true ;
V_8 -> V_89 |= V_129 ;
}
F_58 ( V_126 , & V_8 -> V_127 ) ;
return V_114 ;
}
static int F_60 ( struct V_24 * V_25 , void * V_130 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_124 * V_114 ;
struct V_131 * V_132 = V_130 ;
if ( ! F_61 ( V_132 -> V_133 ) )
return - V_134 ;
if ( F_54 ( V_25 -> V_135 , V_132 -> V_133 ) )
return 0 ;
V_114 = F_55 ( V_8 , V_132 -> V_133 ) ;
if ( V_114 ) {
F_59 ( V_2 -> V_136 . V_132 , V_132 -> V_133 ) ;
F_59 ( V_25 -> V_135 , V_8 -> V_2 . V_136 . V_132 ) ;
}
return ( V_114 == NULL ) ? - V_123 : 0 ;
}
static void F_62 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_124 * V_114 , * V_137 ;
struct V_138 * V_139 ;
struct V_138 * V_140 ;
F_63 (uca, netdev) {
F_55 ( V_8 , V_139 -> V_132 ) ;
}
F_64 (mca, netdev) {
F_55 ( V_8 , V_140 -> V_132 ) ;
}
while ( F_56 ( V_126 ,
& V_8 -> V_127 ) )
F_57 ( 1 ) ;
F_65 (f, ftmp, &adapter->mac_filter_list, list) {
bool V_141 = false ;
if ( F_66 ( V_114 -> V_125 ) ) {
F_64 (mca, netdev) {
if ( F_54 ( V_140 -> V_132 , V_114 -> V_125 ) ) {
V_141 = true ;
break;
}
}
} else {
F_63 (uca, netdev) {
if ( F_54 ( V_139 -> V_132 , V_114 -> V_125 ) ) {
V_141 = true ;
break;
}
}
}
if ( V_141 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_142 ;
}
}
F_58 ( V_126 , & V_8 -> V_127 ) ;
}
static void F_67 ( struct V_7 * V_8 )
{
int V_143 ;
struct V_54 * V_55 ;
int V_75 = V_8 -> V_40 - V_87 ;
for ( V_143 = 0 ; V_143 < V_75 ; V_143 ++ ) {
struct V_144 * V_59 ;
V_55 = V_8 -> V_55 [ V_143 ] ;
V_59 = & V_55 -> V_59 ;
F_68 ( V_59 ) ;
}
}
static void F_69 ( struct V_7 * V_8 )
{
int V_143 ;
struct V_54 * V_55 ;
int V_75 = V_8 -> V_40 - V_87 ;
for ( V_143 = 0 ; V_143 < V_75 ; V_143 ++ ) {
V_55 = V_8 -> V_55 [ V_143 ] ;
F_70 ( & V_55 -> V_59 ) ;
}
}
static void F_71 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
F_62 ( V_25 ) ;
F_41 ( V_8 ) ;
F_43 ( V_8 ) ;
V_8 -> V_89 |= V_145 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
struct V_62 * V_57 = V_8 -> V_64 [ V_39 ] ;
F_72 ( V_57 , V_57 -> V_67 ) ;
V_57 -> V_146 = V_57 -> V_67 - 1 ;
F_73 ( V_57 -> V_146 , V_57 -> V_99 ) ;
}
}
static int F_74 ( struct V_7 * V_8 )
{
V_8 -> V_147 = V_148 ;
F_58 ( V_149 , & V_8 -> V_66 . V_147 ) ;
F_67 ( V_8 ) ;
V_8 -> V_89 |= V_150 ;
F_75 ( & V_8 -> V_151 , V_152 + 1 ) ;
return 0 ;
}
static void F_76 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
F_77 ( V_8 -> V_64 [ V_39 ] ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
F_79 ( V_8 -> V_72 [ V_39 ] ) ;
}
void F_80 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_124 * V_114 ;
if ( V_8 -> V_147 == V_153 )
return;
F_46 (f, &adapter->mac_filter_list, list) {
V_114 -> remove = true ;
}
F_46 (f, &adapter->vlan_filter_list, list) {
V_114 -> remove = true ;
}
if ( ! ( V_8 -> V_27 & V_154 ) &&
V_8 -> V_147 != V_155 ) {
V_8 -> V_89 |= V_142 ;
V_8 -> V_89 |= V_120 ;
V_8 -> V_89 |= V_156 ;
F_75 ( & V_8 -> V_151 , V_152 + 1 ) ;
F_81 ( 20 ) ;
}
F_82 ( V_25 ) ;
F_83 ( V_25 ) ;
F_20 ( V_8 ) ;
F_69 ( V_8 ) ;
F_84 ( V_25 ) ;
F_78 ( V_8 ) ;
F_76 ( V_8 ) ;
}
static int
F_85 ( struct V_7 * V_8 , int V_157 )
{
int V_86 , V_158 ;
V_158 = V_159 ;
V_86 = F_86 ( V_8 -> V_12 , V_8 -> V_33 ,
V_158 , V_157 ) ;
if ( V_86 < 0 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_9 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_86 ;
}
V_8 -> V_40 = V_86 ;
return 0 ;
}
static void F_87 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_80 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
if ( V_8 -> V_72 [ V_39 ] )
F_88 ( V_8 -> V_72 [ V_39 ] , V_160 ) ;
V_8 -> V_72 [ V_39 ] = NULL ;
V_8 -> V_64 [ V_39 ] = NULL ;
}
}
static int F_89 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
struct V_62 * V_71 ;
struct V_62 * V_63 ;
V_71 = F_7 ( sizeof( struct V_62 ) * 2 , V_16 ) ;
if ( ! V_71 )
goto V_161;
V_71 -> V_162 = V_39 ;
V_71 -> V_25 = V_8 -> V_25 ;
V_71 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_71 -> V_67 = V_8 -> V_163 ;
V_8 -> V_72 [ V_39 ] = V_71 ;
V_63 = & V_71 [ 1 ] ;
V_63 -> V_162 = V_39 ;
V_63 -> V_25 = V_8 -> V_25 ;
V_63 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_63 -> V_67 = V_8 -> V_164 ;
V_8 -> V_64 [ V_39 ] = V_63 ;
}
return 0 ;
V_161:
F_87 ( V_8 ) ;
return - V_123 ;
}
static int F_90 ( struct V_7 * V_8 )
{
int V_34 , V_165 ;
int V_166 = 0 ;
int V_86 = 0 ;
if ( ! V_8 -> V_80 ) {
V_86 = - V_167 ;
goto V_88;
}
V_166 = V_8 -> V_80 -> V_81 ;
V_165 = F_91 ( int , V_166 , ( int ) ( F_92 () * 2 ) ) + V_87 ;
V_165 = F_91 ( int , V_165 , ( int ) V_8 -> V_168 -> V_169 ) ;
V_8 -> V_33 = F_93 ( V_165 ,
sizeof( struct V_170 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_86 = - V_123 ;
goto V_88;
}
for ( V_34 = 0 ; V_34 < V_165 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_171 = V_34 ;
F_85 ( V_8 , V_165 ) ;
V_88:
V_8 -> V_25 -> V_172 = V_166 ;
return V_86 ;
}
static int F_94 ( struct V_7 * V_8 )
{
int V_143 , V_173 ;
struct V_54 * V_55 ;
V_173 = V_8 -> V_40 - V_87 ;
for ( V_143 = 0 ; V_143 < V_173 ; V_143 ++ ) {
V_55 = F_7 ( sizeof( struct V_54 ) , V_16 ) ;
if ( ! V_55 )
goto V_161;
V_55 -> V_8 = V_8 ;
V_55 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_60 = V_143 ;
F_95 ( V_8 -> V_25 , & V_55 -> V_59 ,
V_174 , V_175 ) ;
V_8 -> V_55 [ V_143 ] = V_55 ;
}
return 0 ;
V_161:
while ( V_143 ) {
V_143 -- ;
V_55 = V_8 -> V_55 [ V_143 ] ;
F_96 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
V_8 -> V_55 [ V_143 ] = NULL ;
}
return - V_123 ;
}
static void F_97 ( struct V_7 * V_8 )
{
int V_143 , V_173 ;
int V_176 ;
V_173 = V_8 -> V_40 - V_87 ;
V_176 = V_8 -> V_80 -> V_81 ;
for ( V_143 = 0 ; V_143 < V_173 ; V_143 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_143 ] ;
V_8 -> V_55 [ V_143 ] = NULL ;
if ( V_143 < V_176 )
F_96 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
}
}
void F_98 ( struct V_7 * V_8 )
{
F_99 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_100 ( struct V_7 * V_8 )
{
int V_86 ;
V_86 = F_90 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_10 ) ;
goto V_177;
}
V_86 = F_94 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_11 ) ;
goto V_178;
}
V_86 = F_89 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_12 ) ;
goto V_179;
}
F_34 ( & V_8 -> V_12 -> V_13 , L_13 ,
( V_8 -> V_80 -> V_81 > 1 ) ? L_14 :
L_15 , V_8 -> V_80 -> V_81 ) ;
return 0 ;
V_179:
F_97 ( V_8 ) ;
V_178:
F_98 ( V_8 ) ;
V_177:
return V_86 ;
}
static void F_101 ( unsigned long V_47 )
{
struct V_7 * V_8 = (struct V_7 * ) V_47 ;
F_14 ( & V_8 -> V_180 ) ;
}
static void F_102 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_103 ( V_182 ,
struct V_7 ,
V_180 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( F_56 ( V_126 , & V_8 -> V_127 ) )
goto V_183;
if ( V_8 -> V_27 & V_154 ) {
if ( ( F_17 ( V_2 , V_32 ) & 0x3 ) == V_184 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_16 ) ;
V_8 -> V_147 = V_185 ;
V_8 -> V_27 &= ~ V_154 ;
F_104 ( & V_8 -> V_186 , 10 ) ;
F_58 ( V_126 ,
& V_8 -> V_127 ) ;
return;
}
V_8 -> V_187 = 0 ;
V_8 -> V_89 = 0 ;
V_8 -> V_188 = V_189 ;
goto V_190;
}
if ( ( V_8 -> V_147 < V_153 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_190;
if ( ! ( V_8 -> V_27 & V_28 ) &&
( F_17 ( V_2 , V_32 ) & 0x3 ) != V_184 ) {
V_8 -> V_147 = V_155 ;
V_8 -> V_27 |= V_28 ;
F_38 ( & V_8 -> V_12 -> V_13 , L_17 ) ;
F_14 ( & V_8 -> V_30 ) ;
V_8 -> V_187 = 0 ;
V_8 -> V_89 = 0 ;
V_8 -> V_188 = V_189 ;
goto V_190;
}
if ( V_8 -> V_187 )
goto V_190;
if ( V_8 -> V_89 & V_90 ) {
F_105 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_129 ) {
F_106 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_119 ) {
F_107 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_142 ) {
F_108 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_120 ) {
F_109 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_156 ) {
F_110 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_145 ) {
F_111 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_150 ) {
F_112 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_147 == V_148 )
F_113 ( V_8 ) ;
F_24 ( V_8 , true ) ;
F_23 ( V_8 , 0xFF ) ;
V_190:
F_58 ( V_126 , & V_8 -> V_127 ) ;
V_183:
if ( V_8 -> V_89 )
F_114 ( & V_8 -> V_151 ,
V_152 + F_115 ( 20 ) ) ;
else
F_114 ( & V_8 -> V_151 , V_152 + ( V_191 * 2 ) ) ;
F_14 ( & V_8 -> V_52 ) ;
}
static int F_116 ( struct V_7 * V_8 , int V_83 )
{
V_83 += 1 ;
return V_83 >= V_8 -> V_80 -> V_81 ? 0 : V_83 ;
}
static void F_117 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_192 = 0 ;
int V_39 , V_83 ;
T_2 V_193 ;
static const T_3 V_194 [ V_195 + 1 ] = {
0x794221b4 , 0xbca0c5ab , 0x6cd5ebd9 , 0x1ada6127 ,
0x983b3aa1 , 0x1c4e71eb , 0x7f6328b2 , 0xfcdc0da0 ,
0xc135cafa , 0x7a6f7e2d , 0xe7102d28 , 0x163cd12e ,
0x4954b126 } ;
for ( V_39 = 0 ; V_39 <= V_195 ; V_39 ++ )
F_16 ( V_2 , F_118 ( V_39 ) , V_194 [ V_39 ] ) ;
V_193 = V_196 ;
F_16 ( V_2 , F_119 ( 0 ) , ( T_3 ) V_193 ) ;
F_16 ( V_2 , F_119 ( 1 ) , ( T_3 ) ( V_193 >> 32 ) ) ;
V_83 = V_8 -> V_80 -> V_81 ;
for ( V_39 = 0 ; V_39 <= V_197 ; V_39 ++ ) {
V_83 = F_116 ( V_8 , V_83 ) ;
V_192 = V_83 ;
V_83 = F_116 ( V_8 , V_83 ) ;
V_192 |= V_83 << 8 ;
V_83 = F_116 ( V_8 , V_83 ) ;
V_192 |= V_83 << 16 ;
V_83 = F_116 ( V_8 , V_83 ) ;
V_192 |= V_83 << 24 ;
F_16 ( V_2 , F_120 ( V_39 ) , V_192 ) ;
}
F_121 ( V_2 ) ;
}
static void F_122 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_103 ( V_182 ,
struct V_7 ,
V_30 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 = 0 , V_86 ;
T_5 V_198 ;
while ( F_56 ( V_126 ,
& V_8 -> V_127 ) )
F_123 ( 500 ) ;
if ( V_8 -> V_27 & V_29 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_18 ) ;
F_124 ( V_8 ) ;
}
for ( V_39 = 0 ; V_39 < V_199 ; V_39 ++ ) {
V_198 = F_17 ( V_2 , V_32 ) &
V_200 ;
if ( V_198 != V_184 )
break;
else
F_81 ( V_201 ) ;
}
if ( V_39 == V_199 ) {
V_8 -> V_27 &= ~ V_28 ;
goto V_202;
}
for ( V_39 = 0 ; V_39 < V_199 ; V_39 ++ ) {
V_198 = F_17 ( V_2 , V_32 ) &
V_200 ;
if ( V_198 == V_184 )
break;
else
F_81 ( V_201 ) ;
}
if ( V_39 == V_199 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_19 ,
V_198 ) ;
V_8 -> V_27 |= V_154 ;
if ( F_125 ( V_8 -> V_25 ) ) {
F_126 ( V_149 , & V_8 -> V_66 . V_147 ) ;
F_80 ( V_8 ) ;
F_39 ( V_8 ) ;
F_127 ( V_8 ) ;
F_128 ( V_8 ) ;
}
F_40 ( V_8 ) ;
F_98 ( V_8 ) ;
F_87 ( V_8 ) ;
F_9 ( V_8 -> V_168 ) ;
F_129 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_203 ;
F_58 ( V_126 , & V_8 -> V_127 ) ;
return;
}
V_202:
V_8 -> V_27 &= ~ V_28 ;
F_80 ( V_8 ) ;
V_8 -> V_147 = V_155 ;
if ( F_129 ( V_2 ) )
F_130 ( & V_8 -> V_12 -> V_13 ,
L_20 ,
V_95 ) ;
V_86 = F_131 ( V_2 ) ;
if ( V_86 )
F_34 ( & V_8 -> V_12 -> V_13 , L_21 ,
V_95 , V_86 ) ;
V_8 -> V_187 = 0 ;
V_8 -> V_89 = 0 ;
F_105 ( V_8 ) ;
F_58 ( V_126 , & V_8 -> V_127 ) ;
F_114 ( & V_8 -> V_151 , V_152 + 2 ) ;
if ( F_125 ( V_8 -> V_25 ) ) {
V_86 = F_132 ( V_8 ) ;
if ( V_86 )
goto V_204;
V_86 = F_133 ( V_8 ) ;
if ( V_86 )
goto V_204;
F_71 ( V_8 ) ;
V_86 = F_74 ( V_8 ) ;
if ( V_86 )
goto V_204;
F_24 ( V_8 , true ) ;
}
return;
V_204:
F_38 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_134 ( V_8 -> V_25 ) ;
}
static void F_135 ( struct V_181 * V_182 )
{
struct V_7 * V_8 =
F_103 ( V_182 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_205 V_206 ;
struct V_207 * V_208 ;
T_1 V_209 ;
T_3 V_48 , V_210 ;
T_7 V_211 ;
if ( V_8 -> V_27 & V_154 )
return;
V_206 . V_212 = V_213 ;
V_206 . V_214 = F_7 ( V_206 . V_212 , V_16 ) ;
if ( ! V_206 . V_214 )
return;
V_208 = (struct V_207 * ) & V_206 . V_215 ;
do {
V_209 = F_136 ( V_2 , & V_206 , & V_211 ) ;
if ( V_209 )
break;
F_137 ( V_8 , V_208 -> V_216 ,
V_208 -> V_217 , V_206 . V_214 ,
V_206 . V_212 ) ;
if ( V_211 != 0 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_23 ,
V_95 , V_211 ) ;
memset ( V_206 . V_214 , 0 , V_213 ) ;
}
} while ( V_211 );
V_48 = F_17 ( V_2 , V_2 -> V_218 . V_219 . V_220 ) ;
V_210 = V_48 ;
if ( V_48 & V_221 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
V_48 &= ~ V_221 ;
}
if ( V_48 & V_222 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
V_48 &= ~ V_222 ;
}
if ( V_48 & V_223 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
V_48 &= ~ V_223 ;
}
if ( V_210 != V_48 )
F_16 ( V_2 , V_2 -> V_218 . V_219 . V_220 , V_48 ) ;
V_48 = F_17 ( V_2 , V_2 -> V_218 . V_224 . V_220 ) ;
V_210 = V_48 ;
if ( V_48 & V_225 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
V_48 &= ~ V_225 ;
}
if ( V_48 & V_226 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_48 &= ~ V_226 ;
}
if ( V_48 & V_227 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_48 &= ~ V_227 ;
}
if ( V_210 != V_48 )
F_16 ( V_2 , V_2 -> V_218 . V_224 . V_220 , V_48 ) ;
F_19 ( V_8 ) ;
F_9 ( V_206 . V_214 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
if ( V_8 -> V_72 [ V_39 ] -> V_215 )
F_138 ( V_8 -> V_72 [ V_39 ] ) ;
}
static int F_132 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
V_8 -> V_72 [ V_39 ] -> V_67 = V_8 -> V_163 ;
V_86 = F_139 ( V_8 -> V_72 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_30 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
static int F_133 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
V_8 -> V_64 [ V_39 ] -> V_67 = V_8 -> V_164 ;
V_86 = F_140 ( V_8 -> V_64 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_31 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
static void F_128 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
if ( V_8 -> V_64 [ V_39 ] -> V_215 )
F_141 ( V_8 -> V_64 [ V_39 ] ) ;
}
static int F_142 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_86 ;
if ( V_8 -> V_27 & V_154 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
return - V_167 ;
}
if ( V_8 -> V_147 != V_153 )
return - V_228 ;
V_86 = F_132 ( V_8 ) ;
if ( V_86 )
goto V_229;
V_86 = F_133 ( V_8 ) ;
if ( V_86 )
goto V_230;
V_86 = F_32 ( V_8 , V_25 -> V_94 ) ;
if ( V_86 )
goto V_231;
F_71 ( V_8 ) ;
V_86 = F_74 ( V_8 ) ;
if ( V_86 )
goto V_231;
F_24 ( V_8 , true ) ;
return 0 ;
V_231:
F_80 ( V_8 ) ;
F_39 ( V_8 ) ;
V_230:
F_128 ( V_8 ) ;
V_229:
F_127 ( V_8 ) ;
return V_86 ;
}
static int F_134 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_147 <= V_153 )
return 0 ;
F_126 ( V_149 , & V_8 -> V_66 . V_147 ) ;
F_80 ( V_8 ) ;
V_8 -> V_147 = V_153 ;
F_39 ( V_8 ) ;
F_127 ( V_8 ) ;
F_128 ( V_8 ) ;
return 0 ;
}
static struct V_232 * F_143 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_233 ;
}
void F_144 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_86 ;
F_145 ( F_146 () ) ;
F_80 ( V_8 ) ;
V_86 = F_132 ( V_8 ) ;
if ( V_86 )
goto V_234;
V_86 = F_133 ( V_8 ) ;
if ( V_86 )
goto V_234;
F_71 ( V_8 ) ;
V_86 = F_74 ( V_8 ) ;
if ( V_86 )
goto V_234;
F_24 ( V_8 , true ) ;
return;
V_234:
F_38 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_134 ( V_25 ) ;
}
static int F_147 ( struct V_24 * V_25 , int V_235 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_101 = V_235 + V_103 + V_104 ;
if ( ( V_235 < 68 ) || ( V_101 > V_236 ) )
return - V_237 ;
V_25 -> V_102 = V_235 ;
F_144 ( V_8 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
T_3 V_238 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_238 = F_17 ( V_2 , V_32 ) ;
if ( V_238 == V_184 )
return 0 ;
F_123 ( 10 ) ;
}
return - V_228 ;
}
static void F_149 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_103 ( V_182 ,
struct V_7 ,
V_186 . V_182 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_124 * V_114 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_239 * V_12 = V_8 -> V_12 ;
int V_39 , V_86 , V_240 ;
switch ( V_8 -> V_147 ) {
case V_185 :
V_8 -> V_27 &= ~ V_154 ;
V_8 -> V_27 &= ~ V_28 ;
V_86 = F_150 ( V_2 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_33 ,
V_86 ) ;
goto V_86;
}
V_86 = F_148 ( V_2 ) ;
if ( V_86 ) {
F_34 ( & V_12 -> V_13 , L_34 ,
V_86 ) ;
goto V_86;
}
V_2 -> V_218 . V_241 = V_242 ;
V_2 -> V_218 . V_243 = V_242 ;
V_2 -> V_218 . V_244 = V_213 ;
V_2 -> V_218 . V_245 = V_213 ;
V_86 = F_131 ( V_2 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_35 ,
V_86 ) ;
goto V_86;
}
V_86 = F_151 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_36 , V_86 ) ;
F_129 ( V_2 ) ;
goto V_86;
}
V_8 -> V_147 = V_246 ;
goto V_247;
break;
case V_246 :
if ( ! F_152 ( V_2 ) ) {
F_38 ( & V_12 -> V_13 , L_37 ) ;
goto V_86;
}
V_86 = F_153 ( V_8 ) ;
if ( V_86 ) {
F_34 ( & V_12 -> V_13 , L_38 ,
V_86 ) ;
goto V_86;
}
V_86 = F_154 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_39 ,
V_86 ) ;
goto V_86;
}
V_8 -> V_147 = V_248 ;
goto V_247;
break;
case V_248 :
if ( ! V_8 -> V_168 ) {
V_240 = sizeof( struct V_249 ) +
( V_250 *
sizeof( struct V_251 ) ) ;
V_8 -> V_168 = F_7 ( V_240 , V_16 ) ;
if ( ! V_8 -> V_168 )
goto V_86;
}
V_86 = F_155 ( V_8 ) ;
if ( V_86 == V_252 )
goto V_247;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_40 ,
V_86 ) ;
goto V_253;
}
V_8 -> V_147 = V_254 ;
break;
default:
goto V_253;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_168 -> V_255 ; V_39 ++ ) {
if ( V_8 -> V_168 -> V_80 [ V_39 ] . V_256 == V_257 )
V_8 -> V_80 = & V_8 -> V_168 -> V_80 [ V_39 ] ;
}
if ( ! V_8 -> V_80 ) {
F_38 ( & V_12 -> V_13 , L_41 ) ;
goto V_253;
}
V_8 -> V_27 |= V_258 ;
V_25 -> V_259 = & V_260 ;
F_156 ( V_25 ) ;
V_25 -> V_261 = 5 * V_191 ;
V_25 -> V_262 |= V_263 |
V_264 |
V_265 |
V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 ;
if ( V_8 -> V_168 -> V_272
& V_273 ) {
V_25 -> V_274 = V_25 -> V_262 ;
V_25 -> V_262 |= V_275 |
V_276 |
V_277 ;
}
V_25 -> V_278 |= V_25 -> V_262 ;
V_25 -> V_278 &= ~ V_270 ;
if ( ! F_61 ( V_8 -> V_2 . V_136 . V_132 ) ) {
F_34 ( & V_12 -> V_13 , L_42 ,
V_8 -> V_2 . V_136 . V_132 ) ;
F_157 ( V_8 -> V_2 . V_136 . V_132 ) ;
}
F_59 ( V_25 -> V_135 , V_8 -> V_2 . V_136 . V_132 ) ;
F_59 ( V_25 -> V_279 , V_8 -> V_2 . V_136 . V_132 ) ;
F_48 ( & V_8 -> V_128 ) ;
F_48 ( & V_8 -> V_117 ) ;
V_114 = F_7 ( sizeof( * V_114 ) , V_115 ) ;
if ( NULL == V_114 )
goto V_280;
F_59 ( V_114 -> V_125 , V_8 -> V_2 . V_136 . V_132 ) ;
V_114 -> V_118 = true ;
V_8 -> V_89 |= V_129 ;
F_49 ( & V_114 -> V_116 , & V_8 -> V_128 ) ;
F_158 ( & V_8 -> V_151 ) ;
V_8 -> V_151 . V_281 = & F_101 ;
V_8 -> V_151 . V_47 = ( unsigned long ) V_8 ;
F_114 ( & V_8 -> V_151 , V_152 + 1 ) ;
V_8 -> V_163 = V_282 ;
V_8 -> V_164 = V_283 ;
V_86 = F_100 ( V_8 ) ;
if ( V_86 )
goto V_280;
F_30 ( V_8 ) ;
F_117 ( V_8 ) ;
V_86 = F_37 ( V_8 ) ;
if ( V_86 )
goto V_280;
F_84 ( V_25 ) ;
V_8 -> V_66 . V_284 = V_8 -> V_80 -> V_285 ;
V_8 -> V_66 . V_286 = V_8 -> V_80 -> V_285 ;
V_8 -> V_66 . V_9 = V_8 ;
V_8 -> V_66 . V_287 = 1 ;
V_8 -> V_66 . V_288 = V_289 ;
V_8 -> V_66 . V_290 = ( V_291 |
F_159 ( V_292 ) ) ;
V_8 -> V_66 . V_293 = ( V_291 |
F_159 ( V_294 ) ) ;
V_8 -> V_66 . V_25 = V_8 -> V_25 ;
if ( ! V_8 -> V_295 ) {
V_86 = F_160 ( V_25 ) ;
if ( V_86 )
goto V_296;
}
V_8 -> V_295 = true ;
F_83 ( V_25 ) ;
F_34 ( & V_12 -> V_13 , L_43 , V_8 -> V_2 . V_136 . V_132 ) ;
if ( V_25 -> V_262 & V_271 )
F_34 ( & V_12 -> V_13 , L_44 ) ;
F_34 ( & V_12 -> V_13 , L_45 , V_297 ) ;
V_8 -> V_147 = V_153 ;
F_126 ( V_149 , & V_8 -> V_66 . V_147 ) ;
F_19 ( V_8 ) ;
return;
V_247:
F_104 ( & V_8 -> V_186 ,
F_115 ( 50 ) ) ;
return;
V_296:
F_40 ( V_8 ) ;
V_280:
F_98 ( V_8 ) ;
V_253:
F_9 ( V_8 -> V_168 ) ;
V_8 -> V_168 = NULL ;
V_86:
if ( ++ V_8 -> V_298 > V_299 ) {
F_38 ( & V_12 -> V_13 , L_46 ) ;
V_8 -> V_27 |= V_154 ;
return;
}
F_104 ( & V_8 -> V_186 , V_191 * 3 ) ;
}
static void F_161 ( struct V_239 * V_12 )
{
struct V_24 * V_25 = F_162 ( V_12 ) ;
F_163 ( V_25 ) ;
if ( F_125 ( V_25 ) )
F_134 ( V_25 ) ;
#ifdef F_164
F_165 ( V_12 ) ;
#endif
F_166 ( V_12 ) ;
}
static int F_167 ( struct V_239 * V_12 , const struct V_300 * V_301 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_86 ;
V_86 = F_168 ( V_12 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_169 ( & V_12 -> V_13 , F_170 ( 64 ) ) ;
if ( V_86 ) {
V_86 = F_169 ( & V_12 -> V_13 , F_170 ( 32 ) ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 ,
L_47 , V_86 ) ;
goto V_302;
}
}
V_86 = F_171 ( V_12 , V_303 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 ,
L_48 , V_86 ) ;
goto V_304;
}
F_172 ( V_12 ) ;
F_173 ( V_12 ) ;
V_25 = F_174 ( sizeof( struct V_7 ) ,
V_305 ) ;
if ( ! V_25 ) {
V_86 = - V_123 ;
goto V_306;
}
F_175 ( V_25 , & V_12 -> V_13 ) ;
F_176 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_307 = ( 1 << V_308 ) - 1 ;
V_8 -> V_147 = V_185 ;
F_165 ( V_12 ) ;
V_2 -> V_100 = F_177 ( F_178 ( V_12 , 0 ) ,
F_179 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_100 ) {
V_86 = - V_167 ;
goto V_309;
}
V_2 -> V_310 = V_12 -> V_311 ;
V_2 -> V_312 = V_12 -> V_313 ;
F_180 ( V_12 , V_314 , & V_2 -> V_315 ) ;
V_2 -> V_316 = V_12 -> V_317 ;
V_2 -> V_318 = V_12 -> V_319 ;
V_2 -> V_320 . V_313 = F_181 ( V_12 -> V_321 ) ;
V_2 -> V_320 . V_322 = F_182 ( V_12 -> V_321 ) ;
F_183 ( & V_8 -> V_30 , F_122 ) ;
F_183 ( & V_8 -> V_52 , F_135 ) ;
F_183 ( & V_8 -> V_180 , F_102 ) ;
F_184 ( & V_8 -> V_186 , F_149 ) ;
F_104 ( & V_8 -> V_186 , 10 ) ;
return 0 ;
V_309:
F_185 ( V_25 ) ;
V_306:
F_186 ( V_12 ) ;
V_304:
V_302:
F_166 ( V_12 ) ;
return V_86 ;
}
static int F_187 ( struct V_239 * V_12 , T_11 V_147 )
{
struct V_24 * V_25 = F_162 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_323 = 0 ;
F_163 ( V_25 ) ;
if ( F_125 ( V_25 ) ) {
F_188 () ;
F_80 ( V_8 ) ;
F_189 () ;
}
F_40 ( V_8 ) ;
F_98 ( V_8 ) ;
V_323 = F_165 ( V_12 ) ;
if ( V_323 )
return V_323 ;
F_166 ( V_12 ) ;
return 0 ;
}
static int F_190 ( struct V_239 * V_12 )
{
struct V_7 * V_8 = F_162 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_86 ;
F_191 ( V_12 , V_324 ) ;
F_192 ( V_12 ) ;
F_165 ( V_12 ) ;
V_86 = F_193 ( V_12 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_49 ) ;
return V_86 ;
}
F_173 ( V_12 ) ;
F_188 () ;
V_86 = F_90 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_50 ) ;
return V_86 ;
}
V_86 = F_37 ( V_8 ) ;
F_189 () ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_51 ) ;
return V_86 ;
}
F_14 ( & V_8 -> V_30 ) ;
F_194 ( V_25 ) ;
return V_86 ;
}
static void F_195 ( struct V_239 * V_12 )
{
struct V_24 * V_25 = F_162 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_196 ( & V_8 -> V_186 ) ;
F_197 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_295 ) {
F_198 ( V_25 ) ;
V_8 -> V_295 = false ;
}
V_8 -> V_147 = V_325 ;
if ( V_8 -> V_33 ) {
F_15 ( V_8 ) ;
F_40 ( V_8 ) ;
F_98 ( V_8 ) ;
}
F_199 ( & V_8 -> V_151 ) ;
F_200 () ;
if ( V_2 -> V_218 . V_224 . V_67 )
F_129 ( V_2 ) ;
F_201 ( V_2 -> V_100 ) ;
F_186 ( V_12 ) ;
F_87 ( V_8 ) ;
F_9 ( V_8 -> V_168 ) ;
F_185 ( V_25 ) ;
F_202 ( V_12 ) ;
F_166 ( V_12 ) ;
}
static int T_12 F_203 ( void )
{
int V_209 ;
F_11 ( L_52 , V_297 ,
V_326 ) ;
F_11 ( L_45 , V_327 ) ;
V_209 = F_204 ( & V_328 ) ;
return V_209 ;
}
static void T_13 F_205 ( void )
{
F_206 ( & V_328 ) ;
}
