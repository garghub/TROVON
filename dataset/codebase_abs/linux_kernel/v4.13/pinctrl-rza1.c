static inline bool F_1 ( unsigned int V_1 ,
unsigned int V_2 ,
unsigned int V_3 ,
const struct V_4 * V_5 )
{
const struct V_4 * V_6 = & V_5 [ V_1 ] ;
const struct V_7 * V_8 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_10 ; ++ V_9 ) {
V_8 = & V_6 -> V_11 [ V_9 ] ;
if ( V_8 -> V_2 == V_2 && V_8 -> V_3 == V_3 )
return true ;
}
return false ;
}
static inline int F_2 ( unsigned int V_1 ,
unsigned int V_2 ,
unsigned int V_3 ,
const struct V_12 * V_5 )
{
const struct V_13 * V_14 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_10 ; ++ V_9 ) {
V_14 = & V_5 -> V_11 [ V_9 ] ;
if ( V_14 -> V_1 == V_1 && V_14 -> V_2 == V_2 &&
V_14 -> V_3 == V_3 )
return V_14 -> V_15 ;
}
return - V_16 ;
}
static unsigned int F_3 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 ,
struct V_17 * V_18 )
{
const struct V_19 * V_20 = V_18 -> V_21 ;
const struct V_4 * V_22 = V_20 -> V_22 ;
const struct V_12 * V_23 = V_20 -> V_23 ;
unsigned int V_24 = 0 ;
int V_25 ;
if ( F_1 ( V_1 , V_2 , V_3 , V_22 ) )
V_24 |= V_26 ;
V_25 = F_2 ( V_1 , V_2 , V_3 , V_23 ) ;
if ( V_25 == 0 )
V_24 |= V_27 ;
else if ( V_25 > 0 )
V_24 |= V_28 ;
return V_24 ;
}
static inline void F_4 ( struct V_29 * V_1 , unsigned int V_30 ,
unsigned int V_31 , bool V_32 )
{
void T_1 * V_33 = F_5 ( V_1 -> V_34 , V_30 , V_1 -> V_35 ) ;
T_2 V_36 = F_6 ( V_33 ) ;
if ( V_32 )
V_36 |= F_7 ( V_31 ) ;
else
V_36 &= ~ F_7 ( V_31 ) ;
F_8 ( V_36 , V_33 ) ;
}
static inline unsigned int F_9 ( struct V_29 * V_1 ,
unsigned int V_30 , unsigned int V_31 )
{
void T_1 * V_33 = F_5 ( V_1 -> V_34 , V_30 , V_1 -> V_35 ) ;
return F_6 ( V_33 ) & F_7 ( V_31 ) ;
}
static void F_10 ( struct V_29 * V_1 , unsigned int V_2 )
{
unsigned long V_37 ;
F_11 ( & V_1 -> V_38 , V_37 ) ;
F_4 ( V_1 , V_39 , V_2 , 0 ) ;
F_4 ( V_1 , V_40 , V_2 , 0 ) ;
F_4 ( V_1 , V_41 , V_2 , 1 ) ;
F_4 ( V_1 , V_42 , V_2 , 0 ) ;
F_4 ( V_1 , V_43 , V_2 , 0 ) ;
F_12 ( & V_1 -> V_38 , V_37 ) ;
}
static inline int F_13 ( struct V_29 * V_1 ,
unsigned int V_2 )
{
unsigned long V_37 ;
int V_15 ;
F_11 ( & V_1 -> V_38 , V_37 ) ;
V_15 = F_9 ( V_1 , V_41 , V_2 ) ;
F_12 ( & V_1 -> V_38 , V_37 ) ;
return ! ! V_15 ;
}
static inline void F_14 ( struct V_29 * V_1 ,
unsigned int V_2 , bool V_15 )
{
unsigned long V_37 ;
F_11 ( & V_1 -> V_38 , V_37 ) ;
F_4 ( V_1 , V_39 , V_2 , 1 ) ;
if ( V_15 ) {
F_4 ( V_1 , V_41 , V_2 , 1 ) ;
F_4 ( V_1 , V_40 , V_2 , 0 ) ;
} else {
F_4 ( V_1 , V_41 , V_2 , 0 ) ;
F_4 ( V_1 , V_40 , V_2 , 1 ) ;
}
F_12 ( & V_1 -> V_38 , V_37 ) ;
}
static inline void F_15 ( struct V_29 * V_1 , unsigned int V_2 ,
unsigned int V_44 )
{
unsigned long V_37 ;
F_11 ( & V_1 -> V_38 , V_37 ) ;
F_4 ( V_1 , V_45 , V_2 , ! ! V_44 ) ;
F_12 ( & V_1 -> V_38 , V_37 ) ;
}
static inline int F_16 ( struct V_29 * V_1 , unsigned int V_2 )
{
unsigned long V_37 ;
int V_36 ;
F_11 ( & V_1 -> V_38 , V_37 ) ;
V_36 = F_9 ( V_1 , V_46 , V_2 ) ;
F_12 ( & V_1 -> V_38 , V_37 ) ;
return V_36 ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_47 * V_48 )
{
struct V_29 * V_1 = & V_18 -> V_49 [ V_48 -> V_1 ] ;
unsigned int V_2 = V_48 -> V_2 ;
T_3 V_50 = V_48 -> V_50 ;
T_3 V_51 = V_48 -> V_51 ;
T_3 V_52 ;
F_10 ( V_1 , V_2 ) ;
V_52 = F_3 ( V_1 -> V_35 , V_2 , V_50 ,
V_18 ) ;
if ( V_51 )
V_51 |= ( V_52 & V_26 ) ;
else
V_51 = V_52 ;
if ( V_51 & V_26 )
F_4 ( V_1 , V_40 , V_2 , 1 ) ;
V_50 -= 1 ;
F_4 ( V_1 , V_53 , V_2 , V_50 & V_54 ) ;
F_4 ( V_1 , V_55 , V_2 , V_50 & V_56 ) ;
F_4 ( V_1 , V_57 , V_2 , V_50 & V_58 ) ;
if ( V_51 & ( V_28 | V_27 ) )
F_4 ( V_1 , V_41 , V_2 ,
V_51 & V_28 ) ;
else
F_4 ( V_1 , V_43 , V_2 , 1 ) ;
F_4 ( V_1 , V_42 , V_2 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
F_10 ( V_1 , V_61 ) ;
return 0 ;
}
static void F_20 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
F_10 ( V_1 , V_61 ) ;
}
static int F_21 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
return F_13 ( V_1 , V_61 ) ;
}
static int F_22 ( struct V_59 * V_60 ,
unsigned int V_61 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
F_14 ( V_1 , V_61 , true ) ;
return 0 ;
}
static int F_23 ( struct V_59 * V_60 ,
unsigned int V_61 ,
int V_44 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
F_15 ( V_1 , V_61 , V_44 ) ;
F_14 ( V_1 , V_61 , false ) ;
return 0 ;
}
static int F_24 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
return F_16 ( V_1 , V_61 ) ;
}
static void F_25 ( struct V_59 * V_60 , unsigned int V_61 ,
int V_44 )
{
struct V_29 * V_1 = F_19 ( V_60 ) ;
F_15 ( V_1 , V_61 , V_44 ) ;
}
static int F_26 ( struct V_62 * V_63 )
{
struct V_62 * V_64 ;
struct V_65 * V_66 ;
unsigned int V_10 ;
V_66 = F_27 ( V_63 , L_1 , NULL ) ;
if ( V_66 )
return V_66 -> V_67 / sizeof( V_68 ) ;
V_10 = 0 ;
F_28 (np, child) {
V_66 = F_27 ( V_64 , L_1 , NULL ) ;
if ( ! V_66 )
return - V_69 ;
V_10 += V_66 -> V_67 / sizeof( V_68 ) ;
}
return V_10 ;
}
static int F_29 ( struct V_17 * V_18 ,
struct V_62 * V_63 ,
struct V_47 * V_70 ,
unsigned int * V_71 )
{
struct V_72 * V_73 = V_18 -> V_74 ;
char const * V_75 = L_1 ;
unsigned long * V_76 ;
unsigned int V_77 ;
struct V_65 * V_66 ;
unsigned int V_10 ;
T_3 V_78 ;
unsigned int V_9 ;
int V_25 ;
V_66 = F_27 ( V_63 , V_75 , NULL ) ;
if ( ! V_66 ) {
F_30 ( V_18 -> V_79 , L_2 , V_75 ) ;
return - V_16 ;
}
V_10 = V_66 -> V_67 / sizeof( V_68 ) ;
V_25 = F_31 ( V_63 , V_73 , & V_76 ,
& V_77 ) ;
if ( V_25 ) {
F_32 ( V_18 -> V_79 ,
L_3 ,
V_63 -> V_80 ) ;
return V_25 ;
}
V_78 = 0 ;
for ( V_9 = 0 ; V_9 < V_77 && V_78 == 0 ; V_9 ++ )
switch ( F_33 ( V_76 [ V_9 ] ) ) {
case V_81 :
V_78 |= V_28 ;
break;
case V_82 :
V_78 |= V_27 ;
default:
break;
}
F_34 ( V_76 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; ++ V_9 ) {
V_68 V_83 ;
struct V_47 * V_48 = & V_70 [ V_9 ] ;
V_25 = F_35 ( V_63 , V_75 , V_9 , & V_83 ) ;
if ( V_25 )
return V_25 ;
V_48 -> V_35 = V_83 & V_84 ;
V_48 -> V_1 = F_36 ( V_48 -> V_35 ) ;
V_48 -> V_2 = F_37 ( V_48 -> V_35 ) ;
V_48 -> V_50 = F_38 ( V_83 ) ;
V_48 -> V_51 = V_78 ;
if ( V_48 -> V_1 >= V_85 ||
V_48 -> V_2 >= V_86 ) {
F_32 ( V_18 -> V_79 ,
L_4 ,
V_48 -> V_1 , V_48 -> V_2 , V_75 ) ;
return - V_69 ;
}
V_71 [ V_9 ] = V_48 -> V_35 ;
}
return V_10 ;
}
static int F_39 ( struct V_72 * V_73 ,
struct V_62 * V_63 ,
struct V_87 * * V_88 ,
unsigned int * V_89 )
{
struct V_17 * V_18 = F_40 ( V_73 ) ;
struct V_47 * V_70 , * V_48 ;
unsigned int * V_71 , * V_90 ;
struct V_62 * V_64 ;
const char * V_91 ;
const char * * V_92 ;
int V_25 , V_10 ;
V_10 = F_26 ( V_63 ) ;
if ( V_10 < 0 ) {
F_32 ( V_18 -> V_79 , L_5 ) ;
return - V_69 ;
}
V_70 = F_41 ( V_18 -> V_79 , V_10 , sizeof( * V_70 ) ,
V_93 ) ;
V_71 = F_41 ( V_18 -> V_79 , V_10 , sizeof( * V_71 ) ,
V_93 ) ;
V_92 = F_42 ( V_18 -> V_79 , sizeof( * V_92 ) , V_93 ) ;
if ( ! V_70 || ! V_71 || ! V_92 )
return - V_94 ;
V_48 = & V_70 [ 0 ] ;
V_90 = & V_71 [ 0 ] ;
V_25 = F_29 ( V_18 , V_63 , V_48 , V_90 ) ;
if ( V_25 == - V_16 )
F_28 (np, child) {
V_25 = F_29 ( V_18 , V_64 , V_48 ,
V_90 ) ;
if ( V_25 < 0 )
return V_25 ;
V_90 += V_25 ;
V_48 += V_25 ;
}
else if ( V_25 < 0 )
return V_25 ;
V_91 = V_63 -> V_80 ;
V_92 [ 0 ] = V_91 ;
F_43 ( & V_18 -> V_95 ) ;
V_25 = F_44 ( V_73 , V_91 , V_71 , V_10 ,
NULL ) ;
if ( V_25 ) {
F_45 ( & V_18 -> V_95 ) ;
return V_25 ;
}
V_25 = F_46 ( V_73 , V_91 , V_92 , 1 ,
V_70 ) ;
if ( V_25 )
goto V_96;
F_45 ( & V_18 -> V_95 ) ;
F_47 ( V_18 -> V_79 , L_6 ,
V_91 , V_10 ) ;
* V_89 = 0 ;
* V_88 = F_48 ( sizeof( * * V_88 ) , V_93 ) ;
if ( ! * V_88 ) {
V_25 = - V_94 ;
goto V_97;
}
( * V_88 ) -> type = V_98 ;
( * V_88 ) -> V_21 . V_99 . V_100 = V_63 -> V_80 ;
( * V_88 ) -> V_21 . V_99 . V_101 = V_63 -> V_80 ;
* V_89 = 1 ;
return 0 ;
V_97:
F_43 ( & V_18 -> V_95 ) ;
F_49 ( V_73 ) ;
V_96:
F_50 ( V_73 ) ;
F_45 ( & V_18 -> V_95 ) ;
F_47 ( V_18 -> V_79 , L_7 ,
V_91 ) ;
return V_25 ;
}
static void F_51 ( struct V_72 * V_73 ,
struct V_87 * V_88 , unsigned int V_89 )
{
F_34 ( V_88 ) ;
}
static int F_52 ( struct V_72 * V_73 , unsigned int V_102 ,
unsigned int V_100 )
{
struct V_17 * V_18 = F_40 ( V_73 ) ;
struct V_47 * V_70 ;
struct V_103 * V_3 ;
struct V_104 * V_105 ;
int V_9 ;
V_105 = F_53 ( V_73 , V_100 ) ;
if ( ! V_105 )
return - V_69 ;
V_3 = F_54 ( V_73 , V_102 ) ;
if ( ! V_3 )
return - V_69 ;
V_70 = (struct V_47 * ) V_3 -> V_21 ;
for ( V_9 = 0 ; V_9 < V_105 -> V_106 ; ++ V_9 ) {
int V_25 ;
V_25 = F_17 ( V_18 , & V_70 [ V_9 ] ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static unsigned int F_55 ( struct V_62 * V_63 )
{
struct V_62 * V_64 ;
unsigned int V_107 = 0 ;
F_28 (np, child) {
if ( ! F_56 ( V_64 , L_8 ) )
continue;
V_107 ++ ;
}
return V_107 ;
}
static int F_57 ( struct V_17 * V_18 ,
struct V_62 * V_63 ,
struct V_59 * V_60 ,
struct V_108 * V_109 )
{
const char * V_110 = L_9 ;
struct V_111 V_112 ;
unsigned int V_113 ;
V_68 V_114 ;
int V_25 ;
V_25 = F_58 ( V_63 , V_110 , 3 , 0 , & V_112 ) ;
if ( V_25 ) {
F_32 ( V_18 -> V_79 , L_10 ,
V_110 ) ;
return V_25 ;
}
V_114 = V_112 . args [ 1 ] ;
V_113 = F_36 ( V_114 ) ;
if ( V_113 > V_85 ) {
F_32 ( V_18 -> V_79 ,
L_11 , V_110 ) ;
return - V_69 ;
}
* V_60 = V_115 ;
V_60 -> V_34 = - 1 ;
V_60 -> V_116 = F_59 ( V_18 -> V_79 , V_93 , L_12 ,
V_63 -> V_80 , V_113 ) ;
V_60 -> V_117 = V_112 . args [ 2 ] ;
V_60 -> V_118 = V_63 ;
V_60 -> V_119 = V_18 -> V_79 ;
V_109 -> V_35 = V_113 ;
V_109 -> V_80 = V_60 -> V_116 ;
V_109 -> V_120 = V_109 -> V_34 = V_114 ;
V_109 -> V_10 = V_112 . args [ 2 ] ;
V_109 -> V_121 = V_60 ;
V_25 = F_60 ( V_18 -> V_79 , V_60 ,
& V_18 -> V_49 [ V_113 ] ) ;
if ( V_25 )
return V_25 ;
F_61 ( V_18 -> V_74 , V_109 ) ;
F_47 ( V_18 -> V_79 , L_13 ,
V_60 -> V_116 , V_60 -> V_117 ) ;
return 0 ;
}
static int F_62 ( struct V_17 * V_18 )
{
struct V_62 * V_63 = V_18 -> V_79 -> V_118 ;
struct V_108 * V_122 ;
struct V_59 * V_123 ;
struct V_62 * V_64 ;
unsigned int V_124 ;
unsigned int V_9 ;
int V_25 ;
V_124 = F_55 ( V_63 ) ;
if ( V_124 == 0 ) {
F_30 ( V_18 -> V_79 , L_14 ) ;
return 0 ;
}
V_123 = F_41 ( V_18 -> V_79 , V_124 ,
sizeof( * V_123 ) , V_93 ) ;
V_122 = F_41 ( V_18 -> V_79 , V_124 ,
sizeof( * V_122 ) , V_93 ) ;
if ( ! V_123 || ! V_122 )
return - V_94 ;
V_9 = 0 ;
F_28 (np, child) {
if ( ! F_56 ( V_64 , L_8 ) )
continue;
V_25 = F_57 ( V_18 , V_64 , & V_123 [ V_9 ] ,
& V_122 [ V_9 ] ) ;
if ( V_25 )
goto V_125;
++ V_9 ;
}
F_47 ( V_18 -> V_79 , L_15 , V_9 ) ;
return 0 ;
V_125:
for (; V_9 > 0 ; V_9 -- )
F_63 ( V_18 -> V_79 , & V_123 [ V_9 - 1 ] ) ;
return V_25 ;
}
static int F_64 ( struct V_17 * V_18 )
{
struct V_126 * V_11 ;
struct V_29 * V_49 ;
unsigned int V_9 ;
int V_25 ;
V_11 = F_41 ( V_18 -> V_79 , V_127 , sizeof( * V_11 ) ,
V_93 ) ;
V_49 = F_41 ( V_18 -> V_79 , V_85 , sizeof( * V_49 ) ,
V_93 ) ;
if ( ! V_11 || ! V_49 )
return - V_94 ;
V_18 -> V_11 = V_11 ;
V_18 -> V_128 . V_11 = V_11 ;
V_18 -> V_128 . V_10 = V_127 ;
V_18 -> V_49 = V_49 ;
for ( V_9 = 0 ; V_9 < V_127 ; ++ V_9 ) {
unsigned int V_2 = F_37 ( V_9 ) ;
unsigned int V_1 = F_36 ( V_9 ) ;
V_11 [ V_9 ] . V_129 = V_9 ;
V_11 [ V_9 ] . V_80 = F_59 ( V_18 -> V_79 , V_93 ,
L_16 , V_1 , V_2 ) ;
if ( V_9 % V_86 == 0 ) {
unsigned int V_130 = F_36 ( V_9 ) ;
V_49 [ V_130 ] . V_35 = V_130 ;
V_49 [ V_130 ] . V_34 = V_18 -> V_34 ;
V_49 [ V_130 ] . V_11 = & V_11 [ V_9 ] ;
F_65 ( & V_49 [ V_130 ] . V_38 ) ;
}
}
V_25 = F_66 ( V_18 -> V_79 , & V_18 -> V_128 ,
V_18 , & V_18 -> V_74 ) ;
if ( V_25 ) {
F_32 ( V_18 -> V_79 ,
L_17 ) ;
return V_25 ;
}
V_25 = F_67 ( V_18 -> V_74 ) ;
if ( V_25 ) {
F_32 ( V_18 -> V_79 ,
L_18 ) ;
return V_25 ;
}
V_25 = F_62 ( V_18 ) ;
if ( V_25 ) {
F_32 ( V_18 -> V_79 , L_19 ) ;
return V_25 ;
}
return 0 ;
}
static int F_68 ( struct V_131 * V_132 )
{
struct V_17 * V_18 ;
struct V_133 * V_134 ;
int V_25 ;
V_18 = F_42 ( & V_132 -> V_79 , sizeof( * V_18 ) , V_93 ) ;
if ( ! V_18 )
return - V_94 ;
V_18 -> V_79 = & V_132 -> V_79 ;
V_134 = F_69 ( V_132 , V_135 , 0 ) ;
V_18 -> V_34 = F_70 ( & V_132 -> V_79 , V_134 ) ;
if ( F_71 ( V_18 -> V_34 ) )
return F_72 ( V_18 -> V_34 ) ;
F_73 ( & V_18 -> V_95 ) ;
F_74 ( V_132 , V_18 ) ;
V_18 -> V_128 . V_80 = V_136 ;
V_18 -> V_128 . V_137 = & V_138 ;
V_18 -> V_128 . V_139 = & V_140 ;
V_18 -> V_128 . V_141 = V_142 ;
V_18 -> V_21 = F_75 ( & V_132 -> V_79 ) ;
V_25 = F_64 ( V_18 ) ;
if ( V_25 )
return V_25 ;
F_47 ( & V_132 -> V_79 ,
L_20 ) ;
return 0 ;
}
static int T_4 F_76 ( void )
{
return F_77 ( & V_143 ) ;
}
