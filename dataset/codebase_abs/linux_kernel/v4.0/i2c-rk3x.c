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
static int F_22 ( unsigned long V_63 , unsigned long V_64 ,
unsigned long V_65 ,
unsigned long V_66 ,
unsigned long V_67 ,
unsigned long * V_68 , unsigned long * V_69 )
{
unsigned long V_70 , V_71 ;
unsigned long V_72 , V_73 ;
unsigned long V_74 ;
unsigned long V_75 , V_76 ;
unsigned long V_77 , V_78 ;
unsigned long V_79 , V_80 ;
unsigned long V_81 , V_82 ;
unsigned long V_83 ;
unsigned long V_84 , V_85 ;
unsigned long V_86 , V_87 , V_88 ;
int V_89 = 0 ;
if ( F_23 ( V_64 > 400000 ) )
V_64 = 400000 ;
if ( F_23 ( V_64 < 1000 ) )
V_64 = 1000 ;
if ( V_64 <= 100000 ) {
V_70 = 4700 ;
V_72 = 4700 ;
V_71 = 4000 ;
V_73 = 3450 ;
V_74 = 50 ;
} else {
V_70 = 1300 ;
V_72 = 600 ;
V_71 = 600 ;
V_73 = 900 ;
V_74 = 50 ;
}
V_76 = V_65 + V_71 ;
V_76 = F_24 ( V_76 ,
F_25 ( ( V_65 + V_72 ) * 1000 , 875 ) ) ;
V_76 = F_24 ( V_76 ,
F_25 ( ( V_65 + V_72 +
V_67 + V_71 ) , 2 ) ) ;
V_75 = V_66 + V_70 ;
V_77 = V_73 * 2 - V_74 ;
V_78 = V_75 + V_76 ;
V_79 = F_25 ( V_63 , 1000 ) ;
V_80 = V_64 / 1000 ;
V_85 = F_25 ( V_79 , V_80 * 8 ) ;
V_81 = F_25 ( V_79 * V_75 , 8 * 1000000 ) ;
V_82 = F_25 ( V_79 * V_76 , 8 * 1000000 ) ;
V_84 = ( V_81 + V_82 ) ;
V_83 = V_79 * V_77 / ( 8 * 1000000 ) ;
if ( V_81 > V_83 ) {
F_26 ( true ,
L_6 ,
V_81 , V_83 ) ;
V_83 = V_81 ;
}
if ( V_84 > V_85 ) {
* V_68 = V_81 ;
* V_69 = V_82 ;
} else {
V_86 = V_85 - V_84 ;
V_88 = F_25 ( V_79 * V_75 ,
V_80 * 8 * V_78 ) ;
if ( V_88 > V_83 )
V_88 = V_83 ;
if ( V_88 > V_81 + V_86 )
V_88 = V_81 + V_86 ;
V_87 = V_88 - V_81 ;
* V_68 = V_88 ;
* V_69 = V_82 + ( V_86 - V_87 ) ;
}
* V_68 = * V_68 - 1 ;
* V_69 = * V_69 - 1 ;
if ( * V_68 > 0xffff ) {
* V_68 = 0xffff ;
V_89 = - V_90 ;
}
if ( * V_69 > 0xffff ) {
* V_69 = 0xffff ;
V_89 = - V_90 ;
}
return V_89 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned long V_63 )
{
unsigned long V_68 , V_69 ;
T_4 V_91 , V_92 ;
int V_89 ;
V_89 = F_22 ( V_63 , V_2 -> V_93 , V_2 -> V_65 ,
V_2 -> V_66 , V_2 -> V_67 ,
& V_68 , & V_69 ) ;
F_26 ( V_89 != 0 , L_7 , V_2 -> V_93 ) ;
F_28 ( V_2 -> V_94 ) ;
F_1 ( V_2 , ( V_69 << 16 ) | ( V_68 & 0xffff ) , V_95 ) ;
F_29 ( V_2 -> V_94 ) ;
V_91 = F_30 ( ( ( T_4 ) V_68 + 1 ) * 8 * 1000000000 , V_63 ) ;
V_92 = F_30 ( ( ( T_4 ) V_69 + 1 ) * 8 * 1000000000 , V_63 ) ;
F_20 ( V_2 -> V_45 ,
L_8 ,
V_63 / 1000 ,
1000000000 / V_2 -> V_93 ,
V_91 , V_92 ) ;
}
static int F_31 ( struct V_96 * V_97 , unsigned long
V_98 , void * V_99 )
{
struct V_100 * V_101 = V_99 ;
struct V_1 * V_2 = F_32 ( V_97 , struct V_1 , V_102 ) ;
unsigned long V_68 , V_69 ;
switch ( V_98 ) {
case V_103 :
if ( F_22 ( V_101 -> V_104 , V_2 -> V_93 ,
V_2 -> V_65 , V_2 -> V_66 ,
V_2 -> V_67 ,
& V_68 , & V_69 ) != 0 )
return V_105 ;
if ( V_101 -> V_104 > V_101 -> V_106 )
F_27 ( V_2 , V_101 -> V_104 ) ;
return V_107 ;
case V_108 :
if ( V_101 -> V_104 < V_101 -> V_106 )
F_27 ( V_2 , V_101 -> V_104 ) ;
return V_107 ;
case V_109 :
if ( V_101 -> V_104 > V_101 -> V_106 )
F_27 ( V_2 , V_101 -> V_106 ) ;
return V_107 ;
default:
return V_110 ;
}
}
static int F_33 ( struct V_1 * V_2 , struct V_111 * V_112 , int V_113 )
{
T_1 V_39 = ( V_112 [ 0 ] . V_39 & 0x7f ) << 1 ;
int V_89 = 0 ;
if ( V_113 >= 2 && V_112 [ 0 ] . V_29 < 4 &&
! ( V_112 [ 0 ] . V_15 & V_114 ) && ( V_112 [ 1 ] . V_15 & V_114 ) ) {
T_1 V_115 = 0 ;
int V_35 ;
F_20 ( V_2 -> V_45 , L_9 ,
V_39 >> 1 ) ;
for ( V_35 = 0 ; V_35 < V_112 [ 0 ] . V_29 ; ++ V_35 ) {
V_115 |= V_112 [ 0 ] . V_40 [ V_35 ] << ( V_35 * 8 ) ;
V_115 |= F_34 ( V_35 ) ;
}
V_2 -> V_14 = & V_112 [ 1 ] ;
V_2 -> V_12 = V_116 ;
F_1 ( V_2 , V_39 | F_34 ( 0 ) , V_117 ) ;
F_1 ( V_2 , V_115 , V_118 ) ;
V_89 = 2 ;
} else {
if ( V_112 [ 0 ] . V_15 & V_114 ) {
V_39 |= 1 ;
V_2 -> V_12 = V_116 ;
F_1 ( V_2 , V_39 | F_34 ( 0 ) ,
V_117 ) ;
F_1 ( V_2 , 0 , V_118 ) ;
} else {
V_2 -> V_12 = V_46 ;
}
V_2 -> V_14 = & V_112 [ 0 ] ;
V_89 = 1 ;
}
V_2 -> V_39 = V_112 [ 0 ] . V_39 ;
V_2 -> V_26 = true ;
V_2 -> V_23 = V_61 ;
V_2 -> V_20 = 0 ;
V_2 -> error = 0 ;
F_5 ( V_2 ) ;
return V_89 ;
}
static int F_35 ( struct V_119 * V_120 ,
struct V_111 * V_112 , int V_113 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 -> V_121 ;
unsigned long V_122 , V_15 ;
int V_89 = 0 ;
int V_35 ;
F_36 ( & V_2 -> V_56 , V_15 ) ;
F_28 ( V_2 -> V_94 ) ;
V_2 -> V_21 = false ;
for ( V_35 = 0 ; V_35 < V_113 ; V_35 += V_89 ) {
V_89 = F_33 ( V_2 , V_112 + V_35 , V_113 - V_35 ) ;
if ( V_89 < 0 ) {
F_15 ( V_2 -> V_45 , L_10 ) ;
break;
}
if ( V_35 + V_89 >= V_113 )
V_2 -> V_21 = true ;
F_37 ( & V_2 -> V_56 , V_15 ) ;
F_6 ( V_2 ) ;
V_122 = F_38 ( V_2 -> V_28 , ! V_2 -> V_26 ,
F_39 ( V_123 ) ) ;
F_36 ( & V_2 -> V_56 , V_15 ) ;
if ( V_122 == 0 ) {
F_15 ( V_2 -> V_45 , L_11 ,
F_3 ( V_2 , V_7 ) , V_2 -> V_23 ) ;
F_1 ( V_2 , 0 , V_10 ) ;
F_1 ( V_2 , V_11 | V_25 , V_18 ) ;
V_2 -> V_23 = V_27 ;
V_89 = - V_124 ;
break;
}
if ( V_2 -> error ) {
V_89 = V_2 -> error ;
break;
}
}
F_29 ( V_2 -> V_94 ) ;
F_37 ( & V_2 -> V_56 , V_15 ) ;
return V_89 ;
}
static T_1 F_40 ( struct V_119 * V_120 )
{
return V_125 | V_126 | V_127 ;
}
static int F_41 ( struct V_128 * V_129 )
{
struct V_130 * V_131 = V_129 -> V_45 . V_132 ;
const struct V_133 * V_134 ;
struct V_1 * V_2 ;
struct V_135 * V_136 ;
int V_89 = 0 ;
int V_137 ;
T_1 V_3 ;
int V_138 ;
unsigned long V_63 ;
V_2 = F_42 ( & V_129 -> V_45 , sizeof( struct V_1 ) , V_139 ) ;
if ( ! V_2 )
return - V_140 ;
V_134 = F_43 ( V_141 , V_131 ) ;
V_2 -> V_142 = (struct V_143 * ) V_134 -> V_99 ;
if ( F_44 ( V_129 -> V_45 . V_132 , L_12 ,
& V_2 -> V_93 ) ) {
F_45 ( & V_129 -> V_45 , L_13 ,
V_144 ) ;
V_2 -> V_93 = V_144 ;
}
if ( V_2 -> V_93 == 0 || V_2 -> V_93 > 400 * 1000 ) {
F_13 ( & V_129 -> V_45 , L_14 ) ;
F_13 ( & V_129 -> V_45 , L_13 ,
V_144 ) ;
V_2 -> V_93 = V_144 ;
}
if ( F_44 ( V_129 -> V_45 . V_132 , L_15 ,
& V_2 -> V_65 ) ) {
if ( V_2 -> V_93 <= 100000 )
V_2 -> V_65 = 1000 ;
else
V_2 -> V_65 = 300 ;
}
if ( F_44 ( V_129 -> V_45 . V_132 , L_16 ,
& V_2 -> V_66 ) )
V_2 -> V_66 = 300 ;
if ( F_44 ( V_129 -> V_45 . V_132 , L_17 ,
& V_2 -> V_66 ) )
V_2 -> V_67 = V_2 -> V_66 ;
F_46 ( V_2 -> V_120 . V_145 , L_18 , sizeof( V_2 -> V_120 . V_145 ) ) ;
V_2 -> V_120 . V_146 = V_147 ;
V_2 -> V_120 . V_148 = & V_149 ;
V_2 -> V_120 . V_150 = 3 ;
V_2 -> V_120 . V_45 . V_132 = V_131 ;
V_2 -> V_120 . V_121 = V_2 ;
V_2 -> V_120 . V_45 . V_151 = & V_129 -> V_45 ;
V_2 -> V_45 = & V_129 -> V_45 ;
F_47 ( & V_2 -> V_56 ) ;
F_48 ( & V_2 -> V_28 ) ;
V_2 -> V_94 = F_49 ( & V_129 -> V_45 , NULL ) ;
if ( F_50 ( V_2 -> V_94 ) ) {
F_15 ( & V_129 -> V_45 , L_19 ) ;
return F_51 ( V_2 -> V_94 ) ;
}
V_136 = F_52 ( V_129 , V_152 , 0 ) ;
V_2 -> V_5 = F_53 ( & V_129 -> V_45 , V_136 ) ;
if ( F_50 ( V_2 -> V_5 ) )
return F_51 ( V_2 -> V_5 ) ;
V_137 = F_54 ( V_131 , L_20 ) ;
if ( V_2 -> V_142 -> V_153 >= 0 ) {
struct V_154 * V_155 ;
V_155 = F_55 ( V_131 , L_21 ) ;
if ( F_50 ( V_155 ) ) {
F_15 ( & V_129 -> V_45 ,
L_22 ) ;
return F_51 ( V_155 ) ;
}
if ( V_137 < 0 ) {
F_15 ( & V_129 -> V_45 , L_23 ) ;
return - V_90 ;
}
V_3 = F_56 ( 27 + V_137 ) | F_56 ( 11 + V_137 ) ;
V_89 = F_57 ( V_155 , V_2 -> V_142 -> V_153 , V_3 ) ;
if ( V_89 != 0 ) {
F_15 ( V_2 -> V_45 , L_24 , V_89 ) ;
return V_89 ;
}
}
V_138 = F_58 ( V_129 , 0 ) ;
if ( V_138 < 0 ) {
F_15 ( & V_129 -> V_45 , L_25 ) ;
return V_138 ;
}
V_89 = F_59 ( & V_129 -> V_45 , V_138 , F_18 ,
0 , F_60 ( & V_129 -> V_45 ) , V_2 ) ;
if ( V_89 < 0 ) {
F_15 ( & V_129 -> V_45 , L_26 ) ;
return V_89 ;
}
F_61 ( V_129 , V_2 ) ;
V_89 = F_62 ( V_2 -> V_94 ) ;
if ( V_89 < 0 ) {
F_15 ( & V_129 -> V_45 , L_27 ) ;
return V_89 ;
}
V_2 -> V_102 . V_156 = F_31 ;
V_89 = F_63 ( V_2 -> V_94 , & V_2 -> V_102 ) ;
if ( V_89 != 0 ) {
F_15 ( & V_129 -> V_45 , L_28 ) ;
goto V_157;
}
V_63 = F_64 ( V_2 -> V_94 ) ;
F_27 ( V_2 , V_63 ) ;
V_89 = F_65 ( & V_2 -> V_120 ) ;
if ( V_89 < 0 ) {
F_15 ( & V_129 -> V_45 , L_29 ) ;
goto V_158;
}
F_45 ( & V_129 -> V_45 , L_30 , V_2 -> V_5 ) ;
return 0 ;
V_158:
F_66 ( V_2 -> V_94 , & V_2 -> V_102 ) ;
V_157:
F_67 ( V_2 -> V_94 ) ;
return V_89 ;
}
static int F_68 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_69 ( V_129 ) ;
F_70 ( & V_2 -> V_120 ) ;
F_66 ( V_2 -> V_94 , & V_2 -> V_102 ) ;
F_67 ( V_2 -> V_94 ) ;
return 0 ;
}
