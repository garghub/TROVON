static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_5 , T_1 V_7 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_6 ) ;
V_8 &= ~ V_7 ;
V_8 |= V_5 ;
F_3 ( V_2 , V_6 , V_8 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_10 = V_11 + V_12 ;
while ( ! ( F_1 ( V_2 , V_3 ) & V_9 ) ) {
if ( F_7 ( V_10 ) )
return - V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
T_1 * V_19 = ( T_1 * ) V_18 -> V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_23 / sizeof( T_1 ) ; V_21 ++ ) {
if ( V_16 )
V_19 [ V_21 ] = F_1 ( V_2 , F_10 ( V_2 , V_21 ) ) ;
else
F_3 ( V_2 , F_10 ( V_2 , V_21 ) , V_19 [ V_21 ] ) ;
}
}
static void F_11 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_21 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) ) {
struct V_26 * V_27 = F_13 ( V_2 -> V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
T_1 * V_33 = ( T_1 * ) V_31 -> V_33 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_23 / sizeof( T_1 ) ; V_21 ++ ) {
if ( V_16 )
V_33 [ V_21 ] = F_1 ( V_2 ,
F_15 ( V_21 ) ) ;
else
F_3 ( V_2 , F_15 ( V_21 ) ,
V_33 [ V_21 ] ) ;
}
}
F_8 ( V_15 , V_16 ) ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
T_1 * V_34 = ( T_1 * ) V_18 -> V_20 ;
T_1 * V_19 = ( T_1 * ) V_15 -> V_35 ;
int V_21 , V_36 , V_37 = 0 ;
if ( ! V_19 )
return;
switch ( V_18 -> V_24 & V_38 ) {
case V_39 :
V_36 = V_40 / sizeof( T_1 ) ;
break;
case V_41 :
if ( F_17 ( V_42 , & V_18 -> V_2 -> V_24 ) )
V_37 = 1 ;
V_36 = V_43 / sizeof( T_1 ) ;
break;
case V_44 :
V_36 = V_45 / sizeof( T_1 ) ;
break;
case V_46 :
V_36 = V_47 / sizeof( T_1 ) ;
break;
default:
V_36 = 0 ;
}
if ( V_37 )
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ )
V_19 [ V_21 ] = F_18 ( V_34 [ V_21 ] ) ;
else
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ )
V_19 [ V_21 ] = F_19 ( V_34 [ V_21 ] ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_48 ) ;
if ( ! F_17 ( V_49 , & V_2 -> V_24 ) ) {
F_22 ( V_49 , & V_2 -> V_24 ) ;
V_2 -> V_50 = 0 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_51 ,
int V_52 , int V_53 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 = V_51 << 5 , V_7 ;
if ( F_24 ( V_18 -> V_54 ) )
F_3 ( V_2 , F_25 ( V_2 ) , V_18 -> V_54 ) ;
F_5 ( V_2 , F_26 ( V_2 ) ,
V_55 | ( V_53 ? V_56 : 0 ) ,
V_55 | V_56 ) ;
if ( ( V_18 -> V_24 & V_38 ) == V_41 )
V_8 |= V_57 ;
if ( ! V_18 -> V_54 )
V_8 |= V_58 ;
if ( V_52 )
V_8 |= V_59 ;
V_7 = V_58 | V_59 |
V_57 | V_60 ;
F_5 ( V_2 , V_61 , V_8 , V_7 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_51 )
{
}
static int F_28 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_61 , V_62 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , int V_63 )
{
for (; V_63 -- ; V_5 ++ , V_3 += 4 )
F_3 ( V_2 , V_3 , * V_5 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_2 V_51 ,
int V_52 , int V_53 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 , V_7 ;
V_8 = ( V_18 -> V_24 & V_38 ) >> ( V_64 - 1 ) ;
if ( ! V_18 -> V_54 ) {
struct V_26 * V_27 = F_13 ( V_2 -> V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
V_8 |= V_65 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) ) {
V_8 |= V_66 ;
F_29 ( V_2 , F_15 ( 0 ) ,
( T_1 * ) V_31 -> V_67 ,
V_68 / sizeof( T_1 ) ) ;
V_18 -> V_54 += V_68 ;
}
}
if ( V_52 ) {
V_8 |= V_69 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) )
V_8 |= V_70 ;
}
V_7 = V_65 | V_69 |
V_71 | V_70 |
V_66 ;
F_31 ( V_2 -> V_48 , L_1 , V_8 , V_18 -> V_24 ) ;
F_5 ( V_2 , V_72 , V_8 , V_7 ) ;
F_3 ( V_2 , V_73 , V_74 ) ;
F_5 ( V_2 , F_26 ( V_2 ) ,
V_55 |
( V_53 ? V_56 : 0 ) ,
V_55 | V_56 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_51 )
{
F_3 ( V_2 , V_75 , V_51 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_76 ,
V_77 ) ;
}
static int F_34 ( struct V_1 * V_2 , const T_3 * V_78 ,
T_2 V_51 , int V_52 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_63 , V_79 ;
const T_1 * V_80 = ( const T_1 * ) V_78 ;
F_31 ( V_2 -> V_48 , L_2 ,
V_18 -> V_54 , V_51 , V_52 ) ;
V_2 -> V_22 -> V_81 ( V_2 , V_51 , V_52 , 0 ) ;
V_2 -> V_22 -> V_82 ( V_2 , V_51 ) ;
V_18 -> V_54 += V_51 ;
if ( V_2 -> V_22 -> V_83 ( V_2 ) )
return - V_13 ;
if ( V_52 )
F_22 ( V_84 , & V_2 -> V_24 ) ;
F_22 ( V_85 , & V_2 -> V_24 ) ;
V_79 = F_35 ( V_51 , sizeof( T_1 ) ) ;
for ( V_63 = 0 ; V_63 < V_79 ; V_63 ++ )
F_3 ( V_2 , F_36 ( V_2 , V_63 ) , V_80 [ V_63 ] ) ;
return - V_86 ;
}
static void F_37 ( void * V_87 )
{
struct V_1 * V_2 = V_87 ;
F_22 ( V_88 , & V_2 -> V_24 ) ;
F_38 ( & V_2 -> V_89 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_4 V_90 ,
T_2 V_51 , int V_52 , int V_91 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
struct V_92 * V_93 ;
struct V_94 V_95 ;
int V_79 , V_96 ;
F_31 ( V_2 -> V_48 , L_3 ,
V_18 -> V_54 , V_51 , V_52 ) ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_97 = V_2 -> V_98 + F_36 ( V_2 , 0 ) ;
V_95 . V_99 = V_100 ;
V_95 . V_101 = V_102 ;
V_96 = F_40 ( V_2 -> V_103 , & V_95 ) ;
if ( V_96 ) {
F_41 ( L_4 , V_96 ) ;
return V_96 ;
}
V_79 = F_35 ( V_51 , V_104 ) * V_104 ;
if ( V_91 ) {
F_42 ( & V_18 -> V_105 , 1 ) ;
V_18 -> V_105 . V_106 = V_18 -> V_107 -> V_106 ;
V_18 -> V_105 . V_3 = V_18 -> V_107 -> V_3 ;
F_43 ( & V_18 -> V_105 ) = V_79 ;
F_44 ( & V_18 -> V_105 ) = F_44 ( V_18 -> V_107 ) ;
V_93 = F_45 ( V_2 -> V_103 , & V_18 -> V_105 , 1 ,
V_108 , V_109 | V_110 ) ;
} else {
V_93 = F_46 ( V_2 -> V_103 , V_90 , V_79 ,
V_108 , V_109 | V_110 ) ;
}
if ( ! V_93 ) {
F_47 ( V_2 -> V_48 , L_5 ) ;
return - V_111 ;
}
V_93 -> V_112 = F_37 ;
V_93 -> V_113 = V_2 ;
V_2 -> V_22 -> V_81 ( V_2 , V_51 , V_52 , 1 ) ;
V_18 -> V_54 += V_51 ;
if ( V_52 )
F_22 ( V_84 , & V_2 -> V_24 ) ;
F_22 ( V_114 , & V_2 -> V_24 ) ;
F_48 ( V_93 ) ;
F_49 ( V_2 -> V_103 ) ;
V_2 -> V_22 -> V_82 ( V_2 , V_51 ) ;
return - V_86 ;
}
static T_2 F_50 ( struct V_17 * V_18 ,
const T_3 * V_115 , T_2 V_51 )
{
T_2 V_63 = F_51 ( V_51 , V_18 -> V_116 - V_18 -> V_117 ) ;
V_63 = F_51 ( V_63 , V_18 -> V_118 ) ;
if ( V_63 <= 0 )
return 0 ;
memcpy ( V_18 -> V_80 + V_18 -> V_117 , V_115 , V_63 ) ;
V_18 -> V_117 += V_63 ;
return V_63 ;
}
static T_2 F_52 ( struct V_17 * V_18 )
{
T_2 V_63 ;
while ( V_18 -> V_107 ) {
V_63 = F_50 ( V_18 ,
F_53 ( V_18 -> V_107 ) + V_18 -> V_3 ,
V_18 -> V_107 -> V_51 - V_18 -> V_3 ) ;
if ( ! V_63 )
break;
V_18 -> V_3 += V_63 ;
V_18 -> V_118 -= V_63 ;
if ( V_18 -> V_3 == V_18 -> V_107 -> V_51 ) {
V_18 -> V_107 = F_54 ( V_18 -> V_107 ) ;
if ( V_18 -> V_107 )
V_18 -> V_3 = 0 ;
else
V_18 -> V_118 = 0 ;
}
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_2 V_51 , int V_52 )
{
int V_96 ;
V_18 -> V_90 = F_56 ( V_2 -> V_48 , V_18 -> V_80 , V_18 -> V_116 ,
V_119 ) ;
if ( F_57 ( V_2 -> V_48 , V_18 -> V_90 ) ) {
F_47 ( V_2 -> V_48 , L_6 , V_18 -> V_116 ) ;
return - V_111 ;
}
V_18 -> V_24 &= ~ F_12 ( V_120 ) ;
V_96 = F_39 ( V_2 , V_18 -> V_90 , V_51 , V_52 , 0 ) ;
if ( V_96 != - V_86 )
F_58 ( V_2 -> V_48 , V_18 -> V_90 , V_18 -> V_116 ,
V_119 ) ;
return V_96 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_52 ;
T_2 V_63 ;
F_52 ( V_18 ) ;
V_52 = ( V_18 -> V_24 & F_12 ( V_121 ) ) && ! V_18 -> V_118 ;
F_31 ( V_2 -> V_48 , L_7 ,
V_18 -> V_117 , V_18 -> V_54 , V_52 ) ;
if ( V_52 || ( V_18 -> V_117 == V_18 -> V_116 && V_18 -> V_118 ) ) {
V_63 = V_18 -> V_117 ;
V_18 -> V_117 = 0 ;
return F_55 ( V_2 , V_18 , V_63 , V_52 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_51 , V_52 , V_122 ;
struct V_123 * V_107 ;
int V_96 ;
if ( ! V_18 -> V_118 )
return 0 ;
if ( V_18 -> V_117 || V_18 -> V_3 )
return F_59 ( V_2 ) ;
if ( V_18 -> V_118 < ( V_102 * sizeof( T_1 ) ) )
return F_59 ( V_2 ) ;
F_31 ( V_2 -> V_48 , L_8 ,
V_18 -> V_54 , V_18 -> V_117 , V_18 -> V_118 ) ;
V_107 = V_18 -> V_107 ;
if ( ! F_61 ( V_107 ) )
return F_59 ( V_2 ) ;
if ( ! F_62 ( V_107 ) && ! F_63 ( V_107 ) )
return F_59 ( V_2 ) ;
V_51 = F_51 ( V_18 -> V_118 , V_107 -> V_51 ) ;
if ( F_62 ( V_107 ) ) {
if ( ! ( V_18 -> V_24 & F_12 ( V_121 ) ) ) {
V_122 = V_51 & ( V_124 - 1 ) ;
if ( ! V_122 )
V_122 = V_124 ;
V_51 -= V_122 ;
}
}
if ( ! F_64 ( V_2 -> V_48 , V_18 -> V_107 , 1 , V_119 ) ) {
F_47 ( V_2 -> V_48 , L_9 ) ;
return - V_111 ;
}
V_18 -> V_24 |= F_12 ( V_120 ) ;
V_18 -> V_118 -= V_51 ;
V_18 -> V_3 = V_51 ;
V_52 = ( V_18 -> V_24 & F_12 ( V_121 ) ) && ! V_18 -> V_118 ;
V_96 = F_39 ( V_2 , F_44 ( V_18 -> V_107 ) , V_51 , V_52 , 1 ) ;
if ( V_96 != - V_86 )
F_65 ( V_2 -> V_48 , V_18 -> V_107 , 1 , V_119 ) ;
return V_96 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_117 ;
F_52 ( V_18 ) ;
V_117 = V_18 -> V_117 ;
V_18 -> V_117 = 0 ;
return F_34 ( V_2 , V_18 -> V_80 , V_117 , 1 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
F_68 ( V_2 -> V_103 ) ;
if ( V_18 -> V_24 & F_12 ( V_120 ) ) {
F_65 ( V_2 -> V_48 , V_18 -> V_107 , 1 , V_119 ) ;
if ( V_18 -> V_107 -> V_51 == V_18 -> V_3 ) {
V_18 -> V_107 = F_54 ( V_18 -> V_107 ) ;
if ( V_18 -> V_107 )
V_18 -> V_3 = 0 ;
}
} else {
F_58 ( V_2 -> V_48 , V_18 -> V_90 , V_18 -> V_116 ,
V_119 ) ;
}
return 0 ;
}
static int F_69 ( struct V_14 * V_15 )
{
struct V_26 * V_27 = F_13 ( V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = NULL , * V_125 ;
F_70 ( & V_126 . V_127 ) ;
if ( ! V_29 -> V_2 ) {
F_71 (tmp, &sham.dev_list, list) {
V_2 = V_125 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_72 ( & V_126 . V_127 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_24 = 0 ;
F_31 ( V_2 -> V_48 , L_10 ,
F_73 ( V_27 ) ) ;
switch ( F_73 ( V_27 ) ) {
case V_40 :
V_18 -> V_24 |= V_39 ;
break;
case V_43 :
V_18 -> V_24 |= V_41 ;
break;
case V_45 :
V_18 -> V_24 |= V_44 ;
break;
case V_47 :
V_18 -> V_24 |= V_46 ;
break;
}
V_18 -> V_117 = 0 ;
V_18 -> V_54 = 0 ;
V_18 -> V_116 = V_128 ;
if ( V_29 -> V_24 & F_12 ( V_25 ) ) {
if ( ! F_17 ( V_129 , & V_2 -> V_24 ) ) {
struct V_30 * V_31 = V_29 -> V_32 ;
memcpy ( V_18 -> V_80 , V_31 -> V_67 , V_124 ) ;
V_18 -> V_117 = V_124 ;
}
V_18 -> V_24 |= F_12 ( V_25 ) ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_50 ;
F_31 ( V_2 -> V_48 , L_11 ,
V_18 -> V_118 , V_18 -> V_54 , ( V_18 -> V_24 & F_12 ( V_121 ) ) != 0 ) ;
if ( V_18 -> V_24 & F_12 ( V_85 ) )
V_50 = F_66 ( V_2 ) ;
else
V_50 = F_60 ( V_2 ) ;
F_31 ( V_2 -> V_48 , L_12 , V_50 , V_18 -> V_54 ) ;
return V_50 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_50 = 0 , V_130 = 1 ;
if ( V_18 -> V_117 <= V_104 )
V_130 = 0 ;
if ( V_130 )
V_50 = F_55 ( V_2 , V_18 , V_18 -> V_117 , 1 ) ;
else
V_50 = F_34 ( V_2 , V_18 -> V_80 , V_18 -> V_117 , 1 ) ;
V_18 -> V_117 = 0 ;
F_31 ( V_2 -> V_48 , L_13 , V_50 ) ;
return V_50 ;
}
static int F_76 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_77 ( V_15 -> V_32 . V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_131 = F_78 ( V_31 -> V_132 ) ;
int V_133 = F_79 ( V_31 -> V_132 ) ;
struct {
struct V_134 V_132 ;
char V_18 [ F_80 ( V_31 -> V_132 ) ] ;
} V_135 ;
V_135 . V_132 . V_27 = V_31 -> V_132 ;
V_135 . V_132 . V_24 = 0 ;
return F_81 ( & V_135 . V_132 ) ? :
F_82 ( & V_135 . V_132 , V_31 -> V_33 , V_131 ) ? :
F_83 ( & V_135 . V_132 , V_15 -> V_35 , V_133 , V_15 -> V_35 ) ;
}
static int F_84 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_50 = 0 ;
if ( V_18 -> V_54 ) {
F_16 ( V_15 ) ;
if ( ( V_18 -> V_24 & F_12 ( V_25 ) ) &&
! F_17 ( V_129 , & V_2 -> V_24 ) )
V_50 = F_76 ( V_15 ) ;
}
F_31 ( V_2 -> V_48 , L_14 , V_18 -> V_54 , V_18 -> V_117 ) ;
return V_50 ;
}
static void F_85 ( struct V_14 * V_15 , int V_50 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_50 ) {
V_2 -> V_22 -> V_136 ( V_15 , 1 ) ;
if ( F_17 ( V_84 , & V_2 -> V_24 ) )
V_50 = F_84 ( V_15 ) ;
} else {
V_18 -> V_24 |= F_12 ( V_137 ) ;
}
V_2 -> V_24 &= ~ ( F_12 ( V_138 ) | F_12 ( V_84 ) | F_12 ( V_85 ) |
F_12 ( V_88 ) | F_12 ( V_139 ) ) ;
F_86 ( V_2 -> V_48 ) ;
if ( V_15 -> V_32 . V_140 )
V_15 -> V_32 . V_140 ( & V_15 -> V_32 , V_50 ) ;
F_38 ( & V_2 -> V_89 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_141 * V_142 , * V_143 ;
struct V_17 * V_18 ;
unsigned long V_24 ;
int V_50 = 0 , V_96 = 0 ;
F_88 ( & V_2 -> V_127 , V_24 ) ;
if ( V_15 )
V_96 = F_89 ( & V_2 -> V_144 , V_15 ) ;
if ( F_17 ( V_138 , & V_2 -> V_24 ) ) {
F_90 ( & V_2 -> V_127 , V_24 ) ;
return V_96 ;
}
V_143 = F_91 ( & V_2 -> V_144 ) ;
V_142 = F_92 ( & V_2 -> V_144 ) ;
if ( V_142 )
F_22 ( V_138 , & V_2 -> V_24 ) ;
F_90 ( & V_2 -> V_127 , V_24 ) ;
if ( ! V_142 )
return V_96 ;
if ( V_143 )
V_143 -> V_140 ( V_143 , - V_86 ) ;
V_15 = F_93 ( V_142 ) ;
V_2 -> V_15 = V_15 ;
V_18 = F_9 ( V_15 ) ;
F_31 ( V_2 -> V_48 , L_15 ,
V_18 -> V_145 , V_15 -> V_146 ) ;
V_50 = F_20 ( V_2 ) ;
if ( V_50 )
goto V_147;
if ( V_18 -> V_54 )
V_2 -> V_22 -> V_136 ( V_15 , 0 ) ;
if ( V_18 -> V_145 == V_148 ) {
V_50 = F_74 ( V_2 ) ;
if ( V_50 != - V_86 && ( V_18 -> V_24 & F_12 ( V_121 ) ) )
V_50 = F_75 ( V_2 ) ;
} else if ( V_18 -> V_145 == V_149 ) {
V_50 = F_75 ( V_2 ) ;
}
V_147:
if ( V_50 != - V_86 )
F_85 ( V_15 , V_50 ) ;
F_31 ( V_2 -> V_48 , L_16 , V_50 ) ;
return V_96 ;
}
static int F_94 ( struct V_14 * V_15 , unsigned int V_145 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_28 * V_29 = F_77 ( V_15 -> V_32 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
V_18 -> V_145 = V_145 ;
return F_87 ( V_2 , V_15 ) ;
}
static int F_95 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
if ( ! V_15 -> V_146 )
return 0 ;
V_18 -> V_118 = V_15 -> V_146 ;
V_18 -> V_107 = V_15 -> V_150 ;
V_18 -> V_3 = 0 ;
if ( V_18 -> V_24 & F_12 ( V_121 ) ) {
if ( ( V_18 -> V_54 + V_18 -> V_117 + V_18 -> V_118 ) < 9 ) {
F_52 ( V_18 ) ;
return 0 ;
} else if ( V_18 -> V_117 + V_18 -> V_118 <= V_124 ) {
V_18 -> V_24 |= F_12 ( V_85 ) ;
}
} else if ( V_18 -> V_117 + V_18 -> V_118 < V_18 -> V_116 ) {
F_52 ( V_18 ) ;
return 0 ;
}
return F_94 ( V_15 , V_148 ) ;
}
static int F_96 ( struct V_151 * V_132 , T_1 V_24 ,
const T_3 * V_115 , unsigned int V_152 , T_3 * V_16 )
{
struct {
struct V_134 V_132 ;
char V_18 [ F_80 ( V_132 ) ] ;
} V_135 ;
V_135 . V_132 . V_27 = V_132 ;
V_135 . V_132 . V_24 = V_24 & V_153 ;
return F_97 ( & V_135 . V_132 , V_115 , V_152 , V_16 ) ;
}
static int F_98 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_77 ( V_15 -> V_32 . V_27 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
return F_96 ( V_29 -> V_154 , V_15 -> V_32 . V_24 ,
V_18 -> V_80 , V_18 -> V_117 , V_15 -> V_35 ) ;
}
static int F_99 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
V_18 -> V_24 |= F_12 ( V_121 ) ;
if ( V_18 -> V_24 & F_12 ( V_137 ) )
return 0 ;
if ( ( V_18 -> V_54 + V_18 -> V_117 ) < 9 )
return F_98 ( V_15 ) ;
else if ( V_18 -> V_117 )
return F_94 ( V_15 , V_149 ) ;
return F_84 ( V_15 ) ;
}
static int F_100 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_147 , V_155 ;
V_18 -> V_24 |= F_12 ( V_121 ) ;
V_147 = F_95 ( V_15 ) ;
if ( V_147 == - V_86 || V_147 == - V_156 )
return V_147 ;
V_155 = F_99 ( V_15 ) ;
return V_147 ? : V_155 ;
}
static int F_101 ( struct V_14 * V_15 )
{
return F_69 ( V_15 ) ? : F_100 ( V_15 ) ;
}
static int F_102 ( struct V_26 * V_27 , const T_3 * V_157 ,
unsigned int V_158 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_131 = F_78 ( V_31 -> V_132 ) ;
int V_133 = F_79 ( V_31 -> V_132 ) ;
struct V_1 * V_2 = NULL , * V_125 ;
int V_50 , V_21 ;
F_70 ( & V_126 . V_127 ) ;
if ( ! V_29 -> V_2 ) {
F_71 (tmp, &sham.dev_list, list) {
V_2 = V_125 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_72 ( & V_126 . V_127 ) ;
V_50 = F_103 ( V_29 -> V_154 , V_157 , V_158 ) ;
if ( V_50 )
return V_50 ;
if ( V_158 > V_131 ) {
V_50 = F_96 ( V_31 -> V_132 ,
F_104 ( V_31 -> V_132 ) ,
V_157 , V_158 , V_31 -> V_67 ) ;
if ( V_50 )
return V_50 ;
V_158 = V_133 ;
} else {
memcpy ( V_31 -> V_67 , V_157 , V_158 ) ;
}
memset ( V_31 -> V_67 + V_158 , 0 , V_131 - V_158 ) ;
if ( ! F_17 ( V_129 , & V_2 -> V_24 ) ) {
memcpy ( V_31 -> V_33 , V_31 -> V_67 , V_131 ) ;
for ( V_21 = 0 ; V_21 < V_131 ; V_21 ++ ) {
V_31 -> V_67 [ V_21 ] ^= 0x36 ;
V_31 -> V_33 [ V_21 ] ^= 0x5c ;
}
}
return V_50 ;
}
static int F_105 ( struct V_159 * V_27 , const char * V_160 )
{
struct V_28 * V_29 = F_77 ( V_27 ) ;
const char * V_161 = F_106 ( V_27 ) ;
V_29 -> V_154 = F_107 ( V_161 , 0 ,
V_162 ) ;
if ( F_108 ( V_29 -> V_154 ) ) {
F_41 ( L_17
L_18 , V_161 ) ;
return F_109 ( V_29 -> V_154 ) ;
}
F_110 ( F_111 ( V_27 ) ,
sizeof( struct V_17 ) + V_128 ) ;
if ( V_160 ) {
struct V_30 * V_31 = V_29 -> V_32 ;
V_29 -> V_24 |= F_12 ( V_25 ) ;
V_31 -> V_132 = F_107 ( V_160 , 0 ,
V_162 ) ;
if ( F_108 ( V_31 -> V_132 ) ) {
F_41 ( L_19
L_18 , V_160 ) ;
F_112 ( V_29 -> V_154 ) ;
return F_109 ( V_31 -> V_132 ) ;
}
}
return 0 ;
}
static int F_113 ( struct V_159 * V_27 )
{
return F_105 ( V_27 , NULL ) ;
}
static int F_114 ( struct V_159 * V_27 )
{
return F_105 ( V_27 , L_20 ) ;
}
static int F_115 ( struct V_159 * V_27 )
{
return F_105 ( V_27 , L_21 ) ;
}
static int F_116 ( struct V_159 * V_27 )
{
return F_105 ( V_27 , L_22 ) ;
}
static int F_117 ( struct V_159 * V_27 )
{
return F_105 ( V_27 , L_23 ) ;
}
static void F_118 ( struct V_159 * V_27 )
{
struct V_28 * V_29 = F_77 ( V_27 ) ;
F_112 ( V_29 -> V_154 ) ;
V_29 -> V_154 = NULL ;
if ( V_29 -> V_24 & F_12 ( V_25 ) ) {
struct V_30 * V_31 = V_29 -> V_32 ;
F_112 ( V_31 -> V_132 ) ;
}
}
static void F_119 ( unsigned long V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 ;
int V_50 = 0 ;
if ( ! F_17 ( V_138 , & V_2 -> V_24 ) ) {
F_87 ( V_2 , NULL ) ;
return;
}
if ( F_17 ( V_85 , & V_2 -> V_24 ) ) {
if ( F_120 ( V_139 , & V_2 -> V_24 ) )
goto V_163;
} else if ( F_17 ( V_88 , & V_2 -> V_24 ) ) {
if ( F_120 ( V_114 , & V_2 -> V_24 ) ) {
F_67 ( V_2 ) ;
if ( V_2 -> V_50 ) {
V_50 = V_2 -> V_50 ;
goto V_163;
}
}
if ( F_120 ( V_139 , & V_2 -> V_24 ) ) {
F_121 ( V_88 , & V_2 -> V_24 ) ;
V_50 = F_60 ( V_2 ) ;
if ( V_50 != - V_86 )
goto V_163;
}
}
return;
V_163:
F_31 ( V_2 -> V_48 , L_24 , V_50 ) ;
F_85 ( V_2 -> V_15 , V_50 ) ;
}
static T_5 F_122 ( struct V_1 * V_2 )
{
if ( ! F_17 ( V_138 , & V_2 -> V_24 ) ) {
F_123 ( V_2 -> V_48 , L_25 ) ;
} else {
F_22 ( V_139 , & V_2 -> V_24 ) ;
F_38 ( & V_2 -> V_89 ) ;
}
return V_164 ;
}
static T_5 F_124 ( int V_165 , void * V_166 )
{
struct V_1 * V_2 = V_166 ;
if ( F_125 ( F_17 ( V_84 , & V_2 -> V_24 ) ) )
F_5 ( V_2 , V_61 , 0 , V_60 ) ;
F_5 ( V_2 , V_61 , V_167 ,
V_167 ) ;
F_1 ( V_2 , V_61 ) ;
return F_122 ( V_2 ) ;
}
static T_5 F_126 ( int V_165 , void * V_166 )
{
struct V_1 * V_2 = V_166 ;
F_5 ( V_2 , F_26 ( V_2 ) , 0 , V_55 ) ;
return F_122 ( V_2 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_168 * V_48 , struct V_169 * V_170 )
{
struct V_171 * V_172 = V_48 -> V_173 ;
const struct V_174 * V_175 ;
int V_50 = 0 ;
V_175 = F_128 ( F_129 ( V_176 ) , V_48 ) ;
if ( ! V_175 ) {
F_47 ( V_48 , L_26 ) ;
V_50 = - V_111 ;
goto V_50;
}
V_50 = F_130 ( V_172 , 0 , V_170 ) ;
if ( V_50 < 0 ) {
F_47 ( V_48 , L_27 ) ;
V_50 = - V_111 ;
goto V_50;
}
V_2 -> V_165 = F_131 ( V_172 , 0 , NULL ) ;
if ( ! V_2 -> V_165 ) {
F_47 ( V_48 , L_28 ) ;
V_50 = - V_111 ;
goto V_50;
}
V_2 -> V_53 = - 1 ;
V_2 -> V_22 = V_175 -> V_115 ;
V_50:
return V_50 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_168 * V_48 , struct V_169 * V_170 )
{
return - V_111 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_177 * V_178 , struct V_169 * V_170 )
{
struct V_168 * V_48 = & V_178 -> V_48 ;
struct V_169 * V_179 ;
int V_50 = 0 ;
V_179 = F_133 ( V_178 , V_180 , 0 ) ;
if ( ! V_179 ) {
F_47 ( V_48 , L_29 ) ;
V_50 = - V_181 ;
goto V_50;
}
memcpy ( V_170 , V_179 , sizeof( * V_170 ) ) ;
V_2 -> V_165 = F_134 ( V_178 , 0 ) ;
if ( V_2 -> V_165 < 0 ) {
F_47 ( V_48 , L_30 ) ;
V_50 = V_2 -> V_165 ;
goto V_50;
}
V_179 = F_133 ( V_178 , V_182 , 0 ) ;
if ( ! V_179 ) {
F_47 ( V_48 , L_31 ) ;
V_50 = - V_181 ;
goto V_50;
}
V_2 -> V_53 = V_179 -> V_183 ;
V_2 -> V_22 = & V_184 ;
V_50:
return V_50 ;
}
static int F_135 ( struct V_177 * V_178 )
{
struct V_1 * V_2 ;
struct V_168 * V_48 = & V_178 -> V_48 ;
struct V_169 V_170 ;
T_6 V_7 ;
int V_50 , V_21 , V_185 ;
T_1 V_186 ;
V_2 = F_136 ( sizeof( struct V_1 ) , V_187 ) ;
if ( V_2 == NULL ) {
F_47 ( V_48 , L_32 ) ;
V_50 = - V_188 ;
goto V_189;
}
V_2 -> V_48 = V_48 ;
F_137 ( V_178 , V_2 ) ;
F_138 ( & V_2 -> V_190 ) ;
F_139 ( & V_2 -> V_127 ) ;
F_140 ( & V_2 -> V_89 , F_119 , ( unsigned long ) V_2 ) ;
F_141 ( & V_2 -> V_144 , V_191 ) ;
V_50 = ( V_48 -> V_173 ) ? F_127 ( V_2 , V_48 , & V_170 ) :
F_132 ( V_2 , V_178 , & V_170 ) ;
if ( V_50 )
goto V_192;
V_2 -> V_4 = F_142 ( V_48 , & V_170 ) ;
if ( ! V_2 -> V_4 ) {
F_47 ( V_48 , L_33 ) ;
V_50 = - V_188 ;
goto V_192;
}
V_2 -> V_98 = V_170 . V_183 ;
V_50 = F_143 ( V_2 -> V_165 , V_2 -> V_22 -> V_193 , V_194 ,
F_144 ( V_48 ) , V_2 ) ;
if ( V_50 ) {
F_47 ( V_48 , L_34 ) ;
goto V_192;
}
F_145 ( V_7 ) ;
F_146 ( V_195 , V_7 ) ;
V_2 -> V_103 = F_147 ( V_7 , V_196 ,
& V_2 -> V_53 , V_48 , L_35 ) ;
if ( ! V_2 -> V_103 ) {
F_47 ( V_48 , L_36 ,
V_2 -> V_53 ) ;
V_50 = - V_197 ;
goto V_198;
}
V_2 -> V_24 |= V_2 -> V_22 -> V_24 ;
F_148 ( V_48 ) ;
F_21 ( V_48 ) ;
V_186 = F_1 ( V_2 , F_149 ( V_2 ) ) ;
F_86 ( & V_178 -> V_48 ) ;
F_150 ( V_48 , L_37 ,
( V_186 & V_2 -> V_22 -> V_199 ) >> V_2 -> V_22 -> V_200 ,
( V_186 & V_2 -> V_22 -> V_201 ) >> V_2 -> V_22 -> V_202 ) ;
F_151 ( & V_126 . V_127 ) ;
F_152 ( & V_2 -> V_190 , & V_126 . V_203 ) ;
F_153 ( & V_126 . V_127 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_204 ; V_21 ++ ) {
for ( V_185 = 0 ; V_185 < V_2 -> V_22 -> V_205 [ V_21 ] . V_206 ; V_185 ++ ) {
V_50 = F_154 (
& V_2 -> V_22 -> V_205 [ V_21 ] . V_207 [ V_185 ] ) ;
if ( V_50 )
goto V_208;
V_2 -> V_22 -> V_205 [ V_21 ] . V_209 ++ ;
}
}
return 0 ;
V_208:
for ( V_21 = V_2 -> V_22 -> V_204 - 1 ; V_21 >= 0 ; V_21 -- )
for ( V_185 = V_2 -> V_22 -> V_205 [ V_21 ] . V_209 - 1 ; V_185 >= 0 ; V_185 -- )
F_155 (
& V_2 -> V_22 -> V_205 [ V_21 ] . V_207 [ V_185 ] ) ;
F_156 ( V_48 ) ;
F_157 ( V_2 -> V_103 ) ;
V_198:
F_158 ( V_2 -> V_165 , V_2 ) ;
V_192:
F_159 ( V_2 ) ;
V_2 = NULL ;
V_189:
F_47 ( V_48 , L_38 ) ;
return V_50 ;
}
static int F_160 ( struct V_177 * V_178 )
{
static struct V_1 * V_2 ;
int V_21 , V_185 ;
V_2 = F_161 ( V_178 ) ;
if ( ! V_2 )
return - V_181 ;
F_151 ( & V_126 . V_127 ) ;
F_162 ( & V_2 -> V_190 ) ;
F_153 ( & V_126 . V_127 ) ;
for ( V_21 = V_2 -> V_22 -> V_204 - 1 ; V_21 >= 0 ; V_21 -- )
for ( V_185 = V_2 -> V_22 -> V_205 [ V_21 ] . V_209 - 1 ; V_185 >= 0 ; V_185 -- )
F_155 (
& V_2 -> V_22 -> V_205 [ V_21 ] . V_207 [ V_185 ] ) ;
F_163 ( & V_2 -> V_89 ) ;
F_156 ( & V_178 -> V_48 ) ;
F_157 ( V_2 -> V_103 ) ;
F_158 ( V_2 -> V_165 , V_2 ) ;
F_159 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_164 ( struct V_168 * V_48 )
{
F_86 ( V_48 ) ;
return 0 ;
}
static int F_165 ( struct V_168 * V_48 )
{
F_21 ( V_48 ) ;
return 0 ;
}
static int T_7 F_166 ( void )
{
return F_167 ( & V_210 ) ;
}
static void T_8 F_168 ( void )
{
F_169 ( & V_210 ) ;
}
