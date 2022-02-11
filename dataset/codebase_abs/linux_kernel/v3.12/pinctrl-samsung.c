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
}
static void F_20 ( struct V_4 * V_5 , unsigned V_9 ,
unsigned V_49 , bool V_68 )
{
struct V_6 * V_7 ;
const unsigned int * V_12 ;
struct V_1 * V_60 ;
void T_2 * V_58 ;
T_1 V_69 , V_70 , V_40 , V_71 , V_72 ;
unsigned long V_73 ;
V_7 = F_4 ( V_5 ) ;
V_12 = V_7 -> V_10 [ V_49 ] . V_12 ;
for ( V_72 = 0 ; V_72 < V_7 -> V_10 [ V_49 ] . V_13 ; V_72 ++ ) {
struct V_74 * type ;
F_19 ( V_7 , V_12 [ V_72 ] - V_7 -> V_62 -> V_75 ,
& V_58 , & V_71 , & V_60 ) ;
type = V_60 -> type ;
V_69 = ( 1 << type -> V_76 [ V_77 ] ) - 1 ;
V_70 = V_71 * type -> V_76 [ V_77 ] ;
if ( V_70 >= 32 ) {
V_70 -= 32 ;
V_58 += 4 ;
}
F_21 ( & V_60 -> V_78 , V_73 ) ;
V_40 = F_22 ( V_58 + type -> V_79 [ V_77 ] ) ;
V_40 &= ~ ( V_69 << V_70 ) ;
if ( V_68 )
V_40 |= V_7 -> V_10 [ V_49 ] . V_80 << V_70 ;
F_23 ( V_40 , V_58 + type -> V_79 [ V_77 ] ) ;
F_24 ( & V_60 -> V_78 , V_73 ) ;
}
}
static int F_25 ( struct V_4 * V_5 , unsigned V_9 ,
unsigned V_49 )
{
F_20 ( V_5 , V_9 , V_49 , true ) ;
return 0 ;
}
static void F_26 ( struct V_4 * V_5 ,
unsigned V_9 , unsigned V_49 )
{
F_20 ( V_5 , V_9 , V_49 , false ) ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_81 * V_82 , unsigned V_59 , bool V_83 )
{
struct V_74 * type ;
struct V_1 * V_60 ;
struct V_6 * V_7 ;
void T_2 * V_58 ;
T_1 V_40 , V_71 , V_69 , V_70 ;
unsigned long V_73 ;
V_60 = F_1 ( V_82 -> V_3 ) ;
type = V_60 -> type ;
V_7 = F_4 ( V_5 ) ;
V_71 = V_59 - V_60 -> V_64 ;
V_58 = V_7 -> V_66 + V_60 -> V_67 +
type -> V_79 [ V_77 ] ;
V_69 = ( 1 << type -> V_76 [ V_77 ] ) - 1 ;
V_70 = V_71 * type -> V_76 [ V_77 ] ;
if ( V_70 >= 32 ) {
V_70 -= 32 ;
V_58 += 4 ;
}
F_21 ( & V_60 -> V_78 , V_73 ) ;
V_40 = F_22 ( V_58 ) ;
V_40 &= ~ ( V_69 << V_70 ) ;
if ( ! V_83 )
V_40 |= V_84 << V_70 ;
F_23 ( V_40 , V_58 ) ;
F_24 ( & V_60 -> V_78 , V_73 ) ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_85 , bool V_86 )
{
struct V_6 * V_7 ;
struct V_74 * type ;
struct V_1 * V_60 ;
void T_2 * V_87 ;
enum V_88 V_39 = F_29 ( * V_85 ) ;
T_1 V_40 , V_89 , V_71 , V_69 , V_70 ;
T_1 V_90 , V_91 ;
unsigned long V_73 ;
V_7 = F_4 ( V_5 ) ;
F_19 ( V_7 , V_57 - V_7 -> V_62 -> V_75 , & V_87 ,
& V_71 , & V_60 ) ;
type = V_60 -> type ;
if ( V_39 >= V_92 || ! type -> V_76 [ V_39 ] )
return - V_30 ;
V_89 = type -> V_76 [ V_39 ] ;
V_91 = type -> V_79 [ V_39 ] ;
F_21 ( & V_60 -> V_78 , V_73 ) ;
V_69 = ( 1 << V_89 ) - 1 ;
V_70 = V_71 * V_89 ;
V_40 = F_22 ( V_87 + V_91 ) ;
if ( V_86 ) {
V_90 = F_30 ( * V_85 ) ;
V_40 &= ~ ( V_69 << V_70 ) ;
V_40 |= ( V_90 << V_70 ) ;
F_23 ( V_40 , V_87 + V_91 ) ;
} else {
V_40 >>= V_70 ;
V_40 &= V_69 ;
* V_85 = F_13 ( V_39 , V_40 ) ;
}
F_24 ( & V_60 -> V_78 , V_73 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_41 , unsigned V_43 )
{
int V_93 , V_94 ;
for ( V_93 = 0 ; V_93 < V_43 ; V_93 ++ ) {
V_94 = F_28 ( V_5 , V_57 , & V_41 [ V_93 ] , true ) ;
if ( V_94 < 0 )
return V_94 ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 , unsigned int V_57 ,
unsigned long * V_85 )
{
return F_28 ( V_5 , V_57 , V_85 , false ) ;
}
static int F_33 ( struct V_4 * V_5 ,
unsigned V_49 , unsigned long * V_41 ,
unsigned V_43 )
{
struct V_6 * V_7 ;
const unsigned int * V_12 ;
unsigned int V_72 ;
V_7 = F_4 ( V_5 ) ;
V_12 = V_7 -> V_10 [ V_49 ] . V_12 ;
for ( V_72 = 0 ; V_72 < V_7 -> V_10 [ V_49 ] . V_13 ; V_72 ++ )
F_31 ( V_5 , V_12 [ V_72 ] , V_41 , V_43 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
unsigned int V_49 , unsigned long * V_85 )
{
struct V_6 * V_7 ;
const unsigned int * V_12 ;
V_7 = F_4 ( V_5 ) ;
V_12 = V_7 -> V_10 [ V_49 ] . V_12 ;
F_32 ( V_5 , V_12 [ 0 ] , V_85 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned V_59 , int V_38 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_74 * type = V_60 -> type ;
unsigned long V_73 ;
void T_2 * V_58 ;
T_1 V_40 ;
V_58 = V_60 -> V_7 -> V_66 + V_60 -> V_67 ;
F_21 ( & V_60 -> V_78 , V_73 ) ;
V_40 = F_22 ( V_58 + type -> V_79 [ V_95 ] ) ;
V_40 &= ~ ( 1 << V_59 ) ;
if ( V_38 )
V_40 |= 1 << V_59 ;
F_23 ( V_40 , V_58 + type -> V_79 [ V_95 ] ) ;
F_24 ( & V_60 -> V_78 , V_73 ) ;
}
static int F_36 ( struct V_2 * V_3 , unsigned V_59 )
{
void T_2 * V_58 ;
T_1 V_40 ;
struct V_1 * V_60 = F_1 ( V_3 ) ;
struct V_74 * type = V_60 -> type ;
V_58 = V_60 -> V_7 -> V_66 + V_60 -> V_67 ;
V_40 = F_22 ( V_58 + type -> V_79 [ V_95 ] ) ;
V_40 >>= V_59 ;
V_40 &= 1 ;
return V_40 ;
}
static int F_37 ( struct V_2 * V_3 , unsigned V_59 )
{
return F_38 ( V_3 -> V_75 + V_59 ) ;
}
static int F_39 ( struct V_2 * V_3 , unsigned V_59 ,
int V_38 )
{
F_35 ( V_3 , V_59 , V_38 ) ;
return F_40 ( V_3 -> V_75 + V_59 ) ;
}
static int F_41 ( struct V_2 * V_3 , unsigned V_59 )
{
struct V_1 * V_60 = F_1 ( V_3 ) ;
unsigned int V_96 ;
if ( ! V_60 -> V_97 )
return - V_98 ;
V_96 = F_42 ( V_60 -> V_97 , V_59 ) ;
return ( V_96 ) ? : - V_98 ;
}
static int F_43 ( struct V_99 * V_100 ,
struct V_14 * V_101 ,
struct V_102 * V_103 ,
unsigned int * * V_104 ,
unsigned int * V_105 )
{
struct V_19 * V_20 = & V_100 -> V_20 ;
struct V_106 * V_107 ;
struct V_108 const * V_109 = V_103 -> V_12 ;
unsigned int V_27 = 0 , V_72 ;
const char * V_110 ;
* V_105 = F_44 ( V_101 , L_9 ) ;
if ( F_45 ( * V_105 ) ) {
F_10 ( V_20 , L_10 , V_101 -> V_11 ) ;
return - V_30 ;
}
* V_104 = F_46 ( V_20 , * V_105 * sizeof( * * V_104 ) , V_31 ) ;
if ( ! * V_104 ) {
F_10 ( V_20 , L_11 ) ;
return - V_32 ;
}
F_47 (cfg_np, L_9 , prop, pin_name) {
for ( V_72 = 0 ; V_72 < V_103 -> V_105 ; V_72 ++ ) {
if ( V_109 [ V_72 ] . V_11 ) {
if ( ! strcmp ( V_110 , V_109 [ V_72 ] . V_11 ) ) {
( * V_104 ) [ V_27 ++ ] = V_109 [ V_72 ] . V_111 ;
break;
}
}
}
if ( V_72 == V_103 -> V_105 ) {
F_10 ( V_20 , L_12 ,
V_110 , V_101 -> V_11 ) ;
F_48 ( V_20 , * V_104 ) ;
return - V_30 ;
}
}
return 0 ;
}
static int F_49 ( struct V_99 * V_100 ,
struct V_6 * V_7 )
{
struct V_19 * V_20 = & V_100 -> V_20 ;
struct V_14 * V_112 = V_20 -> V_113 ;
struct V_14 * V_101 ;
struct V_114 * V_55 , * V_115 ;
struct V_116 * V_117 , * V_80 ;
unsigned * V_104 ;
unsigned int V_105 , V_118 , V_119 = 0 ;
char * V_23 , * V_24 ;
int V_94 ;
V_118 = F_50 ( V_112 ) ;
if ( ! V_118 )
return - V_30 ;
V_55 = F_46 ( V_20 , V_118 * sizeof( * V_55 ) , V_31 ) ;
if ( ! V_55 ) {
F_10 ( V_20 , L_13 ) ;
return - V_30 ;
}
V_115 = V_55 ;
V_117 = F_46 ( V_20 , V_118 * sizeof( * V_117 ) , V_31 ) ;
if ( ! V_117 ) {
F_10 ( V_20 , L_14 ) ;
return - V_30 ;
}
V_80 = V_117 ;
F_51 (dev_np, cfg_np) {
T_1 V_50 ;
if ( ! F_9 ( V_101 , L_9 , NULL ) )
continue;
V_94 = F_43 ( V_100 , V_101 ,
& V_7 -> V_103 , & V_104 , & V_105 ) ;
if ( V_94 )
return V_94 ;
V_23 = F_46 ( V_20 , strlen ( V_101 -> V_11 ) + V_33 ,
V_31 ) ;
if ( ! V_23 ) {
F_10 ( V_20 , L_5 ) ;
return - V_32 ;
}
sprintf ( V_23 , L_6 , V_101 -> V_11 , V_35 ) ;
V_115 -> V_11 = V_23 ;
V_115 -> V_12 = V_104 ;
V_115 -> V_13 = V_105 ;
F_12 ( V_101 , L_1 , & V_50 ) ;
V_115 -> V_80 = V_50 ;
V_115 ++ ;
if ( ! F_9 ( V_101 , L_1 , NULL ) )
continue;
V_24 = F_46 ( V_20 , strlen ( V_101 -> V_11 ) + V_45 ,
V_31 ) ;
if ( ! V_24 ) {
F_10 ( V_20 , L_8 ) ;
return - V_32 ;
}
sprintf ( V_24 , L_6 , V_101 -> V_11 , V_47 ) ;
V_80 -> V_11 = V_24 ;
V_80 -> V_55 = F_46 ( V_20 , sizeof( char * ) , V_31 ) ;
if ( ! V_80 -> V_55 ) {
F_10 ( V_20 , L_15
L_16 ) ;
return - V_32 ;
}
V_80 -> V_55 [ 0 ] = V_23 ;
V_80 -> V_56 = 1 ;
V_80 ++ ;
V_119 ++ ;
}
V_7 -> V_10 = V_55 ;
V_7 -> V_8 = V_118 ;
V_7 -> V_54 = V_117 ;
V_7 -> V_53 = V_119 ;
return 0 ;
}
static int F_52 ( struct V_99 * V_100 ,
struct V_6 * V_7 )
{
struct V_102 * V_120 = & V_7 -> V_103 ;
struct V_108 * V_121 , * V_109 ;
struct V_1 * V_122 ;
char * V_123 ;
int V_57 , V_60 , V_94 ;
V_120 -> V_11 = L_17 ;
V_120 -> V_124 = V_125 ;
V_120 -> V_126 = & V_127 ;
V_120 -> V_128 = & V_129 ;
V_120 -> V_130 = & V_131 ;
V_121 = F_46 ( & V_100 -> V_20 , sizeof( * V_121 ) *
V_7 -> V_62 -> V_65 , V_31 ) ;
if ( ! V_121 ) {
F_10 ( & V_100 -> V_20 , L_18 ) ;
return - V_32 ;
}
V_120 -> V_12 = V_121 ;
V_120 -> V_105 = V_7 -> V_62 -> V_65 ;
for ( V_57 = 0 , V_109 = V_121 ; V_57 < V_120 -> V_105 ; V_57 ++ , V_109 ++ )
V_109 -> V_111 = V_57 + V_7 -> V_62 -> V_75 ;
V_123 = F_46 ( & V_100 -> V_20 , sizeof( char ) * V_132 *
V_7 -> V_62 -> V_65 , V_31 ) ;
if ( ! V_123 ) {
F_10 ( & V_100 -> V_20 , L_19 ) ;
return - V_32 ;
}
for ( V_60 = 0 ; V_60 < V_7 -> V_62 -> V_133 ; V_60 ++ ) {
V_122 = & V_7 -> V_62 -> V_63 [ V_60 ] ;
for ( V_57 = 0 ; V_57 < V_122 -> V_65 ; V_57 ++ ) {
sprintf ( V_123 , L_20 , V_122 -> V_11 , V_57 ) ;
V_109 = V_121 + V_122 -> V_64 + V_57 ;
V_109 -> V_11 = V_123 ;
V_123 += V_132 ;
}
}
V_94 = F_49 ( V_100 , V_7 ) ;
if ( V_94 )
return V_94 ;
V_7 -> V_134 = F_53 ( V_120 , & V_100 -> V_20 , V_7 ) ;
if ( ! V_7 -> V_134 ) {
F_10 ( & V_100 -> V_20 , L_21 ) ;
return - V_30 ;
}
for ( V_60 = 0 ; V_60 < V_7 -> V_62 -> V_133 ; ++ V_60 ) {
V_122 = & V_7 -> V_62 -> V_63 [ V_60 ] ;
V_122 -> V_135 . V_11 = V_122 -> V_11 ;
V_122 -> V_135 . V_136 = V_60 ;
V_122 -> V_135 . V_64 = V_122 -> V_64 ;
V_122 -> V_135 . V_75 = V_122 -> V_2 . V_75 ;
V_122 -> V_135 . V_105 = V_122 -> V_2 . V_137 ;
V_122 -> V_135 . V_3 = & V_122 -> V_2 ;
F_54 ( V_7 -> V_134 , & V_122 -> V_135 ) ;
}
return 0 ;
}
static int F_55 ( struct V_99 * V_100 ,
struct V_6 * V_7 )
{
struct V_138 * V_62 = V_7 -> V_62 ;
struct V_1 * V_60 = V_62 -> V_63 ;
struct V_2 * V_3 ;
int V_94 ;
int V_93 ;
for ( V_93 = 0 ; V_93 < V_62 -> V_133 ; ++ V_93 , ++ V_60 ) {
V_60 -> V_2 = V_139 ;
V_3 = & V_60 -> V_2 ;
V_3 -> V_75 = V_62 -> V_75 + V_60 -> V_64 ;
V_3 -> V_137 = V_60 -> V_65 ;
V_3 -> V_20 = & V_100 -> V_20 ;
V_3 -> V_113 = V_60 -> V_113 ;
V_3 -> V_140 = V_60 -> V_11 ;
V_94 = F_56 ( V_3 ) ;
if ( V_94 ) {
F_10 ( & V_100 -> V_20 , L_22 ,
V_3 -> V_140 , V_94 ) ;
goto V_141;
}
}
return 0 ;
V_141:
for ( -- V_93 , -- V_60 ; V_93 >= 0 ; -- V_93 , -- V_60 )
if ( F_57 ( & V_60 -> V_2 ) )
F_10 ( & V_100 -> V_20 , L_23 ,
V_60 -> V_2 . V_140 ) ;
return V_94 ;
}
static int F_58 ( struct V_99 * V_100 ,
struct V_6 * V_7 )
{
struct V_138 * V_62 = V_7 -> V_62 ;
struct V_1 * V_60 = V_62 -> V_63 ;
int V_94 = 0 ;
int V_93 ;
for ( V_93 = 0 ; ! V_94 && V_93 < V_62 -> V_133 ; ++ V_93 , ++ V_60 )
V_94 = F_57 ( & V_60 -> V_2 ) ;
if ( V_94 )
F_10 ( & V_100 -> V_20 , L_24 ) ;
return V_94 ;
}
static struct V_138 * F_59 (
struct V_6 * V_142 ,
struct V_99 * V_100 )
{
int V_136 ;
const struct V_143 * V_144 ;
struct V_14 * V_145 = V_100 -> V_20 . V_113 ;
struct V_14 * V_15 ;
struct V_138 * V_62 ;
struct V_1 * V_60 ;
int V_93 ;
V_136 = F_60 ( V_145 , L_25 ) ;
if ( V_136 < 0 ) {
F_10 ( & V_100 -> V_20 , L_26 ) ;
return NULL ;
}
V_144 = F_61 ( V_146 , V_145 ) ;
V_62 = (struct V_138 * ) V_144 -> V_40 + V_136 ;
V_60 = V_62 -> V_63 ;
for ( V_93 = 0 ; V_93 < V_62 -> V_133 ; ++ V_93 , ++ V_60 ) {
F_62 ( & V_60 -> V_78 ) ;
V_60 -> V_7 = V_142 ;
V_60 -> V_64 = V_62 -> V_65 ;
V_62 -> V_65 += V_60 -> V_65 ;
}
F_51 (node, np) {
if ( ! F_9 ( V_15 , L_27 , NULL ) )
continue;
V_60 = V_62 -> V_63 ;
for ( V_93 = 0 ; V_93 < V_62 -> V_133 ; ++ V_93 , ++ V_60 ) {
if ( ! strcmp ( V_60 -> V_11 , V_15 -> V_11 ) ) {
V_60 -> V_113 = V_15 ;
break;
}
}
}
V_62 -> V_75 = V_64 ;
V_64 += V_62 -> V_65 ;
return V_62 ;
}
static int F_63 ( struct V_99 * V_100 )
{
struct V_6 * V_7 ;
struct V_19 * V_20 = & V_100 -> V_20 ;
struct V_138 * V_62 ;
struct V_147 * V_148 ;
int V_94 ;
if ( ! V_20 -> V_113 ) {
F_10 ( V_20 , L_28 ) ;
return - V_149 ;
}
V_7 = F_46 ( V_20 , sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 ) {
F_10 ( V_20 , L_29
L_30 ) ;
return - V_32 ;
}
V_62 = F_59 ( V_7 , V_100 ) ;
if ( ! V_62 ) {
F_10 ( & V_100 -> V_20 , L_31 ) ;
return - V_30 ;
}
V_7 -> V_62 = V_62 ;
V_7 -> V_20 = V_20 ;
V_148 = F_64 ( V_100 , V_150 , 0 ) ;
V_7 -> V_66 = F_65 ( & V_100 -> V_20 , V_148 ) ;
if ( F_66 ( V_7 -> V_66 ) )
return F_67 ( V_7 -> V_66 ) ;
V_148 = F_64 ( V_100 , V_151 , 0 ) ;
if ( V_148 )
V_7 -> V_152 = V_148 -> V_153 ;
V_94 = F_55 ( V_100 , V_7 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_52 ( V_100 , V_7 ) ;
if ( V_94 ) {
F_58 ( V_100 , V_7 ) ;
return V_94 ;
}
if ( V_62 -> V_154 )
V_62 -> V_154 ( V_7 ) ;
if ( V_62 -> V_155 )
V_62 -> V_155 ( V_7 ) ;
F_68 ( V_100 , V_7 ) ;
F_69 ( & V_7 -> V_145 , & V_156 ) ;
return 0 ;
}
static void F_70 (
struct V_6 * V_7 )
{
struct V_138 * V_62 = V_7 -> V_62 ;
void T_2 * V_66 = V_7 -> V_66 ;
int V_93 ;
for ( V_93 = 0 ; V_93 < V_62 -> V_133 ; V_93 ++ ) {
struct V_1 * V_60 = & V_62 -> V_63 [ V_93 ] ;
void T_2 * V_58 = V_66 + V_60 -> V_67 ;
T_3 * V_157 = V_60 -> type -> V_79 ;
T_3 * V_158 = V_60 -> type -> V_76 ;
enum V_88 type ;
if ( ! V_158 [ V_159 ] )
continue;
for ( type = 0 ; type < V_92 ; type ++ )
if ( V_158 [ type ] )
V_60 -> V_160 [ type ] = F_22 ( V_58 + V_157 [ type ] ) ;
if ( V_158 [ V_77 ] * V_60 -> V_65 > 32 ) {
V_60 -> V_160 [ V_92 ] =
F_22 ( V_58 + V_157 [ V_77 ] + 4 ) ;
F_71 ( L_32 ,
V_60 -> V_11 , V_58 ,
V_60 -> V_160 [ V_77 ] ,
V_60 -> V_160 [ V_92 ] ) ;
} else {
F_71 ( L_33 , V_60 -> V_11 ,
V_58 , V_60 -> V_160 [ V_77 ] ) ;
}
}
if ( V_62 -> V_161 )
V_62 -> V_161 ( V_7 ) ;
}
static void F_72 ( struct V_6 * V_7 )
{
struct V_138 * V_62 = V_7 -> V_62 ;
void T_2 * V_66 = V_7 -> V_66 ;
int V_93 ;
if ( V_62 -> V_162 )
V_62 -> V_162 ( V_7 ) ;
for ( V_93 = 0 ; V_93 < V_62 -> V_133 ; V_93 ++ ) {
struct V_1 * V_60 = & V_62 -> V_63 [ V_93 ] ;
void T_2 * V_58 = V_66 + V_60 -> V_67 ;
T_3 * V_157 = V_60 -> type -> V_79 ;
T_3 * V_158 = V_60 -> type -> V_76 ;
enum V_88 type ;
if ( ! V_158 [ V_159 ] )
continue;
if ( V_158 [ V_77 ] * V_60 -> V_65 > 32 ) {
F_71 ( L_34 ,
V_60 -> V_11 , V_58 ,
F_22 ( V_58 + V_157 [ V_77 ] ) ,
F_22 ( V_58 + V_157 [ V_77 ] + 4 ) ,
V_60 -> V_160 [ V_77 ] ,
V_60 -> V_160 [ V_92 ] ) ;
F_23 ( V_60 -> V_160 [ V_92 ] ,
V_58 + V_157 [ V_77 ] + 4 ) ;
} else {
F_71 ( L_35 , V_60 -> V_11 ,
V_58 , F_22 ( V_58 + V_157 [ V_77 ] ) ,
V_60 -> V_160 [ V_77 ] ) ;
}
for ( type = 0 ; type < V_92 ; type ++ )
if ( V_158 [ type ] )
F_23 ( V_60 -> V_160 [ type ] , V_58 + V_157 [ type ] ) ;
}
}
static int F_73 ( void )
{
struct V_6 * V_7 ;
F_74 (drvdata, &drvdata_list, node) {
F_70 ( V_7 ) ;
}
return 0 ;
}
static void F_75 ( void )
{
struct V_6 * V_7 ;
F_76 (drvdata, &drvdata_list, node) {
F_72 ( V_7 ) ;
}
}
static int T_4 F_77 ( void )
{
F_78 ( & V_163 ) ;
return F_79 ( & V_164 ) ;
}
static void T_5 F_80 ( void )
{
F_81 ( & V_164 ) ;
}
