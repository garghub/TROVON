static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
return V_7 -> V_8 ;
}
static const char * F_5 ( struct V_4 * V_5 ,
unsigned V_9 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
return V_7 -> V_10 [ V_9 ] . V_11 ;
}
static int F_6 ( struct V_4 * V_5 ,
unsigned V_9 , const unsigned * * V_12 , unsigned * V_13 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
* V_12 = V_7 -> V_10 [ V_9 ] . V_12 ;
* V_13 = V_7 -> V_10 [ V_9 ] . V_13 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_14 * V_15 , struct V_16 * * V_17 ,
unsigned * V_18 )
{
struct V_19 * V_20 = V_5 -> V_20 ;
struct V_16 * V_21 ;
unsigned long * V_22 = NULL ;
char * V_23 , * V_24 ;
int V_25 = 0 , V_26 = 0 , V_27 = 0 ;
for ( V_27 = 0 ; V_27 < F_8 ( V_28 ) ; V_27 ++ ) {
if ( F_9 ( V_15 , V_28 [ V_27 ] . V_29 , NULL ) )
V_25 ++ ;
}
if ( V_25 )
V_26 = 1 ;
if ( F_9 ( V_15 , L_1 , NULL ) )
V_26 ++ ;
if ( ! V_26 ) {
F_10 ( V_20 , L_2
L_3 , V_15 -> V_11 ) ;
return - V_30 ;
}
V_21 = F_11 ( sizeof( * V_21 ) * V_26 , V_31 ) ;
if ( ! V_21 ) {
F_10 ( V_20 , L_4 ) ;
return - V_32 ;
}
* V_18 = 0 ;
V_23 = F_11 ( strlen ( V_15 -> V_11 ) + V_33 , V_31 ) ;
if ( ! V_23 ) {
F_10 ( V_20 , L_5 ) ;
goto V_34;
}
sprintf ( V_23 , L_6 , V_15 -> V_11 , V_35 ) ;
if ( ! V_25 )
goto V_36;
V_22 = F_11 ( sizeof( * V_22 ) * V_25 , V_31 ) ;
if ( ! V_22 ) {
F_10 ( V_20 , L_7 ) ;
goto V_37;
}
for ( V_27 = 0 , V_25 = 0 ; V_27 < F_8 ( V_28 ) ; V_27 ++ ) {
T_1 V_38 ;
if ( ! F_12 ( V_15 , V_28 [ V_27 ] . V_29 , & V_38 ) )
V_22 [ V_25 ++ ] =
F_13 ( V_28 [ V_27 ] . V_39 , V_38 ) ;
}
V_21 [ * V_18 ] . V_40 . V_41 . V_42 = V_23 ;
V_21 [ * V_18 ] . V_40 . V_41 . V_41 = V_22 ;
V_21 [ * V_18 ] . V_40 . V_41 . V_43 = V_25 ;
V_21 [ * V_18 ] . type = V_44 ;
* V_18 += 1 ;
V_36:
if ( F_9 ( V_15 , L_1 , NULL ) ) {
V_24 = F_11 ( strlen ( V_15 -> V_11 ) + V_45 , V_31 ) ;
if ( ! V_24 ) {
F_10 ( V_20 , L_8 ) ;
goto V_46;
}
sprintf ( V_24 , L_6 , V_15 -> V_11 , V_47 ) ;
V_21 [ * V_18 ] . V_40 . V_48 . V_49 = V_23 ;
V_21 [ * V_18 ] . V_40 . V_48 . V_50 = V_24 ;
V_21 [ * V_18 ] . type = V_51 ;
* V_18 += 1 ;
}
* V_17 = V_21 ;
return 0 ;
V_46:
F_14 ( V_22 ) ;
V_37:
F_14 ( V_23 ) ;
V_34:
F_14 ( V_21 ) ;
return - V_32 ;
}
static void F_15 ( struct V_4 * V_5 ,
struct V_16 * V_21 , unsigned V_52 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_52 ; V_27 ++ ) {
if ( V_21 [ V_27 ] . type == V_51 ) {
F_14 ( V_21 [ V_27 ] . V_40 . V_48 . V_50 ) ;
if ( ! V_27 )
F_14 ( V_21 [ V_27 ] . V_40 . V_48 . V_49 ) ;
} else if ( V_21 -> type == V_44 ) {
F_14 ( V_21 [ V_27 ] . V_40 . V_41 . V_41 ) ;
if ( ! V_27 )
F_14 ( V_21 [ V_27 ] . V_40 . V_41 . V_42 ) ;
}
} ;
F_14 ( V_21 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
return V_7 -> V_53 ;
}
static const char * F_17 ( struct V_4 * V_5 ,
unsigned V_9 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
return V_7 -> V_54 [ V_9 ] . V_11 ;
}
static int F_18 ( struct V_4 * V_5 ,
unsigned V_9 , const char * const * * V_55 ,
unsigned * const V_56 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 ) ;
* V_55 = V_7 -> V_54 [ V_9 ] . V_55 ;
* V_56 = V_7 -> V_54 [ V_9 ] . V_56 ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
unsigned V_57 , void T_2 * * V_58 , T_1 * V_59 ,
struct V_1 * * V_60 )
{
struct V_1 * V_61 ;
V_61 = V_7 -> V_62 -> V_63 ;
while ( ( V_57 >= V_61 -> V_64 ) &&
( ( V_61 -> V_64 + V_61 -> V_65 - 1 ) < V_57 ) )
V_61 ++ ;
* V_58 = V_7 -> V_66 + V_61 -> V_67 ;
* V_59 = V_57 - V_61 -> V_64 ;
if ( V_60 )
* V_60 = V_61 ;
if ( * V_59 * V_61 -> V_68 > V_69 )
* V_58 += 4 ;
}
static void F_20 ( struct V_4 * V_5 , unsigned V_9 ,
unsigned V_49 , bool V_70 )
{
struct V_6 * V_7 ;
const unsigned int * V_12 ;
struct V_1 * V_60 ;
void T_2 * V_58 ;
T_1 V_71 , V_72 , V_40 , V_73 , V_74 ;
V_7 = F_4 ( V_5 ) ;
V_12 = V_7 -> V_10 [ V_49 ] . V_12 ;
for ( V_74 = 0 ; V_74 < V_7 -> V_10 [ V_49 ] . V_13 ; V_74 ++ ) {
F_19 ( V_7 , V_12 [ V_74 ] - V_7 -> V_62 -> V_75 ,
& V_58 , & V_73 , & V_60 ) ;
V_71 = ( 1 << V_60 -> V_68 ) - 1 ;
V_72 = V_73 * V_60 -> V_68 ;
V_40 = F_21 ( V_58 ) ;
V_40 &= ~ ( V_71 << V_72 ) ;
if ( V_70 )
V_40 |= V_7 -> V_10 [ V_49 ] . V_76 << V_72 ;
F_22 ( V_40 , V_58 ) ;
}
}
static int F_23 ( struct V_4 * V_5 , unsigned V_9 ,
unsigned V_49 )
{
F_20 ( V_5 , V_9 , V_49 , true ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_5 ,
unsigned V_9 , unsigned V_49 )
{
F_20 ( V_5 , V_9 , V_49 , false ) ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_77 * V_78 , unsigned V_59 , bool V_79 )
{
struct V_1 * V_60 ;
struct V_6 * V_7 ;
void T_2 * V_58 ;
T_1 V_40 , V_73 , V_71 , V_72 ;
V_60 = F_1 ( V_78 -> V_3 ) ;
V_7 = F_4 ( V_5 ) ;
V_73 = V_59 - V_60 -> V_64 ;
V_58 = V_7 -> V_66 + V_60 -> V_67 ;
V_71 = ( 1 << V_60 -> V_68 ) - 1 ;
V_72 = V_73 * V_60 -> V_68 ;
V_40 = F_21 ( V_58 ) ;
V_40 &= ~ ( V_71 << V_72 ) ;
if ( ! V_79 )
V_40 |= V_80 << V_72 ;
F_22 ( V_40 , V_58 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_81 , bool V_82 )
{
struct V_6 * V_7 ;
struct V_1 * V_60 ;
void T_2 * V_83 ;
enum V_84 V_39 = F_27 ( * V_81 ) ;
T_1 V_40 , V_85 , V_73 , V_71 , V_72 ;
T_1 V_86 , V_87 ;
V_7 = F_4 ( V_5 ) ;
F_19 ( V_7 , V_57 - V_7 -> V_62 -> V_75 , & V_83 ,
& V_73 , & V_60 ) ;
switch ( V_39 ) {
case V_88 :
V_85 = V_60 -> V_89 ;
V_87 = V_90 ;
break;
case V_91 :
V_85 = V_60 -> V_92 ;
V_87 = V_93 ;
break;
case V_94 :
V_85 = V_60 -> V_95 ;
V_87 = V_96 ;
break;
case V_97 :
V_85 = V_60 -> V_98 ;
V_87 = V_99 ;
break;
default:
F_28 ( 1 ) ;
return - V_30 ;
}
if ( ! V_85 )
return - V_30 ;
V_71 = ( 1 << V_85 ) - 1 ;
V_72 = V_73 * V_85 ;
V_40 = F_21 ( V_83 + V_87 ) ;
if ( V_82 ) {
V_86 = F_29 ( * V_81 ) ;
V_40 &= ~ ( V_71 << V_72 ) ;
V_40 |= ( V_86 << V_72 ) ;
F_22 ( V_40 , V_83 + V_87 ) ;
} else {
V_40 >>= V_72 ;
V_40 &= V_71 ;
* V_81 = F_13 ( V_39 , V_40 ) ;
}
return 0 ;
}
static int F_30 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long V_81 )
{
return F_26 ( V_5 , V_57 , & V_81 , true ) ;
}
static int F_31 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_81 )
{
return F_26 ( V_5 , V_57 , V_81 , false ) ;
}
static int F_32 ( struct V_4 * V_5 ,
unsigned V_49 , unsigned long V_81 )
{
struct V_6 * V_7 ;
const unsigned int * V_12 ;
unsigned int V_74 ;
V_7 = F_4 ( V_5 ) ;
V_12 = V_7 -> V_10 [ V_49 ] . V_12 ;
for ( V_74 = 0 ; V_74 < V_7 -> V_10 [ V_49 ] . V_13 ; V_74 ++ )
F_30 ( V_5 , V_12 [ V_74 ] , V_81 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 ,
unsigned int V_49 , unsigned long * V_81 )
{
struct V_6 * V_7 ;
const unsigned int * V_12 ;
V_7 = F_4 ( V_5 ) ;
V_12 = V_7 -> V_10 [ V_49 ] . V_12 ;
F_31 ( V_5 , V_12 [ 0 ] , V_81 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , unsigned V_59 , int V_38 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
void T_2 * V_58 ;
T_1 V_40 ;
V_58 = V_60 -> V_7 -> V_66 + V_60 -> V_67 ;
V_40 = F_21 ( V_58 + V_100 ) ;
V_40 &= ~ ( 1 << V_59 ) ;
if ( V_38 )
V_40 |= 1 << V_59 ;
F_22 ( V_40 , V_58 + V_100 ) ;
}
static int F_35 ( struct V_2 * V_3 , unsigned V_59 )
{
void T_2 * V_58 ;
T_1 V_40 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
V_58 = V_60 -> V_7 -> V_66 + V_60 -> V_67 ;
V_40 = F_21 ( V_58 + V_100 ) ;
V_40 >>= V_59 ;
V_40 &= 1 ;
return V_40 ;
}
static int F_36 ( struct V_2 * V_3 , unsigned V_59 )
{
return F_37 ( V_3 -> V_75 + V_59 ) ;
}
static int F_38 ( struct V_2 * V_3 , unsigned V_59 ,
int V_38 )
{
F_34 ( V_3 , V_59 , V_38 ) ;
return F_39 ( V_3 -> V_75 + V_59 ) ;
}
static int F_40 ( struct V_2 * V_3 , unsigned V_59 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned int V_101 ;
if ( ! V_60 -> V_102 )
return - V_103 ;
V_101 = F_41 ( V_60 -> V_102 , V_59 ) ;
return ( V_101 ) ? : - V_103 ;
}
static int F_42 ( struct V_104 * V_105 ,
struct V_14 * V_106 ,
struct V_107 * V_108 ,
unsigned int * * V_109 ,
unsigned int * V_110 )
{
struct V_19 * V_20 = & V_105 -> V_20 ;
struct V_111 * V_112 ;
struct V_113 const * V_114 = V_108 -> V_12 ;
unsigned int V_27 = 0 , V_74 ;
const char * V_115 ;
* V_110 = F_43 ( V_106 , L_9 ) ;
if ( F_44 ( * V_110 ) ) {
F_10 ( V_20 , L_10 , V_106 -> V_11 ) ;
return - V_30 ;
}
* V_109 = F_45 ( V_20 , * V_110 * sizeof( * * V_109 ) , V_31 ) ;
if ( ! * V_109 ) {
F_10 ( V_20 , L_11 ) ;
return - V_32 ;
}
F_46 (cfg_np, L_9 , prop, pin_name) {
for ( V_74 = 0 ; V_74 < V_108 -> V_110 ; V_74 ++ ) {
if ( V_114 [ V_74 ] . V_11 ) {
if ( ! strcmp ( V_115 , V_114 [ V_74 ] . V_11 ) ) {
( * V_109 ) [ V_27 ++ ] = V_114 [ V_74 ] . V_116 ;
break;
}
}
}
if ( V_74 == V_108 -> V_110 ) {
F_10 ( V_20 , L_12 ,
V_115 , V_106 -> V_11 ) ;
F_47 ( V_20 , * V_109 ) ;
return - V_30 ;
}
}
return 0 ;
}
static int F_48 ( struct V_104 * V_105 ,
struct V_6 * V_7 )
{
struct V_19 * V_20 = & V_105 -> V_20 ;
struct V_14 * V_117 = V_20 -> V_118 ;
struct V_14 * V_106 ;
struct V_119 * V_55 , * V_120 ;
struct V_121 * V_122 , * V_76 ;
unsigned * V_109 ;
unsigned int V_110 , V_123 , V_124 = 0 ;
char * V_23 , * V_24 ;
int V_125 ;
V_123 = F_49 ( V_117 ) ;
if ( ! V_123 )
return - V_30 ;
V_55 = F_45 ( V_20 , V_123 * sizeof( * V_55 ) , V_31 ) ;
if ( ! V_55 ) {
F_10 ( V_20 , L_13 ) ;
return - V_30 ;
}
V_120 = V_55 ;
V_122 = F_45 ( V_20 , V_123 * sizeof( * V_122 ) , V_31 ) ;
if ( ! V_122 ) {
F_10 ( V_20 , L_14 ) ;
return - V_30 ;
}
V_76 = V_122 ;
F_50 (dev_np, cfg_np) {
T_1 V_50 ;
if ( ! F_9 ( V_106 , L_9 , NULL ) )
continue;
V_125 = F_42 ( V_105 , V_106 ,
& V_7 -> V_108 , & V_109 , & V_110 ) ;
if ( V_125 )
return V_125 ;
V_23 = F_45 ( V_20 , strlen ( V_106 -> V_11 ) + V_33 ,
V_31 ) ;
if ( ! V_23 ) {
F_10 ( V_20 , L_5 ) ;
return - V_32 ;
}
sprintf ( V_23 , L_6 , V_106 -> V_11 , V_35 ) ;
V_120 -> V_11 = V_23 ;
V_120 -> V_12 = V_109 ;
V_120 -> V_13 = V_110 ;
F_12 ( V_106 , L_1 , & V_50 ) ;
V_120 -> V_76 = V_50 ;
V_120 ++ ;
if ( ! F_9 ( V_106 , L_1 , NULL ) )
continue;
V_24 = F_45 ( V_20 , strlen ( V_106 -> V_11 ) + V_45 ,
V_31 ) ;
if ( ! V_24 ) {
F_10 ( V_20 , L_8 ) ;
return - V_32 ;
}
sprintf ( V_24 , L_6 , V_106 -> V_11 , V_47 ) ;
V_76 -> V_11 = V_24 ;
V_76 -> V_55 = F_45 ( V_20 , sizeof( char * ) , V_31 ) ;
if ( ! V_76 -> V_55 ) {
F_10 ( V_20 , L_15
L_16 ) ;
return - V_32 ;
}
V_76 -> V_55 [ 0 ] = V_23 ;
V_76 -> V_56 = 1 ;
V_76 ++ ;
V_124 ++ ;
}
V_7 -> V_10 = V_55 ;
V_7 -> V_8 = V_123 ;
V_7 -> V_54 = V_122 ;
V_7 -> V_53 = V_124 ;
return 0 ;
}
static int F_51 ( struct V_104 * V_105 ,
struct V_6 * V_7 )
{
struct V_107 * V_126 = & V_7 -> V_108 ;
struct V_113 * V_127 , * V_114 ;
struct V_1 * V_128 ;
char * V_129 ;
int V_57 , V_60 , V_125 ;
V_126 -> V_11 = L_17 ;
V_126 -> V_130 = V_131 ;
V_126 -> V_132 = & V_133 ;
V_126 -> V_134 = & V_135 ;
V_126 -> V_136 = & V_137 ;
V_127 = F_45 ( & V_105 -> V_20 , sizeof( * V_127 ) *
V_7 -> V_62 -> V_65 , V_31 ) ;
if ( ! V_127 ) {
F_10 ( & V_105 -> V_20 , L_18 ) ;
return - V_32 ;
}
V_126 -> V_12 = V_127 ;
V_126 -> V_110 = V_7 -> V_62 -> V_65 ;
V_126 -> V_110 = V_7 -> V_62 -> V_65 ;
for ( V_57 = 0 , V_114 = V_127 ; V_57 < V_126 -> V_110 ; V_57 ++ , V_114 ++ )
V_114 -> V_116 = V_57 + V_7 -> V_62 -> V_75 ;
V_129 = F_45 ( & V_105 -> V_20 , sizeof( char ) * V_138 *
V_7 -> V_62 -> V_65 , V_31 ) ;
if ( ! V_129 ) {
F_10 ( & V_105 -> V_20 , L_19 ) ;
return - V_32 ;
}
for ( V_60 = 0 ; V_60 < V_7 -> V_62 -> V_139 ; V_60 ++ ) {
V_128 = & V_7 -> V_62 -> V_63 [ V_60 ] ;
for ( V_57 = 0 ; V_57 < V_128 -> V_65 ; V_57 ++ ) {
sprintf ( V_129 , L_20 , V_128 -> V_11 , V_57 ) ;
V_114 = V_127 + V_128 -> V_64 + V_57 ;
V_114 -> V_11 = V_129 ;
V_129 += V_138 ;
}
}
V_7 -> V_140 = F_52 ( V_126 , & V_105 -> V_20 , V_7 ) ;
if ( ! V_7 -> V_140 ) {
F_10 ( & V_105 -> V_20 , L_21 ) ;
return - V_30 ;
}
for ( V_60 = 0 ; V_60 < V_7 -> V_62 -> V_139 ; ++ V_60 ) {
V_128 = & V_7 -> V_62 -> V_63 [ V_60 ] ;
V_128 -> V_141 . V_11 = V_128 -> V_11 ;
V_128 -> V_141 . V_142 = V_60 ;
V_128 -> V_141 . V_64 = V_128 -> V_64 ;
V_128 -> V_141 . V_75 = V_128 -> V_2 . V_75 ;
V_128 -> V_141 . V_110 = V_128 -> V_2 . V_143 ;
V_128 -> V_141 . V_3 = & V_128 -> V_2 ;
F_53 ( V_7 -> V_140 , & V_128 -> V_141 ) ;
}
V_125 = F_48 ( V_105 , V_7 ) ;
if ( V_125 ) {
F_54 ( V_7 -> V_140 ) ;
return V_125 ;
}
return 0 ;
}
static int F_55 ( struct V_104 * V_105 ,
struct V_6 * V_7 )
{
struct V_144 * V_62 = V_7 -> V_62 ;
struct V_1 * V_60 = V_62 -> V_63 ;
struct V_2 * V_3 ;
int V_125 ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_62 -> V_139 ; ++ V_145 , ++ V_60 ) {
V_60 -> V_2 = V_146 ;
V_3 = & V_60 -> V_2 ;
V_3 -> V_75 = V_62 -> V_75 + V_60 -> V_64 ;
V_3 -> V_143 = V_60 -> V_65 ;
V_3 -> V_20 = & V_105 -> V_20 ;
V_3 -> V_118 = V_60 -> V_118 ;
V_3 -> V_147 = V_60 -> V_11 ;
V_125 = F_56 ( V_3 ) ;
if ( V_125 ) {
F_10 ( & V_105 -> V_20 , L_22 ,
V_3 -> V_147 , V_125 ) ;
goto V_148;
}
}
return 0 ;
V_148:
for ( -- V_145 , -- V_60 ; V_145 >= 0 ; -- V_145 , -- V_60 )
if ( F_57 ( & V_60 -> V_2 ) )
F_10 ( & V_105 -> V_20 , L_23 ,
V_60 -> V_2 . V_147 ) ;
return V_125 ;
}
static int F_58 ( struct V_104 * V_105 ,
struct V_6 * V_7 )
{
struct V_144 * V_62 = V_7 -> V_62 ;
struct V_1 * V_60 = V_62 -> V_63 ;
int V_125 = 0 ;
int V_145 ;
for ( V_145 = 0 ; ! V_125 && V_145 < V_62 -> V_139 ; ++ V_145 , ++ V_60 )
V_125 = F_57 ( & V_60 -> V_2 ) ;
if ( V_125 )
F_10 ( & V_105 -> V_20 , L_24 ) ;
return V_125 ;
}
static struct V_144 * F_59 (
struct V_6 * V_149 ,
struct V_104 * V_105 )
{
int V_142 ;
const struct V_150 * V_151 ;
struct V_14 * V_152 = V_105 -> V_20 . V_118 ;
struct V_14 * V_15 ;
struct V_144 * V_62 ;
struct V_1 * V_60 ;
int V_145 ;
V_142 = F_60 ( V_152 , L_25 ) ;
if ( V_142 < 0 ) {
F_10 ( & V_105 -> V_20 , L_26 ) ;
return NULL ;
}
V_151 = F_61 ( V_153 , V_152 ) ;
V_62 = (struct V_144 * ) V_151 -> V_40 + V_142 ;
V_60 = V_62 -> V_63 ;
for ( V_145 = 0 ; V_145 < V_62 -> V_139 ; ++ V_145 , ++ V_60 ) {
V_60 -> V_7 = V_149 ;
V_60 -> V_64 = V_62 -> V_65 ;
V_62 -> V_65 += V_60 -> V_65 ;
}
F_50 (node, np) {
if ( ! F_9 ( V_15 , L_27 , NULL ) )
continue;
V_60 = V_62 -> V_63 ;
for ( V_145 = 0 ; V_145 < V_62 -> V_139 ; ++ V_145 , ++ V_60 ) {
if ( ! strcmp ( V_60 -> V_11 , V_15 -> V_11 ) ) {
V_60 -> V_118 = V_15 ;
break;
}
}
}
V_62 -> V_75 = V_64 ;
V_64 += V_62 -> V_65 ;
return V_62 ;
}
static int F_62 ( struct V_104 * V_105 )
{
struct V_6 * V_7 ;
struct V_19 * V_20 = & V_105 -> V_20 ;
struct V_144 * V_62 ;
struct V_154 * V_155 ;
int V_125 ;
if ( ! V_20 -> V_118 ) {
F_10 ( V_20 , L_28 ) ;
return - V_156 ;
}
V_7 = F_45 ( V_20 , sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 ) {
F_10 ( V_20 , L_29
L_30 ) ;
return - V_32 ;
}
V_62 = F_59 ( V_7 , V_105 ) ;
if ( ! V_62 ) {
F_10 ( & V_105 -> V_20 , L_31 ) ;
return - V_30 ;
}
V_7 -> V_62 = V_62 ;
V_7 -> V_20 = V_20 ;
V_155 = F_63 ( V_105 , V_157 , 0 ) ;
if ( ! V_155 ) {
F_10 ( V_20 , L_32 ) ;
return - V_158 ;
}
V_7 -> V_66 = F_64 ( & V_105 -> V_20 , V_155 ) ;
if ( ! V_7 -> V_66 ) {
F_10 ( V_20 , L_33 ) ;
return - V_156 ;
}
V_155 = F_63 ( V_105 , V_159 , 0 ) ;
if ( V_155 )
V_7 -> V_160 = V_155 -> V_161 ;
V_125 = F_55 ( V_105 , V_7 ) ;
if ( V_125 )
return V_125 ;
V_125 = F_51 ( V_105 , V_7 ) ;
if ( V_125 ) {
F_58 ( V_105 , V_7 ) ;
return V_125 ;
}
if ( V_62 -> V_162 )
V_62 -> V_162 ( V_7 ) ;
if ( V_62 -> V_163 )
V_62 -> V_163 ( V_7 ) ;
F_65 ( V_105 , V_7 ) ;
return 0 ;
}
static int T_3 F_66 ( void )
{
return F_67 ( & V_164 ) ;
}
static void T_4 F_68 ( void )
{
F_69 ( & V_164 ) ;
}
