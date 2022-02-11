static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 , T_1 * V_7 )
{
T_2 V_8 [ 2 ] = { V_6 >> 8 , V_6 & 0xff } ;
struct V_9 V_10 [ 2 ] ;
T_2 V_11 [ 2 ] ;
int V_12 ;
V_10 [ 0 ] . V_6 = V_5 -> V_6 ;
V_10 [ 0 ] . V_13 = 0 ;
V_10 [ 0 ] . V_14 = 2 ;
V_10 [ 0 ] . V_15 = V_8 ;
V_10 [ 1 ] . V_6 = V_5 -> V_6 ;
V_10 [ 1 ] . V_13 = V_16 ;
V_10 [ 1 ] . V_14 = 2 ;
V_10 [ 1 ] . V_15 = V_11 ;
V_12 = F_4 ( V_5 -> V_17 , V_10 , 2 ) ;
* V_7 = F_5 ( * ( ( T_1 * ) V_11 ) ) ;
F_6 ( 4 , V_18 , V_5 , L_1 , V_6 , * V_7 ) ;
return V_12 == 2 ? 0 : V_12 ;
}
static int F_7 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
T_2 V_15 [ 4 ] = { V_6 >> 8 , V_6 & 0xff , V_7 >> 8 , V_7 & 0xff } ;
int V_12 = F_8 ( V_5 , V_15 , 4 ) ;
F_6 ( 4 , V_18 , V_5 , L_2 , V_6 , V_7 ) ;
return V_12 == 4 ? 0 : V_12 ;
}
static int F_9 ( struct V_4 * V_5 , T_3 V_6 , T_1 V_7 )
{
T_1 V_19 = V_6 >> 16 , V_20 = V_6 & 0xffff ;
int V_12 ;
F_6 ( 3 , V_18 , V_5 , L_3 , V_6 , V_7 ) ;
V_12 = F_7 ( V_5 , V_21 , V_19 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_5 , V_22 , V_20 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_5 , V_23 , V_7 ) ;
return V_12 ;
}
static int F_10 ( struct V_4 * V_5 , T_3 V_6 , T_1 * V_7 )
{
T_1 V_19 = V_6 >> 16 , V_20 = V_6 & 0xffff ;
int V_12 ;
V_12 = F_7 ( V_5 , V_24 , V_19 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_5 , V_25 , V_20 ) ;
if ( ! V_12 )
V_12 = F_3 ( V_5 , V_23 , V_7 ) ;
if ( ! V_12 )
F_11 ( & V_5 -> V_26 , L_4 ) ;
return V_12 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_13 ( V_3 ) ;
T_1 V_27 , V_28 = 0 ;
int V_12 ;
V_12 = F_10 ( V_5 , V_29 , & V_28 ) ;
if ( V_12 < 0 || V_28 != V_30 ) {
F_14 ( V_3 , L_5 ) ;
return - V_31 ;
}
V_12 = F_10 ( V_5 , V_32 , & V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
F_15 ( V_3 , L_6 ,
V_28 , V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_13 ( V_3 ) ;
int V_12 ;
V_12 = F_7 ( V_5 , V_33 , V_34 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_5 , 0x0010 , 0x0001 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_5 , 0x1030 , 0x0000 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( V_5 , 0x0014 , 0x0001 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_13 ( V_3 ) ;
const struct V_35 * V_36 ;
const T_2 * V_37 ;
int V_38 , V_39 , V_40 ;
T_3 V_6 , V_41 , V_42 , V_43 = 0 ;
T_1 V_7 ;
V_38 = F_18 ( & V_36 , V_44 , V_3 -> V_45 -> V_26 ) ;
if ( V_38 ) {
F_14 ( V_3 , L_7 , V_44 ) ;
return V_38 ;
}
V_40 = F_19 ( F_20 ( V_36 -> V_46 ) ) ;
F_6 ( 3 , V_18 , V_3 , L_8 ,
V_44 , V_36 -> V_47 , V_40 ) ;
V_40 ++ ;
if ( V_36 -> V_47 != V_40 * V_48 + V_49 ) {
V_38 = - V_50 ;
goto V_51;
}
V_42 = F_19 ( F_20 ( V_36 -> V_46 +
V_40 * V_48 ) ) ;
V_41 = F_21 ( ~ 0 , V_36 -> V_46 , V_40 * V_48 ) ;
if ( V_41 != V_42 ) {
F_14 ( V_3 , L_9 , V_41 , V_42 ) ;
V_38 = - V_50 ;
goto V_51;
}
V_37 = V_36 -> V_46 + V_48 ;
for ( V_39 = 1 ; V_39 < V_40 ; V_39 ++ ) {
V_6 = F_19 ( F_20 ( V_37 ) ) ;
V_37 += sizeof( T_3 ) ;
V_7 = F_22 ( F_23 ( V_37 ) ) ;
V_37 += sizeof( T_1 ) ;
if ( V_6 - V_43 != 2 )
V_38 = F_9 ( V_5 , V_6 , V_7 ) ;
else
V_38 = F_7 ( V_5 , V_23 , V_7 ) ;
if ( V_38 )
break;
V_43 = V_6 ;
}
V_51:
F_24 ( V_36 ) ;
return V_38 ;
}
static int F_25 ( struct V_4 * V_52 ,
const struct V_53 * V_54 )
{
int V_12 ;
V_12 = F_9 ( V_52 , V_55 , V_54 -> V_56 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_57 , V_54 -> V_58 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_59 , V_54 -> V_60 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_61 , V_54 -> V_62 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_63 , V_54 -> V_56 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_64 , V_54 -> V_58 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_65 , V_54 -> V_60 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_66 , V_54 -> V_62 ) ;
return V_12 ;
}
static int F_26 ( struct V_4 * V_52 ,
const struct V_53 * V_54 )
{
int V_12 ;
V_12 = F_9 ( V_52 , V_67 , V_54 -> V_56 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_68 , V_54 -> V_58 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_69 , V_54 -> V_60 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_70 , V_54 -> V_62 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_71 , V_54 -> V_56 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_72 , V_54 -> V_58 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_73 , V_54 -> V_60 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_52 , V_74 , V_54 -> V_62 ) ;
return V_12 ;
}
static int F_27 ( struct V_1 * V_75 )
{
struct V_4 * V_5 = F_13 ( & V_75 -> V_3 ) ;
int V_12 ;
V_12 = F_9 ( V_5 , F_28 ( 0 ) ,
V_75 -> V_76 -> V_47 . V_56 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_29 ( 0 ) ,
V_75 -> V_76 -> V_47 . V_58 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_30 ( 0 ) ,
V_75 -> V_77 -> V_78 ) ;
return V_12 ;
}
static int F_31 ( struct V_2 * V_3 )
{
int V_12 ;
V_12 = F_16 ( V_3 ) ;
F_32 ( 100 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_3 ) ;
if ( V_12 )
F_14 ( V_3 , L_10 ) ;
return V_12 ;
}
static int F_33 ( struct V_1 * V_75 , int V_79 , T_3 V_7 )
{
if ( ! F_34 ( V_75 -> V_80 [ V_79 ] . V_80 ) )
return 0 ;
F_35 ( V_75 -> V_80 [ V_79 ] . V_80 , V_7 ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_75 )
{
int V_12 ;
V_12 = F_37 ( V_81 , V_75 -> V_82 ) ;
if ( V_12 )
return V_12 ;
F_38 ( 30 , 50 ) ;
if ( F_33 ( V_75 , V_83 , V_75 -> V_80 [ V_83 ] . V_84 ) )
F_38 ( 30 , 50 ) ;
if ( F_33 ( V_75 , V_85 , V_75 -> V_80 [ V_85 ] . V_84 ) )
F_38 ( 30 , 50 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_75 )
{
if ( F_33 ( V_75 , V_85 , ! V_75 -> V_80 [ V_85 ] . V_84 ) )
F_38 ( 30 , 50 ) ;
if ( F_33 ( V_75 , V_83 , ! V_75 -> V_80 [ V_83 ] . V_84 ) )
F_38 ( 30 , 50 ) ;
V_75 -> V_86 = 0 ;
return F_40 ( V_81 , V_75 -> V_82 ) ;
}
static int F_41 ( struct V_87 * V_88 ,
const struct V_89 * * V_47 )
{
unsigned int V_90 = ~ 0 ;
int V_39 = F_42 ( V_91 ) ;
const struct V_89 * V_92 = & V_91 [ 0 ] ,
* V_93 = NULL ;
while ( V_39 -- ) {
int V_38 = abs ( V_92 -> V_47 . V_56 - V_88 -> V_56 )
+ abs ( V_92 -> V_47 . V_58 - V_88 -> V_58 ) ;
if ( V_38 < V_90 ) {
V_90 = V_38 ;
V_93 = V_92 ;
}
V_92 ++ ;
}
if ( V_93 ) {
V_88 -> V_56 = V_93 -> V_47 . V_56 ;
V_88 -> V_58 = V_93 -> V_47 . V_58 ;
if ( V_47 )
* V_47 = V_93 ;
return 0 ;
}
return - V_50 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_94 * V_95 ,
struct V_96 * V_97 )
{
if ( V_97 -> V_98 >= F_42 ( V_99 ) )
return - V_50 ;
V_97 -> V_97 = V_99 [ V_97 -> V_98 ] . V_97 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , struct V_94 * V_95 ,
struct V_100 * V_101 )
{
struct V_1 * V_75 = F_1 ( V_3 ) ;
struct V_87 * V_88 ;
if ( V_101 -> V_102 == V_103 ) {
if ( V_95 ) {
V_88 = F_45 ( V_95 , 0 ) ;
V_101 -> V_104 = * V_88 ;
}
return 0 ;
}
V_88 = & V_101 -> V_104 ;
F_46 ( & V_75 -> V_105 ) ;
V_88 -> V_56 = V_75 -> V_76 -> V_47 . V_56 ;
V_88 -> V_58 = V_75 -> V_76 -> V_47 . V_58 ;
V_88 -> V_97 = V_75 -> V_77 -> V_97 ;
V_88 -> V_106 = V_75 -> V_77 -> V_106 ;
V_88 -> V_107 = V_108 ;
F_47 ( & V_75 -> V_105 ) ;
return 0 ;
}
static const struct V_109 * F_48 ( struct V_2 * V_3 ,
struct V_87 * V_88 )
{
int V_39 = F_42 ( V_99 ) ;
while ( -- V_39 )
if ( V_88 -> V_97 == V_99 [ V_39 ] . V_97 )
break;
V_88 -> V_97 = V_99 [ V_39 ] . V_97 ;
return & V_99 [ V_39 ] ;
}
static int F_49 ( struct V_2 * V_3 , struct V_94 * V_95 ,
struct V_100 * V_101 )
{
struct V_1 * V_75 = F_1 ( V_3 ) ;
const struct V_89 * V_92 = NULL ;
const struct V_109 * V_110 ;
struct V_87 * V_88 ;
int V_12 = 0 ;
V_110 = F_48 ( V_3 , & V_101 -> V_104 ) ;
F_41 ( & V_101 -> V_104 , & V_92 ) ;
V_101 -> V_104 . V_106 = V_111 ;
if ( V_101 -> V_102 == V_103 ) {
if ( V_95 ) {
V_88 = F_45 ( V_95 , 0 ) ;
* V_88 = V_101 -> V_104 ;
}
return 0 ;
}
F_46 ( & V_75 -> V_105 ) ;
if ( ! V_75 -> V_86 ) {
V_75 -> V_76 = V_92 ;
V_75 -> V_77 = V_110 ;
V_75 -> V_112 = 1 ;
} else {
V_12 = - V_113 ;
}
F_47 ( & V_75 -> V_105 ) ;
return V_12 ;
}
static int F_50 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = & F_2 ( V_115 -> V_116 , struct V_1 ,
V_116 ) -> V_3 ;
struct V_4 * V_5 = F_13 ( V_3 ) ;
struct V_1 * V_75 = F_1 ( V_3 ) ;
unsigned int V_39 ;
int V_38 = 0 ;
F_6 ( 1 , V_18 , V_3 , L_11 , V_115 -> V_79 , V_115 -> V_7 ) ;
F_46 ( & V_75 -> V_105 ) ;
switch ( V_115 -> V_79 ) {
case V_117 :
V_38 = F_9 ( V_5 , V_118 , V_115 -> V_7 ) ;
break;
case V_119 :
V_38 = F_9 ( V_5 , V_120 , V_115 -> V_7 ) ;
break;
case V_121 :
for ( V_39 = 0 ; V_39 < 4 && ! V_38 ; V_39 ++ )
V_38 = F_9 ( V_5 , F_51 ( V_39 ) ,
V_115 -> V_7 * V_122 ) ;
break;
case V_123 :
V_38 = F_9 ( V_5 , V_124 , V_115 -> V_7 ) ;
break;
}
F_47 ( & V_75 -> V_105 ) ;
if ( V_38 < 0 )
F_14 ( V_3 , L_12 , V_38 ) ;
return V_38 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_12 ;
struct V_1 * V_75 = F_1 ( V_3 ) ;
F_46 ( & V_75 -> V_105 ) ;
V_12 = F_36 ( V_75 ) ;
if ( ! V_12 ) {
V_12 = F_12 ( V_3 ) ;
F_39 ( V_75 ) ;
}
F_47 ( & V_75 -> V_105 ) ;
return V_12 ;
}
static int F_53 ( struct V_2 * V_3 , struct V_94 * V_95 )
{
struct V_87 * V_88 = F_45 ( V_95 , 0 ) ;
V_88 -> V_56 = V_91 [ 0 ] . V_47 . V_56 ;
V_88 -> V_58 = V_91 [ 0 ] . V_47 . V_58 ;
V_88 -> V_97 = V_99 [ 0 ] . V_97 ;
V_88 -> V_106 = V_111 ;
V_88 -> V_107 = V_108 ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , int V_125 )
{
struct V_1 * V_75 = F_1 ( V_3 ) ;
int V_12 ;
F_6 ( 1 , V_18 , V_3 , L_13 , V_125 ? L_14 : L_15 ) ;
if ( V_125 ) {
V_12 = F_36 ( V_75 ) ;
if ( V_12 < 0 )
return V_12 ;
F_32 ( 100 ) ;
V_12 = F_31 ( V_3 ) ;
if ( V_12 < 0 )
F_39 ( V_75 ) ;
else
V_75 -> V_112 = 1 ;
} else {
V_12 = F_39 ( V_75 ) ;
}
return V_12 ;
}
static int F_55 ( struct V_2 * V_3 )
{
F_56 ( V_3 -> V_126 , V_3 -> V_127 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_75 )
{
struct V_4 * V_5 = F_13 ( & V_75 -> V_3 ) ;
const struct V_53 * V_128 = & V_75 -> V_76 -> V_129 ;
int V_12 ;
V_12 = F_25 ( V_5 , V_128 ) ;
if ( ! V_12 )
V_12 = F_26 ( V_5 , V_128 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_130 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , 0x70000a1e , 0x28 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , 0x70000ad4 , 0x3c ) ;
if ( ! V_12 )
V_12 = F_27 ( V_75 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_58 ( 0 ) , 0x52 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_59 ( 0 ) ,
V_131 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_60 ( 0 ) ,
V_132 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_61 ( 0 ) ,
F_62 ( 33300 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_63 ( 0 ) ,
F_62 ( 66600 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_64 ( 0 ) , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_65 ( 0 ) , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_133 , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_134 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_135 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_136 , 1 ) ;
return V_12 ;
}
static int F_66 ( struct V_1 * V_75 , int V_125 )
{
struct V_4 * V_5 = F_13 ( & V_75 -> V_3 ) ;
int V_12 ;
if ( V_125 && V_75 -> V_112 ) {
V_12 = F_57 ( V_75 ) ;
if ( V_12 < 0 )
return V_12 ;
V_75 -> V_112 = 0 ;
}
V_12 = F_9 ( V_5 , V_137 , V_125 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_9 ( V_5 , V_138 , 1 ) ;
}
static int F_67 ( struct V_2 * V_3 , int V_125 )
{
struct V_1 * V_75 = F_1 ( V_3 ) ;
int V_12 = 0 ;
F_6 ( 1 , V_18 , V_3 , L_16 , V_125 ? L_14 : L_15 ) ;
F_46 ( & V_75 -> V_105 ) ;
if ( V_75 -> V_86 == ! V_125 ) {
V_12 = F_66 ( V_75 , V_125 ) ;
if ( ! V_12 )
V_75 -> V_86 = V_125 & 1 ;
}
F_47 ( & V_75 -> V_105 ) ;
return V_12 ;
}
static int F_68 ( int V_139 , int V_7 , const char * V_127 )
{
unsigned long V_13 = V_7 ? V_140 : V_141 ;
int V_12 ;
if ( ! F_34 ( V_139 ) )
return 0 ;
V_12 = F_69 ( V_139 , V_13 , V_127 ) ;
if ( ! V_12 )
F_70 ( V_139 , 0 ) ;
return V_12 ;
}
static void F_71 ( struct V_1 * V_75 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_42 ( V_75 -> V_80 ) ; V_39 ++ ) {
if ( ! F_34 ( V_75 -> V_80 [ V_39 ] . V_80 ) )
continue;
F_72 ( V_75 -> V_80 [ V_39 ] . V_80 ) ;
V_75 -> V_80 [ V_39 ] . V_80 = - V_50 ;
}
}
static int F_73 ( struct V_1 * V_75 ,
const struct V_142 * V_143 )
{
const struct V_144 * V_80 = & V_143 -> V_145 ;
int V_12 ;
V_75 -> V_80 [ V_83 ] . V_80 = - V_50 ;
V_75 -> V_80 [ V_85 ] . V_80 = - V_50 ;
V_12 = F_68 ( V_80 -> V_80 , V_80 -> V_84 , L_17 ) ;
if ( V_12 ) {
F_71 ( V_75 ) ;
return V_12 ;
}
V_75 -> V_80 [ V_83 ] = * V_80 ;
if ( F_34 ( V_80 -> V_80 ) )
F_35 ( V_80 -> V_80 , 0 ) ;
V_80 = & V_143 -> V_146 ;
V_12 = F_68 ( V_80 -> V_80 , V_80 -> V_84 , L_18 ) ;
if ( V_12 ) {
F_71 ( V_75 ) ;
return V_12 ;
}
V_75 -> V_80 [ V_85 ] = * V_80 ;
if ( F_34 ( V_80 -> V_80 ) )
F_35 ( V_80 -> V_80 , 0 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_75 )
{
const struct V_147 * V_148 = & V_149 ;
struct V_150 * V_151 = & V_75 -> V_116 ;
int V_12 ;
V_12 = F_75 ( V_151 , 4 ) ;
if ( V_12 )
return V_12 ;
F_76 ( V_151 , V_148 , V_123 , - 208 , 127 , 1 , 0 ) ;
F_76 ( V_151 , V_148 , V_117 , - 127 , 127 , 1 , 0 ) ;
F_76 ( V_151 , V_148 , V_119 , - 127 , 127 , 1 , 0 ) ;
F_76 ( V_151 , V_148 , V_121 , - 32704 / V_122 ,
24612 / V_122 , 1 , 2 ) ;
if ( V_151 -> error ) {
V_12 = V_151 -> error ;
F_77 ( V_151 ) ;
return V_12 ;
}
V_75 -> V_3 . V_126 = V_151 ;
return 0 ;
}
static int F_78 ( struct V_4 * V_5 ,
const struct V_152 * V_79 )
{
struct V_142 * V_143 = V_5 -> V_26 . V_153 ;
struct V_2 * V_3 ;
struct V_1 * V_75 ;
int V_12 , V_39 ;
if ( V_143 == NULL ) {
F_11 ( & V_5 -> V_26 , L_19 ) ;
return - V_50 ;
}
V_75 = F_79 ( & V_5 -> V_26 , sizeof( struct V_1 ) , V_154 ) ;
if ( ! V_75 )
return - V_155 ;
F_80 ( & V_75 -> V_105 ) ;
V_75 -> V_86 = 0 ;
V_3 = & V_75 -> V_3 ;
F_81 ( V_3 , V_5 , & V_156 ) ;
F_82 ( V_3 -> V_127 , V_157 , sizeof( V_3 -> V_127 ) ) ;
V_3 -> V_158 = & V_159 ;
V_3 -> V_13 |= V_160 ;
V_75 -> V_161 . V_13 = V_162 ;
V_3 -> V_163 . type = V_164 ;
V_12 = F_83 ( & V_3 -> V_163 , 1 , & V_75 -> V_161 , 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_73 ( V_75 , V_143 ) ;
if ( V_12 ) {
F_11 ( & V_5 -> V_26 , L_20 ) ;
goto V_165;
}
for ( V_39 = 0 ; V_39 < V_81 ; V_39 ++ )
V_75 -> V_82 [ V_39 ] . V_166 = V_167 [ V_39 ] ;
V_12 = F_84 ( & V_5 -> V_26 , V_81 ,
V_75 -> V_82 ) ;
if ( V_12 ) {
F_11 ( & V_5 -> V_26 , L_21 ) ;
goto V_168;
}
V_12 = F_74 ( V_75 ) ;
if ( V_12 )
goto V_168;
V_75 -> V_77 = & V_99 [ 0 ] ;
V_75 -> V_76 = & V_91 [ 0 ] ;
return 0 ;
V_168:
F_71 ( V_75 ) ;
V_165:
F_85 ( & V_75 -> V_3 . V_163 ) ;
return V_12 ;
}
static int F_86 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_87 ( V_5 ) ;
struct V_1 * V_75 = F_1 ( V_3 ) ;
F_88 ( & V_75 -> V_105 ) ;
F_71 ( V_75 ) ;
F_89 ( V_3 ) ;
F_77 ( & V_75 -> V_116 ) ;
F_85 ( & V_3 -> V_163 ) ;
return 0 ;
}
