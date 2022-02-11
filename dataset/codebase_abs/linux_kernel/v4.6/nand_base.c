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
static int F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_28 , V_29 = 0 , V_30 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_31 ;
if ( V_6 -> V_32 & V_33 )
V_3 += V_2 -> V_34 - V_2 -> V_35 ;
V_28 = ( int ) ( V_3 >> V_6 -> V_36 ) & V_6 -> V_37 ;
do {
if ( V_6 -> V_38 & V_39 ) {
V_6 -> V_40 ( V_2 , V_41 ,
V_6 -> V_42 & 0xFE , V_28 ) ;
V_31 = F_11 ( V_6 -> V_43 ( V_2 ) ) ;
if ( V_6 -> V_42 & 0x1 )
V_31 >>= 8 ;
else
V_31 &= 0xFF ;
} else {
V_6 -> V_40 ( V_2 , V_41 , V_6 -> V_42 ,
V_28 ) ;
V_31 = V_6 -> V_44 ( V_2 ) ;
}
if ( F_27 ( V_6 -> V_45 == 8 ) )
V_29 = V_31 != 0xFF ;
else
V_29 = F_28 ( V_31 ) < V_6 -> V_45 ;
V_3 += V_2 -> V_35 ;
V_28 = ( int ) ( V_3 >> V_6 -> V_36 ) & V_6 -> V_37 ;
V_30 ++ ;
} while ( ! V_29 && V_30 < 2 && ( V_6 -> V_32 & V_46 ) );
return V_29 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_47 V_48 ;
T_3 V_25 [ 2 ] = { 0 , 0 } ;
int V_7 = 0 , V_29 , V_30 = 0 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_49 = V_25 ;
V_48 . V_50 = V_6 -> V_42 ;
if ( V_6 -> V_38 & V_39 ) {
V_48 . V_50 &= ~ 0x01 ;
V_48 . V_4 = V_48 . V_51 = 2 ;
} else {
V_48 . V_4 = V_48 . V_51 = 1 ;
}
V_48 . V_52 = V_53 ;
if ( V_6 -> V_32 & V_33 )
V_3 += V_2 -> V_34 - V_2 -> V_35 ;
do {
V_29 = F_30 ( V_2 , V_3 , & V_48 ) ;
if ( ! V_7 )
V_7 = V_29 ;
V_30 ++ ;
V_3 += V_2 -> V_35 ;
} while ( ( V_6 -> V_32 & V_46 ) && V_30 < 2 );
return V_7 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_29 , V_7 = 0 ;
if ( ! ( V_6 -> V_32 & V_54 ) ) {
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_2 = V_2 ;
V_56 . V_57 = V_3 ;
V_56 . V_4 = 1ULL << V_6 -> V_8 ;
F_32 ( V_2 , & V_56 , 0 ) ;
F_33 ( V_2 , V_58 ) ;
V_7 = V_6 -> V_59 ( V_2 , V_3 ) ;
F_4 ( V_2 ) ;
}
if ( V_6 -> V_60 ) {
V_29 = F_34 ( V_2 , V_3 ) ;
if ( ! V_7 )
V_7 = V_29 ;
}
if ( ! V_7 )
V_2 -> V_61 . V_62 ++ ;
return V_7 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_38 & V_63 )
return 0 ;
V_6 -> V_40 ( V_2 , V_64 , - 1 , - 1 ) ;
return ( V_6 -> V_44 ( V_2 ) & V_65 ) ? 0 : 1 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_60 )
return 0 ;
return F_37 ( V_2 , V_3 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_3 , int V_66 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_60 )
return V_6 -> V_67 ( V_2 , V_3 ) ;
return F_39 ( V_2 , V_3 , V_66 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_68 ; V_30 ++ ) {
if ( V_6 -> V_69 ( V_2 ) )
break;
F_41 () ;
F_42 ( 1 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_68 = 400 ;
if ( F_44 () || V_70 )
return F_40 ( V_2 , V_68 ) ;
F_45 ( V_71 , V_72 ) ;
V_68 = V_73 + F_46 ( V_68 ) ;
do {
if ( V_6 -> V_69 ( V_2 ) )
goto V_74;
F_47 () ;
} while ( F_48 ( V_73 , V_68 ) );
if ( ! V_6 -> V_69 ( V_2 ) )
F_49 ( L_3 ) ;
V_74:
F_45 ( V_71 , V_75 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned long V_68 )
{
register struct V_5 * V_6 = F_2 ( V_2 ) ;
V_68 = V_73 + F_46 ( V_68 ) ;
do {
if ( ( V_6 -> V_44 ( V_2 ) & V_76 ) )
break;
F_41 () ;
} while ( F_48 ( V_73 , V_68 ) );
}
static void F_51 ( struct V_1 * V_2 , unsigned int V_77 ,
int V_78 , int V_79 )
{
register struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_80 = V_81 | V_21 ;
if ( V_77 == V_82 ) {
int V_83 ;
if ( V_78 >= V_2 -> V_35 ) {
V_78 -= V_2 -> V_35 ;
V_83 = V_41 ;
} else if ( V_78 < 256 ) {
V_83 = V_84 ;
} else {
V_78 -= 256 ;
V_83 = V_85 ;
}
V_6 -> V_19 ( V_2 , V_83 , V_80 ) ;
V_80 &= ~ V_21 ;
}
V_6 -> V_19 ( V_2 , V_77 , V_80 ) ;
V_80 = V_86 | V_21 ;
if ( V_78 != - 1 ) {
if ( V_6 -> V_38 & V_39 &&
! F_52 ( V_77 ) )
V_78 >>= 1 ;
V_6 -> V_19 ( V_2 , V_78 , V_80 ) ;
V_80 &= ~ V_21 ;
}
if ( V_79 != - 1 ) {
V_6 -> V_19 ( V_2 , V_79 , V_80 ) ;
V_80 &= ~ V_21 ;
V_6 -> V_19 ( V_2 , V_79 >> 8 , V_80 ) ;
if ( V_6 -> V_87 > ( 32 << 20 ) )
V_6 -> V_19 ( V_2 , V_79 >> 16 , V_80 ) ;
}
V_6 -> V_19 ( V_2 , V_20 , V_88 | V_21 ) ;
switch ( V_77 ) {
case V_89 :
case V_90 :
case V_91 :
case V_82 :
case V_64 :
return;
case V_92 :
if ( V_6 -> V_69 )
break;
F_53 ( V_6 -> V_93 ) ;
V_6 -> V_19 ( V_2 , V_64 ,
V_81 | V_21 ) ;
V_6 -> V_19 ( V_2 ,
V_20 , V_88 | V_21 ) ;
F_50 ( V_2 , 250 ) ;
return;
default:
if ( ! V_6 -> V_69 ) {
F_53 ( V_6 -> V_93 ) ;
return;
}
}
F_54 ( 100 ) ;
F_43 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_77 ,
int V_78 , int V_79 )
{
register struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_77 == V_41 ) {
V_78 += V_2 -> V_35 ;
V_77 = V_84 ;
}
V_6 -> V_19 ( V_2 , V_77 , V_88 | V_94 | V_21 ) ;
if ( V_78 != - 1 || V_79 != - 1 ) {
int V_80 = V_21 | V_88 | V_95 ;
if ( V_78 != - 1 ) {
if ( V_6 -> V_38 & V_39 &&
! F_52 ( V_77 ) )
V_78 >>= 1 ;
V_6 -> V_19 ( V_2 , V_78 , V_80 ) ;
V_80 &= ~ V_21 ;
V_6 -> V_19 ( V_2 , V_78 >> 8 , V_80 ) ;
}
if ( V_79 != - 1 ) {
V_6 -> V_19 ( V_2 , V_79 , V_80 ) ;
V_6 -> V_19 ( V_2 , V_79 >> 8 ,
V_88 | V_95 ) ;
if ( V_6 -> V_87 > ( 128 << 20 ) )
V_6 -> V_19 ( V_2 , V_79 >> 16 ,
V_88 | V_95 ) ;
}
}
V_6 -> V_19 ( V_2 , V_20 , V_88 | V_21 ) ;
switch ( V_77 ) {
case V_96 :
case V_89 :
case V_90 :
case V_91 :
case V_82 :
case V_97 :
case V_64 :
return;
case V_92 :
if ( V_6 -> V_69 )
break;
F_53 ( V_6 -> V_93 ) ;
V_6 -> V_19 ( V_2 , V_64 ,
V_88 | V_94 | V_21 ) ;
V_6 -> V_19 ( V_2 , V_20 ,
V_88 | V_21 ) ;
F_50 ( V_2 , 250 ) ;
return;
case V_98 :
V_6 -> V_19 ( V_2 , V_99 ,
V_88 | V_94 | V_21 ) ;
V_6 -> V_19 ( V_2 , V_20 ,
V_88 | V_21 ) ;
return;
case V_84 :
V_6 -> V_19 ( V_2 , V_100 ,
V_88 | V_94 | V_21 ) ;
V_6 -> V_19 ( V_2 , V_20 ,
V_88 | V_21 ) ;
default:
if ( ! V_6 -> V_69 ) {
F_53 ( V_6 -> V_93 ) ;
return;
}
}
F_54 ( 100 ) ;
F_43 ( V_2 ) ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_101 )
{
V_6 -> V_11 -> V_13 = V_6 ;
V_6 -> V_14 = V_101 ;
}
static int
F_33 ( struct V_1 * V_2 , int V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_6 * V_12 = & V_6 -> V_11 -> V_12 ;
T_7 * V_16 = & V_6 -> V_11 -> V_16 ;
F_57 ( V_102 , V_103 ) ;
V_104:
F_5 ( V_12 ) ;
if ( ! V_6 -> V_11 -> V_13 )
V_6 -> V_11 -> V_13 = V_6 ;
if ( V_6 -> V_11 -> V_13 == V_6 && V_6 -> V_14 == V_15 ) {
V_6 -> V_14 = V_101 ;
F_7 ( V_12 ) ;
return 0 ;
}
if ( V_101 == V_105 ) {
if ( V_6 -> V_11 -> V_13 -> V_14 == V_105 ) {
V_6 -> V_14 = V_105 ;
F_7 ( V_12 ) ;
return 0 ;
}
}
F_58 ( V_106 ) ;
F_59 ( V_16 , & V_102 ) ;
F_7 ( V_12 ) ;
F_60 () ;
F_61 ( V_16 , & V_102 ) ;
goto V_104;
}
static void F_62 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_68 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_68 ; V_30 ++ ) {
if ( V_6 -> V_69 ) {
if ( V_6 -> V_69 ( V_2 ) )
break;
} else {
if ( V_6 -> V_44 ( V_2 ) & V_76 )
break;
}
F_42 ( 1 ) ;
}
}
static int F_63 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_107 ;
unsigned long V_68 = 400 ;
F_45 ( V_71 , V_72 ) ;
F_54 ( 100 ) ;
V_6 -> V_40 ( V_2 , V_64 , - 1 , - 1 ) ;
if ( F_44 () || V_70 )
F_62 ( V_2 , V_6 , V_68 ) ;
else {
V_68 = V_73 + F_46 ( V_68 ) ;
do {
if ( V_6 -> V_69 ) {
if ( V_6 -> V_69 ( V_2 ) )
break;
} else {
if ( V_6 -> V_44 ( V_2 ) & V_76 )
break;
}
F_47 () ;
} while ( F_48 ( V_73 , V_68 ) );
}
F_45 ( V_71 , V_75 ) ;
V_107 = ( int ) V_6 -> V_44 ( V_2 ) ;
F_64 ( ! ( V_107 & V_76 ) ) ;
return V_107 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_108 )
{
int V_7 = 0 ;
int V_107 , V_28 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_28 = V_3 >> V_6 -> V_36 ;
V_6 -> V_40 ( V_2 , V_109 , - 1 , V_28 & V_6 -> V_37 ) ;
V_28 = ( V_3 + V_4 ) >> V_6 -> V_36 ;
V_6 -> V_40 ( V_2 , V_110 , - 1 ,
( V_28 | V_108 ) & V_6 -> V_37 ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
if ( V_107 & V_112 ) {
F_3 ( L_4 ,
V_9 , V_107 ) ;
V_7 = - V_113 ;
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
if ( V_3 + V_4 == V_2 -> V_114 )
V_4 -= V_2 -> V_34 ;
F_33 ( V_2 , V_115 ) ;
V_18 = V_3 >> V_6 -> V_116 ;
V_6 -> V_117 ( V_2 , V_18 ) ;
V_6 -> V_40 ( V_2 , V_92 , - 1 , - 1 ) ;
if ( F_35 ( V_2 ) ) {
F_3 ( L_6 ,
V_9 ) ;
V_7 = - V_113 ;
goto V_74;
}
V_7 = F_65 ( V_2 , V_3 , V_4 , 0 ) ;
V_74:
V_6 -> V_117 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
return V_7 ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_7 = 0 ;
int V_18 , V_107 , V_28 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_5 ,
V_9 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_10 ;
F_33 ( V_2 , V_118 ) ;
V_18 = V_3 >> V_6 -> V_116 ;
V_6 -> V_117 ( V_2 , V_18 ) ;
V_6 -> V_40 ( V_2 , V_92 , - 1 , - 1 ) ;
if ( F_35 ( V_2 ) ) {
F_3 ( L_6 ,
V_9 ) ;
V_107 = V_119 ;
V_7 = - V_113 ;
goto V_74;
}
V_28 = V_3 >> V_6 -> V_36 ;
V_6 -> V_40 ( V_2 , V_120 , - 1 , V_28 & V_6 -> V_37 ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
if ( V_107 & V_112 ) {
F_3 ( L_4 ,
V_9 , V_107 ) ;
V_7 = - V_113 ;
goto V_74;
}
V_7 = F_65 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_74:
V_6 -> V_117 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_68 ( void * V_25 , int V_4 , int V_121 )
{
const unsigned char * V_122 = V_25 ;
int V_123 = 0 ;
int V_124 ;
for (; V_4 && ( ( V_125 ) V_122 ) % sizeof( long ) ;
V_4 -- , V_122 ++ ) {
V_124 = F_28 ( * V_122 ) ;
V_123 += V_126 - V_124 ;
if ( F_69 ( V_123 > V_121 ) )
return - V_127 ;
}
for (; V_4 >= sizeof( long ) ;
V_4 -= sizeof( long ) , V_122 += sizeof( long ) ) {
V_124 = F_70 ( * ( ( unsigned long * ) V_122 ) ) ;
V_123 += V_128 - V_124 ;
if ( F_69 ( V_123 > V_121 ) )
return - V_127 ;
}
for (; V_4 > 0 ; V_4 -- , V_122 ++ ) {
V_124 = F_28 ( * V_122 ) ;
V_123 += V_126 - V_124 ;
if ( F_69 ( V_123 > V_121 ) )
return - V_127 ;
}
return V_123 ;
}
int F_71 ( void * V_129 , int V_130 ,
void * V_131 , int V_132 ,
void * V_133 , int V_134 ,
int V_121 )
{
int V_135 = 0 , V_136 = 0 , V_137 = 0 ;
V_135 = F_68 ( V_129 , V_130 ,
V_121 ) ;
if ( V_135 < 0 )
return V_135 ;
V_121 -= V_135 ;
V_136 = F_68 ( V_131 , V_132 , V_121 ) ;
if ( V_136 < 0 )
return V_136 ;
V_121 -= V_136 ;
V_137 = F_68 ( V_133 , V_134 ,
V_121 ) ;
if ( V_137 < 0 )
return V_137 ;
if ( V_135 )
memset ( V_129 , 0xff , V_130 ) ;
if ( V_136 )
memset ( V_131 , 0xff , V_132 ) ;
if ( V_137 )
memset ( V_133 , 0xff , V_134 ) ;
return V_135 + V_136 + V_137 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_138 , int V_28 )
{
V_6 -> V_139 ( V_2 , V_25 , V_2 -> V_35 ) ;
if ( V_138 )
V_6 -> V_139 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_25 ,
int V_138 , int V_28 )
{
int V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
T_3 * V_145 = V_6 -> V_140 ;
int V_146 , V_114 ;
for ( V_146 = V_6 -> V_131 . V_146 ; V_146 > 0 ; V_146 -- ) {
V_6 -> V_139 ( V_2 , V_25 , V_142 ) ;
V_25 += V_142 ;
if ( V_6 -> V_131 . V_147 ) {
V_6 -> V_139 ( V_2 , V_145 , V_6 -> V_131 . V_147 ) ;
V_145 += V_6 -> V_131 . V_147 ;
}
V_6 -> V_139 ( V_2 , V_145 , V_143 ) ;
V_145 += V_143 ;
if ( V_6 -> V_131 . V_148 ) {
V_6 -> V_139 ( V_2 , V_145 , V_6 -> V_131 . V_148 ) ;
V_145 += V_6 -> V_131 . V_148 ;
}
}
V_114 = V_2 -> V_141 - ( V_145 - V_6 -> V_140 ) ;
if ( V_114 )
V_6 -> V_139 ( V_2 , V_145 , V_114 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_138 , int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
T_3 * V_27 = V_25 ;
T_3 * V_150 = V_6 -> V_151 -> V_152 ;
T_3 * V_153 = V_6 -> V_151 -> V_154 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
unsigned int V_157 = 0 ;
V_6 -> V_131 . V_158 ( V_2 , V_6 , V_25 , 1 , V_28 ) ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 )
V_6 -> V_131 . V_159 ( V_2 , V_27 , & V_150 [ V_30 ] ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_160 ; V_30 ++ )
V_153 [ V_30 ] = V_6 -> V_140 [ V_155 [ V_30 ] ] ;
V_149 = V_6 -> V_131 . V_146 ;
V_27 = V_25 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
int V_161 ;
V_161 = V_6 -> V_131 . V_162 ( V_2 , V_27 , & V_153 [ V_30 ] , & V_150 [ V_30 ] ) ;
if ( V_161 < 0 ) {
V_2 -> V_61 . V_163 ++ ;
} else {
V_2 -> V_61 . V_164 += V_161 ;
V_157 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_157 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_165 , T_8 V_166 , T_3 * V_167 ,
int V_28 )
{
int V_168 , V_169 , V_170 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
T_3 * V_27 ;
int V_171 , V_30 , V_172 = 0 ;
int V_173 , V_174 , V_175 , V_176 ;
int V_177 = ( V_6 -> V_38 & V_39 ) ? 2 : 1 ;
int V_178 ;
unsigned int V_157 = 0 ;
V_168 = V_165 / V_6 -> V_131 . V_114 ;
V_169 = ( V_165 + V_166 - 1 ) / V_6 -> V_131 . V_114 ;
V_170 = V_169 - V_168 + 1 ;
V_178 = V_168 * V_6 -> V_131 . V_144 ;
V_173 = V_170 * V_6 -> V_131 . V_114 ;
V_174 = V_170 * V_6 -> V_131 . V_144 ;
V_171 = V_168 * V_6 -> V_131 . V_114 ;
if ( V_171 != 0 )
V_6 -> V_40 ( V_2 , V_98 , V_171 , - 1 ) ;
V_27 = V_167 + V_171 ;
V_6 -> V_139 ( V_2 , V_27 , V_173 ) ;
for ( V_30 = 0 ; V_30 < V_174 ; V_30 += V_6 -> V_131 . V_144 , V_27 += V_6 -> V_131 . V_114 )
V_6 -> V_131 . V_159 ( V_2 , V_27 , & V_6 -> V_151 -> V_152 [ V_30 ] ) ;
for ( V_30 = 0 ; V_30 < V_174 - 1 ; V_30 ++ ) {
if ( V_155 [ V_30 + V_178 ] + 1 != V_155 [ V_30 + V_178 + 1 ] ) {
V_172 = 1 ;
break;
}
}
if ( V_172 ) {
V_6 -> V_40 ( V_2 , V_98 , V_2 -> V_35 , - 1 ) ;
V_6 -> V_139 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
} else {
V_176 = V_155 [ V_178 ] & ~ ( V_177 - 1 ) ;
V_175 = V_174 ;
if ( V_155 [ V_178 ] & ( V_177 - 1 ) )
V_175 ++ ;
if ( V_155 [ V_178 + ( V_170 * V_6 -> V_131 . V_144 ) ] & ( V_177 - 1 ) )
V_175 ++ ;
V_6 -> V_40 ( V_2 , V_98 ,
V_2 -> V_35 + V_176 , - 1 ) ;
V_6 -> V_139 ( V_2 , & V_6 -> V_140 [ V_176 ] , V_175 ) ;
}
for ( V_30 = 0 ; V_30 < V_174 ; V_30 ++ )
V_6 -> V_151 -> V_154 [ V_30 ] = V_6 -> V_140 [ V_155 [ V_30 + V_178 ] ] ;
V_27 = V_167 + V_171 ;
for ( V_30 = 0 ; V_30 < V_174 ; V_30 += V_6 -> V_131 . V_144 , V_27 += V_6 -> V_131 . V_114 ) {
int V_161 ;
V_161 = V_6 -> V_131 . V_162 ( V_2 , V_27 ,
& V_6 -> V_151 -> V_154 [ V_30 ] , & V_6 -> V_151 -> V_152 [ V_30 ] ) ;
if ( V_161 == - V_127 &&
( V_6 -> V_131 . V_38 & V_179 ) ) {
V_161 = F_71 ( V_27 , V_6 -> V_131 . V_114 ,
& V_6 -> V_151 -> V_154 [ V_30 ] ,
V_6 -> V_131 . V_144 ,
NULL , 0 ,
V_6 -> V_131 . V_180 ) ;
}
if ( V_161 < 0 ) {
V_2 -> V_61 . V_163 ++ ;
} else {
V_2 -> V_61 . V_164 += V_161 ;
V_157 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_157 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_138 , int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
T_3 * V_27 = V_25 ;
T_3 * V_150 = V_6 -> V_151 -> V_152 ;
T_3 * V_153 = V_6 -> V_151 -> V_154 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
unsigned int V_157 = 0 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
V_6 -> V_131 . V_181 ( V_2 , V_182 ) ;
V_6 -> V_139 ( V_2 , V_27 , V_142 ) ;
V_6 -> V_131 . V_159 ( V_2 , V_27 , & V_150 [ V_30 ] ) ;
}
V_6 -> V_139 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_160 ; V_30 ++ )
V_153 [ V_30 ] = V_6 -> V_140 [ V_155 [ V_30 ] ] ;
V_149 = V_6 -> V_131 . V_146 ;
V_27 = V_25 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
int V_161 ;
V_161 = V_6 -> V_131 . V_162 ( V_2 , V_27 , & V_153 [ V_30 ] , & V_150 [ V_30 ] ) ;
if ( V_161 == - V_127 &&
( V_6 -> V_131 . V_38 & V_179 ) ) {
V_161 = F_71 ( V_27 , V_142 ,
& V_153 [ V_30 ] , V_143 ,
NULL , 0 ,
V_6 -> V_131 . V_180 ) ;
}
if ( V_161 < 0 ) {
V_2 -> V_61 . V_163 ++ ;
} else {
V_2 -> V_61 . V_164 += V_161 ;
V_157 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_157 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_25 , int V_138 , int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
T_3 * V_27 = V_25 ;
T_3 * V_153 = V_6 -> V_151 -> V_154 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
T_3 * V_150 = V_6 -> V_151 -> V_152 ;
unsigned int V_157 = 0 ;
V_6 -> V_40 ( V_2 , V_41 , 0 , V_28 ) ;
V_6 -> V_139 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
V_6 -> V_40 ( V_2 , V_84 , 0 , V_28 ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_160 ; V_30 ++ )
V_153 [ V_30 ] = V_6 -> V_140 [ V_155 [ V_30 ] ] ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
int V_161 ;
V_6 -> V_131 . V_181 ( V_2 , V_182 ) ;
V_6 -> V_139 ( V_2 , V_27 , V_142 ) ;
V_6 -> V_131 . V_159 ( V_2 , V_27 , & V_150 [ V_30 ] ) ;
V_161 = V_6 -> V_131 . V_162 ( V_2 , V_27 , & V_153 [ V_30 ] , NULL ) ;
if ( V_161 == - V_127 &&
( V_6 -> V_131 . V_38 & V_179 ) ) {
V_161 = F_71 ( V_27 , V_142 ,
& V_153 [ V_30 ] , V_143 ,
NULL , 0 ,
V_6 -> V_131 . V_180 ) ;
}
if ( V_161 < 0 ) {
V_2 -> V_61 . V_163 ++ ;
} else {
V_2 -> V_61 . V_164 += V_161 ;
V_157 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
return V_157 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_25 , int V_138 , int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
int V_183 = V_143 + V_6 -> V_131 . V_147 + V_6 -> V_131 . V_148 ;
T_3 * V_27 = V_25 ;
T_3 * V_145 = V_6 -> V_140 ;
unsigned int V_157 = 0 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
int V_161 ;
V_6 -> V_131 . V_181 ( V_2 , V_182 ) ;
V_6 -> V_139 ( V_2 , V_27 , V_142 ) ;
if ( V_6 -> V_131 . V_147 ) {
V_6 -> V_139 ( V_2 , V_145 , V_6 -> V_131 . V_147 ) ;
V_145 += V_6 -> V_131 . V_147 ;
}
V_6 -> V_131 . V_181 ( V_2 , V_184 ) ;
V_6 -> V_139 ( V_2 , V_145 , V_143 ) ;
V_161 = V_6 -> V_131 . V_162 ( V_2 , V_27 , V_145 , NULL ) ;
V_145 += V_143 ;
if ( V_6 -> V_131 . V_148 ) {
V_6 -> V_139 ( V_2 , V_145 , V_6 -> V_131 . V_148 ) ;
V_145 += V_6 -> V_131 . V_148 ;
}
if ( V_161 == - V_127 &&
( V_6 -> V_131 . V_38 & V_179 ) ) {
V_161 = F_71 ( V_27 , V_6 -> V_131 . V_114 ,
V_145 - V_183 ,
V_183 ,
NULL , 0 ,
V_6 -> V_131 . V_180 ) ;
}
if ( V_161 < 0 ) {
V_2 -> V_61 . V_163 ++ ;
} else {
V_2 -> V_61 . V_164 += V_161 ;
V_157 = F_75 (unsigned int, max_bitflips, stat) ;
}
}
V_30 = V_2 -> V_141 - ( V_145 - V_6 -> V_140 ) ;
if ( V_30 )
V_6 -> V_139 ( V_2 , V_145 , V_30 ) ;
return V_157 ;
}
static T_3 * F_80 ( struct V_5 * V_6 , T_3 * V_145 ,
struct V_47 * V_48 , T_9 V_4 )
{
switch ( V_48 -> V_52 ) {
case V_53 :
case V_185 :
memcpy ( V_145 , V_6 -> V_140 + V_48 -> V_50 , V_4 ) ;
return V_145 + V_4 ;
case V_186 : {
struct V_187 * free = V_6 -> V_131 . V_156 -> V_188 ;
T_8 V_189 = 0 , V_190 = V_48 -> V_50 ;
T_9 V_144 = 0 ;
for (; free -> V_191 && V_4 ; free ++ , V_4 -= V_144 ) {
if ( F_69 ( V_190 ) ) {
if ( V_190 >= free -> V_191 ) {
V_190 -= free -> V_191 ;
continue;
}
V_189 = free -> V_192 + V_190 ;
V_144 = F_81 ( T_9 , V_4 ,
( free -> V_191 - V_190 ) ) ;
V_190 = 0 ;
} else {
V_144 = F_81 ( T_9 , V_4 , free -> V_191 ) ;
V_189 = free -> V_192 ;
}
memcpy ( V_145 , V_6 -> V_140 + V_189 , V_144 ) ;
V_145 += V_144 ;
}
return V_145 ;
}
default:
F_15 () ;
}
return NULL ;
}
static int F_82 ( struct V_1 * V_2 , int V_193 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_7 , V_193 ) ;
if ( V_193 >= V_6 -> V_194 )
return - V_10 ;
if ( ! V_6 -> V_195 )
return - V_196 ;
return V_6 -> V_195 ( V_2 , V_193 ) ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_197 ,
struct V_47 * V_48 )
{
int V_18 , V_28 , V_198 , V_199 , V_144 , V_200 , V_138 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = 0 ;
T_8 V_166 = V_48 -> V_4 ;
T_8 V_201 = V_48 -> V_51 ;
T_8 V_202 = F_84 ( V_2 , V_48 ) ;
T_3 * V_167 , * V_145 , * V_25 ;
int V_203 ;
unsigned int V_157 = 0 ;
int V_193 = 0 ;
bool V_204 = false ;
V_18 = ( int ) ( V_197 >> V_6 -> V_116 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
V_198 = ( int ) ( V_197 >> V_6 -> V_36 ) ;
V_28 = V_198 & V_6 -> V_37 ;
V_199 = ( int ) ( V_197 & ( V_2 -> V_35 - 1 ) ) ;
V_25 = V_48 -> V_205 ;
V_145 = V_48 -> V_49 ;
V_138 = V_145 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_206 = V_2 -> V_61 . V_163 ;
V_144 = F_85 ( V_2 -> V_35 - V_199 , V_166 ) ;
V_200 = ( V_144 == V_2 -> V_35 ) ;
if ( ! V_200 )
V_203 = 1 ;
else if ( V_6 -> V_38 & V_207 )
V_203 = ! F_86 ( V_25 ) ;
else
V_203 = 0 ;
if ( V_198 != V_6 -> V_208 || V_145 ) {
V_167 = V_203 ? V_6 -> V_151 -> V_209 : V_25 ;
if ( V_203 && V_200 )
F_3 ( L_8 ,
V_9 , V_25 ) ;
V_210:
V_6 -> V_40 ( V_2 , V_84 , 0x00 , V_28 ) ;
if ( F_69 ( V_48 -> V_52 == V_185 ) )
V_7 = V_6 -> V_131 . V_158 ( V_2 , V_6 , V_167 ,
V_138 ,
V_28 ) ;
else if ( ! V_200 && F_87 ( V_6 ) &&
! V_145 )
V_7 = V_6 -> V_131 . V_211 ( V_2 , V_6 ,
V_199 , V_144 , V_167 ,
V_28 ) ;
else
V_7 = V_6 -> V_131 . V_212 ( V_2 , V_6 , V_167 ,
V_138 , V_28 ) ;
if ( V_7 < 0 ) {
if ( V_203 )
V_6 -> V_208 = - 1 ;
break;
}
V_157 = F_75 (unsigned int, max_bitflips, ret) ;
if ( V_203 ) {
if ( ! F_87 ( V_6 ) && ! V_145 &&
! ( V_2 -> V_61 . V_163 - V_206 ) &&
( V_48 -> V_52 != V_185 ) ) {
V_6 -> V_208 = V_198 ;
V_6 -> V_213 = V_7 ;
} else {
V_6 -> V_208 = - 1 ;
}
memcpy ( V_25 , V_6 -> V_151 -> V_209 + V_199 , V_144 ) ;
}
if ( F_69 ( V_145 ) ) {
int V_214 = F_85 ( V_201 , V_202 ) ;
if ( V_214 ) {
V_145 = F_80 ( V_6 ,
V_145 , V_48 , V_214 ) ;
V_201 -= V_214 ;
}
}
if ( V_6 -> V_38 & V_215 ) {
if ( ! V_6 -> V_69 )
F_53 ( V_6 -> V_93 ) ;
else
F_43 ( V_2 ) ;
}
if ( V_2 -> V_61 . V_163 - V_206 ) {
if ( V_193 + 1 < V_6 -> V_194 ) {
V_193 ++ ;
V_7 = F_82 ( V_2 ,
V_193 ) ;
if ( V_7 < 0 )
break;
V_2 -> V_61 . V_163 = V_206 ;
goto V_210;
} else {
V_204 = true ;
}
}
V_25 += V_144 ;
} else {
memcpy ( V_25 , V_6 -> V_151 -> V_209 + V_199 , V_144 ) ;
V_25 += V_144 ;
V_157 = F_75 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_166 -= V_144 ;
if ( V_193 ) {
V_7 = F_82 ( V_2 , 0 ) ;
if ( V_7 < 0 )
break;
V_193 = 0 ;
}
if ( ! V_166 )
break;
V_199 = 0 ;
V_198 ++ ;
V_28 = V_198 & V_6 -> V_37 ;
if ( ! V_28 ) {
V_18 ++ ;
V_6 -> V_117 ( V_2 , - 1 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
}
}
V_6 -> V_117 ( V_2 , - 1 ) ;
V_48 -> V_216 = V_48 -> V_4 - ( T_9 ) V_166 ;
if ( V_145 )
V_48 -> V_217 = V_48 -> V_51 - V_201 ;
if ( V_7 < 0 )
return V_7 ;
if ( V_204 )
return - V_127 ;
return V_157 ;
}
static int F_88 ( struct V_1 * V_2 , T_1 V_197 , T_9 V_4 ,
T_9 * V_216 , T_3 * V_25 )
{
struct V_47 V_48 ;
int V_7 ;
F_33 ( V_2 , V_218 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_4 = V_4 ;
V_48 . V_205 = V_25 ;
V_48 . V_52 = V_53 ;
V_7 = F_83 ( V_2 , V_197 , & V_48 ) ;
* V_216 = V_48 . V_216 ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_28 )
{
V_6 -> V_40 ( V_2 , V_41 , 0 , V_28 ) ;
V_6 -> V_139 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_28 )
{
int V_191 = V_2 -> V_141 ;
int V_219 = V_6 -> V_131 . V_144 + V_6 -> V_131 . V_147 + V_6 -> V_131 . V_148 ;
int V_142 = V_6 -> V_131 . V_114 ;
T_3 * V_167 = V_6 -> V_140 ;
int V_30 , V_214 , V_220 = 0 , V_221 ;
V_6 -> V_40 ( V_2 , V_84 , V_6 -> V_131 . V_114 , V_28 ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_146 ; V_30 ++ ) {
if ( V_220 ) {
V_221 = V_142 + V_30 * ( V_142 + V_219 ) ;
if ( V_2 -> V_35 > 512 )
V_6 -> V_40 ( V_2 , V_98 , V_221 , - 1 ) ;
else
V_6 -> V_40 ( V_2 , V_84 , V_221 , V_28 ) ;
} else
V_220 = 1 ;
V_214 = F_81 ( int , V_191 , V_219 ) ;
V_6 -> V_139 ( V_2 , V_167 , V_214 ) ;
V_167 += V_214 ;
V_191 -= V_214 ;
}
if ( V_191 > 0 )
V_6 -> V_139 ( V_2 , V_167 , V_191 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_28 )
{
int V_107 = 0 ;
const T_3 * V_25 = V_6 -> V_140 ;
int V_191 = V_2 -> V_141 ;
V_6 -> V_40 ( V_2 , V_82 , V_2 -> V_35 , V_28 ) ;
V_6 -> V_23 ( V_2 , V_25 , V_191 ) ;
V_6 -> V_40 ( V_2 , V_89 , - 1 , - 1 ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
return V_107 & V_112 ? - V_113 : 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_28 )
{
int V_219 = V_6 -> V_131 . V_144 + V_6 -> V_131 . V_147 + V_6 -> V_131 . V_148 ;
int V_142 = V_6 -> V_131 . V_114 , V_191 = V_2 -> V_141 ;
int V_30 , V_4 , V_221 , V_107 = 0 , V_222 = 0 , V_146 = V_6 -> V_131 . V_146 ;
const T_3 * V_167 = V_6 -> V_140 ;
if ( ! V_6 -> V_131 . V_147 && ! V_6 -> V_131 . V_148 ) {
V_221 = V_146 * ( V_142 + V_219 ) ;
V_146 = 0 ;
} else
V_221 = V_142 ;
V_6 -> V_40 ( V_2 , V_82 , V_221 , V_28 ) ;
for ( V_30 = 0 ; V_30 < V_146 ; V_30 ++ ) {
if ( V_222 ) {
if ( V_2 -> V_35 <= 512 ) {
T_8 V_223 = 0xFFFFFFFF ;
V_4 = V_142 ;
while ( V_4 > 0 ) {
int V_224 = F_81 ( int , V_4 , 4 ) ;
V_6 -> V_23 ( V_2 , ( T_3 * ) & V_223 ,
V_224 ) ;
V_4 -= V_224 ;
}
} else {
V_221 = V_142 + V_30 * ( V_142 + V_219 ) ;
V_6 -> V_40 ( V_2 , V_97 , V_221 , - 1 ) ;
}
} else
V_222 = 1 ;
V_4 = F_81 ( int , V_191 , V_219 ) ;
V_6 -> V_23 ( V_2 , V_167 , V_4 ) ;
V_167 += V_4 ;
V_191 -= V_4 ;
}
if ( V_191 > 0 )
V_6 -> V_23 ( V_2 , V_167 , V_191 ) ;
V_6 -> V_40 ( V_2 , V_89 , - 1 , - 1 ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
return V_107 & V_112 ? - V_113 : 0 ;
}
static int F_93 ( struct V_1 * V_2 , T_1 V_197 ,
struct V_47 * V_48 )
{
int V_28 , V_198 , V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_225 V_226 ;
int V_166 = V_48 -> V_51 ;
int V_4 ;
T_3 * V_25 = V_48 -> V_49 ;
int V_7 = 0 ;
F_3 ( L_9 ,
V_9 , ( unsigned long long ) V_197 , V_166 ) ;
V_226 = V_2 -> V_61 ;
V_4 = F_84 ( V_2 , V_48 ) ;
if ( F_69 ( V_48 -> V_50 >= V_4 ) ) {
F_3 ( L_10 ,
V_9 ) ;
return - V_10 ;
}
if ( F_69 ( V_197 >= V_2 -> V_114 ||
V_48 -> V_50 + V_166 > ( ( V_2 -> V_114 >> V_6 -> V_36 ) -
( V_197 >> V_6 -> V_36 ) ) * V_4 ) ) {
F_3 ( L_11 ,
V_9 ) ;
return - V_10 ;
}
V_18 = ( int ) ( V_197 >> V_6 -> V_116 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
V_198 = ( int ) ( V_197 >> V_6 -> V_36 ) ;
V_28 = V_198 & V_6 -> V_37 ;
while ( 1 ) {
if ( V_48 -> V_52 == V_185 )
V_7 = V_6 -> V_131 . V_227 ( V_2 , V_6 , V_28 ) ;
else
V_7 = V_6 -> V_131 . V_228 ( V_2 , V_6 , V_28 ) ;
if ( V_7 < 0 )
break;
V_4 = F_85 ( V_4 , V_166 ) ;
V_25 = F_80 ( V_6 , V_25 , V_48 , V_4 ) ;
if ( V_6 -> V_38 & V_215 ) {
if ( ! V_6 -> V_69 )
F_53 ( V_6 -> V_93 ) ;
else
F_43 ( V_2 ) ;
}
V_166 -= V_4 ;
if ( ! V_166 )
break;
V_198 ++ ;
V_28 = V_198 & V_6 -> V_37 ;
if ( ! V_28 ) {
V_18 ++ ;
V_6 -> V_117 ( V_2 , - 1 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
}
}
V_6 -> V_117 ( V_2 , - 1 ) ;
V_48 -> V_217 = V_48 -> V_51 - V_166 ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_61 . V_163 - V_226 . V_163 )
return - V_127 ;
return V_2 -> V_61 . V_164 - V_226 . V_164 ? - V_229 : 0 ;
}
static int F_94 ( struct V_1 * V_2 , T_1 V_197 ,
struct V_47 * V_48 )
{
int V_7 = - V_230 ;
V_48 -> V_216 = 0 ;
if ( V_48 -> V_205 && ( V_197 + V_48 -> V_4 ) > V_2 -> V_114 ) {
F_3 ( L_11 ,
V_9 ) ;
return - V_10 ;
}
F_33 ( V_2 , V_218 ) ;
switch ( V_48 -> V_52 ) {
case V_53 :
case V_186 :
case V_185 :
break;
default:
goto V_74;
}
if ( ! V_48 -> V_205 )
V_7 = F_93 ( V_2 , V_197 , V_48 ) ;
else
V_7 = F_83 ( V_2 , V_197 , V_48 ) ;
V_74:
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_25 , int V_138 , int V_28 )
{
V_6 -> V_23 ( V_2 , V_25 , V_2 -> V_35 ) ;
if ( V_138 )
V_6 -> V_23 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_25 , int V_138 ,
int V_28 )
{
int V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
T_3 * V_145 = V_6 -> V_140 ;
int V_146 , V_114 ;
for ( V_146 = V_6 -> V_131 . V_146 ; V_146 > 0 ; V_146 -- ) {
V_6 -> V_23 ( V_2 , V_25 , V_142 ) ;
V_25 += V_142 ;
if ( V_6 -> V_131 . V_147 ) {
V_6 -> V_23 ( V_2 , V_145 , V_6 -> V_131 . V_147 ) ;
V_145 += V_6 -> V_131 . V_147 ;
}
V_6 -> V_23 ( V_2 , V_145 , V_143 ) ;
V_145 += V_143 ;
if ( V_6 -> V_131 . V_148 ) {
V_6 -> V_23 ( V_2 , V_145 , V_6 -> V_131 . V_148 ) ;
V_145 += V_6 -> V_131 . V_148 ;
}
}
V_114 = V_2 -> V_141 - ( V_145 - V_6 -> V_140 ) ;
if ( V_114 )
V_6 -> V_23 ( V_2 , V_145 , V_114 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_25 , int V_138 ,
int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
T_3 * V_150 = V_6 -> V_151 -> V_152 ;
const T_3 * V_27 = V_25 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 )
V_6 -> V_131 . V_159 ( V_2 , V_27 , & V_150 [ V_30 ] ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_160 ; V_30 ++ )
V_6 -> V_140 [ V_155 [ V_30 ] ] = V_150 [ V_30 ] ;
return V_6 -> V_131 . V_231 ( V_2 , V_6 , V_25 , 1 , V_28 ) ;
}
static int F_98 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_25 , int V_138 ,
int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
T_3 * V_150 = V_6 -> V_151 -> V_152 ;
const T_3 * V_27 = V_25 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
V_6 -> V_131 . V_181 ( V_2 , V_232 ) ;
V_6 -> V_23 ( V_2 , V_27 , V_142 ) ;
V_6 -> V_131 . V_159 ( V_2 , V_27 , & V_150 [ V_30 ] ) ;
}
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_160 ; V_30 ++ )
V_6 -> V_140 [ V_155 [ V_30 ] ] = V_150 [ V_30 ] ;
V_6 -> V_23 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_8 V_192 ,
T_8 V_233 , const T_3 * V_25 ,
int V_138 , int V_28 )
{
T_3 * V_234 = V_6 -> V_140 ;
T_3 * V_150 = V_6 -> V_151 -> V_152 ;
int V_235 = V_6 -> V_131 . V_114 ;
int V_236 = V_6 -> V_131 . V_144 ;
int V_237 = V_6 -> V_131 . V_146 ;
T_8 * V_155 = V_6 -> V_131 . V_156 -> V_155 ;
T_8 V_168 = V_192 / V_235 ;
T_8 V_169 = ( V_192 + V_233 - 1 ) / V_235 ;
int V_238 = V_2 -> V_141 / V_237 ;
int V_239 , V_30 ;
for ( V_239 = 0 ; V_239 < V_237 ; V_239 ++ ) {
V_6 -> V_131 . V_181 ( V_2 , V_232 ) ;
V_6 -> V_23 ( V_2 , V_25 , V_235 ) ;
if ( ( V_239 < V_168 ) || ( V_239 > V_169 ) )
memset ( V_150 , 0xff , V_236 ) ;
else
V_6 -> V_131 . V_159 ( V_2 , V_25 , V_150 ) ;
if ( ! V_138 || ( V_239 < V_168 ) || ( V_239 > V_169 ) )
memset ( V_234 , 0xff , V_238 ) ;
V_25 += V_235 ;
V_150 += V_236 ;
V_234 += V_238 ;
}
V_150 = V_6 -> V_151 -> V_152 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_131 . V_160 ; V_30 ++ )
V_6 -> V_140 [ V_155 [ V_30 ] ] = V_150 [ V_30 ] ;
V_6 -> V_23 ( V_2 , V_6 -> V_140 , V_2 -> V_141 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_25 , int V_138 ,
int V_28 )
{
int V_30 , V_142 = V_6 -> V_131 . V_114 ;
int V_143 = V_6 -> V_131 . V_144 ;
int V_149 = V_6 -> V_131 . V_146 ;
const T_3 * V_27 = V_25 ;
T_3 * V_145 = V_6 -> V_140 ;
for ( V_30 = 0 ; V_149 ; V_149 -- , V_30 += V_143 , V_27 += V_142 ) {
V_6 -> V_131 . V_181 ( V_2 , V_232 ) ;
V_6 -> V_23 ( V_2 , V_27 , V_142 ) ;
if ( V_6 -> V_131 . V_147 ) {
V_6 -> V_23 ( V_2 , V_145 , V_6 -> V_131 . V_147 ) ;
V_145 += V_6 -> V_131 . V_147 ;
}
V_6 -> V_131 . V_159 ( V_2 , V_27 , V_145 ) ;
V_6 -> V_23 ( V_2 , V_145 , V_143 ) ;
V_145 += V_143 ;
if ( V_6 -> V_131 . V_148 ) {
V_6 -> V_23 ( V_2 , V_145 , V_6 -> V_131 . V_148 ) ;
V_145 += V_6 -> V_131 . V_148 ;
}
}
V_30 = V_2 -> V_141 - ( V_145 - V_6 -> V_140 ) ;
if ( V_30 )
V_6 -> V_23 ( V_2 , V_145 , V_30 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_192 , int V_233 , const T_3 * V_25 ,
int V_138 , int V_28 , int V_240 , int V_241 )
{
int V_107 , V_242 ;
if ( ! ( V_6 -> V_38 & V_243 ) &&
V_6 -> V_131 . V_244 )
V_242 = V_192 || ( V_233 < V_2 -> V_35 ) ;
else
V_242 = 0 ;
V_6 -> V_40 ( V_2 , V_82 , 0x00 , V_28 ) ;
if ( F_69 ( V_241 ) )
V_107 = V_6 -> V_131 . V_231 ( V_2 , V_6 , V_25 ,
V_138 , V_28 ) ;
else if ( V_242 )
V_107 = V_6 -> V_131 . V_244 ( V_2 , V_6 , V_192 , V_233 ,
V_25 , V_138 , V_28 ) ;
else
V_107 = V_6 -> V_131 . V_245 ( V_2 , V_6 , V_25 , V_138 ,
V_28 ) ;
if ( V_107 < 0 )
return V_107 ;
V_240 = 0 ;
if ( ! V_240 || ! F_102 ( V_6 ) ) {
V_6 -> V_40 ( V_2 , V_89 , - 1 , - 1 ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
if ( ( V_107 & V_112 ) && ( V_6 -> V_246 ) )
V_107 = V_6 -> V_246 ( V_2 , V_6 , V_58 , V_107 ,
V_28 ) ;
if ( V_107 & V_112 )
return - V_113 ;
} else {
V_6 -> V_40 ( V_2 , V_96 , - 1 , - 1 ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_103 ( struct V_1 * V_2 , T_3 * V_145 , T_9 V_4 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_6 -> V_140 , 0xff , V_2 -> V_141 ) ;
switch ( V_48 -> V_52 ) {
case V_53 :
case V_185 :
memcpy ( V_6 -> V_140 + V_48 -> V_50 , V_145 , V_4 ) ;
return V_145 + V_4 ;
case V_186 : {
struct V_187 * free = V_6 -> V_131 . V_156 -> V_188 ;
T_8 V_189 = 0 , V_247 = V_48 -> V_50 ;
T_9 V_144 = 0 ;
for (; free -> V_191 && V_4 ; free ++ , V_4 -= V_144 ) {
if ( F_69 ( V_247 ) ) {
if ( V_247 >= free -> V_191 ) {
V_247 -= free -> V_191 ;
continue;
}
V_189 = free -> V_192 + V_247 ;
V_144 = F_81 ( T_9 , V_4 ,
( free -> V_191 - V_247 ) ) ;
V_247 = 0 ;
} else {
V_144 = F_81 ( T_9 , V_4 , free -> V_191 ) ;
V_189 = free -> V_192 ;
}
memcpy ( V_6 -> V_140 + V_189 , V_145 , V_144 ) ;
V_145 += V_144 ;
}
return V_145 ;
}
default:
F_15 () ;
}
return NULL ;
}
static int F_104 ( struct V_1 * V_2 , T_1 V_248 ,
struct V_47 * V_48 )
{
int V_18 , V_198 , V_28 , V_249 , V_78 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_8 V_250 = V_48 -> V_4 ;
T_8 V_251 = V_48 -> V_51 ;
T_8 V_252 = F_84 ( V_2 , V_48 ) ;
T_3 * V_145 = V_48 -> V_49 ;
T_3 * V_25 = V_48 -> V_205 ;
int V_7 ;
int V_138 = V_145 ? 1 : 0 ;
V_48 -> V_216 = 0 ;
if ( ! V_250 )
return 0 ;
if ( F_105 ( V_248 ) || F_105 ( V_48 -> V_4 ) ) {
F_106 ( L_12 ,
V_9 ) ;
return - V_10 ;
}
V_78 = V_248 & ( V_2 -> V_35 - 1 ) ;
V_18 = ( int ) ( V_248 >> V_6 -> V_116 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
if ( F_35 ( V_2 ) ) {
V_7 = - V_113 ;
goto V_253;
}
V_198 = ( int ) ( V_248 >> V_6 -> V_36 ) ;
V_28 = V_198 & V_6 -> V_37 ;
V_249 = ( 1 << ( V_6 -> V_8 - V_6 -> V_36 ) ) - 1 ;
if ( V_248 <= ( ( T_1 ) V_6 -> V_208 << V_6 -> V_36 ) &&
( ( T_1 ) V_6 -> V_208 << V_6 -> V_36 ) < ( V_248 + V_48 -> V_4 ) )
V_6 -> V_208 = - 1 ;
if ( V_145 && V_48 -> V_50 && ( V_48 -> V_50 + V_48 -> V_51 > V_252 ) ) {
V_7 = - V_10 ;
goto V_253;
}
while ( 1 ) {
int V_144 = V_2 -> V_35 ;
int V_240 = V_250 > V_144 && V_28 != V_249 ;
T_3 * V_254 = V_25 ;
int V_203 ;
int V_255 = ( V_78 || V_250 < ( V_2 -> V_35 - 1 ) ) ;
if ( V_255 )
V_203 = 1 ;
else if ( V_6 -> V_38 & V_207 )
V_203 = ! F_86 ( V_25 ) ;
else
V_203 = 0 ;
if ( V_203 ) {
F_3 ( L_13 ,
V_9 , V_25 ) ;
V_240 = 0 ;
if ( V_255 )
V_144 = F_81 ( int , V_144 - V_78 , V_250 ) ;
V_6 -> V_208 = - 1 ;
memset ( V_6 -> V_151 -> V_209 , 0xff , V_2 -> V_35 ) ;
memcpy ( & V_6 -> V_151 -> V_209 [ V_78 ] , V_25 , V_144 ) ;
V_254 = V_6 -> V_151 -> V_209 ;
}
if ( F_69 ( V_145 ) ) {
T_9 V_4 = F_85 ( V_251 , V_252 ) ;
V_145 = F_103 ( V_2 , V_145 , V_4 , V_48 ) ;
V_251 -= V_4 ;
} else {
memset ( V_6 -> V_140 , 0xff , V_2 -> V_141 ) ;
}
V_7 = V_6 -> V_245 ( V_2 , V_6 , V_78 , V_144 , V_254 ,
V_138 , V_28 , V_240 ,
( V_48 -> V_52 == V_185 ) ) ;
if ( V_7 )
break;
V_250 -= V_144 ;
if ( ! V_250 )
break;
V_78 = 0 ;
V_25 += V_144 ;
V_198 ++ ;
V_28 = V_198 & V_6 -> V_37 ;
if ( ! V_28 ) {
V_18 ++ ;
V_6 -> V_117 ( V_2 , - 1 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
}
}
V_48 -> V_216 = V_48 -> V_4 - V_250 ;
if ( F_69 ( V_145 ) )
V_48 -> V_217 = V_48 -> V_51 ;
V_253:
V_6 -> V_117 ( V_2 , - 1 ) ;
return V_7 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_248 , T_9 V_4 ,
T_9 * V_216 , const T_3 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_47 V_48 ;
int V_7 ;
F_62 ( V_2 , V_6 , 400 ) ;
F_56 ( V_6 , V_2 , V_58 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_4 = V_4 ;
V_48 . V_205 = ( T_3 * ) V_25 ;
V_48 . V_52 = V_53 ;
V_7 = F_104 ( V_2 , V_248 , & V_48 ) ;
* V_216 = V_48 . V_216 ;
return V_7 ;
}
static int F_108 ( struct V_1 * V_2 , T_1 V_248 , T_9 V_4 ,
T_9 * V_216 , const T_3 * V_25 )
{
struct V_47 V_48 ;
int V_7 ;
F_33 ( V_2 , V_58 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_4 = V_4 ;
V_48 . V_205 = ( T_3 * ) V_25 ;
V_48 . V_52 = V_53 ;
V_7 = F_104 ( V_2 , V_248 , & V_48 ) ;
* V_216 = V_48 . V_216 ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_248 ,
struct V_47 * V_48 )
{
int V_18 , V_28 , V_107 , V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( L_14 ,
V_9 , ( unsigned int ) V_248 , ( int ) V_48 -> V_51 ) ;
V_4 = F_84 ( V_2 , V_48 ) ;
if ( ( V_48 -> V_50 + V_48 -> V_51 ) > V_4 ) {
F_3 ( L_15 ,
V_9 ) ;
return - V_10 ;
}
if ( F_69 ( V_48 -> V_50 >= V_4 ) ) {
F_3 ( L_16 ,
V_9 ) ;
return - V_10 ;
}
if ( F_69 ( V_248 >= V_2 -> V_114 ||
V_48 -> V_50 + V_48 -> V_51 >
( ( V_2 -> V_114 >> V_6 -> V_36 ) -
( V_248 >> V_6 -> V_36 ) ) * V_4 ) ) {
F_3 ( L_17 ,
V_9 ) ;
return - V_10 ;
}
V_18 = ( int ) ( V_248 >> V_6 -> V_116 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
V_28 = ( int ) ( V_248 >> V_6 -> V_36 ) ;
V_6 -> V_40 ( V_2 , V_92 , - 1 , - 1 ) ;
if ( F_35 ( V_2 ) ) {
V_6 -> V_117 ( V_2 , - 1 ) ;
return - V_256 ;
}
if ( V_28 == V_6 -> V_208 )
V_6 -> V_208 = - 1 ;
F_103 ( V_2 , V_48 -> V_49 , V_48 -> V_51 , V_48 ) ;
if ( V_48 -> V_52 == V_185 )
V_107 = V_6 -> V_131 . V_257 ( V_2 , V_6 , V_28 & V_6 -> V_37 ) ;
else
V_107 = V_6 -> V_131 . V_258 ( V_2 , V_6 , V_28 & V_6 -> V_37 ) ;
V_6 -> V_117 ( V_2 , - 1 ) ;
if ( V_107 )
return V_107 ;
V_48 -> V_217 = V_48 -> V_51 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , T_1 V_248 ,
struct V_47 * V_48 )
{
int V_7 = - V_230 ;
V_48 -> V_216 = 0 ;
if ( V_48 -> V_205 && ( V_248 + V_48 -> V_4 ) > V_2 -> V_114 ) {
F_3 ( L_17 ,
V_9 ) ;
return - V_10 ;
}
F_33 ( V_2 , V_58 ) ;
switch ( V_48 -> V_52 ) {
case V_53 :
case V_186 :
case V_185 :
break;
default:
goto V_74;
}
if ( ! V_48 -> V_205 )
V_7 = F_30 ( V_2 , V_248 , V_48 ) ;
else
V_7 = F_104 ( V_2 , V_248 , V_48 ) ;
V_74:
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_110 ( struct V_1 * V_2 , int V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_40 ( V_2 , V_90 , - 1 , V_28 ) ;
V_6 -> V_40 ( V_2 , V_91 , - 1 , - 1 ) ;
return V_6 -> V_111 ( V_2 , V_6 ) ;
}
static int F_111 ( struct V_1 * V_2 , struct V_55 * V_259 )
{
return F_32 ( V_2 , V_259 , 0 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_55 * V_259 ,
int V_66 )
{
int V_28 , V_107 , V_260 , V_7 , V_18 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 ;
F_3 ( L_5 ,
V_9 , ( unsigned long long ) V_259 -> V_57 ,
( unsigned long long ) V_259 -> V_4 ) ;
if ( F_1 ( V_2 , V_259 -> V_57 , V_259 -> V_4 ) )
return - V_10 ;
F_33 ( V_2 , V_261 ) ;
V_28 = ( int ) ( V_259 -> V_57 >> V_6 -> V_36 ) ;
V_18 = ( int ) ( V_259 -> V_57 >> V_6 -> V_116 ) ;
V_260 = 1 << ( V_6 -> V_8 - V_6 -> V_36 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
if ( F_35 ( V_2 ) ) {
F_3 ( L_6 ,
V_9 ) ;
V_259 -> V_14 = V_119 ;
goto V_262;
}
V_4 = V_259 -> V_4 ;
V_259 -> V_14 = V_263 ;
while ( V_4 ) {
if ( F_38 ( V_2 , ( ( T_1 ) V_28 ) <<
V_6 -> V_36 , V_66 ) ) {
F_112 ( L_18 ,
V_9 , V_28 ) ;
V_259 -> V_14 = V_119 ;
goto V_262;
}
if ( V_28 <= V_6 -> V_208 && V_6 -> V_208 <
( V_28 + V_260 ) )
V_6 -> V_208 = - 1 ;
V_107 = V_6 -> V_264 ( V_2 , V_28 & V_6 -> V_37 ) ;
if ( ( V_107 & V_112 ) && ( V_6 -> V_246 ) )
V_107 = V_6 -> V_246 ( V_2 , V_6 , V_261 ,
V_107 , V_28 ) ;
if ( V_107 & V_112 ) {
F_3 ( L_19 ,
V_9 , V_28 ) ;
V_259 -> V_14 = V_119 ;
V_259 -> V_265 =
( ( T_1 ) V_28 << V_6 -> V_36 ) ;
goto V_262;
}
V_4 -= ( 1ULL << V_6 -> V_8 ) ;
V_28 += V_260 ;
if ( V_4 && ! ( V_28 & V_6 -> V_37 ) ) {
V_18 ++ ;
V_6 -> V_117 ( V_2 , - 1 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
}
}
V_259 -> V_14 = V_266 ;
V_262:
V_7 = V_259 -> V_14 == V_266 ? 0 : - V_113 ;
V_6 -> V_117 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
if ( ! V_7 )
F_113 ( V_259 ) ;
return V_7 ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_3 ( L_20 , V_9 ) ;
F_33 ( V_2 , V_267 ) ;
F_4 ( V_2 ) ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_268 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 = ( int ) ( V_268 >> V_6 -> V_116 ) ;
int V_7 ;
F_33 ( V_2 , V_218 ) ;
V_6 -> V_117 ( V_2 , V_18 ) ;
V_7 = F_38 ( V_2 , V_268 , 0 ) ;
V_6 -> V_117 ( V_2 , - 1 ) ;
F_4 ( V_2 ) ;
return V_7 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_7 ;
V_7 = F_115 ( V_2 , V_3 ) ;
if ( V_7 ) {
if ( V_7 > 0 )
return 0 ;
return V_7 ;
}
return F_31 ( V_2 , V_3 ) ;
}
static int F_117 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_57 , T_3 * V_269 )
{
int V_107 ;
int V_30 ;
if ( ! V_6 -> V_270 ||
! ( F_118 ( V_6 -> V_271 . V_272 )
& V_273 ) )
return - V_10 ;
V_6 -> V_40 ( V_2 , V_274 , V_57 , - 1 ) ;
for ( V_30 = 0 ; V_30 < V_275 ; ++ V_30 )
V_6 -> V_276 ( V_2 , V_269 [ V_30 ] ) ;
V_107 = V_6 -> V_111 ( V_2 , V_6 ) ;
if ( V_107 & V_112 )
return - V_113 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_57 , T_3 * V_269 )
{
int V_30 ;
if ( ! V_6 -> V_270 ||
! ( F_118 ( V_6 -> V_271 . V_272 )
& V_273 ) )
return - V_10 ;
V_6 -> V_40 ( V_2 , V_277 , V_57 , - 1 ) ;
for ( V_30 = 0 ; V_30 < V_275 ; ++ V_30 )
* V_269 ++ = V_6 -> V_44 ( V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , V_105 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_14 == V_105 )
F_4 ( V_2 ) ;
else
F_122 ( L_21 ,
V_9 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_105 ) ;
}
static void F_124 ( struct V_5 * V_6 , int V_177 )
{
if ( ! V_6 -> V_93 )
V_6 -> V_93 = 20 ;
if ( V_6 -> V_40 == NULL )
V_6 -> V_40 = F_51 ;
if ( V_6 -> V_111 == NULL )
V_6 -> V_111 = F_63 ;
if ( ! V_6 -> V_117 )
V_6 -> V_117 = F_14 ;
if ( ! V_6 -> V_278 )
V_6 -> V_278 = F_117 ;
if ( ! V_6 -> V_279 )
V_6 -> V_279 = F_119 ;
if ( ! V_6 -> V_44 || V_6 -> V_44 == F_8 )
V_6 -> V_44 = V_177 ? F_10 : F_8 ;
if ( ! V_6 -> V_43 )
V_6 -> V_43 = F_13 ;
if ( ! V_6 -> V_67 )
V_6 -> V_67 = F_26 ;
if ( ! V_6 -> V_59 )
V_6 -> V_59 = F_29 ;
if ( ! V_6 -> V_23 || V_6 -> V_23 == F_18 )
V_6 -> V_23 = V_177 ? F_22 : F_18 ;
if ( ! V_6 -> V_276 || V_6 -> V_276 == F_16 )
V_6 -> V_276 = V_177 ? F_17 : F_16 ;
if ( ! V_6 -> V_139 || V_6 -> V_139 == F_20 )
V_6 -> V_139 = V_177 ? F_24 : F_20 ;
if ( ! V_6 -> V_280 )
V_6 -> V_280 = V_281 ;
if ( ! V_6 -> V_11 ) {
V_6 -> V_11 = & V_6 -> V_282 ;
F_125 ( & V_6 -> V_11 -> V_12 ) ;
F_126 ( & V_6 -> V_11 -> V_16 ) ;
}
}
static void F_127 ( T_3 * V_283 , T_9 V_4 )
{
T_10 V_30 ;
V_283 [ V_4 - 1 ] = 0 ;
for ( V_30 = 0 ; V_30 < V_4 - 1 ; V_30 ++ ) {
if ( V_283 [ V_30 ] < ' ' || V_283 [ V_30 ] > 127 )
V_283 [ V_30 ] = '?' ;
}
F_128 ( V_283 ) ;
}
static T_4 F_129 ( T_4 V_284 , T_11 const * V_27 , T_9 V_4 )
{
int V_30 ;
while ( V_4 -- ) {
V_284 ^= * V_27 ++ << 8 ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ )
V_284 = ( V_284 << 1 ) ^ ( ( V_284 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_284 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_285 * V_27 )
{
struct V_286 * V_287 ;
struct V_288 * V_283 ;
struct V_289 * V_131 ;
T_3 * V_290 ;
int V_7 = - V_10 ;
int V_4 ;
int V_30 ;
V_4 = F_118 ( V_27 -> V_291 ) * 16 ;
V_287 = F_131 ( V_4 , V_292 ) ;
if ( ! V_287 )
return - V_293 ;
V_6 -> V_40 ( V_2 , V_294 , 0 , - 1 ) ;
V_6 -> V_40 ( V_2 , V_98 ,
sizeof( * V_27 ) * V_27 -> V_295 , - 1 ) ;
V_6 -> V_139 ( V_2 , ( T_3 * ) V_287 , V_4 ) ;
if ( ( F_129 ( V_296 , ( ( T_3 * ) V_287 ) + 2 , V_4 - 2 )
!= F_118 ( V_287 -> V_284 ) ) ) {
F_3 ( L_22 ) ;
goto V_297;
}
if ( strncmp ( V_287 -> V_298 , L_23 , 4 ) ) {
F_3 ( L_24 ) ;
goto V_297;
}
V_290 = ( T_3 * ) ( V_287 + 1 ) ;
for ( V_30 = 0 ; V_30 < V_299 ; V_30 ++ ) {
V_283 = V_287 -> V_300 + V_30 ;
if ( V_283 -> type == V_301 )
break;
V_290 += V_283 -> V_191 * 16 ;
}
if ( V_30 == V_299 ) {
F_3 ( L_25 ) ;
goto V_297;
}
V_131 = (struct V_289 * ) V_290 ;
if ( ! V_131 -> V_302 ) {
F_3 ( L_26 ) ;
goto V_297;
}
V_6 -> V_303 = V_131 -> V_304 ;
V_6 -> V_305 = 1 << V_131 -> V_302 ;
V_7 = 0 ;
V_297:
F_132 ( V_287 ) ;
return V_7 ;
}
static int F_133 ( struct V_1 * V_2 , int V_193 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_306 [ V_275 ] = { V_193 } ;
return V_6 -> V_278 ( V_2 , V_6 , V_307 ,
V_306 ) ;
}
static void F_134 ( struct V_5 * V_6 ,
struct V_285 * V_27 )
{
struct V_308 * V_309 = ( void * ) V_27 -> V_310 ;
if ( F_118 ( V_27 -> V_311 ) < 1 )
return;
V_6 -> V_194 = V_309 -> V_312 ;
V_6 -> V_195 = F_133 ;
}
static int F_135 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_177 )
{
struct V_285 * V_27 = & V_6 -> V_271 ;
int V_30 , V_313 ;
int V_314 ;
V_6 -> V_40 ( V_2 , V_315 , 0x20 , - 1 ) ;
if ( V_6 -> V_44 ( V_2 ) != 'O' || V_6 -> V_44 ( V_2 ) != 'N' ||
V_6 -> V_44 ( V_2 ) != 'F' || V_6 -> V_44 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_40 ( V_2 , V_294 , 0 , - 1 ) ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
for ( V_313 = 0 ; V_313 < sizeof( * V_27 ) ; V_313 ++ )
( ( T_3 * ) V_27 ) [ V_313 ] = V_6 -> V_44 ( V_2 ) ;
if ( F_129 ( V_296 , ( T_3 * ) V_27 , 254 ) ==
F_118 ( V_27 -> V_284 ) ) {
break;
}
}
if ( V_30 == 3 ) {
F_122 ( L_27 ) ;
return 0 ;
}
V_314 = F_118 ( V_27 -> V_316 ) ;
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
F_136 ( L_28 , V_314 ) ;
return 0 ;
}
F_127 ( V_27 -> V_317 , sizeof( V_27 -> V_317 ) ) ;
F_127 ( V_27 -> V_318 , sizeof( V_27 -> V_318 ) ) ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = V_27 -> V_318 ;
V_2 -> V_35 = F_137 ( V_27 -> V_320 ) ;
V_2 -> V_34 = 1 << ( F_138 ( F_137 ( V_27 -> V_260 ) ) - 1 ) ;
V_2 -> V_34 *= V_2 -> V_35 ;
V_2 -> V_141 = F_118 ( V_27 -> V_321 ) ;
V_6 -> V_87 = 1 << ( F_138 ( F_137 ( V_27 -> V_322 ) ) - 1 ) ;
V_6 -> V_87 *= ( T_2 ) V_2 -> V_34 * V_27 -> V_323 ;
V_6 -> V_324 = V_27 -> V_324 ;
if ( F_139 ( V_6 ) & V_325 )
* V_177 = V_39 ;
else
* V_177 = 0 ;
if ( V_27 -> V_304 != 0xff ) {
V_6 -> V_303 = V_27 -> V_304 ;
V_6 -> V_305 = 512 ;
} else if ( V_6 -> V_270 >= 21 &&
( F_139 ( V_6 ) & V_326 ) ) {
if ( V_2 -> V_35 > 512 && V_6 -> V_40 == F_51 )
V_6 -> V_40 = F_55 ;
if ( F_130 ( V_2 , V_6 , V_27 ) )
F_112 ( L_29 ) ;
} else {
F_112 ( L_30 ) ;
}
if ( V_27 -> V_327 == V_328 )
F_134 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_140 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_177 )
{
struct V_329 * V_27 = & V_6 -> V_330 ;
struct V_331 * V_131 ;
int V_314 ;
int V_30 , V_313 ;
V_6 -> V_40 ( V_2 , V_315 , 0x40 , - 1 ) ;
if ( V_6 -> V_44 ( V_2 ) != 'J' || V_6 -> V_44 ( V_2 ) != 'E' ||
V_6 -> V_44 ( V_2 ) != 'D' || V_6 -> V_44 ( V_2 ) != 'E' ||
V_6 -> V_44 ( V_2 ) != 'C' )
return 0 ;
V_6 -> V_40 ( V_2 , V_294 , 0x40 , - 1 ) ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
for ( V_313 = 0 ; V_313 < sizeof( * V_27 ) ; V_313 ++ )
( ( T_3 * ) V_27 ) [ V_313 ] = V_6 -> V_44 ( V_2 ) ;
if ( F_129 ( V_296 , ( T_3 * ) V_27 , 510 ) ==
F_118 ( V_27 -> V_284 ) )
break;
}
if ( V_30 == 3 ) {
F_122 ( L_31 ) ;
return 0 ;
}
V_314 = F_118 ( V_27 -> V_316 ) ;
if ( V_314 & ( 1 << 2 ) )
V_6 -> V_332 = 10 ;
else if ( V_314 & ( 1 << 1 ) )
V_6 -> V_332 = 1 ;
if ( ! V_6 -> V_332 ) {
F_136 ( L_32 , V_314 ) ;
return 0 ;
}
F_127 ( V_27 -> V_317 , sizeof( V_27 -> V_317 ) ) ;
F_127 ( V_27 -> V_318 , sizeof( V_27 -> V_318 ) ) ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = V_27 -> V_318 ;
V_2 -> V_35 = F_137 ( V_27 -> V_320 ) ;
V_2 -> V_34 = 1 << ( F_138 ( F_137 ( V_27 -> V_260 ) ) - 1 ) ;
V_2 -> V_34 *= V_2 -> V_35 ;
V_2 -> V_141 = F_118 ( V_27 -> V_321 ) ;
V_6 -> V_87 = 1 << ( F_138 ( F_137 ( V_27 -> V_322 ) ) - 1 ) ;
V_6 -> V_87 *= ( T_2 ) V_2 -> V_34 * V_27 -> V_323 ;
V_6 -> V_324 = V_27 -> V_324 ;
if ( F_141 ( V_6 ) & V_333 )
* V_177 = V_39 ;
else
* V_177 = 0 ;
V_131 = & V_27 -> V_334 [ 0 ] ;
if ( V_131 -> V_302 >= 9 ) {
V_6 -> V_303 = V_131 -> V_304 ;
V_6 -> V_305 = 1 << V_131 -> V_302 ;
} else {
F_112 ( L_26 ) ;
}
return 1 ;
}
static int F_142 ( T_11 * V_335 , int V_336 , int V_337 )
{
int V_30 , V_313 ;
for ( V_30 = 0 ; V_30 < V_337 ; V_30 ++ )
for ( V_313 = V_30 + V_337 ; V_313 < V_336 ; V_313 += V_337 )
if ( V_335 [ V_30 ] != V_335 [ V_313 ] )
return 0 ;
return 1 ;
}
static int F_143 ( T_11 * V_335 , int V_336 )
{
int V_338 , V_337 ;
for ( V_338 = V_336 - 1 ; V_338 >= 0 ; V_338 -- )
if ( V_335 [ V_338 ] )
break;
if ( V_338 < 0 )
return 0 ;
for ( V_337 = 1 ; V_337 < V_336 ; V_337 ++ )
if ( F_142 ( V_335 , V_336 , V_337 ) )
break;
if ( V_337 < V_336 )
return V_337 ;
if ( V_338 < V_336 - 1 )
return V_338 + 1 ;
return V_336 ;
}
static int F_144 ( T_11 V_339 )
{
int V_340 ;
V_340 = V_339 & V_341 ;
V_340 >>= V_342 ;
return V_340 + 1 ;
}
static void F_145 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_11 V_335 [ 8 ] , int * V_177 )
{
int V_343 , V_344 ;
V_6 -> V_324 = F_144 ( V_335 [ 2 ] ) ;
V_343 = V_335 [ 3 ] ;
V_344 = F_143 ( V_335 , 8 ) ;
if ( V_344 == 6 && V_335 [ 0 ] == V_345 &&
! F_146 ( V_6 ) && V_335 [ 5 ] != 0x00 ) {
V_2 -> V_35 = 2048 << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
switch ( ( ( V_343 >> 2 ) & 0x04 ) | ( V_343 & 0x03 ) ) {
case 1 :
V_2 -> V_141 = 128 ;
break;
case 2 :
V_2 -> V_141 = 218 ;
break;
case 3 :
V_2 -> V_141 = 400 ;
break;
case 4 :
V_2 -> V_141 = 436 ;
break;
case 5 :
V_2 -> V_141 = 512 ;
break;
case 6 :
V_2 -> V_141 = 640 ;
break;
case 7 :
default:
V_2 -> V_141 = 1024 ;
break;
}
V_343 >>= 2 ;
V_2 -> V_34 = ( 128 * 1024 ) <<
( ( ( V_343 >> 1 ) & 0x04 ) | ( V_343 & 0x03 ) ) ;
* V_177 = 0 ;
} else if ( V_344 == 6 && V_335 [ 0 ] == V_346 &&
! F_146 ( V_6 ) ) {
unsigned int V_347 ;
V_2 -> V_35 = 2048 << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
switch ( ( ( V_343 >> 2 ) & 0x04 ) | ( V_343 & 0x03 ) ) {
case 0 :
V_2 -> V_141 = 128 ;
break;
case 1 :
V_2 -> V_141 = 224 ;
break;
case 2 :
V_2 -> V_141 = 448 ;
break;
case 3 :
V_2 -> V_141 = 64 ;
break;
case 4 :
V_2 -> V_141 = 32 ;
break;
case 5 :
V_2 -> V_141 = 16 ;
break;
default:
V_2 -> V_141 = 640 ;
break;
}
V_343 >>= 2 ;
V_347 = ( ( V_343 >> 1 ) & 0x04 ) | ( V_343 & 0x03 ) ;
if ( V_347 < 0x03 )
V_2 -> V_34 = ( 128 * 1024 ) << V_347 ;
else if ( V_347 == 0x03 )
V_2 -> V_34 = 768 * 1024 ;
else
V_2 -> V_34 = ( 64 * 1024 ) << V_347 ;
* V_177 = 0 ;
} else {
V_2 -> V_35 = 1024 << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
V_2 -> V_141 = ( 8 << ( V_343 & 0x01 ) ) *
( V_2 -> V_35 >> 9 ) ;
V_343 >>= 2 ;
V_2 -> V_34 = ( 64 * 1024 ) << ( V_343 & 0x03 ) ;
V_343 >>= 2 ;
* V_177 = ( V_343 & 0x01 ) ? V_39 : 0 ;
if ( V_344 >= 6 && V_335 [ 0 ] == V_348 &&
F_146 ( V_6 ) &&
( V_335 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_335 [ 4 ] & 0x80 ) ) {
V_2 -> V_141 = 32 * V_2 -> V_35 >> 9 ;
}
}
}
static void F_147 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_349 * type , T_11 V_335 [ 8 ] ,
int * V_177 )
{
int V_350 = V_335 [ 0 ] ;
V_2 -> V_34 = type -> V_34 ;
V_2 -> V_35 = type -> V_351 ;
V_2 -> V_141 = V_2 -> V_35 / 32 ;
* V_177 = type -> V_38 & V_39 ;
V_6 -> V_324 = 1 ;
if ( V_350 == V_352 && V_335 [ 4 ] != 0x00 && V_335 [ 5 ] == 0x00
&& V_335 [ 6 ] == 0x00 && V_335 [ 7 ] == 0x00
&& V_2 -> V_35 == 512 ) {
V_2 -> V_34 = 128 * 1024 ;
V_2 -> V_34 <<= ( ( V_335 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_148 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_11 V_335 [ 8 ] )
{
int V_350 = V_335 [ 0 ] ;
if ( V_2 -> V_35 > 512 || ( V_6 -> V_38 & V_39 ) )
V_6 -> V_42 = V_353 ;
else
V_6 -> V_42 = V_354 ;
if ( ! F_146 ( V_6 ) &&
( V_350 == V_345 ||
V_350 == V_346 ) )
V_6 -> V_32 |= V_33 ;
else if ( ( F_146 ( V_6 ) &&
( V_350 == V_345 ||
V_350 == V_346 ||
V_350 == V_348 ||
V_350 == V_352 ||
V_350 == V_355 ) ) ||
( V_2 -> V_35 == 2048 &&
V_350 == V_328 ) )
V_6 -> V_32 |= V_46 ;
}
static inline bool F_149 ( struct V_349 * type )
{
return type -> V_344 ;
}
static bool F_150 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_349 * type , T_11 * V_335 , int * V_177 )
{
if ( ! strncmp ( type -> V_356 , V_335 , type -> V_344 ) ) {
V_2 -> V_35 = type -> V_351 ;
V_2 -> V_34 = type -> V_34 ;
V_2 -> V_141 = type -> V_141 ;
V_6 -> V_324 = F_144 ( V_335 [ 2 ] ) ;
V_6 -> V_87 = ( T_2 ) type -> V_87 << 20 ;
V_6 -> V_38 |= type -> V_38 ;
V_6 -> V_303 = F_151 ( type ) ;
V_6 -> V_305 = F_152 ( type ) ;
V_6 -> V_357 =
type -> V_357 ;
* V_177 = type -> V_38 & V_39 ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = type -> V_319 ;
return true ;
}
return false ;
}
static struct V_349 * F_153 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int * V_350 , int * V_358 ,
struct V_349 * type )
{
int V_177 ;
int V_30 , V_359 ;
T_11 V_335 [ 8 ] ;
V_6 -> V_117 ( V_2 , 0 ) ;
V_6 -> V_40 ( V_2 , V_92 , - 1 , - 1 ) ;
V_6 -> V_40 ( V_2 , V_315 , 0x00 , - 1 ) ;
* V_350 = V_6 -> V_44 ( V_2 ) ;
* V_358 = V_6 -> V_44 ( V_2 ) ;
V_6 -> V_40 ( V_2 , V_315 , 0x00 , - 1 ) ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ )
V_335 [ V_30 ] = V_6 -> V_44 ( V_2 ) ;
if ( V_335 [ 0 ] != * V_350 || V_335 [ 1 ] != * V_358 ) {
F_136 ( L_33 ,
* V_350 , * V_358 , V_335 [ 0 ] , V_335 [ 1 ] ) ;
return F_154 ( - V_360 ) ;
}
if ( ! type )
type = V_361 ;
for (; type -> V_319 != NULL ; type ++ ) {
if ( F_149 ( type ) ) {
if ( F_150 ( V_2 , V_6 , type , V_335 , & V_177 ) )
goto V_362;
} else if ( * V_358 == type -> V_358 ) {
break;
}
}
V_6 -> V_270 = 0 ;
if ( ! type -> V_319 || ! type -> V_351 ) {
if ( F_135 ( V_2 , V_6 , & V_177 ) )
goto V_362;
if ( F_140 ( V_2 , V_6 , & V_177 ) )
goto V_362;
}
if ( ! type -> V_319 )
return F_154 ( - V_360 ) ;
if ( ! V_2 -> V_319 )
V_2 -> V_319 = type -> V_319 ;
V_6 -> V_87 = ( T_2 ) type -> V_87 << 20 ;
if ( ! type -> V_351 ) {
F_145 ( V_2 , V_6 , V_335 , & V_177 ) ;
} else {
F_147 ( V_2 , V_6 , type , V_335 , & V_177 ) ;
}
V_6 -> V_38 |= type -> V_38 ;
if ( * V_350 != V_345 && ! type -> V_351 )
V_6 -> V_38 &= ~ V_363 ;
V_362:
for ( V_359 = 0 ; V_364 [ V_359 ] . V_356 != 0x0 ; V_359 ++ ) {
if ( V_364 [ V_359 ] . V_356 == * V_350 )
break;
}
if ( V_6 -> V_38 & V_365 ) {
F_64 ( V_6 -> V_38 & V_39 ) ;
V_6 -> V_38 |= V_177 ;
F_124 ( V_6 , V_177 ) ;
} else if ( V_177 != ( V_6 -> V_38 & V_39 ) ) {
F_136 ( L_34 ,
* V_350 , * V_358 ) ;
F_136 ( L_35 , V_364 [ V_359 ] . V_319 , V_2 -> V_319 ) ;
F_112 ( L_36 ,
( V_6 -> V_38 & V_39 ) ? 16 : 8 ,
V_177 ? 16 : 8 ) ;
return F_154 ( - V_10 ) ;
}
F_148 ( V_2 , V_6 , V_335 ) ;
V_6 -> V_36 = F_155 ( V_2 -> V_35 ) - 1 ;
V_6 -> V_37 = ( V_6 -> V_87 >> V_6 -> V_36 ) - 1 ;
V_6 -> V_366 = V_6 -> V_8 =
F_155 ( V_2 -> V_34 ) - 1 ;
if ( V_6 -> V_87 & 0xffffffff )
V_6 -> V_116 = F_155 ( ( unsigned ) V_6 -> V_87 ) - 1 ;
else {
V_6 -> V_116 = F_155 ( ( unsigned ) ( V_6 -> V_87 >> 32 ) ) ;
V_6 -> V_116 += 32 - 1 ;
}
V_6 -> V_45 = 8 ;
V_6 -> V_264 = F_110 ;
if ( V_2 -> V_35 > 512 && V_6 -> V_40 == F_51 )
V_6 -> V_40 = F_55 ;
F_136 ( L_34 ,
* V_350 , * V_358 ) ;
if ( V_6 -> V_270 )
F_136 ( L_35 , V_364 [ V_359 ] . V_319 ,
V_6 -> V_271 . V_318 ) ;
else if ( V_6 -> V_332 )
F_136 ( L_35 , V_364 [ V_359 ] . V_319 ,
V_6 -> V_330 . V_318 ) ;
else
F_136 ( L_35 , V_364 [ V_359 ] . V_319 ,
type -> V_319 ) ;
F_136 ( L_37 ,
( int ) ( V_6 -> V_87 >> 20 ) , F_146 ( V_6 ) ? L_38 : L_39 ,
V_2 -> V_34 >> 10 , V_2 -> V_35 , V_2 -> V_141 ) ;
return type ;
}
static int F_156 ( struct V_5 * V_6 )
{
struct V_367 * V_368 = F_157 ( V_6 ) ;
int V_369 , V_370 , V_371 ;
if ( ! V_368 )
return 0 ;
if ( F_158 ( V_368 ) == 16 )
V_6 -> V_38 |= V_39 ;
if ( F_159 ( V_368 ) )
V_6 -> V_32 |= V_372 ;
V_369 = F_160 ( V_368 ) ;
V_370 = F_161 ( V_368 ) ;
V_371 = F_162 ( V_368 ) ;
if ( ( V_371 >= 0 && ! ( V_370 >= 0 ) ) ||
( ! ( V_371 >= 0 ) && V_370 >= 0 ) ) {
F_122 ( L_40 ) ;
return - V_10 ;
}
if ( V_369 >= 0 )
V_6 -> V_131 . V_52 = V_369 ;
if ( V_370 >= 0 )
V_6 -> V_131 . V_180 = V_370 ;
if ( V_371 > 0 )
V_6 -> V_131 . V_114 = V_371 ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , int V_373 ,
struct V_349 * V_374 )
{
int V_30 , V_375 , V_376 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_349 * type ;
int V_7 ;
V_7 = F_156 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_2 -> V_319 && V_2 -> V_377 . V_378 )
V_2 -> V_319 = F_164 ( V_2 -> V_377 . V_378 ) ;
F_124 ( V_6 , V_6 -> V_38 & V_39 ) ;
type = F_153 ( V_2 , V_6 , & V_375 ,
& V_376 , V_374 ) ;
if ( F_165 ( type ) ) {
if ( ! ( V_6 -> V_38 & V_379 ) )
F_112 ( L_41 ) ;
V_6 -> V_117 ( V_2 , - 1 ) ;
return F_166 ( type ) ;
}
V_6 -> V_117 ( V_2 , - 1 ) ;
for ( V_30 = 1 ; V_30 < V_373 ; V_30 ++ ) {
V_6 -> V_117 ( V_2 , V_30 ) ;
V_6 -> V_40 ( V_2 , V_92 , - 1 , - 1 ) ;
V_6 -> V_40 ( V_2 , V_315 , 0x00 , - 1 ) ;
if ( V_375 != V_6 -> V_44 ( V_2 ) ||
V_376 != V_6 -> V_44 ( V_2 ) ) {
V_6 -> V_117 ( V_2 , - 1 ) ;
break;
}
V_6 -> V_117 ( V_2 , - 1 ) ;
}
if ( V_30 > 1 )
F_136 ( L_42 , V_30 ) ;
V_6 -> V_380 = V_30 ;
V_2 -> V_114 = V_30 * V_6 -> V_87 ;
return 0 ;
}
static bool F_167 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_381 * V_131 = & V_6 -> V_131 ;
int V_382 , V_383 ;
if ( V_131 -> V_114 == 0 || V_6 -> V_305 == 0 )
return true ;
V_382 = ( V_2 -> V_35 * V_131 -> V_180 ) / V_131 -> V_114 ;
V_383 = ( V_2 -> V_35 * V_6 -> V_303 ) / V_6 -> V_305 ;
return V_382 >= V_383 && V_131 -> V_180 >= V_6 -> V_303 ;
}
int F_168 ( struct V_1 * V_2 )
{
int V_30 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_381 * V_131 = & V_6 -> V_131 ;
struct V_384 * V_385 ;
F_169 ( ( V_6 -> V_32 & V_54 ) &&
! ( V_6 -> V_32 & V_372 ) ) ;
if ( ! ( V_6 -> V_38 & V_386 ) ) {
V_385 = F_170 ( sizeof( * V_385 ) + V_2 -> V_35
+ V_2 -> V_141 * 3 , V_292 ) ;
if ( ! V_385 )
return - V_293 ;
V_385 -> V_152 = ( T_3 * ) ( V_385 + 1 ) ;
V_385 -> V_154 = V_385 -> V_152 + V_2 -> V_141 ;
V_385 -> V_209 = V_385 -> V_154 + V_2 -> V_141 ;
V_6 -> V_151 = V_385 ;
} else {
if ( ! V_6 -> V_151 )
return - V_293 ;
}
V_6 -> V_140 = V_6 -> V_151 -> V_209 + V_2 -> V_35 ;
if ( ! V_131 -> V_156 && ( V_131 -> V_52 != V_387 ) ) {
switch ( V_2 -> V_141 ) {
case 8 :
V_131 -> V_156 = & V_388 ;
break;
case 16 :
V_131 -> V_156 = & V_389 ;
break;
case 64 :
V_131 -> V_156 = & V_390 ;
break;
case 128 :
V_131 -> V_156 = & V_391 ;
break;
default:
F_112 ( L_43 ,
V_2 -> V_141 ) ;
F_15 () ;
}
}
if ( ! V_6 -> V_245 )
V_6 -> V_245 = F_101 ;
switch ( V_131 -> V_52 ) {
case V_392 :
if ( ! V_131 -> V_159 || ! V_131 -> V_162 || ! V_131 -> V_181 ) {
F_112 ( L_44 ) ;
F_15 () ;
}
if ( ! V_131 -> V_212 )
V_131 -> V_212 = F_78 ;
case V_393 :
if ( ! V_131 -> V_212 )
V_131 -> V_212 = F_77 ;
if ( ! V_131 -> V_245 )
V_131 -> V_245 = F_98 ;
if ( ! V_131 -> V_158 )
V_131 -> V_158 = F_72 ;
if ( ! V_131 -> V_231 )
V_131 -> V_231 = F_95 ;
if ( ! V_131 -> V_228 )
V_131 -> V_228 = F_89 ;
if ( ! V_131 -> V_258 )
V_131 -> V_258 = F_91 ;
if ( ! V_131 -> V_211 )
V_131 -> V_211 = F_76 ;
if ( ! V_131 -> V_244 && V_131 -> V_181 && V_131 -> V_159 )
V_131 -> V_244 = F_99 ;
case V_394 :
if ( ( ! V_131 -> V_159 || ! V_131 -> V_162 || ! V_131 -> V_181 ) &&
( ! V_131 -> V_212 ||
V_131 -> V_212 == F_77 ||
! V_131 -> V_245 ||
V_131 -> V_245 == F_98 ) ) {
F_112 ( L_44 ) ;
F_15 () ;
}
if ( ! V_131 -> V_212 )
V_131 -> V_212 = F_79 ;
if ( ! V_131 -> V_245 )
V_131 -> V_245 = F_100 ;
if ( ! V_131 -> V_158 )
V_131 -> V_158 = F_73 ;
if ( ! V_131 -> V_231 )
V_131 -> V_231 = F_96 ;
if ( ! V_131 -> V_228 )
V_131 -> V_228 = F_90 ;
if ( ! V_131 -> V_258 )
V_131 -> V_258 = F_92 ;
if ( V_2 -> V_35 >= V_131 -> V_114 ) {
if ( ! V_131 -> V_180 ) {
F_112 ( L_45 ) ;
F_15 () ;
}
break;
}
F_112 ( L_46 ,
V_131 -> V_114 , V_2 -> V_35 ) ;
V_131 -> V_52 = V_395 ;
case V_395 :
V_131 -> V_159 = V_396 ;
V_131 -> V_162 = V_397 ;
V_131 -> V_212 = F_74 ;
V_131 -> V_211 = F_76 ;
V_131 -> V_245 = F_97 ;
V_131 -> V_158 = F_72 ;
V_131 -> V_231 = F_95 ;
V_131 -> V_228 = F_89 ;
V_131 -> V_258 = F_91 ;
if ( ! V_131 -> V_114 )
V_131 -> V_114 = 256 ;
V_131 -> V_144 = 3 ;
V_131 -> V_180 = 1 ;
break;
case V_387 :
if ( ! F_171 () ) {
F_112 ( L_47 ) ;
F_15 () ;
}
V_131 -> V_159 = V_398 ;
V_131 -> V_162 = V_399 ;
V_131 -> V_212 = F_74 ;
V_131 -> V_211 = F_76 ;
V_131 -> V_245 = F_97 ;
V_131 -> V_158 = F_72 ;
V_131 -> V_231 = F_95 ;
V_131 -> V_228 = F_89 ;
V_131 -> V_258 = F_91 ;
if ( ! V_131 -> V_114 && ( V_2 -> V_141 >= 64 ) ) {
V_131 -> V_114 = 512 ;
V_131 -> V_180 = 4 ;
}
V_131 -> V_144 = 0 ;
V_131 -> V_400 = F_172 ( V_2 ) ;
if ( ! V_131 -> V_400 ) {
F_112 ( L_48 ) ;
F_15 () ;
}
break;
case V_401 :
F_112 ( L_49 ) ;
V_131 -> V_212 = F_72 ;
V_131 -> V_245 = F_95 ;
V_131 -> V_228 = F_89 ;
V_131 -> V_158 = F_72 ;
V_131 -> V_231 = F_95 ;
V_131 -> V_258 = F_91 ;
V_131 -> V_114 = V_2 -> V_35 ;
V_131 -> V_144 = 0 ;
V_131 -> V_180 = 0 ;
break;
default:
F_112 ( L_50 , V_131 -> V_52 ) ;
F_15 () ;
}
if ( ! V_131 -> V_227 )
V_131 -> V_227 = V_131 -> V_228 ;
if ( ! V_131 -> V_257 )
V_131 -> V_257 = V_131 -> V_258 ;
V_2 -> V_402 = 0 ;
if ( V_131 -> V_156 ) {
for ( V_30 = 0 ; V_131 -> V_156 -> V_188 [ V_30 ] . V_191 ; V_30 ++ )
V_2 -> V_402 += V_131 -> V_156 -> V_188 [ V_30 ] . V_191 ;
}
if ( ! F_167 ( V_2 ) )
F_112 ( L_51 ,
V_2 -> V_319 ) ;
V_131 -> V_146 = V_2 -> V_35 / V_131 -> V_114 ;
if ( V_131 -> V_146 * V_131 -> V_114 != V_2 -> V_35 ) {
F_112 ( L_52 ) ;
F_15 () ;
}
V_131 -> V_160 = V_131 -> V_146 * V_131 -> V_144 ;
if ( ! ( V_6 -> V_38 & V_243 ) && F_146 ( V_6 ) ) {
switch ( V_131 -> V_146 ) {
case 2 :
V_2 -> V_403 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_403 = 2 ;
break;
}
}
V_6 -> V_404 = V_2 -> V_35 >> V_2 -> V_403 ;
V_6 -> V_14 = V_15 ;
V_6 -> V_208 = - 1 ;
switch ( V_131 -> V_52 ) {
case V_395 :
case V_387 :
if ( V_6 -> V_36 > 9 )
V_6 -> V_38 |= V_405 ;
break;
default:
break;
}
V_2 -> type = F_146 ( V_6 ) ? V_406 : V_407 ;
V_2 -> V_408 = ( V_6 -> V_38 & V_409 ) ? V_410 :
V_411 ;
V_2 -> V_412 = F_111 ;
V_2 -> V_413 = NULL ;
V_2 -> V_414 = NULL ;
V_2 -> V_415 = F_88 ;
V_2 -> V_416 = F_108 ;
V_2 -> V_417 = F_107 ;
V_2 -> V_418 = F_94 ;
V_2 -> V_419 = F_109 ;
V_2 -> V_420 = F_114 ;
V_2 -> V_421 = NULL ;
V_2 -> V_422 = NULL ;
V_2 -> V_423 = F_120 ;
V_2 -> V_424 = F_121 ;
V_2 -> V_425 = F_123 ;
V_2 -> V_426 = F_36 ;
V_2 -> V_427 = F_115 ;
V_2 -> V_428 = F_116 ;
V_2 -> V_429 = V_2 -> V_35 ;
V_2 -> V_430 = V_131 -> V_156 ;
V_2 -> V_370 = V_131 -> V_180 ;
V_2 -> V_431 = V_131 -> V_114 ;
if ( ! V_2 -> V_432 )
V_2 -> V_432 = F_173 ( V_2 -> V_370 * 3 , 4 ) ;
if ( V_6 -> V_38 & V_433 )
return 0 ;
return V_6 -> V_280 ( V_2 ) ;
}
int F_174 ( struct V_1 * V_2 , int V_373 )
{
int V_7 ;
V_7 = F_163 ( V_2 , V_373 , NULL ) ;
if ( ! V_7 )
V_7 = F_168 ( V_2 ) ;
return V_7 ;
}
void F_175 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_131 . V_52 == V_387 )
F_176 ( (struct V_434 * ) V_6 -> V_131 . V_400 ) ;
F_177 ( V_2 ) ;
F_132 ( V_6 -> V_60 ) ;
if ( ! ( V_6 -> V_38 & V_386 ) )
F_132 ( V_6 -> V_151 ) ;
if ( V_6 -> V_435 && V_6 -> V_435 -> V_38
& V_436 )
F_132 ( V_6 -> V_435 ) ;
}
static int T_12 F_178 ( void )
{
F_179 ( L_53 , & V_71 ) ;
return 0 ;
}
static void T_13 F_180 ( void )
{
F_181 ( V_71 ) ;
}
