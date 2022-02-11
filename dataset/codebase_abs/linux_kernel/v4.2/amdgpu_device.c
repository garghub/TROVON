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
V_29 , true , V_30 , 0 ,
NULL , & V_4 -> V_26 . V_27 ) ;
if ( V_25 ) {
return V_25 ;
}
}
V_25 = F_22 ( V_4 -> V_26 . V_27 , false ) ;
if ( F_23 ( V_25 != 0 ) )
return V_25 ;
V_25 = F_24 ( V_4 -> V_26 . V_27 ,
V_30 , & V_4 -> V_26 . V_31 ) ;
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
const T_2 * V_32 ,
const T_2 V_33 )
{
T_2 V_34 , V_8 , V_35 , V_36 ;
int V_37 ;
if ( V_33 % 3 )
return;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 += 3 ) {
V_8 = V_32 [ V_37 + 0 ] ;
V_35 = V_32 [ V_37 + 1 ] ;
V_36 = V_32 [ V_37 + 2 ] ;
if ( V_35 == 0xffffffff ) {
V_34 = V_36 ;
} else {
V_34 = F_33 ( V_8 ) ;
V_34 &= ~ V_35 ;
V_34 |= V_36 ;
}
F_34 ( V_8 , V_34 ) ;
}
}
void F_35 ( struct V_3 * V_4 )
{
F_36 ( V_4 -> V_38 , 0x7c , V_39 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
V_4 -> V_21 . V_40 = F_38 ( V_4 -> V_38 , 2 ) ;
V_4 -> V_21 . V_41 = F_39 ( V_4 -> V_38 , 2 ) ;
V_4 -> V_21 . V_22 = F_40 ( T_2 , V_4 -> V_21 . V_41 / sizeof( T_2 ) ,
V_42 + 1 ) ;
if ( V_4 -> V_21 . V_22 == 0 )
return - V_43 ;
V_4 -> V_21 . V_23 = F_41 ( V_4 -> V_21 . V_40 , V_4 -> V_21 . V_22 * sizeof( T_2 ) ) ;
if ( V_4 -> V_21 . V_23 == NULL ) {
return - V_44 ;
}
F_42 ( L_7 , ( T_1 ) V_4 -> V_21 . V_40 ) ;
F_42 ( L_8 , ( unsigned ) V_4 -> V_21 . V_41 ) ;
return 0 ;
}
static void F_43 ( struct V_3 * V_4 )
{
F_44 ( V_4 -> V_21 . V_23 ) ;
V_4 -> V_21 . V_23 = NULL ;
}
void F_45 ( struct V_3 * V_4 ,
T_3 * V_45 ,
T_4 * V_46 ,
T_4 * V_47 )
{
if ( V_4 -> V_21 . V_41 > V_4 -> V_21 . V_22 * sizeof( T_2 ) ) {
* V_45 = V_4 -> V_21 . V_40 ;
* V_46 = V_4 -> V_21 . V_41 ;
* V_47 = V_4 -> V_21 . V_22 * sizeof( T_2 ) ;
} else {
* V_45 = 0 ;
* V_46 = 0 ;
* V_47 = 0 ;
}
}
static void F_46 ( struct V_3 * V_4 )
{
if ( V_4 -> V_48 . V_49 ) {
if ( ! F_22 ( V_4 -> V_48 . V_49 , false ) ) {
F_30 ( V_4 -> V_48 . V_49 ) ;
F_27 ( V_4 -> V_48 . V_49 ) ;
F_25 ( V_4 -> V_48 . V_49 ) ;
}
F_31 ( & V_4 -> V_48 . V_49 ) ;
V_4 -> V_48 . V_48 = NULL ;
V_4 -> V_48 . V_49 = NULL ;
}
}
static int F_47 ( struct V_3 * V_4 )
{
int V_25 ;
if ( V_4 -> V_48 . V_49 == NULL ) {
V_25 = F_21 ( V_4 , V_50 * 4 , V_29 , true ,
V_51 , 0 , NULL , & V_4 -> V_48 . V_49 ) ;
if ( V_25 ) {
F_48 ( V_4 -> V_2 , L_9 , V_25 ) ;
return V_25 ;
}
V_25 = F_22 ( V_4 -> V_48 . V_49 , false ) ;
if ( F_23 ( V_25 != 0 ) ) {
F_46 ( V_4 ) ;
return V_25 ;
}
V_25 = F_24 ( V_4 -> V_48 . V_49 , V_51 ,
& V_4 -> V_48 . V_31 ) ;
if ( V_25 ) {
F_25 ( V_4 -> V_48 . V_49 ) ;
F_48 ( V_4 -> V_2 , L_10 , V_25 ) ;
F_46 ( V_4 ) ;
return V_25 ;
}
V_25 = F_26 ( V_4 -> V_48 . V_49 , ( void * * ) & V_4 -> V_48 . V_48 ) ;
F_25 ( V_4 -> V_48 . V_49 ) ;
if ( V_25 ) {
F_48 ( V_4 -> V_2 , L_11 , V_25 ) ;
F_46 ( V_4 ) ;
return V_25 ;
}
V_4 -> V_48 . V_52 = V_50 ;
memset ( & V_4 -> V_48 . V_53 , 0 , sizeof( V_4 -> V_48 . V_53 ) ) ;
memset ( ( char * ) V_4 -> V_48 . V_48 , 0 , V_28 ) ;
}
return 0 ;
}
int F_49 ( struct V_3 * V_4 , T_2 * V_48 )
{
unsigned long V_54 = F_50 ( V_4 -> V_48 . V_53 , V_4 -> V_48 . V_52 ) ;
if ( V_54 < V_4 -> V_48 . V_52 ) {
F_51 ( V_54 , V_4 -> V_48 . V_53 ) ;
* V_48 = V_54 ;
return 0 ;
} else {
return - V_43 ;
}
}
void F_52 ( struct V_3 * V_4 , T_2 V_48 )
{
if ( V_48 < V_4 -> V_48 . V_52 )
F_53 ( V_48 , V_4 -> V_48 . V_53 ) ;
}
void F_54 ( struct V_3 * V_4 , struct V_55 * V_56 , T_5 V_40 )
{
T_6 V_57 = ( T_6 ) V_58 << 20 ;
V_56 -> V_59 = V_40 ;
if ( V_56 -> V_60 > ( V_4 -> V_56 . V_61 - V_40 + 1 ) ) {
F_48 ( V_4 -> V_2 , L_12 ) ;
V_56 -> V_62 = V_56 -> V_63 ;
V_56 -> V_60 = V_56 -> V_63 ;
}
V_56 -> V_64 = V_56 -> V_59 + V_56 -> V_60 - 1 ;
if ( V_57 && V_57 < V_56 -> V_62 )
V_56 -> V_62 = V_57 ;
F_55 ( V_4 -> V_2 , L_13 ,
V_56 -> V_60 >> 20 , V_56 -> V_59 ,
V_56 -> V_64 , V_56 -> V_62 >> 20 ) ;
}
void F_56 ( struct V_3 * V_4 , struct V_55 * V_56 )
{
T_5 V_65 , V_66 ;
V_65 = ( ( V_4 -> V_56 . V_61 - V_56 -> V_64 ) + V_56 -> V_67 ) & ~ V_56 -> V_67 ;
V_66 = V_56 -> V_59 & ~ V_56 -> V_67 ;
if ( V_66 > V_65 ) {
if ( V_56 -> V_68 > V_66 ) {
F_48 ( V_4 -> V_2 , L_14 ) ;
V_56 -> V_68 = V_66 ;
}
V_56 -> V_69 = ( V_56 -> V_59 & ~ V_56 -> V_67 ) - V_56 -> V_68 ;
} else {
if ( V_56 -> V_68 > V_65 ) {
F_48 ( V_4 -> V_2 , L_14 ) ;
V_56 -> V_68 = V_65 ;
}
V_56 -> V_69 = ( V_56 -> V_64 + 1 + V_56 -> V_67 ) & ~ V_56 -> V_67 ;
}
V_56 -> V_70 = V_56 -> V_69 + V_56 -> V_68 - 1 ;
F_55 ( V_4 -> V_2 , L_15 ,
V_56 -> V_68 >> 20 , V_56 -> V_69 , V_56 -> V_70 ) ;
}
bool F_57 ( struct V_3 * V_4 )
{
T_1 V_8 ;
V_8 = F_33 ( V_71 ) ;
if ( V_8 )
return true ;
return false ;
}
bool F_58 ( struct V_3 * V_4 )
{
if ( F_57 ( V_4 ) )
return true ;
if ( V_4 -> V_72 ) {
F_42 ( L_16 ) ;
if ( V_4 -> V_73 )
F_59 ( V_4 -> V_74 . V_75 ) ;
return true ;
} else {
F_60 ( V_4 -> V_2 , L_17 ) ;
return false ;
}
}
int F_61 ( struct V_3 * V_4 )
{
if ( V_4 -> V_76 . V_77 )
return 0 ;
V_4 -> V_76 . V_77 = F_62 ( V_78 | V_79 | V_80 ) ;
if ( V_4 -> V_76 . V_77 == NULL )
return - V_44 ;
V_4 -> V_76 . V_81 = F_63 ( V_4 -> V_38 , V_4 -> V_76 . V_77 ,
0 , V_29 , V_82 ) ;
if ( F_64 ( V_4 -> V_38 , V_4 -> V_76 . V_81 ) ) {
F_60 ( & V_4 -> V_38 -> V_2 , L_18 ) ;
F_65 ( V_4 -> V_76 . V_77 ) ;
V_4 -> V_76 . V_77 = NULL ;
return - V_44 ;
}
return 0 ;
}
void F_66 ( struct V_3 * V_4 )
{
if ( V_4 -> V_76 . V_77 == NULL )
return;
F_67 ( V_4 -> V_38 , V_4 -> V_76 . V_81 ,
V_29 , V_82 ) ;
F_65 ( V_4 -> V_76 . V_77 ) ;
V_4 -> V_76 . V_77 = NULL ;
}
static T_1 F_68 ( struct V_83 * V_84 , T_1 V_8 )
{
return 0 ;
}
static void F_69 ( struct V_83 * V_84 , T_1 V_8 , T_1 V_85 )
{
}
static T_1 F_70 ( struct V_83 * V_84 , T_1 V_8 )
{
return 0 ;
}
static void F_71 ( struct V_83 * V_84 , T_1 V_8 , T_1 V_85 )
{
}
static void F_72 ( struct V_83 * V_84 , T_1 V_8 , T_1 V_85 )
{
struct V_3 * V_4 = V_84 -> V_2 -> V_5 ;
F_34 ( V_8 , V_85 ) ;
}
static T_1 F_73 ( struct V_83 * V_84 , T_1 V_8 )
{
struct V_3 * V_4 = V_84 -> V_2 -> V_5 ;
T_1 V_25 ;
V_25 = F_33 ( V_8 ) ;
return V_25 ;
}
static void F_74 ( struct V_83 * V_84 , T_1 V_8 , T_1 V_85 )
{
struct V_3 * V_4 = V_84 -> V_2 -> V_5 ;
F_75 ( V_8 , V_85 ) ;
}
static T_1 F_76 ( struct V_83 * V_84 , T_1 V_8 )
{
struct V_3 * V_4 = V_84 -> V_2 -> V_5 ;
T_1 V_25 ;
V_25 = F_77 ( V_8 ) ;
return V_25 ;
}
static void F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_74 . V_75 )
F_79 ( V_4 -> V_74 . V_75 -> V_86 ) ;
F_79 ( V_4 -> V_74 . V_75 ) ;
V_4 -> V_74 . V_75 = NULL ;
F_79 ( V_4 -> V_74 . V_87 ) ;
V_4 -> V_74 . V_87 = NULL ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_83 * V_87 =
F_81 ( sizeof( struct V_83 ) , V_79 ) ;
if ( ! V_87 )
return - V_44 ;
V_4 -> V_74 . V_87 = V_87 ;
V_87 -> V_2 = V_4 -> V_88 ;
V_87 -> V_89 = F_73 ;
V_87 -> V_90 = F_72 ;
if ( V_4 -> V_19 ) {
V_87 -> V_91 = F_76 ;
V_87 -> V_92 = F_74 ;
} else {
F_13 ( L_19 ) ;
V_87 -> V_91 = F_73 ;
V_87 -> V_92 = F_72 ;
}
V_87 -> V_93 = F_70 ;
V_87 -> V_94 = F_71 ;
V_87 -> V_95 = F_68 ;
V_87 -> V_96 = F_69 ;
V_4 -> V_74 . V_75 = F_82 ( V_87 , V_4 -> V_72 ) ;
if ( ! V_4 -> V_74 . V_75 ) {
F_78 ( V_4 ) ;
return - V_44 ;
}
F_83 ( & V_4 -> V_74 . V_75 -> V_97 ) ;
F_84 ( V_4 ) ;
F_85 ( V_4 -> V_74 . V_75 ) ;
return 0 ;
}
static unsigned int F_86 ( void * V_98 , bool V_99 )
{
struct V_3 * V_4 = V_98 ;
F_87 ( V_4 , V_99 ) ;
if ( V_99 )
return V_100 | V_101 |
V_102 | V_103 ;
else
return V_102 | V_103 ;
}
static bool F_88 ( int V_104 )
{
return ( V_104 & ( V_104 - 1 ) ) == 0 ;
}
static void F_89 ( struct V_3 * V_4 )
{
if ( ! F_88 ( V_58 ) ) {
F_48 ( V_4 -> V_2 , L_20 ,
V_58 ) ;
V_58 = 0 ;
}
if ( V_105 != - 1 ) {
if ( V_105 < 32 ) {
F_48 ( V_4 -> V_2 , L_21 ,
V_105 ) ;
V_105 = - 1 ;
} else if ( ! F_88 ( V_105 ) ) {
F_48 ( V_4 -> V_2 , L_22 ,
V_105 ) ;
V_105 = - 1 ;
}
}
if ( ! F_88 ( V_106 ) ) {
F_48 ( V_4 -> V_2 , L_23 ,
V_106 ) ;
V_106 = 8 ;
}
if ( V_106 < 1 ) {
F_48 ( V_4 -> V_2 , L_24 ,
V_106 ) ;
V_106 = 8 ;
}
if ( V_106 > 1024 ) {
F_48 ( V_4 -> V_2 , L_25 ,
V_106 ) ;
V_106 = 8 ;
}
if ( V_107 == - 1 ) {
unsigned V_108 = F_90 ( V_106 ) + 18 ;
if ( V_106 <= 8 )
V_107 = V_108 - 9 ;
else
V_107 = ( V_108 + 3 ) / 2 ;
} else if ( V_107 < 9 ) {
F_48 ( V_4 -> V_2 , L_26 ,
V_107 ) ;
V_107 = 9 ;
}
if ( V_107 > 24 ||
( V_106 * 1024 ) < ( 1ull << V_107 ) ) {
F_48 ( V_4 -> V_2 , L_27 ,
V_107 ) ;
V_107 = 9 ;
}
}
static void F_91 ( struct V_109 * V_38 , enum V_110 V_99 )
{
struct V_1 * V_2 = F_92 ( V_38 ) ;
if ( F_1 ( V_2 ) && V_99 == V_111 )
return;
if ( V_99 == V_112 ) {
unsigned V_113 = V_2 -> V_38 -> V_113 ;
F_93 ( V_114 L_28 ) ;
V_2 -> V_115 = V_116 ;
F_94 ( V_2 , true , true ) ;
V_2 -> V_38 -> V_113 = V_113 ;
V_2 -> V_115 = V_117 ;
F_95 ( V_2 ) ;
} else {
F_93 ( V_114 L_29 ) ;
F_96 ( V_2 ) ;
V_2 -> V_115 = V_116 ;
F_97 ( V_2 , true , true ) ;
V_2 -> V_115 = V_118 ;
}
}
static bool F_98 ( struct V_109 * V_38 )
{
struct V_1 * V_2 = F_92 ( V_38 ) ;
return V_2 -> V_119 == 0 ;
}
int F_99 ( struct V_3 * V_4 ,
enum V_120 V_121 ,
enum V_122 V_99 )
{
int V_37 , V_25 = 0 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( V_4 -> V_124 [ V_37 ] . type == V_121 ) {
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_126 ( ( void * ) V_4 ,
V_99 ) ;
if ( V_25 )
return V_25 ;
}
}
return V_25 ;
}
int F_100 ( struct V_3 * V_4 ,
enum V_120 V_121 ,
enum V_127 V_99 )
{
int V_37 , V_25 = 0 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( V_4 -> V_124 [ V_37 ] . type == V_121 ) {
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_128 ( ( void * ) V_4 ,
V_99 ) ;
if ( V_25 )
return V_25 ;
}
}
return V_25 ;
}
const struct V_129 * F_101 (
struct V_3 * V_4 ,
enum V_120 type )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ )
if ( V_4 -> V_124 [ V_37 ] . type == type )
return & V_4 -> V_124 [ V_37 ] ;
return NULL ;
}
int F_102 ( struct V_3 * V_4 ,
enum V_120 type ,
T_2 V_130 , T_2 V_131 )
{
const struct V_129 * V_132 ;
V_132 = F_101 ( V_4 , type ) ;
if ( V_132 && ( ( V_132 -> V_130 > V_130 ) ||
( ( V_132 -> V_130 == V_130 ) &&
( V_132 -> V_131 >= V_131 ) ) ) )
return 0 ;
return 1 ;
}
static int F_103 ( struct V_3 * V_4 )
{
int V_37 , V_25 ;
switch ( V_4 -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
if ( V_4 -> V_133 == V_136 )
V_4 -> V_137 = V_138 ;
else
V_4 -> V_137 = V_139 ;
V_25 = F_104 ( V_4 ) ;
if ( V_25 )
return V_25 ;
break;
#ifdef F_105
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
if ( ( V_4 -> V_133 == V_140 ) || ( V_4 -> V_133 == V_141 ) )
V_4 -> V_137 = V_145 ;
else
V_4 -> V_137 = V_146 ;
V_25 = F_106 ( V_4 ) ;
if ( V_25 )
return V_25 ;
break;
#endif
default:
return - V_43 ;
}
V_4 -> V_147 = F_107 ( V_4 -> V_123 ,
sizeof( struct V_148 ) , V_79 ) ;
if ( V_4 -> V_147 == NULL )
return - V_44 ;
if ( V_4 -> V_124 == NULL ) {
F_13 ( L_30 ) ;
return V_25 ;
}
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( ( V_149 & ( 1 << V_37 ) ) == 0 ) {
F_13 ( L_31 , V_37 ) ;
V_4 -> V_147 [ V_37 ] . V_150 = false ;
} else {
if ( V_4 -> V_124 [ V_37 ] . V_125 -> V_151 ) {
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_151 ( ( void * ) V_4 ) ;
if ( V_25 == - V_152 )
V_4 -> V_147 [ V_37 ] . V_150 = false ;
else if ( V_25 )
return V_25 ;
else
V_4 -> V_147 [ V_37 ] . V_150 = true ;
} else {
V_4 -> V_147 [ V_37 ] . V_150 = true ;
}
}
}
return 0 ;
}
static int F_108 ( struct V_3 * V_4 )
{
int V_37 , V_25 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_150 )
continue;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_153 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_147 [ V_37 ] . V_154 = true ;
if ( V_4 -> V_124 [ V_37 ] . type == V_155 ) {
V_25 = F_20 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_156 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_47 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_147 [ V_37 ] . V_157 = true ;
}
}
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_154 )
continue;
if ( V_4 -> V_124 [ V_37 ] . type == V_155 )
continue;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_156 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 -> V_147 [ V_37 ] . V_157 = true ;
}
return 0 ;
}
static int F_109 ( struct V_3 * V_4 )
{
int V_37 = 0 , V_25 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_150 )
continue;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_126 ( ( void * ) V_4 ,
V_158 ) ;
if ( V_25 )
return V_25 ;
if ( V_4 -> V_124 [ V_37 ] . V_125 -> V_159 ) {
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_159 ( ( void * ) V_4 ) ;
if ( V_25 )
return V_25 ;
}
}
return 0 ;
}
static int F_110 ( struct V_3 * V_4 )
{
int V_37 , V_25 ;
for ( V_37 = V_4 -> V_123 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_157 )
continue;
if ( V_4 -> V_124 [ V_37 ] . type == V_155 ) {
F_46 ( V_4 ) ;
F_28 ( V_4 ) ;
}
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_126 ( ( void * ) V_4 ,
V_160 ) ;
if ( V_25 )
return V_25 ;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_161 ( ( void * ) V_4 ) ;
V_4 -> V_147 [ V_37 ] . V_157 = false ;
}
for ( V_37 = V_4 -> V_123 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_154 )
continue;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_162 ( ( void * ) V_4 ) ;
V_4 -> V_147 [ V_37 ] . V_154 = false ;
V_4 -> V_147 [ V_37 ] . V_150 = false ;
}
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
int V_37 , V_25 ;
for ( V_37 = V_4 -> V_123 - 1 ; V_37 >= 0 ; V_37 -- ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_150 )
continue;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_126 ( ( void * ) V_4 ,
V_160 ) ;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_163 ( V_4 ) ;
}
return 0 ;
}
static int F_112 ( struct V_3 * V_4 )
{
int V_37 , V_25 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_123 ; V_37 ++ ) {
if ( ! V_4 -> V_147 [ V_37 ] . V_150 )
continue;
V_25 = V_4 -> V_124 [ V_37 ] . V_125 -> V_164 ( V_4 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
int F_113 ( struct V_3 * V_4 ,
struct V_1 * V_88 ,
struct V_109 * V_38 ,
T_1 V_6 )
{
int V_25 , V_37 ;
bool V_165 = false ;
V_4 -> V_166 = false ;
V_4 -> V_2 = & V_38 -> V_2 ;
V_4 -> V_88 = V_88 ;
V_4 -> V_38 = V_38 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_133 = V_6 & V_167 ;
V_4 -> V_73 = false ;
V_4 -> V_168 = V_169 ;
V_4 -> V_56 . V_68 = 512 * 1024 * 1024 ;
V_4 -> V_170 = false ;
V_4 -> V_171 = 0 ;
V_4 -> V_172 . V_173 = NULL ;
V_4 -> V_172 . V_174 = NULL ;
V_4 -> V_175 . V_176 = NULL ;
V_4 -> V_175 . V_177 = NULL ;
V_4 -> V_178 . V_179 = NULL ;
V_4 -> V_180 = F_114 ( V_181 ) ;
V_4 -> V_182 = & F_15 ;
V_4 -> V_183 = & F_17 ;
V_4 -> V_184 = & F_15 ;
V_4 -> V_185 = & F_17 ;
V_4 -> V_186 = & F_15 ;
V_4 -> V_187 = & F_17 ;
V_4 -> V_188 = & F_15 ;
V_4 -> V_189 = & F_17 ;
V_4 -> V_190 = & F_18 ;
V_4 -> V_191 = & F_19 ;
F_42 ( L_32 ,
V_192 [ V_4 -> V_133 ] , V_38 -> V_193 , V_38 -> V_194 ,
V_38 -> V_195 , V_38 -> V_196 , V_38 -> V_197 ) ;
F_83 ( & V_4 -> V_198 ) ;
F_115 ( & V_4 -> V_199 . V_200 . V_201 , 0 ) ;
F_83 ( & V_4 -> V_202 . V_97 ) ;
F_83 ( & V_4 -> V_203 . V_97 ) ;
F_83 ( & V_4 -> V_204 . V_205 ) ;
F_83 ( & V_4 -> V_206 ) ;
F_83 ( & V_4 -> V_207 ) ;
F_116 ( & V_4 -> V_208 ) ;
F_83 ( & V_4 -> V_209 ) ;
F_117 ( V_4 -> V_210 ) ;
F_89 ( V_4 ) ;
F_118 ( & V_4 -> V_14 ) ;
F_118 ( & V_4 -> V_211 ) ;
F_118 ( & V_4 -> V_212 ) ;
F_118 ( & V_4 -> V_213 ) ;
F_118 ( & V_4 -> V_214 ) ;
F_118 ( & V_4 -> V_215 ) ;
V_4 -> V_216 = F_38 ( V_4 -> V_38 , 5 ) ;
V_4 -> V_10 = F_39 ( V_4 -> V_38 , 5 ) ;
V_4 -> V_12 = F_41 ( V_4 -> V_216 , V_4 -> V_10 ) ;
if ( V_4 -> V_12 == NULL ) {
return - V_44 ;
}
F_42 ( L_33 , ( T_1 ) V_4 -> V_216 ) ;
F_42 ( L_34 , ( unsigned ) V_4 -> V_10 ) ;
F_37 ( V_4 ) ;
for ( V_37 = 0 ; V_37 < V_217 ; V_37 ++ ) {
if ( F_119 ( V_4 -> V_38 , V_37 ) & V_218 ) {
V_4 -> V_18 = F_39 ( V_4 -> V_38 , V_37 ) ;
V_4 -> V_19 = F_120 ( V_4 -> V_38 , V_37 , V_4 -> V_18 ) ;
break;
}
}
if ( V_4 -> V_19 == NULL )
F_13 ( L_35 ) ;
V_25 = F_103 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_121 ( V_4 -> V_38 , V_4 , NULL , F_86 ) ;
if ( V_219 == 1 )
V_165 = true ;
if ( F_1 ( V_88 ) )
V_165 = true ;
F_122 ( V_4 -> V_38 , & V_220 , V_165 ) ;
if ( V_165 )
F_123 ( V_4 -> V_2 , & V_4 -> V_221 ) ;
if ( ! F_124 ( V_4 ) )
return - V_43 ;
if ( ! V_4 -> V_73 ) {
F_60 ( V_4 -> V_2 , L_36 ) ;
return - V_43 ;
}
V_25 = F_80 ( V_4 ) ;
if ( V_25 )
return V_25 ;
if ( ! F_57 ( V_4 ) ) {
if ( ! V_4 -> V_72 ) {
F_60 ( V_4 -> V_2 , L_17 ) ;
return - V_43 ;
}
F_42 ( L_16 ) ;
F_59 ( V_4 -> V_74 . V_75 ) ;
}
V_25 = F_125 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_126 ( V_4 ) ;
V_25 = F_127 ( V_4 ) ;
if ( V_25 )
return V_25 ;
F_128 ( V_4 -> V_88 ) ;
V_25 = F_108 ( V_4 ) ;
if ( V_25 ) {
F_110 ( V_4 ) ;
return V_25 ;
}
V_4 -> V_170 = true ;
F_129 ( V_4 ) ;
V_25 = F_130 ( V_4 ) ;
if ( V_25 ) {
F_60 ( V_4 -> V_2 , L_37 , V_25 ) ;
return V_25 ;
}
V_25 = F_131 ( V_4 ) ;
if ( V_25 )
F_13 ( L_38 , V_25 ) ;
V_25 = F_132 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_39 , V_25 ) ;
}
V_25 = F_133 ( V_4 ) ;
if ( V_25 ) {
F_13 ( L_40 , V_25 ) ;
}
if ( ( V_222 & 1 ) ) {
if ( V_4 -> V_170 )
F_134 ( V_4 ) ;
else
F_42 ( L_41 ) ;
}
if ( ( V_222 & 2 ) ) {
if ( V_4 -> V_170 )
F_135 ( V_4 ) ;
else
F_42 ( L_42 ) ;
}
if ( V_223 ) {
if ( V_4 -> V_170 )
F_136 ( V_4 , V_223 ) ;
else
F_42 ( L_43 ) ;
}
V_25 = F_109 ( V_4 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
void F_137 ( struct V_3 * V_4 )
{
int V_25 ;
F_42 ( L_44 ) ;
V_4 -> V_166 = true ;
F_138 ( V_4 ) ;
F_139 ( V_4 ) ;
F_140 ( V_4 ) ;
F_141 ( V_4 ) ;
V_25 = F_110 ( V_4 ) ;
F_79 ( V_4 -> V_147 ) ;
V_4 -> V_147 = NULL ;
V_4 -> V_170 = false ;
F_142 ( V_4 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
F_143 ( V_4 -> V_38 ) ;
F_121 ( V_4 -> V_38 , NULL , NULL , NULL ) ;
if ( V_4 -> V_19 )
F_144 ( V_4 -> V_38 , V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_44 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
F_43 ( V_4 ) ;
F_145 ( V_4 ) ;
F_146 ( V_4 ) ;
}
int F_97 ( struct V_1 * V_2 , bool V_163 , bool V_224 )
{
struct V_3 * V_4 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
int V_37 , V_25 ;
bool V_229 = false ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_230 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_115 == V_118 )
return 0 ;
F_96 ( V_2 ) ;
F_147 (connector, &dev->mode_config.connector_list, head) {
F_148 ( V_228 , V_231 ) ;
}
F_147 (crtc, &dev->mode_config.crtc_list, head) {
struct V_232 * V_233 = F_149 ( V_226 -> V_234 -> V_235 ) ;
struct V_236 * V_27 ;
if ( V_233 == NULL || V_233 -> V_237 == NULL ) {
continue;
}
V_27 = F_150 ( V_233 -> V_237 ) ;
if ( ! F_151 ( V_4 , V_27 ) ) {
V_25 = F_22 ( V_27 , false ) ;
if ( V_25 == 0 ) {
F_27 ( V_27 ) ;
F_25 ( V_27 ) ;
}
}
}
F_138 ( V_4 ) ;
for ( V_37 = 0 ; V_37 < V_181 ; V_37 ++ ) {
struct V_238 * V_239 = V_4 -> V_240 [ V_37 ] ;
if ( ! V_239 )
continue;
V_25 = F_152 ( V_239 ) ;
if ( V_25 ) {
V_229 = true ;
}
}
if ( V_229 ) {
F_153 ( V_4 ) ;
}
V_25 = F_111 ( V_4 ) ;
F_138 ( V_4 ) ;
F_154 ( V_2 -> V_38 ) ;
if ( V_163 ) {
F_155 ( V_2 -> V_38 ) ;
F_156 ( V_2 -> V_38 , V_241 ) ;
}
if ( V_224 ) {
F_157 () ;
F_158 ( V_4 , 1 ) ;
F_159 () ;
}
return 0 ;
}
int F_94 ( struct V_1 * V_2 , bool V_164 , bool V_224 )
{
struct V_227 * V_228 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_25 ;
if ( V_2 -> V_115 == V_118 )
return 0 ;
if ( V_224 ) {
F_157 () ;
}
if ( V_164 ) {
F_156 ( V_2 -> V_38 , V_242 ) ;
F_160 ( V_2 -> V_38 ) ;
if ( F_161 ( V_2 -> V_38 ) ) {
if ( V_224 )
F_159 () ;
return - 1 ;
}
}
F_59 ( V_4 -> V_74 . V_75 ) ;
V_25 = F_112 ( V_4 ) ;
V_25 = F_131 ( V_4 ) ;
if ( V_25 )
F_13 ( L_38 , V_25 ) ;
V_25 = F_109 ( V_4 ) ;
if ( V_25 )
return V_25 ;
if ( V_224 ) {
F_162 ( V_2 ) ;
F_147 (connector, &dev->mode_config.connector_list, head) {
F_148 ( V_228 , V_243 ) ;
}
}
F_95 ( V_2 ) ;
if ( V_224 ) {
F_158 ( V_4 , 0 ) ;
F_159 () ;
}
return 0 ;
}
int F_163 ( struct V_3 * V_4 )
{
unsigned V_244 [ V_181 ] ;
T_1 * V_245 [ V_181 ] ;
bool V_246 = false ;
int V_37 , V_25 ;
int V_247 ;
F_164 ( & V_4 -> V_208 ) ;
if ( ! V_4 -> V_248 ) {
F_165 ( & V_4 -> V_208 ) ;
return 0 ;
}
V_4 -> V_248 = false ;
F_166 ( & V_4 -> V_249 ) ;
V_247 = F_167 ( & V_4 -> V_172 . V_250 ) ;
V_25 = F_111 ( V_4 ) ;
for ( V_37 = 0 ; V_37 < V_181 ; ++ V_37 ) {
struct V_238 * V_239 = V_4 -> V_240 [ V_37 ] ;
if ( ! V_239 )
continue;
V_244 [ V_37 ] = F_168 ( V_239 , & V_245 [ V_37 ] ) ;
if ( V_244 [ V_37 ] ) {
V_246 = true ;
F_55 ( V_4 -> V_2 , L_45
L_46 , V_244 [ V_37 ] , V_37 ) ;
}
}
V_251:
V_25 = F_169 ( V_4 ) ;
if ( ! V_25 ) {
F_55 ( V_4 -> V_2 , L_47 ) ;
V_25 = F_112 ( V_4 ) ;
}
if ( ! V_25 ) {
for ( V_37 = 0 ; V_37 < V_181 ; ++ V_37 ) {
struct V_238 * V_239 = V_4 -> V_240 [ V_37 ] ;
if ( ! V_239 )
continue;
F_170 ( V_239 , V_244 [ V_37 ] , V_245 [ V_37 ] ) ;
V_244 [ V_37 ] = 0 ;
V_245 [ V_37 ] = NULL ;
}
V_25 = F_131 ( V_4 ) ;
if ( V_25 ) {
F_60 ( V_4 -> V_2 , L_38 , V_25 ) ;
if ( V_246 ) {
V_246 = false ;
V_25 = F_111 ( V_4 ) ;
goto V_251;
}
}
} else {
F_153 ( V_4 ) ;
for ( V_37 = 0 ; V_37 < V_181 ; ++ V_37 ) {
if ( V_4 -> V_240 [ V_37 ] )
F_79 ( V_245 [ V_37 ] ) ;
}
}
F_162 ( V_4 -> V_88 ) ;
F_171 ( & V_4 -> V_172 . V_250 , V_247 ) ;
if ( V_25 ) {
F_55 ( V_4 -> V_2 , L_48 ) ;
}
F_165 ( & V_4 -> V_208 ) ;
return V_25 ;
}
int F_172 ( struct V_3 * V_4 ,
struct V_252 * V_253 ,
unsigned V_254 )
{
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_255 ; V_37 ++ ) {
if ( V_4 -> V_256 [ V_37 ] . V_253 == V_253 ) {
return 0 ;
}
}
V_37 = V_4 -> V_255 + 1 ;
if ( V_37 > V_257 ) {
F_13 ( L_49 ) ;
F_13 ( L_50
L_51 ) ;
return - V_43 ;
}
V_4 -> V_256 [ V_4 -> V_255 ] . V_253 = V_253 ;
V_4 -> V_256 [ V_4 -> V_255 ] . V_258 = V_254 ;
V_4 -> V_255 = V_37 ;
#if F_173 ( V_259 )
F_174 ( V_253 , V_254 ,
V_4 -> V_88 -> V_260 -> V_261 ,
V_4 -> V_88 -> V_260 ) ;
F_174 ( V_253 , V_254 ,
V_4 -> V_88 -> V_234 -> V_261 ,
V_4 -> V_88 -> V_234 ) ;
#endif
return 0 ;
}
static void F_146 ( struct V_3 * V_4 )
{
#if F_173 ( V_259 )
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < V_4 -> V_255 ; V_37 ++ ) {
F_175 ( V_4 -> V_256 [ V_37 ] . V_253 ,
V_4 -> V_256 [ V_37 ] . V_258 ,
V_4 -> V_88 -> V_260 ) ;
F_175 ( V_4 -> V_256 [ V_37 ] . V_253 ,
V_4 -> V_256 [ V_37 ] . V_258 ,
V_4 -> V_88 -> V_234 ) ;
}
#endif
}
static T_7 F_176 ( struct V_262 * V_263 , char T_8 * V_264 ,
T_4 V_41 , T_9 * V_265 )
{
struct V_3 * V_4 = V_263 -> V_266 -> V_267 ;
T_7 V_268 = 0 ;
int V_25 ;
if ( V_41 & 0x3 || * V_265 & 0x3 )
return - V_43 ;
while ( V_41 ) {
T_1 V_269 ;
if ( * V_265 > V_4 -> V_10 )
return V_268 ;
V_269 = F_33 ( * V_265 >> 2 ) ;
V_25 = F_177 ( V_269 , ( T_1 * ) V_264 ) ;
if ( V_25 )
return V_25 ;
V_268 += 4 ;
V_264 += 4 ;
* V_265 += 4 ;
V_41 -= 4 ;
}
return V_268 ;
}
static T_7 F_178 ( struct V_262 * V_263 , const char T_8 * V_264 ,
T_4 V_41 , T_9 * V_265 )
{
struct V_3 * V_4 = V_263 -> V_266 -> V_267 ;
T_7 V_268 = 0 ;
int V_25 ;
if ( V_41 & 0x3 || * V_265 & 0x3 )
return - V_43 ;
while ( V_41 ) {
T_1 V_269 ;
if ( * V_265 > V_4 -> V_10 )
return V_268 ;
V_25 = F_179 ( V_269 , ( T_1 * ) V_264 ) ;
if ( V_25 )
return V_25 ;
F_34 ( * V_265 >> 2 , V_269 ) ;
V_268 += 4 ;
V_264 += 4 ;
* V_265 += 4 ;
V_41 -= 4 ;
}
return V_268 ;
}
static int F_133 ( struct V_3 * V_4 )
{
struct V_270 * V_131 = V_4 -> V_88 -> V_234 ;
struct V_271 * V_272 , * V_273 = V_131 -> V_261 ;
V_272 = F_180 ( L_52 , V_274 | V_275 , V_273 ,
V_4 , & V_276 ) ;
if ( F_181 ( V_272 ) )
return F_182 ( V_272 ) ;
F_183 ( V_272 -> V_277 , V_4 -> V_10 ) ;
V_4 -> V_278 = V_272 ;
return 0 ;
}
static void F_145 ( struct V_3 * V_4 )
{
F_184 ( V_4 -> V_278 ) ;
V_4 -> V_278 = NULL ;
}
int F_185 ( struct V_270 * V_131 )
{
return 0 ;
}
void F_186 ( struct V_270 * V_131 )
{
}
static int F_133 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_145 ( struct V_3 * V_4 ) { }
