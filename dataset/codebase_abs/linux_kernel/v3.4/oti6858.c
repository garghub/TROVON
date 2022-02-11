static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_11 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
V_9 = F_4 ( V_14 , V_15 ) ;
if ( V_9 == NULL ) {
F_5 ( & V_7 -> V_16 , L_2 , V_12 ) ;
F_6 ( & V_4 -> V_5 ,
F_7 ( 2 ) ) ;
return;
}
V_11 = F_8 ( V_7 -> V_17 -> V_16 ,
F_9 ( V_7 -> V_17 -> V_16 , 0 ) ,
V_18 ,
V_19 ,
0 , 0 ,
V_9 , V_14 ,
100 ) ;
if ( V_11 != V_14 ) {
F_5 ( & V_7 -> V_16 , L_3 , V_12 ) ;
F_10 ( V_9 ) ;
F_6 ( & V_4 -> V_5 ,
F_7 ( 2 ) ) ;
return;
}
F_11 ( & V_4 -> V_20 , V_10 ) ;
if ( ! F_12 ( V_9 , V_4 ) ) {
V_9 -> V_21 = V_4 -> V_22 . V_21 ;
V_9 -> V_23 = V_4 -> V_22 . V_23 ;
V_9 -> V_24 = V_4 -> V_22 . V_24 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
V_11 = F_8 ( V_7 -> V_17 -> V_16 ,
F_14 ( V_7 -> V_17 -> V_16 , 0 ) ,
V_25 ,
V_26 ,
0 , 0 ,
V_9 , V_14 ,
100 ) ;
} else {
F_13 ( & V_4 -> V_20 , V_10 ) ;
V_11 = 0 ;
}
F_10 ( V_9 ) ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
if ( V_11 != V_14 )
V_4 -> V_27 = 0 ;
V_4 -> V_28 = 1 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
F_3 ( L_4 , V_12 ) ;
V_11 = F_15 ( V_7 -> V_29 , V_15 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_7 -> V_16 , L_5
L_6 , V_12 , V_11 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_30 . V_2 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_31 = 0 , V_11 ;
unsigned long V_10 ;
T_1 * V_32 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
if ( V_4 -> V_10 . V_33 ) {
F_13 ( & V_4 -> V_20 , V_10 ) ;
F_6 ( & V_4 -> V_30 ,
F_7 ( 2 ) ) ;
return;
}
V_4 -> V_10 . V_33 = 1 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
F_11 ( & V_7 -> V_20 , V_10 ) ;
V_31 = F_17 ( & V_7 -> V_34 ) ;
F_13 ( & V_7 -> V_20 , V_10 ) ;
if ( V_31 > V_7 -> V_35 )
V_31 = V_7 -> V_35 ;
if ( V_31 != 0 ) {
V_32 = F_4 ( 1 , V_15 ) ;
if ( ! V_32 ) {
F_18 ( V_7 , L_7 ,
V_12 ) ;
return;
}
V_11 = F_8 ( V_7 -> V_17 -> V_16 ,
F_9 ( V_7 -> V_17 -> V_16 , 0 ) ,
V_36 ,
V_37 ,
V_31 , 0 , V_32 , 1 , 100 ) ;
if ( V_11 != 1 || * V_32 != 0 )
V_31 = 0 ;
F_10 ( V_32 ) ;
}
if ( V_31 == 0 ) {
V_4 -> V_10 . V_33 = 0 ;
F_3 ( L_4 , V_12 ) ;
V_11 = F_15 ( V_7 -> V_29 , V_38 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_7 -> V_16 , L_5
L_6 , V_12 , V_11 ) ;
}
return;
}
V_31 = F_19 ( & V_7 -> V_34 ,
V_7 -> V_39 -> V_40 ,
V_31 , & V_7 -> V_20 ) ;
V_7 -> V_39 -> V_41 = V_31 ;
V_11 = F_15 ( V_7 -> V_39 , V_38 ) ;
if ( V_11 != 0 ) {
F_18 ( V_7 , L_5
L_6 , V_12 , V_11 ) ;
V_4 -> V_10 . V_33 = 0 ;
}
F_20 ( V_7 ) ;
}
static int F_21 ( struct V_42 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_7 [ 0 ] ;
struct V_3 * V_4 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_17 -> V_44 ; ++ V_43 ) {
V_4 = F_22 ( sizeof( struct V_3 ) , V_15 ) ;
if ( ! V_4 )
break;
F_23 ( & V_4 -> V_20 ) ;
F_24 ( & V_4 -> V_45 ) ;
V_4 -> V_7 = V_7 ;
F_25 ( & V_4 -> V_5 , F_1 ) ;
F_25 ( & V_4 -> V_30 , F_16 ) ;
F_26 ( V_17 -> V_7 [ V_43 ] , V_4 ) ;
}
if ( V_43 == V_17 -> V_44 )
return 0 ;
for ( -- V_43 ; V_43 >= 0 ; -- V_43 ) {
V_4 = F_27 ( V_17 -> V_7 [ V_43 ] ) ;
F_10 ( V_4 ) ;
F_26 ( V_17 -> V_7 [ V_43 ] , NULL ) ;
}
return - V_46 ;
}
static int F_28 ( struct V_47 * V_48 , struct V_6 * V_7 ,
const unsigned char * V_49 , int V_31 )
{
F_3 ( L_8 , V_12 , V_7 -> V_13 , V_31 ) ;
if ( ! V_31 )
return V_31 ;
V_31 = F_29 ( & V_7 -> V_34 , V_49 , V_31 , & V_7 -> V_20 ) ;
return V_31 ;
}
static int F_30 ( struct V_47 * V_48 )
{
struct V_6 * V_7 = V_48 -> V_50 ;
int V_51 = 0 ;
unsigned long V_10 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
F_11 ( & V_7 -> V_20 , V_10 ) ;
V_51 = F_31 ( & V_7 -> V_34 ) ;
F_13 ( & V_7 -> V_20 , V_10 ) ;
return V_51 ;
}
static int F_32 ( struct V_47 * V_48 )
{
struct V_6 * V_7 = V_48 -> V_50 ;
int V_52 = 0 ;
unsigned long V_10 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
F_11 ( & V_7 -> V_20 , V_10 ) ;
V_52 = F_17 ( & V_7 -> V_34 ) ;
F_13 ( & V_7 -> V_20 , V_10 ) ;
return V_52 ;
}
static void F_33 ( struct V_47 * V_48 )
{
* ( V_48 -> V_53 ) = V_54 ;
V_48 -> V_53 -> V_55 = V_56 | V_57 | V_58 | V_59 | V_60 ;
V_48 -> V_53 -> V_61 = 38400 ;
V_48 -> V_53 -> V_62 = 38400 ;
}
static void F_34 ( struct V_47 * V_48 ,
struct V_6 * V_7 , struct V_63 * V_64 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_65 ;
T_1 V_24 , V_23 ;
T_2 V_21 ;
int V_66 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
if ( ! V_48 ) {
F_3 ( L_9 , V_12 ) ;
return;
}
V_65 = V_48 -> V_53 -> V_55 ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
V_21 = V_4 -> V_22 . V_21 ;
V_24 = V_4 -> V_22 . V_24 ;
V_23 = V_4 -> V_22 . V_23 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
V_24 &= ~ V_67 ;
switch ( V_65 & V_68 ) {
case V_69 :
V_24 |= V_70 ;
break;
case V_71 :
V_24 |= V_72 ;
break;
case V_73 :
V_24 |= V_74 ;
break;
default:
case V_57 :
V_24 |= V_75 ;
break;
}
V_66 = F_35 ( V_48 ) ;
if ( V_66 == 0 ) {
V_21 = 0 ;
} else {
int V_76 ;
int V_77 ;
V_66 = F_36 ( V_66 , V_78 ) ;
V_77 = ( 96000000 + 8 * V_66 ) / ( 16 * V_66 ) ;
V_76 = 96000000 / ( 16 * V_77 ) ;
V_21 = F_37 ( V_77 ) ;
F_38 ( V_48 , V_76 , V_76 ) ;
}
V_24 &= ~ V_79 ;
if ( ( V_65 & V_80 ) != 0 )
V_24 |= V_81 ;
else
V_24 |= V_82 ;
V_24 &= ~ V_83 ;
if ( ( V_65 & V_84 ) != 0 ) {
if ( ( V_65 & V_85 ) != 0 )
V_24 |= V_86 ;
else
V_24 |= V_87 ;
} else {
V_24 |= V_88 ;
}
V_23 &= ~ V_89 ;
if ( ( V_65 & V_90 ) != 0 )
V_23 |= ( V_91 | V_92 ) ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
if ( V_21 != V_4 -> V_22 . V_21
|| V_23 != V_4 -> V_22 . V_23
|| V_24 != V_4 -> V_22 . V_24 ) {
V_4 -> V_22 . V_21 = V_21 ;
V_4 -> V_22 . V_23 = V_23 ;
V_4 -> V_22 . V_24 = V_24 ;
}
F_13 ( & V_4 -> V_20 , V_10 ) ;
}
static int F_39 ( struct V_47 * V_48 , struct V_6 * V_7 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
struct V_63 V_93 ;
struct V_42 * V_17 = V_7 -> V_17 ;
struct V_8 * V_49 ;
unsigned long V_10 ;
int V_11 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
F_40 ( V_17 -> V_16 , V_7 -> V_39 -> V_94 ) ;
F_40 ( V_17 -> V_16 , V_7 -> V_95 -> V_94 ) ;
V_49 = F_4 ( V_14 , V_15 ) ;
if ( V_49 == NULL ) {
F_5 ( & V_7 -> V_16 , L_2 , V_12 ) ;
return - V_46 ;
}
V_11 = F_8 ( V_17 -> V_16 , F_9 ( V_17 -> V_16 , 0 ) ,
V_18 ,
V_19 ,
0 , 0 ,
V_49 , V_14 ,
100 ) ;
if ( V_11 != V_14 ) {
V_49 -> V_21 = F_37 ( 0x009c ) ;
V_49 -> V_24 = 0x03 ;
V_49 -> V_96 = 0x43 ;
V_49 -> V_23 = 0x4c ;
V_49 -> V_97 = 0x00 ;
V_49 -> V_98 = 0x5b ;
V_49 -> V_99 = 0x00 ;
}
F_11 ( & V_4 -> V_20 , V_10 ) ;
memcpy ( & V_4 -> V_100 , V_49 , V_14 ) ;
V_4 -> V_22 . V_21 = V_49 -> V_21 ;
V_4 -> V_22 . V_24 = V_49 -> V_24 ;
V_4 -> V_22 . V_23 = V_49 -> V_23 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
F_10 ( V_49 ) ;
F_3 ( L_4 , V_12 ) ;
V_11 = F_15 ( V_7 -> V_29 , V_15 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_7 -> V_16 , L_5
L_6 , V_12 , V_11 ) ;
F_41 ( V_7 ) ;
return V_11 ;
}
if ( V_48 )
F_34 ( V_48 , V_7 , & V_93 ) ;
V_7 -> V_7 . V_101 = 256 ;
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
F_11 ( & V_7 -> V_20 , V_10 ) ;
F_42 ( & V_7 -> V_34 ) ;
F_13 ( & V_7 -> V_20 , V_10 ) ;
F_3 ( L_10 , V_12 ) ;
F_43 ( & V_4 -> V_5 ) ;
F_43 ( & V_4 -> V_30 ) ;
F_3 ( L_11 , V_12 ) ;
F_44 ( V_7 -> V_39 ) ;
F_44 ( V_7 -> V_95 ) ;
F_44 ( V_7 -> V_29 ) ;
}
static int F_45 ( struct V_47 * V_48 ,
unsigned int V_102 , unsigned int V_103 )
{
struct V_6 * V_7 = V_48 -> V_50 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
T_1 V_23 ;
F_3 ( L_12 ,
V_12 , V_7 -> V_13 , V_102 , V_103 ) ;
if ( ! F_46 ( V_7 -> V_17 -> V_104 ) )
return - V_105 ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
V_23 = V_4 -> V_22 . V_23 ;
if ( ( V_102 & V_106 ) != 0 )
V_23 |= V_92 ;
if ( ( V_102 & V_107 ) != 0 )
V_23 |= V_91 ;
if ( ( V_103 & V_106 ) != 0 )
V_23 &= ~ V_92 ;
if ( ( V_103 & V_107 ) != 0 )
V_23 &= ~ V_91 ;
if ( V_23 != V_4 -> V_22 . V_23 )
V_4 -> V_22 . V_23 = V_23 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
return 0 ;
}
static int F_47 ( struct V_47 * V_48 )
{
struct V_6 * V_7 = V_48 -> V_50 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned V_98 ;
unsigned V_11 = 0 ;
F_3 ( L_1 , V_12 , V_7 -> V_13 ) ;
if ( ! F_46 ( V_7 -> V_17 -> V_104 ) )
return - V_105 ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
V_98 = V_4 -> V_100 . V_98 & V_108 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
if ( ( V_98 & V_109 ) != 0 )
V_11 |= V_106 ;
if ( ( V_98 & V_110 ) != 0 )
V_11 |= V_111 ;
if ( ( V_98 & V_112 ) != 0 )
V_11 |= V_113 ;
if ( ( V_98 & V_114 ) != 0 )
V_11 |= V_107 ;
if ( ( V_98 & V_115 ) != 0 )
V_11 |= V_116 ;
if ( ( V_98 & V_117 ) != 0 )
V_11 |= V_118 ;
F_3 ( L_13 , V_12 , V_11 ) ;
return V_11 ;
}
static int F_48 ( struct V_6 * V_7 , unsigned int V_119 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_120 , V_100 ;
unsigned int V_121 ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
V_120 = V_4 -> V_100 . V_98 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
while ( 1 ) {
F_49 ( V_4 -> V_45 ,
V_4 -> V_100 . V_98 != V_120 ) ;
if ( F_50 ( V_122 ) )
return - V_123 ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
V_100 = V_4 -> V_100 . V_98 & V_108 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
V_121 = V_120 ^ V_100 ;
if ( ( ( V_119 & V_124 ) && ( V_121 & V_115 ) ) ||
( ( V_119 & V_113 ) && ( V_121 & V_112 ) ) ||
( ( V_119 & V_118 ) && ( V_121 & V_117 ) ) ||
( ( V_119 & V_111 ) && ( V_121 & V_110 ) ) )
return 0 ;
V_120 = V_100 ;
}
return 0 ;
}
static int F_51 ( struct V_47 * V_48 ,
unsigned int V_125 , unsigned long V_119 )
{
struct V_6 * V_7 = V_48 -> V_50 ;
F_3 ( L_14 ,
V_12 , V_7 -> V_13 , V_125 , V_119 ) ;
switch ( V_125 ) {
case V_126 :
F_3 ( L_15 , V_12 ) ;
return F_48 ( V_7 , V_119 ) ;
default:
F_3 ( L_16 , V_12 , V_125 ) ;
break;
}
return - V_127 ;
}
static void F_52 ( struct V_42 * V_17 )
{
int V_43 ;
F_3 ( L_17 , V_12 ) ;
for ( V_43 = 0 ; V_43 < V_17 -> V_44 ; ++ V_43 )
F_10 ( F_27 ( V_17 -> V_7 [ V_43 ] ) ) ;
}
static void F_53 ( struct V_128 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_129 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
int V_27 = 0 , V_130 = 0 , V_131 = 1 ;
int V_100 = V_128 -> V_100 ;
F_3 ( L_18 ,
V_12 , V_7 -> V_13 , V_100 ) ;
switch ( V_100 ) {
case 0 :
break;
case - V_132 :
case - V_133 :
case - V_134 :
F_3 ( L_19 ,
V_12 , V_100 ) ;
return;
default:
F_3 ( L_20 ,
V_12 , V_100 ) ;
break;
}
if ( V_100 == 0 && V_128 -> V_135 == V_14 ) {
struct V_8 * V_136 = V_128 -> V_40 ;
unsigned long V_10 ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
if ( ! V_4 -> V_27 ) {
if ( ! F_12 ( V_136 , V_4 ) ) {
if ( V_136 -> V_99 == 0 ) {
V_4 -> V_27 = 4 ;
V_4 -> V_28 = 0 ;
V_131 = 0 ;
F_3 ( L_21 ,
V_12 ) ;
F_6 ( & V_4 -> V_5 , 0 ) ;
}
}
} else {
if ( F_12 ( V_136 , V_4 ) ) {
V_4 -> V_27 = 0 ;
} else if ( ! V_4 -> V_28 ) {
V_131 = 0 ;
} else if ( -- V_4 -> V_27 == 0 ) {
if ( V_136 -> V_99 == 0 ) {
V_4 -> V_27 = 4 ;
V_4 -> V_28 = 0 ;
V_131 = 0 ;
F_3 ( L_21 ,
V_12 ) ;
F_6 ( & V_4 -> V_5 , 0 ) ;
}
}
}
if ( ! V_4 -> V_27 ) {
if ( V_136 -> V_98 != V_4 -> V_100 . V_98 )
F_54 ( & V_4 -> V_45 ) ;
memcpy ( & V_4 -> V_100 , V_136 , V_14 ) ;
}
if ( ! V_4 -> V_27 && V_136 -> V_99 != 0 ) {
V_130 = V_136 -> V_99 ;
V_4 -> V_10 . V_137 = 1 ;
}
V_27 = V_4 -> V_27 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
}
if ( V_130 ) {
int V_11 ;
V_11 = F_15 ( V_7 -> V_95 , V_138 ) ;
if ( V_11 != 0 ) {
V_4 -> V_10 . V_137 = 0 ;
F_5 ( & V_7 -> V_16 , L_22
L_23 , V_12 , V_11 ) ;
} else {
V_131 = 0 ;
}
} else if ( ! V_27 ) {
unsigned long V_10 ;
int V_31 ;
F_11 ( & V_7 -> V_20 , V_10 ) ;
V_31 = F_17 ( & V_7 -> V_34 ) ;
F_13 ( & V_7 -> V_20 , V_10 ) ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
if ( V_4 -> V_10 . V_33 == 0 && V_31 != 0 ) {
F_6 ( & V_4 -> V_30 , 0 ) ;
V_131 = 0 ;
}
F_13 ( & V_4 -> V_20 , V_10 ) ;
}
if ( V_131 ) {
int V_11 ;
V_11 = F_15 ( V_128 , V_138 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_128 -> V_16 -> V_16 ,
L_24
L_23 , V_12 , V_11 ) ;
}
}
}
static void F_55 ( struct V_128 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_129 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
struct V_47 * V_48 ;
unsigned char * V_139 = V_128 -> V_40 ;
unsigned long V_10 ;
int V_100 = V_128 -> V_100 ;
int V_11 ;
F_3 ( L_18 ,
V_12 , V_7 -> V_13 , V_100 ) ;
F_11 ( & V_4 -> V_20 , V_10 ) ;
V_4 -> V_10 . V_137 = 0 ;
F_13 ( & V_4 -> V_20 , V_10 ) ;
if ( V_100 != 0 ) {
F_3 ( L_25 , V_12 ) ;
return;
}
V_48 = F_56 ( & V_7 -> V_7 ) ;
if ( V_48 != NULL && V_128 -> V_135 > 0 ) {
F_57 ( V_48 , V_139 , V_128 -> V_135 ) ;
F_58 ( V_48 ) ;
}
F_59 ( V_48 ) ;
V_11 = F_15 ( V_7 -> V_29 , V_138 ) ;
if ( V_11 != 0 && V_11 != - V_140 ) {
F_5 ( & V_7 -> V_16 , L_22
L_23 , V_12 , V_11 ) ;
}
}
static void F_60 ( struct V_128 * V_128 )
{
struct V_6 * V_7 = V_128 -> V_129 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
int V_100 = V_128 -> V_100 ;
int V_11 ;
F_3 ( L_18 ,
V_12 , V_7 -> V_13 , V_100 ) ;
switch ( V_100 ) {
case 0 :
break;
case - V_132 :
case - V_133 :
case - V_134 :
F_3 ( L_19 ,
V_12 , V_100 ) ;
V_4 -> V_10 . V_33 = 0 ;
return;
default:
F_3 ( L_26 ,
V_12 , V_100 ) ;
F_3 ( L_27 , V_12 ) ;
V_7 -> V_39 -> V_41 = 1 ;
V_11 = F_15 ( V_7 -> V_39 , V_138 ) ;
if ( V_11 ) {
F_18 ( V_7 , L_22
L_23 , V_12 , V_11 ) ;
} else {
return;
}
}
V_4 -> V_10 . V_33 = 0 ;
F_3 ( L_4 , V_12 ) ;
V_11 = F_15 ( V_7 -> V_29 , V_138 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_7 -> V_16 , L_28
L_23 , V_12 , V_11 ) ;
}
}
