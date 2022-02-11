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
V_42 |
V_43 ) ;
}
}
}
static void F_23 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
T_5 V_44 ;
if ( V_19 & 1 ) {
V_44 = F_17 ( V_2 , V_31 ) ;
V_44 |= V_45 |
V_42 |
V_43 ;
F_16 ( V_2 , V_31 , V_44 ) ;
}
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & ( 1 << V_39 ) ) {
V_44 = F_17 ( V_2 , F_21 ( V_39 - 1 ) ) ;
V_44 |= V_45 |
V_42 |
V_43 ;
F_16 ( V_2 , F_21 ( V_39 - 1 ) , V_44 ) ;
}
}
}
void F_24 ( struct V_7 * V_8 , bool V_46 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_19 ( V_8 ) ;
F_22 ( V_8 , ~ 0 ) ;
if ( V_46 )
F_17 ( V_2 , V_32 ) ;
}
static T_6 F_25 ( int V_47 , void * V_48 )
{
struct V_24 * V_25 = V_48 ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_49 ;
T_3 V_50 ;
V_49 = F_17 ( V_2 , V_51 ) ;
V_50 = F_17 ( V_2 , V_37 ) ;
V_49 = F_17 ( V_2 , V_31 ) ;
V_49 = V_49 | V_52 ;
F_16 ( V_2 , V_31 , V_49 ) ;
F_14 ( & V_8 -> V_53 ) ;
return V_54 ;
}
static T_6 F_26 ( int V_47 , void * V_48 )
{
struct V_55 * V_56 = V_48 ;
if ( ! V_56 -> V_57 . V_58 && ! V_56 -> V_59 . V_58 )
return V_54 ;
F_27 ( & V_56 -> V_60 ) ;
return V_54 ;
}
static void
F_28 ( struct V_7 * V_8 , int V_61 , int V_62 )
{
struct V_55 * V_56 = V_8 -> V_56 [ V_61 ] ;
struct V_63 * V_64 = V_8 -> V_65 [ V_62 ] ;
V_64 -> V_56 = V_56 ;
V_64 -> V_66 = V_56 -> V_59 . V_58 ;
V_64 -> V_67 = & V_8 -> V_67 ;
V_56 -> V_59 . V_58 = V_64 ;
V_56 -> V_59 . V_68 ++ ;
V_56 -> V_59 . V_69 = V_70 ;
}
static void
F_29 ( struct V_7 * V_8 , int V_61 , int V_71 )
{
struct V_55 * V_56 = V_8 -> V_56 [ V_61 ] ;
struct V_63 * V_72 = V_8 -> V_73 [ V_71 ] ;
V_72 -> V_56 = V_56 ;
V_72 -> V_66 = V_56 -> V_57 . V_58 ;
V_72 -> V_67 = & V_8 -> V_67 ;
V_56 -> V_57 . V_58 = V_72 ;
V_56 -> V_57 . V_68 ++ ;
V_56 -> V_57 . V_69 = V_70 ;
V_56 -> V_74 ++ ;
V_56 -> V_75 |= ( 1 << V_71 ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
int V_76 ;
int V_77 = 0 ;
int V_78 = 0 , V_79 = 0 ;
int V_80 = V_8 -> V_81 ;
int V_82 = V_8 -> V_81 ;
int V_39 , V_83 ;
int V_84 , V_85 ;
int V_86 = 0 ;
V_76 = V_8 -> V_40 - V_87 ;
if ( V_76 == ( V_80 * 2 ) ) {
for (; V_78 < V_80 ; V_77 ++ , V_78 ++ )
F_28 ( V_8 , V_77 , V_78 ) ;
for (; V_79 < V_82 ; V_77 ++ , V_79 ++ )
F_29 ( V_8 , V_77 , V_79 ) ;
goto V_88;
}
for ( V_39 = V_77 ; V_39 < V_76 ; V_39 ++ ) {
V_84 = F_31 ( V_80 , V_76 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
F_28 ( V_8 , V_39 , V_78 ) ;
V_78 ++ ;
V_80 -- ;
}
}
for ( V_39 = V_77 ; V_39 < V_76 ; V_39 ++ ) {
V_85 = F_31 ( V_82 , V_76 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
F_29 ( V_8 , V_39 , V_79 ) ;
V_79 ++ ;
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
int V_34 , V_86 , V_76 ;
int V_92 = 0 , V_93 = 0 ;
F_20 ( V_8 ) ;
V_76 = V_8 -> V_40 - V_87 ;
for ( V_34 = 0 ; V_34 < V_76 ; V_34 ++ ) {
struct V_55 * V_56 = V_8 -> V_56 [ V_34 ] ;
if ( V_56 -> V_57 . V_58 && V_56 -> V_59 . V_58 ) {
snprintf ( V_56 -> V_94 , sizeof( V_56 -> V_94 ) - 1 ,
L_2 , V_91 ,
L_3 , V_92 ++ ) ;
V_93 ++ ;
} else if ( V_56 -> V_59 . V_58 ) {
snprintf ( V_56 -> V_94 , sizeof( V_56 -> V_94 ) - 1 ,
L_2 , V_91 ,
L_4 , V_92 ++ ) ;
} else if ( V_56 -> V_57 . V_58 ) {
snprintf ( V_56 -> V_94 , sizeof( V_56 -> V_94 ) - 1 ,
L_2 , V_91 ,
L_5 , V_93 ++ ) ;
} else {
continue;
}
V_86 = F_33 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
F_26 ,
0 ,
V_56 -> V_94 ,
V_56 ) ;
if ( V_86 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_6 ,
V_95 , V_86 ) ;
goto V_96;
}
F_35 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
V_56 -> V_97 ) ;
}
return 0 ;
V_96:
while ( V_34 ) {
V_34 -- ;
F_35 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
NULL ) ;
F_36 ( V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
V_8 -> V_56 [ V_34 ] ) ;
}
return V_86 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_86 ;
snprintf ( V_8 -> V_98 ,
sizeof( V_8 -> V_98 ) - 1 , L_7 ,
F_38 ( & V_8 -> V_12 -> V_13 ) ) ;
V_86 = F_33 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_25 , 0 ,
V_8 -> V_98 , V_25 ) ;
if ( V_86 ) {
F_39 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_98 , V_86 ) ;
F_36 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
return V_86 ;
}
static void F_40 ( struct V_7 * V_8 )
{
int V_39 ;
int V_76 ;
V_76 = V_8 -> V_40 - V_87 ;
for ( V_39 = 0 ; V_39 < V_76 ; V_39 ++ ) {
F_35 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_36 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
V_8 -> V_56 [ V_39 ] ) ;
}
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
F_36 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ )
V_8 -> V_73 [ V_39 ] -> V_99 = V_2 -> V_100 + F_43 ( V_39 ) ;
}
static void F_44 ( struct V_7 * V_8 )
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
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] -> V_99 = V_2 -> V_100 + F_45 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] -> V_105 = V_105 ;
}
}
static struct
V_112 * F_46 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
F_47 (f, &adapter->vlan_filter_list, list) {
if ( V_113 == V_114 -> V_113 )
return V_114 ;
}
return NULL ;
}
static struct
V_112 * F_48 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 = NULL ;
int V_68 = 50 ;
while ( F_49 ( V_115 ,
& V_8 -> V_116 ) ) {
F_50 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_88;
}
V_114 = F_46 ( V_8 , V_113 ) ;
if ( ! V_114 ) {
V_114 = F_7 ( sizeof( * V_114 ) , V_117 ) ;
if ( ! V_114 )
goto V_118;
V_114 -> V_113 = V_113 ;
F_51 ( & V_114 -> V_119 ) ;
F_52 ( & V_114 -> V_119 , & V_8 -> V_120 ) ;
V_114 -> V_121 = true ;
V_8 -> V_89 |= V_122 ;
}
V_118:
F_53 ( V_115 , & V_8 -> V_116 ) ;
V_88:
return V_114 ;
}
static void F_54 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
int V_68 = 50 ;
while ( F_49 ( V_115 ,
& V_8 -> V_116 ) ) {
F_50 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_114 = F_46 ( V_8 , V_113 ) ;
if ( V_114 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_123 ;
}
F_53 ( V_115 , & V_8 -> V_116 ) ;
}
static int F_55 ( struct V_24 * V_25 ,
T_8 T_9 V_124 , T_7 V_125 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( F_48 ( V_8 , V_125 ) == NULL )
return - V_126 ;
return 0 ;
}
static int F_56 ( struct V_24 * V_25 ,
T_8 T_9 V_124 , T_7 V_125 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_54 ( V_8 , V_125 ) ;
return 0 ;
}
static struct
V_127 * F_57 ( struct V_7 * V_8 ,
T_10 * V_128 )
{
struct V_127 * V_114 ;
if ( ! V_128 )
return NULL ;
F_47 (f, &adapter->mac_filter_list, list) {
if ( F_58 ( V_128 , V_114 -> V_128 ) )
return V_114 ;
}
return NULL ;
}
static struct
V_127 * F_59 ( struct V_7 * V_8 ,
T_10 * V_128 )
{
struct V_127 * V_114 ;
int V_68 = 50 ;
if ( ! V_128 )
return NULL ;
while ( F_49 ( V_115 ,
& V_8 -> V_116 ) ) {
F_50 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_114 = F_57 ( V_8 , V_128 ) ;
if ( ! V_114 ) {
V_114 = F_7 ( sizeof( * V_114 ) , V_117 ) ;
if ( ! V_114 ) {
F_53 ( V_115 ,
& V_8 -> V_116 ) ;
return NULL ;
}
F_60 ( V_114 -> V_128 , V_128 ) ;
F_52 ( & V_114 -> V_119 , & V_8 -> V_129 ) ;
V_114 -> V_121 = true ;
V_8 -> V_89 |= V_130 ;
}
F_53 ( V_115 , & V_8 -> V_116 ) ;
return V_114 ;
}
static int F_61 ( struct V_24 * V_25 , void * V_131 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_127 * V_114 ;
struct V_132 * V_133 = V_131 ;
if ( ! F_62 ( V_133 -> V_134 ) )
return - V_135 ;
if ( F_58 ( V_25 -> V_136 , V_133 -> V_134 ) )
return 0 ;
V_114 = F_59 ( V_8 , V_133 -> V_134 ) ;
if ( V_114 ) {
F_60 ( V_2 -> V_137 . V_133 , V_133 -> V_134 ) ;
F_60 ( V_25 -> V_136 , V_8 -> V_2 . V_137 . V_133 ) ;
}
return ( V_114 == NULL ) ? - V_126 : 0 ;
}
static void F_63 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_127 * V_114 , * V_138 ;
struct V_139 * V_140 ;
struct V_139 * V_141 ;
int V_68 = 50 ;
F_64 (uca, netdev) {
F_59 ( V_8 , V_140 -> V_133 ) ;
}
F_65 (mca, netdev) {
F_59 ( V_8 , V_141 -> V_133 ) ;
}
while ( F_49 ( V_115 ,
& V_8 -> V_116 ) ) {
F_50 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_39 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_95 ) ;
return;
}
}
F_66 (f, ftmp, &adapter->mac_filter_list, list) {
bool V_142 = false ;
if ( F_67 ( V_114 -> V_128 ) ) {
F_65 (mca, netdev) {
if ( F_58 ( V_141 -> V_133 , V_114 -> V_128 ) ) {
V_142 = true ;
break;
}
}
} else {
F_64 (uca, netdev) {
if ( F_58 ( V_140 -> V_133 , V_114 -> V_128 ) ) {
V_142 = true ;
break;
}
}
}
if ( V_142 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_143 ;
}
}
F_53 ( V_115 , & V_8 -> V_116 ) ;
}
static void F_68 ( struct V_7 * V_8 )
{
int V_144 ;
struct V_55 * V_56 ;
int V_76 = V_8 -> V_40 - V_87 ;
for ( V_144 = 0 ; V_144 < V_76 ; V_144 ++ ) {
struct V_145 * V_60 ;
V_56 = V_8 -> V_56 [ V_144 ] ;
V_60 = & V_56 -> V_60 ;
F_69 ( V_60 ) ;
}
}
static void F_70 ( struct V_7 * V_8 )
{
int V_144 ;
struct V_55 * V_56 ;
int V_76 = V_8 -> V_40 - V_87 ;
for ( V_144 = 0 ; V_144 < V_76 ; V_144 ++ ) {
V_56 = V_8 -> V_56 [ V_144 ] ;
F_71 ( & V_56 -> V_60 ) ;
}
}
static void F_72 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
F_63 ( V_25 ) ;
F_42 ( V_8 ) ;
F_44 ( V_8 ) ;
V_8 -> V_89 |= V_146 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
struct V_63 * V_58 = V_8 -> V_65 [ V_39 ] ;
F_73 ( V_58 , V_58 -> V_68 ) ;
V_58 -> V_147 = V_58 -> V_68 - 1 ;
F_74 ( V_58 -> V_147 , V_58 -> V_99 ) ;
}
}
static int F_75 ( struct V_7 * V_8 )
{
V_8 -> V_148 = V_149 ;
F_53 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_68 ( V_8 ) ;
V_8 -> V_89 |= V_151 ;
F_76 ( & V_8 -> V_152 , V_153 + 1 ) ;
return 0 ;
}
void F_77 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_127 * V_114 ;
if ( V_8 -> V_148 == V_154 )
return;
while ( F_49 ( V_115 ,
& V_8 -> V_116 ) )
F_78 ( 500 , 1000 ) ;
F_79 ( V_25 ) ;
F_80 ( V_25 ) ;
F_70 ( V_8 ) ;
F_20 ( V_8 ) ;
F_47 (f, &adapter->mac_filter_list, list) {
V_114 -> remove = true ;
}
F_47 (f, &adapter->vlan_filter_list, list) {
V_114 -> remove = true ;
}
if ( ! ( V_8 -> V_27 & V_155 ) &&
V_8 -> V_148 != V_156 ) {
V_8 -> V_157 = V_158 ;
V_8 -> V_89 = V_143 ;
V_8 -> V_89 |= V_123 ;
V_8 -> V_89 |= V_159 ;
}
F_53 ( V_115 , & V_8 -> V_116 ) ;
}
static int
F_81 ( struct V_7 * V_8 , int V_160 )
{
int V_86 , V_161 ;
V_161 = V_162 ;
V_86 = F_82 ( V_8 -> V_12 , V_8 -> V_33 ,
V_161 , V_160 ) ;
if ( V_86 < 0 ) {
F_39 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_86 ;
}
V_8 -> V_40 = V_86 ;
return 0 ;
}
static void F_83 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_163 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
if ( V_8 -> V_73 [ V_39 ] )
F_84 ( V_8 -> V_73 [ V_39 ] , V_164 ) ;
V_8 -> V_73 [ V_39 ] = NULL ;
V_8 -> V_65 [ V_39 ] = NULL ;
}
}
static int F_85 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
struct V_63 * V_72 ;
struct V_63 * V_64 ;
V_72 = F_7 ( sizeof( * V_72 ) * 2 , V_16 ) ;
if ( ! V_72 )
goto V_165;
V_72 -> V_166 = V_39 ;
V_72 -> V_25 = V_8 -> V_25 ;
V_72 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_72 -> V_68 = V_8 -> V_167 ;
V_8 -> V_73 [ V_39 ] = V_72 ;
V_64 = & V_72 [ 1 ] ;
V_64 -> V_166 = V_39 ;
V_64 -> V_25 = V_8 -> V_25 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_168 ;
V_8 -> V_65 [ V_39 ] = V_64 ;
}
return 0 ;
V_165:
F_83 ( V_8 ) ;
return - V_126 ;
}
static int F_86 ( struct V_7 * V_8 )
{
int V_34 , V_169 ;
int V_170 = 0 ;
int V_86 = 0 ;
if ( ! V_8 -> V_163 ) {
V_86 = - V_171 ;
goto V_88;
}
V_170 = V_8 -> V_81 ;
V_169 = F_87 ( int , V_170 , ( int ) ( F_88 () * 2 ) ) + V_87 ;
V_169 = F_87 ( int , V_169 , ( int ) V_8 -> V_172 -> V_173 ) ;
V_8 -> V_33 = F_89 ( V_169 ,
sizeof( struct V_174 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_86 = - V_126 ;
goto V_88;
}
for ( V_34 = 0 ; V_34 < V_169 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_175 = V_34 ;
F_81 ( V_8 , V_169 ) ;
V_88:
V_8 -> V_25 -> V_176 = V_170 ;
return V_86 ;
}
static int F_90 ( struct V_7 * V_8 )
{
int V_144 , V_177 ;
struct V_55 * V_56 ;
V_177 = V_8 -> V_40 - V_87 ;
for ( V_144 = 0 ; V_144 < V_177 ; V_144 ++ ) {
V_56 = F_7 ( sizeof( * V_56 ) , V_16 ) ;
if ( ! V_56 )
goto V_165;
V_56 -> V_8 = V_8 ;
V_56 -> V_67 = & V_8 -> V_67 ;
V_56 -> V_61 = V_144 ;
F_91 ( V_8 -> V_25 , & V_56 -> V_60 ,
V_178 , V_179 ) ;
V_8 -> V_56 [ V_144 ] = V_56 ;
}
return 0 ;
V_165:
while ( V_144 ) {
V_144 -- ;
V_56 = V_8 -> V_56 [ V_144 ] ;
F_92 ( & V_56 -> V_60 ) ;
F_9 ( V_56 ) ;
V_8 -> V_56 [ V_144 ] = NULL ;
}
return - V_126 ;
}
static void F_93 ( struct V_7 * V_8 )
{
int V_144 , V_177 ;
int V_180 ;
V_177 = V_8 -> V_40 - V_87 ;
V_180 = V_8 -> V_81 ;
for ( V_144 = 0 ; V_144 < V_177 ; V_144 ++ ) {
struct V_55 * V_56 = V_8 -> V_56 [ V_144 ] ;
V_8 -> V_56 [ V_144 ] = NULL ;
if ( V_144 < V_180 )
F_92 ( & V_56 -> V_60 ) ;
F_9 ( V_56 ) ;
}
}
void F_94 ( struct V_7 * V_8 )
{
F_95 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_96 ( struct V_7 * V_8 )
{
int V_86 ;
V_86 = F_86 ( V_8 ) ;
if ( V_86 ) {
F_39 ( & V_8 -> V_12 -> V_13 ,
L_11 ) ;
goto V_181;
}
V_86 = F_90 ( V_8 ) ;
if ( V_86 ) {
F_39 ( & V_8 -> V_12 -> V_13 ,
L_12 ) ;
goto V_182;
}
V_86 = F_85 ( V_8 ) ;
if ( V_86 ) {
F_39 ( & V_8 -> V_12 -> V_13 ,
L_13 ) ;
goto V_183;
}
F_34 ( & V_8 -> V_12 -> V_13 , L_14 ,
( V_8 -> V_81 > 1 ) ? L_15 : L_16 ,
V_8 -> V_81 ) ;
return 0 ;
V_183:
F_93 ( V_8 ) ;
V_182:
F_94 ( V_8 ) ;
V_181:
return V_86 ;
}
static void F_97 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_14 ( & V_8 -> V_184 ) ;
}
static void F_98 ( struct V_185 * V_186 )
{
struct V_7 * V_8 = F_99 ( V_186 ,
struct V_7 ,
V_184 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_5 V_187 ;
if ( F_49 ( V_115 , & V_8 -> V_116 ) )
goto V_188;
if ( V_8 -> V_27 & V_155 ) {
V_187 = F_17 ( V_2 , V_32 ) &
V_189 ;
if ( ( V_187 == V_190 ) ||
( V_187 == V_191 ) ) {
F_39 ( & V_8 -> V_12 -> V_13 , L_17 ) ;
V_8 -> V_148 = V_192 ;
V_8 -> V_27 &= ~ V_155 ;
F_100 ( & V_8 -> V_193 , 10 ) ;
F_53 ( V_115 ,
& V_8 -> V_116 ) ;
return;
}
V_8 -> V_89 = 0 ;
V_8 -> V_157 = V_158 ;
goto V_194;
}
if ( ( V_8 -> V_148 < V_154 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_194;
V_187 = F_17 ( V_2 , V_32 ) &
V_189 ;
if ( ! ( V_8 -> V_27 & V_28 ) &&
( V_187 != V_190 ) &&
( V_187 != V_191 ) ) {
V_8 -> V_148 = V_156 ;
V_8 -> V_27 |= V_28 ;
F_39 ( & V_8 -> V_12 -> V_13 , L_18 ) ;
F_14 ( & V_8 -> V_30 ) ;
V_8 -> V_89 = 0 ;
V_8 -> V_157 = V_158 ;
goto V_194;
}
if ( V_8 -> V_157 ) {
if ( ! F_101 ( V_2 ) ) {
F_102 ( & V_8 -> V_12 -> V_13 , L_19 ) ;
F_103 ( V_8 ) ;
}
goto V_194;
}
if ( V_8 -> V_89 & V_159 ) {
F_104 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_90 ) {
F_105 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_130 ) {
F_106 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_122 ) {
F_107 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_143 ) {
F_108 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_123 ) {
F_109 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_146 ) {
F_110 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_89 & V_151 ) {
F_111 ( V_8 ) ;
goto V_194;
}
if ( V_8 -> V_148 == V_149 )
F_112 ( V_8 ) ;
V_194:
if ( V_8 -> V_148 == V_149 ) {
F_22 ( V_8 , ~ 0 ) ;
F_23 ( V_8 , 0xFF ) ;
} else {
F_23 ( V_8 , 0x1 ) ;
}
F_53 ( V_115 , & V_8 -> V_116 ) ;
V_188:
if ( V_8 -> V_148 == V_195 )
return;
if ( V_8 -> V_89 )
F_113 ( & V_8 -> V_152 ,
V_153 + F_114 ( 20 ) ) ;
else
F_113 ( & V_8 -> V_152 , V_153 + ( V_196 * 2 ) ) ;
F_14 ( & V_8 -> V_53 ) ;
}
static void F_115 ( struct V_7 * V_8 )
{
T_3 V_197 [ V_198 + 1 ] ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_199 = 0 ;
T_3 V_200 = 0 ;
int V_39 , V_83 ;
T_2 V_201 ;
F_116 ( V_197 , sizeof( V_197 ) ) ;
for ( V_39 = 0 ; V_39 <= V_198 ; V_39 ++ )
F_16 ( V_2 , F_117 ( V_39 ) , V_197 [ V_39 ] ) ;
V_201 = V_202 ;
F_16 ( V_2 , F_118 ( 0 ) , ( T_3 ) V_201 ) ;
F_16 ( V_2 , F_118 ( 1 ) , ( T_3 ) ( V_201 >> 32 ) ) ;
for ( V_39 = 0 ; V_39 <= V_203 ; V_39 ++ ) {
V_200 = 0 ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( V_199 == V_8 -> V_163 -> V_204 )
V_199 = 0 ;
V_200 |= ( ( V_199 ) << ( 8 * V_83 ) ) ;
V_199 ++ ;
}
F_16 ( V_2 , F_119 ( V_39 ) , V_200 ) ;
}
F_120 ( V_2 ) ;
}
static void F_121 ( struct V_185 * V_186 )
{
struct V_7 * V_8 = F_99 ( V_186 ,
struct V_7 ,
V_30 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_127 * V_114 ;
T_5 V_187 ;
int V_39 = 0 , V_86 ;
while ( F_49 ( V_115 ,
& V_8 -> V_116 ) )
F_78 ( 500 , 1000 ) ;
if ( V_8 -> V_27 & V_29 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
F_122 ( V_8 ) ;
}
for ( V_39 = 0 ; V_39 < V_205 ; V_39 ++ ) {
V_187 = F_17 ( V_2 , V_32 ) &
V_189 ;
if ( ( V_187 != V_190 ) &&
( V_187 != V_191 ) )
break;
F_123 ( V_206 ) ;
}
if ( V_39 == V_205 ) {
V_8 -> V_27 &= ~ V_28 ;
goto V_207;
}
for ( V_39 = 0 ; V_39 < V_205 ; V_39 ++ ) {
V_187 = F_17 ( V_2 , V_32 ) &
V_189 ;
if ( ( V_187 == V_190 ) ||
( V_187 == V_191 ) )
break;
F_123 ( V_206 ) ;
}
if ( V_39 == V_205 ) {
struct V_127 * V_114 , * V_138 ;
struct V_112 * V_208 , * V_209 ;
F_39 ( & V_8 -> V_12 -> V_13 , L_21 ,
V_187 ) ;
V_8 -> V_27 |= V_155 ;
if ( F_124 ( V_8 -> V_25 ) ) {
F_125 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_20 ( V_8 ) ;
F_70 ( V_8 ) ;
F_80 ( V_25 ) ;
F_126 ( V_25 ) ;
F_79 ( V_25 ) ;
F_40 ( V_8 ) ;
F_127 ( V_8 ) ;
F_128 ( V_8 ) ;
}
F_66 (f, ftmp, &adapter->mac_filter_list,
list) {
F_129 ( & V_114 -> V_119 ) ;
F_9 ( V_114 ) ;
}
F_66 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_129 ( & V_208 -> V_119 ) ;
F_9 ( V_208 ) ;
}
F_41 ( V_8 ) ;
F_94 ( V_8 ) ;
F_83 ( V_8 ) ;
F_93 ( V_8 ) ;
F_9 ( V_8 -> V_172 ) ;
F_130 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_210 ;
F_53 ( V_115 , & V_8 -> V_116 ) ;
return;
}
V_207:
V_8 -> V_27 &= ~ V_28 ;
F_20 ( V_8 ) ;
if ( F_124 ( V_8 -> V_25 ) ) {
F_70 ( V_8 ) ;
F_80 ( V_25 ) ;
F_126 ( V_25 ) ;
F_79 ( V_25 ) ;
}
V_8 -> V_148 = V_156 ;
if ( F_130 ( V_2 ) )
F_131 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
V_8 -> V_157 = V_158 ;
V_86 = F_132 ( V_2 ) ;
if ( V_86 )
F_34 ( & V_8 -> V_12 -> V_13 , L_23 ,
V_86 ) ;
F_105 ( V_8 ) ;
F_47 (f, &adapter->mac_filter_list, list) {
V_114 -> V_121 = true ;
}
F_47 (f, &adapter->vlan_filter_list, list) {
V_114 -> V_121 = true ;
}
V_8 -> V_89 = V_130 ;
V_8 -> V_89 |= V_122 ;
F_53 ( V_115 , & V_8 -> V_116 ) ;
F_113 ( & V_8 -> V_152 , V_153 + 2 ) ;
if ( F_124 ( V_8 -> V_25 ) ) {
V_86 = F_133 ( V_8 ) ;
if ( V_86 )
goto V_211;
V_86 = F_134 ( V_8 ) ;
if ( V_86 )
goto V_211;
F_72 ( V_8 ) ;
V_86 = F_75 ( V_8 ) ;
if ( V_86 )
goto V_211;
F_24 ( V_8 , true ) ;
}
return;
V_211:
F_39 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
F_135 ( V_8 -> V_25 ) ;
}
static void F_136 ( struct V_185 * V_186 )
{
struct V_7 * V_8 =
F_99 ( V_186 , struct V_7 , V_53 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_212 V_213 ;
struct V_214 * V_215 ;
T_1 V_216 ;
T_3 V_49 , V_217 ;
T_7 V_218 ;
if ( V_8 -> V_27 & V_155 )
goto V_88;
V_213 . V_219 = V_220 ;
V_213 . V_221 = F_7 ( V_213 . V_219 , V_16 ) ;
if ( ! V_213 . V_221 )
goto V_88;
V_215 = (struct V_214 * ) & V_213 . V_222 ;
do {
V_216 = F_137 ( V_2 , & V_213 , & V_218 ) ;
if ( V_216 || ! V_215 -> V_223 )
break;
F_138 ( V_8 , V_215 -> V_223 ,
V_215 -> V_224 , V_213 . V_221 ,
V_213 . V_225 ) ;
if ( V_218 != 0 )
memset ( V_213 . V_221 , 0 , V_220 ) ;
} while ( V_218 );
V_49 = F_17 ( V_2 , V_2 -> V_226 . V_227 . V_228 ) ;
V_217 = V_49 ;
if ( V_49 & V_229 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
V_49 &= ~ V_229 ;
}
if ( V_49 & V_230 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
V_49 &= ~ V_230 ;
}
if ( V_49 & V_231 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
V_49 &= ~ V_231 ;
}
if ( V_217 != V_49 )
F_16 ( V_2 , V_2 -> V_226 . V_227 . V_228 , V_49 ) ;
V_49 = F_17 ( V_2 , V_2 -> V_226 . V_232 . V_228 ) ;
V_217 = V_49 ;
if ( V_49 & V_233 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_49 &= ~ V_233 ;
}
if ( V_49 & V_234 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_234 ;
}
if ( V_49 & V_235 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_235 ;
}
if ( V_217 != V_49 )
F_16 ( V_2 , V_2 -> V_226 . V_232 . V_228 , V_49 ) ;
F_9 ( V_213 . V_221 ) ;
V_88:
F_19 ( V_8 ) ;
}
void F_127 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ )
if ( V_8 -> V_73 [ V_39 ] -> V_222 )
F_139 ( V_8 -> V_73 [ V_39 ] ) ;
}
static int F_133 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
V_8 -> V_73 [ V_39 ] -> V_68 = V_8 -> V_167 ;
V_86 = F_140 ( V_8 -> V_73 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_39 ( & V_8 -> V_12 -> V_13 ,
L_31 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
static int F_134 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] -> V_68 = V_8 -> V_168 ;
V_86 = F_141 ( V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_39 ( & V_8 -> V_12 -> V_13 ,
L_32 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
void F_128 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] -> V_222 )
F_142 ( V_8 -> V_65 [ V_39 ] ) ;
}
static int F_143 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_86 ;
if ( V_8 -> V_27 & V_155 ) {
F_39 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
return - V_171 ;
}
if ( V_8 -> V_148 != V_154 || V_8 -> V_89 )
return - V_236 ;
V_86 = F_133 ( V_8 ) ;
if ( V_86 )
goto V_237;
V_86 = F_134 ( V_8 ) ;
if ( V_86 )
goto V_238;
V_86 = F_32 ( V_8 , V_25 -> V_94 ) ;
if ( V_86 )
goto V_239;
F_72 ( V_8 ) ;
V_86 = F_75 ( V_8 ) ;
if ( V_86 )
goto V_239;
F_24 ( V_8 , true ) ;
return 0 ;
V_239:
F_77 ( V_8 ) ;
F_40 ( V_8 ) ;
V_238:
F_128 ( V_8 ) ;
V_237:
F_127 ( V_8 ) ;
return V_86 ;
}
static int F_135 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_148 <= V_154 )
return 0 ;
F_125 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_77 ( V_8 ) ;
V_8 -> V_148 = V_154 ;
F_40 ( V_8 ) ;
return 0 ;
}
static struct V_240 * F_144 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_241 ;
}
void F_145 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_86 ;
F_146 ( F_147 () ) ;
F_77 ( V_8 ) ;
V_86 = F_133 ( V_8 ) ;
if ( V_86 )
goto V_242;
V_86 = F_134 ( V_8 ) ;
if ( V_86 )
goto V_242;
F_72 ( V_8 ) ;
V_86 = F_75 ( V_8 ) ;
if ( V_86 )
goto V_242;
F_24 ( V_8 , true ) ;
return;
V_242:
F_39 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
F_135 ( V_25 ) ;
}
static int F_148 ( struct V_24 * V_25 , int V_243 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_101 = V_243 + V_103 + V_104 ;
if ( ( V_243 < 68 ) || ( V_101 > V_244 ) )
return - V_245 ;
V_25 -> V_102 = V_243 ;
F_145 ( V_8 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 )
{
T_3 V_246 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_246 = F_17 ( V_2 , V_32 ) &
V_189 ;
if ( ( V_246 == V_190 ) ||
( V_246 == V_191 ) )
return 0 ;
F_78 ( 10 , 20 ) ;
}
return - V_236 ;
}
static void F_150 ( struct V_185 * V_186 )
{
struct V_7 * V_8 = F_99 ( V_186 ,
struct V_7 ,
V_193 . V_186 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_127 * V_114 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_247 * V_12 = V_8 -> V_12 ;
int V_39 , V_86 , V_248 ;
switch ( V_8 -> V_148 ) {
case V_192 :
V_8 -> V_27 &= ~ V_155 ;
V_8 -> V_27 &= ~ V_28 ;
V_86 = F_151 ( V_2 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_34 ,
V_86 ) ;
goto V_86;
}
V_86 = F_149 ( V_2 ) ;
if ( V_86 ) {
F_34 ( & V_12 -> V_13 , L_35 ,
V_86 ) ;
goto V_86;
}
V_2 -> V_226 . V_249 = V_250 ;
V_2 -> V_226 . V_251 = V_250 ;
V_2 -> V_226 . V_252 = V_220 ;
V_2 -> V_226 . V_253 = V_220 ;
V_86 = F_132 ( V_2 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_36 ,
V_86 ) ;
goto V_86;
}
V_86 = F_103 ( V_8 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_37 , V_86 ) ;
F_130 ( V_2 ) ;
goto V_86;
}
V_8 -> V_148 = V_254 ;
goto V_255;
case V_254 :
if ( ! F_101 ( V_2 ) ) {
F_39 ( & V_12 -> V_13 , L_38 ) ;
F_130 ( V_2 ) ;
V_8 -> V_148 = V_192 ;
goto V_86;
}
V_86 = F_152 ( V_8 ) ;
if ( V_86 ) {
if ( V_86 == V_256 )
V_86 = F_103 ( V_8 ) ;
goto V_86;
}
V_86 = F_153 ( V_8 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_39 ,
V_86 ) ;
goto V_86;
}
V_8 -> V_148 = V_257 ;
goto V_255;
case V_257 :
if ( ! V_8 -> V_172 ) {
V_248 = sizeof( struct V_258 ) +
( V_259 *
sizeof( struct V_260 ) ) ;
V_8 -> V_172 = F_7 ( V_248 , V_16 ) ;
if ( ! V_8 -> V_172 )
goto V_86;
}
V_86 = F_154 ( V_8 ) ;
if ( V_86 == V_256 ) {
V_86 = F_153 ( V_8 ) ;
goto V_86;
}
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_40 ,
V_86 ) ;
goto V_261;
}
V_8 -> V_148 = V_262 ;
break;
default:
goto V_261;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_172 -> V_263 ; V_39 ++ ) {
if ( V_8 -> V_172 -> V_163 [ V_39 ] . V_264 == V_265 )
V_8 -> V_163 = & V_8 -> V_172 -> V_163 [ V_39 ] ;
}
if ( ! V_8 -> V_163 ) {
F_39 ( & V_12 -> V_13 , L_41 ) ;
goto V_261;
}
V_8 -> V_27 |= V_266 ;
V_25 -> V_267 = & V_268 ;
F_155 ( V_25 ) ;
V_25 -> V_269 = 5 * V_196 ;
V_25 -> V_270 |= V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 |
V_277 |
V_278 |
V_279 ;
if ( V_8 -> V_172 -> V_280
& V_281 ) {
V_25 -> V_282 = V_25 -> V_270 ;
V_25 -> V_270 |= V_283 |
V_284 |
V_285 ;
}
V_25 -> V_286 |= V_25 -> V_270 ;
V_25 -> V_286 &= ~ V_278 ;
if ( ! F_62 ( V_8 -> V_2 . V_137 . V_133 ) ) {
F_34 ( & V_12 -> V_13 , L_42 ,
V_8 -> V_2 . V_137 . V_133 ) ;
F_156 ( V_8 -> V_2 . V_137 . V_133 ) ;
}
F_60 ( V_25 -> V_136 , V_8 -> V_2 . V_137 . V_133 ) ;
F_60 ( V_25 -> V_287 , V_8 -> V_2 . V_137 . V_133 ) ;
V_114 = F_7 ( sizeof( * V_114 ) , V_117 ) ;
if ( ! V_114 )
goto V_288;
F_60 ( V_114 -> V_128 , V_8 -> V_2 . V_137 . V_133 ) ;
V_114 -> V_121 = true ;
V_8 -> V_89 |= V_130 ;
F_52 ( & V_114 -> V_119 , & V_8 -> V_129 ) ;
F_157 ( & V_8 -> V_152 ) ;
V_8 -> V_152 . V_289 = & F_97 ;
V_8 -> V_152 . V_48 = ( unsigned long ) V_8 ;
F_113 ( & V_8 -> V_152 , V_153 + 1 ) ;
V_8 -> V_81 = F_87 ( int ,
V_8 -> V_163 -> V_204 ,
( int ) ( F_88 () ) ) ;
V_8 -> V_167 = V_290 ;
V_8 -> V_168 = V_291 ;
V_86 = F_96 ( V_8 ) ;
if ( V_86 )
goto V_288;
F_30 ( V_8 ) ;
F_115 ( V_8 ) ;
V_86 = F_37 ( V_8 ) ;
if ( V_86 )
goto V_288;
F_79 ( V_25 ) ;
V_8 -> V_67 . V_292 = V_8 -> V_163 -> V_293 ;
V_8 -> V_67 . V_294 = V_8 -> V_163 -> V_293 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_295 = 1 ;
V_8 -> V_67 . V_296 = V_297 ;
V_8 -> V_67 . V_298 = ( V_299 |
F_158 ( V_300 ) ) ;
V_8 -> V_67 . V_301 = ( V_299 |
F_158 ( V_302 ) ) ;
V_8 -> V_67 . V_25 = V_8 -> V_25 ;
if ( ! V_8 -> V_303 ) {
V_86 = F_159 ( V_25 ) ;
if ( V_86 )
goto V_304;
}
V_8 -> V_303 = true ;
F_126 ( V_25 ) ;
F_34 ( & V_12 -> V_13 , L_43 , V_8 -> V_2 . V_137 . V_133 ) ;
if ( V_25 -> V_270 & V_279 )
F_34 ( & V_12 -> V_13 , L_44 ) ;
F_34 ( & V_12 -> V_13 , L_45 , V_305 ) ;
V_8 -> V_148 = V_154 ;
F_125 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_19 ( V_8 ) ;
return;
V_255:
F_100 ( & V_8 -> V_193 ,
F_114 ( 50 ) ) ;
return;
V_304:
F_41 ( V_8 ) ;
V_288:
F_94 ( V_8 ) ;
V_261:
F_9 ( V_8 -> V_172 ) ;
V_8 -> V_172 = NULL ;
V_86:
if ( ++ V_8 -> V_306 > V_307 ) {
F_39 ( & V_12 -> V_13 , L_46 ) ;
V_8 -> V_27 |= V_155 ;
return;
}
F_100 ( & V_8 -> V_193 , V_196 * 3 ) ;
}
static void F_160 ( struct V_247 * V_12 )
{
struct V_24 * V_25 = F_161 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_162 ( V_25 ) ;
if ( F_124 ( V_25 ) )
F_135 ( V_25 ) ;
V_8 -> V_148 = V_195 ;
V_8 -> V_89 = 0 ;
#ifdef F_163
F_164 ( V_12 ) ;
#endif
F_165 ( V_12 ) ;
}
static int F_166 ( struct V_247 * V_12 , const struct V_308 * V_309 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_86 ;
V_86 = F_167 ( V_12 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_168 ( & V_12 -> V_13 , F_169 ( 64 ) ) ;
if ( V_86 ) {
V_86 = F_168 ( & V_12 -> V_13 , F_169 ( 32 ) ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 ,
L_47 , V_86 ) ;
goto V_310;
}
}
V_86 = F_170 ( V_12 , V_311 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 ,
L_48 , V_86 ) ;
goto V_312;
}
F_171 ( V_12 ) ;
F_172 ( V_12 ) ;
V_25 = F_173 ( sizeof( struct V_7 ) ,
V_313 ) ;
if ( ! V_25 ) {
V_86 = - V_126 ;
goto V_314;
}
F_174 ( V_25 , & V_12 -> V_13 ) ;
F_175 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_315 = ( 1 << V_316 ) - 1 ;
V_8 -> V_148 = V_192 ;
F_164 ( V_12 ) ;
V_2 -> V_100 = F_176 ( F_177 ( V_12 , 0 ) ,
F_178 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_100 ) {
V_86 = - V_171 ;
goto V_317;
}
V_2 -> V_318 = V_12 -> V_319 ;
V_2 -> V_320 = V_12 -> V_321 ;
F_179 ( V_12 , V_322 , & V_2 -> V_323 ) ;
V_2 -> V_324 = V_12 -> V_325 ;
V_2 -> V_326 = V_12 -> V_327 ;
V_2 -> V_328 . V_321 = F_180 ( V_12 -> V_329 ) ;
V_2 -> V_328 . V_330 = F_181 ( V_12 -> V_329 ) ;
F_51 ( & V_8 -> V_129 ) ;
F_51 ( & V_8 -> V_120 ) ;
F_182 ( & V_8 -> V_30 , F_121 ) ;
F_182 ( & V_8 -> V_53 , F_136 ) ;
F_182 ( & V_8 -> V_184 , F_98 ) ;
F_183 ( & V_8 -> V_193 , F_150 ) ;
F_100 ( & V_8 -> V_193 , 10 ) ;
return 0 ;
V_317:
F_184 ( V_25 ) ;
V_314:
F_185 ( V_12 ) ;
V_312:
V_310:
F_165 ( V_12 ) ;
return V_86 ;
}
static int F_186 ( struct V_247 * V_12 , T_11 V_148 )
{
struct V_24 * V_25 = F_161 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_331 = 0 ;
F_162 ( V_25 ) ;
if ( F_124 ( V_25 ) ) {
F_187 () ;
F_77 ( V_8 ) ;
F_188 () ;
}
F_41 ( V_8 ) ;
F_94 ( V_8 ) ;
V_331 = F_164 ( V_12 ) ;
if ( V_331 )
return V_331 ;
F_165 ( V_12 ) ;
return 0 ;
}
static int F_189 ( struct V_247 * V_12 )
{
struct V_7 * V_8 = F_161 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_86 ;
F_190 ( V_12 , V_332 ) ;
F_191 ( V_12 ) ;
F_164 ( V_12 ) ;
V_86 = F_192 ( V_12 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_49 ) ;
return V_86 ;
}
F_172 ( V_12 ) ;
F_187 () ;
V_86 = F_86 ( V_8 ) ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_50 ) ;
return V_86 ;
}
V_86 = F_37 ( V_8 ) ;
F_188 () ;
if ( V_86 ) {
F_39 ( & V_12 -> V_13 , L_51 ) ;
return V_86 ;
}
F_14 ( & V_8 -> V_30 ) ;
F_193 ( V_25 ) ;
return V_86 ;
}
static void F_194 ( struct V_247 * V_12 )
{
struct V_24 * V_25 = F_161 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_127 * V_114 , * V_138 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_195 ( & V_8 -> V_193 ) ;
F_196 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_303 ) {
F_197 ( V_25 ) ;
V_8 -> V_303 = false ;
}
V_8 -> V_148 = V_195 ;
V_8 -> V_89 = 0 ;
F_122 ( V_8 ) ;
F_123 ( 20 ) ;
if ( ! F_101 ( V_2 ) ) {
F_122 ( V_8 ) ;
F_123 ( 20 ) ;
}
if ( V_8 -> V_33 ) {
F_15 ( V_8 ) ;
F_41 ( V_8 ) ;
F_94 ( V_8 ) ;
F_93 ( V_8 ) ;
}
if ( V_8 -> V_152 . V_289 )
F_198 ( & V_8 -> V_152 ) ;
F_199 () ;
if ( V_2 -> V_226 . V_232 . V_68 )
F_130 ( V_2 ) ;
F_200 ( V_2 -> V_100 ) ;
F_185 ( V_12 ) ;
F_127 ( V_8 ) ;
F_128 ( V_8 ) ;
F_83 ( V_8 ) ;
F_9 ( V_8 -> V_172 ) ;
F_66 (f, ftmp, &adapter->mac_filter_list, list) {
F_129 ( & V_114 -> V_119 ) ;
F_9 ( V_114 ) ;
}
F_66 (f, ftmp, &adapter->vlan_filter_list, list) {
F_129 ( & V_114 -> V_119 ) ;
F_9 ( V_114 ) ;
}
F_184 ( V_25 ) ;
F_201 ( V_12 ) ;
F_165 ( V_12 ) ;
}
static int T_12 F_202 ( void )
{
int V_216 ;
F_11 ( L_52 , V_305 ,
V_333 ) ;
F_11 ( L_45 , V_334 ) ;
V_216 = F_203 ( & V_335 ) ;
return V_216 ;
}
static void T_13 F_204 ( void )
{
F_205 ( & V_335 ) ;
}
