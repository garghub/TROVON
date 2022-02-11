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
static void F_58 ( struct V_6 * V_7 )
{
if ( ! ( V_7 -> V_48 & V_100 ) )
return;
if ( V_7 -> V_101 && V_7 -> V_101 -> V_102 . V_103 . V_104 )
F_57 ( V_7 -> V_101 -> V_102 . V_103 . V_104 / 1000 ) ;
else
F_57 ( 500 ) ;
}
static void F_59 ( struct V_1 * V_2 , unsigned int V_83 ,
int V_84 , int V_85 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_83 == V_51 ) {
V_84 += V_2 -> V_45 ;
V_83 = V_90 ;
}
V_7 -> V_29 ( V_2 , V_83 , V_94 | V_105 | V_31 ) ;
if ( V_84 != - 1 || V_85 != - 1 ) {
int V_86 = V_31 | V_94 | V_106 ;
if ( V_84 != - 1 ) {
if ( V_7 -> V_48 & V_49 &&
! F_55 ( V_83 ) )
V_84 >>= 1 ;
V_7 -> V_29 ( V_2 , V_84 , V_86 ) ;
V_86 &= ~ V_31 ;
if ( ! F_55 ( V_83 ) )
V_7 -> V_29 ( V_2 , V_84 >> 8 , V_86 ) ;
}
if ( V_85 != - 1 ) {
V_7 -> V_29 ( V_2 , V_85 , V_86 ) ;
V_7 -> V_29 ( V_2 , V_85 >> 8 ,
V_94 | V_106 ) ;
if ( V_7 -> V_93 > ( 128 << 20 ) )
V_7 -> V_29 ( V_2 , V_85 >> 16 ,
V_94 | V_106 ) ;
}
}
V_7 -> V_29 ( V_2 , V_30 , V_94 | V_31 ) ;
switch ( V_83 ) {
case V_107 :
case V_95 :
case V_96 :
case V_97 :
case V_88 :
case V_74 :
return;
case V_108 :
F_58 ( V_7 ) ;
return;
case V_98 :
if ( V_7 -> V_79 )
break;
F_56 ( V_7 -> V_99 ) ;
V_7 -> V_29 ( V_2 , V_74 ,
V_94 | V_105 | V_31 ) ;
V_7 -> V_29 ( V_2 , V_30 ,
V_94 | V_31 ) ;
F_53 ( V_2 , 250 ) ;
return;
case V_109 :
V_7 -> V_29 ( V_2 , V_110 ,
V_94 | V_105 | V_31 ) ;
V_7 -> V_29 ( V_2 , V_30 ,
V_94 | V_31 ) ;
F_58 ( V_7 ) ;
return;
case V_90 :
V_7 -> V_29 ( V_2 , V_111 ,
V_94 | V_105 | V_31 ) ;
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
static void F_60 ( struct V_6 * V_7 ,
struct V_1 * V_2 , int V_112 )
{
V_7 -> V_21 -> V_23 = V_7 ;
V_7 -> V_24 = V_112 ;
}
static int
F_37 ( struct V_1 * V_2 , int V_112 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_6 * V_22 = & V_7 -> V_21 -> V_22 ;
T_7 * V_26 = & V_7 -> V_21 -> V_26 ;
F_61 ( V_113 , V_114 ) ;
V_115:
F_9 ( V_22 ) ;
if ( ! V_7 -> V_21 -> V_23 )
V_7 -> V_21 -> V_23 = V_7 ;
if ( V_7 -> V_21 -> V_23 == V_7 && V_7 -> V_24 == V_25 ) {
V_7 -> V_24 = V_112 ;
F_11 ( V_22 ) ;
return 0 ;
}
if ( V_112 == V_116 ) {
if ( V_7 -> V_21 -> V_23 -> V_24 == V_116 ) {
V_7 -> V_24 = V_116 ;
F_11 ( V_22 ) ;
return 0 ;
}
}
F_62 ( V_117 ) ;
F_63 ( V_26 , & V_113 ) ;
F_11 ( V_22 ) ;
F_64 () ;
F_65 ( V_26 , & V_113 ) ;
goto V_115;
}
static void F_66 ( struct V_1 * V_2 , struct V_6 * V_7 ,
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
static int F_67 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_118 ;
unsigned long V_78 = 400 ;
F_57 ( 100 ) ;
V_7 -> V_50 ( V_2 , V_74 , - 1 , - 1 ) ;
if ( F_48 () || V_80 )
F_66 ( V_2 , V_7 , V_78 ) ;
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
V_118 = ( int ) V_7 -> V_54 ( V_2 ) ;
F_68 ( ! ( V_118 & V_82 ) ) ;
return V_118 ;
}
static int F_69 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_70 ( V_7 ) ;
const struct V_119 * V_120 ;
int V_17 ;
if ( ! V_7 -> V_121 )
return 0 ;
V_120 = F_71 () ;
V_17 = V_7 -> V_121 ( V_2 , V_120 , false ) ;
if ( V_17 )
F_72 ( L_4 ) ;
return V_17 ;
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_70 ( V_7 ) ;
int V_17 ;
if ( ! V_7 -> V_121 || ! V_7 -> V_101 )
return 0 ;
if ( V_7 -> V_122 ) {
T_8 V_123 [ V_124 ] = {
V_7 -> V_125 ,
} ;
V_17 = V_7 -> V_126 ( V_2 , V_7 ,
V_127 ,
V_123 ) ;
if ( V_17 )
goto V_128;
}
V_17 = V_7 -> V_121 ( V_2 , V_7 -> V_101 , false ) ;
V_128:
return V_17 ;
}
static int F_74 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_70 ( V_7 ) ;
int V_129 , V_62 , V_17 ;
if ( ! V_7 -> V_121 )
return 0 ;
V_129 = F_75 ( V_7 ) ;
if ( V_129 == V_130 ) {
if ( ! V_7 -> V_125 )
return 0 ;
V_129 = F_76 ( V_7 -> V_125 , 0 ) ;
}
V_7 -> V_101 = F_77 ( sizeof( * V_7 -> V_101 ) ,
V_131 ) ;
if ( ! V_7 -> V_101 )
return - V_132 ;
for ( V_62 = F_78 ( V_129 ) - 1 ; V_62 >= 0 ; V_62 -- ) {
V_17 = F_79 ( V_7 , V_7 -> V_101 ,
V_133 , V_62 ) ;
if ( V_17 )
continue;
V_17 = V_7 -> V_121 ( V_2 , V_7 -> V_101 ,
true ) ;
if ( ! V_17 ) {
V_7 -> V_125 = V_62 ;
break;
}
}
return 0 ;
}
static void F_80 ( struct V_6 * V_7 )
{
F_81 ( V_7 -> V_101 ) ;
}
int F_82 ( struct V_6 * V_7 , int V_28 )
{
struct V_1 * V_2 = F_70 ( V_7 ) ;
int V_17 ;
V_17 = F_69 ( V_7 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_134 ( V_2 , V_28 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
V_7 -> V_134 ( V_2 , - 1 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
V_17 = F_73 ( V_7 ) ;
V_7 -> V_134 ( V_2 , - 1 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_15 ,
T_2 V_16 , int V_135 )
{
int V_17 = 0 ;
int V_118 , V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_38 = V_15 >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_136 , - 1 , V_38 & V_7 -> V_47 ) ;
V_38 = ( V_15 + V_16 ) >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_137 , - 1 ,
( V_38 | V_135 ) & V_7 -> V_47 ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
if ( V_118 & V_139 ) {
F_7 ( L_5 ,
V_19 , V_118 ) ;
V_17 = - V_140 ;
}
return V_17 ;
}
int F_84 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 )
{
int V_17 = 0 ;
int V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_6 ,
V_19 , ( unsigned long long ) V_15 , V_16 ) ;
if ( F_6 ( V_2 , V_15 , V_16 ) )
return - V_20 ;
if ( V_15 + V_16 == V_2 -> V_141 )
V_16 -= V_2 -> V_44 ;
F_37 ( V_2 , V_142 ) ;
V_28 = V_15 >> V_7 -> V_143 ;
F_82 ( V_7 , V_28 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_7 ,
V_19 ) ;
V_17 = - V_140 ;
goto V_144;
}
V_17 = F_83 ( V_2 , V_15 , V_16 , 0 ) ;
V_144:
V_7 -> V_134 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
int F_85 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 )
{
int V_17 = 0 ;
int V_28 , V_118 , V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_6 ,
V_19 , ( unsigned long long ) V_15 , V_16 ) ;
if ( F_6 ( V_2 , V_15 , V_16 ) )
return - V_20 ;
F_37 ( V_2 , V_145 ) ;
V_28 = V_15 >> V_7 -> V_143 ;
F_82 ( V_7 , V_28 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_7 ,
V_19 ) ;
V_118 = V_146 ;
V_17 = - V_140 ;
goto V_144;
}
V_38 = V_15 >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_147 , - 1 , V_38 & V_7 -> V_47 ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
if ( V_118 & V_139 ) {
F_7 ( L_5 ,
V_19 , V_118 ) ;
V_17 = - V_140 ;
goto V_144;
}
V_17 = F_83 ( V_2 , V_15 , V_16 , 0x1 ) ;
V_144:
V_7 -> V_134 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_86 ( void * V_35 , int V_16 , int V_148 )
{
const unsigned char * V_149 = V_35 ;
int V_150 = 0 ;
int V_151 ;
for (; V_16 && ( ( V_152 ) V_149 ) % sizeof( long ) ;
V_16 -- , V_149 ++ ) {
V_151 = F_32 ( * V_149 ) ;
V_150 += V_153 - V_151 ;
if ( F_87 ( V_150 > V_148 ) )
return - V_154 ;
}
for (; V_16 >= sizeof( long ) ;
V_16 -= sizeof( long ) , V_149 += sizeof( long ) ) {
V_151 = F_88 ( * ( ( unsigned long * ) V_149 ) ) ;
V_150 += V_155 - V_151 ;
if ( F_87 ( V_150 > V_148 ) )
return - V_154 ;
}
for (; V_16 > 0 ; V_16 -- , V_149 ++ ) {
V_151 = F_32 ( * V_149 ) ;
V_150 += V_153 - V_151 ;
if ( F_87 ( V_150 > V_148 ) )
return - V_154 ;
}
return V_150 ;
}
int F_89 ( void * V_156 , int V_157 ,
void * V_9 , int V_158 ,
void * V_159 , int V_160 ,
int V_148 )
{
int V_161 = 0 , V_162 = 0 , V_163 = 0 ;
V_161 = F_86 ( V_156 , V_157 ,
V_148 ) ;
if ( V_161 < 0 )
return V_161 ;
V_148 -= V_161 ;
V_162 = F_86 ( V_9 , V_158 , V_148 ) ;
if ( V_162 < 0 )
return V_162 ;
V_148 -= V_162 ;
V_163 = F_86 ( V_159 , V_160 ,
V_148 ) ;
if ( V_163 < 0 )
return V_163 ;
if ( V_161 )
memset ( V_156 , 0xff , V_157 ) ;
if ( V_162 )
memset ( V_9 , 0xff , V_158 ) ;
if ( V_163 )
memset ( V_159 , 0xff , V_160 ) ;
return V_161 + V_162 + V_163 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_164 , int V_38 )
{
V_7 -> V_165 ( V_2 , V_35 , V_2 -> V_45 ) ;
if ( V_164 )
V_7 -> V_165 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_35 ,
int V_164 , int V_38 )
{
int V_167 = V_7 -> V_9 . V_141 ;
int V_168 = V_7 -> V_9 . V_169 ;
T_3 * V_170 = V_7 -> V_166 ;
int V_171 , V_141 ;
for ( V_171 = V_7 -> V_9 . V_171 ; V_171 > 0 ; V_171 -- ) {
V_7 -> V_165 ( V_2 , V_35 , V_167 ) ;
V_35 += V_167 ;
if ( V_7 -> V_9 . V_172 ) {
V_7 -> V_165 ( V_2 , V_170 , V_7 -> V_9 . V_172 ) ;
V_170 += V_7 -> V_9 . V_172 ;
}
V_7 -> V_165 ( V_2 , V_170 , V_168 ) ;
V_170 += V_168 ;
if ( V_7 -> V_9 . V_173 ) {
V_7 -> V_165 ( V_2 , V_170 , V_7 -> V_9 . V_173 ) ;
V_170 += V_7 -> V_9 . V_173 ;
}
}
V_141 = V_2 -> V_14 - ( V_170 - V_7 -> V_166 ) ;
if ( V_141 )
V_7 -> V_165 ( V_2 , V_170 , V_141 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_164 , int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 , V_17 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
T_3 * V_37 = V_35 ;
T_3 * V_175 = V_7 -> V_176 -> V_177 ;
T_3 * V_178 = V_7 -> V_176 -> V_179 ;
unsigned int V_180 = 0 ;
V_7 -> V_9 . V_181 ( V_2 , V_7 , V_35 , 1 , V_38 ) ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 )
V_7 -> V_9 . V_182 ( V_2 , V_37 , & V_175 [ V_40 ] ) ;
V_17 = F_93 ( V_2 , V_178 , V_7 -> V_166 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_174 = V_7 -> V_9 . V_171 ;
V_37 = V_35 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
int V_183 ;
V_183 = V_7 -> V_9 . V_184 ( V_2 , V_37 , & V_178 [ V_40 ] , & V_175 [ V_40 ] ) ;
if ( V_183 < 0 ) {
V_2 -> V_71 . V_185 ++ ;
} else {
V_2 -> V_71 . V_186 += V_183 ;
V_180 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_180 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_187 , T_9 V_188 , T_3 * V_189 ,
int V_38 )
{
int V_190 , V_191 , V_192 , V_17 ;
T_3 * V_37 ;
int V_193 , V_40 , V_194 = 0 ;
int V_195 , V_196 , V_197 , V_198 ;
int V_199 = ( V_7 -> V_48 & V_49 ) ? 2 : 1 ;
int V_200 , V_3 = 0 ;
unsigned int V_180 = 0 ;
struct V_4 V_5 = { } ;
V_190 = V_187 / V_7 -> V_9 . V_141 ;
V_191 = ( V_187 + V_188 - 1 ) / V_7 -> V_9 . V_141 ;
V_192 = V_191 - V_190 + 1 ;
V_200 = V_190 * V_7 -> V_9 . V_169 ;
V_195 = V_192 * V_7 -> V_9 . V_141 ;
V_196 = V_192 * V_7 -> V_9 . V_169 ;
V_193 = V_190 * V_7 -> V_9 . V_141 ;
if ( V_193 != 0 )
V_7 -> V_50 ( V_2 , V_109 , V_193 , - 1 ) ;
V_37 = V_189 + V_193 ;
V_7 -> V_165 ( V_2 , V_37 , V_195 ) ;
for ( V_40 = 0 ; V_40 < V_196 ; V_40 += V_7 -> V_9 . V_169 , V_37 += V_7 -> V_9 . V_141 )
V_7 -> V_9 . V_182 ( V_2 , V_37 , & V_7 -> V_176 -> V_177 [ V_40 ] ) ;
V_17 = F_96 ( V_2 , V_200 , & V_3 , & V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_5 . V_12 < V_196 )
V_194 = 1 ;
if ( V_194 ) {
V_7 -> V_50 ( V_2 , V_109 , V_2 -> V_45 , - 1 ) ;
V_7 -> V_165 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
} else {
V_198 = V_5 . V_11 & ~ ( V_199 - 1 ) ;
V_197 = V_196 ;
if ( V_5 . V_11 & ( V_199 - 1 ) )
V_197 ++ ;
if ( ( V_5 . V_11 + ( V_192 * V_7 -> V_9 . V_169 ) ) &
( V_199 - 1 ) )
V_197 ++ ;
V_7 -> V_50 ( V_2 , V_109 ,
V_2 -> V_45 + V_198 , - 1 ) ;
V_7 -> V_165 ( V_2 , & V_7 -> V_166 [ V_198 ] , V_197 ) ;
}
V_17 = F_93 ( V_2 , V_7 -> V_176 -> V_179 ,
V_7 -> V_166 , V_200 , V_196 ) ;
if ( V_17 )
return V_17 ;
V_37 = V_189 + V_193 ;
for ( V_40 = 0 ; V_40 < V_196 ; V_40 += V_7 -> V_9 . V_169 , V_37 += V_7 -> V_9 . V_141 ) {
int V_183 ;
V_183 = V_7 -> V_9 . V_184 ( V_2 , V_37 ,
& V_7 -> V_176 -> V_179 [ V_40 ] , & V_7 -> V_176 -> V_177 [ V_40 ] ) ;
if ( V_183 == - V_154 &&
( V_7 -> V_9 . V_48 & V_201 ) ) {
V_183 = F_89 ( V_37 , V_7 -> V_9 . V_141 ,
& V_7 -> V_176 -> V_179 [ V_40 ] ,
V_7 -> V_9 . V_169 ,
NULL , 0 ,
V_7 -> V_9 . V_202 ) ;
}
if ( V_183 < 0 ) {
V_2 -> V_71 . V_185 ++ ;
} else {
V_2 -> V_71 . V_186 += V_183 ;
V_180 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_180 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_164 , int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 , V_17 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
T_3 * V_37 = V_35 ;
T_3 * V_175 = V_7 -> V_176 -> V_177 ;
T_3 * V_178 = V_7 -> V_176 -> V_179 ;
unsigned int V_180 = 0 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
V_7 -> V_9 . V_203 ( V_2 , V_204 ) ;
V_7 -> V_165 ( V_2 , V_37 , V_167 ) ;
V_7 -> V_9 . V_182 ( V_2 , V_37 , & V_175 [ V_40 ] ) ;
}
V_7 -> V_165 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
V_17 = F_93 ( V_2 , V_178 , V_7 -> V_166 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_174 = V_7 -> V_9 . V_171 ;
V_37 = V_35 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
int V_183 ;
V_183 = V_7 -> V_9 . V_184 ( V_2 , V_37 , & V_178 [ V_40 ] , & V_175 [ V_40 ] ) ;
if ( V_183 == - V_154 &&
( V_7 -> V_9 . V_48 & V_201 ) ) {
V_183 = F_89 ( V_37 , V_167 ,
& V_178 [ V_40 ] , V_168 ,
NULL , 0 ,
V_7 -> V_9 . V_202 ) ;
}
if ( V_183 < 0 ) {
V_2 -> V_71 . V_185 ++ ;
} else {
V_2 -> V_71 . V_186 += V_183 ;
V_180 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_180 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_35 , int V_164 , int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 , V_17 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
T_3 * V_37 = V_35 ;
T_3 * V_178 = V_7 -> V_176 -> V_179 ;
T_3 * V_175 = V_7 -> V_176 -> V_177 ;
unsigned int V_180 = 0 ;
V_7 -> V_50 ( V_2 , V_51 , 0 , V_38 ) ;
V_7 -> V_165 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
V_7 -> V_50 ( V_2 , V_90 , 0 , V_38 ) ;
V_17 = F_93 ( V_2 , V_178 , V_7 -> V_166 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
int V_183 ;
V_7 -> V_9 . V_203 ( V_2 , V_204 ) ;
V_7 -> V_165 ( V_2 , V_37 , V_167 ) ;
V_7 -> V_9 . V_182 ( V_2 , V_37 , & V_175 [ V_40 ] ) ;
V_183 = V_7 -> V_9 . V_184 ( V_2 , V_37 , & V_178 [ V_40 ] , NULL ) ;
if ( V_183 == - V_154 &&
( V_7 -> V_9 . V_48 & V_201 ) ) {
V_183 = F_89 ( V_37 , V_167 ,
& V_178 [ V_40 ] , V_168 ,
NULL , 0 ,
V_7 -> V_9 . V_202 ) ;
}
if ( V_183 < 0 ) {
V_2 -> V_71 . V_185 ++ ;
} else {
V_2 -> V_71 . V_186 += V_183 ;
V_180 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_180 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_164 , int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
int V_205 = V_168 + V_7 -> V_9 . V_172 + V_7 -> V_9 . V_173 ;
T_3 * V_37 = V_35 ;
T_3 * V_170 = V_7 -> V_166 ;
unsigned int V_180 = 0 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
int V_183 ;
V_7 -> V_9 . V_203 ( V_2 , V_204 ) ;
V_7 -> V_165 ( V_2 , V_37 , V_167 ) ;
if ( V_7 -> V_9 . V_172 ) {
V_7 -> V_165 ( V_2 , V_170 , V_7 -> V_9 . V_172 ) ;
V_170 += V_7 -> V_9 . V_172 ;
}
V_7 -> V_9 . V_203 ( V_2 , V_206 ) ;
V_7 -> V_165 ( V_2 , V_170 , V_168 ) ;
V_183 = V_7 -> V_9 . V_184 ( V_2 , V_37 , V_170 , NULL ) ;
V_170 += V_168 ;
if ( V_7 -> V_9 . V_173 ) {
V_7 -> V_165 ( V_2 , V_170 , V_7 -> V_9 . V_173 ) ;
V_170 += V_7 -> V_9 . V_173 ;
}
if ( V_183 == - V_154 &&
( V_7 -> V_9 . V_48 & V_201 ) ) {
V_183 = F_89 ( V_37 , V_7 -> V_9 . V_141 ,
V_170 - V_205 ,
V_205 ,
NULL , 0 ,
V_7 -> V_9 . V_202 ) ;
}
if ( V_183 < 0 ) {
V_2 -> V_71 . V_185 ++ ;
} else {
V_2 -> V_71 . V_186 += V_183 ;
V_180 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
V_40 = V_2 -> V_14 - ( V_170 - V_7 -> V_166 ) ;
if ( V_40 )
V_7 -> V_165 ( V_2 , V_170 , V_40 ) ;
return V_180 ;
}
static T_3 * F_100 ( struct V_1 * V_2 , T_3 * V_170 ,
struct V_57 * V_58 , T_10 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_207 :
memcpy ( V_170 , V_7 -> V_166 + V_58 -> V_60 , V_16 ) ;
return V_170 + V_16 ;
case V_208 :
V_17 = F_101 ( V_2 , V_170 , V_7 -> V_166 ,
V_58 -> V_60 , V_16 ) ;
F_102 ( V_17 ) ;
return V_170 + V_16 ;
default:
F_19 () ;
}
return NULL ;
}
static int F_103 ( struct V_1 * V_2 , int V_209 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_8 , V_209 ) ;
if ( V_209 >= V_7 -> V_210 )
return - V_20 ;
if ( ! V_7 -> V_211 )
return - V_212 ;
return V_7 -> V_211 ( V_2 , V_209 ) ;
}
static int F_104 ( struct V_1 * V_2 , T_1 V_213 ,
struct V_57 * V_58 )
{
int V_28 , V_38 , V_214 , V_215 , V_169 , V_216 , V_164 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 = 0 ;
T_9 V_188 = V_58 -> V_16 ;
T_9 V_217 = V_58 -> V_61 ;
T_9 V_218 = F_105 ( V_2 , V_58 ) ;
T_3 * V_189 , * V_170 , * V_35 ;
int V_219 ;
unsigned int V_180 = 0 ;
int V_209 = 0 ;
bool V_220 = false ;
V_28 = ( int ) ( V_213 >> V_7 -> V_143 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
V_214 = ( int ) ( V_213 >> V_7 -> V_46 ) ;
V_38 = V_214 & V_7 -> V_47 ;
V_215 = ( int ) ( V_213 & ( V_2 -> V_45 - 1 ) ) ;
V_35 = V_58 -> V_221 ;
V_170 = V_58 -> V_59 ;
V_164 = V_170 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_222 = V_2 -> V_71 . V_185 ;
V_169 = F_106 ( V_2 -> V_45 - V_215 , V_188 ) ;
V_216 = ( V_169 == V_2 -> V_45 ) ;
if ( ! V_216 )
V_219 = 1 ;
else if ( V_7 -> V_48 & V_223 )
V_219 = ! F_107 ( V_35 ) ;
else
V_219 = 0 ;
if ( V_214 != V_7 -> V_224 || V_170 ) {
V_189 = V_219 ? V_7 -> V_176 -> V_225 : V_35 ;
if ( V_219 && V_216 )
F_7 ( L_9 ,
V_19 , V_35 ) ;
V_226:
if ( F_108 ( & V_7 -> V_9 ) )
V_7 -> V_50 ( V_2 , V_90 , 0x00 , V_38 ) ;
if ( F_87 ( V_58 -> V_62 == V_207 ) )
V_17 = V_7 -> V_9 . V_181 ( V_2 , V_7 , V_189 ,
V_164 ,
V_38 ) ;
else if ( ! V_216 && F_109 ( V_7 ) &&
! V_170 )
V_17 = V_7 -> V_9 . V_227 ( V_2 , V_7 ,
V_215 , V_169 , V_189 ,
V_38 ) ;
else
V_17 = V_7 -> V_9 . V_228 ( V_2 , V_7 , V_189 ,
V_164 , V_38 ) ;
if ( V_17 < 0 ) {
if ( V_219 )
V_7 -> V_224 = - 1 ;
break;
}
V_180 = F_94 (unsigned int, max_bitflips, ret) ;
if ( V_219 ) {
if ( ! F_109 ( V_7 ) && ! V_170 &&
! ( V_2 -> V_71 . V_185 - V_222 ) &&
( V_58 -> V_62 != V_207 ) ) {
V_7 -> V_224 = V_214 ;
V_7 -> V_229 = V_17 ;
} else {
V_7 -> V_224 = - 1 ;
}
memcpy ( V_35 , V_7 -> V_176 -> V_225 + V_215 , V_169 ) ;
}
if ( F_87 ( V_170 ) ) {
int V_230 = F_106 ( V_217 , V_218 ) ;
if ( V_230 ) {
V_170 = F_100 ( V_2 ,
V_170 , V_58 , V_230 ) ;
V_217 -= V_230 ;
}
}
if ( V_7 -> V_48 & V_231 ) {
if ( ! V_7 -> V_79 )
F_56 ( V_7 -> V_99 ) ;
else
F_47 ( V_2 ) ;
}
if ( V_2 -> V_71 . V_185 - V_222 ) {
if ( V_209 + 1 < V_7 -> V_210 ) {
V_209 ++ ;
V_17 = F_103 ( V_2 ,
V_209 ) ;
if ( V_17 < 0 )
break;
V_2 -> V_71 . V_185 = V_222 ;
goto V_226;
} else {
V_220 = true ;
}
}
V_35 += V_169 ;
} else {
memcpy ( V_35 , V_7 -> V_176 -> V_225 + V_215 , V_169 ) ;
V_35 += V_169 ;
V_180 = F_94 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_188 -= V_169 ;
if ( V_209 ) {
V_17 = F_103 ( V_2 , 0 ) ;
if ( V_17 < 0 )
break;
V_209 = 0 ;
}
if ( ! V_188 )
break;
V_215 = 0 ;
V_214 ++ ;
V_38 = V_214 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_134 ( V_2 , - 1 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
}
}
V_7 -> V_134 ( V_2 , - 1 ) ;
V_58 -> V_232 = V_58 -> V_16 - ( T_10 ) V_188 ;
if ( V_170 )
V_58 -> V_233 = V_58 -> V_61 - V_217 ;
if ( V_17 < 0 )
return V_17 ;
if ( V_220 )
return - V_154 ;
return V_180 ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_213 , T_10 V_16 ,
T_10 * V_232 , T_3 * V_35 )
{
struct V_57 V_58 ;
int V_17 ;
F_37 ( V_2 , V_234 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_221 = V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_104 ( V_2 , V_213 , & V_58 ) ;
* V_232 = V_58 . V_232 ;
F_8 ( V_2 ) ;
return V_17 ;
}
int F_111 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_38 )
{
V_7 -> V_50 ( V_2 , V_51 , 0 , V_38 ) ;
V_7 -> V_165 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_38 )
{
int V_12 = V_2 -> V_14 ;
int V_235 = V_7 -> V_9 . V_169 + V_7 -> V_9 . V_172 + V_7 -> V_9 . V_173 ;
int V_167 = V_7 -> V_9 . V_141 ;
T_3 * V_189 = V_7 -> V_166 ;
int V_40 , V_230 , V_236 = 0 , V_237 ;
V_7 -> V_50 ( V_2 , V_90 , V_7 -> V_9 . V_141 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_7 -> V_9 . V_171 ; V_40 ++ ) {
if ( V_236 ) {
V_237 = V_167 + V_40 * ( V_167 + V_235 ) ;
if ( V_2 -> V_45 > 512 )
V_7 -> V_50 ( V_2 , V_109 , V_237 , - 1 ) ;
else
V_7 -> V_50 ( V_2 , V_90 , V_237 , V_38 ) ;
} else
V_236 = 1 ;
V_230 = F_113 ( int , V_12 , V_235 ) ;
V_7 -> V_165 ( V_2 , V_189 , V_230 ) ;
V_189 += V_230 ;
V_12 -= V_230 ;
}
if ( V_12 > 0 )
V_7 -> V_165 ( V_2 , V_189 , V_12 ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_38 )
{
int V_118 = 0 ;
const T_3 * V_35 = V_7 -> V_166 ;
int V_12 = V_2 -> V_14 ;
V_7 -> V_50 ( V_2 , V_88 , V_2 -> V_45 , V_38 ) ;
V_7 -> V_33 ( V_2 , V_35 , V_12 ) ;
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
return V_118 & V_139 ? - V_140 : 0 ;
}
int F_115 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_38 )
{
int V_235 = V_7 -> V_9 . V_169 + V_7 -> V_9 . V_172 + V_7 -> V_9 . V_173 ;
int V_167 = V_7 -> V_9 . V_141 , V_12 = V_2 -> V_14 ;
int V_40 , V_16 , V_237 , V_118 = 0 , V_238 = 0 , V_171 = V_7 -> V_9 . V_171 ;
const T_3 * V_189 = V_7 -> V_166 ;
if ( ! V_7 -> V_9 . V_172 && ! V_7 -> V_9 . V_173 ) {
V_237 = V_171 * ( V_167 + V_235 ) ;
V_171 = 0 ;
} else
V_237 = V_167 ;
V_7 -> V_50 ( V_2 , V_88 , V_237 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_171 ; V_40 ++ ) {
if ( V_238 ) {
if ( V_2 -> V_45 <= 512 ) {
T_9 V_239 = 0xFFFFFFFF ;
V_16 = V_167 ;
while ( V_16 > 0 ) {
int V_240 = F_113 ( int , V_16 , 4 ) ;
V_7 -> V_33 ( V_2 , ( T_3 * ) & V_239 ,
V_240 ) ;
V_16 -= V_240 ;
}
} else {
V_237 = V_167 + V_40 * ( V_167 + V_235 ) ;
V_7 -> V_50 ( V_2 , V_108 , V_237 , - 1 ) ;
}
} else
V_238 = 1 ;
V_16 = F_113 ( int , V_12 , V_235 ) ;
V_7 -> V_33 ( V_2 , V_189 , V_16 ) ;
V_189 += V_16 ;
V_12 -= V_16 ;
}
if ( V_12 > 0 )
V_7 -> V_33 ( V_2 , V_189 , V_12 ) ;
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
return V_118 & V_139 ? - V_140 : 0 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_213 ,
struct V_57 * V_58 )
{
int V_38 , V_214 , V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_241 V_242 ;
int V_188 = V_58 -> V_61 ;
int V_16 ;
T_3 * V_35 = V_58 -> V_59 ;
int V_17 = 0 ;
F_7 ( L_10 ,
V_19 , ( unsigned long long ) V_213 , V_188 ) ;
V_242 = V_2 -> V_71 ;
V_16 = F_105 ( V_2 , V_58 ) ;
if ( F_87 ( V_58 -> V_60 >= V_16 ) ) {
F_7 ( L_11 ,
V_19 ) ;
return - V_20 ;
}
if ( F_87 ( V_213 >= V_2 -> V_141 ||
V_58 -> V_60 + V_188 > ( ( V_2 -> V_141 >> V_7 -> V_46 ) -
( V_213 >> V_7 -> V_46 ) ) * V_16 ) ) {
F_7 ( L_12 ,
V_19 ) ;
return - V_20 ;
}
V_28 = ( int ) ( V_213 >> V_7 -> V_143 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
V_214 = ( int ) ( V_213 >> V_7 -> V_46 ) ;
V_38 = V_214 & V_7 -> V_47 ;
while ( 1 ) {
if ( V_58 -> V_62 == V_207 )
V_17 = V_7 -> V_9 . V_243 ( V_2 , V_7 , V_38 ) ;
else
V_17 = V_7 -> V_9 . V_244 ( V_2 , V_7 , V_38 ) ;
if ( V_17 < 0 )
break;
V_16 = F_106 ( V_16 , V_188 ) ;
V_35 = F_100 ( V_2 , V_35 , V_58 , V_16 ) ;
if ( V_7 -> V_48 & V_231 ) {
if ( ! V_7 -> V_79 )
F_56 ( V_7 -> V_99 ) ;
else
F_47 ( V_2 ) ;
}
V_188 -= V_16 ;
if ( ! V_188 )
break;
V_214 ++ ;
V_38 = V_214 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_134 ( V_2 , - 1 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
}
}
V_7 -> V_134 ( V_2 , - 1 ) ;
V_58 -> V_233 = V_58 -> V_61 - V_188 ;
if ( V_17 < 0 )
return V_17 ;
if ( V_2 -> V_71 . V_185 - V_242 . V_185 )
return - V_154 ;
return V_2 -> V_71 . V_186 - V_242 . V_186 ? - V_245 : 0 ;
}
static int F_117 ( struct V_1 * V_2 , T_1 V_213 ,
struct V_57 * V_58 )
{
int V_17 ;
V_58 -> V_232 = 0 ;
if ( V_58 -> V_221 && ( V_213 + V_58 -> V_16 ) > V_2 -> V_141 ) {
F_7 ( L_12 ,
V_19 ) ;
return - V_20 ;
}
if ( V_58 -> V_62 != V_63 &&
V_58 -> V_62 != V_208 &&
V_58 -> V_62 != V_207 )
return - V_246 ;
F_37 ( V_2 , V_234 ) ;
if ( ! V_58 -> V_221 )
V_17 = F_116 ( V_2 , V_213 , V_58 ) ;
else
V_17 = F_104 ( V_2 , V_213 , V_58 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_164 , int V_38 )
{
V_7 -> V_33 ( V_2 , V_35 , V_2 -> V_45 ) ;
if ( V_164 )
V_7 -> V_33 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_35 , int V_164 ,
int V_38 )
{
int V_167 = V_7 -> V_9 . V_141 ;
int V_168 = V_7 -> V_9 . V_169 ;
T_3 * V_170 = V_7 -> V_166 ;
int V_171 , V_141 ;
for ( V_171 = V_7 -> V_9 . V_171 ; V_171 > 0 ; V_171 -- ) {
V_7 -> V_33 ( V_2 , V_35 , V_167 ) ;
V_35 += V_167 ;
if ( V_7 -> V_9 . V_172 ) {
V_7 -> V_33 ( V_2 , V_170 , V_7 -> V_9 . V_172 ) ;
V_170 += V_7 -> V_9 . V_172 ;
}
V_7 -> V_33 ( V_2 , V_170 , V_168 ) ;
V_170 += V_168 ;
if ( V_7 -> V_9 . V_173 ) {
V_7 -> V_33 ( V_2 , V_170 , V_7 -> V_9 . V_173 ) ;
V_170 += V_7 -> V_9 . V_173 ;
}
}
V_141 = V_2 -> V_14 - ( V_170 - V_7 -> V_166 ) ;
if ( V_141 )
V_7 -> V_33 ( V_2 , V_170 , V_141 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_164 ,
int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 , V_17 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
T_3 * V_175 = V_7 -> V_176 -> V_177 ;
const T_3 * V_37 = V_35 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 )
V_7 -> V_9 . V_182 ( V_2 , V_37 , & V_175 [ V_40 ] ) ;
V_17 = F_121 ( V_2 , V_175 , V_7 -> V_166 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
return V_7 -> V_9 . V_247 ( V_2 , V_7 , V_35 , 1 , V_38 ) ;
}
static int F_122 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_164 ,
int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 , V_17 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
T_3 * V_175 = V_7 -> V_176 -> V_177 ;
const T_3 * V_37 = V_35 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
V_7 -> V_9 . V_203 ( V_2 , V_248 ) ;
V_7 -> V_33 ( V_2 , V_37 , V_167 ) ;
V_7 -> V_9 . V_182 ( V_2 , V_37 , & V_175 [ V_40 ] ) ;
}
V_17 = F_121 ( V_2 , V_175 , V_7 -> V_166 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_33 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_9 V_11 ,
T_9 V_249 , const T_3 * V_35 ,
int V_164 , int V_38 )
{
T_3 * V_250 = V_7 -> V_166 ;
T_3 * V_175 = V_7 -> V_176 -> V_177 ;
int V_251 = V_7 -> V_9 . V_141 ;
int V_252 = V_7 -> V_9 . V_169 ;
int V_253 = V_7 -> V_9 . V_171 ;
T_9 V_190 = V_11 / V_251 ;
T_9 V_191 = ( V_11 + V_249 - 1 ) / V_251 ;
int V_254 = V_2 -> V_14 / V_253 ;
int V_255 , V_17 ;
for ( V_255 = 0 ; V_255 < V_253 ; V_255 ++ ) {
V_7 -> V_9 . V_203 ( V_2 , V_248 ) ;
V_7 -> V_33 ( V_2 , V_35 , V_251 ) ;
if ( ( V_255 < V_190 ) || ( V_255 > V_191 ) )
memset ( V_175 , 0xff , V_252 ) ;
else
V_7 -> V_9 . V_182 ( V_2 , V_35 , V_175 ) ;
if ( ! V_164 || ( V_255 < V_190 ) || ( V_255 > V_191 ) )
memset ( V_250 , 0xff , V_254 ) ;
V_35 += V_251 ;
V_175 += V_252 ;
V_250 += V_254 ;
}
V_175 = V_7 -> V_176 -> V_177 ;
V_17 = F_121 ( V_2 , V_175 , V_7 -> V_166 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_33 ( V_2 , V_7 -> V_166 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_35 , int V_164 ,
int V_38 )
{
int V_40 , V_167 = V_7 -> V_9 . V_141 ;
int V_168 = V_7 -> V_9 . V_169 ;
int V_174 = V_7 -> V_9 . V_171 ;
const T_3 * V_37 = V_35 ;
T_3 * V_170 = V_7 -> V_166 ;
for ( V_40 = 0 ; V_174 ; V_174 -- , V_40 += V_168 , V_37 += V_167 ) {
V_7 -> V_9 . V_203 ( V_2 , V_248 ) ;
V_7 -> V_33 ( V_2 , V_37 , V_167 ) ;
if ( V_7 -> V_9 . V_172 ) {
V_7 -> V_33 ( V_2 , V_170 , V_7 -> V_9 . V_172 ) ;
V_170 += V_7 -> V_9 . V_172 ;
}
V_7 -> V_9 . V_182 ( V_2 , V_37 , V_170 ) ;
V_7 -> V_33 ( V_2 , V_170 , V_168 ) ;
V_170 += V_168 ;
if ( V_7 -> V_9 . V_173 ) {
V_7 -> V_33 ( V_2 , V_170 , V_7 -> V_9 . V_173 ) ;
V_170 += V_7 -> V_9 . V_173 ;
}
}
V_40 = V_2 -> V_14 - ( V_170 - V_7 -> V_166 ) ;
if ( V_40 )
V_7 -> V_33 ( V_2 , V_170 , V_40 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_11 , int V_249 , const T_3 * V_35 ,
int V_164 , int V_38 , int V_256 , int V_257 )
{
int V_118 , V_258 ;
if ( ! ( V_7 -> V_48 & V_259 ) &&
V_7 -> V_9 . V_260 )
V_258 = V_11 || ( V_249 < V_2 -> V_45 ) ;
else
V_258 = 0 ;
if ( F_108 ( & V_7 -> V_9 ) )
V_7 -> V_50 ( V_2 , V_88 , 0x00 , V_38 ) ;
if ( F_87 ( V_257 ) )
V_118 = V_7 -> V_9 . V_247 ( V_2 , V_7 , V_35 ,
V_164 , V_38 ) ;
else if ( V_258 )
V_118 = V_7 -> V_9 . V_260 ( V_2 , V_7 , V_11 , V_249 ,
V_35 , V_164 , V_38 ) ;
else
V_118 = V_7 -> V_9 . V_261 ( V_2 , V_7 , V_35 , V_164 ,
V_38 ) ;
if ( V_118 < 0 )
return V_118 ;
V_256 = 0 ;
if ( ! V_256 || ! F_126 ( V_7 ) ) {
if ( F_108 ( & V_7 -> V_9 ) )
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
if ( ( V_118 & V_139 ) && ( V_7 -> V_262 ) )
V_118 = V_7 -> V_262 ( V_2 , V_7 , V_68 , V_118 ,
V_38 ) ;
if ( V_118 & V_139 )
return - V_140 ;
} else {
V_7 -> V_50 ( V_2 , V_107 , - 1 , - 1 ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
}
return 0 ;
}
static T_3 * F_127 ( struct V_1 * V_2 , T_3 * V_170 , T_10 V_16 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
memset ( V_7 -> V_166 , 0xff , V_2 -> V_14 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_207 :
memcpy ( V_7 -> V_166 + V_58 -> V_60 , V_170 , V_16 ) ;
return V_170 + V_16 ;
case V_208 :
V_17 = F_128 ( V_2 , V_170 , V_7 -> V_166 ,
V_58 -> V_60 , V_16 ) ;
F_102 ( V_17 ) ;
return V_170 + V_16 ;
default:
F_19 () ;
}
return NULL ;
}
static int F_129 ( struct V_1 * V_2 , T_1 V_263 ,
struct V_57 * V_58 )
{
int V_28 , V_214 , V_38 , V_264 , V_84 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_9 V_265 = V_58 -> V_16 ;
T_9 V_266 = V_58 -> V_61 ;
T_9 V_267 = F_105 ( V_2 , V_58 ) ;
T_3 * V_170 = V_58 -> V_59 ;
T_3 * V_35 = V_58 -> V_221 ;
int V_17 ;
int V_164 = V_170 ? 1 : 0 ;
V_58 -> V_232 = 0 ;
if ( ! V_265 )
return 0 ;
if ( F_130 ( V_263 ) || F_130 ( V_58 -> V_16 ) ) {
F_131 ( L_13 ,
V_19 ) ;
return - V_20 ;
}
V_84 = V_263 & ( V_2 -> V_45 - 1 ) ;
V_28 = ( int ) ( V_263 >> V_7 -> V_143 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
V_17 = - V_140 ;
goto V_268;
}
V_214 = ( int ) ( V_263 >> V_7 -> V_46 ) ;
V_38 = V_214 & V_7 -> V_47 ;
V_264 = ( 1 << ( V_7 -> V_18 - V_7 -> V_46 ) ) - 1 ;
if ( V_263 <= ( ( T_1 ) V_7 -> V_224 << V_7 -> V_46 ) &&
( ( T_1 ) V_7 -> V_224 << V_7 -> V_46 ) < ( V_263 + V_58 -> V_16 ) )
V_7 -> V_224 = - 1 ;
if ( V_170 && V_58 -> V_60 && ( V_58 -> V_60 + V_58 -> V_61 > V_267 ) ) {
V_17 = - V_20 ;
goto V_268;
}
while ( 1 ) {
int V_169 = V_2 -> V_45 ;
int V_256 = V_265 > V_169 && V_38 != V_264 ;
T_3 * V_269 = V_35 ;
int V_219 ;
int V_270 = ( V_84 || V_265 < V_2 -> V_45 ) ;
if ( V_270 )
V_219 = 1 ;
else if ( V_7 -> V_48 & V_223 )
V_219 = ! F_107 ( V_35 ) ;
else
V_219 = 0 ;
if ( V_219 ) {
F_7 ( L_14 ,
V_19 , V_35 ) ;
V_256 = 0 ;
if ( V_270 )
V_169 = F_113 ( int , V_169 - V_84 , V_265 ) ;
V_7 -> V_224 = - 1 ;
memset ( V_7 -> V_176 -> V_225 , 0xff , V_2 -> V_45 ) ;
memcpy ( & V_7 -> V_176 -> V_225 [ V_84 ] , V_35 , V_169 ) ;
V_269 = V_7 -> V_176 -> V_225 ;
}
if ( F_87 ( V_170 ) ) {
T_10 V_16 = F_106 ( V_266 , V_267 ) ;
V_170 = F_127 ( V_2 , V_170 , V_16 , V_58 ) ;
V_266 -= V_16 ;
} else {
memset ( V_7 -> V_166 , 0xff , V_2 -> V_14 ) ;
}
V_17 = V_7 -> V_261 ( V_2 , V_7 , V_84 , V_169 , V_269 ,
V_164 , V_38 , V_256 ,
( V_58 -> V_62 == V_207 ) ) ;
if ( V_17 )
break;
V_265 -= V_169 ;
if ( ! V_265 )
break;
V_84 = 0 ;
V_35 += V_169 ;
V_214 ++ ;
V_38 = V_214 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_134 ( V_2 , - 1 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
}
}
V_58 -> V_232 = V_58 -> V_16 - V_265 ;
if ( F_87 ( V_170 ) )
V_58 -> V_233 = V_58 -> V_61 ;
V_268:
V_7 -> V_134 ( V_2 , - 1 ) ;
return V_17 ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_263 , T_10 V_16 ,
T_10 * V_232 , const T_3 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_57 V_58 ;
int V_17 ;
F_66 ( V_2 , V_7 , 400 ) ;
F_60 ( V_7 , V_2 , V_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_221 = ( T_3 * ) V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_129 ( V_2 , V_263 , & V_58 ) ;
* V_232 = V_58 . V_232 ;
return V_17 ;
}
static int F_133 ( struct V_1 * V_2 , T_1 V_263 , T_10 V_16 ,
T_10 * V_232 , const T_3 * V_35 )
{
struct V_57 V_58 ;
int V_17 ;
F_37 ( V_2 , V_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_221 = ( T_3 * ) V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_129 ( V_2 , V_263 , & V_58 ) ;
* V_232 = V_58 . V_232 ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_263 ,
struct V_57 * V_58 )
{
int V_28 , V_38 , V_118 , V_16 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_15 ,
V_19 , ( unsigned int ) V_263 , ( int ) V_58 -> V_61 ) ;
V_16 = F_105 ( V_2 , V_58 ) ;
if ( ( V_58 -> V_60 + V_58 -> V_61 ) > V_16 ) {
F_7 ( L_16 ,
V_19 ) ;
return - V_20 ;
}
if ( F_87 ( V_58 -> V_60 >= V_16 ) ) {
F_7 ( L_17 ,
V_19 ) ;
return - V_20 ;
}
if ( F_87 ( V_263 >= V_2 -> V_141 ||
V_58 -> V_60 + V_58 -> V_61 >
( ( V_2 -> V_141 >> V_7 -> V_46 ) -
( V_263 >> V_7 -> V_46 ) ) * V_16 ) ) {
F_7 ( L_18 ,
V_19 ) ;
return - V_20 ;
}
V_28 = ( int ) ( V_263 >> V_7 -> V_143 ) ;
F_82 ( V_7 , V_28 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
V_38 = ( int ) ( V_263 >> V_7 -> V_46 ) ;
if ( F_39 ( V_2 ) ) {
V_7 -> V_134 ( V_2 , - 1 ) ;
return - V_271 ;
}
if ( V_38 == V_7 -> V_224 )
V_7 -> V_224 = - 1 ;
F_127 ( V_2 , V_58 -> V_59 , V_58 -> V_61 , V_58 ) ;
if ( V_58 -> V_62 == V_207 )
V_118 = V_7 -> V_9 . V_272 ( V_2 , V_7 , V_38 & V_7 -> V_47 ) ;
else
V_118 = V_7 -> V_9 . V_273 ( V_2 , V_7 , V_38 & V_7 -> V_47 ) ;
V_7 -> V_134 ( V_2 , - 1 ) ;
if ( V_118 )
return V_118 ;
V_58 -> V_233 = V_58 -> V_61 ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , T_1 V_263 ,
struct V_57 * V_58 )
{
int V_17 = - V_246 ;
V_58 -> V_232 = 0 ;
if ( V_58 -> V_221 && ( V_263 + V_58 -> V_16 ) > V_2 -> V_141 ) {
F_7 ( L_18 ,
V_19 ) ;
return - V_20 ;
}
F_37 ( V_2 , V_68 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_208 :
case V_207 :
break;
default:
goto V_144;
}
if ( ! V_58 -> V_221 )
V_17 = F_34 ( V_2 , V_263 , V_58 ) ;
else
V_17 = F_129 ( V_2 , V_263 , V_58 ) ;
V_144:
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_135 ( struct V_1 * V_2 , int V_38 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_50 ( V_2 , V_96 , - 1 , V_38 ) ;
V_7 -> V_50 ( V_2 , V_97 , - 1 , - 1 ) ;
return V_7 -> V_138 ( V_2 , V_7 ) ;
}
static int F_136 ( struct V_1 * V_2 , struct V_65 * V_274 )
{
return F_36 ( V_2 , V_274 , 0 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_65 * V_274 ,
int V_76 )
{
int V_38 , V_118 , V_275 , V_17 , V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_16 ;
F_7 ( L_6 ,
V_19 , ( unsigned long long ) V_274 -> V_67 ,
( unsigned long long ) V_274 -> V_16 ) ;
if ( F_6 ( V_2 , V_274 -> V_67 , V_274 -> V_16 ) )
return - V_20 ;
F_37 ( V_2 , V_276 ) ;
V_38 = ( int ) ( V_274 -> V_67 >> V_7 -> V_46 ) ;
V_28 = ( int ) ( V_274 -> V_67 >> V_7 -> V_143 ) ;
V_275 = 1 << ( V_7 -> V_18 - V_7 -> V_46 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_7 ,
V_19 ) ;
V_274 -> V_24 = V_146 ;
goto V_277;
}
V_16 = V_274 -> V_16 ;
V_274 -> V_24 = V_278 ;
while ( V_16 ) {
if ( F_42 ( V_2 , ( ( T_1 ) V_38 ) <<
V_7 -> V_46 , V_76 ) ) {
F_137 ( L_19 ,
V_19 , V_38 ) ;
V_274 -> V_24 = V_146 ;
goto V_277;
}
if ( V_38 <= V_7 -> V_224 && V_7 -> V_224 <
( V_38 + V_275 ) )
V_7 -> V_224 = - 1 ;
V_118 = V_7 -> V_279 ( V_2 , V_38 & V_7 -> V_47 ) ;
if ( ( V_118 & V_139 ) && ( V_7 -> V_262 ) )
V_118 = V_7 -> V_262 ( V_2 , V_7 , V_276 ,
V_118 , V_38 ) ;
if ( V_118 & V_139 ) {
F_7 ( L_20 ,
V_19 , V_38 ) ;
V_274 -> V_24 = V_146 ;
V_274 -> V_280 =
( ( T_1 ) V_38 << V_7 -> V_46 ) ;
goto V_277;
}
V_16 -= ( 1ULL << V_7 -> V_18 ) ;
V_38 += V_275 ;
if ( V_16 && ! ( V_38 & V_7 -> V_47 ) ) {
V_28 ++ ;
V_7 -> V_134 ( V_2 , - 1 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
}
}
V_274 -> V_24 = V_281 ;
V_277:
V_17 = V_274 -> V_24 == V_281 ? 0 : - V_140 ;
V_7 -> V_134 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
if ( ! V_17 )
F_138 ( V_274 ) ;
return V_17 ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_7 ( L_21 , V_19 ) ;
F_37 ( V_2 , V_282 ) ;
F_8 ( V_2 ) ;
}
static int F_140 ( struct V_1 * V_2 , T_1 V_283 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_28 = ( int ) ( V_283 >> V_7 -> V_143 ) ;
int V_17 ;
F_37 ( V_2 , V_234 ) ;
V_7 -> V_134 ( V_2 , V_28 ) ;
V_17 = F_42 ( V_2 , V_283 , 0 ) ;
V_7 -> V_134 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_141 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_17 ;
V_17 = F_140 ( V_2 , V_15 ) ;
if ( V_17 ) {
if ( V_17 > 0 )
return 0 ;
return V_17 ;
}
return F_35 ( V_2 , V_15 ) ;
}
static int F_142 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_284 )
{
int V_118 ;
int V_40 ;
if ( ! V_7 -> V_122 ||
! ( F_143 ( V_7 -> V_285 . V_286 )
& V_287 ) )
return - V_20 ;
V_7 -> V_50 ( V_2 , V_288 , V_67 , - 1 ) ;
for ( V_40 = 0 ; V_40 < V_124 ; ++ V_40 )
V_7 -> V_289 ( V_2 , V_284 [ V_40 ] ) ;
V_118 = V_7 -> V_138 ( V_2 , V_7 ) ;
if ( V_118 & V_139 )
return - V_140 ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_284 )
{
int V_40 ;
if ( ! V_7 -> V_122 ||
! ( F_143 ( V_7 -> V_285 . V_286 )
& V_287 ) )
return - V_20 ;
V_7 -> V_50 ( V_2 , V_290 , V_67 , - 1 ) ;
for ( V_40 = 0 ; V_40 < V_124 ; ++ V_40 )
* V_284 ++ = V_7 -> V_54 ( V_2 ) ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_116 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_24 == V_116 )
F_8 ( V_2 ) ;
else
F_72 ( L_22 ,
V_19 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
F_37 ( V_2 , V_116 ) ;
}
static void F_148 ( struct V_6 * V_7 , int V_199 )
{
if ( ! V_7 -> V_99 )
V_7 -> V_99 = 20 ;
if ( V_7 -> V_50 == NULL )
V_7 -> V_50 = F_54 ;
if ( V_7 -> V_138 == NULL )
V_7 -> V_138 = F_67 ;
if ( ! V_7 -> V_134 )
V_7 -> V_134 = F_18 ;
if ( ! V_7 -> V_126 )
V_7 -> V_126 = F_142 ;
if ( ! V_7 -> V_291 )
V_7 -> V_291 = F_144 ;
if ( ! V_7 -> V_54 || V_7 -> V_54 == F_12 )
V_7 -> V_54 = V_199 ? F_14 : F_12 ;
if ( ! V_7 -> V_53 )
V_7 -> V_53 = F_17 ;
if ( ! V_7 -> V_77 )
V_7 -> V_77 = F_30 ;
if ( ! V_7 -> V_69 )
V_7 -> V_69 = F_33 ;
if ( ! V_7 -> V_33 || V_7 -> V_33 == F_22 )
V_7 -> V_33 = V_199 ? F_26 : F_22 ;
if ( ! V_7 -> V_289 || V_7 -> V_289 == F_20 )
V_7 -> V_289 = V_199 ? F_21 : F_20 ;
if ( ! V_7 -> V_165 || V_7 -> V_165 == F_24 )
V_7 -> V_165 = V_199 ? F_28 : F_24 ;
if ( ! V_7 -> V_292 )
V_7 -> V_292 = V_293 ;
if ( ! V_7 -> V_21 ) {
V_7 -> V_21 = & V_7 -> V_294 ;
F_149 ( V_7 -> V_21 ) ;
}
}
static void F_150 ( T_3 * V_295 , T_10 V_16 )
{
T_11 V_40 ;
V_295 [ V_16 - 1 ] = 0 ;
for ( V_40 = 0 ; V_40 < V_16 - 1 ; V_40 ++ ) {
if ( V_295 [ V_40 ] < ' ' || V_295 [ V_40 ] > 127 )
V_295 [ V_40 ] = '?' ;
}
F_151 ( V_295 ) ;
}
static T_4 F_152 ( T_4 V_296 , T_8 const * V_37 , T_10 V_16 )
{
int V_40 ;
while ( V_16 -- ) {
V_296 ^= * V_37 ++ << 8 ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
V_296 = ( V_296 << 1 ) ^ ( ( V_296 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_296 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_297 * V_37 )
{
struct V_298 * V_299 ;
struct V_300 * V_295 ;
struct V_301 * V_9 ;
T_3 * V_302 ;
int V_17 = - V_20 ;
int V_16 ;
int V_40 ;
V_16 = F_143 ( V_37 -> V_303 ) * 16 ;
V_299 = F_154 ( V_16 , V_131 ) ;
if ( ! V_299 )
return - V_132 ;
V_7 -> V_50 ( V_2 , V_304 , 0 , - 1 ) ;
V_7 -> V_50 ( V_2 , V_109 ,
sizeof( * V_37 ) * V_37 -> V_305 , - 1 ) ;
V_7 -> V_165 ( V_2 , ( T_3 * ) V_299 , V_16 ) ;
if ( ( F_152 ( V_306 , ( ( T_3 * ) V_299 ) + 2 , V_16 - 2 )
!= F_143 ( V_299 -> V_296 ) ) ) {
F_7 ( L_23 ) ;
goto V_307;
}
if ( strncmp ( V_299 -> V_308 , L_24 , 4 ) ) {
F_7 ( L_25 ) ;
goto V_307;
}
V_302 = ( T_3 * ) ( V_299 + 1 ) ;
for ( V_40 = 0 ; V_40 < V_309 ; V_40 ++ ) {
V_295 = V_299 -> V_310 + V_40 ;
if ( V_295 -> type == V_311 )
break;
V_302 += V_295 -> V_12 * 16 ;
}
if ( V_40 == V_309 ) {
F_7 ( L_26 ) ;
goto V_307;
}
V_9 = (struct V_301 * ) V_302 ;
if ( ! V_9 -> V_312 ) {
F_7 ( L_27 ) ;
goto V_307;
}
V_7 -> V_313 = V_9 -> V_314 ;
V_7 -> V_315 = 1 << V_9 -> V_312 ;
V_17 = 0 ;
V_307:
F_81 ( V_299 ) ;
return V_17 ;
}
static int F_155 ( struct V_1 * V_2 , int V_209 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_316 [ V_124 ] = { V_209 } ;
return V_7 -> V_126 ( V_2 , V_7 , V_317 ,
V_316 ) ;
}
static void F_156 ( struct V_6 * V_7 ,
struct V_297 * V_37 )
{
struct V_318 * V_319 = ( void * ) V_37 -> V_320 ;
if ( F_143 ( V_37 -> V_321 ) < 1 )
return;
V_7 -> V_210 = V_319 -> V_322 ;
V_7 -> V_211 = F_155 ;
}
static int F_157 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_199 )
{
struct V_297 * V_37 = & V_7 -> V_285 ;
int V_40 , V_323 ;
int V_324 ;
V_7 -> V_50 ( V_2 , V_325 , 0x20 , - 1 ) ;
if ( V_7 -> V_54 ( V_2 ) != 'O' || V_7 -> V_54 ( V_2 ) != 'N' ||
V_7 -> V_54 ( V_2 ) != 'F' || V_7 -> V_54 ( V_2 ) != 'I' )
return 0 ;
V_7 -> V_50 ( V_2 , V_304 , 0 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
for ( V_323 = 0 ; V_323 < sizeof( * V_37 ) ; V_323 ++ )
( ( T_3 * ) V_37 ) [ V_323 ] = V_7 -> V_54 ( V_2 ) ;
if ( F_152 ( V_306 , ( T_3 * ) V_37 , 254 ) ==
F_143 ( V_37 -> V_296 ) ) {
break;
}
}
if ( V_40 == 3 ) {
F_72 ( L_28 ) ;
return 0 ;
}
V_324 = F_143 ( V_37 -> V_326 ) ;
if ( V_324 & ( 1 << 5 ) )
V_7 -> V_122 = 23 ;
else if ( V_324 & ( 1 << 4 ) )
V_7 -> V_122 = 22 ;
else if ( V_324 & ( 1 << 3 ) )
V_7 -> V_122 = 21 ;
else if ( V_324 & ( 1 << 2 ) )
V_7 -> V_122 = 20 ;
else if ( V_324 & ( 1 << 1 ) )
V_7 -> V_122 = 10 ;
if ( ! V_7 -> V_122 ) {
F_158 ( L_29 , V_324 ) ;
return 0 ;
}
F_150 ( V_37 -> V_327 , sizeof( V_37 -> V_327 ) ) ;
F_150 ( V_37 -> V_328 , sizeof( V_37 -> V_328 ) ) ;
if ( ! V_2 -> V_329 )
V_2 -> V_329 = V_37 -> V_328 ;
V_2 -> V_45 = F_159 ( V_37 -> V_330 ) ;
V_2 -> V_44 = 1 << ( F_78 ( F_159 ( V_37 -> V_275 ) ) - 1 ) ;
V_2 -> V_44 *= V_2 -> V_45 ;
V_2 -> V_14 = F_143 ( V_37 -> V_331 ) ;
V_7 -> V_93 = 1 << ( F_78 ( F_159 ( V_37 -> V_332 ) ) - 1 ) ;
V_7 -> V_93 *= ( T_2 ) V_2 -> V_44 * V_37 -> V_333 ;
V_7 -> V_334 = V_37 -> V_334 ;
if ( F_160 ( V_7 ) & V_335 )
* V_199 = V_49 ;
else
* V_199 = 0 ;
if ( V_37 -> V_314 != 0xff ) {
V_7 -> V_313 = V_37 -> V_314 ;
V_7 -> V_315 = 512 ;
} else if ( V_7 -> V_122 >= 21 &&
( F_160 ( V_7 ) & V_336 ) ) {
if ( V_2 -> V_45 > 512 && V_7 -> V_50 == F_54 )
V_7 -> V_50 = F_59 ;
if ( F_153 ( V_2 , V_7 , V_37 ) )
F_137 ( L_30 ) ;
} else {
F_137 ( L_31 ) ;
}
if ( V_37 -> V_337 == V_338 )
F_156 ( V_7 , V_37 ) ;
return 1 ;
}
static int F_161 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_199 )
{
struct V_339 * V_37 = & V_7 -> V_340 ;
struct V_341 * V_9 ;
int V_324 ;
int V_40 , V_323 ;
V_7 -> V_50 ( V_2 , V_325 , 0x40 , - 1 ) ;
if ( V_7 -> V_54 ( V_2 ) != 'J' || V_7 -> V_54 ( V_2 ) != 'E' ||
V_7 -> V_54 ( V_2 ) != 'D' || V_7 -> V_54 ( V_2 ) != 'E' ||
V_7 -> V_54 ( V_2 ) != 'C' )
return 0 ;
V_7 -> V_50 ( V_2 , V_304 , 0x40 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
for ( V_323 = 0 ; V_323 < sizeof( * V_37 ) ; V_323 ++ )
( ( T_3 * ) V_37 ) [ V_323 ] = V_7 -> V_54 ( V_2 ) ;
if ( F_152 ( V_306 , ( T_3 * ) V_37 , 510 ) ==
F_143 ( V_37 -> V_296 ) )
break;
}
if ( V_40 == 3 ) {
F_72 ( L_32 ) ;
return 0 ;
}
V_324 = F_143 ( V_37 -> V_326 ) ;
if ( V_324 & ( 1 << 2 ) )
V_7 -> V_342 = 10 ;
else if ( V_324 & ( 1 << 1 ) )
V_7 -> V_342 = 1 ;
if ( ! V_7 -> V_342 ) {
F_158 ( L_33 , V_324 ) ;
return 0 ;
}
F_150 ( V_37 -> V_327 , sizeof( V_37 -> V_327 ) ) ;
F_150 ( V_37 -> V_328 , sizeof( V_37 -> V_328 ) ) ;
if ( ! V_2 -> V_329 )
V_2 -> V_329 = V_37 -> V_328 ;
V_2 -> V_45 = F_159 ( V_37 -> V_330 ) ;
V_2 -> V_44 = 1 << ( F_78 ( F_159 ( V_37 -> V_275 ) ) - 1 ) ;
V_2 -> V_44 *= V_2 -> V_45 ;
V_2 -> V_14 = F_143 ( V_37 -> V_331 ) ;
V_7 -> V_93 = 1 << ( F_78 ( F_159 ( V_37 -> V_332 ) ) - 1 ) ;
V_7 -> V_93 *= ( T_2 ) V_2 -> V_44 * V_37 -> V_333 ;
V_7 -> V_334 = V_37 -> V_334 ;
if ( F_162 ( V_7 ) & V_343 )
* V_199 = V_49 ;
else
* V_199 = 0 ;
V_9 = & V_37 -> V_344 [ 0 ] ;
if ( V_9 -> V_312 >= 9 ) {
V_7 -> V_313 = V_9 -> V_314 ;
V_7 -> V_315 = 1 << V_9 -> V_312 ;
} else {
F_137 ( L_27 ) ;
}
return 1 ;
}
static int F_163 ( T_8 * V_345 , int V_346 , int V_347 )
{
int V_40 , V_323 ;
for ( V_40 = 0 ; V_40 < V_347 ; V_40 ++ )
for ( V_323 = V_40 + V_347 ; V_323 < V_346 ; V_323 += V_347 )
if ( V_345 [ V_40 ] != V_345 [ V_323 ] )
return 0 ;
return 1 ;
}
static int F_164 ( T_8 * V_345 , int V_346 )
{
int V_348 , V_347 ;
for ( V_348 = V_346 - 1 ; V_348 >= 0 ; V_348 -- )
if ( V_345 [ V_348 ] )
break;
if ( V_348 < 0 )
return 0 ;
for ( V_347 = 1 ; V_347 < V_346 ; V_347 ++ )
if ( F_163 ( V_345 , V_346 , V_347 ) )
break;
if ( V_347 < V_346 )
return V_347 ;
if ( V_348 < V_346 - 1 )
return V_348 + 1 ;
return V_346 ;
}
static int F_165 ( T_8 V_349 )
{
int V_350 ;
V_350 = V_349 & V_351 ;
V_350 >>= V_352 ;
return V_350 + 1 ;
}
static void F_166 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_8 V_345 [ 8 ] , int * V_199 )
{
int V_353 , V_354 ;
V_7 -> V_334 = F_165 ( V_345 [ 2 ] ) ;
V_353 = V_345 [ 3 ] ;
V_354 = F_164 ( V_345 , 8 ) ;
if ( V_354 == 6 && V_345 [ 0 ] == V_355 &&
! F_167 ( V_7 ) && V_345 [ 5 ] != 0x00 ) {
V_2 -> V_45 = 2048 << ( V_353 & 0x03 ) ;
V_353 >>= 2 ;
switch ( ( ( V_353 >> 2 ) & 0x04 ) | ( V_353 & 0x03 ) ) {
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
V_353 >>= 2 ;
V_2 -> V_44 = ( 128 * 1024 ) <<
( ( ( V_353 >> 1 ) & 0x04 ) | ( V_353 & 0x03 ) ) ;
* V_199 = 0 ;
} else if ( V_354 == 6 && V_345 [ 0 ] == V_356 &&
! F_167 ( V_7 ) ) {
unsigned int V_357 ;
V_2 -> V_45 = 2048 << ( V_353 & 0x03 ) ;
V_353 >>= 2 ;
switch ( ( ( V_353 >> 2 ) & 0x04 ) | ( V_353 & 0x03 ) ) {
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
V_353 >>= 2 ;
V_357 = ( ( V_353 >> 1 ) & 0x04 ) | ( V_353 & 0x03 ) ;
if ( V_357 < 0x03 )
V_2 -> V_44 = ( 128 * 1024 ) << V_357 ;
else if ( V_357 == 0x03 )
V_2 -> V_44 = 768 * 1024 ;
else
V_2 -> V_44 = ( 64 * 1024 ) << V_357 ;
* V_199 = 0 ;
} else {
V_2 -> V_45 = 1024 << ( V_353 & 0x03 ) ;
V_353 >>= 2 ;
V_2 -> V_14 = ( 8 << ( V_353 & 0x01 ) ) *
( V_2 -> V_45 >> 9 ) ;
V_353 >>= 2 ;
V_2 -> V_44 = ( 64 * 1024 ) << ( V_353 & 0x03 ) ;
V_353 >>= 2 ;
* V_199 = ( V_353 & 0x01 ) ? V_49 : 0 ;
if ( V_354 >= 6 && V_345 [ 0 ] == V_358 &&
F_167 ( V_7 ) &&
( V_345 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_345 [ 4 ] & 0x80 ) ) {
V_2 -> V_14 = 32 * V_2 -> V_45 >> 9 ;
}
}
}
static void F_168 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_359 * type , T_8 V_345 [ 8 ] ,
int * V_199 )
{
int V_360 = V_345 [ 0 ] ;
V_2 -> V_44 = type -> V_44 ;
V_2 -> V_45 = type -> V_361 ;
V_2 -> V_14 = V_2 -> V_45 / 32 ;
* V_199 = type -> V_48 & V_49 ;
V_7 -> V_334 = 1 ;
if ( V_360 == V_362 && V_345 [ 4 ] != 0x00 && V_345 [ 5 ] == 0x00
&& V_345 [ 6 ] == 0x00 && V_345 [ 7 ] == 0x00
&& V_2 -> V_45 == 512 ) {
V_2 -> V_44 = 128 * 1024 ;
V_2 -> V_44 <<= ( ( V_345 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_169 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_8 V_345 [ 8 ] )
{
int V_360 = V_345 [ 0 ] ;
if ( V_2 -> V_45 > 512 || ( V_7 -> V_48 & V_49 ) )
V_7 -> V_52 = V_363 ;
else
V_7 -> V_52 = V_364 ;
if ( ! F_167 ( V_7 ) &&
( V_360 == V_355 ||
V_360 == V_356 ) )
V_7 -> V_42 |= V_43 ;
else if ( ( F_167 ( V_7 ) &&
( V_360 == V_355 ||
V_360 == V_356 ||
V_360 == V_358 ||
V_360 == V_362 ||
V_360 == V_365 ) ) ||
( V_2 -> V_45 == 2048 &&
V_360 == V_338 ) )
V_7 -> V_42 |= V_56 ;
}
static inline bool F_170 ( struct V_359 * type )
{
return type -> V_354 ;
}
static bool F_171 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_359 * type , T_8 * V_345 , int * V_199 )
{
if ( ! strncmp ( type -> V_366 , V_345 , type -> V_354 ) ) {
V_2 -> V_45 = type -> V_361 ;
V_2 -> V_44 = type -> V_44 ;
V_2 -> V_14 = type -> V_14 ;
V_7 -> V_334 = F_165 ( V_345 [ 2 ] ) ;
V_7 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
V_7 -> V_48 |= type -> V_48 ;
V_7 -> V_313 = F_172 ( type ) ;
V_7 -> V_315 = F_173 ( type ) ;
V_7 -> V_125 =
type -> V_125 ;
* V_199 = type -> V_48 & V_49 ;
if ( ! V_2 -> V_329 )
V_2 -> V_329 = type -> V_329 ;
return true ;
}
return false ;
}
static int F_174 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_360 , int * V_367 ,
struct V_359 * type )
{
int V_199 ;
int V_40 , V_368 ;
T_8 V_345 [ 8 ] ;
F_82 ( V_7 , 0 ) ;
V_7 -> V_134 ( V_2 , 0 ) ;
V_7 -> V_50 ( V_2 , V_325 , 0x00 , - 1 ) ;
* V_360 = V_7 -> V_54 ( V_2 ) ;
* V_367 = V_7 -> V_54 ( V_2 ) ;
V_7 -> V_50 ( V_2 , V_325 , 0x00 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
V_345 [ V_40 ] = V_7 -> V_54 ( V_2 ) ;
if ( V_345 [ 0 ] != * V_360 || V_345 [ 1 ] != * V_367 ) {
F_158 ( L_34 ,
* V_360 , * V_367 , V_345 [ 0 ] , V_345 [ 1 ] ) ;
return - V_369 ;
}
if ( ! type )
type = V_370 ;
for (; type -> V_329 != NULL ; type ++ ) {
if ( F_170 ( type ) ) {
if ( F_171 ( V_2 , V_7 , type , V_345 , & V_199 ) )
goto V_371;
} else if ( * V_367 == type -> V_367 ) {
break;
}
}
V_7 -> V_122 = 0 ;
if ( ! type -> V_329 || ! type -> V_361 ) {
if ( F_157 ( V_2 , V_7 , & V_199 ) )
goto V_371;
if ( F_161 ( V_2 , V_7 , & V_199 ) )
goto V_371;
}
if ( ! type -> V_329 )
return - V_369 ;
if ( ! V_2 -> V_329 )
V_2 -> V_329 = type -> V_329 ;
V_7 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
if ( ! type -> V_361 ) {
F_166 ( V_2 , V_7 , V_345 , & V_199 ) ;
} else {
F_168 ( V_2 , V_7 , type , V_345 , & V_199 ) ;
}
V_7 -> V_48 |= type -> V_48 ;
if ( * V_360 != V_355 && ! type -> V_361 )
V_7 -> V_48 &= ~ V_372 ;
V_371:
for ( V_368 = 0 ; V_373 [ V_368 ] . V_366 != 0x0 ; V_368 ++ ) {
if ( V_373 [ V_368 ] . V_366 == * V_360 )
break;
}
if ( V_7 -> V_48 & V_374 ) {
F_68 ( V_7 -> V_48 & V_49 ) ;
V_7 -> V_48 |= V_199 ;
F_148 ( V_7 , V_199 ) ;
} else if ( V_199 != ( V_7 -> V_48 & V_49 ) ) {
F_158 ( L_35 ,
* V_360 , * V_367 ) ;
F_158 ( L_36 , V_373 [ V_368 ] . V_329 , V_2 -> V_329 ) ;
F_137 ( L_37 ,
( V_7 -> V_48 & V_49 ) ? 16 : 8 ,
V_199 ? 16 : 8 ) ;
return - V_20 ;
}
F_169 ( V_2 , V_7 , V_345 ) ;
V_7 -> V_46 = F_175 ( V_2 -> V_45 ) - 1 ;
V_7 -> V_47 = ( V_7 -> V_93 >> V_7 -> V_46 ) - 1 ;
V_7 -> V_375 = V_7 -> V_18 =
F_175 ( V_2 -> V_44 ) - 1 ;
if ( V_7 -> V_93 & 0xffffffff )
V_7 -> V_143 = F_175 ( ( unsigned ) V_7 -> V_93 ) - 1 ;
else {
V_7 -> V_143 = F_175 ( ( unsigned ) ( V_7 -> V_93 >> 32 ) ) ;
V_7 -> V_143 += 32 - 1 ;
}
V_7 -> V_55 = 8 ;
V_7 -> V_279 = F_135 ;
if ( V_2 -> V_45 > 512 && V_7 -> V_50 == F_54 )
V_7 -> V_50 = F_59 ;
F_158 ( L_35 ,
* V_360 , * V_367 ) ;
if ( V_7 -> V_122 )
F_158 ( L_36 , V_373 [ V_368 ] . V_329 ,
V_7 -> V_285 . V_328 ) ;
else if ( V_7 -> V_342 )
F_158 ( L_36 , V_373 [ V_368 ] . V_329 ,
V_7 -> V_340 . V_328 ) ;
else
F_158 ( L_36 , V_373 [ V_368 ] . V_329 ,
type -> V_329 ) ;
F_158 ( L_38 ,
( int ) ( V_7 -> V_93 >> 20 ) , F_167 ( V_7 ) ? L_39 : L_40 ,
V_2 -> V_44 >> 10 , V_2 -> V_45 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_176 ( struct V_376 * V_377 )
{
const char * V_378 ;
int V_128 , V_40 ;
V_128 = F_177 ( V_377 , L_41 , & V_378 ) ;
if ( V_128 < 0 )
return V_128 ;
for ( V_40 = 0 ; V_40 < F_178 ( V_379 ) ; V_40 ++ )
if ( ! strcasecmp ( V_378 , V_379 [ V_40 ] ) )
return V_40 ;
if ( ! strcasecmp ( V_378 , L_42 ) )
return V_380 ;
return - V_369 ;
}
static int F_179 ( struct V_376 * V_377 )
{
const char * V_378 ;
int V_128 , V_40 ;
V_128 = F_177 ( V_377 , L_43 , & V_378 ) ;
if ( ! V_128 ) {
for ( V_40 = V_381 ; V_40 < F_178 ( V_382 ) ; V_40 ++ )
if ( ! strcasecmp ( V_378 , V_382 [ V_40 ] ) )
return V_40 ;
return - V_369 ;
}
V_128 = F_177 ( V_377 , L_41 , & V_378 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( ! strcasecmp ( V_378 , L_44 ) )
return V_381 ;
else if ( ! strcasecmp ( V_378 , L_42 ) )
return V_383 ;
return - V_369 ;
}
static int F_180 ( struct V_376 * V_377 )
{
int V_17 ;
T_12 V_324 ;
V_17 = F_181 ( V_377 , L_45 , & V_324 ) ;
return V_17 ? V_17 : V_324 ;
}
static int F_182 ( struct V_376 * V_377 )
{
int V_17 ;
T_12 V_324 ;
V_17 = F_181 ( V_377 , L_46 , & V_324 ) ;
return V_17 ? V_17 : V_324 ;
}
static int F_183 ( struct V_376 * V_377 )
{
T_12 V_324 ;
if ( F_181 ( V_377 , L_47 , & V_324 ) )
return 8 ;
switch ( V_324 ) {
case 8 :
case 16 :
return V_324 ;
default:
return - V_140 ;
}
}
static bool F_184 ( struct V_376 * V_377 )
{
return F_185 ( V_377 , L_48 ) ;
}
static int F_186 ( struct V_6 * V_7 )
{
struct V_376 * V_384 = F_187 ( V_7 ) ;
int V_385 , V_386 , V_387 , V_388 ;
if ( ! V_384 )
return 0 ;
if ( F_183 ( V_384 ) == 16 )
V_7 -> V_48 |= V_49 ;
if ( F_184 ( V_384 ) )
V_7 -> V_42 |= V_389 ;
V_385 = F_176 ( V_384 ) ;
V_386 = F_179 ( V_384 ) ;
V_387 = F_182 ( V_384 ) ;
V_388 = F_180 ( V_384 ) ;
if ( ( V_388 >= 0 && ! ( V_387 >= 0 ) ) ||
( ! ( V_388 >= 0 ) && V_387 >= 0 ) ) {
F_72 ( L_49 ) ;
return - V_20 ;
}
if ( V_385 >= 0 )
V_7 -> V_9 . V_62 = V_385 ;
if ( V_386 >= 0 )
V_7 -> V_9 . V_390 = V_386 ;
if ( V_387 >= 0 )
V_7 -> V_9 . V_202 = V_387 ;
if ( V_388 > 0 )
V_7 -> V_9 . V_141 = V_388 ;
if ( F_185 ( V_384 , L_50 ) )
V_7 -> V_9 . V_48 |= V_391 ;
return 0 ;
}
int F_188 ( struct V_1 * V_2 , int V_392 ,
struct V_359 * V_393 )
{
int V_40 , V_394 , V_395 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
V_17 = F_186 ( V_7 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_2 -> V_329 && V_2 -> V_396 . V_397 )
V_2 -> V_329 = F_189 ( V_2 -> V_396 . V_397 ) ;
if ( ( ! V_7 -> V_50 || ! V_7 -> V_134 ) && ! V_7 -> V_29 ) {
F_72 ( L_51 ) ;
return - V_20 ;
}
F_148 ( V_7 , V_7 -> V_48 & V_49 ) ;
V_17 = F_174 ( V_2 , V_7 , & V_394 , & V_395 , V_393 ) ;
if ( V_17 ) {
if ( ! ( V_7 -> V_48 & V_398 ) )
F_137 ( L_52 ) ;
V_7 -> V_134 ( V_2 , - 1 ) ;
return V_17 ;
}
V_17 = F_74 ( V_7 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_73 ( V_7 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_134 ( V_2 , - 1 ) ;
for ( V_40 = 1 ; V_40 < V_392 ; V_40 ++ ) {
F_82 ( V_7 , V_40 ) ;
V_7 -> V_134 ( V_2 , V_40 ) ;
V_7 -> V_50 ( V_2 , V_325 , 0x00 , - 1 ) ;
if ( V_394 != V_7 -> V_54 ( V_2 ) ||
V_395 != V_7 -> V_54 ( V_2 ) ) {
V_7 -> V_134 ( V_2 , - 1 ) ;
break;
}
V_7 -> V_134 ( V_2 , - 1 ) ;
}
if ( V_40 > 1 )
F_158 ( L_53 , V_40 ) ;
V_7 -> V_399 = V_40 ;
V_2 -> V_141 = V_40 * V_7 -> V_93 ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_68 ( V_9 -> V_62 != V_380 ) )
return - V_20 ;
switch ( V_9 -> V_390 ) {
case V_381 :
V_9 -> V_182 = V_400 ;
V_9 -> V_184 = V_401 ;
V_9 -> V_228 = F_92 ;
V_9 -> V_227 = F_95 ;
V_9 -> V_261 = F_120 ;
V_9 -> V_181 = F_90 ;
V_9 -> V_247 = F_118 ;
V_9 -> V_244 = F_111 ;
V_9 -> V_273 = F_114 ;
if ( ! V_9 -> V_141 )
V_9 -> V_141 = 256 ;
V_9 -> V_169 = 3 ;
V_9 -> V_202 = 1 ;
return 0 ;
case V_383 :
if ( ! F_191 () ) {
F_192 ( 1 , L_54 ) ;
return - V_20 ;
}
V_9 -> V_182 = V_402 ;
V_9 -> V_184 = V_403 ;
V_9 -> V_228 = F_92 ;
V_9 -> V_227 = F_95 ;
V_9 -> V_261 = F_120 ;
V_9 -> V_181 = F_90 ;
V_9 -> V_247 = F_118 ;
V_9 -> V_244 = F_111 ;
V_9 -> V_273 = F_114 ;
if ( ! V_9 -> V_141 && ( V_2 -> V_14 >= 64 ) ) {
V_9 -> V_141 = 512 ;
V_9 -> V_202 = 4 ;
}
if ( ! V_2 -> V_404 ) {
if ( V_2 -> V_14 < 64 ) {
F_192 ( 1 , L_55 ) ;
return - V_20 ;
}
F_193 ( V_2 , & V_405 ) ;
}
if ( V_2 -> V_404 == & V_405 &&
V_9 -> V_48 & V_391 ) {
int V_171 , V_169 ;
V_9 -> V_141 = 1024 ;
V_171 = V_2 -> V_45 / V_9 -> V_141 ;
V_169 = ( V_2 -> V_14 - 2 ) / V_171 ;
V_9 -> V_202 = V_169 * 8 / F_78 ( 8 * V_9 -> V_141 ) ;
}
V_9 -> V_169 = 0 ;
V_9 -> V_406 = F_194 ( V_2 ) ;
if ( ! V_9 -> V_406 ) {
F_192 ( 1 , L_56 ) ;
return - V_20 ;
}
return 0 ;
default:
F_192 ( 1 , L_57 ) ;
return - V_20 ;
}
}
static bool F_195 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_407 , V_408 ;
if ( V_9 -> V_141 == 0 || V_7 -> V_315 == 0 )
return true ;
V_407 = ( V_2 -> V_45 * V_9 -> V_202 ) / V_9 -> V_141 ;
V_408 = ( V_2 -> V_45 * V_7 -> V_313 ) / V_7 -> V_315 ;
return V_407 >= V_408 && V_9 -> V_202 >= V_7 -> V_313 ;
}
static bool F_196 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_108 ( V_9 ) )
return false ;
return ( ! V_9 -> V_228 || ! V_9 -> V_261 ||
! V_9 -> V_181 || ! V_9 -> V_247 ||
( F_109 ( V_7 ) && ! V_9 -> V_227 ) ||
( F_197 ( V_7 ) && ! V_9 -> V_260 &&
V_9 -> V_203 && V_9 -> V_182 ) ) ;
}
int F_198 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_409 * V_410 ;
int V_17 ;
if ( F_68 ( ( V_7 -> V_42 & V_64 ) &&
! ( V_7 -> V_42 & V_389 ) ) )
return - V_20 ;
if ( F_196 ( V_7 ) ) {
F_72 ( L_58 ) ;
return - V_20 ;
}
if ( ! ( V_7 -> V_48 & V_411 ) ) {
V_410 = F_77 ( sizeof( * V_410 ) + V_2 -> V_45
+ V_2 -> V_14 * 3 , V_131 ) ;
if ( ! V_410 )
return - V_132 ;
V_410 -> V_177 = ( T_3 * ) ( V_410 + 1 ) ;
V_410 -> V_179 = V_410 -> V_177 + V_2 -> V_14 ;
V_410 -> V_225 = V_410 -> V_179 + V_2 -> V_14 ;
V_7 -> V_176 = V_410 ;
} else {
if ( ! V_7 -> V_176 )
return - V_132 ;
}
V_7 -> V_166 = V_7 -> V_176 -> V_225 + V_2 -> V_45 ;
if ( ! V_2 -> V_404 &&
! ( V_9 -> V_62 == V_380 && V_9 -> V_390 == V_383 ) ) {
switch ( V_2 -> V_14 ) {
case 8 :
case 16 :
F_193 ( V_2 , & V_412 ) ;
break;
case 64 :
case 128 :
F_193 ( V_2 , & V_405 ) ;
break;
default:
F_192 ( 1 , L_59 ,
V_2 -> V_14 ) ;
V_17 = - V_20 ;
goto V_413;
}
}
if ( ! V_7 -> V_261 )
V_7 -> V_261 = F_125 ;
switch ( V_9 -> V_62 ) {
case V_414 :
if ( ! V_9 -> V_182 || ! V_9 -> V_184 || ! V_9 -> V_203 ) {
F_192 ( 1 , L_60 ) ;
V_17 = - V_20 ;
goto V_413;
}
if ( ! V_9 -> V_228 )
V_9 -> V_228 = F_98 ;
case V_415 :
if ( ! V_9 -> V_228 )
V_9 -> V_228 = F_97 ;
if ( ! V_9 -> V_261 )
V_9 -> V_261 = F_122 ;
if ( ! V_9 -> V_181 )
V_9 -> V_181 = F_90 ;
if ( ! V_9 -> V_247 )
V_9 -> V_247 = F_118 ;
if ( ! V_9 -> V_244 )
V_9 -> V_244 = F_111 ;
if ( ! V_9 -> V_273 )
V_9 -> V_273 = F_114 ;
if ( ! V_9 -> V_227 )
V_9 -> V_227 = F_95 ;
if ( ! V_9 -> V_260 && V_9 -> V_203 && V_9 -> V_182 )
V_9 -> V_260 = F_123 ;
case V_416 :
if ( ( ! V_9 -> V_182 || ! V_9 -> V_184 || ! V_9 -> V_203 ) &&
( ! V_9 -> V_228 ||
V_9 -> V_228 == F_97 ||
! V_9 -> V_261 ||
V_9 -> V_261 == F_122 ) ) {
F_192 ( 1 , L_60 ) ;
V_17 = - V_20 ;
goto V_413;
}
if ( ! V_9 -> V_228 )
V_9 -> V_228 = F_99 ;
if ( ! V_9 -> V_261 )
V_9 -> V_261 = F_124 ;
if ( ! V_9 -> V_181 )
V_9 -> V_181 = F_91 ;
if ( ! V_9 -> V_247 )
V_9 -> V_247 = F_119 ;
if ( ! V_9 -> V_244 )
V_9 -> V_244 = F_112 ;
if ( ! V_9 -> V_273 )
V_9 -> V_273 = F_115 ;
if ( V_2 -> V_45 >= V_9 -> V_141 ) {
if ( ! V_9 -> V_202 ) {
F_192 ( 1 , L_61 ) ;
V_17 = - V_20 ;
goto V_413;
}
break;
}
F_137 ( L_62 ,
V_9 -> V_141 , V_2 -> V_45 ) ;
V_9 -> V_62 = V_380 ;
V_9 -> V_390 = V_381 ;
case V_380 :
V_17 = F_190 ( V_2 ) ;
if ( V_17 ) {
V_17 = - V_20 ;
goto V_413;
}
break;
case V_417 :
F_137 ( L_63 ) ;
V_9 -> V_228 = F_90 ;
V_9 -> V_261 = F_118 ;
V_9 -> V_244 = F_111 ;
V_9 -> V_181 = F_90 ;
V_9 -> V_247 = F_118 ;
V_9 -> V_273 = F_114 ;
V_9 -> V_141 = V_2 -> V_45 ;
V_9 -> V_169 = 0 ;
V_9 -> V_202 = 0 ;
break;
default:
F_192 ( 1 , L_64 , V_9 -> V_62 ) ;
V_17 = - V_20 ;
goto V_413;
}
if ( ! V_9 -> V_243 )
V_9 -> V_243 = V_9 -> V_244 ;
if ( ! V_9 -> V_272 )
V_9 -> V_272 = V_9 -> V_273 ;
V_2 -> V_387 = V_9 -> V_202 ;
V_2 -> V_418 = V_9 -> V_141 ;
V_9 -> V_171 = V_2 -> V_45 / V_9 -> V_141 ;
if ( V_9 -> V_171 * V_9 -> V_141 != V_2 -> V_45 ) {
F_192 ( 1 , L_65 ) ;
V_17 = - V_20 ;
goto V_413;
}
V_9 -> V_13 = V_9 -> V_171 * V_9 -> V_169 ;
V_17 = F_199 ( V_2 ) ;
if ( V_17 < 0 )
V_17 = 0 ;
V_2 -> V_419 = V_17 ;
if ( ! F_195 ( V_2 ) )
F_137 ( L_66 ,
V_2 -> V_329 ) ;
if ( ! ( V_7 -> V_48 & V_259 ) && F_167 ( V_7 ) ) {
switch ( V_9 -> V_171 ) {
case 2 :
V_2 -> V_420 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_420 = 2 ;
break;
}
}
V_7 -> V_421 = V_2 -> V_45 >> V_2 -> V_420 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_224 = - 1 ;
switch ( V_9 -> V_62 ) {
case V_380 :
if ( V_7 -> V_46 > 9 )
V_7 -> V_48 |= V_422 ;
break;
default:
break;
}
V_2 -> type = F_167 ( V_7 ) ? V_423 : V_424 ;
V_2 -> V_425 = ( V_7 -> V_48 & V_426 ) ? V_427 :
V_428 ;
V_2 -> V_429 = F_136 ;
V_2 -> V_430 = NULL ;
V_2 -> V_431 = NULL ;
V_2 -> V_432 = F_110 ;
V_2 -> V_433 = F_133 ;
V_2 -> V_434 = F_132 ;
V_2 -> V_435 = F_117 ;
V_2 -> V_436 = F_134 ;
V_2 -> V_437 = F_139 ;
V_2 -> V_438 = NULL ;
V_2 -> V_439 = NULL ;
V_2 -> V_440 = F_145 ;
V_2 -> V_441 = F_146 ;
V_2 -> V_442 = F_147 ;
V_2 -> V_443 = F_40 ;
V_2 -> V_444 = F_140 ;
V_2 -> V_445 = F_141 ;
V_2 -> V_446 = V_2 -> V_45 ;
if ( ! V_2 -> V_447 )
V_2 -> V_447 = F_200 ( V_2 -> V_387 * 3 , 4 ) ;
if ( V_7 -> V_48 & V_448 )
return 0 ;
return V_7 -> V_292 ( V_2 ) ;
V_413:
if ( ! ( V_7 -> V_48 & V_411 ) )
F_81 ( V_7 -> V_176 ) ;
return V_17 ;
}
int F_201 ( struct V_1 * V_2 , int V_392 )
{
int V_17 ;
V_17 = F_188 ( V_2 , V_392 , NULL ) ;
if ( ! V_17 )
V_17 = F_198 ( V_2 ) ;
return V_17 ;
}
void F_202 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 . V_62 == V_380 &&
V_7 -> V_9 . V_390 == V_383 )
F_203 ( (struct V_449 * ) V_7 -> V_9 . V_406 ) ;
F_80 ( V_7 ) ;
F_81 ( V_7 -> V_70 ) ;
if ( ! ( V_7 -> V_48 & V_411 ) )
F_81 ( V_7 -> V_176 ) ;
if ( V_7 -> V_450 && V_7 -> V_450 -> V_48
& V_451 )
F_81 ( V_7 -> V_450 ) ;
}
void F_204 ( struct V_1 * V_2 )
{
F_205 ( V_2 ) ;
F_202 ( F_2 ( V_2 ) ) ;
}
