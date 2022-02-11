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
int F_60 ( struct V_3 * V_4 )
{
if ( V_4 -> V_74 . V_75 )
return 0 ;
V_4 -> V_74 . V_75 = F_61 ( V_76 | V_77 | V_78 ) ;
if ( V_4 -> V_74 . V_75 == NULL )
return - V_46 ;
V_4 -> V_74 . V_79 = F_62 ( V_4 -> V_17 , V_4 -> V_74 . V_75 ,
0 , V_31 , V_80 ) ;
if ( F_63 ( V_4 -> V_17 , V_4 -> V_74 . V_79 ) ) {
F_64 ( & V_4 -> V_17 -> V_2 , L_16 ) ;
F_65 ( V_4 -> V_74 . V_75 ) ;
V_4 -> V_74 . V_75 = NULL ;
return - V_46 ;
}
return 0 ;
}
void F_66 ( struct V_3 * V_4 )
{
if ( V_4 -> V_74 . V_75 == NULL )
return;
F_67 ( V_4 -> V_17 , V_4 -> V_74 . V_79 ,
V_31 , V_80 ) ;
F_65 ( V_4 -> V_74 . V_75 ) ;
V_4 -> V_74 . V_75 = NULL ;
}
static T_1 F_68 ( struct V_81 * V_82 , T_1 V_8 )
{
return 0 ;
}
static void F_69 ( struct V_81 * V_82 , T_1 V_8 , T_1 V_83 )
{
}
static T_1 F_70 ( struct V_81 * V_82 , T_1 V_8 )
{
return 0 ;
}
static void F_71 ( struct V_81 * V_82 , T_1 V_8 , T_1 V_83 )
{
}
static void F_72 ( struct V_81 * V_82 , T_1 V_8 , T_1 V_83 )
{
struct V_3 * V_4 = V_82 -> V_2 -> V_5 ;
F_36 ( V_8 , V_83 ) ;
}
static T_1 F_73 ( struct V_81 * V_82 , T_1 V_8 )
{
struct V_3 * V_4 = V_82 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_35 ( V_8 ) ;
return V_27 ;
}
static void F_74 ( struct V_81 * V_82 , T_1 V_8 , T_1 V_83 )
{
struct V_3 * V_4 = V_82 -> V_2 -> V_5 ;
F_75 ( V_8 , V_83 ) ;
}
static T_1 F_76 ( struct V_81 * V_82 , T_1 V_8 )
{
struct V_3 * V_4 = V_82 -> V_2 -> V_5 ;
T_1 V_27 ;
V_27 = F_77 ( V_8 ) ;
return V_27 ;
}
static void F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_84 . V_85 ) {
F_79 ( V_4 -> V_84 . V_85 -> V_86 ) ;
F_79 ( V_4 -> V_84 . V_85 -> V_87 ) ;
}
F_79 ( V_4 -> V_84 . V_85 ) ;
V_4 -> V_84 . V_85 = NULL ;
F_79 ( V_4 -> V_84 . V_88 ) ;
V_4 -> V_84 . V_88 = NULL ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_81 * V_88 =
F_81 ( sizeof( struct V_81 ) , V_77 ) ;
if ( ! V_88 )
return - V_46 ;
V_4 -> V_84 . V_88 = V_88 ;
V_88 -> V_2 = V_4 -> V_89 ;
V_88 -> V_90 = F_73 ;
V_88 -> V_91 = F_72 ;
if ( V_4 -> V_21 ) {
V_88 -> V_92 = F_76 ;
V_88 -> V_93 = F_74 ;
} else {
F_15 ( L_17 ) ;
V_88 -> V_92 = F_73 ;
V_88 -> V_93 = F_72 ;
}
V_88 -> V_94 = F_70 ;
V_88 -> V_95 = F_71 ;
V_88 -> V_96 = F_68 ;
V_88 -> V_97 = F_69 ;
V_4 -> V_84 . V_85 = F_82 ( V_88 , V_4 -> V_98 ) ;
if ( ! V_4 -> V_84 . V_85 ) {
F_78 ( V_4 ) ;
return - V_46 ;
}
F_83 ( & V_4 -> V_84 . V_85 -> V_99 ) ;
F_84 ( V_4 ) ;
F_85 ( V_4 -> V_84 . V_85 ) ;
return 0 ;
}
static unsigned int F_86 ( void * V_100 , bool V_101 )
{
struct V_3 * V_4 = V_100 ;
F_87 ( V_4 , V_101 ) ;
if ( V_101 )
return V_102 | V_103 |
V_104 | V_105 ;
else
return V_104 | V_105 ;
}
static bool F_88 ( int V_106 )
{
return ( V_106 & ( V_106 - 1 ) ) == 0 ;
}
static void F_89 ( struct V_3 * V_4 )
{
if ( V_107 < 4 ) {
F_50 ( V_4 -> V_2 , L_18 ,
V_107 ) ;
V_107 = 4 ;
} else if ( ! F_88 ( V_107 ) ) {
F_50 ( V_4 -> V_2 , L_19 ,
V_107 ) ;
V_107 = F_90 ( V_107 ) ;
}
if ( V_108 != - 1 ) {
if ( V_108 < 32 ) {
F_50 ( V_4 -> V_2 , L_20 ,
V_108 ) ;
V_108 = - 1 ;
}
}
if ( ! F_88 ( V_109 ) ) {
F_50 ( V_4 -> V_2 , L_21 ,
V_109 ) ;
V_109 = 8 ;
}
if ( V_109 < 1 ) {
F_50 ( V_4 -> V_2 , L_22 ,
V_109 ) ;
V_109 = 8 ;
}
if ( V_109 > 1024 ) {
F_50 ( V_4 -> V_2 , L_23 ,
V_109 ) ;
V_109 = 8 ;
}
if ( V_110 == - 1 ) {
unsigned V_111 = F_91 ( V_109 ) + 18 ;
if ( V_109 <= 8 )
V_110 = V_111 - 9 ;
else
V_110 = ( V_111 + 3 ) / 2 ;
} else if ( V_110 < 9 ) {
F_50 ( V_4 -> V_2 , L_24 ,
V_110 ) ;
V_110 = 9 ;
}
if ( V_110 > 24 ||
( V_109 * 1024 ) < ( 1ull << V_110 ) ) {
F_50 ( V_4 -> V_2 , L_25 ,
V_110 ) ;
V_110 = 9 ;
}
}
static void F_92 ( struct V_112 * V_17 , enum V_113 V_101 )
{
struct V_1 * V_2 = F_93 ( V_17 ) ;
if ( F_1 ( V_2 ) && V_101 == V_114 )
return;
if ( V_101 == V_115 ) {
unsigned V_116 = V_2 -> V_17 -> V_116 ;
F_94 ( V_117 L_26 ) ;
V_2 -> V_118 = V_119 ;
F_95 ( V_2 , true , true ) ;
V_2 -> V_17 -> V_116 = V_116 ;
V_2 -> V_118 = V_120 ;
F_96 ( V_2 ) ;
} else {
F_94 ( V_117 L_27 ) ;
F_97 ( V_2 ) ;
V_2 -> V_118 = V_119 ;
F_98 ( V_2 , true , true ) ;
V_2 -> V_118 = V_121 ;
}
}
static bool F_99 ( struct V_112 * V_17 )
{
struct V_1 * V_2 = F_93 ( V_17 ) ;
return V_2 -> V_122 == 0 ;
}
int F_100 ( struct V_3 * V_4 ,
enum V_123 V_124 ,
enum V_125 V_101 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
if ( V_4 -> V_129 [ V_40 ] . type == V_124 ) {
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_131 ( ( void * ) V_4 ,
V_101 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_101 ( struct V_3 * V_4 ,
enum V_123 V_124 ,
enum V_132 V_101 )
{
int V_40 , V_27 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
if ( V_4 -> V_129 [ V_40 ] . type == V_124 ) {
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_133 ( ( void * ) V_4 ,
V_101 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return V_27 ;
}
int F_102 ( struct V_3 * V_4 ,
enum V_123 V_124 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
if ( V_4 -> V_129 [ V_40 ] . type == V_124 ) {
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_134 ( ( void * ) V_4 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
return 0 ;
}
bool F_103 ( struct V_3 * V_4 ,
enum V_123 V_124 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
if ( V_4 -> V_129 [ V_40 ] . type == V_124 )
return V_4 -> V_129 [ V_40 ] . V_130 -> V_135 ( ( void * ) V_4 ) ;
}
return true ;
}
const struct V_136 * F_104 (
struct V_3 * V_4 ,
enum V_123 type )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ )
if ( V_4 -> V_129 [ V_40 ] . type == type )
return & V_4 -> V_129 [ V_40 ] ;
return NULL ;
}
int F_105 ( struct V_3 * V_4 ,
enum V_123 type ,
T_2 V_137 , T_2 V_138 )
{
const struct V_136 * V_139 ;
V_139 = F_104 ( V_4 , type ) ;
if ( V_139 && ( ( V_139 -> V_137 > V_137 ) ||
( ( V_139 -> V_137 == V_137 ) &&
( V_139 -> V_138 >= V_138 ) ) ) )
return 0 ;
return 1 ;
}
static int F_106 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
switch ( V_4 -> V_140 ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
if ( V_4 -> V_140 == V_146 || V_4 -> V_140 == V_147 )
V_4 -> V_148 = V_149 ;
else
V_4 -> V_148 = V_150 ;
V_27 = F_107 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#ifdef F_108
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
if ( ( V_4 -> V_140 == V_151 ) || ( V_4 -> V_140 == V_152 ) )
V_4 -> V_148 = V_156 ;
else
V_4 -> V_148 = V_157 ;
V_27 = F_109 ( V_4 ) ;
if ( V_27 )
return V_27 ;
break;
#endif
default:
return - V_45 ;
}
V_4 -> V_127 = F_110 ( V_4 -> V_126 ,
sizeof( struct V_158 ) , V_77 ) ;
if ( V_4 -> V_127 == NULL )
return - V_46 ;
if ( V_4 -> V_129 == NULL ) {
F_15 ( L_28 ) ;
return V_27 ;
}
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ( V_159 & ( 1 << V_40 ) ) == 0 ) {
F_15 ( L_29 , V_40 ) ;
V_4 -> V_127 [ V_40 ] . V_128 = false ;
} else {
if ( V_4 -> V_129 [ V_40 ] . V_130 -> V_160 ) {
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_160 ( ( void * ) V_4 ) ;
if ( V_27 == - V_161 ) {
V_4 -> V_127 [ V_40 ] . V_128 = false ;
} else if ( V_27 ) {
F_15 ( L_30 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
} else {
V_4 -> V_127 [ V_40 ] . V_128 = true ;
}
} else {
V_4 -> V_127 [ V_40 ] . V_128 = true ;
}
}
}
V_4 -> V_163 &= V_164 ;
V_4 -> V_165 &= V_166 ;
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_167 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_31 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
}
V_4 -> V_127 [ V_40 ] . V_168 = true ;
if ( V_4 -> V_129 [ V_40 ] . type == V_169 ) {
V_27 = F_22 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_32 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_170 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_33 , V_40 , V_27 ) ;
return V_27 ;
}
V_27 = F_49 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_34 , V_27 ) ;
return V_27 ;
}
V_4 -> V_127 [ V_40 ] . V_171 = true ;
}
}
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_168 )
continue;
if ( V_4 -> V_129 [ V_40 ] . type == V_169 )
continue;
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_170 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_35 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
}
V_4 -> V_127 [ V_40 ] . V_171 = true ;
}
return 0 ;
}
static int F_112 ( struct V_3 * V_4 )
{
int V_40 = 0 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_131 ( ( void * ) V_4 ,
V_172 ) ;
if ( V_27 ) {
F_15 ( L_36 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
}
if ( V_4 -> V_129 [ V_40 ] . V_130 -> V_173 ) {
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_173 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_15 ( L_37 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
}
}
}
return 0 ;
}
static int F_113 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
for ( V_40 = V_4 -> V_126 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_171 )
continue;
if ( V_4 -> V_129 [ V_40 ] . type == V_169 ) {
F_48 ( V_4 ) ;
F_30 ( V_4 ) ;
}
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_131 ( ( void * ) V_4 ,
V_174 ) ;
if ( V_27 ) {
F_15 ( L_38 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
}
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_175 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_114 ( L_39 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
}
V_4 -> V_127 [ V_40 ] . V_171 = false ;
}
for ( V_40 = V_4 -> V_126 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_168 )
continue;
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_176 ( ( void * ) V_4 ) ;
if ( V_27 ) {
F_114 ( L_40 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
}
V_4 -> V_127 [ V_40 ] . V_168 = false ;
V_4 -> V_127 [ V_40 ] . V_128 = false ;
}
for ( V_40 = V_4 -> V_126 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( V_4 -> V_129 [ V_40 ] . V_130 -> V_177 )
V_4 -> V_129 [ V_40 ] . V_130 -> V_177 ( ( void * ) V_4 ) ;
}
return 0 ;
}
static int F_115 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
V_27 = F_100 ( V_4 , V_178 ,
V_174 ) ;
if ( V_27 ) {
F_15 ( L_41 , V_27 ) ;
}
for ( V_40 = V_4 -> V_126 - 1 ; V_40 >= 0 ; V_40 -- ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
if ( V_40 != V_178 ) {
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_131 ( ( void * ) V_4 ,
V_174 ) ;
if ( V_27 ) {
F_15 ( L_38 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
}
}
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_179 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_42 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
}
}
return 0 ;
}
static int F_116 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_126 ; V_40 ++ ) {
if ( ! V_4 -> V_127 [ V_40 ] . V_128 )
continue;
V_27 = V_4 -> V_129 [ V_40 ] . V_130 -> V_180 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_43 , V_4 -> V_129 [ V_40 ] . V_130 -> V_162 , V_27 ) ;
return V_27 ;
}
}
return 0 ;
}
static bool F_117 ( void )
{
#ifdef F_118
return F_119 ( V_181 ) ;
#else
return false ;
#endif
}
int F_120 ( struct V_3 * V_4 ,
struct V_1 * V_89 ,
struct V_112 * V_17 ,
T_1 V_6 )
{
int V_27 , V_40 ;
bool V_182 = false ;
V_4 -> V_183 = false ;
V_4 -> V_2 = & V_17 -> V_2 ;
V_4 -> V_89 = V_89 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_140 = V_6 & V_184 ;
V_4 -> V_185 = false ;
V_4 -> V_186 = V_187 ;
V_4 -> V_58 . V_70 = 512 * 1024 * 1024 ;
V_4 -> V_188 = false ;
V_4 -> V_189 = 0 ;
V_4 -> V_190 . V_191 = NULL ;
V_4 -> V_190 . V_192 = NULL ;
V_4 -> V_193 . V_194 = NULL ;
V_4 -> V_193 . V_195 = 0 ;
V_4 -> V_196 . V_197 = NULL ;
V_4 -> V_198 = F_121 ( V_199 ) ;
V_4 -> V_200 = & F_17 ;
V_4 -> V_201 = & F_19 ;
V_4 -> V_202 = & F_17 ;
V_4 -> V_203 = & F_19 ;
V_4 -> V_204 = & F_17 ;
V_4 -> V_205 = & F_19 ;
V_4 -> V_206 = & F_17 ;
V_4 -> V_207 = & F_19 ;
V_4 -> V_208 = & F_17 ;
V_4 -> V_209 = & F_19 ;
V_4 -> V_210 = & F_20 ;
V_4 -> V_211 = & F_21 ;
F_44 ( L_44 ,
V_212 [ V_4 -> V_140 ] , V_17 -> V_213 , V_17 -> V_18 ,
V_17 -> V_214 , V_17 -> V_215 , V_17 -> V_216 ) ;
F_83 ( & V_4 -> V_193 . V_217 ) ;
F_122 ( & V_4 -> V_218 . V_219 . V_217 , 0 ) ;
F_83 ( & V_4 -> V_220 . V_99 ) ;
F_83 ( & V_4 -> V_221 . V_222 ) ;
F_83 ( & V_4 -> V_223 ) ;
F_83 ( & V_4 -> V_224 ) ;
F_83 ( & V_4 -> V_225 ) ;
F_123 ( V_4 -> V_226 ) ;
F_89 ( V_4 ) ;
F_124 ( & V_4 -> V_14 ) ;
F_124 ( & V_4 -> V_227 ) ;
F_124 ( & V_4 -> V_228 ) ;
F_124 ( & V_4 -> V_229 ) ;
F_124 ( & V_4 -> V_230 ) ;
F_124 ( & V_4 -> V_231 ) ;
F_124 ( & V_4 -> V_232 ) ;
V_4 -> V_233 = F_40 ( V_4 -> V_17 , 5 ) ;
V_4 -> V_11 = F_41 ( V_4 -> V_17 , 5 ) ;
V_4 -> V_13 = F_43 ( V_4 -> V_233 , V_4 -> V_11 ) ;
if ( V_4 -> V_13 == NULL ) {
return - V_46 ;
}
F_44 ( L_45 , ( T_1 ) V_4 -> V_233 ) ;
F_44 ( L_46 , ( unsigned ) V_4 -> V_11 ) ;
F_39 ( V_4 ) ;
for ( V_40 = 0 ; V_40 < V_234 ; V_40 ++ ) {
if ( F_125 ( V_4 -> V_17 , V_40 ) & V_235 ) {
V_4 -> V_20 = F_41 ( V_4 -> V_17 , V_40 ) ;
V_4 -> V_21 = F_126 ( V_4 -> V_17 , V_40 , V_4 -> V_20 ) ;
break;
}
}
if ( V_4 -> V_21 == NULL )
F_15 ( L_47 ) ;
V_27 = F_106 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_127 ( V_4 -> V_17 , V_4 , NULL , F_86 ) ;
if ( V_236 == 1 )
V_182 = true ;
if ( F_1 ( V_89 ) )
V_182 = true ;
F_128 ( V_4 -> V_17 , & V_237 , V_182 ) ;
if ( V_182 )
F_129 ( V_4 -> V_2 , & V_4 -> V_238 ) ;
if ( ! F_130 ( V_4 ) ) {
V_27 = - V_45 ;
goto V_239;
}
if ( ! V_4 -> V_185 ) {
F_64 ( V_4 -> V_2 , L_48 ) ;
V_27 = - V_45 ;
goto V_239;
}
V_27 = F_80 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_49 ) ;
goto V_239;
}
V_4 -> V_240 . V_241 =
F_131 ( V_4 ) ;
V_4 -> V_240 . V_242 = F_117 () ;
V_4 -> V_240 . V_243 = F_132 ( V_4 ) ;
if ( ! F_59 ( V_4 ) ||
( V_4 -> V_240 . V_242 &&
! ( V_4 -> V_240 . V_243 & V_244 ) ) ) {
if ( ! V_4 -> V_98 ) {
F_64 ( V_4 -> V_2 , L_50 ) ;
V_27 = - V_45 ;
goto V_239;
}
F_44 ( L_51 ) ;
F_133 ( V_4 -> V_84 . V_85 ) ;
}
V_27 = F_134 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_52 ) ;
goto V_239;
}
F_135 ( V_4 ) ;
V_27 = F_136 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_53 ) ;
goto V_239;
}
F_137 ( V_4 -> V_89 ) ;
V_27 = F_111 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_54 ) ;
F_113 ( V_4 ) ;
goto V_239;
}
V_4 -> V_188 = true ;
F_138 ( V_4 ) ;
V_27 = F_139 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_55 , V_27 ) ;
goto V_239;
}
V_27 = F_140 ( V_4 ) ;
if ( V_27 )
F_15 ( L_56 , V_27 ) ;
V_27 = F_141 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_57 , V_27 ) ;
}
V_27 = F_142 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_58 , V_27 ) ;
}
V_27 = F_143 ( V_4 ) ;
if ( V_27 ) {
F_15 ( L_59 , V_27 ) ;
return V_27 ;
}
if ( ( V_245 & 1 ) ) {
if ( V_4 -> V_188 )
F_144 ( V_4 ) ;
else
F_44 ( L_60 ) ;
}
if ( ( V_245 & 2 ) ) {
if ( V_4 -> V_188 )
F_145 ( V_4 ) ;
else
F_44 ( L_61 ) ;
}
if ( V_246 ) {
if ( V_4 -> V_188 )
F_146 ( V_4 , V_246 ) ;
else
F_44 ( L_62 ) ;
}
V_27 = F_112 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_63 ) ;
goto V_239;
}
return 0 ;
V_239:
if ( V_182 )
F_147 ( V_4 -> V_2 ) ;
return V_27 ;
}
void F_148 ( struct V_3 * V_4 )
{
int V_27 ;
F_44 ( L_64 ) ;
V_4 -> V_183 = true ;
F_149 ( V_4 -> V_89 ) ;
F_150 ( V_4 ) ;
F_151 ( V_4 ) ;
F_152 ( V_4 ) ;
F_153 ( V_4 ) ;
V_27 = F_113 ( V_4 ) ;
F_79 ( V_4 -> V_127 ) ;
V_4 -> V_127 = NULL ;
V_4 -> V_188 = false ;
F_154 ( V_4 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 -> V_98 ) ;
V_4 -> V_98 = NULL ;
F_155 ( V_4 -> V_17 ) ;
if ( V_4 -> V_6 & V_7 )
F_147 ( V_4 -> V_2 ) ;
F_127 ( V_4 -> V_17 , NULL , NULL , NULL ) ;
if ( V_4 -> V_21 )
F_156 ( V_4 -> V_17 , V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
F_46 ( V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
F_45 ( V_4 ) ;
F_157 ( V_4 ) ;
F_158 ( V_4 ) ;
}
int F_98 ( struct V_1 * V_2 , bool V_179 , bool V_247 )
{
struct V_3 * V_4 ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
int V_27 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_252 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_118 == V_121 )
return 0 ;
F_97 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 (connector, &dev->mode_config.connector_list, head) {
F_161 ( V_251 , V_253 ) ;
}
F_162 ( V_2 ) ;
F_160 (crtc, &dev->mode_config.crtc_list, head) {
struct V_254 * V_254 = F_163 ( V_249 ) ;
struct V_255 * V_256 = F_164 ( V_249 -> V_257 -> V_258 ) ;
struct V_259 * V_29 ;
if ( V_254 -> V_260 ) {
struct V_259 * V_261 = F_165 ( V_254 -> V_260 ) ;
V_27 = F_24 ( V_261 , false ) ;
if ( V_27 == 0 ) {
F_29 ( V_261 ) ;
F_27 ( V_261 ) ;
}
}
if ( V_256 == NULL || V_256 -> V_262 == NULL ) {
continue;
}
V_29 = F_165 ( V_256 -> V_262 ) ;
if ( ! F_166 ( V_4 , V_29 ) ) {
V_27 = F_24 ( V_29 , false ) ;
if ( V_27 == 0 ) {
F_29 ( V_29 ) ;
F_27 ( V_29 ) ;
}
}
}
F_150 ( V_4 ) ;
F_167 ( V_4 ) ;
V_27 = F_115 ( V_4 ) ;
F_150 ( V_4 ) ;
F_168 ( V_2 -> V_17 ) ;
if ( V_179 ) {
F_169 ( V_2 -> V_17 ) ;
F_170 ( V_2 -> V_17 , V_263 ) ;
}
if ( V_247 ) {
F_171 () ;
F_172 ( V_4 , 1 ) ;
F_173 () ;
}
return 0 ;
}
int F_95 ( struct V_1 * V_2 , bool V_180 , bool V_247 )
{
struct V_250 * V_251 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_248 * V_249 ;
int V_27 ;
if ( V_2 -> V_118 == V_121 )
return 0 ;
if ( V_247 ) {
F_171 () ;
}
if ( V_180 ) {
F_170 ( V_2 -> V_17 , V_264 ) ;
F_174 ( V_2 -> V_17 ) ;
if ( F_175 ( V_2 -> V_17 ) ) {
if ( V_247 )
F_173 () ;
return - 1 ;
}
}
if ( ! F_59 ( V_4 ) )
F_133 ( V_4 -> V_84 . V_85 ) ;
V_27 = F_116 ( V_4 ) ;
if ( V_27 )
F_15 ( L_65 , V_27 ) ;
F_176 ( V_4 ) ;
if ( V_180 ) {
V_27 = F_140 ( V_4 ) ;
if ( V_27 )
F_15 ( L_56 , V_27 ) ;
}
V_27 = F_112 ( V_4 ) ;
if ( V_27 )
return V_27 ;
F_160 (crtc, &dev->mode_config.crtc_list, head) {
struct V_254 * V_254 = F_163 ( V_249 ) ;
if ( V_254 -> V_260 ) {
struct V_259 * V_261 = F_165 ( V_254 -> V_260 ) ;
V_27 = F_24 ( V_261 , false ) ;
if ( V_27 == 0 ) {
V_27 = F_26 ( V_261 ,
V_32 ,
& V_254 -> V_265 ) ;
if ( V_27 != 0 )
F_15 ( L_66 , V_27 ) ;
F_27 ( V_261 ) ;
}
}
}
if ( V_247 ) {
F_177 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 (connector, &dev->mode_config.connector_list, head) {
F_161 ( V_251 , V_266 ) ;
}
F_162 ( V_2 ) ;
}
F_96 ( V_2 ) ;
#ifdef F_178
V_2 -> V_2 -> V_267 . V_268 ++ ;
#endif
F_179 ( V_2 ) ;
#ifdef F_178
V_2 -> V_2 -> V_267 . V_268 -- ;
#endif
if ( V_247 ) {
F_172 ( V_4 , 0 ) ;
F_173 () ;
}
return 0 ;
}
int F_180 ( struct V_3 * V_4 )
{
int V_40 , V_27 ;
int V_269 ;
F_181 ( & V_4 -> V_270 ) ;
V_269 = F_182 ( & V_4 -> V_190 . V_271 ) ;
for ( V_40 = 0 ; V_40 < V_199 ; ++ V_40 ) {
struct V_272 * V_273 = V_4 -> V_274 [ V_40 ] ;
if ( ! V_273 )
continue;
F_183 ( V_273 -> V_275 . V_276 ) ;
F_184 ( & V_273 -> V_275 ) ;
}
F_185 ( V_4 ) ;
F_186 ( V_4 ) ;
V_27 = F_115 ( V_4 ) ;
V_277:
if ( V_4 -> V_84 . V_278 ) {
struct V_279 V_280 ;
F_187 ( V_4 , & V_280 ) ;
F_102 ( V_4 , V_169 ) ;
}
V_27 = F_188 ( V_4 ) ;
F_133 ( V_4 -> V_84 . V_85 ) ;
if ( ! V_27 ) {
F_57 ( V_4 -> V_2 , L_67 ) ;
V_27 = F_116 ( V_4 ) ;
}
F_189 ( V_4 ) ;
if ( ! V_27 ) {
V_27 = F_140 ( V_4 ) ;
if ( V_27 ) {
F_64 ( V_4 -> V_2 , L_56 , V_27 ) ;
V_27 = F_115 ( V_4 ) ;
goto V_277;
}
for ( V_40 = 0 ; V_40 < V_199 ; ++ V_40 ) {
struct V_272 * V_273 = V_4 -> V_274 [ V_40 ] ;
if ( ! V_273 )
continue;
F_190 ( & V_273 -> V_275 ) ;
F_191 ( V_273 -> V_275 . V_276 ) ;
}
} else {
F_64 ( V_4 -> V_2 , L_68 , V_27 ) ;
for ( V_40 = 0 ; V_40 < V_199 ; ++ V_40 ) {
if ( V_4 -> V_274 [ V_40 ] ) {
F_191 ( V_4 -> V_274 [ V_40 ] -> V_275 . V_276 ) ;
}
}
}
F_177 ( V_4 -> V_89 ) ;
F_192 ( & V_4 -> V_190 . V_271 , V_269 ) ;
if ( V_27 ) {
F_57 ( V_4 -> V_2 , L_69 ) ;
}
F_193 ( V_4 ) ;
return V_27 ;
}
void F_194 ( struct V_3 * V_4 )
{
T_2 V_281 ;
int V_10 ;
if ( V_282 )
V_4 -> V_220 . V_283 = V_282 ;
if ( V_284 )
V_4 -> V_220 . V_285 = V_284 ;
if ( F_195 ( V_4 -> V_17 -> V_286 ) ) {
if ( V_4 -> V_220 . V_283 == 0 )
V_4 -> V_220 . V_283 = V_287 ;
if ( V_4 -> V_220 . V_285 == 0 )
V_4 -> V_220 . V_285 = V_288 ;
return;
}
if ( V_4 -> V_220 . V_283 == 0 ) {
V_10 = F_196 ( V_4 -> V_89 , & V_281 ) ;
if ( ! V_10 ) {
V_4 -> V_220 . V_283 = ( V_289 |
V_290 |
V_291 ) ;
if ( V_281 & V_292 )
V_4 -> V_220 . V_283 |= V_293 ;
if ( V_281 & V_294 )
V_4 -> V_220 . V_283 |= V_295 ;
if ( V_281 & V_296 )
V_4 -> V_220 . V_283 |= V_297 ;
} else {
V_4 -> V_220 . V_283 = V_287 ;
}
}
if ( V_4 -> V_220 . V_285 == 0 ) {
V_10 = F_197 ( V_4 -> V_89 , & V_281 ) ;
if ( ! V_10 ) {
switch ( V_281 ) {
case 32 :
V_4 -> V_220 . V_285 = ( V_298 |
V_299 |
V_300 |
V_301 |
V_302 |
V_303 |
V_304 ) ;
break;
case 16 :
V_4 -> V_220 . V_285 = ( V_299 |
V_300 |
V_301 |
V_302 |
V_303 |
V_304 ) ;
break;
case 12 :
V_4 -> V_220 . V_285 = ( V_300 |
V_301 |
V_302 |
V_303 |
V_304 ) ;
break;
case 8 :
V_4 -> V_220 . V_285 = ( V_301 |
V_302 |
V_303 |
V_304 ) ;
break;
case 4 :
V_4 -> V_220 . V_285 = ( V_302 |
V_303 |
V_304 ) ;
break;
case 2 :
V_4 -> V_220 . V_285 = ( V_303 |
V_304 ) ;
break;
case 1 :
V_4 -> V_220 . V_285 = V_304 ;
break;
default:
break;
}
} else {
V_4 -> V_220 . V_285 = V_288 ;
}
}
}
int F_198 ( struct V_3 * V_4 ,
const struct V_305 * V_306 ,
unsigned V_307 )
{
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_308 ; V_40 ++ ) {
if ( V_4 -> V_309 [ V_40 ] . V_306 == V_306 ) {
return 0 ;
}
}
V_40 = V_4 -> V_308 + 1 ;
if ( V_40 > V_310 ) {
F_15 ( L_70 ) ;
F_15 ( L_71
L_72 ) ;
return - V_45 ;
}
V_4 -> V_309 [ V_4 -> V_308 ] . V_306 = V_306 ;
V_4 -> V_309 [ V_4 -> V_308 ] . V_311 = V_307 ;
V_4 -> V_308 = V_40 ;
#if F_199 ( V_312 )
F_200 ( V_306 , V_307 ,
V_4 -> V_89 -> V_313 -> V_314 ,
V_4 -> V_89 -> V_313 ) ;
F_200 ( V_306 , V_307 ,
V_4 -> V_89 -> V_257 -> V_314 ,
V_4 -> V_89 -> V_257 ) ;
#endif
return 0 ;
}
static void F_158 ( struct V_3 * V_4 )
{
#if F_199 ( V_312 )
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_308 ; V_40 ++ ) {
F_201 ( V_4 -> V_309 [ V_40 ] . V_306 ,
V_4 -> V_309 [ V_40 ] . V_311 ,
V_4 -> V_89 -> V_313 ) ;
F_201 ( V_4 -> V_309 [ V_40 ] . V_306 ,
V_4 -> V_309 [ V_40 ] . V_311 ,
V_4 -> V_89 -> V_257 ) ;
}
#endif
}
static T_7 F_202 ( struct V_315 * V_316 , char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
bool V_322 ;
unsigned V_323 , V_324 , V_325 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
if ( * V_318 & ( 1ULL << 62 ) ) {
V_325 = ( * V_318 >> 24 ) & 0x3FF ;
V_324 = ( * V_318 >> 34 ) & 0x3FF ;
V_323 = ( * V_318 >> 44 ) & 0x3FF ;
V_322 = 1 ;
* V_318 &= 0xFFFFFF ;
} else {
V_322 = 0 ;
}
if ( V_322 ) {
if ( V_324 >= V_4 -> V_221 . V_326 . V_327 ||
V_325 >= V_4 -> V_221 . V_326 . V_328 )
return - V_45 ;
F_203 ( & V_4 -> V_224 ) ;
F_204 ( V_4 , V_325 ,
V_324 , V_323 ) ;
}
while ( V_43 ) {
T_1 V_329 ;
if ( * V_318 > V_4 -> V_11 )
goto V_330;
V_329 = F_35 ( * V_318 >> 2 ) ;
V_27 = F_205 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 ) {
V_321 = V_27 ;
goto V_330;
}
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
V_330:
if ( V_322 ) {
F_204 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_206 ( & V_4 -> V_224 ) ;
}
return V_321 ;
}
static T_7 F_207 ( struct V_315 * V_316 , const char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
if ( * V_318 > V_4 -> V_11 )
return V_321 ;
V_27 = F_208 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
F_36 ( * V_318 >> 2 , V_329 ) ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_209 ( struct V_315 * V_316 , char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
V_329 = F_210 ( * V_318 >> 2 ) ;
V_27 = F_205 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_211 ( struct V_315 * V_316 , const char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
V_27 = F_208 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
F_212 ( * V_318 >> 2 , V_329 ) ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_213 ( struct V_315 * V_316 , char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
V_329 = F_214 ( * V_318 >> 2 ) ;
V_27 = F_205 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_215 ( struct V_315 * V_316 , const char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
V_27 = F_208 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
F_216 ( * V_318 >> 2 , V_329 ) ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_217 ( struct V_315 * V_316 , char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
V_329 = F_218 ( * V_318 >> 2 ) ;
V_27 = F_205 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_219 ( struct V_315 * V_316 , const char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
while ( V_43 ) {
T_1 V_329 ;
V_27 = F_208 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 )
return V_27 ;
F_220 ( * V_318 >> 2 , V_329 ) ;
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
return V_321 ;
}
static T_7 F_221 ( struct V_315 * V_316 , char T_8 * V_317 ,
T_4 V_43 , T_9 * V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 -> V_320 ;
T_7 V_321 = 0 ;
int V_27 ;
T_1 * V_326 , V_331 = 0 ;
if ( V_43 & 0x3 || * V_318 & 0x3 )
return - V_45 ;
V_326 = F_222 ( 256 * sizeof( * V_326 ) , V_77 ) ;
if ( ! V_326 )
return - V_46 ;
V_326 [ V_331 ++ ] = 0 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_328 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_332 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_333 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_327 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_334 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_335 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_336 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_337 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_338 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_339 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_340 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_341 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_342 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_343 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_344 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_345 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_346 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_347 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_348 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_349 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_350 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_351 ;
V_326 [ V_331 ++ ] = V_4 -> V_221 . V_326 . V_352 ;
while ( V_43 && ( * V_318 < V_331 * 4 ) ) {
T_1 V_329 ;
V_329 = V_326 [ * V_318 >> 2 ] ;
V_27 = F_205 ( V_329 , ( T_1 * ) V_317 ) ;
if ( V_27 ) {
F_79 ( V_326 ) ;
return V_27 ;
}
V_321 += 4 ;
V_317 += 4 ;
* V_318 += 4 ;
V_43 -= 4 ;
}
F_79 ( V_326 ) ;
return V_321 ;
}
static int F_142 ( struct V_3 * V_4 )
{
struct V_353 * V_138 = V_4 -> V_89 -> V_257 ;
struct V_354 * V_355 , * V_356 = V_138 -> V_314 ;
unsigned V_40 , V_357 ;
for ( V_40 = 0 ; V_40 < F_223 ( V_358 ) ; V_40 ++ ) {
V_355 = F_224 ( V_359 [ V_40 ] ,
V_360 | V_361 , V_356 ,
V_4 , V_358 [ V_40 ] ) ;
if ( F_225 ( V_355 ) ) {
for ( V_357 = 0 ; V_357 < V_40 ; V_357 ++ ) {
F_226 ( V_4 -> V_358 [ V_40 ] ) ;
V_4 -> V_358 [ V_40 ] = NULL ;
}
return F_227 ( V_355 ) ;
}
if ( ! V_40 )
F_228 ( V_355 -> V_362 , V_4 -> V_11 ) ;
V_4 -> V_358 [ V_40 ] = V_355 ;
}
return 0 ;
}
static void F_157 ( struct V_3 * V_4 )
{
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < F_223 ( V_358 ) ; V_40 ++ ) {
if ( V_4 -> V_358 [ V_40 ] ) {
F_226 ( V_4 -> V_358 [ V_40 ] ) ;
V_4 -> V_358 [ V_40 ] = NULL ;
}
}
}
int F_229 ( struct V_353 * V_138 )
{
return 0 ;
}
void F_230 ( struct V_353 * V_138 )
{
}
static int F_142 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_157 ( struct V_3 * V_4 ) { }
