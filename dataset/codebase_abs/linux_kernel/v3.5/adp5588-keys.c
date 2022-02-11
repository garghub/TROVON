static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 , L_1 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
return F_5 ( V_2 , V_3 , V_6 ) ;
}
static int F_6 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
return ! ! ( F_1 ( V_11 -> V_2 , V_16 + V_13 ) & V_15 ) ;
}
static void F_10 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
F_11 ( & V_11 -> V_17 ) ;
if ( V_6 )
V_11 -> V_18 [ V_13 ] |= V_15 ;
else
V_11 -> V_18 [ V_13 ] &= ~ V_15 ;
F_4 ( V_11 -> V_2 , V_19 + V_13 ,
V_11 -> V_18 [ V_13 ] ) ;
F_12 ( & V_11 -> V_17 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
int V_4 ;
F_11 ( & V_11 -> V_17 ) ;
V_11 -> V_20 [ V_13 ] &= ~ V_15 ;
V_4 = F_4 ( V_11 -> V_2 , V_21 + V_13 , V_11 -> V_20 [ V_13 ] ) ;
F_12 ( & V_11 -> V_17 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
int V_4 ;
F_11 ( & V_11 -> V_17 ) ;
V_11 -> V_20 [ V_13 ] |= V_15 ;
if ( V_6 )
V_11 -> V_18 [ V_13 ] |= V_15 ;
else
V_11 -> V_18 [ V_13 ] &= ~ V_15 ;
V_4 = F_4 ( V_11 -> V_2 , V_19 + V_13 ,
V_11 -> V_18 [ V_13 ] ) ;
V_4 |= F_4 ( V_11 -> V_2 , V_21 + V_13 ,
V_11 -> V_20 [ V_13 ] ) ;
F_12 ( & V_11 -> V_17 ) ;
return V_4 ;
}
static int T_2 F_15 ( struct V_10 * V_11 ,
const struct V_22 * V_23 )
{
bool V_24 [ V_25 ] ;
int V_26 = 0 ;
int V_27 ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
for ( V_27 = 0 ; V_27 < V_23 -> V_28 ; V_27 ++ )
V_24 [ V_27 ] = true ;
for ( V_27 = 0 ; V_27 < V_23 -> V_29 ; V_27 ++ )
V_24 [ V_27 + V_30 - V_31 ] = true ;
for ( V_27 = 0 ; V_27 < V_11 -> V_32 ; V_27 ++ )
V_24 [ V_11 -> V_33 [ V_27 ] . V_34 - V_31 ] = true ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ )
if ( ! V_24 [ V_27 ] )
V_11 -> V_14 [ V_26 ++ ] = V_27 ;
return V_26 ;
}
static int T_2 F_16 ( struct V_10 * V_11 )
{
struct V_35 * V_5 = & V_11 -> V_2 -> V_5 ;
const struct V_22 * V_23 = V_5 -> V_36 ;
const struct V_37 * V_38 = V_23 -> V_38 ;
int V_27 , error ;
if ( ! V_38 )
return 0 ;
V_11 -> V_12 . V_39 = F_15 ( V_11 , V_23 ) ;
if ( V_11 -> V_12 . V_39 == 0 ) {
F_17 ( V_5 , L_2 ) ;
return 0 ;
}
V_11 -> V_40 = true ;
V_11 -> V_12 . V_41 = F_13 ;
V_11 -> V_12 . V_42 = F_14 ;
V_11 -> V_12 . V_43 = F_6 ;
V_11 -> V_12 . V_44 = F_10 ;
V_11 -> V_12 . V_45 = 1 ;
V_11 -> V_12 . V_46 = V_38 -> V_47 ;
V_11 -> V_12 . V_48 = V_11 -> V_2 -> V_49 ;
V_11 -> V_12 . V_50 = V_51 ;
V_11 -> V_12 . V_52 = V_38 -> V_52 ;
F_18 ( & V_11 -> V_17 ) ;
error = F_19 ( & V_11 -> V_12 ) ;
if ( error ) {
F_3 ( V_5 , L_3 , error ) ;
return error ;
}
for ( V_27 = 0 ; V_27 <= F_8 ( V_25 ) ; V_27 ++ ) {
V_11 -> V_18 [ V_27 ] = F_1 ( V_11 -> V_2 ,
V_19 + V_27 ) ;
V_11 -> V_20 [ V_27 ] = F_1 ( V_11 -> V_2 , V_21 + V_27 ) ;
}
if ( V_38 -> V_53 ) {
error = V_38 -> V_53 ( V_11 -> V_2 ,
V_11 -> V_12 . V_46 , V_11 -> V_12 . V_39 ,
V_38 -> V_54 ) ;
if ( error )
F_20 ( V_5 , L_4 , error ) ;
}
return 0 ;
}
static void T_3 F_21 ( struct V_10 * V_11 )
{
struct V_35 * V_5 = & V_11 -> V_2 -> V_5 ;
const struct V_22 * V_23 = V_5 -> V_36 ;
const struct V_37 * V_38 = V_23 -> V_38 ;
int error ;
if ( ! V_11 -> V_40 )
return;
if ( V_38 -> V_55 ) {
error = V_38 -> V_55 ( V_11 -> V_2 ,
V_11 -> V_12 . V_46 , V_11 -> V_12 . V_39 ,
V_38 -> V_54 ) ;
if ( error )
F_20 ( V_5 , L_5 , error ) ;
}
error = F_22 ( & V_11 -> V_12 ) ;
if ( error )
F_20 ( V_5 , L_6 , error ) ;
}
static inline int F_16 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline void F_21 ( struct V_10 * V_11 )
{
}
static void F_23 ( struct V_10 * V_11 , int V_56 )
{
int V_27 , V_57 ;
for ( V_27 = 0 ; V_27 < V_56 ; V_27 ++ ) {
int V_58 = F_1 ( V_11 -> V_2 , V_59 + V_27 ) ;
int V_60 = V_58 & V_61 ;
if ( V_60 >= V_31 && V_60 <= V_62 ) {
for ( V_57 = 0 ; V_57 < V_11 -> V_32 ; V_57 ++ ) {
if ( V_60 == V_11 -> V_33 [ V_57 ] . V_34 ) {
F_24 ( V_11 -> V_63 ,
V_11 -> V_33 [ V_57 ] . V_64 ,
V_58 & V_65 ) ;
break;
}
}
} else {
F_25 ( V_11 -> V_63 ,
V_11 -> V_66 [ V_60 - 1 ] ,
V_58 & V_65 ) ;
}
}
}
static void F_26 ( struct V_67 * V_68 )
{
struct V_10 * V_11 = F_7 ( V_68 ,
struct V_10 , V_68 . V_68 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_69 , V_56 ;
V_69 = F_1 ( V_2 , V_70 ) ;
if ( V_69 & V_71 )
F_3 ( & V_2 -> V_5 , L_7 ) ;
if ( V_69 & V_72 ) {
V_56 = F_1 ( V_2 , V_73 ) & V_74 ;
if ( V_56 ) {
F_23 ( V_11 , V_56 ) ;
F_27 ( V_11 -> V_63 ) ;
}
}
F_4 ( V_2 , V_70 , V_69 ) ;
}
static T_4 F_28 ( int V_75 , void * V_76 )
{
struct V_10 * V_11 = V_76 ;
F_29 ( & V_11 -> V_68 , V_11 -> V_77 ) ;
return V_78 ;
}
static int T_2 F_30 ( struct V_1 * V_2 )
{
const struct V_22 * V_23 = V_2 -> V_5 . V_36 ;
const struct V_37 * V_38 = V_23 -> V_38 ;
int V_27 , V_4 ;
unsigned char V_79 = 0 , V_80 = 0 , V_81 = 0 ;
V_4 = F_4 ( V_2 , V_82 , F_31 ( V_23 -> V_28 ) ) ;
V_4 |= F_4 ( V_2 , V_83 , F_31 ( V_23 -> V_29 ) & 0xFF ) ;
V_4 |= F_4 ( V_2 , V_84 , F_31 ( V_23 -> V_29 ) >> 8 ) ;
if ( V_23 -> V_85 ) {
V_4 |= F_4 ( V_2 , V_86 , V_23 -> V_87 ) ;
V_4 |= F_4 ( V_2 , V_88 , V_23 -> V_89 ) ;
V_4 |= F_4 ( V_2 , V_73 , V_90 ) ;
}
for ( V_27 = 0 ; V_27 < V_91 ; V_27 ++ )
V_4 |= F_1 ( V_2 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_23 -> V_32 ; V_27 ++ ) {
unsigned short V_34 = V_23 -> V_33 [ V_27 ] . V_34 ;
if ( V_34 <= V_92 ) {
V_79 |= ( 1 << ( V_34 - V_93 ) ) ;
} else {
V_80 |= ( ( 1 << ( V_34 - V_30 ) ) & 0xFF ) ;
V_81 |= ( ( 1 << ( V_34 - V_30 ) ) >> 8 ) ;
}
}
if ( V_23 -> V_32 ) {
V_4 |= F_4 ( V_2 , V_94 , V_79 ) ;
V_4 |= F_4 ( V_2 , V_95 , V_80 ) ;
V_4 |= F_4 ( V_2 , V_96 , V_81 ) ;
}
if ( V_38 ) {
for ( V_27 = 0 ; V_27 <= F_8 ( V_25 ) ; V_27 ++ ) {
int V_97 = V_38 -> V_98 ;
V_4 |= F_4 ( V_2 , V_99 + V_27 ,
( V_97 >> ( 8 * V_27 ) ) & 0xFF ) ;
}
}
V_4 |= F_4 ( V_2 , V_70 ,
V_100 | V_101 |
V_71 | V_102 |
V_103 | V_72 ) ;
V_4 |= F_4 ( V_2 , V_104 , V_105 |
V_106 |
V_107 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 , L_8 ) ;
return V_4 ;
}
return 0 ;
}
static void T_2 F_32 ( struct V_10 * V_11 )
{
int V_108 = F_1 ( V_11 -> V_2 , V_16 ) ;
int V_109 = F_1 ( V_11 -> V_2 , V_110 ) ;
int V_111 = F_1 ( V_11 -> V_2 , V_112 ) ;
int V_113 , V_114 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_11 -> V_32 ; V_27 ++ ) {
unsigned short V_34 = V_11 -> V_33 [ V_27 ] . V_34 ;
if ( V_34 <= V_92 ) {
V_113 = V_108 ;
V_114 = V_34 - V_93 ;
} else if ( ( V_34 - V_30 ) < 8 ) {
V_113 = V_109 ;
V_114 = V_34 - V_30 ;
} else {
V_113 = V_111 ;
V_114 = V_34 - V_30 - 8 ;
}
if ( V_113 < 0 ) {
F_3 ( & V_11 -> V_2 -> V_5 ,
L_9 ,
V_34 ) ;
V_113 = 0 ;
}
F_24 ( V_11 -> V_63 ,
V_11 -> V_33 [ V_27 ] . V_64 ,
! ( V_113 & ( 1 << V_114 ) ) ) ;
}
F_27 ( V_11 -> V_63 ) ;
}
static int T_2 F_33 ( struct V_1 * V_2 ,
const struct V_115 * V_116 )
{
struct V_10 * V_11 ;
const struct V_22 * V_23 = V_2 -> V_5 . V_36 ;
struct V_117 * V_63 ;
unsigned int V_118 ;
int V_4 , V_27 ;
int error ;
if ( ! F_34 ( V_2 -> V_119 ,
V_120 ) ) {
F_3 ( & V_2 -> V_5 , L_10 ) ;
return - V_121 ;
}
if ( ! V_23 ) {
F_3 ( & V_2 -> V_5 , L_11 ) ;
return - V_122 ;
}
if ( ! V_23 -> V_28 || ! V_23 -> V_29 || ! V_23 -> V_123 ) {
F_3 ( & V_2 -> V_5 , L_12 ) ;
return - V_122 ;
}
if ( V_23 -> V_124 != V_125 ) {
F_3 ( & V_2 -> V_5 , L_13 ) ;
return - V_122 ;
}
if ( ! V_23 -> V_33 && V_23 -> V_32 ) {
F_3 ( & V_2 -> V_5 , L_14 ) ;
return - V_122 ;
}
if ( V_23 -> V_32 > V_126 ) {
F_3 ( & V_2 -> V_5 , L_15 ) ;
return - V_122 ;
}
for ( V_27 = 0 ; V_27 < V_23 -> V_32 ; V_27 ++ ) {
unsigned short V_34 = V_23 -> V_33 [ V_27 ] . V_34 ;
if ( V_34 < V_31 || V_34 > V_62 ) {
F_3 ( & V_2 -> V_5 , L_16 ) ;
return - V_122 ;
}
if ( V_34 <= V_92 ) {
if ( V_34 - V_93 + 1 <= V_23 -> V_28 ) {
F_3 ( & V_2 -> V_5 , L_17 ) ;
return - V_122 ;
}
} else {
if ( V_34 - V_30 + 1 <= V_23 -> V_29 ) {
F_3 ( & V_2 -> V_5 , L_18 ) ;
return - V_122 ;
}
}
}
if ( ! V_2 -> V_75 ) {
F_3 ( & V_2 -> V_5 , L_19 ) ;
return - V_122 ;
}
V_11 = F_35 ( sizeof( * V_11 ) , V_127 ) ;
V_63 = F_36 () ;
if ( ! V_11 || ! V_63 ) {
error = - V_128 ;
goto V_129;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_63 = V_63 ;
F_37 ( & V_11 -> V_68 , F_26 ) ;
V_4 = F_1 ( V_2 , V_130 ) ;
if ( V_4 < 0 ) {
error = V_4 ;
goto V_129;
}
V_118 = ( T_1 ) V_4 & V_131 ;
if ( F_38 ( V_118 ) )
V_11 -> V_77 = F_39 ( 30 ) ;
V_63 -> V_49 = V_2 -> V_49 ;
V_63 -> V_132 = L_20 ;
V_63 -> V_5 . V_133 = & V_2 -> V_5 ;
F_40 ( V_63 , V_11 ) ;
V_63 -> V_116 . V_134 = V_135 ;
V_63 -> V_116 . V_136 = 0x0001 ;
V_63 -> V_116 . V_137 = 0x0001 ;
V_63 -> V_116 . V_138 = V_118 ;
V_63 -> V_139 = sizeof( V_11 -> V_66 [ 0 ] ) ;
V_63 -> V_140 = V_23 -> V_124 ;
V_63 -> V_66 = V_11 -> V_66 ;
memcpy ( V_11 -> V_66 , V_23 -> V_123 ,
V_23 -> V_124 * V_63 -> V_139 ) ;
V_11 -> V_33 = V_23 -> V_33 ;
V_11 -> V_32 = V_23 -> V_32 ;
F_41 ( V_141 , V_63 -> V_142 ) ;
if ( V_23 -> V_143 )
F_41 ( V_144 , V_63 -> V_142 ) ;
for ( V_27 = 0 ; V_27 < V_63 -> V_140 ; V_27 ++ )
F_41 ( V_11 -> V_66 [ V_27 ] & V_145 , V_63 -> V_146 ) ;
F_42 ( V_147 , V_63 -> V_146 ) ;
if ( V_11 -> V_32 )
F_41 ( V_148 , V_63 -> V_142 ) ;
for ( V_27 = 0 ; V_27 < V_11 -> V_32 ; V_27 ++ )
F_41 ( V_11 -> V_33 [ V_27 ] . V_64 , V_63 -> V_149 ) ;
error = F_43 ( V_63 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 , L_21 ) ;
goto V_129;
}
error = F_44 ( V_2 -> V_75 , F_28 ,
V_150 ,
V_2 -> V_5 . V_151 -> V_49 , V_11 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 , L_22 , V_2 -> V_75 ) ;
goto V_152;
}
error = F_30 ( V_2 ) ;
if ( error )
goto V_153;
if ( V_11 -> V_32 )
F_32 ( V_11 ) ;
error = F_16 ( V_11 ) ;
if ( error )
goto V_153;
F_45 ( & V_2 -> V_5 , 1 ) ;
F_46 ( V_2 , V_11 ) ;
F_17 ( & V_2 -> V_5 , L_23 , V_118 , V_2 -> V_75 ) ;
return 0 ;
V_153:
F_47 ( V_2 -> V_75 , V_11 ) ;
V_152:
F_48 ( V_63 ) ;
V_63 = NULL ;
V_129:
F_49 ( V_63 ) ;
F_50 ( V_11 ) ;
return error ;
}
static int T_3 F_51 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_52 ( V_2 ) ;
F_4 ( V_2 , V_104 , 0 ) ;
F_47 ( V_2 -> V_75 , V_11 ) ;
F_53 ( & V_11 -> V_68 ) ;
F_48 ( V_11 -> V_63 ) ;
F_21 ( V_11 ) ;
F_50 ( V_11 ) ;
return 0 ;
}
static int F_54 ( struct V_35 * V_5 )
{
struct V_10 * V_11 = F_55 ( V_5 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_56 ( V_2 -> V_75 ) ;
F_53 ( & V_11 -> V_68 ) ;
if ( F_57 ( & V_2 -> V_5 ) )
F_58 ( V_2 -> V_75 ) ;
return 0 ;
}
static int F_59 ( struct V_35 * V_5 )
{
struct V_10 * V_11 = F_55 ( V_5 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( F_57 ( & V_2 -> V_5 ) )
F_60 ( V_2 -> V_75 ) ;
F_61 ( V_2 -> V_75 ) ;
return 0 ;
}
