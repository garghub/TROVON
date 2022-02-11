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
struct V_10 * V_11 = F_7 ( V_8 ) ;
unsigned int V_12 = F_8 ( V_11 -> V_13 [ V_9 ] ) ;
unsigned int V_14 = F_9 ( V_11 -> V_13 [ V_9 ] ) ;
int V_6 ;
F_10 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_16 [ V_12 ] & V_14 )
V_6 = V_11 -> V_17 [ V_12 ] ;
else
V_6 = F_1 ( V_11 -> V_2 , V_18 + V_12 ) ;
F_11 ( & V_11 -> V_15 ) ;
return ! ! ( V_6 & V_14 ) ;
}
static void F_12 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
unsigned int V_12 = F_8 ( V_11 -> V_13 [ V_9 ] ) ;
unsigned int V_14 = F_9 ( V_11 -> V_13 [ V_9 ] ) ;
F_10 ( & V_11 -> V_15 ) ;
if ( V_6 )
V_11 -> V_17 [ V_12 ] |= V_14 ;
else
V_11 -> V_17 [ V_12 ] &= ~ V_14 ;
F_4 ( V_11 -> V_2 , V_19 + V_12 ,
V_11 -> V_17 [ V_12 ] ) ;
F_11 ( & V_11 -> V_15 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
unsigned int V_12 = F_8 ( V_11 -> V_13 [ V_9 ] ) ;
unsigned int V_14 = F_9 ( V_11 -> V_13 [ V_9 ] ) ;
int V_4 ;
F_10 ( & V_11 -> V_15 ) ;
V_11 -> V_16 [ V_12 ] &= ~ V_14 ;
V_4 = F_4 ( V_11 -> V_2 , V_20 + V_12 , V_11 -> V_16 [ V_12 ] ) ;
F_11 ( & V_11 -> V_15 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
unsigned int V_12 = F_8 ( V_11 -> V_13 [ V_9 ] ) ;
unsigned int V_14 = F_9 ( V_11 -> V_13 [ V_9 ] ) ;
int V_4 ;
F_10 ( & V_11 -> V_15 ) ;
V_11 -> V_16 [ V_12 ] |= V_14 ;
if ( V_6 )
V_11 -> V_17 [ V_12 ] |= V_14 ;
else
V_11 -> V_17 [ V_12 ] &= ~ V_14 ;
V_4 = F_4 ( V_11 -> V_2 , V_19 + V_12 ,
V_11 -> V_17 [ V_12 ] ) ;
V_4 |= F_4 ( V_11 -> V_2 , V_20 + V_12 ,
V_11 -> V_16 [ V_12 ] ) ;
F_11 ( & V_11 -> V_15 ) ;
return V_4 ;
}
static int F_15 ( struct V_10 * V_11 ,
const struct V_21 * V_22 )
{
bool V_23 [ V_24 ] ;
int V_25 = 0 ;
int V_26 ;
memset ( V_23 , 0 , sizeof( V_23 ) ) ;
for ( V_26 = 0 ; V_26 < V_22 -> V_27 ; V_26 ++ )
V_23 [ V_26 ] = true ;
for ( V_26 = 0 ; V_26 < V_22 -> V_28 ; V_26 ++ )
V_23 [ V_26 + V_29 - V_30 ] = true ;
for ( V_26 = 0 ; V_26 < V_11 -> V_31 ; V_26 ++ )
V_23 [ V_11 -> V_32 [ V_26 ] . V_33 - V_30 ] = true ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
if ( ! V_23 [ V_26 ] )
V_11 -> V_13 [ V_25 ++ ] = V_26 ;
return V_25 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_34 * V_5 = & V_11 -> V_2 -> V_5 ;
const struct V_21 * V_22 = F_17 ( V_5 ) ;
const struct V_35 * V_36 = V_22 -> V_36 ;
int V_26 , error ;
if ( ! V_36 )
return 0 ;
V_11 -> V_37 . V_38 = F_15 ( V_11 , V_22 ) ;
if ( V_11 -> V_37 . V_38 == 0 ) {
F_18 ( V_5 , L_2 ) ;
return 0 ;
}
V_11 -> V_39 = true ;
V_11 -> V_37 . V_40 = F_13 ;
V_11 -> V_37 . V_41 = F_14 ;
V_11 -> V_37 . V_42 = F_6 ;
V_11 -> V_37 . V_43 = F_12 ;
V_11 -> V_37 . V_44 = 1 ;
V_11 -> V_37 . V_45 = V_36 -> V_46 ;
V_11 -> V_37 . V_47 = V_11 -> V_2 -> V_48 ;
V_11 -> V_37 . V_49 = V_50 ;
V_11 -> V_37 . V_51 = V_36 -> V_51 ;
F_19 ( & V_11 -> V_15 ) ;
error = F_20 ( & V_11 -> V_37 , V_11 ) ;
if ( error ) {
F_3 ( V_5 , L_3 , error ) ;
return error ;
}
for ( V_26 = 0 ; V_26 <= F_8 ( V_24 ) ; V_26 ++ ) {
V_11 -> V_17 [ V_26 ] = F_1 ( V_11 -> V_2 ,
V_19 + V_26 ) ;
V_11 -> V_16 [ V_26 ] = F_1 ( V_11 -> V_2 , V_20 + V_26 ) ;
}
if ( V_36 -> V_52 ) {
error = V_36 -> V_52 ( V_11 -> V_2 ,
V_11 -> V_37 . V_45 , V_11 -> V_37 . V_38 ,
V_36 -> V_53 ) ;
if ( error )
F_21 ( V_5 , L_4 , error ) ;
}
return 0 ;
}
static void F_22 ( struct V_10 * V_11 )
{
struct V_34 * V_5 = & V_11 -> V_2 -> V_5 ;
const struct V_21 * V_22 = F_17 ( V_5 ) ;
const struct V_35 * V_36 = V_22 -> V_36 ;
int error ;
if ( ! V_11 -> V_39 )
return;
if ( V_36 -> V_54 ) {
error = V_36 -> V_54 ( V_11 -> V_2 ,
V_11 -> V_37 . V_45 , V_11 -> V_37 . V_38 ,
V_36 -> V_53 ) ;
if ( error )
F_21 ( V_5 , L_5 , error ) ;
}
F_23 ( & V_11 -> V_37 ) ;
}
static inline int F_16 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline void F_22 ( struct V_10 * V_11 )
{
}
static void F_24 ( struct V_10 * V_11 , int V_55 )
{
int V_26 , V_56 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
int V_57 = F_1 ( V_11 -> V_2 , V_58 + V_26 ) ;
int V_59 = V_57 & V_60 ;
if ( V_59 >= V_30 && V_59 <= V_61 ) {
for ( V_56 = 0 ; V_56 < V_11 -> V_31 ; V_56 ++ ) {
if ( V_59 == V_11 -> V_32 [ V_56 ] . V_33 ) {
F_25 ( V_11 -> V_62 ,
V_11 -> V_32 [ V_56 ] . V_63 ,
V_57 & V_64 ) ;
break;
}
}
} else {
F_26 ( V_11 -> V_62 ,
V_11 -> V_65 [ V_59 - 1 ] ,
V_57 & V_64 ) ;
}
}
}
static void F_27 ( struct V_66 * V_67 )
{
struct V_10 * V_11 = F_28 ( V_67 ,
struct V_10 , V_67 . V_67 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_68 , V_55 ;
V_68 = F_1 ( V_2 , V_69 ) ;
if ( V_68 & V_70 )
F_3 ( & V_2 -> V_5 , L_6 ) ;
if ( V_68 & V_71 ) {
V_55 = F_1 ( V_2 , V_72 ) & V_73 ;
if ( V_55 ) {
F_24 ( V_11 , V_55 ) ;
F_29 ( V_11 -> V_62 ) ;
}
}
F_4 ( V_2 , V_69 , V_68 ) ;
}
static T_2 F_30 ( int V_74 , void * V_75 )
{
struct V_10 * V_11 = V_75 ;
F_31 ( & V_11 -> V_67 , V_11 -> V_76 ) ;
return V_77 ;
}
static int F_32 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 =
F_17 ( & V_2 -> V_5 ) ;
const struct V_35 * V_36 = V_22 -> V_36 ;
int V_26 , V_4 ;
unsigned char V_78 = 0 , V_79 = 0 , V_80 = 0 ;
V_4 = F_4 ( V_2 , V_81 , F_33 ( V_22 -> V_27 ) ) ;
V_4 |= F_4 ( V_2 , V_82 , F_33 ( V_22 -> V_28 ) & 0xFF ) ;
V_4 |= F_4 ( V_2 , V_83 , F_33 ( V_22 -> V_28 ) >> 8 ) ;
if ( V_22 -> V_84 ) {
V_4 |= F_4 ( V_2 , V_85 , V_22 -> V_86 ) ;
V_4 |= F_4 ( V_2 , V_87 , V_22 -> V_88 ) ;
V_4 |= F_4 ( V_2 , V_72 , V_89 ) ;
}
for ( V_26 = 0 ; V_26 < V_90 ; V_26 ++ )
V_4 |= F_1 ( V_2 , V_58 ) ;
for ( V_26 = 0 ; V_26 < V_22 -> V_31 ; V_26 ++ ) {
unsigned short V_33 = V_22 -> V_32 [ V_26 ] . V_33 ;
if ( V_33 <= V_91 ) {
V_78 |= ( 1 << ( V_33 - V_92 ) ) ;
} else {
V_79 |= ( ( 1 << ( V_33 - V_29 ) ) & 0xFF ) ;
V_80 |= ( ( 1 << ( V_33 - V_29 ) ) >> 8 ) ;
}
}
if ( V_22 -> V_31 ) {
V_4 |= F_4 ( V_2 , V_93 , V_78 ) ;
V_4 |= F_4 ( V_2 , V_94 , V_79 ) ;
V_4 |= F_4 ( V_2 , V_95 , V_80 ) ;
}
if ( V_36 ) {
for ( V_26 = 0 ; V_26 <= F_8 ( V_24 ) ; V_26 ++ ) {
int V_96 = V_36 -> V_97 ;
V_4 |= F_4 ( V_2 , V_98 + V_26 ,
( V_96 >> ( 8 * V_26 ) ) & 0xFF ) ;
}
}
V_4 |= F_4 ( V_2 , V_69 ,
V_99 | V_100 |
V_70 | V_101 |
V_102 | V_71 ) ;
V_4 |= F_4 ( V_2 , V_103 , V_104 |
V_105 |
V_106 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 , L_7 ) ;
return V_4 ;
}
return 0 ;
}
static void F_34 ( struct V_10 * V_11 )
{
int V_107 = F_1 ( V_11 -> V_2 , V_18 ) ;
int V_108 = F_1 ( V_11 -> V_2 , V_109 ) ;
int V_110 = F_1 ( V_11 -> V_2 , V_111 ) ;
int V_112 , V_113 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_11 -> V_31 ; V_26 ++ ) {
unsigned short V_33 = V_11 -> V_32 [ V_26 ] . V_33 ;
if ( V_33 <= V_91 ) {
V_112 = V_107 ;
V_113 = V_33 - V_92 ;
} else if ( ( V_33 - V_29 ) < 8 ) {
V_112 = V_108 ;
V_113 = V_33 - V_29 ;
} else {
V_112 = V_110 ;
V_113 = V_33 - V_29 - 8 ;
}
if ( V_112 < 0 ) {
F_3 ( & V_11 -> V_2 -> V_5 ,
L_8 ,
V_33 ) ;
V_112 = 0 ;
}
F_25 ( V_11 -> V_62 ,
V_11 -> V_32 [ V_26 ] . V_63 ,
! ( V_112 & ( 1 << V_113 ) ) ) ;
}
F_29 ( V_11 -> V_62 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_114 * V_115 )
{
struct V_10 * V_11 ;
const struct V_21 * V_22 =
F_17 ( & V_2 -> V_5 ) ;
struct V_116 * V_62 ;
unsigned int V_117 ;
int V_4 , V_26 ;
int error ;
if ( ! F_36 ( V_2 -> V_118 ,
V_119 ) ) {
F_3 ( & V_2 -> V_5 , L_9 ) ;
return - V_120 ;
}
if ( ! V_22 ) {
F_3 ( & V_2 -> V_5 , L_10 ) ;
return - V_121 ;
}
if ( ! V_22 -> V_27 || ! V_22 -> V_28 || ! V_22 -> V_122 ) {
F_3 ( & V_2 -> V_5 , L_11 ) ;
return - V_121 ;
}
if ( V_22 -> V_123 != V_124 ) {
F_3 ( & V_2 -> V_5 , L_12 ) ;
return - V_121 ;
}
if ( ! V_22 -> V_32 && V_22 -> V_31 ) {
F_3 ( & V_2 -> V_5 , L_13 ) ;
return - V_121 ;
}
if ( V_22 -> V_31 > V_125 ) {
F_3 ( & V_2 -> V_5 , L_14 ) ;
return - V_121 ;
}
for ( V_26 = 0 ; V_26 < V_22 -> V_31 ; V_26 ++ ) {
unsigned short V_33 = V_22 -> V_32 [ V_26 ] . V_33 ;
if ( V_33 < V_30 || V_33 > V_61 ) {
F_3 ( & V_2 -> V_5 , L_15 ) ;
return - V_121 ;
}
if ( V_33 <= V_91 ) {
if ( V_33 - V_92 + 1 <= V_22 -> V_27 ) {
F_3 ( & V_2 -> V_5 , L_16 ) ;
return - V_121 ;
}
} else {
if ( V_33 - V_29 + 1 <= V_22 -> V_28 ) {
F_3 ( & V_2 -> V_5 , L_17 ) ;
return - V_121 ;
}
}
}
if ( ! V_2 -> V_74 ) {
F_3 ( & V_2 -> V_5 , L_18 ) ;
return - V_121 ;
}
V_11 = F_37 ( sizeof( * V_11 ) , V_126 ) ;
V_62 = F_38 () ;
if ( ! V_11 || ! V_62 ) {
error = - V_127 ;
goto V_128;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_62 = V_62 ;
F_39 ( & V_11 -> V_67 , F_27 ) ;
V_4 = F_1 ( V_2 , V_129 ) ;
if ( V_4 < 0 ) {
error = V_4 ;
goto V_128;
}
V_117 = ( T_1 ) V_4 & V_130 ;
if ( F_40 ( V_117 ) )
V_11 -> V_76 = F_41 ( 30 ) ;
V_62 -> V_48 = V_2 -> V_48 ;
V_62 -> V_131 = L_19 ;
V_62 -> V_5 . V_132 = & V_2 -> V_5 ;
F_42 ( V_62 , V_11 ) ;
V_62 -> V_115 . V_133 = V_134 ;
V_62 -> V_115 . V_135 = 0x0001 ;
V_62 -> V_115 . V_136 = 0x0001 ;
V_62 -> V_115 . V_137 = V_117 ;
V_62 -> V_138 = sizeof( V_11 -> V_65 [ 0 ] ) ;
V_62 -> V_139 = V_22 -> V_123 ;
V_62 -> V_65 = V_11 -> V_65 ;
memcpy ( V_11 -> V_65 , V_22 -> V_122 ,
V_22 -> V_123 * V_62 -> V_138 ) ;
V_11 -> V_32 = V_22 -> V_32 ;
V_11 -> V_31 = V_22 -> V_31 ;
F_43 ( V_140 , V_62 -> V_141 ) ;
if ( V_22 -> V_142 )
F_43 ( V_143 , V_62 -> V_141 ) ;
for ( V_26 = 0 ; V_26 < V_62 -> V_139 ; V_26 ++ )
if ( V_11 -> V_65 [ V_26 ] <= V_144 )
F_43 ( V_11 -> V_65 [ V_26 ] , V_62 -> V_145 ) ;
F_44 ( V_146 , V_62 -> V_145 ) ;
if ( V_11 -> V_31 )
F_43 ( V_147 , V_62 -> V_141 ) ;
for ( V_26 = 0 ; V_26 < V_11 -> V_31 ; V_26 ++ )
F_43 ( V_11 -> V_32 [ V_26 ] . V_63 , V_62 -> V_148 ) ;
error = F_45 ( V_62 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 , L_20 ) ;
goto V_128;
}
error = F_46 ( V_2 -> V_74 , F_30 ,
V_149 ,
V_2 -> V_5 . V_150 -> V_48 , V_11 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 , L_21 , V_2 -> V_74 ) ;
goto V_151;
}
error = F_32 ( V_2 ) ;
if ( error )
goto V_152;
if ( V_11 -> V_31 )
F_34 ( V_11 ) ;
error = F_16 ( V_11 ) ;
if ( error )
goto V_152;
F_47 ( & V_2 -> V_5 , 1 ) ;
F_48 ( V_2 , V_11 ) ;
F_18 ( & V_2 -> V_5 , L_22 , V_117 , V_2 -> V_74 ) ;
return 0 ;
V_152:
F_49 ( V_2 -> V_74 , V_11 ) ;
F_50 ( & V_11 -> V_67 ) ;
V_151:
F_51 ( V_62 ) ;
V_62 = NULL ;
V_128:
F_52 ( V_62 ) ;
F_53 ( V_11 ) ;
return error ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_55 ( V_2 ) ;
F_4 ( V_2 , V_103 , 0 ) ;
F_49 ( V_2 -> V_74 , V_11 ) ;
F_50 ( & V_11 -> V_67 ) ;
F_51 ( V_11 -> V_62 ) ;
F_22 ( V_11 ) ;
F_53 ( V_11 ) ;
return 0 ;
}
static int F_56 ( struct V_34 * V_5 )
{
struct V_10 * V_11 = F_57 ( V_5 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_58 ( V_2 -> V_74 ) ;
F_50 ( & V_11 -> V_67 ) ;
if ( F_59 ( & V_2 -> V_5 ) )
F_60 ( V_2 -> V_74 ) ;
return 0 ;
}
static int F_61 ( struct V_34 * V_5 )
{
struct V_10 * V_11 = F_57 ( V_5 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( F_59 ( & V_2 -> V_5 ) )
F_62 ( V_2 -> V_74 ) ;
F_63 ( V_2 -> V_74 ) ;
return 0 ;
}
