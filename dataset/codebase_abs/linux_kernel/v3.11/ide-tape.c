static struct V_1 * F_1 ( struct V_2 * V_3 , bool V_4 ,
unsigned int V_5 )
{
struct V_1 * V_6 = NULL ;
F_2 ( & V_7 ) ;
if ( V_4 )
V_6 = V_8 [ V_5 ] ;
else
V_6 = F_3 ( V_3 , V_1 ) ;
if ( V_6 ) {
if ( F_4 ( V_6 -> V_9 ) )
V_6 = NULL ;
else
F_5 ( & V_6 -> V_10 ) ;
}
F_6 ( & V_7 ) ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_6 )
{
T_1 * V_9 = V_6 -> V_9 ;
F_2 ( & V_7 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_9 ( V_9 ) ;
F_6 ( & V_7 ) ;
}
static void F_10 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_15 * V_16 = V_9 -> V_17 -> V_16 ;
T_3 * V_18 = F_11 ( V_16 -> V_19 ) ;
V_6 -> V_20 = V_18 [ 2 ] & 0xF ;
V_6 -> V_21 = V_18 [ 12 ] ;
V_6 -> V_22 = V_18 [ 13 ] ;
F_12 ( V_23 ,
L_1 ,
V_16 -> V_24 [ 0 ] , V_6 -> V_20 , V_6 -> V_21 , V_6 -> V_22 ) ;
if ( V_13 -> V_25 & V_26 )
V_16 -> V_27 = V_6 -> V_28 * F_13 ( & V_18 [ 3 ] ) ;
if ( ( V_13 -> V_29 [ 0 ] == V_30 || V_13 -> V_29 [ 0 ] == V_31 )
&& V_13 -> V_29 [ 4 ] == 0 && V_13 -> V_29 [ 3 ] == 0 && V_13 -> V_29 [ 2 ] == 0 ) {
if ( V_6 -> V_20 == 5 ) {
V_13 -> error = 0 ;
V_13 -> V_25 |= V_32 ;
}
}
if ( V_13 -> V_29 [ 0 ] == V_30 && ( V_18 [ 2 ] & 0x80 ) ) {
V_13 -> error = V_33 ;
V_13 -> V_25 |= V_32 ;
}
if ( V_13 -> V_29 [ 0 ] == V_31 ) {
if ( ( V_18 [ 2 ] & 0x40 ) || ( V_6 -> V_20 == 0xd
&& V_6 -> V_21 == 0x0 && V_6 -> V_22 == 0x2 ) ) {
V_13 -> error = V_34 ;
V_13 -> V_25 |= V_32 ;
}
}
if ( V_13 -> V_29 [ 0 ] == V_30 || V_13 -> V_29 [ 0 ] == V_31 ) {
if ( V_6 -> V_20 == 8 ) {
V_13 -> error = V_34 ;
V_13 -> V_25 |= V_32 ;
}
if ( ! ( V_13 -> V_25 & V_32 ) &&
( F_14 ( V_16 ) - V_16 -> V_27 ) )
V_13 -> V_35 = V_36 + 1 ;
}
}
static int F_15 ( T_1 * V_9 , int V_37 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 * V_13 = V_9 -> V_13 ;
struct V_15 * V_16 = V_9 -> V_17 -> V_16 ;
int V_38 = V_13 -> error ? 0 : 1 ;
int V_39 = V_38 ? 0 : V_40 ;
F_12 ( V_23 , L_2 , V_16 -> V_24 [ 0 ] ,
V_37 , V_39 ) ;
if ( V_37 )
F_16 ( V_9 ) ;
if ( V_9 -> V_14 == V_13 )
V_9 -> V_14 = NULL ;
if ( V_13 -> V_29 [ 0 ] == V_41 ) {
if ( V_38 )
F_10 ( V_9 ) ;
else
F_17 ( V_42 L_3
L_4 ) ;
} else if ( V_13 -> V_29 [ 0 ] == V_30 || V_13 -> V_29 [ 0 ] == V_31 ) {
unsigned int V_43 =
( F_14 ( V_16 ) - V_16 -> V_27 ) / V_6 -> V_28 ;
V_6 -> V_44 += V_43 * V_6 -> V_28 ;
if ( F_18 ( V_45 , V_6 -> V_46 + V_47 ) ) {
V_6 -> V_48 = V_6 -> V_44 * V_47 /
( V_45 - V_6 -> V_46 ) / 1024 ;
V_6 -> V_44 = 0 ;
V_6 -> V_46 = V_45 ;
}
V_6 -> V_49 += V_43 ;
if ( V_13 -> error ) {
V_38 = 0 ;
V_39 = V_13 -> error ;
}
}
V_16 -> V_50 = V_39 ;
return V_38 ;
}
static void F_19 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
F_12 ( V_23 , L_5 ,
V_9 -> V_17 -> V_16 -> V_24 [ 0 ] , V_6 -> V_51 ) ;
V_6 -> V_52 = true ;
F_20 ( V_9 , V_6 -> V_51 ) ;
}
static void F_16 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
V_6 -> V_53 = V_45 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_55 = V_45 + V_56 ;
F_19 ( V_9 ) ;
}
static T_4 F_21 ( T_1 * V_9 ,
struct V_57 * V_24 ,
struct V_12 * V_13 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_15 * V_16 = V_9 -> V_17 -> V_16 ;
if ( V_9 -> V_14 == NULL && V_13 -> V_29 [ 0 ] != V_41 )
V_9 -> V_14 = V_13 ;
V_9 -> V_13 = V_13 ;
if ( V_13 -> V_35 > V_36 ||
( V_13 -> V_25 & V_32 ) ) {
if ( ! ( V_13 -> V_25 & V_32 ) ) {
if ( ! ( V_13 -> V_29 [ 0 ] == V_58 &&
V_6 -> V_20 == 2 && V_6 -> V_21 == 4 &&
( V_6 -> V_22 == 1 || V_6 -> V_22 == 8 ) ) ) {
F_17 ( V_42 L_6
L_7
L_8 ,
V_6 -> V_59 , V_13 -> V_29 [ 0 ] ,
V_6 -> V_20 , V_6 -> V_21 ,
V_6 -> V_22 ) ;
}
V_13 -> error = V_40 ;
}
V_9 -> V_14 = NULL ;
V_9 -> V_60 ( V_9 , 0 ) ;
F_22 ( V_9 , - V_61 , F_14 ( V_16 ) ) ;
return V_62 ;
}
F_12 ( V_63 , L_9 , V_13 -> V_35 ,
V_13 -> V_29 [ 0 ] ) ;
V_13 -> V_35 ++ ;
return F_23 ( V_9 , V_24 ) ;
}
static void F_24 ( struct V_12 * V_13 , T_3 V_64 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_65 ;
if ( V_64 != V_66 )
V_13 -> V_29 [ 1 ] = 8 ;
V_13 -> V_29 [ 2 ] = V_64 ;
V_13 -> V_29 [ 3 ] = 0 ;
V_13 -> V_29 [ 4 ] = 255 ;
if ( V_64 == V_66 )
V_13 -> V_67 = 12 ;
else if ( V_64 == V_68 )
V_13 -> V_67 = 24 ;
else
V_13 -> V_67 = 50 ;
}
static T_4 F_26 ( T_1 * V_9 )
{
T_5 * V_17 = V_9 -> V_17 ;
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 * V_13 = V_9 -> V_13 ;
T_3 V_69 ;
V_69 = V_17 -> V_70 -> V_71 ( V_17 ) ;
if ( V_69 & V_72 ) {
if ( V_69 & V_73 ) {
if ( V_13 -> V_29 [ 0 ] != V_58 )
F_17 ( V_42 L_6 ,
V_6 -> V_59 ) ;
F_27 ( V_9 ) ;
return V_62 ;
}
V_13 -> error = 0 ;
} else {
V_13 -> error = V_40 ;
V_9 -> V_14 = NULL ;
}
V_9 -> V_60 ( V_9 , 0 ) ;
return V_62 ;
}
static void F_28 ( T_2 * V_6 ,
struct V_12 * V_13 , struct V_15 * V_16 ,
T_3 V_74 )
{
unsigned int V_75 = F_29 ( V_16 ) / ( V_6 -> V_28 >> 9 ) ;
F_25 ( V_13 ) ;
F_30 ( F_31 ( V_75 ) , ( unsigned int * ) & V_13 -> V_29 [ 1 ] ) ;
V_13 -> V_29 [ 1 ] = 1 ;
if ( F_14 ( V_16 ) == V_6 -> V_76 )
V_13 -> V_25 |= V_77 ;
if ( V_74 == V_30 )
V_13 -> V_29 [ 0 ] = V_30 ;
else if ( V_74 == V_31 ) {
V_13 -> V_29 [ 0 ] = V_31 ;
V_13 -> V_25 |= V_78 ;
}
memcpy ( V_16 -> V_24 , V_13 -> V_29 , 12 ) ;
}
static T_4 F_32 ( T_1 * V_9 ,
struct V_15 * V_16 , T_6 V_79 )
{
T_5 * V_17 = V_9 -> V_17 ;
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 * V_13 = NULL ;
struct V_57 V_24 ;
T_3 V_69 ;
F_12 ( V_80 , L_10 ,
V_16 -> V_24 [ 0 ] , ( unsigned long long ) F_33 ( V_16 ) ,
F_29 ( V_16 ) ) ;
F_34 ( ! ( V_16 -> V_81 == V_82 ||
V_16 -> V_81 == V_83 ) ) ;
if ( V_9 -> V_14 && V_9 -> V_13 -> V_29 [ 0 ] == V_41 ) {
V_13 = V_9 -> V_14 ;
goto V_84;
}
V_69 = V_17 -> V_70 -> V_71 ( V_17 ) ;
if ( ( V_9 -> V_85 & V_86 ) == 0 &&
( V_16 -> V_24 [ 13 ] & V_87 ) == 0 )
V_9 -> V_88 |= V_89 ;
if ( V_9 -> V_85 & V_90 ) {
V_9 -> V_88 |= V_89 ;
V_9 -> V_85 &= ~ V_90 ;
}
if ( ! ( V_9 -> V_88 & V_89 ) &&
! ( V_69 & V_72 ) ) {
if ( ! V_6 -> V_52 ) {
V_6 -> V_53 = V_45 ;
V_6 -> V_51 = V_6 -> V_91 ;
V_6 -> V_55 = V_45 + V_92 ;
} else if ( F_35 ( V_45 , V_6 -> V_55 ) ) {
F_17 ( V_42 L_11 ,
V_6 -> V_59 ) ;
if ( V_16 -> V_24 [ 13 ] & V_87 ) {
F_26 ( V_9 ) ;
return V_62 ;
} else {
return F_36 ( V_9 ) ;
}
} else if ( F_35 ( V_45 ,
V_6 -> V_53 +
V_93 ) )
V_6 -> V_51 = V_94 ;
F_19 ( V_9 ) ;
return V_62 ;
} else {
V_9 -> V_88 &= ~ V_89 ;
V_6 -> V_52 = false ;
}
if ( V_16 -> V_24 [ 13 ] & V_95 ) {
V_13 = & V_6 -> V_96 ;
F_28 ( V_6 , V_13 , V_16 , V_30 ) ;
goto V_84;
}
if ( V_16 -> V_24 [ 13 ] & V_97 ) {
V_13 = & V_6 -> V_96 ;
F_28 ( V_6 , V_13 , V_16 , V_31 ) ;
goto V_84;
}
if ( V_16 -> V_24 [ 13 ] & V_98 ) {
V_13 = (struct V_12 * ) V_16 -> V_99 ;
V_16 -> V_24 [ 13 ] &= ~ ( V_98 ) ;
V_16 -> V_24 [ 13 ] |= V_87 ;
goto V_84;
}
if ( V_16 -> V_24 [ 13 ] & V_87 ) {
F_26 ( V_9 ) ;
return V_62 ;
}
F_37 () ;
V_84:
F_38 ( V_9 , V_16 ) ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
if ( F_39 ( V_16 ) )
V_24 . V_100 |= V_101 ;
V_24 . V_16 = V_16 ;
F_40 ( & V_24 , F_14 ( V_16 ) ) ;
F_41 ( V_9 , & V_24 ) ;
return F_21 ( V_9 , & V_24 , V_13 ) ;
}
static void F_42 ( T_1 * V_9 ,
struct V_12 * V_13 , int V_102 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_103 ;
V_13 -> V_29 [ 4 ] = V_102 ;
V_13 -> V_25 |= V_104 ;
}
static int F_43 ( T_1 * V_9 , unsigned long V_105 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_2 * V_3 = V_6 -> V_3 ;
int V_106 = 0 ;
F_44 ( F_45 ( V_107 ) , & V_9 -> V_88 ) ;
V_105 += V_45 ;
while ( F_46 ( V_45 , V_105 ) ) {
if ( F_47 ( V_9 , V_3 ) == 0 )
return 0 ;
if ( ( V_6 -> V_20 == 2 && V_6 -> V_21 == 4 && V_6 -> V_22 == 2 )
|| ( V_6 -> V_21 == 0x3A ) ) {
if ( V_106 )
return - V_108 ;
F_48 ( V_9 , V_3 , V_109 ) ;
V_106 = 1 ;
} else if ( ! ( V_6 -> V_20 == 2 && V_6 -> V_21 == 4 &&
( V_6 -> V_22 == 1 || V_6 -> V_22 == 8 ) ) )
return - V_61 ;
F_49 ( 100 ) ;
}
return - V_61 ;
}
static int F_50 ( T_1 * V_9 )
{
struct V_1 * V_6 = V_9 -> V_11 ;
struct V_12 V_13 ;
int V_110 ;
F_42 ( V_9 , & V_13 , 0 ) ;
V_110 = F_51 ( V_9 , V_6 -> V_3 , & V_13 , NULL , 0 ) ;
if ( V_110 )
return V_110 ;
F_43 ( V_9 , 60 * 5 * V_47 ) ;
return 0 ;
}
static int F_52 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 V_13 ;
T_3 V_111 [ 20 ] ;
F_12 ( V_23 , L_12 ) ;
F_25 ( & V_13 ) ;
V_13 . V_29 [ 0 ] = V_112 ;
V_13 . V_67 = 20 ;
if ( F_51 ( V_9 , V_6 -> V_3 , & V_13 , V_111 , V_13 . V_67 ) )
return - 1 ;
if ( ! V_13 . error ) {
F_12 ( V_23 , L_13 ,
( V_111 [ 0 ] & 0x80 ) ? L_14 : L_15 ) ;
F_12 ( V_23 , L_16 ,
( V_111 [ 0 ] & 0x40 ) ? L_14 : L_15 ) ;
if ( V_111 [ 0 ] & 0x4 ) {
F_17 ( V_113 L_17
L_18 ) ;
F_53 ( F_45 ( V_114 ) ,
& V_9 -> V_88 ) ;
return - 1 ;
} else {
F_12 ( V_23 , L_19 ,
F_54 ( ( V_115 * ) & V_111 [ 4 ] ) ) ;
V_6 -> V_116 = V_111 [ 1 ] ;
V_6 -> V_49 = F_54 ( ( V_115 * ) & V_111 [ 4 ] ) ;
F_44 ( F_45 ( V_114 ) ,
& V_9 -> V_88 ) ;
}
}
return V_6 -> V_49 ;
}
static void F_55 ( T_1 * V_9 ,
struct V_12 * V_13 ,
unsigned int V_79 , T_3 V_116 , int V_117 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_118 ;
V_13 -> V_29 [ 1 ] = 2 ;
F_30 ( F_31 ( V_79 ) , ( unsigned int * ) & V_13 -> V_29 [ 3 ] ) ;
V_13 -> V_29 [ 8 ] = V_116 ;
V_13 -> V_25 |= V_104 ;
}
static void F_56 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
if ( V_6 -> V_119 != V_120 )
return;
F_53 ( F_45 ( V_121 ) , & V_9 -> V_88 ) ;
V_6 -> V_122 = 0 ;
if ( V_6 -> V_111 != NULL ) {
F_57 ( V_6 -> V_111 ) ;
V_6 -> V_111 = NULL ;
}
V_6 -> V_119 = V_123 ;
}
static int F_58 ( T_1 * V_9 , unsigned int V_79 ,
T_3 V_116 , int V_117 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_2 * V_3 = V_6 -> V_3 ;
int V_124 ;
struct V_12 V_13 ;
if ( V_6 -> V_119 == V_120 )
F_56 ( V_9 ) ;
F_43 ( V_9 , 60 * 5 * V_47 ) ;
F_55 ( V_9 , & V_13 , V_79 , V_116 , V_117 ) ;
V_124 = F_51 ( V_9 , V_3 , & V_13 , NULL , 0 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_52 ( V_9 ) ;
if ( V_124 < 0 )
return V_124 ;
return 0 ;
}
static void F_59 ( T_1 * V_9 ,
int V_125 )
{
T_2 * V_6 = V_9 -> V_11 ;
int V_126 , V_127 ;
F_56 ( V_9 ) ;
if ( V_125 ) {
V_127 = F_52 ( V_9 ) ;
V_126 = V_127 > 0 ? V_127 : 0 ;
if ( F_58 ( V_9 , V_126 , 0 , 0 ) ) {
F_17 ( V_113 L_20
L_21 , V_6 -> V_59 , V_128 ) ;
return;
}
}
}
static int F_60 ( T_1 * V_9 , int V_24 , int V_129 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_15 * V_16 ;
int V_124 ;
F_12 ( V_23 , L_22 , V_24 , V_129 ) ;
F_34 ( V_24 != V_95 && V_24 != V_97 ) ;
F_34 ( V_129 < 0 || V_129 % V_6 -> V_28 ) ;
V_16 = F_61 ( V_9 -> V_130 , V_131 , V_132 ) ;
V_16 -> V_81 = V_82 ;
V_16 -> V_24 [ 13 ] = V_24 ;
V_16 -> V_133 = V_6 -> V_3 ;
V_16 -> V_134 = V_6 -> V_49 ;
if ( V_129 ) {
V_124 = F_62 ( V_9 -> V_130 , V_16 , V_6 -> V_111 , V_129 ,
V_132 ) ;
if ( V_124 )
goto V_135;
}
F_63 ( V_9 -> V_130 , V_6 -> V_3 , V_16 , 0 ) ;
V_129 -= V_16 -> V_27 ;
V_6 -> V_136 = V_6 -> V_111 ;
if ( V_24 == V_95 )
V_6 -> V_122 = V_129 ;
else
V_6 -> V_122 = 0 ;
V_124 = V_129 ;
if ( V_16 -> V_50 == V_40 )
V_124 = - V_61 ;
V_135:
F_64 ( V_16 ) ;
return V_124 ;
}
static void F_65 ( struct V_12 * V_13 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_137 ;
V_13 -> V_29 [ 4 ] = 254 ;
V_13 -> V_67 = 254 ;
}
static void F_66 ( T_1 * V_9 ,
struct V_12 * V_13 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_138 ;
V_13 -> V_25 |= V_104 ;
}
static void F_67 ( struct V_12 * V_13 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_139 ;
V_13 -> V_29 [ 1 ] = 1 ;
V_13 -> V_25 |= V_104 ;
}
static void F_68 ( struct V_12 * V_13 , int V_140 , T_3 V_24 )
{
F_25 ( V_13 ) ;
V_13 -> V_29 [ 0 ] = V_141 ;
F_30 ( F_31 ( V_140 ) , ( unsigned int * ) & V_13 -> V_29 [ 1 ] ) ;
V_13 -> V_29 [ 1 ] = V_24 ;
V_13 -> V_25 |= V_104 ;
}
static void F_69 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
if ( V_6 -> V_119 != V_142 ) {
F_17 ( V_42 L_23
L_24 ) ;
return;
}
if ( V_6 -> V_111 ) {
T_7 V_143 = F_70 ( V_6 -> V_122 , V_6 -> V_28 ) ;
memset ( V_6 -> V_136 , 0 , V_143 - V_6 -> V_122 ) ;
F_60 ( V_9 , V_97 , V_143 ) ;
F_57 ( V_6 -> V_111 ) ;
V_6 -> V_111 = NULL ;
}
V_6 -> V_119 = V_123 ;
}
static int F_71 ( T_1 * V_9 , int V_144 )
{
T_2 * V_6 = V_9 -> V_11 ;
int V_110 ;
F_34 ( V_144 != V_120 && V_144 != V_142 ) ;
if ( V_6 -> V_119 == V_144 )
return 0 ;
if ( V_6 -> V_119 == V_120 )
F_59 ( V_9 , 1 ) ;
else if ( V_6 -> V_119 == V_142 ) {
F_69 ( V_9 ) ;
F_50 ( V_9 ) ;
}
if ( V_6 -> V_111 || V_6 -> V_122 ) {
F_17 ( V_42 L_25 ) ;
V_6 -> V_122 = 0 ;
}
V_6 -> V_111 = F_72 ( V_6 -> V_76 , V_145 ) ;
if ( ! V_6 -> V_111 )
return - V_146 ;
V_6 -> V_119 = V_144 ;
V_6 -> V_136 = V_6 -> V_111 ;
if ( V_9 -> V_85 & V_86 ) {
int V_24 = V_144 == V_120 ? V_95
: V_97 ;
V_110 = F_60 ( V_9 , V_24 , 0 ) ;
if ( V_110 < 0 ) {
F_57 ( V_6 -> V_111 ) ;
V_6 -> V_111 = NULL ;
V_6 -> V_119 = V_123 ;
return V_110 ;
}
}
return 0 ;
}
static void F_73 ( T_1 * V_9 , int V_147 )
{
T_2 * V_6 = V_9 -> V_11 ;
memset ( V_6 -> V_111 , 0 , V_6 -> V_76 ) ;
while ( V_147 ) {
unsigned int V_140 = F_74 ( V_6 -> V_76 , V_147 ) ;
F_60 ( V_9 , V_97 , V_140 ) ;
V_147 -= V_140 ;
}
}
static int F_75 ( T_1 * V_9 )
{
struct V_1 * V_6 = V_9 -> V_11 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_12 V_13 ;
int V_124 ;
F_12 ( V_23 , L_12 ) ;
F_66 ( V_9 , & V_13 ) ;
V_124 = F_51 ( V_9 , V_3 , & V_13 , NULL , 0 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_52 ( V_9 ) ;
if ( V_124 < 0 )
return V_124 ;
return 0 ;
}
static int F_76 ( T_1 * V_9 , unsigned int V_24 ,
unsigned long V_148 )
{
T_2 * V_6 = V_9 -> V_11 ;
void T_8 * V_149 = ( void T_8 * ) V_148 ;
struct V_150 {
int V_151 ;
int V_152 ;
int V_153 ;
} V_154 ;
F_12 ( V_23 , L_26 , V_24 ) ;
switch ( V_24 ) {
case 0x0340 :
if ( F_77 ( & V_154 , V_149 , sizeof( V_154 ) ) )
return - V_155 ;
V_6 -> V_91 = V_154 . V_151 ;
break;
case 0x0350 :
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_151 = ( int ) V_6 -> V_91 ;
V_154 . V_153 = 1 ;
if ( F_78 ( V_149 , & V_154 , sizeof( V_154 ) ) )
return - V_155 ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_79 ( T_1 * V_9 , short V_156 ,
int V_157 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_12 V_13 ;
int V_158 , V_140 = 0 ;
int V_159 = ! ! ( V_6 -> V_160 [ 4 ] & 0x20 ) ;
F_12 ( V_23 , L_27 , V_156 , V_157 ) ;
if ( V_157 == 0 )
return 0 ;
if ( V_161 == V_156 || V_162 == V_156 ) {
if ( ! V_159 )
return - V_61 ;
V_157 = - V_157 ;
}
if ( V_6 -> V_119 == V_120 ) {
V_6 -> V_122 = 0 ;
if ( F_80 ( F_45 ( V_121 ) ,
& V_9 -> V_88 ) )
++ V_140 ;
F_59 ( V_9 , 0 ) ;
}
switch ( V_156 ) {
case V_163 :
case V_161 :
F_68 ( & V_13 , V_157 - V_140 ,
V_164 ) ;
return F_51 ( V_9 , V_3 , & V_13 , NULL , 0 ) ;
case V_165 :
case V_162 :
if ( ! V_159 )
return - V_61 ;
V_158 = F_79 ( V_9 , V_163 ,
V_157 - V_140 ) ;
if ( V_158 )
return V_158 ;
V_140 = ( V_162 == V_156 ? 1 : - 1 ) ;
return F_79 ( V_9 , V_163 , V_140 ) ;
default:
F_17 ( V_42 L_28 ,
V_156 ) ;
return - V_61 ;
}
}
static T_9 F_81 ( struct V_166 * V_166 , char T_8 * V_111 ,
T_7 V_140 , T_10 * V_167 )
{
struct V_1 * V_6 = V_166 -> V_168 ;
T_1 * V_9 = V_6 -> V_9 ;
T_7 V_169 = 0 ;
T_9 V_124 = 0 ;
int V_110 ;
F_12 ( V_23 , L_29 , V_140 ) ;
if ( V_6 -> V_119 != V_120 ) {
if ( F_82 ( F_45 ( V_170 ) , & V_9 -> V_88 ) )
if ( V_140 > V_6 -> V_28 &&
( V_140 % V_6 -> V_28 ) == 0 )
V_6 -> V_171 = V_140 / V_6 -> V_28 ;
}
V_110 = F_71 ( V_9 , V_120 ) ;
if ( V_110 < 0 )
return V_110 ;
while ( V_169 < V_140 ) {
T_7 V_172 ;
if ( ! V_6 -> V_122 ) {
if ( F_82 ( F_45 ( V_121 ) ,
& V_9 -> V_88 ) )
break;
if ( F_60 ( V_9 , V_95 ,
V_6 -> V_76 ) <= 0 )
break;
}
V_172 = F_83 ( T_7 , V_140 - V_169 , V_6 -> V_122 ) ;
if ( F_78 ( V_111 + V_169 , V_6 -> V_136 , V_172 ) )
V_124 = - V_155 ;
V_6 -> V_136 += V_172 ;
V_6 -> V_122 -= V_172 ;
V_169 += V_172 ;
}
if ( ! V_169 && F_82 ( F_45 ( V_121 ) , & V_9 -> V_88 ) ) {
F_79 ( V_9 , V_163 , 1 ) ;
return 0 ;
}
return V_124 ? V_124 : V_169 ;
}
static T_9 F_84 ( struct V_166 * V_166 , const char T_8 * V_111 ,
T_7 V_140 , T_10 * V_167 )
{
struct V_1 * V_6 = V_166 -> V_168 ;
T_1 * V_9 = V_6 -> V_9 ;
T_7 V_169 = 0 ;
T_9 V_124 = 0 ;
int V_110 ;
if ( V_6 -> V_173 )
return - V_174 ;
F_12 ( V_23 , L_29 , V_140 ) ;
V_110 = F_71 ( V_9 , V_142 ) ;
if ( V_110 < 0 )
return V_110 ;
while ( V_169 < V_140 ) {
T_7 V_172 ;
if ( V_6 -> V_122 == V_6 -> V_76 &&
F_60 ( V_9 , V_97 ,
V_6 -> V_76 ) <= 0 )
return V_110 ;
V_172 = F_83 ( T_7 , V_140 - V_169 ,
V_6 -> V_76 - V_6 -> V_122 ) ;
if ( F_77 ( V_6 -> V_136 , V_111 + V_169 , V_172 ) )
V_124 = - V_155 ;
V_6 -> V_136 += V_172 ;
V_6 -> V_122 += V_172 ;
V_169 += V_172 ;
}
return V_124 ? V_124 : V_169 ;
}
static int F_85 ( T_1 * V_9 )
{
struct V_1 * V_6 = V_9 -> V_11 ;
struct V_12 V_13 ;
F_42 ( V_9 , & V_13 , 1 ) ;
if ( F_51 ( V_9 , V_6 -> V_3 , & V_13 , NULL , 0 ) ) {
F_17 ( V_42 L_30 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_86 ( T_1 * V_9 , short V_156 , int V_157 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_12 V_13 ;
int V_5 , V_158 ;
F_12 ( V_23 , L_31 ,
V_156 , V_157 ) ;
switch ( V_156 ) {
case V_163 :
case V_165 :
case V_161 :
case V_162 :
if ( ! V_157 )
return 0 ;
return F_79 ( V_9 , V_156 , V_157 ) ;
default:
break;
}
switch ( V_156 ) {
case V_175 :
if ( V_6 -> V_173 )
return - V_174 ;
F_59 ( V_9 , 1 ) ;
for ( V_5 = 0 ; V_5 < V_157 ; V_5 ++ ) {
V_158 = F_85 ( V_9 ) ;
if ( V_158 )
return V_158 ;
}
return 0 ;
case V_176 :
F_59 ( V_9 , 0 ) ;
if ( F_75 ( V_9 ) )
return - V_61 ;
return 0 ;
case V_177 :
F_59 ( V_9 , 0 ) ;
return F_48 ( V_9 , V_3 , V_109 ) ;
case V_178 :
case V_179 :
if ( V_6 -> V_180 ) {
if ( ! F_87 ( V_9 , V_3 , 0 ) )
V_6 -> V_180 = V_181 ;
}
F_59 ( V_9 , 0 ) ;
V_158 = F_48 ( V_9 , V_3 , ! V_109 ) ;
if ( ! V_158 )
F_53 ( F_45 ( V_107 ) ,
& V_9 -> V_88 ) ;
return V_158 ;
case V_182 :
F_59 ( V_9 , 0 ) ;
return F_50 ( V_9 ) ;
case V_183 :
F_59 ( V_9 , 0 ) ;
return F_48 ( V_9 , V_3 ,
V_184 | V_109 ) ;
case V_185 :
F_68 ( & V_13 , 0 , V_186 ) ;
return F_51 ( V_9 , V_3 , & V_13 , NULL , 0 ) ;
case V_187 :
( void ) F_75 ( V_9 ) ;
F_67 ( & V_13 ) ;
return F_51 ( V_9 , V_3 , & V_13 , NULL , 0 ) ;
case V_188 :
if ( V_157 ) {
if ( V_157 < V_6 -> V_28 ||
V_157 % V_6 -> V_28 )
return - V_61 ;
V_6 -> V_171 = V_157 / V_6 -> V_28 ;
F_53 ( F_45 ( V_170 ) ,
& V_9 -> V_88 ) ;
} else
F_44 ( F_45 ( V_170 ) ,
& V_9 -> V_88 ) ;
return 0 ;
case V_189 :
F_59 ( V_9 , 0 ) ;
return F_58 ( V_9 ,
V_157 * V_6 -> V_171 , V_6 -> V_116 , 0 ) ;
case V_190 :
F_59 ( V_9 , 0 ) ;
return F_58 ( V_9 , 0 , V_157 , 0 ) ;
case V_191 :
case V_192 :
case V_193 :
V_158 = F_87 ( V_9 , V_3 , 1 ) ;
if ( V_158 )
return V_158 ;
V_6 -> V_180 = V_194 ;
return 0 ;
case V_195 :
V_158 = F_87 ( V_9 , V_3 , 0 ) ;
if ( V_158 )
return V_158 ;
V_6 -> V_180 = V_181 ;
return 0 ;
default:
F_17 ( V_42 L_28 ,
V_156 ) ;
return - V_61 ;
}
}
static long F_88 ( struct V_166 * V_166 ,
unsigned int V_24 , unsigned long V_148 )
{
struct V_1 * V_6 = V_166 -> V_168 ;
T_1 * V_9 = V_6 -> V_9 ;
struct V_196 V_196 ;
struct V_197 V_197 ;
struct V_198 V_198 ;
int V_199 = 0 , V_127 = V_6 -> V_49 ;
void T_8 * V_149 = ( void T_8 * ) V_148 ;
F_12 ( V_23 , L_32 , V_24 ) ;
if ( V_6 -> V_119 == V_142 ) {
F_69 ( V_9 ) ;
F_50 ( V_9 ) ;
}
if ( V_24 == V_200 || V_24 == V_201 ) {
V_199 = V_6 -> V_122 /
( V_6 -> V_28 * V_6 -> V_171 ) ;
V_127 = F_52 ( V_9 ) ;
if ( V_127 < 0 )
return - V_61 ;
}
switch ( V_24 ) {
case V_202 :
if ( F_77 ( & V_196 , V_149 , sizeof( struct V_196 ) ) )
return - V_155 ;
return F_86 ( V_9 , V_196 . V_156 , V_196 . V_157 ) ;
case V_200 :
memset ( & V_197 , 0 , sizeof( struct V_197 ) ) ;
V_197 . V_203 = V_204 ;
V_197 . V_205 = V_127 / V_6 -> V_171 - V_199 ;
V_197 . V_206 =
( ( V_6 -> V_28 * V_6 -> V_171 )
<< V_207 ) & V_208 ;
if ( V_6 -> V_209 )
V_197 . V_210 |= F_89 ( 0xffffffff ) ;
if ( F_78 ( V_149 , & V_197 , sizeof( struct V_197 ) ) )
return - V_155 ;
return 0 ;
case V_201 :
V_198 . V_205 = V_127 / V_6 -> V_171 - V_199 ;
if ( F_78 ( V_149 , & V_198 , sizeof( struct V_198 ) ) )
return - V_155 ;
return 0 ;
default:
if ( V_6 -> V_119 == V_120 )
F_59 ( V_9 , 1 ) ;
return F_76 ( V_9 , V_24 , V_148 ) ;
}
}
static long F_90 ( struct V_166 * V_166 ,
unsigned int V_24 , unsigned long V_148 )
{
long V_124 ;
F_2 ( & V_211 ) ;
V_124 = F_88 ( V_166 , V_24 , V_148 ) ;
F_6 ( & V_211 ) ;
return V_124 ;
}
static void F_91 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 V_13 ;
T_3 V_111 [ 12 ] ;
F_24 ( & V_13 , V_66 ) ;
if ( F_51 ( V_9 , V_6 -> V_3 , & V_13 , V_111 , V_13 . V_67 ) ) {
F_17 ( V_42 L_33 ) ;
if ( V_6 -> V_28 == 0 ) {
F_17 ( V_212 L_34
L_35 ) ;
V_6 -> V_28 = 32768 ;
}
return;
}
V_6 -> V_28 = ( V_111 [ 4 + 5 ] << 16 ) +
( V_111 [ 4 + 6 ] << 8 ) +
V_111 [ 4 + 7 ] ;
V_6 -> V_209 = ( V_111 [ 2 ] & 0x80 ) >> 7 ;
F_12 ( V_23 , L_36 ,
V_6 -> V_28 , V_6 -> V_209 ) ;
}
static int F_92 ( struct V_213 * V_213 , struct V_166 * V_214 )
{
unsigned int V_215 = F_93 ( V_213 ) , V_5 = V_215 & ~ 0xc0 ;
T_1 * V_9 ;
T_2 * V_6 ;
int V_158 ;
if ( V_5 >= V_216 * V_217 )
return - V_218 ;
F_2 ( & V_219 ) ;
V_6 = F_1 ( NULL , true , V_5 ) ;
if ( ! V_6 ) {
F_6 ( & V_219 ) ;
return - V_218 ;
}
V_9 = V_6 -> V_9 ;
V_214 -> V_168 = V_6 ;
F_12 ( V_23 , L_12 ) ;
V_214 -> V_220 &= ~ ( V_221 | V_222 ) ;
if ( F_94 ( F_45 ( V_223 ) , & V_9 -> V_88 ) ) {
V_158 = - V_224 ;
goto V_225;
}
V_158 = F_43 ( V_9 , 60 * V_47 ) ;
if ( V_158 ) {
F_53 ( F_45 ( V_223 ) , & V_9 -> V_88 ) ;
F_17 ( V_42 L_37 , V_6 -> V_59 ) ;
goto V_225;
}
F_52 ( V_9 ) ;
if ( ! F_82 ( F_45 ( V_114 ) , & V_9 -> V_88 ) )
( void ) F_75 ( V_9 ) ;
F_91 ( V_9 ) ;
if ( ( V_214 -> V_226 & V_227 ) == V_228 )
V_6 -> V_173 = 1 ;
else
V_6 -> V_173 = V_6 -> V_209 ;
if ( V_6 -> V_173 ) {
if ( ( V_214 -> V_226 & V_227 ) == V_229 ||
( V_214 -> V_226 & V_227 ) == V_230 ) {
F_53 ( F_45 ( V_223 ) , & V_9 -> V_88 ) ;
V_158 = - V_231 ;
goto V_225;
}
}
if ( V_6 -> V_119 == V_123 ) {
if ( ! F_87 ( V_9 , V_6 -> V_3 , 1 ) ) {
if ( V_6 -> V_180 != V_194 )
V_6 -> V_180 = V_232 ;
}
}
F_6 ( & V_219 ) ;
return 0 ;
V_225:
F_7 ( V_6 ) ;
F_6 ( & V_219 ) ;
return V_158 ;
}
static void F_95 ( T_1 * V_9 , unsigned int V_215 )
{
T_2 * V_6 = V_9 -> V_11 ;
F_69 ( V_9 ) ;
V_6 -> V_111 = F_72 ( V_6 -> V_76 , V_145 ) ;
if ( V_6 -> V_111 != NULL ) {
F_73 ( V_9 , V_6 -> V_28 *
( V_6 -> V_171 - 1 ) ) ;
F_57 ( V_6 -> V_111 ) ;
V_6 -> V_111 = NULL ;
}
F_85 ( V_9 ) ;
F_50 ( V_9 ) ;
F_50 ( V_9 ) ;
}
static int F_96 ( struct V_213 * V_213 , struct V_166 * V_214 )
{
struct V_1 * V_6 = V_214 -> V_168 ;
T_1 * V_9 = V_6 -> V_9 ;
unsigned int V_215 = F_93 ( V_213 ) ;
F_2 ( & V_219 ) ;
V_6 = V_9 -> V_11 ;
F_12 ( V_23 , L_12 ) ;
if ( V_6 -> V_119 == V_142 )
F_95 ( V_9 , V_215 ) ;
if ( V_6 -> V_119 == V_120 ) {
if ( V_215 < 128 )
F_59 ( V_9 , 1 ) ;
}
if ( V_215 < 128 && F_82 ( F_45 ( V_107 ) ,
& V_9 -> V_88 ) )
( void ) F_75 ( V_9 ) ;
if ( V_6 -> V_119 == V_123 ) {
if ( V_6 -> V_180 == V_232 ) {
if ( ! F_87 ( V_9 , V_6 -> V_3 , 0 ) )
V_6 -> V_180 = V_181 ;
}
}
F_53 ( F_45 ( V_223 ) , & V_9 -> V_88 ) ;
F_7 ( V_6 ) ;
F_6 ( & V_219 ) ;
return 0 ;
}
static void F_97 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 V_13 ;
T_3 V_233 [ 256 ] ;
char V_234 [ 4 ] , V_235 [ 8 ] , V_236 [ 16 ] ;
F_65 ( & V_13 ) ;
if ( F_51 ( V_9 , V_6 -> V_3 , & V_13 , V_233 , V_13 . V_67 ) ) {
F_17 ( V_42 L_38 ,
V_6 -> V_59 ) ;
return;
}
memcpy ( V_235 , & V_233 [ 8 ] , 8 ) ;
memcpy ( V_236 , & V_233 [ 16 ] , 16 ) ;
memcpy ( V_234 , & V_233 [ 32 ] , 4 ) ;
F_98 ( V_235 , 8 , 0 ) ;
F_98 ( V_236 , 16 , 0 ) ;
F_98 ( V_234 , 4 , 0 ) ;
F_17 ( V_113 L_39 ,
V_9 -> V_59 , V_6 -> V_59 , V_235 , V_236 , V_234 ) ;
}
static void F_99 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
struct V_12 V_13 ;
T_3 V_111 [ 24 ] , * V_160 ;
T_3 V_237 , V_238 ;
F_24 ( & V_13 , V_68 ) ;
if ( F_51 ( V_9 , V_6 -> V_3 , & V_13 , V_111 , V_13 . V_67 ) ) {
F_17 ( V_42 L_40
L_41 ) ;
V_6 -> V_28 = 512 ;
F_30 ( 52 , ( V_239 * ) & V_6 -> V_160 [ 12 ] ) ;
F_30 ( 540 , ( V_239 * ) & V_6 -> V_160 [ 14 ] ) ;
F_30 ( 6 * 52 , ( V_239 * ) & V_6 -> V_160 [ 16 ] ) ;
return;
}
V_160 = V_111 + 4 + V_111 [ 3 ] ;
V_237 = F_100 ( ( V_240 * ) & V_160 [ 14 ] ) ;
V_238 = F_100 ( ( V_240 * ) & V_160 [ 8 ] ) ;
* ( V_239 * ) & V_160 [ 8 ] = V_238 ;
* ( V_239 * ) & V_160 [ 12 ] = F_100 ( ( V_240 * ) & V_160 [ 12 ] ) ;
* ( V_239 * ) & V_160 [ 14 ] = V_237 ;
* ( V_239 * ) & V_160 [ 16 ] = F_100 ( ( V_240 * ) & V_160 [ 16 ] ) ;
if ( ! V_237 ) {
F_17 ( V_113 L_42
L_43 , V_9 -> V_59 ) ;
* ( V_239 * ) & V_160 [ 14 ] = 650 ;
}
if ( ! V_238 ) {
F_17 ( V_113 L_44
L_43 , V_9 -> V_59 ) ;
* ( V_239 * ) & V_160 [ 8 ] = 650 ;
}
memcpy ( & V_6 -> V_160 , V_160 , 20 ) ;
if ( ( V_160 [ 6 ] & 1 ) == 0 )
V_9 -> V_85 &= ~ V_241 ;
if ( V_160 [ 7 ] & 0x02 )
V_6 -> V_28 = 512 ;
else if ( V_160 [ 7 ] & 0x04 )
V_6 -> V_28 = 1024 ;
}
static int F_101 ( T_1 * V_9 ) { return 1000 ; }
static int F_102 ( T_1 * V_9 ) { return V_47 ; }
static int F_103 ( T_1 * V_9 ) { return 2 ; }
static int F_104 ( T_1 * V_9 ) { return 1024 ; }
static void F_105 ( T_1 * V_9 , T_2 * V_6 , int V_215 )
{
unsigned long V_242 ;
int V_237 ;
int V_76 ;
V_239 * V_243 = ( V_239 * ) & V_6 -> V_160 [ 12 ] ;
F_12 ( V_23 , L_45 , V_215 ) ;
V_9 -> V_60 = F_15 ;
V_9 -> V_85 |= V_86 ;
if ( V_9 -> V_17 -> V_244 & V_245 ) {
F_17 ( V_113 L_46 ,
V_6 -> V_59 ) ;
V_9 -> V_85 &= ~ V_86 ;
}
if ( strstr ( ( char * ) & V_9 -> V_246 [ V_247 ] , L_47 ) )
V_9 -> V_85 &= ~ V_86 ;
V_6 -> V_215 = V_215 ;
V_6 -> V_59 [ 0 ] = 'h' ;
V_6 -> V_59 [ 1 ] = 't' ;
V_6 -> V_59 [ 2 ] = '0' + V_215 ;
V_6 -> V_119 = V_123 ;
F_97 ( V_9 ) ;
F_99 ( V_9 ) ;
F_91 ( V_9 ) ;
V_6 -> V_171 = 1 ;
V_6 -> V_76 = * V_243 * V_6 -> V_28 ;
while ( V_6 -> V_76 > 0xffff ) {
F_17 ( V_248 L_48 ) ;
* V_243 /= 2 ;
V_6 -> V_76 = * V_243 * V_6 -> V_28 ;
}
V_76 = V_6 -> V_76 ;
V_237 = F_106 ( * ( V_239 * ) & V_6 -> V_160 [ 14 ] , * ( V_239 * ) & V_6 -> V_160 [ 8 ] ) ;
V_242 = ( V_249 * V_6 -> V_76 * V_47 ) / ( V_237 * 1000 ) ;
V_6 -> V_91 = F_107 (unsigned long, t, IDETAPE_DSC_RW_MIN,
IDETAPE_DSC_RW_MAX) ;
F_17 ( V_113 L_49
L_50 ,
V_9 -> V_59 , V_6 -> V_59 , * ( V_239 * ) & V_6 -> V_160 [ 14 ] ,
( * ( V_239 * ) & V_6 -> V_160 [ 16 ] * 512 ) / V_6 -> V_76 ,
V_6 -> V_76 / 1024 ,
V_6 -> V_91 * 1000 / V_47 ,
( V_9 -> V_85 & V_250 ) ? L_51 : L_52 ) ;
F_108 ( V_9 , V_6 -> V_251 ) ;
}
static void F_109 ( T_1 * V_9 )
{
T_2 * V_6 = V_9 -> V_11 ;
F_110 ( V_9 , V_6 -> V_251 ) ;
F_111 ( & V_6 -> V_10 ) ;
F_112 ( V_6 -> V_3 ) ;
F_2 ( & V_7 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_6 ( & V_7 ) ;
}
static void F_113 ( struct V_252 * V_10 )
{
struct V_1 * V_6 = F_114 ( V_10 , V_1 ) ;
T_1 * V_9 = V_6 -> V_9 ;
struct V_2 * V_253 = V_6 -> V_3 ;
F_34 ( V_6 -> V_122 ) ;
V_9 -> V_85 &= ~ V_86 ;
V_9 -> V_11 = NULL ;
F_115 ( V_254 , F_116 ( V_255 , V_6 -> V_215 ) ) ;
F_115 ( V_254 ,
F_116 ( V_255 , V_6 -> V_215 + 128 ) ) ;
V_8 [ V_6 -> V_215 ] = NULL ;
V_253 -> V_168 = NULL ;
F_117 ( V_253 ) ;
F_57 ( V_6 ) ;
}
static int F_118 ( struct V_256 * V_257 , void * V_258 )
{
T_1 * V_9 = ( T_1 * ) V_257 -> V_259 ;
T_2 * V_6 = V_9 -> V_11 ;
F_119 ( V_257 , L_53 , V_6 -> V_59 ) ;
return 0 ;
}
static int F_120 ( struct V_213 * V_213 , struct V_166 * V_166 )
{
return F_121 ( V_166 , F_118 , F_122 ( V_213 ) ) ;
}
static T_11 * F_123 ( T_1 * V_9 )
{
return V_260 ;
}
static const struct V_261 * F_124 ( T_1 * V_9 )
{
return V_262 ;
}
static int F_125 ( struct V_263 * V_264 , T_12 V_265 )
{
struct V_1 * V_6 ;
F_2 ( & V_211 ) ;
V_6 = F_1 ( V_264 -> V_266 , false , 0 ) ;
F_6 ( & V_211 ) ;
if ( ! V_6 )
return - V_218 ;
return 0 ;
}
static void F_126 ( struct V_2 * V_3 , T_12 V_265 )
{
struct V_1 * V_6 = F_3 ( V_3 , V_1 ) ;
F_2 ( & V_211 ) ;
F_7 ( V_6 ) ;
F_6 ( & V_211 ) ;
}
static int F_127 ( struct V_263 * V_264 , T_12 V_265 ,
unsigned int V_24 , unsigned long V_148 )
{
struct V_1 * V_6 = F_3 ( V_264 -> V_266 , V_1 ) ;
T_1 * V_9 = V_6 -> V_9 ;
int V_39 ;
F_2 ( & V_211 ) ;
V_39 = F_128 ( V_9 , V_264 , V_24 , V_148 ) ;
if ( V_39 == - V_267 )
V_39 = F_76 ( V_9 , V_24 , V_148 ) ;
F_6 ( & V_211 ) ;
return V_39 ;
}
static int F_129 ( T_1 * V_9 )
{
T_2 * V_6 ;
struct V_2 * V_253 ;
int V_215 ;
F_12 ( V_23 , L_12 ) ;
if ( ! strstr ( V_268 , V_9 -> V_269 ) )
goto V_270;
if ( V_9 -> V_271 != V_272 )
goto V_270;
if ( ( V_9 -> V_85 & V_273 ) &&
F_130 ( V_9 , V_268 ) == 0 ) {
F_17 ( V_42 L_54
L_55 , V_9 -> V_59 ) ;
goto V_270;
}
V_6 = F_131 ( sizeof( T_2 ) , V_145 ) ;
if ( V_6 == NULL ) {
F_17 ( V_42 L_56 ,
V_9 -> V_59 ) ;
goto V_270;
}
V_253 = F_132 ( 1 << V_274 ) ;
if ( ! V_253 )
goto V_275;
F_133 ( V_253 , V_9 ) ;
V_6 -> V_10 . V_276 = & V_9 -> V_277 ;
V_6 -> V_10 . V_278 = F_113 ;
F_134 ( & V_6 -> V_10 , L_57 , F_135 ( & V_9 -> V_277 ) ) ;
if ( F_136 ( & V_6 -> V_10 ) )
goto V_279;
V_6 -> V_9 = V_9 ;
V_6 -> V_251 = & V_280 ;
V_6 -> V_3 = V_253 ;
V_253 -> V_168 = & V_6 -> V_251 ;
V_9 -> V_11 = V_6 ;
F_2 ( & V_7 ) ;
for ( V_215 = 0 ; V_8 [ V_215 ] ; V_215 ++ )
;
V_8 [ V_215 ] = V_6 ;
F_6 ( & V_7 ) ;
F_105 ( V_9 , V_6 , V_215 ) ;
F_137 ( V_254 , & V_9 -> V_277 ,
F_116 ( V_255 , V_215 ) , NULL , L_57 , V_6 -> V_59 ) ;
F_137 ( V_254 , & V_9 -> V_277 ,
F_116 ( V_255 , V_215 + 128 ) , NULL ,
L_58 , V_6 -> V_59 ) ;
V_253 -> V_281 = & V_282 ;
F_138 ( V_253 ) ;
return 0 ;
V_279:
F_117 ( V_253 ) ;
V_275:
F_57 ( V_6 ) ;
V_270:
return - V_283 ;
}
static void T_13 F_139 ( void )
{
F_140 ( & V_280 . V_284 ) ;
F_141 ( V_254 ) ;
F_142 ( V_255 , L_59 ) ;
}
static int T_14 F_143 ( void )
{
int error = 1 ;
V_254 = F_144 ( V_285 , L_60 ) ;
if ( F_145 ( V_254 ) ) {
V_254 = NULL ;
F_17 ( V_42 L_61 ) ;
error = - V_224 ;
goto V_84;
}
if ( F_146 ( V_255 , L_59 , & V_286 ) ) {
F_17 ( V_42 L_62
L_63 ) ;
error = - V_224 ;
goto V_287;
}
error = F_147 ( & V_280 . V_284 ) ;
if ( error )
goto V_288;
return 0 ;
V_288:
F_140 ( & V_280 . V_284 ) ;
V_287:
F_141 ( V_254 ) ;
V_84:
return error ;
}
