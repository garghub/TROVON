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
if ( ( V_8 * 4 ) < V_4 -> V_10 && ! V_9 )
return F_3 ( ( ( void V_11 * ) V_4 -> V_12 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
T_1 V_13 ;
F_4 ( & V_4 -> V_14 , V_6 ) ;
F_5 ( ( V_8 * 4 ) , ( ( void V_11 * ) V_4 -> V_12 ) + ( V_15 * 4 ) ) ;
V_13 = F_3 ( ( ( void V_11 * ) V_4 -> V_12 ) + ( V_16 * 4 ) ) ;
F_6 ( & V_4 -> V_14 , V_6 ) ;
return V_13 ;
}
}
void F_7 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_17 ,
bool V_9 )
{
if ( ( V_8 * 4 ) < V_4 -> V_10 && ! V_9 )
F_5 ( V_17 , ( ( void V_11 * ) V_4 -> V_12 ) + ( V_8 * 4 ) ) ;
else {
unsigned long V_6 ;
F_4 ( & V_4 -> V_14 , V_6 ) ;
F_5 ( ( V_8 * 4 ) , ( ( void V_11 * ) V_4 -> V_12 ) + ( V_15 * 4 ) ) ;
F_5 ( V_17 , ( ( void V_11 * ) V_4 -> V_12 ) + ( V_16 * 4 ) ) ;
F_6 ( & V_4 -> V_14 , V_6 ) ;
}
}
T_2 F_8 ( struct V_3 * V_4 , T_2 V_8 )
{
if ( ( V_8 * 4 ) < V_4 -> V_18 )
return F_9 ( V_4 -> V_19 + ( V_8 * 4 ) ) ;
else {
F_10 ( ( V_8 * 4 ) , V_4 -> V_19 + ( V_15 * 4 ) ) ;
return F_9 ( V_4 -> V_19 + ( V_16 * 4 ) ) ;
}
}
void F_11 ( struct V_3 * V_4 , T_2 V_8 , T_2 V_17 )
{
if ( ( V_8 * 4 ) < V_4 -> V_18 )
F_10 ( V_17 , V_4 -> V_19 + ( V_8 * 4 ) ) ;
else {
F_10 ( ( V_8 * 4 ) , V_4 -> V_19 + ( V_15 * 4 ) ) ;
F_10 ( V_17 , V_4 -> V_19 + ( V_16 * 4 ) ) ;
}
}
T_2 F_12 ( struct V_3 * V_4 , T_2 V_20 )
{
if ( V_20 < V_4 -> V_21 . V_22 ) {
return F_3 ( V_4 -> V_21 . V_23 + V_20 ) ;
} else {
F_13 ( L_1 , V_20 ) ;
return 0 ;
}
}
void F_14 ( struct V_3 * V_4 , T_2 V_20 , T_2 V_17 )
{
if ( V_20 < V_4 -> V_21 . V_22 ) {
F_5 ( V_17 , V_4 -> V_21 . V_23 + V_20 ) ;
} else {
F_13 ( L_2 , V_20 ) ;
}
}
static T_1 F_15 ( struct V_3 * V_4 , T_1 V_8 )
{
F_13 ( L_3 , V_8 ) ;
F_16 () ;
return 0 ;
}
static void F_17 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_17 )
{
F_13 ( L_4 ,
V_8 , V_17 ) ;
F_16 () ;
}
static T_1 F_18 ( struct V_3 * V_4 ,
T_1 V_24 , T_1 V_8 )
{
F_13 ( L_5 ,
V_8 , V_24 ) ;
F_16 () ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 ,
T_1 V_24 ,
T_1 V_8 , T_1 V_17 )
{
F_13 ( L_6 ,
V_8 , V_24 , V_17 ) ;
F_16 () ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_25 ;
if ( V_4 -> V_26 . V_27 == NULL ) {
V_25 = F_21 ( V_4 , V_28 ,
V_29 , true , V_30 ,
V_31 ,
NULL , NULL , & V_4 -> V_26 . V_27 ) ;
if ( V_25 ) {
return V_25 ;
}
}
V_25 = F_22 ( V_4 -> V_26 . V_27 , false ) ;
if ( F_23 ( V_25 != 0 ) )
return V_25 ;
V_25 = F_24 ( V_4 -> V_26 . V_27 ,
V_30 , & V_4 -> V_26 . V_32 ) ;
if ( V_25 ) {
F_25 ( V_4 -> V_26 . V_27 ) ;
return V_25 ;
}
V_25 = F_26 ( V_4 -> V_26 . V_27 ,
( void * * ) & V_4 -> V_26 . V_23 ) ;
if ( V_25 )
F_27 ( V_4 -> V_26 . V_27 ) ;
F_25 ( V_4 -> V_26 . V_27 ) ;
return V_25 ;
}
static void F_28 ( struct V_3 * V_4 )
{
int V_25 ;
if ( V_4 -> V_26 . V_27 == NULL ) {
return;
}
V_25 = F_22 ( V_4 -> V_26 . V_27 , false ) ;
if ( F_29 ( V_25 == 0 ) ) {
F_30 ( V_4 -> V_26 . V_27 ) ;
F_27 ( V_4 -> V_26 . V_27 ) ;
F_25 ( V_4 -> V_26 . V_27 ) ;
}
F_31 ( & V_4 -> V_26 . V_27 ) ;
}
void F_32 ( struct V_3 * V_4 ,
const T_2 * V_33 ,
const T_2 V_34 )
{
T_2 V_35 , V_8 , V_36 , V_37 ;
int V_38 ;
if ( V_34 % 3 )
return;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 += 3 ) {
V_8 = V_33 [ V_38 + 0 ] ;
V_36 = V_33 [ V_38 + 1 ] ;
V_37 = V_33 [ V_38 + 2 ] ;
if ( V_36 == 0xffffffff ) {
V_35 = V_37 ;
} else {
V_35 = F_33 ( V_8 ) ;
V_35 &= ~ V_36 ;
V_35 |= V_37 ;
}
F_34 ( V_8 , V_35 ) ;
}
}
void F_35 ( struct V_3 * V_4 )
{
F_36 ( V_4 -> V_39 , 0x7c , V_40 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
V_4 -> V_21 . V_41 = F_38 ( V_4 -> V_39 , 2 ) ;
V_4 -> V_21 . V_42 = F_39 ( V_4 -> V_39 , 2 ) ;
V_4 -> V_21 . V_22 = F_40 ( T_2 , V_4 -> V_21 . V_42 / sizeof( T_2 ) ,
V_43 + 1 ) ;
if ( V_4 -> V_21 . V_22 == 0 )
return - V_44 ;
V_4 -> V_21 . V_23 = F_41 ( V_4 -> V_21 . V_41 , V_4 -> V_21 . V_22 * sizeof( T_2 ) ) ;
if ( V_4 -> V_21 . V_23 == NULL ) {
return - V_45 ;
}
F_42 ( L_7 , ( T_1 ) V_4 -> V_21 . V_41 ) ;
F_42 ( L_8 , ( unsigned ) V_4 -> V_21 . V_42 ) ;
return 0 ;
}
static void F_43 ( struct V_3 * V_4 )
{
F_44 ( V_4 -> V_21 . V_23 ) ;
V_4 -> V_21 . V_23 = NULL ;
}
void F_45 ( struct V_3 * V_4 ,
T_3 * V_46 ,
T_4 * V_47 ,
T_4 * V_48 )
{
if ( V_4 -> V_21 . V_42 > V_4 -> V_21 . V_22 * sizeof( T_2 ) ) {
* V_46 = V_4 -> V_21 . V_41 ;
* V_47 = V_4 -> V_21 . V_42 ;
* V_48 = V_4 -> V_21 . V_22 * sizeof( T_2 ) ;
} else {
* V_46 = 0 ;
* V_47 = 0 ;
* V_48 = 0 ;
}
}
static void F_46 ( struct V_3 * V_4 )
{
if ( V_4 -> V_49 . V_50 ) {
if ( ! F_22 ( V_4 -> V_49 . V_50 , false ) ) {
F_30 ( V_4 -> V_49 . V_50 ) ;
F_27 ( V_4 -> V_49 . V_50 ) ;
F_25 ( V_4 -> V_49 . V_50 ) ;
}
F_31 ( & V_4 -> V_49 . V_50 ) ;
V_4 -> V_49 . V_49 = NULL ;
V_4 -> V_49 . V_50 = NULL ;
}
}
static int F_47 ( struct V_3 * V_4 )
{
int V_25 ;
if ( V_4 -> V_49 . V_50 == NULL ) {
V_25 = F_21 ( V_4 , V_51 * 4 , V_29 , true ,
V_52 , 0 , NULL , NULL ,
& V_4 -> V_49 . V_50 ) ;
if ( V_25 ) {
F_48 ( V_4 -> V_2 , L_9 , V_25 ) ;
return V_25 ;
}
V_25 = F_22 ( V_4 -> V_49 . V_50 , false ) ;
if ( F_23 ( V_25 != 0 ) ) {
F_46 ( V_4 ) ;
return V_25 ;
}
V_25 = F_24 ( V_4 -> V_49 . V_50 , V_52 ,
& V_4 -> V_49 . V_32 ) ;
if ( V_25 ) {
F_25 ( V_4 -> V_49 . V_50 ) ;
F_48 ( V_4 -> V_2 , L_10 , V_25 ) ;
F_46 ( V_4 ) ;
return V_25 ;
}
V_25 = F_26 ( V_4 -> V_49 . V_50 , ( void * * ) & V_4 -> V_49 . V_49 ) ;
F_25 ( V_4 -> V_49 . V_50 ) ;
if ( V_25 ) {
F_48 ( V_4 -> V_2 , L_11 , V_25 ) ;
F_46 ( V_4 ) ;
return V_25 ;
}
V_4 -> V_49 . V_53 = V_51 ;
memset ( & V_4 -> V_49 . V_54 , 0 , sizeof( V_4 -> V_49 . V_54 ) ) ;
memset ( ( char * ) V_4 -> V_49 . V_49 , 0 , V_28 ) ;
}
return 0 ;
}
int F_49 ( struct V_3 * V_4 , T_2 * V_49 )
{
unsigned long V_55 = F_50 ( V_4 -> V_49 . V_54 , V_4 -> V_49 . V_53 ) ;
if ( V_55 < V_4 -> V_49 . V_53 ) {
F_51 ( V_55 , V_4 -> V_49 . V_54 ) ;
* V_49 = V_55 ;
return 0 ;
} else {
return - V_44 ;
}
}
void F_52 ( struct V_3 * V_4 , T_2 V_49 )
{
if ( V_49 < V_4 -> V_49 . V_53 )
F_53 ( V_49 , V_4 -> V_49 . V_54 ) ;
}
void F_54 ( struct V_3 * V_4 , struct V_56 * V_57 , T_5 V_41 )
{
T_6 V_58 = ( T_6 ) V_59 << 20 ;
V_57 -> V_60 = V_41 ;
if ( V_57 -> V_61 > ( V_4 -> V_57 . V_62 - V_41 + 1 ) ) {
F_48 ( V_4 -> V_2 , L_12 ) ;
V_57 -> V_63 = V_57 -> V_64 ;
V_57 -> V_61 = V_57 -> V_64 ;
}
V_57 -> V_65 = V_57 -> V_60 + V_57 -> V_61 - 1 ;
if ( V_58 && V_58 < V_57 -> V_63 )
V_57 -> V_63 = V_58 ;
F_55 ( V_4 -> V_2 , L_13 ,
V_57 -> V_61 >> 20 , V_57 -> V_60 ,
V_57 -> V_65 , V_57 -> V_63 >> 20 ) ;
}
void F_56 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
T_5 V_66 , V_67 ;
V_66 = ( ( V_4 -> V_57 . V_62 - V_57 -> V_65 ) + V_57 -> V_68 ) & ~ V_57 -> V_68 ;
V_67 = V_57 -> V_60 & ~ V_57 -> V_68 ;
if ( V_67 > V_66 ) {
if ( V_57 -> V_69 > V_67 ) {
F_48 ( V_4 -> V_2 , L_14 ) ;
V_57 -> V_69 = V_67 ;
}
V_57 -> V_70 = ( V_57 -> V_60 & ~ V_57 -> V_68 ) - V_57 -> V_69 ;
} else {
if ( V_57 -> V_69 > V_66 ) {
F_48 ( V_4 -> V_2 , L_14 ) ;
V_57 -> V_69 = V_66 ;
}
V_57 -> V_70 = ( V_57 -> V_65 + 1 + V_57 -> V_68 ) & ~ V_57 -> V_68 ;
}
V_57 -> V_71 = V_57 -> V_70 + V_57 -> V_69 - 1 ;
F_55 ( V_4 -> V_2 , L_15 ,
V_57 -> V_69 >> 20 , V_57 -> V_70 , V_57 -> V_71 ) ;
}
bool F_57 ( struct V_3 * V_4 )
{
T_1 V_8 ;
V_8 = F_33 ( V_72 ) ;
if ( V_8 )
return true ;
return false ;
}
int F_58 ( struct V_3 * V_4 )
{
if ( V_4 -> V_73 . V_74 )
return 0 ;
V_4 -> V_73 . V_74 = F_59 ( V_75 | V_76 | V_77 ) ;
if ( V_4 -> V_73 . V_74 == NULL )
return - V_45 ;
V_4 -> V_73 . V_78 = F_60 ( V_4 -> V_39 , V_4 -> V_73 . V_74 ,
0 , V_29 , V_79 ) ;
if ( F_61 ( V_4 -> V_39 , V_4 -> V_73 . V_78 ) ) {
F_62 ( & V_4 -> V_39 -> V_2 , L_16 ) ;
F_63 ( V_4 -> V_73 . V_74 ) ;
V_4 -> V_73 . V_74 = NULL ;
return - V_45 ;
}
return 0 ;
}
void F_64 ( struct V_3 * V_4 )
{
if ( V_4 -> V_73 . V_74 == NULL )
return;
F_65 ( V_4 -> V_39 , V_4 -> V_73 . V_78 ,
V_29 , V_79 ) ;
F_63 ( V_4 -> V_73 . V_74 ) ;
V_4 -> V_73 . V_74 = NULL ;
}
static T_1 F_66 ( struct V_80 * V_81 , T_1 V_8 )
{
return 0 ;
}
static void F_67 ( struct V_80 * V_81 , T_1 V_8 , T_1 V_82 )
{
}
static T_1 F_68 ( struct V_80 * V_81 , T_1 V_8 )
{
return 0 ;
}
static void F_69 ( struct V_80 * V_81 , T_1 V_8 , T_1 V_82 )
{
}
static void F_70 ( struct V_80 * V_81 , T_1 V_8 , T_1 V_82 )
{
struct V_3 * V_4 = V_81 -> V_2 -> V_5 ;
F_34 ( V_8 , V_82 ) ;
}
static T_1 F_71 ( struct V_80 * V_81 , T_1 V_8 )
{
struct V_3 * V_4 = V_81 -> V_2 -> V_5 ;
T_1 V_25 ;
V_25 = F_33 ( V_8 ) ;
return V_25 ;
}
static void F_72 ( struct V_80 * V_81 , T_1 V_8 , T_1 V_82 )
{
struct V_3 * V_4 = V_81 -> V_2 -> V_5 ;
F_73 ( V_8 , V_82 ) ;
}
static T_1 F_74 ( struct V_80 * V_81 , T_1 V_8 )
{
struct V_3 * V_4 = V_81 -> V_2 -> V_5 ;
T_1 V_25 ;
V_25 = F_75 ( V_8 ) ;
return V_25 ;
}
static void F_76 ( struct V_3 * V_4 )
{
if ( V_4 -> V_83 . V_84 ) {
F_77 ( V_4 -> V_83 . V_84 -> V_85 ) ;
F_77 ( V_4 -> V_83 . V_84 -> V_86 ) ;
}
F_77 ( V_4 -> V_83 . V_84 ) ;
V_4 -> V_83 . V_84 = NULL ;
F_77 ( V_4 -> V_83 . V_87 ) ;
V_4 -> V_83 . V_87 = NULL ;
}
static int F_78 ( struct V_3 * V_4 )
{
struct V_80 * V_87 =
F_79 ( sizeof( struct V_80 ) , V_76 ) ;
if ( ! V_87 )
return - V_45 ;
V_4 -> V_83 . V_87 = V_87 ;
V_87 -> V_2 = V_4 -> V_88 ;
V_87 -> V_89 = F_71 ;
V_87 -> V_90 = F_70 ;
if ( V_4 -> V_19 ) {
V_87 -> V_91 = F_74 ;
V_87 -> V_92 = F_72 ;
} else {
F_13 ( L_17 ) ;
V_87 -> V_91 = F_71 ;
V_87 -> V_92 = F_70 ;
}
V_87 -> V_93 = F_68 ;
V_87 -> V_94 = F_69 ;
V_87 -> V_95 = F_66 ;
V_87 -> V_96 = F_67 ;
V_4 -> V_83 . V_84 = F_80 ( V_87 , V_4 -> V_97 ) ;
if ( ! V_4 -> V_83 . V_84 ) {
F_76 ( V_4 ) ;
return - V_45 ;
}
F_81 ( & V_4 -> V_83 . V_84 -> V_98 ) ;
F_82 ( V_4 ) ;
F_83 ( V_4 -> V_83 . V_84 ) ;
return 0 ;
}
static unsigned int F_84 ( void * V_99 , bool V_100 )
{
struct V_3 * V_4 = V_99 ;
F_85 ( V_4 , V_100 ) ;
if ( V_100 )
return V_101 | V_102 |
V_103 | V_104 ;
else
return V_103 | V_104 ;
}
static bool F_86 ( int V_105 )
{
return ( V_105 & ( V_105 - 1 ) ) == 0 ;
}
static void F_87 ( struct V_3 * V_4 )
{
if ( V_106 < 4 ) {
F_48 ( V_4 -> V_2 , L_18 ,
V_106 ) ;
V_106 = 4 ;
} else if ( ! F_86 ( V_106 ) ) {
F_48 ( V_4 -> V_2 , L_19 ,
V_106 ) ;
V_106 = F_88 ( V_106 ) ;
}
if ( V_107 != - 1 ) {
if ( V_107 < 32 ) {
F_48 ( V_4 -> V_2 , L_20 ,
V_107 ) ;
V_107 = - 1 ;
}
}
if ( ! F_86 ( V_108 ) ) {
F_48 ( V_4 -> V_2 , L_21 ,
V_108 ) ;
V_108 = 8 ;
}
if ( V_108 < 1 ) {
F_48 ( V_4 -> V_2 , L_22 ,
V_108 ) ;
V_108 = 8 ;
}
if ( V_108 > 1024 ) {
F_48 ( V_4 -> V_2 , L_23 ,
V_108 ) ;
V_108 = 8 ;
}
if ( V_109 == - 1 ) {
unsigned V_110 = F_89 ( V_108 ) + 18 ;
if ( V_108 <= 8 )
V_109 = V_110 - 9 ;
else
V_109 = ( V_110 + 3 ) / 2 ;
} else if ( V_109 < 9 ) {
F_48 ( V_4 -> V_2 , L_24 ,
V_109 ) ;
V_109 = 9 ;
}
if ( V_109 > 24 ||
( V_108 * 1024 ) < ( 1ull << V_109 ) ) {
F_48 ( V_4 -> V_2 , L_25 ,
V_109 ) ;
V_109 = 9 ;
}
}
static void F_90 ( struct V_111 * V_39 , enum V_112 V_100 )
{
struct V_1 * V_2 = F_91 ( V_39 ) ;
if ( F_1 ( V_2 ) && V_100 == V_113 )
return;
if ( V_100 == V_114 ) {
unsigned V_115 = V_2 -> V_39 -> V_115 ;
F_92 ( V_116 L_26 ) ;
V_2 -> V_117 = V_118 ;
F_93 ( V_2 , true , true ) ;
V_2 -> V_39 -> V_115 = V_115 ;
V_2 -> V_117 = V_119 ;
F_94 ( V_2 ) ;
} else {
F_92 ( V_116 L_27 ) ;
F_95 ( V_2 ) ;
V_2 -> V_117 = V_118 ;
F_96 ( V_2 , true , true ) ;
V_2 -> V_117 = V_120 ;
}
}
static bool F_97 ( struct V_111 * V_39 )
{
struct V_1 * V_2 = F_91 ( V_39 ) ;
return V_2 -> V_121 == 0 ;
}
int F_98 ( struct V_3 * V_4 ,
enum V_122 V_123 ,
enum V_124 V_100 )
{
int V_38 , V_25 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( V_4 -> V_126 [ V_38 ] . type == V_123 ) {
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_128 ( ( void * ) V_4 ,
V_100 ) ;
if ( V_25 )
return V_25 ;
}
}
return V_25 ;
}
int F_99 ( struct V_3 * V_4 ,
enum V_122 V_123 ,
enum V_129 V_100 )
{
int V_38 , V_25 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( V_4 -> V_126 [ V_38 ] . type == V_123 ) {
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_130 ( ( void * ) V_4 ,
V_100 ) ;
if ( V_25 )
return V_25 ;
}
}
return V_25 ;
}
const struct V_131 * F_100 (
struct V_3 * V_4 ,
enum V_122 type )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ )
if ( V_4 -> V_126 [ V_38 ] . type == type )
return & V_4 -> V_126 [ V_38 ] ;
return NULL ;
}
int F_101 ( struct V_3 * V_4 ,
enum V_122 type ,
T_2 V_132 , T_2 V_133 )
{
const struct V_131 * V_134 ;
V_134 = F_100 ( V_4 , type ) ;
if ( V_134 && ( ( V_134 -> V_132 > V_132 ) ||
( ( V_134 -> V_132 == V_132 ) &&
( V_134 -> V_133 >= V_133 ) ) ) )
return 0 ;
return 1 ;
}
static int F_102 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
switch ( V_4 -> V_135 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
if ( V_4 -> V_135 == V_141 || V_4 -> V_135 == V_142 )
V_4 -> V_143 = V_144 ;
else
V_4 -> V_143 = V_145 ;
V_25 = F_103 ( V_4 ) ;
if ( V_25 )
return V_25 ;
break;
#ifdef F_104
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
if ( ( V_4 -> V_135 == V_146 ) || ( V_4 -> V_135 == V_147 ) )
V_4 -> V_143 = V_151 ;
else
V_4 -> V_143 = V_152 ;
V_25 = F_105 ( V_4 ) ;
if ( V_25 )
return V_25 ;
break;
#endif
default:
return - V_44 ;
}
V_4 -> V_153 = F_106 ( V_4 -> V_125 ,
sizeof( struct V_154 ) , V_76 ) ;
if ( V_4 -> V_153 == NULL )
return - V_45 ;
if ( V_4 -> V_126 == NULL ) {
F_13 ( L_28 ) ;
return V_25 ;
}
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( ( V_155 & ( 1 << V_38 ) ) == 0 ) {
F_13 ( L_29 , V_38 ) ;
V_4 -> V_153 [ V_38 ] . V_156 = false ;
} else {
if ( V_4 -> V_126 [ V_38 ] . V_127 -> V_157 ) {
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_157 ( ( void * ) V_4 ) ;
if ( V_25 == - V_158 ) {
V_4 -> V_153 [ V_38 ] . V_156 = false ;
} else if ( V_25 ) {
F_13 ( L_30 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
} else {
V_4 -> V_153 [ V_38 ] . V_156 = true ;
}
} else {
V_4 -> V_153 [ V_38 ] . V_156 = true ;
}
}
}
return 0 ;
}
static int F_107 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_156 )
continue;
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_160 ( ( void * ) V_4 ) ;
if ( V_25 ) {
F_13 ( L_31 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
}
V_4 -> V_153 [ V_38 ] . V_161 = true ;
if ( V_4 -> V_126 [ V_38 ] . type == V_162 ) {
V_25 = F_20 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_32 , V_25 ) ;
return V_25 ;
}
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_163 ( ( void * ) V_4 ) ;
if ( V_25 ) {
F_13 ( L_33 , V_38 , V_25 ) ;
return V_25 ;
}
V_25 = F_47 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_34 , V_25 ) ;
return V_25 ;
}
V_4 -> V_153 [ V_38 ] . V_164 = true ;
}
}
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_161 )
continue;
if ( V_4 -> V_126 [ V_38 ] . type == V_162 )
continue;
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_163 ( ( void * ) V_4 ) ;
if ( V_25 ) {
F_13 ( L_35 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
}
V_4 -> V_153 [ V_38 ] . V_164 = true ;
}
return 0 ;
}
static int F_108 ( struct V_3 * V_4 )
{
int V_38 = 0 , V_25 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_156 )
continue;
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_128 ( ( void * ) V_4 ,
V_165 ) ;
if ( V_25 ) {
F_13 ( L_36 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
}
if ( V_4 -> V_126 [ V_38 ] . V_127 -> V_166 ) {
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_166 ( ( void * ) V_4 ) ;
if ( V_25 ) {
F_13 ( L_37 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
}
}
}
return 0 ;
}
static int F_109 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = V_4 -> V_125 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_164 )
continue;
if ( V_4 -> V_126 [ V_38 ] . type == V_162 ) {
F_46 ( V_4 ) ;
F_28 ( V_4 ) ;
}
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_128 ( ( void * ) V_4 ,
V_167 ) ;
if ( V_25 ) {
F_13 ( L_38 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
}
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_168 ( ( void * ) V_4 ) ;
if ( V_25 ) {
F_110 ( L_39 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
}
V_4 -> V_153 [ V_38 ] . V_164 = false ;
}
for ( V_38 = V_4 -> V_125 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_161 )
continue;
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_169 ( ( void * ) V_4 ) ;
if ( V_25 ) {
F_110 ( L_40 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
}
V_4 -> V_153 [ V_38 ] . V_161 = false ;
V_4 -> V_153 [ V_38 ] . V_156 = false ;
}
for ( V_38 = V_4 -> V_125 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( V_4 -> V_126 [ V_38 ] . V_127 -> V_170 )
V_4 -> V_126 [ V_38 ] . V_127 -> V_170 ( ( void * ) V_4 ) ;
}
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
V_25 = F_98 ( V_4 , V_171 ,
V_167 ) ;
if ( V_25 ) {
F_13 ( L_41 , V_25 ) ;
}
for ( V_38 = V_4 -> V_125 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_156 )
continue;
if ( V_38 != V_171 ) {
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_128 ( ( void * ) V_4 ,
V_167 ) ;
if ( V_25 ) {
F_13 ( L_38 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
}
}
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_172 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_42 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
}
}
return 0 ;
}
static int F_112 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_125 ; V_38 ++ ) {
if ( ! V_4 -> V_153 [ V_38 ] . V_156 )
continue;
V_25 = V_4 -> V_126 [ V_38 ] . V_127 -> V_173 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_43 , V_4 -> V_126 [ V_38 ] . V_127 -> V_159 , V_25 ) ;
return V_25 ;
}
}
return 0 ;
}
static bool F_113 ( void )
{
#ifdef F_114
return F_115 ( V_174 ) ;
#else
return false ;
#endif
}
int F_116 ( struct V_3 * V_4 ,
struct V_1 * V_88 ,
struct V_111 * V_39 ,
T_1 V_6 )
{
int V_25 , V_38 ;
bool V_175 = false ;
V_4 -> V_176 = false ;
V_4 -> V_2 = & V_39 -> V_2 ;
V_4 -> V_88 = V_88 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_135 = V_6 & V_177 ;
V_4 -> V_178 = false ;
V_4 -> V_179 = V_180 ;
V_4 -> V_57 . V_69 = 512 * 1024 * 1024 ;
V_4 -> V_181 = false ;
V_4 -> V_182 = 0 ;
V_4 -> V_183 . V_184 = NULL ;
V_4 -> V_183 . V_185 = NULL ;
V_4 -> V_186 . V_187 = NULL ;
V_4 -> V_186 . V_188 = 0 ;
V_4 -> V_189 . V_190 = NULL ;
V_4 -> V_191 = F_117 ( V_192 ) ;
V_4 -> V_193 = & F_15 ;
V_4 -> V_194 = & F_17 ;
V_4 -> V_195 = & F_15 ;
V_4 -> V_196 = & F_17 ;
V_4 -> V_197 = & F_15 ;
V_4 -> V_198 = & F_17 ;
V_4 -> V_199 = & F_15 ;
V_4 -> V_200 = & F_17 ;
V_4 -> V_201 = & F_18 ;
V_4 -> V_202 = & F_19 ;
F_42 ( L_44 ,
V_203 [ V_4 -> V_135 ] , V_39 -> V_204 , V_39 -> V_205 ,
V_39 -> V_206 , V_39 -> V_207 , V_39 -> V_208 ) ;
F_81 ( & V_4 -> V_186 . V_209 ) ;
F_118 ( & V_4 -> V_210 . V_211 . V_209 , 0 ) ;
F_81 ( & V_4 -> V_212 . V_98 ) ;
F_81 ( & V_4 -> V_213 . V_214 ) ;
F_81 ( & V_4 -> V_215 ) ;
F_81 ( & V_4 -> V_216 ) ;
F_81 ( & V_4 -> V_217 ) ;
F_119 ( V_4 -> V_218 ) ;
F_87 ( V_4 ) ;
F_120 ( & V_4 -> V_14 ) ;
F_120 ( & V_4 -> V_219 ) ;
F_120 ( & V_4 -> V_220 ) ;
F_120 ( & V_4 -> V_221 ) ;
F_120 ( & V_4 -> V_222 ) ;
F_120 ( & V_4 -> V_223 ) ;
V_4 -> V_224 = F_38 ( V_4 -> V_39 , 5 ) ;
V_4 -> V_10 = F_39 ( V_4 -> V_39 , 5 ) ;
V_4 -> V_12 = F_41 ( V_4 -> V_224 , V_4 -> V_10 ) ;
if ( V_4 -> V_12 == NULL ) {
return - V_45 ;
}
F_42 ( L_45 , ( T_1 ) V_4 -> V_224 ) ;
F_42 ( L_46 , ( unsigned ) V_4 -> V_10 ) ;
F_37 ( V_4 ) ;
for ( V_38 = 0 ; V_38 < V_225 ; V_38 ++ ) {
if ( F_121 ( V_4 -> V_39 , V_38 ) & V_226 ) {
V_4 -> V_18 = F_39 ( V_4 -> V_39 , V_38 ) ;
V_4 -> V_19 = F_122 ( V_4 -> V_39 , V_38 , V_4 -> V_18 ) ;
break;
}
}
if ( V_4 -> V_19 == NULL )
F_13 ( L_47 ) ;
V_25 = F_102 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_123 ( V_4 -> V_39 , V_4 , NULL , F_84 ) ;
if ( V_227 == 1 )
V_175 = true ;
if ( F_1 ( V_88 ) )
V_175 = true ;
F_124 ( V_4 -> V_39 , & V_228 , V_175 ) ;
if ( V_175 )
F_125 ( V_4 -> V_2 , & V_4 -> V_229 ) ;
if ( ! F_126 ( V_4 ) )
return - V_44 ;
if ( ! V_4 -> V_178 ) {
F_62 ( V_4 -> V_2 , L_48 ) ;
return - V_44 ;
}
V_25 = F_78 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_49 ) ;
return V_25 ;
}
V_4 -> V_230 . V_231 =
F_127 ( V_4 ) ;
V_4 -> V_230 . V_232 = F_113 () ;
V_4 -> V_230 . V_233 = F_128 ( V_4 ) ;
if ( ! F_57 ( V_4 ) ||
( V_4 -> V_230 . V_232 &&
! ( V_4 -> V_230 . V_233 & V_234 ) ) ) {
if ( ! V_4 -> V_97 ) {
F_62 ( V_4 -> V_2 , L_50 ) ;
return - V_44 ;
}
F_42 ( L_51 ) ;
F_129 ( V_4 -> V_83 . V_84 ) ;
}
V_25 = F_130 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_52 ) ;
return V_25 ;
}
F_131 ( V_4 ) ;
V_25 = F_132 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_53 ) ;
return V_25 ;
}
F_133 ( V_4 -> V_88 ) ;
V_25 = F_107 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_54 ) ;
F_109 ( V_4 ) ;
return V_25 ;
}
V_4 -> V_181 = true ;
F_134 ( V_4 ) ;
V_25 = F_135 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_55 , V_25 ) ;
return V_25 ;
}
V_25 = F_136 ( V_4 ) ;
if ( V_25 )
F_13 ( L_56 , V_25 ) ;
V_25 = F_137 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_57 , V_25 ) ;
}
V_25 = F_138 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_58 , V_25 ) ;
}
if ( ( V_235 & 1 ) ) {
if ( V_4 -> V_181 )
F_139 ( V_4 ) ;
else
F_42 ( L_59 ) ;
}
if ( ( V_235 & 2 ) ) {
if ( V_4 -> V_181 )
F_140 ( V_4 ) ;
else
F_42 ( L_60 ) ;
}
if ( V_236 ) {
if ( V_4 -> V_181 )
F_141 ( V_4 , V_236 ) ;
else
F_42 ( L_61 ) ;
}
V_25 = F_108 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_62 ) ;
return V_25 ;
}
return 0 ;
}
void F_142 ( struct V_3 * V_4 )
{
int V_25 ;
F_42 ( L_63 ) ;
V_4 -> V_176 = true ;
F_143 ( V_4 ) ;
F_144 ( V_4 ) ;
F_145 ( V_4 ) ;
F_146 ( V_4 ) ;
V_25 = F_109 ( V_4 ) ;
F_77 ( V_4 -> V_153 ) ;
V_4 -> V_153 = NULL ;
V_4 -> V_181 = false ;
F_147 ( V_4 ) ;
F_76 ( V_4 ) ;
F_77 ( V_4 -> V_97 ) ;
V_4 -> V_97 = NULL ;
F_148 ( V_4 -> V_39 ) ;
F_123 ( V_4 -> V_39 , NULL , NULL , NULL ) ;
if ( V_4 -> V_19 )
F_149 ( V_4 -> V_39 , V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_44 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
F_43 ( V_4 ) ;
F_150 ( V_4 ) ;
F_151 ( V_4 ) ;
}
int F_96 ( struct V_1 * V_2 , bool V_172 , bool V_237 )
{
struct V_3 * V_4 ;
struct V_238 * V_239 ;
struct V_240 * V_241 ;
int V_25 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_242 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_117 == V_120 )
return 0 ;
F_95 ( V_2 ) ;
F_152 ( V_2 ) ;
F_153 (connector, &dev->mode_config.connector_list, head) {
F_154 ( V_241 , V_243 ) ;
}
F_155 ( V_2 ) ;
F_153 (crtc, &dev->mode_config.crtc_list, head) {
struct V_244 * V_244 = F_156 ( V_239 ) ;
struct V_245 * V_246 = F_157 ( V_239 -> V_247 -> V_248 ) ;
struct V_249 * V_27 ;
if ( V_244 -> V_250 ) {
struct V_249 * V_251 = F_158 ( V_244 -> V_250 ) ;
V_25 = F_22 ( V_251 , false ) ;
if ( V_25 == 0 ) {
F_27 ( V_251 ) ;
F_25 ( V_251 ) ;
}
}
if ( V_246 == NULL || V_246 -> V_252 == NULL ) {
continue;
}
V_27 = F_158 ( V_246 -> V_252 ) ;
if ( ! F_159 ( V_4 , V_27 ) ) {
V_25 = F_22 ( V_27 , false ) ;
if ( V_25 == 0 ) {
F_27 ( V_27 ) ;
F_25 ( V_27 ) ;
}
}
}
F_143 ( V_4 ) ;
F_160 ( V_4 ) ;
V_25 = F_111 ( V_4 ) ;
F_143 ( V_4 ) ;
F_161 ( V_2 -> V_39 ) ;
if ( V_172 ) {
F_162 ( V_2 -> V_39 ) ;
F_163 ( V_2 -> V_39 , V_253 ) ;
}
if ( V_237 ) {
F_164 () ;
F_165 ( V_4 , 1 ) ;
F_166 () ;
}
return 0 ;
}
int F_93 ( struct V_1 * V_2 , bool V_173 , bool V_237 )
{
struct V_240 * V_241 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_238 * V_239 ;
int V_25 ;
if ( V_2 -> V_117 == V_120 )
return 0 ;
if ( V_237 ) {
F_164 () ;
}
if ( V_173 ) {
F_163 ( V_2 -> V_39 , V_254 ) ;
F_167 ( V_2 -> V_39 ) ;
if ( F_168 ( V_2 -> V_39 ) ) {
if ( V_237 )
F_166 () ;
return - 1 ;
}
}
if ( ! F_57 ( V_4 ) )
F_129 ( V_4 -> V_83 . V_84 ) ;
V_25 = F_112 ( V_4 ) ;
if ( V_25 )
F_13 ( L_64 , V_25 ) ;
F_169 ( V_4 ) ;
if ( V_173 ) {
V_25 = F_136 ( V_4 ) ;
if ( V_25 )
F_13 ( L_56 , V_25 ) ;
}
V_25 = F_108 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_153 (crtc, &dev->mode_config.crtc_list, head) {
struct V_244 * V_244 = F_156 ( V_239 ) ;
if ( V_244 -> V_250 ) {
struct V_249 * V_251 = F_158 ( V_244 -> V_250 ) ;
V_25 = F_22 ( V_251 , false ) ;
if ( V_25 == 0 ) {
V_25 = F_24 ( V_251 ,
V_30 ,
& V_244 -> V_255 ) ;
if ( V_25 != 0 )
F_13 ( L_65 , V_25 ) ;
F_25 ( V_251 ) ;
}
}
}
if ( V_237 ) {
F_170 ( V_2 ) ;
F_152 ( V_2 ) ;
F_153 (connector, &dev->mode_config.connector_list, head) {
F_154 ( V_241 , V_256 ) ;
}
F_155 ( V_2 ) ;
}
F_94 ( V_2 ) ;
F_171 ( V_2 ) ;
if ( V_237 ) {
F_165 ( V_4 , 0 ) ;
F_166 () ;
}
return 0 ;
}
int F_172 ( struct V_3 * V_4 )
{
unsigned V_257 [ V_192 ] ;
T_1 * V_258 [ V_192 ] ;
bool V_259 = false ;
int V_38 , V_25 ;
int V_260 ;
F_173 ( & V_4 -> V_261 ) ;
V_260 = F_174 ( & V_4 -> V_183 . V_262 ) ;
V_25 = F_111 ( V_4 ) ;
for ( V_38 = 0 ; V_38 < V_192 ; ++ V_38 ) {
struct V_263 * V_264 = V_4 -> V_265 [ V_38 ] ;
if ( ! V_264 )
continue;
V_257 [ V_38 ] = F_175 ( V_264 , & V_258 [ V_38 ] ) ;
if ( V_257 [ V_38 ] ) {
V_259 = true ;
F_55 ( V_4 -> V_2 , L_66
L_67 , V_257 [ V_38 ] , V_38 ) ;
}
}
V_266:
V_25 = F_176 ( V_4 ) ;
F_129 ( V_4 -> V_83 . V_84 ) ;
if ( ! V_25 ) {
F_55 ( V_4 -> V_2 , L_68 ) ;
V_25 = F_112 ( V_4 ) ;
}
if ( ! V_25 ) {
for ( V_38 = 0 ; V_38 < V_192 ; ++ V_38 ) {
struct V_263 * V_264 = V_4 -> V_265 [ V_38 ] ;
if ( ! V_264 )
continue;
F_177 ( V_264 , V_257 [ V_38 ] , V_258 [ V_38 ] ) ;
V_257 [ V_38 ] = 0 ;
V_258 [ V_38 ] = NULL ;
}
V_25 = F_136 ( V_4 ) ;
if ( V_25 ) {
F_62 ( V_4 -> V_2 , L_56 , V_25 ) ;
if ( V_259 ) {
V_259 = false ;
V_25 = F_111 ( V_4 ) ;
goto V_266;
}
}
} else {
F_178 ( V_4 ) ;
for ( V_38 = 0 ; V_38 < V_192 ; ++ V_38 ) {
if ( V_4 -> V_265 [ V_38 ] )
F_77 ( V_258 [ V_38 ] ) ;
}
}
F_170 ( V_4 -> V_88 ) ;
F_179 ( & V_4 -> V_183 . V_262 , V_260 ) ;
if ( V_25 ) {
F_55 ( V_4 -> V_2 , L_69 ) ;
}
return V_25 ;
}
void F_180 ( struct V_3 * V_4 )
{
T_2 V_267 ;
int V_13 ;
if ( V_268 )
V_4 -> V_212 . V_269 = V_268 ;
if ( V_270 )
V_4 -> V_212 . V_271 = V_270 ;
if ( F_181 ( V_4 -> V_39 -> V_272 ) ) {
if ( V_4 -> V_212 . V_269 == 0 )
V_4 -> V_212 . V_269 = V_273 ;
if ( V_4 -> V_212 . V_271 == 0 )
V_4 -> V_212 . V_271 = V_274 ;
return;
}
if ( V_4 -> V_212 . V_269 == 0 ) {
V_13 = F_182 ( V_4 -> V_88 , & V_267 ) ;
if ( ! V_13 ) {
V_4 -> V_212 . V_269 = ( V_275 |
V_276 |
V_277 ) ;
if ( V_267 & V_278 )
V_4 -> V_212 . V_269 |= V_279 ;
if ( V_267 & V_280 )
V_4 -> V_212 . V_269 |= V_281 ;
if ( V_267 & V_282 )
V_4 -> V_212 . V_269 |= V_283 ;
} else {
V_4 -> V_212 . V_269 = V_273 ;
}
}
if ( V_4 -> V_212 . V_271 == 0 ) {
V_13 = F_183 ( V_4 -> V_88 , & V_267 ) ;
if ( ! V_13 ) {
switch ( V_267 ) {
case 32 :
V_4 -> V_212 . V_271 = ( V_284 |
V_285 |
V_286 |
V_287 |
V_288 |
V_289 |
V_290 ) ;
break;
case 16 :
V_4 -> V_212 . V_271 = ( V_285 |
V_286 |
V_287 |
V_288 |
V_289 |
V_290 ) ;
break;
case 12 :
V_4 -> V_212 . V_271 = ( V_286 |
V_287 |
V_288 |
V_289 |
V_290 ) ;
break;
case 8 :
V_4 -> V_212 . V_271 = ( V_287 |
V_288 |
V_289 |
V_290 ) ;
break;
case 4 :
V_4 -> V_212 . V_271 = ( V_288 |
V_289 |
V_290 ) ;
break;
case 2 :
V_4 -> V_212 . V_271 = ( V_289 |
V_290 ) ;
break;
case 1 :
V_4 -> V_212 . V_271 = V_290 ;
break;
default:
break;
}
} else {
V_4 -> V_212 . V_271 = V_274 ;
}
}
}
int F_184 ( struct V_3 * V_4 ,
const struct V_291 * V_292 ,
unsigned V_293 )
{
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_294 ; V_38 ++ ) {
if ( V_4 -> V_295 [ V_38 ] . V_292 == V_292 ) {
return 0 ;
}
}
V_38 = V_4 -> V_294 + 1 ;
if ( V_38 > V_296 ) {
F_13 ( L_70 ) ;
F_13 ( L_71
L_72 ) ;
return - V_44 ;
}
V_4 -> V_295 [ V_4 -> V_294 ] . V_292 = V_292 ;
V_4 -> V_295 [ V_4 -> V_294 ] . V_297 = V_293 ;
V_4 -> V_294 = V_38 ;
#if F_185 ( V_298 )
F_186 ( V_292 , V_293 ,
V_4 -> V_88 -> V_299 -> V_300 ,
V_4 -> V_88 -> V_299 ) ;
F_186 ( V_292 , V_293 ,
V_4 -> V_88 -> V_247 -> V_300 ,
V_4 -> V_88 -> V_247 ) ;
#endif
return 0 ;
}
static void F_151 ( struct V_3 * V_4 )
{
#if F_185 ( V_298 )
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_294 ; V_38 ++ ) {
F_187 ( V_4 -> V_295 [ V_38 ] . V_292 ,
V_4 -> V_295 [ V_38 ] . V_297 ,
V_4 -> V_88 -> V_299 ) ;
F_187 ( V_4 -> V_295 [ V_38 ] . V_292 ,
V_4 -> V_295 [ V_38 ] . V_297 ,
V_4 -> V_88 -> V_247 ) ;
}
#endif
}
static T_7 F_188 ( struct V_301 * V_302 , char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
if ( * V_304 > V_4 -> V_10 )
return V_307 ;
V_308 = F_33 ( * V_304 >> 2 ) ;
V_25 = F_189 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_190 ( struct V_301 * V_302 , const char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
if ( * V_304 > V_4 -> V_10 )
return V_307 ;
V_25 = F_191 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
F_34 ( * V_304 >> 2 , V_308 ) ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_192 ( struct V_301 * V_302 , char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
V_308 = F_193 ( * V_304 >> 2 ) ;
V_25 = F_189 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_194 ( struct V_301 * V_302 , const char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
V_25 = F_191 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
F_195 ( * V_304 >> 2 , V_308 ) ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_196 ( struct V_301 * V_302 , char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
V_308 = F_197 ( * V_304 >> 2 ) ;
V_25 = F_189 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_198 ( struct V_301 * V_302 , const char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
V_25 = F_191 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
F_199 ( * V_304 >> 2 , V_308 ) ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_200 ( struct V_301 * V_302 , char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
V_308 = F_201 ( * V_304 >> 2 ) ;
V_25 = F_189 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static T_7 F_202 ( struct V_301 * V_302 , const char T_8 * V_303 ,
T_4 V_42 , T_9 * V_304 )
{
struct V_3 * V_4 = V_302 -> V_305 -> V_306 ;
T_7 V_307 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_304 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_308 ;
V_25 = F_191 ( V_308 , ( T_1 * ) V_303 ) ;
if ( V_25 )
return V_25 ;
F_203 ( * V_304 >> 2 , V_308 ) ;
V_307 += 4 ;
V_303 += 4 ;
* V_304 += 4 ;
V_42 -= 4 ;
}
return V_307 ;
}
static int F_138 ( struct V_3 * V_4 )
{
struct V_309 * V_133 = V_4 -> V_88 -> V_247 ;
struct V_310 * V_311 , * V_312 = V_133 -> V_300 ;
unsigned V_38 , V_313 ;
for ( V_38 = 0 ; V_38 < F_204 ( V_314 ) ; V_38 ++ ) {
V_311 = F_205 ( V_315 [ V_38 ] ,
V_316 | V_317 , V_312 ,
V_4 , V_314 [ V_38 ] ) ;
if ( F_206 ( V_311 ) ) {
for ( V_313 = 0 ; V_313 < V_38 ; V_313 ++ ) {
F_207 ( V_4 -> V_314 [ V_38 ] ) ;
V_4 -> V_314 [ V_38 ] = NULL ;
}
return F_208 ( V_311 ) ;
}
if ( ! V_38 )
F_209 ( V_311 -> V_318 , V_4 -> V_10 ) ;
V_4 -> V_314 [ V_38 ] = V_311 ;
}
return 0 ;
}
static void F_150 ( struct V_3 * V_4 )
{
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < F_204 ( V_314 ) ; V_38 ++ ) {
if ( V_4 -> V_314 [ V_38 ] ) {
F_207 ( V_4 -> V_314 [ V_38 ] ) ;
V_4 -> V_314 [ V_38 ] = NULL ;
}
}
}
int F_210 ( struct V_309 * V_133 )
{
return 0 ;
}
void F_211 ( struct V_309 * V_133 )
{
}
static int F_138 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_150 ( struct V_3 * V_4 ) { }
