static int F_1 ( unsigned int * V_1 ,
unsigned int V_2 , int V_3 )
{
int V_4 ;
switch ( V_2 & V_5 ) {
case V_6 :
default:
V_4 = F_2 ( * V_1 , V_3 ) ;
break;
case V_7 :
V_4 = ( * V_1 ) / V_3 ;
break;
case V_8 :
V_4 = F_3 ( * V_1 , V_3 ) ;
break;
}
if ( V_4 < 2 )
V_4 = 2 ;
* V_1 = V_3 * V_4 ;
return V_4 - 1 ;
}
static int F_4 ( unsigned int * V_9 , unsigned int V_2 )
{
return F_1 ( V_9 , V_2 , V_10 ) ;
}
static unsigned short F_5 ( struct V_11 * V_12 ,
unsigned int V_13 , int V_14 )
{
const struct V_15 * V_16 = V_12 -> V_17 ;
unsigned int V_18 = F_6 ( V_13 ) ;
unsigned int V_19 = F_7 ( V_13 ) ;
unsigned int V_20 = F_8 ( V_13 ) ;
unsigned short V_21 = 0 ;
V_21 |= V_18 & 0xf ;
if ( V_19 < V_16 -> V_22 ) {
V_21 |= 0x000 ;
V_21 |= ( V_19 & 0x7 ) << 4 ;
} else if ( V_19 < V_16 -> V_23 ) {
V_21 |= 0x100 ;
V_21 |= ( ( V_19 - V_16 -> V_22 ) & 0x7 ) << 4 ;
} else {
V_21 |= 0x200 ;
V_21 |= ( ( V_19 - V_16 -> V_23 ) & 0x7 ) << 4 ;
}
switch ( V_20 ) {
case V_24 :
break;
case V_25 :
V_21 |= 0x80 ;
break;
case V_26 :
V_21 |= 0x400 ;
break;
case V_27 :
break;
}
return V_21 ;
}
static void F_9 ( struct V_11 * V_12 ,
unsigned int V_28 , unsigned int * V_29 )
{
if ( V_28 > 1 ) {
int V_30 ;
F_10 ( 0 , V_12 -> V_31 + V_32 ) ;
F_10 ( 1 , V_12 -> V_31 + V_33 ) ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
F_10 ( F_5 ( V_12 , V_29 [ V_30 ] , V_30 ) ,
V_12 -> V_31 + V_34 ) ;
}
} else {
F_10 ( 0 , V_12 -> V_31 + V_33 ) ;
F_10 ( F_5 ( V_12 , V_29 [ 0 ] , 0 ) ,
V_12 -> V_31 + V_35 ) ;
}
}
static int F_11 ( struct V_11 * V_12 )
{
unsigned int V_13 = F_12 ( 0 , 0 , V_24 ) ;
unsigned V_36 ;
static const unsigned V_37 = 0x2000 ;
unsigned V_38 = 0 ;
F_10 ( 0 , V_12 -> V_31 + V_39 ) ;
F_9 ( V_12 , 1 , & V_13 ) ;
F_10 ( 0 , V_12 -> V_31 + V_40 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; ++ V_36 ) {
unsigned V_41 ;
F_13 ( 0 , V_12 -> V_31 + V_42 ) ;
F_14 ( 1 , 1000 ) ;
V_41 = F_15 ( V_12 -> V_31 + V_42 ) ;
if ( ( V_41 & V_43 ) == 0 ) {
V_38 = 2 * V_36 ;
break;
}
}
if ( V_36 == V_37 ) {
F_16 ( V_12 -> V_44 , L_1 ) ;
return - V_45 ;
}
F_10 ( 0 , V_12 -> V_31 + V_39 ) ;
if ( V_38 != 0x400 && V_38 != 0x2000 ) {
F_16 ( V_12 -> V_44 ,
L_2 ,
V_38 ) ;
return - V_45 ;
}
return V_38 ;
}
static int F_17 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_50 )
{
unsigned int V_51 ;
V_51 = F_15 ( V_12 -> V_31 + V_42 ) ;
if ( V_51 & V_52 )
return 0 ;
return - V_53 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_46 * V_47 , struct V_48 * V_49 ,
unsigned int * V_54 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
unsigned int V_19 = F_7 ( V_49 -> V_13 ) ;
int V_58 ;
int V_59 ;
F_10 ( 0 , V_12 -> V_31 + V_39 ) ;
F_9 ( V_12 , 1 , & V_49 -> V_13 ) ;
F_10 ( 0 , V_12 -> V_31 + V_40 ) ;
for ( V_59 = 0 ; V_59 < V_49 -> V_59 ; V_59 ++ ) {
unsigned short V_60 ;
F_13 ( 0 , V_12 -> V_31 + V_42 ) ;
V_58 = F_19 ( V_12 , V_47 , V_49 , F_17 , 0 ) ;
if ( V_58 )
return V_58 ;
V_60 = F_20 ( V_56 -> V_61 + V_62 ) ;
V_60 >>= 3 ;
if ( F_21 ( V_47 , V_19 ) )
V_60 = F_22 ( V_47 , V_60 ) ;
V_54 [ V_59 ] = V_60 & V_47 -> V_63 ;
}
return V_59 ;
}
static int F_23 ( struct V_11 * V_12 , struct V_46 * V_47 ,
int V_64 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
struct V_65 * V_66 = V_47 -> V_66 ;
struct V_67 * V_68 = & V_66 -> V_68 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_64 ; V_30 ++ ) {
unsigned int V_19 = F_7 ( V_68 -> V_69 [ V_66 -> V_70 ] ) ;
unsigned short V_60 ;
if ( V_56 -> V_71 == 0 ) {
V_60 = F_20 ( V_56 -> V_61 + V_62 ) ;
continue;
}
V_60 = F_20 ( V_56 -> V_61 + V_62 ) ;
V_60 >>= 3 ;
if ( F_21 ( V_47 , V_19 ) )
V_60 = F_22 ( V_47 , V_60 ) ;
V_60 &= V_47 -> V_63 ;
if ( ! F_24 ( V_47 , & V_60 , 1 ) )
return - 1 ;
if ( V_56 -> V_71 > 0 )
V_56 -> V_71 -- ;
}
return 0 ;
}
static T_1 F_25 ( int V_72 , void * V_60 )
{
struct V_11 * V_12 = V_60 ;
struct V_46 * V_47 = V_12 -> V_73 ;
struct V_55 * V_56 = V_12 -> V_57 ;
T_2 V_74 ;
T_3 V_51 ;
T_3 V_41 ;
if ( ! V_12 -> V_75 )
return V_76 ;
V_41 = F_15 ( V_12 -> V_31 + V_42 ) ;
if ( ! ( V_41 & V_77 ) )
goto V_78;
V_51 = F_20 ( V_12 -> V_31 + V_79 ) ;
if ( V_51 == 0 )
return V_80 ;
if ( V_51 & V_81 ) {
if ( ! ( V_41 & V_43 ) ) {
if ( F_23 ( V_12 , V_47 , V_56 -> V_82 / 2 ) < 0 )
goto V_78;
if ( V_56 -> V_71 == 0 )
goto V_83;
} else if ( V_56 -> V_84 > 0 ) {
if ( V_41 & V_52 ) {
if ( F_23 ( V_12 , V_47 , V_56 -> V_84 ) < 0 )
goto V_78;
if ( V_56 -> V_71 == 0 )
goto V_83;
}
}
}
V_74 = F_15 ( V_12 -> V_31 + V_85 ) & 0xffff ;
if ( V_74 )
goto V_78;
F_13 ( V_51 , V_12 -> V_31 + V_86 ) ;
F_20 ( V_12 -> V_31 + V_86 ) ;
F_26 ( V_12 , V_47 ) ;
return V_80 ;
V_78:
V_47 -> V_66 -> V_87 |= V_88 ;
V_83:
V_47 -> V_66 -> V_87 |= V_89 ;
V_51 = F_20 ( V_12 -> V_31 + V_79 ) ;
F_13 ( V_51 , V_12 -> V_31 + V_86 ) ;
F_20 ( V_12 -> V_31 + V_86 ) ;
V_41 = F_15 ( V_12 -> V_31 + V_42 ) ;
V_74 = F_15 ( V_12 -> V_31 + V_85 ) & 0xffff ;
F_26 ( V_12 , V_47 ) ;
return V_80 ;
}
static int F_27 ( struct V_11 * V_12 ,
struct V_46 * V_47 , struct V_67 * V_68 )
{
int V_90 = 0 ;
unsigned int V_91 ;
V_90 |= F_28 ( & V_68 -> V_92 , V_93 ) ;
V_90 |= F_28 ( & V_68 -> V_94 ,
V_95 | V_96 ) ;
V_90 |= F_28 ( & V_68 -> V_97 ,
V_95 | V_96 ) ;
V_90 |= F_28 ( & V_68 -> V_98 , V_99 ) ;
V_90 |= F_28 ( & V_68 -> V_100 , V_99 | V_101 ) ;
if ( V_90 )
return 1 ;
V_90 |= F_29 ( V_68 -> V_94 ) ;
V_90 |= F_29 ( V_68 -> V_97 ) ;
V_90 |= F_29 ( V_68 -> V_100 ) ;
if ( V_90 )
return 2 ;
V_90 |= F_30 ( & V_68 -> V_102 , 0 ) ;
if ( V_68 -> V_94 == V_95 ) {
if ( V_68 -> V_103 == 1 ) {
if ( F_31 ( & V_68 -> V_104 ,
V_105 ) ) {
F_4 ( & V_68 -> V_104 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_32 ( & V_68 -> V_104 ,
V_107 ) ) {
F_4 ( & V_68 -> V_104 ,
V_7 ) ;
V_90 |= - V_106 ;
}
} else {
if ( F_31 ( & V_68 -> V_104 ,
V_108 ) ) {
F_4 ( & V_68 -> V_104 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_32 ( & V_68 -> V_104 ,
V_109 ) ) {
F_4 ( & V_68 -> V_104 ,
V_7 ) ;
V_90 |= - V_106 ;
}
}
} else {
V_90 |= F_32 ( & V_68 -> V_104 , 9 ) ;
}
if ( V_68 -> V_97 == V_95 ) {
if ( V_68 -> V_103 == 1 ) {
if ( F_31 ( & V_68 -> V_110 ,
V_105 ) ) {
F_4 ( & V_68 -> V_110 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_32 ( & V_68 -> V_110 ,
V_107 ) ) {
F_4 ( & V_68 -> V_110 ,
V_7 ) ;
V_90 |= - V_106 ;
}
} else {
if ( F_31 ( & V_68 -> V_110 ,
V_108 ) ) {
F_4 ( & V_68 -> V_110 ,
V_8 ) ;
V_90 |= - V_106 ;
}
if ( F_32 ( & V_68 -> V_110 ,
V_109 ) ) {
F_4 ( & V_68 -> V_110 ,
V_7 ) ;
V_90 |= - V_106 ;
}
}
} else {
V_90 |= F_32 ( & V_68 -> V_110 , 9 ) ;
}
V_90 |= F_30 ( & V_68 -> V_111 ,
V_68 -> V_103 ) ;
if ( V_68 -> V_100 == V_99 )
V_90 |= F_31 ( & V_68 -> V_112 , 1 ) ;
else
V_90 |= F_30 ( & V_68 -> V_112 , 0 ) ;
if ( V_90 )
return 3 ;
if ( V_68 -> V_94 == V_95 ) {
V_91 = V_68 -> V_104 ;
F_4 ( & V_91 , V_68 -> V_2 ) ;
V_90 |= F_30 ( & V_68 -> V_104 , V_91 ) ;
}
if ( V_68 -> V_97 == V_95 ) {
V_91 = V_68 -> V_110 ;
F_4 ( & V_91 , V_68 -> V_2 ) ;
V_90 |= F_30 ( & V_68 -> V_110 , V_91 ) ;
if ( V_68 -> V_94 == V_95 ) {
V_91 = V_68 -> V_110 * V_68 -> V_111 ;
V_90 |= F_31 ( & V_68 ->
V_104 ,
V_91 ) ;
}
}
if ( V_90 )
return 4 ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 , struct V_46 * V_47 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
struct V_67 * V_68 = & V_47 -> V_66 -> V_68 ;
int V_113 ;
F_10 ( 0 , V_12 -> V_31 + V_114 ) ;
F_10 ( 0 , V_12 -> V_31 + V_115 ) ;
F_10 ( 0 , V_12 -> V_31 + V_40 ) ;
F_13 ( 0 , V_12 -> V_31 + V_79 ) ;
F_10 ( 0 , V_12 -> V_31 + V_39 ) ;
F_10 ( 0 , V_12 -> V_31 + V_85 ) ;
F_9 ( V_12 , V_68 -> V_103 , V_68 -> V_69 ) ;
if ( V_68 -> V_103 > 1 ) {
F_10 ( 0 , V_12 -> V_31 + V_116 ) ;
F_10 ( 1 , V_12 -> V_31 + V_117 ) ;
F_10 ( 2 , V_12 -> V_31 + V_40 ) ;
} else {
F_10 ( 0 , V_12 -> V_31 + V_116 ) ;
F_10 ( 1 , V_12 -> V_31 + V_40 ) ;
}
F_10 ( ( V_56 -> V_82 / 2 - 1 ) & 0xffff , V_12 -> V_31 + V_118 ) ;
if ( V_68 -> V_94 == V_95 ) {
if ( V_68 -> V_2 & V_119 ) {
V_56 -> V_84 = V_68 -> V_103 ;
V_56 -> V_2 |= V_120 ;
} else {
V_56 -> V_84 =
( V_121 * V_68 -> V_103 ) /
V_68 -> V_104 ;
if ( V_56 -> V_84 < V_68 -> V_103 ) {
V_56 -> V_84 = V_68 -> V_103 ;
} else {
V_56 -> V_84 =
( V_56 -> V_84 +
V_68 -> V_103 - 1 )
/ V_68 -> V_103 ;
V_56 -> V_84 *= V_68 -> V_103 ;
}
V_56 -> V_2 |= V_120 ;
}
if ( V_56 -> V_84 >= ( V_56 -> V_82 / 2 ) ) {
V_56 -> V_84 = 0 ;
V_56 -> V_2 &= ~ V_120 ;
} else {
F_10 ( ( V_56 -> V_84 - 1 ) & 0xffff ,
V_12 -> V_31 + V_118 ) ;
}
} else {
V_56 -> V_84 = 0 ;
V_56 -> V_2 &= ~ V_120 ;
}
F_10 ( 1 , V_12 -> V_31 + V_122 ) ;
F_10 ( 1 , V_12 -> V_31 + V_123 ) ;
switch ( V_68 -> V_100 ) {
case V_99 :
V_56 -> V_71 = V_68 -> V_112 * V_68 -> V_103 ;
if ( ( V_56 -> V_84 > 0 ) &&
( V_56 -> V_84 > V_56 -> V_71 ) ) {
V_56 -> V_84 = V_56 -> V_71 ;
}
break;
case V_101 :
V_56 -> V_71 = - 1 ;
break;
}
switch ( V_68 -> V_94 ) {
case V_95 :
V_113 = F_4 ( & V_68 -> V_104 ,
V_6 ) ;
F_10 ( V_113 & 0xffffff , V_12 -> V_31 + V_124 ) ;
break;
case V_96 :
F_10 ( 1 , V_12 -> V_31 + V_116 ) ;
break;
}
switch ( V_68 -> V_97 ) {
case V_95 :
if ( V_68 -> V_103 > 1 ) {
V_113 = F_4 ( & V_68 -> V_110 ,
V_6 ) ;
F_10 ( V_113 & 0x3ff , V_12 -> V_31 + V_125 ) ;
}
break;
case V_96 :
F_10 ( 2 , V_12 -> V_31 + V_117 ) ;
break;
}
F_13 ( ~ 0 , V_12 -> V_31 + V_86 ) ;
F_20 ( V_12 -> V_31 + V_86 ) ;
F_13 ( V_81 , V_12 -> V_31 + V_79 ) ;
F_15 ( V_12 -> V_31 + V_115 ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 , struct V_46 * V_47 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
F_10 ( 0 , V_12 -> V_31 + V_114 ) ;
F_10 ( 0 , V_12 -> V_31 + V_115 ) ;
F_10 ( 0 , V_12 -> V_31 + V_40 ) ;
F_13 ( 0 , V_12 -> V_31 + V_79 ) ;
V_56 -> V_71 = 0 ;
F_10 ( 0 , V_12 -> V_31 + V_39 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_50 )
{
unsigned int V_18 = F_6 ( V_49 -> V_13 ) ;
unsigned int V_126 = ( V_18 == 0 ) ? V_127 : V_128 ;
unsigned int V_51 ;
V_51 = F_15 ( V_12 -> V_31 + V_42 ) ;
if ( V_51 & V_126 )
return 0 ;
return - V_53 ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_54 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
unsigned int V_18 = F_6 ( V_49 -> V_13 ) ;
unsigned int V_19 = F_7 ( V_49 -> V_13 ) ;
int V_58 ;
int V_36 ;
F_13 ( V_19 & 7 , V_12 -> V_31 + F_37 ( V_18 ) ) ;
for ( V_36 = 0 ; V_36 < V_49 -> V_59 ; ++ V_36 ) {
unsigned int V_129 = V_54 [ V_36 ] ;
if ( F_21 ( V_47 , V_19 ) ) {
V_129 = F_22 ( V_47 , V_129 ) ;
V_129 |= ( V_129 & ( ( V_47 -> V_63 + 1 ) >> 1 ) ) << 1 ;
}
V_129 <<= 3 ;
F_13 ( V_129 , V_56 -> V_61 + F_38 ( V_18 ) ) ;
F_13 ( 0 , V_12 -> V_31 + F_39 ( V_18 ) ) ;
V_58 = F_19 ( V_12 , V_47 , V_49 , F_35 , 0 ) ;
if ( V_58 )
return V_58 ;
V_47 -> V_130 [ V_18 ] = V_54 [ V_36 ] ;
}
return V_49 -> V_59 ;
}
static int F_40 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_54 )
{
if ( F_41 ( V_47 , V_54 ) )
F_13 ( V_47 -> V_131 & 0xff , V_12 -> V_31 + V_132 ) ;
V_54 [ 1 ] = F_20 ( V_12 -> V_31 + V_132 ) & 0xff ;
return V_49 -> V_59 ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_54 )
{
int V_58 ;
V_58 = F_43 ( V_12 , V_47 , V_49 , V_54 , 0 ) ;
if ( V_58 )
return V_58 ;
F_13 ( 0x01 , V_12 -> V_31 + V_133 ) ;
F_13 ( V_47 -> V_134 & 0xff , V_12 -> V_31 + V_135 ) ;
F_13 ( 0x00 , V_12 -> V_31 + V_133 ) ;
return V_49 -> V_59 ;
}
static int F_44 ( struct V_11 * V_12 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_54 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
unsigned int V_18 = F_6 ( V_49 -> V_13 ) ;
unsigned int V_136 ;
unsigned int V_137 ;
switch ( V_54 [ 0 ] ) {
case V_138 :
V_137 = V_54 [ 2 ] ;
V_136 = ( V_18 == 0 ) ? 3 : 4 ;
if ( V_137 > V_136 )
return - V_106 ;
V_56 -> V_139 [ V_18 ] = V_137 ;
F_45 ( V_137 , V_12 -> V_31 + F_46 ( V_18 ) ) ;
break;
case V_140 :
V_54 [ 2 ] = V_56 -> V_139 [ V_18 ] ;
break;
case V_141 :
V_137 = V_54 [ 1 ] ;
switch ( V_18 ) {
case 0 :
V_136 = 3 ;
break;
case 1 :
V_136 = 5 ;
break;
case 2 :
V_136 = 4 ;
break;
default:
return - V_106 ;
}
if ( V_137 > V_136 )
return - V_106 ;
V_56 -> V_142 [ V_18 ] = V_137 ;
F_45 ( V_137 , V_12 -> V_31 + F_47 ( V_18 ) ) ;
break;
case V_143 :
V_137 = V_56 -> V_142 [ V_18 ] ;
V_54 [ 1 ] = V_56 -> V_142 [ V_18 ] ;
V_54 [ 2 ] = ( V_137 == 0 ) ? V_10 : 0 ;
break;
default:
return - V_106 ;
}
return V_49 -> V_59 ;
}
static void F_48 ( struct V_11 * V_12 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
F_10 ( 0 , V_12 -> V_31 + V_144 ) ;
F_14 ( 100 , 1000 ) ;
F_10 ( 0 , V_56 -> V_145 + V_146 ) ;
F_13 ( 0 , V_12 -> V_31 + V_79 ) ;
F_13 ( ~ 0 , V_12 -> V_31 + V_86 ) ;
F_20 ( V_12 -> V_31 + V_86 ) ;
}
static void F_49 ( struct V_11 * V_12 )
{
F_48 ( V_12 ) ;
F_10 ( 0 , V_12 -> V_31 + V_85 ) ;
F_10 ( 0 , V_12 -> V_31 + V_32 ) ;
F_10 ( 0 , V_12 -> V_31 + V_39 ) ;
F_10 ( 0 , V_12 -> V_31 + F_50 ( 0 ) ) ;
F_10 ( 0 , V_12 -> V_31 + F_50 ( 1 ) ) ;
F_13 ( 0 , V_12 -> V_31 + V_133 ) ;
}
static void F_51 ( struct V_11 * V_12 ,
struct V_147 * V_148 )
{
unsigned char V_149 ;
F_52 ( V_148 , V_150 , & V_149 ) ;
if ( V_149 < 32 ) {
F_16 ( V_12 -> V_44 ,
L_3 ,
V_149 , 32 ) ;
F_53 ( V_148 , V_150 , 32 ) ;
}
}
static int F_54 ( struct V_11 * V_12 ,
unsigned long V_50 )
{
struct V_147 * V_148 = F_55 ( V_12 ) ;
const struct V_15 * V_16 = NULL ;
struct V_55 * V_56 ;
struct V_46 * V_47 ;
int V_58 ;
if ( V_50 < F_56 ( V_151 ) )
V_16 = & V_151 [ V_50 ] ;
if ( ! V_16 )
return - V_152 ;
V_12 -> V_17 = V_16 ;
V_12 -> V_153 = V_16 -> V_154 ;
V_56 = F_57 ( V_12 , sizeof( * V_56 ) ) ;
if ( ! V_56 )
return - V_155 ;
V_58 = F_58 ( V_12 ) ;
if ( V_58 )
return V_58 ;
V_12 -> V_31 = F_59 ( V_148 , 2 ) ;
V_56 -> V_61 = F_59 ( V_148 , 3 ) ;
V_56 -> V_145 = F_59 ( V_148 , 0 ) ;
if ( ! V_12 -> V_31 || ! V_56 -> V_61 || ! V_56 -> V_145 )
return - V_155 ;
F_51 ( V_12 , V_148 ) ;
if ( V_148 -> V_72 ) {
V_58 = F_60 ( V_148 -> V_72 , F_25 , V_156 ,
V_12 -> V_153 , V_12 ) ;
if ( V_58 == 0 )
V_12 -> V_72 = V_148 -> V_72 ;
}
V_58 = F_61 ( V_12 , 4 ) ;
if ( V_58 )
return V_58 ;
V_47 = & V_12 -> V_157 [ 0 ] ;
V_47 -> type = V_158 ;
V_47 -> V_159 = V_160 | V_161 | V_162 | V_163 ;
V_47 -> V_28 = 16 ;
V_47 -> V_63 = 0x0fff ;
V_47 -> V_164 = V_16 -> V_165 ;
V_47 -> V_166 = V_167 ;
V_47 -> V_168 = F_18 ;
if ( V_12 -> V_72 ) {
V_12 -> V_73 = V_47 ;
V_47 -> V_159 |= V_169 ;
V_47 -> V_170 = F_33 ;
V_47 -> V_171 = F_27 ;
V_47 -> V_172 = F_34 ;
}
V_47 = & V_12 -> V_157 [ 1 ] ;
V_47 -> type = V_173 ;
V_47 -> V_159 = V_174 ;
V_47 -> V_28 = 2 ;
V_47 -> V_63 = 0x0fff ;
V_47 -> V_164 = & V_175 ;
V_47 -> V_176 = F_36 ;
V_58 = F_62 ( V_47 ) ;
if ( V_58 )
return V_58 ;
V_47 = & V_12 -> V_157 [ 2 ] ;
V_47 -> type = V_177 ;
V_47 -> V_159 = V_160 | V_174 ;
V_47 -> V_28 = 8 ;
V_47 -> V_63 = 1 ;
V_47 -> V_164 = & V_178 ;
V_47 -> V_179 = F_40 ;
V_47 -> V_180 = F_42 ;
V_47 = & V_12 -> V_157 [ 3 ] ;
V_12 -> V_181 = F_63 ( V_12 -> V_31 + V_182 ,
V_10 , V_183 , 2 ) ;
if ( ! V_12 -> V_181 )
return - V_155 ;
F_64 ( V_47 , V_12 -> V_181 ) ;
V_12 -> V_181 -> V_180 = F_44 ;
F_49 ( V_12 ) ;
V_58 = F_11 ( V_12 ) ;
if ( V_58 < 0 )
return V_58 ;
V_56 -> V_82 = V_58 ;
if ( V_12 -> V_72 )
F_10 ( V_184 | V_185 , V_56 -> V_145 + V_146 ) ;
return 0 ;
}
static void F_65 ( struct V_11 * V_12 )
{
struct V_55 * V_56 = V_12 -> V_57 ;
if ( V_56 ) {
if ( V_12 -> V_31 && V_56 -> V_145 )
F_48 ( V_12 ) ;
if ( V_12 -> V_72 )
F_66 ( V_12 -> V_72 , V_12 ) ;
if ( V_12 -> V_31 )
F_67 ( V_12 -> V_31 ) ;
if ( V_56 -> V_61 )
F_67 ( V_56 -> V_61 ) ;
if ( V_56 -> V_145 )
F_67 ( V_56 -> V_145 ) ;
}
F_68 ( V_12 ) ;
}
static int F_69 ( struct V_147 * V_12 ,
const struct V_186 * V_187 )
{
return F_70 ( V_12 , & V_188 , V_187 -> V_189 ) ;
}
