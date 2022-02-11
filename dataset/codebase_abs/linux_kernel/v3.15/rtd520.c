static int F_1 ( unsigned int * V_1 ,
int V_2 , int V_3 )
{
int V_4 ;
switch ( V_2 ) {
case V_5 :
default:
V_4 = ( * V_1 + V_3 / 2 ) / V_3 ;
break;
case V_6 :
V_4 = ( * V_1 ) / V_3 ;
break;
case V_7 :
V_4 = ( * V_1 + V_3 - 1 ) / V_3 ;
break;
}
if ( V_4 < 2 )
V_4 = 2 ;
* V_1 = V_3 * V_4 ;
return V_4 - 1 ;
}
static int F_2 ( unsigned int * V_8 , int V_2 )
{
return F_1 ( V_8 , V_2 , V_9 ) ;
}
static unsigned short F_3 ( struct V_10 * V_11 ,
unsigned int V_12 , int V_13 )
{
const struct V_14 * V_15 = F_4 ( V_11 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned int V_19 = F_5 ( V_12 ) ;
unsigned int V_20 = F_6 ( V_12 ) ;
unsigned int V_21 = F_7 ( V_12 ) ;
unsigned short V_22 = 0 ;
V_22 |= V_19 & 0xf ;
if ( V_20 < V_15 -> V_23 ) {
V_22 |= 0x000 ;
V_22 |= ( V_20 & 0x7 ) << 4 ;
F_8 ( V_13 , V_17 -> V_24 ) ;
} else if ( V_20 < V_15 -> V_25 ) {
V_22 |= 0x100 ;
V_22 |= ( ( V_20 - V_15 -> V_23 ) & 0x7 ) << 4 ;
F_8 ( V_13 , V_17 -> V_24 ) ;
} else {
V_22 |= 0x200 ;
V_22 |= ( ( V_20 - V_15 -> V_25 ) & 0x7 ) << 4 ;
F_9 ( V_13 , V_17 -> V_24 ) ;
}
switch ( V_21 ) {
case V_26 :
break;
case V_27 :
V_22 |= 0x80 ;
break;
case V_28 :
V_22 |= 0x400 ;
break;
case V_29 :
break;
}
return V_22 ;
}
static void F_10 ( struct V_10 * V_11 ,
unsigned int V_30 , unsigned int * V_31 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_30 > 1 ) {
int V_32 ;
F_11 ( 0 , V_17 -> V_33 + V_34 ) ;
F_11 ( 1 , V_17 -> V_33 + V_35 ) ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ ) {
F_11 ( F_3 ( V_11 , V_31 [ V_32 ] , V_32 ) ,
V_17 -> V_33 + V_36 ) ;
}
} else {
F_11 ( 0 , V_17 -> V_33 + V_35 ) ;
F_11 ( F_3 ( V_11 , V_31 [ 0 ] , 0 ) ,
V_17 -> V_33 + V_37 ) ;
}
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned int V_12 = F_13 ( 0 , 0 , V_26 ) ;
unsigned V_38 ;
static const unsigned V_39 = 0x2000 ;
unsigned V_40 = 0 ;
F_11 ( 0 , V_17 -> V_33 + V_41 ) ;
F_10 ( V_11 , 1 , & V_12 ) ;
F_11 ( 0 , V_17 -> V_33 + V_42 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
unsigned V_43 ;
F_14 ( 0 , V_17 -> V_33 + V_44 ) ;
F_15 ( 1 ) ;
V_43 = F_16 ( V_17 -> V_33 + V_44 ) ;
if ( ( V_43 & V_45 ) == 0 ) {
V_40 = 2 * V_38 ;
break;
}
}
if ( V_38 == V_39 ) {
F_17 ( V_11 -> V_46 , L_1 ) ;
return - V_47 ;
}
F_11 ( 0 , V_17 -> V_33 + V_41 ) ;
if ( V_40 != 0x400 && V_40 != 0x2000 ) {
F_17 ( V_11 -> V_46 ,
L_2 ,
V_40 ) ;
return - V_47 ;
}
return V_40 ;
}
static int F_18 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
unsigned long V_52 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned int V_53 ;
V_53 = F_16 ( V_17 -> V_33 + V_44 ) ;
if ( V_53 & V_54 )
return 0 ;
return - V_55 ;
}
static int F_19 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_50 * V_51 ,
unsigned int * V_56 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_57 ;
int V_58 ;
F_11 ( 0 , V_17 -> V_33 + V_41 ) ;
F_10 ( V_11 , 1 , & V_51 -> V_12 ) ;
F_11 ( 0 , V_17 -> V_33 + V_42 ) ;
for ( V_58 = 0 ; V_58 < V_51 -> V_58 ; V_58 ++ ) {
unsigned short V_59 ;
F_14 ( 0 , V_17 -> V_33 + V_44 ) ;
V_57 = F_20 ( V_11 , V_49 , V_51 , F_18 , 0 ) ;
if ( V_57 )
return V_57 ;
V_59 = F_21 ( V_17 -> V_60 + V_61 ) ;
V_59 = V_59 >> 3 ;
if ( F_22 ( 0 , V_17 -> V_24 ) )
V_59 = F_23 ( V_49 , V_59 ) ;
V_56 [ V_58 ] = V_59 & V_49 -> V_62 ;
}
return V_58 ;
}
static int F_24 ( struct V_10 * V_11 , struct V_48 * V_49 ,
int V_63 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_63 ; V_32 ++ ) {
unsigned short V_59 ;
if ( 0 == V_17 -> V_64 ) {
V_59 = F_21 ( V_17 -> V_60 + V_61 ) ;
continue;
}
V_59 = F_21 ( V_17 -> V_60 + V_61 ) ;
V_59 = V_59 >> 3 ;
if ( F_22 ( V_49 -> V_65 -> V_66 , V_17 -> V_24 ) )
V_59 = F_23 ( V_49 , V_59 ) ;
V_59 &= V_49 -> V_62 ;
if ( ! F_25 ( V_49 -> V_65 , V_59 ) )
return - 1 ;
if ( V_17 -> V_64 > 0 )
V_17 -> V_64 -- ;
}
return 0 ;
}
static int F_26 ( struct V_10 * V_11 , struct V_48 * V_49 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
while ( F_16 ( V_17 -> V_33 + V_44 ) & V_54 ) {
unsigned short V_59 = F_21 ( V_17 -> V_60 + V_61 ) ;
if ( 0 == V_17 -> V_64 ) {
continue;
}
V_59 = V_59 >> 3 ;
if ( F_22 ( V_49 -> V_65 -> V_66 , V_17 -> V_24 ) )
V_59 = F_23 ( V_49 , V_59 ) ;
V_59 &= V_49 -> V_62 ;
if ( ! F_25 ( V_49 -> V_65 , V_59 ) )
return - 1 ;
if ( V_17 -> V_64 > 0 )
V_17 -> V_64 -- ;
}
return 0 ;
}
static T_1 F_27 ( int V_67 , void * V_59 )
{
struct V_10 * V_11 = V_59 ;
struct V_48 * V_49 = V_11 -> V_68 ;
struct V_16 * V_17 = V_11 -> V_18 ;
T_2 V_69 ;
T_3 V_53 ;
T_3 V_43 ;
if ( ! V_11 -> V_70 )
return V_71 ;
V_43 = F_16 ( V_17 -> V_33 + V_44 ) ;
if ( ! ( V_43 & V_72 ) )
goto V_73;
V_53 = F_21 ( V_17 -> V_33 + V_74 ) ;
if ( 0 == V_53 )
return V_75 ;
if ( V_53 & V_76 ) {
if ( ! ( V_43 & V_45 ) ) {
if ( F_24 ( V_11 , V_49 , V_17 -> V_77 / 2 ) < 0 )
goto V_73;
if ( 0 == V_17 -> V_64 )
goto V_78;
F_28 ( V_11 , V_49 ) ;
} else if ( V_17 -> V_79 > 0 ) {
if ( V_43 & V_54 ) {
if ( F_24 ( V_11 , V_49 , V_17 -> V_79 ) < 0 )
goto V_73;
if ( 0 == V_17 -> V_64 )
goto V_78;
F_28 ( V_11 , V_49 ) ;
}
}
}
V_69 = F_16 ( V_17 -> V_33 + V_80 ) & 0xffff ;
if ( V_69 )
goto V_73;
F_14 ( V_53 , V_17 -> V_33 + V_81 ) ;
F_21 ( V_17 -> V_33 + V_81 ) ;
return V_75 ;
V_73:
F_11 ( 0 , V_17 -> V_33 + V_41 ) ;
V_49 -> V_65 -> V_82 |= V_83 ;
V_17 -> V_64 = 0 ;
V_78:
F_11 ( 0 , V_17 -> V_33 + V_84 ) ;
F_11 ( 0 , V_17 -> V_33 + V_85 ) ;
F_11 ( 0 , V_17 -> V_33 + V_42 ) ;
F_14 ( 0 , V_17 -> V_33 + V_74 ) ;
if ( V_17 -> V_64 > 0 ) {
V_43 = F_16 ( V_17 -> V_33 + V_44 ) ;
F_26 ( V_11 , V_49 ) ;
}
V_49 -> V_65 -> V_82 |= V_86 ;
F_28 ( V_11 , V_49 ) ;
V_53 = F_21 ( V_17 -> V_33 + V_74 ) ;
F_14 ( V_53 , V_17 -> V_33 + V_81 ) ;
F_21 ( V_17 -> V_33 + V_81 ) ;
V_43 = F_16 ( V_17 -> V_33 + V_44 ) ;
V_69 = F_16 ( V_17 -> V_33 + V_80 ) & 0xffff ;
return V_75 ;
}
static int F_29 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_87 * V_88 )
{
int V_89 = 0 ;
int V_90 ;
V_89 |= F_30 ( & V_88 -> V_91 , V_92 ) ;
V_89 |= F_30 ( & V_88 -> V_93 ,
V_94 | V_95 ) ;
V_89 |= F_30 ( & V_88 -> V_96 , V_94 | V_95 ) ;
V_89 |= F_30 ( & V_88 -> V_97 , V_98 ) ;
V_89 |= F_30 ( & V_88 -> V_99 , V_98 | V_100 ) ;
if ( V_89 )
return 1 ;
V_89 |= F_31 ( V_88 -> V_93 ) ;
V_89 |= F_31 ( V_88 -> V_96 ) ;
V_89 |= F_31 ( V_88 -> V_99 ) ;
if ( V_89 )
return 2 ;
V_89 |= F_32 ( & V_88 -> V_101 , 0 ) ;
if ( V_88 -> V_93 == V_94 ) {
if ( 1 == V_88 -> V_102 ) {
if ( F_33 ( & V_88 -> V_103 ,
V_104 ) ) {
F_2 ( & V_88 -> V_103 ,
V_7 ) ;
V_89 |= - V_105 ;
}
if ( F_34 ( & V_88 -> V_103 ,
V_106 ) ) {
F_2 ( & V_88 -> V_103 ,
V_6 ) ;
V_89 |= - V_105 ;
}
} else {
if ( F_33 ( & V_88 -> V_103 ,
V_107 ) ) {
F_2 ( & V_88 -> V_103 ,
V_7 ) ;
V_89 |= - V_105 ;
}
if ( F_34 ( & V_88 -> V_103 ,
V_108 ) ) {
F_2 ( & V_88 -> V_103 ,
V_6 ) ;
V_89 |= - V_105 ;
}
}
} else {
V_89 |= F_34 ( & V_88 -> V_103 , 9 ) ;
}
if ( V_88 -> V_96 == V_94 ) {
if ( 1 == V_88 -> V_102 ) {
if ( F_33 ( & V_88 -> V_109 ,
V_104 ) ) {
F_2 ( & V_88 -> V_109 ,
V_7 ) ;
V_89 |= - V_105 ;
}
if ( F_34 ( & V_88 -> V_109 ,
V_106 ) ) {
F_2 ( & V_88 -> V_109 ,
V_6 ) ;
V_89 |= - V_105 ;
}
} else {
if ( F_33 ( & V_88 -> V_109 ,
V_107 ) ) {
F_2 ( & V_88 -> V_109 ,
V_7 ) ;
V_89 |= - V_105 ;
}
if ( F_34 ( & V_88 -> V_109 ,
V_108 ) ) {
F_2 ( & V_88 -> V_109 ,
V_6 ) ;
V_89 |= - V_105 ;
}
}
} else {
V_89 |= F_34 ( & V_88 -> V_109 , 9 ) ;
}
if ( V_88 -> V_99 == V_98 ) {
} else {
V_89 |= F_32 ( & V_88 -> V_110 , 0 ) ;
}
if ( V_89 )
return 3 ;
if ( V_88 -> V_102 > V_111 ) {
V_88 -> V_102 = V_111 ;
V_89 ++ ;
}
if ( V_88 -> V_93 == V_94 ) {
V_90 = V_88 -> V_103 ;
F_2 ( & V_88 -> V_103 ,
V_88 -> V_112 & V_113 ) ;
if ( V_90 != V_88 -> V_103 )
V_89 ++ ;
}
if ( V_88 -> V_96 == V_94 ) {
V_90 = V_88 -> V_109 ;
F_2 ( & V_88 -> V_109 ,
V_88 -> V_112 & V_113 ) ;
if ( V_90 != V_88 -> V_109 )
V_89 ++ ;
if ( V_88 -> V_93 == V_94
&& ( V_88 -> V_103
< ( V_88 -> V_109 * V_88 -> V_114 ) ) ) {
V_88 -> V_103 =
V_88 -> V_109 * V_88 -> V_114 ;
V_89 ++ ;
}
}
if ( V_89 )
return 4 ;
return 0 ;
}
static int F_35 ( struct V_10 * V_11 , struct V_48 * V_49 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_87 * V_88 = & V_49 -> V_65 -> V_88 ;
int V_115 ;
F_11 ( 0 , V_17 -> V_33 + V_84 ) ;
F_11 ( 0 , V_17 -> V_33 + V_85 ) ;
F_11 ( 0 , V_17 -> V_33 + V_42 ) ;
F_14 ( 0 , V_17 -> V_33 + V_74 ) ;
F_11 ( 0 , V_17 -> V_33 + V_41 ) ;
F_11 ( 0 , V_17 -> V_33 + V_80 ) ;
F_10 ( V_11 , V_88 -> V_102 , V_88 -> V_116 ) ;
if ( V_88 -> V_102 > 1 ) {
F_11 ( 0 , V_17 -> V_33 + V_117 ) ;
F_11 ( 1 , V_17 -> V_33 + V_118 ) ;
F_11 ( 2 , V_17 -> V_33 + V_42 ) ;
} else {
F_11 ( 0 , V_17 -> V_33 + V_117 ) ;
F_11 ( 1 , V_17 -> V_33 + V_42 ) ;
}
F_11 ( ( V_17 -> V_77 / 2 - 1 ) & 0xffff , V_17 -> V_33 + V_119 ) ;
if ( V_94 == V_88 -> V_93 ) {
if ( V_88 -> V_112 & V_120 ) {
V_17 -> V_79 = V_88 -> V_102 ;
V_17 -> V_112 |= V_121 ;
} else {
V_17 -> V_79 =
( V_122 * V_88 -> V_102 ) /
V_88 -> V_103 ;
if ( V_17 -> V_79 < V_88 -> V_102 ) {
V_17 -> V_79 = V_88 -> V_102 ;
} else {
V_17 -> V_79 =
( V_17 -> V_79 +
V_88 -> V_102 - 1 )
/ V_88 -> V_102 ;
V_17 -> V_79 *= V_88 -> V_102 ;
}
V_17 -> V_112 |= V_121 ;
}
if ( V_17 -> V_79 >= ( V_17 -> V_77 / 2 ) ) {
V_17 -> V_79 = 0 ;
V_17 -> V_112 &= ~ V_121 ;
} else {
F_11 ( ( V_17 -> V_79 - 1 ) & 0xffff ,
V_17 -> V_33 + V_119 ) ;
}
} else {
V_17 -> V_79 = 0 ;
V_17 -> V_112 &= ~ V_121 ;
}
F_11 ( 1 , V_17 -> V_33 + V_123 ) ;
F_11 ( 1 , V_17 -> V_33 + V_124 ) ;
switch ( V_88 -> V_99 ) {
case V_98 :
V_17 -> V_64 = V_88 -> V_110 * V_88 -> V_102 ;
if ( ( V_17 -> V_79 > 0 )
&& ( V_17 -> V_79 > V_17 -> V_64 ) ) {
V_17 -> V_79 = V_17 -> V_64 ;
}
break;
case V_100 :
V_17 -> V_64 = - 1 ;
break;
}
switch ( V_88 -> V_93 ) {
case V_94 :
V_115 = F_2 ( & V_88 -> V_103 ,
V_5 ) ;
F_11 ( V_115 & 0xffffff , V_17 -> V_33 + V_125 ) ;
break;
case V_95 :
F_11 ( 1 , V_17 -> V_33 + V_117 ) ;
break;
}
switch ( V_88 -> V_96 ) {
case V_94 :
if ( V_88 -> V_102 > 1 ) {
V_115 = F_2 ( & V_88 -> V_109 ,
V_5 ) ;
F_11 ( V_115 & 0x3ff , V_17 -> V_33 + V_126 ) ;
}
break;
case V_95 :
F_11 ( 2 , V_17 -> V_33 + V_118 ) ;
break;
}
F_14 ( ~ 0 , V_17 -> V_33 + V_81 ) ;
F_21 ( V_17 -> V_33 + V_81 ) ;
if ( V_17 -> V_79 > 0 ) {
F_14 ( V_76 , V_17 -> V_33 + V_74 ) ;
} else {
F_14 ( V_76 , V_17 -> V_33 + V_74 ) ;
}
F_16 ( V_17 -> V_33 + V_85 ) ;
return 0 ;
}
static int F_36 ( struct V_10 * V_11 , struct V_48 * V_49 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
T_2 V_69 ;
T_3 V_53 ;
F_11 ( 0 , V_17 -> V_33 + V_84 ) ;
F_11 ( 0 , V_17 -> V_33 + V_85 ) ;
F_11 ( 0 , V_17 -> V_33 + V_42 ) ;
F_14 ( 0 , V_17 -> V_33 + V_74 ) ;
V_17 -> V_64 = 0 ;
V_53 = F_21 ( V_17 -> V_33 + V_74 ) ;
V_69 = F_16 ( V_17 -> V_33 + V_80 ) & 0xffff ;
return 0 ;
}
static int F_37 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
unsigned long V_52 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned int V_19 = F_5 ( V_51 -> V_12 ) ;
unsigned int V_127 = ( V_19 == 0 ) ? V_128 : V_129 ;
unsigned int V_53 ;
V_53 = F_16 ( V_17 -> V_33 + V_44 ) ;
if ( V_53 & V_127 )
return 0 ;
return - V_55 ;
}
static int F_38 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_50 * V_51 ,
unsigned int * V_56 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_38 ;
int V_19 = F_5 ( V_51 -> V_12 ) ;
int V_20 = F_6 ( V_51 -> V_12 ) ;
int V_57 ;
F_14 ( V_20 & 7 , V_17 -> V_33 +
( ( V_19 == 0 ) ? V_130 : V_131 ) ) ;
for ( V_38 = 0 ; V_38 < V_51 -> V_58 ; ++ V_38 ) {
int V_132 = V_56 [ V_38 ] << 3 ;
if ( ( V_20 > 1 )
&& ( V_56 [ V_38 ] < 2048 ) ) {
V_132 = ( ( ( int ) V_56 [ V_38 ] ) - 2048 ) << 3 ;
} else {
V_132 = V_56 [ V_38 ] << 3 ;
}
F_14 ( V_132 , V_17 -> V_60 +
( ( V_19 == 0 ) ? V_133 : V_134 ) ) ;
F_14 ( 0 , V_17 -> V_33 +
( ( V_19 == 0 ) ? V_135 : V_136 ) ) ;
V_17 -> V_137 [ V_19 ] = V_56 [ V_38 ] ;
V_57 = F_20 ( V_11 , V_49 , V_51 , F_37 , 0 ) ;
if ( V_57 )
return V_57 ;
}
return V_38 ;
}
static int F_39 ( struct V_10 * V_11 ,
struct V_48 * V_49 , struct V_50 * V_51 ,
unsigned int * V_56 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_38 ;
int V_19 = F_5 ( V_51 -> V_12 ) ;
for ( V_38 = 0 ; V_38 < V_51 -> V_58 ; V_38 ++ )
V_56 [ V_38 ] = V_17 -> V_137 [ V_19 ] ;
return V_38 ;
}
static int F_40 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
unsigned int * V_56 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( F_41 ( V_49 , V_56 ) )
F_14 ( V_49 -> V_138 & 0xff , V_17 -> V_33 + V_139 ) ;
V_56 [ 1 ] = F_21 ( V_17 -> V_33 + V_139 ) & 0xff ;
return V_51 -> V_58 ;
}
static int F_42 ( struct V_10 * V_11 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
unsigned int * V_56 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_57 ;
V_57 = F_43 ( V_11 , V_49 , V_51 , V_56 , 0 ) ;
if ( V_57 )
return V_57 ;
F_14 ( 0x01 , V_17 -> V_33 + V_140 ) ;
F_14 ( V_49 -> V_141 & 0xff , V_17 -> V_33 + V_142 ) ;
F_14 ( 0x00 , V_17 -> V_33 + V_140 ) ;
return V_51 -> V_58 ;
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
F_11 ( 0 , V_17 -> V_33 + V_143 ) ;
F_15 ( 100 ) ;
F_11 ( 0 , V_17 -> V_144 + V_145 ) ;
F_14 ( 0 , V_17 -> V_33 + V_74 ) ;
F_14 ( ~ 0 , V_17 -> V_33 + V_81 ) ;
F_21 ( V_17 -> V_33 + V_81 ) ;
}
static void F_45 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
F_44 ( V_11 ) ;
F_11 ( 0 , V_17 -> V_33 + V_80 ) ;
F_11 ( 0 , V_17 -> V_33 + V_34 ) ;
F_11 ( 0 , V_17 -> V_33 + V_41 ) ;
F_11 ( 0 , V_17 -> V_33 + V_146 ) ;
F_11 ( 0 , V_17 -> V_33 + V_147 ) ;
F_14 ( 0 , V_17 -> V_33 + V_140 ) ;
F_46 ( ( 0 << 6 ) | 0x30 , V_17 -> V_33 + V_148 ) ;
F_46 ( ( 1 << 6 ) | 0x30 , V_17 -> V_33 + V_148 ) ;
F_46 ( ( 2 << 6 ) | 0x30 , V_17 -> V_33 + V_148 ) ;
F_46 ( ( 3 << 6 ) | 0x00 , V_17 -> V_33 + V_148 ) ;
}
static void F_47 ( struct V_10 * V_11 ,
struct V_149 * V_150 )
{
unsigned char V_151 ;
F_48 ( V_150 , V_152 , & V_151 ) ;
if ( V_151 < 32 ) {
F_17 ( V_11 -> V_46 ,
L_3 ,
V_151 , 32 ) ;
F_49 ( V_150 , V_152 , 32 ) ;
}
}
static int F_50 ( struct V_10 * V_11 ,
unsigned long V_52 )
{
struct V_149 * V_150 = F_51 ( V_11 ) ;
const struct V_14 * V_15 = NULL ;
struct V_16 * V_17 ;
struct V_48 * V_49 ;
int V_57 ;
if ( V_52 < F_52 ( V_153 ) )
V_15 = & V_153 [ V_52 ] ;
if ( ! V_15 )
return - V_154 ;
V_11 -> V_155 = V_15 ;
V_11 -> V_156 = V_15 -> V_157 ;
V_17 = F_53 ( V_11 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_158 ;
V_57 = F_54 ( V_11 ) ;
if ( V_57 )
return V_57 ;
V_17 -> V_33 = F_55 ( V_150 , 2 ) ;
V_17 -> V_60 = F_55 ( V_150 , 3 ) ;
V_17 -> V_144 = F_55 ( V_150 , 0 ) ;
if ( ! V_17 -> V_33 || ! V_17 -> V_60 || ! V_17 -> V_144 )
return - V_158 ;
F_47 ( V_11 , V_150 ) ;
if ( V_150 -> V_67 ) {
V_57 = F_56 ( V_150 -> V_67 , F_27 , V_159 ,
V_11 -> V_156 , V_11 ) ;
if ( V_57 == 0 )
V_11 -> V_67 = V_150 -> V_67 ;
}
V_57 = F_57 ( V_11 , 4 ) ;
if ( V_57 )
return V_57 ;
V_49 = & V_11 -> V_160 [ 0 ] ;
V_49 -> type = V_161 ;
V_49 -> V_162 = V_163 | V_164 | V_165 | V_166 ;
V_49 -> V_30 = 16 ;
V_49 -> V_62 = 0x0fff ;
V_49 -> V_167 = V_15 -> V_168 ;
V_49 -> V_169 = V_111 ;
V_49 -> V_170 = F_19 ;
if ( V_11 -> V_67 ) {
V_11 -> V_68 = V_49 ;
V_49 -> V_162 |= V_171 ;
V_49 -> V_172 = F_35 ;
V_49 -> V_173 = F_29 ;
V_49 -> V_174 = F_36 ;
}
V_49 = & V_11 -> V_160 [ 1 ] ;
V_49 -> type = V_175 ;
V_49 -> V_162 = V_176 ;
V_49 -> V_30 = 2 ;
V_49 -> V_62 = 0x0fff ;
V_49 -> V_167 = & V_177 ;
V_49 -> V_178 = F_38 ;
V_49 -> V_170 = F_39 ;
V_49 = & V_11 -> V_160 [ 2 ] ;
V_49 -> type = V_179 ;
V_49 -> V_162 = V_163 | V_176 ;
V_49 -> V_30 = 8 ;
V_49 -> V_62 = 1 ;
V_49 -> V_167 = & V_180 ;
V_49 -> V_181 = F_40 ;
V_49 -> V_182 = F_42 ;
V_49 = & V_11 -> V_160 [ 3 ] ;
V_49 -> type = V_183 ;
V_49 -> V_162 = V_163 | V_176 ;
V_49 -> V_30 = 3 ;
V_49 -> V_62 = 0xffff ;
F_45 ( V_11 ) ;
V_57 = F_12 ( V_11 ) ;
if ( V_57 < 0 )
return V_57 ;
V_17 -> V_77 = V_57 ;
if ( V_11 -> V_67 )
F_11 ( V_184 | V_185 , V_17 -> V_144 + V_145 ) ;
return 0 ;
}
static void F_58 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 ) {
if ( V_17 -> V_33 && V_17 -> V_144 )
F_44 ( V_11 ) ;
if ( V_11 -> V_67 ) {
F_11 ( F_16 ( V_17 -> V_144 + V_145 ) &
~ ( V_185 | V_186 | V_187 ) ,
V_17 -> V_144 + V_145 ) ;
F_59 ( V_11 -> V_67 , V_11 ) ;
}
if ( V_17 -> V_33 )
F_60 ( V_17 -> V_33 ) ;
if ( V_17 -> V_60 )
F_60 ( V_17 -> V_60 ) ;
if ( V_17 -> V_144 )
F_60 ( V_17 -> V_144 ) ;
}
F_61 ( V_11 ) ;
}
static int F_62 ( struct V_149 * V_11 ,
const struct V_188 * V_189 )
{
return F_63 ( V_11 , & V_190 , V_189 -> V_191 ) ;
}
