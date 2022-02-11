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
F_15 ( V_2 , V_21 ) ) ;
else
F_3 ( V_2 , F_15 ( V_2 , V_21 ) ,
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
case V_48 :
V_36 = V_49 / sizeof( T_1 ) ;
break;
case V_50 :
V_36 = V_51 / sizeof( T_1 ) ;
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
int V_52 ;
V_52 = F_21 ( V_2 -> V_53 ) ;
if ( V_52 < 0 ) {
F_22 ( V_2 -> V_53 , L_1 , V_52 ) ;
return V_52 ;
}
if ( ! F_17 ( V_54 , & V_2 -> V_24 ) ) {
F_23 ( V_54 , & V_2 -> V_24 ) ;
V_2 -> V_52 = 0 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_55 ,
int V_56 , int V_57 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 = V_55 << 5 , V_7 ;
if ( F_25 ( V_18 -> V_58 ) )
F_3 ( V_2 , F_26 ( V_2 ) , V_18 -> V_58 ) ;
F_5 ( V_2 , F_27 ( V_2 ) ,
V_59 | ( V_57 ? V_60 : 0 ) ,
V_59 | V_60 ) ;
if ( ( V_18 -> V_24 & V_38 ) == V_41 )
V_8 |= V_61 ;
if ( ! V_18 -> V_58 )
V_8 |= V_62 ;
if ( V_56 )
V_8 |= V_63 ;
V_7 = V_62 | V_63 |
V_61 | V_64 ;
F_5 ( V_2 , V_65 , V_8 , V_7 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_55 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_65 , V_66 ) ;
}
static int F_30 ( struct V_17 * V_18 )
{
int V_36 ;
switch ( V_18 -> V_24 & V_38 ) {
case V_39 :
case V_41 :
V_36 = V_67 ;
break;
case V_44 :
case V_46 :
V_36 = V_68 ;
break;
case V_48 :
case V_50 :
V_36 = V_69 ;
break;
default:
V_36 = 0 ;
}
return V_36 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , int V_70 )
{
for (; V_70 -- ; V_5 ++ , V_3 += 4 )
F_3 ( V_2 , V_3 , * V_5 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_55 ,
int V_56 , int V_57 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 , V_7 ;
V_8 = ( V_18 -> V_24 & V_38 ) >> ( V_71 ) ;
if ( ! V_18 -> V_58 ) {
struct V_26 * V_27 = F_13 ( V_2 -> V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_72 , V_73 ;
V_8 |= V_74 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) ) {
V_72 = F_30 ( V_18 ) ;
V_73 = V_72 / ( 2 * sizeof( T_1 ) ) ;
V_8 |= V_75 ;
F_31 ( V_2 , F_15 ( V_2 , 0 ) ,
( T_1 * ) V_31 -> V_76 , V_73 ) ;
F_31 ( V_2 , F_10 ( V_2 , 0 ) ,
( T_1 * ) V_31 -> V_76 + V_73 , V_73 ) ;
V_18 -> V_58 += V_72 ;
}
}
if ( V_56 ) {
V_8 |= V_77 ;
if ( V_18 -> V_24 & F_12 ( V_25 ) )
V_8 |= V_78 ;
}
V_7 = V_74 | V_77 |
V_79 | V_78 |
V_75 ;
F_33 ( V_2 -> V_53 , L_2 , V_8 , V_18 -> V_24 ) ;
F_5 ( V_2 , F_34 ( V_2 ) , V_8 , V_7 ) ;
F_3 ( V_2 , V_80 , V_81 ) ;
F_5 ( V_2 , F_27 ( V_2 ) ,
V_59 |
( V_57 ? V_60 : 0 ) ,
V_59 | V_60 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_55 )
{
F_3 ( V_2 , F_36 ( V_2 ) , V_55 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_82 ,
V_83 ) ;
}
static int F_38 ( struct V_1 * V_2 , const T_3 * V_84 ,
T_2 V_55 , int V_56 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_70 , V_85 , V_86 , V_3 = 0 ;
const T_1 * V_87 = ( const T_1 * ) V_84 ;
F_33 ( V_2 -> V_53 , L_3 ,
V_18 -> V_58 , V_55 , V_56 ) ;
V_2 -> V_22 -> V_88 ( V_2 , V_55 , V_56 , 0 ) ;
V_2 -> V_22 -> V_89 ( V_2 , V_55 ) ;
V_18 -> V_58 += V_55 ;
if ( V_56 )
F_23 ( V_90 , & V_2 -> V_24 ) ;
F_23 ( V_91 , & V_2 -> V_24 ) ;
V_85 = F_39 ( V_55 , sizeof( T_1 ) ) ;
V_86 = F_30 ( V_18 ) / sizeof( T_1 ) ;
while ( V_85 ) {
if ( V_2 -> V_22 -> V_92 ( V_2 ) )
return - V_13 ;
for ( V_70 = 0 ; V_70 < F_40 ( V_85 , V_86 ) ; V_70 ++ , V_3 ++ )
F_3 ( V_2 , F_41 ( V_2 , V_70 ) ,
V_87 [ V_3 ] ) ;
V_85 -= F_40 ( V_85 , V_86 ) ;
}
return - V_93 ;
}
static void F_42 ( void * V_94 )
{
struct V_1 * V_2 = V_94 ;
F_23 ( V_95 , & V_2 -> V_24 ) ;
F_43 ( & V_2 -> V_96 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_4 V_97 ,
T_2 V_55 , int V_56 , int V_98 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
struct V_99 * V_100 ;
struct V_101 V_102 ;
int V_85 , V_103 , V_104 = F_30 ( V_18 ) ;
F_33 ( V_2 -> V_53 , L_4 ,
V_18 -> V_58 , V_55 , V_56 ) ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_105 = V_2 -> V_106 + F_41 ( V_2 , 0 ) ;
V_102 . V_107 = V_108 ;
V_102 . V_109 = V_104 / V_108 ;
V_103 = F_45 ( V_2 -> V_110 , & V_102 ) ;
if ( V_103 ) {
F_46 ( L_5 , V_103 ) ;
return V_103 ;
}
V_85 = F_39 ( V_55 , V_104 ) * V_104 ;
if ( V_98 ) {
F_47 ( & V_18 -> V_111 , 1 ) ;
F_48 ( & V_18 -> V_111 , F_49 ( V_18 -> V_112 ) ) ;
V_18 -> V_111 . V_3 = V_18 -> V_112 -> V_3 ;
F_50 ( & V_18 -> V_111 ) = V_85 ;
F_51 ( & V_18 -> V_111 ) = F_51 ( V_18 -> V_112 ) ;
V_100 = F_52 ( V_2 -> V_110 , & V_18 -> V_111 , 1 ,
V_113 , V_114 | V_115 ) ;
} else {
V_100 = F_53 ( V_2 -> V_110 , V_97 , V_85 ,
V_113 , V_114 | V_115 ) ;
}
if ( ! V_100 ) {
F_22 ( V_2 -> V_53 , L_6 ) ;
return - V_116 ;
}
V_100 -> V_117 = F_42 ;
V_100 -> V_118 = V_2 ;
V_2 -> V_22 -> V_88 ( V_2 , V_55 , V_56 , 1 ) ;
V_18 -> V_58 += V_55 ;
if ( V_56 )
F_23 ( V_90 , & V_2 -> V_24 ) ;
F_23 ( V_119 , & V_2 -> V_24 ) ;
F_54 ( V_100 ) ;
F_55 ( V_2 -> V_110 ) ;
V_2 -> V_22 -> V_89 ( V_2 , V_55 ) ;
return - V_93 ;
}
static T_2 F_56 ( struct V_17 * V_18 ,
const T_3 * V_120 , T_2 V_55 )
{
T_2 V_70 = F_40 ( V_55 , V_18 -> V_121 - V_18 -> V_122 ) ;
V_70 = F_40 ( V_70 , V_18 -> V_123 ) ;
if ( V_70 <= 0 )
return 0 ;
memcpy ( V_18 -> V_87 + V_18 -> V_122 , V_120 , V_70 ) ;
V_18 -> V_122 += V_70 ;
return V_70 ;
}
static T_2 F_57 ( struct V_17 * V_18 )
{
T_2 V_70 ;
const T_3 * V_124 ;
while ( V_18 -> V_112 ) {
V_124 = F_58 ( F_49 ( V_18 -> V_112 ) ) ;
V_124 += V_18 -> V_112 -> V_3 ;
V_70 = F_56 ( V_18 ,
V_124 + V_18 -> V_3 ,
V_18 -> V_112 -> V_55 - V_18 -> V_3 ) ;
F_59 ( ( void * ) V_124 ) ;
if ( ! V_70 )
break;
V_18 -> V_3 += V_70 ;
V_18 -> V_123 -= V_70 ;
if ( V_18 -> V_3 == V_18 -> V_112 -> V_55 ) {
V_18 -> V_112 = F_60 ( V_18 -> V_112 ) ;
if ( V_18 -> V_112 )
V_18 -> V_3 = 0 ;
else
V_18 -> V_123 = 0 ;
}
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_2 V_55 , int V_56 )
{
int V_103 ;
V_18 -> V_97 = F_62 ( V_2 -> V_53 , V_18 -> V_87 , V_18 -> V_121 ,
V_125 ) ;
if ( F_63 ( V_2 -> V_53 , V_18 -> V_97 ) ) {
F_22 ( V_2 -> V_53 , L_7 , V_18 -> V_121 ) ;
return - V_116 ;
}
V_18 -> V_24 &= ~ F_12 ( V_126 ) ;
V_103 = F_44 ( V_2 , V_18 -> V_97 , V_55 , V_56 , 0 ) ;
if ( V_103 != - V_93 )
F_64 ( V_2 -> V_53 , V_18 -> V_97 , V_18 -> V_121 ,
V_125 ) ;
return V_103 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_56 ;
T_2 V_70 ;
F_57 ( V_18 ) ;
V_56 = ( V_18 -> V_24 & F_12 ( V_127 ) ) && ! V_18 -> V_123 ;
F_33 ( V_2 -> V_53 , L_8 ,
V_18 -> V_122 , V_18 -> V_58 , V_56 ) ;
if ( V_56 || ( V_18 -> V_122 == V_18 -> V_121 && V_18 -> V_123 ) ) {
V_70 = V_18 -> V_122 ;
V_18 -> V_122 = 0 ;
return F_61 ( V_2 , V_18 , V_70 , V_56 ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_55 , V_56 , V_128 ;
struct V_129 * V_112 ;
int V_103 , V_72 ;
if ( ! V_18 -> V_123 )
return 0 ;
if ( V_18 -> V_122 || V_18 -> V_3 )
return F_65 ( V_2 ) ;
if ( V_18 -> V_123 < F_30 ( V_18 ) )
return F_65 ( V_2 ) ;
F_33 ( V_2 -> V_53 , L_9 ,
V_18 -> V_58 , V_18 -> V_122 , V_18 -> V_123 ) ;
V_112 = V_18 -> V_112 ;
V_72 = F_30 ( V_18 ) ;
if ( ! F_67 ( V_112 ) )
return F_65 ( V_2 ) ;
if ( ! F_68 ( V_112 ) && ! F_69 ( V_112 , V_72 ) )
return F_65 ( V_2 ) ;
V_55 = F_40 ( V_18 -> V_123 , V_112 -> V_55 ) ;
if ( F_68 ( V_112 ) ) {
if ( ! ( V_18 -> V_24 & F_12 ( V_127 ) ) ) {
V_128 = V_55 & ( V_72 - 1 ) ;
if ( ! V_128 )
V_128 = V_72 ;
V_55 -= V_128 ;
}
}
if ( ! F_70 ( V_2 -> V_53 , V_18 -> V_112 , 1 , V_125 ) ) {
F_22 ( V_2 -> V_53 , L_10 ) ;
return - V_116 ;
}
V_18 -> V_24 |= F_12 ( V_126 ) ;
V_18 -> V_123 -= V_55 ;
V_18 -> V_3 = V_55 ;
V_56 = ( V_18 -> V_24 & F_12 ( V_127 ) ) && ! V_18 -> V_123 ;
V_103 = F_44 ( V_2 , F_51 ( V_18 -> V_112 ) , V_55 , V_56 , 1 ) ;
if ( V_103 != - V_93 )
F_71 ( V_2 -> V_53 , V_18 -> V_112 , 1 , V_125 ) ;
return V_103 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_122 , V_56 ;
if ( ! V_18 -> V_123 )
return 0 ;
F_57 ( V_18 ) ;
V_56 = ( V_18 -> V_24 & F_12 ( V_127 ) ) && ! V_18 -> V_123 ;
F_33 ( V_2 -> V_53 , L_11 ,
V_18 -> V_122 , V_18 -> V_58 , V_56 ) ;
if ( V_56 || ( V_18 -> V_122 == V_18 -> V_121 && V_18 -> V_123 ) ) {
V_122 = V_18 -> V_122 ;
V_18 -> V_122 = 0 ;
return F_38 ( V_2 , V_18 -> V_87 , V_122 , V_56 ) ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
if ( V_18 -> V_24 & F_12 ( V_126 ) ) {
F_71 ( V_2 -> V_53 , V_18 -> V_112 , 1 , V_125 ) ;
if ( V_18 -> V_112 -> V_55 == V_18 -> V_3 ) {
V_18 -> V_112 = F_60 ( V_18 -> V_112 ) ;
if ( V_18 -> V_112 )
V_18 -> V_3 = 0 ;
}
} else {
F_64 ( V_2 -> V_53 , V_18 -> V_97 , V_18 -> V_121 ,
V_125 ) ;
}
return 0 ;
}
static int F_74 ( struct V_14 * V_15 )
{
struct V_26 * V_27 = F_13 ( V_15 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = NULL , * V_130 ;
int V_72 = 0 ;
F_75 ( & V_131 . V_132 ) ;
if ( ! V_29 -> V_2 ) {
F_76 (tmp, &sham.dev_list, list) {
V_2 = V_130 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_77 ( & V_131 . V_132 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_24 = 0 ;
F_33 ( V_2 -> V_53 , L_12 ,
F_78 ( V_27 ) ) ;
switch ( F_78 ( V_27 ) ) {
case V_40 :
V_18 -> V_24 |= V_39 ;
V_72 = V_67 ;
break;
case V_43 :
V_18 -> V_24 |= V_41 ;
V_72 = V_67 ;
break;
case V_45 :
V_18 -> V_24 |= V_44 ;
V_72 = V_133 ;
break;
case V_47 :
V_18 -> V_24 |= V_46 ;
V_72 = V_68 ;
break;
case V_49 :
V_18 -> V_24 |= V_48 ;
V_72 = V_134 ;
break;
case V_51 :
V_18 -> V_24 |= V_50 ;
V_72 = V_69 ;
break;
}
V_18 -> V_122 = 0 ;
V_18 -> V_58 = 0 ;
V_18 -> V_121 = V_135 ;
if ( V_29 -> V_24 & F_12 ( V_25 ) ) {
if ( ! F_17 ( V_136 , & V_2 -> V_24 ) ) {
struct V_30 * V_31 = V_29 -> V_32 ;
memcpy ( V_18 -> V_87 , V_31 -> V_76 , V_72 ) ;
V_18 -> V_122 = V_72 ;
}
V_18 -> V_24 |= F_12 ( V_25 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_52 ;
F_33 ( V_2 -> V_53 , L_13 ,
V_18 -> V_123 , V_18 -> V_58 , ( V_18 -> V_24 & F_12 ( V_127 ) ) != 0 ) ;
if ( V_18 -> V_24 & F_12 ( V_91 ) )
V_52 = F_72 ( V_2 ) ;
else
V_52 = F_66 ( V_2 ) ;
F_33 ( V_2 -> V_53 , L_14 , V_52 , V_18 -> V_58 ) ;
return V_52 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_52 = 0 , V_137 = 1 ;
if ( ( V_18 -> V_122 <= F_30 ( V_18 ) ) || V_2 -> V_138 )
V_137 = 0 ;
if ( V_137 )
V_52 = F_61 ( V_2 , V_18 , V_18 -> V_122 , 1 ) ;
else
V_52 = F_38 ( V_2 , V_18 -> V_87 , V_18 -> V_122 , 1 ) ;
V_18 -> V_122 = 0 ;
F_33 ( V_2 -> V_53 , L_15 , V_52 ) ;
return V_52 ;
}
static int F_81 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_82 ( V_15 -> V_32 . V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_72 = F_83 ( V_31 -> V_139 ) ;
int V_140 = F_84 ( V_31 -> V_139 ) ;
F_85 ( V_139 , V_31 -> V_139 ) ;
V_139 -> V_27 = V_31 -> V_139 ;
V_139 -> V_24 = 0 ;
return F_86 ( V_139 ) ? :
F_87 ( V_139 , V_31 -> V_33 , V_72 ) ? :
F_88 ( V_139 , V_15 -> V_35 , V_140 , V_15 -> V_35 ) ;
}
static int F_89 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_52 = 0 ;
if ( V_18 -> V_58 ) {
F_16 ( V_15 ) ;
if ( ( V_18 -> V_24 & F_12 ( V_25 ) ) &&
! F_17 ( V_136 , & V_2 -> V_24 ) )
V_52 = F_81 ( V_15 ) ;
}
F_33 ( V_2 -> V_53 , L_16 , V_18 -> V_58 , V_18 -> V_122 ) ;
return V_52 ;
}
static void F_90 ( struct V_14 * V_15 , int V_52 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_52 ) {
V_2 -> V_22 -> V_141 ( V_15 , 1 ) ;
if ( F_17 ( V_90 , & V_2 -> V_24 ) )
V_52 = F_89 ( V_15 ) ;
} else {
V_18 -> V_24 |= F_12 ( V_142 ) ;
}
V_2 -> V_24 &= ~ ( F_12 ( V_143 ) | F_12 ( V_90 ) | F_12 ( V_91 ) |
F_12 ( V_95 ) | F_12 ( V_144 ) ) ;
F_91 ( V_2 -> V_53 ) ;
F_92 ( V_2 -> V_53 ) ;
if ( V_15 -> V_32 . V_145 )
V_15 -> V_32 . V_145 ( & V_15 -> V_32 , V_52 ) ;
F_43 ( & V_2 -> V_96 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_146 * V_147 , * V_148 ;
struct V_17 * V_18 ;
unsigned long V_24 ;
int V_52 = 0 , V_103 = 0 ;
F_94 ( & V_2 -> V_132 , V_24 ) ;
if ( V_15 )
V_103 = F_95 ( & V_2 -> V_149 , V_15 ) ;
if ( F_17 ( V_143 , & V_2 -> V_24 ) ) {
F_96 ( & V_2 -> V_132 , V_24 ) ;
return V_103 ;
}
V_148 = F_97 ( & V_2 -> V_149 ) ;
V_147 = F_98 ( & V_2 -> V_149 ) ;
if ( V_147 )
F_23 ( V_143 , & V_2 -> V_24 ) ;
F_96 ( & V_2 -> V_132 , V_24 ) ;
if ( ! V_147 )
return V_103 ;
if ( V_148 )
V_148 -> V_145 ( V_148 , - V_93 ) ;
V_15 = F_99 ( V_147 ) ;
V_2 -> V_15 = V_15 ;
V_18 = F_9 ( V_15 ) ;
F_33 ( V_2 -> V_53 , L_17 ,
V_18 -> V_150 , V_15 -> V_151 ) ;
V_52 = F_20 ( V_2 ) ;
if ( V_52 )
goto V_152;
if ( V_18 -> V_58 )
V_2 -> V_22 -> V_141 ( V_15 , 0 ) ;
if ( V_18 -> V_150 == V_153 ) {
V_52 = F_79 ( V_2 ) ;
if ( V_52 != - V_93 && ( V_18 -> V_24 & F_12 ( V_127 ) ) )
V_52 = F_80 ( V_2 ) ;
} else if ( V_18 -> V_150 == V_154 ) {
V_52 = F_80 ( V_2 ) ;
}
V_152:
if ( V_52 != - V_93 )
F_90 ( V_15 , V_52 ) ;
F_33 ( V_2 -> V_53 , L_18 , V_52 ) ;
return V_103 ;
}
static int F_100 ( struct V_14 * V_15 , unsigned int V_150 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_28 * V_29 = F_82 ( V_15 -> V_32 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
V_18 -> V_150 = V_150 ;
return F_93 ( V_2 , V_15 ) ;
}
static int F_101 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_72 = F_30 ( V_18 ) ;
if ( ! V_15 -> V_151 )
return 0 ;
V_18 -> V_123 = V_15 -> V_151 ;
V_18 -> V_112 = V_15 -> V_155 ;
V_18 -> V_3 = 0 ;
if ( V_18 -> V_24 & F_12 ( V_127 ) ) {
if ( ( V_18 -> V_58 + V_18 -> V_122 + V_18 -> V_123 ) < 240 ) {
F_57 ( V_18 ) ;
return 0 ;
} else if ( ( V_18 -> V_122 + V_18 -> V_123 <= V_72 ) ||
V_2 -> V_138 ) {
V_18 -> V_24 |= F_12 ( V_91 ) ;
}
} else if ( V_18 -> V_122 + V_18 -> V_123 < V_18 -> V_121 ) {
F_57 ( V_18 ) ;
return 0 ;
}
if ( V_2 -> V_138 )
V_18 -> V_24 |= F_12 ( V_91 ) ;
return F_100 ( V_15 , V_153 ) ;
}
static int F_102 ( struct V_156 * V_27 , T_1 V_24 ,
const T_3 * V_120 , unsigned int V_157 , T_3 * V_16 )
{
F_85 ( V_139 , V_27 ) ;
V_139 -> V_27 = V_27 ;
V_139 -> V_24 = V_24 & V_158 ;
return F_103 ( V_139 , V_120 , V_157 , V_16 ) ;
}
static int F_104 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_82 ( V_15 -> V_32 . V_27 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
return F_102 ( V_29 -> V_159 , V_15 -> V_32 . V_24 ,
V_18 -> V_87 , V_18 -> V_122 , V_15 -> V_35 ) ;
}
static int F_105 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
V_18 -> V_24 |= F_12 ( V_127 ) ;
if ( V_18 -> V_24 & F_12 ( V_142 ) )
return 0 ;
if ( ( V_18 -> V_58 + V_18 -> V_122 ) < 240 )
return F_104 ( V_15 ) ;
else if ( V_18 -> V_122 )
return F_100 ( V_15 , V_154 ) ;
return F_89 ( V_15 ) ;
}
static int F_106 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_152 , V_160 ;
V_18 -> V_24 |= F_12 ( V_127 ) ;
V_152 = F_101 ( V_15 ) ;
if ( V_152 == - V_93 || V_152 == - V_161 )
return V_152 ;
V_160 = F_105 ( V_15 ) ;
return V_152 ? : V_160 ;
}
static int F_107 ( struct V_14 * V_15 )
{
return F_74 ( V_15 ) ? : F_106 ( V_15 ) ;
}
static int F_108 ( struct V_26 * V_27 , const T_3 * V_162 ,
unsigned int V_163 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_30 * V_31 = V_29 -> V_32 ;
int V_72 = F_83 ( V_31 -> V_139 ) ;
int V_140 = F_84 ( V_31 -> V_139 ) ;
struct V_1 * V_2 = NULL , * V_130 ;
int V_52 , V_21 ;
F_75 ( & V_131 . V_132 ) ;
if ( ! V_29 -> V_2 ) {
F_76 (tmp, &sham.dev_list, list) {
V_2 = V_130 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_77 ( & V_131 . V_132 ) ;
V_52 = F_109 ( V_29 -> V_159 , V_162 , V_163 ) ;
if ( V_52 )
return V_52 ;
if ( V_163 > V_72 ) {
V_52 = F_102 ( V_31 -> V_139 ,
F_110 ( V_31 -> V_139 ) ,
V_162 , V_163 , V_31 -> V_76 ) ;
if ( V_52 )
return V_52 ;
V_163 = V_140 ;
} else {
memcpy ( V_31 -> V_76 , V_162 , V_163 ) ;
}
memset ( V_31 -> V_76 + V_163 , 0 , V_72 - V_163 ) ;
if ( ! F_17 ( V_136 , & V_2 -> V_24 ) ) {
memcpy ( V_31 -> V_33 , V_31 -> V_76 , V_72 ) ;
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ ) {
V_31 -> V_76 [ V_21 ] ^= 0x36 ;
V_31 -> V_33 [ V_21 ] ^= 0x5c ;
}
}
return V_52 ;
}
static int F_111 ( struct V_164 * V_27 , const char * V_165 )
{
struct V_28 * V_29 = F_82 ( V_27 ) ;
const char * V_166 = F_112 ( V_27 ) ;
V_29 -> V_159 = F_113 ( V_166 , 0 ,
V_167 ) ;
if ( F_114 ( V_29 -> V_159 ) ) {
F_46 ( L_19
L_20 , V_166 ) ;
return F_115 ( V_29 -> V_159 ) ;
}
F_116 ( F_117 ( V_27 ) ,
sizeof( struct V_17 ) + V_135 ) ;
if ( V_165 ) {
struct V_30 * V_31 = V_29 -> V_32 ;
V_29 -> V_24 |= F_12 ( V_25 ) ;
V_31 -> V_139 = F_113 ( V_165 , 0 ,
V_167 ) ;
if ( F_114 ( V_31 -> V_139 ) ) {
F_46 ( L_21
L_20 , V_165 ) ;
F_118 ( V_29 -> V_159 ) ;
return F_115 ( V_31 -> V_139 ) ;
}
}
return 0 ;
}
static int F_119 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , NULL ) ;
}
static int F_120 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , L_22 ) ;
}
static int F_121 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , L_23 ) ;
}
static int F_122 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , L_24 ) ;
}
static int F_123 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , L_25 ) ;
}
static int F_124 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , L_26 ) ;
}
static int F_125 ( struct V_164 * V_27 )
{
return F_111 ( V_27 , L_27 ) ;
}
static void F_126 ( struct V_164 * V_27 )
{
struct V_28 * V_29 = F_82 ( V_27 ) ;
F_118 ( V_29 -> V_159 ) ;
V_29 -> V_159 = NULL ;
if ( V_29 -> V_24 & F_12 ( V_25 ) ) {
struct V_30 * V_31 = V_29 -> V_32 ;
F_118 ( V_31 -> V_139 ) ;
}
}
static void F_127 ( unsigned long V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
int V_52 = 0 ;
if ( ! F_17 ( V_143 , & V_2 -> V_24 ) ) {
F_93 ( V_2 , NULL ) ;
return;
}
if ( F_17 ( V_91 , & V_2 -> V_24 ) ) {
if ( F_128 ( V_144 , & V_2 -> V_24 ) ) {
V_52 = F_72 ( V_2 ) ;
if ( V_52 != - V_93 )
goto V_168;
}
} else if ( F_17 ( V_95 , & V_2 -> V_24 ) ) {
if ( F_128 ( V_119 , & V_2 -> V_24 ) ) {
F_73 ( V_2 ) ;
if ( V_2 -> V_52 ) {
V_52 = V_2 -> V_52 ;
goto V_168;
}
}
if ( F_128 ( V_144 , & V_2 -> V_24 ) ) {
F_129 ( V_95 , & V_2 -> V_24 ) ;
V_52 = F_66 ( V_2 ) ;
if ( V_52 != - V_93 )
goto V_168;
}
}
return;
V_168:
F_33 ( V_2 -> V_53 , L_28 , V_52 ) ;
F_90 ( V_2 -> V_15 , V_52 ) ;
}
static T_5 F_130 ( struct V_1 * V_2 )
{
if ( ! F_17 ( V_143 , & V_2 -> V_24 ) ) {
F_131 ( V_2 -> V_53 , L_29 ) ;
} else {
F_23 ( V_144 , & V_2 -> V_24 ) ;
F_43 ( & V_2 -> V_96 ) ;
}
return V_169 ;
}
static T_5 F_132 ( int V_170 , void * V_171 )
{
struct V_1 * V_2 = V_171 ;
if ( F_133 ( F_17 ( V_90 , & V_2 -> V_24 ) ) )
F_5 ( V_2 , V_65 , 0 , V_64 ) ;
F_5 ( V_2 , V_65 , V_172 ,
V_172 ) ;
F_1 ( V_2 , V_65 ) ;
return F_130 ( V_2 ) ;
}
static T_5 F_134 ( int V_170 , void * V_171 )
{
struct V_1 * V_2 = V_171 ;
F_5 ( V_2 , F_27 ( V_2 ) , 0 , V_59 ) ;
return F_130 ( V_2 ) ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_173 * V_53 , struct V_174 * V_175 )
{
struct V_176 * V_177 = V_53 -> V_178 ;
const struct V_179 * V_180 ;
int V_52 = 0 ;
V_180 = F_136 ( F_137 ( V_181 ) , V_53 ) ;
if ( ! V_180 ) {
F_22 ( V_53 , L_30 ) ;
V_52 = - V_116 ;
goto V_52;
}
V_52 = F_138 ( V_177 , 0 , V_175 ) ;
if ( V_52 < 0 ) {
F_22 ( V_53 , L_31 ) ;
V_52 = - V_116 ;
goto V_52;
}
V_2 -> V_170 = F_139 ( V_177 , 0 ) ;
if ( ! V_2 -> V_170 ) {
F_22 ( V_53 , L_32 ) ;
V_52 = - V_116 ;
goto V_52;
}
V_2 -> V_22 = V_180 -> V_120 ;
V_52:
return V_52 ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_173 * V_53 , struct V_174 * V_175 )
{
return - V_116 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_182 * V_183 , struct V_174 * V_175 )
{
struct V_173 * V_53 = & V_183 -> V_53 ;
struct V_174 * V_184 ;
int V_52 = 0 ;
V_184 = F_141 ( V_183 , V_185 , 0 ) ;
if ( ! V_184 ) {
F_22 ( V_53 , L_33 ) ;
V_52 = - V_186 ;
goto V_52;
}
memcpy ( V_175 , V_184 , sizeof( * V_175 ) ) ;
V_2 -> V_170 = F_142 ( V_183 , 0 ) ;
if ( V_2 -> V_170 < 0 ) {
F_22 ( V_53 , L_34 ) ;
V_52 = V_2 -> V_170 ;
goto V_52;
}
V_2 -> V_22 = & V_187 ;
V_52:
return V_52 ;
}
static int F_143 ( struct V_182 * V_183 )
{
struct V_1 * V_2 ;
struct V_173 * V_53 = & V_183 -> V_53 ;
struct V_174 V_175 ;
T_6 V_7 ;
int V_52 , V_21 , V_188 ;
T_1 V_189 ;
V_2 = F_144 ( V_53 , sizeof( struct V_1 ) , V_190 ) ;
if ( V_2 == NULL ) {
F_22 ( V_53 , L_35 ) ;
V_52 = - V_191 ;
goto V_192;
}
V_2 -> V_53 = V_53 ;
F_145 ( V_183 , V_2 ) ;
F_146 ( & V_2 -> V_193 ) ;
F_147 ( & V_2 -> V_132 ) ;
F_148 ( & V_2 -> V_96 , F_127 , ( unsigned long ) V_2 ) ;
F_149 ( & V_2 -> V_149 , V_194 ) ;
V_52 = ( V_53 -> V_178 ) ? F_135 ( V_2 , V_53 , & V_175 ) :
F_140 ( V_2 , V_183 , & V_175 ) ;
if ( V_52 )
goto V_192;
V_2 -> V_4 = F_150 ( V_53 , & V_175 ) ;
if ( F_114 ( V_2 -> V_4 ) ) {
V_52 = F_115 ( V_2 -> V_4 ) ;
goto V_192;
}
V_2 -> V_106 = V_175 . V_195 ;
V_52 = F_151 ( V_53 , V_2 -> V_170 , V_2 -> V_22 -> V_196 ,
V_197 , F_152 ( V_53 ) , V_2 ) ;
if ( V_52 ) {
F_22 ( V_53 , L_36 ,
V_2 -> V_170 , V_52 ) ;
goto V_192;
}
F_153 ( V_7 ) ;
F_154 ( V_198 , V_7 ) ;
V_2 -> V_110 = F_155 ( V_53 , L_37 ) ;
if ( F_114 ( V_2 -> V_110 ) ) {
V_52 = F_115 ( V_2 -> V_110 ) ;
if ( V_52 == - V_199 )
goto V_192;
V_2 -> V_138 = 1 ;
F_33 ( V_53 , L_38 ) ;
}
V_2 -> V_24 |= V_2 -> V_22 -> V_24 ;
F_156 ( V_53 ) ;
F_157 ( V_53 , V_200 ) ;
F_158 ( V_53 ) ;
F_159 ( V_53 ) ;
V_52 = F_21 ( V_53 ) ;
if ( V_52 < 0 ) {
F_22 ( V_53 , L_1 , V_52 ) ;
goto V_201;
}
V_189 = F_1 ( V_2 , F_160 ( V_2 ) ) ;
F_161 ( & V_183 -> V_53 ) ;
F_162 ( V_53 , L_39 ,
( V_189 & V_2 -> V_22 -> V_202 ) >> V_2 -> V_22 -> V_203 ,
( V_189 & V_2 -> V_22 -> V_204 ) >> V_2 -> V_22 -> V_205 ) ;
F_163 ( & V_131 . V_132 ) ;
F_164 ( & V_2 -> V_193 , & V_131 . V_206 ) ;
F_165 ( & V_131 . V_132 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 -> V_207 ; V_21 ++ ) {
for ( V_188 = 0 ; V_188 < V_2 -> V_22 -> V_208 [ V_21 ] . V_209 ; V_188 ++ ) {
V_52 = F_166 (
& V_2 -> V_22 -> V_208 [ V_21 ] . V_210 [ V_188 ] ) ;
if ( V_52 )
goto V_211;
V_2 -> V_22 -> V_208 [ V_21 ] . V_212 ++ ;
}
}
return 0 ;
V_211:
for ( V_21 = V_2 -> V_22 -> V_207 - 1 ; V_21 >= 0 ; V_21 -- )
for ( V_188 = V_2 -> V_22 -> V_208 [ V_21 ] . V_212 - 1 ; V_188 >= 0 ; V_188 -- )
F_167 (
& V_2 -> V_22 -> V_208 [ V_21 ] . V_210 [ V_188 ] ) ;
V_201:
F_168 ( V_53 ) ;
if ( ! V_2 -> V_138 )
F_169 ( V_2 -> V_110 ) ;
V_192:
F_22 ( V_53 , L_40 ) ;
return V_52 ;
}
static int F_170 ( struct V_182 * V_183 )
{
static struct V_1 * V_2 ;
int V_21 , V_188 ;
V_2 = F_171 ( V_183 ) ;
if ( ! V_2 )
return - V_186 ;
F_163 ( & V_131 . V_132 ) ;
F_172 ( & V_2 -> V_193 ) ;
F_165 ( & V_131 . V_132 ) ;
for ( V_21 = V_2 -> V_22 -> V_207 - 1 ; V_21 >= 0 ; V_21 -- )
for ( V_188 = V_2 -> V_22 -> V_208 [ V_21 ] . V_212 - 1 ; V_188 >= 0 ; V_188 -- )
F_167 (
& V_2 -> V_22 -> V_208 [ V_21 ] . V_210 [ V_188 ] ) ;
F_173 ( & V_2 -> V_96 ) ;
F_168 ( & V_183 -> V_53 ) ;
if ( ! V_2 -> V_138 )
F_169 ( V_2 -> V_110 ) ;
return 0 ;
}
static int F_174 ( struct V_173 * V_53 )
{
F_161 ( V_53 ) ;
return 0 ;
}
static int F_175 ( struct V_173 * V_53 )
{
int V_52 = F_21 ( V_53 ) ;
if ( V_52 < 0 ) {
F_22 ( V_53 , L_1 , V_52 ) ;
return V_52 ;
}
return 0 ;
}
