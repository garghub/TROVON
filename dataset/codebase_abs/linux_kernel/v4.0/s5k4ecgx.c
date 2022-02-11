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
* V_7 = F_5 ( * ( ( V_18 * ) V_11 ) ) ;
F_6 ( 4 , V_19 , V_5 , L_1 , V_6 , * V_7 ) ;
return V_12 == 2 ? 0 : V_12 ;
}
static int F_7 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
T_2 V_15 [ 4 ] = { V_6 >> 8 , V_6 & 0xff , V_7 >> 8 , V_7 & 0xff } ;
int V_12 = F_8 ( V_5 , V_15 , 4 ) ;
F_6 ( 4 , V_19 , V_5 , L_2 , V_6 , V_7 ) ;
return V_12 == 4 ? 0 : V_12 ;
}
static int F_9 ( struct V_4 * V_5 , T_3 V_6 , T_1 V_7 )
{
T_1 V_20 = V_6 >> 16 , V_21 = V_6 & 0xffff ;
int V_12 ;
F_6 ( 3 , V_19 , V_5 , L_3 , V_6 , V_7 ) ;
V_12 = F_7 ( V_5 , V_22 , V_20 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_5 , V_23 , V_21 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_5 , V_24 , V_7 ) ;
return V_12 ;
}
static int F_10 ( struct V_4 * V_5 , T_3 V_6 , T_1 * V_7 )
{
T_1 V_20 = V_6 >> 16 , V_21 = V_6 & 0xffff ;
int V_12 ;
V_12 = F_7 ( V_5 , V_25 , V_20 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_5 , V_26 , V_21 ) ;
if ( ! V_12 )
V_12 = F_3 ( V_5 , V_24 , V_7 ) ;
if ( ! V_12 )
F_11 ( & V_5 -> V_27 , L_4 ) ;
return V_12 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_13 ( V_3 ) ;
T_1 V_28 , V_29 = 0 ;
int V_12 ;
V_12 = F_10 ( V_5 , V_30 , & V_29 ) ;
if ( V_12 < 0 || V_29 != V_31 ) {
F_14 ( V_3 , L_5 ) ;
return - V_32 ;
}
V_12 = F_10 ( V_5 , V_33 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
F_15 ( V_3 , L_6 ,
V_29 , V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_13 ( V_3 ) ;
int V_12 ;
V_12 = F_7 ( V_5 , V_34 , V_35 ) ;
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
const struct V_36 * V_37 ;
const T_2 * V_38 ;
int V_39 , V_40 , V_41 ;
T_3 V_6 , V_42 , V_43 , V_44 = 0 ;
T_1 V_7 ;
V_39 = F_18 ( & V_37 , V_45 , V_3 -> V_46 -> V_27 ) ;
if ( V_39 ) {
F_14 ( V_3 , L_7 , V_45 ) ;
return V_39 ;
}
V_41 = F_19 ( V_37 -> V_47 ) ;
F_6 ( 3 , V_19 , V_3 , L_8 ,
V_45 , V_37 -> V_48 , V_41 ) ;
V_41 ++ ;
if ( V_37 -> V_48 != V_41 * V_49 + V_50 ) {
V_39 = - V_51 ;
goto V_52;
}
V_43 = F_19 ( V_37 -> V_47 + V_41 * V_49 ) ;
V_42 = F_20 ( ~ 0 , V_37 -> V_47 , V_41 * V_49 ) ;
if ( V_42 != V_43 ) {
F_14 ( V_3 , L_9 , V_42 , V_43 ) ;
V_39 = - V_51 ;
goto V_52;
}
V_38 = V_37 -> V_47 + V_49 ;
for ( V_40 = 1 ; V_40 < V_41 ; V_40 ++ ) {
V_6 = F_19 ( V_38 ) ;
V_38 += sizeof( T_3 ) ;
V_7 = F_21 ( V_38 ) ;
V_38 += sizeof( T_1 ) ;
if ( V_6 - V_44 != 2 )
V_39 = F_9 ( V_5 , V_6 , V_7 ) ;
else
V_39 = F_7 ( V_5 , V_24 , V_7 ) ;
if ( V_39 )
break;
V_44 = V_6 ;
}
V_52:
F_22 ( V_37 ) ;
return V_39 ;
}
static int F_23 ( struct V_4 * V_53 ,
const struct V_54 * V_55 )
{
int V_12 ;
V_12 = F_9 ( V_53 , V_56 , V_55 -> V_57 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_58 , V_55 -> V_59 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_60 , V_55 -> V_61 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_62 , V_55 -> V_63 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_64 , V_55 -> V_57 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_65 , V_55 -> V_59 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_66 , V_55 -> V_61 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_67 , V_55 -> V_63 ) ;
return V_12 ;
}
static int F_24 ( struct V_4 * V_53 ,
const struct V_54 * V_55 )
{
int V_12 ;
V_12 = F_9 ( V_53 , V_68 , V_55 -> V_57 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_69 , V_55 -> V_59 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_70 , V_55 -> V_61 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_71 , V_55 -> V_63 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_72 , V_55 -> V_57 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_73 , V_55 -> V_59 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_74 , V_55 -> V_61 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_53 , V_75 , V_55 -> V_63 ) ;
return V_12 ;
}
static int F_25 ( struct V_1 * V_76 )
{
struct V_4 * V_5 = F_13 ( & V_76 -> V_3 ) ;
int V_12 ;
V_12 = F_9 ( V_5 , F_26 ( 0 ) ,
V_76 -> V_77 -> V_48 . V_57 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_27 ( 0 ) ,
V_76 -> V_77 -> V_48 . V_59 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_28 ( 0 ) ,
V_76 -> V_78 -> V_79 ) ;
return V_12 ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_12 ;
V_12 = F_16 ( V_3 ) ;
F_30 ( 100 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_3 ) ;
if ( V_12 )
F_14 ( V_3 , L_10 ) ;
return V_12 ;
}
static int F_31 ( struct V_1 * V_76 , int V_80 , T_3 V_7 )
{
if ( ! F_32 ( V_76 -> V_81 [ V_80 ] . V_81 ) )
return 0 ;
F_33 ( V_76 -> V_81 [ V_80 ] . V_81 , V_7 ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_76 )
{
int V_12 ;
V_12 = F_35 ( V_82 , V_76 -> V_83 ) ;
if ( V_12 )
return V_12 ;
F_36 ( 30 , 50 ) ;
if ( F_31 ( V_76 , V_84 , V_76 -> V_81 [ V_84 ] . V_85 ) )
F_36 ( 30 , 50 ) ;
if ( F_31 ( V_76 , V_86 , V_76 -> V_81 [ V_86 ] . V_85 ) )
F_36 ( 30 , 50 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_76 )
{
if ( F_31 ( V_76 , V_86 , ! V_76 -> V_81 [ V_86 ] . V_85 ) )
F_36 ( 30 , 50 ) ;
if ( F_31 ( V_76 , V_84 , ! V_76 -> V_81 [ V_84 ] . V_85 ) )
F_36 ( 30 , 50 ) ;
V_76 -> V_87 = 0 ;
return F_38 ( V_82 , V_76 -> V_83 ) ;
}
static int F_39 ( struct V_88 * V_89 ,
const struct V_90 * * V_48 )
{
unsigned int V_91 = ~ 0 ;
int V_40 = F_40 ( V_92 ) ;
const struct V_90 * V_93 = & V_92 [ 0 ] ,
* V_94 = NULL ;
while ( V_40 -- ) {
int V_39 = abs ( V_93 -> V_48 . V_57 - V_89 -> V_57 )
+ abs ( V_93 -> V_48 . V_59 - V_89 -> V_59 ) ;
if ( V_39 < V_91 ) {
V_91 = V_39 ;
V_94 = V_93 ;
}
V_93 ++ ;
}
if ( V_94 ) {
V_89 -> V_57 = V_94 -> V_48 . V_57 ;
V_89 -> V_59 = V_94 -> V_48 . V_59 ;
if ( V_48 )
* V_48 = V_94 ;
return 0 ;
}
return - V_51 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
if ( V_98 -> V_99 >= F_40 ( V_100 ) )
return - V_51 ;
V_98 -> V_98 = V_100 [ V_98 -> V_99 ] . V_98 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_95 * V_96 ,
struct V_101 * V_102 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_88 * V_89 ;
if ( V_102 -> V_103 == V_104 ) {
if ( V_96 ) {
V_89 = F_43 ( V_96 , 0 ) ;
V_102 -> V_105 = * V_89 ;
}
return 0 ;
}
V_89 = & V_102 -> V_105 ;
F_44 ( & V_76 -> V_106 ) ;
V_89 -> V_57 = V_76 -> V_77 -> V_48 . V_57 ;
V_89 -> V_59 = V_76 -> V_77 -> V_48 . V_59 ;
V_89 -> V_98 = V_76 -> V_78 -> V_98 ;
V_89 -> V_107 = V_76 -> V_78 -> V_107 ;
V_89 -> V_108 = V_109 ;
F_45 ( & V_76 -> V_106 ) ;
return 0 ;
}
static const struct V_110 * F_46 ( struct V_2 * V_3 ,
struct V_88 * V_89 )
{
int V_40 = F_40 ( V_100 ) ;
while ( -- V_40 )
if ( V_89 -> V_98 == V_100 [ V_40 ] . V_98 )
break;
V_89 -> V_98 = V_100 [ V_40 ] . V_98 ;
return & V_100 [ V_40 ] ;
}
static int F_47 ( struct V_2 * V_3 , struct V_95 * V_96 ,
struct V_101 * V_102 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
const struct V_90 * V_93 = NULL ;
const struct V_110 * V_111 ;
struct V_88 * V_89 ;
int V_12 = 0 ;
V_111 = F_46 ( V_3 , & V_102 -> V_105 ) ;
F_39 ( & V_102 -> V_105 , & V_93 ) ;
V_102 -> V_105 . V_107 = V_112 ;
V_102 -> V_105 . V_108 = V_109 ;
if ( V_102 -> V_103 == V_104 ) {
if ( V_96 ) {
V_89 = F_43 ( V_96 , 0 ) ;
* V_89 = V_102 -> V_105 ;
}
return 0 ;
}
F_44 ( & V_76 -> V_106 ) ;
if ( ! V_76 -> V_87 ) {
V_76 -> V_77 = V_93 ;
V_76 -> V_78 = V_111 ;
V_76 -> V_113 = 1 ;
} else {
V_12 = - V_114 ;
}
F_45 ( & V_76 -> V_106 ) ;
return V_12 ;
}
static int F_48 ( struct V_115 * V_116 )
{
struct V_2 * V_3 = & F_2 ( V_116 -> V_117 , struct V_1 ,
V_117 ) -> V_3 ;
struct V_4 * V_5 = F_13 ( V_3 ) ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
unsigned int V_40 ;
int V_39 = 0 ;
F_6 ( 1 , V_19 , V_3 , L_11 , V_116 -> V_80 , V_116 -> V_7 ) ;
F_44 ( & V_76 -> V_106 ) ;
switch ( V_116 -> V_80 ) {
case V_118 :
V_39 = F_9 ( V_5 , V_119 , V_116 -> V_7 ) ;
break;
case V_120 :
V_39 = F_9 ( V_5 , V_121 , V_116 -> V_7 ) ;
break;
case V_122 :
for ( V_40 = 0 ; V_40 < 4 && ! V_39 ; V_40 ++ )
V_39 = F_9 ( V_5 , F_49 ( V_40 ) ,
V_116 -> V_7 * V_123 ) ;
break;
case V_124 :
V_39 = F_9 ( V_5 , V_125 , V_116 -> V_7 ) ;
break;
}
F_45 ( & V_76 -> V_106 ) ;
if ( V_39 < 0 )
F_14 ( V_3 , L_12 , V_39 ) ;
return V_39 ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_12 ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
F_44 ( & V_76 -> V_106 ) ;
V_12 = F_34 ( V_76 ) ;
if ( ! V_12 ) {
V_12 = F_12 ( V_3 ) ;
F_37 ( V_76 ) ;
}
F_45 ( & V_76 -> V_106 ) ;
return V_12 ;
}
static int F_51 ( struct V_2 * V_3 , struct V_95 * V_96 )
{
struct V_88 * V_89 = F_43 ( V_96 , 0 ) ;
V_89 -> V_57 = V_92 [ 0 ] . V_48 . V_57 ;
V_89 -> V_59 = V_92 [ 0 ] . V_48 . V_59 ;
V_89 -> V_98 = V_100 [ 0 ] . V_98 ;
V_89 -> V_107 = V_112 ;
V_89 -> V_108 = V_109 ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , int V_126 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
int V_12 ;
F_6 ( 1 , V_19 , V_3 , L_13 , V_126 ? L_14 : L_15 ) ;
if ( V_126 ) {
V_12 = F_34 ( V_76 ) ;
if ( V_12 < 0 )
return V_12 ;
F_30 ( 100 ) ;
V_12 = F_29 ( V_3 ) ;
if ( V_12 < 0 )
F_37 ( V_76 ) ;
else
V_76 -> V_113 = 1 ;
} else {
V_12 = F_37 ( V_76 ) ;
}
return V_12 ;
}
static int F_53 ( struct V_2 * V_3 )
{
F_54 ( V_3 -> V_127 , V_3 -> V_128 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_76 )
{
struct V_4 * V_5 = F_13 ( & V_76 -> V_3 ) ;
const struct V_54 * V_129 = & V_76 -> V_77 -> V_130 ;
int V_12 ;
V_12 = F_23 ( V_5 , V_129 ) ;
if ( ! V_12 )
V_12 = F_24 ( V_5 , V_129 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_131 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , 0x70000a1e , 0x28 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , 0x70000ad4 , 0x3c ) ;
if ( ! V_12 )
V_12 = F_25 ( V_76 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_56 ( 0 ) , 0x52 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_57 ( 0 ) ,
V_132 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_58 ( 0 ) ,
V_133 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_59 ( 0 ) ,
F_60 ( 33300 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_61 ( 0 ) ,
F_60 ( 66600 ) ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_62 ( 0 ) , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , F_63 ( 0 ) , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_134 , 0 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_135 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_136 , 1 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_5 , V_137 , 1 ) ;
return V_12 ;
}
static int F_64 ( struct V_1 * V_76 , int V_126 )
{
struct V_4 * V_5 = F_13 ( & V_76 -> V_3 ) ;
int V_12 ;
if ( V_126 && V_76 -> V_113 ) {
V_12 = F_55 ( V_76 ) ;
if ( V_12 < 0 )
return V_12 ;
V_76 -> V_113 = 0 ;
}
V_12 = F_9 ( V_5 , V_138 , V_126 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_9 ( V_5 , V_139 , 1 ) ;
}
static int F_65 ( struct V_2 * V_3 , int V_126 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
int V_12 = 0 ;
F_6 ( 1 , V_19 , V_3 , L_16 , V_126 ? L_14 : L_15 ) ;
F_44 ( & V_76 -> V_106 ) ;
if ( V_76 -> V_87 == ! V_126 ) {
V_12 = F_64 ( V_76 , V_126 ) ;
if ( ! V_12 )
V_76 -> V_87 = V_126 & 1 ;
}
F_45 ( & V_76 -> V_106 ) ;
return V_12 ;
}
static int F_66 ( int V_140 , int V_7 , const char * V_128 )
{
unsigned long V_13 = V_7 ? V_141 : V_142 ;
int V_12 ;
if ( ! F_32 ( V_140 ) )
return 0 ;
V_12 = F_67 ( V_140 , V_13 , V_128 ) ;
if ( ! V_12 )
F_68 ( V_140 , 0 ) ;
return V_12 ;
}
static void F_69 ( struct V_1 * V_76 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_40 ( V_76 -> V_81 ) ; V_40 ++ ) {
if ( ! F_32 ( V_76 -> V_81 [ V_40 ] . V_81 ) )
continue;
F_70 ( V_76 -> V_81 [ V_40 ] . V_81 ) ;
V_76 -> V_81 [ V_40 ] . V_81 = - V_51 ;
}
}
static int F_71 ( struct V_1 * V_76 ,
const struct V_143 * V_144 )
{
const struct V_145 * V_81 = & V_144 -> V_146 ;
int V_12 ;
V_76 -> V_81 [ V_84 ] . V_81 = - V_51 ;
V_76 -> V_81 [ V_86 ] . V_81 = - V_51 ;
V_12 = F_66 ( V_81 -> V_81 , V_81 -> V_85 , L_17 ) ;
if ( V_12 ) {
F_69 ( V_76 ) ;
return V_12 ;
}
V_76 -> V_81 [ V_84 ] = * V_81 ;
if ( F_32 ( V_81 -> V_81 ) )
F_33 ( V_81 -> V_81 , 0 ) ;
V_81 = & V_144 -> V_147 ;
V_12 = F_66 ( V_81 -> V_81 , V_81 -> V_85 , L_18 ) ;
if ( V_12 ) {
F_69 ( V_76 ) ;
return V_12 ;
}
V_76 -> V_81 [ V_86 ] = * V_81 ;
if ( F_32 ( V_81 -> V_81 ) )
F_33 ( V_81 -> V_81 , 0 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_76 )
{
const struct V_148 * V_149 = & V_150 ;
struct V_151 * V_152 = & V_76 -> V_117 ;
int V_12 ;
V_12 = F_73 ( V_152 , 4 ) ;
if ( V_12 )
return V_12 ;
F_74 ( V_152 , V_149 , V_124 , - 208 , 127 , 1 , 0 ) ;
F_74 ( V_152 , V_149 , V_118 , - 127 , 127 , 1 , 0 ) ;
F_74 ( V_152 , V_149 , V_120 , - 127 , 127 , 1 , 0 ) ;
F_74 ( V_152 , V_149 , V_122 , - 32704 / V_123 ,
24612 / V_123 , 1 , 2 ) ;
if ( V_152 -> error ) {
V_12 = V_152 -> error ;
F_75 ( V_152 ) ;
return V_12 ;
}
V_76 -> V_3 . V_127 = V_152 ;
return 0 ;
}
static int F_76 ( struct V_4 * V_5 ,
const struct V_153 * V_80 )
{
struct V_143 * V_144 = V_5 -> V_27 . V_154 ;
struct V_2 * V_3 ;
struct V_1 * V_76 ;
int V_12 , V_40 ;
if ( V_144 == NULL ) {
F_11 ( & V_5 -> V_27 , L_19 ) ;
return - V_51 ;
}
V_76 = F_77 ( & V_5 -> V_27 , sizeof( struct V_1 ) , V_155 ) ;
if ( ! V_76 )
return - V_156 ;
F_78 ( & V_76 -> V_106 ) ;
V_76 -> V_87 = 0 ;
V_3 = & V_76 -> V_3 ;
F_79 ( V_3 , V_5 , & V_157 ) ;
F_80 ( V_3 -> V_128 , V_158 , sizeof( V_3 -> V_128 ) ) ;
V_3 -> V_159 = & V_160 ;
V_3 -> V_13 |= V_161 ;
V_76 -> V_162 . V_13 = V_163 ;
V_3 -> V_164 . type = V_165 ;
V_12 = F_81 ( & V_3 -> V_164 , 1 , & V_76 -> V_162 , 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_71 ( V_76 , V_144 ) ;
if ( V_12 ) {
F_11 ( & V_5 -> V_27 , L_20 ) ;
goto V_166;
}
for ( V_40 = 0 ; V_40 < V_82 ; V_40 ++ )
V_76 -> V_83 [ V_40 ] . V_167 = V_168 [ V_40 ] ;
V_12 = F_82 ( & V_5 -> V_27 , V_82 ,
V_76 -> V_83 ) ;
if ( V_12 ) {
F_11 ( & V_5 -> V_27 , L_21 ) ;
goto V_169;
}
V_12 = F_72 ( V_76 ) ;
if ( V_12 )
goto V_169;
V_76 -> V_78 = & V_100 [ 0 ] ;
V_76 -> V_77 = & V_92 [ 0 ] ;
return 0 ;
V_169:
F_69 ( V_76 ) ;
V_166:
F_83 ( & V_76 -> V_3 . V_164 ) ;
return V_12 ;
}
static int F_84 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_85 ( V_5 ) ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
F_86 ( & V_76 -> V_106 ) ;
F_69 ( V_76 ) ;
F_87 ( V_3 ) ;
F_75 ( & V_76 -> V_117 ) ;
F_83 ( & V_3 -> V_164 ) ;
return 0 ;
}
