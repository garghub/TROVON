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
T_3 V_44 ;
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
static T_5 F_26 ( int V_47 , void * V_48 )
{
struct V_24 * V_25 = V_48 ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_49 ;
V_49 = F_17 ( V_2 , V_50 ) ;
V_49 = F_17 ( V_2 , V_37 ) ;
V_49 = F_17 ( V_2 , V_31 ) |
V_51 ;
F_16 ( V_2 , V_31 , V_49 ) ;
F_14 ( & V_8 -> V_52 ) ;
return V_53 ;
}
static T_5 F_27 ( int V_47 , void * V_48 )
{
struct V_54 * V_55 = V_48 ;
if ( ! V_55 -> V_56 . V_57 && ! V_55 -> V_58 . V_57 )
return V_53 ;
F_28 ( & V_55 -> V_59 ) ;
return V_53 ;
}
static void
F_29 ( struct V_7 * V_8 , int V_60 , int V_61 )
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
F_30 ( struct V_7 * V_8 , int V_60 , int V_73 )
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
V_55 -> V_77 |= F_23 ( V_73 ) ;
}
static int F_31 ( struct V_7 * V_8 )
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
F_29 ( V_8 , V_78 , V_79 ) ;
for (; V_80 < V_83 ; V_78 ++ , V_80 ++ )
F_30 ( V_8 , V_78 , V_80 ) ;
goto V_89;
}
for ( V_39 = V_78 ; V_39 < V_62 ; V_39 ++ ) {
V_85 = F_32 ( V_81 , V_62 - V_39 ) ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ ) {
F_29 ( V_8 , V_39 , V_79 ) ;
V_79 ++ ;
V_81 -- ;
}
}
for ( V_39 = V_78 ; V_39 < V_62 ; V_39 ++ ) {
V_86 = F_32 ( V_83 , V_62 - V_39 ) ;
for ( V_84 = 0 ; V_84 < V_86 ; V_84 ++ ) {
F_30 ( V_8 , V_39 , V_80 ) ;
V_80 ++ ;
V_83 -- ;
}
}
V_89:
V_8 -> V_90 |= V_91 ;
return V_87 ;
}
static void F_33 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_62 = V_8 -> V_40 - V_88 ;
int V_39 ;
if ( F_34 ( V_92 , & V_8 -> V_67 . V_93 ) )
return;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ )
F_27 ( 0 , & V_8 -> V_62 [ V_39 ] ) ;
}
static int
F_35 ( struct V_7 * V_8 , char * V_94 )
{
int V_34 , V_87 , V_62 ;
int V_95 = 0 , V_96 = 0 ;
F_20 ( V_8 ) ;
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
V_87 = F_36 (
V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
F_27 ,
0 ,
V_55 -> V_97 ,
V_55 ) ;
if ( V_87 ) {
F_37 ( & V_8 -> V_12 -> V_13 ,
L_6 , V_87 ) ;
goto V_98;
}
F_38 (
V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
V_55 -> V_99 ) ;
}
return 0 ;
V_98:
while ( V_34 ) {
V_34 -- ;
F_38 (
V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
NULL ) ;
F_39 ( V_8 -> V_33 [ V_34 + V_88 ] . V_34 ,
& V_8 -> V_62 [ V_34 ] ) ;
}
return V_87 ;
}
static int F_40 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_87 ;
snprintf ( V_8 -> V_100 ,
sizeof( V_8 -> V_100 ) - 1 , L_7 ,
F_41 ( & V_8 -> V_12 -> V_13 ) ) ;
V_87 = F_36 ( V_8 -> V_33 [ 0 ] . V_34 ,
& F_26 , 0 ,
V_8 -> V_100 , V_25 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_8 ,
V_8 -> V_100 , V_87 ) ;
F_39 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
return V_87 ;
}
static void F_43 ( struct V_7 * V_8 )
{
int V_39 ;
int V_62 ;
V_62 = V_8 -> V_40 - V_88 ;
for ( V_39 = 0 ; V_39 < V_62 ; V_39 ++ ) {
F_38 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_39 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
& V_8 -> V_62 [ V_39 ] ) ;
}
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
F_39 ( V_8 -> V_33 [ 0 ] . V_34 , V_25 ) ;
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
V_8 -> V_75 [ V_39 ] . V_101 = V_2 -> V_102 + F_46 ( V_39 ) ;
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_24 * V_25 = V_8 -> V_25 ;
int V_103 = V_25 -> V_104 + V_105 + V_106 ;
int V_39 ;
int V_107 ;
V_8 -> V_27 &= ~ V_108 ;
V_8 -> V_27 |= V_109 ;
if ( V_25 -> V_104 > V_110 ) {
if ( V_8 -> V_27 & V_108 )
V_8 -> V_27 |= V_111 ;
else
V_8 -> V_27 &= ~ V_111 ;
} else {
if ( V_8 -> V_27 & V_109 )
V_8 -> V_27 &= ~ V_111 ;
else
V_8 -> V_27 |= V_111 ;
}
if ( V_8 -> V_27 & V_111 ) {
V_107 = V_112 ;
} else {
if ( V_25 -> V_104 <= V_110 )
V_107 = V_113 ;
else
V_107 = F_2 ( V_103 , 1024 ) ;
}
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_101 = V_2 -> V_102 + F_48 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] . V_107 = V_107 ;
}
}
static struct
V_114 * F_49 ( struct V_7 * V_8 , T_6 V_115 )
{
struct V_114 * V_116 ;
F_50 (f, &adapter->vlan_filter_list, list) {
if ( V_115 == V_116 -> V_115 )
return V_116 ;
}
return NULL ;
}
static struct
V_114 * F_51 ( struct V_7 * V_8 , T_6 V_115 )
{
struct V_114 * V_116 = NULL ;
int V_68 = 50 ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_89;
}
V_116 = F_49 ( V_8 , V_115 ) ;
if ( ! V_116 ) {
V_116 = F_7 ( sizeof( * V_116 ) , V_119 ) ;
if ( ! V_116 )
goto V_120;
V_116 -> V_115 = V_115 ;
F_54 ( & V_116 -> V_121 ) ;
F_55 ( & V_116 -> V_121 , & V_8 -> V_122 ) ;
V_116 -> V_123 = true ;
V_8 -> V_90 |= V_124 ;
}
V_120:
F_56 ( V_117 , & V_8 -> V_118 ) ;
V_89:
return V_116 ;
}
static void F_57 ( struct V_7 * V_8 , T_6 V_115 )
{
struct V_114 * V_116 ;
int V_68 = 50 ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_116 = F_49 ( V_8 , V_115 ) ;
if ( V_116 ) {
V_116 -> remove = true ;
V_8 -> V_90 |= V_125 ;
}
F_56 ( V_117 , & V_8 -> V_118 ) ;
}
static int F_58 ( struct V_24 * V_25 ,
T_7 T_8 V_126 , T_6 V_127 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( ! F_59 ( V_8 ) )
return - V_128 ;
if ( F_51 ( V_8 , V_127 ) == NULL )
return - V_129 ;
return 0 ;
}
static int F_60 ( struct V_24 * V_25 ,
T_7 T_8 V_126 , T_6 V_127 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( F_59 ( V_8 ) ) {
F_57 ( V_8 , V_127 ) ;
return 0 ;
}
return - V_128 ;
}
static struct
V_130 * F_61 ( struct V_7 * V_8 ,
T_9 * V_131 )
{
struct V_130 * V_116 ;
if ( ! V_131 )
return NULL ;
F_50 (f, &adapter->mac_filter_list, list) {
if ( F_62 ( V_131 , V_116 -> V_131 ) )
return V_116 ;
}
return NULL ;
}
static struct
V_130 * F_63 ( struct V_7 * V_8 ,
T_9 * V_131 )
{
struct V_130 * V_116 ;
int V_68 = 50 ;
if ( ! V_131 )
return NULL ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_116 = F_61 ( V_8 , V_131 ) ;
if ( ! V_116 ) {
V_116 = F_7 ( sizeof( * V_116 ) , V_119 ) ;
if ( ! V_116 ) {
F_56 ( V_117 ,
& V_8 -> V_118 ) ;
return NULL ;
}
F_64 ( V_116 -> V_131 , V_131 ) ;
F_55 ( & V_116 -> V_121 , & V_8 -> V_132 ) ;
V_116 -> V_123 = true ;
V_8 -> V_90 |= V_133 ;
}
F_56 ( V_117 , & V_8 -> V_118 ) ;
return V_116 ;
}
static int F_65 ( struct V_24 * V_25 , void * V_134 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_130 * V_116 ;
struct V_135 * V_136 = V_134 ;
if ( ! F_66 ( V_136 -> V_137 ) )
return - V_138 ;
if ( F_62 ( V_25 -> V_139 , V_136 -> V_137 ) )
return 0 ;
if ( V_8 -> V_27 & V_140 )
return - V_141 ;
V_116 = F_61 ( V_8 , V_2 -> V_142 . V_136 ) ;
if ( V_116 ) {
V_116 -> remove = true ;
V_8 -> V_90 |= V_143 ;
}
V_116 = F_63 ( V_8 , V_136 -> V_137 ) ;
if ( V_116 ) {
F_64 ( V_2 -> V_142 . V_136 , V_136 -> V_137 ) ;
F_64 ( V_25 -> V_139 , V_8 -> V_2 . V_142 . V_136 ) ;
}
return ( V_116 == NULL ) ? - V_129 : 0 ;
}
static void F_67 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_130 * V_116 , * V_144 ;
struct V_145 * V_146 ;
struct V_145 * V_147 ;
struct V_145 * V_148 ;
int V_68 = 50 ;
F_68 (uca, netdev) {
F_63 ( V_8 , V_146 -> V_136 ) ;
}
F_69 (mca, netdev) {
F_63 ( V_8 , V_147 -> V_136 ) ;
}
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_149 ) ;
return;
}
}
F_70 (f, ftmp, &adapter->mac_filter_list, list) {
F_69 (mca, netdev)
if ( F_62 ( V_147 -> V_136 , V_116 -> V_131 ) )
goto V_150;
F_68 (uca, netdev)
if ( F_62 ( V_146 -> V_136 , V_116 -> V_131 ) )
goto V_150;
F_71 (netdev, ha)
if ( F_62 ( V_148 -> V_136 , V_116 -> V_131 ) )
goto V_150;
if ( F_62 ( V_116 -> V_131 , V_8 -> V_2 . V_142 . V_136 ) )
goto V_150;
V_116 -> remove = true ;
V_8 -> V_90 |= V_143 ;
V_150:
continue;
}
F_56 ( V_117 , & V_8 -> V_118 ) ;
}
static void F_72 ( struct V_7 * V_8 )
{
int V_151 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_88 ;
for ( V_151 = 0 ; V_151 < V_62 ; V_151 ++ ) {
struct V_152 * V_59 ;
V_55 = & V_8 -> V_62 [ V_151 ] ;
V_59 = & V_55 -> V_59 ;
F_73 ( V_59 ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
int V_151 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_88 ;
for ( V_151 = 0 ; V_151 < V_62 ; V_151 ++ ) {
V_55 = & V_8 -> V_62 [ V_151 ] ;
F_75 ( & V_55 -> V_59 ) ;
}
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
F_67 ( V_25 ) ;
F_45 ( V_8 ) ;
F_47 ( V_8 ) ;
V_8 -> V_90 |= V_153 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_63 * V_57 = & V_8 -> V_65 [ V_39 ] ;
F_77 ( V_57 , V_57 -> V_68 ) ;
V_57 -> V_154 = V_57 -> V_68 - 1 ;
F_78 ( V_57 -> V_154 , V_57 -> V_101 ) ;
}
}
static int F_79 ( struct V_7 * V_8 )
{
V_8 -> V_93 = V_155 ;
F_56 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_72 ( V_8 ) ;
V_8 -> V_90 |= V_156 ;
F_80 ( & V_8 -> V_157 , V_158 + 1 ) ;
return 0 ;
}
void F_81 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_130 * V_116 ;
if ( V_8 -> V_93 == V_159 )
return;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) )
F_82 ( 500 , 1000 ) ;
F_83 ( V_25 ) ;
F_84 ( V_25 ) ;
F_74 ( V_8 ) ;
F_20 ( V_8 ) ;
F_50 (f, &adapter->mac_filter_list, list) {
V_116 -> remove = true ;
}
F_50 (f, &adapter->vlan_filter_list, list) {
V_116 -> remove = true ;
}
if ( ! ( V_8 -> V_27 & V_160 ) &&
V_8 -> V_93 != V_161 ) {
V_8 -> V_162 = V_163 ;
V_8 -> V_90 = V_143 ;
V_8 -> V_90 |= V_125 ;
V_8 -> V_90 |= V_164 ;
}
F_56 ( V_117 , & V_8 -> V_118 ) ;
}
static int
F_85 ( struct V_7 * V_8 , int V_165 )
{
int V_87 , V_166 ;
V_166 = V_167 ;
V_87 = F_86 ( V_8 -> V_12 , V_8 -> V_33 ,
V_166 , V_165 ) ;
if ( V_87 < 0 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
return V_87 ;
}
V_8 -> V_40 = V_87 ;
return 0 ;
}
static void F_87 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_168 )
return;
F_9 ( V_8 -> V_75 ) ;
F_9 ( V_8 -> V_65 ) ;
}
static int F_88 ( struct V_7 * V_8 )
{
int V_39 ;
V_8 -> V_75 = F_89 ( V_8 -> V_82 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_75 )
goto V_169;
V_8 -> V_65 = F_89 ( V_8 -> V_82 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_65 )
goto V_169;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_63 * V_74 ;
struct V_63 * V_64 ;
V_74 = & V_8 -> V_75 [ V_39 ] ;
V_74 -> V_170 = V_39 ;
V_74 -> V_25 = V_8 -> V_25 ;
V_74 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_74 -> V_68 = V_8 -> V_171 ;
if ( V_8 -> V_27 & V_172 )
V_74 -> V_27 |= V_173 ;
V_64 = & V_8 -> V_65 [ V_39 ] ;
V_64 -> V_170 = V_39 ;
V_64 -> V_25 = V_8 -> V_25 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_174 ;
}
return 0 ;
V_169:
F_87 ( V_8 ) ;
return - V_129 ;
}
static int F_90 ( struct V_7 * V_8 )
{
int V_34 , V_175 ;
int V_176 = 0 ;
int V_87 = 0 ;
if ( ! V_8 -> V_168 ) {
V_87 = - V_128 ;
goto V_89;
}
V_176 = V_8 -> V_82 ;
V_175 = F_91 ( int , V_176 , ( int ) ( F_92 () * 2 ) ) + V_88 ;
V_175 = F_91 ( int , V_175 , ( int ) V_8 -> V_177 -> V_178 ) ;
V_8 -> V_33 = F_89 ( V_175 ,
sizeof( struct V_179 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_87 = - V_129 ;
goto V_89;
}
for ( V_34 = 0 ; V_34 < V_175 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_180 = V_34 ;
V_87 = F_85 ( V_8 , V_175 ) ;
V_89:
F_93 ( V_8 -> V_25 , V_176 ) ;
F_94 ( V_8 -> V_25 , V_176 ) ;
return V_87 ;
}
static int F_95 ( struct V_181 * V_67 , const T_9 * V_182 ,
T_9 * V_183 , T_6 V_184 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_185 = 0 ;
if ( ! V_67 -> V_186 )
return - V_187 ;
if ( V_8 -> V_162 != V_163 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_162 ) ;
return - V_188 ;
}
if ( V_182 ) {
struct V_189 * V_190 =
(struct V_189 * ) V_182 ;
V_185 = F_96 ( V_2 , V_67 -> V_186 , V_190 ) ;
if ( V_185 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_12 ,
F_97 ( V_2 , V_185 ) ,
F_98 ( V_2 , V_2 -> V_191 . V_192 ) ) ;
return V_185 ;
}
}
if ( V_183 ) {
V_185 = F_99 ( V_2 , V_67 -> V_186 , false , V_183 , V_184 ) ;
if ( V_185 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_13 ,
F_97 ( V_2 , V_185 ) ,
F_98 ( V_2 , V_2 -> V_191 . V_192 ) ) ;
return V_185 ;
}
}
return V_185 ;
}
static int F_100 ( struct V_181 * V_67 , const T_9 * V_182 ,
const T_9 * V_183 , T_6 V_184 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_6 V_39 ;
if ( V_182 ) {
T_3 * V_193 = ( T_3 * ) V_182 ;
for ( V_39 = 0 ; V_39 <= V_194 ; V_39 ++ )
F_16 ( V_2 , F_101 ( V_39 ) , V_193 [ V_39 ] ) ;
}
if ( V_183 ) {
T_3 * V_195 = ( T_3 * ) V_183 ;
if ( V_184 != V_196 )
return - V_187 ;
for ( V_39 = 0 ; V_39 <= V_197 ; V_39 ++ )
F_16 ( V_2 , F_102 ( V_39 ) , V_195 [ V_39 ] ) ;
}
F_103 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_181 * V_67 , const T_9 * V_182 ,
T_9 * V_183 , T_6 V_184 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_185 = 0 ;
if ( V_182 ) {
V_185 = F_105 ( V_2 , V_67 -> V_186 ,
(struct V_189 * ) V_182 ) ;
if ( V_185 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_14 ,
F_97 ( V_2 , V_185 ) ,
F_98 ( V_2 , V_2 -> V_191 . V_192 ) ) ;
return V_185 ;
}
}
if ( V_183 ) {
V_185 = F_106 ( V_2 , V_67 -> V_186 , V_182 , V_183 , V_184 ) ;
if ( V_185 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_15 ,
F_97 ( V_2 , V_185 ) ,
F_98 ( V_2 , V_2 -> V_191 . V_192 ) ) ;
return V_185 ;
}
}
return V_185 ;
}
static int F_107 ( struct V_181 * V_67 , const T_9 * V_182 ,
const T_9 * V_183 , T_6 V_184 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_6 V_39 ;
if ( V_182 ) {
T_3 * V_193 = ( T_3 * ) V_182 ;
for ( V_39 = 0 ; V_39 <= V_194 ; V_39 ++ )
V_193 [ V_39 ] = F_17 ( V_2 , F_101 ( V_39 ) ) ;
}
if ( V_183 ) {
T_3 * V_195 = ( T_3 * ) V_183 ;
if ( V_184 != V_196 )
return - V_187 ;
for ( V_39 = 0 ; V_39 <= V_197 ; V_39 ++ )
V_195 [ V_39 ] = F_17 ( V_2 , F_102 ( V_39 ) ) ;
}
return 0 ;
}
int F_108 ( struct V_181 * V_67 , const T_9 * V_182 ,
T_9 * V_183 , T_6 V_184 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
if ( F_109 ( V_8 ) )
return F_95 ( V_67 , V_182 , V_183 , V_184 ) ;
else
return F_100 ( V_67 , V_182 , V_183 , V_184 ) ;
}
int F_110 ( struct V_181 * V_67 , const T_9 * V_182 , T_9 * V_183 , T_6 V_184 )
{
struct V_7 * V_8 = V_67 -> V_9 ;
if ( F_109 ( V_8 ) )
return F_104 ( V_67 , V_182 , V_183 , V_184 ) ;
else
return F_107 ( V_67 , V_182 , V_183 , V_184 ) ;
}
static void F_111 ( T_9 * V_183 , T_6 V_198 , T_6 V_199 )
{
T_6 V_39 ;
for ( V_39 = 0 ; V_39 < V_198 ; V_39 ++ )
V_183 [ V_39 ] = V_39 % V_199 ;
}
static int F_112 ( struct V_7 * V_8 )
{
struct V_181 * V_67 = & V_8 -> V_67 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_9 V_182 [ V_200 ] ;
T_2 V_201 ;
T_9 * V_183 ;
int V_185 ;
V_201 = V_202 ;
F_16 ( V_2 , F_113 ( 0 ) , ( T_3 ) V_201 ) ;
F_16 ( V_2 , F_113 ( 1 ) , ( T_3 ) ( V_201 >> 32 ) ) ;
V_183 = F_7 ( V_196 , V_16 ) ;
if ( ! V_183 )
return - V_129 ;
if ( V_67 -> V_203 )
memcpy ( V_183 , V_67 -> V_203 , V_196 ) ;
else
F_111 ( V_183 , V_196 ,
V_8 -> V_82 ) ;
if ( V_67 -> V_204 )
memcpy ( V_182 , V_67 -> V_204 , V_200 ) ;
else
F_114 ( ( void * ) V_182 , V_200 ) ;
V_185 = F_108 ( V_67 , V_182 , V_183 , V_196 ) ;
F_9 ( V_183 ) ;
return V_185 ;
}
static int F_115 ( struct V_7 * V_8 )
{
int V_151 = 0 , V_205 ;
struct V_54 * V_55 ;
V_205 = V_8 -> V_40 - V_88 ;
V_8 -> V_62 = F_89 ( V_205 , sizeof( * V_55 ) ,
V_16 ) ;
if ( ! V_8 -> V_62 )
goto V_169;
for ( V_151 = 0 ; V_151 < V_205 ; V_151 ++ ) {
V_55 = & V_8 -> V_62 [ V_151 ] ;
V_55 -> V_8 = V_8 ;
V_55 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_60 = V_151 ;
F_116 ( V_8 -> V_25 , & V_55 -> V_59 ,
V_206 , V_207 ) ;
}
return 0 ;
V_169:
while ( V_151 ) {
V_151 -- ;
V_55 = & V_8 -> V_62 [ V_151 ] ;
F_117 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
return - V_129 ;
}
static void F_118 ( struct V_7 * V_8 )
{
int V_151 , V_205 ;
int V_208 ;
V_205 = V_8 -> V_40 - V_88 ;
V_208 = V_8 -> V_82 ;
for ( V_151 = 0 ; V_151 < V_205 ; V_151 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_151 ] ;
if ( V_151 < V_208 )
F_117 ( & V_55 -> V_59 ) ;
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
int V_87 ;
V_87 = F_90 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_209;
}
V_87 = F_115 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_17 ) ;
goto V_210;
}
V_87 = F_88 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_18 ) ;
goto V_211;
}
F_37 ( & V_8 -> V_12 -> V_13 , L_19 ,
( V_8 -> V_82 > 1 ) ? L_20 : L_21 ,
V_8 -> V_82 ) ;
return 0 ;
V_211:
F_118 ( V_8 ) ;
V_210:
F_119 ( V_8 ) ;
V_209:
return V_87 ;
}
static void F_122 ( struct V_181 * V_67 )
{
if ( ! V_67 )
return;
F_9 ( V_67 -> V_204 ) ;
V_67 -> V_204 = NULL ;
F_9 ( V_67 -> V_203 ) ;
V_67 -> V_203 = NULL ;
}
static void F_123 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_14 ( & V_8 -> V_212 ) ;
}
static void F_124 ( struct V_213 * V_214 )
{
struct V_7 * V_8 = F_125 ( V_214 ,
struct V_7 ,
V_212 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_215 ;
if ( F_52 ( V_117 , & V_8 -> V_118 ) )
goto V_216;
if ( V_8 -> V_27 & V_160 ) {
V_215 = F_17 ( V_2 , V_32 ) &
V_217 ;
if ( ( V_215 == V_218 ) ||
( V_215 == V_219 ) ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
V_8 -> V_93 = V_220 ;
V_8 -> V_27 &= ~ V_160 ;
F_126 ( & V_8 -> V_221 , 10 ) ;
F_56 ( V_117 ,
& V_8 -> V_118 ) ;
return;
}
V_8 -> V_90 = 0 ;
V_8 -> V_162 = V_163 ;
goto V_222;
}
if ( ( V_8 -> V_93 < V_159 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_222;
V_215 = F_17 ( V_2 , V_223 ) & V_224 ;
if ( ! ( V_8 -> V_27 & V_28 ) && ! V_215 ) {
V_8 -> V_93 = V_161 ;
V_8 -> V_27 |= V_28 ;
F_42 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
F_14 ( & V_8 -> V_30 ) ;
V_8 -> V_90 = 0 ;
V_8 -> V_162 = V_163 ;
goto V_222;
}
if ( V_8 -> V_162 ) {
if ( ! F_127 ( V_2 ) ) {
F_128 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
F_129 ( V_8 ) ;
}
goto V_222;
}
if ( V_8 -> V_90 & V_225 ) {
F_130 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_164 ) {
F_131 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_91 ) {
F_132 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_133 ) {
F_133 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_124 ) {
F_134 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_143 ) {
F_135 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_125 ) {
F_136 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_153 ) {
F_137 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_156 ) {
F_138 ( V_8 ) ;
goto V_222;
}
if ( V_8 -> V_90 & V_226 ) {
F_112 ( V_8 ) ;
V_8 -> V_90 &= ~ V_226 ;
goto V_222;
}
if ( V_8 -> V_93 == V_155 )
F_139 ( V_8 ) ;
V_222:
if ( V_8 -> V_93 == V_155 ) {
F_22 ( V_8 , ~ 0 ) ;
F_24 ( V_8 , 0xFF ) ;
} else {
F_24 ( V_8 , 0x1 ) ;
}
F_56 ( V_117 , & V_8 -> V_118 ) ;
V_216:
if ( V_8 -> V_93 == V_227 )
return;
if ( V_8 -> V_90 )
F_140 ( & V_8 -> V_157 ,
V_158 + F_141 ( 20 ) ) ;
else
F_140 ( & V_8 -> V_157 , V_158 + ( V_228 * 2 ) ) ;
F_14 ( & V_8 -> V_52 ) ;
}
static void F_142 ( struct V_213 * V_214 )
{
struct V_7 * V_8 = F_125 ( V_214 ,
struct V_7 ,
V_30 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_114 * V_229 ;
struct V_130 * V_116 ;
T_3 V_215 ;
int V_39 = 0 , V_87 ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) )
F_82 ( 500 , 1000 ) ;
F_15 ( V_8 ) ;
if ( V_8 -> V_27 & V_29 ) {
V_8 -> V_27 &= ~ V_29 ;
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_8 ) ;
}
V_8 -> V_27 |= V_28 ;
for ( V_39 = 0 ; V_39 < V_230 ; V_39 ++ ) {
V_215 = F_17 ( V_2 , V_223 ) &
V_224 ;
if ( ! V_215 )
break;
F_82 ( 5000 , 10000 ) ;
}
if ( V_39 == V_230 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
goto V_231;
}
for ( V_39 = 0 ; V_39 < V_230 ; V_39 ++ ) {
V_215 = F_17 ( V_2 , V_32 ) &
V_217 ;
if ( V_215 == V_218 )
break;
F_146 ( V_232 ) ;
}
F_146 ( V_232 ) ;
if ( V_39 == V_230 ) {
struct V_130 * V_144 ;
struct V_114 * V_233 , * V_234 ;
F_42 ( & V_8 -> V_12 -> V_13 , L_26 ,
V_215 ) ;
V_8 -> V_27 |= V_160 ;
if ( F_147 ( V_8 -> V_25 ) ) {
F_148 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_83 ( V_25 ) ;
F_84 ( V_25 ) ;
F_74 ( V_8 ) ;
F_20 ( V_8 ) ;
F_43 ( V_8 ) ;
F_149 ( V_8 ) ;
F_150 ( V_8 ) ;
}
F_70 (f, ftmp, &adapter->mac_filter_list,
list) {
F_151 ( & V_116 -> V_121 ) ;
F_9 ( V_116 ) ;
}
F_70 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_151 ( & V_233 -> V_121 ) ;
F_9 ( V_233 ) ;
}
F_44 ( V_8 ) ;
F_119 ( V_8 ) ;
F_87 ( V_8 ) ;
F_118 ( V_8 ) ;
F_9 ( V_8 -> V_177 ) ;
F_143 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_235 ;
F_56 ( V_117 , & V_8 -> V_118 ) ;
V_8 -> V_27 &= ~ V_28 ;
F_37 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
return;
}
V_231:
if ( F_147 ( V_8 -> V_25 ) ) {
F_83 ( V_25 ) ;
F_152 ( V_25 ) ;
F_74 ( V_8 ) ;
}
F_20 ( V_8 ) ;
V_8 -> V_93 = V_161 ;
V_8 -> V_27 &= ~ V_28 ;
F_150 ( V_8 ) ;
F_149 ( V_8 ) ;
if ( F_143 ( V_2 ) )
F_153 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_8 -> V_162 = V_163 ;
V_87 = F_144 ( V_2 ) ;
if ( V_87 )
F_37 ( & V_8 -> V_12 -> V_13 , L_29 ,
V_87 ) ;
V_8 -> V_90 = V_225 ;
V_8 -> V_90 |= V_91 ;
F_50 (f, &adapter->mac_filter_list, list) {
V_116 -> V_123 = true ;
}
F_50 (vlf, &adapter->vlan_filter_list, list) {
V_229 -> V_123 = true ;
}
V_8 -> V_90 |= V_133 ;
V_8 -> V_90 |= V_124 ;
F_56 ( V_117 , & V_8 -> V_118 ) ;
F_19 ( V_8 ) ;
F_140 ( & V_8 -> V_157 , V_158 + 2 ) ;
if ( F_147 ( V_8 -> V_25 ) ) {
V_87 = F_154 ( V_8 ) ;
if ( V_87 )
goto V_236;
V_87 = F_155 ( V_8 ) ;
if ( V_87 )
goto V_236;
F_76 ( V_8 ) ;
V_87 = F_79 ( V_8 ) ;
if ( V_87 )
goto V_236;
F_25 ( V_8 , true ) ;
} else {
V_8 -> V_93 = V_159 ;
}
return;
V_236:
F_42 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
F_156 ( V_8 -> V_25 ) ;
}
static void F_157 ( struct V_213 * V_214 )
{
struct V_7 * V_8 =
F_125 ( V_214 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_237 V_238 ;
struct V_239 * V_240 ;
T_1 V_185 ;
T_3 V_49 , V_241 ;
T_6 V_242 ;
if ( V_8 -> V_27 & V_160 )
goto V_89;
V_238 . V_243 = V_244 ;
V_238 . V_245 = F_7 ( V_238 . V_243 , V_16 ) ;
if ( ! V_238 . V_245 )
goto V_89;
V_240 = (struct V_239 * ) & V_238 . V_246 ;
do {
V_185 = F_158 ( V_2 , & V_238 , & V_242 ) ;
if ( V_185 || ! V_240 -> V_247 )
break;
F_159 ( V_8 , V_240 -> V_247 ,
V_240 -> V_248 , V_238 . V_245 ,
V_238 . V_249 ) ;
if ( V_242 != 0 )
memset ( V_238 . V_245 , 0 , V_244 ) ;
} while ( V_242 );
if ( ( V_8 -> V_27 &
( V_28 | V_29 ) ) ||
V_8 -> V_93 == V_161 )
goto V_250;
V_49 = F_17 ( V_2 , V_2 -> V_191 . V_251 . V_252 ) ;
V_241 = V_49 ;
if ( V_49 & V_253 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_253 ;
}
if ( V_49 & V_254 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_254 ;
}
if ( V_49 & V_255 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_255 ;
}
if ( V_241 != V_49 )
F_16 ( V_2 , V_2 -> V_191 . V_251 . V_252 , V_49 ) ;
V_49 = F_17 ( V_2 , V_2 -> V_191 . V_256 . V_252 ) ;
V_241 = V_49 ;
if ( V_49 & V_257 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_34 ) ;
V_49 &= ~ V_257 ;
}
if ( V_49 & V_258 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_35 ) ;
V_49 &= ~ V_258 ;
}
if ( V_49 & V_259 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_36 ) ;
V_49 &= ~ V_259 ;
}
if ( V_241 != V_49 )
F_16 ( V_2 , V_2 -> V_191 . V_256 . V_252 , V_49 ) ;
V_250:
F_9 ( V_238 . V_245 ) ;
V_89:
F_19 ( V_8 ) ;
}
void F_149 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_75 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_75 [ V_39 ] . V_246 )
F_160 ( & V_8 -> V_75 [ V_39 ] ) ;
}
static int F_154 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_75 [ V_39 ] . V_68 = V_8 -> V_171 ;
V_87 = F_161 ( & V_8 -> V_75 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_42 ( & V_8 -> V_12 -> V_13 ,
L_37 , V_39 ) ;
break;
}
return V_87 ;
}
static int F_155 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_68 = V_8 -> V_174 ;
V_87 = F_162 ( & V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_42 ( & V_8 -> V_12 -> V_13 ,
L_38 , V_39 ) ;
break;
}
return V_87 ;
}
void F_150 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_65 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] . V_246 )
F_163 ( & V_8 -> V_65 [ V_39 ] ) ;
}
static int F_164 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_87 ;
if ( V_8 -> V_27 & V_160 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_39 ) ;
return - V_128 ;
}
if ( V_8 -> V_93 != V_159 || V_8 -> V_90 )
return - V_188 ;
V_87 = F_154 ( V_8 ) ;
if ( V_87 )
goto V_260;
V_87 = F_155 ( V_8 ) ;
if ( V_87 )
goto V_261;
V_87 = F_35 ( V_8 , V_25 -> V_97 ) ;
if ( V_87 )
goto V_262;
F_63 ( V_8 , V_8 -> V_2 . V_142 . V_136 ) ;
F_76 ( V_8 ) ;
V_87 = F_79 ( V_8 ) ;
if ( V_87 )
goto V_262;
F_25 ( V_8 , true ) ;
return 0 ;
V_262:
F_81 ( V_8 ) ;
F_43 ( V_8 ) ;
V_261:
F_150 ( V_8 ) ;
V_260:
F_149 ( V_8 ) ;
return V_87 ;
}
static int F_156 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_93 <= V_159 )
return 0 ;
F_148 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_81 ( V_8 ) ;
V_8 -> V_93 = V_159 ;
F_43 ( V_8 ) ;
return 0 ;
}
static struct V_263 * F_165 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_264 ;
}
static int F_166 ( struct V_24 * V_25 , int V_265 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_103 = V_265 + V_105 + V_106 ;
if ( ( V_265 < 68 ) || ( V_103 > V_266 ) )
return - V_187 ;
V_25 -> V_104 = V_265 ;
V_8 -> V_27 |= V_29 ;
F_14 ( & V_8 -> V_30 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 )
{
T_3 V_267 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_267 = F_17 ( V_2 , V_32 ) &
V_217 ;
if ( ( V_267 == V_218 ) ||
( V_267 == V_219 ) )
return 0 ;
F_82 ( 10 , 20 ) ;
}
return - V_188 ;
}
int F_168 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_177 -> V_268 ; V_39 ++ ) {
if ( V_8 -> V_177 -> V_168 [ V_39 ] . V_269 == V_270 )
V_8 -> V_168 = & V_8 -> V_177 -> V_168 [ V_39 ] ;
}
if ( ! V_8 -> V_168 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_40 ) ;
return - V_271 ;
}
if ( V_8 -> V_177 -> V_272
& V_273 ) {
V_25 -> V_274 = V_25 -> V_275 &
~ ( V_276 |
V_277 |
V_278 ) ;
V_25 -> V_275 |= V_276 |
V_277 |
V_278 ;
}
V_25 -> V_275 |= V_279 |
V_280 |
V_281 |
V_282 |
V_283 |
V_284 |
V_285 |
V_286 |
V_287 ;
V_25 -> V_288 |= V_25 -> V_275 ;
V_25 -> V_288 &= ~ V_286 ;
V_8 -> V_67 . V_186 = V_8 -> V_168 -> V_289 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_290 = 1 ;
V_8 -> V_67 . V_291 = V_292 ;
V_8 -> V_67 . V_293 = ( V_294 |
F_169 ( V_295 ) ) ;
V_8 -> V_67 . V_296 = ( V_294 |
F_169 ( V_297 ) ) ;
V_8 -> V_67 . V_25 = V_8 -> V_25 ;
V_8 -> V_67 . V_298 = V_8 -> V_168 -> V_299 ;
return 0 ;
}
static void F_170 ( struct V_213 * V_214 )
{
struct V_7 * V_8 = F_125 ( V_214 ,
struct V_7 ,
V_221 . V_214 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_300 * V_12 = V_8 -> V_12 ;
int V_87 , V_301 ;
switch ( V_8 -> V_93 ) {
case V_220 :
V_8 -> V_27 &= ~ V_160 ;
V_8 -> V_27 &= ~ V_28 ;
V_87 = F_171 ( V_2 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_41 ,
V_87 ) ;
goto V_87;
}
V_87 = F_167 ( V_2 ) ;
if ( V_87 ) {
F_37 ( & V_12 -> V_13 , L_42 ,
V_87 ) ;
goto V_87;
}
V_2 -> V_191 . V_302 = V_303 ;
V_2 -> V_191 . V_304 = V_303 ;
V_2 -> V_191 . V_305 = V_244 ;
V_2 -> V_191 . V_306 = V_244 ;
V_87 = F_144 ( V_2 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_43 ,
V_87 ) ;
goto V_87;
}
V_87 = F_129 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_44 , V_87 ) ;
F_143 ( V_2 ) ;
goto V_87;
}
V_8 -> V_93 = V_307 ;
goto V_308;
case V_307 :
if ( ! F_127 ( V_2 ) ) {
F_42 ( & V_12 -> V_13 , L_45 ) ;
F_143 ( V_2 ) ;
V_8 -> V_93 = V_220 ;
goto V_87;
}
V_87 = F_172 ( V_8 ) ;
if ( V_87 ) {
if ( V_87 == V_309 )
V_87 = F_129 ( V_8 ) ;
else
F_42 ( & V_12 -> V_13 , L_46 ,
V_8 -> V_310 . V_311 ,
V_8 -> V_310 . V_312 ,
V_313 ,
V_314 ) ;
goto V_87;
}
V_87 = F_130 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_47 ,
V_87 ) ;
goto V_87;
}
V_8 -> V_93 = V_315 ;
goto V_308;
case V_315 :
if ( ! V_8 -> V_177 ) {
V_301 = sizeof( struct V_316 ) +
( V_317 *
sizeof( struct V_318 ) ) ;
V_8 -> V_177 = F_7 ( V_301 , V_16 ) ;
if ( ! V_8 -> V_177 )
goto V_87;
}
V_87 = F_173 ( V_8 ) ;
if ( V_87 == V_309 ) {
V_87 = F_130 ( V_8 ) ;
goto V_87;
} else if ( V_87 == V_10 ) {
F_143 ( V_2 ) ;
F_42 ( & V_12 -> V_13 , L_48 ) ;
return;
}
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_49 ,
V_87 ) ;
goto V_319;
}
V_8 -> V_93 = V_320 ;
break;
default:
goto V_319;
}
if ( F_168 ( V_8 ) )
goto V_319;
V_8 -> V_162 = V_163 ;
V_8 -> V_27 |= V_321 ;
V_25 -> V_322 = & V_323 ;
F_174 ( V_25 ) ;
V_25 -> V_324 = 5 * V_228 ;
if ( ! F_66 ( V_8 -> V_2 . V_142 . V_136 ) ) {
F_37 ( & V_12 -> V_13 , L_50 ,
V_8 -> V_2 . V_142 . V_136 ) ;
F_175 ( V_25 ) ;
F_64 ( V_8 -> V_2 . V_142 . V_136 , V_25 -> V_139 ) ;
} else {
V_8 -> V_27 |= V_140 ;
F_64 ( V_25 -> V_139 , V_8 -> V_2 . V_142 . V_136 ) ;
F_64 ( V_25 -> V_325 , V_8 -> V_2 . V_142 . V_136 ) ;
}
F_176 ( & V_8 -> V_157 ) ;
V_8 -> V_157 . V_326 = & F_123 ;
V_8 -> V_157 . V_48 = ( unsigned long ) V_8 ;
F_140 ( & V_8 -> V_157 , V_158 + 1 ) ;
V_8 -> V_82 = F_91 ( int ,
V_8 -> V_168 -> V_327 ,
( int ) ( F_92 () ) ) ;
V_8 -> V_171 = V_328 ;
V_8 -> V_174 = V_329 ;
V_87 = F_121 ( V_8 ) ;
if ( V_87 )
goto V_330;
F_31 ( V_8 ) ;
if ( V_8 -> V_177 -> V_272 &
V_331 )
V_8 -> V_27 |= V_332 ;
if ( ! F_109 ( V_8 ) )
F_112 ( V_8 ) ;
V_87 = F_40 ( V_8 ) ;
if ( V_87 )
goto V_330;
F_83 ( V_25 ) ;
if ( ! V_8 -> V_333 ) {
V_87 = F_177 ( V_25 ) ;
if ( V_87 )
goto V_334;
}
V_8 -> V_333 = true ;
F_152 ( V_25 ) ;
F_37 ( & V_12 -> V_13 , L_51 , V_8 -> V_2 . V_142 . V_136 ) ;
if ( V_25 -> V_275 & V_287 )
F_37 ( & V_12 -> V_13 , L_52 ) ;
V_8 -> V_93 = V_159 ;
F_148 ( V_92 , & V_8 -> V_67 . V_93 ) ;
F_19 ( V_8 ) ;
if ( F_109 ( V_8 ) ) {
V_8 -> V_90 |= V_226 ;
F_80 ( & V_8 -> V_157 , V_158 + 1 ) ;
} else {
F_112 ( V_8 ) ;
}
return;
V_308:
F_126 ( & V_8 -> V_221 , F_141 ( 30 ) ) ;
return;
V_334:
F_44 ( V_8 ) ;
V_330:
F_119 ( V_8 ) ;
V_319:
F_9 ( V_8 -> V_177 ) ;
V_8 -> V_177 = NULL ;
V_87:
if ( ++ V_8 -> V_335 > V_336 ) {
F_42 ( & V_12 -> V_13 , L_53 ) ;
V_8 -> V_27 |= V_160 ;
F_143 ( V_2 ) ;
V_8 -> V_93 = V_220 ;
F_126 ( & V_8 -> V_221 , V_228 * 5 ) ;
return;
}
F_126 ( & V_8 -> V_221 , V_228 ) ;
}
static void F_178 ( struct V_300 * V_12 )
{
struct V_24 * V_25 = F_179 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_180 ( V_25 ) ;
if ( F_147 ( V_25 ) )
F_156 ( V_25 ) ;
V_8 -> V_93 = V_227 ;
V_8 -> V_90 = 0 ;
#ifdef F_181
F_182 ( V_12 ) ;
#endif
F_183 ( V_12 ) ;
}
static int F_184 ( struct V_300 * V_12 , const struct V_337 * V_338 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_87 ;
V_87 = F_185 ( V_12 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_186 ( & V_12 -> V_13 , F_187 ( 64 ) ) ;
if ( V_87 ) {
V_87 = F_186 ( & V_12 -> V_13 , F_187 ( 32 ) ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 ,
L_54 , V_87 ) ;
goto V_339;
}
}
V_87 = F_188 ( V_12 , V_340 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 ,
L_55 , V_87 ) ;
goto V_341;
}
F_189 ( V_12 ) ;
F_190 ( V_12 ) ;
V_25 = F_191 ( sizeof( struct V_7 ) , V_342 ) ;
if ( ! V_25 ) {
V_87 = - V_129 ;
goto V_343;
}
F_192 ( V_25 , & V_12 -> V_13 ) ;
F_193 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_344 = F_23 ( V_345 ) - 1 ;
V_8 -> V_93 = V_220 ;
F_182 ( V_12 ) ;
V_2 -> V_102 = F_194 ( F_195 ( V_12 , 0 ) ,
F_196 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_102 ) {
V_87 = - V_128 ;
goto V_346;
}
V_2 -> V_347 = V_12 -> V_348 ;
V_2 -> V_349 = V_12 -> V_350 ;
F_197 ( V_12 , V_351 , & V_2 -> V_352 ) ;
V_2 -> V_353 = V_12 -> V_354 ;
V_2 -> V_355 = V_12 -> V_356 ;
V_2 -> V_357 . V_350 = F_198 ( V_12 -> V_358 ) ;
V_2 -> V_357 . V_359 = F_199 ( V_12 -> V_358 ) ;
F_200 ( & V_2 -> V_191 . V_360 ) ;
F_200 ( & V_2 -> V_191 . V_361 ) ;
F_54 ( & V_8 -> V_132 ) ;
F_54 ( & V_8 -> V_122 ) ;
F_201 ( & V_8 -> V_30 , F_142 ) ;
F_201 ( & V_8 -> V_52 , F_157 ) ;
F_201 ( & V_8 -> V_212 , F_124 ) ;
F_202 ( & V_8 -> V_221 , F_170 ) ;
F_126 ( & V_8 -> V_221 ,
F_141 ( 5 * ( V_12 -> V_358 & 0x07 ) ) ) ;
return 0 ;
V_346:
F_203 ( V_25 ) ;
V_343:
F_204 ( V_12 ) ;
V_341:
V_339:
F_183 ( V_12 ) ;
return V_87 ;
}
static int F_205 ( struct V_300 * V_12 , T_10 V_93 )
{
struct V_24 * V_25 = F_179 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_362 = 0 ;
F_180 ( V_25 ) ;
if ( F_147 ( V_25 ) ) {
F_206 () ;
F_81 ( V_8 ) ;
F_207 () ;
}
F_44 ( V_8 ) ;
F_119 ( V_8 ) ;
V_362 = F_182 ( V_12 ) ;
if ( V_362 )
return V_362 ;
F_183 ( V_12 ) ;
return 0 ;
}
static int F_208 ( struct V_300 * V_12 )
{
struct V_7 * V_8 = F_179 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_87 ;
F_209 ( V_12 , V_363 ) ;
F_210 ( V_12 ) ;
F_182 ( V_12 ) ;
V_87 = F_211 ( V_12 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_56 ) ;
return V_87 ;
}
F_190 ( V_12 ) ;
F_206 () ;
V_87 = F_90 ( V_8 ) ;
if ( V_87 ) {
F_207 () ;
F_42 ( & V_12 -> V_13 , L_57 ) ;
return V_87 ;
}
V_87 = F_40 ( V_8 ) ;
F_207 () ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_58 ) ;
return V_87 ;
}
F_14 ( & V_8 -> V_30 ) ;
F_212 ( V_25 ) ;
return V_87 ;
}
static void F_213 ( struct V_300 * V_12 )
{
struct V_24 * V_25 = F_179 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_130 * V_116 , * V_144 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_214 ( & V_8 -> V_221 ) ;
F_215 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_333 ) {
F_216 ( V_25 ) ;
V_8 -> V_333 = false ;
}
V_8 -> V_93 = V_227 ;
V_8 -> V_90 = 0 ;
F_145 ( V_8 ) ;
F_146 ( 20 ) ;
if ( ! F_127 ( V_2 ) ) {
F_145 ( V_8 ) ;
F_146 ( 20 ) ;
}
if ( V_8 -> V_33 ) {
F_15 ( V_8 ) ;
F_44 ( V_8 ) ;
F_119 ( V_8 ) ;
F_118 ( V_8 ) ;
}
if ( V_8 -> V_157 . V_326 )
F_217 ( & V_8 -> V_157 ) ;
F_218 () ;
F_122 ( & V_8 -> V_67 ) ;
if ( V_2 -> V_191 . V_256 . V_68 )
F_143 ( V_2 ) ;
F_219 ( & V_2 -> V_191 . V_361 ) ;
F_219 ( & V_2 -> V_191 . V_360 ) ;
F_220 ( V_2 -> V_102 ) ;
F_204 ( V_12 ) ;
F_149 ( V_8 ) ;
F_150 ( V_8 ) ;
F_87 ( V_8 ) ;
F_9 ( V_8 -> V_177 ) ;
F_70 (f, ftmp, &adapter->mac_filter_list, list) {
F_151 ( & V_116 -> V_121 ) ;
F_9 ( V_116 ) ;
}
F_70 (f, ftmp, &adapter->vlan_filter_list, list) {
F_151 ( & V_116 -> V_121 ) ;
F_9 ( V_116 ) ;
}
F_203 ( V_25 ) ;
F_221 ( V_12 ) ;
F_183 ( V_12 ) ;
}
static int T_11 F_222 ( void )
{
int V_185 ;
F_11 ( L_59 , V_364 ,
V_365 ) ;
F_11 ( L_60 , V_366 ) ;
V_185 = F_223 ( & V_367 ) ;
return V_185 ;
}
static void T_12 F_224 ( void )
{
F_225 ( & V_367 ) ;
}
