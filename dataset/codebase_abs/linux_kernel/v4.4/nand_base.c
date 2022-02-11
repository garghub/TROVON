static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
if ( V_3 & ( ( 1ULL << V_6 -> V_9 ) - 1 ) ) {
F_2 ( L_1 , V_10 ) ;
V_8 = - V_11 ;
}
if ( V_4 & ( ( 1ULL << V_6 -> V_9 ) - 1 ) ) {
F_2 ( L_2 , V_10 ) ;
V_8 = - V_11 ;
}
return V_8 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( & V_6 -> V_12 -> V_13 ) ;
V_6 -> V_12 -> V_14 = NULL ;
V_6 -> V_15 = V_16 ;
F_5 ( & V_6 -> V_12 -> V_17 ) ;
F_6 ( & V_6 -> V_12 -> V_13 ) ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_8 ( V_6 -> V_18 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return ( T_3 ) F_10 ( F_11 ( V_6 -> V_18 ) ) ;
}
static T_4 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_11 ( V_6 -> V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_19 ) {
case - 1 :
V_6 -> V_20 ( V_2 , V_21 , 0 | V_22 ) ;
break;
case 0 :
break;
default:
F_14 () ;
}
}
static void F_15 ( struct V_1 * V_2 , T_3 V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_24 ( V_2 , & V_23 , 1 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_3 V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_5 V_25 = V_23 ;
V_6 -> V_24 ( V_2 , ( T_3 * ) & V_25 , 2 ) ;
}
static void F_17 ( struct V_1 * V_2 , const T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_18 ( V_6 -> V_27 , V_26 , V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_20 ( V_6 -> V_18 , V_26 , V_4 ) ;
}
static void F_21 ( struct V_1 * V_2 , const T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_26 ;
F_22 ( V_6 -> V_27 , V_28 , V_4 >> 1 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_26 ;
F_24 ( V_6 -> V_18 , V_28 , V_4 >> 1 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_3 , int V_29 )
{
int V_30 , V_19 , V_31 = 0 , V_32 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 V_33 ;
if ( V_6 -> V_34 & V_35 )
V_3 += V_2 -> V_36 - V_2 -> V_37 ;
V_30 = ( int ) ( V_3 >> V_6 -> V_38 ) & V_6 -> V_39 ;
if ( V_29 ) {
V_19 = ( int ) ( V_3 >> V_6 -> V_40 ) ;
F_26 ( V_2 , V_41 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
do {
if ( V_6 -> V_43 & V_44 ) {
V_6 -> V_45 ( V_2 , V_46 ,
V_6 -> V_47 & 0xFE , V_30 ) ;
V_33 = F_10 ( V_6 -> V_48 ( V_2 ) ) ;
if ( V_6 -> V_47 & 0x1 )
V_33 >>= 8 ;
else
V_33 &= 0xFF ;
} else {
V_6 -> V_45 ( V_2 , V_46 , V_6 -> V_47 ,
V_30 ) ;
V_33 = V_6 -> V_49 ( V_2 ) ;
}
if ( F_27 ( V_6 -> V_50 == 8 ) )
V_31 = V_33 != 0xFF ;
else
V_31 = F_28 ( V_33 ) < V_6 -> V_50 ;
V_3 += V_2 -> V_37 ;
V_30 = ( int ) ( V_3 >> V_6 -> V_38 ) & V_6 -> V_39 ;
V_32 ++ ;
} while ( ! V_31 && V_32 < 2 && ( V_6 -> V_34 & V_51 ) );
if ( V_29 ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
}
return V_31 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_52 V_53 ;
T_3 V_26 [ 2 ] = { 0 , 0 } ;
int V_8 = 0 , V_31 , V_32 = 0 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_54 = V_26 ;
V_53 . V_55 = V_6 -> V_47 ;
if ( V_6 -> V_43 & V_44 ) {
V_53 . V_55 &= ~ 0x01 ;
V_53 . V_4 = V_53 . V_56 = 2 ;
} else {
V_53 . V_4 = V_53 . V_56 = 1 ;
}
V_53 . V_57 = V_58 ;
if ( V_6 -> V_34 & V_35 )
V_3 += V_2 -> V_36 - V_2 -> V_37 ;
do {
V_31 = F_30 ( V_2 , V_3 , & V_53 ) ;
if ( ! V_8 )
V_8 = V_31 ;
V_32 ++ ;
V_3 += V_2 -> V_37 ;
} while ( ( V_6 -> V_34 & V_51 ) && V_32 < 2 );
return V_8 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_31 , V_8 = 0 ;
if ( ! ( V_6 -> V_34 & V_59 ) ) {
struct V_60 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_2 = V_2 ;
V_61 . V_62 = V_3 ;
V_61 . V_4 = 1ULL << V_6 -> V_9 ;
F_32 ( V_2 , & V_61 , 0 ) ;
F_26 ( V_2 , V_63 ) ;
V_8 = V_6 -> V_64 ( V_2 , V_3 ) ;
F_3 ( V_2 ) ;
}
if ( V_6 -> V_65 ) {
V_31 = F_33 ( V_2 , V_3 ) ;
if ( ! V_8 )
V_8 = V_31 ;
}
if ( ! V_8 )
V_2 -> V_66 . V_67 ++ ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_43 & V_68 )
return 0 ;
V_6 -> V_45 ( V_2 , V_69 , - 1 , - 1 ) ;
return ( V_6 -> V_49 ( V_2 ) & V_70 ) ? 0 : 1 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_65 )
return 0 ;
return F_36 ( V_2 , V_3 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_3 , int V_29 ,
int V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_65 )
return V_6 -> V_72 ( V_2 , V_3 , V_29 ) ;
return F_38 ( V_2 , V_3 , V_71 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_73 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( V_6 -> V_74 ( V_2 ) )
break;
F_40 () ;
F_41 ( 1 ) ;
}
}
void F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_73 = 400 ;
if ( F_43 () || V_75 )
return F_39 ( V_2 , V_73 ) ;
F_44 ( V_76 , V_77 ) ;
V_73 = V_78 + F_45 ( V_73 ) ;
do {
if ( V_6 -> V_74 ( V_2 ) )
goto V_79;
F_46 () ;
} while ( F_47 ( V_78 , V_73 ) );
F_48 (
L_3 ) ;
V_79:
F_44 ( V_76 , V_80 ) ;
}
static void F_49 ( struct V_1 * V_2 , unsigned long V_73 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
V_73 = V_78 + F_45 ( V_73 ) ;
do {
if ( ( V_6 -> V_49 ( V_2 ) & V_81 ) )
break;
F_40 () ;
} while ( F_47 ( V_78 , V_73 ) );
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_82 ,
int V_83 , int V_84 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
int V_85 = V_86 | V_22 ;
if ( V_82 == V_87 ) {
int V_88 ;
if ( V_83 >= V_2 -> V_37 ) {
V_83 -= V_2 -> V_37 ;
V_88 = V_46 ;
} else if ( V_83 < 256 ) {
V_88 = V_89 ;
} else {
V_83 -= 256 ;
V_88 = V_90 ;
}
V_6 -> V_20 ( V_2 , V_88 , V_85 ) ;
V_85 &= ~ V_22 ;
}
V_6 -> V_20 ( V_2 , V_82 , V_85 ) ;
V_85 = V_91 | V_22 ;
if ( V_83 != - 1 ) {
if ( V_6 -> V_43 & V_44 &&
! F_51 ( V_82 ) )
V_83 >>= 1 ;
V_6 -> V_20 ( V_2 , V_83 , V_85 ) ;
V_85 &= ~ V_22 ;
}
if ( V_84 != - 1 ) {
V_6 -> V_20 ( V_2 , V_84 , V_85 ) ;
V_85 &= ~ V_22 ;
V_6 -> V_20 ( V_2 , V_84 >> 8 , V_85 ) ;
if ( V_6 -> V_92 > ( 32 << 20 ) )
V_6 -> V_20 ( V_2 , V_84 >> 16 , V_85 ) ;
}
V_6 -> V_20 ( V_2 , V_21 , V_93 | V_22 ) ;
switch ( V_82 ) {
case V_94 :
case V_95 :
case V_96 :
case V_87 :
case V_69 :
return;
case V_97 :
if ( V_6 -> V_74 )
break;
F_52 ( V_6 -> V_98 ) ;
V_6 -> V_20 ( V_2 , V_69 ,
V_86 | V_22 ) ;
V_6 -> V_20 ( V_2 ,
V_21 , V_93 | V_22 ) ;
F_49 ( V_2 , 250 ) ;
return;
default:
if ( ! V_6 -> V_74 ) {
F_52 ( V_6 -> V_98 ) ;
return;
}
}
F_53 ( 100 ) ;
F_42 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_82 ,
int V_83 , int V_84 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_82 == V_46 ) {
V_83 += V_2 -> V_37 ;
V_82 = V_89 ;
}
V_6 -> V_20 ( V_2 , V_82 , V_93 | V_99 | V_22 ) ;
if ( V_83 != - 1 || V_84 != - 1 ) {
int V_85 = V_22 | V_93 | V_100 ;
if ( V_83 != - 1 ) {
if ( V_6 -> V_43 & V_44 &&
! F_51 ( V_82 ) )
V_83 >>= 1 ;
V_6 -> V_20 ( V_2 , V_83 , V_85 ) ;
V_85 &= ~ V_22 ;
V_6 -> V_20 ( V_2 , V_83 >> 8 , V_85 ) ;
}
if ( V_84 != - 1 ) {
V_6 -> V_20 ( V_2 , V_84 , V_85 ) ;
V_6 -> V_20 ( V_2 , V_84 >> 8 ,
V_93 | V_100 ) ;
if ( V_6 -> V_92 > ( 128 << 20 ) )
V_6 -> V_20 ( V_2 , V_84 >> 16 ,
V_93 | V_100 ) ;
}
}
V_6 -> V_20 ( V_2 , V_21 , V_93 | V_22 ) ;
switch ( V_82 ) {
case V_101 :
case V_94 :
case V_95 :
case V_96 :
case V_87 :
case V_102 :
case V_69 :
return;
case V_97 :
if ( V_6 -> V_74 )
break;
F_52 ( V_6 -> V_98 ) ;
V_6 -> V_20 ( V_2 , V_69 ,
V_93 | V_99 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_93 | V_22 ) ;
F_49 ( V_2 , 250 ) ;
return;
case V_103 :
V_6 -> V_20 ( V_2 , V_104 ,
V_93 | V_99 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_93 | V_22 ) ;
return;
case V_89 :
V_6 -> V_20 ( V_2 , V_105 ,
V_93 | V_99 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_93 | V_22 ) ;
default:
if ( ! V_6 -> V_74 ) {
F_52 ( V_6 -> V_98 ) ;
return;
}
}
F_53 ( 100 ) ;
F_42 ( V_2 ) ;
}
static void F_55 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_106 )
{
V_6 -> V_12 -> V_14 = V_6 ;
V_6 -> V_15 = V_106 ;
}
static int
F_26 ( struct V_1 * V_2 , int V_106 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_6 * V_13 = & V_6 -> V_12 -> V_13 ;
T_7 * V_17 = & V_6 -> V_12 -> V_17 ;
F_56 ( V_107 , V_108 ) ;
V_109:
F_4 ( V_13 ) ;
if ( ! V_6 -> V_12 -> V_14 )
V_6 -> V_12 -> V_14 = V_6 ;
if ( V_6 -> V_12 -> V_14 == V_6 && V_6 -> V_15 == V_16 ) {
V_6 -> V_15 = V_106 ;
F_6 ( V_13 ) ;
return 0 ;
}
if ( V_106 == V_110 ) {
if ( V_6 -> V_12 -> V_14 -> V_15 == V_110 ) {
V_6 -> V_15 = V_110 ;
F_6 ( V_13 ) ;
return 0 ;
}
}
F_57 ( V_111 ) ;
F_58 ( V_17 , & V_107 ) ;
F_6 ( V_13 ) ;
F_59 () ;
F_60 ( V_17 , & V_107 ) ;
goto V_109;
}
static void F_61 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_73 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( V_6 -> V_74 ) {
if ( V_6 -> V_74 ( V_2 ) )
break;
} else {
if ( V_6 -> V_49 ( V_2 ) & V_81 )
break;
}
F_41 ( 1 ) ;
}
}
static int F_62 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_112 ;
unsigned long V_73 = 400 ;
F_44 ( V_76 , V_77 ) ;
F_53 ( 100 ) ;
V_6 -> V_45 ( V_2 , V_69 , - 1 , - 1 ) ;
if ( F_43 () || V_75 )
F_61 ( V_2 , V_6 , V_73 ) ;
else {
V_73 = V_78 + F_45 ( V_73 ) ;
do {
if ( V_6 -> V_74 ) {
if ( V_6 -> V_74 ( V_2 ) )
break;
} else {
if ( V_6 -> V_49 ( V_2 ) & V_81 )
break;
}
F_46 () ;
} while ( F_47 ( V_78 , V_73 ) );
}
F_44 ( V_76 , V_80 ) ;
V_112 = ( int ) V_6 -> V_49 ( V_2 ) ;
F_63 ( ! ( V_112 & V_81 ) ) ;
return V_112 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_113 )
{
int V_8 = 0 ;
int V_112 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_30 = V_3 >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_114 , - 1 , V_30 & V_6 -> V_39 ) ;
V_30 = ( V_3 + V_4 ) >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_115 , - 1 ,
( V_30 | V_113 ) & V_6 -> V_39 ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( V_112 & V_117 ) {
F_2 ( L_4 ,
V_10 , V_112 ) ;
V_8 = - V_118 ;
}
return V_8 ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_5 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_11 ;
if ( V_3 + V_4 == V_2 -> V_119 )
V_4 -= V_2 -> V_36 ;
F_26 ( V_2 , V_120 ) ;
V_19 = V_3 >> V_6 -> V_40 ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_6 -> V_45 ( V_2 , V_97 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_6 ,
V_10 ) ;
V_8 = - V_118 ;
goto V_79;
}
V_8 = F_64 ( V_2 , V_3 , V_4 , 0 ) ;
V_79:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_19 , V_112 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_5 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_11 ;
F_26 ( V_2 , V_121 ) ;
V_19 = V_3 >> V_6 -> V_40 ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_6 -> V_45 ( V_2 , V_97 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_6 ,
V_10 ) ;
V_112 = V_122 ;
V_8 = - V_118 ;
goto V_79;
}
V_30 = V_3 >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_123 , - 1 , V_30 & V_6 -> V_39 ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( V_112 & V_117 ) {
F_2 ( L_4 ,
V_10 , V_112 ) ;
V_8 = - V_118 ;
goto V_79;
}
V_8 = F_64 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_79:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_67 ( void * V_26 , int V_4 , int V_124 )
{
const unsigned char * V_125 = V_26 ;
int V_126 = 0 ;
int V_127 ;
for (; V_4 && ( ( V_128 ) V_125 ) % sizeof( long ) ;
V_4 -- , V_125 ++ ) {
V_127 = F_28 ( * V_125 ) ;
V_126 += V_129 - V_127 ;
if ( F_68 ( V_126 > V_124 ) )
return - V_130 ;
}
for (; V_4 >= sizeof( long ) ;
V_4 -= sizeof( long ) , V_125 += sizeof( long ) ) {
V_127 = F_69 ( * ( ( unsigned long * ) V_125 ) ) ;
V_126 += V_131 - V_127 ;
if ( F_68 ( V_126 > V_124 ) )
return - V_130 ;
}
for (; V_4 > 0 ; V_4 -- , V_125 ++ ) {
V_127 = F_28 ( * V_125 ) ;
V_126 += V_129 - V_127 ;
if ( F_68 ( V_126 > V_124 ) )
return - V_130 ;
}
return V_126 ;
}
int F_70 ( void * V_132 , int V_133 ,
void * V_134 , int V_135 ,
void * V_136 , int V_137 ,
int V_124 )
{
int V_138 = 0 , V_139 = 0 , V_140 = 0 ;
V_138 = F_67 ( V_132 , V_133 ,
V_124 ) ;
if ( V_138 < 0 )
return V_138 ;
V_124 -= V_138 ;
V_139 = F_67 ( V_134 , V_135 , V_124 ) ;
if ( V_139 < 0 )
return V_139 ;
V_124 -= V_139 ;
V_140 = F_67 ( V_136 , V_137 ,
V_124 ) ;
if ( V_140 < 0 )
return V_140 ;
if ( V_138 )
memset ( V_132 , 0xff , V_133 ) ;
if ( V_139 )
memset ( V_134 , 0xff , V_135 ) ;
if ( V_140 )
memset ( V_136 , 0xff , V_137 ) ;
return V_138 + V_139 + V_140 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_141 , int V_30 )
{
V_6 -> V_142 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_141 )
V_6 -> V_142 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_26 ,
int V_141 , int V_30 )
{
int V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
T_3 * V_148 = V_6 -> V_143 ;
int V_149 , V_119 ;
for ( V_149 = V_6 -> V_134 . V_149 ; V_149 > 0 ; V_149 -- ) {
V_6 -> V_142 ( V_2 , V_26 , V_145 ) ;
V_26 += V_145 ;
if ( V_6 -> V_134 . V_150 ) {
V_6 -> V_142 ( V_2 , V_148 , V_6 -> V_134 . V_150 ) ;
V_148 += V_6 -> V_134 . V_150 ;
}
V_6 -> V_142 ( V_2 , V_148 , V_146 ) ;
V_148 += V_146 ;
if ( V_6 -> V_134 . V_151 ) {
V_6 -> V_142 ( V_2 , V_148 , V_6 -> V_134 . V_151 ) ;
V_148 += V_6 -> V_134 . V_151 ;
}
}
V_119 = V_2 -> V_144 - ( V_148 - V_6 -> V_143 ) ;
if ( V_119 )
V_6 -> V_142 ( V_2 , V_148 , V_119 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_141 , int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
T_3 * V_28 = V_26 ;
T_3 * V_153 = V_6 -> V_154 -> V_155 ;
T_3 * V_156 = V_6 -> V_154 -> V_157 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
unsigned int V_160 = 0 ;
V_6 -> V_134 . V_161 ( V_2 , V_6 , V_26 , 1 , V_30 ) ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 )
V_6 -> V_134 . V_162 ( V_2 , V_28 , & V_153 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_163 ; V_32 ++ )
V_156 [ V_32 ] = V_6 -> V_143 [ V_158 [ V_32 ] ] ;
V_152 = V_6 -> V_134 . V_149 ;
V_28 = V_26 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
int V_164 ;
V_164 = V_6 -> V_134 . V_165 ( V_2 , V_28 , & V_156 [ V_32 ] , & V_153 [ V_32 ] ) ;
if ( V_164 < 0 ) {
V_2 -> V_66 . V_166 ++ ;
} else {
V_2 -> V_66 . V_167 += V_164 ;
V_160 = F_74 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_168 , T_8 V_169 , T_3 * V_170 ,
int V_30 )
{
int V_171 , V_172 , V_173 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
T_3 * V_28 ;
int V_174 , V_32 , V_175 = 0 ;
int V_176 , V_177 , V_178 , V_179 ;
int V_180 = ( V_6 -> V_43 & V_44 ) ? 2 : 1 ;
int V_181 ;
unsigned int V_160 = 0 ;
V_171 = V_168 / V_6 -> V_134 . V_119 ;
V_172 = ( V_168 + V_169 - 1 ) / V_6 -> V_134 . V_119 ;
V_173 = V_172 - V_171 + 1 ;
V_181 = V_171 * V_6 -> V_134 . V_147 ;
V_176 = V_173 * V_6 -> V_134 . V_119 ;
V_177 = V_173 * V_6 -> V_134 . V_147 ;
V_174 = V_171 * V_6 -> V_134 . V_119 ;
if ( V_174 != 0 )
V_6 -> V_45 ( V_2 , V_103 , V_174 , - 1 ) ;
V_28 = V_170 + V_174 ;
V_6 -> V_142 ( V_2 , V_28 , V_176 ) ;
for ( V_32 = 0 ; V_32 < V_177 ; V_32 += V_6 -> V_134 . V_147 , V_28 += V_6 -> V_134 . V_119 )
V_6 -> V_134 . V_162 ( V_2 , V_28 , & V_6 -> V_154 -> V_155 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_177 - 1 ; V_32 ++ ) {
if ( V_158 [ V_32 + V_181 ] + 1 != V_158 [ V_32 + V_181 + 1 ] ) {
V_175 = 1 ;
break;
}
}
if ( V_175 ) {
V_6 -> V_45 ( V_2 , V_103 , V_2 -> V_37 , - 1 ) ;
V_6 -> V_142 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
} else {
V_179 = V_158 [ V_181 ] & ~ ( V_180 - 1 ) ;
V_178 = V_177 ;
if ( V_158 [ V_181 ] & ( V_180 - 1 ) )
V_178 ++ ;
if ( V_158 [ V_181 + ( V_173 * V_6 -> V_134 . V_147 ) ] & ( V_180 - 1 ) )
V_178 ++ ;
V_6 -> V_45 ( V_2 , V_103 ,
V_2 -> V_37 + V_179 , - 1 ) ;
V_6 -> V_142 ( V_2 , & V_6 -> V_143 [ V_179 ] , V_178 ) ;
}
for ( V_32 = 0 ; V_32 < V_177 ; V_32 ++ )
V_6 -> V_154 -> V_157 [ V_32 ] = V_6 -> V_143 [ V_158 [ V_32 + V_181 ] ] ;
V_28 = V_170 + V_174 ;
for ( V_32 = 0 ; V_32 < V_177 ; V_32 += V_6 -> V_134 . V_147 , V_28 += V_6 -> V_134 . V_119 ) {
int V_164 ;
V_164 = V_6 -> V_134 . V_165 ( V_2 , V_28 ,
& V_6 -> V_154 -> V_157 [ V_32 ] , & V_6 -> V_154 -> V_155 [ V_32 ] ) ;
if ( V_164 < 0 ) {
V_2 -> V_66 . V_166 ++ ;
} else {
V_2 -> V_66 . V_167 += V_164 ;
V_160 = F_74 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_141 , int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
T_3 * V_28 = V_26 ;
T_3 * V_153 = V_6 -> V_154 -> V_155 ;
T_3 * V_156 = V_6 -> V_154 -> V_157 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
unsigned int V_160 = 0 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
V_6 -> V_134 . V_182 ( V_2 , V_183 ) ;
V_6 -> V_142 ( V_2 , V_28 , V_145 ) ;
V_6 -> V_134 . V_162 ( V_2 , V_28 , & V_153 [ V_32 ] ) ;
}
V_6 -> V_142 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_163 ; V_32 ++ )
V_156 [ V_32 ] = V_6 -> V_143 [ V_158 [ V_32 ] ] ;
V_152 = V_6 -> V_134 . V_149 ;
V_28 = V_26 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
int V_164 ;
V_164 = V_6 -> V_134 . V_165 ( V_2 , V_28 , & V_156 [ V_32 ] , & V_153 [ V_32 ] ) ;
if ( V_164 < 0 ) {
V_2 -> V_66 . V_166 ++ ;
} else {
V_2 -> V_66 . V_167 += V_164 ;
V_160 = F_74 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_26 , int V_141 , int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
T_3 * V_28 = V_26 ;
T_3 * V_156 = V_6 -> V_154 -> V_157 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
T_3 * V_153 = V_6 -> V_154 -> V_155 ;
unsigned int V_160 = 0 ;
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_142 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
V_6 -> V_45 ( V_2 , V_89 , 0 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_163 ; V_32 ++ )
V_156 [ V_32 ] = V_6 -> V_143 [ V_158 [ V_32 ] ] ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
int V_164 ;
V_6 -> V_134 . V_182 ( V_2 , V_183 ) ;
V_6 -> V_142 ( V_2 , V_28 , V_145 ) ;
V_6 -> V_134 . V_162 ( V_2 , V_28 , & V_153 [ V_32 ] ) ;
V_164 = V_6 -> V_134 . V_165 ( V_2 , V_28 , & V_156 [ V_32 ] , NULL ) ;
if ( V_164 < 0 ) {
V_2 -> V_66 . V_166 ++ ;
} else {
V_2 -> V_66 . V_167 += V_164 ;
V_160 = F_74 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_141 , int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
T_3 * V_28 = V_26 ;
T_3 * V_148 = V_6 -> V_143 ;
unsigned int V_160 = 0 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
int V_164 ;
V_6 -> V_134 . V_182 ( V_2 , V_183 ) ;
V_6 -> V_142 ( V_2 , V_28 , V_145 ) ;
if ( V_6 -> V_134 . V_150 ) {
V_6 -> V_142 ( V_2 , V_148 , V_6 -> V_134 . V_150 ) ;
V_148 += V_6 -> V_134 . V_150 ;
}
V_6 -> V_134 . V_182 ( V_2 , V_184 ) ;
V_6 -> V_142 ( V_2 , V_148 , V_146 ) ;
V_164 = V_6 -> V_134 . V_165 ( V_2 , V_28 , V_148 , NULL ) ;
if ( V_164 < 0 ) {
V_2 -> V_66 . V_166 ++ ;
} else {
V_2 -> V_66 . V_167 += V_164 ;
V_160 = F_74 (unsigned int, max_bitflips, stat) ;
}
V_148 += V_146 ;
if ( V_6 -> V_134 . V_151 ) {
V_6 -> V_142 ( V_2 , V_148 , V_6 -> V_134 . V_151 ) ;
V_148 += V_6 -> V_134 . V_151 ;
}
}
V_32 = V_2 -> V_144 - ( V_148 - V_6 -> V_143 ) ;
if ( V_32 )
V_6 -> V_142 ( V_2 , V_148 , V_32 ) ;
return V_160 ;
}
static T_3 * F_79 ( struct V_5 * V_6 , T_3 * V_148 ,
struct V_52 * V_53 , T_9 V_4 )
{
switch ( V_53 -> V_57 ) {
case V_58 :
case V_185 :
memcpy ( V_148 , V_6 -> V_143 + V_53 -> V_55 , V_4 ) ;
return V_148 + V_4 ;
case V_186 : {
struct V_187 * free = V_6 -> V_134 . V_159 -> V_188 ;
T_8 V_189 = 0 , V_190 = V_53 -> V_55 ;
T_9 V_147 = 0 ;
for (; free -> V_191 && V_4 ; free ++ , V_4 -= V_147 ) {
if ( F_68 ( V_190 ) ) {
if ( V_190 >= free -> V_191 ) {
V_190 -= free -> V_191 ;
continue;
}
V_189 = free -> V_192 + V_190 ;
V_147 = F_80 ( T_9 , V_4 ,
( free -> V_191 - V_190 ) ) ;
V_190 = 0 ;
} else {
V_147 = F_80 ( T_9 , V_4 , free -> V_191 ) ;
V_189 = free -> V_192 ;
}
memcpy ( V_148 , V_6 -> V_143 + V_189 , V_147 ) ;
V_148 += V_147 ;
}
return V_148 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_81 ( struct V_1 * V_2 , int V_193 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_7 , V_193 ) ;
if ( V_193 >= V_6 -> V_194 )
return - V_11 ;
if ( ! V_6 -> V_195 )
return - V_196 ;
return V_6 -> V_195 ( V_2 , V_193 ) ;
}
static int F_82 ( struct V_1 * V_2 , T_1 V_197 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_198 , V_199 , V_147 , V_200 , V_141 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
T_8 V_169 = V_53 -> V_4 ;
T_8 V_201 = V_53 -> V_56 ;
T_8 V_202 = V_53 -> V_57 == V_186 ?
V_2 -> V_203 : V_2 -> V_144 ;
T_3 * V_170 , * V_148 , * V_26 ;
int V_204 ;
unsigned int V_160 = 0 ;
int V_193 = 0 ;
bool V_205 = false ;
V_19 = ( int ) ( V_197 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_198 = ( int ) ( V_197 >> V_6 -> V_38 ) ;
V_30 = V_198 & V_6 -> V_39 ;
V_199 = ( int ) ( V_197 & ( V_2 -> V_37 - 1 ) ) ;
V_26 = V_53 -> V_206 ;
V_148 = V_53 -> V_54 ;
V_141 = V_148 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_207 = V_2 -> V_66 . V_166 ;
V_147 = F_83 ( V_2 -> V_37 - V_199 , V_169 ) ;
V_200 = ( V_147 == V_2 -> V_37 ) ;
if ( ! V_200 )
V_204 = 1 ;
else if ( V_6 -> V_43 & V_208 )
V_204 = ! F_84 ( V_26 ) ;
else
V_204 = 0 ;
if ( V_198 != V_6 -> V_209 || V_148 ) {
V_170 = V_204 ? V_6 -> V_154 -> V_210 : V_26 ;
if ( V_204 && V_200 )
F_2 ( L_8 ,
V_10 , V_26 ) ;
V_211:
V_6 -> V_45 ( V_2 , V_89 , 0x00 , V_30 ) ;
if ( F_68 ( V_53 -> V_57 == V_185 ) )
V_8 = V_6 -> V_134 . V_161 ( V_2 , V_6 , V_170 ,
V_141 ,
V_30 ) ;
else if ( ! V_200 && F_85 ( V_6 ) &&
! V_148 )
V_8 = V_6 -> V_134 . V_212 ( V_2 , V_6 ,
V_199 , V_147 , V_170 ,
V_30 ) ;
else
V_8 = V_6 -> V_134 . V_213 ( V_2 , V_6 , V_170 ,
V_141 , V_30 ) ;
if ( V_8 < 0 ) {
if ( V_204 )
V_6 -> V_209 = - 1 ;
break;
}
V_160 = F_74 (unsigned int, max_bitflips, ret) ;
if ( V_204 ) {
if ( ! F_85 ( V_6 ) && ! V_148 &&
! ( V_2 -> V_66 . V_166 - V_207 ) &&
( V_53 -> V_57 != V_185 ) ) {
V_6 -> V_209 = V_198 ;
V_6 -> V_214 = V_8 ;
} else {
V_6 -> V_209 = - 1 ;
}
memcpy ( V_26 , V_6 -> V_154 -> V_210 + V_199 , V_147 ) ;
}
if ( F_68 ( V_148 ) ) {
int V_215 = F_83 ( V_201 , V_202 ) ;
if ( V_215 ) {
V_148 = F_79 ( V_6 ,
V_148 , V_53 , V_215 ) ;
V_201 -= V_215 ;
}
}
if ( V_6 -> V_43 & V_216 ) {
if ( ! V_6 -> V_74 )
F_52 ( V_6 -> V_98 ) ;
else
F_42 ( V_2 ) ;
}
if ( V_2 -> V_66 . V_166 - V_207 ) {
if ( V_193 + 1 < V_6 -> V_194 ) {
V_193 ++ ;
V_8 = F_81 ( V_2 ,
V_193 ) ;
if ( V_8 < 0 )
break;
V_2 -> V_66 . V_166 = V_207 ;
goto V_211;
} else {
V_205 = true ;
}
}
V_26 += V_147 ;
} else {
memcpy ( V_26 , V_6 -> V_154 -> V_210 + V_199 , V_147 ) ;
V_26 += V_147 ;
V_160 = F_74 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_169 -= V_147 ;
if ( V_193 ) {
V_8 = F_81 ( V_2 , 0 ) ;
if ( V_8 < 0 )
break;
V_193 = 0 ;
}
if ( ! V_169 )
break;
V_199 = 0 ;
V_198 ++ ;
V_30 = V_198 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_6 -> V_42 ( V_2 , - 1 ) ;
V_53 -> V_217 = V_53 -> V_4 - ( T_9 ) V_169 ;
if ( V_148 )
V_53 -> V_218 = V_53 -> V_56 - V_201 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_205 )
return - V_130 ;
return V_160 ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_197 , T_9 V_4 ,
T_9 * V_217 , T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_41 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_206 = V_26 ;
V_53 . V_57 = V_58 ;
V_8 = F_82 ( V_2 , V_197 , & V_53 ) ;
* V_217 = V_53 . V_217 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_142 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
int V_191 = V_2 -> V_144 ;
int V_219 = V_6 -> V_134 . V_147 + V_6 -> V_134 . V_150 + V_6 -> V_134 . V_151 ;
int V_145 = V_6 -> V_134 . V_119 ;
T_3 * V_170 = V_6 -> V_143 ;
int V_32 , V_215 , V_220 = 0 , V_221 ;
V_6 -> V_45 ( V_2 , V_89 , V_6 -> V_134 . V_119 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_149 ; V_32 ++ ) {
if ( V_220 ) {
V_221 = V_145 + V_32 * ( V_145 + V_219 ) ;
if ( V_2 -> V_37 > 512 )
V_6 -> V_45 ( V_2 , V_103 , V_221 , - 1 ) ;
else
V_6 -> V_45 ( V_2 , V_89 , V_221 , V_30 ) ;
} else
V_220 = 1 ;
V_215 = F_80 ( int , V_191 , V_219 ) ;
V_6 -> V_142 ( V_2 , V_170 , V_215 ) ;
V_170 += V_215 ;
V_191 -= V_215 ;
}
if ( V_191 > 0 )
V_6 -> V_142 ( V_2 , V_170 , V_191 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
int V_112 = 0 ;
const T_3 * V_26 = V_6 -> V_143 ;
int V_191 = V_2 -> V_144 ;
V_6 -> V_45 ( V_2 , V_87 , V_2 -> V_37 , V_30 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_191 ) ;
V_6 -> V_45 ( V_2 , V_94 , - 1 , - 1 ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
return V_112 & V_117 ? - V_118 : 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_30 )
{
int V_219 = V_6 -> V_134 . V_147 + V_6 -> V_134 . V_150 + V_6 -> V_134 . V_151 ;
int V_145 = V_6 -> V_134 . V_119 , V_191 = V_2 -> V_144 ;
int V_32 , V_4 , V_221 , V_112 = 0 , V_222 = 0 , V_149 = V_6 -> V_134 . V_149 ;
const T_3 * V_170 = V_6 -> V_143 ;
if ( ! V_6 -> V_134 . V_150 && ! V_6 -> V_134 . V_151 ) {
V_221 = V_149 * ( V_145 + V_219 ) ;
V_149 = 0 ;
} else
V_221 = V_145 ;
V_6 -> V_45 ( V_2 , V_87 , V_221 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_149 ; V_32 ++ ) {
if ( V_222 ) {
if ( V_2 -> V_37 <= 512 ) {
T_8 V_223 = 0xFFFFFFFF ;
V_4 = V_145 ;
while ( V_4 > 0 ) {
int V_224 = F_80 ( int , V_4 , 4 ) ;
V_6 -> V_24 ( V_2 , ( T_3 * ) & V_223 ,
V_224 ) ;
V_4 -= V_224 ;
}
} else {
V_221 = V_145 + V_32 * ( V_145 + V_219 ) ;
V_6 -> V_45 ( V_2 , V_102 , V_221 , - 1 ) ;
}
} else
V_222 = 1 ;
V_4 = F_80 ( int , V_191 , V_219 ) ;
V_6 -> V_24 ( V_2 , V_170 , V_4 ) ;
V_170 += V_4 ;
V_191 -= V_4 ;
}
if ( V_191 > 0 )
V_6 -> V_24 ( V_2 , V_170 , V_191 ) ;
V_6 -> V_45 ( V_2 , V_94 , - 1 , - 1 ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
return V_112 & V_117 ? - V_118 : 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_1 V_197 ,
struct V_52 * V_53 )
{
int V_30 , V_198 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_225 V_226 ;
int V_169 = V_53 -> V_56 ;
int V_4 ;
T_3 * V_26 = V_53 -> V_54 ;
int V_8 = 0 ;
F_2 ( L_9 ,
V_10 , ( unsigned long long ) V_197 , V_169 ) ;
V_226 = V_2 -> V_66 ;
if ( V_53 -> V_57 == V_186 )
V_4 = V_6 -> V_134 . V_159 -> V_203 ;
else
V_4 = V_2 -> V_144 ;
if ( F_68 ( V_53 -> V_55 >= V_4 ) ) {
F_2 ( L_10 ,
V_10 ) ;
return - V_11 ;
}
if ( F_68 ( V_197 >= V_2 -> V_119 ||
V_53 -> V_55 + V_169 > ( ( V_2 -> V_119 >> V_6 -> V_38 ) -
( V_197 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_11 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_197 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_198 = ( int ) ( V_197 >> V_6 -> V_38 ) ;
V_30 = V_198 & V_6 -> V_39 ;
while ( 1 ) {
if ( V_53 -> V_57 == V_185 )
V_8 = V_6 -> V_134 . V_227 ( V_2 , V_6 , V_30 ) ;
else
V_8 = V_6 -> V_134 . V_228 ( V_2 , V_6 , V_30 ) ;
if ( V_8 < 0 )
break;
V_4 = F_83 ( V_4 , V_169 ) ;
V_26 = F_79 ( V_6 , V_26 , V_53 , V_4 ) ;
if ( V_6 -> V_43 & V_216 ) {
if ( ! V_6 -> V_74 )
F_52 ( V_6 -> V_98 ) ;
else
F_42 ( V_2 ) ;
}
V_169 -= V_4 ;
if ( ! V_169 )
break;
V_198 ++ ;
V_30 = V_198 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_6 -> V_42 ( V_2 , - 1 ) ;
V_53 -> V_218 = V_53 -> V_56 - V_169 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_66 . V_166 - V_226 . V_166 )
return - V_130 ;
return V_2 -> V_66 . V_167 - V_226 . V_167 ? - V_229 : 0 ;
}
static int F_92 ( struct V_1 * V_2 , T_1 V_197 ,
struct V_52 * V_53 )
{
int V_8 = - V_230 ;
V_53 -> V_217 = 0 ;
if ( V_53 -> V_206 && ( V_197 + V_53 -> V_4 ) > V_2 -> V_119 ) {
F_2 ( L_11 ,
V_10 ) ;
return - V_11 ;
}
F_26 ( V_2 , V_41 ) ;
switch ( V_53 -> V_57 ) {
case V_58 :
case V_186 :
case V_185 :
break;
default:
goto V_79;
}
if ( ! V_53 -> V_206 )
V_8 = F_91 ( V_2 , V_197 , V_53 ) ;
else
V_8 = F_82 ( V_2 , V_197 , V_53 ) ;
V_79:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_141 , int V_30 )
{
V_6 -> V_24 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_141 )
V_6 -> V_24 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_141 ,
int V_30 )
{
int V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
T_3 * V_148 = V_6 -> V_143 ;
int V_149 , V_119 ;
for ( V_149 = V_6 -> V_134 . V_149 ; V_149 > 0 ; V_149 -- ) {
V_6 -> V_24 ( V_2 , V_26 , V_145 ) ;
V_26 += V_145 ;
if ( V_6 -> V_134 . V_150 ) {
V_6 -> V_24 ( V_2 , V_148 , V_6 -> V_134 . V_150 ) ;
V_148 += V_6 -> V_134 . V_150 ;
}
V_6 -> V_24 ( V_2 , V_148 , V_146 ) ;
V_148 += V_146 ;
if ( V_6 -> V_134 . V_151 ) {
V_6 -> V_24 ( V_2 , V_148 , V_6 -> V_134 . V_151 ) ;
V_148 += V_6 -> V_134 . V_151 ;
}
}
V_119 = V_2 -> V_144 - ( V_148 - V_6 -> V_143 ) ;
if ( V_119 )
V_6 -> V_24 ( V_2 , V_148 , V_119 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_141 ,
int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
T_3 * V_153 = V_6 -> V_154 -> V_155 ;
const T_3 * V_28 = V_26 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 )
V_6 -> V_134 . V_162 ( V_2 , V_28 , & V_153 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_163 ; V_32 ++ )
V_6 -> V_143 [ V_158 [ V_32 ] ] = V_153 [ V_32 ] ;
return V_6 -> V_134 . V_231 ( V_2 , V_6 , V_26 , 1 , V_30 ) ;
}
static int F_96 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_141 ,
int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
T_3 * V_153 = V_6 -> V_154 -> V_155 ;
const T_3 * V_28 = V_26 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
V_6 -> V_134 . V_182 ( V_2 , V_232 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_145 ) ;
V_6 -> V_134 . V_162 ( V_2 , V_28 , & V_153 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_163 ; V_32 ++ )
V_6 -> V_143 [ V_158 [ V_32 ] ] = V_153 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_8 V_192 ,
T_8 V_233 , const T_3 * V_26 ,
int V_141 , int V_30 )
{
T_3 * V_234 = V_6 -> V_143 ;
T_3 * V_153 = V_6 -> V_154 -> V_155 ;
int V_235 = V_6 -> V_134 . V_119 ;
int V_236 = V_6 -> V_134 . V_147 ;
int V_237 = V_6 -> V_134 . V_149 ;
T_8 * V_158 = V_6 -> V_134 . V_159 -> V_158 ;
T_8 V_171 = V_192 / V_235 ;
T_8 V_172 = ( V_192 + V_233 - 1 ) / V_235 ;
int V_238 = V_2 -> V_144 / V_237 ;
int V_239 , V_32 ;
for ( V_239 = 0 ; V_239 < V_237 ; V_239 ++ ) {
V_6 -> V_134 . V_182 ( V_2 , V_232 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_235 ) ;
if ( ( V_239 < V_171 ) || ( V_239 > V_172 ) )
memset ( V_153 , 0xff , V_236 ) ;
else
V_6 -> V_134 . V_162 ( V_2 , V_26 , V_153 ) ;
if ( ! V_141 || ( V_239 < V_171 ) || ( V_239 > V_172 ) )
memset ( V_234 , 0xff , V_238 ) ;
V_26 += V_235 ;
V_153 += V_236 ;
V_234 += V_238 ;
}
V_153 = V_6 -> V_154 -> V_155 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_134 . V_163 ; V_32 ++ )
V_6 -> V_143 [ V_158 [ V_32 ] ] = V_153 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_143 , V_2 -> V_144 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_141 ,
int V_30 )
{
int V_32 , V_145 = V_6 -> V_134 . V_119 ;
int V_146 = V_6 -> V_134 . V_147 ;
int V_152 = V_6 -> V_134 . V_149 ;
const T_3 * V_28 = V_26 ;
T_3 * V_148 = V_6 -> V_143 ;
for ( V_32 = 0 ; V_152 ; V_152 -- , V_32 += V_146 , V_28 += V_145 ) {
V_6 -> V_134 . V_182 ( V_2 , V_232 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_145 ) ;
if ( V_6 -> V_134 . V_150 ) {
V_6 -> V_24 ( V_2 , V_148 , V_6 -> V_134 . V_150 ) ;
V_148 += V_6 -> V_134 . V_150 ;
}
V_6 -> V_134 . V_162 ( V_2 , V_28 , V_148 ) ;
V_6 -> V_24 ( V_2 , V_148 , V_146 ) ;
V_148 += V_146 ;
if ( V_6 -> V_134 . V_151 ) {
V_6 -> V_24 ( V_2 , V_148 , V_6 -> V_134 . V_151 ) ;
V_148 += V_6 -> V_134 . V_151 ;
}
}
V_32 = V_2 -> V_144 - ( V_148 - V_6 -> V_143 ) ;
if ( V_32 )
V_6 -> V_24 ( V_2 , V_148 , V_32 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_192 , int V_233 , const T_3 * V_26 ,
int V_141 , int V_30 , int V_240 , int V_241 )
{
int V_112 , V_242 ;
if ( ! ( V_6 -> V_43 & V_243 ) &&
V_6 -> V_134 . V_244 )
V_242 = V_192 || ( V_233 < V_2 -> V_37 ) ;
else
V_242 = 0 ;
V_6 -> V_45 ( V_2 , V_87 , 0x00 , V_30 ) ;
if ( F_68 ( V_241 ) )
V_112 = V_6 -> V_134 . V_231 ( V_2 , V_6 , V_26 ,
V_141 , V_30 ) ;
else if ( V_242 )
V_112 = V_6 -> V_134 . V_244 ( V_2 , V_6 , V_192 , V_233 ,
V_26 , V_141 , V_30 ) ;
else
V_112 = V_6 -> V_134 . V_245 ( V_2 , V_6 , V_26 , V_141 ,
V_30 ) ;
if ( V_112 < 0 )
return V_112 ;
V_240 = 0 ;
if ( ! V_240 || ! F_100 ( V_6 ) ) {
V_6 -> V_45 ( V_2 , V_94 , - 1 , - 1 ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( ( V_112 & V_117 ) && ( V_6 -> V_246 ) )
V_112 = V_6 -> V_246 ( V_2 , V_6 , V_63 , V_112 ,
V_30 ) ;
if ( V_112 & V_117 )
return - V_118 ;
} else {
V_6 -> V_45 ( V_2 , V_101 , - 1 , - 1 ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_101 ( struct V_1 * V_2 , T_3 * V_148 , T_9 V_4 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memset ( V_6 -> V_143 , 0xff , V_2 -> V_144 ) ;
switch ( V_53 -> V_57 ) {
case V_58 :
case V_185 :
memcpy ( V_6 -> V_143 + V_53 -> V_55 , V_148 , V_4 ) ;
return V_148 + V_4 ;
case V_186 : {
struct V_187 * free = V_6 -> V_134 . V_159 -> V_188 ;
T_8 V_189 = 0 , V_247 = V_53 -> V_55 ;
T_9 V_147 = 0 ;
for (; free -> V_191 && V_4 ; free ++ , V_4 -= V_147 ) {
if ( F_68 ( V_247 ) ) {
if ( V_247 >= free -> V_191 ) {
V_247 -= free -> V_191 ;
continue;
}
V_189 = free -> V_192 + V_247 ;
V_147 = F_80 ( T_9 , V_4 ,
( free -> V_191 - V_247 ) ) ;
V_247 = 0 ;
} else {
V_147 = F_80 ( T_9 , V_4 , free -> V_191 ) ;
V_189 = free -> V_192 ;
}
memcpy ( V_6 -> V_143 + V_189 , V_148 , V_147 ) ;
V_148 += V_147 ;
}
return V_148 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_102 ( struct V_1 * V_2 , T_1 V_248 ,
struct V_52 * V_53 )
{
int V_19 , V_198 , V_30 , V_249 , V_83 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_250 = V_53 -> V_4 ;
T_8 V_251 = V_53 -> V_56 ;
T_8 V_252 = V_53 -> V_57 == V_186 ?
V_2 -> V_203 : V_2 -> V_144 ;
T_3 * V_148 = V_53 -> V_54 ;
T_3 * V_26 = V_53 -> V_206 ;
int V_8 ;
int V_141 = V_148 ? 1 : 0 ;
V_53 -> V_217 = 0 ;
if ( ! V_250 )
return 0 ;
if ( F_103 ( V_248 ) || F_103 ( V_53 -> V_4 ) ) {
F_104 ( L_12 ,
V_10 ) ;
return - V_11 ;
}
V_83 = V_248 & ( V_2 -> V_37 - 1 ) ;
V_19 = ( int ) ( V_248 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
V_8 = - V_118 ;
goto V_253;
}
V_198 = ( int ) ( V_248 >> V_6 -> V_38 ) ;
V_30 = V_198 & V_6 -> V_39 ;
V_249 = ( 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ) - 1 ;
if ( V_248 <= ( ( T_1 ) V_6 -> V_209 << V_6 -> V_38 ) &&
( ( T_1 ) V_6 -> V_209 << V_6 -> V_38 ) < ( V_248 + V_53 -> V_4 ) )
V_6 -> V_209 = - 1 ;
if ( V_148 && V_53 -> V_55 && ( V_53 -> V_55 + V_53 -> V_56 > V_252 ) ) {
V_8 = - V_11 ;
goto V_253;
}
while ( 1 ) {
int V_147 = V_2 -> V_37 ;
int V_240 = V_250 > V_147 && V_30 != V_249 ;
T_3 * V_254 = V_26 ;
int V_204 ;
int V_255 = ( V_83 || V_250 < ( V_2 -> V_37 - 1 ) ) ;
if ( V_255 )
V_204 = 1 ;
else if ( V_6 -> V_43 & V_208 )
V_204 = ! F_84 ( V_26 ) ;
else
V_204 = 0 ;
if ( V_204 ) {
F_2 ( L_13 ,
V_10 , V_26 ) ;
V_240 = 0 ;
if ( V_255 )
V_147 = F_80 ( int , V_147 - V_83 , V_250 ) ;
V_6 -> V_209 = - 1 ;
memset ( V_6 -> V_154 -> V_210 , 0xff , V_2 -> V_37 ) ;
memcpy ( & V_6 -> V_154 -> V_210 [ V_83 ] , V_26 , V_147 ) ;
V_254 = V_6 -> V_154 -> V_210 ;
}
if ( F_68 ( V_148 ) ) {
T_9 V_4 = F_83 ( V_251 , V_252 ) ;
V_148 = F_101 ( V_2 , V_148 , V_4 , V_53 ) ;
V_251 -= V_4 ;
} else {
memset ( V_6 -> V_143 , 0xff , V_2 -> V_144 ) ;
}
V_8 = V_6 -> V_245 ( V_2 , V_6 , V_83 , V_147 , V_254 ,
V_141 , V_30 , V_240 ,
( V_53 -> V_57 == V_185 ) ) ;
if ( V_8 )
break;
V_250 -= V_147 ;
if ( ! V_250 )
break;
V_83 = 0 ;
V_26 += V_147 ;
V_198 ++ ;
V_30 = V_198 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_53 -> V_217 = V_53 -> V_4 - V_250 ;
if ( F_68 ( V_148 ) )
V_53 -> V_218 = V_53 -> V_56 ;
V_253:
V_6 -> V_42 ( V_2 , - 1 ) ;
return V_8 ;
}
static int F_105 ( struct V_1 * V_2 , T_1 V_248 , T_9 V_4 ,
T_9 * V_217 , const T_3 * V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_52 V_53 ;
int V_8 ;
F_61 ( V_2 , V_6 , 400 ) ;
F_55 ( V_6 , V_2 , V_63 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_206 = ( T_3 * ) V_26 ;
V_53 . V_57 = V_58 ;
V_8 = F_102 ( V_2 , V_248 , & V_53 ) ;
* V_217 = V_53 . V_217 ;
return V_8 ;
}
static int F_106 ( struct V_1 * V_2 , T_1 V_248 , T_9 V_4 ,
T_9 * V_217 , const T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_63 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_206 = ( T_3 * ) V_26 ;
V_53 . V_57 = V_58 ;
V_8 = F_102 ( V_2 , V_248 , & V_53 ) ;
* V_217 = V_53 . V_217 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_248 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_112 , V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_14 ,
V_10 , ( unsigned int ) V_248 , ( int ) V_53 -> V_56 ) ;
if ( V_53 -> V_57 == V_186 )
V_4 = V_6 -> V_134 . V_159 -> V_203 ;
else
V_4 = V_2 -> V_144 ;
if ( ( V_53 -> V_55 + V_53 -> V_56 ) > V_4 ) {
F_2 ( L_15 ,
V_10 ) ;
return - V_11 ;
}
if ( F_68 ( V_53 -> V_55 >= V_4 ) ) {
F_2 ( L_16 ,
V_10 ) ;
return - V_11 ;
}
if ( F_68 ( V_248 >= V_2 -> V_119 ||
V_53 -> V_55 + V_53 -> V_56 >
( ( V_2 -> V_119 >> V_6 -> V_38 ) -
( V_248 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_17 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_248 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_30 = ( int ) ( V_248 >> V_6 -> V_38 ) ;
V_6 -> V_45 ( V_2 , V_97 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
return - V_256 ;
}
if ( V_30 == V_6 -> V_209 )
V_6 -> V_209 = - 1 ;
F_101 ( V_2 , V_53 -> V_54 , V_53 -> V_56 , V_53 ) ;
if ( V_53 -> V_57 == V_185 )
V_112 = V_6 -> V_134 . V_257 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
else
V_112 = V_6 -> V_134 . V_258 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
if ( V_112 )
return V_112 ;
V_53 -> V_218 = V_53 -> V_56 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_248 ,
struct V_52 * V_53 )
{
int V_8 = - V_230 ;
V_53 -> V_217 = 0 ;
if ( V_53 -> V_206 && ( V_248 + V_53 -> V_4 ) > V_2 -> V_119 ) {
F_2 ( L_17 ,
V_10 ) ;
return - V_11 ;
}
F_26 ( V_2 , V_63 ) ;
switch ( V_53 -> V_57 ) {
case V_58 :
case V_186 :
case V_185 :
break;
default:
goto V_79;
}
if ( ! V_53 -> V_206 )
V_8 = F_30 ( V_2 , V_248 , V_53 ) ;
else
V_8 = F_102 ( V_2 , V_248 , V_53 ) ;
V_79:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_108 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_45 ( V_2 , V_95 , - 1 , V_30 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
return V_6 -> V_116 ( V_2 , V_6 ) ;
}
static int F_109 ( struct V_1 * V_2 , struct V_60 * V_259 )
{
return F_32 ( V_2 , V_259 , 0 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_60 * V_259 ,
int V_71 )
{
int V_30 , V_112 , V_260 , V_8 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 ;
F_2 ( L_5 ,
V_10 , ( unsigned long long ) V_259 -> V_62 ,
( unsigned long long ) V_259 -> V_4 ) ;
if ( F_1 ( V_2 , V_259 -> V_62 , V_259 -> V_4 ) )
return - V_11 ;
F_26 ( V_2 , V_261 ) ;
V_30 = ( int ) ( V_259 -> V_62 >> V_6 -> V_38 ) ;
V_19 = ( int ) ( V_259 -> V_62 >> V_6 -> V_40 ) ;
V_260 = 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_6 ,
V_10 ) ;
V_259 -> V_15 = V_122 ;
goto V_262;
}
V_4 = V_259 -> V_4 ;
V_259 -> V_15 = V_263 ;
while ( V_4 ) {
if ( F_37 ( V_2 , ( ( T_1 ) V_30 ) <<
V_6 -> V_38 , 0 , V_71 ) ) {
F_110 ( L_18 ,
V_10 , V_30 ) ;
V_259 -> V_15 = V_122 ;
goto V_262;
}
if ( V_30 <= V_6 -> V_209 && V_6 -> V_209 <
( V_30 + V_260 ) )
V_6 -> V_209 = - 1 ;
V_112 = V_6 -> V_264 ( V_2 , V_30 & V_6 -> V_39 ) ;
if ( ( V_112 & V_117 ) && ( V_6 -> V_246 ) )
V_112 = V_6 -> V_246 ( V_2 , V_6 , V_261 ,
V_112 , V_30 ) ;
if ( V_112 & V_117 ) {
F_2 ( L_19 ,
V_10 , V_30 ) ;
V_259 -> V_15 = V_122 ;
V_259 -> V_265 =
( ( T_1 ) V_30 << V_6 -> V_38 ) ;
goto V_262;
}
V_4 -= ( 1ULL << V_6 -> V_9 ) ;
V_30 += V_260 ;
if ( V_4 && ! ( V_30 & V_6 -> V_39 ) ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_259 -> V_15 = V_266 ;
V_262:
V_8 = V_259 -> V_15 == V_266 ? 0 : - V_118 ;
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
if ( ! V_8 )
F_111 ( V_259 ) ;
return V_8 ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_2 ( L_20 , V_10 ) ;
F_26 ( V_2 , V_267 ) ;
F_3 ( V_2 ) ;
}
static int F_113 ( struct V_1 * V_2 , T_1 V_268 )
{
return F_37 ( V_2 , V_268 , 1 , 0 ) ;
}
static int F_114 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
V_8 = F_113 ( V_2 , V_3 ) ;
if ( V_8 ) {
if ( V_8 > 0 )
return 0 ;
return V_8 ;
}
return F_31 ( V_2 , V_3 ) ;
}
static int F_115 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_62 , T_3 * V_269 )
{
int V_112 ;
int V_32 ;
if ( ! V_6 -> V_270 ||
! ( F_116 ( V_6 -> V_271 . V_272 )
& V_273 ) )
return - V_11 ;
V_6 -> V_45 ( V_2 , V_274 , V_62 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_275 ; ++ V_32 )
V_6 -> V_276 ( V_2 , V_269 [ V_32 ] ) ;
V_112 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( V_112 & V_117 )
return - V_118 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_62 , T_3 * V_269 )
{
int V_32 ;
if ( ! V_6 -> V_270 ||
! ( F_116 ( V_6 -> V_271 . V_272 )
& V_273 ) )
return - V_11 ;
V_6 -> V_45 ( V_2 , V_277 , V_62 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_275 ; ++ V_32 )
* V_269 ++ = V_6 -> V_49 ( V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_110 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_15 == V_110 )
F_3 ( V_2 ) ;
else
F_120 ( L_21 ,
V_10 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_26 ( V_2 , V_110 ) ;
}
static void F_122 ( struct V_5 * V_6 , int V_180 )
{
if ( ! V_6 -> V_98 )
V_6 -> V_98 = 20 ;
if ( V_6 -> V_45 == NULL )
V_6 -> V_45 = F_50 ;
if ( V_6 -> V_116 == NULL )
V_6 -> V_116 = F_62 ;
if ( ! V_6 -> V_42 )
V_6 -> V_42 = F_13 ;
if ( ! V_6 -> V_278 )
V_6 -> V_278 = F_115 ;
if ( ! V_6 -> V_279 )
V_6 -> V_279 = F_117 ;
if ( ! V_6 -> V_49 || V_6 -> V_49 == F_7 )
V_6 -> V_49 = V_180 ? F_9 : F_7 ;
if ( ! V_6 -> V_48 )
V_6 -> V_48 = F_12 ;
if ( ! V_6 -> V_72 )
V_6 -> V_72 = F_25 ;
if ( ! V_6 -> V_64 )
V_6 -> V_64 = F_29 ;
if ( ! V_6 -> V_24 || V_6 -> V_24 == F_17 )
V_6 -> V_24 = V_180 ? F_21 : F_17 ;
if ( ! V_6 -> V_276 || V_6 -> V_276 == F_15 )
V_6 -> V_276 = V_180 ? F_16 : F_15 ;
if ( ! V_6 -> V_142 || V_6 -> V_142 == F_19 )
V_6 -> V_142 = V_180 ? F_23 : F_19 ;
if ( ! V_6 -> V_280 )
V_6 -> V_280 = V_281 ;
if ( ! V_6 -> V_12 ) {
V_6 -> V_12 = & V_6 -> V_282 ;
F_123 ( & V_6 -> V_12 -> V_13 ) ;
F_124 ( & V_6 -> V_12 -> V_17 ) ;
}
}
static void F_125 ( T_3 * V_283 , T_9 V_4 )
{
T_10 V_32 ;
V_283 [ V_4 - 1 ] = 0 ;
for ( V_32 = 0 ; V_32 < V_4 - 1 ; V_32 ++ ) {
if ( V_283 [ V_32 ] < ' ' || V_283 [ V_32 ] > 127 )
V_283 [ V_32 ] = '?' ;
}
F_126 ( V_283 ) ;
}
static T_4 F_127 ( T_4 V_284 , T_11 const * V_28 , T_9 V_4 )
{
int V_32 ;
while ( V_4 -- ) {
V_284 ^= * V_28 ++ << 8 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_284 = ( V_284 << 1 ) ^ ( ( V_284 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_284 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_285 * V_28 )
{
struct V_286 * V_287 ;
struct V_288 * V_283 ;
struct V_289 * V_134 ;
T_3 * V_290 ;
int V_8 = - V_11 ;
int V_4 ;
int V_32 ;
V_4 = F_116 ( V_28 -> V_291 ) * 16 ;
V_287 = F_129 ( V_4 , V_292 ) ;
if ( ! V_287 )
return - V_293 ;
V_6 -> V_45 ( V_2 , V_294 , 0 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_103 ,
sizeof( * V_28 ) * V_28 -> V_295 , - 1 ) ;
V_6 -> V_142 ( V_2 , ( T_3 * ) V_287 , V_4 ) ;
if ( ( F_127 ( V_296 , ( ( T_3 * ) V_287 ) + 2 , V_4 - 2 )
!= F_116 ( V_287 -> V_284 ) ) ) {
F_2 ( L_22 ) ;
goto V_297;
}
if ( strncmp ( V_287 -> V_298 , L_23 , 4 ) ) {
F_2 ( L_24 ) ;
goto V_297;
}
V_290 = ( T_3 * ) ( V_287 + 1 ) ;
for ( V_32 = 0 ; V_32 < V_299 ; V_32 ++ ) {
V_283 = V_287 -> V_300 + V_32 ;
if ( V_283 -> type == V_301 )
break;
V_290 += V_283 -> V_191 * 16 ;
}
if ( V_32 == V_299 ) {
F_2 ( L_25 ) ;
goto V_297;
}
V_134 = (struct V_289 * ) V_290 ;
if ( ! V_134 -> V_302 ) {
F_2 ( L_26 ) ;
goto V_297;
}
V_6 -> V_303 = V_134 -> V_304 ;
V_6 -> V_305 = 1 << V_134 -> V_302 ;
V_8 = 0 ;
V_297:
F_130 ( V_287 ) ;
return V_8 ;
}
static int F_131 ( struct V_1 * V_2 , int V_193 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_306 [ V_275 ] = { V_193 } ;
return V_6 -> V_278 ( V_2 , V_6 , V_307 ,
V_306 ) ;
}
static void F_132 ( struct V_5 * V_6 ,
struct V_285 * V_28 )
{
struct V_308 * V_309 = ( void * ) V_28 -> V_310 ;
if ( F_116 ( V_28 -> V_311 ) < 1 )
return;
V_6 -> V_194 = V_309 -> V_312 ;
V_6 -> V_195 = F_131 ;
}
static int F_133 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_180 )
{
struct V_285 * V_28 = & V_6 -> V_271 ;
int V_32 , V_313 ;
int V_314 ;
V_6 -> V_45 ( V_2 , V_315 , 0x20 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'O' || V_6 -> V_49 ( V_2 ) != 'N' ||
V_6 -> V_49 ( V_2 ) != 'F' || V_6 -> V_49 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_45 ( V_2 , V_294 , 0 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
for ( V_313 = 0 ; V_313 < sizeof( * V_28 ) ; V_313 ++ )
( ( T_3 * ) V_28 ) [ V_313 ] = V_6 -> V_49 ( V_2 ) ;
if ( F_127 ( V_296 , ( T_3 * ) V_28 , 254 ) ==
F_116 ( V_28 -> V_284 ) ) {
break;
}
}
if ( V_32 == 3 ) {
F_120 ( L_27 ) ;
return 0 ;
}
V_314 = F_116 ( V_28 -> V_316 ) ;
if ( V_314 & ( 1 << 5 ) )
V_6 -> V_270 = 23 ;
else if ( V_314 & ( 1 << 4 ) )
V_6 -> V_270 = 22 ;
else if ( V_314 & ( 1 << 3 ) )
V_6 -> V_270 = 21 ;
else if ( V_314 & ( 1 << 2 ) )
V_6 -> V_270 = 20 ;
else if ( V_314 & ( 1 << 1 ) )
V_6 -> V_270 = 10 ;
if ( ! V_6 -> V_270 ) {
F_134 ( L_28 , V_314 ) ;
return 0 ;
}
F_125 ( V_28 -> V_317 , sizeof( V_28 -> V_317 ) ) ;
F_125 ( V_28 -> V_318 , sizeof( V_28 -> V_318 ) ) ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = V_28 -> V_318 ;
V_2 -> V_37 = F_135 ( V_28 -> V_320 ) ;
V_2 -> V_36 = 1 << ( F_136 ( F_135 ( V_28 -> V_260 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_144 = F_116 ( V_28 -> V_321 ) ;
V_6 -> V_92 = 1 << ( F_136 ( F_135 ( V_28 -> V_322 ) ) - 1 ) ;
V_6 -> V_92 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_323 ;
V_6 -> V_324 = V_28 -> V_324 ;
if ( F_137 ( V_6 ) & V_325 )
* V_180 = V_44 ;
else
* V_180 = 0 ;
if ( V_28 -> V_304 != 0xff ) {
V_6 -> V_303 = V_28 -> V_304 ;
V_6 -> V_305 = 512 ;
} else if ( V_6 -> V_270 >= 21 &&
( F_137 ( V_6 ) & V_326 ) ) {
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_50 )
V_6 -> V_45 = F_54 ;
if ( F_128 ( V_2 , V_6 , V_28 ) )
F_110 ( L_29 ) ;
} else {
F_110 ( L_30 ) ;
}
if ( V_28 -> V_327 == V_328 )
F_132 ( V_6 , V_28 ) ;
return 1 ;
}
static int F_138 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_180 )
{
struct V_329 * V_28 = & V_6 -> V_330 ;
struct V_331 * V_134 ;
int V_314 ;
int V_32 , V_313 ;
V_6 -> V_45 ( V_2 , V_315 , 0x40 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'J' || V_6 -> V_49 ( V_2 ) != 'E' ||
V_6 -> V_49 ( V_2 ) != 'D' || V_6 -> V_49 ( V_2 ) != 'E' ||
V_6 -> V_49 ( V_2 ) != 'C' )
return 0 ;
V_6 -> V_45 ( V_2 , V_294 , 0x40 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
for ( V_313 = 0 ; V_313 < sizeof( * V_28 ) ; V_313 ++ )
( ( T_3 * ) V_28 ) [ V_313 ] = V_6 -> V_49 ( V_2 ) ;
if ( F_127 ( V_296 , ( T_3 * ) V_28 , 510 ) ==
F_116 ( V_28 -> V_284 ) )
break;
}
if ( V_32 == 3 ) {
F_120 ( L_31 ) ;
return 0 ;
}
V_314 = F_116 ( V_28 -> V_316 ) ;
if ( V_314 & ( 1 << 2 ) )
V_6 -> V_332 = 10 ;
else if ( V_314 & ( 1 << 1 ) )
V_6 -> V_332 = 1 ;
if ( ! V_6 -> V_332 ) {
F_134 ( L_32 , V_314 ) ;
return 0 ;
}
F_125 ( V_28 -> V_317 , sizeof( V_28 -> V_317 ) ) ;
F_125 ( V_28 -> V_318 , sizeof( V_28 -> V_318 ) ) ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = V_28 -> V_318 ;
V_2 -> V_37 = F_135 ( V_28 -> V_320 ) ;
V_2 -> V_36 = 1 << ( F_136 ( F_135 ( V_28 -> V_260 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_144 = F_116 ( V_28 -> V_321 ) ;
V_6 -> V_92 = 1 << ( F_136 ( F_135 ( V_28 -> V_322 ) ) - 1 ) ;
V_6 -> V_92 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_323 ;
V_6 -> V_324 = V_28 -> V_324 ;
if ( F_139 ( V_6 ) & V_333 )
* V_180 = V_44 ;
else
* V_180 = 0 ;
V_134 = & V_28 -> V_334 [ 0 ] ;
if ( V_134 -> V_302 >= 9 ) {
V_6 -> V_303 = V_134 -> V_304 ;
V_6 -> V_305 = 1 << V_134 -> V_302 ;
} else {
F_110 ( L_26 ) ;
}
return 1 ;
}
static int F_140 ( T_11 * V_335 , int V_336 , int V_337 )
{
int V_32 , V_313 ;
for ( V_32 = 0 ; V_32 < V_337 ; V_32 ++ )
for ( V_313 = V_32 + V_337 ; V_313 < V_336 ; V_313 += V_337 )
if ( V_335 [ V_32 ] != V_335 [ V_313 ] )
return 0 ;
return 1 ;
}
static int F_141 ( T_11 * V_335 , int V_336 )
{
int V_338 , V_337 ;
for ( V_338 = V_336 - 1 ; V_338 >= 0 ; V_338 -- )
if ( V_335 [ V_338 ] )
break;
if ( V_338 < 0 )
return 0 ;
for ( V_337 = 1 ; V_337 < V_336 ; V_337 ++ )
if ( F_140 ( V_335 , V_336 , V_337 ) )
break;
if ( V_337 < V_336 )
return V_337 ;
if ( V_338 < V_336 - 1 )
return V_338 + 1 ;
return V_336 ;
}
static int F_142 ( T_11 V_339 )
{
int V_340 ;
V_340 = V_339 & V_341 ;
V_340 >>= V_342 ;
return V_340 + 1 ;
}
static void F_143 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_11 V_335 [ 8 ] , int * V_180 )
{
int V_343 , V_344 ;
V_6 -> V_324 = F_142 ( V_335 [ 2 ] ) ;
V_343 = V_335 [ 3 ] ;
V_344 = F_141 ( V_335 , 8 ) ;
if ( V_344 == 6 && V_335 [ 0 ] == V_345 &&
! F_144 ( V_6 ) && V_335 [ 5 ] != 0x00 ) {
V_2 -> V_37 = 2048 << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
switch ( ( ( V_343 >> 2 ) & 0x04 ) | ( V_343 & 0x03 ) ) {
case 1 :
V_2 -> V_144 = 128 ;
break;
case 2 :
V_2 -> V_144 = 218 ;
break;
case 3 :
V_2 -> V_144 = 400 ;
break;
case 4 :
V_2 -> V_144 = 436 ;
break;
case 5 :
V_2 -> V_144 = 512 ;
break;
case 6 :
V_2 -> V_144 = 640 ;
break;
case 7 :
default:
V_2 -> V_144 = 1024 ;
break;
}
V_343 >>= 2 ;
V_2 -> V_36 = ( 128 * 1024 ) <<
( ( ( V_343 >> 1 ) & 0x04 ) | ( V_343 & 0x03 ) ) ;
* V_180 = 0 ;
} else if ( V_344 == 6 && V_335 [ 0 ] == V_346 &&
! F_144 ( V_6 ) ) {
unsigned int V_347 ;
V_2 -> V_37 = 2048 << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
switch ( ( ( V_343 >> 2 ) & 0x04 ) | ( V_343 & 0x03 ) ) {
case 0 :
V_2 -> V_144 = 128 ;
break;
case 1 :
V_2 -> V_144 = 224 ;
break;
case 2 :
V_2 -> V_144 = 448 ;
break;
case 3 :
V_2 -> V_144 = 64 ;
break;
case 4 :
V_2 -> V_144 = 32 ;
break;
case 5 :
V_2 -> V_144 = 16 ;
break;
default:
V_2 -> V_144 = 640 ;
break;
}
V_343 >>= 2 ;
V_347 = ( ( V_343 >> 1 ) & 0x04 ) | ( V_343 & 0x03 ) ;
if ( V_347 < 0x03 )
V_2 -> V_36 = ( 128 * 1024 ) << V_347 ;
else if ( V_347 == 0x03 )
V_2 -> V_36 = 768 * 1024 ;
else
V_2 -> V_36 = ( 64 * 1024 ) << V_347 ;
* V_180 = 0 ;
} else {
V_2 -> V_37 = 1024 << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
V_2 -> V_144 = ( 8 << ( V_343 & 0x01 ) ) *
( V_2 -> V_37 >> 9 ) ;
V_343 >>= 2 ;
V_2 -> V_36 = ( 64 * 1024 ) << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
* V_180 = ( V_343 & 0x01 ) ? V_44 : 0 ;
if ( V_344 >= 6 && V_335 [ 0 ] == V_348 &&
F_144 ( V_6 ) &&
( V_335 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_335 [ 4 ] & 0x80 ) ) {
V_2 -> V_144 = 32 * V_2 -> V_37 >> 9 ;
}
}
}
static void F_145 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_349 * type , T_11 V_335 [ 8 ] ,
int * V_180 )
{
int V_350 = V_335 [ 0 ] ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_37 = type -> V_351 ;
V_2 -> V_144 = V_2 -> V_37 / 32 ;
* V_180 = type -> V_43 & V_44 ;
V_6 -> V_324 = 1 ;
if ( V_350 == V_352 && V_335 [ 4 ] != 0x00 && V_335 [ 5 ] == 0x00
&& V_335 [ 6 ] == 0x00 && V_335 [ 7 ] == 0x00
&& V_2 -> V_37 == 512 ) {
V_2 -> V_36 = 128 * 1024 ;
V_2 -> V_36 <<= ( ( V_335 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_146 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_11 V_335 [ 8 ] )
{
int V_350 = V_335 [ 0 ] ;
if ( V_2 -> V_37 > 512 || ( V_6 -> V_43 & V_44 ) )
V_6 -> V_47 = V_353 ;
else
V_6 -> V_47 = V_354 ;
if ( ! F_144 ( V_6 ) &&
( V_350 == V_345 ||
V_350 == V_346 ) )
V_6 -> V_34 |= V_35 ;
else if ( ( F_144 ( V_6 ) &&
( V_350 == V_345 ||
V_350 == V_346 ||
V_350 == V_348 ||
V_350 == V_352 ||
V_350 == V_355 ) ) ||
( V_2 -> V_37 == 2048 &&
V_350 == V_328 ) )
V_6 -> V_34 |= V_51 ;
}
static inline bool F_147 ( struct V_349 * type )
{
return type -> V_344 ;
}
static bool F_148 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_349 * type , T_11 * V_335 , int * V_180 )
{
if ( ! strncmp ( type -> V_356 , V_335 , type -> V_344 ) ) {
V_2 -> V_37 = type -> V_351 ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_144 = type -> V_144 ;
V_6 -> V_324 = F_142 ( V_335 [ 2 ] ) ;
V_6 -> V_92 = ( T_2 ) type -> V_92 << 20 ;
V_6 -> V_43 |= type -> V_43 ;
V_6 -> V_303 = F_149 ( type ) ;
V_6 -> V_305 = F_150 ( type ) ;
V_6 -> V_357 =
type -> V_357 ;
* V_180 = type -> V_43 & V_44 ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = type -> V_319 ;
return true ;
}
return false ;
}
static struct V_349 * F_151 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int * V_350 , int * V_358 ,
struct V_349 * type )
{
int V_180 ;
int V_32 , V_359 ;
T_11 V_335 [ 8 ] ;
V_6 -> V_42 ( V_2 , 0 ) ;
V_6 -> V_45 ( V_2 , V_97 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_315 , 0x00 , - 1 ) ;
* V_350 = V_6 -> V_49 ( V_2 ) ;
* V_358 = V_6 -> V_49 ( V_2 ) ;
V_6 -> V_45 ( V_2 , V_315 , 0x00 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_335 [ V_32 ] = V_6 -> V_49 ( V_2 ) ;
if ( V_335 [ 0 ] != * V_350 || V_335 [ 1 ] != * V_358 ) {
F_134 ( L_33 ,
* V_350 , * V_358 , V_335 [ 0 ] , V_335 [ 1 ] ) ;
return F_152 ( - V_360 ) ;
}
if ( ! type )
type = V_361 ;
for (; type -> V_319 != NULL ; type ++ ) {
if ( F_147 ( type ) ) {
if ( F_148 ( V_2 , V_6 , type , V_335 , & V_180 ) )
goto V_362;
} else if ( * V_358 == type -> V_358 ) {
break;
}
}
V_6 -> V_270 = 0 ;
if ( ! type -> V_319 || ! type -> V_351 ) {
if ( F_133 ( V_2 , V_6 , & V_180 ) )
goto V_362;
if ( F_138 ( V_2 , V_6 , & V_180 ) )
goto V_362;
}
if ( ! type -> V_319 )
return F_152 ( - V_360 ) ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = type -> V_319 ;
V_6 -> V_92 = ( T_2 ) type -> V_92 << 20 ;
if ( ! type -> V_351 ) {
F_143 ( V_2 , V_6 , V_335 , & V_180 ) ;
} else {
F_145 ( V_2 , V_6 , type , V_335 , & V_180 ) ;
}
V_6 -> V_43 |= type -> V_43 ;
if ( * V_350 != V_345 && ! type -> V_351 )
V_6 -> V_43 &= ~ V_363 ;
V_362:
for ( V_359 = 0 ; V_364 [ V_359 ] . V_356 != 0x0 ; V_359 ++ ) {
if ( V_364 [ V_359 ] . V_356 == * V_350 )
break;
}
if ( V_6 -> V_43 & V_365 ) {
F_63 ( V_6 -> V_43 & V_44 ) ;
V_6 -> V_43 |= V_180 ;
F_122 ( V_6 , V_180 ) ;
} else if ( V_180 != ( V_6 -> V_43 & V_44 ) ) {
F_134 ( L_34 ,
* V_350 , * V_358 ) ;
F_134 ( L_35 , V_364 [ V_359 ] . V_319 , V_2 -> V_319 ) ;
F_110 ( L_36 ,
( V_6 -> V_43 & V_44 ) ? 16 : 8 ,
V_180 ? 16 : 8 ) ;
return F_152 ( - V_11 ) ;
}
F_146 ( V_2 , V_6 , V_335 ) ;
V_6 -> V_38 = F_153 ( V_2 -> V_37 ) - 1 ;
V_6 -> V_39 = ( V_6 -> V_92 >> V_6 -> V_38 ) - 1 ;
V_6 -> V_366 = V_6 -> V_9 =
F_153 ( V_2 -> V_36 ) - 1 ;
if ( V_6 -> V_92 & 0xffffffff )
V_6 -> V_40 = F_153 ( ( unsigned ) V_6 -> V_92 ) - 1 ;
else {
V_6 -> V_40 = F_153 ( ( unsigned ) ( V_6 -> V_92 >> 32 ) ) ;
V_6 -> V_40 += 32 - 1 ;
}
V_6 -> V_50 = 8 ;
V_6 -> V_264 = F_108 ;
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_50 )
V_6 -> V_45 = F_54 ;
F_134 ( L_34 ,
* V_350 , * V_358 ) ;
if ( V_6 -> V_270 )
F_134 ( L_35 , V_364 [ V_359 ] . V_319 ,
V_6 -> V_271 . V_318 ) ;
else if ( V_6 -> V_332 )
F_134 ( L_35 , V_364 [ V_359 ] . V_319 ,
V_6 -> V_330 . V_318 ) ;
else
F_134 ( L_35 , V_364 [ V_359 ] . V_319 ,
type -> V_319 ) ;
F_134 ( L_37 ,
( int ) ( V_6 -> V_92 >> 20 ) , F_144 ( V_6 ) ? L_38 : L_39 ,
V_2 -> V_36 >> 10 , V_2 -> V_37 , V_2 -> V_144 ) ;
return type ;
}
static int F_154 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_367 * V_368 )
{
int V_369 , V_370 , V_371 ;
if ( F_155 ( V_368 ) == 16 )
V_6 -> V_43 |= V_44 ;
if ( F_156 ( V_368 ) )
V_6 -> V_34 |= V_372 ;
V_369 = F_157 ( V_368 ) ;
V_370 = F_158 ( V_368 ) ;
V_371 = F_159 ( V_368 ) ;
if ( ( V_371 >= 0 && ! ( V_370 >= 0 ) ) ||
( ! ( V_371 >= 0 ) && V_370 >= 0 ) ) {
F_120 ( L_40 ) ;
return - V_11 ;
}
if ( V_369 >= 0 )
V_6 -> V_134 . V_57 = V_369 ;
if ( V_370 >= 0 )
V_6 -> V_134 . V_373 = V_370 ;
if ( V_371 > 0 )
V_6 -> V_134 . V_119 = V_371 ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 , int V_374 ,
struct V_349 * V_375 )
{
int V_32 , V_376 , V_377 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_349 * type ;
int V_8 ;
if ( V_6 -> V_378 ) {
V_8 = F_154 ( V_2 , V_6 , V_6 -> V_378 ) ;
if ( V_8 )
return V_8 ;
}
F_122 ( V_6 , V_6 -> V_43 & V_44 ) ;
type = F_151 ( V_2 , V_6 , & V_376 ,
& V_377 , V_375 ) ;
if ( F_161 ( type ) ) {
if ( ! ( V_6 -> V_43 & V_379 ) )
F_110 ( L_41 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
return F_162 ( type ) ;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
for ( V_32 = 1 ; V_32 < V_374 ; V_32 ++ ) {
V_6 -> V_42 ( V_2 , V_32 ) ;
V_6 -> V_45 ( V_2 , V_97 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_315 , 0x00 , - 1 ) ;
if ( V_376 != V_6 -> V_49 ( V_2 ) ||
V_377 != V_6 -> V_49 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
break;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
}
if ( V_32 > 1 )
F_134 ( L_42 , V_32 ) ;
V_6 -> V_380 = V_32 ;
V_2 -> V_119 = V_32 * V_6 -> V_92 ;
return 0 ;
}
static bool F_163 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_381 * V_134 = & V_6 -> V_134 ;
int V_382 , V_383 ;
if ( V_134 -> V_119 == 0 || V_6 -> V_305 == 0 )
return true ;
V_382 = ( V_2 -> V_37 * V_134 -> V_373 ) / V_134 -> V_119 ;
V_383 = ( V_2 -> V_37 * V_6 -> V_303 ) / V_6 -> V_305 ;
return V_382 >= V_383 && V_134 -> V_373 >= V_6 -> V_303 ;
}
int F_164 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_381 * V_134 = & V_6 -> V_134 ;
struct V_384 * V_385 ;
F_165 ( ( V_6 -> V_34 & V_59 ) &&
! ( V_6 -> V_34 & V_372 ) ) ;
if ( ! ( V_6 -> V_43 & V_386 ) ) {
V_385 = F_166 ( sizeof( * V_385 ) + V_2 -> V_37
+ V_2 -> V_144 * 3 , V_292 ) ;
if ( ! V_385 )
return - V_293 ;
V_385 -> V_155 = ( T_3 * ) ( V_385 + 1 ) ;
V_385 -> V_157 = V_385 -> V_155 + V_2 -> V_144 ;
V_385 -> V_210 = V_385 -> V_157 + V_2 -> V_144 ;
V_6 -> V_154 = V_385 ;
} else {
if ( ! V_6 -> V_154 )
return - V_293 ;
}
V_6 -> V_143 = V_6 -> V_154 -> V_210 + V_2 -> V_37 ;
if ( ! V_134 -> V_159 && ( V_134 -> V_57 != V_387 ) ) {
switch ( V_2 -> V_144 ) {
case 8 :
V_134 -> V_159 = & V_388 ;
break;
case 16 :
V_134 -> V_159 = & V_389 ;
break;
case 64 :
V_134 -> V_159 = & V_390 ;
break;
case 128 :
V_134 -> V_159 = & V_391 ;
break;
default:
F_110 ( L_43 ,
V_2 -> V_144 ) ;
F_14 () ;
}
}
if ( ! V_6 -> V_245 )
V_6 -> V_245 = F_99 ;
switch ( V_134 -> V_57 ) {
case V_392 :
if ( ! V_134 -> V_162 || ! V_134 -> V_165 || ! V_134 -> V_182 ) {
F_110 ( L_44 ) ;
F_14 () ;
}
if ( ! V_134 -> V_213 )
V_134 -> V_213 = F_77 ;
case V_393 :
if ( ! V_134 -> V_213 )
V_134 -> V_213 = F_76 ;
if ( ! V_134 -> V_245 )
V_134 -> V_245 = F_96 ;
if ( ! V_134 -> V_161 )
V_134 -> V_161 = F_71 ;
if ( ! V_134 -> V_231 )
V_134 -> V_231 = F_93 ;
if ( ! V_134 -> V_228 )
V_134 -> V_228 = F_87 ;
if ( ! V_134 -> V_258 )
V_134 -> V_258 = F_89 ;
if ( ! V_134 -> V_212 )
V_134 -> V_212 = F_75 ;
if ( ! V_134 -> V_244 )
V_134 -> V_244 = F_97 ;
case V_394 :
if ( ( ! V_134 -> V_162 || ! V_134 -> V_165 || ! V_134 -> V_182 ) &&
( ! V_134 -> V_213 ||
V_134 -> V_213 == F_76 ||
! V_134 -> V_245 ||
V_134 -> V_245 == F_96 ) ) {
F_110 ( L_44 ) ;
F_14 () ;
}
if ( ! V_134 -> V_213 )
V_134 -> V_213 = F_78 ;
if ( ! V_134 -> V_245 )
V_134 -> V_245 = F_98 ;
if ( ! V_134 -> V_161 )
V_134 -> V_161 = F_72 ;
if ( ! V_134 -> V_231 )
V_134 -> V_231 = F_94 ;
if ( ! V_134 -> V_228 )
V_134 -> V_228 = F_88 ;
if ( ! V_134 -> V_258 )
V_134 -> V_258 = F_90 ;
if ( V_2 -> V_37 >= V_134 -> V_119 ) {
if ( ! V_134 -> V_373 ) {
F_110 ( L_45 ) ;
F_14 () ;
}
break;
}
F_110 ( L_46 ,
V_134 -> V_119 , V_2 -> V_37 ) ;
V_134 -> V_57 = V_395 ;
case V_395 :
V_134 -> V_162 = V_396 ;
V_134 -> V_165 = V_397 ;
V_134 -> V_213 = F_73 ;
V_134 -> V_212 = F_75 ;
V_134 -> V_245 = F_95 ;
V_134 -> V_161 = F_71 ;
V_134 -> V_231 = F_93 ;
V_134 -> V_228 = F_87 ;
V_134 -> V_258 = F_89 ;
if ( ! V_134 -> V_119 )
V_134 -> V_119 = 256 ;
V_134 -> V_147 = 3 ;
V_134 -> V_373 = 1 ;
break;
case V_387 :
if ( ! F_167 () ) {
F_110 ( L_47 ) ;
F_14 () ;
}
V_134 -> V_162 = V_398 ;
V_134 -> V_165 = V_399 ;
V_134 -> V_213 = F_73 ;
V_134 -> V_212 = F_75 ;
V_134 -> V_245 = F_95 ;
V_134 -> V_161 = F_71 ;
V_134 -> V_231 = F_93 ;
V_134 -> V_228 = F_87 ;
V_134 -> V_258 = F_89 ;
if ( ! V_134 -> V_119 && ( V_2 -> V_144 >= 64 ) ) {
V_134 -> V_119 = 512 ;
V_134 -> V_373 = 4 ;
}
V_134 -> V_147 = F_168 (
V_134 -> V_373 * F_136 ( 8 * V_134 -> V_119 ) , 8 ) ;
V_134 -> V_7 = F_169 ( V_2 , V_134 -> V_119 , V_134 -> V_147 ,
& V_134 -> V_159 ) ;
if ( ! V_134 -> V_7 ) {
F_110 ( L_48 ) ;
F_14 () ;
}
break;
case V_400 :
F_110 ( L_49 ) ;
V_134 -> V_213 = F_71 ;
V_134 -> V_245 = F_93 ;
V_134 -> V_228 = F_87 ;
V_134 -> V_161 = F_71 ;
V_134 -> V_231 = F_93 ;
V_134 -> V_258 = F_89 ;
V_134 -> V_119 = V_2 -> V_37 ;
V_134 -> V_147 = 0 ;
V_134 -> V_373 = 0 ;
break;
default:
F_110 ( L_50 , V_134 -> V_57 ) ;
F_14 () ;
}
if ( ! V_134 -> V_227 )
V_134 -> V_227 = V_134 -> V_228 ;
if ( ! V_134 -> V_257 )
V_134 -> V_257 = V_134 -> V_258 ;
V_134 -> V_159 -> V_203 = 0 ;
for ( V_32 = 0 ; V_134 -> V_159 -> V_188 [ V_32 ] . V_191
&& V_32 < F_170 ( V_134 -> V_159 -> V_188 ) ; V_32 ++ )
V_134 -> V_159 -> V_203 += V_134 -> V_159 -> V_188 [ V_32 ] . V_191 ;
V_2 -> V_203 = V_134 -> V_159 -> V_203 ;
if ( ! F_163 ( V_2 ) )
F_110 ( L_51 ,
V_2 -> V_319 ) ;
V_134 -> V_149 = V_2 -> V_37 / V_134 -> V_119 ;
if ( V_134 -> V_149 * V_134 -> V_119 != V_2 -> V_37 ) {
F_110 ( L_52 ) ;
F_14 () ;
}
V_134 -> V_163 = V_134 -> V_149 * V_134 -> V_147 ;
if ( ! ( V_6 -> V_43 & V_243 ) && F_144 ( V_6 ) ) {
switch ( V_134 -> V_149 ) {
case 2 :
V_2 -> V_401 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_401 = 2 ;
break;
}
}
V_6 -> V_402 = V_2 -> V_37 >> V_2 -> V_401 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_209 = - 1 ;
switch ( V_134 -> V_57 ) {
case V_395 :
case V_387 :
if ( V_6 -> V_38 > 9 )
V_6 -> V_43 |= V_403 ;
break;
default:
break;
}
V_2 -> type = F_144 ( V_6 ) ? V_404 : V_405 ;
V_2 -> V_406 = ( V_6 -> V_43 & V_407 ) ? V_408 :
V_409 ;
V_2 -> V_410 = F_109 ;
V_2 -> V_411 = NULL ;
V_2 -> V_412 = NULL ;
V_2 -> V_413 = F_86 ;
V_2 -> V_414 = F_106 ;
V_2 -> V_415 = F_105 ;
V_2 -> V_416 = F_92 ;
V_2 -> V_417 = F_107 ;
V_2 -> V_418 = F_112 ;
V_2 -> V_419 = NULL ;
V_2 -> V_420 = NULL ;
V_2 -> V_421 = F_118 ;
V_2 -> V_422 = F_119 ;
V_2 -> V_423 = F_121 ;
V_2 -> V_424 = F_35 ;
V_2 -> V_425 = F_113 ;
V_2 -> V_426 = F_114 ;
V_2 -> V_427 = V_2 -> V_37 ;
V_2 -> V_428 = V_134 -> V_159 ;
V_2 -> V_370 = V_134 -> V_373 ;
V_2 -> V_429 = V_134 -> V_119 ;
if ( ! V_2 -> V_430 )
V_2 -> V_430 = F_168 ( V_2 -> V_370 * 3 , 4 ) ;
if ( V_6 -> V_43 & V_431 )
return 0 ;
return V_6 -> V_280 ( V_2 ) ;
}
int F_171 ( struct V_1 * V_2 , int V_374 )
{
int V_8 ;
if ( ! V_2 -> V_432 && F_172 () ) {
F_173 ( L_53 , V_10 ) ;
F_14 () ;
}
V_8 = F_160 ( V_2 , V_374 , NULL ) ;
if ( ! V_8 )
V_8 = F_164 ( V_2 ) ;
return V_8 ;
}
void F_174 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_134 . V_57 == V_387 )
F_175 ( (struct V_433 * ) V_6 -> V_134 . V_7 ) ;
F_176 ( V_2 ) ;
F_130 ( V_6 -> V_65 ) ;
if ( ! ( V_6 -> V_43 & V_386 ) )
F_130 ( V_6 -> V_154 ) ;
if ( V_6 -> V_434 && V_6 -> V_434 -> V_43
& V_435 )
F_130 ( V_6 -> V_434 ) ;
}
static int T_12 F_177 ( void )
{
F_178 ( L_54 , & V_76 ) ;
return 0 ;
}
static void T_13 F_179 ( void )
{
F_180 ( V_76 ) ;
}
