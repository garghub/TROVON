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
F_14 ( & V_8 -> V_12 -> V_13 , L_2 ) ;
if ( ! ( V_8 -> V_27 & V_28 ) ) {
V_8 -> V_27 |= V_29 ;
F_15 ( & V_8 -> V_30 ) ;
}
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_17 ( V_2 , V_31 , 0 ) ;
F_18 ( V_2 , V_32 ) ;
F_19 ( V_8 -> V_33 [ 0 ] . V_34 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_17 ( V_2 , V_31 , V_35 |
V_36 ) ;
F_17 ( V_2 , V_37 , V_38 ) ;
F_18 ( V_2 , V_32 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
int V_39 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( ! V_8 -> V_33 )
return;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
F_17 ( V_2 , F_22 ( V_39 - 1 ) , 0 ) ;
F_19 ( V_8 -> V_33 [ V_39 ] . V_34 ) ;
}
F_18 ( V_2 , V_32 ) ;
}
void F_23 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & ( 1 << ( V_39 - 1 ) ) ) {
F_17 ( V_2 , F_22 ( V_39 - 1 ) ,
V_41 |
V_42 ) ;
}
}
}
static void F_24 ( struct V_7 * V_8 ,
T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
T_5 V_43 ;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & ( 1 << V_39 ) ) {
V_43 = F_18 ( V_2 , F_22 ( V_39 - 1 ) ) ;
V_43 |= V_44 |
V_42 ;
F_17 ( V_2 , F_22 ( V_39 - 1 ) , V_43 ) ;
}
}
}
void F_25 ( struct V_7 * V_8 , bool V_45 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_23 ( V_8 , ~ 0 ) ;
if ( V_45 )
F_18 ( V_2 , V_32 ) ;
}
static T_6 F_26 ( int V_46 , void * V_47 )
{
struct V_24 * V_25 = V_47 ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_48 ;
T_3 V_49 ;
V_48 = F_18 ( V_2 , V_50 ) ;
V_49 = F_18 ( V_2 , V_37 ) ;
V_48 = F_18 ( V_2 , V_31 ) ;
V_48 = V_48 | V_51 ;
F_17 ( V_2 , V_31 , V_48 ) ;
F_17 ( V_2 , V_37 , V_49 ) ;
F_17 ( V_2 , V_31 , V_35 ) ;
F_15 ( & V_8 -> V_52 ) ;
return V_53 ;
}
static T_6 F_27 ( int V_46 , void * V_47 )
{
struct V_54 * V_55 = V_47 ;
if ( ! V_55 -> V_56 . V_57 && ! V_55 -> V_58 . V_57 )
return V_53 ;
F_28 ( & V_55 -> V_59 ) ;
return V_53 ;
}
static void
F_29 ( struct V_7 * V_8 , int V_60 , int V_61 )
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
F_30 ( struct V_7 * V_8 , int V_60 , int V_70 )
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
static int F_31 ( struct V_7 * V_8 )
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
F_29 ( V_8 , V_76 , V_77 ) ;
for (; V_78 < V_82 ; V_76 ++ , V_78 ++ )
F_30 ( V_8 , V_76 , V_78 ) ;
goto V_88;
}
for ( V_39 = V_76 ; V_39 < V_75 ; V_39 ++ ) {
V_84 = F_32 ( V_79 , V_75 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
F_29 ( V_8 , V_39 , V_77 ) ;
V_77 ++ ;
V_79 -- ;
}
}
for ( V_39 = V_76 ; V_39 < V_75 ; V_39 ++ ) {
V_85 = F_32 ( V_82 , V_75 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
F_30 ( V_8 , V_39 , V_78 ) ;
V_78 ++ ;
V_82 -- ;
}
}
V_88:
V_8 -> V_89 |= V_90 ;
return V_86 ;
}
static int
F_33 ( struct V_7 * V_8 , char * V_91 )
{
int V_34 , V_86 , V_75 ;
int V_92 = 0 , V_93 = 0 ;
F_21 ( V_8 ) ;
V_75 = V_8 -> V_40 - V_87 ;
for ( V_34 = 0 ; V_34 < V_75 ; V_34 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_34 ] ;
if ( V_55 -> V_56 . V_57 && V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_94 , sizeof( V_55 -> V_94 ) - 1 ,
L_3 , V_91 ,
L_4 , V_92 ++ ) ;
V_93 ++ ;
} else if ( V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_94 , sizeof( V_55 -> V_94 ) - 1 ,
L_3 , V_91 ,
L_5 , V_92 ++ ) ;
} else if ( V_55 -> V_56 . V_57 ) {
snprintf ( V_55 -> V_94 , sizeof( V_55 -> V_94 ) - 1 ,
L_3 , V_91 ,
L_6 , V_93 ++ ) ;
} else {
continue;
}
V_86 = F_34 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
F_27 ,
0 ,
V_55 -> V_94 ,
V_55 ) ;
if ( V_86 ) {
F_14 ( & V_8 -> V_12 -> V_13 ,
L_7 ,
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
sprintf ( V_8 -> V_98 , L_8 ) ;
V_86 = F_34 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_26 , 0 ,
V_8 -> V_98 , V_25 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_9 ,
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
if ( NULL == V_114 ) {
F_14 ( & V_8 -> V_12 -> V_13 ,
L_10 ,
V_95 ) ;
return NULL ;
}
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
return;
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
F_14 ( & V_8 -> V_12 -> V_13 ,
L_11 , V_95 ) ;
F_58 ( V_126 ,
& V_8 -> V_127 ) ;
return NULL ;
}
memcpy ( V_114 -> V_125 , V_125 , V_128 ) ;
F_49 ( & V_114 -> V_116 , & V_8 -> V_129 ) ;
V_114 -> V_118 = true ;
V_8 -> V_89 |= V_130 ;
}
F_58 ( V_126 , & V_8 -> V_127 ) ;
return V_114 ;
}
static int F_59 ( struct V_24 * V_25 , void * V_131 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_124 * V_114 ;
struct V_132 * V_133 = V_131 ;
if ( ! F_60 ( V_133 -> V_134 ) )
return - V_135 ;
if ( F_54 ( V_25 -> V_136 , V_133 -> V_134 ) )
return 0 ;
V_114 = F_55 ( V_8 , V_133 -> V_134 ) ;
if ( V_114 ) {
memcpy ( V_2 -> V_137 . V_133 , V_133 -> V_134 , V_25 -> V_138 ) ;
memcpy ( V_25 -> V_136 , V_8 -> V_2 . V_137 . V_133 ,
V_25 -> V_138 ) ;
}
return ( V_114 == NULL ) ? - V_123 : 0 ;
}
static void F_61 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_124 * V_114 , * V_139 ;
struct V_140 * V_141 ;
struct V_140 * V_142 ;
F_62 (uca, netdev) {
F_55 ( V_8 , V_141 -> V_133 ) ;
}
F_63 (mca, netdev) {
F_55 ( V_8 , V_142 -> V_133 ) ;
}
while ( F_56 ( V_126 ,
& V_8 -> V_127 ) )
F_57 ( 1 ) ;
F_64 (f, ftmp, &adapter->mac_filter_list, list) {
bool V_143 = false ;
if ( V_114 -> V_125 [ 0 ] & 0x01 ) {
F_63 (mca, netdev) {
if ( F_54 ( V_142 -> V_133 , V_114 -> V_125 ) ) {
V_143 = true ;
break;
}
}
} else {
F_62 (uca, netdev) {
if ( F_54 ( V_141 -> V_133 , V_114 -> V_125 ) ) {
V_143 = true ;
break;
}
}
}
if ( V_143 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_144 ;
}
}
F_58 ( V_126 , & V_8 -> V_127 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
int V_145 ;
struct V_54 * V_55 ;
int V_75 = V_8 -> V_40 - V_87 ;
for ( V_145 = 0 ; V_145 < V_75 ; V_145 ++ ) {
struct V_146 * V_59 ;
V_55 = V_8 -> V_55 [ V_145 ] ;
V_59 = & V_55 -> V_59 ;
F_66 ( V_59 ) ;
}
}
static void F_67 ( struct V_7 * V_8 )
{
int V_145 ;
struct V_54 * V_55 ;
int V_75 = V_8 -> V_40 - V_87 ;
for ( V_145 = 0 ; V_145 < V_75 ; V_145 ++ ) {
V_55 = V_8 -> V_55 [ V_145 ] ;
F_68 ( & V_55 -> V_59 ) ;
}
}
static void F_69 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
F_61 ( V_25 ) ;
F_41 ( V_8 ) ;
F_43 ( V_8 ) ;
V_8 -> V_89 |= V_147 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
struct V_62 * V_57 = V_8 -> V_64 [ V_39 ] ;
F_70 ( V_57 , V_57 -> V_67 ) ;
V_57 -> V_148 = V_57 -> V_67 - 1 ;
F_71 ( V_57 -> V_148 , V_57 -> V_99 ) ;
}
}
static int F_72 ( struct V_7 * V_8 )
{
V_8 -> V_149 = V_150 ;
F_58 ( V_151 , & V_8 -> V_66 . V_149 ) ;
F_65 ( V_8 ) ;
V_8 -> V_89 |= V_152 ;
F_73 ( & V_8 -> V_153 , V_154 + 1 ) ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
F_75 ( V_8 -> V_64 [ V_39 ] ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
F_77 ( V_8 -> V_72 [ V_39 ] ) ;
}
void F_78 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_124 * V_114 ;
F_46 (f, &adapter->mac_filter_list, list) {
V_114 -> remove = true ;
}
F_46 (f, &adapter->vlan_filter_list, list) {
V_114 -> remove = true ;
}
if ( ! ( V_8 -> V_27 & V_155 ) &&
V_8 -> V_149 != V_156 ) {
V_8 -> V_89 |= V_144 ;
V_8 -> V_89 |= V_120 ;
V_8 -> V_89 |= V_157 ;
F_73 ( & V_8 -> V_153 , V_154 + 1 ) ;
F_79 ( 20 ) ;
}
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_21 ( V_8 ) ;
F_67 ( V_8 ) ;
F_82 ( V_25 ) ;
F_76 ( V_8 ) ;
F_74 ( V_8 ) ;
}
static int
F_83 ( struct V_7 * V_8 , int V_158 )
{
int V_86 , V_159 ;
V_159 = V_160 ;
while ( V_158 >= V_159 ) {
V_86 = F_84 ( V_8 -> V_12 , V_8 -> V_33 ,
V_158 ) ;
if ( ! V_86 )
break;
else if ( V_86 < 0 )
V_158 = 0 ;
else
V_158 = V_86 ;
}
if ( V_158 < V_159 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
V_86 = - V_161 ;
} else {
V_8 -> V_40 = V_158 ;
}
return V_86 ;
}
static void F_85 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_80 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
if ( V_8 -> V_72 [ V_39 ] )
F_86 ( V_8 -> V_72 [ V_39 ] , V_162 ) ;
V_8 -> V_72 [ V_39 ] = NULL ;
V_8 -> V_64 [ V_39 ] = NULL ;
}
}
static int F_87 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
struct V_62 * V_71 ;
struct V_62 * V_63 ;
V_71 = F_7 ( sizeof( struct V_62 ) * 2 , V_16 ) ;
if ( ! V_71 )
goto V_163;
V_71 -> V_164 = V_39 ;
V_71 -> V_25 = V_8 -> V_25 ;
V_71 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_71 -> V_67 = V_165 ;
V_8 -> V_72 [ V_39 ] = V_71 ;
V_63 = & V_71 [ 1 ] ;
V_63 -> V_164 = V_39 ;
V_63 -> V_25 = V_8 -> V_25 ;
V_63 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_63 -> V_67 = V_166 ;
V_8 -> V_64 [ V_39 ] = V_63 ;
}
return 0 ;
V_163:
F_85 ( V_8 ) ;
return - V_123 ;
}
static int F_88 ( struct V_7 * V_8 )
{
int V_34 , V_167 ;
int V_168 = 0 ;
int V_86 = 0 ;
if ( ! V_8 -> V_80 ) {
V_86 = - V_161 ;
goto V_88;
}
V_168 = V_8 -> V_80 -> V_81 ;
V_167 = F_89 ( int , V_168 , ( int ) ( F_90 () * 2 ) ) + V_87 ;
V_167 = F_89 ( int , V_167 , ( int ) V_8 -> V_169 -> V_170 ) ;
V_8 -> V_33 = F_91 ( V_167 ,
sizeof( struct V_171 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_86 = - V_123 ;
goto V_88;
}
for ( V_34 = 0 ; V_34 < V_167 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_172 = V_34 ;
F_83 ( V_8 , V_167 ) ;
V_88:
V_8 -> V_25 -> V_173 = V_168 ;
return V_86 ;
}
static int F_92 ( struct V_7 * V_8 )
{
int V_145 , V_174 ;
struct V_54 * V_55 ;
V_174 = V_8 -> V_40 - V_87 ;
for ( V_145 = 0 ; V_145 < V_174 ; V_145 ++ ) {
V_55 = F_7 ( sizeof( struct V_54 ) , V_16 ) ;
if ( ! V_55 )
goto V_163;
V_55 -> V_8 = V_8 ;
V_55 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_60 = V_145 ;
F_93 ( V_8 -> V_25 , & V_55 -> V_59 ,
V_175 , 64 ) ;
V_8 -> V_55 [ V_145 ] = V_55 ;
}
return 0 ;
V_163:
while ( V_145 ) {
V_145 -- ;
V_55 = V_8 -> V_55 [ V_145 ] ;
F_94 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
V_8 -> V_55 [ V_145 ] = NULL ;
}
return - V_123 ;
}
static void F_95 ( struct V_7 * V_8 )
{
int V_145 , V_174 ;
int V_176 ;
V_174 = V_8 -> V_40 - V_87 ;
V_176 = V_8 -> V_80 -> V_81 ;
for ( V_145 = 0 ; V_145 < V_174 ; V_145 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_145 ] ;
V_8 -> V_55 [ V_145 ] = NULL ;
if ( V_145 < V_176 )
F_94 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
}
}
void F_96 ( struct V_7 * V_8 )
{
F_97 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return;
}
int F_98 ( struct V_7 * V_8 )
{
int V_86 ;
V_86 = F_88 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_13 ) ;
goto V_177;
}
V_86 = F_92 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_178;
}
V_86 = F_87 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_179;
}
F_14 ( & V_8 -> V_12 -> V_13 , L_16 ,
( V_8 -> V_80 -> V_81 > 1 ) ? L_17 :
L_18 , V_8 -> V_80 -> V_81 ) ;
return 0 ;
V_179:
F_95 ( V_8 ) ;
V_178:
F_96 ( V_8 ) ;
V_177:
return V_86 ;
}
static void F_99 ( unsigned long V_47 )
{
struct V_7 * V_8 = (struct V_7 * ) V_47 ;
F_15 ( & V_8 -> V_180 ) ;
}
static void F_100 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_101 ( V_182 ,
struct V_7 ,
V_180 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( F_56 ( V_126 , & V_8 -> V_127 ) )
goto V_183;
if ( V_8 -> V_27 & V_155 ) {
F_14 ( & V_8 -> V_12 -> V_13 , L_19 ) ;
if ( ( F_18 ( V_2 , V_32 ) & 0x3 ) == V_184 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_149 = V_185 ;
V_8 -> V_27 &= ~ V_155 ;
F_102 ( & V_8 -> V_186 , 10 ) ;
F_58 ( V_126 ,
& V_8 -> V_127 ) ;
return;
}
V_8 -> V_187 = 0 ;
V_8 -> V_89 = 0 ;
V_8 -> V_188 = V_189 ;
goto V_190;
}
if ( ( V_8 -> V_149 < V_191 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_190;
if ( ! ( V_8 -> V_27 & V_28 ) &&
( F_18 ( V_2 , V_32 ) & 0x3 ) != V_184 ) {
V_8 -> V_149 = V_156 ;
V_8 -> V_27 |= V_28 ;
F_38 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_14 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_15 ( & V_8 -> V_30 ) ;
V_8 -> V_187 = 0 ;
V_8 -> V_89 = 0 ;
V_8 -> V_188 = V_189 ;
goto V_190;
}
if ( V_8 -> V_187 )
goto V_190;
if ( V_8 -> V_89 & V_90 ) {
F_103 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_130 ) {
F_104 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_119 ) {
F_105 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_144 ) {
F_106 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_120 ) {
F_107 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_157 ) {
F_108 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_147 ) {
F_109 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_89 & V_152 ) {
F_110 ( V_8 ) ;
goto V_190;
}
if ( V_8 -> V_149 == V_150 )
F_111 ( V_8 ) ;
F_25 ( V_8 , true ) ;
F_24 ( V_8 , 0xFF ) ;
V_190:
F_58 ( V_126 , & V_8 -> V_127 ) ;
V_183:
if ( V_8 -> V_89 )
F_112 ( & V_8 -> V_153 ,
V_154 + F_113 ( 20 ) ) ;
else
F_112 ( & V_8 -> V_153 , V_154 + ( V_192 * 2 ) ) ;
F_15 ( & V_8 -> V_52 ) ;
}
static int F_114 ( struct V_7 * V_8 , int V_83 )
{
V_83 += 1 ;
return V_83 >= V_8 -> V_80 -> V_81 ? 0 : V_83 ;
}
static void F_115 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_193 = 0 ;
int V_39 , V_83 ;
T_2 V_194 ;
static const T_3 V_195 [ V_196 + 1 ] = {
0x794221b4 , 0xbca0c5ab , 0x6cd5ebd9 , 0x1ada6127 ,
0x983b3aa1 , 0x1c4e71eb , 0x7f6328b2 , 0xfcdc0da0 ,
0xc135cafa , 0x7a6f7e2d , 0xe7102d28 , 0x163cd12e ,
0x4954b126 } ;
for ( V_39 = 0 ; V_39 <= V_196 ; V_39 ++ )
F_17 ( V_2 , F_116 ( V_39 ) , V_195 [ V_39 ] ) ;
V_194 = V_197 ;
F_17 ( V_2 , F_117 ( 0 ) , ( T_3 ) V_194 ) ;
F_17 ( V_2 , F_117 ( 1 ) , ( T_3 ) ( V_194 >> 32 ) ) ;
V_83 = V_8 -> V_80 -> V_81 ;
for ( V_39 = 0 ; V_39 <= V_198 ; V_39 ++ ) {
V_83 = F_114 ( V_8 , V_83 ) ;
V_193 = V_83 ;
V_83 = F_114 ( V_8 , V_83 ) ;
V_193 |= V_83 << 8 ;
V_83 = F_114 ( V_8 , V_83 ) ;
V_193 |= V_83 << 16 ;
V_83 = F_114 ( V_8 , V_83 ) ;
V_193 |= V_83 << 24 ;
F_17 ( V_2 , F_118 ( V_39 ) , V_193 ) ;
}
F_119 ( V_2 ) ;
}
static void F_120 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_101 ( V_182 ,
struct V_7 ,
V_30 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 = 0 , V_86 ;
T_5 V_199 ;
while ( F_56 ( V_126 ,
& V_8 -> V_127 ) )
F_121 ( 500 ) ;
if ( V_8 -> V_27 & V_29 ) {
F_14 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
F_122 ( V_8 ) ;
}
for ( V_39 = 0 ; V_39 < V_200 ; V_39 ++ ) {
V_199 = F_18 ( V_2 , V_32 ) &
V_201 ;
if ( V_199 != V_184 ) {
F_14 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
break;
} else {
F_79 ( V_202 ) ;
}
}
if ( V_39 == V_200 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
V_8 -> V_27 &= ~ V_28 ;
goto V_203;
}
for ( V_39 = 0 ; V_39 < V_200 ; V_39 ++ ) {
V_199 = F_18 ( V_2 , V_32 ) &
V_201 ;
if ( V_199 == V_184 ) {
F_14 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
break;
} else {
F_79 ( V_202 ) ;
}
}
if ( V_39 == V_200 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_27 ,
V_199 ) ;
V_8 -> V_27 |= V_155 ;
if ( F_123 ( V_8 -> V_25 ) )
F_124 ( V_8 -> V_25 ) ;
F_40 ( V_8 ) ;
F_96 ( V_8 ) ;
F_85 ( V_8 ) ;
F_9 ( V_8 -> V_169 ) ;
F_125 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_204 ;
F_58 ( V_126 , & V_8 -> V_127 ) ;
return;
}
V_203:
V_8 -> V_27 &= ~ V_28 ;
F_78 ( V_8 ) ;
V_8 -> V_149 = V_156 ;
if ( F_125 ( V_2 ) )
F_126 ( & V_8 -> V_12 -> V_13 ,
L_28 ,
V_95 ) ;
V_86 = F_127 ( V_2 ) ;
if ( V_86 )
F_14 ( & V_8 -> V_12 -> V_13 , L_29 ,
V_95 , V_86 ) ;
V_8 -> V_187 = 0 ;
V_8 -> V_89 = 0 ;
F_103 ( V_8 ) ;
F_58 ( V_126 , & V_8 -> V_127 ) ;
F_112 ( & V_8 -> V_153 , V_154 + 2 ) ;
if ( F_123 ( V_8 -> V_25 ) ) {
V_86 = F_128 ( V_8 ) ;
if ( V_86 )
goto V_205;
V_86 = F_129 ( V_8 ) ;
if ( V_86 )
goto V_205;
F_69 ( V_8 ) ;
V_86 = F_72 ( V_8 ) ;
if ( V_86 )
goto V_205;
F_25 ( V_8 , true ) ;
}
return;
V_205:
F_38 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
F_124 ( V_8 -> V_25 ) ;
}
static void F_130 ( struct V_181 * V_182 )
{
struct V_7 * V_8 =
F_101 ( V_182 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_206 V_207 ;
struct V_208 * V_209 ;
T_1 V_210 ;
T_7 V_211 ;
if ( V_8 -> V_27 & V_155 )
return;
V_207 . V_212 = V_213 ;
V_207 . V_214 = F_7 ( V_207 . V_212 , V_16 ) ;
if ( ! V_207 . V_214 ) {
F_14 ( & V_8 -> V_12 -> V_13 , L_31 ,
V_95 ) ;
return;
}
V_209 = (struct V_208 * ) & V_207 . V_215 ;
do {
V_210 = F_131 ( V_2 , & V_207 , & V_211 ) ;
if ( V_210 )
break;
F_132 ( V_8 , V_209 -> V_216 ,
V_209 -> V_217 , V_207 . V_214 ,
V_207 . V_212 ) ;
if ( V_211 != 0 ) {
F_14 ( & V_8 -> V_12 -> V_13 ,
L_32 ,
V_95 , V_211 ) ;
memset ( V_207 . V_214 , 0 , V_213 ) ;
}
} while ( V_211 );
F_20 ( V_8 ) ;
F_9 ( V_207 . V_214 ) ;
}
static void F_133 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
if ( V_8 -> V_72 [ V_39 ] -> V_215 )
F_134 ( V_8 -> V_72 [ V_39 ] ) ;
}
static int F_128 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
V_86 = F_135 ( V_8 -> V_72 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_33 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
static int F_129 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ ) {
V_86 = F_136 ( V_8 -> V_64 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_34 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
static void F_137 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 -> V_81 ; V_39 ++ )
if ( V_8 -> V_64 [ V_39 ] -> V_215 )
F_138 ( V_8 -> V_64 [ V_39 ] ) ;
}
static int F_139 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_86 ;
if ( V_8 -> V_27 & V_155 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_35 ) ;
return - V_161 ;
}
if ( V_8 -> V_149 != V_191 )
return - V_218 ;
V_86 = F_128 ( V_8 ) ;
if ( V_86 )
goto V_219;
V_86 = F_129 ( V_8 ) ;
if ( V_86 )
goto V_220;
V_86 = F_33 ( V_8 , V_25 -> V_94 ) ;
if ( V_86 )
goto V_221;
F_69 ( V_8 ) ;
V_86 = F_72 ( V_8 ) ;
if ( V_86 )
goto V_221;
F_25 ( V_8 , true ) ;
return 0 ;
V_221:
F_78 ( V_8 ) ;
F_39 ( V_8 ) ;
V_220:
F_137 ( V_8 ) ;
V_219:
F_133 ( V_8 ) ;
return V_86 ;
}
static int F_124 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_149 <= V_191 )
return 0 ;
V_8 -> V_149 = V_191 ;
F_140 ( V_151 , & V_8 -> V_66 . V_149 ) ;
F_78 ( V_8 ) ;
F_39 ( V_8 ) ;
F_133 ( V_8 ) ;
F_137 ( V_8 ) ;
return 0 ;
}
static struct V_222 * F_141 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_223 ;
}
void F_142 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_86 ;
F_143 ( F_144 () ) ;
V_8 -> V_149 = V_156 ;
F_78 ( V_8 ) ;
V_86 = F_128 ( V_8 ) ;
if ( V_86 )
goto V_224;
V_86 = F_129 ( V_8 ) ;
if ( V_86 )
goto V_224;
F_69 ( V_8 ) ;
V_86 = F_72 ( V_8 ) ;
if ( V_86 )
goto V_224;
F_25 ( V_8 , true ) ;
return;
V_224:
F_38 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
F_124 ( V_25 ) ;
}
static int F_145 ( struct V_24 * V_25 , int V_225 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_101 = V_225 + V_103 + V_104 ;
if ( ( V_225 < 68 ) || ( V_101 > V_226 ) )
return - V_227 ;
V_25 -> V_102 = V_225 ;
F_142 ( V_8 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 )
{
T_3 V_228 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_228 = F_18 ( V_2 , V_32 ) ;
if ( V_228 == V_184 )
return 0 ;
F_121 ( 10 ) ;
}
return - V_218 ;
}
static void F_147 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_101 ( V_182 ,
struct V_7 ,
V_186 . V_182 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_124 * V_114 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_229 * V_12 = V_8 -> V_12 ;
int V_39 , V_86 , V_230 ;
switch ( V_8 -> V_149 ) {
case V_185 :
V_8 -> V_27 &= ~ V_155 ;
V_8 -> V_27 &= ~ V_28 ;
V_86 = F_148 ( V_2 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_36 ,
V_86 ) ;
goto V_86;
}
V_86 = F_146 ( V_2 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_37 ,
V_86 ) ;
goto V_86;
}
V_2 -> V_231 . V_232 = V_233 ;
V_2 -> V_231 . V_234 = V_233 ;
V_2 -> V_231 . V_235 = V_213 ;
V_2 -> V_231 . V_236 = V_213 ;
V_86 = F_127 ( V_2 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_38 ,
V_86 ) ;
goto V_86;
}
V_86 = F_149 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_39 , V_86 ) ;
F_125 ( V_2 ) ;
goto V_86;
}
V_8 -> V_149 = V_237 ;
goto V_238;
break;
case V_237 :
if ( ! F_150 ( V_2 ) ) {
F_38 ( & V_12 -> V_13 , L_40 ) ;
goto V_86;
}
V_86 = F_151 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_41 ,
V_86 ) ;
goto V_86;
}
V_86 = F_152 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_42 ,
V_86 ) ;
goto V_86;
}
V_8 -> V_149 = V_239 ;
goto V_238;
break;
case V_239 :
if ( ! V_8 -> V_169 ) {
V_230 = sizeof( struct V_240 ) +
( V_241 *
sizeof( struct V_242 ) ) ;
V_8 -> V_169 = F_7 ( V_230 , V_16 ) ;
if ( ! V_8 -> V_169 )
goto V_86;
}
V_86 = F_153 ( V_8 ) ;
if ( V_86 == V_243 )
goto V_238;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_43 ,
V_86 ) ;
goto V_244;
}
V_8 -> V_149 = V_245 ;
break;
default:
goto V_244;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_169 -> V_246 ; V_39 ++ ) {
if ( V_8 -> V_169 -> V_80 [ V_39 ] . V_247 == V_248 )
V_8 -> V_80 = & V_8 -> V_169 -> V_80 [ V_39 ] ;
}
if ( ! V_8 -> V_80 ) {
F_38 ( & V_12 -> V_13 , L_44 ) ;
goto V_244;
}
V_8 -> V_27 |= V_249 ;
V_25 -> V_250 = & V_251 ;
F_154 ( V_25 ) ;
V_25 -> V_252 = 5 * V_192 ;
V_25 -> V_253 |= V_254 |
V_255 |
V_256 |
V_257 |
V_258 |
V_259 |
V_260 |
V_261 |
V_262 ;
if ( V_8 -> V_169 -> V_263
& V_264 ) {
V_25 -> V_265 = V_25 -> V_253 ;
V_25 -> V_253 |= V_266 |
V_267 |
V_268 ;
}
V_25 -> V_269 |= V_25 -> V_253 ;
V_25 -> V_269 &= ~ V_261 ;
if ( ! F_60 ( V_8 -> V_2 . V_137 . V_133 ) ) {
F_14 ( & V_12 -> V_13 , L_45 ,
V_8 -> V_2 . V_137 . V_133 ) ;
F_155 ( V_8 -> V_2 . V_137 . V_133 ) ;
}
memcpy ( V_25 -> V_136 , V_8 -> V_2 . V_137 . V_133 , V_25 -> V_138 ) ;
memcpy ( V_25 -> V_270 , V_8 -> V_2 . V_137 . V_133 , V_25 -> V_138 ) ;
F_48 ( & V_8 -> V_129 ) ;
F_48 ( & V_8 -> V_117 ) ;
V_114 = F_7 ( sizeof( * V_114 ) , V_115 ) ;
if ( NULL == V_114 )
goto V_271;
memcpy ( V_114 -> V_125 , V_8 -> V_2 . V_137 . V_133 , V_128 ) ;
V_114 -> V_118 = true ;
V_8 -> V_89 |= V_130 ;
F_49 ( & V_114 -> V_116 , & V_8 -> V_129 ) ;
F_156 ( & V_8 -> V_153 ) ;
V_8 -> V_153 . V_272 = & F_99 ;
V_8 -> V_153 . V_47 = ( unsigned long ) V_8 ;
F_112 ( & V_8 -> V_153 , V_154 + 1 ) ;
V_86 = F_98 ( V_8 ) ;
if ( V_86 )
goto V_271;
F_31 ( V_8 ) ;
F_115 ( V_8 ) ;
V_86 = F_37 ( V_8 ) ;
if ( V_86 )
goto V_271;
F_82 ( V_25 ) ;
V_8 -> V_66 . V_273 = V_8 -> V_80 -> V_274 ;
V_8 -> V_66 . V_275 = V_8 -> V_80 -> V_274 ;
V_8 -> V_66 . V_9 = V_8 ;
V_8 -> V_66 . V_276 = 1 ;
V_8 -> V_66 . V_277 = V_278 ;
V_8 -> V_66 . V_279 = V_280 ;
V_8 -> V_66 . V_281 = V_280 ;
V_8 -> V_66 . V_25 = V_8 -> V_25 ;
if ( ! V_8 -> V_282 ) {
V_86 = F_157 ( V_25 ) ;
if ( V_86 )
goto V_283;
}
V_8 -> V_282 = true ;
F_81 ( V_25 ) ;
F_14 ( & V_12 -> V_13 , L_46 , V_8 -> V_2 . V_137 . V_133 ) ;
if ( V_25 -> V_253 & V_262 )
F_14 ( & V_12 -> V_13 , L_47 ) ;
F_14 ( & V_12 -> V_13 , L_48 , V_284 ) ;
V_8 -> V_149 = V_191 ;
F_140 ( V_151 , & V_8 -> V_66 . V_149 ) ;
F_20 ( V_8 ) ;
return;
V_238:
F_102 ( & V_8 -> V_186 ,
F_113 ( 50 ) ) ;
return;
V_283:
F_40 ( V_8 ) ;
V_271:
F_96 ( V_8 ) ;
V_244:
F_9 ( V_8 -> V_169 ) ;
V_8 -> V_169 = NULL ;
V_86:
if ( ++ V_8 -> V_285 > V_286 ) {
F_38 ( & V_12 -> V_13 , L_49 ) ;
V_8 -> V_27 |= V_155 ;
return;
}
F_102 ( & V_8 -> V_186 , V_192 * 3 ) ;
return;
}
static void F_158 ( struct V_229 * V_12 )
{
struct V_24 * V_25 = F_159 ( V_12 ) ;
F_160 ( V_25 ) ;
if ( F_123 ( V_25 ) )
F_124 ( V_25 ) ;
#ifdef F_161
F_162 ( V_12 ) ;
#endif
F_163 ( V_12 ) ;
}
static int F_164 ( struct V_229 * V_12 , const struct V_287 * V_288 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_86 ;
V_86 = F_165 ( V_12 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_166 ( & V_12 -> V_13 , F_167 ( 64 ) ) ;
if ( V_86 ) {
V_86 = F_166 ( & V_12 -> V_13 , F_167 ( 32 ) ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 ,
L_50 , V_86 ) ;
goto V_289;
}
}
V_86 = F_168 ( V_12 , V_290 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 ,
L_51 , V_86 ) ;
goto V_291;
}
F_169 ( V_12 ) ;
F_170 ( V_12 ) ;
V_25 = F_171 ( sizeof( struct V_7 ) ,
V_292 ) ;
if ( ! V_25 ) {
V_86 = - V_123 ;
goto V_293;
}
F_172 ( V_25 , & V_12 -> V_13 ) ;
F_173 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_294 = ( 1 << V_295 ) - 1 ;
V_8 -> V_149 = V_185 ;
F_162 ( V_12 ) ;
V_2 -> V_100 = F_174 ( F_175 ( V_12 , 0 ) ,
F_176 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_100 ) {
V_86 = - V_161 ;
goto V_296;
}
V_2 -> V_297 = V_12 -> V_298 ;
V_2 -> V_299 = V_12 -> V_300 ;
F_177 ( V_12 , V_301 , & V_2 -> V_302 ) ;
V_2 -> V_303 = V_12 -> V_304 ;
V_2 -> V_305 = V_12 -> V_306 ;
V_2 -> V_307 . V_300 = F_178 ( V_12 -> V_308 ) ;
V_2 -> V_307 . V_309 = F_179 ( V_12 -> V_308 ) ;
F_180 ( & V_8 -> V_30 , F_120 ) ;
F_180 ( & V_8 -> V_52 , F_130 ) ;
F_180 ( & V_8 -> V_180 , F_100 ) ;
F_181 ( & V_8 -> V_186 , F_147 ) ;
F_102 ( & V_8 -> V_186 , 10 ) ;
return 0 ;
V_296:
F_182 ( V_25 ) ;
V_293:
F_183 ( V_12 ) ;
V_291:
V_289:
F_163 ( V_12 ) ;
return V_86 ;
}
static int F_184 ( struct V_229 * V_12 , T_11 V_149 )
{
struct V_24 * V_25 = F_159 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_310 = 0 ;
F_160 ( V_25 ) ;
if ( F_123 ( V_25 ) ) {
F_185 () ;
F_78 ( V_8 ) ;
F_186 () ;
}
F_40 ( V_8 ) ;
F_96 ( V_8 ) ;
V_310 = F_162 ( V_12 ) ;
if ( V_310 )
return V_310 ;
F_163 ( V_12 ) ;
return 0 ;
}
static int F_187 ( struct V_229 * V_12 )
{
struct V_7 * V_8 = F_159 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_86 ;
F_188 ( V_12 , V_311 ) ;
F_189 ( V_12 ) ;
F_162 ( V_12 ) ;
V_86 = F_190 ( V_12 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_52 ) ;
return V_86 ;
}
F_170 ( V_12 ) ;
F_185 () ;
V_86 = F_88 ( V_8 ) ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_53 ) ;
return V_86 ;
}
V_86 = F_37 ( V_8 ) ;
F_186 () ;
if ( V_86 ) {
F_38 ( & V_12 -> V_13 , L_54 ) ;
return V_86 ;
}
F_15 ( & V_8 -> V_30 ) ;
F_191 ( V_25 ) ;
return V_86 ;
}
static void F_192 ( struct V_229 * V_12 )
{
struct V_24 * V_25 = F_159 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_193 ( & V_8 -> V_186 ) ;
F_194 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_282 ) {
F_195 ( V_25 ) ;
V_8 -> V_282 = false ;
}
V_8 -> V_149 = V_312 ;
if ( V_8 -> V_33 ) {
F_16 ( V_8 ) ;
F_40 ( V_8 ) ;
F_96 ( V_8 ) ;
}
F_196 ( & V_8 -> V_153 ) ;
F_197 () ;
if ( V_2 -> V_231 . V_313 . V_67 )
F_125 ( V_2 ) ;
F_198 ( V_2 -> V_100 ) ;
F_183 ( V_12 ) ;
F_85 ( V_8 ) ;
F_9 ( V_8 -> V_169 ) ;
F_182 ( V_25 ) ;
F_199 ( V_12 ) ;
F_163 ( V_12 ) ;
}
static int T_12 F_200 ( void )
{
int V_210 ;
F_11 ( L_55 , V_284 ,
V_314 ) ;
F_11 ( L_48 , V_315 ) ;
V_210 = F_201 ( & V_316 ) ;
return V_210 ;
}
static void T_13 F_202 ( void )
{
F_203 ( & V_316 ) ;
}
