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
if ( F_4 ( V_7 < 0 ) )
F_5 ( V_2 -> V_14 , L_1 ,
V_3 , V_7 ) ;
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
static int F_47 ( struct V_26 * V_27 ,
T_5 V_103 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
T_2 V_104 ;
int V_7 ;
V_7 = F_11 ( V_2 , V_105 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_103 & V_106 )
V_104 |= V_107 ;
else
V_104 &= ~ V_107 ;
if ( V_103 & V_108 )
V_104 |= V_109 ;
else
V_104 &= ~ V_109 ;
V_7 = F_12 ( V_2 , V_105 , V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_110 , V_2 -> V_14 , L_34 , V_104 ) ;
return 0 ;
}
static int F_48 ( struct V_26 * V_14 )
{
return V_111 ;
}
static int F_49 ( struct V_26 * V_27 ,
struct V_112 * V_113 , T_3 * V_4 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
V_113 -> V_114 = V_115 ;
return F_27 ( V_2 , V_113 -> V_43 , V_113 -> V_116 , V_4 ) ;
}
static int F_50 ( struct V_26 * V_27 ,
struct V_112 * V_113 , T_3 * V_4 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
if ( V_113 -> V_114 != V_115 ) {
F_5 ( V_2 -> V_14 , L_35 ,
V_113 -> V_114 ) ;
return - V_117 ;
}
return F_28 ( V_2 , V_113 -> V_43 , V_113 -> V_116 , V_4 ) ;
}
static int F_51 ( struct V_26 * V_27 )
{
return V_105 - V_118 + sizeof( T_2 ) ;
}
static void
F_52 ( struct V_26 * V_27 , struct V_119 * V_120 ,
void * V_6 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
unsigned int V_45 , V_121 ;
int V_122 ;
T_2 * V_4 = V_6 ;
V_122 = F_11 ( V_2 , V_118 , & V_120 -> V_123 ) ;
if ( V_122 < 0 ) {
F_5 ( V_27 , L_36 ) ;
return;
}
for ( V_45 = V_118 , V_121 = 0 ; V_45 <= V_105 ; V_45 += ( sizeof( T_2 ) ) , V_121 ++ ) {
V_122 = F_11 ( V_2 , V_45 , & V_4 [ V_121 ] ) ;
if ( V_122 < 0 ) {
F_5 ( V_27 , L_37 , V_45 ) ;
return;
}
}
}
static void F_53 ( struct V_26 * V_14 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_125 -> V_126 = V_127 ;
V_125 -> V_128 = V_54 -> V_128 ;
}
static int F_54 ( struct V_26 * V_14 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
V_54 -> V_128 = V_125 -> V_128 & V_127 ;
V_7 = F_55 ( & V_2 -> V_129 -> V_2 , V_54 -> V_128 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_38 , V_7 ) ;
return V_7 ;
}
static int F_56 ( struct V_26 * V_27 , struct V_130 * V_131 , int V_88 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
if ( ! F_57 ( V_27 ) )
return - V_117 ;
return F_58 ( & V_2 -> V_33 , F_59 ( V_131 ) , V_88 , NULL ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( F_27 ( V_2 , V_132 , V_52 ,
V_2 -> V_14 -> V_133 ) == 0 ) {
if ( F_61 ( V_2 -> V_14 -> V_133 ) ) {
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_39 ) ;
return;
}
}
F_62 ( V_2 -> V_14 ) ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_40 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_2 V_135 = V_2 -> V_14 -> V_133 [ 0 ] | V_2 -> V_14 -> V_133 [ 1 ] << 8 |
V_2 -> V_14 -> V_133 [ 2 ] << 16 | V_2 -> V_14 -> V_133 [ 3 ] << 24 ;
T_2 V_136 = V_2 -> V_14 -> V_133 [ 4 ] | V_2 -> V_14 -> V_133 [ 5 ] << 8 ;
int V_7 ;
V_7 = F_12 ( V_2 , V_137 , V_135 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_138 , V_136 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
int V_7 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_139 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
V_7 = F_12 ( V_2 , V_72 , V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_140 , V_141 ) ;
}
static int F_65 ( struct V_1 * V_2 , int V_5 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_142 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
return F_7 ( V_2 , V_72 , V_54 -> V_61 , V_5 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_143 , V_7 , V_144 = 0 ;
V_2 -> V_33 . V_2 = V_2 -> V_14 ;
V_2 -> V_33 . V_145 = F_22 ;
V_2 -> V_33 . V_146 = F_23 ;
V_2 -> V_33 . V_34 = 0x1f ;
V_2 -> V_33 . V_35 = 0x1f ;
V_2 -> V_33 . V_28 = V_147 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_148 , V_149 ) ;
do {
F_67 ( 10 ) ;
V_143 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_148 ) ;
V_144 ++ ;
} while ( ( V_143 & V_149 ) && ( V_144 < 100 ) );
if ( V_144 >= 100 ) {
F_5 ( V_2 -> V_14 , L_41 ) ;
return - V_25 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_93 ,
V_150 | V_151 | V_152 |
V_153 ) ;
V_7 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_90 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_42 ) ;
return V_7 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_154 ,
V_155 ) ;
F_68 ( & V_2 -> V_33 ) ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_43 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_104 , V_156 , V_157 ;
int V_7 = 0 , V_144 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_44 ) ;
V_7 = F_12 ( V_2 , V_158 , V_159 ) ;
if ( V_7 < 0 )
return V_7 ;
V_144 = 0 ;
do {
F_67 ( 10 ) ;
V_7 = F_11 ( V_2 , V_158 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_144 ++ ;
} while ( ( V_104 & V_159 ) && ( V_144 < 100 ) );
if ( V_144 >= 100 ) {
F_5 ( V_2 -> V_14 , L_45 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 , V_160 , V_161 ) ;
if ( V_7 < 0 )
return V_7 ;
V_144 = 0 ;
do {
F_67 ( 10 ) ;
V_7 = F_11 ( V_2 , V_160 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_144 ++ ;
} while ( ( V_104 & V_161 ) && ( V_144 < 100 ) );
if ( V_144 >= 100 ) {
F_5 ( V_2 -> V_14 , L_46 ) ;
return V_7 ;
}
V_7 = F_63 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_47 ,
V_2 -> V_14 -> V_133 ) ;
V_7 = F_11 ( V_2 , V_158 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_48 ,
V_104 ) ;
V_104 |= V_162 ;
V_7 = F_12 ( V_2 , V_158 , V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_158 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 ,
L_49 ,
V_104 ) ;
if ( ! V_163 ) {
V_157 = 0 ;
V_2 -> V_164 = V_165 ;
} else if ( V_2 -> V_129 -> V_166 == V_167 ) {
V_157 = V_168 / V_169 ;
V_2 -> V_164 = V_168 ;
} else {
V_157 = V_170 / V_171 ;
V_2 -> V_164 = V_170 ;
}
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_50 ,
( V_172 ) V_2 -> V_164 ) ;
V_7 = F_12 ( V_2 , V_173 , V_157 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_173 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 ,
L_51 ,
V_104 ) ;
V_7 = F_12 ( V_2 , V_174 , V_175 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_174 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 ,
L_52 ,
V_104 ) ;
V_7 = F_11 ( V_2 , V_158 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_53 ,
V_104 ) ;
if ( V_163 )
V_104 |= ( V_176 | V_177 ) ;
V_104 &= ~ V_178 ;
V_104 |= V_179 << 9 ;
V_7 = F_12 ( V_2 , V_158 , V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_158 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 ,
L_54 , V_104 ) ;
V_7 = F_12 ( V_2 , V_91 , V_92 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_118 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_55 , V_104 ) ;
V_156 = V_180 | V_181 |
V_182 ;
V_7 = F_12 ( V_2 , V_183 , V_156 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_84 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_78 , V_184 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_72 , & V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_185 , ( T_2 ) V_186 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_47 ( V_2 -> V_14 , V_2 -> V_14 -> V_103 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_56 ) ;
return V_7 ;
}
F_33 ( V_2 -> V_14 ) ;
V_7 = F_66 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_57 ) ;
return V_7 ;
}
V_7 = F_11 ( V_2 , V_187 , & V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_104 |= V_188 ;
V_7 = F_12 ( V_2 , V_187 , V_104 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_64 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_58 ) ;
return V_7 ;
}
V_7 = F_65 ( V_2 , 0 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_59 ) ;
return V_7 ;
}
F_35 ( V_2 , V_134 , V_2 -> V_14 , L_60 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
struct V_53 * V_54 = NULL ;
T_2 V_21 ;
int V_7 ;
F_71 (KERN_INFO SMSC_CHIPNAME L_61 SMSC_DRIVER_VERSION L_62 ) ;
V_7 = F_72 ( V_2 , V_190 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_63 , V_7 ) ;
return V_7 ;
}
V_2 -> V_4 [ 0 ] = ( unsigned long ) F_73 ( sizeof( struct V_53 ) ,
V_191 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( ! V_54 )
return - V_192 ;
F_74 ( & V_54 -> V_58 ) ;
if ( V_193 )
V_2 -> V_14 -> V_103 |= V_106 ;
if ( V_194 )
V_2 -> V_14 -> V_103 |= V_108 ;
V_2 -> V_14 -> V_195 = V_106 | V_108 ;
F_60 ( V_2 ) ;
V_7 = F_69 ( V_2 ) ;
V_7 = F_11 ( V_2 , V_118 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 >>= 16 ;
if ( ( V_21 == V_196 ) || ( V_21 == V_197 ) ||
( V_21 == V_198 ) || ( V_21 == V_199 ) )
V_54 -> V_103 = ( V_200 |
V_201 |
V_202 ) ;
else if ( V_21 == V_203 )
V_54 -> V_103 = V_200 ;
V_2 -> V_14 -> V_204 = & V_205 ;
V_2 -> V_14 -> V_206 = & V_207 ;
V_2 -> V_14 -> V_55 |= V_208 ;
V_2 -> V_14 -> V_209 += V_210 ;
V_2 -> V_211 = V_2 -> V_14 -> V_212 + V_2 -> V_14 -> V_209 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( V_54 ) {
F_35 ( V_2 , V_213 , V_2 -> V_14 , L_64 ) ;
F_76 ( V_54 ) ;
V_54 = NULL ;
V_2 -> V_4 [ 0 ] = 0 ;
}
}
static T_2 F_77 ( const T_3 * V_214 , T_6 V_116 , int V_215 )
{
T_2 V_216 = F_78 ( F_79 ( 0xFFFF , V_214 , V_116 ) ) ;
return V_216 << ( ( V_215 % 2 ) * 16 ) ;
}
static int F_80 ( struct V_1 * V_2 , T_4 V_69 )
{
struct V_85 * V_33 = & V_2 -> V_33 ;
int V_7 ;
F_81 ( V_2 -> V_14 , L_65 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_90 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_154 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_69 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_154 , V_7 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_85 * V_33 = & V_2 -> V_33 ;
int V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_217 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_217 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ! ( V_7 & V_218 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ( ~ ( V_219 | V_220 | V_161 ) ) ;
V_21 |= V_221 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_220 ;
V_21 |= V_222 ;
if ( V_54 -> V_128 & V_223 )
V_21 |= V_224 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_225 |= V_226 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
struct V_85 * V_33 = & V_2 -> V_33 ;
T_2 V_21 ;
int V_7 ;
if ( V_54 -> V_103 & V_201 )
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_227 ,
V_228 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_229 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_230 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_229 , V_7 ) ;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_219 | V_220 | V_161 ) ;
V_21 |= V_231 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_220 ;
V_21 |= ( V_224 | V_232 ) ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_225 |= V_233 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_219 | V_220 | V_161 ) ;
V_21 |= V_234 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_225 |= V_235 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_236 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_21 & 0xFFFF ) {
F_87 ( V_2 -> V_14 , L_66 ) ;
return - V_237 ;
}
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_219 | V_220 | V_161 ) ;
V_21 |= V_238 | V_239 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_220 ;
V_21 |= V_222 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_225 |= V_240 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , T_2 V_241 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
if ( ! F_57 ( V_2 -> V_14 ) ) {
F_81 ( V_2 -> V_14 , L_67 ) ;
return F_85 ( V_2 ) ;
}
if ( ! V_241 ) {
if ( ! ( V_54 -> V_103 & V_201 ) ) {
F_5 ( V_2 -> V_14 , L_68 ) ;
return - V_237 ;
}
F_81 ( V_2 -> V_14 , L_69 ) ;
V_7 = F_80 ( V_2 ,
V_242 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_70 ) ;
return V_7 ;
}
F_87 ( V_2 -> V_14 , L_71 ) ;
return F_84 ( V_2 ) ;
}
V_7 = F_80 ( V_2 ,
V_243 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_70 ) ;
return V_7 ;
}
F_81 ( V_2 -> V_14 , L_72 ) ;
return F_86 ( V_2 ) ;
}
static int F_89 ( struct V_189 * V_190 , T_7 V_244 )
{
struct V_1 * V_2 = F_90 ( V_190 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 , V_241 ;
int V_7 ;
V_7 = F_91 ( V_190 , V_244 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_73 ) ;
return V_7 ;
}
if ( V_54 -> V_225 ) {
F_5 ( V_2 -> V_14 , L_74 ) ;
V_54 -> V_225 = 0 ;
}
V_241 = F_82 ( V_2 ) ;
if ( V_244 . V_245 == V_246 &&
( V_54 -> V_103 & V_202 ) ) {
V_7 = F_88 ( V_2 , V_241 ) ;
goto V_32;
}
if ( ! ( V_54 -> V_128 & V_127 ) ||
! ( V_241 || ( V_54 -> V_128 & V_223 ) ) ) {
F_87 ( V_2 -> V_14 , L_75 ) ;
V_7 = F_9 ( V_2 , V_247 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_248 | V_249 ) ;
V_7 = F_10 ( V_2 , V_247 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_232 | V_250 ) ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_85 ( V_2 ) ;
goto V_32;
}
if ( V_54 -> V_128 & V_223 ) {
V_7 = F_80 ( V_2 ,
( V_242 | V_243 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_70 ) ;
goto V_32;
}
if ( ! V_241 ) {
F_87 ( V_2 -> V_14 , L_71 ) ;
V_7 = F_84 ( V_2 ) ;
goto V_32;
}
}
if ( V_54 -> V_128 & ( V_251 | V_252 | V_253 | V_254 ) ) {
T_2 * V_255 = F_73 ( sizeof( T_2 ) * 32 , V_191 ) ;
T_2 V_256 [ 2 ] ;
T_2 V_43 [ 2 ] ;
T_2 V_216 [ 4 ] ;
int V_257 =
( V_54 -> V_103 & V_200 ) ?
V_258 : V_259 ;
int V_45 , V_215 = 0 ;
if ( ! V_255 ) {
F_5 ( V_2 -> V_14 , L_76 ) ;
V_7 = - V_192 ;
goto V_32;
}
memset ( V_256 , 0 , sizeof( V_256 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_216 , 0 , sizeof( V_216 ) ) ;
if ( V_54 -> V_128 & V_251 ) {
const T_3 V_260 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
F_87 ( V_2 -> V_14 , L_77 ) ;
V_255 [ V_215 * 4 ] = 0x003F ;
V_255 [ V_215 * 4 + 1 ] = 0x00 ;
V_255 [ V_215 * 4 + 2 ] = 0x00 ;
V_255 [ V_215 * 4 + 3 ] = 0x00 ;
V_256 [ V_215 / 4 ] |= 0x05UL << ( ( V_215 % 4 ) * 8 ) ;
V_43 [ V_215 / 4 ] |= 0x00 << ( ( V_215 % 4 ) * 8 ) ;
V_216 [ V_215 / 2 ] |= F_77 ( V_260 , 6 , V_215 ) ;
V_215 ++ ;
}
if ( V_54 -> V_128 & V_252 ) {
const T_3 V_261 [] = { 0x01 , 0x00 , 0x5E } ;
F_87 ( V_2 -> V_14 , L_78 ) ;
V_255 [ V_215 * 4 ] = 0x0007 ;
V_255 [ V_215 * 4 + 1 ] = 0x00 ;
V_255 [ V_215 * 4 + 2 ] = 0x00 ;
V_255 [ V_215 * 4 + 3 ] = 0x00 ;
V_256 [ V_215 / 4 ] |= 0x09UL << ( ( V_215 % 4 ) * 8 ) ;
V_43 [ V_215 / 4 ] |= 0x00 << ( ( V_215 % 4 ) * 8 ) ;
V_216 [ V_215 / 2 ] |= F_77 ( V_261 , 3 , V_215 ) ;
V_215 ++ ;
}
if ( V_54 -> V_128 & V_253 ) {
const T_3 V_262 [] = { 0x08 , 0x06 } ;
F_87 ( V_2 -> V_14 , L_79 ) ;
V_255 [ V_215 * 4 ] = 0x0003 ;
V_255 [ V_215 * 4 + 1 ] = 0x00 ;
V_255 [ V_215 * 4 + 2 ] = 0x00 ;
V_255 [ V_215 * 4 + 3 ] = 0x00 ;
V_256 [ V_215 / 4 ] |= 0x05UL << ( ( V_215 % 4 ) * 8 ) ;
V_43 [ V_215 / 4 ] |= 0x0C << ( ( V_215 % 4 ) * 8 ) ;
V_216 [ V_215 / 2 ] |= F_77 ( V_262 , 2 , V_215 ) ;
V_215 ++ ;
}
if ( V_54 -> V_128 & V_254 ) {
F_87 ( V_2 -> V_14 , L_80 ) ;
V_255 [ V_215 * 4 ] = 0x003F ;
V_255 [ V_215 * 4 + 1 ] = 0x00 ;
V_255 [ V_215 * 4 + 2 ] = 0x00 ;
V_255 [ V_215 * 4 + 3 ] = 0x00 ;
V_256 [ V_215 / 4 ] |= 0x01UL << ( ( V_215 % 4 ) * 8 ) ;
V_43 [ V_215 / 4 ] |= 0x00 << ( ( V_215 % 4 ) * 8 ) ;
V_216 [ V_215 / 2 ] |= F_77 ( V_2 -> V_14 -> V_133 , V_52 , V_215 ) ;
V_215 ++ ;
}
for ( V_45 = 0 ; V_45 < ( V_257 * 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_263 , V_255 [ V_45 ] ) ;
if ( V_7 < 0 ) {
F_76 ( V_255 ) ;
goto V_32;
}
}
F_76 ( V_255 ) ;
for ( V_45 = 0 ; V_45 < ( V_257 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_263 , V_256 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_257 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_263 , V_43 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_257 / 2 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_263 , V_216 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_247 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_264 ;
V_7 = F_10 ( V_2 , V_247 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
if ( V_54 -> V_128 & V_265 ) {
V_7 = F_9 ( V_2 , V_247 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_266 ;
V_7 = F_10 ( V_2 , V_247 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_247 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
if ( V_54 -> V_128 & ( V_251 | V_252 | V_253 | V_254 ) ) {
F_87 ( V_2 -> V_14 , L_81 ) ;
V_21 |= V_249 ;
} else {
F_87 ( V_2 -> V_14 , L_82 ) ;
V_21 &= ~ V_249 ;
}
if ( V_54 -> V_128 & V_265 ) {
F_87 ( V_2 -> V_14 , L_83 ) ;
V_21 |= V_248 ;
} else {
F_87 ( V_2 -> V_14 , L_84 ) ;
V_21 &= ~ V_248 ;
}
V_7 = F_10 ( V_2 , V_247 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_250 ;
if ( V_54 -> V_128 & V_223 )
V_21 |= V_232 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
F_65 ( V_2 , 1 ) ;
F_87 ( V_2 -> V_14 , L_85 ) ;
V_7 = F_83 ( V_2 ) ;
V_32:
if ( V_7 && F_92 ( V_244 ) )
F_93 ( V_190 ) ;
return V_7 ;
}
static int F_94 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_90 ( V_190 ) ;
struct V_53 * V_54 ;
T_3 V_225 ;
int V_7 ;
T_2 V_21 ;
F_3 ( ! V_2 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_225 = V_54 -> V_225 ;
F_81 ( V_2 -> V_14 , L_86 , V_225 ) ;
V_54 -> V_225 = 0 ;
if ( V_225 & V_267 ) {
V_7 = F_9 ( V_2 , V_247 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_249 | V_248 ) ;
V_7 = F_10 ( V_2 , V_247 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_160 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_250 ;
V_21 |= V_220 ;
V_7 = F_10 ( V_2 , V_160 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_93 ( V_190 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_87 ) ;
return V_7 ;
}
static int F_95 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_90 ( V_190 ) ;
int V_7 ;
V_7 = F_69 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_94 ( V_190 ) ;
}
static void F_96 ( struct V_268 * V_269 )
{
V_269 -> V_270 = * ( T_4 * ) ( F_97 ( V_269 ) - 2 ) ;
V_269 -> V_271 = V_272 ;
F_98 ( V_269 , V_269 -> V_116 - 2 ) ;
}
static int F_99 ( struct V_1 * V_2 , struct V_268 * V_269 )
{
if ( V_269 -> V_116 < V_2 -> V_14 -> V_209 )
return 0 ;
while ( V_269 -> V_116 > 0 ) {
T_2 V_273 , V_274 ;
struct V_268 * V_275 ;
unsigned char * V_276 ;
T_4 V_51 ;
memcpy ( & V_273 , V_269 -> V_4 , sizeof( V_273 ) ) ;
F_6 ( & V_273 ) ;
F_100 ( V_269 , 4 + V_179 ) ;
V_276 = V_269 -> V_4 ;
V_51 = ( T_4 ) ( ( V_273 & V_277 ) >> 16 ) ;
V_274 = ( 4 - ( ( V_51 + V_179 ) % 4 ) ) % 4 ;
if ( F_4 ( V_273 & V_278 ) ) {
F_35 ( V_2 , V_279 , V_2 -> V_14 ,
L_88 , V_273 ) ;
V_2 -> V_14 -> V_280 . V_281 ++ ;
V_2 -> V_14 -> V_280 . V_282 ++ ;
if ( V_273 & V_283 ) {
V_2 -> V_14 -> V_280 . V_284 ++ ;
} else {
if ( V_273 & ( V_285 | V_286 ) )
V_2 -> V_14 -> V_280 . V_287 ++ ;
if ( ( V_273 & V_288 ) &&
( ! ( V_273 & V_289 ) ) )
V_2 -> V_14 -> V_280 . V_290 ++ ;
}
} else {
if ( F_4 ( V_51 > ( V_291 + 12 ) ) ) {
F_35 ( V_2 , V_279 , V_2 -> V_14 ,
L_89 , V_273 ) ;
return 0 ;
}
if ( V_269 -> V_116 == V_51 ) {
if ( V_2 -> V_14 -> V_103 & V_108 )
F_96 ( V_269 ) ;
F_98 ( V_269 , V_269 -> V_116 - 4 ) ;
V_269 -> V_292 = V_51 + sizeof( struct V_268 ) ;
return 1 ;
}
V_275 = F_101 ( V_269 , V_293 ) ;
if ( F_4 ( ! V_275 ) ) {
F_5 ( V_2 -> V_14 , L_90 ) ;
return 0 ;
}
V_275 -> V_116 = V_51 ;
V_275 -> V_4 = V_276 ;
F_102 ( V_275 , V_51 ) ;
if ( V_2 -> V_14 -> V_103 & V_108 )
F_96 ( V_275 ) ;
F_98 ( V_275 , V_275 -> V_116 - 4 ) ;
V_275 -> V_292 = V_51 + sizeof( struct V_268 ) ;
F_103 ( V_2 , V_275 ) ;
}
F_100 ( V_269 , V_51 ) ;
if ( V_269 -> V_116 )
F_100 ( V_269 , V_274 ) ;
}
if ( F_4 ( V_269 -> V_116 < 0 ) ) {
F_5 ( V_2 -> V_14 , L_91 , V_269 -> V_116 ) ;
return 0 ;
}
return 1 ;
}
static T_2 F_104 ( struct V_268 * V_269 )
{
T_4 V_294 = ( T_4 ) F_105 ( V_269 ) ;
T_4 V_295 = V_294 + V_269 -> V_296 ;
return ( V_295 << 16 ) | V_294 ;
}
static struct V_268 * F_106 ( struct V_1 * V_2 ,
struct V_268 * V_269 , T_8 V_55 )
{
bool V_270 = V_269 -> V_271 == V_297 ;
int V_298 = V_270 ? V_210 : V_299 ;
T_2 V_300 , V_301 ;
F_3 ( F_107 ( V_269 ) -> V_302 ) ;
if ( F_108 ( V_269 ) < V_298 ) {
struct V_268 * V_303 = F_109 ( V_269 ,
V_298 , 0 , V_55 ) ;
F_110 ( V_269 ) ;
V_269 = V_303 ;
if ( ! V_269 )
return NULL ;
}
if ( V_270 ) {
if ( V_269 -> V_116 <= 45 ) {
long V_304 = F_105 ( V_269 ) ;
T_9 V_305 = F_111 ( V_269 -> V_4 + V_304 ,
V_269 -> V_116 - V_304 , 0 ) ;
* ( ( V_306 * ) ( V_269 -> V_4 + V_304
+ V_269 -> V_296 ) ) = F_112 ( V_305 ) ;
V_270 = false ;
} else {
T_2 V_307 = F_104 ( V_269 ) ;
F_113 ( V_269 , 4 ) ;
F_8 ( & V_307 ) ;
memcpy ( V_269 -> V_4 , & V_307 , 4 ) ;
}
}
F_113 ( V_269 , 4 ) ;
V_301 = ( T_2 ) ( V_269 -> V_116 - 4 ) ;
if ( V_270 )
V_301 |= V_308 ;
F_8 ( & V_301 ) ;
memcpy ( V_269 -> V_4 , & V_301 , 4 ) ;
F_113 ( V_269 , 4 ) ;
V_300 = ( T_2 ) ( V_269 -> V_116 - 8 ) | V_309 |
V_310 ;
F_8 ( & V_300 ) ;
memcpy ( V_269 -> V_4 , & V_300 , 4 ) ;
return V_269 ;
}
static int F_114 ( struct V_1 * V_2 , int V_311 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_190 -> V_312 = V_311 ;
if ( V_54 -> V_103 & V_202 )
return 0 ;
F_87 ( V_2 -> V_14 , L_92 ) ;
if ( V_311 )
F_115 ( V_2 -> V_190 ) ;
else
F_116 ( V_2 -> V_190 ) ;
return 0 ;
}
