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
V_44 = F_18 ( V_2 , V_31 ) ;
V_44 |= V_45 |
V_42 |
V_43 ;
F_17 ( V_2 , V_31 , V_44 ) ;
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
F_18 ( V_2 , V_32 ) ;
}
static T_5 F_27 ( int V_47 , void * V_48 )
{
struct V_28 * V_29 = V_48 ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_49 ;
V_49 = F_18 ( V_2 , V_50 ) ;
V_49 = F_18 ( V_2 , V_37 ) ;
V_49 = F_18 ( V_2 , V_31 ) |
V_51 ;
F_17 ( V_2 , V_31 , V_49 ) ;
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
if ( F_37 ( V_97 , & V_8 -> V_67 . V_98 ) )
return;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ )
F_28 ( 0 , & V_8 -> V_62 [ V_39 ] ) ;
}
static int
F_38 ( struct V_7 * V_8 , char * V_99 )
{
int V_34 , V_92 , V_62 ;
int V_100 = 0 , V_101 = 0 ;
F_21 ( V_8 ) ;
V_62 = V_8 -> V_40 - V_93 ;
for ( V_34 = 0 ; V_34 < V_62 ; V_34 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_34 ] ;
if ( V_55 -> V_56 . V_57 && V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_102 , sizeof( V_55 -> V_102 ) - 1 ,
L_2 , V_99 ,
L_3 , V_100 ++ ) ;
V_101 ++ ;
} else if ( V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_102 , sizeof( V_55 -> V_102 ) - 1 ,
L_2 , V_99 ,
L_4 , V_100 ++ ) ;
} else if ( V_55 -> V_56 . V_57 ) {
snprintf ( V_55 -> V_102 , sizeof( V_55 -> V_102 ) - 1 ,
L_2 , V_99 ,
L_5 , V_101 ++ ) ;
} else {
continue;
}
V_92 = F_39 (
V_8 -> V_33 [ V_34 + V_93 ] . V_34 ,
F_28 ,
0 ,
V_55 -> V_102 ,
V_55 ) ;
if ( V_92 ) {
F_40 ( & V_8 -> V_12 -> V_13 ,
L_6 , V_92 ) ;
goto V_103;
}
F_41 (
V_8 -> V_33 [ V_34 + V_93 ] . V_34 ,
V_55 -> V_104 ) ;
}
return 0 ;
V_103:
while ( V_34 ) {
V_34 -- ;
F_41 (
V_8 -> V_33 [ V_34 + V_93 ] . V_34 ,
NULL ) ;
F_42 ( V_8 -> V_33 [ V_34 + V_93 ] . V_34 ,
& V_8 -> V_62 [ V_34 ] ) ;
}
return V_92 ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_92 ;
snprintf ( V_8 -> V_105 ,
sizeof( V_8 -> V_105 ) - 1 , L_7 ,
F_44 ( & V_8 -> V_12 -> V_13 ) ) ;
V_92 = F_39 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_27 , 0 ,
V_8 -> V_105 , V_29 ) ;
if ( V_92 ) {
F_45 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_105 , V_92 ) ;
F_42 ( V_8 -> V_33 [ 0 ] . V_34 , V_29 ) ;
}
return V_92 ;
}
static void F_46 ( struct V_7 * V_8 )
{
int V_39 ;
int V_62 ;
V_62 = V_8 -> V_40 - V_93 ;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ ) {
F_41 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_42 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
& V_8 -> V_62 [ V_39 ] ) ;
}
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
F_42 ( V_8 -> V_33 [ 0 ] . V_34 , V_29 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
V_8 -> V_79 [ V_39 ] . V_106 = V_2 -> V_107 + F_49 ( V_39 ) ;
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_106 = V_2 -> V_107 + F_51 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] . V_108 = V_109 ;
}
}
static struct
V_110 * F_52 ( struct V_7 * V_8 , T_6 V_111 )
{
struct V_110 * V_112 ;
F_53 (f, &adapter->vlan_filter_list, list) {
if ( V_111 == V_112 -> V_111 )
return V_112 ;
}
return NULL ;
}
static struct
V_110 * F_54 ( struct V_7 * V_8 , T_6 V_111 )
{
struct V_110 * V_112 = NULL ;
int V_68 = 50 ;
while ( F_55 ( V_113 ,
& V_8 -> V_114 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_94;
}
V_112 = F_52 ( V_8 , V_111 ) ;
if ( ! V_112 ) {
V_112 = F_7 ( sizeof( * V_112 ) , V_115 ) ;
if ( ! V_112 )
goto V_116;
V_112 -> V_111 = V_111 ;
F_57 ( & V_112 -> V_117 ) ;
F_58 ( & V_112 -> V_117 , & V_8 -> V_118 ) ;
V_112 -> V_119 = true ;
V_8 -> V_95 |= V_120 ;
}
V_116:
F_59 ( V_113 , & V_8 -> V_114 ) ;
V_94:
return V_112 ;
}
static void F_60 ( struct V_7 * V_8 , T_6 V_111 )
{
struct V_110 * V_112 ;
int V_68 = 50 ;
while ( F_55 ( V_113 ,
& V_8 -> V_114 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_112 = F_52 ( V_8 , V_111 ) ;
if ( V_112 ) {
V_112 -> remove = true ;
V_8 -> V_95 |= V_121 ;
}
F_59 ( V_113 , & V_8 -> V_114 ) ;
}
static int F_61 ( struct V_28 * V_29 ,
T_7 T_8 V_122 , T_6 V_123 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( ! F_62 ( V_8 ) )
return - V_124 ;
if ( F_54 ( V_8 , V_123 ) == NULL )
return - V_125 ;
return 0 ;
}
static int F_63 ( struct V_28 * V_29 ,
T_7 T_8 V_122 , T_6 V_123 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( F_62 ( V_8 ) ) {
F_60 ( V_8 , V_123 ) ;
return 0 ;
}
return - V_124 ;
}
static struct
V_126 * F_64 ( struct V_7 * V_8 ,
T_9 * V_127 )
{
struct V_126 * V_112 ;
if ( ! V_127 )
return NULL ;
F_53 (f, &adapter->mac_filter_list, list) {
if ( F_65 ( V_127 , V_112 -> V_127 ) )
return V_112 ;
}
return NULL ;
}
static struct
V_126 * F_66 ( struct V_7 * V_8 ,
T_9 * V_127 )
{
struct V_126 * V_112 ;
int V_68 = 50 ;
if ( ! V_127 )
return NULL ;
while ( F_55 ( V_113 ,
& V_8 -> V_114 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_112 = F_64 ( V_8 , V_127 ) ;
if ( ! V_112 ) {
V_112 = F_7 ( sizeof( * V_112 ) , V_115 ) ;
if ( ! V_112 ) {
F_59 ( V_113 ,
& V_8 -> V_114 ) ;
return NULL ;
}
F_67 ( V_112 -> V_127 , V_127 ) ;
F_68 ( & V_112 -> V_117 , & V_8 -> V_128 ) ;
V_112 -> V_119 = true ;
V_8 -> V_95 |= V_129 ;
}
F_59 ( V_113 , & V_8 -> V_114 ) ;
return V_112 ;
}
static int F_69 ( struct V_28 * V_29 , void * V_130 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_126 * V_112 ;
struct V_131 * V_132 = V_130 ;
if ( ! F_70 ( V_132 -> V_133 ) )
return - V_134 ;
if ( F_65 ( V_29 -> V_135 , V_132 -> V_133 ) )
return 0 ;
if ( V_8 -> V_24 & V_136 )
return - V_137 ;
V_112 = F_64 ( V_8 , V_2 -> V_138 . V_132 ) ;
if ( V_112 ) {
V_112 -> remove = true ;
V_8 -> V_95 |= V_139 ;
}
V_112 = F_66 ( V_8 , V_132 -> V_133 ) ;
if ( V_112 ) {
F_67 ( V_2 -> V_138 . V_132 , V_132 -> V_133 ) ;
F_67 ( V_29 -> V_135 , V_8 -> V_2 . V_138 . V_132 ) ;
}
return ( V_112 == NULL ) ? - V_125 : 0 ;
}
static void F_71 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_126 * V_112 , * V_140 ;
struct V_141 * V_142 ;
struct V_141 * V_143 ;
struct V_141 * V_144 ;
int V_68 = 50 ;
F_72 (uca, netdev) {
F_66 ( V_8 , V_142 -> V_132 ) ;
}
F_73 (mca, netdev) {
F_66 ( V_8 , V_143 -> V_132 ) ;
}
while ( F_55 ( V_113 ,
& V_8 -> V_114 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_45 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_145 ) ;
return;
}
}
F_74 (f, ftmp, &adapter->mac_filter_list, list) {
F_73 (mca, netdev)
if ( F_65 ( V_143 -> V_132 , V_112 -> V_127 ) )
goto V_146;
F_72 (uca, netdev)
if ( F_65 ( V_142 -> V_132 , V_112 -> V_127 ) )
goto V_146;
F_75 (netdev, ha)
if ( F_65 ( V_144 -> V_132 , V_112 -> V_127 ) )
goto V_146;
if ( F_65 ( V_112 -> V_127 , V_8 -> V_2 . V_138 . V_132 ) )
goto V_146;
V_112 -> remove = true ;
V_8 -> V_95 |= V_139 ;
V_146:
continue;
}
if ( V_29 -> V_24 & V_147 &&
! ( V_8 -> V_24 & V_148 ) )
V_8 -> V_95 |= V_149 ;
else if ( ! ( V_29 -> V_24 & V_147 ) &&
V_8 -> V_24 & V_148 )
V_8 -> V_95 |= V_150 ;
if ( V_29 -> V_24 & V_151 &&
! ( V_8 -> V_24 & V_152 ) )
V_8 -> V_95 |= V_153 ;
else if ( ! ( V_29 -> V_24 & V_151 ) &&
V_8 -> V_24 & V_152 )
V_8 -> V_95 |= V_154 ;
F_59 ( V_113 , & V_8 -> V_114 ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
int V_155 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_93 ;
for ( V_155 = 0 ; V_155 < V_62 ; V_155 ++ ) {
struct V_156 * V_59 ;
V_55 = & V_8 -> V_62 [ V_155 ] ;
V_59 = & V_55 -> V_59 ;
F_77 ( V_59 ) ;
}
}
static void F_78 ( struct V_7 * V_8 )
{
int V_155 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_93 ;
for ( V_155 = 0 ; V_155 < V_62 ; V_155 ++ ) {
V_55 = & V_8 -> V_62 [ V_155 ] ;
F_79 ( & V_55 -> V_59 ) ;
}
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_39 ;
F_71 ( V_29 ) ;
F_48 ( V_8 ) ;
F_50 ( V_8 ) ;
V_8 -> V_95 |= V_157 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
struct V_63 * V_57 = & V_8 -> V_65 [ V_39 ] ;
F_81 ( V_57 , F_82 ( V_57 ) ) ;
}
}
static void F_83 ( struct V_7 * V_8 )
{
V_8 -> V_98 = V_158 ;
F_59 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_76 ( V_8 ) ;
V_8 -> V_95 |= V_159 ;
F_84 ( & V_8 -> V_160 , V_161 + 1 ) ;
}
void F_85 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_126 * V_112 ;
if ( V_8 -> V_98 <= V_162 )
return;
while ( F_55 ( V_113 ,
& V_8 -> V_114 ) )
F_86 ( 500 , 1000 ) ;
F_87 ( V_29 ) ;
F_88 ( V_29 ) ;
V_8 -> V_163 = false ;
F_78 ( V_8 ) ;
F_21 ( V_8 ) ;
F_53 (f, &adapter->mac_filter_list, list) {
V_112 -> remove = true ;
}
F_53 (f, &adapter->vlan_filter_list, list) {
V_112 -> remove = true ;
}
if ( ! ( V_8 -> V_24 & V_164 ) &&
V_8 -> V_98 != V_165 ) {
V_8 -> V_166 = V_167 ;
V_8 -> V_95 = V_139 ;
V_8 -> V_95 |= V_121 ;
V_8 -> V_95 |= V_168 ;
}
F_59 ( V_113 , & V_8 -> V_114 ) ;
}
static int
F_89 ( struct V_7 * V_8 , int V_169 )
{
int V_92 , V_170 ;
V_170 = V_171 ;
V_92 = F_90 ( V_8 -> V_12 , V_8 -> V_33 ,
V_170 , V_169 ) ;
if ( V_92 < 0 ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_92 ;
}
V_8 -> V_40 = V_92 ;
return 0 ;
}
static void F_91 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_172 )
return;
F_9 ( V_8 -> V_79 ) ;
V_8 -> V_79 = NULL ;
F_9 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
}
static int F_92 ( struct V_7 * V_8 )
{
int V_39 ;
V_8 -> V_79 = F_93 ( V_8 -> V_87 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_79 )
goto V_173;
V_8 -> V_65 = F_93 ( V_8 -> V_87 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_65 )
goto V_173;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
struct V_63 * V_78 ;
struct V_63 * V_64 ;
V_78 = & V_8 -> V_79 [ V_39 ] ;
V_78 -> V_174 = V_39 ;
V_78 -> V_29 = V_8 -> V_29 ;
V_78 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_78 -> V_68 = V_8 -> V_175 ;
V_78 -> V_80 = ( V_176 | V_177 ) ;
if ( V_8 -> V_24 & V_178 )
V_78 -> V_24 |= V_179 ;
V_64 = & V_8 -> V_65 [ V_39 ] ;
V_64 -> V_174 = V_39 ;
V_64 -> V_29 = V_8 -> V_29 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_180 ;
V_64 -> V_72 = ( V_176 | V_181 ) ;
}
return 0 ;
V_173:
F_91 ( V_8 ) ;
return - V_125 ;
}
static int F_94 ( struct V_7 * V_8 )
{
int V_34 , V_182 ;
int V_183 = 0 ;
int V_92 = 0 ;
if ( ! V_8 -> V_172 ) {
V_92 = - V_124 ;
goto V_94;
}
V_183 = V_8 -> V_87 ;
V_182 = F_95 ( int , V_183 , ( int ) ( F_96 () * 2 ) ) + V_93 ;
V_182 = F_95 ( int , V_182 , ( int ) V_8 -> V_184 -> V_185 ) ;
V_8 -> V_33 = F_93 ( V_182 ,
sizeof( struct V_186 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_92 = - V_125 ;
goto V_94;
}
for ( V_34 = 0 ; V_34 < V_182 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_187 = V_34 ;
V_92 = F_89 ( V_8 , V_182 ) ;
V_94:
F_97 ( V_8 -> V_29 , V_183 ) ;
F_98 ( V_8 -> V_29 , V_183 ) ;
return V_92 ;
}
static int F_99 ( struct V_7 * V_8 )
{
struct V_188 * V_189 =
(struct V_188 * ) V_8 -> V_189 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_190 = 0 ;
if ( V_8 -> V_166 != V_167 ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_166 ) ;
return - V_191 ;
}
V_190 = F_100 ( V_2 , V_8 -> V_67 . V_192 , V_189 ) ;
if ( V_190 ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_12 ,
F_101 ( V_2 , V_190 ) ,
F_102 ( V_2 , V_2 -> V_193 . V_194 ) ) ;
return V_190 ;
}
V_190 = F_103 ( V_2 , V_8 -> V_67 . V_192 , false ,
V_8 -> V_195 , V_8 -> V_196 ) ;
if ( V_190 ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_13 ,
F_101 ( V_2 , V_190 ) ,
F_102 ( V_2 , V_2 -> V_193 . V_194 ) ) ;
}
return V_190 ;
}
static int F_104 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 * V_197 ;
T_6 V_39 ;
V_197 = ( T_3 * ) V_8 -> V_189 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_198 / 4 ; V_39 ++ )
F_17 ( V_2 , F_105 ( V_39 ) , V_197 [ V_39 ] ) ;
V_197 = ( T_3 * ) V_8 -> V_195 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_196 / 4 ; V_39 ++ )
F_17 ( V_2 , F_106 ( V_39 ) , V_197 [ V_39 ] ) ;
F_107 ( V_2 ) ;
return 0 ;
}
int F_108 ( struct V_7 * V_8 )
{
if ( F_109 ( V_8 ) ) {
V_8 -> V_95 |= V_199 |
V_200 ;
return 0 ;
} else if ( F_110 ( V_8 ) ) {
return F_99 ( V_8 ) ;
} else {
return F_104 ( V_8 ) ;
}
}
static void F_111 ( struct V_7 * V_8 )
{
T_6 V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_196 ; V_39 ++ )
V_8 -> V_195 [ V_39 ] = V_39 % V_8 -> V_87 ;
}
static int F_112 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_190 ;
if ( ! F_109 ( V_8 ) ) {
if ( V_8 -> V_184 -> V_201 &
V_202 )
V_8 -> V_203 = V_204 ;
else
V_8 -> V_203 = V_205 ;
F_17 ( V_2 , F_113 ( 0 ) , ( T_3 ) V_8 -> V_203 ) ;
F_17 ( V_2 , F_113 ( 1 ) , ( T_3 ) ( V_8 -> V_203 >> 32 ) ) ;
}
F_111 ( V_8 ) ;
F_114 ( ( void * ) V_8 -> V_189 , V_8 -> V_198 ) ;
V_190 = F_108 ( V_8 ) ;
return V_190 ;
}
static int F_115 ( struct V_7 * V_8 )
{
int V_155 = 0 , V_206 ;
struct V_54 * V_55 ;
V_206 = V_8 -> V_40 - V_93 ;
V_8 -> V_62 = F_93 ( V_206 , sizeof( * V_55 ) ,
V_16 ) ;
if ( ! V_8 -> V_62 )
return - V_125 ;
for ( V_155 = 0 ; V_155 < V_206 ; V_155 ++ ) {
V_55 = & V_8 -> V_62 [ V_155 ] ;
V_55 -> V_8 = V_8 ;
V_55 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_60 = V_155 ;
F_116 ( V_8 -> V_29 , & V_55 -> V_59 ,
V_207 , V_208 ) ;
}
return 0 ;
}
static void F_117 ( struct V_7 * V_8 )
{
int V_155 , V_206 ;
int V_209 ;
V_206 = V_8 -> V_40 - V_93 ;
V_209 = V_8 -> V_87 ;
for ( V_155 = 0 ; V_155 < V_206 ; V_155 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_155 ] ;
if ( V_155 < V_209 )
F_118 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
}
void F_119 ( struct V_7 * V_8 )
{
F_120 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_121 ( struct V_7 * V_8 )
{
int V_92 ;
F_122 () ;
V_92 = F_94 ( V_8 ) ;
F_123 () ;
if ( V_92 ) {
F_45 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_210;
}
V_92 = F_115 ( V_8 ) ;
if ( V_92 ) {
F_45 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_211;
}
V_92 = F_92 ( V_8 ) ;
if ( V_92 ) {
F_45 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_212;
}
F_40 ( & V_8 -> V_12 -> V_13 , L_17 ,
( V_8 -> V_87 > 1 ) ? L_18 : L_19 ,
V_8 -> V_87 ) ;
return 0 ;
V_212:
F_117 ( V_8 ) ;
V_211:
F_119 ( V_8 ) ;
V_210:
return V_92 ;
}
static void F_124 ( struct V_7 * V_8 )
{
F_9 ( V_8 -> V_189 ) ;
V_8 -> V_189 = NULL ;
F_9 ( V_8 -> V_195 ) ;
V_8 -> V_195 = NULL ;
}
static void F_125 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_13 ( & V_8 -> V_213 ) ;
}
static void F_126 ( struct V_214 * V_215 )
{
struct V_7 * V_8 = F_127 ( V_215 ,
struct V_7 ,
V_213 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_216 ;
if ( F_55 ( V_113 , & V_8 -> V_114 ) )
goto V_217;
if ( V_8 -> V_24 & V_164 ) {
V_216 = F_18 ( V_2 , V_32 ) &
V_218 ;
if ( ( V_216 == V_219 ) ||
( V_216 == V_220 ) ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_98 = V_221 ;
V_8 -> V_24 &= ~ V_164 ;
F_128 ( & V_8 -> V_222 , 10 ) ;
F_59 ( V_113 ,
& V_8 -> V_114 ) ;
return;
}
V_8 -> V_95 = 0 ;
V_8 -> V_166 = V_167 ;
goto V_223;
}
if ( ( V_8 -> V_98 < V_224 ) ||
( V_8 -> V_24 & V_25 ) )
goto V_223;
V_216 = F_18 ( V_2 , V_225 ) & V_226 ;
if ( ! ( V_8 -> V_24 & V_25 ) && ! V_216 ) {
V_8 -> V_98 = V_165 ;
V_8 -> V_24 |= V_25 ;
F_45 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_13 ( & V_8 -> V_27 ) ;
V_8 -> V_95 = 0 ;
V_8 -> V_166 = V_167 ;
goto V_223;
}
if ( V_8 -> V_166 ) {
if ( ! F_129 ( V_2 ) ) {
F_130 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_131 ( V_8 ) ;
}
goto V_223;
}
if ( V_8 -> V_95 & V_227 ) {
F_132 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_168 ) {
F_133 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_96 ) {
F_134 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_129 ) {
F_135 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_120 ) {
F_136 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_139 ) {
F_137 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_121 ) {
F_138 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_157 ) {
F_139 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_159 ) {
F_140 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_228 ) {
F_112 ( V_8 ) ;
V_8 -> V_95 &= ~ V_228 ;
goto V_223;
}
if ( V_8 -> V_95 & V_229 ) {
F_141 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_230 ) {
F_142 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_200 ) {
F_143 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_199 ) {
F_144 ( V_8 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_149 ) {
F_145 ( V_8 , V_231 |
V_232 ) ;
goto V_223;
}
if ( V_8 -> V_95 & V_153 ) {
F_145 ( V_8 , V_232 ) ;
goto V_223;
}
if ( ( V_8 -> V_95 & V_150 ) &&
( V_8 -> V_95 & V_154 ) ) {
F_145 ( V_8 , 0 ) ;
goto V_223;
}
if ( V_8 -> V_98 == V_158 )
F_146 ( V_8 ) ;
V_223:
if ( V_8 -> V_98 == V_158 ) {
F_23 ( V_8 , ~ 0 ) ;
F_25 ( V_8 , 0xFF ) ;
} else {
F_25 ( V_8 , 0x1 ) ;
}
F_59 ( V_113 , & V_8 -> V_114 ) ;
V_217:
if ( V_8 -> V_98 == V_233 )
return;
if ( V_8 -> V_95 )
F_147 ( & V_8 -> V_160 ,
V_161 + F_148 ( 20 ) ) ;
else
F_147 ( & V_8 -> V_160 , V_161 + ( V_234 * 2 ) ) ;
F_13 ( & V_8 -> V_52 ) ;
}
static void F_149 ( struct V_214 * V_215 )
{
struct V_7 * V_8 = F_127 ( V_215 ,
struct V_7 ,
V_27 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_110 * V_235 ;
struct V_126 * V_112 ;
T_3 V_216 ;
int V_39 = 0 , V_92 ;
while ( F_55 ( V_113 ,
& V_8 -> V_114 ) )
F_86 ( 500 , 1000 ) ;
F_16 ( V_8 ) ;
if ( V_8 -> V_24 & V_26 ) {
V_8 -> V_24 &= ~ V_26 ;
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
F_152 ( V_8 ) ;
}
V_8 -> V_24 |= V_25 ;
for ( V_39 = 0 ; V_39 < V_236 ; V_39 ++ ) {
V_216 = F_18 ( V_2 , V_225 ) &
V_226 ;
if ( ! V_216 )
break;
F_86 ( 5000 , 10000 ) ;
}
if ( V_39 == V_236 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
goto V_237;
}
for ( V_39 = 0 ; V_39 < V_236 ; V_39 ++ ) {
V_216 = F_18 ( V_2 , V_32 ) &
V_218 ;
if ( V_216 == V_219 )
break;
F_153 ( V_238 ) ;
}
F_154 ( V_8 -> V_12 ) ;
F_153 ( V_238 ) ;
if ( V_39 == V_236 ) {
struct V_126 * V_140 ;
struct V_110 * V_239 , * V_240 ;
F_45 ( & V_8 -> V_12 -> V_13 , L_24 ,
V_216 ) ;
V_8 -> V_24 |= V_164 ;
if ( F_155 ( V_8 -> V_29 ) ) {
F_156 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_87 ( V_29 ) ;
F_88 ( V_29 ) ;
V_8 -> V_163 = false ;
F_78 ( V_8 ) ;
F_21 ( V_8 ) ;
F_46 ( V_8 ) ;
F_157 ( V_8 ) ;
F_158 ( V_8 ) ;
}
F_74 (f, ftmp, &adapter->mac_filter_list,
list) {
F_159 ( & V_112 -> V_117 ) ;
F_9 ( V_112 ) ;
}
F_74 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_159 ( & V_239 -> V_117 ) ;
F_9 ( V_239 ) ;
}
F_47 ( V_8 ) ;
F_119 ( V_8 ) ;
F_91 ( V_8 ) ;
F_117 ( V_8 ) ;
F_9 ( V_8 -> V_184 ) ;
F_150 ( V_2 ) ;
V_8 -> V_29 -> V_24 &= ~ V_241 ;
F_59 ( V_113 , & V_8 -> V_114 ) ;
V_8 -> V_24 &= ~ V_25 ;
V_8 -> V_98 = V_224 ;
F_40 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
return;
}
V_237:
if ( F_155 ( V_8 -> V_29 ) ) {
F_87 ( V_29 ) ;
F_160 ( V_29 ) ;
V_8 -> V_163 = false ;
F_78 ( V_8 ) ;
}
F_21 ( V_8 ) ;
V_8 -> V_98 = V_165 ;
V_8 -> V_24 &= ~ V_25 ;
F_158 ( V_8 ) ;
F_157 ( V_8 ) ;
F_150 ( V_2 ) ;
V_8 -> V_166 = V_167 ;
V_92 = F_151 ( V_2 ) ;
if ( V_92 )
F_40 ( & V_8 -> V_12 -> V_13 , L_26 ,
V_92 ) ;
V_8 -> V_95 = V_227 ;
V_8 -> V_95 |= V_96 ;
F_53 (f, &adapter->mac_filter_list, list) {
V_112 -> V_119 = true ;
}
F_53 (vlf, &adapter->vlan_filter_list, list) {
V_235 -> V_119 = true ;
}
V_8 -> V_95 |= V_129 ;
V_8 -> V_95 |= V_120 ;
V_8 -> V_95 |= V_242 ;
F_59 ( V_113 , & V_8 -> V_114 ) ;
F_20 ( V_8 ) ;
F_147 ( & V_8 -> V_160 , V_161 + 2 ) ;
if ( F_155 ( V_8 -> V_29 ) ) {
V_92 = F_161 ( V_8 ) ;
if ( V_92 )
goto V_243;
V_92 = F_162 ( V_8 ) ;
if ( V_92 )
goto V_243;
F_80 ( V_8 ) ;
F_83 ( V_8 ) ;
F_26 ( V_8 , true ) ;
} else {
V_8 -> V_98 = V_224 ;
}
return;
V_243:
F_45 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
F_163 ( V_8 -> V_29 ) ;
}
static void F_164 ( struct V_214 * V_215 )
{
struct V_7 * V_8 =
F_127 ( V_215 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_244 V_245 ;
struct V_246 * V_247 ;
T_1 V_190 ;
T_3 V_49 , V_248 ;
T_6 V_249 ;
if ( V_8 -> V_24 & V_164 )
goto V_94;
V_245 . V_250 = V_251 ;
V_245 . V_252 = F_7 ( V_245 . V_250 , V_16 ) ;
if ( ! V_245 . V_252 )
goto V_94;
V_247 = (struct V_246 * ) & V_245 . V_253 ;
do {
V_190 = F_165 ( V_2 , & V_245 , & V_249 ) ;
if ( V_190 || ! V_247 -> V_254 )
break;
F_166 ( V_8 , V_247 -> V_254 ,
V_247 -> V_255 , V_245 . V_252 ,
V_245 . V_256 ) ;
if ( V_249 != 0 )
memset ( V_245 . V_252 , 0 , V_251 ) ;
} while ( V_249 );
if ( ( V_8 -> V_24 &
( V_25 | V_26 ) ) ||
V_8 -> V_98 == V_165 )
goto V_257;
V_49 = F_18 ( V_2 , V_2 -> V_193 . V_258 . V_259 ) ;
if ( V_49 == 0xdeadbeef )
goto V_257;
V_248 = V_49 ;
if ( V_49 & V_260 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_49 &= ~ V_260 ;
}
if ( V_49 & V_261 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_261 ;
}
if ( V_49 & V_262 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_262 ;
}
if ( V_248 != V_49 )
F_17 ( V_2 , V_2 -> V_193 . V_258 . V_259 , V_49 ) ;
V_49 = F_18 ( V_2 , V_2 -> V_193 . V_263 . V_259 ) ;
V_248 = V_49 ;
if ( V_49 & V_264 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_264 ;
}
if ( V_49 & V_265 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_265 ;
}
if ( V_49 & V_266 ) {
F_40 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_266 ;
}
if ( V_248 != V_49 )
F_17 ( V_2 , V_2 -> V_193 . V_263 . V_259 , V_49 ) ;
V_257:
F_9 ( V_245 . V_252 ) ;
V_94:
F_20 ( V_8 ) ;
}
void F_157 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_79 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
if ( V_8 -> V_79 [ V_39 ] . V_253 )
F_167 ( & V_8 -> V_79 [ V_39 ] ) ;
}
static int F_161 ( struct V_7 * V_8 )
{
int V_39 , V_92 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_79 [ V_39 ] . V_68 = V_8 -> V_175 ;
V_92 = F_168 ( & V_8 -> V_79 [ V_39 ] ) ;
if ( ! V_92 )
continue;
F_45 ( & V_8 -> V_12 -> V_13 ,
L_34 , V_39 ) ;
break;
}
return V_92 ;
}
static int F_162 ( struct V_7 * V_8 )
{
int V_39 , V_92 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_68 = V_8 -> V_180 ;
V_92 = F_169 ( & V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_92 )
continue;
F_45 ( & V_8 -> V_12 -> V_13 ,
L_35 , V_39 ) ;
break;
}
return V_92 ;
}
void F_158 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_65 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] . V_253 )
F_170 ( & V_8 -> V_65 [ V_39 ] ) ;
}
static int F_171 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_92 ;
if ( V_8 -> V_24 & V_164 ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_36 ) ;
return - V_124 ;
}
if ( V_8 -> V_98 != V_224 )
return - V_191 ;
V_92 = F_161 ( V_8 ) ;
if ( V_92 )
goto V_267;
V_92 = F_162 ( V_8 ) ;
if ( V_92 )
goto V_268;
V_92 = F_38 ( V_8 , V_29 -> V_102 ) ;
if ( V_92 )
goto V_269;
F_66 ( V_8 , V_8 -> V_2 . V_138 . V_132 ) ;
F_80 ( V_8 ) ;
F_83 ( V_8 ) ;
F_26 ( V_8 , true ) ;
return 0 ;
V_269:
F_85 ( V_8 ) ;
F_46 ( V_8 ) ;
V_268:
F_158 ( V_8 ) ;
V_267:
F_157 ( V_8 ) ;
return V_92 ;
}
static int F_163 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( V_8 -> V_98 <= V_162 )
return 0 ;
F_156 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_85 ( V_8 ) ;
V_8 -> V_98 = V_162 ;
F_46 ( V_8 ) ;
return 0 ;
}
static struct V_270 * F_172 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
return & V_8 -> V_271 ;
}
static int F_173 ( struct V_28 * V_29 , int V_272 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_273 = V_272 + V_274 + V_275 ;
if ( ( V_272 < 68 ) || ( V_273 > V_276 ) )
return - V_277 ;
V_29 -> V_278 = V_272 ;
V_8 -> V_24 |= V_26 ;
F_13 ( & V_8 -> V_27 ) ;
return 0 ;
}
static T_10 F_174 ( struct V_28 * V_29 ,
T_10 V_279 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_279 &= ~ V_280 ;
if ( V_8 -> V_184 -> V_201 & V_281 )
V_279 |= V_280 ;
return V_279 ;
}
static int F_175 ( struct V_1 * V_2 )
{
T_3 V_282 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_282 = F_18 ( V_2 , V_32 ) &
V_218 ;
if ( ( V_282 == V_219 ) ||
( V_282 == V_220 ) )
return 0 ;
F_86 ( 10 , 20 ) ;
}
return - V_191 ;
}
int F_176 ( struct V_7 * V_8 )
{
struct V_283 * V_284 = V_8 -> V_184 ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_285 * V_67 = & V_8 -> V_67 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_284 -> V_286 ; V_39 ++ ) {
if ( V_284 -> V_172 [ V_39 ] . V_287 == V_288 )
V_8 -> V_172 = & V_284 -> V_172 [ V_39 ] ;
}
if ( ! V_8 -> V_172 ) {
F_45 ( & V_8 -> V_12 -> V_13 , L_37 ) ;
return - V_289 ;
}
V_29 -> V_290 |= V_291 |
V_292 |
V_293 |
V_294 |
V_295 |
V_296 |
V_297 |
V_298 |
V_299 |
V_300 |
V_301 |
V_302 |
V_303 |
V_304 |
V_305 |
V_306 |
V_307 |
V_308 |
0 ;
if ( ! ( V_8 -> V_24 & V_309 ) )
V_29 -> V_310 |= V_304 ;
V_29 -> V_310 |= V_300 ;
V_29 -> V_311 |= V_29 -> V_290 |
V_312 ;
V_29 -> V_313 |= V_29 -> V_290 ;
V_29 -> V_279 |= V_29 -> V_290 | V_280 ;
V_29 -> V_290 |= V_312 ;
if ( ! ( V_284 -> V_201 & V_281 ) )
V_29 -> V_279 ^= V_280 ;
V_8 -> V_67 . V_192 = V_8 -> V_172 -> V_314 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_315 = 1 ;
V_8 -> V_67 . V_316 = V_317 ;
V_67 -> V_29 = V_8 -> V_29 ;
V_67 -> V_318 = V_8 -> V_172 -> V_319 ;
if ( V_284 -> V_201 & V_320 ) {
V_8 -> V_198 = V_284 -> V_198 ;
V_8 -> V_196 = V_284 -> V_196 ;
} else {
V_8 -> V_198 = V_321 ;
V_8 -> V_196 = V_322 ;
}
return 0 ;
}
static void F_177 ( struct V_214 * V_215 )
{
struct V_7 * V_8 = F_127 ( V_215 ,
struct V_7 ,
V_222 . V_215 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_323 * V_12 = V_8 -> V_12 ;
int V_92 , V_324 ;
switch ( V_8 -> V_98 ) {
case V_221 :
V_8 -> V_24 &= ~ V_164 ;
V_8 -> V_24 &= ~ V_25 ;
V_92 = F_178 ( V_2 ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_38 ,
V_92 ) ;
goto V_92;
}
V_92 = F_175 ( V_2 ) ;
if ( V_92 ) {
F_40 ( & V_12 -> V_13 , L_39 ,
V_92 ) ;
goto V_92;
}
V_2 -> V_193 . V_325 = V_326 ;
V_2 -> V_193 . V_327 = V_326 ;
V_2 -> V_193 . V_328 = V_251 ;
V_2 -> V_193 . V_329 = V_251 ;
V_92 = F_151 ( V_2 ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_40 ,
V_92 ) ;
goto V_92;
}
V_92 = F_131 ( V_8 ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_41 , V_92 ) ;
F_150 ( V_2 ) ;
goto V_92;
}
V_8 -> V_98 = V_330 ;
goto V_331;
case V_330 :
if ( ! F_129 ( V_2 ) ) {
F_45 ( & V_12 -> V_13 , L_42 ) ;
F_150 ( V_2 ) ;
V_8 -> V_98 = V_221 ;
goto V_92;
}
V_92 = F_179 ( V_8 ) ;
if ( V_92 ) {
if ( V_92 == V_332 )
V_92 = F_131 ( V_8 ) ;
else
F_45 ( & V_12 -> V_13 , L_43 ,
V_8 -> V_333 . V_334 ,
V_8 -> V_333 . V_335 ,
V_336 ,
V_337 ) ;
goto V_92;
}
V_92 = F_132 ( V_8 ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_44 ,
V_92 ) ;
goto V_92;
}
V_8 -> V_98 = V_338 ;
goto V_331;
case V_338 :
if ( ! V_8 -> V_184 ) {
V_324 = sizeof( struct V_283 ) +
( V_339 *
sizeof( struct V_340 ) ) ;
V_8 -> V_184 = F_7 ( V_324 , V_16 ) ;
if ( ! V_8 -> V_184 )
goto V_92;
}
V_92 = F_180 ( V_8 ) ;
if ( V_92 == V_332 ) {
V_92 = F_132 ( V_8 ) ;
goto V_92;
} else if ( V_92 == V_10 ) {
F_150 ( V_2 ) ;
F_45 ( & V_12 -> V_13 , L_45 ) ;
return;
}
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_46 ,
V_92 ) ;
goto V_341;
}
V_8 -> V_98 = V_342 ;
break;
default:
goto V_341;
}
if ( V_2 -> V_138 . type == V_343 )
V_8 -> V_24 |= V_309 ;
if ( F_176 ( V_8 ) )
goto V_341;
V_8 -> V_166 = V_167 ;
V_8 -> V_24 |= V_344 ;
V_29 -> V_345 = & V_346 ;
F_181 ( V_29 ) ;
V_29 -> V_347 = 5 * V_234 ;
if ( ! F_70 ( V_8 -> V_2 . V_138 . V_132 ) ) {
F_40 ( & V_12 -> V_13 , L_47 ,
V_8 -> V_2 . V_138 . V_132 ) ;
F_182 ( V_29 ) ;
F_67 ( V_8 -> V_2 . V_138 . V_132 , V_29 -> V_135 ) ;
} else {
V_8 -> V_24 |= V_136 ;
F_67 ( V_29 -> V_135 , V_8 -> V_2 . V_138 . V_132 ) ;
F_67 ( V_29 -> V_348 , V_8 -> V_2 . V_138 . V_132 ) ;
}
F_183 ( & V_8 -> V_160 ) ;
V_8 -> V_160 . V_349 = & F_125 ;
V_8 -> V_160 . V_48 = ( unsigned long ) V_8 ;
F_147 ( & V_8 -> V_160 , V_161 + 1 ) ;
V_8 -> V_87 = F_95 ( int ,
V_8 -> V_172 -> V_350 ,
( int ) ( F_96 () ) ) ;
V_8 -> V_175 = V_351 ;
V_8 -> V_180 = V_352 ;
V_92 = F_121 ( V_8 ) ;
if ( V_92 )
goto V_353;
F_34 ( V_8 ) ;
if ( V_8 -> V_184 -> V_201 &
V_354 )
V_8 -> V_24 |= V_355 ;
V_92 = F_43 ( V_8 ) ;
if ( V_92 )
goto V_353;
F_87 ( V_29 ) ;
V_8 -> V_163 = false ;
if ( ! V_8 -> V_356 ) {
V_92 = F_184 ( V_29 ) ;
if ( V_92 )
goto V_357;
}
V_8 -> V_356 = true ;
F_160 ( V_29 ) ;
F_40 ( & V_12 -> V_13 , L_48 , V_8 -> V_2 . V_138 . V_132 ) ;
if ( V_29 -> V_279 & V_358 )
F_40 ( & V_12 -> V_13 , L_49 ) ;
V_8 -> V_98 = V_224 ;
F_156 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_20 ( V_8 ) ;
V_8 -> V_189 = F_7 ( V_8 -> V_198 , V_16 ) ;
V_8 -> V_195 = F_7 ( V_8 -> V_196 , V_16 ) ;
if ( ! V_8 -> V_189 || ! V_8 -> V_195 )
goto V_359;
if ( F_110 ( V_8 ) ) {
V_8 -> V_95 |= V_228 ;
F_84 ( & V_8 -> V_160 , V_161 + 1 ) ;
} else {
F_112 ( V_8 ) ;
}
return;
V_331:
F_128 ( & V_8 -> V_222 , F_148 ( 30 ) ) ;
return;
V_359:
F_124 ( V_8 ) ;
V_357:
F_47 ( V_8 ) ;
V_353:
F_119 ( V_8 ) ;
V_341:
F_9 ( V_8 -> V_184 ) ;
V_8 -> V_184 = NULL ;
V_92:
if ( ++ V_8 -> V_360 > V_361 ) {
F_45 ( & V_12 -> V_13 , L_50 ) ;
V_8 -> V_24 |= V_164 ;
F_150 ( V_2 ) ;
V_8 -> V_98 = V_221 ;
F_128 ( & V_8 -> V_222 , V_234 * 5 ) ;
return;
}
F_128 ( & V_8 -> V_222 , V_234 ) ;
}
static void F_185 ( struct V_323 * V_12 )
{
struct V_28 * V_29 = F_186 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
F_187 ( V_29 ) ;
if ( F_155 ( V_29 ) )
F_163 ( V_29 ) ;
V_8 -> V_98 = V_233 ;
V_8 -> V_95 = 0 ;
#ifdef F_188
F_189 ( V_12 ) ;
#endif
F_190 ( V_12 ) ;
}
static int F_191 ( struct V_323 * V_12 , const struct V_362 * V_363 )
{
struct V_28 * V_29 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_92 ;
V_92 = F_192 ( V_12 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_193 ( & V_12 -> V_13 , F_194 ( 64 ) ) ;
if ( V_92 ) {
V_92 = F_193 ( & V_12 -> V_13 , F_194 ( 32 ) ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 ,
L_51 , V_92 ) ;
goto V_364;
}
}
V_92 = F_195 ( V_12 , V_365 ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 ,
L_52 , V_92 ) ;
goto V_366;
}
F_196 ( V_12 ) ;
F_154 ( V_12 ) ;
V_29 = F_197 ( sizeof( struct V_7 ) , V_367 ) ;
if ( ! V_29 ) {
V_92 = - V_125 ;
goto V_368;
}
F_198 ( V_29 , & V_12 -> V_13 ) ;
F_199 ( V_12 , V_29 ) ;
V_8 = F_15 ( V_29 ) ;
V_8 -> V_29 = V_29 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_369 = F_24 ( V_370 ) - 1 ;
V_8 -> V_98 = V_221 ;
F_189 ( V_12 ) ;
V_2 -> V_107 = F_200 ( F_201 ( V_12 , 0 ) ,
F_202 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_107 ) {
V_92 = - V_124 ;
goto V_371;
}
V_2 -> V_372 = V_12 -> V_373 ;
V_2 -> V_374 = V_12 -> V_375 ;
F_203 ( V_12 , V_376 , & V_2 -> V_377 ) ;
V_2 -> V_378 = V_12 -> V_379 ;
V_2 -> V_380 = V_12 -> V_381 ;
V_2 -> V_382 . V_375 = F_204 ( V_12 -> V_383 ) ;
V_2 -> V_382 . V_384 = F_205 ( V_12 -> V_383 ) ;
F_206 ( & V_2 -> V_193 . V_385 ) ;
F_206 ( & V_2 -> V_193 . V_386 ) ;
F_57 ( & V_8 -> V_128 ) ;
F_57 ( & V_8 -> V_118 ) ;
F_207 ( & V_8 -> V_27 , F_149 ) ;
F_207 ( & V_8 -> V_52 , F_164 ) ;
F_207 ( & V_8 -> V_213 , F_126 ) ;
F_208 ( & V_8 -> V_222 , F_177 ) ;
F_128 ( & V_8 -> V_222 ,
F_148 ( 5 * ( V_12 -> V_383 & 0x07 ) ) ) ;
return 0 ;
V_371:
F_209 ( V_29 ) ;
V_368:
F_210 ( V_12 ) ;
V_366:
V_364:
F_190 ( V_12 ) ;
return V_92 ;
}
static int F_211 ( struct V_323 * V_12 , T_11 V_98 )
{
struct V_28 * V_29 = F_186 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_387 = 0 ;
F_187 ( V_29 ) ;
if ( F_155 ( V_29 ) ) {
F_122 () ;
F_85 ( V_8 ) ;
F_123 () ;
}
F_47 ( V_8 ) ;
F_119 ( V_8 ) ;
V_387 = F_189 ( V_12 ) ;
if ( V_387 )
return V_387 ;
F_190 ( V_12 ) ;
return 0 ;
}
static int F_212 ( struct V_323 * V_12 )
{
struct V_7 * V_8 = F_186 ( V_12 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
T_3 V_92 ;
F_213 ( V_12 , V_388 ) ;
F_214 ( V_12 ) ;
F_189 ( V_12 ) ;
V_92 = F_215 ( V_12 ) ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_53 ) ;
return V_92 ;
}
F_154 ( V_12 ) ;
F_122 () ;
V_92 = F_94 ( V_8 ) ;
if ( V_92 ) {
F_123 () ;
F_45 ( & V_12 -> V_13 , L_54 ) ;
return V_92 ;
}
V_92 = F_43 ( V_8 ) ;
F_123 () ;
if ( V_92 ) {
F_45 ( & V_12 -> V_13 , L_55 ) ;
return V_92 ;
}
F_13 ( & V_8 -> V_27 ) ;
F_216 ( V_29 ) ;
return V_92 ;
}
static void F_217 ( struct V_323 * V_12 )
{
struct V_28 * V_29 = F_186 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_126 * V_112 , * V_140 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_218 ( & V_8 -> V_222 ) ;
F_219 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_356 ) {
F_220 ( V_29 ) ;
V_8 -> V_356 = false ;
}
V_8 -> V_98 = V_233 ;
V_8 -> V_95 = 0 ;
F_152 ( V_8 ) ;
F_153 ( 50 ) ;
if ( ! F_129 ( V_2 ) ) {
F_152 ( V_8 ) ;
F_153 ( 50 ) ;
}
if ( V_8 -> V_33 ) {
F_16 ( V_8 ) ;
F_47 ( V_8 ) ;
F_119 ( V_8 ) ;
F_117 ( V_8 ) ;
}
if ( V_8 -> V_160 . V_349 )
F_221 ( & V_8 -> V_160 ) ;
F_222 () ;
F_124 ( V_8 ) ;
if ( V_2 -> V_193 . V_263 . V_68 )
F_150 ( V_2 ) ;
F_223 ( & V_2 -> V_193 . V_386 ) ;
F_223 ( & V_2 -> V_193 . V_385 ) ;
F_224 ( V_2 -> V_107 ) ;
F_210 ( V_12 ) ;
F_157 ( V_8 ) ;
F_158 ( V_8 ) ;
F_91 ( V_8 ) ;
F_9 ( V_8 -> V_184 ) ;
F_74 (f, ftmp, &adapter->mac_filter_list, list) {
F_159 ( & V_112 -> V_117 ) ;
F_9 ( V_112 ) ;
}
F_74 (f, ftmp, &adapter->vlan_filter_list, list) {
F_159 ( & V_112 -> V_117 ) ;
F_9 ( V_112 ) ;
}
F_209 ( V_29 ) ;
F_225 ( V_12 ) ;
F_190 ( V_12 ) ;
}
static int T_12 F_226 ( void )
{
int V_190 ;
F_11 ( L_56 , V_389 ,
V_390 ) ;
F_11 ( L_57 , V_391 ) ;
V_392 = F_227 ( L_1 , V_393 | V_394 , 1 ,
V_365 ) ;
if ( ! V_392 ) {
F_228 ( L_58 , V_365 ) ;
return - V_125 ;
}
V_190 = F_229 ( & V_395 ) ;
return V_190 ;
}
static void T_13 F_230 ( void )
{
F_231 ( & V_395 ) ;
F_232 ( V_392 ) ;
}
