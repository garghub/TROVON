static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_5 ( V_2 ) ;
F_1 ( V_2 , V_9 , V_10 ) ;
V_8 = V_11 | F_7 ( V_2 -> V_12 ) | V_13 ;
if ( ! ( V_2 -> V_14 -> V_15 & V_16 ) )
V_8 |= V_17 ;
F_1 ( V_2 , V_8 , V_18 ) ;
}
static void F_8 ( struct V_1 * V_2 , int error )
{
unsigned int V_19 ;
V_2 -> V_20 = 0 ;
V_2 -> V_14 = NULL ;
V_2 -> error = error ;
if ( V_2 -> V_21 ) {
F_1 ( V_2 , V_22 , V_10 ) ;
V_2 -> V_23 = V_24 ;
V_19 = F_3 ( V_2 , V_18 ) ;
V_19 |= V_25 ;
F_1 ( V_2 , V_19 , V_18 ) ;
} else {
V_2 -> V_26 = false ;
V_2 -> V_23 = V_27 ;
F_1 ( V_2 , 0 , V_18 ) ;
F_9 ( & V_2 -> V_28 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_29 = V_2 -> V_14 -> V_29 - V_2 -> V_20 ;
T_1 V_30 ;
V_30 = F_3 ( V_2 , V_18 ) ;
if ( V_29 > 32 ) {
V_29 = 32 ;
V_30 &= ~ V_31 ;
} else {
V_30 |= V_31 ;
}
if ( V_2 -> V_20 != 0 ) {
V_30 &= ~ V_32 ;
V_30 |= F_7 ( V_33 ) ;
}
F_1 ( V_2 , V_30 , V_18 ) ;
F_1 ( V_2 , V_29 , V_34 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_35 , V_36 ;
T_1 V_37 = 0 ;
T_1 V_8 ;
T_2 V_38 ;
for ( V_35 = 0 ; V_35 < 8 ; ++ V_35 ) {
V_8 = 0 ;
for ( V_36 = 0 ; V_36 < 4 ; ++ V_36 ) {
if ( ( V_2 -> V_20 == V_2 -> V_14 -> V_29 ) && ( V_37 != 0 ) )
break;
if ( V_2 -> V_20 == 0 && V_37 == 0 )
V_38 = ( V_2 -> V_39 & 0x7f ) << 1 ;
else
V_38 = V_2 -> V_14 -> V_40 [ V_2 -> V_20 ++ ] ;
V_8 |= V_38 << ( V_36 * 8 ) ;
V_37 ++ ;
}
F_1 ( V_2 , V_8 , V_41 + 4 * V_35 ) ;
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
break;
}
F_1 ( V_2 , V_37 , V_42 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_43 )
{
if ( ! ( V_43 & V_9 ) ) {
F_8 ( V_2 , - V_44 ) ;
F_13 ( V_2 -> V_45 , L_1 , V_43 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_9 , V_7 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_18 ) & ~ V_13 , V_18 ) ;
if ( V_2 -> V_12 == V_46 ) {
F_1 ( V_2 , V_47 | V_48 , V_10 ) ;
V_2 -> V_23 = V_49 ;
F_11 ( V_2 ) ;
} else {
F_1 ( V_2 , V_50 | V_48 , V_10 ) ;
V_2 -> V_23 = V_51 ;
F_10 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_43 )
{
if ( ! ( V_43 & V_47 ) ) {
F_8 ( V_2 , - V_44 ) ;
F_15 ( V_2 -> V_45 , L_2 , V_43 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_47 , V_7 ) ;
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
F_8 ( V_2 , V_2 -> error ) ;
else
F_11 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_35 ;
unsigned int V_29 = V_2 -> V_14 -> V_29 - V_2 -> V_20 ;
T_1 V_52 ( V_8 ) ;
T_2 V_38 ;
if ( ! ( V_43 & V_50 ) )
return;
F_1 ( V_2 , V_50 , V_7 ) ;
if ( V_29 > 32 )
V_29 = 32 ;
for ( V_35 = 0 ; V_35 < V_29 ; ++ V_35 ) {
if ( V_35 % 4 == 0 )
V_8 = F_3 ( V_2 , V_53 + ( V_35 / 4 ) * 4 ) ;
V_38 = ( V_8 >> ( ( V_35 % 4 ) * 8 ) ) & 0xff ;
V_2 -> V_14 -> V_40 [ V_2 -> V_20 ++ ] = V_38 ;
}
if ( V_2 -> V_20 == V_2 -> V_14 -> V_29 )
F_8 ( V_2 , V_2 -> error ) ;
else
F_10 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_30 ;
if ( ! ( V_43 & V_22 ) ) {
F_8 ( V_2 , - V_44 ) ;
F_15 ( V_2 -> V_45 , L_3 , V_43 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_22 , V_7 ) ;
V_30 = F_3 ( V_2 , V_18 ) ;
V_30 &= ~ V_25 ;
F_1 ( V_2 , V_30 , V_18 ) ;
V_2 -> V_26 = false ;
V_2 -> V_23 = V_27 ;
F_9 ( & V_2 -> V_28 ) ;
}
static T_3 F_18 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
unsigned int V_43 ;
F_19 ( & V_2 -> V_56 ) ;
V_43 = F_3 ( V_2 , V_7 ) ;
if ( V_2 -> V_23 == V_27 ) {
F_13 ( V_2 -> V_45 , L_4 , V_43 ) ;
F_5 ( V_2 ) ;
goto V_57;
}
F_20 ( V_2 -> V_45 , L_5 , V_2 -> V_23 , V_43 ) ;
V_43 &= ~ ( V_58 | V_59 ) ;
if ( V_43 & V_48 ) {
F_1 ( V_2 , V_48 , V_7 ) ;
V_43 &= ~ V_48 ;
if ( ! ( V_2 -> V_14 -> V_15 & V_16 ) )
F_8 ( V_2 , - V_60 ) ;
}
if ( ( V_43 & V_6 ) == 0 )
goto V_57;
switch ( V_2 -> V_23 ) {
case V_61 :
F_12 ( V_2 , V_43 ) ;
break;
case V_49 :
F_14 ( V_2 , V_43 ) ;
break;
case V_51 :
F_16 ( V_2 , V_43 ) ;
break;
case V_24 :
F_17 ( V_2 , V_43 ) ;
break;
case V_27 :
break;
}
V_57:
F_21 ( & V_2 -> V_56 ) ;
return V_62 ;
}
static int F_22 ( unsigned long V_63 ,
struct V_64 * V_65 ,
unsigned long * V_66 ,
unsigned long * V_67 )
{
unsigned long V_68 , V_69 ;
unsigned long V_70 , V_71 ;
unsigned long V_72 ;
unsigned long V_73 , V_74 ;
unsigned long V_75 , V_76 ;
unsigned long V_77 , V_78 ;
unsigned long V_79 , V_80 ;
unsigned long V_81 ;
unsigned long V_82 , V_83 ;
unsigned long V_84 , V_85 , V_86 ;
int V_87 = 0 ;
if ( F_23 ( V_65 -> V_88 > 400000 ) )
V_65 -> V_88 = 400000 ;
if ( F_23 ( V_65 -> V_88 < 1000 ) )
V_65 -> V_88 = 1000 ;
if ( V_65 -> V_88 <= 100000 ) {
V_68 = 4700 ;
V_70 = 4700 ;
V_69 = 4000 ;
V_71 = 3450 ;
V_72 = 50 ;
} else {
V_68 = 1300 ;
V_70 = 600 ;
V_69 = 600 ;
V_71 = 900 ;
V_72 = 50 ;
}
V_74 = V_65 -> V_89 + V_69 ;
V_74 = F_24 ( V_74 ,
F_25 ( ( V_65 -> V_89 + V_70 ) * 1000 , 875 ) ) ;
V_74 = F_24 ( V_74 ,
F_25 ( ( V_65 -> V_89 + V_70 +
V_65 -> V_90 + V_69 ) , 2 ) ) ;
V_73 = V_65 -> V_91 + V_68 ;
V_75 = V_71 * 2 - V_72 ;
V_76 = V_73 + V_74 ;
V_77 = F_25 ( V_63 , 1000 ) ;
V_78 = V_65 -> V_88 / 1000 ;
V_83 = F_25 ( V_77 , V_78 * 8 ) ;
V_79 = F_25 ( V_77 * V_73 , 8 * 1000000 ) ;
V_80 = F_25 ( V_77 * V_74 , 8 * 1000000 ) ;
V_82 = ( V_79 + V_80 ) ;
V_81 = V_77 * V_75 / ( 8 * 1000000 ) ;
if ( V_79 > V_81 ) {
F_26 ( true ,
L_6 ,
V_79 , V_81 ) ;
V_81 = V_79 ;
}
if ( V_82 > V_83 ) {
* V_66 = V_79 ;
* V_67 = V_80 ;
} else {
V_84 = V_83 - V_82 ;
V_86 = F_25 ( V_77 * V_73 ,
V_78 * 8 * V_76 ) ;
if ( V_86 > V_81 )
V_86 = V_81 ;
if ( V_86 > V_79 + V_84 )
V_86 = V_79 + V_84 ;
V_85 = V_86 - V_79 ;
* V_66 = V_86 ;
* V_67 = V_80 + ( V_84 - V_85 ) ;
}
* V_66 = * V_66 - 1 ;
* V_67 = * V_67 - 1 ;
if ( * V_66 > 0xffff ) {
* V_66 = 0xffff ;
V_87 = - V_92 ;
}
if ( * V_67 > 0xffff ) {
* V_67 = 0xffff ;
V_87 = - V_92 ;
}
return V_87 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned long V_63 )
{
struct V_64 * V_65 = & V_2 -> V_65 ;
unsigned long V_66 , V_67 ;
T_4 V_93 , V_94 ;
int V_87 ;
V_87 = F_22 ( V_63 , V_65 , & V_66 , & V_67 ) ;
F_26 ( V_87 != 0 , L_7 , V_65 -> V_88 ) ;
F_28 ( V_2 -> V_95 ) ;
F_1 ( V_2 , ( V_67 << 16 ) | ( V_66 & 0xffff ) , V_96 ) ;
F_29 ( V_2 -> V_95 ) ;
V_93 = F_30 ( ( ( T_4 ) V_66 + 1 ) * 8 * 1000000000 , V_63 ) ;
V_94 = F_30 ( ( ( T_4 ) V_67 + 1 ) * 8 * 1000000000 , V_63 ) ;
F_20 ( V_2 -> V_45 ,
L_8 ,
V_63 / 1000 ,
1000000000 / V_65 -> V_88 ,
V_93 , V_94 ) ;
}
static int F_31 ( struct V_97 * V_98 , unsigned long
V_99 , void * V_100 )
{
struct V_101 * V_102 = V_100 ;
struct V_1 * V_2 = F_32 ( V_98 , struct V_1 , V_103 ) ;
unsigned long V_66 , V_67 ;
switch ( V_99 ) {
case V_104 :
if ( F_22 ( V_102 -> V_105 , & V_2 -> V_65 ,
& V_66 , & V_67 ) != 0 )
return V_106 ;
if ( V_102 -> V_105 > V_102 -> V_107 )
F_27 ( V_2 , V_102 -> V_105 ) ;
return V_108 ;
case V_109 :
if ( V_102 -> V_105 < V_102 -> V_107 )
F_27 ( V_2 , V_102 -> V_105 ) ;
return V_108 ;
case V_110 :
if ( V_102 -> V_105 > V_102 -> V_107 )
F_27 ( V_2 , V_102 -> V_107 ) ;
return V_108 ;
default:
return V_111 ;
}
}
static int F_33 ( struct V_1 * V_2 , struct V_112 * V_113 , int V_114 )
{
T_1 V_39 = ( V_113 [ 0 ] . V_39 & 0x7f ) << 1 ;
int V_87 = 0 ;
if ( V_114 >= 2 && V_113 [ 0 ] . V_29 < 4 &&
! ( V_113 [ 0 ] . V_15 & V_115 ) && ( V_113 [ 1 ] . V_15 & V_115 ) ) {
T_1 V_116 = 0 ;
int V_35 ;
F_20 ( V_2 -> V_45 , L_9 ,
V_39 >> 1 ) ;
for ( V_35 = 0 ; V_35 < V_113 [ 0 ] . V_29 ; ++ V_35 ) {
V_116 |= V_113 [ 0 ] . V_40 [ V_35 ] << ( V_35 * 8 ) ;
V_116 |= F_34 ( V_35 ) ;
}
V_2 -> V_14 = & V_113 [ 1 ] ;
V_2 -> V_12 = V_117 ;
F_1 ( V_2 , V_39 | F_34 ( 0 ) , V_118 ) ;
F_1 ( V_2 , V_116 , V_119 ) ;
V_87 = 2 ;
} else {
if ( V_113 [ 0 ] . V_15 & V_115 ) {
V_39 |= 1 ;
V_2 -> V_12 = V_117 ;
F_1 ( V_2 , V_39 | F_34 ( 0 ) ,
V_118 ) ;
F_1 ( V_2 , 0 , V_119 ) ;
} else {
V_2 -> V_12 = V_46 ;
}
V_2 -> V_14 = & V_113 [ 0 ] ;
V_87 = 1 ;
}
V_2 -> V_39 = V_113 [ 0 ] . V_39 ;
V_2 -> V_26 = true ;
V_2 -> V_23 = V_61 ;
V_2 -> V_20 = 0 ;
V_2 -> error = 0 ;
F_5 ( V_2 ) ;
return V_87 ;
}
static int F_35 ( struct V_120 * V_121 ,
struct V_112 * V_113 , int V_114 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 -> V_122 ;
unsigned long V_123 , V_15 ;
int V_87 = 0 ;
int V_35 ;
F_36 ( & V_2 -> V_56 , V_15 ) ;
F_28 ( V_2 -> V_95 ) ;
V_2 -> V_21 = false ;
for ( V_35 = 0 ; V_35 < V_114 ; V_35 += V_87 ) {
V_87 = F_33 ( V_2 , V_113 + V_35 , V_114 - V_35 ) ;
if ( V_87 < 0 ) {
F_15 ( V_2 -> V_45 , L_10 ) ;
break;
}
if ( V_35 + V_87 >= V_114 )
V_2 -> V_21 = true ;
F_37 ( & V_2 -> V_56 , V_15 ) ;
F_6 ( V_2 ) ;
V_123 = F_38 ( V_2 -> V_28 , ! V_2 -> V_26 ,
F_39 ( V_124 ) ) ;
F_36 ( & V_2 -> V_56 , V_15 ) ;
if ( V_123 == 0 ) {
F_15 ( V_2 -> V_45 , L_11 ,
F_3 ( V_2 , V_7 ) , V_2 -> V_23 ) ;
F_1 ( V_2 , 0 , V_10 ) ;
F_1 ( V_2 , V_11 | V_25 , V_18 ) ;
V_2 -> V_23 = V_27 ;
V_87 = - V_125 ;
break;
}
if ( V_2 -> error ) {
V_87 = V_2 -> error ;
break;
}
}
F_29 ( V_2 -> V_95 ) ;
F_37 ( & V_2 -> V_56 , V_15 ) ;
return V_87 < 0 ? V_87 : V_114 ;
}
static T_1 F_40 ( struct V_120 * V_121 )
{
return V_126 | V_127 | V_128 ;
}
static int F_41 ( struct V_129 * V_130 )
{
struct V_131 * V_132 = V_130 -> V_45 . V_133 ;
const struct V_134 * V_135 ;
struct V_1 * V_2 ;
struct V_136 * V_137 ;
int V_87 = 0 ;
int V_138 ;
T_1 V_3 ;
int V_139 ;
unsigned long V_63 ;
V_2 = F_42 ( & V_130 -> V_45 , sizeof( struct V_1 ) , V_140 ) ;
if ( ! V_2 )
return - V_141 ;
V_135 = F_43 ( V_142 , V_132 ) ;
V_2 -> V_143 = (struct V_144 * ) V_135 -> V_100 ;
F_44 ( & V_130 -> V_45 , & V_2 -> V_65 , true ) ;
F_45 ( V_2 -> V_121 . V_145 , L_12 , sizeof( V_2 -> V_121 . V_145 ) ) ;
V_2 -> V_121 . V_146 = V_147 ;
V_2 -> V_121 . V_148 = & V_149 ;
V_2 -> V_121 . V_150 = 3 ;
V_2 -> V_121 . V_45 . V_133 = V_132 ;
V_2 -> V_121 . V_122 = V_2 ;
V_2 -> V_121 . V_45 . V_151 = & V_130 -> V_45 ;
V_2 -> V_45 = & V_130 -> V_45 ;
F_46 ( & V_2 -> V_56 ) ;
F_47 ( & V_2 -> V_28 ) ;
V_2 -> V_95 = F_48 ( & V_130 -> V_45 , NULL ) ;
if ( F_49 ( V_2 -> V_95 ) ) {
F_15 ( & V_130 -> V_45 , L_13 ) ;
return F_50 ( V_2 -> V_95 ) ;
}
V_137 = F_51 ( V_130 , V_152 , 0 ) ;
V_2 -> V_5 = F_52 ( & V_130 -> V_45 , V_137 ) ;
if ( F_49 ( V_2 -> V_5 ) )
return F_50 ( V_2 -> V_5 ) ;
V_138 = F_53 ( V_132 , L_14 ) ;
if ( V_2 -> V_143 -> V_153 >= 0 ) {
struct V_154 * V_155 ;
V_155 = F_54 ( V_132 , L_15 ) ;
if ( F_49 ( V_155 ) ) {
F_15 ( & V_130 -> V_45 ,
L_16 ) ;
return F_50 ( V_155 ) ;
}
if ( V_138 < 0 ) {
F_15 ( & V_130 -> V_45 , L_17 ) ;
return - V_92 ;
}
V_3 = F_55 ( 27 + V_138 ) | F_55 ( 11 + V_138 ) ;
V_87 = F_56 ( V_155 , V_2 -> V_143 -> V_153 , V_3 ) ;
if ( V_87 != 0 ) {
F_15 ( V_2 -> V_45 , L_18 , V_87 ) ;
return V_87 ;
}
}
V_139 = F_57 ( V_130 , 0 ) ;
if ( V_139 < 0 ) {
F_15 ( & V_130 -> V_45 , L_19 ) ;
return V_139 ;
}
V_87 = F_58 ( & V_130 -> V_45 , V_139 , F_18 ,
0 , F_59 ( & V_130 -> V_45 ) , V_2 ) ;
if ( V_87 < 0 ) {
F_15 ( & V_130 -> V_45 , L_20 ) ;
return V_87 ;
}
F_60 ( V_130 , V_2 ) ;
V_87 = F_61 ( V_2 -> V_95 ) ;
if ( V_87 < 0 ) {
F_15 ( & V_130 -> V_45 , L_21 ) ;
return V_87 ;
}
V_2 -> V_103 . V_156 = F_31 ;
V_87 = F_62 ( V_2 -> V_95 , & V_2 -> V_103 ) ;
if ( V_87 != 0 ) {
F_15 ( & V_130 -> V_45 , L_22 ) ;
goto V_157;
}
V_63 = F_63 ( V_2 -> V_95 ) ;
F_27 ( V_2 , V_63 ) ;
V_87 = F_64 ( & V_2 -> V_121 ) ;
if ( V_87 < 0 ) {
F_15 ( & V_130 -> V_45 , L_23 ) ;
goto V_158;
}
F_65 ( & V_130 -> V_45 , L_24 , V_2 -> V_5 ) ;
return 0 ;
V_158:
F_66 ( V_2 -> V_95 , & V_2 -> V_103 ) ;
V_157:
F_67 ( V_2 -> V_95 ) ;
return V_87 ;
}
static int F_68 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_69 ( V_130 ) ;
F_70 ( & V_2 -> V_121 ) ;
F_66 ( V_2 -> V_95 , & V_2 -> V_103 ) ;
F_67 ( V_2 -> V_95 ) ;
return 0 ;
}
