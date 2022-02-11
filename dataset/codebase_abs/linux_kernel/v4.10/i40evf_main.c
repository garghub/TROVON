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
if ( F_37 ( V_97 , & V_8 -> V_67 . V_98 ) )
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
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_113 = V_2 -> V_114 + F_55 ( V_39 ) ;
V_8 -> V_65 [ V_39 ] . V_115 = V_116 ;
}
}
static struct
V_117 * F_56 ( struct V_7 * V_8 , T_7 V_118 )
{
struct V_117 * V_119 ;
F_57 (f, &adapter->vlan_filter_list, list) {
if ( V_118 == V_119 -> V_118 )
return V_119 ;
}
return NULL ;
}
static struct
V_117 * F_58 ( struct V_7 * V_8 , T_7 V_118 )
{
struct V_117 * V_119 = NULL ;
int V_68 = 50 ;
while ( F_59 ( V_120 ,
& V_8 -> V_121 ) ) {
F_60 ( 1 ) ;
if ( -- V_68 == 0 )
goto V_94;
}
V_119 = F_56 ( V_8 , V_118 ) ;
if ( ! V_119 ) {
V_119 = F_7 ( sizeof( * V_119 ) , V_122 ) ;
if ( ! V_119 )
goto V_123;
V_119 -> V_118 = V_118 ;
F_61 ( & V_119 -> V_124 ) ;
F_62 ( & V_119 -> V_124 , & V_8 -> V_125 ) ;
V_119 -> V_126 = true ;
V_8 -> V_95 |= V_127 ;
}
V_123:
F_63 ( V_120 , & V_8 -> V_121 ) ;
V_94:
return V_119 ;
}
static void F_64 ( struct V_7 * V_8 , T_7 V_118 )
{
struct V_117 * V_119 ;
int V_68 = 50 ;
while ( F_59 ( V_120 ,
& V_8 -> V_121 ) ) {
F_60 ( 1 ) ;
if ( -- V_68 == 0 )
return;
}
V_119 = F_56 ( V_8 , V_118 ) ;
if ( V_119 ) {
V_119 -> remove = true ;
V_8 -> V_95 |= V_128 ;
}
F_63 ( V_120 , & V_8 -> V_121 ) ;
}
static int F_65 ( struct V_28 * V_29 ,
T_8 T_9 V_129 , T_7 V_130 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( ! F_66 ( V_8 ) )
return - V_131 ;
if ( F_58 ( V_8 , V_130 ) == NULL )
return - V_132 ;
return 0 ;
}
static int F_67 ( struct V_28 * V_29 ,
T_8 T_9 V_129 , T_7 V_130 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( F_66 ( V_8 ) ) {
F_64 ( V_8 , V_130 ) ;
return 0 ;
}
return - V_131 ;
}
static struct
V_133 * F_68 ( struct V_7 * V_8 ,
T_10 * V_134 )
{
struct V_133 * V_119 ;
if ( ! V_134 )
return NULL ;
F_57 (f, &adapter->mac_filter_list, list) {
if ( F_69 ( V_134 , V_119 -> V_134 ) )
return V_119 ;
}
return NULL ;
}
static struct
V_133 * F_70 ( struct V_7 * V_8 ,
T_10 * V_134 )
{
struct V_133 * V_119 ;
int V_68 = 50 ;
if ( ! V_134 )
return NULL ;
while ( F_59 ( V_120 ,
& V_8 -> V_121 ) ) {
F_60 ( 1 ) ;
if ( -- V_68 == 0 )
return NULL ;
}
V_119 = F_68 ( V_8 , V_134 ) ;
if ( ! V_119 ) {
V_119 = F_7 ( sizeof( * V_119 ) , V_122 ) ;
if ( ! V_119 ) {
F_63 ( V_120 ,
& V_8 -> V_121 ) ;
return NULL ;
}
F_71 ( V_119 -> V_134 , V_134 ) ;
F_72 ( & V_119 -> V_124 , & V_8 -> V_135 ) ;
V_119 -> V_126 = true ;
V_8 -> V_95 |= V_136 ;
}
F_63 ( V_120 , & V_8 -> V_121 ) ;
return V_119 ;
}
static int F_73 ( struct V_28 * V_29 , void * V_137 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_133 * V_119 ;
struct V_138 * V_139 = V_137 ;
if ( ! F_74 ( V_139 -> V_140 ) )
return - V_141 ;
if ( F_69 ( V_29 -> V_142 , V_139 -> V_140 ) )
return 0 ;
if ( V_8 -> V_24 & V_143 )
return - V_144 ;
V_119 = F_68 ( V_8 , V_2 -> V_145 . V_139 ) ;
if ( V_119 ) {
V_119 -> remove = true ;
V_8 -> V_95 |= V_146 ;
}
V_119 = F_70 ( V_8 , V_139 -> V_140 ) ;
if ( V_119 ) {
F_71 ( V_2 -> V_145 . V_139 , V_139 -> V_140 ) ;
F_71 ( V_29 -> V_142 , V_8 -> V_2 . V_145 . V_139 ) ;
}
return ( V_119 == NULL ) ? - V_132 : 0 ;
}
static void F_75 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_133 * V_119 , * V_147 ;
struct V_148 * V_149 ;
struct V_148 * V_150 ;
struct V_148 * V_151 ;
int V_68 = 50 ;
F_76 (uca, netdev) {
F_70 ( V_8 , V_149 -> V_139 ) ;
}
F_77 (mca, netdev) {
F_70 ( V_8 , V_150 -> V_139 ) ;
}
while ( F_59 ( V_120 ,
& V_8 -> V_121 ) ) {
F_60 ( 1 ) ;
if ( -- V_68 == 0 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_9 , V_152 ) ;
return;
}
}
F_78 (f, ftmp, &adapter->mac_filter_list, list) {
F_77 (mca, netdev)
if ( F_69 ( V_150 -> V_139 , V_119 -> V_134 ) )
goto V_153;
F_76 (uca, netdev)
if ( F_69 ( V_149 -> V_139 , V_119 -> V_134 ) )
goto V_153;
F_79 (netdev, ha)
if ( F_69 ( V_151 -> V_139 , V_119 -> V_134 ) )
goto V_153;
if ( F_69 ( V_119 -> V_134 , V_8 -> V_2 . V_145 . V_139 ) )
goto V_153;
V_119 -> remove = true ;
V_8 -> V_95 |= V_146 ;
V_153:
continue;
}
if ( V_29 -> V_24 & V_154 &&
! ( V_8 -> V_24 & V_155 ) )
V_8 -> V_95 |= V_156 ;
else if ( ! ( V_29 -> V_24 & V_154 ) &&
V_8 -> V_24 & V_155 )
V_8 -> V_95 |= V_157 ;
if ( V_29 -> V_24 & V_158 &&
! ( V_8 -> V_24 & V_159 ) )
V_8 -> V_95 |= V_160 ;
else if ( ! ( V_29 -> V_24 & V_158 ) &&
V_8 -> V_24 & V_159 )
V_8 -> V_95 |= V_161 ;
F_63 ( V_120 , & V_8 -> V_121 ) ;
}
static void F_80 ( struct V_7 * V_8 )
{
int V_162 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_93 ;
for ( V_162 = 0 ; V_162 < V_62 ; V_162 ++ ) {
struct V_163 * V_59 ;
V_55 = & V_8 -> V_62 [ V_162 ] ;
V_59 = & V_55 -> V_59 ;
F_81 ( V_59 ) ;
}
}
static void F_82 ( struct V_7 * V_8 )
{
int V_162 ;
struct V_54 * V_55 ;
int V_62 = V_8 -> V_40 - V_93 ;
for ( V_162 = 0 ; V_162 < V_62 ; V_162 ++ ) {
V_55 = & V_8 -> V_62 [ V_162 ] ;
F_83 ( & V_55 -> V_59 ) ;
}
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
int V_39 ;
F_75 ( V_29 ) ;
F_52 ( V_8 ) ;
F_54 ( V_8 ) ;
V_8 -> V_95 |= V_164 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
struct V_63 * V_57 = & V_8 -> V_65 [ V_39 ] ;
F_85 ( V_57 , F_86 ( V_57 ) ) ;
}
}
static void F_87 ( struct V_7 * V_8 )
{
V_8 -> V_98 = V_165 ;
F_63 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_80 ( V_8 ) ;
V_8 -> V_95 |= V_166 ;
F_88 ( & V_8 -> V_167 , V_168 + 1 ) ;
}
void F_89 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_133 * V_119 ;
if ( V_8 -> V_98 <= V_169 )
return;
while ( F_59 ( V_120 ,
& V_8 -> V_121 ) )
F_90 ( 500 , 1000 ) ;
F_91 ( V_29 ) ;
F_92 ( V_29 ) ;
V_8 -> V_170 = false ;
F_82 ( V_8 ) ;
F_21 ( V_8 ) ;
F_57 (f, &adapter->mac_filter_list, list) {
V_119 -> remove = true ;
}
F_57 (f, &adapter->vlan_filter_list, list) {
V_119 -> remove = true ;
}
if ( ! ( V_8 -> V_24 & V_171 ) &&
V_8 -> V_98 != V_172 ) {
V_8 -> V_173 = V_174 ;
V_8 -> V_95 = V_146 ;
V_8 -> V_95 |= V_128 ;
V_8 -> V_95 |= V_175 ;
}
F_63 ( V_120 , & V_8 -> V_121 ) ;
}
static int
F_93 ( struct V_7 * V_8 , int V_176 )
{
int V_92 , V_177 ;
V_177 = V_178 ;
V_92 = F_94 ( V_8 -> V_12 , V_8 -> V_31 ,
V_177 , V_176 ) ;
if ( V_92 < 0 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_10 ) ;
F_9 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
return V_92 ;
}
V_8 -> V_40 = V_92 ;
return 0 ;
}
static void F_95 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_179 )
return;
F_9 ( V_8 -> V_79 ) ;
V_8 -> V_79 = NULL ;
F_9 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
}
static int F_96 ( struct V_7 * V_8 )
{
int V_39 ;
V_8 -> V_79 = F_97 ( V_8 -> V_87 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_79 )
goto V_180;
V_8 -> V_65 = F_97 ( V_8 -> V_87 ,
sizeof( struct V_63 ) , V_16 ) ;
if ( ! V_8 -> V_65 )
goto V_180;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
struct V_63 * V_78 ;
struct V_63 * V_64 ;
V_78 = & V_8 -> V_79 [ V_39 ] ;
V_78 -> V_181 = V_39 ;
V_78 -> V_29 = V_8 -> V_29 ;
V_78 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_78 -> V_68 = V_8 -> V_182 ;
V_78 -> V_80 = ( V_183 | V_184 ) ;
if ( V_8 -> V_24 & V_185 )
V_78 -> V_24 |= V_186 ;
V_64 = & V_8 -> V_65 [ V_39 ] ;
V_64 -> V_181 = V_39 ;
V_64 -> V_29 = V_8 -> V_29 ;
V_64 -> V_13 = & V_8 -> V_12 -> V_13 ;
V_64 -> V_68 = V_8 -> V_187 ;
V_64 -> V_72 = ( V_183 | V_188 ) ;
}
return 0 ;
V_180:
F_95 ( V_8 ) ;
return - V_132 ;
}
static int F_98 ( struct V_7 * V_8 )
{
int V_34 , V_189 ;
int V_190 = 0 ;
int V_92 = 0 ;
if ( ! V_8 -> V_179 ) {
V_92 = - V_131 ;
goto V_94;
}
V_190 = V_8 -> V_87 ;
V_189 = F_99 ( int , V_190 , ( int ) ( F_100 () * 2 ) ) + V_93 ;
V_189 = F_99 ( int , V_189 , ( int ) V_8 -> V_191 -> V_192 ) ;
V_8 -> V_31 = F_97 ( V_189 ,
sizeof( struct V_193 ) , V_16 ) ;
if ( ! V_8 -> V_31 ) {
V_92 = - V_132 ;
goto V_94;
}
for ( V_34 = 0 ; V_34 < V_189 ; V_34 ++ )
V_8 -> V_31 [ V_34 ] . V_194 = V_34 ;
V_92 = F_93 ( V_8 , V_189 ) ;
V_94:
F_101 ( V_8 -> V_29 , V_190 ) ;
F_102 ( V_8 -> V_29 , V_190 ) ;
return V_92 ;
}
static int F_103 ( struct V_7 * V_8 )
{
struct V_195 * V_196 =
(struct V_195 * ) V_8 -> V_196 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_197 = 0 ;
if ( V_8 -> V_173 != V_174 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_11 ,
V_8 -> V_173 ) ;
return - V_198 ;
}
V_197 = F_104 ( V_2 , V_8 -> V_67 . V_199 , V_196 ) ;
if ( V_197 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_12 ,
F_105 ( V_2 , V_197 ) ,
F_106 ( V_2 , V_2 -> V_200 . V_201 ) ) ;
return V_197 ;
}
V_197 = F_107 ( V_2 , V_8 -> V_67 . V_199 , false ,
V_8 -> V_202 , V_8 -> V_203 ) ;
if ( V_197 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_13 ,
F_105 ( V_2 , V_197 ) ,
F_106 ( V_2 , V_2 -> V_200 . V_201 ) ) ;
}
return V_197 ;
}
static int F_108 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 * V_204 ;
T_7 V_39 ;
V_204 = ( T_3 * ) V_8 -> V_196 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_205 / 4 ; V_39 ++ )
F_17 ( V_2 , F_109 ( V_39 ) , V_204 [ V_39 ] ) ;
V_204 = ( T_3 * ) V_8 -> V_202 ;
for ( V_39 = 0 ; V_39 <= V_8 -> V_203 / 4 ; V_39 ++ )
F_17 ( V_2 , F_110 ( V_39 ) , V_204 [ V_39 ] ) ;
F_111 ( V_2 ) ;
return 0 ;
}
int F_112 ( struct V_7 * V_8 )
{
if ( F_113 ( V_8 ) ) {
V_8 -> V_95 |= V_206 |
V_207 ;
return 0 ;
} else if ( F_114 ( V_8 ) ) {
return F_103 ( V_8 ) ;
} else {
return F_108 ( V_8 ) ;
}
}
static void F_115 ( struct V_7 * V_8 )
{
T_7 V_39 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_203 ; V_39 ++ )
V_8 -> V_202 [ V_39 ] = V_39 % V_8 -> V_87 ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_197 ;
if ( ! F_113 ( V_8 ) ) {
if ( V_8 -> V_191 -> V_208 &
V_209 )
V_8 -> V_210 = V_211 ;
else
V_8 -> V_210 = V_212 ;
F_17 ( V_2 , F_117 ( 0 ) , ( T_3 ) V_8 -> V_210 ) ;
F_17 ( V_2 , F_117 ( 1 ) , ( T_3 ) ( V_8 -> V_210 >> 32 ) ) ;
}
F_115 ( V_8 ) ;
F_118 ( ( void * ) V_8 -> V_196 , V_8 -> V_205 ) ;
V_197 = F_112 ( V_8 ) ;
return V_197 ;
}
static int F_119 ( struct V_7 * V_8 )
{
int V_162 = 0 , V_213 ;
struct V_54 * V_55 ;
V_213 = V_8 -> V_40 - V_93 ;
V_8 -> V_62 = F_97 ( V_213 , sizeof( * V_55 ) ,
V_16 ) ;
if ( ! V_8 -> V_62 )
return - V_132 ;
for ( V_162 = 0 ; V_162 < V_213 ; V_162 ++ ) {
V_55 = & V_8 -> V_62 [ V_162 ] ;
V_55 -> V_8 = V_8 ;
V_55 -> V_67 = & V_8 -> V_67 ;
V_55 -> V_60 = V_162 ;
F_120 ( V_8 -> V_29 , & V_55 -> V_59 ,
V_214 , V_215 ) ;
}
return 0 ;
}
static void F_121 ( struct V_7 * V_8 )
{
int V_162 , V_213 ;
int V_216 ;
if ( ! V_8 -> V_62 )
return;
V_213 = V_8 -> V_40 - V_93 ;
V_216 = V_8 -> V_87 ;
for ( V_162 = 0 ; V_162 < V_213 ; V_162 ++ ) {
struct V_54 * V_55 = & V_8 -> V_62 [ V_162 ] ;
if ( V_162 < V_216 )
F_122 ( & V_55 -> V_59 ) ;
}
F_9 ( V_8 -> V_62 ) ;
V_8 -> V_62 = NULL ;
}
void F_123 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_31 )
return;
F_124 ( V_8 -> V_12 ) ;
F_9 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
}
int F_125 ( struct V_7 * V_8 )
{
int V_92 ;
F_126 () ;
V_92 = F_98 ( V_8 ) ;
F_127 () ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_14 ) ;
goto V_217;
}
V_92 = F_119 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_15 ) ;
goto V_218;
}
V_92 = F_96 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_8 -> V_12 -> V_13 ,
L_16 ) ;
goto V_219;
}
F_43 ( & V_8 -> V_12 -> V_13 , L_17 ,
( V_8 -> V_87 > 1 ) ? L_18 : L_19 ,
V_8 -> V_87 ) ;
return 0 ;
V_219:
F_121 ( V_8 ) ;
V_218:
F_123 ( V_8 ) ;
V_217:
return V_92 ;
}
static void F_128 ( struct V_7 * V_8 )
{
F_9 ( V_8 -> V_196 ) ;
V_8 -> V_196 = NULL ;
F_9 ( V_8 -> V_202 ) ;
V_8 -> V_202 = NULL ;
}
static void F_129 ( unsigned long V_48 )
{
struct V_7 * V_8 = (struct V_7 * ) V_48 ;
F_13 ( & V_8 -> V_220 ) ;
}
static void F_130 ( struct V_221 * V_222 )
{
struct V_7 * V_8 = F_39 ( V_222 ,
struct V_7 ,
V_220 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
T_3 V_223 ;
if ( F_59 ( V_120 , & V_8 -> V_121 ) )
goto V_224;
if ( V_8 -> V_24 & V_171 ) {
V_223 = F_18 ( V_2 , V_33 ) &
V_225 ;
if ( ( V_223 == V_226 ) ||
( V_223 == V_227 ) ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_20 ) ;
V_8 -> V_98 = V_228 ;
V_8 -> V_24 &= ~ V_171 ;
F_131 ( & V_8 -> V_229 , 10 ) ;
F_63 ( V_120 ,
& V_8 -> V_121 ) ;
return;
}
V_8 -> V_95 = 0 ;
V_8 -> V_173 = V_174 ;
goto V_230;
}
if ( ( V_8 -> V_98 < V_231 ) ||
( V_8 -> V_24 & V_25 ) )
goto V_230;
V_223 = F_18 ( V_2 , V_232 ) & V_233 ;
if ( ! ( V_8 -> V_24 & V_25 ) && ! V_223 ) {
V_8 -> V_98 = V_172 ;
V_8 -> V_24 |= V_25 ;
F_49 ( & V_8 -> V_12 -> V_13 , L_21 ) ;
F_13 ( & V_8 -> V_27 ) ;
V_8 -> V_95 = 0 ;
V_8 -> V_173 = V_174 ;
goto V_230;
}
if ( V_8 -> V_173 ) {
if ( ! F_132 ( V_2 ) ) {
F_133 ( & V_8 -> V_12 -> V_13 , L_22 ) ;
F_134 ( V_8 ) ;
}
goto V_230;
}
if ( V_8 -> V_95 & V_234 ) {
F_135 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_175 ) {
F_136 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_96 ) {
F_137 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_136 ) {
F_138 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_127 ) {
F_139 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_146 ) {
F_140 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_128 ) {
F_141 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_164 ) {
F_142 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_166 ) {
F_143 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_235 ) {
F_116 ( V_8 ) ;
V_8 -> V_95 &= ~ V_235 ;
goto V_230;
}
if ( V_8 -> V_95 & V_236 ) {
F_144 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_237 ) {
F_145 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_207 ) {
F_146 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_206 ) {
F_147 ( V_8 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_156 ) {
F_148 ( V_8 , V_238 |
V_239 ) ;
goto V_230;
}
if ( V_8 -> V_95 & V_160 ) {
F_148 ( V_8 , V_239 ) ;
goto V_230;
}
if ( ( V_8 -> V_95 & V_157 ) &&
( V_8 -> V_95 & V_161 ) ) {
F_148 ( V_8 , 0 ) ;
goto V_230;
}
if ( V_8 -> V_98 == V_165 )
F_149 ( V_8 ) ;
V_230:
if ( V_8 -> V_98 == V_165 ) {
F_23 ( V_8 , ~ 0 ) ;
F_25 ( V_8 , 0xFF ) ;
} else {
F_25 ( V_8 , 0x1 ) ;
}
F_63 ( V_120 , & V_8 -> V_121 ) ;
V_224:
if ( V_8 -> V_98 == V_240 )
return;
if ( V_8 -> V_95 )
F_150 ( & V_8 -> V_167 ,
V_168 + F_151 ( 20 ) ) ;
else
F_150 ( & V_8 -> V_167 , V_168 + ( V_241 * 2 ) ) ;
F_13 ( & V_8 -> V_52 ) ;
}
static void F_152 ( struct V_7 * V_8 )
{
struct V_133 * V_119 , * V_147 ;
struct V_117 * V_242 , * V_243 ;
V_8 -> V_24 |= V_171 ;
if ( F_153 ( V_8 -> V_29 ) ) {
F_154 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_91 ( V_8 -> V_29 ) ;
F_92 ( V_8 -> V_29 ) ;
V_8 -> V_170 = false ;
F_82 ( V_8 ) ;
F_21 ( V_8 ) ;
F_50 ( V_8 ) ;
F_155 ( V_8 ) ;
F_156 ( V_8 ) ;
}
F_78 (f, ftmp, &adapter->mac_filter_list, list) {
F_157 ( & V_119 -> V_124 ) ;
F_9 ( V_119 ) ;
}
F_78 (fv, fvtmp, &adapter->vlan_filter_list, list) {
F_157 ( & V_242 -> V_124 ) ;
F_9 ( V_242 ) ;
}
F_51 ( V_8 ) ;
F_123 ( V_8 ) ;
F_95 ( V_8 ) ;
F_121 ( V_8 ) ;
F_9 ( V_8 -> V_191 ) ;
F_158 ( & V_8 -> V_2 ) ;
V_8 -> V_29 -> V_24 &= ~ V_244 ;
F_63 ( V_120 , & V_8 -> V_121 ) ;
V_8 -> V_24 &= ~ V_25 ;
V_8 -> V_98 = V_231 ;
F_43 ( & V_8 -> V_12 -> V_13 , L_23 ) ;
}
static void F_159 ( struct V_221 * V_222 )
{
struct V_7 * V_8 = F_39 ( V_222 ,
struct V_7 ,
V_27 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_117 * V_245 ;
struct V_133 * V_119 ;
T_3 V_223 ;
int V_39 = 0 , V_92 ;
while ( F_59 ( V_120 ,
& V_8 -> V_121 ) )
F_90 ( 500 , 1000 ) ;
F_16 ( V_8 ) ;
if ( V_8 -> V_24 & V_26 ) {
V_8 -> V_24 &= ~ V_26 ;
F_158 ( V_2 ) ;
F_160 ( V_2 ) ;
F_161 ( V_8 ) ;
}
V_8 -> V_24 |= V_25 ;
for ( V_39 = 0 ; V_39 < V_246 ; V_39 ++ ) {
V_223 = F_18 ( V_2 , V_232 ) &
V_233 ;
if ( ! V_223 )
break;
F_90 ( 5000 , 10000 ) ;
}
if ( V_39 == V_246 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_24 ) ;
goto V_247;
}
for ( V_39 = 0 ; V_39 < V_246 ; V_39 ++ ) {
F_162 ( V_248 ) ;
V_223 = F_18 ( V_2 , V_33 ) &
V_225 ;
if ( V_223 == V_226 )
break;
}
F_163 ( V_8 -> V_12 ) ;
if ( V_39 == V_246 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_25 ,
V_223 ) ;
F_152 ( V_8 ) ;
return;
}
V_247:
if ( F_153 ( V_8 -> V_29 ) ) {
F_91 ( V_29 ) ;
F_164 ( V_29 ) ;
V_8 -> V_170 = false ;
F_82 ( V_8 ) ;
}
F_21 ( V_8 ) ;
V_8 -> V_98 = V_172 ;
V_8 -> V_24 &= ~ V_25 ;
F_156 ( V_8 ) ;
F_155 ( V_8 ) ;
F_158 ( V_2 ) ;
V_8 -> V_173 = V_174 ;
V_92 = F_160 ( V_2 ) ;
if ( V_92 )
F_43 ( & V_8 -> V_12 -> V_13 , L_26 ,
V_92 ) ;
V_8 -> V_95 = V_234 ;
V_8 -> V_95 |= V_96 ;
F_57 (f, &adapter->mac_filter_list, list) {
V_119 -> V_126 = true ;
}
F_57 (vlf, &adapter->vlan_filter_list, list) {
V_245 -> V_126 = true ;
}
V_8 -> V_95 |= V_136 ;
V_8 -> V_95 |= V_127 ;
V_8 -> V_95 |= V_249 ;
F_63 ( V_120 , & V_8 -> V_121 ) ;
F_20 ( V_8 ) ;
F_150 ( & V_8 -> V_167 , V_168 + 2 ) ;
if ( F_153 ( V_8 -> V_29 ) ) {
V_92 = F_165 ( V_8 ) ;
if ( V_92 )
goto V_250;
V_92 = F_166 ( V_8 ) ;
if ( V_92 )
goto V_250;
F_84 ( V_8 ) ;
F_87 ( V_8 ) ;
F_26 ( V_8 , true ) ;
} else {
V_8 -> V_98 = V_231 ;
}
return;
V_250:
F_49 ( & V_8 -> V_12 -> V_13 , L_27 ) ;
F_167 ( V_8 -> V_29 ) ;
}
static void F_168 ( struct V_221 * V_222 )
{
struct V_7 * V_8 =
F_39 ( V_222 , struct V_7 , V_52 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_251 V_252 ;
struct V_253 * V_254 ;
T_1 V_197 ;
T_3 V_49 , V_255 ;
T_7 V_256 ;
if ( V_8 -> V_24 & V_171 )
goto V_94;
V_252 . V_257 = V_258 ;
V_252 . V_259 = F_7 ( V_252 . V_257 , V_16 ) ;
if ( ! V_252 . V_259 )
goto V_94;
V_254 = (struct V_253 * ) & V_252 . V_260 ;
do {
V_197 = F_169 ( V_2 , & V_252 , & V_256 ) ;
if ( V_197 || ! V_254 -> V_261 )
break;
F_170 ( V_8 , V_254 -> V_261 ,
V_254 -> V_262 , V_252 . V_259 ,
V_252 . V_263 ) ;
if ( V_256 != 0 )
memset ( V_252 . V_259 , 0 , V_258 ) ;
} while ( V_256 );
if ( ( V_8 -> V_24 &
( V_25 | V_26 ) ) ||
V_8 -> V_98 == V_172 )
goto V_264;
V_49 = F_18 ( V_2 , V_2 -> V_200 . V_265 . V_266 ) ;
if ( V_49 == 0xdeadbeef )
goto V_264;
V_255 = V_49 ;
if ( V_49 & V_267 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_28 ) ;
V_49 &= ~ V_267 ;
}
if ( V_49 & V_268 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_29 ) ;
V_49 &= ~ V_268 ;
}
if ( V_49 & V_269 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_30 ) ;
V_49 &= ~ V_269 ;
}
if ( V_255 != V_49 )
F_17 ( V_2 , V_2 -> V_200 . V_265 . V_266 , V_49 ) ;
V_49 = F_18 ( V_2 , V_2 -> V_200 . V_270 . V_266 ) ;
V_255 = V_49 ;
if ( V_49 & V_271 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_31 ) ;
V_49 &= ~ V_271 ;
}
if ( V_49 & V_272 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_32 ) ;
V_49 &= ~ V_272 ;
}
if ( V_49 & V_273 ) {
F_43 ( & V_8 -> V_12 -> V_13 , L_33 ) ;
V_49 &= ~ V_273 ;
}
if ( V_255 != V_49 )
F_17 ( V_2 , V_2 -> V_200 . V_270 . V_266 , V_49 ) ;
V_264:
F_9 ( V_252 . V_259 ) ;
V_94:
F_20 ( V_8 ) ;
}
void F_155 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_79 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
if ( V_8 -> V_79 [ V_39 ] . V_260 )
F_171 ( & V_8 -> V_79 [ V_39 ] ) ;
}
static int F_165 ( struct V_7 * V_8 )
{
int V_39 , V_92 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_79 [ V_39 ] . V_68 = V_8 -> V_182 ;
V_92 = F_172 ( & V_8 -> V_79 [ V_39 ] ) ;
if ( ! V_92 )
continue;
F_49 ( & V_8 -> V_12 -> V_13 ,
L_34 , V_39 ) ;
break;
}
return V_92 ;
}
static int F_166 ( struct V_7 * V_8 )
{
int V_39 , V_92 = 0 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ ) {
V_8 -> V_65 [ V_39 ] . V_68 = V_8 -> V_187 ;
V_92 = F_173 ( & V_8 -> V_65 [ V_39 ] ) ;
if ( ! V_92 )
continue;
F_49 ( & V_8 -> V_12 -> V_13 ,
L_35 , V_39 ) ;
break;
}
return V_92 ;
}
void F_156 ( struct V_7 * V_8 )
{
int V_39 ;
if ( ! V_8 -> V_65 )
return;
for ( V_39 = 0 ; V_39 < V_8 -> V_87 ; V_39 ++ )
if ( V_8 -> V_65 [ V_39 ] . V_260 )
F_174 ( & V_8 -> V_65 [ V_39 ] ) ;
}
static int F_175 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_92 ;
if ( V_8 -> V_24 & V_171 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_36 ) ;
return - V_131 ;
}
if ( V_8 -> V_98 != V_231 )
return - V_198 ;
V_92 = F_165 ( V_8 ) ;
if ( V_92 )
goto V_274;
V_92 = F_166 ( V_8 ) ;
if ( V_92 )
goto V_275;
V_92 = F_41 ( V_8 , V_29 -> V_109 ) ;
if ( V_92 )
goto V_276;
F_70 ( V_8 , V_8 -> V_2 . V_145 . V_139 ) ;
F_84 ( V_8 ) ;
F_87 ( V_8 ) ;
F_26 ( V_8 , true ) ;
return 0 ;
V_276:
F_89 ( V_8 ) ;
F_50 ( V_8 ) ;
V_275:
F_156 ( V_8 ) ;
V_274:
F_155 ( V_8 ) ;
return V_92 ;
}
static int F_167 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
if ( V_8 -> V_98 <= V_169 )
return 0 ;
F_154 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_89 ( V_8 ) ;
V_8 -> V_98 = V_169 ;
F_50 ( V_8 ) ;
return 0 ;
}
static struct V_277 * F_176 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
return & V_8 -> V_278 ;
}
static int F_177 ( struct V_28 * V_29 , int V_279 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_29 -> V_280 = V_279 ;
V_8 -> V_24 |= V_26 ;
F_13 ( & V_8 -> V_27 ) ;
return 0 ;
}
static T_11 F_178 ( struct V_281 * V_282 ,
struct V_28 * V_13 ,
T_11 V_283 )
{
T_12 V_266 ;
if ( V_282 -> V_284 != V_285 )
return V_283 ;
if ( F_179 ( V_282 ) && ( F_180 ( V_282 ) -> V_286 < 64 ) )
V_283 &= ~ V_287 ;
V_266 = F_181 ( V_282 ) - V_282 -> V_48 ;
if ( V_266 & ~ ( 63 * 2 ) )
goto V_288;
V_266 = F_182 ( V_282 ) - F_181 ( V_282 ) ;
if ( V_266 & ~ ( 127 * 4 ) )
goto V_288;
if ( V_282 -> V_289 ) {
V_266 = F_183 ( V_282 ) - F_182 ( V_282 ) ;
if ( V_266 & ~ ( 127 * 2 ) )
goto V_288;
V_266 = F_184 ( V_282 ) -
F_183 ( V_282 ) ;
if ( V_266 & ~ ( 127 * 4 ) )
goto V_288;
}
return V_283 ;
V_288:
return V_283 & ~ ( V_290 | V_287 ) ;
}
static T_11 F_185 ( struct V_28 * V_29 ,
T_11 V_283 )
{
struct V_7 * V_8 = F_15 ( V_29 ) ;
V_283 &= ~ V_291 ;
if ( V_8 -> V_191 -> V_208 & V_292 )
V_283 |= V_291 ;
return V_283 ;
}
static int F_186 ( struct V_1 * V_2 )
{
T_3 V_293 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 100 ; V_39 ++ ) {
V_293 = F_18 ( V_2 , V_33 ) &
V_225 ;
if ( ( V_293 == V_226 ) ||
( V_293 == V_227 ) )
return 0 ;
F_90 ( 10 , 20 ) ;
}
return - V_198 ;
}
int F_187 ( struct V_7 * V_8 )
{
struct V_294 * V_295 = V_8 -> V_191 ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_296 * V_67 = & V_8 -> V_67 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_295 -> V_297 ; V_39 ++ ) {
if ( V_295 -> V_179 [ V_39 ] . V_298 == V_299 )
V_8 -> V_179 = & V_295 -> V_179 [ V_39 ] ;
}
if ( ! V_8 -> V_179 ) {
F_49 ( & V_8 -> V_12 -> V_13 , L_37 ) ;
return - V_300 ;
}
V_29 -> V_301 |= V_302 |
V_303 |
V_304 |
V_305 |
V_306 |
V_307 |
V_308 |
V_309 |
V_310 |
V_311 |
V_312 |
V_313 |
V_314 |
V_315 |
V_316 |
V_317 |
V_318 |
V_319 |
0 ;
if ( ! ( V_8 -> V_24 & V_320 ) )
V_29 -> V_321 |= V_315 ;
V_29 -> V_321 |= V_311 ;
V_29 -> V_322 |= V_29 -> V_301 |
V_323 ;
V_29 -> V_324 |= V_29 -> V_301 ;
V_29 -> V_283 |= V_29 -> V_301 | V_291 ;
V_29 -> V_301 |= V_323 ;
if ( ! ( V_295 -> V_208 & V_292 ) )
V_29 -> V_283 ^= V_291 ;
V_8 -> V_67 . V_199 = V_8 -> V_179 -> V_325 ;
V_8 -> V_67 . V_9 = V_8 ;
V_8 -> V_67 . V_326 = 1 ;
V_8 -> V_67 . V_327 = V_328 ;
V_67 -> V_29 = V_8 -> V_29 ;
V_67 -> V_329 = V_8 -> V_179 -> V_330 ;
if ( V_295 -> V_208 & V_331 ) {
V_8 -> V_205 = V_295 -> V_205 ;
V_8 -> V_203 = V_295 -> V_203 ;
} else {
V_8 -> V_205 = V_332 ;
V_8 -> V_203 = V_333 ;
}
return 0 ;
}
static void F_188 ( struct V_221 * V_222 )
{
struct V_7 * V_8 = F_39 ( V_222 ,
struct V_7 ,
V_229 . V_222 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_334 * V_12 = V_8 -> V_12 ;
int V_92 , V_335 ;
switch ( V_8 -> V_98 ) {
case V_228 :
V_8 -> V_24 &= ~ V_171 ;
V_8 -> V_24 &= ~ V_25 ;
V_92 = F_189 ( V_2 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_38 ,
V_92 ) ;
goto V_92;
}
V_92 = F_186 ( V_2 ) ;
if ( V_92 ) {
F_43 ( & V_12 -> V_13 , L_39 ,
V_92 ) ;
goto V_92;
}
V_2 -> V_200 . V_336 = V_337 ;
V_2 -> V_200 . V_338 = V_337 ;
V_2 -> V_200 . V_339 = V_258 ;
V_2 -> V_200 . V_340 = V_258 ;
V_92 = F_160 ( V_2 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_40 ,
V_92 ) ;
goto V_92;
}
V_92 = F_134 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_41 , V_92 ) ;
F_158 ( V_2 ) ;
goto V_92;
}
V_8 -> V_98 = V_341 ;
goto V_342;
case V_341 :
if ( ! F_132 ( V_2 ) ) {
F_49 ( & V_12 -> V_13 , L_42 ) ;
F_158 ( V_2 ) ;
V_8 -> V_98 = V_228 ;
goto V_92;
}
V_92 = F_190 ( V_8 ) ;
if ( V_92 ) {
if ( V_92 == V_343 )
V_92 = F_134 ( V_8 ) ;
else
F_49 ( & V_12 -> V_13 , L_43 ,
V_8 -> V_344 . V_345 ,
V_8 -> V_344 . V_346 ,
V_347 ,
V_348 ) ;
goto V_92;
}
V_92 = F_135 ( V_8 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_44 ,
V_92 ) ;
goto V_92;
}
V_8 -> V_98 = V_349 ;
goto V_342;
case V_349 :
if ( ! V_8 -> V_191 ) {
V_335 = sizeof( struct V_294 ) +
( V_350 *
sizeof( struct V_351 ) ) ;
V_8 -> V_191 = F_7 ( V_335 , V_16 ) ;
if ( ! V_8 -> V_191 )
goto V_92;
}
V_92 = F_191 ( V_8 ) ;
if ( V_92 == V_343 ) {
V_92 = F_135 ( V_8 ) ;
goto V_92;
} else if ( V_92 == V_10 ) {
F_158 ( V_2 ) ;
F_49 ( & V_12 -> V_13 , L_45 ) ;
return;
}
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_46 ,
V_92 ) ;
goto V_352;
}
V_8 -> V_98 = V_353 ;
break;
default:
goto V_352;
}
if ( V_2 -> V_145 . type == V_354 )
V_8 -> V_24 |= V_320 ;
if ( F_187 ( V_8 ) )
goto V_352;
V_8 -> V_173 = V_174 ;
V_8 -> V_24 |= V_355 ;
V_29 -> V_356 = & V_357 ;
F_192 ( V_29 ) ;
V_29 -> V_358 = 5 * V_241 ;
V_29 -> V_359 = V_360 ;
V_29 -> V_361 = V_362 - ( V_363 + V_364 ) ;
if ( ! F_74 ( V_8 -> V_2 . V_145 . V_139 ) ) {
F_43 ( & V_12 -> V_13 , L_47 ,
V_8 -> V_2 . V_145 . V_139 ) ;
F_193 ( V_29 ) ;
F_71 ( V_8 -> V_2 . V_145 . V_139 , V_29 -> V_142 ) ;
} else {
V_8 -> V_24 |= V_143 ;
F_71 ( V_29 -> V_142 , V_8 -> V_2 . V_145 . V_139 ) ;
F_71 ( V_29 -> V_365 , V_8 -> V_2 . V_145 . V_139 ) ;
}
F_194 ( & V_8 -> V_167 ) ;
V_8 -> V_167 . V_366 = & F_129 ;
V_8 -> V_167 . V_48 = ( unsigned long ) V_8 ;
F_150 ( & V_8 -> V_167 , V_168 + 1 ) ;
V_8 -> V_87 = F_99 ( int ,
V_8 -> V_179 -> V_367 ,
( int ) ( F_100 () ) ) ;
V_8 -> V_182 = V_368 ;
V_8 -> V_187 = V_369 ;
V_92 = F_125 ( V_8 ) ;
if ( V_92 )
goto V_370;
F_34 ( V_8 ) ;
if ( V_8 -> V_191 -> V_208 &
V_371 )
V_8 -> V_24 |= V_372 ;
V_92 = F_47 ( V_8 ) ;
if ( V_92 )
goto V_370;
F_91 ( V_29 ) ;
V_8 -> V_170 = false ;
if ( ! V_8 -> V_373 ) {
V_92 = F_195 ( V_29 ) ;
if ( V_92 )
goto V_374;
}
V_8 -> V_373 = true ;
F_164 ( V_29 ) ;
F_43 ( & V_12 -> V_13 , L_48 , V_8 -> V_2 . V_145 . V_139 ) ;
if ( V_29 -> V_283 & V_375 )
F_43 ( & V_12 -> V_13 , L_49 ) ;
V_8 -> V_98 = V_231 ;
F_154 ( V_97 , & V_8 -> V_67 . V_98 ) ;
F_20 ( V_8 ) ;
V_8 -> V_196 = F_7 ( V_8 -> V_205 , V_16 ) ;
V_8 -> V_202 = F_7 ( V_8 -> V_203 , V_16 ) ;
if ( ! V_8 -> V_196 || ! V_8 -> V_202 )
goto V_376;
if ( F_114 ( V_8 ) ) {
V_8 -> V_95 |= V_235 ;
F_88 ( & V_8 -> V_167 , V_168 + 1 ) ;
} else {
F_116 ( V_8 ) ;
}
return;
V_342:
F_131 ( & V_8 -> V_229 , F_151 ( 30 ) ) ;
return;
V_376:
F_128 ( V_8 ) ;
V_374:
F_51 ( V_8 ) ;
V_370:
F_123 ( V_8 ) ;
V_352:
F_9 ( V_8 -> V_191 ) ;
V_8 -> V_191 = NULL ;
V_92:
if ( ++ V_8 -> V_377 > V_378 ) {
F_49 ( & V_12 -> V_13 , L_50 ) ;
V_8 -> V_24 |= V_171 ;
F_158 ( V_2 ) ;
V_8 -> V_98 = V_228 ;
F_131 ( & V_8 -> V_229 , V_241 * 5 ) ;
return;
}
F_131 ( & V_8 -> V_229 , V_241 ) ;
}
static void F_196 ( struct V_334 * V_12 )
{
struct V_28 * V_29 = F_197 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
F_198 ( V_29 ) ;
if ( F_153 ( V_29 ) )
F_167 ( V_29 ) ;
V_8 -> V_98 = V_240 ;
V_8 -> V_95 = 0 ;
#ifdef F_199
F_200 ( V_12 ) ;
#endif
F_201 ( V_12 ) ;
}
static int F_202 ( struct V_334 * V_12 , const struct V_379 * V_380 )
{
struct V_28 * V_29 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_92 ;
V_92 = F_203 ( V_12 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_204 ( & V_12 -> V_13 , F_205 ( 64 ) ) ;
if ( V_92 ) {
V_92 = F_204 ( & V_12 -> V_13 , F_205 ( 32 ) ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 ,
L_51 , V_92 ) ;
goto V_381;
}
}
V_92 = F_206 ( V_12 , V_382 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 ,
L_52 , V_92 ) ;
goto V_383;
}
F_207 ( V_12 ) ;
F_163 ( V_12 ) ;
V_29 = F_208 ( sizeof( struct V_7 ) , V_384 ) ;
if ( ! V_29 ) {
V_92 = - V_132 ;
goto V_385;
}
F_209 ( V_29 , & V_12 -> V_13 ) ;
F_210 ( V_12 , V_29 ) ;
V_8 = F_15 ( V_29 ) ;
V_8 -> V_29 = V_29 ;
V_8 -> V_12 = V_12 ;
V_2 = & V_8 -> V_2 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_386 = F_24 ( V_387 ) - 1 ;
V_8 -> V_98 = V_228 ;
F_200 ( V_12 ) ;
V_2 -> V_114 = F_211 ( F_212 ( V_12 , 0 ) ,
F_213 ( V_12 , 0 ) ) ;
if ( ! V_2 -> V_114 ) {
V_92 = - V_131 ;
goto V_388;
}
V_2 -> V_389 = V_12 -> V_390 ;
V_2 -> V_391 = V_12 -> V_392 ;
F_214 ( V_12 , V_393 , & V_2 -> V_394 ) ;
V_2 -> V_395 = V_12 -> V_396 ;
V_2 -> V_397 = V_12 -> V_398 ;
V_2 -> V_399 . V_392 = F_215 ( V_12 -> V_400 ) ;
V_2 -> V_399 . V_401 = F_216 ( V_12 -> V_400 ) ;
F_217 ( & V_2 -> V_200 . V_402 ) ;
F_217 ( & V_2 -> V_200 . V_403 ) ;
F_61 ( & V_8 -> V_135 ) ;
F_61 ( & V_8 -> V_125 ) ;
F_218 ( & V_8 -> V_27 , F_159 ) ;
F_218 ( & V_8 -> V_52 , F_168 ) ;
F_218 ( & V_8 -> V_220 , F_130 ) ;
F_219 ( & V_8 -> V_229 , F_188 ) ;
F_131 ( & V_8 -> V_229 ,
F_151 ( 5 * ( V_12 -> V_400 & 0x07 ) ) ) ;
return 0 ;
V_388:
F_220 ( V_29 ) ;
V_385:
F_221 ( V_12 ) ;
V_383:
V_381:
F_201 ( V_12 ) ;
return V_92 ;
}
static int F_222 ( struct V_334 * V_12 , T_13 V_98 )
{
struct V_28 * V_29 = F_197 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
int V_404 = 0 ;
F_198 ( V_29 ) ;
if ( F_153 ( V_29 ) ) {
F_126 () ;
F_89 ( V_8 ) ;
F_127 () ;
}
F_51 ( V_8 ) ;
F_123 ( V_8 ) ;
V_404 = F_200 ( V_12 ) ;
if ( V_404 )
return V_404 ;
F_201 ( V_12 ) ;
return 0 ;
}
static int F_223 ( struct V_334 * V_12 )
{
struct V_7 * V_8 = F_197 ( V_12 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
T_3 V_92 ;
F_224 ( V_12 , V_405 ) ;
F_225 ( V_12 ) ;
F_200 ( V_12 ) ;
V_92 = F_226 ( V_12 ) ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_53 ) ;
return V_92 ;
}
F_163 ( V_12 ) ;
F_126 () ;
V_92 = F_98 ( V_8 ) ;
if ( V_92 ) {
F_127 () ;
F_49 ( & V_12 -> V_13 , L_54 ) ;
return V_92 ;
}
V_92 = F_47 ( V_8 ) ;
F_127 () ;
if ( V_92 ) {
F_49 ( & V_12 -> V_13 , L_55 ) ;
return V_92 ;
}
F_13 ( & V_8 -> V_27 ) ;
F_227 ( V_29 ) ;
return V_92 ;
}
static void F_228 ( struct V_334 * V_12 )
{
struct V_28 * V_29 = F_197 ( V_12 ) ;
struct V_7 * V_8 = F_15 ( V_29 ) ;
struct V_133 * V_119 , * V_147 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
F_229 ( & V_8 -> V_229 ) ;
F_230 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_373 ) {
F_231 ( V_29 ) ;
V_8 -> V_373 = false ;
}
V_8 -> V_98 = V_240 ;
V_8 -> V_95 = 0 ;
F_161 ( V_8 ) ;
F_162 ( 50 ) ;
if ( ! F_132 ( V_2 ) ) {
F_161 ( V_8 ) ;
F_162 ( 50 ) ;
}
F_16 ( V_8 ) ;
F_51 ( V_8 ) ;
F_123 ( V_8 ) ;
F_121 ( V_8 ) ;
if ( V_8 -> V_167 . V_366 )
F_232 ( & V_8 -> V_167 ) ;
F_233 () ;
F_128 ( V_8 ) ;
if ( V_2 -> V_200 . V_270 . V_68 )
F_158 ( V_2 ) ;
F_234 ( & V_2 -> V_200 . V_403 ) ;
F_234 ( & V_2 -> V_200 . V_402 ) ;
F_235 ( V_2 -> V_114 ) ;
F_221 ( V_12 ) ;
F_155 ( V_8 ) ;
F_156 ( V_8 ) ;
F_95 ( V_8 ) ;
F_9 ( V_8 -> V_191 ) ;
F_78 (f, ftmp, &adapter->mac_filter_list, list) {
F_157 ( & V_119 -> V_124 ) ;
F_9 ( V_119 ) ;
}
F_78 (f, ftmp, &adapter->vlan_filter_list, list) {
F_157 ( & V_119 -> V_124 ) ;
F_9 ( V_119 ) ;
}
F_220 ( V_29 ) ;
F_236 ( V_12 ) ;
F_201 ( V_12 ) ;
}
static int T_14 F_237 ( void )
{
int V_197 ;
F_11 ( L_56 , V_406 ,
V_407 ) ;
F_11 ( L_57 , V_408 ) ;
V_409 = F_238 ( L_1 , V_410 | V_411 , 1 ,
V_382 ) ;
if ( ! V_409 ) {
F_239 ( L_58 , V_382 ) ;
return - V_132 ;
}
V_197 = F_240 ( & V_412 ) ;
return V_197 ;
}
static void T_15 F_241 ( void )
{
F_242 ( & V_412 ) ;
F_243 ( V_409 ) ;
}
