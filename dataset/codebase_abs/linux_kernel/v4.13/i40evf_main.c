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
void F_12 ( struct V_7 * V_8 )
{
if ( ! ( V_8 -> V_24 &
( V_25 | V_26 ) ) ) {
V_8 -> V_24 |= V_26 ;
F_13 ( & V_8 -> V_27 ) ;
}
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_8 -> V_30 ++ ;
F_12 ( V_8 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( ! V_8 -> V_31 )
return;
F_17 ( V_2 , V_32 , 0 ) ;
F_18 ( V_2 , V_33 ) ;
F_19 ( V_8 -> V_31 [ 0 ] . V_34 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_17 ( V_2 , V_32 , V_35 |
V_36 ) ;
F_17 ( V_2 , V_37 , V_38 ) ;
F_18 ( V_2 , V_33 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
int V_39 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( ! V_8 -> V_31 )
return;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
F_17 ( V_2 , F_22 ( V_39 - 1 ) , 0 ) ;
F_19 ( V_8 -> V_31 [ V_39 ] . V_34 ) ;
}
F_18 ( V_2 , V_33 ) ;
}
void F_23 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & F_24 ( V_39 - 1 ) ) {
F_17 ( V_2 , F_22 ( V_39 - 1 ) ,
V_41 |
V_42 |
V_43 ) ;
}
}
}
static void F_25 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
T_3 V_44 ;
if ( V_19 & 1 ) {
V_44 = F_18 ( V_2 , V_32 ) ;
V_44 |= V_45 |
V_42 |
V_43 ;
F_17 ( V_2 , V_32 , V_44 ) ;
}
for ( V_39 = 1 ; V_39 < V_8 -> V_40 ; V_39 ++ ) {
if ( V_19 & F_24 ( V_39 ) ) {
V_44 = F_18 ( V_2 , F_22 ( V_39 - 1 ) ) ;
V_44 |= V_45 |
V_42 |
V_43 ;
F_17 ( V_2 , F_22 ( V_39 - 1 ) , V_44 ) ;
}
}
}
void F_26 ( struct V_7 * V_8 , bool V_46 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_20 ( V_8 ) ;
F_23 ( V_8 , ~ 0 ) ;
if ( V_46 )
F_18 ( V_2 , V_33 ) ;
}
static T_5 F_27 ( int V_47 , void * V_48 )
{
struct V_28 * V_29 = V_48 ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_49 ;
V_49 = F_18 ( V_2 , V_50 ) ;
V_49 = F_18 ( V_2 , V_37 ) ;
V_49 = F_18 ( V_2 , V_32 ) |
V_51 ;
F_17 ( V_2 , V_32 , V_49 ) ;
F_13 ( & V_8 -> V_52 ) ;
return V_53 ;
}
static T_5 F_28 ( int V_47 , void * V_48 )
{
struct V_54 * V_55 = V_48 ;
if ( ! V_55 -> V_56 . V_57 && ! V_55 -> V_58 . V_57 )
return V_53 ;
F_29 ( & V_55 -> V_59 ) ;
return V_53 ;
}
static void
F_30 ( struct V_7 * V_8 , int V_60 , int V_61 )
{
struct V_54 * V_55 = & V_8 -> V_62 [ V_60 ] ;
struct V_63 * V_64 = & V_8 -> V_65 [ V_61 ] ;
struct V_1 * V_2 = & V_8 -> V_2 ;
V_64 -> V_55 = V_55 ;
V_64 -> V_66 = V_55 -> V_58 . V_57 ;
V_64 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_58 . V_57 = V_64 ;
V_55 -> V_58 . V_68 ++ ;
V_55 -> V_58 . V_69 = V_70 ;
V_55 -> V_58 . V_71 = F_31 ( V_64 -> V_72 ) ;
V_55 -> V_73 |= F_24 ( V_61 ) ;
V_55 -> V_74 = V_75 ;
F_17 ( V_2 , F_32 ( V_76 , V_60 - 1 ) , V_55 -> V_58 . V_71 ) ;
}
static void
F_33 ( struct V_7 * V_8 , int V_60 , int V_77 )
{
struct V_54 * V_55 = & V_8 -> V_62 [ V_60 ] ;
struct V_63 * V_78 = & V_8 -> V_79 [ V_77 ] ;
struct V_1 * V_2 = & V_8 -> V_2 ;
V_78 -> V_55 = V_55 ;
V_78 -> V_66 = V_55 -> V_56 . V_57 ;
V_78 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_56 . V_57 = V_78 ;
V_55 -> V_56 . V_68 ++ ;
V_55 -> V_56 . V_69 = V_70 ;
V_55 -> V_56 . V_71 = F_31 ( V_78 -> V_80 ) ;
V_55 -> V_74 = V_75 ;
V_55 -> V_81 ++ ;
F_17 ( V_2 , F_32 ( V_82 , V_60 - 1 ) , V_55 -> V_56 . V_71 ) ;
}
static int F_34 ( struct V_7 * V_8 )
{
int V_62 ;
int V_83 = 0 ;
int V_84 = 0 , V_85 = 0 ;
int V_86 = V_8 -> V_87 ;
int V_88 = V_8 -> V_87 ;
int V_39 , V_89 ;
int V_90 , V_91 ;
int V_92 = 0 ;
V_62 = V_8 -> V_40 - V_93 ;
if ( V_62 >= ( V_86 * 2 ) ) {
for (; V_84 < V_86 ; V_83 ++ , V_84 ++ )
F_30 ( V_8 , V_83 , V_84 ) ;
for (; V_85 < V_88 ; V_83 ++ , V_85 ++ )
F_33 ( V_8 , V_83 , V_85 ) ;
goto V_94;
}
for ( V_39 = V_83 ; V_39 < V_62 ; V_39 ++ ) {
V_90 = F_35 ( V_86 , V_62 - V_39 ) ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
F_30 ( V_8 , V_39 , V_84 ) ;
V_84 ++ ;
V_86 -- ;
}
}
for ( V_39 = V_83 ; V_39 < V_62 ; V_39 ++ ) {
V_91 = F_35 ( V_88 , V_62 - V_39 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
F_33 ( V_8 , V_39 , V_85 ) ;
V_85 ++ ;
V_88 -- ;
}
}
V_94:
V_8 -> V_95 |= V_96 ;
return V_92 ;
}
static void F_36 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_62 = V_8 -> V_40 - V_93 ;
int V_39 ;
if ( F_37 ( V_97 , V_8 -> V_67 . V_98 ) )
return;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ )
F_28 ( 0 , & V_8 -> V_62 [ V_39 ] ) ;
}
static void F_38 ( struct V_99 * V_100 ,
const T_6 * V_19 )
{
struct V_54 * V_55 =
F_39 ( V_100 , struct V_54 , V_101 ) ;
V_55 -> V_102 = * V_19 ;
}
static void F_40 ( struct V_103 * V_104 ) {}
static int
F_41 ( struct V_7 * V_8 , char * V_105 )
{
int V_34 , V_92 , V_62 ;
int V_106 = 0 , V_107 = 0 ;
int V_108 ;
F_21 ( V_8 ) ;
V_62 = V_8 -> V_40 - V_93 ;
for ( V_34 = 0 ; V_34 < V_62 ; V_34 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_34 ] ;
V_108 = V_8 -> V_31 [ V_34 + V_93 ] . V_34 ;
if ( V_55 -> V_56 . V_57 && V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_109 , sizeof( V_55 -> V_109 ) - 1 ,
L_2 , V_105 ,
L_3 , V_106 ++ ) ;
V_107 ++ ;
} else if ( V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_109 , sizeof( V_55 -> V_109 ) - 1 ,
L_2 , V_105 ,
L_4 , V_106 ++ ) ;
} else if ( V_55 -> V_56 . V_57 ) {
snprintf ( V_55 -> V_109 , sizeof( V_55 -> V_109 ) - 1 ,
L_2 , V_105 ,
L_5 , V_107 ++ ) ;
} else {
continue;
}
V_92 = F_42 ( V_108 ,
F_28 ,
0 ,
V_55 -> V_109 ,
V_55 ) ;
if ( V_92 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_6 , V_92 ) ;
goto V_110;
}
V_55 -> V_101 . V_100 = F_38 ;
V_55 -> V_101 . V_111 =
F_40 ;
F_44 ( V_108 , & V_55 -> V_101 ) ;
F_45 ( V_108 , & V_55 -> V_102 ) ;
}
return 0 ;
V_110:
while ( V_34 ) {
V_34 -- ;
V_108 = V_8 -> V_31 [ V_34 + V_93 ] . V_34 ;
F_44 ( V_108 , NULL ) ;
F_45 ( V_108 , NULL ) ;
F_46 ( V_108 , & V_8 -> V_62 [ V_34 ] ) ;
}
return V_92 ;
}
static int F_47 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_92 ;
snprintf ( V_8 -> V_112 ,
sizeof( V_8 -> V_112 ) - 1 , L_7 ,
F_48 ( & V_8 -> V_12 -> V_13 ) ) ;
V_92 = F_42 ( V_8 -> V_31 [ 0 ] . V_34 ,
& F_27 , 0 ,
V_8 -> V_112 , V_29 ) ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_112 , V_92 ) ;
F_46 ( V_8 -> V_31 [ 0 ] . V_34 , V_29 ) ;
}
return V_92 ;
}
static void F_50 ( struct V_7 * V_8 )
{
int V_34 , V_108 , V_62 ;
if ( ! V_8 -> V_31 )
return;
V_62 = V_8 -> V_40 - V_93 ;
for ( V_34 = 0 ; V_34 < V_62 ; V_34 ++ ) {
V_108 = V_8 -> V_31 [ V_34 + V_93 ] . V_34 ;
F_44 ( V_108 , NULL ) ;
F_45 ( V_108 , NULL ) ;
F_46 ( V_108 , & V_8 -> V_62 [ V_34 ] ) ;
}
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
if ( ! V_8 -> V_31 )
return;
F_46 ( V_8 -> V_31 [ 0 ] . V_34 , V_29 ) ;
}
static void F_52 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
V_8 -> V_79 [ V_39 ] . V_113 = V_2 -> V_114 + F_53 ( V_39 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
unsigned int V_115 = V_116 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
#if ( V_117 < 8192 )
if ( ! ( V_8 -> V_24 & V_118 ) ) {
struct V_28 * V_29 = V_8 -> V_29 ;
V_115 = V_119 ;
if ( ! V_120 &&
( V_29 -> V_121 <= V_122 ) )
V_115 = V_123 - V_124 ;
}
#endif
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_113 = V_2 -> V_114 + F_55 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] . V_115 = V_115 ;
if ( V_8 -> V_24 & V_118 )
F_56 ( & V_8 -> V_65 [ V_39 ] ) ;
else
F_57 ( & V_8 -> V_65 [ V_39 ] ) ;
}
}
static struct
V_125 * F_58 ( struct V_7 * V_8 , T_7 V_126 )
{
struct V_125 * V_127 ;
F_59 (f, &adapter->vlan_filter_list, list) {
if ( V_126 == V_127 -> V_126 )
return V_127 ;
}
return NULL ;
}
static struct
V_125 * F_60 ( struct V_7 * V_8 , T_7 V_126 )
{
struct V_125 * V_127 = NULL ;
int V_68 = 50 ;
while ( F_61 ( V_128 ,
& V_8 -> V_129 ) ) {
F_62 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_94;
}
V_127 = F_58 ( V_8 , V_126 ) ;
if ( ! V_127 ) {
V_127 = F_7 ( sizeof( * V_127 ) , V_130 ) ;
if ( ! V_127 )
goto V_131;
V_127 -> V_126 = V_126 ;
F_63 ( & V_127 -> V_132 ) ;
F_64 ( & V_127 -> V_132 , & V_8 -> V_133 ) ;
V_127 -> V_134 = true ;
V_8 -> V_95 |= V_135 ;
}
V_131:
F_65 ( V_128 , & V_8 -> V_129 ) ;
V_94:
return V_127 ;
}
static void F_66 ( struct V_7 * V_8 , T_7 V_126 )
{
struct V_125 * V_127 ;
int V_68 = 50 ;
while ( F_61 ( V_128 ,
& V_8 -> V_129 ) ) {
F_62 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_127 = F_58 ( V_8 , V_126 ) ;
if ( V_127 ) {
V_127 -> remove = true ;
V_8 -> V_95 |= V_136 ;
}
F_65 ( V_128 , & V_8 -> V_129 ) ;
}
static int F_67 ( struct V_28 * V_29 ,
T_8 T_9 V_137 , T_7 V_138 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( ! F_68 ( V_8 ) )
return - V_139 ;
if ( F_60 ( V_8 , V_138 ) == NULL )
return - V_140 ;
return 0 ;
}
static int F_69 ( struct V_28 * V_29 ,
T_8 T_9 V_137 , T_7 V_138 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( F_68 ( V_8 ) ) {
F_66 ( V_8 , V_138 ) ;
return 0 ;
}
return - V_139 ;
}
static struct
V_141 * F_70 ( struct V_7 * V_8 ,
T_10 * V_142 )
{
struct V_141 * V_127 ;
if ( ! V_142 )
return NULL ;
F_59 (f, &adapter->mac_filter_list, list) {
if ( F_71 ( V_142 , V_127 -> V_142 ) )
return V_127 ;
}
return NULL ;
}
static struct
V_141 * F_72 ( struct V_7 * V_8 ,
T_10 * V_142 )
{
struct V_141 * V_127 ;
int V_68 = 50 ;
if ( ! V_142 )
return NULL ;
while ( F_61 ( V_128 ,
& V_8 -> V_129 ) ) {
F_62 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_127 = F_70 ( V_8 , V_142 ) ;
if ( ! V_127 ) {
V_127 = F_7 ( sizeof( * V_127 ) , V_130 ) ;
if ( ! V_127 ) {
F_65 ( V_128 ,
& V_8 -> V_129 ) ;
return NULL ;
}
F_73 ( V_127 -> V_142 , V_142 ) ;
F_74 ( & V_127 -> V_132 , & V_8 -> V_143 ) ;
V_127 -> V_134 = true ;
V_8 -> V_95 |= V_144 ;
}
F_65 ( V_128 , & V_8 -> V_129 ) ;
return V_127 ;
}
static int F_75 ( struct V_28 * V_29 , void * V_145 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_141 * V_127 ;
struct V_146 * V_147 = V_145 ;
if ( ! F_76 ( V_147 -> V_148 ) )
return - V_149 ;
if ( F_71 ( V_29 -> V_150 , V_147 -> V_148 ) )
return 0 ;
if ( V_8 -> V_24 & V_151 )
return - V_152 ;
V_127 = F_70 ( V_8 , V_2 -> V_153 . V_147 ) ;
if ( V_127 ) {
V_127 -> remove = true ;
V_8 -> V_95 |= V_154 ;
}
V_127 = F_72 ( V_8 , V_147 -> V_148 ) ;
if ( V_127 ) {
F_73 ( V_2 -> V_153 . V_147 , V_147 -> V_148 ) ;
F_73 ( V_29 -> V_150 , V_8 -> V_2 . V_153 . V_147 ) ;
}
return ( V_127 == NULL ) ? - V_140 : 0 ;
}
static void F_77 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_141 * V_127 , * V_155 ;
struct V_156 * V_157 ;
struct V_156 * V_158 ;
struct V_156 * V_159 ;
int V_68 = 50 ;
F_78 (uca, netdev) {
F_72 ( V_8 , V_157 -> V_147 ) ;
}
F_79 (mca, netdev) {
F_72 ( V_8 , V_158 -> V_147 ) ;
}
while ( F_61 ( V_128 ,
& V_8 -> V_129 ) ) {
F_62 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_160 ) ;
return;
}
}
F_80 (f, ftmp, &adapter->mac_filter_list, list) {
F_79 (mca, netdev)
if ( F_71 ( V_158 -> V_147 , V_127 -> V_142 ) )
goto V_161;
F_78 (uca, netdev)
if ( F_71 ( V_157 -> V_147 , V_127 -> V_142 ) )
goto V_161;
F_81 (netdev, ha)
if ( F_71 ( V_159 -> V_147 , V_127 -> V_142 ) )
goto V_161;
if ( F_71 ( V_127 -> V_142 , V_8 -> V_2 . V_153 . V_147 ) )
goto V_161;
V_127 -> remove = true ;
V_8 -> V_95 |= V_154 ;
V_161:
continue;
}
if ( V_29 -> V_24 & V_162 &&
! ( V_8 -> V_24 & V_163 ) )
V_8 -> V_95 |= V_164 ;
else if ( ! ( V_29 -> V_24 & V_162 ) &&
V_8 -> V_24 & V_163 )
V_8 -> V_95 |= V_165 ;
if ( V_29 -> V_24 & V_166 &&
! ( V_8 -> V_24 & V_167 ) )
V_8 -> V_95 |= V_168 ;
else if ( ! ( V_29 -> V_24 & V_166 ) &&
V_8 -> V_24 & V_167 )
V_8 -> V_95 |= V_169 ;
F_65 ( V_128 , & V_8 -> V_129 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
int V_170 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_93 ;
for ( V_170 = 0 ; V_170 < V_62 ; V_170 ++ ) {
struct V_171 * V_59 ;
V_55 = & V_8 -> V_62 [ V_170 ] ;
V_59 = & V_55 -> V_59 ;
F_83 ( V_59 ) ;
}
}
static void F_84 ( struct V_7 * V_8 )
{
int V_170 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_93 ;
for ( V_170 = 0 ; V_170 < V_62 ; V_170 ++ ) {
V_55 = & V_8 -> V_62 [ V_170 ] ;
F_85 ( & V_55 -> V_59 ) ;
}
}
static void F_86 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_39 ;
F_77 ( V_29 ) ;
F_52 ( V_8 ) ;
F_54 ( V_8 ) ;
V_8 -> V_95 |= V_172 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
struct V_63 * V_57 = & V_8 -> V_65 [ V_39 ] ;
F_87 ( V_57 , F_88 ( V_57 ) ) ;
}
}
static void F_89 ( struct V_7 * V_8 )
{
V_8 -> V_98 = V_173 ;
F_65 ( V_97 , V_8 -> V_67 . V_98 ) ;
F_82 ( V_8 ) ;
V_8 -> V_95 |= V_174 ;
if ( F_90 ( V_8 ) )
V_8 -> V_24 |= V_175 ;
F_91 ( & V_8 -> V_176 , V_177 + 1 ) ;
}
void F_92 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_141 * V_127 ;
if ( V_8 -> V_98 <= V_178 )
return;
while ( F_61 ( V_128 ,
& V_8 -> V_129 ) )
F_93 ( 500 , 1000 ) ;
F_94 ( V_29 ) ;
F_95 ( V_29 ) ;
V_8 -> V_179 = false ;
F_84 ( V_8 ) ;
F_21 ( V_8 ) ;
F_59 (f, &adapter->mac_filter_list, list) {
V_127 -> remove = true ;
}
F_59 (f, &adapter->vlan_filter_list, list) {
V_127 -> remove = true ;
}
if ( ! ( V_8 -> V_24 & V_180 ) &&
V_8 -> V_98 != V_181 ) {
V_8 -> V_182 = V_183 ;
V_8 -> V_95 = V_154 ;
V_8 -> V_95 |= V_136 ;
V_8 -> V_95 |= V_184 ;
}
F_65 ( V_128 , & V_8 -> V_129 ) ;
}
static int
F_96 ( struct V_7 * V_8 , int V_185 )
{
int V_92 , V_186 ;
V_186 = V_187 ;
V_92 = F_97 ( V_8 -> V_12 , V_8 -> V_31 ,
V_186 , V_185 ) ;
if ( V_92 < 0 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
return V_92 ;
}
V_8 -> V_40 = V_92 ;
return 0 ;
}
static void F_98 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_188 )
return;
V_8 -> V_87 = 0 ;
F_9 ( V_8 -> V_79 ) ;
V_8 -> V_79 = NULL ;
F_9 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
}
static int F_99 ( struct V_7 * V_8 )
{
int V_39 , V_87 ;
V_87 = F_100 ( int ,
V_8 -> V_188 -> V_189 ,
( int ) ( F_101 () ) ) ;
V_8 -> V_79 = F_102 ( V_87 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_79 )
goto V_190;
V_8 -> V_65 = F_102 ( V_87 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_65 )
goto V_190;
for ( V_39 = 0 ; V_39 < V_87 ; V_39 ++ ) {
struct V_63 * V_78 ;
struct V_63 * V_64 ;
V_78 = & V_8 -> V_79 [ V_39 ] ;
V_78 -> V_191 = V_39 ;
V_78 -> V_29 = V_8 -> V_29 ;
V_78 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_78 -> V_68 = V_8 -> V_192 ;
V_78 -> V_80 = ( V_193 | V_194 ) ;
if ( V_8 -> V_24 & V_195 )
V_78 -> V_24 |= V_196 ;
V_64 = & V_8 -> V_65 [ V_39 ] ;
V_64 -> V_191 = V_39 ;
V_64 -> V_29 = V_8 -> V_29 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_197 ;
V_64 -> V_72 = ( V_193 | V_198 ) ;
}
V_8 -> V_87 = V_87 ;
return 0 ;
V_190:
F_98 ( V_8 ) ;
return - V_140 ;
}
static int F_103 ( struct V_7 * V_8 )
{
int V_34 , V_199 ;
int V_200 = 0 ;
int V_92 = 0 ;
if ( ! V_8 -> V_188 ) {
V_92 = - V_139 ;
goto V_94;
}
V_200 = V_8 -> V_87 ;
V_199 = F_100 ( int , V_200 + V_93 ,
( int ) V_8 -> V_201 -> V_202 ) ;
V_8 -> V_31 = F_102 ( V_199 ,
sizeof( struct V_203 ) , V_16 ) ;
if ( ! V_8 -> V_31 ) {
V_92 = - V_140 ;
goto V_94;
}
for ( V_34 = 0 ; V_34 < V_199 ; V_34 ++ )
V_8 -> V_31 [ V_34 ] . V_204 = V_34 ;
V_92 = F_96 ( V_8 , V_199 ) ;
V_94:
F_104 ( V_8 -> V_29 , V_200 ) ;
F_105 ( V_8 -> V_29 , V_200 ) ;
return V_92 ;
}
static int F_106 ( struct V_7 * V_8 )
{
struct V_205 * V_206 =
(struct V_205 * ) V_8 -> V_206 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_207 = 0 ;
if ( V_8 -> V_182 != V_183 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_182 ) ;
return - V_208 ;
}
V_207 = F_107 ( V_2 , V_8 -> V_67 . V_209 , V_206 ) ;
if ( V_207 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_12 ,
F_108 ( V_2 , V_207 ) ,
F_109 ( V_2 , V_2 -> V_210 . V_211 ) ) ;
return V_207 ;
}
V_207 = F_110 ( V_2 , V_8 -> V_67 . V_209 , false ,
V_8 -> V_212 , V_8 -> V_213 ) ;
if ( V_207 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_13 ,
F_108 ( V_2 , V_207 ) ,
F_109 ( V_2 , V_2 -> V_210 . V_211 ) ) ;
}
return V_207 ;
}
static int F_111 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 * V_214 ;
T_7 V_39 ;
V_214 = ( T_3 * ) V_8 -> V_206 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_215 / 4 ; V_39 ++ )
F_17 ( V_2 , F_112 ( V_39 ) , V_214 [ V_39 ] ) ;
V_214 = ( T_3 * ) V_8 -> V_212 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_213 / 4 ; V_39 ++ )
F_17 ( V_2 , F_113 ( V_39 ) , V_214 [ V_39 ] ) ;
F_114 ( V_2 ) ;
return 0 ;
}
int F_115 ( struct V_7 * V_8 )
{
if ( F_116 ( V_8 ) ) {
V_8 -> V_95 |= V_216 |
V_217 ;
return 0 ;
} else if ( F_117 ( V_8 ) ) {
return F_106 ( V_8 ) ;
} else {
return F_111 ( V_8 ) ;
}
}
static void F_118 ( struct V_7 * V_8 )
{
T_7 V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_213 ; V_39 ++ )
V_8 -> V_212 [ V_39 ] = V_39 % V_8 -> V_87 ;
}
static int F_119 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_207 ;
if ( ! F_116 ( V_8 ) ) {
if ( V_8 -> V_201 -> V_218 &
V_219 )
V_8 -> V_220 = V_221 ;
else
V_8 -> V_220 = V_222 ;
F_17 ( V_2 , F_120 ( 0 ) , ( T_3 ) V_8 -> V_220 ) ;
F_17 ( V_2 , F_120 ( 1 ) , ( T_3 ) ( V_8 -> V_220 >> 32 ) ) ;
}
F_118 ( V_8 ) ;
F_121 ( ( void * ) V_8 -> V_206 , V_8 -> V_215 ) ;
V_207 = F_115 ( V_8 ) ;
return V_207 ;
}
static int F_122 ( struct V_7 * V_8 )
{
int V_170 = 0 , V_223 ;
struct V_54 * V_55 ;
V_223 = V_8 -> V_40 - V_93 ;
V_8 -> V_62 = F_102 ( V_223 , sizeof( * V_55 ) ,
V_16 ) ;
if ( ! V_8 -> V_62 )
return - V_140 ;
for ( V_170 = 0 ; V_170 < V_223 ; V_170 ++ ) {
V_55 = & V_8 -> V_62 [ V_170 ] ;
V_55 -> V_8 = V_8 ;
V_55 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_60 = V_170 ;
F_123 ( V_8 -> V_29 , & V_55 -> V_59 ,
V_224 , V_225 ) ;
}
return 0 ;
}
static void F_124 ( struct V_7 * V_8 )
{
int V_170 , V_223 ;
int V_226 ;
if ( ! V_8 -> V_62 )
return;
V_223 = V_8 -> V_40 - V_93 ;
V_226 = V_8 -> V_87 ;
for ( V_170 = 0 ; V_170 < V_223 ; V_170 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_170 ] ;
if ( V_170 < V_226 )
F_125 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
V_8 -> V_62 = NULL ;
}
void F_126 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_31 )
return;
F_127 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
}
int F_128 ( struct V_7 * V_8 )
{
int V_92 ;
V_92 = F_99 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_227;
}
F_129 () ;
V_92 = F_103 ( V_8 ) ;
F_130 () ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_228;
}
V_92 = F_122 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_229;
}
F_43 ( & V_8 -> V_12 -> V_13 , L_17 ,
( V_8 -> V_87 > 1 ) ? L_18 : L_19 ,
V_8 -> V_87 ) ;
return 0 ;
V_229:
F_126 ( V_8 ) ;
V_228:
F_98 ( V_8 ) ;
V_227:
return V_92 ;
}
static void F_131 ( struct V_7 * V_8 )
{
F_9 ( V_8 -> V_206 ) ;
V_8 -> V_206 = NULL ;
F_9 ( V_8 -> V_212 ) ;
V_8 -> V_212 = NULL ;
}
static void F_132 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_13 ( & V_8 -> V_230 ) ;
}
static void F_133 ( struct V_231 * V_232 )
{
struct V_7 * V_8 = F_39 ( V_232 ,
struct V_7 ,
V_230 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_233 ;
if ( F_61 ( V_128 , & V_8 -> V_129 ) )
goto V_234;
if ( V_8 -> V_24 & V_180 ) {
V_233 = F_18 ( V_2 , V_33 ) &
V_235 ;
if ( ( V_233 == V_236 ) ||
( V_233 == V_237 ) ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_98 = V_238 ;
V_8 -> V_24 &= ~ V_180 ;
F_134 ( & V_8 -> V_239 , 10 ) ;
F_65 ( V_128 ,
& V_8 -> V_129 ) ;
return;
}
V_8 -> V_95 = 0 ;
V_8 -> V_182 = V_183 ;
goto V_240;
}
if ( ( V_8 -> V_98 < V_241 ) ||
( V_8 -> V_24 & V_25 ) )
goto V_240;
V_233 = F_18 ( V_2 , V_242 ) & V_243 ;
if ( ! ( V_8 -> V_24 & V_25 ) && ! V_233 ) {
V_8 -> V_98 = V_181 ;
V_8 -> V_24 |= V_25 ;
F_49 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_13 ( & V_8 -> V_27 ) ;
V_8 -> V_95 = 0 ;
V_8 -> V_182 = V_183 ;
goto V_240;
}
if ( V_8 -> V_182 ) {
if ( ! F_135 ( V_2 ) ) {
F_136 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_137 ( V_8 ) ;
}
goto V_240;
}
if ( V_8 -> V_95 & V_244 ) {
F_138 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_184 ) {
F_139 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_96 ) {
F_140 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_144 ) {
F_141 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_135 ) {
F_142 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_154 ) {
F_143 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_136 ) {
F_144 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_172 ) {
F_145 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_174 ) {
F_146 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_245 ) {
F_119 ( V_8 ) ;
V_8 -> V_95 &= ~ V_245 ;
goto V_240;
}
if ( V_8 -> V_95 & V_246 ) {
F_147 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_247 ) {
F_148 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_217 ) {
F_149 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_216 ) {
F_150 ( V_8 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_164 ) {
F_151 ( V_8 , V_248 |
V_249 ) ;
goto V_240;
}
if ( V_8 -> V_95 & V_168 ) {
F_151 ( V_8 , V_249 ) ;
goto V_240;
}
if ( ( V_8 -> V_95 & V_165 ) &&
( V_8 -> V_95 & V_169 ) ) {
F_151 ( V_8 , 0 ) ;
goto V_240;
}
F_134 ( & V_8 -> V_250 , F_152 ( 5 ) ) ;
if ( V_8 -> V_98 == V_173 )
F_153 ( V_8 ) ;
V_240:
if ( V_8 -> V_98 == V_173 ) {
F_23 ( V_8 , ~ 0 ) ;
F_25 ( V_8 , 0xFF ) ;
} else {
F_25 ( V_8 , 0x1 ) ;
}
F_65 ( V_128 , & V_8 -> V_129 ) ;
V_234:
if ( V_8 -> V_98 == V_251 )
return;
if ( V_8 -> V_95 )
F_154 ( & V_8 -> V_176 ,
V_177 + F_152 ( 20 ) ) ;
else
F_154 ( & V_8 -> V_176 , V_177 + ( V_252 * 2 ) ) ;
F_13 ( & V_8 -> V_52 ) ;
}
static void F_155 ( struct V_7 * V_8 )
{
struct V_141 * V_127 , * V_155 ;
struct V_125 * V_253 , * V_254 ;
V_8 -> V_24 |= V_180 ;
if ( F_156 ( V_8 -> V_29 ) ) {
F_157 ( V_97 , V_8 -> V_67 . V_98 ) ;
F_94 ( V_8 -> V_29 ) ;
F_95 ( V_8 -> V_29 ) ;
V_8 -> V_179 = false ;
F_84 ( V_8 ) ;
F_21 ( V_8 ) ;
F_50 ( V_8 ) ;
F_158 ( V_8 ) ;
F_159 ( V_8 ) ;
}
F_80 (f, ftmp, &adapter->mac_filter_list, list) {
F_160 ( & V_127 -> V_132 ) ;
F_9 ( V_127 ) ;
}
F_80 (fv, fvtmp, &adapter->vlan_filter_list, list) {
F_160 ( & V_253 -> V_132 ) ;
F_9 ( V_253 ) ;
}
F_51 ( V_8 ) ;
F_126 ( V_8 ) ;
F_98 ( V_8 ) ;
F_124 ( V_8 ) ;
F_9 ( V_8 -> V_201 ) ;
F_161 ( & V_8 -> V_2 ) ;
V_8 -> V_29 -> V_24 &= ~ V_255 ;
F_65 ( V_128 , & V_8 -> V_129 ) ;
V_8 -> V_24 &= ~ V_25 ;
V_8 -> V_98 = V_241 ;
F_43 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
}
static void F_162 ( struct V_231 * V_232 )
{
struct V_7 * V_8 = F_39 ( V_232 ,
struct V_7 ,
V_27 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_125 * V_256 ;
struct V_141 * V_127 ;
T_3 V_233 ;
int V_39 = 0 , V_92 ;
while ( F_61 ( V_257 ,
& V_8 -> V_129 ) )
F_93 ( 500 , 1000 ) ;
if ( F_90 ( V_8 ) ) {
V_8 -> V_24 &= ~ ( V_175 |
V_258 |
V_259 |
V_260 ) ;
F_163 ( & V_8 -> V_250 ) ;
F_164 ( & V_8 -> V_67 , true ) ;
}
F_16 ( V_8 ) ;
if ( V_8 -> V_24 & V_26 ) {
V_8 -> V_24 &= ~ V_26 ;
F_161 ( V_2 ) ;
F_165 ( V_2 ) ;
F_166 ( V_8 ) ;
}
V_8 -> V_24 |= V_25 ;
for ( V_39 = 0 ; V_39 < V_261 ; V_39 ++ ) {
V_233 = F_18 ( V_2 , V_242 ) &
V_243 ;
if ( ! V_233 )
break;
F_93 ( 5000 , 10000 ) ;
}
if ( V_39 == V_261 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
goto V_262;
}
for ( V_39 = 0 ; V_39 < V_261 ; V_39 ++ ) {
F_167 ( V_263 ) ;
V_233 = F_18 ( V_2 , V_33 ) &
V_235 ;
if ( V_233 == V_236 )
break;
}
F_168 ( V_8 -> V_12 ) ;
if ( V_39 == V_261 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_25 ,
V_233 ) ;
F_155 ( V_8 ) ;
F_65 ( V_257 , & V_8 -> V_129 ) ;
return;
}
V_262:
if ( F_156 ( V_8 -> V_29 ) ) {
F_94 ( V_29 ) ;
F_169 ( V_29 ) ;
V_8 -> V_179 = false ;
F_84 ( V_8 ) ;
}
F_21 ( V_8 ) ;
V_8 -> V_98 = V_181 ;
V_8 -> V_24 &= ~ V_25 ;
F_159 ( V_8 ) ;
F_158 ( V_8 ) ;
F_161 ( V_2 ) ;
V_8 -> V_182 = V_183 ;
V_92 = F_165 ( V_2 ) ;
if ( V_92 )
F_43 ( & V_8 -> V_12 -> V_13 , L_26 ,
V_92 ) ;
V_8 -> V_95 = V_244 ;
V_8 -> V_95 |= V_96 ;
F_59 (f, &adapter->mac_filter_list, list) {
V_127 -> V_134 = true ;
}
F_59 (vlf, &adapter->vlan_filter_list, list) {
V_256 -> V_134 = true ;
}
V_8 -> V_95 |= V_144 ;
V_8 -> V_95 |= V_135 ;
F_65 ( V_128 , & V_8 -> V_129 ) ;
F_65 ( V_257 , & V_8 -> V_129 ) ;
F_20 ( V_8 ) ;
F_154 ( & V_8 -> V_176 , V_177 + 2 ) ;
if ( F_156 ( V_8 -> V_29 ) ) {
V_92 = F_170 ( V_8 ) ;
if ( V_92 )
goto V_264;
V_92 = F_171 ( V_8 ) ;
if ( V_92 )
goto V_264;
F_86 ( V_8 ) ;
F_89 ( V_8 ) ;
F_26 ( V_8 , true ) ;
} else {
V_8 -> V_98 = V_241 ;
}
return;
V_264:
F_49 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
F_172 ( V_8 -> V_29 ) ;
}
static void F_173 ( struct V_231 * V_232 )
{
struct V_7 * V_8 =
F_39 ( V_232 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_265 V_266 ;
struct V_267 * V_268 ;
T_1 V_207 ;
T_3 V_49 , V_269 ;
T_7 V_270 ;
if ( V_8 -> V_24 & V_180 )
goto V_94;
V_266 . V_271 = V_272 ;
V_266 . V_273 = F_7 ( V_266 . V_271 , V_16 ) ;
if ( ! V_266 . V_273 )
goto V_94;
V_268 = (struct V_267 * ) & V_266 . V_274 ;
do {
V_207 = F_174 ( V_2 , & V_266 , & V_270 ) ;
if ( V_207 || ! V_268 -> V_275 )
break;
F_175 ( V_8 , V_268 -> V_275 ,
( T_1 ) V_268 -> V_276 ,
V_266 . V_273 ,
V_266 . V_277 ) ;
if ( V_270 != 0 )
memset ( V_266 . V_273 , 0 , V_272 ) ;
} while ( V_270 );
if ( ( V_8 -> V_24 &
( V_25 | V_26 ) ) ||
V_8 -> V_98 == V_181 )
goto V_278;
V_49 = F_18 ( V_2 , V_2 -> V_210 . V_279 . V_280 ) ;
if ( V_49 == 0xdeadbeef )
goto V_278;
V_269 = V_49 ;
if ( V_49 & V_281 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_49 &= ~ V_281 ;
}
if ( V_49 & V_282 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_282 ;
}
if ( V_49 & V_283 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_283 ;
}
if ( V_269 != V_49 )
F_17 ( V_2 , V_2 -> V_210 . V_279 . V_280 , V_49 ) ;
V_49 = F_18 ( V_2 , V_2 -> V_210 . V_284 . V_280 ) ;
V_269 = V_49 ;
if ( V_49 & V_285 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_285 ;
}
if ( V_49 & V_286 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_286 ;
}
if ( V_49 & V_287 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_287 ;
}
if ( V_269 != V_49 )
F_17 ( V_2 , V_2 -> V_210 . V_284 . V_280 , V_49 ) ;
V_278:
F_9 ( V_266 . V_273 ) ;
V_94:
F_20 ( V_8 ) ;
}
static void F_176 ( struct V_231 * V_232 )
{
struct V_7 * V_8 =
F_39 ( V_232 , struct V_7 , V_250 . V_232 ) ;
if ( F_61 ( V_257 , & V_8 -> V_129 ) )
return;
if ( V_8 -> V_24 & V_260 ) {
F_177 ( V_8 ) ;
V_8 -> V_24 &= ~ V_260 ;
goto V_94;
}
if ( V_8 -> V_24 & V_258 ) {
F_164 ( & V_8 -> V_67 , false ) ;
V_8 -> V_24 &= ~ V_258 ;
goto V_94;
}
if ( V_8 -> V_24 & V_175 ) {
F_178 ( & V_8 -> V_67 ) ;
V_8 -> V_24 &= ~ V_175 ;
goto V_94;
}
if ( V_8 -> V_24 & V_259 ) {
F_179 ( & V_8 -> V_67 ) ;
V_8 -> V_24 &= ~ V_259 ;
}
V_94:
F_65 ( V_257 , & V_8 -> V_129 ) ;
}
void F_158 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_79 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
if ( V_8 -> V_79 [ V_39 ] . V_274 )
F_180 ( & V_8 -> V_79 [ V_39 ] ) ;
}
static int F_170 ( struct V_7 * V_8 )
{
int V_39 , V_92 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_79 [ V_39 ] . V_68 = V_8 -> V_192 ;
V_92 = F_181 ( & V_8 -> V_79 [ V_39 ] ) ;
if ( ! V_92 )
continue;
F_49 ( & V_8 -> V_12 -> V_13 ,
L_34 , V_39 ) ;
break;
}
return V_92 ;
}
static int F_171 ( struct V_7 * V_8 )
{
int V_39 , V_92 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_68 = V_8 -> V_197 ;
V_92 = F_182 ( & V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_92 )
continue;
F_49 ( & V_8 -> V_12 -> V_13 ,
L_35 , V_39 ) ;
break;
}
return V_92 ;
}
void F_159 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_65 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] . V_274 )
F_183 ( & V_8 -> V_65 [ V_39 ] ) ;
}
static int F_184 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_92 ;
if ( V_8 -> V_24 & V_180 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_36 ) ;
return - V_139 ;
}
if ( V_8 -> V_98 != V_241 )
return - V_208 ;
V_92 = F_170 ( V_8 ) ;
if ( V_92 )
goto V_288;
V_92 = F_171 ( V_8 ) ;
if ( V_92 )
goto V_289;
V_92 = F_41 ( V_8 , V_29 -> V_109 ) ;
if ( V_92 )
goto V_290;
F_72 ( V_8 , V_8 -> V_2 . V_153 . V_147 ) ;
F_86 ( V_8 ) ;
F_89 ( V_8 ) ;
F_26 ( V_8 , true ) ;
return 0 ;
V_290:
F_92 ( V_8 ) ;
F_50 ( V_8 ) ;
V_289:
F_159 ( V_8 ) ;
V_288:
F_158 ( V_8 ) ;
return V_92 ;
}
static int F_172 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( V_8 -> V_98 <= V_178 )
return 0 ;
F_157 ( V_97 , V_8 -> V_67 . V_98 ) ;
if ( F_90 ( V_8 ) )
V_8 -> V_24 |= V_258 ;
F_92 ( V_8 ) ;
V_8 -> V_98 = V_178 ;
F_50 ( V_8 ) ;
return 0 ;
}
static int F_185 ( struct V_28 * V_29 , int V_291 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_29 -> V_121 = V_291 ;
if ( F_90 ( V_8 ) ) {
F_179 ( & V_8 -> V_67 ) ;
V_8 -> V_24 |= V_260 ;
}
V_8 -> V_24 |= V_26 ;
F_13 ( & V_8 -> V_27 ) ;
return 0 ;
}
static T_11 F_186 ( struct V_292 * V_293 ,
struct V_28 * V_13 ,
T_11 V_294 )
{
T_12 V_280 ;
if ( V_293 -> V_295 != V_296 )
return V_294 ;
if ( F_187 ( V_293 ) && ( F_188 ( V_293 ) -> V_297 < 64 ) )
V_294 &= ~ V_298 ;
V_280 = F_189 ( V_293 ) - V_293 -> V_48 ;
if ( V_280 & ~ ( 63 * 2 ) )
goto V_299;
V_280 = F_190 ( V_293 ) - F_189 ( V_293 ) ;
if ( V_280 & ~ ( 127 * 4 ) )
goto V_299;
if ( V_293 -> V_300 ) {
V_280 = F_191 ( V_293 ) - F_190 ( V_293 ) ;
if ( V_280 & ~ ( 127 * 2 ) )
goto V_299;
V_280 = F_192 ( V_293 ) -
F_191 ( V_293 ) ;
if ( V_280 & ~ ( 127 * 4 ) )
goto V_299;
}
return V_294 ;
V_299:
return V_294 & ~ ( V_301 | V_298 ) ;
}
static T_11 F_193 ( struct V_28 * V_29 ,
T_11 V_294 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_294 &= ~ V_302 ;
if ( V_8 -> V_201 -> V_218 & V_303 )
V_294 |= V_302 ;
return V_294 ;
}
static int F_194 ( struct V_1 * V_2 )
{
T_3 V_304 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_304 = F_18 ( V_2 , V_33 ) &
V_235 ;
if ( ( V_304 == V_236 ) ||
( V_304 == V_237 ) )
return 0 ;
F_93 ( 10 , 20 ) ;
}
return - V_208 ;
}
int F_195 ( struct V_7 * V_8 )
{
struct V_305 * V_306 = V_8 -> V_201 ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_307 * V_67 = & V_8 -> V_67 ;
int V_39 ;
T_11 V_308 ;
T_11 V_309 ;
for ( V_39 = 0 ; V_39 < V_306 -> V_310 ; V_39 ++ ) {
if ( V_306 -> V_188 [ V_39 ] . V_311 == V_312 )
V_8 -> V_188 = & V_306 -> V_188 [ V_39 ] ;
}
if ( ! V_8 -> V_188 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_37 ) ;
return - V_313 ;
}
V_308 = V_314 |
V_315 |
V_316 |
V_317 |
V_318 |
V_319 |
V_320 |
V_321 |
V_322 |
V_323 |
V_324 |
0 ;
if ( V_306 -> V_218 & V_325 ) {
V_308 |= V_326 |
V_327 |
V_328 |
V_329 |
V_330 |
V_331 |
V_332 |
0 ;
if ( ! ( V_306 -> V_218 &
V_333 ) )
V_29 -> V_334 |=
V_331 ;
V_29 -> V_334 |= V_328 ;
V_29 -> V_308 |= V_335 ;
V_29 -> V_308 |= V_308 ;
}
V_29 -> V_336 |= V_308 | V_335 ;
V_309 = V_308 ;
V_29 -> V_309 |= V_309 ;
V_29 -> V_294 |= V_309 | V_302 ;
V_8 -> V_67 . V_209 = V_8 -> V_188 -> V_337 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_338 = 1 ;
V_8 -> V_67 . V_339 = V_340 ;
V_67 -> V_29 = V_8 -> V_29 ;
V_67 -> V_341 = V_8 -> V_188 -> V_342 ;
if ( V_306 -> V_218 & V_343 ) {
V_8 -> V_215 = V_306 -> V_215 ;
V_8 -> V_213 = V_306 -> V_213 ;
} else {
V_8 -> V_215 = V_344 ;
V_8 -> V_213 = V_345 ;
}
return 0 ;
}
static void F_196 ( struct V_231 * V_232 )
{
struct V_7 * V_8 = F_39 ( V_232 ,
struct V_7 ,
V_239 . V_232 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_346 * V_12 = V_8 -> V_12 ;
int V_92 , V_347 ;
switch ( V_8 -> V_98 ) {
case V_238 :
V_8 -> V_24 &= ~ V_180 ;
V_8 -> V_24 &= ~ V_25 ;
V_92 = F_197 ( V_2 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_38 ,
V_92 ) ;
goto V_92;
}
V_92 = F_194 ( V_2 ) ;
if ( V_92 ) {
F_43 ( & V_12 -> V_13 , L_39 ,
V_92 ) ;
goto V_92;
}
V_2 -> V_210 . V_348 = V_349 ;
V_2 -> V_210 . V_350 = V_349 ;
V_2 -> V_210 . V_351 = V_272 ;
V_2 -> V_210 . V_352 = V_272 ;
V_92 = F_165 ( V_2 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_40 ,
V_92 ) ;
goto V_92;
}
V_92 = F_137 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_41 , V_92 ) ;
F_161 ( V_2 ) ;
goto V_92;
}
V_8 -> V_98 = V_353 ;
goto V_354;
case V_353 :
if ( ! F_135 ( V_2 ) ) {
F_49 ( & V_12 -> V_13 , L_42 ) ;
F_161 ( V_2 ) ;
V_8 -> V_98 = V_238 ;
goto V_92;
}
V_92 = F_198 ( V_8 ) ;
if ( V_92 ) {
if ( V_92 == V_355 )
V_92 = F_137 ( V_8 ) ;
else
F_49 ( & V_12 -> V_13 , L_43 ,
V_8 -> V_356 . V_357 ,
V_8 -> V_356 . V_358 ,
V_359 ,
V_360 ) ;
goto V_92;
}
V_92 = F_138 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_44 ,
V_92 ) ;
goto V_92;
}
V_8 -> V_98 = V_361 ;
goto V_354;
case V_361 :
if ( ! V_8 -> V_201 ) {
V_347 = sizeof( struct V_305 ) +
( V_362 *
sizeof( struct V_363 ) ) ;
V_8 -> V_201 = F_7 ( V_347 , V_16 ) ;
if ( ! V_8 -> V_201 )
goto V_92;
}
V_92 = F_199 ( V_8 ) ;
if ( V_92 == V_355 ) {
V_92 = F_138 ( V_8 ) ;
goto V_92;
} else if ( V_92 == V_10 ) {
F_161 ( V_2 ) ;
F_49 ( & V_12 -> V_13 , L_45 ) ;
return;
}
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_46 ,
V_92 ) ;
goto V_364;
}
V_8 -> V_98 = V_365 ;
break;
default:
goto V_364;
}
if ( F_195 ( V_8 ) )
goto V_364;
V_8 -> V_182 = V_183 ;
V_8 -> V_24 |= V_366 ;
V_29 -> V_367 = & V_368 ;
F_200 ( V_29 ) ;
V_29 -> V_369 = 5 * V_252 ;
V_29 -> V_370 = V_371 ;
V_29 -> V_372 = V_373 - ( V_374 + V_375 ) ;
if ( ! F_76 ( V_8 -> V_2 . V_153 . V_147 ) ) {
F_43 ( & V_12 -> V_13 , L_47 ,
V_8 -> V_2 . V_153 . V_147 ) ;
F_201 ( V_29 ) ;
F_73 ( V_8 -> V_2 . V_153 . V_147 , V_29 -> V_150 ) ;
} else {
V_8 -> V_24 |= V_151 ;
F_73 ( V_29 -> V_150 , V_8 -> V_2 . V_153 . V_147 ) ;
F_73 ( V_29 -> V_376 , V_8 -> V_2 . V_153 . V_147 ) ;
}
F_202 ( & V_8 -> V_176 ) ;
V_8 -> V_176 . V_377 = & F_132 ;
V_8 -> V_176 . V_48 = ( unsigned long ) V_8 ;
F_154 ( & V_8 -> V_176 , V_177 + 1 ) ;
V_8 -> V_192 = V_378 ;
V_8 -> V_197 = V_379 ;
V_92 = F_128 ( V_8 ) ;
if ( V_92 )
goto V_380;
F_34 ( V_8 ) ;
if ( V_8 -> V_201 -> V_218 &
V_381 )
V_8 -> V_24 |= V_382 ;
V_92 = F_47 ( V_8 ) ;
if ( V_92 )
goto V_380;
F_94 ( V_29 ) ;
V_8 -> V_179 = false ;
if ( ! V_8 -> V_383 ) {
V_92 = F_203 ( V_29 ) ;
if ( V_92 )
goto V_384;
}
V_8 -> V_383 = true ;
F_169 ( V_29 ) ;
if ( F_204 ( V_8 ) ) {
V_92 = F_205 ( V_8 ) ;
if ( V_92 )
F_43 ( & V_12 -> V_13 , L_48 ,
V_92 ) ;
}
F_43 ( & V_12 -> V_13 , L_49 , V_8 -> V_2 . V_153 . V_147 ) ;
if ( V_29 -> V_294 & V_385 )
F_43 ( & V_12 -> V_13 , L_50 ) ;
V_8 -> V_98 = V_241 ;
F_157 ( V_97 , V_8 -> V_67 . V_98 ) ;
F_20 ( V_8 ) ;
V_8 -> V_206 = F_7 ( V_8 -> V_215 , V_16 ) ;
V_8 -> V_212 = F_7 ( V_8 -> V_213 , V_16 ) ;
if ( ! V_8 -> V_206 || ! V_8 -> V_212 )
goto V_386;
if ( F_117 ( V_8 ) ) {
V_8 -> V_95 |= V_245 ;
F_91 ( & V_8 -> V_176 , V_177 + 1 ) ;
} else {
F_119 ( V_8 ) ;
}
return;
V_354:
F_134 ( & V_8 -> V_239 , F_152 ( 30 ) ) ;
return;
V_386:
F_131 ( V_8 ) ;
V_384:
F_51 ( V_8 ) ;
V_380:
F_126 ( V_8 ) ;
V_364:
F_9 ( V_8 -> V_201 ) ;
V_8 -> V_201 = NULL ;
V_92:
if ( ++ V_8 -> V_387 > V_388 ) {
F_49 ( & V_12 -> V_13 , L_51 ) ;
V_8 -> V_24 |= V_180 ;
F_161 ( V_2 ) ;
V_8 -> V_98 = V_238 ;
F_134 ( & V_8 -> V_239 , V_252 * 5 ) ;
return;
}
F_134 ( & V_8 -> V_239 , V_252 ) ;
}
static void F_206 ( struct V_346 * V_12 )
{
struct V_28 * V_29 = F_207 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
F_208 ( V_29 ) ;
if ( F_156 ( V_29 ) )
F_172 ( V_29 ) ;
V_8 -> V_98 = V_251 ;
V_8 -> V_95 = 0 ;
#ifdef F_209
F_210 ( V_12 ) ;
#endif
F_211 ( V_12 ) ;
}
static int F_212 ( struct V_346 * V_12 , const struct V_389 * V_390 )
{
struct V_28 * V_29 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_92 ;
V_92 = F_213 ( V_12 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_214 ( & V_12 -> V_13 , F_215 ( 64 ) ) ;
if ( V_92 ) {
V_92 = F_214 ( & V_12 -> V_13 , F_215 ( 32 ) ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 ,
L_52 , V_92 ) ;
goto V_391;
}
}
V_92 = F_216 ( V_12 , V_392 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 ,
L_53 , V_92 ) ;
goto V_393;
}
F_217 ( V_12 ) ;
F_168 ( V_12 ) ;
V_29 = F_218 ( sizeof( struct V_7 ) , V_394 ) ;
if ( ! V_29 ) {
V_92 = - V_140 ;
goto V_395;
}
F_219 ( V_29 , & V_12 -> V_13 ) ;
F_220 ( V_12 , V_29 ) ;
V_8 = F_15 ( V_29 ) ;
V_8 -> V_29 = V_29 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_396 = F_24 ( V_397 ) - 1 ;
V_8 -> V_98 = V_238 ;
F_210 ( V_12 ) ;
V_2 -> V_114 = F_221 ( F_222 ( V_12 , 0 ) ,
F_223 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_114 ) {
V_92 = - V_139 ;
goto V_398;
}
V_2 -> V_399 = V_12 -> V_400 ;
V_2 -> V_401 = V_12 -> V_402 ;
F_224 ( V_12 , V_403 , & V_2 -> V_404 ) ;
V_2 -> V_405 = V_12 -> V_406 ;
V_2 -> V_407 = V_12 -> V_408 ;
V_2 -> V_409 . V_402 = F_225 ( V_12 -> V_410 ) ;
V_2 -> V_409 . V_411 = F_226 ( V_12 -> V_410 ) ;
V_2 -> V_409 . V_412 = V_12 -> V_409 -> V_413 ;
F_227 ( & V_2 -> V_210 . V_414 ) ;
F_227 ( & V_2 -> V_210 . V_415 ) ;
F_63 ( & V_8 -> V_143 ) ;
F_63 ( & V_8 -> V_133 ) ;
F_228 ( & V_8 -> V_27 , F_162 ) ;
F_228 ( & V_8 -> V_52 , F_173 ) ;
F_228 ( & V_8 -> V_230 , F_133 ) ;
F_229 ( & V_8 -> V_250 , F_176 ) ;
F_229 ( & V_8 -> V_239 , F_196 ) ;
F_134 ( & V_8 -> V_239 ,
F_152 ( 5 * ( V_12 -> V_410 & 0x07 ) ) ) ;
return 0 ;
V_398:
F_230 ( V_29 ) ;
V_395:
F_231 ( V_12 ) ;
V_393:
V_391:
F_211 ( V_12 ) ;
return V_92 ;
}
static int F_232 ( struct V_346 * V_12 , T_13 V_98 )
{
struct V_28 * V_29 = F_207 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_416 = 0 ;
F_208 ( V_29 ) ;
if ( F_156 ( V_29 ) ) {
F_129 () ;
F_92 ( V_8 ) ;
F_130 () ;
}
F_51 ( V_8 ) ;
F_126 ( V_8 ) ;
V_416 = F_210 ( V_12 ) ;
if ( V_416 )
return V_416 ;
F_211 ( V_12 ) ;
return 0 ;
}
static int F_233 ( struct V_346 * V_12 )
{
struct V_7 * V_8 = F_207 ( V_12 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
T_3 V_92 ;
F_234 ( V_12 , V_417 ) ;
F_235 ( V_12 ) ;
F_210 ( V_12 ) ;
V_92 = F_236 ( V_12 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_54 ) ;
return V_92 ;
}
F_168 ( V_12 ) ;
F_129 () ;
V_92 = F_103 ( V_8 ) ;
if ( V_92 ) {
F_130 () ;
F_49 ( & V_12 -> V_13 , L_55 ) ;
return V_92 ;
}
V_92 = F_47 ( V_8 ) ;
F_130 () ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_56 ) ;
return V_92 ;
}
F_13 ( & V_8 -> V_27 ) ;
F_237 ( V_29 ) ;
return V_92 ;
}
static void F_238 ( struct V_346 * V_12 )
{
struct V_28 * V_29 = F_207 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_141 * V_127 , * V_155 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_92 ;
F_163 ( & V_8 -> V_239 ) ;
F_239 ( & V_8 -> V_27 ) ;
F_163 ( & V_8 -> V_250 ) ;
if ( V_8 -> V_383 ) {
F_240 ( V_29 ) ;
V_8 -> V_383 = false ;
}
if ( F_204 ( V_8 ) ) {
V_92 = F_241 ( V_8 ) ;
if ( V_92 )
F_242 ( & V_12 -> V_13 , L_57 ,
V_92 ) ;
}
V_8 -> V_98 = V_251 ;
V_8 -> V_95 = 0 ;
F_166 ( V_8 ) ;
F_167 ( 50 ) ;
if ( ! F_135 ( V_2 ) ) {
F_166 ( V_8 ) ;
F_167 ( 50 ) ;
}
F_158 ( V_8 ) ;
F_159 ( V_8 ) ;
F_16 ( V_8 ) ;
F_51 ( V_8 ) ;
F_126 ( V_8 ) ;
F_124 ( V_8 ) ;
if ( V_8 -> V_176 . V_377 )
F_243 ( & V_8 -> V_176 ) ;
F_244 () ;
F_131 ( V_8 ) ;
if ( V_2 -> V_210 . V_284 . V_68 )
F_161 ( V_2 ) ;
F_245 ( & V_2 -> V_210 . V_415 ) ;
F_245 ( & V_2 -> V_210 . V_414 ) ;
F_246 ( V_2 -> V_114 ) ;
F_231 ( V_12 ) ;
F_158 ( V_8 ) ;
F_159 ( V_8 ) ;
F_98 ( V_8 ) ;
F_9 ( V_8 -> V_201 ) ;
F_80 (f, ftmp, &adapter->mac_filter_list, list) {
F_160 ( & V_127 -> V_132 ) ;
F_9 ( V_127 ) ;
}
F_80 (f, ftmp, &adapter->vlan_filter_list, list) {
F_160 ( & V_127 -> V_132 ) ;
F_9 ( V_127 ) ;
}
F_230 ( V_29 ) ;
F_247 ( V_12 ) ;
F_211 ( V_12 ) ;
}
static int T_14 F_248 ( void )
{
int V_207 ;
F_11 ( L_58 , V_418 ,
V_419 ) ;
F_11 ( L_59 , V_420 ) ;
V_421 = F_249 ( L_1 , V_422 | V_423 , 1 ,
V_392 ) ;
if ( ! V_421 ) {
F_250 ( L_60 , V_392 ) ;
return - V_140 ;
}
V_207 = F_251 ( & V_424 ) ;
return V_207 ;
}
static void T_15 F_252 ( void )
{
F_253 ( & V_424 ) ;
F_254 ( V_421 ) ;
}
