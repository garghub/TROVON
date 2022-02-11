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
bool F_58 ( struct V_3 * V_4 )
{
if ( F_57 ( V_4 ) )
return true ;
if ( V_4 -> V_73 ) {
F_42 ( L_16 ) ;
if ( V_4 -> V_74 )
F_59 ( V_4 -> V_75 . V_76 ) ;
return true ;
} else {
F_60 ( V_4 -> V_2 , L_17 ) ;
return false ;
}
}
int F_61 ( struct V_3 * V_4 )
{
if ( V_4 -> V_77 . V_78 )
return 0 ;
V_4 -> V_77 . V_78 = F_62 ( V_79 | V_80 | V_81 ) ;
if ( V_4 -> V_77 . V_78 == NULL )
return - V_45 ;
V_4 -> V_77 . V_82 = F_63 ( V_4 -> V_39 , V_4 -> V_77 . V_78 ,
0 , V_29 , V_83 ) ;
if ( F_64 ( V_4 -> V_39 , V_4 -> V_77 . V_82 ) ) {
F_60 ( & V_4 -> V_39 -> V_2 , L_18 ) ;
F_65 ( V_4 -> V_77 . V_78 ) ;
V_4 -> V_77 . V_78 = NULL ;
return - V_45 ;
}
return 0 ;
}
void F_66 ( struct V_3 * V_4 )
{
if ( V_4 -> V_77 . V_78 == NULL )
return;
F_67 ( V_4 -> V_39 , V_4 -> V_77 . V_82 ,
V_29 , V_83 ) ;
F_65 ( V_4 -> V_77 . V_78 ) ;
V_4 -> V_77 . V_78 = NULL ;
}
static T_1 F_68 ( struct V_84 * V_85 , T_1 V_8 )
{
return 0 ;
}
static void F_69 ( struct V_84 * V_85 , T_1 V_8 , T_1 V_86 )
{
}
static T_1 F_70 ( struct V_84 * V_85 , T_1 V_8 )
{
return 0 ;
}
static void F_71 ( struct V_84 * V_85 , T_1 V_8 , T_1 V_86 )
{
}
static void F_72 ( struct V_84 * V_85 , T_1 V_8 , T_1 V_86 )
{
struct V_3 * V_4 = V_85 -> V_2 -> V_5 ;
F_34 ( V_8 , V_86 ) ;
}
static T_1 F_73 ( struct V_84 * V_85 , T_1 V_8 )
{
struct V_3 * V_4 = V_85 -> V_2 -> V_5 ;
T_1 V_25 ;
V_25 = F_33 ( V_8 ) ;
return V_25 ;
}
static void F_74 ( struct V_84 * V_85 , T_1 V_8 , T_1 V_86 )
{
struct V_3 * V_4 = V_85 -> V_2 -> V_5 ;
F_75 ( V_8 , V_86 ) ;
}
static T_1 F_76 ( struct V_84 * V_85 , T_1 V_8 )
{
struct V_3 * V_4 = V_85 -> V_2 -> V_5 ;
T_1 V_25 ;
V_25 = F_77 ( V_8 ) ;
return V_25 ;
}
static void F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_75 . V_76 )
F_79 ( V_4 -> V_75 . V_76 -> V_87 ) ;
F_79 ( V_4 -> V_75 . V_76 ) ;
V_4 -> V_75 . V_76 = NULL ;
F_79 ( V_4 -> V_75 . V_88 ) ;
V_4 -> V_75 . V_88 = NULL ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_84 * V_88 =
F_81 ( sizeof( struct V_84 ) , V_80 ) ;
if ( ! V_88 )
return - V_45 ;
V_4 -> V_75 . V_88 = V_88 ;
V_88 -> V_2 = V_4 -> V_89 ;
V_88 -> V_90 = F_73 ;
V_88 -> V_91 = F_72 ;
if ( V_4 -> V_19 ) {
V_88 -> V_92 = F_76 ;
V_88 -> V_93 = F_74 ;
} else {
F_13 ( L_19 ) ;
V_88 -> V_92 = F_73 ;
V_88 -> V_93 = F_72 ;
}
V_88 -> V_94 = F_70 ;
V_88 -> V_95 = F_71 ;
V_88 -> V_96 = F_68 ;
V_88 -> V_97 = F_69 ;
V_4 -> V_75 . V_76 = F_82 ( V_88 , V_4 -> V_73 ) ;
if ( ! V_4 -> V_75 . V_76 ) {
F_78 ( V_4 ) ;
return - V_45 ;
}
F_83 ( & V_4 -> V_75 . V_76 -> V_98 ) ;
F_84 ( V_4 ) ;
F_85 ( V_4 -> V_75 . V_76 ) ;
return 0 ;
}
static unsigned int F_86 ( void * V_99 , bool V_100 )
{
struct V_3 * V_4 = V_99 ;
F_87 ( V_4 , V_100 ) ;
if ( V_100 )
return V_101 | V_102 |
V_103 | V_104 ;
else
return V_103 | V_104 ;
}
static bool F_88 ( int V_105 )
{
return ( V_105 & ( V_105 - 1 ) ) == 0 ;
}
static void F_89 ( struct V_3 * V_4 )
{
if ( ! F_88 ( V_59 ) ) {
F_48 ( V_4 -> V_2 , L_20 ,
V_59 ) ;
V_59 = 0 ;
}
if ( V_106 != - 1 ) {
if ( V_106 < 32 ) {
F_48 ( V_4 -> V_2 , L_21 ,
V_106 ) ;
V_106 = - 1 ;
} else if ( ! F_88 ( V_106 ) ) {
F_48 ( V_4 -> V_2 , L_22 ,
V_106 ) ;
V_106 = - 1 ;
}
}
if ( ! F_88 ( V_107 ) ) {
F_48 ( V_4 -> V_2 , L_23 ,
V_107 ) ;
V_107 = 8 ;
}
if ( V_107 < 1 ) {
F_48 ( V_4 -> V_2 , L_24 ,
V_107 ) ;
V_107 = 8 ;
}
if ( V_107 > 1024 ) {
F_48 ( V_4 -> V_2 , L_25 ,
V_107 ) ;
V_107 = 8 ;
}
if ( V_108 == - 1 ) {
unsigned V_109 = F_90 ( V_107 ) + 18 ;
if ( V_107 <= 8 )
V_108 = V_109 - 9 ;
else
V_108 = ( V_109 + 3 ) / 2 ;
} else if ( V_108 < 9 ) {
F_48 ( V_4 -> V_2 , L_26 ,
V_108 ) ;
V_108 = 9 ;
}
if ( V_108 > 24 ||
( V_107 * 1024 ) < ( 1ull << V_108 ) ) {
F_48 ( V_4 -> V_2 , L_27 ,
V_108 ) ;
V_108 = 9 ;
}
}
static void F_91 ( struct V_110 * V_39 , enum V_111 V_100 )
{
struct V_1 * V_2 = F_92 ( V_39 ) ;
if ( F_1 ( V_2 ) && V_100 == V_112 )
return;
if ( V_100 == V_113 ) {
unsigned V_114 = V_2 -> V_39 -> V_114 ;
F_93 ( V_115 L_28 ) ;
V_2 -> V_116 = V_117 ;
F_94 ( V_2 , true , true ) ;
V_2 -> V_39 -> V_114 = V_114 ;
V_2 -> V_116 = V_118 ;
F_95 ( V_2 ) ;
} else {
F_93 ( V_115 L_29 ) ;
F_96 ( V_2 ) ;
V_2 -> V_116 = V_117 ;
F_97 ( V_2 , true , true ) ;
V_2 -> V_116 = V_119 ;
}
}
static bool F_98 ( struct V_110 * V_39 )
{
struct V_1 * V_2 = F_92 ( V_39 ) ;
return V_2 -> V_120 == 0 ;
}
int F_99 ( struct V_3 * V_4 ,
enum V_121 V_122 ,
enum V_123 V_100 )
{
int V_38 , V_25 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( V_4 -> V_125 [ V_38 ] . type == V_122 ) {
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_127 ( ( void * ) V_4 ,
V_100 ) ;
if ( V_25 )
return V_25 ;
}
}
return V_25 ;
}
int F_100 ( struct V_3 * V_4 ,
enum V_121 V_122 ,
enum V_128 V_100 )
{
int V_38 , V_25 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( V_4 -> V_125 [ V_38 ] . type == V_122 ) {
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_129 ( ( void * ) V_4 ,
V_100 ) ;
if ( V_25 )
return V_25 ;
}
}
return V_25 ;
}
const struct V_130 * F_101 (
struct V_3 * V_4 ,
enum V_121 type )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ )
if ( V_4 -> V_125 [ V_38 ] . type == type )
return & V_4 -> V_125 [ V_38 ] ;
return NULL ;
}
int F_102 ( struct V_3 * V_4 ,
enum V_121 type ,
T_2 V_131 , T_2 V_132 )
{
const struct V_130 * V_133 ;
V_133 = F_101 ( V_4 , type ) ;
if ( V_133 && ( ( V_133 -> V_131 > V_131 ) ||
( ( V_133 -> V_131 == V_131 ) &&
( V_133 -> V_132 >= V_132 ) ) ) )
return 0 ;
return 1 ;
}
static int F_103 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
switch ( V_4 -> V_134 ) {
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
if ( V_4 -> V_134 == V_138 || V_4 -> V_134 == V_139 )
V_4 -> V_140 = V_141 ;
else
V_4 -> V_140 = V_142 ;
V_25 = F_104 ( V_4 ) ;
if ( V_25 )
return V_25 ;
break;
#ifdef F_105
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
if ( ( V_4 -> V_134 == V_143 ) || ( V_4 -> V_134 == V_144 ) )
V_4 -> V_140 = V_148 ;
else
V_4 -> V_140 = V_149 ;
V_25 = F_106 ( V_4 ) ;
if ( V_25 )
return V_25 ;
break;
#endif
default:
return - V_44 ;
}
V_4 -> V_150 = F_107 ( V_4 -> V_124 ,
sizeof( struct V_151 ) , V_80 ) ;
if ( V_4 -> V_150 == NULL )
return - V_45 ;
if ( V_4 -> V_125 == NULL ) {
F_13 ( L_30 ) ;
return V_25 ;
}
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( ( V_152 & ( 1 << V_38 ) ) == 0 ) {
F_13 ( L_31 , V_38 ) ;
V_4 -> V_150 [ V_38 ] . V_153 = false ;
} else {
if ( V_4 -> V_125 [ V_38 ] . V_126 -> V_154 ) {
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_154 ( ( void * ) V_4 ) ;
if ( V_25 == - V_155 )
V_4 -> V_150 [ V_38 ] . V_153 = false ;
else if ( V_25 )
return V_25 ;
else
V_4 -> V_150 [ V_38 ] . V_153 = true ;
} else {
V_4 -> V_150 [ V_38 ] . V_153 = true ;
}
}
}
return 0 ;
}
static int F_108 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_153 )
continue;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_156 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_150 [ V_38 ] . V_157 = true ;
if ( V_4 -> V_125 [ V_38 ] . type == V_158 ) {
V_25 = F_20 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_159 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_47 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_150 [ V_38 ] . V_160 = true ;
}
}
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_157 )
continue;
if ( V_4 -> V_125 [ V_38 ] . type == V_158 )
continue;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_159 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_150 [ V_38 ] . V_160 = true ;
}
return 0 ;
}
static int F_109 ( struct V_3 * V_4 )
{
int V_38 = 0 , V_25 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_153 )
continue;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_127 ( ( void * ) V_4 ,
V_161 ) ;
if ( V_25 )
return V_25 ;
if ( V_4 -> V_125 [ V_38 ] . V_126 -> V_162 ) {
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_162 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
}
}
return 0 ;
}
static int F_110 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = V_4 -> V_124 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_160 )
continue;
if ( V_4 -> V_125 [ V_38 ] . type == V_158 ) {
F_46 ( V_4 ) ;
F_28 ( V_4 ) ;
}
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_127 ( ( void * ) V_4 ,
V_163 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_164 ( ( void * ) V_4 ) ;
V_4 -> V_150 [ V_38 ] . V_160 = false ;
}
for ( V_38 = V_4 -> V_124 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_157 )
continue;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_165 ( ( void * ) V_4 ) ;
V_4 -> V_150 [ V_38 ] . V_157 = false ;
V_4 -> V_150 [ V_38 ] . V_153 = false ;
}
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = V_4 -> V_124 - 1 ; V_38 >= 0 ; V_38 -- ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_153 )
continue;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_127 ( ( void * ) V_4 ,
V_163 ) ;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_166 ( V_4 ) ;
}
return 0 ;
}
static int F_112 ( struct V_3 * V_4 )
{
int V_38 , V_25 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_124 ; V_38 ++ ) {
if ( ! V_4 -> V_150 [ V_38 ] . V_153 )
continue;
V_25 = V_4 -> V_125 [ V_38 ] . V_126 -> V_167 ( V_4 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
int F_113 ( struct V_3 * V_4 ,
struct V_1 * V_89 ,
struct V_110 * V_39 ,
T_1 V_6 )
{
int V_25 , V_38 ;
bool V_168 = false ;
V_4 -> V_169 = false ;
V_4 -> V_2 = & V_39 -> V_2 ;
V_4 -> V_89 = V_89 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_134 = V_6 & V_170 ;
V_4 -> V_74 = false ;
V_4 -> V_171 = V_172 ;
V_4 -> V_57 . V_69 = 512 * 1024 * 1024 ;
V_4 -> V_173 = false ;
V_4 -> V_174 = 0 ;
V_4 -> V_175 . V_176 = NULL ;
V_4 -> V_175 . V_177 = NULL ;
V_4 -> V_178 . V_179 = NULL ;
V_4 -> V_178 . V_180 = NULL ;
V_4 -> V_181 . V_182 = NULL ;
V_4 -> V_183 = F_114 ( V_184 ) ;
V_4 -> V_185 = & F_15 ;
V_4 -> V_186 = & F_17 ;
V_4 -> V_187 = & F_15 ;
V_4 -> V_188 = & F_17 ;
V_4 -> V_189 = & F_15 ;
V_4 -> V_190 = & F_17 ;
V_4 -> V_191 = & F_15 ;
V_4 -> V_192 = & F_17 ;
V_4 -> V_193 = & F_18 ;
V_4 -> V_194 = & F_19 ;
F_42 ( L_32 ,
V_195 [ V_4 -> V_134 ] , V_39 -> V_196 , V_39 -> V_197 ,
V_39 -> V_198 , V_39 -> V_199 , V_39 -> V_200 ) ;
F_83 ( & V_4 -> V_201 ) ;
F_115 ( & V_4 -> V_202 . V_203 . V_204 , 0 ) ;
F_83 ( & V_4 -> V_205 . V_98 ) ;
F_83 ( & V_4 -> V_206 . V_98 ) ;
F_83 ( & V_4 -> V_207 . V_208 ) ;
F_83 ( & V_4 -> V_209 ) ;
F_83 ( & V_4 -> V_210 ) ;
F_83 ( & V_4 -> V_211 ) ;
F_116 ( V_4 -> V_212 ) ;
F_89 ( V_4 ) ;
F_117 ( & V_4 -> V_14 ) ;
F_117 ( & V_4 -> V_213 ) ;
F_117 ( & V_4 -> V_214 ) ;
F_117 ( & V_4 -> V_215 ) ;
F_117 ( & V_4 -> V_216 ) ;
F_117 ( & V_4 -> V_217 ) ;
V_4 -> V_218 = F_38 ( V_4 -> V_39 , 5 ) ;
V_4 -> V_10 = F_39 ( V_4 -> V_39 , 5 ) ;
V_4 -> V_12 = F_41 ( V_4 -> V_218 , V_4 -> V_10 ) ;
if ( V_4 -> V_12 == NULL ) {
return - V_45 ;
}
F_42 ( L_33 , ( T_1 ) V_4 -> V_218 ) ;
F_42 ( L_34 , ( unsigned ) V_4 -> V_10 ) ;
F_37 ( V_4 ) ;
for ( V_38 = 0 ; V_38 < V_219 ; V_38 ++ ) {
if ( F_118 ( V_4 -> V_39 , V_38 ) & V_220 ) {
V_4 -> V_18 = F_39 ( V_4 -> V_39 , V_38 ) ;
V_4 -> V_19 = F_119 ( V_4 -> V_39 , V_38 , V_4 -> V_18 ) ;
break;
}
}
if ( V_4 -> V_19 == NULL )
F_13 ( L_35 ) ;
V_25 = F_103 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_120 ( V_4 -> V_39 , V_4 , NULL , F_86 ) ;
if ( V_221 == 1 )
V_168 = true ;
if ( F_1 ( V_89 ) )
V_168 = true ;
F_121 ( V_4 -> V_39 , & V_222 , V_168 ) ;
if ( V_168 )
F_122 ( V_4 -> V_2 , & V_4 -> V_223 ) ;
if ( ! F_123 ( V_4 ) )
return - V_44 ;
if ( ! V_4 -> V_74 ) {
F_60 ( V_4 -> V_2 , L_36 ) ;
return - V_44 ;
}
V_25 = F_80 ( V_4 ) ;
if ( V_25 )
return V_25 ;
if ( ! F_57 ( V_4 ) ) {
if ( ! V_4 -> V_73 ) {
F_60 ( V_4 -> V_2 , L_17 ) ;
return - V_44 ;
}
F_42 ( L_16 ) ;
F_59 ( V_4 -> V_75 . V_76 ) ;
}
V_25 = F_124 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_125 ( V_4 ) ;
V_25 = F_126 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_127 ( V_4 -> V_89 ) ;
V_25 = F_108 ( V_4 ) ;
if ( V_25 ) {
F_110 ( V_4 ) ;
return V_25 ;
}
V_4 -> V_173 = true ;
F_128 ( V_4 ) ;
V_25 = F_129 ( V_4 ) ;
if ( V_25 ) {
F_60 ( V_4 -> V_2 , L_37 , V_25 ) ;
return V_25 ;
}
V_25 = F_130 ( V_4 , true , & V_4 -> V_224 ) ;
if ( V_25 ) {
F_60 ( V_4 -> V_2 , L_38 , V_25 ) ;
return V_25 ;
}
V_25 = F_131 ( V_4 ) ;
if ( V_25 )
F_13 ( L_39 , V_25 ) ;
V_25 = F_132 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_40 , V_25 ) ;
}
V_25 = F_133 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_41 , V_25 ) ;
}
if ( ( V_225 & 1 ) ) {
if ( V_4 -> V_173 )
F_134 ( V_4 ) ;
else
F_42 ( L_42 ) ;
}
if ( ( V_225 & 2 ) ) {
if ( V_4 -> V_173 )
F_135 ( V_4 ) ;
else
F_42 ( L_43 ) ;
}
if ( V_226 ) {
if ( V_4 -> V_173 )
F_136 ( V_4 , V_226 ) ;
else
F_42 ( L_44 ) ;
}
V_25 = F_109 ( V_4 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
void F_137 ( struct V_3 * V_4 )
{
int V_25 ;
F_42 ( L_45 ) ;
V_4 -> V_169 = true ;
F_138 ( V_4 ) ;
F_139 ( & V_4 -> V_224 ) ;
F_140 ( V_4 ) ;
F_141 ( V_4 ) ;
F_142 ( V_4 ) ;
V_25 = F_110 ( V_4 ) ;
F_79 ( V_4 -> V_150 ) ;
V_4 -> V_150 = NULL ;
V_4 -> V_173 = false ;
F_143 ( V_4 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 -> V_73 ) ;
V_4 -> V_73 = NULL ;
F_144 ( V_4 -> V_39 ) ;
F_120 ( V_4 -> V_39 , NULL , NULL , NULL ) ;
if ( V_4 -> V_19 )
F_145 ( V_4 -> V_39 , V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_44 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
F_43 ( V_4 ) ;
F_146 ( V_4 ) ;
F_147 ( V_4 ) ;
}
int F_97 ( struct V_1 * V_2 , bool V_166 , bool V_227 )
{
struct V_3 * V_4 ;
struct V_228 * V_229 ;
struct V_230 * V_231 ;
int V_25 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_232 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_116 == V_119 )
return 0 ;
F_96 ( V_2 ) ;
F_148 ( V_2 ) ;
F_149 (connector, &dev->mode_config.connector_list, head) {
F_150 ( V_231 , V_233 ) ;
}
F_151 ( V_2 ) ;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
struct V_234 * V_234 = F_152 ( V_229 ) ;
struct V_235 * V_236 = F_153 ( V_229 -> V_237 -> V_238 ) ;
struct V_239 * V_27 ;
if ( V_234 -> V_240 ) {
struct V_239 * V_241 = F_154 ( V_234 -> V_240 ) ;
V_25 = F_22 ( V_241 , false ) ;
if ( V_25 == 0 ) {
F_27 ( V_241 ) ;
F_25 ( V_241 ) ;
}
}
if ( V_236 == NULL || V_236 -> V_242 == NULL ) {
continue;
}
V_27 = F_154 ( V_236 -> V_242 ) ;
if ( ! F_155 ( V_4 , V_27 ) ) {
V_25 = F_22 ( V_27 , false ) ;
if ( V_25 == 0 ) {
F_27 ( V_27 ) ;
F_25 ( V_27 ) ;
}
}
}
F_138 ( V_4 ) ;
F_156 ( V_4 ) ;
V_25 = F_111 ( V_4 ) ;
F_138 ( V_4 ) ;
F_157 ( V_2 -> V_39 ) ;
if ( V_166 ) {
F_158 ( V_2 -> V_39 ) ;
F_159 ( V_2 -> V_39 , V_243 ) ;
}
if ( V_227 ) {
F_160 () ;
F_161 ( V_4 , 1 ) ;
F_162 () ;
}
return 0 ;
}
int F_94 ( struct V_1 * V_2 , bool V_167 , bool V_227 )
{
struct V_230 * V_231 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_228 * V_229 ;
int V_25 ;
if ( V_2 -> V_116 == V_119 )
return 0 ;
if ( V_227 ) {
F_160 () ;
}
if ( V_167 ) {
F_159 ( V_2 -> V_39 , V_244 ) ;
F_163 ( V_2 -> V_39 ) ;
if ( F_164 ( V_2 -> V_39 ) ) {
if ( V_227 )
F_162 () ;
return - 1 ;
}
}
F_59 ( V_4 -> V_75 . V_76 ) ;
V_25 = F_112 ( V_4 ) ;
F_165 ( V_4 ) ;
V_25 = F_131 ( V_4 ) ;
if ( V_25 )
F_13 ( L_39 , V_25 ) ;
V_25 = F_109 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_149 (crtc, &dev->mode_config.crtc_list, head) {
struct V_234 * V_234 = F_152 ( V_229 ) ;
if ( V_234 -> V_240 ) {
struct V_239 * V_241 = F_154 ( V_234 -> V_240 ) ;
V_25 = F_22 ( V_241 , false ) ;
if ( V_25 == 0 ) {
V_25 = F_24 ( V_241 ,
V_30 ,
& V_234 -> V_245 ) ;
if ( V_25 != 0 )
F_13 ( L_46 , V_25 ) ;
F_25 ( V_241 ) ;
}
}
}
if ( V_227 ) {
F_166 ( V_2 ) ;
F_148 ( V_2 ) ;
F_149 (connector, &dev->mode_config.connector_list, head) {
F_150 ( V_231 , V_246 ) ;
}
F_151 ( V_2 ) ;
}
F_95 ( V_2 ) ;
if ( V_227 ) {
F_161 ( V_4 , 0 ) ;
F_162 () ;
}
return 0 ;
}
int F_167 ( struct V_3 * V_4 )
{
unsigned V_247 [ V_184 ] ;
T_1 * V_248 [ V_184 ] ;
bool V_249 = false ;
int V_38 , V_25 ;
int V_250 ;
F_168 ( & V_4 -> V_251 ) ;
V_250 = F_169 ( & V_4 -> V_175 . V_252 ) ;
V_25 = F_111 ( V_4 ) ;
for ( V_38 = 0 ; V_38 < V_184 ; ++ V_38 ) {
struct V_253 * V_254 = V_4 -> V_255 [ V_38 ] ;
if ( ! V_254 )
continue;
V_247 [ V_38 ] = F_170 ( V_254 , & V_248 [ V_38 ] ) ;
if ( V_247 [ V_38 ] ) {
V_249 = true ;
F_55 ( V_4 -> V_2 , L_47
L_48 , V_247 [ V_38 ] , V_38 ) ;
}
}
V_256:
V_25 = F_171 ( V_4 ) ;
if ( ! V_25 ) {
F_55 ( V_4 -> V_2 , L_49 ) ;
V_25 = F_112 ( V_4 ) ;
}
if ( ! V_25 ) {
for ( V_38 = 0 ; V_38 < V_184 ; ++ V_38 ) {
struct V_253 * V_254 = V_4 -> V_255 [ V_38 ] ;
if ( ! V_254 )
continue;
F_172 ( V_254 , V_247 [ V_38 ] , V_248 [ V_38 ] ) ;
V_247 [ V_38 ] = 0 ;
V_248 [ V_38 ] = NULL ;
}
V_25 = F_131 ( V_4 ) ;
if ( V_25 ) {
F_60 ( V_4 -> V_2 , L_39 , V_25 ) ;
if ( V_249 ) {
V_249 = false ;
V_25 = F_111 ( V_4 ) ;
goto V_256;
}
}
} else {
F_173 ( V_4 ) ;
for ( V_38 = 0 ; V_38 < V_184 ; ++ V_38 ) {
if ( V_4 -> V_255 [ V_38 ] )
F_79 ( V_248 [ V_38 ] ) ;
}
}
F_166 ( V_4 -> V_89 ) ;
F_174 ( & V_4 -> V_175 . V_252 , V_250 ) ;
if ( V_25 ) {
F_55 ( V_4 -> V_2 , L_50 ) ;
}
return V_25 ;
}
int F_175 ( struct V_3 * V_4 ,
struct V_257 * V_258 ,
unsigned V_259 )
{
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_260 ; V_38 ++ ) {
if ( V_4 -> V_261 [ V_38 ] . V_258 == V_258 ) {
return 0 ;
}
}
V_38 = V_4 -> V_260 + 1 ;
if ( V_38 > V_262 ) {
F_13 ( L_51 ) ;
F_13 ( L_52
L_53 ) ;
return - V_44 ;
}
V_4 -> V_261 [ V_4 -> V_260 ] . V_258 = V_258 ;
V_4 -> V_261 [ V_4 -> V_260 ] . V_263 = V_259 ;
V_4 -> V_260 = V_38 ;
#if F_176 ( V_264 )
F_177 ( V_258 , V_259 ,
V_4 -> V_89 -> V_265 -> V_266 ,
V_4 -> V_89 -> V_265 ) ;
F_177 ( V_258 , V_259 ,
V_4 -> V_89 -> V_237 -> V_266 ,
V_4 -> V_89 -> V_237 ) ;
#endif
return 0 ;
}
static void F_147 ( struct V_3 * V_4 )
{
#if F_176 ( V_264 )
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_260 ; V_38 ++ ) {
F_178 ( V_4 -> V_261 [ V_38 ] . V_258 ,
V_4 -> V_261 [ V_38 ] . V_263 ,
V_4 -> V_89 -> V_265 ) ;
F_178 ( V_4 -> V_261 [ V_38 ] . V_258 ,
V_4 -> V_261 [ V_38 ] . V_263 ,
V_4 -> V_89 -> V_237 ) ;
}
#endif
}
static T_7 F_179 ( struct V_267 * V_268 , char T_8 * V_269 ,
T_4 V_42 , T_9 * V_270 )
{
struct V_3 * V_4 = V_268 -> V_271 -> V_272 ;
T_7 V_273 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_270 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_274 ;
if ( * V_270 > V_4 -> V_10 )
return V_273 ;
V_274 = F_33 ( * V_270 >> 2 ) ;
V_25 = F_180 ( V_274 , ( T_1 * ) V_269 ) ;
if ( V_25 )
return V_25 ;
V_273 += 4 ;
V_269 += 4 ;
* V_270 += 4 ;
V_42 -= 4 ;
}
return V_273 ;
}
static T_7 F_181 ( struct V_267 * V_268 , const char T_8 * V_269 ,
T_4 V_42 , T_9 * V_270 )
{
struct V_3 * V_4 = V_268 -> V_271 -> V_272 ;
T_7 V_273 = 0 ;
int V_25 ;
if ( V_42 & 0x3 || * V_270 & 0x3 )
return - V_44 ;
while ( V_42 ) {
T_1 V_274 ;
if ( * V_270 > V_4 -> V_10 )
return V_273 ;
V_25 = F_182 ( V_274 , ( T_1 * ) V_269 ) ;
if ( V_25 )
return V_25 ;
F_34 ( * V_270 >> 2 , V_274 ) ;
V_273 += 4 ;
V_269 += 4 ;
* V_270 += 4 ;
V_42 -= 4 ;
}
return V_273 ;
}
static int F_133 ( struct V_3 * V_4 )
{
struct V_275 * V_132 = V_4 -> V_89 -> V_237 ;
struct V_276 * V_277 , * V_278 = V_132 -> V_266 ;
V_277 = F_183 ( L_54 , V_279 | V_280 , V_278 ,
V_4 , & V_281 ) ;
if ( F_184 ( V_277 ) )
return F_185 ( V_277 ) ;
F_186 ( V_277 -> V_282 , V_4 -> V_10 ) ;
V_4 -> V_283 = V_277 ;
return 0 ;
}
static void F_146 ( struct V_3 * V_4 )
{
F_187 ( V_4 -> V_283 ) ;
V_4 -> V_283 = NULL ;
}
int F_188 ( struct V_275 * V_132 )
{
return 0 ;
}
void F_189 ( struct V_275 * V_132 )
{
}
static int F_133 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_146 ( struct V_3 * V_4 ) { }
