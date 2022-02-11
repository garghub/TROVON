bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & V_7 )
return true ;
return false ;
}
T_1 F_2 ( struct V_3 * V_4 , T_1 V_8 ,
T_1 V_9 )
{
T_1 V_10 ;
if ( ! ( V_9 & V_11 ) && F_3 ( V_4 ) ) {
F_4 ( F_5 () ) ;
return F_6 ( V_4 , V_8 ) ;
}
if ( ( V_8 * 4 ) < V_4 -> V_12 && ! ( V_9 & V_13 ) )
V_10 = F_7 ( ( ( void V_14 * ) V_4 -> V_15 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_8 ( & V_4 -> V_16 , V_6 ) ;
F_9 ( ( V_8 * 4 ) , ( ( void V_14 * ) V_4 -> V_15 ) + ( V_17 * 4 ) ) ;
V_10 = F_7 ( ( ( void V_14 * ) V_4 -> V_15 ) + ( V_18 * 4 ) ) ;
F_10 ( & V_4 -> V_16 , V_6 ) ;
}
F_11 ( V_4 -> V_19 -> V_20 , V_8 , V_10 ) ;
return V_10 ;
}
void F_12 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_21 ,
T_1 V_9 )
{
F_13 ( V_4 -> V_19 -> V_20 , V_8 , V_21 ) ;
if ( V_4 -> V_22 >= V_23 && V_8 == 0 ) {
V_4 -> V_24 = V_21 ;
}
if ( ! ( V_9 & V_11 ) && F_3 ( V_4 ) ) {
F_4 ( F_5 () ) ;
return F_14 ( V_4 , V_8 , V_21 ) ;
}
if ( ( V_8 * 4 ) < V_4 -> V_12 && ! ( V_9 & V_13 ) )
F_9 ( V_21 , ( ( void V_14 * ) V_4 -> V_15 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_8 ( & V_4 -> V_16 , V_6 ) ;
F_9 ( ( V_8 * 4 ) , ( ( void V_14 * ) V_4 -> V_15 ) + ( V_17 * 4 ) ) ;
F_9 ( V_21 , ( ( void V_14 * ) V_4 -> V_15 ) + ( V_18 * 4 ) ) ;
F_10 ( & V_4 -> V_16 , V_6 ) ;
}
if ( V_4 -> V_22 >= V_23 && V_8 == 1 && V_4 -> V_24 == 0x5702C ) {
F_15 ( 500 ) ;
}
}
T_2 F_16 ( struct V_3 * V_4 , T_2 V_8 )
{
if ( ( V_8 * 4 ) < V_4 -> V_25 )
return F_17 ( V_4 -> V_26 + ( V_8 * 4 ) ) ;
else {
F_18 ( ( V_8 * 4 ) , V_4 -> V_26 + ( V_17 * 4 ) ) ;
return F_17 ( V_4 -> V_26 + ( V_18 * 4 ) ) ;
}
}
void F_19 ( struct V_3 * V_4 , T_2 V_8 , T_2 V_21 )
{
if ( V_4 -> V_22 >= V_23 && V_8 == 0 ) {
V_4 -> V_24 = V_21 ;
}
if ( ( V_8 * 4 ) < V_4 -> V_25 )
F_18 ( V_21 , V_4 -> V_26 + ( V_8 * 4 ) ) ;
else {
F_18 ( ( V_8 * 4 ) , V_4 -> V_26 + ( V_17 * 4 ) ) ;
F_18 ( V_21 , V_4 -> V_26 + ( V_18 * 4 ) ) ;
}
if ( V_4 -> V_22 >= V_23 && V_8 == 1 && V_4 -> V_24 == 0x5702C ) {
F_15 ( 500 ) ;
}
}
T_2 F_20 ( struct V_3 * V_4 , T_2 V_27 )
{
if ( V_27 < V_4 -> V_28 . V_29 ) {
return F_7 ( V_4 -> V_28 . V_30 + V_27 ) ;
} else {
F_21 ( L_1 , V_27 ) ;
return 0 ;
}
}
void F_22 ( struct V_3 * V_4 , T_2 V_27 , T_2 V_21 )
{
if ( V_27 < V_4 -> V_28 . V_29 ) {
F_9 ( V_21 , V_4 -> V_28 . V_30 + V_27 ) ;
} else {
F_21 ( L_2 , V_27 ) ;
}
}
T_3 F_23 ( struct V_3 * V_4 , T_2 V_27 )
{
if ( V_27 < V_4 -> V_28 . V_29 ) {
return F_24 ( ( V_31 * ) ( V_4 -> V_28 . V_30 + V_27 ) ) ;
} else {
F_21 ( L_1 , V_27 ) ;
return 0 ;
}
}
void F_25 ( struct V_3 * V_4 , T_2 V_27 , T_3 V_21 )
{
if ( V_27 < V_4 -> V_28 . V_29 ) {
F_26 ( ( V_31 * ) ( V_4 -> V_28 . V_30 + V_27 ) , V_21 ) ;
} else {
F_21 ( L_2 , V_27 ) ;
}
}
static T_1 F_27 ( struct V_3 * V_4 , T_1 V_8 )
{
F_21 ( L_3 , V_8 ) ;
F_28 () ;
return 0 ;
}
static void F_29 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_21 )
{
F_21 ( L_4 ,
V_8 , V_21 ) ;
F_28 () ;
}
static T_1 F_30 ( struct V_3 * V_4 ,
T_1 V_32 , T_1 V_8 )
{
F_21 ( L_5 ,
V_8 , V_32 ) ;
F_28 () ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 ,
T_1 V_32 ,
T_1 V_8 , T_1 V_21 )
{
F_21 ( L_6 ,
V_8 , V_32 , V_21 ) ;
F_28 () ;
}
static int F_32 ( struct V_3 * V_4 )
{
return F_33 ( V_4 , V_33 ,
V_34 , V_35 ,
& V_4 -> V_36 . V_37 ,
& V_4 -> V_36 . V_38 ,
( void * * ) & V_4 -> V_36 . V_30 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
F_35 ( & V_4 -> V_36 . V_37 , NULL , NULL ) ;
}
void F_36 ( struct V_3 * V_4 ,
const T_2 * V_39 ,
const T_2 V_40 )
{
T_2 V_41 , V_8 , V_42 , V_43 ;
int V_44 ;
if ( V_40 % 3 )
return;
for ( V_44 = 0 ; V_44 < V_40 ; V_44 += 3 ) {
V_8 = V_39 [ V_44 + 0 ] ;
V_42 = V_39 [ V_44 + 1 ] ;
V_43 = V_39 [ V_44 + 2 ] ;
if ( V_42 == 0xffffffff ) {
V_41 = V_43 ;
} else {
V_41 = F_37 ( V_8 ) ;
V_41 &= ~ V_42 ;
V_41 |= V_43 ;
}
F_38 ( V_8 , V_41 ) ;
}
}
void F_39 ( struct V_3 * V_4 )
{
F_40 ( V_4 -> V_19 , 0x7c , V_45 ) ;
}
static int F_41 ( struct V_3 * V_4 )
{
V_4 -> V_28 . V_46 = F_42 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_28 . V_47 = F_43 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_28 . V_29 = F_44 ( T_2 , V_4 -> V_28 . V_47 / sizeof( T_2 ) ,
V_48 + 1 ) ;
if ( V_4 -> V_28 . V_29 == 0 )
return - V_49 ;
V_4 -> V_28 . V_30 = F_45 ( V_4 -> V_28 . V_46 ,
V_4 -> V_28 . V_29 *
sizeof( T_2 ) ) ;
if ( V_4 -> V_28 . V_30 == NULL )
return - V_50 ;
return 0 ;
}
static void F_46 ( struct V_3 * V_4 )
{
F_47 ( V_4 -> V_28 . V_30 ) ;
V_4 -> V_28 . V_30 = NULL ;
}
void F_48 ( struct V_3 * V_4 ,
T_4 * V_51 ,
T_5 * V_52 ,
T_5 * V_53 )
{
if ( V_4 -> V_28 . V_47 > V_4 -> V_28 . V_29 * sizeof( T_2 ) ) {
* V_51 = V_4 -> V_28 . V_46 ;
* V_52 = V_4 -> V_28 . V_47 ;
* V_53 = V_4 -> V_28 . V_29 * sizeof( T_2 ) ;
} else {
* V_51 = 0 ;
* V_52 = 0 ;
* V_53 = 0 ;
}
}
static void F_49 ( struct V_3 * V_4 )
{
if ( V_4 -> V_54 . V_55 ) {
F_35 ( & V_4 -> V_54 . V_55 ,
& V_4 -> V_54 . V_38 ,
( void * * ) & V_4 -> V_54 . V_54 ) ;
V_4 -> V_54 . V_55 = NULL ;
}
}
static int F_50 ( struct V_3 * V_4 )
{
int V_56 ;
if ( V_4 -> V_54 . V_55 == NULL ) {
V_56 = F_33 ( V_4 , V_57 * sizeof( T_1 ) * 8 ,
V_34 , V_58 ,
& V_4 -> V_54 . V_55 , & V_4 -> V_54 . V_38 ,
( void * * ) & V_4 -> V_54 . V_54 ) ;
if ( V_56 ) {
F_51 ( V_4 -> V_2 , L_7 , V_56 ) ;
return V_56 ;
}
V_4 -> V_54 . V_59 = V_57 ;
memset ( & V_4 -> V_54 . V_60 , 0 , sizeof( V_4 -> V_54 . V_60 ) ) ;
memset ( ( char * ) V_4 -> V_54 . V_54 , 0 , V_57 * sizeof( T_1 ) ) ;
}
return 0 ;
}
int F_52 ( struct V_3 * V_4 , T_2 * V_54 )
{
unsigned long V_61 = F_53 ( V_4 -> V_54 . V_60 , V_4 -> V_54 . V_59 ) ;
if ( V_61 < V_4 -> V_54 . V_59 ) {
F_54 ( V_61 , V_4 -> V_54 . V_60 ) ;
* V_54 = V_61 * 8 ;
return 0 ;
} else {
return - V_49 ;
}
}
void F_55 ( struct V_3 * V_4 , T_2 V_54 )
{
if ( V_54 < V_4 -> V_54 . V_59 )
F_56 ( V_54 , V_4 -> V_54 . V_60 ) ;
}
void F_57 ( struct V_3 * V_4 , struct V_62 * V_63 , T_3 V_46 )
{
T_6 V_64 = ( T_6 ) V_65 << 20 ;
V_63 -> V_66 = V_46 ;
if ( V_63 -> V_67 > ( V_4 -> V_63 . V_68 - V_46 + 1 ) ) {
F_51 ( V_4 -> V_2 , L_8 ) ;
V_63 -> V_69 = V_63 -> V_70 ;
V_63 -> V_67 = V_63 -> V_70 ;
}
V_63 -> V_71 = V_63 -> V_66 + V_63 -> V_67 - 1 ;
if ( V_64 && V_64 < V_63 -> V_69 )
V_63 -> V_69 = V_64 ;
F_58 ( V_4 -> V_2 , L_9 ,
V_63 -> V_67 >> 20 , V_63 -> V_66 ,
V_63 -> V_71 , V_63 -> V_69 >> 20 ) ;
}
void F_59 ( struct V_3 * V_4 , struct V_62 * V_63 )
{
T_3 V_72 , V_73 ;
V_72 = V_4 -> V_63 . V_68 - V_63 -> V_71 ;
V_73 = V_63 -> V_66 ;
if ( V_73 > V_72 ) {
if ( V_63 -> V_74 > V_73 ) {
F_51 ( V_4 -> V_2 , L_10 ) ;
V_63 -> V_74 = V_73 ;
}
V_63 -> V_75 = 0 ;
} else {
if ( V_63 -> V_74 > V_72 ) {
F_51 ( V_4 -> V_2 , L_10 ) ;
V_63 -> V_74 = V_72 ;
}
V_63 -> V_75 = V_63 -> V_71 + 1 ;
}
V_63 -> V_76 = V_63 -> V_75 + V_63 -> V_74 - 1 ;
F_58 ( V_4 -> V_2 , L_11 ,
V_63 -> V_74 >> 20 , V_63 -> V_75 , V_63 -> V_76 ) ;
}
bool F_60 ( struct V_3 * V_4 )
{
T_1 V_8 ;
if ( V_4 -> V_77 ) {
V_4 -> V_77 = false ;
return true ;
}
if ( V_4 -> V_22 >= V_78 )
return F_61 ( V_4 ) ;
V_8 = F_62 ( V_4 ) ;
if ( ( V_8 != 0 ) && ( V_8 != 0xffffffff ) )
return false ;
return true ;
}
static bool F_63 ( struct V_3 * V_4 )
{
if ( F_64 ( V_4 ) )
return false ;
if ( F_65 ( V_4 ) ) {
if ( V_4 -> V_22 == V_79 ) {
int V_80 ;
T_1 V_81 ;
V_80 = F_66 ( & V_4 -> V_82 . V_83 , L_12 , V_4 -> V_2 ) ;
if ( V_80 )
return true ;
V_81 = * ( ( T_1 * ) V_4 -> V_82 . V_83 -> V_84 + 69 ) ;
if ( V_81 < 0x00160e00 )
return true ;
}
}
return F_60 ( V_4 ) ;
}
int F_67 ( struct V_3 * V_4 )
{
if ( V_4 -> V_85 . V_86 )
return 0 ;
V_4 -> V_85 . V_86 = F_68 ( V_87 | V_88 | V_89 ) ;
if ( V_4 -> V_85 . V_86 == NULL )
return - V_50 ;
V_4 -> V_85 . V_90 = F_69 ( V_4 -> V_19 , V_4 -> V_85 . V_86 ,
0 , V_34 , V_91 ) ;
if ( F_70 ( V_4 -> V_19 , V_4 -> V_85 . V_90 ) ) {
F_71 ( & V_4 -> V_19 -> V_2 , L_13 ) ;
F_72 ( V_4 -> V_85 . V_86 ) ;
V_4 -> V_85 . V_86 = NULL ;
return - V_50 ;
}
return 0 ;
}
void F_73 ( struct V_3 * V_4 )
{
if ( V_4 -> V_85 . V_86 == NULL )
return;
F_74 ( V_4 -> V_19 , V_4 -> V_85 . V_90 ,
V_34 , V_91 ) ;
F_72 ( V_4 -> V_85 . V_86 ) ;
V_4 -> V_85 . V_86 = NULL ;
}
static T_1 F_75 ( struct V_92 * V_93 , T_1 V_8 )
{
return 0 ;
}
static void F_76 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
}
static T_1 F_77 ( struct V_92 * V_93 , T_1 V_8 )
{
return 0 ;
}
static void F_78 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
}
static void F_79 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
F_38 ( V_8 , V_94 ) ;
}
static T_1 F_80 ( struct V_92 * V_93 , T_1 V_8 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
T_1 V_56 ;
V_56 = F_37 ( V_8 ) ;
return V_56 ;
}
static void F_81 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
F_82 ( V_8 , V_94 ) ;
}
static T_1 F_83 ( struct V_92 * V_93 , T_1 V_8 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
T_1 V_56 ;
V_56 = F_84 ( V_8 ) ;
return V_56 ;
}
static void F_85 ( struct V_3 * V_4 )
{
if ( V_4 -> V_95 . V_96 ) {
F_86 ( V_4 -> V_95 . V_96 -> V_97 ) ;
F_86 ( V_4 -> V_95 . V_96 -> V_98 ) ;
}
F_86 ( V_4 -> V_95 . V_96 ) ;
V_4 -> V_95 . V_96 = NULL ;
F_86 ( V_4 -> V_95 . V_99 ) ;
V_4 -> V_95 . V_99 = NULL ;
}
static int F_87 ( struct V_3 * V_4 )
{
struct V_92 * V_99 =
F_88 ( sizeof( struct V_92 ) , V_88 ) ;
if ( ! V_99 )
return - V_50 ;
V_4 -> V_95 . V_99 = V_99 ;
V_99 -> V_2 = V_4 -> V_100 ;
V_99 -> V_101 = F_80 ;
V_99 -> V_102 = F_79 ;
if ( V_4 -> V_26 ) {
V_99 -> V_103 = F_83 ;
V_99 -> V_104 = F_81 ;
} else {
F_89 ( L_14 ) ;
V_99 -> V_103 = F_80 ;
V_99 -> V_104 = F_79 ;
}
V_99 -> V_105 = F_77 ;
V_99 -> V_106 = F_78 ;
V_99 -> V_107 = F_75 ;
V_99 -> V_108 = F_76 ;
V_4 -> V_95 . V_96 = F_90 ( V_99 , V_4 -> V_109 ) ;
if ( ! V_4 -> V_95 . V_96 ) {
F_85 ( V_4 ) ;
return - V_50 ;
}
F_91 ( & V_4 -> V_95 . V_96 -> V_110 ) ;
if ( V_4 -> V_111 ) {
F_92 ( V_4 ) ;
F_93 ( V_4 ) ;
} else {
F_94 ( V_4 ) ;
F_95 ( V_4 ) ;
}
return 0 ;
}
static unsigned int F_96 ( void * V_112 , bool V_113 )
{
struct V_3 * V_4 = V_112 ;
F_97 ( V_4 , V_113 ) ;
if ( V_113 )
return V_114 | V_115 |
V_116 | V_117 ;
else
return V_116 | V_117 ;
}
static void F_98 ( struct V_3 * V_4 )
{
if ( V_118 == - 1 )
return;
if ( V_118 < 9 ) {
F_51 ( V_4 -> V_2 , L_15 ,
V_118 ) ;
goto V_119;
}
if ( V_118 > 24 ||
( V_120 * 1024 ) < ( 1ull << V_118 ) ) {
F_51 ( V_4 -> V_2 , L_16 ,
V_118 ) ;
goto V_119;
}
return;
V_119:
V_118 = - 1 ;
}
static void F_99 ( struct V_3 * V_4 )
{
if ( V_120 == - 1 )
return;
if ( ! F_100 ( V_120 ) ) {
F_51 ( V_4 -> V_2 , L_17 ,
V_120 ) ;
goto V_119;
}
if ( V_120 < 1 ) {
F_51 ( V_4 -> V_2 , L_18 ,
V_120 ) ;
goto V_119;
}
if ( V_120 > 1024 ) {
F_51 ( V_4 -> V_2 , L_19 ,
V_120 ) ;
goto V_119;
}
return;
V_119:
V_120 = - 1 ;
}
static void F_101 ( struct V_3 * V_4 )
{
if ( V_121 < 4 ) {
F_51 ( V_4 -> V_2 , L_20 ,
V_121 ) ;
V_121 = 4 ;
} else if ( ! F_100 ( V_121 ) ) {
F_51 ( V_4 -> V_2 , L_21 ,
V_121 ) ;
V_121 = F_102 ( V_121 ) ;
}
if ( V_122 != - 1 && V_122 < 32 ) {
F_51 ( V_4 -> V_2 , L_22 ,
V_122 ) ;
V_122 = - 1 ;
}
if ( V_123 != - 1 && V_123 < 32 ) {
F_51 ( V_4 -> V_2 , L_23 ,
V_123 ) ;
V_123 = - 1 ;
}
if ( V_124 != - 1 &&
( V_124 > 9 || V_124 < 4 ) ) {
F_51 ( V_4 -> V_2 , L_24 ) ;
V_124 = - 1 ;
}
F_99 ( V_4 ) ;
F_98 ( V_4 ) ;
if ( V_125 != - 1 && ( V_125 < 16 ||
! F_100 ( V_125 ) ) ) {
F_51 ( V_4 -> V_2 , L_25 ,
V_125 ) ;
V_125 = 1024 ;
}
}
static void F_103 ( struct V_126 * V_19 , enum V_127 V_113 )
{
struct V_1 * V_2 = F_104 ( V_19 ) ;
if ( F_1 ( V_2 ) && V_113 == V_128 )
return;
if ( V_113 == V_129 ) {
F_105 ( L_26 ) ;
V_2 -> V_130 = V_131 ;
F_106 ( V_2 , true , true ) ;
V_2 -> V_130 = V_132 ;
F_107 ( V_2 ) ;
} else {
F_105 ( L_27 ) ;
F_108 ( V_2 ) ;
V_2 -> V_130 = V_131 ;
F_109 ( V_2 , true , true ) ;
V_2 -> V_130 = V_133 ;
}
}
static bool F_110 ( struct V_126 * V_19 )
{
struct V_1 * V_2 = F_104 ( V_19 ) ;
return V_2 -> V_134 == 0 ;
}
int F_111 ( struct V_3 * V_4 ,
enum V_135 V_136 ,
enum V_137 V_113 )
{
int V_44 , V_56 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_136 )
continue;
if ( ! V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 )
continue;
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 (
( void * ) V_4 , V_113 ) ;
if ( V_56 )
F_21 ( L_28 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
return V_56 ;
}
int F_112 ( struct V_3 * V_4 ,
enum V_135 V_136 ,
enum V_146 V_113 )
{
int V_44 , V_56 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_136 )
continue;
if ( ! V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_147 )
continue;
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_147 (
( void * ) V_4 , V_113 ) ;
if ( V_56 )
F_21 ( L_29 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
return V_56 ;
}
void F_113 ( struct V_3 * V_4 , T_2 * V_6 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_148 )
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_148 ( ( void * ) V_4 , V_6 ) ;
}
}
int F_114 ( struct V_3 * V_4 ,
enum V_135 V_136 )
{
int V_44 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_136 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_149 ( ( void * ) V_4 ) ;
if ( V_56 )
return V_56 ;
break;
}
}
return 0 ;
}
bool F_115 ( struct V_3 * V_4 ,
enum V_135 V_136 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_136 )
return V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_150 ( ( void * ) V_4 ) ;
}
return true ;
}
struct V_151 * F_116 ( struct V_3 * V_4 ,
enum V_135 type )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ )
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == type )
return & V_4 -> V_139 [ V_44 ] ;
return NULL ;
}
int F_117 ( struct V_3 * V_4 ,
enum V_135 type ,
T_2 V_152 , T_2 V_153 )
{
struct V_151 * V_154 = F_116 ( V_4 , type ) ;
if ( V_154 && ( ( V_154 -> V_142 -> V_152 > V_152 ) ||
( ( V_154 -> V_142 -> V_152 == V_152 ) &&
( V_154 -> V_142 -> V_153 >= V_153 ) ) ) )
return 0 ;
return 1 ;
}
int F_118 ( struct V_3 * V_4 ,
const struct V_155 * V_156 )
{
if ( ! V_156 )
return - V_49 ;
F_119 ( L_30 , V_4 -> V_138 ,
V_156 -> V_143 -> V_145 ) ;
V_4 -> V_139 [ V_4 -> V_138 ++ ] . V_142 = V_156 ;
return 0 ;
}
static void F_120 ( struct V_3 * V_4 )
{
V_4 -> V_157 = false ;
if ( V_158 ) {
struct V_1 * V_100 = V_4 -> V_100 ;
const char * V_159 = F_121 ( V_100 -> V_19 ) ;
char * V_160 , * V_161 , * V_162 , * V_163 ;
V_160 = F_122 ( V_158 , V_88 ) ;
V_161 = V_160 ;
while ( ( V_162 = F_123 ( & V_161 , L_31 ) ) ) {
V_163 = F_123 ( & V_162 , L_32 ) ;
if ( ! strcmp ( L_33 , V_163 )
|| ! strcmp ( V_159 , V_163 ) ) {
long V_164 ;
int V_165 = - 1 ;
V_4 -> V_157 = true ;
if ( V_162 )
V_165 = F_124 ( V_162 , 10 ,
& V_164 ) ;
if ( ! V_165 ) {
if ( V_164 < 1 )
V_164 = 1 ;
if ( V_164 > 6 )
V_164 = 6 ;
V_4 -> V_95 . V_164 = V_164 ;
} else {
V_4 -> V_95 . V_164 = 1 ;
}
break;
}
}
F_89 ( L_34 ,
V_158 , V_159 ,
V_4 -> V_157 , V_4 -> V_95 . V_164 ) ;
F_86 ( V_160 ) ;
}
}
static int F_125 ( struct V_3 * V_4 )
{
const char * V_166 ;
char V_167 [ 30 ] ;
int V_80 ;
const struct V_168 * V_169 ;
V_4 -> V_170 . V_171 = NULL ;
switch ( V_4 -> V_22 ) {
case V_172 :
case V_173 :
case V_79 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
#ifdef F_126
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
#endif
#ifdef F_127
case V_78 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
#endif
default:
return 0 ;
case V_23 :
V_166 = L_35 ;
break;
case V_188 :
V_166 = L_36 ;
break;
}
snprintf ( V_167 , sizeof( V_167 ) , L_37 , V_166 ) ;
V_80 = F_66 ( & V_4 -> V_170 . V_171 , V_167 , V_4 -> V_2 ) ;
if ( V_80 ) {
F_71 ( V_4 -> V_2 ,
L_38 ,
V_167 ) ;
goto V_189;
}
V_80 = F_128 ( V_4 -> V_170 . V_171 ) ;
if ( V_80 ) {
F_71 ( V_4 -> V_2 ,
L_39 ,
V_167 ) ;
goto V_189;
}
V_169 = ( const struct V_168 * ) V_4 -> V_170 . V_171 -> V_84 ;
F_129 ( & V_169 -> V_190 ) ;
switch ( V_169 -> V_191 ) {
case 1 :
{
const struct V_192 * V_171 =
( const struct V_192 * ) ( V_4 -> V_170 . V_171 -> V_84 +
F_130 ( V_169 -> V_190 . V_193 ) ) ;
V_4 -> V_194 . V_195 . V_196 = F_130 ( V_171 -> V_197 ) ;
V_4 -> V_194 . V_195 . V_198 = F_130 ( V_171 -> V_199 ) ;
V_4 -> V_194 . V_195 . V_200 = F_130 ( V_171 -> V_201 ) ;
V_4 -> V_194 . V_195 . V_202 = F_130 ( V_171 -> V_203 ) ;
V_4 -> V_194 . V_195 . V_204 =
F_130 ( V_171 -> V_205 ) ;
V_4 -> V_194 . V_195 . V_206 = F_130 ( V_171 -> V_207 ) ;
V_4 -> V_194 . V_195 . V_208 = F_130 ( V_171 -> V_209 ) ;
V_4 -> V_194 . V_195 . V_210 = F_130 ( V_171 -> V_211 ) ;
V_4 -> V_194 . V_195 . V_212 = F_130 ( V_171 -> V_213 ) ;
V_4 -> V_194 . V_195 . V_214 =
F_130 ( V_171 -> V_215 ) ;
V_4 -> V_194 . V_216 . V_217 = F_130 ( V_171 -> V_218 ) ;
V_4 -> V_194 . V_216 . V_219 =
F_130 ( V_171 -> V_220 ) ;
V_4 -> V_194 . V_216 . V_221 =
F_130 ( V_171 -> V_222 ) ;
V_4 -> V_194 . V_216 . V_223 = F_130 ( V_171 -> V_224 ) ;
break;
}
default:
F_71 ( V_4 -> V_2 ,
L_40 , V_169 -> V_190 . V_225 ) ;
V_80 = - V_49 ;
goto V_189;
}
V_189:
return V_80 ;
}
static int F_131 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
F_120 ( V_4 ) ;
switch ( V_4 -> V_22 ) {
case V_172 :
case V_173 :
case V_79 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
if ( V_4 -> V_22 == V_177 || V_4 -> V_22 == V_178 )
V_4 -> V_226 = V_227 ;
else
V_4 -> V_226 = V_228 ;
V_56 = F_132 ( V_4 ) ;
if ( V_56 )
return V_56 ;
break;
#ifdef F_126
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
V_4 -> V_226 = V_229 ;
V_56 = F_133 ( V_4 ) ;
if ( V_56 )
return V_56 ;
break;
#endif
#ifdef F_127
case V_78 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
if ( ( V_4 -> V_22 == V_78 ) || ( V_4 -> V_22 == V_184 ) )
V_4 -> V_226 = V_230 ;
else
V_4 -> V_226 = V_231 ;
V_56 = F_134 ( V_4 ) ;
if ( V_56 )
return V_56 ;
break;
#endif
case V_23 :
case V_188 :
if ( V_4 -> V_22 == V_188 )
V_4 -> V_226 = V_232 ;
else
V_4 -> V_226 = V_233 ;
V_56 = F_135 ( V_4 ) ;
if ( V_56 )
return V_56 ;
break;
default:
return - V_49 ;
}
V_56 = F_125 ( V_4 ) ;
if ( V_56 )
return V_56 ;
if ( F_64 ( V_4 ) ) {
V_56 = F_136 ( V_4 , true ) ;
if ( V_56 )
return V_56 ;
}
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ( V_234 & ( 1 << V_44 ) ) == 0 ) {
F_21 ( L_41 ,
V_44 , V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 ) ;
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = false ;
} else {
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_235 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_235 ( ( void * ) V_4 ) ;
if ( V_56 == - V_236 ) {
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = false ;
} else if ( V_56 ) {
F_21 ( L_42 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
} else {
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = true ;
}
} else {
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = true ;
}
}
}
V_4 -> V_237 &= V_238 ;
V_4 -> V_239 &= V_240 ;
return 0 ;
}
static int F_137 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_241 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_21 ( L_43 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_242 = true ;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_243 ) {
V_56 = F_32 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_44 , V_56 ) ;
return V_56 ;
}
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_244 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_21 ( L_45 , V_44 , V_56 ) ;
return V_56 ;
}
V_56 = F_50 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_46 , V_56 ) ;
return V_56 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_245 = true ;
if ( F_64 ( V_4 ) ) {
V_56 = F_138 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_47 , V_56 ) ;
return V_56 ;
}
}
}
}
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_242 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_243 )
continue;
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_244 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_21 ( L_48 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_245 = true ;
}
return 0 ;
}
static void F_139 ( struct V_3 * V_4 )
{
memcpy ( V_4 -> V_246 , V_4 -> V_247 . V_30 , V_248 ) ;
}
static bool F_140 ( struct V_3 * V_4 )
{
return ! ! memcmp ( V_4 -> V_247 . V_30 , V_4 -> V_246 ,
V_248 ) ;
}
static int F_141 ( struct V_3 * V_4 )
{
int V_44 = 0 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_249 &&
V_4 -> V_139 [ V_44 ] . V_142 -> type != V_250 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_251 ) ;
if ( V_56 ) {
F_21 ( L_49 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
}
}
return 0 ;
}
static int F_142 ( struct V_3 * V_4 )
{
int V_44 = 0 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_252 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_252 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_21 ( L_50 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_253 = true ;
}
}
F_143 ( V_254 , & V_4 -> V_255 ,
F_144 ( V_256 ) ) ;
F_139 ( V_4 ) ;
return 0 ;
}
static int F_145 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_245 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_257 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_258 ) ;
if ( V_56 ) {
F_21 ( L_51 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_259 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_119 ( L_52 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_245 = false ;
break;
}
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_245 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_243 ) {
F_49 ( V_4 ) ;
F_34 ( V_4 ) ;
}
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_249 &&
V_4 -> V_139 [ V_44 ] . V_142 -> type != V_250 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_258 ) ;
if ( V_56 ) {
F_21 ( L_51 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
}
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_259 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_119 ( L_52 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_245 = false ;
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_242 )
continue;
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_260 ( ( void * ) V_4 ) ;
if ( V_56 ) {
F_119 ( L_53 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_242 = false ;
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = false ;
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_253 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_261 )
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_261 ( ( void * ) V_4 ) ;
V_4 -> V_139 [ V_44 ] . V_140 . V_253 = false ;
}
if ( F_64 ( V_4 ) ) {
F_35 ( & V_4 -> V_262 . V_263 , & V_4 -> V_262 . V_264 , NULL ) ;
F_146 ( V_4 , false ) ;
}
return 0 ;
}
static void F_147 ( struct V_265 * V_266 )
{
struct V_3 * V_4 =
F_148 ( V_266 , struct V_3 , V_255 . V_266 ) ;
F_141 ( V_4 ) ;
}
int F_149 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
if ( F_64 ( V_4 ) )
F_136 ( V_4 , false ) ;
V_56 = F_111 ( V_4 , V_257 ,
V_258 ) ;
if ( V_56 ) {
F_21 ( L_54 , V_56 ) ;
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_44 != V_257 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_258 ) ;
if ( V_56 ) {
F_21 ( L_51 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
}
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_267 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_55 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
}
}
if ( F_64 ( V_4 ) )
F_146 ( V_4 , false ) ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
static enum V_135 V_268 [] = {
V_243 ,
V_269 ,
V_270 ,
} ;
for ( V_44 = 0 ; V_44 < F_151 ( V_268 ) ; V_44 ++ ) {
int V_271 ;
struct V_151 * V_32 ;
for ( V_271 = 0 ; V_271 < V_4 -> V_138 ; V_271 ++ ) {
V_32 = & V_4 -> V_139 [ V_271 ] ;
if ( V_32 -> V_142 -> type != V_268 [ V_44 ] ||
! V_32 -> V_140 . V_141 )
continue;
V_56 = V_32 -> V_142 -> V_143 -> V_244 ( V_4 ) ;
F_89 ( L_56 , V_32 -> V_142 -> V_143 -> V_145 , V_56 ? L_57 : L_58 ) ;
}
}
return 0 ;
}
static int F_152 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
static enum V_135 V_268 [] = {
V_257 ,
V_272 ,
V_273 ,
V_274 ,
V_249 ,
V_250
} ;
for ( V_44 = 0 ; V_44 < F_151 ( V_268 ) ; V_44 ++ ) {
int V_271 ;
struct V_151 * V_32 ;
for ( V_271 = 0 ; V_271 < V_4 -> V_138 ; V_271 ++ ) {
V_32 = & V_4 -> V_139 [ V_271 ] ;
if ( V_32 -> V_142 -> type != V_268 [ V_44 ] ||
! V_32 -> V_140 . V_141 )
continue;
V_56 = V_32 -> V_142 -> V_143 -> V_244 ( V_4 ) ;
F_89 ( L_56 , V_32 -> V_142 -> V_143 -> V_145 , V_56 ? L_57 : L_58 ) ;
}
}
return 0 ;
}
static int F_153 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_269 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_243 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type ==
V_270 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_275 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_59 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
}
}
return 0 ;
}
static int F_154 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_269 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_243 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_270 )
continue;
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_275 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_59 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_56 ) ;
return V_56 ;
}
}
return 0 ;
}
static int F_155 ( struct V_3 * V_4 )
{
int V_56 ;
V_56 = F_153 ( V_4 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_154 ( V_4 ) ;
return V_56 ;
}
static void F_156 ( struct V_3 * V_4 )
{
if ( V_4 -> V_111 ) {
if ( F_157 ( V_4 ) )
V_4 -> V_262 . V_276 |= V_277 ;
} else {
if ( F_158 ( V_4 ) )
V_4 -> V_262 . V_276 |= V_277 ;
}
}
int F_159 ( struct V_3 * V_4 ,
struct V_1 * V_100 ,
struct V_126 * V_19 ,
T_1 V_6 )
{
int V_56 , V_44 ;
bool V_278 = false ;
T_2 V_279 ;
V_4 -> V_280 = false ;
V_4 -> V_2 = & V_19 -> V_2 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_22 = V_6 & V_281 ;
V_4 -> V_282 = V_283 ;
V_4 -> V_63 . V_74 = 512 * 1024 * 1024 ;
V_4 -> V_284 = false ;
V_4 -> V_285 = 0 ;
V_4 -> V_286 . V_287 = NULL ;
V_4 -> V_286 . V_288 = NULL ;
V_4 -> V_289 . V_290 = NULL ;
V_4 -> V_289 . V_291 = 0 ;
V_4 -> V_247 . V_292 = NULL ;
V_4 -> V_293 = F_160 ( V_294 ) ;
V_4 -> V_295 = & F_27 ;
V_4 -> V_296 = & F_29 ;
V_4 -> V_297 = & F_27 ;
V_4 -> V_298 = & F_29 ;
V_4 -> V_299 = & F_27 ;
V_4 -> V_300 = & F_29 ;
V_4 -> V_301 = & F_27 ;
V_4 -> V_302 = & F_29 ;
V_4 -> V_303 = & F_27 ;
V_4 -> V_304 = & F_29 ;
V_4 -> V_305 = & F_27 ;
V_4 -> V_306 = & F_29 ;
V_4 -> V_307 = & F_30 ;
V_4 -> V_308 = & F_31 ;
F_89 ( L_60 ,
V_309 [ V_4 -> V_22 ] , V_19 -> V_310 , V_19 -> V_20 ,
V_19 -> V_311 , V_19 -> V_312 , V_19 -> V_313 ) ;
F_161 ( & V_4 -> V_314 . V_315 . V_316 , 0 ) ;
F_91 ( & V_4 -> V_170 . V_110 ) ;
F_91 ( & V_4 -> V_82 . V_110 ) ;
F_91 ( & V_4 -> V_194 . V_317 ) ;
F_91 ( & V_4 -> V_318 ) ;
F_91 ( & V_4 -> V_319 ) ;
F_91 ( & V_4 -> V_320 ) ;
F_162 ( V_4 -> V_321 ) ;
F_101 ( V_4 ) ;
F_163 ( & V_4 -> V_16 ) ;
F_163 ( & V_4 -> V_322 ) ;
F_163 ( & V_4 -> V_323 ) ;
F_163 ( & V_4 -> V_324 ) ;
F_163 ( & V_4 -> V_325 ) ;
F_163 ( & V_4 -> V_326 ) ;
F_163 ( & V_4 -> V_327 ) ;
F_163 ( & V_4 -> V_328 ) ;
F_163 ( & V_4 -> V_329 . V_316 ) ;
F_164 ( & V_4 -> V_330 ) ;
F_91 ( & V_4 -> V_331 ) ;
F_164 ( & V_4 -> V_332 ) ;
F_163 ( & V_4 -> V_333 ) ;
F_164 ( & V_4 -> V_334 ) ;
F_163 ( & V_4 -> V_335 ) ;
F_165 ( & V_4 -> V_255 , F_147 ) ;
if ( V_4 -> V_22 >= V_78 ) {
V_4 -> V_336 = F_42 ( V_4 -> V_19 , 5 ) ;
V_4 -> V_12 = F_43 ( V_4 -> V_19 , 5 ) ;
} else {
V_4 -> V_336 = F_42 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_12 = F_43 ( V_4 -> V_19 , 2 ) ;
}
V_4 -> V_15 = F_45 ( V_4 -> V_336 , V_4 -> V_12 ) ;
if ( V_4 -> V_15 == NULL ) {
return - V_50 ;
}
F_89 ( L_61 , ( T_1 ) V_4 -> V_336 ) ;
F_89 ( L_62 , ( unsigned ) V_4 -> V_12 ) ;
if ( V_4 -> V_22 >= V_78 )
F_41 ( V_4 ) ;
for ( V_44 = 0 ; V_44 < V_337 ; V_44 ++ ) {
if ( F_166 ( V_4 -> V_19 , V_44 ) & V_338 ) {
V_4 -> V_25 = F_43 ( V_4 -> V_19 , V_44 ) ;
V_4 -> V_26 = F_167 ( V_4 -> V_19 , V_44 , V_4 -> V_25 ) ;
break;
}
}
if ( V_4 -> V_26 == NULL )
F_89 ( L_63 ) ;
V_56 = F_131 ( V_4 ) ;
if ( V_56 )
return V_56 ;
F_168 ( V_4 -> V_19 , V_4 , NULL , F_96 ) ;
if ( V_339 == 1 )
V_278 = true ;
if ( F_1 ( V_100 ) )
V_278 = true ;
if ( ! F_169 ( V_4 -> V_19 ) )
F_170 ( V_4 -> V_19 ,
& V_340 , V_278 ) ;
if ( V_278 )
F_171 ( V_4 -> V_2 , & V_4 -> V_341 ) ;
if ( ! F_172 ( V_4 ) ) {
V_56 = - V_49 ;
goto V_342;
}
V_56 = F_87 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_64 ) ;
F_173 ( V_343 , 0 , 0 ) ;
goto V_342;
}
F_156 ( V_4 ) ;
if ( F_63 ( V_4 ) ) {
if ( ! V_4 -> V_109 ) {
F_71 ( V_4 -> V_2 , L_65 ) ;
F_173 ( V_344 , 0 , 0 ) ;
V_56 = - V_49 ;
goto V_342;
}
F_89 ( L_66 ) ;
V_56 = F_174 ( V_4 -> V_95 . V_96 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_67 ) ;
F_173 ( V_345 , 0 , 0 ) ;
goto V_342;
}
} else {
F_89 ( L_68 ) ;
}
if ( V_4 -> V_111 ) {
V_56 = F_175 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_69 ) ;
F_173 ( V_346 , 0 , 0 ) ;
goto V_342;
}
} else {
V_56 = F_176 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_70 ) ;
F_173 ( V_346 , 0 , 0 ) ;
goto V_342;
}
F_177 ( V_4 ) ;
}
V_56 = F_178 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_71 ) ;
F_173 ( V_347 , 0 , 0 ) ;
goto V_342;
}
F_179 ( V_4 -> V_100 ) ;
V_56 = F_137 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_72 ) ;
F_173 ( V_348 , 0 , 0 ) ;
F_145 ( V_4 ) ;
goto V_342;
}
V_4 -> V_284 = true ;
F_180 ( V_4 ) ;
if ( V_349 >= 0 )
V_279 = V_349 ;
else
V_279 = 8 ;
V_4 -> V_329 . V_350 = F_181 ( F_182 ( 1u , V_279 ) ) ;
V_56 = F_183 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_73 , V_56 ) ;
F_173 ( V_351 , 0 , V_56 ) ;
goto V_342;
}
V_56 = F_184 ( V_4 ) ;
if ( V_56 )
F_21 ( L_74 , V_56 ) ;
F_185 ( V_4 ) ;
V_56 = F_186 ( V_4 ) ;
if ( V_56 )
F_21 ( L_75 , V_56 ) ;
V_56 = F_187 ( V_4 ) ;
if ( V_56 )
F_21 ( L_76 , V_56 ) ;
V_56 = F_188 ( V_4 ) ;
if ( V_56 )
F_21 ( L_77 , V_56 ) ;
V_56 = F_189 ( V_4 ) ;
if ( V_56 )
F_21 ( L_78 , V_56 ) ;
if ( ( V_352 & 1 ) ) {
if ( V_4 -> V_284 )
F_190 ( V_4 ) ;
else
F_89 ( L_79 ) ;
}
if ( V_353 ) {
if ( V_4 -> V_284 )
F_191 ( V_4 , V_353 ) ;
else
F_89 ( L_80 ) ;
}
V_56 = F_142 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_81 ) ;
F_173 ( V_354 , 0 , V_56 ) ;
goto V_342;
}
return 0 ;
V_342:
F_192 ( V_4 ) ;
if ( V_278 )
F_193 ( V_4 -> V_2 ) ;
return V_56 ;
}
void F_194 ( struct V_3 * V_4 )
{
int V_56 ;
F_89 ( L_82 ) ;
V_4 -> V_280 = true ;
if ( V_4 -> V_95 . V_355 )
F_195 ( V_4 -> V_100 ) ;
F_196 ( V_4 ) ;
F_197 ( V_4 ) ;
F_198 ( V_4 ) ;
F_199 ( V_4 ) ;
V_56 = F_145 ( V_4 ) ;
if ( V_4 -> V_170 . V_171 ) {
F_200 ( V_4 -> V_170 . V_171 ) ;
V_4 -> V_170 . V_171 = NULL ;
}
V_4 -> V_284 = false ;
F_201 ( & V_4 -> V_255 ) ;
F_202 ( V_4 ) ;
F_85 ( V_4 ) ;
F_86 ( V_4 -> V_109 ) ;
V_4 -> V_109 = NULL ;
if ( ! F_169 ( V_4 -> V_19 ) )
F_203 ( V_4 -> V_19 ) ;
if ( V_4 -> V_6 & V_7 )
F_193 ( V_4 -> V_2 ) ;
F_168 ( V_4 -> V_19 , NULL , NULL , NULL ) ;
if ( V_4 -> V_26 )
F_204 ( V_4 -> V_19 , V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
F_47 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
if ( V_4 -> V_22 >= V_78 )
F_46 ( V_4 ) ;
F_205 ( V_4 ) ;
}
int F_109 ( struct V_1 * V_2 , bool V_267 , bool V_356 )
{
struct V_3 * V_4 ;
struct V_357 * V_358 ;
struct V_359 * V_360 ;
int V_56 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_361 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_130 == V_133 )
return 0 ;
F_108 ( V_2 ) ;
F_206 ( V_2 ) ;
F_207 (connector, &dev->mode_config.connector_list, head) {
F_208 ( V_360 , V_362 ) ;
}
F_209 ( V_2 ) ;
F_210 ( V_4 ) ;
F_207 (crtc, &dev->mode_config.crtc_list, head) {
struct V_363 * V_363 = F_211 ( V_358 ) ;
struct V_364 * V_365 = F_212 ( V_358 -> V_366 -> V_367 ) ;
struct V_368 * V_37 ;
if ( V_363 -> V_369 ) {
struct V_368 * V_370 = F_213 ( V_363 -> V_369 ) ;
V_56 = F_214 ( V_370 , true ) ;
if ( V_56 == 0 ) {
F_215 ( V_370 ) ;
F_216 ( V_370 ) ;
}
}
if ( V_365 == NULL || V_365 -> V_371 == NULL ) {
continue;
}
V_37 = F_213 ( V_365 -> V_371 ) ;
if ( ! F_217 ( V_4 , V_37 ) ) {
V_56 = F_214 ( V_37 , true ) ;
if ( V_56 == 0 ) {
F_215 ( V_37 ) ;
F_216 ( V_37 ) ;
}
}
}
F_196 ( V_4 ) ;
F_218 ( V_4 ) ;
V_56 = F_149 ( V_4 ) ;
F_196 ( V_4 ) ;
F_219 ( V_4 ) ;
F_220 ( V_2 -> V_19 ) ;
if ( V_267 ) {
F_221 ( V_2 -> V_19 ) ;
F_222 ( V_2 -> V_19 , V_372 ) ;
} else {
V_56 = F_223 ( V_4 ) ;
if ( V_56 )
F_21 ( L_83 ) ;
}
if ( V_356 ) {
F_224 () ;
F_225 ( V_4 , 1 ) ;
F_226 () ;
}
return 0 ;
}
int F_106 ( struct V_1 * V_2 , bool V_275 , bool V_356 )
{
struct V_359 * V_360 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_357 * V_358 ;
int V_56 = 0 ;
if ( V_2 -> V_130 == V_133 )
return 0 ;
if ( V_356 )
F_224 () ;
if ( V_275 ) {
F_222 ( V_2 -> V_19 , V_373 ) ;
F_227 ( V_2 -> V_19 ) ;
V_56 = F_228 ( V_2 -> V_19 ) ;
if ( V_56 )
goto V_374;
}
F_229 ( V_4 ) ;
if ( F_60 ( V_4 ) ) {
V_56 = F_174 ( V_4 -> V_95 . V_96 ) ;
if ( V_56 )
F_21 ( L_84 ) ;
}
V_56 = F_155 ( V_4 ) ;
if ( V_56 ) {
F_21 ( L_85 , V_56 ) ;
goto V_374;
}
F_230 ( V_4 ) ;
if ( V_275 ) {
V_56 = F_184 ( V_4 ) ;
if ( V_56 )
F_21 ( L_74 , V_56 ) ;
}
V_56 = F_142 ( V_4 ) ;
if ( V_56 )
goto V_374;
F_207 (crtc, &dev->mode_config.crtc_list, head) {
struct V_363 * V_363 = F_211 ( V_358 ) ;
if ( V_363 -> V_369 ) {
struct V_368 * V_370 = F_213 ( V_363 -> V_369 ) ;
V_56 = F_214 ( V_370 , true ) ;
if ( V_56 == 0 ) {
V_56 = F_231 ( V_370 ,
V_35 ,
& V_363 -> V_375 ) ;
if ( V_56 != 0 )
F_21 ( L_86 , V_56 ) ;
F_216 ( V_370 ) ;
}
}
}
V_56 = F_232 ( V_4 ) ;
if ( V_56 )
return V_56 ;
if ( V_356 ) {
F_233 ( V_2 ) ;
F_206 ( V_2 ) ;
F_207 (connector, &dev->mode_config.connector_list, head) {
F_208 ( V_360 , V_376 ) ;
}
F_209 ( V_2 ) ;
}
F_107 ( V_2 ) ;
#ifdef F_234
V_2 -> V_2 -> V_377 . V_378 ++ ;
#endif
F_235 ( V_2 ) ;
#ifdef F_234
V_2 -> V_2 -> V_377 . V_378 -- ;
#endif
if ( V_356 )
F_225 ( V_4 , 0 ) ;
V_374:
if ( V_356 )
F_226 () ;
return V_56 ;
}
static bool F_236 ( struct V_3 * V_4 )
{
int V_44 ;
bool V_379 = false ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_380 )
V_4 -> V_139 [ V_44 ] . V_140 . V_381 =
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_380 ( V_4 ) ;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_381 ) {
F_89 ( L_87 , V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 ) ;
V_379 = true ;
}
}
return V_379 ;
}
static int F_237 ( struct V_3 * V_4 )
{
int V_44 , V_56 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_381 &&
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_382 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_382 ( V_4 ) ;
if ( V_56 )
return V_56 ;
}
}
return 0 ;
}
static bool F_238 ( struct V_3 * V_4 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_243 ) ||
( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_257 ) ||
( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_383 ) ||
( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_272 ) ) {
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_381 ) {
F_89 ( L_88 ) ;
return true ;
}
}
}
return false ;
}
static int F_239 ( struct V_3 * V_4 )
{
int V_44 , V_56 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_381 &&
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_384 ) {
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_384 ( V_4 ) ;
if ( V_56 )
return V_56 ;
}
}
return 0 ;
}
static int F_240 ( struct V_3 * V_4 )
{
int V_44 , V_56 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_381 &&
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_385 )
V_56 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_385 ( V_4 ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
bool F_241 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 & V_386 )
return false ;
return V_387 > 0 ? true : false ;
}
static int F_242 ( struct V_3 * V_4 ,
struct V_388 * V_389 ,
struct V_368 * V_390 ,
struct V_391 * * V_392 )
{
T_1 V_393 ;
int V_56 ;
if ( ! V_390 -> V_394 )
return 0 ;
V_56 = F_214 ( V_390 , true ) ;
if ( V_56 )
return V_56 ;
V_393 = F_243 ( V_390 -> V_395 . V_396 . V_397 ) ;
if ( V_393 == V_35 ) {
V_56 = F_244 ( V_390 -> V_394 ) ;
if ( V_56 ) {
F_21 ( L_89 ) ;
goto V_80;
}
V_56 = F_245 ( V_4 , V_389 , V_390 ,
NULL , V_392 , true ) ;
if ( V_56 ) {
F_21 ( L_90 ) ;
goto V_80;
}
}
V_80:
F_216 ( V_390 ) ;
return V_56 ;
}
int F_246 ( struct V_3 * V_4 , struct V_398 * V_399 )
{
int V_44 , V_271 , V_56 = 0 ;
int V_400 ;
struct V_368 * V_390 , * V_41 ;
struct V_388 * V_389 ;
struct V_391 * V_392 = NULL , * V_401 = NULL ;
F_247 ( & V_4 -> V_262 . V_402 ) ;
F_248 ( & V_4 -> V_403 ) ;
V_4 -> V_194 . V_404 = true ;
V_400 = F_249 ( & V_4 -> V_286 . V_405 ) ;
V_271 = V_399 ? V_399 -> V_389 -> V_406 : 0 ;
for ( V_44 = V_271 ; V_44 < V_271 + V_294 ; ++ V_44 ) {
V_389 = V_4 -> V_407 [ V_44 % V_294 ] ;
if ( ! V_389 || ! V_389 -> V_408 . V_409 )
continue;
F_250 ( V_389 -> V_408 . V_409 ) ;
if ( V_399 && V_271 != V_44 )
continue;
if ( V_399 && F_251 ( & V_399 -> V_46 . V_410 ) ) {
F_252 ( V_389 -> V_408 . V_409 ) ;
goto V_411;
}
if ( F_253 ( & V_399 -> V_46 , V_412 ) )
F_254 ( & V_399 -> V_46 ) ;
F_255 ( & V_389 -> V_408 ) ;
F_256 ( V_389 ) ;
}
if ( V_399 )
F_257 ( V_4 ) ;
else
F_136 ( V_4 , true ) ;
F_150 ( V_4 ) ;
F_258 ( V_4 ) ;
F_152 ( V_4 ) ;
F_259 ( V_4 ) ;
if ( F_184 ( V_4 ) )
F_71 ( V_4 -> V_2 , L_91 , V_56 ) ;
F_146 ( V_4 , true ) ;
F_89 ( L_92 ) ;
V_389 = V_4 -> V_286 . V_288 ;
F_247 ( & V_4 -> V_331 ) ;
F_260 (bo, tmp, &adev->shadow_list, shadow_list) {
V_401 = NULL ;
F_242 ( V_4 , V_389 , V_390 , & V_401 ) ;
if ( V_392 ) {
V_56 = F_261 ( V_392 , false ) ;
if ( V_56 ) {
F_262 ( V_56 , L_93 ) ;
break;
}
}
F_263 ( V_392 ) ;
V_392 = V_401 ;
}
F_264 ( & V_4 -> V_331 ) ;
if ( V_392 ) {
V_56 = F_261 ( V_392 , false ) ;
if ( V_56 )
F_262 ( V_56 , L_93 ) ;
}
F_263 ( V_392 ) ;
for ( V_44 = V_271 ; V_44 < V_271 + V_294 ; ++ V_44 ) {
V_389 = V_4 -> V_407 [ V_44 % V_294 ] ;
if ( ! V_389 || ! V_389 -> V_408 . V_409 )
continue;
if ( V_399 && V_271 != V_44 ) {
F_252 ( V_389 -> V_408 . V_409 ) ;
continue;
}
F_265 ( & V_389 -> V_408 ) ;
F_252 ( V_389 -> V_408 . V_409 ) ;
}
F_233 ( V_4 -> V_100 ) ;
V_411:
F_266 ( & V_4 -> V_286 . V_405 , V_400 ) ;
if ( V_56 ) {
F_58 ( V_4 -> V_2 , L_94 ) ;
} else {
F_58 ( V_4 -> V_2 , L_95 ) ;
}
V_4 -> V_194 . V_404 = false ;
F_264 ( & V_4 -> V_262 . V_402 ) ;
return V_56 ;
}
int F_267 ( struct V_3 * V_4 )
{
int V_44 , V_56 ;
int V_400 ;
bool V_413 , V_414 = false ;
if ( ! F_236 ( V_4 ) ) {
F_89 ( L_96 ) ;
return 0 ;
}
F_248 ( & V_4 -> V_403 ) ;
V_400 = F_249 ( & V_4 -> V_286 . V_405 ) ;
for ( V_44 = 0 ; V_44 < V_294 ; ++ V_44 ) {
struct V_388 * V_389 = V_4 -> V_407 [ V_44 ] ;
if ( ! V_389 || ! V_389 -> V_408 . V_409 )
continue;
F_250 ( V_389 -> V_408 . V_409 ) ;
F_255 ( & V_389 -> V_408 ) ;
}
F_268 ( V_4 ) ;
V_413 = F_238 ( V_4 ) ;
if ( ! V_413 ) {
F_237 ( V_4 ) ;
V_56 = F_239 ( V_4 ) ;
F_240 ( V_4 ) ;
if ( V_56 || F_236 ( V_4 ) ) {
F_89 ( L_97 ) ;
V_413 = true ;
}
}
if ( V_413 ) {
V_56 = F_149 ( V_4 ) ;
V_415:
F_219 ( V_4 ) ;
V_56 = F_223 ( V_4 ) ;
F_229 ( V_4 ) ;
F_174 ( V_4 -> V_95 . V_96 ) ;
if ( ! V_56 ) {
F_58 ( V_4 -> V_2 , L_98 ) ;
V_56 = F_153 ( V_4 ) ;
if ( V_56 )
goto V_189;
V_414 = F_140 ( V_4 ) ;
if ( V_414 ) {
F_21 ( L_99 ) ;
F_248 ( & V_4 -> V_416 ) ;
}
V_56 = F_258 ( V_4 ) ;
if ( V_56 )
goto V_189;
V_56 = F_154 ( V_4 ) ;
if ( V_56 )
goto V_189;
if ( V_414 )
F_139 ( V_4 ) ;
}
}
V_189:
if ( ! V_56 ) {
F_259 ( V_4 ) ;
V_56 = F_184 ( V_4 ) ;
if ( V_56 ) {
F_71 ( V_4 -> V_2 , L_74 , V_56 ) ;
V_56 = F_149 ( V_4 ) ;
V_413 = true ;
goto V_415;
}
if ( V_413 && F_241 ( V_4 ) ) {
struct V_388 * V_389 = V_4 -> V_286 . V_288 ;
struct V_368 * V_390 , * V_41 ;
struct V_391 * V_392 = NULL , * V_401 = NULL ;
F_89 ( L_92 ) ;
F_247 ( & V_4 -> V_331 ) ;
F_260 (bo, tmp, &adev->shadow_list, shadow_list) {
V_401 = NULL ;
F_242 ( V_4 , V_389 , V_390 , & V_401 ) ;
if ( V_392 ) {
V_56 = F_261 ( V_392 , false ) ;
if ( V_56 ) {
F_262 ( V_56 , L_93 ) ;
break;
}
}
F_263 ( V_392 ) ;
V_392 = V_401 ;
}
F_264 ( & V_4 -> V_331 ) ;
if ( V_392 ) {
V_56 = F_261 ( V_392 , false ) ;
if ( V_56 )
F_262 ( V_56 , L_93 ) ;
}
F_263 ( V_392 ) ;
}
for ( V_44 = 0 ; V_44 < V_294 ; ++ V_44 ) {
struct V_388 * V_389 = V_4 -> V_407 [ V_44 ] ;
if ( ! V_389 || ! V_389 -> V_408 . V_409 )
continue;
F_265 ( & V_389 -> V_408 ) ;
F_252 ( V_389 -> V_408 . V_409 ) ;
}
} else {
F_71 ( V_4 -> V_2 , L_100 , V_56 ) ;
F_173 ( V_417 , 0 , V_56 ) ;
for ( V_44 = 0 ; V_44 < V_294 ; ++ V_44 ) {
if ( V_4 -> V_407 [ V_44 ] && V_4 -> V_407 [ V_44 ] -> V_408 . V_409 ) {
F_252 ( V_4 -> V_407 [ V_44 ] -> V_408 . V_409 ) ;
}
}
}
F_233 ( V_4 -> V_100 ) ;
F_266 ( & V_4 -> V_286 . V_405 , V_400 ) ;
if ( V_56 ) {
F_58 ( V_4 -> V_2 , L_94 ) ;
F_173 ( V_418 , 0 , V_56 ) ;
}
else {
F_58 ( V_4 -> V_2 , L_95 ) ;
}
F_192 ( V_4 ) ;
return V_56 ;
}
void F_269 ( struct V_3 * V_4 )
{
T_2 V_419 ;
int V_10 ;
if ( V_420 )
V_4 -> V_82 . V_421 = V_420 ;
if ( V_422 )
V_4 -> V_82 . V_423 = V_422 ;
if ( F_270 ( V_4 -> V_19 -> V_424 ) ) {
if ( V_4 -> V_82 . V_421 == 0 )
V_4 -> V_82 . V_421 = V_425 ;
if ( V_4 -> V_82 . V_423 == 0 )
V_4 -> V_82 . V_423 = V_426 ;
return;
}
if ( V_4 -> V_82 . V_421 == 0 ) {
V_10 = F_271 ( V_4 -> V_100 , & V_419 ) ;
if ( ! V_10 ) {
V_4 -> V_82 . V_421 = ( V_427 |
V_428 |
V_429 ) ;
if ( V_419 & V_430 )
V_4 -> V_82 . V_421 |= V_431 ;
if ( V_419 & V_432 )
V_4 -> V_82 . V_421 |= V_433 ;
if ( V_419 & V_434 )
V_4 -> V_82 . V_421 |= V_435 ;
} else {
V_4 -> V_82 . V_421 = V_425 ;
}
}
if ( V_4 -> V_82 . V_423 == 0 ) {
V_10 = F_272 ( V_4 -> V_100 , & V_419 ) ;
if ( ! V_10 ) {
switch ( V_419 ) {
case 32 :
V_4 -> V_82 . V_423 = ( V_436 |
V_437 |
V_438 |
V_439 |
V_440 |
V_441 |
V_442 ) ;
break;
case 16 :
V_4 -> V_82 . V_423 = ( V_437 |
V_438 |
V_439 |
V_440 |
V_441 |
V_442 ) ;
break;
case 12 :
V_4 -> V_82 . V_423 = ( V_438 |
V_439 |
V_440 |
V_441 |
V_442 ) ;
break;
case 8 :
V_4 -> V_82 . V_423 = ( V_439 |
V_440 |
V_441 |
V_442 ) ;
break;
case 4 :
V_4 -> V_82 . V_423 = ( V_440 |
V_441 |
V_442 ) ;
break;
case 2 :
V_4 -> V_82 . V_423 = ( V_441 |
V_442 ) ;
break;
case 1 :
V_4 -> V_82 . V_423 = V_442 ;
break;
default:
break;
}
} else {
V_4 -> V_82 . V_423 = V_426 ;
}
}
}
int F_273 ( struct V_3 * V_4 ,
const struct V_443 * V_444 ,
unsigned V_445 )
{
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_446 ; V_44 ++ ) {
if ( V_4 -> V_447 [ V_44 ] . V_444 == V_444 ) {
return 0 ;
}
}
V_44 = V_4 -> V_446 + 1 ;
if ( V_44 > V_448 ) {
F_21 ( L_101 ) ;
F_21 ( L_102
L_103 ) ;
return - V_49 ;
}
V_4 -> V_447 [ V_4 -> V_446 ] . V_444 = V_444 ;
V_4 -> V_447 [ V_4 -> V_446 ] . V_449 = V_445 ;
V_4 -> V_446 = V_44 ;
#if F_274 ( V_450 )
F_275 ( V_444 , V_445 ,
V_4 -> V_100 -> V_366 -> V_451 ,
V_4 -> V_100 -> V_366 ) ;
#endif
return 0 ;
}
static T_7 F_276 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
bool V_458 , V_459 ;
unsigned V_460 , V_461 , V_462 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
V_458 = ( * V_455 >> 23 ) & 1 ;
if ( * V_455 & ( 1ULL << 62 ) ) {
V_462 = ( * V_455 >> 24 ) & 0x3FF ;
V_461 = ( * V_455 >> 34 ) & 0x3FF ;
V_460 = ( * V_455 >> 44 ) & 0x3FF ;
if ( V_462 == 0x3FF )
V_462 = 0xFFFFFFFF ;
if ( V_461 == 0x3FF )
V_461 = 0xFFFFFFFF ;
if ( V_460 == 0x3FF )
V_460 = 0xFFFFFFFF ;
V_459 = 1 ;
} else {
V_459 = 0 ;
}
* V_455 &= ( 1UL << 22 ) - 1 ;
if ( V_459 ) {
if ( ( V_461 != 0xFFFFFFFF && V_461 >= V_4 -> V_194 . V_195 . V_200 ) ||
( V_462 != 0xFFFFFFFF && V_462 >= V_4 -> V_194 . V_195 . V_196 ) )
return - V_49 ;
F_247 ( & V_4 -> V_319 ) ;
F_278 ( V_4 , V_462 ,
V_461 , V_460 ) ;
}
if ( V_458 )
F_247 ( & V_4 -> V_82 . V_110 ) ;
while ( V_47 ) {
T_1 V_463 ;
if ( * V_455 > V_4 -> V_12 )
goto V_464;
V_463 = F_37 ( * V_455 >> 2 ) ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 ) {
V_457 = V_56 ;
goto V_464;
}
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
V_464:
if ( V_459 ) {
F_278 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_264 ( & V_4 -> V_319 ) ;
}
if ( V_458 )
F_264 ( & V_4 -> V_82 . V_110 ) ;
return V_457 ;
}
static T_7 F_280 ( struct V_452 * V_453 , const char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
bool V_458 , V_459 ;
unsigned V_460 , V_461 , V_462 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
V_458 = ( * V_455 >> 23 ) & 1 ;
if ( * V_455 & ( 1ULL << 62 ) ) {
V_462 = ( * V_455 >> 24 ) & 0x3FF ;
V_461 = ( * V_455 >> 34 ) & 0x3FF ;
V_460 = ( * V_455 >> 44 ) & 0x3FF ;
if ( V_462 == 0x3FF )
V_462 = 0xFFFFFFFF ;
if ( V_461 == 0x3FF )
V_461 = 0xFFFFFFFF ;
if ( V_460 == 0x3FF )
V_460 = 0xFFFFFFFF ;
V_459 = 1 ;
} else {
V_459 = 0 ;
}
* V_455 &= ( 1UL << 22 ) - 1 ;
if ( V_459 ) {
if ( ( V_461 != 0xFFFFFFFF && V_461 >= V_4 -> V_194 . V_195 . V_200 ) ||
( V_462 != 0xFFFFFFFF && V_462 >= V_4 -> V_194 . V_195 . V_196 ) )
return - V_49 ;
F_247 ( & V_4 -> V_319 ) ;
F_278 ( V_4 , V_462 ,
V_461 , V_460 ) ;
}
if ( V_458 )
F_247 ( & V_4 -> V_82 . V_110 ) ;
while ( V_47 ) {
T_1 V_463 ;
if ( * V_455 > V_4 -> V_12 )
return V_457 ;
V_56 = F_281 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
F_38 ( * V_455 >> 2 , V_463 ) ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
if ( V_459 ) {
F_278 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_264 ( & V_4 -> V_319 ) ;
}
if ( V_458 )
F_264 ( & V_4 -> V_82 . V_110 ) ;
return V_457 ;
}
static T_7 F_282 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_463 ;
V_463 = F_283 ( * V_455 >> 2 ) ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_284 ( struct V_452 * V_453 , const char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_463 ;
V_56 = F_281 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
F_285 ( * V_455 >> 2 , V_463 ) ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_286 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_463 ;
V_463 = F_287 ( * V_455 >> 2 ) ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_288 ( struct V_452 * V_453 , const char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_463 ;
V_56 = F_281 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
F_289 ( * V_455 >> 2 , V_463 ) ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_290 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_463 ;
V_463 = F_291 ( * V_455 ) ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_292 ( struct V_452 * V_453 , const char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_463 ;
V_56 = F_281 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
F_293 ( * V_455 , V_463 ) ;
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_294 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
T_7 V_457 = 0 ;
int V_56 ;
T_1 * V_195 , V_465 = 0 ;
if ( V_47 & 0x3 || * V_455 & 0x3 )
return - V_49 ;
V_195 = F_295 ( 256 , sizeof( * V_195 ) , V_88 ) ;
if ( ! V_195 )
return - V_50 ;
V_195 [ V_465 ++ ] = 3 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_196 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_466 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_198 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_200 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_202 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_204 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_206 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_208 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_467 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_468 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_469 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_470 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_471 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_472 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_473 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_474 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_475 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_476 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_477 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_478 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_479 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_480 ;
V_195 [ V_465 ++ ] = V_4 -> V_194 . V_195 . V_481 ;
V_195 [ V_465 ++ ] = V_4 -> V_482 ;
V_195 [ V_465 ++ ] = V_4 -> V_239 ;
V_195 [ V_465 ++ ] = V_4 -> V_237 ;
V_195 [ V_465 ++ ] = V_4 -> V_226 ;
V_195 [ V_465 ++ ] = V_4 -> V_483 ;
V_195 [ V_465 ++ ] = V_4 -> V_19 -> V_20 ;
V_195 [ V_465 ++ ] = V_4 -> V_19 -> V_313 ;
V_195 [ V_465 ++ ] = V_4 -> V_19 -> V_312 ;
V_195 [ V_465 ++ ] = V_4 -> V_19 -> V_311 ;
while ( V_47 && ( * V_455 < V_465 * 4 ) ) {
T_1 V_463 ;
V_463 = V_195 [ * V_455 >> 2 ] ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 ) {
F_86 ( V_195 ) ;
return V_56 ;
}
V_457 += 4 ;
V_454 += 4 ;
* V_455 += 4 ;
V_47 -= 4 ;
}
F_86 ( V_195 ) ;
return V_457 ;
}
static T_7 F_296 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = F_277 ( V_453 ) -> V_456 ;
int V_406 , V_484 , V_485 , V_56 , V_486 ;
T_1 V_487 [ 16 ] ;
if ( V_47 & 3 || * V_455 & 0x3 )
return - V_49 ;
if ( V_488 == 0 )
return - V_49 ;
V_406 = * V_455 >> 2 ;
V_486 = sizeof( V_487 ) ;
if ( V_4 -> V_489 . V_490 && V_4 -> V_489 . V_490 -> V_491 )
V_56 = V_4 -> V_489 . V_490 -> V_491 ( V_4 -> V_489 . V_492 , V_406 , & V_487 [ 0 ] , & V_486 ) ;
else if ( V_4 -> V_82 . V_143 && V_4 -> V_82 . V_143 -> V_491 )
V_56 = V_4 -> V_82 . V_143 -> V_491 ( V_4 , V_406 , & V_487 [ 0 ] ,
& V_486 ) ;
else
return - V_49 ;
if ( V_47 > V_486 )
return - V_49 ;
V_485 = 0 ;
V_484 = 0 ;
if ( ! V_56 ) {
while ( V_47 ) {
V_56 = F_279 ( V_487 [ V_484 ++ ] , ( V_493 * ) V_454 ) ;
V_454 += 4 ;
V_47 -= 4 ;
V_485 += 4 ;
}
}
return ! V_56 ? V_485 : V_56 ;
}
static T_7 F_297 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = V_453 -> V_494 -> V_456 ;
int V_56 , V_484 ;
T_7 V_457 = 0 ;
T_1 V_61 , V_495 , V_496 , V_497 , V_498 , V_499 , V_84 [ 32 ] ;
if ( V_47 & 3 || * V_455 & 3 )
return - V_49 ;
V_61 = ( * V_455 & 0x7F ) ;
V_495 = ( ( * V_455 >> 7 ) & 0xFF ) ;
V_496 = ( ( * V_455 >> 15 ) & 0xFF ) ;
V_497 = ( ( * V_455 >> 23 ) & 0xFF ) ;
V_498 = ( ( * V_455 >> 31 ) & 0xFF ) ;
V_499 = ( ( * V_455 >> 37 ) & 0xFF ) ;
F_247 ( & V_4 -> V_319 ) ;
F_278 ( V_4 , V_495 , V_496 , V_497 ) ;
V_484 = 0 ;
if ( V_4 -> V_194 . V_143 -> V_500 )
V_4 -> V_194 . V_143 -> V_500 ( V_4 , V_499 , V_498 , V_84 , & V_484 ) ;
F_278 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_264 ( & V_4 -> V_319 ) ;
if ( ! V_484 )
return - V_49 ;
while ( V_47 && ( V_61 < V_484 * 4 ) ) {
T_1 V_463 ;
V_463 = V_84 [ V_61 >> 2 ] ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 )
return V_56 ;
V_457 += 4 ;
V_454 += 4 ;
V_61 += 4 ;
V_47 -= 4 ;
}
return V_457 ;
}
static T_7 F_298 ( struct V_452 * V_453 , char T_8 * V_454 ,
T_5 V_47 , T_9 * V_455 )
{
struct V_3 * V_4 = V_453 -> V_494 -> V_456 ;
int V_56 ;
T_7 V_457 = 0 ;
T_1 V_61 , V_495 , V_496 , V_497 , V_498 , V_499 , V_409 , V_501 , * V_84 ;
if ( V_47 & 3 || * V_455 & 3 )
return - V_49 ;
V_61 = ( * V_455 & 0xFFF ) ;
V_495 = ( ( * V_455 >> 12 ) & 0xFF ) ;
V_496 = ( ( * V_455 >> 20 ) & 0xFF ) ;
V_497 = ( ( * V_455 >> 28 ) & 0xFF ) ;
V_498 = ( ( * V_455 >> 36 ) & 0xFF ) ;
V_499 = ( ( * V_455 >> 44 ) & 0xFF ) ;
V_409 = ( ( * V_455 >> 52 ) & 0xFF ) ;
V_501 = ( ( * V_455 >> 60 ) & 1 ) ;
V_84 = F_295 ( 1024 , sizeof( * V_84 ) , V_88 ) ;
if ( ! V_84 )
return - V_50 ;
F_247 ( & V_4 -> V_319 ) ;
F_278 ( V_4 , V_495 , V_496 , V_497 ) ;
if ( V_501 == 0 ) {
if ( V_4 -> V_194 . V_143 -> V_502 )
V_4 -> V_194 . V_143 -> V_502 ( V_4 , V_499 , V_498 , V_409 , V_61 , V_47 >> 2 , V_84 ) ;
} else {
if ( V_4 -> V_194 . V_143 -> V_503 )
V_4 -> V_194 . V_143 -> V_503 ( V_4 , V_499 , V_498 , V_61 , V_47 >> 2 , V_84 ) ;
}
F_278 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_264 ( & V_4 -> V_319 ) ;
while ( V_47 ) {
T_1 V_463 ;
V_463 = V_84 [ V_61 ++ ] ;
V_56 = F_279 ( V_463 , ( T_1 * ) V_454 ) ;
if ( V_56 ) {
V_457 = V_56 ;
goto V_80;
}
V_457 += 4 ;
V_454 += 4 ;
V_47 -= 4 ;
}
V_80:
F_86 ( V_84 ) ;
return V_457 ;
}
static int F_187 ( struct V_3 * V_4 )
{
struct V_504 * V_153 = V_4 -> V_100 -> V_366 ;
struct V_505 * V_506 , * V_507 = V_153 -> V_451 ;
unsigned V_44 , V_271 ;
for ( V_44 = 0 ; V_44 < F_151 ( V_508 ) ; V_44 ++ ) {
V_506 = F_299 ( V_509 [ V_44 ] ,
V_510 | V_511 , V_507 ,
V_4 , V_508 [ V_44 ] ) ;
if ( F_300 ( V_506 ) ) {
for ( V_271 = 0 ; V_271 < V_44 ; V_271 ++ ) {
F_301 ( V_4 -> V_508 [ V_44 ] ) ;
V_4 -> V_508 [ V_44 ] = NULL ;
}
return F_302 ( V_506 ) ;
}
if ( ! V_44 )
F_303 ( V_506 -> V_512 , V_4 -> V_12 ) ;
V_4 -> V_508 [ V_44 ] = V_506 ;
}
return 0 ;
}
static void F_205 ( struct V_3 * V_4 )
{
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < F_151 ( V_508 ) ; V_44 ++ ) {
if ( V_4 -> V_508 [ V_44 ] ) {
F_301 ( V_4 -> V_508 [ V_44 ] ) ;
V_4 -> V_508 [ V_44 ] = NULL ;
}
}
}
static int F_304 ( struct V_513 * V_514 , void * V_84 )
{
struct V_515 * V_410 = (struct V_515 * ) V_514 -> V_516 ;
struct V_1 * V_2 = V_410 -> V_153 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_56 = 0 , V_44 ;
for ( V_44 = 0 ; V_44 < V_294 ; V_44 ++ ) {
struct V_388 * V_389 = V_4 -> V_407 [ V_44 ] ;
if ( ! V_389 || ! V_389 -> V_408 . V_409 )
continue;
F_250 ( V_389 -> V_408 . V_409 ) ;
}
F_305 ( V_514 , L_104 ) ;
V_56 = F_184 ( V_4 ) ;
if ( V_56 )
F_305 ( V_514 , L_105 , V_56 ) ;
else
F_305 ( V_514 , L_106 ) ;
for ( V_44 = 0 ; V_44 < V_294 ; V_44 ++ ) {
struct V_388 * V_389 = V_4 -> V_407 [ V_44 ] ;
if ( ! V_389 || ! V_389 -> V_408 . V_409 )
continue;
F_252 ( V_389 -> V_408 . V_409 ) ;
}
return 0 ;
}
static int F_188 ( struct V_3 * V_4 )
{
return F_273 ( V_4 ,
V_517 , 1 ) ;
}
int F_306 ( struct V_504 * V_153 )
{
return 0 ;
}
static int F_188 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_187 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_205 ( struct V_3 * V_4 ) { }
