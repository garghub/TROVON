static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static int F_3 ( struct V_6 * V_7 , int V_8 )
{
int V_9 = 100 ;
while ( -- V_9 && ( ( F_4 ( V_7 -> V_10 + V_11 ) & 3 ) != V_8 ) )
F_5 ( 1 ) ;
if ( V_9 <= 0 )
return - V_12 ;
return 0 ;
}
static int F_6 ( int V_13 , struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_16 * V_17 = V_7 -> V_17 ;
unsigned short V_18 = F_4 ( V_7 -> V_10 + V_19 ) ;
unsigned short V_20 = F_4 ( V_7 -> V_10 + V_21 ) ;
int V_22 ;
if ( V_13 == V_23 ) {
V_20 |= V_24 ;
V_18 = V_25 | V_26 ;
V_22 = 3 ;
} else {
V_20 &= ~ V_24 ;
V_18 = V_25 ;
V_22 = 0 ;
}
if ( V_17 -> V_13 )
V_17 -> V_13 ( V_13 ) ;
F_7 ( V_20 , V_7 -> V_10 + V_21 ) ;
F_7 ( V_18 , V_7 -> V_10 + V_19 ) ;
return F_3 ( V_7 , V_22 ) ;
}
static int F_8 ( T_2 V_27 ,
T_2 V_28 , T_2 V_29 , T_2 V_30 ,
T_2 V_31 , struct V_14 * V_15 )
{
T_3 * V_32 = V_15 -> V_33 ;
if ( V_27 >= 16 )
return - V_34 ;
V_28 >>= 16 - V_15 -> V_35 . V_28 . V_36 ;
V_29 >>= 16 - V_15 -> V_35 . V_29 . V_36 ;
V_30 >>= 16 - V_15 -> V_35 . V_30 . V_36 ;
V_31 >>= 16 - V_15 -> V_35 . V_31 . V_36 ;
V_32 [ V_27 ] = ( V_28 << V_15 -> V_35 . V_28 . V_37 ) |
( V_29 << V_15 -> V_35 . V_29 . V_37 ) |
( V_30 << V_15 -> V_35 . V_30 . V_37 ) |
( V_31 << V_15 -> V_35 . V_31 . V_37 ) ;
return 0 ;
}
static int F_9 ( struct V_38 * V_39 ,
T_4 V_40 , int * V_41 , int * V_42 )
{
int V_43 , V_44 ;
V_44 = V_43 = 0 ;
switch ( V_40 & V_45 ) {
case V_46 :
V_44 = 1 ;
V_43 = 1 ;
break;
case V_47 :
V_44 = 1 ;
V_43 = 2 ;
break;
case V_48 :
V_44 = 1 ;
case V_49 :
V_43 = 4 ;
break;
case V_50 :
V_44 = 1 ;
case V_51 :
V_43 = 8 ;
break;
case V_52 :
case V_53 :
V_43 = 16 ;
V_44 = 0 ;
break;
default:
F_10 ( V_39 , L_1 ) ;
return - V_34 ;
}
if ( V_41 )
* V_41 = V_43 ;
if ( V_42 )
* V_42 = V_44 ;
return 0 ;
}
static int F_11 ( struct V_54 * V_35 ,
struct V_14 * V_15 )
{
struct V_55 * V_56 = & V_15 -> V_56 ;
struct V_6 * V_7 = V_15 -> V_7 ;
int V_57 , V_41 ;
V_57 = F_9 ( V_15 -> V_39 , V_7 -> V_17 -> V_40 , & V_41 , NULL ) ;
if ( V_57 )
return V_57 ;
V_35 -> V_58 = V_41 ;
if ( ( V_35 -> V_59 ) && ( V_35 -> V_58 == 1 ) )
V_56 -> V_60 = V_61 ;
else if ( V_35 -> V_58 >= 15 )
V_56 -> V_60 = V_62 ;
else
V_56 -> V_60 = V_63 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
struct V_64 * V_65 = V_7 -> V_17 -> V_66 ;
unsigned long V_67 , V_68 , V_69 , V_70 ;
unsigned short V_71 , V_72 , V_73 , V_74 ;
unsigned short V_75 , V_76 , V_77 , V_78 ;
unsigned short V_40 , V_79 ;
int V_57 , V_41 , V_42 ;
V_7 -> V_80 = V_7 -> V_17 -> V_81 ;
if ( V_7 -> V_80 && ( V_65 -> V_82 > 320 ) ) {
F_10 ( V_15 -> V_39 , L_2 ) ;
V_7 -> V_80 = 0 ;
}
V_71 = V_65 -> V_83 + V_65 -> V_82 ;
V_72 = V_65 -> V_84 ;
V_73 = V_65 -> V_85 + V_71 + V_72 ;
V_74 = V_65 -> V_82 ;
V_75 = V_65 -> V_86 + V_65 -> V_87 ;
V_76 = V_65 -> V_88 ;
V_77 = V_65 -> V_89 + V_75 + V_76 ;
V_78 = V_65 -> V_87 ;
V_57 = F_9 ( V_15 -> V_39 , V_7 -> V_17 -> V_40 , & V_41 , & V_42 ) ;
if ( V_57 )
return V_57 ;
F_10 ( V_15 -> V_39 , L_3 , V_74 ,
V_78 , V_41 , V_42 ? L_4 : L_5 ,
V_7 -> V_80 ? L_6 : L_7 ) ;
#ifdef F_13
V_40 = V_7 -> V_17 -> V_40 | ( 1 << 8 ) ;
#else
V_40 = V_7 -> V_17 -> V_40 & ~ ( 1 << 8 ) ;
#endif
V_79 = V_7 -> V_17 -> V_79 ;
if ( ! ( V_65 -> V_90 & V_91 ) )
V_79 |= V_92 ;
if ( ! ( V_65 -> V_90 & V_93 ) )
V_79 |= V_94 ;
F_6 ( V_95 , V_15 ) ;
F_7 ( V_7 -> V_17 -> V_96 , V_7 -> V_10 + V_97 ) ;
F_7 ( V_79 , V_7 -> V_10 + V_98 ) ;
F_7 ( V_40 , V_7 -> V_10 + V_99 ) ;
F_7 ( ( V_7 -> V_80 ? 1 << 13 : 0 ) , V_7 -> V_10 + V_100 ) ;
F_7 ( V_7 -> V_17 -> V_101 , V_7 -> V_10 + V_11 ) ;
F_7 ( V_7 -> V_17 -> V_102 , V_7 -> V_10 + V_103 ) ;
F_7 ( ( ( V_73 >> 3 ) - 1 ) | ( ( ( V_74 >> 3 ) - 1 ) << 8 ) ,
V_7 -> V_10 + V_104 ) ;
F_7 ( V_78 - 1 , V_7 -> V_10 + V_105 ) ;
F_7 ( V_77 - 1 , V_7 -> V_10 + V_106 ) ;
F_7 ( ( V_75 - 1 ) | ( ( V_76 - 1 ) << 12 ) , V_7 -> V_10 + V_107 ) ;
F_7 ( ( ( V_71 >> 3 ) - 1 ) | ( ( ( V_72 >> 3 ) - 1 ) << 12 ) ,
V_7 -> V_10 + V_108 ) ;
F_7 ( V_7 -> V_17 -> V_109 , V_7 -> V_10 + V_110 ) ;
V_70 = ( V_7 -> V_80 ) ? V_77 : V_74 ;
if ( ! V_42 )
V_70 *= ( V_41 + 7 ) >> 3 ;
else {
if ( V_41 == 1 )
V_70 >>= 3 ;
else if ( V_41 == 2 )
V_70 >>= 2 ;
else if ( V_41 == 4 )
V_70 >>= 1 ;
}
if ( V_7 -> V_80 ) {
unsigned long V_111 = 1 << 31 ;
while ( V_111 ) {
if ( V_70 & V_111 )
break;
V_111 >>= 1 ;
}
if ( V_70 & ~ V_111 )
V_70 = V_111 << 1 ;
}
F_7 ( V_70 , V_7 -> V_10 + V_112 ) ;
V_67 = ( unsigned long ) V_7 -> V_113 ;
if ( V_7 -> V_80 )
V_67 += ( V_74 - 1 ) * V_70 ;
F_14 ( V_67 , V_7 -> V_10 + V_114 ) ;
if ( ( ( V_79 & 0x003f ) >= V_115 ) &&
( ( V_79 & 0x003f ) <= V_116 ) ) {
F_10 ( V_15 -> V_39 , L_8 ) ;
V_68 = V_70 ;
if ( V_7 -> V_80 )
V_68 *= V_74 >> 1 ;
else
V_68 *= V_78 >> 1 ;
V_69 = V_67 + V_68 ;
} else
V_69 = 0 ;
F_14 ( V_69 , V_7 -> V_10 + V_117 ) ;
V_15 -> V_56 . V_118 = V_70 ;
F_11 ( & V_15 -> V_35 , V_15 ) ;
F_6 ( V_23 , V_15 ) ;
F_10 ( V_15 -> V_39 , L_9 , V_74 , V_73 ) ;
F_10 ( V_15 -> V_39 , L_10 , V_72 , V_71 ) ;
F_10 ( V_15 -> V_39 , L_11 , V_78 , V_77 ) ;
F_10 ( V_15 -> V_39 , L_12 , V_76 , V_75 ) ;
F_10 ( V_15 -> V_39 , L_13 ,
( V_7 -> V_17 -> V_96 >> 12 ) & 3 , V_7 -> V_17 -> V_96 & 0x1f ) ;
F_10 ( V_15 -> V_39 , L_14 , V_7 -> V_17 -> V_101 ,
V_7 -> V_17 -> V_102 ) ;
F_10 ( V_15 -> V_39 , L_15 , V_79 , V_40 ) ;
F_10 ( V_15 -> V_39 , L_16 , V_70 ) ;
F_10 ( V_15 -> V_39 , L_17 , V_67 , V_69 ) ;
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
if ( ! V_15 -> V_119 )
return;
F_16 ( V_15 -> V_39 , V_15 -> V_120 ,
V_15 -> V_119 , V_7 -> V_113 ) ;
V_7 -> V_113 = 0 ;
V_15 -> V_119 = NULL ;
V_15 -> V_120 = 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
void * V_121 ;
unsigned long V_122 ;
int V_57 , V_41 ;
if ( V_15 -> V_119 )
return 0 ;
V_57 = F_9 ( V_15 -> V_39 , V_7 -> V_17 -> V_40 , & V_41 , NULL ) ;
if ( V_57 ) {
F_18 ( V_123 L_18 ) ;
return V_57 ;
}
V_122 = V_15 -> V_35 . V_82 * V_15 -> V_35 . V_87 ;
if ( V_15 -> V_35 . V_59 ) {
if ( V_41 == 1 )
V_122 >>= 3 ;
else if ( V_41 == 2 )
V_122 >>= 2 ;
else if ( V_41 == 4 )
V_122 >>= 1 ;
} else if ( V_41 > 8 )
V_122 *= 2 ;
if ( ( V_122 < 1 ) || ( V_122 > 1024 * 2048 ) ) {
F_10 ( V_15 -> V_39 , L_19 ) ;
return - V_124 ;
}
if ( V_122 < V_125 )
V_122 = V_125 ;
V_121 = F_19 ( V_15 -> V_39 , V_122 , & V_7 -> V_113 , V_126 ) ;
if ( ! V_121 )
return - V_127 ;
if ( ( V_7 -> V_113 & V_128 ) != V_128 ) {
F_15 ( V_15 ) ;
F_20 ( V_15 -> V_39 , L_20
L_21 , ( unsigned long ) V_7 -> V_113 ) ;
return - V_127 ;
}
V_15 -> V_119 = V_121 ;
V_15 -> V_120 = V_122 ;
V_15 -> V_56 . V_129 = ( unsigned long ) V_15 -> V_119 ;
V_15 -> V_56 . V_130 = V_15 -> V_120 ;
return 0 ;
}
static int T_5 F_21 ( struct V_131 * V_132 )
{
struct V_14 * V_15 ;
struct V_133 * V_134 ;
struct V_6 * V_7 ;
int V_57 ;
V_134 = F_22 ( V_132 , V_135 , 0 ) ;
if ( F_23 ( V_134 == NULL ) ) {
F_20 ( & V_132 -> V_39 , L_22 ) ;
return - V_34 ;
}
V_15 = F_24 ( sizeof( struct V_6 ) , & V_132 -> V_39 ) ;
if ( ! V_15 )
return - V_127 ;
V_7 = V_15 -> V_7 ;
V_7 -> V_39 = V_132 ;
V_7 -> V_17 = V_132 -> V_39 . V_136 ;
if ( ! V_7 -> V_17 ) {
F_10 ( V_15 -> V_39 , L_23 ) ;
V_57 = - V_124 ;
goto V_137;
}
V_7 -> V_138 = F_25 ( V_134 -> V_139 ,
F_26 ( V_134 ) , V_132 -> V_140 ) ;
if ( ! V_7 -> V_138 ) {
F_20 ( & V_132 -> V_39 , L_24 ) ;
V_57 = - V_141 ;
goto V_137;
}
V_7 -> V_10 = F_27 ( V_134 -> V_139 , F_26 ( V_134 ) ) ;
if ( ! V_7 -> V_10 ) {
F_20 ( & V_132 -> V_39 , L_25 ) ;
V_57 = - V_124 ;
goto V_142;
}
F_7 ( 0 , V_7 -> V_10 + V_21 ) ;
V_7 -> V_1 = F_28 ( V_132 , 0 ) ;
if ( V_7 -> V_1 >= 0 ) {
V_57 = F_29 ( V_7 -> V_1 , F_1 , 0 ,
L_26 , & V_7 -> V_143 ) ;
if ( V_57 ) {
F_20 ( & V_132 -> V_39 , L_27 ) ;
V_7 -> V_1 = - V_144 ;
} else
F_30 ( V_7 -> V_1 ) ;
}
F_31 ( & V_15 -> V_35 , V_7 -> V_17 -> V_66 ) ;
V_57 = F_17 ( V_15 ) ;
if ( V_57 ) {
F_10 ( V_15 -> V_39 , L_28 ) ;
goto V_145;
}
V_15 -> V_33 = V_7 -> V_33 ;
V_15 -> V_35 . V_28 . V_37 = 11 ;
V_15 -> V_35 . V_28 . V_36 = 5 ;
V_15 -> V_35 . V_28 . V_146 = 0 ;
V_15 -> V_35 . V_29 . V_37 = 5 ;
V_15 -> V_35 . V_29 . V_36 = 6 ;
V_15 -> V_35 . V_29 . V_146 = 0 ;
V_15 -> V_35 . V_30 . V_37 = 0 ;
V_15 -> V_35 . V_30 . V_36 = 5 ;
V_15 -> V_35 . V_30 . V_146 = 0 ;
V_15 -> V_35 . V_31 . V_37 = 0 ;
V_15 -> V_35 . V_31 . V_36 = 0 ;
V_15 -> V_35 . V_31 . V_146 = 0 ;
strcpy ( V_15 -> V_56 . V_147 , L_26 ) ;
F_7 ( V_25 , V_7 -> V_10 + V_19 ) ;
V_15 -> V_148 = & V_149 ;
V_57 = F_32 ( & V_15 -> V_150 , 256 , 0 ) ;
if ( V_57 ) {
F_10 ( V_15 -> V_39 , L_29 ) ;
goto V_151;
}
V_57 = F_33 ( V_15 ) ;
if ( V_57 < 0 ) {
F_10 ( V_15 -> V_39 , L_30 ) ;
goto V_152;
}
F_34 ( V_132 , V_15 ) ;
F_18 ( V_153 L_31 ,
V_132 -> V_140 ,
( unsigned long ) V_7 -> V_113 ,
( unsigned long ) ( V_7 -> V_113 + V_15 -> V_120 - 1 ) ,
V_15 -> V_120 >> 10 ) ;
return 0 ;
V_152:
F_6 ( V_95 , V_15 ) ;
F_35 ( & V_15 -> V_150 ) ;
V_151:
F_15 ( V_15 ) ;
V_145:
if ( V_7 -> V_1 >= 0 )
F_36 ( V_7 -> V_1 , & V_7 -> V_143 ) ;
F_37 ( V_7 -> V_10 ) ;
V_142:
F_38 ( V_134 -> V_139 , F_26 ( V_134 ) ) ;
V_137:
F_39 ( V_15 ) ;
return V_57 ;
}
static int T_6 F_40 ( struct V_131 * V_39 )
{
struct V_14 * V_15 = F_41 ( V_39 ) ;
struct V_6 * V_7 = V_15 -> V_7 ;
F_6 ( V_95 , V_15 ) ;
F_42 ( V_15 ) ;
F_35 ( & V_15 -> V_150 ) ;
F_15 ( V_15 ) ;
if ( V_7 -> V_1 >= 0 )
F_36 ( V_7 -> V_1 , V_7 ) ;
F_37 ( V_7 -> V_10 ) ;
F_38 ( V_7 -> V_138 -> V_139 , F_26 ( V_7 -> V_138 ) ) ;
F_39 ( V_15 ) ;
F_34 ( V_39 , NULL ) ;
return 0 ;
}
