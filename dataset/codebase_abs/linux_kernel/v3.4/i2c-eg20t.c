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
static inline bool F_9 ( const T_3 V_25 , const T_3 V_26 )
{
return V_25 . V_27 < V_26 . V_27 ;
}
static T_4 F_10 ( struct V_5 * V_6 ,
T_4 V_28 )
{
void T_1 * V_7 = V_6 -> V_8 ;
int V_29 = 0 ;
unsigned long V_30 = V_31 + F_11 ( V_28 ) ;
while ( F_2 ( V_7 + V_32 ) & V_33 ) {
if ( F_12 ( V_31 , V_30 ) ) {
F_7 ( V_6 , L_3 , F_2 ( V_7 + V_32 ) ) ;
F_13 ( V_6 , L_4 ,
V_34 , - V_35 ) ;
F_5 ( V_6 ) ;
return - V_35 ;
}
if ( ! V_29 )
F_14 ( 5 ) ;
else
F_15 ( 20 , 1000 ) ;
V_29 = 1 ;
}
return 0 ;
}
static void F_16 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_36 ) ;
}
static T_4 F_17 ( struct V_5 * V_6 )
{
long V_37 ;
V_37 = F_18 ( V_24 ,
( V_6 -> V_38 != 0 ) , F_11 ( 1000 ) ) ;
if ( V_37 == 0 ) {
F_13 ( V_6 , L_6 , V_6 -> V_38 ) ;
V_6 -> V_38 = 0 ;
return - V_39 ;
}
if ( V_6 -> V_38 & V_40 ) {
F_13 ( V_6 , L_7 , V_6 -> V_38 ) ;
V_6 -> V_38 = 0 ;
return - V_41 ;
}
V_6 -> V_38 = 0 ;
return 0 ;
}
static T_4 F_19 ( struct V_5 * V_6 )
{
T_2 V_42 ;
void T_1 * V_7 = V_6 -> V_8 ;
V_42 = F_2 ( V_7 + V_32 ) & V_43 ;
if ( V_42 != 0 ) {
F_13 ( V_6 , L_8 , - V_44 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_4 ( V_6 -> V_8 , V_14 , V_36 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_45 ) ;
}
static T_4 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 , T_2 V_50 , T_2 V_51 )
{
struct V_5 * V_6 = V_47 -> V_52 ;
T_5 * V_53 ;
T_2 V_54 ;
T_2 V_1 ;
T_2 V_55 ;
T_2 V_56 ;
T_4 V_57 ;
T_4 V_58 ;
void T_1 * V_7 = V_6 -> V_8 ;
V_54 = V_49 -> V_59 ;
V_53 = V_49 -> V_53 ;
V_1 = V_49 -> V_1 ;
F_1 ( V_6 -> V_8 , V_14 , V_60 ) ;
F_7 ( V_6 , L_9 , F_2 ( V_7 + V_14 ) ,
V_54 ) ;
if ( V_51 ) {
if ( F_10 ( V_6 , V_61 ) == - V_35 )
return - V_35 ;
}
if ( V_49 -> V_62 & V_63 ) {
V_55 = ( ( V_1 & V_64 ) >> 7 ) & 0x06 ;
F_3 ( V_55 | V_65 , V_7 + V_66 ) ;
if ( V_51 )
F_16 ( V_6 ) ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_10
L_11 ) ;
return - V_41 ;
}
V_56 = ( V_1 & V_67 ) ;
F_3 ( V_56 , V_7 + V_66 ) ;
} else if ( V_58 == - V_41 ) {
F_13 ( V_6 , L_12 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_68 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_69 ) ;
F_5 ( V_6 ) ;
return - V_70 ;
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
} else {
F_3 ( V_1 << 1 , V_7 + V_66 ) ;
if ( V_51 )
F_16 ( V_6 ) ;
}
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_10
L_11 ) ;
return - V_41 ;
}
} else if ( V_58 == - V_41 ) {
F_13 ( V_6 , L_12 ) ;
F_4 ( V_6 -> V_8 , V_32 , V_68 ) ;
F_4 ( V_6 -> V_8 , V_32 , V_69 ) ;
F_5 ( V_6 ) ;
return - V_70 ;
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
for ( V_57 = 0 ; V_57 < V_54 ; ++ V_57 ) {
F_3 ( V_53 [ V_57 ] , V_7 + V_66 ) ;
F_7 ( V_6 , L_13 , V_53 [ V_57 ] ) ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_10
L_11 ) ;
return - V_41 ;
}
F_4 ( V_6 -> V_8 , V_32 ,
V_71 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_69 ) ;
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
}
if ( V_50 )
F_20 ( V_6 ) ;
else
F_21 ( V_6 ) ;
F_7 ( V_6 , L_14 , V_57 ) ;
return V_57 ;
}
static void F_23 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_4 ( V_6 -> V_8 , V_14 , V_72 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_72 ) ;
}
static void F_25 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_7 ( V_6 , L_5 , F_2 ( V_7 + V_14 ) ) ;
F_1 ( V_6 -> V_8 , V_14 , V_73 ) ;
}
static T_4 F_26 ( struct V_46 * V_47 , struct V_48 * V_49 ,
T_2 V_50 , T_2 V_51 )
{
struct V_5 * V_6 = V_47 -> V_52 ;
T_5 * V_53 ;
T_2 V_74 ;
T_2 V_54 ;
T_2 V_1 ;
T_2 V_55 ;
T_2 V_56 ;
void T_1 * V_7 = V_6 -> V_8 ;
T_4 V_58 ;
V_54 = V_49 -> V_59 ;
V_53 = V_49 -> V_53 ;
V_1 = V_49 -> V_1 ;
F_4 ( V_6 -> V_8 , V_14 , V_60 ) ;
if ( V_51 ) {
if ( F_10 ( V_6 , V_61 ) == - V_35 )
return - V_35 ;
}
if ( V_49 -> V_62 & V_63 ) {
V_55 = ( ( V_1 & V_64 ) >> 7 ) ;
F_3 ( V_55 | V_65 , V_7 + V_66 ) ;
if ( V_51 )
F_16 ( V_6 ) ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_10
L_11 ) ;
return - V_41 ;
}
V_56 = ( V_1 & V_67 ) ;
F_3 ( V_56 , V_7 + V_66 ) ;
} else if ( V_58 == - V_41 ) {
F_13 ( V_6 , L_12 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_68 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_69 ) ;
F_5 ( V_6 ) ;
return - V_70 ;
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
F_25 ( V_6 ) ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_10
L_11 ) ;
return - V_41 ;
}
V_55 |= V_75 ;
F_3 ( V_55 | V_65 ,
V_7 + V_66 ) ;
} else if ( V_58 == - V_41 ) {
F_13 ( V_6 , L_12 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_68 ) ;
F_4 ( V_6 -> V_8 , V_32 ,
V_69 ) ;
F_5 ( V_6 ) ;
return - V_70 ;
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
} else {
V_1 = ( ( ( V_1 ) << 1 ) | ( V_75 ) ) ;
F_3 ( V_1 , V_7 + V_66 ) ;
}
if ( V_51 )
F_16 ( V_6 ) ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_10
L_11 ) ;
return - V_41 ;
}
} else if ( V_58 == - V_41 ) {
F_13 ( V_6 , L_12 ) ;
F_4 ( V_6 -> V_8 , V_32 , V_68 ) ;
F_4 ( V_6 -> V_8 , V_32 , V_69 ) ;
F_5 ( V_6 ) ;
return - V_70 ;
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
if ( V_54 == 0 ) {
F_20 ( V_6 ) ;
F_2 ( V_7 + V_66 ) ;
V_74 = V_54 ;
} else {
int V_76 ;
int V_77 ;
F_23 ( V_6 ) ;
for ( V_77 = 1 , V_76 = 0 ; V_77 < V_54 ; V_77 ++ ) {
V_53 [ V_76 ] = F_2 ( V_7 + V_66 ) ;
if ( V_77 != 1 )
V_76 ++ ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_15
L_16 ) ;
return - V_41 ;
}
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
}
F_24 ( V_6 ) ;
V_53 [ V_76 ] = F_2 ( V_7 + V_66 ) ;
if ( V_54 != 1 )
V_76 ++ ;
V_58 = F_17 ( V_6 ) ;
if ( V_58 == 0 ) {
if ( F_19 ( V_6 ) ) {
F_7 ( V_6 , L_15
L_16 ) ;
return - V_41 ;
}
} else {
F_20 ( V_6 ) ;
return - V_35 ;
}
if ( V_50 )
F_20 ( V_6 ) ;
else
F_21 ( V_6 ) ;
V_53 [ V_76 ++ ] = F_2 ( V_7 + V_66 ) ;
V_74 = V_76 ;
}
return V_74 ;
}
static void F_27 ( struct V_5 * V_6 )
{
T_2 V_78 ;
void T_1 * V_7 = V_6 -> V_8 ;
V_78 = F_2 ( V_7 + V_32 ) ;
V_78 &= ( V_68 | V_71 | V_69 ) ;
if ( V_78 & V_68 )
V_6 -> V_38 |= V_79 ;
if ( V_78 & V_71 )
V_6 -> V_38 |= V_80 ;
F_4 ( V_6 -> V_8 , V_32 , V_78 ) ;
F_7 ( V_6 , L_17 , F_2 ( V_7 + V_32 ) ) ;
F_28 ( & V_24 ) ;
}
static T_6 F_29 ( int V_81 , void * V_82 )
{
T_2 V_42 ;
int V_83 ;
int V_84 ;
struct V_85 * V_86 = V_82 ;
void T_1 * V_7 ;
T_2 V_87 ;
for ( V_84 = 0 , V_83 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ ) {
V_7 = V_86 -> V_89 [ V_84 ] . V_8 ;
V_87 = F_2 ( V_7 + V_90 ) ;
V_87 &= V_91 | V_92 ;
if ( V_87 != V_93 ) {
F_13 ( V_86 -> V_89 ,
L_18 , V_87 , V_84 ) ;
continue;
}
V_42 = F_2 ( V_7 + V_32 ) ;
if ( V_42 & ( V_68 | V_71 | V_69 ) ) {
F_27 ( & V_86 -> V_89 [ V_84 ] ) ;
V_83 = 1 ;
}
}
return V_83 ? V_94 : V_95 ;
}
static T_4 F_30 ( struct V_46 * V_47 ,
struct V_48 * V_49 , T_4 V_96 )
{
struct V_48 * V_97 ;
T_2 V_84 = 0 ;
T_2 V_98 ;
T_4 V_37 ;
struct V_5 * V_6 = V_47 -> V_52 ;
V_37 = F_31 ( & V_99 ) ;
if ( V_37 )
return - V_100 ;
if ( V_6 -> V_101 -> V_102 ) {
F_32 ( & V_99 ) ;
return - V_103 ;
}
F_7 ( V_6 , L_19 ,
V_6 -> V_101 -> V_102 ) ;
V_6 -> V_104 = true ;
for ( V_84 = 0 ; V_84 < V_96 && V_37 >= 0 ; V_84 ++ ) {
V_97 = & V_49 [ V_84 ] ;
V_97 -> V_62 |= V_6 -> V_105 ;
V_98 = V_97 -> V_62 ;
F_7 ( V_6 ,
L_20 , V_98 ) ;
if ( ( V_98 & ( V_106 ) ) != false ) {
V_37 = F_26 ( V_47 , V_97 , ( V_84 + 1 == V_96 ) ,
( V_84 == 0 ) ) ;
} else {
V_37 = F_22 ( V_47 , V_97 , ( V_84 + 1 == V_96 ) ,
( V_84 == 0 ) ) ;
}
}
V_6 -> V_104 = false ;
F_32 ( & V_99 ) ;
return ( V_37 < 0 ) ? V_37 : V_96 ;
}
static T_2 F_33 ( struct V_46 * V_6 )
{
return V_107 | V_108 | V_109 ;
}
static void F_34 ( struct V_5 * V_6 )
{
void T_1 * V_7 = V_6 -> V_8 ;
F_4 ( V_6 -> V_8 , V_14 , V_23 ) ;
F_3 ( V_110 , V_7 + V_111 ) ;
F_3 ( V_112 , V_7 + V_113 ) ;
}
static int T_7 F_35 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
void T_1 * V_118 ;
int V_37 ;
int V_84 , V_119 ;
struct V_85 * V_86 ;
struct V_46 * V_120 ;
F_36 ( V_115 , L_21 ) ;
V_86 = F_37 ( ( sizeof( struct V_85 ) ) , V_121 ) ;
if ( V_86 == NULL ) {
F_38 ( V_115 , L_22 ) ;
return - V_122 ;
}
V_37 = F_39 ( V_115 ) ;
if ( V_37 ) {
F_38 ( V_115 , L_23 ) ;
goto V_123;
}
V_37 = F_40 ( V_115 , V_124 ) ;
if ( V_37 ) {
F_38 ( V_115 , L_24 ) ;
goto V_125;
}
V_118 = F_41 ( V_115 , 1 , 0 ) ;
if ( V_118 == NULL ) {
F_38 ( V_115 , L_25 ) ;
V_37 = - V_122 ;
goto V_126;
}
V_86 -> V_88 = V_117 -> V_127 ;
V_37 = F_42 ( V_115 -> V_81 , F_29 , V_128 ,
V_124 , V_86 ) ;
if ( V_37 ) {
F_38 ( V_115 , L_26 ) ;
goto V_129;
}
for ( V_84 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ ) {
V_120 = & V_86 -> V_89 [ V_84 ] . V_130 ;
V_86 -> V_102 = false ;
V_86 -> V_89 [ V_84 ] . V_101 = V_86 ;
V_120 -> V_131 = V_132 ;
V_120 -> V_133 = V_134 ;
strcpy ( V_120 -> V_135 , V_124 ) ;
V_120 -> V_136 = & V_137 ;
V_120 -> V_52 = & V_86 -> V_89 [ V_84 ] ;
V_86 -> V_89 [ V_84 ] . V_8 = V_118 + 0x100 * V_84 ;
V_120 -> V_138 . V_139 = & V_115 -> V_138 ;
F_5 ( & V_86 -> V_89 [ V_84 ] ) ;
V_120 -> V_140 = V_84 ;
V_37 = F_43 ( V_120 ) ;
if ( V_37 ) {
F_38 ( V_115 , L_27 , V_84 ) ;
goto V_141;
}
}
F_44 ( V_115 , V_86 ) ;
F_36 ( V_115 , L_28 , V_37 ) ;
return 0 ;
V_141:
for ( V_119 = 0 ; V_119 < V_84 ; V_119 ++ )
F_45 ( & V_86 -> V_89 [ V_119 ] . V_130 ) ;
F_46 ( V_115 -> V_81 , V_86 ) ;
V_129:
F_47 ( V_115 , V_118 ) ;
V_126:
F_48 ( V_115 ) ;
V_125:
F_49 ( V_115 ) ;
V_123:
F_50 ( V_86 ) ;
return V_37 ;
}
static void T_8 F_51 ( struct V_114 * V_115 )
{
int V_84 ;
struct V_85 * V_86 = F_52 ( V_115 ) ;
F_46 ( V_115 -> V_81 , V_86 ) ;
for ( V_84 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ ) {
F_34 ( & V_86 -> V_89 [ V_84 ] ) ;
F_45 ( & V_86 -> V_89 [ V_84 ] . V_130 ) ;
}
if ( V_86 -> V_89 [ 0 ] . V_8 )
F_47 ( V_115 , V_86 -> V_89 [ 0 ] . V_8 ) ;
for ( V_84 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ )
V_86 -> V_89 [ V_84 ] . V_8 = 0 ;
F_44 ( V_115 , NULL ) ;
F_48 ( V_115 ) ;
F_49 ( V_115 ) ;
F_50 ( V_86 ) ;
}
static int F_53 ( struct V_114 * V_115 , T_9 V_142 )
{
int V_37 ;
int V_84 ;
struct V_85 * V_86 = F_52 ( V_115 ) ;
void T_1 * V_7 = V_86 -> V_89 [ 0 ] . V_8 ;
V_86 -> V_102 = true ;
for ( V_84 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ ) {
while ( ( V_86 -> V_89 [ V_84 ] . V_104 ) ) {
F_6 ( 20 ) ;
}
}
for ( V_84 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ )
F_34 ( & V_86 -> V_89 [ V_84 ] ) ;
F_36 ( V_115 , L_29
L_30 ,
F_2 ( V_7 + V_32 ) , F_2 ( V_7 + V_143 ) ,
F_2 ( V_7 + V_144 ) ) ;
V_37 = F_54 ( V_115 ) ;
if ( V_37 ) {
F_38 ( V_115 , L_31 ) ;
return V_37 ;
}
F_55 ( V_115 , V_145 , 0 ) ;
F_49 ( V_115 ) ;
F_56 ( V_115 , F_57 ( V_115 , V_142 ) ) ;
return 0 ;
}
static int F_58 ( struct V_114 * V_115 )
{
int V_84 ;
struct V_85 * V_86 = F_52 ( V_115 ) ;
F_56 ( V_115 , V_146 ) ;
F_59 ( V_115 ) ;
if ( F_39 ( V_115 ) < 0 ) {
F_38 ( V_115 , L_32 ) ;
return - V_41 ;
}
F_55 ( V_115 , V_145 , 0 ) ;
for ( V_84 = 0 ; V_84 < V_86 -> V_88 ; V_84 ++ )
F_5 ( & V_86 -> V_89 [ V_84 ] ) ;
V_86 -> V_102 = false ;
return 0 ;
}
static int T_10 F_60 ( void )
{
return F_61 ( & V_147 ) ;
}
static void T_11 F_62 ( void )
{
F_63 ( & V_147 ) ;
}
