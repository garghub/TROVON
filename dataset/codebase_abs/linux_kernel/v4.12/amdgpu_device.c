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
}
T_2 F_15 ( struct V_3 * V_4 , T_2 V_8 )
{
if ( ( V_8 * 4 ) < V_4 -> V_22 )
return F_16 ( V_4 -> V_23 + ( V_8 * 4 ) ) ;
else {
F_17 ( ( V_8 * 4 ) , V_4 -> V_23 + ( V_17 * 4 ) ) ;
return F_16 ( V_4 -> V_23 + ( V_18 * 4 ) ) ;
}
}
void F_18 ( struct V_3 * V_4 , T_2 V_8 , T_2 V_21 )
{
if ( ( V_8 * 4 ) < V_4 -> V_22 )
F_17 ( V_21 , V_4 -> V_23 + ( V_8 * 4 ) ) ;
else {
F_17 ( ( V_8 * 4 ) , V_4 -> V_23 + ( V_17 * 4 ) ) ;
F_17 ( V_21 , V_4 -> V_23 + ( V_18 * 4 ) ) ;
}
}
T_2 F_19 ( struct V_3 * V_4 , T_2 V_24 )
{
if ( V_24 < V_4 -> V_25 . V_26 ) {
return F_7 ( V_4 -> V_25 . V_27 + V_24 ) ;
} else {
F_20 ( L_1 , V_24 ) ;
return 0 ;
}
}
void F_21 ( struct V_3 * V_4 , T_2 V_24 , T_2 V_21 )
{
if ( V_24 < V_4 -> V_25 . V_26 ) {
F_9 ( V_21 , V_4 -> V_25 . V_27 + V_24 ) ;
} else {
F_20 ( L_2 , V_24 ) ;
}
}
T_3 F_22 ( struct V_3 * V_4 , T_2 V_24 )
{
if ( V_24 < V_4 -> V_25 . V_26 ) {
return F_23 ( ( V_28 * ) ( V_4 -> V_25 . V_27 + V_24 ) ) ;
} else {
F_20 ( L_1 , V_24 ) ;
return 0 ;
}
}
void F_24 ( struct V_3 * V_4 , T_2 V_24 , T_3 V_21 )
{
if ( V_24 < V_4 -> V_25 . V_26 ) {
F_25 ( ( V_28 * ) ( V_4 -> V_25 . V_27 + V_24 ) , V_21 ) ;
} else {
F_20 ( L_2 , V_24 ) ;
}
}
static T_1 F_26 ( struct V_3 * V_4 , T_1 V_8 )
{
F_20 ( L_3 , V_8 ) ;
F_27 () ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_21 )
{
F_20 ( L_4 ,
V_8 , V_21 ) ;
F_27 () ;
}
static T_1 F_29 ( struct V_3 * V_4 ,
T_1 V_29 , T_1 V_8 )
{
F_20 ( L_5 ,
V_8 , V_29 ) ;
F_27 () ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 ,
T_1 V_29 ,
T_1 V_8 , T_1 V_21 )
{
F_20 ( L_6 ,
V_8 , V_29 , V_21 ) ;
F_27 () ;
}
static int F_31 ( struct V_3 * V_4 )
{
int V_30 ;
if ( V_4 -> V_31 . V_32 == NULL ) {
V_30 = F_32 ( V_4 , V_33 ,
V_34 , true , V_35 ,
V_36 |
V_37 ,
NULL , NULL , & V_4 -> V_31 . V_32 ) ;
if ( V_30 ) {
return V_30 ;
}
}
V_30 = F_33 ( V_4 -> V_31 . V_32 , false ) ;
if ( F_34 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_35 ( V_4 -> V_31 . V_32 ,
V_35 , & V_4 -> V_31 . V_38 ) ;
if ( V_30 ) {
F_36 ( V_4 -> V_31 . V_32 ) ;
return V_30 ;
}
V_30 = F_37 ( V_4 -> V_31 . V_32 ,
( void * * ) & V_4 -> V_31 . V_27 ) ;
if ( V_30 )
F_38 ( V_4 -> V_31 . V_32 ) ;
F_36 ( V_4 -> V_31 . V_32 ) ;
return V_30 ;
}
static void F_39 ( struct V_3 * V_4 )
{
int V_30 ;
if ( V_4 -> V_31 . V_32 == NULL ) {
return;
}
V_30 = F_33 ( V_4 -> V_31 . V_32 , true ) ;
if ( F_40 ( V_30 == 0 ) ) {
F_41 ( V_4 -> V_31 . V_32 ) ;
F_38 ( V_4 -> V_31 . V_32 ) ;
F_36 ( V_4 -> V_31 . V_32 ) ;
}
F_42 ( & V_4 -> V_31 . V_32 ) ;
}
void F_43 ( struct V_3 * V_4 ,
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
V_41 = F_44 ( V_8 ) ;
V_41 &= ~ V_42 ;
V_41 |= V_43 ;
}
F_45 ( V_8 , V_41 ) ;
}
}
void F_46 ( struct V_3 * V_4 )
{
F_47 ( V_4 -> V_19 , 0x7c , V_45 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
V_4 -> V_25 . V_46 = F_49 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_25 . V_47 = F_50 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_25 . V_26 = F_51 ( T_2 , V_4 -> V_25 . V_47 / sizeof( T_2 ) ,
V_48 + 1 ) ;
if ( V_4 -> V_25 . V_26 == 0 )
return - V_49 ;
V_4 -> V_25 . V_27 = F_52 ( V_4 -> V_25 . V_46 ,
V_4 -> V_25 . V_26 *
sizeof( T_2 ) ) ;
if ( V_4 -> V_25 . V_27 == NULL )
return - V_50 ;
return 0 ;
}
static void F_53 ( struct V_3 * V_4 )
{
F_54 ( V_4 -> V_25 . V_27 ) ;
V_4 -> V_25 . V_27 = NULL ;
}
void F_55 ( struct V_3 * V_4 ,
T_4 * V_51 ,
T_5 * V_52 ,
T_5 * V_53 )
{
if ( V_4 -> V_25 . V_47 > V_4 -> V_25 . V_26 * sizeof( T_2 ) ) {
* V_51 = V_4 -> V_25 . V_46 ;
* V_52 = V_4 -> V_25 . V_47 ;
* V_53 = V_4 -> V_25 . V_26 * sizeof( T_2 ) ;
} else {
* V_51 = 0 ;
* V_52 = 0 ;
* V_53 = 0 ;
}
}
static void F_56 ( struct V_3 * V_4 )
{
if ( V_4 -> V_54 . V_55 ) {
F_57 ( & V_4 -> V_54 . V_55 ,
& V_4 -> V_54 . V_38 ,
( void * * ) & V_4 -> V_54 . V_54 ) ;
V_4 -> V_54 . V_55 = NULL ;
}
}
static int F_58 ( struct V_3 * V_4 )
{
int V_30 ;
if ( V_4 -> V_54 . V_55 == NULL ) {
V_30 = F_59 ( V_4 , V_56 * sizeof( T_1 ) ,
V_34 , V_57 ,
& V_4 -> V_54 . V_55 , & V_4 -> V_54 . V_38 ,
( void * * ) & V_4 -> V_54 . V_54 ) ;
if ( V_30 ) {
F_60 ( V_4 -> V_2 , L_7 , V_30 ) ;
return V_30 ;
}
V_4 -> V_54 . V_58 = V_56 ;
memset ( & V_4 -> V_54 . V_59 , 0 , sizeof( V_4 -> V_54 . V_59 ) ) ;
memset ( ( char * ) V_4 -> V_54 . V_54 , 0 , V_56 * sizeof( T_1 ) ) ;
}
return 0 ;
}
int F_61 ( struct V_3 * V_4 , T_2 * V_54 )
{
unsigned long V_60 = F_62 ( V_4 -> V_54 . V_59 , V_4 -> V_54 . V_58 ) ;
if ( V_60 < V_4 -> V_54 . V_58 ) {
F_63 ( V_60 , V_4 -> V_54 . V_59 ) ;
* V_54 = V_60 ;
return 0 ;
} else {
return - V_49 ;
}
}
int F_64 ( struct V_3 * V_4 , T_2 * V_54 )
{
unsigned long V_60 = F_65 ( V_4 -> V_54 . V_59 ,
V_4 -> V_54 . V_58 , 0 , 2 , 7 , 0 ) ;
if ( ( V_60 + 1 ) < V_4 -> V_54 . V_58 ) {
F_63 ( V_60 , V_4 -> V_54 . V_59 ) ;
F_63 ( V_60 + 1 , V_4 -> V_54 . V_59 ) ;
* V_54 = V_60 ;
return 0 ;
} else {
return - V_49 ;
}
}
void F_66 ( struct V_3 * V_4 , T_2 V_54 )
{
if ( V_54 < V_4 -> V_54 . V_58 )
F_67 ( V_54 , V_4 -> V_54 . V_59 ) ;
}
void F_68 ( struct V_3 * V_4 , T_2 V_54 )
{
if ( ( V_54 + 1 ) < V_4 -> V_54 . V_58 ) {
F_67 ( V_54 , V_4 -> V_54 . V_59 ) ;
F_67 ( V_54 + 1 , V_4 -> V_54 . V_59 ) ;
}
}
void F_69 ( struct V_3 * V_4 , struct V_61 * V_62 , T_3 V_46 )
{
T_6 V_63 = ( T_6 ) V_64 << 20 ;
V_62 -> V_65 = V_46 ;
if ( V_62 -> V_66 > ( V_4 -> V_62 . V_67 - V_46 + 1 ) ) {
F_60 ( V_4 -> V_2 , L_8 ) ;
V_62 -> V_68 = V_62 -> V_69 ;
V_62 -> V_66 = V_62 -> V_69 ;
}
V_62 -> V_70 = V_62 -> V_65 + V_62 -> V_66 - 1 ;
if ( V_63 && V_63 < V_62 -> V_68 )
V_62 -> V_68 = V_63 ;
F_70 ( V_4 -> V_2 , L_9 ,
V_62 -> V_66 >> 20 , V_62 -> V_65 ,
V_62 -> V_70 , V_62 -> V_68 >> 20 ) ;
}
void F_71 ( struct V_3 * V_4 , struct V_61 * V_62 )
{
T_3 V_71 , V_72 ;
V_71 = ( ( V_4 -> V_62 . V_67 - V_62 -> V_70 ) + V_62 -> V_73 ) & ~ V_62 -> V_73 ;
V_72 = V_62 -> V_65 & ~ V_62 -> V_73 ;
if ( V_72 > V_71 ) {
if ( V_62 -> V_74 > V_72 ) {
F_60 ( V_4 -> V_2 , L_10 ) ;
V_62 -> V_74 = V_72 ;
}
V_62 -> V_75 = 0 ;
} else {
if ( V_62 -> V_74 > V_71 ) {
F_60 ( V_4 -> V_2 , L_10 ) ;
V_62 -> V_74 = V_71 ;
}
V_62 -> V_75 = ( V_62 -> V_70 + 1 + V_62 -> V_73 ) & ~ V_62 -> V_73 ;
}
V_62 -> V_76 = V_62 -> V_75 + V_62 -> V_74 - 1 ;
F_70 ( V_4 -> V_2 , L_11 ,
V_62 -> V_74 >> 20 , V_62 -> V_75 , V_62 -> V_76 ) ;
}
bool F_72 ( struct V_3 * V_4 )
{
T_1 V_8 ;
if ( V_4 -> V_77 ) {
V_4 -> V_77 = false ;
return true ;
}
V_8 = F_73 ( V_4 ) ;
if ( ( V_8 != 0 ) && ( V_8 != 0xffffffff ) )
return false ;
return true ;
}
static bool F_74 ( struct V_3 * V_4 )
{
if ( F_75 ( V_4 ) )
return false ;
if ( F_76 ( V_4 ) ) {
if ( V_4 -> V_78 == V_79 ) {
int V_80 ;
T_1 V_81 ;
V_80 = F_77 ( & V_4 -> V_82 . V_83 , L_12 , V_4 -> V_2 ) ;
if ( V_80 )
return true ;
V_81 = * ( ( T_1 * ) V_4 -> V_82 . V_83 -> V_84 + 69 ) ;
if ( V_81 < 0x00160e00 )
return true ;
}
}
return F_72 ( V_4 ) ;
}
int F_78 ( struct V_3 * V_4 )
{
if ( V_4 -> V_85 . V_86 )
return 0 ;
V_4 -> V_85 . V_86 = F_79 ( V_87 | V_88 | V_89 ) ;
if ( V_4 -> V_85 . V_86 == NULL )
return - V_50 ;
V_4 -> V_85 . V_90 = F_80 ( V_4 -> V_19 , V_4 -> V_85 . V_86 ,
0 , V_34 , V_91 ) ;
if ( F_81 ( V_4 -> V_19 , V_4 -> V_85 . V_90 ) ) {
F_82 ( & V_4 -> V_19 -> V_2 , L_13 ) ;
F_83 ( V_4 -> V_85 . V_86 ) ;
V_4 -> V_85 . V_86 = NULL ;
return - V_50 ;
}
return 0 ;
}
void F_84 ( struct V_3 * V_4 )
{
if ( V_4 -> V_85 . V_86 == NULL )
return;
F_85 ( V_4 -> V_19 , V_4 -> V_85 . V_90 ,
V_34 , V_91 ) ;
F_83 ( V_4 -> V_85 . V_86 ) ;
V_4 -> V_85 . V_86 = NULL ;
}
static T_1 F_86 ( struct V_92 * V_93 , T_1 V_8 )
{
return 0 ;
}
static void F_87 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
}
static T_1 F_88 ( struct V_92 * V_93 , T_1 V_8 )
{
return 0 ;
}
static void F_89 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
}
static void F_90 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
F_45 ( V_8 , V_94 ) ;
}
static T_1 F_91 ( struct V_92 * V_93 , T_1 V_8 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
T_1 V_30 ;
V_30 = F_44 ( V_8 ) ;
return V_30 ;
}
static void F_92 ( struct V_92 * V_93 , T_1 V_8 , T_1 V_94 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
F_93 ( V_8 , V_94 ) ;
}
static T_1 F_94 ( struct V_92 * V_93 , T_1 V_8 )
{
struct V_3 * V_4 = V_93 -> V_2 -> V_5 ;
T_1 V_30 ;
V_30 = F_95 ( V_8 ) ;
return V_30 ;
}
static void F_96 ( struct V_3 * V_4 )
{
if ( V_4 -> V_95 . V_96 ) {
F_97 ( V_4 -> V_95 . V_96 -> V_97 ) ;
F_97 ( V_4 -> V_95 . V_96 -> V_98 ) ;
}
F_97 ( V_4 -> V_95 . V_96 ) ;
V_4 -> V_95 . V_96 = NULL ;
F_97 ( V_4 -> V_95 . V_99 ) ;
V_4 -> V_95 . V_99 = NULL ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_92 * V_99 =
F_99 ( sizeof( struct V_92 ) , V_88 ) ;
if ( ! V_99 )
return - V_50 ;
V_4 -> V_95 . V_99 = V_99 ;
V_99 -> V_2 = V_4 -> V_100 ;
V_99 -> V_101 = F_91 ;
V_99 -> V_102 = F_90 ;
if ( V_4 -> V_23 ) {
V_99 -> V_103 = F_94 ;
V_99 -> V_104 = F_92 ;
} else {
F_100 ( L_14 ) ;
V_99 -> V_103 = F_91 ;
V_99 -> V_104 = F_90 ;
}
V_99 -> V_105 = F_88 ;
V_99 -> V_106 = F_89 ;
V_99 -> V_107 = F_86 ;
V_99 -> V_108 = F_87 ;
V_4 -> V_95 . V_96 = F_101 ( V_99 , V_4 -> V_109 ) ;
if ( ! V_4 -> V_95 . V_96 ) {
F_96 ( V_4 ) ;
return - V_50 ;
}
F_102 ( & V_4 -> V_95 . V_96 -> V_110 ) ;
if ( V_4 -> V_111 ) {
F_103 ( V_4 ) ;
F_104 ( V_4 ) ;
} else {
F_105 ( V_4 ) ;
F_106 ( V_4 ) ;
}
return 0 ;
}
static unsigned int F_107 ( void * V_112 , bool V_113 )
{
struct V_3 * V_4 = V_112 ;
F_108 ( V_4 , V_113 ) ;
if ( V_113 )
return V_114 | V_115 |
V_116 | V_117 ;
else
return V_116 | V_117 ;
}
static bool F_109 ( int V_118 )
{
return ( V_118 & ( V_118 - 1 ) ) == 0 ;
}
static void F_110 ( struct V_3 * V_4 )
{
if ( V_119 == - 1 )
return;
if ( V_119 < 9 ) {
F_60 ( V_4 -> V_2 , L_15 ,
V_119 ) ;
goto V_120;
}
if ( V_119 > 24 ||
( V_121 * 1024 ) < ( 1ull << V_119 ) ) {
F_60 ( V_4 -> V_2 , L_16 ,
V_119 ) ;
goto V_120;
}
return;
V_120:
V_119 = - 1 ;
}
static void F_111 ( struct V_3 * V_4 )
{
if ( ! F_109 ( V_121 ) ) {
F_60 ( V_4 -> V_2 , L_17 ,
V_121 ) ;
goto V_120;
}
if ( V_121 < 1 ) {
F_60 ( V_4 -> V_2 , L_18 ,
V_121 ) ;
goto V_120;
}
if ( V_121 > 1024 ) {
F_60 ( V_4 -> V_2 , L_19 ,
V_121 ) ;
goto V_120;
}
return;
V_120:
V_121 = - 1 ;
}
static void F_112 ( struct V_3 * V_4 )
{
if ( V_122 < 4 ) {
F_60 ( V_4 -> V_2 , L_20 ,
V_122 ) ;
V_122 = 4 ;
} else if ( ! F_109 ( V_122 ) ) {
F_60 ( V_4 -> V_2 , L_21 ,
V_122 ) ;
V_122 = F_113 ( V_122 ) ;
}
if ( V_123 != - 1 ) {
if ( V_123 < 32 ) {
F_60 ( V_4 -> V_2 , L_22 ,
V_123 ) ;
V_123 = - 1 ;
}
}
F_111 ( V_4 ) ;
F_110 ( V_4 ) ;
if ( V_124 != - 1 && ( V_124 < 16 ||
! F_109 ( V_124 ) ) ) {
F_60 ( V_4 -> V_2 , L_23 ,
V_124 ) ;
V_124 = 1024 ;
}
}
static void F_114 ( struct V_125 * V_19 , enum V_126 V_113 )
{
struct V_1 * V_2 = F_115 ( V_19 ) ;
if ( F_1 ( V_2 ) && V_113 == V_127 )
return;
if ( V_113 == V_128 ) {
unsigned V_129 = V_2 -> V_19 -> V_129 ;
F_116 ( L_24 ) ;
V_2 -> V_130 = V_131 ;
F_117 ( V_2 , true , true ) ;
V_2 -> V_19 -> V_129 = V_129 ;
V_2 -> V_130 = V_132 ;
F_118 ( V_2 ) ;
} else {
F_116 ( L_25 ) ;
F_119 ( V_2 ) ;
V_2 -> V_130 = V_131 ;
F_120 ( V_2 , true , true ) ;
V_2 -> V_130 = V_133 ;
}
}
static bool F_121 ( struct V_125 * V_19 )
{
struct V_1 * V_2 = F_115 ( V_19 ) ;
return V_2 -> V_134 == 0 ;
}
int F_122 ( struct V_3 * V_4 ,
enum V_135 V_136 ,
enum V_137 V_113 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_136 )
continue;
if ( ! V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 (
( void * ) V_4 , V_113 ) ;
if ( V_30 )
F_20 ( L_26 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
return V_30 ;
}
int F_123 ( struct V_3 * V_4 ,
enum V_135 V_136 ,
enum V_146 V_113 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_136 )
continue;
if ( ! V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_147 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_147 (
( void * ) V_4 , V_113 ) ;
if ( V_30 )
F_20 ( L_27 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
return V_30 ;
}
void F_124 ( struct V_3 * V_4 , T_2 * V_6 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_148 )
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_148 ( ( void * ) V_4 , V_6 ) ;
}
}
int F_125 ( struct V_3 * V_4 ,
enum V_135 V_136 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_136 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_149 ( ( void * ) V_4 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
return 0 ;
}
bool F_126 ( struct V_3 * V_4 ,
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
struct V_151 * F_127 ( struct V_3 * V_4 ,
enum V_135 type )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ )
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == type )
return & V_4 -> V_139 [ V_44 ] ;
return NULL ;
}
int F_128 ( struct V_3 * V_4 ,
enum V_135 type ,
T_2 V_152 , T_2 V_153 )
{
struct V_151 * V_154 = F_127 ( V_4 , type ) ;
if ( V_154 && ( ( V_154 -> V_142 -> V_152 > V_152 ) ||
( ( V_154 -> V_142 -> V_152 == V_152 ) &&
( V_154 -> V_142 -> V_153 >= V_153 ) ) ) )
return 0 ;
return 1 ;
}
int F_129 ( struct V_3 * V_4 ,
const struct V_155 * V_156 )
{
if ( ! V_156 )
return - V_49 ;
V_4 -> V_139 [ V_4 -> V_138 ++ ] . V_142 = V_156 ;
return 0 ;
}
static void F_130 ( struct V_3 * V_4 )
{
V_4 -> V_157 = false ;
if ( V_158 ) {
struct V_1 * V_100 = V_4 -> V_100 ;
const char * V_159 = F_131 ( V_100 -> V_19 ) ;
char * V_160 , * V_161 , * V_162 , * V_163 ;
V_160 = F_132 ( V_158 , V_88 ) ;
V_161 = V_160 ;
while ( ( V_162 = F_133 ( & V_161 , L_28 ) ) ) {
V_163 = F_133 ( & V_162 , L_29 ) ;
if ( ! strcmp ( L_30 , V_163 )
|| ! strcmp ( V_159 , V_163 ) ) {
long V_164 ;
int V_165 = - 1 ;
V_4 -> V_157 = true ;
if ( V_162 )
V_165 = F_134 ( V_162 , 10 ,
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
F_100 ( L_31 ,
V_158 , V_159 ,
V_4 -> V_157 , V_4 -> V_95 . V_164 ) ;
F_97 ( V_160 ) ;
}
}
static int F_135 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
F_130 ( V_4 ) ;
switch ( V_4 -> V_78 ) {
case V_166 :
case V_167 :
case V_79 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
if ( V_4 -> V_78 == V_171 || V_4 -> V_78 == V_172 )
V_4 -> V_173 = V_174 ;
else
V_4 -> V_173 = V_175 ;
V_30 = F_136 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
#ifdef F_137
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
V_4 -> V_173 = V_181 ;
V_30 = F_138 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
#endif
#ifdef F_139
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
if ( ( V_4 -> V_78 == V_182 ) || ( V_4 -> V_78 == V_183 ) )
V_4 -> V_173 = V_187 ;
else
V_4 -> V_173 = V_188 ;
V_30 = F_140 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
#endif
case V_189 :
V_4 -> V_173 = V_190 ;
V_30 = F_141 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
default:
return - V_49 ;
}
if ( F_75 ( V_4 ) ) {
V_30 = F_142 ( V_4 , true ) ;
if ( V_30 )
return V_30 ;
}
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ( V_191 & ( 1 << V_44 ) ) == 0 ) {
F_20 ( L_32 , V_44 ) ;
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = false ;
} else {
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_192 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_192 ( ( void * ) V_4 ) ;
if ( V_30 == - V_193 ) {
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = false ;
} else if ( V_30 ) {
F_20 ( L_33 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
} else {
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = true ;
}
} else {
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = true ;
}
}
}
V_4 -> V_194 &= V_195 ;
V_4 -> V_196 &= V_197 ;
return 0 ;
}
static int F_143 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_198 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_34 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_199 = true ;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_200 ) {
V_30 = F_31 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_35 , V_30 ) ;
return V_30 ;
}
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_201 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_36 , V_44 , V_30 ) ;
return V_30 ;
}
V_30 = F_58 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_37 , V_30 ) ;
return V_30 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_202 = true ;
if ( F_75 ( V_4 ) ) {
V_30 = F_144 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_38 , V_30 ) ;
return V_30 ;
}
}
}
}
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_199 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_200 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_201 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_39 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_202 = true ;
}
return 0 ;
}
static int F_145 ( struct V_3 * V_4 )
{
int V_44 = 0 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_203 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_203 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_40 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_204 = true ;
}
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_205 &&
V_4 -> V_139 [ V_44 ] . V_142 -> type != V_206 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_207 ) ;
if ( V_30 ) {
F_20 ( L_41 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
}
}
return 0 ;
}
static int F_146 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_202 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_208 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_209 ) ;
if ( V_30 ) {
F_20 ( L_42 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_210 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_147 ( L_43 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_202 = false ;
break;
}
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_202 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_200 ) {
F_56 ( V_4 ) ;
F_39 ( V_4 ) ;
}
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type != V_205 &&
V_4 -> V_139 [ V_44 ] . V_142 -> type != V_206 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_209 ) ;
if ( V_30 ) {
F_20 ( L_42 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
}
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_210 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_147 ( L_43 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_202 = false ;
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_199 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_211 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_147 ( L_44 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
V_4 -> V_139 [ V_44 ] . V_140 . V_199 = false ;
V_4 -> V_139 [ V_44 ] . V_140 . V_141 = false ;
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_204 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_212 )
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_212 ( ( void * ) V_4 ) ;
V_4 -> V_139 [ V_44 ] . V_140 . V_204 = false ;
}
if ( F_75 ( V_4 ) ) {
F_57 ( & V_4 -> V_213 . V_214 , & V_4 -> V_213 . V_215 , NULL ) ;
F_148 ( V_4 , false ) ;
}
return 0 ;
}
int F_149 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
if ( F_75 ( V_4 ) )
F_142 ( V_4 , false ) ;
V_30 = F_122 ( V_4 , V_208 ,
V_209 ) ;
if ( V_30 ) {
F_20 ( L_45 , V_30 ) ;
}
for ( V_44 = V_4 -> V_138 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_44 != V_208 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_144 ( ( void * ) V_4 ,
V_209 ) ;
if ( V_30 ) {
F_20 ( L_42 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
}
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_216 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_46 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
}
}
if ( F_75 ( V_4 ) )
F_148 ( V_4 , false ) ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_217 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_200 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_218 )
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_201 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_47 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_151 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_217 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_200 ||
V_4 -> V_139 [ V_44 ] . V_142 -> type == V_218 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_201 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_47 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_152 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_219 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_47 ,
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static void F_153 ( struct V_3 * V_4 )
{
if ( V_4 -> V_111 ) {
if ( F_154 ( V_4 ) )
V_4 -> V_213 . V_220 |= V_221 ;
} else {
if ( F_155 ( V_4 ) )
V_4 -> V_213 . V_220 |= V_221 ;
}
}
int F_156 ( struct V_3 * V_4 ,
struct V_1 * V_100 ,
struct V_125 * V_19 ,
T_1 V_6 )
{
int V_30 , V_44 ;
bool V_222 = false ;
T_2 V_223 ;
V_4 -> V_224 = false ;
V_4 -> V_2 = & V_19 -> V_2 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_78 = V_6 & V_225 ;
V_4 -> V_226 = V_227 ;
V_4 -> V_62 . V_74 = 512 * 1024 * 1024 ;
V_4 -> V_228 = false ;
V_4 -> V_229 = 0 ;
V_4 -> V_230 . V_231 = NULL ;
V_4 -> V_230 . V_232 = NULL ;
V_4 -> V_233 . V_234 = NULL ;
V_4 -> V_233 . V_235 = 0 ;
V_4 -> V_236 . V_237 = NULL ;
V_4 -> V_238 = F_157 ( V_239 ) ;
V_4 -> V_240 = & F_26 ;
V_4 -> V_241 = & F_28 ;
V_4 -> V_242 = & F_26 ;
V_4 -> V_243 = & F_28 ;
V_4 -> V_244 = & F_26 ;
V_4 -> V_245 = & F_28 ;
V_4 -> V_246 = & F_26 ;
V_4 -> V_247 = & F_28 ;
V_4 -> V_248 = & F_26 ;
V_4 -> V_249 = & F_28 ;
V_4 -> V_250 = & F_26 ;
V_4 -> V_251 = & F_28 ;
V_4 -> V_252 = & F_29 ;
V_4 -> V_253 = & F_30 ;
F_100 ( L_48 ,
V_254 [ V_4 -> V_78 ] , V_19 -> V_255 , V_19 -> V_20 ,
V_19 -> V_256 , V_19 -> V_257 , V_19 -> V_258 ) ;
F_158 ( & V_4 -> V_259 . V_260 . V_261 , 0 ) ;
F_102 ( & V_4 -> V_262 . V_110 ) ;
F_102 ( & V_4 -> V_82 . V_110 ) ;
F_102 ( & V_4 -> V_263 . V_264 ) ;
F_102 ( & V_4 -> V_265 ) ;
F_102 ( & V_4 -> V_266 ) ;
F_102 ( & V_4 -> V_267 ) ;
F_159 ( V_4 -> V_268 ) ;
F_112 ( V_4 ) ;
F_160 ( & V_4 -> V_16 ) ;
F_160 ( & V_4 -> V_269 ) ;
F_160 ( & V_4 -> V_270 ) ;
F_160 ( & V_4 -> V_271 ) ;
F_160 ( & V_4 -> V_272 ) ;
F_160 ( & V_4 -> V_273 ) ;
F_160 ( & V_4 -> V_274 ) ;
F_160 ( & V_4 -> V_275 . V_261 ) ;
F_161 ( & V_4 -> V_276 ) ;
F_102 ( & V_4 -> V_277 ) ;
F_161 ( & V_4 -> V_278 ) ;
F_160 ( & V_4 -> V_279 ) ;
if ( V_4 -> V_78 >= V_182 ) {
V_4 -> V_280 = F_49 ( V_4 -> V_19 , 5 ) ;
V_4 -> V_12 = F_50 ( V_4 -> V_19 , 5 ) ;
} else {
V_4 -> V_280 = F_49 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_12 = F_50 ( V_4 -> V_19 , 2 ) ;
}
V_4 -> V_15 = F_52 ( V_4 -> V_280 , V_4 -> V_12 ) ;
if ( V_4 -> V_15 == NULL ) {
return - V_50 ;
}
F_100 ( L_49 , ( T_1 ) V_4 -> V_280 ) ;
F_100 ( L_50 , ( unsigned ) V_4 -> V_12 ) ;
if ( V_4 -> V_78 >= V_182 )
F_48 ( V_4 ) ;
for ( V_44 = 0 ; V_44 < V_281 ; V_44 ++ ) {
if ( F_162 ( V_4 -> V_19 , V_44 ) & V_282 ) {
V_4 -> V_22 = F_50 ( V_4 -> V_19 , V_44 ) ;
V_4 -> V_23 = F_163 ( V_4 -> V_19 , V_44 , V_4 -> V_22 ) ;
break;
}
}
if ( V_4 -> V_23 == NULL )
F_100 ( L_51 ) ;
V_30 = F_135 ( V_4 ) ;
if ( V_30 )
return V_30 ;
F_164 ( V_4 -> V_19 , V_4 , NULL , F_107 ) ;
if ( V_283 == 1 )
V_222 = true ;
if ( F_1 ( V_100 ) )
V_222 = true ;
if ( ! F_165 ( V_4 -> V_19 ) )
F_166 ( V_4 -> V_19 ,
& V_284 , V_222 ) ;
if ( V_222 )
F_167 ( V_4 -> V_2 , & V_4 -> V_285 ) ;
if ( ! F_168 ( V_4 ) ) {
V_30 = - V_49 ;
goto V_286;
}
V_30 = F_98 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_52 ) ;
goto V_286;
}
F_153 ( V_4 ) ;
if ( F_74 ( V_4 ) ) {
if ( ! V_4 -> V_109 ) {
F_82 ( V_4 -> V_2 , L_53 ) ;
V_30 = - V_49 ;
goto V_286;
}
F_100 ( L_54 ) ;
V_30 = F_169 ( V_4 -> V_95 . V_96 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_55 ) ;
goto V_286;
}
} else {
F_100 ( L_56 ) ;
}
if ( ! V_4 -> V_111 ) {
V_30 = F_170 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_57 ) ;
return V_30 ;
}
F_171 ( V_4 ) ;
}
V_30 = F_172 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_58 ) ;
goto V_286;
}
F_173 ( V_4 -> V_100 ) ;
V_30 = F_143 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_59 ) ;
F_146 ( V_4 ) ;
goto V_286;
}
V_4 -> V_228 = true ;
if ( V_287 >= 0 )
V_223 = V_287 ;
else
V_223 = 8 ;
V_4 -> V_275 . V_288 = F_174 ( F_175 ( 1u , V_223 ) ) ;
V_30 = F_176 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_60 , V_30 ) ;
goto V_286;
}
V_30 = F_177 ( V_4 ) ;
if ( V_30 )
F_20 ( L_61 , V_30 ) ;
F_178 ( V_4 ) ;
V_30 = F_179 ( V_4 ) ;
if ( V_30 )
F_20 ( L_62 , V_30 ) ;
V_30 = F_180 ( V_4 ) ;
if ( V_30 )
F_20 ( L_63 , V_30 ) ;
V_30 = F_181 ( V_4 ) ;
if ( V_30 )
F_20 ( L_64 , V_30 ) ;
if ( ( V_289 & 1 ) ) {
if ( V_4 -> V_228 )
F_182 ( V_4 ) ;
else
F_100 ( L_65 ) ;
}
if ( V_290 ) {
if ( V_4 -> V_228 )
F_183 ( V_4 , V_290 ) ;
else
F_100 ( L_66 ) ;
}
V_30 = F_145 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_67 ) ;
goto V_286;
}
return 0 ;
V_286:
if ( V_222 )
F_184 ( V_4 -> V_2 ) ;
return V_30 ;
}
void F_185 ( struct V_3 * V_4 )
{
int V_30 ;
F_100 ( L_68 ) ;
V_4 -> V_224 = true ;
if ( V_4 -> V_95 . V_291 )
F_186 ( V_4 -> V_100 ) ;
F_187 ( V_4 ) ;
F_188 ( V_4 ) ;
F_189 ( V_4 ) ;
F_190 ( V_4 ) ;
V_30 = F_146 ( V_4 ) ;
V_4 -> V_228 = false ;
F_191 ( V_4 ) ;
F_96 ( V_4 ) ;
F_97 ( V_4 -> V_109 ) ;
V_4 -> V_109 = NULL ;
if ( ! F_165 ( V_4 -> V_19 ) )
F_192 ( V_4 -> V_19 ) ;
if ( V_4 -> V_6 & V_7 )
F_184 ( V_4 -> V_2 ) ;
F_164 ( V_4 -> V_19 , NULL , NULL , NULL ) ;
if ( V_4 -> V_23 )
F_193 ( V_4 -> V_19 , V_4 -> V_23 ) ;
V_4 -> V_23 = NULL ;
F_54 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
if ( V_4 -> V_78 >= V_182 )
F_53 ( V_4 ) ;
F_194 ( V_4 ) ;
}
int F_120 ( struct V_1 * V_2 , bool V_216 , bool V_292 )
{
struct V_3 * V_4 ;
struct V_293 * V_294 ;
struct V_295 * V_296 ;
int V_30 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_297 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_130 == V_133 )
return 0 ;
F_119 ( V_2 ) ;
F_195 ( V_2 ) ;
F_196 (connector, &dev->mode_config.connector_list, head) {
F_197 ( V_296 , V_298 ) ;
}
F_198 ( V_2 ) ;
F_196 (crtc, &dev->mode_config.crtc_list, head) {
struct V_299 * V_299 = F_199 ( V_294 ) ;
struct V_300 * V_301 = F_200 ( V_294 -> V_302 -> V_303 ) ;
struct V_304 * V_32 ;
if ( V_299 -> V_305 ) {
struct V_304 * V_306 = F_201 ( V_299 -> V_305 ) ;
V_30 = F_33 ( V_306 , true ) ;
if ( V_30 == 0 ) {
F_38 ( V_306 ) ;
F_36 ( V_306 ) ;
}
}
if ( V_301 == NULL || V_301 -> V_307 == NULL ) {
continue;
}
V_32 = F_201 ( V_301 -> V_307 ) ;
if ( ! F_202 ( V_4 , V_32 ) ) {
V_30 = F_33 ( V_32 , true ) ;
if ( V_30 == 0 ) {
F_38 ( V_32 ) ;
F_36 ( V_32 ) ;
}
}
}
F_187 ( V_4 ) ;
F_203 ( V_4 ) ;
V_30 = F_149 ( V_4 ) ;
F_187 ( V_4 ) ;
if ( V_4 -> V_111 )
F_204 ( V_4 ) ;
else
F_205 ( V_4 ) ;
F_206 ( V_2 -> V_19 ) ;
if ( V_216 ) {
F_207 ( V_2 -> V_19 ) ;
F_208 ( V_2 -> V_19 , V_308 ) ;
} else {
V_30 = F_209 ( V_4 ) ;
if ( V_30 )
F_20 ( L_69 ) ;
}
if ( V_292 ) {
F_210 () ;
F_211 ( V_4 , 1 ) ;
F_212 () ;
}
return 0 ;
}
int F_117 ( struct V_1 * V_2 , bool V_219 , bool V_292 )
{
struct V_295 * V_296 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_293 * V_294 ;
int V_30 = 0 ;
if ( V_2 -> V_130 == V_133 )
return 0 ;
if ( V_292 )
F_210 () ;
if ( V_219 ) {
F_208 ( V_2 -> V_19 , V_309 ) ;
F_213 ( V_2 -> V_19 ) ;
V_30 = F_214 ( V_2 -> V_19 ) ;
if ( V_30 )
goto V_310;
}
if ( V_4 -> V_111 )
F_215 ( V_4 ) ;
else
F_216 ( V_4 ) ;
if ( F_72 ( V_4 ) ) {
V_30 = F_169 ( V_4 -> V_95 . V_96 ) ;
if ( V_30 )
F_20 ( L_70 ) ;
}
V_30 = F_152 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_71 , V_30 ) ;
goto V_310;
}
F_217 ( V_4 ) ;
if ( V_219 ) {
V_30 = F_177 ( V_4 ) ;
if ( V_30 )
F_20 ( L_61 , V_30 ) ;
}
V_30 = F_145 ( V_4 ) ;
if ( V_30 )
goto V_310;
F_196 (crtc, &dev->mode_config.crtc_list, head) {
struct V_299 * V_299 = F_199 ( V_294 ) ;
if ( V_299 -> V_305 ) {
struct V_304 * V_306 = F_201 ( V_299 -> V_305 ) ;
V_30 = F_33 ( V_306 , true ) ;
if ( V_30 == 0 ) {
V_30 = F_35 ( V_306 ,
V_35 ,
& V_299 -> V_311 ) ;
if ( V_30 != 0 )
F_20 ( L_72 , V_30 ) ;
F_36 ( V_306 ) ;
}
}
}
if ( V_292 ) {
F_218 ( V_2 ) ;
F_195 ( V_2 ) ;
F_196 (connector, &dev->mode_config.connector_list, head) {
F_197 ( V_296 , V_312 ) ;
}
F_198 ( V_2 ) ;
}
F_118 ( V_2 ) ;
#ifdef F_219
V_2 -> V_2 -> V_313 . V_314 ++ ;
#endif
F_220 ( V_2 ) ;
#ifdef F_219
V_2 -> V_2 -> V_313 . V_314 -- ;
#endif
if ( V_292 )
F_211 ( V_4 , 0 ) ;
V_310:
if ( V_292 )
F_212 () ;
return V_30 ;
}
static bool F_221 ( struct V_3 * V_4 )
{
int V_44 ;
bool V_315 = false ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_316 )
V_4 -> V_139 [ V_44 ] . V_140 . V_317 =
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_316 ( V_4 ) ;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_317 ) {
F_100 ( L_73 , V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_145 ) ;
V_315 = true ;
}
}
return V_315 ;
}
static int F_222 ( struct V_3 * V_4 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_317 &&
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_318 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_318 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static bool F_223 ( struct V_3 * V_4 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( ( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_200 ) ||
( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_208 ) ||
( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_319 ) ||
( V_4 -> V_139 [ V_44 ] . V_142 -> type == V_320 ) ) {
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_317 ) {
F_100 ( L_74 ) ;
return true ;
}
}
}
return false ;
}
static int F_224 ( struct V_3 * V_4 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_317 &&
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_321 ) {
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_321 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static int F_225 ( struct V_3 * V_4 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_138 ; V_44 ++ ) {
if ( ! V_4 -> V_139 [ V_44 ] . V_140 . V_141 )
continue;
if ( V_4 -> V_139 [ V_44 ] . V_140 . V_317 &&
V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_322 )
V_30 = V_4 -> V_139 [ V_44 ] . V_142 -> V_143 -> V_322 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
bool F_226 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 & V_323 )
return false ;
return V_324 > 0 ? true : false ;
}
static int F_227 ( struct V_3 * V_4 ,
struct V_325 * V_326 ,
struct V_304 * V_327 ,
struct V_328 * * V_329 )
{
T_1 V_330 ;
int V_30 ;
if ( ! V_327 -> V_331 )
return 0 ;
V_30 = F_33 ( V_327 , true ) ;
if ( V_30 )
return V_30 ;
V_330 = F_228 ( V_327 -> V_332 . V_333 . V_334 ) ;
if ( V_330 == V_35 ) {
V_30 = F_229 ( V_327 -> V_331 ) ;
if ( V_30 ) {
F_20 ( L_75 ) ;
goto V_80;
}
V_30 = F_230 ( & V_327 -> V_331 -> V_332 , & V_327 -> V_331 -> V_332 . V_333 ) ;
if ( V_30 ) {
F_20 ( L_76 , V_327 -> V_331 ) ;
goto V_80;
}
V_30 = F_231 ( V_4 , V_326 , V_327 ,
NULL , V_329 , true ) ;
if ( V_30 ) {
F_20 ( L_77 ) ;
goto V_80;
}
}
V_80:
F_36 ( V_327 ) ;
return V_30 ;
}
int F_232 ( struct V_3 * V_4 , bool V_335 )
{
int V_44 , V_30 = 0 ;
int V_336 ;
struct V_304 * V_327 , * V_41 ;
struct V_325 * V_326 ;
struct V_328 * V_329 = NULL , * V_337 = NULL ;
F_233 ( & V_4 -> V_213 . V_338 ) ;
F_234 ( & V_4 -> V_339 ) ;
V_4 -> V_263 . V_340 = true ;
V_336 = F_235 ( & V_4 -> V_230 . V_341 ) ;
for ( V_44 = 0 ; V_44 < V_239 ; ++ V_44 ) {
V_326 = V_4 -> V_342 [ V_44 ] ;
if ( ! V_326 || ! V_326 -> V_343 . V_344 )
continue;
F_236 ( V_326 -> V_343 . V_344 ) ;
F_237 ( & V_326 -> V_343 ) ;
}
F_238 ( V_4 ) ;
if ( V_335 )
F_239 ( V_4 ) ;
else
F_142 ( V_4 , true ) ;
F_150 ( V_4 ) ;
F_240 ( V_4 ) ;
F_151 ( V_4 ) ;
F_241 ( V_4 ) ;
if ( F_177 ( V_4 ) )
F_82 ( V_4 -> V_2 , L_78 , V_30 ) ;
F_148 ( V_4 , true ) ;
F_100 ( L_79 ) ;
V_326 = V_4 -> V_230 . V_232 ;
F_233 ( & V_4 -> V_277 ) ;
F_242 (bo, tmp, &adev->shadow_list, shadow_list) {
V_337 = NULL ;
F_227 ( V_4 , V_326 , V_327 , & V_337 ) ;
if ( V_329 ) {
V_30 = F_243 ( V_329 , false ) ;
if ( V_30 ) {
F_244 ( V_30 , L_80 ) ;
break;
}
}
F_245 ( V_329 ) ;
V_329 = V_337 ;
}
F_246 ( & V_4 -> V_277 ) ;
if ( V_329 ) {
V_30 = F_243 ( V_329 , false ) ;
if ( V_30 )
F_244 ( V_30 , L_80 ) ;
}
F_245 ( V_329 ) ;
for ( V_44 = 0 ; V_44 < V_239 ; ++ V_44 ) {
struct V_325 * V_326 = V_4 -> V_342 [ V_44 ] ;
if ( ! V_326 || ! V_326 -> V_343 . V_344 )
continue;
F_247 ( & V_326 -> V_343 ) ;
F_248 ( V_326 -> V_343 . V_344 ) ;
}
F_218 ( V_4 -> V_100 ) ;
F_249 ( & V_4 -> V_230 . V_341 , V_336 ) ;
if ( V_30 ) {
F_70 ( V_4 -> V_2 , L_81 ) ;
}
V_4 -> V_263 . V_340 = false ;
F_246 ( & V_4 -> V_213 . V_338 ) ;
return V_30 ;
}
int F_250 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
int V_336 ;
bool V_345 ;
if ( F_75 ( V_4 ) )
return F_232 ( V_4 , true ) ;
if ( ! F_221 ( V_4 ) ) {
F_100 ( L_82 ) ;
return 0 ;
}
F_234 ( & V_4 -> V_339 ) ;
V_336 = F_235 ( & V_4 -> V_230 . V_341 ) ;
for ( V_44 = 0 ; V_44 < V_239 ; ++ V_44 ) {
struct V_325 * V_326 = V_4 -> V_342 [ V_44 ] ;
if ( ! V_326 || ! V_326 -> V_343 . V_344 )
continue;
F_236 ( V_326 -> V_343 . V_344 ) ;
F_237 ( & V_326 -> V_343 ) ;
}
F_238 ( V_4 ) ;
V_345 = F_223 ( V_4 ) ;
if ( ! V_345 ) {
F_222 ( V_4 ) ;
V_30 = F_224 ( V_4 ) ;
F_225 ( V_4 ) ;
if ( V_30 || F_221 ( V_4 ) ) {
F_100 ( L_83 ) ;
V_345 = true ;
}
}
if ( V_345 ) {
V_30 = F_149 ( V_4 ) ;
V_346:
if ( V_4 -> V_95 . V_164 ) {
struct V_347 V_348 ;
F_251 ( V_4 , & V_348 ) ;
F_125 ( V_4 , V_200 ) ;
}
if ( V_4 -> V_111 )
F_204 ( V_4 ) ;
else
F_205 ( V_4 ) ;
V_30 = F_209 ( V_4 ) ;
if ( V_4 -> V_111 )
F_215 ( V_4 ) ;
else
F_216 ( V_4 ) ;
F_169 ( V_4 -> V_95 . V_96 ) ;
if ( ! V_30 ) {
F_70 ( V_4 -> V_2 , L_84 ) ;
V_30 = F_152 ( V_4 ) ;
}
}
if ( ! V_30 ) {
F_241 ( V_4 ) ;
if ( V_345 && F_226 ( V_4 ) ) {
V_30 = F_240 ( V_4 ) ;
if ( V_30 )
F_20 ( L_85 ) ;
}
V_30 = F_177 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_61 , V_30 ) ;
V_30 = F_149 ( V_4 ) ;
V_345 = true ;
goto V_346;
}
if ( V_345 && F_226 ( V_4 ) ) {
struct V_325 * V_326 = V_4 -> V_230 . V_232 ;
struct V_304 * V_327 , * V_41 ;
struct V_328 * V_329 = NULL , * V_337 = NULL ;
F_100 ( L_79 ) ;
F_233 ( & V_4 -> V_277 ) ;
F_242 (bo, tmp, &adev->shadow_list, shadow_list) {
V_337 = NULL ;
F_227 ( V_4 , V_326 , V_327 , & V_337 ) ;
if ( V_329 ) {
V_30 = F_243 ( V_329 , false ) ;
if ( V_30 ) {
F_244 ( V_30 , L_80 ) ;
break;
}
}
F_245 ( V_329 ) ;
V_329 = V_337 ;
}
F_246 ( & V_4 -> V_277 ) ;
if ( V_329 ) {
V_30 = F_243 ( V_329 , false ) ;
if ( V_30 )
F_244 ( V_30 , L_80 ) ;
}
F_245 ( V_329 ) ;
}
for ( V_44 = 0 ; V_44 < V_239 ; ++ V_44 ) {
struct V_325 * V_326 = V_4 -> V_342 [ V_44 ] ;
if ( ! V_326 || ! V_326 -> V_343 . V_344 )
continue;
F_247 ( & V_326 -> V_343 ) ;
F_248 ( V_326 -> V_343 . V_344 ) ;
}
} else {
F_82 ( V_4 -> V_2 , L_86 , V_30 ) ;
for ( V_44 = 0 ; V_44 < V_239 ; ++ V_44 ) {
if ( V_4 -> V_342 [ V_44 ] && V_4 -> V_342 [ V_44 ] -> V_343 . V_344 ) {
F_248 ( V_4 -> V_342 [ V_44 ] -> V_343 . V_344 ) ;
}
}
}
F_218 ( V_4 -> V_100 ) ;
F_249 ( & V_4 -> V_230 . V_341 , V_336 ) ;
if ( V_30 ) {
F_70 ( V_4 -> V_2 , L_81 ) ;
}
return V_30 ;
}
void F_252 ( struct V_3 * V_4 )
{
T_2 V_349 ;
int V_10 ;
if ( V_350 )
V_4 -> V_82 . V_351 = V_350 ;
if ( V_352 )
V_4 -> V_82 . V_353 = V_352 ;
if ( F_253 ( V_4 -> V_19 -> V_354 ) ) {
if ( V_4 -> V_82 . V_351 == 0 )
V_4 -> V_82 . V_351 = V_355 ;
if ( V_4 -> V_82 . V_353 == 0 )
V_4 -> V_82 . V_353 = V_356 ;
return;
}
if ( V_4 -> V_82 . V_351 == 0 ) {
V_10 = F_254 ( V_4 -> V_100 , & V_349 ) ;
if ( ! V_10 ) {
V_4 -> V_82 . V_351 = ( V_357 |
V_358 |
V_359 ) ;
if ( V_349 & V_360 )
V_4 -> V_82 . V_351 |= V_361 ;
if ( V_349 & V_362 )
V_4 -> V_82 . V_351 |= V_363 ;
if ( V_349 & V_364 )
V_4 -> V_82 . V_351 |= V_365 ;
} else {
V_4 -> V_82 . V_351 = V_355 ;
}
}
if ( V_4 -> V_82 . V_353 == 0 ) {
V_10 = F_255 ( V_4 -> V_100 , & V_349 ) ;
if ( ! V_10 ) {
switch ( V_349 ) {
case 32 :
V_4 -> V_82 . V_353 = ( V_366 |
V_367 |
V_368 |
V_369 |
V_370 |
V_371 |
V_372 ) ;
break;
case 16 :
V_4 -> V_82 . V_353 = ( V_367 |
V_368 |
V_369 |
V_370 |
V_371 |
V_372 ) ;
break;
case 12 :
V_4 -> V_82 . V_353 = ( V_368 |
V_369 |
V_370 |
V_371 |
V_372 ) ;
break;
case 8 :
V_4 -> V_82 . V_353 = ( V_369 |
V_370 |
V_371 |
V_372 ) ;
break;
case 4 :
V_4 -> V_82 . V_353 = ( V_370 |
V_371 |
V_372 ) ;
break;
case 2 :
V_4 -> V_82 . V_353 = ( V_371 |
V_372 ) ;
break;
case 1 :
V_4 -> V_82 . V_353 = V_372 ;
break;
default:
break;
}
} else {
V_4 -> V_82 . V_353 = V_356 ;
}
}
}
int F_256 ( struct V_3 * V_4 ,
const struct V_373 * V_374 ,
unsigned V_375 )
{
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_376 ; V_44 ++ ) {
if ( V_4 -> V_377 [ V_44 ] . V_374 == V_374 ) {
return 0 ;
}
}
V_44 = V_4 -> V_376 + 1 ;
if ( V_44 > V_378 ) {
F_20 ( L_87 ) ;
F_20 ( L_88
L_89 ) ;
return - V_49 ;
}
V_4 -> V_377 [ V_4 -> V_376 ] . V_374 = V_374 ;
V_4 -> V_377 [ V_4 -> V_376 ] . V_379 = V_375 ;
V_4 -> V_376 = V_44 ;
#if F_257 ( V_380 )
F_258 ( V_374 , V_375 ,
V_4 -> V_100 -> V_302 -> V_381 ,
V_4 -> V_100 -> V_302 ) ;
#endif
return 0 ;
}
static T_7 F_259 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
bool V_388 , V_389 ;
unsigned V_390 , V_391 , V_392 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
V_388 = ( * V_385 >> 23 ) & 1 ;
if ( * V_385 & ( 1ULL << 62 ) ) {
V_392 = ( * V_385 >> 24 ) & 0x3FF ;
V_391 = ( * V_385 >> 34 ) & 0x3FF ;
V_390 = ( * V_385 >> 44 ) & 0x3FF ;
if ( V_392 == 0x3FF )
V_392 = 0xFFFFFFFF ;
if ( V_391 == 0x3FF )
V_391 = 0xFFFFFFFF ;
if ( V_390 == 0x3FF )
V_390 = 0xFFFFFFFF ;
V_389 = 1 ;
} else {
V_389 = 0 ;
}
* V_385 &= ( 1UL << 22 ) - 1 ;
if ( V_389 ) {
if ( ( V_391 != 0xFFFFFFFF && V_391 >= V_4 -> V_263 . V_393 . V_394 ) ||
( V_392 != 0xFFFFFFFF && V_392 >= V_4 -> V_263 . V_393 . V_395 ) )
return - V_49 ;
F_233 ( & V_4 -> V_266 ) ;
F_261 ( V_4 , V_392 ,
V_391 , V_390 ) ;
}
if ( V_388 )
F_233 ( & V_4 -> V_82 . V_110 ) ;
while ( V_47 ) {
T_1 V_396 ;
if ( * V_385 > V_4 -> V_12 )
goto V_397;
V_396 = F_44 ( * V_385 >> 2 ) ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 ) {
V_387 = V_30 ;
goto V_397;
}
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
V_397:
if ( V_389 ) {
F_261 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_246 ( & V_4 -> V_266 ) ;
}
if ( V_388 )
F_246 ( & V_4 -> V_82 . V_110 ) ;
return V_387 ;
}
static T_7 F_263 ( struct V_382 * V_383 , const char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
bool V_388 , V_389 ;
unsigned V_390 , V_391 , V_392 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
V_388 = ( * V_385 >> 23 ) & 1 ;
if ( * V_385 & ( 1ULL << 62 ) ) {
V_392 = ( * V_385 >> 24 ) & 0x3FF ;
V_391 = ( * V_385 >> 34 ) & 0x3FF ;
V_390 = ( * V_385 >> 44 ) & 0x3FF ;
if ( V_392 == 0x3FF )
V_392 = 0xFFFFFFFF ;
if ( V_391 == 0x3FF )
V_391 = 0xFFFFFFFF ;
if ( V_390 == 0x3FF )
V_390 = 0xFFFFFFFF ;
V_389 = 1 ;
} else {
V_389 = 0 ;
}
* V_385 &= ( 1UL << 22 ) - 1 ;
if ( V_389 ) {
if ( ( V_391 != 0xFFFFFFFF && V_391 >= V_4 -> V_263 . V_393 . V_394 ) ||
( V_392 != 0xFFFFFFFF && V_392 >= V_4 -> V_263 . V_393 . V_395 ) )
return - V_49 ;
F_233 ( & V_4 -> V_266 ) ;
F_261 ( V_4 , V_392 ,
V_391 , V_390 ) ;
}
if ( V_388 )
F_233 ( & V_4 -> V_82 . V_110 ) ;
while ( V_47 ) {
T_1 V_396 ;
if ( * V_385 > V_4 -> V_12 )
return V_387 ;
V_30 = F_264 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
F_45 ( * V_385 >> 2 , V_396 ) ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
if ( V_389 ) {
F_261 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_246 ( & V_4 -> V_266 ) ;
}
if ( V_388 )
F_246 ( & V_4 -> V_82 . V_110 ) ;
return V_387 ;
}
static T_7 F_265 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_396 ;
V_396 = F_266 ( * V_385 >> 2 ) ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_267 ( struct V_382 * V_383 , const char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_396 ;
V_30 = F_264 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
F_268 ( * V_385 >> 2 , V_396 ) ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_269 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_396 ;
V_396 = F_270 ( * V_385 >> 2 ) ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_271 ( struct V_382 * V_383 , const char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_396 ;
V_30 = F_264 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
F_272 ( * V_385 >> 2 , V_396 ) ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_273 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_396 ;
V_396 = F_274 ( * V_385 ) ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_275 ( struct V_382 * V_383 , const char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_396 ;
V_30 = F_264 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
F_276 ( * V_385 , V_396 ) ;
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_277 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
T_7 V_387 = 0 ;
int V_30 ;
T_1 * V_393 , V_398 = 0 ;
if ( V_47 & 0x3 || * V_385 & 0x3 )
return - V_49 ;
V_393 = F_278 ( 256 , sizeof( * V_393 ) , V_88 ) ;
if ( ! V_393 )
return - V_50 ;
V_393 [ V_398 ++ ] = 3 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_395 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_399 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_400 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_394 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_401 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_402 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_403 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_404 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_405 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_406 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_407 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_408 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_409 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_410 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_411 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_412 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_413 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_414 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_415 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_416 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_417 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_418 ;
V_393 [ V_398 ++ ] = V_4 -> V_263 . V_393 . V_419 ;
V_393 [ V_398 ++ ] = V_4 -> V_420 ;
V_393 [ V_398 ++ ] = V_4 -> V_196 ;
V_393 [ V_398 ++ ] = V_4 -> V_194 ;
V_393 [ V_398 ++ ] = V_4 -> V_173 ;
V_393 [ V_398 ++ ] = V_4 -> V_421 ;
V_393 [ V_398 ++ ] = V_4 -> V_19 -> V_20 ;
V_393 [ V_398 ++ ] = V_4 -> V_19 -> V_258 ;
V_393 [ V_398 ++ ] = V_4 -> V_19 -> V_257 ;
V_393 [ V_398 ++ ] = V_4 -> V_19 -> V_256 ;
while ( V_47 && ( * V_385 < V_398 * 4 ) ) {
T_1 V_396 ;
V_396 = V_393 [ * V_385 >> 2 ] ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 ) {
F_97 ( V_393 ) ;
return V_30 ;
}
V_387 += 4 ;
V_384 += 4 ;
* V_385 += 4 ;
V_47 -= 4 ;
}
F_97 ( V_393 ) ;
return V_387 ;
}
static T_7 F_279 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = F_260 ( V_383 ) -> V_386 ;
int V_422 , V_423 , V_424 , V_30 , V_425 ;
T_1 V_426 [ 16 ] ;
if ( V_47 & 3 || * V_385 & 0x3 )
return - V_49 ;
if ( V_427 == 0 )
return - V_49 ;
V_422 = * V_385 >> 2 ;
V_425 = sizeof( V_426 ) ;
if ( V_4 -> V_428 . V_429 && V_4 -> V_428 . V_429 -> V_430 )
V_30 = V_4 -> V_428 . V_429 -> V_430 ( V_4 -> V_428 . V_431 , V_422 , & V_426 [ 0 ] , & V_425 ) ;
else if ( V_4 -> V_82 . V_143 && V_4 -> V_82 . V_143 -> V_430 )
V_30 = V_4 -> V_82 . V_143 -> V_430 ( V_4 , V_422 , & V_426 [ 0 ] ,
& V_425 ) ;
else
return - V_49 ;
if ( V_47 > V_425 )
return - V_49 ;
V_424 = 0 ;
V_423 = 0 ;
if ( ! V_30 ) {
while ( V_47 ) {
V_30 = F_262 ( V_426 [ V_423 ++ ] , ( V_432 * ) V_384 ) ;
V_384 += 4 ;
V_47 -= 4 ;
V_424 += 4 ;
}
}
return ! V_30 ? V_424 : V_30 ;
}
static T_7 F_280 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = V_383 -> V_433 -> V_386 ;
int V_30 , V_423 ;
T_7 V_387 = 0 ;
T_1 V_60 , V_434 , V_435 , V_436 , V_437 , V_438 , V_84 [ 32 ] ;
if ( V_47 & 3 || * V_385 & 3 )
return - V_49 ;
V_60 = ( * V_385 & 0x7F ) ;
V_434 = ( ( * V_385 >> 7 ) & 0xFF ) ;
V_435 = ( ( * V_385 >> 15 ) & 0xFF ) ;
V_436 = ( ( * V_385 >> 23 ) & 0xFF ) ;
V_437 = ( ( * V_385 >> 31 ) & 0xFF ) ;
V_438 = ( ( * V_385 >> 37 ) & 0xFF ) ;
F_233 ( & V_4 -> V_266 ) ;
F_261 ( V_4 , V_434 , V_435 , V_436 ) ;
V_423 = 0 ;
if ( V_4 -> V_263 . V_143 -> V_439 )
V_4 -> V_263 . V_143 -> V_439 ( V_4 , V_438 , V_437 , V_84 , & V_423 ) ;
F_261 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_246 ( & V_4 -> V_266 ) ;
if ( ! V_423 )
return - V_49 ;
while ( V_47 && ( V_60 < V_423 * 4 ) ) {
T_1 V_396 ;
V_396 = V_84 [ V_60 >> 2 ] ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 )
return V_30 ;
V_387 += 4 ;
V_384 += 4 ;
V_60 += 4 ;
V_47 -= 4 ;
}
return V_387 ;
}
static T_7 F_281 ( struct V_382 * V_383 , char T_8 * V_384 ,
T_5 V_47 , T_9 * V_385 )
{
struct V_3 * V_4 = V_383 -> V_433 -> V_386 ;
int V_30 ;
T_7 V_387 = 0 ;
T_1 V_60 , V_434 , V_435 , V_436 , V_437 , V_438 , V_344 , V_440 , * V_84 ;
if ( V_47 & 3 || * V_385 & 3 )
return - V_49 ;
V_60 = ( * V_385 & 0xFFF ) ;
V_434 = ( ( * V_385 >> 12 ) & 0xFF ) ;
V_435 = ( ( * V_385 >> 20 ) & 0xFF ) ;
V_436 = ( ( * V_385 >> 28 ) & 0xFF ) ;
V_437 = ( ( * V_385 >> 36 ) & 0xFF ) ;
V_438 = ( ( * V_385 >> 44 ) & 0xFF ) ;
V_344 = ( ( * V_385 >> 52 ) & 0xFF ) ;
V_440 = ( ( * V_385 >> 60 ) & 1 ) ;
V_84 = F_278 ( 1024 , sizeof( * V_84 ) , V_88 ) ;
if ( ! V_84 )
return - V_50 ;
F_233 ( & V_4 -> V_266 ) ;
F_261 ( V_4 , V_434 , V_435 , V_436 ) ;
if ( V_440 == 0 ) {
if ( V_4 -> V_263 . V_143 -> V_441 )
V_4 -> V_263 . V_143 -> V_441 ( V_4 , V_438 , V_437 , V_344 , V_60 , V_47 >> 2 , V_84 ) ;
} else {
if ( V_4 -> V_263 . V_143 -> V_442 )
V_4 -> V_263 . V_143 -> V_442 ( V_4 , V_438 , V_437 , V_60 , V_47 >> 2 , V_84 ) ;
}
F_261 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_246 ( & V_4 -> V_266 ) ;
while ( V_47 ) {
T_1 V_396 ;
V_396 = V_84 [ V_60 ++ ] ;
V_30 = F_262 ( V_396 , ( T_1 * ) V_384 ) ;
if ( V_30 ) {
V_387 = V_30 ;
goto V_80;
}
V_387 += 4 ;
V_384 += 4 ;
V_47 -= 4 ;
}
V_80:
F_97 ( V_84 ) ;
return V_387 ;
}
static int F_180 ( struct V_3 * V_4 )
{
struct V_443 * V_153 = V_4 -> V_100 -> V_302 ;
struct V_444 * V_445 , * V_446 = V_153 -> V_381 ;
unsigned V_44 , V_447 ;
for ( V_44 = 0 ; V_44 < F_282 ( V_448 ) ; V_44 ++ ) {
V_445 = F_283 ( V_449 [ V_44 ] ,
V_450 | V_451 , V_446 ,
V_4 , V_448 [ V_44 ] ) ;
if ( F_284 ( V_445 ) ) {
for ( V_447 = 0 ; V_447 < V_44 ; V_447 ++ ) {
F_285 ( V_4 -> V_448 [ V_44 ] ) ;
V_4 -> V_448 [ V_44 ] = NULL ;
}
return F_286 ( V_445 ) ;
}
if ( ! V_44 )
F_287 ( V_445 -> V_452 , V_4 -> V_12 ) ;
V_4 -> V_448 [ V_44 ] = V_445 ;
}
return 0 ;
}
static void F_194 ( struct V_3 * V_4 )
{
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < F_282 ( V_448 ) ; V_44 ++ ) {
if ( V_4 -> V_448 [ V_44 ] ) {
F_285 ( V_4 -> V_448 [ V_44 ] ) ;
V_4 -> V_448 [ V_44 ] = NULL ;
}
}
}
int F_288 ( struct V_443 * V_153 )
{
return 0 ;
}
static int F_180 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_194 ( struct V_3 * V_4 ) { }
