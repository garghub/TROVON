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
if ( V_12 )
V_13 |= V_11 -> V_15 ;
else
V_13 &= ~ V_11 -> V_15 ;
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
struct V_67 * V_53 ,
struct V_68 * V_10 )
{
if ( V_10 -> V_69 >= F_4 ( V_9 ) )
return - V_42 ;
V_10 -> V_10 = V_9 [ V_10 -> V_69 ] . V_10 ;
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
F_42 ( & V_7 -> V_25 , 1 , V_70 ,
V_29 -> V_71 ,
& V_7 -> V_26 , 1 , V_72 , 1 ,
0 ) ;
return V_29 ;
}
static struct V_6 * F_43 (
struct V_1 * V_11 , struct V_67 * V_53 ,
enum V_73 V_74 )
{
if ( V_74 == V_75 )
return V_53 ? F_44 ( & V_11 -> V_4 , V_53 , 0 ) : NULL ;
return & V_11 -> V_23 ;
}
static int F_45 ( struct V_2 * V_4 , struct V_67 * V_53 ,
struct V_76 * V_77 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_5 const * V_29 ;
struct V_6 * V_7 ;
V_7 = F_43 ( V_11 , V_53 , V_77 -> V_74 ) ;
if ( V_77 -> V_78 == V_79 ) {
if ( V_7 ) {
F_37 ( & V_11 -> V_62 ) ;
V_77 -> V_23 = * V_7 ;
F_38 ( & V_11 -> V_62 ) ;
}
return 0 ;
}
V_29 = F_41 ( & V_77 -> V_23 ) ;
if ( V_7 ) {
F_37 ( & V_11 -> V_62 ) ;
* V_7 = V_77 -> V_23 ;
if ( V_77 -> V_74 == V_80 )
V_11 -> V_29 = V_29 ;
F_38 ( & V_11 -> V_62 ) ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_4 , struct V_67 * V_53 ,
struct V_76 * V_77 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_6 * V_7 ;
V_7 = F_43 ( V_11 , V_53 , V_77 -> V_74 ) ;
if ( ! V_7 )
return - V_42 ;
F_37 ( & V_11 -> V_62 ) ;
V_77 -> V_23 = * V_7 ;
F_38 ( & V_11 -> V_62 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_4 , void * V_81 ,
unsigned int * V_82 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_54 ;
* V_82 = F_48 (unsigned int, *size, S5PCSIS_PKTDATA_SIZE) ;
F_30 ( & V_11 -> V_55 , V_54 ) ;
V_11 -> V_83 . V_84 = V_81 ;
V_11 -> V_83 . V_85 = * V_82 ;
F_31 ( & V_11 -> V_55 , V_54 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_37 ( & V_11 -> V_62 ) ;
F_32 ( V_11 , true ) ;
if ( V_24 && ( V_11 -> V_54 & V_86 ) )
F_25 ( V_11 , V_61 ) ;
F_38 ( & V_11 -> V_62 ) ;
return 0 ;
}
static T_2 F_50 ( int V_87 , void * V_88 )
{
struct V_1 * V_11 = V_88 ;
struct V_89 * V_90 = & V_11 -> V_83 ;
unsigned long V_54 ;
T_1 V_91 ;
V_91 = F_6 ( V_11 , V_92 ) ;
F_30 ( & V_11 -> V_55 , V_54 ) ;
if ( ( V_91 & V_93 ) && V_90 -> V_84 ) {
T_1 V_50 ;
if ( V_91 & V_94 )
V_50 = V_95 ;
else
V_50 = V_96 ;
memcpy ( V_90 -> V_84 , ( V_97 V_98 * ) V_11 -> V_99 + V_50 ,
V_90 -> V_85 ) ;
V_90 -> V_84 = NULL ;
F_51 () ;
}
if ( ( V_91 & V_100 ) || V_24 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_56 ; V_8 ++ ) {
if ( ! ( V_91 & V_11 -> V_57 [ V_8 ] . V_18 ) )
continue;
V_11 -> V_57 [ V_8 ] . V_58 ++ ;
F_12 ( 2 , V_24 , & V_11 -> V_4 , L_14 ,
V_11 -> V_57 [ V_8 ] . V_51 ,
V_11 -> V_57 [ V_8 ] . V_58 ) ;
}
F_12 ( 2 , V_24 , & V_11 -> V_4 , L_15 , V_91 ) ;
}
F_31 ( & V_11 -> V_55 , V_54 ) ;
F_7 ( V_11 , V_92 , V_91 ) ;
return V_101 ;
}
static int F_52 ( struct V_102 * V_45 ,
struct V_1 * V_11 )
{
struct V_103 * V_104 = V_45 -> V_44 . V_105 ;
struct V_106 V_107 ;
int V_46 ;
if ( F_53 ( V_104 , L_16 ,
& V_11 -> V_108 ) )
V_11 -> V_108 = V_109 ;
if ( F_53 ( V_104 , L_17 ,
& V_11 -> V_110 ) )
return - V_42 ;
V_104 = F_54 ( V_104 , NULL ) ;
if ( ! V_104 ) {
F_24 ( & V_45 -> V_44 , L_18 ,
V_45 -> V_44 . V_105 -> V_111 ) ;
return - V_42 ;
}
V_46 = F_55 ( F_56 ( V_104 ) , & V_107 ) ;
if ( V_46 )
goto V_48;
V_11 -> V_69 = V_107 . V_112 . V_113 - V_114 ;
if ( V_11 -> V_69 >= V_115 ) {
V_46 = - V_116 ;
goto V_48;
}
F_53 ( V_104 , L_19 ,
& V_11 -> V_35 ) ;
V_11 -> V_39 = F_57 ( V_104 ,
L_20 ) ;
V_11 -> V_22 = V_107 . V_117 . V_118 . V_119 ;
V_48:
F_58 ( V_104 ) ;
return V_46 ;
}
static int F_59 ( struct V_102 * V_45 )
{
const struct V_120 * V_121 ;
const struct V_122 * V_123 ;
struct V_43 * V_44 = & V_45 -> V_44 ;
struct V_124 * V_125 ;
struct V_1 * V_11 ;
int V_46 = - V_126 ;
int V_8 ;
V_11 = F_60 ( V_44 , sizeof( * V_11 ) , V_127 ) ;
if ( ! V_11 )
return - V_126 ;
F_61 ( & V_11 -> V_62 ) ;
F_62 ( & V_11 -> V_55 ) ;
V_11 -> V_45 = V_45 ;
V_121 = F_63 ( V_128 , V_44 -> V_105 ) ;
if ( F_64 ( V_121 == NULL ) )
return - V_42 ;
V_123 = V_121 -> V_84 ;
V_11 -> V_15 = V_123 -> V_15 ;
V_46 = F_52 ( V_45 , V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_11 -> V_22 == 0 || V_11 -> V_22 > V_11 -> V_110 ) {
F_24 ( V_44 , L_21 ,
V_11 -> V_22 , V_11 -> V_110 ) ;
return - V_42 ;
}
V_11 -> V_129 = F_65 ( V_44 , L_22 ) ;
if ( F_16 ( V_11 -> V_129 ) )
return F_22 ( V_11 -> V_129 ) ;
V_125 = F_66 ( V_45 , V_130 , 0 ) ;
V_11 -> V_99 = F_67 ( V_44 , V_125 ) ;
if ( F_16 ( V_11 -> V_99 ) )
return F_22 ( V_11 -> V_99 ) ;
V_11 -> V_87 = F_68 ( V_45 , 0 ) ;
if ( V_11 -> V_87 < 0 ) {
F_24 ( V_44 , L_23 ) ;
return V_11 -> V_87 ;
}
for ( V_8 = 0 ; V_8 < V_131 ; V_8 ++ )
V_11 -> V_132 [ V_8 ] . V_133 = V_134 [ V_8 ] ;
V_46 = F_69 ( V_44 , V_131 ,
V_11 -> V_132 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_20 ( V_11 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_11 -> V_108 )
V_46 = F_70 ( V_11 -> clock [ V_135 ] ,
V_11 -> V_108 ) ;
else
F_71 ( V_44 , L_24 ) ;
if ( V_46 < 0 )
goto V_136;
V_46 = F_72 ( V_11 -> clock [ V_135 ] ) ;
if ( V_46 < 0 )
goto V_136;
V_46 = F_73 ( V_44 , V_11 -> V_87 , F_50 ,
0 , F_74 ( V_44 ) , V_11 ) ;
if ( V_46 ) {
F_24 ( V_44 , L_25 ) ;
goto V_137;
}
F_75 ( & V_11 -> V_4 , & V_138 ) ;
V_11 -> V_4 . V_139 = V_140 ;
snprintf ( V_11 -> V_4 . V_51 , sizeof( V_11 -> V_4 . V_51 ) , L_26 ,
V_141 , V_11 -> V_69 ) ;
V_11 -> V_4 . V_54 |= V_142 ;
V_11 -> V_29 = & V_9 [ 0 ] ;
V_11 -> V_23 . V_10 = V_9 [ 0 ] . V_10 ;
V_11 -> V_23 . V_25 = V_143 ;
V_11 -> V_23 . V_26 = V_144 ;
V_11 -> V_4 . V_145 . V_146 = V_147 ;
V_11 -> V_148 [ V_149 ] . V_54 = V_150 ;
V_11 -> V_148 [ V_79 ] . V_54 = V_151 ;
V_46 = F_76 ( & V_11 -> V_4 . V_145 ,
V_152 , V_11 -> V_148 ) ;
if ( V_46 < 0 )
goto V_137;
F_77 ( & V_11 -> V_4 , V_45 ) ;
F_78 ( V_45 , & V_11 -> V_4 ) ;
memcpy ( V_11 -> V_57 , V_153 , sizeof( V_11 -> V_57 ) ) ;
F_79 ( V_44 ) ;
if ( ! F_80 ( V_44 ) ) {
V_46 = F_81 ( V_44 , true ) ;
if ( V_46 < 0 )
goto V_154;
}
F_82 ( & V_45 -> V_44 , L_27 ,
V_11 -> V_22 , V_11 -> V_35 , V_11 -> V_39 ,
V_11 -> V_108 ) ;
return 0 ;
V_154:
F_83 ( & V_11 -> V_4 . V_145 ) ;
V_137:
F_84 ( V_11 -> clock [ V_135 ] ) ;
V_136:
F_15 ( V_11 ) ;
return V_46 ;
}
static int F_85 ( struct V_43 * V_44 , bool V_155 )
{
struct V_102 * V_45 = F_86 ( V_44 ) ;
struct V_2 * V_4 = F_87 ( V_45 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_24 , V_4 , L_28 ,
V_61 , V_11 -> V_54 ) ;
F_37 ( & V_11 -> V_62 ) ;
if ( V_11 -> V_54 & V_86 ) {
F_28 ( V_11 ) ;
V_46 = F_88 ( V_11 -> V_129 ) ;
if ( V_46 )
goto V_65;
V_46 = F_89 ( V_131 ,
V_11 -> V_132 ) ;
if ( V_46 )
goto V_65;
F_84 ( V_11 -> clock [ V_156 ] ) ;
V_11 -> V_54 &= ~ V_86 ;
if ( ! V_155 )
V_11 -> V_54 |= V_63 ;
}
V_65:
F_38 ( & V_11 -> V_62 ) ;
return V_46 ? - V_157 : 0 ;
}
static int F_81 ( struct V_43 * V_44 , bool V_155 )
{
struct V_102 * V_45 = F_86 ( V_44 ) ;
struct V_2 * V_4 = F_87 ( V_45 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_24 , V_4 , L_28 ,
V_61 , V_11 -> V_54 ) ;
F_37 ( & V_11 -> V_62 ) ;
if ( ! V_155 && ! ( V_11 -> V_54 & V_63 ) )
goto V_65;
if ( ! ( V_11 -> V_54 & V_86 ) ) {
V_46 = F_90 ( V_131 ,
V_11 -> V_132 ) ;
if ( V_46 )
goto V_65;
V_46 = F_91 ( V_11 -> V_129 ) ;
if ( ! V_46 ) {
V_11 -> V_54 |= V_86 ;
} else {
F_89 ( V_131 ,
V_11 -> V_132 ) ;
goto V_65;
}
F_72 ( V_11 -> clock [ V_156 ] ) ;
}
if ( V_11 -> V_54 & V_66 )
F_27 ( V_11 ) ;
V_11 -> V_54 &= ~ V_63 ;
V_65:
F_38 ( & V_11 -> V_62 ) ;
return V_46 ? - V_157 : 0 ;
}
static int F_92 ( struct V_43 * V_44 )
{
return F_85 ( V_44 , false ) ;
}
static int F_93 ( struct V_43 * V_44 )
{
return F_81 ( V_44 , false ) ;
}
static int F_94 ( struct V_43 * V_44 )
{
return F_85 ( V_44 , true ) ;
}
static int F_95 ( struct V_43 * V_44 )
{
return F_81 ( V_44 , true ) ;
}
static int F_96 ( struct V_102 * V_45 )
{
struct V_2 * V_4 = F_87 ( V_45 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_97 ( & V_45 -> V_44 ) ;
F_85 ( & V_45 -> V_44 , true ) ;
F_84 ( V_11 -> clock [ V_135 ] ) ;
F_98 ( & V_45 -> V_44 ) ;
F_15 ( V_11 ) ;
F_83 ( & V_11 -> V_4 . V_145 ) ;
return 0 ;
}
