static int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 * V_4 , int V_5 )
{
T_2 V_6 ;
int V_7 ;
int (* F_2)( struct V_1 * , T_3 , T_3 , T_4 , T_4 , void * , T_4 );
F_3 ( ! V_2 ) ;
if ( ! V_5 )
F_2 = V_8 ;
else
F_2 = V_9 ;
V_7 = F_2 ( V_2 , V_10 , V_11
| V_12 | V_13 ,
0 , V_3 , & V_6 , 4 ) ;
if ( F_4 ( V_7 < 0 ) ) {
F_5 ( V_2 -> V_14 , L_1 ,
V_3 , V_7 ) ;
return V_7 ;
}
F_6 ( & V_6 ) ;
* V_4 = V_6 ;
return V_7 ;
}
static int T_1 F_7 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 , int V_5 )
{
T_2 V_6 ;
int V_7 ;
int (* F_2)( struct V_1 * , T_3 , T_3 , T_4 , T_4 , const void * , T_4 );
F_3 ( ! V_2 ) ;
if ( ! V_5 )
F_2 = V_15 ;
else
F_2 = V_16 ;
V_6 = V_4 ;
F_8 ( & V_6 ) ;
V_7 = F_2 ( V_2 , V_17 , V_18
| V_12 | V_13 ,
0 , V_3 , & V_6 , 4 ) ;
if ( F_4 ( V_7 < 0 ) )
F_5 ( V_2 -> V_14 , L_2 ,
V_3 , V_7 ) ;
return V_7 ;
}
static int T_1 F_9 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 * V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int T_1 F_10 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 )
{
return F_7 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int T_1 F_11 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 * V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int T_1 F_12 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 )
{
return F_7 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int T_1 F_13 ( struct V_1 * V_2 ,
int V_5 )
{
unsigned long V_19 = V_20 ;
T_2 V_21 ;
int V_7 ;
do {
V_7 = F_1 ( V_2 , V_22 , & V_21 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_3 ) ;
return V_7 ;
}
if ( ! ( V_21 & V_23 ) )
return 0 ;
} while ( ! F_14 ( V_20 , V_19 + V_24 ) );
return - V_25 ;
}
static int F_15 ( struct V_26 * V_27 , int V_28 , int V_29 ,
int V_5 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
T_2 V_21 , V_30 ;
int V_7 ;
F_17 ( & V_2 -> V_31 ) ;
V_7 = F_13 ( V_2 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_4 ) ;
goto V_32;
}
V_28 &= V_2 -> V_33 . V_34 ;
V_29 &= V_2 -> V_33 . V_35 ;
V_30 = ( V_28 << 11 ) | ( V_29 << 6 ) | V_36 | V_23 ;
V_7 = F_7 ( V_2 , V_22 , V_30 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_5 ) ;
goto V_32;
}
V_7 = F_13 ( V_2 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_6 , V_29 ) ;
goto V_32;
}
V_7 = F_1 ( V_2 , V_37 , & V_21 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_7 ) ;
goto V_32;
}
V_7 = ( T_4 ) ( V_21 & 0xFFFF ) ;
V_32:
F_18 ( & V_2 -> V_31 ) ;
return V_7 ;
}
static void F_19 ( struct V_26 * V_27 , int V_28 ,
int V_29 , int V_38 , int V_5 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
T_2 V_21 , V_30 ;
int V_7 ;
F_17 ( & V_2 -> V_31 ) ;
V_7 = F_13 ( V_2 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_8 ) ;
goto V_32;
}
V_21 = V_38 ;
V_7 = F_7 ( V_2 , V_37 , V_21 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_9 ) ;
goto V_32;
}
V_28 &= V_2 -> V_33 . V_34 ;
V_29 &= V_2 -> V_33 . V_35 ;
V_30 = ( V_28 << 11 ) | ( V_29 << 6 ) | V_39 | V_23 ;
V_7 = F_7 ( V_2 , V_22 , V_30 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_5 ) ;
goto V_32;
}
V_7 = F_13 ( V_2 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_10 , V_29 ) ;
goto V_32;
}
V_32:
F_18 ( & V_2 -> V_31 ) ;
}
static int F_20 ( struct V_26 * V_27 , int V_28 ,
int V_29 )
{
return F_15 ( V_27 , V_28 , V_29 , 1 ) ;
}
static void F_21 ( struct V_26 * V_27 , int V_28 ,
int V_29 , int V_38 )
{
F_19 ( V_27 , V_28 , V_29 , V_38 , 1 ) ;
}
static int F_22 ( struct V_26 * V_27 , int V_28 , int V_29 )
{
return F_15 ( V_27 , V_28 , V_29 , 0 ) ;
}
static void F_23 ( struct V_26 * V_27 , int V_28 , int V_29 ,
int V_38 )
{
F_19 ( V_27 , V_28 , V_29 , V_38 , 0 ) ;
}
static int T_1 F_24 ( struct V_1 * V_2 )
{
unsigned long V_19 = V_20 ;
T_2 V_21 ;
int V_7 ;
do {
V_7 = F_11 ( V_2 , V_40 , & V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_11 ) ;
return V_7 ;
}
if ( ! ( V_21 & V_41 ) || ( V_21 & V_42 ) )
break;
F_25 ( 40 ) ;
} while ( ! F_14 ( V_20 , V_19 + V_24 ) );
if ( V_21 & ( V_42 | V_41 ) ) {
F_5 ( V_2 -> V_14 , L_12 ) ;
return - V_25 ;
}
return 0 ;
}
static int T_1 F_26 ( struct V_1 * V_2 )
{
unsigned long V_19 = V_20 ;
T_2 V_21 ;
int V_7 ;
do {
V_7 = F_11 ( V_2 , V_40 , & V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_11 ) ;
return V_7 ;
}
if ( ! ( V_21 & V_41 ) )
return 0 ;
F_25 ( 40 ) ;
} while ( ! F_14 ( V_20 , V_19 + V_24 ) );
F_5 ( V_2 -> V_14 , L_13 ) ;
return - V_25 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_44 ,
T_3 * V_4 )
{
T_2 V_21 ;
int V_45 , V_7 ;
F_3 ( ! V_2 ) ;
F_3 ( ! V_4 ) ;
V_7 = F_26 ( V_2 ) ;
if ( V_7 )
return V_7 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
V_21 = V_41 | V_46 | ( V_43 & V_47 ) ;
V_7 = F_12 ( V_2 , V_40 , V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_14 ) ;
return V_7 ;
}
V_7 = F_24 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_48 , & V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_15 ) ;
return V_7 ;
}
V_4 [ V_45 ] = V_21 & 0xFF ;
V_43 ++ ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_44 ,
T_3 * V_4 )
{
T_2 V_21 ;
int V_45 , V_7 ;
F_3 ( ! V_2 ) ;
F_3 ( ! V_4 ) ;
V_7 = F_26 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_21 = V_41 | V_49 ;
V_7 = F_12 ( V_2 , V_40 , V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_16 ) ;
return V_7 ;
}
V_7 = F_24 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
V_21 = V_4 [ V_45 ] ;
V_7 = F_12 ( V_2 , V_48 , V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_16 ) ;
return V_7 ;
}
V_21 = V_41 | V_50 | ( V_43 & V_47 ) ;
V_7 = F_12 ( V_2 , V_40 , V_21 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_14 ) ;
return V_7 ;
}
V_7 = F_24 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_43 ++ ;
}
return 0 ;
}
static int T_1 F_29 ( struct V_1 * V_2 , T_4 V_3 ,
T_2 V_4 )
{
const T_4 V_51 = 4 ;
T_2 V_6 ;
int V_7 ;
V_6 = V_4 ;
F_8 ( & V_6 ) ;
V_7 = F_30 ( V_2 , V_17 ,
V_18 | V_12 |
V_13 ,
0 , V_3 , & V_6 , V_51 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_17 ,
V_7 ) ;
return V_7 ;
}
static unsigned int F_31 ( char V_30 [ V_52 ] )
{
return ( F_32 ( V_52 , V_30 ) >> 26 ) & 0x3f ;
}
static void F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
int V_7 ;
V_54 -> V_56 = 0 ;
V_54 -> V_57 = 0 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
if ( V_2 -> V_14 -> V_55 & V_59 ) {
F_35 ( V_2 , V_60 , V_2 -> V_14 , L_18 ) ;
V_54 -> V_61 |= V_62 ;
V_54 -> V_61 &= ~ ( V_63 | V_64 ) ;
} else if ( V_2 -> V_14 -> V_55 & V_65 ) {
F_35 ( V_2 , V_60 , V_2 -> V_14 , L_19 ) ;
V_54 -> V_61 |= V_63 ;
V_54 -> V_61 &= ~ ( V_62 | V_64 ) ;
} else if ( ! F_36 ( V_2 -> V_14 ) ) {
struct V_66 * V_67 ;
V_54 -> V_61 |= V_64 ;
V_54 -> V_61 &= ~ ( V_62 | V_63 ) ;
F_37 (ha, netdev) {
T_2 V_68 = F_31 ( V_67 -> V_30 ) ;
T_2 V_69 = 0x01 << ( V_68 & 0x1F ) ;
if ( V_68 & 0x20 )
V_54 -> V_56 |= V_69 ;
else
V_54 -> V_57 |= V_69 ;
}
F_35 ( V_2 , V_60 , V_2 -> V_14 , L_20 ,
V_54 -> V_56 , V_54 -> V_57 ) ;
} else {
F_35 ( V_2 , V_60 , V_2 -> V_14 , L_21 ) ;
V_54 -> V_61 &=
~ ( V_62 | V_63 | V_64 ) ;
}
F_38 ( & V_54 -> V_58 , V_55 ) ;
V_7 = F_29 ( V_2 , V_70 , V_54 -> V_56 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_22 ) ;
V_7 = F_29 ( V_2 , V_71 , V_54 -> V_57 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_23 ) ;
V_7 = F_29 ( V_2 , V_72 , V_54 -> V_61 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_24 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_73 ,
T_4 V_74 , T_4 V_75 )
{
T_2 V_76 , V_77 = 0 ;
int V_7 = F_11 ( V_2 , V_78 , & V_77 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_73 == V_79 ) {
T_3 V_80 = F_40 ( V_74 , V_75 ) ;
if ( V_80 & V_81 )
V_76 = 0xFFFF0002 ;
else
V_76 = 0 ;
if ( V_80 & V_82 )
V_77 |= 0xF ;
else
V_77 &= ~ 0xF ;
F_35 ( V_2 , V_83 , V_2 -> V_14 , L_25 ,
V_80 & V_81 ? L_26 : L_27 ,
V_80 & V_82 ? L_26 : L_27 ) ;
} else {
F_35 ( V_2 , V_83 , V_2 -> V_14 , L_28 ) ;
V_76 = 0 ;
V_77 |= 0xF ;
}
V_7 = F_12 ( V_2 , V_84 , V_76 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_78 , V_77 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
struct V_85 * V_33 = & V_2 -> V_33 ;
struct V_86 V_87 = { . V_88 = V_89 } ;
unsigned long V_55 ;
T_4 V_74 , V_75 ;
int V_7 ;
V_7 = F_22 ( V_2 -> V_14 , V_33 -> V_28 , V_90 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_91 , V_92 ) ;
if ( V_7 < 0 )
return V_7 ;
F_42 ( V_33 , 1 , 1 ) ;
F_43 ( & V_2 -> V_33 , & V_87 ) ;
V_74 = F_22 ( V_2 -> V_14 , V_33 -> V_28 , V_93 ) ;
V_75 = F_22 ( V_2 -> V_14 , V_33 -> V_28 , V_94 ) ;
F_35 ( V_2 , V_83 , V_2 -> V_14 ,
L_29 ,
F_44 ( & V_87 ) , V_87 . V_73 , V_74 , V_75 ) ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
if ( V_87 . V_73 != V_79 ) {
V_54 -> V_61 &= ~ V_95 ;
V_54 -> V_61 |= V_96 ;
} else {
V_54 -> V_61 &= ~ V_96 ;
V_54 -> V_61 |= V_95 ;
}
F_38 ( & V_54 -> V_58 , V_55 ) ;
V_7 = F_12 ( V_2 , V_72 , V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_39 ( V_2 , V_87 . V_73 , V_74 , V_75 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_30 ) ;
return V_7 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_97 * V_97 )
{
T_2 V_98 ;
if ( V_97 -> V_99 != 4 ) {
F_5 ( V_2 -> V_14 , L_31 ,
V_97 -> V_99 ) ;
return;
}
memcpy ( & V_98 , V_97 -> V_100 , 4 ) ;
F_6 ( & V_98 ) ;
F_35 ( V_2 , V_83 , V_2 -> V_14 , L_32 , V_98 ) ;
if ( V_98 & V_101 )
F_46 ( V_2 , V_102 ) ;
else
F_5 ( V_2 -> V_14 , L_33 ,
V_98 ) ;
}
static void F_47 ( struct V_1 * V_2 , bool V_83 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( V_54 -> V_103 == V_83 )
return;
V_54 -> V_103 = V_83 ;
if ( V_83 )
F_48 ( V_2 , 1 , 0 ) ;
else
F_48 ( V_2 , 0 , 0 ) ;
}
static void F_49 ( struct V_104 * V_105 )
{
struct V_53 * V_54 = F_50 ( V_105 , struct V_53 ,
V_106 . V_105 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
int V_7 ;
if ( V_54 -> V_107 != 0 )
return;
V_7 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_108 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_34 ) ;
return;
}
if ( V_7 & V_109 )
F_47 ( V_2 , 1 ) ;
else
F_47 ( V_2 , 0 ) ;
F_51 ( & V_54 -> V_106 , V_110 ) ;
}
static int F_52 ( struct V_26 * V_27 ,
T_5 V_111 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
T_2 V_112 ;
int V_7 ;
V_7 = F_11 ( V_2 , V_113 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_111 & V_114 )
V_112 |= V_115 ;
else
V_112 &= ~ V_115 ;
if ( V_111 & V_116 )
V_112 |= V_117 ;
else
V_112 &= ~ V_117 ;
V_7 = F_12 ( V_2 , V_113 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_118 , V_2 -> V_14 , L_35 , V_112 ) ;
return 0 ;
}
static int F_53 ( struct V_26 * V_14 )
{
return V_119 ;
}
static int F_54 ( struct V_26 * V_27 ,
struct V_120 * V_121 , T_3 * V_4 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
V_121 -> V_122 = V_123 ;
return F_27 ( V_2 , V_121 -> V_43 , V_121 -> V_124 , V_4 ) ;
}
static int F_55 ( struct V_26 * V_27 ,
struct V_120 * V_121 , T_3 * V_4 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
if ( V_121 -> V_122 != V_123 ) {
F_5 ( V_2 -> V_14 , L_36 ,
V_121 -> V_122 ) ;
return - V_125 ;
}
return F_28 ( V_2 , V_121 -> V_43 , V_121 -> V_124 , V_4 ) ;
}
static int F_56 ( struct V_26 * V_27 )
{
return V_113 - V_126 + sizeof( T_2 ) ;
}
static void
F_57 ( struct V_26 * V_27 , struct V_127 * V_128 ,
void * V_6 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
unsigned int V_45 , V_129 ;
int V_130 ;
T_2 * V_4 = V_6 ;
V_130 = F_11 ( V_2 , V_126 , & V_128 -> V_131 ) ;
if ( V_130 < 0 ) {
F_5 ( V_27 , L_37 ) ;
return;
}
for ( V_45 = V_126 , V_129 = 0 ; V_45 <= V_113 ; V_45 += ( sizeof( T_2 ) ) , V_129 ++ ) {
V_130 = F_11 ( V_2 , V_45 , & V_4 [ V_129 ] ) ;
if ( V_130 < 0 ) {
F_5 ( V_27 , L_38 , V_45 ) ;
return;
}
}
}
static void F_58 ( struct V_26 * V_14 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_133 -> V_134 = V_135 ;
V_133 -> V_136 = V_54 -> V_136 ;
}
static int F_59 ( struct V_26 * V_14 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
V_54 -> V_136 = V_133 -> V_136 & V_135 ;
V_7 = F_60 ( & V_2 -> V_137 -> V_2 , V_54 -> V_136 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_39 , V_7 ) ;
return V_7 ;
}
static int F_61 ( struct V_26 * V_14 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
T_2 V_21 ;
int V_6 ;
V_6 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_138 ) ;
if ( V_6 & V_139 ) {
if ( V_6 & V_140 )
return V_141 ;
else if ( V_6 & V_142 )
return V_143 ;
} else {
V_6 = F_11 ( V_2 , V_144 , & V_21 ) ;
if ( V_21 & V_145 )
return V_141 ;
}
return V_146 ;
}
static void F_62 ( struct V_26 * V_14 , T_6 V_147 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_6 ;
if ( ( V_54 -> V_148 == V_149 ) ||
( V_54 -> V_148 == V_150 ) ||
( V_54 -> V_148 == V_151 ) ||
( V_54 -> V_148 == V_152 ) ) {
V_6 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_153 ) ;
V_6 |= V_154 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_153 , V_6 ) ;
}
if ( V_147 == V_146 ) {
V_6 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_138 ) ;
V_6 |= V_139 ;
V_6 &= ~ ( V_140 |
V_142 ) ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_138 , V_6 ) ;
} else if ( V_147 == V_143 ) {
V_6 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_138 ) ;
V_6 |= V_139 ;
V_6 &= ~ ( V_140 |
V_142 ) ;
V_6 |= V_142 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_138 , V_6 ) ;
} else if ( V_147 == V_141 ) {
V_6 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_138 ) ;
V_6 &= ~ V_139 ;
V_6 &= ~ ( V_140 |
V_142 ) ;
V_6 |= V_140 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 ,
V_138 , V_6 ) ;
}
V_54 -> V_147 = V_147 ;
}
static int F_63 ( struct V_26 * V_14 ,
struct V_155 * V_88 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_130 ;
V_130 = F_64 ( V_14 , V_88 ) ;
V_88 -> V_156 . V_157 = V_54 -> V_147 ;
V_88 -> V_156 . V_158 = V_54 -> V_147 ;
return V_130 ;
}
static int F_65 ( struct V_26 * V_14 ,
const struct V_155 * V_88 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_130 ;
if ( V_54 -> V_147 != V_88 -> V_156 . V_158 )
F_62 ( V_14 , V_88 -> V_156 . V_158 ) ;
V_130 = F_66 ( V_14 , V_88 ) ;
return V_130 ;
}
static int F_67 ( struct V_26 * V_27 , struct V_159 * V_160 , int V_88 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
if ( ! F_68 ( V_27 ) )
return - V_125 ;
return F_69 ( & V_2 -> V_33 , F_70 ( V_160 ) , V_88 , NULL ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
const T_3 * V_161 ;
V_161 = F_72 ( V_2 -> V_137 -> V_2 . V_162 ) ;
if ( V_161 ) {
memcpy ( V_2 -> V_14 -> V_163 , V_161 , V_52 ) ;
return;
}
if ( F_27 ( V_2 , V_164 , V_52 ,
V_2 -> V_14 -> V_163 ) == 0 ) {
if ( F_73 ( V_2 -> V_14 -> V_163 ) ) {
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_40 ) ;
return;
}
}
F_74 ( V_2 -> V_14 ) ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_41 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_2 V_166 = V_2 -> V_14 -> V_163 [ 0 ] | V_2 -> V_14 -> V_163 [ 1 ] << 8 |
V_2 -> V_14 -> V_163 [ 2 ] << 16 | V_2 -> V_14 -> V_163 [ 3 ] << 24 ;
T_2 V_167 = V_2 -> V_14 -> V_163 [ 4 ] | V_2 -> V_14 -> V_163 [ 5 ] << 8 ;
int V_7 ;
V_7 = F_12 ( V_2 , V_168 , V_166 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_169 , V_167 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
int V_7 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_170 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
V_7 = F_12 ( V_2 , V_72 , V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_171 , V_172 ) ;
}
static int F_77 ( struct V_1 * V_2 , int V_5 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_173 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
return F_7 ( V_2 , V_72 , V_54 -> V_61 , V_5 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_174 , V_7 , V_175 = 0 ;
V_2 -> V_33 . V_2 = V_2 -> V_14 ;
V_2 -> V_33 . V_176 = F_22 ;
V_2 -> V_33 . V_177 = F_23 ;
V_2 -> V_33 . V_34 = 0x1f ;
V_2 -> V_33 . V_35 = 0x1f ;
V_2 -> V_33 . V_28 = V_178 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_179 , V_180 ) ;
do {
F_79 ( 10 ) ;
V_174 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_179 ) ;
V_175 ++ ;
} while ( ( V_174 & V_180 ) && ( V_175 < 100 ) );
if ( V_175 >= 100 ) {
F_5 ( V_2 -> V_14 , L_42 ) ;
return - V_25 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_93 ,
V_181 | V_182 | V_183 |
V_184 ) ;
V_7 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_90 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_43 ) ;
return V_7 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_185 ,
V_186 ) ;
F_80 ( & V_2 -> V_33 ) ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_44 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_112 , V_187 , V_188 ;
int V_7 = 0 , V_175 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_45 ) ;
V_7 = F_12 ( V_2 , V_189 , V_190 ) ;
if ( V_7 < 0 )
return V_7 ;
V_175 = 0 ;
do {
F_79 ( 10 ) ;
V_7 = F_11 ( V_2 , V_189 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_175 ++ ;
} while ( ( V_112 & V_190 ) && ( V_175 < 100 ) );
if ( V_175 >= 100 ) {
F_5 ( V_2 -> V_14 , L_46 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 , V_191 , V_192 ) ;
if ( V_7 < 0 )
return V_7 ;
V_175 = 0 ;
do {
F_79 ( 10 ) ;
V_7 = F_11 ( V_2 , V_191 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_175 ++ ;
} while ( ( V_112 & V_192 ) && ( V_175 < 100 ) );
if ( V_175 >= 100 ) {
F_5 ( V_2 -> V_14 , L_47 ) ;
return V_7 ;
}
V_7 = F_75 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_48 ,
V_2 -> V_14 -> V_163 ) ;
V_7 = F_11 ( V_2 , V_189 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_49 ,
V_112 ) ;
V_112 |= V_193 ;
V_7 = F_12 ( V_2 , V_189 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_189 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 ,
L_50 ,
V_112 ) ;
if ( ! V_194 ) {
V_188 = 0 ;
V_2 -> V_195 = V_196 ;
} else if ( V_2 -> V_137 -> V_197 == V_198 ) {
V_188 = V_199 / V_200 ;
V_2 -> V_195 = V_199 ;
} else {
V_188 = V_201 / V_202 ;
V_2 -> V_195 = V_201 ;
}
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_51 ,
( V_203 ) V_2 -> V_195 ) ;
V_7 = F_12 ( V_2 , V_204 , V_188 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_204 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 ,
L_52 ,
V_112 ) ;
V_7 = F_12 ( V_2 , V_205 , V_206 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_205 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 ,
L_53 ,
V_112 ) ;
V_7 = F_11 ( V_2 , V_189 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_54 ,
V_112 ) ;
if ( V_194 )
V_112 |= ( V_207 | V_208 ) ;
V_112 &= ~ V_209 ;
V_112 |= V_210 << 9 ;
V_7 = F_12 ( V_2 , V_189 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_189 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 ,
L_55 , V_112 ) ;
V_7 = F_12 ( V_2 , V_91 , V_92 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_126 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_56 , V_112 ) ;
V_187 = V_211 | V_212 |
V_213 ;
V_7 = F_12 ( V_2 , V_214 , V_187 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_84 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_78 , V_215 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_72 , & V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_216 , ( T_2 ) V_217 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_52 ( V_2 -> V_14 , V_2 -> V_14 -> V_111 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_57 ) ;
return V_7 ;
}
F_33 ( V_2 -> V_14 ) ;
V_7 = F_78 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_58 ) ;
return V_7 ;
}
V_7 = F_11 ( V_2 , V_218 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_112 |= V_219 ;
V_7 = F_12 ( V_2 , V_218 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_76 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_59 ) ;
return V_7 ;
}
V_7 = F_77 ( V_2 , 0 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_60 ) ;
return V_7 ;
}
F_35 ( V_2 , V_165 , V_2 -> V_14 , L_61 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_220 * V_221 )
{
struct V_53 * V_54 = NULL ;
T_2 V_21 ;
int V_7 ;
F_83 (KERN_INFO SMSC_CHIPNAME L_62 SMSC_DRIVER_VERSION L_63 ) ;
V_7 = F_84 ( V_2 , V_221 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_64 , V_7 ) ;
return V_7 ;
}
V_2 -> V_4 [ 0 ] = ( unsigned long ) F_85 ( sizeof( struct V_53 ) ,
V_222 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( ! V_54 )
return - V_223 ;
F_86 ( & V_54 -> V_58 ) ;
if ( V_224 )
V_2 -> V_14 -> V_111 |= V_114 ;
if ( V_225 )
V_2 -> V_14 -> V_111 |= V_116 ;
V_2 -> V_14 -> V_226 = V_114 | V_116 ;
F_71 ( V_2 ) ;
V_7 = F_81 ( V_2 ) ;
V_7 = F_11 ( V_2 , V_126 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 >>= 16 ;
V_54 -> V_148 = V_21 ;
V_54 -> V_147 = F_61 ( V_2 -> V_14 ) ;
if ( ( V_21 == V_149 ) || ( V_21 == V_150 ) ||
( V_21 == V_151 ) || ( V_21 == V_152 ) )
V_54 -> V_111 = ( V_227 |
V_228 |
V_229 ) ;
else if ( V_21 == V_230 )
V_54 -> V_111 = V_227 ;
V_2 -> V_14 -> V_231 = & V_232 ;
V_2 -> V_14 -> V_233 = & V_234 ;
V_2 -> V_14 -> V_55 |= V_235 ;
V_2 -> V_14 -> V_236 += V_237 ;
V_2 -> V_238 = V_2 -> V_14 -> V_239 + V_2 -> V_14 -> V_236 ;
V_54 -> V_2 = V_2 ;
F_87 ( & V_54 -> V_106 , F_49 ) ;
F_51 ( & V_54 -> V_106 , V_110 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , struct V_220 * V_221 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( V_54 ) {
F_89 ( & V_54 -> V_106 ) ;
F_35 ( V_2 , V_240 , V_2 -> V_14 , L_65 ) ;
F_90 ( V_54 ) ;
V_54 = NULL ;
V_2 -> V_4 [ 0 ] = 0 ;
}
}
static T_2 F_91 ( const T_3 * V_241 , T_7 V_124 , int V_242 )
{
T_2 V_243 = F_92 ( F_93 ( 0xFFFF , V_241 , V_124 ) ) ;
return V_243 << ( ( V_242 % 2 ) * 16 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_4 V_69 )
{
struct V_85 * V_33 = & V_2 -> V_33 ;
int V_7 ;
F_95 ( V_2 -> V_14 , L_66 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_90 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_185 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_69 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_185 , V_7 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_85 * V_33 = & V_2 -> V_33 ;
int V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_108 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_108 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ! ( V_7 & V_109 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ( ~ ( V_244 | V_245 | V_192 ) ) ;
V_21 |= V_246 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_245 ;
V_21 |= V_247 ;
if ( V_54 -> V_136 & V_248 )
V_21 |= V_249 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_250 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
struct V_85 * V_33 = & V_2 -> V_33 ;
T_2 V_21 ;
int V_7 ;
if ( V_54 -> V_111 & V_228 )
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_153 ,
V_251 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_252 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_253 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_252 , V_7 ) ;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_244 | V_245 | V_192 ) ;
V_21 |= V_254 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_245 ;
V_21 |= ( V_249 | V_255 ) ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_256 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_244 | V_245 | V_192 ) ;
V_21 |= V_257 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_258 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_259 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_21 & V_260 ) {
F_101 ( V_2 -> V_14 , L_67 ) ;
return - V_261 ;
}
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_244 | V_245 | V_192 ) ;
V_21 |= V_262 | V_263 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_245 ;
V_21 |= V_247 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_264 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , T_2 V_265 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
if ( ! F_68 ( V_2 -> V_14 ) ) {
F_95 ( V_2 -> V_14 , L_68 ) ;
return F_99 ( V_2 ) ;
}
if ( ! V_265 ) {
if ( ! ( V_54 -> V_111 & V_228 ) ) {
F_5 ( V_2 -> V_14 , L_69 ) ;
return - V_261 ;
}
F_95 ( V_2 -> V_14 , L_70 ) ;
V_7 = F_94 ( V_2 ,
V_266 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
return V_7 ;
}
F_101 ( V_2 -> V_14 , L_72 ) ;
return F_98 ( V_2 ) ;
}
V_7 = F_94 ( V_2 ,
V_267 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
return V_7 ;
}
F_95 ( V_2 -> V_14 , L_73 ) ;
return F_100 ( V_2 ) ;
}
static int F_103 ( struct V_220 * V_221 , T_8 V_268 )
{
struct V_1 * V_2 = F_104 ( V_221 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 , V_265 ;
int V_7 ;
V_7 = F_105 ( V_221 , V_268 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_74 ) ;
return V_7 ;
}
if ( V_54 -> V_107 ) {
F_5 ( V_2 -> V_14 , L_75 ) ;
V_54 -> V_107 = 0 ;
}
V_265 = F_96 ( V_2 ) ;
if ( V_268 . V_269 == V_270 &&
( V_54 -> V_111 & V_229 ) ) {
V_7 = F_102 ( V_2 , V_265 ) ;
goto V_32;
}
if ( ! ( V_54 -> V_136 & V_135 ) ||
! ( V_265 || ( V_54 -> V_136 & V_248 ) ) ) {
F_101 ( V_2 -> V_14 , L_76 ) ;
V_7 = F_9 ( V_2 , V_271 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_272 | V_273 ) ;
V_7 = F_10 ( V_2 , V_271 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_255 | V_274 ) ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_99 ( V_2 ) ;
goto V_32;
}
if ( V_54 -> V_136 & V_248 ) {
V_7 = F_94 ( V_2 ,
( V_266 | V_267 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
goto V_32;
}
if ( ! V_265 ) {
F_101 ( V_2 -> V_14 , L_72 ) ;
V_7 = F_98 ( V_2 ) ;
goto V_32;
}
}
if ( V_54 -> V_136 & ( V_275 | V_276 | V_277 | V_278 ) ) {
T_2 * V_279 = F_85 ( sizeof( T_2 ) * 32 , V_222 ) ;
T_2 V_280 [ 2 ] ;
T_2 V_43 [ 2 ] ;
T_2 V_243 [ 4 ] ;
int V_281 =
( V_54 -> V_111 & V_227 ) ?
V_282 : V_283 ;
int V_45 , V_242 = 0 ;
if ( ! V_279 ) {
F_5 ( V_2 -> V_14 , L_77 ) ;
V_7 = - V_223 ;
goto V_32;
}
memset ( V_280 , 0 , sizeof( V_280 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_243 , 0 , sizeof( V_243 ) ) ;
if ( V_54 -> V_136 & V_275 ) {
const T_3 V_284 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
F_101 ( V_2 -> V_14 , L_78 ) ;
V_279 [ V_242 * 4 ] = 0x003F ;
V_279 [ V_242 * 4 + 1 ] = 0x00 ;
V_279 [ V_242 * 4 + 2 ] = 0x00 ;
V_279 [ V_242 * 4 + 3 ] = 0x00 ;
V_280 [ V_242 / 4 ] |= 0x05UL << ( ( V_242 % 4 ) * 8 ) ;
V_43 [ V_242 / 4 ] |= 0x00 << ( ( V_242 % 4 ) * 8 ) ;
V_243 [ V_242 / 2 ] |= F_91 ( V_284 , 6 , V_242 ) ;
V_242 ++ ;
}
if ( V_54 -> V_136 & V_276 ) {
const T_3 V_285 [] = { 0x01 , 0x00 , 0x5E } ;
F_101 ( V_2 -> V_14 , L_79 ) ;
V_279 [ V_242 * 4 ] = 0x0007 ;
V_279 [ V_242 * 4 + 1 ] = 0x00 ;
V_279 [ V_242 * 4 + 2 ] = 0x00 ;
V_279 [ V_242 * 4 + 3 ] = 0x00 ;
V_280 [ V_242 / 4 ] |= 0x09UL << ( ( V_242 % 4 ) * 8 ) ;
V_43 [ V_242 / 4 ] |= 0x00 << ( ( V_242 % 4 ) * 8 ) ;
V_243 [ V_242 / 2 ] |= F_91 ( V_285 , 3 , V_242 ) ;
V_242 ++ ;
}
if ( V_54 -> V_136 & V_277 ) {
const T_3 V_286 [] = { 0x08 , 0x06 } ;
F_101 ( V_2 -> V_14 , L_80 ) ;
V_279 [ V_242 * 4 ] = 0x0003 ;
V_279 [ V_242 * 4 + 1 ] = 0x00 ;
V_279 [ V_242 * 4 + 2 ] = 0x00 ;
V_279 [ V_242 * 4 + 3 ] = 0x00 ;
V_280 [ V_242 / 4 ] |= 0x05UL << ( ( V_242 % 4 ) * 8 ) ;
V_43 [ V_242 / 4 ] |= 0x0C << ( ( V_242 % 4 ) * 8 ) ;
V_243 [ V_242 / 2 ] |= F_91 ( V_286 , 2 , V_242 ) ;
V_242 ++ ;
}
if ( V_54 -> V_136 & V_278 ) {
F_101 ( V_2 -> V_14 , L_81 ) ;
V_279 [ V_242 * 4 ] = 0x003F ;
V_279 [ V_242 * 4 + 1 ] = 0x00 ;
V_279 [ V_242 * 4 + 2 ] = 0x00 ;
V_279 [ V_242 * 4 + 3 ] = 0x00 ;
V_280 [ V_242 / 4 ] |= 0x01UL << ( ( V_242 % 4 ) * 8 ) ;
V_43 [ V_242 / 4 ] |= 0x00 << ( ( V_242 % 4 ) * 8 ) ;
V_243 [ V_242 / 2 ] |= F_91 ( V_2 -> V_14 -> V_163 , V_52 , V_242 ) ;
V_242 ++ ;
}
for ( V_45 = 0 ; V_45 < ( V_281 * 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_287 , V_279 [ V_45 ] ) ;
if ( V_7 < 0 ) {
F_90 ( V_279 ) ;
goto V_32;
}
}
F_90 ( V_279 ) ;
for ( V_45 = 0 ; V_45 < ( V_281 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_287 , V_280 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_281 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_287 , V_43 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_281 / 2 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_287 , V_243 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_271 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_288 ;
V_7 = F_10 ( V_2 , V_271 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
if ( V_54 -> V_136 & V_289 ) {
V_7 = F_9 ( V_2 , V_271 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_290 ;
V_7 = F_10 ( V_2 , V_271 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_271 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
if ( V_54 -> V_136 & ( V_275 | V_276 | V_277 | V_278 ) ) {
F_101 ( V_2 -> V_14 , L_82 ) ;
V_21 |= V_273 ;
} else {
F_101 ( V_2 -> V_14 , L_83 ) ;
V_21 &= ~ V_273 ;
}
if ( V_54 -> V_136 & V_289 ) {
F_101 ( V_2 -> V_14 , L_84 ) ;
V_21 |= V_272 ;
} else {
F_101 ( V_2 -> V_14 , L_85 ) ;
V_21 &= ~ V_272 ;
}
V_7 = F_10 ( V_2 , V_271 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_274 ;
if ( V_54 -> V_136 & V_248 )
V_21 |= V_255 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
F_77 ( V_2 , 1 ) ;
F_101 ( V_2 -> V_14 , L_86 ) ;
V_7 = F_97 ( V_2 ) ;
V_32:
if ( V_7 && F_106 ( V_268 ) )
F_107 ( V_221 ) ;
return V_7 ;
}
static int F_108 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_104 ( V_221 ) ;
struct V_53 * V_54 ;
T_3 V_107 ;
int V_7 ;
T_2 V_21 ;
F_3 ( ! V_2 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_107 = V_54 -> V_107 ;
F_95 ( V_2 -> V_14 , L_87 , V_107 ) ;
V_54 -> V_107 = 0 ;
F_51 ( & V_54 -> V_106 , V_110 ) ;
if ( V_107 & V_291 ) {
V_7 = F_9 ( V_2 , V_271 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_273 | V_272 ) ;
V_7 = F_10 ( V_2 , V_271 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_191 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_274 ;
V_21 |= V_245 ;
V_7 = F_10 ( V_2 , V_191 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_107 ( V_221 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_88 ) ;
return V_7 ;
}
static int F_109 ( struct V_220 * V_221 )
{
struct V_1 * V_2 = F_104 ( V_221 ) ;
int V_7 ;
V_7 = F_81 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_108 ( V_221 ) ;
}
static void F_110 ( struct V_292 * V_293 )
{
V_293 -> V_294 = * ( T_4 * ) ( F_111 ( V_293 ) - 2 ) ;
V_293 -> V_295 = V_296 ;
F_112 ( V_293 , V_293 -> V_124 - 2 ) ;
}
static int F_113 ( struct V_1 * V_2 , struct V_292 * V_293 )
{
if ( V_293 -> V_124 < V_2 -> V_14 -> V_236 )
return 0 ;
while ( V_293 -> V_124 > 0 ) {
T_2 V_297 , V_298 ;
struct V_292 * V_299 ;
unsigned char * V_300 ;
T_4 V_51 ;
memcpy ( & V_297 , V_293 -> V_4 , sizeof( V_297 ) ) ;
F_6 ( & V_297 ) ;
F_114 ( V_293 , 4 + V_210 ) ;
V_300 = V_293 -> V_4 ;
V_51 = ( T_4 ) ( ( V_297 & V_301 ) >> 16 ) ;
V_298 = ( 4 - ( ( V_51 + V_210 ) % 4 ) ) % 4 ;
if ( F_4 ( V_297 & V_302 ) ) {
F_35 ( V_2 , V_303 , V_2 -> V_14 ,
L_89 , V_297 ) ;
V_2 -> V_14 -> V_304 . V_305 ++ ;
V_2 -> V_14 -> V_304 . V_306 ++ ;
if ( V_297 & V_307 ) {
V_2 -> V_14 -> V_304 . V_308 ++ ;
} else {
if ( V_297 & ( V_309 | V_310 ) )
V_2 -> V_14 -> V_304 . V_311 ++ ;
if ( ( V_297 & V_312 ) &&
( ! ( V_297 & V_313 ) ) )
V_2 -> V_14 -> V_304 . V_314 ++ ;
}
} else {
if ( F_4 ( V_51 > ( V_315 + 12 ) ) ) {
F_35 ( V_2 , V_303 , V_2 -> V_14 ,
L_90 , V_297 ) ;
return 0 ;
}
if ( V_293 -> V_124 == V_51 ) {
if ( V_2 -> V_14 -> V_111 & V_116 )
F_110 ( V_293 ) ;
F_112 ( V_293 , V_293 -> V_124 - 4 ) ;
V_293 -> V_316 = V_51 + sizeof( struct V_292 ) ;
return 1 ;
}
V_299 = F_115 ( V_293 , V_317 ) ;
if ( F_4 ( ! V_299 ) ) {
F_5 ( V_2 -> V_14 , L_91 ) ;
return 0 ;
}
V_299 -> V_124 = V_51 ;
V_299 -> V_4 = V_300 ;
F_116 ( V_299 , V_51 ) ;
if ( V_2 -> V_14 -> V_111 & V_116 )
F_110 ( V_299 ) ;
F_112 ( V_299 , V_299 -> V_124 - 4 ) ;
V_299 -> V_316 = V_51 + sizeof( struct V_292 ) ;
F_117 ( V_2 , V_299 ) ;
}
F_114 ( V_293 , V_51 ) ;
if ( V_293 -> V_124 )
F_114 ( V_293 , V_298 ) ;
}
return 1 ;
}
static T_2 F_118 ( struct V_292 * V_293 )
{
T_4 V_318 = ( T_4 ) F_119 ( V_293 ) ;
T_4 V_319 = V_318 + V_293 -> V_320 ;
return ( V_319 << 16 ) | V_318 ;
}
static struct V_292 * F_120 ( struct V_1 * V_2 ,
struct V_292 * V_293 , T_9 V_55 )
{
bool V_294 = V_293 -> V_295 == V_321 ;
int V_322 = V_294 ? V_237 : V_323 ;
T_2 V_324 , V_325 ;
F_3 ( F_121 ( V_293 ) -> V_326 ) ;
if ( F_122 ( V_293 , V_322 ) ) {
F_123 ( V_293 ) ;
return NULL ;
}
if ( V_294 ) {
if ( V_293 -> V_124 <= 45 ) {
long V_327 = F_119 ( V_293 ) ;
T_10 V_328 = F_124 ( V_293 -> V_4 + V_327 ,
V_293 -> V_124 - V_327 , 0 ) ;
* ( ( V_329 * ) ( V_293 -> V_4 + V_327
+ V_293 -> V_320 ) ) = F_125 ( V_328 ) ;
V_294 = false ;
} else {
T_2 V_330 = F_118 ( V_293 ) ;
F_126 ( V_293 , 4 ) ;
F_8 ( & V_330 ) ;
memcpy ( V_293 -> V_4 , & V_330 , 4 ) ;
}
}
F_126 ( V_293 , 4 ) ;
V_325 = ( T_2 ) ( V_293 -> V_124 - 4 ) ;
if ( V_294 )
V_325 |= V_331 ;
F_8 ( & V_325 ) ;
memcpy ( V_293 -> V_4 , & V_325 , 4 ) ;
F_126 ( V_293 , 4 ) ;
V_324 = ( T_2 ) ( V_293 -> V_124 - 8 ) | V_332 |
V_333 ;
F_8 ( & V_324 ) ;
memcpy ( V_293 -> V_4 , & V_324 , 4 ) ;
return V_293 ;
}
static int F_127 ( struct V_1 * V_2 , int V_334 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_221 -> V_335 = V_334 ;
if ( V_54 -> V_111 & V_229 )
return 0 ;
F_101 ( V_2 -> V_14 , L_92 ) ;
if ( V_334 )
F_128 ( V_2 -> V_221 ) ;
else
F_129 ( V_2 -> V_221 ) ;
return 0 ;
}
