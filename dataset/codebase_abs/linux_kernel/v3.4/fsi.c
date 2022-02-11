static void F_1 ( T_1 T_2 * V_1 , T_1 V_2 )
{
V_2 &= 0x00ffffff ;
F_2 ( V_2 , V_1 ) ;
}
static T_1 F_3 ( T_1 T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( T_1 T_2 * V_1 , T_1 V_3 , T_1 V_2 )
{
T_1 V_4 = F_3 ( V_1 ) ;
V_4 &= ~ V_3 ;
V_4 |= V_2 & V_3 ;
F_1 ( V_1 , V_4 ) ;
}
static T_1 F_6 ( struct V_5 * V_6 , T_1 V_1 )
{
T_1 V_7 ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = F_3 ( V_6 -> V_10 + V_1 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static void F_9 ( struct V_5 * V_6 ,
T_1 V_1 , T_1 V_3 , T_1 V_2 )
{
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
F_5 ( V_6 -> V_10 + V_1 , V_3 , V_2 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static struct V_5 * F_10 ( struct V_11 * V_12 )
{
return V_12 -> V_6 ;
}
static int F_11 ( struct V_11 * V_12 )
{
return V_12 -> V_13 ;
}
static int F_12 ( struct V_11 * V_12 )
{
return V_12 -> V_6 -> V_10 == V_12 -> V_10 ;
}
static int F_13 ( struct V_11 * V_12 )
{
return V_12 -> V_14 ;
}
static int F_14 ( struct V_15 * V_16 )
{
return V_16 -> V_17 == V_18 ;
}
static struct V_19 * F_15 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_16 -> V_22 ;
return V_21 -> V_23 ;
}
static struct V_11 * F_16 ( struct V_19 * V_24 )
{
struct V_5 * V_6 = F_17 ( V_24 ) ;
if ( V_24 -> V_25 == 0 )
return & V_6 -> V_26 ;
else
return & V_6 -> V_27 ;
}
static struct V_11 * F_18 ( struct V_15 * V_16 )
{
return F_16 ( F_15 ( V_16 ) ) ;
}
static T_3 F_19 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_28 )
return NULL ;
return V_12 -> V_28 -> V_29 ;
}
static T_1 F_20 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_28 )
return 0 ;
return V_12 -> V_28 -> V_8 ;
}
static T_1 F_21 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
int V_32 = F_22 ( V_12 , V_31 ) ;
int V_33 = F_12 ( V_12 ) ;
T_1 V_34 ;
if ( V_33 )
V_34 = V_32 ? V_35 : V_36 ;
else
V_34 = V_32 ? V_37 : V_38 ;
return V_34 ;
}
static int F_23 ( struct V_11 * V_12 , int V_39 )
{
return V_39 * V_12 -> V_40 ;
}
static int F_24 ( struct V_11 * V_12 , int V_41 )
{
return V_41 / V_12 -> V_40 ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_30 * V_31 )
{
int V_32 = F_22 ( V_12 , V_31 ) ;
T_1 V_42 ;
int V_39 ;
V_42 = V_32 ?
F_26 ( V_12 , V_43 ) :
F_26 ( V_12 , V_44 ) ;
V_39 = 0x1ff & ( V_42 >> 8 ) ;
return F_23 ( V_12 , V_39 ) ;
}
static void F_27 ( struct V_11 * V_12 )
{
T_1 V_45 = F_26 ( V_12 , V_43 ) ;
T_1 V_46 = F_26 ( V_12 , V_44 ) ;
if ( V_45 & V_47 )
V_12 -> V_48 . V_49 ++ ;
if ( V_45 & V_50 )
V_12 -> V_48 . V_51 ++ ;
if ( V_46 & V_47 )
V_12 -> V_52 . V_49 ++ ;
if ( V_46 & V_50 )
V_12 -> V_52 . V_51 ++ ;
F_28 ( V_12 , V_43 , 0 ) ;
F_28 ( V_12 , V_44 , 0 ) ;
}
static inline int F_22 ( struct V_11 * V_12 ,
struct V_30 * V_31 )
{
return & V_12 -> V_48 == V_31 ;
}
static inline struct V_30 * F_29 ( struct V_11 * V_12 ,
struct V_15 * V_16 )
{
return F_14 ( V_16 ) ? & V_12 -> V_48 : & V_12 -> V_52 ;
}
static int F_30 ( struct V_11 * V_12 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned long V_8 ;
int V_7 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = ! ! ( V_31 -> V_16 && V_31 -> V_16 -> V_53 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static struct V_11 * F_31 ( struct V_30 * V_31 )
{
return V_31 -> V_54 ;
}
static void F_32 ( struct V_11 * V_12 ,
struct V_30 * V_31 ,
struct V_15 * V_16 )
{
struct V_55 * V_53 = V_16 -> V_53 ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_31 -> V_16 = V_16 ;
V_31 -> V_56 = F_23 ( V_12 , V_53 -> V_57 ) ;
V_31 -> V_58 = 0 ;
V_31 -> V_59 = F_23 ( V_12 , V_53 -> V_60 ) ;
V_31 -> V_61 = 0 ;
V_31 -> V_62 = F_33 ( V_53 , 1 ) ;
V_31 -> V_49 = - 1 ;
V_31 -> V_51 = - 1 ;
F_34 ( V_31 , V_63 , V_12 , V_31 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static void F_35 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
struct V_19 * V_24 = F_15 ( V_31 -> V_16 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
if ( V_31 -> V_49 > 0 )
F_36 ( V_24 -> V_64 , L_1 , V_31 -> V_49 ) ;
if ( V_31 -> V_51 > 0 )
F_36 ( V_24 -> V_64 , L_2 , V_31 -> V_51 ) ;
F_34 ( V_31 , V_65 , V_12 , V_31 ) ;
V_31 -> V_16 = NULL ;
V_31 -> V_56 = 0 ;
V_31 -> V_58 = 0 ;
V_31 -> V_59 = 0 ;
V_31 -> V_61 = 0 ;
V_31 -> V_62 = 0 ;
V_31 -> V_49 = 0 ;
V_31 -> V_51 = 0 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static int F_37 ( struct V_30 * V_31 )
{
struct V_11 * V_12 = F_31 ( V_31 ) ;
if ( ! V_12 )
return - V_66 ;
return F_34 ( V_31 , V_67 , V_12 , V_31 ) ;
}
static int F_38 ( struct V_11 * V_12 )
{
struct V_30 * V_31 ;
int V_68 , V_69 ;
V_31 = & V_12 -> V_48 ;
V_68 = F_34 ( V_31 , V_70 , V_12 , V_31 ) ;
V_31 = & V_12 -> V_52 ;
V_69 = F_34 ( V_31 , V_70 , V_12 , V_31 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_69 < 0 )
return V_69 ;
return 0 ;
}
static int F_39 ( struct V_11 * V_12 )
{
struct V_30 * V_31 ;
int V_68 , V_69 ;
V_31 = & V_12 -> V_48 ;
V_68 = F_34 ( V_31 , remove , V_12 , V_31 ) ;
V_31 = & V_12 -> V_52 ;
V_69 = F_34 ( V_31 , remove , V_12 , V_31 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_69 < 0 )
return V_69 ;
return 0 ;
}
static void F_40 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
T_1 V_2 = F_41 ( 1 , F_21 ( V_12 , V_31 ) ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
F_42 ( V_6 , V_71 , V_2 , V_2 ) ;
F_42 ( V_6 , V_72 , V_2 , V_2 ) ;
}
static void F_43 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
T_1 V_2 = F_41 ( 1 , F_21 ( V_12 , V_31 ) ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
F_42 ( V_6 , V_71 , V_2 , 0 ) ;
F_42 ( V_6 , V_72 , V_2 , 0 ) ;
}
static T_1 F_44 ( struct V_5 * V_6 )
{
return F_45 ( V_6 , V_73 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
T_1 V_2 = 0 ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
V_2 |= F_41 ( 1 , F_21 ( V_12 , & V_12 -> V_48 ) ) ;
V_2 |= F_41 ( 1 , F_21 ( V_12 , & V_12 -> V_52 ) ) ;
F_42 ( V_6 , V_73 , V_2 , 0 ) ;
}
static void F_47 ( struct V_11 * V_12 , int V_74 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_3 , V_4 ;
if ( V_6 -> V_75 -> V_76 < 2 ) {
F_48 ( L_3 , V_77 ) ;
return;
}
V_3 = V_78 | V_79 ;
V_4 = V_74 ? V_3 : 0 ;
F_12 ( V_12 ) ?
F_42 ( V_6 , V_80 , V_3 , V_4 ) :
F_42 ( V_6 , V_81 , V_3 , V_4 ) ;
}
static int F_49 ( struct V_82 * V_64 , struct V_11 * V_12 ,
long V_83 , int V_74 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_3 V_29 = F_19 ( V_12 ) ;
int V_84 = V_6 -> V_75 -> V_76 ;
int V_7 ;
if ( ! V_29 )
return 0 ;
V_7 = V_29 ( V_64 , V_83 , V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_74 )
return 0 ;
if ( V_7 > 0 ) {
T_1 V_2 = 0 ;
switch ( V_7 & V_85 ) {
default:
case V_86 :
V_2 |= ( 0x0 << 12 ) ;
break;
case V_87 :
V_2 |= ( 0x1 << 12 ) ;
break;
case V_88 :
V_2 |= ( 0x2 << 12 ) ;
break;
case V_89 :
V_2 |= ( 0x3 << 12 ) ;
break;
case V_90 :
if ( V_84 < 2 )
F_36 ( V_64 , L_4 ) ;
else
V_2 |= ( 0x4 << 12 ) ;
break;
}
switch ( V_7 & V_91 ) {
default:
case V_92 :
V_2 |= ( 0x0 << 8 ) ;
break;
case V_93 :
V_2 |= ( 0x1 << 8 ) ;
break;
case V_94 :
V_2 |= ( 0x2 << 8 ) ;
break;
case V_95 :
V_2 |= ( 0x3 << 8 ) ;
break;
case V_96 :
V_2 |= ( 0x4 << 8 ) ;
break;
case V_97 :
if ( V_84 < 2 )
F_36 ( V_64 , L_4 ) ;
else
V_2 |= ( 0x7 << 8 ) ;
break;
}
F_50 ( V_12 , V_98 , ( V_99 | V_100 ) , V_2 ) ;
F_51 ( 10 ) ;
V_7 = 0 ;
}
return V_7 ;
}
static void F_52 ( struct V_11 * V_12 , T_4 * V_101 , int V_41 )
{
T_5 * V_102 = ( T_5 * ) V_101 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_41 ; V_103 ++ )
F_28 ( V_12 , V_104 , ( ( T_1 ) * ( V_102 + V_103 ) << 8 ) ) ;
}
static void F_53 ( struct V_11 * V_12 , T_4 * V_101 , int V_41 )
{
T_5 * V_102 = ( T_5 * ) V_101 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_41 ; V_103 ++ )
* ( V_102 + V_103 ) = ( T_5 ) ( F_26 ( V_12 , V_105 ) >> 8 ) ;
}
static void F_54 ( struct V_11 * V_12 , T_4 * V_101 , int V_41 )
{
T_1 * V_102 = ( T_1 * ) V_101 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_41 ; V_103 ++ )
F_28 ( V_12 , V_104 , * ( V_102 + V_103 ) ) ;
}
static void F_55 ( struct V_11 * V_12 , T_4 * V_101 , int V_41 )
{
T_1 * V_102 = ( T_1 * ) V_101 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_41 ; V_103 ++ )
* ( V_102 + V_103 ) = F_26 ( V_12 , V_105 ) ;
}
static T_4 * F_56 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
struct V_55 * V_53 = V_31 -> V_16 -> V_53 ;
return V_53 -> V_106 +
F_33 ( V_53 , V_31 -> V_58 ) ;
}
static int F_57 ( struct V_11 * V_12 , struct V_30 * V_31 ,
void (* F_58)( struct V_11 * V_12 , T_4 * V_102 , int V_41 ) ,
void (* F_59)( struct V_11 * V_12 , T_4 * V_102 , int V_41 ) ,
int V_41 )
{
struct V_55 * V_53 ;
struct V_15 * V_16 ;
T_4 * V_102 ;
int V_107 ;
if ( ! F_30 ( V_12 , V_31 ) )
return - V_108 ;
V_107 = 0 ;
V_16 = V_31 -> V_16 ;
V_53 = V_16 -> V_53 ;
if ( V_31 -> V_58 >=
V_31 -> V_59 * ( V_31 -> V_61 + 1 ) ) {
V_107 = 1 ;
V_31 -> V_61 = ( V_31 -> V_61 + 1 ) % V_53 -> V_109 ;
if ( 0 == V_31 -> V_61 )
V_31 -> V_58 = 0 ;
}
V_102 = F_56 ( V_12 , V_31 ) ;
switch ( V_31 -> V_62 ) {
case 2 :
F_58 ( V_12 , V_102 , V_41 ) ;
break;
case 4 :
F_59 ( V_12 , V_102 , V_41 ) ;
break;
default:
return - V_108 ;
}
V_31 -> V_58 += V_41 ;
if ( V_107 )
F_60 ( V_16 ) ;
return 0 ;
}
static int F_61 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
int V_110 ;
int V_111 ;
int V_41 ;
V_110 = F_25 ( V_12 , V_31 ) ;
V_111 = V_31 -> V_56 - V_31 -> V_58 ;
V_41 = F_62 ( V_110 , V_111 ) ;
return F_57 ( V_12 , V_31 ,
F_53 ,
F_55 ,
V_41 ) ;
}
static int F_63 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
int V_110 ;
int V_111 ;
int V_41 ;
V_110 = V_31 -> V_56 - V_31 -> V_58 ;
V_111 = V_31 -> V_112 -
F_25 ( V_12 , V_31 ) ;
V_41 = F_62 ( V_110 , V_111 ) ;
return F_57 ( V_12 , V_31 ,
F_52 ,
F_54 ,
V_41 ) ;
}
static void F_64 ( struct V_11 * V_12 , struct V_30 * V_31 ,
int V_74 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_113 = F_12 ( V_12 ) ? V_114 : V_115 ;
if ( V_74 )
F_40 ( V_12 , V_31 ) ;
else
F_43 ( V_12 , V_31 ) ;
if ( F_11 ( V_12 ) )
F_65 ( V_6 , V_116 , V_113 , ( V_74 ) ? V_113 : 0 ) ;
}
static T_6 F_66 ( int V_117 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
T_1 V_73 = F_44 ( V_6 ) ;
F_65 ( V_6 , V_118 , V_119 , 0 ) ;
F_65 ( V_6 , V_118 , V_119 , V_119 ) ;
if ( V_73 & F_41 ( 1 , V_35 ) )
F_37 ( & V_6 -> V_26 . V_48 ) ;
if ( V_73 & F_41 ( 1 , V_37 ) )
F_37 ( & V_6 -> V_27 . V_48 ) ;
if ( V_73 & F_41 ( 1 , V_36 ) )
F_37 ( & V_6 -> V_26 . V_52 ) ;
if ( V_73 & F_41 ( 1 , V_38 ) )
F_37 ( & V_6 -> V_27 . V_52 ) ;
F_27 ( & V_6 -> V_26 ) ;
F_27 ( & V_6 -> V_27 ) ;
F_46 ( & V_6 -> V_26 ) ;
F_46 ( & V_6 -> V_27 ) ;
return V_120 ;
}
static int F_67 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
struct V_55 * V_53 = V_31 -> V_16 -> V_53 ;
struct V_19 * V_24 = F_15 ( V_31 -> V_16 ) ;
enum V_121 V_122 = F_22 ( V_12 , V_31 ) ?
V_123 : V_124 ;
V_31 -> V_125 = F_68 ( V_24 -> V_64 , V_53 -> V_106 ,
F_69 ( V_31 -> V_16 ) , V_122 ) ;
return 0 ;
}
static int F_70 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
struct V_19 * V_24 = F_15 ( V_31 -> V_16 ) ;
enum V_121 V_122 = F_22 ( V_12 , V_31 ) ?
V_123 : V_124 ;
F_71 ( V_24 -> V_64 , V_31 -> V_125 ,
F_69 ( V_31 -> V_16 ) , V_122 ) ;
return 0 ;
}
static void F_72 ( void * V_2 )
{
struct V_30 * V_31 = (struct V_30 * ) V_2 ;
struct V_11 * V_12 = F_31 ( V_31 ) ;
struct V_55 * V_53 = V_31 -> V_16 -> V_53 ;
struct V_19 * V_24 = F_15 ( V_31 -> V_16 ) ;
enum V_121 V_122 = F_22 ( V_12 , V_31 ) ?
V_123 : V_124 ;
F_73 ( V_24 -> V_64 , V_31 -> V_125 ,
F_33 ( V_53 , V_31 -> V_59 ) , V_122 ) ;
V_31 -> V_58 += V_31 -> V_59 ;
V_31 -> V_61 ++ ;
if ( V_31 -> V_61 >= V_53 -> V_109 ) {
V_31 -> V_61 = 0 ;
V_31 -> V_58 = 0 ;
}
F_27 ( V_12 ) ;
F_37 ( V_31 ) ;
F_60 ( V_31 -> V_16 ) ;
}
static T_7 F_74 ( struct V_30 * V_31 )
{
struct V_55 * V_53 = V_31 -> V_16 -> V_53 ;
return V_31 -> V_125 + F_33 ( V_53 , V_31 -> V_58 ) ;
}
static void F_75 ( unsigned long V_2 )
{
struct V_30 * V_31 = (struct V_30 * ) V_2 ;
struct V_11 * V_12 = F_31 ( V_31 ) ;
struct V_126 * V_127 ;
struct V_19 * V_24 ;
struct V_128 * V_129 ;
struct V_130 V_131 ;
struct V_55 * V_53 ;
enum V_121 V_122 ;
T_8 V_132 ;
int V_32 = F_22 ( V_12 , V_31 ) ;
int V_133 ;
T_7 V_102 ;
if ( ! F_30 ( V_12 , V_31 ) )
return;
V_24 = F_15 ( V_31 -> V_16 ) ;
V_127 = V_31 -> V_127 ;
V_53 = V_31 -> V_16 -> V_53 ;
V_122 = V_32 ? V_123 : V_124 ;
V_133 = F_33 ( V_53 , V_31 -> V_59 ) ;
V_102 = F_74 ( V_31 ) ;
F_76 ( V_24 -> V_64 , V_31 -> V_125 , V_133 , V_122 ) ;
F_77 ( & V_131 , 1 ) ;
F_78 ( & V_131 , F_79 ( F_80 ( V_102 ) ) ,
V_133 , F_81 ( V_102 ) ) ;
F_82 ( & V_131 ) = V_102 ;
F_83 ( & V_131 ) = V_133 ;
V_129 = F_84 ( V_127 , & V_131 , 1 , V_122 ,
V_134 | V_135 ) ;
if ( ! V_129 ) {
F_36 ( V_24 -> V_64 , L_5 ) ;
return;
}
V_129 -> V_136 = F_72 ;
V_129 -> V_137 = V_31 ;
V_132 = V_129 -> V_138 ( V_129 ) ;
if ( V_132 < 0 ) {
F_36 ( V_24 -> V_64 , L_6 ) ;
return;
}
F_85 ( V_127 ) ;
if ( ! V_32 ) {
if ( V_47 & F_26 ( V_12 , V_44 ) ) {
F_50 ( V_12 , V_139 , V_140 , V_140 ) ;
F_28 ( V_12 , V_44 , 0 ) ;
}
}
}
static bool F_86 ( struct V_126 * V_127 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
V_127 -> V_144 = V_143 ;
return true ;
}
static int F_87 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
F_88 ( & V_31 -> V_145 ) ;
return 0 ;
}
static void F_89 ( struct V_11 * V_12 , struct V_30 * V_31 ,
int V_146 )
{
T_1 V_147 ;
T_1 V_125 ;
switch ( V_31 -> V_62 * V_146 ) {
case 2 :
V_147 = V_148 ;
V_125 = V_149 | V_150 ;
break;
case 4 :
V_147 = V_151 ;
V_125 = V_152 | V_150 ;
break;
default:
V_147 = 0 ;
V_125 = 0 ;
}
F_50 ( V_12 , V_153 , V_154 , V_147 ) ;
F_28 ( V_12 , V_155 , V_125 ) ;
}
static int F_90 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
T_9 V_3 ;
F_91 ( V_3 ) ;
F_92 ( V_156 , V_3 ) ;
V_31 -> V_127 = F_93 ( V_3 , F_86 , & V_31 -> V_143 ) ;
if ( ! V_31 -> V_127 )
return - V_66 ;
F_94 ( & V_31 -> V_145 , F_75 , ( unsigned long ) V_31 ) ;
return 0 ;
}
static int F_95 ( struct V_11 * V_12 , struct V_30 * V_31 )
{
F_96 ( & V_31 -> V_145 ) ;
F_97 ( V_12 , V_31 ) ;
if ( V_31 -> V_127 )
F_98 ( V_31 -> V_127 ) ;
V_31 -> V_127 = NULL ;
return 0 ;
}
static void F_99 ( struct V_11 * V_12 ,
struct V_30 * V_31 ,
struct V_82 * V_64 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_32 = F_22 ( V_12 , V_31 ) ;
T_1 V_34 , V_103 ;
int V_157 ;
V_34 = F_100 ( V_6 , V_158 ) ;
V_34 >>= F_21 ( V_12 , V_31 ) ;
V_34 &= V_159 ;
V_157 = 256 << V_34 ;
F_101 ( V_64 , L_7 , V_157 ) ;
for ( V_103 = 1 ; V_103 < V_12 -> V_40 ; V_103 <<= 1 )
V_157 >>= 1 ;
F_101 ( V_64 , L_8 ,
V_12 -> V_40 , V_157 ) ;
V_31 -> V_112 = F_23 ( V_12 , V_157 ) ;
if ( V_32 ) {
F_28 ( V_12 , V_160 , V_161 ) ;
F_50 ( V_12 , V_160 , V_140 , V_140 ) ;
} else {
F_28 ( V_12 , V_139 , V_161 ) ;
F_50 ( V_12 , V_139 , V_140 , V_140 ) ;
}
}
static int F_102 ( struct V_11 * V_12 ,
struct V_30 * V_31 ,
struct V_82 * V_64 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
int V_84 = V_6 -> V_75 -> V_76 ;
T_1 V_8 = F_20 ( V_12 ) ;
T_1 V_2 = 0 ;
if ( F_11 ( V_12 ) )
V_2 = V_162 | V_163 ;
F_50 ( V_12 , V_98 , ( V_162 | V_163 ) , V_2 ) ;
V_2 = 0 ;
if ( V_164 & V_8 )
V_2 |= 1 << 12 ;
if ( V_165 & V_8 )
V_2 |= 1 << 8 ;
if ( V_166 & V_8 )
V_2 |= 1 << 4 ;
if ( V_167 & V_8 )
V_2 |= 1 << 0 ;
F_28 ( V_12 , V_168 , V_2 ) ;
F_28 ( V_12 , V_153 , V_12 -> V_169 ) ;
F_28 ( V_12 , V_170 , V_12 -> V_171 ) ;
if ( F_13 ( V_12 ) ) {
F_47 ( V_12 , 1 ) ;
F_50 ( V_12 , V_172 , V_173 , V_173 ) ;
}
if ( V_84 >= 2 ) {
F_28 ( V_12 , V_155 , ( 1 << 4 ) ) ;
F_28 ( V_12 , V_174 , ( 1 << 4 ) ) ;
}
F_43 ( V_12 , V_31 ) ;
F_46 ( V_12 ) ;
F_99 ( V_12 , V_31 , V_64 ) ;
return 0 ;
}
static void F_103 ( struct V_11 * V_12 ,
struct V_82 * V_64 )
{
if ( F_11 ( V_12 ) )
F_49 ( V_64 , V_12 , V_12 -> V_83 , 0 ) ;
}
static int F_104 ( struct V_15 * V_16 ,
struct V_19 * V_24 )
{
struct V_11 * V_12 = F_18 ( V_16 ) ;
return F_102 ( V_12 , F_29 ( V_12 , V_16 ) , V_24 -> V_64 ) ;
}
static void F_105 ( struct V_15 * V_16 ,
struct V_19 * V_24 )
{
struct V_11 * V_12 = F_18 ( V_16 ) ;
F_103 ( V_12 , V_24 -> V_64 ) ;
V_12 -> V_83 = 0 ;
}
static int F_106 ( struct V_15 * V_16 , int V_175 ,
struct V_19 * V_24 )
{
struct V_11 * V_12 = F_18 ( V_16 ) ;
struct V_30 * V_31 = F_29 ( V_12 , V_16 ) ;
int V_7 = 0 ;
switch ( V_175 ) {
case V_176 :
F_32 ( V_12 , V_31 , V_16 ) ;
V_7 = F_37 ( V_31 ) ;
if ( 0 == V_7 )
F_107 ( V_12 , V_31 ) ;
break;
case V_177 :
F_97 ( V_12 , V_31 ) ;
F_35 ( V_12 , V_31 ) ;
break;
}
return V_7 ;
}
static int F_108 ( struct V_11 * V_12 , unsigned int V_178 )
{
T_1 V_2 = 0 ;
switch ( V_178 & V_179 ) {
case V_180 :
V_2 = V_181 ;
V_12 -> V_40 = 2 ;
break;
case V_182 :
V_2 = V_183 ;
V_12 -> V_40 = 2 ;
break;
default:
return - V_108 ;
}
V_12 -> V_169 = V_2 ;
V_12 -> V_171 = V_2 ;
return 0 ;
}
static int F_109 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_2 = 0 ;
if ( V_6 -> V_75 -> V_76 < 2 )
return - V_108 ;
V_2 = V_148 | V_184 | V_183 ;
V_12 -> V_40 = 2 ;
V_12 -> V_14 = 1 ;
V_12 -> V_169 = V_2 ;
V_12 -> V_171 = V_2 ;
return 0 ;
}
static int F_110 ( struct V_19 * V_24 , unsigned int V_178 )
{
struct V_11 * V_12 = F_16 ( V_24 ) ;
T_3 V_29 = F_19 ( V_12 ) ;
T_1 V_8 = F_20 ( V_12 ) ;
int V_7 ;
switch ( V_178 & V_185 ) {
case V_186 :
V_12 -> V_13 = 1 ;
break;
case V_187 :
break;
default:
return - V_108 ;
}
if ( F_11 ( V_12 ) && ! V_29 ) {
F_36 ( V_24 -> V_64 , L_9 ) ;
return - V_108 ;
}
switch ( V_8 & V_188 ) {
case V_189 :
V_7 = F_108 ( V_12 , V_178 & V_179 ) ;
break;
case V_190 :
V_7 = F_109 ( V_12 ) ;
break;
default:
V_7 = - V_108 ;
}
return V_7 ;
}
static int F_111 ( struct V_15 * V_16 ,
struct V_191 * V_192 ,
struct V_19 * V_24 )
{
struct V_11 * V_12 = F_18 ( V_16 ) ;
long V_83 = F_112 ( V_192 ) ;
int V_7 ;
if ( ! F_11 ( V_12 ) )
return 0 ;
V_7 = F_49 ( V_24 -> V_64 , V_12 , V_83 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_12 -> V_83 = V_83 ;
return V_7 ;
}
static int F_113 ( struct V_15 * V_16 )
{
struct V_55 * V_53 = V_16 -> V_53 ;
int V_7 = 0 ;
F_114 ( V_16 , & V_193 ) ;
V_7 = F_115 ( V_53 ,
V_194 ) ;
return V_7 ;
}
static int F_116 ( struct V_15 * V_16 ,
struct V_191 * V_195 )
{
return F_117 ( V_16 ,
F_118 ( V_195 ) ) ;
}
static int F_119 ( struct V_15 * V_16 )
{
return F_120 ( V_16 ) ;
}
static T_10 F_121 ( struct V_15 * V_16 )
{
struct V_11 * V_12 = F_18 ( V_16 ) ;
struct V_30 * V_31 = F_29 ( V_12 , V_16 ) ;
return F_24 ( V_12 , V_31 -> V_58 ) ;
}
static void F_122 ( struct V_196 * V_197 )
{
F_123 ( V_197 ) ;
}
static int F_124 ( struct V_20 * V_21 )
{
struct V_196 * V_197 = V_21 -> V_197 ;
return F_125 (
V_197 ,
V_198 ,
F_126 ( V_199 ) ,
V_200 , V_201 ) ;
}
static void F_127 ( struct V_11 * V_12 )
{
V_12 -> V_48 . V_202 = & V_203 ;
V_12 -> V_48 . V_54 = V_12 ;
V_12 -> V_52 . V_202 = & V_204 ;
V_12 -> V_52 . V_54 = V_12 ;
if ( V_12 -> V_28 -> V_205 ) {
V_12 -> V_48 . V_143 . V_206 = V_12 -> V_28 -> V_205 ;
V_12 -> V_48 . V_202 = & V_207 ;
}
}
static int F_128 ( struct V_208 * V_209 )
{
struct V_5 * V_6 ;
const struct V_210 * V_211 ;
struct V_212 * V_28 = V_209 -> V_64 . V_213 ;
struct V_214 * V_215 ;
unsigned int V_117 ;
int V_7 ;
V_211 = V_209 -> V_211 ;
if ( ! V_211 ) {
F_36 ( & V_209 -> V_64 , L_10 ) ;
return - V_216 ;
}
V_215 = F_129 ( V_209 , V_217 , 0 ) ;
V_117 = F_130 ( V_209 , 0 ) ;
if ( ! V_215 || ( int ) V_117 <= 0 ) {
F_36 ( & V_209 -> V_64 , L_11 ) ;
V_7 = - V_216 ;
goto exit;
}
V_6 = F_131 ( sizeof( * V_6 ) , V_199 ) ;
if ( ! V_6 ) {
F_36 ( & V_209 -> V_64 , L_12 ) ;
V_7 = - V_218 ;
goto exit;
}
V_6 -> V_10 = F_132 ( V_215 -> V_146 , F_133 ( V_215 ) ) ;
if ( ! V_6 -> V_10 ) {
V_7 = - V_219 ;
F_36 ( & V_209 -> V_64 , L_13 ) ;
goto V_220;
}
V_6 -> V_117 = V_117 ;
V_6 -> V_75 = (struct V_221 * ) V_211 -> V_222 ;
F_134 ( & V_6 -> V_9 ) ;
V_6 -> V_26 . V_10 = V_6 -> V_10 ;
V_6 -> V_26 . V_6 = V_6 ;
V_6 -> V_26 . V_28 = & V_28 -> V_223 ;
F_127 ( & V_6 -> V_26 ) ;
V_7 = F_38 ( & V_6 -> V_26 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_209 -> V_64 , L_14 ) ;
goto V_224;
}
V_6 -> V_27 . V_10 = V_6 -> V_10 + 0x40 ;
V_6 -> V_27 . V_6 = V_6 ;
V_6 -> V_27 . V_28 = & V_28 -> V_225 ;
F_127 ( & V_6 -> V_27 ) ;
V_7 = F_38 ( & V_6 -> V_27 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_209 -> V_64 , L_15 ) ;
goto V_226;
}
F_135 ( & V_209 -> V_64 ) ;
F_136 ( & V_209 -> V_64 , V_6 ) ;
V_7 = F_137 ( V_117 , & F_66 , 0 ,
V_211 -> V_227 , V_6 ) ;
if ( V_7 ) {
F_36 ( & V_209 -> V_64 , L_16 ) ;
goto V_228;
}
V_7 = F_138 ( & V_209 -> V_64 , & V_229 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_209 -> V_64 , L_17 ) ;
goto V_230;
}
V_7 = F_139 ( & V_209 -> V_64 , V_231 ,
F_140 ( V_231 ) ) ;
if ( V_7 < 0 ) {
F_36 ( & V_209 -> V_64 , L_18 ) ;
goto V_232;
}
return V_7 ;
V_232:
F_141 ( & V_209 -> V_64 ) ;
V_230:
F_142 ( V_117 , V_6 ) ;
V_228:
F_39 ( & V_6 -> V_27 ) ;
V_226:
F_39 ( & V_6 -> V_26 ) ;
V_224:
F_143 ( V_6 -> V_10 ) ;
F_144 ( & V_209 -> V_64 ) ;
V_220:
F_145 ( V_6 ) ;
V_6 = NULL ;
exit:
return V_7 ;
}
static int F_146 ( struct V_208 * V_209 )
{
struct V_5 * V_6 ;
V_6 = F_147 ( & V_209 -> V_64 ) ;
F_142 ( V_6 -> V_117 , V_6 ) ;
F_144 ( & V_209 -> V_64 ) ;
F_148 ( & V_209 -> V_64 , F_140 ( V_231 ) ) ;
F_141 ( & V_209 -> V_64 ) ;
F_39 ( & V_6 -> V_26 ) ;
F_39 ( & V_6 -> V_27 ) ;
F_143 ( V_6 -> V_10 ) ;
F_145 ( V_6 ) ;
return 0 ;
}
static void F_149 ( struct V_11 * V_12 ,
struct V_30 * V_31 ,
struct V_82 * V_64 )
{
if ( ! F_30 ( V_12 , V_31 ) )
return;
F_97 ( V_12 , V_31 ) ;
F_103 ( V_12 , V_64 ) ;
}
static void F_150 ( struct V_11 * V_12 ,
struct V_30 * V_31 ,
struct V_82 * V_64 )
{
if ( ! F_30 ( V_12 , V_31 ) )
return;
F_102 ( V_12 , V_31 , V_64 ) ;
if ( F_11 ( V_12 ) && V_12 -> V_83 )
F_49 ( V_64 , V_12 , V_12 -> V_83 , 1 ) ;
F_107 ( V_12 , V_31 ) ;
}
static int F_151 ( struct V_82 * V_64 )
{
struct V_5 * V_6 = F_147 ( V_64 ) ;
struct V_11 * V_26 = & V_6 -> V_26 ;
struct V_11 * V_27 = & V_6 -> V_27 ;
F_149 ( V_26 , & V_26 -> V_48 , V_64 ) ;
F_149 ( V_26 , & V_26 -> V_52 , V_64 ) ;
F_149 ( V_27 , & V_27 -> V_48 , V_64 ) ;
F_149 ( V_27 , & V_27 -> V_52 , V_64 ) ;
return 0 ;
}
static int F_152 ( struct V_82 * V_64 )
{
struct V_5 * V_6 = F_147 ( V_64 ) ;
struct V_11 * V_26 = & V_6 -> V_26 ;
struct V_11 * V_27 = & V_6 -> V_27 ;
F_150 ( V_26 , & V_26 -> V_48 , V_64 ) ;
F_150 ( V_26 , & V_26 -> V_52 , V_64 ) ;
F_150 ( V_27 , & V_27 -> V_48 , V_64 ) ;
F_150 ( V_27 , & V_27 -> V_52 , V_64 ) ;
return 0 ;
}
