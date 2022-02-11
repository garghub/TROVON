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
struct V_28 * V_29 = V_8 -> V_29 ;
int V_103 = V_29 -> V_104 + V_105 + V_106 ;
int V_39 ;
int V_107 ;
if ( V_8 -> V_24 & V_108 ||
V_29 -> V_104 <= V_109 )
V_107 = V_110 ;
else
V_107 = F_2 ( V_103 , 1024 ) ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_101 = V_2 -> V_102 + F_49 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] . V_107 = V_107 ;
if ( V_8 -> V_24 & V_108 ) {
F_50 ( & V_8 -> V_65 [ V_39 ] ) ;
V_8 -> V_65 [ V_39 ] . V_111 = V_112 ;
} else {
F_51 ( & V_8 -> V_65 [ V_39 ] ) ;
}
}
}
static struct
V_113 * F_52 ( struct V_7 * V_8 , T_6 V_114 )
{
struct V_113 * V_115 ;
F_53 (f, &adapter->vlan_filter_list, list) {
if ( V_114 == V_115 -> V_114 )
return V_115 ;
}
return NULL ;
}
static struct
V_113 * F_54 ( struct V_7 * V_8 , T_6 V_114 )
{
struct V_113 * V_115 = NULL ;
int V_68 = 50 ;
while ( F_55 ( V_116 ,
& V_8 -> V_117 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_89;
}
V_115 = F_52 ( V_8 , V_114 ) ;
if ( ! V_115 ) {
V_115 = F_7 ( sizeof( * V_115 ) , V_118 ) ;
if ( ! V_115 )
goto V_119;
V_115 -> V_114 = V_114 ;
F_57 ( & V_115 -> V_120 ) ;
F_58 ( & V_115 -> V_120 , & V_8 -> V_121 ) ;
V_115 -> V_122 = true ;
V_8 -> V_90 |= V_123 ;
}
V_119:
F_59 ( V_116 , & V_8 -> V_117 ) ;
V_89:
return V_115 ;
}
static void F_60 ( struct V_7 * V_8 , T_6 V_114 )
{
struct V_113 * V_115 ;
int V_68 = 50 ;
while ( F_55 ( V_116 ,
& V_8 -> V_117 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_115 = F_52 ( V_8 , V_114 ) ;
if ( V_115 ) {
V_115 -> remove = true ;
V_8 -> V_90 |= V_124 ;
}
F_59 ( V_116 , & V_8 -> V_117 ) ;
}
static int F_61 ( struct V_28 * V_29 ,
T_7 T_8 V_125 , T_6 V_126 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( ! F_62 ( V_8 ) )
return - V_127 ;
if ( F_54 ( V_8 , V_126 ) == NULL )
return - V_128 ;
return 0 ;
}
static int F_63 ( struct V_28 * V_29 ,
T_7 T_8 V_125 , T_6 V_126 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( F_62 ( V_8 ) ) {
F_60 ( V_8 , V_126 ) ;
return 0 ;
}
return - V_127 ;
}
static struct
V_129 * F_64 ( struct V_7 * V_8 ,
T_9 * V_130 )
{
struct V_129 * V_115 ;
if ( ! V_130 )
return NULL ;
F_53 (f, &adapter->mac_filter_list, list) {
if ( F_65 ( V_130 , V_115 -> V_130 ) )
return V_115 ;
}
return NULL ;
}
static struct
V_129 * F_66 ( struct V_7 * V_8 ,
T_9 * V_130 )
{
struct V_129 * V_115 ;
int V_68 = 50 ;
if ( ! V_130 )
return NULL ;
while ( F_55 ( V_116 ,
& V_8 -> V_117 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_115 = F_64 ( V_8 , V_130 ) ;
if ( ! V_115 ) {
V_115 = F_7 ( sizeof( * V_115 ) , V_118 ) ;
if ( ! V_115 ) {
F_59 ( V_116 ,
& V_8 -> V_117 ) ;
return NULL ;
}
F_67 ( V_115 -> V_130 , V_130 ) ;
F_58 ( & V_115 -> V_120 , & V_8 -> V_131 ) ;
V_115 -> V_122 = true ;
V_8 -> V_90 |= V_132 ;
}
F_59 ( V_116 , & V_8 -> V_117 ) ;
return V_115 ;
}
static int F_68 ( struct V_28 * V_29 , void * V_133 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_129 * V_115 ;
struct V_134 * V_135 = V_133 ;
if ( ! F_69 ( V_135 -> V_136 ) )
return - V_137 ;
if ( F_65 ( V_29 -> V_138 , V_135 -> V_136 ) )
return 0 ;
if ( V_8 -> V_24 & V_139 )
return - V_140 ;
V_115 = F_64 ( V_8 , V_2 -> V_141 . V_135 ) ;
if ( V_115 ) {
V_115 -> remove = true ;
V_8 -> V_90 |= V_142 ;
}
V_115 = F_66 ( V_8 , V_135 -> V_136 ) ;
if ( V_115 ) {
F_67 ( V_2 -> V_141 . V_135 , V_135 -> V_136 ) ;
F_67 ( V_29 -> V_138 , V_8 -> V_2 . V_141 . V_135 ) ;
}
return ( V_115 == NULL ) ? - V_128 : 0 ;
}
static void F_70 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_129 * V_115 , * V_143 ;
struct V_144 * V_145 ;
struct V_144 * V_146 ;
struct V_144 * V_147 ;
int V_68 = 50 ;
F_71 (uca, netdev) {
F_66 ( V_8 , V_145 -> V_135 ) ;
}
F_72 (mca, netdev) {
F_66 ( V_8 , V_146 -> V_135 ) ;
}
while ( F_55 ( V_116 ,
& V_8 -> V_117 ) ) {
F_56 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_148 ) ;
return;
}
}
F_73 (f, ftmp, &adapter->mac_filter_list, list) {
F_72 (mca, netdev)
if ( F_65 ( V_146 -> V_135 , V_115 -> V_130 ) )
goto V_149;
F_71 (uca, netdev)
if ( F_65 ( V_145 -> V_135 , V_115 -> V_130 ) )
goto V_149;
F_74 (netdev, ha)
if ( F_65 ( V_147 -> V_135 , V_115 -> V_130 ) )
goto V_149;
if ( F_65 ( V_115 -> V_130 , V_8 -> V_2 . V_141 . V_135 ) )
goto V_149;
V_115 -> remove = true ;
V_8 -> V_90 |= V_142 ;
V_149:
continue;
}
F_59 ( V_116 , & V_8 -> V_117 ) ;
}
static void F_75 ( struct V_7 * V_8 )
{
int V_150 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_88 ;
for ( V_150 = 0 ; V_150 < V_62 ; V_150 ++ ) {
struct V_151 * V_59 ;
V_55 = & V_8 -> V_62 [ V_150 ] ;
V_59 = & V_55 -> V_59 ;
F_76 ( V_59 ) ;
}
}
static void F_77 ( struct V_7 * V_8 )
{
int V_150 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_88 ;
for ( V_150 = 0 ; V_150 < V_62 ; V_150 ++ ) {
V_55 = & V_8 -> V_62 [ V_150 ] ;
F_78 ( & V_55 -> V_59 ) ;
}
}
static void F_79 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_39 ;
F_70 ( V_29 ) ;
F_46 ( V_8 ) ;
F_48 ( V_8 ) ;
V_8 -> V_90 |= V_152 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_63 * V_57 = & V_8 -> V_65 [ V_39 ] ;
if ( V_8 -> V_24 & V_108 ) {
F_80 ( V_57 ) ;
F_81 ( V_57 , V_57 -> V_68 ) ;
} else {
F_82 ( V_57 , V_57 -> V_68 ) ;
}
V_57 -> V_153 = V_57 -> V_68 - 1 ;
F_83 ( V_57 -> V_153 , V_57 -> V_101 ) ;
}
}
static int F_84 ( struct V_7 * V_8 )
{
V_8 -> V_93 = V_154 ;
F_59 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_75 ( V_8 ) ;
V_8 -> V_90 |= V_155 ;
F_85 ( & V_8 -> V_156 , V_157 + 1 ) ;
return 0 ;
}
void F_86 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_129 * V_115 ;
if ( V_8 -> V_93 <= V_158 )
return;
while ( F_55 ( V_116 ,
& V_8 -> V_117 ) )
F_87 ( 500 , 1000 ) ;
F_88 ( V_29 ) ;
F_89 ( V_29 ) ;
F_77 ( V_8 ) ;
F_21 ( V_8 ) ;
F_53 (f, &adapter->mac_filter_list, list) {
V_115 -> remove = true ;
}
F_53 (f, &adapter->vlan_filter_list, list) {
V_115 -> remove = true ;
}
if ( ! ( V_8 -> V_24 & V_159 ) &&
V_8 -> V_93 != V_160 ) {
V_8 -> V_161 = V_162 ;
V_8 -> V_90 = V_142 ;
V_8 -> V_90 |= V_124 ;
V_8 -> V_90 |= V_163 ;
}
F_59 ( V_116 , & V_8 -> V_117 ) ;
}
static int
F_90 ( struct V_7 * V_8 , int V_164 )
{
int V_87 , V_165 ;
V_165 = V_166 ;
V_87 = F_91 ( V_8 -> V_12 , V_8 -> V_33 ,
V_165 , V_164 ) ;
if ( V_87 < 0 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_87 ;
}
V_8 -> V_40 = V_87 ;
return 0 ;
}
static void F_92 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_167 )
return;
F_9 ( V_8 -> V_75 ) ;
V_8 -> V_75 = NULL ;
F_9 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
}
static int F_93 ( struct V_7 * V_8 )
{
int V_39 ;
V_8 -> V_75 = F_94 ( V_8 -> V_82 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_75 )
goto V_168;
V_8 -> V_65 = F_94 ( V_8 -> V_82 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_65 )
goto V_168;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_63 * V_74 ;
struct V_63 * V_64 ;
V_74 = & V_8 -> V_75 [ V_39 ] ;
V_74 -> V_169 = V_39 ;
V_74 -> V_29 = V_8 -> V_29 ;
V_74 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_74 -> V_68 = V_8 -> V_170 ;
if ( V_8 -> V_24 & V_171 )
V_74 -> V_24 |= V_172 ;
V_64 = & V_8 -> V_65 [ V_39 ] ;
V_64 -> V_169 = V_39 ;
V_64 -> V_29 = V_8 -> V_29 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_173 ;
}
return 0 ;
V_168:
F_92 ( V_8 ) ;
return - V_128 ;
}
static int F_95 ( struct V_7 * V_8 )
{
int V_34 , V_174 ;
int V_175 = 0 ;
int V_87 = 0 ;
if ( ! V_8 -> V_167 ) {
V_87 = - V_127 ;
goto V_89;
}
V_175 = V_8 -> V_82 ;
V_174 = F_96 ( int , V_175 , ( int ) ( F_97 () * 2 ) ) + V_88 ;
V_174 = F_96 ( int , V_174 , ( int ) V_8 -> V_176 -> V_177 ) ;
V_8 -> V_33 = F_94 ( V_174 ,
sizeof( struct V_178 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_87 = - V_128 ;
goto V_89;
}
for ( V_34 = 0 ; V_34 < V_174 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_179 = V_34 ;
V_87 = F_90 ( V_8 , V_174 ) ;
V_89:
F_98 ( V_8 -> V_29 , V_175 ) ;
F_99 ( V_8 -> V_29 , V_175 ) ;
return V_87 ;
}
static int F_100 ( struct V_180 * V_67 , const T_9 * V_181 ,
T_9 * V_182 , T_6 V_183 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_184 = 0 ;
if ( ! V_67 -> V_185 )
return - V_186 ;
if ( V_8 -> V_161 != V_162 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_161 ) ;
return - V_187 ;
}
if ( V_181 ) {
struct V_188 * V_189 =
(struct V_188 * ) V_181 ;
V_184 = F_101 ( V_2 , V_67 -> V_185 , V_189 ) ;
if ( V_184 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_12 ,
F_102 ( V_2 , V_184 ) ,
F_103 ( V_2 , V_2 -> V_190 . V_191 ) ) ;
return V_184 ;
}
}
if ( V_182 ) {
V_184 = F_104 ( V_2 , V_67 -> V_185 , false , V_182 , V_183 ) ;
if ( V_184 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_13 ,
F_102 ( V_2 , V_184 ) ,
F_103 ( V_2 , V_2 -> V_190 . V_191 ) ) ;
return V_184 ;
}
}
return V_184 ;
}
static int F_105 ( struct V_180 * V_67 , const T_9 * V_181 ,
const T_9 * V_182 , T_6 V_183 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_6 V_39 ;
if ( V_181 ) {
T_3 * V_192 = ( T_3 * ) V_181 ;
for ( V_39 = 0 ; V_39 <= V_193 ; V_39 ++ )
F_17 ( V_2 , F_106 ( V_39 ) , V_192 [ V_39 ] ) ;
}
if ( V_182 ) {
T_3 * V_194 = ( T_3 * ) V_182 ;
if ( V_183 != V_195 )
return - V_186 ;
for ( V_39 = 0 ; V_39 <= V_196 ; V_39 ++ )
F_17 ( V_2 , F_107 ( V_39 ) , V_194 [ V_39 ] ) ;
}
F_108 ( V_2 ) ;
return 0 ;
}
static int F_109 ( struct V_180 * V_67 , const T_9 * V_181 ,
T_9 * V_182 , T_6 V_183 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_184 = 0 ;
if ( V_181 ) {
V_184 = F_110 ( V_2 , V_67 -> V_185 ,
(struct V_188 * ) V_181 ) ;
if ( V_184 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_14 ,
F_102 ( V_2 , V_184 ) ,
F_103 ( V_2 , V_2 -> V_190 . V_191 ) ) ;
return V_184 ;
}
}
if ( V_182 ) {
V_184 = F_111 ( V_2 , V_67 -> V_185 , V_181 , V_182 , V_183 ) ;
if ( V_184 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_15 ,
F_102 ( V_2 , V_184 ) ,
F_103 ( V_2 , V_2 -> V_190 . V_191 ) ) ;
return V_184 ;
}
}
return V_184 ;
}
static int F_112 ( struct V_180 * V_67 , const T_9 * V_181 ,
const T_9 * V_182 , T_6 V_183 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_6 V_39 ;
if ( V_181 ) {
T_3 * V_192 = ( T_3 * ) V_181 ;
for ( V_39 = 0 ; V_39 <= V_193 ; V_39 ++ )
V_192 [ V_39 ] = F_18 ( V_2 , F_106 ( V_39 ) ) ;
}
if ( V_182 ) {
T_3 * V_194 = ( T_3 * ) V_182 ;
if ( V_183 != V_195 )
return - V_186 ;
for ( V_39 = 0 ; V_39 <= V_196 ; V_39 ++ )
V_194 [ V_39 ] = F_18 ( V_2 , F_107 ( V_39 ) ) ;
}
return 0 ;
}
int F_113 ( struct V_180 * V_67 , const T_9 * V_181 ,
T_9 * V_182 , T_6 V_183 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
if ( F_114 ( V_8 ) )
return F_100 ( V_67 , V_181 , V_182 , V_183 ) ;
else
return F_105 ( V_67 , V_181 , V_182 , V_183 ) ;
}
int F_115 ( struct V_180 * V_67 , const T_9 * V_181 , T_9 * V_182 , T_6 V_183 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
if ( F_114 ( V_8 ) )
return F_109 ( V_67 , V_181 , V_182 , V_183 ) ;
else
return F_112 ( V_67 , V_181 , V_182 , V_183 ) ;
}
static void F_116 ( T_9 * V_182 , T_6 V_197 , T_6 V_198 )
{
T_6 V_39 ;
for ( V_39 = 0 ; V_39 < V_197 ; V_39 ++ )
V_182 [ V_39 ] = V_39 % V_198 ;
}
static int F_117 ( struct V_7 * V_8 )
{
struct V_180 * V_67 = & V_8 -> V_67 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_9 V_181 [ V_199 ] ;
T_2 V_200 ;
T_9 * V_182 ;
int V_184 ;
if ( V_8 -> V_176 -> V_201 &
V_202 )
V_200 = V_203 ;
else
V_200 = V_204 ;
F_17 ( V_2 , F_118 ( 0 ) , ( T_3 ) V_200 ) ;
F_17 ( V_2 , F_118 ( 1 ) , ( T_3 ) ( V_200 >> 32 ) ) ;
V_182 = F_7 ( V_195 , V_16 ) ;
if ( ! V_182 )
return - V_128 ;
if ( V_67 -> V_205 )
memcpy ( V_182 , V_67 -> V_205 , V_195 ) ;
else
F_116 ( V_182 , V_195 ,
V_8 -> V_82 ) ;
if ( V_67 -> V_206 )
memcpy ( V_181 , V_67 -> V_206 , V_199 ) ;
else
F_119 ( ( void * ) V_181 , V_199 ) ;
V_184 = F_113 ( V_67 , V_181 , V_182 , V_195 ) ;
F_9 ( V_182 ) ;
return V_184 ;
}
static int F_120 ( struct V_7 * V_8 )
{
int V_150 = 0 , V_207 ;
struct V_54 * V_55 ;
V_207 = V_8 -> V_40 - V_88 ;
V_8 -> V_62 = F_94 ( V_207 , sizeof( * V_55 ) ,
V_16 ) ;
if ( ! V_8 -> V_62 )
goto V_168;
for ( V_150 = 0 ; V_150 < V_207 ; V_150 ++ ) {
V_55 = & V_8 -> V_62 [ V_150 ] ;
V_55 -> V_8 = V_8 ;
V_55 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_60 = V_150 ;
F_121 ( V_8 -> V_29 , & V_55 -> V_59 ,
V_208 , V_209 ) ;
}
return 0 ;
V_168:
while ( V_150 ) {
V_150 -- ;
V_55 = & V_8 -> V_62 [ V_150 ] ;
F_122 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
return - V_128 ;
}
static void F_123 ( struct V_7 * V_8 )
{
int V_150 , V_207 ;
int V_210 ;
V_207 = V_8 -> V_40 - V_88 ;
V_210 = V_8 -> V_82 ;
for ( V_150 = 0 ; V_150 < V_207 ; V_150 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_150 ] ;
if ( V_150 < V_210 )
F_122 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
}
void F_124 ( struct V_7 * V_8 )
{
F_125 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_126 ( struct V_7 * V_8 )
{
int V_87 ;
V_87 = F_95 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_211;
}
V_87 = F_120 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_17 ) ;
goto V_212;
}
V_87 = F_93 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_8 -> V_12 -> V_13 ,
L_18 ) ;
goto V_213;
}
F_38 ( & V_8 -> V_12 -> V_13 , L_19 ,
( V_8 -> V_82 > 1 ) ? L_20 : L_21 ,
V_8 -> V_82 ) ;
return 0 ;
V_213:
F_123 ( V_8 ) ;
V_212:
F_124 ( V_8 ) ;
V_211:
return V_87 ;
}
static void F_127 ( struct V_180 * V_67 )
{
if ( ! V_67 )
return;
F_9 ( V_67 -> V_206 ) ;
V_67 -> V_206 = NULL ;
F_9 ( V_67 -> V_205 ) ;
V_67 -> V_205 = NULL ;
}
static void F_128 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_13 ( & V_8 -> V_214 ) ;
}
static void F_129 ( struct V_215 * V_216 )
{
struct V_7 * V_8 = F_130 ( V_216 ,
struct V_7 ,
V_214 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_217 ;
if ( F_55 ( V_116 , & V_8 -> V_117 ) )
goto V_218;
if ( V_8 -> V_24 & V_159 ) {
V_217 = F_18 ( V_2 , V_32 ) &
V_219 ;
if ( ( V_217 == V_220 ) ||
( V_217 == V_221 ) ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
V_8 -> V_93 = V_222 ;
V_8 -> V_24 &= ~ V_159 ;
F_131 ( & V_8 -> V_223 , 10 ) ;
F_59 ( V_116 ,
& V_8 -> V_117 ) ;
return;
}
V_8 -> V_90 = 0 ;
V_8 -> V_161 = V_162 ;
goto V_224;
}
if ( ( V_8 -> V_93 < V_225 ) ||
( V_8 -> V_24 & V_25 ) )
goto V_224;
V_217 = F_18 ( V_2 , V_226 ) & V_227 ;
if ( ! ( V_8 -> V_24 & V_25 ) && ! V_217 ) {
V_8 -> V_93 = V_160 ;
V_8 -> V_24 |= V_25 ;
F_43 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
F_13 ( & V_8 -> V_27 ) ;
V_8 -> V_90 = 0 ;
V_8 -> V_161 = V_162 ;
goto V_224;
}
if ( V_8 -> V_161 ) {
if ( ! F_132 ( V_2 ) ) {
F_133 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
F_134 ( V_8 ) ;
}
goto V_224;
}
if ( V_8 -> V_90 & V_228 ) {
F_135 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_163 ) {
F_136 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_91 ) {
F_137 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_132 ) {
F_138 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_123 ) {
F_139 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_142 ) {
F_140 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_124 ) {
F_141 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_152 ) {
F_142 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_155 ) {
F_143 ( V_8 ) ;
goto V_224;
}
if ( V_8 -> V_90 & V_229 ) {
F_117 ( V_8 ) ;
V_8 -> V_90 &= ~ V_229 ;
goto V_224;
}
if ( V_8 -> V_93 == V_154 )
F_144 ( V_8 ) ;
V_224:
if ( V_8 -> V_93 == V_154 ) {
F_23 ( V_8 , ~ 0 ) ;
F_25 ( V_8 , 0xFF ) ;
} else {
F_25 ( V_8 , 0x1 ) ;
}
F_59 ( V_116 , & V_8 -> V_117 ) ;
V_218:
if ( V_8 -> V_93 == V_230 )
return;
if ( V_8 -> V_90 )
F_145 ( & V_8 -> V_156 ,
V_157 + F_146 ( 20 ) ) ;
else
F_145 ( & V_8 -> V_156 , V_157 + ( V_231 * 2 ) ) ;
F_13 ( & V_8 -> V_52 ) ;
}
static void F_147 ( struct V_215 * V_216 )
{
struct V_7 * V_8 = F_130 ( V_216 ,
struct V_7 ,
V_27 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_113 * V_232 ;
struct V_129 * V_115 ;
T_3 V_217 ;
int V_39 = 0 , V_87 ;
while ( F_55 ( V_116 ,
& V_8 -> V_117 ) )
F_87 ( 500 , 1000 ) ;
F_16 ( V_8 ) ;
if ( V_8 -> V_24 & V_26 ) {
V_8 -> V_24 &= ~ V_26 ;
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_8 ) ;
}
V_8 -> V_24 |= V_25 ;
for ( V_39 = 0 ; V_39 < V_233 ; V_39 ++ ) {
V_217 = F_18 ( V_2 , V_226 ) &
V_227 ;
if ( ! V_217 )
break;
F_87 ( 5000 , 10000 ) ;
}
if ( V_39 == V_233 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
goto V_234;
}
for ( V_39 = 0 ; V_39 < V_233 ; V_39 ++ ) {
V_217 = F_18 ( V_2 , V_32 ) &
V_219 ;
if ( V_217 == V_220 )
break;
F_151 ( V_235 ) ;
}
F_152 ( V_8 -> V_12 ) ;
F_151 ( V_235 ) ;
if ( V_39 == V_233 ) {
struct V_129 * V_143 ;
struct V_113 * V_236 , * V_237 ;
F_43 ( & V_8 -> V_12 -> V_13 , L_26 ,
V_217 ) ;
V_8 -> V_24 |= V_159 ;
if ( F_153 ( V_8 -> V_29 ) ) {
F_154 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_88 ( V_29 ) ;
F_89 ( V_29 ) ;
F_77 ( V_8 ) ;
F_21 ( V_8 ) ;
F_44 ( V_8 ) ;
F_155 ( V_8 ) ;
F_156 ( V_8 ) ;
}
F_73 (f, ftmp, &adapter->mac_filter_list,
list) {
F_157 ( & V_115 -> V_120 ) ;
F_9 ( V_115 ) ;
}
F_73 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_157 ( & V_236 -> V_120 ) ;
F_9 ( V_236 ) ;
}
F_45 ( V_8 ) ;
F_124 ( V_8 ) ;
F_92 ( V_8 ) ;
F_123 ( V_8 ) ;
F_9 ( V_8 -> V_176 ) ;
F_148 ( V_2 ) ;
V_8 -> V_29 -> V_24 &= ~ V_238 ;
F_59 ( V_116 , & V_8 -> V_117 ) ;
V_8 -> V_24 &= ~ V_25 ;
V_8 -> V_93 = V_225 ;
F_38 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
return;
}
V_234:
if ( F_153 ( V_8 -> V_29 ) ) {
F_88 ( V_29 ) ;
F_158 ( V_29 ) ;
F_77 ( V_8 ) ;
}
F_21 ( V_8 ) ;
V_8 -> V_93 = V_160 ;
V_8 -> V_24 &= ~ V_25 ;
F_156 ( V_8 ) ;
F_155 ( V_8 ) ;
if ( F_148 ( V_2 ) )
F_159 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_8 -> V_161 = V_162 ;
V_87 = F_149 ( V_2 ) ;
if ( V_87 )
F_38 ( & V_8 -> V_12 -> V_13 , L_29 ,
V_87 ) ;
V_8 -> V_90 = V_228 ;
V_8 -> V_90 |= V_91 ;
F_53 (f, &adapter->mac_filter_list, list) {
V_115 -> V_122 = true ;
}
F_53 (vlf, &adapter->vlan_filter_list, list) {
V_232 -> V_122 = true ;
}
V_8 -> V_90 |= V_132 ;
V_8 -> V_90 |= V_123 ;
F_59 ( V_116 , & V_8 -> V_117 ) ;
F_20 ( V_8 ) ;
F_145 ( & V_8 -> V_156 , V_157 + 2 ) ;
if ( F_153 ( V_8 -> V_29 ) ) {
V_87 = F_160 ( V_8 ) ;
if ( V_87 )
goto V_239;
V_87 = F_161 ( V_8 ) ;
if ( V_87 )
goto V_239;
F_79 ( V_8 ) ;
V_87 = F_84 ( V_8 ) ;
if ( V_87 )
goto V_239;
F_26 ( V_8 , true ) ;
} else {
V_8 -> V_93 = V_225 ;
}
return;
V_239:
F_43 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
F_162 ( V_8 -> V_29 ) ;
}
static void F_163 ( struct V_215 * V_216 )
{
struct V_7 * V_8 =
F_130 ( V_216 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_240 V_241 ;
struct V_242 * V_243 ;
T_1 V_184 ;
T_3 V_49 , V_244 ;
T_6 V_245 ;
if ( V_8 -> V_24 & V_159 )
goto V_89;
V_241 . V_246 = V_247 ;
V_241 . V_248 = F_7 ( V_241 . V_246 , V_16 ) ;
if ( ! V_241 . V_248 )
goto V_89;
V_243 = (struct V_242 * ) & V_241 . V_249 ;
do {
V_184 = F_164 ( V_2 , & V_241 , & V_245 ) ;
if ( V_184 || ! V_243 -> V_250 )
break;
F_165 ( V_8 , V_243 -> V_250 ,
V_243 -> V_251 , V_241 . V_248 ,
V_241 . V_252 ) ;
if ( V_245 != 0 )
memset ( V_241 . V_248 , 0 , V_247 ) ;
} while ( V_245 );
if ( ( V_8 -> V_24 &
( V_25 | V_26 ) ) ||
V_8 -> V_93 == V_160 )
goto V_253;
V_49 = F_18 ( V_2 , V_2 -> V_190 . V_254 . V_255 ) ;
V_244 = V_49 ;
if ( V_49 & V_256 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_256 ;
}
if ( V_49 & V_257 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_257 ;
}
if ( V_49 & V_258 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_258 ;
}
if ( V_244 != V_49 )
F_17 ( V_2 , V_2 -> V_190 . V_254 . V_255 , V_49 ) ;
V_49 = F_18 ( V_2 , V_2 -> V_190 . V_259 . V_255 ) ;
V_244 = V_49 ;
if ( V_49 & V_260 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_34 ) ;
V_49 &= ~ V_260 ;
}
if ( V_49 & V_261 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_35 ) ;
V_49 &= ~ V_261 ;
}
if ( V_49 & V_262 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_36 ) ;
V_49 &= ~ V_262 ;
}
if ( V_244 != V_49 )
F_17 ( V_2 , V_2 -> V_190 . V_259 . V_255 , V_49 ) ;
V_253:
F_9 ( V_241 . V_248 ) ;
V_89:
F_20 ( V_8 ) ;
}
void F_155 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_75 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_75 [ V_39 ] . V_249 )
F_166 ( & V_8 -> V_75 [ V_39 ] ) ;
}
static int F_160 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_75 [ V_39 ] . V_68 = V_8 -> V_170 ;
V_87 = F_167 ( & V_8 -> V_75 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_43 ( & V_8 -> V_12 -> V_13 ,
L_37 , V_39 ) ;
break;
}
return V_87 ;
}
static int F_161 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_68 = V_8 -> V_173 ;
V_87 = F_168 ( & V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_43 ( & V_8 -> V_12 -> V_13 ,
L_38 , V_39 ) ;
break;
}
return V_87 ;
}
void F_156 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_65 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] . V_249 )
F_169 ( & V_8 -> V_65 [ V_39 ] ) ;
}
static int F_170 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_87 ;
if ( V_8 -> V_24 & V_159 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_39 ) ;
return - V_127 ;
}
if ( V_8 -> V_93 != V_225 )
return - V_187 ;
V_87 = F_160 ( V_8 ) ;
if ( V_87 )
goto V_263;
V_87 = F_161 ( V_8 ) ;
if ( V_87 )
goto V_264;
V_87 = F_36 ( V_8 , V_29 -> V_97 ) ;
if ( V_87 )
goto V_265;
F_66 ( V_8 , V_8 -> V_2 . V_141 . V_135 ) ;
F_79 ( V_8 ) ;
V_87 = F_84 ( V_8 ) ;
if ( V_87 )
goto V_265;
F_26 ( V_8 , true ) ;
return 0 ;
V_265:
F_86 ( V_8 ) ;
F_44 ( V_8 ) ;
V_264:
F_156 ( V_8 ) ;
V_263:
F_155 ( V_8 ) ;
return V_87 ;
}
static int F_162 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( V_8 -> V_93 <= V_158 )
return 0 ;
F_154 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_86 ( V_8 ) ;
V_8 -> V_93 = V_158 ;
F_44 ( V_8 ) ;
return 0 ;
}
static struct V_266 * F_171 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
return & V_8 -> V_267 ;
}
static int F_172 ( struct V_28 * V_29 , int V_268 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_103 = V_268 + V_105 + V_106 ;
if ( ( V_268 < 68 ) || ( V_103 > V_269 ) )
return - V_186 ;
V_29 -> V_104 = V_268 ;
V_8 -> V_24 |= V_26 ;
F_13 ( & V_8 -> V_27 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
T_3 V_270 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_270 = F_18 ( V_2 , V_32 ) &
V_219 ;
if ( ( V_270 == V_220 ) ||
( V_270 == V_221 ) )
return 0 ;
F_87 ( 10 , 20 ) ;
}
return - V_187 ;
}
int F_174 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_176 -> V_271 ; V_39 ++ ) {
if ( V_8 -> V_176 -> V_167 [ V_39 ] . V_272 == V_273 )
V_8 -> V_167 = & V_8 -> V_176 -> V_167 [ V_39 ] ;
}
if ( ! V_8 -> V_167 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_40 ) ;
return - V_274 ;
}
if ( V_8 -> V_176 -> V_201
& V_275 ) {
V_29 -> V_276 = V_29 -> V_277 &
~ ( V_278 |
V_279 |
V_280 ) ;
V_29 -> V_277 |= V_278 |
V_279 |
V_280 ;
}
V_29 -> V_277 |= V_281 |
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
V_292 ;
V_29 -> V_293 |= V_283 |
V_285 |
V_286 |
V_287 |
V_288 |
V_289 |
V_290 |
V_294 ;
if ( V_8 -> V_24 & V_295 )
V_29 -> V_277 |= V_294 ;
V_29 -> V_296 |= V_29 -> V_277 ;
V_29 -> V_296 &= ~ V_291 ;
V_8 -> V_67 . V_185 = V_8 -> V_167 -> V_297 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_298 = 1 ;
V_8 -> V_67 . V_299 = V_300 ;
V_8 -> V_67 . V_301 = ( V_302 |
F_175 ( V_303 ) ) ;
V_8 -> V_67 . V_304 = ( V_302 |
F_175 ( V_305 ) ) ;
V_8 -> V_67 . V_29 = V_8 -> V_29 ;
V_8 -> V_67 . V_306 = V_8 -> V_167 -> V_307 ;
return 0 ;
}
static void F_176 ( struct V_215 * V_216 )
{
struct V_7 * V_8 = F_130 ( V_216 ,
struct V_7 ,
V_223 . V_216 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_308 * V_12 = V_8 -> V_12 ;
int V_87 , V_309 ;
switch ( V_8 -> V_93 ) {
case V_222 :
V_8 -> V_24 &= ~ V_159 ;
V_8 -> V_24 &= ~ V_25 ;
V_87 = F_177 ( V_2 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_41 ,
V_87 ) ;
goto V_87;
}
V_87 = F_173 ( V_2 ) ;
if ( V_87 ) {
F_38 ( & V_12 -> V_13 , L_42 ,
V_87 ) ;
goto V_87;
}
V_2 -> V_190 . V_310 = V_311 ;
V_2 -> V_190 . V_312 = V_311 ;
V_2 -> V_190 . V_313 = V_247 ;
V_2 -> V_190 . V_314 = V_247 ;
V_87 = F_149 ( V_2 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_43 ,
V_87 ) ;
goto V_87;
}
V_87 = F_134 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_44 , V_87 ) ;
F_148 ( V_2 ) ;
goto V_87;
}
V_8 -> V_93 = V_315 ;
goto V_316;
case V_315 :
if ( ! F_132 ( V_2 ) ) {
F_43 ( & V_12 -> V_13 , L_45 ) ;
F_148 ( V_2 ) ;
V_8 -> V_93 = V_222 ;
goto V_87;
}
V_87 = F_178 ( V_8 ) ;
if ( V_87 ) {
if ( V_87 == V_317 )
V_87 = F_134 ( V_8 ) ;
else
F_43 ( & V_12 -> V_13 , L_46 ,
V_8 -> V_318 . V_319 ,
V_8 -> V_318 . V_320 ,
V_321 ,
V_322 ) ;
goto V_87;
}
V_87 = F_135 ( V_8 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_47 ,
V_87 ) ;
goto V_87;
}
V_8 -> V_93 = V_323 ;
goto V_316;
case V_323 :
if ( ! V_8 -> V_176 ) {
V_309 = sizeof( struct V_324 ) +
( V_325 *
sizeof( struct V_326 ) ) ;
V_8 -> V_176 = F_7 ( V_309 , V_16 ) ;
if ( ! V_8 -> V_176 )
goto V_87;
}
V_87 = F_179 ( V_8 ) ;
if ( V_87 == V_317 ) {
V_87 = F_135 ( V_8 ) ;
goto V_87;
} else if ( V_87 == V_10 ) {
F_148 ( V_2 ) ;
F_43 ( & V_12 -> V_13 , L_48 ) ;
return;
}
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_49 ,
V_87 ) ;
goto V_327;
}
V_8 -> V_93 = V_328 ;
break;
default:
goto V_327;
}
if ( V_2 -> V_141 . type == V_329 )
V_8 -> V_24 |= V_295 ;
if ( F_174 ( V_8 ) )
goto V_327;
V_8 -> V_161 = V_162 ;
V_8 -> V_24 |= V_330 ;
V_8 -> V_24 |= V_331 ;
V_8 -> V_24 |= V_332 ;
V_8 -> V_24 &= ~ V_108 ;
V_29 -> V_333 = & V_334 ;
F_180 ( V_29 ) ;
V_29 -> V_335 = 5 * V_231 ;
if ( ! F_69 ( V_8 -> V_2 . V_141 . V_135 ) ) {
F_38 ( & V_12 -> V_13 , L_50 ,
V_8 -> V_2 . V_141 . V_135 ) ;
F_181 ( V_29 ) ;
F_67 ( V_8 -> V_2 . V_141 . V_135 , V_29 -> V_138 ) ;
} else {
V_8 -> V_24 |= V_139 ;
F_67 ( V_29 -> V_138 , V_8 -> V_2 . V_141 . V_135 ) ;
F_67 ( V_29 -> V_336 , V_8 -> V_2 . V_141 . V_135 ) ;
}
F_182 ( & V_8 -> V_156 ) ;
V_8 -> V_156 . V_337 = & F_128 ;
V_8 -> V_156 . V_48 = ( unsigned long ) V_8 ;
F_145 ( & V_8 -> V_156 , V_157 + 1 ) ;
V_8 -> V_82 = F_96 ( int ,
V_8 -> V_167 -> V_338 ,
( int ) ( F_97 () ) ) ;
V_8 -> V_170 = V_339 ;
V_8 -> V_173 = V_340 ;
V_87 = F_126 ( V_8 ) ;
if ( V_87 )
goto V_341;
F_32 ( V_8 ) ;
if ( V_8 -> V_176 -> V_201 &
V_342 )
V_8 -> V_24 |= V_343 ;
V_87 = F_41 ( V_8 ) ;
if ( V_87 )
goto V_341;
F_88 ( V_29 ) ;
if ( ! V_8 -> V_344 ) {
V_87 = F_183 ( V_29 ) ;
if ( V_87 )
goto V_345;
}
V_8 -> V_344 = true ;
F_158 ( V_29 ) ;
F_38 ( & V_12 -> V_13 , L_51 , V_8 -> V_2 . V_141 . V_135 ) ;
if ( V_29 -> V_277 & V_292 )
F_38 ( & V_12 -> V_13 , L_52 ) ;
V_8 -> V_93 = V_225 ;
F_154 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_20 ( V_8 ) ;
if ( F_114 ( V_8 ) ) {
V_8 -> V_90 |= V_229 ;
F_85 ( & V_8 -> V_156 , V_157 + 1 ) ;
} else {
F_117 ( V_8 ) ;
}
return;
V_316:
F_131 ( & V_8 -> V_223 , F_146 ( 30 ) ) ;
return;
V_345:
F_45 ( V_8 ) ;
V_341:
F_124 ( V_8 ) ;
V_327:
F_9 ( V_8 -> V_176 ) ;
V_8 -> V_176 = NULL ;
V_87:
if ( ++ V_8 -> V_346 > V_347 ) {
F_43 ( & V_12 -> V_13 , L_53 ) ;
V_8 -> V_24 |= V_159 ;
F_148 ( V_2 ) ;
V_8 -> V_93 = V_222 ;
F_131 ( & V_8 -> V_223 , V_231 * 5 ) ;
return;
}
F_131 ( & V_8 -> V_223 , V_231 ) ;
}
static void F_184 ( struct V_308 * V_12 )
{
struct V_28 * V_29 = F_185 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
F_186 ( V_29 ) ;
if ( F_153 ( V_29 ) )
F_162 ( V_29 ) ;
V_8 -> V_93 = V_230 ;
V_8 -> V_90 = 0 ;
#ifdef F_187
F_188 ( V_12 ) ;
#endif
F_189 ( V_12 ) ;
}
static int F_190 ( struct V_308 * V_12 , const struct V_348 * V_349 )
{
struct V_28 * V_29 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_87 ;
V_87 = F_191 ( V_12 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_192 ( & V_12 -> V_13 , F_193 ( 64 ) ) ;
if ( V_87 ) {
V_87 = F_192 ( & V_12 -> V_13 , F_193 ( 32 ) ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 ,
L_54 , V_87 ) ;
goto V_350;
}
}
V_87 = F_194 ( V_12 , V_351 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 ,
L_55 , V_87 ) ;
goto V_352;
}
F_195 ( V_12 ) ;
F_152 ( V_12 ) ;
V_29 = F_196 ( sizeof( struct V_7 ) , V_353 ) ;
if ( ! V_29 ) {
V_87 = - V_128 ;
goto V_354;
}
F_197 ( V_29 , & V_12 -> V_13 ) ;
F_198 ( V_12 , V_29 ) ;
V_8 = F_15 ( V_29 ) ;
V_8 -> V_29 = V_29 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_355 = F_24 ( V_356 ) - 1 ;
V_8 -> V_93 = V_222 ;
F_188 ( V_12 ) ;
V_2 -> V_102 = F_199 ( F_200 ( V_12 , 0 ) ,
F_201 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_102 ) {
V_87 = - V_127 ;
goto V_357;
}
V_2 -> V_358 = V_12 -> V_359 ;
V_2 -> V_360 = V_12 -> V_361 ;
F_202 ( V_12 , V_362 , & V_2 -> V_363 ) ;
V_2 -> V_364 = V_12 -> V_365 ;
V_2 -> V_366 = V_12 -> V_367 ;
V_2 -> V_368 . V_361 = F_203 ( V_12 -> V_369 ) ;
V_2 -> V_368 . V_370 = F_204 ( V_12 -> V_369 ) ;
F_205 ( & V_2 -> V_190 . V_371 ) ;
F_205 ( & V_2 -> V_190 . V_372 ) ;
F_57 ( & V_8 -> V_131 ) ;
F_57 ( & V_8 -> V_121 ) ;
F_206 ( & V_8 -> V_27 , F_147 ) ;
F_206 ( & V_8 -> V_52 , F_163 ) ;
F_206 ( & V_8 -> V_214 , F_129 ) ;
F_207 ( & V_8 -> V_223 , F_176 ) ;
F_131 ( & V_8 -> V_223 ,
F_146 ( 5 * ( V_12 -> V_369 & 0x07 ) ) ) ;
return 0 ;
V_357:
F_208 ( V_29 ) ;
V_354:
F_209 ( V_12 ) ;
V_352:
V_350:
F_189 ( V_12 ) ;
return V_87 ;
}
static int F_210 ( struct V_308 * V_12 , T_10 V_93 )
{
struct V_28 * V_29 = F_185 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_373 = 0 ;
F_186 ( V_29 ) ;
if ( F_153 ( V_29 ) ) {
F_211 () ;
F_86 ( V_8 ) ;
F_212 () ;
}
F_45 ( V_8 ) ;
F_124 ( V_8 ) ;
V_373 = F_188 ( V_12 ) ;
if ( V_373 )
return V_373 ;
F_189 ( V_12 ) ;
return 0 ;
}
static int F_213 ( struct V_308 * V_12 )
{
struct V_7 * V_8 = F_185 ( V_12 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
T_3 V_87 ;
F_214 ( V_12 , V_374 ) ;
F_215 ( V_12 ) ;
F_188 ( V_12 ) ;
V_87 = F_216 ( V_12 ) ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_56 ) ;
return V_87 ;
}
F_152 ( V_12 ) ;
F_211 () ;
V_87 = F_95 ( V_8 ) ;
if ( V_87 ) {
F_212 () ;
F_43 ( & V_12 -> V_13 , L_57 ) ;
return V_87 ;
}
V_87 = F_41 ( V_8 ) ;
F_212 () ;
if ( V_87 ) {
F_43 ( & V_12 -> V_13 , L_58 ) ;
return V_87 ;
}
F_13 ( & V_8 -> V_27 ) ;
F_217 ( V_29 ) ;
return V_87 ;
}
static void F_218 ( struct V_308 * V_12 )
{
struct V_28 * V_29 = F_185 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_129 * V_115 , * V_143 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_219 ( & V_8 -> V_223 ) ;
F_220 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_344 ) {
F_221 ( V_29 ) ;
V_8 -> V_344 = false ;
}
V_8 -> V_93 = V_230 ;
V_8 -> V_90 = 0 ;
F_150 ( V_8 ) ;
F_151 ( 20 ) ;
if ( ! F_132 ( V_2 ) ) {
F_150 ( V_8 ) ;
F_151 ( 20 ) ;
}
if ( V_8 -> V_33 ) {
F_16 ( V_8 ) ;
F_45 ( V_8 ) ;
F_124 ( V_8 ) ;
F_123 ( V_8 ) ;
}
if ( V_8 -> V_156 . V_337 )
F_222 ( & V_8 -> V_156 ) ;
F_223 () ;
F_127 ( & V_8 -> V_67 ) ;
if ( V_2 -> V_190 . V_259 . V_68 )
F_148 ( V_2 ) ;
F_224 ( & V_2 -> V_190 . V_372 ) ;
F_224 ( & V_2 -> V_190 . V_371 ) ;
F_225 ( V_2 -> V_102 ) ;
F_209 ( V_12 ) ;
F_155 ( V_8 ) ;
F_156 ( V_8 ) ;
F_92 ( V_8 ) ;
F_9 ( V_8 -> V_176 ) ;
F_73 (f, ftmp, &adapter->mac_filter_list, list) {
F_157 ( & V_115 -> V_120 ) ;
F_9 ( V_115 ) ;
}
F_73 (f, ftmp, &adapter->vlan_filter_list, list) {
F_157 ( & V_115 -> V_120 ) ;
F_9 ( V_115 ) ;
}
F_208 ( V_29 ) ;
F_226 ( V_12 ) ;
F_189 ( V_12 ) ;
}
static int T_11 F_227 ( void )
{
int V_184 ;
F_11 ( L_59 , V_375 ,
V_376 ) ;
F_11 ( L_60 , V_377 ) ;
V_378 = F_228 ( V_351 ) ;
if ( ! V_378 ) {
F_229 ( L_61 , V_351 ) ;
return - V_128 ;
}
V_184 = F_230 ( & V_379 ) ;
return V_184 ;
}
static void T_12 F_231 ( void )
{
F_232 ( & V_379 ) ;
F_233 ( V_378 ) ;
}
