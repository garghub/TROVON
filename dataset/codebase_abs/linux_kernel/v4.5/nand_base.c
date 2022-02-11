static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = 0 ;
if ( V_3 & ( ( 1ULL << V_6 -> V_8 ) - 1 ) ) {
F_3 ( L_1 , V_9 ) ;
V_7 = - V_10 ;
}
if ( V_4 & ( ( 1ULL << V_6 -> V_8 ) - 1 ) ) {
F_3 ( L_2 , V_9 ) ;
V_7 = - V_10 ;
}
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( & V_6 -> V_11 -> V_12 ) ;
V_6 -> V_11 -> V_13 = NULL ;
V_6 -> V_14 = V_15 ;
F_6 ( & V_6 -> V_11 -> V_16 ) ;
F_7 ( & V_6 -> V_11 -> V_12 ) ;
}
static T_3 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_9 ( V_6 -> V_17 ) ;
}
static T_3 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ( T_3 ) F_11 ( F_12 ( V_6 -> V_17 ) ) ;
}
static T_4 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_12 ( V_6 -> V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_18 ) {
case - 1 :
V_6 -> V_19 ( V_2 , V_20 , 0 | V_21 ) ;
break;
case 0 :
break;
default:
F_15 () ;
}
}
static void F_16 ( struct V_1 * V_2 , T_3 V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_23 ( V_2 , & V_22 , 1 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_3 V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_5 V_24 = V_22 ;
V_6 -> V_23 ( V_2 , ( T_3 * ) & V_24 , 2 ) ;
}
static void F_18 ( struct V_1 * V_2 , const T_3 * V_25 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 -> V_26 , V_25 , V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_3 * V_25 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_21 ( V_6 -> V_17 , V_25 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 , const T_3 * V_25 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 * V_27 = ( T_4 * ) V_25 ;
F_23 ( V_6 -> V_26 , V_27 , V_4 >> 1 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 * V_25 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 * V_27 = ( T_4 * ) V_25 ;
F_25 ( V_6 -> V_17 , V_27 , V_4 >> 1 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 , int V_28 )
{
int V_29 , V_18 , V_30 = 0 , V_31 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_32 ;
if ( V_6 -> V_33 & V_34 )
V_3 += V_2 -> V_35 - V_2 -> V_36 ;
V_29 = ( int ) ( V_3 >> V_6 -> V_37 ) & V_6 -> V_38 ;
if ( V_28 ) {
V_18 = ( int ) ( V_3 >> V_6 -> V_39 ) ;
F_27 ( V_2 , V_40 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
}
do {
if ( V_6 -> V_42 & V_43 ) {
V_6 -> V_44 ( V_2 , V_45 ,
V_6 -> V_46 & 0xFE , V_29 ) ;
V_32 = F_11 ( V_6 -> V_47 ( V_2 ) ) ;
if ( V_6 -> V_46 & 0x1 )
V_32 >>= 8 ;
else
V_32 &= 0xFF ;
} else {
V_6 -> V_44 ( V_2 , V_45 , V_6 -> V_46 ,
V_29 ) ;
V_32 = V_6 -> V_48 ( V_2 ) ;
}
if ( F_28 ( V_6 -> V_49 == 8 ) )
V_30 = V_32 != 0xFF ;
else
V_30 = F_29 ( V_32 ) < V_6 -> V_49 ;
V_3 += V_2 -> V_36 ;
V_29 = ( int ) ( V_3 >> V_6 -> V_37 ) & V_6 -> V_38 ;
V_31 ++ ;
} while ( ! V_30 && V_31 < 2 && ( V_6 -> V_33 & V_50 ) );
if ( V_28 ) {
V_6 -> V_41 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
}
return V_30 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_51 V_52 ;
T_3 V_25 [ 2 ] = { 0 , 0 } ;
int V_7 = 0 , V_30 , V_31 = 0 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_53 = V_25 ;
V_52 . V_54 = V_6 -> V_46 ;
if ( V_6 -> V_42 & V_43 ) {
V_52 . V_54 &= ~ 0x01 ;
V_52 . V_4 = V_52 . V_55 = 2 ;
} else {
V_52 . V_4 = V_52 . V_55 = 1 ;
}
V_52 . V_56 = V_57 ;
if ( V_6 -> V_33 & V_34 )
V_3 += V_2 -> V_35 - V_2 -> V_36 ;
do {
V_30 = F_31 ( V_2 , V_3 , & V_52 ) ;
if ( ! V_7 )
V_7 = V_30 ;
V_31 ++ ;
V_3 += V_2 -> V_36 ;
} while ( ( V_6 -> V_33 & V_50 ) && V_31 < 2 );
return V_7 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_30 , V_7 = 0 ;
if ( ! ( V_6 -> V_33 & V_58 ) ) {
struct V_59 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_2 = V_2 ;
V_60 . V_61 = V_3 ;
V_60 . V_4 = 1ULL << V_6 -> V_8 ;
F_33 ( V_2 , & V_60 , 0 ) ;
F_27 ( V_2 , V_62 ) ;
V_7 = V_6 -> V_63 ( V_2 , V_3 ) ;
F_4 ( V_2 ) ;
}
if ( V_6 -> V_64 ) {
V_30 = F_34 ( V_2 , V_3 ) ;
if ( ! V_7 )
V_7 = V_30 ;
}
if ( ! V_7 )
V_2 -> V_65 . V_66 ++ ;
return V_7 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_42 & V_67 )
return 0 ;
V_6 -> V_44 ( V_2 , V_68 , - 1 , - 1 ) ;
return ( V_6 -> V_48 ( V_2 ) & V_69 ) ? 0 : 1 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_64 )
return 0 ;
return F_37 ( V_2 , V_3 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_3 , int V_28 ,
int V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_64 )
return V_6 -> V_71 ( V_2 , V_3 , V_28 ) ;
return F_39 ( V_2 , V_3 , V_70 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_72 ; V_31 ++ ) {
if ( V_6 -> V_73 ( V_2 ) )
break;
F_41 () ;
F_42 ( 1 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_72 = 400 ;
if ( F_44 () || V_74 )
return F_40 ( V_2 , V_72 ) ;
F_45 ( V_75 , V_76 ) ;
V_72 = V_77 + F_46 ( V_72 ) ;
do {
if ( V_6 -> V_73 ( V_2 ) )
goto V_78;
F_47 () ;
} while ( F_48 ( V_77 , V_72 ) );
F_49 (
L_3 ) ;
V_78:
F_45 ( V_75 , V_79 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned long V_72 )
{
register struct V_5 * V_6 = F_2 ( V_2 ) ;
V_72 = V_77 + F_46 ( V_72 ) ;
do {
if ( ( V_6 -> V_48 ( V_2 ) & V_80 ) )
break;
F_41 () ;
} while ( F_48 ( V_77 , V_72 ) );
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_81 ,
int V_82 , int V_83 )
{
register struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_84 = V_85 | V_21 ;
if ( V_81 == V_86 ) {
int V_87 ;
if ( V_82 >= V_2 -> V_36 ) {
V_82 -= V_2 -> V_36 ;
V_87 = V_45 ;
} else if ( V_82 < 256 ) {
V_87 = V_88 ;
} else {
V_82 -= 256 ;
V_87 = V_89 ;
}
V_6 -> V_19 ( V_2 , V_87 , V_84 ) ;
V_84 &= ~ V_21 ;
}
V_6 -> V_19 ( V_2 , V_81 , V_84 ) ;
V_84 = V_90 | V_21 ;
if ( V_82 != - 1 ) {
if ( V_6 -> V_42 & V_43 &&
! F_52 ( V_81 ) )
V_82 >>= 1 ;
V_6 -> V_19 ( V_2 , V_82 , V_84 ) ;
V_84 &= ~ V_21 ;
}
if ( V_83 != - 1 ) {
V_6 -> V_19 ( V_2 , V_83 , V_84 ) ;
V_84 &= ~ V_21 ;
V_6 -> V_19 ( V_2 , V_83 >> 8 , V_84 ) ;
if ( V_6 -> V_91 > ( 32 << 20 ) )
V_6 -> V_19 ( V_2 , V_83 >> 16 , V_84 ) ;
}
V_6 -> V_19 ( V_2 , V_20 , V_92 | V_21 ) ;
switch ( V_81 ) {
case V_93 :
case V_94 :
case V_95 :
case V_86 :
case V_68 :
return;
case V_96 :
if ( V_6 -> V_73 )
break;
F_53 ( V_6 -> V_97 ) ;
V_6 -> V_19 ( V_2 , V_68 ,
V_85 | V_21 ) ;
V_6 -> V_19 ( V_2 ,
V_20 , V_92 | V_21 ) ;
F_50 ( V_2 , 250 ) ;
return;
default:
if ( ! V_6 -> V_73 ) {
F_53 ( V_6 -> V_97 ) ;
return;
}
}
F_54 ( 100 ) ;
F_43 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_81 ,
int V_82 , int V_83 )
{
register struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_81 == V_45 ) {
V_82 += V_2 -> V_36 ;
V_81 = V_88 ;
}
V_6 -> V_19 ( V_2 , V_81 , V_92 | V_98 | V_21 ) ;
if ( V_82 != - 1 || V_83 != - 1 ) {
int V_84 = V_21 | V_92 | V_99 ;
if ( V_82 != - 1 ) {
if ( V_6 -> V_42 & V_43 &&
! F_52 ( V_81 ) )
V_82 >>= 1 ;
V_6 -> V_19 ( V_2 , V_82 , V_84 ) ;
V_84 &= ~ V_21 ;
V_6 -> V_19 ( V_2 , V_82 >> 8 , V_84 ) ;
}
if ( V_83 != - 1 ) {
V_6 -> V_19 ( V_2 , V_83 , V_84 ) ;
V_6 -> V_19 ( V_2 , V_83 >> 8 ,
V_92 | V_99 ) ;
if ( V_6 -> V_91 > ( 128 << 20 ) )
V_6 -> V_19 ( V_2 , V_83 >> 16 ,
V_92 | V_99 ) ;
}
}
V_6 -> V_19 ( V_2 , V_20 , V_92 | V_21 ) ;
switch ( V_81 ) {
case V_100 :
case V_93 :
case V_94 :
case V_95 :
case V_86 :
case V_101 :
case V_68 :
return;
case V_96 :
if ( V_6 -> V_73 )
break;
F_53 ( V_6 -> V_97 ) ;
V_6 -> V_19 ( V_2 , V_68 ,
V_92 | V_98 | V_21 ) ;
V_6 -> V_19 ( V_2 , V_20 ,
V_92 | V_21 ) ;
F_50 ( V_2 , 250 ) ;
return;
case V_102 :
V_6 -> V_19 ( V_2 , V_103 ,
V_92 | V_98 | V_21 ) ;
V_6 -> V_19 ( V_2 , V_20 ,
V_92 | V_21 ) ;
return;
case V_88 :
V_6 -> V_19 ( V_2 , V_104 ,
V_92 | V_98 | V_21 ) ;
V_6 -> V_19 ( V_2 , V_20 ,
V_92 | V_21 ) ;
default:
if ( ! V_6 -> V_73 ) {
F_53 ( V_6 -> V_97 ) ;
return;
}
}
F_54 ( 100 ) ;
F_43 ( V_2 ) ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_105 )
{
V_6 -> V_11 -> V_13 = V_6 ;
V_6 -> V_14 = V_105 ;
}
static int
F_27 ( struct V_1 * V_2 , int V_105 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_6 * V_12 = & V_6 -> V_11 -> V_12 ;
T_7 * V_16 = & V_6 -> V_11 -> V_16 ;
F_57 ( V_106 , V_107 ) ;
V_108:
F_5 ( V_12 ) ;
if ( ! V_6 -> V_11 -> V_13 )
V_6 -> V_11 -> V_13 = V_6 ;
if ( V_6 -> V_11 -> V_13 == V_6 && V_6 -> V_14 == V_15 ) {
V_6 -> V_14 = V_105 ;
F_7 ( V_12 ) ;
return 0 ;
}
if ( V_105 == V_109 ) {
if ( V_6 -> V_11 -> V_13 -> V_14 == V_109 ) {
V_6 -> V_14 = V_109 ;
F_7 ( V_12 ) ;
return 0 ;
}
}
F_58 ( V_110 ) ;
F_59 ( V_16 , & V_106 ) ;
F_7 ( V_12 ) ;
F_60 () ;
F_61 ( V_16 , & V_106 ) ;
goto V_108;
}
static void F_62 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_72 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_72 ; V_31 ++ ) {
if ( V_6 -> V_73 ) {
if ( V_6 -> V_73 ( V_2 ) )
break;
} else {
if ( V_6 -> V_48 ( V_2 ) & V_80 )
break;
}
F_42 ( 1 ) ;
}
}
static int F_63 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_111 ;
unsigned long V_72 = 400 ;
F_45 ( V_75 , V_76 ) ;
F_54 ( 100 ) ;
V_6 -> V_44 ( V_2 , V_68 , - 1 , - 1 ) ;
if ( F_44 () || V_74 )
F_62 ( V_2 , V_6 , V_72 ) ;
else {
V_72 = V_77 + F_46 ( V_72 ) ;
do {
if ( V_6 -> V_73 ) {
if ( V_6 -> V_73 ( V_2 ) )
break;
} else {
if ( V_6 -> V_48 ( V_2 ) & V_80 )
break;
}
F_47 () ;
} while ( F_48 ( V_77 , V_72 ) );
}
F_45 ( V_75 , V_79 ) ;
V_111 = ( int ) V_6 -> V_48 ( V_2 ) ;
F_64 ( ! ( V_111 & V_80 ) ) ;
return V_111 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_112 )
{
int V_7 = 0 ;
int V_111 , V_29 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_29 = V_3 >> V_6 -> V_37 ;
V_6 -> V_44 ( V_2 , V_113 , - 1 , V_29 & V_6 -> V_38 ) ;
V_29 = ( V_3 + V_4 ) >> V_6 -> V_37 ;
V_6 -> V_44 ( V_2 , V_114 , - 1 ,
( V_29 | V_112 ) & V_6 -> V_38 ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
if ( V_111 & V_116 ) {
F_3 ( L_4 ,
V_9 , V_111 ) ;
V_7 = - V_117 ;
}
return V_7 ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_7 = 0 ;
int V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_5 ,
V_9 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_10 ;
if ( V_3 + V_4 == V_2 -> V_118 )
V_4 -= V_2 -> V_35 ;
F_27 ( V_2 , V_119 ) ;
V_18 = V_3 >> V_6 -> V_39 ;
V_6 -> V_41 ( V_2 , V_18 ) ;
V_6 -> V_44 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_35 ( V_2 ) ) {
F_3 ( L_6 ,
V_9 ) ;
V_7 = - V_117 ;
goto V_78;
}
V_7 = F_65 ( V_2 , V_3 , V_4 , 0 ) ;
V_78:
V_6 -> V_41 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
return V_7 ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_7 = 0 ;
int V_18 , V_111 , V_29 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_5 ,
V_9 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_10 ;
F_27 ( V_2 , V_120 ) ;
V_18 = V_3 >> V_6 -> V_39 ;
V_6 -> V_41 ( V_2 , V_18 ) ;
V_6 -> V_44 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_35 ( V_2 ) ) {
F_3 ( L_6 ,
V_9 ) ;
V_111 = V_121 ;
V_7 = - V_117 ;
goto V_78;
}
V_29 = V_3 >> V_6 -> V_37 ;
V_6 -> V_44 ( V_2 , V_122 , - 1 , V_29 & V_6 -> V_38 ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
if ( V_111 & V_116 ) {
F_3 ( L_4 ,
V_9 , V_111 ) ;
V_7 = - V_117 ;
goto V_78;
}
V_7 = F_65 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_78:
V_6 -> V_41 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_68 ( void * V_25 , int V_4 , int V_123 )
{
const unsigned char * V_124 = V_25 ;
int V_125 = 0 ;
int V_126 ;
for (; V_4 && ( ( V_127 ) V_124 ) % sizeof( long ) ;
V_4 -- , V_124 ++ ) {
V_126 = F_29 ( * V_124 ) ;
V_125 += V_128 - V_126 ;
if ( F_69 ( V_125 > V_123 ) )
return - V_129 ;
}
for (; V_4 >= sizeof( long ) ;
V_4 -= sizeof( long ) , V_124 += sizeof( long ) ) {
V_126 = F_70 ( * ( ( unsigned long * ) V_124 ) ) ;
V_125 += V_130 - V_126 ;
if ( F_69 ( V_125 > V_123 ) )
return - V_129 ;
}
for (; V_4 > 0 ; V_4 -- , V_124 ++ ) {
V_126 = F_29 ( * V_124 ) ;
V_125 += V_128 - V_126 ;
if ( F_69 ( V_125 > V_123 ) )
return - V_129 ;
}
return V_125 ;
}
int F_71 ( void * V_131 , int V_132 ,
void * V_133 , int V_134 ,
void * V_135 , int V_136 ,
int V_123 )
{
int V_137 = 0 , V_138 = 0 , V_139 = 0 ;
V_137 = F_68 ( V_131 , V_132 ,
V_123 ) ;
if ( V_137 < 0 )
return V_137 ;
V_123 -= V_137 ;
V_138 = F_68 ( V_133 , V_134 , V_123 ) ;
if ( V_138 < 0 )
return V_138 ;
V_123 -= V_138 ;
V_139 = F_68 ( V_135 , V_136 ,
V_123 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( V_137 )
memset ( V_131 , 0xff , V_132 ) ;
if ( V_138 )
memset ( V_133 , 0xff , V_134 ) ;
if ( V_139 )
memset ( V_135 , 0xff , V_136 ) ;
return V_137 + V_138 + V_139 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_140 , int V_29 )
{
V_6 -> V_141 ( V_2 , V_25 , V_2 -> V_36 ) ;
if ( V_140 )
V_6 -> V_141 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_25 ,
int V_140 , int V_29 )
{
int V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
T_3 * V_147 = V_6 -> V_142 ;
int V_148 , V_118 ;
for ( V_148 = V_6 -> V_133 . V_148 ; V_148 > 0 ; V_148 -- ) {
V_6 -> V_141 ( V_2 , V_25 , V_144 ) ;
V_25 += V_144 ;
if ( V_6 -> V_133 . V_149 ) {
V_6 -> V_141 ( V_2 , V_147 , V_6 -> V_133 . V_149 ) ;
V_147 += V_6 -> V_133 . V_149 ;
}
V_6 -> V_141 ( V_2 , V_147 , V_145 ) ;
V_147 += V_145 ;
if ( V_6 -> V_133 . V_150 ) {
V_6 -> V_141 ( V_2 , V_147 , V_6 -> V_133 . V_150 ) ;
V_147 += V_6 -> V_133 . V_150 ;
}
}
V_118 = V_2 -> V_143 - ( V_147 - V_6 -> V_142 ) ;
if ( V_118 )
V_6 -> V_141 ( V_2 , V_147 , V_118 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_140 , int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
T_3 * V_27 = V_25 ;
T_3 * V_152 = V_6 -> V_153 -> V_154 ;
T_3 * V_155 = V_6 -> V_153 -> V_156 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
unsigned int V_159 = 0 ;
V_6 -> V_133 . V_160 ( V_2 , V_6 , V_25 , 1 , V_29 ) ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 )
V_6 -> V_133 . V_161 ( V_2 , V_27 , & V_152 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_162 ; V_31 ++ )
V_155 [ V_31 ] = V_6 -> V_142 [ V_157 [ V_31 ] ] ;
V_151 = V_6 -> V_133 . V_148 ;
V_27 = V_25 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
int V_163 ;
V_163 = V_6 -> V_133 . V_164 ( V_2 , V_27 , & V_155 [ V_31 ] , & V_152 [ V_31 ] ) ;
if ( V_163 < 0 ) {
V_2 -> V_65 . V_165 ++ ;
} else {
V_2 -> V_65 . V_166 += V_163 ;
V_159 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_159 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_167 , T_8 V_168 , T_3 * V_169 ,
int V_29 )
{
int V_170 , V_171 , V_172 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
T_3 * V_27 ;
int V_173 , V_31 , V_174 = 0 ;
int V_175 , V_176 , V_177 , V_178 ;
int V_179 = ( V_6 -> V_42 & V_43 ) ? 2 : 1 ;
int V_180 ;
unsigned int V_159 = 0 ;
V_170 = V_167 / V_6 -> V_133 . V_118 ;
V_171 = ( V_167 + V_168 - 1 ) / V_6 -> V_133 . V_118 ;
V_172 = V_171 - V_170 + 1 ;
V_180 = V_170 * V_6 -> V_133 . V_146 ;
V_175 = V_172 * V_6 -> V_133 . V_118 ;
V_176 = V_172 * V_6 -> V_133 . V_146 ;
V_173 = V_170 * V_6 -> V_133 . V_118 ;
if ( V_173 != 0 )
V_6 -> V_44 ( V_2 , V_102 , V_173 , - 1 ) ;
V_27 = V_169 + V_173 ;
V_6 -> V_141 ( V_2 , V_27 , V_175 ) ;
for ( V_31 = 0 ; V_31 < V_176 ; V_31 += V_6 -> V_133 . V_146 , V_27 += V_6 -> V_133 . V_118 )
V_6 -> V_133 . V_161 ( V_2 , V_27 , & V_6 -> V_153 -> V_154 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_176 - 1 ; V_31 ++ ) {
if ( V_157 [ V_31 + V_180 ] + 1 != V_157 [ V_31 + V_180 + 1 ] ) {
V_174 = 1 ;
break;
}
}
if ( V_174 ) {
V_6 -> V_44 ( V_2 , V_102 , V_2 -> V_36 , - 1 ) ;
V_6 -> V_141 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
} else {
V_178 = V_157 [ V_180 ] & ~ ( V_179 - 1 ) ;
V_177 = V_176 ;
if ( V_157 [ V_180 ] & ( V_179 - 1 ) )
V_177 ++ ;
if ( V_157 [ V_180 + ( V_172 * V_6 -> V_133 . V_146 ) ] & ( V_179 - 1 ) )
V_177 ++ ;
V_6 -> V_44 ( V_2 , V_102 ,
V_2 -> V_36 + V_178 , - 1 ) ;
V_6 -> V_141 ( V_2 , & V_6 -> V_142 [ V_178 ] , V_177 ) ;
}
for ( V_31 = 0 ; V_31 < V_176 ; V_31 ++ )
V_6 -> V_153 -> V_156 [ V_31 ] = V_6 -> V_142 [ V_157 [ V_31 + V_180 ] ] ;
V_27 = V_169 + V_173 ;
for ( V_31 = 0 ; V_31 < V_176 ; V_31 += V_6 -> V_133 . V_146 , V_27 += V_6 -> V_133 . V_118 ) {
int V_163 ;
V_163 = V_6 -> V_133 . V_164 ( V_2 , V_27 ,
& V_6 -> V_153 -> V_156 [ V_31 ] , & V_6 -> V_153 -> V_154 [ V_31 ] ) ;
if ( V_163 == - V_129 &&
( V_6 -> V_133 . V_42 & V_181 ) ) {
V_163 = F_71 ( V_27 , V_6 -> V_133 . V_118 ,
& V_6 -> V_153 -> V_156 [ V_31 ] ,
V_6 -> V_133 . V_146 ,
NULL , 0 ,
V_6 -> V_133 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_65 . V_165 ++ ;
} else {
V_2 -> V_65 . V_166 += V_163 ;
V_159 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_159 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_140 , int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
T_3 * V_27 = V_25 ;
T_3 * V_152 = V_6 -> V_153 -> V_154 ;
T_3 * V_155 = V_6 -> V_153 -> V_156 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
unsigned int V_159 = 0 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
V_6 -> V_133 . V_183 ( V_2 , V_184 ) ;
V_6 -> V_141 ( V_2 , V_27 , V_144 ) ;
V_6 -> V_133 . V_161 ( V_2 , V_27 , & V_152 [ V_31 ] ) ;
}
V_6 -> V_141 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_162 ; V_31 ++ )
V_155 [ V_31 ] = V_6 -> V_142 [ V_157 [ V_31 ] ] ;
V_151 = V_6 -> V_133 . V_148 ;
V_27 = V_25 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
int V_163 ;
V_163 = V_6 -> V_133 . V_164 ( V_2 , V_27 , & V_155 [ V_31 ] , & V_152 [ V_31 ] ) ;
if ( V_163 == - V_129 &&
( V_6 -> V_133 . V_42 & V_181 ) ) {
V_163 = F_71 ( V_27 , V_144 ,
& V_155 [ V_31 ] , V_145 ,
NULL , 0 ,
V_6 -> V_133 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_65 . V_165 ++ ;
} else {
V_2 -> V_65 . V_166 += V_163 ;
V_159 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_159 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_25 , int V_140 , int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
T_3 * V_27 = V_25 ;
T_3 * V_155 = V_6 -> V_153 -> V_156 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
T_3 * V_152 = V_6 -> V_153 -> V_154 ;
unsigned int V_159 = 0 ;
V_6 -> V_44 ( V_2 , V_45 , 0 , V_29 ) ;
V_6 -> V_141 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
V_6 -> V_44 ( V_2 , V_88 , 0 , V_29 ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_162 ; V_31 ++ )
V_155 [ V_31 ] = V_6 -> V_142 [ V_157 [ V_31 ] ] ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
int V_163 ;
V_6 -> V_133 . V_183 ( V_2 , V_184 ) ;
V_6 -> V_141 ( V_2 , V_27 , V_144 ) ;
V_6 -> V_133 . V_161 ( V_2 , V_27 , & V_152 [ V_31 ] ) ;
V_163 = V_6 -> V_133 . V_164 ( V_2 , V_27 , & V_155 [ V_31 ] , NULL ) ;
if ( V_163 == - V_129 &&
( V_6 -> V_133 . V_42 & V_181 ) ) {
V_163 = F_71 ( V_27 , V_144 ,
& V_155 [ V_31 ] , V_145 ,
NULL , 0 ,
V_6 -> V_133 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_65 . V_165 ++ ;
} else {
V_2 -> V_65 . V_166 += V_163 ;
V_159 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_159 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_140 , int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
int V_185 = V_145 + V_6 -> V_133 . V_149 + V_6 -> V_133 . V_150 ;
T_3 * V_27 = V_25 ;
T_3 * V_147 = V_6 -> V_142 ;
unsigned int V_159 = 0 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
int V_163 ;
V_6 -> V_133 . V_183 ( V_2 , V_184 ) ;
V_6 -> V_141 ( V_2 , V_27 , V_144 ) ;
if ( V_6 -> V_133 . V_149 ) {
V_6 -> V_141 ( V_2 , V_147 , V_6 -> V_133 . V_149 ) ;
V_147 += V_6 -> V_133 . V_149 ;
}
V_6 -> V_133 . V_183 ( V_2 , V_186 ) ;
V_6 -> V_141 ( V_2 , V_147 , V_145 ) ;
V_163 = V_6 -> V_133 . V_164 ( V_2 , V_27 , V_147 , NULL ) ;
V_147 += V_145 ;
if ( V_6 -> V_133 . V_150 ) {
V_6 -> V_141 ( V_2 , V_147 , V_6 -> V_133 . V_150 ) ;
V_147 += V_6 -> V_133 . V_150 ;
}
if ( V_163 == - V_129 &&
( V_6 -> V_133 . V_42 & V_181 ) ) {
V_163 = F_71 ( V_27 , V_6 -> V_133 . V_118 ,
V_147 - V_185 ,
V_185 ,
NULL , 0 ,
V_6 -> V_133 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_65 . V_165 ++ ;
} else {
V_2 -> V_65 . V_166 += V_163 ;
V_159 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
V_31 = V_2 -> V_143 - ( V_147 - V_6 -> V_142 ) ;
if ( V_31 )
V_6 -> V_141 ( V_2 , V_147 , V_31 ) ;
return V_159 ;
}
static T_3 * F_80 ( struct V_5 * V_6 , T_3 * V_147 ,
struct V_51 * V_52 , T_9 V_4 )
{
switch ( V_52 -> V_56 ) {
case V_57 :
case V_187 :
memcpy ( V_147 , V_6 -> V_142 + V_52 -> V_54 , V_4 ) ;
return V_147 + V_4 ;
case V_188 : {
struct V_189 * free = V_6 -> V_133 . V_158 -> V_190 ;
T_8 V_191 = 0 , V_192 = V_52 -> V_54 ;
T_9 V_146 = 0 ;
for (; free -> V_193 && V_4 ; free ++ , V_4 -= V_146 ) {
if ( F_69 ( V_192 ) ) {
if ( V_192 >= free -> V_193 ) {
V_192 -= free -> V_193 ;
continue;
}
V_191 = free -> V_194 + V_192 ;
V_146 = F_81 ( T_9 , V_4 ,
( free -> V_193 - V_192 ) ) ;
V_192 = 0 ;
} else {
V_146 = F_81 ( T_9 , V_4 , free -> V_193 ) ;
V_191 = free -> V_194 ;
}
memcpy ( V_147 , V_6 -> V_142 + V_191 , V_146 ) ;
V_147 += V_146 ;
}
return V_147 ;
}
default:
F_15 () ;
}
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_195 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_7 , V_195 ) ;
if ( V_195 >= V_6 -> V_196 )
return - V_10 ;
if ( ! V_6 -> V_197 )
return - V_198 ;
return V_6 -> V_197 ( V_2 , V_195 ) ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_199 ,
struct V_51 * V_52 )
{
int V_18 , V_29 , V_200 , V_201 , V_146 , V_202 , V_140 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = 0 ;
T_8 V_168 = V_52 -> V_4 ;
T_8 V_203 = V_52 -> V_55 ;
T_8 V_204 = V_52 -> V_56 == V_188 ?
V_2 -> V_205 : V_2 -> V_143 ;
T_3 * V_169 , * V_147 , * V_25 ;
int V_206 ;
unsigned int V_159 = 0 ;
int V_195 = 0 ;
bool V_207 = false ;
V_18 = ( int ) ( V_199 >> V_6 -> V_39 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
V_200 = ( int ) ( V_199 >> V_6 -> V_37 ) ;
V_29 = V_200 & V_6 -> V_38 ;
V_201 = ( int ) ( V_199 & ( V_2 -> V_36 - 1 ) ) ;
V_25 = V_52 -> V_208 ;
V_147 = V_52 -> V_53 ;
V_140 = V_147 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_209 = V_2 -> V_65 . V_165 ;
V_146 = F_84 ( V_2 -> V_36 - V_201 , V_168 ) ;
V_202 = ( V_146 == V_2 -> V_36 ) ;
if ( ! V_202 )
V_206 = 1 ;
else if ( V_6 -> V_42 & V_210 )
V_206 = ! F_85 ( V_25 ) ;
else
V_206 = 0 ;
if ( V_200 != V_6 -> V_211 || V_147 ) {
V_169 = V_206 ? V_6 -> V_153 -> V_212 : V_25 ;
if ( V_206 && V_202 )
F_3 ( L_8 ,
V_9 , V_25 ) ;
V_213:
V_6 -> V_44 ( V_2 , V_88 , 0x00 , V_29 ) ;
if ( F_69 ( V_52 -> V_56 == V_187 ) )
V_7 = V_6 -> V_133 . V_160 ( V_2 , V_6 , V_169 ,
V_140 ,
V_29 ) ;
else if ( ! V_202 && F_86 ( V_6 ) &&
! V_147 )
V_7 = V_6 -> V_133 . V_214 ( V_2 , V_6 ,
V_201 , V_146 , V_169 ,
V_29 ) ;
else
V_7 = V_6 -> V_133 . V_215 ( V_2 , V_6 , V_169 ,
V_140 , V_29 ) ;
if ( V_7 < 0 ) {
if ( V_206 )
V_6 -> V_211 = - 1 ;
break;
}
V_159 = F_75 (unsigned int, max_bitflips, ret) ;
if ( V_206 ) {
if ( ! F_86 ( V_6 ) && ! V_147 &&
! ( V_2 -> V_65 . V_165 - V_209 ) &&
( V_52 -> V_56 != V_187 ) ) {
V_6 -> V_211 = V_200 ;
V_6 -> V_216 = V_7 ;
} else {
V_6 -> V_211 = - 1 ;
}
memcpy ( V_25 , V_6 -> V_153 -> V_212 + V_201 , V_146 ) ;
}
if ( F_69 ( V_147 ) ) {
int V_217 = F_84 ( V_203 , V_204 ) ;
if ( V_217 ) {
V_147 = F_80 ( V_6 ,
V_147 , V_52 , V_217 ) ;
V_203 -= V_217 ;
}
}
if ( V_6 -> V_42 & V_218 ) {
if ( ! V_6 -> V_73 )
F_53 ( V_6 -> V_97 ) ;
else
F_43 ( V_2 ) ;
}
if ( V_2 -> V_65 . V_165 - V_209 ) {
if ( V_195 + 1 < V_6 -> V_196 ) {
V_195 ++ ;
V_7 = F_82 ( V_2 ,
V_195 ) ;
if ( V_7 < 0 )
break;
V_2 -> V_65 . V_165 = V_209 ;
goto V_213;
} else {
V_207 = true ;
}
}
V_25 += V_146 ;
} else {
memcpy ( V_25 , V_6 -> V_153 -> V_212 + V_201 , V_146 ) ;
V_25 += V_146 ;
V_159 = F_75 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_168 -= V_146 ;
if ( V_195 ) {
V_7 = F_82 ( V_2 , 0 ) ;
if ( V_7 < 0 )
break;
V_195 = 0 ;
}
if ( ! V_168 )
break;
V_201 = 0 ;
V_200 ++ ;
V_29 = V_200 & V_6 -> V_38 ;
if ( ! V_29 ) {
V_18 ++ ;
V_6 -> V_41 ( V_2 , - 1 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
}
}
V_6 -> V_41 ( V_2 , - 1 ) ;
V_52 -> V_219 = V_52 -> V_4 - ( T_9 ) V_168 ;
if ( V_147 )
V_52 -> V_220 = V_52 -> V_55 - V_203 ;
if ( V_7 < 0 )
return V_7 ;
if ( V_207 )
return - V_129 ;
return V_159 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_199 , T_9 V_4 ,
T_9 * V_219 , T_3 * V_25 )
{
struct V_51 V_52 ;
int V_7 ;
F_27 ( V_2 , V_40 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_4 = V_4 ;
V_52 . V_208 = V_25 ;
V_52 . V_56 = V_57 ;
V_7 = F_83 ( V_2 , V_199 , & V_52 ) ;
* V_219 = V_52 . V_219 ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
V_6 -> V_44 ( V_2 , V_45 , 0 , V_29 ) ;
V_6 -> V_141 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
int V_193 = V_2 -> V_143 ;
int V_221 = V_6 -> V_133 . V_146 + V_6 -> V_133 . V_149 + V_6 -> V_133 . V_150 ;
int V_144 = V_6 -> V_133 . V_118 ;
T_3 * V_169 = V_6 -> V_142 ;
int V_31 , V_217 , V_222 = 0 , V_223 ;
V_6 -> V_44 ( V_2 , V_88 , V_6 -> V_133 . V_118 , V_29 ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_148 ; V_31 ++ ) {
if ( V_222 ) {
V_223 = V_144 + V_31 * ( V_144 + V_221 ) ;
if ( V_2 -> V_36 > 512 )
V_6 -> V_44 ( V_2 , V_102 , V_223 , - 1 ) ;
else
V_6 -> V_44 ( V_2 , V_88 , V_223 , V_29 ) ;
} else
V_222 = 1 ;
V_217 = F_81 ( int , V_193 , V_221 ) ;
V_6 -> V_141 ( V_2 , V_169 , V_217 ) ;
V_169 += V_217 ;
V_193 -= V_217 ;
}
if ( V_193 > 0 )
V_6 -> V_141 ( V_2 , V_169 , V_193 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_29 )
{
int V_111 = 0 ;
const T_3 * V_25 = V_6 -> V_142 ;
int V_193 = V_2 -> V_143 ;
V_6 -> V_44 ( V_2 , V_86 , V_2 -> V_36 , V_29 ) ;
V_6 -> V_23 ( V_2 , V_25 , V_193 ) ;
V_6 -> V_44 ( V_2 , V_93 , - 1 , - 1 ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
return V_111 & V_116 ? - V_117 : 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_29 )
{
int V_221 = V_6 -> V_133 . V_146 + V_6 -> V_133 . V_149 + V_6 -> V_133 . V_150 ;
int V_144 = V_6 -> V_133 . V_118 , V_193 = V_2 -> V_143 ;
int V_31 , V_4 , V_223 , V_111 = 0 , V_224 = 0 , V_148 = V_6 -> V_133 . V_148 ;
const T_3 * V_169 = V_6 -> V_142 ;
if ( ! V_6 -> V_133 . V_149 && ! V_6 -> V_133 . V_150 ) {
V_223 = V_148 * ( V_144 + V_221 ) ;
V_148 = 0 ;
} else
V_223 = V_144 ;
V_6 -> V_44 ( V_2 , V_86 , V_223 , V_29 ) ;
for ( V_31 = 0 ; V_31 < V_148 ; V_31 ++ ) {
if ( V_224 ) {
if ( V_2 -> V_36 <= 512 ) {
T_8 V_225 = 0xFFFFFFFF ;
V_4 = V_144 ;
while ( V_4 > 0 ) {
int V_226 = F_81 ( int , V_4 , 4 ) ;
V_6 -> V_23 ( V_2 , ( T_3 * ) & V_225 ,
V_226 ) ;
V_4 -= V_226 ;
}
} else {
V_223 = V_144 + V_31 * ( V_144 + V_221 ) ;
V_6 -> V_44 ( V_2 , V_101 , V_223 , - 1 ) ;
}
} else
V_224 = 1 ;
V_4 = F_81 ( int , V_193 , V_221 ) ;
V_6 -> V_23 ( V_2 , V_169 , V_4 ) ;
V_169 += V_4 ;
V_193 -= V_4 ;
}
if ( V_193 > 0 )
V_6 -> V_23 ( V_2 , V_169 , V_193 ) ;
V_6 -> V_44 ( V_2 , V_93 , - 1 , - 1 ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
return V_111 & V_116 ? - V_117 : 0 ;
}
static int F_92 ( struct V_1 * V_2 , T_1 V_199 ,
struct V_51 * V_52 )
{
int V_29 , V_200 , V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_227 V_228 ;
int V_168 = V_52 -> V_55 ;
int V_4 ;
T_3 * V_25 = V_52 -> V_53 ;
int V_7 = 0 ;
F_3 ( L_9 ,
V_9 , ( unsigned long long ) V_199 , V_168 ) ;
V_228 = V_2 -> V_65 ;
if ( V_52 -> V_56 == V_188 )
V_4 = V_6 -> V_133 . V_158 -> V_205 ;
else
V_4 = V_2 -> V_143 ;
if ( F_69 ( V_52 -> V_54 >= V_4 ) ) {
F_3 ( L_10 ,
V_9 ) ;
return - V_10 ;
}
if ( F_69 ( V_199 >= V_2 -> V_118 ||
V_52 -> V_54 + V_168 > ( ( V_2 -> V_118 >> V_6 -> V_37 ) -
( V_199 >> V_6 -> V_37 ) ) * V_4 ) ) {
F_3 ( L_11 ,
V_9 ) ;
return - V_10 ;
}
V_18 = ( int ) ( V_199 >> V_6 -> V_39 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
V_200 = ( int ) ( V_199 >> V_6 -> V_37 ) ;
V_29 = V_200 & V_6 -> V_38 ;
while ( 1 ) {
if ( V_52 -> V_56 == V_187 )
V_7 = V_6 -> V_133 . V_229 ( V_2 , V_6 , V_29 ) ;
else
V_7 = V_6 -> V_133 . V_230 ( V_2 , V_6 , V_29 ) ;
if ( V_7 < 0 )
break;
V_4 = F_84 ( V_4 , V_168 ) ;
V_25 = F_80 ( V_6 , V_25 , V_52 , V_4 ) ;
if ( V_6 -> V_42 & V_218 ) {
if ( ! V_6 -> V_73 )
F_53 ( V_6 -> V_97 ) ;
else
F_43 ( V_2 ) ;
}
V_168 -= V_4 ;
if ( ! V_168 )
break;
V_200 ++ ;
V_29 = V_200 & V_6 -> V_38 ;
if ( ! V_29 ) {
V_18 ++ ;
V_6 -> V_41 ( V_2 , - 1 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
}
}
V_6 -> V_41 ( V_2 , - 1 ) ;
V_52 -> V_220 = V_52 -> V_55 - V_168 ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_65 . V_165 - V_228 . V_165 )
return - V_129 ;
return V_2 -> V_65 . V_166 - V_228 . V_166 ? - V_231 : 0 ;
}
static int F_93 ( struct V_1 * V_2 , T_1 V_199 ,
struct V_51 * V_52 )
{
int V_7 = - V_232 ;
V_52 -> V_219 = 0 ;
if ( V_52 -> V_208 && ( V_199 + V_52 -> V_4 ) > V_2 -> V_118 ) {
F_3 ( L_11 ,
V_9 ) ;
return - V_10 ;
}
F_27 ( V_2 , V_40 ) ;
switch ( V_52 -> V_56 ) {
case V_57 :
case V_188 :
case V_187 :
break;
default:
goto V_78;
}
if ( ! V_52 -> V_208 )
V_7 = F_92 ( V_2 , V_199 , V_52 ) ;
else
V_7 = F_83 ( V_2 , V_199 , V_52 ) ;
V_78:
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_25 , int V_140 , int V_29 )
{
V_6 -> V_23 ( V_2 , V_25 , V_2 -> V_36 ) ;
if ( V_140 )
V_6 -> V_23 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_25 , int V_140 ,
int V_29 )
{
int V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
T_3 * V_147 = V_6 -> V_142 ;
int V_148 , V_118 ;
for ( V_148 = V_6 -> V_133 . V_148 ; V_148 > 0 ; V_148 -- ) {
V_6 -> V_23 ( V_2 , V_25 , V_144 ) ;
V_25 += V_144 ;
if ( V_6 -> V_133 . V_149 ) {
V_6 -> V_23 ( V_2 , V_147 , V_6 -> V_133 . V_149 ) ;
V_147 += V_6 -> V_133 . V_149 ;
}
V_6 -> V_23 ( V_2 , V_147 , V_145 ) ;
V_147 += V_145 ;
if ( V_6 -> V_133 . V_150 ) {
V_6 -> V_23 ( V_2 , V_147 , V_6 -> V_133 . V_150 ) ;
V_147 += V_6 -> V_133 . V_150 ;
}
}
V_118 = V_2 -> V_143 - ( V_147 - V_6 -> V_142 ) ;
if ( V_118 )
V_6 -> V_23 ( V_2 , V_147 , V_118 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_25 , int V_140 ,
int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
T_3 * V_152 = V_6 -> V_153 -> V_154 ;
const T_3 * V_27 = V_25 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 )
V_6 -> V_133 . V_161 ( V_2 , V_27 , & V_152 [ V_31 ] ) ;
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_162 ; V_31 ++ )
V_6 -> V_142 [ V_157 [ V_31 ] ] = V_152 [ V_31 ] ;
return V_6 -> V_133 . V_233 ( V_2 , V_6 , V_25 , 1 , V_29 ) ;
}
static int F_97 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_25 , int V_140 ,
int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
T_3 * V_152 = V_6 -> V_153 -> V_154 ;
const T_3 * V_27 = V_25 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
V_6 -> V_133 . V_183 ( V_2 , V_234 ) ;
V_6 -> V_23 ( V_2 , V_27 , V_144 ) ;
V_6 -> V_133 . V_161 ( V_2 , V_27 , & V_152 [ V_31 ] ) ;
}
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_162 ; V_31 ++ )
V_6 -> V_142 [ V_157 [ V_31 ] ] = V_152 [ V_31 ] ;
V_6 -> V_23 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_8 V_194 ,
T_8 V_235 , const T_3 * V_25 ,
int V_140 , int V_29 )
{
T_3 * V_236 = V_6 -> V_142 ;
T_3 * V_152 = V_6 -> V_153 -> V_154 ;
int V_237 = V_6 -> V_133 . V_118 ;
int V_238 = V_6 -> V_133 . V_146 ;
int V_239 = V_6 -> V_133 . V_148 ;
T_8 * V_157 = V_6 -> V_133 . V_158 -> V_157 ;
T_8 V_170 = V_194 / V_237 ;
T_8 V_171 = ( V_194 + V_235 - 1 ) / V_237 ;
int V_240 = V_2 -> V_143 / V_239 ;
int V_241 , V_31 ;
for ( V_241 = 0 ; V_241 < V_239 ; V_241 ++ ) {
V_6 -> V_133 . V_183 ( V_2 , V_234 ) ;
V_6 -> V_23 ( V_2 , V_25 , V_237 ) ;
if ( ( V_241 < V_170 ) || ( V_241 > V_171 ) )
memset ( V_152 , 0xff , V_238 ) ;
else
V_6 -> V_133 . V_161 ( V_2 , V_25 , V_152 ) ;
if ( ! V_140 || ( V_241 < V_170 ) || ( V_241 > V_171 ) )
memset ( V_236 , 0xff , V_240 ) ;
V_25 += V_237 ;
V_152 += V_238 ;
V_236 += V_240 ;
}
V_152 = V_6 -> V_153 -> V_154 ;
for ( V_31 = 0 ; V_31 < V_6 -> V_133 . V_162 ; V_31 ++ )
V_6 -> V_142 [ V_157 [ V_31 ] ] = V_152 [ V_31 ] ;
V_6 -> V_23 ( V_2 , V_6 -> V_142 , V_2 -> V_143 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_25 , int V_140 ,
int V_29 )
{
int V_31 , V_144 = V_6 -> V_133 . V_118 ;
int V_145 = V_6 -> V_133 . V_146 ;
int V_151 = V_6 -> V_133 . V_148 ;
const T_3 * V_27 = V_25 ;
T_3 * V_147 = V_6 -> V_142 ;
for ( V_31 = 0 ; V_151 ; V_151 -- , V_31 += V_145 , V_27 += V_144 ) {
V_6 -> V_133 . V_183 ( V_2 , V_234 ) ;
V_6 -> V_23 ( V_2 , V_27 , V_144 ) ;
if ( V_6 -> V_133 . V_149 ) {
V_6 -> V_23 ( V_2 , V_147 , V_6 -> V_133 . V_149 ) ;
V_147 += V_6 -> V_133 . V_149 ;
}
V_6 -> V_133 . V_161 ( V_2 , V_27 , V_147 ) ;
V_6 -> V_23 ( V_2 , V_147 , V_145 ) ;
V_147 += V_145 ;
if ( V_6 -> V_133 . V_150 ) {
V_6 -> V_23 ( V_2 , V_147 , V_6 -> V_133 . V_150 ) ;
V_147 += V_6 -> V_133 . V_150 ;
}
}
V_31 = V_2 -> V_143 - ( V_147 - V_6 -> V_142 ) ;
if ( V_31 )
V_6 -> V_23 ( V_2 , V_147 , V_31 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_194 , int V_235 , const T_3 * V_25 ,
int V_140 , int V_29 , int V_242 , int V_243 )
{
int V_111 , V_244 ;
if ( ! ( V_6 -> V_42 & V_245 ) &&
V_6 -> V_133 . V_246 )
V_244 = V_194 || ( V_235 < V_2 -> V_36 ) ;
else
V_244 = 0 ;
V_6 -> V_44 ( V_2 , V_86 , 0x00 , V_29 ) ;
if ( F_69 ( V_243 ) )
V_111 = V_6 -> V_133 . V_233 ( V_2 , V_6 , V_25 ,
V_140 , V_29 ) ;
else if ( V_244 )
V_111 = V_6 -> V_133 . V_246 ( V_2 , V_6 , V_194 , V_235 ,
V_25 , V_140 , V_29 ) ;
else
V_111 = V_6 -> V_133 . V_247 ( V_2 , V_6 , V_25 , V_140 ,
V_29 ) ;
if ( V_111 < 0 )
return V_111 ;
V_242 = 0 ;
if ( ! V_242 || ! F_101 ( V_6 ) ) {
V_6 -> V_44 ( V_2 , V_93 , - 1 , - 1 ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
if ( ( V_111 & V_116 ) && ( V_6 -> V_248 ) )
V_111 = V_6 -> V_248 ( V_2 , V_6 , V_62 , V_111 ,
V_29 ) ;
if ( V_111 & V_116 )
return - V_117 ;
} else {
V_6 -> V_44 ( V_2 , V_100 , - 1 , - 1 ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_102 ( struct V_1 * V_2 , T_3 * V_147 , T_9 V_4 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_6 -> V_142 , 0xff , V_2 -> V_143 ) ;
switch ( V_52 -> V_56 ) {
case V_57 :
case V_187 :
memcpy ( V_6 -> V_142 + V_52 -> V_54 , V_147 , V_4 ) ;
return V_147 + V_4 ;
case V_188 : {
struct V_189 * free = V_6 -> V_133 . V_158 -> V_190 ;
T_8 V_191 = 0 , V_249 = V_52 -> V_54 ;
T_9 V_146 = 0 ;
for (; free -> V_193 && V_4 ; free ++ , V_4 -= V_146 ) {
if ( F_69 ( V_249 ) ) {
if ( V_249 >= free -> V_193 ) {
V_249 -= free -> V_193 ;
continue;
}
V_191 = free -> V_194 + V_249 ;
V_146 = F_81 ( T_9 , V_4 ,
( free -> V_193 - V_249 ) ) ;
V_249 = 0 ;
} else {
V_146 = F_81 ( T_9 , V_4 , free -> V_193 ) ;
V_191 = free -> V_194 ;
}
memcpy ( V_6 -> V_142 + V_191 , V_147 , V_146 ) ;
V_147 += V_146 ;
}
return V_147 ;
}
default:
F_15 () ;
}
return NULL ;
}
static int F_103 ( struct V_1 * V_2 , T_1 V_250 ,
struct V_51 * V_52 )
{
int V_18 , V_200 , V_29 , V_251 , V_82 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_8 V_252 = V_52 -> V_4 ;
T_8 V_253 = V_52 -> V_55 ;
T_8 V_254 = V_52 -> V_56 == V_188 ?
V_2 -> V_205 : V_2 -> V_143 ;
T_3 * V_147 = V_52 -> V_53 ;
T_3 * V_25 = V_52 -> V_208 ;
int V_7 ;
int V_140 = V_147 ? 1 : 0 ;
V_52 -> V_219 = 0 ;
if ( ! V_252 )
return 0 ;
if ( F_104 ( V_250 ) || F_104 ( V_52 -> V_4 ) ) {
F_105 ( L_12 ,
V_9 ) ;
return - V_10 ;
}
V_82 = V_250 & ( V_2 -> V_36 - 1 ) ;
V_18 = ( int ) ( V_250 >> V_6 -> V_39 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
if ( F_35 ( V_2 ) ) {
V_7 = - V_117 ;
goto V_255;
}
V_200 = ( int ) ( V_250 >> V_6 -> V_37 ) ;
V_29 = V_200 & V_6 -> V_38 ;
V_251 = ( 1 << ( V_6 -> V_8 - V_6 -> V_37 ) ) - 1 ;
if ( V_250 <= ( ( T_1 ) V_6 -> V_211 << V_6 -> V_37 ) &&
( ( T_1 ) V_6 -> V_211 << V_6 -> V_37 ) < ( V_250 + V_52 -> V_4 ) )
V_6 -> V_211 = - 1 ;
if ( V_147 && V_52 -> V_54 && ( V_52 -> V_54 + V_52 -> V_55 > V_254 ) ) {
V_7 = - V_10 ;
goto V_255;
}
while ( 1 ) {
int V_146 = V_2 -> V_36 ;
int V_242 = V_252 > V_146 && V_29 != V_251 ;
T_3 * V_256 = V_25 ;
int V_206 ;
int V_257 = ( V_82 || V_252 < ( V_2 -> V_36 - 1 ) ) ;
if ( V_257 )
V_206 = 1 ;
else if ( V_6 -> V_42 & V_210 )
V_206 = ! F_85 ( V_25 ) ;
else
V_206 = 0 ;
if ( V_206 ) {
F_3 ( L_13 ,
V_9 , V_25 ) ;
V_242 = 0 ;
if ( V_257 )
V_146 = F_81 ( int , V_146 - V_82 , V_252 ) ;
V_6 -> V_211 = - 1 ;
memset ( V_6 -> V_153 -> V_212 , 0xff , V_2 -> V_36 ) ;
memcpy ( & V_6 -> V_153 -> V_212 [ V_82 ] , V_25 , V_146 ) ;
V_256 = V_6 -> V_153 -> V_212 ;
}
if ( F_69 ( V_147 ) ) {
T_9 V_4 = F_84 ( V_253 , V_254 ) ;
V_147 = F_102 ( V_2 , V_147 , V_4 , V_52 ) ;
V_253 -= V_4 ;
} else {
memset ( V_6 -> V_142 , 0xff , V_2 -> V_143 ) ;
}
V_7 = V_6 -> V_247 ( V_2 , V_6 , V_82 , V_146 , V_256 ,
V_140 , V_29 , V_242 ,
( V_52 -> V_56 == V_187 ) ) ;
if ( V_7 )
break;
V_252 -= V_146 ;
if ( ! V_252 )
break;
V_82 = 0 ;
V_25 += V_146 ;
V_200 ++ ;
V_29 = V_200 & V_6 -> V_38 ;
if ( ! V_29 ) {
V_18 ++ ;
V_6 -> V_41 ( V_2 , - 1 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
}
}
V_52 -> V_219 = V_52 -> V_4 - V_252 ;
if ( F_69 ( V_147 ) )
V_52 -> V_220 = V_52 -> V_55 ;
V_255:
V_6 -> V_41 ( V_2 , - 1 ) ;
return V_7 ;
}
static int F_106 ( struct V_1 * V_2 , T_1 V_250 , T_9 V_4 ,
T_9 * V_219 , const T_3 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_51 V_52 ;
int V_7 ;
F_62 ( V_2 , V_6 , 400 ) ;
F_56 ( V_6 , V_2 , V_62 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_4 = V_4 ;
V_52 . V_208 = ( T_3 * ) V_25 ;
V_52 . V_56 = V_57 ;
V_7 = F_103 ( V_2 , V_250 , & V_52 ) ;
* V_219 = V_52 . V_219 ;
return V_7 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_250 , T_9 V_4 ,
T_9 * V_219 , const T_3 * V_25 )
{
struct V_51 V_52 ;
int V_7 ;
F_27 ( V_2 , V_62 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_4 = V_4 ;
V_52 . V_208 = ( T_3 * ) V_25 ;
V_52 . V_56 = V_57 ;
V_7 = F_103 ( V_2 , V_250 , & V_52 ) ;
* V_219 = V_52 . V_219 ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_250 ,
struct V_51 * V_52 )
{
int V_18 , V_29 , V_111 , V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_14 ,
V_9 , ( unsigned int ) V_250 , ( int ) V_52 -> V_55 ) ;
if ( V_52 -> V_56 == V_188 )
V_4 = V_6 -> V_133 . V_158 -> V_205 ;
else
V_4 = V_2 -> V_143 ;
if ( ( V_52 -> V_54 + V_52 -> V_55 ) > V_4 ) {
F_3 ( L_15 ,
V_9 ) ;
return - V_10 ;
}
if ( F_69 ( V_52 -> V_54 >= V_4 ) ) {
F_3 ( L_16 ,
V_9 ) ;
return - V_10 ;
}
if ( F_69 ( V_250 >= V_2 -> V_118 ||
V_52 -> V_54 + V_52 -> V_55 >
( ( V_2 -> V_118 >> V_6 -> V_37 ) -
( V_250 >> V_6 -> V_37 ) ) * V_4 ) ) {
F_3 ( L_17 ,
V_9 ) ;
return - V_10 ;
}
V_18 = ( int ) ( V_250 >> V_6 -> V_39 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
V_29 = ( int ) ( V_250 >> V_6 -> V_37 ) ;
V_6 -> V_44 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_35 ( V_2 ) ) {
V_6 -> V_41 ( V_2 , - 1 ) ;
return - V_258 ;
}
if ( V_29 == V_6 -> V_211 )
V_6 -> V_211 = - 1 ;
F_102 ( V_2 , V_52 -> V_53 , V_52 -> V_55 , V_52 ) ;
if ( V_52 -> V_56 == V_187 )
V_111 = V_6 -> V_133 . V_259 ( V_2 , V_6 , V_29 & V_6 -> V_38 ) ;
else
V_111 = V_6 -> V_133 . V_260 ( V_2 , V_6 , V_29 & V_6 -> V_38 ) ;
V_6 -> V_41 ( V_2 , - 1 ) ;
if ( V_111 )
return V_111 ;
V_52 -> V_220 = V_52 -> V_55 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 , T_1 V_250 ,
struct V_51 * V_52 )
{
int V_7 = - V_232 ;
V_52 -> V_219 = 0 ;
if ( V_52 -> V_208 && ( V_250 + V_52 -> V_4 ) > V_2 -> V_118 ) {
F_3 ( L_17 ,
V_9 ) ;
return - V_10 ;
}
F_27 ( V_2 , V_62 ) ;
switch ( V_52 -> V_56 ) {
case V_57 :
case V_188 :
case V_187 :
break;
default:
goto V_78;
}
if ( ! V_52 -> V_208 )
V_7 = F_31 ( V_2 , V_250 , V_52 ) ;
else
V_7 = F_103 ( V_2 , V_250 , V_52 ) ;
V_78:
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_109 ( struct V_1 * V_2 , int V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_44 ( V_2 , V_94 , - 1 , V_29 ) ;
V_6 -> V_44 ( V_2 , V_95 , - 1 , - 1 ) ;
return V_6 -> V_115 ( V_2 , V_6 ) ;
}
static int F_110 ( struct V_1 * V_2 , struct V_59 * V_261 )
{
return F_33 ( V_2 , V_261 , 0 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_59 * V_261 ,
int V_70 )
{
int V_29 , V_111 , V_262 , V_7 , V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 ;
F_3 ( L_5 ,
V_9 , ( unsigned long long ) V_261 -> V_61 ,
( unsigned long long ) V_261 -> V_4 ) ;
if ( F_1 ( V_2 , V_261 -> V_61 , V_261 -> V_4 ) )
return - V_10 ;
F_27 ( V_2 , V_263 ) ;
V_29 = ( int ) ( V_261 -> V_61 >> V_6 -> V_37 ) ;
V_18 = ( int ) ( V_261 -> V_61 >> V_6 -> V_39 ) ;
V_262 = 1 << ( V_6 -> V_8 - V_6 -> V_37 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
if ( F_35 ( V_2 ) ) {
F_3 ( L_6 ,
V_9 ) ;
V_261 -> V_14 = V_121 ;
goto V_264;
}
V_4 = V_261 -> V_4 ;
V_261 -> V_14 = V_265 ;
while ( V_4 ) {
if ( F_38 ( V_2 , ( ( T_1 ) V_29 ) <<
V_6 -> V_37 , 0 , V_70 ) ) {
F_111 ( L_18 ,
V_9 , V_29 ) ;
V_261 -> V_14 = V_121 ;
goto V_264;
}
if ( V_29 <= V_6 -> V_211 && V_6 -> V_211 <
( V_29 + V_262 ) )
V_6 -> V_211 = - 1 ;
V_111 = V_6 -> V_266 ( V_2 , V_29 & V_6 -> V_38 ) ;
if ( ( V_111 & V_116 ) && ( V_6 -> V_248 ) )
V_111 = V_6 -> V_248 ( V_2 , V_6 , V_263 ,
V_111 , V_29 ) ;
if ( V_111 & V_116 ) {
F_3 ( L_19 ,
V_9 , V_29 ) ;
V_261 -> V_14 = V_121 ;
V_261 -> V_267 =
( ( T_1 ) V_29 << V_6 -> V_37 ) ;
goto V_264;
}
V_4 -= ( 1ULL << V_6 -> V_8 ) ;
V_29 += V_262 ;
if ( V_4 && ! ( V_29 & V_6 -> V_38 ) ) {
V_18 ++ ;
V_6 -> V_41 ( V_2 , - 1 ) ;
V_6 -> V_41 ( V_2 , V_18 ) ;
}
}
V_261 -> V_14 = V_268 ;
V_264:
V_7 = V_261 -> V_14 == V_268 ? 0 : - V_117 ;
V_6 -> V_41 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
if ( ! V_7 )
F_112 ( V_261 ) ;
return V_7 ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_3 ( L_20 , V_9 ) ;
F_27 ( V_2 , V_269 ) ;
F_4 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 , T_1 V_270 )
{
return F_38 ( V_2 , V_270 , 1 , 0 ) ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_7 ;
V_7 = F_114 ( V_2 , V_3 ) ;
if ( V_7 ) {
if ( V_7 > 0 )
return 0 ;
return V_7 ;
}
return F_32 ( V_2 , V_3 ) ;
}
static int F_116 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_61 , T_3 * V_271 )
{
int V_111 ;
int V_31 ;
if ( ! V_6 -> V_272 ||
! ( F_117 ( V_6 -> V_273 . V_274 )
& V_275 ) )
return - V_10 ;
V_6 -> V_44 ( V_2 , V_276 , V_61 , - 1 ) ;
for ( V_31 = 0 ; V_31 < V_277 ; ++ V_31 )
V_6 -> V_278 ( V_2 , V_271 [ V_31 ] ) ;
V_111 = V_6 -> V_115 ( V_2 , V_6 ) ;
if ( V_111 & V_116 )
return - V_117 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_61 , T_3 * V_271 )
{
int V_31 ;
if ( ! V_6 -> V_272 ||
! ( F_117 ( V_6 -> V_273 . V_274 )
& V_275 ) )
return - V_10 ;
V_6 -> V_44 ( V_2 , V_279 , V_61 , - 1 ) ;
for ( V_31 = 0 ; V_31 < V_277 ; ++ V_31 )
* V_271 ++ = V_6 -> V_48 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
return F_27 ( V_2 , V_109 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_14 == V_109 )
F_4 ( V_2 ) ;
else
F_121 ( L_21 ,
V_9 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_109 ) ;
}
static void F_123 ( struct V_5 * V_6 , int V_179 )
{
if ( ! V_6 -> V_97 )
V_6 -> V_97 = 20 ;
if ( V_6 -> V_44 == NULL )
V_6 -> V_44 = F_51 ;
if ( V_6 -> V_115 == NULL )
V_6 -> V_115 = F_63 ;
if ( ! V_6 -> V_41 )
V_6 -> V_41 = F_14 ;
if ( ! V_6 -> V_280 )
V_6 -> V_280 = F_116 ;
if ( ! V_6 -> V_281 )
V_6 -> V_281 = F_118 ;
if ( ! V_6 -> V_48 || V_6 -> V_48 == F_8 )
V_6 -> V_48 = V_179 ? F_10 : F_8 ;
if ( ! V_6 -> V_47 )
V_6 -> V_47 = F_13 ;
if ( ! V_6 -> V_71 )
V_6 -> V_71 = F_26 ;
if ( ! V_6 -> V_63 )
V_6 -> V_63 = F_30 ;
if ( ! V_6 -> V_23 || V_6 -> V_23 == F_18 )
V_6 -> V_23 = V_179 ? F_22 : F_18 ;
if ( ! V_6 -> V_278 || V_6 -> V_278 == F_16 )
V_6 -> V_278 = V_179 ? F_17 : F_16 ;
if ( ! V_6 -> V_141 || V_6 -> V_141 == F_20 )
V_6 -> V_141 = V_179 ? F_24 : F_20 ;
if ( ! V_6 -> V_282 )
V_6 -> V_282 = V_283 ;
if ( ! V_6 -> V_11 ) {
V_6 -> V_11 = & V_6 -> V_284 ;
F_124 ( & V_6 -> V_11 -> V_12 ) ;
F_125 ( & V_6 -> V_11 -> V_16 ) ;
}
}
static void F_126 ( T_3 * V_285 , T_9 V_4 )
{
T_10 V_31 ;
V_285 [ V_4 - 1 ] = 0 ;
for ( V_31 = 0 ; V_31 < V_4 - 1 ; V_31 ++ ) {
if ( V_285 [ V_31 ] < ' ' || V_285 [ V_31 ] > 127 )
V_285 [ V_31 ] = '?' ;
}
F_127 ( V_285 ) ;
}
static T_4 F_128 ( T_4 V_286 , T_11 const * V_27 , T_9 V_4 )
{
int V_31 ;
while ( V_4 -- ) {
V_286 ^= * V_27 ++ << 8 ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_286 = ( V_286 << 1 ) ^ ( ( V_286 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_286 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_287 * V_27 )
{
struct V_288 * V_289 ;
struct V_290 * V_285 ;
struct V_291 * V_133 ;
T_3 * V_292 ;
int V_7 = - V_10 ;
int V_4 ;
int V_31 ;
V_4 = F_117 ( V_27 -> V_293 ) * 16 ;
V_289 = F_130 ( V_4 , V_294 ) ;
if ( ! V_289 )
return - V_295 ;
V_6 -> V_44 ( V_2 , V_296 , 0 , - 1 ) ;
V_6 -> V_44 ( V_2 , V_102 ,
sizeof( * V_27 ) * V_27 -> V_297 , - 1 ) ;
V_6 -> V_141 ( V_2 , ( T_3 * ) V_289 , V_4 ) ;
if ( ( F_128 ( V_298 , ( ( T_3 * ) V_289 ) + 2 , V_4 - 2 )
!= F_117 ( V_289 -> V_286 ) ) ) {
F_3 ( L_22 ) ;
goto V_299;
}
if ( strncmp ( V_289 -> V_300 , L_23 , 4 ) ) {
F_3 ( L_24 ) ;
goto V_299;
}
V_292 = ( T_3 * ) ( V_289 + 1 ) ;
for ( V_31 = 0 ; V_31 < V_301 ; V_31 ++ ) {
V_285 = V_289 -> V_302 + V_31 ;
if ( V_285 -> type == V_303 )
break;
V_292 += V_285 -> V_193 * 16 ;
}
if ( V_31 == V_301 ) {
F_3 ( L_25 ) ;
goto V_299;
}
V_133 = (struct V_291 * ) V_292 ;
if ( ! V_133 -> V_304 ) {
F_3 ( L_26 ) ;
goto V_299;
}
V_6 -> V_305 = V_133 -> V_306 ;
V_6 -> V_307 = 1 << V_133 -> V_304 ;
V_7 = 0 ;
V_299:
F_131 ( V_289 ) ;
return V_7 ;
}
static int F_132 ( struct V_1 * V_2 , int V_195 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_308 [ V_277 ] = { V_195 } ;
return V_6 -> V_280 ( V_2 , V_6 , V_309 ,
V_308 ) ;
}
static void F_133 ( struct V_5 * V_6 ,
struct V_287 * V_27 )
{
struct V_310 * V_311 = ( void * ) V_27 -> V_312 ;
if ( F_117 ( V_27 -> V_313 ) < 1 )
return;
V_6 -> V_196 = V_311 -> V_314 ;
V_6 -> V_197 = F_132 ;
}
static int F_134 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_179 )
{
struct V_287 * V_27 = & V_6 -> V_273 ;
int V_31 , V_315 ;
int V_316 ;
V_6 -> V_44 ( V_2 , V_317 , 0x20 , - 1 ) ;
if ( V_6 -> V_48 ( V_2 ) != 'O' || V_6 -> V_48 ( V_2 ) != 'N' ||
V_6 -> V_48 ( V_2 ) != 'F' || V_6 -> V_48 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_44 ( V_2 , V_296 , 0 , - 1 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
for ( V_315 = 0 ; V_315 < sizeof( * V_27 ) ; V_315 ++ )
( ( T_3 * ) V_27 ) [ V_315 ] = V_6 -> V_48 ( V_2 ) ;
if ( F_128 ( V_298 , ( T_3 * ) V_27 , 254 ) ==
F_117 ( V_27 -> V_286 ) ) {
break;
}
}
if ( V_31 == 3 ) {
F_121 ( L_27 ) ;
return 0 ;
}
V_316 = F_117 ( V_27 -> V_318 ) ;
if ( V_316 & ( 1 << 5 ) )
V_6 -> V_272 = 23 ;
else if ( V_316 & ( 1 << 4 ) )
V_6 -> V_272 = 22 ;
else if ( V_316 & ( 1 << 3 ) )
V_6 -> V_272 = 21 ;
else if ( V_316 & ( 1 << 2 ) )
V_6 -> V_272 = 20 ;
else if ( V_316 & ( 1 << 1 ) )
V_6 -> V_272 = 10 ;
if ( ! V_6 -> V_272 ) {
F_135 ( L_28 , V_316 ) ;
return 0 ;
}
F_126 ( V_27 -> V_319 , sizeof( V_27 -> V_319 ) ) ;
F_126 ( V_27 -> V_320 , sizeof( V_27 -> V_320 ) ) ;
if ( ! V_2 -> V_321 )
V_2 -> V_321 = V_27 -> V_320 ;
V_2 -> V_36 = F_136 ( V_27 -> V_322 ) ;
V_2 -> V_35 = 1 << ( F_137 ( F_136 ( V_27 -> V_262 ) ) - 1 ) ;
V_2 -> V_35 *= V_2 -> V_36 ;
V_2 -> V_143 = F_117 ( V_27 -> V_323 ) ;
V_6 -> V_91 = 1 << ( F_137 ( F_136 ( V_27 -> V_324 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_35 * V_27 -> V_325 ;
V_6 -> V_326 = V_27 -> V_326 ;
if ( F_138 ( V_6 ) & V_327 )
* V_179 = V_43 ;
else
* V_179 = 0 ;
if ( V_27 -> V_306 != 0xff ) {
V_6 -> V_305 = V_27 -> V_306 ;
V_6 -> V_307 = 512 ;
} else if ( V_6 -> V_272 >= 21 &&
( F_138 ( V_6 ) & V_328 ) ) {
if ( V_2 -> V_36 > 512 && V_6 -> V_44 == F_51 )
V_6 -> V_44 = F_55 ;
if ( F_129 ( V_2 , V_6 , V_27 ) )
F_111 ( L_29 ) ;
} else {
F_111 ( L_30 ) ;
}
if ( V_27 -> V_329 == V_330 )
F_133 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_139 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_179 )
{
struct V_331 * V_27 = & V_6 -> V_332 ;
struct V_333 * V_133 ;
int V_316 ;
int V_31 , V_315 ;
V_6 -> V_44 ( V_2 , V_317 , 0x40 , - 1 ) ;
if ( V_6 -> V_48 ( V_2 ) != 'J' || V_6 -> V_48 ( V_2 ) != 'E' ||
V_6 -> V_48 ( V_2 ) != 'D' || V_6 -> V_48 ( V_2 ) != 'E' ||
V_6 -> V_48 ( V_2 ) != 'C' )
return 0 ;
V_6 -> V_44 ( V_2 , V_296 , 0x40 , - 1 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
for ( V_315 = 0 ; V_315 < sizeof( * V_27 ) ; V_315 ++ )
( ( T_3 * ) V_27 ) [ V_315 ] = V_6 -> V_48 ( V_2 ) ;
if ( F_128 ( V_298 , ( T_3 * ) V_27 , 510 ) ==
F_117 ( V_27 -> V_286 ) )
break;
}
if ( V_31 == 3 ) {
F_121 ( L_31 ) ;
return 0 ;
}
V_316 = F_117 ( V_27 -> V_318 ) ;
if ( V_316 & ( 1 << 2 ) )
V_6 -> V_334 = 10 ;
else if ( V_316 & ( 1 << 1 ) )
V_6 -> V_334 = 1 ;
if ( ! V_6 -> V_334 ) {
F_135 ( L_32 , V_316 ) ;
return 0 ;
}
F_126 ( V_27 -> V_319 , sizeof( V_27 -> V_319 ) ) ;
F_126 ( V_27 -> V_320 , sizeof( V_27 -> V_320 ) ) ;
if ( ! V_2 -> V_321 )
V_2 -> V_321 = V_27 -> V_320 ;
V_2 -> V_36 = F_136 ( V_27 -> V_322 ) ;
V_2 -> V_35 = 1 << ( F_137 ( F_136 ( V_27 -> V_262 ) ) - 1 ) ;
V_2 -> V_35 *= V_2 -> V_36 ;
V_2 -> V_143 = F_117 ( V_27 -> V_323 ) ;
V_6 -> V_91 = 1 << ( F_137 ( F_136 ( V_27 -> V_324 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_35 * V_27 -> V_325 ;
V_6 -> V_326 = V_27 -> V_326 ;
if ( F_140 ( V_6 ) & V_335 )
* V_179 = V_43 ;
else
* V_179 = 0 ;
V_133 = & V_27 -> V_336 [ 0 ] ;
if ( V_133 -> V_304 >= 9 ) {
V_6 -> V_305 = V_133 -> V_306 ;
V_6 -> V_307 = 1 << V_133 -> V_304 ;
} else {
F_111 ( L_26 ) ;
}
return 1 ;
}
static int F_141 ( T_11 * V_337 , int V_338 , int V_339 )
{
int V_31 , V_315 ;
for ( V_31 = 0 ; V_31 < V_339 ; V_31 ++ )
for ( V_315 = V_31 + V_339 ; V_315 < V_338 ; V_315 += V_339 )
if ( V_337 [ V_31 ] != V_337 [ V_315 ] )
return 0 ;
return 1 ;
}
static int F_142 ( T_11 * V_337 , int V_338 )
{
int V_340 , V_339 ;
for ( V_340 = V_338 - 1 ; V_340 >= 0 ; V_340 -- )
if ( V_337 [ V_340 ] )
break;
if ( V_340 < 0 )
return 0 ;
for ( V_339 = 1 ; V_339 < V_338 ; V_339 ++ )
if ( F_141 ( V_337 , V_338 , V_339 ) )
break;
if ( V_339 < V_338 )
return V_339 ;
if ( V_340 < V_338 - 1 )
return V_340 + 1 ;
return V_338 ;
}
static int F_143 ( T_11 V_341 )
{
int V_342 ;
V_342 = V_341 & V_343 ;
V_342 >>= V_344 ;
return V_342 + 1 ;
}
static void F_144 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_11 V_337 [ 8 ] , int * V_179 )
{
int V_345 , V_346 ;
V_6 -> V_326 = F_143 ( V_337 [ 2 ] ) ;
V_345 = V_337 [ 3 ] ;
V_346 = F_142 ( V_337 , 8 ) ;
if ( V_346 == 6 && V_337 [ 0 ] == V_347 &&
! F_145 ( V_6 ) && V_337 [ 5 ] != 0x00 ) {
V_2 -> V_36 = 2048 << ( V_345 & 0x03 ) ;
V_345 >>= 2 ;
switch ( ( ( V_345 >> 2 ) & 0x04 ) | ( V_345 & 0x03 ) ) {
case 1 :
V_2 -> V_143 = 128 ;
break;
case 2 :
V_2 -> V_143 = 218 ;
break;
case 3 :
V_2 -> V_143 = 400 ;
break;
case 4 :
V_2 -> V_143 = 436 ;
break;
case 5 :
V_2 -> V_143 = 512 ;
break;
case 6 :
V_2 -> V_143 = 640 ;
break;
case 7 :
default:
V_2 -> V_143 = 1024 ;
break;
}
V_345 >>= 2 ;
V_2 -> V_35 = ( 128 * 1024 ) <<
( ( ( V_345 >> 1 ) & 0x04 ) | ( V_345 & 0x03 ) ) ;
* V_179 = 0 ;
} else if ( V_346 == 6 && V_337 [ 0 ] == V_348 &&
! F_145 ( V_6 ) ) {
unsigned int V_349 ;
V_2 -> V_36 = 2048 << ( V_345 & 0x03 ) ;
V_345 >>= 2 ;
switch ( ( ( V_345 >> 2 ) & 0x04 ) | ( V_345 & 0x03 ) ) {
case 0 :
V_2 -> V_143 = 128 ;
break;
case 1 :
V_2 -> V_143 = 224 ;
break;
case 2 :
V_2 -> V_143 = 448 ;
break;
case 3 :
V_2 -> V_143 = 64 ;
break;
case 4 :
V_2 -> V_143 = 32 ;
break;
case 5 :
V_2 -> V_143 = 16 ;
break;
default:
V_2 -> V_143 = 640 ;
break;
}
V_345 >>= 2 ;
V_349 = ( ( V_345 >> 1 ) & 0x04 ) | ( V_345 & 0x03 ) ;
if ( V_349 < 0x03 )
V_2 -> V_35 = ( 128 * 1024 ) << V_349 ;
else if ( V_349 == 0x03 )
V_2 -> V_35 = 768 * 1024 ;
else
V_2 -> V_35 = ( 64 * 1024 ) << V_349 ;
* V_179 = 0 ;
} else {
V_2 -> V_36 = 1024 << ( V_345 & 0x03 ) ;
V_345 >>= 2 ;
V_2 -> V_143 = ( 8 << ( V_345 & 0x01 ) ) *
( V_2 -> V_36 >> 9 ) ;
V_345 >>= 2 ;
V_2 -> V_35 = ( 64 * 1024 ) << ( V_345 & 0x03 ) ;
V_345 >>= 2 ;
* V_179 = ( V_345 & 0x01 ) ? V_43 : 0 ;
if ( V_346 >= 6 && V_337 [ 0 ] == V_350 &&
F_145 ( V_6 ) &&
( V_337 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_337 [ 4 ] & 0x80 ) ) {
V_2 -> V_143 = 32 * V_2 -> V_36 >> 9 ;
}
}
}
static void F_146 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_351 * type , T_11 V_337 [ 8 ] ,
int * V_179 )
{
int V_352 = V_337 [ 0 ] ;
V_2 -> V_35 = type -> V_35 ;
V_2 -> V_36 = type -> V_353 ;
V_2 -> V_143 = V_2 -> V_36 / 32 ;
* V_179 = type -> V_42 & V_43 ;
V_6 -> V_326 = 1 ;
if ( V_352 == V_354 && V_337 [ 4 ] != 0x00 && V_337 [ 5 ] == 0x00
&& V_337 [ 6 ] == 0x00 && V_337 [ 7 ] == 0x00
&& V_2 -> V_36 == 512 ) {
V_2 -> V_35 = 128 * 1024 ;
V_2 -> V_35 <<= ( ( V_337 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_147 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_11 V_337 [ 8 ] )
{
int V_352 = V_337 [ 0 ] ;
if ( V_2 -> V_36 > 512 || ( V_6 -> V_42 & V_43 ) )
V_6 -> V_46 = V_355 ;
else
V_6 -> V_46 = V_356 ;
if ( ! F_145 ( V_6 ) &&
( V_352 == V_347 ||
V_352 == V_348 ) )
V_6 -> V_33 |= V_34 ;
else if ( ( F_145 ( V_6 ) &&
( V_352 == V_347 ||
V_352 == V_348 ||
V_352 == V_350 ||
V_352 == V_354 ||
V_352 == V_357 ) ) ||
( V_2 -> V_36 == 2048 &&
V_352 == V_330 ) )
V_6 -> V_33 |= V_50 ;
}
static inline bool F_148 ( struct V_351 * type )
{
return type -> V_346 ;
}
static bool F_149 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_351 * type , T_11 * V_337 , int * V_179 )
{
if ( ! strncmp ( type -> V_358 , V_337 , type -> V_346 ) ) {
V_2 -> V_36 = type -> V_353 ;
V_2 -> V_35 = type -> V_35 ;
V_2 -> V_143 = type -> V_143 ;
V_6 -> V_326 = F_143 ( V_337 [ 2 ] ) ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
V_6 -> V_42 |= type -> V_42 ;
V_6 -> V_305 = F_150 ( type ) ;
V_6 -> V_307 = F_151 ( type ) ;
V_6 -> V_359 =
type -> V_359 ;
* V_179 = type -> V_42 & V_43 ;
if ( ! V_2 -> V_321 )
V_2 -> V_321 = type -> V_321 ;
return true ;
}
return false ;
}
static struct V_351 * F_152 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int * V_352 , int * V_360 ,
struct V_351 * type )
{
int V_179 ;
int V_31 , V_361 ;
T_11 V_337 [ 8 ] ;
V_6 -> V_41 ( V_2 , 0 ) ;
V_6 -> V_44 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_44 ( V_2 , V_317 , 0x00 , - 1 ) ;
* V_352 = V_6 -> V_48 ( V_2 ) ;
* V_360 = V_6 -> V_48 ( V_2 ) ;
V_6 -> V_44 ( V_2 , V_317 , 0x00 , - 1 ) ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_337 [ V_31 ] = V_6 -> V_48 ( V_2 ) ;
if ( V_337 [ 0 ] != * V_352 || V_337 [ 1 ] != * V_360 ) {
F_135 ( L_33 ,
* V_352 , * V_360 , V_337 [ 0 ] , V_337 [ 1 ] ) ;
return F_153 ( - V_362 ) ;
}
if ( ! type )
type = V_363 ;
for (; type -> V_321 != NULL ; type ++ ) {
if ( F_148 ( type ) ) {
if ( F_149 ( V_2 , V_6 , type , V_337 , & V_179 ) )
goto V_364;
} else if ( * V_360 == type -> V_360 ) {
break;
}
}
V_6 -> V_272 = 0 ;
if ( ! type -> V_321 || ! type -> V_353 ) {
if ( F_134 ( V_2 , V_6 , & V_179 ) )
goto V_364;
if ( F_139 ( V_2 , V_6 , & V_179 ) )
goto V_364;
}
if ( ! type -> V_321 )
return F_153 ( - V_362 ) ;
if ( ! V_2 -> V_321 )
V_2 -> V_321 = type -> V_321 ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
if ( ! type -> V_353 ) {
F_144 ( V_2 , V_6 , V_337 , & V_179 ) ;
} else {
F_146 ( V_2 , V_6 , type , V_337 , & V_179 ) ;
}
V_6 -> V_42 |= type -> V_42 ;
if ( * V_352 != V_347 && ! type -> V_353 )
V_6 -> V_42 &= ~ V_365 ;
V_364:
for ( V_361 = 0 ; V_366 [ V_361 ] . V_358 != 0x0 ; V_361 ++ ) {
if ( V_366 [ V_361 ] . V_358 == * V_352 )
break;
}
if ( V_6 -> V_42 & V_367 ) {
F_64 ( V_6 -> V_42 & V_43 ) ;
V_6 -> V_42 |= V_179 ;
F_123 ( V_6 , V_179 ) ;
} else if ( V_179 != ( V_6 -> V_42 & V_43 ) ) {
F_135 ( L_34 ,
* V_352 , * V_360 ) ;
F_135 ( L_35 , V_366 [ V_361 ] . V_321 , V_2 -> V_321 ) ;
F_111 ( L_36 ,
( V_6 -> V_42 & V_43 ) ? 16 : 8 ,
V_179 ? 16 : 8 ) ;
return F_153 ( - V_10 ) ;
}
F_147 ( V_2 , V_6 , V_337 ) ;
V_6 -> V_37 = F_154 ( V_2 -> V_36 ) - 1 ;
V_6 -> V_38 = ( V_6 -> V_91 >> V_6 -> V_37 ) - 1 ;
V_6 -> V_368 = V_6 -> V_8 =
F_154 ( V_2 -> V_35 ) - 1 ;
if ( V_6 -> V_91 & 0xffffffff )
V_6 -> V_39 = F_154 ( ( unsigned ) V_6 -> V_91 ) - 1 ;
else {
V_6 -> V_39 = F_154 ( ( unsigned ) ( V_6 -> V_91 >> 32 ) ) ;
V_6 -> V_39 += 32 - 1 ;
}
V_6 -> V_49 = 8 ;
V_6 -> V_266 = F_109 ;
if ( V_2 -> V_36 > 512 && V_6 -> V_44 == F_51 )
V_6 -> V_44 = F_55 ;
F_135 ( L_34 ,
* V_352 , * V_360 ) ;
if ( V_6 -> V_272 )
F_135 ( L_35 , V_366 [ V_361 ] . V_321 ,
V_6 -> V_273 . V_320 ) ;
else if ( V_6 -> V_334 )
F_135 ( L_35 , V_366 [ V_361 ] . V_321 ,
V_6 -> V_332 . V_320 ) ;
else
F_135 ( L_35 , V_366 [ V_361 ] . V_321 ,
type -> V_321 ) ;
F_135 ( L_37 ,
( int ) ( V_6 -> V_91 >> 20 ) , F_145 ( V_6 ) ? L_38 : L_39 ,
V_2 -> V_35 >> 10 , V_2 -> V_36 , V_2 -> V_143 ) ;
return type ;
}
static int F_155 ( struct V_5 * V_6 )
{
struct V_369 * V_370 = F_156 ( V_6 ) ;
int V_371 , V_372 , V_373 ;
if ( ! V_370 )
return 0 ;
if ( F_157 ( V_370 ) == 16 )
V_6 -> V_42 |= V_43 ;
if ( F_158 ( V_370 ) )
V_6 -> V_33 |= V_374 ;
V_371 = F_159 ( V_370 ) ;
V_372 = F_160 ( V_370 ) ;
V_373 = F_161 ( V_370 ) ;
if ( ( V_373 >= 0 && ! ( V_372 >= 0 ) ) ||
( ! ( V_373 >= 0 ) && V_372 >= 0 ) ) {
F_121 ( L_40 ) ;
return - V_10 ;
}
if ( V_371 >= 0 )
V_6 -> V_133 . V_56 = V_371 ;
if ( V_372 >= 0 )
V_6 -> V_133 . V_182 = V_372 ;
if ( V_373 > 0 )
V_6 -> V_133 . V_118 = V_373 ;
return 0 ;
}
int F_162 ( struct V_1 * V_2 , int V_375 ,
struct V_351 * V_376 )
{
int V_31 , V_377 , V_378 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_351 * type ;
int V_7 ;
V_7 = F_155 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_2 -> V_321 && V_2 -> V_379 . V_380 )
V_2 -> V_321 = F_163 ( V_2 -> V_379 . V_380 ) ;
F_123 ( V_6 , V_6 -> V_42 & V_43 ) ;
type = F_152 ( V_2 , V_6 , & V_377 ,
& V_378 , V_376 ) ;
if ( F_164 ( type ) ) {
if ( ! ( V_6 -> V_42 & V_381 ) )
F_111 ( L_41 ) ;
V_6 -> V_41 ( V_2 , - 1 ) ;
return F_165 ( type ) ;
}
V_6 -> V_41 ( V_2 , - 1 ) ;
for ( V_31 = 1 ; V_31 < V_375 ; V_31 ++ ) {
V_6 -> V_41 ( V_2 , V_31 ) ;
V_6 -> V_44 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_44 ( V_2 , V_317 , 0x00 , - 1 ) ;
if ( V_377 != V_6 -> V_48 ( V_2 ) ||
V_378 != V_6 -> V_48 ( V_2 ) ) {
V_6 -> V_41 ( V_2 , - 1 ) ;
break;
}
V_6 -> V_41 ( V_2 , - 1 ) ;
}
if ( V_31 > 1 )
F_135 ( L_42 , V_31 ) ;
V_6 -> V_382 = V_31 ;
V_2 -> V_118 = V_31 * V_6 -> V_91 ;
return 0 ;
}
static bool F_166 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_383 * V_133 = & V_6 -> V_133 ;
int V_384 , V_385 ;
if ( V_133 -> V_118 == 0 || V_6 -> V_307 == 0 )
return true ;
V_384 = ( V_2 -> V_36 * V_133 -> V_182 ) / V_133 -> V_118 ;
V_385 = ( V_2 -> V_36 * V_6 -> V_305 ) / V_6 -> V_307 ;
return V_384 >= V_385 && V_133 -> V_182 >= V_6 -> V_305 ;
}
int F_167 ( struct V_1 * V_2 )
{
int V_31 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_383 * V_133 = & V_6 -> V_133 ;
struct V_386 * V_387 ;
F_168 ( ( V_6 -> V_33 & V_58 ) &&
! ( V_6 -> V_33 & V_374 ) ) ;
if ( ! ( V_6 -> V_42 & V_388 ) ) {
V_387 = F_169 ( sizeof( * V_387 ) + V_2 -> V_36
+ V_2 -> V_143 * 3 , V_294 ) ;
if ( ! V_387 )
return - V_295 ;
V_387 -> V_154 = ( T_3 * ) ( V_387 + 1 ) ;
V_387 -> V_156 = V_387 -> V_154 + V_2 -> V_143 ;
V_387 -> V_212 = V_387 -> V_156 + V_2 -> V_143 ;
V_6 -> V_153 = V_387 ;
} else {
if ( ! V_6 -> V_153 )
return - V_295 ;
}
V_6 -> V_142 = V_6 -> V_153 -> V_212 + V_2 -> V_36 ;
if ( ! V_133 -> V_158 && ( V_133 -> V_56 != V_389 ) ) {
switch ( V_2 -> V_143 ) {
case 8 :
V_133 -> V_158 = & V_390 ;
break;
case 16 :
V_133 -> V_158 = & V_391 ;
break;
case 64 :
V_133 -> V_158 = & V_392 ;
break;
case 128 :
V_133 -> V_158 = & V_393 ;
break;
default:
F_111 ( L_43 ,
V_2 -> V_143 ) ;
F_15 () ;
}
}
if ( ! V_6 -> V_247 )
V_6 -> V_247 = F_100 ;
switch ( V_133 -> V_56 ) {
case V_394 :
if ( ! V_133 -> V_161 || ! V_133 -> V_164 || ! V_133 -> V_183 ) {
F_111 ( L_44 ) ;
F_15 () ;
}
if ( ! V_133 -> V_215 )
V_133 -> V_215 = F_78 ;
case V_395 :
if ( ! V_133 -> V_215 )
V_133 -> V_215 = F_77 ;
if ( ! V_133 -> V_247 )
V_133 -> V_247 = F_97 ;
if ( ! V_133 -> V_160 )
V_133 -> V_160 = F_72 ;
if ( ! V_133 -> V_233 )
V_133 -> V_233 = F_94 ;
if ( ! V_133 -> V_230 )
V_133 -> V_230 = F_88 ;
if ( ! V_133 -> V_260 )
V_133 -> V_260 = F_90 ;
if ( ! V_133 -> V_214 )
V_133 -> V_214 = F_76 ;
if ( ! V_133 -> V_246 && V_133 -> V_183 && V_133 -> V_161 )
V_133 -> V_246 = F_98 ;
case V_396 :
if ( ( ! V_133 -> V_161 || ! V_133 -> V_164 || ! V_133 -> V_183 ) &&
( ! V_133 -> V_215 ||
V_133 -> V_215 == F_77 ||
! V_133 -> V_247 ||
V_133 -> V_247 == F_97 ) ) {
F_111 ( L_44 ) ;
F_15 () ;
}
if ( ! V_133 -> V_215 )
V_133 -> V_215 = F_79 ;
if ( ! V_133 -> V_247 )
V_133 -> V_247 = F_99 ;
if ( ! V_133 -> V_160 )
V_133 -> V_160 = F_73 ;
if ( ! V_133 -> V_233 )
V_133 -> V_233 = F_95 ;
if ( ! V_133 -> V_230 )
V_133 -> V_230 = F_89 ;
if ( ! V_133 -> V_260 )
V_133 -> V_260 = F_91 ;
if ( V_2 -> V_36 >= V_133 -> V_118 ) {
if ( ! V_133 -> V_182 ) {
F_111 ( L_45 ) ;
F_15 () ;
}
break;
}
F_111 ( L_46 ,
V_133 -> V_118 , V_2 -> V_36 ) ;
V_133 -> V_56 = V_397 ;
case V_397 :
V_133 -> V_161 = V_398 ;
V_133 -> V_164 = V_399 ;
V_133 -> V_215 = F_74 ;
V_133 -> V_214 = F_76 ;
V_133 -> V_247 = F_96 ;
V_133 -> V_160 = F_72 ;
V_133 -> V_233 = F_94 ;
V_133 -> V_230 = F_88 ;
V_133 -> V_260 = F_90 ;
if ( ! V_133 -> V_118 )
V_133 -> V_118 = 256 ;
V_133 -> V_146 = 3 ;
V_133 -> V_182 = 1 ;
break;
case V_389 :
if ( ! F_170 () ) {
F_111 ( L_47 ) ;
F_15 () ;
}
V_133 -> V_161 = V_400 ;
V_133 -> V_164 = V_401 ;
V_133 -> V_215 = F_74 ;
V_133 -> V_214 = F_76 ;
V_133 -> V_247 = F_96 ;
V_133 -> V_160 = F_72 ;
V_133 -> V_233 = F_94 ;
V_133 -> V_230 = F_88 ;
V_133 -> V_260 = F_90 ;
if ( ! V_133 -> V_118 && ( V_2 -> V_143 >= 64 ) ) {
V_133 -> V_118 = 512 ;
V_133 -> V_182 = 4 ;
}
V_133 -> V_146 = F_171 (
V_133 -> V_182 * F_137 ( 8 * V_133 -> V_118 ) , 8 ) ;
V_133 -> V_402 = F_172 ( V_2 , V_133 -> V_118 , V_133 -> V_146 ,
& V_133 -> V_158 ) ;
if ( ! V_133 -> V_402 ) {
F_111 ( L_48 ) ;
F_15 () ;
}
break;
case V_403 :
F_111 ( L_49 ) ;
V_133 -> V_215 = F_72 ;
V_133 -> V_247 = F_94 ;
V_133 -> V_230 = F_88 ;
V_133 -> V_160 = F_72 ;
V_133 -> V_233 = F_94 ;
V_133 -> V_260 = F_90 ;
V_133 -> V_118 = V_2 -> V_36 ;
V_133 -> V_146 = 0 ;
V_133 -> V_182 = 0 ;
break;
default:
F_111 ( L_50 , V_133 -> V_56 ) ;
F_15 () ;
}
if ( ! V_133 -> V_229 )
V_133 -> V_229 = V_133 -> V_230 ;
if ( ! V_133 -> V_259 )
V_133 -> V_259 = V_133 -> V_260 ;
V_133 -> V_158 -> V_205 = 0 ;
for ( V_31 = 0 ; V_133 -> V_158 -> V_190 [ V_31 ] . V_193
&& V_31 < F_173 ( V_133 -> V_158 -> V_190 ) ; V_31 ++ )
V_133 -> V_158 -> V_205 += V_133 -> V_158 -> V_190 [ V_31 ] . V_193 ;
V_2 -> V_205 = V_133 -> V_158 -> V_205 ;
if ( ! F_166 ( V_2 ) )
F_111 ( L_51 ,
V_2 -> V_321 ) ;
V_133 -> V_148 = V_2 -> V_36 / V_133 -> V_118 ;
if ( V_133 -> V_148 * V_133 -> V_118 != V_2 -> V_36 ) {
F_111 ( L_52 ) ;
F_15 () ;
}
V_133 -> V_162 = V_133 -> V_148 * V_133 -> V_146 ;
if ( ! ( V_6 -> V_42 & V_245 ) && F_145 ( V_6 ) ) {
switch ( V_133 -> V_148 ) {
case 2 :
V_2 -> V_404 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_404 = 2 ;
break;
}
}
V_6 -> V_405 = V_2 -> V_36 >> V_2 -> V_404 ;
V_6 -> V_14 = V_15 ;
V_6 -> V_211 = - 1 ;
switch ( V_133 -> V_56 ) {
case V_397 :
case V_389 :
if ( V_6 -> V_37 > 9 )
V_6 -> V_42 |= V_406 ;
break;
default:
break;
}
V_2 -> type = F_145 ( V_6 ) ? V_407 : V_408 ;
V_2 -> V_409 = ( V_6 -> V_42 & V_410 ) ? V_411 :
V_412 ;
V_2 -> V_413 = F_110 ;
V_2 -> V_414 = NULL ;
V_2 -> V_415 = NULL ;
V_2 -> V_416 = F_87 ;
V_2 -> V_417 = F_107 ;
V_2 -> V_418 = F_106 ;
V_2 -> V_419 = F_93 ;
V_2 -> V_420 = F_108 ;
V_2 -> V_421 = F_113 ;
V_2 -> V_422 = NULL ;
V_2 -> V_423 = NULL ;
V_2 -> V_424 = F_119 ;
V_2 -> V_425 = F_120 ;
V_2 -> V_426 = F_122 ;
V_2 -> V_427 = F_36 ;
V_2 -> V_428 = F_114 ;
V_2 -> V_429 = F_115 ;
V_2 -> V_430 = V_2 -> V_36 ;
V_2 -> V_431 = V_133 -> V_158 ;
V_2 -> V_372 = V_133 -> V_182 ;
V_2 -> V_432 = V_133 -> V_118 ;
if ( ! V_2 -> V_433 )
V_2 -> V_433 = F_171 ( V_2 -> V_372 * 3 , 4 ) ;
if ( V_6 -> V_42 & V_434 )
return 0 ;
return V_6 -> V_282 ( V_2 ) ;
}
int F_174 ( struct V_1 * V_2 , int V_375 )
{
int V_7 ;
if ( ! V_2 -> V_435 && F_175 () ) {
F_176 ( L_53 , V_9 ) ;
F_15 () ;
}
V_7 = F_162 ( V_2 , V_375 , NULL ) ;
if ( ! V_7 )
V_7 = F_167 ( V_2 ) ;
return V_7 ;
}
void F_177 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_133 . V_56 == V_389 )
F_178 ( (struct V_436 * ) V_6 -> V_133 . V_402 ) ;
F_179 ( V_2 ) ;
F_131 ( V_6 -> V_64 ) ;
if ( ! ( V_6 -> V_42 & V_388 ) )
F_131 ( V_6 -> V_153 ) ;
if ( V_6 -> V_437 && V_6 -> V_437 -> V_42
& V_438 )
F_131 ( V_6 -> V_437 ) ;
}
static int T_12 F_180 ( void )
{
F_181 ( L_54 , & V_75 ) ;
return 0 ;
}
static void T_13 F_182 ( void )
{
F_183 ( V_75 ) ;
}
