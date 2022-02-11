struct V_1 * F_1 ( void )
{
return (struct V_1 * ) & V_2 ;
}
static inline struct V_3 * F_2 ( struct V_4 * V_5 )
{
return (struct V_3 * ) V_5 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_11 = F_4 ( V_7 ) | F_5 ( V_6 ) | F_6 ( V_9 ) | F_7 ( V_8 ) ;
F_8 ( & V_10 -> V_12 ) ;
F_9 ( V_13 , V_11 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_9 ( V_13 , 0 ) ;
F_11 ( & V_10 -> V_12 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 = ( ++ V_14 / V_10 -> V_16 . V_6 . V_17 ) + 1 ;
T_1 V_7 = ( V_14 % V_10 -> V_16 . V_6 . V_17 ) ;
F_3 ( V_5 , V_6 , V_7 , V_15 , 0 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_10 ( V_5 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_9 ,
T_1 V_18 ,
T_1 V_19 ,
T_1 V_20 ,
T_1 V_21 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
F_3 ( V_5 , 0 , 0 , 0 , V_9 ) ;
F_9 ( V_22 , V_18 ) ;
F_9 ( V_23 , V_19 ) ;
F_9 ( V_24 , V_20 ) ;
F_9 ( V_25 , V_21 ) ;
F_10 ( V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 , unsigned int V_26 ,
unsigned int V_9 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_27 = ( V_26 == 0 ) ? 0 : ( T_1 ) V_26 |
V_28 ;
F_9 ( V_29 + V_9 , V_27 ) ;
while ( ! ( F_16 ( V_30 ) & ( 1U << V_9 ) ) )
F_17 () ;
F_9 ( V_30 , 1U << V_9 ) ;
F_9 ( V_31 + V_9 , V_27 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 , T_1 V_14 ,
T_1 V_32 , T_2 V_33 )
{
return 0 ;
}
static int F_19 ( struct V_4 * V_5 , T_1 V_14 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_6 ;
T_1 V_7 ;
V_6 = ( V_14 / V_10 -> V_16 . V_6 . V_17 ) + 1 ;
V_7 = ( V_14 % V_10 -> V_16 . V_6 . V_17 ) ;
F_3 ( V_5 , V_6 , V_7 , 0 , 0 ) ;
F_9 ( V_34 , V_35 |
V_36 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_20 ( struct V_37 * V_38 )
{
T_1 V_39 ;
V_39 = V_38 -> V_40 * V_41 +
V_38 -> V_42 * V_43 ;
F_21 ( L_1 , V_39 ) ;
return V_39 ;
}
static inline struct V_44 * F_22 ( void * V_45 )
{
return (struct V_44 * ) V_45 ;
}
static inline struct V_37 * F_23 ( void * V_45 )
{
return (struct V_37 * ) V_45 ;
}
static int F_24 ( struct V_4 * V_5 , void * V_45 , T_1 V_14 ,
T_1 V_15 , T_1 T_3 * V_46 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_47 , V_48 ;
struct V_44 * V_38 ;
V_38 = F_22 ( V_45 ) ;
V_48 = ! F_25 ( V_47 , V_46 ) ;
if ( V_48 )
V_38 -> V_49 = V_47 ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_26 ( V_10 , V_38 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 , void * V_45 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_37 * V_38 ;
T_1 V_50 ;
V_38 = F_23 ( V_45 ) ;
V_50 = F_20 ( V_38 ) ;
F_9 ( V_50 + V_51 ,
V_38 -> V_52 ) ;
F_9 ( V_50 + V_53 ,
V_38 -> V_54 ) ;
F_9 ( V_50 + V_55 ,
V_38 -> V_56 ) ;
F_9 ( V_50 + V_57 ,
V_38 -> V_58 ) ;
F_9 ( V_50 + V_59 ,
V_38 -> V_60 ) ;
F_9 ( V_50 + V_61 ,
V_38 -> V_62 ) ;
F_9 ( V_50 + V_63 ,
V_38 -> V_64 ) ;
return 0 ;
}
static bool F_28 ( struct V_4 * V_5 , T_2 V_65 ,
T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_66 ;
bool V_39 = false ;
T_1 V_67 , V_68 ;
F_12 ( V_5 , V_14 , V_15 ) ;
V_66 = F_16 ( V_69 ) ;
if ( V_66 ) {
V_67 = F_29 ( V_65 >> 8 ) ;
V_68 = F_30 ( V_65 >> 8 ) ;
if ( V_67 == F_16 ( V_70 ) &&
V_68 == F_16 ( V_71 ) )
V_39 = true ;
}
F_13 ( V_5 ) ;
return V_39 ;
}
static bool F_31 ( struct V_4 * V_5 , void * V_45 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_37 * V_38 ;
T_1 V_50 ;
T_1 V_64 ;
V_38 = F_23 ( V_45 ) ;
V_50 = F_20 ( V_38 ) ;
V_64 = F_16 ( V_50 + V_63 ) ;
if ( V_64 & V_72 )
return true ;
return false ;
}
static int F_32 ( struct V_4 * V_5 , T_1 V_73 ,
unsigned int V_74 , T_1 V_14 ,
T_1 V_15 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_75 ;
int V_76 = V_74 ;
F_12 ( V_5 , V_14 , V_15 ) ;
F_9 ( V_77 , 0 ) ;
F_9 ( V_78 , V_73 ) ;
while ( true ) {
V_75 = F_16 ( V_69 ) ;
if ( V_75 & V_79 )
break;
if ( V_76 <= 0 ) {
F_33 ( L_2 ) ;
F_13 ( V_5 ) ;
return - V_80 ;
}
F_34 ( 20 ) ;
V_76 -= 20 ;
}
F_13 ( V_5 ) ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 , void * V_45 ,
unsigned int V_74 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
struct V_37 * V_38 ;
T_1 V_50 ;
T_1 V_75 ;
int V_76 = V_74 ;
V_38 = F_23 ( V_45 ) ;
V_50 = F_20 ( V_38 ) ;
V_75 = F_16 ( V_50 + V_63 ) ;
V_75 = V_75 & ~ V_72 ;
F_9 ( V_50 + V_63 , V_75 ) ;
while ( true ) {
V_75 = F_16 ( V_50 + V_81 ) ;
if ( V_75 & V_82 )
break;
if ( V_76 <= 0 )
return - V_80 ;
F_34 ( 20 ) ;
V_76 -= 20 ;
}
F_9 ( V_50 + V_61 , 0 ) ;
F_9 ( V_50 + V_83 , 0 ) ;
F_9 ( V_50 + V_84 , 0 ) ;
F_9 ( V_50 + V_53 , 0 ) ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
union V_85 V_86 ;
unsigned int V_87 ;
V_86 . V_88 = 0 ;
V_86 . V_89 . V_90 = 0 ;
V_86 . V_89 . V_91 = V_92 ;
V_86 . V_89 . V_93 = 1 ;
for ( V_87 = 0 ; V_87 < V_94 ; V_87 ++ )
F_9 ( V_95 [ V_87 * V_96 +
V_97 ] , V_86 . V_88 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 ,
unsigned int V_98 ,
T_1 V_99 ,
T_1 V_100 ,
T_1 V_101 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
union V_85 V_86 ;
V_86 . V_88 = V_99 ;
V_86 . V_89 . V_90 = 0 ;
F_9 ( V_95 [ V_98 * V_96 +
V_97 ] , V_86 . V_88 ) ;
F_9 ( V_95 [ V_98 * V_96 +
V_102 ] , V_100 ) ;
F_9 ( V_95 [ V_98 * V_96 +
V_103 ] , V_101 ) ;
V_86 . V_89 . V_90 = 1 ;
F_9 ( V_95 [ V_98 * V_96 +
V_97 ] , V_86 . V_88 ) ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 ,
T_1 V_104 ,
T_1 V_105 )
{
struct V_3 * V_10 = F_2 ( V_5 ) ;
T_1 V_106 ;
F_8 ( & V_10 -> V_107 ) ;
F_9 ( V_108 , V_104 ) ;
F_9 ( V_109 , V_105 ) ;
V_106 = V_110 |
V_111 |
V_112 ;
F_9 ( V_108 , V_106 ) ;
F_11 ( & V_10 -> V_107 ) ;
return 0 ;
}
static T_1 F_39 ( struct V_4 * V_5 ,
unsigned int V_98 ,
unsigned int V_113 )
{
return V_95 [ V_98 * V_96 + V_113 ] ;
}
static bool F_40 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_114 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_114 = F_16 ( V_29 + V_9 ) ;
return V_114 & V_28 ;
}
static T_5 F_41 ( struct V_4 * V_5 ,
T_4 V_9 )
{
T_1 V_114 ;
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
V_114 = F_16 ( V_29 + V_9 ) ;
return V_114 & V_28 ;
}
static void F_42 ( struct V_4 * V_5 , T_4 V_9 )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
F_9 ( V_115 , 1 << V_9 ) ;
}
static T_5 F_43 ( struct V_4 * V_5 , enum V_116 type )
{
struct V_3 * V_10 = (struct V_3 * ) V_5 ;
const union V_117 * V_118 ;
F_44 ( V_5 == NULL ) ;
switch ( type ) {
case V_119 :
V_118 = ( const union V_117 * )
V_10 -> V_16 . V_120 -> V_106 ;
break;
case V_121 :
V_118 = ( const union V_117 * )
V_10 -> V_16 . V_122 -> V_106 ;
break;
case V_123 :
V_118 = ( const union V_117 * )
V_10 -> V_16 . V_124 -> V_106 ;
break;
case V_125 :
V_118 = ( const union V_117 * )
V_10 -> V_16 . V_126 -> V_106 ;
break;
case V_127 :
V_118 = ( const union V_117 * )
V_10 -> V_16 . V_128 -> V_106 ;
break;
case V_129 :
V_118 = ( const union V_117 * )
V_10 -> V_16 . V_130 -> V_106 ;
break;
case V_131 :
V_118 = ( const union V_117 * )
V_10 -> V_132 . V_133 [ 0 ] . V_134 -> V_106 ;
break;
case V_135 :
V_118 = ( const union V_117 * )
V_10 -> V_132 . V_133 [ 1 ] . V_134 -> V_106 ;
break;
default:
return 0 ;
}
if ( V_118 == NULL )
return 0 ;
return V_118 -> V_136 . V_137 ;
}
