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
static int F_61 ( struct V_26 * V_27 , struct V_138 * V_139 , int V_88 )
{
struct V_1 * V_2 = F_16 ( V_27 ) ;
if ( ! F_62 ( V_27 ) )
return - V_125 ;
return F_63 ( & V_2 -> V_33 , F_64 ( V_139 ) , V_88 , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
const T_3 * V_140 ;
V_140 = F_66 ( V_2 -> V_137 -> V_2 . V_141 ) ;
if ( V_140 ) {
memcpy ( V_2 -> V_14 -> V_142 , V_140 , V_52 ) ;
return;
}
if ( F_27 ( V_2 , V_143 , V_52 ,
V_2 -> V_14 -> V_142 ) == 0 ) {
if ( F_67 ( V_2 -> V_14 -> V_142 ) ) {
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_40 ) ;
return;
}
}
F_68 ( V_2 -> V_14 ) ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_41 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_145 = V_2 -> V_14 -> V_142 [ 0 ] | V_2 -> V_14 -> V_142 [ 1 ] << 8 |
V_2 -> V_14 -> V_142 [ 2 ] << 16 | V_2 -> V_14 -> V_142 [ 3 ] << 24 ;
T_2 V_146 = V_2 -> V_14 -> V_142 [ 4 ] | V_2 -> V_14 -> V_142 [ 5 ] << 8 ;
int V_7 ;
V_7 = F_12 ( V_2 , V_147 , V_145 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_148 , V_146 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
int V_7 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_149 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
V_7 = F_12 ( V_2 , V_72 , V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_2 , V_150 , V_151 ) ;
}
static int F_71 ( struct V_1 * V_2 , int V_5 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_55 ;
F_34 ( & V_54 -> V_58 , V_55 ) ;
V_54 -> V_61 |= V_152 ;
F_38 ( & V_54 -> V_58 , V_55 ) ;
return F_7 ( V_2 , V_72 , V_54 -> V_61 , V_5 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_153 , V_7 , V_154 = 0 ;
V_2 -> V_33 . V_2 = V_2 -> V_14 ;
V_2 -> V_33 . V_155 = F_22 ;
V_2 -> V_33 . V_156 = F_23 ;
V_2 -> V_33 . V_34 = 0x1f ;
V_2 -> V_33 . V_35 = 0x1f ;
V_2 -> V_33 . V_28 = V_157 ;
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_158 , V_159 ) ;
do {
F_73 ( 10 ) ;
V_153 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_158 ) ;
V_154 ++ ;
} while ( ( V_153 & V_159 ) && ( V_154 < 100 ) );
if ( V_154 >= 100 ) {
F_5 ( V_2 -> V_14 , L_42 ) ;
return - V_25 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_93 ,
V_160 | V_161 | V_162 |
V_163 ) ;
V_7 = F_22 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_90 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_43 ) ;
return V_7 ;
}
F_23 ( V_2 -> V_14 , V_2 -> V_33 . V_28 , V_164 ,
V_165 ) ;
F_74 ( & V_2 -> V_33 ) ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_44 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_112 , V_166 , V_167 ;
int V_7 = 0 , V_154 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_45 ) ;
V_7 = F_12 ( V_2 , V_168 , V_169 ) ;
if ( V_7 < 0 )
return V_7 ;
V_154 = 0 ;
do {
F_73 ( 10 ) ;
V_7 = F_11 ( V_2 , V_168 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_154 ++ ;
} while ( ( V_112 & V_169 ) && ( V_154 < 100 ) );
if ( V_154 >= 100 ) {
F_5 ( V_2 -> V_14 , L_46 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 , V_170 , V_171 ) ;
if ( V_7 < 0 )
return V_7 ;
V_154 = 0 ;
do {
F_73 ( 10 ) ;
V_7 = F_11 ( V_2 , V_170 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_154 ++ ;
} while ( ( V_112 & V_171 ) && ( V_154 < 100 ) );
if ( V_154 >= 100 ) {
F_5 ( V_2 -> V_14 , L_47 ) ;
return V_7 ;
}
V_7 = F_69 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_48 ,
V_2 -> V_14 -> V_142 ) ;
V_7 = F_11 ( V_2 , V_168 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_49 ,
V_112 ) ;
V_112 |= V_172 ;
V_7 = F_12 ( V_2 , V_168 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_168 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 ,
L_50 ,
V_112 ) ;
if ( ! V_173 ) {
V_167 = 0 ;
V_2 -> V_174 = V_175 ;
} else if ( V_2 -> V_137 -> V_176 == V_177 ) {
V_167 = V_178 / V_179 ;
V_2 -> V_174 = V_178 ;
} else {
V_167 = V_180 / V_181 ;
V_2 -> V_174 = V_180 ;
}
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_51 ,
( V_182 ) V_2 -> V_174 ) ;
V_7 = F_12 ( V_2 , V_183 , V_167 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_183 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 ,
L_52 ,
V_112 ) ;
V_7 = F_12 ( V_2 , V_184 , V_185 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_184 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 ,
L_53 ,
V_112 ) ;
V_7 = F_11 ( V_2 , V_168 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_54 ,
V_112 ) ;
if ( V_173 )
V_112 |= ( V_186 | V_187 ) ;
V_112 &= ~ V_188 ;
V_112 |= V_189 << 9 ;
V_7 = F_12 ( V_2 , V_168 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_168 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 ,
L_55 , V_112 ) ;
V_7 = F_12 ( V_2 , V_91 , V_92 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_126 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_56 , V_112 ) ;
V_166 = V_190 | V_191 |
V_192 ;
V_7 = F_12 ( V_2 , V_193 , V_166 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_84 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_78 , V_194 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 , V_72 , & V_54 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_2 , V_195 , ( T_2 ) V_196 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_52 ( V_2 -> V_14 , V_2 -> V_14 -> V_111 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_57 ) ;
return V_7 ;
}
F_33 ( V_2 -> V_14 ) ;
V_7 = F_72 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_58 ) ;
return V_7 ;
}
V_7 = F_11 ( V_2 , V_197 , & V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_112 |= V_198 ;
V_7 = F_12 ( V_2 , V_197 , V_112 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_70 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_59 ) ;
return V_7 ;
}
V_7 = F_71 ( V_2 , 0 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_60 ) ;
return V_7 ;
}
F_35 ( V_2 , V_144 , V_2 -> V_14 , L_61 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_199 * V_200 )
{
struct V_53 * V_54 = NULL ;
T_2 V_21 ;
int V_7 ;
F_77 (KERN_INFO SMSC_CHIPNAME L_62 SMSC_DRIVER_VERSION L_63 ) ;
V_7 = F_78 ( V_2 , V_200 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_64 , V_7 ) ;
return V_7 ;
}
V_2 -> V_4 [ 0 ] = ( unsigned long ) F_79 ( sizeof( struct V_53 ) ,
V_201 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( ! V_54 )
return - V_202 ;
F_80 ( & V_54 -> V_58 ) ;
if ( V_203 )
V_2 -> V_14 -> V_111 |= V_114 ;
if ( V_204 )
V_2 -> V_14 -> V_111 |= V_116 ;
V_2 -> V_14 -> V_205 = V_114 | V_116 ;
F_65 ( V_2 ) ;
V_7 = F_75 ( V_2 ) ;
V_7 = F_11 ( V_2 , V_126 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 >>= 16 ;
if ( ( V_21 == V_206 ) || ( V_21 == V_207 ) ||
( V_21 == V_208 ) || ( V_21 == V_209 ) )
V_54 -> V_111 = ( V_210 |
V_211 |
V_212 ) ;
else if ( V_21 == V_213 )
V_54 -> V_111 = V_210 ;
V_2 -> V_14 -> V_214 = & V_215 ;
V_2 -> V_14 -> V_216 = & V_217 ;
V_2 -> V_14 -> V_55 |= V_218 ;
V_2 -> V_14 -> V_219 += V_220 ;
V_2 -> V_221 = V_2 -> V_14 -> V_222 + V_2 -> V_14 -> V_219 ;
V_54 -> V_2 = V_2 ;
F_81 ( & V_54 -> V_106 , F_49 ) ;
F_51 ( & V_54 -> V_106 , V_110 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 , struct V_199 * V_200 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( V_54 ) {
F_83 ( & V_54 -> V_106 ) ;
F_35 ( V_2 , V_223 , V_2 -> V_14 , L_65 ) ;
F_84 ( V_54 ) ;
V_54 = NULL ;
V_2 -> V_4 [ 0 ] = 0 ;
}
}
static T_2 F_85 ( const T_3 * V_224 , T_6 V_124 , int V_225 )
{
T_2 V_226 = F_86 ( F_87 ( 0xFFFF , V_224 , V_124 ) ) ;
return V_226 << ( ( V_225 % 2 ) * 16 ) ;
}
static int F_88 ( struct V_1 * V_2 , T_4 V_69 )
{
struct V_85 * V_33 = & V_2 -> V_33 ;
int V_7 ;
F_89 ( V_2 -> V_14 , L_66 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_90 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_164 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_69 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_164 , V_7 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
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
static int F_91 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ( ~ ( V_227 | V_228 | V_171 ) ) ;
V_21 |= V_229 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_228 ;
V_21 |= V_230 ;
if ( V_54 -> V_136 & V_231 )
V_21 |= V_232 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_233 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
struct V_85 * V_33 = & V_2 -> V_33 ;
T_2 V_21 ;
int V_7 ;
if ( V_54 -> V_111 & V_211 )
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_234 ,
V_235 ) ;
V_7 = F_20 ( V_2 -> V_14 , V_33 -> V_28 , V_236 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 |= V_237 ;
F_21 ( V_2 -> V_14 , V_33 -> V_28 , V_236 , V_7 ) ;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_227 | V_228 | V_171 ) ;
V_21 |= V_238 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_228 ;
V_21 |= ( V_232 | V_239 ) ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_240 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_227 | V_228 | V_171 ) ;
V_21 |= V_241 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_242 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 ;
int V_7 ;
V_7 = F_9 ( V_2 , V_243 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_21 & 0xFFFF ) {
F_95 ( V_2 -> V_14 , L_67 ) ;
return - V_244 ;
}
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_227 | V_228 | V_171 ) ;
V_21 |= V_245 | V_246 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_228 ;
V_21 |= V_230 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 -> V_107 |= V_247 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , T_2 V_248 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
if ( ! F_62 ( V_2 -> V_14 ) ) {
F_89 ( V_2 -> V_14 , L_68 ) ;
return F_93 ( V_2 ) ;
}
if ( ! V_248 ) {
if ( ! ( V_54 -> V_111 & V_211 ) ) {
F_5 ( V_2 -> V_14 , L_69 ) ;
return - V_244 ;
}
F_89 ( V_2 -> V_14 , L_70 ) ;
V_7 = F_88 ( V_2 ,
V_249 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
return V_7 ;
}
F_95 ( V_2 -> V_14 , L_72 ) ;
return F_92 ( V_2 ) ;
}
V_7 = F_88 ( V_2 ,
V_250 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
return V_7 ;
}
F_89 ( V_2 -> V_14 , L_73 ) ;
return F_94 ( V_2 ) ;
}
static int F_97 ( struct V_199 * V_200 , T_7 V_251 )
{
struct V_1 * V_2 = F_98 ( V_200 ) ;
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_21 , V_248 ;
int V_7 ;
V_7 = F_99 ( V_200 , V_251 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_74 ) ;
return V_7 ;
}
if ( V_54 -> V_107 ) {
F_5 ( V_2 -> V_14 , L_75 ) ;
V_54 -> V_107 = 0 ;
}
V_248 = F_90 ( V_2 ) ;
if ( V_251 . V_252 == V_253 &&
( V_54 -> V_111 & V_212 ) ) {
V_7 = F_96 ( V_2 , V_248 ) ;
goto V_32;
}
if ( ! ( V_54 -> V_136 & V_135 ) ||
! ( V_248 || ( V_54 -> V_136 & V_231 ) ) ) {
F_95 ( V_2 -> V_14 , L_76 ) ;
V_7 = F_9 ( V_2 , V_254 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_255 | V_256 ) ;
V_7 = F_10 ( V_2 , V_254 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 &= ~ ( V_239 | V_257 ) ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_93 ( V_2 ) ;
goto V_32;
}
if ( V_54 -> V_136 & V_231 ) {
V_7 = F_88 ( V_2 ,
( V_249 | V_250 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_14 , L_71 ) ;
goto V_32;
}
if ( ! V_248 ) {
F_95 ( V_2 -> V_14 , L_72 ) ;
V_7 = F_92 ( V_2 ) ;
goto V_32;
}
}
if ( V_54 -> V_136 & ( V_258 | V_259 | V_260 | V_261 ) ) {
T_2 * V_262 = F_79 ( sizeof( T_2 ) * 32 , V_201 ) ;
T_2 V_263 [ 2 ] ;
T_2 V_43 [ 2 ] ;
T_2 V_226 [ 4 ] ;
int V_264 =
( V_54 -> V_111 & V_210 ) ?
V_265 : V_266 ;
int V_45 , V_225 = 0 ;
if ( ! V_262 ) {
F_5 ( V_2 -> V_14 , L_77 ) ;
V_7 = - V_202 ;
goto V_32;
}
memset ( V_263 , 0 , sizeof( V_263 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_226 , 0 , sizeof( V_226 ) ) ;
if ( V_54 -> V_136 & V_258 ) {
const T_3 V_267 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
F_95 ( V_2 -> V_14 , L_78 ) ;
V_262 [ V_225 * 4 ] = 0x003F ;
V_262 [ V_225 * 4 + 1 ] = 0x00 ;
V_262 [ V_225 * 4 + 2 ] = 0x00 ;
V_262 [ V_225 * 4 + 3 ] = 0x00 ;
V_263 [ V_225 / 4 ] |= 0x05UL << ( ( V_225 % 4 ) * 8 ) ;
V_43 [ V_225 / 4 ] |= 0x00 << ( ( V_225 % 4 ) * 8 ) ;
V_226 [ V_225 / 2 ] |= F_85 ( V_267 , 6 , V_225 ) ;
V_225 ++ ;
}
if ( V_54 -> V_136 & V_259 ) {
const T_3 V_268 [] = { 0x01 , 0x00 , 0x5E } ;
F_95 ( V_2 -> V_14 , L_79 ) ;
V_262 [ V_225 * 4 ] = 0x0007 ;
V_262 [ V_225 * 4 + 1 ] = 0x00 ;
V_262 [ V_225 * 4 + 2 ] = 0x00 ;
V_262 [ V_225 * 4 + 3 ] = 0x00 ;
V_263 [ V_225 / 4 ] |= 0x09UL << ( ( V_225 % 4 ) * 8 ) ;
V_43 [ V_225 / 4 ] |= 0x00 << ( ( V_225 % 4 ) * 8 ) ;
V_226 [ V_225 / 2 ] |= F_85 ( V_268 , 3 , V_225 ) ;
V_225 ++ ;
}
if ( V_54 -> V_136 & V_260 ) {
const T_3 V_269 [] = { 0x08 , 0x06 } ;
F_95 ( V_2 -> V_14 , L_80 ) ;
V_262 [ V_225 * 4 ] = 0x0003 ;
V_262 [ V_225 * 4 + 1 ] = 0x00 ;
V_262 [ V_225 * 4 + 2 ] = 0x00 ;
V_262 [ V_225 * 4 + 3 ] = 0x00 ;
V_263 [ V_225 / 4 ] |= 0x05UL << ( ( V_225 % 4 ) * 8 ) ;
V_43 [ V_225 / 4 ] |= 0x0C << ( ( V_225 % 4 ) * 8 ) ;
V_226 [ V_225 / 2 ] |= F_85 ( V_269 , 2 , V_225 ) ;
V_225 ++ ;
}
if ( V_54 -> V_136 & V_261 ) {
F_95 ( V_2 -> V_14 , L_81 ) ;
V_262 [ V_225 * 4 ] = 0x003F ;
V_262 [ V_225 * 4 + 1 ] = 0x00 ;
V_262 [ V_225 * 4 + 2 ] = 0x00 ;
V_262 [ V_225 * 4 + 3 ] = 0x00 ;
V_263 [ V_225 / 4 ] |= 0x01UL << ( ( V_225 % 4 ) * 8 ) ;
V_43 [ V_225 / 4 ] |= 0x00 << ( ( V_225 % 4 ) * 8 ) ;
V_226 [ V_225 / 2 ] |= F_85 ( V_2 -> V_14 -> V_142 , V_52 , V_225 ) ;
V_225 ++ ;
}
for ( V_45 = 0 ; V_45 < ( V_264 * 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_270 , V_262 [ V_45 ] ) ;
if ( V_7 < 0 ) {
F_84 ( V_262 ) ;
goto V_32;
}
}
F_84 ( V_262 ) ;
for ( V_45 = 0 ; V_45 < ( V_264 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_270 , V_263 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_264 / 4 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_270 , V_43 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
for ( V_45 = 0 ; V_45 < ( V_264 / 2 ) ; V_45 ++ ) {
V_7 = F_10 ( V_2 , V_270 , V_226 [ V_45 ] ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_254 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_271 ;
V_7 = F_10 ( V_2 , V_254 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
if ( V_54 -> V_136 & V_272 ) {
V_7 = F_9 ( V_2 , V_254 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_273 ;
V_7 = F_10 ( V_2 , V_254 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
}
V_7 = F_9 ( V_2 , V_254 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
if ( V_54 -> V_136 & ( V_258 | V_259 | V_260 | V_261 ) ) {
F_95 ( V_2 -> V_14 , L_82 ) ;
V_21 |= V_256 ;
} else {
F_95 ( V_2 -> V_14 , L_83 ) ;
V_21 &= ~ V_256 ;
}
if ( V_54 -> V_136 & V_272 ) {
F_95 ( V_2 -> V_14 , L_84 ) ;
V_21 |= V_255 ;
} else {
F_95 ( V_2 -> V_14 , L_85 ) ;
V_21 &= ~ V_255 ;
}
V_7 = F_10 ( V_2 , V_254 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
goto V_32;
V_21 |= V_257 ;
if ( V_54 -> V_136 & V_231 )
V_21 |= V_239 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
goto V_32;
F_71 ( V_2 , 1 ) ;
F_95 ( V_2 -> V_14 , L_86 ) ;
V_7 = F_91 ( V_2 ) ;
V_32:
if ( V_7 && F_100 ( V_251 ) )
F_101 ( V_200 ) ;
return V_7 ;
}
static int F_102 ( struct V_199 * V_200 )
{
struct V_1 * V_2 = F_98 ( V_200 ) ;
struct V_53 * V_54 ;
T_3 V_107 ;
int V_7 ;
T_2 V_21 ;
F_3 ( ! V_2 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_107 = V_54 -> V_107 ;
F_89 ( V_2 -> V_14 , L_87 , V_107 ) ;
V_54 -> V_107 = 0 ;
F_51 ( & V_54 -> V_106 , V_110 ) ;
if ( V_107 & V_274 ) {
V_7 = F_9 ( V_2 , V_254 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ ( V_256 | V_255 ) ;
V_7 = F_10 ( V_2 , V_254 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_2 , V_170 , & V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 &= ~ V_257 ;
V_21 |= V_228 ;
V_7 = F_10 ( V_2 , V_170 , V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_101 ( V_200 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_14 , L_88 ) ;
return V_7 ;
}
static int F_103 ( struct V_199 * V_200 )
{
struct V_1 * V_2 = F_98 ( V_200 ) ;
int V_7 ;
V_7 = F_75 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_102 ( V_200 ) ;
}
static void F_104 ( struct V_275 * V_276 )
{
V_276 -> V_277 = * ( T_4 * ) ( F_105 ( V_276 ) - 2 ) ;
V_276 -> V_278 = V_279 ;
F_106 ( V_276 , V_276 -> V_124 - 2 ) ;
}
static int F_107 ( struct V_1 * V_2 , struct V_275 * V_276 )
{
if ( V_276 -> V_124 < V_2 -> V_14 -> V_219 )
return 0 ;
while ( V_276 -> V_124 > 0 ) {
T_2 V_280 , V_281 ;
struct V_275 * V_282 ;
unsigned char * V_283 ;
T_4 V_51 ;
memcpy ( & V_280 , V_276 -> V_4 , sizeof( V_280 ) ) ;
F_6 ( & V_280 ) ;
F_108 ( V_276 , 4 + V_189 ) ;
V_283 = V_276 -> V_4 ;
V_51 = ( T_4 ) ( ( V_280 & V_284 ) >> 16 ) ;
V_281 = ( 4 - ( ( V_51 + V_189 ) % 4 ) ) % 4 ;
if ( F_4 ( V_280 & V_285 ) ) {
F_35 ( V_2 , V_286 , V_2 -> V_14 ,
L_89 , V_280 ) ;
V_2 -> V_14 -> V_287 . V_288 ++ ;
V_2 -> V_14 -> V_287 . V_289 ++ ;
if ( V_280 & V_290 ) {
V_2 -> V_14 -> V_287 . V_291 ++ ;
} else {
if ( V_280 & ( V_292 | V_293 ) )
V_2 -> V_14 -> V_287 . V_294 ++ ;
if ( ( V_280 & V_295 ) &&
( ! ( V_280 & V_296 ) ) )
V_2 -> V_14 -> V_287 . V_297 ++ ;
}
} else {
if ( F_4 ( V_51 > ( V_298 + 12 ) ) ) {
F_35 ( V_2 , V_286 , V_2 -> V_14 ,
L_90 , V_280 ) ;
return 0 ;
}
if ( V_276 -> V_124 == V_51 ) {
if ( V_2 -> V_14 -> V_111 & V_116 )
F_104 ( V_276 ) ;
F_106 ( V_276 , V_276 -> V_124 - 4 ) ;
V_276 -> V_299 = V_51 + sizeof( struct V_275 ) ;
return 1 ;
}
V_282 = F_109 ( V_276 , V_300 ) ;
if ( F_4 ( ! V_282 ) ) {
F_5 ( V_2 -> V_14 , L_91 ) ;
return 0 ;
}
V_282 -> V_124 = V_51 ;
V_282 -> V_4 = V_283 ;
F_110 ( V_282 , V_51 ) ;
if ( V_2 -> V_14 -> V_111 & V_116 )
F_104 ( V_282 ) ;
F_106 ( V_282 , V_282 -> V_124 - 4 ) ;
V_282 -> V_299 = V_51 + sizeof( struct V_275 ) ;
F_111 ( V_2 , V_282 ) ;
}
F_108 ( V_276 , V_51 ) ;
if ( V_276 -> V_124 )
F_108 ( V_276 , V_281 ) ;
}
return 1 ;
}
static T_2 F_112 ( struct V_275 * V_276 )
{
T_4 V_301 = ( T_4 ) F_113 ( V_276 ) ;
T_4 V_302 = V_301 + V_276 -> V_303 ;
return ( V_302 << 16 ) | V_301 ;
}
static struct V_275 * F_114 ( struct V_1 * V_2 ,
struct V_275 * V_276 , T_8 V_55 )
{
bool V_277 = V_276 -> V_278 == V_304 ;
int V_305 = V_277 ? V_220 : V_306 ;
T_2 V_307 , V_308 ;
F_3 ( F_115 ( V_276 ) -> V_309 ) ;
if ( F_116 ( V_276 ) < V_305 ) {
struct V_275 * V_310 = F_117 ( V_276 ,
V_305 , 0 , V_55 ) ;
F_118 ( V_276 ) ;
V_276 = V_310 ;
if ( ! V_276 )
return NULL ;
}
if ( V_277 ) {
if ( V_276 -> V_124 <= 45 ) {
long V_311 = F_113 ( V_276 ) ;
T_9 V_312 = F_119 ( V_276 -> V_4 + V_311 ,
V_276 -> V_124 - V_311 , 0 ) ;
* ( ( V_313 * ) ( V_276 -> V_4 + V_311
+ V_276 -> V_303 ) ) = F_120 ( V_312 ) ;
V_277 = false ;
} else {
T_2 V_314 = F_112 ( V_276 ) ;
F_121 ( V_276 , 4 ) ;
F_8 ( & V_314 ) ;
memcpy ( V_276 -> V_4 , & V_314 , 4 ) ;
}
}
F_121 ( V_276 , 4 ) ;
V_308 = ( T_2 ) ( V_276 -> V_124 - 4 ) ;
if ( V_277 )
V_308 |= V_315 ;
F_8 ( & V_308 ) ;
memcpy ( V_276 -> V_4 , & V_308 , 4 ) ;
F_121 ( V_276 , 4 ) ;
V_307 = ( T_2 ) ( V_276 -> V_124 - 8 ) | V_316 |
V_317 ;
F_8 ( & V_307 ) ;
memcpy ( V_276 -> V_4 , & V_307 , 4 ) ;
return V_276 ;
}
static int F_122 ( struct V_1 * V_2 , int V_318 )
{
struct V_53 * V_54 = (struct V_53 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_200 -> V_319 = V_318 ;
if ( V_54 -> V_111 & V_212 )
return 0 ;
F_95 ( V_2 -> V_14 , L_92 ) ;
if ( V_318 )
F_123 ( V_2 -> V_200 ) ;
else
F_124 ( V_2 -> V_200 ) ;
return 0 ;
}
