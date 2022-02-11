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
if ( ! F_55 ( V_83 ) )
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
static int F_68 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_69 ( V_7 ) ;
const struct V_114 * V_115 ;
int V_17 ;
if ( ! V_7 -> V_116 )
return 0 ;
V_115 = F_70 () ;
V_17 = V_7 -> V_116 ( V_2 , V_115 , false ) ;
if ( V_17 )
F_71 ( L_4 ) ;
return V_17 ;
}
static int F_72 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_69 ( V_7 ) ;
int V_17 ;
if ( ! V_7 -> V_116 || ! V_7 -> V_117 )
return 0 ;
if ( V_7 -> V_118 ) {
T_8 V_119 [ V_120 ] = {
V_7 -> V_121 ,
} ;
V_17 = V_7 -> V_122 ( V_2 , V_7 ,
V_123 ,
V_119 ) ;
if ( V_17 )
goto V_124;
}
V_17 = V_7 -> V_116 ( V_2 , V_7 -> V_117 , false ) ;
V_124:
return V_17 ;
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_69 ( V_7 ) ;
int V_125 , V_62 , V_17 ;
if ( ! V_7 -> V_116 )
return 0 ;
V_125 = F_74 ( V_7 ) ;
if ( V_125 == V_126 ) {
if ( ! V_7 -> V_121 )
return 0 ;
V_125 = F_75 ( V_7 -> V_121 , 0 ) ;
}
V_7 -> V_117 = F_76 ( sizeof( * V_7 -> V_117 ) ,
V_127 ) ;
if ( ! V_7 -> V_117 )
return - V_128 ;
for ( V_62 = F_77 ( V_125 ) - 1 ; V_62 >= 0 ; V_62 -- ) {
V_17 = F_78 ( V_7 , V_7 -> V_117 ,
V_129 , V_62 ) ;
if ( V_17 )
continue;
V_17 = V_7 -> V_116 ( V_2 , V_7 -> V_117 ,
true ) ;
if ( ! V_17 ) {
V_7 -> V_121 = V_62 ;
break;
}
}
return 0 ;
}
static void F_79 ( struct V_6 * V_7 )
{
F_80 ( V_7 -> V_117 ) ;
}
int F_81 ( struct V_6 * V_7 , int V_28 )
{
struct V_1 * V_2 = F_69 ( V_7 ) ;
int V_17 ;
V_17 = F_68 ( V_7 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_130 ( V_2 , V_28 ) ;
V_7 -> V_50 ( V_2 , V_98 , - 1 , - 1 ) ;
V_7 -> V_130 ( V_2 , - 1 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
V_17 = F_72 ( V_7 ) ;
V_7 -> V_130 ( V_2 , - 1 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , T_1 V_15 ,
T_2 V_16 , int V_131 )
{
int V_17 = 0 ;
int V_113 , V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_38 = V_15 >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_132 , - 1 , V_38 & V_7 -> V_47 ) ;
V_38 = ( V_15 + V_16 ) >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_133 , - 1 ,
( V_38 | V_131 ) & V_7 -> V_47 ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
if ( V_113 & V_135 ) {
F_7 ( L_5 ,
V_19 , V_113 ) ;
V_17 = - V_136 ;
}
return V_17 ;
}
int F_83 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 )
{
int V_17 = 0 ;
int V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_6 ,
V_19 , ( unsigned long long ) V_15 , V_16 ) ;
if ( F_6 ( V_2 , V_15 , V_16 ) )
return - V_20 ;
if ( V_15 + V_16 == V_2 -> V_137 )
V_16 -= V_2 -> V_44 ;
F_37 ( V_2 , V_138 ) ;
V_28 = V_15 >> V_7 -> V_139 ;
F_81 ( V_7 , V_28 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_7 ,
V_19 ) ;
V_17 = - V_136 ;
goto V_140;
}
V_17 = F_82 ( V_2 , V_15 , V_16 , 0 ) ;
V_140:
V_7 -> V_130 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
int F_84 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 )
{
int V_17 = 0 ;
int V_28 , V_113 , V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_6 ,
V_19 , ( unsigned long long ) V_15 , V_16 ) ;
if ( F_6 ( V_2 , V_15 , V_16 ) )
return - V_20 ;
F_37 ( V_2 , V_141 ) ;
V_28 = V_15 >> V_7 -> V_139 ;
F_81 ( V_7 , V_28 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_7 ,
V_19 ) ;
V_113 = V_142 ;
V_17 = - V_136 ;
goto V_140;
}
V_38 = V_15 >> V_7 -> V_46 ;
V_7 -> V_50 ( V_2 , V_143 , - 1 , V_38 & V_7 -> V_47 ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
if ( V_113 & V_135 ) {
F_7 ( L_5 ,
V_19 , V_113 ) ;
V_17 = - V_136 ;
goto V_140;
}
V_17 = F_82 ( V_2 , V_15 , V_16 , 0x1 ) ;
V_140:
V_7 -> V_130 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_85 ( void * V_35 , int V_16 , int V_144 )
{
const unsigned char * V_145 = V_35 ;
int V_146 = 0 ;
int V_147 ;
for (; V_16 && ( ( V_148 ) V_145 ) % sizeof( long ) ;
V_16 -- , V_145 ++ ) {
V_147 = F_32 ( * V_145 ) ;
V_146 += V_149 - V_147 ;
if ( F_86 ( V_146 > V_144 ) )
return - V_150 ;
}
for (; V_16 >= sizeof( long ) ;
V_16 -= sizeof( long ) , V_145 += sizeof( long ) ) {
V_147 = F_87 ( * ( ( unsigned long * ) V_145 ) ) ;
V_146 += V_151 - V_147 ;
if ( F_86 ( V_146 > V_144 ) )
return - V_150 ;
}
for (; V_16 > 0 ; V_16 -- , V_145 ++ ) {
V_147 = F_32 ( * V_145 ) ;
V_146 += V_149 - V_147 ;
if ( F_86 ( V_146 > V_144 ) )
return - V_150 ;
}
return V_146 ;
}
int F_88 ( void * V_152 , int V_153 ,
void * V_9 , int V_154 ,
void * V_155 , int V_156 ,
int V_144 )
{
int V_157 = 0 , V_158 = 0 , V_159 = 0 ;
V_157 = F_85 ( V_152 , V_153 ,
V_144 ) ;
if ( V_157 < 0 )
return V_157 ;
V_144 -= V_157 ;
V_158 = F_85 ( V_9 , V_154 , V_144 ) ;
if ( V_158 < 0 )
return V_158 ;
V_144 -= V_158 ;
V_159 = F_85 ( V_155 , V_156 ,
V_144 ) ;
if ( V_159 < 0 )
return V_159 ;
if ( V_157 )
memset ( V_152 , 0xff , V_153 ) ;
if ( V_158 )
memset ( V_9 , 0xff , V_154 ) ;
if ( V_159 )
memset ( V_155 , 0xff , V_156 ) ;
return V_157 + V_158 + V_159 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_160 , int V_38 )
{
V_7 -> V_161 ( V_2 , V_35 , V_2 -> V_45 ) ;
if ( V_160 )
V_7 -> V_161 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_35 ,
int V_160 , int V_38 )
{
int V_163 = V_7 -> V_9 . V_137 ;
int V_164 = V_7 -> V_9 . V_165 ;
T_3 * V_166 = V_7 -> V_162 ;
int V_167 , V_137 ;
for ( V_167 = V_7 -> V_9 . V_167 ; V_167 > 0 ; V_167 -- ) {
V_7 -> V_161 ( V_2 , V_35 , V_163 ) ;
V_35 += V_163 ;
if ( V_7 -> V_9 . V_168 ) {
V_7 -> V_161 ( V_2 , V_166 , V_7 -> V_9 . V_168 ) ;
V_166 += V_7 -> V_9 . V_168 ;
}
V_7 -> V_161 ( V_2 , V_166 , V_164 ) ;
V_166 += V_164 ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_161 ( V_2 , V_166 , V_7 -> V_9 . V_169 ) ;
V_166 += V_7 -> V_9 . V_169 ;
}
}
V_137 = V_2 -> V_14 - ( V_166 - V_7 -> V_162 ) ;
if ( V_137 )
V_7 -> V_161 ( V_2 , V_166 , V_137 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_160 , int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 , V_17 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
T_3 * V_37 = V_35 ;
T_3 * V_171 = V_7 -> V_172 -> V_173 ;
T_3 * V_174 = V_7 -> V_172 -> V_175 ;
unsigned int V_176 = 0 ;
V_7 -> V_9 . V_177 ( V_2 , V_7 , V_35 , 1 , V_38 ) ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 )
V_7 -> V_9 . V_178 ( V_2 , V_37 , & V_171 [ V_40 ] ) ;
V_17 = F_92 ( V_2 , V_174 , V_7 -> V_162 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_170 = V_7 -> V_9 . V_167 ;
V_37 = V_35 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
int V_179 ;
V_179 = V_7 -> V_9 . V_180 ( V_2 , V_37 , & V_174 [ V_40 ] , & V_171 [ V_40 ] ) ;
if ( V_179 < 0 ) {
V_2 -> V_71 . V_181 ++ ;
} else {
V_2 -> V_71 . V_182 += V_179 ;
V_176 = F_93 (unsigned int, max_bitflips, stat) ;
}
}
return V_176 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_183 , T_9 V_184 , T_3 * V_185 ,
int V_38 )
{
int V_186 , V_187 , V_188 , V_17 ;
T_3 * V_37 ;
int V_189 , V_40 , V_190 = 0 ;
int V_191 , V_192 , V_193 , V_194 ;
int V_195 = ( V_7 -> V_48 & V_49 ) ? 2 : 1 ;
int V_196 , V_3 = 0 ;
unsigned int V_176 = 0 ;
struct V_4 V_5 = { } ;
V_186 = V_183 / V_7 -> V_9 . V_137 ;
V_187 = ( V_183 + V_184 - 1 ) / V_7 -> V_9 . V_137 ;
V_188 = V_187 - V_186 + 1 ;
V_196 = V_186 * V_7 -> V_9 . V_165 ;
V_191 = V_188 * V_7 -> V_9 . V_137 ;
V_192 = V_188 * V_7 -> V_9 . V_165 ;
V_189 = V_186 * V_7 -> V_9 . V_137 ;
if ( V_189 != 0 )
V_7 -> V_50 ( V_2 , V_104 , V_189 , - 1 ) ;
V_37 = V_185 + V_189 ;
V_7 -> V_161 ( V_2 , V_37 , V_191 ) ;
for ( V_40 = 0 ; V_40 < V_192 ; V_40 += V_7 -> V_9 . V_165 , V_37 += V_7 -> V_9 . V_137 )
V_7 -> V_9 . V_178 ( V_2 , V_37 , & V_7 -> V_172 -> V_173 [ V_40 ] ) ;
V_17 = F_95 ( V_2 , V_196 , & V_3 , & V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_5 . V_12 < V_192 )
V_190 = 1 ;
if ( V_190 ) {
V_7 -> V_50 ( V_2 , V_104 , V_2 -> V_45 , - 1 ) ;
V_7 -> V_161 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
} else {
V_194 = V_5 . V_11 & ~ ( V_195 - 1 ) ;
V_193 = V_192 ;
if ( V_5 . V_11 & ( V_195 - 1 ) )
V_193 ++ ;
if ( ( V_5 . V_11 + ( V_188 * V_7 -> V_9 . V_165 ) ) &
( V_195 - 1 ) )
V_193 ++ ;
V_7 -> V_50 ( V_2 , V_104 ,
V_2 -> V_45 + V_194 , - 1 ) ;
V_7 -> V_161 ( V_2 , & V_7 -> V_162 [ V_194 ] , V_193 ) ;
}
V_17 = F_92 ( V_2 , V_7 -> V_172 -> V_175 ,
V_7 -> V_162 , V_196 , V_192 ) ;
if ( V_17 )
return V_17 ;
V_37 = V_185 + V_189 ;
for ( V_40 = 0 ; V_40 < V_192 ; V_40 += V_7 -> V_9 . V_165 , V_37 += V_7 -> V_9 . V_137 ) {
int V_179 ;
V_179 = V_7 -> V_9 . V_180 ( V_2 , V_37 ,
& V_7 -> V_172 -> V_175 [ V_40 ] , & V_7 -> V_172 -> V_173 [ V_40 ] ) ;
if ( V_179 == - V_150 &&
( V_7 -> V_9 . V_48 & V_197 ) ) {
V_179 = F_88 ( V_37 , V_7 -> V_9 . V_137 ,
& V_7 -> V_172 -> V_175 [ V_40 ] ,
V_7 -> V_9 . V_165 ,
NULL , 0 ,
V_7 -> V_9 . V_198 ) ;
}
if ( V_179 < 0 ) {
V_2 -> V_71 . V_181 ++ ;
} else {
V_2 -> V_71 . V_182 += V_179 ;
V_176 = F_93 (unsigned int, max_bitflips, stat) ;
}
}
return V_176 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_160 , int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 , V_17 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
T_3 * V_37 = V_35 ;
T_3 * V_171 = V_7 -> V_172 -> V_173 ;
T_3 * V_174 = V_7 -> V_172 -> V_175 ;
unsigned int V_176 = 0 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
V_7 -> V_9 . V_199 ( V_2 , V_200 ) ;
V_7 -> V_161 ( V_2 , V_37 , V_163 ) ;
V_7 -> V_9 . V_178 ( V_2 , V_37 , & V_171 [ V_40 ] ) ;
}
V_7 -> V_161 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
V_17 = F_92 ( V_2 , V_174 , V_7 -> V_162 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_170 = V_7 -> V_9 . V_167 ;
V_37 = V_35 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
int V_179 ;
V_179 = V_7 -> V_9 . V_180 ( V_2 , V_37 , & V_174 [ V_40 ] , & V_171 [ V_40 ] ) ;
if ( V_179 == - V_150 &&
( V_7 -> V_9 . V_48 & V_197 ) ) {
V_179 = F_88 ( V_37 , V_163 ,
& V_174 [ V_40 ] , V_164 ,
NULL , 0 ,
V_7 -> V_9 . V_198 ) ;
}
if ( V_179 < 0 ) {
V_2 -> V_71 . V_181 ++ ;
} else {
V_2 -> V_71 . V_182 += V_179 ;
V_176 = F_93 (unsigned int, max_bitflips, stat) ;
}
}
return V_176 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_35 , int V_160 , int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 , V_17 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
T_3 * V_37 = V_35 ;
T_3 * V_174 = V_7 -> V_172 -> V_175 ;
T_3 * V_171 = V_7 -> V_172 -> V_173 ;
unsigned int V_176 = 0 ;
V_7 -> V_50 ( V_2 , V_51 , 0 , V_38 ) ;
V_7 -> V_161 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
V_7 -> V_50 ( V_2 , V_90 , 0 , V_38 ) ;
V_17 = F_92 ( V_2 , V_174 , V_7 -> V_162 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
int V_179 ;
V_7 -> V_9 . V_199 ( V_2 , V_200 ) ;
V_7 -> V_161 ( V_2 , V_37 , V_163 ) ;
V_7 -> V_9 . V_178 ( V_2 , V_37 , & V_171 [ V_40 ] ) ;
V_179 = V_7 -> V_9 . V_180 ( V_2 , V_37 , & V_174 [ V_40 ] , NULL ) ;
if ( V_179 == - V_150 &&
( V_7 -> V_9 . V_48 & V_197 ) ) {
V_179 = F_88 ( V_37 , V_163 ,
& V_174 [ V_40 ] , V_164 ,
NULL , 0 ,
V_7 -> V_9 . V_198 ) ;
}
if ( V_179 < 0 ) {
V_2 -> V_71 . V_181 ++ ;
} else {
V_2 -> V_71 . V_182 += V_179 ;
V_176 = F_93 (unsigned int, max_bitflips, stat) ;
}
}
return V_176 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_35 , int V_160 , int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
int V_201 = V_164 + V_7 -> V_9 . V_168 + V_7 -> V_9 . V_169 ;
T_3 * V_37 = V_35 ;
T_3 * V_166 = V_7 -> V_162 ;
unsigned int V_176 = 0 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
int V_179 ;
V_7 -> V_9 . V_199 ( V_2 , V_200 ) ;
V_7 -> V_161 ( V_2 , V_37 , V_163 ) ;
if ( V_7 -> V_9 . V_168 ) {
V_7 -> V_161 ( V_2 , V_166 , V_7 -> V_9 . V_168 ) ;
V_166 += V_7 -> V_9 . V_168 ;
}
V_7 -> V_9 . V_199 ( V_2 , V_202 ) ;
V_7 -> V_161 ( V_2 , V_166 , V_164 ) ;
V_179 = V_7 -> V_9 . V_180 ( V_2 , V_37 , V_166 , NULL ) ;
V_166 += V_164 ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_161 ( V_2 , V_166 , V_7 -> V_9 . V_169 ) ;
V_166 += V_7 -> V_9 . V_169 ;
}
if ( V_179 == - V_150 &&
( V_7 -> V_9 . V_48 & V_197 ) ) {
V_179 = F_88 ( V_37 , V_7 -> V_9 . V_137 ,
V_166 - V_201 ,
V_201 ,
NULL , 0 ,
V_7 -> V_9 . V_198 ) ;
}
if ( V_179 < 0 ) {
V_2 -> V_71 . V_181 ++ ;
} else {
V_2 -> V_71 . V_182 += V_179 ;
V_176 = F_93 (unsigned int, max_bitflips, stat) ;
}
}
V_40 = V_2 -> V_14 - ( V_166 - V_7 -> V_162 ) ;
if ( V_40 )
V_7 -> V_161 ( V_2 , V_166 , V_40 ) ;
return V_176 ;
}
static T_3 * F_99 ( struct V_1 * V_2 , T_3 * V_166 ,
struct V_57 * V_58 , T_10 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_203 :
memcpy ( V_166 , V_7 -> V_162 + V_58 -> V_60 , V_16 ) ;
return V_166 + V_16 ;
case V_204 :
V_17 = F_100 ( V_2 , V_166 , V_7 -> V_162 ,
V_58 -> V_60 , V_16 ) ;
F_101 ( V_17 ) ;
return V_166 + V_16 ;
default:
F_19 () ;
}
return NULL ;
}
static int F_102 ( struct V_1 * V_2 , int V_205 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_8 , V_205 ) ;
if ( V_205 >= V_7 -> V_206 )
return - V_20 ;
if ( ! V_7 -> V_207 )
return - V_208 ;
return V_7 -> V_207 ( V_2 , V_205 ) ;
}
static int F_103 ( struct V_1 * V_2 , T_1 V_209 ,
struct V_57 * V_58 )
{
int V_28 , V_38 , V_210 , V_211 , V_165 , V_212 , V_160 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 = 0 ;
T_9 V_184 = V_58 -> V_16 ;
T_9 V_213 = V_58 -> V_61 ;
T_9 V_214 = F_104 ( V_2 , V_58 ) ;
T_3 * V_185 , * V_166 , * V_35 ;
int V_215 ;
unsigned int V_176 = 0 ;
int V_205 = 0 ;
bool V_216 = false ;
V_28 = ( int ) ( V_209 >> V_7 -> V_139 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
V_210 = ( int ) ( V_209 >> V_7 -> V_46 ) ;
V_38 = V_210 & V_7 -> V_47 ;
V_211 = ( int ) ( V_209 & ( V_2 -> V_45 - 1 ) ) ;
V_35 = V_58 -> V_217 ;
V_166 = V_58 -> V_59 ;
V_160 = V_166 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_218 = V_2 -> V_71 . V_181 ;
V_165 = F_105 ( V_2 -> V_45 - V_211 , V_184 ) ;
V_212 = ( V_165 == V_2 -> V_45 ) ;
if ( ! V_212 )
V_215 = 1 ;
else if ( V_7 -> V_48 & V_219 )
V_215 = ! F_106 ( V_35 ) ;
else
V_215 = 0 ;
if ( V_210 != V_7 -> V_220 || V_166 ) {
V_185 = V_215 ? V_7 -> V_172 -> V_221 : V_35 ;
if ( V_215 && V_212 )
F_7 ( L_9 ,
V_19 , V_35 ) ;
V_222:
V_7 -> V_50 ( V_2 , V_90 , 0x00 , V_38 ) ;
if ( F_86 ( V_58 -> V_62 == V_203 ) )
V_17 = V_7 -> V_9 . V_177 ( V_2 , V_7 , V_185 ,
V_160 ,
V_38 ) ;
else if ( ! V_212 && F_107 ( V_7 ) &&
! V_166 )
V_17 = V_7 -> V_9 . V_223 ( V_2 , V_7 ,
V_211 , V_165 , V_185 ,
V_38 ) ;
else
V_17 = V_7 -> V_9 . V_224 ( V_2 , V_7 , V_185 ,
V_160 , V_38 ) ;
if ( V_17 < 0 ) {
if ( V_215 )
V_7 -> V_220 = - 1 ;
break;
}
V_176 = F_93 (unsigned int, max_bitflips, ret) ;
if ( V_215 ) {
if ( ! F_107 ( V_7 ) && ! V_166 &&
! ( V_2 -> V_71 . V_181 - V_218 ) &&
( V_58 -> V_62 != V_203 ) ) {
V_7 -> V_220 = V_210 ;
V_7 -> V_225 = V_17 ;
} else {
V_7 -> V_220 = - 1 ;
}
memcpy ( V_35 , V_7 -> V_172 -> V_221 + V_211 , V_165 ) ;
}
if ( F_86 ( V_166 ) ) {
int V_226 = F_105 ( V_213 , V_214 ) ;
if ( V_226 ) {
V_166 = F_99 ( V_2 ,
V_166 , V_58 , V_226 ) ;
V_213 -= V_226 ;
}
}
if ( V_7 -> V_48 & V_227 ) {
if ( ! V_7 -> V_79 )
F_56 ( V_7 -> V_99 ) ;
else
F_47 ( V_2 ) ;
}
if ( V_2 -> V_71 . V_181 - V_218 ) {
if ( V_205 + 1 < V_7 -> V_206 ) {
V_205 ++ ;
V_17 = F_102 ( V_2 ,
V_205 ) ;
if ( V_17 < 0 )
break;
V_2 -> V_71 . V_181 = V_218 ;
goto V_222;
} else {
V_216 = true ;
}
}
V_35 += V_165 ;
} else {
memcpy ( V_35 , V_7 -> V_172 -> V_221 + V_211 , V_165 ) ;
V_35 += V_165 ;
V_176 = F_93 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_184 -= V_165 ;
if ( V_205 ) {
V_17 = F_102 ( V_2 , 0 ) ;
if ( V_17 < 0 )
break;
V_205 = 0 ;
}
if ( ! V_184 )
break;
V_211 = 0 ;
V_210 ++ ;
V_38 = V_210 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_130 ( V_2 , - 1 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
}
}
V_7 -> V_130 ( V_2 , - 1 ) ;
V_58 -> V_228 = V_58 -> V_16 - ( T_10 ) V_184 ;
if ( V_166 )
V_58 -> V_229 = V_58 -> V_61 - V_213 ;
if ( V_17 < 0 )
return V_17 ;
if ( V_216 )
return - V_150 ;
return V_176 ;
}
static int F_108 ( struct V_1 * V_2 , T_1 V_209 , T_10 V_16 ,
T_10 * V_228 , T_3 * V_35 )
{
struct V_57 V_58 ;
int V_17 ;
F_37 ( V_2 , V_230 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_217 = V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_103 ( V_2 , V_209 , & V_58 ) ;
* V_228 = V_58 . V_228 ;
F_8 ( V_2 ) ;
return V_17 ;
}
int F_109 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_38 )
{
V_7 -> V_50 ( V_2 , V_51 , 0 , V_38 ) ;
V_7 -> V_161 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_38 )
{
int V_12 = V_2 -> V_14 ;
int V_231 = V_7 -> V_9 . V_165 + V_7 -> V_9 . V_168 + V_7 -> V_9 . V_169 ;
int V_163 = V_7 -> V_9 . V_137 ;
T_3 * V_185 = V_7 -> V_162 ;
int V_40 , V_226 , V_232 = 0 , V_233 ;
V_7 -> V_50 ( V_2 , V_90 , V_7 -> V_9 . V_137 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_7 -> V_9 . V_167 ; V_40 ++ ) {
if ( V_232 ) {
V_233 = V_163 + V_40 * ( V_163 + V_231 ) ;
if ( V_2 -> V_45 > 512 )
V_7 -> V_50 ( V_2 , V_104 , V_233 , - 1 ) ;
else
V_7 -> V_50 ( V_2 , V_90 , V_233 , V_38 ) ;
} else
V_232 = 1 ;
V_226 = F_111 ( int , V_12 , V_231 ) ;
V_7 -> V_161 ( V_2 , V_185 , V_226 ) ;
V_185 += V_226 ;
V_12 -= V_226 ;
}
if ( V_12 > 0 )
V_7 -> V_161 ( V_2 , V_185 , V_12 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_38 )
{
int V_113 = 0 ;
const T_3 * V_35 = V_7 -> V_162 ;
int V_12 = V_2 -> V_14 ;
V_7 -> V_50 ( V_2 , V_88 , V_2 -> V_45 , V_38 ) ;
V_7 -> V_33 ( V_2 , V_35 , V_12 ) ;
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
return V_113 & V_135 ? - V_136 : 0 ;
}
int F_113 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_38 )
{
int V_231 = V_7 -> V_9 . V_165 + V_7 -> V_9 . V_168 + V_7 -> V_9 . V_169 ;
int V_163 = V_7 -> V_9 . V_137 , V_12 = V_2 -> V_14 ;
int V_40 , V_16 , V_233 , V_113 = 0 , V_234 = 0 , V_167 = V_7 -> V_9 . V_167 ;
const T_3 * V_185 = V_7 -> V_162 ;
if ( ! V_7 -> V_9 . V_168 && ! V_7 -> V_9 . V_169 ) {
V_233 = V_167 * ( V_163 + V_231 ) ;
V_167 = 0 ;
} else
V_233 = V_163 ;
V_7 -> V_50 ( V_2 , V_88 , V_233 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_167 ; V_40 ++ ) {
if ( V_234 ) {
if ( V_2 -> V_45 <= 512 ) {
T_9 V_235 = 0xFFFFFFFF ;
V_16 = V_163 ;
while ( V_16 > 0 ) {
int V_236 = F_111 ( int , V_16 , 4 ) ;
V_7 -> V_33 ( V_2 , ( T_3 * ) & V_235 ,
V_236 ) ;
V_16 -= V_236 ;
}
} else {
V_233 = V_163 + V_40 * ( V_163 + V_231 ) ;
V_7 -> V_50 ( V_2 , V_103 , V_233 , - 1 ) ;
}
} else
V_234 = 1 ;
V_16 = F_111 ( int , V_12 , V_231 ) ;
V_7 -> V_33 ( V_2 , V_185 , V_16 ) ;
V_185 += V_16 ;
V_12 -= V_16 ;
}
if ( V_12 > 0 )
V_7 -> V_33 ( V_2 , V_185 , V_12 ) ;
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
return V_113 & V_135 ? - V_136 : 0 ;
}
static int F_114 ( struct V_1 * V_2 , T_1 V_209 ,
struct V_57 * V_58 )
{
int V_38 , V_210 , V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_237 V_238 ;
int V_184 = V_58 -> V_61 ;
int V_16 ;
T_3 * V_35 = V_58 -> V_59 ;
int V_17 = 0 ;
F_7 ( L_10 ,
V_19 , ( unsigned long long ) V_209 , V_184 ) ;
V_238 = V_2 -> V_71 ;
V_16 = F_104 ( V_2 , V_58 ) ;
if ( F_86 ( V_58 -> V_60 >= V_16 ) ) {
F_7 ( L_11 ,
V_19 ) ;
return - V_20 ;
}
if ( F_86 ( V_209 >= V_2 -> V_137 ||
V_58 -> V_60 + V_184 > ( ( V_2 -> V_137 >> V_7 -> V_46 ) -
( V_209 >> V_7 -> V_46 ) ) * V_16 ) ) {
F_7 ( L_12 ,
V_19 ) ;
return - V_20 ;
}
V_28 = ( int ) ( V_209 >> V_7 -> V_139 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
V_210 = ( int ) ( V_209 >> V_7 -> V_46 ) ;
V_38 = V_210 & V_7 -> V_47 ;
while ( 1 ) {
if ( V_58 -> V_62 == V_203 )
V_17 = V_7 -> V_9 . V_239 ( V_2 , V_7 , V_38 ) ;
else
V_17 = V_7 -> V_9 . V_240 ( V_2 , V_7 , V_38 ) ;
if ( V_17 < 0 )
break;
V_16 = F_105 ( V_16 , V_184 ) ;
V_35 = F_99 ( V_2 , V_35 , V_58 , V_16 ) ;
if ( V_7 -> V_48 & V_227 ) {
if ( ! V_7 -> V_79 )
F_56 ( V_7 -> V_99 ) ;
else
F_47 ( V_2 ) ;
}
V_184 -= V_16 ;
if ( ! V_184 )
break;
V_210 ++ ;
V_38 = V_210 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_130 ( V_2 , - 1 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
}
}
V_7 -> V_130 ( V_2 , - 1 ) ;
V_58 -> V_229 = V_58 -> V_61 - V_184 ;
if ( V_17 < 0 )
return V_17 ;
if ( V_2 -> V_71 . V_181 - V_238 . V_181 )
return - V_150 ;
return V_2 -> V_71 . V_182 - V_238 . V_182 ? - V_241 : 0 ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_209 ,
struct V_57 * V_58 )
{
int V_17 ;
V_58 -> V_228 = 0 ;
if ( V_58 -> V_217 && ( V_209 + V_58 -> V_16 ) > V_2 -> V_137 ) {
F_7 ( L_12 ,
V_19 ) ;
return - V_20 ;
}
if ( V_58 -> V_62 != V_63 &&
V_58 -> V_62 != V_204 &&
V_58 -> V_62 != V_203 )
return - V_242 ;
F_37 ( V_2 , V_230 ) ;
if ( ! V_58 -> V_217 )
V_17 = F_114 ( V_2 , V_209 , V_58 ) ;
else
V_17 = F_103 ( V_2 , V_209 , V_58 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_116 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_160 , int V_38 )
{
V_7 -> V_33 ( V_2 , V_35 , V_2 -> V_45 ) ;
if ( V_160 )
V_7 -> V_33 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_35 , int V_160 ,
int V_38 )
{
int V_163 = V_7 -> V_9 . V_137 ;
int V_164 = V_7 -> V_9 . V_165 ;
T_3 * V_166 = V_7 -> V_162 ;
int V_167 , V_137 ;
for ( V_167 = V_7 -> V_9 . V_167 ; V_167 > 0 ; V_167 -- ) {
V_7 -> V_33 ( V_2 , V_35 , V_163 ) ;
V_35 += V_163 ;
if ( V_7 -> V_9 . V_168 ) {
V_7 -> V_33 ( V_2 , V_166 , V_7 -> V_9 . V_168 ) ;
V_166 += V_7 -> V_9 . V_168 ;
}
V_7 -> V_33 ( V_2 , V_166 , V_164 ) ;
V_166 += V_164 ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_33 ( V_2 , V_166 , V_7 -> V_9 . V_169 ) ;
V_166 += V_7 -> V_9 . V_169 ;
}
}
V_137 = V_2 -> V_14 - ( V_166 - V_7 -> V_162 ) ;
if ( V_137 )
V_7 -> V_33 ( V_2 , V_166 , V_137 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_160 ,
int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 , V_17 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
T_3 * V_171 = V_7 -> V_172 -> V_173 ;
const T_3 * V_37 = V_35 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 )
V_7 -> V_9 . V_178 ( V_2 , V_37 , & V_171 [ V_40 ] ) ;
V_17 = F_119 ( V_2 , V_171 , V_7 -> V_162 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
return V_7 -> V_9 . V_243 ( V_2 , V_7 , V_35 , 1 , V_38 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_35 , int V_160 ,
int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 , V_17 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
T_3 * V_171 = V_7 -> V_172 -> V_173 ;
const T_3 * V_37 = V_35 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
V_7 -> V_9 . V_199 ( V_2 , V_244 ) ;
V_7 -> V_33 ( V_2 , V_37 , V_163 ) ;
V_7 -> V_9 . V_178 ( V_2 , V_37 , & V_171 [ V_40 ] ) ;
}
V_17 = F_119 ( V_2 , V_171 , V_7 -> V_162 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_33 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_9 V_11 ,
T_9 V_245 , const T_3 * V_35 ,
int V_160 , int V_38 )
{
T_3 * V_246 = V_7 -> V_162 ;
T_3 * V_171 = V_7 -> V_172 -> V_173 ;
int V_247 = V_7 -> V_9 . V_137 ;
int V_248 = V_7 -> V_9 . V_165 ;
int V_249 = V_7 -> V_9 . V_167 ;
T_9 V_186 = V_11 / V_247 ;
T_9 V_187 = ( V_11 + V_245 - 1 ) / V_247 ;
int V_250 = V_2 -> V_14 / V_249 ;
int V_251 , V_17 ;
for ( V_251 = 0 ; V_251 < V_249 ; V_251 ++ ) {
V_7 -> V_9 . V_199 ( V_2 , V_244 ) ;
V_7 -> V_33 ( V_2 , V_35 , V_247 ) ;
if ( ( V_251 < V_186 ) || ( V_251 > V_187 ) )
memset ( V_171 , 0xff , V_248 ) ;
else
V_7 -> V_9 . V_178 ( V_2 , V_35 , V_171 ) ;
if ( ! V_160 || ( V_251 < V_186 ) || ( V_251 > V_187 ) )
memset ( V_246 , 0xff , V_250 ) ;
V_35 += V_247 ;
V_171 += V_248 ;
V_246 += V_250 ;
}
V_171 = V_7 -> V_172 -> V_173 ;
V_17 = F_119 ( V_2 , V_171 , V_7 -> V_162 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_33 ( V_2 , V_7 -> V_162 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_35 , int V_160 ,
int V_38 )
{
int V_40 , V_163 = V_7 -> V_9 . V_137 ;
int V_164 = V_7 -> V_9 . V_165 ;
int V_170 = V_7 -> V_9 . V_167 ;
const T_3 * V_37 = V_35 ;
T_3 * V_166 = V_7 -> V_162 ;
for ( V_40 = 0 ; V_170 ; V_170 -- , V_40 += V_164 , V_37 += V_163 ) {
V_7 -> V_9 . V_199 ( V_2 , V_244 ) ;
V_7 -> V_33 ( V_2 , V_37 , V_163 ) ;
if ( V_7 -> V_9 . V_168 ) {
V_7 -> V_33 ( V_2 , V_166 , V_7 -> V_9 . V_168 ) ;
V_166 += V_7 -> V_9 . V_168 ;
}
V_7 -> V_9 . V_178 ( V_2 , V_37 , V_166 ) ;
V_7 -> V_33 ( V_2 , V_166 , V_164 ) ;
V_166 += V_164 ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_33 ( V_2 , V_166 , V_7 -> V_9 . V_169 ) ;
V_166 += V_7 -> V_9 . V_169 ;
}
}
V_40 = V_2 -> V_14 - ( V_166 - V_7 -> V_162 ) ;
if ( V_40 )
V_7 -> V_33 ( V_2 , V_166 , V_40 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_11 , int V_245 , const T_3 * V_35 ,
int V_160 , int V_38 , int V_252 , int V_253 )
{
int V_113 , V_254 ;
if ( ! ( V_7 -> V_48 & V_255 ) &&
V_7 -> V_9 . V_256 )
V_254 = V_11 || ( V_245 < V_2 -> V_45 ) ;
else
V_254 = 0 ;
V_7 -> V_50 ( V_2 , V_88 , 0x00 , V_38 ) ;
if ( F_86 ( V_253 ) )
V_113 = V_7 -> V_9 . V_243 ( V_2 , V_7 , V_35 ,
V_160 , V_38 ) ;
else if ( V_254 )
V_113 = V_7 -> V_9 . V_256 ( V_2 , V_7 , V_11 , V_245 ,
V_35 , V_160 , V_38 ) ;
else
V_113 = V_7 -> V_9 . V_257 ( V_2 , V_7 , V_35 , V_160 ,
V_38 ) ;
if ( V_113 < 0 )
return V_113 ;
V_252 = 0 ;
if ( ! V_252 || ! F_124 ( V_7 ) ) {
V_7 -> V_50 ( V_2 , V_95 , - 1 , - 1 ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
if ( ( V_113 & V_135 ) && ( V_7 -> V_258 ) )
V_113 = V_7 -> V_258 ( V_2 , V_7 , V_68 , V_113 ,
V_38 ) ;
if ( V_113 & V_135 )
return - V_136 ;
} else {
V_7 -> V_50 ( V_2 , V_102 , - 1 , - 1 ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
}
return 0 ;
}
static T_3 * F_125 ( struct V_1 * V_2 , T_3 * V_166 , T_10 V_16 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 ;
memset ( V_7 -> V_162 , 0xff , V_2 -> V_14 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_203 :
memcpy ( V_7 -> V_162 + V_58 -> V_60 , V_166 , V_16 ) ;
return V_166 + V_16 ;
case V_204 :
V_17 = F_126 ( V_2 , V_166 , V_7 -> V_162 ,
V_58 -> V_60 , V_16 ) ;
F_101 ( V_17 ) ;
return V_166 + V_16 ;
default:
F_19 () ;
}
return NULL ;
}
static int F_127 ( struct V_1 * V_2 , T_1 V_259 ,
struct V_57 * V_58 )
{
int V_28 , V_210 , V_38 , V_260 , V_84 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_9 V_261 = V_58 -> V_16 ;
T_9 V_262 = V_58 -> V_61 ;
T_9 V_263 = F_104 ( V_2 , V_58 ) ;
T_3 * V_166 = V_58 -> V_59 ;
T_3 * V_35 = V_58 -> V_217 ;
int V_17 ;
int V_160 = V_166 ? 1 : 0 ;
V_58 -> V_228 = 0 ;
if ( ! V_261 )
return 0 ;
if ( F_128 ( V_259 ) || F_128 ( V_58 -> V_16 ) ) {
F_129 ( L_13 ,
V_19 ) ;
return - V_20 ;
}
V_84 = V_259 & ( V_2 -> V_45 - 1 ) ;
V_28 = ( int ) ( V_259 >> V_7 -> V_139 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
V_17 = - V_136 ;
goto V_264;
}
V_210 = ( int ) ( V_259 >> V_7 -> V_46 ) ;
V_38 = V_210 & V_7 -> V_47 ;
V_260 = ( 1 << ( V_7 -> V_18 - V_7 -> V_46 ) ) - 1 ;
if ( V_259 <= ( ( T_1 ) V_7 -> V_220 << V_7 -> V_46 ) &&
( ( T_1 ) V_7 -> V_220 << V_7 -> V_46 ) < ( V_259 + V_58 -> V_16 ) )
V_7 -> V_220 = - 1 ;
if ( V_166 && V_58 -> V_60 && ( V_58 -> V_60 + V_58 -> V_61 > V_263 ) ) {
V_17 = - V_20 ;
goto V_264;
}
while ( 1 ) {
int V_165 = V_2 -> V_45 ;
int V_252 = V_261 > V_165 && V_38 != V_260 ;
T_3 * V_265 = V_35 ;
int V_215 ;
int V_266 = ( V_84 || V_261 < V_2 -> V_45 ) ;
if ( V_266 )
V_215 = 1 ;
else if ( V_7 -> V_48 & V_219 )
V_215 = ! F_106 ( V_35 ) ;
else
V_215 = 0 ;
if ( V_215 ) {
F_7 ( L_14 ,
V_19 , V_35 ) ;
V_252 = 0 ;
if ( V_266 )
V_165 = F_111 ( int , V_165 - V_84 , V_261 ) ;
V_7 -> V_220 = - 1 ;
memset ( V_7 -> V_172 -> V_221 , 0xff , V_2 -> V_45 ) ;
memcpy ( & V_7 -> V_172 -> V_221 [ V_84 ] , V_35 , V_165 ) ;
V_265 = V_7 -> V_172 -> V_221 ;
}
if ( F_86 ( V_166 ) ) {
T_10 V_16 = F_105 ( V_262 , V_263 ) ;
V_166 = F_125 ( V_2 , V_166 , V_16 , V_58 ) ;
V_262 -= V_16 ;
} else {
memset ( V_7 -> V_162 , 0xff , V_2 -> V_14 ) ;
}
V_17 = V_7 -> V_257 ( V_2 , V_7 , V_84 , V_165 , V_265 ,
V_160 , V_38 , V_252 ,
( V_58 -> V_62 == V_203 ) ) ;
if ( V_17 )
break;
V_261 -= V_165 ;
if ( ! V_261 )
break;
V_84 = 0 ;
V_35 += V_165 ;
V_210 ++ ;
V_38 = V_210 & V_7 -> V_47 ;
if ( ! V_38 ) {
V_28 ++ ;
V_7 -> V_130 ( V_2 , - 1 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
}
}
V_58 -> V_228 = V_58 -> V_16 - V_261 ;
if ( F_86 ( V_166 ) )
V_58 -> V_229 = V_58 -> V_61 ;
V_264:
V_7 -> V_130 ( V_2 , - 1 ) ;
return V_17 ;
}
static int F_130 ( struct V_1 * V_2 , T_1 V_259 , T_10 V_16 ,
T_10 * V_228 , const T_3 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_57 V_58 ;
int V_17 ;
F_65 ( V_2 , V_7 , 400 ) ;
F_59 ( V_7 , V_2 , V_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_217 = ( T_3 * ) V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_127 ( V_2 , V_259 , & V_58 ) ;
* V_228 = V_58 . V_228 ;
return V_17 ;
}
static int F_131 ( struct V_1 * V_2 , T_1 V_259 , T_10 V_16 ,
T_10 * V_228 , const T_3 * V_35 )
{
struct V_57 V_58 ;
int V_17 ;
F_37 ( V_2 , V_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_16 = V_16 ;
V_58 . V_217 = ( T_3 * ) V_35 ;
V_58 . V_62 = V_63 ;
V_17 = F_127 ( V_2 , V_259 , & V_58 ) ;
* V_228 = V_58 . V_228 ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_259 ,
struct V_57 * V_58 )
{
int V_28 , V_38 , V_113 , V_16 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( L_15 ,
V_19 , ( unsigned int ) V_259 , ( int ) V_58 -> V_61 ) ;
V_16 = F_104 ( V_2 , V_58 ) ;
if ( ( V_58 -> V_60 + V_58 -> V_61 ) > V_16 ) {
F_7 ( L_16 ,
V_19 ) ;
return - V_20 ;
}
if ( F_86 ( V_58 -> V_60 >= V_16 ) ) {
F_7 ( L_17 ,
V_19 ) ;
return - V_20 ;
}
if ( F_86 ( V_259 >= V_2 -> V_137 ||
V_58 -> V_60 + V_58 -> V_61 >
( ( V_2 -> V_137 >> V_7 -> V_46 ) -
( V_259 >> V_7 -> V_46 ) ) * V_16 ) ) {
F_7 ( L_18 ,
V_19 ) ;
return - V_20 ;
}
V_28 = ( int ) ( V_259 >> V_7 -> V_139 ) ;
F_81 ( V_7 , V_28 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
V_38 = ( int ) ( V_259 >> V_7 -> V_46 ) ;
if ( F_39 ( V_2 ) ) {
V_7 -> V_130 ( V_2 , - 1 ) ;
return - V_267 ;
}
if ( V_38 == V_7 -> V_220 )
V_7 -> V_220 = - 1 ;
F_125 ( V_2 , V_58 -> V_59 , V_58 -> V_61 , V_58 ) ;
if ( V_58 -> V_62 == V_203 )
V_113 = V_7 -> V_9 . V_268 ( V_2 , V_7 , V_38 & V_7 -> V_47 ) ;
else
V_113 = V_7 -> V_9 . V_269 ( V_2 , V_7 , V_38 & V_7 -> V_47 ) ;
V_7 -> V_130 ( V_2 , - 1 ) ;
if ( V_113 )
return V_113 ;
V_58 -> V_229 = V_58 -> V_61 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_259 ,
struct V_57 * V_58 )
{
int V_17 = - V_242 ;
V_58 -> V_228 = 0 ;
if ( V_58 -> V_217 && ( V_259 + V_58 -> V_16 ) > V_2 -> V_137 ) {
F_7 ( L_18 ,
V_19 ) ;
return - V_20 ;
}
F_37 ( V_2 , V_68 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
case V_204 :
case V_203 :
break;
default:
goto V_140;
}
if ( ! V_58 -> V_217 )
V_17 = F_34 ( V_2 , V_259 , V_58 ) ;
else
V_17 = F_127 ( V_2 , V_259 , V_58 ) ;
V_140:
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_133 ( struct V_1 * V_2 , int V_38 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_50 ( V_2 , V_96 , - 1 , V_38 ) ;
V_7 -> V_50 ( V_2 , V_97 , - 1 , - 1 ) ;
return V_7 -> V_134 ( V_2 , V_7 ) ;
}
static int F_134 ( struct V_1 * V_2 , struct V_65 * V_270 )
{
return F_36 ( V_2 , V_270 , 0 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_65 * V_270 ,
int V_76 )
{
int V_38 , V_113 , V_271 , V_17 , V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_16 ;
F_7 ( L_6 ,
V_19 , ( unsigned long long ) V_270 -> V_67 ,
( unsigned long long ) V_270 -> V_16 ) ;
if ( F_6 ( V_2 , V_270 -> V_67 , V_270 -> V_16 ) )
return - V_20 ;
F_37 ( V_2 , V_272 ) ;
V_38 = ( int ) ( V_270 -> V_67 >> V_7 -> V_46 ) ;
V_28 = ( int ) ( V_270 -> V_67 >> V_7 -> V_139 ) ;
V_271 = 1 << ( V_7 -> V_18 - V_7 -> V_46 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
if ( F_39 ( V_2 ) ) {
F_7 ( L_7 ,
V_19 ) ;
V_270 -> V_24 = V_142 ;
goto V_273;
}
V_16 = V_270 -> V_16 ;
V_270 -> V_24 = V_274 ;
while ( V_16 ) {
if ( F_42 ( V_2 , ( ( T_1 ) V_38 ) <<
V_7 -> V_46 , V_76 ) ) {
F_135 ( L_19 ,
V_19 , V_38 ) ;
V_270 -> V_24 = V_142 ;
goto V_273;
}
if ( V_38 <= V_7 -> V_220 && V_7 -> V_220 <
( V_38 + V_271 ) )
V_7 -> V_220 = - 1 ;
V_113 = V_7 -> V_275 ( V_2 , V_38 & V_7 -> V_47 ) ;
if ( ( V_113 & V_135 ) && ( V_7 -> V_258 ) )
V_113 = V_7 -> V_258 ( V_2 , V_7 , V_272 ,
V_113 , V_38 ) ;
if ( V_113 & V_135 ) {
F_7 ( L_20 ,
V_19 , V_38 ) ;
V_270 -> V_24 = V_142 ;
V_270 -> V_276 =
( ( T_1 ) V_38 << V_7 -> V_46 ) ;
goto V_273;
}
V_16 -= ( 1ULL << V_7 -> V_18 ) ;
V_38 += V_271 ;
if ( V_16 && ! ( V_38 & V_7 -> V_47 ) ) {
V_28 ++ ;
V_7 -> V_130 ( V_2 , - 1 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
}
}
V_270 -> V_24 = V_277 ;
V_273:
V_17 = V_270 -> V_24 == V_277 ? 0 : - V_136 ;
V_7 -> V_130 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
if ( ! V_17 )
F_136 ( V_270 ) ;
return V_17 ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_7 ( L_21 , V_19 ) ;
F_37 ( V_2 , V_278 ) ;
F_8 ( V_2 ) ;
}
static int F_138 ( struct V_1 * V_2 , T_1 V_279 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_28 = ( int ) ( V_279 >> V_7 -> V_139 ) ;
int V_17 ;
F_37 ( V_2 , V_230 ) ;
V_7 -> V_130 ( V_2 , V_28 ) ;
V_17 = F_42 ( V_2 , V_279 , 0 ) ;
V_7 -> V_130 ( V_2 , - 1 ) ;
F_8 ( V_2 ) ;
return V_17 ;
}
static int F_139 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_17 ;
V_17 = F_138 ( V_2 , V_15 ) ;
if ( V_17 ) {
if ( V_17 > 0 )
return 0 ;
return V_17 ;
}
return F_35 ( V_2 , V_15 ) ;
}
static int F_140 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_280 )
{
int V_113 ;
int V_40 ;
if ( ! V_7 -> V_118 ||
! ( F_141 ( V_7 -> V_281 . V_282 )
& V_283 ) )
return - V_20 ;
V_7 -> V_50 ( V_2 , V_284 , V_67 , - 1 ) ;
for ( V_40 = 0 ; V_40 < V_120 ; ++ V_40 )
V_7 -> V_285 ( V_2 , V_280 [ V_40 ] ) ;
V_113 = V_7 -> V_134 ( V_2 , V_7 ) ;
if ( V_113 & V_135 )
return - V_136 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_280 )
{
int V_40 ;
if ( ! V_7 -> V_118 ||
! ( F_141 ( V_7 -> V_281 . V_282 )
& V_283 ) )
return - V_20 ;
V_7 -> V_50 ( V_2 , V_286 , V_67 , - 1 ) ;
for ( V_40 = 0 ; V_40 < V_120 ; ++ V_40 )
* V_280 ++ = V_7 -> V_54 ( V_2 ) ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , V_111 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_24 == V_111 )
F_8 ( V_2 ) ;
else
F_71 ( L_22 ,
V_19 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_37 ( V_2 , V_111 ) ;
}
static void F_146 ( struct V_6 * V_7 , int V_195 )
{
if ( ! V_7 -> V_99 )
V_7 -> V_99 = 20 ;
if ( V_7 -> V_50 == NULL )
V_7 -> V_50 = F_54 ;
if ( V_7 -> V_134 == NULL )
V_7 -> V_134 = F_66 ;
if ( ! V_7 -> V_130 )
V_7 -> V_130 = F_18 ;
if ( ! V_7 -> V_122 )
V_7 -> V_122 = F_140 ;
if ( ! V_7 -> V_287 )
V_7 -> V_287 = F_142 ;
if ( ! V_7 -> V_54 || V_7 -> V_54 == F_12 )
V_7 -> V_54 = V_195 ? F_14 : F_12 ;
if ( ! V_7 -> V_53 )
V_7 -> V_53 = F_17 ;
if ( ! V_7 -> V_77 )
V_7 -> V_77 = F_30 ;
if ( ! V_7 -> V_69 )
V_7 -> V_69 = F_33 ;
if ( ! V_7 -> V_33 || V_7 -> V_33 == F_22 )
V_7 -> V_33 = V_195 ? F_26 : F_22 ;
if ( ! V_7 -> V_285 || V_7 -> V_285 == F_20 )
V_7 -> V_285 = V_195 ? F_21 : F_20 ;
if ( ! V_7 -> V_161 || V_7 -> V_161 == F_24 )
V_7 -> V_161 = V_195 ? F_28 : F_24 ;
if ( ! V_7 -> V_288 )
V_7 -> V_288 = V_289 ;
if ( ! V_7 -> V_21 ) {
V_7 -> V_21 = & V_7 -> V_290 ;
F_147 ( V_7 -> V_21 ) ;
}
}
static void F_148 ( T_3 * V_291 , T_10 V_16 )
{
T_11 V_40 ;
V_291 [ V_16 - 1 ] = 0 ;
for ( V_40 = 0 ; V_40 < V_16 - 1 ; V_40 ++ ) {
if ( V_291 [ V_40 ] < ' ' || V_291 [ V_40 ] > 127 )
V_291 [ V_40 ] = '?' ;
}
F_149 ( V_291 ) ;
}
static T_4 F_150 ( T_4 V_292 , T_8 const * V_37 , T_10 V_16 )
{
int V_40 ;
while ( V_16 -- ) {
V_292 ^= * V_37 ++ << 8 ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
V_292 = ( V_292 << 1 ) ^ ( ( V_292 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_292 ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_293 * V_37 )
{
struct V_294 * V_295 ;
struct V_296 * V_291 ;
struct V_297 * V_9 ;
T_3 * V_298 ;
int V_17 = - V_20 ;
int V_16 ;
int V_40 ;
V_16 = F_141 ( V_37 -> V_299 ) * 16 ;
V_295 = F_152 ( V_16 , V_127 ) ;
if ( ! V_295 )
return - V_128 ;
V_7 -> V_50 ( V_2 , V_300 , 0 , - 1 ) ;
V_7 -> V_50 ( V_2 , V_104 ,
sizeof( * V_37 ) * V_37 -> V_301 , - 1 ) ;
V_7 -> V_161 ( V_2 , ( T_3 * ) V_295 , V_16 ) ;
if ( ( F_150 ( V_302 , ( ( T_3 * ) V_295 ) + 2 , V_16 - 2 )
!= F_141 ( V_295 -> V_292 ) ) ) {
F_7 ( L_23 ) ;
goto V_303;
}
if ( strncmp ( V_295 -> V_304 , L_24 , 4 ) ) {
F_7 ( L_25 ) ;
goto V_303;
}
V_298 = ( T_3 * ) ( V_295 + 1 ) ;
for ( V_40 = 0 ; V_40 < V_305 ; V_40 ++ ) {
V_291 = V_295 -> V_306 + V_40 ;
if ( V_291 -> type == V_307 )
break;
V_298 += V_291 -> V_12 * 16 ;
}
if ( V_40 == V_305 ) {
F_7 ( L_26 ) ;
goto V_303;
}
V_9 = (struct V_297 * ) V_298 ;
if ( ! V_9 -> V_308 ) {
F_7 ( L_27 ) ;
goto V_303;
}
V_7 -> V_309 = V_9 -> V_310 ;
V_7 -> V_311 = 1 << V_9 -> V_308 ;
V_17 = 0 ;
V_303:
F_80 ( V_295 ) ;
return V_17 ;
}
static int F_153 ( struct V_1 * V_2 , int V_205 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_312 [ V_120 ] = { V_205 } ;
return V_7 -> V_122 ( V_2 , V_7 , V_313 ,
V_312 ) ;
}
static void F_154 ( struct V_6 * V_7 ,
struct V_293 * V_37 )
{
struct V_314 * V_315 = ( void * ) V_37 -> V_316 ;
if ( F_141 ( V_37 -> V_317 ) < 1 )
return;
V_7 -> V_206 = V_315 -> V_318 ;
V_7 -> V_207 = F_153 ;
}
static int F_155 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_195 )
{
struct V_293 * V_37 = & V_7 -> V_281 ;
int V_40 , V_319 ;
int V_320 ;
V_7 -> V_50 ( V_2 , V_321 , 0x20 , - 1 ) ;
if ( V_7 -> V_54 ( V_2 ) != 'O' || V_7 -> V_54 ( V_2 ) != 'N' ||
V_7 -> V_54 ( V_2 ) != 'F' || V_7 -> V_54 ( V_2 ) != 'I' )
return 0 ;
V_7 -> V_50 ( V_2 , V_300 , 0 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
for ( V_319 = 0 ; V_319 < sizeof( * V_37 ) ; V_319 ++ )
( ( T_3 * ) V_37 ) [ V_319 ] = V_7 -> V_54 ( V_2 ) ;
if ( F_150 ( V_302 , ( T_3 * ) V_37 , 254 ) ==
F_141 ( V_37 -> V_292 ) ) {
break;
}
}
if ( V_40 == 3 ) {
F_71 ( L_28 ) ;
return 0 ;
}
V_320 = F_141 ( V_37 -> V_322 ) ;
if ( V_320 & ( 1 << 5 ) )
V_7 -> V_118 = 23 ;
else if ( V_320 & ( 1 << 4 ) )
V_7 -> V_118 = 22 ;
else if ( V_320 & ( 1 << 3 ) )
V_7 -> V_118 = 21 ;
else if ( V_320 & ( 1 << 2 ) )
V_7 -> V_118 = 20 ;
else if ( V_320 & ( 1 << 1 ) )
V_7 -> V_118 = 10 ;
if ( ! V_7 -> V_118 ) {
F_156 ( L_29 , V_320 ) ;
return 0 ;
}
F_148 ( V_37 -> V_323 , sizeof( V_37 -> V_323 ) ) ;
F_148 ( V_37 -> V_324 , sizeof( V_37 -> V_324 ) ) ;
if ( ! V_2 -> V_325 )
V_2 -> V_325 = V_37 -> V_324 ;
V_2 -> V_45 = F_157 ( V_37 -> V_326 ) ;
V_2 -> V_44 = 1 << ( F_77 ( F_157 ( V_37 -> V_271 ) ) - 1 ) ;
V_2 -> V_44 *= V_2 -> V_45 ;
V_2 -> V_14 = F_141 ( V_37 -> V_327 ) ;
V_7 -> V_93 = 1 << ( F_77 ( F_157 ( V_37 -> V_328 ) ) - 1 ) ;
V_7 -> V_93 *= ( T_2 ) V_2 -> V_44 * V_37 -> V_329 ;
V_7 -> V_330 = V_37 -> V_330 ;
if ( F_158 ( V_7 ) & V_331 )
* V_195 = V_49 ;
else
* V_195 = 0 ;
if ( V_37 -> V_310 != 0xff ) {
V_7 -> V_309 = V_37 -> V_310 ;
V_7 -> V_311 = 512 ;
} else if ( V_7 -> V_118 >= 21 &&
( F_158 ( V_7 ) & V_332 ) ) {
if ( V_2 -> V_45 > 512 && V_7 -> V_50 == F_54 )
V_7 -> V_50 = F_58 ;
if ( F_151 ( V_2 , V_7 , V_37 ) )
F_135 ( L_30 ) ;
} else {
F_135 ( L_31 ) ;
}
if ( V_37 -> V_333 == V_334 )
F_154 ( V_7 , V_37 ) ;
return 1 ;
}
static int F_159 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int * V_195 )
{
struct V_335 * V_37 = & V_7 -> V_336 ;
struct V_337 * V_9 ;
int V_320 ;
int V_40 , V_319 ;
V_7 -> V_50 ( V_2 , V_321 , 0x40 , - 1 ) ;
if ( V_7 -> V_54 ( V_2 ) != 'J' || V_7 -> V_54 ( V_2 ) != 'E' ||
V_7 -> V_54 ( V_2 ) != 'D' || V_7 -> V_54 ( V_2 ) != 'E' ||
V_7 -> V_54 ( V_2 ) != 'C' )
return 0 ;
V_7 -> V_50 ( V_2 , V_300 , 0x40 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
for ( V_319 = 0 ; V_319 < sizeof( * V_37 ) ; V_319 ++ )
( ( T_3 * ) V_37 ) [ V_319 ] = V_7 -> V_54 ( V_2 ) ;
if ( F_150 ( V_302 , ( T_3 * ) V_37 , 510 ) ==
F_141 ( V_37 -> V_292 ) )
break;
}
if ( V_40 == 3 ) {
F_71 ( L_32 ) ;
return 0 ;
}
V_320 = F_141 ( V_37 -> V_322 ) ;
if ( V_320 & ( 1 << 2 ) )
V_7 -> V_338 = 10 ;
else if ( V_320 & ( 1 << 1 ) )
V_7 -> V_338 = 1 ;
if ( ! V_7 -> V_338 ) {
F_156 ( L_33 , V_320 ) ;
return 0 ;
}
F_148 ( V_37 -> V_323 , sizeof( V_37 -> V_323 ) ) ;
F_148 ( V_37 -> V_324 , sizeof( V_37 -> V_324 ) ) ;
if ( ! V_2 -> V_325 )
V_2 -> V_325 = V_37 -> V_324 ;
V_2 -> V_45 = F_157 ( V_37 -> V_326 ) ;
V_2 -> V_44 = 1 << ( F_77 ( F_157 ( V_37 -> V_271 ) ) - 1 ) ;
V_2 -> V_44 *= V_2 -> V_45 ;
V_2 -> V_14 = F_141 ( V_37 -> V_327 ) ;
V_7 -> V_93 = 1 << ( F_77 ( F_157 ( V_37 -> V_328 ) ) - 1 ) ;
V_7 -> V_93 *= ( T_2 ) V_2 -> V_44 * V_37 -> V_329 ;
V_7 -> V_330 = V_37 -> V_330 ;
if ( F_160 ( V_7 ) & V_339 )
* V_195 = V_49 ;
else
* V_195 = 0 ;
V_9 = & V_37 -> V_340 [ 0 ] ;
if ( V_9 -> V_308 >= 9 ) {
V_7 -> V_309 = V_9 -> V_310 ;
V_7 -> V_311 = 1 << V_9 -> V_308 ;
} else {
F_135 ( L_27 ) ;
}
return 1 ;
}
static int F_161 ( T_8 * V_341 , int V_342 , int V_343 )
{
int V_40 , V_319 ;
for ( V_40 = 0 ; V_40 < V_343 ; V_40 ++ )
for ( V_319 = V_40 + V_343 ; V_319 < V_342 ; V_319 += V_343 )
if ( V_341 [ V_40 ] != V_341 [ V_319 ] )
return 0 ;
return 1 ;
}
static int F_162 ( T_8 * V_341 , int V_342 )
{
int V_344 , V_343 ;
for ( V_344 = V_342 - 1 ; V_344 >= 0 ; V_344 -- )
if ( V_341 [ V_344 ] )
break;
if ( V_344 < 0 )
return 0 ;
for ( V_343 = 1 ; V_343 < V_342 ; V_343 ++ )
if ( F_161 ( V_341 , V_342 , V_343 ) )
break;
if ( V_343 < V_342 )
return V_343 ;
if ( V_344 < V_342 - 1 )
return V_344 + 1 ;
return V_342 ;
}
static int F_163 ( T_8 V_345 )
{
int V_346 ;
V_346 = V_345 & V_347 ;
V_346 >>= V_348 ;
return V_346 + 1 ;
}
static void F_164 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_8 V_341 [ 8 ] , int * V_195 )
{
int V_349 , V_350 ;
V_7 -> V_330 = F_163 ( V_341 [ 2 ] ) ;
V_349 = V_341 [ 3 ] ;
V_350 = F_162 ( V_341 , 8 ) ;
if ( V_350 == 6 && V_341 [ 0 ] == V_351 &&
! F_165 ( V_7 ) && V_341 [ 5 ] != 0x00 ) {
V_2 -> V_45 = 2048 << ( V_349 & 0x03 ) ;
V_349 >>= 2 ;
switch ( ( ( V_349 >> 2 ) & 0x04 ) | ( V_349 & 0x03 ) ) {
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
V_349 >>= 2 ;
V_2 -> V_44 = ( 128 * 1024 ) <<
( ( ( V_349 >> 1 ) & 0x04 ) | ( V_349 & 0x03 ) ) ;
* V_195 = 0 ;
} else if ( V_350 == 6 && V_341 [ 0 ] == V_352 &&
! F_165 ( V_7 ) ) {
unsigned int V_353 ;
V_2 -> V_45 = 2048 << ( V_349 & 0x03 ) ;
V_349 >>= 2 ;
switch ( ( ( V_349 >> 2 ) & 0x04 ) | ( V_349 & 0x03 ) ) {
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
V_349 >>= 2 ;
V_353 = ( ( V_349 >> 1 ) & 0x04 ) | ( V_349 & 0x03 ) ;
if ( V_353 < 0x03 )
V_2 -> V_44 = ( 128 * 1024 ) << V_353 ;
else if ( V_353 == 0x03 )
V_2 -> V_44 = 768 * 1024 ;
else
V_2 -> V_44 = ( 64 * 1024 ) << V_353 ;
* V_195 = 0 ;
} else {
V_2 -> V_45 = 1024 << ( V_349 & 0x03 ) ;
V_349 >>= 2 ;
V_2 -> V_14 = ( 8 << ( V_349 & 0x01 ) ) *
( V_2 -> V_45 >> 9 ) ;
V_349 >>= 2 ;
V_2 -> V_44 = ( 64 * 1024 ) << ( V_349 & 0x03 ) ;
V_349 >>= 2 ;
* V_195 = ( V_349 & 0x01 ) ? V_49 : 0 ;
if ( V_350 >= 6 && V_341 [ 0 ] == V_354 &&
F_165 ( V_7 ) &&
( V_341 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_341 [ 4 ] & 0x80 ) ) {
V_2 -> V_14 = 32 * V_2 -> V_45 >> 9 ;
}
}
}
static void F_166 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_355 * type , T_8 V_341 [ 8 ] ,
int * V_195 )
{
int V_356 = V_341 [ 0 ] ;
V_2 -> V_44 = type -> V_44 ;
V_2 -> V_45 = type -> V_357 ;
V_2 -> V_14 = V_2 -> V_45 / 32 ;
* V_195 = type -> V_48 & V_49 ;
V_7 -> V_330 = 1 ;
if ( V_356 == V_358 && V_341 [ 4 ] != 0x00 && V_341 [ 5 ] == 0x00
&& V_341 [ 6 ] == 0x00 && V_341 [ 7 ] == 0x00
&& V_2 -> V_45 == 512 ) {
V_2 -> V_44 = 128 * 1024 ;
V_2 -> V_44 <<= ( ( V_341 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_167 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_8 V_341 [ 8 ] )
{
int V_356 = V_341 [ 0 ] ;
if ( V_2 -> V_45 > 512 || ( V_7 -> V_48 & V_49 ) )
V_7 -> V_52 = V_359 ;
else
V_7 -> V_52 = V_360 ;
if ( ! F_165 ( V_7 ) &&
( V_356 == V_351 ||
V_356 == V_352 ) )
V_7 -> V_42 |= V_43 ;
else if ( ( F_165 ( V_7 ) &&
( V_356 == V_351 ||
V_356 == V_352 ||
V_356 == V_354 ||
V_356 == V_358 ||
V_356 == V_361 ) ) ||
( V_2 -> V_45 == 2048 &&
V_356 == V_334 ) )
V_7 -> V_42 |= V_56 ;
}
static inline bool F_168 ( struct V_355 * type )
{
return type -> V_350 ;
}
static bool F_169 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_355 * type , T_8 * V_341 , int * V_195 )
{
if ( ! strncmp ( type -> V_362 , V_341 , type -> V_350 ) ) {
V_2 -> V_45 = type -> V_357 ;
V_2 -> V_44 = type -> V_44 ;
V_2 -> V_14 = type -> V_14 ;
V_7 -> V_330 = F_163 ( V_341 [ 2 ] ) ;
V_7 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
V_7 -> V_48 |= type -> V_48 ;
V_7 -> V_309 = F_170 ( type ) ;
V_7 -> V_311 = F_171 ( type ) ;
V_7 -> V_121 =
type -> V_121 ;
* V_195 = type -> V_48 & V_49 ;
if ( ! V_2 -> V_325 )
V_2 -> V_325 = type -> V_325 ;
return true ;
}
return false ;
}
static struct V_355 * F_172 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
int * V_356 , int * V_363 ,
struct V_355 * type )
{
int V_195 ;
int V_40 , V_364 ;
T_8 V_341 [ 8 ] ;
F_81 ( V_7 , 0 ) ;
V_7 -> V_130 ( V_2 , 0 ) ;
V_7 -> V_50 ( V_2 , V_321 , 0x00 , - 1 ) ;
* V_356 = V_7 -> V_54 ( V_2 ) ;
* V_363 = V_7 -> V_54 ( V_2 ) ;
V_7 -> V_50 ( V_2 , V_321 , 0x00 , - 1 ) ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ )
V_341 [ V_40 ] = V_7 -> V_54 ( V_2 ) ;
if ( V_341 [ 0 ] != * V_356 || V_341 [ 1 ] != * V_363 ) {
F_156 ( L_34 ,
* V_356 , * V_363 , V_341 [ 0 ] , V_341 [ 1 ] ) ;
return F_173 ( - V_365 ) ;
}
if ( ! type )
type = V_366 ;
for (; type -> V_325 != NULL ; type ++ ) {
if ( F_168 ( type ) ) {
if ( F_169 ( V_2 , V_7 , type , V_341 , & V_195 ) )
goto V_367;
} else if ( * V_363 == type -> V_363 ) {
break;
}
}
V_7 -> V_118 = 0 ;
if ( ! type -> V_325 || ! type -> V_357 ) {
if ( F_155 ( V_2 , V_7 , & V_195 ) )
goto V_367;
if ( F_159 ( V_2 , V_7 , & V_195 ) )
goto V_367;
}
if ( ! type -> V_325 )
return F_173 ( - V_365 ) ;
if ( ! V_2 -> V_325 )
V_2 -> V_325 = type -> V_325 ;
V_7 -> V_93 = ( T_2 ) type -> V_93 << 20 ;
if ( ! type -> V_357 ) {
F_164 ( V_2 , V_7 , V_341 , & V_195 ) ;
} else {
F_166 ( V_2 , V_7 , type , V_341 , & V_195 ) ;
}
V_7 -> V_48 |= type -> V_48 ;
if ( * V_356 != V_351 && ! type -> V_357 )
V_7 -> V_48 &= ~ V_368 ;
V_367:
for ( V_364 = 0 ; V_369 [ V_364 ] . V_362 != 0x0 ; V_364 ++ ) {
if ( V_369 [ V_364 ] . V_362 == * V_356 )
break;
}
if ( V_7 -> V_48 & V_370 ) {
F_67 ( V_7 -> V_48 & V_49 ) ;
V_7 -> V_48 |= V_195 ;
F_146 ( V_7 , V_195 ) ;
} else if ( V_195 != ( V_7 -> V_48 & V_49 ) ) {
F_156 ( L_35 ,
* V_356 , * V_363 ) ;
F_156 ( L_36 , V_369 [ V_364 ] . V_325 , V_2 -> V_325 ) ;
F_135 ( L_37 ,
( V_7 -> V_48 & V_49 ) ? 16 : 8 ,
V_195 ? 16 : 8 ) ;
return F_173 ( - V_20 ) ;
}
F_167 ( V_2 , V_7 , V_341 ) ;
V_7 -> V_46 = F_174 ( V_2 -> V_45 ) - 1 ;
V_7 -> V_47 = ( V_7 -> V_93 >> V_7 -> V_46 ) - 1 ;
V_7 -> V_371 = V_7 -> V_18 =
F_174 ( V_2 -> V_44 ) - 1 ;
if ( V_7 -> V_93 & 0xffffffff )
V_7 -> V_139 = F_174 ( ( unsigned ) V_7 -> V_93 ) - 1 ;
else {
V_7 -> V_139 = F_174 ( ( unsigned ) ( V_7 -> V_93 >> 32 ) ) ;
V_7 -> V_139 += 32 - 1 ;
}
V_7 -> V_55 = 8 ;
V_7 -> V_275 = F_133 ;
if ( V_2 -> V_45 > 512 && V_7 -> V_50 == F_54 )
V_7 -> V_50 = F_58 ;
F_156 ( L_35 ,
* V_356 , * V_363 ) ;
if ( V_7 -> V_118 )
F_156 ( L_36 , V_369 [ V_364 ] . V_325 ,
V_7 -> V_281 . V_324 ) ;
else if ( V_7 -> V_338 )
F_156 ( L_36 , V_369 [ V_364 ] . V_325 ,
V_7 -> V_336 . V_324 ) ;
else
F_156 ( L_36 , V_369 [ V_364 ] . V_325 ,
type -> V_325 ) ;
F_156 ( L_38 ,
( int ) ( V_7 -> V_93 >> 20 ) , F_165 ( V_7 ) ? L_39 : L_40 ,
V_2 -> V_44 >> 10 , V_2 -> V_45 , V_2 -> V_14 ) ;
return type ;
}
static int F_175 ( struct V_372 * V_373 )
{
const char * V_374 ;
int V_124 , V_40 ;
V_124 = F_176 ( V_373 , L_41 , & V_374 ) ;
if ( V_124 < 0 )
return V_124 ;
for ( V_40 = 0 ; V_40 < F_177 ( V_375 ) ; V_40 ++ )
if ( ! strcasecmp ( V_374 , V_375 [ V_40 ] ) )
return V_40 ;
if ( ! strcasecmp ( V_374 , L_42 ) )
return V_376 ;
return - V_365 ;
}
static int F_178 ( struct V_372 * V_373 )
{
const char * V_374 ;
int V_124 , V_40 ;
V_124 = F_176 ( V_373 , L_43 , & V_374 ) ;
if ( ! V_124 ) {
for ( V_40 = V_377 ; V_40 < F_177 ( V_378 ) ; V_40 ++ )
if ( ! strcasecmp ( V_374 , V_378 [ V_40 ] ) )
return V_40 ;
return - V_365 ;
}
V_124 = F_176 ( V_373 , L_41 , & V_374 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! strcasecmp ( V_374 , L_44 ) )
return V_377 ;
else if ( ! strcasecmp ( V_374 , L_42 ) )
return V_379 ;
return - V_365 ;
}
static int F_179 ( struct V_372 * V_373 )
{
int V_17 ;
T_12 V_320 ;
V_17 = F_180 ( V_373 , L_45 , & V_320 ) ;
return V_17 ? V_17 : V_320 ;
}
static int F_181 ( struct V_372 * V_373 )
{
int V_17 ;
T_12 V_320 ;
V_17 = F_180 ( V_373 , L_46 , & V_320 ) ;
return V_17 ? V_17 : V_320 ;
}
static int F_182 ( struct V_372 * V_373 )
{
T_12 V_320 ;
if ( F_180 ( V_373 , L_47 , & V_320 ) )
return 8 ;
switch ( V_320 ) {
case 8 :
case 16 :
return V_320 ;
default:
return - V_136 ;
}
}
static bool F_183 ( struct V_372 * V_373 )
{
return F_184 ( V_373 , L_48 ) ;
}
static int F_185 ( struct V_6 * V_7 )
{
struct V_372 * V_380 = F_186 ( V_7 ) ;
int V_381 , V_382 , V_383 , V_384 ;
if ( ! V_380 )
return 0 ;
if ( F_182 ( V_380 ) == 16 )
V_7 -> V_48 |= V_49 ;
if ( F_183 ( V_380 ) )
V_7 -> V_42 |= V_385 ;
V_381 = F_175 ( V_380 ) ;
V_382 = F_178 ( V_380 ) ;
V_383 = F_181 ( V_380 ) ;
V_384 = F_179 ( V_380 ) ;
if ( ( V_384 >= 0 && ! ( V_383 >= 0 ) ) ||
( ! ( V_384 >= 0 ) && V_383 >= 0 ) ) {
F_71 ( L_49 ) ;
return - V_20 ;
}
if ( V_381 >= 0 )
V_7 -> V_9 . V_62 = V_381 ;
if ( V_382 >= 0 )
V_7 -> V_9 . V_386 = V_382 ;
if ( V_383 >= 0 )
V_7 -> V_9 . V_198 = V_383 ;
if ( V_384 > 0 )
V_7 -> V_9 . V_137 = V_384 ;
if ( F_184 ( V_380 , L_50 ) )
V_7 -> V_9 . V_48 |= V_387 ;
return 0 ;
}
int F_187 ( struct V_1 * V_2 , int V_388 ,
struct V_355 * V_389 )
{
int V_40 , V_390 , V_391 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_355 * type ;
int V_17 ;
V_17 = F_185 ( V_7 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_2 -> V_325 && V_2 -> V_392 . V_393 )
V_2 -> V_325 = F_188 ( V_2 -> V_392 . V_393 ) ;
if ( ( ! V_7 -> V_50 || ! V_7 -> V_130 ) && ! V_7 -> V_29 ) {
F_71 ( L_51 ) ;
return - V_20 ;
}
F_146 ( V_7 , V_7 -> V_48 & V_49 ) ;
type = F_172 ( V_2 , V_7 , & V_390 ,
& V_391 , V_389 ) ;
if ( F_189 ( type ) ) {
if ( ! ( V_7 -> V_48 & V_394 ) )
F_135 ( L_52 ) ;
V_7 -> V_130 ( V_2 , - 1 ) ;
return F_190 ( type ) ;
}
V_17 = F_73 ( V_7 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_72 ( V_7 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_130 ( V_2 , - 1 ) ;
for ( V_40 = 1 ; V_40 < V_388 ; V_40 ++ ) {
F_81 ( V_7 , V_40 ) ;
V_7 -> V_130 ( V_2 , V_40 ) ;
V_7 -> V_50 ( V_2 , V_321 , 0x00 , - 1 ) ;
if ( V_390 != V_7 -> V_54 ( V_2 ) ||
V_391 != V_7 -> V_54 ( V_2 ) ) {
V_7 -> V_130 ( V_2 , - 1 ) ;
break;
}
V_7 -> V_130 ( V_2 , - 1 ) ;
}
if ( V_40 > 1 )
F_156 ( L_53 , V_40 ) ;
V_7 -> V_395 = V_40 ;
V_2 -> V_137 = V_40 * V_7 -> V_93 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_67 ( V_9 -> V_62 != V_376 ) )
return - V_20 ;
switch ( V_9 -> V_386 ) {
case V_377 :
V_9 -> V_178 = V_396 ;
V_9 -> V_180 = V_397 ;
V_9 -> V_224 = F_91 ;
V_9 -> V_223 = F_94 ;
V_9 -> V_257 = F_118 ;
V_9 -> V_177 = F_89 ;
V_9 -> V_243 = F_116 ;
V_9 -> V_240 = F_109 ;
V_9 -> V_269 = F_112 ;
if ( ! V_9 -> V_137 )
V_9 -> V_137 = 256 ;
V_9 -> V_165 = 3 ;
V_9 -> V_198 = 1 ;
return 0 ;
case V_379 :
if ( ! F_192 () ) {
F_193 ( 1 , L_54 ) ;
return - V_20 ;
}
V_9 -> V_178 = V_398 ;
V_9 -> V_180 = V_399 ;
V_9 -> V_224 = F_91 ;
V_9 -> V_223 = F_94 ;
V_9 -> V_257 = F_118 ;
V_9 -> V_177 = F_89 ;
V_9 -> V_243 = F_116 ;
V_9 -> V_240 = F_109 ;
V_9 -> V_269 = F_112 ;
if ( ! V_9 -> V_137 && ( V_2 -> V_14 >= 64 ) ) {
V_9 -> V_137 = 512 ;
V_9 -> V_198 = 4 ;
}
if ( ! V_2 -> V_400 ) {
if ( V_2 -> V_14 < 64 ) {
F_193 ( 1 , L_55 ) ;
return - V_20 ;
}
F_194 ( V_2 , & V_401 ) ;
}
if ( V_2 -> V_400 == & V_401 &&
V_9 -> V_48 & V_387 ) {
int V_167 , V_165 ;
V_9 -> V_137 = 1024 ;
V_167 = V_2 -> V_45 / V_9 -> V_137 ;
V_165 = ( V_2 -> V_14 - 2 ) / V_167 ;
V_9 -> V_198 = V_165 * 8 / F_77 ( 8 * V_9 -> V_137 ) ;
}
V_9 -> V_165 = 0 ;
V_9 -> V_402 = F_195 ( V_2 ) ;
if ( ! V_9 -> V_402 ) {
F_193 ( 1 , L_56 ) ;
return - V_20 ;
}
return 0 ;
default:
F_193 ( 1 , L_57 ) ;
return - V_20 ;
}
}
static bool F_196 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_403 , V_404 ;
if ( V_9 -> V_137 == 0 || V_7 -> V_311 == 0 )
return true ;
V_403 = ( V_2 -> V_45 * V_9 -> V_198 ) / V_9 -> V_137 ;
V_404 = ( V_2 -> V_45 * V_7 -> V_309 ) / V_7 -> V_311 ;
return V_403 >= V_404 && V_9 -> V_198 >= V_7 -> V_309 ;
}
int F_197 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_405 * V_406 ;
int V_17 ;
if ( F_67 ( ( V_7 -> V_42 & V_64 ) &&
! ( V_7 -> V_42 & V_385 ) ) )
return - V_20 ;
if ( ! ( V_7 -> V_48 & V_407 ) ) {
V_406 = F_76 ( sizeof( * V_406 ) + V_2 -> V_45
+ V_2 -> V_14 * 3 , V_127 ) ;
if ( ! V_406 )
return - V_128 ;
V_406 -> V_173 = ( T_3 * ) ( V_406 + 1 ) ;
V_406 -> V_175 = V_406 -> V_173 + V_2 -> V_14 ;
V_406 -> V_221 = V_406 -> V_175 + V_2 -> V_14 ;
V_7 -> V_172 = V_406 ;
} else {
if ( ! V_7 -> V_172 )
return - V_128 ;
}
V_7 -> V_162 = V_7 -> V_172 -> V_221 + V_2 -> V_45 ;
if ( ! V_2 -> V_400 &&
! ( V_9 -> V_62 == V_376 && V_9 -> V_386 == V_379 ) ) {
switch ( V_2 -> V_14 ) {
case 8 :
case 16 :
F_194 ( V_2 , & V_408 ) ;
break;
case 64 :
case 128 :
F_194 ( V_2 , & V_401 ) ;
break;
default:
F_193 ( 1 , L_58 ,
V_2 -> V_14 ) ;
V_17 = - V_20 ;
goto V_409;
}
}
if ( ! V_7 -> V_257 )
V_7 -> V_257 = F_123 ;
switch ( V_9 -> V_62 ) {
case V_410 :
if ( ! V_9 -> V_178 || ! V_9 -> V_180 || ! V_9 -> V_199 ) {
F_193 ( 1 , L_59 ) ;
V_17 = - V_20 ;
goto V_409;
}
if ( ! V_9 -> V_224 )
V_9 -> V_224 = F_97 ;
case V_411 :
if ( ! V_9 -> V_224 )
V_9 -> V_224 = F_96 ;
if ( ! V_9 -> V_257 )
V_9 -> V_257 = F_120 ;
if ( ! V_9 -> V_177 )
V_9 -> V_177 = F_89 ;
if ( ! V_9 -> V_243 )
V_9 -> V_243 = F_116 ;
if ( ! V_9 -> V_240 )
V_9 -> V_240 = F_109 ;
if ( ! V_9 -> V_269 )
V_9 -> V_269 = F_112 ;
if ( ! V_9 -> V_223 )
V_9 -> V_223 = F_94 ;
if ( ! V_9 -> V_256 && V_9 -> V_199 && V_9 -> V_178 )
V_9 -> V_256 = F_121 ;
case V_412 :
if ( ( ! V_9 -> V_178 || ! V_9 -> V_180 || ! V_9 -> V_199 ) &&
( ! V_9 -> V_224 ||
V_9 -> V_224 == F_96 ||
! V_9 -> V_257 ||
V_9 -> V_257 == F_120 ) ) {
F_193 ( 1 , L_59 ) ;
V_17 = - V_20 ;
goto V_409;
}
if ( ! V_9 -> V_224 )
V_9 -> V_224 = F_98 ;
if ( ! V_9 -> V_257 )
V_9 -> V_257 = F_122 ;
if ( ! V_9 -> V_177 )
V_9 -> V_177 = F_90 ;
if ( ! V_9 -> V_243 )
V_9 -> V_243 = F_117 ;
if ( ! V_9 -> V_240 )
V_9 -> V_240 = F_110 ;
if ( ! V_9 -> V_269 )
V_9 -> V_269 = F_113 ;
if ( V_2 -> V_45 >= V_9 -> V_137 ) {
if ( ! V_9 -> V_198 ) {
F_193 ( 1 , L_60 ) ;
V_17 = - V_20 ;
goto V_409;
}
break;
}
F_135 ( L_61 ,
V_9 -> V_137 , V_2 -> V_45 ) ;
V_9 -> V_62 = V_376 ;
V_9 -> V_386 = V_377 ;
case V_376 :
V_17 = F_191 ( V_2 ) ;
if ( V_17 ) {
V_17 = - V_20 ;
goto V_409;
}
break;
case V_413 :
F_135 ( L_62 ) ;
V_9 -> V_224 = F_89 ;
V_9 -> V_257 = F_116 ;
V_9 -> V_240 = F_109 ;
V_9 -> V_177 = F_89 ;
V_9 -> V_243 = F_116 ;
V_9 -> V_269 = F_112 ;
V_9 -> V_137 = V_2 -> V_45 ;
V_9 -> V_165 = 0 ;
V_9 -> V_198 = 0 ;
break;
default:
F_193 ( 1 , L_63 , V_9 -> V_62 ) ;
V_17 = - V_20 ;
goto V_409;
}
if ( ! V_9 -> V_239 )
V_9 -> V_239 = V_9 -> V_240 ;
if ( ! V_9 -> V_268 )
V_9 -> V_268 = V_9 -> V_269 ;
V_2 -> V_383 = V_9 -> V_198 ;
V_2 -> V_414 = V_9 -> V_137 ;
V_9 -> V_167 = V_2 -> V_45 / V_9 -> V_137 ;
if ( V_9 -> V_167 * V_9 -> V_137 != V_2 -> V_45 ) {
F_193 ( 1 , L_64 ) ;
V_17 = - V_20 ;
goto V_409;
}
V_9 -> V_13 = V_9 -> V_167 * V_9 -> V_165 ;
V_17 = F_198 ( V_2 ) ;
if ( V_17 < 0 )
V_17 = 0 ;
V_2 -> V_415 = V_17 ;
if ( ! F_196 ( V_2 ) )
F_135 ( L_65 ,
V_2 -> V_325 ) ;
if ( ! ( V_7 -> V_48 & V_255 ) && F_165 ( V_7 ) ) {
switch ( V_9 -> V_167 ) {
case 2 :
V_2 -> V_416 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_416 = 2 ;
break;
}
}
V_7 -> V_417 = V_2 -> V_45 >> V_2 -> V_416 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_220 = - 1 ;
switch ( V_9 -> V_62 ) {
case V_376 :
if ( V_7 -> V_46 > 9 )
V_7 -> V_48 |= V_418 ;
break;
default:
break;
}
V_2 -> type = F_165 ( V_7 ) ? V_419 : V_420 ;
V_2 -> V_421 = ( V_7 -> V_48 & V_422 ) ? V_423 :
V_424 ;
V_2 -> V_425 = F_134 ;
V_2 -> V_426 = NULL ;
V_2 -> V_427 = NULL ;
V_2 -> V_428 = F_108 ;
V_2 -> V_429 = F_131 ;
V_2 -> V_430 = F_130 ;
V_2 -> V_431 = F_115 ;
V_2 -> V_432 = F_132 ;
V_2 -> V_433 = F_137 ;
V_2 -> V_434 = NULL ;
V_2 -> V_435 = NULL ;
V_2 -> V_436 = F_143 ;
V_2 -> V_437 = F_144 ;
V_2 -> V_438 = F_145 ;
V_2 -> V_439 = F_40 ;
V_2 -> V_440 = F_138 ;
V_2 -> V_441 = F_139 ;
V_2 -> V_442 = V_2 -> V_45 ;
if ( ! V_2 -> V_443 )
V_2 -> V_443 = F_199 ( V_2 -> V_383 * 3 , 4 ) ;
if ( V_7 -> V_48 & V_444 )
return 0 ;
return V_7 -> V_288 ( V_2 ) ;
V_409:
if ( ! ( V_7 -> V_48 & V_407 ) )
F_80 ( V_7 -> V_172 ) ;
return V_17 ;
}
int F_200 ( struct V_1 * V_2 , int V_388 )
{
int V_17 ;
V_17 = F_187 ( V_2 , V_388 , NULL ) ;
if ( ! V_17 )
V_17 = F_197 ( V_2 ) ;
return V_17 ;
}
void F_201 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 . V_62 == V_376 &&
V_7 -> V_9 . V_386 == V_379 )
F_202 ( (struct V_445 * ) V_7 -> V_9 . V_402 ) ;
F_79 ( V_7 ) ;
F_80 ( V_7 -> V_70 ) ;
if ( ! ( V_7 -> V_48 & V_407 ) )
F_80 ( V_7 -> V_172 ) ;
if ( V_7 -> V_446 && V_7 -> V_446 -> V_48
& V_447 )
F_80 ( V_7 -> V_446 ) ;
}
void F_203 ( struct V_1 * V_2 )
{
F_204 ( V_2 ) ;
F_201 ( F_2 ( V_2 ) ) ;
}
