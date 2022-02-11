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
unsigned long * V_65 , unsigned long * V_66 )
{
unsigned long V_67 , V_68 ;
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 , V_72 ;
unsigned long V_73 , V_74 ;
unsigned long V_75 , V_76 ;
unsigned long V_77 ;
unsigned long V_78 , V_79 ;
unsigned long V_80 , V_81 , V_82 ;
int V_83 = 0 ;
if ( F_23 ( V_64 > 400000 ) )
V_64 = 400000 ;
if ( F_23 ( V_64 < 1000 ) )
V_64 = 1000 ;
if ( V_64 <= 100000 ) {
V_67 = 4700 ;
V_68 = 4000 ;
V_69 = 3450 ;
V_70 = 50 ;
} else {
V_67 = 1300 ;
V_68 = 600 ;
V_69 = 900 ;
V_70 = 50 ;
}
V_71 = V_69 * 2 - V_70 ;
V_72 = V_67 + V_68 ;
V_73 = F_24 ( V_63 , 1000 ) ;
V_74 = V_64 / 1000 ;
V_79 = F_24 ( V_73 , V_74 * 8 ) ;
V_75 = F_24 ( V_73 * V_67 , 8 * 1000000 ) ;
V_76 = F_24 ( V_73 * V_68 , 8 * 1000000 ) ;
V_78 = ( V_75 + V_76 ) ;
V_77 = V_73 * V_71 / ( 8 * 1000000 ) ;
if ( V_75 > V_77 ) {
F_25 ( true ,
L_6 ,
V_75 , V_77 ) ;
V_77 = V_75 ;
}
if ( V_78 > V_79 ) {
* V_65 = V_75 ;
* V_66 = V_76 ;
} else {
V_80 = V_79 - V_78 ;
V_82 = F_24 ( V_73 * V_67 ,
V_74 * 8 * V_72 ) ;
if ( V_82 > V_77 )
V_82 = V_77 ;
if ( V_82 > V_75 + V_80 )
V_82 = V_75 + V_80 ;
V_81 = V_82 - V_75 ;
* V_65 = V_82 ;
* V_66 = V_76 + ( V_80 - V_81 ) ;
}
* V_65 = * V_65 - 1 ;
* V_66 = * V_66 - 1 ;
if ( * V_65 > 0xffff ) {
* V_65 = 0xffff ;
V_83 = - V_84 ;
}
if ( * V_66 > 0xffff ) {
* V_66 = 0xffff ;
V_83 = - V_84 ;
}
return V_83 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned long V_63 )
{
unsigned long V_65 , V_66 ;
T_4 V_85 , V_86 ;
int V_83 ;
V_83 = F_22 ( V_63 , V_2 -> V_87 , & V_65 ,
& V_66 ) ;
F_25 ( V_83 != 0 , L_7 , V_2 -> V_87 ) ;
F_27 ( V_2 -> V_88 ) ;
F_1 ( V_2 , ( V_66 << 16 ) | ( V_65 & 0xffff ) , V_89 ) ;
F_28 ( V_2 -> V_88 ) ;
V_85 = F_29 ( ( ( T_4 ) V_65 + 1 ) * 8 * 1000000000 , V_63 ) ;
V_86 = F_29 ( ( ( T_4 ) V_66 + 1 ) * 8 * 1000000000 , V_63 ) ;
F_20 ( V_2 -> V_45 ,
L_8 ,
V_63 / 1000 ,
1000000000 / V_2 -> V_87 ,
V_85 , V_86 ) ;
}
static int F_30 ( struct V_90 * V_91 , unsigned long
V_92 , void * V_93 )
{
struct V_94 * V_95 = V_93 ;
struct V_1 * V_2 = F_31 ( V_91 , struct V_1 , V_96 ) ;
unsigned long V_65 , V_66 ;
switch ( V_92 ) {
case V_97 :
if ( F_22 ( V_95 -> V_98 , V_2 -> V_87 ,
& V_65 , & V_66 ) != 0 ) {
return V_99 ;
}
if ( V_95 -> V_98 > V_95 -> V_100 )
F_26 ( V_2 , V_95 -> V_98 ) ;
return V_101 ;
case V_102 :
if ( V_95 -> V_98 < V_95 -> V_100 )
F_26 ( V_2 , V_95 -> V_98 ) ;
return V_101 ;
case V_103 :
if ( V_95 -> V_98 > V_95 -> V_100 )
F_26 ( V_2 , V_95 -> V_100 ) ;
return V_101 ;
default:
return V_104 ;
}
}
static int F_32 ( struct V_1 * V_2 , struct V_105 * V_106 , int V_107 )
{
T_1 V_39 = ( V_106 [ 0 ] . V_39 & 0x7f ) << 1 ;
int V_83 = 0 ;
if ( V_107 >= 2 && V_106 [ 0 ] . V_29 < 4 &&
! ( V_106 [ 0 ] . V_15 & V_108 ) && ( V_106 [ 1 ] . V_15 & V_108 ) ) {
T_1 V_109 = 0 ;
int V_35 ;
F_20 ( V_2 -> V_45 , L_9 ,
V_39 >> 1 ) ;
for ( V_35 = 0 ; V_35 < V_106 [ 0 ] . V_29 ; ++ V_35 ) {
V_109 |= V_106 [ 0 ] . V_40 [ V_35 ] << ( V_35 * 8 ) ;
V_109 |= F_33 ( V_35 ) ;
}
V_2 -> V_14 = & V_106 [ 1 ] ;
V_2 -> V_12 = V_110 ;
F_1 ( V_2 , V_39 | F_33 ( 0 ) , V_111 ) ;
F_1 ( V_2 , V_109 , V_112 ) ;
V_83 = 2 ;
} else {
if ( V_106 [ 0 ] . V_15 & V_108 ) {
V_39 |= 1 ;
V_2 -> V_12 = V_110 ;
F_1 ( V_2 , V_39 | F_33 ( 0 ) ,
V_111 ) ;
F_1 ( V_2 , 0 , V_112 ) ;
} else {
V_2 -> V_12 = V_46 ;
}
V_2 -> V_14 = & V_106 [ 0 ] ;
V_83 = 1 ;
}
V_2 -> V_39 = V_106 [ 0 ] . V_39 ;
V_2 -> V_26 = true ;
V_2 -> V_23 = V_61 ;
V_2 -> V_20 = 0 ;
V_2 -> error = 0 ;
F_5 ( V_2 ) ;
return V_83 ;
}
static int F_34 ( struct V_113 * V_114 ,
struct V_105 * V_106 , int V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_114 -> V_115 ;
unsigned long V_116 , V_15 ;
int V_83 = 0 ;
int V_35 ;
F_35 ( & V_2 -> V_56 , V_15 ) ;
F_27 ( V_2 -> V_88 ) ;
V_2 -> V_21 = false ;
for ( V_35 = 0 ; V_35 < V_107 ; V_35 += V_83 ) {
V_83 = F_32 ( V_2 , V_106 + V_35 , V_107 - V_35 ) ;
if ( V_83 < 0 ) {
F_15 ( V_2 -> V_45 , L_10 ) ;
break;
}
if ( V_35 + V_83 >= V_107 )
V_2 -> V_21 = true ;
F_36 ( & V_2 -> V_56 , V_15 ) ;
F_6 ( V_2 ) ;
V_116 = F_37 ( V_2 -> V_28 , ! V_2 -> V_26 ,
F_38 ( V_117 ) ) ;
F_35 ( & V_2 -> V_56 , V_15 ) ;
if ( V_116 == 0 ) {
F_15 ( V_2 -> V_45 , L_11 ,
F_3 ( V_2 , V_7 ) , V_2 -> V_23 ) ;
F_1 ( V_2 , 0 , V_10 ) ;
F_1 ( V_2 , V_11 | V_25 , V_18 ) ;
V_2 -> V_23 = V_27 ;
V_83 = - V_118 ;
break;
}
if ( V_2 -> error ) {
V_83 = V_2 -> error ;
break;
}
}
F_28 ( V_2 -> V_88 ) ;
F_36 ( & V_2 -> V_56 , V_15 ) ;
return V_83 ;
}
static T_1 F_39 ( struct V_113 * V_114 )
{
return V_119 | V_120 | V_121 ;
}
static int F_40 ( struct V_122 * V_123 )
{
struct V_124 * V_125 = V_123 -> V_45 . V_126 ;
const struct V_127 * V_128 ;
struct V_1 * V_2 ;
struct V_129 * V_130 ;
int V_83 = 0 ;
int V_131 ;
T_1 V_3 ;
int V_132 ;
unsigned long V_63 ;
V_2 = F_41 ( & V_123 -> V_45 , sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_2 )
return - V_134 ;
V_128 = F_42 ( V_135 , V_125 ) ;
V_2 -> V_136 = (struct V_137 * ) V_128 -> V_93 ;
if ( F_43 ( V_123 -> V_45 . V_126 , L_12 ,
& V_2 -> V_87 ) ) {
F_44 ( & V_123 -> V_45 , L_13 ,
V_138 ) ;
V_2 -> V_87 = V_138 ;
}
if ( V_2 -> V_87 == 0 || V_2 -> V_87 > 400 * 1000 ) {
F_13 ( & V_123 -> V_45 , L_14 ) ;
F_13 ( & V_123 -> V_45 , L_13 ,
V_138 ) ;
V_2 -> V_87 = V_138 ;
}
F_45 ( V_2 -> V_114 . V_139 , L_15 , sizeof( V_2 -> V_114 . V_139 ) ) ;
V_2 -> V_114 . V_140 = V_141 ;
V_2 -> V_114 . V_142 = & V_143 ;
V_2 -> V_114 . V_144 = 3 ;
V_2 -> V_114 . V_45 . V_126 = V_125 ;
V_2 -> V_114 . V_115 = V_2 ;
V_2 -> V_114 . V_45 . V_145 = & V_123 -> V_45 ;
V_2 -> V_45 = & V_123 -> V_45 ;
F_46 ( & V_2 -> V_56 ) ;
F_47 ( & V_2 -> V_28 ) ;
V_2 -> V_88 = F_48 ( & V_123 -> V_45 , NULL ) ;
if ( F_49 ( V_2 -> V_88 ) ) {
F_15 ( & V_123 -> V_45 , L_16 ) ;
return F_50 ( V_2 -> V_88 ) ;
}
V_130 = F_51 ( V_123 , V_146 , 0 ) ;
V_2 -> V_5 = F_52 ( & V_123 -> V_45 , V_130 ) ;
if ( F_49 ( V_2 -> V_5 ) )
return F_50 ( V_2 -> V_5 ) ;
V_131 = F_53 ( V_125 , L_17 ) ;
if ( V_2 -> V_136 -> V_147 >= 0 ) {
struct V_148 * V_149 ;
V_149 = F_54 ( V_125 , L_18 ) ;
if ( F_49 ( V_149 ) ) {
F_15 ( & V_123 -> V_45 ,
L_19 ) ;
return F_50 ( V_149 ) ;
}
if ( V_131 < 0 ) {
F_15 ( & V_123 -> V_45 , L_20 ) ;
return - V_84 ;
}
V_3 = F_55 ( 27 + V_131 ) | F_55 ( 11 + V_131 ) ;
V_83 = F_56 ( V_149 , V_2 -> V_136 -> V_147 , V_3 ) ;
if ( V_83 != 0 ) {
F_15 ( V_2 -> V_45 , L_21 , V_83 ) ;
return V_83 ;
}
}
V_132 = F_57 ( V_123 , 0 ) ;
if ( V_132 < 0 ) {
F_15 ( & V_123 -> V_45 , L_22 ) ;
return V_132 ;
}
V_83 = F_58 ( & V_123 -> V_45 , V_132 , F_18 ,
0 , F_59 ( & V_123 -> V_45 ) , V_2 ) ;
if ( V_83 < 0 ) {
F_15 ( & V_123 -> V_45 , L_23 ) ;
return V_83 ;
}
F_60 ( V_123 , V_2 ) ;
V_83 = F_61 ( V_2 -> V_88 ) ;
if ( V_83 < 0 ) {
F_15 ( & V_123 -> V_45 , L_24 ) ;
return V_83 ;
}
V_2 -> V_96 . V_150 = F_30 ;
V_83 = F_62 ( V_2 -> V_88 , & V_2 -> V_96 ) ;
if ( V_83 != 0 ) {
F_15 ( & V_123 -> V_45 , L_25 ) ;
goto V_151;
}
V_63 = F_63 ( V_2 -> V_88 ) ;
F_26 ( V_2 , V_63 ) ;
V_83 = F_64 ( & V_2 -> V_114 ) ;
if ( V_83 < 0 ) {
F_15 ( & V_123 -> V_45 , L_26 ) ;
goto V_152;
}
F_44 ( & V_123 -> V_45 , L_27 , V_2 -> V_5 ) ;
return 0 ;
V_152:
F_65 ( V_2 -> V_88 , & V_2 -> V_96 ) ;
V_151:
F_66 ( V_2 -> V_88 ) ;
return V_83 ;
}
static int F_67 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_68 ( V_123 ) ;
F_69 ( & V_2 -> V_114 ) ;
F_65 ( V_2 -> V_88 , & V_2 -> V_96 ) ;
F_66 ( V_2 -> V_88 ) ;
return 0 ;
}
