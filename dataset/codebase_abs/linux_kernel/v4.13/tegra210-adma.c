static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_6 * V_7 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_7 -> V_8 + V_3 ) ;
}
static inline T_1 F_6 ( struct V_6 * V_7 , T_1 V_3 )
{
return F_4 ( V_7 -> V_8 + V_3 ) ;
}
static inline struct V_6 * F_7 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , struct V_6 , V_11 . V_12 ) ;
}
static inline struct V_13 * F_9 (
struct V_14 * V_15 )
{
return F_8 ( V_15 , struct V_13 , V_16 . V_17 ) ;
}
static inline struct V_18 * F_10 ( struct V_6 * V_7 )
{
return V_7 -> V_2 -> V_19 ;
}
static void F_11 ( struct V_20 * V_16 )
{
F_12 ( F_8 ( V_16 , struct V_13 , V_16 ) ) ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_21 * V_22 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
memcpy ( & V_7 -> V_22 , V_22 , sizeof( * V_22 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_23 ;
int V_24 ;
F_1 ( V_2 , V_25 , 0x1 ) ;
F_1 ( V_2 , V_26 , 0x1 ) ;
V_24 = F_15 ( F_4 ,
V_2 -> V_5 + V_26 ,
V_23 , V_23 == 0 , 20 , 10000 ) ;
if ( V_24 )
return V_24 ;
F_1 ( V_2 , V_27 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
enum V_28 V_29 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned int V_30 = V_7 -> V_30 ;
if ( V_7 -> V_31 )
return V_7 -> V_32 == V_29 ? 0 : - V_33 ;
switch ( V_29 ) {
case V_34 :
if ( V_30 > V_35 ) {
F_17 ( V_2 -> V_19 , L_1 ) ;
return - V_33 ;
}
if ( F_18 ( V_30 , & V_2 -> V_36 ) ) {
F_17 ( V_2 -> V_19 , L_2 ) ;
return - V_33 ;
}
break;
case V_37 :
if ( V_30 > V_38 ) {
F_17 ( V_2 -> V_19 , L_1 ) ;
return - V_33 ;
}
if ( F_18 ( V_30 , & V_2 -> V_39 ) ) {
F_17 ( V_2 -> V_19 , L_2 ) ;
return - V_33 ;
}
break;
default:
F_19 ( V_2 -> V_19 , L_3 ,
F_20 ( & V_7 -> V_11 . V_12 ) ) ;
return - V_33 ;
}
V_7 -> V_32 = V_29 ;
V_7 -> V_31 = true ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! V_7 -> V_31 )
return;
switch ( V_7 -> V_32 ) {
case V_34 :
F_22 ( V_7 -> V_30 , & V_2 -> V_36 ) ;
break;
case V_37 :
F_22 ( V_7 -> V_30 , & V_2 -> V_39 ) ;
break;
default:
F_19 ( V_2 -> V_19 , L_3 ,
F_20 ( & V_7 -> V_11 . V_12 ) ) ;
return;
}
V_7 -> V_31 = false ;
}
static T_1 F_23 ( struct V_6 * V_7 )
{
T_1 V_23 = F_6 ( V_7 , V_40 ) ;
return V_23 & V_41 ;
}
static T_1 F_24 ( struct V_6 * V_7 )
{
T_1 V_23 = F_23 ( V_7 ) ;
if ( V_23 )
F_5 ( V_7 , V_42 , V_23 ) ;
return V_23 ;
}
static void F_25 ( struct V_6 * V_7 )
{
unsigned int V_23 ;
F_5 ( V_7 , V_43 , 0 ) ;
F_24 ( V_7 ) ;
if ( F_26 ( F_4 , V_7 -> V_8 + V_44 ,
V_23 , ! ( V_23 & V_45 ) ,
20 , 10000 ) ) {
F_17 ( F_10 ( V_7 ) , L_4 ) ;
return;
}
F_12 ( V_7 -> V_46 ) ;
V_7 -> V_46 = NULL ;
}
static void F_27 ( struct V_6 * V_7 )
{
struct V_20 * V_16 = F_28 ( & V_7 -> V_11 ) ;
struct V_47 * V_48 ;
struct V_13 * V_46 ;
if ( ! V_16 )
return;
F_29 ( & V_16 -> V_49 ) ;
V_46 = F_9 ( & V_16 -> V_17 ) ;
if ( ! V_46 ) {
F_30 ( F_10 ( V_7 ) , L_5 ) ;
return;
}
V_48 = & V_46 -> V_48 ;
V_7 -> V_50 = 0 ;
V_7 -> V_51 = 0 ;
F_5 ( V_7 , V_52 , V_48 -> V_53 ) ;
F_5 ( V_7 , V_54 , V_48 -> V_55 ) ;
F_5 ( V_7 , V_56 , V_48 -> V_57 ) ;
F_5 ( V_7 , V_58 , V_48 -> V_59 ) ;
F_5 ( V_7 , V_60 , V_48 -> V_61 ) ;
F_5 ( V_7 , V_62 , V_48 -> V_63 ) ;
F_5 ( V_7 , V_43 , 1 ) ;
V_7 -> V_46 = V_46 ;
}
static unsigned int F_31 ( struct V_6 * V_7 )
{
struct V_13 * V_46 = V_7 -> V_46 ;
unsigned int V_64 = V_65 + 1 ;
unsigned int V_66 = F_6 ( V_7 , V_67 ) ;
unsigned int V_68 ;
if ( V_66 < V_7 -> V_50 )
V_7 -> V_51 += V_66 + ( V_64 - V_7 -> V_50 ) ;
else
V_7 -> V_51 += V_66 - V_7 -> V_50 ;
V_68 = V_7 -> V_51 % V_46 -> V_69 ;
V_7 -> V_50 = V_66 ;
return V_46 -> V_70 - ( V_68 * V_46 -> V_71 ) ;
}
static T_2 F_32 ( int V_72 , void * V_73 )
{
struct V_6 * V_7 = V_73 ;
unsigned long V_23 ;
unsigned long V_74 ;
F_33 ( & V_7 -> V_11 . V_75 , V_74 ) ;
V_23 = F_24 ( V_7 ) ;
if ( V_23 == 0 || ! V_7 -> V_46 ) {
F_34 ( & V_7 -> V_11 . V_75 , V_74 ) ;
return V_76 ;
}
F_35 ( & V_7 -> V_46 -> V_16 ) ;
F_34 ( & V_7 -> V_11 . V_75 , V_74 ) ;
return V_77 ;
}
static void F_36 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_74 ;
F_33 ( & V_7 -> V_11 . V_75 , V_74 ) ;
if ( F_37 ( & V_7 -> V_11 ) ) {
if ( ! V_7 -> V_46 )
F_27 ( V_7 ) ;
}
F_34 ( & V_7 -> V_11 . V_75 , V_74 ) ;
}
static int F_38 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
unsigned long V_74 ;
F_39 ( V_78 ) ;
F_33 ( & V_7 -> V_11 . V_75 , V_74 ) ;
if ( V_7 -> V_46 )
F_25 ( V_7 ) ;
F_21 ( V_7 ) ;
F_40 ( & V_7 -> V_11 , & V_78 ) ;
F_34 ( & V_7 -> V_11 . V_75 , V_74 ) ;
F_41 ( & V_7 -> V_11 , & V_78 ) ;
return 0 ;
}
static enum V_79 F_42 ( struct V_9 * V_10 ,
T_3 V_80 ,
struct V_81 * V_82 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_13 * V_46 ;
struct V_20 * V_16 ;
enum V_79 V_24 ;
unsigned long V_74 ;
unsigned int V_83 ;
V_24 = F_43 ( V_10 , V_80 , V_82 ) ;
if ( V_24 == V_84 || ! V_82 )
return V_24 ;
F_33 ( & V_7 -> V_11 . V_75 , V_74 ) ;
V_16 = F_44 ( & V_7 -> V_11 , V_80 ) ;
if ( V_16 ) {
V_46 = F_9 ( & V_16 -> V_17 ) ;
V_83 = V_46 -> V_48 . V_53 ;
} else if ( V_7 -> V_46 && V_7 -> V_46 -> V_16 . V_17 . V_80 == V_80 ) {
V_83 = F_31 ( V_7 ) ;
} else {
V_83 = 0 ;
}
F_34 ( & V_7 -> V_11 . V_75 , V_74 ) ;
F_45 ( V_82 , V_83 ) ;
return V_24 ;
}
static int F_46 ( struct V_6 * V_7 ,
struct V_13 * V_46 ,
T_4 V_85 ,
enum V_28 V_29 )
{
struct V_47 * V_48 = & V_46 -> V_48 ;
unsigned int V_86 , V_87 ;
if ( V_46 -> V_69 > V_88 )
return - V_33 ;
switch ( V_29 ) {
case V_34 :
V_87 = V_89 ;
V_86 = F_47 ( V_7 -> V_22 . V_90 ) ;
V_48 -> V_63 = F_48 ( V_46 -> V_69 - 1 ) ;
V_48 -> V_55 = F_49 ( V_7 -> V_30 ) ;
V_48 -> V_57 = V_85 ;
break;
case V_37 :
V_87 = V_91 ;
V_86 = F_47 ( V_7 -> V_22 . V_92 ) ;
V_48 -> V_63 = F_50 ( V_46 -> V_69 - 1 ) ;
V_48 -> V_55 = F_51 ( V_7 -> V_30 ) ;
V_48 -> V_59 = V_85 ;
break;
default:
F_17 ( F_10 ( V_7 ) , L_6 ) ;
return - V_33 ;
}
if ( ! V_86 || V_86 > V_93 )
V_86 = V_93 ;
V_48 -> V_55 |= F_52 ( V_87 ) |
V_94 |
V_95 ;
V_48 -> V_63 |= F_53 ( V_86 ) ;
V_48 -> V_63 |= F_54 ( 1 ) ;
V_48 -> V_61 = V_96 ;
V_48 -> V_53 = V_46 -> V_71 & V_97 ;
return F_16 ( V_7 , V_29 ) ;
}
static struct V_14 * F_55 (
struct V_9 * V_10 , T_4 V_85 , T_5 V_70 ,
T_5 V_71 , enum V_28 V_29 ,
unsigned long V_74 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
struct V_13 * V_46 = NULL ;
if ( ! V_70 || ! V_71 || V_71 > V_97 ) {
F_17 ( F_10 ( V_7 ) , L_7 ) ;
return NULL ;
}
if ( V_70 % V_71 ) {
F_17 ( F_10 ( V_7 ) , L_8 ) ;
return NULL ;
}
if ( ! F_56 ( V_85 , 4 ) ) {
F_17 ( F_10 ( V_7 ) , L_9 ) ;
return NULL ;
}
V_46 = F_57 ( sizeof( * V_46 ) , V_98 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_70 = V_70 ;
V_46 -> V_71 = V_71 ;
V_46 -> V_69 = V_70 / V_71 ;
if ( F_46 ( V_7 , V_46 , V_85 , V_29 ) ) {
F_12 ( V_46 ) ;
return NULL ;
}
return F_58 ( & V_7 -> V_11 , & V_46 -> V_16 , V_74 ) ;
}
static int F_59 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
int V_24 ;
V_24 = F_60 ( V_7 -> V_72 , F_32 , 0 , F_20 ( V_10 ) , V_7 ) ;
if ( V_24 ) {
F_17 ( F_10 ( V_7 ) , L_10 ,
F_20 ( V_10 ) ) ;
return V_24 ;
}
V_24 = F_61 ( F_10 ( V_7 ) ) ;
if ( V_24 < 0 ) {
F_62 ( V_7 -> V_72 , V_7 ) ;
return V_24 ;
}
F_63 ( & V_7 -> V_11 . V_12 ) ;
return 0 ;
}
static void F_64 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
F_38 ( V_10 ) ;
F_65 ( & V_7 -> V_11 ) ;
F_66 ( & V_7 -> V_11 . V_99 ) ;
F_62 ( V_7 -> V_72 , V_7 ) ;
F_67 ( F_10 ( V_7 ) ) ;
V_7 -> V_30 = 0 ;
V_7 -> V_32 = V_100 ;
}
static struct V_9 * F_68 ( struct V_101 * V_102 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_105 ;
struct V_6 * V_7 ;
struct V_9 * V_12 ;
unsigned int V_30 ;
if ( V_102 -> V_106 != 1 )
return NULL ;
V_30 = V_102 -> args [ 0 ] ;
if ( V_30 == 0 ) {
F_17 ( V_2 -> V_19 , L_11 ) ;
return NULL ;
}
V_12 = F_69 ( & V_2 -> V_107 ) ;
if ( ! V_12 )
return NULL ;
V_7 = F_7 ( V_12 ) ;
V_7 -> V_30 = V_30 ;
return V_12 ;
}
static int F_70 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_71 ( V_19 ) ;
V_2 -> V_108 = F_3 ( V_2 , V_27 ) ;
return F_72 ( V_19 ) ;
}
static int F_73 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_71 ( V_19 ) ;
int V_24 ;
V_24 = F_74 ( V_19 ) ;
if ( V_24 )
return V_24 ;
F_1 ( V_2 , V_27 , V_2 -> V_108 ) ;
return 0 ;
}
static int F_75 ( struct V_109 * V_110 )
{
const struct V_111 * V_112 ;
struct V_1 * V_2 ;
struct V_113 * V_114 ;
int V_24 , V_115 ;
V_112 = F_76 ( & V_110 -> V_19 ) ;
if ( ! V_112 ) {
F_17 ( & V_110 -> V_19 , L_12 ) ;
return - V_116 ;
}
V_2 = F_77 ( & V_110 -> V_19 , sizeof( * V_2 ) + V_112 -> V_117 *
sizeof( struct V_6 ) , V_118 ) ;
if ( ! V_2 )
return - V_119 ;
V_2 -> V_19 = & V_110 -> V_19 ;
V_2 -> V_117 = V_112 -> V_117 ;
F_78 ( V_110 , V_2 ) ;
V_114 = F_79 ( V_110 , V_120 , 0 ) ;
V_2 -> V_5 = F_80 ( & V_110 -> V_19 , V_114 ) ;
if ( F_81 ( V_2 -> V_5 ) )
return F_82 ( V_2 -> V_5 ) ;
V_24 = F_83 ( & V_110 -> V_19 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_84 ( & V_110 -> V_19 , L_13 ) ;
if ( V_24 )
goto V_121;
F_85 ( & V_110 -> V_19 ) ;
V_24 = F_61 ( & V_110 -> V_19 ) ;
if ( V_24 < 0 )
goto V_122;
V_24 = F_14 ( V_2 ) ;
if ( V_24 )
goto V_123;
F_86 ( & V_2 -> V_107 . V_124 ) ;
for ( V_115 = 0 ; V_115 < V_2 -> V_117 ; V_115 ++ ) {
struct V_6 * V_7 = & V_2 -> V_124 [ V_115 ] ;
V_7 -> V_8 = V_2 -> V_5 + F_87 ( V_115 ) ;
V_7 -> V_72 = F_88 ( V_110 -> V_19 . V_125 , V_115 ) ;
if ( V_7 -> V_72 <= 0 ) {
V_24 = V_7 -> V_72 ? : - V_126 ;
goto V_127;
}
F_89 ( & V_7 -> V_11 , & V_2 -> V_107 ) ;
V_7 -> V_11 . V_128 = F_11 ;
V_7 -> V_2 = V_2 ;
}
F_90 ( V_129 , V_2 -> V_107 . V_130 ) ;
F_90 ( V_131 , V_2 -> V_107 . V_130 ) ;
F_90 ( V_132 , V_2 -> V_107 . V_130 ) ;
V_2 -> V_107 . V_19 = & V_110 -> V_19 ;
V_2 -> V_107 . V_133 =
F_59 ;
V_2 -> V_107 . V_134 =
F_64 ;
V_2 -> V_107 . V_135 = F_36 ;
V_2 -> V_107 . V_136 = F_55 ;
V_2 -> V_107 . V_137 = F_13 ;
V_2 -> V_107 . V_138 = F_42 ;
V_2 -> V_107 . V_139 = F_38 ;
V_2 -> V_107 . V_140 = F_91 ( V_141 ) ;
V_2 -> V_107 . V_142 = F_91 ( V_141 ) ;
V_2 -> V_107 . V_143 = F_91 ( V_37 ) | F_91 ( V_34 ) ;
V_2 -> V_107 . V_144 = V_145 ;
V_24 = F_92 ( & V_2 -> V_107 ) ;
if ( V_24 < 0 ) {
F_17 ( & V_110 -> V_19 , L_14 , V_24 ) ;
goto V_127;
}
V_24 = F_93 ( V_110 -> V_19 . V_125 ,
F_68 , V_2 ) ;
if ( V_24 < 0 ) {
F_17 ( & V_110 -> V_19 , L_15 , V_24 ) ;
goto V_146;
}
F_67 ( & V_110 -> V_19 ) ;
F_94 ( & V_110 -> V_19 , L_16 ,
V_2 -> V_117 ) ;
return 0 ;
V_146:
F_95 ( & V_2 -> V_107 ) ;
V_127:
while ( -- V_115 >= 0 )
F_96 ( V_2 -> V_124 [ V_115 ] . V_72 ) ;
V_123:
F_97 ( & V_110 -> V_19 ) ;
V_122:
F_98 ( & V_110 -> V_19 ) ;
V_121:
F_99 ( & V_110 -> V_19 ) ;
return V_24 ;
}
static int F_100 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_101 ( V_110 ) ;
int V_115 ;
F_95 ( & V_2 -> V_107 ) ;
for ( V_115 = 0 ; V_115 < V_2 -> V_117 ; ++ V_115 )
F_96 ( V_2 -> V_124 [ V_115 ] . V_72 ) ;
F_97 ( & V_110 -> V_19 ) ;
F_98 ( & V_110 -> V_19 ) ;
F_99 ( & V_110 -> V_19 ) ;
return 0 ;
}
static int F_102 ( struct V_18 * V_19 )
{
return F_103 ( V_19 ) == false ;
}
