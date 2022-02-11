static inline T_1 F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
}
return V_1 ;
}
static inline T_1 F_2 ( struct V_12 * V_13 , unsigned int V_1 )
{
if ( V_13 -> V_14 & V_15 )
return F_1 ( V_1 ) ;
return V_1 ;
}
static inline T_1 F_3 ( struct V_12 * V_13 , unsigned int V_1 )
{
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
void T_2 * V_19 = V_13 -> V_20 ;
return V_17 -> V_21 ( V_19 + F_2 ( V_13 , V_1 ) ) ;
}
static inline void F_4 ( struct V_12 * V_13 , unsigned int V_1 ,
T_1 V_22 )
{
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
void T_2 * V_19 = V_13 -> V_20 ;
V_17 -> V_23 ( V_19 + F_2 ( V_13 , V_1 ) , V_22 ) ;
}
static int F_5 ( struct V_16 * V_17 , unsigned V_1 )
{
struct V_24 * V_25 = F_6 ( V_17 ) ;
struct V_12 * V_13 = V_25 -> V_13 ;
return F_7 ( V_13 -> V_26 , V_1 ) ;
}
static void F_8 ( struct V_12 * V_13 , unsigned int V_27 )
{
T_1 V_28 = F_3 ( V_13 , V_6 ) ;
if ( F_9 ( V_13 -> V_18 [ 0 ] . V_17 . V_29 + V_27 ) )
V_28 &= ~ F_10 ( V_27 ) ;
else
V_28 |= F_10 ( V_27 ) ;
F_4 ( V_13 , V_6 , V_28 ) ;
}
static T_1 F_11 ( struct V_12 * V_13 )
{
T_1 V_30 = F_3 ( V_13 , V_8 ) ;
T_1 V_31 = V_30 ;
while ( V_30 ) {
int V_32 = F_12 ( V_30 ) - 1 ;
int V_33 = F_7 ( V_13 -> V_26 , V_32 ) ;
F_13 ( V_33 ) ;
V_30 &= ~ F_10 ( V_32 ) ;
if ( ( F_14 ( V_33 ) & V_34 )
== V_35 )
F_8 ( V_13 , V_32 ) ;
}
return V_31 ;
}
static void F_15 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = F_16 ( V_37 ) ;
struct V_38 * V_39 = F_17 ( V_37 ) ;
F_11 ( V_13 ) ;
if ( V_39 -> V_40 )
V_39 -> V_40 ( F_18 ( V_37 ) ) ;
}
static void F_19 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_20 ( V_42 ) ;
struct V_12 * V_13 = V_44 -> V_45 ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
unsigned long V_14 ;
T_1 V_22 ;
F_21 ( & V_17 -> V_46 , V_14 ) ;
V_22 = F_3 ( V_13 , V_47 ) ;
V_22 |= F_10 ( V_42 -> V_32 ) ;
F_4 ( V_13 , V_47 , V_22 ) ;
F_22 ( & V_17 -> V_46 , V_14 ) ;
}
static void F_23 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_20 ( V_42 ) ;
struct V_12 * V_13 = V_44 -> V_45 ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
unsigned long V_14 ;
T_1 V_22 ;
F_21 ( & V_17 -> V_46 , V_14 ) ;
V_22 = F_3 ( V_13 , V_47 ) ;
V_22 &= ~ F_10 ( V_42 -> V_32 ) ;
F_4 ( V_13 , V_47 , V_22 ) ;
F_22 ( & V_17 -> V_46 , V_14 ) ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_20 ( V_42 ) ;
struct V_12 * V_13 = V_44 -> V_45 ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
if ( F_25 ( V_17 , F_26 ( V_42 ) ) ) {
F_27 ( V_13 -> V_48 , L_1 ,
F_26 ( V_42 ) ) ;
return - V_49 ;
}
return 0 ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_20 ( V_42 ) ;
struct V_12 * V_13 = V_44 -> V_45 ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
F_29 ( V_17 , F_26 ( V_42 ) ) ;
}
static int F_30 ( struct V_41 * V_42 , T_1 type )
{
struct V_43 * V_44 = F_20 ( V_42 ) ;
struct V_12 * V_13 = V_44 -> V_45 ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
int V_50 = V_42 -> V_32 ;
unsigned long V_51 , V_52 , V_14 ;
if ( type & ~ ( V_53 | V_54 |
V_55 | V_56 ) )
return - V_49 ;
F_21 ( & V_17 -> V_46 , V_14 ) ;
V_51 = F_3 ( V_13 , V_4 ) ;
V_52 = F_3 ( V_13 , V_6 ) ;
switch ( type ) {
case V_35 :
V_51 |= F_10 ( V_50 ) ;
F_8 ( V_13 , V_50 ) ;
break;
case V_53 :
V_51 |= F_10 ( V_50 ) ;
V_52 |= F_10 ( V_50 ) ;
break;
case V_54 :
V_51 |= F_10 ( V_50 ) ;
V_52 &= ~ F_10 ( V_50 ) ;
break;
case V_55 :
V_51 &= ~ F_10 ( V_50 ) ;
V_52 |= F_10 ( V_50 ) ;
break;
case V_56 :
V_51 &= ~ F_10 ( V_50 ) ;
V_52 &= ~ F_10 ( V_50 ) ;
break;
}
F_31 ( V_42 , type ) ;
F_4 ( V_13 , V_4 , V_51 ) ;
F_4 ( V_13 , V_6 , V_52 ) ;
F_22 ( & V_17 -> V_46 , V_14 ) ;
return 0 ;
}
static int F_32 ( struct V_16 * V_17 ,
unsigned V_1 , unsigned V_57 )
{
struct V_24 * V_25 = F_6 ( V_17 ) ;
struct V_12 * V_13 = V_25 -> V_13 ;
unsigned long V_14 , V_58 ;
unsigned long V_59 = V_17 -> V_60 ( V_17 , V_1 ) ;
F_21 ( & V_17 -> V_46 , V_14 ) ;
V_58 = F_3 ( V_13 , V_61 ) ;
if ( V_57 )
F_4 ( V_13 , V_61 , V_58 | V_59 ) ;
else
F_4 ( V_13 , V_61 , V_58 & ~ V_59 ) ;
F_22 ( & V_17 -> V_46 , V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 , unsigned V_1 ,
unsigned long V_62 )
{
T_1 V_57 ;
if ( F_34 ( V_62 ) != V_63 )
return - V_64 ;
V_57 = F_35 ( V_62 ) ;
return F_32 ( V_17 , V_1 , V_57 ) ;
}
static T_3 F_36 ( int V_65 , void * V_66 )
{
T_1 V_67 ;
struct V_12 * V_13 = V_66 ;
V_67 = F_11 ( V_13 ) ;
return V_67 ? V_68 : V_69 ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_24 * V_25 ,
struct V_70 * V_71 )
{
struct V_16 * V_17 = & V_25 -> V_17 ;
struct V_72 * V_73 = V_71 -> V_73 ;
struct V_43 * V_74 = NULL ;
unsigned int V_32 , V_75 = V_17 -> V_75 ;
struct V_76 * V_77 ;
int V_78 , V_79 ;
V_13 -> V_26 = F_38 ( V_73 , V_75 ,
& V_80 , V_13 ) ;
if ( ! V_13 -> V_26 )
return;
V_78 = F_39 ( V_13 -> V_26 , V_75 , 2 ,
L_2 , V_81 ,
V_82 , 0 ,
V_83 ) ;
if ( V_78 ) {
F_40 ( V_13 -> V_48 , L_3 ) ;
F_41 ( V_13 -> V_26 ) ;
V_13 -> V_26 = NULL ;
return;
}
V_74 = F_42 ( V_13 -> V_26 , 0 ) ;
if ( ! V_74 ) {
F_41 ( V_13 -> V_26 ) ;
V_13 -> V_26 = NULL ;
return;
}
V_74 -> V_19 = V_13 -> V_20 ;
V_74 -> V_45 = V_13 ;
for ( V_79 = 0 ; V_79 < 2 ; V_79 ++ ) {
V_77 = & V_74 -> V_84 [ V_79 ] ;
V_77 -> V_39 . V_85 = V_86 ;
V_77 -> V_39 . V_87 = V_88 ;
V_77 -> V_39 . V_89 = V_90 ;
V_77 -> V_39 . V_91 = F_30 ;
V_77 -> V_39 . V_92 = F_19 ;
V_77 -> V_39 . V_93 = F_23 ;
V_77 -> V_39 . V_94 = F_24 ;
V_77 -> V_39 . V_95 = F_28 ;
V_77 -> V_20 . V_96 = F_2 ( V_13 , V_10 ) ;
V_77 -> V_20 . V_59 = F_2 ( V_13 , V_2 ) ;
V_77 -> type = V_97 ;
}
V_74 -> V_84 [ 0 ] . type = V_97 ;
V_74 -> V_84 [ 1 ] . type = V_35 ;
V_74 -> V_84 [ 1 ] . V_98 = V_99 ;
if ( ! V_71 -> V_100 ) {
F_43 ( V_71 -> V_65 , F_15 ,
V_13 ) ;
} else {
V_78 = F_44 ( V_13 -> V_48 , V_71 -> V_65 ,
F_36 ,
V_101 , L_4 , V_13 ) ;
if ( V_78 ) {
F_27 ( V_13 -> V_48 , L_5 ) ;
F_41 ( V_13 -> V_26 ) ;
V_13 -> V_26 = NULL ;
return;
}
}
for ( V_32 = 0 ; V_32 < V_75 ; V_32 ++ )
F_45 ( V_13 -> V_26 , V_32 ) ;
V_25 -> V_17 . V_102 = F_5 ;
}
static void F_46 ( struct V_12 * V_13 )
{
struct V_24 * V_25 = & V_13 -> V_18 [ 0 ] ;
struct V_16 * V_17 = & V_25 -> V_17 ;
unsigned int V_75 = V_17 -> V_75 ;
T_4 V_32 ;
if ( ! V_13 -> V_26 )
return;
for ( V_32 = 0 ; V_32 < V_75 ; V_32 ++ )
F_47 ( F_7 ( V_13 -> V_26 , V_32 ) ) ;
F_41 ( V_13 -> V_26 ) ;
V_13 -> V_26 = NULL ;
}
static int F_48 ( struct V_12 * V_13 ,
struct V_70 * V_71 ,
unsigned int V_27 )
{
struct V_24 * V_25 ;
void T_2 * V_103 , * V_104 , * V_105 ;
int V_78 ;
V_25 = & V_13 -> V_18 [ V_27 ] ;
V_25 -> V_13 = V_13 ;
V_25 -> V_106 = V_71 -> V_106 ;
#ifdef F_49
V_25 -> V_107 = F_50 ( V_13 -> V_48 , sizeof( * V_25 -> V_107 ) , V_108 ) ;
if ( ! V_25 -> V_107 )
return - V_109 ;
#endif
V_103 = V_13 -> V_20 + V_110 + ( V_71 -> V_106 * V_111 ) ;
V_104 = V_13 -> V_20 + V_112 + ( V_71 -> V_106 * V_113 ) ;
V_105 = V_13 -> V_20 + V_114 +
( V_71 -> V_106 * V_115 ) ;
V_78 = F_51 ( & V_25 -> V_17 , V_13 -> V_48 , 4 , V_103 , V_104 , NULL , V_105 ,
NULL , false ) ;
if ( V_78 ) {
F_27 ( V_13 -> V_48 , L_6 ,
V_25 -> V_106 ) ;
return V_78 ;
}
#ifdef F_52
V_25 -> V_17 . V_116 = F_53 ( V_71 -> V_73 ) ;
#endif
V_25 -> V_17 . V_75 = V_71 -> V_75 ;
V_25 -> V_17 . V_29 = V_71 -> V_117 ;
if ( V_71 -> V_106 == 0 )
V_25 -> V_17 . V_118 = F_33 ;
if ( V_71 -> V_65 )
F_37 ( V_13 , V_25 , V_71 ) ;
V_78 = F_54 ( & V_25 -> V_17 , V_25 ) ;
if ( V_78 )
F_27 ( V_13 -> V_48 , L_7 ,
V_25 -> V_106 ) ;
else
V_25 -> V_119 = true ;
if ( V_71 -> V_65 )
F_55 ( & V_25 -> V_17 ) ;
return V_78 ;
}
static void F_56 ( struct V_12 * V_13 )
{
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < V_13 -> V_121 ; ++ V_120 )
if ( V_13 -> V_18 [ V_120 ] . V_119 )
F_57 ( & V_13 -> V_18 [ V_120 ] . V_17 ) ;
}
static struct V_122 *
F_58 ( struct V_123 * V_48 )
{
struct V_72 * V_73 ;
struct V_122 * V_124 ;
struct V_70 * V_71 ;
int V_125 ;
int V_79 ;
V_125 = F_59 ( V_48 ) ;
if ( V_125 == 0 )
return F_60 ( - V_126 ) ;
V_124 = F_50 ( V_48 , sizeof( * V_124 ) , V_108 ) ;
if ( ! V_124 )
return F_60 ( - V_109 ) ;
V_124 -> V_127 = F_61 ( V_48 , V_125 , sizeof( * V_71 ) , V_108 ) ;
if ( ! V_124 -> V_127 )
return F_60 ( - V_109 ) ;
V_124 -> V_125 = V_125 ;
V_79 = 0 ;
F_62 (dev, fwnode) {
V_71 = & V_124 -> V_127 [ V_79 ++ ] ;
V_71 -> V_73 = V_73 ;
if ( F_63 ( V_73 , L_8 , & V_71 -> V_106 ) ||
V_71 -> V_106 >= V_128 ) {
F_27 ( V_48 ,
L_9 , V_79 ) ;
F_64 ( V_73 ) ;
return F_60 ( - V_49 ) ;
}
if ( F_63 ( V_73 , L_10 ,
& V_71 -> V_75 ) ) {
F_40 ( V_48 ,
L_11 ,
V_79 ) ;
V_71 -> V_75 = 32 ;
}
if ( V_48 -> V_116 && V_71 -> V_106 == 0 &&
F_65 ( V_73 ,
L_12 ) ) {
V_71 -> V_65 = F_66 ( F_53 ( V_73 ) , 0 ) ;
if ( ! V_71 -> V_65 )
F_67 ( V_48 , L_13 , V_71 -> V_106 ) ;
}
if ( F_68 ( V_48 ) && V_71 -> V_106 == 0 )
V_71 -> V_65 = F_69 ( F_70 ( V_48 ) , 0 ) ;
V_71 -> V_100 = false ;
V_71 -> V_117 = - 1 ;
}
return V_124 ;
}
static int F_71 ( struct V_129 * V_130 )
{
unsigned int V_79 ;
struct V_131 * V_132 ;
struct V_12 * V_13 ;
int V_78 ;
struct V_123 * V_48 = & V_130 -> V_48 ;
struct V_122 * V_124 = F_72 ( V_48 ) ;
if ( ! V_124 ) {
V_124 = F_58 ( V_48 ) ;
if ( F_73 ( V_124 ) )
return F_74 ( V_124 ) ;
}
if ( ! V_124 -> V_125 )
return - V_126 ;
V_13 = F_50 ( & V_130 -> V_48 , sizeof( * V_13 ) , V_108 ) ;
if ( ! V_13 )
return - V_109 ;
V_13 -> V_48 = & V_130 -> V_48 ;
V_13 -> V_121 = V_124 -> V_125 ;
V_13 -> V_18 = F_61 ( & V_130 -> V_48 , V_13 -> V_121 ,
sizeof( * V_13 -> V_18 ) , V_108 ) ;
if ( ! V_13 -> V_18 )
return - V_109 ;
V_132 = F_75 ( V_130 , V_133 , 0 ) ;
V_13 -> V_20 = F_76 ( & V_130 -> V_48 , V_132 ) ;
if ( F_73 ( V_13 -> V_20 ) )
return F_74 ( V_13 -> V_20 ) ;
V_13 -> V_14 = 0 ;
if ( V_48 -> V_116 ) {
const struct V_134 * V_135 ;
V_135 = F_77 ( V_136 , V_48 ) ;
if ( V_135 ) {
if ( V_135 -> V_137 )
V_13 -> V_14 = ( V_138 ) V_135 -> V_137 ;
}
} else if ( F_68 ( V_48 ) ) {
const struct V_139 * V_140 ;
V_140 = F_78 ( V_141 , V_48 ) ;
if ( V_140 ) {
if ( V_140 -> V_142 )
V_13 -> V_14 = V_140 -> V_142 ;
}
}
for ( V_79 = 0 ; V_79 < V_13 -> V_121 ; V_79 ++ ) {
V_78 = F_48 ( V_13 , & V_124 -> V_127 [ V_79 ] , V_79 ) ;
if ( V_78 )
goto V_143;
}
F_79 ( V_130 , V_13 ) ;
return 0 ;
V_143:
F_56 ( V_13 ) ;
F_46 ( V_13 ) ;
return V_78 ;
}
static int F_80 ( struct V_129 * V_130 )
{
struct V_12 * V_13 = F_81 ( V_130 ) ;
F_56 ( V_13 ) ;
F_46 ( V_13 ) ;
return 0 ;
}
static int F_82 ( struct V_123 * V_48 )
{
struct V_129 * V_130 = F_70 ( V_48 ) ;
struct V_12 * V_13 = F_81 ( V_130 ) ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
unsigned long V_14 ;
int V_79 ;
F_21 ( & V_17 -> V_46 , V_14 ) ;
for ( V_79 = 0 ; V_79 < V_13 -> V_121 ; V_79 ++ ) {
unsigned int V_1 ;
unsigned int V_106 = V_13 -> V_18 [ V_79 ] . V_106 ;
struct V_144 * V_107 = V_13 -> V_18 [ V_79 ] . V_107 ;
F_83 ( ! V_107 ) ;
V_1 = V_114 + V_106 * V_115 ;
V_107 -> V_145 = F_3 ( V_13 , V_1 ) ;
V_1 = V_112 + V_106 * V_113 ;
V_107 -> V_137 = F_3 ( V_13 , V_1 ) ;
V_1 = V_110 + V_106 * V_111 ;
V_107 -> V_146 = F_3 ( V_13 , V_1 ) ;
if ( V_106 == 0 ) {
V_107 -> V_147 = F_3 ( V_13 , V_2 ) ;
V_107 -> V_148 = F_3 ( V_13 , V_47 ) ;
V_107 -> V_149 = F_3 ( V_13 , V_6 ) ;
V_107 -> V_150 = F_3 ( V_13 , V_4 ) ;
V_107 -> V_151 = F_3 ( V_13 , V_61 ) ;
F_4 ( V_13 , V_2 , 0xffffffff ) ;
}
}
F_22 ( & V_17 -> V_46 , V_14 ) ;
return 0 ;
}
static int F_84 ( struct V_123 * V_48 )
{
struct V_129 * V_130 = F_70 ( V_48 ) ;
struct V_12 * V_13 = F_81 ( V_130 ) ;
struct V_16 * V_17 = & V_13 -> V_18 [ 0 ] . V_17 ;
unsigned long V_14 ;
int V_79 ;
F_21 ( & V_17 -> V_46 , V_14 ) ;
for ( V_79 = 0 ; V_79 < V_13 -> V_121 ; V_79 ++ ) {
unsigned int V_1 ;
unsigned int V_106 = V_13 -> V_18 [ V_79 ] . V_106 ;
struct V_144 * V_107 = V_13 -> V_18 [ V_79 ] . V_107 ;
F_83 ( ! V_107 ) ;
V_1 = V_112 + V_106 * V_113 ;
F_4 ( V_13 , V_1 , V_107 -> V_137 ) ;
V_1 = V_114 + V_106 * V_115 ;
F_4 ( V_13 , V_1 , V_107 -> V_145 ) ;
V_1 = V_110 + V_106 * V_111 ;
F_4 ( V_13 , V_1 , V_107 -> V_146 ) ;
if ( V_106 == 0 ) {
F_4 ( V_13 , V_4 , V_107 -> V_150 ) ;
F_4 ( V_13 , V_6 , V_107 -> V_149 ) ;
F_4 ( V_13 , V_61 , V_107 -> V_151 ) ;
F_4 ( V_13 , V_47 , V_107 -> V_148 ) ;
F_4 ( V_13 , V_2 , V_107 -> V_147 ) ;
F_4 ( V_13 , V_10 , 0xffffffff ) ;
}
}
F_22 ( & V_17 -> V_46 , V_14 ) ;
return 0 ;
}
