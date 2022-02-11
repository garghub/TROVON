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
static void F_23 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
T_5 V_43 ;
if ( V_19 & 1 ) {
V_43 = F_17 ( V_2 , V_31 ) ;
V_43 |= V_44 |
V_42 ;
F_16 ( V_2 , V_31 , V_43 ) ;
}
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
F_19 ( V_8 ) ;
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
int V_79 = V_8 -> V_80 ;
int V_81 = V_8 -> V_80 ;
int V_39 , V_82 ;
int V_83 , V_84 ;
int V_85 = 0 ;
V_75 = V_8 -> V_40 - V_86 ;
if ( V_75 == ( V_79 * 2 ) ) {
for (; V_77 < V_79 ; V_76 ++ , V_77 ++ )
F_28 ( V_8 , V_76 , V_77 ) ;
for (; V_78 < V_81 ; V_76 ++ , V_78 ++ )
F_29 ( V_8 , V_76 , V_78 ) ;
goto V_87;
}
for ( V_39 = V_76 ; V_39 < V_75 ; V_39 ++ ) {
V_83 = F_31 ( V_79 , V_75 - V_39 ) ;
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ ) {
F_28 ( V_8 , V_39 , V_77 ) ;
V_77 ++ ;
V_79 -- ;
}
}
for ( V_39 = V_76 ; V_39 < V_75 ; V_39 ++ ) {
V_84 = F_31 ( V_81 , V_75 - V_39 ) ;
for ( V_82 = 0 ; V_82 < V_84 ; V_82 ++ ) {
F_29 ( V_8 , V_39 , V_78 ) ;
V_78 ++ ;
V_81 -- ;
}
}
V_87:
V_8 -> V_88 |= V_89 ;
return V_85 ;
}
static int
F_32 ( struct V_7 * V_8 , char * V_90 )
{
int V_34 , V_85 , V_75 ;
int V_91 = 0 , V_92 = 0 ;
F_20 ( V_8 ) ;
V_75 = V_8 -> V_40 - V_86 ;
for ( V_34 = 0 ; V_34 < V_75 ; V_34 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_34 ] ;
if ( V_55 -> V_56 . V_57 && V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_93 , sizeof( V_55 -> V_93 ) - 1 ,
L_2 , V_90 ,
L_3 , V_91 ++ ) ;
V_92 ++ ;
} else if ( V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_93 , sizeof( V_55 -> V_93 ) - 1 ,
L_2 , V_90 ,
L_4 , V_91 ++ ) ;
} else if ( V_55 -> V_56 . V_57 ) {
snprintf ( V_55 -> V_93 , sizeof( V_55 -> V_93 ) - 1 ,
L_2 , V_90 ,
L_5 , V_92 ++ ) ;
} else {
continue;
}
V_85 = F_33 (
V_8 -> V_33 [ V_34 + V_86 ] . V_34 ,
F_26 ,
0 ,
V_55 -> V_93 ,
V_55 ) ;
if ( V_85 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_6 ,
V_94 , V_85 ) ;
goto V_95;
}
F_35 (
V_8 -> V_33 [ V_34 + V_86 ] . V_34 ,
V_55 -> V_96 ) ;
}
return 0 ;
V_95:
while ( V_34 ) {
V_34 -- ;
F_35 (
V_8 -> V_33 [ V_34 + V_86 ] . V_34 ,
NULL ) ;
F_36 ( V_8 -> V_33 [ V_34 + V_86 ] . V_34 ,
V_8 -> V_55 [ V_34 ] ) ;
}
return V_85 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_85 ;
snprintf ( V_8 -> V_97 ,
sizeof( V_8 -> V_97 ) - 1 , L_7 ) ;
V_85 = F_33 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_25 , 0 ,
V_8 -> V_97 , V_25 ) ;
if ( V_85 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_97 , V_85 ) ;
F_36 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
return V_85 ;
}
static void F_39 ( struct V_7 * V_8 )
{
int V_39 ;
int V_75 ;
V_75 = V_8 -> V_40 - V_86 ;
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
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ )
V_8 -> V_72 [ V_39 ] -> V_98 = V_2 -> V_99 + F_42 ( V_39 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_24 * V_25 = V_8 -> V_25 ;
int V_100 = V_25 -> V_101 + V_102 + V_103 ;
int V_39 ;
int V_104 ;
V_8 -> V_27 &= ~ V_105 ;
V_8 -> V_27 |= V_106 ;
if ( V_25 -> V_101 > V_107 ) {
if ( V_8 -> V_27 & V_105 )
V_8 -> V_27 |= V_108 ;
else
V_8 -> V_27 &= ~ V_108 ;
} else {
if ( V_8 -> V_27 & V_106 )
V_8 -> V_27 &= ~ V_108 ;
else
V_8 -> V_27 |= V_108 ;
}
if ( V_8 -> V_27 & V_108 ) {
V_104 = V_109 ;
} else {
if ( V_25 -> V_101 <= V_107 )
V_104 = V_110 ;
else
V_104 = F_2 ( V_100 , 1024 ) ;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ ) {
V_8 -> V_64 [ V_39 ] -> V_98 = V_2 -> V_99 + F_44 ( V_39 ) ;
V_8 -> V_64 [ V_39 ] -> V_104 = V_104 ;
}
}
static struct
V_111 * F_45 ( struct V_7 * V_8 , T_7 V_112 )
{
struct V_111 * V_113 ;
F_46 (f, &adapter->vlan_filter_list, list) {
if ( V_112 == V_113 -> V_112 )
return V_113 ;
}
return NULL ;
}
static struct
V_111 * F_47 ( struct V_7 * V_8 , T_7 V_112 )
{
struct V_111 * V_113 ;
V_113 = F_45 ( V_8 , V_112 ) ;
if ( ! V_113 ) {
V_113 = F_7 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 )
return NULL ;
V_113 -> V_112 = V_112 ;
F_48 ( & V_113 -> V_115 ) ;
F_49 ( & V_113 -> V_115 , & V_8 -> V_116 ) ;
V_113 -> V_117 = true ;
V_8 -> V_88 |= V_118 ;
}
return V_113 ;
}
static void F_50 ( struct V_7 * V_8 , T_7 V_112 )
{
struct V_111 * V_113 ;
V_113 = F_45 ( V_8 , V_112 ) ;
if ( V_113 ) {
V_113 -> remove = true ;
V_8 -> V_88 |= V_119 ;
}
}
static int F_51 ( struct V_24 * V_25 ,
T_8 T_9 V_120 , T_7 V_121 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( F_47 ( V_8 , V_121 ) == NULL )
return - V_122 ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 ,
T_8 T_9 V_120 , T_7 V_121 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_50 ( V_8 , V_121 ) ;
return 0 ;
}
static struct
V_123 * F_53 ( struct V_7 * V_8 ,
T_10 * V_124 )
{
struct V_123 * V_113 ;
if ( ! V_124 )
return NULL ;
F_46 (f, &adapter->mac_filter_list, list) {
if ( F_54 ( V_124 , V_113 -> V_124 ) )
return V_113 ;
}
return NULL ;
}
static struct
V_123 * F_55 ( struct V_7 * V_8 ,
T_10 * V_124 )
{
struct V_123 * V_113 ;
if ( ! V_124 )
return NULL ;
while ( F_56 ( V_125 ,
& V_8 -> V_126 ) )
F_57 ( 1 ) ;
V_113 = F_53 ( V_8 , V_124 ) ;
if ( ! V_113 ) {
V_113 = F_7 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 ) {
F_58 ( V_125 ,
& V_8 -> V_126 ) ;
return NULL ;
}
F_59 ( V_113 -> V_124 , V_124 ) ;
F_49 ( & V_113 -> V_115 , & V_8 -> V_127 ) ;
V_113 -> V_117 = true ;
V_8 -> V_88 |= V_128 ;
}
F_58 ( V_125 , & V_8 -> V_126 ) ;
return V_113 ;
}
static int F_60 ( struct V_24 * V_25 , void * V_129 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_123 * V_113 ;
struct V_130 * V_131 = V_129 ;
if ( ! F_61 ( V_131 -> V_132 ) )
return - V_133 ;
if ( F_54 ( V_25 -> V_134 , V_131 -> V_132 ) )
return 0 ;
V_113 = F_55 ( V_8 , V_131 -> V_132 ) ;
if ( V_113 ) {
F_59 ( V_2 -> V_135 . V_131 , V_131 -> V_132 ) ;
F_59 ( V_25 -> V_134 , V_8 -> V_2 . V_135 . V_131 ) ;
}
return ( V_113 == NULL ) ? - V_122 : 0 ;
}
static void F_62 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_123 * V_113 , * V_136 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
F_63 (uca, netdev) {
F_55 ( V_8 , V_138 -> V_131 ) ;
}
F_64 (mca, netdev) {
F_55 ( V_8 , V_139 -> V_131 ) ;
}
while ( F_56 ( V_125 ,
& V_8 -> V_126 ) )
F_57 ( 1 ) ;
F_65 (f, ftmp, &adapter->mac_filter_list, list) {
bool V_140 = false ;
if ( F_66 ( V_113 -> V_124 ) ) {
F_64 (mca, netdev) {
if ( F_54 ( V_139 -> V_131 , V_113 -> V_124 ) ) {
V_140 = true ;
break;
}
}
} else {
F_63 (uca, netdev) {
if ( F_54 ( V_138 -> V_131 , V_113 -> V_124 ) ) {
V_140 = true ;
break;
}
}
}
if ( V_140 ) {
V_113 -> remove = true ;
V_8 -> V_88 |= V_141 ;
}
}
F_58 ( V_125 , & V_8 -> V_126 ) ;
}
static void F_67 ( struct V_7 * V_8 )
{
int V_142 ;
struct V_54 * V_55 ;
int V_75 = V_8 -> V_40 - V_86 ;
for ( V_142 = 0 ; V_142 < V_75 ; V_142 ++ ) {
struct V_143 * V_59 ;
V_55 = V_8 -> V_55 [ V_142 ] ;
V_59 = & V_55 -> V_59 ;
F_68 ( V_59 ) ;
}
}
static void F_69 ( struct V_7 * V_8 )
{
int V_142 ;
struct V_54 * V_55 ;
int V_75 = V_8 -> V_40 - V_86 ;
for ( V_142 = 0 ; V_142 < V_75 ; V_142 ++ ) {
V_55 = V_8 -> V_55 [ V_142 ] ;
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
V_8 -> V_88 |= V_144 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ ) {
struct V_62 * V_57 = V_8 -> V_64 [ V_39 ] ;
F_72 ( V_57 , V_57 -> V_67 ) ;
V_57 -> V_145 = V_57 -> V_67 - 1 ;
F_73 ( V_57 -> V_145 , V_57 -> V_98 ) ;
}
}
static int F_74 ( struct V_7 * V_8 )
{
V_8 -> V_146 = V_147 ;
F_58 ( V_148 , & V_8 -> V_66 . V_146 ) ;
F_67 ( V_8 ) ;
V_8 -> V_88 |= V_149 ;
F_75 ( & V_8 -> V_150 , V_151 + 1 ) ;
return 0 ;
}
static void F_76 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ )
F_77 ( V_8 -> V_64 [ V_39 ] ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ )
F_79 ( V_8 -> V_72 [ V_39 ] ) ;
}
void F_80 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_123 * V_113 ;
if ( V_8 -> V_146 == V_152 )
return;
F_46 (f, &adapter->mac_filter_list, list) {
V_113 -> remove = true ;
}
F_46 (f, &adapter->vlan_filter_list, list) {
V_113 -> remove = true ;
}
if ( ! ( V_8 -> V_27 & V_153 ) &&
V_8 -> V_146 != V_154 ) {
V_8 -> V_88 |= V_141 ;
V_8 -> V_88 |= V_119 ;
V_8 -> V_88 |= V_155 ;
F_75 ( & V_8 -> V_150 , V_151 + 1 ) ;
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
F_85 ( struct V_7 * V_8 , int V_156 )
{
int V_85 , V_157 ;
V_157 = V_158 ;
V_85 = F_86 ( V_8 -> V_12 , V_8 -> V_33 ,
V_157 , V_156 ) ;
if ( V_85 < 0 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_9 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_85 ;
}
V_8 -> V_40 = V_85 ;
return 0 ;
}
static void F_87 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_159 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ ) {
if ( V_8 -> V_72 [ V_39 ] )
F_88 ( V_8 -> V_72 [ V_39 ] , V_160 ) ;
V_8 -> V_72 [ V_39 ] = NULL ;
V_8 -> V_64 [ V_39 ] = NULL ;
}
}
static int F_89 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ ) {
struct V_62 * V_71 ;
struct V_62 * V_63 ;
V_71 = F_7 ( sizeof( * V_71 ) * 2 , V_16 ) ;
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
return - V_122 ;
}
static int F_90 ( struct V_7 * V_8 )
{
int V_34 , V_165 ;
int V_166 = 0 ;
int V_85 = 0 ;
if ( ! V_8 -> V_159 ) {
V_85 = - V_167 ;
goto V_87;
}
V_166 = V_8 -> V_80 ;
V_165 = F_91 ( int , V_166 , ( int ) ( F_92 () * 2 ) ) + V_86 ;
V_165 = F_91 ( int , V_165 , ( int ) V_8 -> V_168 -> V_169 ) ;
V_8 -> V_33 = F_93 ( V_165 ,
sizeof( struct V_170 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_85 = - V_122 ;
goto V_87;
}
for ( V_34 = 0 ; V_34 < V_165 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_171 = V_34 ;
F_85 ( V_8 , V_165 ) ;
V_87:
V_8 -> V_25 -> V_172 = V_166 ;
return V_85 ;
}
static int F_94 ( struct V_7 * V_8 )
{
int V_142 , V_173 ;
struct V_54 * V_55 ;
V_173 = V_8 -> V_40 - V_86 ;
for ( V_142 = 0 ; V_142 < V_173 ; V_142 ++ ) {
V_55 = F_7 ( sizeof( * V_55 ) , V_16 ) ;
if ( ! V_55 )
goto V_161;
V_55 -> V_8 = V_8 ;
V_55 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_60 = V_142 ;
F_95 ( V_8 -> V_25 , & V_55 -> V_59 ,
V_174 , V_175 ) ;
V_8 -> V_55 [ V_142 ] = V_55 ;
}
return 0 ;
V_161:
while ( V_142 ) {
V_142 -- ;
V_55 = V_8 -> V_55 [ V_142 ] ;
F_96 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
V_8 -> V_55 [ V_142 ] = NULL ;
}
return - V_122 ;
}
static void F_97 ( struct V_7 * V_8 )
{
int V_142 , V_173 ;
int V_176 ;
V_173 = V_8 -> V_40 - V_86 ;
V_176 = V_8 -> V_80 ;
for ( V_142 = 0 ; V_142 < V_173 ; V_142 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_142 ] ;
V_8 -> V_55 [ V_142 ] = NULL ;
if ( V_142 < V_176 )
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
int V_85 ;
V_85 = F_90 ( V_8 ) ;
if ( V_85 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_10 ) ;
goto V_177;
}
V_85 = F_94 ( V_8 ) ;
if ( V_85 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_11 ) ;
goto V_178;
}
V_85 = F_89 ( V_8 ) ;
if ( V_85 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_12 ) ;
goto V_179;
}
F_34 ( & V_8 -> V_12 -> V_13 , L_13 ,
( V_8 -> V_80 > 1 ) ? L_14 : L_15 ,
V_8 -> V_80 ) ;
return 0 ;
V_179:
F_97 ( V_8 ) ;
V_178:
F_98 ( V_8 ) ;
V_177:
return V_85 ;
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
T_5 V_183 ;
if ( F_56 ( V_125 , & V_8 -> V_126 ) )
goto V_184;
if ( V_8 -> V_27 & V_153 ) {
V_183 = F_17 ( V_2 , V_32 ) &
V_185 ;
if ( ( V_183 == V_186 ) ||
( V_183 == V_187 ) ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_16 ) ;
V_8 -> V_146 = V_188 ;
V_8 -> V_27 &= ~ V_153 ;
F_104 ( & V_8 -> V_189 , 10 ) ;
F_58 ( V_125 ,
& V_8 -> V_126 ) ;
return;
}
V_8 -> V_190 = 0 ;
V_8 -> V_88 = 0 ;
V_8 -> V_191 = V_192 ;
goto V_193;
}
if ( ( V_8 -> V_146 < V_152 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_193;
V_183 = F_17 ( V_2 , V_32 ) &
V_185 ;
if ( ! ( V_8 -> V_27 & V_28 ) &&
( V_183 != V_186 ) &&
( V_183 != V_187 ) ) {
V_8 -> V_146 = V_154 ;
V_8 -> V_27 |= V_28 ;
F_38 ( & V_8 -> V_12 -> V_13 , L_17 ) ;
F_14 ( & V_8 -> V_30 ) ;
V_8 -> V_190 = 0 ;
V_8 -> V_88 = 0 ;
V_8 -> V_191 = V_192 ;
goto V_193;
}
if ( V_8 -> V_190 )
goto V_193;
if ( V_8 -> V_88 & V_89 ) {
F_105 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_128 ) {
F_106 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_118 ) {
F_107 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_141 ) {
F_108 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_119 ) {
F_109 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_155 ) {
F_110 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_144 ) {
F_111 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_88 & V_149 ) {
F_112 ( V_8 ) ;
goto V_193;
}
if ( V_8 -> V_146 == V_147 )
F_113 ( V_8 ) ;
F_24 ( V_8 , true ) ;
F_23 ( V_8 , 0xFF ) ;
V_193:
F_58 ( V_125 , & V_8 -> V_126 ) ;
V_184:
if ( V_8 -> V_146 == V_194 )
return;
if ( V_8 -> V_88 )
F_114 ( & V_8 -> V_150 ,
V_151 + F_115 ( 20 ) ) ;
else
F_114 ( & V_8 -> V_150 , V_151 + ( V_195 * 2 ) ) ;
F_14 ( & V_8 -> V_52 ) ;
}
static int F_116 ( struct V_7 * V_8 , int V_82 )
{
V_82 += 1 ;
return V_82 >= V_8 -> V_80 ? 0 : V_82 ;
}
static void F_117 ( struct V_7 * V_8 )
{
T_3 V_196 [ V_197 + 1 ] ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_198 = 0 ;
int V_39 , V_82 ;
T_2 V_199 ;
if ( V_8 -> V_80 == 1 ) {
F_16 ( V_2 , F_118 ( 0 ) , 0 ) ;
F_16 ( V_2 , F_118 ( 1 ) , 0 ) ;
return;
}
F_119 ( V_196 , sizeof( V_196 ) ) ;
for ( V_39 = 0 ; V_39 <= V_197 ; V_39 ++ )
F_16 ( V_2 , F_120 ( V_39 ) , V_196 [ V_39 ] ) ;
V_199 = V_200 ;
F_16 ( V_2 , F_118 ( 0 ) , ( T_3 ) V_199 ) ;
F_16 ( V_2 , F_118 ( 1 ) , ( T_3 ) ( V_199 >> 32 ) ) ;
V_82 = V_8 -> V_80 ;
for ( V_39 = 0 ; V_39 <= V_201 ; V_39 ++ ) {
V_82 = F_116 ( V_8 , V_82 ) ;
V_198 = V_82 ;
V_82 = F_116 ( V_8 , V_82 ) ;
V_198 |= V_82 << 8 ;
V_82 = F_116 ( V_8 , V_82 ) ;
V_198 |= V_82 << 16 ;
V_82 = F_116 ( V_8 , V_82 ) ;
V_198 |= V_82 << 24 ;
F_16 ( V_2 , F_121 ( V_39 ) , V_198 ) ;
}
F_122 ( V_2 ) ;
}
static void F_123 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_103 ( V_182 ,
struct V_7 ,
V_30 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 = 0 , V_85 ;
T_5 V_183 ;
while ( F_56 ( V_125 ,
& V_8 -> V_126 ) )
F_124 ( 500 , 1000 ) ;
if ( V_8 -> V_27 & V_29 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_18 ) ;
F_125 ( V_8 ) ;
}
for ( V_39 = 0 ; V_39 < V_202 ; V_39 ++ ) {
V_183 = F_17 ( V_2 , V_32 ) &
V_185 ;
if ( ( V_183 != V_186 ) &&
( V_183 != V_187 ) )
break;
F_81 ( V_203 ) ;
}
if ( V_39 == V_202 ) {
V_8 -> V_27 &= ~ V_28 ;
goto V_204;
}
for ( V_39 = 0 ; V_39 < V_202 ; V_39 ++ ) {
V_183 = F_17 ( V_2 , V_32 ) &
V_185 ;
if ( ( V_183 == V_186 ) ||
( V_183 == V_187 ) )
break;
F_81 ( V_203 ) ;
}
if ( V_39 == V_202 ) {
struct V_123 * V_113 , * V_136 ;
struct V_111 * V_205 , * V_206 ;
F_38 ( & V_8 -> V_12 -> V_13 , L_19 ,
V_183 ) ;
V_8 -> V_27 |= V_153 ;
if ( F_126 ( V_8 -> V_25 ) ) {
F_127 ( V_148 , & V_8 -> V_66 . V_146 ) ;
F_80 ( V_8 ) ;
F_39 ( V_8 ) ;
F_128 ( V_8 ) ;
F_129 ( V_8 ) ;
}
F_65 (f, ftmp, &adapter->mac_filter_list,
list) {
F_130 ( & V_113 -> V_115 ) ;
F_9 ( V_113 ) ;
}
F_65 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_130 ( & V_205 -> V_115 ) ;
F_9 ( V_205 ) ;
}
F_40 ( V_8 ) ;
F_98 ( V_8 ) ;
F_87 ( V_8 ) ;
F_97 ( V_8 ) ;
F_9 ( V_8 -> V_168 ) ;
F_131 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_207 ;
F_58 ( V_125 , & V_8 -> V_126 ) ;
return;
}
V_204:
V_8 -> V_27 &= ~ V_28 ;
F_80 ( V_8 ) ;
V_8 -> V_146 = V_154 ;
if ( F_131 ( V_2 ) )
F_132 ( & V_8 -> V_12 -> V_13 ,
L_20 ,
V_94 ) ;
V_85 = F_133 ( V_2 ) ;
if ( V_85 )
F_34 ( & V_8 -> V_12 -> V_13 , L_21 ,
V_94 , V_85 ) ;
V_8 -> V_190 = 0 ;
V_8 -> V_88 = 0 ;
F_105 ( V_8 ) ;
F_58 ( V_125 , & V_8 -> V_126 ) ;
F_114 ( & V_8 -> V_150 , V_151 + 2 ) ;
if ( F_126 ( V_8 -> V_25 ) ) {
V_85 = F_134 ( V_8 ) ;
if ( V_85 )
goto V_208;
V_85 = F_135 ( V_8 ) ;
if ( V_85 )
goto V_208;
F_71 ( V_8 ) ;
V_85 = F_74 ( V_8 ) ;
if ( V_85 )
goto V_208;
F_24 ( V_8 , true ) ;
}
return;
V_208:
F_38 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_136 ( V_8 -> V_25 ) ;
}
static void F_137 ( struct V_181 * V_182 )
{
struct V_7 * V_8 =
F_103 ( V_182 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_209 V_210 ;
struct V_211 * V_212 ;
T_1 V_213 ;
T_3 V_48 , V_214 ;
T_7 V_215 ;
if ( V_8 -> V_27 & V_153 )
return;
V_210 . V_216 = V_217 ;
V_210 . V_218 = F_7 ( V_210 . V_216 , V_16 ) ;
if ( ! V_210 . V_218 )
return;
V_212 = (struct V_211 * ) & V_210 . V_219 ;
do {
V_213 = F_138 ( V_2 , & V_210 , & V_215 ) ;
if ( V_213 )
break;
F_139 ( V_8 , V_212 -> V_220 ,
V_212 -> V_221 , V_210 . V_218 ,
V_210 . V_222 ) ;
if ( V_215 != 0 )
memset ( V_210 . V_218 , 0 , V_217 ) ;
} while ( V_215 );
V_48 = F_17 ( V_2 , V_2 -> V_223 . V_224 . V_225 ) ;
V_214 = V_48 ;
if ( V_48 & V_226 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
V_48 &= ~ V_226 ;
}
if ( V_48 & V_227 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
V_48 &= ~ V_227 ;
}
if ( V_48 & V_228 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
V_48 &= ~ V_228 ;
}
if ( V_214 != V_48 )
F_16 ( V_2 , V_2 -> V_223 . V_224 . V_225 , V_48 ) ;
V_48 = F_17 ( V_2 , V_2 -> V_223 . V_229 . V_225 ) ;
V_214 = V_48 ;
if ( V_48 & V_230 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
V_48 &= ~ V_230 ;
}
if ( V_48 & V_231 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
V_48 &= ~ V_231 ;
}
if ( V_48 & V_232 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_48 &= ~ V_232 ;
}
if ( V_214 != V_48 )
F_16 ( V_2 , V_2 -> V_223 . V_229 . V_225 , V_48 ) ;
F_19 ( V_8 ) ;
F_9 ( V_210 . V_218 ) ;
}
static void F_128 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ )
if ( V_8 -> V_72 [ V_39 ] -> V_219 )
F_140 ( V_8 -> V_72 [ V_39 ] ) ;
}
static int F_134 ( struct V_7 * V_8 )
{
int V_39 , V_85 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ ) {
V_8 -> V_72 [ V_39 ] -> V_67 = V_8 -> V_163 ;
V_85 = F_141 ( V_8 -> V_72 [ V_39 ] ) ;
if ( ! V_85 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_29 ,
V_94 , V_39 ) ;
break;
}
return V_85 ;
}
static int F_135 ( struct V_7 * V_8 )
{
int V_39 , V_85 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ ) {
V_8 -> V_64 [ V_39 ] -> V_67 = V_8 -> V_164 ;
V_85 = F_142 ( V_8 -> V_64 [ V_39 ] ) ;
if ( ! V_85 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_30 ,
V_94 , V_39 ) ;
break;
}
return V_85 ;
}
static void F_129 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_80 ; V_39 ++ )
if ( V_8 -> V_64 [ V_39 ] -> V_219 )
F_143 ( V_8 -> V_64 [ V_39 ] ) ;
}
static int F_144 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_85 ;
if ( V_8 -> V_27 & V_153 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
return - V_167 ;
}
if ( V_8 -> V_146 != V_152 )
return - V_233 ;
V_85 = F_134 ( V_8 ) ;
if ( V_85 )
goto V_234;
V_85 = F_135 ( V_8 ) ;
if ( V_85 )
goto V_235;
V_85 = F_32 ( V_8 , V_25 -> V_93 ) ;
if ( V_85 )
goto V_236;
F_71 ( V_8 ) ;
V_85 = F_74 ( V_8 ) ;
if ( V_85 )
goto V_236;
F_24 ( V_8 , true ) ;
return 0 ;
V_236:
F_80 ( V_8 ) ;
F_39 ( V_8 ) ;
V_235:
F_129 ( V_8 ) ;
V_234:
F_128 ( V_8 ) ;
return V_85 ;
}
static int F_136 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_146 <= V_152 )
return 0 ;
F_127 ( V_148 , & V_8 -> V_66 . V_146 ) ;
F_80 ( V_8 ) ;
V_8 -> V_146 = V_152 ;
F_39 ( V_8 ) ;
F_128 ( V_8 ) ;
F_129 ( V_8 ) ;
return 0 ;
}
static struct V_237 * F_145 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_238 ;
}
void F_146 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_85 ;
F_147 ( F_148 () ) ;
F_80 ( V_8 ) ;
V_85 = F_134 ( V_8 ) ;
if ( V_85 )
goto V_239;
V_85 = F_135 ( V_8 ) ;
if ( V_85 )
goto V_239;
F_71 ( V_8 ) ;
V_85 = F_74 ( V_8 ) ;
if ( V_85 )
goto V_239;
F_24 ( V_8 , true ) ;
return;
V_239:
F_38 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_136 ( V_25 ) ;
}
static int F_149 ( struct V_24 * V_25 , int V_240 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_100 = V_240 + V_102 + V_103 ;
if ( ( V_240 < 68 ) || ( V_100 > V_241 ) )
return - V_242 ;
V_25 -> V_101 = V_240 ;
F_146 ( V_8 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 )
{
T_3 V_243 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_243 = F_17 ( V_2 , V_32 ) &
V_185 ;
if ( ( V_243 == V_186 ) ||
( V_243 == V_187 ) )
return 0 ;
F_124 ( 10 , 20 ) ;
}
return - V_233 ;
}
static void F_151 ( struct V_181 * V_182 )
{
struct V_7 * V_8 = F_103 ( V_182 ,
struct V_7 ,
V_189 . V_182 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_123 * V_113 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_244 * V_12 = V_8 -> V_12 ;
int V_39 , V_85 , V_245 ;
switch ( V_8 -> V_146 ) {
case V_188 :
V_8 -> V_27 &= ~ V_153 ;
V_8 -> V_27 &= ~ V_28 ;
V_85 = F_152 ( V_2 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_32 ,
V_85 ) ;
goto V_85;
}
V_85 = F_150 ( V_2 ) ;
if ( V_85 ) {
F_34 ( & V_12 -> V_13 , L_33 ,
V_85 ) ;
goto V_85;
}
V_2 -> V_223 . V_246 = V_247 ;
V_2 -> V_223 . V_248 = V_247 ;
V_2 -> V_223 . V_249 = V_217 ;
V_2 -> V_223 . V_250 = V_217 ;
V_85 = F_133 ( V_2 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_34 ,
V_85 ) ;
goto V_85;
}
V_85 = F_153 ( V_8 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_35 , V_85 ) ;
F_131 ( V_2 ) ;
goto V_85;
}
V_8 -> V_146 = V_251 ;
goto V_252;
case V_251 :
if ( ! F_154 ( V_2 ) ) {
F_38 ( & V_12 -> V_13 , L_36 ) ;
F_131 ( V_2 ) ;
V_8 -> V_146 = V_188 ;
goto V_85;
}
V_85 = F_155 ( V_8 ) ;
if ( V_85 ) {
F_34 ( & V_12 -> V_13 , L_37 ,
V_85 ) ;
if ( V_85 == V_253 ) {
F_34 ( & V_12 -> V_13 , L_38 ) ;
V_85 = F_153 ( V_8 ) ;
}
goto V_85;
}
V_85 = F_156 ( V_8 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_39 ,
V_85 ) ;
goto V_85;
}
V_8 -> V_146 = V_254 ;
goto V_252;
case V_254 :
if ( ! V_8 -> V_168 ) {
V_245 = sizeof( struct V_255 ) +
( V_256 *
sizeof( struct V_257 ) ) ;
V_8 -> V_168 = F_7 ( V_245 , V_16 ) ;
if ( ! V_8 -> V_168 )
goto V_85;
}
V_85 = F_157 ( V_8 ) ;
if ( V_85 == V_253 ) {
F_34 ( & V_12 -> V_13 , L_40 ) ;
V_85 = F_156 ( V_8 ) ;
goto V_85;
}
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_41 ,
V_85 ) ;
goto V_258;
}
V_8 -> V_146 = V_259 ;
break;
default:
goto V_258;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_168 -> V_260 ; V_39 ++ ) {
if ( V_8 -> V_168 -> V_159 [ V_39 ] . V_261 == V_262 )
V_8 -> V_159 = & V_8 -> V_168 -> V_159 [ V_39 ] ;
}
if ( ! V_8 -> V_159 ) {
F_38 ( & V_12 -> V_13 , L_42 ) ;
goto V_258;
}
V_8 -> V_27 |= V_263 ;
V_25 -> V_264 = & V_265 ;
F_158 ( V_25 ) ;
V_25 -> V_266 = 5 * V_195 ;
V_25 -> V_267 |= V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 ;
if ( V_8 -> V_168 -> V_277
& V_278 ) {
V_25 -> V_279 = V_25 -> V_267 ;
V_25 -> V_267 |= V_280 |
V_281 |
V_282 ;
}
V_25 -> V_283 |= V_25 -> V_267 ;
V_25 -> V_283 &= ~ V_275 ;
if ( ! F_61 ( V_8 -> V_2 . V_135 . V_131 ) ) {
F_34 ( & V_12 -> V_13 , L_43 ,
V_8 -> V_2 . V_135 . V_131 ) ;
F_159 ( V_8 -> V_2 . V_135 . V_131 ) ;
}
F_59 ( V_25 -> V_134 , V_8 -> V_2 . V_135 . V_131 ) ;
F_59 ( V_25 -> V_284 , V_8 -> V_2 . V_135 . V_131 ) ;
V_113 = F_7 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 )
goto V_285;
F_59 ( V_113 -> V_124 , V_8 -> V_2 . V_135 . V_131 ) ;
V_113 -> V_117 = true ;
V_8 -> V_88 |= V_128 ;
F_49 ( & V_113 -> V_115 , & V_8 -> V_127 ) ;
F_160 ( & V_8 -> V_150 ) ;
V_8 -> V_150 . V_286 = & F_101 ;
V_8 -> V_150 . V_47 = ( unsigned long ) V_8 ;
F_114 ( & V_8 -> V_150 , V_151 + 1 ) ;
V_8 -> V_80 = F_91 ( int ,
V_8 -> V_159 -> V_287 ,
( int ) ( F_92 () ) ) ;
V_8 -> V_163 = V_288 ;
V_8 -> V_164 = V_289 ;
V_85 = F_100 ( V_8 ) ;
if ( V_85 )
goto V_285;
F_30 ( V_8 ) ;
F_117 ( V_8 ) ;
V_85 = F_37 ( V_8 ) ;
if ( V_85 )
goto V_285;
F_84 ( V_25 ) ;
V_8 -> V_66 . V_290 = V_8 -> V_159 -> V_291 ;
V_8 -> V_66 . V_292 = V_8 -> V_159 -> V_291 ;
V_8 -> V_66 . V_9 = V_8 ;
V_8 -> V_66 . V_293 = 1 ;
V_8 -> V_66 . V_294 = V_295 ;
V_8 -> V_66 . V_296 = ( V_297 |
F_161 ( V_298 ) ) ;
V_8 -> V_66 . V_299 = ( V_297 |
F_161 ( V_300 ) ) ;
V_8 -> V_66 . V_25 = V_8 -> V_25 ;
if ( ! V_8 -> V_301 ) {
V_85 = F_162 ( V_25 ) ;
if ( V_85 )
goto V_302;
}
V_8 -> V_301 = true ;
F_83 ( V_25 ) ;
F_34 ( & V_12 -> V_13 , L_44 , V_8 -> V_2 . V_135 . V_131 ) ;
if ( V_25 -> V_267 & V_276 )
F_34 ( & V_12 -> V_13 , L_45 ) ;
F_34 ( & V_12 -> V_13 , L_46 , V_303 ) ;
V_8 -> V_146 = V_152 ;
F_127 ( V_148 , & V_8 -> V_66 . V_146 ) ;
F_19 ( V_8 ) ;
return;
V_252:
F_104 ( & V_8 -> V_189 ,
F_115 ( 50 ) ) ;
return;
V_302:
F_40 ( V_8 ) ;
V_285:
F_98 ( V_8 ) ;
V_258:
F_9 ( V_8 -> V_168 ) ;
V_8 -> V_168 = NULL ;
V_85:
if ( ++ V_8 -> V_304 > V_305 ) {
F_38 ( & V_12 -> V_13 , L_47 ) ;
V_8 -> V_27 |= V_153 ;
return;
}
F_104 ( & V_8 -> V_189 , V_195 * 3 ) ;
}
static void F_163 ( struct V_244 * V_12 )
{
struct V_24 * V_25 = F_164 ( V_12 ) ;
F_165 ( V_25 ) ;
if ( F_126 ( V_25 ) )
F_136 ( V_25 ) ;
#ifdef F_166
F_167 ( V_12 ) ;
#endif
F_168 ( V_12 ) ;
}
static int F_169 ( struct V_244 * V_12 , const struct V_306 * V_307 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_85 ;
V_85 = F_170 ( V_12 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_171 ( & V_12 -> V_13 , F_172 ( 64 ) ) ;
if ( V_85 ) {
V_85 = F_171 ( & V_12 -> V_13 , F_172 ( 32 ) ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 ,
L_48 , V_85 ) ;
goto V_308;
}
}
V_85 = F_173 ( V_12 , V_309 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 ,
L_49 , V_85 ) ;
goto V_310;
}
F_174 ( V_12 ) ;
F_175 ( V_12 ) ;
V_25 = F_176 ( sizeof( struct V_7 ) ,
V_311 ) ;
if ( ! V_25 ) {
V_85 = - V_122 ;
goto V_312;
}
F_177 ( V_25 , & V_12 -> V_13 ) ;
F_178 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_313 = ( 1 << V_314 ) - 1 ;
V_8 -> V_146 = V_188 ;
F_167 ( V_12 ) ;
V_2 -> V_99 = F_179 ( F_180 ( V_12 , 0 ) ,
F_181 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_99 ) {
V_85 = - V_167 ;
goto V_315;
}
V_2 -> V_316 = V_12 -> V_317 ;
V_2 -> V_318 = V_12 -> V_319 ;
F_182 ( V_12 , V_320 , & V_2 -> V_321 ) ;
V_2 -> V_322 = V_12 -> V_323 ;
V_2 -> V_324 = V_12 -> V_325 ;
V_2 -> V_326 . V_319 = F_183 ( V_12 -> V_327 ) ;
V_2 -> V_326 . V_328 = F_184 ( V_12 -> V_327 ) ;
F_48 ( & V_8 -> V_127 ) ;
F_48 ( & V_8 -> V_116 ) ;
F_185 ( & V_8 -> V_30 , F_123 ) ;
F_185 ( & V_8 -> V_52 , F_137 ) ;
F_185 ( & V_8 -> V_180 , F_102 ) ;
F_186 ( & V_8 -> V_189 , F_151 ) ;
F_104 ( & V_8 -> V_189 , 10 ) ;
return 0 ;
V_315:
F_187 ( V_25 ) ;
V_312:
F_188 ( V_12 ) ;
V_310:
V_308:
F_168 ( V_12 ) ;
return V_85 ;
}
static int F_189 ( struct V_244 * V_12 , T_11 V_146 )
{
struct V_24 * V_25 = F_164 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_329 = 0 ;
F_165 ( V_25 ) ;
if ( F_126 ( V_25 ) ) {
F_190 () ;
F_80 ( V_8 ) ;
F_191 () ;
}
F_40 ( V_8 ) ;
F_98 ( V_8 ) ;
V_329 = F_167 ( V_12 ) ;
if ( V_329 )
return V_329 ;
F_168 ( V_12 ) ;
return 0 ;
}
static int F_192 ( struct V_244 * V_12 )
{
struct V_7 * V_8 = F_164 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_85 ;
F_193 ( V_12 , V_330 ) ;
F_194 ( V_12 ) ;
F_167 ( V_12 ) ;
V_85 = F_195 ( V_12 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_50 ) ;
return V_85 ;
}
F_175 ( V_12 ) ;
F_190 () ;
V_85 = F_90 ( V_8 ) ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_51 ) ;
return V_85 ;
}
V_85 = F_37 ( V_8 ) ;
F_191 () ;
if ( V_85 ) {
F_38 ( & V_12 -> V_13 , L_52 ) ;
return V_85 ;
}
F_14 ( & V_8 -> V_30 ) ;
F_196 ( V_25 ) ;
return V_85 ;
}
static void F_197 ( struct V_244 * V_12 )
{
struct V_24 * V_25 = F_164 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_123 * V_113 , * V_136 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_198 ( & V_8 -> V_189 ) ;
F_199 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_301 ) {
F_200 ( V_25 ) ;
V_8 -> V_301 = false ;
}
V_8 -> V_146 = V_194 ;
if ( V_8 -> V_33 ) {
F_15 ( V_8 ) ;
F_40 ( V_8 ) ;
F_98 ( V_8 ) ;
F_97 ( V_8 ) ;
}
if ( V_8 -> V_150 . V_286 )
F_201 ( & V_8 -> V_150 ) ;
F_202 () ;
if ( V_2 -> V_223 . V_229 . V_67 )
F_131 ( V_2 ) ;
F_203 ( V_2 -> V_99 ) ;
F_188 ( V_12 ) ;
F_87 ( V_8 ) ;
F_9 ( V_8 -> V_168 ) ;
F_65 (f, ftmp, &adapter->mac_filter_list, list) {
F_130 ( & V_113 -> V_115 ) ;
F_9 ( V_113 ) ;
}
F_187 ( V_25 ) ;
F_204 ( V_12 ) ;
F_168 ( V_12 ) ;
}
static int T_12 F_205 ( void )
{
int V_213 ;
F_11 ( L_53 , V_303 ,
V_331 ) ;
F_11 ( L_46 , V_332 ) ;
V_213 = F_206 ( & V_333 ) ;
return V_213 ;
}
static void T_13 F_207 ( void )
{
F_208 ( & V_333 ) ;
}
