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
V_33 ,
NULL , NULL , & V_4 -> V_28 . V_29 ) ;
if ( V_27 ) {
return V_27 ;
}
}
V_27 = F_24 ( V_4 -> V_28 . V_29 , false ) ;
if ( F_25 ( V_27 != 0 ) )
return V_27 ;
V_27 = F_26 ( V_4 -> V_28 . V_29 ,
V_32 , & V_4 -> V_28 . V_34 ) ;
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
const T_2 * V_35 ,
const T_2 V_36 )
{
T_2 V_37 , V_8 , V_38 , V_39 ;
int V_40 ;
if ( V_36 % 3 )
return;
for ( V_40 = 0 ; V_40 < V_36 ; V_40 += 3 ) {
V_8 = V_35 [ V_40 + 0 ] ;
V_38 = V_35 [ V_40 + 1 ] ;
V_39 = V_35 [ V_40 + 2 ] ;
if ( V_38 == 0xffffffff ) {
V_37 = V_39 ;
} else {
V_37 = F_35 ( V_8 ) ;
V_37 &= ~ V_38 ;
V_37 |= V_39 ;
}
F_36 ( V_8 , V_37 ) ;
}
}
void F_37 ( struct V_3 * V_4 )
{
F_38 ( V_4 -> V_17 , 0x7c , V_41 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
V_4 -> V_23 . V_42 = F_40 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_23 . V_43 = F_41 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_23 . V_24 = F_42 ( T_2 , V_4 -> V_23 . V_43 / sizeof( T_2 ) ,
V_44 + 1 ) ;
if ( V_4 -> V_23 . V_24 == 0 )
return - V_45 ;
V_4 -> V_23 . V_25 = F_43 ( V_4 -> V_23 . V_42 , V_4 -> V_23 . V_24 * sizeof( T_2 ) ) ;
if ( V_4 -> V_23 . V_25 == NULL ) {
return - V_46 ;
}
F_44 ( L_7 , ( T_1 ) V_4 -> V_23 . V_42 ) ;
F_44 ( L_8 , ( unsigned ) V_4 -> V_23 . V_43 ) ;
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
F_46 ( V_4 -> V_23 . V_25 ) ;
V_4 -> V_23 . V_25 = NULL ;
}
void F_47 ( struct V_3 * V_4 ,
T_3 * V_47 ,
T_4 * V_48 ,
T_4 * V_49 )
{
if ( V_4 -> V_23 . V_43 > V_4 -> V_23 . V_24 * sizeof( T_2 ) ) {
* V_47 = V_4 -> V_23 . V_42 ;
* V_48 = V_4 -> V_23 . V_43 ;
* V_49 = V_4 -> V_23 . V_24 * sizeof( T_2 ) ;
} else {
* V_47 = 0 ;
* V_48 = 0 ;
* V_49 = 0 ;
}
}
static void F_48 ( struct V_3 * V_4 )
{
if ( V_4 -> V_50 . V_51 ) {
if ( ! F_24 ( V_4 -> V_50 . V_51 , false ) ) {
F_32 ( V_4 -> V_50 . V_51 ) ;
F_29 ( V_4 -> V_50 . V_51 ) ;
F_27 ( V_4 -> V_50 . V_51 ) ;
}
F_33 ( & V_4 -> V_50 . V_51 ) ;
V_4 -> V_50 . V_50 = NULL ;
V_4 -> V_50 . V_51 = NULL ;
}
}
static int F_49 ( struct V_3 * V_4 )
{
int V_27 ;
if ( V_4 -> V_50 . V_51 == NULL ) {
V_27 = F_23 ( V_4 , V_52 * 4 , V_31 , true ,
V_53 , 0 , NULL , NULL ,
& V_4 -> V_50 . V_51 ) ;
if ( V_27 ) {
F_50 ( V_4 -> V_2 , L_9 , V_27 ) ;
return V_27 ;
}
V_27 = F_24 ( V_4 -> V_50 . V_51 , false ) ;
if ( F_25 ( V_27 != 0 ) ) {
F_48 ( V_4 ) ;
return V_27 ;
}
V_27 = F_26 ( V_4 -> V_50 . V_51 , V_53 ,
& V_4 -> V_50 . V_34 ) ;
if ( V_27 ) {
F_27 ( V_4 -> V_50 . V_51 ) ;
F_50 ( V_4 -> V_2 , L_10 , V_27 ) ;
F_48 ( V_4 ) ;
return V_27 ;
}
V_27 = F_28 ( V_4 -> V_50 . V_51 , ( void * * ) & V_4 -> V_50 . V_50 ) ;
F_27 ( V_4 -> V_50 . V_51 ) ;
if ( V_27 ) {
F_50 ( V_4 -> V_2 , L_11 , V_27 ) ;
F_48 ( V_4 ) ;
return V_27 ;
}
V_4 -> V_50 . V_54 = V_52 ;
memset ( & V_4 -> V_50 . V_55 , 0 , sizeof( V_4 -> V_50 . V_55 ) ) ;
memset ( ( char * ) V_4 -> V_50 . V_50 , 0 , V_30 ) ;
}
return 0 ;
}
int F_51 ( struct V_3 * V_4 , T_2 * V_50 )
{
unsigned long V_56 = F_52 ( V_4 -> V_50 . V_55 , V_4 -> V_50 . V_54 ) ;
if ( V_56 < V_4 -> V_50 . V_54 ) {
F_53 ( V_56 , V_4 -> V_50 . V_55 ) ;
* V_50 = V_56 ;
return 0 ;
} else {
return - V_45 ;
}
}
void F_54 ( struct V_3 * V_4 , T_2 V_50 )
{
if ( V_50 < V_4 -> V_50 . V_54 )
F_55 ( V_50 , V_4 -> V_50 . V_55 ) ;
}
void F_56 ( struct V_3 * V_4 , struct V_57 * V_58 , T_5 V_42 )
{
T_6 V_59 = ( T_6 ) V_60 << 20 ;
V_58 -> V_61 = V_42 ;
if ( V_58 -> V_62 > ( V_4 -> V_58 . V_63 - V_42 + 1 ) ) {
F_50 ( V_4 -> V_2 , L_12 ) ;
V_58 -> V_64 = V_58 -> V_65 ;
V_58 -> V_62 = V_58 -> V_65 ;
}
V_58 -> V_66 = V_58 -> V_61 + V_58 -> V_62 - 1 ;
if ( V_59 && V_59 < V_58 -> V_64 )
V_58 -> V_64 = V_59 ;
F_57 ( V_4 -> V_2 , L_13 ,
V_58 -> V_62 >> 20 , V_58 -> V_61 ,
V_58 -> V_66 , V_58 -> V_64 >> 20 ) ;
}
void F_58 ( struct V_3 * V_4 , struct V_57 * V_58 )
{
T_5 V_67 , V_68 ;
V_67 = ( ( V_4 -> V_58 . V_63 - V_58 -> V_66 ) + V_58 -> V_69 ) & ~ V_58 -> V_69 ;
V_68 = V_58 -> V_61 & ~ V_58 -> V_69 ;
if ( V_68 > V_67 ) {
if ( V_58 -> V_70 > V_68 ) {
F_50 ( V_4 -> V_2 , L_14 ) ;
V_58 -> V_70 = V_68 ;
}
V_58 -> V_71 = ( V_58 -> V_61 & ~ V_58 -> V_69 ) - V_58 -> V_70 ;
} else {
if ( V_58 -> V_70 > V_67 ) {
F_50 ( V_4 -> V_2 , L_14 ) ;
V_58 -> V_70 = V_67 ;
}
V_58 -> V_71 = ( V_58 -> V_66 + 1 + V_58 -> V_69 ) & ~ V_58 -> V_69 ;
}
V_58 -> V_72 = V_58 -> V_71 + V_58 -> V_70 - 1 ;
F_57 ( V_4 -> V_2 , L_15 ,
V_58 -> V_70 >> 20 , V_58 -> V_71 , V_58 -> V_72 ) ;
}
bool F_59 ( struct V_3 * V_4 )
{
T_1 V_8 ;
V_8 = F_35 ( V_73 ) ;
if ( V_8 )
return true ;
return false ;
}
static bool F_60 ( struct V_3 * V_4 )
{
if ( F_61 ( V_4 ) )
return false ;
if ( F_62 ( V_4 ) ) {
if ( V_4 -> V_74 == V_75 ) {
int V_76 ;
T_1 V_77 ;
V_76 = F_63 ( & V_4 -> V_78 . V_79 , L_16 , V_4 -> V_2 ) ;
if ( V_76 )
return true ;
V_77 = * ( ( T_1 * ) V_4 -> V_78 . V_79 -> V_80 + 69 ) ;
if ( V_77 < 0x00160e00 )
return true ;
}
}
return ! F_59 ( V_4 ) ;
}
int F_64 ( struct V_3 * V_4 )
{
if ( V_4 -> V_81 . V_82 )
return 0 ;
V_4 -> V_81 . V_82 = F_65 ( V_83 | V_84 | V_85 ) ;
if ( V_4 -> V_81 . V_82 == NULL )
return - V_46 ;
V_4 -> V_81 . V_86 = F_66 ( V_4 -> V_17 , V_4 -> V_81 . V_82 ,
0 , V_31 , V_87 ) ;
if ( F_67 ( V_4 -> V_17 , V_4 -> V_81 . V_86 ) ) {
F_68 ( & V_4 -> V_17 -> V_2 , L_17 ) ;
F_69 ( V_4 -> V_81 . V_82 ) ;
V_4 -> V_81 . V_82 = NULL ;
return - V_46 ;
}
return 0 ;
}
void F_70 ( struct V_3 * V_4 )
{
if ( V_4 -> V_81 . V_82 == NULL )
return;
F_71 ( V_4 -> V_17 , V_4 -> V_81 . V_86 ,
V_31 , V_87 ) ;
F_69 ( V_4 -> V_81 . V_82 ) ;
V_4 -> V_81 . V_82 = NULL ;
}
static T_1 F_72 ( struct V_88 * V_89 , T_1 V_8 )
{
return 0 ;
}
static void F_73 ( struct V_88 * V_89 , T_1 V_8 , T_1 V_90 )
{
}
static T_1 F_74 ( struct V_88 * V_89 , T_1 V_8 )
{
return 0 ;
}
static void F_75 ( struct V_88 * V_89 , T_1 V_8 , T_1 V_90 )
{
}
static void F_76 ( struct V_88 * V_89 , T_1 V_8 , T_1 V_90 )
{
struct V_3 * V_4 = V_89 -> V_2 -> V_5 ;
F_36 ( V_8 , V_90 ) ;
}
static T_1 F_77 ( struct V_88 * V_89 , T_1 V_8 )
{
struct V_3 * V_4 = V_89 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_35 ( V_8 ) ;
return V_27 ;
}
static void F_78 ( struct V_88 * V_89 , T_1 V_8 , T_1 V_90 )
{
struct V_3 * V_4 = V_89 -> V_2 -> V_5 ;
F_79 ( V_8 , V_90 ) ;
}
static T_1 F_80 ( struct V_88 * V_89 , T_1 V_8 )
{
struct V_3 * V_4 = V_89 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_81 ( V_8 ) ;
return V_27 ;
}
static void F_82 ( struct V_3 * V_4 )
{
if ( V_4 -> V_91 . V_92 ) {
F_83 ( V_4 -> V_91 . V_92 -> V_93 ) ;
F_83 ( V_4 -> V_91 . V_92 -> V_94 ) ;
}
F_83 ( V_4 -> V_91 . V_92 ) ;
V_4 -> V_91 . V_92 = NULL ;
F_83 ( V_4 -> V_91 . V_95 ) ;
V_4 -> V_91 . V_95 = NULL ;
}
static int F_84 ( struct V_3 * V_4 )
{
struct V_88 * V_95 =
F_85 ( sizeof( struct V_88 ) , V_84 ) ;
if ( ! V_95 )
return - V_46 ;
V_4 -> V_91 . V_95 = V_95 ;
V_95 -> V_2 = V_4 -> V_96 ;
V_95 -> V_97 = F_77 ;
V_95 -> V_98 = F_76 ;
if ( V_4 -> V_21 ) {
V_95 -> V_99 = F_80 ;
V_95 -> V_100 = F_78 ;
} else {
F_15 ( L_18 ) ;
V_95 -> V_99 = F_77 ;
V_95 -> V_100 = F_76 ;
}
V_95 -> V_101 = F_74 ;
V_95 -> V_102 = F_75 ;
V_95 -> V_103 = F_72 ;
V_95 -> V_104 = F_73 ;
V_4 -> V_91 . V_92 = F_86 ( V_95 , V_4 -> V_105 ) ;
if ( ! V_4 -> V_91 . V_92 ) {
F_82 ( V_4 ) ;
return - V_46 ;
}
F_87 ( & V_4 -> V_91 . V_92 -> V_106 ) ;
F_88 ( V_4 ) ;
F_89 ( V_4 -> V_91 . V_92 ) ;
return 0 ;
}
static unsigned int F_90 ( void * V_107 , bool V_108 )
{
struct V_3 * V_4 = V_107 ;
F_91 ( V_4 , V_108 ) ;
if ( V_108 )
return V_109 | V_110 |
V_111 | V_112 ;
else
return V_111 | V_112 ;
}
static bool F_92 ( int V_113 )
{
return ( V_113 & ( V_113 - 1 ) ) == 0 ;
}
static void F_93 ( struct V_3 * V_4 )
{
if ( V_114 < 4 ) {
F_50 ( V_4 -> V_2 , L_19 ,
V_114 ) ;
V_114 = 4 ;
} else if ( ! F_92 ( V_114 ) ) {
F_50 ( V_4 -> V_2 , L_20 ,
V_114 ) ;
V_114 = F_94 ( V_114 ) ;
}
if ( V_115 != - 1 ) {
if ( V_115 < 32 ) {
F_50 ( V_4 -> V_2 , L_21 ,
V_115 ) ;
V_115 = - 1 ;
}
}
if ( ! F_92 ( V_116 ) ) {
F_50 ( V_4 -> V_2 , L_22 ,
V_116 ) ;
V_116 = 8 ;
}
if ( V_116 < 1 ) {
F_50 ( V_4 -> V_2 , L_23 ,
V_116 ) ;
V_116 = 8 ;
}
if ( V_116 > 1024 ) {
F_50 ( V_4 -> V_2 , L_24 ,
V_116 ) ;
V_116 = 8 ;
}
if ( V_117 == - 1 ) {
unsigned V_118 = F_95 ( V_116 ) + 18 ;
if ( V_116 <= 8 )
V_117 = V_118 - 9 ;
else
V_117 = ( V_118 + 3 ) / 2 ;
} else if ( V_117 < 9 ) {
F_50 ( V_4 -> V_2 , L_25 ,
V_117 ) ;
V_117 = 9 ;
}
if ( V_117 > 24 ||
( V_116 * 1024 ) < ( 1ull << V_117 ) ) {
F_50 ( V_4 -> V_2 , L_26 ,
V_117 ) ;
V_117 = 9 ;
}
}
static void F_96 ( struct V_119 * V_17 , enum V_120 V_108 )
{
struct V_1 * V_2 = F_97 ( V_17 ) ;
if ( F_1 ( V_2 ) && V_108 == V_121 )
return;
if ( V_108 == V_122 ) {
unsigned V_123 = V_2 -> V_17 -> V_123 ;
F_98 ( V_124 L_27 ) ;
V_2 -> V_125 = V_126 ;
F_99 ( V_2 , true , true ) ;
V_2 -> V_17 -> V_123 = V_123 ;
V_2 -> V_125 = V_127 ;
F_100 ( V_2 ) ;
} else {
F_98 ( V_124 L_28 ) ;
F_101 ( V_2 ) ;
V_2 -> V_125 = V_126 ;
F_102 ( V_2 , true , true ) ;
V_2 -> V_125 = V_128 ;
}
}
static bool F_103 ( struct V_119 * V_17 )
{
struct V_1 * V_2 = F_97 ( V_17 ) ;
return V_2 -> V_129 == 0 ;
}
int F_104 ( struct V_3 * V_4 ,
enum V_130 V_131 ,
enum V_132 V_108 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_131 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_138 ( ( void * ) V_4 ,
V_108 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_105 ( struct V_3 * V_4 ,
enum V_130 V_131 ,
enum V_139 V_108 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_131 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_140 ( ( void * ) V_4 ,
V_108 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_106 ( struct V_3 * V_4 ,
enum V_130 V_131 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_131 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_141 ( ( void * ) V_4 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return 0 ;
}
bool F_107 ( struct V_3 * V_4 ,
enum V_130 V_131 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_131 )
return V_4 -> V_136 [ V_40 ] . V_137 -> V_142 ( ( void * ) V_4 ) ;
}
return true ;
}
const struct V_143 * F_108 (
struct V_3 * V_4 ,
enum V_130 type )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ )
if ( V_4 -> V_136 [ V_40 ] . type == type )
return & V_4 -> V_136 [ V_40 ] ;
return NULL ;
}
int F_109 ( struct V_3 * V_4 ,
enum V_130 type ,
T_2 V_144 , T_2 V_145 )
{
const struct V_143 * V_146 ;
V_146 = F_108 ( V_4 , type ) ;
if ( V_146 && ( ( V_146 -> V_144 > V_144 ) ||
( ( V_146 -> V_144 == V_144 ) &&
( V_146 -> V_145 >= V_145 ) ) ) )
return 0 ;
return 1 ;
}
static void F_110 ( struct V_3 * V_4 )
{
V_4 -> V_147 = false ;
if ( V_148 ) {
struct V_1 * V_96 = V_4 -> V_96 ;
const char * V_149 = F_111 ( V_96 -> V_17 ) ;
char * V_150 , * V_151 , * V_152 ;
V_150 = F_112 ( V_148 , V_84 ) ;
V_151 = V_150 ;
while ( ( V_152 = F_113 ( & V_151 , L_29 ) ) ) {
if ( ! strcmp ( V_149 , V_152 ) ) {
V_4 -> V_147 = true ;
break;
}
}
F_44 ( L_30 ,
V_148 , V_149 ,
V_4 -> V_147 ) ;
F_83 ( V_150 ) ;
}
}
static int F_114 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
F_110 ( V_4 ) ;
switch ( V_4 -> V_74 ) {
case V_153 :
case V_154 :
case V_75 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
if ( V_4 -> V_74 == V_157 || V_4 -> V_74 == V_158 )
V_4 -> V_159 = V_160 ;
else
V_4 -> V_159 = V_161 ;
V_27 = F_115 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#ifdef F_116
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_4 -> V_159 = V_167 ;
V_27 = F_117 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
#ifdef F_118
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
if ( ( V_4 -> V_74 == V_168 ) || ( V_4 -> V_74 == V_169 ) )
V_4 -> V_159 = V_173 ;
else
V_4 -> V_159 = V_174 ;
V_27 = F_119 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
default:
return - V_45 ;
}
V_4 -> V_134 = F_120 ( V_4 -> V_133 ,
sizeof( struct V_175 ) , V_84 ) ;
if ( V_4 -> V_134 == NULL )
return - V_46 ;
if ( V_4 -> V_136 == NULL ) {
F_15 ( L_31 ) ;
return V_27 ;
}
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ( V_176 & ( 1 << V_40 ) ) == 0 ) {
F_15 ( L_32 , V_40 ) ;
V_4 -> V_134 [ V_40 ] . V_135 = false ;
} else {
if ( V_4 -> V_136 [ V_40 ] . V_137 -> V_177 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_177 ( ( void * ) V_4 ) ;
if ( V_27 == - V_178 ) {
V_4 -> V_134 [ V_40 ] . V_135 = false ;
} else if ( V_27 ) {
F_15 ( L_33 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
} else {
V_4 -> V_134 [ V_40 ] . V_135 = true ;
}
} else {
V_4 -> V_134 [ V_40 ] . V_135 = true ;
}
}
}
V_4 -> V_180 &= V_181 ;
V_4 -> V_182 &= V_183 ;
return 0 ;
}
static int F_121 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_184 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_34 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
V_4 -> V_134 [ V_40 ] . V_185 = true ;
if ( V_4 -> V_136 [ V_40 ] . type == V_186 ) {
V_27 = F_22 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_35 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_187 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_36 , V_40 , V_27 ) ;
return V_27 ;
}
V_27 = F_49 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_37 , V_27 ) ;
return V_27 ;
}
V_4 -> V_134 [ V_40 ] . V_188 = true ;
}
}
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_185 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_186 )
continue;
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_187 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_38 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
V_4 -> V_134 [ V_40 ] . V_188 = true ;
}
return 0 ;
}
static int F_122 ( struct V_3 * V_4 )
{
int V_40 = 0 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_136 [ V_40 ] . V_137 -> V_189 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_189 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_39 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
V_4 -> V_134 [ V_40 ] . V_190 = true ;
}
if ( V_4 -> V_136 [ V_40 ] . type != V_191 &&
V_4 -> V_136 [ V_40 ] . type != V_192 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_138 ( ( void * ) V_4 ,
V_193 ) ;
if ( V_27 ) {
F_15 ( L_40 ,
V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
}
}
return 0 ;
}
static int F_123 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_188 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_194 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_138 ( ( void * ) V_4 ,
V_195 ) ;
if ( V_27 ) {
F_15 ( L_41 ,
V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_196 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_124 ( L_42 ,
V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
}
V_4 -> V_134 [ V_40 ] . V_188 = false ;
break;
}
}
for ( V_40 = V_4 -> V_133 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_188 )
continue;
if ( V_4 -> V_136 [ V_40 ] . type == V_186 ) {
F_48 ( V_4 ) ;
F_30 ( V_4 ) ;
}
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_138 ( ( void * ) V_4 ,
V_195 ) ;
if ( V_27 ) {
F_15 ( L_41 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_196 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_124 ( L_42 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
}
V_4 -> V_134 [ V_40 ] . V_188 = false ;
}
for ( V_40 = V_4 -> V_133 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_185 )
continue;
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_197 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_124 ( L_43 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
}
V_4 -> V_134 [ V_40 ] . V_185 = false ;
V_4 -> V_134 [ V_40 ] . V_135 = false ;
}
for ( V_40 = V_4 -> V_133 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_190 )
continue;
if ( V_4 -> V_136 [ V_40 ] . V_137 -> V_198 )
V_4 -> V_136 [ V_40 ] . V_137 -> V_198 ( ( void * ) V_4 ) ;
V_4 -> V_134 [ V_40 ] . V_190 = false ;
}
return 0 ;
}
int F_125 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
V_27 = F_104 ( V_4 , V_194 ,
V_195 ) ;
if ( V_27 ) {
F_15 ( L_44 , V_27 ) ;
}
for ( V_40 = V_4 -> V_133 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_40 != V_194 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_138 ( ( void * ) V_4 ,
V_195 ) ;
if ( V_27 ) {
F_15 ( L_41 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
}
}
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_199 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_45 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
}
}
return 0 ;
}
static int F_126 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_200 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_46 , V_4 -> V_136 [ V_40 ] . V_137 -> V_179 , V_27 ) ;
return V_27 ;
}
}
return 0 ;
}
static void F_127 ( struct V_3 * V_4 )
{
if ( F_128 ( V_4 ) )
V_4 -> V_201 . V_202 |= V_203 ;
}
int F_129 ( struct V_3 * V_4 ,
struct V_1 * V_96 ,
struct V_119 * V_17 ,
T_1 V_6 )
{
int V_27 , V_40 ;
bool V_204 = false ;
T_2 V_205 ;
V_4 -> V_206 = false ;
V_4 -> V_2 = & V_17 -> V_2 ;
V_4 -> V_96 = V_96 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_74 = V_6 & V_207 ;
V_4 -> V_208 = false ;
V_4 -> V_209 = V_210 ;
V_4 -> V_58 . V_70 = 512 * 1024 * 1024 ;
V_4 -> V_211 = false ;
V_4 -> V_212 = 0 ;
V_4 -> V_213 . V_214 = NULL ;
V_4 -> V_213 . V_215 = NULL ;
V_4 -> V_216 . V_217 = NULL ;
V_4 -> V_216 . V_218 = 0 ;
V_4 -> V_219 . V_220 = NULL ;
V_4 -> V_221 = F_130 ( V_222 ) ;
V_4 -> V_223 = & F_17 ;
V_4 -> V_224 = & F_19 ;
V_4 -> V_225 = & F_17 ;
V_4 -> V_226 = & F_19 ;
V_4 -> V_227 = & F_17 ;
V_4 -> V_228 = & F_19 ;
V_4 -> V_229 = & F_17 ;
V_4 -> V_230 = & F_19 ;
V_4 -> V_231 = & F_17 ;
V_4 -> V_232 = & F_19 ;
V_4 -> V_233 = & F_17 ;
V_4 -> V_234 = & F_19 ;
V_4 -> V_235 = & F_20 ;
V_4 -> V_236 = & F_21 ;
F_44 ( L_47 ,
V_237 [ V_4 -> V_74 ] , V_17 -> V_238 , V_17 -> V_18 ,
V_17 -> V_239 , V_17 -> V_240 , V_17 -> V_241 ) ;
F_87 ( & V_4 -> V_216 . V_242 ) ;
F_131 ( & V_4 -> V_243 . V_244 . V_242 , 0 ) ;
F_87 ( & V_4 -> V_78 . V_106 ) ;
F_87 ( & V_4 -> V_245 . V_246 ) ;
F_87 ( & V_4 -> V_247 ) ;
F_87 ( & V_4 -> V_248 ) ;
F_87 ( & V_4 -> V_249 ) ;
F_132 ( V_4 -> V_250 ) ;
F_93 ( V_4 ) ;
F_133 ( & V_4 -> V_14 ) ;
F_133 ( & V_4 -> V_251 ) ;
F_133 ( & V_4 -> V_252 ) ;
F_133 ( & V_4 -> V_253 ) ;
F_133 ( & V_4 -> V_254 ) ;
F_133 ( & V_4 -> V_255 ) ;
F_133 ( & V_4 -> V_256 ) ;
F_133 ( & V_4 -> V_257 . V_242 ) ;
F_134 ( & V_4 -> V_258 ) ;
F_87 ( & V_4 -> V_259 ) ;
F_134 ( & V_4 -> V_260 ) ;
F_133 ( & V_4 -> V_261 ) ;
if ( V_4 -> V_74 >= V_168 ) {
V_4 -> V_262 = F_40 ( V_4 -> V_17 , 5 ) ;
V_4 -> V_11 = F_41 ( V_4 -> V_17 , 5 ) ;
} else {
V_4 -> V_262 = F_40 ( V_4 -> V_17 , 2 ) ;
V_4 -> V_11 = F_41 ( V_4 -> V_17 , 2 ) ;
}
V_4 -> V_13 = F_43 ( V_4 -> V_262 , V_4 -> V_11 ) ;
if ( V_4 -> V_13 == NULL ) {
return - V_46 ;
}
F_44 ( L_48 , ( T_1 ) V_4 -> V_262 ) ;
F_44 ( L_49 , ( unsigned ) V_4 -> V_11 ) ;
if ( V_4 -> V_74 >= V_168 )
F_39 ( V_4 ) ;
for ( V_40 = 0 ; V_40 < V_263 ; V_40 ++ ) {
if ( F_135 ( V_4 -> V_17 , V_40 ) & V_264 ) {
V_4 -> V_20 = F_41 ( V_4 -> V_17 , V_40 ) ;
V_4 -> V_21 = F_136 ( V_4 -> V_17 , V_40 , V_4 -> V_20 ) ;
break;
}
}
if ( V_4 -> V_21 == NULL )
F_15 ( L_50 ) ;
V_27 = F_114 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_137 ( V_4 -> V_17 , V_4 , NULL , F_90 ) ;
if ( V_265 == 1 )
V_204 = true ;
if ( F_1 ( V_96 ) )
V_204 = true ;
F_138 ( V_4 -> V_17 , & V_266 , V_204 ) ;
if ( V_204 )
F_139 ( V_4 -> V_2 , & V_4 -> V_267 ) ;
if ( ! F_140 ( V_4 ) ) {
V_27 = - V_45 ;
goto V_268;
}
if ( ! V_4 -> V_208 ) {
F_68 ( V_4 -> V_2 , L_51 ) ;
V_27 = - V_45 ;
goto V_268;
}
V_27 = F_84 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_52 ) ;
goto V_268;
}
F_127 ( V_4 ) ;
if ( F_60 ( V_4 ) ) {
if ( ! V_4 -> V_105 ) {
F_68 ( V_4 -> V_2 , L_53 ) ;
V_27 = - V_45 ;
goto V_268;
}
F_44 ( L_54 ) ;
V_27 = F_141 ( V_4 -> V_91 . V_92 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_55 ) ;
goto V_268;
}
} else {
F_44 ( L_56 ) ;
}
V_27 = F_142 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_57 ) ;
goto V_268;
}
F_143 ( V_4 ) ;
V_27 = F_144 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_58 ) ;
goto V_268;
}
F_145 ( V_4 -> V_96 ) ;
V_27 = F_121 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_59 ) ;
F_123 ( V_4 ) ;
goto V_268;
}
V_4 -> V_211 = true ;
if ( V_269 >= 0 )
V_205 = V_269 ;
else
V_205 = 8 ;
V_4 -> V_257 . V_270 = F_95 ( F_146 ( 1u , V_205 ) ) ;
F_147 ( V_4 ) ;
V_27 = F_148 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_60 , V_27 ) ;
goto V_268;
}
V_27 = F_149 ( V_4 ) ;
if ( V_27 )
F_15 ( L_61 , V_27 ) ;
V_27 = F_150 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_62 , V_27 ) ;
}
V_27 = F_151 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_63 , V_27 ) ;
}
V_27 = F_152 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_64 , V_27 ) ;
return V_27 ;
}
if ( ( V_271 & 1 ) ) {
if ( V_4 -> V_211 )
F_153 ( V_4 ) ;
else
F_44 ( L_65 ) ;
}
if ( ( V_271 & 2 ) ) {
if ( V_4 -> V_211 )
F_154 ( V_4 ) ;
else
F_44 ( L_66 ) ;
}
if ( V_272 ) {
if ( V_4 -> V_211 )
F_155 ( V_4 , V_272 ) ;
else
F_44 ( L_67 ) ;
}
V_27 = F_122 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_68 ) ;
goto V_268;
}
return 0 ;
V_268:
if ( V_204 )
F_156 ( V_4 -> V_2 ) ;
return V_27 ;
}
void F_157 ( struct V_3 * V_4 )
{
int V_27 ;
F_44 ( L_69 ) ;
V_4 -> V_206 = true ;
F_158 ( V_4 -> V_96 ) ;
F_159 ( V_4 ) ;
F_160 ( V_4 ) ;
F_161 ( V_4 ) ;
F_162 ( V_4 ) ;
V_27 = F_123 ( V_4 ) ;
F_83 ( V_4 -> V_134 ) ;
V_4 -> V_134 = NULL ;
V_4 -> V_211 = false ;
F_163 ( V_4 ) ;
F_82 ( V_4 ) ;
F_83 ( V_4 -> V_105 ) ;
V_4 -> V_105 = NULL ;
F_164 ( V_4 -> V_17 ) ;
if ( V_4 -> V_6 & V_7 )
F_156 ( V_4 -> V_2 ) ;
F_137 ( V_4 -> V_17 , NULL , NULL , NULL ) ;
if ( V_4 -> V_21 )
F_165 ( V_4 -> V_17 , V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
F_46 ( V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
if ( V_4 -> V_74 >= V_168 )
F_45 ( V_4 ) ;
F_166 ( V_4 ) ;
F_167 ( V_4 ) ;
}
int F_102 ( struct V_1 * V_2 , bool V_199 , bool V_273 )
{
struct V_3 * V_4 ;
struct V_274 * V_275 ;
struct V_276 * V_277 ;
int V_27 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_278 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_125 == V_128 )
return 0 ;
F_101 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 (connector, &dev->mode_config.connector_list, head) {
F_170 ( V_277 , V_279 ) ;
}
F_171 ( V_2 ) ;
F_169 (crtc, &dev->mode_config.crtc_list, head) {
struct V_280 * V_280 = F_172 ( V_275 ) ;
struct V_281 * V_282 = F_173 ( V_275 -> V_283 -> V_284 ) ;
struct V_285 * V_29 ;
if ( V_280 -> V_286 ) {
struct V_285 * V_287 = F_174 ( V_280 -> V_286 ) ;
V_27 = F_24 ( V_287 , false ) ;
if ( V_27 == 0 ) {
F_29 ( V_287 ) ;
F_27 ( V_287 ) ;
}
}
if ( V_282 == NULL || V_282 -> V_288 == NULL ) {
continue;
}
V_29 = F_174 ( V_282 -> V_288 ) ;
if ( ! F_175 ( V_4 , V_29 ) ) {
V_27 = F_24 ( V_29 , false ) ;
if ( V_27 == 0 ) {
F_29 ( V_29 ) ;
F_27 ( V_29 ) ;
}
}
}
F_159 ( V_4 ) ;
F_176 ( V_4 ) ;
V_27 = F_125 ( V_4 ) ;
F_159 ( V_4 ) ;
F_177 ( V_4 ) ;
F_178 ( V_2 -> V_17 ) ;
if ( V_199 ) {
F_179 ( V_2 -> V_17 ) ;
F_180 ( V_2 -> V_17 , V_289 ) ;
} else {
V_27 = F_181 ( V_4 ) ;
if ( V_27 )
F_15 ( L_70 ) ;
}
if ( V_273 ) {
F_182 () ;
F_183 ( V_4 , 1 ) ;
F_184 () ;
}
return 0 ;
}
int F_99 ( struct V_1 * V_2 , bool V_200 , bool V_273 )
{
struct V_276 * V_277 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_274 * V_275 ;
int V_27 ;
if ( V_2 -> V_125 == V_128 )
return 0 ;
if ( V_273 )
F_182 () ;
if ( V_200 ) {
F_180 ( V_2 -> V_17 , V_290 ) ;
F_185 ( V_2 -> V_17 ) ;
V_27 = F_186 ( V_2 -> V_17 ) ;
if ( V_27 ) {
if ( V_273 )
F_184 () ;
return V_27 ;
}
}
F_187 ( V_4 ) ;
if ( ! F_59 ( V_4 ) || ! V_200 ) {
V_27 = F_141 ( V_4 -> V_91 . V_92 ) ;
if ( V_27 )
F_15 ( L_71 ) ;
}
V_27 = F_126 ( V_4 ) ;
if ( V_27 )
F_15 ( L_72 , V_27 ) ;
F_188 ( V_4 ) ;
if ( V_200 ) {
V_27 = F_149 ( V_4 ) ;
if ( V_27 )
F_15 ( L_61 , V_27 ) ;
}
V_27 = F_122 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_169 (crtc, &dev->mode_config.crtc_list, head) {
struct V_280 * V_280 = F_172 ( V_275 ) ;
if ( V_280 -> V_286 ) {
struct V_285 * V_287 = F_174 ( V_280 -> V_286 ) ;
V_27 = F_24 ( V_287 , false ) ;
if ( V_27 == 0 ) {
V_27 = F_26 ( V_287 ,
V_32 ,
& V_280 -> V_291 ) ;
if ( V_27 != 0 )
F_15 ( L_73 , V_27 ) ;
F_27 ( V_287 ) ;
}
}
}
if ( V_273 ) {
F_189 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 (connector, &dev->mode_config.connector_list, head) {
F_170 ( V_277 , V_292 ) ;
}
F_171 ( V_2 ) ;
}
F_100 ( V_2 ) ;
#ifdef F_190
V_2 -> V_2 -> V_293 . V_294 ++ ;
#endif
F_191 ( V_2 ) ;
#ifdef F_190
V_2 -> V_2 -> V_293 . V_294 -- ;
#endif
if ( V_273 ) {
F_183 ( V_4 , 0 ) ;
F_184 () ;
}
return 0 ;
}
static bool F_192 ( struct V_3 * V_4 )
{
int V_40 ;
bool V_295 = false ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_136 [ V_40 ] . V_137 -> V_296 )
V_4 -> V_134 [ V_40 ] . V_297 =
V_4 -> V_136 [ V_40 ] . V_137 -> V_296 ( V_4 ) ;
if ( V_4 -> V_134 [ V_40 ] . V_297 ) {
F_44 ( L_74 , V_40 ) ;
V_295 = true ;
}
}
return V_295 ;
}
static int F_193 ( struct V_3 * V_4 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_134 [ V_40 ] . V_297 &&
V_4 -> V_136 [ V_40 ] . V_137 -> V_298 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_298 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static bool F_194 ( struct V_3 * V_4 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( ( V_4 -> V_136 [ V_40 ] . type == V_186 ) ||
( V_4 -> V_136 [ V_40 ] . type == V_194 ) ||
( V_4 -> V_136 [ V_40 ] . type == V_299 ) ||
( V_4 -> V_136 [ V_40 ] . type == V_300 ) ) {
if ( V_4 -> V_134 [ V_40 ] . V_297 ) {
F_44 ( L_75 ) ;
return true ;
}
}
}
return false ;
}
static int F_195 ( struct V_3 * V_4 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_134 [ V_40 ] . V_297 &&
V_4 -> V_136 [ V_40 ] . V_137 -> V_301 ) {
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_301 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
}
return 0 ;
}
static int F_196 ( struct V_3 * V_4 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_133 ; V_40 ++ ) {
if ( ! V_4 -> V_134 [ V_40 ] . V_135 )
continue;
if ( V_4 -> V_134 [ V_40 ] . V_297 &&
V_4 -> V_136 [ V_40 ] . V_137 -> V_302 )
V_27 = V_4 -> V_136 [ V_40 ] . V_137 -> V_302 ( V_4 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
bool F_197 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 & V_303 )
return false ;
return V_304 > 0 ? true : false ;
}
static int F_198 ( struct V_3 * V_4 ,
struct V_305 * V_306 ,
struct V_285 * V_307 ,
struct V_308 * * V_308 )
{
T_1 V_309 ;
int V_27 ;
if ( ! V_307 -> V_310 )
return 0 ;
V_27 = F_24 ( V_307 , false ) ;
if ( V_27 )
return V_27 ;
V_309 = F_199 ( V_307 -> V_311 . V_312 . V_313 ) ;
if ( V_309 == V_32 ) {
V_27 = F_200 ( V_4 , V_306 , V_307 ,
NULL , V_308 , true ) ;
if ( V_27 ) {
F_15 ( L_76 ) ;
goto V_76;
}
}
V_76:
F_27 ( V_307 ) ;
return V_27 ;
}
int F_201 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
int V_314 ;
bool V_315 ;
if ( ! F_192 ( V_4 ) ) {
F_44 ( L_77 ) ;
return 0 ;
}
F_202 ( & V_4 -> V_316 ) ;
V_314 = F_203 ( & V_4 -> V_213 . V_317 ) ;
for ( V_40 = 0 ; V_40 < V_222 ; ++ V_40 ) {
struct V_305 * V_306 = V_4 -> V_318 [ V_40 ] ;
if ( ! V_306 )
continue;
F_204 ( V_306 -> V_319 . V_320 ) ;
F_205 ( & V_306 -> V_319 ) ;
}
F_206 ( V_4 ) ;
V_315 = F_194 ( V_4 ) ;
if ( ! V_315 ) {
F_193 ( V_4 ) ;
V_27 = F_195 ( V_4 ) ;
F_196 ( V_4 ) ;
if ( V_27 || F_192 ( V_4 ) ) {
F_44 ( L_78 ) ;
V_315 = true ;
}
}
if ( V_315 ) {
V_27 = F_125 ( V_4 ) ;
V_321:
if ( V_4 -> V_91 . V_322 ) {
struct V_323 V_324 ;
F_207 ( V_4 , & V_324 ) ;
F_106 ( V_4 , V_186 ) ;
}
F_177 ( V_4 ) ;
V_27 = F_181 ( V_4 ) ;
F_187 ( V_4 ) ;
F_141 ( V_4 -> V_91 . V_92 ) ;
if ( ! V_27 ) {
F_57 ( V_4 -> V_2 , L_79 ) ;
V_27 = F_126 ( V_4 ) ;
}
}
if ( ! V_27 ) {
F_208 ( V_4 ) ;
if ( V_315 && F_197 ( V_4 ) ) {
V_27 = F_209 ( V_4 ) ;
if ( V_27 )
F_15 ( L_80 ) ;
}
V_27 = F_149 ( V_4 ) ;
if ( V_27 ) {
F_68 ( V_4 -> V_2 , L_61 , V_27 ) ;
V_27 = F_125 ( V_4 ) ;
V_315 = true ;
goto V_321;
}
if ( V_315 && F_197 ( V_4 ) ) {
struct V_305 * V_306 = V_4 -> V_213 . V_215 ;
struct V_285 * V_307 , * V_37 ;
struct V_308 * V_308 = NULL , * V_325 = NULL ;
F_44 ( L_81 ) ;
F_210 ( & V_4 -> V_259 ) ;
F_211 (bo, tmp, &adev->shadow_list, shadow_list) {
F_198 ( V_4 , V_306 , V_307 , & V_325 ) ;
if ( V_308 ) {
V_27 = F_212 ( V_308 , false ) ;
if ( V_27 ) {
F_213 ( V_27 , L_82 ) ;
break;
}
}
F_214 ( V_308 ) ;
V_308 = V_325 ;
}
F_215 ( & V_4 -> V_259 ) ;
if ( V_308 ) {
V_27 = F_212 ( V_308 , false ) ;
if ( V_27 )
F_213 ( V_27 , L_82 ) ;
}
F_214 ( V_308 ) ;
}
for ( V_40 = 0 ; V_40 < V_222 ; ++ V_40 ) {
struct V_305 * V_306 = V_4 -> V_318 [ V_40 ] ;
if ( ! V_306 )
continue;
F_216 ( & V_306 -> V_319 ) ;
F_217 ( V_306 -> V_319 . V_320 ) ;
}
} else {
F_68 ( V_4 -> V_2 , L_83 , V_27 ) ;
for ( V_40 = 0 ; V_40 < V_222 ; ++ V_40 ) {
if ( V_4 -> V_318 [ V_40 ] ) {
F_217 ( V_4 -> V_318 [ V_40 ] -> V_319 . V_320 ) ;
}
}
}
F_189 ( V_4 -> V_96 ) ;
F_218 ( & V_4 -> V_213 . V_317 , V_314 ) ;
if ( V_27 ) {
F_57 ( V_4 -> V_2 , L_84 ) ;
}
return V_27 ;
}
void F_219 ( struct V_3 * V_4 )
{
T_2 V_326 ;
int V_10 ;
if ( V_327 )
V_4 -> V_78 . V_328 = V_327 ;
if ( V_329 )
V_4 -> V_78 . V_330 = V_329 ;
if ( F_220 ( V_4 -> V_17 -> V_331 ) ) {
if ( V_4 -> V_78 . V_328 == 0 )
V_4 -> V_78 . V_328 = V_332 ;
if ( V_4 -> V_78 . V_330 == 0 )
V_4 -> V_78 . V_330 = V_333 ;
return;
}
if ( V_4 -> V_78 . V_328 == 0 ) {
V_10 = F_221 ( V_4 -> V_96 , & V_326 ) ;
if ( ! V_10 ) {
V_4 -> V_78 . V_328 = ( V_334 |
V_335 |
V_336 ) ;
if ( V_326 & V_337 )
V_4 -> V_78 . V_328 |= V_338 ;
if ( V_326 & V_339 )
V_4 -> V_78 . V_328 |= V_340 ;
if ( V_326 & V_341 )
V_4 -> V_78 . V_328 |= V_342 ;
} else {
V_4 -> V_78 . V_328 = V_332 ;
}
}
if ( V_4 -> V_78 . V_330 == 0 ) {
V_10 = F_222 ( V_4 -> V_96 , & V_326 ) ;
if ( ! V_10 ) {
switch ( V_326 ) {
case 32 :
V_4 -> V_78 . V_330 = ( V_343 |
V_344 |
V_345 |
V_346 |
V_347 |
V_348 |
V_349 ) ;
break;
case 16 :
V_4 -> V_78 . V_330 = ( V_344 |
V_345 |
V_346 |
V_347 |
V_348 |
V_349 ) ;
break;
case 12 :
V_4 -> V_78 . V_330 = ( V_345 |
V_346 |
V_347 |
V_348 |
V_349 ) ;
break;
case 8 :
V_4 -> V_78 . V_330 = ( V_346 |
V_347 |
V_348 |
V_349 ) ;
break;
case 4 :
V_4 -> V_78 . V_330 = ( V_347 |
V_348 |
V_349 ) ;
break;
case 2 :
V_4 -> V_78 . V_330 = ( V_348 |
V_349 ) ;
break;
case 1 :
V_4 -> V_78 . V_330 = V_349 ;
break;
default:
break;
}
} else {
V_4 -> V_78 . V_330 = V_333 ;
}
}
}
int F_223 ( struct V_3 * V_4 ,
const struct V_350 * V_351 ,
unsigned V_352 )
{
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_353 ; V_40 ++ ) {
if ( V_4 -> V_354 [ V_40 ] . V_351 == V_351 ) {
return 0 ;
}
}
V_40 = V_4 -> V_353 + 1 ;
if ( V_40 > V_355 ) {
F_15 ( L_85 ) ;
F_15 ( L_86
L_87 ) ;
return - V_45 ;
}
V_4 -> V_354 [ V_4 -> V_353 ] . V_351 = V_351 ;
V_4 -> V_354 [ V_4 -> V_353 ] . V_356 = V_352 ;
V_4 -> V_353 = V_40 ;
#if F_224 ( V_357 )
F_225 ( V_351 , V_352 ,
V_4 -> V_96 -> V_358 -> V_359 ,
V_4 -> V_96 -> V_358 ) ;
F_225 ( V_351 , V_352 ,
V_4 -> V_96 -> V_283 -> V_359 ,
V_4 -> V_96 -> V_283 ) ;
#endif
return 0 ;
}
static void F_167 ( struct V_3 * V_4 )
{
#if F_224 ( V_357 )
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_353 ; V_40 ++ ) {
F_226 ( V_4 -> V_354 [ V_40 ] . V_351 ,
V_4 -> V_354 [ V_40 ] . V_356 ,
V_4 -> V_96 -> V_358 ) ;
F_226 ( V_4 -> V_354 [ V_40 ] . V_351 ,
V_4 -> V_354 [ V_40 ] . V_356 ,
V_4 -> V_96 -> V_283 ) ;
}
#endif
}
static T_7 F_227 ( struct V_360 * V_361 , char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
bool V_367 , V_368 ;
unsigned V_369 , V_370 , V_371 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
V_367 = ( * V_363 >> 23 ) & 1 ;
if ( * V_363 & ( 1ULL << 62 ) ) {
V_371 = ( * V_363 >> 24 ) & 0x3FF ;
V_370 = ( * V_363 >> 34 ) & 0x3FF ;
V_369 = ( * V_363 >> 44 ) & 0x3FF ;
V_368 = 1 ;
} else {
V_368 = 0 ;
}
* V_363 &= 0x3FFFF ;
if ( V_368 ) {
if ( V_370 >= V_4 -> V_245 . V_372 . V_373 ||
V_371 >= V_4 -> V_245 . V_372 . V_374 )
return - V_45 ;
F_210 ( & V_4 -> V_248 ) ;
F_228 ( V_4 , V_371 ,
V_370 , V_369 ) ;
}
if ( V_367 )
F_210 ( & V_4 -> V_78 . V_106 ) ;
while ( V_43 ) {
T_1 V_375 ;
if ( * V_363 > V_4 -> V_11 )
goto V_376;
V_375 = F_35 ( * V_363 >> 2 ) ;
V_27 = F_229 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 ) {
V_366 = V_27 ;
goto V_376;
}
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
V_376:
if ( V_368 ) {
F_228 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_215 ( & V_4 -> V_248 ) ;
}
if ( V_367 )
F_215 ( & V_4 -> V_78 . V_106 ) ;
return V_366 ;
}
static T_7 F_230 ( struct V_360 * V_361 , const char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
if ( * V_363 > V_4 -> V_11 )
return V_366 ;
V_27 = F_231 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
F_36 ( * V_363 >> 2 , V_375 ) ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_232 ( struct V_360 * V_361 , char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
V_375 = F_233 ( * V_363 >> 2 ) ;
V_27 = F_229 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_234 ( struct V_360 * V_361 , const char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
V_27 = F_231 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
F_235 ( * V_363 >> 2 , V_375 ) ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_236 ( struct V_360 * V_361 , char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
V_375 = F_237 ( * V_363 >> 2 ) ;
V_27 = F_229 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_238 ( struct V_360 * V_361 , const char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
V_27 = F_231 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
F_239 ( * V_363 >> 2 , V_375 ) ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_240 ( struct V_360 * V_361 , char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
V_375 = F_241 ( * V_363 ) ;
V_27 = F_229 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_242 ( struct V_360 * V_361 , const char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_375 ;
V_27 = F_231 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 )
return V_27 ;
F_243 ( * V_363 , V_375 ) ;
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
return V_366 ;
}
static T_7 F_244 ( struct V_360 * V_361 , char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
T_7 V_366 = 0 ;
int V_27 ;
T_1 * V_372 , V_377 = 0 ;
if ( V_43 & 0x3 || * V_363 & 0x3 )
return - V_45 ;
V_372 = F_245 ( 256 , sizeof( * V_372 ) , V_84 ) ;
if ( ! V_372 )
return - V_46 ;
V_372 [ V_377 ++ ] = 2 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_374 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_378 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_379 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_373 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_380 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_381 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_382 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_383 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_384 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_385 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_386 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_387 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_388 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_389 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_390 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_391 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_392 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_393 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_394 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_395 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_396 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_397 ;
V_372 [ V_377 ++ ] = V_4 -> V_245 . V_372 . V_398 ;
V_372 [ V_377 ++ ] = V_4 -> V_399 ;
V_372 [ V_377 ++ ] = V_4 -> V_182 ;
V_372 [ V_377 ++ ] = V_4 -> V_180 ;
V_372 [ V_377 ++ ] = V_4 -> V_159 ;
V_372 [ V_377 ++ ] = V_4 -> V_400 ;
while ( V_43 && ( * V_363 < V_377 * 4 ) ) {
T_1 V_375 ;
V_375 = V_372 [ * V_363 >> 2 ] ;
V_27 = F_229 ( V_375 , ( T_1 * ) V_362 ) ;
if ( V_27 ) {
F_83 ( V_372 ) ;
return V_27 ;
}
V_366 += 4 ;
V_362 += 4 ;
* V_363 += 4 ;
V_43 -= 4 ;
}
F_83 ( V_372 ) ;
return V_366 ;
}
static T_7 F_246 ( struct V_360 * V_361 , char T_8 * V_362 ,
T_4 V_43 , T_9 * V_363 )
{
struct V_3 * V_4 = V_361 -> V_364 -> V_365 ;
int V_401 , V_27 ;
T_10 V_375 ;
if ( V_43 != 4 || * V_363 & 0x3 )
return - V_45 ;
V_401 = * V_363 >> 2 ;
if ( V_4 -> V_402 . V_403 && V_4 -> V_402 . V_403 -> V_404 )
V_27 = V_4 -> V_402 . V_403 -> V_404 ( V_4 -> V_402 . V_405 , V_401 , & V_375 ) ;
else
return - V_45 ;
if ( ! V_27 )
V_27 = F_229 ( V_375 , ( T_10 * ) V_362 ) ;
return ! V_27 ? 4 : V_27 ;
}
static int F_151 ( struct V_3 * V_4 )
{
struct V_406 * V_145 = V_4 -> V_96 -> V_283 ;
struct V_407 * V_408 , * V_409 = V_145 -> V_359 ;
unsigned V_40 , V_410 ;
for ( V_40 = 0 ; V_40 < F_247 ( V_411 ) ; V_40 ++ ) {
V_408 = F_248 ( V_412 [ V_40 ] ,
V_413 | V_414 , V_409 ,
V_4 , V_411 [ V_40 ] ) ;
if ( F_249 ( V_408 ) ) {
for ( V_410 = 0 ; V_410 < V_40 ; V_410 ++ ) {
F_250 ( V_4 -> V_411 [ V_40 ] ) ;
V_4 -> V_411 [ V_40 ] = NULL ;
}
return F_251 ( V_408 ) ;
}
if ( ! V_40 )
F_252 ( V_408 -> V_415 , V_4 -> V_11 ) ;
V_4 -> V_411 [ V_40 ] = V_408 ;
}
return 0 ;
}
static void F_166 ( struct V_3 * V_4 )
{
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < F_247 ( V_411 ) ; V_40 ++ ) {
if ( V_4 -> V_411 [ V_40 ] ) {
F_250 ( V_4 -> V_411 [ V_40 ] ) ;
V_4 -> V_411 [ V_40 ] = NULL ;
}
}
}
int F_253 ( struct V_406 * V_145 )
{
return 0 ;
}
void F_254 ( struct V_406 * V_145 )
{
}
static int F_151 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_166 ( struct V_3 * V_4 ) { }
