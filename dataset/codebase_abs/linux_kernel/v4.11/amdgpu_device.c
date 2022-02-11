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
if ( F_3 ( V_4 ) ) {
F_4 ( F_5 () ) ;
return F_6 ( V_4 , V_8 ) ;
}
if ( ( V_8 * 4 ) < V_4 -> V_11 && ! V_9 )
V_10 = F_7 ( ( ( void V_12 * ) V_4 -> V_13 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_8 ( & V_4 -> V_14 , V_6 ) ;
F_9 ( ( V_8 * 4 ) , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_15 * 4 ) ) ;
V_10 = F_7 ( ( ( void V_12 * ) V_4 -> V_13 ) + ( V_16 * 4 ) ) ;
F_10 ( & V_4 -> V_14 , V_6 ) ;
}
F_11 ( V_4 -> V_17 -> V_18 , V_8 , V_10 ) ;
return V_10 ;
}
void F_12 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_19 ,
bool V_9 )
{
F_13 ( V_4 -> V_17 -> V_18 , V_8 , V_19 ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( F_5 () ) ;
return F_14 ( V_4 , V_8 , V_19 ) ;
}
if ( ( V_8 * 4 ) < V_4 -> V_11 && ! V_9 )
F_9 ( V_19 , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_8 ( & V_4 -> V_14 , V_6 ) ;
F_9 ( ( V_8 * 4 ) , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_15 * 4 ) ) ;
F_9 ( V_19 , ( ( void V_12 * ) V_4 -> V_13 ) + ( V_16 * 4 ) ) ;
F_10 ( & V_4 -> V_14 , V_6 ) ;
}
}
T_2 F_15 ( struct V_3 * V_4 , T_2 V_8 )
{
if ( ( V_8 * 4 ) < V_4 -> V_20 )
return F_16 ( V_4 -> V_21 + ( V_8 * 4 ) ) ;
else {
F_17 ( ( V_8 * 4 ) , V_4 -> V_21 + ( V_15 * 4 ) ) ;
return F_16 ( V_4 -> V_21 + ( V_16 * 4 ) ) ;
}
}
void F_18 ( struct V_3 * V_4 , T_2 V_8 , T_2 V_19 )
{
if ( ( V_8 * 4 ) < V_4 -> V_20 )
F_17 ( V_19 , V_4 -> V_21 + ( V_8 * 4 ) ) ;
else {
F_17 ( ( V_8 * 4 ) , V_4 -> V_21 + ( V_15 * 4 ) ) ;
F_17 ( V_19 , V_4 -> V_21 + ( V_16 * 4 ) ) ;
}
}
T_2 F_19 ( struct V_3 * V_4 , T_2 V_22 )
{
if ( V_22 < V_4 -> V_23 . V_24 ) {
return F_7 ( V_4 -> V_23 . V_25 + V_22 ) ;
} else {
F_20 ( L_1 , V_22 ) ;
return 0 ;
}
}
void F_21 ( struct V_3 * V_4 , T_2 V_22 , T_2 V_19 )
{
if ( V_22 < V_4 -> V_23 . V_24 ) {
F_9 ( V_19 , V_4 -> V_23 . V_25 + V_22 ) ;
} else {
F_20 ( L_2 , V_22 ) ;
}
}
static T_1 F_22 ( struct V_3 * V_4 , T_1 V_8 )
{
F_20 ( L_3 , V_8 ) ;
F_23 () ;
return 0 ;
}
static void F_24 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_19 )
{
F_20 ( L_4 ,
V_8 , V_19 ) ;
F_23 () ;
}
static T_1 F_25 ( struct V_3 * V_4 ,
T_1 V_26 , T_1 V_8 )
{
F_20 ( L_5 ,
V_8 , V_26 ) ;
F_23 () ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 ,
T_1 V_26 ,
T_1 V_8 , T_1 V_19 )
{
F_20 ( L_6 ,
V_8 , V_26 , V_19 ) ;
F_23 () ;
}
static int F_27 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_28 . V_29 == NULL ) {
V_27 = F_28 ( V_4 , V_30 ,
V_31 , true , V_32 ,
V_33 |
V_34 ,
NULL , NULL , & V_4 -> V_28 . V_29 ) ;
if ( V_27 ) {
return V_27 ;
}
}
V_27 = F_29 ( V_4 -> V_28 . V_29 , false ) ;
if ( F_30 ( V_27 != 0 ) )
return V_27 ;
V_27 = F_31 ( V_4 -> V_28 . V_29 ,
V_32 , & V_4 -> V_28 . V_35 ) ;
if ( V_27 ) {
F_32 ( V_4 -> V_28 . V_29 ) ;
return V_27 ;
}
V_27 = F_33 ( V_4 -> V_28 . V_29 ,
( void * * ) & V_4 -> V_28 . V_25 ) ;
if ( V_27 )
F_34 ( V_4 -> V_28 . V_29 ) ;
F_32 ( V_4 -> V_28 . V_29 ) ;
return V_27 ;
}
static void F_35 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_28 . V_29 == NULL ) {
return;
}
V_27 = F_29 ( V_4 -> V_28 . V_29 , false ) ;
if ( F_36 ( V_27 == 0 ) ) {
F_37 ( V_4 -> V_28 . V_29 ) ;
F_34 ( V_4 -> V_28 . V_29 ) ;
F_32 ( V_4 -> V_28 . V_29 ) ;
}
F_38 ( & V_4 -> V_28 . V_29 ) ;
}
void F_39 ( struct V_3 * V_4 ,
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
V_38 = F_40 ( V_8 ) ;
V_38 &= ~ V_39 ;
V_38 |= V_40 ;
}
F_41 ( V_8 , V_38 ) ;
}
}
void F_42 ( struct V_3 * V_4 )
{
F_43 ( V_4 -> V_17 , 0x7c , V_42 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
V_4 -> V_23 . V_43 = F_45 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_23 . V_44 = F_46 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_23 . V_24 = F_47 ( T_2 , V_4 -> V_23 . V_44 / sizeof( T_2 ) ,
V_45 + 1 ) ;
if ( V_4 -> V_23 . V_24 == 0 )
return - V_46 ;
V_4 -> V_23 . V_25 = F_48 ( V_4 -> V_23 . V_43 , V_4 -> V_23 . V_24 * sizeof( T_2 ) ) ;
if ( V_4 -> V_23 . V_25 == NULL ) {
return - V_47 ;
}
F_49 ( L_7 , ( T_1 ) V_4 -> V_23 . V_43 ) ;
F_49 ( L_8 , ( unsigned ) V_4 -> V_23 . V_44 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 )
{
F_51 ( V_4 -> V_23 . V_25 ) ;
V_4 -> V_23 . V_25 = NULL ;
}
void F_52 ( struct V_3 * V_4 ,
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
static void F_53 ( struct V_3 * V_4 )
{
if ( V_4 -> V_51 . V_52 ) {
F_54 ( & V_4 -> V_51 . V_52 ,
& V_4 -> V_51 . V_35 ,
( void * * ) & V_4 -> V_51 . V_51 ) ;
V_4 -> V_51 . V_52 = NULL ;
}
}
static int F_55 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_51 . V_52 == NULL ) {
V_27 = F_56 ( V_4 , V_53 * sizeof( T_1 ) ,
V_31 , V_54 ,
& V_4 -> V_51 . V_52 , & V_4 -> V_51 . V_35 ,
( void * * ) & V_4 -> V_51 . V_51 ) ;
if ( V_27 ) {
F_57 ( V_4 -> V_2 , L_9 , V_27 ) ;
return V_27 ;
}
V_4 -> V_51 . V_55 = V_53 ;
memset ( & V_4 -> V_51 . V_56 , 0 , sizeof( V_4 -> V_51 . V_56 ) ) ;
memset ( ( char * ) V_4 -> V_51 . V_51 , 0 , V_53 * sizeof( T_1 ) ) ;
}
return 0 ;
}
int F_58 ( struct V_3 * V_4 , T_2 * V_51 )
{
unsigned long V_57 = F_59 ( V_4 -> V_51 . V_56 , V_4 -> V_51 . V_55 ) ;
if ( V_57 < V_4 -> V_51 . V_55 ) {
F_60 ( V_57 , V_4 -> V_51 . V_56 ) ;
* V_51 = V_57 ;
return 0 ;
} else {
return - V_46 ;
}
}
void F_61 ( struct V_3 * V_4 , T_2 V_51 )
{
if ( V_51 < V_4 -> V_51 . V_55 )
F_62 ( V_51 , V_4 -> V_51 . V_56 ) ;
}
void F_63 ( struct V_3 * V_4 , struct V_58 * V_59 , T_5 V_43 )
{
T_6 V_60 = ( T_6 ) V_61 << 20 ;
V_59 -> V_62 = V_43 ;
if ( V_59 -> V_63 > ( V_4 -> V_59 . V_64 - V_43 + 1 ) ) {
F_57 ( V_4 -> V_2 , L_10 ) ;
V_59 -> V_65 = V_59 -> V_66 ;
V_59 -> V_63 = V_59 -> V_66 ;
}
V_59 -> V_67 = V_59 -> V_62 + V_59 -> V_63 - 1 ;
if ( V_60 && V_60 < V_59 -> V_65 )
V_59 -> V_65 = V_60 ;
F_64 ( V_4 -> V_2 , L_11 ,
V_59 -> V_63 >> 20 , V_59 -> V_62 ,
V_59 -> V_67 , V_59 -> V_65 >> 20 ) ;
}
void F_65 ( struct V_3 * V_4 , struct V_58 * V_59 )
{
T_5 V_68 , V_69 ;
V_68 = ( ( V_4 -> V_59 . V_64 - V_59 -> V_67 ) + V_59 -> V_70 ) & ~ V_59 -> V_70 ;
V_69 = V_59 -> V_62 & ~ V_59 -> V_70 ;
if ( V_69 > V_68 ) {
if ( V_59 -> V_71 > V_69 ) {
F_57 ( V_4 -> V_2 , L_12 ) ;
V_59 -> V_71 = V_69 ;
}
V_59 -> V_72 = ( V_59 -> V_62 & ~ V_59 -> V_70 ) - V_59 -> V_71 ;
} else {
if ( V_59 -> V_71 > V_68 ) {
F_57 ( V_4 -> V_2 , L_12 ) ;
V_59 -> V_71 = V_68 ;
}
V_59 -> V_72 = ( V_59 -> V_67 + 1 + V_59 -> V_70 ) & ~ V_59 -> V_70 ;
}
V_59 -> V_73 = V_59 -> V_72 + V_59 -> V_71 - 1 ;
F_64 ( V_4 -> V_2 , L_13 ,
V_59 -> V_71 >> 20 , V_59 -> V_72 , V_59 -> V_73 ) ;
}
bool F_66 ( struct V_3 * V_4 )
{
T_1 V_8 ;
if ( V_4 -> V_74 ) {
V_4 -> V_74 = false ;
return true ;
}
V_8 = F_40 ( V_75 ) ;
if ( V_8 )
return false ;
return true ;
}
static bool F_67 ( struct V_3 * V_4 )
{
if ( F_68 ( V_4 ) )
return false ;
if ( F_69 ( V_4 ) ) {
if ( V_4 -> V_76 == V_77 ) {
int V_78 ;
T_1 V_79 ;
V_78 = F_70 ( & V_4 -> V_80 . V_81 , L_14 , V_4 -> V_2 ) ;
if ( V_78 )
return true ;
V_79 = * ( ( T_1 * ) V_4 -> V_80 . V_81 -> V_82 + 69 ) ;
if ( V_79 < 0x00160e00 )
return true ;
}
}
return F_66 ( V_4 ) ;
}
int F_71 ( struct V_3 * V_4 )
{
if ( V_4 -> V_83 . V_84 )
return 0 ;
V_4 -> V_83 . V_84 = F_72 ( V_85 | V_86 | V_87 ) ;
if ( V_4 -> V_83 . V_84 == NULL )
return - V_47 ;
V_4 -> V_83 . V_88 = F_73 ( V_4 -> V_17 , V_4 -> V_83 . V_84 ,
0 , V_31 , V_89 ) ;
if ( F_74 ( V_4 -> V_17 , V_4 -> V_83 . V_88 ) ) {
F_75 ( & V_4 -> V_17 -> V_2 , L_15 ) ;
F_76 ( V_4 -> V_83 . V_84 ) ;
V_4 -> V_83 . V_84 = NULL ;
return - V_47 ;
}
return 0 ;
}
void F_77 ( struct V_3 * V_4 )
{
if ( V_4 -> V_83 . V_84 == NULL )
return;
F_78 ( V_4 -> V_17 , V_4 -> V_83 . V_88 ,
V_31 , V_89 ) ;
F_76 ( V_4 -> V_83 . V_84 ) ;
V_4 -> V_83 . V_84 = NULL ;
}
static T_1 F_79 ( struct V_90 * V_91 , T_1 V_8 )
{
return 0 ;
}
static void F_80 ( struct V_90 * V_91 , T_1 V_8 , T_1 V_92 )
{
}
static T_1 F_81 ( struct V_90 * V_91 , T_1 V_8 )
{
return 0 ;
}
static void F_82 ( struct V_90 * V_91 , T_1 V_8 , T_1 V_92 )
{
}
static void F_83 ( struct V_90 * V_91 , T_1 V_8 , T_1 V_92 )
{
struct V_3 * V_4 = V_91 -> V_2 -> V_5 ;
F_41 ( V_8 , V_92 ) ;
}
static T_1 F_84 ( struct V_90 * V_91 , T_1 V_8 )
{
struct V_3 * V_4 = V_91 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_40 ( V_8 ) ;
return V_27 ;
}
static void F_85 ( struct V_90 * V_91 , T_1 V_8 , T_1 V_92 )
{
struct V_3 * V_4 = V_91 -> V_2 -> V_5 ;
F_86 ( V_8 , V_92 ) ;
}
static T_1 F_87 ( struct V_90 * V_91 , T_1 V_8 )
{
struct V_3 * V_4 = V_91 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_88 ( V_8 ) ;
return V_27 ;
}
static void F_89 ( struct V_3 * V_4 )
{
if ( V_4 -> V_93 . V_94 ) {
F_90 ( V_4 -> V_93 . V_94 -> V_95 ) ;
F_90 ( V_4 -> V_93 . V_94 -> V_96 ) ;
}
F_90 ( V_4 -> V_93 . V_94 ) ;
V_4 -> V_93 . V_94 = NULL ;
F_90 ( V_4 -> V_93 . V_97 ) ;
V_4 -> V_93 . V_97 = NULL ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_90 * V_97 =
F_92 ( sizeof( struct V_90 ) , V_86 ) ;
if ( ! V_97 )
return - V_47 ;
V_4 -> V_93 . V_97 = V_97 ;
V_97 -> V_2 = V_4 -> V_98 ;
V_97 -> V_99 = F_84 ;
V_97 -> V_100 = F_83 ;
if ( V_4 -> V_21 ) {
V_97 -> V_101 = F_87 ;
V_97 -> V_102 = F_85 ;
} else {
F_49 ( L_16 ) ;
V_97 -> V_101 = F_84 ;
V_97 -> V_102 = F_83 ;
}
V_97 -> V_103 = F_81 ;
V_97 -> V_104 = F_82 ;
V_97 -> V_105 = F_79 ;
V_97 -> V_106 = F_80 ;
V_4 -> V_93 . V_94 = F_93 ( V_97 , V_4 -> V_107 ) ;
if ( ! V_4 -> V_93 . V_94 ) {
F_89 ( V_4 ) ;
return - V_47 ;
}
F_94 ( & V_4 -> V_93 . V_94 -> V_108 ) ;
F_95 ( V_4 ) ;
F_96 ( V_4 -> V_93 . V_94 ) ;
return 0 ;
}
static unsigned int F_97 ( void * V_109 , bool V_110 )
{
struct V_3 * V_4 = V_109 ;
F_98 ( V_4 , V_110 ) ;
if ( V_110 )
return V_111 | V_112 |
V_113 | V_114 ;
else
return V_113 | V_114 ;
}
static bool F_99 ( int V_115 )
{
return ( V_115 & ( V_115 - 1 ) ) == 0 ;
}
static void F_100 ( struct V_3 * V_4 )
{
if ( V_116 < 4 ) {
F_57 ( V_4 -> V_2 , L_17 ,
V_116 ) ;
V_116 = 4 ;
} else if ( ! F_99 ( V_116 ) ) {
F_57 ( V_4 -> V_2 , L_18 ,
V_116 ) ;
V_116 = F_101 ( V_116 ) ;
}
if ( V_117 != - 1 ) {
if ( V_117 < 32 ) {
F_57 ( V_4 -> V_2 , L_19 ,
V_117 ) ;
V_117 = - 1 ;
}
}
if ( ! F_99 ( V_118 ) ) {
F_57 ( V_4 -> V_2 , L_20 ,
V_118 ) ;
V_118 = 8 ;
}
if ( V_118 < 1 ) {
F_57 ( V_4 -> V_2 , L_21 ,
V_118 ) ;
V_118 = 8 ;
}
if ( V_118 > 1024 ) {
F_57 ( V_4 -> V_2 , L_22 ,
V_118 ) ;
V_118 = 8 ;
}
if ( V_119 == - 1 ) {
unsigned V_120 = F_102 ( V_118 ) + 18 ;
if ( V_118 <= 8 )
V_119 = V_120 - 9 ;
else
V_119 = ( V_120 + 3 ) / 2 ;
} else if ( V_119 < 9 ) {
F_57 ( V_4 -> V_2 , L_23 ,
V_119 ) ;
V_119 = 9 ;
}
if ( V_119 > 24 ||
( V_118 * 1024 ) < ( 1ull << V_119 ) ) {
F_57 ( V_4 -> V_2 , L_24 ,
V_119 ) ;
V_119 = 9 ;
}
if ( V_121 != - 1 && ( V_121 < 16 ||
! F_99 ( V_121 ) ) ) {
F_57 ( V_4 -> V_2 , L_25 ,
V_121 ) ;
V_121 = 1024 ;
}
}
static void F_103 ( struct V_122 * V_17 , enum V_123 V_110 )
{
struct V_1 * V_2 = F_104 ( V_17 ) ;
if ( F_1 ( V_2 ) && V_110 == V_124 )
return;
if ( V_110 == V_125 ) {
unsigned V_126 = V_2 -> V_17 -> V_126 ;
F_105 ( V_127 L_26 ) ;
V_2 -> V_128 = V_129 ;
F_106 ( V_2 , true , true ) ;
V_2 -> V_17 -> V_126 = V_126 ;
V_2 -> V_128 = V_130 ;
F_107 ( V_2 ) ;
} else {
F_105 ( V_127 L_27 ) ;
F_108 ( V_2 ) ;
V_2 -> V_128 = V_129 ;
F_109 ( V_2 , true , true ) ;
V_2 -> V_128 = V_131 ;
}
}
static bool F_110 ( struct V_122 * V_17 )
{
struct V_1 * V_2 = F_104 ( V_17 ) ;
return V_2 -> V_132 == 0 ;
}
int F_111 ( struct V_3 * V_4 ,
enum V_133 V_134 ,
enum V_135 V_110 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_134 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_142 ( ( void * ) V_4 ,
V_110 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_112 ( struct V_3 * V_4 ,
enum V_133 V_134 ,
enum V_143 V_110 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_134 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_144 ( ( void * ) V_4 ,
V_110 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
void F_113 ( struct V_3 * V_4 , T_2 * V_6 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_145 )
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_145 ( ( void * ) V_4 , V_6 ) ;
}
}
int F_114 ( struct V_3 * V_4 ,
enum V_133 V_134 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_134 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_146 ( ( void * ) V_4 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return 0 ;
}
bool F_115 ( struct V_3 * V_4 ,
enum V_133 V_134 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_134 )
return V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_147 ( ( void * ) V_4 ) ;
}
return true ;
}
struct V_148 * F_116 ( struct V_3 * V_4 ,
enum V_133 type )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ )
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == type )
return & V_4 -> V_137 [ V_41 ] ;
return NULL ;
}
int F_117 ( struct V_3 * V_4 ,
enum V_133 type ,
T_2 V_149 , T_2 V_150 )
{
struct V_148 * V_151 = F_116 ( V_4 , type ) ;
if ( V_151 && ( ( V_151 -> V_140 -> V_149 > V_149 ) ||
( ( V_151 -> V_140 -> V_149 == V_149 ) &&
( V_151 -> V_140 -> V_150 >= V_150 ) ) ) )
return 0 ;
return 1 ;
}
int F_118 ( struct V_3 * V_4 ,
const struct V_152 * V_153 )
{
if ( ! V_153 )
return - V_46 ;
V_4 -> V_137 [ V_4 -> V_136 ++ ] . V_140 = V_153 ;
return 0 ;
}
static void F_119 ( struct V_3 * V_4 )
{
V_4 -> V_154 = false ;
if ( V_155 ) {
struct V_1 * V_98 = V_4 -> V_98 ;
const char * V_156 = F_120 ( V_98 -> V_17 ) ;
char * V_157 , * V_158 , * V_159 , * V_160 ;
V_157 = F_121 ( V_155 , V_86 ) ;
V_158 = V_157 ;
while ( ( V_159 = F_122 ( & V_158 , L_28 ) ) ) {
V_160 = F_122 ( & V_159 , L_29 ) ;
if ( ! strcmp ( L_30 , V_160 )
|| ! strcmp ( V_156 , V_160 ) ) {
long V_161 ;
int V_162 = - 1 ;
V_4 -> V_154 = true ;
if ( V_159 )
V_162 = F_123 ( V_159 , 10 ,
& V_161 ) ;
if ( ! V_162 ) {
if ( V_161 < 1 )
V_161 = 1 ;
if ( V_161 > 6 )
V_161 = 6 ;
V_4 -> V_93 . V_161 = V_161 ;
} else {
V_4 -> V_93 . V_161 = 1 ;
}
break;
}
}
F_49 ( L_31 ,
V_155 , V_156 ,
V_4 -> V_154 , V_4 -> V_93 . V_161 ) ;
F_90 ( V_157 ) ;
}
}
static int F_124 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
F_119 ( V_4 ) ;
switch ( V_4 -> V_76 ) {
case V_163 :
case V_164 :
case V_77 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
if ( V_4 -> V_76 == V_168 || V_4 -> V_76 == V_169 )
V_4 -> V_170 = V_171 ;
else
V_4 -> V_170 = V_172 ;
V_27 = F_125 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#ifdef F_126
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_4 -> V_170 = V_178 ;
V_27 = F_127 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
#ifdef F_128
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( ( V_4 -> V_76 == V_179 ) || ( V_4 -> V_76 == V_180 ) )
V_4 -> V_170 = V_184 ;
else
V_4 -> V_170 = V_185 ;
V_27 = F_129 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
default:
return - V_46 ;
}
if ( F_68 ( V_4 ) ) {
V_27 = F_130 ( V_4 , true ) ;
if ( V_27 )
return V_27 ;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ( V_186 & ( 1 << V_41 ) ) == 0 ) {
F_20 ( L_32 , V_41 ) ;
V_4 -> V_137 [ V_41 ] . V_138 . V_139 = false ;
} else {
if ( V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_187 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_187 ( ( void * ) V_4 ) ;
if ( V_27 == - V_188 ) {
V_4 -> V_137 [ V_41 ] . V_138 . V_139 = false ;
} else if ( V_27 ) {
F_20 ( L_33 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
} else {
V_4 -> V_137 [ V_41 ] . V_138 . V_139 = true ;
}
} else {
V_4 -> V_137 [ V_41 ] . V_138 . V_139 = true ;
}
}
}
V_4 -> V_190 &= V_191 ;
V_4 -> V_192 &= V_193 ;
return 0 ;
}
static int F_131 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_194 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_20 ( L_34 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_195 = true ;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_196 ) {
V_27 = F_27 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_35 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_197 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_20 ( L_36 , V_41 , V_27 ) ;
return V_27 ;
}
V_27 = F_55 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_37 , V_27 ) ;
return V_27 ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_198 = true ;
if ( F_68 ( V_4 ) ) {
V_27 = F_132 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_38 , V_27 ) ;
return V_27 ;
}
}
}
}
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_195 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_196 )
continue;
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_197 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_20 ( L_39 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_198 = true ;
}
return 0 ;
}
static int F_133 ( struct V_3 * V_4 )
{
int V_41 = 0 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_199 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_199 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_20 ( L_40 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_200 = true ;
}
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type != V_201 &&
V_4 -> V_137 [ V_41 ] . V_140 -> type != V_202 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_142 ( ( void * ) V_4 ,
V_203 ) ;
if ( V_27 ) {
F_20 ( L_41 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
}
}
return 0 ;
}
static int F_134 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_198 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_204 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_142 ( ( void * ) V_4 ,
V_205 ) ;
if ( V_27 ) {
F_20 ( L_42 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_206 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_135 ( L_43 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_198 = false ;
break;
}
}
for ( V_41 = V_4 -> V_136 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_198 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_196 ) {
F_53 ( V_4 ) ;
F_35 ( V_4 ) ;
}
if ( V_4 -> V_137 [ V_41 ] . V_140 -> type != V_201 &&
V_4 -> V_137 [ V_41 ] . V_140 -> type != V_202 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_142 ( ( void * ) V_4 ,
V_205 ) ;
if ( V_27 ) {
F_20 ( L_42 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
}
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_206 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_135 ( L_43 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_198 = false ;
}
for ( V_41 = V_4 -> V_136 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_195 )
continue;
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_207 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_135 ( L_44 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
}
V_4 -> V_137 [ V_41 ] . V_138 . V_195 = false ;
V_4 -> V_137 [ V_41 ] . V_138 . V_139 = false ;
}
for ( V_41 = V_4 -> V_136 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_200 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_208 )
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_208 ( ( void * ) V_4 ) ;
V_4 -> V_137 [ V_41 ] . V_138 . V_200 = false ;
}
if ( F_68 ( V_4 ) ) {
F_54 ( & V_4 -> V_209 . V_210 , & V_4 -> V_209 . V_211 , NULL ) ;
F_136 ( V_4 , false ) ;
}
return 0 ;
}
int F_137 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
if ( F_68 ( V_4 ) )
F_130 ( V_4 , false ) ;
V_27 = F_111 ( V_4 , V_204 ,
V_205 ) ;
if ( V_27 ) {
F_20 ( L_45 , V_27 ) ;
}
for ( V_41 = V_4 -> V_136 - 1 ; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_41 != V_204 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_142 ( ( void * ) V_4 ,
V_205 ) ;
if ( V_27 ) {
F_20 ( L_42 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
}
}
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_212 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_46 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
}
}
if ( F_68 ( V_4 ) )
F_136 ( V_4 , false ) ;
return 0 ;
}
static int F_138 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_213 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_47 ,
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 , V_27 ) ;
return V_27 ;
}
}
return 0 ;
}
static void F_139 ( struct V_3 * V_4 )
{
if ( F_140 ( V_4 ) )
V_4 -> V_209 . V_214 |= V_215 ;
}
int F_141 ( struct V_3 * V_4 ,
struct V_1 * V_98 ,
struct V_122 * V_17 ,
T_1 V_6 )
{
int V_27 , V_41 ;
bool V_216 = false ;
T_2 V_217 ;
V_4 -> V_218 = false ;
V_4 -> V_2 = & V_17 -> V_2 ;
V_4 -> V_98 = V_98 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_76 = V_6 & V_219 ;
V_4 -> V_220 = V_221 ;
V_4 -> V_59 . V_71 = 512 * 1024 * 1024 ;
V_4 -> V_222 = false ;
V_4 -> V_223 = 0 ;
V_4 -> V_224 . V_225 = NULL ;
V_4 -> V_224 . V_226 = NULL ;
V_4 -> V_227 . V_228 = NULL ;
V_4 -> V_227 . V_229 = 0 ;
V_4 -> V_230 . V_231 = NULL ;
V_4 -> V_232 = F_142 ( V_233 ) ;
V_4 -> V_234 = & F_22 ;
V_4 -> V_235 = & F_24 ;
V_4 -> V_236 = & F_22 ;
V_4 -> V_237 = & F_24 ;
V_4 -> V_238 = & F_22 ;
V_4 -> V_239 = & F_24 ;
V_4 -> V_240 = & F_22 ;
V_4 -> V_241 = & F_24 ;
V_4 -> V_242 = & F_22 ;
V_4 -> V_243 = & F_24 ;
V_4 -> V_244 = & F_22 ;
V_4 -> V_245 = & F_24 ;
V_4 -> V_246 = & F_25 ;
V_4 -> V_247 = & F_26 ;
F_49 ( L_48 ,
V_248 [ V_4 -> V_76 ] , V_17 -> V_249 , V_17 -> V_18 ,
V_17 -> V_250 , V_17 -> V_251 , V_17 -> V_252 ) ;
F_94 ( & V_4 -> V_227 . V_253 ) ;
F_143 ( & V_4 -> V_254 . V_255 . V_253 , 0 ) ;
F_94 ( & V_4 -> V_80 . V_108 ) ;
F_94 ( & V_4 -> V_256 . V_257 ) ;
F_94 ( & V_4 -> V_258 ) ;
F_94 ( & V_4 -> V_259 ) ;
F_94 ( & V_4 -> V_260 ) ;
F_144 ( V_4 -> V_261 ) ;
F_100 ( V_4 ) ;
F_145 ( & V_4 -> V_14 ) ;
F_145 ( & V_4 -> V_262 ) ;
F_145 ( & V_4 -> V_263 ) ;
F_145 ( & V_4 -> V_264 ) ;
F_145 ( & V_4 -> V_265 ) ;
F_145 ( & V_4 -> V_266 ) ;
F_145 ( & V_4 -> V_267 ) ;
F_145 ( & V_4 -> V_268 . V_253 ) ;
F_146 ( & V_4 -> V_269 ) ;
F_94 ( & V_4 -> V_270 ) ;
F_146 ( & V_4 -> V_271 ) ;
F_145 ( & V_4 -> V_272 ) ;
if ( V_4 -> V_76 >= V_179 ) {
V_4 -> V_273 = F_45 ( V_4 -> V_17 , 5 ) ;
V_4 -> V_11 = F_46 ( V_4 -> V_17 , 5 ) ;
} else {
V_4 -> V_273 = F_45 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_11 = F_46 ( V_4 -> V_17 , 2 ) ;
}
V_4 -> V_13 = F_48 ( V_4 -> V_273 , V_4 -> V_11 ) ;
if ( V_4 -> V_13 == NULL ) {
return - V_47 ;
}
F_49 ( L_49 , ( T_1 ) V_4 -> V_273 ) ;
F_49 ( L_50 , ( unsigned ) V_4 -> V_11 ) ;
if ( V_4 -> V_76 >= V_179 )
F_44 ( V_4 ) ;
for ( V_41 = 0 ; V_41 < V_274 ; V_41 ++ ) {
if ( F_147 ( V_4 -> V_17 , V_41 ) & V_275 ) {
V_4 -> V_20 = F_46 ( V_4 -> V_17 , V_41 ) ;
V_4 -> V_21 = F_148 ( V_4 -> V_17 , V_41 , V_4 -> V_20 ) ;
break;
}
}
if ( V_4 -> V_21 == NULL )
F_49 ( L_51 ) ;
V_27 = F_124 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_149 ( V_4 -> V_17 , V_4 , NULL , F_97 ) ;
if ( V_276 == 1 )
V_216 = true ;
if ( F_1 ( V_98 ) )
V_216 = true ;
F_150 ( V_4 -> V_17 , & V_277 , V_216 ) ;
if ( V_216 )
F_151 ( V_4 -> V_2 , & V_4 -> V_278 ) ;
if ( ! F_152 ( V_4 ) ) {
V_27 = - V_46 ;
goto V_279;
}
V_27 = F_91 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_52 ) ;
goto V_279;
}
F_139 ( V_4 ) ;
if ( F_67 ( V_4 ) ) {
if ( ! V_4 -> V_107 ) {
F_75 ( V_4 -> V_2 , L_53 ) ;
V_27 = - V_46 ;
goto V_279;
}
F_49 ( L_54 ) ;
V_27 = F_153 ( V_4 -> V_93 . V_94 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_55 ) ;
goto V_279;
}
} else {
F_49 ( L_56 ) ;
}
V_27 = F_154 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_57 ) ;
goto V_279;
}
F_155 ( V_4 ) ;
V_27 = F_156 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_58 ) ;
goto V_279;
}
F_157 ( V_4 -> V_98 ) ;
V_27 = F_131 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_59 ) ;
F_134 ( V_4 ) ;
goto V_279;
}
V_4 -> V_222 = true ;
if ( V_280 >= 0 )
V_217 = V_280 ;
else
V_217 = 8 ;
V_4 -> V_268 . V_281 = F_102 ( F_158 ( 1u , V_217 ) ) ;
F_159 ( V_4 ) ;
V_27 = F_160 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_60 , V_27 ) ;
goto V_279;
}
V_27 = F_161 ( V_4 ) ;
if ( V_27 )
F_20 ( L_61 , V_27 ) ;
V_27 = F_162 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_62 , V_27 ) ;
}
V_27 = F_163 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_63 , V_27 ) ;
}
V_27 = F_164 ( V_4 ) ;
if ( V_27 ) {
F_20 ( L_64 , V_27 ) ;
return V_27 ;
}
if ( ( V_282 & 1 ) ) {
if ( V_4 -> V_222 )
F_165 ( V_4 ) ;
else
F_49 ( L_65 ) ;
}
if ( ( V_282 & 2 ) ) {
if ( V_4 -> V_222 )
F_166 ( V_4 ) ;
else
F_49 ( L_66 ) ;
}
if ( V_283 ) {
if ( V_4 -> V_222 )
F_167 ( V_4 , V_283 ) ;
else
F_49 ( L_67 ) ;
}
V_27 = F_133 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_68 ) ;
goto V_279;
}
return 0 ;
V_279:
if ( V_216 )
F_168 ( V_4 -> V_2 ) ;
return V_27 ;
}
void F_169 ( struct V_3 * V_4 )
{
int V_27 ;
F_49 ( L_69 ) ;
V_4 -> V_218 = true ;
F_170 ( V_4 -> V_98 ) ;
F_171 ( V_4 ) ;
F_172 ( V_4 ) ;
F_173 ( V_4 ) ;
F_174 ( V_4 ) ;
V_27 = F_134 ( V_4 ) ;
V_4 -> V_222 = false ;
F_175 ( V_4 ) ;
F_89 ( V_4 ) ;
F_90 ( V_4 -> V_107 ) ;
V_4 -> V_107 = NULL ;
F_176 ( V_4 -> V_17 ) ;
if ( V_4 -> V_6 & V_7 )
F_168 ( V_4 -> V_2 ) ;
F_149 ( V_4 -> V_17 , NULL , NULL , NULL ) ;
if ( V_4 -> V_21 )
F_177 ( V_4 -> V_17 , V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
F_51 ( V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
if ( V_4 -> V_76 >= V_179 )
F_50 ( V_4 ) ;
F_178 ( V_4 ) ;
}
int F_109 ( struct V_1 * V_2 , bool V_212 , bool V_284 )
{
struct V_3 * V_4 ;
struct V_285 * V_286 ;
struct V_287 * V_288 ;
int V_27 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_289 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_128 == V_131 )
return 0 ;
F_108 ( V_2 ) ;
F_179 ( V_2 ) ;
F_180 (connector, &dev->mode_config.connector_list, head) {
F_181 ( V_288 , V_290 ) ;
}
F_182 ( V_2 ) ;
F_180 (crtc, &dev->mode_config.crtc_list, head) {
struct V_291 * V_291 = F_183 ( V_286 ) ;
struct V_292 * V_293 = F_184 ( V_286 -> V_294 -> V_295 ) ;
struct V_296 * V_29 ;
if ( V_291 -> V_297 ) {
struct V_296 * V_298 = F_185 ( V_291 -> V_297 ) ;
V_27 = F_29 ( V_298 , false ) ;
if ( V_27 == 0 ) {
F_34 ( V_298 ) ;
F_32 ( V_298 ) ;
}
}
if ( V_293 == NULL || V_293 -> V_299 == NULL ) {
continue;
}
V_29 = F_185 ( V_293 -> V_299 ) ;
if ( ! F_186 ( V_4 , V_29 ) ) {
V_27 = F_29 ( V_29 , false ) ;
if ( V_27 == 0 ) {
F_34 ( V_29 ) ;
F_32 ( V_29 ) ;
}
}
}
F_171 ( V_4 ) ;
F_187 ( V_4 ) ;
V_27 = F_137 ( V_4 ) ;
F_171 ( V_4 ) ;
F_188 ( V_4 ) ;
F_189 ( V_2 -> V_17 ) ;
if ( V_212 ) {
F_190 ( V_2 -> V_17 ) ;
F_191 ( V_2 -> V_17 , V_300 ) ;
} else {
V_27 = F_192 ( V_4 ) ;
if ( V_27 )
F_20 ( L_70 ) ;
}
if ( V_284 ) {
F_193 () ;
F_194 ( V_4 , 1 ) ;
F_195 () ;
}
return 0 ;
}
int F_106 ( struct V_1 * V_2 , bool V_213 , bool V_284 )
{
struct V_287 * V_288 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_285 * V_286 ;
int V_27 ;
if ( V_2 -> V_128 == V_131 )
return 0 ;
if ( V_284 )
F_193 () ;
if ( V_213 ) {
F_191 ( V_2 -> V_17 , V_301 ) ;
F_196 ( V_2 -> V_17 ) ;
V_27 = F_197 ( V_2 -> V_17 ) ;
if ( V_27 ) {
if ( V_284 )
F_195 () ;
return V_27 ;
}
}
F_198 ( V_4 ) ;
if ( F_66 ( V_4 ) ) {
V_27 = F_153 ( V_4 -> V_93 . V_94 ) ;
if ( V_27 )
F_20 ( L_71 ) ;
}
V_27 = F_138 ( V_4 ) ;
if ( V_27 )
F_20 ( L_72 , V_27 ) ;
F_199 ( V_4 ) ;
if ( V_213 ) {
V_27 = F_161 ( V_4 ) ;
if ( V_27 )
F_20 ( L_61 , V_27 ) ;
}
V_27 = F_133 ( V_4 ) ;
if ( V_27 ) {
if ( V_284 )
F_195 () ;
return V_27 ;
}
F_180 (crtc, &dev->mode_config.crtc_list, head) {
struct V_291 * V_291 = F_183 ( V_286 ) ;
if ( V_291 -> V_297 ) {
struct V_296 * V_298 = F_185 ( V_291 -> V_297 ) ;
V_27 = F_29 ( V_298 , false ) ;
if ( V_27 == 0 ) {
V_27 = F_31 ( V_298 ,
V_32 ,
& V_291 -> V_302 ) ;
if ( V_27 != 0 )
F_20 ( L_73 , V_27 ) ;
F_32 ( V_298 ) ;
}
}
}
if ( V_284 ) {
F_200 ( V_2 ) ;
F_179 ( V_2 ) ;
F_180 (connector, &dev->mode_config.connector_list, head) {
F_181 ( V_288 , V_303 ) ;
}
F_182 ( V_2 ) ;
}
F_107 ( V_2 ) ;
#ifdef F_201
V_2 -> V_2 -> V_304 . V_305 ++ ;
#endif
F_202 ( V_2 ) ;
#ifdef F_201
V_2 -> V_2 -> V_304 . V_305 -- ;
#endif
if ( V_284 ) {
F_194 ( V_4 , 0 ) ;
F_195 () ;
}
return 0 ;
}
static bool F_203 ( struct V_3 * V_4 )
{
int V_41 ;
bool V_306 = false ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_307 )
V_4 -> V_137 [ V_41 ] . V_138 . V_308 =
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_307 ( V_4 ) ;
if ( V_4 -> V_137 [ V_41 ] . V_138 . V_308 ) {
F_49 ( L_74 , V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_189 ) ;
V_306 = true ;
}
}
return V_306 ;
}
static int F_204 ( struct V_3 * V_4 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_138 . V_308 &&
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_309 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_309 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static bool F_205 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( ( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_196 ) ||
( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_204 ) ||
( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_310 ) ||
( V_4 -> V_137 [ V_41 ] . V_140 -> type == V_311 ) ) {
if ( V_4 -> V_137 [ V_41 ] . V_138 . V_308 ) {
F_49 ( L_75 ) ;
return true ;
}
}
}
return false ;
}
static int F_206 ( struct V_3 * V_4 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_138 . V_308 &&
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_312 ) {
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_312 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static int F_207 ( struct V_3 * V_4 )
{
int V_41 , V_27 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_136 ; V_41 ++ ) {
if ( ! V_4 -> V_137 [ V_41 ] . V_138 . V_139 )
continue;
if ( V_4 -> V_137 [ V_41 ] . V_138 . V_308 &&
V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_313 )
V_27 = V_4 -> V_137 [ V_41 ] . V_140 -> V_141 -> V_313 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
bool F_208 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 & V_314 )
return false ;
return V_315 > 0 ? true : false ;
}
static int F_209 ( struct V_3 * V_4 ,
struct V_316 * V_317 ,
struct V_296 * V_318 ,
struct V_319 * * V_320 )
{
T_1 V_321 ;
int V_27 ;
if ( ! V_318 -> V_322 )
return 0 ;
V_27 = F_29 ( V_318 , false ) ;
if ( V_27 )
return V_27 ;
V_321 = F_210 ( V_318 -> V_323 . V_324 . V_325 ) ;
if ( V_321 == V_32 ) {
V_27 = F_211 ( V_4 , V_317 , V_318 ,
NULL , V_320 , true ) ;
if ( V_27 ) {
F_20 ( L_76 ) ;
goto V_78;
}
}
V_78:
F_32 ( V_318 ) ;
return V_27 ;
}
int F_212 ( struct V_3 * V_4 )
{
int V_41 , V_27 ;
int V_326 ;
bool V_327 ;
if ( F_68 ( V_4 ) )
return 0 ;
if ( ! F_203 ( V_4 ) ) {
F_49 ( L_77 ) ;
return 0 ;
}
F_213 ( & V_4 -> V_328 ) ;
V_326 = F_214 ( & V_4 -> V_224 . V_329 ) ;
for ( V_41 = 0 ; V_41 < V_233 ; ++ V_41 ) {
struct V_316 * V_317 = V_4 -> V_330 [ V_41 ] ;
if ( ! V_317 )
continue;
F_215 ( V_317 -> V_331 . V_332 ) ;
F_216 ( & V_317 -> V_331 ) ;
}
F_217 ( V_4 ) ;
V_327 = F_205 ( V_4 ) ;
if ( ! V_327 ) {
F_204 ( V_4 ) ;
V_27 = F_206 ( V_4 ) ;
F_207 ( V_4 ) ;
if ( V_27 || F_203 ( V_4 ) ) {
F_49 ( L_78 ) ;
V_327 = true ;
}
}
if ( V_327 ) {
V_27 = F_137 ( V_4 ) ;
V_333:
if ( V_4 -> V_93 . V_161 ) {
struct V_334 V_335 ;
F_218 ( V_4 , & V_335 ) ;
F_114 ( V_4 , V_196 ) ;
}
F_188 ( V_4 ) ;
V_27 = F_192 ( V_4 ) ;
F_198 ( V_4 ) ;
F_153 ( V_4 -> V_93 . V_94 ) ;
if ( ! V_27 ) {
F_64 ( V_4 -> V_2 , L_79 ) ;
V_27 = F_138 ( V_4 ) ;
}
}
if ( ! V_27 ) {
F_219 ( V_4 ) ;
if ( V_327 && F_208 ( V_4 ) ) {
V_27 = F_220 ( V_4 ) ;
if ( V_27 )
F_20 ( L_80 ) ;
}
V_27 = F_161 ( V_4 ) ;
if ( V_27 ) {
F_75 ( V_4 -> V_2 , L_61 , V_27 ) ;
V_27 = F_137 ( V_4 ) ;
V_327 = true ;
goto V_333;
}
if ( V_327 && F_208 ( V_4 ) ) {
struct V_316 * V_317 = V_4 -> V_224 . V_226 ;
struct V_296 * V_318 , * V_38 ;
struct V_319 * V_320 = NULL , * V_336 = NULL ;
F_49 ( L_81 ) ;
F_221 ( & V_4 -> V_270 ) ;
F_222 (bo, tmp, &adev->shadow_list, shadow_list) {
F_209 ( V_4 , V_317 , V_318 , & V_336 ) ;
if ( V_320 ) {
V_27 = F_223 ( V_320 , false ) ;
if ( V_27 ) {
F_224 ( V_27 , L_82 ) ;
break;
}
}
F_225 ( V_320 ) ;
V_320 = V_336 ;
}
F_226 ( & V_4 -> V_270 ) ;
if ( V_320 ) {
V_27 = F_223 ( V_320 , false ) ;
if ( V_27 )
F_224 ( V_27 , L_82 ) ;
}
F_225 ( V_320 ) ;
}
for ( V_41 = 0 ; V_41 < V_233 ; ++ V_41 ) {
struct V_316 * V_317 = V_4 -> V_330 [ V_41 ] ;
if ( ! V_317 )
continue;
F_227 ( & V_317 -> V_331 ) ;
F_228 ( V_317 -> V_331 . V_332 ) ;
}
} else {
F_75 ( V_4 -> V_2 , L_83 , V_27 ) ;
for ( V_41 = 0 ; V_41 < V_233 ; ++ V_41 ) {
if ( V_4 -> V_330 [ V_41 ] ) {
F_228 ( V_4 -> V_330 [ V_41 ] -> V_331 . V_332 ) ;
}
}
}
F_200 ( V_4 -> V_98 ) ;
F_229 ( & V_4 -> V_224 . V_329 , V_326 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_84 ) ;
}
return V_27 ;
}
void F_230 ( struct V_3 * V_4 )
{
T_2 V_337 ;
int V_10 ;
if ( V_338 )
V_4 -> V_80 . V_339 = V_338 ;
if ( V_340 )
V_4 -> V_80 . V_341 = V_340 ;
if ( F_231 ( V_4 -> V_17 -> V_342 ) ) {
if ( V_4 -> V_80 . V_339 == 0 )
V_4 -> V_80 . V_339 = V_343 ;
if ( V_4 -> V_80 . V_341 == 0 )
V_4 -> V_80 . V_341 = V_344 ;
return;
}
if ( V_4 -> V_80 . V_339 == 0 ) {
V_10 = F_232 ( V_4 -> V_98 , & V_337 ) ;
if ( ! V_10 ) {
V_4 -> V_80 . V_339 = ( V_345 |
V_346 |
V_347 ) ;
if ( V_337 & V_348 )
V_4 -> V_80 . V_339 |= V_349 ;
if ( V_337 & V_350 )
V_4 -> V_80 . V_339 |= V_351 ;
if ( V_337 & V_352 )
V_4 -> V_80 . V_339 |= V_353 ;
} else {
V_4 -> V_80 . V_339 = V_343 ;
}
}
if ( V_4 -> V_80 . V_341 == 0 ) {
V_10 = F_233 ( V_4 -> V_98 , & V_337 ) ;
if ( ! V_10 ) {
switch ( V_337 ) {
case 32 :
V_4 -> V_80 . V_341 = ( V_354 |
V_355 |
V_356 |
V_357 |
V_358 |
V_359 |
V_360 ) ;
break;
case 16 :
V_4 -> V_80 . V_341 = ( V_355 |
V_356 |
V_357 |
V_358 |
V_359 |
V_360 ) ;
break;
case 12 :
V_4 -> V_80 . V_341 = ( V_356 |
V_357 |
V_358 |
V_359 |
V_360 ) ;
break;
case 8 :
V_4 -> V_80 . V_341 = ( V_357 |
V_358 |
V_359 |
V_360 ) ;
break;
case 4 :
V_4 -> V_80 . V_341 = ( V_358 |
V_359 |
V_360 ) ;
break;
case 2 :
V_4 -> V_80 . V_341 = ( V_359 |
V_360 ) ;
break;
case 1 :
V_4 -> V_80 . V_341 = V_360 ;
break;
default:
break;
}
} else {
V_4 -> V_80 . V_341 = V_344 ;
}
}
}
int F_234 ( struct V_3 * V_4 ,
const struct V_361 * V_362 ,
unsigned V_363 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_364 ; V_41 ++ ) {
if ( V_4 -> V_365 [ V_41 ] . V_362 == V_362 ) {
return 0 ;
}
}
V_41 = V_4 -> V_364 + 1 ;
if ( V_41 > V_366 ) {
F_20 ( L_85 ) ;
F_20 ( L_86
L_87 ) ;
return - V_46 ;
}
V_4 -> V_365 [ V_4 -> V_364 ] . V_362 = V_362 ;
V_4 -> V_365 [ V_4 -> V_364 ] . V_367 = V_363 ;
V_4 -> V_364 = V_41 ;
#if F_235 ( V_368 )
F_236 ( V_362 , V_363 ,
V_4 -> V_98 -> V_294 -> V_369 ,
V_4 -> V_98 -> V_294 ) ;
#endif
return 0 ;
}
static T_7 F_237 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
bool V_376 , V_377 ;
unsigned V_378 , V_379 , V_380 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
V_376 = ( * V_373 >> 23 ) & 1 ;
if ( * V_373 & ( 1ULL << 62 ) ) {
V_380 = ( * V_373 >> 24 ) & 0x3FF ;
V_379 = ( * V_373 >> 34 ) & 0x3FF ;
V_378 = ( * V_373 >> 44 ) & 0x3FF ;
if ( V_380 == 0x3FF )
V_380 = 0xFFFFFFFF ;
if ( V_379 == 0x3FF )
V_379 = 0xFFFFFFFF ;
if ( V_378 == 0x3FF )
V_378 = 0xFFFFFFFF ;
V_377 = 1 ;
} else {
V_377 = 0 ;
}
* V_373 &= ( 1UL << 22 ) - 1 ;
if ( V_377 ) {
if ( ( V_379 != 0xFFFFFFFF && V_379 >= V_4 -> V_256 . V_381 . V_382 ) ||
( V_380 != 0xFFFFFFFF && V_380 >= V_4 -> V_256 . V_381 . V_383 ) )
return - V_46 ;
F_221 ( & V_4 -> V_259 ) ;
F_239 ( V_4 , V_380 ,
V_379 , V_378 ) ;
}
if ( V_376 )
F_221 ( & V_4 -> V_80 . V_108 ) ;
while ( V_44 ) {
T_1 V_384 ;
if ( * V_373 > V_4 -> V_11 )
goto V_385;
V_384 = F_40 ( * V_373 >> 2 ) ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 ) {
V_375 = V_27 ;
goto V_385;
}
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
V_385:
if ( V_377 ) {
F_239 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_226 ( & V_4 -> V_259 ) ;
}
if ( V_376 )
F_226 ( & V_4 -> V_80 . V_108 ) ;
return V_375 ;
}
static T_7 F_241 ( struct V_370 * V_371 , const char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
bool V_376 , V_377 ;
unsigned V_378 , V_379 , V_380 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
V_376 = ( * V_373 >> 23 ) & 1 ;
if ( * V_373 & ( 1ULL << 62 ) ) {
V_380 = ( * V_373 >> 24 ) & 0x3FF ;
V_379 = ( * V_373 >> 34 ) & 0x3FF ;
V_378 = ( * V_373 >> 44 ) & 0x3FF ;
if ( V_380 == 0x3FF )
V_380 = 0xFFFFFFFF ;
if ( V_379 == 0x3FF )
V_379 = 0xFFFFFFFF ;
if ( V_378 == 0x3FF )
V_378 = 0xFFFFFFFF ;
V_377 = 1 ;
} else {
V_377 = 0 ;
}
* V_373 &= ( 1UL << 22 ) - 1 ;
if ( V_377 ) {
if ( ( V_379 != 0xFFFFFFFF && V_379 >= V_4 -> V_256 . V_381 . V_382 ) ||
( V_380 != 0xFFFFFFFF && V_380 >= V_4 -> V_256 . V_381 . V_383 ) )
return - V_46 ;
F_221 ( & V_4 -> V_259 ) ;
F_239 ( V_4 , V_380 ,
V_379 , V_378 ) ;
}
if ( V_376 )
F_221 ( & V_4 -> V_80 . V_108 ) ;
while ( V_44 ) {
T_1 V_384 ;
if ( * V_373 > V_4 -> V_11 )
return V_375 ;
V_27 = F_242 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
F_41 ( * V_373 >> 2 , V_384 ) ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
if ( V_377 ) {
F_239 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_226 ( & V_4 -> V_259 ) ;
}
if ( V_376 )
F_226 ( & V_4 -> V_80 . V_108 ) ;
return V_375 ;
}
static T_7 F_243 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_384 ;
V_384 = F_244 ( * V_373 >> 2 ) ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_245 ( struct V_370 * V_371 , const char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_384 ;
V_27 = F_242 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
F_246 ( * V_373 >> 2 , V_384 ) ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_247 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_384 ;
V_384 = F_248 ( * V_373 >> 2 ) ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_249 ( struct V_370 * V_371 , const char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_384 ;
V_27 = F_242 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
F_250 ( * V_373 >> 2 , V_384 ) ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_251 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_384 ;
V_384 = F_252 ( * V_373 ) ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_253 ( struct V_370 * V_371 , const char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
while ( V_44 ) {
T_1 V_384 ;
V_27 = F_242 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
F_254 ( * V_373 , V_384 ) ;
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_255 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
T_7 V_375 = 0 ;
int V_27 ;
T_1 * V_381 , V_386 = 0 ;
if ( V_44 & 0x3 || * V_373 & 0x3 )
return - V_46 ;
V_381 = F_256 ( 256 , sizeof( * V_381 ) , V_86 ) ;
if ( ! V_381 )
return - V_47 ;
V_381 [ V_386 ++ ] = 3 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_383 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_387 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_388 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_382 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_389 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_390 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_391 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_392 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_393 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_394 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_395 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_396 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_397 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_398 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_399 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_400 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_401 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_402 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_403 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_404 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_405 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_406 ;
V_381 [ V_386 ++ ] = V_4 -> V_256 . V_381 . V_407 ;
V_381 [ V_386 ++ ] = V_4 -> V_408 ;
V_381 [ V_386 ++ ] = V_4 -> V_192 ;
V_381 [ V_386 ++ ] = V_4 -> V_190 ;
V_381 [ V_386 ++ ] = V_4 -> V_170 ;
V_381 [ V_386 ++ ] = V_4 -> V_409 ;
V_381 [ V_386 ++ ] = V_4 -> V_17 -> V_18 ;
V_381 [ V_386 ++ ] = V_4 -> V_17 -> V_252 ;
V_381 [ V_386 ++ ] = V_4 -> V_17 -> V_251 ;
V_381 [ V_386 ++ ] = V_4 -> V_17 -> V_250 ;
while ( V_44 && ( * V_373 < V_386 * 4 ) ) {
T_1 V_384 ;
V_384 = V_381 [ * V_373 >> 2 ] ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 ) {
F_90 ( V_381 ) ;
return V_27 ;
}
V_375 += 4 ;
V_372 += 4 ;
* V_373 += 4 ;
V_44 -= 4 ;
}
F_90 ( V_381 ) ;
return V_375 ;
}
static T_7 F_257 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = F_238 ( V_371 ) -> V_374 ;
int V_410 , V_27 ;
T_10 V_384 ;
if ( V_44 != 4 || * V_373 & 0x3 )
return - V_46 ;
V_410 = * V_373 >> 2 ;
if ( V_4 -> V_411 . V_412 && V_4 -> V_411 . V_412 -> V_413 )
V_27 = V_4 -> V_411 . V_412 -> V_413 ( V_4 -> V_411 . V_414 , V_410 , & V_384 ) ;
else
return - V_46 ;
if ( ! V_27 )
V_27 = F_240 ( V_384 , ( T_10 * ) V_372 ) ;
return ! V_27 ? 4 : V_27 ;
}
static T_7 F_258 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = V_371 -> V_415 -> V_374 ;
int V_27 , V_416 ;
T_7 V_375 = 0 ;
T_1 V_57 , V_417 , V_418 , V_419 , V_420 , V_421 , V_82 [ 32 ] ;
if ( V_44 & 3 || * V_373 & 3 )
return - V_46 ;
V_57 = ( * V_373 & 0x7F ) ;
V_417 = ( ( * V_373 >> 7 ) & 0xFF ) ;
V_418 = ( ( * V_373 >> 15 ) & 0xFF ) ;
V_419 = ( ( * V_373 >> 23 ) & 0xFF ) ;
V_420 = ( ( * V_373 >> 31 ) & 0xFF ) ;
V_421 = ( ( * V_373 >> 37 ) & 0xFF ) ;
F_221 ( & V_4 -> V_259 ) ;
F_239 ( V_4 , V_417 , V_418 , V_419 ) ;
V_416 = 0 ;
if ( V_4 -> V_256 . V_141 -> V_422 )
V_4 -> V_256 . V_141 -> V_422 ( V_4 , V_421 , V_420 , V_82 , & V_416 ) ;
F_239 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_226 ( & V_4 -> V_259 ) ;
if ( ! V_416 )
return - V_46 ;
while ( V_44 && ( V_57 < V_416 * 4 ) ) {
T_1 V_384 ;
V_384 = V_82 [ V_57 >> 2 ] ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 )
return V_27 ;
V_375 += 4 ;
V_372 += 4 ;
V_57 += 4 ;
V_44 -= 4 ;
}
return V_375 ;
}
static T_7 F_259 ( struct V_370 * V_371 , char T_8 * V_372 ,
T_4 V_44 , T_9 * V_373 )
{
struct V_3 * V_4 = V_371 -> V_415 -> V_374 ;
int V_27 ;
T_7 V_375 = 0 ;
T_1 V_57 , V_417 , V_418 , V_419 , V_420 , V_421 , V_332 , V_423 , * V_82 ;
if ( V_44 & 3 || * V_373 & 3 )
return - V_46 ;
V_57 = ( * V_373 & 0xFFF ) ;
V_417 = ( ( * V_373 >> 12 ) & 0xFF ) ;
V_418 = ( ( * V_373 >> 20 ) & 0xFF ) ;
V_419 = ( ( * V_373 >> 28 ) & 0xFF ) ;
V_420 = ( ( * V_373 >> 36 ) & 0xFF ) ;
V_421 = ( ( * V_373 >> 44 ) & 0xFF ) ;
V_332 = ( ( * V_373 >> 52 ) & 0xFF ) ;
V_423 = ( ( * V_373 >> 60 ) & 1 ) ;
V_82 = F_256 ( 1024 , sizeof( * V_82 ) , V_86 ) ;
if ( ! V_82 )
return - V_47 ;
F_221 ( & V_4 -> V_259 ) ;
F_239 ( V_4 , V_417 , V_418 , V_419 ) ;
if ( V_423 == 0 ) {
if ( V_4 -> V_256 . V_141 -> V_424 )
V_4 -> V_256 . V_141 -> V_424 ( V_4 , V_421 , V_420 , V_332 , V_57 , V_44 >> 2 , V_82 ) ;
} else {
if ( V_4 -> V_256 . V_141 -> V_425 )
V_4 -> V_256 . V_141 -> V_425 ( V_4 , V_421 , V_420 , V_57 , V_44 >> 2 , V_82 ) ;
}
F_239 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_226 ( & V_4 -> V_259 ) ;
while ( V_44 ) {
T_1 V_384 ;
V_384 = V_82 [ V_57 ++ ] ;
V_27 = F_240 ( V_384 , ( T_1 * ) V_372 ) ;
if ( V_27 ) {
V_375 = V_27 ;
goto V_78;
}
V_375 += 4 ;
V_372 += 4 ;
V_44 -= 4 ;
}
V_78:
F_90 ( V_82 ) ;
return V_375 ;
}
static int F_163 ( struct V_3 * V_4 )
{
struct V_426 * V_150 = V_4 -> V_98 -> V_294 ;
struct V_427 * V_428 , * V_429 = V_150 -> V_369 ;
unsigned V_41 , V_430 ;
for ( V_41 = 0 ; V_41 < F_260 ( V_431 ) ; V_41 ++ ) {
V_428 = F_261 ( V_432 [ V_41 ] ,
V_433 | V_434 , V_429 ,
V_4 , V_431 [ V_41 ] ) ;
if ( F_262 ( V_428 ) ) {
for ( V_430 = 0 ; V_430 < V_41 ; V_430 ++ ) {
F_263 ( V_4 -> V_431 [ V_41 ] ) ;
V_4 -> V_431 [ V_41 ] = NULL ;
}
return F_264 ( V_428 ) ;
}
if ( ! V_41 )
F_265 ( V_428 -> V_435 , V_4 -> V_11 ) ;
V_4 -> V_431 [ V_41 ] = V_428 ;
}
return 0 ;
}
static void F_178 ( struct V_3 * V_4 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < F_260 ( V_431 ) ; V_41 ++ ) {
if ( V_4 -> V_431 [ V_41 ] ) {
F_263 ( V_4 -> V_431 [ V_41 ] ) ;
V_4 -> V_431 [ V_41 ] = NULL ;
}
}
}
int F_266 ( struct V_426 * V_150 )
{
return 0 ;
}
static int F_163 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_178 ( struct V_3 * V_4 ) { }
