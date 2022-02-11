static inline void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( ( V_1 << 16 ) | V_1 , V_2 ) ;
}
static inline T_1 F_3 ( void T_2 * V_2 )
{
return F_4 ( V_2 ) & 0x000000FFU ;
}
static void F_5 ( struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_8 ;
F_1 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_1 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_1 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_1 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
enum V_9 V_10 ) {
T_1 V_11 ;
T_1 V_12 ;
V_11 = F_3 ( V_4 -> V_6 + V_13 ) ;
if ( ! ( V_11 & V_14 ) )
return 0 ;
V_12 = F_3 ( V_4 -> V_6 + V_15 ) ;
F_6 ( V_4 ) ;
if ( V_12 & V_16 ) {
V_4 -> V_17 = V_18 ;
return 1 ;
} else if ( V_12 & V_19 ) {
V_4 -> V_17 = V_20 ;
return 1 ;
} else if ( V_12 & V_21 ) {
V_4 -> V_17 = V_22 ;
return 1 ;
}
switch ( V_10 ) {
case V_23 :
if ( V_11 & V_24 )
return 1 ;
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
if ( V_11 & V_29 ) {
return 1 ;
}
break;
case V_30 :
if ( V_12 & V_31 )
return 1 ;
break;
case V_32 :
if ( V_11 & V_33 )
return 1 ;
break;
case V_34 :
if ( V_12 & V_35 ) {
return 1 ;
}
break;
case V_36 :
if ( V_11 & V_37 )
return 1 ;
break;
default:
break;
}
V_4 -> V_17 = V_38 ;
F_8 ( & V_4 -> V_39 -> V_4 ,
L_1 ,
V_10 , V_11 , V_12 ) ;
return 0 ;
}
static T_3 F_9 ( int V_40 , void * V_41 )
{
struct V_3 * V_4 = V_41 ;
int V_42 ;
F_10 ( V_4 -> V_43 ) ;
F_11 ( & V_4 -> V_44 ) ;
V_42 = F_7 ( V_4 , V_4 -> V_45 ) ;
if ( V_42 || V_4 -> V_17 != V_46 )
F_12 ( & V_4 -> V_47 ) ;
F_13 ( & V_4 -> V_44 ) ;
F_14 ( V_4 -> V_43 ) ;
return V_48 ;
}
static int F_15 ( struct V_3 * V_4 ,
T_4 V_49 ,
enum V_9 V_10 )
{
int V_50 ;
if ( F_16 ( F_17 () ) ) {
F_18 ( 1 , L_2 ) ;
return - V_51 ;
}
F_19 ( & V_4 -> V_44 ) ;
F_20 ( & V_4 -> V_47 ) ;
V_4 -> V_17 = V_46 ;
V_4 -> V_45 = V_10 ;
F_21 ( & V_4 -> V_44 ) ;
V_49 |= V_8 ;
F_1 ( V_49 , V_4 -> V_6 + V_7 ) ;
V_50 = F_22 ( & V_4 -> V_47 ,
V_52 ) ;
if ( V_50 < 0 ) {
F_8 ( & V_4 -> V_39 -> V_4 ,
L_3
L_4 , V_50 , V_10 ) ;
return V_50 ;
}
if ( V_50 == 0 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_5
L_6 , V_10 ) ;
( void ) F_23 ( V_4 ) ;
return - V_53 ;
}
if ( V_4 -> V_17 != V_46 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_7
L_8 ,
V_4 -> V_17 , V_10 ) ;
( void ) F_23 ( V_4 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
enum V_9 V_10 )
{
int V_50 ;
if ( F_16 ( F_17 () ) ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_9
L_10 ) ;
return - V_51 ;
}
F_19 ( & V_4 -> V_44 ) ;
V_4 -> V_17 = V_46 ;
V_4 -> V_45 = V_10 ;
F_20 ( & V_4 -> V_47 ) ;
F_5 ( V_4 ) ;
F_21 ( & V_4 -> V_44 ) ;
V_50 = F_22 ( & V_4 -> V_47 ,
V_52 ) ;
if ( V_50 < 0 ) {
F_8 ( & V_4 -> V_39 -> V_4 ,
L_11
L_4 , V_50 , V_10 ) ;
return V_50 ;
}
if ( V_50 == 0 ) {
if ( V_10 != V_34 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_12
L_13
L_14 , V_10 ) ;
( void ) F_23 ( V_4 ) ;
}
return - V_53 ;
}
if ( V_4 -> V_17 != V_46 ) {
if ( V_10 != V_34 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_12
L_15
L_16 , V_4 -> V_17 , V_10 ) ;
( void ) F_23 ( V_4 ) ;
}
return - V_51 ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 )
{
unsigned long V_54 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_54 = V_57 + V_52 ;
while ( ! F_26 ( V_57 , V_54 ) ) {
if ( ( F_3 ( V_4 -> V_6 + V_13 ) &
V_58 ) == 0 )
return 0 ;
F_27 ( 1 ) ;
}
F_8 ( & V_4 -> V_39 -> V_4 , L_17
L_18
L_19 , V_55 + 1 ) ;
F_8 ( & V_4 -> V_39 -> V_4 , L_20
L_21 , ( T_1 ) V_4 -> V_6 ) ;
( void ) F_23 ( V_4 ) ;
}
F_8 ( & V_4 -> V_39 -> V_4 , L_22
L_23 , V_56 ) ;
return - V_53 ;
}
static int F_28 ( struct V_3 * V_4 , unsigned long V_59 )
{
T_1 V_5 ;
int V_55 = 0 ;
while ( V_55 < F_29 ( V_60 ) - 1 &&
V_60 [ V_55 ] . V_61 < V_59 )
V_55 ++ ;
if ( V_60 [ V_55 ] . V_62 == 0xFFU ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_24
L_25 , V_55 ? L_26 : L_27 , V_59 ) ;
return - V_63 ;
}
F_1 ( V_60 [ V_55 ] . V_62 ,
V_4 -> V_6 + V_64 ) ;
F_30 ( & V_4 -> V_39 -> V_4 , L_28
L_29 , V_59 , V_4 -> V_65 , V_4 -> V_6 ) ;
if ( V_4 -> V_65 > 100000 )
V_5 = ( ( V_59 / V_4 -> V_65 ) - 9 ) / 3 + 1 ;
else
V_5 = ( ( V_59 / V_4 -> V_65 ) - 7 ) / 2 + 1 ;
if ( V_5 < 0x002 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_30 ,
V_59 ) ;
return - V_63 ;
}
if ( V_5 & 0xFFFFF000U ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_31 ,
V_59 ) ;
return - V_63 ;
}
if ( V_4 -> V_65 > 100000 ) {
F_1 ( ( V_5 & V_66 ) | V_67 ,
V_4 -> V_6 + V_68 ) ;
F_30 ( & V_4 -> V_39 -> V_4 , L_32
L_33 , V_5 ) ;
} else {
F_1 ( ( V_5 & V_66 ) ,
V_4 -> V_6 + V_68 ) ;
F_30 ( & V_4 -> V_39 -> V_4 , L_34
L_35 , V_5 ) ;
}
F_1 ( ( ( V_5 >> 7 ) & 0x1F ) ,
V_4 -> V_6 + V_69 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 )
{
T_1 V_70 ;
unsigned long V_59 ;
int V_50 ;
F_1 ( 0x00 , V_4 -> V_6 + V_7 ) ;
F_1 ( 0x00 , V_4 -> V_6 + V_71 ) ;
V_59 = F_31 ( V_4 -> V_43 ) ;
V_50 = F_28 ( V_4 , V_59 ) ;
if ( V_50 )
return V_50 ;
F_1 ( V_72 ,
V_4 -> V_6 + V_7 ) ;
F_1 ( V_72 ,
V_4 -> V_6 + V_7 ) ;
V_70 = F_3 ( V_4 -> V_6 + V_15 ) ;
V_70 = F_3 ( V_4 -> V_6 + V_13 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_73 * V_74 , int V_75 )
{
T_1 V_5 ;
int V_50 ;
if ( V_74 -> V_76 & V_77 )
V_5 = ( 0xf0 | ( ( ( T_1 ) V_74 -> V_78 & 0x300 ) >> 7 ) ) &
V_79 ;
else
V_5 = ( ( V_74 -> V_78 << 1 ) & V_79 ) ;
if ( V_74 -> V_76 & V_80 ) {
V_5 |= 0x01 ;
if ( V_75 )
F_30 ( & V_4 -> V_39 -> V_4 , L_36 ) ;
} else if ( V_75 )
F_30 ( & V_4 -> V_39 -> V_4 , L_37 ) ;
F_1 ( V_5 , V_4 -> V_6 + V_81 ) ;
if ( V_74 -> V_76 & V_77 ) {
V_50 = F_24 ( V_4 , V_36 ) ;
V_5 = V_74 -> V_78 & V_79 ;
F_1 ( V_5 , V_4 -> V_6 + V_81 ) ;
if ( V_50 != 0 )
return V_50 ;
}
if ( V_75 )
F_30 ( & V_4 -> V_39 -> V_4 , L_38 ) ;
V_50 = F_24 ( V_4 , V_34 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_72 ;
F_1 ( V_5 , V_4 -> V_6 + V_7 ) ;
return V_50 ;
}
static int F_33 ( struct V_82 * V_83 ,
struct V_73 * V_74 , int V_84 )
{
T_1 V_85 ;
T_1 V_5 ;
T_1 V_55 ;
int V_50 ;
int V_86 = 0 ;
struct V_3 * V_4 = F_34 ( V_83 ) ;
F_10 ( V_4 -> V_43 ) ;
if ( 0 ) {
F_30 ( & V_4 -> V_39 -> V_4 , L_39
L_40 ,
V_74 -> V_78 , V_74 -> V_87 , V_74 -> V_76 , V_84 ) ;
}
if ( V_74 -> V_87 == 0 ) {
V_50 = - V_63 ;
goto V_88;
}
do {
if ( V_86 )
F_30 ( & V_4 -> V_39 -> V_4 , L_41 ) ;
V_50 = F_25 ( V_4 ) ;
if ( V_50 != 0 )
goto V_88;
if ( V_86 )
F_30 ( & V_4 -> V_39 -> V_4 , L_42 ) ;
V_50 = F_23 ( V_4 ) ;
if ( V_50 )
goto V_88;
V_85 = V_72 ;
if ( ! ( V_74 -> V_76 & V_89 ) )
V_85 |= V_90 ;
if ( ( V_74 -> V_76 & V_80 ) && ( V_74 -> V_87 > 1 ) )
V_85 |= V_91 ;
if ( ! ( V_74 -> V_76 & V_89 ) ) {
if ( V_86 )
F_30 ( & V_4 -> V_39 -> V_4 , L_43 ) ;
V_50 = F_15 ( V_4 , V_85 ,
V_32 ) ;
}
if ( V_86 )
F_30 ( & V_4 -> V_39 -> V_4 , L_44 ) ;
if ( V_50 == 0 )
V_50 = F_32 ( V_4 , V_74 , V_86 != 0 ) ;
if ( V_50 != 0 ) {
V_86 ++ ;
F_30 ( & V_4 -> V_39 -> V_4 , L_45
L_46 ,
V_86 , V_4 -> V_92 , V_4 -> V_93 ) ;
}
} while ( V_50 != 0 && V_86 < V_94 );
if ( V_86 < V_94 && V_86 > 0 ) {
F_30 ( & V_4 -> V_39 -> V_4 , L_47
L_48 , V_86 ) ;
} else if ( V_86 == V_94 ) {
F_30 ( & V_4 -> V_39 -> V_4 , L_49
L_50 ,
V_94 ) ;
goto V_88;
}
if ( V_74 -> V_76 & V_80 ) {
for ( V_55 = 0 ; V_55 < V_74 -> V_87 ; V_55 ++ ) {
if ( V_55 == V_74 -> V_87 - 1 ) {
V_5 = V_72 ;
if ( V_84 )
V_5 |= V_95 ;
F_1 ( V_5 ,
V_4 -> V_6 + V_7 ) ;
}
V_50 = F_24 ( V_4 , V_27 ) ;
if ( V_50 != 0 )
goto V_88;
V_74 -> V_96 [ V_55 ] = ( T_4 ) F_3 ( V_4 -> V_6 + V_81 ) ;
}
} else {
for ( V_55 = 0 ; V_55 < V_74 -> V_87 ; V_55 ++ ) {
F_1 ( V_74 -> V_96 [ V_55 ] ,
V_4 -> V_6 + V_81 ) ;
V_50 = F_24 ( V_4 , V_28 ) ;
if ( V_50 != 0 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_51
L_52 , V_50 ) ;
goto V_88;
}
}
if ( ! ( V_74 -> V_76 & V_97 ) ) {
if ( F_3 ( V_4 -> V_6 + V_15 ) &
V_16 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_53
L_54 ) ;
V_50 = - V_51 ;
goto V_88;
}
}
if ( V_84 ) {
V_5 = V_72 ;
V_5 |= V_95 ;
F_1 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
}
V_50 = F_25 ( V_4 ) ;
if ( V_50 != 0 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_55
L_56 ) ;
goto V_88;
}
V_5 = F_3 ( V_4 -> V_6 + V_15 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_13 ) ;
V_50 = 0 ;
V_88:
F_1 ( 0x00 , V_4 -> V_6 + V_7 ) ;
F_14 ( V_4 -> V_43 ) ;
return V_50 ;
}
static int F_35 ( struct V_82 * V_83 , struct V_73 * V_98 ,
int V_99 )
{
int V_50 = - 1 ;
int V_55 ;
struct V_3 * V_4 = F_34 ( V_83 ) ;
V_4 -> V_93 = V_99 ;
for ( V_55 = 0 ; V_55 < V_99 ; V_55 ++ ) {
V_4 -> V_92 = V_55 ;
V_50 = F_33 ( V_83 , & V_98 [ V_55 ] , ( V_55 == ( V_99 - 1 ) ) ) ;
if ( V_50 != 0 ) {
V_99 = V_50 ;
break;
}
}
return V_99 ;
}
static T_1 F_36 ( struct V_82 * V_83 )
{
return V_100 | V_101 ;
}
static int T_5
F_37 ( struct V_102 * V_39 )
{
struct V_3 * V_4 ;
struct V_82 * V_83 ;
struct V_103 * V_42 ;
int V_104 ;
int V_50 = 0 ;
char V_105 [] = L_57 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_106 ) ;
if ( ! V_4 ) {
F_8 ( & V_39 -> V_4 , L_58 ) ;
V_50 = - V_107 ;
goto V_108;
}
V_104 = V_39 -> V_109 ;
V_105 [ 3 ] += ( char ) V_104 ;
V_4 -> V_43 = F_39 ( & V_39 -> V_4 , V_105 ) ;
if ( F_40 ( V_4 -> V_43 ) ) {
V_50 = F_41 ( V_4 -> V_43 ) ;
F_8 ( & V_39 -> V_4 , L_59 ) ;
goto V_110;
}
V_4 -> V_39 = V_39 ;
F_42 ( V_39 , V_4 ) ;
V_42 = F_43 ( V_39 , V_111 , 0 ) ;
if ( ! V_42 ) {
V_50 = - V_112 ;
goto V_113;
}
V_4 -> V_114 = V_42 -> V_115 ;
V_4 -> V_116 = F_44 ( V_42 ) ;
if ( F_45 ( V_4 -> V_114 , V_4 -> V_116 ,
V_117 L_60 ) == NULL ) {
V_50 = - V_118 ;
goto V_119;
}
V_4 -> V_6 = F_46 ( V_4 -> V_114 , V_4 -> V_116 ) ;
F_30 ( & V_39 -> V_4 , L_61
L_62 , V_104 , V_4 -> V_6 ) ;
if ( ! V_4 -> V_6 ) {
V_50 = - V_107 ;
goto V_120;
}
V_4 -> V_40 = F_47 ( V_39 , 0 ) ;
if ( F_48 ( V_4 -> V_40 , F_9 , V_121 ,
V_117 , V_4 ) ) {
V_50 = - V_51 ;
goto V_122;
}
V_4 -> V_65 = V_123 ;
F_10 ( V_4 -> V_43 ) ;
V_50 = F_23 ( V_4 ) ;
F_14 ( V_4 -> V_43 ) ;
if ( V_50 != 0 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_63 ) ;
goto V_124;
}
F_49 ( & V_4 -> V_44 ) ;
V_4 -> V_45 = V_125 ;
V_4 -> V_17 = V_46 ;
V_83 = & V_4 -> V_126 ;
V_83 -> V_127 = V_128 ;
V_83 -> V_129 = V_130 ;
F_50 ( V_83 -> V_131 , L_64 ,
sizeof( V_83 -> V_131 ) ) ;
V_83 -> V_132 = V_104 ;
V_83 -> V_133 = & V_134 ;
V_83 -> V_4 . V_135 = & V_39 -> V_4 ;
F_51 ( V_83 , V_4 ) ;
V_50 = F_52 ( V_83 ) ;
if ( V_50 ) {
F_8 ( & V_4 -> V_39 -> V_4 , L_65
L_66 ) ;
goto V_136;
}
return 0 ;
V_136:
V_124:
F_53 ( V_4 -> V_40 , V_4 ) ;
V_122:
F_54 ( V_4 -> V_6 ) ;
V_120:
F_55 ( V_4 -> V_114 , V_4 -> V_116 ) ;
V_119:
F_42 ( V_39 , NULL ) ;
V_113:
F_56 ( V_4 -> V_43 ) ;
V_110:
F_57 ( V_4 ) ;
V_108:
F_8 ( & V_39 -> V_4 , L_67 V_117 L_68 ,
V_39 -> V_109 ) ;
return V_50 ;
}
static int F_58 ( struct V_102 * V_39 , T_6 V_137 )
{
struct V_3 * V_4 = F_59 ( V_39 ) ;
F_1 ( 0x00 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_102 * V_39 )
{
int V_50 = 0 ;
struct V_3 * V_4 = F_59 ( V_39 ) ;
F_10 ( V_4 -> V_43 ) ;
V_50 = F_23 ( V_4 ) ;
F_14 ( V_4 -> V_43 ) ;
if ( V_50 != 0 )
F_8 ( & V_39 -> V_4 , L_69 ) ;
return V_50 ;
}
static int T_7
F_61 ( struct V_102 * V_39 )
{
struct V_3 * V_4 = F_59 ( V_39 ) ;
F_62 ( & V_4 -> V_126 ) ;
F_1 ( 0x00 , V_4 -> V_6 + V_7 ) ;
F_53 ( V_4 -> V_40 , V_4 ) ;
F_54 ( V_4 -> V_6 ) ;
F_55 ( V_4 -> V_114 , V_4 -> V_116 ) ;
F_56 ( V_4 -> V_43 ) ;
F_42 ( V_39 , NULL ) ;
F_57 ( V_4 ) ;
return 0 ;
}
static int T_5 F_63 ( void )
{
return F_64 ( & V_138 , F_37 ) ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_138 ) ;
}
