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
if ( ! V_18 ) {
F_8 ( V_17 , L_4 ) ;
return - V_29 ;
}
* V_15 = 0 ;
V_20 = F_9 ( strlen ( V_12 -> V_8 ) + V_30 , V_28 ) ;
if ( ! V_20 ) {
F_8 ( V_17 , L_5 ) ;
goto V_31;
}
snprintf ( V_20 , strlen ( V_12 -> V_8 ) + 4 , L_6 , V_12 -> V_8 , V_32 ) ;
if ( ! V_22 )
goto V_33;
V_19 = F_9 ( sizeof( * V_19 ) * V_22 , V_28 ) ;
if ( ! V_19 ) {
F_8 ( V_17 , L_7 ) ;
goto V_34;
}
for ( V_24 = 0 , V_22 = 0 ; V_24 < F_6 ( V_25 ) ; V_24 ++ ) {
T_1 V_35 ;
if ( ! F_10 ( V_12 , V_25 [ V_24 ] . V_26 , & V_35 ) )
V_19 [ V_22 ++ ] =
F_11 ( V_25 [ V_24 ] . V_36 , V_35 ) ;
}
V_18 [ * V_15 ] . V_37 . V_38 . V_39 = V_20 ;
V_18 [ * V_15 ] . V_37 . V_38 . V_38 = V_19 ;
V_18 [ * V_15 ] . V_37 . V_38 . V_40 = V_22 ;
V_18 [ * V_15 ] . type = V_41 ;
* V_15 += 1 ;
V_33:
if ( F_7 ( V_12 , L_1 , NULL ) ) {
V_21 = F_9 ( strlen ( V_12 -> V_8 ) + V_42 , V_28 ) ;
if ( ! V_21 ) {
F_8 ( V_17 , L_8 ) ;
goto V_43;
}
snprintf ( V_21 , strlen ( V_12 -> V_8 ) + 4 , L_6 , V_12 -> V_8 ,
V_44 ) ;
V_18 [ * V_15 ] . V_37 . V_45 . V_46 = V_20 ;
V_18 [ * V_15 ] . V_37 . V_45 . V_47 = V_21 ;
V_18 [ * V_15 ] . type = V_48 ;
* V_15 += 1 ;
}
* V_14 = V_18 ;
return 0 ;
V_43:
F_12 ( V_19 ) ;
V_34:
F_12 ( V_20 ) ;
V_31:
F_12 ( V_18 ) ;
return - V_29 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_13 * V_18 , unsigned V_49 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_49 ; V_24 ++ ) {
if ( V_18 [ V_24 ] . type == V_48 ) {
F_12 ( V_18 [ V_24 ] . V_37 . V_45 . V_47 ) ;
if ( ! V_24 )
F_12 ( V_18 [ V_24 ] . V_37 . V_45 . V_46 ) ;
} else if ( V_18 -> type == V_41 ) {
F_12 ( V_18 [ V_24 ] . V_37 . V_38 . V_38 ) ;
if ( ! V_24 )
F_12 ( V_18 [ V_24 ] . V_37 . V_38 . V_39 ) ;
}
} ;
F_12 ( V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_50 ;
}
static const char * F_15 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_51 [ V_6 ] . V_8 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_6 , const char * const * * V_52 ,
unsigned * const V_53 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
* V_52 = V_4 -> V_51 [ V_6 ] . V_52 ;
* V_53 = V_4 -> V_51 [ V_6 ] . V_53 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_46 , bool V_54 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
T_1 V_47 ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
V_47 = V_4 -> V_51 [ V_6 ] . V_47 ;
V_37 = F_18 ( V_55 + V_57 ) ;
if ( V_54 )
V_37 |= ( 1 << V_47 ) ;
else
V_37 &= ~ ( 1 << V_47 ) ;
F_19 ( V_37 , V_55 + V_57 ) ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_46 )
{
F_17 ( V_2 , V_6 , V_46 , true ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned V_6 , unsigned V_46 )
{
F_17 ( V_2 , V_6 , V_46 , false ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_58 * V_59 , unsigned V_60 , bool V_61 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned long V_63 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
enum V_64 V_36 = F_24 ( V_63 ) ;
T_1 V_65 = F_25 ( V_63 ) ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
switch ( V_36 ) {
case V_66 :
V_37 = F_18 ( V_55 + V_67 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
if ( V_65 )
V_37 |= ( 1 << V_62 ) ;
F_19 ( V_37 , V_55 + V_67 ) ;
V_37 = F_18 ( V_55 + V_68 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
if ( V_65 == 2 )
V_37 |= ( 1 << V_62 ) ;
F_19 ( V_37 , V_55 + V_68 ) ;
break;
case V_69 :
V_37 = F_18 ( V_55 + V_70 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_70 ) ;
V_65 >>= 1 ;
V_37 = F_18 ( V_55 + V_71 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_71 ) ;
break;
case V_72 :
V_37 = F_18 ( V_55 + V_73 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_73 ) ;
break;
case V_74 :
V_37 = F_18 ( V_55 + V_75 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_75 ) ;
break;
default:
F_26 ( 1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned long * V_63 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
enum V_64 V_36 = F_24 ( * V_63 ) ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
switch ( V_36 ) {
case V_66 :
V_37 = F_18 ( V_55 + V_67 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
if ( ! V_37 )
* V_63 = 0 ;
else
* V_63 = ( ( F_18 ( V_55 + V_68 ) >> V_62 ) & 1 ) + 1 ;
break;
case V_69 :
V_37 = F_18 ( V_55 + V_70 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
* V_63 = V_37 ;
V_37 = F_18 ( V_55 + V_71 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
* V_63 |= ( V_37 << 1 ) ;
break;
case V_72 :
V_37 = F_18 ( V_55 + V_73 ) ;
* V_63 = ( V_37 >> V_62 ) & 1 ;
break;
case V_74 :
V_37 = F_18 ( V_55 + V_75 ) ;
* V_63 = ( V_37 >> V_62 ) & 1 ;
break;
default:
F_26 ( 1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned V_46 , unsigned long V_63 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
unsigned int V_76 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
for ( V_76 = 0 ; V_76 < V_4 -> V_7 [ V_46 ] . V_10 ; V_76 ++ )
F_23 ( V_2 , V_9 [ V_76 ] , V_63 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_46 , unsigned long * V_63 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
F_27 ( V_2 , V_9 [ 0 ] , V_63 ) ;
return 0 ;
}
static void F_30 ( struct V_77 * V_78 , unsigned V_60 , int V_35 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_79 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
if ( V_35 )
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_79 ) ;
}
static int F_32 ( struct V_77 * V_78 , unsigned V_60 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_80 ) ;
V_37 >>= V_60 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_33 ( struct V_77 * V_78 , unsigned V_60 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_81 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
F_19 ( V_37 , V_55 + V_81 ) ;
V_37 = F_18 ( V_55 + V_82 ) ;
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_82 ) ;
return 0 ;
}
static int F_34 ( struct V_77 * V_78 , unsigned V_60 ,
int V_35 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
F_30 ( V_78 , V_60 , V_35 ) ;
V_37 = F_18 ( V_55 + V_82 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
F_19 ( V_37 , V_55 + V_82 ) ;
V_37 = F_18 ( V_55 + V_81 ) ;
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_81 ) ;
return 0 ;
}
static int F_35 ( struct V_77 * V_78 , unsigned V_60 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
unsigned int V_83 ;
if ( V_60 < 16 || V_60 > 23 )
return - V_84 ;
if ( ! V_4 -> V_85 )
return - V_84 ;
V_83 = F_36 ( V_4 -> V_85 , V_60 - 16 ) ;
return V_83 ? : - V_84 ;
}
static int F_37 ( struct V_86 * V_87 ,
struct V_11 * V_88 , unsigned int * * V_89 ,
unsigned int * V_90 )
{
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_91 * V_92 ;
V_92 = F_7 ( V_88 , L_9 , NULL ) ;
if ( ! V_92 )
return - V_93 ;
* V_90 = V_92 -> V_94 / sizeof( unsigned long ) ;
if ( ! * V_90 ) {
F_8 ( V_17 , L_10 , V_88 -> V_8 ) ;
return - V_27 ;
}
* V_89 = F_38 ( V_17 , * V_90 * sizeof( * * V_89 ) , V_28 ) ;
if ( ! * V_89 ) {
F_8 ( V_17 , L_11 ) ;
return - V_29 ;
}
return F_39 ( V_88 , L_9 ,
* V_89 , * V_90 ) ;
}
static int F_40 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_11 * V_95 = V_17 -> V_96 ;
struct V_11 * V_88 ;
struct V_97 * V_52 , * V_98 ;
struct V_99 * V_100 , * V_101 ;
unsigned * V_89 ;
unsigned int V_90 , V_102 , V_103 = 0 ;
char * V_20 , * V_21 ;
int V_104 ;
V_102 = F_41 ( V_95 ) ;
if ( ! V_102 )
return - V_27 ;
V_52 = F_38 ( V_17 , V_102 * sizeof( * V_52 ) , V_28 ) ;
if ( ! V_52 ) {
F_8 ( V_17 , L_12 ) ;
return - V_27 ;
}
V_98 = V_52 ;
V_100 = F_38 ( V_17 , V_102 * sizeof( * V_100 ) , V_28 ) ;
if ( ! V_100 ) {
F_8 ( V_17 , L_13 ) ;
return - V_27 ;
}
V_101 = V_100 ;
F_42 (dev_np, cfg_np) {
T_1 V_47 ;
V_104 = F_37 ( V_87 , V_88 ,
& V_89 , & V_90 ) ;
if ( V_104 ) {
V_20 = NULL ;
goto V_105;
}
V_20 = F_38 ( V_17 , strlen ( V_88 -> V_8 ) + V_30 ,
V_28 ) ;
if ( ! V_20 ) {
F_8 ( V_17 , L_5 ) ;
return - V_29 ;
}
snprintf ( V_20 , strlen ( V_88 -> V_8 ) + 4 , L_6 , V_88 -> V_8 ,
V_32 ) ;
V_98 -> V_8 = V_20 ;
V_98 -> V_9 = V_89 ;
V_98 -> V_10 = V_90 ;
V_98 ++ ;
V_105:
V_104 = F_10 ( V_88 , L_1 ,
& V_47 ) ;
if ( V_104 )
continue;
V_21 = F_38 ( V_17 , strlen ( V_88 -> V_8 ) + V_42 ,
V_28 ) ;
if ( ! V_21 ) {
F_8 ( V_17 , L_8 ) ;
return - V_29 ;
}
snprintf ( V_21 , strlen ( V_88 -> V_8 ) + 4 , L_6 , V_88 -> V_8 ,
V_44 ) ;
V_101 -> V_8 = V_21 ;
V_101 -> V_52 = F_38 ( V_17 , sizeof( char * ) , V_28 ) ;
if ( ! V_101 -> V_52 ) {
F_8 ( V_17 , L_14
L_15 ) ;
return - V_29 ;
}
V_101 -> V_52 [ 0 ] = V_20 ;
V_101 -> V_53 = V_20 ? 1 : 0 ;
V_101 -> V_47 = V_47 ;
V_101 ++ ;
V_103 ++ ;
}
V_4 -> V_7 = V_52 ;
V_4 -> V_5 = V_102 ;
V_4 -> V_51 = V_100 ;
V_4 -> V_50 = V_103 ;
return 0 ;
}
static int F_43 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_106 * V_107 ;
struct V_1 * V_108 ;
struct V_109 * V_110 , * V_111 ;
struct V_58 V_112 ;
char * V_113 ;
int V_62 , V_104 ;
V_107 = F_38 ( V_17 , sizeof( * V_107 ) , V_28 ) ;
if ( ! V_107 ) {
F_8 ( V_17 , L_16 ) ;
return - V_29 ;
}
V_107 -> V_8 = L_17 ;
V_107 -> V_114 = V_115 ;
V_107 -> V_116 = & V_117 ;
V_107 -> V_118 = & V_119 ;
V_107 -> V_120 = & V_121 ;
V_110 = F_38 ( & V_87 -> V_17 , sizeof( * V_110 ) *
V_122 , V_28 ) ;
if ( ! V_110 ) {
F_8 ( & V_87 -> V_17 , L_18 ) ;
return - V_29 ;
}
V_107 -> V_9 = V_110 ;
V_107 -> V_90 = V_122 ;
for ( V_62 = 0 , V_111 = V_110 ; V_62 < V_107 -> V_90 ; V_62 ++ , V_111 ++ )
V_111 -> V_123 = V_62 ;
V_113 = F_38 ( & V_87 -> V_17 , sizeof( char ) * V_124 *
V_107 -> V_90 , V_28 ) ;
if ( ! V_113 ) {
F_8 ( & V_87 -> V_17 , L_19 ) ;
return - V_29 ;
}
for ( V_62 = 0 ; V_62 < V_107 -> V_90 ; V_62 ++ ) {
snprintf ( V_113 , 6 , L_20 , V_62 ) ;
V_111 = V_110 + V_62 ;
V_111 -> V_8 = V_113 ;
V_113 += V_124 ;
}
V_104 = F_40 ( V_87 , V_4 ) ;
if ( V_104 )
return V_104 ;
V_108 = F_44 ( V_107 , & V_87 -> V_17 , V_4 ) ;
if ( ! V_108 ) {
F_8 ( & V_87 -> V_17 , L_21 ) ;
return - V_27 ;
}
V_112 . V_8 = L_22 ;
V_112 . V_125 = 0 ;
V_112 . V_55 = 0 ;
V_112 . V_90 = V_122 ;
V_112 . V_78 = V_4 -> V_78 ;
F_45 ( V_108 , & V_112 ) ;
return 0 ;
}
static int F_46 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_77 * V_78 ;
int V_104 ;
V_78 = F_38 ( & V_87 -> V_17 , sizeof( * V_78 ) , V_28 ) ;
if ( ! V_78 ) {
F_8 ( & V_87 -> V_17 , L_23 ) ;
return - V_29 ;
}
V_4 -> V_78 = V_78 ;
V_78 -> V_55 = 0 ;
V_78 -> V_126 = V_122 ;
V_78 -> V_17 = & V_87 -> V_17 ;
V_78 -> V_127 = F_30 ;
V_78 -> V_128 = F_32 ;
V_78 -> V_129 = F_33 ;
V_78 -> V_130 = F_34 ;
V_78 -> V_131 = F_35 ;
V_78 -> V_132 = L_24 ;
V_78 -> V_114 = V_115 ;
V_104 = F_47 ( V_78 ) ;
if ( V_104 ) {
F_8 ( & V_87 -> V_17 , L_25
L_26 , V_78 -> V_132 , V_104 ) ;
return V_104 ;
}
return 0 ;
}
static int F_48 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
int V_104 = F_49 ( V_4 -> V_78 ) ;
if ( V_104 ) {
F_8 ( & V_87 -> V_17 , L_27 ) ;
return V_104 ;
}
return 0 ;
}
static void F_50 ( struct V_133 * V_134 )
{
struct V_3 * V_135 ;
unsigned long V_136 ;
V_135 = F_51 ( V_134 ) ;
V_136 = F_18 ( V_135 -> V_56 + V_137 ) ;
V_136 |= 1 << V_134 -> V_138 ;
F_19 ( V_136 , V_135 -> V_56 + V_137 ) ;
}
static void F_52 ( struct V_133 * V_134 )
{
struct V_3 * V_135 ;
unsigned long V_136 ;
V_135 = F_51 ( V_134 ) ;
V_136 = F_18 ( V_135 -> V_56 + V_137 ) ;
V_136 &= ~ ( 1 << V_134 -> V_138 ) ;
F_19 ( V_136 , V_135 -> V_56 + V_137 ) ;
}
static T_3 F_53 ( int V_139 , void * V_37 )
{
struct V_140 * V_141 = V_37 ;
struct V_3 * V_135 = V_141 -> V_4 ;
int V_83 ;
V_83 = F_54 ( V_135 -> V_85 , V_141 -> V_136 ) ;
if ( ! V_83 )
return V_142 ;
F_55 ( V_83 ) ;
return V_143 ;
}
static int F_56 ( struct V_85 * V_144 , unsigned int V_83 ,
T_4 V_145 )
{
struct V_3 * V_135 = V_144 -> V_146 ;
F_57 ( V_83 , V_135 ) ;
F_58 ( V_83 , & V_147 ,
V_148 ) ;
F_59 ( V_83 , V_149 ) ;
return 0 ;
}
static int F_60 ( struct V_86 * V_87 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_140 * V_141 ;
int V_150 , V_139 , V_104 ;
V_141 = F_38 ( V_17 , sizeof( * V_141 ) * V_151 ,
V_28 ) ;
if ( ! V_141 ) {
F_8 ( V_17 , L_28 ) ;
return - V_29 ;
}
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
V_139 = F_61 ( V_17 -> V_96 , V_150 ) ;
if ( V_139 <= 0 ) {
F_8 ( V_17 , L_29 ) ;
return - V_27 ;
}
V_141 -> V_136 = V_150 ;
V_141 -> V_4 = V_4 ;
V_104 = F_62 ( V_17 , V_139 , F_53 ,
0 , F_63 ( V_17 ) , V_141 ++ ) ;
if ( V_104 ) {
F_8 ( V_17 , L_30 ) ;
return - V_84 ;
}
}
V_4 -> V_85 = F_64 ( V_17 -> V_96 ,
V_151 ,
& V_152 , V_4 ) ;
if ( ! V_4 -> V_85 ) {
F_8 ( V_17 , L_31 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_65 ( struct V_86 * V_87 )
{
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_3 * V_4 ;
struct V_153 * V_154 ;
int V_104 ;
if ( ! V_17 -> V_96 ) {
F_8 ( V_17 , L_32 ) ;
return - V_155 ;
}
V_4 = F_38 ( V_17 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 ) {
F_8 ( V_17 , L_33 ) ;
return - V_29 ;
}
V_154 = F_66 ( V_87 , V_156 , 0 ) ;
V_4 -> V_56 = F_67 ( & V_87 -> V_17 , V_154 ) ;
if ( F_68 ( V_4 -> V_56 ) )
return F_69 ( V_4 -> V_56 ) ;
V_104 = F_46 ( V_87 , V_4 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_43 ( V_87 , V_4 ) ;
if ( V_104 ) {
F_48 ( V_87 , V_4 ) ;
return V_104 ;
}
V_104 = F_60 ( V_87 , V_4 ) ;
if ( V_104 ) {
F_8 ( V_17 , L_34 ) ;
return V_104 ;
}
F_70 ( V_87 , V_4 ) ;
F_71 ( V_17 , L_35 ) ;
return 0 ;
}
static int T_5 F_72 ( void )
{
return F_73 ( & V_157 ) ;
}
static void T_6 F_74 ( void )
{
F_75 ( & V_157 ) ;
}
