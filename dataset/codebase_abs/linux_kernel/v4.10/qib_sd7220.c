static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! V_6 -> V_7 -> V_8 &&
F_2 ( V_6 , V_4 ) > 0 )
V_6 -> V_7 -> V_8 = 1 ;
return V_6 -> V_7 -> V_8 ;
}
void F_3 ( struct V_5 * V_6 )
{
int V_9 ;
V_9 = F_4 ( V_6 , V_10 , V_11 ,
V_12 , V_13 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_1 ) ;
goto V_14;
}
V_9 = F_4 ( V_6 , V_10 , V_11 , 0 ,
V_13 ) ;
F_6 ( V_6 , V_15 ) ;
F_7 ( 4 ) ;
F_8 ( V_6 , V_16 ,
V_17 ) ;
F_6 ( V_6 , V_15 ) ;
V_14:
return;
}
static int F_9 ( struct V_5 * V_6 )
{
int V_9 , V_18 , V_19 , V_20 ;
T_1 V_21 ;
V_9 = - 1 ;
V_20 = 0 ;
for ( V_19 = 0 ; V_19 < ( 4 * V_22 ) ; ++ V_19 ) {
V_21 = F_10 ( V_20 ) ;
V_9 = F_4 ( V_6 , V_10 , V_21 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_2 ) ;
continue;
}
if ( V_9 != 0xF0 && V_9 != 0x55 && V_19 == 0 )
F_5 ( V_6 , L_3 ) ;
V_18 = V_9 ^ 0xA5 ;
V_9 = F_4 ( V_6 , V_10 , V_21 , V_18 , 0xFF ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_4 ) ;
continue;
}
V_9 = F_4 ( V_6 , V_10 , V_21 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_5 ) ;
continue;
}
if ( V_9 != V_18 ) {
F_5 ( V_6 , L_6 ) ;
continue;
}
V_21 = F_11 ( V_20 ) ;
V_9 = F_4 ( V_6 , V_10 , V_21 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_7 ) ;
continue;
}
if ( ( V_9 & 0x70 ) != ( ( V_20 << 4 ) | 0x40 ) ) {
F_5 ( V_6 , L_8 ,
V_9 , V_20 ) ;
continue;
}
if ( ++ V_20 == 4 )
break;
}
return ( V_9 > 0 ) ? 0 : V_9 ;
}
static int F_12 ( struct V_5 * V_6 , int V_23 )
{
T_2 V_24 ;
int V_9 = 0 ;
unsigned long V_25 ;
V_24 = F_13 ( V_6 , V_26 ) ;
if ( V_23 ) {
F_14 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
F_15 ( V_6 , V_10 , 1 ) ;
V_24 |= 1ULL ;
F_8 ( V_6 , V_28 ,
V_6 -> V_7 -> V_29 &
~ V_17 ) ;
F_8 ( V_6 , V_26 , V_24 ) ;
F_6 ( V_6 , V_15 ) ;
F_7 ( 2 ) ;
F_15 ( V_6 , V_10 , - 1 ) ;
F_16 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
} else {
T_2 V_30 ;
V_24 &= ~ ( 1ULL ) ;
F_8 ( V_6 , V_28 ,
V_6 -> V_7 -> V_29 &
~ V_17 ) ;
V_9 = F_9 ( V_6 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_9 ) ;
V_9 = F_4 ( V_6 , V_10 , V_31 , 1 , 1 ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_4 ( V_6 , V_10 , V_11 , 0x80 ,
0x80 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_10 ) ;
goto V_14;
}
F_8 ( V_6 , V_26 , V_24 ) ;
F_6 ( V_6 , V_15 ) ;
F_7 ( 1 ) ;
F_3 ( V_6 ) ;
V_30 = F_13 ( V_6 , V_32 ) ;
if ( V_30 & V_17 ) {
F_5 ( V_6 , L_11 ) ;
V_6 -> V_7 -> V_29 &=
~ V_17 ;
}
F_8 ( V_6 , V_28 ,
V_6 -> V_7 -> V_29 ) ;
}
V_14:
return V_9 ;
}
static void F_17 ( struct V_5 * V_6 ,
const char * V_33 )
{
int V_9 , V_20 , V_34 ;
T_2 V_30 ;
if ( ! V_33 )
V_33 = L_12 ;
F_7 ( 2 ) ;
V_9 = F_9 ( V_6 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_13 , V_33 ) ;
V_9 = F_4 ( V_6 , V_10 , F_18 ( 0 ) , 0 , 0 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_14 , V_33 ) ;
V_30 = F_13 ( V_6 , V_35 ) ;
if ( ! ( V_30 & ( 1ULL << 11 ) ) )
F_5 ( V_6 , L_15 , V_33 ) ;
F_7 ( 2 ) ;
V_9 = F_4 ( V_6 , V_10 , V_11 , 0x80 , 0x80 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_16 , V_33 ) ;
F_7 ( 10 ) ;
V_34 = 0 ;
for ( V_20 = 3 ; V_20 >= 0 ; -- V_20 ) {
V_9 = F_4 ( V_6 , V_10 ,
F_18 ( V_20 ) , 0 , 0 ) ;
if ( V_9 < 0 )
F_5 ( V_6 ,
L_17 ,
V_20 , V_33 ) ;
if ( ! ( V_9 & 0x10 ) ) {
int V_36 ;
V_34 |= ( 1 << V_20 ) ;
F_5 ( V_6 ,
L_18 ,
V_20 , V_9 , V_33 ) ;
V_36 = F_4 ( V_6 , V_10 ,
F_10 ( 0 ) , 0 , 0 ) ;
F_5 ( V_6 , L_19 ,
V_36 , V_36 ) ;
V_36 = F_4 ( V_6 , V_10 ,
F_18 ( V_20 ) , 0 , 0 ) ;
F_5 ( V_6 , L_20 ,
V_36 , V_36 ) ;
V_9 = F_4 ( V_6 , V_10 ,
F_18 ( V_20 ) , 0x10 , 0x10 ) ;
if ( V_9 < 0 )
F_5 ( V_6 ,
L_21 ) ;
}
}
for ( V_20 = 3 ; V_20 >= 0 ; -- V_20 ) {
if ( V_34 & ( 1 << V_20 ) ) {
F_5 ( V_6 ,
L_22 ,
V_20 , V_33 ) ;
V_9 = F_4 ( V_6 , V_10 ,
F_18 ( V_20 ) , 0x10 , 0x10 ) ;
if ( V_9 < 0 )
F_5 ( V_6 ,
L_23 ,
V_20 , V_33 ) ;
}
}
}
int F_19 ( struct V_5 * V_6 )
{
const struct V_3 * V_4 ;
int V_9 = 1 ;
int V_37 , V_38 ;
V_38 = ( F_13 ( V_6 , V_26 ) & 1 ) ;
if ( ! V_38 ) {
F_12 ( V_6 , 1 ) ;
F_17 ( V_6 , L_24 ) ;
}
V_9 = F_20 ( & V_4 , V_39 , & V_6 -> V_40 -> V_41 ) ;
if ( V_9 ) {
F_5 ( V_6 , L_25 ) ;
goto V_42;
}
V_9 = F_1 ( V_6 -> V_43 , V_4 ) ;
if ( V_9 < 0 )
goto V_14;
V_37 = ! V_9 ;
V_9 = F_21 ( V_6 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_26 ) ;
goto V_14;
}
if ( V_37 ) {
V_9 = F_22 ( V_6 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_27 ) ;
goto V_14;
}
}
V_9 = F_23 ( V_6 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_28 ) ;
goto V_14;
}
V_9 = F_24 ( V_6 , 0x80 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_29 ) ;
goto V_14;
}
V_9 = 0 ;
if ( V_37 ) {
int V_44 ;
int V_45 ;
V_9 = F_25 ( V_6 , V_4 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_25 ) ;
goto V_14;
} else {
V_44 = F_2 ( V_6 , V_4 ) ;
if ( V_44 != V_9 ) {
F_5 ( V_6 , L_30 ) ;
goto V_14;
}
}
V_9 = 0 ;
V_9 = F_26 ( V_6 , F_27 ( 0 ) , 0 , 0x38 ) ;
if ( V_9 < 0 ) {
F_5 ( V_6 , L_31 ) ;
goto V_14;
}
F_12 ( V_6 , 0 ) ;
V_45 = F_28 ( V_6 ) ;
F_12 ( V_6 , 1 ) ;
if ( ! V_45 ) {
F_5 ( V_6 , L_32 ) ;
goto V_14;
}
F_17 ( V_6 , L_33 ) ;
V_6 -> V_7 -> V_8 = 1 ;
}
V_9 = 0 ;
if ( F_29 ( V_6 ) >= 0 )
goto V_42;
V_14:
V_9 = 1 ;
V_42:
F_30 ( V_6 , - 1 ) ;
F_31 ( V_4 ) ;
return V_9 ;
}
static int F_15 ( struct V_5 * V_6 , int V_46 , int V_47 )
{
T_3 V_48 ;
T_2 V_49 ;
int V_50 = 0 ;
T_2 V_51 = 0 ;
switch ( V_46 ) {
case V_10 :
V_48 = V_52 ;
break;
case V_53 :
case V_54 :
V_48 = V_55 ;
V_51 = ( 2 << ( V_46 - V_53 ) ) ;
break;
default:
return 0 ;
}
F_6 ( V_6 , V_15 ) ;
F_7 ( 15 ) ;
V_49 = F_6 ( V_6 , V_48 ) ;
V_50 = ! ! ( V_49 & V_56 ) ;
if ( V_47 < 0 ) {
T_2 V_57 ;
T_2 V_58 = 0 ;
F_8 ( V_6 , V_48 , V_58 ) ;
V_57 = F_6 ( V_6 , V_48 ) ;
F_7 ( 5 ) ;
V_57 = F_6 ( V_6 , V_48 ) ;
if ( V_57 & V_56 )
V_50 = - 1 ;
} else if ( V_47 > 0 ) {
T_2 V_57 ;
T_2 V_58 = V_59 | V_51 ;
F_8 ( V_6 , V_48 , V_58 ) ;
V_57 = F_6 ( V_6 , V_48 ) ;
F_7 ( 5 ) ;
V_57 = F_6 ( V_6 , V_48 ) ;
if ( ! ( V_57 & V_56 ) )
V_50 = - 1 ;
}
return V_50 ;
}
static int F_32 ( struct V_5 * V_6 , T_3 V_60 , T_2 V_61 , T_2 * V_62 )
{
int V_19 ;
T_2 V_63 ;
F_8 ( V_6 , V_60 , V_61 ) ;
V_63 = F_13 ( V_6 , V_60 ) ;
for ( V_19 = V_64 ; V_19 ; -- V_19 ) {
V_63 = F_6 ( V_6 , V_60 ) ;
if ( V_63 & V_65 )
break;
F_7 ( 5 ) ;
}
if ( V_63 & V_66 )
return - 1 ;
if ( V_19 > 0 && V_62 )
* V_62 = V_63 ;
return V_19 ;
}
static int F_4 ( struct V_5 * V_6 , int V_46 , T_1 V_21 ,
T_1 V_67 , T_1 V_68 )
{
T_3 V_69 ;
T_2 V_63 ;
int V_50 ;
int V_19 , V_9 ;
unsigned long V_25 ;
switch ( V_46 ) {
case V_10 :
V_69 = V_70 ;
break;
case V_53 :
case V_54 :
V_69 = V_71 ;
break;
default:
return - 1 ;
}
F_14 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
V_50 = F_15 ( V_6 , V_46 , 1 ) ;
if ( V_50 < 0 ) {
F_16 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
return - 1 ;
}
V_9 = 0 ;
for ( V_19 = V_64 ; V_19 ; -- V_19 ) {
V_63 = F_6 ( V_6 , V_69 ) ;
if ( V_63 & V_65 )
break;
F_7 ( 5 ) ;
}
if ( V_19 > 0 ) {
V_19 = 1 ;
if ( V_68 != 0xFF ) {
V_63 = V_21 | V_72 ;
V_19 = F_32 ( V_6 , V_69 , V_63 , & V_63 ) ;
}
if ( V_19 > 0 && V_68 != 0 ) {
V_67 = ( V_67 & V_68 ) | ( V_63 & ~ V_68 ) ;
V_63 = V_21 | ( V_67 & V_73 ) ;
V_19 = F_32 ( V_6 , V_69 , V_63 , & V_63 ) ;
}
}
if ( F_15 ( V_6 , V_46 , - 1 ) < 0 )
V_9 = - 1 ;
else
V_9 = V_63 & V_73 ;
F_16 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
if ( V_19 <= 0 )
V_9 = - 1 ;
return V_9 ;
}
static int F_33 ( struct V_5 * V_6 , int V_46 , T_1 V_21 ,
T_4 * V_74 , int V_75 , int V_76 )
{
T_3 V_69 ;
T_2 V_63 ;
T_2 V_77 ;
int V_50 ;
int V_19 ;
int V_78 ;
int V_79 ;
int V_9 ;
unsigned long V_25 ;
const char * V_80 ;
switch ( V_46 ) {
case V_10 :
V_77 = 1ULL << V_81 ;
V_69 = V_70 ;
break;
case V_53 :
case V_54 :
V_77 = 1ULL << V_82 ;
V_69 = V_71 ;
break;
default:
return - 1 ;
}
V_80 = V_76 ? L_34 : L_35 ;
F_14 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
V_50 = F_15 ( V_6 , V_46 , 1 ) ;
if ( V_50 < 0 ) {
F_16 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
return - 1 ;
}
V_79 = V_21 & 0x1FFF ;
for ( V_19 = V_64 ; V_19 ; -- V_19 ) {
V_63 = F_6 ( V_6 , V_69 ) ;
if ( V_63 & V_65 )
break;
F_7 ( 5 ) ;
}
V_78 = 0 ;
if ( V_19 > 0 ) {
V_63 = V_77 | V_83 |
( V_76 ? V_84 : V_85 ) ;
V_19 = F_32 ( V_6 , V_69 , V_63 , & V_63 ) ;
while ( V_19 > 0 && V_78 < V_75 ) {
if ( ! V_78 ) {
int V_86 = ( V_79 + V_78 ) >> 8 ;
V_63 = V_77 | V_87 | V_86 ;
V_19 = F_32 ( V_6 , V_69 , V_63 ,
& V_63 ) ;
if ( V_19 <= 0 )
break;
V_86 = ( V_79 + V_78 ) & 0xFF ;
V_63 = V_77 | V_88 | V_86 ;
V_19 = F_32 ( V_6 , V_69 , V_63 ,
& V_63 ) ;
if ( V_19 <= 0 )
break;
}
if ( V_76 )
V_63 = V_77 | V_89 | V_72 ;
else
V_63 = V_77 | V_89 | V_74 [ V_78 ] ;
V_19 = F_32 ( V_6 , V_69 , V_63 , & V_63 ) ;
if ( V_19 <= 0 )
break;
if ( V_76 )
V_74 [ V_78 ] = V_63 & V_73 ;
++ V_78 ;
}
V_63 = V_77 | V_83 ;
V_19 = F_32 ( V_6 , V_69 , V_63 , & V_63 ) ;
}
V_9 = V_78 ;
if ( F_15 ( V_6 , V_46 , - 1 ) < 0 )
V_9 = - 1 ;
F_16 ( & V_6 -> V_7 -> V_27 , V_25 ) ;
if ( V_19 <= 0 )
V_9 = - 1 ;
return V_9 ;
}
static int F_34 ( struct V_5 * V_6 , int V_46 ,
const T_4 * V_90 , int V_91 , int V_92 )
{
int V_75 , V_78 , V_93 ;
V_78 = 0 ;
while ( V_78 < V_91 ) {
V_93 = V_91 - V_78 ;
if ( V_93 > V_94 )
V_93 = V_94 ;
V_75 = F_33 ( V_6 , V_46 , V_92 + V_78 ,
( T_4 * ) V_90 + V_78 , V_93 , 0 ) ;
if ( V_75 < V_93 ) {
V_78 = - 1 ;
break;
}
V_78 += V_93 ;
}
return V_78 ;
}
static int F_35 ( struct V_5 * V_6 , int V_46 ,
const T_4 * V_90 , int V_91 , int V_92 )
{
int V_75 , V_78 , V_93 , V_95 , V_96 ;
unsigned char V_97 [ V_98 ] ;
V_96 = 0 ;
V_78 = 0 ;
while ( V_78 < V_91 ) {
V_93 = V_91 - V_78 ;
if ( V_93 > V_98 )
V_93 = V_98 ;
V_75 = F_33 ( V_6 , V_46 , V_78 + V_92 ,
V_97 , V_93 , 1 ) ;
if ( V_75 < V_93 ) {
V_78 = - 1 ;
break;
}
for ( V_95 = 0 ; V_95 < V_75 ; ++ V_95 ) {
if ( V_97 [ V_95 ] != V_90 [ V_95 + V_78 ] )
++ V_96 ;
}
V_78 += V_75 ;
}
return V_96 ? - V_96 : V_78 ;
}
static int
F_25 ( struct V_5 * V_6 , const struct V_3 * V_4 )
{
return F_34 ( V_6 , V_10 , V_4 -> V_99 , V_4 -> V_100 , 0 ) ;
}
static int
F_2 ( struct V_5 * V_6 , const struct V_3 * V_4 )
{
return F_35 ( V_6 , V_10 , V_4 -> V_99 , V_4 -> V_100 , 0 ) ;
}
static int F_28 ( struct V_5 * V_6 )
{
int V_101 , V_9 ;
T_5 V_30 ;
V_9 = 0 ;
for ( V_101 = 0 ; V_101 < V_102 ; ++ V_101 ) {
V_30 = F_13 ( V_6 , V_35 ) ;
if ( V_30 & V_103 ) {
V_9 = 1 ;
break;
}
F_36 ( 20 ) ;
}
if ( V_101 >= V_102 ) {
F_5 ( V_6 , L_36 , V_101 ) ;
V_9 = 0 ;
}
return V_9 ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_95 , V_104 ;
int V_105 ;
T_6 V_106 ;
T_2 T_7 * V_107 , * V_108 ;
T_5 V_99 ;
T_5 V_109 ;
V_107 = V_6 -> V_110 + V_111 ;
V_108 = V_6 -> V_110 + V_112 ;
V_109 = F_13 ( V_6 , V_26 ) ;
V_109 = ( V_109 & ~ ( 0x1f << 8 ) ) | ( V_113 << 8 ) ;
V_109 = ( V_109 & ~ ( 0x1f << 13 ) ) | ( V_114 << 13 ) ;
F_8 ( V_6 , V_26 , V_109 ) ;
V_106 = V_115 ;
for ( V_95 = 0 ; V_95 < V_113 ; ++ V_95 ) {
V_99 = ( ( V_106 & 0xF ) << 4 ) | V_116 ;
F_37 ( V_99 , V_108 + V_95 ) ;
F_38 () ;
F_6 ( V_6 , V_15 ) ;
V_106 >>= 4 ;
for ( V_104 = 0 ; V_104 < V_117 ; ++ V_104 ) {
T_2 T_7 * V_118 = V_107 + ( ( V_104 << 4 ) + V_95 ) ;
V_99 = V_119 [ V_104 ] . V_120 [ V_95 ] ;
F_37 ( V_99 , V_118 ) ;
F_38 () ;
F_6 ( V_6 , V_15 ) ;
}
}
V_105 = V_95 ;
V_107 += 0x100 ;
for ( V_95 = 0 ; V_95 < V_114 ; ++ V_95 ) {
int V_121 ;
int V_122 ;
V_121 = V_95 + V_105 ;
F_37 ( V_123 [ V_95 ] . V_124 , V_108 + V_121 ) ;
F_38 () ;
F_6 ( V_6 , V_15 ) ;
for ( V_122 = 0 ; V_122 < 4 ; V_122 ++ ) {
V_99 = V_123 [ V_95 ] . V_125 [ V_122 ] ;
F_37 ( V_99 , V_107 + ( V_122 << 6 ) + V_95 ) ;
F_38 () ;
F_6 ( V_6 , V_15 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_5 * V_6 , int V_21 , int V_30 ,
int V_68 )
{
int V_9 = - 1 ;
int V_126 ;
if ( V_21 & V_127 ) {
V_21 |= ( 1U << V_128 ) ;
V_126 = ( V_21 >> ( 4 + V_129 ) ) & 7 ;
if ( V_68 != 0xFF ) {
V_9 = F_4 ( V_6 , V_10 ,
V_21 & ~ V_127 , 0 , 0 ) ;
if ( V_9 < 0 ) {
int V_130 = V_21 >> V_129 ;
F_5 ( V_6 ,
L_37 ,
( V_130 & 0xF ) ,
( V_130 >> 9 ) & 0x3f , V_126 ) ;
return V_9 ;
}
V_30 = ( V_9 & ~ V_68 ) | ( V_30 & V_68 ) ;
}
V_21 &= ~ ( 7 << ( 4 + V_129 ) ) ;
V_9 = F_4 ( V_6 , V_10 , V_21 , V_30 , 0xFF ) ;
if ( V_9 < 0 ) {
int V_130 = V_21 >> V_129 ;
F_5 ( V_6 ,
L_38 ,
( V_130 & 0xF ) , ( V_130 >> 9 ) & 0x3f , V_30 ) ;
}
return V_9 ;
}
V_21 &= ~ ( 7 << ( 4 + V_129 ) ) ;
V_21 |= ( 1U << V_128 ) ;
for ( V_126 = 0 ; V_126 < 4 ; ++ V_126 ) {
int V_131 = V_21 | ( V_126 << ( 4 + V_129 ) ) ;
V_9 = F_4 ( V_6 , V_10 , V_131 , V_30 , V_68 ) ;
if ( V_9 < 0 ) {
int V_130 = V_21 >> V_129 ;
F_5 ( V_6 ,
L_39 ,
( V_130 & 0xF ) , ( V_130 >> 9 ) & 0x3f , V_126 ,
V_30 & 0xFF , V_68 & 0xFF ) ;
break;
}
}
return V_9 ;
}
static int F_39 ( struct V_5 * V_6 , struct V_132 * V_133 )
{
int V_9 ;
int V_95 , V_60 , V_99 ;
T_6 V_134 ;
V_134 = V_115 ;
for ( V_95 = 0 ; V_95 < V_113 ; ++ V_95 ) {
V_60 = ( V_134 & 0xF ) ;
V_134 >>= 4 ;
V_99 = V_133 -> V_120 [ V_95 ] ;
V_9 = F_26 ( V_6 , F_40 ( 0 , 9 , V_60 ) , V_99 , 0xFF ) ;
if ( V_9 < 0 )
break;
}
return V_9 ;
}
static int F_41 ( struct V_5 * V_6 , int V_135 )
{
int V_9 ;
int V_136 ;
int V_75 = F_42 ( V_123 ) ;
for ( V_136 = 0 ; V_136 < V_75 ; ++ V_136 ) {
int V_137 , V_60 , V_30 , V_21 ;
V_137 = V_123 [ V_136 ] . V_124 & 0xF ;
V_60 = V_123 [ V_136 ] . V_124 >> 4 ;
V_21 = F_40 ( 0 , V_137 , V_60 ) ;
V_30 = V_123 [ V_136 ] . V_125 [ V_135 ] ;
V_9 = F_26 ( V_6 , V_21 , V_30 , 0xFF ) ;
if ( V_9 < 0 )
break;
}
return V_9 ;
}
static int F_23 ( struct V_5 * V_6 )
{
int V_9 = 0 ;
V_9 = F_39 ( V_6 , V_119 + V_138 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_40 ) ;
V_9 = F_41 ( V_6 , V_139 & 3 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_41 ) ;
return V_9 ;
}
int F_43 ( struct V_5 * V_6 )
{
int V_9 = 0 ;
if ( ! V_6 -> V_7 -> V_140 )
return V_9 ;
V_6 -> V_7 -> V_140 = 0 ;
F_12 ( V_6 , 1 ) ;
F_7 ( 2 ) ;
F_17 ( V_6 , L_42 ) ;
V_9 = F_23 ( V_6 ) ;
return V_9 ;
}
static int F_24 ( struct V_5 * V_6 , int V_30 )
{
int V_21 = V_141 | ( 1U << V_128 ) ;
return F_4 ( V_6 , V_10 , V_21 , V_30 , 0xFF ) ;
}
static int F_21 ( struct V_5 * V_6 )
{
int V_9 ;
V_9 = F_26 ( V_6 , F_44 ( 0 ) | V_127 , 0xD4 , 0xFF ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_26 ( V_6 , F_27 ( 0 ) | V_127 , 0x10 , 0xFF ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_26 ( V_6 , F_45 ( 0 ) | V_127 , 0x30 , 0xFF ) ;
V_14:
return V_9 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_9 ;
V_9 = F_26 ( V_6 , F_46 ( 0 ) | V_127 , 0x2D , 0xFF ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_26 ( V_6 , F_47 ( 0 ) , 3 , 0xF ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_26 ( V_6 , F_48 ( 0 ) | V_127 , 0x40 , 0xFF ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_26 ( V_6 , F_49 ( 0 ) | V_127 , 0x04 , 0xFF ) ;
if ( V_9 < 0 )
goto V_14;
V_9 = F_26 ( V_6 , F_50 ( 0 ) | V_127 , 0x04 , 0xFF ) ;
if ( V_9 < 0 )
goto V_14;
F_7 ( 415 ) ;
V_9 = F_26 ( V_6 , F_49 ( 0 ) | V_127 , 0x00 , 0xFF ) ;
V_14:
return V_9 ;
}
void F_51 ( struct V_5 * V_6 )
{
int V_21 = F_52 ( 0 ) | V_127 ;
int V_9 ;
V_9 = F_26 ( V_6 , V_21 , 0 , 0x80 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_43 ) ;
else {
F_7 ( 1 ) ;
F_26 ( V_6 , V_21 , 0x80 , 0x80 ) ;
}
F_7 ( 1 ) ;
V_9 = F_26 ( V_6 , V_21 , 0 , 0x80 ) ;
if ( V_9 < 0 )
F_5 ( V_6 , L_43 ) ;
else {
F_7 ( 1 ) ;
F_26 ( V_6 , V_21 , 0x80 , 0x80 ) ;
}
V_6 -> V_142 ( V_6 -> V_43 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 -> V_143 )
F_54 ( & V_6 -> V_7 -> V_144 ) ;
}
static void F_55 ( unsigned long V_145 )
{
struct V_5 * V_6 = (struct V_5 * ) V_145 ;
struct V_1 * V_2 = V_6 -> V_43 ;
struct V_146 * V_147 = V_6 -> V_7 ;
int V_148 ;
if ( ( V_6 -> V_25 & V_149 ) && ! ( V_2 -> V_150 &
( V_151 | V_152 | V_153 |
V_154 ) ) ) {
if ( V_155 ) {
if ( ! ( V_2 -> V_150 & V_156 ) )
F_51 ( V_6 ) ;
}
V_148 = V_147 -> V_157 << 1 ;
if ( V_148 > V_158 )
V_148 = V_158 ;
V_147 -> V_157 = V_148 ;
} else
V_148 = V_158 ;
F_56 ( & V_147 -> V_144 , V_159 + V_148 ) ;
}
void F_30 ( struct V_5 * V_6 , int V_160 )
{
struct V_146 * V_147 = V_6 -> V_7 ;
if ( V_160 ) {
if ( V_147 -> V_143 ) {
V_147 -> V_157 = V_158 ;
F_56 ( & V_147 -> V_144 , V_159 + V_158 ) ;
}
} else {
unsigned int V_161 ;
V_161 = F_57 ( V_162 ) ;
if ( V_161 == 0 )
V_161 = 1 ;
if ( ! V_147 -> V_143 ) {
V_147 -> V_143 = 1 ;
F_58 ( & V_147 -> V_144 ) ;
V_147 -> V_144 . V_163 = F_55 ;
V_147 -> V_144 . V_99 = ( unsigned long ) V_6 ;
V_147 -> V_157 = V_161 ;
V_147 -> V_144 . V_164 = V_159 + V_161 ;
F_59 ( & V_147 -> V_144 ) ;
} else {
V_147 -> V_157 = V_161 ;
F_56 ( & V_147 -> V_144 , V_159 + V_161 ) ;
}
}
}
