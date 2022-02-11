bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & V_7 )
return true ;
return false ;
}
T_1 F_2 ( struct V_3 * V_4 , T_1 V_8 ,
bool V_9 )
{
T_1 V_10 ;
if ( ( V_8 * 4 ) < V_4 -> V_11 && ! V_9 )
V_10 = F_3 ( ( ( void V_12 * ) V_4 -> V_13 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_4 ( & V_4 -> V_14 , V_6 ) ;
F_5 ( ( V_8 * 4 ) , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_15 * 4 ) ) ;
V_10 = F_3 ( ( ( void V_12 * ) V_4 -> V_13 ) + ( V_16 * 4 ) ) ;
F_6 ( & V_4 -> V_14 , V_6 ) ;
}
F_7 ( V_4 -> V_17 -> V_18 , V_8 , V_10 ) ;
return V_10 ;
}
void F_8 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_19 ,
bool V_9 )
{
F_9 ( V_4 -> V_17 -> V_18 , V_8 , V_19 ) ;
if ( ( V_8 * 4 ) < V_4 -> V_11 && ! V_9 )
F_5 ( V_19 , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_4 ( & V_4 -> V_14 , V_6 ) ;
F_5 ( ( V_8 * 4 ) , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_15 * 4 ) ) ;
F_5 ( V_19 , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_16 * 4 ) ) ;
F_6 ( & V_4 -> V_14 , V_6 ) ;
}
}
T_2 F_10 ( struct V_3 * V_4 , T_2 V_8 )
{
if ( ( V_8 * 4 ) < V_4 -> V_20 )
return F_11 ( V_4 -> V_21 + ( V_8 * 4 ) ) ;
else {
F_12 ( ( V_8 * 4 ) , V_4 -> V_21 + ( V_15 * 4 ) ) ;
return F_11 ( V_4 -> V_21 + ( V_16 * 4 ) ) ;
}
}
void F_13 ( struct V_3 * V_4 , T_2 V_8 , T_2 V_19 )
{
if ( ( V_8 * 4 ) < V_4 -> V_20 )
F_12 ( V_19 , V_4 -> V_21 + ( V_8 * 4 ) ) ;
else {
F_12 ( ( V_8 * 4 ) , V_4 -> V_21 + ( V_15 * 4 ) ) ;
F_12 ( V_19 , V_4 -> V_21 + ( V_16 * 4 ) ) ;
}
}
T_2 F_14 ( struct V_3 * V_4 , T_2 V_22 )
{
if ( V_22 < V_4 -> V_23 . V_24 ) {
return F_3 ( V_4 -> V_23 . V_25 + V_22 ) ;
} else {
F_15 ( L_1 , V_22 ) ;
return 0 ;
}
}
void F_16 ( struct V_3 * V_4 , T_2 V_22 , T_2 V_19 )
{
if ( V_22 < V_4 -> V_23 . V_24 ) {
F_5 ( V_19 , V_4 -> V_23 . V_25 + V_22 ) ;
} else {
F_15 ( L_2 , V_22 ) ;
}
}
static T_1 F_17 ( struct V_3 * V_4 , T_1 V_8 )
{
F_15 ( L_3 , V_8 ) ;
F_18 () ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_19 )
{
F_15 ( L_4 ,
V_8 , V_19 ) ;
F_18 () ;
}
static T_1 F_20 ( struct V_3 * V_4 ,
T_1 V_26 , T_1 V_8 )
{
F_15 ( L_5 ,
V_8 , V_26 ) ;
F_18 () ;
return 0 ;
}
static void F_21 ( struct V_3 * V_4 ,
T_1 V_26 ,
T_1 V_8 , T_1 V_19 )
{
F_15 ( L_6 ,
V_8 , V_26 , V_19 ) ;
F_18 () ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_28 . V_29 == NULL ) {
V_27 = F_23 ( V_4 , V_30 ,
V_31 , true , V_32 ,
V_33 |
V_34 ,
NULL , NULL , & V_4 -> V_28 . V_29 ) ;
if ( V_27 ) {
return V_27 ;
}
}
V_27 = F_24 ( V_4 -> V_28 . V_29 , false ) ;
if ( F_25 ( V_27 != 0 ) )
return V_27 ;
V_27 = F_26 ( V_4 -> V_28 . V_29 ,
V_32 , & V_4 -> V_28 . V_35 ) ;
if ( V_27 ) {
F_27 ( V_4 -> V_28 . V_29 ) ;
return V_27 ;
}
V_27 = F_28 ( V_4 -> V_28 . V_29 ,
( void * * ) & V_4 -> V_28 . V_25 ) ;
if ( V_27 )
F_29 ( V_4 -> V_28 . V_29 ) ;
F_27 ( V_4 -> V_28 . V_29 ) ;
return V_27 ;
}
static void F_30 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_28 . V_29 == NULL ) {
return;
}
V_27 = F_24 ( V_4 -> V_28 . V_29 , false ) ;
if ( F_31 ( V_27 == 0 ) ) {
F_32 ( V_4 -> V_28 . V_29 ) ;
F_29 ( V_4 -> V_28 . V_29 ) ;
F_27 ( V_4 -> V_28 . V_29 ) ;
}
F_33 ( & V_4 -> V_28 . V_29 ) ;
}
void F_34 ( struct V_3 * V_4 ,
const T_2 * V_36 ,
const T_2 V_37 )
{
T_2 V_38 , V_8 , V_39 , V_40 ;
int V_41 ;
if ( V_37 % 3 )
return;
for ( V_41 = 0 ; V_41 < V_37 ; V_41 += 3 ) {
V_8 = V_36 [ V_41 + 0 ] ;
V_39 = V_36 [ V_41 + 1 ] ;
V_40 = V_36 [ V_41 + 2 ] ;
if ( V_39 == 0xffffffff ) {
V_38 = V_40 ;
} else {
V_38 = F_35 ( V_8 ) ;
V_38 &= ~ V_39 ;
V_38 |= V_40 ;
}
F_36 ( V_8 , V_38 ) ;
}
}
void F_37 ( struct V_3 * V_4 )
{
F_38 ( V_4 -> V_17 , 0x7c , V_42 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
V_4 -> V_23 . V_43 = F_40 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_23 . V_44 = F_41 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_23 . V_24 = F_42 ( T_2 , V_4 -> V_23 . V_44 / sizeof( T_2 ) ,
V_45 + 1 ) ;
if ( V_4 -> V_23 . V_24 == 0 )
return - V_46 ;
V_4 -> V_23 . V_25 = F_43 ( V_4 -> V_23 . V_43 , V_4 -> V_23 . V_24 * sizeof( T_2 ) ) ;
if ( V_4 -> V_23 . V_25 == NULL ) {
return - V_47 ;
}
F_44 ( L_7 , ( T_1 ) V_4 -> V_23 . V_43 ) ;
F_44 ( L_8 , ( unsigned ) V_4 -> V_23 . V_44 ) ;
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
F_46 ( V_4 -> V_23 . V_25 ) ;
V_4 -> V_23 . V_25 = NULL ;
}
void F_47 ( struct V_3 * V_4 ,
T_3 * V_48 ,
T_4 * V_49 ,
T_4 * V_50 )
{
if ( V_4 -> V_23 . V_44 > V_4 -> V_23 . V_24 * sizeof( T_2 ) ) {
* V_48 = V_4 -> V_23 . V_43 ;
* V_49 = V_4 -> V_23 . V_44 ;
* V_50 = V_4 -> V_23 . V_24 * sizeof( T_2 ) ;
} else {
* V_48 = 0 ;
* V_49 = 0 ;
* V_50 = 0 ;
}
}
static void F_48 ( struct V_3 * V_4 )
{
if ( V_4 -> V_51 . V_52 ) {
F_49 ( & V_4 -> V_51 . V_52 ,
& V_4 -> V_51 . V_35 ,
( void * * ) & V_4 -> V_51 . V_51 ) ;
V_4 -> V_51 . V_52 = NULL ;
}
}
static int F_50 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_51 . V_52 == NULL ) {
V_27 = F_51 ( V_4 , V_53 * 4 ,
V_31 , V_54 ,
& V_4 -> V_51 . V_52 , & V_4 -> V_51 . V_35 ,
( void * * ) & V_4 -> V_51 . V_51 ) ;
if ( V_27 ) {
F_52 ( V_4 -> V_2 , L_9 , V_27 ) ;
return V_27 ;
}
V_4 -> V_51 . V_55 = V_53 ;
memset ( & V_4 -> V_51 . V_56 , 0 , sizeof( V_4 -> V_51 . V_56 ) ) ;
memset ( ( char * ) V_4 -> V_51 . V_51 , 0 , V_30 ) ;
}
return 0 ;
}
int F_53 ( struct V_3 * V_4 , T_2 * V_51 )
{
unsigned long V_57 = F_54 ( V_4 -> V_51 . V_56 , V_4 -> V_51 . V_55 ) ;
if ( V_57 < V_4 -> V_51 . V_55 ) {
F_55 ( V_57 , V_4 -> V_51 . V_56 ) ;
* V_51 = V_57 ;
return 0 ;
} else {
return - V_46 ;
}
}
void F_56 ( struct V_3 * V_4 , T_2 V_51 )
{
if ( V_51 < V_4 -> V_51 . V_55 )
F_57 ( V_51 , V_4 -> V_51 . V_56 ) ;
}
void F_58 ( struct V_3 * V_4 , struct V_58 * V_59 , T_5 V_43 )
{
T_6 V_60 = ( T_6 ) V_61 << 20 ;
V_59 -> V_62 = V_43 ;
if ( V_59 -> V_63 > ( V_4 -> V_59 . V_64 - V_43 + 1 ) ) {
F_52 ( V_4 -> V_2 , L_10 ) ;
V_59 -> V_65 = V_59 -> V_66 ;
V_59 -> V_63 = V_59 -> V_66 ;
}
V_59 -> V_67 = V_59 -> V_62 + V_59 -> V_63 - 1 ;
if ( V_60 && V_60 < V_59 -> V_65 )
V_59 -> V_65 = V_60 ;
F_59 ( V_4 -> V_2 , L_11 ,
V_59 -> V_63 >> 20 , V_59 -> V_62 ,
V_59 -> V_67 , V_59 -> V_65 >> 20 ) ;
}
void F_60 ( struct V_3 * V_4 , struct V_58 * V_59 )
{
T_5 V_68 , V_69 ;
V_68 = ( ( V_4 -> V_59 . V_64 - V_59 -> V_67 ) + V_59 -> V_70 ) & ~ V_59 -> V_70 ;
V_69 = V_59 -> V_62 & ~ V_59 -> V_70 ;
if ( V_69 > V_68 ) {
if ( V_59 -> V_71 > V_69 ) {
F_52 ( V_4 -> V_2 , L_12 ) ;
V_59 -> V_71 = V_69 ;
}
V_59 -> V_72 = ( V_59 -> V_62 & ~ V_59 -> V_70 ) - V_59 -> V_71 ;
} else {
if ( V_59 -> V_71 > V_68 ) {
F_52 ( V_4 -> V_2 , L_12 ) ;
V_59 -> V_71 = V_68 ;
}
V_59 -> V_72 = ( V_59 -> V_67 + 1 + V_59 -> V_70 ) & ~ V_59 -> V_70 ;
}
V_59 -> V_73 = V_59 -> V_72 + V_59 -> V_71 - 1 ;
F_59 ( V_4 -> V_2 , L_13 ,
V_59 -> V_71 >> 20 , V_59 -> V_72 , V_59 -> V_73 ) ;
}
bool F_61 ( struct V_3 * V_4 )
{
T_1 V_8 ;
V_8 = F_35 ( V_74 ) ;
if ( V_8 )
return true ;
return false ;
}
static bool F_62 ( struct V_3 * V_4 )
{
if ( F_63 ( V_4 ) )
return false ;
if ( F_64 ( V_4 ) ) {
if ( V_4 -> V_75 == V_76 ) {
int V_77 ;
T_1 V_78 ;
V_77 = F_65 ( & V_4 -> V_79 . V_80 , L_14 , V_4 -> V_2 ) ;
if ( V_77 )
return true ;
V_78 = * ( ( T_1 * ) V_4 -> V_79 . V_80 -> V_81 + 69 ) ;
if ( V_78 < 0x00160e00 )
return true ;
}
}
return ! F_61 ( V_4 ) ;
}
int F_66 ( struct V_3 * V_4 )
{
if ( V_4 -> V_82 . V_83 )
return 0 ;
V_4 -> V_82 . V_83 = F_67 ( V_84 | V_85 | V_86 ) ;
if ( V_4 -> V_82 . V_83 == NULL )
return - V_47 ;
V_4 -> V_82 . V_87 = F_68 ( V_4 -> V_17 , V_4 -> V_82 . V_83 ,
0 , V_31 , V_88 ) ;
if ( F_69 ( V_4 -> V_17 , V_4 -> V_82 . V_87 ) ) {
F_70 ( & V_4 -> V_17 -> V_2 , L_15 ) ;
F_71 ( V_4 -> V_82 . V_83 ) ;
V_4 -> V_82 . V_83 = NULL ;
return - V_47 ;
}
return 0 ;
}
void F_72 ( struct V_3 * V_4 )
{
if ( V_4 -> V_82 . V_83 == NULL )
return;
F_73 ( V_4 -> V_17 , V_4 -> V_82 . V_87 ,
V_31 , V_88 ) ;
F_71 ( V_4 -> V_82 . V_83 ) ;
V_4 -> V_82 . V_83 = NULL ;
}
static T_1 F_74 ( struct V_89 * V_90 , T_1 V_8 )
{
return 0 ;
}
static void F_75 ( struct V_89 * V_90 , T_1 V_8 , T_1 V_91 )
{
}
static T_1 F_76 ( struct V_89 * V_90 , T_1 V_8 )
{
return 0 ;
}
static void F_77 ( struct V_89 * V_90 , T_1 V_8 , T_1 V_91 )
{
}
static void F_78 ( struct V_89 * V_90 , T_1 V_8 , T_1 V_91 )
{
struct V_3 * V_4 = V_90 -> V_2 -> V_5 ;
F_36 ( V_8 , V_91 ) ;
}
static T_1 F_79 ( struct V_89 * V_90 , T_1 V_8 )
{
struct V_3 * V_4 = V_90 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_35 ( V_8 ) ;
return V_27 ;
}
static void F_80 ( struct V_89 * V_90 , T_1 V_8 , T_1 V_91 )
{
struct V_3 * V_4 = V_90 -> V_2 -> V_5 ;
F_81 ( V_8 , V_91 ) ;
}
static T_1 F_82 ( struct V_89 * V_90 , T_1 V_8 )
{
struct V_3 * V_4 = V_90 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_83 ( V_8 ) ;
return V_27 ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( V_4 -> V_92 . V_93 ) {
F_85 ( V_4 -> V_92 . V_93 -> V_94 ) ;
F_85 ( V_4 -> V_92 . V_93 -> V_95 ) ;
}
F_85 ( V_4 -> V_92 . V_93 ) ;
V_4 -> V_92 . V_93 = NULL ;
F_85 ( V_4 -> V_92 . V_96 ) ;
V_4 -> V_92 . V_96 = NULL ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_89 * V_96 =
F_87 ( sizeof( struct V_89 ) , V_85 ) ;
if ( ! V_96 )
return - V_47 ;
V_4 -> V_92 . V_96 = V_96 ;
V_96 -> V_2 = V_4 -> V_97 ;
V_96 -> V_98 = F_79 ;
V_96 -> V_99 = F_78 ;
if ( V_4 -> V_21 ) {
V_96 -> V_100 = F_82 ;
V_96 -> V_101 = F_80 ;
} else {
F_15 ( L_16 ) ;
V_96 -> V_100 = F_79 ;
V_96 -> V_101 = F_78 ;
}
V_96 -> V_102 = F_76 ;
V_96 -> V_103 = F_77 ;
V_96 -> V_104 = F_74 ;
V_96 -> V_105 = F_75 ;
V_4 -> V_92 . V_93 = F_88 ( V_96 , V_4 -> V_106 ) ;
if ( ! V_4 -> V_92 . V_93 ) {
F_84 ( V_4 ) ;
return - V_47 ;
}
F_89 ( & V_4 -> V_92 . V_93 -> V_107 ) ;
F_90 ( V_4 ) ;
F_91 ( V_4 -> V_92 . V_93 ) ;
return 0 ;
}
static unsigned int F_92 ( void * V_108 , bool V_109 )
{
struct V_3 * V_4 = V_108 ;
F_93 ( V_4 , V_109 ) ;
if ( V_109 )
return V_110 | V_111 |
V_112 | V_113 ;
else
return V_112 | V_113 ;
}
static bool F_94 ( int V_114 )
{
return ( V_114 & ( V_114 - 1 ) ) == 0 ;
}
static void F_95 ( struct V_3 * V_4 )
{
if ( V_115 < 4 ) {
F_52 ( V_4 -> V_2 , L_17 ,
V_115 ) ;
V_115 = 4 ;
} else if ( ! F_94 ( V_115 ) ) {
F_52 ( V_4 -> V_2 , L_18 ,
V_115 ) ;
V_115 = F_96 ( V_115 ) ;
}
if ( V_116 != - 1 ) {
if ( V_116 < 32 ) {
F_52 ( V_4 -> V_2 , L_19 ,
V_116 ) ;
V_116 = - 1 ;
}
}
if ( ! F_94 ( V_117 ) ) {
F_52 ( V_4 -> V_2 , L_20 ,
V_117 ) ;
V_117 = 8 ;
}
if ( V_117 < 1 ) {
F_52 ( V_4 -> V_2 , L_21 ,
V_117 ) ;
V_117 = 8 ;
}
if ( V_117 > 1024 ) {
F_52 ( V_4 -> V_2 , L_22 ,
V_117 ) ;
V_117 = 8 ;
}
if ( V_118 == - 1 ) {
unsigned V_119 = F_97 ( V_117 ) + 18 ;
if ( V_117 <= 8 )
V_118 = V_119 - 9 ;
else
V_118 = ( V_119 + 3 ) / 2 ;
} else if ( V_118 < 9 ) {
F_52 ( V_4 -> V_2 , L_23 ,
V_118 ) ;
V_118 = 9 ;
}
if ( V_118 > 24 ||
( V_117 * 1024 ) < ( 1ull << V_118 ) ) {
F_52 ( V_4 -> V_2 , L_24 ,
V_118 ) ;
V_118 = 9 ;
}
if ( V_120 != - 1 && ( V_120 < 16 ||
! F_94 ( V_120 ) ) ) {
F_52 ( V_4 -> V_2 , L_25 ,
V_120 ) ;
V_120 = 1024 ;
}
}
static void F_98 ( struct V_121 * V_17 , enum V_122 V_109 )
{
struct V_1 * V_2 = F_99 ( V_17 ) ;
if ( F_1 ( V_2 ) && V_109 == V_123 )
return;
if ( V_109 == V_124 ) {
unsigned V_125 = V_2 -> V_17 -> V_125 ;
F_100 ( V_126 L_26 ) ;
V_2 -> V_127 = V_128 ;
F_101 ( V_2 , true , true ) ;
V_2 -> V_17 -> V_125 = V_125 ;
V_2 -> V_127 = V_129 ;
F_102 ( V_2 ) ;
} else {
F_100 ( V_126 L_27 ) ;
F_103 ( V_2 ) ;
V_2 -> V_127 = V_128 ;
F_104 ( V_2 , true , true ) ;
V_2 -> V_127 = V_130 ;
}
}
static bool F_105 ( struct V_121 * V_17 )
{
struct V_1 * V_2 = F_99 ( V_17 ) ;
return V_2 -> V_131 == 0 ;
}
int F_106 ( struct V_3 * V_4 ,
enum V_132 V_133 ,
enum V_134 V_109 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_133 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_141 ( ( void * ) V_4 ,
V_109 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_107 ( struct V_3 * V_4 ,
enum V_132 V_133 ,
enum V_142 V_109 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_133 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_143 ( ( void * ) V_4 ,
V_109 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_108 ( struct V_3 * V_4 ,
enum V_132 V_133 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_133 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_144 ( ( void * ) V_4 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return 0 ;
}
bool F_109 ( struct V_3 * V_4 ,
enum V_132 V_133 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_133 )
return V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_145 ( ( void * ) V_4 ) ;
}
return true ;
}
struct V_146 * F_110 ( struct V_3 * V_4 ,
enum V_132 type )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ )
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == type )
return & V_4 -> V_136 [ V_41 ] ;
return NULL ;
}
int F_111 ( struct V_3 * V_4 ,
enum V_132 type ,
T_2 V_147 , T_2 V_148 )
{
struct V_146 * V_149 = F_110 ( V_4 , type ) ;
if ( V_149 && ( ( V_149 -> V_139 -> V_147 > V_147 ) ||
( ( V_149 -> V_139 -> V_147 == V_147 ) &&
( V_149 -> V_139 -> V_148 >= V_148 ) ) ) )
return 0 ;
return 1 ;
}
int F_112 ( struct V_3 * V_4 ,
const struct V_150 * V_151 )
{
if ( ! V_151 )
return - V_46 ;
V_4 -> V_136 [ V_4 -> V_135 ++ ] . V_139 = V_151 ;
return 0 ;
}
static void F_113 ( struct V_3 * V_4 )
{
V_4 -> V_152 = false ;
if ( V_153 ) {
struct V_1 * V_97 = V_4 -> V_97 ;
const char * V_154 = F_114 ( V_97 -> V_17 ) ;
char * V_155 , * V_156 , * V_157 , * V_158 ;
V_155 = F_115 ( V_153 , V_85 ) ;
V_156 = V_155 ;
while ( ( V_157 = F_116 ( & V_156 , L_28 ) ) ) {
V_158 = F_116 ( & V_157 , L_29 ) ;
if ( ! strcmp ( V_154 , V_158 ) ) {
long V_159 ;
int V_160 = - 1 ;
V_4 -> V_152 = true ;
if ( V_157 )
V_160 = F_117 ( V_157 , 10 ,
& V_159 ) ;
if ( ! V_160 ) {
if ( V_159 < 1 )
V_159 = 1 ;
if ( V_159 > 6 )
V_159 = 6 ;
V_4 -> V_92 . V_159 = V_159 ;
} else {
V_4 -> V_92 . V_159 = 1 ;
}
break;
}
}
F_44 ( L_30 ,
V_153 , V_154 ,
V_4 -> V_152 , V_4 -> V_92 . V_159 ) ;
F_85 ( V_155 ) ;
}
}
static int F_118 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
F_113 ( V_4 ) ;
switch ( V_4 -> V_75 ) {
case V_161 :
case V_162 :
case V_76 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
if ( V_4 -> V_75 == V_166 || V_4 -> V_75 == V_167 )
V_4 -> V_168 = V_169 ;
else
V_4 -> V_168 = V_170 ;
V_27 = F_119 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#ifdef F_120
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_4 -> V_168 = V_176 ;
V_27 = F_121 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
#ifdef F_122
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
if ( ( V_4 -> V_75 == V_177 ) || ( V_4 -> V_75 == V_178 ) )
V_4 -> V_168 = V_182 ;
else
V_4 -> V_168 = V_183 ;
V_27 = F_123 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
default:
return - V_46 ;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ( V_184 & ( 1 << V_41 ) ) == 0 ) {
F_15 ( L_31 , V_41 ) ;
V_4 -> V_136 [ V_41 ] . V_137 . V_138 = false ;
} else {
if ( V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_185 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_185 ( ( void * ) V_4 ) ;
if ( V_27 == - V_186 ) {
V_4 -> V_136 [ V_41 ] . V_137 . V_138 = false ;
} else if ( V_27 ) {
F_15 ( L_32 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
} else {
V_4 -> V_136 [ V_41 ] . V_137 . V_138 = true ;
}
} else {
V_4 -> V_136 [ V_41 ] . V_137 . V_138 = true ;
}
}
}
V_4 -> V_188 &= V_189 ;
V_4 -> V_190 &= V_191 ;
return 0 ;
}
static int F_124 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_192 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_33 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_193 = true ;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_194 ) {
V_27 = F_22 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_34 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_195 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_35 , V_41 , V_27 ) ;
return V_27 ;
}
V_27 = F_50 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_36 , V_27 ) ;
return V_27 ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_196 = true ;
}
}
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_193 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_194 )
continue;
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_195 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_37 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_196 = true ;
}
return 0 ;
}
static int F_125 ( struct V_3 * V_4 )
{
int V_41 = 0 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_197 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_197 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_38 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_198 = true ;
}
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type != V_199 &&
V_4 -> V_136 [ V_41 ] . V_139 -> type != V_200 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_141 ( ( void * ) V_4 ,
V_201 ) ;
if ( V_27 ) {
F_15 ( L_39 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
}
}
return 0 ;
}
static int F_126 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_196 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_202 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_141 ( ( void * ) V_4 ,
V_203 ) ;
if ( V_27 ) {
F_15 ( L_40 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_204 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_127 ( L_41 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_196 = false ;
break;
}
}
for ( V_41 = V_4 -> V_135 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_196 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_194 ) {
F_48 ( V_4 ) ;
F_30 ( V_4 ) ;
}
if ( V_4 -> V_136 [ V_41 ] . V_139 -> type != V_199 &&
V_4 -> V_136 [ V_41 ] . V_139 -> type != V_200 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_141 ( ( void * ) V_4 ,
V_203 ) ;
if ( V_27 ) {
F_15 ( L_40 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
}
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_204 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_127 ( L_41 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_196 = false ;
}
for ( V_41 = V_4 -> V_135 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_193 )
continue;
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_205 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_127 ( L_42 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
}
V_4 -> V_136 [ V_41 ] . V_137 . V_193 = false ;
V_4 -> V_136 [ V_41 ] . V_137 . V_138 = false ;
}
for ( V_41 = V_4 -> V_135 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_198 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_206 )
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_206 ( ( void * ) V_4 ) ;
V_4 -> V_136 [ V_41 ] . V_137 . V_198 = false ;
}
return 0 ;
}
int F_128 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
V_27 = F_106 ( V_4 , V_202 ,
V_203 ) ;
if ( V_27 ) {
F_15 ( L_43 , V_27 ) ;
}
for ( V_41 = V_4 -> V_135 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_41 != V_202 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_141 ( ( void * ) V_4 ,
V_203 ) ;
if ( V_27 ) {
F_15 ( L_40 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
}
}
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_207 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_44 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
}
}
return 0 ;
}
static int F_129 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_208 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_45 ,
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 , V_27 ) ;
return V_27 ;
}
}
return 0 ;
}
static void F_130 ( struct V_3 * V_4 )
{
if ( F_131 ( V_4 ) )
V_4 -> V_209 . V_210 |= V_211 ;
}
int F_132 ( struct V_3 * V_4 ,
struct V_1 * V_97 ,
struct V_121 * V_17 ,
T_1 V_6 )
{
int V_27 , V_41 ;
bool V_212 = false ;
T_2 V_213 ;
V_4 -> V_214 = false ;
V_4 -> V_2 = & V_17 -> V_2 ;
V_4 -> V_97 = V_97 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_75 = V_6 & V_215 ;
V_4 -> V_216 = false ;
V_4 -> V_217 = V_218 ;
V_4 -> V_59 . V_71 = 512 * 1024 * 1024 ;
V_4 -> V_219 = false ;
V_4 -> V_220 = 0 ;
V_4 -> V_221 . V_222 = NULL ;
V_4 -> V_221 . V_223 = NULL ;
V_4 -> V_224 . V_225 = NULL ;
V_4 -> V_224 . V_226 = 0 ;
V_4 -> V_227 . V_228 = NULL ;
V_4 -> V_229 = F_133 ( V_230 ) ;
V_4 -> V_231 = & F_17 ;
V_4 -> V_232 = & F_19 ;
V_4 -> V_233 = & F_17 ;
V_4 -> V_234 = & F_19 ;
V_4 -> V_235 = & F_17 ;
V_4 -> V_236 = & F_19 ;
V_4 -> V_237 = & F_17 ;
V_4 -> V_238 = & F_19 ;
V_4 -> V_239 = & F_17 ;
V_4 -> V_240 = & F_19 ;
V_4 -> V_241 = & F_17 ;
V_4 -> V_242 = & F_19 ;
V_4 -> V_243 = & F_20 ;
V_4 -> V_244 = & F_21 ;
F_44 ( L_46 ,
V_245 [ V_4 -> V_75 ] , V_17 -> V_246 , V_17 -> V_18 ,
V_17 -> V_247 , V_17 -> V_248 , V_17 -> V_249 ) ;
F_89 ( & V_4 -> V_224 . V_250 ) ;
F_134 ( & V_4 -> V_251 . V_252 . V_250 , 0 ) ;
F_89 ( & V_4 -> V_79 . V_107 ) ;
F_89 ( & V_4 -> V_253 . V_254 ) ;
F_89 ( & V_4 -> V_255 ) ;
F_89 ( & V_4 -> V_256 ) ;
F_89 ( & V_4 -> V_257 ) ;
F_135 ( V_4 -> V_258 ) ;
F_95 ( V_4 ) ;
F_136 ( & V_4 -> V_14 ) ;
F_136 ( & V_4 -> V_259 ) ;
F_136 ( & V_4 -> V_260 ) ;
F_136 ( & V_4 -> V_261 ) ;
F_136 ( & V_4 -> V_262 ) ;
F_136 ( & V_4 -> V_263 ) ;
F_136 ( & V_4 -> V_264 ) ;
F_136 ( & V_4 -> V_265 . V_250 ) ;
F_137 ( & V_4 -> V_266 ) ;
F_89 ( & V_4 -> V_267 ) ;
F_137 ( & V_4 -> V_268 ) ;
F_136 ( & V_4 -> V_269 ) ;
if ( V_4 -> V_75 >= V_177 ) {
V_4 -> V_270 = F_40 ( V_4 -> V_17 , 5 ) ;
V_4 -> V_11 = F_41 ( V_4 -> V_17 , 5 ) ;
} else {
V_4 -> V_270 = F_40 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_11 = F_41 ( V_4 -> V_17 , 2 ) ;
}
V_4 -> V_13 = F_43 ( V_4 -> V_270 , V_4 -> V_11 ) ;
if ( V_4 -> V_13 == NULL ) {
return - V_47 ;
}
F_44 ( L_47 , ( T_1 ) V_4 -> V_270 ) ;
F_44 ( L_48 , ( unsigned ) V_4 -> V_11 ) ;
if ( V_4 -> V_75 >= V_177 )
F_39 ( V_4 ) ;
for ( V_41 = 0 ; V_41 < V_271 ; V_41 ++ ) {
if ( F_138 ( V_4 -> V_17 , V_41 ) & V_272 ) {
V_4 -> V_20 = F_41 ( V_4 -> V_17 , V_41 ) ;
V_4 -> V_21 = F_139 ( V_4 -> V_17 , V_41 , V_4 -> V_20 ) ;
break;
}
}
if ( V_4 -> V_21 == NULL )
F_15 ( L_49 ) ;
V_27 = F_118 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_140 ( V_4 -> V_17 , V_4 , NULL , F_92 ) ;
if ( V_273 == 1 )
V_212 = true ;
if ( F_1 ( V_97 ) )
V_212 = true ;
F_141 ( V_4 -> V_17 , & V_274 , V_212 ) ;
if ( V_212 )
F_142 ( V_4 -> V_2 , & V_4 -> V_275 ) ;
if ( ! F_143 ( V_4 ) ) {
V_27 = - V_46 ;
goto V_276;
}
if ( ! V_4 -> V_216 ) {
F_70 ( V_4 -> V_2 , L_50 ) ;
V_27 = - V_46 ;
goto V_276;
}
V_27 = F_86 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_51 ) ;
goto V_276;
}
F_130 ( V_4 ) ;
if ( F_62 ( V_4 ) ) {
if ( ! V_4 -> V_106 ) {
F_70 ( V_4 -> V_2 , L_52 ) ;
V_27 = - V_46 ;
goto V_276;
}
F_44 ( L_53 ) ;
V_27 = F_144 ( V_4 -> V_92 . V_93 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_54 ) ;
goto V_276;
}
} else {
F_44 ( L_55 ) ;
}
V_27 = F_145 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_56 ) ;
goto V_276;
}
F_146 ( V_4 ) ;
V_27 = F_147 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_57 ) ;
goto V_276;
}
F_148 ( V_4 -> V_97 ) ;
V_27 = F_124 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_58 ) ;
F_126 ( V_4 ) ;
goto V_276;
}
V_4 -> V_219 = true ;
if ( V_277 >= 0 )
V_213 = V_277 ;
else
V_213 = 8 ;
V_4 -> V_265 . V_278 = F_97 ( F_149 ( 1u , V_213 ) ) ;
F_150 ( V_4 ) ;
V_27 = F_151 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_59 , V_27 ) ;
goto V_276;
}
V_27 = F_152 ( V_4 ) ;
if ( V_27 )
F_15 ( L_60 , V_27 ) ;
V_27 = F_153 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_61 , V_27 ) ;
}
V_27 = F_154 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_62 , V_27 ) ;
}
V_27 = F_155 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_63 , V_27 ) ;
return V_27 ;
}
if ( ( V_279 & 1 ) ) {
if ( V_4 -> V_219 )
F_156 ( V_4 ) ;
else
F_44 ( L_64 ) ;
}
if ( ( V_279 & 2 ) ) {
if ( V_4 -> V_219 )
F_157 ( V_4 ) ;
else
F_44 ( L_65 ) ;
}
if ( V_280 ) {
if ( V_4 -> V_219 )
F_158 ( V_4 , V_280 ) ;
else
F_44 ( L_66 ) ;
}
V_27 = F_125 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_67 ) ;
goto V_276;
}
return 0 ;
V_276:
if ( V_212 )
F_159 ( V_4 -> V_2 ) ;
return V_27 ;
}
void F_160 ( struct V_3 * V_4 )
{
int V_27 ;
F_44 ( L_68 ) ;
V_4 -> V_214 = true ;
F_161 ( V_4 -> V_97 ) ;
F_162 ( V_4 ) ;
F_163 ( V_4 ) ;
F_164 ( V_4 ) ;
F_165 ( V_4 ) ;
V_27 = F_126 ( V_4 ) ;
V_4 -> V_219 = false ;
F_166 ( V_4 ) ;
F_84 ( V_4 ) ;
F_85 ( V_4 -> V_106 ) ;
V_4 -> V_106 = NULL ;
F_167 ( V_4 -> V_17 ) ;
if ( V_4 -> V_6 & V_7 )
F_159 ( V_4 -> V_2 ) ;
F_140 ( V_4 -> V_17 , NULL , NULL , NULL ) ;
if ( V_4 -> V_21 )
F_168 ( V_4 -> V_17 , V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
F_46 ( V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
if ( V_4 -> V_75 >= V_177 )
F_45 ( V_4 ) ;
F_169 ( V_4 ) ;
F_170 ( V_4 ) ;
}
int F_104 ( struct V_1 * V_2 , bool V_207 , bool V_281 )
{
struct V_3 * V_4 ;
struct V_282 * V_283 ;
struct V_284 * V_285 ;
int V_27 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_286 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_127 == V_130 )
return 0 ;
F_103 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 (connector, &dev->mode_config.connector_list, head) {
F_173 ( V_285 , V_287 ) ;
}
F_174 ( V_2 ) ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
struct V_288 * V_288 = F_175 ( V_283 ) ;
struct V_289 * V_290 = F_176 ( V_283 -> V_291 -> V_292 ) ;
struct V_293 * V_29 ;
if ( V_288 -> V_294 ) {
struct V_293 * V_295 = F_177 ( V_288 -> V_294 ) ;
V_27 = F_24 ( V_295 , false ) ;
if ( V_27 == 0 ) {
F_29 ( V_295 ) ;
F_27 ( V_295 ) ;
}
}
if ( V_290 == NULL || V_290 -> V_296 == NULL ) {
continue;
}
V_29 = F_177 ( V_290 -> V_296 ) ;
if ( ! F_178 ( V_4 , V_29 ) ) {
V_27 = F_24 ( V_29 , false ) ;
if ( V_27 == 0 ) {
F_29 ( V_29 ) ;
F_27 ( V_29 ) ;
}
}
}
F_162 ( V_4 ) ;
F_179 ( V_4 ) ;
V_27 = F_128 ( V_4 ) ;
F_162 ( V_4 ) ;
F_180 ( V_4 ) ;
F_181 ( V_2 -> V_17 ) ;
if ( V_207 ) {
F_182 ( V_2 -> V_17 ) ;
F_183 ( V_2 -> V_17 , V_297 ) ;
} else {
V_27 = F_184 ( V_4 ) ;
if ( V_27 )
F_15 ( L_69 ) ;
}
if ( V_281 ) {
F_185 () ;
F_186 ( V_4 , 1 ) ;
F_187 () ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , bool V_208 , bool V_281 )
{
struct V_284 * V_285 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_282 * V_283 ;
int V_27 ;
if ( V_2 -> V_127 == V_130 )
return 0 ;
if ( V_281 )
F_185 () ;
if ( V_208 ) {
F_183 ( V_2 -> V_17 , V_298 ) ;
F_188 ( V_2 -> V_17 ) ;
V_27 = F_189 ( V_2 -> V_17 ) ;
if ( V_27 ) {
if ( V_281 )
F_187 () ;
return V_27 ;
}
}
F_190 ( V_4 ) ;
if ( ! F_61 ( V_4 ) || ! V_208 ) {
V_27 = F_144 ( V_4 -> V_92 . V_93 ) ;
if ( V_27 )
F_15 ( L_70 ) ;
}
V_27 = F_129 ( V_4 ) ;
if ( V_27 )
F_15 ( L_71 , V_27 ) ;
F_191 ( V_4 ) ;
if ( V_208 ) {
V_27 = F_152 ( V_4 ) ;
if ( V_27 )
F_15 ( L_60 , V_27 ) ;
}
V_27 = F_125 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_172 (crtc, &dev->mode_config.crtc_list, head) {
struct V_288 * V_288 = F_175 ( V_283 ) ;
if ( V_288 -> V_294 ) {
struct V_293 * V_295 = F_177 ( V_288 -> V_294 ) ;
V_27 = F_24 ( V_295 , false ) ;
if ( V_27 == 0 ) {
V_27 = F_26 ( V_295 ,
V_32 ,
& V_288 -> V_299 ) ;
if ( V_27 != 0 )
F_15 ( L_72 , V_27 ) ;
F_27 ( V_295 ) ;
}
}
}
if ( V_281 ) {
F_192 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 (connector, &dev->mode_config.connector_list, head) {
F_173 ( V_285 , V_300 ) ;
}
F_174 ( V_2 ) ;
}
F_102 ( V_2 ) ;
#ifdef F_193
V_2 -> V_2 -> V_301 . V_302 ++ ;
#endif
F_194 ( V_2 ) ;
#ifdef F_193
V_2 -> V_2 -> V_301 . V_302 -- ;
#endif
if ( V_281 ) {
F_186 ( V_4 , 0 ) ;
F_187 () ;
}
return 0 ;
}
static bool F_195 ( struct V_3 * V_4 )
{
int V_41 ;
bool V_303 = false ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_304 )
V_4 -> V_136 [ V_41 ] . V_137 . V_305 =
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_304 ( V_4 ) ;
if ( V_4 -> V_136 [ V_41 ] . V_137 . V_305 ) {
F_44 ( L_73 , V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_187 ) ;
V_303 = true ;
}
}
return V_303 ;
}
static int F_196 ( struct V_3 * V_4 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_137 . V_305 &&
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_306 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_306 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static bool F_197 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( ( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_194 ) ||
( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_202 ) ||
( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_307 ) ||
( V_4 -> V_136 [ V_41 ] . V_139 -> type == V_308 ) ) {
if ( V_4 -> V_136 [ V_41 ] . V_137 . V_305 ) {
F_44 ( L_74 ) ;
return true ;
}
}
}
return false ;
}
static int F_198 ( struct V_3 * V_4 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_137 . V_305 &&
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_309 ) {
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_309 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static int F_199 ( struct V_3 * V_4 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_135 ; V_41 ++ ) {
if ( ! V_4 -> V_136 [ V_41 ] . V_137 . V_138 )
continue;
if ( V_4 -> V_136 [ V_41 ] . V_137 . V_305 &&
V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_310 )
V_27 = V_4 -> V_136 [ V_41 ] . V_139 -> V_140 -> V_310 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
bool F_200 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 & V_311 )
return false ;
return V_312 > 0 ? true : false ;
}
static int F_201 ( struct V_3 * V_4 ,
struct V_313 * V_314 ,
struct V_293 * V_315 ,
struct V_316 * * V_317 )
{
T_1 V_318 ;
int V_27 ;
if ( ! V_315 -> V_319 )
return 0 ;
V_27 = F_24 ( V_315 , false ) ;
if ( V_27 )
return V_27 ;
V_318 = F_202 ( V_315 -> V_320 . V_321 . V_322 ) ;
if ( V_318 == V_32 ) {
V_27 = F_203 ( V_4 , V_314 , V_315 ,
NULL , V_317 , true ) ;
if ( V_27 ) {
F_15 ( L_75 ) ;
goto V_77;
}
}
V_77:
F_27 ( V_315 ) ;
return V_27 ;
}
int F_204 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
int V_323 ;
bool V_324 ;
if ( ! F_195 ( V_4 ) ) {
F_44 ( L_76 ) ;
return 0 ;
}
F_205 ( & V_4 -> V_325 ) ;
V_323 = F_206 ( & V_4 -> V_221 . V_326 ) ;
for ( V_41 = 0 ; V_41 < V_230 ; ++ V_41 ) {
struct V_313 * V_314 = V_4 -> V_327 [ V_41 ] ;
if ( ! V_314 )
continue;
F_207 ( V_314 -> V_328 . V_329 ) ;
F_208 ( & V_314 -> V_328 ) ;
}
F_209 ( V_4 ) ;
V_324 = F_197 ( V_4 ) ;
if ( ! V_324 ) {
F_196 ( V_4 ) ;
V_27 = F_198 ( V_4 ) ;
F_199 ( V_4 ) ;
if ( V_27 || F_195 ( V_4 ) ) {
F_44 ( L_77 ) ;
V_324 = true ;
}
}
if ( V_324 ) {
V_27 = F_128 ( V_4 ) ;
V_330:
if ( V_4 -> V_92 . V_159 ) {
struct V_331 V_332 ;
F_210 ( V_4 , & V_332 ) ;
F_108 ( V_4 , V_194 ) ;
}
F_180 ( V_4 ) ;
V_27 = F_184 ( V_4 ) ;
F_190 ( V_4 ) ;
F_144 ( V_4 -> V_92 . V_93 ) ;
if ( ! V_27 ) {
F_59 ( V_4 -> V_2 , L_78 ) ;
V_27 = F_129 ( V_4 ) ;
}
}
if ( ! V_27 ) {
F_211 ( V_4 ) ;
if ( V_324 && F_200 ( V_4 ) ) {
V_27 = F_212 ( V_4 ) ;
if ( V_27 )
F_15 ( L_79 ) ;
}
V_27 = F_152 ( V_4 ) ;
if ( V_27 ) {
F_70 ( V_4 -> V_2 , L_60 , V_27 ) ;
V_27 = F_128 ( V_4 ) ;
V_324 = true ;
goto V_330;
}
if ( V_324 && F_200 ( V_4 ) ) {
struct V_313 * V_314 = V_4 -> V_221 . V_223 ;
struct V_293 * V_315 , * V_38 ;
struct V_316 * V_317 = NULL , * V_333 = NULL ;
F_44 ( L_80 ) ;
F_213 ( & V_4 -> V_267 ) ;
F_214 (bo, tmp, &adev->shadow_list, shadow_list) {
F_201 ( V_4 , V_314 , V_315 , & V_333 ) ;
if ( V_317 ) {
V_27 = F_215 ( V_317 , false ) ;
if ( V_27 ) {
F_216 ( V_27 , L_81 ) ;
break;
}
}
F_217 ( V_317 ) ;
V_317 = V_333 ;
}
F_218 ( & V_4 -> V_267 ) ;
if ( V_317 ) {
V_27 = F_215 ( V_317 , false ) ;
if ( V_27 )
F_216 ( V_27 , L_81 ) ;
}
F_217 ( V_317 ) ;
}
for ( V_41 = 0 ; V_41 < V_230 ; ++ V_41 ) {
struct V_313 * V_314 = V_4 -> V_327 [ V_41 ] ;
if ( ! V_314 )
continue;
F_219 ( & V_314 -> V_328 ) ;
F_220 ( V_314 -> V_328 . V_329 ) ;
}
} else {
F_70 ( V_4 -> V_2 , L_82 , V_27 ) ;
for ( V_41 = 0 ; V_41 < V_230 ; ++ V_41 ) {
if ( V_4 -> V_327 [ V_41 ] ) {
F_220 ( V_4 -> V_327 [ V_41 ] -> V_328 . V_329 ) ;
}
}
}
F_192 ( V_4 -> V_97 ) ;
F_221 ( & V_4 -> V_221 . V_326 , V_323 ) ;
if ( V_27 ) {
F_59 ( V_4 -> V_2 , L_83 ) ;
}
return V_27 ;
}
void F_222 ( struct V_3 * V_4 )
{
T_2 V_334 ;
int V_10 ;
if ( V_335 )
V_4 -> V_79 . V_336 = V_335 ;
if ( V_337 )
V_4 -> V_79 . V_338 = V_337 ;
if ( F_223 ( V_4 -> V_17 -> V_339 ) ) {
if ( V_4 -> V_79 . V_336 == 0 )
V_4 -> V_79 . V_336 = V_340 ;
if ( V_4 -> V_79 . V_338 == 0 )
V_4 -> V_79 . V_338 = V_341 ;
return;
}
if ( V_4 -> V_79 . V_336 == 0 ) {
V_10 = F_224 ( V_4 -> V_97 , & V_334 ) ;
if ( ! V_10 ) {
V_4 -> V_79 . V_336 = ( V_342 |
V_343 |
V_344 ) ;
if ( V_334 & V_345 )
V_4 -> V_79 . V_336 |= V_346 ;
if ( V_334 & V_347 )
V_4 -> V_79 . V_336 |= V_348 ;
if ( V_334 & V_349 )
V_4 -> V_79 . V_336 |= V_350 ;
} else {
V_4 -> V_79 . V_336 = V_340 ;
}
}
if ( V_4 -> V_79 . V_338 == 0 ) {
V_10 = F_225 ( V_4 -> V_97 , & V_334 ) ;
if ( ! V_10 ) {
switch ( V_334 ) {
case 32 :
V_4 -> V_79 . V_338 = ( V_351 |
V_352 |
V_353 |
V_354 |
V_355 |
V_356 |
V_357 ) ;
break;
case 16 :
V_4 -> V_79 . V_338 = ( V_352 |
V_353 |
V_354 |
V_355 |
V_356 |
V_357 ) ;
break;
case 12 :
V_4 -> V_79 . V_338 = ( V_353 |
V_354 |
V_355 |
V_356 |
V_357 ) ;
break;
case 8 :
V_4 -> V_79 . V_338 = ( V_354 |
V_355 |
V_356 |
V_357 ) ;
break;
case 4 :
V_4 -> V_79 . V_338 = ( V_355 |
V_356 |
V_357 ) ;
break;
case 2 :
V_4 -> V_79 . V_338 = ( V_356 |
V_357 ) ;
break;
case 1 :
V_4 -> V_79 . V_338 = V_357 ;
break;
default:
break;
}
} else {
V_4 -> V_79 . V_338 = V_341 ;
}
}
}
int F_226 ( struct V_3 * V_4 ,
const struct V_358 * V_359 ,
unsigned V_360 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_361 ; V_41 ++ ) {
if ( V_4 -> V_362 [ V_41 ] . V_359 == V_359 ) {
return 0 ;
}
}
V_41 = V_4 -> V_361 + 1 ;
if ( V_41 > V_363 ) {
F_15 ( L_84 ) ;
F_15 ( L_85
L_86 ) ;
return - V_46 ;
}
V_4 -> V_362 [ V_4 -> V_361 ] . V_359 = V_359 ;
V_4 -> V_362 [ V_4 -> V_361 ] . V_364 = V_360 ;
V_4 -> V_361 = V_41 ;
#if F_227 ( V_365 )
F_228 ( V_359 , V_360 ,
V_4 -> V_97 -> V_291 -> V_366 ,
V_4 -> V_97 -> V_291 ) ;
#endif
return 0 ;
}
static void F_170 ( struct V_3 * V_4 )
{
#if F_227 ( V_365 )
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_361 ; V_41 ++ ) {
F_229 ( V_4 -> V_362 [ V_41 ] . V_359 ,
V_4 -> V_362 [ V_41 ] . V_364 ,
V_4 -> V_97 -> V_291 ) ;
}
#endif
}
static T_7 F_230 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
bool V_373 , V_374 ;
unsigned V_375 , V_376 , V_377 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
V_373 = ( * V_370 >> 23 ) & 1 ;
if ( * V_370 & ( 1ULL << 62 ) ) {
V_377 = ( * V_370 >> 24 ) & 0x3FF ;
V_376 = ( * V_370 >> 34 ) & 0x3FF ;
V_375 = ( * V_370 >> 44 ) & 0x3FF ;
if ( V_377 == 0x3FF )
V_377 = 0xFFFFFFFF ;
if ( V_376 == 0x3FF )
V_376 = 0xFFFFFFFF ;
if ( V_375 == 0x3FF )
V_375 = 0xFFFFFFFF ;
V_374 = 1 ;
} else {
V_374 = 0 ;
}
* V_370 &= 0x3FFFF ;
if ( V_374 ) {
if ( ( V_376 != 0xFFFFFFFF && V_376 >= V_4 -> V_253 . V_378 . V_379 ) ||
( V_377 != 0xFFFFFFFF && V_377 >= V_4 -> V_253 . V_378 . V_380 ) )
return - V_46 ;
F_213 ( & V_4 -> V_256 ) ;
F_232 ( V_4 , V_377 ,
V_376 , V_375 ) ;
}
if ( V_373 )
F_213 ( & V_4 -> V_79 . V_107 ) ;
while ( V_44 ) {
T_1 V_381 ;
if ( * V_370 > V_4 -> V_11 )
goto V_382;
V_381 = F_35 ( * V_370 >> 2 ) ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 ) {
V_372 = V_27 ;
goto V_382;
}
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
V_382:
if ( V_374 ) {
F_232 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_218 ( & V_4 -> V_256 ) ;
}
if ( V_373 )
F_218 ( & V_4 -> V_79 . V_107 ) ;
return V_372 ;
}
static T_7 F_234 ( struct V_367 * V_368 , const char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
bool V_373 , V_374 ;
unsigned V_375 , V_376 , V_377 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
V_373 = ( * V_370 >> 23 ) & 1 ;
if ( * V_370 & ( 1ULL << 62 ) ) {
V_377 = ( * V_370 >> 24 ) & 0x3FF ;
V_376 = ( * V_370 >> 34 ) & 0x3FF ;
V_375 = ( * V_370 >> 44 ) & 0x3FF ;
if ( V_377 == 0x3FF )
V_377 = 0xFFFFFFFF ;
if ( V_376 == 0x3FF )
V_376 = 0xFFFFFFFF ;
if ( V_375 == 0x3FF )
V_375 = 0xFFFFFFFF ;
V_374 = 1 ;
} else {
V_374 = 0 ;
}
* V_370 &= 0x3FFFF ;
if ( V_374 ) {
if ( ( V_376 != 0xFFFFFFFF && V_376 >= V_4 -> V_253 . V_378 . V_379 ) ||
( V_377 != 0xFFFFFFFF && V_377 >= V_4 -> V_253 . V_378 . V_380 ) )
return - V_46 ;
F_213 ( & V_4 -> V_256 ) ;
F_232 ( V_4 , V_377 ,
V_376 , V_375 ) ;
}
if ( V_373 )
F_213 ( & V_4 -> V_79 . V_107 ) ;
while ( V_44 ) {
T_1 V_381 ;
if ( * V_370 > V_4 -> V_11 )
return V_372 ;
V_27 = F_235 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
F_36 ( * V_370 >> 2 , V_381 ) ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
if ( V_374 ) {
F_232 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_218 ( & V_4 -> V_256 ) ;
}
if ( V_373 )
F_218 ( & V_4 -> V_79 . V_107 ) ;
return V_372 ;
}
static T_7 F_236 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_381 ;
V_381 = F_237 ( * V_370 >> 2 ) ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_238 ( struct V_367 * V_368 , const char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_381 ;
V_27 = F_235 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
F_239 ( * V_370 >> 2 , V_381 ) ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_240 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_381 ;
V_381 = F_241 ( * V_370 >> 2 ) ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_242 ( struct V_367 * V_368 , const char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_381 ;
V_27 = F_235 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
F_243 ( * V_370 >> 2 , V_381 ) ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_244 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_381 ;
V_381 = F_245 ( * V_370 ) ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_246 ( struct V_367 * V_368 , const char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_381 ;
V_27 = F_235 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
F_247 ( * V_370 , V_381 ) ;
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_248 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
T_7 V_372 = 0 ;
int V_27 ;
T_1 * V_378 , V_383 = 0 ;
if ( V_44 & 0x3 || * V_370 & 0x3 )
return - V_46 ;
V_378 = F_249 ( 256 , sizeof( * V_378 ) , V_85 ) ;
if ( ! V_378 )
return - V_47 ;
V_378 [ V_383 ++ ] = 2 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_380 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_384 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_385 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_379 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_386 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_387 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_388 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_389 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_390 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_391 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_392 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_393 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_394 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_395 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_396 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_397 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_398 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_399 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_400 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_401 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_402 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_403 ;
V_378 [ V_383 ++ ] = V_4 -> V_253 . V_378 . V_404 ;
V_378 [ V_383 ++ ] = V_4 -> V_405 ;
V_378 [ V_383 ++ ] = V_4 -> V_190 ;
V_378 [ V_383 ++ ] = V_4 -> V_188 ;
V_378 [ V_383 ++ ] = V_4 -> V_168 ;
V_378 [ V_383 ++ ] = V_4 -> V_406 ;
while ( V_44 && ( * V_370 < V_383 * 4 ) ) {
T_1 V_381 ;
V_381 = V_378 [ * V_370 >> 2 ] ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 ) {
F_85 ( V_378 ) ;
return V_27 ;
}
V_372 += 4 ;
V_369 += 4 ;
* V_370 += 4 ;
V_44 -= 4 ;
}
F_85 ( V_378 ) ;
return V_372 ;
}
static T_7 F_250 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = F_231 ( V_368 ) -> V_371 ;
int V_407 , V_27 ;
T_10 V_381 ;
if ( V_44 != 4 || * V_370 & 0x3 )
return - V_46 ;
V_407 = * V_370 >> 2 ;
if ( V_4 -> V_408 . V_409 && V_4 -> V_408 . V_409 -> V_410 )
V_27 = V_4 -> V_408 . V_409 -> V_410 ( V_4 -> V_408 . V_411 , V_407 , & V_381 ) ;
else
return - V_46 ;
if ( ! V_27 )
V_27 = F_233 ( V_381 , ( T_10 * ) V_369 ) ;
return ! V_27 ? 4 : V_27 ;
}
static T_7 F_251 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = V_368 -> V_412 -> V_371 ;
int V_27 , V_413 ;
T_7 V_372 = 0 ;
T_1 V_57 , V_414 , V_415 , V_416 , V_417 , V_418 , V_81 [ 32 ] ;
if ( V_44 & 3 || * V_370 & 3 )
return - V_46 ;
V_57 = ( * V_370 & 0x7F ) ;
V_414 = ( ( * V_370 >> 7 ) & 0xFF ) ;
V_415 = ( ( * V_370 >> 15 ) & 0xFF ) ;
V_416 = ( ( * V_370 >> 23 ) & 0xFF ) ;
V_417 = ( ( * V_370 >> 31 ) & 0xFF ) ;
V_418 = ( ( * V_370 >> 37 ) & 0xFF ) ;
F_213 ( & V_4 -> V_256 ) ;
F_232 ( V_4 , V_414 , V_415 , V_416 ) ;
V_413 = 0 ;
if ( V_4 -> V_253 . V_140 -> V_419 )
V_4 -> V_253 . V_140 -> V_419 ( V_4 , V_418 , V_417 , V_81 , & V_413 ) ;
F_232 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_218 ( & V_4 -> V_256 ) ;
if ( ! V_413 )
return - V_46 ;
while ( V_44 && ( V_57 < V_413 * 4 ) ) {
T_1 V_381 ;
V_381 = V_81 [ V_57 >> 2 ] ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 )
return V_27 ;
V_372 += 4 ;
V_369 += 4 ;
V_57 += 4 ;
V_44 -= 4 ;
}
return V_372 ;
}
static T_7 F_252 ( struct V_367 * V_368 , char T_8 * V_369 ,
T_4 V_44 , T_9 * V_370 )
{
struct V_3 * V_4 = V_368 -> V_412 -> V_371 ;
int V_27 ;
T_7 V_372 = 0 ;
T_1 V_57 , V_414 , V_415 , V_416 , V_417 , V_418 , V_329 , V_420 , * V_81 ;
if ( V_44 & 3 || * V_370 & 3 )
return - V_46 ;
V_57 = ( * V_370 & 0xFFF ) ;
V_414 = ( ( * V_370 >> 12 ) & 0xFF ) ;
V_415 = ( ( * V_370 >> 20 ) & 0xFF ) ;
V_416 = ( ( * V_370 >> 28 ) & 0xFF ) ;
V_417 = ( ( * V_370 >> 36 ) & 0xFF ) ;
V_418 = ( ( * V_370 >> 44 ) & 0xFF ) ;
V_329 = ( ( * V_370 >> 52 ) & 0xFF ) ;
V_420 = ( ( * V_370 >> 60 ) & 1 ) ;
V_81 = F_249 ( 1024 , sizeof( * V_81 ) , V_85 ) ;
if ( ! V_81 )
return - V_47 ;
F_213 ( & V_4 -> V_256 ) ;
F_232 ( V_4 , V_414 , V_415 , V_416 ) ;
if ( V_420 == 0 ) {
if ( V_4 -> V_253 . V_140 -> V_421 )
V_4 -> V_253 . V_140 -> V_421 ( V_4 , V_418 , V_417 , V_329 , V_57 , V_44 >> 2 , V_81 ) ;
} else {
if ( V_4 -> V_253 . V_140 -> V_422 )
V_4 -> V_253 . V_140 -> V_422 ( V_4 , V_418 , V_417 , V_57 , V_44 >> 2 , V_81 ) ;
}
F_232 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_218 ( & V_4 -> V_256 ) ;
while ( V_44 ) {
T_1 V_381 ;
V_381 = V_81 [ V_57 ++ ] ;
V_27 = F_233 ( V_381 , ( T_1 * ) V_369 ) ;
if ( V_27 ) {
V_372 = V_27 ;
goto V_77;
}
V_372 += 4 ;
V_369 += 4 ;
V_44 -= 4 ;
}
V_77:
F_85 ( V_81 ) ;
return V_372 ;
}
static int F_154 ( struct V_3 * V_4 )
{
struct V_423 * V_148 = V_4 -> V_97 -> V_291 ;
struct V_424 * V_425 , * V_426 = V_148 -> V_366 ;
unsigned V_41 , V_427 ;
for ( V_41 = 0 ; V_41 < F_253 ( V_428 ) ; V_41 ++ ) {
V_425 = F_254 ( V_429 [ V_41 ] ,
V_430 | V_431 , V_426 ,
V_4 , V_428 [ V_41 ] ) ;
if ( F_255 ( V_425 ) ) {
for ( V_427 = 0 ; V_427 < V_41 ; V_427 ++ ) {
F_256 ( V_4 -> V_428 [ V_41 ] ) ;
V_4 -> V_428 [ V_41 ] = NULL ;
}
return F_257 ( V_425 ) ;
}
if ( ! V_41 )
F_258 ( V_425 -> V_432 , V_4 -> V_11 ) ;
V_4 -> V_428 [ V_41 ] = V_425 ;
}
return 0 ;
}
static void F_169 ( struct V_3 * V_4 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < F_253 ( V_428 ) ; V_41 ++ ) {
if ( V_4 -> V_428 [ V_41 ] ) {
F_256 ( V_4 -> V_428 [ V_41 ] ) ;
V_4 -> V_428 [ V_41 ] = NULL ;
}
}
}
int F_259 ( struct V_423 * V_148 )
{
return 0 ;
}
void F_260 ( struct V_423 * V_148 )
{
}
static int F_154 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_169 ( struct V_3 * V_4 ) { }
