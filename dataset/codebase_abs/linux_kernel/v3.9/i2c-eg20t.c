static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_2 ) ;
V_4 |= V_3 ;
F_3 ( V_4 , V_1 + V_2 ) ;
}
static inline void F_4 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_2 ) ;
V_4 &= ( ~ V_3 ) ;
F_3 ( V_4 , V_1 + V_2 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
T_2 V_9 ;
T_2 V_10 ;
T_2 V_11 ;
F_3 ( 0x01 , V_7 + V_12 ) ;
F_6 ( 20 ) ;
F_3 ( 0x0 , V_7 + V_12 ) ;
F_3 ( 0x21 , V_7 + V_13 ) ;
F_1 ( V_6 -> V_8 , V_14 , V_15 ) ;
if ( V_16 != 400 )
V_16 = 100 ;
V_11 = V_15 ;
if ( V_16 == V_17 ) {
V_11 |= V_18 ;
F_7 ( V_6 , L_1 ) ;
}
if ( V_19 > V_20 )
V_19 = 62500 ;
V_9 = ( V_19 + ( V_16 * 4 ) ) / ( V_16 * 8 ) ;
F_3 ( V_9 , V_7 + V_21 ) ;
V_10 = ( V_19 ) / 8 ;
F_3 ( V_10 , V_7 + V_22 ) ;
V_11 |= V_23 ;
F_3 ( V_11 , V_7 + V_14 ) ;
F_7 ( V_6 ,
L_2 ,
F_2 ( V_7 + V_14 ) , V_9 , V_10 ) ;
F_8 ( & V_24 ) ;
}
static T_3 F_9 ( struct V_5 * V_6 ,
T_3 V_25 )
{
void T_1 * V_7 = V_6 -> V_8 ;
int V_26 = 0 ;
unsigned long V_27 = V_28 + F_10 ( V_25 ) ;
while ( F_2 ( V_7 + V_29 ) & V_30 ) {
if ( F_11 ( V_28 , V_27 ) ) {
F_7 ( V_6 , L_3 , F_2 ( V_7 + V_29 ) ) ;
F_12 ( V_6 , L_4 ,
V_31 , - V_32 ) ;
F_5 ( V_6 ) ;
return - V_32 ;
}
if ( ! V_26 )
F_13 ( 5 ) ;
else
F_14 ( 20 , 1000 ) ;
V_26 = 1 ;
}
return 0 ;
}
static void F_15 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_33 ) ;
}
static T_3 F_16 ( struct V_5 * V_6 )
{
T_2 V_34 ;
void T_1 * V_7 = V_6 -> V_8 ;
V_34 = F_2 ( V_7 + V_29 ) & V_35 ;
if ( V_34 != 0 ) {
F_12 ( V_6 , L_6 , - V_36 ) ;
return - V_36 ;
}
return 0 ;
}
static void F_17 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_4 ( V_6 -> V_8 , V_14 , V_33 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
long V_37 ;
V_37 = F_19 ( V_24 ,
( V_6 -> V_38 != 0 ) , F_10 ( 1000 ) ) ;
if ( ! V_37 ) {
F_12 ( V_6 , L_7 , V_31 ) ;
V_6 -> V_38 = 0 ;
F_17 ( V_6 ) ;
F_5 ( V_6 ) ;
return - V_39 ;
}
if ( V_6 -> V_38 & V_40 ) {
F_12 ( V_6 , L_8 ) ;
V_6 -> V_38 = 0 ;
F_4 ( V_6 -> V_8 , V_29 , V_41 ) ;
F_4 ( V_6 -> V_8 , V_29 , V_42 ) ;
F_5 ( V_6 ) ;
return - V_43 ;
}
V_6 -> V_38 = 0 ;
if ( F_16 ( V_6 ) ) {
F_7 ( V_6 , L_9
L_10 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_45 ) ;
}
static T_3 F_21 ( struct V_46 * V_47 ,
struct V_48 * V_49 , T_2 V_50 , T_2 V_51 )
{
struct V_5 * V_6 = V_47 -> V_52 ;
T_4 * V_53 ;
T_2 V_54 ;
T_2 V_1 ;
T_2 V_55 ;
T_2 V_56 ;
T_3 V_57 ;
T_3 V_58 ;
void T_1 * V_7 = V_6 -> V_8 ;
V_54 = V_49 -> V_59 ;
V_53 = V_49 -> V_53 ;
V_1 = V_49 -> V_1 ;
F_1 ( V_6 -> V_8 , V_14 , V_60 ) ;
F_7 ( V_6 , L_11 , F_2 ( V_7 + V_14 ) ,
V_54 ) ;
if ( V_51 ) {
if ( F_9 ( V_6 , V_61 ) == - V_32 )
return - V_32 ;
}
if ( V_49 -> V_62 & V_63 ) {
V_55 = ( ( V_1 & V_64 ) >> 7 ) & 0x06 ;
F_3 ( V_55 | V_65 , V_7 + V_66 ) ;
if ( V_51 )
F_15 ( V_6 ) ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
V_56 = ( V_1 & V_67 ) ;
F_3 ( V_56 , V_7 + V_66 ) ;
} else {
F_3 ( V_1 << 1 , V_7 + V_66 ) ;
if ( V_51 )
F_15 ( V_6 ) ;
}
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
for ( V_57 = 0 ; V_57 < V_54 ; ++ V_57 ) {
F_3 ( V_53 [ V_57 ] , V_7 + V_66 ) ;
F_7 ( V_6 , L_12 , V_53 [ V_57 ] ) ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_6 -> V_8 , V_29 , V_68 ) ;
F_4 ( V_6 -> V_8 , V_29 , V_42 ) ;
}
if ( V_50 )
F_17 ( V_6 ) ;
else
F_20 ( V_6 ) ;
F_7 ( V_6 , L_13 , V_57 ) ;
return V_57 ;
}
static void F_22 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_4 ( V_6 -> V_8 , V_14 , V_69 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_69 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_70 ) ;
}
static T_3 F_25 ( struct V_46 * V_47 , struct V_48 * V_49 ,
T_2 V_50 , T_2 V_51 )
{
struct V_5 * V_6 = V_47 -> V_52 ;
T_4 * V_53 ;
T_2 V_71 ;
T_2 V_54 ;
T_2 V_1 ;
T_2 V_55 ;
T_2 V_56 ;
void T_1 * V_7 = V_6 -> V_8 ;
T_3 V_58 ;
V_54 = V_49 -> V_59 ;
V_53 = V_49 -> V_53 ;
V_1 = V_49 -> V_1 ;
F_4 ( V_6 -> V_8 , V_14 , V_60 ) ;
if ( V_51 ) {
if ( F_9 ( V_6 , V_61 ) == - V_32 )
return - V_32 ;
}
if ( V_49 -> V_62 & V_63 ) {
V_55 = ( ( V_1 & V_64 ) >> 7 ) ;
F_3 ( V_55 | V_65 , V_7 + V_66 ) ;
if ( V_51 )
F_15 ( V_6 ) ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
V_56 = ( V_1 & V_67 ) ;
F_3 ( V_56 , V_7 + V_66 ) ;
F_24 ( V_6 ) ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
V_55 |= V_72 ;
F_3 ( V_55 | V_65 , V_7 + V_66 ) ;
} else {
V_1 = ( ( ( V_1 ) << 1 ) | ( V_72 ) ) ;
F_3 ( V_1 , V_7 + V_66 ) ;
}
if ( V_51 )
F_15 ( V_6 ) ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
if ( V_54 == 0 ) {
F_17 ( V_6 ) ;
F_2 ( V_7 + V_66 ) ;
V_71 = V_54 ;
} else {
int V_73 ;
int V_74 ;
F_22 ( V_6 ) ;
for ( V_74 = 1 , V_73 = 0 ; V_74 < V_54 ; V_74 ++ ) {
V_53 [ V_73 ] = F_2 ( V_7 + V_66 ) ;
if ( V_74 != 1 )
V_73 ++ ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
}
F_23 ( V_6 ) ;
V_53 [ V_73 ] = F_2 ( V_7 + V_66 ) ;
if ( V_54 != 1 )
V_73 ++ ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 )
return V_58 ;
if ( V_50 )
F_17 ( V_6 ) ;
else
F_20 ( V_6 ) ;
V_53 [ V_73 ++ ] = F_2 ( V_7 + V_66 ) ;
V_71 = V_73 ;
}
return V_71 ;
}
static void F_26 ( struct V_5 * V_6 )
{
T_2 V_75 ;
void T_1 * V_7 = V_6 -> V_8 ;
V_75 = F_2 ( V_7 + V_29 ) ;
V_75 &= ( V_41 | V_68 | V_42 ) ;
if ( V_75 & V_41 )
V_6 -> V_38 |= V_76 ;
if ( V_75 & V_68 )
V_6 -> V_38 |= V_77 ;
F_4 ( V_6 -> V_8 , V_29 , V_75 ) ;
F_7 ( V_6 , L_14 , F_2 ( V_7 + V_29 ) ) ;
F_27 ( & V_24 ) ;
}
static T_5 F_28 ( int V_78 , void * V_79 )
{
T_2 V_34 ;
int V_80 ;
int V_81 ;
struct V_82 * V_83 = V_79 ;
void T_1 * V_7 ;
T_2 V_84 ;
for ( V_81 = 0 , V_80 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ ) {
V_7 = V_83 -> V_86 [ V_81 ] . V_8 ;
V_84 = F_2 ( V_7 + V_87 ) ;
V_84 &= V_88 | V_89 ;
if ( V_84 != V_90 ) {
F_12 ( V_83 -> V_86 ,
L_15 , V_84 , V_81 ) ;
continue;
}
V_34 = F_2 ( V_7 + V_29 ) ;
if ( V_34 & ( V_41 | V_68 | V_42 ) ) {
F_26 ( & V_83 -> V_86 [ V_81 ] ) ;
V_80 = 1 ;
}
}
return V_80 ? V_91 : V_92 ;
}
static T_3 F_29 ( struct V_46 * V_47 ,
struct V_48 * V_49 , T_3 V_93 )
{
struct V_48 * V_94 ;
T_2 V_81 = 0 ;
T_2 V_95 ;
T_3 V_37 ;
struct V_5 * V_6 = V_47 -> V_52 ;
V_37 = F_30 ( & V_96 ) ;
if ( V_37 )
return V_37 ;
if ( V_6 -> V_97 -> V_98 ) {
F_31 ( & V_96 ) ;
return - V_99 ;
}
F_7 ( V_6 , L_16 ,
V_6 -> V_97 -> V_98 ) ;
V_6 -> V_100 = true ;
for ( V_81 = 0 ; V_81 < V_93 && V_37 >= 0 ; V_81 ++ ) {
V_94 = & V_49 [ V_81 ] ;
V_94 -> V_62 |= V_6 -> V_101 ;
V_95 = V_94 -> V_62 ;
F_7 ( V_6 ,
L_17 , V_95 ) ;
if ( ( V_95 & ( V_102 ) ) != false ) {
V_37 = F_25 ( V_47 , V_94 , ( V_81 + 1 == V_93 ) ,
( V_81 == 0 ) ) ;
} else {
V_37 = F_21 ( V_47 , V_94 , ( V_81 + 1 == V_93 ) ,
( V_81 == 0 ) ) ;
}
}
V_6 -> V_100 = false ;
F_31 ( & V_96 ) ;
return ( V_37 < 0 ) ? V_37 : V_93 ;
}
static T_2 F_32 ( struct V_46 * V_6 )
{
return V_103 | V_104 | V_105 ;
}
static void F_33 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_4 ( V_6 -> V_8 , V_14 , V_23 ) ;
F_3 ( V_106 , V_7 + V_107 ) ;
F_3 ( V_108 , V_7 + V_109 ) ;
}
static int F_34 ( struct V_110 * V_111 ,
const struct V_112 * V_113 )
{
void T_1 * V_114 ;
int V_37 ;
int V_81 , V_115 ;
struct V_82 * V_83 ;
struct V_46 * V_116 ;
F_35 ( V_111 , L_18 ) ;
V_83 = F_36 ( ( sizeof( struct V_82 ) ) , V_117 ) ;
if ( V_83 == NULL ) {
F_37 ( V_111 , L_19 ) ;
return - V_118 ;
}
V_37 = F_38 ( V_111 ) ;
if ( V_37 ) {
F_37 ( V_111 , L_20 ) ;
goto V_119;
}
V_37 = F_39 ( V_111 , V_120 ) ;
if ( V_37 ) {
F_37 ( V_111 , L_21 ) ;
goto V_121;
}
V_114 = F_40 ( V_111 , 1 , 0 ) ;
if ( V_114 == NULL ) {
F_37 ( V_111 , L_22 ) ;
V_37 = - V_118 ;
goto V_122;
}
V_83 -> V_85 = V_113 -> V_123 ;
V_37 = F_41 ( V_111 -> V_78 , F_28 , V_124 ,
V_120 , V_83 ) ;
if ( V_37 ) {
F_37 ( V_111 , L_23 ) ;
goto V_125;
}
for ( V_81 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ ) {
V_116 = & V_83 -> V_86 [ V_81 ] . V_126 ;
V_83 -> V_98 = false ;
V_83 -> V_86 [ V_81 ] . V_97 = V_83 ;
V_116 -> V_127 = V_128 ;
V_116 -> V_129 = V_130 ;
F_42 ( V_116 -> V_131 , V_120 , sizeof( V_116 -> V_131 ) ) ;
V_116 -> V_132 = & V_133 ;
V_116 -> V_52 = & V_83 -> V_86 [ V_81 ] ;
V_83 -> V_86 [ V_81 ] . V_8 = V_114 + 0x100 * V_81 ;
V_116 -> V_134 . V_135 = & V_111 -> V_134 ;
F_5 ( & V_83 -> V_86 [ V_81 ] ) ;
V_116 -> V_136 = V_81 ;
V_37 = F_43 ( V_116 ) ;
if ( V_37 ) {
F_37 ( V_111 , L_24 , V_81 ) ;
goto V_137;
}
}
F_44 ( V_111 , V_83 ) ;
F_35 ( V_111 , L_25 , V_37 ) ;
return 0 ;
V_137:
for ( V_115 = 0 ; V_115 < V_81 ; V_115 ++ )
F_45 ( & V_83 -> V_86 [ V_115 ] . V_126 ) ;
F_46 ( V_111 -> V_78 , V_83 ) ;
V_125:
F_47 ( V_111 , V_114 ) ;
V_122:
F_48 ( V_111 ) ;
V_121:
F_49 ( V_111 ) ;
V_119:
F_50 ( V_83 ) ;
return V_37 ;
}
static void F_51 ( struct V_110 * V_111 )
{
int V_81 ;
struct V_82 * V_83 = F_52 ( V_111 ) ;
F_46 ( V_111 -> V_78 , V_83 ) ;
for ( V_81 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ ) {
F_33 ( & V_83 -> V_86 [ V_81 ] ) ;
F_45 ( & V_83 -> V_86 [ V_81 ] . V_126 ) ;
}
if ( V_83 -> V_86 [ 0 ] . V_8 )
F_47 ( V_111 , V_83 -> V_86 [ 0 ] . V_8 ) ;
for ( V_81 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ )
V_83 -> V_86 [ V_81 ] . V_8 = NULL ;
F_48 ( V_111 ) ;
F_49 ( V_111 ) ;
F_50 ( V_83 ) ;
}
static int F_53 ( struct V_110 * V_111 , T_6 V_138 )
{
int V_37 ;
int V_81 ;
struct V_82 * V_83 = F_52 ( V_111 ) ;
void T_1 * V_7 = V_83 -> V_86 [ 0 ] . V_8 ;
V_83 -> V_98 = true ;
for ( V_81 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ ) {
while ( ( V_83 -> V_86 [ V_81 ] . V_100 ) ) {
F_6 ( 20 ) ;
}
}
for ( V_81 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ )
F_33 ( & V_83 -> V_86 [ V_81 ] ) ;
F_35 ( V_111 , L_26
L_27 ,
F_2 ( V_7 + V_29 ) , F_2 ( V_7 + V_139 ) ,
F_2 ( V_7 + V_140 ) ) ;
V_37 = F_54 ( V_111 ) ;
if ( V_37 ) {
F_37 ( V_111 , L_28 ) ;
return V_37 ;
}
F_55 ( V_111 , V_141 , 0 ) ;
F_49 ( V_111 ) ;
F_56 ( V_111 , F_57 ( V_111 , V_138 ) ) ;
return 0 ;
}
static int F_58 ( struct V_110 * V_111 )
{
int V_81 ;
struct V_82 * V_83 = F_52 ( V_111 ) ;
F_56 ( V_111 , V_142 ) ;
F_59 ( V_111 ) ;
if ( F_38 ( V_111 ) < 0 ) {
F_37 ( V_111 , L_29 ) ;
return - V_44 ;
}
F_55 ( V_111 , V_141 , 0 ) ;
for ( V_81 = 0 ; V_81 < V_83 -> V_85 ; V_81 ++ )
F_5 ( & V_83 -> V_86 [ V_81 ] ) ;
V_83 -> V_98 = false ;
return 0 ;
}
