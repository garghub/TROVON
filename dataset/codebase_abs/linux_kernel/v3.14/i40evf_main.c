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
F_14 ( & V_8 -> V_27 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_16 ( V_2 , V_28 , 0 ) ;
F_17 ( V_2 , V_29 ) ;
F_18 ( V_8 -> V_30 [ 0 ] . V_31 ) ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_16 ( V_2 , V_28 , V_32 |
V_33 ) ;
F_16 ( V_2 , V_34 , V_35 ) ;
F_17 ( V_2 , V_29 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
int V_36 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
for ( V_36 = 1 ; V_36 < V_8 -> V_37 ; V_36 ++ ) {
F_16 ( V_2 , F_21 ( V_36 - 1 ) , 0 ) ;
F_18 ( V_8 -> V_30 [ V_36 ] . V_31 ) ;
}
F_17 ( V_2 , V_29 ) ;
}
void F_22 ( struct V_7 * V_8 , T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_36 ;
for ( V_36 = 1 ; V_36 < V_8 -> V_37 ; V_36 ++ ) {
if ( V_19 & ( 1 << ( V_36 - 1 ) ) ) {
F_16 ( V_2 , F_21 ( V_36 - 1 ) ,
V_38 |
V_39 ) ;
}
}
}
static void F_23 ( struct V_7 * V_8 ,
T_3 V_19 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_36 ;
T_5 V_40 ;
for ( V_36 = 1 ; V_36 < V_8 -> V_37 ; V_36 ++ ) {
if ( V_19 & ( 1 << V_36 ) ) {
V_40 = F_17 ( V_2 , F_21 ( V_36 - 1 ) ) ;
V_40 |= V_41 |
V_39 ;
F_16 ( V_2 , F_21 ( V_36 - 1 ) , V_40 ) ;
}
}
}
void F_24 ( struct V_7 * V_8 , bool V_42 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
F_22 ( V_8 , ~ 0 ) ;
if ( V_42 )
F_17 ( V_2 , V_29 ) ;
}
static T_6 F_25 ( int V_43 , void * V_44 )
{
struct V_24 * V_25 = V_44 ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_45 ;
T_3 V_46 ;
V_45 = F_17 ( V_2 , V_47 ) ;
V_46 = F_17 ( V_2 , V_34 ) ;
V_45 = F_17 ( V_2 , V_28 ) ;
V_45 = V_45 | V_48 ;
F_16 ( V_2 , V_28 , V_45 ) ;
F_16 ( V_2 , V_34 , V_46 ) ;
F_16 ( V_2 , V_28 , V_32 ) ;
F_14 ( & V_8 -> V_49 ) ;
return V_50 ;
}
static T_6 F_26 ( int V_43 , void * V_44 )
{
struct V_51 * V_52 = V_44 ;
if ( ! V_52 -> V_53 . V_54 && ! V_52 -> V_55 . V_54 )
return V_50 ;
F_27 ( & V_52 -> V_56 ) ;
return V_50 ;
}
static void
F_28 ( struct V_7 * V_8 , int V_57 , int V_58 )
{
struct V_51 * V_52 = V_8 -> V_52 [ V_57 ] ;
struct V_59 * V_60 = V_8 -> V_61 [ V_58 ] ;
V_60 -> V_52 = V_52 ;
V_60 -> V_62 = V_52 -> V_55 . V_54 ;
V_60 -> V_63 = & V_8 -> V_63 ;
V_52 -> V_55 . V_54 = V_60 ;
V_52 -> V_55 . V_64 ++ ;
V_52 -> V_55 . V_65 = V_66 ;
}
static void
F_29 ( struct V_7 * V_8 , int V_57 , int V_67 )
{
struct V_51 * V_52 = V_8 -> V_52 [ V_57 ] ;
struct V_59 * V_68 = V_8 -> V_69 [ V_67 ] ;
V_68 -> V_52 = V_52 ;
V_68 -> V_62 = V_52 -> V_53 . V_54 ;
V_68 -> V_63 = & V_8 -> V_63 ;
V_52 -> V_53 . V_54 = V_68 ;
V_52 -> V_53 . V_64 ++ ;
V_52 -> V_53 . V_65 = V_66 ;
V_52 -> V_70 ++ ;
V_52 -> V_71 |= ( 1 << V_67 ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
int V_72 ;
int V_73 = 0 ;
int V_74 = 0 , V_75 = 0 ;
int V_76 = V_8 -> V_77 -> V_78 ;
int V_79 = V_8 -> V_77 -> V_78 ;
int V_36 , V_80 ;
int V_81 , V_82 ;
int V_83 = 0 ;
V_72 = V_8 -> V_37 - V_84 ;
if ( V_72 == ( V_76 * 2 ) ) {
for (; V_74 < V_76 ; V_73 ++ , V_74 ++ )
F_28 ( V_8 , V_73 , V_74 ) ;
for (; V_75 < V_79 ; V_73 ++ , V_75 ++ )
F_29 ( V_8 , V_73 , V_75 ) ;
goto V_85;
}
for ( V_36 = V_73 ; V_36 < V_72 ; V_36 ++ ) {
V_81 = F_31 ( V_76 , V_72 - V_36 ) ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
F_28 ( V_8 , V_36 , V_74 ) ;
V_74 ++ ;
V_76 -- ;
}
}
for ( V_36 = V_73 ; V_36 < V_72 ; V_36 ++ ) {
V_82 = F_31 ( V_79 , V_72 - V_36 ) ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
F_29 ( V_8 , V_36 , V_75 ) ;
V_75 ++ ;
V_79 -- ;
}
}
V_85:
V_8 -> V_86 |= V_87 ;
return V_83 ;
}
static int
F_32 ( struct V_7 * V_8 , char * V_88 )
{
int V_31 , V_83 , V_72 ;
int V_89 = 0 , V_90 = 0 ;
F_20 ( V_8 ) ;
V_72 = V_8 -> V_37 - V_84 ;
for ( V_31 = 0 ; V_31 < V_72 ; V_31 ++ ) {
struct V_51 * V_52 = V_8 -> V_52 [ V_31 ] ;
if ( V_52 -> V_53 . V_54 && V_52 -> V_55 . V_54 ) {
snprintf ( V_52 -> V_91 , sizeof( V_52 -> V_91 ) - 1 ,
L_2 , V_88 ,
L_3 , V_89 ++ ) ;
V_90 ++ ;
} else if ( V_52 -> V_55 . V_54 ) {
snprintf ( V_52 -> V_91 , sizeof( V_52 -> V_91 ) - 1 ,
L_2 , V_88 ,
L_4 , V_89 ++ ) ;
} else if ( V_52 -> V_53 . V_54 ) {
snprintf ( V_52 -> V_91 , sizeof( V_52 -> V_91 ) - 1 ,
L_2 , V_88 ,
L_5 , V_90 ++ ) ;
} else {
continue;
}
V_83 = F_33 (
V_8 -> V_30 [ V_31 + V_84 ] . V_31 ,
F_26 ,
0 ,
V_52 -> V_91 ,
V_52 ) ;
if ( V_83 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_6 ,
V_92 , V_83 ) ;
goto V_93;
}
F_35 (
V_8 -> V_30 [ V_31 + V_84 ] . V_31 ,
V_52 -> V_94 ) ;
}
return 0 ;
V_93:
while ( V_31 ) {
V_31 -- ;
F_35 (
V_8 -> V_30 [ V_31 + V_84 ] . V_31 ,
NULL ) ;
F_36 ( V_8 -> V_30 [ V_31 + V_84 ] . V_31 ,
V_8 -> V_52 [ V_31 ] ) ;
}
return V_83 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_83 ;
sprintf ( V_8 -> V_91 [ 0 ] , L_7 ) ;
V_83 = F_33 ( V_8 -> V_30 [ 0 ] . V_31 ,
& F_25 , 0 , V_8 -> V_91 [ 0 ] , V_25 ) ;
if ( V_83 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_8 , V_83 ) ;
F_36 ( V_8 -> V_30 [ 0 ] . V_31 , V_25 ) ;
}
return V_83 ;
}
static void F_39 ( struct V_7 * V_8 )
{
int V_36 ;
int V_72 ;
V_72 = V_8 -> V_37 - V_84 ;
for ( V_36 = 0 ; V_36 < V_72 ; V_36 ++ ) {
F_35 ( V_8 -> V_30 [ V_36 + 1 ] . V_31 ,
NULL ) ;
F_36 ( V_8 -> V_30 [ V_36 + 1 ] . V_31 ,
V_8 -> V_52 [ V_36 ] ) ;
}
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
F_36 ( V_8 -> V_30 [ 0 ] . V_31 , V_25 ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ )
V_8 -> V_69 [ V_36 ] -> V_95 = V_2 -> V_96 + F_42 ( V_36 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_24 * V_25 = V_8 -> V_25 ;
int V_97 = V_25 -> V_98 + V_99 + V_100 ;
int V_36 ;
int V_101 ;
V_8 -> V_102 &= ~ V_103 ;
V_8 -> V_102 |= V_104 ;
if ( V_25 -> V_98 > V_105 ) {
if ( V_8 -> V_102 & V_103 )
V_8 -> V_102 |= V_106 ;
else
V_8 -> V_102 &= ~ V_106 ;
} else {
if ( V_8 -> V_102 & V_104 )
V_8 -> V_102 &= ~ V_106 ;
else
V_8 -> V_102 |= V_106 ;
}
if ( V_8 -> V_102 & V_106 ) {
V_101 = V_107 ;
} else {
if ( V_25 -> V_98 <= V_105 )
V_101 = V_108 ;
else
V_101 = F_2 ( V_97 , 1024 ) ;
}
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ ) {
V_8 -> V_61 [ V_36 ] -> V_95 = V_2 -> V_96 + F_44 ( V_36 ) ;
V_8 -> V_61 [ V_36 ] -> V_101 = V_101 ;
}
}
static struct
V_109 * F_45 ( struct V_7 * V_8 , T_7 V_110 )
{
struct V_109 * V_111 ;
F_46 (f, &adapter->vlan_filter_list, list) {
if ( V_110 == V_111 -> V_110 )
return V_111 ;
}
return NULL ;
}
static struct
V_109 * F_47 ( struct V_7 * V_8 , T_7 V_110 )
{
struct V_109 * V_111 ;
V_111 = F_45 ( V_8 , V_110 ) ;
if ( NULL == V_111 ) {
V_111 = F_7 ( sizeof( * V_111 ) , V_112 ) ;
if ( NULL == V_111 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_9 ,
V_92 ) ;
return NULL ;
}
V_111 -> V_110 = V_110 ;
F_48 ( & V_111 -> V_113 ) ;
F_49 ( & V_111 -> V_113 , & V_8 -> V_114 ) ;
V_111 -> V_115 = true ;
V_8 -> V_86 |= V_116 ;
}
return V_111 ;
}
static void F_50 ( struct V_7 * V_8 , T_7 V_110 )
{
struct V_109 * V_111 ;
V_111 = F_45 ( V_8 , V_110 ) ;
if ( V_111 ) {
V_111 -> remove = true ;
V_8 -> V_86 |= V_117 ;
}
return;
}
static int F_51 ( struct V_24 * V_25 ,
T_8 T_9 V_118 , T_7 V_119 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
if ( F_47 ( V_8 , V_119 ) == NULL )
return - V_120 ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 ,
T_8 T_9 V_118 , T_7 V_119 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
F_50 ( V_8 , V_119 ) ;
return 0 ;
}
static struct
V_121 * F_53 ( struct V_7 * V_8 ,
T_10 * V_122 )
{
struct V_121 * V_111 ;
if ( ! V_122 )
return NULL ;
F_46 (f, &adapter->mac_filter_list, list) {
if ( F_54 ( V_122 , V_111 -> V_122 ) )
return V_111 ;
}
return NULL ;
}
static struct
V_121 * F_55 ( struct V_7 * V_8 ,
T_10 * V_122 )
{
struct V_121 * V_111 ;
if ( ! V_122 )
return NULL ;
while ( F_56 ( V_123 ,
& V_8 -> V_124 ) )
F_57 ( 1 ) ;
V_111 = F_53 ( V_8 , V_122 ) ;
if ( NULL == V_111 ) {
V_111 = F_7 ( sizeof( * V_111 ) , V_112 ) ;
if ( NULL == V_111 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_10 , V_92 ) ;
F_58 ( V_123 ,
& V_8 -> V_124 ) ;
return NULL ;
}
memcpy ( V_111 -> V_122 , V_122 , V_125 ) ;
F_49 ( & V_111 -> V_113 , & V_8 -> V_126 ) ;
V_111 -> V_115 = true ;
V_8 -> V_86 |= V_127 ;
}
F_58 ( V_123 , & V_8 -> V_124 ) ;
return V_111 ;
}
static int F_59 ( struct V_24 * V_25 , void * V_128 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_121 * V_111 ;
struct V_129 * V_130 = V_128 ;
if ( ! F_60 ( V_130 -> V_131 ) )
return - V_132 ;
if ( F_54 ( V_25 -> V_133 , V_130 -> V_131 ) )
return 0 ;
V_111 = F_55 ( V_8 , V_130 -> V_131 ) ;
if ( V_111 ) {
memcpy ( V_2 -> V_134 . V_130 , V_130 -> V_131 , V_25 -> V_135 ) ;
memcpy ( V_25 -> V_133 , V_8 -> V_2 . V_134 . V_130 ,
V_25 -> V_135 ) ;
}
return ( V_111 == NULL ) ? - V_120 : 0 ;
}
static void F_61 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_121 * V_111 , * V_136 ;
struct V_137 * V_138 ;
struct V_137 * V_139 ;
F_62 (uca, netdev) {
F_55 ( V_8 , V_138 -> V_130 ) ;
}
F_63 (mca, netdev) {
F_55 ( V_8 , V_139 -> V_130 ) ;
}
while ( F_56 ( V_123 ,
& V_8 -> V_124 ) )
F_57 ( 1 ) ;
F_64 (f, ftmp, &adapter->mac_filter_list, list) {
bool V_140 = false ;
if ( V_111 -> V_122 [ 0 ] & 0x01 ) {
F_63 (mca, netdev) {
if ( F_54 ( V_139 -> V_130 , V_111 -> V_122 ) ) {
V_140 = true ;
break;
}
}
} else {
F_62 (uca, netdev) {
if ( F_54 ( V_138 -> V_130 , V_111 -> V_122 ) ) {
V_140 = true ;
break;
}
}
}
if ( V_140 ) {
V_111 -> remove = true ;
V_8 -> V_86 |= V_141 ;
}
}
F_58 ( V_123 , & V_8 -> V_124 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
int V_142 ;
struct V_51 * V_52 ;
int V_72 = V_8 -> V_37 - V_84 ;
for ( V_142 = 0 ; V_142 < V_72 ; V_142 ++ ) {
struct V_143 * V_56 ;
V_52 = V_8 -> V_52 [ V_142 ] ;
V_56 = & V_52 -> V_56 ;
F_66 ( V_56 ) ;
}
}
static void F_67 ( struct V_7 * V_8 )
{
int V_142 ;
struct V_51 * V_52 ;
int V_72 = V_8 -> V_37 - V_84 ;
for ( V_142 = 0 ; V_142 < V_72 ; V_142 ++ ) {
V_52 = V_8 -> V_52 [ V_142 ] ;
F_68 ( & V_52 -> V_56 ) ;
}
}
static void F_69 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_36 ;
F_61 ( V_25 ) ;
F_41 ( V_8 ) ;
F_43 ( V_8 ) ;
V_8 -> V_86 |= V_144 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ ) {
struct V_59 * V_54 = V_8 -> V_61 [ V_36 ] ;
F_70 ( V_54 , V_54 -> V_64 ) ;
V_54 -> V_145 = V_54 -> V_64 - 1 ;
F_71 ( V_54 -> V_145 , V_54 -> V_95 ) ;
}
}
static int F_72 ( struct V_7 * V_8 )
{
V_8 -> V_146 = V_147 ;
F_58 ( V_148 , & V_8 -> V_63 . V_146 ) ;
F_65 ( V_8 ) ;
V_8 -> V_86 |= V_149 ;
F_73 ( & V_8 -> V_150 , V_151 + 1 ) ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ )
F_75 ( V_8 -> V_61 [ V_36 ] ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ )
F_77 ( V_8 -> V_69 [ V_36 ] ) ;
}
void F_78 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_121 * V_111 ;
F_46 (f, &adapter->mac_filter_list, list) {
V_111 -> remove = true ;
}
V_8 -> V_86 |= V_141 ;
V_8 -> V_86 |= V_152 ;
F_73 ( & V_8 -> V_150 , V_151 + 1 ) ;
F_79 ( 20 ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_20 ( V_8 ) ;
F_67 ( V_8 ) ;
F_82 ( V_25 ) ;
F_76 ( V_8 ) ;
F_74 ( V_8 ) ;
}
static int
F_83 ( struct V_7 * V_8 , int V_153 )
{
int V_83 , V_154 ;
V_154 = V_155 ;
while ( V_153 >= V_154 ) {
V_83 = F_84 ( V_8 -> V_12 , V_8 -> V_30 ,
V_153 ) ;
if ( ! V_83 )
break;
else if ( V_83 < 0 )
V_153 = 0 ;
else
V_153 = V_83 ;
}
if ( V_153 < V_154 ) {
F_38 ( & V_8 -> V_12 -> V_13 , L_11 ) ;
F_9 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
V_83 = - V_156 ;
} else {
V_8 -> V_37 = V_153 ;
}
return V_83 ;
}
static void F_85 ( struct V_7 * V_8 )
{
int V_36 ;
if ( ! V_8 -> V_77 )
return;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ ) {
if ( V_8 -> V_69 [ V_36 ] )
F_86 ( V_8 -> V_69 [ V_36 ] , V_157 ) ;
V_8 -> V_69 [ V_36 ] = NULL ;
V_8 -> V_61 [ V_36 ] = NULL ;
}
}
static int F_87 ( struct V_7 * V_8 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ ) {
struct V_59 * V_68 ;
struct V_59 * V_60 ;
V_68 = F_7 ( sizeof( struct V_59 ) * 2 , V_16 ) ;
if ( ! V_68 )
goto V_158;
V_68 -> V_159 = V_36 ;
V_68 -> V_25 = V_8 -> V_25 ;
V_68 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_68 -> V_64 = V_160 ;
V_8 -> V_69 [ V_36 ] = V_68 ;
V_60 = & V_68 [ 1 ] ;
V_60 -> V_159 = V_36 ;
V_60 -> V_25 = V_8 -> V_25 ;
V_60 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_60 -> V_64 = V_161 ;
V_8 -> V_61 [ V_36 ] = V_60 ;
}
return 0 ;
V_158:
F_85 ( V_8 ) ;
return - V_120 ;
}
static int F_88 ( struct V_7 * V_8 )
{
int V_31 , V_162 ;
int V_163 = 0 ;
int V_83 = 0 ;
if ( ! V_8 -> V_77 ) {
V_83 = - V_156 ;
goto V_85;
}
V_163 = V_8 -> V_77 -> V_78 ;
V_162 = F_89 ( V_163 , ( int ) ( F_90 () * 2 ) ) + V_84 ;
V_162 = F_89 ( V_162 , ( int ) V_8 -> V_164 -> V_165 + 1 ) ;
V_8 -> V_30 = F_91 ( V_162 ,
sizeof( struct V_166 ) , V_16 ) ;
if ( ! V_8 -> V_30 ) {
V_83 = - V_120 ;
goto V_85;
}
for ( V_31 = 0 ; V_31 < V_162 ; V_31 ++ )
V_8 -> V_30 [ V_31 ] . V_167 = V_31 ;
F_83 ( V_8 , V_162 ) ;
V_85:
V_8 -> V_25 -> V_168 = V_163 ;
return V_83 ;
}
static int F_92 ( struct V_7 * V_8 )
{
int V_142 , V_169 ;
struct V_51 * V_52 ;
V_169 = V_8 -> V_37 - V_84 ;
for ( V_142 = 0 ; V_142 < V_169 ; V_142 ++ ) {
V_52 = F_7 ( sizeof( struct V_51 ) , V_16 ) ;
if ( ! V_52 )
goto V_158;
V_52 -> V_8 = V_8 ;
V_52 -> V_63 = & V_8 -> V_63 ;
V_52 -> V_57 = V_142 ;
F_93 ( V_8 -> V_25 , & V_52 -> V_56 ,
V_170 , 64 ) ;
V_8 -> V_52 [ V_142 ] = V_52 ;
}
return 0 ;
V_158:
while ( V_142 ) {
V_142 -- ;
V_52 = V_8 -> V_52 [ V_142 ] ;
F_94 ( & V_52 -> V_56 ) ;
F_9 ( V_52 ) ;
V_8 -> V_52 [ V_142 ] = NULL ;
}
return - V_120 ;
}
static void F_95 ( struct V_7 * V_8 )
{
int V_142 , V_169 ;
int V_171 ;
V_169 = V_8 -> V_37 - V_84 ;
V_171 = V_8 -> V_77 -> V_78 ;
for ( V_142 = 0 ; V_142 < V_169 ; V_142 ++ ) {
struct V_51 * V_52 = V_8 -> V_52 [ V_142 ] ;
V_8 -> V_52 [ V_142 ] = NULL ;
if ( V_142 < V_171 )
F_94 ( & V_52 -> V_56 ) ;
F_9 ( V_52 ) ;
}
}
void F_96 ( struct V_7 * V_8 )
{
F_97 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
return;
}
int F_98 ( struct V_7 * V_8 )
{
int V_83 ;
V_83 = F_88 ( V_8 ) ;
if ( V_83 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_12 ) ;
goto V_172;
}
V_83 = F_92 ( V_8 ) ;
if ( V_83 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_13 ) ;
goto V_173;
}
V_83 = F_87 ( V_8 ) ;
if ( V_83 ) {
F_38 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_174;
}
F_34 ( & V_8 -> V_12 -> V_13 , L_15 ,
( V_8 -> V_77 -> V_78 > 1 ) ? L_16 :
L_17 , V_8 -> V_77 -> V_78 ) ;
return 0 ;
V_174:
F_95 ( V_8 ) ;
V_173:
F_96 ( V_8 ) ;
V_172:
return V_83 ;
}
static void F_99 ( unsigned long V_44 )
{
struct V_7 * V_8 = (struct V_7 * ) V_44 ;
F_14 ( & V_8 -> V_175 ) ;
}
static void F_100 ( struct V_176 * V_177 )
{
struct V_7 * V_8 = F_101 ( V_177 ,
struct V_7 ,
V_175 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( V_8 -> V_146 < V_178 )
goto V_179;
if ( F_56 ( V_123 , & V_8 -> V_124 ) )
goto V_179;
if ( ( V_8 -> V_146 != V_180 ) &&
( F_17 ( V_2 , V_29 ) & 0x3 ) != V_181 ) {
V_8 -> V_146 = V_180 ;
F_14 ( & V_8 -> V_27 ) ;
F_34 ( & V_8 -> V_12 -> V_13 , L_18 ,
V_92 ) ;
goto V_179;
}
if ( V_8 -> V_182 )
goto V_179;
if ( V_8 -> V_86 & V_87 ) {
F_102 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_127 ) {
F_103 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_116 ) {
F_104 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_141 ) {
F_105 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_117 ) {
F_106 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_152 ) {
F_107 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_144 ) {
F_108 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_86 & V_149 ) {
F_109 ( V_8 ) ;
goto V_179;
}
if ( V_8 -> V_146 == V_147 )
F_110 ( V_8 ) ;
F_24 ( V_8 , true ) ;
F_23 ( V_8 , 0xFF ) ;
V_179:
if ( V_8 -> V_86 )
F_111 ( & V_8 -> V_150 ,
V_151 + F_112 ( 20 ) ) ;
else
F_111 ( & V_8 -> V_150 , V_151 + ( V_183 * 2 ) ) ;
F_58 ( V_123 , & V_8 -> V_124 ) ;
F_14 ( & V_8 -> V_49 ) ;
}
static void F_113 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_184 = 0 ;
int V_36 , V_80 ;
T_2 V_185 ;
static const T_3 V_186 [ V_187 + 1 ] = {
0x794221b4 , 0xbca0c5ab , 0x6cd5ebd9 , 0x1ada6127 ,
0x983b3aa1 , 0x1c4e71eb , 0x7f6328b2 , 0xfcdc0da0 ,
0xc135cafa , 0x7a6f7e2d , 0xe7102d28 , 0x163cd12e ,
0x4954b126 } ;
for ( V_36 = 0 ; V_36 <= V_187 ; V_36 ++ )
F_16 ( V_2 , F_114 ( V_36 ) , V_186 [ V_36 ] ) ;
V_185 = V_188 ;
F_16 ( V_2 , F_115 ( 0 ) , ( T_3 ) V_185 ) ;
F_16 ( V_2 , F_115 ( 1 ) , ( T_3 ) ( V_185 >> 32 ) ) ;
for ( V_36 = 0 , V_80 = 0 ; V_36 < V_189 ; V_36 ++ , V_80 ++ ) {
if ( V_80 == V_8 -> V_77 -> V_78 )
V_80 = 0 ;
V_184 = ( V_184 << 8 ) | ( V_80 &
( ( 0x1 << 8 ) - 1 ) ) ;
if ( ( V_36 & 3 ) == 3 )
F_16 ( V_2 , F_116 ( V_36 >> 2 ) , V_184 ) ;
}
F_117 ( V_2 ) ;
}
static void F_118 ( struct V_176 * V_177 )
{
struct V_7 * V_8 =
F_101 ( V_177 , struct V_7 , V_27 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_36 = 0 , V_83 ;
T_5 V_190 ;
while ( F_56 ( V_123 ,
& V_8 -> V_124 ) )
F_119 ( 500 ) ;
for ( V_36 = 0 ; V_36 < 20 ; V_36 ++ ) {
V_190 = F_17 ( V_2 , V_29 ) &
V_191 ;
if ( V_190 == V_192 )
break;
else
F_57 ( 100 ) ;
}
if ( V_36 == 20 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_19 ,
V_92 , V_190 ) ;
}
F_78 ( V_8 ) ;
V_8 -> V_146 = V_180 ;
if ( F_120 ( V_2 ) )
F_121 ( & V_8 -> V_12 -> V_13 ,
L_20 ,
V_92 ) ;
V_83 = F_122 ( V_2 ) ;
if ( V_83 )
F_34 ( & V_8 -> V_12 -> V_13 , L_21 ,
V_92 , V_83 ) ;
V_8 -> V_182 = 0 ;
V_8 -> V_86 = 0 ;
F_102 ( V_8 ) ;
F_58 ( V_123 , & V_8 -> V_124 ) ;
F_111 ( & V_8 -> V_150 , V_151 + 2 ) ;
if ( F_123 ( V_8 -> V_25 ) ) {
V_83 = F_124 ( V_8 ) ;
if ( V_83 )
goto V_193;
V_83 = F_125 ( V_8 ) ;
if ( V_83 )
goto V_193;
F_69 ( V_8 ) ;
V_83 = F_72 ( V_8 ) ;
if ( V_83 )
goto V_193;
F_24 ( V_8 , true ) ;
}
return;
V_193:
F_38 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_126 ( V_8 -> V_25 ) ;
}
static void F_127 ( struct V_176 * V_177 )
{
struct V_7 * V_8 =
F_101 ( V_177 , struct V_7 , V_49 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_194 V_195 ;
struct V_196 * V_197 ;
T_1 V_198 ;
T_7 V_199 ;
V_195 . V_200 = V_201 ;
V_195 . V_202 = F_7 ( V_195 . V_200 , V_16 ) ;
if ( ! V_195 . V_202 ) {
F_34 ( & V_8 -> V_12 -> V_13 , L_23 ,
V_92 ) ;
return;
}
V_197 = (struct V_196 * ) & V_195 . V_203 ;
do {
V_198 = F_128 ( V_2 , & V_195 , & V_199 ) ;
if ( V_198 )
break;
F_129 ( V_8 , V_197 -> V_204 ,
V_197 -> V_205 , V_195 . V_202 ,
V_195 . V_200 ) ;
if ( V_199 != 0 ) {
F_34 ( & V_8 -> V_12 -> V_13 ,
L_24 ,
V_92 , V_199 ) ;
memset ( V_195 . V_202 , 0 , V_201 ) ;
}
} while ( V_199 );
F_19 ( V_8 ) ;
F_9 ( V_195 . V_202 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ )
if ( V_8 -> V_69 [ V_36 ] -> V_203 )
F_131 ( V_8 -> V_69 [ V_36 ] ) ;
}
static int F_124 ( struct V_7 * V_8 )
{
int V_36 , V_83 = 0 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ ) {
V_83 = F_132 ( V_8 -> V_69 [ V_36 ] ) ;
if ( ! V_83 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_25 ,
V_92 , V_36 ) ;
break;
}
return V_83 ;
}
static int F_125 ( struct V_7 * V_8 )
{
int V_36 , V_83 = 0 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ ) {
V_83 = F_133 ( V_8 -> V_61 [ V_36 ] ) ;
if ( ! V_83 )
continue;
F_38 ( & V_8 -> V_12 -> V_13 ,
L_26 ,
V_92 , V_36 ) ;
break;
}
return V_83 ;
}
static void F_134 ( struct V_7 * V_8 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_77 -> V_78 ; V_36 ++ )
if ( V_8 -> V_61 [ V_36 ] -> V_203 )
F_135 ( V_8 -> V_61 [ V_36 ] ) ;
}
static int F_136 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_83 ;
if ( V_8 -> V_146 != V_178 )
return - V_206 ;
V_83 = F_124 ( V_8 ) ;
if ( V_83 )
goto V_207;
V_83 = F_125 ( V_8 ) ;
if ( V_83 )
goto V_208;
V_83 = F_32 ( V_8 , V_25 -> V_91 ) ;
if ( V_83 )
goto V_209;
F_69 ( V_8 ) ;
V_83 = F_72 ( V_8 ) ;
if ( V_83 )
goto V_209;
F_24 ( V_8 , true ) ;
return 0 ;
V_209:
F_78 ( V_8 ) ;
F_39 ( V_8 ) ;
V_208:
F_134 ( V_8 ) ;
V_207:
F_130 ( V_8 ) ;
return V_83 ;
}
static int F_126 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
V_8 -> V_146 = V_178 ;
F_137 ( V_148 , & V_8 -> V_63 . V_146 ) ;
F_78 ( V_8 ) ;
F_39 ( V_8 ) ;
F_130 ( V_8 ) ;
F_134 ( V_8 ) ;
return 0 ;
}
static struct V_210 * F_138 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
return & V_8 -> V_211 ;
}
void F_139 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_25 ;
int V_83 ;
F_140 ( F_141 () ) ;
V_8 -> V_146 = V_180 ;
F_78 ( V_8 ) ;
V_83 = F_124 ( V_8 ) ;
if ( V_83 )
goto V_212;
V_83 = F_125 ( V_8 ) ;
if ( V_83 )
goto V_212;
F_69 ( V_8 ) ;
V_83 = F_72 ( V_8 ) ;
if ( V_83 )
goto V_212;
F_24 ( V_8 , true ) ;
return;
V_212:
F_38 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_126 ( V_25 ) ;
}
static int F_142 ( struct V_24 * V_25 , int V_213 )
{
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_97 = V_213 + V_99 + V_100 ;
if ( ( V_213 < 68 ) || ( V_97 > V_214 ) )
return - V_215 ;
V_25 -> V_98 = V_213 ;
F_139 ( V_8 ) ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 )
{
T_3 V_216 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < 100 ; V_36 ++ ) {
V_216 = F_17 ( V_2 , V_29 ) ;
if ( V_216 == V_181 )
return 0 ;
F_119 ( 10 ) ;
}
return - V_206 ;
}
static void F_144 ( struct V_176 * V_177 )
{
struct V_7 * V_8 = F_101 ( V_177 ,
struct V_7 ,
V_217 . V_177 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
struct V_121 * V_111 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_218 * V_12 = V_8 -> V_12 ;
int V_36 , V_83 , V_219 ;
switch ( V_8 -> V_146 ) {
case V_220 :
V_83 = F_145 ( V_2 ) ;
if ( V_83 ) {
F_34 ( & V_12 -> V_13 , L_27 ,
V_92 , V_83 ) ;
goto V_83;
}
V_83 = F_143 ( V_2 ) ;
if ( V_83 ) {
F_34 ( & V_12 -> V_13 , L_28 ,
V_92 , V_83 ) ;
goto V_83;
}
V_2 -> V_221 . V_222 = V_223 ;
V_2 -> V_221 . V_224 = V_223 ;
V_2 -> V_221 . V_225 = V_201 ;
V_2 -> V_221 . V_226 = V_201 ;
V_83 = F_122 ( V_2 ) ;
if ( V_83 ) {
F_34 ( & V_12 -> V_13 , L_21 ,
V_92 , V_83 ) ;
goto V_83;
}
V_83 = F_146 ( V_8 ) ;
if ( V_83 ) {
F_34 ( & V_12 -> V_13 , L_29 ,
V_92 , V_83 ) ;
F_120 ( V_2 ) ;
goto V_83;
}
V_8 -> V_146 = V_227 ;
goto V_228;
break;
case V_227 :
if ( ! F_147 ( V_2 ) )
goto V_83;
V_83 = F_148 ( V_8 ) ;
if ( V_83 ) {
F_38 ( & V_12 -> V_13 , L_30 ,
V_83 ) ;
goto V_83;
}
V_83 = F_149 ( V_8 ) ;
if ( V_83 ) {
F_38 ( & V_12 -> V_13 , L_31 ,
V_83 ) ;
goto V_83;
}
V_8 -> V_146 = V_229 ;
goto V_228;
break;
case V_229 :
if ( ! V_8 -> V_164 ) {
V_219 = sizeof( struct V_230 ) +
( V_231 *
sizeof( struct V_232 ) ) ;
V_8 -> V_164 = F_7 ( V_219 , V_16 ) ;
if ( ! V_8 -> V_164 ) {
F_38 ( & V_12 -> V_13 , L_32 ,
V_92 ) ;
goto V_83;
}
}
V_83 = F_150 ( V_8 ) ;
if ( V_83 == V_233 )
goto V_228;
if ( V_83 ) {
F_34 ( & V_12 -> V_13 , L_33 ,
V_92 , V_83 ) ;
goto V_234;
}
V_8 -> V_146 = V_235 ;
break;
default:
goto V_234;
}
for ( V_36 = 0 ; V_36 < V_8 -> V_164 -> V_236 ; V_36 ++ ) {
if ( V_8 -> V_164 -> V_77 [ V_36 ] . V_237 == V_238 )
V_8 -> V_77 = & V_8 -> V_164 -> V_77 [ V_36 ] ;
}
if ( ! V_8 -> V_77 ) {
F_34 ( & V_12 -> V_13 , L_34 , V_92 ) ;
goto V_234;
}
V_8 -> V_102 |= V_239 ;
V_8 -> V_240 = V_160 ;
V_8 -> V_241 = V_161 ;
V_25 -> V_242 = & V_243 ;
F_151 ( V_25 ) ;
V_25 -> V_244 = 5 * V_183 ;
V_25 -> V_245 |= V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_252 ;
if ( V_8 -> V_164 -> V_253
& V_254 ) {
V_25 -> V_255 = V_25 -> V_245 ;
V_25 -> V_245 |= V_256 |
V_257 |
V_258 ;
}
if ( ! F_60 ( V_8 -> V_2 . V_134 . V_130 ) ) {
F_34 ( & V_12 -> V_13 ,
L_35 ,
V_8 -> V_2 . V_134 . V_130 ) ;
F_152 ( V_8 -> V_2 . V_134 . V_130 ) ;
}
memcpy ( V_25 -> V_133 , V_8 -> V_2 . V_134 . V_130 , V_25 -> V_135 ) ;
memcpy ( V_25 -> V_259 , V_8 -> V_2 . V_134 . V_130 , V_25 -> V_135 ) ;
F_48 ( & V_8 -> V_126 ) ;
F_48 ( & V_8 -> V_114 ) ;
V_111 = F_7 ( sizeof( * V_111 ) , V_112 ) ;
if ( NULL == V_111 )
goto V_260;
memcpy ( V_111 -> V_122 , V_8 -> V_2 . V_134 . V_130 , V_125 ) ;
V_111 -> V_115 = true ;
V_8 -> V_86 |= V_127 ;
F_49 ( & V_111 -> V_113 , & V_8 -> V_126 ) ;
F_153 ( & V_8 -> V_150 ) ;
V_8 -> V_150 . V_261 = & F_99 ;
V_8 -> V_150 . V_44 = ( unsigned long ) V_8 ;
F_111 ( & V_8 -> V_150 , V_151 + 1 ) ;
V_83 = F_98 ( V_8 ) ;
if ( V_83 )
goto V_260;
F_30 ( V_8 ) ;
F_113 ( V_8 ) ;
V_83 = F_37 ( V_8 ) ;
if ( V_83 )
goto V_260;
F_82 ( V_25 ) ;
strcpy ( V_25 -> V_91 , L_36 ) ;
V_8 -> V_63 . V_262 = V_8 -> V_77 -> V_263 ;
V_8 -> V_63 . V_264 = V_8 -> V_77 -> V_263 ;
V_8 -> V_63 . V_9 = V_8 ;
V_8 -> V_63 . V_265 = 1 ;
V_8 -> V_63 . V_266 = V_267 ;
V_8 -> V_63 . V_268 = V_269 ;
V_8 -> V_63 . V_270 = V_269 ;
V_8 -> V_63 . V_25 = V_8 -> V_25 ;
V_83 = F_154 ( V_25 ) ;
if ( V_83 )
goto V_271;
V_8 -> V_272 = true ;
F_81 ( V_25 ) ;
F_34 ( & V_12 -> V_13 , L_37 , V_8 -> V_2 . V_134 . V_130 ) ;
if ( V_25 -> V_245 & V_252 )
F_34 ( & V_12 -> V_13 , L_38 ) ;
F_34 ( & V_12 -> V_13 , L_39 , V_273 ) ;
V_8 -> V_146 = V_178 ;
F_137 ( V_148 , & V_8 -> V_63 . V_146 ) ;
F_19 ( V_8 ) ;
return;
V_228:
F_155 ( & V_8 -> V_217 ,
F_112 ( 50 ) ) ;
return;
V_271:
F_40 ( V_8 ) ;
V_260:
F_96 ( V_8 ) ;
V_8 -> V_146 = V_274 ;
V_234:
F_9 ( V_8 -> V_164 ) ;
V_8 -> V_164 = NULL ;
V_83:
if ( ++ V_8 -> V_275 > V_276 ) {
F_38 ( & V_12 -> V_13 , L_40 ) ;
if ( V_2 -> V_221 . V_277 . V_64 )
F_120 ( V_2 ) ;
V_8 -> V_146 = V_274 ;
return;
}
F_155 ( & V_8 -> V_217 , V_183 * 3 ) ;
return;
}
static void F_156 ( struct V_218 * V_12 )
{
struct V_24 * V_25 = F_157 ( V_12 ) ;
F_158 ( V_25 ) ;
if ( F_123 ( V_25 ) )
F_126 ( V_25 ) ;
#ifdef F_159
F_160 ( V_12 ) ;
#endif
F_161 ( V_12 ) ;
}
static int F_162 ( struct V_218 * V_12 , const struct V_278 * V_279 )
{
struct V_24 * V_25 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_83 , V_280 ;
V_83 = F_163 ( V_12 ) ;
if ( V_83 )
return V_83 ;
if ( ! F_164 ( & V_12 -> V_13 , F_165 ( 64 ) ) ) {
V_280 = true ;
F_166 ( & V_12 -> V_13 , F_165 ( 64 ) ) ;
} else if ( ! F_164 ( & V_12 -> V_13 , F_165 ( 32 ) ) ) {
V_280 = false ;
F_166 ( & V_12 -> V_13 , F_165 ( 32 ) ) ;
} else {
F_38 ( & V_12 -> V_13 , L_41 ,
V_92 , V_83 ) ;
V_83 = - V_156 ;
goto V_281;
}
V_83 = F_167 ( V_12 , V_282 ) ;
if ( V_83 ) {
F_38 ( & V_12 -> V_13 ,
L_42 , V_83 ) ;
goto V_283;
}
F_168 ( V_12 ) ;
F_169 ( V_12 ) ;
V_25 = F_170 ( sizeof( struct V_7 ) ,
V_284 ) ;
if ( ! V_25 ) {
V_83 = - V_120 ;
goto V_285;
}
F_171 ( V_25 , & V_12 -> V_13 ) ;
F_172 ( V_12 , V_25 ) ;
V_8 = F_13 ( V_25 ) ;
if ( V_280 )
V_25 -> V_245 |= V_286 ;
V_8 -> V_25 = V_25 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_287 = ( 1 << V_288 ) - 1 ;
V_8 -> V_146 = V_220 ;
F_160 ( V_12 ) ;
V_2 -> V_96 = F_173 ( F_174 ( V_12 , 0 ) ,
F_175 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_96 ) {
V_83 = - V_156 ;
goto V_289;
}
V_2 -> V_290 = V_12 -> V_291 ;
V_2 -> V_292 = V_12 -> V_293 ;
F_176 ( V_12 , V_294 , & V_2 -> V_295 ) ;
V_2 -> V_296 = V_12 -> V_297 ;
V_2 -> V_298 = V_12 -> V_299 ;
V_2 -> V_300 . V_293 = F_177 ( V_12 -> V_301 ) ;
V_2 -> V_300 . V_302 = F_178 ( V_12 -> V_301 ) ;
F_179 ( & V_8 -> V_27 , F_118 ) ;
F_179 ( & V_8 -> V_49 , F_127 ) ;
F_179 ( & V_8 -> V_175 , F_100 ) ;
F_180 ( & V_8 -> V_217 , F_144 ) ;
F_155 ( & V_8 -> V_217 , 10 ) ;
return 0 ;
V_289:
F_181 ( V_25 ) ;
V_285:
F_182 ( V_12 ) ;
V_283:
V_281:
F_161 ( V_12 ) ;
return V_83 ;
}
static int F_183 ( struct V_218 * V_12 , T_11 V_146 )
{
struct V_24 * V_25 = F_157 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
int V_303 = 0 ;
F_158 ( V_25 ) ;
if ( F_123 ( V_25 ) ) {
F_184 () ;
F_78 ( V_8 ) ;
F_185 () ;
}
F_40 ( V_8 ) ;
F_96 ( V_8 ) ;
V_303 = F_160 ( V_12 ) ;
if ( V_303 )
return V_303 ;
F_161 ( V_12 ) ;
return 0 ;
}
static int F_186 ( struct V_218 * V_12 )
{
struct V_7 * V_8 = F_157 ( V_12 ) ;
struct V_24 * V_25 = V_8 -> V_25 ;
T_3 V_83 ;
F_187 ( V_12 , V_304 ) ;
F_188 ( V_12 ) ;
F_160 ( V_12 ) ;
V_83 = F_189 ( V_12 ) ;
if ( V_83 ) {
F_38 ( & V_12 -> V_13 , L_43 ) ;
return V_83 ;
}
F_169 ( V_12 ) ;
F_184 () ;
V_83 = F_88 ( V_8 ) ;
if ( V_83 ) {
F_38 ( & V_12 -> V_13 , L_44 ) ;
return V_83 ;
}
V_83 = F_37 ( V_8 ) ;
F_185 () ;
if ( V_83 ) {
F_38 ( & V_12 -> V_13 , L_45 ) ;
return V_83 ;
}
F_14 ( & V_8 -> V_27 ) ;
F_190 ( V_25 ) ;
return V_83 ;
}
static void F_191 ( struct V_218 * V_12 )
{
struct V_24 * V_25 = F_157 ( V_12 ) ;
struct V_7 * V_8 = F_13 ( V_25 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_192 ( & V_8 -> V_217 ) ;
if ( V_8 -> V_272 ) {
F_193 ( V_25 ) ;
V_8 -> V_272 = false ;
}
V_8 -> V_146 = V_305 ;
if ( V_8 -> V_37 ) {
F_15 ( V_8 ) ;
F_194 ( & V_8 -> V_150 ) ;
F_195 () ;
F_40 ( V_8 ) ;
F_96 ( V_8 ) ;
}
if ( V_2 -> V_221 . V_277 . V_64 )
F_120 ( V_2 ) ;
F_196 ( V_2 -> V_96 ) ;
F_182 ( V_12 ) ;
F_85 ( V_8 ) ;
F_9 ( V_8 -> V_164 ) ;
F_181 ( V_25 ) ;
F_197 ( V_12 ) ;
F_161 ( V_12 ) ;
}
static int T_12 F_198 ( void )
{
int V_198 ;
F_11 ( L_46 , V_273 ,
V_306 ) ;
F_11 ( L_39 , V_307 ) ;
V_198 = F_199 ( & V_308 ) ;
return V_198 ;
}
static void T_13 F_200 ( void )
{
F_201 ( & V_308 ) ;
}
