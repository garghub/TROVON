static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_3 . V_5 , struct V_1 ,
V_6 ) ;
}
static struct V_2 * F_3 ( struct V_7 * V_8 )
{
return F_2 ( V_8 , struct V_2 , V_4 . V_3 ) ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 )
{
return F_2 ( V_11 , struct V_9 , V_11 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_12 ,
unsigned int V_13 )
{
return F_6 ( V_12 -> V_14 + V_13 ) ;
}
static inline void F_7 ( struct V_1 * V_12 ,
unsigned V_13 , T_1 V_15 )
{
F_8 ( V_15 , V_12 -> V_14 + V_13 ) ;
}
static inline void F_9 ( struct V_1 * V_12 ,
unsigned int V_13 , T_1 V_15 , T_1 V_16 )
{
T_1 V_17 ;
V_17 = F_5 ( V_12 , V_13 ) ;
V_17 &= ~ V_16 ;
V_17 |= V_15 ;
F_7 ( V_12 , V_13 , V_17 ) ;
}
static struct V_9 * F_10 ( unsigned int V_18 )
{
return F_11 ( sizeof( struct V_9 ) +
sizeof( struct V_19 ) * V_18 , V_20 ) ;
}
static enum V_21 V_21 ( enum V_22 V_23 )
{
switch ( V_23 ) {
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
return V_29 ;
}
}
static enum V_30 F_12 ( T_2 V_31 )
{
if ( V_31 <= 1 )
return V_32 ;
else if ( V_31 <= 3 )
return V_33 ;
else if ( V_31 <= 15 )
return V_34 ;
else if ( V_31 <= 31 )
return V_35 ;
return V_36 ;
}
static int F_13 ( struct V_7 * V_8 ,
const struct V_37 * V_38 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
enum V_21 V_39 ;
enum V_21 V_40 ;
enum V_30 V_41 ;
enum V_42 V_43 ;
T_1 V_44 ;
switch ( V_38 -> V_45 ) {
case V_46 :
V_43 = V_47 ;
V_41 = F_12 ( V_38 -> V_48 ) ;
V_3 -> V_49 = V_38 -> V_50 ;
break;
case V_51 :
V_43 = V_52 ;
V_41 = F_12 ( V_38 -> V_53 ) ;
V_3 -> V_49 = V_38 -> V_54 ;
break;
default:
return - V_55 ;
}
V_39 = V_21 ( V_38 -> V_56 ) ;
V_40 = V_21 ( V_38 -> V_57 ) ;
switch ( V_41 ) {
case V_33 :
V_3 -> V_58 = 1 ;
break;
case V_34 :
V_3 -> V_58 = 2 ;
break;
case V_35 :
V_3 -> V_58 = 4 ;
break;
case V_36 :
V_3 -> V_58 = 5 ;
break;
default:
V_3 -> V_58 = 0 ;
break;
}
V_44 = V_43 << V_59 ;
V_44 |= V_39 << V_60 ;
V_44 |= V_40 << V_61 ;
V_44 |= V_41 << V_62 ;
V_44 |= V_63 << V_64 ;
V_44 |= V_65 ;
F_7 ( V_12 , F_14 ( V_3 -> V_66 ) , V_44 ) ;
F_7 ( V_12 , F_15 ( V_3 -> V_66 ) , 0 ) ;
F_7 ( V_12 , F_16 ( V_3 -> V_66 ) ,
V_38 -> V_67 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned long V_43 ;
F_18 ( V_68 ) ;
F_19 ( & V_3 -> V_4 . V_69 , V_43 ) ;
F_9 ( V_12 , F_15 ( V_3 -> V_66 ) , 0 ,
V_70 ) ;
V_3 -> V_71 = NULL ;
F_20 ( & V_3 -> V_4 , & V_68 ) ;
F_21 ( & V_3 -> V_4 . V_69 , V_43 ) ;
F_22 ( & V_3 -> V_4 , & V_68 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_3 , enum V_72 V_44 ,
unsigned long V_73 )
{
struct V_37 * V_38 = (struct V_37 * ) V_73 ;
switch ( V_44 ) {
case V_74 :
return F_13 ( V_3 , V_38 ) ;
case V_75 :
return F_17 ( V_3 ) ;
default:
return - V_76 ;
}
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_3 V_54 , V_50 ;
struct V_10 * V_11 ;
struct V_19 * V_77 ;
F_9 ( V_12 , F_15 ( V_3 -> V_66 ) , 0 ,
V_70 ) ;
if ( ! V_3 -> V_71 ) {
V_11 = F_25 ( & V_3 -> V_4 ) ;
if ( ! V_11 )
return 0 ;
V_3 -> V_71 = F_4 ( V_11 ) ;
V_3 -> V_78 = 0 ;
}
if ( V_3 -> V_78 == V_3 -> V_71 -> V_18 )
V_3 -> V_78 = 0 ;
V_77 = & V_3 -> V_71 -> V_77 [ V_3 -> V_78 ] ;
if ( V_3 -> V_71 -> V_45 == V_46 ) {
V_54 = V_77 -> V_79 ;
V_50 = V_3 -> V_49 ;
} else {
V_54 = V_3 -> V_49 ;
V_50 = V_77 -> V_79 ;
}
F_7 ( V_12 , F_26 ( V_3 -> V_66 ) , V_54 ) ;
F_7 ( V_12 , F_27 ( V_3 -> V_66 ) , V_50 ) ;
F_7 ( V_12 , F_28 ( V_3 -> V_66 ) ,
V_77 -> V_80 >> V_3 -> V_58 ) ;
V_3 -> V_78 ++ ;
F_9 ( V_12 , F_15 ( V_3 -> V_66 ) ,
V_81 | V_70 ,
V_82 | V_81 |
V_70 ) ;
F_9 ( V_12 , V_83 ,
V_84 ,
V_85 | V_84 ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_30 ( & V_3 -> V_4 . V_69 ) ;
if ( V_3 -> V_71 ) {
if ( V_3 -> V_71 && V_3 -> V_71 -> V_86 ) {
F_31 ( & V_3 -> V_71 -> V_11 ) ;
} else {
if ( V_3 -> V_78 == V_3 -> V_71 -> V_18 ) {
V_3 -> V_71 = NULL ;
F_32 ( & V_3 -> V_71 -> V_11 ) ;
}
}
}
F_24 ( V_3 ) ;
F_33 ( & V_3 -> V_4 . V_69 ) ;
}
static T_4 F_34 ( int V_87 , void * V_88 )
{
struct V_1 * V_12 = V_88 ;
T_1 V_89 ;
unsigned int V_90 ;
V_89 = F_6 ( V_12 -> V_14 + V_91 ) ;
for ( V_90 = 0 ; V_90 < 6 ; ++ V_90 ) {
if ( V_89 & ( 1 << V_90 ) ) {
F_9 ( V_12 ,
F_15 ( V_90 ) , 0 ,
V_70 |
V_92 ) ;
F_29 ( & V_12 -> V_3 [ V_90 ] ) ;
}
}
return V_93 ;
}
static void F_35 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
unsigned long V_43 ;
F_19 ( & V_3 -> V_4 . V_69 , V_43 ) ;
if ( F_36 ( & V_3 -> V_4 ) && ! V_3 -> V_71 )
F_24 ( V_3 ) ;
F_21 ( & V_3 -> V_4 . V_69 , V_43 ) ;
}
static struct V_94 * F_37 (
struct V_7 * V_8 , struct V_95 * V_96 ,
unsigned int V_97 , enum V_98 V_45 ,
unsigned long V_43 , void * V_99 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_71 ;
struct V_95 * V_77 ;
unsigned int V_90 ;
V_71 = F_10 ( V_97 ) ;
if ( ! V_71 )
return NULL ;
F_38 (sgl, sg, sg_len, i) {
V_71 -> V_77 [ V_90 ] . V_79 = F_39 ( V_77 ) ;
V_71 -> V_77 [ V_90 ] . V_80 = F_40 ( V_77 ) ;
}
V_71 -> V_18 = V_97 ;
V_71 -> V_45 = V_45 ;
V_71 -> V_86 = false ;
return F_41 ( & V_3 -> V_4 , & V_71 -> V_11 , V_43 ) ;
}
static struct V_94 * F_42 (
struct V_7 * V_8 , T_3 V_100 , T_5 V_101 ,
T_5 V_102 , enum V_98 V_45 ,
unsigned long V_43 , void * V_99 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_71 ;
unsigned int V_103 , V_90 ;
if ( V_101 % V_102 )
return NULL ;
V_103 = V_101 / V_102 ;
V_71 = F_10 ( V_103 ) ;
if ( ! V_71 )
return NULL ;
for ( V_90 = 0 ; V_90 < V_103 ; V_90 ++ ) {
V_71 -> V_77 [ V_90 ] . V_79 = V_100 ;
V_71 -> V_77 [ V_90 ] . V_80 = V_102 ;
V_100 += V_102 ;
}
V_71 -> V_18 = V_103 ;
V_71 -> V_45 = V_45 ;
V_71 -> V_86 = true ;
return F_41 ( & V_3 -> V_4 , & V_71 -> V_11 , V_43 ) ;
}
static T_5 F_43 ( struct V_2 * V_3 ,
struct V_9 * V_71 , unsigned int V_78 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned int V_104 , V_105 ;
unsigned int V_90 ;
V_104 = 0 ;
for ( V_90 = V_78 ; V_90 < V_71 -> V_18 ; V_90 ++ )
V_104 += V_71 -> V_77 [ V_90 ] . V_80 ;
if ( V_78 != 0 ) {
V_105 = F_5 ( V_12 ,
F_28 ( V_3 -> V_66 ) ) ;
V_104 += V_105 << V_3 -> V_58 ;
}
return V_104 ;
}
static enum V_106 F_44 ( struct V_7 * V_8 ,
T_6 V_107 , struct V_108 * V_109 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_10 * V_11 ;
enum V_106 V_110 ;
unsigned long V_43 ;
V_110 = F_45 ( V_8 , V_107 , V_109 ) ;
if ( V_110 == V_111 || ! V_109 )
return V_110 ;
F_19 ( & V_3 -> V_4 . V_69 , V_43 ) ;
V_11 = F_46 ( & V_3 -> V_4 , V_107 ) ;
if ( V_107 == V_3 -> V_71 -> V_11 . V_112 . V_107 ) {
V_109 -> V_104 = F_43 ( V_3 , V_3 -> V_71 ,
V_3 -> V_78 ) ;
} else if ( V_11 ) {
V_109 -> V_104 = F_43 ( V_3 ,
F_4 ( V_11 ) , 0 ) ;
} else {
V_109 -> V_104 = 0 ;
}
F_21 ( & V_3 -> V_4 . V_69 , V_43 ) ;
return V_110 ;
}
static int F_47 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_48 ( struct V_7 * V_8 )
{
F_49 ( F_50 ( V_8 ) ) ;
}
static void F_51 ( struct V_10 * V_11 )
{
F_52 ( F_2 ( V_11 , struct V_9 , V_11 ) ) ;
}
static int F_53 ( struct V_113 * V_114 )
{
struct V_2 * V_3 ;
struct V_1 * V_12 ;
struct V_115 * V_116 ;
unsigned int V_90 ;
struct V_117 * V_118 ;
int V_119 ;
int V_87 ;
V_12 = F_54 ( & V_114 -> V_120 , sizeof( * V_12 ) , V_121 ) ;
if ( ! V_12 )
return - V_55 ;
V_116 = & V_12 -> V_6 ;
V_118 = F_55 ( V_114 , V_122 , 0 ) ;
V_12 -> V_14 = F_56 ( & V_114 -> V_120 , V_118 ) ;
if ( F_57 ( V_12 -> V_14 ) )
return F_58 ( V_12 -> V_14 ) ;
V_12 -> V_123 = F_59 ( & V_114 -> V_120 , L_1 ) ;
if ( F_57 ( V_12 -> V_123 ) )
return F_58 ( V_12 -> V_123 ) ;
F_60 ( V_12 -> V_123 ) ;
F_61 ( V_124 , V_116 -> V_125 ) ;
F_61 ( V_126 , V_116 -> V_125 ) ;
V_116 -> V_127 = F_47 ;
V_116 -> V_128 = F_48 ;
V_116 -> V_129 = F_44 ;
V_116 -> V_130 = F_35 ;
V_116 -> V_131 = F_37 ;
V_116 -> V_132 = F_42 ;
V_116 -> V_133 = F_23 ;
V_116 -> V_120 = & V_114 -> V_120 ;
V_116 -> V_134 = V_135 ;
F_62 ( & V_116 -> V_136 ) ;
for ( V_90 = 0 ; V_90 < V_116 -> V_134 ; V_90 ++ ) {
V_3 = & V_12 -> V_3 [ V_90 ] ;
V_3 -> V_66 = V_90 ;
V_3 -> V_4 . V_137 = F_51 ;
F_63 ( & V_3 -> V_4 , V_116 ) ;
}
V_119 = F_64 ( V_116 ) ;
if ( V_119 )
return V_119 ;
V_87 = F_65 ( V_114 , 0 ) ;
V_119 = F_66 ( V_87 , F_34 , 0 , F_67 ( & V_114 -> V_120 ) , V_12 ) ;
if ( V_119 )
goto V_138;
F_68 ( V_114 , V_12 ) ;
return 0 ;
V_138:
F_69 ( V_116 ) ;
return V_119 ;
}
static int F_70 ( struct V_113 * V_114 )
{
struct V_1 * V_12 = F_71 ( V_114 ) ;
int V_87 = F_65 ( V_114 , 0 ) ;
F_72 ( V_87 , V_12 ) ;
F_69 ( & V_12 -> V_6 ) ;
F_73 ( V_12 -> V_123 ) ;
return 0 ;
}
