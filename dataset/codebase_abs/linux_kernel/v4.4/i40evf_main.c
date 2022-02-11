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
F_17 ( V_2 , V_50 ) ;
F_17 ( V_2 , V_37 ) ;
V_49 = F_17 ( V_2 , V_31 ) |
V_51 ;
F_16 ( V_2 , V_31 , V_49 ) ;
F_14 ( & V_8 -> V_52 ) ;
return V_53 ;
}
static T_6 F_27 ( int V_47 , void * V_48 )
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
struct V_54 * V_55 = V_8 -> V_55 [ V_60 ] ;
struct V_62 * V_63 = V_8 -> V_64 [ V_61 ] ;
V_63 -> V_55 = V_55 ;
V_63 -> V_65 = V_55 -> V_58 . V_57 ;
V_63 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_58 . V_57 = V_63 ;
V_55 -> V_58 . V_67 ++ ;
V_55 -> V_58 . V_68 = V_69 ;
V_55 -> V_70 = V_71 ;
}
static void
F_30 ( struct V_7 * V_8 , int V_60 , int V_72 )
{
struct V_54 * V_55 = V_8 -> V_55 [ V_60 ] ;
struct V_62 * V_73 = V_8 -> V_74 [ V_72 ] ;
V_73 -> V_55 = V_55 ;
V_73 -> V_65 = V_55 -> V_56 . V_57 ;
V_73 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_56 . V_57 = V_73 ;
V_55 -> V_56 . V_67 ++ ;
V_55 -> V_56 . V_68 = V_69 ;
V_55 -> V_70 = V_71 ;
V_55 -> V_75 ++ ;
V_55 -> V_76 |= F_23 ( V_72 ) ;
}
static int F_31 ( struct V_7 * V_8 )
{
int V_77 ;
int V_78 = 0 ;
int V_79 = 0 , V_80 = 0 ;
int V_81 = V_8 -> V_82 ;
int V_83 = V_8 -> V_82 ;
int V_39 , V_84 ;
int V_85 , V_86 ;
int V_87 = 0 ;
V_77 = V_8 -> V_40 - V_88 ;
if ( V_77 >= ( V_81 * 2 ) ) {
for (; V_79 < V_81 ; V_78 ++ , V_79 ++ )
F_29 ( V_8 , V_78 , V_79 ) ;
for (; V_80 < V_83 ; V_78 ++ , V_80 ++ )
F_30 ( V_8 , V_78 , V_80 ) ;
goto V_89;
}
for ( V_39 = V_78 ; V_39 < V_77 ; V_39 ++ ) {
V_85 = F_32 ( V_81 , V_77 - V_39 ) ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ ) {
F_29 ( V_8 , V_39 , V_79 ) ;
V_79 ++ ;
V_81 -- ;
}
}
for ( V_39 = V_78 ; V_39 < V_77 ; V_39 ++ ) {
V_86 = F_32 ( V_83 , V_77 - V_39 ) ;
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
int V_77 = V_8 -> V_40 - V_88 ;
int V_39 ;
if ( F_34 ( V_92 , & V_8 -> V_66 . V_93 ) )
return;
for ( V_39 = 0 ; V_39 < V_77 ; V_39 ++ )
F_27 ( 0 , V_8 -> V_55 [ V_39 ] ) ;
}
static int
F_35 ( struct V_7 * V_8 , char * V_94 )
{
int V_34 , V_87 , V_77 ;
int V_95 = 0 , V_96 = 0 ;
F_20 ( V_8 ) ;
V_77 = V_8 -> V_40 - V_88 ;
for ( V_34 = 0 ; V_34 < V_77 ; V_34 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_34 ] ;
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
V_8 -> V_55 [ V_34 ] ) ;
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
int V_77 ;
V_77 = V_8 -> V_40 - V_88 ;
for ( V_39 = 0 ; V_39 < V_77 ; V_39 ++ ) {
F_38 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
NULL ) ;
F_39 ( V_8 -> V_33 [ V_39 + 1 ] . V_34 ,
V_8 -> V_55 [ V_39 ] ) ;
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
V_8 -> V_74 [ V_39 ] -> V_101 = V_2 -> V_102 + F_46 ( V_39 ) ;
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
V_8 -> V_64 [ V_39 ] -> V_101 = V_2 -> V_102 + F_48 ( V_39 ) ;
V_8 -> V_64 [ V_39 ] -> V_107 = V_107 ;
}
}
static struct
V_114 * F_49 ( struct V_7 * V_8 , T_7 V_115 )
{
struct V_114 * V_116 ;
F_50 (f, &adapter->vlan_filter_list, list) {
if ( V_115 == V_116 -> V_115 )
return V_116 ;
}
return NULL ;
}
static struct
V_114 * F_51 ( struct V_7 * V_8 , T_7 V_115 )
{
struct V_114 * V_116 = NULL ;
int V_67 = 50 ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_67 == 0 )
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
static void F_57 ( struct V_7 * V_8 , T_7 V_115 )
{
struct V_114 * V_116 ;
int V_67 = 50 ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_67 == 0 )
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
T_8 T_9 V_126 , T_7 V_127 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( ! F_59 ( V_8 ) )
return - V_128 ;
if ( F_51 ( V_8 , V_127 ) == NULL )
return - V_129 ;
return 0 ;
}
static int F_60 ( struct V_24 * V_25 ,
T_8 T_9 V_126 , T_7 V_127 )
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
T_10 * V_131 )
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
T_10 * V_131 )
{
struct V_130 * V_116 ;
int V_67 = 50 ;
if ( ! V_131 )
return NULL ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_67 == 0 )
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
int V_67 = 50 ;
F_68 (uca, netdev) {
F_63 ( V_8 , V_146 -> V_136 ) ;
}
F_69 (mca, netdev) {
F_63 ( V_8 , V_147 -> V_136 ) ;
}
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) ) {
F_53 ( 1 ) ;
if ( -- V_67 == 0 ) {
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
int V_77 = V_8 -> V_40 - V_88 ;
for ( V_151 = 0 ; V_151 < V_77 ; V_151 ++ ) {
struct V_152 * V_59 ;
V_55 = V_8 -> V_55 [ V_151 ] ;
V_59 = & V_55 -> V_59 ;
F_73 ( V_59 ) ;
}
}
static void F_74 ( struct V_7 * V_8 )
{
int V_151 ;
struct V_54 * V_55 ;
int V_77 = V_8 -> V_40 - V_88 ;
for ( V_151 = 0 ; V_151 < V_77 ; V_151 ++ ) {
V_55 = V_8 -> V_55 [ V_151 ] ;
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
struct V_62 * V_57 = V_8 -> V_64 [ V_39 ] ;
F_77 ( V_57 , V_57 -> V_67 ) ;
V_57 -> V_154 = V_57 -> V_67 - 1 ;
F_78 ( V_57 -> V_154 , V_57 -> V_101 ) ;
}
}
static int F_79 ( struct V_7 * V_8 )
{
V_8 -> V_93 = V_155 ;
F_56 ( V_92 , & V_8 -> V_66 . V_93 ) ;
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
int V_39 ;
if ( ! V_8 -> V_168 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
if ( V_8 -> V_74 [ V_39 ] )
F_88 ( V_8 -> V_74 [ V_39 ] , V_169 ) ;
V_8 -> V_74 [ V_39 ] = NULL ;
V_8 -> V_64 [ V_39 ] = NULL ;
}
}
static int F_89 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
struct V_62 * V_73 ;
struct V_62 * V_63 ;
V_73 = F_7 ( sizeof( * V_73 ) * 2 , V_16 ) ;
if ( ! V_73 )
goto V_170;
V_73 -> V_171 = V_39 ;
V_73 -> V_25 = V_8 -> V_25 ;
V_73 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_73 -> V_67 = V_8 -> V_172 ;
if ( V_8 -> V_27 & V_173 )
V_73 -> V_27 |= V_174 ;
V_8 -> V_74 [ V_39 ] = V_73 ;
V_63 = & V_73 [ 1 ] ;
V_63 -> V_171 = V_39 ;
V_63 -> V_25 = V_8 -> V_25 ;
V_63 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_63 -> V_67 = V_8 -> V_175 ;
V_8 -> V_64 [ V_39 ] = V_63 ;
}
return 0 ;
V_170:
F_87 ( V_8 ) ;
return - V_129 ;
}
static int F_90 ( struct V_7 * V_8 )
{
int V_34 , V_176 ;
int V_177 = 0 ;
int V_87 = 0 ;
if ( ! V_8 -> V_168 ) {
V_87 = - V_128 ;
goto V_89;
}
V_177 = V_8 -> V_82 ;
V_176 = F_91 ( int , V_177 , ( int ) ( F_92 () * 2 ) ) + V_88 ;
V_176 = F_91 ( int , V_176 , ( int ) V_8 -> V_178 -> V_179 ) ;
V_8 -> V_33 = F_93 ( V_176 ,
sizeof( struct V_180 ) , V_16 ) ;
if ( ! V_8 -> V_33 ) {
V_87 = - V_129 ;
goto V_89;
}
for ( V_34 = 0 ; V_34 < V_176 ; V_34 ++ )
V_8 -> V_33 [ V_34 ] . V_181 = V_34 ;
V_87 = F_85 ( V_8 , V_176 ) ;
V_89:
V_8 -> V_25 -> V_182 = V_177 ;
return V_87 ;
}
static void F_94 ( struct V_183 * V_66 , const T_10 * V_184 )
{
struct V_185 V_186 ;
struct V_7 * V_8 = V_66 -> V_9 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_187 = 0 , V_39 ;
T_10 * V_188 ;
if ( ! V_66 -> V_189 )
return;
if ( V_8 -> V_162 != V_163 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_162 ) ;
return;
}
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
memcpy ( & V_186 , V_184 , sizeof( V_186 ) ) ;
V_188 = F_7 ( ( ( V_190 + 1 ) * 4 ) , V_16 ) ;
if ( ! V_188 )
return;
for ( V_39 = 0 ; V_39 <= ( V_190 * 4 ) ; V_39 ++ )
V_188 [ V_39 ] = V_39 % V_8 -> V_82 ;
V_187 = F_95 ( V_2 , V_66 -> V_189 , & V_186 ) ;
if ( V_187 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_12 ,
F_96 ( V_2 , V_187 ) ,
F_97 ( V_2 , V_2 -> V_191 . V_192 ) ) ;
return;
}
V_187 = F_98 ( V_2 , V_66 -> V_189 , false , V_188 ,
( V_190 + 1 ) * 4 ) ;
if ( V_187 )
F_42 ( & V_8 -> V_12 -> V_13 ,
L_13 ,
F_96 ( V_2 , V_187 ) ,
F_97 ( V_2 , V_2 -> V_191 . V_192 ) ) ;
}
static void F_99 ( struct V_7 * V_8 ,
const T_10 * V_184 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 * V_193 = ( T_3 * ) V_184 ;
T_3 V_194 = 0 ;
T_3 V_195 = 0 ;
int V_39 , V_84 ;
for ( V_39 = 0 ; V_39 <= V_196 ; V_39 ++ )
F_16 ( V_2 , F_100 ( V_39 ) , V_193 [ V_39 ] ) ;
for ( V_39 = 0 ; V_39 <= V_190 ; V_39 ++ ) {
V_195 = 0 ;
for ( V_84 = 0 ; V_84 < 4 ; V_84 ++ ) {
if ( V_194 == V_8 -> V_82 )
V_194 = 0 ;
V_195 |= ( ( V_194 ) << ( 8 * V_84 ) ) ;
V_194 ++ ;
}
F_16 ( V_2 , F_101 ( V_39 ) , V_195 ) ;
}
F_102 ( V_2 ) ;
}
static void F_103 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_10 V_184 [ V_197 ] ;
T_2 V_198 ;
F_104 ( ( void * ) V_184 , V_197 ) ;
V_198 = V_199 ;
F_16 ( V_2 , F_105 ( 0 ) , ( T_3 ) V_198 ) ;
F_16 ( V_2 , F_105 ( 1 ) , ( T_3 ) ( V_198 >> 32 ) ) ;
if ( F_106 ( V_8 ) )
F_94 ( & V_8 -> V_66 , V_184 ) ;
else
F_99 ( V_8 , V_184 ) ;
}
static int F_107 ( struct V_7 * V_8 )
{
int V_151 , V_200 ;
struct V_54 * V_55 ;
V_200 = V_8 -> V_40 - V_88 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
V_55 = F_7 ( sizeof( * V_55 ) , V_16 ) ;
if ( ! V_55 )
goto V_170;
V_55 -> V_8 = V_8 ;
V_55 -> V_66 = & V_8 -> V_66 ;
V_55 -> V_60 = V_151 ;
F_108 ( V_8 -> V_25 , & V_55 -> V_59 ,
V_201 , V_202 ) ;
V_8 -> V_55 [ V_151 ] = V_55 ;
}
return 0 ;
V_170:
while ( V_151 ) {
V_151 -- ;
V_55 = V_8 -> V_55 [ V_151 ] ;
F_109 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
V_8 -> V_55 [ V_151 ] = NULL ;
}
return - V_129 ;
}
static void F_110 ( struct V_7 * V_8 )
{
int V_151 , V_200 ;
int V_203 ;
V_200 = V_8 -> V_40 - V_88 ;
V_203 = V_8 -> V_82 ;
for ( V_151 = 0 ; V_151 < V_200 ; V_151 ++ ) {
struct V_54 * V_55 = V_8 -> V_55 [ V_151 ] ;
V_8 -> V_55 [ V_151 ] = NULL ;
if ( V_151 < V_203 )
F_109 ( & V_55 -> V_59 ) ;
F_9 ( V_55 ) ;
}
}
void F_111 ( struct V_7 * V_8 )
{
F_112 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
int F_113 ( struct V_7 * V_8 )
{
int V_87 ;
V_87 = F_90 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_204;
}
V_87 = F_107 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_205;
}
V_87 = F_89 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_206;
}
F_37 ( & V_8 -> V_12 -> V_13 , L_17 ,
( V_8 -> V_82 > 1 ) ? L_18 : L_19 ,
V_8 -> V_82 ) ;
return 0 ;
V_206:
F_110 ( V_8 ) ;
V_205:
F_111 ( V_8 ) ;
V_204:
return V_87 ;
}
static void F_114 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_14 ( & V_8 -> V_207 ) ;
}
static void F_115 ( struct V_208 * V_209 )
{
struct V_7 * V_8 = F_116 ( V_209 ,
struct V_7 ,
V_207 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_210 ;
if ( F_52 ( V_117 , & V_8 -> V_118 ) )
goto V_211;
if ( V_8 -> V_27 & V_160 ) {
V_210 = F_17 ( V_2 , V_32 ) &
V_212 ;
if ( ( V_210 == V_213 ) ||
( V_210 == V_214 ) ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_93 = V_215 ;
V_8 -> V_27 &= ~ V_160 ;
F_117 ( & V_8 -> V_216 , 10 ) ;
F_56 ( V_117 ,
& V_8 -> V_118 ) ;
return;
}
V_8 -> V_90 = 0 ;
V_8 -> V_162 = V_163 ;
goto V_217;
}
if ( ( V_8 -> V_93 < V_159 ) ||
( V_8 -> V_27 & V_28 ) )
goto V_217;
V_210 = F_17 ( V_2 , V_218 ) & V_219 ;
if ( ! ( V_8 -> V_27 & V_28 ) && ! V_210 ) {
V_8 -> V_93 = V_161 ;
V_8 -> V_27 |= V_28 ;
F_42 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_14 ( & V_8 -> V_30 ) ;
V_8 -> V_90 = 0 ;
V_8 -> V_162 = V_163 ;
goto V_217;
}
if ( V_8 -> V_162 ) {
if ( ! F_118 ( V_2 ) ) {
F_119 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_120 ( V_8 ) ;
}
goto V_217;
}
if ( V_8 -> V_90 & V_220 ) {
F_121 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_164 ) {
F_122 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_91 ) {
F_123 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_133 ) {
F_124 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_124 ) {
F_125 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_143 ) {
F_126 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_125 ) {
F_127 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_153 ) {
F_128 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_156 ) {
F_129 ( V_8 ) ;
goto V_217;
}
if ( V_8 -> V_90 & V_221 ) {
F_103 ( V_8 ) ;
V_8 -> V_90 &= ~ V_221 ;
goto V_217;
}
if ( V_8 -> V_93 == V_155 )
F_130 ( V_8 ) ;
V_217:
if ( V_8 -> V_93 == V_155 ) {
F_22 ( V_8 , ~ 0 ) ;
F_24 ( V_8 , 0xFF ) ;
} else {
F_24 ( V_8 , 0x1 ) ;
}
F_56 ( V_117 , & V_8 -> V_118 ) ;
V_211:
if ( V_8 -> V_93 == V_222 )
return;
if ( V_8 -> V_90 )
F_131 ( & V_8 -> V_157 ,
V_158 + F_132 ( 20 ) ) ;
else
F_131 ( & V_8 -> V_157 , V_158 + ( V_223 * 2 ) ) ;
F_14 ( & V_8 -> V_52 ) ;
}
static void F_133 ( struct V_208 * V_209 )
{
struct V_7 * V_8 = F_116 ( V_209 ,
struct V_7 ,
V_30 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_114 * V_224 ;
struct V_130 * V_116 ;
T_3 V_210 ;
int V_39 = 0 , V_87 ;
while ( F_52 ( V_117 ,
& V_8 -> V_118 ) )
F_82 ( 500 , 1000 ) ;
F_15 ( V_8 ) ;
if ( V_8 -> V_27 & V_29 ) {
V_8 -> V_27 &= ~ V_29 ;
F_134 ( V_2 ) ;
F_135 ( V_2 ) ;
F_136 ( V_8 ) ;
}
V_8 -> V_27 |= V_28 ;
for ( V_39 = 0 ; V_39 < V_225 ; V_39 ++ ) {
V_210 = F_17 ( V_2 , V_218 ) &
V_219 ;
if ( ! V_210 )
break;
F_82 ( 5000 , 10000 ) ;
}
if ( V_39 == V_225 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
goto V_226;
}
for ( V_39 = 0 ; V_39 < V_225 ; V_39 ++ ) {
V_210 = F_17 ( V_2 , V_32 ) &
V_212 ;
if ( V_210 == V_213 )
break;
F_137 ( V_227 ) ;
}
F_137 ( V_227 ) ;
if ( V_39 == V_225 ) {
struct V_130 * V_144 ;
struct V_114 * V_228 , * V_229 ;
F_42 ( & V_8 -> V_12 -> V_13 , L_24 ,
V_210 ) ;
V_8 -> V_27 |= V_160 ;
if ( F_138 ( V_8 -> V_25 ) ) {
F_139 ( V_92 , & V_8 -> V_66 . V_93 ) ;
F_83 ( V_25 ) ;
F_84 ( V_25 ) ;
F_74 ( V_8 ) ;
F_20 ( V_8 ) ;
F_43 ( V_8 ) ;
F_140 ( V_8 ) ;
F_141 ( V_8 ) ;
}
F_70 (f, ftmp, &adapter->mac_filter_list,
list) {
F_142 ( & V_116 -> V_121 ) ;
F_9 ( V_116 ) ;
}
F_70 (fv, fvtmp, &adapter->vlan_filter_list,
list) {
F_142 ( & V_228 -> V_121 ) ;
F_9 ( V_228 ) ;
}
F_44 ( V_8 ) ;
F_111 ( V_8 ) ;
F_87 ( V_8 ) ;
F_110 ( V_8 ) ;
F_9 ( V_8 -> V_178 ) ;
F_134 ( V_2 ) ;
V_8 -> V_25 -> V_27 &= ~ V_230 ;
F_56 ( V_117 , & V_8 -> V_118 ) ;
V_8 -> V_27 &= ~ V_28 ;
F_37 ( & V_8 -> V_12 -> V_13 , L_25 ) ;
return;
}
V_226:
if ( F_138 ( V_8 -> V_25 ) ) {
F_83 ( V_25 ) ;
F_143 ( V_25 ) ;
F_74 ( V_8 ) ;
}
F_20 ( V_8 ) ;
V_8 -> V_93 = V_161 ;
V_8 -> V_27 &= ~ V_28 ;
F_141 ( V_8 ) ;
F_140 ( V_8 ) ;
if ( F_134 ( V_2 ) )
F_144 ( & V_8 -> V_12 -> V_13 , L_26 ) ;
V_8 -> V_162 = V_163 ;
V_87 = F_135 ( V_2 ) ;
if ( V_87 )
F_37 ( & V_8 -> V_12 -> V_13 , L_27 ,
V_87 ) ;
V_8 -> V_90 = V_220 ;
V_8 -> V_90 |= V_91 ;
F_50 (f, &adapter->mac_filter_list, list) {
V_116 -> V_123 = true ;
}
F_50 (vlf, &adapter->vlan_filter_list, list) {
V_224 -> V_123 = true ;
}
V_8 -> V_90 |= V_133 ;
V_8 -> V_90 |= V_124 ;
F_56 ( V_117 , & V_8 -> V_118 ) ;
F_19 ( V_8 ) ;
F_131 ( & V_8 -> V_157 , V_158 + 2 ) ;
if ( F_138 ( V_8 -> V_25 ) ) {
V_87 = F_145 ( V_8 ) ;
if ( V_87 )
goto V_231;
V_87 = F_146 ( V_8 ) ;
if ( V_87 )
goto V_231;
F_76 ( V_8 ) ;
V_87 = F_79 ( V_8 ) ;
if ( V_87 )
goto V_231;
F_25 ( V_8 , true ) ;
} else {
V_8 -> V_93 = V_159 ;
}
return;
V_231:
F_42 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
F_147 ( V_8 -> V_25 ) ;
}
static void F_148 ( struct V_208 * V_209 )
{
struct V_7 * V_8 =
F_116 ( V_209 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_232 V_233 ;
struct V_234 * V_235 ;
T_1 V_187 ;
T_3 V_49 , V_236 ;
T_7 V_237 ;
if ( V_8 -> V_27 & V_160 )
goto V_89;
V_233 . V_238 = V_239 ;
V_233 . V_240 = F_7 ( V_233 . V_238 , V_16 ) ;
if ( ! V_233 . V_240 )
goto V_89;
V_235 = (struct V_234 * ) & V_233 . V_241 ;
do {
V_187 = F_149 ( V_2 , & V_233 , & V_237 ) ;
if ( V_187 || ! V_235 -> V_242 )
break;
F_150 ( V_8 , V_235 -> V_242 ,
V_235 -> V_243 , V_233 . V_240 ,
V_233 . V_244 ) ;
if ( V_237 != 0 )
memset ( V_233 . V_240 , 0 , V_239 ) ;
} while ( V_237 );
if ( ( V_8 -> V_27 &
( V_28 | V_29 ) ) ||
V_8 -> V_93 == V_161 )
goto V_245;
V_49 = F_17 ( V_2 , V_2 -> V_191 . V_246 . V_247 ) ;
V_236 = V_49 ;
if ( V_49 & V_248 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_248 ;
}
if ( V_49 & V_249 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_249 ;
}
if ( V_49 & V_250 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_250 ;
}
if ( V_236 != V_49 )
F_16 ( V_2 , V_2 -> V_191 . V_246 . V_247 , V_49 ) ;
V_49 = F_17 ( V_2 , V_2 -> V_191 . V_251 . V_247 ) ;
V_236 = V_49 ;
if ( V_49 & V_252 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_252 ;
}
if ( V_49 & V_253 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_253 ;
}
if ( V_49 & V_254 ) {
F_37 ( & V_8 -> V_12 -> V_13 , L_34 ) ;
V_49 &= ~ V_254 ;
}
if ( V_236 != V_49 )
F_16 ( V_2 , V_2 -> V_191 . V_251 . V_247 , V_49 ) ;
V_245:
F_9 ( V_233 . V_240 ) ;
V_89:
F_19 ( V_8 ) ;
}
void F_140 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_74 [ V_39 ] -> V_241 )
F_151 ( V_8 -> V_74 [ V_39 ] ) ;
}
static int F_145 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_74 [ V_39 ] -> V_67 = V_8 -> V_172 ;
V_87 = F_152 ( V_8 -> V_74 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_42 ( & V_8 -> V_12 -> V_13 ,
L_35 , V_39 ) ;
break;
}
return V_87 ;
}
static int F_146 ( struct V_7 * V_8 )
{
int V_39 , V_87 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ ) {
V_8 -> V_64 [ V_39 ] -> V_67 = V_8 -> V_175 ;
V_87 = F_153 ( V_8 -> V_64 [ V_39 ] ) ;
if ( ! V_87 )
continue;
F_42 ( & V_8 -> V_12 -> V_13 ,
L_36 , V_39 ) ;
break;
}
return V_87 ;
}
void F_141 ( struct V_7 * V_8 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_82 ; V_39 ++ )
if ( V_8 -> V_64 [ V_39 ] -> V_241 )
F_154 ( V_8 -> V_64 [ V_39 ] ) ;
}
static int F_155 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_87 ;
if ( V_8 -> V_27 & V_160 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_37 ) ;
return - V_128 ;
}
if ( V_8 -> V_93 != V_159 || V_8 -> V_90 )
return - V_255 ;
V_87 = F_145 ( V_8 ) ;
if ( V_87 )
goto V_256;
V_87 = F_146 ( V_8 ) ;
if ( V_87 )
goto V_257;
V_87 = F_35 ( V_8 , V_25 -> V_97 ) ;
if ( V_87 )
goto V_258;
F_63 ( V_8 , V_8 -> V_2 . V_142 . V_136 ) ;
F_76 ( V_8 ) ;
V_87 = F_79 ( V_8 ) ;
if ( V_87 )
goto V_258;
F_25 ( V_8 , true ) ;
return 0 ;
V_258:
F_81 ( V_8 ) ;
F_43 ( V_8 ) ;
V_257:
F_141 ( V_8 ) ;
V_256:
F_140 ( V_8 ) ;
return V_87 ;
}
static int F_147 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( V_8 -> V_93 <= V_159 )
return 0 ;
F_139 ( V_92 , & V_8 -> V_66 . V_93 ) ;
F_81 ( V_8 ) ;
V_8 -> V_93 = V_159 ;
F_43 ( V_8 ) ;
return 0 ;
}
static struct V_259 * F_156 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_260 ;
}
static int F_157 ( struct V_24 * V_25 , int V_261 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_103 = V_261 + V_105 + V_106 ;
if ( ( V_261 < 68 ) || ( V_103 > V_262 ) )
return - V_263 ;
V_25 -> V_104 = V_261 ;
V_8 -> V_27 |= V_29 ;
F_14 ( & V_8 -> V_30 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 )
{
T_3 V_264 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_264 = F_17 ( V_2 , V_32 ) &
V_212 ;
if ( ( V_264 == V_213 ) ||
( V_264 == V_214 ) )
return 0 ;
F_82 ( 10 , 20 ) ;
}
return - V_255 ;
}
int F_159 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_178 -> V_265 ; V_39 ++ ) {
if ( V_8 -> V_178 -> V_168 [ V_39 ] . V_266 == V_267 )
V_8 -> V_168 = & V_8 -> V_178 -> V_168 [ V_39 ] ;
}
if ( ! V_8 -> V_168 ) {
F_42 ( & V_8 -> V_12 -> V_13 , L_38 ) ;
return - V_268 ;
}
if ( V_8 -> V_178 -> V_269
& V_270 ) {
V_25 -> V_271 = V_25 -> V_272 &
~ ( V_273 |
V_274 |
V_275 ) ;
V_25 -> V_272 |= V_273 |
V_274 |
V_275 ;
}
V_25 -> V_272 |= V_276 |
V_277 |
V_278 |
V_279 |
V_280 |
V_281 |
V_282 |
V_283 |
V_284 ;
V_25 -> V_285 |= V_25 -> V_272 ;
V_25 -> V_285 &= ~ V_283 ;
V_8 -> V_66 . V_189 = V_8 -> V_168 -> V_286 ;
V_8 -> V_66 . V_9 = V_8 ;
V_8 -> V_66 . V_287 = 1 ;
V_8 -> V_66 . V_288 = V_289 ;
V_8 -> V_66 . V_290 = ( V_291 |
F_160 ( V_292 ) ) ;
V_8 -> V_66 . V_293 = ( V_291 |
F_160 ( V_294 ) ) ;
V_8 -> V_66 . V_25 = V_8 -> V_25 ;
V_8 -> V_66 . V_295 = V_8 -> V_168 -> V_296 ;
return 0 ;
}
static void F_161 ( struct V_208 * V_209 )
{
struct V_7 * V_8 = F_116 ( V_209 ,
struct V_7 ,
V_216 . V_209 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_297 * V_12 = V_8 -> V_12 ;
int V_87 , V_298 ;
switch ( V_8 -> V_93 ) {
case V_215 :
V_8 -> V_27 &= ~ V_160 ;
V_8 -> V_27 &= ~ V_28 ;
V_87 = F_162 ( V_2 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_39 ,
V_87 ) ;
goto V_87;
}
V_87 = F_158 ( V_2 ) ;
if ( V_87 ) {
F_37 ( & V_12 -> V_13 , L_40 ,
V_87 ) ;
goto V_87;
}
V_2 -> V_191 . V_299 = V_300 ;
V_2 -> V_191 . V_301 = V_300 ;
V_2 -> V_191 . V_302 = V_239 ;
V_2 -> V_191 . V_303 = V_239 ;
V_87 = F_135 ( V_2 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_41 ,
V_87 ) ;
goto V_87;
}
V_87 = F_120 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_42 , V_87 ) ;
F_134 ( V_2 ) ;
goto V_87;
}
V_8 -> V_93 = V_304 ;
goto V_305;
case V_304 :
if ( ! F_118 ( V_2 ) ) {
F_42 ( & V_12 -> V_13 , L_43 ) ;
F_134 ( V_2 ) ;
V_8 -> V_93 = V_215 ;
goto V_87;
}
V_87 = F_163 ( V_8 ) ;
if ( V_87 ) {
if ( V_87 == V_306 )
V_87 = F_120 ( V_8 ) ;
else
F_42 ( & V_12 -> V_13 , L_44 ,
V_8 -> V_307 . V_308 ,
V_8 -> V_307 . V_309 ,
V_310 ,
V_311 ) ;
goto V_87;
}
V_87 = F_121 ( V_8 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_45 ,
V_87 ) ;
goto V_87;
}
V_8 -> V_93 = V_312 ;
goto V_305;
case V_312 :
if ( ! V_8 -> V_178 ) {
V_298 = sizeof( struct V_313 ) +
( V_314 *
sizeof( struct V_315 ) ) ;
V_8 -> V_178 = F_7 ( V_298 , V_16 ) ;
if ( ! V_8 -> V_178 )
goto V_87;
}
V_87 = F_164 ( V_8 ) ;
if ( V_87 == V_306 ) {
V_87 = F_121 ( V_8 ) ;
goto V_87;
}
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_46 ,
V_87 ) ;
goto V_316;
}
V_8 -> V_93 = V_317 ;
break;
default:
goto V_316;
}
if ( F_159 ( V_8 ) )
goto V_316;
V_8 -> V_162 = V_163 ;
V_8 -> V_27 |= V_318 ;
V_25 -> V_319 = & V_320 ;
F_165 ( V_25 ) ;
V_25 -> V_321 = 5 * V_223 ;
if ( ! F_66 ( V_8 -> V_2 . V_142 . V_136 ) ) {
F_37 ( & V_12 -> V_13 , L_47 ,
V_8 -> V_2 . V_142 . V_136 ) ;
F_166 ( V_25 ) ;
F_64 ( V_8 -> V_2 . V_142 . V_136 , V_25 -> V_139 ) ;
} else {
V_8 -> V_27 |= V_140 ;
F_64 ( V_25 -> V_139 , V_8 -> V_2 . V_142 . V_136 ) ;
F_64 ( V_25 -> V_322 , V_8 -> V_2 . V_142 . V_136 ) ;
}
F_167 ( & V_8 -> V_157 ) ;
V_8 -> V_157 . V_323 = & F_114 ;
V_8 -> V_157 . V_48 = ( unsigned long ) V_8 ;
F_131 ( & V_8 -> V_157 , V_158 + 1 ) ;
V_8 -> V_82 = F_91 ( int ,
V_8 -> V_168 -> V_324 ,
( int ) ( F_92 () ) ) ;
V_8 -> V_172 = V_325 ;
V_8 -> V_175 = V_326 ;
V_87 = F_113 ( V_8 ) ;
if ( V_87 )
goto V_327;
F_31 ( V_8 ) ;
if ( V_8 -> V_178 -> V_269 &
V_328 )
V_8 -> V_27 |= V_329 ;
if ( ! F_106 ( V_8 ) )
F_103 ( V_8 ) ;
V_87 = F_40 ( V_8 ) ;
if ( V_87 )
goto V_327;
F_83 ( V_25 ) ;
if ( ! V_8 -> V_330 ) {
V_87 = F_168 ( V_25 ) ;
if ( V_87 )
goto V_331;
}
V_8 -> V_330 = true ;
F_143 ( V_25 ) ;
F_37 ( & V_12 -> V_13 , L_48 , V_8 -> V_2 . V_142 . V_136 ) ;
if ( V_25 -> V_272 & V_284 )
F_37 ( & V_12 -> V_13 , L_49 ) ;
F_37 ( & V_12 -> V_13 , L_50 , V_332 ) ;
V_8 -> V_93 = V_159 ;
F_139 ( V_92 , & V_8 -> V_66 . V_93 ) ;
F_19 ( V_8 ) ;
if ( F_106 ( V_8 ) ) {
V_8 -> V_90 |= V_221 ;
F_80 ( & V_8 -> V_157 , V_158 + 1 ) ;
} else {
F_103 ( V_8 ) ;
}
return;
V_305:
F_117 ( & V_8 -> V_216 , F_132 ( 30 ) ) ;
return;
V_331:
F_44 ( V_8 ) ;
V_327:
F_111 ( V_8 ) ;
V_316:
F_9 ( V_8 -> V_178 ) ;
V_8 -> V_178 = NULL ;
V_87:
if ( ++ V_8 -> V_333 > V_334 ) {
F_42 ( & V_12 -> V_13 , L_51 ) ;
V_8 -> V_27 |= V_160 ;
F_134 ( V_2 ) ;
V_8 -> V_93 = V_215 ;
F_117 ( & V_8 -> V_216 , V_223 * 5 ) ;
return;
}
F_117 ( & V_8 -> V_216 , V_223 ) ;
}
static void F_169 ( struct V_297 * V_12 )
{
struct V_24 * V_25 = F_170 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_171 ( V_25 ) ;
if ( F_138 ( V_25 ) )
F_147 ( V_25 ) ;
V_8 -> V_93 = V_222 ;
V_8 -> V_90 = 0 ;
#ifdef F_172
F_173 ( V_12 ) ;
#endif
F_174 ( V_12 ) ;
}
static int F_175 ( struct V_297 * V_12 , const struct V_335 * V_336 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_87 ;
V_87 = F_176 ( V_12 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_177 ( & V_12 -> V_13 , F_178 ( 64 ) ) ;
if ( V_87 ) {
V_87 = F_177 ( & V_12 -> V_13 , F_178 ( 32 ) ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 ,
L_52 , V_87 ) ;
goto V_337;
}
}
V_87 = F_179 ( V_12 , V_338 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 ,
L_53 , V_87 ) ;
goto V_339;
}
F_180 ( V_12 ) ;
F_181 ( V_12 ) ;
V_25 = F_182 ( sizeof( struct V_7 ) ,
V_340 ) ;
if ( ! V_25 ) {
V_87 = - V_129 ;
goto V_341;
}
F_183 ( V_25 , & V_12 -> V_13 ) ;
F_184 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_342 = F_23 ( V_343 ) - 1 ;
V_8 -> V_93 = V_215 ;
F_173 ( V_12 ) ;
V_2 -> V_102 = F_185 ( F_186 ( V_12 , 0 ) ,
F_187 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_102 ) {
V_87 = - V_128 ;
goto V_344;
}
V_2 -> V_345 = V_12 -> V_346 ;
V_2 -> V_347 = V_12 -> V_348 ;
F_188 ( V_12 , V_349 , & V_2 -> V_350 ) ;
V_2 -> V_351 = V_12 -> V_352 ;
V_2 -> V_353 = V_12 -> V_354 ;
V_2 -> V_355 . V_348 = F_189 ( V_12 -> V_356 ) ;
V_2 -> V_355 . V_357 = F_190 ( V_12 -> V_356 ) ;
F_191 ( & V_2 -> V_191 . V_358 ) ;
F_191 ( & V_2 -> V_191 . V_359 ) ;
F_54 ( & V_8 -> V_132 ) ;
F_54 ( & V_8 -> V_122 ) ;
F_192 ( & V_8 -> V_30 , F_133 ) ;
F_192 ( & V_8 -> V_52 , F_148 ) ;
F_192 ( & V_8 -> V_207 , F_115 ) ;
F_193 ( & V_8 -> V_216 , F_161 ) ;
F_117 ( & V_8 -> V_216 ,
F_132 ( 5 * ( V_12 -> V_356 & 0x07 ) ) ) ;
return 0 ;
V_344:
F_194 ( V_25 ) ;
V_341:
F_195 ( V_12 ) ;
V_339:
V_337:
F_174 ( V_12 ) ;
return V_87 ;
}
static int F_196 ( struct V_297 * V_12 , T_11 V_93 )
{
struct V_24 * V_25 = F_170 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_360 = 0 ;
F_171 ( V_25 ) ;
if ( F_138 ( V_25 ) ) {
F_197 () ;
F_81 ( V_8 ) ;
F_198 () ;
}
F_44 ( V_8 ) ;
F_111 ( V_8 ) ;
V_360 = F_173 ( V_12 ) ;
if ( V_360 )
return V_360 ;
F_174 ( V_12 ) ;
return 0 ;
}
static int F_199 ( struct V_297 * V_12 )
{
struct V_7 * V_8 = F_170 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_87 ;
F_200 ( V_12 , V_361 ) ;
F_201 ( V_12 ) ;
F_173 ( V_12 ) ;
V_87 = F_202 ( V_12 ) ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_54 ) ;
return V_87 ;
}
F_181 ( V_12 ) ;
F_197 () ;
V_87 = F_90 ( V_8 ) ;
if ( V_87 ) {
F_198 () ;
F_42 ( & V_12 -> V_13 , L_55 ) ;
return V_87 ;
}
V_87 = F_40 ( V_8 ) ;
F_198 () ;
if ( V_87 ) {
F_42 ( & V_12 -> V_13 , L_56 ) ;
return V_87 ;
}
F_14 ( & V_8 -> V_30 ) ;
F_203 ( V_25 ) ;
return V_87 ;
}
static void F_204 ( struct V_297 * V_12 )
{
struct V_24 * V_25 = F_170 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_130 * V_116 , * V_144 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_205 ( & V_8 -> V_216 ) ;
F_206 ( & V_8 -> V_30 ) ;
if ( V_8 -> V_330 ) {
F_207 ( V_25 ) ;
V_8 -> V_330 = false ;
}
V_8 -> V_93 = V_222 ;
V_8 -> V_90 = 0 ;
F_136 ( V_8 ) ;
F_137 ( 20 ) ;
if ( ! F_118 ( V_2 ) ) {
F_136 ( V_8 ) ;
F_137 ( 20 ) ;
}
if ( V_8 -> V_33 ) {
F_15 ( V_8 ) ;
F_44 ( V_8 ) ;
F_111 ( V_8 ) ;
F_110 ( V_8 ) ;
}
if ( V_8 -> V_157 . V_323 )
F_208 ( & V_8 -> V_157 ) ;
F_209 () ;
if ( V_2 -> V_191 . V_251 . V_67 )
F_134 ( V_2 ) ;
F_210 ( & V_2 -> V_191 . V_359 ) ;
F_210 ( & V_2 -> V_191 . V_358 ) ;
F_211 ( V_2 -> V_102 ) ;
F_195 ( V_12 ) ;
F_140 ( V_8 ) ;
F_141 ( V_8 ) ;
F_87 ( V_8 ) ;
F_9 ( V_8 -> V_178 ) ;
F_70 (f, ftmp, &adapter->mac_filter_list, list) {
F_142 ( & V_116 -> V_121 ) ;
F_9 ( V_116 ) ;
}
F_70 (f, ftmp, &adapter->vlan_filter_list, list) {
F_142 ( & V_116 -> V_121 ) ;
F_9 ( V_116 ) ;
}
F_194 ( V_25 ) ;
F_212 ( V_12 ) ;
F_174 ( V_12 ) ;
}
static int T_12 F_213 ( void )
{
int V_187 ;
F_11 ( L_57 , V_332 ,
V_362 ) ;
F_11 ( L_50 , V_363 ) ;
V_187 = F_214 ( & V_364 ) ;
return V_187 ;
}
static void T_13 F_215 ( void )
{
F_216 ( & V_364 ) ;
}
