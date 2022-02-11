static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_9 ) ;
}
static inline struct V_10 * F_4 ( struct V_11 * V_12 )
{
return F_2 ( V_12 , struct V_10 , V_13 . V_14 ) ;
}
static void F_5 ( struct V_15 * V_13 )
{
F_6 ( F_2 ( V_13 , struct V_10 , V_13 ) ) ;
}
static void F_7 ( struct V_5 * V_7 , struct V_10 * V_3 ,
unsigned V_16 )
{
struct V_17 * V_18 = V_3 -> V_18 + V_16 ;
if ( V_3 -> V_19 == V_20 )
F_8 ( V_7 -> V_21 , V_22 ,
V_23 , V_18 -> V_24 , 0 , 0 ) ;
else
F_9 ( V_7 -> V_21 , V_22 ,
V_23 , V_18 -> V_24 , 0 , 0 ) ;
F_10 ( V_7 -> V_21 , V_3 -> V_25 , V_18 -> V_26 , V_18 -> V_27 ,
V_3 -> V_28 , V_7 -> V_29 , V_3 -> V_30 ) ;
F_11 ( V_7 -> V_21 ) ;
}
static void F_12 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_13 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
if ( ! V_13 ) {
V_7 -> V_31 = NULL ;
return;
}
F_14 ( & V_13 -> V_32 ) ;
V_7 -> V_31 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_33 = 0 ;
if ( V_3 -> V_19 == V_20 )
F_9 ( V_7 -> V_21 , V_3 -> V_34 ,
V_35 , V_3 -> V_36 , 0 , V_3 -> V_37 ) ;
else
F_8 ( V_7 -> V_21 , V_3 -> V_34 ,
V_35 , V_3 -> V_36 , 0 , V_3 -> V_37 ) ;
F_7 ( V_7 , V_3 , 0 ) ;
}
static void F_15 ( int V_38 , T_1 V_39 , void * V_40 )
{
struct V_5 * V_7 = V_40 ;
struct V_10 * V_3 ;
unsigned long V_41 ;
F_16 ( & V_7 -> V_8 . V_42 , V_41 ) ;
V_3 = V_7 -> V_31 ;
if ( V_3 ) {
if ( ! V_7 -> V_43 ) {
if ( ++ V_7 -> V_33 < V_3 -> V_44 ) {
F_7 ( V_7 , V_3 , V_7 -> V_33 ) ;
} else {
F_12 ( V_7 ) ;
F_17 ( & V_3 -> V_13 ) ;
}
} else {
F_18 ( & V_3 -> V_13 ) ;
}
}
F_19 ( & V_7 -> V_8 . V_42 , V_41 ) ;
}
static void F_20 ( unsigned long V_40 )
{
struct V_1 * V_3 = (struct V_1 * ) V_40 ;
F_21 ( V_45 ) ;
F_22 ( & V_3 -> V_42 ) ;
F_23 ( & V_3 -> V_46 , & V_45 ) ;
F_24 ( & V_3 -> V_42 ) ;
while ( ! F_25 ( & V_45 ) ) {
struct V_5 * V_7 = F_26 ( & V_45 ,
struct V_5 , V_32 ) ;
F_22 ( & V_7 -> V_8 . V_42 ) ;
F_27 ( & V_7 -> V_32 ) ;
F_12 ( V_7 ) ;
F_24 ( & V_7 -> V_8 . V_42 ) ;
}
}
static int F_28 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_29 ( V_7 -> V_8 . V_9 . V_47 -> V_48 , L_1 , V_7 -> V_29 ) ;
return F_30 ( V_7 -> V_29 , L_2 ,
F_15 , V_7 , & V_7 -> V_21 ) ;
}
static void F_31 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_32 ( & V_7 -> V_8 ) ;
F_33 ( V_7 -> V_21 ) ;
F_29 ( V_7 -> V_8 . V_9 . V_47 -> V_48 , L_3 , V_7 -> V_29 ) ;
}
static T_2 F_34 ( struct V_17 * V_18 )
{
return V_18 -> V_26 * V_18 -> V_27 ;
}
static T_2 F_35 ( struct V_10 * V_3 )
{
unsigned V_49 ;
T_2 V_50 ;
for ( V_50 = V_49 = 0 ; V_49 < V_3 -> V_44 ; V_49 ++ )
V_50 += F_34 ( & V_3 -> V_18 [ V_49 ] ) ;
return V_50 * V_51 [ V_3 -> V_25 ] ;
}
static T_2 F_36 ( struct V_10 * V_3 , T_3 V_24 )
{
unsigned V_49 ;
T_2 V_50 , V_52 = V_51 [ V_3 -> V_25 ] ;
for ( V_50 = V_49 = 0 ; V_49 < V_3 -> V_44 ; V_49 ++ ) {
T_2 V_53 = F_34 ( & V_3 -> V_18 [ V_49 ] ) * V_52 ;
if ( V_50 )
V_50 += V_53 ;
else if ( V_24 >= V_3 -> V_18 [ V_49 ] . V_24 &&
V_24 < V_3 -> V_18 [ V_49 ] . V_24 + V_53 )
V_50 += V_3 -> V_18 [ V_49 ] . V_24 + V_53 - V_24 ;
}
return V_50 ;
}
static enum V_54 F_37 ( struct V_6 * V_9 ,
T_4 V_55 , struct V_56 * V_57 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_54 V_58 ;
unsigned long V_41 ;
V_58 = F_38 ( V_9 , V_55 , V_57 ) ;
if ( V_58 == V_59 || ! V_57 )
return V_58 ;
F_16 ( & V_7 -> V_8 . V_42 , V_41 ) ;
V_13 = F_39 ( & V_7 -> V_8 , V_55 ) ;
if ( V_13 ) {
V_57 -> V_60 = F_35 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_31 && V_7 -> V_31 -> V_13 . V_14 . V_55 == V_55 ) {
struct V_10 * V_3 = V_7 -> V_31 ;
T_3 V_61 ;
if ( V_3 -> V_19 == V_62 )
V_61 = F_40 ( V_7 -> V_21 ) ;
else if ( V_3 -> V_19 == V_20 )
V_61 = F_41 ( V_7 -> V_21 ) ;
else
V_61 = 0 ;
V_57 -> V_60 = F_36 ( V_3 , V_61 ) ;
} else {
V_57 -> V_60 = 0 ;
}
F_19 ( & V_7 -> V_8 . V_42 , V_41 ) ;
return V_58 ;
}
static void F_42 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_41 ;
F_16 ( & V_7 -> V_8 . V_42 , V_41 ) ;
if ( F_43 ( & V_7 -> V_8 ) && ! V_7 -> V_31 ) {
struct V_1 * V_3 = F_1 ( V_9 -> V_47 ) ;
F_44 ( & V_3 -> V_42 ) ;
if ( F_25 ( & V_7 -> V_32 ) )
F_45 ( & V_7 -> V_32 , & V_3 -> V_46 ) ;
F_46 ( & V_3 -> V_42 ) ;
F_47 ( & V_3 -> V_63 ) ;
}
F_19 ( & V_7 -> V_8 . V_42 , V_41 ) ;
}
static struct V_11 * F_48 (
struct V_6 * V_9 , struct V_64 * V_65 , unsigned V_44 ,
enum V_66 V_19 , unsigned long V_67 , void * V_68 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_69 V_70 ;
struct V_64 * V_71 ;
struct V_10 * V_3 ;
T_3 V_36 ;
unsigned V_49 , V_72 = 0 , V_25 , V_26 , V_73 , V_30 ;
T_5 V_74 ;
if ( V_19 == V_20 ) {
V_36 = V_7 -> V_75 . V_76 ;
V_70 = V_7 -> V_75 . V_77 ;
V_74 = V_7 -> V_75 . V_78 ;
V_30 = V_79 ;
} else if ( V_19 == V_62 ) {
V_36 = V_7 -> V_75 . V_80 ;
V_70 = V_7 -> V_75 . V_81 ;
V_74 = V_7 -> V_75 . V_82 ;
V_30 = V_83 ;
} else {
F_49 ( V_9 -> V_47 -> V_48 , L_4 , V_84 ) ;
return NULL ;
}
switch ( V_70 ) {
case V_85 :
V_25 = V_86 ;
break;
case V_87 :
V_25 = V_88 ;
break;
case V_89 :
V_25 = V_90 ;
break;
default:
return NULL ;
}
V_3 = F_50 ( sizeof( * V_3 ) + V_44 * sizeof( V_3 -> V_18 [ 0 ] ) , V_91 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_19 ;
V_3 -> V_36 = V_36 ;
V_3 -> V_25 = V_25 ;
V_3 -> V_28 = V_92 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_34 = V_93 ;
V_26 = V_74 ;
V_73 = V_51 [ V_25 ] * V_26 ;
F_51 (sgl, sgent, sglen, i) {
V_3 -> V_18 [ V_72 ] . V_24 = F_52 ( V_71 ) ;
V_3 -> V_18 [ V_72 ] . V_26 = V_26 ;
V_3 -> V_18 [ V_72 ] . V_27 = F_53 ( V_71 ) / V_73 ;
V_72 ++ ;
}
V_3 -> V_44 = V_72 ;
return F_54 ( & V_7 -> V_8 , & V_3 -> V_13 , V_67 ) ;
}
static struct V_11 * F_55 (
struct V_6 * V_9 , T_3 V_94 , T_2 V_95 ,
T_2 V_96 , enum V_66 V_19 , unsigned long V_41 ,
void * V_68 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_69 V_70 ;
struct V_10 * V_3 ;
T_3 V_36 ;
unsigned V_25 , V_30 ;
T_5 V_74 ;
if ( V_19 == V_20 ) {
V_36 = V_7 -> V_75 . V_76 ;
V_70 = V_7 -> V_75 . V_77 ;
V_74 = V_7 -> V_75 . V_78 ;
V_30 = V_79 ;
} else if ( V_19 == V_62 ) {
V_36 = V_7 -> V_75 . V_80 ;
V_70 = V_7 -> V_75 . V_81 ;
V_74 = V_7 -> V_75 . V_82 ;
V_30 = V_83 ;
} else {
F_49 ( V_9 -> V_47 -> V_48 , L_4 , V_84 ) ;
return NULL ;
}
switch ( V_70 ) {
case V_85 :
V_25 = V_86 ;
break;
case V_87 :
V_25 = V_88 ;
break;
case V_89 :
V_25 = V_90 ;
break;
default:
return NULL ;
}
V_3 = F_50 ( sizeof( * V_3 ) + sizeof( V_3 -> V_18 [ 0 ] ) , V_91 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_19 ;
V_3 -> V_36 = V_36 ;
V_3 -> V_37 = V_74 ;
V_3 -> V_25 = V_25 ;
if ( V_74 )
V_3 -> V_28 = V_97 ;
else
V_3 -> V_28 = V_98 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_34 = V_99 ;
V_3 -> V_18 [ 0 ] . V_24 = V_94 ;
V_3 -> V_18 [ 0 ] . V_26 = V_96 / V_51 [ V_25 ] ;
V_3 -> V_18 [ 0 ] . V_27 = V_95 / V_96 ;
V_3 -> V_44 = 1 ;
if ( ! V_7 -> V_43 ) {
V_7 -> V_43 = true ;
F_56 ( V_7 -> V_21 , V_7 -> V_21 ) ;
if ( V_41 & V_100 )
F_57 ( V_7 -> V_21 , V_101 ) ;
F_58 ( V_7 -> V_21 , V_102 ) ;
}
if ( F_59 () ) {
F_60 ( V_7 -> V_21 , V_103 ) ;
F_61 ( V_7 -> V_21 , V_103 ) ;
}
return F_54 ( & V_7 -> V_8 , & V_3 -> V_13 , V_41 ) ;
}
static int F_62 ( struct V_5 * V_7 , struct V_104 * V_75 )
{
if ( V_75 -> V_77 == V_105 ||
V_75 -> V_81 == V_105 )
return - V_106 ;
memcpy ( & V_7 -> V_75 , V_75 , sizeof( V_7 -> V_75 ) ) ;
return 0 ;
}
static int F_63 ( struct V_5 * V_7 )
{
struct V_1 * V_3 = F_1 ( V_7 -> V_8 . V_9 . V_47 ) ;
unsigned long V_41 ;
F_21 ( V_45 ) ;
F_16 ( & V_7 -> V_8 . V_42 , V_41 ) ;
F_44 ( & V_3 -> V_42 ) ;
F_27 ( & V_7 -> V_32 ) ;
F_46 ( & V_3 -> V_42 ) ;
if ( V_7 -> V_31 ) {
V_7 -> V_31 = NULL ;
if ( ! V_7 -> V_107 )
F_64 ( V_7 -> V_21 ) ;
}
if ( V_7 -> V_43 ) {
V_7 -> V_43 = false ;
V_7 -> V_107 = false ;
F_65 ( V_7 -> V_21 , V_7 -> V_21 ) ;
}
F_66 ( & V_7 -> V_8 , & V_45 ) ;
F_19 ( & V_7 -> V_8 . V_42 , V_41 ) ;
F_67 ( & V_7 -> V_8 , & V_45 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_7 )
{
if ( ! V_7 -> V_43 )
return - V_106 ;
if ( ! V_7 -> V_107 ) {
F_64 ( V_7 -> V_21 ) ;
V_7 -> V_107 = true ;
}
return 0 ;
}
static int F_69 ( struct V_5 * V_7 )
{
if ( ! V_7 -> V_43 )
return - V_106 ;
if ( V_7 -> V_107 ) {
F_11 ( V_7 -> V_21 ) ;
V_7 -> V_107 = false ;
}
return 0 ;
}
static int F_70 ( struct V_6 * V_9 , enum V_108 V_109 ,
unsigned long V_110 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_58 ;
switch ( V_109 ) {
case V_111 :
V_58 = F_62 ( V_7 , (struct V_104 * ) V_110 ) ;
break;
case V_112 :
V_58 = F_63 ( V_7 ) ;
break;
case V_113 :
V_58 = F_68 ( V_7 ) ;
break;
case V_114 :
V_58 = F_69 ( V_7 ) ;
break;
default:
V_58 = - V_115 ;
break;
}
return V_58 ;
}
static int F_71 ( struct V_1 * V_116 , int V_29 )
{
struct V_5 * V_7 ;
V_7 = F_50 ( sizeof( * V_7 ) , V_117 ) ;
if ( ! V_7 )
return - V_118 ;
V_7 -> V_29 = V_29 ;
V_7 -> V_8 . V_119 = F_5 ;
F_72 ( & V_7 -> V_8 , & V_116 -> V_4 ) ;
F_73 ( & V_7 -> V_32 ) ;
V_116 -> V_4 . V_120 ++ ;
return 0 ;
}
static void F_74 ( struct V_1 * V_116 )
{
F_75 ( & V_116 -> V_63 ) ;
while ( ! F_25 ( & V_116 -> V_4 . V_121 ) ) {
struct V_5 * V_7 = F_26 ( & V_116 -> V_4 . V_121 ,
struct V_5 , V_8 . V_9 . V_122 ) ;
F_14 ( & V_7 -> V_8 . V_9 . V_122 ) ;
F_75 ( & V_7 -> V_8 . V_63 ) ;
F_6 ( V_7 ) ;
}
F_6 ( V_116 ) ;
}
static int F_76 ( struct V_123 * V_124 )
{
struct V_1 * V_116 ;
int V_125 , V_49 ;
V_116 = F_50 ( sizeof( * V_116 ) , V_117 ) ;
if ( ! V_116 )
return - V_118 ;
F_77 ( V_126 , V_116 -> V_4 . V_127 ) ;
F_77 ( V_128 , V_116 -> V_4 . V_127 ) ;
V_116 -> V_4 . V_129 = F_28 ;
V_116 -> V_4 . V_130 = F_31 ;
V_116 -> V_4 . V_131 = F_37 ;
V_116 -> V_4 . V_132 = F_42 ;
V_116 -> V_4 . V_133 = F_48 ;
V_116 -> V_4 . V_134 = F_55 ;
V_116 -> V_4 . V_135 = F_70 ;
V_116 -> V_4 . V_48 = & V_124 -> V_48 ;
F_73 ( & V_116 -> V_4 . V_121 ) ;
F_73 ( & V_116 -> V_46 ) ;
F_78 ( & V_116 -> V_42 ) ;
F_79 ( & V_116 -> V_63 , F_20 , ( unsigned long ) V_116 ) ;
for ( V_49 = 0 ; V_49 < 127 ; V_49 ++ ) {
V_125 = F_71 ( V_116 , V_49 ) ;
if ( V_125 ) {
F_74 ( V_116 ) ;
return V_125 ;
}
}
V_125 = F_80 ( & V_116 -> V_4 ) ;
if ( V_125 ) {
F_81 ( L_5 ,
V_125 ) ;
F_74 ( V_116 ) ;
} else {
F_82 ( V_124 , V_116 ) ;
}
F_29 ( & V_124 -> V_48 , L_6 ) ;
return V_125 ;
}
static int F_83 ( struct V_123 * V_124 )
{
struct V_1 * V_116 = F_84 ( V_124 ) ;
F_85 ( & V_116 -> V_4 ) ;
F_74 ( V_116 ) ;
return 0 ;
}
bool F_86 ( struct V_6 * V_9 , void * V_136 )
{
if ( V_9 -> V_47 -> V_48 -> V_137 == & V_138 . V_137 ) {
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_139 = * ( unsigned * ) V_136 ;
return V_139 == V_7 -> V_29 ;
}
return false ;
}
static int F_87 ( void )
{
int V_125 = F_88 ( & V_138 ) ;
if ( V_125 == 0 ) {
V_124 = F_89 ( & V_140 ) ;
if ( F_90 ( V_124 ) ) {
F_91 ( & V_138 ) ;
V_125 = F_92 ( V_124 ) ;
}
}
return V_125 ;
}
static void T_6 F_93 ( void )
{
F_94 ( V_124 ) ;
F_91 ( & V_138 ) ;
}
