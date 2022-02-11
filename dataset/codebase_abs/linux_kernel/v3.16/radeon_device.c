bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & V_7 )
return true ;
return false ;
}
void F_2 ( struct V_3 * V_4 ,
const T_1 * V_8 ,
const T_1 V_9 )
{
T_1 V_10 , V_11 , V_12 , V_13 ;
int V_14 ;
if ( V_9 % 3 )
return;
for ( V_14 = 0 ; V_14 < V_9 ; V_14 += 3 ) {
V_11 = V_8 [ V_14 + 0 ] ;
V_12 = V_8 [ V_14 + 1 ] ;
V_13 = V_8 [ V_14 + 2 ] ;
if ( V_12 == 0xffffffff ) {
V_10 = V_13 ;
} else {
V_10 = F_3 ( V_11 ) ;
V_10 &= ~ V_12 ;
V_10 |= V_13 ;
}
F_4 ( V_11 , V_10 ) ;
}
}
void F_5 ( struct V_3 * V_4 )
{
F_6 ( V_4 -> V_15 , 0x7c , V_16 ) ;
}
void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_17 < V_18 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
if ( V_4 -> V_20 [ V_14 ] . V_21 )
F_8 ( V_4 -> V_20 [ V_14 ] . V_21 ) ;
else
F_9 ( V_4 , V_14 ) ;
}
F_4 ( V_22 , 0 ) ;
}
}
void F_10 ( struct V_3 * V_4 )
{
int V_14 ;
if ( V_4 -> V_17 < V_23 ) {
V_4 -> V_24 . V_25 = 5 ;
} else {
V_4 -> V_24 . V_25 = 7 ;
}
V_4 -> V_24 . V_26 = V_27 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_24 . V_25 ; V_14 ++ ) {
V_4 -> V_24 . free [ V_14 ] = true ;
V_4 -> V_24 . V_11 [ V_14 ] = V_4 -> V_24 . V_26 + ( V_14 * 4 ) ;
}
}
int F_11 ( struct V_3 * V_4 , T_2 * V_11 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_24 . V_25 ; V_14 ++ ) {
if ( V_4 -> V_24 . free [ V_14 ] ) {
V_4 -> V_24 . free [ V_14 ] = false ;
* V_11 = V_4 -> V_24 . V_11 [ V_14 ] ;
return 0 ;
}
}
return - V_28 ;
}
void F_12 ( struct V_3 * V_4 , T_2 V_11 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_24 . V_25 ; V_14 ++ ) {
if ( V_4 -> V_24 . V_11 [ V_14 ] == V_11 ) {
V_4 -> V_24 . free [ V_14 ] = true ;
return;
}
}
}
static int F_13 ( struct V_3 * V_4 )
{
V_4 -> V_29 . V_30 = F_14 ( V_4 -> V_15 , 2 ) ;
V_4 -> V_29 . V_31 = F_15 ( V_4 -> V_15 , 2 ) ;
V_4 -> V_29 . V_32 = F_16 ( T_1 , V_4 -> V_29 . V_31 / sizeof( T_1 ) , V_33 ) ;
if ( V_4 -> V_29 . V_32 == 0 )
return - V_28 ;
V_4 -> V_29 . V_34 = F_17 ( V_4 -> V_29 . V_30 , V_4 -> V_29 . V_32 * sizeof( T_1 ) ) ;
if ( V_4 -> V_29 . V_34 == NULL ) {
return - V_35 ;
}
F_18 ( L_1 , ( T_2 ) V_4 -> V_29 . V_30 ) ;
F_18 ( L_2 , ( unsigned ) V_4 -> V_29 . V_31 ) ;
memset ( & V_4 -> V_29 . V_36 , 0 , sizeof( V_4 -> V_29 . V_36 ) ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
F_20 ( V_4 -> V_29 . V_34 ) ;
V_4 -> V_29 . V_34 = NULL ;
}
int F_21 ( struct V_3 * V_4 , T_1 * V_29 )
{
unsigned long V_37 = F_22 ( V_4 -> V_29 . V_36 , V_4 -> V_29 . V_32 ) ;
if ( V_37 < V_4 -> V_29 . V_32 ) {
F_23 ( V_37 , V_4 -> V_29 . V_36 ) ;
* V_29 = V_37 ;
return 0 ;
} else {
return - V_28 ;
}
}
void F_24 ( struct V_3 * V_4 , T_1 V_29 )
{
if ( V_29 < V_4 -> V_29 . V_32 )
F_25 ( V_29 , V_4 -> V_29 . V_36 ) ;
}
void F_26 ( struct V_3 * V_4 )
{
V_4 -> V_38 . V_39 = false ;
}
void F_27 ( struct V_3 * V_4 )
{
F_26 ( V_4 ) ;
if ( V_4 -> V_38 . V_40 ) {
if ( ! F_28 ( V_4 -> V_38 . V_40 , false ) ) {
F_29 ( V_4 -> V_38 . V_40 ) ;
F_30 ( V_4 -> V_38 . V_40 ) ;
F_31 ( V_4 -> V_38 . V_40 ) ;
}
F_32 ( & V_4 -> V_38 . V_40 ) ;
V_4 -> V_38 . V_38 = NULL ;
V_4 -> V_38 . V_40 = NULL ;
}
}
int F_33 ( struct V_3 * V_4 )
{
int V_41 ;
if ( V_4 -> V_38 . V_40 == NULL ) {
V_41 = F_34 ( V_4 , V_42 , V_43 , true ,
V_44 , NULL , & V_4 -> V_38 . V_40 ) ;
if ( V_41 ) {
F_35 ( V_4 -> V_2 , L_3 , V_41 ) ;
return V_41 ;
}
V_41 = F_28 ( V_4 -> V_38 . V_40 , false ) ;
if ( F_36 ( V_41 != 0 ) ) {
F_27 ( V_4 ) ;
return V_41 ;
}
V_41 = F_37 ( V_4 -> V_38 . V_40 , V_44 ,
& V_4 -> V_38 . V_45 ) ;
if ( V_41 ) {
F_31 ( V_4 -> V_38 . V_40 ) ;
F_35 ( V_4 -> V_2 , L_4 , V_41 ) ;
F_27 ( V_4 ) ;
return V_41 ;
}
V_41 = F_38 ( V_4 -> V_38 . V_40 , ( void * * ) & V_4 -> V_38 . V_38 ) ;
F_31 ( V_4 -> V_38 . V_40 ) ;
if ( V_41 ) {
F_35 ( V_4 -> V_2 , L_5 , V_41 ) ;
F_27 ( V_4 ) ;
return V_41 ;
}
}
memset ( ( char * ) V_4 -> V_38 . V_38 , 0 , V_42 ) ;
V_4 -> V_38 . V_46 = false ;
if ( V_47 == 1 ) {
V_4 -> V_38 . V_39 = false ;
} else {
if ( V_4 -> V_6 & V_48 ) {
V_4 -> V_38 . V_39 = false ;
} else if ( V_4 -> V_17 < V_23 ) {
V_4 -> V_38 . V_39 = false ;
} else {
V_4 -> V_38 . V_39 = true ;
if ( V_4 -> V_17 >= V_18 ) {
V_4 -> V_38 . V_46 = true ;
}
}
}
if ( V_4 -> V_17 >= V_49 ) {
V_4 -> V_38 . V_39 = true ;
V_4 -> V_38 . V_46 = true ;
}
F_39 ( V_4 -> V_2 , L_6 , V_4 -> V_38 . V_39 ? L_7 : L_8 ) ;
return 0 ;
}
void F_40 ( struct V_3 * V_4 , struct V_50 * V_51 , T_3 V_30 )
{
T_4 V_52 = ( T_4 ) V_53 << 20 ;
V_51 -> V_54 = V_30 ;
if ( V_51 -> V_55 > ( V_4 -> V_51 . V_56 - V_30 + 1 ) ) {
F_35 ( V_4 -> V_2 , L_9 ) ;
V_51 -> V_57 = V_51 -> V_58 ;
V_51 -> V_55 = V_51 -> V_58 ;
}
V_51 -> V_59 = V_51 -> V_54 + V_51 -> V_55 - 1 ;
if ( V_4 -> V_6 & V_48 && V_51 -> V_59 > V_51 -> V_60 && V_51 -> V_54 <= V_51 -> V_61 ) {
F_35 ( V_4 -> V_2 , L_9 ) ;
V_51 -> V_57 = V_51 -> V_58 ;
V_51 -> V_55 = V_51 -> V_58 ;
}
V_51 -> V_59 = V_51 -> V_54 + V_51 -> V_55 - 1 ;
if ( V_52 && V_52 < V_51 -> V_57 )
V_51 -> V_57 = V_52 ;
F_39 ( V_4 -> V_2 , L_10 ,
V_51 -> V_55 >> 20 , V_51 -> V_54 ,
V_51 -> V_59 , V_51 -> V_57 >> 20 ) ;
}
void F_41 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
T_3 V_62 , V_63 ;
V_62 = ( ( V_4 -> V_51 . V_56 - V_51 -> V_59 ) + V_51 -> V_64 ) & ~ V_51 -> V_64 ;
V_63 = V_51 -> V_54 & ~ V_51 -> V_64 ;
if ( V_63 > V_62 ) {
if ( V_51 -> V_65 > V_63 ) {
F_35 ( V_4 -> V_2 , L_11 ) ;
V_51 -> V_65 = V_63 ;
}
V_51 -> V_60 = ( V_51 -> V_54 & ~ V_51 -> V_64 ) - V_51 -> V_65 ;
} else {
if ( V_51 -> V_65 > V_62 ) {
F_35 ( V_4 -> V_2 , L_11 ) ;
V_51 -> V_65 = V_62 ;
}
V_51 -> V_60 = ( V_51 -> V_59 + 1 + V_51 -> V_64 ) & ~ V_51 -> V_64 ;
}
V_51 -> V_61 = V_51 -> V_60 + V_51 -> V_65 - 1 ;
F_39 ( V_4 -> V_2 , L_12 ,
V_51 -> V_65 >> 20 , V_51 -> V_60 , V_51 -> V_61 ) ;
}
bool F_42 ( struct V_3 * V_4 )
{
T_2 V_11 ;
if ( F_43 ( V_66 ) &&
( V_4 -> V_15 -> V_67 == V_68 ) &&
( V_4 -> V_17 < V_18 ) )
return false ;
if ( F_44 ( V_4 ) )
goto V_69;
if ( F_45 ( V_4 ) ) {
V_11 = F_3 ( V_70 + V_71 ) |
F_3 ( V_70 + V_72 ) ;
if ( V_4 -> V_73 >= 4 ) {
V_11 |= F_3 ( V_70 + V_74 ) |
F_3 ( V_70 + V_75 ) ;
}
if ( V_4 -> V_73 >= 6 ) {
V_11 |= F_3 ( V_70 + V_76 ) |
F_3 ( V_70 + V_77 ) ;
}
if ( V_11 & V_78 )
return true ;
} else if ( F_46 ( V_4 ) ) {
V_11 = F_3 ( V_79 ) |
F_3 ( V_80 ) ;
if ( V_11 & V_81 ) {
return true ;
}
} else {
V_11 = F_3 ( V_82 ) |
F_3 ( V_83 ) ;
if ( V_11 & V_84 ) {
return true ;
}
}
V_69:
if ( V_4 -> V_17 >= V_18 )
V_11 = F_3 ( V_85 ) ;
else
V_11 = F_3 ( V_86 ) ;
if ( V_11 )
return true ;
return false ;
}
void F_47 ( struct V_3 * V_4 )
{
T_5 V_87 ;
T_1 V_88 = V_4 -> V_89 . V_90 ;
T_1 V_91 = V_4 -> V_89 . V_92 ;
V_87 . V_93 = F_48 ( 100 ) ;
V_4 -> V_89 . V_88 . V_93 = F_48 ( V_88 ) ;
V_4 -> V_89 . V_88 . V_93 = F_49 ( V_4 -> V_89 . V_88 , V_87 ) ;
V_4 -> V_89 . V_91 . V_93 = F_48 ( V_91 ) ;
V_4 -> V_89 . V_91 . V_93 = F_49 ( V_4 -> V_89 . V_91 , V_87 ) ;
if ( V_4 -> V_6 & V_94 ) {
V_87 . V_93 = F_48 ( 16 ) ;
V_4 -> V_89 . V_95 . V_93 = F_49 ( V_4 -> V_89 . V_88 , V_87 ) ;
}
}
bool F_50 ( struct V_3 * V_4 )
{
if ( F_42 ( V_4 ) )
return true ;
if ( V_4 -> V_96 ) {
F_18 ( L_13 ) ;
if ( V_4 -> V_97 )
F_51 ( V_4 -> V_98 . V_99 ) ;
else
F_52 ( V_4 -> V_100 ) ;
return true ;
} else {
F_53 ( V_4 -> V_2 , L_14 ) ;
return false ;
}
}
int F_54 ( struct V_3 * V_4 )
{
if ( V_4 -> V_101 . V_102 )
return 0 ;
V_4 -> V_101 . V_102 = F_55 ( V_103 | V_104 | V_105 ) ;
if ( V_4 -> V_101 . V_102 == NULL )
return - V_35 ;
V_4 -> V_101 . V_106 = F_56 ( V_4 -> V_15 , V_4 -> V_101 . V_102 ,
0 , V_43 , V_107 ) ;
if ( F_57 ( V_4 -> V_15 , V_4 -> V_101 . V_106 ) ) {
F_53 ( & V_4 -> V_15 -> V_2 , L_15 ) ;
F_58 ( V_4 -> V_101 . V_102 ) ;
V_4 -> V_101 . V_102 = NULL ;
return - V_35 ;
}
return 0 ;
}
void F_59 ( struct V_3 * V_4 )
{
if ( V_4 -> V_101 . V_102 == NULL )
return;
F_60 ( V_4 -> V_15 , V_4 -> V_101 . V_106 ,
V_43 , V_107 ) ;
F_58 ( V_4 -> V_101 . V_102 ) ;
V_4 -> V_101 . V_102 = NULL ;
}
static T_2 F_61 ( struct V_108 * V_109 , T_2 V_11 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
T_2 V_41 ;
V_41 = V_4 -> V_110 ( V_4 , V_11 ) ;
return V_41 ;
}
static void F_62 ( struct V_108 * V_109 , T_2 V_11 , T_2 V_111 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
V_4 -> V_112 ( V_4 , V_11 , V_111 ) ;
}
static T_2 F_63 ( struct V_108 * V_109 , T_2 V_11 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
T_2 V_41 ;
V_41 = V_4 -> V_113 ( V_4 , V_11 ) ;
return V_41 ;
}
static void F_64 ( struct V_108 * V_109 , T_2 V_11 , T_2 V_111 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
V_4 -> V_114 ( V_4 , V_11 , V_111 ) ;
}
static void F_65 ( struct V_108 * V_109 , T_2 V_11 , T_2 V_111 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
F_4 ( V_11 * 4 , V_111 ) ;
}
static T_2 F_66 ( struct V_108 * V_109 , T_2 V_11 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
T_2 V_41 ;
V_41 = F_3 ( V_11 * 4 ) ;
return V_41 ;
}
static void F_67 ( struct V_108 * V_109 , T_2 V_11 , T_2 V_111 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
F_68 ( V_11 * 4 , V_111 ) ;
}
static T_2 F_69 ( struct V_108 * V_109 , T_2 V_11 )
{
struct V_3 * V_4 = V_109 -> V_2 -> V_5 ;
T_2 V_41 ;
V_41 = F_70 ( V_11 * 4 ) ;
return V_41 ;
}
int F_71 ( struct V_3 * V_4 )
{
struct V_108 * V_115 =
F_72 ( sizeof( struct V_108 ) , V_104 ) ;
if ( ! V_115 )
return - V_35 ;
V_4 -> V_98 . V_115 = V_115 ;
V_115 -> V_2 = V_4 -> V_100 ;
V_115 -> V_116 = F_66 ;
V_115 -> V_117 = F_65 ;
if ( V_4 -> V_118 ) {
V_115 -> V_119 = F_69 ;
V_115 -> V_120 = F_67 ;
} else {
F_73 ( L_16 ) ;
V_115 -> V_119 = F_66 ;
V_115 -> V_120 = F_65 ;
}
V_115 -> V_121 = F_63 ;
V_115 -> V_122 = F_64 ;
V_115 -> V_123 = F_61 ;
V_115 -> V_124 = F_62 ;
V_4 -> V_98 . V_99 = F_74 ( V_115 , V_4 -> V_96 ) ;
if ( ! V_4 -> V_98 . V_99 ) {
F_75 ( V_4 ) ;
return - V_35 ;
}
F_76 ( & V_4 -> V_98 . V_99 -> V_125 ) ;
F_77 ( V_4 -> V_100 ) ;
F_78 ( V_4 -> V_98 . V_99 ) ;
return 0 ;
}
void F_75 ( struct V_3 * V_4 )
{
if ( V_4 -> V_98 . V_99 ) {
F_79 ( V_4 -> V_98 . V_99 -> V_24 ) ;
}
F_79 ( V_4 -> V_98 . V_99 ) ;
V_4 -> V_98 . V_99 = NULL ;
F_79 ( V_4 -> V_98 . V_115 ) ;
V_4 -> V_98 . V_115 = NULL ;
}
int F_80 ( struct V_3 * V_4 )
{
F_81 ( V_4 -> V_100 ) ;
return 0 ;
}
void F_82 ( struct V_3 * V_4 )
{
}
static unsigned int F_83 ( void * V_126 , bool V_127 )
{
struct V_3 * V_4 = V_126 ;
F_84 ( V_4 , V_127 ) ;
if ( V_127 )
return V_128 | V_129 |
V_130 | V_131 ;
else
return V_130 | V_131 ;
}
static bool F_85 ( int V_132 )
{
return ( V_132 & ( V_132 - 1 ) ) == 0 ;
}
static void F_86 ( struct V_3 * V_4 )
{
if ( ! F_85 ( V_53 ) ) {
F_35 ( V_4 -> V_2 , L_17 ,
V_53 ) ;
V_53 = 0 ;
}
if ( V_133 == - 1 ) {
if ( V_4 -> V_17 >= V_134 )
V_133 = 1024 ;
else
V_133 = 512 ;
}
if ( V_133 < 32 ) {
F_35 ( V_4 -> V_2 , L_18 ,
V_133 ) ;
if ( V_4 -> V_17 >= V_134 )
V_133 = 1024 ;
else
V_133 = 512 ;
} else if ( ! F_85 ( V_133 ) ) {
F_35 ( V_4 -> V_2 , L_19 ,
V_133 ) ;
if ( V_4 -> V_17 >= V_134 )
V_133 = 1024 ;
else
V_133 = 512 ;
}
V_4 -> V_51 . V_65 = ( T_4 ) V_133 << 20 ;
switch ( V_135 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_35 ( V_4 -> V_2 , L_20
L_21 , V_135 ) ;
V_135 = 0 ;
break;
}
if ( ! F_85 ( V_136 ) ) {
F_35 ( V_4 -> V_2 , L_22 ,
V_136 ) ;
V_136 = 4 ;
}
if ( V_136 < 1 ) {
F_35 ( V_4 -> V_2 , L_23 ,
V_136 ) ;
V_136 = 4 ;
}
if ( V_136 > 1024 ) {
F_35 ( V_4 -> V_2 , L_24 ,
V_136 ) ;
V_136 = 4 ;
}
if ( V_137 < 9 ) {
F_35 ( V_4 -> V_2 , L_25 ,
V_137 ) ;
V_137 = 9 ;
}
if ( V_137 > 24 ||
( V_136 * 1024 ) < ( 1ull << V_137 ) ) {
F_35 ( V_4 -> V_2 , L_26 ,
V_137 ) ;
V_137 = 9 ;
}
}
static bool F_87 ( struct V_138 * V_15 )
{
if ( V_15 -> V_67 == V_68 &&
V_15 -> V_139 == 0x00e2 ) {
F_88 ( V_140 L_27 ) ;
return true ;
}
return false ;
}
static void F_89 ( struct V_138 * V_15 , enum V_141 V_127 )
{
struct V_1 * V_2 = F_90 ( V_15 ) ;
if ( F_1 ( V_2 ) && V_127 == V_142 )
return;
if ( V_127 == V_143 ) {
unsigned V_144 = V_2 -> V_15 -> V_144 ;
F_88 ( V_140 L_28 ) ;
V_2 -> V_145 = V_146 ;
if ( V_144 < 20 && F_87 ( V_15 ) )
V_2 -> V_15 -> V_144 = 20 ;
F_91 ( V_2 , true , true ) ;
V_2 -> V_15 -> V_144 = V_144 ;
V_2 -> V_145 = V_147 ;
F_92 ( V_2 ) ;
} else {
F_88 ( V_140 L_29 ) ;
F_93 ( V_2 ) ;
V_2 -> V_145 = V_146 ;
F_94 ( V_2 , true , true ) ;
V_2 -> V_145 = V_148 ;
}
}
static bool F_95 ( struct V_138 * V_15 )
{
struct V_1 * V_2 = F_90 ( V_15 ) ;
return V_2 -> V_149 == 0 ;
}
int F_96 ( struct V_3 * V_4 ,
struct V_1 * V_100 ,
struct V_138 * V_15 ,
T_2 V_6 )
{
int V_41 , V_14 ;
int V_150 ;
bool V_151 = false ;
V_4 -> V_152 = false ;
V_4 -> V_2 = & V_15 -> V_2 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_17 = V_6 & V_153 ;
V_4 -> V_97 = false ;
V_4 -> V_154 = V_155 ;
V_4 -> V_51 . V_65 = 512 * 1024 * 1024 ;
V_4 -> V_156 = false ;
for ( V_14 = 0 ; V_14 < V_157 ; V_14 ++ ) {
V_4 -> V_158 [ V_14 ] . V_159 = V_14 ;
}
F_18 ( L_30 ,
V_160 [ V_4 -> V_17 ] , V_15 -> V_161 , V_15 -> V_162 ,
V_15 -> V_67 , V_15 -> V_139 ) ;
F_76 ( & V_4 -> V_163 ) ;
F_76 ( & V_4 -> V_164 ) ;
F_97 ( & V_4 -> V_165 . V_166 , 0 ) ;
F_76 ( & V_4 -> V_167 . V_125 ) ;
F_76 ( & V_4 -> V_89 . V_125 ) ;
F_76 ( & V_4 -> V_168 ) ;
F_76 ( & V_4 -> V_169 ) ;
F_98 ( & V_4 -> V_89 . V_170 ) ;
F_98 ( & V_4 -> V_171 ) ;
F_99 ( & V_4 -> V_172 . V_173 ) ;
V_41 = F_100 ( V_4 ) ;
if ( V_41 )
return V_41 ;
F_86 ( V_4 ) ;
V_4 -> V_174 . V_175 = V_136 << 18 ;
V_41 = F_101 ( V_4 ) ;
if ( V_41 )
return V_41 ;
if ( ( V_4 -> V_17 >= V_176 ) &&
( V_4 -> V_6 & V_94 ) ) {
V_4 -> V_6 &= ~ V_48 ;
}
if ( V_4 -> V_6 & V_48 && V_135 == - 1 ) {
F_102 ( V_4 ) ;
}
if ( V_4 -> V_17 >= V_177 )
V_4 -> V_51 . V_56 = 0xffffffffffULL ;
else if ( V_4 -> V_17 >= V_178 )
V_4 -> V_51 . V_56 = 0xfffffffffULL ;
else
V_4 -> V_51 . V_56 = 0xffffffffULL ;
V_4 -> V_179 = false ;
if ( V_4 -> V_6 & V_48 )
V_4 -> V_179 = true ;
if ( ( V_4 -> V_6 & V_180 ) &&
( V_4 -> V_17 <= V_181 ) )
V_4 -> V_179 = true ;
V_150 = V_4 -> V_179 ? 32 : 40 ;
V_41 = F_103 ( V_4 -> V_15 , F_104 ( V_150 ) ) ;
if ( V_41 ) {
V_4 -> V_179 = true ;
V_150 = 32 ;
F_88 ( V_182 L_31 ) ;
}
V_41 = F_105 ( V_4 -> V_15 , F_104 ( V_150 ) ) ;
if ( V_41 ) {
F_105 ( V_4 -> V_15 , F_104 ( 32 ) ) ;
F_88 ( V_182 L_32 ) ;
}
F_106 ( & V_4 -> V_183 ) ;
F_106 ( & V_4 -> V_184 ) ;
F_106 ( & V_4 -> V_185 ) ;
F_106 ( & V_4 -> V_186 ) ;
F_106 ( & V_4 -> V_187 ) ;
F_106 ( & V_4 -> V_188 ) ;
F_106 ( & V_4 -> V_189 ) ;
F_106 ( & V_4 -> V_190 ) ;
F_106 ( & V_4 -> V_191 ) ;
F_106 ( & V_4 -> V_192 ) ;
F_106 ( & V_4 -> V_193 ) ;
F_106 ( & V_4 -> V_194 ) ;
if ( V_4 -> V_17 >= V_195 ) {
V_4 -> V_196 = F_14 ( V_4 -> V_15 , 5 ) ;
V_4 -> V_197 = F_15 ( V_4 -> V_15 , 5 ) ;
} else {
V_4 -> V_196 = F_14 ( V_4 -> V_15 , 2 ) ;
V_4 -> V_197 = F_15 ( V_4 -> V_15 , 2 ) ;
}
V_4 -> V_198 = F_17 ( V_4 -> V_196 , V_4 -> V_197 ) ;
if ( V_4 -> V_198 == NULL ) {
return - V_35 ;
}
F_18 ( L_33 , ( T_2 ) V_4 -> V_196 ) ;
F_18 ( L_34 , ( unsigned ) V_4 -> V_197 ) ;
if ( V_4 -> V_17 >= V_195 )
F_13 ( V_4 ) ;
for ( V_14 = 0 ; V_14 < V_199 ; V_14 ++ ) {
if ( F_107 ( V_4 -> V_15 , V_14 ) & V_200 ) {
V_4 -> V_201 = F_15 ( V_4 -> V_15 , V_14 ) ;
V_4 -> V_118 = F_108 ( V_4 -> V_15 , V_14 , V_4 -> V_201 ) ;
break;
}
}
if ( V_4 -> V_118 == NULL )
F_73 ( L_35 ) ;
F_109 ( V_4 -> V_15 , V_4 , NULL , F_83 ) ;
if ( V_4 -> V_6 & V_7 )
V_151 = true ;
F_110 ( V_4 -> V_15 , & V_202 , V_151 ) ;
if ( V_151 )
F_111 ( V_4 -> V_2 , & V_4 -> V_203 ) ;
V_41 = F_112 ( V_4 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_113 ( V_4 ) ;
if ( V_41 )
F_73 ( L_36 , V_41 ) ;
V_41 = F_114 ( V_4 ) ;
if ( V_41 ) {
F_73 ( L_37 , V_41 ) ;
}
if ( V_4 -> V_6 & V_48 && ! V_4 -> V_156 ) {
F_115 ( V_4 ) ;
F_116 ( V_4 ) ;
F_102 ( V_4 ) ;
V_41 = F_112 ( V_4 ) ;
if ( V_41 )
return V_41 ;
}
if ( ( V_204 & 1 ) ) {
if ( V_4 -> V_156 )
F_117 ( V_4 ) ;
else
F_18 ( L_38 ) ;
}
if ( ( V_204 & 2 ) ) {
if ( V_4 -> V_156 )
F_118 ( V_4 ) ;
else
F_18 ( L_39 ) ;
}
if ( V_205 ) {
if ( V_4 -> V_156 )
F_119 ( V_4 , V_205 ) ;
else
F_18 ( L_40 ) ;
}
return 0 ;
}
void F_120 ( struct V_3 * V_4 )
{
F_18 ( L_41 ) ;
V_4 -> V_152 = true ;
F_121 ( V_4 ) ;
F_116 ( V_4 ) ;
F_122 ( V_4 -> V_15 ) ;
F_109 ( V_4 -> V_15 , NULL , NULL , NULL ) ;
if ( V_4 -> V_118 )
F_123 ( V_4 -> V_15 , V_4 -> V_118 ) ;
V_4 -> V_118 = NULL ;
F_20 ( V_4 -> V_198 ) ;
V_4 -> V_198 = NULL ;
if ( V_4 -> V_17 >= V_195 )
F_19 ( V_4 ) ;
F_124 ( V_4 ) ;
}
int F_94 ( struct V_1 * V_2 , bool V_206 , bool V_207 )
{
struct V_3 * V_4 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
int V_14 , V_41 ;
bool V_212 = false ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_213 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_145 == V_148 )
return 0 ;
F_93 ( V_2 ) ;
F_125 (connector, &dev->mode_config.connector_list, head) {
F_126 ( V_211 , V_214 ) ;
}
F_125 (crtc, &dev->mode_config.crtc_list, head) {
struct V_215 * V_216 = F_127 ( V_209 -> V_217 -> V_218 ) ;
struct V_219 * V_220 ;
if ( V_216 == NULL || V_216 -> V_221 == NULL ) {
continue;
}
V_220 = F_128 ( V_216 -> V_221 ) ;
if ( ! F_129 ( V_4 , V_220 ) ) {
V_41 = F_28 ( V_220 , false ) ;
if ( V_41 == 0 ) {
F_30 ( V_220 ) ;
F_31 ( V_220 ) ;
}
}
}
F_121 ( V_4 ) ;
for ( V_14 = 0 ; V_14 < V_157 ; V_14 ++ ) {
V_41 = F_130 ( V_4 , V_14 ) ;
if ( V_41 ) {
V_212 = true ;
}
}
if ( V_212 ) {
F_131 ( V_4 ) ;
}
F_132 ( V_4 ) ;
F_133 ( V_4 ) ;
F_134 ( V_4 ) ;
F_121 ( V_4 ) ;
F_135 ( V_4 ) ;
F_136 ( V_2 -> V_15 ) ;
if ( V_206 ) {
F_137 ( V_2 -> V_15 ) ;
F_138 ( V_2 -> V_15 , V_222 ) ;
}
if ( V_207 ) {
F_139 () ;
F_140 ( V_4 , 1 ) ;
F_141 () ;
}
return 0 ;
}
int F_91 ( struct V_1 * V_2 , bool V_223 , bool V_207 )
{
struct V_210 * V_211 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_41 ;
if ( V_2 -> V_145 == V_148 )
return 0 ;
if ( V_207 ) {
F_139 () ;
}
if ( V_223 ) {
F_138 ( V_2 -> V_15 , V_224 ) ;
F_142 ( V_2 -> V_15 ) ;
if ( F_143 ( V_2 -> V_15 ) ) {
if ( V_207 )
F_141 () ;
return - 1 ;
}
}
F_144 ( V_4 ) ;
F_145 ( V_4 ) ;
V_41 = F_113 ( V_4 ) ;
if ( V_41 )
F_73 ( L_36 , V_41 ) ;
if ( ( V_4 -> V_89 . V_225 == V_226 ) && V_4 -> V_89 . V_227 ) {
V_41 = F_146 ( V_4 ) ;
if ( V_41 ) {
V_4 -> V_89 . V_227 = false ;
F_73 ( L_42 ) ;
}
} else {
F_147 ( V_4 ) ;
}
F_148 ( V_4 ) ;
if ( V_4 -> V_97 ) {
F_149 ( V_4 ) ;
F_150 ( V_4 ) ;
if ( V_4 -> V_98 . V_228 ) {
T_6 V_229 = F_151 ( V_4 ,
V_4 -> V_98 . V_228 ) ;
F_152 ( V_4 , V_4 -> V_98 . V_228 ,
V_229 ) ;
}
}
F_153 ( V_4 ) ;
if ( V_207 ) {
F_154 ( V_2 ) ;
F_125 (connector, &dev->mode_config.connector_list, head) {
F_126 ( V_211 , V_230 ) ;
}
}
F_92 ( V_2 ) ;
if ( ( V_4 -> V_89 . V_225 == V_226 ) && V_4 -> V_89 . V_227 )
F_155 ( V_4 ) ;
if ( V_207 ) {
F_140 ( V_4 , 0 ) ;
F_141 () ;
}
return 0 ;
}
int F_156 ( struct V_3 * V_4 )
{
unsigned V_231 [ V_157 ] ;
T_2 * V_232 [ V_157 ] ;
bool V_233 = false ;
int V_14 , V_41 ;
int V_234 ;
F_157 ( & V_4 -> V_171 ) ;
if ( ! V_4 -> V_235 ) {
F_158 ( & V_4 -> V_171 ) ;
return 0 ;
}
V_4 -> V_235 = false ;
F_132 ( V_4 ) ;
V_234 = F_159 ( & V_4 -> V_236 . V_237 ) ;
F_160 ( V_4 ) ;
F_133 ( V_4 ) ;
for ( V_14 = 0 ; V_14 < V_157 ; ++ V_14 ) {
V_231 [ V_14 ] = F_161 ( V_4 , & V_4 -> V_158 [ V_14 ] ,
& V_232 [ V_14 ] ) ;
if ( V_231 [ V_14 ] ) {
V_233 = true ;
F_39 ( V_4 -> V_2 , L_43
L_44 , V_231 [ V_14 ] , V_14 ) ;
}
}
V_238:
V_41 = F_115 ( V_4 ) ;
if ( ! V_41 ) {
F_39 ( V_4 -> V_2 , L_45 ) ;
F_145 ( V_4 ) ;
}
F_148 ( V_4 ) ;
if ( ! V_41 ) {
for ( V_14 = 0 ; V_14 < V_157 ; ++ V_14 ) {
F_162 ( V_4 , & V_4 -> V_158 [ V_14 ] ,
V_231 [ V_14 ] , V_232 [ V_14 ] ) ;
V_231 [ V_14 ] = 0 ;
V_232 [ V_14 ] = NULL ;
}
V_41 = F_113 ( V_4 ) ;
if ( V_41 ) {
F_53 ( V_4 -> V_2 , L_36 , V_41 ) ;
if ( V_233 ) {
V_233 = false ;
F_133 ( V_4 ) ;
goto V_238;
}
}
} else {
F_131 ( V_4 ) ;
for ( V_14 = 0 ; V_14 < V_157 ; ++ V_14 ) {
F_79 ( V_232 [ V_14 ] ) ;
}
}
F_147 ( V_4 ) ;
F_154 ( V_4 -> V_100 ) ;
F_163 ( & V_4 -> V_236 . V_237 , V_234 ) ;
if ( V_41 ) {
F_39 ( V_4 -> V_2 , L_46 ) ;
}
F_158 ( & V_4 -> V_171 ) ;
return V_41 ;
}
int F_164 ( struct V_3 * V_4 ,
struct V_239 * V_240 ,
unsigned V_241 )
{
unsigned V_14 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_242 ; V_14 ++ ) {
if ( V_4 -> V_243 [ V_14 ] . V_240 == V_240 ) {
return 0 ;
}
}
V_14 = V_4 -> V_242 + 1 ;
if ( V_14 > V_244 ) {
F_73 ( L_47 ) ;
F_73 ( L_48
L_49 ) ;
return - V_28 ;
}
V_4 -> V_243 [ V_4 -> V_242 ] . V_240 = V_240 ;
V_4 -> V_243 [ V_4 -> V_242 ] . V_245 = V_241 ;
V_4 -> V_242 = V_14 ;
#if F_165 ( V_246 )
F_166 ( V_240 , V_241 ,
V_4 -> V_100 -> V_247 -> V_248 ,
V_4 -> V_100 -> V_247 ) ;
F_166 ( V_240 , V_241 ,
V_4 -> V_100 -> V_217 -> V_248 ,
V_4 -> V_100 -> V_217 ) ;
#endif
return 0 ;
}
static void F_124 ( struct V_3 * V_4 )
{
#if F_165 ( V_246 )
unsigned V_14 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_242 ; V_14 ++ ) {
F_167 ( V_4 -> V_243 [ V_14 ] . V_240 ,
V_4 -> V_243 [ V_14 ] . V_245 ,
V_4 -> V_100 -> V_247 ) ;
F_167 ( V_4 -> V_243 [ V_14 ] . V_240 ,
V_4 -> V_243 [ V_14 ] . V_245 ,
V_4 -> V_100 -> V_217 ) ;
}
#endif
}
int F_168 ( struct V_249 * V_250 )
{
return 0 ;
}
void F_169 ( struct V_249 * V_250 )
{
}
