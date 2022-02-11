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
static int F_21 ( struct V_1 * V_2 ,
struct V_58 * V_59 , unsigned V_60 , bool V_61 )
{
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned long * V_38 ,
unsigned V_40 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
enum V_63 V_36 ;
T_1 V_64 ;
T_1 V_37 ;
int V_65 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
for ( V_65 = 0 ; V_65 < V_40 ; V_65 ++ ) {
V_36 = F_23 ( V_38 [ V_65 ] ) ;
V_64 = F_24 ( V_38 [ V_65 ] ) ;
switch ( V_36 ) {
case V_66 :
V_37 = F_18 ( V_55 + V_67 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
if ( V_64 )
V_37 |= ( 1 << V_62 ) ;
F_19 ( V_37 , V_55 + V_67 ) ;
V_37 = F_18 ( V_55 + V_68 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
if ( V_64 == 2 )
V_37 |= ( 1 << V_62 ) ;
F_19 ( V_37 , V_55 + V_68 ) ;
break;
case V_69 :
V_37 = F_18 ( V_55 + V_70 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_64 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_70 ) ;
V_64 >>= 1 ;
V_37 = F_18 ( V_55 + V_71 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_64 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_71 ) ;
break;
case V_72 :
V_37 = F_18 ( V_55 + V_73 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_64 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_73 ) ;
break;
case V_74 :
V_37 = F_18 ( V_55 + V_75 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_64 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_75 ) ;
break;
default:
F_25 ( 1 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned long * V_76 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
enum V_63 V_36 = F_23 ( * V_76 ) ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
switch ( V_36 ) {
case V_66 :
V_37 = F_18 ( V_55 + V_67 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
if ( ! V_37 )
* V_76 = 0 ;
else
* V_76 = ( ( F_18 ( V_55 + V_68 ) >> V_62 ) & 1 ) + 1 ;
break;
case V_69 :
V_37 = F_18 ( V_55 + V_70 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
* V_76 = V_37 ;
V_37 = F_18 ( V_55 + V_71 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
* V_76 |= ( V_37 << 1 ) ;
break;
case V_72 :
V_37 = F_18 ( V_55 + V_73 ) ;
* V_76 = ( V_37 >> V_62 ) & 1 ;
break;
case V_74 :
V_37 = F_18 ( V_55 + V_75 ) ;
* V_76 = ( V_37 >> V_62 ) & 1 ;
break;
default:
F_25 ( 1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned V_46 , unsigned long * V_38 ,
unsigned V_40 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
unsigned int V_77 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
for ( V_77 = 0 ; V_77 < V_4 -> V_7 [ V_46 ] . V_10 ; V_77 ++ )
F_22 ( V_2 , V_9 [ V_77 ] , V_38 ,
V_40 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned int V_46 , unsigned long * V_76 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
F_26 ( V_2 , V_9 [ 0 ] , V_76 ) ;
return 0 ;
}
static void F_29 ( struct V_78 * V_79 , unsigned V_60 , int V_35 )
{
struct V_3 * V_4 = F_30 ( V_79 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_80 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
if ( V_35 )
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_80 ) ;
}
static int F_31 ( struct V_78 * V_79 , unsigned V_60 )
{
struct V_3 * V_4 = F_30 ( V_79 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_81 ) ;
V_37 >>= V_60 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_32 ( struct V_78 * V_79 , unsigned V_60 )
{
struct V_3 * V_4 = F_30 ( V_79 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_82 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
F_19 ( V_37 , V_55 + V_82 ) ;
V_37 = F_18 ( V_55 + V_83 ) ;
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_83 ) ;
return 0 ;
}
static int F_33 ( struct V_78 * V_79 , unsigned V_60 ,
int V_35 )
{
struct V_3 * V_4 = F_30 ( V_79 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
F_29 ( V_79 , V_60 , V_35 ) ;
V_37 = F_18 ( V_55 + V_83 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
F_19 ( V_37 , V_55 + V_83 ) ;
V_37 = F_18 ( V_55 + V_82 ) ;
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_82 ) ;
return 0 ;
}
static int F_34 ( struct V_78 * V_79 , unsigned V_60 )
{
struct V_3 * V_4 = F_30 ( V_79 -> V_17 ) ;
unsigned int V_84 ;
if ( V_60 < 16 || V_60 > 23 )
return - V_85 ;
if ( ! V_4 -> V_86 )
return - V_85 ;
V_84 = F_35 ( V_4 -> V_86 , V_60 - 16 ) ;
return V_84 ? : - V_85 ;
}
static int F_36 ( struct V_87 * V_88 ,
struct V_11 * V_89 , unsigned int * * V_90 ,
unsigned int * V_91 )
{
struct V_16 * V_17 = & V_88 -> V_17 ;
struct V_92 * V_93 ;
V_93 = F_7 ( V_89 , L_9 , NULL ) ;
if ( ! V_93 )
return - V_94 ;
* V_91 = V_93 -> V_95 / sizeof( unsigned long ) ;
if ( ! * V_91 ) {
F_8 ( V_17 , L_10 , V_89 -> V_8 ) ;
return - V_27 ;
}
* V_90 = F_37 ( V_17 , * V_91 * sizeof( * * V_90 ) , V_28 ) ;
if ( ! * V_90 ) {
F_8 ( V_17 , L_11 ) ;
return - V_29 ;
}
return F_38 ( V_89 , L_9 ,
* V_90 , * V_91 ) ;
}
static int F_39 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_88 -> V_17 ;
struct V_11 * V_96 = V_17 -> V_97 ;
struct V_11 * V_89 ;
struct V_98 * V_52 , * V_99 ;
struct V_100 * V_101 , * V_102 ;
unsigned * V_90 ;
unsigned int V_91 , V_103 , V_104 = 0 ;
char * V_20 , * V_21 ;
int V_105 ;
V_103 = F_40 ( V_96 ) ;
if ( ! V_103 )
return - V_27 ;
V_52 = F_37 ( V_17 , V_103 * sizeof( * V_52 ) , V_28 ) ;
if ( ! V_52 ) {
F_8 ( V_17 , L_12 ) ;
return - V_27 ;
}
V_99 = V_52 ;
V_101 = F_37 ( V_17 , V_103 * sizeof( * V_101 ) , V_28 ) ;
if ( ! V_101 ) {
F_8 ( V_17 , L_13 ) ;
return - V_27 ;
}
V_102 = V_101 ;
F_41 (dev_np, cfg_np) {
T_1 V_47 ;
V_105 = F_36 ( V_88 , V_89 ,
& V_90 , & V_91 ) ;
if ( V_105 ) {
V_20 = NULL ;
goto V_106;
}
V_20 = F_37 ( V_17 , strlen ( V_89 -> V_8 ) + V_30 ,
V_28 ) ;
if ( ! V_20 ) {
F_8 ( V_17 , L_5 ) ;
return - V_29 ;
}
snprintf ( V_20 , strlen ( V_89 -> V_8 ) + 4 , L_6 , V_89 -> V_8 ,
V_32 ) ;
V_99 -> V_8 = V_20 ;
V_99 -> V_9 = V_90 ;
V_99 -> V_10 = V_91 ;
V_99 ++ ;
V_106:
V_105 = F_10 ( V_89 , L_1 ,
& V_47 ) ;
if ( V_105 )
continue;
V_21 = F_37 ( V_17 , strlen ( V_89 -> V_8 ) + V_42 ,
V_28 ) ;
if ( ! V_21 ) {
F_8 ( V_17 , L_8 ) ;
return - V_29 ;
}
snprintf ( V_21 , strlen ( V_89 -> V_8 ) + 4 , L_6 , V_89 -> V_8 ,
V_44 ) ;
V_102 -> V_8 = V_21 ;
V_102 -> V_52 = F_37 ( V_17 , sizeof( char * ) , V_28 ) ;
if ( ! V_102 -> V_52 ) {
F_8 ( V_17 , L_14
L_15 ) ;
return - V_29 ;
}
V_102 -> V_52 [ 0 ] = V_20 ;
V_102 -> V_53 = V_20 ? 1 : 0 ;
V_102 -> V_47 = V_47 ;
V_102 ++ ;
V_104 ++ ;
}
V_4 -> V_7 = V_52 ;
V_4 -> V_5 = V_103 ;
V_4 -> V_51 = V_101 ;
V_4 -> V_50 = V_104 ;
return 0 ;
}
static int F_42 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_88 -> V_17 ;
struct V_107 * V_108 ;
struct V_1 * V_109 ;
struct V_110 * V_111 , * V_112 ;
struct V_58 V_113 ;
char * V_114 ;
int V_62 , V_105 ;
V_108 = F_37 ( V_17 , sizeof( * V_108 ) , V_28 ) ;
if ( ! V_108 ) {
F_8 ( V_17 , L_16 ) ;
return - V_29 ;
}
V_108 -> V_8 = L_17 ;
V_108 -> V_115 = V_116 ;
V_108 -> V_117 = & V_118 ;
V_108 -> V_119 = & V_120 ;
V_108 -> V_121 = & V_122 ;
V_111 = F_37 ( & V_88 -> V_17 , sizeof( * V_111 ) *
V_123 , V_28 ) ;
if ( ! V_111 ) {
F_8 ( & V_88 -> V_17 , L_18 ) ;
return - V_29 ;
}
V_108 -> V_9 = V_111 ;
V_108 -> V_91 = V_123 ;
for ( V_62 = 0 , V_112 = V_111 ; V_62 < V_108 -> V_91 ; V_62 ++ , V_112 ++ )
V_112 -> V_124 = V_62 ;
V_114 = F_37 ( & V_88 -> V_17 , sizeof( char ) * V_125 *
V_108 -> V_91 , V_28 ) ;
if ( ! V_114 ) {
F_8 ( & V_88 -> V_17 , L_19 ) ;
return - V_29 ;
}
for ( V_62 = 0 ; V_62 < V_108 -> V_91 ; V_62 ++ ) {
snprintf ( V_114 , 6 , L_20 , V_62 ) ;
V_112 = V_111 + V_62 ;
V_112 -> V_8 = V_114 ;
V_114 += V_125 ;
}
V_105 = F_39 ( V_88 , V_4 ) ;
if ( V_105 )
return V_105 ;
V_109 = F_43 ( V_108 , & V_88 -> V_17 , V_4 ) ;
if ( ! V_109 ) {
F_8 ( & V_88 -> V_17 , L_21 ) ;
return - V_27 ;
}
V_113 . V_8 = L_22 ;
V_113 . V_126 = 0 ;
V_113 . V_55 = 0 ;
V_113 . V_91 = V_123 ;
V_113 . V_79 = V_4 -> V_79 ;
F_44 ( V_109 , & V_113 ) ;
return 0 ;
}
static int F_45 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
struct V_78 * V_79 ;
int V_105 ;
V_79 = F_37 ( & V_88 -> V_17 , sizeof( * V_79 ) , V_28 ) ;
if ( ! V_79 ) {
F_8 ( & V_88 -> V_17 , L_23 ) ;
return - V_29 ;
}
V_4 -> V_79 = V_79 ;
V_79 -> V_55 = 0 ;
V_79 -> V_127 = V_123 ;
V_79 -> V_17 = & V_88 -> V_17 ;
V_79 -> V_128 = F_29 ;
V_79 -> V_129 = F_31 ;
V_79 -> V_130 = F_32 ;
V_79 -> V_131 = F_33 ;
V_79 -> V_132 = F_34 ;
V_79 -> V_133 = L_24 ;
V_79 -> V_115 = V_116 ;
V_105 = F_46 ( V_79 ) ;
if ( V_105 ) {
F_8 ( & V_88 -> V_17 , L_25
L_26 , V_79 -> V_133 , V_105 ) ;
return V_105 ;
}
return 0 ;
}
static int F_47 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
int V_105 = F_48 ( V_4 -> V_79 ) ;
if ( V_105 ) {
F_8 ( & V_88 -> V_17 , L_27 ) ;
return V_105 ;
}
return 0 ;
}
static void F_49 ( struct V_134 * V_135 )
{
struct V_3 * V_136 ;
unsigned long V_137 ;
V_136 = F_50 ( V_135 ) ;
V_137 = F_18 ( V_136 -> V_56 + V_138 ) ;
V_137 |= 1 << V_135 -> V_139 ;
F_19 ( V_137 , V_136 -> V_56 + V_138 ) ;
}
static void F_51 ( struct V_134 * V_135 )
{
struct V_3 * V_136 ;
unsigned long V_137 ;
V_136 = F_50 ( V_135 ) ;
V_137 = F_18 ( V_136 -> V_56 + V_138 ) ;
V_137 &= ~ ( 1 << V_135 -> V_139 ) ;
F_19 ( V_137 , V_136 -> V_56 + V_138 ) ;
}
static T_3 F_52 ( int V_140 , void * V_37 )
{
struct V_141 * V_142 = V_37 ;
struct V_3 * V_136 = V_142 -> V_4 ;
int V_84 ;
V_84 = F_53 ( V_136 -> V_86 , V_142 -> V_137 ) ;
if ( ! V_84 )
return V_143 ;
F_54 ( V_84 ) ;
return V_144 ;
}
static int F_55 ( struct V_86 * V_145 , unsigned int V_84 ,
T_4 V_146 )
{
struct V_3 * V_136 = V_145 -> V_147 ;
F_56 ( V_84 , V_136 ) ;
F_57 ( V_84 , & V_148 ,
V_149 ) ;
F_58 ( V_84 , V_150 ) ;
return 0 ;
}
static int F_59 ( struct V_87 * V_88 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_88 -> V_17 ;
struct V_141 * V_142 ;
int V_65 , V_140 , V_105 ;
V_142 = F_37 ( V_17 , sizeof( * V_142 ) * V_151 ,
V_28 ) ;
if ( ! V_142 ) {
F_8 ( V_17 , L_28 ) ;
return - V_29 ;
}
for ( V_65 = 0 ; V_65 < V_151 ; V_65 ++ ) {
V_140 = F_60 ( V_17 -> V_97 , V_65 ) ;
if ( V_140 <= 0 ) {
F_8 ( V_17 , L_29 ) ;
return - V_27 ;
}
V_142 -> V_137 = V_65 ;
V_142 -> V_4 = V_4 ;
V_105 = F_61 ( V_17 , V_140 , F_52 ,
0 , F_62 ( V_17 ) , V_142 ++ ) ;
if ( V_105 ) {
F_8 ( V_17 , L_30 ) ;
return - V_85 ;
}
}
V_4 -> V_86 = F_63 ( V_17 -> V_97 ,
V_151 ,
& V_152 , V_4 ) ;
if ( ! V_4 -> V_86 ) {
F_8 ( V_17 , L_31 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_64 ( struct V_87 * V_88 )
{
struct V_16 * V_17 = & V_88 -> V_17 ;
struct V_3 * V_4 ;
struct V_153 * V_154 ;
int V_105 ;
if ( ! V_17 -> V_97 ) {
F_8 ( V_17 , L_32 ) ;
return - V_155 ;
}
V_4 = F_37 ( V_17 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 ) {
F_8 ( V_17 , L_33 ) ;
return - V_29 ;
}
V_154 = F_65 ( V_88 , V_156 , 0 ) ;
V_4 -> V_56 = F_66 ( & V_88 -> V_17 , V_154 ) ;
if ( F_67 ( V_4 -> V_56 ) )
return F_68 ( V_4 -> V_56 ) ;
V_105 = F_45 ( V_88 , V_4 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_42 ( V_88 , V_4 ) ;
if ( V_105 ) {
F_47 ( V_88 , V_4 ) ;
return V_105 ;
}
V_105 = F_59 ( V_88 , V_4 ) ;
if ( V_105 ) {
F_8 ( V_17 , L_34 ) ;
return V_105 ;
}
F_69 ( V_88 , V_4 ) ;
F_70 ( V_17 , L_35 ) ;
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_157 ) ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_157 ) ;
}
