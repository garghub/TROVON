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
if ( ! ( V_8 -> V_27 & ( V_28 |
V_29 ) ) ) {
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
if ( V_19 & F_23 ( V_39 - 1 ) ) {
F_16 ( V_2 , F_21 ( V_39 - 1 ) ,
V_41 |
V_42 |
V_43 ) ;
}
}
}
static void F_24 ( struct V_7 * V_8 , T_3 V_19 )
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
if ( V_19 & F_23 ( V_39 ) ) {
V_44 = F_17 ( V_2 , F_21 ( V_39 - 1 ) ) ;
V_44 |= V_45 |
V_42 |
V_43 ;
F_16 ( V_2 , F_21 ( V_39 - 1 ) , V_44 ) ;
}
}
}
void F_25 ( struct V_7 * V_8 , bool V_46 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_19 ( V_8 ) ;
F_22 ( V_8 , ~ 0 ) ;
if ( V_46 )
F_17 ( V_2 , V_32 ) ;
}
static T_6 F_26 ( int V_47 , void * V_48 )
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
static T_6 F_27 ( int V_47 , void * V_48 )
{
struct V_55 * V_56 = V_48 ;
if ( ! V_56 -> V_57 . V_58 && ! V_56 -> V_59 . V_58 )
return V_54 ;
F_28 ( & V_56 -> V_60 ) ;
return V_54 ;
}
static void
F_29 ( struct V_7 * V_8 , int V_61 , int V_62 )
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
F_30 ( struct V_7 * V_8 , int V_61 , int V_71 )
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
V_56 -> V_75 |= F_23 ( V_71 ) ;
}
static int F_31 ( struct V_7 * V_8 )
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
if ( V_76 >= ( V_80 * 2 ) ) {
for (; V_78 < V_80 ; V_77 ++ , V_78 ++ )
F_29 ( V_8 , V_77 , V_78 ) ;
for (; V_79 < V_82 ; V_77 ++ , V_79 ++ )
F_30 ( V_8 , V_77 , V_79 ) ;
goto V_88;
}
for ( V_39 = V_77 ; V_39 < V_76 ; V_39 ++ ) {
V_84 = F_32 ( V_80 , V_76 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
F_29 ( V_8 , V_39 , V_78 ) ;
V_78 ++ ;
V_80 -- ;
}
}
for ( V_39 = V_77 ; V_39 < V_76 ; V_39 ++ ) {
V_85 = F_32 ( V_82 , V_76 - V_39 ) ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
F_30 ( V_8 , V_39 , V_79 ) ;
V_79 ++ ;
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
V_86 = F_34 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
F_27 ,
0 ,
V_56 -> V_94 ,
V_56 ) ;
if ( V_86 ) {
F_35 ( & V_8 -> V_12 -> V_13 ,
L_6 ,
V_95 , V_86 ) ;
goto V_96;
}
F_36 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
V_56 -> V_97 ) ;
}
return 0 ;
V_96:
while ( V_34 ) {
V_34 -- ;
F_36 (
V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
NULL ) ;
F_37 ( V_8 -> V_33 [ V_34 + V_87 ] . V_34 ,
V_8 -> V_56 [ V_34 ] ) ;
}
return V_86 ;
}
static int F_38 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_86 ;
snprintf ( V_8 -> V_98 ,
sizeof( V_8 -> V_98 ) - 1 , L_7 ,
F_39 ( & V_8 -> V_12 -> V_13 ) ) ;
V_86 = F_34 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_26 , 0 ,
V_8 -> V_98 , V_25 ) ;
if ( V_86 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_98 , V_86 ) ;
F_37 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
return V_86 ;
}
static void F_41 ( struct V_7 * V_8 )
{
int V_39 ;
int V_76 ;
V_76 = V_8 -> V_40 - V_87 ;
for ( V_39 = 0 ; V_39 < V_76 ; V_39 ++ ) {
F_36 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_37 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
V_8 -> V_56 [ V_39 ] ) ;
}
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
F_37 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ )
V_8 -> V_73 [ V_39 ] -> V_99 = V_2 -> V_100 + F_44 ( V_39 ) ;
}
static void F_45 ( struct V_7 * V_8 )
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
V_8 -> V_65 [ V_39 ] -> V_99 = V_2 -> V_100 + F_46 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] -> V_105 = V_105 ;
}
}
static struct
V_112 * F_47 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
F_48 (f, &adapter->vlan_filter_list, list) {
if ( V_113 == V_114 -> V_113 )
return V_114 ;
}
return NULL ;
}
static struct
V_112 * F_49 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 = NULL ;
int V_68 = 50 ;
while ( F_50 ( V_115 ,
& V_8 -> V_116 ) ) {
F_51 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_88;
}
V_114 = F_47 ( V_8 , V_113 ) ;
if ( ! V_114 ) {
V_114 = F_7 ( sizeof( * V_114 ) , V_117 ) ;
if ( ! V_114 )
goto V_118;
V_114 -> V_113 = V_113 ;
F_52 ( & V_114 -> V_119 ) ;
F_53 ( & V_114 -> V_119 , & V_8 -> V_120 ) ;
V_114 -> V_121 = true ;
V_8 -> V_89 |= V_122 ;
}
V_118:
F_54 ( V_115 , & V_8 -> V_116 ) ;
V_88:
return V_114 ;
}
static void F_55 ( struct V_7 * V_8 , T_7 V_113 )
{
struct V_112 * V_114 ;
int V_68 = 50 ;
while ( F_50 ( V_115 ,
& V_8 -> V_116 ) ) {
F_51 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_114 = F_47 ( V_8 , V_113 ) ;
if ( V_114 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_123 ;
}
F_54 ( V_115 , & V_8 -> V_116 ) ;
}
static int F_56 ( struct V_24 * V_25 ,
T_8 T_9 V_124 , T_7 V_125 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( F_49 ( V_8 , V_125 ) == NULL )
return - V_126 ;
return 0 ;
}
static int F_57 ( struct V_24 * V_25 ,
T_8 T_9 V_124 , T_7 V_125 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_55 ( V_8 , V_125 ) ;
return 0 ;
}
static struct
V_127 * F_58 ( struct V_7 * V_8 ,
T_10 * V_128 )
{
struct V_127 * V_114 ;
if ( ! V_128 )
return NULL ;
F_48 (f, &adapter->mac_filter_list, list) {
if ( F_59 ( V_128 , V_114 -> V_128 ) )
return V_114 ;
}
return NULL ;
}
static struct
V_127 * F_60 ( struct V_7 * V_8 ,
T_10 * V_128 )
{
struct V_127 * V_114 ;
int V_68 = 50 ;
if ( ! V_128 )
return NULL ;
while ( F_50 ( V_115 ,
& V_8 -> V_116 ) ) {
F_51 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_114 = F_58 ( V_8 , V_128 ) ;
if ( ! V_114 ) {
V_114 = F_7 ( sizeof( * V_114 ) , V_117 ) ;
if ( ! V_114 ) {
F_54 ( V_115 ,
& V_8 -> V_116 ) ;
return NULL ;
}
F_61 ( V_114 -> V_128 , V_128 ) ;
F_53 ( & V_114 -> V_119 , & V_8 -> V_129 ) ;
V_114 -> V_121 = true ;
V_8 -> V_89 |= V_130 ;
}
F_54 ( V_115 , & V_8 -> V_116 ) ;
return V_114 ;
}
static int F_62 ( struct V_24 * V_25 , void * V_131 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_127 * V_114 ;
struct V_132 * V_133 = V_131 ;
if ( ! F_63 ( V_133 -> V_134 ) )
return - V_135 ;
if ( F_59 ( V_25 -> V_136 , V_133 -> V_134 ) )
return 0 ;
V_114 = F_60 ( V_8 , V_133 -> V_134 ) ;
if ( V_114 ) {
F_61 ( V_2 -> V_137 . V_133 , V_133 -> V_134 ) ;
F_61 ( V_25 -> V_136 , V_8 -> V_2 . V_137 . V_133 ) ;
}
return ( V_114 == NULL ) ? - V_126 : 0 ;
}
static void F_64 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_127 * V_114 , * V_138 ;
struct V_139 * V_140 ;
struct V_139 * V_141 ;
int V_68 = 50 ;
F_65 (uca, netdev) {
F_60 ( V_8 , V_140 -> V_133 ) ;
}
F_66 (mca, netdev) {
F_60 ( V_8 , V_141 -> V_133 ) ;
}
while ( F_50 ( V_115 ,
& V_8 -> V_116 ) ) {
F_51 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_95 ) ;
return;
}
}
F_67 (f, ftmp, &adapter->mac_filter_list, list) {
bool V_142 = false ;
if ( F_68 ( V_114 -> V_128 ) ) {
F_66 (mca, netdev) {
if ( F_59 ( V_141 -> V_133 , V_114 -> V_128 ) ) {
V_142 = true ;
break;
}
}
} else {
F_65 (uca, netdev) {
if ( F_59 ( V_140 -> V_133 , V_114 -> V_128 ) ) {
V_142 = true ;
break;
}
}
if ( F_59 ( V_114 -> V_128 , V_8 -> V_2 . V_137 . V_133 ) )
V_142 = true ;
}
if ( ! V_142 ) {
V_114 -> remove = true ;
V_8 -> V_89 |= V_143 ;
}
}
F_54 ( V_115 , & V_8 -> V_116 ) ;
}
static void F_69 ( struct V_7 * V_8 )
{
int V_144 ;
struct V_55 * V_56 ;
int V_76 = V_8 -> V_40 - V_87 ;
for ( V_144 = 0 ; V_144 < V_76 ; V_144 ++ ) {
struct V_145 * V_60 ;
V_56 = V_8 -> V_56 [ V_144 ] ;
V_60 = & V_56 -> V_60 ;
F_70 ( V_60 ) ;
}
}
static void F_71 ( struct V_7 * V_8 )
{
int V_144 ;
struct V_55 * V_56 ;
int V_76 = V_8 -> V_40 - V_87 ;
for ( V_144 = 0 ; V_144 < V_76 ; V_144 ++ ) {
V_56 = V_8 -> V_56 [ V_144 ] ;
F_72 ( & V_56 -> V_60 ) ;
}
}
static void F_73 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
F_64 ( V_25 ) ;
F_43 ( V_8 ) ;
F_45 ( V_8 ) ;
V_8 -> V_89 |= V_146 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
struct V_63 * V_58 = V_8 -> V_65 [ V_39 ] ;
F_74 ( V_58 , V_58 -> V_68 ) ;
V_58 -> V_147 = V_58 -> V_68 - 1 ;
F_75 ( V_58 -> V_147 , V_58 -> V_99 ) ;
}
}
static int F_76 ( struct V_7 * V_8 )
{
V_8 -> V_148 = V_149 ;
F_54 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_69 ( V_8 ) ;
V_8 -> V_89 |= V_151 ;
F_77 ( & V_8 -> V_152 , V_153 + 1 ) ;
return 0 ;
}
void F_78 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_127 * V_114 ;
if ( V_8 -> V_148 == V_154 )
return;
while ( F_50 ( V_115 ,
& V_8 -> V_116 ) )
F_79 ( 500 , 1000 ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_71 ( V_8 ) ;
F_20 ( V_8 ) ;
F_48 (f, &adapter->mac_filter_list, list) {
V_114 -> remove = true ;
}
F_48 (f, &adapter->vlan_filter_list, list) {
V_114 -> remove = true ;
}
if ( ! ( V_8 -> V_27 & V_155 ) &&
V_8 -> V_148 != V_156 ) {
V_8 -> V_157 = V_158 ;
V_8 -> V_89 = V_143 ;
V_8 -> V_89 |= V_123 ;
V_8 -> V_89 |= V_159 ;
}
F_54 ( V_115 , & V_8 -> V_116 ) ;
}
static int
F_82 ( struct V_7 * V_8 , int V_160 )
{
int V_86 , V_161 ;
V_161 = V_162 ;
V_86 = F_83 ( V_8 -> V_12 , V_8 -> V_33 ,
V_161 , V_160 ) ;
if ( V_86 < 0 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_86 ;
}
V_8 -> V_40 = V_86 ;
return 0 ;
}
static void F_84 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_163 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
if ( V_8 -> V_73 [ V_39 ] )
F_85 ( V_8 -> V_73 [ V_39 ] , V_164 ) ;
V_8 -> V_73 [ V_39 ] = NULL ;
V_8 -> V_65 [ V_39 ] = NULL ;
}
}
static int F_86 ( struct V_7 * V_8 )
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
F_84 ( V_8 ) ;
return - V_126 ;
}
static int F_87 ( struct V_7 * V_8 )
{
int V_34 , V_169 ;
int V_170 = 0 ;
int V_86 = 0 ;
if ( ! V_8 -> V_163 ) {
V_86 = - V_171 ;
goto V_88;
}
V_170 = V_8 -> V_81 ;
V_169 = F_88 ( int , V_170 , ( int ) ( F_89 () * 2 ) ) + V_87 ;
V_169 = F_88 ( int , V_169 , ( int ) V_8 -> V_172 -> V_173 ) ;
V_8 -> V_33 = F_90 ( V_169 ,
sizeof( struct V_174 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_86 = - V_126 ;
goto V_88;
}
for ( V_34 = 0 ; V_34 < V_169 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_175 = V_34 ;
F_82 ( V_8 , V_169 ) ;
V_88:
V_8 -> V_25 -> V_176 = V_170 ;
return V_86 ;
}
static void F_91 ( struct V_177 * V_67 , const T_10 * V_178 )
{
struct V_179 V_180 ;
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_181 = 0 , V_39 ;
T_10 * V_182 ;
if ( ! V_67 -> V_183 )
return;
if ( V_8 -> V_157 != V_158 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_157 ) ;
return;
}
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
memcpy ( & V_180 , V_178 , sizeof( V_180 ) ) ;
V_182 = F_7 ( ( ( V_184 + 1 ) * 4 ) , V_16 ) ;
if ( ! V_182 )
return;
for ( V_39 = 0 ; V_39 <= ( V_184 * 4 ) ; V_39 ++ )
V_182 [ V_39 ] = V_39 % V_8 -> V_81 ;
V_181 = F_92 ( V_2 , V_67 -> V_183 , & V_180 ) ;
if ( V_181 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_12 ,
F_93 ( V_2 , V_181 ) ,
F_94 ( V_2 , V_2 -> V_185 . V_186 ) ) ;
return;
}
V_181 = F_95 ( V_2 , V_67 -> V_183 , false , V_182 ,
( V_184 + 1 ) * 4 ) ;
if ( V_181 )
F_40 ( & V_8 -> V_12 -> V_13 ,
L_13 ,
F_93 ( V_2 , V_181 ) ,
F_94 ( V_2 , V_2 -> V_185 . V_186 ) ) ;
}
static void F_96 ( struct V_7 * V_8 ,
const T_10 * V_178 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 * V_187 = ( T_3 * ) V_178 ;
T_3 V_188 = 0 ;
T_3 V_189 = 0 ;
int V_39 , V_83 ;
for ( V_39 = 0 ; V_39 <= V_190 ; V_39 ++ )
F_16 ( V_2 , F_97 ( V_39 ) , V_187 [ V_39 ] ) ;
for ( V_39 = 0 ; V_39 <= V_184 ; V_39 ++ ) {
V_189 = 0 ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( V_188 == V_8 -> V_81 )
V_188 = 0 ;
V_189 |= ( ( V_188 ) << ( 8 * V_83 ) ) ;
V_188 ++ ;
}
F_16 ( V_2 , F_98 ( V_39 ) , V_189 ) ;
}
F_99 ( V_2 ) ;
}
static void F_100 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_10 V_178 [ V_191 ] ;
T_2 V_192 ;
F_101 ( ( void * ) V_178 , V_191 ) ;
V_192 = V_193 ;
F_16 ( V_2 , F_102 ( 0 ) , ( T_3 ) V_192 ) ;
F_16 ( V_2 , F_102 ( 1 ) , ( T_3 ) ( V_192 >> 32 ) ) ;
if ( F_103 ( V_8 ) )
F_91 ( & V_8 -> V_67 , V_178 ) ;
else
F_96 ( V_8 , V_178 ) ;
}
static int F_104 ( struct V_7 * V_8 )
{
int V_144 , V_194 ;
struct V_55 * V_56 ;
V_194 = V_8 -> V_40 - V_87 ;
for ( V_144 = 0 ; V_144 < V_194 ; V_144 ++ ) {
V_56 = F_7 ( sizeof( * V_56 ) , V_16 ) ;
if ( ! V_56 )
goto V_165;
V_56 -> V_8 = V_8 ;
V_56 -> V_67 = & V_8 -> V_67 ;
V_56 -> V_61 = V_144 ;
F_105 ( V_8 -> V_25 , & V_56 -> V_60 ,
V_195 , V_196 ) ;
V_8 -> V_56 [ V_144 ] = V_56 ;
}
return 0 ;
V_165:
while ( V_144 ) {
V_144 -- ;
V_56 = V_8 -> V_56 [ V_144 ] ;
F_106 ( & V_56 -> V_60 ) ;
F_9 ( V_56 ) ;
V_8 -> V_56 [ V_144 ] = NULL ;
}
return - V_126 ;
}
static void F_107 ( struct V_7 * V_8 )
{
int V_144 , V_194 ;
int V_197 ;
V_194 = V_8 -> V_40 - V_87 ;
V_197 = V_8 -> V_81 ;
for ( V_144 = 0 ; V_144 < V_194 ; V_144 ++ ) {
struct V_55 * V_56 = V_8 -> V_56 [ V_144 ] ;
V_8 -> V_56 [ V_144 ] = NULL ;
if ( V_144 < V_197 )
F_106 ( & V_56 -> V_60 ) ;
F_9 ( V_56 ) ;
}
}
void F_108 ( struct V_7 * V_8 )
{
F_109 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_110 ( struct V_7 * V_8 )
{
int V_86 ;
V_86 = F_87 ( V_8 ) ;
if ( V_86 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_198;
}
V_86 = F_104 ( V_8 ) ;
if ( V_86 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_199;
}
V_86 = F_86 ( V_8 ) ;
if ( V_86 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_200;
}
F_35 ( & V_8 -> V_12 -> V_13 , L_17 ,
( V_8 -> V_81 > 1 ) ? L_18 : L_19 ,
V_8 -> V_81 ) ;
return 0 ;
V_200:
F_107 ( V_8 ) ;
V_199:
F_108 ( V_8 ) ;
V_198:
return V_86 ;
}
static void F_111 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_14 ( & V_8 -> V_201 ) ;
}
static void F_112 ( struct V_202 * V_203 )
{
struct V_7 * V_8 = F_113 ( V_203 ,
struct V_7 ,
V_201 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_5 V_204 ;
if ( F_50 ( V_115 , & V_8 -> V_116 ) )
goto V_205;
if ( V_8 -> V_27 & V_155 ) {
V_204 = F_17 ( V_2 , V_32 ) &
V_206 ;
if ( ( V_204 == V_207 ) ||
( V_204 == V_208 ) ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_148 = V_209 ;
V_8 -> V_27 &= ~ V_155 ;
F_114 ( & V_8 -> V_210 , 10 ) ;
F_54 ( V_115 ,
& V_8 -> V_116 ) ;
return;
}
V_8 -> V_89 = 0 ;
V_8 -> V_157 = V_158 ;
goto V_211;
}
if ( ( V_8 -> V_148 < V_154 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_211;
V_204 = F_17 ( V_2 , V_32 ) &
V_206 ;
if ( ! ( V_8 -> V_27 & V_28 ) &&
( V_204 != V_207 ) &&
( V_204 != V_208 ) ) {
V_8 -> V_148 = V_156 ;
V_8 -> V_27 |= V_28 ;
F_40 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_14 ( & V_8 -> V_30 ) ;
V_8 -> V_89 = 0 ;
V_8 -> V_157 = V_158 ;
goto V_211;
}
if ( V_8 -> V_157 ) {
if ( ! F_115 ( V_2 ) ) {
F_116 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_117 ( V_8 ) ;
}
goto V_211;
}
if ( V_8 -> V_89 & V_212 ) {
F_118 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_159 ) {
F_119 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_90 ) {
F_120 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_130 ) {
F_121 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_122 ) {
F_122 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_143 ) {
F_123 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_123 ) {
F_124 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_146 ) {
F_125 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_151 ) {
F_126 ( V_8 ) ;
goto V_211;
}
if ( V_8 -> V_89 & V_213 ) {
F_100 ( V_8 ) ;
V_8 -> V_89 &= ~ V_213 ;
goto V_211;
}
if ( V_8 -> V_148 == V_149 )
F_127 ( V_8 ) ;
V_211:
if ( V_8 -> V_148 == V_149 ) {
F_22 ( V_8 , ~ 0 ) ;
F_24 ( V_8 , 0xFF ) ;
} else {
F_24 ( V_8 , 0x1 ) ;
}
F_54 ( V_115 , & V_8 -> V_116 ) ;
V_205:
if ( V_8 -> V_148 == V_214 )
return;
if ( V_8 -> V_89 )
F_128 ( & V_8 -> V_152 ,
V_153 + F_129 ( 20 ) ) ;
else
F_128 ( & V_8 -> V_152 , V_153 + ( V_215 * 2 ) ) ;
F_14 ( & V_8 -> V_53 ) ;
}
static void F_130 ( struct V_202 * V_203 )
{
struct V_7 * V_8 = F_113 ( V_203 ,
struct V_7 ,
V_30 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_127 * V_114 ;
T_5 V_204 ;
int V_39 = 0 , V_86 ;
while ( F_50 ( V_115 ,
& V_8 -> V_116 ) )
F_79 ( 500 , 1000 ) ;
F_15 ( V_8 ) ;
if ( V_8 -> V_27 & V_29 ) {
V_8 -> V_27 &= ~ V_29 ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( V_8 ) ;
}
V_8 -> V_27 |= V_28 ;
for ( V_39 = 0 ; V_39 < V_216 ; V_39 ++ ) {
V_204 = F_17 ( V_2 , V_32 ) &
V_206 ;
if ( ( V_204 != V_207 ) &&
( V_204 != V_208 ) )
break;
F_79 ( 500 , 1000 ) ;
}
if ( V_39 == V_216 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
goto V_217;
}
for ( V_39 = 0 ; V_39 < V_216 ; V_39 ++ ) {
V_204 = F_17 ( V_2 , V_32 ) &
V_206 ;
if ( V_204 == V_207 )
break;
F_134 ( V_218 ) ;
}
F_134 ( V_218 ) ;
if ( V_39 == V_216 ) {
struct V_127 * V_114 , * V_138 ;
struct V_112 * V_219 , * V_220 ;
F_40 ( & V_8 -> V_12 -> V_13 , L_24 ,
V_204 ) ;
V_8 -> V_27 |= V_155 ;
if ( F_135 ( V_8 -> V_25 ) ) {
F_136 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_71 ( V_8 ) ;
F_20 ( V_8 ) ;
F_41 ( V_8 ) ;
F_137 ( V_8 ) ;
F_138 ( V_8 ) ;
}
F_67 (f, ftmp, &adapter->mac_filter_list,
list) {
F_139 ( & V_114 -> V_119 ) ;
F_9 ( V_114 ) ;
}
F_67 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_139 ( & V_219 -> V_119 ) ;
F_9 ( V_219 ) ;
}
F_42 ( V_8 ) ;
F_108 ( V_8 ) ;
F_84 ( V_8 ) ;
F_107 ( V_8 ) ;
F_9 ( V_8 -> V_172 ) ;
F_131 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_221 ;
F_54 ( V_115 , & V_8 -> V_116 ) ;
V_8 -> V_27 &= ~ V_28 ;
F_35 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
return;
}
V_217:
if ( F_135 ( V_8 -> V_25 ) ) {
F_80 ( V_25 ) ;
F_140 ( V_25 ) ;
F_71 ( V_8 ) ;
}
F_20 ( V_8 ) ;
V_8 -> V_148 = V_156 ;
V_8 -> V_27 &= ~ V_28 ;
F_138 ( V_8 ) ;
F_137 ( V_8 ) ;
if ( F_131 ( V_2 ) )
F_141 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
V_8 -> V_157 = V_158 ;
V_86 = F_132 ( V_2 ) ;
if ( V_86 )
F_35 ( & V_8 -> V_12 -> V_13 , L_27 ,
V_86 ) ;
V_8 -> V_89 = V_212 ;
V_8 -> V_89 |= V_90 ;
F_48 (f, &adapter->mac_filter_list, list) {
V_114 -> V_121 = true ;
}
F_48 (f, &adapter->vlan_filter_list, list) {
V_114 -> V_121 = true ;
}
V_8 -> V_89 |= V_130 ;
V_8 -> V_89 |= V_122 ;
F_54 ( V_115 , & V_8 -> V_116 ) ;
F_19 ( V_8 ) ;
F_128 ( & V_8 -> V_152 , V_153 + 2 ) ;
if ( F_135 ( V_8 -> V_25 ) ) {
V_86 = F_142 ( V_8 ) ;
if ( V_86 )
goto V_222;
V_86 = F_143 ( V_8 ) ;
if ( V_86 )
goto V_222;
F_73 ( V_8 ) ;
V_86 = F_76 ( V_8 ) ;
if ( V_86 )
goto V_222;
F_25 ( V_8 , true ) ;
} else {
V_8 -> V_148 = V_154 ;
}
return;
V_222:
F_40 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
F_144 ( V_8 -> V_25 ) ;
}
static void F_145 ( struct V_202 * V_203 )
{
struct V_7 * V_8 =
F_113 ( V_203 , struct V_7 , V_53 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_223 V_224 ;
struct V_225 * V_226 ;
T_1 V_181 ;
T_3 V_49 , V_227 ;
T_7 V_228 ;
if ( V_8 -> V_27 & V_155 )
goto V_88;
V_224 . V_229 = V_230 ;
V_224 . V_231 = F_7 ( V_224 . V_229 , V_16 ) ;
if ( ! V_224 . V_231 )
goto V_88;
V_226 = (struct V_225 * ) & V_224 . V_232 ;
do {
V_181 = F_146 ( V_2 , & V_224 , & V_228 ) ;
if ( V_181 || ! V_226 -> V_233 )
break;
F_147 ( V_8 , V_226 -> V_233 ,
V_226 -> V_234 , V_224 . V_231 ,
V_224 . V_235 ) ;
if ( V_228 != 0 )
memset ( V_224 . V_231 , 0 , V_230 ) ;
} while ( V_228 );
if ( ( V_8 -> V_27 &
( V_28 | V_29 ) ) ||
V_8 -> V_148 == V_156 )
goto V_236;
V_49 = F_17 ( V_2 , V_2 -> V_185 . V_237 . V_238 ) ;
V_227 = V_49 ;
if ( V_49 & V_239 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_239 ;
}
if ( V_49 & V_240 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_240 ;
}
if ( V_49 & V_241 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_241 ;
}
if ( V_227 != V_49 )
F_16 ( V_2 , V_2 -> V_185 . V_237 . V_238 , V_49 ) ;
V_49 = F_17 ( V_2 , V_2 -> V_185 . V_242 . V_238 ) ;
V_227 = V_49 ;
if ( V_49 & V_243 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_243 ;
}
if ( V_49 & V_244 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_244 ;
}
if ( V_49 & V_245 ) {
F_35 ( & V_8 -> V_12 -> V_13 , L_34 ) ;
V_49 &= ~ V_245 ;
}
if ( V_227 != V_49 )
F_16 ( V_2 , V_2 -> V_185 . V_242 . V_238 , V_49 ) ;
V_236:
F_9 ( V_224 . V_231 ) ;
V_88:
F_19 ( V_8 ) ;
}
void F_137 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ )
if ( V_8 -> V_73 [ V_39 ] -> V_232 )
F_148 ( V_8 -> V_73 [ V_39 ] ) ;
}
static int F_142 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
V_8 -> V_73 [ V_39 ] -> V_68 = V_8 -> V_167 ;
V_86 = F_149 ( V_8 -> V_73 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_40 ( & V_8 -> V_12 -> V_13 ,
L_35 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
static int F_143 ( struct V_7 * V_8 )
{
int V_39 , V_86 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] -> V_68 = V_8 -> V_168 ;
V_86 = F_150 ( V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_86 )
continue;
F_40 ( & V_8 -> V_12 -> V_13 ,
L_36 ,
V_95 , V_39 ) ;
break;
}
return V_86 ;
}
void F_138 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] -> V_232 )
F_151 ( V_8 -> V_65 [ V_39 ] ) ;
}
static int F_152 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_86 ;
if ( V_8 -> V_27 & V_155 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_37 ) ;
return - V_171 ;
}
if ( V_8 -> V_148 != V_154 || V_8 -> V_89 )
return - V_246 ;
V_86 = F_142 ( V_8 ) ;
if ( V_86 )
goto V_247;
V_86 = F_143 ( V_8 ) ;
if ( V_86 )
goto V_248;
V_86 = F_33 ( V_8 , V_25 -> V_94 ) ;
if ( V_86 )
goto V_249;
F_60 ( V_8 , V_8 -> V_2 . V_137 . V_133 ) ;
F_73 ( V_8 ) ;
V_86 = F_76 ( V_8 ) ;
if ( V_86 )
goto V_249;
F_25 ( V_8 , true ) ;
return 0 ;
V_249:
F_78 ( V_8 ) ;
F_41 ( V_8 ) ;
V_248:
F_138 ( V_8 ) ;
V_247:
F_137 ( V_8 ) ;
return V_86 ;
}
static int F_144 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_148 <= V_154 )
return 0 ;
F_136 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_78 ( V_8 ) ;
V_8 -> V_148 = V_154 ;
F_41 ( V_8 ) ;
return 0 ;
}
static struct V_250 * F_153 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_251 ;
}
static int F_154 ( struct V_24 * V_25 , int V_252 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_101 = V_252 + V_103 + V_104 ;
if ( ( V_252 < 68 ) || ( V_101 > V_253 ) )
return - V_254 ;
V_25 -> V_102 = V_252 ;
V_8 -> V_27 |= V_29 ;
F_14 ( & V_8 -> V_30 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 )
{
T_3 V_255 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_255 = F_17 ( V_2 , V_32 ) &
V_206 ;
if ( ( V_255 == V_207 ) ||
( V_255 == V_208 ) )
return 0 ;
F_79 ( 10 , 20 ) ;
}
return - V_246 ;
}
int F_156 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_172 -> V_256 ; V_39 ++ ) {
if ( V_8 -> V_172 -> V_163 [ V_39 ] . V_257 == V_258 )
V_8 -> V_163 = & V_8 -> V_172 -> V_163 [ V_39 ] ;
}
if ( ! V_8 -> V_163 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_38 ) ;
return - V_259 ;
}
if ( V_8 -> V_172 -> V_260
& V_261 ) {
V_25 -> V_262 = V_25 -> V_263 ;
V_25 -> V_263 |= V_264 |
V_265 |
V_266 ;
}
V_25 -> V_263 |= V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 ;
V_25 -> V_276 |= V_25 -> V_263 ;
V_25 -> V_276 &= ~ V_274 ;
V_8 -> V_67 . V_183 = V_8 -> V_163 -> V_277 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_278 = 1 ;
V_8 -> V_67 . V_279 = V_280 ;
V_8 -> V_67 . V_281 = ( V_282 |
F_157 ( V_283 ) ) ;
V_8 -> V_67 . V_284 = ( V_282 |
F_157 ( V_285 ) ) ;
V_8 -> V_67 . V_25 = V_8 -> V_25 ;
return 0 ;
}
static void F_158 ( struct V_202 * V_203 )
{
struct V_7 * V_8 = F_113 ( V_203 ,
struct V_7 ,
V_210 . V_203 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_286 * V_12 = V_8 -> V_12 ;
int V_86 , V_287 ;
switch ( V_8 -> V_148 ) {
case V_209 :
V_8 -> V_27 &= ~ V_155 ;
V_8 -> V_27 &= ~ V_28 ;
V_86 = F_159 ( V_2 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_39 ,
V_86 ) ;
goto V_86;
}
V_86 = F_155 ( V_2 ) ;
if ( V_86 ) {
F_35 ( & V_12 -> V_13 , L_40 ,
V_86 ) ;
goto V_86;
}
V_2 -> V_185 . V_288 = V_289 ;
V_2 -> V_185 . V_290 = V_289 ;
V_2 -> V_185 . V_291 = V_230 ;
V_2 -> V_185 . V_292 = V_230 ;
V_86 = F_132 ( V_2 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_41 ,
V_86 ) ;
goto V_86;
}
V_86 = F_117 ( V_8 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_42 , V_86 ) ;
F_131 ( V_2 ) ;
goto V_86;
}
V_8 -> V_148 = V_293 ;
goto V_294;
case V_293 :
if ( ! F_115 ( V_2 ) ) {
F_40 ( & V_12 -> V_13 , L_43 ) ;
F_131 ( V_2 ) ;
V_8 -> V_148 = V_209 ;
goto V_86;
}
V_86 = F_160 ( V_8 ) ;
if ( V_86 ) {
if ( V_86 == V_295 )
V_86 = F_117 ( V_8 ) ;
else
F_40 ( & V_12 -> V_13 , L_44 ,
V_8 -> V_296 . V_297 ,
V_8 -> V_296 . V_298 ,
V_299 ,
V_300 ) ;
goto V_86;
}
V_86 = F_118 ( V_8 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_45 ,
V_86 ) ;
goto V_86;
}
V_8 -> V_148 = V_301 ;
goto V_294;
case V_301 :
if ( ! V_8 -> V_172 ) {
V_287 = sizeof( struct V_302 ) +
( V_303 *
sizeof( struct V_304 ) ) ;
V_8 -> V_172 = F_7 ( V_287 , V_16 ) ;
if ( ! V_8 -> V_172 )
goto V_86;
}
V_86 = F_161 ( V_8 ) ;
if ( V_86 == V_295 ) {
V_86 = F_118 ( V_8 ) ;
goto V_86;
}
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_46 ,
V_86 ) ;
goto V_305;
}
V_8 -> V_148 = V_306 ;
break;
default:
goto V_305;
}
if ( F_156 ( V_8 ) )
goto V_305;
V_8 -> V_157 = V_158 ;
V_8 -> V_27 |= V_307 ;
V_25 -> V_308 = & V_309 ;
F_162 ( V_25 ) ;
V_25 -> V_310 = 5 * V_215 ;
if ( ! F_63 ( V_8 -> V_2 . V_137 . V_133 ) ) {
F_35 ( & V_12 -> V_13 , L_47 ,
V_8 -> V_2 . V_137 . V_133 ) ;
F_163 ( V_8 -> V_2 . V_137 . V_133 ) ;
}
F_61 ( V_25 -> V_136 , V_8 -> V_2 . V_137 . V_133 ) ;
F_61 ( V_25 -> V_311 , V_8 -> V_2 . V_137 . V_133 ) ;
F_164 ( & V_8 -> V_152 ) ;
V_8 -> V_152 . V_312 = & F_111 ;
V_8 -> V_152 . V_48 = ( unsigned long ) V_8 ;
F_128 ( & V_8 -> V_152 , V_153 + 1 ) ;
V_8 -> V_81 = F_88 ( int ,
V_8 -> V_163 -> V_313 ,
( int ) ( F_89 () ) ) ;
V_8 -> V_167 = V_314 ;
V_8 -> V_168 = V_315 ;
V_86 = F_110 ( V_8 ) ;
if ( V_86 )
goto V_316;
F_31 ( V_8 ) ;
if ( ! F_103 ( V_8 ) )
F_100 ( V_8 ) ;
V_86 = F_38 ( V_8 ) ;
if ( V_86 )
goto V_316;
F_80 ( V_25 ) ;
if ( ! V_8 -> V_317 ) {
V_86 = F_165 ( V_25 ) ;
if ( V_86 )
goto V_318;
}
V_8 -> V_317 = true ;
F_140 ( V_25 ) ;
F_35 ( & V_12 -> V_13 , L_48 , V_8 -> V_2 . V_137 . V_133 ) ;
if ( V_25 -> V_263 & V_275 )
F_35 ( & V_12 -> V_13 , L_49 ) ;
F_35 ( & V_12 -> V_13 , L_50 , V_319 ) ;
V_8 -> V_148 = V_154 ;
F_136 ( V_150 , & V_8 -> V_67 . V_148 ) ;
F_19 ( V_8 ) ;
if ( F_103 ( V_8 ) ) {
V_8 -> V_89 |= V_213 ;
F_77 ( & V_8 -> V_152 , V_153 + 1 ) ;
} else {
F_100 ( V_8 ) ;
}
return;
V_294:
F_114 ( & V_8 -> V_210 ,
F_129 ( 50 ) ) ;
return;
V_318:
F_42 ( V_8 ) ;
V_316:
F_108 ( V_8 ) ;
V_305:
F_9 ( V_8 -> V_172 ) ;
V_8 -> V_172 = NULL ;
V_86:
if ( ++ V_8 -> V_320 > V_321 ) {
F_40 ( & V_12 -> V_13 , L_51 ) ;
V_8 -> V_27 |= V_155 ;
return;
}
F_114 ( & V_8 -> V_210 , V_215 * 3 ) ;
}
static void F_166 ( struct V_286 * V_12 )
{
struct V_24 * V_25 = F_167 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_168 ( V_25 ) ;
if ( F_135 ( V_25 ) )
F_144 ( V_25 ) ;
V_8 -> V_148 = V_214 ;
V_8 -> V_89 = 0 ;
#ifdef F_169
F_170 ( V_12 ) ;
#endif
F_171 ( V_12 ) ;
}
static int F_172 ( struct V_286 * V_12 , const struct V_322 * V_323 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_86 ;
V_86 = F_173 ( V_12 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_174 ( & V_12 -> V_13 , F_175 ( 64 ) ) ;
if ( V_86 ) {
V_86 = F_174 ( & V_12 -> V_13 , F_175 ( 32 ) ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 ,
L_52 , V_86 ) ;
goto V_324;
}
}
V_86 = F_176 ( V_12 , V_325 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 ,
L_53 , V_86 ) ;
goto V_326;
}
F_177 ( V_12 ) ;
F_178 ( V_12 ) ;
V_25 = F_179 ( sizeof( struct V_7 ) ,
V_327 ) ;
if ( ! V_25 ) {
V_86 = - V_126 ;
goto V_328;
}
F_180 ( V_25 , & V_12 -> V_13 ) ;
F_181 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_329 = F_23 ( V_330 ) - 1 ;
V_8 -> V_148 = V_209 ;
F_170 ( V_12 ) ;
V_2 -> V_100 = F_182 ( F_183 ( V_12 , 0 ) ,
F_184 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_100 ) {
V_86 = - V_171 ;
goto V_331;
}
V_2 -> V_332 = V_12 -> V_333 ;
V_2 -> V_334 = V_12 -> V_335 ;
F_185 ( V_12 , V_336 , & V_2 -> V_337 ) ;
V_2 -> V_338 = V_12 -> V_339 ;
V_2 -> V_340 = V_12 -> V_341 ;
V_2 -> V_342 . V_335 = F_186 ( V_12 -> V_343 ) ;
V_2 -> V_342 . V_344 = F_187 ( V_12 -> V_343 ) ;
F_52 ( & V_8 -> V_129 ) ;
F_52 ( & V_8 -> V_120 ) ;
F_188 ( & V_8 -> V_30 , F_130 ) ;
F_188 ( & V_8 -> V_53 , F_145 ) ;
F_188 ( & V_8 -> V_201 , F_112 ) ;
F_189 ( & V_8 -> V_210 , F_158 ) ;
F_114 ( & V_8 -> V_210 , 10 ) ;
return 0 ;
V_331:
F_190 ( V_25 ) ;
V_328:
F_191 ( V_12 ) ;
V_326:
V_324:
F_171 ( V_12 ) ;
return V_86 ;
}
static int F_192 ( struct V_286 * V_12 , T_11 V_148 )
{
struct V_24 * V_25 = F_167 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_345 = 0 ;
F_168 ( V_25 ) ;
if ( F_135 ( V_25 ) ) {
F_193 () ;
F_78 ( V_8 ) ;
F_194 () ;
}
F_42 ( V_8 ) ;
F_108 ( V_8 ) ;
V_345 = F_170 ( V_12 ) ;
if ( V_345 )
return V_345 ;
F_171 ( V_12 ) ;
return 0 ;
}
static int F_195 ( struct V_286 * V_12 )
{
struct V_7 * V_8 = F_167 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_86 ;
F_196 ( V_12 , V_346 ) ;
F_197 ( V_12 ) ;
F_170 ( V_12 ) ;
V_86 = F_198 ( V_12 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_54 ) ;
return V_86 ;
}
F_178 ( V_12 ) ;
F_193 () ;
V_86 = F_87 ( V_8 ) ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_55 ) ;
return V_86 ;
}
V_86 = F_38 ( V_8 ) ;
F_194 () ;
if ( V_86 ) {
F_40 ( & V_12 -> V_13 , L_56 ) ;
return V_86 ;
}
F_14 ( & V_8 -> V_30 ) ;
F_199 ( V_25 ) ;
return V_86 ;
}
static void F_200 ( struct V_286 * V_12 )
{
struct V_24 * V_25 = F_167 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_127 * V_114 , * V_138 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_201 ( & V_8 -> V_210 ) ;
F_202 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_317 ) {
F_203 ( V_25 ) ;
V_8 -> V_317 = false ;
}
V_8 -> V_148 = V_214 ;
V_8 -> V_89 = 0 ;
F_133 ( V_8 ) ;
F_134 ( 20 ) ;
if ( ! F_115 ( V_2 ) ) {
F_133 ( V_8 ) ;
F_134 ( 20 ) ;
}
if ( V_8 -> V_33 ) {
F_15 ( V_8 ) ;
F_42 ( V_8 ) ;
F_108 ( V_8 ) ;
F_107 ( V_8 ) ;
}
if ( V_8 -> V_152 . V_312 )
F_204 ( & V_8 -> V_152 ) ;
F_205 () ;
if ( V_2 -> V_185 . V_242 . V_68 )
F_131 ( V_2 ) ;
F_206 ( V_2 -> V_100 ) ;
F_191 ( V_12 ) ;
F_137 ( V_8 ) ;
F_138 ( V_8 ) ;
F_84 ( V_8 ) ;
F_9 ( V_8 -> V_172 ) ;
F_67 (f, ftmp, &adapter->mac_filter_list, list) {
F_139 ( & V_114 -> V_119 ) ;
F_9 ( V_114 ) ;
}
F_67 (f, ftmp, &adapter->vlan_filter_list, list) {
F_139 ( & V_114 -> V_119 ) ;
F_9 ( V_114 ) ;
}
F_190 ( V_25 ) ;
F_207 ( V_12 ) ;
F_171 ( V_12 ) ;
}
static int T_12 F_208 ( void )
{
int V_181 ;
F_11 ( L_57 , V_319 ,
V_347 ) ;
F_11 ( L_50 , V_348 ) ;
V_181 = F_209 ( & V_349 ) ;
return V_181 ;
}
static void T_13 F_210 ( void )
{
F_211 ( & V_349 ) ;
}
