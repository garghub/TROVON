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
struct V_18 * V_19 = V_11 -> V_20 -> V_21 . V_22 ;
T_1 V_13 , V_23 ;
V_13 = F_6 ( V_11 , V_16 ) ;
if ( V_12 )
V_13 |= V_24 ;
else
V_13 &= ~ V_24 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_25 ) ;
V_13 &= ~ V_26 ;
if ( V_12 ) {
V_23 = ( 1 << ( V_19 -> V_27 + 1 ) ) - 1 ;
V_13 |= ( V_23 & V_26 ) ;
}
F_7 ( V_11 , V_25 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_28 ;
T_1 V_13 ;
F_12 ( 1 , V_29 , & V_11 -> V_4 , L_1 ,
V_7 -> V_10 , V_7 -> V_30 , V_7 -> V_31 ) ;
V_13 = F_6 ( V_11 , V_32 ) ;
V_13 = ( V_13 & ~ V_33 ) | V_11 -> V_34 -> V_35 ;
F_7 ( V_11 , V_32 , V_13 ) ;
V_13 = ( V_7 -> V_30 << 16 ) | V_7 -> V_31 ;
F_7 ( V_11 , V_36 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_11 , int V_37 )
{
T_1 V_13 = F_6 ( V_11 , V_25 ) ;
V_13 = ( V_13 & ~ V_38 ) | ( V_37 << 27 ) ;
F_7 ( V_11 , V_25 , V_13 ) ;
}
static void F_14 ( struct V_1 * V_11 )
{
struct V_18 * V_19 = V_11 -> V_20 -> V_21 . V_22 ;
T_1 V_13 ;
V_13 = F_6 ( V_11 , V_32 ) ;
V_13 = ( V_13 & ~ V_39 ) | ( V_19 -> V_27 - 1 ) ;
F_7 ( V_11 , V_32 , V_13 ) ;
F_11 ( V_11 ) ;
F_13 ( V_11 , V_19 -> V_40 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
if ( V_11 -> V_34 -> V_41 == 32 )
V_13 |= V_42 ;
else
V_13 &= ~ V_42 ;
V_13 &= ~ V_43 ;
if ( V_19 -> V_44 )
V_13 |= V_43 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
F_7 ( V_11 , V_16 , V_13 | V_45 ) ;
}
static void F_15 ( struct V_1 * V_11 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
if ( F_16 ( V_11 -> clock [ V_8 ] ) )
continue;
F_17 ( V_11 -> clock [ V_8 ] ) ;
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = F_19 ( - V_47 ) ;
}
}
static int F_20 ( struct V_1 * V_11 )
{
struct V_48 * V_21 = & V_11 -> V_20 -> V_21 ;
int V_8 , V_49 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ )
V_11 -> clock [ V_8 ] = F_19 ( - V_47 ) ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
V_11 -> clock [ V_8 ] = F_21 ( V_21 , V_50 [ V_8 ] ) ;
if ( F_16 ( V_11 -> clock [ V_8 ] ) ) {
V_49 = F_22 ( V_11 -> clock [ V_8 ] ) ;
goto V_51;
}
V_49 = F_23 ( V_11 -> clock [ V_8 ] ) ;
if ( V_49 < 0 ) {
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = F_19 ( - V_47 ) ;
goto V_51;
}
}
return 0 ;
V_51:
F_15 ( V_11 ) ;
F_24 ( V_21 , L_2 , V_50 [ V_8 ] ) ;
return V_49 ;
}
static void F_25 ( struct V_1 * V_11 , const char * V_52 )
{
struct {
T_1 V_53 ;
const char * const V_54 ;
} V_55 [] = {
{ 0x00 , L_3 } ,
{ 0x04 , L_4 } ,
{ 0x08 , L_5 } ,
{ 0x0c , L_6 } ,
{ 0x10 , L_7 } ,
{ 0x2c , L_8 } ,
{ 0x38 , L_9 } ,
} ;
T_1 V_8 ;
F_26 ( & V_11 -> V_4 , L_10 , V_52 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_55 ) ; V_8 ++ ) {
T_1 V_56 = F_6 ( V_11 , V_55 [ V_8 ] . V_53 ) ;
F_26 ( & V_11 -> V_4 , L_11 , V_55 [ V_8 ] . V_54 , V_56 ) ;
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
unsigned long V_57 ;
int V_8 ;
F_30 ( & V_11 -> V_58 , V_57 ) ;
for ( V_8 = 0 ; V_8 < V_59 ; V_8 ++ )
V_11 -> V_60 [ V_8 ] . V_61 = 0 ;
F_31 ( & V_11 -> V_58 , V_57 ) ;
}
static void F_32 ( struct V_1 * V_11 , bool V_62 )
{
int V_8 = V_62 ? V_59 : V_59 - 4 ;
unsigned long V_57 ;
F_30 ( & V_11 -> V_58 , V_57 ) ;
for ( V_8 -- ; V_8 >= 0 ; V_8 -- ) {
if ( V_11 -> V_60 [ V_8 ] . V_61 > 0 || V_29 )
F_26 ( & V_11 -> V_4 , L_12 ,
V_11 -> V_60 [ V_8 ] . V_54 ,
V_11 -> V_60 [ V_8 ] . V_61 ) ;
}
F_31 ( & V_11 -> V_58 , V_57 ) ;
}
static int F_33 ( struct V_2 * V_4 , int V_12 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_48 * V_21 = & V_11 -> V_20 -> V_21 ;
if ( V_12 )
return F_34 ( V_21 ) ;
return F_35 ( V_21 ) ;
}
static int F_36 ( struct V_2 * V_4 , int V_63 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_49 = 0 ;
F_12 ( 1 , V_29 , V_4 , L_13 ,
V_64 , V_63 , V_11 -> V_57 ) ;
if ( V_63 ) {
F_29 ( V_11 ) ;
V_49 = F_34 ( & V_11 -> V_20 -> V_21 ) ;
if ( V_49 && V_49 != 1 )
return V_49 ;
}
F_37 ( & V_11 -> V_65 ) ;
if ( V_63 ) {
if ( V_11 -> V_57 & V_66 ) {
V_49 = - V_67 ;
goto V_68;
}
F_27 ( V_11 ) ;
V_11 -> V_57 |= V_69 ;
} else {
F_28 ( V_11 ) ;
V_11 -> V_57 &= ~ V_69 ;
if ( V_29 > 0 )
F_32 ( V_11 , true ) ;
}
V_68:
F_38 ( & V_11 -> V_65 ) ;
if ( ! V_63 )
F_39 ( & V_11 -> V_20 -> V_21 ) ;
return V_49 == 1 ? 0 : V_49 ;
}
static int F_40 ( struct V_2 * V_4 ,
struct V_70 * V_71 ,
struct V_72 * V_10 )
{
if ( V_10 -> V_73 >= F_4 ( V_9 ) )
return - V_47 ;
V_10 -> V_10 = V_9 [ V_10 -> V_73 ] . V_10 ;
return 0 ;
}
static struct V_5 const * F_41 (
struct V_6 * V_7 )
{
struct V_5 const * V_34 ;
V_34 = F_3 ( V_7 ) ;
if ( V_34 == NULL )
V_34 = & V_9 [ 0 ] ;
V_7 -> V_10 = V_34 -> V_10 ;
F_42 ( & V_7 -> V_30 , 1 , V_74 ,
V_34 -> V_75 ,
& V_7 -> V_31 , 1 , V_76 , 1 ,
0 ) ;
return V_34 ;
}
static struct V_6 * F_43 (
struct V_1 * V_11 , struct V_70 * V_71 ,
T_1 V_77 , enum V_78 V_79 )
{
if ( V_79 == V_80 )
return V_71 ? F_44 ( V_71 , V_77 ) : NULL ;
return & V_11 -> V_28 ;
}
static int F_45 ( struct V_2 * V_4 , struct V_70 * V_71 ,
struct V_81 * V_82 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_5 const * V_34 ;
struct V_6 * V_7 ;
if ( V_82 -> V_77 != V_83 && V_82 -> V_77 != V_84 )
return - V_47 ;
V_7 = F_43 ( V_11 , V_71 , V_82 -> V_77 , V_82 -> V_79 ) ;
if ( V_82 -> V_77 == V_83 ) {
if ( V_7 ) {
F_37 ( & V_11 -> V_65 ) ;
V_82 -> V_28 = * V_7 ;
F_38 ( & V_11 -> V_65 ) ;
}
return 0 ;
}
V_34 = F_41 ( & V_82 -> V_28 ) ;
if ( V_7 ) {
F_37 ( & V_11 -> V_65 ) ;
* V_7 = V_82 -> V_28 ;
if ( V_82 -> V_79 == V_85 )
V_11 -> V_34 = V_34 ;
F_38 ( & V_11 -> V_65 ) ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_4 , struct V_70 * V_71 ,
struct V_81 * V_82 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_6 * V_7 ;
if ( V_82 -> V_77 != V_83 && V_82 -> V_77 != V_84 )
return - V_47 ;
V_7 = F_43 ( V_11 , V_71 , V_82 -> V_77 , V_82 -> V_79 ) ;
if ( ! V_7 )
return - V_47 ;
F_37 ( & V_11 -> V_65 ) ;
V_82 -> V_28 = * V_7 ;
F_38 ( & V_11 -> V_65 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_4 , void * V_86 ,
unsigned int * V_87 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_57 ;
* V_87 = F_48 (unsigned int, *size, S5PCSIS_PKTDATA_SIZE) ;
F_30 ( & V_11 -> V_58 , V_57 ) ;
V_11 -> V_88 . V_89 = V_86 ;
V_11 -> V_88 . V_90 = * V_87 ;
F_31 ( & V_11 -> V_58 , V_57 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_37 ( & V_11 -> V_65 ) ;
F_32 ( V_11 , true ) ;
if ( V_29 && ( V_11 -> V_57 & V_91 ) )
F_25 ( V_11 , V_64 ) ;
F_38 ( & V_11 -> V_65 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_4 , struct V_70 * V_71 )
{
struct V_6 * V_28 = F_44 ( V_71 , 0 ) ;
V_28 -> V_92 = V_93 ;
V_28 -> V_10 = V_9 [ 0 ] . V_10 ;
V_28 -> V_30 = V_94 ;
V_28 -> V_31 = V_95 ;
V_28 -> V_96 = V_97 ;
return 0 ;
}
static T_2 F_51 ( int V_98 , void * V_99 )
{
struct V_1 * V_11 = V_99 ;
struct V_100 * V_101 = & V_11 -> V_88 ;
unsigned long V_57 ;
T_1 V_102 ;
V_102 = F_6 ( V_11 , V_103 ) ;
F_30 ( & V_11 -> V_58 , V_57 ) ;
if ( ( V_102 & V_104 ) && V_101 -> V_89 ) {
T_1 V_53 ;
if ( V_102 & V_105 )
V_53 = V_106 ;
else
V_53 = V_107 ;
memcpy ( V_101 -> V_89 , V_11 -> V_108 + V_53 , V_101 -> V_90 ) ;
V_101 -> V_89 = NULL ;
F_52 () ;
}
if ( ( V_102 & V_109 ) || V_29 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_59 ; V_8 ++ ) {
if ( ! ( V_102 & V_11 -> V_60 [ V_8 ] . V_23 ) )
continue;
V_11 -> V_60 [ V_8 ] . V_61 ++ ;
F_12 ( 2 , V_29 , & V_11 -> V_4 , L_14 ,
V_11 -> V_60 [ V_8 ] . V_54 ,
V_11 -> V_60 [ V_8 ] . V_61 ) ;
}
F_12 ( 2 , V_29 , & V_11 -> V_4 , L_15 , V_102 ) ;
}
F_31 ( & V_11 -> V_58 , V_57 ) ;
F_7 ( V_11 , V_103 , V_102 ) ;
return V_110 ;
}
static int F_53 ( struct V_111 * V_20 )
{
struct V_18 * V_19 ;
struct V_112 * V_113 ;
struct V_1 * V_11 ;
int V_49 = - V_114 ;
int V_8 ;
V_11 = F_54 ( & V_20 -> V_21 , sizeof( * V_11 ) , V_115 ) ;
if ( ! V_11 )
return - V_114 ;
F_55 ( & V_11 -> V_65 ) ;
F_56 ( & V_11 -> V_58 ) ;
V_11 -> V_20 = V_20 ;
V_11 -> V_73 = F_57 ( 0 , V_20 -> V_116 ) ;
V_19 = V_20 -> V_21 . V_22 ;
if ( V_19 == NULL ) {
F_24 ( & V_20 -> V_21 , L_16 ) ;
return - V_47 ;
}
if ( ( V_11 -> V_73 == 1 && V_19 -> V_27 > V_117 ) ||
V_19 -> V_27 > V_118 ) {
F_24 ( & V_20 -> V_21 , L_17 ,
V_19 -> V_27 ) ;
return - V_47 ;
}
V_113 = F_58 ( V_20 , V_119 , 0 ) ;
V_11 -> V_108 = F_59 ( & V_20 -> V_21 , V_113 ) ;
if ( F_16 ( V_11 -> V_108 ) )
return F_22 ( V_11 -> V_108 ) ;
V_11 -> V_98 = F_60 ( V_20 , 0 ) ;
if ( V_11 -> V_98 < 0 ) {
F_24 ( & V_20 -> V_21 , L_18 ) ;
return V_11 -> V_98 ;
}
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ )
V_11 -> V_121 [ V_8 ] . V_122 = V_123 [ V_8 ] ;
V_49 = F_61 ( & V_20 -> V_21 , V_120 ,
V_11 -> V_121 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_20 ( V_11 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_19 -> V_124 )
V_49 = F_62 ( V_11 -> clock [ V_125 ] ,
V_19 -> V_124 ) ;
else
F_63 ( & V_20 -> V_21 , L_19 ) ;
if ( V_49 < 0 )
goto V_126;
V_49 = F_64 ( V_11 -> clock [ V_125 ] ) ;
if ( V_49 < 0 )
goto V_126;
V_49 = F_65 ( & V_20 -> V_21 , V_11 -> V_98 , F_51 ,
0 , F_66 ( & V_20 -> V_21 ) , V_11 ) ;
if ( V_49 ) {
F_24 ( & V_20 -> V_21 , L_20 ) ;
goto V_127;
}
F_67 ( & V_11 -> V_4 , & V_128 ) ;
V_11 -> V_4 . V_129 = V_130 ;
F_68 ( V_11 -> V_4 . V_54 , F_66 ( & V_20 -> V_21 ) , sizeof( V_11 -> V_4 . V_54 ) ) ;
V_11 -> V_4 . V_57 |= V_131 ;
V_11 -> V_34 = & V_9 [ 0 ] ;
V_11 -> V_28 . V_10 = V_9 [ 0 ] . V_10 ;
V_11 -> V_28 . V_30 = V_94 ;
V_11 -> V_28 . V_31 = V_95 ;
V_11 -> V_132 [ V_84 ] . V_57 = V_133 ;
V_11 -> V_132 [ V_83 ] . V_57 = V_134 ;
V_49 = F_69 ( & V_11 -> V_4 . V_135 ,
V_136 , V_11 -> V_132 , 0 ) ;
if ( V_49 < 0 )
goto V_127;
F_70 ( & V_11 -> V_4 , V_20 ) ;
F_71 ( V_20 , & V_11 -> V_4 ) ;
memcpy ( V_11 -> V_60 , V_137 , sizeof( V_11 -> V_60 ) ) ;
F_72 ( & V_20 -> V_21 ) ;
return 0 ;
V_127:
F_73 ( V_11 -> clock [ V_125 ] ) ;
V_126:
F_15 ( V_11 ) ;
return V_49 ;
}
static int F_74 ( struct V_48 * V_21 , bool V_138 )
{
struct V_111 * V_20 = F_75 ( V_21 ) ;
struct V_2 * V_4 = F_76 ( V_20 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_49 = 0 ;
F_12 ( 1 , V_29 , V_4 , L_21 ,
V_64 , V_11 -> V_57 ) ;
F_37 ( & V_11 -> V_65 ) ;
if ( V_11 -> V_57 & V_91 ) {
F_28 ( V_11 ) ;
V_49 = F_77 ( V_11 -> V_73 , false ) ;
if ( V_49 )
goto V_68;
V_49 = F_78 ( V_120 ,
V_11 -> V_121 ) ;
if ( V_49 )
goto V_68;
F_73 ( V_11 -> clock [ V_139 ] ) ;
V_11 -> V_57 &= ~ V_91 ;
if ( ! V_138 )
V_11 -> V_57 |= V_66 ;
}
V_68:
F_38 ( & V_11 -> V_65 ) ;
return V_49 ? - V_140 : 0 ;
}
static int F_79 ( struct V_48 * V_21 , bool V_138 )
{
struct V_111 * V_20 = F_75 ( V_21 ) ;
struct V_2 * V_4 = F_76 ( V_20 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_49 = 0 ;
F_12 ( 1 , V_29 , V_4 , L_21 ,
V_64 , V_11 -> V_57 ) ;
F_37 ( & V_11 -> V_65 ) ;
if ( ! V_138 && ! ( V_11 -> V_57 & V_66 ) )
goto V_68;
if ( ! ( V_11 -> V_57 & V_91 ) ) {
V_49 = F_80 ( V_120 ,
V_11 -> V_121 ) ;
if ( V_49 )
goto V_68;
V_49 = F_77 ( V_11 -> V_73 , true ) ;
if ( ! V_49 ) {
V_11 -> V_57 |= V_91 ;
} else {
F_78 ( V_120 ,
V_11 -> V_121 ) ;
goto V_68;
}
F_64 ( V_11 -> clock [ V_139 ] ) ;
}
if ( V_11 -> V_57 & V_69 )
F_27 ( V_11 ) ;
V_11 -> V_57 &= ~ V_66 ;
V_68:
F_38 ( & V_11 -> V_65 ) ;
return V_49 ? - V_140 : 0 ;
}
static int F_81 ( struct V_48 * V_21 )
{
return F_74 ( V_21 , false ) ;
}
static int F_82 ( struct V_48 * V_21 )
{
return F_79 ( V_21 , false ) ;
}
static int F_83 ( struct V_48 * V_21 )
{
return F_74 ( V_21 , true ) ;
}
static int F_84 ( struct V_48 * V_21 )
{
return F_79 ( V_21 , true ) ;
}
static int F_85 ( struct V_111 * V_20 )
{
struct V_2 * V_4 = F_76 ( V_20 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_86 ( & V_20 -> V_21 ) ;
F_74 ( & V_20 -> V_21 , false ) ;
F_73 ( V_11 -> clock [ V_125 ] ) ;
F_87 ( & V_20 -> V_21 ) ;
F_15 ( V_11 ) ;
F_88 ( & V_11 -> V_4 . V_135 ) ;
return 0 ;
}
