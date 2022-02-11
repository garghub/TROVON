static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 , const unsigned * * V_9 , unsigned * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , struct V_13 * * V_14 ,
unsigned * V_15 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_13 * V_18 ;
unsigned long * V_19 = NULL ;
char * V_20 , * V_21 ;
int V_22 = 0 , V_23 = 0 , V_24 = 0 ;
for ( V_24 = 0 ; V_24 < F_6 ( V_25 ) ; V_24 ++ )
if ( F_7 ( V_12 , V_25 [ V_24 ] . V_26 , NULL ) )
V_22 ++ ;
if ( V_22 )
V_23 = 1 ;
if ( F_7 ( V_12 , L_1 , NULL ) )
V_23 ++ ;
if ( ! V_23 ) {
F_8 ( V_17 , L_2
L_3 , V_12 -> V_8 ) ;
return - V_27 ;
}
V_18 = F_9 ( sizeof( * V_18 ) * V_23 , V_28 ) ;
if ( ! V_18 )
return - V_29 ;
* V_15 = 0 ;
V_20 = F_10 ( V_28 , L_4 , V_12 -> V_8 , V_30 ) ;
if ( ! V_20 )
goto V_31;
if ( ! V_22 )
goto V_32;
V_19 = F_9 ( sizeof( * V_19 ) * V_22 , V_28 ) ;
if ( ! V_19 )
goto V_33;
for ( V_24 = 0 , V_22 = 0 ; V_24 < F_6 ( V_25 ) ; V_24 ++ ) {
T_1 V_34 ;
if ( ! F_11 ( V_12 , V_25 [ V_24 ] . V_26 , & V_34 ) )
V_19 [ V_22 ++ ] =
F_12 ( V_25 [ V_24 ] . V_35 , V_34 ) ;
}
V_18 [ * V_15 ] . V_36 . V_37 . V_38 = V_20 ;
V_18 [ * V_15 ] . V_36 . V_37 . V_37 = V_19 ;
V_18 [ * V_15 ] . V_36 . V_37 . V_39 = V_22 ;
V_18 [ * V_15 ] . type = V_40 ;
* V_15 += 1 ;
V_32:
if ( F_7 ( V_12 , L_1 , NULL ) ) {
V_21 = F_10 ( V_28 ,
L_4 , V_12 -> V_8 , V_41 ) ;
if ( ! V_21 )
goto V_42;
V_18 [ * V_15 ] . V_36 . V_43 . V_44 = V_20 ;
V_18 [ * V_15 ] . V_36 . V_43 . V_45 = V_21 ;
V_18 [ * V_15 ] . type = V_46 ;
* V_15 += 1 ;
}
* V_14 = V_18 ;
return 0 ;
V_42:
F_13 ( V_19 ) ;
V_33:
F_13 ( V_20 ) ;
V_31:
F_13 ( V_18 ) ;
return - V_29 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_13 * V_18 , unsigned V_47 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_47 ; V_24 ++ ) {
if ( V_18 [ V_24 ] . type == V_46 ) {
F_13 ( V_18 [ V_24 ] . V_36 . V_43 . V_45 ) ;
if ( ! V_24 )
F_13 ( V_18 [ V_24 ] . V_36 . V_43 . V_44 ) ;
} else if ( V_18 -> type == V_40 ) {
F_13 ( V_18 [ V_24 ] . V_36 . V_37 . V_37 ) ;
if ( ! V_24 )
F_13 ( V_18 [ V_24 ] . V_36 . V_37 . V_38 ) ;
}
} ;
F_13 ( V_18 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_48 ;
}
static const char * F_16 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_49 [ V_6 ] . V_8 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_6 , const char * const * * V_50 ,
unsigned * const V_51 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
* V_50 = V_4 -> V_49 [ V_6 ] . V_50 ;
* V_51 = V_4 -> V_49 [ V_6 ] . V_51 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_44 , bool V_52 )
{
struct V_3 * V_4 ;
void T_2 * V_53 ;
T_1 V_45 ;
T_1 V_36 ;
V_4 = F_2 ( V_2 ) ;
V_53 = V_4 -> V_54 ;
V_45 = V_4 -> V_49 [ V_6 ] . V_45 ;
V_36 = F_19 ( V_53 + V_55 ) ;
if ( V_52 )
V_36 |= ( 1 << V_45 ) ;
else
V_36 &= ~ ( 1 << V_45 ) ;
F_20 ( V_36 , V_53 + V_55 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned V_6 ,
unsigned V_44 )
{
F_18 ( V_2 , V_6 , V_44 , true ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_56 * V_57 , unsigned V_58 , bool V_59 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_60 ,
unsigned long * V_37 ,
unsigned V_39 )
{
struct V_3 * V_4 ;
void T_2 * V_53 ;
enum V_61 V_35 ;
T_1 V_62 ;
T_1 V_36 ;
int V_63 ;
V_4 = F_2 ( V_2 ) ;
V_53 = V_4 -> V_54 ;
for ( V_63 = 0 ; V_63 < V_39 ; V_63 ++ ) {
V_35 = F_24 ( V_37 [ V_63 ] ) ;
V_62 = F_25 ( V_37 [ V_63 ] ) ;
switch ( V_35 ) {
case V_64 :
V_36 = F_19 ( V_53 + V_65 ) ;
V_36 &= ~ ( 1 << V_60 ) ;
if ( V_62 )
V_36 |= ( 1 << V_60 ) ;
F_20 ( V_36 , V_53 + V_65 ) ;
V_36 = F_19 ( V_53 + V_66 ) ;
V_36 &= ~ ( 1 << V_60 ) ;
if ( V_62 == 2 )
V_36 |= ( 1 << V_60 ) ;
F_20 ( V_36 , V_53 + V_66 ) ;
break;
case V_67 :
V_36 = F_19 ( V_53 + V_68 ) ;
V_36 &= ~ ( 1 << V_60 ) ;
V_36 |= ( ( V_62 & 1 ) << V_60 ) ;
F_20 ( V_36 , V_53 + V_68 ) ;
V_62 >>= 1 ;
V_36 = F_19 ( V_53 + V_69 ) ;
V_36 &= ~ ( 1 << V_60 ) ;
V_36 |= ( ( V_62 & 1 ) << V_60 ) ;
F_20 ( V_36 , V_53 + V_69 ) ;
break;
case V_70 :
V_36 = F_19 ( V_53 + V_71 ) ;
V_36 &= ~ ( 1 << V_60 ) ;
V_36 |= ( ( V_62 & 1 ) << V_60 ) ;
F_20 ( V_36 , V_53 + V_71 ) ;
break;
case V_72 :
V_36 = F_19 ( V_53 + V_73 ) ;
V_36 &= ~ ( 1 << V_60 ) ;
V_36 |= ( ( V_62 & 1 ) << V_60 ) ;
F_20 ( V_36 , V_53 + V_73 ) ;
break;
default:
F_26 ( 1 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_60 ,
unsigned long * V_74 )
{
struct V_3 * V_4 ;
void T_2 * V_53 ;
enum V_61 V_35 = F_24 ( * V_74 ) ;
T_1 V_36 ;
V_4 = F_2 ( V_2 ) ;
V_53 = V_4 -> V_54 ;
switch ( V_35 ) {
case V_64 :
V_36 = F_19 ( V_53 + V_65 ) ;
V_36 = ( V_36 >> V_60 ) & 1 ;
if ( ! V_36 )
* V_74 = 0 ;
else
* V_74 = ( ( F_19 ( V_53 + V_66 ) >> V_60 ) & 1 ) + 1 ;
break;
case V_67 :
V_36 = F_19 ( V_53 + V_68 ) ;
V_36 = ( V_36 >> V_60 ) & 1 ;
* V_74 = V_36 ;
V_36 = F_19 ( V_53 + V_69 ) ;
V_36 = ( V_36 >> V_60 ) & 1 ;
* V_74 |= ( V_36 << 1 ) ;
break;
case V_70 :
V_36 = F_19 ( V_53 + V_71 ) ;
* V_74 = ( V_36 >> V_60 ) & 1 ;
break;
case V_72 :
V_36 = F_19 ( V_53 + V_73 ) ;
* V_74 = ( V_36 >> V_60 ) & 1 ;
break;
default:
F_26 ( 1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned V_44 , unsigned long * V_37 ,
unsigned V_39 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
unsigned int V_75 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_44 ] . V_9 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_7 [ V_44 ] . V_10 ; V_75 ++ )
F_23 ( V_2 , V_9 [ V_75 ] , V_37 ,
V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_44 , unsigned long * V_74 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_44 ] . V_9 ;
F_27 ( V_2 , V_9 [ 0 ] , V_74 ) ;
return 0 ;
}
static void F_30 ( struct V_76 * V_77 , unsigned V_58 , int V_34 )
{
struct V_3 * V_4 = F_31 ( V_77 -> V_17 ) ;
void T_2 * V_53 = V_4 -> V_54 ;
T_1 V_36 ;
V_36 = F_19 ( V_53 + V_78 ) ;
V_36 &= ~ ( 1 << V_58 ) ;
if ( V_34 )
V_36 |= 1 << V_58 ;
F_20 ( V_36 , V_53 + V_78 ) ;
}
static int F_32 ( struct V_76 * V_77 , unsigned V_58 )
{
struct V_3 * V_4 = F_31 ( V_77 -> V_17 ) ;
void T_2 * V_53 = V_4 -> V_54 ;
T_1 V_36 ;
V_36 = F_19 ( V_53 + V_79 ) ;
V_36 >>= V_58 ;
V_36 &= 1 ;
return V_36 ;
}
static int F_33 ( struct V_76 * V_77 , unsigned V_58 )
{
struct V_3 * V_4 = F_31 ( V_77 -> V_17 ) ;
void T_2 * V_53 = V_4 -> V_54 ;
T_1 V_36 ;
V_36 = F_19 ( V_53 + V_80 ) ;
V_36 &= ~ ( 1 << V_58 ) ;
F_20 ( V_36 , V_53 + V_80 ) ;
V_36 = F_19 ( V_53 + V_81 ) ;
V_36 |= 1 << V_58 ;
F_20 ( V_36 , V_53 + V_81 ) ;
return 0 ;
}
static int F_34 ( struct V_76 * V_77 , unsigned V_58 ,
int V_34 )
{
struct V_3 * V_4 = F_31 ( V_77 -> V_17 ) ;
void T_2 * V_53 = V_4 -> V_54 ;
T_1 V_36 ;
F_30 ( V_77 , V_58 , V_34 ) ;
V_36 = F_19 ( V_53 + V_81 ) ;
V_36 &= ~ ( 1 << V_58 ) ;
F_20 ( V_36 , V_53 + V_81 ) ;
V_36 = F_19 ( V_53 + V_80 ) ;
V_36 |= 1 << V_58 ;
F_20 ( V_36 , V_53 + V_80 ) ;
return 0 ;
}
static int F_35 ( struct V_76 * V_77 , unsigned V_58 )
{
struct V_3 * V_4 = F_31 ( V_77 -> V_17 ) ;
unsigned int V_82 ;
if ( V_58 < 16 || V_58 > 23 )
return - V_83 ;
if ( ! V_4 -> V_84 )
return - V_83 ;
V_82 = F_36 ( V_4 -> V_84 , V_58 - 16 ) ;
return V_82 ? : - V_83 ;
}
static int F_37 ( struct V_85 * V_86 ,
struct V_11 * V_87 , unsigned int * * V_88 ,
unsigned int * V_89 )
{
struct V_16 * V_17 = & V_86 -> V_17 ;
struct V_90 * V_91 ;
V_91 = F_7 ( V_87 , L_5 , NULL ) ;
if ( ! V_91 )
return - V_92 ;
* V_89 = V_91 -> V_93 / sizeof( unsigned long ) ;
if ( ! * V_89 ) {
F_8 ( V_17 , L_6 , V_87 -> V_8 ) ;
return - V_27 ;
}
* V_88 = F_38 ( V_17 , * V_89 * sizeof( * * V_88 ) , V_28 ) ;
if ( ! * V_88 )
return - V_29 ;
return F_39 ( V_87 , L_5 ,
* V_88 , * V_89 ) ;
}
static int F_40 ( struct V_85 * V_86 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_86 -> V_17 ;
struct V_11 * V_94 = V_17 -> V_95 ;
struct V_11 * V_87 ;
struct V_96 * V_50 , * V_97 ;
struct V_98 * V_99 , * V_100 ;
unsigned * V_88 ;
unsigned int V_89 , V_101 , V_102 = 0 ;
char * V_20 , * V_21 ;
int V_103 ;
V_101 = F_41 ( V_94 ) ;
if ( ! V_101 )
return - V_27 ;
V_50 = F_38 ( V_17 , V_101 * sizeof( * V_50 ) , V_28 ) ;
if ( ! V_50 )
return - V_27 ;
V_97 = V_50 ;
V_99 = F_38 ( V_17 , V_101 * sizeof( * V_99 ) , V_28 ) ;
if ( ! V_99 )
return - V_27 ;
V_100 = V_99 ;
F_42 (dev_np, cfg_np) {
T_1 V_45 ;
V_103 = F_37 ( V_86 , V_87 ,
& V_88 , & V_89 ) ;
if ( V_103 ) {
V_20 = NULL ;
goto V_104;
}
V_20 = F_43 ( V_17 , V_28 ,
L_4 , V_87 -> V_8 , V_30 ) ;
if ( ! V_20 )
return - V_29 ;
V_97 -> V_8 = V_20 ;
V_97 -> V_9 = V_88 ;
V_97 -> V_10 = V_89 ;
V_97 ++ ;
V_104:
V_103 = F_11 ( V_87 , L_1 ,
& V_45 ) ;
if ( V_103 )
continue;
V_21 = F_43 ( V_17 , V_28 ,
L_4 , V_87 -> V_8 , V_41 ) ;
if ( ! V_21 )
return - V_29 ;
V_100 -> V_8 = V_21 ;
V_100 -> V_50 = F_38 ( V_17 , sizeof( char * ) , V_28 ) ;
if ( ! V_100 -> V_50 )
return - V_29 ;
V_100 -> V_50 [ 0 ] = V_20 ;
V_100 -> V_51 = V_20 ? 1 : 0 ;
V_100 -> V_45 = V_45 ;
V_100 ++ ;
V_102 ++ ;
}
V_4 -> V_7 = V_50 ;
V_4 -> V_5 = V_101 ;
V_4 -> V_49 = V_99 ;
V_4 -> V_48 = V_102 ;
return 0 ;
}
static int F_44 ( struct V_85 * V_86 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_86 -> V_17 ;
struct V_105 * V_106 ;
struct V_1 * V_107 ;
struct V_108 * V_109 , * V_110 ;
struct V_56 V_111 ;
char * V_112 ;
int V_60 , V_103 ;
V_106 = F_38 ( V_17 , sizeof( * V_106 ) , V_28 ) ;
if ( ! V_106 )
return - V_29 ;
V_106 -> V_8 = L_7 ;
V_106 -> V_113 = V_114 ;
V_106 -> V_115 = & V_116 ;
V_106 -> V_117 = & V_118 ;
V_106 -> V_119 = & V_120 ;
V_109 = F_38 ( & V_86 -> V_17 , sizeof( * V_109 ) *
V_121 , V_28 ) ;
if ( ! V_109 )
return - V_29 ;
V_106 -> V_9 = V_109 ;
V_106 -> V_89 = V_121 ;
for ( V_60 = 0 , V_110 = V_109 ; V_60 < V_106 -> V_89 ; V_60 ++ , V_110 ++ )
V_110 -> V_122 = V_60 ;
V_112 = F_38 ( & V_86 -> V_17 , sizeof( char ) * V_123 *
V_106 -> V_89 , V_28 ) ;
if ( ! V_112 )
return - V_29 ;
for ( V_60 = 0 ; V_60 < V_106 -> V_89 ; V_60 ++ ) {
snprintf ( V_112 , 6 , L_8 , V_60 ) ;
V_110 = V_109 + V_60 ;
V_110 -> V_8 = V_112 ;
V_112 += V_123 ;
}
V_103 = F_40 ( V_86 , V_4 ) ;
if ( V_103 )
return V_103 ;
V_107 = F_45 ( V_106 , & V_86 -> V_17 , V_4 ) ;
if ( F_46 ( V_107 ) ) {
F_8 ( & V_86 -> V_17 , L_9 ) ;
return F_47 ( V_107 ) ;
}
V_111 . V_8 = L_10 ;
V_111 . V_124 = 0 ;
V_111 . V_53 = 0 ;
V_111 . V_89 = V_121 ;
V_111 . V_77 = V_4 -> V_77 ;
F_48 ( V_107 , & V_111 ) ;
return 0 ;
}
static int F_49 ( struct V_85 * V_86 ,
struct V_3 * V_4 )
{
struct V_76 * V_77 ;
int V_103 ;
V_77 = F_38 ( & V_86 -> V_17 , sizeof( * V_77 ) , V_28 ) ;
if ( ! V_77 )
return - V_29 ;
V_4 -> V_77 = V_77 ;
V_77 -> V_53 = 0 ;
V_77 -> V_125 = V_121 ;
V_77 -> V_17 = & V_86 -> V_17 ;
V_77 -> V_126 = F_30 ;
V_77 -> V_127 = F_32 ;
V_77 -> V_128 = F_33 ;
V_77 -> V_129 = F_34 ;
V_77 -> V_130 = F_35 ;
V_77 -> V_131 = L_11 ;
V_77 -> V_113 = V_114 ;
V_103 = F_50 ( V_77 ) ;
if ( V_103 ) {
F_8 ( & V_86 -> V_17 , L_12
L_13 , V_77 -> V_131 , V_103 ) ;
return V_103 ;
}
return 0 ;
}
static int F_51 ( struct V_85 * V_86 ,
struct V_3 * V_4 )
{
F_52 ( V_4 -> V_77 ) ;
return 0 ;
}
static void F_53 ( struct V_132 * V_133 )
{
struct V_3 * V_134 ;
unsigned long V_135 ;
V_134 = F_54 ( V_133 ) ;
V_135 = F_19 ( V_134 -> V_54 + V_136 ) ;
V_135 |= 1 << V_133 -> V_137 ;
F_20 ( V_135 , V_134 -> V_54 + V_136 ) ;
}
static void F_55 ( struct V_132 * V_133 )
{
struct V_3 * V_134 ;
unsigned long V_135 ;
V_134 = F_54 ( V_133 ) ;
V_135 = F_19 ( V_134 -> V_54 + V_136 ) ;
V_135 &= ~ ( 1 << V_133 -> V_137 ) ;
F_20 ( V_135 , V_134 -> V_54 + V_136 ) ;
}
static T_3 F_56 ( int V_138 , void * V_36 )
{
struct V_139 * V_140 = V_36 ;
struct V_3 * V_134 = V_140 -> V_4 ;
int V_82 ;
V_82 = F_57 ( V_134 -> V_84 , V_140 -> V_135 ) ;
if ( ! V_82 )
return V_141 ;
F_58 ( V_82 ) ;
return V_142 ;
}
static int F_59 ( struct V_84 * V_143 , unsigned int V_82 ,
T_4 V_144 )
{
struct V_3 * V_134 = V_143 -> V_145 ;
F_60 ( V_82 , V_134 ) ;
F_61 ( V_82 , & V_146 ,
V_147 ) ;
return 0 ;
}
static int F_62 ( struct V_85 * V_86 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_86 -> V_17 ;
struct V_139 * V_140 ;
int V_63 , V_138 , V_103 ;
V_140 = F_38 ( V_17 , sizeof( * V_140 ) * V_148 ,
V_28 ) ;
if ( ! V_140 )
return - V_29 ;
for ( V_63 = 0 ; V_63 < V_148 ; V_63 ++ ) {
V_138 = F_63 ( V_17 -> V_95 , V_63 ) ;
if ( V_138 <= 0 ) {
F_8 ( V_17 , L_14 ) ;
return - V_27 ;
}
V_140 -> V_135 = V_63 ;
V_140 -> V_4 = V_4 ;
V_103 = F_64 ( V_17 , V_138 , F_56 ,
0 , F_65 ( V_17 ) , V_140 ++ ) ;
if ( V_103 ) {
F_8 ( V_17 , L_15 ) ;
return - V_83 ;
}
}
V_4 -> V_84 = F_66 ( V_17 -> V_95 ,
V_148 ,
& V_149 , V_4 ) ;
if ( ! V_4 -> V_84 ) {
F_8 ( V_17 , L_16 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_67 ( struct V_85 * V_86 )
{
struct V_16 * V_17 = & V_86 -> V_17 ;
struct V_3 * V_4 ;
struct V_150 * V_151 ;
int V_103 ;
if ( ! V_17 -> V_95 ) {
F_8 ( V_17 , L_17 ) ;
return - V_152 ;
}
V_4 = F_38 ( V_17 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_29 ;
V_151 = F_68 ( V_86 , V_153 , 0 ) ;
V_4 -> V_54 = F_69 ( & V_86 -> V_17 , V_151 ) ;
if ( F_46 ( V_4 -> V_54 ) )
return F_47 ( V_4 -> V_54 ) ;
V_103 = F_49 ( V_86 , V_4 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_44 ( V_86 , V_4 ) ;
if ( V_103 ) {
F_51 ( V_86 , V_4 ) ;
return V_103 ;
}
V_103 = F_62 ( V_86 , V_4 ) ;
if ( V_103 ) {
F_8 ( V_17 , L_18 ) ;
return V_103 ;
}
F_70 ( V_86 , V_4 ) ;
F_71 ( V_17 , L_19 ) ;
return 0 ;
}
static int T_5 F_72 ( void )
{
return F_73 ( & V_154 ) ;
}
static void T_6 F_74 ( void )
{
F_75 ( & V_154 ) ;
}
