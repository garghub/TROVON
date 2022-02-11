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
struct V_86 * V_88 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_130 ;
V_130 = F_64 ( V_14 , V_88 ) ;
V_88 -> V_155 = V_54 -> V_147 ;
V_88 -> V_156 = V_54 -> V_147 ;
return V_130 ;
}
static int F_65 ( struct V_26 * V_14 ,
struct V_86 * V_88 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_130 ;
if ( V_54 -> V_147 != V_88 -> V_156 )
F_62 ( V_14 , V_88 -> V_156 ) ;
V_130 = F_66 ( V_14 , V_88 ) ;
return V_130 ;
}
static int F_67 ( struct V_26 * V_27 , struct V_157 * V_158 , int V_88 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
if ( ! F_68 ( V_27 ) )
return - V_125 ;
return F_69 ( & V_2 -> V_33 , F_70 ( V_158 ) , V_88 , NULL ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
const T_3 * V_159 ;
V_159 = F_72 ( V_2 -> V_137 -> V_2 . V_160 ) ;
if ( V_159 ) {
memcpy ( V_2 -> V_14 -> V_161 , V_159 , V_52 ) ;
return;
}
if ( F_27 ( V_2 , V_162 , V_52 ,
V_2 -> V_14 -> V_161 ) == 0 ) {
if ( F_73 ( V_2 -> V_14 -> V_161 ) ) {
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_40 ) ;
return;
}
}
F_74 ( V_2 -> V_14 ) ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_41 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_2 V_164 = V_2 -> V_14 -> V_161 [ 0 ] | V_2 -> V_14 -> V_161 [ 1 ] << 8 |
V_2 -> V_14 -> V_161 [ 2 ] << 16 | V_2 -> V_14 -> V_161 [ 3 ] << 24 ;
T_2 V_165 = V_2 -> V_14 -> V_161 [ 4 ] | V_2 -> V_14 -> V_161 [ 5 ] << 8 ;
int V_7 ;
V_7 = F_12 ( V_2 , V_166 , V_164 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_167 , V_165 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
int V_7 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_168 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
V_7 = F_12 ( V_2 , V_72 , V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_169 , V_170 ) ;
}
static int F_77 ( struct V_1 * V_2 , int V_5 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_171 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
return F_7 ( V_2 , V_72 , V_54 -> V_61 , V_5 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_172 , V_7 , V_173 = 0 ;
V_2 -> V_33 . V_2 = V_2 -> V_14 ;
V_2 -> V_33 . V_174 = F_22 ;
V_2 -> V_33 . V_175 = F_23 ;
V_2 -> V_33 . V_34 = 0x1f ;
V_2 -> V_33 . V_35 = 0x1f ;
V_2 -> V_33 . V_28 = V_176 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_177 , V_178 ) ;
do {
F_79 ( 10 ) ;
V_172 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_177 ) ;
V_173 ++ ;
} while ( ( V_172 & V_178 ) && ( V_173 < 100 ) );
if ( V_173 >= 100 ) {
F_5 ( V_2 -> V_14 , L_42 ) ;
return - V_25 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_93 ,
V_179 | V_180 | V_181 |
V_182 ) ;
V_7 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_90 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_43 ) ;
return V_7 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_183 ,
V_184 ) ;
F_80 ( & V_2 -> V_33 ) ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_44 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_112 , V_185 , V_186 ;
int V_7 = 0 , V_173 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_45 ) ;
V_7 = F_12 ( V_2 , V_187 , V_188 ) ;
if ( V_7 < 0 )
return V_7 ;
V_173 = 0 ;
do {
F_79 ( 10 ) ;
V_7 = F_11 ( V_2 , V_187 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_173 ++ ;
} while ( ( V_112 & V_188 ) && ( V_173 < 100 ) );
if ( V_173 >= 100 ) {
F_5 ( V_2 -> V_14 , L_46 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 , V_189 , V_190 ) ;
if ( V_7 < 0 )
return V_7 ;
V_173 = 0 ;
do {
F_79 ( 10 ) ;
V_7 = F_11 ( V_2 , V_189 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_173 ++ ;
} while ( ( V_112 & V_190 ) && ( V_173 < 100 ) );
if ( V_173 >= 100 ) {
F_5 ( V_2 -> V_14 , L_47 ) ;
return V_7 ;
}
V_7 = F_75 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_48 ,
V_2 -> V_14 -> V_161 ) ;
V_7 = F_11 ( V_2 , V_187 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_49 ,
V_112 ) ;
V_112 |= V_191 ;
V_7 = F_12 ( V_2 , V_187 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_187 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 ,
L_50 ,
V_112 ) ;
if ( ! V_192 ) {
V_186 = 0 ;
V_2 -> V_193 = V_194 ;
} else if ( V_2 -> V_137 -> V_195 == V_196 ) {
V_186 = V_197 / V_198 ;
V_2 -> V_193 = V_197 ;
} else {
V_186 = V_199 / V_200 ;
V_2 -> V_193 = V_199 ;
}
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_51 ,
( V_201 ) V_2 -> V_193 ) ;
V_7 = F_12 ( V_2 , V_202 , V_186 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_202 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 ,
L_52 ,
V_112 ) ;
V_7 = F_12 ( V_2 , V_203 , V_204 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_203 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 ,
L_53 ,
V_112 ) ;
V_7 = F_11 ( V_2 , V_187 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_54 ,
V_112 ) ;
if ( V_192 )
V_112 |= ( V_205 | V_206 ) ;
V_112 &= ~ V_207 ;
V_112 |= V_208 << 9 ;
V_7 = F_12 ( V_2 , V_187 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_187 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 ,
L_55 , V_112 ) ;
V_7 = F_12 ( V_2 , V_91 , V_92 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_126 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_56 , V_112 ) ;
V_185 = V_209 | V_210 |
V_211 ;
V_7 = F_12 ( V_2 , V_212 , V_185 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_84 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_78 , V_213 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_72 , & V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_214 , ( T_2 ) V_215 ) ;
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
V_7 = F_11 ( V_2 , V_216 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_112 |= V_217 ;
V_7 = F_12 ( V_2 , V_216 , V_112 ) ;
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
F_35 ( V_2 , V_163 , V_2 -> V_14 , L_61 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
struct V_53 * V_54 = NULL ;
T_2 V_21 ;
int V_7 ;
F_83 (KERN_INFO SMSC_CHIPNAME L_62 SMSC_DRIVER_VERSION L_63 ) ;
V_7 = F_84 ( V_2 , V_219 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_64 , V_7 ) ;
return V_7 ;
}
V_2 -> V_4 [ 0 ] = ( unsigned long ) F_85 ( sizeof( struct V_53 ) ,
V_220 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( ! V_54 )
return - V_221 ;
F_86 ( & V_54 -> V_58 ) ;
if ( V_222 )
V_2 -> V_14 -> V_111 |= V_114 ;
if ( V_223 )
V_2 -> V_14 -> V_111 |= V_116 ;
V_2 -> V_14 -> V_224 = V_114 | V_116 ;
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
V_54 -> V_111 = ( V_225 |
V_226 |
V_227 ) ;
else if ( V_21 == V_228 )
V_54 -> V_111 = V_225 ;
V_2 -> V_14 -> V_229 = & V_230 ;
V_2 -> V_14 -> V_231 = & V_232 ;
V_2 -> V_14 -> V_55 |= V_233 ;
V_2 -> V_14 -> V_234 += V_235 ;
V_2 -> V_236 = V_2 -> V_14 -> V_237 + V_2 -> V_14 -> V_234 ;
V_54 -> V_2 = V_2 ;
F_87 ( & V_54 -> V_106 , F_49 ) ;
F_51 ( & V_54 -> V_106 , V_110 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( V_54 ) {
F_89 ( & V_54 -> V_106 ) ;
F_35 ( V_2 , V_238 , V_2 -> V_14 , L_65 ) ;
F_90 ( V_54 ) ;
V_54 = NULL ;
V_2 -> V_4 [ 0 ] = 0 ;
}
}
static T_2 F_91 ( const T_3 * V_239 , T_7 V_124 , int V_240 )
{
T_2 V_241 = F_92 ( F_93 ( 0xFFFF , V_239 , V_124 ) ) ;
return V_241 << ( ( V_240 % 2 ) * 16 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_4 V_69 )
{
struct V_85 * V_33 = & V_2 -> V_33 ;
int V_7 ;
F_95 ( V_2 -> V_14 , L_66 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_90 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_183 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_69 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_183 , V_7 ) ;
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
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ( ~ ( V_242 | V_243 | V_190 ) ) ;
V_21 |= V_244 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_243 ;
V_21 |= V_245 ;
if ( V_54 -> V_136 & V_246 )
V_21 |= V_247 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_248 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
struct V_85 * V_33 = & V_2 -> V_33 ;
T_2 V_21 ;
int V_7 ;
if ( V_54 -> V_111 & V_226 )
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_153 ,
V_249 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_250 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_251 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_250 , V_7 ) ;
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_242 | V_243 | V_190 ) ;
V_21 |= V_252 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_243 ;
V_21 |= ( V_247 | V_253 ) ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_254 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_242 | V_243 | V_190 ) ;
V_21 |= V_255 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_256 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_257 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_21 & 0xFFFF ) {
F_101 ( V_2 -> V_14 , L_67 ) ;
return - V_258 ;
}
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_242 | V_243 | V_190 ) ;
V_21 |= V_259 | V_260 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_243 ;
V_21 |= V_245 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_261 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , T_2 V_262 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
if ( ! F_68 ( V_2 -> V_14 ) ) {
F_95 ( V_2 -> V_14 , L_68 ) ;
return F_99 ( V_2 ) ;
}
if ( ! V_262 ) {
if ( ! ( V_54 -> V_111 & V_226 ) ) {
F_5 ( V_2 -> V_14 , L_69 ) ;
return - V_258 ;
}
F_95 ( V_2 -> V_14 , L_70 ) ;
V_7 = F_94 ( V_2 ,
V_263 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
return V_7 ;
}
F_101 ( V_2 -> V_14 , L_72 ) ;
return F_98 ( V_2 ) ;
}
V_7 = F_94 ( V_2 ,
V_264 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
return V_7 ;
}
F_95 ( V_2 -> V_14 , L_73 ) ;
return F_100 ( V_2 ) ;
}
static int F_103 ( struct V_218 * V_219 , T_8 V_265 )
{
struct V_1 * V_2 = F_104 ( V_219 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 , V_262 ;
int V_7 ;
V_7 = F_105 ( V_219 , V_265 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_74 ) ;
return V_7 ;
}
if ( V_54 -> V_107 ) {
F_5 ( V_2 -> V_14 , L_75 ) ;
V_54 -> V_107 = 0 ;
}
V_262 = F_96 ( V_2 ) ;
if ( V_265 . V_266 == V_267 &&
( V_54 -> V_111 & V_227 ) ) {
V_7 = F_102 ( V_2 , V_262 ) ;
goto V_32;
}
if ( ! ( V_54 -> V_136 & V_135 ) ||
! ( V_262 || ( V_54 -> V_136 & V_246 ) ) ) {
F_101 ( V_2 -> V_14 , L_76 ) ;
V_7 = F_9 ( V_2 , V_268 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_269 | V_270 ) ;
V_7 = F_10 ( V_2 , V_268 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_253 | V_271 ) ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_99 ( V_2 ) ;
goto V_32;
}
if ( V_54 -> V_136 & V_246 ) {
V_7 = F_94 ( V_2 ,
( V_263 | V_264 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
goto V_32;
}
if ( ! V_262 ) {
F_101 ( V_2 -> V_14 , L_72 ) ;
V_7 = F_98 ( V_2 ) ;
goto V_32;
}
}
if ( V_54 -> V_136 & ( V_272 | V_273 | V_274 | V_275 ) ) {
T_2 * V_276 = F_85 ( sizeof( T_2 ) * 32 , V_220 ) ;
T_2 V_277 [ 2 ] ;
T_2 V_43 [ 2 ] ;
T_2 V_241 [ 4 ] ;
int V_278 =
( V_54 -> V_111 & V_225 ) ?
V_279 : V_280 ;
int V_45 , V_240 = 0 ;
if ( ! V_276 ) {
F_5 ( V_2 -> V_14 , L_77 ) ;
V_7 = - V_221 ;
goto V_32;
}
memset ( V_277 , 0 , sizeof( V_277 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_241 , 0 , sizeof( V_241 ) ) ;
if ( V_54 -> V_136 & V_272 ) {
const T_3 V_281 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
F_101 ( V_2 -> V_14 , L_78 ) ;
V_276 [ V_240 * 4 ] = 0x003F ;
V_276 [ V_240 * 4 + 1 ] = 0x00 ;
V_276 [ V_240 * 4 + 2 ] = 0x00 ;
V_276 [ V_240 * 4 + 3 ] = 0x00 ;
V_277 [ V_240 / 4 ] |= 0x05UL << ( ( V_240 % 4 ) * 8 ) ;
V_43 [ V_240 / 4 ] |= 0x00 << ( ( V_240 % 4 ) * 8 ) ;
V_241 [ V_240 / 2 ] |= F_91 ( V_281 , 6 , V_240 ) ;
V_240 ++ ;
}
if ( V_54 -> V_136 & V_273 ) {
const T_3 V_282 [] = { 0x01 , 0x00 , 0x5E } ;
F_101 ( V_2 -> V_14 , L_79 ) ;
V_276 [ V_240 * 4 ] = 0x0007 ;
V_276 [ V_240 * 4 + 1 ] = 0x00 ;
V_276 [ V_240 * 4 + 2 ] = 0x00 ;
V_276 [ V_240 * 4 + 3 ] = 0x00 ;
V_277 [ V_240 / 4 ] |= 0x09UL << ( ( V_240 % 4 ) * 8 ) ;
V_43 [ V_240 / 4 ] |= 0x00 << ( ( V_240 % 4 ) * 8 ) ;
V_241 [ V_240 / 2 ] |= F_91 ( V_282 , 3 , V_240 ) ;
V_240 ++ ;
}
if ( V_54 -> V_136 & V_274 ) {
const T_3 V_283 [] = { 0x08 , 0x06 } ;
F_101 ( V_2 -> V_14 , L_80 ) ;
V_276 [ V_240 * 4 ] = 0x0003 ;
V_276 [ V_240 * 4 + 1 ] = 0x00 ;
V_276 [ V_240 * 4 + 2 ] = 0x00 ;
V_276 [ V_240 * 4 + 3 ] = 0x00 ;
V_277 [ V_240 / 4 ] |= 0x05UL << ( ( V_240 % 4 ) * 8 ) ;
V_43 [ V_240 / 4 ] |= 0x0C << ( ( V_240 % 4 ) * 8 ) ;
V_241 [ V_240 / 2 ] |= F_91 ( V_283 , 2 , V_240 ) ;
V_240 ++ ;
}
if ( V_54 -> V_136 & V_275 ) {
F_101 ( V_2 -> V_14 , L_81 ) ;
V_276 [ V_240 * 4 ] = 0x003F ;
V_276 [ V_240 * 4 + 1 ] = 0x00 ;
V_276 [ V_240 * 4 + 2 ] = 0x00 ;
V_276 [ V_240 * 4 + 3 ] = 0x00 ;
V_277 [ V_240 / 4 ] |= 0x01UL << ( ( V_240 % 4 ) * 8 ) ;
V_43 [ V_240 / 4 ] |= 0x00 << ( ( V_240 % 4 ) * 8 ) ;
V_241 [ V_240 / 2 ] |= F_91 ( V_2 -> V_14 -> V_161 , V_52 , V_240 ) ;
V_240 ++ ;
}
for ( V_45 = 0 ; V_45 < ( V_278 * 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_284 , V_276 [ V_45 ] ) ;
if ( V_7 < 0 ) {
F_90 ( V_276 ) ;
goto V_32;
}
}
F_90 ( V_276 ) ;
for ( V_45 = 0 ; V_45 < ( V_278 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_284 , V_277 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_278 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_284 , V_43 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_278 / 2 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_284 , V_241 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_268 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_285 ;
V_7 = F_10 ( V_2 , V_268 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
if ( V_54 -> V_136 & V_286 ) {
V_7 = F_9 ( V_2 , V_268 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_287 ;
V_7 = F_10 ( V_2 , V_268 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_268 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
if ( V_54 -> V_136 & ( V_272 | V_273 | V_274 | V_275 ) ) {
F_101 ( V_2 -> V_14 , L_82 ) ;
V_21 |= V_270 ;
} else {
F_101 ( V_2 -> V_14 , L_83 ) ;
V_21 &= ~ V_270 ;
}
if ( V_54 -> V_136 & V_286 ) {
F_101 ( V_2 -> V_14 , L_84 ) ;
V_21 |= V_269 ;
} else {
F_101 ( V_2 -> V_14 , L_85 ) ;
V_21 &= ~ V_269 ;
}
V_7 = F_10 ( V_2 , V_268 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_271 ;
if ( V_54 -> V_136 & V_246 )
V_21 |= V_253 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
F_77 ( V_2 , 1 ) ;
F_101 ( V_2 -> V_14 , L_86 ) ;
V_7 = F_97 ( V_2 ) ;
V_32:
if ( V_7 && F_106 ( V_265 ) )
F_107 ( V_219 ) ;
return V_7 ;
}
static int F_108 ( struct V_218 * V_219 )
{
struct V_1 * V_2 = F_104 ( V_219 ) ;
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
if ( V_107 & V_288 ) {
V_7 = F_9 ( V_2 , V_268 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_270 | V_269 ) ;
V_7 = F_10 ( V_2 , V_268 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_189 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_271 ;
V_21 |= V_243 ;
V_7 = F_10 ( V_2 , V_189 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_107 ( V_219 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_88 ) ;
return V_7 ;
}
static int F_109 ( struct V_218 * V_219 )
{
struct V_1 * V_2 = F_104 ( V_219 ) ;
int V_7 ;
V_7 = F_81 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_108 ( V_219 ) ;
}
static void F_110 ( struct V_289 * V_290 )
{
V_290 -> V_291 = * ( T_4 * ) ( F_111 ( V_290 ) - 2 ) ;
V_290 -> V_292 = V_293 ;
F_112 ( V_290 , V_290 -> V_124 - 2 ) ;
}
static int F_113 ( struct V_1 * V_2 , struct V_289 * V_290 )
{
if ( V_290 -> V_124 < V_2 -> V_14 -> V_234 )
return 0 ;
while ( V_290 -> V_124 > 0 ) {
T_2 V_294 , V_295 ;
struct V_289 * V_296 ;
unsigned char * V_297 ;
T_4 V_51 ;
memcpy ( & V_294 , V_290 -> V_4 , sizeof( V_294 ) ) ;
F_6 ( & V_294 ) ;
F_114 ( V_290 , 4 + V_208 ) ;
V_297 = V_290 -> V_4 ;
V_51 = ( T_4 ) ( ( V_294 & V_298 ) >> 16 ) ;
V_295 = ( 4 - ( ( V_51 + V_208 ) % 4 ) ) % 4 ;
if ( F_4 ( V_294 & V_299 ) ) {
F_35 ( V_2 , V_300 , V_2 -> V_14 ,
L_89 , V_294 ) ;
V_2 -> V_14 -> V_301 . V_302 ++ ;
V_2 -> V_14 -> V_301 . V_303 ++ ;
if ( V_294 & V_304 ) {
V_2 -> V_14 -> V_301 . V_305 ++ ;
} else {
if ( V_294 & ( V_306 | V_307 ) )
V_2 -> V_14 -> V_301 . V_308 ++ ;
if ( ( V_294 & V_309 ) &&
( ! ( V_294 & V_310 ) ) )
V_2 -> V_14 -> V_301 . V_311 ++ ;
}
} else {
if ( F_4 ( V_51 > ( V_312 + 12 ) ) ) {
F_35 ( V_2 , V_300 , V_2 -> V_14 ,
L_90 , V_294 ) ;
return 0 ;
}
if ( V_290 -> V_124 == V_51 ) {
if ( V_2 -> V_14 -> V_111 & V_116 )
F_110 ( V_290 ) ;
F_112 ( V_290 , V_290 -> V_124 - 4 ) ;
V_290 -> V_313 = V_51 + sizeof( struct V_289 ) ;
return 1 ;
}
V_296 = F_115 ( V_290 , V_314 ) ;
if ( F_4 ( ! V_296 ) ) {
F_5 ( V_2 -> V_14 , L_91 ) ;
return 0 ;
}
V_296 -> V_124 = V_51 ;
V_296 -> V_4 = V_297 ;
F_116 ( V_296 , V_51 ) ;
if ( V_2 -> V_14 -> V_111 & V_116 )
F_110 ( V_296 ) ;
F_112 ( V_296 , V_296 -> V_124 - 4 ) ;
V_296 -> V_313 = V_51 + sizeof( struct V_289 ) ;
F_117 ( V_2 , V_296 ) ;
}
F_114 ( V_290 , V_51 ) ;
if ( V_290 -> V_124 )
F_114 ( V_290 , V_295 ) ;
}
return 1 ;
}
static T_2 F_118 ( struct V_289 * V_290 )
{
T_4 V_315 = ( T_4 ) F_119 ( V_290 ) ;
T_4 V_316 = V_315 + V_290 -> V_317 ;
return ( V_316 << 16 ) | V_315 ;
}
static struct V_289 * F_120 ( struct V_1 * V_2 ,
struct V_289 * V_290 , T_9 V_55 )
{
bool V_291 = V_290 -> V_292 == V_318 ;
int V_319 = V_291 ? V_235 : V_320 ;
T_2 V_321 , V_322 ;
F_3 ( F_121 ( V_290 ) -> V_323 ) ;
if ( F_122 ( V_290 ) < V_319 ) {
struct V_289 * V_324 = F_123 ( V_290 ,
V_319 , 0 , V_55 ) ;
F_124 ( V_290 ) ;
V_290 = V_324 ;
if ( ! V_290 )
return NULL ;
}
if ( V_291 ) {
if ( V_290 -> V_124 <= 45 ) {
long V_325 = F_119 ( V_290 ) ;
T_10 V_326 = F_125 ( V_290 -> V_4 + V_325 ,
V_290 -> V_124 - V_325 , 0 ) ;
* ( ( V_327 * ) ( V_290 -> V_4 + V_325
+ V_290 -> V_317 ) ) = F_126 ( V_326 ) ;
V_291 = false ;
} else {
T_2 V_328 = F_118 ( V_290 ) ;
F_127 ( V_290 , 4 ) ;
F_8 ( & V_328 ) ;
memcpy ( V_290 -> V_4 , & V_328 , 4 ) ;
}
}
F_127 ( V_290 , 4 ) ;
V_322 = ( T_2 ) ( V_290 -> V_124 - 4 ) ;
if ( V_291 )
V_322 |= V_329 ;
F_8 ( & V_322 ) ;
memcpy ( V_290 -> V_4 , & V_322 , 4 ) ;
F_127 ( V_290 , 4 ) ;
V_321 = ( T_2 ) ( V_290 -> V_124 - 8 ) | V_330 |
V_331 ;
F_8 ( & V_321 ) ;
memcpy ( V_290 -> V_4 , & V_321 , 4 ) ;
return V_290 ;
}
static int F_128 ( struct V_1 * V_2 , int V_332 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_219 -> V_333 = V_332 ;
if ( V_54 -> V_111 & V_227 )
return 0 ;
F_101 ( V_2 -> V_14 , L_92 ) ;
if ( V_332 )
F_129 ( V_2 -> V_219 ) ;
else
F_130 ( V_2 -> V_219 ) ;
return 0 ;
}
