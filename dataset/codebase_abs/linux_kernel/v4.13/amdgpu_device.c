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
if ( V_121 == - 1 )
return;
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
F_116 ( L_24 ) ;
V_2 -> V_129 = V_130 ;
F_117 ( V_2 , true , true ) ;
V_2 -> V_129 = V_131 ;
F_118 ( V_2 ) ;
} else {
F_116 ( L_25 ) ;
F_119 ( V_2 ) ;
V_2 -> V_129 = V_130 ;
F_120 ( V_2 , true , true ) ;
V_2 -> V_129 = V_132 ;
}
}
static bool F_121 ( struct V_125 * V_19 )
{
struct V_1 * V_2 = F_115 ( V_19 ) ;
return V_2 -> V_133 == 0 ;
}
int F_122 ( struct V_3 * V_4 ,
enum V_134 V_135 ,
enum V_136 V_113 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type != V_135 )
continue;
if ( ! V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_143 )
continue;
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_143 (
( void * ) V_4 , V_113 ) ;
if ( V_30 )
F_20 ( L_26 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
return V_30 ;
}
int F_123 ( struct V_3 * V_4 ,
enum V_134 V_135 ,
enum V_145 V_113 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type != V_135 )
continue;
if ( ! V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_146 )
continue;
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_146 (
( void * ) V_4 , V_113 ) ;
if ( V_30 )
F_20 ( L_27 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
return V_30 ;
}
void F_124 ( struct V_3 * V_4 , T_2 * V_6 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_147 )
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_147 ( ( void * ) V_4 , V_6 ) ;
}
}
int F_125 ( struct V_3 * V_4 ,
enum V_134 V_135 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_135 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_148 ( ( void * ) V_4 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
return 0 ;
}
bool F_126 ( struct V_3 * V_4 ,
enum V_134 V_135 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_135 )
return V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_149 ( ( void * ) V_4 ) ;
}
return true ;
}
struct V_150 * F_127 ( struct V_3 * V_4 ,
enum V_134 type )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ )
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == type )
return & V_4 -> V_138 [ V_44 ] ;
return NULL ;
}
int F_128 ( struct V_3 * V_4 ,
enum V_134 type ,
T_2 V_151 , T_2 V_152 )
{
struct V_150 * V_153 = F_127 ( V_4 , type ) ;
if ( V_153 && ( ( V_153 -> V_141 -> V_151 > V_151 ) ||
( ( V_153 -> V_141 -> V_151 == V_151 ) &&
( V_153 -> V_141 -> V_152 >= V_152 ) ) ) )
return 0 ;
return 1 ;
}
int F_129 ( struct V_3 * V_4 ,
const struct V_154 * V_155 )
{
if ( ! V_155 )
return - V_49 ;
F_130 ( L_28 , V_4 -> V_137 ,
V_155 -> V_142 -> V_144 ) ;
V_4 -> V_138 [ V_4 -> V_137 ++ ] . V_141 = V_155 ;
return 0 ;
}
static void F_131 ( struct V_3 * V_4 )
{
V_4 -> V_156 = false ;
if ( V_157 ) {
struct V_1 * V_100 = V_4 -> V_100 ;
const char * V_158 = F_132 ( V_100 -> V_19 ) ;
char * V_159 , * V_160 , * V_161 , * V_162 ;
V_159 = F_133 ( V_157 , V_88 ) ;
V_160 = V_159 ;
while ( ( V_161 = F_134 ( & V_160 , L_29 ) ) ) {
V_162 = F_134 ( & V_161 , L_30 ) ;
if ( ! strcmp ( L_31 , V_162 )
|| ! strcmp ( V_158 , V_162 ) ) {
long V_163 ;
int V_164 = - 1 ;
V_4 -> V_156 = true ;
if ( V_161 )
V_164 = F_135 ( V_161 , 10 ,
& V_163 ) ;
if ( ! V_164 ) {
if ( V_163 < 1 )
V_163 = 1 ;
if ( V_163 > 6 )
V_163 = 6 ;
V_4 -> V_95 . V_163 = V_163 ;
} else {
V_4 -> V_95 . V_163 = 1 ;
}
break;
}
}
F_100 ( L_32 ,
V_157 , V_158 ,
V_4 -> V_156 , V_4 -> V_95 . V_163 ) ;
F_97 ( V_159 ) ;
}
}
static int F_136 ( struct V_3 * V_4 )
{
const char * V_165 ;
char V_166 [ 30 ] ;
int V_80 ;
const struct V_167 * V_168 ;
V_4 -> V_169 . V_170 = NULL ;
switch ( V_4 -> V_78 ) {
case V_171 :
case V_172 :
case V_79 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
#ifdef F_137
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
#endif
#ifdef F_138
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
#endif
default:
return 0 ;
case V_188 :
V_165 = L_33 ;
break;
case V_189 :
V_165 = L_34 ;
break;
}
snprintf ( V_166 , sizeof( V_166 ) , L_35 , V_165 ) ;
V_80 = F_77 ( & V_4 -> V_169 . V_170 , V_166 , V_4 -> V_2 ) ;
if ( V_80 ) {
F_82 ( V_4 -> V_2 ,
L_36 ,
V_166 ) ;
goto V_190;
}
V_80 = F_139 ( V_4 -> V_169 . V_170 ) ;
if ( V_80 ) {
F_82 ( V_4 -> V_2 ,
L_37 ,
V_166 ) ;
goto V_190;
}
V_168 = ( const struct V_167 * ) V_4 -> V_169 . V_170 -> V_84 ;
F_140 ( & V_168 -> V_191 ) ;
switch ( V_168 -> V_192 ) {
case 1 :
{
const struct V_193 * V_170 =
( const struct V_193 * ) ( V_4 -> V_169 . V_170 -> V_84 +
F_141 ( V_168 -> V_191 . V_194 ) ) ;
V_4 -> V_195 . V_196 . V_197 = F_141 ( V_170 -> V_198 ) ;
V_4 -> V_195 . V_196 . V_199 = F_141 ( V_170 -> V_200 ) ;
V_4 -> V_195 . V_196 . V_201 = F_141 ( V_170 -> V_202 ) ;
V_4 -> V_195 . V_196 . V_203 = F_141 ( V_170 -> V_204 ) ;
V_4 -> V_195 . V_196 . V_205 =
F_141 ( V_170 -> V_206 ) ;
V_4 -> V_195 . V_196 . V_207 = F_141 ( V_170 -> V_208 ) ;
V_4 -> V_195 . V_196 . V_209 = F_141 ( V_170 -> V_210 ) ;
V_4 -> V_195 . V_196 . V_211 = F_141 ( V_170 -> V_212 ) ;
V_4 -> V_195 . V_196 . V_213 = F_141 ( V_170 -> V_214 ) ;
V_4 -> V_195 . V_196 . V_215 =
F_141 ( V_170 -> V_216 ) ;
V_4 -> V_195 . V_217 . V_218 = F_141 ( V_170 -> V_219 ) ;
V_4 -> V_195 . V_217 . V_220 =
F_141 ( V_170 -> V_221 ) ;
V_4 -> V_195 . V_217 . V_222 =
F_141 ( V_170 -> V_223 ) ;
V_4 -> V_195 . V_217 . V_224 = F_141 ( V_170 -> V_225 ) ;
break;
}
default:
F_82 ( V_4 -> V_2 ,
L_38 , V_168 -> V_191 . V_226 ) ;
V_80 = - V_49 ;
goto V_190;
}
V_190:
return V_80 ;
}
static int F_142 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
F_131 ( V_4 ) ;
switch ( V_4 -> V_78 ) {
case V_171 :
case V_172 :
case V_79 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
if ( V_4 -> V_78 == V_176 || V_4 -> V_78 == V_177 )
V_4 -> V_227 = V_228 ;
else
V_4 -> V_227 = V_229 ;
V_30 = F_143 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
#ifdef F_137
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
V_4 -> V_227 = V_230 ;
V_30 = F_144 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
#endif
#ifdef F_138
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
if ( ( V_4 -> V_78 == V_183 ) || ( V_4 -> V_78 == V_184 ) )
V_4 -> V_227 = V_231 ;
else
V_4 -> V_227 = V_232 ;
V_30 = F_145 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
#endif
case V_188 :
case V_189 :
if ( V_4 -> V_78 == V_189 )
V_4 -> V_227 = V_233 ;
else
V_4 -> V_227 = V_234 ;
V_30 = F_146 ( V_4 ) ;
if ( V_30 )
return V_30 ;
break;
default:
return - V_49 ;
}
V_30 = F_136 ( V_4 ) ;
if ( V_30 )
return V_30 ;
if ( F_75 ( V_4 ) ) {
V_30 = F_147 ( V_4 , true ) ;
if ( V_30 )
return V_30 ;
}
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ( V_235 & ( 1 << V_44 ) ) == 0 ) {
F_20 ( L_39 ,
V_44 , V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 ) ;
V_4 -> V_138 [ V_44 ] . V_139 . V_140 = false ;
} else {
if ( V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_236 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_236 ( ( void * ) V_4 ) ;
if ( V_30 == - V_237 ) {
V_4 -> V_138 [ V_44 ] . V_139 . V_140 = false ;
} else if ( V_30 ) {
F_20 ( L_40 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
} else {
V_4 -> V_138 [ V_44 ] . V_139 . V_140 = true ;
}
} else {
V_4 -> V_138 [ V_44 ] . V_139 . V_140 = true ;
}
}
}
V_4 -> V_238 &= V_239 ;
V_4 -> V_240 &= V_241 ;
return 0 ;
}
static int F_148 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_242 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_41 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_243 = true ;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_244 ) {
V_30 = F_31 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_42 , V_30 ) ;
return V_30 ;
}
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_245 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_43 , V_44 , V_30 ) ;
return V_30 ;
}
V_30 = F_58 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_44 , V_30 ) ;
return V_30 ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_246 = true ;
if ( F_75 ( V_4 ) ) {
V_30 = F_149 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_45 , V_30 ) ;
return V_30 ;
}
}
}
}
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_243 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_244 )
continue;
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_245 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_46 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_246 = true ;
}
return 0 ;
}
static void F_150 ( struct V_3 * V_4 )
{
memcpy ( V_4 -> V_247 , V_4 -> V_248 . V_27 , V_249 ) ;
}
static bool F_151 ( struct V_3 * V_4 )
{
return ! ! memcmp ( V_4 -> V_248 . V_27 , V_4 -> V_247 ,
V_249 ) ;
}
static int F_152 ( struct V_3 * V_4 )
{
int V_44 = 0 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type != V_250 &&
V_4 -> V_138 [ V_44 ] . V_141 -> type != V_251 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_143 ( ( void * ) V_4 ,
V_252 ) ;
if ( V_30 ) {
F_20 ( L_47 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
}
}
return 0 ;
}
static int F_153 ( struct V_3 * V_4 )
{
int V_44 = 0 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_253 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_253 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_20 ( L_48 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_254 = true ;
}
}
F_154 ( V_255 , & V_4 -> V_256 ,
F_155 ( V_257 ) ) ;
F_150 ( V_4 ) ;
return 0 ;
}
static int F_156 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_246 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_258 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_143 ( ( void * ) V_4 ,
V_259 ) ;
if ( V_30 ) {
F_20 ( L_49 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_260 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_130 ( L_50 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_246 = false ;
break;
}
}
for ( V_44 = V_4 -> V_137 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_246 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_244 ) {
F_56 ( V_4 ) ;
F_39 ( V_4 ) ;
}
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type != V_250 &&
V_4 -> V_138 [ V_44 ] . V_141 -> type != V_251 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_143 ( ( void * ) V_4 ,
V_259 ) ;
if ( V_30 ) {
F_20 ( L_49 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
}
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_260 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_130 ( L_50 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_246 = false ;
}
for ( V_44 = V_4 -> V_137 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_243 )
continue;
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_261 ( ( void * ) V_4 ) ;
if ( V_30 ) {
F_130 ( L_51 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
V_4 -> V_138 [ V_44 ] . V_139 . V_243 = false ;
V_4 -> V_138 [ V_44 ] . V_139 . V_140 = false ;
}
for ( V_44 = V_4 -> V_137 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_254 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_262 )
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_262 ( ( void * ) V_4 ) ;
V_4 -> V_138 [ V_44 ] . V_139 . V_254 = false ;
}
if ( F_75 ( V_4 ) ) {
F_57 ( & V_4 -> V_263 . V_264 , & V_4 -> V_263 . V_265 , NULL ) ;
F_157 ( V_4 , false ) ;
}
return 0 ;
}
static void F_158 ( struct V_266 * V_267 )
{
struct V_3 * V_4 =
F_159 ( V_267 , struct V_3 , V_256 . V_267 ) ;
F_152 ( V_4 ) ;
}
int F_160 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
if ( F_75 ( V_4 ) )
F_147 ( V_4 , false ) ;
V_30 = F_122 ( V_4 , V_258 ,
V_259 ) ;
if ( V_30 ) {
F_20 ( L_52 , V_30 ) ;
}
for ( V_44 = V_4 -> V_137 - 1 ; V_44 >= 0 ; V_44 -- ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_44 != V_258 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_143 ( ( void * ) V_4 ,
V_259 ) ;
if ( V_30 ) {
F_20 ( L_49 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
}
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_268 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_53 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
}
}
if ( F_75 ( V_4 ) )
F_157 ( V_4 , false ) ;
return 0 ;
}
static int F_161 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
static enum V_134 V_269 [] = {
V_244 ,
V_270 ,
V_271 ,
} ;
for ( V_44 = 0 ; V_44 < F_162 ( V_269 ) ; V_44 ++ ) {
int V_272 ;
struct V_150 * V_29 ;
for ( V_272 = 0 ; V_272 < V_4 -> V_137 ; V_272 ++ ) {
V_29 = & V_4 -> V_138 [ V_272 ] ;
if ( V_29 -> V_141 -> type != V_269 [ V_44 ] ||
! V_29 -> V_139 . V_140 )
continue;
V_30 = V_29 -> V_141 -> V_142 -> V_245 ( V_4 ) ;
F_100 ( L_54 , V_29 -> V_141 -> V_142 -> V_144 , V_30 ? L_55 : L_56 ) ;
}
}
return 0 ;
}
static int F_163 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
static enum V_134 V_269 [] = {
V_258 ,
V_273 ,
V_274 ,
V_275 ,
V_251 ,
} ;
for ( V_44 = 0 ; V_44 < F_162 ( V_269 ) ; V_44 ++ ) {
int V_272 ;
struct V_150 * V_29 ;
for ( V_272 = 0 ; V_272 < V_4 -> V_137 ; V_272 ++ ) {
V_29 = & V_4 -> V_138 [ V_272 ] ;
if ( V_29 -> V_141 -> type != V_269 [ V_44 ] ||
! V_29 -> V_139 . V_140 )
continue;
V_30 = V_29 -> V_141 -> V_142 -> V_245 ( V_4 ) ;
F_100 ( L_54 , V_29 -> V_141 -> V_142 -> V_144 , V_30 ? L_55 : L_56 ) ;
}
}
return 0 ;
}
static int F_164 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_270 ||
V_4 -> V_138 [ V_44 ] . V_141 -> type == V_244 ||
V_4 -> V_138 [ V_44 ] . V_141 -> type ==
V_271 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_276 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_57 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
}
}
return 0 ;
}
static int F_165 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_270 ||
V_4 -> V_138 [ V_44 ] . V_141 -> type == V_244 ||
V_4 -> V_138 [ V_44 ] . V_141 -> type == V_271 )
continue;
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_276 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_57 ,
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_166 ( struct V_3 * V_4 )
{
int V_30 ;
V_30 = F_164 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_165 ( V_4 ) ;
return V_30 ;
}
static void F_167 ( struct V_3 * V_4 )
{
if ( V_4 -> V_111 ) {
if ( F_168 ( V_4 ) )
V_4 -> V_263 . V_277 |= V_278 ;
} else {
if ( F_169 ( V_4 ) )
V_4 -> V_263 . V_277 |= V_278 ;
}
}
int F_170 ( struct V_3 * V_4 ,
struct V_1 * V_100 ,
struct V_125 * V_19 ,
T_1 V_6 )
{
int V_30 , V_44 ;
bool V_279 = false ;
T_2 V_280 ;
V_4 -> V_281 = false ;
V_4 -> V_2 = & V_19 -> V_2 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_78 = V_6 & V_282 ;
V_4 -> V_283 = V_284 ;
V_4 -> V_62 . V_74 = 512 * 1024 * 1024 ;
V_4 -> V_285 = false ;
V_4 -> V_286 = 0 ;
V_4 -> V_287 . V_288 = NULL ;
V_4 -> V_287 . V_289 = NULL ;
V_4 -> V_290 . V_291 = NULL ;
V_4 -> V_290 . V_292 = 0 ;
V_4 -> V_248 . V_293 = NULL ;
V_4 -> V_294 = F_171 ( V_295 ) ;
V_4 -> V_296 = & F_26 ;
V_4 -> V_297 = & F_28 ;
V_4 -> V_298 = & F_26 ;
V_4 -> V_299 = & F_28 ;
V_4 -> V_300 = & F_26 ;
V_4 -> V_301 = & F_28 ;
V_4 -> V_302 = & F_26 ;
V_4 -> V_303 = & F_28 ;
V_4 -> V_304 = & F_26 ;
V_4 -> V_305 = & F_28 ;
V_4 -> V_306 = & F_26 ;
V_4 -> V_307 = & F_28 ;
V_4 -> V_308 = & F_29 ;
V_4 -> V_309 = & F_30 ;
F_100 ( L_58 ,
V_310 [ V_4 -> V_78 ] , V_19 -> V_311 , V_19 -> V_20 ,
V_19 -> V_312 , V_19 -> V_313 , V_19 -> V_314 ) ;
F_172 ( & V_4 -> V_315 . V_316 . V_317 , 0 ) ;
F_102 ( & V_4 -> V_169 . V_110 ) ;
F_102 ( & V_4 -> V_82 . V_110 ) ;
F_102 ( & V_4 -> V_195 . V_318 ) ;
F_102 ( & V_4 -> V_319 ) ;
F_102 ( & V_4 -> V_320 ) ;
F_102 ( & V_4 -> V_321 ) ;
F_173 ( V_4 -> V_322 ) ;
F_112 ( V_4 ) ;
F_174 ( & V_4 -> V_16 ) ;
F_174 ( & V_4 -> V_323 ) ;
F_174 ( & V_4 -> V_324 ) ;
F_174 ( & V_4 -> V_325 ) ;
F_174 ( & V_4 -> V_326 ) ;
F_174 ( & V_4 -> V_327 ) ;
F_174 ( & V_4 -> V_328 ) ;
F_174 ( & V_4 -> V_329 . V_317 ) ;
F_175 ( & V_4 -> V_330 ) ;
F_102 ( & V_4 -> V_331 ) ;
F_175 ( & V_4 -> V_332 ) ;
F_174 ( & V_4 -> V_333 ) ;
F_175 ( & V_4 -> V_334 ) ;
F_174 ( & V_4 -> V_335 ) ;
F_176 ( & V_4 -> V_256 , F_158 ) ;
if ( V_4 -> V_78 >= V_183 ) {
V_4 -> V_336 = F_49 ( V_4 -> V_19 , 5 ) ;
V_4 -> V_12 = F_50 ( V_4 -> V_19 , 5 ) ;
} else {
V_4 -> V_336 = F_49 ( V_4 -> V_19 , 2 ) ;
V_4 -> V_12 = F_50 ( V_4 -> V_19 , 2 ) ;
}
V_4 -> V_15 = F_52 ( V_4 -> V_336 , V_4 -> V_12 ) ;
if ( V_4 -> V_15 == NULL ) {
return - V_50 ;
}
F_100 ( L_59 , ( T_1 ) V_4 -> V_336 ) ;
F_100 ( L_60 , ( unsigned ) V_4 -> V_12 ) ;
if ( V_4 -> V_78 >= V_183 )
F_48 ( V_4 ) ;
for ( V_44 = 0 ; V_44 < V_337 ; V_44 ++ ) {
if ( F_177 ( V_4 -> V_19 , V_44 ) & V_338 ) {
V_4 -> V_22 = F_50 ( V_4 -> V_19 , V_44 ) ;
V_4 -> V_23 = F_178 ( V_4 -> V_19 , V_44 , V_4 -> V_22 ) ;
break;
}
}
if ( V_4 -> V_23 == NULL )
F_100 ( L_61 ) ;
V_30 = F_142 ( V_4 ) ;
if ( V_30 )
return V_30 ;
F_179 ( V_4 -> V_19 , V_4 , NULL , F_107 ) ;
if ( V_339 == 1 )
V_279 = true ;
if ( F_1 ( V_100 ) )
V_279 = true ;
if ( ! F_180 ( V_4 -> V_19 ) )
F_181 ( V_4 -> V_19 ,
& V_340 , V_279 ) ;
if ( V_279 )
F_182 ( V_4 -> V_2 , & V_4 -> V_341 ) ;
if ( ! F_183 ( V_4 ) ) {
V_30 = - V_49 ;
goto V_342;
}
V_30 = F_98 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_62 ) ;
goto V_342;
}
F_167 ( V_4 ) ;
if ( F_74 ( V_4 ) ) {
if ( ! V_4 -> V_109 ) {
F_82 ( V_4 -> V_2 , L_63 ) ;
V_30 = - V_49 ;
goto V_342;
}
F_100 ( L_64 ) ;
V_30 = F_184 ( V_4 -> V_95 . V_96 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_65 ) ;
goto V_342;
}
} else {
F_100 ( L_66 ) ;
}
if ( ! V_4 -> V_111 ) {
V_30 = F_185 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_67 ) ;
return V_30 ;
}
F_186 ( V_4 ) ;
}
V_30 = F_187 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_68 ) ;
goto V_342;
}
F_188 ( V_4 -> V_100 ) ;
V_30 = F_148 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_69 ) ;
F_156 ( V_4 ) ;
goto V_342;
}
V_4 -> V_285 = true ;
F_189 ( V_4 ) ;
if ( V_343 >= 0 )
V_280 = V_343 ;
else
V_280 = 8 ;
V_4 -> V_329 . V_344 = F_190 ( F_191 ( 1u , V_280 ) ) ;
V_30 = F_192 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_70 , V_30 ) ;
goto V_342;
}
V_30 = F_193 ( V_4 ) ;
if ( V_30 )
F_20 ( L_71 , V_30 ) ;
F_194 ( V_4 ) ;
V_30 = F_195 ( V_4 ) ;
if ( V_30 )
F_20 ( L_72 , V_30 ) ;
V_30 = F_196 ( V_4 ) ;
if ( V_30 )
F_20 ( L_73 , V_30 ) ;
V_30 = F_197 ( V_4 ) ;
if ( V_30 )
F_20 ( L_74 , V_30 ) ;
V_30 = F_198 ( V_4 ) ;
if ( V_30 )
F_20 ( L_75 , V_30 ) ;
if ( ( V_345 & 1 ) ) {
if ( V_4 -> V_285 )
F_199 ( V_4 ) ;
else
F_100 ( L_76 ) ;
}
if ( V_346 ) {
if ( V_4 -> V_285 )
F_200 ( V_4 , V_346 ) ;
else
F_100 ( L_77 ) ;
}
V_30 = F_153 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_78 ) ;
goto V_342;
}
return 0 ;
V_342:
if ( V_279 )
F_201 ( V_4 -> V_2 ) ;
return V_30 ;
}
void F_202 ( struct V_3 * V_4 )
{
int V_30 ;
F_100 ( L_79 ) ;
V_4 -> V_281 = true ;
if ( V_4 -> V_95 . V_347 )
F_203 ( V_4 -> V_100 ) ;
F_204 ( V_4 ) ;
F_205 ( V_4 ) ;
F_206 ( V_4 ) ;
F_207 ( V_4 ) ;
V_30 = F_156 ( V_4 ) ;
if ( V_4 -> V_169 . V_170 ) {
F_208 ( V_4 -> V_169 . V_170 ) ;
V_4 -> V_169 . V_170 = NULL ;
}
V_4 -> V_285 = false ;
F_209 ( & V_4 -> V_256 ) ;
F_210 ( V_4 ) ;
F_96 ( V_4 ) ;
F_97 ( V_4 -> V_109 ) ;
V_4 -> V_109 = NULL ;
if ( ! F_180 ( V_4 -> V_19 ) )
F_211 ( V_4 -> V_19 ) ;
if ( V_4 -> V_6 & V_7 )
F_201 ( V_4 -> V_2 ) ;
F_179 ( V_4 -> V_19 , NULL , NULL , NULL ) ;
if ( V_4 -> V_23 )
F_212 ( V_4 -> V_19 , V_4 -> V_23 ) ;
V_4 -> V_23 = NULL ;
F_54 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
if ( V_4 -> V_78 >= V_183 )
F_53 ( V_4 ) ;
F_213 ( V_4 ) ;
}
int F_120 ( struct V_1 * V_2 , bool V_268 , bool V_348 )
{
struct V_3 * V_4 ;
struct V_349 * V_350 ;
struct V_351 * V_352 ;
int V_30 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL ) {
return - V_353 ;
}
V_4 = V_2 -> V_5 ;
if ( V_2 -> V_129 == V_132 )
return 0 ;
F_119 ( V_2 ) ;
F_214 ( V_2 ) ;
F_215 (connector, &dev->mode_config.connector_list, head) {
F_216 ( V_352 , V_354 ) ;
}
F_217 ( V_2 ) ;
F_215 (crtc, &dev->mode_config.crtc_list, head) {
struct V_355 * V_355 = F_218 ( V_350 ) ;
struct V_356 * V_357 = F_219 ( V_350 -> V_358 -> V_359 ) ;
struct V_360 * V_32 ;
if ( V_355 -> V_361 ) {
struct V_360 * V_362 = F_220 ( V_355 -> V_361 ) ;
V_30 = F_33 ( V_362 , true ) ;
if ( V_30 == 0 ) {
F_38 ( V_362 ) ;
F_36 ( V_362 ) ;
}
}
if ( V_357 == NULL || V_357 -> V_363 == NULL ) {
continue;
}
V_32 = F_220 ( V_357 -> V_363 ) ;
if ( ! F_221 ( V_4 , V_32 ) ) {
V_30 = F_33 ( V_32 , true ) ;
if ( V_30 == 0 ) {
F_38 ( V_32 ) ;
F_36 ( V_32 ) ;
}
}
}
F_204 ( V_4 ) ;
F_222 ( V_4 ) ;
V_30 = F_160 ( V_4 ) ;
F_204 ( V_4 ) ;
if ( V_4 -> V_111 )
F_223 ( V_4 ) ;
else
F_224 ( V_4 ) ;
F_225 ( V_2 -> V_19 ) ;
if ( V_268 ) {
F_226 ( V_2 -> V_19 ) ;
F_227 ( V_2 -> V_19 , V_364 ) ;
} else {
V_30 = F_228 ( V_4 ) ;
if ( V_30 )
F_20 ( L_80 ) ;
}
if ( V_348 ) {
F_229 () ;
F_230 ( V_4 , 1 ) ;
F_231 () ;
}
return 0 ;
}
int F_117 ( struct V_1 * V_2 , bool V_276 , bool V_348 )
{
struct V_351 * V_352 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_349 * V_350 ;
int V_30 = 0 ;
if ( V_2 -> V_129 == V_132 )
return 0 ;
if ( V_348 )
F_229 () ;
if ( V_276 ) {
F_227 ( V_2 -> V_19 , V_365 ) ;
F_232 ( V_2 -> V_19 ) ;
V_30 = F_233 ( V_2 -> V_19 ) ;
if ( V_30 )
goto V_366;
}
if ( V_4 -> V_111 )
F_234 ( V_4 ) ;
else
F_235 ( V_4 ) ;
if ( F_72 ( V_4 ) ) {
V_30 = F_184 ( V_4 -> V_95 . V_96 ) ;
if ( V_30 )
F_20 ( L_81 ) ;
}
V_30 = F_166 ( V_4 ) ;
if ( V_30 ) {
F_20 ( L_82 , V_30 ) ;
goto V_366;
}
F_236 ( V_4 ) ;
if ( V_276 ) {
V_30 = F_193 ( V_4 ) ;
if ( V_30 )
F_20 ( L_71 , V_30 ) ;
}
V_30 = F_153 ( V_4 ) ;
if ( V_30 )
goto V_366;
F_215 (crtc, &dev->mode_config.crtc_list, head) {
struct V_355 * V_355 = F_218 ( V_350 ) ;
if ( V_355 -> V_361 ) {
struct V_360 * V_362 = F_220 ( V_355 -> V_361 ) ;
V_30 = F_33 ( V_362 , true ) ;
if ( V_30 == 0 ) {
V_30 = F_35 ( V_362 ,
V_35 ,
& V_355 -> V_367 ) ;
if ( V_30 != 0 )
F_20 ( L_83 , V_30 ) ;
F_36 ( V_362 ) ;
}
}
}
if ( V_348 ) {
F_237 ( V_2 ) ;
F_214 ( V_2 ) ;
F_215 (connector, &dev->mode_config.connector_list, head) {
F_216 ( V_352 , V_368 ) ;
}
F_217 ( V_2 ) ;
}
F_118 ( V_2 ) ;
#ifdef F_238
V_2 -> V_2 -> V_369 . V_370 ++ ;
#endif
F_239 ( V_2 ) ;
#ifdef F_238
V_2 -> V_2 -> V_369 . V_370 -- ;
#endif
if ( V_348 )
F_230 ( V_4 , 0 ) ;
V_366:
if ( V_348 )
F_231 () ;
return V_30 ;
}
static bool F_240 ( struct V_3 * V_4 )
{
int V_44 ;
bool V_371 = false ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_372 )
V_4 -> V_138 [ V_44 ] . V_139 . V_373 =
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_372 ( V_4 ) ;
if ( V_4 -> V_138 [ V_44 ] . V_139 . V_373 ) {
F_100 ( L_84 , V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_144 ) ;
V_371 = true ;
}
}
return V_371 ;
}
static int F_241 ( struct V_3 * V_4 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_139 . V_373 &&
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_374 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_374 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static bool F_242 ( struct V_3 * V_4 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( ( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_244 ) ||
( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_258 ) ||
( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_375 ) ||
( V_4 -> V_138 [ V_44 ] . V_141 -> type == V_273 ) ) {
if ( V_4 -> V_138 [ V_44 ] . V_139 . V_373 ) {
F_100 ( L_85 ) ;
return true ;
}
}
}
return false ;
}
static int F_243 ( struct V_3 * V_4 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_139 . V_373 &&
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_376 ) {
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_376 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static int F_244 ( struct V_3 * V_4 )
{
int V_44 , V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_137 ; V_44 ++ ) {
if ( ! V_4 -> V_138 [ V_44 ] . V_139 . V_140 )
continue;
if ( V_4 -> V_138 [ V_44 ] . V_139 . V_373 &&
V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_377 )
V_30 = V_4 -> V_138 [ V_44 ] . V_141 -> V_142 -> V_377 ( V_4 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
bool F_245 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 & V_378 )
return false ;
return V_379 > 0 ? true : false ;
}
static int F_246 ( struct V_3 * V_4 ,
struct V_380 * V_381 ,
struct V_360 * V_382 ,
struct V_383 * * V_384 )
{
T_1 V_385 ;
int V_30 ;
if ( ! V_382 -> V_386 )
return 0 ;
V_30 = F_33 ( V_382 , true ) ;
if ( V_30 )
return V_30 ;
V_385 = F_247 ( V_382 -> V_387 . V_388 . V_389 ) ;
if ( V_385 == V_35 ) {
V_30 = F_248 ( V_382 -> V_386 ) ;
if ( V_30 ) {
F_20 ( L_86 ) ;
goto V_80;
}
V_30 = F_249 ( & V_382 -> V_386 -> V_387 , & V_382 -> V_386 -> V_387 . V_388 ) ;
if ( V_30 ) {
F_20 ( L_87 , V_382 -> V_386 ) ;
goto V_80;
}
V_30 = F_250 ( V_4 , V_381 , V_382 ,
NULL , V_384 , true ) ;
if ( V_30 ) {
F_20 ( L_88 ) ;
goto V_80;
}
}
V_80:
F_36 ( V_382 ) ;
return V_30 ;
}
int F_251 ( struct V_3 * V_4 , struct V_390 * V_391 )
{
int V_44 , V_272 , V_30 = 0 ;
int V_392 ;
struct V_360 * V_382 , * V_41 ;
struct V_380 * V_381 ;
struct V_383 * V_384 = NULL , * V_393 = NULL ;
F_252 ( & V_4 -> V_263 . V_394 ) ;
F_253 ( & V_4 -> V_395 ) ;
V_4 -> V_195 . V_396 = true ;
V_392 = F_254 ( & V_4 -> V_287 . V_397 ) ;
V_272 = V_391 ? V_391 -> V_381 -> V_398 : 0 ;
for ( V_44 = V_272 ; V_44 < V_272 + V_295 ; ++ V_44 ) {
V_381 = V_4 -> V_399 [ V_44 % V_295 ] ;
if ( ! V_381 || ! V_381 -> V_400 . V_401 )
continue;
F_255 ( V_381 -> V_400 . V_401 ) ;
if ( V_391 && V_272 != V_44 )
continue;
if ( V_391 && F_256 ( & V_391 -> V_46 . V_402 ) ) {
F_257 ( V_381 -> V_400 . V_401 ) ;
goto V_403;
}
if ( F_258 ( & V_391 -> V_46 , V_404 ) )
F_259 ( & V_391 -> V_46 ) ;
F_260 ( & V_381 -> V_400 ) ;
F_261 ( V_381 ) ;
}
if ( V_391 )
F_262 ( V_4 ) ;
else
F_147 ( V_4 , true ) ;
F_161 ( V_4 ) ;
F_263 ( V_4 ) ;
F_163 ( V_4 ) ;
F_264 ( V_4 ) ;
if ( F_193 ( V_4 ) )
F_82 ( V_4 -> V_2 , L_89 , V_30 ) ;
F_157 ( V_4 , true ) ;
F_100 ( L_90 ) ;
V_381 = V_4 -> V_287 . V_289 ;
F_252 ( & V_4 -> V_331 ) ;
F_265 (bo, tmp, &adev->shadow_list, shadow_list) {
V_393 = NULL ;
F_246 ( V_4 , V_381 , V_382 , & V_393 ) ;
if ( V_384 ) {
V_30 = F_266 ( V_384 , false ) ;
if ( V_30 ) {
F_267 ( V_30 , L_91 ) ;
break;
}
}
F_268 ( V_384 ) ;
V_384 = V_393 ;
}
F_269 ( & V_4 -> V_331 ) ;
if ( V_384 ) {
V_30 = F_266 ( V_384 , false ) ;
if ( V_30 )
F_267 ( V_30 , L_91 ) ;
}
F_268 ( V_384 ) ;
for ( V_44 = V_272 ; V_44 < V_272 + V_295 ; ++ V_44 ) {
V_381 = V_4 -> V_399 [ V_44 % V_295 ] ;
if ( ! V_381 || ! V_381 -> V_400 . V_401 )
continue;
if ( V_391 && V_272 != V_44 ) {
F_257 ( V_381 -> V_400 . V_401 ) ;
continue;
}
F_270 ( & V_381 -> V_400 ) ;
F_257 ( V_381 -> V_400 . V_401 ) ;
}
F_237 ( V_4 -> V_100 ) ;
V_403:
F_271 ( & V_4 -> V_287 . V_397 , V_392 ) ;
if ( V_30 ) {
F_70 ( V_4 -> V_2 , L_92 ) ;
} else {
F_70 ( V_4 -> V_2 , L_93 ) ;
}
V_4 -> V_195 . V_396 = false ;
F_269 ( & V_4 -> V_263 . V_394 ) ;
return V_30 ;
}
int F_272 ( struct V_3 * V_4 )
{
int V_44 , V_30 ;
int V_392 ;
bool V_405 , V_406 = false ;
if ( ! F_240 ( V_4 ) ) {
F_100 ( L_94 ) ;
return 0 ;
}
F_253 ( & V_4 -> V_395 ) ;
V_392 = F_254 ( & V_4 -> V_287 . V_397 ) ;
for ( V_44 = 0 ; V_44 < V_295 ; ++ V_44 ) {
struct V_380 * V_381 = V_4 -> V_399 [ V_44 ] ;
if ( ! V_381 || ! V_381 -> V_400 . V_401 )
continue;
F_255 ( V_381 -> V_400 . V_401 ) ;
F_260 ( & V_381 -> V_400 ) ;
}
F_273 ( V_4 ) ;
V_405 = F_242 ( V_4 ) ;
if ( ! V_405 ) {
F_241 ( V_4 ) ;
V_30 = F_243 ( V_4 ) ;
F_244 ( V_4 ) ;
if ( V_30 || F_240 ( V_4 ) ) {
F_100 ( L_95 ) ;
V_405 = true ;
}
}
if ( V_405 ) {
V_30 = F_160 ( V_4 ) ;
V_407:
if ( V_4 -> V_95 . V_163 ) {
struct V_408 V_409 ;
F_274 ( V_4 , & V_409 ) ;
F_125 ( V_4 , V_244 ) ;
}
if ( V_4 -> V_111 )
F_223 ( V_4 ) ;
else
F_224 ( V_4 ) ;
V_30 = F_228 ( V_4 ) ;
if ( V_4 -> V_111 )
F_234 ( V_4 ) ;
else
F_235 ( V_4 ) ;
F_184 ( V_4 -> V_95 . V_96 ) ;
if ( ! V_30 ) {
F_70 ( V_4 -> V_2 , L_96 ) ;
V_30 = F_164 ( V_4 ) ;
if ( V_30 )
goto V_190;
V_406 = F_151 ( V_4 ) ;
if ( V_406 ) {
F_20 ( L_97 ) ;
F_253 ( & V_4 -> V_410 ) ;
}
V_30 = F_263 ( V_4 ) ;
if ( V_30 )
goto V_190;
V_30 = F_165 ( V_4 ) ;
if ( V_30 )
goto V_190;
if ( V_406 )
F_150 ( V_4 ) ;
}
}
V_190:
if ( ! V_30 ) {
F_264 ( V_4 ) ;
V_30 = F_193 ( V_4 ) ;
if ( V_30 ) {
F_82 ( V_4 -> V_2 , L_71 , V_30 ) ;
V_30 = F_160 ( V_4 ) ;
V_405 = true ;
goto V_407;
}
if ( V_405 && F_245 ( V_4 ) ) {
struct V_380 * V_381 = V_4 -> V_287 . V_289 ;
struct V_360 * V_382 , * V_41 ;
struct V_383 * V_384 = NULL , * V_393 = NULL ;
F_100 ( L_90 ) ;
F_252 ( & V_4 -> V_331 ) ;
F_265 (bo, tmp, &adev->shadow_list, shadow_list) {
V_393 = NULL ;
F_246 ( V_4 , V_381 , V_382 , & V_393 ) ;
if ( V_384 ) {
V_30 = F_266 ( V_384 , false ) ;
if ( V_30 ) {
F_267 ( V_30 , L_91 ) ;
break;
}
}
F_268 ( V_384 ) ;
V_384 = V_393 ;
}
F_269 ( & V_4 -> V_331 ) ;
if ( V_384 ) {
V_30 = F_266 ( V_384 , false ) ;
if ( V_30 )
F_267 ( V_30 , L_91 ) ;
}
F_268 ( V_384 ) ;
}
for ( V_44 = 0 ; V_44 < V_295 ; ++ V_44 ) {
struct V_380 * V_381 = V_4 -> V_399 [ V_44 ] ;
if ( ! V_381 || ! V_381 -> V_400 . V_401 )
continue;
F_270 ( & V_381 -> V_400 ) ;
F_257 ( V_381 -> V_400 . V_401 ) ;
}
} else {
F_82 ( V_4 -> V_2 , L_98 , V_30 ) ;
for ( V_44 = 0 ; V_44 < V_295 ; ++ V_44 ) {
if ( V_4 -> V_399 [ V_44 ] && V_4 -> V_399 [ V_44 ] -> V_400 . V_401 ) {
F_257 ( V_4 -> V_399 [ V_44 ] -> V_400 . V_401 ) ;
}
}
}
F_237 ( V_4 -> V_100 ) ;
F_271 ( & V_4 -> V_287 . V_397 , V_392 ) ;
if ( V_30 )
F_70 ( V_4 -> V_2 , L_92 ) ;
else
F_70 ( V_4 -> V_2 , L_93 ) ;
return V_30 ;
}
void F_275 ( struct V_3 * V_4 )
{
T_2 V_411 ;
int V_10 ;
if ( V_412 )
V_4 -> V_82 . V_413 = V_412 ;
if ( V_414 )
V_4 -> V_82 . V_415 = V_414 ;
if ( F_276 ( V_4 -> V_19 -> V_416 ) ) {
if ( V_4 -> V_82 . V_413 == 0 )
V_4 -> V_82 . V_413 = V_417 ;
if ( V_4 -> V_82 . V_415 == 0 )
V_4 -> V_82 . V_415 = V_418 ;
return;
}
if ( V_4 -> V_82 . V_413 == 0 ) {
V_10 = F_277 ( V_4 -> V_100 , & V_411 ) ;
if ( ! V_10 ) {
V_4 -> V_82 . V_413 = ( V_419 |
V_420 |
V_421 ) ;
if ( V_411 & V_422 )
V_4 -> V_82 . V_413 |= V_423 ;
if ( V_411 & V_424 )
V_4 -> V_82 . V_413 |= V_425 ;
if ( V_411 & V_426 )
V_4 -> V_82 . V_413 |= V_427 ;
} else {
V_4 -> V_82 . V_413 = V_417 ;
}
}
if ( V_4 -> V_82 . V_415 == 0 ) {
V_10 = F_278 ( V_4 -> V_100 , & V_411 ) ;
if ( ! V_10 ) {
switch ( V_411 ) {
case 32 :
V_4 -> V_82 . V_415 = ( V_428 |
V_429 |
V_430 |
V_431 |
V_432 |
V_433 |
V_434 ) ;
break;
case 16 :
V_4 -> V_82 . V_415 = ( V_429 |
V_430 |
V_431 |
V_432 |
V_433 |
V_434 ) ;
break;
case 12 :
V_4 -> V_82 . V_415 = ( V_430 |
V_431 |
V_432 |
V_433 |
V_434 ) ;
break;
case 8 :
V_4 -> V_82 . V_415 = ( V_431 |
V_432 |
V_433 |
V_434 ) ;
break;
case 4 :
V_4 -> V_82 . V_415 = ( V_432 |
V_433 |
V_434 ) ;
break;
case 2 :
V_4 -> V_82 . V_415 = ( V_433 |
V_434 ) ;
break;
case 1 :
V_4 -> V_82 . V_415 = V_434 ;
break;
default:
break;
}
} else {
V_4 -> V_82 . V_415 = V_418 ;
}
}
}
int F_279 ( struct V_3 * V_4 ,
const struct V_435 * V_436 ,
unsigned V_437 )
{
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_438 ; V_44 ++ ) {
if ( V_4 -> V_439 [ V_44 ] . V_436 == V_436 ) {
return 0 ;
}
}
V_44 = V_4 -> V_438 + 1 ;
if ( V_44 > V_440 ) {
F_20 ( L_99 ) ;
F_20 ( L_100
L_101 ) ;
return - V_49 ;
}
V_4 -> V_439 [ V_4 -> V_438 ] . V_436 = V_436 ;
V_4 -> V_439 [ V_4 -> V_438 ] . V_441 = V_437 ;
V_4 -> V_438 = V_44 ;
#if F_280 ( V_442 )
F_281 ( V_436 , V_437 ,
V_4 -> V_100 -> V_358 -> V_443 ,
V_4 -> V_100 -> V_358 ) ;
#endif
return 0 ;
}
static T_7 F_282 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
bool V_450 , V_451 ;
unsigned V_452 , V_453 , V_454 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
V_450 = ( * V_447 >> 23 ) & 1 ;
if ( * V_447 & ( 1ULL << 62 ) ) {
V_454 = ( * V_447 >> 24 ) & 0x3FF ;
V_453 = ( * V_447 >> 34 ) & 0x3FF ;
V_452 = ( * V_447 >> 44 ) & 0x3FF ;
if ( V_454 == 0x3FF )
V_454 = 0xFFFFFFFF ;
if ( V_453 == 0x3FF )
V_453 = 0xFFFFFFFF ;
if ( V_452 == 0x3FF )
V_452 = 0xFFFFFFFF ;
V_451 = 1 ;
} else {
V_451 = 0 ;
}
* V_447 &= ( 1UL << 22 ) - 1 ;
if ( V_451 ) {
if ( ( V_453 != 0xFFFFFFFF && V_453 >= V_4 -> V_195 . V_196 . V_201 ) ||
( V_454 != 0xFFFFFFFF && V_454 >= V_4 -> V_195 . V_196 . V_197 ) )
return - V_49 ;
F_252 ( & V_4 -> V_320 ) ;
F_284 ( V_4 , V_454 ,
V_453 , V_452 ) ;
}
if ( V_450 )
F_252 ( & V_4 -> V_82 . V_110 ) ;
while ( V_47 ) {
T_1 V_455 ;
if ( * V_447 > V_4 -> V_12 )
goto V_456;
V_455 = F_44 ( * V_447 >> 2 ) ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 ) {
V_449 = V_30 ;
goto V_456;
}
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
V_456:
if ( V_451 ) {
F_284 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_269 ( & V_4 -> V_320 ) ;
}
if ( V_450 )
F_269 ( & V_4 -> V_82 . V_110 ) ;
return V_449 ;
}
static T_7 F_286 ( struct V_444 * V_445 , const char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
bool V_450 , V_451 ;
unsigned V_452 , V_453 , V_454 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
V_450 = ( * V_447 >> 23 ) & 1 ;
if ( * V_447 & ( 1ULL << 62 ) ) {
V_454 = ( * V_447 >> 24 ) & 0x3FF ;
V_453 = ( * V_447 >> 34 ) & 0x3FF ;
V_452 = ( * V_447 >> 44 ) & 0x3FF ;
if ( V_454 == 0x3FF )
V_454 = 0xFFFFFFFF ;
if ( V_453 == 0x3FF )
V_453 = 0xFFFFFFFF ;
if ( V_452 == 0x3FF )
V_452 = 0xFFFFFFFF ;
V_451 = 1 ;
} else {
V_451 = 0 ;
}
* V_447 &= ( 1UL << 22 ) - 1 ;
if ( V_451 ) {
if ( ( V_453 != 0xFFFFFFFF && V_453 >= V_4 -> V_195 . V_196 . V_201 ) ||
( V_454 != 0xFFFFFFFF && V_454 >= V_4 -> V_195 . V_196 . V_197 ) )
return - V_49 ;
F_252 ( & V_4 -> V_320 ) ;
F_284 ( V_4 , V_454 ,
V_453 , V_452 ) ;
}
if ( V_450 )
F_252 ( & V_4 -> V_82 . V_110 ) ;
while ( V_47 ) {
T_1 V_455 ;
if ( * V_447 > V_4 -> V_12 )
return V_449 ;
V_30 = F_287 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
F_45 ( * V_447 >> 2 , V_455 ) ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
if ( V_451 ) {
F_284 ( V_4 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_269 ( & V_4 -> V_320 ) ;
}
if ( V_450 )
F_269 ( & V_4 -> V_82 . V_110 ) ;
return V_449 ;
}
static T_7 F_288 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_455 ;
V_455 = F_289 ( * V_447 >> 2 ) ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_290 ( struct V_444 * V_445 , const char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_455 ;
V_30 = F_287 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
F_291 ( * V_447 >> 2 , V_455 ) ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_292 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_455 ;
V_455 = F_293 ( * V_447 >> 2 ) ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_294 ( struct V_444 * V_445 , const char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_455 ;
V_30 = F_287 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
F_295 ( * V_447 >> 2 , V_455 ) ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_296 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_455 ;
V_455 = F_297 ( * V_447 ) ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_298 ( struct V_444 * V_445 , const char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
while ( V_47 ) {
T_1 V_455 ;
V_30 = F_287 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
F_299 ( * V_447 , V_455 ) ;
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_300 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
T_7 V_449 = 0 ;
int V_30 ;
T_1 * V_196 , V_457 = 0 ;
if ( V_47 & 0x3 || * V_447 & 0x3 )
return - V_49 ;
V_196 = F_301 ( 256 , sizeof( * V_196 ) , V_88 ) ;
if ( ! V_196 )
return - V_50 ;
V_196 [ V_457 ++ ] = 3 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_197 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_458 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_199 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_201 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_203 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_205 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_207 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_209 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_459 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_460 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_461 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_462 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_463 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_464 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_465 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_466 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_467 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_468 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_469 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_470 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_471 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_472 ;
V_196 [ V_457 ++ ] = V_4 -> V_195 . V_196 . V_473 ;
V_196 [ V_457 ++ ] = V_4 -> V_474 ;
V_196 [ V_457 ++ ] = V_4 -> V_240 ;
V_196 [ V_457 ++ ] = V_4 -> V_238 ;
V_196 [ V_457 ++ ] = V_4 -> V_227 ;
V_196 [ V_457 ++ ] = V_4 -> V_475 ;
V_196 [ V_457 ++ ] = V_4 -> V_19 -> V_20 ;
V_196 [ V_457 ++ ] = V_4 -> V_19 -> V_314 ;
V_196 [ V_457 ++ ] = V_4 -> V_19 -> V_313 ;
V_196 [ V_457 ++ ] = V_4 -> V_19 -> V_312 ;
while ( V_47 && ( * V_447 < V_457 * 4 ) ) {
T_1 V_455 ;
V_455 = V_196 [ * V_447 >> 2 ] ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 ) {
F_97 ( V_196 ) ;
return V_30 ;
}
V_449 += 4 ;
V_446 += 4 ;
* V_447 += 4 ;
V_47 -= 4 ;
}
F_97 ( V_196 ) ;
return V_449 ;
}
static T_7 F_302 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = F_283 ( V_445 ) -> V_448 ;
int V_398 , V_476 , V_477 , V_30 , V_478 ;
T_1 V_479 [ 16 ] ;
if ( V_47 & 3 || * V_447 & 0x3 )
return - V_49 ;
if ( V_480 == 0 )
return - V_49 ;
V_398 = * V_447 >> 2 ;
V_478 = sizeof( V_479 ) ;
if ( V_4 -> V_481 . V_482 && V_4 -> V_481 . V_482 -> V_483 )
V_30 = V_4 -> V_481 . V_482 -> V_483 ( V_4 -> V_481 . V_484 , V_398 , & V_479 [ 0 ] , & V_478 ) ;
else if ( V_4 -> V_82 . V_142 && V_4 -> V_82 . V_142 -> V_483 )
V_30 = V_4 -> V_82 . V_142 -> V_483 ( V_4 , V_398 , & V_479 [ 0 ] ,
& V_478 ) ;
else
return - V_49 ;
if ( V_47 > V_478 )
return - V_49 ;
V_477 = 0 ;
V_476 = 0 ;
if ( ! V_30 ) {
while ( V_47 ) {
V_30 = F_285 ( V_479 [ V_476 ++ ] , ( V_485 * ) V_446 ) ;
V_446 += 4 ;
V_47 -= 4 ;
V_477 += 4 ;
}
}
return ! V_30 ? V_477 : V_30 ;
}
static T_7 F_303 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = V_445 -> V_486 -> V_448 ;
int V_30 , V_476 ;
T_7 V_449 = 0 ;
T_1 V_60 , V_487 , V_488 , V_489 , V_490 , V_491 , V_84 [ 32 ] ;
if ( V_47 & 3 || * V_447 & 3 )
return - V_49 ;
V_60 = ( * V_447 & 0x7F ) ;
V_487 = ( ( * V_447 >> 7 ) & 0xFF ) ;
V_488 = ( ( * V_447 >> 15 ) & 0xFF ) ;
V_489 = ( ( * V_447 >> 23 ) & 0xFF ) ;
V_490 = ( ( * V_447 >> 31 ) & 0xFF ) ;
V_491 = ( ( * V_447 >> 37 ) & 0xFF ) ;
F_252 ( & V_4 -> V_320 ) ;
F_284 ( V_4 , V_487 , V_488 , V_489 ) ;
V_476 = 0 ;
if ( V_4 -> V_195 . V_142 -> V_492 )
V_4 -> V_195 . V_142 -> V_492 ( V_4 , V_491 , V_490 , V_84 , & V_476 ) ;
F_284 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_269 ( & V_4 -> V_320 ) ;
if ( ! V_476 )
return - V_49 ;
while ( V_47 && ( V_60 < V_476 * 4 ) ) {
T_1 V_455 ;
V_455 = V_84 [ V_60 >> 2 ] ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 )
return V_30 ;
V_449 += 4 ;
V_446 += 4 ;
V_60 += 4 ;
V_47 -= 4 ;
}
return V_449 ;
}
static T_7 F_304 ( struct V_444 * V_445 , char T_8 * V_446 ,
T_5 V_47 , T_9 * V_447 )
{
struct V_3 * V_4 = V_445 -> V_486 -> V_448 ;
int V_30 ;
T_7 V_449 = 0 ;
T_1 V_60 , V_487 , V_488 , V_489 , V_490 , V_491 , V_401 , V_493 , * V_84 ;
if ( V_47 & 3 || * V_447 & 3 )
return - V_49 ;
V_60 = ( * V_447 & 0xFFF ) ;
V_487 = ( ( * V_447 >> 12 ) & 0xFF ) ;
V_488 = ( ( * V_447 >> 20 ) & 0xFF ) ;
V_489 = ( ( * V_447 >> 28 ) & 0xFF ) ;
V_490 = ( ( * V_447 >> 36 ) & 0xFF ) ;
V_491 = ( ( * V_447 >> 44 ) & 0xFF ) ;
V_401 = ( ( * V_447 >> 52 ) & 0xFF ) ;
V_493 = ( ( * V_447 >> 60 ) & 1 ) ;
V_84 = F_301 ( 1024 , sizeof( * V_84 ) , V_88 ) ;
if ( ! V_84 )
return - V_50 ;
F_252 ( & V_4 -> V_320 ) ;
F_284 ( V_4 , V_487 , V_488 , V_489 ) ;
if ( V_493 == 0 ) {
if ( V_4 -> V_195 . V_142 -> V_494 )
V_4 -> V_195 . V_142 -> V_494 ( V_4 , V_491 , V_490 , V_401 , V_60 , V_47 >> 2 , V_84 ) ;
} else {
if ( V_4 -> V_195 . V_142 -> V_495 )
V_4 -> V_195 . V_142 -> V_495 ( V_4 , V_491 , V_490 , V_60 , V_47 >> 2 , V_84 ) ;
}
F_284 ( V_4 , 0xFFFFFFFF , 0xFFFFFFFF , 0xFFFFFFFF ) ;
F_269 ( & V_4 -> V_320 ) ;
while ( V_47 ) {
T_1 V_455 ;
V_455 = V_84 [ V_60 ++ ] ;
V_30 = F_285 ( V_455 , ( T_1 * ) V_446 ) ;
if ( V_30 ) {
V_449 = V_30 ;
goto V_80;
}
V_449 += 4 ;
V_446 += 4 ;
V_47 -= 4 ;
}
V_80:
F_97 ( V_84 ) ;
return V_449 ;
}
static int F_196 ( struct V_3 * V_4 )
{
struct V_496 * V_152 = V_4 -> V_100 -> V_358 ;
struct V_497 * V_498 , * V_499 = V_152 -> V_443 ;
unsigned V_44 , V_272 ;
for ( V_44 = 0 ; V_44 < F_162 ( V_500 ) ; V_44 ++ ) {
V_498 = F_305 ( V_501 [ V_44 ] ,
V_502 | V_503 , V_499 ,
V_4 , V_500 [ V_44 ] ) ;
if ( F_306 ( V_498 ) ) {
for ( V_272 = 0 ; V_272 < V_44 ; V_272 ++ ) {
F_307 ( V_4 -> V_500 [ V_44 ] ) ;
V_4 -> V_500 [ V_44 ] = NULL ;
}
return F_308 ( V_498 ) ;
}
if ( ! V_44 )
F_309 ( V_498 -> V_504 , V_4 -> V_12 ) ;
V_4 -> V_500 [ V_44 ] = V_498 ;
}
return 0 ;
}
static void F_213 ( struct V_3 * V_4 )
{
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < F_162 ( V_500 ) ; V_44 ++ ) {
if ( V_4 -> V_500 [ V_44 ] ) {
F_307 ( V_4 -> V_500 [ V_44 ] ) ;
V_4 -> V_500 [ V_44 ] = NULL ;
}
}
}
static int F_310 ( struct V_505 * V_506 , void * V_84 )
{
struct V_507 * V_402 = (struct V_507 * ) V_506 -> V_508 ;
struct V_1 * V_2 = V_402 -> V_152 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_30 = 0 , V_44 ;
for ( V_44 = 0 ; V_44 < V_295 ; V_44 ++ ) {
struct V_380 * V_381 = V_4 -> V_399 [ V_44 ] ;
if ( ! V_381 || ! V_381 -> V_400 . V_401 )
continue;
F_255 ( V_381 -> V_400 . V_401 ) ;
}
F_311 ( V_506 , L_102 ) ;
V_30 = F_193 ( V_4 ) ;
if ( V_30 )
F_311 ( V_506 , L_103 , V_30 ) ;
else
F_311 ( V_506 , L_104 ) ;
for ( V_44 = 0 ; V_44 < V_295 ; V_44 ++ ) {
struct V_380 * V_381 = V_4 -> V_399 [ V_44 ] ;
if ( ! V_381 || ! V_381 -> V_400 . V_401 )
continue;
F_257 ( V_381 -> V_400 . V_401 ) ;
}
return 0 ;
}
static int F_197 ( struct V_3 * V_4 )
{
return F_279 ( V_4 ,
V_509 , 1 ) ;
}
int F_312 ( struct V_496 * V_152 )
{
return 0 ;
}
static int F_197 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_196 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_213 ( struct V_3 * V_4 ) { }
