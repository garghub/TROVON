T_1 F_1 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_2 , V_6 ) & 0xff ;
if ( F_3 ( V_5 ) == 3 ) {
V_4 = F_4 ( F_2 ( V_2 ,
V_7 ) ) ;
if ( V_4 >= V_8 )
V_5 |= 1 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_1 V_5 ;
V_5 = F_1 ( V_1 ) ;
F_6 ( L_1 ,
L_2 ,
F_3 ( F_2 ( V_2 , V_9 ) ) ,
F_7 ( F_2 ( V_2 , V_9 ) ) ,
L_3 ,
F_3 ( F_2 ( V_2 , V_10 ) ) ,
F_7 ( F_2 ( V_2 , V_10 ) ) ,
L_4 ,
F_3 ( F_2 ( V_2 , V_11 ) ) ,
F_7 ( F_2 ( V_2 , V_11 ) ) ,
L_5 ,
F_3 ( F_2 ( V_2 , V_6 ) ) ,
F_7 ( F_2 ( V_2 , V_6 ) ) ,
L_6 ,
F_4 ( F_2 ( V_2 , V_7 ) ) ,
L_7 ,
F_3 ( V_5 ) , F_7 ( V_5 ) ) ;
return F_1 ( V_1 ) ;
}
static void F_8 ( struct V_1 * V_1 , int V_12 )
{
void T_2 * V_2 = V_1 -> V_3 ;
static T_3 V_13 , V_14 ;
T_3 V_15 ;
if ( V_12 ) {
V_13 = F_2 ( V_2 , V_16 ) ;
V_14 = F_2 ( V_2 , V_17 ) ;
V_15 = V_18
| V_14 | V_19 ;
F_9 ( V_2 , V_16 , V_15 ) ;
V_15 = V_14 & ~ V_19 ;
V_15 |= V_18 | V_20 ;
F_9 ( V_2 , V_17 , V_15 ) ;
F_10 ( V_1 -> V_21 , L_8 ,
F_2 ( V_2 , V_16 ) ,
F_2 ( V_2 , V_17 ) ) ;
} else if ( F_2 ( V_2 , V_17 )
& V_20 ) {
V_15 = V_18 | V_13 ;
F_9 ( V_2 , V_16 , V_15 ) ;
V_15 = V_18 | V_14 ;
F_9 ( V_2 , V_17 , V_15 ) ;
F_10 ( V_1 -> V_21 , L_9 ,
F_2 ( V_2 , V_16 ) ,
F_2 ( V_2 , V_17 ) ) ;
V_13 = 0 ;
V_14 = 0 ;
}
}
static inline void
F_11 ( void T_2 * V_22 , const T_1 * V_23 , T_4 V_24 )
{
T_3 V_25 ;
int V_26 ;
if ( V_24 > 4 ) {
for ( V_26 = 0 ; V_26 < ( V_24 >> 2 ) ; V_26 ++ ) {
memcpy ( & V_25 , V_23 , 4 ) ;
F_9 ( V_22 , 0 , V_25 ) ;
V_23 += 4 ;
}
V_24 %= 4 ;
}
if ( V_24 > 0 ) {
memcpy ( & V_25 , V_23 , V_24 ) ;
F_9 ( V_22 , 0 , V_25 ) ;
}
}
static inline void F_12 ( void T_2 * V_22 ,
void * V_23 , T_4 V_24 )
{
T_3 V_25 ;
int V_26 ;
if ( V_24 > 4 ) {
for ( V_26 = 0 ; V_26 < ( V_24 >> 2 ) ; V_26 ++ ) {
V_25 = F_2 ( V_22 , 0 ) ;
memcpy ( V_23 , & V_25 , 4 ) ;
V_23 += 4 ;
}
V_24 %= 4 ;
}
if ( V_24 > 0 ) {
V_25 = F_2 ( V_22 , 0 ) ;
memcpy ( V_23 , & V_25 , V_24 ) ;
}
}
void F_13 ( struct V_27 * V_28 , T_4 V_24 , const T_1 * V_23 )
{
struct V_1 * V_1 = V_28 -> V_1 ;
void T_2 * V_29 = V_28 -> V_30 ;
void T_2 * V_22 = V_28 -> V_22 ;
T_1 V_31 = V_28 -> V_31 ;
F_14 ( V_23 ) ;
F_10 ( V_1 -> V_21 , L_10 ,
'T' , V_31 , V_22 , V_24 , V_23 ) ;
if ( V_31 )
F_9 ( V_29 , V_32 ,
F_15 ( V_24 ) ) ;
else
F_9 ( V_29 , 0 , V_33 |
F_16 ( V_24 ) ) ;
if ( F_17 ( ( 0x01 & ( unsigned long ) V_23 ) == 0 ) ) {
if ( ( 0x02 & ( unsigned long ) V_23 ) == 0 ) {
if ( V_24 >= 4 ) {
F_18 ( V_22 , V_23 , V_24 >> 2 ) ;
V_23 += ( V_24 & ~ 0x03 ) ;
V_24 &= 0x03 ;
}
} else {
if ( V_24 >= 2 ) {
T_3 V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < ( V_24 >> 2 ) ; V_26 ++ ) {
V_25 = ( T_3 ) ( * ( T_4 * ) V_23 ) ;
V_23 += 2 ;
V_25 |= ( * ( T_4 * ) V_23 ) << 16 ;
V_23 += 2 ;
F_9 ( V_22 , 0 , V_25 ) ;
}
V_24 &= 0x03 ;
}
}
}
if ( V_24 > 0 )
F_11 ( V_22 , V_23 , V_24 ) ;
}
void F_19 ( struct V_27 * V_28 , T_4 V_24 , T_1 * V_23 )
{
struct V_1 * V_1 = V_28 -> V_1 ;
void T_2 * V_29 = V_28 -> V_30 ;
void T_2 * V_22 = V_28 -> V_22 ;
T_1 V_31 = V_28 -> V_31 ;
F_10 ( V_1 -> V_21 , L_10 ,
'R' , V_31 , V_22 , V_24 , V_23 ) ;
if ( V_31 )
F_9 ( V_29 , V_34 ,
F_15 ( V_24 ) ) ;
else
F_9 ( V_29 , 0 , F_16 ( V_24 ) ) ;
if ( F_17 ( ( 0x01 & ( unsigned long ) V_23 ) == 0 ) ) {
if ( ( 0x02 & ( unsigned long ) V_23 ) == 0 ) {
if ( V_24 >= 4 ) {
F_20 ( V_22 , V_23 , V_24 >> 2 ) ;
V_23 += ( V_24 & ~ 0x03 ) ;
V_24 &= 0x03 ;
}
} else {
if ( V_24 >= 2 ) {
T_3 V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < ( V_24 >> 2 ) ; V_26 ++ ) {
V_25 = F_2 ( V_22 , 0 ) ;
* ( T_4 * ) V_23 = ( T_4 ) ( V_25 & 0xffff ) ;
V_23 += 2 ;
* ( T_4 * ) V_23 = ( T_4 ) ( V_25 >> 16 ) ;
V_23 += 2 ;
}
V_24 &= 0x03 ;
}
}
}
if ( V_24 > 0 )
F_12 ( V_22 , V_23 , V_24 ) ;
}
static int F_21 ( struct V_35 * V_36 , unsigned V_37 )
{
struct V_1 * V_1 = V_38 ;
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_39 ;
if ( V_36 -> V_40 -> V_41 || V_37 < ( V_1 -> V_42 << 1 ) )
V_37 = 0 ;
V_39 = F_2 ( V_2 , V_43 ) ;
if ( V_37 ) {
V_1 -> V_44 = 1 ;
V_39 |= V_45 | V_46 ;
} else {
V_1 -> V_44 = 0 ;
V_39 &= ~ ( V_45 | V_46 ) ;
}
F_9 ( V_2 , V_43 , V_39 ) ;
F_10 ( V_1 -> V_21 , L_11 , V_37 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_1 , unsigned V_47 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_39 ;
V_39 = F_2 ( V_2 , V_48 ) ;
V_39 &= ~ F_23 ( 0x3 ) ;
if ( V_47 > 0 )
V_39 |= F_23 ( V_47 & 0x3 ) ;
F_9 ( V_2 , V_48 , V_39 ) ;
}
static void F_24 ( struct V_1 * V_1 , T_3 V_49 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_39 ;
if ( ( V_49 & V_50 )
&& ( F_1 ( V_1 ) == V_51 ) )
F_8 ( V_1 , 1 ) ;
F_22 ( V_1 , 0 ) ;
V_49 |= V_52 ;
F_9 ( V_2 , V_53 , ~ V_49 ) ;
V_39 = F_2 ( V_2 , V_43 ) ;
if ( F_25 ( V_1 ) ) {
V_39 |= V_54 ;
V_39 &= ~ V_55 ;
} else {
V_39 |= V_55 ;
V_39 &= ~ V_54 ;
}
V_39 |= V_56 | V_57 ;
F_9 ( V_2 , V_43 , V_39 ) ;
F_10 ( V_1 -> V_21 , L_12 , V_49 ) ;
}
static int F_26 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_58 , V_59 ;
int V_60 = 0 ;
V_58 = F_2 ( V_2 , V_61 ) ;
V_59 = F_2 ( V_2 , V_43 ) ;
if ( ! ( V_59 & V_54 ) ) {
T_3 V_15 = V_59 ;
V_15 |= V_54 ;
F_9 ( V_2 , V_43 , V_15 ) ;
V_58 = F_2 ( V_2 , V_61 ) ;
F_9 ( V_2 , V_43 , V_59 ) ;
}
if ( V_58 & V_62 )
V_60 = 1 ;
return V_60 ;
}
static void F_27 ( unsigned long V_63 )
{
struct V_1 * V_1 = ( void * ) V_63 ;
unsigned long V_64 ;
F_28 ( & V_1 -> V_65 , V_64 ) ;
switch ( V_1 -> V_66 -> V_67 ) {
case V_68 :
if ( ( V_1 -> V_69 != 0 )
&& ( V_1 -> V_70 == 0
|| F_29 ( V_71 , V_1 -> V_70 ) ) ) {
F_10 ( V_1 -> V_21 , L_13 ,
F_30 ( V_1 -> V_66 -> V_67 ) ) ;
}
case V_72 :
F_31 ( V_1 , 0 ) ;
default:
break;
}
if ( ! V_1 -> V_73 ) {
T_3 V_74 ;
if ( F_25 ( V_1 ) && ( V_1 -> V_75 >> 16 ) )
goto V_76;
if ( ! V_1 -> V_77 ) {
V_74 = 0 ;
} else {
V_74 = V_78
| V_50
| V_79 ;
V_74 |= V_80 ;
}
F_24 ( V_1 , V_74 ) ;
}
V_76:
F_32 ( & V_1 -> V_65 , V_64 ) ;
}
static void F_33 ( struct V_1 * V_1 , unsigned long V_81 )
{
unsigned long V_82 = V_71 + F_34 ( 3 ) ;
static unsigned long V_83 ;
if ( V_81 == 0 )
V_81 = V_82 ;
if ( V_1 -> V_73 || ( ( V_1 -> V_69 == 0 )
&& ( V_1 -> V_66 -> V_67 == V_68 ) ) ) {
F_10 ( V_1 -> V_21 , L_14 ,
F_30 ( V_1 -> V_66 -> V_67 ) ) ;
F_35 ( & V_84 ) ;
V_83 = V_71 ;
return;
}
if ( F_29 ( V_83 , V_81 ) ) {
if ( ! F_36 ( & V_84 ) )
V_83 = V_81 ;
else {
F_10 ( V_1 -> V_21 , L_15 ) ;
return;
}
}
V_83 = V_81 ;
F_10 ( V_1 -> V_21 , L_16 ,
F_30 ( V_1 -> V_66 -> V_67 ) ,
( unsigned long ) F_37 ( V_81 - V_71 ) ) ;
F_38 ( & V_84 , V_81 ) ;
}
static void F_31 ( struct V_1 * V_1 , int V_85 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_30 , V_86 , V_87 ;
T_1 V_88 ;
struct V_89 * V_40 = V_1 -> V_66 -> V_40 ;
V_86 = F_2 ( V_2 , V_43 ) ;
V_30 = F_2 ( V_2 , V_90 ) ;
V_88 = F_39 ( V_1 -> V_91 , V_92 ) ;
if ( V_85 ) {
V_87 = F_40 ( V_93 ) ;
V_40 -> V_41 = 1 ;
V_1 -> V_66 -> V_67 = V_94 ;
V_88 |= V_95 ;
V_30 |= V_96 ;
F_41 ( V_1 ) ;
} else {
T_3 V_58 ;
V_87 = 0 ;
V_58 = F_2 ( V_2 , V_61 ) ;
if ( ! ( V_58 & V_97 ) ) {
switch ( V_1 -> V_66 -> V_67 ) {
case V_94 :
case V_68 :
V_1 -> V_66 -> V_67 = V_98 ;
break;
case V_98 :
V_1 -> V_66 -> V_67 = V_72 ;
break;
default:
V_1 -> V_66 -> V_67 = V_72 ;
}
V_1 -> V_73 = 0 ;
V_40 -> V_41 = 1 ;
F_41 ( V_1 ) ;
} else {
V_1 -> V_73 = 0 ;
V_40 -> V_41 = 0 ;
V_1 -> V_66 -> V_67 = V_99 ;
F_42 ( V_1 ) ;
}
V_88 &= ~ V_95 ;
V_30 &= ~ V_96 ;
}
V_86 &= ~ ( V_45 | V_46 ) ;
F_9 ( V_2 , V_43 , V_86 ) ;
F_9 ( V_2 , V_100 , V_87 ) ;
F_9 ( V_2 , V_90 , V_30 ) ;
F_43 ( V_1 -> V_91 , V_92 , V_88 ) ;
F_10 ( V_1 -> V_21 , L_17 ,
F_30 ( V_1 -> V_66 -> V_67 ) ,
F_39 ( V_1 -> V_91 , V_92 ) ,
F_2 ( V_2 , V_61 ) ,
V_30 , V_86 ) ;
}
static int F_44 ( struct V_1 * V_1 , T_1 V_101 )
{
void T_2 * V_2 = V_1 -> V_3 ;
T_3 V_58 , V_13 , V_14 , V_102 ;
V_58 = F_2 ( V_2 , V_61 ) ;
V_13 = F_2 ( V_2 , V_16 ) ;
V_14 = F_2 ( V_2 , V_17 ) ;
V_102 = F_2 ( V_2 , V_90 ) ;
switch ( V_101 ) {
case V_103 :
V_13 &= ~ V_104 ;
V_14 |= V_104 ;
V_102 |= V_105 ;
V_102 &= ~ V_106 ;
break;
case V_107 :
V_13 |= V_104 ;
V_14 |= V_104 ;
V_102 |= ( V_105 | V_106 ) ;
break;
case V_108 :
V_13 |= V_104 ;
V_14 |= V_104 ;
V_102 &= ~ ( V_105 | V_106 ) ;
break;
default:
F_10 ( V_1 -> V_21 , L_18 , V_101 ) ;
return - V_109 ;
}
F_9 ( V_2 , V_16 ,
V_18 | V_13 ) ;
F_9 ( V_2 , V_17 ,
V_18 | V_14 ) ;
F_9 ( V_2 , V_90 , V_102 ) ;
V_58 = F_2 ( V_2 , V_61 ) ;
if ( ( V_101 == V_107 ) &&
! ( V_58 & V_97 ) )
F_45 ( L_19
L_20 , V_58 ) ;
return 0 ;
}
static inline unsigned long
F_46 ( struct V_1 * V_1 , T_3 V_110 , void T_2 * V_2 )
{
T_3 V_58 = F_2 ( V_2 , V_61 ) ;
unsigned long V_70 = 0 ;
struct V_89 * V_40 = V_1 -> V_66 -> V_40 ;
if ( ( V_110 & V_111 ) ) {
int V_41 ;
V_41 = ! ( V_58 & V_97 ) ;
F_10 ( V_1 -> V_21 , L_21 , V_41 ? 'A' : 'B' ) ;
V_40 -> V_41 = V_41 ;
F_31 ( V_1 , V_41 ) ;
if ( V_41 )
V_70 = V_71 + ( V_112 * 3 ) ;
}
if ( V_110 & V_113 ) {
if ( ! V_40 -> V_41 ) {
V_1 -> V_75 &=
~ ( V_114
| V_115
| V_116
| V_117
| V_118
) ;
if ( V_58 & V_119 ) {
F_10 ( V_1 -> V_21 , L_22 ) ;
if ( V_1 -> V_66 -> V_67 != V_99 ) {
V_1 -> V_66 -> V_67 = V_99 ;
V_1 -> V_120 |= V_121 ;
}
V_1 -> V_73 = 0 ;
}
F_10 ( V_1 -> V_21 , L_23 ,
F_30 ( V_1 -> V_66 -> V_67 ) , V_58 ) ;
V_70 = V_71 + ( 1 * V_112 ) ;
F_47 ( & V_1 -> V_122 ) ;
} else {
F_10 ( V_1 -> V_21 , L_23 ,
F_30 ( V_1 -> V_66 -> V_67 ) , V_58 ) ;
switch ( V_1 -> V_66 -> V_67 ) {
case V_72 :
F_10 ( V_1 -> V_21 , L_24 ) ;
F_48 ( V_1 , 1 ) ;
if ( V_1 -> V_69 != 0 )
V_1 -> V_73 = 0 ;
else
V_1 -> V_73 = 1 ;
V_70 = V_71 + ( 2 * V_112 ) ;
break;
case V_94 :
break;
case V_98 :
if ( V_1 -> V_123 ) {
V_1 -> V_123 -- ;
F_31 ( V_1 , 1 ) ;
} else {
V_1 -> V_123
= V_124 ;
F_31 ( V_1 , 0 ) ;
}
break;
default:
break;
}
}
}
if ( V_110 & V_125 ) {
T_1 V_88 ;
F_10 ( V_1 -> V_21 , L_25 ,
F_30 ( V_1 -> V_66 -> V_67 ) , V_58 ) ;
switch ( V_1 -> V_66 -> V_67 ) {
case V_94 :
V_88 = F_39 ( V_1 -> V_91 , V_92 ) ;
if ( V_58 & V_62 ) {
if ( ( V_88 & V_126 )
!= V_126 ) {
F_10 ( V_1 -> V_21 , L_26 , V_88 ) ;
break;
}
V_1 -> V_66 -> V_67 = V_68 ;
V_1 -> V_73 = 0 ;
V_70 = V_71
+ F_34 ( V_1 -> V_69 ) ;
} else {
F_49 ( L_27 , V_88 ) ;
F_31 ( V_1 , 0 ) ;
}
break;
case V_68 :
if ( V_1 -> V_69 != 0 )
V_70 = V_71
+ F_34 ( V_1 -> V_69 ) ;
break;
case V_127 :
break;
case V_128 :
break;
default:
break;
}
}
F_47 ( & V_1 -> V_122 ) ;
return V_70 ;
}
static T_5 F_50 ( int V_129 , void * V_130 )
{
struct V_1 * V_1 = V_130 ;
void T_2 * V_2 = V_1 -> V_3 ;
unsigned long V_64 , V_70 = 0 ;
T_3 V_131 , V_110 ;
F_28 ( & V_1 -> V_65 , V_64 ) ;
V_131 = F_2 ( V_2 , V_132 ) ;
F_9 ( V_2 , V_132 , ~ V_133 ) ;
V_110 = F_2 ( V_2 , V_134 ) & ~ V_135 ;
F_10 ( V_1 -> V_21 , L_28 , V_110 ) ;
V_1 -> V_120 = ( T_1 ) V_110 ;
if ( V_110 & V_136 ) {
T_3 V_39 ;
T_3 V_26 ;
if ( F_1 ( V_1 ) == V_51 )
F_8 ( V_1 , 0 ) ;
for ( V_26 = 0xf7f7f7 ; V_26 > 0xf7f7f7 - 1000 ; V_26 -- ) {
F_9 ( V_2 , V_137 , 0 ) ;
F_9 ( V_2 , V_137 , V_26 ) ;
V_39 = F_2 ( V_2 , V_137 ) ;
if ( V_39 == V_26 )
break;
F_10 ( V_1 -> V_21 , L_29 ) ;
}
F_22 ( V_1 , 1 ) ;
V_39 = F_2 ( V_2 , V_138 ) ;
F_9 ( V_2 , V_139 , V_39 ) ;
if ( V_39 & ~ V_52 ) {
V_1 -> V_73 = 1 ;
F_47 ( & V_1 -> V_122 ) ;
}
F_10 ( V_1 -> V_21 , L_30 ,
V_1 -> V_73 ? L_31 : L_32 , V_39 ) ;
}
if ( V_110 & V_140 )
F_35 ( & V_84 ) ;
if ( V_110 & ( V_113
| V_125
| V_111 ) )
V_70 = F_46 ( V_1 , V_110 , V_2 ) ;
if ( ( V_110 & V_141 ) ) {
T_3 V_142 = F_2 ( V_2 , V_143 ) ;
T_3 V_144 = F_2 ( V_2 , V_145 ) ;
F_10 ( V_1 -> V_21 , L_33 , V_142 ) ;
V_144 = ~ V_144 & V_142 ;
if ( F_51 () && V_144 ) {
int V_146 = ( V_144 & 0xffff ) ;
int V_26 ;
for ( V_26 = 1 ; V_26 <= 15 ; V_26 ++ ) {
if ( V_146 & ( 1 << V_26 ) ) {
F_10 ( V_1 -> V_21 , L_34 , V_26 , L_35 ) ;
F_52 ( V_1 , V_26 , 1 ) ;
}
}
}
F_9 ( V_2 , V_147 , V_142 ) ;
}
if ( V_110 & ( V_148 | V_149 ) ) {
T_3 V_150 = F_2 ( V_2 , V_151 ) ;
F_9 ( V_2 , V_152 , V_150 ) ;
V_1 -> V_153 = ( ( ( V_150 >> 16 ) & 0xffff ) << 1 ) ;
V_1 -> V_154 = ( V_150 & 0xffff ) ;
} else {
V_1 -> V_153 = 0 ;
V_1 -> V_154 = 0 ;
}
if ( V_110 & ( V_148 | V_149 | 0xff ) )
F_53 ( V_1 ) ;
F_9 ( V_2 , V_155 ,
V_110 & ~ V_133 ) ;
F_33 ( V_1 , V_70 ) ;
F_9 ( V_2 , V_132 , V_131 ) ;
F_32 ( & V_1 -> V_65 , V_64 ) ;
return V_156 ;
}
static void F_54 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
F_9 ( V_2 , V_132 , V_157 ) ;
F_9 ( V_2 , V_158 , 0 ) ;
F_9 ( V_2 , V_145 , 0x7fffffff ) ;
F_9 ( V_2 , V_159 , 0x1ff ) ;
F_9 ( V_2 , V_152 , 0x7fffffff ) ;
F_9 ( V_2 , V_147 , 0x7fffffff ) ;
F_9 ( V_2 , V_160 , 0x1ff ) ;
F_9 ( V_2 , V_155 , ~ V_133 ) ;
F_9 ( V_2 , V_161 ,
F_55 ( 0 ) ) ;
F_56 ( V_1 -> V_162 , V_163 ) ;
if ( ! ( F_2 ( V_2 , V_61 )
& V_97 ) )
F_9 ( V_2 , V_164 ,
V_111 ) ;
if ( F_57 () && V_165 )
F_58 ( V_166 L_36 ,
__FILE__ , V_167 ) ;
else
V_165 = 1 ;
}
static void F_59 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
F_9 ( V_2 , V_132 , ~ V_133 ) ;
F_9 ( V_2 , V_158 , 0x7fffffff ) ;
F_9 ( V_2 , V_145 , 0x7fffffff ) ;
F_9 ( V_2 , V_159 , 0x1ff ) ;
F_35 ( & V_84 ) ;
if ( F_57 () && ! V_165 ) {
F_58 ( V_166 L_37 ,
__FILE__ , V_167 ) ;
V_165 = 1 ;
}
}
static void F_60 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
F_9 ( V_2 , V_168 , 0x0000003F ) ;
F_9 ( V_2 , V_169 , 0x01FFFFFF ) ;
F_9 ( V_2 , V_170 , F_61 ( 0x3f ) ) ;
F_9 ( V_2 , V_171 ,
F_62 ( 2 ) |
F_63 ( 0x3f ) |
F_64 ( 2 ) ) ;
F_9 ( V_2 , V_172 , 1 ) ;
}
static int F_65 ( struct V_1 * V_1 )
{
void T_2 * V_2 = V_1 -> V_3 ;
int V_60 = 0 ;
unsigned long V_64 ;
T_3 V_39 ;
if ( V_1 -> V_173 )
V_60 = V_1 -> V_173 ( 1 ) ;
if ( V_60 != 0 ) {
F_58 ( V_174 L_38 ) ;
return V_60 ;
}
F_28 ( & V_1 -> V_65 , V_64 ) ;
if ( F_2 ( V_2 , V_175 ) !=
V_176 ) {
F_58 ( V_174 L_39 ) ;
goto V_177;
}
V_60 = F_5 ( V_1 ) ;
if ( V_60 < 2 ) {
F_58 ( V_174 L_40 ,
V_60 ) ;
goto V_177;
}
F_9 ( V_2 , V_178 , 8 ) ;
F_22 ( V_1 , 1 ) ;
F_9 ( V_2 , V_43 ,
F_66 ( 0xa ) |
V_179 |
V_55 |
V_54 |
V_180 ) ;
F_60 ( V_1 ) ;
V_39 = F_2 ( V_2 , V_17 ) ;
V_39 |= V_18 | V_104 ;
F_9 ( V_2 , V_17 , V_39 ) ;
V_39 = F_2 ( V_2 , V_16 ) ;
V_39 |= V_18 | V_104 ;
F_9 ( V_2 , V_16 , V_39 ) ;
F_32 ( & V_1 -> V_65 , V_64 ) ;
return 0 ;
V_177:
F_32 ( & V_1 -> V_65 , V_64 ) ;
if ( V_1 -> V_173 )
V_1 -> V_173 ( 0 ) ;
return - V_181 ;
}
static int F_67 ( struct V_1 * V_1 )
{
struct V_182 * V_183 ;
struct V_184 * V_185 ;
void T_2 * V_186 = NULL ;
int V_60 ;
F_68 () ;
V_1 -> V_66 = F_69 ( V_187 ) ;
if ( F_70 ( V_1 -> V_66 ) )
return - V_188 ;
V_183 = F_71 ( V_1 -> V_21 ) ;
V_185 = F_72 ( V_183 , V_189 , 0 ) ;
V_1 -> V_190 = V_185 -> V_191 ;
V_185 = F_72 ( V_183 , V_189 , 1 ) ;
if ( ! V_185 ) {
F_73 ( L_41 ) ;
V_60 = - V_181 ;
goto V_76;
}
V_1 -> V_186 = V_185 -> V_191 ;
V_186 = F_74 ( V_185 -> V_191 , F_75 ( V_185 ) ) ;
if ( ! V_186 ) {
F_73 ( L_42 ) ;
V_60 = - V_192 ;
goto V_76;
}
V_1 -> V_193 = V_186 ;
V_1 -> V_91 += V_194 ;
V_60 = F_65 ( V_1 ) ;
if ( V_60 ) {
F_58 ( V_174 L_43 ,
V_60 ) ;
goto V_76;
}
V_1 -> V_195 = F_50 ;
V_1 -> V_66 -> V_196 = F_21 ;
V_38 = V_1 ;
F_76 ( & V_84 , F_27 , ( unsigned long ) V_1 ) ;
V_76:
if ( V_60 < 0 ) {
if ( V_186 )
F_77 ( V_186 ) ;
F_78 ( V_1 -> V_66 ) ;
F_79 () ;
}
return V_60 ;
}
static int F_80 ( struct V_1 * V_1 )
{
F_81 ( & V_84 ) ;
V_38 = NULL ;
if ( V_1 -> V_173 )
V_1 -> V_173 ( 0 ) ;
F_77 ( V_1 -> V_193 ) ;
F_78 ( V_1 -> V_66 ) ;
F_79 () ;
return 0 ;
}
static int F_82 ( struct V_182 * V_183 )
{
struct V_184 V_197 [ 3 ] ;
struct V_198 * V_199 = V_183 -> V_200 . V_201 ;
struct V_182 * V_1 ;
struct V_202 * V_203 ;
int V_60 = - V_192 ;
V_203 = F_83 ( sizeof( * V_203 ) , V_204 ) ;
if ( ! V_203 ) {
F_84 ( & V_183 -> V_200 , L_44 ) ;
goto V_205;
}
V_1 = F_85 ( L_45 , V_206 ) ;
if ( ! V_1 ) {
F_84 ( & V_183 -> V_200 , L_46 ) ;
goto V_207;
}
V_1 -> V_200 . V_208 = & V_183 -> V_200 ;
V_1 -> V_200 . V_209 = & V_210 ;
V_1 -> V_200 . V_211 = V_210 ;
V_203 -> V_200 = & V_183 -> V_200 ;
V_203 -> V_1 = V_1 ;
V_199 -> V_212 = & V_213 ;
F_86 ( V_183 , V_203 ) ;
memset ( V_197 , 0x00 , sizeof( * V_197 ) *
F_87 ( V_197 ) ) ;
V_197 [ 0 ] . V_214 = V_183 -> V_184 [ 0 ] . V_214 ;
V_197 [ 0 ] . V_191 = V_183 -> V_184 [ 0 ] . V_191 ;
V_197 [ 0 ] . V_215 = V_183 -> V_184 [ 0 ] . V_215 ;
V_197 [ 0 ] . V_64 = V_183 -> V_184 [ 0 ] . V_64 ;
V_197 [ 1 ] . V_214 = V_183 -> V_184 [ 1 ] . V_214 ;
V_197 [ 1 ] . V_191 = V_183 -> V_184 [ 1 ] . V_191 ;
V_197 [ 1 ] . V_215 = V_183 -> V_184 [ 1 ] . V_215 ;
V_197 [ 1 ] . V_64 = V_183 -> V_184 [ 1 ] . V_64 ;
V_197 [ 2 ] . V_214 = V_183 -> V_184 [ 2 ] . V_214 ;
V_197 [ 2 ] . V_191 = V_183 -> V_184 [ 2 ] . V_191 ;
V_197 [ 2 ] . V_215 = V_183 -> V_184 [ 2 ] . V_215 ;
V_197 [ 2 ] . V_64 = V_183 -> V_184 [ 2 ] . V_64 ;
V_60 = F_88 ( V_1 , V_197 ,
F_87 ( V_197 ) ) ;
if ( V_60 ) {
F_84 ( & V_183 -> V_200 , L_47 ) ;
goto V_216;
}
V_60 = F_89 ( V_1 , V_199 , sizeof( * V_199 ) ) ;
if ( V_60 ) {
F_84 ( & V_183 -> V_200 , L_48 ) ;
goto V_216;
}
V_60 = F_90 ( V_1 ) ;
if ( V_60 ) {
F_84 ( & V_183 -> V_200 , L_49 ) ;
goto V_216;
}
return 0 ;
V_216:
F_91 ( V_1 ) ;
V_207:
F_92 ( V_203 ) ;
V_205:
return V_60 ;
}
static int F_93 ( struct V_182 * V_183 )
{
struct V_202 * V_203 = F_94 ( V_183 ) ;
F_95 ( V_203 -> V_1 ) ;
F_92 ( V_203 ) ;
return 0 ;
}
