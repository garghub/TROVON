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
static int F_10 ( struct V_5 * V_6 )
{
return V_6 -> V_11 -> V_12 ;
}
static struct V_5 * F_11 ( struct V_13 * V_14 )
{
return V_14 -> V_6 ;
}
static int F_12 ( struct V_13 * V_14 )
{
return V_14 -> V_15 ;
}
static int F_13 ( struct V_13 * V_14 )
{
return V_14 -> V_6 -> V_10 == V_14 -> V_10 ;
}
static int F_14 ( struct V_13 * V_14 )
{
return V_14 -> V_16 ;
}
static int F_15 ( struct V_17 * V_18 )
{
return V_18 -> V_19 == V_20 ;
}
static struct V_21 * F_16 ( struct V_17 * V_18 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
return V_23 -> V_25 ;
}
static struct V_13 * F_17 ( struct V_21 * V_26 )
{
struct V_5 * V_6 = F_18 ( V_26 ) ;
if ( V_26 -> V_27 == 0 )
return & V_6 -> V_28 ;
else
return & V_6 -> V_29 ;
}
static struct V_13 * F_19 ( struct V_17 * V_18 )
{
return F_17 ( F_16 ( V_18 ) ) ;
}
static T_3 F_20 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_30 )
return NULL ;
return V_14 -> V_30 -> V_31 ;
}
static T_1 F_21 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_30 )
return 0 ;
return V_14 -> V_30 -> V_8 ;
}
static T_1 F_22 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
int V_34 = F_23 ( V_14 , V_33 ) ;
int V_35 = F_13 ( V_14 ) ;
T_1 V_36 ;
if ( V_35 )
V_36 = V_34 ? V_37 : V_38 ;
else
V_36 = V_34 ? V_39 : V_40 ;
return V_36 ;
}
static int F_24 ( struct V_13 * V_14 , int V_41 )
{
return V_41 * V_14 -> V_42 ;
}
static int F_25 ( struct V_13 * V_14 , int V_43 )
{
return V_43 / V_14 -> V_42 ;
}
static int F_26 ( struct V_13 * V_14 ,
struct V_32 * V_33 )
{
int V_34 = F_23 ( V_14 , V_33 ) ;
T_1 V_44 ;
int V_41 ;
V_44 = V_34 ?
F_27 ( V_14 , V_45 ) :
F_27 ( V_14 , V_46 ) ;
V_41 = 0x1ff & ( V_44 >> 8 ) ;
return F_24 ( V_14 , V_41 ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
T_1 V_47 = F_27 ( V_14 , V_45 ) ;
T_1 V_48 = F_27 ( V_14 , V_46 ) ;
if ( V_47 & V_49 )
V_14 -> V_50 . V_51 ++ ;
if ( V_47 & V_52 )
V_14 -> V_50 . V_53 ++ ;
if ( V_48 & V_49 )
V_14 -> V_54 . V_51 ++ ;
if ( V_48 & V_52 )
V_14 -> V_54 . V_53 ++ ;
F_29 ( V_14 , V_45 , 0 ) ;
F_29 ( V_14 , V_46 , 0 ) ;
}
static inline int F_23 ( struct V_13 * V_14 ,
struct V_32 * V_33 )
{
return & V_14 -> V_50 == V_33 ;
}
static inline struct V_32 * F_30 ( struct V_13 * V_14 ,
struct V_17 * V_18 )
{
return F_15 ( V_18 ) ? & V_14 -> V_50 : & V_14 -> V_54 ;
}
static int F_31 ( struct V_13 * V_14 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
int V_7 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = ! ! ( V_33 -> V_18 && V_33 -> V_18 -> V_55 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static struct V_13 * F_32 ( struct V_32 * V_33 )
{
return V_33 -> V_56 ;
}
static void F_33 ( struct V_13 * V_14 ,
struct V_32 * V_33 ,
struct V_17 * V_18 )
{
struct V_57 * V_55 = V_18 -> V_55 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_33 -> V_18 = V_18 ;
V_33 -> V_58 = F_24 ( V_14 , V_55 -> V_59 ) ;
V_33 -> V_60 = 0 ;
V_33 -> V_61 = F_24 ( V_14 , V_55 -> V_62 ) ;
V_33 -> V_63 = 0 ;
V_33 -> V_64 = F_34 ( V_55 , 1 ) ;
V_33 -> V_65 = 0 ;
V_33 -> V_51 = - 1 ;
V_33 -> V_53 = - 1 ;
F_35 ( V_33 , V_66 , V_14 , V_33 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static void F_36 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
struct V_21 * V_26 = F_16 ( V_33 -> V_18 ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
if ( V_33 -> V_51 > 0 )
F_37 ( V_26 -> V_67 , L_1 , V_33 -> V_51 ) ;
if ( V_33 -> V_53 > 0 )
F_37 ( V_26 -> V_67 , L_2 , V_33 -> V_53 ) ;
F_35 ( V_33 , V_68 , V_14 , V_33 ) ;
V_33 -> V_18 = NULL ;
V_33 -> V_58 = 0 ;
V_33 -> V_60 = 0 ;
V_33 -> V_61 = 0 ;
V_33 -> V_63 = 0 ;
V_33 -> V_64 = 0 ;
V_33 -> V_65 = 0 ;
V_33 -> V_51 = 0 ;
V_33 -> V_53 = 0 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static int F_38 ( struct V_32 * V_33 )
{
struct V_13 * V_14 = F_32 ( V_33 ) ;
if ( ! V_14 )
return - V_69 ;
return F_35 ( V_33 , V_70 , V_14 , V_33 ) ;
}
static int F_39 ( struct V_13 * V_14 , struct V_71 * V_67 )
{
struct V_32 * V_33 ;
int V_72 , V_73 ;
V_33 = & V_14 -> V_50 ;
V_72 = F_35 ( V_33 , V_74 , V_14 , V_33 , V_67 ) ;
V_33 = & V_14 -> V_54 ;
V_73 = F_35 ( V_33 , V_74 , V_14 , V_33 , V_67 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_73 < 0 )
return V_73 ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 )
{
struct V_32 * V_33 ;
int V_72 , V_73 ;
V_33 = & V_14 -> V_50 ;
V_72 = F_35 ( V_33 , remove , V_14 , V_33 ) ;
V_33 = & V_14 -> V_54 ;
V_73 = F_35 ( V_33 , remove , V_14 , V_33 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_73 < 0 )
return V_73 ;
return 0 ;
}
static void F_41 ( struct V_13 * V_14 , struct V_32 * V_33 ,
T_1 V_75 , struct V_71 * V_67 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
int V_34 = F_23 ( V_14 , V_33 ) ;
T_1 V_76 = V_14 -> V_76 ;
if ( F_10 ( V_6 ) >= 2 ) {
T_1 V_77 = 0 ;
switch ( V_75 ) {
case V_78 :
V_76 |= V_79 ;
V_77 |= V_80 ;
F_42 ( V_67 , L_3 ) ;
break;
case V_81 :
V_76 |= V_82 ;
V_77 |= V_83 ;
F_42 ( V_67 , L_4 ) ;
break;
case V_84 :
default:
V_76 |= V_79 ;
V_77 |= V_85 ;
F_42 ( V_67 , L_5 ) ;
break;
}
if ( V_34 )
F_29 ( V_14 , V_86 , V_77 ) ;
else
F_29 ( V_14 , V_87 , V_77 ) ;
}
if ( V_34 )
F_29 ( V_14 , V_88 , V_76 ) ;
else
F_29 ( V_14 , V_89 , V_76 ) ;
}
static void F_43 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
T_1 V_2 = F_44 ( 1 , F_22 ( V_14 , V_33 ) ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
F_45 ( V_6 , V_90 , V_2 , V_2 ) ;
F_45 ( V_6 , V_91 , V_2 , V_2 ) ;
}
static void F_46 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
T_1 V_2 = F_44 ( 1 , F_22 ( V_14 , V_33 ) ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
F_45 ( V_6 , V_90 , V_2 , 0 ) ;
F_45 ( V_6 , V_91 , V_2 , 0 ) ;
}
static T_1 F_47 ( struct V_5 * V_6 )
{
return F_48 ( V_6 , V_92 ) ;
}
static void F_49 ( struct V_13 * V_14 )
{
T_1 V_2 = 0 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
V_2 |= F_44 ( 1 , F_22 ( V_14 , & V_14 -> V_50 ) ) ;
V_2 |= F_44 ( 1 , F_22 ( V_14 , & V_14 -> V_54 ) ) ;
F_45 ( V_6 , V_92 , V_2 , 0 ) ;
}
static void F_50 ( struct V_13 * V_14 , int V_93 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_3 , V_4 ;
V_3 = V_94 | V_95 ;
V_4 = V_93 ? V_3 : 0 ;
F_13 ( V_14 ) ?
F_45 ( V_6 , V_96 , V_3 , V_4 ) :
F_45 ( V_6 , V_97 , V_3 , V_4 ) ;
}
static int F_51 ( struct V_71 * V_67 , struct V_13 * V_14 ,
long V_98 , int V_93 )
{
T_3 V_31 = F_20 ( V_14 ) ;
int V_7 ;
if ( ! V_31 )
return 0 ;
V_7 = V_31 ( V_67 , V_98 , V_93 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_93 )
return 0 ;
if ( V_7 > 0 ) {
T_1 V_2 = 0 ;
switch ( V_7 & V_99 ) {
default:
case V_100 :
V_2 |= ( 0x0 << 12 ) ;
break;
case V_101 :
V_2 |= ( 0x1 << 12 ) ;
break;
case V_102 :
V_2 |= ( 0x2 << 12 ) ;
break;
case V_103 :
V_2 |= ( 0x3 << 12 ) ;
break;
case V_104 :
V_2 |= ( 0x4 << 12 ) ;
break;
}
switch ( V_7 & V_105 ) {
default:
case V_106 :
V_2 |= ( 0x0 << 8 ) ;
break;
case V_107 :
V_2 |= ( 0x1 << 8 ) ;
break;
case V_108 :
V_2 |= ( 0x2 << 8 ) ;
break;
case V_109 :
V_2 |= ( 0x3 << 8 ) ;
break;
case V_110 :
V_2 |= ( 0x4 << 8 ) ;
break;
case V_111 :
V_2 |= ( 0x7 << 8 ) ;
break;
}
F_52 ( V_14 , V_112 , ( V_113 | V_114 ) , V_2 ) ;
F_53 ( 10 ) ;
V_7 = 0 ;
}
return V_7 ;
}
static void F_54 ( struct V_13 * V_14 , T_4 * V_115 , int V_43 )
{
T_1 V_116 = F_21 ( V_14 ) & V_117 ;
int V_118 ;
if ( V_116 ) {
T_1 * V_119 = ( T_1 * ) V_115 ;
for ( V_118 = 0 ; V_118 < V_43 / 2 ; V_118 ++ )
F_29 ( V_14 , V_120 , V_119 [ V_118 ] ) ;
} else {
T_5 * V_119 = ( T_5 * ) V_115 ;
for ( V_118 = 0 ; V_118 < V_43 ; V_118 ++ )
F_29 ( V_14 , V_120 , ( ( T_1 ) * ( V_119 + V_118 ) << 8 ) ) ;
}
}
static void F_55 ( struct V_13 * V_14 , T_4 * V_115 , int V_43 )
{
T_5 * V_119 = ( T_5 * ) V_115 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_43 ; V_118 ++ )
* ( V_119 + V_118 ) = ( T_5 ) ( F_27 ( V_14 , V_121 ) >> 8 ) ;
}
static void F_56 ( struct V_13 * V_14 , T_4 * V_115 , int V_43 )
{
T_1 * V_119 = ( T_1 * ) V_115 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_43 ; V_118 ++ )
F_29 ( V_14 , V_120 , * ( V_119 + V_118 ) ) ;
}
static void F_57 ( struct V_13 * V_14 , T_4 * V_115 , int V_43 )
{
T_1 * V_119 = ( T_1 * ) V_115 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_43 ; V_118 ++ )
* ( V_119 + V_118 ) = F_27 ( V_14 , V_121 ) ;
}
static T_4 * F_58 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
struct V_57 * V_55 = V_33 -> V_18 -> V_55 ;
return V_55 -> V_122 +
F_34 ( V_55 , V_33 -> V_60 ) ;
}
static int F_59 ( struct V_13 * V_14 , struct V_32 * V_33 ,
void (* F_60)( struct V_13 * V_14 , T_4 * V_119 , int V_43 ) ,
void (* F_61)( struct V_13 * V_14 , T_4 * V_119 , int V_43 ) ,
int V_43 )
{
struct V_57 * V_55 ;
struct V_17 * V_18 ;
T_4 * V_119 ;
int V_123 ;
if ( ! F_31 ( V_14 , V_33 ) )
return - V_124 ;
V_123 = 0 ;
V_18 = V_33 -> V_18 ;
V_55 = V_18 -> V_55 ;
if ( V_33 -> V_60 >=
V_33 -> V_61 * ( V_33 -> V_63 + 1 ) ) {
V_123 = 1 ;
V_33 -> V_63 = ( V_33 -> V_63 + 1 ) % V_55 -> V_125 ;
if ( 0 == V_33 -> V_63 )
V_33 -> V_60 = 0 ;
}
V_119 = F_58 ( V_14 , V_33 ) ;
switch ( V_33 -> V_64 ) {
case 2 :
F_60 ( V_14 , V_119 , V_43 ) ;
break;
case 4 :
F_61 ( V_14 , V_119 , V_43 ) ;
break;
default:
return - V_124 ;
}
V_33 -> V_60 += V_43 ;
if ( V_123 )
F_62 ( V_18 ) ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
int V_126 ;
int V_127 ;
int V_43 ;
V_126 = F_26 ( V_14 , V_33 ) ;
V_127 = V_33 -> V_58 - V_33 -> V_60 ;
V_43 = F_64 ( V_126 , V_127 ) ;
return F_59 ( V_14 , V_33 ,
F_55 ,
F_57 ,
V_43 ) ;
}
static int F_65 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
int V_126 ;
int V_127 ;
int V_43 ;
V_126 = V_33 -> V_58 - V_33 -> V_60 ;
V_127 = V_33 -> V_128 -
F_26 ( V_14 , V_33 ) ;
V_43 = F_64 ( V_126 , V_127 ) ;
return F_59 ( V_14 , V_33 ,
F_54 ,
F_56 ,
V_43 ) ;
}
static void F_66 ( struct V_13 * V_14 , struct V_32 * V_33 ,
int V_93 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_129 = F_13 ( V_14 ) ? V_130 : V_131 ;
if ( V_93 )
F_43 ( V_14 , V_33 ) ;
else
F_46 ( V_14 , V_33 ) ;
if ( F_12 ( V_14 ) )
F_67 ( V_6 , V_132 , V_129 , ( V_93 ) ? V_129 : 0 ) ;
}
static int F_68 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
T_1 V_116 = F_21 ( V_14 ) & V_117 ;
if ( V_116 )
V_33 -> V_65 = F_69 ( 24 , V_84 ) |
F_69 ( 16 , V_81 ) ;
else
V_33 -> V_65 = F_69 ( 24 , V_84 ) |
F_69 ( 16 , V_84 ) ;
return 0 ;
}
static int F_70 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
V_33 -> V_65 = F_69 ( 24 , V_84 ) |
F_69 ( 16 , V_84 ) ;
return 0 ;
}
static T_6 F_71 ( int V_133 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
T_1 V_92 = F_47 ( V_6 ) ;
F_67 ( V_6 , V_134 , V_135 , 0 ) ;
F_67 ( V_6 , V_134 , V_135 , V_135 ) ;
if ( V_92 & F_44 ( 1 , V_37 ) )
F_38 ( & V_6 -> V_28 . V_50 ) ;
if ( V_92 & F_44 ( 1 , V_39 ) )
F_38 ( & V_6 -> V_29 . V_50 ) ;
if ( V_92 & F_44 ( 1 , V_38 ) )
F_38 ( & V_6 -> V_28 . V_54 ) ;
if ( V_92 & F_44 ( 1 , V_40 ) )
F_38 ( & V_6 -> V_29 . V_54 ) ;
F_28 ( & V_6 -> V_28 ) ;
F_28 ( & V_6 -> V_29 ) ;
F_49 ( & V_6 -> V_28 ) ;
F_49 ( & V_6 -> V_29 ) ;
return V_136 ;
}
static int F_72 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
struct V_57 * V_55 = V_33 -> V_18 -> V_55 ;
struct V_21 * V_26 = F_16 ( V_33 -> V_18 ) ;
enum V_137 V_138 = F_23 ( V_14 , V_33 ) ?
V_139 : V_140 ;
V_33 -> V_65 = F_69 ( 24 , V_84 ) |
F_69 ( 16 , V_81 ) ;
V_33 -> V_77 = F_73 ( V_26 -> V_67 , V_55 -> V_122 ,
F_74 ( V_33 -> V_18 ) , V_138 ) ;
return 0 ;
}
static int F_75 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
struct V_21 * V_26 = F_16 ( V_33 -> V_18 ) ;
enum V_137 V_138 = F_23 ( V_14 , V_33 ) ?
V_139 : V_140 ;
F_76 ( V_26 -> V_67 , V_33 -> V_77 ,
F_74 ( V_33 -> V_18 ) , V_138 ) ;
return 0 ;
}
static T_7 F_77 ( struct V_32 * V_33 )
{
struct V_57 * V_55 = V_33 -> V_18 -> V_55 ;
return V_33 -> V_77 + F_34 ( V_55 , V_33 -> V_60 ) ;
}
static void F_78 ( void * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 ;
struct V_13 * V_14 = F_32 ( V_33 ) ;
struct V_57 * V_55 = V_33 -> V_18 -> V_55 ;
struct V_21 * V_26 = F_16 ( V_33 -> V_18 ) ;
enum V_137 V_138 = F_23 ( V_14 , V_33 ) ?
V_139 : V_140 ;
F_79 ( V_26 -> V_67 , F_77 ( V_33 ) ,
F_34 ( V_55 , V_33 -> V_61 ) , V_138 ) ;
V_33 -> V_60 += V_33 -> V_61 ;
V_33 -> V_63 ++ ;
if ( V_33 -> V_63 >= V_55 -> V_125 ) {
V_33 -> V_63 = 0 ;
V_33 -> V_60 = 0 ;
}
F_28 ( V_14 ) ;
F_38 ( V_33 ) ;
F_62 ( V_33 -> V_18 ) ;
}
static void F_80 ( struct V_141 * V_142 )
{
struct V_32 * V_33 = F_81 ( V_142 , struct V_32 , V_142 ) ;
struct V_13 * V_14 = F_32 ( V_33 ) ;
struct V_21 * V_26 ;
struct V_143 * V_144 ;
struct V_57 * V_55 ;
enum V_137 V_138 ;
int V_34 = F_23 ( V_14 , V_33 ) ;
int V_145 ;
T_7 V_119 ;
if ( ! F_31 ( V_14 , V_33 ) )
return;
V_26 = F_16 ( V_33 -> V_18 ) ;
V_55 = V_33 -> V_18 -> V_55 ;
V_138 = V_34 ? V_139 : V_140 ;
V_145 = F_34 ( V_55 , V_33 -> V_61 ) ;
V_119 = F_77 ( V_33 ) ;
F_82 ( V_26 -> V_67 , V_119 , V_145 , V_138 ) ;
V_144 = F_83 ( V_33 -> V_146 , V_119 , V_145 , V_138 ,
V_147 | V_148 ) ;
if ( ! V_144 ) {
F_37 ( V_26 -> V_67 , L_6 ) ;
return;
}
V_144 -> V_149 = F_78 ;
V_144 -> V_150 = V_33 ;
if ( F_84 ( V_144 ) < 0 ) {
F_37 ( V_26 -> V_67 , L_7 ) ;
return;
}
F_85 ( V_33 -> V_146 ) ;
if ( ! V_34 ) {
if ( V_49 & F_27 ( V_14 , V_46 ) ) {
F_52 ( V_14 , V_151 , V_152 , V_152 ) ;
F_29 ( V_14 , V_46 , 0 ) ;
}
}
}
static bool F_86 ( struct V_153 * V_146 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
V_146 -> V_157 = V_156 ;
return true ;
}
static int F_87 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
F_88 ( & V_33 -> V_142 ) ;
return 0 ;
}
static void F_89 ( struct V_13 * V_14 , struct V_32 * V_33 ,
int V_158 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_129 = F_13 ( V_14 ) ? V_130 : V_131 ;
T_1 V_93 = V_158 ? V_159 : 0 ;
F_52 ( V_14 , V_86 , V_159 , V_93 ) ;
F_90 ( V_33 -> V_146 ) ;
if ( F_12 ( V_14 ) )
F_67 ( V_6 , V_132 , V_129 , ( V_93 ) ? V_129 : 0 ) ;
}
static int F_91 ( struct V_13 * V_14 , struct V_32 * V_33 , struct V_71 * V_67 )
{
T_8 V_3 ;
F_92 ( V_3 ) ;
F_93 ( V_160 , V_3 ) ;
V_33 -> V_146 = F_94 ( V_3 , F_86 , & V_33 -> V_156 ) ;
if ( ! V_33 -> V_146 ) {
if ( F_23 ( V_14 , V_33 ) )
V_14 -> V_50 . V_161 = & V_162 ;
else
V_14 -> V_54 . V_161 = & V_163 ;
F_95 ( V_67 , L_8 ) ;
return F_39 ( V_14 , V_67 ) ;
}
F_96 ( & V_33 -> V_142 , F_80 ) ;
return 0 ;
}
static int F_97 ( struct V_13 * V_14 , struct V_32 * V_33 )
{
F_98 ( & V_33 -> V_142 ) ;
F_99 ( V_14 , V_33 ) ;
if ( V_33 -> V_146 )
F_100 ( V_33 -> V_146 ) ;
V_33 -> V_146 = NULL ;
return 0 ;
}
static void F_101 ( struct V_13 * V_14 ,
struct V_32 * V_33 ,
struct V_71 * V_67 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
int V_34 = F_23 ( V_14 , V_33 ) ;
T_1 V_36 , V_118 ;
int V_164 ;
V_36 = F_102 ( V_6 , V_165 ) ;
V_36 >>= F_22 ( V_14 , V_33 ) ;
V_36 &= V_166 ;
V_164 = 256 << V_36 ;
F_42 ( V_67 , L_9 , V_164 ) ;
for ( V_118 = 1 ; V_118 < V_14 -> V_42 ; V_118 <<= 1 )
V_164 >>= 1 ;
F_42 ( V_67 , L_10 ,
V_14 -> V_42 , V_164 ) ;
V_33 -> V_128 = F_24 ( V_14 , V_164 ) ;
if ( V_34 ) {
F_29 ( V_14 , V_167 , V_168 ) ;
F_52 ( V_14 , V_167 , V_152 , V_152 ) ;
} else {
F_29 ( V_14 , V_151 , V_168 ) ;
F_52 ( V_14 , V_151 , V_152 , V_152 ) ;
}
}
static int F_103 ( struct V_13 * V_14 ,
struct V_32 * V_33 ,
struct V_71 * V_67 )
{
T_1 V_8 = F_21 ( V_14 ) ;
T_1 V_2 = 0 ;
if ( F_12 ( V_14 ) )
V_2 = V_169 | V_170 ;
F_52 ( V_14 , V_112 , ( V_169 | V_170 ) , V_2 ) ;
V_2 = 0 ;
if ( V_171 & V_8 )
V_2 |= 1 << 12 ;
if ( V_172 & V_8 )
V_2 |= 1 << 8 ;
if ( V_173 & V_8 )
V_2 |= 1 << 4 ;
if ( V_174 & V_8 )
V_2 |= 1 << 0 ;
F_29 ( V_14 , V_175 , V_2 ) ;
if ( F_14 ( V_14 ) ) {
F_50 ( V_14 , 1 ) ;
F_52 ( V_14 , V_176 , V_177 , V_177 ) ;
}
V_2 = 0 ;
switch ( V_33 -> V_64 ) {
case 2 :
V_2 = F_104 ( 16 , V_33 -> V_65 ) ;
break;
case 4 :
V_2 = F_104 ( 24 , V_33 -> V_65 ) ;
break;
}
F_41 ( V_14 , V_33 , V_2 , V_67 ) ;
F_46 ( V_14 , V_33 ) ;
F_49 ( V_14 ) ;
F_101 ( V_14 , V_33 , V_67 ) ;
return 0 ;
}
static void F_105 ( struct V_13 * V_14 ,
struct V_71 * V_67 )
{
if ( F_12 ( V_14 ) )
F_51 ( V_67 , V_14 , V_14 -> V_98 , 0 ) ;
}
static int F_106 ( struct V_17 * V_18 ,
struct V_21 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_18 ) ;
V_14 -> V_98 = 0 ;
return 0 ;
}
static void F_107 ( struct V_17 * V_18 ,
struct V_21 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_18 ) ;
V_14 -> V_98 = 0 ;
}
static int F_108 ( struct V_17 * V_18 , int V_178 ,
struct V_21 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_18 ) ;
struct V_32 * V_33 = F_30 ( V_14 , V_18 ) ;
int V_7 = 0 ;
switch ( V_178 ) {
case V_179 :
F_33 ( V_14 , V_33 , V_18 ) ;
F_103 ( V_14 , V_33 , V_26 -> V_67 ) ;
V_7 = F_38 ( V_33 ) ;
if ( 0 == V_7 )
F_109 ( V_14 , V_33 ) ;
break;
case V_180 :
F_105 ( V_14 , V_26 -> V_67 ) ;
F_99 ( V_14 , V_33 ) ;
F_36 ( V_14 , V_33 ) ;
break;
}
return V_7 ;
}
static int F_110 ( struct V_13 * V_14 , unsigned int V_76 )
{
switch ( V_76 & V_181 ) {
case V_182 :
V_14 -> V_76 = V_183 ;
V_14 -> V_42 = 2 ;
break;
case V_184 :
V_14 -> V_76 = V_185 ;
V_14 -> V_42 = 2 ;
break;
default:
return - V_124 ;
}
return 0 ;
}
static int F_111 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
if ( F_10 ( V_6 ) < 2 )
return - V_124 ;
V_14 -> V_76 = V_186 | V_185 ;
V_14 -> V_42 = 2 ;
V_14 -> V_16 = 1 ;
return 0 ;
}
static int F_112 ( struct V_21 * V_26 , unsigned int V_76 )
{
struct V_13 * V_14 = F_17 ( V_26 ) ;
T_3 V_31 = F_20 ( V_14 ) ;
T_1 V_8 = F_21 ( V_14 ) ;
int V_7 ;
switch ( V_76 & V_187 ) {
case V_188 :
V_14 -> V_15 = 1 ;
break;
case V_189 :
break;
default:
return - V_124 ;
}
if ( F_12 ( V_14 ) && ! V_31 ) {
F_37 ( V_26 -> V_67 , L_11 ) ;
return - V_124 ;
}
switch ( V_8 & V_190 ) {
case V_191 :
V_7 = F_110 ( V_14 , V_76 & V_181 ) ;
break;
case V_192 :
V_7 = F_111 ( V_14 ) ;
break;
default:
V_7 = - V_124 ;
}
return V_7 ;
}
static int F_113 ( struct V_17 * V_18 ,
struct V_193 * V_194 ,
struct V_21 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_18 ) ;
long V_98 = F_114 ( V_194 ) ;
int V_7 ;
if ( ! F_12 ( V_14 ) )
return 0 ;
V_7 = F_51 ( V_26 -> V_67 , V_14 , V_98 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_14 -> V_98 = V_98 ;
return V_7 ;
}
static int F_115 ( struct V_17 * V_18 )
{
struct V_57 * V_55 = V_18 -> V_55 ;
int V_7 = 0 ;
F_116 ( V_18 , & V_195 ) ;
V_7 = F_117 ( V_55 ,
V_196 ) ;
return V_7 ;
}
static int F_118 ( struct V_17 * V_18 ,
struct V_193 * V_197 )
{
return F_119 ( V_18 ,
F_120 ( V_197 ) ) ;
}
static int F_121 ( struct V_17 * V_18 )
{
return F_122 ( V_18 ) ;
}
static T_9 F_123 ( struct V_17 * V_18 )
{
struct V_13 * V_14 = F_19 ( V_18 ) ;
struct V_32 * V_33 = F_30 ( V_14 , V_18 ) ;
return F_25 ( V_14 , V_33 -> V_60 ) ;
}
static void F_124 ( struct V_198 * V_199 )
{
F_125 ( V_199 ) ;
}
static int F_126 ( struct V_22 * V_23 )
{
struct V_198 * V_199 = V_23 -> V_199 ;
return F_127 (
V_199 ,
V_200 ,
F_128 ( V_201 ) ,
V_202 , V_203 ) ;
}
static void F_129 ( struct V_13 * V_14 )
{
V_14 -> V_50 . V_161 = & V_162 ;
V_14 -> V_50 . V_56 = V_14 ;
V_14 -> V_54 . V_161 = & V_163 ;
V_14 -> V_54 . V_56 = V_14 ;
if ( V_14 -> V_30 -> V_204 ) {
V_14 -> V_50 . V_156 . V_205 . V_206 = V_14 -> V_30 -> V_204 ;
V_14 -> V_50 . V_161 = & V_207 ;
}
}
static int F_130 ( struct V_208 * V_209 )
{
struct V_5 * V_6 ;
const struct V_210 * V_211 ;
struct V_212 * V_30 = V_209 -> V_67 . V_213 ;
struct V_214 * V_215 ;
unsigned int V_133 ;
int V_7 ;
V_211 = V_209 -> V_211 ;
if ( ! V_211 ) {
F_37 ( & V_209 -> V_67 , L_12 ) ;
return - V_216 ;
}
V_215 = F_131 ( V_209 , V_217 , 0 ) ;
V_133 = F_132 ( V_209 , 0 ) ;
if ( ! V_215 || ( int ) V_133 <= 0 ) {
F_37 ( & V_209 -> V_67 , L_13 ) ;
return - V_216 ;
}
V_6 = F_133 ( & V_209 -> V_67 , sizeof( * V_6 ) , V_201 ) ;
if ( ! V_6 ) {
F_37 ( & V_209 -> V_67 , L_14 ) ;
return - V_218 ;
}
V_6 -> V_10 = F_134 ( & V_209 -> V_67 ,
V_215 -> V_158 , F_135 ( V_215 ) ) ;
if ( ! V_6 -> V_10 ) {
F_37 ( & V_209 -> V_67 , L_15 ) ;
return - V_219 ;
}
V_6 -> V_133 = V_133 ;
V_6 -> V_11 = (struct V_220 * ) V_211 -> V_221 ;
F_136 ( & V_6 -> V_9 ) ;
V_6 -> V_28 . V_10 = V_6 -> V_10 ;
V_6 -> V_28 . V_6 = V_6 ;
V_6 -> V_28 . V_30 = & V_30 -> V_222 ;
F_129 ( & V_6 -> V_28 ) ;
V_7 = F_39 ( & V_6 -> V_28 , & V_209 -> V_67 ) ;
if ( V_7 < 0 ) {
F_37 ( & V_209 -> V_67 , L_16 ) ;
return V_7 ;
}
V_6 -> V_29 . V_10 = V_6 -> V_10 + 0x40 ;
V_6 -> V_29 . V_6 = V_6 ;
V_6 -> V_29 . V_30 = & V_30 -> V_223 ;
F_129 ( & V_6 -> V_29 ) ;
V_7 = F_39 ( & V_6 -> V_29 , & V_209 -> V_67 ) ;
if ( V_7 < 0 ) {
F_37 ( & V_209 -> V_67 , L_17 ) ;
goto V_224;
}
F_137 ( & V_209 -> V_67 ) ;
F_138 ( & V_209 -> V_67 , V_6 ) ;
V_7 = F_139 ( V_133 , & F_71 , 0 ,
V_211 -> V_225 , V_6 ) ;
if ( V_7 ) {
F_37 ( & V_209 -> V_67 , L_18 ) ;
goto V_226;
}
V_7 = F_140 ( & V_209 -> V_67 , & V_227 ) ;
if ( V_7 < 0 ) {
F_37 ( & V_209 -> V_67 , L_19 ) ;
goto V_228;
}
V_7 = F_141 ( & V_209 -> V_67 , V_229 ,
F_142 ( V_229 ) ) ;
if ( V_7 < 0 ) {
F_37 ( & V_209 -> V_67 , L_20 ) ;
goto V_230;
}
return V_7 ;
V_230:
F_143 ( & V_209 -> V_67 ) ;
V_228:
F_144 ( V_133 , V_6 ) ;
V_226:
F_145 ( & V_209 -> V_67 ) ;
F_40 ( & V_6 -> V_29 ) ;
V_224:
F_40 ( & V_6 -> V_28 ) ;
return V_7 ;
}
static int F_146 ( struct V_208 * V_209 )
{
struct V_5 * V_6 ;
V_6 = F_147 ( & V_209 -> V_67 ) ;
F_144 ( V_6 -> V_133 , V_6 ) ;
F_145 ( & V_209 -> V_67 ) ;
F_148 ( & V_209 -> V_67 , F_142 ( V_229 ) ) ;
F_143 ( & V_209 -> V_67 ) ;
F_40 ( & V_6 -> V_28 ) ;
F_40 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_149 ( struct V_13 * V_14 ,
struct V_32 * V_33 ,
struct V_71 * V_67 )
{
if ( ! F_31 ( V_14 , V_33 ) )
return;
F_99 ( V_14 , V_33 ) ;
F_105 ( V_14 , V_67 ) ;
}
static void F_150 ( struct V_13 * V_14 ,
struct V_32 * V_33 ,
struct V_71 * V_67 )
{
if ( ! F_31 ( V_14 , V_33 ) )
return;
F_103 ( V_14 , V_33 , V_67 ) ;
if ( F_12 ( V_14 ) && V_14 -> V_98 )
F_51 ( V_67 , V_14 , V_14 -> V_98 , 1 ) ;
F_109 ( V_14 , V_33 ) ;
}
static int F_151 ( struct V_71 * V_67 )
{
struct V_5 * V_6 = F_147 ( V_67 ) ;
struct V_13 * V_28 = & V_6 -> V_28 ;
struct V_13 * V_29 = & V_6 -> V_29 ;
F_149 ( V_28 , & V_28 -> V_50 , V_67 ) ;
F_149 ( V_28 , & V_28 -> V_54 , V_67 ) ;
F_149 ( V_29 , & V_29 -> V_50 , V_67 ) ;
F_149 ( V_29 , & V_29 -> V_54 , V_67 ) ;
return 0 ;
}
static int F_152 ( struct V_71 * V_67 )
{
struct V_5 * V_6 = F_147 ( V_67 ) ;
struct V_13 * V_28 = & V_6 -> V_28 ;
struct V_13 * V_29 = & V_6 -> V_29 ;
F_150 ( V_28 , & V_28 -> V_50 , V_67 ) ;
F_150 ( V_28 , & V_28 -> V_54 , V_67 ) ;
F_150 ( V_29 , & V_29 -> V_50 , V_67 ) ;
F_150 ( V_29 , & V_29 -> V_54 , V_67 ) ;
return 0 ;
}
