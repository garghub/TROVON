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
for ( V_24 = 0 ; V_24 < F_6 ( V_25 ) ; V_24 ++ ) {
if ( F_7 ( V_12 , V_25 [ V_24 ] . V_26 , NULL ) )
V_22 ++ ;
}
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
sprintf ( V_20 , L_6 , V_12 -> V_8 , V_32 ) ;
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
sprintf ( V_21 , L_6 , V_12 -> V_8 , V_44 ) ;
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
static void F_17 ( struct V_54 * V_55 , unsigned V_56 ,
void T_2 * * V_57 , T_1 * V_58 ,
struct V_59 * * V_60 )
{
struct V_3 * V_4 ;
struct V_59 * V_61 ;
V_4 = F_18 ( V_55 -> V_17 ) ;
V_61 = V_4 -> V_62 -> V_63 ;
while ( ( V_56 >= V_61 -> V_64 ) &&
( ( V_61 -> V_64 + V_61 -> V_65 - 1 ) < V_56 ) )
V_61 ++ ;
* V_57 = V_4 -> V_66 + V_61 -> V_67 ;
* V_58 = V_56 - V_61 -> V_64 ;
if ( V_60 )
* V_60 = V_61 ;
if ( * V_58 * V_61 -> V_68 > V_69 )
* V_57 += 4 ;
}
static void F_19 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_46 , bool V_70 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
struct V_59 * V_60 ;
void T_2 * V_57 ;
T_1 V_71 , V_72 , V_37 , V_73 , V_74 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
for ( V_74 = 0 ; V_74 < V_4 -> V_7 [ V_46 ] . V_10 ; V_74 ++ ) {
F_17 ( V_4 -> V_55 , V_9 [ V_74 ] - V_4 -> V_62 -> V_75 ,
& V_57 , & V_73 , & V_60 ) ;
V_71 = ( 1 << V_60 -> V_68 ) - 1 ;
V_72 = V_73 * V_60 -> V_68 ;
V_37 = F_20 ( V_57 ) ;
V_37 &= ~ ( V_71 << V_72 ) ;
if ( V_70 )
V_37 |= V_4 -> V_7 [ V_46 ] . V_76 << V_72 ;
F_21 ( V_37 , V_57 ) ;
}
}
static int F_22 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_46 )
{
F_19 ( V_2 , V_6 , V_46 , true ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned V_6 , unsigned V_46 )
{
F_19 ( V_2 , V_6 , V_46 , false ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_77 * V_78 , unsigned V_58 , bool V_79 )
{
struct V_59 * V_60 ;
void T_2 * V_57 ;
T_1 V_37 , V_73 , V_71 , V_72 ;
F_17 ( V_78 -> V_55 , V_58 , & V_57 , & V_73 , & V_60 ) ;
V_71 = ( 1 << V_60 -> V_68 ) - 1 ;
V_72 = V_73 * V_60 -> V_68 ;
V_37 = F_20 ( V_57 ) ;
V_37 &= ~ ( V_71 << V_72 ) ;
if ( ! V_79 )
V_37 |= V_80 << V_72 ;
F_21 ( V_37 , V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_56 ,
unsigned long * V_81 , bool V_82 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
void T_2 * V_83 ;
enum V_84 V_36 = F_26 ( * V_81 ) ;
T_1 V_37 , V_85 , V_73 , V_71 , V_72 ;
T_1 V_86 , V_87 ;
V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 -> V_55 , V_56 - V_4 -> V_62 -> V_75 , & V_83 ,
& V_73 , & V_60 ) ;
switch ( V_36 ) {
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
F_27 ( 1 ) ;
return - V_27 ;
}
V_71 = ( 1 << V_85 ) - 1 ;
V_72 = V_73 * V_85 ;
V_37 = F_20 ( V_83 + V_87 ) ;
if ( V_82 ) {
V_86 = F_28 ( * V_81 ) ;
V_37 &= ~ ( V_71 << V_72 ) ;
V_37 |= ( V_86 << V_72 ) ;
F_21 ( V_37 , V_83 + V_87 ) ;
} else {
V_37 >>= V_72 ;
V_37 &= V_71 ;
* V_81 = F_11 ( V_36 , V_37 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_56 ,
unsigned long V_81 )
{
return F_25 ( V_2 , V_56 , & V_81 , true ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_56 ,
unsigned long * V_81 )
{
return F_25 ( V_2 , V_56 , V_81 , false ) ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned V_46 , unsigned long V_81 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
unsigned int V_74 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
for ( V_74 = 0 ; V_74 < V_4 -> V_7 [ V_46 ] . V_10 ; V_74 ++ )
F_29 ( V_2 , V_9 [ V_74 ] , V_81 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned int V_46 , unsigned long * V_81 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
F_30 ( V_2 , V_9 [ 0 ] , V_81 ) ;
return 0 ;
}
static void F_33 ( struct V_54 * V_55 , unsigned V_58 , int V_35 )
{
void T_2 * V_57 ;
T_1 V_73 , V_37 ;
F_17 ( V_55 , V_58 , & V_57 , & V_73 , NULL ) ;
V_37 = F_20 ( V_57 + V_100 ) ;
V_37 &= ~ ( 1 << V_73 ) ;
if ( V_35 )
V_37 |= 1 << V_73 ;
F_21 ( V_37 , V_57 + V_100 ) ;
}
static int F_34 ( struct V_54 * V_55 , unsigned V_58 )
{
void T_2 * V_57 ;
T_1 V_73 , V_37 ;
F_17 ( V_55 , V_58 , & V_57 , & V_73 , NULL ) ;
V_37 = F_20 ( V_57 + V_100 ) ;
V_37 >>= V_73 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_35 ( struct V_54 * V_55 , unsigned V_58 )
{
return F_36 ( V_55 -> V_75 + V_58 ) ;
}
static int F_37 ( struct V_54 * V_55 , unsigned V_58 ,
int V_35 )
{
F_33 ( V_55 , V_58 , V_35 ) ;
return F_38 ( V_55 -> V_75 + V_58 ) ;
}
static int T_3 F_39 ( struct V_101 * V_102 ,
struct V_11 * V_103 , struct V_104 * V_105 ,
unsigned int * * V_106 , unsigned int * V_107 )
{
struct V_16 * V_17 = & V_102 -> V_17 ;
struct V_108 * V_109 ;
struct V_110 const * V_111 = V_105 -> V_9 ;
unsigned int V_24 = 0 , V_74 ;
const char * V_112 ;
* V_107 = F_40 ( V_103 , L_9 ) ;
if ( * V_107 < 0 ) {
F_8 ( V_17 , L_10 , V_103 -> V_8 ) ;
return - V_27 ;
}
* V_106 = F_41 ( V_17 , * V_107 * sizeof( * * V_106 ) , V_28 ) ;
if ( ! * V_106 ) {
F_8 ( V_17 , L_11 ) ;
return - V_29 ;
}
F_42 (cfg_np, L_9 , prop, pin_name) {
for ( V_74 = 0 ; V_74 < V_105 -> V_107 ; V_74 ++ ) {
if ( V_111 [ V_74 ] . V_8 ) {
if ( ! strcmp ( V_112 , V_111 [ V_74 ] . V_8 ) ) {
( * V_106 ) [ V_24 ++ ] = V_111 [ V_74 ] . V_113 ;
break;
}
}
}
if ( V_74 == V_105 -> V_107 ) {
F_8 ( V_17 , L_12 ,
V_112 , V_103 -> V_8 ) ;
F_43 ( V_17 , * V_106 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int T_3 F_44 ( struct V_101 * V_102 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_102 -> V_17 ;
struct V_11 * V_114 = V_17 -> V_115 ;
struct V_11 * V_103 ;
struct V_116 * V_52 , * V_117 ;
struct V_118 * V_119 , * V_76 ;
unsigned * V_106 ;
unsigned int V_107 , V_120 , V_121 = 0 ;
char * V_20 , * V_21 ;
int V_122 ;
V_120 = F_45 ( V_114 ) ;
if ( ! V_120 )
return - V_27 ;
V_52 = F_41 ( V_17 , V_120 * sizeof( * V_52 ) , V_28 ) ;
if ( ! V_52 ) {
F_8 ( V_17 , L_13 ) ;
return - V_27 ;
}
V_117 = V_52 ;
V_119 = F_41 ( V_17 , V_120 * sizeof( * V_119 ) , V_28 ) ;
if ( ! V_119 ) {
F_8 ( V_17 , L_14 ) ;
return - V_27 ;
}
V_76 = V_119 ;
F_46 (dev_np, cfg_np) {
T_1 V_47 ;
if ( F_7 ( V_103 , L_15 , NULL ) )
continue;
V_122 = F_39 ( V_102 , V_103 ,
& V_4 -> V_105 , & V_106 , & V_107 ) ;
if ( V_122 )
return V_122 ;
V_20 = F_41 ( V_17 , strlen ( V_103 -> V_8 ) + V_30 ,
V_28 ) ;
if ( ! V_20 ) {
F_8 ( V_17 , L_5 ) ;
return - V_29 ;
}
sprintf ( V_20 , L_6 , V_103 -> V_8 , V_32 ) ;
V_117 -> V_8 = V_20 ;
V_117 -> V_9 = V_106 ;
V_117 -> V_10 = V_107 ;
F_10 ( V_103 , L_1 , & V_47 ) ;
V_117 -> V_76 = V_47 ;
V_117 ++ ;
if ( ! F_7 ( V_103 , L_1 , NULL ) )
continue;
V_21 = F_41 ( V_17 , strlen ( V_103 -> V_8 ) + V_42 ,
V_28 ) ;
if ( ! V_21 ) {
F_8 ( V_17 , L_8 ) ;
return - V_29 ;
}
sprintf ( V_21 , L_6 , V_103 -> V_8 , V_44 ) ;
V_76 -> V_8 = V_21 ;
V_76 -> V_52 = F_41 ( V_17 , sizeof( char * ) , V_28 ) ;
if ( ! V_76 -> V_52 ) {
F_8 ( V_17 , L_16
L_17 ) ;
return - V_29 ;
}
V_76 -> V_52 [ 0 ] = V_20 ;
V_76 -> V_53 = 1 ;
V_76 ++ ;
V_121 ++ ;
}
V_4 -> V_7 = V_52 ;
V_4 -> V_5 = V_120 ;
V_4 -> V_51 = V_119 ;
V_4 -> V_50 = V_121 ;
return 0 ;
}
static int T_3 F_47 ( struct V_101 * V_102 ,
struct V_3 * V_4 )
{
struct V_104 * V_123 = & V_4 -> V_105 ;
struct V_110 * V_124 , * V_111 ;
struct V_59 * V_125 ;
char * V_126 ;
int V_56 , V_60 , V_122 ;
V_123 -> V_8 = L_18 ;
V_123 -> V_127 = V_128 ;
V_123 -> V_129 = & V_130 ;
V_123 -> V_131 = & V_132 ;
V_123 -> V_133 = & V_134 ;
V_124 = F_41 ( & V_102 -> V_17 , sizeof( * V_124 ) *
V_4 -> V_62 -> V_65 , V_28 ) ;
if ( ! V_124 ) {
F_8 ( & V_102 -> V_17 , L_19 ) ;
return - V_29 ;
}
V_123 -> V_9 = V_124 ;
V_123 -> V_107 = V_4 -> V_62 -> V_65 ;
V_123 -> V_107 = V_4 -> V_62 -> V_65 ;
for ( V_56 = 0 , V_111 = V_124 ; V_56 < V_123 -> V_107 ; V_56 ++ , V_111 ++ )
V_111 -> V_113 = V_56 + V_4 -> V_62 -> V_75 ;
V_126 = F_41 ( & V_102 -> V_17 , sizeof( char ) * V_135 *
V_4 -> V_62 -> V_65 , V_28 ) ;
if ( ! V_126 ) {
F_8 ( & V_102 -> V_17 , L_20 ) ;
return - V_29 ;
}
for ( V_60 = 0 ; V_60 < V_4 -> V_62 -> V_136 ; V_60 ++ ) {
V_125 = & V_4 -> V_62 -> V_63 [ V_60 ] ;
for ( V_56 = 0 ; V_56 < V_125 -> V_65 ; V_56 ++ ) {
sprintf ( V_126 , L_21 , V_125 -> V_8 , V_56 ) ;
V_111 = V_124 + V_125 -> V_64 + V_56 ;
V_111 -> V_8 = V_126 ;
V_126 += V_135 ;
}
}
V_4 -> V_137 = F_48 ( V_123 , & V_102 -> V_17 , V_4 ) ;
if ( ! V_4 -> V_137 ) {
F_8 ( & V_102 -> V_17 , L_22 ) ;
return - V_27 ;
}
V_4 -> V_138 . V_8 = L_23 ;
V_4 -> V_138 . V_139 = 0 ;
V_4 -> V_138 . V_75 = V_4 -> V_62 -> V_75 ;
V_4 -> V_138 . V_107 = V_4 -> V_62 -> V_65 ;
V_4 -> V_138 . V_55 = V_4 -> V_55 ;
F_49 ( V_4 -> V_137 , & V_4 -> V_138 ) ;
V_122 = F_44 ( V_102 , V_4 ) ;
if ( V_122 ) {
F_50 ( V_4 -> V_137 ) ;
return V_122 ;
}
return 0 ;
}
static int T_3 F_51 ( struct V_101 * V_102 ,
struct V_3 * V_4 )
{
struct V_54 * V_55 ;
int V_122 ;
V_55 = F_41 ( & V_102 -> V_17 , sizeof( * V_55 ) , V_28 ) ;
if ( ! V_55 ) {
F_8 ( & V_102 -> V_17 , L_24 ) ;
return - V_29 ;
}
V_4 -> V_55 = V_55 ;
V_55 -> V_75 = V_4 -> V_62 -> V_75 ;
V_55 -> V_140 = V_4 -> V_62 -> V_65 ;
V_55 -> V_17 = & V_102 -> V_17 ;
V_55 -> V_82 = F_33 ;
V_55 -> V_141 = F_34 ;
V_55 -> V_142 = F_35 ;
V_55 -> V_143 = F_37 ;
V_55 -> V_144 = V_4 -> V_62 -> V_144 ;
V_55 -> V_127 = V_128 ;
V_122 = F_52 ( V_55 ) ;
if ( V_122 ) {
F_8 ( & V_102 -> V_17 , L_25
L_26 , V_55 -> V_144 , V_122 ) ;
return V_122 ;
}
return 0 ;
}
static int T_3 F_53 ( struct V_101 * V_102 ,
struct V_3 * V_4 )
{
int V_122 = F_54 ( V_4 -> V_55 ) ;
if ( V_122 ) {
F_8 ( & V_102 -> V_17 , L_27 ) ;
return V_122 ;
}
return 0 ;
}
static struct V_145 * F_55 (
struct V_101 * V_102 )
{
int V_139 ;
const struct V_146 * V_147 ;
const struct V_11 * V_148 = V_102 -> V_17 . V_115 ;
V_139 = F_56 ( V_102 -> V_17 . V_115 , L_28 ) ;
if ( V_139 < 0 ) {
F_8 ( & V_102 -> V_17 , L_29 ) ;
return NULL ;
}
V_147 = F_57 ( V_149 , V_148 ) ;
return (struct V_145 * ) V_147 -> V_37 + V_139 ;
}
static int T_3 F_58 ( struct V_101 * V_102 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 = & V_102 -> V_17 ;
struct V_145 * V_62 ;
struct V_150 * V_151 ;
int V_122 ;
if ( ! V_17 -> V_115 ) {
F_8 ( V_17 , L_30 ) ;
return - V_152 ;
}
V_62 = F_55 ( V_102 ) ;
if ( ! V_62 ) {
F_8 ( & V_102 -> V_17 , L_31 ) ;
return - V_27 ;
}
V_4 = F_41 ( V_17 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 ) {
F_8 ( V_17 , L_32
L_33 ) ;
return - V_29 ;
}
V_4 -> V_62 = V_62 ;
V_4 -> V_17 = V_17 ;
V_151 = F_59 ( V_102 , V_153 , 0 ) ;
if ( ! V_151 ) {
F_8 ( V_17 , L_34 ) ;
return - V_154 ;
}
V_4 -> V_66 = F_60 ( & V_102 -> V_17 , V_151 ) ;
if ( ! V_4 -> V_66 ) {
F_8 ( V_17 , L_35 ) ;
return - V_152 ;
}
V_151 = F_59 ( V_102 , V_155 , 0 ) ;
if ( V_151 )
V_4 -> V_156 = V_151 -> V_157 ;
V_122 = F_51 ( V_102 , V_4 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_47 ( V_102 , V_4 ) ;
if ( V_122 ) {
F_53 ( V_102 , V_4 ) ;
return V_122 ;
}
if ( V_62 -> V_158 )
V_62 -> V_158 ( V_4 ) ;
if ( V_62 -> V_159 )
V_62 -> V_159 ( V_4 ) ;
F_61 ( V_102 , V_4 ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_160 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_160 ) ;
}
