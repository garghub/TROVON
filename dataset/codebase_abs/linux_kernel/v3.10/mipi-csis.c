static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static const struct V_5 * F_3 (
struct V_6 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_9 ) ; V_8 ++ )
if ( V_7 -> V_10 == V_9 [ V_8 ] . V_10 )
return & V_9 [ V_8 ] ;
return NULL ;
}
static void F_5 ( struct V_1 * V_11 , bool V_12 )
{
T_1 V_13 = F_6 ( V_11 , V_14 ) ;
V_13 = V_12 ? V_13 | V_15 :
V_13 & ~ V_15 ;
F_7 ( V_11 , V_14 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_11 )
{
T_1 V_13 = F_6 ( V_11 , V_16 ) ;
F_7 ( V_11 , V_16 , V_13 | V_17 ) ;
F_9 ( 10 ) ;
}
static void F_10 ( struct V_1 * V_11 , int V_12 )
{
T_1 V_13 , V_18 ;
V_13 = F_6 ( V_11 , V_16 ) ;
if ( V_12 )
V_13 |= V_19 ;
else
V_13 &= ~ V_19 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_20 ) ;
V_13 &= ~ V_21 ;
if ( V_12 ) {
V_18 = ( 1 << ( V_11 -> V_22 + 1 ) ) - 1 ;
V_13 |= ( V_18 & V_21 ) ;
}
F_7 ( V_11 , V_20 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_23 ;
T_1 V_13 ;
F_12 ( 1 , V_24 , & V_11 -> V_4 , L_1 ,
V_7 -> V_10 , V_7 -> V_25 , V_7 -> V_26 ) ;
V_13 = F_6 ( V_11 , V_27 ) ;
V_13 = ( V_13 & ~ V_28 ) | V_11 -> V_29 -> V_30 ;
F_7 ( V_11 , V_27 , V_13 ) ;
V_13 = ( V_7 -> V_25 << 16 ) | V_7 -> V_26 ;
F_7 ( V_11 , V_31 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_11 , int V_32 )
{
T_1 V_13 = F_6 ( V_11 , V_20 ) ;
V_13 = ( V_13 & ~ V_33 ) | ( V_32 << 27 ) ;
F_7 ( V_11 , V_20 , V_13 ) ;
}
static void F_14 ( struct V_1 * V_11 )
{
T_1 V_13 ;
V_13 = F_6 ( V_11 , V_27 ) ;
V_13 = ( V_13 & ~ V_34 ) | ( V_11 -> V_22 - 1 ) ;
F_7 ( V_11 , V_27 , V_13 ) ;
F_11 ( V_11 ) ;
F_13 ( V_11 , V_11 -> V_35 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
if ( V_11 -> V_29 -> V_36 == 32 )
V_13 |= V_37 ;
else
V_13 &= ~ V_37 ;
V_13 &= ~ V_38 ;
if ( V_11 -> V_39 )
V_13 |= V_38 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
F_7 ( V_11 , V_16 , V_13 | V_40 ) ;
}
static void F_15 ( struct V_1 * V_11 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ ) {
if ( F_16 ( V_11 -> clock [ V_8 ] ) )
continue;
F_17 ( V_11 -> clock [ V_8 ] ) ;
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = F_19 ( - V_42 ) ;
}
}
static int F_20 ( struct V_1 * V_11 )
{
struct V_43 * V_44 = & V_11 -> V_45 -> V_44 ;
int V_8 , V_46 ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ )
V_11 -> clock [ V_8 ] = F_19 ( - V_42 ) ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ ) {
V_11 -> clock [ V_8 ] = F_21 ( V_44 , V_47 [ V_8 ] ) ;
if ( F_16 ( V_11 -> clock [ V_8 ] ) ) {
V_46 = F_22 ( V_11 -> clock [ V_8 ] ) ;
goto V_48;
}
V_46 = F_23 ( V_11 -> clock [ V_8 ] ) ;
if ( V_46 < 0 ) {
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = F_19 ( - V_42 ) ;
goto V_48;
}
}
return 0 ;
V_48:
F_15 ( V_11 ) ;
F_24 ( V_44 , L_2 , V_47 [ V_8 ] ) ;
return V_46 ;
}
static void F_25 ( struct V_1 * V_11 , const char * V_49 )
{
struct {
T_1 V_50 ;
const char * const V_51 ;
} V_52 [] = {
{ 0x00 , L_3 } ,
{ 0x04 , L_4 } ,
{ 0x08 , L_5 } ,
{ 0x0c , L_6 } ,
{ 0x10 , L_7 } ,
{ 0x2c , L_8 } ,
{ 0x38 , L_9 } ,
} ;
T_1 V_8 ;
F_26 ( & V_11 -> V_4 , L_10 , V_49 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_52 ) ; V_8 ++ ) {
T_1 V_53 = F_6 ( V_11 , V_52 [ V_8 ] . V_50 ) ;
F_26 ( & V_11 -> V_4 , L_11 , V_52 [ V_8 ] . V_51 , V_53 ) ;
}
}
static void F_27 ( struct V_1 * V_11 )
{
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
F_10 ( V_11 , true ) ;
F_5 ( V_11 , true ) ;
}
static void F_28 ( struct V_1 * V_11 )
{
F_5 ( V_11 , false ) ;
F_10 ( V_11 , false ) ;
}
static void F_29 ( struct V_1 * V_11 )
{
unsigned long V_54 ;
int V_8 ;
F_30 ( & V_11 -> V_55 , V_54 ) ;
for ( V_8 = 0 ; V_8 < V_56 ; V_8 ++ )
V_11 -> V_57 [ V_8 ] . V_58 = 0 ;
F_31 ( & V_11 -> V_55 , V_54 ) ;
}
static void F_32 ( struct V_1 * V_11 , bool V_59 )
{
int V_8 = V_59 ? V_56 : V_56 - 4 ;
unsigned long V_54 ;
F_30 ( & V_11 -> V_55 , V_54 ) ;
for ( V_8 -- ; V_8 >= 0 ; V_8 -- ) {
if ( V_11 -> V_57 [ V_8 ] . V_58 > 0 || V_24 )
F_26 ( & V_11 -> V_4 , L_12 ,
V_11 -> V_57 [ V_8 ] . V_51 ,
V_11 -> V_57 [ V_8 ] . V_58 ) ;
}
F_31 ( & V_11 -> V_55 , V_54 ) ;
}
static int F_33 ( struct V_2 * V_4 , int V_12 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_43 * V_44 = & V_11 -> V_45 -> V_44 ;
if ( V_12 )
return F_34 ( V_44 ) ;
return F_35 ( V_44 ) ;
}
static int F_36 ( struct V_2 * V_4 , int V_60 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_24 , V_4 , L_13 ,
V_61 , V_60 , V_11 -> V_54 ) ;
if ( V_60 ) {
F_29 ( V_11 ) ;
V_46 = F_34 ( & V_11 -> V_45 -> V_44 ) ;
if ( V_46 && V_46 != 1 )
return V_46 ;
}
F_37 ( & V_11 -> V_62 ) ;
if ( V_60 ) {
if ( V_11 -> V_54 & V_63 ) {
V_46 = - V_64 ;
goto V_65;
}
F_27 ( V_11 ) ;
V_11 -> V_54 |= V_66 ;
} else {
F_28 ( V_11 ) ;
V_11 -> V_54 &= ~ V_66 ;
if ( V_24 > 0 )
F_32 ( V_11 , true ) ;
}
V_65:
F_38 ( & V_11 -> V_62 ) ;
if ( ! V_60 )
F_39 ( & V_11 -> V_45 -> V_44 ) ;
return V_46 == 1 ? 0 : V_46 ;
}
static int F_40 ( struct V_2 * V_4 ,
struct V_67 * V_68 ,
struct V_69 * V_10 )
{
if ( V_10 -> V_70 >= F_4 ( V_9 ) )
return - V_42 ;
V_10 -> V_10 = V_9 [ V_10 -> V_70 ] . V_10 ;
return 0 ;
}
static struct V_5 const * F_41 (
struct V_6 * V_7 )
{
struct V_5 const * V_29 ;
V_29 = F_3 ( V_7 ) ;
if ( V_29 == NULL )
V_29 = & V_9 [ 0 ] ;
V_7 -> V_10 = V_29 -> V_10 ;
F_42 ( & V_7 -> V_25 , 1 , V_71 ,
V_29 -> V_72 ,
& V_7 -> V_26 , 1 , V_73 , 1 ,
0 ) ;
return V_29 ;
}
static struct V_6 * F_43 (
struct V_1 * V_11 , struct V_67 * V_68 ,
enum V_74 V_75 )
{
if ( V_75 == V_76 )
return V_68 ? F_44 ( V_68 , 0 ) : NULL ;
return & V_11 -> V_23 ;
}
static int F_45 ( struct V_2 * V_4 , struct V_67 * V_68 ,
struct V_77 * V_78 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_5 const * V_29 ;
struct V_6 * V_7 ;
V_7 = F_43 ( V_11 , V_68 , V_78 -> V_75 ) ;
if ( V_78 -> V_79 == V_80 ) {
if ( V_7 ) {
F_37 ( & V_11 -> V_62 ) ;
V_78 -> V_23 = * V_7 ;
F_38 ( & V_11 -> V_62 ) ;
}
return 0 ;
}
V_29 = F_41 ( & V_78 -> V_23 ) ;
if ( V_7 ) {
F_37 ( & V_11 -> V_62 ) ;
* V_7 = V_78 -> V_23 ;
if ( V_78 -> V_75 == V_81 )
V_11 -> V_29 = V_29 ;
F_38 ( & V_11 -> V_62 ) ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_4 , struct V_67 * V_68 ,
struct V_77 * V_78 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_6 * V_7 ;
V_7 = F_43 ( V_11 , V_68 , V_78 -> V_75 ) ;
if ( ! V_7 )
return - V_42 ;
F_37 ( & V_11 -> V_62 ) ;
V_78 -> V_23 = * V_7 ;
F_38 ( & V_11 -> V_62 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_4 , void * V_82 ,
unsigned int * V_83 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_54 ;
* V_83 = F_48 (unsigned int, *size, S5PCSIS_PKTDATA_SIZE) ;
F_30 ( & V_11 -> V_55 , V_54 ) ;
V_11 -> V_84 . V_85 = V_82 ;
V_11 -> V_84 . V_86 = * V_83 ;
F_31 ( & V_11 -> V_55 , V_54 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_37 ( & V_11 -> V_62 ) ;
F_32 ( V_11 , true ) ;
if ( V_24 && ( V_11 -> V_54 & V_87 ) )
F_25 ( V_11 , V_61 ) ;
F_38 ( & V_11 -> V_62 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_4 , struct V_67 * V_68 )
{
struct V_6 * V_23 = F_44 ( V_68 , 0 ) ;
V_23 -> V_88 = V_89 ;
V_23 -> V_10 = V_9 [ 0 ] . V_10 ;
V_23 -> V_25 = V_90 ;
V_23 -> V_26 = V_91 ;
V_23 -> V_92 = V_93 ;
return 0 ;
}
static T_2 F_51 ( int V_94 , void * V_95 )
{
struct V_1 * V_11 = V_95 ;
struct V_96 * V_97 = & V_11 -> V_84 ;
unsigned long V_54 ;
T_1 V_98 ;
V_98 = F_6 ( V_11 , V_99 ) ;
F_30 ( & V_11 -> V_55 , V_54 ) ;
if ( ( V_98 & V_100 ) && V_97 -> V_85 ) {
T_1 V_50 ;
if ( V_98 & V_101 )
V_50 = V_102 ;
else
V_50 = V_103 ;
memcpy ( V_97 -> V_85 , V_11 -> V_104 + V_50 , V_97 -> V_86 ) ;
V_97 -> V_85 = NULL ;
F_52 () ;
}
if ( ( V_98 & V_105 ) || V_24 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_56 ; V_8 ++ ) {
if ( ! ( V_98 & V_11 -> V_57 [ V_8 ] . V_18 ) )
continue;
V_11 -> V_57 [ V_8 ] . V_58 ++ ;
F_12 ( 2 , V_24 , & V_11 -> V_4 , L_14 ,
V_11 -> V_57 [ V_8 ] . V_51 ,
V_11 -> V_57 [ V_8 ] . V_58 ) ;
}
F_12 ( 2 , V_24 , & V_11 -> V_4 , L_15 , V_98 ) ;
}
F_31 ( & V_11 -> V_55 , V_54 ) ;
F_7 ( V_11 , V_99 , V_98 ) ;
return V_106 ;
}
static int F_53 ( struct V_107 * V_45 ,
struct V_1 * V_11 )
{
struct V_108 * V_109 = V_45 -> V_44 . V_110 ;
if ( V_109 == NULL ) {
F_24 ( & V_45 -> V_44 , L_16 ) ;
return - V_42 ;
}
V_11 -> V_111 = V_109 -> V_112 ;
V_11 -> V_22 = V_109 -> V_113 ;
V_11 -> V_35 = V_109 -> V_35 ;
V_11 -> V_70 = F_54 ( 0 , V_45 -> V_114 ) ;
V_11 -> V_115 = V_11 -> V_70 ? V_116 :
V_117 ;
return 0 ;
}
static int F_55 ( struct V_107 * V_45 ,
struct V_1 * V_11 )
{
struct V_118 * V_119 = V_45 -> V_44 . V_120 ;
struct V_121 V_122 ;
if ( F_56 ( V_119 , L_17 ,
& V_11 -> V_111 ) )
V_11 -> V_111 = V_123 ;
if ( F_56 ( V_119 , L_18 ,
& V_11 -> V_115 ) )
return - V_42 ;
V_119 = F_57 ( V_119 , NULL ) ;
if ( ! V_119 ) {
F_24 ( & V_45 -> V_44 , L_19 ,
V_45 -> V_44 . V_120 -> V_124 ) ;
return - V_42 ;
}
F_58 ( V_119 , & V_122 ) ;
V_11 -> V_70 = V_122 . V_125 - V_126 ;
if ( V_11 -> V_70 < 0 || V_11 -> V_70 >= V_127 )
return - V_128 ;
F_56 ( V_119 , L_20 ,
& V_11 -> V_35 ) ;
V_11 -> V_39 = F_59 ( V_119 ,
L_21 ) ;
V_11 -> V_22 = V_122 . V_129 . V_130 . V_131 ;
F_60 ( V_119 ) ;
return 0 ;
}
static int F_61 ( struct V_107 * V_45 )
{
struct V_43 * V_44 = & V_45 -> V_44 ;
struct V_132 * V_133 ;
struct V_1 * V_11 ;
int V_46 = - V_134 ;
int V_8 ;
V_11 = F_62 ( V_44 , sizeof( * V_11 ) , V_135 ) ;
if ( ! V_11 )
return - V_134 ;
F_63 ( & V_11 -> V_62 ) ;
F_64 ( & V_11 -> V_55 ) ;
V_11 -> V_45 = V_45 ;
if ( V_44 -> V_120 )
V_46 = F_55 ( V_45 , V_11 ) ;
else
V_46 = F_53 ( V_45 , V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_11 -> V_22 == 0 || V_11 -> V_22 > V_11 -> V_115 ) {
F_24 ( V_44 , L_22 ,
V_11 -> V_22 , V_11 -> V_115 ) ;
return - V_42 ;
}
V_133 = F_65 ( V_45 , V_136 , 0 ) ;
V_11 -> V_104 = F_66 ( V_44 , V_133 ) ;
if ( F_16 ( V_11 -> V_104 ) )
return F_22 ( V_11 -> V_104 ) ;
V_11 -> V_94 = F_67 ( V_45 , 0 ) ;
if ( V_11 -> V_94 < 0 ) {
F_24 ( V_44 , L_23 ) ;
return V_11 -> V_94 ;
}
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ )
V_11 -> V_138 [ V_8 ] . V_139 = V_140 [ V_8 ] ;
V_46 = F_68 ( V_44 , V_137 ,
V_11 -> V_138 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_20 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_11 -> V_111 )
V_46 = F_69 ( V_11 -> clock [ V_141 ] ,
V_11 -> V_111 ) ;
else
F_70 ( V_44 , L_24 ) ;
if ( V_46 < 0 )
goto V_142;
V_46 = F_71 ( V_11 -> clock [ V_141 ] ) ;
if ( V_46 < 0 )
goto V_142;
V_46 = F_72 ( V_44 , V_11 -> V_94 , F_51 ,
0 , F_73 ( V_44 ) , V_11 ) ;
if ( V_46 ) {
F_24 ( V_44 , L_25 ) ;
goto V_143;
}
F_74 ( & V_11 -> V_4 , & V_144 ) ;
V_11 -> V_4 . V_145 = V_146 ;
snprintf ( V_11 -> V_4 . V_51 , sizeof( V_11 -> V_4 . V_51 ) , L_26 ,
V_147 , V_11 -> V_70 ) ;
V_11 -> V_4 . V_54 |= V_148 ;
V_11 -> V_29 = & V_9 [ 0 ] ;
V_11 -> V_23 . V_10 = V_9 [ 0 ] . V_10 ;
V_11 -> V_23 . V_25 = V_90 ;
V_11 -> V_23 . V_26 = V_91 ;
V_11 -> V_149 [ V_150 ] . V_54 = V_151 ;
V_11 -> V_149 [ V_80 ] . V_54 = V_152 ;
V_46 = F_75 ( & V_11 -> V_4 . V_153 ,
V_154 , V_11 -> V_149 , 0 ) ;
if ( V_46 < 0 )
goto V_143;
F_76 ( & V_11 -> V_4 , V_45 ) ;
F_77 ( V_45 , & V_11 -> V_4 ) ;
memcpy ( V_11 -> V_57 , V_155 , sizeof( V_11 -> V_57 ) ) ;
F_78 ( V_44 ) ;
F_79 ( & V_45 -> V_44 , L_27 ,
V_11 -> V_22 , V_11 -> V_35 , V_11 -> V_39 ,
V_11 -> V_111 ) ;
return 0 ;
V_143:
F_80 ( V_11 -> clock [ V_141 ] ) ;
V_142:
F_15 ( V_11 ) ;
return V_46 ;
}
static int F_81 ( struct V_43 * V_44 , bool V_156 )
{
struct V_107 * V_45 = F_82 ( V_44 ) ;
struct V_2 * V_4 = F_83 ( V_45 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_24 , V_4 , L_28 ,
V_61 , V_11 -> V_54 ) ;
F_37 ( & V_11 -> V_62 ) ;
if ( V_11 -> V_54 & V_87 ) {
F_28 ( V_11 ) ;
V_46 = F_84 ( V_11 -> V_70 , false ) ;
if ( V_46 )
goto V_65;
V_46 = F_85 ( V_137 ,
V_11 -> V_138 ) ;
if ( V_46 )
goto V_65;
F_80 ( V_11 -> clock [ V_157 ] ) ;
V_11 -> V_54 &= ~ V_87 ;
if ( ! V_156 )
V_11 -> V_54 |= V_63 ;
}
V_65:
F_38 ( & V_11 -> V_62 ) ;
return V_46 ? - V_158 : 0 ;
}
static int F_86 ( struct V_43 * V_44 , bool V_156 )
{
struct V_107 * V_45 = F_82 ( V_44 ) ;
struct V_2 * V_4 = F_83 ( V_45 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_24 , V_4 , L_28 ,
V_61 , V_11 -> V_54 ) ;
F_37 ( & V_11 -> V_62 ) ;
if ( ! V_156 && ! ( V_11 -> V_54 & V_63 ) )
goto V_65;
if ( ! ( V_11 -> V_54 & V_87 ) ) {
V_46 = F_87 ( V_137 ,
V_11 -> V_138 ) ;
if ( V_46 )
goto V_65;
V_46 = F_84 ( V_11 -> V_70 , true ) ;
if ( ! V_46 ) {
V_11 -> V_54 |= V_87 ;
} else {
F_85 ( V_137 ,
V_11 -> V_138 ) ;
goto V_65;
}
F_71 ( V_11 -> clock [ V_157 ] ) ;
}
if ( V_11 -> V_54 & V_66 )
F_27 ( V_11 ) ;
V_11 -> V_54 &= ~ V_63 ;
V_65:
F_38 ( & V_11 -> V_62 ) ;
return V_46 ? - V_158 : 0 ;
}
static int F_88 ( struct V_43 * V_44 )
{
return F_81 ( V_44 , false ) ;
}
static int F_89 ( struct V_43 * V_44 )
{
return F_86 ( V_44 , false ) ;
}
static int F_90 ( struct V_43 * V_44 )
{
return F_81 ( V_44 , true ) ;
}
static int F_91 ( struct V_43 * V_44 )
{
return F_86 ( V_44 , true ) ;
}
static int F_92 ( struct V_107 * V_45 )
{
struct V_2 * V_4 = F_83 ( V_45 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_93 ( & V_45 -> V_44 ) ;
F_81 ( & V_45 -> V_44 , false ) ;
F_80 ( V_11 -> clock [ V_141 ] ) ;
F_94 ( & V_45 -> V_44 ) ;
F_15 ( V_11 ) ;
F_95 ( & V_11 -> V_4 . V_153 ) ;
return 0 ;
}
