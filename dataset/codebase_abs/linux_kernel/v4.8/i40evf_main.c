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
V_64 -> V_55 = V_55 ;
V_64 -> V_66 = V_55 -> V_58 . V_57 ;
V_64 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_58 . V_57 = V_64 ;
V_55 -> V_58 . V_68 ++ ;
V_55 -> V_58 . V_69 = V_70 ;
V_55 -> V_71 = V_72 ;
}
static void
F_31 ( struct V_7 * V_8 , int V_60 , int V_73 )
{
struct V_54 * V_55 = & V_8 -> V_62 [ V_60 ] ;
struct V_63 * V_74 = & V_8 -> V_75 [ V_73 ] ;
V_74 -> V_55 = V_55 ;
V_74 -> V_66 = V_55 -> V_56 . V_57 ;
V_74 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_56 . V_57 = V_74 ;
V_55 -> V_56 . V_68 ++ ;
V_55 -> V_56 . V_69 = V_70 ;
V_55 -> V_71 = V_72 ;
V_55 -> V_76 ++ ;
V_55 -> V_77 |= F_24 ( V_73 ) ;
}
static int F_32 ( struct V_7 * V_8 )
{
int V_62 ;
int V_78 = 0 ;
int V_79 = 0 , V_80 = 0 ;
int V_81 = V_8 -> V_82 ;
int V_83 = V_8 -> V_82 ;
int V_39 , V_84 ;
int V_85 , V_86 ;
int V_87 = 0 ;
V_62 = V_8 -> V_40 - V_88 ;
if ( V_62 >= ( V_81 * 2 ) ) {
for (; V_79 < V_81 ; V_78 ++ , V_79 ++ )
F_30 ( V_8 , V_78 , V_79 ) ;
for (; V_80 < V_83 ; V_78 ++ , V_80 ++ )
F_31 ( V_8 , V_78 , V_80 ) ;
goto V_89;
}
for ( V_39 = V_78 ; V_39 < V_62 ; V_39 ++ ) {
V_85 = F_33 ( V_81 , V_62 - V_39 ) ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ ) {
F_30 ( V_8 , V_39 , V_79 ) ;
V_79 ++ ;
V_81 -- ;
}
}
for ( V_39 = V_78 ; V_39 < V_62 ; V_39 ++ ) {
V_86 = F_33 ( V_83 , V_62 - V_39 ) ;
for ( V_84 = 0 ; V_84 < V_86 ; V_84 ++ ) {
F_31 ( V_8 , V_39 , V_80 ) ;
V_80 ++ ;
V_83 -- ;
}
}
V_89:
V_8 -> V_90 |= V_91 ;
return V_87 ;
}
static void F_34 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_62 = V_8 -> V_40 - V_88 ;
int V_39 ;
if ( F_35 ( V_92 , & V_8 -> V_67 . V_93 ) )
return;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ )
F_28 ( 0 , & V_8 -> V_62 [ V_39 ] ) ;
}
static int
F_36 ( struct V_7 * V_8 , char * V_94 )
{
int V_34 , V_87 , V_62 ;
int V_95 = 0 , V_96 = 0 ;
F_21 ( V_8 ) ;
V_62 = V_8 -> V_40 - V_88 ;
for ( V_34 = 0 ; V_34 < V_62 ; V_34 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_34 ] ;
if ( V_55 -> V_56 . V_57 && V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_97 , sizeof( V_55 -> V_97 ) - 1 ,
L_2 , V_94 ,
L_3 , V_95 ++ ) ;
V_96 ++ ;
} else if ( V_55 -> V_58 . V_57 ) {
snprintf ( V_55 -> V_97 , sizeof( V_55 -> V_97 ) - 1 ,
L_2 , V_94 ,
L_4 , V_95 ++ ) ;
} else if ( V_55 -> V_56 . V_57 ) {
snprintf ( V_55 -> V_97 , sizeof( V_55 -> V_97 ) - 1 ,
L_2 , V_94 ,
L_5 , V_96 ++ ) ;
} else {
continue;
}
V_87 = F_37 (
V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
F_28 ,
0 ,
V_55 -> V_97 ,
V_55 ) ;
if ( V_87 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_6 , V_87 ) ;
goto V_98;
}
F_39 (
V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
V_55 -> V_99 ) ;
}
return 0 ;
V_98:
while ( V_34 ) {
V_34 -- ;
F_39 (
V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
NULL ) ;
F_40 ( V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
& V_8 -> V_62 [ V_34 ] ) ;
}
return V_87 ;
}
static int F_41 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_87 ;
snprintf ( V_8 -> V_100 ,
sizeof( V_8 -> V_100 ) - 1 , L_7 ,
F_42 ( & V_8 -> V_12 -> V_13 ) ) ;
V_87 = F_37 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_27 , 0 ,
V_8 -> V_100 , V_29 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_100 , V_87 ) ;
F_40 ( V_8 -> V_33 [ 0 ] . V_34 , V_29 ) ;
}
return V_87 ;
}
static void F_44 ( struct V_7 * V_8 )
{
int V_39 ;
int V_62 ;
V_62 = V_8 -> V_40 - V_88 ;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ ) {
F_39 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_40 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
& V_8 -> V_62 [ V_39 ] ) ;
}
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
F_40 ( V_8 -> V_33 [ 0 ] . V_34 , V_29 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
V_8 -> V_75 [ V_39 ] . V_101 = V_2 -> V_102 + F_47 ( V_39 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_101 = V_2 -> V_102 + F_49 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] . V_103 = V_104 ;
}
}
static struct
V_105 * F_50 ( struct V_7 * V_8 , T_6 V_106 )
{
struct V_105 * V_107 ;
F_51 (f, &adapter->vlan_filter_list, list) {
if ( V_106 == V_107 -> V_106 )
return V_107 ;
}
return NULL ;
}
static struct
V_105 * F_52 ( struct V_7 * V_8 , T_6 V_106 )
{
struct V_105 * V_107 = NULL ;
int V_68 = 50 ;
while ( F_53 ( V_108 ,
& V_8 -> V_109 ) ) {
F_54 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_89;
}
V_107 = F_50 ( V_8 , V_106 ) ;
if ( ! V_107 ) {
V_107 = F_7 ( sizeof( * V_107 ) , V_110 ) ;
if ( ! V_107 )
goto V_111;
V_107 -> V_106 = V_106 ;
F_55 ( & V_107 -> V_112 ) ;
F_56 ( & V_107 -> V_112 , & V_8 -> V_113 ) ;
V_107 -> V_114 = true ;
V_8 -> V_90 |= V_115 ;
}
V_111:
F_57 ( V_108 , & V_8 -> V_109 ) ;
V_89:
return V_107 ;
}
static void F_58 ( struct V_7 * V_8 , T_6 V_106 )
{
struct V_105 * V_107 ;
int V_68 = 50 ;
while ( F_53 ( V_108 ,
& V_8 -> V_109 ) ) {
F_54 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_107 = F_50 ( V_8 , V_106 ) ;
if ( V_107 ) {
V_107 -> remove = true ;
V_8 -> V_90 |= V_116 ;
}
F_57 ( V_108 , & V_8 -> V_109 ) ;
}
static int F_59 ( struct V_28 * V_29 ,
T_7 T_8 V_117 , T_6 V_118 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( ! F_60 ( V_8 ) )
return - V_119 ;
if ( F_52 ( V_8 , V_118 ) == NULL )
return - V_120 ;
return 0 ;
}
static int F_61 ( struct V_28 * V_29 ,
T_7 T_8 V_117 , T_6 V_118 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( F_60 ( V_8 ) ) {
F_58 ( V_8 , V_118 ) ;
return 0 ;
}
return - V_119 ;
}
static struct
V_121 * F_62 ( struct V_7 * V_8 ,
T_9 * V_122 )
{
struct V_121 * V_107 ;
if ( ! V_122 )
return NULL ;
F_51 (f, &adapter->mac_filter_list, list) {
if ( F_63 ( V_122 , V_107 -> V_122 ) )
return V_107 ;
}
return NULL ;
}
static struct
V_121 * F_64 ( struct V_7 * V_8 ,
T_9 * V_122 )
{
struct V_121 * V_107 ;
int V_68 = 50 ;
if ( ! V_122 )
return NULL ;
while ( F_53 ( V_108 ,
& V_8 -> V_109 ) ) {
F_54 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_107 = F_62 ( V_8 , V_122 ) ;
if ( ! V_107 ) {
V_107 = F_7 ( sizeof( * V_107 ) , V_110 ) ;
if ( ! V_107 ) {
F_57 ( V_108 ,
& V_8 -> V_109 ) ;
return NULL ;
}
F_65 ( V_107 -> V_122 , V_122 ) ;
F_66 ( & V_107 -> V_112 , & V_8 -> V_123 ) ;
V_107 -> V_114 = true ;
V_8 -> V_90 |= V_124 ;
}
F_57 ( V_108 , & V_8 -> V_109 ) ;
return V_107 ;
}
static int F_67 ( struct V_28 * V_29 , void * V_125 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_121 * V_107 ;
struct V_126 * V_127 = V_125 ;
if ( ! F_68 ( V_127 -> V_128 ) )
return - V_129 ;
if ( F_63 ( V_29 -> V_130 , V_127 -> V_128 ) )
return 0 ;
if ( V_8 -> V_24 & V_131 )
return - V_132 ;
V_107 = F_62 ( V_8 , V_2 -> V_133 . V_127 ) ;
if ( V_107 ) {
V_107 -> remove = true ;
V_8 -> V_90 |= V_134 ;
}
V_107 = F_64 ( V_8 , V_127 -> V_128 ) ;
if ( V_107 ) {
F_65 ( V_2 -> V_133 . V_127 , V_127 -> V_128 ) ;
F_65 ( V_29 -> V_130 , V_8 -> V_2 . V_133 . V_127 ) ;
}
return ( V_107 == NULL ) ? - V_120 : 0 ;
}
static void F_69 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_121 * V_107 , * V_135 ;
struct V_136 * V_137 ;
struct V_136 * V_138 ;
struct V_136 * V_139 ;
int V_68 = 50 ;
F_70 (uca, netdev) {
F_64 ( V_8 , V_137 -> V_127 ) ;
}
F_71 (mca, netdev) {
F_64 ( V_8 , V_138 -> V_127 ) ;
}
while ( F_53 ( V_108 ,
& V_8 -> V_109 ) ) {
F_54 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_140 ) ;
return;
}
}
F_72 (f, ftmp, &adapter->mac_filter_list, list) {
F_71 (mca, netdev)
if ( F_63 ( V_138 -> V_127 , V_107 -> V_122 ) )
goto V_141;
F_70 (uca, netdev)
if ( F_63 ( V_137 -> V_127 , V_107 -> V_122 ) )
goto V_141;
F_73 (netdev, ha)
if ( F_63 ( V_139 -> V_127 , V_107 -> V_122 ) )
goto V_141;
if ( F_63 ( V_107 -> V_122 , V_8 -> V_2 . V_133 . V_127 ) )
goto V_141;
V_107 -> remove = true ;
V_8 -> V_90 |= V_134 ;
V_141:
continue;
}
if ( V_29 -> V_24 & V_142 &&
! ( V_8 -> V_24 & V_143 ) )
V_8 -> V_90 |= V_144 ;
else if ( ! ( V_29 -> V_24 & V_142 ) &&
V_8 -> V_24 & V_143 )
V_8 -> V_90 |= V_145 ;
if ( V_29 -> V_24 & V_146 &&
! ( V_8 -> V_24 & V_147 ) )
V_8 -> V_90 |= V_148 ;
else if ( ! ( V_29 -> V_24 & V_146 ) &&
V_8 -> V_24 & V_147 )
V_8 -> V_90 |= V_149 ;
F_57 ( V_108 , & V_8 -> V_109 ) ;
}
static void F_74 ( struct V_7 * V_8 )
{
int V_150 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_88 ;
for ( V_150 = 0 ; V_150 < V_62 ; V_150 ++ ) {
struct V_151 * V_59 ;
V_55 = & V_8 -> V_62 [ V_150 ] ;
V_59 = & V_55 -> V_59 ;
F_75 ( V_59 ) ;
}
}
static void F_76 ( struct V_7 * V_8 )
{
int V_150 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_88 ;
for ( V_150 = 0 ; V_150 < V_62 ; V_150 ++ ) {
V_55 = & V_8 -> V_62 [ V_150 ] ;
F_77 ( & V_55 -> V_59 ) ;
}
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_39 ;
F_69 ( V_29 ) ;
F_46 ( V_8 ) ;
F_48 ( V_8 ) ;
V_8 -> V_90 |= V_152 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_63 * V_57 = & V_8 -> V_65 [ V_39 ] ;
F_79 ( V_57 , F_80 ( V_57 ) ) ;
}
}
static int F_81 ( struct V_7 * V_8 )
{
V_8 -> V_93 = V_153 ;
F_57 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_74 ( V_8 ) ;
V_8 -> V_90 |= V_154 ;
F_82 ( & V_8 -> V_155 , V_156 + 1 ) ;
return 0 ;
}
void F_83 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_121 * V_107 ;
if ( V_8 -> V_93 <= V_157 )
return;
while ( F_53 ( V_108 ,
& V_8 -> V_109 ) )
F_84 ( 500 , 1000 ) ;
F_85 ( V_29 ) ;
F_86 ( V_29 ) ;
F_76 ( V_8 ) ;
F_21 ( V_8 ) ;
F_51 (f, &adapter->mac_filter_list, list) {
V_107 -> remove = true ;
}
F_51 (f, &adapter->vlan_filter_list, list) {
V_107 -> remove = true ;
}
if ( ! ( V_8 -> V_24 & V_158 ) &&
V_8 -> V_93 != V_159 ) {
V_8 -> V_160 = V_161 ;
V_8 -> V_90 = V_134 ;
V_8 -> V_90 |= V_116 ;
V_8 -> V_90 |= V_162 ;
}
F_57 ( V_108 , & V_8 -> V_109 ) ;
}
static int
F_87 ( struct V_7 * V_8 , int V_163 )
{
int V_87 , V_164 ;
V_164 = V_165 ;
V_87 = F_88 ( V_8 -> V_12 , V_8 -> V_33 ,
V_164 , V_163 ) ;
if ( V_87 < 0 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_87 ;
}
V_8 -> V_40 = V_87 ;
return 0 ;
}
static void F_89 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_166 )
return;
F_9 ( V_8 -> V_75 ) ;
V_8 -> V_75 = NULL ;
F_9 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
}
static int F_90 ( struct V_7 * V_8 )
{
int V_39 ;
V_8 -> V_75 = F_91 ( V_8 -> V_82 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_75 )
goto V_167;
V_8 -> V_65 = F_91 ( V_8 -> V_82 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_65 )
goto V_167;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_63 * V_74 ;
struct V_63 * V_64 ;
V_74 = & V_8 -> V_75 [ V_39 ] ;
V_74 -> V_168 = V_39 ;
V_74 -> V_29 = V_8 -> V_29 ;
V_74 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_74 -> V_68 = V_8 -> V_169 ;
if ( V_8 -> V_24 & V_170 )
V_74 -> V_24 |= V_171 ;
V_64 = & V_8 -> V_65 [ V_39 ] ;
V_64 -> V_168 = V_39 ;
V_64 -> V_29 = V_8 -> V_29 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_172 ;
}
return 0 ;
V_167:
F_89 ( V_8 ) ;
return - V_120 ;
}
static int F_92 ( struct V_7 * V_8 )
{
int V_34 , V_173 ;
int V_174 = 0 ;
int V_87 = 0 ;
if ( ! V_8 -> V_166 ) {
V_87 = - V_119 ;
goto V_89;
}
V_174 = V_8 -> V_82 ;
V_173 = F_93 ( int , V_174 , ( int ) ( F_94 () * 2 ) ) + V_88 ;
V_173 = F_93 ( int , V_173 , ( int ) V_8 -> V_175 -> V_176 ) ;
V_8 -> V_33 = F_91 ( V_173 ,
sizeof( struct V_177 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_87 = - V_120 ;
goto V_89;
}
for ( V_34 = 0 ; V_34 < V_173 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_178 = V_34 ;
V_87 = F_87 ( V_8 , V_173 ) ;
V_89:
F_95 ( V_8 -> V_29 , V_174 ) ;
F_96 ( V_8 -> V_29 , V_174 ) ;
return V_87 ;
}
static int F_97 ( struct V_7 * V_8 )
{
struct V_179 * V_180 =
(struct V_179 * ) V_8 -> V_180 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_181 = 0 ;
if ( V_8 -> V_160 != V_161 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_160 ) ;
return - V_182 ;
}
V_181 = F_98 ( V_2 , V_8 -> V_67 . V_183 , V_180 ) ;
if ( V_181 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_12 ,
F_99 ( V_2 , V_181 ) ,
F_100 ( V_2 , V_2 -> V_184 . V_185 ) ) ;
return V_181 ;
}
V_181 = F_101 ( V_2 , V_8 -> V_67 . V_183 , false ,
V_8 -> V_186 , V_8 -> V_187 ) ;
if ( V_181 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_13 ,
F_99 ( V_2 , V_181 ) ,
F_100 ( V_2 , V_2 -> V_184 . V_185 ) ) ;
}
return V_181 ;
}
static int F_102 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 * V_188 ;
T_6 V_39 ;
V_188 = ( T_3 * ) V_8 -> V_180 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_189 / 4 ; V_39 ++ )
F_17 ( V_2 , F_103 ( V_39 ) , V_188 [ V_39 ] ) ;
V_188 = ( T_3 * ) V_8 -> V_186 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_187 / 4 ; V_39 ++ )
F_17 ( V_2 , F_104 ( V_39 ) , V_188 [ V_39 ] ) ;
F_105 ( V_2 ) ;
return 0 ;
}
int F_106 ( struct V_7 * V_8 )
{
if ( F_107 ( V_8 ) ) {
V_8 -> V_90 |= V_190 |
V_191 ;
return 0 ;
} else if ( F_108 ( V_8 ) ) {
return F_97 ( V_8 ) ;
} else {
return F_102 ( V_8 ) ;
}
}
static void F_109 ( struct V_7 * V_8 )
{
T_6 V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_187 ; V_39 ++ )
V_8 -> V_186 [ V_39 ] = V_39 % V_8 -> V_82 ;
}
static int F_110 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_181 ;
if ( ! F_107 ( V_8 ) ) {
if ( V_8 -> V_175 -> V_192 &
V_193 )
V_8 -> V_194 = V_195 ;
else
V_8 -> V_194 = V_196 ;
F_17 ( V_2 , F_111 ( 0 ) , ( T_3 ) V_8 -> V_194 ) ;
F_17 ( V_2 , F_111 ( 1 ) , ( T_3 ) ( V_8 -> V_194 >> 32 ) ) ;
}
F_109 ( V_8 ) ;
F_112 ( ( void * ) V_8 -> V_180 , V_8 -> V_189 ) ;
V_181 = F_106 ( V_8 ) ;
return V_181 ;
}
static int F_113 ( struct V_7 * V_8 )
{
int V_150 = 0 , V_197 ;
struct V_54 * V_55 ;
V_197 = V_8 -> V_40 - V_88 ;
V_8 -> V_62 = F_91 ( V_197 , sizeof( * V_55 ) ,
V_16 ) ;
if ( ! V_8 -> V_62 )
return - V_120 ;
for ( V_150 = 0 ; V_150 < V_197 ; V_150 ++ ) {
V_55 = & V_8 -> V_62 [ V_150 ] ;
V_55 -> V_8 = V_8 ;
V_55 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_60 = V_150 ;
F_114 ( V_8 -> V_29 , & V_55 -> V_59 ,
V_198 , V_199 ) ;
}
return 0 ;
}
static void F_115 ( struct V_7 * V_8 )
{
int V_150 , V_197 ;
int V_200 ;
V_197 = V_8 -> V_40 - V_88 ;
V_200 = V_8 -> V_82 ;
for ( V_150 = 0 ; V_150 < V_197 ; V_150 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_150 ] ;
if ( V_150 < V_200 )
F_116 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
}
void F_117 ( struct V_7 * V_8 )
{
F_118 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_119 ( struct V_7 * V_8 )
{
int V_87 ;
V_87 = F_92 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_201;
}
V_87 = F_113 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_202;
}
V_87 = F_90 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_203;
}
F_38 ( & V_8 -> V_12 -> V_13 , L_17 ,
( V_8 -> V_82 > 1 ) ? L_18 : L_19 ,
V_8 -> V_82 ) ;
return 0 ;
V_203:
F_115 ( V_8 ) ;
V_202:
F_117 ( V_8 ) ;
V_201:
return V_87 ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_9 ( V_8 -> V_180 ) ;
V_8 -> V_180 = NULL ;
F_9 ( V_8 -> V_186 ) ;
V_8 -> V_186 = NULL ;
}
static void F_121 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_13 ( & V_8 -> V_204 ) ;
}
static void F_122 ( struct V_205 * V_206 )
{
struct V_7 * V_8 = F_123 ( V_206 ,
struct V_7 ,
V_204 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_207 ;
if ( F_53 ( V_108 , & V_8 -> V_109 ) )
goto V_208;
if ( V_8 -> V_24 & V_158 ) {
V_207 = F_18 ( V_2 , V_32 ) &
V_209 ;
if ( ( V_207 == V_210 ) ||
( V_207 == V_211 ) ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_93 = V_212 ;
V_8 -> V_24 &= ~ V_158 ;
F_124 ( & V_8 -> V_213 , 10 ) ;
F_57 ( V_108 ,
& V_8 -> V_109 ) ;
return;
}
V_8 -> V_90 = 0 ;
V_8 -> V_160 = V_161 ;
goto V_214;
}
if ( ( V_8 -> V_93 < V_215 ) ||
( V_8 -> V_24 & V_25 ) )
goto V_214;
V_207 = F_18 ( V_2 , V_216 ) & V_217 ;
if ( ! ( V_8 -> V_24 & V_25 ) && ! V_207 ) {
V_8 -> V_93 = V_159 ;
V_8 -> V_24 |= V_25 ;
F_43 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_13 ( & V_8 -> V_27 ) ;
V_8 -> V_90 = 0 ;
V_8 -> V_160 = V_161 ;
goto V_214;
}
if ( V_8 -> V_160 ) {
if ( ! F_125 ( V_2 ) ) {
F_126 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_127 ( V_8 ) ;
}
goto V_214;
}
if ( V_8 -> V_90 & V_218 ) {
F_128 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_162 ) {
F_129 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_91 ) {
F_130 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_124 ) {
F_131 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_115 ) {
F_132 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_134 ) {
F_133 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_116 ) {
F_134 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_152 ) {
F_135 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_154 ) {
F_136 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_219 ) {
F_110 ( V_8 ) ;
V_8 -> V_90 &= ~ V_219 ;
goto V_214;
}
if ( V_8 -> V_90 & V_220 ) {
F_137 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_221 ) {
F_138 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_191 ) {
F_139 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_190 ) {
F_140 ( V_8 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_144 ) {
F_141 ( V_8 , V_222 |
V_223 ) ;
goto V_214;
}
if ( V_8 -> V_90 & V_148 ) {
F_141 ( V_8 , V_223 ) ;
goto V_214;
}
if ( ( V_8 -> V_90 & V_145 ) &&
( V_8 -> V_90 & V_149 ) ) {
F_141 ( V_8 , 0 ) ;
goto V_214;
}
if ( V_8 -> V_93 == V_153 )
F_142 ( V_8 ) ;
V_214:
if ( V_8 -> V_93 == V_153 ) {
F_23 ( V_8 , ~ 0 ) ;
F_25 ( V_8 , 0xFF ) ;
} else {
F_25 ( V_8 , 0x1 ) ;
}
F_57 ( V_108 , & V_8 -> V_109 ) ;
V_208:
if ( V_8 -> V_93 == V_224 )
return;
if ( V_8 -> V_90 )
F_143 ( & V_8 -> V_155 ,
V_156 + F_144 ( 20 ) ) ;
else
F_143 ( & V_8 -> V_155 , V_156 + ( V_225 * 2 ) ) ;
F_13 ( & V_8 -> V_52 ) ;
}
static void F_145 ( struct V_205 * V_206 )
{
struct V_7 * V_8 = F_123 ( V_206 ,
struct V_7 ,
V_27 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_105 * V_226 ;
struct V_121 * V_107 ;
T_3 V_207 ;
int V_39 = 0 , V_87 ;
while ( F_53 ( V_108 ,
& V_8 -> V_109 ) )
F_84 ( 500 , 1000 ) ;
F_16 ( V_8 ) ;
if ( V_8 -> V_24 & V_26 ) {
V_8 -> V_24 &= ~ V_26 ;
F_146 ( V_2 ) ;
F_147 ( V_2 ) ;
F_148 ( V_8 ) ;
}
V_8 -> V_24 |= V_25 ;
for ( V_39 = 0 ; V_39 < V_227 ; V_39 ++ ) {
V_207 = F_18 ( V_2 , V_216 ) &
V_217 ;
if ( ! V_207 )
break;
F_84 ( 5000 , 10000 ) ;
}
if ( V_39 == V_227 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
goto V_228;
}
for ( V_39 = 0 ; V_39 < V_227 ; V_39 ++ ) {
V_207 = F_18 ( V_2 , V_32 ) &
V_209 ;
if ( V_207 == V_210 )
break;
F_149 ( V_229 ) ;
}
F_150 ( V_8 -> V_12 ) ;
F_149 ( V_229 ) ;
if ( V_39 == V_227 ) {
struct V_121 * V_135 ;
struct V_105 * V_230 , * V_231 ;
F_43 ( & V_8 -> V_12 -> V_13 , L_24 ,
V_207 ) ;
V_8 -> V_24 |= V_158 ;
if ( F_151 ( V_8 -> V_29 ) ) {
F_152 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_85 ( V_29 ) ;
F_86 ( V_29 ) ;
F_76 ( V_8 ) ;
F_21 ( V_8 ) ;
F_44 ( V_8 ) ;
F_153 ( V_8 ) ;
F_154 ( V_8 ) ;
}
F_72 (f, ftmp, &adapter->mac_filter_list,
list) {
F_155 ( & V_107 -> V_112 ) ;
F_9 ( V_107 ) ;
}
F_72 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_155 ( & V_230 -> V_112 ) ;
F_9 ( V_230 ) ;
}
F_45 ( V_8 ) ;
F_117 ( V_8 ) ;
F_89 ( V_8 ) ;
F_115 ( V_8 ) ;
F_9 ( V_8 -> V_175 ) ;
F_146 ( V_2 ) ;
V_8 -> V_29 -> V_24 &= ~ V_232 ;
F_57 ( V_108 , & V_8 -> V_109 ) ;
V_8 -> V_24 &= ~ V_25 ;
V_8 -> V_93 = V_215 ;
F_38 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
return;
}
V_228:
if ( F_151 ( V_8 -> V_29 ) ) {
F_85 ( V_29 ) ;
F_156 ( V_29 ) ;
F_76 ( V_8 ) ;
}
F_21 ( V_8 ) ;
V_8 -> V_93 = V_159 ;
V_8 -> V_24 &= ~ V_25 ;
F_154 ( V_8 ) ;
F_153 ( V_8 ) ;
if ( F_146 ( V_2 ) )
F_157 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
V_8 -> V_160 = V_161 ;
V_87 = F_147 ( V_2 ) ;
if ( V_87 )
F_38 ( & V_8 -> V_12 -> V_13 , L_27 ,
V_87 ) ;
V_8 -> V_90 = V_218 ;
V_8 -> V_90 |= V_91 ;
F_51 (f, &adapter->mac_filter_list, list) {
V_107 -> V_114 = true ;
}
F_51 (vlf, &adapter->vlan_filter_list, list) {
V_226 -> V_114 = true ;
}
V_8 -> V_90 |= V_124 ;
V_8 -> V_90 |= V_115 ;
F_57 ( V_108 , & V_8 -> V_109 ) ;
F_20 ( V_8 ) ;
F_143 ( & V_8 -> V_155 , V_156 + 2 ) ;
if ( F_151 ( V_8 -> V_29 ) ) {
V_87 = F_158 ( V_8 ) ;
if ( V_87 )
goto V_233;
V_87 = F_159 ( V_8 ) ;
if ( V_87 )
goto V_233;
F_78 ( V_8 ) ;
V_87 = F_81 ( V_8 ) ;
if ( V_87 )
goto V_233;
F_26 ( V_8 , true ) ;
} else {
V_8 -> V_93 = V_215 ;
}
return;
V_233:
F_43 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
F_160 ( V_8 -> V_29 ) ;
}
static void F_161 ( struct V_205 * V_206 )
{
struct V_7 * V_8 =
F_123 ( V_206 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_234 V_235 ;
struct V_236 * V_237 ;
T_1 V_181 ;
T_3 V_49 , V_238 ;
T_6 V_239 ;
if ( V_8 -> V_24 & V_158 )
goto V_89;
V_235 . V_240 = V_241 ;
V_235 . V_242 = F_7 ( V_235 . V_240 , V_16 ) ;
if ( ! V_235 . V_242 )
goto V_89;
V_237 = (struct V_236 * ) & V_235 . V_243 ;
do {
V_181 = F_162 ( V_2 , & V_235 , & V_239 ) ;
if ( V_181 || ! V_237 -> V_244 )
break;
F_163 ( V_8 , V_237 -> V_244 ,
V_237 -> V_245 , V_235 . V_242 ,
V_235 . V_246 ) ;
if ( V_239 != 0 )
memset ( V_235 . V_242 , 0 , V_241 ) ;
} while ( V_239 );
if ( ( V_8 -> V_24 &
( V_25 | V_26 ) ) ||
V_8 -> V_93 == V_159 )
goto V_247;
V_49 = F_18 ( V_2 , V_2 -> V_184 . V_248 . V_249 ) ;
if ( V_49 == 0xdeadbeef )
goto V_247;
V_238 = V_49 ;
if ( V_49 & V_250 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_250 ;
}
if ( V_49 & V_251 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_251 ;
}
if ( V_49 & V_252 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_252 ;
}
if ( V_238 != V_49 )
F_17 ( V_2 , V_2 -> V_184 . V_248 . V_249 , V_49 ) ;
V_49 = F_18 ( V_2 , V_2 -> V_184 . V_253 . V_249 ) ;
V_238 = V_49 ;
if ( V_49 & V_254 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_254 ;
}
if ( V_49 & V_255 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_255 ;
}
if ( V_49 & V_256 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_34 ) ;
V_49 &= ~ V_256 ;
}
if ( V_238 != V_49 )
F_17 ( V_2 , V_2 -> V_184 . V_253 . V_249 , V_49 ) ;
V_247:
F_9 ( V_235 . V_242 ) ;
V_89:
F_20 ( V_8 ) ;
}
void F_153 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_75 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_75 [ V_39 ] . V_243 )
F_164 ( & V_8 -> V_75 [ V_39 ] ) ;
}
static int F_158 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_75 [ V_39 ] . V_68 = V_8 -> V_169 ;
V_87 = F_165 ( & V_8 -> V_75 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_43 ( & V_8 -> V_12 -> V_13 ,
L_35 , V_39 ) ;
break;
}
return V_87 ;
}
static int F_159 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_68 = V_8 -> V_172 ;
V_87 = F_166 ( & V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_43 ( & V_8 -> V_12 -> V_13 ,
L_36 , V_39 ) ;
break;
}
return V_87 ;
}
void F_154 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_65 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] . V_243 )
F_167 ( & V_8 -> V_65 [ V_39 ] ) ;
}
static int F_168 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_87 ;
if ( V_8 -> V_24 & V_158 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_37 ) ;
return - V_119 ;
}
if ( V_8 -> V_93 != V_215 )
return - V_182 ;
V_87 = F_158 ( V_8 ) ;
if ( V_87 )
goto V_257;
V_87 = F_159 ( V_8 ) ;
if ( V_87 )
goto V_258;
V_87 = F_36 ( V_8 , V_29 -> V_97 ) ;
if ( V_87 )
goto V_259;
F_64 ( V_8 , V_8 -> V_2 . V_133 . V_127 ) ;
F_78 ( V_8 ) ;
V_87 = F_81 ( V_8 ) ;
if ( V_87 )
goto V_259;
F_26 ( V_8 , true ) ;
return 0 ;
V_259:
F_83 ( V_8 ) ;
F_44 ( V_8 ) ;
V_258:
F_154 ( V_8 ) ;
V_257:
F_153 ( V_8 ) ;
return V_87 ;
}
static int F_160 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( V_8 -> V_93 <= V_157 )
return 0 ;
F_152 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_83 ( V_8 ) ;
V_8 -> V_93 = V_157 ;
F_44 ( V_8 ) ;
return 0 ;
}
static struct V_260 * F_169 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
return & V_8 -> V_261 ;
}
static int F_170 ( struct V_28 * V_29 , int V_262 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_263 = V_262 + V_264 + V_265 ;
if ( ( V_262 < 68 ) || ( V_263 > V_266 ) )
return - V_267 ;
V_29 -> V_268 = V_262 ;
V_8 -> V_24 |= V_26 ;
F_13 ( & V_8 -> V_27 ) ;
return 0 ;
}
static T_10 F_171 ( struct V_28 * V_29 ,
T_10 V_269 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_269 &= ~ V_270 ;
if ( V_8 -> V_175 -> V_192 & V_271 )
V_269 |= V_270 ;
return V_269 ;
}
static int F_172 ( struct V_1 * V_2 )
{
T_3 V_272 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_272 = F_18 ( V_2 , V_32 ) &
V_209 ;
if ( ( V_272 == V_210 ) ||
( V_272 == V_211 ) )
return 0 ;
F_84 ( 10 , 20 ) ;
}
return - V_182 ;
}
int F_173 ( struct V_7 * V_8 )
{
struct V_273 * V_274 = V_8 -> V_175 ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_275 * V_67 = & V_8 -> V_67 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_274 -> V_276 ; V_39 ++ ) {
if ( V_274 -> V_166 [ V_39 ] . V_277 == V_278 )
V_8 -> V_166 = & V_274 -> V_166 [ V_39 ] ;
}
if ( ! V_8 -> V_166 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_38 ) ;
return - V_279 ;
}
V_29 -> V_280 |= V_281 |
V_282 |
V_283 |
V_284 |
V_285 |
V_286 |
V_287 |
V_288 |
V_289 |
V_290 |
V_291 |
V_292 |
V_293 |
V_294 |
V_295 |
V_296 |
V_297 |
V_298 |
0 ;
if ( ! ( V_8 -> V_24 & V_299 ) )
V_29 -> V_300 |= V_294 ;
V_29 -> V_300 |= V_290 ;
V_29 -> V_301 |= V_29 -> V_280 |
V_302 ;
V_29 -> V_303 |= V_29 -> V_280 ;
V_29 -> V_269 |= V_29 -> V_280 | V_270 ;
V_29 -> V_280 |= V_302 ;
if ( ! ( V_274 -> V_192 & V_271 ) )
V_29 -> V_269 ^= V_270 ;
V_8 -> V_67 . V_183 = V_8 -> V_166 -> V_304 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_305 = 1 ;
V_8 -> V_67 . V_306 = V_307 ;
V_8 -> V_67 . V_308 = ( V_309 |
F_174 ( V_310 ) ) ;
V_8 -> V_67 . V_311 = ( V_309 |
F_174 ( V_312 ) ) ;
V_67 -> V_29 = V_8 -> V_29 ;
V_67 -> V_313 = V_8 -> V_166 -> V_314 ;
if ( V_274 -> V_192 & V_315 ) {
V_8 -> V_189 = V_274 -> V_189 ;
V_8 -> V_187 = V_274 -> V_187 ;
} else {
V_8 -> V_189 = V_316 ;
V_8 -> V_187 = V_317 ;
}
return 0 ;
}
static void F_175 ( struct V_205 * V_206 )
{
struct V_7 * V_8 = F_123 ( V_206 ,
struct V_7 ,
V_213 . V_206 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_318 * V_12 = V_8 -> V_12 ;
int V_87 , V_319 ;
switch ( V_8 -> V_93 ) {
case V_212 :
V_8 -> V_24 &= ~ V_158 ;
V_8 -> V_24 &= ~ V_25 ;
V_87 = F_176 ( V_2 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_39 ,
V_87 ) ;
goto V_87;
}
V_87 = F_172 ( V_2 ) ;
if ( V_87 ) {
F_38 ( & V_12 -> V_13 , L_40 ,
V_87 ) ;
goto V_87;
}
V_2 -> V_184 . V_320 = V_321 ;
V_2 -> V_184 . V_322 = V_321 ;
V_2 -> V_184 . V_323 = V_241 ;
V_2 -> V_184 . V_324 = V_241 ;
V_87 = F_147 ( V_2 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_41 ,
V_87 ) ;
goto V_87;
}
V_87 = F_127 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_42 , V_87 ) ;
F_146 ( V_2 ) ;
goto V_87;
}
V_8 -> V_93 = V_325 ;
goto V_326;
case V_325 :
if ( ! F_125 ( V_2 ) ) {
F_43 ( & V_12 -> V_13 , L_43 ) ;
F_146 ( V_2 ) ;
V_8 -> V_93 = V_212 ;
goto V_87;
}
V_87 = F_177 ( V_8 ) ;
if ( V_87 ) {
if ( V_87 == V_327 )
V_87 = F_127 ( V_8 ) ;
else
F_43 ( & V_12 -> V_13 , L_44 ,
V_8 -> V_328 . V_329 ,
V_8 -> V_328 . V_330 ,
V_331 ,
V_332 ) ;
goto V_87;
}
V_87 = F_128 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_45 ,
V_87 ) ;
goto V_87;
}
V_8 -> V_93 = V_333 ;
goto V_326;
case V_333 :
if ( ! V_8 -> V_175 ) {
V_319 = sizeof( struct V_273 ) +
( V_334 *
sizeof( struct V_335 ) ) ;
V_8 -> V_175 = F_7 ( V_319 , V_16 ) ;
if ( ! V_8 -> V_175 )
goto V_87;
}
V_87 = F_178 ( V_8 ) ;
if ( V_87 == V_327 ) {
V_87 = F_128 ( V_8 ) ;
goto V_87;
} else if ( V_87 == V_10 ) {
F_146 ( V_2 ) ;
F_43 ( & V_12 -> V_13 , L_46 ) ;
return;
}
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_47 ,
V_87 ) ;
goto V_336;
}
V_8 -> V_93 = V_337 ;
break;
default:
goto V_336;
}
if ( V_2 -> V_133 . type == V_338 )
V_8 -> V_24 |= V_299 ;
if ( F_173 ( V_8 ) )
goto V_336;
V_8 -> V_160 = V_161 ;
V_8 -> V_24 |= V_339 ;
V_29 -> V_340 = & V_341 ;
F_179 ( V_29 ) ;
V_29 -> V_342 = 5 * V_225 ;
if ( ! F_68 ( V_8 -> V_2 . V_133 . V_127 ) ) {
F_38 ( & V_12 -> V_13 , L_48 ,
V_8 -> V_2 . V_133 . V_127 ) ;
F_180 ( V_29 ) ;
F_65 ( V_8 -> V_2 . V_133 . V_127 , V_29 -> V_130 ) ;
} else {
V_8 -> V_24 |= V_131 ;
F_65 ( V_29 -> V_130 , V_8 -> V_2 . V_133 . V_127 ) ;
F_65 ( V_29 -> V_343 , V_8 -> V_2 . V_133 . V_127 ) ;
}
F_181 ( & V_8 -> V_155 ) ;
V_8 -> V_155 . V_344 = & F_121 ;
V_8 -> V_155 . V_48 = ( unsigned long ) V_8 ;
F_143 ( & V_8 -> V_155 , V_156 + 1 ) ;
V_8 -> V_82 = F_93 ( int ,
V_8 -> V_166 -> V_345 ,
( int ) ( F_94 () ) ) ;
V_8 -> V_169 = V_346 ;
V_8 -> V_172 = V_347 ;
V_87 = F_119 ( V_8 ) ;
if ( V_87 )
goto V_348;
F_32 ( V_8 ) ;
if ( V_8 -> V_175 -> V_192 &
V_349 )
V_8 -> V_24 |= V_350 ;
V_87 = F_41 ( V_8 ) ;
if ( V_87 )
goto V_348;
F_85 ( V_29 ) ;
if ( ! V_8 -> V_351 ) {
V_87 = F_182 ( V_29 ) ;
if ( V_87 )
goto V_352;
}
V_8 -> V_351 = true ;
F_156 ( V_29 ) ;
F_38 ( & V_12 -> V_13 , L_49 , V_8 -> V_2 . V_133 . V_127 ) ;
if ( V_29 -> V_269 & V_353 )
F_38 ( & V_12 -> V_13 , L_50 ) ;
V_8 -> V_93 = V_215 ;
F_152 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_20 ( V_8 ) ;
V_8 -> V_180 = F_7 ( V_8 -> V_189 , V_16 ) ;
V_8 -> V_186 = F_7 ( V_8 -> V_187 , V_16 ) ;
if ( ! V_8 -> V_180 || ! V_8 -> V_186 )
goto V_354;
if ( F_108 ( V_8 ) ) {
V_8 -> V_90 |= V_219 ;
F_82 ( & V_8 -> V_155 , V_156 + 1 ) ;
} else {
F_110 ( V_8 ) ;
}
return;
V_326:
F_124 ( & V_8 -> V_213 , F_144 ( 30 ) ) ;
return;
V_354:
F_120 ( V_8 ) ;
V_352:
F_45 ( V_8 ) ;
V_348:
F_117 ( V_8 ) ;
V_336:
F_9 ( V_8 -> V_175 ) ;
V_8 -> V_175 = NULL ;
V_87:
if ( ++ V_8 -> V_355 > V_356 ) {
F_43 ( & V_12 -> V_13 , L_51 ) ;
V_8 -> V_24 |= V_158 ;
F_146 ( V_2 ) ;
V_8 -> V_93 = V_212 ;
F_124 ( & V_8 -> V_213 , V_225 * 5 ) ;
return;
}
F_124 ( & V_8 -> V_213 , V_225 ) ;
}
static void F_183 ( struct V_318 * V_12 )
{
struct V_28 * V_29 = F_184 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
F_185 ( V_29 ) ;
if ( F_151 ( V_29 ) )
F_160 ( V_29 ) ;
V_8 -> V_93 = V_224 ;
V_8 -> V_90 = 0 ;
#ifdef F_186
F_187 ( V_12 ) ;
#endif
F_188 ( V_12 ) ;
}
static int F_189 ( struct V_318 * V_12 , const struct V_357 * V_358 )
{
struct V_28 * V_29 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_87 ;
V_87 = F_190 ( V_12 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_191 ( & V_12 -> V_13 , F_192 ( 64 ) ) ;
if ( V_87 ) {
V_87 = F_191 ( & V_12 -> V_13 , F_192 ( 32 ) ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 ,
L_52 , V_87 ) ;
goto V_359;
}
}
V_87 = F_193 ( V_12 , V_360 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 ,
L_53 , V_87 ) ;
goto V_361;
}
F_194 ( V_12 ) ;
F_150 ( V_12 ) ;
V_29 = F_195 ( sizeof( struct V_7 ) , V_362 ) ;
if ( ! V_29 ) {
V_87 = - V_120 ;
goto V_363;
}
F_196 ( V_29 , & V_12 -> V_13 ) ;
F_197 ( V_12 , V_29 ) ;
V_8 = F_15 ( V_29 ) ;
V_8 -> V_29 = V_29 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_364 = F_24 ( V_365 ) - 1 ;
V_8 -> V_93 = V_212 ;
F_187 ( V_12 ) ;
V_2 -> V_102 = F_198 ( F_199 ( V_12 , 0 ) ,
F_200 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_102 ) {
V_87 = - V_119 ;
goto V_366;
}
V_2 -> V_367 = V_12 -> V_368 ;
V_2 -> V_369 = V_12 -> V_370 ;
F_201 ( V_12 , V_371 , & V_2 -> V_372 ) ;
V_2 -> V_373 = V_12 -> V_374 ;
V_2 -> V_375 = V_12 -> V_376 ;
V_2 -> V_377 . V_370 = F_202 ( V_12 -> V_378 ) ;
V_2 -> V_377 . V_379 = F_203 ( V_12 -> V_378 ) ;
F_204 ( & V_2 -> V_184 . V_380 ) ;
F_204 ( & V_2 -> V_184 . V_381 ) ;
F_55 ( & V_8 -> V_123 ) ;
F_55 ( & V_8 -> V_113 ) ;
F_205 ( & V_8 -> V_27 , F_145 ) ;
F_205 ( & V_8 -> V_52 , F_161 ) ;
F_205 ( & V_8 -> V_204 , F_122 ) ;
F_206 ( & V_8 -> V_213 , F_175 ) ;
F_124 ( & V_8 -> V_213 ,
F_144 ( 5 * ( V_12 -> V_378 & 0x07 ) ) ) ;
return 0 ;
V_366:
F_207 ( V_29 ) ;
V_363:
F_208 ( V_12 ) ;
V_361:
V_359:
F_188 ( V_12 ) ;
return V_87 ;
}
static int F_209 ( struct V_318 * V_12 , T_11 V_93 )
{
struct V_28 * V_29 = F_184 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_382 = 0 ;
F_185 ( V_29 ) ;
if ( F_151 ( V_29 ) ) {
F_210 () ;
F_83 ( V_8 ) ;
F_211 () ;
}
F_45 ( V_8 ) ;
F_117 ( V_8 ) ;
V_382 = F_187 ( V_12 ) ;
if ( V_382 )
return V_382 ;
F_188 ( V_12 ) ;
return 0 ;
}
static int F_212 ( struct V_318 * V_12 )
{
struct V_7 * V_8 = F_184 ( V_12 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
T_3 V_87 ;
F_213 ( V_12 , V_383 ) ;
F_214 ( V_12 ) ;
F_187 ( V_12 ) ;
V_87 = F_215 ( V_12 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_54 ) ;
return V_87 ;
}
F_150 ( V_12 ) ;
F_210 () ;
V_87 = F_92 ( V_8 ) ;
if ( V_87 ) {
F_211 () ;
F_43 ( & V_12 -> V_13 , L_55 ) ;
return V_87 ;
}
V_87 = F_41 ( V_8 ) ;
F_211 () ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_56 ) ;
return V_87 ;
}
F_13 ( & V_8 -> V_27 ) ;
F_216 ( V_29 ) ;
return V_87 ;
}
static void F_217 ( struct V_318 * V_12 )
{
struct V_28 * V_29 = F_184 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_121 * V_107 , * V_135 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_218 ( & V_8 -> V_213 ) ;
F_219 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_351 ) {
F_220 ( V_29 ) ;
V_8 -> V_351 = false ;
}
V_8 -> V_93 = V_224 ;
V_8 -> V_90 = 0 ;
F_148 ( V_8 ) ;
F_149 ( 50 ) ;
if ( ! F_125 ( V_2 ) ) {
F_148 ( V_8 ) ;
F_149 ( 50 ) ;
}
if ( V_8 -> V_33 ) {
F_16 ( V_8 ) ;
F_45 ( V_8 ) ;
F_117 ( V_8 ) ;
F_115 ( V_8 ) ;
}
if ( V_8 -> V_155 . V_344 )
F_221 ( & V_8 -> V_155 ) ;
F_222 () ;
F_120 ( V_8 ) ;
if ( V_2 -> V_184 . V_253 . V_68 )
F_146 ( V_2 ) ;
F_223 ( & V_2 -> V_184 . V_381 ) ;
F_223 ( & V_2 -> V_184 . V_380 ) ;
F_224 ( V_2 -> V_102 ) ;
F_208 ( V_12 ) ;
F_153 ( V_8 ) ;
F_154 ( V_8 ) ;
F_89 ( V_8 ) ;
F_9 ( V_8 -> V_175 ) ;
F_72 (f, ftmp, &adapter->mac_filter_list, list) {
F_155 ( & V_107 -> V_112 ) ;
F_9 ( V_107 ) ;
}
F_72 (f, ftmp, &adapter->vlan_filter_list, list) {
F_155 ( & V_107 -> V_112 ) ;
F_9 ( V_107 ) ;
}
F_207 ( V_29 ) ;
F_225 ( V_12 ) ;
F_188 ( V_12 ) ;
}
static int T_12 F_226 ( void )
{
int V_181 ;
F_11 ( L_57 , V_384 ,
V_385 ) ;
F_11 ( L_58 , V_386 ) ;
V_387 = F_227 ( V_360 ) ;
if ( ! V_387 ) {
F_228 ( L_59 , V_360 ) ;
return - V_120 ;
}
V_181 = F_229 ( & V_388 ) ;
return V_181 ;
}
static void T_13 F_230 ( void )
{
F_231 ( & V_388 ) ;
F_232 ( V_387 ) ;
}
