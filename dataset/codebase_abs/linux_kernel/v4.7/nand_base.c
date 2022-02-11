static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_3 > 1 )
return - V_10 ;
if ( ! V_3 ) {
V_5 -> V_11 = 0 ;
V_5 -> V_12 = 4 ;
} else {
V_5 -> V_11 = 6 ;
V_5 -> V_12 = V_9 -> V_13 - 4 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 > 1 )
return - V_10 ;
if ( V_2 -> V_14 == 16 ) {
if ( V_3 )
return - V_10 ;
V_5 -> V_12 = 8 ;
V_5 -> V_11 = 8 ;
} else {
V_5 -> V_12 = 2 ;
if ( ! V_3 )
V_5 -> V_11 = 3 ;
else
V_5 -> V_11 = 6 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_3 )
return - V_10 ;
V_5 -> V_12 = V_9 -> V_13 ;
V_5 -> V_11 = V_2 -> V_14 - V_5 -> V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_3 )
return - V_10 ;
V_5 -> V_12 = V_2 -> V_14 - V_9 -> V_13 - 2 ;
V_5 -> V_11 = 2 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_15 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 = 0 ;
if ( V_15 & ( ( 1ULL << V_7 -> V_18 ) - 1 ) ) {
F_7 ( L_1 , V_19 ) ;
V_17 = - V_20 ;
}
if ( V_16 & ( ( 1ULL << V_7 -> V_18 ) - 1 ) ) {
F_7 ( L_2 , V_19 ) ;
V_17 = - V_20 ;
}
return V_17 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( & V_7 -> V_21 -> V_22 ) ;
V_7 -> V_21 -> V_23 = NULL ;
V_7 -> V_24 = V_25 ;
F_10 ( & V_7 -> V_21 -> V_26 ) ;
F_11 ( & V_7 -> V_21 -> V_22 ) ;
}
static T_3 F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_13 ( V_7 -> V_27 ) ;
}
static T_3 F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return ( T_3 ) F_15 ( F_16 ( V_7 -> V_27 ) ) ;
}
static T_4 F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_16 ( V_7 -> V_27 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_28 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_28 ) {
case - 1 :
V_7 -> V_29 ( V_2 , V_30 , 0 | V_31 ) ;
break;
case 0 :
break;
default:
F_19 () ;
}
}
static void F_20 ( struct V_1 * V_2 , T_3 V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_33 ( V_2 , & V_32 , 1 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_3 V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_5 V_34 = V_32 ;
V_7 -> V_33 ( V_2 , ( T_3 * ) & V_34 , 2 ) ;
}
static void F_22 ( struct V_1 * V_2 , const T_3 * V_35 , int V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_23 ( V_7 -> V_36 , V_35 , V_16 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 * V_35 , int V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_25 ( V_7 -> V_27 , V_35 , V_16 ) ;
}
static void F_26 ( struct V_1 * V_2 , const T_3 * V_35 , int V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 * V_37 = ( T_4 * ) V_35 ;
F_27 ( V_7 -> V_36 , V_37 , V_16 >> 1 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_3 * V_35 , int V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 * V_37 = ( T_4 * ) V_35 ;
F_29 ( V_7 -> V_27 , V_37 , V_16 >> 1 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_38 , V_39 = 0 , V_40 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_41 ;
if ( V_7 -> V_42 & V_43 )
V_15 += V_2 -> V_44 - V_2 -> V_45 ;
V_38 = ( int ) ( V_15 >> V_7 -> V_46 ) & V_7 -> V_47 ;
do {
if ( V_7 -> V_48 & V_49 ) {
V_7 -> V_50 ( V_2 , V_51 ,
V_7 -> V_52 & 0xFE , V_38 ) ;
V_41 = F_15 ( V_7 -> V_53 ( V_2 ) ) ;
if ( V_7 -> V_52 & 0x1 )
V_41 >>= 8 ;
else
V_41 &= 0xFF ;
} else {
V_7 -> V_50 ( V_2 , V_51 , V_7 -> V_52 ,
V_38 ) ;
V_41 = V_7 -> V_54 ( V_2 ) ;
}
if ( F_31 ( V_7 -> V_55 == 8 ) )
V_39 = V_41 != 0xFF ;
else
V_39 = F_32 ( V_41 ) < V_7 -> V_55 ;
V_15 += V_2 -> V_45 ;
V_38 = ( int ) ( V_15 >> V_7 -> V_46 ) & V_7 -> V_47 ;
V_40 ++ ;
} while ( ! V_39 && V_40 < 2 && ( V_7 -> V_42 & V_56 ) );
return V_39 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_57 V_58 ;
T_3 V_35 [ 2 ] = { 0 , 0 } ;
int V_17 = 0 , V_39 , V_40 = 0 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_59 = V_35 ;
V_58 . V_60 = V_7 -> V_52 ;
if ( V_7 -> V_48 & V_49 ) {
V_58 . V_60 &= ~ 0x01 ;
V_58 . V_16 = V_58 . V_61 = 2 ;
} else {
V_58 . V_16 = V_58 . V_61 = 1 ;
}
V_58 . V_62 = V_63 ;
if ( V_7 -> V_42 & V_43 )
V_15 += V_2 -> V_44 - V_2 -> V_45 ;
do {
V_39 = F_34 ( V_2 , V_15 , & V_58 ) ;
if ( ! V_17 )
V_17 = V_39 ;
V_40 ++ ;
V_15 += V_2 -> V_45 ;
} while ( ( V_7 -> V_42 & V_56 ) && V_40 < 2 );
return V_17 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_39 , V_17 = 0 ;
if ( ! ( V_7 -> V_42 & V_64 ) ) {
struct V_65 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_2 = V_2 ;
V_66 . V_67 = V_15 ;
V_66 . V_16 = 1ULL << V_7 -> V_18 ;
F_36 ( V_2 , & V_66 , 0 ) ;
F_37 ( V_2 , V_68 ) ;
V_17 = V_7 -> V_69 ( V_2 , V_15 ) ;
F_8 ( V_2 ) ;
}
if ( V_7 -> V_70 ) {
V_39 = F_38 ( V_2 , V_15 ) ;
if ( ! V_17 )
V_17 = V_39 ;
}
if ( ! V_17 )
V_2 -> V_71 . V_72 ++ ;
return V_17 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_48 & V_73 )
return 0 ;
V_7 -> V_50 ( V_2 , V_74 , - 1 , - 1 ) ;
return ( V_7 -> V_54 ( V_2 ) & V_75 ) ? 0 : 1 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_70 )
return 0 ;
return F_41 ( V_2 , V_15 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_15 , int V_76 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_70 )
return V_7 -> V_77 ( V_2 , V_15 ) ;
return F_43 ( V_2 , V_15 , V_76 ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned long V_78 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_78 ; V_40 ++ ) {
if ( V_7 -> V_79 ( V_2 ) )
break;
F_45 () ;
F_46 ( 1 ) ;
}
}
void F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_78 = 400 ;
if ( F_48 () || V_80 )
return F_44 ( V_2 , V_78 ) ;
V_78 = V_81 + F_49 ( V_78 ) ;
do {
if ( V_7 -> V_79 ( V_2 ) )
return;
F_50 () ;
} while ( F_51 ( V_81 , V_78 ) );
if ( ! V_7 -> V_79 ( V_2 ) )
F_52 ( L_3 ) ;
}
static void F_53 ( struct V_1 * V_2 , unsigned long V_78 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
V_78 = V_81 + F_49 ( V_78 ) ;
do {
if ( ( V_7 -> V_54 ( V_2 ) & V_82 ) )
break;
F_45 () ;
} while ( F_51 ( V_81 , V_78 ) );
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_83 ,
int V_84 , int V_85 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_86 = V_87 | V_31 ;
if ( V_83 == V_88 ) {
int V_89 ;
if ( V_84 >= V_2 -> V_45 ) {
V_84 -= V_2 -> V_45 ;
V_89 = V_51 ;
} else if ( V_84 < 256 ) {
V_89 = V_90 ;
} else {
V_84 -= 256 ;
V_89 = V_91 ;
}
V_7 -> V_29 ( V_2 , V_89 , V_86 ) ;
V_86 &= ~ V_31 ;
}
V_7 -> V_29 ( V_2 , V_83 , V_86 ) ;
V_86 = V_92 | V_31 ;
if ( V_84 != - 1 ) {
if ( V_7 -> V_48 & V_49 &&
! F_55 ( V_83 ) )
V_84 >>= 1 ;
V_7 -> V_29 ( V_2 , V_84 , V_86 ) ;
V_86 &= ~ V_31 ;
}
if ( V_85 != - 1 ) {
V_7 -> V_29 ( V_2 , V_85 , V_86 ) ;
V_86 &= ~ V_31 ;
V_7 -> V_29 ( V_2 , V_85 >> 8 , V_86 ) ;
if ( V_7 -> V_93 > ( 32 << 20 ) )
V_7 -> V_29 ( V_2 , V_85 >> 16 , V_86 ) ;
}
V_7 -> V_29 ( V_2 , V_30 , V_94 | V_31 ) ;
switch ( V_83 ) {
case V_95 :
case V_96 :
case V_97 :
case V_88 :
case V_74 :
return;
case V_98 :
if ( V_7 -> V_79 )
break;
F_56 ( V_7 -> V_99 ) ;
V_7 -> V_29 ( V_2 , V_74 ,
V_87 | V_31 ) ;
V_7 -> V_29 ( V_2 ,
V_30 , V_94 | V_31 ) ;
F_53 ( V_2 , 250 ) ;
return;
default:
if ( ! V_7 -> V_79 ) {
F_56 ( V_7 -> V_99 ) ;
return;
}
}
F_57 ( 100 ) ;
F_47 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_83 ,
int V_84 , int V_85 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_83 == V_51 ) {
V_84 += V_2 -> V_45 ;
V_83 = V_90 ;
}
V_7 -> V_29 ( V_2 , V_83 , V_94 | V_100 | V_31 ) ;
if ( V_84 != - 1 || V_85 != - 1 ) {
int V_86 = V_31 | V_94 | V_101 ;
if ( V_84 != - 1 ) {
if ( V_7 -> V_48 & V_49 &&
! F_55 ( V_83 ) )
V_84 >>= 1 ;
V_7 -> V_29 ( V_2 , V_84 , V_86 ) ;
V_86 &= ~ V_31 ;
V_7 -> V_29 ( V_2 , V_84 >> 8 , V_86 ) ;
}
if ( V_85 != - 1 ) {
V_7 -> V_29 ( V_2 , V_85 , V_86 ) ;
V_7 -> V_29 ( V_2 , V_85 >> 8 ,
V_94 | V_101 ) ;
if ( V_7 -> V_93 > ( 128 << 20 ) )
V_7 -> V_29 ( V_2 , V_85 >> 16 ,
V_94 | V_101 ) ;
}
}
V_7 -> V_29 ( V_2 , V_30 , V_94 | V_31 ) ;
switch ( V_83 ) {
case V_102 :
case V_95 :
case V_96 :
case V_97 :
case V_88 :
case V_103 :
case V_74 :
return;
case V_98 :
if ( V_7 -> V_79 )
break;
F_56 ( V_7 -> V_99 ) ;
V_7 -> V_29 ( V_2 , V_74 ,
V_94 | V_100 | V_31 ) ;
V_7 -> V_29 ( V_2 , V_30 ,
V_94 | V_31 ) ;
F_53 ( V_2 , 250 ) ;
return;
case V_104 :
V_7 -> V_29 ( V_2 , V_105 ,
V_94 | V_100 | V_31 ) ;
V_7 -> V_29 ( V_2 , V_30 ,
V_94 | V_31 ) ;
return;
case V_90 :
V_7 -> V_29 ( V_2 , V_106 ,
V_94 | V_100 | V_31 ) ;
V_7 -> V_29 ( V_2 , V_30 ,
V_94 | V_31 ) ;
default:
if ( ! V_7 -> V_79 ) {
F_56 ( V_7 -> V_99 ) ;
return;
}
}
F_57 ( 100 ) ;
F_47 ( V_2 ) ;
}
static void F_59 ( struct V_6 * V_7 ,
struct V_1 * V_2 , int V_107 )
{
V_7 -> V_21 -> V_23 = V_7 ;
V_7 -> V_24 = V_107 ;
}
static int
F_37 ( struct V_1 * V_2 , int V_107 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_6 * V_22 = & V_7 -> V_21 -> V_22 ;
T_7 * V_26 = & V_7 -> V_21 -> V_26 ;
F_60 ( V_108 , V_109 ) ;
V_110:
F_9 ( V_22 ) ;
if ( ! V_7 -> V_21 -> V_23 )
V_7 -> V_21 -> V_23 = V_7 ;
if ( V_7 -> V_21 -> V_23 == V_7 && V_7 -> V_24 == V_25 ) {
V_7 -> V_24 = V_107 ;
F_11 ( V_22 ) ;
return 0 ;
}
if ( V_107 == V_111 ) {
if ( V_7 -> V_21 -> V_23 -> V_24 == V_111 ) {
V_7 -> V_24 = V_111 ;
F_11 ( V_22 ) ;
return 0 ;
}
}
F_61 ( V_112 ) ;
F_62 ( V_26 , & V_108 ) ;
F_11 ( V_22 ) ;
F_63 () ;
F_64 ( V_26 , & V_108 ) ;
goto V_110;
}
static void F_65 ( struct V_1 * V_2 , struct V_6 * V_7 ,
unsigned long V_78 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_78 ; V_40 ++ ) {
if ( V_7 -> V_79 ) {
if ( V_7 -> V_79 ( V_2 ) )
break;
} else {
if ( V_7 -> V_54 ( V_2 ) & V_82 )
break;
}
F_46 ( 1 ) ;
}
}
static int F_66 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_113 ;
unsigned long V_78 = 400 ;
F_57 ( 100 ) ;
V_7 -> V_50 ( V_2 , V_74 , - 1 , - 1 ) ;
if ( F_48 () || V_80 )
F_65 ( V_2 , V_7 , V_78 ) ;
else {
V_78 = V_81 + F_49 ( V_78 ) ;
do {
if ( V_7 -> V_79 ) {
if ( V_7 -> V_79 ( V_2 ) )
break;
} else {
if ( V_7 -> V_54 ( V_2 ) & V_82 )
break;
}
F_50 () ;
} while ( F_51 ( V_81 , V_78 ) );
}
V_113 = ( int ) V_7 -> V_54 ( V_2 ) ;
F_67 ( ! ( V_113 & V_82 ) ) ;
return V_113 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_15 ,
T_2 V_16 , int V_114 )
{
int V_17 = 0 ;
int V_113 , V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_38 = V_15 >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_115 , - 1 , V_38 & V_7 -> V_47 ) ;
V_38 = ( V_15 + V_16 ) >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_116 , - 1 ,
( V_38 | V_114 ) & V_7 -> V_47 ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
if ( V_113 & V_118 ) {
F_7 ( L_4 ,
V_19 , V_113 ) ;
V_17 = - V_119 ;
}
return V_17 ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 )
{
int V_17 = 0 ;
int V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_5 ,
V_19 , ( unsigned long long ) V_15 , V_16 ) ;
if ( F_6 ( V_2 , V_15 , V_16 ) )
return - V_20 ;
if ( V_15 + V_16 == V_2 -> V_120 )
V_16 -= V_2 -> V_44 ;
F_37 ( V_2 , V_121 ) ;
V_28 = V_15 >> V_7 -> V_122 ;
V_7 -> V_123 ( V_2 , V_28 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_6 ,
V_19 ) ;
V_17 = - V_119 ;
goto V_124;
}
V_17 = F_68 ( V_2 , V_15 , V_16 , 0 ) ;
V_124:
V_7 -> V_123 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
int F_70 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 )
{
int V_17 = 0 ;
int V_28 , V_113 , V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_5 ,
V_19 , ( unsigned long long ) V_15 , V_16 ) ;
if ( F_6 ( V_2 , V_15 , V_16 ) )
return - V_20 ;
F_37 ( V_2 , V_125 ) ;
V_28 = V_15 >> V_7 -> V_122 ;
V_7 -> V_123 ( V_2 , V_28 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_6 ,
V_19 ) ;
V_113 = V_126 ;
V_17 = - V_119 ;
goto V_124;
}
V_38 = V_15 >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_127 , - 1 , V_38 & V_7 -> V_47 ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
if ( V_113 & V_118 ) {
F_7 ( L_4 ,
V_19 , V_113 ) ;
V_17 = - V_119 ;
goto V_124;
}
V_17 = F_68 ( V_2 , V_15 , V_16 , 0x1 ) ;
V_124:
V_7 -> V_123 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_71 ( void * V_35 , int V_16 , int V_128 )
{
const unsigned char * V_129 = V_35 ;
int V_130 = 0 ;
int V_131 ;
for (; V_16 && ( ( V_132 ) V_129 ) % sizeof( long ) ;
V_16 -- , V_129 ++ ) {
V_131 = F_32 ( * V_129 ) ;
V_130 += V_133 - V_131 ;
if ( F_72 ( V_130 > V_128 ) )
return - V_134 ;
}
for (; V_16 >= sizeof( long ) ;
V_16 -= sizeof( long ) , V_129 += sizeof( long ) ) {
V_131 = F_73 ( * ( ( unsigned long * ) V_129 ) ) ;
V_130 += V_135 - V_131 ;
if ( F_72 ( V_130 > V_128 ) )
return - V_134 ;
}
for (; V_16 > 0 ; V_16 -- , V_129 ++ ) {
V_131 = F_32 ( * V_129 ) ;
V_130 += V_133 - V_131 ;
if ( F_72 ( V_130 > V_128 ) )
return - V_134 ;
}
return V_130 ;
}
int F_74 ( void * V_136 , int V_137 ,
void * V_9 , int V_138 ,
void * V_139 , int V_140 ,
int V_128 )
{
int V_141 = 0 , V_142 = 0 , V_143 = 0 ;
V_141 = F_71 ( V_136 , V_137 ,
V_128 ) ;
if ( V_141 < 0 )
return V_141 ;
V_128 -= V_141 ;
V_142 = F_71 ( V_9 , V_138 , V_128 ) ;
if ( V_142 < 0 )
return V_142 ;
V_128 -= V_142 ;
V_143 = F_71 ( V_139 , V_140 ,
V_128 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_141 )
memset ( V_136 , 0xff , V_137 ) ;
if ( V_142 )
memset ( V_9 , 0xff , V_138 ) ;
if ( V_143 )
memset ( V_139 , 0xff , V_140 ) ;
return V_141 + V_142 + V_143 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_144 , int V_38 )
{
V_7 -> V_145 ( V_2 , V_35 , V_2 -> V_45 ) ;
if ( V_144 )
V_7 -> V_145 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_35 ,
int V_144 , int V_38 )
{
int V_147 = V_7 -> V_9 . V_120 ;
int V_148 = V_7 -> V_9 . V_149 ;
T_3 * V_150 = V_7 -> V_146 ;
int V_151 , V_120 ;
for ( V_151 = V_7 -> V_9 . V_151 ; V_151 > 0 ; V_151 -- ) {
V_7 -> V_145 ( V_2 , V_35 , V_147 ) ;
V_35 += V_147 ;
if ( V_7 -> V_9 . V_152 ) {
V_7 -> V_145 ( V_2 , V_150 , V_7 -> V_9 . V_152 ) ;
V_150 += V_7 -> V_9 . V_152 ;
}
V_7 -> V_145 ( V_2 , V_150 , V_148 ) ;
V_150 += V_148 ;
if ( V_7 -> V_9 . V_153 ) {
V_7 -> V_145 ( V_2 , V_150 , V_7 -> V_9 . V_153 ) ;
V_150 += V_7 -> V_9 . V_153 ;
}
}
V_120 = V_2 -> V_14 - ( V_150 - V_7 -> V_146 ) ;
if ( V_120 )
V_7 -> V_145 ( V_2 , V_150 , V_120 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_144 , int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 , V_17 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
T_3 * V_37 = V_35 ;
T_3 * V_155 = V_7 -> V_156 -> V_157 ;
T_3 * V_158 = V_7 -> V_156 -> V_159 ;
unsigned int V_160 = 0 ;
V_7 -> V_9 . V_161 ( V_2 , V_7 , V_35 , 1 , V_38 ) ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 )
V_7 -> V_9 . V_162 ( V_2 , V_37 , & V_155 [ V_40 ] ) ;
V_17 = F_78 ( V_2 , V_158 , V_7 -> V_146 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_154 = V_7 -> V_9 . V_151 ;
V_37 = V_35 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
int V_163 ;
V_163 = V_7 -> V_9 . V_164 ( V_2 , V_37 , & V_158 [ V_40 ] , & V_155 [ V_40 ] ) ;
if ( V_163 < 0 ) {
V_2 -> V_71 . V_165 ++ ;
} else {
V_2 -> V_71 . V_166 += V_163 ;
V_160 = F_79 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_8 V_167 , T_8 V_168 , T_3 * V_169 ,
int V_38 )
{
int V_170 , V_171 , V_172 , V_17 ;
T_3 * V_37 ;
int V_173 , V_40 , V_174 = 0 ;
int V_175 , V_176 , V_177 , V_178 ;
int V_179 = ( V_7 -> V_48 & V_49 ) ? 2 : 1 ;
int V_180 , V_3 = 0 ;
unsigned int V_160 = 0 ;
struct V_4 V_5 = { } ;
V_170 = V_167 / V_7 -> V_9 . V_120 ;
V_171 = ( V_167 + V_168 - 1 ) / V_7 -> V_9 . V_120 ;
V_172 = V_171 - V_170 + 1 ;
V_180 = V_170 * V_7 -> V_9 . V_149 ;
V_175 = V_172 * V_7 -> V_9 . V_120 ;
V_176 = V_172 * V_7 -> V_9 . V_149 ;
V_173 = V_170 * V_7 -> V_9 . V_120 ;
if ( V_173 != 0 )
V_7 -> V_50 ( V_2 , V_104 , V_173 , - 1 ) ;
V_37 = V_169 + V_173 ;
V_7 -> V_145 ( V_2 , V_37 , V_175 ) ;
for ( V_40 = 0 ; V_40 < V_176 ; V_40 += V_7 -> V_9 . V_149 , V_37 += V_7 -> V_9 . V_120 )
V_7 -> V_9 . V_162 ( V_2 , V_37 , & V_7 -> V_156 -> V_157 [ V_40 ] ) ;
V_17 = F_81 ( V_2 , V_180 , & V_3 , & V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_5 . V_12 < V_176 )
V_174 = 1 ;
if ( V_174 ) {
V_7 -> V_50 ( V_2 , V_104 , V_2 -> V_45 , - 1 ) ;
V_7 -> V_145 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
} else {
V_178 = V_5 . V_11 & ~ ( V_179 - 1 ) ;
V_177 = V_176 ;
if ( V_5 . V_11 & ( V_179 - 1 ) )
V_177 ++ ;
if ( ( V_5 . V_11 + ( V_172 * V_7 -> V_9 . V_149 ) ) &
( V_179 - 1 ) )
V_177 ++ ;
V_7 -> V_50 ( V_2 , V_104 ,
V_2 -> V_45 + V_178 , - 1 ) ;
V_7 -> V_145 ( V_2 , & V_7 -> V_146 [ V_178 ] , V_177 ) ;
}
V_17 = F_78 ( V_2 , V_7 -> V_156 -> V_159 ,
V_7 -> V_146 , V_180 , V_176 ) ;
if ( V_17 )
return V_17 ;
V_37 = V_169 + V_173 ;
for ( V_40 = 0 ; V_40 < V_176 ; V_40 += V_7 -> V_9 . V_149 , V_37 += V_7 -> V_9 . V_120 ) {
int V_163 ;
V_163 = V_7 -> V_9 . V_164 ( V_2 , V_37 ,
& V_7 -> V_156 -> V_159 [ V_40 ] , & V_7 -> V_156 -> V_157 [ V_40 ] ) ;
if ( V_163 == - V_134 &&
( V_7 -> V_9 . V_48 & V_181 ) ) {
V_163 = F_74 ( V_37 , V_7 -> V_9 . V_120 ,
& V_7 -> V_156 -> V_159 [ V_40 ] ,
V_7 -> V_9 . V_149 ,
NULL , 0 ,
V_7 -> V_9 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_71 . V_165 ++ ;
} else {
V_2 -> V_71 . V_166 += V_163 ;
V_160 = F_79 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_144 , int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 , V_17 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
T_3 * V_37 = V_35 ;
T_3 * V_155 = V_7 -> V_156 -> V_157 ;
T_3 * V_158 = V_7 -> V_156 -> V_159 ;
unsigned int V_160 = 0 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
V_7 -> V_9 . V_183 ( V_2 , V_184 ) ;
V_7 -> V_145 ( V_2 , V_37 , V_147 ) ;
V_7 -> V_9 . V_162 ( V_2 , V_37 , & V_155 [ V_40 ] ) ;
}
V_7 -> V_145 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
V_17 = F_78 ( V_2 , V_158 , V_7 -> V_146 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_154 = V_7 -> V_9 . V_151 ;
V_37 = V_35 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
int V_163 ;
V_163 = V_7 -> V_9 . V_164 ( V_2 , V_37 , & V_158 [ V_40 ] , & V_155 [ V_40 ] ) ;
if ( V_163 == - V_134 &&
( V_7 -> V_9 . V_48 & V_181 ) ) {
V_163 = F_74 ( V_37 , V_147 ,
& V_158 [ V_40 ] , V_148 ,
NULL , 0 ,
V_7 -> V_9 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_71 . V_165 ++ ;
} else {
V_2 -> V_71 . V_166 += V_163 ;
V_160 = F_79 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_35 , int V_144 , int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 , V_17 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
T_3 * V_37 = V_35 ;
T_3 * V_158 = V_7 -> V_156 -> V_159 ;
T_3 * V_155 = V_7 -> V_156 -> V_157 ;
unsigned int V_160 = 0 ;
V_7 -> V_50 ( V_2 , V_51 , 0 , V_38 ) ;
V_7 -> V_145 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
V_7 -> V_50 ( V_2 , V_90 , 0 , V_38 ) ;
V_17 = F_78 ( V_2 , V_158 , V_7 -> V_146 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
int V_163 ;
V_7 -> V_9 . V_183 ( V_2 , V_184 ) ;
V_7 -> V_145 ( V_2 , V_37 , V_147 ) ;
V_7 -> V_9 . V_162 ( V_2 , V_37 , & V_155 [ V_40 ] ) ;
V_163 = V_7 -> V_9 . V_164 ( V_2 , V_37 , & V_158 [ V_40 ] , NULL ) ;
if ( V_163 == - V_134 &&
( V_7 -> V_9 . V_48 & V_181 ) ) {
V_163 = F_74 ( V_37 , V_147 ,
& V_158 [ V_40 ] , V_148 ,
NULL , 0 ,
V_7 -> V_9 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_71 . V_165 ++ ;
} else {
V_2 -> V_71 . V_166 += V_163 ;
V_160 = F_79 (unsigned int, max_bitflips, stat) ;
}
}
return V_160 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_144 , int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
int V_185 = V_148 + V_7 -> V_9 . V_152 + V_7 -> V_9 . V_153 ;
T_3 * V_37 = V_35 ;
T_3 * V_150 = V_7 -> V_146 ;
unsigned int V_160 = 0 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
int V_163 ;
V_7 -> V_9 . V_183 ( V_2 , V_184 ) ;
V_7 -> V_145 ( V_2 , V_37 , V_147 ) ;
if ( V_7 -> V_9 . V_152 ) {
V_7 -> V_145 ( V_2 , V_150 , V_7 -> V_9 . V_152 ) ;
V_150 += V_7 -> V_9 . V_152 ;
}
V_7 -> V_9 . V_183 ( V_2 , V_186 ) ;
V_7 -> V_145 ( V_2 , V_150 , V_148 ) ;
V_163 = V_7 -> V_9 . V_164 ( V_2 , V_37 , V_150 , NULL ) ;
V_150 += V_148 ;
if ( V_7 -> V_9 . V_153 ) {
V_7 -> V_145 ( V_2 , V_150 , V_7 -> V_9 . V_153 ) ;
V_150 += V_7 -> V_9 . V_153 ;
}
if ( V_163 == - V_134 &&
( V_7 -> V_9 . V_48 & V_181 ) ) {
V_163 = F_74 ( V_37 , V_7 -> V_9 . V_120 ,
V_150 - V_185 ,
V_185 ,
NULL , 0 ,
V_7 -> V_9 . V_182 ) ;
}
if ( V_163 < 0 ) {
V_2 -> V_71 . V_165 ++ ;
} else {
V_2 -> V_71 . V_166 += V_163 ;
V_160 = F_79 (unsigned int, max_bitflips, stat) ;
}
}
V_40 = V_2 -> V_14 - ( V_150 - V_7 -> V_146 ) ;
if ( V_40 )
V_7 -> V_145 ( V_2 , V_150 , V_40 ) ;
return V_160 ;
}
static T_3 * F_85 ( struct V_1 * V_2 , T_3 * V_150 ,
struct V_57 * V_58 , T_9 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_187 :
memcpy ( V_150 , V_7 -> V_146 + V_58 -> V_60 , V_16 ) ;
return V_150 + V_16 ;
case V_188 :
V_17 = F_86 ( V_2 , V_150 , V_7 -> V_146 ,
V_58 -> V_60 , V_16 ) ;
F_87 ( V_17 ) ;
return V_150 + V_16 ;
default:
F_19 () ;
}
return NULL ;
}
static int F_88 ( struct V_1 * V_2 , int V_189 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_7 , V_189 ) ;
if ( V_189 >= V_7 -> V_190 )
return - V_20 ;
if ( ! V_7 -> V_191 )
return - V_192 ;
return V_7 -> V_191 ( V_2 , V_189 ) ;
}
static int F_89 ( struct V_1 * V_2 , T_1 V_193 ,
struct V_57 * V_58 )
{
int V_28 , V_38 , V_194 , V_195 , V_149 , V_196 , V_144 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 = 0 ;
T_8 V_168 = V_58 -> V_16 ;
T_8 V_197 = V_58 -> V_61 ;
T_8 V_198 = F_90 ( V_2 , V_58 ) ;
T_3 * V_169 , * V_150 , * V_35 ;
int V_199 ;
unsigned int V_160 = 0 ;
int V_189 = 0 ;
bool V_200 = false ;
V_28 = ( int ) ( V_193 >> V_7 -> V_122 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
V_194 = ( int ) ( V_193 >> V_7 -> V_46 ) ;
V_38 = V_194 & V_7 -> V_47 ;
V_195 = ( int ) ( V_193 & ( V_2 -> V_45 - 1 ) ) ;
V_35 = V_58 -> V_201 ;
V_150 = V_58 -> V_59 ;
V_144 = V_150 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_202 = V_2 -> V_71 . V_165 ;
V_149 = F_91 ( V_2 -> V_45 - V_195 , V_168 ) ;
V_196 = ( V_149 == V_2 -> V_45 ) ;
if ( ! V_196 )
V_199 = 1 ;
else if ( V_7 -> V_48 & V_203 )
V_199 = ! F_92 ( V_35 ) ;
else
V_199 = 0 ;
if ( V_194 != V_7 -> V_204 || V_150 ) {
V_169 = V_199 ? V_7 -> V_156 -> V_205 : V_35 ;
if ( V_199 && V_196 )
F_7 ( L_8 ,
V_19 , V_35 ) ;
V_206:
V_7 -> V_50 ( V_2 , V_90 , 0x00 , V_38 ) ;
if ( F_72 ( V_58 -> V_62 == V_187 ) )
V_17 = V_7 -> V_9 . V_161 ( V_2 , V_7 , V_169 ,
V_144 ,
V_38 ) ;
else if ( ! V_196 && F_93 ( V_7 ) &&
! V_150 )
V_17 = V_7 -> V_9 . V_207 ( V_2 , V_7 ,
V_195 , V_149 , V_169 ,
V_38 ) ;
else
V_17 = V_7 -> V_9 . V_208 ( V_2 , V_7 , V_169 ,
V_144 , V_38 ) ;
if ( V_17 < 0 ) {
if ( V_199 )
V_7 -> V_204 = - 1 ;
break;
}
V_160 = F_79 (unsigned int, max_bitflips, ret) ;
if ( V_199 ) {
if ( ! F_93 ( V_7 ) && ! V_150 &&
! ( V_2 -> V_71 . V_165 - V_202 ) &&
( V_58 -> V_62 != V_187 ) ) {
V_7 -> V_204 = V_194 ;
V_7 -> V_209 = V_17 ;
} else {
V_7 -> V_204 = - 1 ;
}
memcpy ( V_35 , V_7 -> V_156 -> V_205 + V_195 , V_149 ) ;
}
if ( F_72 ( V_150 ) ) {
int V_210 = F_91 ( V_197 , V_198 ) ;
if ( V_210 ) {
V_150 = F_85 ( V_2 ,
V_150 , V_58 , V_210 ) ;
V_197 -= V_210 ;
}
}
if ( V_7 -> V_48 & V_211 ) {
if ( ! V_7 -> V_79 )
F_56 ( V_7 -> V_99 ) ;
else
F_47 ( V_2 ) ;
}
if ( V_2 -> V_71 . V_165 - V_202 ) {
if ( V_189 + 1 < V_7 -> V_190 ) {
V_189 ++ ;
V_17 = F_88 ( V_2 ,
V_189 ) ;
if ( V_17 < 0 )
break;
V_2 -> V_71 . V_165 = V_202 ;
goto V_206;
} else {
V_200 = true ;
}
}
V_35 += V_149 ;
} else {
memcpy ( V_35 , V_7 -> V_156 -> V_205 + V_195 , V_149 ) ;
V_35 += V_149 ;
V_160 = F_79 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_168 -= V_149 ;
if ( V_189 ) {
V_17 = F_88 ( V_2 , 0 ) ;
if ( V_17 < 0 )
break;
V_189 = 0 ;
}
if ( ! V_168 )
break;
V_195 = 0 ;
V_194 ++ ;
V_38 = V_194 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_123 ( V_2 , - 1 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
}
}
V_7 -> V_123 ( V_2 , - 1 ) ;
V_58 -> V_212 = V_58 -> V_16 - ( T_9 ) V_168 ;
if ( V_150 )
V_58 -> V_213 = V_58 -> V_61 - V_197 ;
if ( V_17 < 0 )
return V_17 ;
if ( V_200 )
return - V_134 ;
return V_160 ;
}
static int F_94 ( struct V_1 * V_2 , T_1 V_193 , T_9 V_16 ,
T_9 * V_212 , T_3 * V_35 )
{
struct V_57 V_58 ;
int V_17 ;
F_37 ( V_2 , V_214 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_201 = V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_89 ( V_2 , V_193 , & V_58 ) ;
* V_212 = V_58 . V_212 ;
F_8 ( V_2 ) ;
return V_17 ;
}
int F_95 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_38 )
{
V_7 -> V_50 ( V_2 , V_51 , 0 , V_38 ) ;
V_7 -> V_145 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_38 )
{
int V_12 = V_2 -> V_14 ;
int V_215 = V_7 -> V_9 . V_149 + V_7 -> V_9 . V_152 + V_7 -> V_9 . V_153 ;
int V_147 = V_7 -> V_9 . V_120 ;
T_3 * V_169 = V_7 -> V_146 ;
int V_40 , V_210 , V_216 = 0 , V_217 ;
V_7 -> V_50 ( V_2 , V_90 , V_7 -> V_9 . V_120 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_7 -> V_9 . V_151 ; V_40 ++ ) {
if ( V_216 ) {
V_217 = V_147 + V_40 * ( V_147 + V_215 ) ;
if ( V_2 -> V_45 > 512 )
V_7 -> V_50 ( V_2 , V_104 , V_217 , - 1 ) ;
else
V_7 -> V_50 ( V_2 , V_90 , V_217 , V_38 ) ;
} else
V_216 = 1 ;
V_210 = F_97 ( int , V_12 , V_215 ) ;
V_7 -> V_145 ( V_2 , V_169 , V_210 ) ;
V_169 += V_210 ;
V_12 -= V_210 ;
}
if ( V_12 > 0 )
V_7 -> V_145 ( V_2 , V_169 , V_12 ) ;
return 0 ;
}
int F_98 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_38 )
{
int V_113 = 0 ;
const T_3 * V_35 = V_7 -> V_146 ;
int V_12 = V_2 -> V_14 ;
V_7 -> V_50 ( V_2 , V_88 , V_2 -> V_45 , V_38 ) ;
V_7 -> V_33 ( V_2 , V_35 , V_12 ) ;
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
return V_113 & V_118 ? - V_119 : 0 ;
}
int F_99 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_38 )
{
int V_215 = V_7 -> V_9 . V_149 + V_7 -> V_9 . V_152 + V_7 -> V_9 . V_153 ;
int V_147 = V_7 -> V_9 . V_120 , V_12 = V_2 -> V_14 ;
int V_40 , V_16 , V_217 , V_113 = 0 , V_218 = 0 , V_151 = V_7 -> V_9 . V_151 ;
const T_3 * V_169 = V_7 -> V_146 ;
if ( ! V_7 -> V_9 . V_152 && ! V_7 -> V_9 . V_153 ) {
V_217 = V_151 * ( V_147 + V_215 ) ;
V_151 = 0 ;
} else
V_217 = V_147 ;
V_7 -> V_50 ( V_2 , V_88 , V_217 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_151 ; V_40 ++ ) {
if ( V_218 ) {
if ( V_2 -> V_45 <= 512 ) {
T_8 V_219 = 0xFFFFFFFF ;
V_16 = V_147 ;
while ( V_16 > 0 ) {
int V_220 = F_97 ( int , V_16 , 4 ) ;
V_7 -> V_33 ( V_2 , ( T_3 * ) & V_219 ,
V_220 ) ;
V_16 -= V_220 ;
}
} else {
V_217 = V_147 + V_40 * ( V_147 + V_215 ) ;
V_7 -> V_50 ( V_2 , V_103 , V_217 , - 1 ) ;
}
} else
V_218 = 1 ;
V_16 = F_97 ( int , V_12 , V_215 ) ;
V_7 -> V_33 ( V_2 , V_169 , V_16 ) ;
V_169 += V_16 ;
V_12 -= V_16 ;
}
if ( V_12 > 0 )
V_7 -> V_33 ( V_2 , V_169 , V_12 ) ;
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
return V_113 & V_118 ? - V_119 : 0 ;
}
static int F_100 ( struct V_1 * V_2 , T_1 V_193 ,
struct V_57 * V_58 )
{
int V_38 , V_194 , V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_221 V_222 ;
int V_168 = V_58 -> V_61 ;
int V_16 ;
T_3 * V_35 = V_58 -> V_59 ;
int V_17 = 0 ;
F_7 ( L_9 ,
V_19 , ( unsigned long long ) V_193 , V_168 ) ;
V_222 = V_2 -> V_71 ;
V_16 = F_90 ( V_2 , V_58 ) ;
if ( F_72 ( V_58 -> V_60 >= V_16 ) ) {
F_7 ( L_10 ,
V_19 ) ;
return - V_20 ;
}
if ( F_72 ( V_193 >= V_2 -> V_120 ||
V_58 -> V_60 + V_168 > ( ( V_2 -> V_120 >> V_7 -> V_46 ) -
( V_193 >> V_7 -> V_46 ) ) * V_16 ) ) {
F_7 ( L_11 ,
V_19 ) ;
return - V_20 ;
}
V_28 = ( int ) ( V_193 >> V_7 -> V_122 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
V_194 = ( int ) ( V_193 >> V_7 -> V_46 ) ;
V_38 = V_194 & V_7 -> V_47 ;
while ( 1 ) {
if ( V_58 -> V_62 == V_187 )
V_17 = V_7 -> V_9 . V_223 ( V_2 , V_7 , V_38 ) ;
else
V_17 = V_7 -> V_9 . V_224 ( V_2 , V_7 , V_38 ) ;
if ( V_17 < 0 )
break;
V_16 = F_91 ( V_16 , V_168 ) ;
V_35 = F_85 ( V_2 , V_35 , V_58 , V_16 ) ;
if ( V_7 -> V_48 & V_211 ) {
if ( ! V_7 -> V_79 )
F_56 ( V_7 -> V_99 ) ;
else
F_47 ( V_2 ) ;
}
V_168 -= V_16 ;
if ( ! V_168 )
break;
V_194 ++ ;
V_38 = V_194 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_123 ( V_2 , - 1 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
}
}
V_7 -> V_123 ( V_2 , - 1 ) ;
V_58 -> V_213 = V_58 -> V_61 - V_168 ;
if ( V_17 < 0 )
return V_17 ;
if ( V_2 -> V_71 . V_165 - V_222 . V_165 )
return - V_134 ;
return V_2 -> V_71 . V_166 - V_222 . V_166 ? - V_225 : 0 ;
}
static int F_101 ( struct V_1 * V_2 , T_1 V_193 ,
struct V_57 * V_58 )
{
int V_17 = - V_226 ;
V_58 -> V_212 = 0 ;
if ( V_58 -> V_201 && ( V_193 + V_58 -> V_16 ) > V_2 -> V_120 ) {
F_7 ( L_11 ,
V_19 ) ;
return - V_20 ;
}
F_37 ( V_2 , V_214 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_188 :
case V_187 :
break;
default:
goto V_124;
}
if ( ! V_58 -> V_201 )
V_17 = F_100 ( V_2 , V_193 , V_58 ) ;
else
V_17 = F_89 ( V_2 , V_193 , V_58 ) ;
V_124:
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_144 , int V_38 )
{
V_7 -> V_33 ( V_2 , V_35 , V_2 -> V_45 ) ;
if ( V_144 )
V_7 -> V_33 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_35 , int V_144 ,
int V_38 )
{
int V_147 = V_7 -> V_9 . V_120 ;
int V_148 = V_7 -> V_9 . V_149 ;
T_3 * V_150 = V_7 -> V_146 ;
int V_151 , V_120 ;
for ( V_151 = V_7 -> V_9 . V_151 ; V_151 > 0 ; V_151 -- ) {
V_7 -> V_33 ( V_2 , V_35 , V_147 ) ;
V_35 += V_147 ;
if ( V_7 -> V_9 . V_152 ) {
V_7 -> V_33 ( V_2 , V_150 , V_7 -> V_9 . V_152 ) ;
V_150 += V_7 -> V_9 . V_152 ;
}
V_7 -> V_33 ( V_2 , V_150 , V_148 ) ;
V_150 += V_148 ;
if ( V_7 -> V_9 . V_153 ) {
V_7 -> V_33 ( V_2 , V_150 , V_7 -> V_9 . V_153 ) ;
V_150 += V_7 -> V_9 . V_153 ;
}
}
V_120 = V_2 -> V_14 - ( V_150 - V_7 -> V_146 ) ;
if ( V_120 )
V_7 -> V_33 ( V_2 , V_150 , V_120 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_144 ,
int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 , V_17 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
T_3 * V_155 = V_7 -> V_156 -> V_157 ;
const T_3 * V_37 = V_35 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 )
V_7 -> V_9 . V_162 ( V_2 , V_37 , & V_155 [ V_40 ] ) ;
V_17 = F_105 ( V_2 , V_155 , V_7 -> V_146 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
return V_7 -> V_9 . V_227 ( V_2 , V_7 , V_35 , 1 , V_38 ) ;
}
static int F_106 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_144 ,
int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 , V_17 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
T_3 * V_155 = V_7 -> V_156 -> V_157 ;
const T_3 * V_37 = V_35 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
V_7 -> V_9 . V_183 ( V_2 , V_228 ) ;
V_7 -> V_33 ( V_2 , V_37 , V_147 ) ;
V_7 -> V_9 . V_162 ( V_2 , V_37 , & V_155 [ V_40 ] ) ;
}
V_17 = F_105 ( V_2 , V_155 , V_7 -> V_146 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_33 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_8 V_11 ,
T_8 V_229 , const T_3 * V_35 ,
int V_144 , int V_38 )
{
T_3 * V_230 = V_7 -> V_146 ;
T_3 * V_155 = V_7 -> V_156 -> V_157 ;
int V_231 = V_7 -> V_9 . V_120 ;
int V_232 = V_7 -> V_9 . V_149 ;
int V_233 = V_7 -> V_9 . V_151 ;
T_8 V_170 = V_11 / V_231 ;
T_8 V_171 = ( V_11 + V_229 - 1 ) / V_231 ;
int V_234 = V_2 -> V_14 / V_233 ;
int V_235 , V_17 ;
for ( V_235 = 0 ; V_235 < V_233 ; V_235 ++ ) {
V_7 -> V_9 . V_183 ( V_2 , V_228 ) ;
V_7 -> V_33 ( V_2 , V_35 , V_231 ) ;
if ( ( V_235 < V_170 ) || ( V_235 > V_171 ) )
memset ( V_155 , 0xff , V_232 ) ;
else
V_7 -> V_9 . V_162 ( V_2 , V_35 , V_155 ) ;
if ( ! V_144 || ( V_235 < V_170 ) || ( V_235 > V_171 ) )
memset ( V_230 , 0xff , V_234 ) ;
V_35 += V_231 ;
V_155 += V_232 ;
V_230 += V_234 ;
}
V_155 = V_7 -> V_156 -> V_157 ;
V_17 = F_105 ( V_2 , V_155 , V_7 -> V_146 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_33 ( V_2 , V_7 -> V_146 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_35 , int V_144 ,
int V_38 )
{
int V_40 , V_147 = V_7 -> V_9 . V_120 ;
int V_148 = V_7 -> V_9 . V_149 ;
int V_154 = V_7 -> V_9 . V_151 ;
const T_3 * V_37 = V_35 ;
T_3 * V_150 = V_7 -> V_146 ;
for ( V_40 = 0 ; V_154 ; V_154 -- , V_40 += V_148 , V_37 += V_147 ) {
V_7 -> V_9 . V_183 ( V_2 , V_228 ) ;
V_7 -> V_33 ( V_2 , V_37 , V_147 ) ;
if ( V_7 -> V_9 . V_152 ) {
V_7 -> V_33 ( V_2 , V_150 , V_7 -> V_9 . V_152 ) ;
V_150 += V_7 -> V_9 . V_152 ;
}
V_7 -> V_9 . V_162 ( V_2 , V_37 , V_150 ) ;
V_7 -> V_33 ( V_2 , V_150 , V_148 ) ;
V_150 += V_148 ;
if ( V_7 -> V_9 . V_153 ) {
V_7 -> V_33 ( V_2 , V_150 , V_7 -> V_9 . V_153 ) ;
V_150 += V_7 -> V_9 . V_153 ;
}
}
V_40 = V_2 -> V_14 - ( V_150 - V_7 -> V_146 ) ;
if ( V_40 )
V_7 -> V_33 ( V_2 , V_150 , V_40 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_8 V_11 , int V_229 , const T_3 * V_35 ,
int V_144 , int V_38 , int V_236 , int V_237 )
{
int V_113 , V_238 ;
if ( ! ( V_7 -> V_48 & V_239 ) &&
V_7 -> V_9 . V_240 )
V_238 = V_11 || ( V_229 < V_2 -> V_45 ) ;
else
V_238 = 0 ;
V_7 -> V_50 ( V_2 , V_88 , 0x00 , V_38 ) ;
if ( F_72 ( V_237 ) )
V_113 = V_7 -> V_9 . V_227 ( V_2 , V_7 , V_35 ,
V_144 , V_38 ) ;
else if ( V_238 )
V_113 = V_7 -> V_9 . V_240 ( V_2 , V_7 , V_11 , V_229 ,
V_35 , V_144 , V_38 ) ;
else
V_113 = V_7 -> V_9 . V_241 ( V_2 , V_7 , V_35 , V_144 ,
V_38 ) ;
if ( V_113 < 0 )
return V_113 ;
V_236 = 0 ;
if ( ! V_236 || ! F_110 ( V_7 ) ) {
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
if ( ( V_113 & V_118 ) && ( V_7 -> V_242 ) )
V_113 = V_7 -> V_242 ( V_2 , V_7 , V_68 , V_113 ,
V_38 ) ;
if ( V_113 & V_118 )
return - V_119 ;
} else {
V_7 -> V_50 ( V_2 , V_102 , - 1 , - 1 ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
}
return 0 ;
}
static T_3 * F_111 ( struct V_1 * V_2 , T_3 * V_150 , T_9 V_16 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
memset ( V_7 -> V_146 , 0xff , V_2 -> V_14 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_187 :
memcpy ( V_7 -> V_146 + V_58 -> V_60 , V_150 , V_16 ) ;
return V_150 + V_16 ;
case V_188 :
V_17 = F_112 ( V_2 , V_150 , V_7 -> V_146 ,
V_58 -> V_60 , V_16 ) ;
F_87 ( V_17 ) ;
return V_150 + V_16 ;
default:
F_19 () ;
}
return NULL ;
}
static int F_113 ( struct V_1 * V_2 , T_1 V_243 ,
struct V_57 * V_58 )
{
int V_28 , V_194 , V_38 , V_244 , V_84 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_8 V_245 = V_58 -> V_16 ;
T_8 V_246 = V_58 -> V_61 ;
T_8 V_247 = F_90 ( V_2 , V_58 ) ;
T_3 * V_150 = V_58 -> V_59 ;
T_3 * V_35 = V_58 -> V_201 ;
int V_17 ;
int V_144 = V_150 ? 1 : 0 ;
V_58 -> V_212 = 0 ;
if ( ! V_245 )
return 0 ;
if ( F_114 ( V_243 ) || F_114 ( V_58 -> V_16 ) ) {
F_115 ( L_12 ,
V_19 ) ;
return - V_20 ;
}
V_84 = V_243 & ( V_2 -> V_45 - 1 ) ;
V_28 = ( int ) ( V_243 >> V_7 -> V_122 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
V_17 = - V_119 ;
goto V_248;
}
V_194 = ( int ) ( V_243 >> V_7 -> V_46 ) ;
V_38 = V_194 & V_7 -> V_47 ;
V_244 = ( 1 << ( V_7 -> V_18 - V_7 -> V_46 ) ) - 1 ;
if ( V_243 <= ( ( T_1 ) V_7 -> V_204 << V_7 -> V_46 ) &&
( ( T_1 ) V_7 -> V_204 << V_7 -> V_46 ) < ( V_243 + V_58 -> V_16 ) )
V_7 -> V_204 = - 1 ;
if ( V_150 && V_58 -> V_60 && ( V_58 -> V_60 + V_58 -> V_61 > V_247 ) ) {
V_17 = - V_20 ;
goto V_248;
}
while ( 1 ) {
int V_149 = V_2 -> V_45 ;
int V_236 = V_245 > V_149 && V_38 != V_244 ;
T_3 * V_249 = V_35 ;
int V_199 ;
int V_250 = ( V_84 || V_245 < ( V_2 -> V_45 - 1 ) ) ;
if ( V_250 )
V_199 = 1 ;
else if ( V_7 -> V_48 & V_203 )
V_199 = ! F_92 ( V_35 ) ;
else
V_199 = 0 ;
if ( V_199 ) {
F_7 ( L_13 ,
V_19 , V_35 ) ;
V_236 = 0 ;
if ( V_250 )
V_149 = F_97 ( int , V_149 - V_84 , V_245 ) ;
V_7 -> V_204 = - 1 ;
memset ( V_7 -> V_156 -> V_205 , 0xff , V_2 -> V_45 ) ;
memcpy ( & V_7 -> V_156 -> V_205 [ V_84 ] , V_35 , V_149 ) ;
V_249 = V_7 -> V_156 -> V_205 ;
}
if ( F_72 ( V_150 ) ) {
T_9 V_16 = F_91 ( V_246 , V_247 ) ;
V_150 = F_111 ( V_2 , V_150 , V_16 , V_58 ) ;
V_246 -= V_16 ;
} else {
memset ( V_7 -> V_146 , 0xff , V_2 -> V_14 ) ;
}
V_17 = V_7 -> V_241 ( V_2 , V_7 , V_84 , V_149 , V_249 ,
V_144 , V_38 , V_236 ,
( V_58 -> V_62 == V_187 ) ) ;
if ( V_17 )
break;
V_245 -= V_149 ;
if ( ! V_245 )
break;
V_84 = 0 ;
V_35 += V_149 ;
V_194 ++ ;
V_38 = V_194 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_123 ( V_2 , - 1 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
}
}
V_58 -> V_212 = V_58 -> V_16 - V_245 ;
if ( F_72 ( V_150 ) )
V_58 -> V_213 = V_58 -> V_61 ;
V_248:
V_7 -> V_123 ( V_2 , - 1 ) ;
return V_17 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_243 , T_9 V_16 ,
T_9 * V_212 , const T_3 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_57 V_58 ;
int V_17 ;
F_65 ( V_2 , V_7 , 400 ) ;
F_59 ( V_7 , V_2 , V_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_201 = ( T_3 * ) V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_113 ( V_2 , V_243 , & V_58 ) ;
* V_212 = V_58 . V_212 ;
return V_17 ;
}
static int F_117 ( struct V_1 * V_2 , T_1 V_243 , T_9 V_16 ,
T_9 * V_212 , const T_3 * V_35 )
{
struct V_57 V_58 ;
int V_17 ;
F_37 ( V_2 , V_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_201 = ( T_3 * ) V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_113 ( V_2 , V_243 , & V_58 ) ;
* V_212 = V_58 . V_212 ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_243 ,
struct V_57 * V_58 )
{
int V_28 , V_38 , V_113 , V_16 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_14 ,
V_19 , ( unsigned int ) V_243 , ( int ) V_58 -> V_61 ) ;
V_16 = F_90 ( V_2 , V_58 ) ;
if ( ( V_58 -> V_60 + V_58 -> V_61 ) > V_16 ) {
F_7 ( L_15 ,
V_19 ) ;
return - V_20 ;
}
if ( F_72 ( V_58 -> V_60 >= V_16 ) ) {
F_7 ( L_16 ,
V_19 ) ;
return - V_20 ;
}
if ( F_72 ( V_243 >= V_2 -> V_120 ||
V_58 -> V_60 + V_58 -> V_61 >
( ( V_2 -> V_120 >> V_7 -> V_46 ) -
( V_243 >> V_7 -> V_46 ) ) * V_16 ) ) {
F_7 ( L_17 ,
V_19 ) ;
return - V_20 ;
}
V_28 = ( int ) ( V_243 >> V_7 -> V_122 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
V_38 = ( int ) ( V_243 >> V_7 -> V_46 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
if ( F_39 ( V_2 ) ) {
V_7 -> V_123 ( V_2 , - 1 ) ;
return - V_251 ;
}
if ( V_38 == V_7 -> V_204 )
V_7 -> V_204 = - 1 ;
F_111 ( V_2 , V_58 -> V_59 , V_58 -> V_61 , V_58 ) ;
if ( V_58 -> V_62 == V_187 )
V_113 = V_7 -> V_9 . V_252 ( V_2 , V_7 , V_38 & V_7 -> V_47 ) ;
else
V_113 = V_7 -> V_9 . V_253 ( V_2 , V_7 , V_38 & V_7 -> V_47 ) ;
V_7 -> V_123 ( V_2 , - 1 ) ;
if ( V_113 )
return V_113 ;
V_58 -> V_213 = V_58 -> V_61 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , T_1 V_243 ,
struct V_57 * V_58 )
{
int V_17 = - V_226 ;
V_58 -> V_212 = 0 ;
if ( V_58 -> V_201 && ( V_243 + V_58 -> V_16 ) > V_2 -> V_120 ) {
F_7 ( L_17 ,
V_19 ) ;
return - V_20 ;
}
F_37 ( V_2 , V_68 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_188 :
case V_187 :
break;
default:
goto V_124;
}
if ( ! V_58 -> V_201 )
V_17 = F_34 ( V_2 , V_243 , V_58 ) ;
else
V_17 = F_113 ( V_2 , V_243 , V_58 ) ;
V_124:
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_119 ( struct V_1 * V_2 , int V_38 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_50 ( V_2 , V_96 , - 1 , V_38 ) ;
V_7 -> V_50 ( V_2 , V_97 , - 1 , - 1 ) ;
return V_7 -> V_117 ( V_2 , V_7 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_65 * V_254 )
{
return F_36 ( V_2 , V_254 , 0 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_65 * V_254 ,
int V_76 )
{
int V_38 , V_113 , V_255 , V_17 , V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_16 ;
F_7 ( L_5 ,
V_19 , ( unsigned long long ) V_254 -> V_67 ,
( unsigned long long ) V_254 -> V_16 ) ;
if ( F_6 ( V_2 , V_254 -> V_67 , V_254 -> V_16 ) )
return - V_20 ;
F_37 ( V_2 , V_256 ) ;
V_38 = ( int ) ( V_254 -> V_67 >> V_7 -> V_46 ) ;
V_28 = ( int ) ( V_254 -> V_67 >> V_7 -> V_122 ) ;
V_255 = 1 << ( V_7 -> V_18 - V_7 -> V_46 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_6 ,
V_19 ) ;
V_254 -> V_24 = V_126 ;
goto V_257;
}
V_16 = V_254 -> V_16 ;
V_254 -> V_24 = V_258 ;
while ( V_16 ) {
if ( F_42 ( V_2 , ( ( T_1 ) V_38 ) <<
V_7 -> V_46 , V_76 ) ) {
F_121 ( L_18 ,
V_19 , V_38 ) ;
V_254 -> V_24 = V_126 ;
goto V_257;
}
if ( V_38 <= V_7 -> V_204 && V_7 -> V_204 <
( V_38 + V_255 ) )
V_7 -> V_204 = - 1 ;
V_113 = V_7 -> V_259 ( V_2 , V_38 & V_7 -> V_47 ) ;
if ( ( V_113 & V_118 ) && ( V_7 -> V_242 ) )
V_113 = V_7 -> V_242 ( V_2 , V_7 , V_256 ,
V_113 , V_38 ) ;
if ( V_113 & V_118 ) {
F_7 ( L_19 ,
V_19 , V_38 ) ;
V_254 -> V_24 = V_126 ;
V_254 -> V_260 =
( ( T_1 ) V_38 << V_7 -> V_46 ) ;
goto V_257;
}
V_16 -= ( 1ULL << V_7 -> V_18 ) ;
V_38 += V_255 ;
if ( V_16 && ! ( V_38 & V_7 -> V_47 ) ) {
V_28 ++ ;
V_7 -> V_123 ( V_2 , - 1 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
}
}
V_254 -> V_24 = V_261 ;
V_257:
V_17 = V_254 -> V_24 == V_261 ? 0 : - V_119 ;
V_7 -> V_123 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
if ( ! V_17 )
F_122 ( V_254 ) ;
return V_17 ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_7 ( L_20 , V_19 ) ;
F_37 ( V_2 , V_262 ) ;
F_8 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_263 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_28 = ( int ) ( V_263 >> V_7 -> V_122 ) ;
int V_17 ;
F_37 ( V_2 , V_214 ) ;
V_7 -> V_123 ( V_2 , V_28 ) ;
V_17 = F_42 ( V_2 , V_263 , 0 ) ;
V_7 -> V_123 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_125 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_17 ;
V_17 = F_124 ( V_2 , V_15 ) ;
if ( V_17 ) {
if ( V_17 > 0 )
return 0 ;
return V_17 ;
}
return F_35 ( V_2 , V_15 ) ;
}
static int F_126 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_264 )
{
int V_113 ;
int V_40 ;
if ( ! V_7 -> V_265 ||
! ( F_127 ( V_7 -> V_266 . V_267 )
& V_268 ) )
return - V_20 ;
V_7 -> V_50 ( V_2 , V_269 , V_67 , - 1 ) ;
for ( V_40 = 0 ; V_40 < V_270 ; ++ V_40 )
V_7 -> V_271 ( V_2 , V_264 [ V_40 ] ) ;
V_113 = V_7 -> V_117 ( V_2 , V_7 ) ;
if ( V_113 & V_118 )
return - V_119 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_264 )
{
int V_40 ;
if ( ! V_7 -> V_265 ||
! ( F_127 ( V_7 -> V_266 . V_267 )
& V_268 ) )
return - V_20 ;
V_7 -> V_50 ( V_2 , V_272 , V_67 , - 1 ) ;
for ( V_40 = 0 ; V_40 < V_270 ; ++ V_40 )
* V_264 ++ = V_7 -> V_54 ( V_2 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_111 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_24 == V_111 )
F_8 ( V_2 ) ;
else
F_131 ( L_21 ,
V_19 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_37 ( V_2 , V_111 ) ;
}
static void F_133 ( struct V_6 * V_7 , int V_179 )
{
if ( ! V_7 -> V_99 )
V_7 -> V_99 = 20 ;
if ( V_7 -> V_50 == NULL )
V_7 -> V_50 = F_54 ;
if ( V_7 -> V_117 == NULL )
V_7 -> V_117 = F_66 ;
if ( ! V_7 -> V_123 )
V_7 -> V_123 = F_18 ;
if ( ! V_7 -> V_273 )
V_7 -> V_273 = F_126 ;
if ( ! V_7 -> V_274 )
V_7 -> V_274 = F_128 ;
if ( ! V_7 -> V_54 || V_7 -> V_54 == F_12 )
V_7 -> V_54 = V_179 ? F_14 : F_12 ;
if ( ! V_7 -> V_53 )
V_7 -> V_53 = F_17 ;
if ( ! V_7 -> V_77 )
V_7 -> V_77 = F_30 ;
if ( ! V_7 -> V_69 )
V_7 -> V_69 = F_33 ;
if ( ! V_7 -> V_33 || V_7 -> V_33 == F_22 )
V_7 -> V_33 = V_179 ? F_26 : F_22 ;
if ( ! V_7 -> V_271 || V_7 -> V_271 == F_20 )
V_7 -> V_271 = V_179 ? F_21 : F_20 ;
if ( ! V_7 -> V_145 || V_7 -> V_145 == F_24 )
V_7 -> V_145 = V_179 ? F_28 : F_24 ;
if ( ! V_7 -> V_275 )
V_7 -> V_275 = V_276 ;
if ( ! V_7 -> V_21 ) {
V_7 -> V_21 = & V_7 -> V_277 ;
F_134 ( & V_7 -> V_21 -> V_22 ) ;
F_135 ( & V_7 -> V_21 -> V_26 ) ;
}
}
static void F_136 ( T_3 * V_278 , T_9 V_16 )
{
T_10 V_40 ;
V_278 [ V_16 - 1 ] = 0 ;
for ( V_40 = 0 ; V_40 < V_16 - 1 ; V_40 ++ ) {
if ( V_278 [ V_40 ] < ' ' || V_278 [ V_40 ] > 127 )
V_278 [ V_40 ] = '?' ;
}
F_137 ( V_278 ) ;
}
static T_4 F_138 ( T_4 V_279 , T_11 const * V_37 , T_9 V_16 )
{
int V_40 ;
while ( V_16 -- ) {
V_279 ^= * V_37 ++ << 8 ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
V_279 = ( V_279 << 1 ) ^ ( ( V_279 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_279 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_280 * V_37 )
{
struct V_281 * V_282 ;
struct V_283 * V_278 ;
struct V_284 * V_9 ;
T_3 * V_285 ;
int V_17 = - V_20 ;
int V_16 ;
int V_40 ;
V_16 = F_127 ( V_37 -> V_286 ) * 16 ;
V_282 = F_140 ( V_16 , V_287 ) ;
if ( ! V_282 )
return - V_288 ;
V_7 -> V_50 ( V_2 , V_289 , 0 , - 1 ) ;
V_7 -> V_50 ( V_2 , V_104 ,
sizeof( * V_37 ) * V_37 -> V_290 , - 1 ) ;
V_7 -> V_145 ( V_2 , ( T_3 * ) V_282 , V_16 ) ;
if ( ( F_138 ( V_291 , ( ( T_3 * ) V_282 ) + 2 , V_16 - 2 )
!= F_127 ( V_282 -> V_279 ) ) ) {
F_7 ( L_22 ) ;
goto V_292;
}
if ( strncmp ( V_282 -> V_293 , L_23 , 4 ) ) {
F_7 ( L_24 ) ;
goto V_292;
}
V_285 = ( T_3 * ) ( V_282 + 1 ) ;
for ( V_40 = 0 ; V_40 < V_294 ; V_40 ++ ) {
V_278 = V_282 -> V_295 + V_40 ;
if ( V_278 -> type == V_296 )
break;
V_285 += V_278 -> V_12 * 16 ;
}
if ( V_40 == V_294 ) {
F_7 ( L_25 ) ;
goto V_292;
}
V_9 = (struct V_284 * ) V_285 ;
if ( ! V_9 -> V_297 ) {
F_7 ( L_26 ) ;
goto V_292;
}
V_7 -> V_298 = V_9 -> V_299 ;
V_7 -> V_300 = 1 << V_9 -> V_297 ;
V_17 = 0 ;
V_292:
F_141 ( V_282 ) ;
return V_17 ;
}
static int F_142 ( struct V_1 * V_2 , int V_189 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_301 [ V_270 ] = { V_189 } ;
return V_7 -> V_273 ( V_2 , V_7 , V_302 ,
V_301 ) ;
}
static void F_143 ( struct V_6 * V_7 ,
struct V_280 * V_37 )
{
struct V_303 * V_304 = ( void * ) V_37 -> V_305 ;
if ( F_127 ( V_37 -> V_306 ) < 1 )
return;
V_7 -> V_190 = V_304 -> V_307 ;
V_7 -> V_191 = F_142 ;
}
static int F_144 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_179 )
{
struct V_280 * V_37 = & V_7 -> V_266 ;
int V_40 , V_308 ;
int V_309 ;
V_7 -> V_50 ( V_2 , V_310 , 0x20 , - 1 ) ;
if ( V_7 -> V_54 ( V_2 ) != 'O' || V_7 -> V_54 ( V_2 ) != 'N' ||
V_7 -> V_54 ( V_2 ) != 'F' || V_7 -> V_54 ( V_2 ) != 'I' )
return 0 ;
V_7 -> V_50 ( V_2 , V_289 , 0 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
for ( V_308 = 0 ; V_308 < sizeof( * V_37 ) ; V_308 ++ )
( ( T_3 * ) V_37 ) [ V_308 ] = V_7 -> V_54 ( V_2 ) ;
if ( F_138 ( V_291 , ( T_3 * ) V_37 , 254 ) ==
F_127 ( V_37 -> V_279 ) ) {
break;
}
}
if ( V_40 == 3 ) {
F_131 ( L_27 ) ;
return 0 ;
}
V_309 = F_127 ( V_37 -> V_311 ) ;
if ( V_309 & ( 1 << 5 ) )
V_7 -> V_265 = 23 ;
else if ( V_309 & ( 1 << 4 ) )
V_7 -> V_265 = 22 ;
else if ( V_309 & ( 1 << 3 ) )
V_7 -> V_265 = 21 ;
else if ( V_309 & ( 1 << 2 ) )
V_7 -> V_265 = 20 ;
else if ( V_309 & ( 1 << 1 ) )
V_7 -> V_265 = 10 ;
if ( ! V_7 -> V_265 ) {
F_145 ( L_28 , V_309 ) ;
return 0 ;
}
F_136 ( V_37 -> V_312 , sizeof( V_37 -> V_312 ) ) ;
F_136 ( V_37 -> V_313 , sizeof( V_37 -> V_313 ) ) ;
if ( ! V_2 -> V_314 )
V_2 -> V_314 = V_37 -> V_313 ;
V_2 -> V_45 = F_146 ( V_37 -> V_315 ) ;
V_2 -> V_44 = 1 << ( F_147 ( F_146 ( V_37 -> V_255 ) ) - 1 ) ;
V_2 -> V_44 *= V_2 -> V_45 ;
V_2 -> V_14 = F_127 ( V_37 -> V_316 ) ;
V_7 -> V_93 = 1 << ( F_147 ( F_146 ( V_37 -> V_317 ) ) - 1 ) ;
V_7 -> V_93 *= ( T_2 ) V_2 -> V_44 * V_37 -> V_318 ;
V_7 -> V_319 = V_37 -> V_319 ;
if ( F_148 ( V_7 ) & V_320 )
* V_179 = V_49 ;
else
* V_179 = 0 ;
if ( V_37 -> V_299 != 0xff ) {
V_7 -> V_298 = V_37 -> V_299 ;
V_7 -> V_300 = 512 ;
} else if ( V_7 -> V_265 >= 21 &&
( F_148 ( V_7 ) & V_321 ) ) {
if ( V_2 -> V_45 > 512 && V_7 -> V_50 == F_54 )
V_7 -> V_50 = F_58 ;
if ( F_139 ( V_2 , V_7 , V_37 ) )
F_121 ( L_29 ) ;
} else {
F_121 ( L_30 ) ;
}
if ( V_37 -> V_322 == V_323 )
F_143 ( V_7 , V_37 ) ;
return 1 ;
}
static int F_149 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_179 )
{
struct V_324 * V_37 = & V_7 -> V_325 ;
struct V_326 * V_9 ;
int V_309 ;
int V_40 , V_308 ;
V_7 -> V_50 ( V_2 , V_310 , 0x40 , - 1 ) ;
if ( V_7 -> V_54 ( V_2 ) != 'J' || V_7 -> V_54 ( V_2 ) != 'E' ||
V_7 -> V_54 ( V_2 ) != 'D' || V_7 -> V_54 ( V_2 ) != 'E' ||
V_7 -> V_54 ( V_2 ) != 'C' )
return 0 ;
V_7 -> V_50 ( V_2 , V_289 , 0x40 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
for ( V_308 = 0 ; V_308 < sizeof( * V_37 ) ; V_308 ++ )
( ( T_3 * ) V_37 ) [ V_308 ] = V_7 -> V_54 ( V_2 ) ;
if ( F_138 ( V_291 , ( T_3 * ) V_37 , 510 ) ==
F_127 ( V_37 -> V_279 ) )
break;
}
if ( V_40 == 3 ) {
F_131 ( L_31 ) ;
return 0 ;
}
V_309 = F_127 ( V_37 -> V_311 ) ;
if ( V_309 & ( 1 << 2 ) )
V_7 -> V_327 = 10 ;
else if ( V_309 & ( 1 << 1 ) )
V_7 -> V_327 = 1 ;
if ( ! V_7 -> V_327 ) {
F_145 ( L_32 , V_309 ) ;
return 0 ;
}
F_136 ( V_37 -> V_312 , sizeof( V_37 -> V_312 ) ) ;
F_136 ( V_37 -> V_313 , sizeof( V_37 -> V_313 ) ) ;
if ( ! V_2 -> V_314 )
V_2 -> V_314 = V_37 -> V_313 ;
V_2 -> V_45 = F_146 ( V_37 -> V_315 ) ;
V_2 -> V_44 = 1 << ( F_147 ( F_146 ( V_37 -> V_255 ) ) - 1 ) ;
V_2 -> V_44 *= V_2 -> V_45 ;
V_2 -> V_14 = F_127 ( V_37 -> V_316 ) ;
V_7 -> V_93 = 1 << ( F_147 ( F_146 ( V_37 -> V_317 ) ) - 1 ) ;
V_7 -> V_93 *= ( T_2 ) V_2 -> V_44 * V_37 -> V_318 ;
V_7 -> V_319 = V_37 -> V_319 ;
if ( F_150 ( V_7 ) & V_328 )
* V_179 = V_49 ;
else
* V_179 = 0 ;
V_9 = & V_37 -> V_329 [ 0 ] ;
if ( V_9 -> V_297 >= 9 ) {
V_7 -> V_298 = V_9 -> V_299 ;
V_7 -> V_300 = 1 << V_9 -> V_297 ;
} else {
F_121 ( L_26 ) ;
}
return 1 ;
}
static int F_151 ( T_11 * V_330 , int V_331 , int V_332 )
{
int V_40 , V_308 ;
for ( V_40 = 0 ; V_40 < V_332 ; V_40 ++ )
for ( V_308 = V_40 + V_332 ; V_308 < V_331 ; V_308 += V_332 )
if ( V_330 [ V_40 ] != V_330 [ V_308 ] )
return 0 ;
return 1 ;
}
static int F_152 ( T_11 * V_330 , int V_331 )
{
int V_333 , V_332 ;
for ( V_333 = V_331 - 1 ; V_333 >= 0 ; V_333 -- )
if ( V_330 [ V_333 ] )
break;
if ( V_333 < 0 )
return 0 ;
for ( V_332 = 1 ; V_332 < V_331 ; V_332 ++ )
if ( F_151 ( V_330 , V_331 , V_332 ) )
break;
if ( V_332 < V_331 )
return V_332 ;
if ( V_333 < V_331 - 1 )
return V_333 + 1 ;
return V_331 ;
}
static int F_153 ( T_11 V_334 )
{
int V_335 ;
V_335 = V_334 & V_336 ;
V_335 >>= V_337 ;
return V_335 + 1 ;
}
static void F_154 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_11 V_330 [ 8 ] , int * V_179 )
{
int V_338 , V_339 ;
V_7 -> V_319 = F_153 ( V_330 [ 2 ] ) ;
V_338 = V_330 [ 3 ] ;
V_339 = F_152 ( V_330 , 8 ) ;
if ( V_339 == 6 && V_330 [ 0 ] == V_340 &&
! F_155 ( V_7 ) && V_330 [ 5 ] != 0x00 ) {
V_2 -> V_45 = 2048 << ( V_338 & 0x03 ) ;
V_338 >>= 2 ;
switch ( ( ( V_338 >> 2 ) & 0x04 ) | ( V_338 & 0x03 ) ) {
case 1 :
V_2 -> V_14 = 128 ;
break;
case 2 :
V_2 -> V_14 = 218 ;
break;
case 3 :
V_2 -> V_14 = 400 ;
break;
case 4 :
V_2 -> V_14 = 436 ;
break;
case 5 :
V_2 -> V_14 = 512 ;
break;
case 6 :
V_2 -> V_14 = 640 ;
break;
case 7 :
default:
V_2 -> V_14 = 1024 ;
break;
}
V_338 >>= 2 ;
V_2 -> V_44 = ( 128 * 1024 ) <<
( ( ( V_338 >> 1 ) & 0x04 ) | ( V_338 & 0x03 ) ) ;
* V_179 = 0 ;
} else if ( V_339 == 6 && V_330 [ 0 ] == V_341 &&
! F_155 ( V_7 ) ) {
unsigned int V_342 ;
V_2 -> V_45 = 2048 << ( V_338 & 0x03 ) ;
V_338 >>= 2 ;
switch ( ( ( V_338 >> 2 ) & 0x04 ) | ( V_338 & 0x03 ) ) {
case 0 :
V_2 -> V_14 = 128 ;
break;
case 1 :
V_2 -> V_14 = 224 ;
break;
case 2 :
V_2 -> V_14 = 448 ;
break;
case 3 :
V_2 -> V_14 = 64 ;
break;
case 4 :
V_2 -> V_14 = 32 ;
break;
case 5 :
V_2 -> V_14 = 16 ;
break;
default:
V_2 -> V_14 = 640 ;
break;
}
V_338 >>= 2 ;
V_342 = ( ( V_338 >> 1 ) & 0x04 ) | ( V_338 & 0x03 ) ;
if ( V_342 < 0x03 )
V_2 -> V_44 = ( 128 * 1024 ) << V_342 ;
else if ( V_342 == 0x03 )
V_2 -> V_44 = 768 * 1024 ;
else
V_2 -> V_44 = ( 64 * 1024 ) << V_342 ;
* V_179 = 0 ;
} else {
V_2 -> V_45 = 1024 << ( V_338 & 0x03 ) ;
V_338 >>= 2 ;
V_2 -> V_14 = ( 8 << ( V_338 & 0x01 ) ) *
( V_2 -> V_45 >> 9 ) ;
V_338 >>= 2 ;
V_2 -> V_44 = ( 64 * 1024 ) << ( V_338 & 0x03 ) ;
V_338 >>= 2 ;
* V_179 = ( V_338 & 0x01 ) ? V_49 : 0 ;
if ( V_339 >= 6 && V_330 [ 0 ] == V_343 &&
F_155 ( V_7 ) &&
( V_330 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_330 [ 4 ] & 0x80 ) ) {
V_2 -> V_14 = 32 * V_2 -> V_45 >> 9 ;
}
}
}
static void F_156 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_344 * type , T_11 V_330 [ 8 ] ,
int * V_179 )
{
int V_345 = V_330 [ 0 ] ;
V_2 -> V_44 = type -> V_44 ;
V_2 -> V_45 = type -> V_346 ;
V_2 -> V_14 = V_2 -> V_45 / 32 ;
* V_179 = type -> V_48 & V_49 ;
V_7 -> V_319 = 1 ;
if ( V_345 == V_347 && V_330 [ 4 ] != 0x00 && V_330 [ 5 ] == 0x00
&& V_330 [ 6 ] == 0x00 && V_330 [ 7 ] == 0x00
&& V_2 -> V_45 == 512 ) {
V_2 -> V_44 = 128 * 1024 ;
V_2 -> V_44 <<= ( ( V_330 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_157 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_11 V_330 [ 8 ] )
{
int V_345 = V_330 [ 0 ] ;
if ( V_2 -> V_45 > 512 || ( V_7 -> V_48 & V_49 ) )
V_7 -> V_52 = V_348 ;
else
V_7 -> V_52 = V_349 ;
if ( ! F_155 ( V_7 ) &&
( V_345 == V_340 ||
V_345 == V_341 ) )
V_7 -> V_42 |= V_43 ;
else if ( ( F_155 ( V_7 ) &&
( V_345 == V_340 ||
V_345 == V_341 ||
V_345 == V_343 ||
V_345 == V_347 ||
V_345 == V_350 ) ) ||
( V_2 -> V_45 == 2048 &&
V_345 == V_323 ) )
V_7 -> V_42 |= V_56 ;
}
static inline bool F_158 ( struct V_344 * type )
{
return type -> V_339 ;
}
static bool F_159 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_344 * type , T_11 * V_330 , int * V_179 )
{
if ( ! strncmp ( type -> V_351 , V_330 , type -> V_339 ) ) {
V_2 -> V_45 = type -> V_346 ;
V_2 -> V_44 = type -> V_44 ;
V_2 -> V_14 = type -> V_14 ;
V_7 -> V_319 = F_153 ( V_330 [ 2 ] ) ;
V_7 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
V_7 -> V_48 |= type -> V_48 ;
V_7 -> V_298 = F_160 ( type ) ;
V_7 -> V_300 = F_161 ( type ) ;
V_7 -> V_352 =
type -> V_352 ;
* V_179 = type -> V_48 & V_49 ;
if ( ! V_2 -> V_314 )
V_2 -> V_314 = type -> V_314 ;
return true ;
}
return false ;
}
static struct V_344 * F_162 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int * V_345 , int * V_353 ,
struct V_344 * type )
{
int V_179 ;
int V_40 , V_354 ;
T_11 V_330 [ 8 ] ;
V_7 -> V_123 ( V_2 , 0 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
V_7 -> V_50 ( V_2 , V_310 , 0x00 , - 1 ) ;
* V_345 = V_7 -> V_54 ( V_2 ) ;
* V_353 = V_7 -> V_54 ( V_2 ) ;
V_7 -> V_50 ( V_2 , V_310 , 0x00 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
V_330 [ V_40 ] = V_7 -> V_54 ( V_2 ) ;
if ( V_330 [ 0 ] != * V_345 || V_330 [ 1 ] != * V_353 ) {
F_145 ( L_33 ,
* V_345 , * V_353 , V_330 [ 0 ] , V_330 [ 1 ] ) ;
return F_163 ( - V_355 ) ;
}
if ( ! type )
type = V_356 ;
for (; type -> V_314 != NULL ; type ++ ) {
if ( F_158 ( type ) ) {
if ( F_159 ( V_2 , V_7 , type , V_330 , & V_179 ) )
goto V_357;
} else if ( * V_353 == type -> V_353 ) {
break;
}
}
V_7 -> V_265 = 0 ;
if ( ! type -> V_314 || ! type -> V_346 ) {
if ( F_144 ( V_2 , V_7 , & V_179 ) )
goto V_357;
if ( F_149 ( V_2 , V_7 , & V_179 ) )
goto V_357;
}
if ( ! type -> V_314 )
return F_163 ( - V_355 ) ;
if ( ! V_2 -> V_314 )
V_2 -> V_314 = type -> V_314 ;
V_7 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
if ( ! type -> V_346 ) {
F_154 ( V_2 , V_7 , V_330 , & V_179 ) ;
} else {
F_156 ( V_2 , V_7 , type , V_330 , & V_179 ) ;
}
V_7 -> V_48 |= type -> V_48 ;
if ( * V_345 != V_340 && ! type -> V_346 )
V_7 -> V_48 &= ~ V_358 ;
V_357:
for ( V_354 = 0 ; V_359 [ V_354 ] . V_351 != 0x0 ; V_354 ++ ) {
if ( V_359 [ V_354 ] . V_351 == * V_345 )
break;
}
if ( V_7 -> V_48 & V_360 ) {
F_67 ( V_7 -> V_48 & V_49 ) ;
V_7 -> V_48 |= V_179 ;
F_133 ( V_7 , V_179 ) ;
} else if ( V_179 != ( V_7 -> V_48 & V_49 ) ) {
F_145 ( L_34 ,
* V_345 , * V_353 ) ;
F_145 ( L_35 , V_359 [ V_354 ] . V_314 , V_2 -> V_314 ) ;
F_121 ( L_36 ,
( V_7 -> V_48 & V_49 ) ? 16 : 8 ,
V_179 ? 16 : 8 ) ;
return F_163 ( - V_20 ) ;
}
F_157 ( V_2 , V_7 , V_330 ) ;
V_7 -> V_46 = F_164 ( V_2 -> V_45 ) - 1 ;
V_7 -> V_47 = ( V_7 -> V_93 >> V_7 -> V_46 ) - 1 ;
V_7 -> V_361 = V_7 -> V_18 =
F_164 ( V_2 -> V_44 ) - 1 ;
if ( V_7 -> V_93 & 0xffffffff )
V_7 -> V_122 = F_164 ( ( unsigned ) V_7 -> V_93 ) - 1 ;
else {
V_7 -> V_122 = F_164 ( ( unsigned ) ( V_7 -> V_93 >> 32 ) ) ;
V_7 -> V_122 += 32 - 1 ;
}
V_7 -> V_55 = 8 ;
V_7 -> V_259 = F_119 ;
if ( V_2 -> V_45 > 512 && V_7 -> V_50 == F_54 )
V_7 -> V_50 = F_58 ;
F_145 ( L_34 ,
* V_345 , * V_353 ) ;
if ( V_7 -> V_265 )
F_145 ( L_35 , V_359 [ V_354 ] . V_314 ,
V_7 -> V_266 . V_313 ) ;
else if ( V_7 -> V_327 )
F_145 ( L_35 , V_359 [ V_354 ] . V_314 ,
V_7 -> V_325 . V_313 ) ;
else
F_145 ( L_35 , V_359 [ V_354 ] . V_314 ,
type -> V_314 ) ;
F_145 ( L_37 ,
( int ) ( V_7 -> V_93 >> 20 ) , F_155 ( V_7 ) ? L_38 : L_39 ,
V_2 -> V_44 >> 10 , V_2 -> V_45 , V_2 -> V_14 ) ;
return type ;
}
static int F_165 ( struct V_362 * V_363 )
{
const char * V_364 ;
int V_365 , V_40 ;
V_365 = F_166 ( V_363 , L_40 , & V_364 ) ;
if ( V_365 < 0 )
return V_365 ;
for ( V_40 = 0 ; V_40 < F_167 ( V_366 ) ; V_40 ++ )
if ( ! strcasecmp ( V_364 , V_366 [ V_40 ] ) )
return V_40 ;
if ( ! strcasecmp ( V_364 , L_41 ) )
return V_367 ;
return - V_355 ;
}
static int F_168 ( struct V_362 * V_363 )
{
const char * V_364 ;
int V_365 , V_40 ;
V_365 = F_166 ( V_363 , L_42 , & V_364 ) ;
if ( ! V_365 ) {
for ( V_40 = V_368 ; V_40 < F_167 ( V_369 ) ; V_40 ++ )
if ( ! strcasecmp ( V_364 , V_369 [ V_40 ] ) )
return V_40 ;
return - V_355 ;
}
V_365 = F_166 ( V_363 , L_40 , & V_364 ) ;
if ( V_365 < 0 )
return V_365 ;
if ( ! strcasecmp ( V_364 , L_43 ) )
return V_368 ;
else if ( ! strcasecmp ( V_364 , L_41 ) )
return V_370 ;
return - V_355 ;
}
static int F_169 ( struct V_362 * V_363 )
{
int V_17 ;
T_12 V_309 ;
V_17 = F_170 ( V_363 , L_44 , & V_309 ) ;
return V_17 ? V_17 : V_309 ;
}
static int F_171 ( struct V_362 * V_363 )
{
int V_17 ;
T_12 V_309 ;
V_17 = F_170 ( V_363 , L_45 , & V_309 ) ;
return V_17 ? V_17 : V_309 ;
}
static int F_172 ( struct V_362 * V_363 )
{
T_12 V_309 ;
if ( F_170 ( V_363 , L_46 , & V_309 ) )
return 8 ;
switch ( V_309 ) {
case 8 :
case 16 :
return V_309 ;
default:
return - V_119 ;
}
}
static bool F_173 ( struct V_362 * V_363 )
{
return F_174 ( V_363 , L_47 ) ;
}
static int F_175 ( struct V_6 * V_7 )
{
struct V_362 * V_371 = F_176 ( V_7 ) ;
int V_372 , V_373 , V_374 , V_375 ;
if ( ! V_371 )
return 0 ;
if ( F_172 ( V_371 ) == 16 )
V_7 -> V_48 |= V_49 ;
if ( F_173 ( V_371 ) )
V_7 -> V_42 |= V_376 ;
V_372 = F_165 ( V_371 ) ;
V_373 = F_168 ( V_371 ) ;
V_374 = F_171 ( V_371 ) ;
V_375 = F_169 ( V_371 ) ;
if ( ( V_375 >= 0 && ! ( V_374 >= 0 ) ) ||
( ! ( V_375 >= 0 ) && V_374 >= 0 ) ) {
F_131 ( L_48 ) ;
return - V_20 ;
}
if ( V_372 >= 0 )
V_7 -> V_9 . V_62 = V_372 ;
if ( V_373 >= 0 )
V_7 -> V_9 . V_377 = V_373 ;
if ( V_374 >= 0 )
V_7 -> V_9 . V_182 = V_374 ;
if ( V_375 > 0 )
V_7 -> V_9 . V_120 = V_375 ;
return 0 ;
}
int F_177 ( struct V_1 * V_2 , int V_378 ,
struct V_344 * V_379 )
{
int V_40 , V_380 , V_381 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_344 * type ;
int V_17 ;
V_17 = F_175 ( V_7 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_2 -> V_314 && V_2 -> V_382 . V_383 )
V_2 -> V_314 = F_178 ( V_2 -> V_382 . V_383 ) ;
F_133 ( V_7 , V_7 -> V_48 & V_49 ) ;
type = F_162 ( V_2 , V_7 , & V_380 ,
& V_381 , V_379 ) ;
if ( F_179 ( type ) ) {
if ( ! ( V_7 -> V_48 & V_384 ) )
F_121 ( L_49 ) ;
V_7 -> V_123 ( V_2 , - 1 ) ;
return F_180 ( type ) ;
}
V_7 -> V_123 ( V_2 , - 1 ) ;
for ( V_40 = 1 ; V_40 < V_378 ; V_40 ++ ) {
V_7 -> V_123 ( V_2 , V_40 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
V_7 -> V_50 ( V_2 , V_310 , 0x00 , - 1 ) ;
if ( V_380 != V_7 -> V_54 ( V_2 ) ||
V_381 != V_7 -> V_54 ( V_2 ) ) {
V_7 -> V_123 ( V_2 , - 1 ) ;
break;
}
V_7 -> V_123 ( V_2 , - 1 ) ;
}
if ( V_40 > 1 )
F_145 ( L_50 , V_40 ) ;
V_7 -> V_385 = V_40 ;
V_2 -> V_120 = V_40 * V_7 -> V_93 ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_67 ( V_9 -> V_62 != V_367 ) )
return - V_20 ;
switch ( V_9 -> V_377 ) {
case V_368 :
V_9 -> V_162 = V_386 ;
V_9 -> V_164 = V_387 ;
V_9 -> V_208 = F_77 ;
V_9 -> V_207 = F_80 ;
V_9 -> V_241 = F_104 ;
V_9 -> V_161 = F_75 ;
V_9 -> V_227 = F_102 ;
V_9 -> V_224 = F_95 ;
V_9 -> V_253 = F_98 ;
if ( ! V_9 -> V_120 )
V_9 -> V_120 = 256 ;
V_9 -> V_149 = 3 ;
V_9 -> V_182 = 1 ;
return 0 ;
case V_370 :
if ( ! F_182 () ) {
F_183 ( 1 , L_51 ) ;
return - V_20 ;
}
V_9 -> V_162 = V_388 ;
V_9 -> V_164 = V_389 ;
V_9 -> V_208 = F_77 ;
V_9 -> V_207 = F_80 ;
V_9 -> V_241 = F_104 ;
V_9 -> V_161 = F_75 ;
V_9 -> V_227 = F_102 ;
V_9 -> V_224 = F_95 ;
V_9 -> V_253 = F_98 ;
if ( ! V_9 -> V_120 && ( V_2 -> V_14 >= 64 ) ) {
V_9 -> V_120 = 512 ;
V_9 -> V_182 = 4 ;
}
if ( ! V_2 -> V_390 ) {
if ( V_2 -> V_14 < 64 ) {
F_183 ( 1 , L_52 ) ;
return - V_20 ;
}
F_184 ( V_2 , & V_391 ) ;
}
V_9 -> V_149 = 0 ;
V_9 -> V_392 = F_185 ( V_2 ) ;
if ( ! V_9 -> V_392 ) {
F_183 ( 1 , L_53 ) ;
return - V_20 ;
}
return 0 ;
default:
F_183 ( 1 , L_54 ) ;
return - V_20 ;
}
}
static bool F_186 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_393 , V_394 ;
if ( V_9 -> V_120 == 0 || V_7 -> V_300 == 0 )
return true ;
V_393 = ( V_2 -> V_45 * V_9 -> V_182 ) / V_9 -> V_120 ;
V_394 = ( V_2 -> V_45 * V_7 -> V_298 ) / V_7 -> V_300 ;
return V_393 >= V_394 && V_9 -> V_182 >= V_7 -> V_298 ;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_395 * V_396 ;
int V_17 ;
if ( F_67 ( ( V_7 -> V_42 & V_64 ) &&
! ( V_7 -> V_42 & V_376 ) ) )
return - V_20 ;
if ( ! ( V_7 -> V_48 & V_397 ) ) {
V_396 = F_188 ( sizeof( * V_396 ) + V_2 -> V_45
+ V_2 -> V_14 * 3 , V_287 ) ;
if ( ! V_396 )
return - V_288 ;
V_396 -> V_157 = ( T_3 * ) ( V_396 + 1 ) ;
V_396 -> V_159 = V_396 -> V_157 + V_2 -> V_14 ;
V_396 -> V_205 = V_396 -> V_159 + V_2 -> V_14 ;
V_7 -> V_156 = V_396 ;
} else {
if ( ! V_7 -> V_156 )
return - V_288 ;
}
V_7 -> V_146 = V_7 -> V_156 -> V_205 + V_2 -> V_45 ;
if ( ! V_2 -> V_390 &&
! ( V_9 -> V_62 == V_367 && V_9 -> V_377 == V_370 ) ) {
switch ( V_2 -> V_14 ) {
case 8 :
case 16 :
F_184 ( V_2 , & V_398 ) ;
break;
case 64 :
case 128 :
F_184 ( V_2 , & V_391 ) ;
break;
default:
F_183 ( 1 , L_55 ,
V_2 -> V_14 ) ;
V_17 = - V_20 ;
goto V_399;
}
}
if ( ! V_7 -> V_241 )
V_7 -> V_241 = F_109 ;
switch ( V_9 -> V_62 ) {
case V_400 :
if ( ! V_9 -> V_162 || ! V_9 -> V_164 || ! V_9 -> V_183 ) {
F_183 ( 1 , L_56 ) ;
V_17 = - V_20 ;
goto V_399;
}
if ( ! V_9 -> V_208 )
V_9 -> V_208 = F_83 ;
case V_401 :
if ( ! V_9 -> V_208 )
V_9 -> V_208 = F_82 ;
if ( ! V_9 -> V_241 )
V_9 -> V_241 = F_106 ;
if ( ! V_9 -> V_161 )
V_9 -> V_161 = F_75 ;
if ( ! V_9 -> V_227 )
V_9 -> V_227 = F_102 ;
if ( ! V_9 -> V_224 )
V_9 -> V_224 = F_95 ;
if ( ! V_9 -> V_253 )
V_9 -> V_253 = F_98 ;
if ( ! V_9 -> V_207 )
V_9 -> V_207 = F_80 ;
if ( ! V_9 -> V_240 && V_9 -> V_183 && V_9 -> V_162 )
V_9 -> V_240 = F_107 ;
case V_402 :
if ( ( ! V_9 -> V_162 || ! V_9 -> V_164 || ! V_9 -> V_183 ) &&
( ! V_9 -> V_208 ||
V_9 -> V_208 == F_82 ||
! V_9 -> V_241 ||
V_9 -> V_241 == F_106 ) ) {
F_183 ( 1 , L_56 ) ;
V_17 = - V_20 ;
goto V_399;
}
if ( ! V_9 -> V_208 )
V_9 -> V_208 = F_84 ;
if ( ! V_9 -> V_241 )
V_9 -> V_241 = F_108 ;
if ( ! V_9 -> V_161 )
V_9 -> V_161 = F_76 ;
if ( ! V_9 -> V_227 )
V_9 -> V_227 = F_103 ;
if ( ! V_9 -> V_224 )
V_9 -> V_224 = F_96 ;
if ( ! V_9 -> V_253 )
V_9 -> V_253 = F_99 ;
if ( V_2 -> V_45 >= V_9 -> V_120 ) {
if ( ! V_9 -> V_182 ) {
F_183 ( 1 , L_57 ) ;
V_17 = - V_20 ;
goto V_399;
}
break;
}
F_121 ( L_58 ,
V_9 -> V_120 , V_2 -> V_45 ) ;
V_9 -> V_62 = V_367 ;
V_9 -> V_377 = V_368 ;
case V_367 :
V_17 = F_181 ( V_2 ) ;
if ( V_17 ) {
V_17 = - V_20 ;
goto V_399;
}
break;
case V_403 :
F_121 ( L_59 ) ;
V_9 -> V_208 = F_75 ;
V_9 -> V_241 = F_102 ;
V_9 -> V_224 = F_95 ;
V_9 -> V_161 = F_75 ;
V_9 -> V_227 = F_102 ;
V_9 -> V_253 = F_98 ;
V_9 -> V_120 = V_2 -> V_45 ;
V_9 -> V_149 = 0 ;
V_9 -> V_182 = 0 ;
break;
default:
F_183 ( 1 , L_60 , V_9 -> V_62 ) ;
V_17 = - V_20 ;
goto V_399;
}
if ( ! V_9 -> V_223 )
V_9 -> V_223 = V_9 -> V_224 ;
if ( ! V_9 -> V_252 )
V_9 -> V_252 = V_9 -> V_253 ;
V_2 -> V_374 = V_9 -> V_182 ;
V_2 -> V_404 = V_9 -> V_120 ;
V_9 -> V_151 = V_2 -> V_45 / V_9 -> V_120 ;
if ( V_9 -> V_151 * V_9 -> V_120 != V_2 -> V_45 ) {
F_183 ( 1 , L_61 ) ;
V_17 = - V_20 ;
goto V_399;
}
V_9 -> V_13 = V_9 -> V_151 * V_9 -> V_149 ;
V_17 = F_189 ( V_2 ) ;
if ( V_17 < 0 )
V_17 = 0 ;
V_2 -> V_405 = V_17 ;
if ( ! F_186 ( V_2 ) )
F_121 ( L_62 ,
V_2 -> V_314 ) ;
if ( ! ( V_7 -> V_48 & V_239 ) && F_155 ( V_7 ) ) {
switch ( V_9 -> V_151 ) {
case 2 :
V_2 -> V_406 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_406 = 2 ;
break;
}
}
V_7 -> V_407 = V_2 -> V_45 >> V_2 -> V_406 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_204 = - 1 ;
switch ( V_9 -> V_62 ) {
case V_367 :
if ( V_7 -> V_46 > 9 )
V_7 -> V_48 |= V_408 ;
break;
default:
break;
}
V_2 -> type = F_155 ( V_7 ) ? V_409 : V_410 ;
V_2 -> V_411 = ( V_7 -> V_48 & V_412 ) ? V_413 :
V_414 ;
V_2 -> V_415 = F_120 ;
V_2 -> V_416 = NULL ;
V_2 -> V_417 = NULL ;
V_2 -> V_418 = F_94 ;
V_2 -> V_419 = F_117 ;
V_2 -> V_420 = F_116 ;
V_2 -> V_421 = F_101 ;
V_2 -> V_422 = F_118 ;
V_2 -> V_423 = F_123 ;
V_2 -> V_424 = NULL ;
V_2 -> V_425 = NULL ;
V_2 -> V_426 = F_129 ;
V_2 -> V_427 = F_130 ;
V_2 -> V_428 = F_132 ;
V_2 -> V_429 = F_40 ;
V_2 -> V_430 = F_124 ;
V_2 -> V_431 = F_125 ;
V_2 -> V_432 = V_2 -> V_45 ;
if ( ! V_2 -> V_433 )
V_2 -> V_433 = F_190 ( V_2 -> V_374 * 3 , 4 ) ;
if ( V_7 -> V_48 & V_434 )
return 0 ;
return V_7 -> V_275 ( V_2 ) ;
V_399:
if ( ! ( V_7 -> V_48 & V_397 ) )
F_141 ( V_7 -> V_156 ) ;
return V_17 ;
}
int F_191 ( struct V_1 * V_2 , int V_378 )
{
int V_17 ;
V_17 = F_177 ( V_2 , V_378 , NULL ) ;
if ( ! V_17 )
V_17 = F_187 ( V_2 ) ;
return V_17 ;
}
void F_192 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 . V_62 == V_367 &&
V_7 -> V_9 . V_377 == V_370 )
F_193 ( (struct V_435 * ) V_7 -> V_9 . V_392 ) ;
F_194 ( V_2 ) ;
F_141 ( V_7 -> V_70 ) ;
if ( ! ( V_7 -> V_48 & V_397 ) )
F_141 ( V_7 -> V_156 ) ;
if ( V_7 -> V_436 && V_7 -> V_436 -> V_48
& V_437 )
F_141 ( V_7 -> V_436 ) ;
}
