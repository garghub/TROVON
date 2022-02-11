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
static int F_6 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_3 )
return - V_10 ;
switch ( V_2 -> V_14 ) {
case 64 :
V_5 -> V_11 = 40 ;
break;
case 128 :
V_5 -> V_11 = 80 ;
break;
default:
return - V_15 ;
}
V_5 -> V_12 = V_9 -> V_13 ;
if ( V_5 -> V_11 + V_5 -> V_12 > V_2 -> V_14 )
return - V_10 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_16 = 0 ;
if ( V_3 < 0 || V_3 > 1 )
return - V_10 ;
switch ( V_2 -> V_14 ) {
case 64 :
V_16 = 40 ;
break;
case 128 :
V_16 = 80 ;
break;
default:
return - V_15 ;
}
if ( V_3 == 0 ) {
V_5 -> V_11 = 2 ;
V_5 -> V_12 = V_16 - 2 ;
} else {
V_5 -> V_11 = V_16 + V_9 -> V_13 ;
V_5 -> V_12 = V_2 -> V_14 - V_5 -> V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_17 , T_2 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 = 0 ;
if ( V_17 & ( ( 1ULL << V_7 -> V_20 ) - 1 ) ) {
F_9 ( L_1 , V_21 ) ;
V_19 = - V_15 ;
}
if ( V_18 & ( ( 1ULL << V_7 -> V_20 ) - 1 ) ) {
F_9 ( L_2 , V_21 ) ;
V_19 = - V_15 ;
}
return V_19 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_11 ( & V_7 -> V_22 -> V_23 ) ;
V_7 -> V_22 -> V_24 = NULL ;
V_7 -> V_25 = V_26 ;
F_12 ( & V_7 -> V_22 -> V_27 ) ;
F_13 ( & V_7 -> V_22 -> V_23 ) ;
}
static T_3 F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_15 ( V_7 -> V_28 ) ;
}
static T_3 F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return ( T_3 ) F_17 ( F_18 ( V_7 -> V_28 ) ) ;
}
static T_4 F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_18 ( V_7 -> V_28 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_29 ) {
case - 1 :
V_7 -> V_30 ( V_2 , V_31 , 0 | V_32 ) ;
break;
case 0 :
break;
default:
F_21 () ;
}
}
static void F_22 ( struct V_1 * V_2 , T_3 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_34 ( V_2 , & V_33 , 1 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_3 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_5 V_35 = V_33 ;
V_7 -> V_34 ( V_2 , ( T_3 * ) & V_35 , 2 ) ;
}
static void F_24 ( struct V_1 * V_2 , const T_3 * V_36 , int V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_25 ( V_7 -> V_37 , V_36 , V_18 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_3 * V_36 , int V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_27 ( V_7 -> V_28 , V_36 , V_18 ) ;
}
static void F_28 ( struct V_1 * V_2 , const T_3 * V_36 , int V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 * V_38 = ( T_4 * ) V_36 ;
F_29 ( V_7 -> V_37 , V_38 , V_18 >> 1 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_3 * V_36 , int V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 * V_38 = ( T_4 * ) V_36 ;
F_31 ( V_7 -> V_28 , V_38 , V_18 >> 1 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_39 , V_40 , V_41 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_6 V_42 ;
if ( V_7 -> V_43 & V_44 )
V_17 += V_2 -> V_45 - V_2 -> V_46 ;
V_39 = ( int ) ( V_17 >> V_7 -> V_47 ) & V_7 -> V_48 ;
V_40 = V_39 + ( V_7 -> V_43 & V_49 ? 2 : 1 ) ;
for (; V_39 < V_40 ; V_39 ++ ) {
V_41 = V_7 -> V_9 . V_50 ( V_2 , V_7 , V_39 ) ;
if ( V_41 )
return V_41 ;
V_42 = V_7 -> V_51 [ V_7 -> V_52 ] ;
if ( F_33 ( V_7 -> V_53 == 8 ) )
V_41 = V_42 != 0xFF ;
else
V_41 = F_34 ( V_42 ) < V_7 -> V_53 ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_54 V_55 ;
T_3 V_36 [ 2 ] = { 0 , 0 } ;
int V_19 = 0 , V_41 , V_56 = 0 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_57 = V_36 ;
V_55 . V_58 = V_7 -> V_52 ;
if ( V_7 -> V_59 & V_60 ) {
V_55 . V_58 &= ~ 0x01 ;
V_55 . V_18 = V_55 . V_61 = 2 ;
} else {
V_55 . V_18 = V_55 . V_61 = 1 ;
}
V_55 . V_62 = V_63 ;
if ( V_7 -> V_43 & V_44 )
V_17 += V_2 -> V_45 - V_2 -> V_46 ;
do {
V_41 = F_36 ( V_2 , V_17 , & V_55 ) ;
if ( ! V_19 )
V_19 = V_41 ;
V_56 ++ ;
V_17 += V_2 -> V_46 ;
} while ( ( V_7 -> V_43 & V_49 ) && V_56 < 2 );
return V_19 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_41 , V_19 = 0 ;
if ( ! ( V_7 -> V_43 & V_64 ) ) {
struct V_65 V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_2 = V_2 ;
V_66 . V_67 = V_17 ;
V_66 . V_18 = 1ULL << V_7 -> V_20 ;
F_38 ( V_2 , & V_66 , 0 ) ;
F_39 ( V_2 , V_68 ) ;
V_19 = V_7 -> V_69 ( V_2 , V_17 ) ;
F_10 ( V_2 ) ;
}
if ( V_7 -> V_70 ) {
V_41 = F_40 ( V_2 , V_17 ) ;
if ( ! V_19 )
V_19 = V_41 ;
}
if ( ! V_19 )
V_2 -> V_71 . V_72 ++ ;
return V_19 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_59 & V_73 )
return 0 ;
V_7 -> V_74 ( V_2 , V_75 , - 1 , - 1 ) ;
return ( V_7 -> V_76 ( V_2 ) & V_77 ) ? 0 : 1 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_70 )
return 0 ;
return F_43 ( V_2 , V_17 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_17 , int V_78 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_70 )
return V_7 -> V_79 ( V_2 , V_17 ) ;
return F_45 ( V_2 , V_17 , V_78 ) ;
}
static void F_46 ( struct V_1 * V_2 , unsigned long V_80 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_80 ; V_56 ++ ) {
if ( V_7 -> V_81 ( V_2 ) )
break;
F_47 () ;
F_48 ( 1 ) ;
}
}
void F_49 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_80 = 400 ;
if ( F_50 () || V_82 )
return F_46 ( V_2 , V_80 ) ;
V_80 = V_83 + F_51 ( V_80 ) ;
do {
if ( V_7 -> V_81 ( V_2 ) )
return;
F_52 () ;
} while ( F_53 ( V_83 , V_80 ) );
if ( ! V_7 -> V_81 ( V_2 ) )
F_54 ( L_3 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned long V_80 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
V_80 = V_83 + F_51 ( V_80 ) ;
do {
if ( ( V_7 -> V_76 ( V_2 ) & V_84 ) )
break;
F_47 () ;
} while ( F_53 ( V_83 , V_80 ) );
}
static void F_56 ( struct V_1 * V_2 , unsigned int V_85 ,
int V_86 , int V_87 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_88 = V_89 | V_32 ;
if ( V_85 == V_90 ) {
int V_91 ;
if ( V_86 >= V_2 -> V_46 ) {
V_86 -= V_2 -> V_46 ;
V_91 = V_92 ;
} else if ( V_86 < 256 ) {
V_91 = V_93 ;
} else {
V_86 -= 256 ;
V_91 = V_94 ;
}
V_7 -> V_30 ( V_2 , V_91 , V_88 ) ;
V_88 &= ~ V_32 ;
}
V_7 -> V_30 ( V_2 , V_85 , V_88 ) ;
V_88 = V_95 | V_32 ;
if ( V_86 != - 1 ) {
if ( V_7 -> V_59 & V_60 &&
! F_57 ( V_85 ) )
V_86 >>= 1 ;
V_7 -> V_30 ( V_2 , V_86 , V_88 ) ;
V_88 &= ~ V_32 ;
}
if ( V_87 != - 1 ) {
V_7 -> V_30 ( V_2 , V_87 , V_88 ) ;
V_88 &= ~ V_32 ;
V_7 -> V_30 ( V_2 , V_87 >> 8 , V_88 ) ;
if ( V_7 -> V_96 > ( 32 << 20 ) )
V_7 -> V_30 ( V_2 , V_87 >> 16 , V_88 ) ;
}
V_7 -> V_30 ( V_2 , V_31 , V_97 | V_32 ) ;
switch ( V_85 ) {
case V_98 :
case V_99 :
case V_100 :
case V_90 :
case V_75 :
case V_101 :
case V_102 :
return;
case V_103 :
if ( V_7 -> V_81 )
break;
F_58 ( V_7 -> V_104 ) ;
V_7 -> V_30 ( V_2 , V_75 ,
V_89 | V_32 ) ;
V_7 -> V_30 ( V_2 ,
V_31 , V_97 | V_32 ) ;
F_55 ( V_2 , 250 ) ;
return;
default:
if ( ! V_7 -> V_81 ) {
F_58 ( V_7 -> V_104 ) ;
return;
}
}
F_59 ( 100 ) ;
F_49 ( V_2 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
if ( ! ( V_7 -> V_59 & V_105 ) )
return;
if ( V_7 -> V_106 && V_7 -> V_106 -> V_107 . V_108 . V_109 )
F_59 ( V_7 -> V_106 -> V_107 . V_108 . V_109 / 1000 ) ;
else
F_59 ( 500 ) ;
}
static void F_61 ( struct V_1 * V_2 , unsigned int V_85 ,
int V_86 , int V_87 )
{
register struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_85 == V_92 ) {
V_86 += V_2 -> V_46 ;
V_85 = V_93 ;
}
V_7 -> V_30 ( V_2 , V_85 , V_97 | V_110 | V_32 ) ;
if ( V_86 != - 1 || V_87 != - 1 ) {
int V_88 = V_32 | V_97 | V_111 ;
if ( V_86 != - 1 ) {
if ( V_7 -> V_59 & V_60 &&
! F_57 ( V_85 ) )
V_86 >>= 1 ;
V_7 -> V_30 ( V_2 , V_86 , V_88 ) ;
V_88 &= ~ V_32 ;
if ( ! F_57 ( V_85 ) )
V_7 -> V_30 ( V_2 , V_86 >> 8 , V_88 ) ;
}
if ( V_87 != - 1 ) {
V_7 -> V_30 ( V_2 , V_87 , V_88 ) ;
V_7 -> V_30 ( V_2 , V_87 >> 8 ,
V_97 | V_111 ) ;
if ( V_7 -> V_96 > ( 128 << 20 ) )
V_7 -> V_30 ( V_2 , V_87 >> 16 ,
V_97 | V_111 ) ;
}
}
V_7 -> V_30 ( V_2 , V_31 , V_97 | V_32 ) ;
switch ( V_85 ) {
case V_112 :
case V_98 :
case V_99 :
case V_100 :
case V_90 :
case V_75 :
case V_101 :
case V_102 :
return;
case V_113 :
F_60 ( V_7 ) ;
return;
case V_103 :
if ( V_7 -> V_81 )
break;
F_58 ( V_7 -> V_104 ) ;
V_7 -> V_30 ( V_2 , V_75 ,
V_97 | V_110 | V_32 ) ;
V_7 -> V_30 ( V_2 , V_31 ,
V_97 | V_32 ) ;
F_55 ( V_2 , 250 ) ;
return;
case V_114 :
V_7 -> V_30 ( V_2 , V_115 ,
V_97 | V_110 | V_32 ) ;
V_7 -> V_30 ( V_2 , V_31 ,
V_97 | V_32 ) ;
F_60 ( V_7 ) ;
return;
case V_93 :
V_7 -> V_30 ( V_2 , V_116 ,
V_97 | V_110 | V_32 ) ;
V_7 -> V_30 ( V_2 , V_31 ,
V_97 | V_32 ) ;
default:
if ( ! V_7 -> V_81 ) {
F_58 ( V_7 -> V_104 ) ;
return;
}
}
F_59 ( 100 ) ;
F_49 ( V_2 ) ;
}
static void F_62 ( struct V_6 * V_7 ,
struct V_1 * V_2 , int V_117 )
{
V_7 -> V_22 -> V_24 = V_7 ;
V_7 -> V_25 = V_117 ;
}
static int
F_39 ( struct V_1 * V_2 , int V_117 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_7 * V_23 = & V_7 -> V_22 -> V_23 ;
T_8 * V_27 = & V_7 -> V_22 -> V_27 ;
F_63 ( V_118 , V_119 ) ;
V_120:
F_11 ( V_23 ) ;
if ( ! V_7 -> V_22 -> V_24 )
V_7 -> V_22 -> V_24 = V_7 ;
if ( V_7 -> V_22 -> V_24 == V_7 && V_7 -> V_25 == V_26 ) {
V_7 -> V_25 = V_117 ;
F_13 ( V_23 ) ;
return 0 ;
}
if ( V_117 == V_121 ) {
if ( V_7 -> V_22 -> V_24 -> V_25 == V_121 ) {
V_7 -> V_25 = V_121 ;
F_13 ( V_23 ) ;
return 0 ;
}
}
F_64 ( V_122 ) ;
F_65 ( V_27 , & V_118 ) ;
F_13 ( V_23 ) ;
F_66 () ;
F_67 ( V_27 , & V_118 ) ;
goto V_120;
}
static void F_68 ( struct V_1 * V_2 , struct V_6 * V_7 ,
unsigned long V_80 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_80 ; V_56 ++ ) {
if ( V_7 -> V_81 ) {
if ( V_7 -> V_81 ( V_2 ) )
break;
} else {
if ( V_7 -> V_76 ( V_2 ) & V_84 )
break;
}
F_48 ( 1 ) ;
}
}
static int F_69 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_123 ;
unsigned long V_80 = 400 ;
F_59 ( 100 ) ;
V_7 -> V_74 ( V_2 , V_75 , - 1 , - 1 ) ;
if ( F_50 () || V_82 )
F_68 ( V_2 , V_7 , V_80 ) ;
else {
V_80 = V_83 + F_51 ( V_80 ) ;
do {
if ( V_7 -> V_81 ) {
if ( V_7 -> V_81 ( V_2 ) )
break;
} else {
if ( V_7 -> V_76 ( V_2 ) & V_84 )
break;
}
F_52 () ;
} while ( F_53 ( V_83 , V_80 ) );
}
V_123 = ( int ) V_7 -> V_76 ( V_2 ) ;
F_70 ( ! ( V_123 & V_84 ) ) ;
return V_123 ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
const struct V_124 * V_125 ;
int V_19 ;
if ( ! V_7 -> V_126 )
return 0 ;
V_125 = F_73 () ;
V_19 = V_7 -> V_126 ( V_2 , V_125 , false ) ;
if ( V_19 )
F_74 ( L_4 ) ;
return V_19 ;
}
static int F_75 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_19 ;
if ( ! V_7 -> V_126 || ! V_7 -> V_106 )
return 0 ;
if ( V_7 -> V_127 ) {
T_6 V_128 [ V_129 ] = {
V_7 -> V_130 ,
} ;
V_19 = V_7 -> V_131 ( V_2 , V_7 ,
V_132 ,
V_128 ) ;
if ( V_19 )
goto V_133;
}
V_19 = V_7 -> V_126 ( V_2 , V_7 -> V_106 , false ) ;
V_133:
return V_19 ;
}
static int F_76 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_134 , V_62 , V_19 ;
if ( ! V_7 -> V_126 )
return 0 ;
V_134 = F_77 ( V_7 ) ;
if ( V_134 == V_135 ) {
if ( ! V_7 -> V_130 )
return 0 ;
V_134 = F_78 ( V_7 -> V_130 , 0 ) ;
}
V_7 -> V_106 = F_79 ( sizeof( * V_7 -> V_106 ) ,
V_136 ) ;
if ( ! V_7 -> V_106 )
return - V_137 ;
for ( V_62 = F_80 ( V_134 ) - 1 ; V_62 >= 0 ; V_62 -- ) {
V_19 = F_81 ( V_7 , V_7 -> V_106 ,
V_138 , V_62 ) ;
if ( V_19 )
continue;
V_19 = V_7 -> V_126 ( V_2 , V_7 -> V_106 ,
true ) ;
if ( ! V_19 ) {
V_7 -> V_130 = V_62 ;
break;
}
}
return 0 ;
}
static void F_82 ( struct V_6 * V_7 )
{
F_83 ( V_7 -> V_106 ) ;
}
int F_84 ( struct V_6 * V_7 , int V_29 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_19 ;
V_19 = F_71 ( V_7 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_139 ( V_2 , V_29 ) ;
V_7 -> V_74 ( V_2 , V_103 , - 1 , - 1 ) ;
V_7 -> V_139 ( V_2 , - 1 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
V_19 = F_75 ( V_7 ) ;
V_7 -> V_139 ( V_2 , - 1 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , T_1 V_17 ,
T_2 V_18 , int V_140 )
{
int V_19 = 0 ;
int V_123 , V_39 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_39 = V_17 >> V_7 -> V_47 ;
V_7 -> V_74 ( V_2 , V_141 , - 1 , V_39 & V_7 -> V_48 ) ;
V_39 = ( V_17 + V_18 ) >> V_7 -> V_47 ;
V_7 -> V_74 ( V_2 , V_142 , - 1 ,
( V_39 | V_140 ) & V_7 -> V_48 ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
if ( V_123 & V_144 ) {
F_9 ( L_5 ,
V_21 , V_123 ) ;
V_19 = - V_145 ;
}
return V_19 ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_17 , T_2 V_18 )
{
int V_19 = 0 ;
int V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( L_6 ,
V_21 , ( unsigned long long ) V_17 , V_18 ) ;
if ( F_8 ( V_2 , V_17 , V_18 ) )
return - V_15 ;
if ( V_17 + V_18 == V_2 -> V_146 )
V_18 -= V_2 -> V_45 ;
F_39 ( V_2 , V_147 ) ;
V_29 = V_17 >> V_7 -> V_148 ;
F_84 ( V_7 , V_29 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
if ( F_41 ( V_2 ) ) {
F_9 ( L_7 ,
V_21 ) ;
V_19 = - V_145 ;
goto V_149;
}
V_19 = F_85 ( V_2 , V_17 , V_18 , 0 ) ;
V_149:
V_7 -> V_139 ( V_2 , - 1 ) ;
F_10 ( V_2 ) ;
return V_19 ;
}
int F_87 ( struct V_1 * V_2 , T_1 V_17 , T_2 V_18 )
{
int V_19 = 0 ;
int V_29 , V_123 , V_39 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( L_6 ,
V_21 , ( unsigned long long ) V_17 , V_18 ) ;
if ( F_8 ( V_2 , V_17 , V_18 ) )
return - V_15 ;
F_39 ( V_2 , V_150 ) ;
V_29 = V_17 >> V_7 -> V_148 ;
F_84 ( V_7 , V_29 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
if ( F_41 ( V_2 ) ) {
F_9 ( L_7 ,
V_21 ) ;
V_123 = V_151 ;
V_19 = - V_145 ;
goto V_149;
}
V_39 = V_17 >> V_7 -> V_47 ;
V_7 -> V_74 ( V_2 , V_152 , - 1 , V_39 & V_7 -> V_48 ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
if ( V_123 & V_144 ) {
F_9 ( L_5 ,
V_21 , V_123 ) ;
V_19 = - V_145 ;
goto V_149;
}
V_19 = F_85 ( V_2 , V_17 , V_18 , 0x1 ) ;
V_149:
V_7 -> V_139 ( V_2 , - 1 ) ;
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_88 ( void * V_36 , int V_18 , int V_153 )
{
const unsigned char * V_154 = V_36 ;
int V_155 = 0 ;
int V_156 ;
for (; V_18 && ( ( V_157 ) V_154 ) % sizeof( long ) ;
V_18 -- , V_154 ++ ) {
V_156 = F_34 ( * V_154 ) ;
V_155 += V_158 - V_156 ;
if ( F_89 ( V_155 > V_153 ) )
return - V_159 ;
}
for (; V_18 >= sizeof( long ) ;
V_18 -= sizeof( long ) , V_154 += sizeof( long ) ) {
V_156 = F_90 ( * ( ( unsigned long * ) V_154 ) ) ;
V_155 += V_160 - V_156 ;
if ( F_89 ( V_155 > V_153 ) )
return - V_159 ;
}
for (; V_18 > 0 ; V_18 -- , V_154 ++ ) {
V_156 = F_34 ( * V_154 ) ;
V_155 += V_158 - V_156 ;
if ( F_89 ( V_155 > V_153 ) )
return - V_159 ;
}
return V_155 ;
}
int F_91 ( void * V_161 , int V_162 ,
void * V_9 , int V_163 ,
void * V_164 , int V_165 ,
int V_153 )
{
int V_166 = 0 , V_167 = 0 , V_168 = 0 ;
V_166 = F_88 ( V_161 , V_162 ,
V_153 ) ;
if ( V_166 < 0 )
return V_166 ;
V_153 -= V_166 ;
V_167 = F_88 ( V_9 , V_163 , V_153 ) ;
if ( V_167 < 0 )
return V_167 ;
V_153 -= V_167 ;
V_168 = F_88 ( V_164 , V_165 ,
V_153 ) ;
if ( V_168 < 0 )
return V_168 ;
if ( V_166 )
memset ( V_161 , 0xff , V_162 ) ;
if ( V_167 )
memset ( V_9 , 0xff , V_163 ) ;
if ( V_168 )
memset ( V_164 , 0xff , V_165 ) ;
return V_166 + V_167 + V_168 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_169 , int V_39 )
{
V_7 -> V_170 ( V_2 , V_36 , V_2 -> V_46 ) ;
if ( V_169 )
V_7 -> V_170 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_36 ,
int V_169 , int V_39 )
{
int V_171 = V_7 -> V_9 . V_146 ;
int V_172 = V_7 -> V_9 . V_173 ;
T_3 * V_174 = V_7 -> V_51 ;
int V_175 , V_146 ;
for ( V_175 = V_7 -> V_9 . V_175 ; V_175 > 0 ; V_175 -- ) {
V_7 -> V_170 ( V_2 , V_36 , V_171 ) ;
V_36 += V_171 ;
if ( V_7 -> V_9 . V_176 ) {
V_7 -> V_170 ( V_2 , V_174 , V_7 -> V_9 . V_176 ) ;
V_174 += V_7 -> V_9 . V_176 ;
}
V_7 -> V_170 ( V_2 , V_174 , V_172 ) ;
V_174 += V_172 ;
if ( V_7 -> V_9 . V_177 ) {
V_7 -> V_170 ( V_2 , V_174 , V_7 -> V_9 . V_177 ) ;
V_174 += V_7 -> V_9 . V_177 ;
}
}
V_146 = V_2 -> V_14 - ( V_174 - V_7 -> V_51 ) ;
if ( V_146 )
V_7 -> V_170 ( V_2 , V_174 , V_146 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_169 , int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 , V_19 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
T_3 * V_38 = V_36 ;
T_3 * V_179 = V_7 -> V_180 -> V_181 ;
T_3 * V_182 = V_7 -> V_180 -> V_183 ;
unsigned int V_184 = 0 ;
V_7 -> V_9 . V_185 ( V_2 , V_7 , V_36 , 1 , V_39 ) ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 )
V_7 -> V_9 . V_186 ( V_2 , V_38 , & V_179 [ V_56 ] ) ;
V_19 = F_95 ( V_2 , V_182 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_19 )
return V_19 ;
V_178 = V_7 -> V_9 . V_175 ;
V_38 = V_36 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
int V_187 ;
V_187 = V_7 -> V_9 . V_188 ( V_2 , V_38 , & V_182 [ V_56 ] , & V_179 [ V_56 ] ) ;
if ( V_187 < 0 ) {
V_2 -> V_71 . V_189 ++ ;
} else {
V_2 -> V_71 . V_190 += V_187 ;
V_184 = F_96 (unsigned int, max_bitflips, stat) ;
}
}
return V_184 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_191 , T_9 V_192 , T_3 * V_193 ,
int V_39 )
{
int V_194 , V_195 , V_196 , V_19 ;
T_3 * V_38 ;
int V_197 , V_56 , V_198 = 0 ;
int V_199 , V_200 , V_201 , V_202 ;
int V_203 = ( V_7 -> V_59 & V_60 ) ? 2 : 1 ;
int V_204 , V_3 = 0 ;
unsigned int V_184 = 0 ;
struct V_4 V_5 = { } ;
V_194 = V_191 / V_7 -> V_9 . V_146 ;
V_195 = ( V_191 + V_192 - 1 ) / V_7 -> V_9 . V_146 ;
V_196 = V_195 - V_194 + 1 ;
V_204 = V_194 * V_7 -> V_9 . V_173 ;
V_199 = V_196 * V_7 -> V_9 . V_146 ;
V_200 = V_196 * V_7 -> V_9 . V_173 ;
V_197 = V_194 * V_7 -> V_9 . V_146 ;
if ( V_197 != 0 )
V_7 -> V_74 ( V_2 , V_114 , V_197 , - 1 ) ;
V_38 = V_193 + V_197 ;
V_7 -> V_170 ( V_2 , V_38 , V_199 ) ;
for ( V_56 = 0 ; V_56 < V_200 ; V_56 += V_7 -> V_9 . V_173 , V_38 += V_7 -> V_9 . V_146 )
V_7 -> V_9 . V_186 ( V_2 , V_38 , & V_7 -> V_180 -> V_181 [ V_56 ] ) ;
V_19 = F_98 ( V_2 , V_204 , & V_3 , & V_5 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 . V_12 < V_200 )
V_198 = 1 ;
if ( V_198 ) {
V_7 -> V_74 ( V_2 , V_114 , V_2 -> V_46 , - 1 ) ;
V_7 -> V_170 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
} else {
V_202 = V_5 . V_11 & ~ ( V_203 - 1 ) ;
V_201 = V_200 ;
if ( V_5 . V_11 & ( V_203 - 1 ) )
V_201 ++ ;
if ( ( V_5 . V_11 + ( V_196 * V_7 -> V_9 . V_173 ) ) &
( V_203 - 1 ) )
V_201 ++ ;
V_7 -> V_74 ( V_2 , V_114 ,
V_2 -> V_46 + V_202 , - 1 ) ;
V_7 -> V_170 ( V_2 , & V_7 -> V_51 [ V_202 ] , V_201 ) ;
}
V_19 = F_95 ( V_2 , V_7 -> V_180 -> V_183 ,
V_7 -> V_51 , V_204 , V_200 ) ;
if ( V_19 )
return V_19 ;
V_38 = V_193 + V_197 ;
for ( V_56 = 0 ; V_56 < V_200 ; V_56 += V_7 -> V_9 . V_173 , V_38 += V_7 -> V_9 . V_146 ) {
int V_187 ;
V_187 = V_7 -> V_9 . V_188 ( V_2 , V_38 ,
& V_7 -> V_180 -> V_183 [ V_56 ] , & V_7 -> V_180 -> V_181 [ V_56 ] ) ;
if ( V_187 == - V_159 &&
( V_7 -> V_9 . V_59 & V_205 ) ) {
V_187 = F_91 ( V_38 , V_7 -> V_9 . V_146 ,
& V_7 -> V_180 -> V_183 [ V_56 ] ,
V_7 -> V_9 . V_173 ,
NULL , 0 ,
V_7 -> V_9 . V_206 ) ;
}
if ( V_187 < 0 ) {
V_2 -> V_71 . V_189 ++ ;
} else {
V_2 -> V_71 . V_190 += V_187 ;
V_184 = F_96 (unsigned int, max_bitflips, stat) ;
}
}
return V_184 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_169 , int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 , V_19 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
T_3 * V_38 = V_36 ;
T_3 * V_179 = V_7 -> V_180 -> V_181 ;
T_3 * V_182 = V_7 -> V_180 -> V_183 ;
unsigned int V_184 = 0 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
V_7 -> V_9 . V_207 ( V_2 , V_208 ) ;
V_7 -> V_170 ( V_2 , V_38 , V_171 ) ;
V_7 -> V_9 . V_186 ( V_2 , V_38 , & V_179 [ V_56 ] ) ;
}
V_7 -> V_170 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
V_19 = F_95 ( V_2 , V_182 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_19 )
return V_19 ;
V_178 = V_7 -> V_9 . V_175 ;
V_38 = V_36 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
int V_187 ;
V_187 = V_7 -> V_9 . V_188 ( V_2 , V_38 , & V_182 [ V_56 ] , & V_179 [ V_56 ] ) ;
if ( V_187 == - V_159 &&
( V_7 -> V_9 . V_59 & V_205 ) ) {
V_187 = F_91 ( V_38 , V_171 ,
& V_182 [ V_56 ] , V_172 ,
NULL , 0 ,
V_7 -> V_9 . V_206 ) ;
}
if ( V_187 < 0 ) {
V_2 -> V_71 . V_189 ++ ;
} else {
V_2 -> V_71 . V_190 += V_187 ;
V_184 = F_96 (unsigned int, max_bitflips, stat) ;
}
}
return V_184 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_36 , int V_169 , int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 , V_19 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
T_3 * V_38 = V_36 ;
T_3 * V_182 = V_7 -> V_180 -> V_183 ;
T_3 * V_179 = V_7 -> V_180 -> V_181 ;
unsigned int V_184 = 0 ;
V_7 -> V_74 ( V_2 , V_92 , 0 , V_39 ) ;
V_7 -> V_170 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
V_7 -> V_74 ( V_2 , V_93 , 0 , V_39 ) ;
V_19 = F_95 ( V_2 , V_182 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_19 )
return V_19 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
int V_187 ;
V_7 -> V_9 . V_207 ( V_2 , V_208 ) ;
V_7 -> V_170 ( V_2 , V_38 , V_171 ) ;
V_7 -> V_9 . V_186 ( V_2 , V_38 , & V_179 [ V_56 ] ) ;
V_187 = V_7 -> V_9 . V_188 ( V_2 , V_38 , & V_182 [ V_56 ] , NULL ) ;
if ( V_187 == - V_159 &&
( V_7 -> V_9 . V_59 & V_205 ) ) {
V_187 = F_91 ( V_38 , V_171 ,
& V_182 [ V_56 ] , V_172 ,
NULL , 0 ,
V_7 -> V_9 . V_206 ) ;
}
if ( V_187 < 0 ) {
V_2 -> V_71 . V_189 ++ ;
} else {
V_2 -> V_71 . V_190 += V_187 ;
V_184 = F_96 (unsigned int, max_bitflips, stat) ;
}
}
return V_184 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_169 , int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
int V_209 = V_172 + V_7 -> V_9 . V_176 + V_7 -> V_9 . V_177 ;
T_3 * V_38 = V_36 ;
T_3 * V_174 = V_7 -> V_51 ;
unsigned int V_184 = 0 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
int V_187 ;
V_7 -> V_9 . V_207 ( V_2 , V_208 ) ;
V_7 -> V_170 ( V_2 , V_38 , V_171 ) ;
if ( V_7 -> V_9 . V_176 ) {
V_7 -> V_170 ( V_2 , V_174 , V_7 -> V_9 . V_176 ) ;
V_174 += V_7 -> V_9 . V_176 ;
}
V_7 -> V_9 . V_207 ( V_2 , V_210 ) ;
V_7 -> V_170 ( V_2 , V_174 , V_172 ) ;
V_187 = V_7 -> V_9 . V_188 ( V_2 , V_38 , V_174 , NULL ) ;
V_174 += V_172 ;
if ( V_7 -> V_9 . V_177 ) {
V_7 -> V_170 ( V_2 , V_174 , V_7 -> V_9 . V_177 ) ;
V_174 += V_7 -> V_9 . V_177 ;
}
if ( V_187 == - V_159 &&
( V_7 -> V_9 . V_59 & V_205 ) ) {
V_187 = F_91 ( V_38 , V_7 -> V_9 . V_146 ,
V_174 - V_209 ,
V_209 ,
NULL , 0 ,
V_7 -> V_9 . V_206 ) ;
}
if ( V_187 < 0 ) {
V_2 -> V_71 . V_189 ++ ;
} else {
V_2 -> V_71 . V_190 += V_187 ;
V_184 = F_96 (unsigned int, max_bitflips, stat) ;
}
}
V_56 = V_2 -> V_14 - ( V_174 - V_7 -> V_51 ) ;
if ( V_56 )
V_7 -> V_170 ( V_2 , V_174 , V_56 ) ;
return V_184 ;
}
static T_3 * F_102 ( struct V_1 * V_2 , T_3 * V_174 ,
struct V_54 * V_55 , T_10 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 ;
switch ( V_55 -> V_62 ) {
case V_63 :
case V_211 :
memcpy ( V_174 , V_7 -> V_51 + V_55 -> V_58 , V_18 ) ;
return V_174 + V_18 ;
case V_212 :
V_19 = F_103 ( V_2 , V_174 , V_7 -> V_51 ,
V_55 -> V_58 , V_18 ) ;
F_104 ( V_19 ) ;
return V_174 + V_18 ;
default:
F_21 () ;
}
return NULL ;
}
static int F_105 ( struct V_1 * V_2 , int V_213 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( L_8 , V_213 ) ;
if ( V_213 >= V_7 -> V_214 )
return - V_15 ;
if ( ! V_7 -> V_215 )
return - V_216 ;
return V_7 -> V_215 ( V_2 , V_213 ) ;
}
static int F_106 ( struct V_1 * V_2 , T_1 V_217 ,
struct V_54 * V_55 )
{
int V_29 , V_39 , V_218 , V_219 , V_173 , V_220 , V_169 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 = 0 ;
T_9 V_192 = V_55 -> V_18 ;
T_9 V_221 = V_55 -> V_61 ;
T_9 V_222 = F_107 ( V_2 , V_55 ) ;
T_3 * V_193 , * V_174 , * V_36 ;
int V_223 ;
unsigned int V_184 = 0 ;
int V_213 = 0 ;
bool V_224 = false ;
V_29 = ( int ) ( V_217 >> V_7 -> V_148 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
V_218 = ( int ) ( V_217 >> V_7 -> V_47 ) ;
V_39 = V_218 & V_7 -> V_48 ;
V_219 = ( int ) ( V_217 & ( V_2 -> V_46 - 1 ) ) ;
V_36 = V_55 -> V_225 ;
V_174 = V_55 -> V_57 ;
V_169 = V_174 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_226 = V_2 -> V_71 . V_189 ;
V_173 = F_108 ( V_2 -> V_46 - V_219 , V_192 ) ;
V_220 = ( V_173 == V_2 -> V_46 ) ;
if ( ! V_220 )
V_223 = 1 ;
else if ( V_7 -> V_59 & V_227 )
V_223 = ! F_109 ( V_36 ) ||
! F_110 ( ( unsigned long ) V_36 ,
V_7 -> V_228 ) ;
else
V_223 = 0 ;
if ( V_218 != V_7 -> V_229 || V_174 ) {
V_193 = V_223 ? V_7 -> V_180 -> V_230 : V_36 ;
if ( V_223 && V_220 )
F_9 ( L_9 ,
V_21 , V_36 ) ;
V_231:
if ( F_111 ( & V_7 -> V_9 ) )
V_7 -> V_74 ( V_2 , V_93 , 0x00 , V_39 ) ;
if ( F_89 ( V_55 -> V_62 == V_211 ) )
V_19 = V_7 -> V_9 . V_185 ( V_2 , V_7 , V_193 ,
V_169 ,
V_39 ) ;
else if ( ! V_220 && F_112 ( V_7 ) &&
! V_174 )
V_19 = V_7 -> V_9 . V_232 ( V_2 , V_7 ,
V_219 , V_173 , V_193 ,
V_39 ) ;
else
V_19 = V_7 -> V_9 . V_233 ( V_2 , V_7 , V_193 ,
V_169 , V_39 ) ;
if ( V_19 < 0 ) {
if ( V_223 )
V_7 -> V_229 = - 1 ;
break;
}
if ( V_223 ) {
if ( ! F_112 ( V_7 ) && ! V_174 &&
! ( V_2 -> V_71 . V_189 - V_226 ) &&
( V_55 -> V_62 != V_211 ) ) {
V_7 -> V_229 = V_218 ;
V_7 -> V_234 = V_19 ;
} else {
V_7 -> V_229 = - 1 ;
}
memcpy ( V_36 , V_7 -> V_180 -> V_230 + V_219 , V_173 ) ;
}
if ( F_89 ( V_174 ) ) {
int V_235 = F_108 ( V_221 , V_222 ) ;
if ( V_235 ) {
V_174 = F_102 ( V_2 ,
V_174 , V_55 , V_235 ) ;
V_221 -= V_235 ;
}
}
if ( V_7 -> V_59 & V_236 ) {
if ( ! V_7 -> V_81 )
F_58 ( V_7 -> V_104 ) ;
else
F_49 ( V_2 ) ;
}
if ( V_2 -> V_71 . V_189 - V_226 ) {
if ( V_213 + 1 < V_7 -> V_214 ) {
V_213 ++ ;
V_19 = F_105 ( V_2 ,
V_213 ) ;
if ( V_19 < 0 )
break;
V_2 -> V_71 . V_189 = V_226 ;
goto V_231;
} else {
V_224 = true ;
}
}
V_36 += V_173 ;
V_184 = F_96 (unsigned int, max_bitflips, ret) ;
} else {
memcpy ( V_36 , V_7 -> V_180 -> V_230 + V_219 , V_173 ) ;
V_36 += V_173 ;
V_184 = F_96 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_192 -= V_173 ;
if ( V_213 ) {
V_19 = F_105 ( V_2 , 0 ) ;
if ( V_19 < 0 )
break;
V_213 = 0 ;
}
if ( ! V_192 )
break;
V_219 = 0 ;
V_218 ++ ;
V_39 = V_218 & V_7 -> V_48 ;
if ( ! V_39 ) {
V_29 ++ ;
V_7 -> V_139 ( V_2 , - 1 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
}
}
V_7 -> V_139 ( V_2 , - 1 ) ;
V_55 -> V_237 = V_55 -> V_18 - ( T_10 ) V_192 ;
if ( V_174 )
V_55 -> V_238 = V_55 -> V_61 - V_221 ;
if ( V_19 < 0 )
return V_19 ;
if ( V_224 )
return - V_159 ;
return V_184 ;
}
static int F_113 ( struct V_1 * V_2 , T_1 V_217 , T_10 V_18 ,
T_10 * V_237 , T_3 * V_36 )
{
struct V_54 V_55 ;
int V_19 ;
F_39 ( V_2 , V_239 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_18 = V_18 ;
V_55 . V_225 = V_36 ;
V_55 . V_62 = V_63 ;
V_19 = F_106 ( V_2 , V_217 , & V_55 ) ;
* V_237 = V_55 . V_237 ;
F_10 ( V_2 ) ;
return V_19 ;
}
int F_114 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_39 )
{
V_7 -> V_74 ( V_2 , V_92 , 0 , V_39 ) ;
V_7 -> V_170 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_39 )
{
int V_12 = V_2 -> V_14 ;
int V_240 = V_7 -> V_9 . V_173 + V_7 -> V_9 . V_176 + V_7 -> V_9 . V_177 ;
int V_171 = V_7 -> V_9 . V_146 ;
T_3 * V_193 = V_7 -> V_51 ;
int V_56 , V_235 , V_241 = 0 , V_242 ;
V_7 -> V_74 ( V_2 , V_93 , V_7 -> V_9 . V_146 , V_39 ) ;
for ( V_56 = 0 ; V_56 < V_7 -> V_9 . V_175 ; V_56 ++ ) {
if ( V_241 ) {
V_242 = V_171 + V_56 * ( V_171 + V_240 ) ;
if ( V_2 -> V_46 > 512 )
V_7 -> V_74 ( V_2 , V_114 , V_242 , - 1 ) ;
else
V_7 -> V_74 ( V_2 , V_93 , V_242 , V_39 ) ;
} else
V_241 = 1 ;
V_235 = F_116 ( int , V_12 , V_240 ) ;
V_7 -> V_170 ( V_2 , V_193 , V_235 ) ;
V_193 += V_235 ;
V_12 -= V_235 ;
}
if ( V_12 > 0 )
V_7 -> V_170 ( V_2 , V_193 , V_12 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_39 )
{
int V_123 = 0 ;
const T_3 * V_36 = V_7 -> V_51 ;
int V_12 = V_2 -> V_14 ;
V_7 -> V_74 ( V_2 , V_90 , V_2 -> V_46 , V_39 ) ;
V_7 -> V_34 ( V_2 , V_36 , V_12 ) ;
V_7 -> V_74 ( V_2 , V_98 , - 1 , - 1 ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
return V_123 & V_144 ? - V_145 : 0 ;
}
int F_118 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_39 )
{
int V_240 = V_7 -> V_9 . V_173 + V_7 -> V_9 . V_176 + V_7 -> V_9 . V_177 ;
int V_171 = V_7 -> V_9 . V_146 , V_12 = V_2 -> V_14 ;
int V_56 , V_18 , V_242 , V_123 = 0 , V_243 = 0 , V_175 = V_7 -> V_9 . V_175 ;
const T_3 * V_193 = V_7 -> V_51 ;
if ( ! V_7 -> V_9 . V_176 && ! V_7 -> V_9 . V_177 ) {
V_242 = V_175 * ( V_171 + V_240 ) ;
V_175 = 0 ;
} else
V_242 = V_171 ;
V_7 -> V_74 ( V_2 , V_90 , V_242 , V_39 ) ;
for ( V_56 = 0 ; V_56 < V_175 ; V_56 ++ ) {
if ( V_243 ) {
if ( V_2 -> V_46 <= 512 ) {
T_9 V_244 = 0xFFFFFFFF ;
V_18 = V_171 ;
while ( V_18 > 0 ) {
int V_245 = F_116 ( int , V_18 , 4 ) ;
V_7 -> V_34 ( V_2 , ( T_3 * ) & V_244 ,
V_245 ) ;
V_18 -= V_245 ;
}
} else {
V_242 = V_171 + V_56 * ( V_171 + V_240 ) ;
V_7 -> V_74 ( V_2 , V_113 , V_242 , - 1 ) ;
}
} else
V_243 = 1 ;
V_18 = F_116 ( int , V_12 , V_240 ) ;
V_7 -> V_34 ( V_2 , V_193 , V_18 ) ;
V_193 += V_18 ;
V_12 -= V_18 ;
}
if ( V_12 > 0 )
V_7 -> V_34 ( V_2 , V_193 , V_12 ) ;
V_7 -> V_74 ( V_2 , V_98 , - 1 , - 1 ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
return V_123 & V_144 ? - V_145 : 0 ;
}
static int F_119 ( struct V_1 * V_2 , T_1 V_217 ,
struct V_54 * V_55 )
{
int V_39 , V_218 , V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_246 V_247 ;
int V_192 = V_55 -> V_61 ;
int V_18 ;
T_3 * V_36 = V_55 -> V_57 ;
int V_19 = 0 ;
F_9 ( L_10 ,
V_21 , ( unsigned long long ) V_217 , V_192 ) ;
V_247 = V_2 -> V_71 ;
V_18 = F_107 ( V_2 , V_55 ) ;
if ( F_89 ( V_55 -> V_58 >= V_18 ) ) {
F_9 ( L_11 ,
V_21 ) ;
return - V_15 ;
}
if ( F_89 ( V_217 >= V_2 -> V_146 ||
V_55 -> V_58 + V_192 > ( ( V_2 -> V_146 >> V_7 -> V_47 ) -
( V_217 >> V_7 -> V_47 ) ) * V_18 ) ) {
F_9 ( L_12 ,
V_21 ) ;
return - V_15 ;
}
V_29 = ( int ) ( V_217 >> V_7 -> V_148 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
V_218 = ( int ) ( V_217 >> V_7 -> V_47 ) ;
V_39 = V_218 & V_7 -> V_48 ;
while ( 1 ) {
if ( V_55 -> V_62 == V_211 )
V_19 = V_7 -> V_9 . V_248 ( V_2 , V_7 , V_39 ) ;
else
V_19 = V_7 -> V_9 . V_50 ( V_2 , V_7 , V_39 ) ;
if ( V_19 < 0 )
break;
V_18 = F_108 ( V_18 , V_192 ) ;
V_36 = F_102 ( V_2 , V_36 , V_55 , V_18 ) ;
if ( V_7 -> V_59 & V_236 ) {
if ( ! V_7 -> V_81 )
F_58 ( V_7 -> V_104 ) ;
else
F_49 ( V_2 ) ;
}
V_192 -= V_18 ;
if ( ! V_192 )
break;
V_218 ++ ;
V_39 = V_218 & V_7 -> V_48 ;
if ( ! V_39 ) {
V_29 ++ ;
V_7 -> V_139 ( V_2 , - 1 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
}
}
V_7 -> V_139 ( V_2 , - 1 ) ;
V_55 -> V_238 = V_55 -> V_61 - V_192 ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_71 . V_189 - V_247 . V_189 )
return - V_159 ;
return V_2 -> V_71 . V_190 - V_247 . V_190 ? - V_249 : 0 ;
}
static int F_120 ( struct V_1 * V_2 , T_1 V_217 ,
struct V_54 * V_55 )
{
int V_19 ;
V_55 -> V_237 = 0 ;
if ( V_55 -> V_225 && ( V_217 + V_55 -> V_18 ) > V_2 -> V_146 ) {
F_9 ( L_12 ,
V_21 ) ;
return - V_15 ;
}
if ( V_55 -> V_62 != V_63 &&
V_55 -> V_62 != V_212 &&
V_55 -> V_62 != V_211 )
return - V_250 ;
F_39 ( V_2 , V_239 ) ;
if ( ! V_55 -> V_225 )
V_19 = F_119 ( V_2 , V_217 , V_55 ) ;
else
V_19 = F_106 ( V_2 , V_217 , V_55 ) ;
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_36 , int V_169 , int V_39 )
{
V_7 -> V_34 ( V_2 , V_36 , V_2 -> V_46 ) ;
if ( V_169 )
V_7 -> V_34 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_36 , int V_169 ,
int V_39 )
{
int V_171 = V_7 -> V_9 . V_146 ;
int V_172 = V_7 -> V_9 . V_173 ;
T_3 * V_174 = V_7 -> V_51 ;
int V_175 , V_146 ;
for ( V_175 = V_7 -> V_9 . V_175 ; V_175 > 0 ; V_175 -- ) {
V_7 -> V_34 ( V_2 , V_36 , V_171 ) ;
V_36 += V_171 ;
if ( V_7 -> V_9 . V_176 ) {
V_7 -> V_34 ( V_2 , V_174 , V_7 -> V_9 . V_176 ) ;
V_174 += V_7 -> V_9 . V_176 ;
}
V_7 -> V_34 ( V_2 , V_174 , V_172 ) ;
V_174 += V_172 ;
if ( V_7 -> V_9 . V_177 ) {
V_7 -> V_34 ( V_2 , V_174 , V_7 -> V_9 . V_177 ) ;
V_174 += V_7 -> V_9 . V_177 ;
}
}
V_146 = V_2 -> V_14 - ( V_174 - V_7 -> V_51 ) ;
if ( V_146 )
V_7 -> V_34 ( V_2 , V_174 , V_146 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_36 , int V_169 ,
int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 , V_19 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
T_3 * V_179 = V_7 -> V_180 -> V_181 ;
const T_3 * V_38 = V_36 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 )
V_7 -> V_9 . V_186 ( V_2 , V_38 , & V_179 [ V_56 ] ) ;
V_19 = F_124 ( V_2 , V_179 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_19 )
return V_19 ;
return V_7 -> V_9 . V_251 ( V_2 , V_7 , V_36 , 1 , V_39 ) ;
}
static int F_125 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_36 , int V_169 ,
int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 , V_19 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
T_3 * V_179 = V_7 -> V_180 -> V_181 ;
const T_3 * V_38 = V_36 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
V_7 -> V_9 . V_207 ( V_2 , V_252 ) ;
V_7 -> V_34 ( V_2 , V_38 , V_171 ) ;
V_7 -> V_9 . V_186 ( V_2 , V_38 , & V_179 [ V_56 ] ) ;
}
V_19 = F_124 ( V_2 , V_179 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_34 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_9 V_11 ,
T_9 V_253 , const T_3 * V_36 ,
int V_169 , int V_39 )
{
T_3 * V_254 = V_7 -> V_51 ;
T_3 * V_179 = V_7 -> V_180 -> V_181 ;
int V_255 = V_7 -> V_9 . V_146 ;
int V_256 = V_7 -> V_9 . V_173 ;
int V_257 = V_7 -> V_9 . V_175 ;
T_9 V_194 = V_11 / V_255 ;
T_9 V_195 = ( V_11 + V_253 - 1 ) / V_255 ;
int V_258 = V_2 -> V_14 / V_257 ;
int V_259 , V_19 ;
for ( V_259 = 0 ; V_259 < V_257 ; V_259 ++ ) {
V_7 -> V_9 . V_207 ( V_2 , V_252 ) ;
V_7 -> V_34 ( V_2 , V_36 , V_255 ) ;
if ( ( V_259 < V_194 ) || ( V_259 > V_195 ) )
memset ( V_179 , 0xff , V_256 ) ;
else
V_7 -> V_9 . V_186 ( V_2 , V_36 , V_179 ) ;
if ( ! V_169 || ( V_259 < V_194 ) || ( V_259 > V_195 ) )
memset ( V_254 , 0xff , V_258 ) ;
V_36 += V_255 ;
V_179 += V_256 ;
V_254 += V_258 ;
}
V_179 = V_7 -> V_180 -> V_181 ;
V_19 = F_124 ( V_2 , V_179 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_13 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_34 ( V_2 , V_7 -> V_51 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_36 , int V_169 ,
int V_39 )
{
int V_56 , V_171 = V_7 -> V_9 . V_146 ;
int V_172 = V_7 -> V_9 . V_173 ;
int V_178 = V_7 -> V_9 . V_175 ;
const T_3 * V_38 = V_36 ;
T_3 * V_174 = V_7 -> V_51 ;
for ( V_56 = 0 ; V_178 ; V_178 -- , V_56 += V_172 , V_38 += V_171 ) {
V_7 -> V_9 . V_207 ( V_2 , V_252 ) ;
V_7 -> V_34 ( V_2 , V_38 , V_171 ) ;
if ( V_7 -> V_9 . V_176 ) {
V_7 -> V_34 ( V_2 , V_174 , V_7 -> V_9 . V_176 ) ;
V_174 += V_7 -> V_9 . V_176 ;
}
V_7 -> V_9 . V_186 ( V_2 , V_38 , V_174 ) ;
V_7 -> V_34 ( V_2 , V_174 , V_172 ) ;
V_174 += V_172 ;
if ( V_7 -> V_9 . V_177 ) {
V_7 -> V_34 ( V_2 , V_174 , V_7 -> V_9 . V_177 ) ;
V_174 += V_7 -> V_9 . V_177 ;
}
}
V_56 = V_2 -> V_14 - ( V_174 - V_7 -> V_51 ) ;
if ( V_56 )
V_7 -> V_34 ( V_2 , V_174 , V_56 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_11 , int V_253 , const T_3 * V_36 ,
int V_169 , int V_39 , int V_260 , int V_261 )
{
int V_123 , V_262 ;
if ( ! ( V_7 -> V_59 & V_263 ) &&
V_7 -> V_9 . V_264 )
V_262 = V_11 || ( V_253 < V_2 -> V_46 ) ;
else
V_262 = 0 ;
if ( F_111 ( & V_7 -> V_9 ) )
V_7 -> V_74 ( V_2 , V_90 , 0x00 , V_39 ) ;
if ( F_89 ( V_261 ) )
V_123 = V_7 -> V_9 . V_251 ( V_2 , V_7 , V_36 ,
V_169 , V_39 ) ;
else if ( V_262 )
V_123 = V_7 -> V_9 . V_264 ( V_2 , V_7 , V_11 , V_253 ,
V_36 , V_169 , V_39 ) ;
else
V_123 = V_7 -> V_9 . V_265 ( V_2 , V_7 , V_36 , V_169 ,
V_39 ) ;
if ( V_123 < 0 )
return V_123 ;
V_260 = 0 ;
if ( ! V_260 || ! F_129 ( V_7 ) ) {
if ( F_111 ( & V_7 -> V_9 ) )
V_7 -> V_74 ( V_2 , V_98 , - 1 , - 1 ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
if ( ( V_123 & V_144 ) && ( V_7 -> V_266 ) )
V_123 = V_7 -> V_266 ( V_2 , V_7 , V_68 , V_123 ,
V_39 ) ;
if ( V_123 & V_144 )
return - V_145 ;
} else {
V_7 -> V_74 ( V_2 , V_112 , - 1 , - 1 ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
}
return 0 ;
}
static T_3 * F_130 ( struct V_1 * V_2 , T_3 * V_174 , T_10 V_18 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 ;
memset ( V_7 -> V_51 , 0xff , V_2 -> V_14 ) ;
switch ( V_55 -> V_62 ) {
case V_63 :
case V_211 :
memcpy ( V_7 -> V_51 + V_55 -> V_58 , V_174 , V_18 ) ;
return V_174 + V_18 ;
case V_212 :
V_19 = F_131 ( V_2 , V_174 , V_7 -> V_51 ,
V_55 -> V_58 , V_18 ) ;
F_104 ( V_19 ) ;
return V_174 + V_18 ;
default:
F_21 () ;
}
return NULL ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_267 ,
struct V_54 * V_55 )
{
int V_29 , V_218 , V_39 , V_268 , V_86 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_9 V_269 = V_55 -> V_18 ;
T_9 V_270 = V_55 -> V_61 ;
T_9 V_271 = F_107 ( V_2 , V_55 ) ;
T_3 * V_174 = V_55 -> V_57 ;
T_3 * V_36 = V_55 -> V_225 ;
int V_19 ;
int V_169 = V_174 ? 1 : 0 ;
V_55 -> V_237 = 0 ;
if ( ! V_269 )
return 0 ;
if ( F_133 ( V_267 ) || F_133 ( V_55 -> V_18 ) ) {
F_134 ( L_13 ,
V_21 ) ;
return - V_15 ;
}
V_86 = V_267 & ( V_2 -> V_46 - 1 ) ;
V_29 = ( int ) ( V_267 >> V_7 -> V_148 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
if ( F_41 ( V_2 ) ) {
V_19 = - V_145 ;
goto V_272;
}
V_218 = ( int ) ( V_267 >> V_7 -> V_47 ) ;
V_39 = V_218 & V_7 -> V_48 ;
V_268 = ( 1 << ( V_7 -> V_20 - V_7 -> V_47 ) ) - 1 ;
if ( V_267 <= ( ( T_1 ) V_7 -> V_229 << V_7 -> V_47 ) &&
( ( T_1 ) V_7 -> V_229 << V_7 -> V_47 ) < ( V_267 + V_55 -> V_18 ) )
V_7 -> V_229 = - 1 ;
if ( V_174 && V_55 -> V_58 && ( V_55 -> V_58 + V_55 -> V_61 > V_271 ) ) {
V_19 = - V_15 ;
goto V_272;
}
while ( 1 ) {
int V_173 = V_2 -> V_46 ;
int V_260 = V_269 > V_173 && V_39 != V_268 ;
T_3 * V_273 = V_36 ;
int V_223 ;
int V_274 = ( V_86 || V_269 < V_2 -> V_46 ) ;
if ( V_274 )
V_223 = 1 ;
else if ( V_7 -> V_59 & V_227 )
V_223 = ! F_109 ( V_36 ) ||
! F_110 ( ( unsigned long ) V_36 ,
V_7 -> V_228 ) ;
else
V_223 = 0 ;
if ( V_223 ) {
F_9 ( L_14 ,
V_21 , V_36 ) ;
V_260 = 0 ;
if ( V_274 )
V_173 = F_116 ( int , V_173 - V_86 , V_269 ) ;
V_7 -> V_229 = - 1 ;
memset ( V_7 -> V_180 -> V_230 , 0xff , V_2 -> V_46 ) ;
memcpy ( & V_7 -> V_180 -> V_230 [ V_86 ] , V_36 , V_173 ) ;
V_273 = V_7 -> V_180 -> V_230 ;
}
if ( F_89 ( V_174 ) ) {
T_10 V_18 = F_108 ( V_270 , V_271 ) ;
V_174 = F_130 ( V_2 , V_174 , V_18 , V_55 ) ;
V_270 -= V_18 ;
} else {
memset ( V_7 -> V_51 , 0xff , V_2 -> V_14 ) ;
}
V_19 = F_128 ( V_2 , V_7 , V_86 , V_173 , V_273 ,
V_169 , V_39 , V_260 ,
( V_55 -> V_62 == V_211 ) ) ;
if ( V_19 )
break;
V_269 -= V_173 ;
if ( ! V_269 )
break;
V_86 = 0 ;
V_36 += V_173 ;
V_218 ++ ;
V_39 = V_218 & V_7 -> V_48 ;
if ( ! V_39 ) {
V_29 ++ ;
V_7 -> V_139 ( V_2 , - 1 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
}
}
V_55 -> V_237 = V_55 -> V_18 - V_269 ;
if ( F_89 ( V_174 ) )
V_55 -> V_238 = V_55 -> V_61 ;
V_272:
V_7 -> V_139 ( V_2 , - 1 ) ;
return V_19 ;
}
static int F_135 ( struct V_1 * V_2 , T_1 V_267 , T_10 V_18 ,
T_10 * V_237 , const T_3 * V_36 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_54 V_55 ;
int V_19 ;
F_68 ( V_2 , V_7 , 400 ) ;
F_62 ( V_7 , V_2 , V_68 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_18 = V_18 ;
V_55 . V_225 = ( T_3 * ) V_36 ;
V_55 . V_62 = V_63 ;
V_19 = F_132 ( V_2 , V_267 , & V_55 ) ;
* V_237 = V_55 . V_237 ;
return V_19 ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_267 , T_10 V_18 ,
T_10 * V_237 , const T_3 * V_36 )
{
struct V_54 V_55 ;
int V_19 ;
F_39 ( V_2 , V_68 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_18 = V_18 ;
V_55 . V_225 = ( T_3 * ) V_36 ;
V_55 . V_62 = V_63 ;
V_19 = F_132 ( V_2 , V_267 , & V_55 ) ;
* V_237 = V_55 . V_237 ;
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_267 ,
struct V_54 * V_55 )
{
int V_29 , V_39 , V_123 , V_18 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( L_15 ,
V_21 , ( unsigned int ) V_267 , ( int ) V_55 -> V_61 ) ;
V_18 = F_107 ( V_2 , V_55 ) ;
if ( ( V_55 -> V_58 + V_55 -> V_61 ) > V_18 ) {
F_9 ( L_16 ,
V_21 ) ;
return - V_15 ;
}
if ( F_89 ( V_55 -> V_58 >= V_18 ) ) {
F_9 ( L_17 ,
V_21 ) ;
return - V_15 ;
}
if ( F_89 ( V_267 >= V_2 -> V_146 ||
V_55 -> V_58 + V_55 -> V_61 >
( ( V_2 -> V_146 >> V_7 -> V_47 ) -
( V_267 >> V_7 -> V_47 ) ) * V_18 ) ) {
F_9 ( L_18 ,
V_21 ) ;
return - V_15 ;
}
V_29 = ( int ) ( V_267 >> V_7 -> V_148 ) ;
F_84 ( V_7 , V_29 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
V_39 = ( int ) ( V_267 >> V_7 -> V_47 ) ;
if ( F_41 ( V_2 ) ) {
V_7 -> V_139 ( V_2 , - 1 ) ;
return - V_275 ;
}
if ( V_39 == V_7 -> V_229 )
V_7 -> V_229 = - 1 ;
F_130 ( V_2 , V_55 -> V_57 , V_55 -> V_61 , V_55 ) ;
if ( V_55 -> V_62 == V_211 )
V_123 = V_7 -> V_9 . V_276 ( V_2 , V_7 , V_39 & V_7 -> V_48 ) ;
else
V_123 = V_7 -> V_9 . V_277 ( V_2 , V_7 , V_39 & V_7 -> V_48 ) ;
V_7 -> V_139 ( V_2 , - 1 ) ;
if ( V_123 )
return V_123 ;
V_55 -> V_238 = V_55 -> V_61 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , T_1 V_267 ,
struct V_54 * V_55 )
{
int V_19 = - V_250 ;
V_55 -> V_237 = 0 ;
if ( V_55 -> V_225 && ( V_267 + V_55 -> V_18 ) > V_2 -> V_146 ) {
F_9 ( L_18 ,
V_21 ) ;
return - V_15 ;
}
F_39 ( V_2 , V_68 ) ;
switch ( V_55 -> V_62 ) {
case V_63 :
case V_212 :
case V_211 :
break;
default:
goto V_149;
}
if ( ! V_55 -> V_225 )
V_19 = F_36 ( V_2 , V_267 , V_55 ) ;
else
V_19 = F_132 ( V_2 , V_267 , V_55 ) ;
V_149:
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_138 ( struct V_1 * V_2 , int V_39 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_74 ( V_2 , V_99 , - 1 , V_39 ) ;
V_7 -> V_74 ( V_2 , V_100 , - 1 , - 1 ) ;
return V_7 -> V_143 ( V_2 , V_7 ) ;
}
static int F_139 ( struct V_1 * V_2 , struct V_65 * V_278 )
{
return F_38 ( V_2 , V_278 , 0 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_65 * V_278 ,
int V_78 )
{
int V_39 , V_123 , V_279 , V_19 , V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_18 ;
F_9 ( L_6 ,
V_21 , ( unsigned long long ) V_278 -> V_67 ,
( unsigned long long ) V_278 -> V_18 ) ;
if ( F_8 ( V_2 , V_278 -> V_67 , V_278 -> V_18 ) )
return - V_15 ;
F_39 ( V_2 , V_280 ) ;
V_39 = ( int ) ( V_278 -> V_67 >> V_7 -> V_47 ) ;
V_29 = ( int ) ( V_278 -> V_67 >> V_7 -> V_148 ) ;
V_279 = 1 << ( V_7 -> V_20 - V_7 -> V_47 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
if ( F_41 ( V_2 ) ) {
F_9 ( L_7 ,
V_21 ) ;
V_278 -> V_25 = V_151 ;
goto V_281;
}
V_18 = V_278 -> V_18 ;
V_278 -> V_25 = V_282 ;
while ( V_18 ) {
if ( F_44 ( V_2 , ( ( T_1 ) V_39 ) <<
V_7 -> V_47 , V_78 ) ) {
F_140 ( L_19 ,
V_21 , V_39 ) ;
V_278 -> V_25 = V_151 ;
goto V_281;
}
if ( V_39 <= V_7 -> V_229 && V_7 -> V_229 <
( V_39 + V_279 ) )
V_7 -> V_229 = - 1 ;
V_123 = V_7 -> V_283 ( V_2 , V_39 & V_7 -> V_48 ) ;
if ( ( V_123 & V_144 ) && ( V_7 -> V_266 ) )
V_123 = V_7 -> V_266 ( V_2 , V_7 , V_280 ,
V_123 , V_39 ) ;
if ( V_123 & V_144 ) {
F_9 ( L_20 ,
V_21 , V_39 ) ;
V_278 -> V_25 = V_151 ;
V_278 -> V_284 =
( ( T_1 ) V_39 << V_7 -> V_47 ) ;
goto V_281;
}
V_18 -= ( 1ULL << V_7 -> V_20 ) ;
V_39 += V_279 ;
if ( V_18 && ! ( V_39 & V_7 -> V_48 ) ) {
V_29 ++ ;
V_7 -> V_139 ( V_2 , - 1 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
}
}
V_278 -> V_25 = V_285 ;
V_281:
V_19 = V_278 -> V_25 == V_285 ? 0 : - V_145 ;
V_7 -> V_139 ( V_2 , - 1 ) ;
F_10 ( V_2 ) ;
if ( ! V_19 )
F_141 ( V_278 ) ;
return V_19 ;
}
static void F_142 ( struct V_1 * V_2 )
{
F_9 ( L_21 , V_21 ) ;
F_39 ( V_2 , V_286 ) ;
F_10 ( V_2 ) ;
}
static int F_143 ( struct V_1 * V_2 , T_1 V_287 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_29 = ( int ) ( V_287 >> V_7 -> V_148 ) ;
int V_19 ;
F_39 ( V_2 , V_239 ) ;
V_7 -> V_139 ( V_2 , V_29 ) ;
V_19 = F_44 ( V_2 , V_287 , 0 ) ;
V_7 -> V_139 ( V_2 , - 1 ) ;
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_144 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_19 ;
V_19 = F_143 ( V_2 , V_17 ) ;
if ( V_19 ) {
if ( V_19 > 0 )
return 0 ;
return V_19 ;
}
return F_37 ( V_2 , V_17 ) ;
}
static int F_145 ( struct V_1 * V_2 , T_1 V_17 , T_10 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_11 V_288 ;
T_11 V_289 ;
T_11 V_290 ;
T_11 V_291 ;
if ( ! V_7 -> V_292 || ! V_7 -> V_293 )
return - V_250 ;
V_288 = F_146 ( V_17 , V_2 ) ;
V_289 = F_146 ( V_18 , V_2 ) + V_288 - 1 ;
V_290 = V_288 / V_7 -> V_293 ;
V_291 = V_289 / V_7 -> V_293 ;
return V_7 -> V_292 * ( V_291 - V_290 + 1 ) ;
}
static int F_147 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_294 )
{
int V_123 ;
int V_56 ;
if ( ! V_7 -> V_127 ||
! ( F_148 ( V_7 -> V_295 . V_296 )
& V_297 ) )
return - V_15 ;
V_7 -> V_74 ( V_2 , V_102 , V_67 , - 1 ) ;
for ( V_56 = 0 ; V_56 < V_129 ; ++ V_56 )
V_7 -> V_298 ( V_2 , V_294 [ V_56 ] ) ;
V_123 = V_7 -> V_143 ( V_2 , V_7 ) ;
if ( V_123 & V_144 )
return - V_145 ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_294 )
{
int V_56 ;
if ( ! V_7 -> V_127 ||
! ( F_148 ( V_7 -> V_295 . V_296 )
& V_297 ) )
return - V_15 ;
V_7 -> V_74 ( V_2 , V_299 , V_67 , - 1 ) ;
for ( V_56 = 0 ; V_56 < V_129 ; ++ V_56 )
* V_294 ++ = V_7 -> V_76 ( V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_121 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_25 == V_121 )
F_10 ( V_2 ) ;
else
F_74 ( L_22 ,
V_21 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_121 ) ;
}
static void F_153 ( struct V_6 * V_7 )
{
unsigned int V_203 = V_7 -> V_59 & V_60 ;
if ( ! V_7 -> V_104 )
V_7 -> V_104 = 20 ;
if ( V_7 -> V_74 == NULL )
V_7 -> V_74 = F_56 ;
if ( V_7 -> V_143 == NULL )
V_7 -> V_143 = F_69 ;
if ( ! V_7 -> V_139 )
V_7 -> V_139 = F_20 ;
if ( ! V_7 -> V_131 )
V_7 -> V_131 = F_147 ;
if ( ! V_7 -> V_300 )
V_7 -> V_300 = F_149 ;
if ( ! V_7 -> V_76 || V_7 -> V_76 == F_14 )
V_7 -> V_76 = V_203 ? F_16 : F_14 ;
if ( ! V_7 -> V_301 )
V_7 -> V_301 = F_19 ;
if ( ! V_7 -> V_79 )
V_7 -> V_79 = F_32 ;
if ( ! V_7 -> V_69 )
V_7 -> V_69 = F_35 ;
if ( ! V_7 -> V_34 || V_7 -> V_34 == F_24 )
V_7 -> V_34 = V_203 ? F_28 : F_24 ;
if ( ! V_7 -> V_298 || V_7 -> V_298 == F_22 )
V_7 -> V_298 = V_203 ? F_23 : F_22 ;
if ( ! V_7 -> V_170 || V_7 -> V_170 == F_26 )
V_7 -> V_170 = V_203 ? F_30 : F_26 ;
if ( ! V_7 -> V_302 )
V_7 -> V_302 = V_303 ;
if ( ! V_7 -> V_22 ) {
V_7 -> V_22 = & V_7 -> V_304 ;
F_154 ( V_7 -> V_22 ) ;
}
if ( ! V_7 -> V_228 )
V_7 -> V_228 = 1 ;
}
static void F_155 ( T_3 * V_305 , T_10 V_18 )
{
T_12 V_56 ;
V_305 [ V_18 - 1 ] = 0 ;
for ( V_56 = 0 ; V_56 < V_18 - 1 ; V_56 ++ ) {
if ( V_305 [ V_56 ] < ' ' || V_305 [ V_56 ] > 127 )
V_305 [ V_56 ] = '?' ;
}
F_156 ( V_305 ) ;
}
static T_4 F_157 ( T_4 V_306 , T_6 const * V_38 , T_10 V_18 )
{
int V_56 ;
while ( V_18 -- ) {
V_306 ^= * V_38 ++ << 8 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
V_306 = ( V_306 << 1 ) ^ ( ( V_306 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_306 ;
}
static int F_158 ( struct V_6 * V_7 ,
struct V_307 * V_38 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_308 * V_309 ;
struct V_310 * V_305 ;
struct V_311 * V_9 ;
T_3 * V_312 ;
int V_19 = - V_15 ;
int V_18 ;
int V_56 ;
V_18 = F_148 ( V_38 -> V_313 ) * 16 ;
V_309 = F_159 ( V_18 , V_136 ) ;
if ( ! V_309 )
return - V_137 ;
V_7 -> V_74 ( V_2 , V_314 , 0 , - 1 ) ;
V_7 -> V_74 ( V_2 , V_114 ,
sizeof( * V_38 ) * V_38 -> V_315 , - 1 ) ;
V_7 -> V_170 ( V_2 , ( T_3 * ) V_309 , V_18 ) ;
if ( ( F_157 ( V_316 , ( ( T_3 * ) V_309 ) + 2 , V_18 - 2 )
!= F_148 ( V_309 -> V_306 ) ) ) {
F_9 ( L_23 ) ;
goto V_317;
}
if ( strncmp ( V_309 -> V_318 , L_24 , 4 ) ) {
F_9 ( L_25 ) ;
goto V_317;
}
V_312 = ( T_3 * ) ( V_309 + 1 ) ;
for ( V_56 = 0 ; V_56 < V_319 ; V_56 ++ ) {
V_305 = V_309 -> V_320 + V_56 ;
if ( V_305 -> type == V_321 )
break;
V_312 += V_305 -> V_12 * 16 ;
}
if ( V_56 == V_319 ) {
F_9 ( L_26 ) ;
goto V_317;
}
V_9 = (struct V_311 * ) V_312 ;
if ( ! V_9 -> V_322 ) {
F_9 ( L_27 ) ;
goto V_317;
}
V_7 -> V_323 = V_9 -> V_324 ;
V_7 -> V_325 = 1 << V_9 -> V_322 ;
V_19 = 0 ;
V_317:
F_83 ( V_309 ) ;
return V_19 ;
}
static int F_160 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_307 * V_38 = & V_7 -> V_295 ;
int V_56 , V_326 ;
int V_327 ;
V_7 -> V_74 ( V_2 , V_101 , 0x20 , - 1 ) ;
if ( V_7 -> V_76 ( V_2 ) != 'O' || V_7 -> V_76 ( V_2 ) != 'N' ||
V_7 -> V_76 ( V_2 ) != 'F' || V_7 -> V_76 ( V_2 ) != 'I' )
return 0 ;
V_7 -> V_74 ( V_2 , V_314 , 0 , - 1 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
for ( V_326 = 0 ; V_326 < sizeof( * V_38 ) ; V_326 ++ )
( ( T_3 * ) V_38 ) [ V_326 ] = V_7 -> V_76 ( V_2 ) ;
if ( F_157 ( V_316 , ( T_3 * ) V_38 , 254 ) ==
F_148 ( V_38 -> V_306 ) ) {
break;
}
}
if ( V_56 == 3 ) {
F_74 ( L_28 ) ;
return 0 ;
}
V_327 = F_148 ( V_38 -> V_328 ) ;
if ( V_327 & ( 1 << 5 ) )
V_7 -> V_127 = 23 ;
else if ( V_327 & ( 1 << 4 ) )
V_7 -> V_127 = 22 ;
else if ( V_327 & ( 1 << 3 ) )
V_7 -> V_127 = 21 ;
else if ( V_327 & ( 1 << 2 ) )
V_7 -> V_127 = 20 ;
else if ( V_327 & ( 1 << 1 ) )
V_7 -> V_127 = 10 ;
if ( ! V_7 -> V_127 ) {
F_161 ( L_29 , V_327 ) ;
return 0 ;
}
F_155 ( V_38 -> V_329 , sizeof( V_38 -> V_329 ) ) ;
F_155 ( V_38 -> V_330 , sizeof( V_38 -> V_330 ) ) ;
if ( ! V_2 -> V_331 )
V_2 -> V_331 = V_38 -> V_330 ;
V_2 -> V_46 = F_162 ( V_38 -> V_332 ) ;
V_2 -> V_45 = 1 << ( F_80 ( F_162 ( V_38 -> V_279 ) ) - 1 ) ;
V_2 -> V_45 *= V_2 -> V_46 ;
V_2 -> V_14 = F_148 ( V_38 -> V_333 ) ;
V_7 -> V_96 = 1 << ( F_80 ( F_162 ( V_38 -> V_334 ) ) - 1 ) ;
V_7 -> V_96 *= ( T_2 ) V_2 -> V_45 * V_38 -> V_335 ;
V_7 -> V_336 = V_38 -> V_336 ;
V_7 -> V_292 = F_148 ( V_38 -> V_337 ) ;
V_7 -> V_293 = F_162 ( V_38 -> V_334 ) ;
if ( F_163 ( V_7 ) & V_338 )
V_7 -> V_59 |= V_60 ;
if ( V_38 -> V_324 != 0xff ) {
V_7 -> V_323 = V_38 -> V_324 ;
V_7 -> V_325 = 512 ;
} else if ( V_7 -> V_127 >= 21 &&
( F_163 ( V_7 ) & V_339 ) ) {
if ( V_2 -> V_46 > 512 && V_7 -> V_74 == F_56 )
V_7 -> V_74 = F_61 ;
if ( F_158 ( V_7 , V_38 ) )
F_140 ( L_30 ) ;
} else {
F_140 ( L_31 ) ;
}
return 1 ;
}
static int F_164 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_340 * V_38 = & V_7 -> V_341 ;
struct V_342 * V_9 ;
int V_327 ;
int V_56 , V_326 ;
V_7 -> V_74 ( V_2 , V_101 , 0x40 , - 1 ) ;
if ( V_7 -> V_76 ( V_2 ) != 'J' || V_7 -> V_76 ( V_2 ) != 'E' ||
V_7 -> V_76 ( V_2 ) != 'D' || V_7 -> V_76 ( V_2 ) != 'E' ||
V_7 -> V_76 ( V_2 ) != 'C' )
return 0 ;
V_7 -> V_74 ( V_2 , V_314 , 0x40 , - 1 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
for ( V_326 = 0 ; V_326 < sizeof( * V_38 ) ; V_326 ++ )
( ( T_3 * ) V_38 ) [ V_326 ] = V_7 -> V_76 ( V_2 ) ;
if ( F_157 ( V_316 , ( T_3 * ) V_38 , 510 ) ==
F_148 ( V_38 -> V_306 ) )
break;
}
if ( V_56 == 3 ) {
F_74 ( L_32 ) ;
return 0 ;
}
V_327 = F_148 ( V_38 -> V_328 ) ;
if ( V_327 & ( 1 << 2 ) )
V_7 -> V_343 = 10 ;
else if ( V_327 & ( 1 << 1 ) )
V_7 -> V_343 = 1 ;
if ( ! V_7 -> V_343 ) {
F_161 ( L_33 , V_327 ) ;
return 0 ;
}
F_155 ( V_38 -> V_329 , sizeof( V_38 -> V_329 ) ) ;
F_155 ( V_38 -> V_330 , sizeof( V_38 -> V_330 ) ) ;
if ( ! V_2 -> V_331 )
V_2 -> V_331 = V_38 -> V_330 ;
V_2 -> V_46 = F_162 ( V_38 -> V_332 ) ;
V_2 -> V_45 = 1 << ( F_80 ( F_162 ( V_38 -> V_279 ) ) - 1 ) ;
V_2 -> V_45 *= V_2 -> V_46 ;
V_2 -> V_14 = F_148 ( V_38 -> V_333 ) ;
V_7 -> V_96 = 1 << ( F_80 ( F_162 ( V_38 -> V_334 ) ) - 1 ) ;
V_7 -> V_96 *= ( T_2 ) V_2 -> V_45 * V_38 -> V_335 ;
V_7 -> V_336 = V_38 -> V_336 ;
if ( F_165 ( V_7 ) & V_344 )
V_7 -> V_59 |= V_60 ;
V_9 = & V_38 -> V_345 [ 0 ] ;
if ( V_9 -> V_322 >= 9 ) {
V_7 -> V_323 = V_9 -> V_324 ;
V_7 -> V_325 = 1 << V_9 -> V_322 ;
} else {
F_140 ( L_27 ) ;
}
return 1 ;
}
static int F_166 ( T_6 * V_346 , int V_347 , int V_348 )
{
int V_56 , V_326 ;
for ( V_56 = 0 ; V_56 < V_348 ; V_56 ++ )
for ( V_326 = V_56 + V_348 ; V_326 < V_347 ; V_326 += V_348 )
if ( V_346 [ V_56 ] != V_346 [ V_326 ] )
return 0 ;
return 1 ;
}
static int F_167 ( T_6 * V_346 , int V_347 )
{
int V_349 , V_348 ;
for ( V_349 = V_347 - 1 ; V_349 >= 0 ; V_349 -- )
if ( V_346 [ V_349 ] )
break;
if ( V_349 < 0 )
return 0 ;
for ( V_348 = 1 ; V_348 < V_347 ; V_348 ++ )
if ( F_166 ( V_346 , V_347 , V_348 ) )
break;
if ( V_348 < V_347 )
return V_348 ;
if ( V_349 < V_347 - 1 )
return V_349 + 1 ;
return V_347 ;
}
static int F_168 ( T_6 V_350 )
{
int V_351 ;
V_351 = V_350 & V_352 ;
V_351 >>= V_353 ;
return V_351 + 1 ;
}
void F_169 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_354 ;
T_6 * V_346 = V_7 -> V_355 . V_161 ;
V_7 -> V_336 = F_168 ( V_346 [ 2 ] ) ;
V_354 = V_346 [ 3 ] ;
V_2 -> V_46 = 1024 << ( V_354 & 0x03 ) ;
V_354 >>= 2 ;
V_2 -> V_14 = ( 8 << ( V_354 & 0x01 ) ) * ( V_2 -> V_46 >> 9 ) ;
V_354 >>= 2 ;
V_2 -> V_45 = ( 64 * 1024 ) << ( V_354 & 0x03 ) ;
V_354 >>= 2 ;
if ( V_354 & 0x1 )
V_7 -> V_59 |= V_60 ;
}
static void F_170 ( struct V_6 * V_7 , struct V_356 * type )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
V_2 -> V_45 = type -> V_45 ;
V_2 -> V_46 = type -> V_357 ;
V_2 -> V_14 = V_2 -> V_46 / 32 ;
V_7 -> V_336 = 1 ;
}
static void F_171 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
if ( V_2 -> V_46 > 512 || ( V_7 -> V_59 & V_60 ) )
V_7 -> V_52 = V_358 ;
else
V_7 -> V_52 = V_359 ;
}
static inline bool F_172 ( struct V_356 * type )
{
return type -> V_360 ;
}
static bool F_173 ( struct V_6 * V_7 ,
struct V_356 * type )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
T_6 * V_346 = V_7 -> V_355 . V_161 ;
if ( ! strncmp ( type -> V_355 , V_346 , type -> V_360 ) ) {
V_2 -> V_46 = type -> V_357 ;
V_2 -> V_45 = type -> V_45 ;
V_2 -> V_14 = type -> V_14 ;
V_7 -> V_336 = F_168 ( V_346 [ 2 ] ) ;
V_7 -> V_96 = ( T_2 ) type -> V_96 << 20 ;
V_7 -> V_59 |= type -> V_59 ;
V_7 -> V_323 = F_174 ( type ) ;
V_7 -> V_325 = F_175 ( type ) ;
V_7 -> V_130 =
type -> V_130 ;
if ( ! V_2 -> V_331 )
V_2 -> V_331 = type -> V_331 ;
return true ;
}
return false ;
}
static void F_176 ( struct V_6 * V_7 )
{
if ( V_7 -> V_329 . V_361 && V_7 -> V_329 . V_361 -> V_55 &&
V_7 -> V_329 . V_361 -> V_55 -> V_362 )
V_7 -> V_329 . V_361 -> V_55 -> V_362 ( V_7 ) ;
else
F_169 ( V_7 ) ;
}
static int F_177 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_329 . V_361 || ! V_7 -> V_329 . V_361 -> V_55 ||
! V_7 -> V_329 . V_361 -> V_55 -> V_363 )
return 0 ;
return V_7 -> V_329 . V_361 -> V_55 -> V_363 ( V_7 ) ;
}
static void F_178 ( struct V_6 * V_7 )
{
if ( V_7 -> V_329 . V_361 && V_7 -> V_329 . V_361 -> V_55 &&
V_7 -> V_329 . V_361 -> V_55 -> V_364 )
V_7 -> V_329 . V_361 -> V_55 -> V_364 ( V_7 ) ;
}
static int F_179 ( struct V_6 * V_7 , struct V_356 * type )
{
const struct V_365 * V_329 ;
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_203 ;
int V_56 , V_19 ;
T_6 * V_346 = V_7 -> V_355 . V_161 ;
T_6 V_366 , V_367 ;
F_84 ( V_7 , 0 ) ;
V_7 -> V_139 ( V_2 , 0 ) ;
V_7 -> V_74 ( V_2 , V_101 , 0x00 , - 1 ) ;
V_366 = V_7 -> V_76 ( V_2 ) ;
V_367 = V_7 -> V_76 ( V_2 ) ;
V_7 -> V_74 ( V_2 , V_101 , 0x00 , - 1 ) ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
V_346 [ V_56 ] = V_7 -> V_76 ( V_2 ) ;
if ( V_346 [ 0 ] != V_366 || V_346 [ 1 ] != V_367 ) {
F_161 ( L_34 ,
V_366 , V_367 , V_346 [ 0 ] , V_346 [ 1 ] ) ;
return - V_368 ;
}
V_7 -> V_355 . V_18 = F_167 ( V_346 , 8 ) ;
V_329 = F_180 ( V_366 ) ;
V_7 -> V_329 . V_361 = V_329 ;
if ( ! type )
type = V_369 ;
V_203 = V_7 -> V_59 & V_60 ;
V_7 -> V_59 &= ~ V_60 ;
for (; type -> V_331 != NULL ; type ++ ) {
if ( F_172 ( type ) ) {
if ( F_173 ( V_7 , type ) )
goto V_370;
} else if ( V_367 == type -> V_367 ) {
break;
}
}
V_7 -> V_127 = 0 ;
if ( ! type -> V_331 || ! type -> V_357 ) {
if ( F_160 ( V_7 ) )
goto V_370;
if ( F_164 ( V_7 ) )
goto V_370;
}
if ( ! type -> V_331 )
return - V_368 ;
if ( ! V_2 -> V_331 )
V_2 -> V_331 = type -> V_331 ;
V_7 -> V_96 = ( T_2 ) type -> V_96 << 20 ;
if ( ! type -> V_357 )
F_176 ( V_7 ) ;
else
F_170 ( V_7 , type ) ;
V_7 -> V_59 |= type -> V_59 ;
V_370:
if ( V_7 -> V_59 & V_371 ) {
F_70 ( V_203 & V_60 ) ;
F_153 ( V_7 ) ;
} else if ( V_203 != ( V_7 -> V_59 & V_60 ) ) {
F_161 ( L_35 ,
V_366 , V_367 ) ;
F_161 ( L_36 , F_181 ( V_329 ) ,
V_2 -> V_331 ) ;
F_140 ( L_37 , V_203 ? 16 : 8 ,
( V_7 -> V_59 & V_60 ) ? 16 : 8 ) ;
return - V_15 ;
}
F_171 ( V_7 ) ;
V_7 -> V_47 = F_182 ( V_2 -> V_46 ) - 1 ;
V_7 -> V_48 = ( V_7 -> V_96 >> V_7 -> V_47 ) - 1 ;
V_7 -> V_372 = V_7 -> V_20 =
F_182 ( V_2 -> V_45 ) - 1 ;
if ( V_7 -> V_96 & 0xffffffff )
V_7 -> V_148 = F_182 ( ( unsigned ) V_7 -> V_96 ) - 1 ;
else {
V_7 -> V_148 = F_182 ( ( unsigned ) ( V_7 -> V_96 >> 32 ) ) ;
V_7 -> V_148 += 32 - 1 ;
}
V_7 -> V_53 = 8 ;
V_7 -> V_283 = F_138 ;
if ( V_2 -> V_46 > 512 && V_7 -> V_74 == F_56 )
V_7 -> V_74 = F_61 ;
V_19 = F_177 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_161 ( L_35 ,
V_366 , V_367 ) ;
if ( V_7 -> V_127 )
F_161 ( L_36 , F_181 ( V_329 ) ,
V_7 -> V_295 . V_330 ) ;
else if ( V_7 -> V_343 )
F_161 ( L_36 , F_181 ( V_329 ) ,
V_7 -> V_341 . V_330 ) ;
else
F_161 ( L_36 , F_181 ( V_329 ) ,
type -> V_331 ) ;
F_161 ( L_38 ,
( int ) ( V_7 -> V_96 >> 20 ) , F_183 ( V_7 ) ? L_39 : L_40 ,
V_2 -> V_45 >> 10 , V_2 -> V_46 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_184 ( struct V_373 * V_374 )
{
const char * V_375 ;
int V_133 , V_56 ;
V_133 = F_185 ( V_374 , L_41 , & V_375 ) ;
if ( V_133 < 0 )
return V_133 ;
for ( V_56 = 0 ; V_56 < F_186 ( V_376 ) ; V_56 ++ )
if ( ! strcasecmp ( V_375 , V_376 [ V_56 ] ) )
return V_56 ;
if ( ! strcasecmp ( V_375 , L_42 ) )
return V_377 ;
return - V_368 ;
}
static int F_187 ( struct V_373 * V_374 )
{
const char * V_375 ;
int V_133 , V_56 ;
V_133 = F_185 ( V_374 , L_43 , & V_375 ) ;
if ( ! V_133 ) {
for ( V_56 = V_378 ; V_56 < F_186 ( V_379 ) ; V_56 ++ )
if ( ! strcasecmp ( V_375 , V_379 [ V_56 ] ) )
return V_56 ;
return - V_368 ;
}
V_133 = F_185 ( V_374 , L_41 , & V_375 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! strcasecmp ( V_375 , L_44 ) )
return V_378 ;
else if ( ! strcasecmp ( V_375 , L_42 ) )
return V_380 ;
return - V_368 ;
}
static int F_188 ( struct V_373 * V_374 )
{
int V_19 ;
T_11 V_327 ;
V_19 = F_189 ( V_374 , L_45 , & V_327 ) ;
return V_19 ? V_19 : V_327 ;
}
static int F_190 ( struct V_373 * V_374 )
{
int V_19 ;
T_11 V_327 ;
V_19 = F_189 ( V_374 , L_46 , & V_327 ) ;
return V_19 ? V_19 : V_327 ;
}
static int F_191 ( struct V_373 * V_374 )
{
T_11 V_327 ;
if ( F_189 ( V_374 , L_47 , & V_327 ) )
return 8 ;
switch ( V_327 ) {
case 8 :
case 16 :
return V_327 ;
default:
return - V_145 ;
}
}
static bool F_192 ( struct V_373 * V_374 )
{
return F_193 ( V_374 , L_48 ) ;
}
static int F_194 ( struct V_6 * V_7 )
{
struct V_373 * V_381 = F_195 ( V_7 ) ;
int V_382 , V_383 , V_384 , V_385 ;
if ( ! V_381 )
return 0 ;
if ( F_191 ( V_381 ) == 16 )
V_7 -> V_59 |= V_60 ;
if ( F_192 ( V_381 ) )
V_7 -> V_43 |= V_386 ;
V_382 = F_184 ( V_381 ) ;
V_383 = F_187 ( V_381 ) ;
V_384 = F_190 ( V_381 ) ;
V_385 = F_188 ( V_381 ) ;
if ( V_382 >= 0 )
V_7 -> V_9 . V_62 = V_382 ;
if ( V_383 >= 0 )
V_7 -> V_9 . V_387 = V_383 ;
if ( V_384 >= 0 )
V_7 -> V_9 . V_206 = V_384 ;
if ( V_385 > 0 )
V_7 -> V_9 . V_146 = V_385 ;
if ( F_193 ( V_381 , L_49 ) )
V_7 -> V_9 . V_59 |= V_388 ;
return 0 ;
}
int F_196 ( struct V_1 * V_2 , int V_389 ,
struct V_356 * V_390 )
{
int V_56 , V_391 , V_392 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 ;
V_19 = F_194 ( V_7 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_2 -> V_331 && V_2 -> V_393 . V_394 )
V_2 -> V_331 = F_197 ( V_2 -> V_393 . V_394 ) ;
if ( ( ! V_7 -> V_74 || ! V_7 -> V_139 ) && ! V_7 -> V_30 ) {
F_74 ( L_50 ) ;
return - V_15 ;
}
F_153 ( V_7 ) ;
V_19 = F_179 ( V_7 , V_390 ) ;
if ( V_19 ) {
if ( ! ( V_7 -> V_59 & V_395 ) )
F_140 ( L_51 ) ;
V_7 -> V_139 ( V_2 , - 1 ) ;
return V_19 ;
}
V_19 = F_76 ( V_7 ) ;
if ( V_19 )
goto V_396;
V_19 = F_75 ( V_7 ) ;
if ( V_19 )
goto V_396;
V_391 = V_7 -> V_355 . V_161 [ 0 ] ;
V_392 = V_7 -> V_355 . V_161 [ 1 ] ;
V_7 -> V_139 ( V_2 , - 1 ) ;
for ( V_56 = 1 ; V_56 < V_389 ; V_56 ++ ) {
F_84 ( V_7 , V_56 ) ;
V_7 -> V_139 ( V_2 , V_56 ) ;
V_7 -> V_74 ( V_2 , V_101 , 0x00 , - 1 ) ;
if ( V_391 != V_7 -> V_76 ( V_2 ) ||
V_392 != V_7 -> V_76 ( V_2 ) ) {
V_7 -> V_139 ( V_2 , - 1 ) ;
break;
}
V_7 -> V_139 ( V_2 , - 1 ) ;
}
if ( V_56 > 1 )
F_161 ( L_52 , V_56 ) ;
V_7 -> V_397 = V_56 ;
V_2 -> V_146 = V_56 * V_7 -> V_96 ;
return 0 ;
V_396:
F_178 ( V_7 ) ;
return V_19 ;
}
static int F_198 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_70 ( V_9 -> V_62 != V_377 ) )
return - V_15 ;
switch ( V_9 -> V_387 ) {
case V_378 :
V_9 -> V_186 = V_398 ;
V_9 -> V_188 = V_399 ;
V_9 -> V_233 = F_94 ;
V_9 -> V_232 = F_97 ;
V_9 -> V_265 = F_123 ;
V_9 -> V_185 = F_92 ;
V_9 -> V_251 = F_121 ;
V_9 -> V_50 = F_114 ;
V_9 -> V_277 = F_117 ;
if ( ! V_9 -> V_146 )
V_9 -> V_146 = 256 ;
V_9 -> V_173 = 3 ;
V_9 -> V_206 = 1 ;
return 0 ;
case V_380 :
if ( ! F_199 () ) {
F_200 ( 1 , L_53 ) ;
return - V_15 ;
}
V_9 -> V_186 = V_400 ;
V_9 -> V_188 = V_401 ;
V_9 -> V_233 = F_94 ;
V_9 -> V_232 = F_97 ;
V_9 -> V_265 = F_123 ;
V_9 -> V_185 = F_92 ;
V_9 -> V_251 = F_121 ;
V_9 -> V_50 = F_114 ;
V_9 -> V_277 = F_117 ;
if ( ! V_9 -> V_146 && ( V_2 -> V_14 >= 64 ) ) {
V_9 -> V_146 = 512 ;
V_9 -> V_206 = 4 ;
}
if ( ! V_2 -> V_402 ) {
if ( V_2 -> V_14 < 64 ) {
F_200 ( 1 , L_54 ) ;
return - V_15 ;
}
F_201 ( V_2 , & V_403 ) ;
}
if ( V_2 -> V_402 == & V_403 &&
V_9 -> V_59 & V_388 ) {
int V_175 , V_173 ;
V_9 -> V_146 = 1024 ;
V_175 = V_2 -> V_46 / V_9 -> V_146 ;
V_173 = ( V_2 -> V_14 - 2 ) / V_175 ;
V_9 -> V_206 = V_173 * 8 / F_80 ( 8 * V_9 -> V_146 ) ;
}
V_9 -> V_173 = 0 ;
V_9 -> V_404 = F_202 ( V_2 ) ;
if ( ! V_9 -> V_404 ) {
F_200 ( 1 , L_55 ) ;
return - V_15 ;
}
return 0 ;
default:
F_200 ( 1 , L_56 ) ;
return - V_15 ;
}
}
static bool F_203 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_405 , V_406 ;
if ( V_9 -> V_146 == 0 || V_7 -> V_325 == 0 )
return true ;
V_405 = ( V_2 -> V_46 * V_9 -> V_206 ) / V_9 -> V_146 ;
V_406 = ( V_2 -> V_46 * V_7 -> V_323 ) / V_7 -> V_325 ;
return V_405 >= V_406 && V_9 -> V_206 >= V_7 -> V_323 ;
}
static bool F_204 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_111 ( V_9 ) )
return false ;
return ( ! V_9 -> V_233 || ! V_9 -> V_265 ||
! V_9 -> V_185 || ! V_9 -> V_251 ||
( F_112 ( V_7 ) && ! V_9 -> V_232 ) ||
( F_205 ( V_7 ) && ! V_9 -> V_264 &&
V_9 -> V_207 && V_9 -> V_186 ) ) ;
}
int F_206 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_407 * V_408 = NULL ;
int V_19 ;
if ( F_70 ( ( V_7 -> V_43 & V_64 ) &&
! ( V_7 -> V_43 & V_386 ) ) ) {
V_19 = - V_15 ;
goto V_409;
}
if ( F_204 ( V_7 ) ) {
F_74 ( L_57 ) ;
V_19 = - V_15 ;
goto V_409;
}
if ( ! ( V_7 -> V_59 & V_410 ) ) {
V_408 = F_79 ( sizeof( * V_408 ) , V_136 ) ;
if ( ! V_408 ) {
V_19 = - V_137 ;
goto V_409;
}
V_408 -> V_181 = F_159 ( V_2 -> V_14 , V_136 ) ;
if ( ! V_408 -> V_181 ) {
V_19 = - V_137 ;
goto V_411;
}
V_408 -> V_183 = F_159 ( V_2 -> V_14 , V_136 ) ;
if ( ! V_408 -> V_183 ) {
V_19 = - V_137 ;
goto V_411;
}
V_408 -> V_230 = F_159 ( V_2 -> V_46 + V_2 -> V_14 ,
V_136 ) ;
if ( ! V_408 -> V_230 ) {
V_19 = - V_137 ;
goto V_411;
}
V_7 -> V_180 = V_408 ;
} else {
if ( ! V_7 -> V_180 ) {
V_19 = - V_137 ;
goto V_409;
}
}
V_7 -> V_51 = V_7 -> V_180 -> V_230 + V_2 -> V_46 ;
if ( ! V_2 -> V_402 &&
! ( V_9 -> V_62 == V_377 && V_9 -> V_387 == V_380 ) ) {
switch ( V_2 -> V_14 ) {
case 8 :
case 16 :
F_201 ( V_2 , & V_412 ) ;
break;
case 64 :
case 128 :
F_201 ( V_2 , & V_413 ) ;
break;
default:
F_200 ( 1 , L_58 ,
V_2 -> V_14 ) ;
V_19 = - V_15 ;
goto V_411;
}
}
switch ( V_9 -> V_62 ) {
case V_414 :
if ( ! V_9 -> V_186 || ! V_9 -> V_188 || ! V_9 -> V_207 ) {
F_200 ( 1 , L_59 ) ;
V_19 = - V_15 ;
goto V_411;
}
if ( ! V_9 -> V_233 )
V_9 -> V_233 = F_100 ;
case V_415 :
if ( ! V_9 -> V_233 )
V_9 -> V_233 = F_99 ;
if ( ! V_9 -> V_265 )
V_9 -> V_265 = F_125 ;
if ( ! V_9 -> V_185 )
V_9 -> V_185 = F_92 ;
if ( ! V_9 -> V_251 )
V_9 -> V_251 = F_121 ;
if ( ! V_9 -> V_50 )
V_9 -> V_50 = F_114 ;
if ( ! V_9 -> V_277 )
V_9 -> V_277 = F_117 ;
if ( ! V_9 -> V_232 )
V_9 -> V_232 = F_97 ;
if ( ! V_9 -> V_264 && V_9 -> V_207 && V_9 -> V_186 )
V_9 -> V_264 = F_126 ;
case V_416 :
if ( ( ! V_9 -> V_186 || ! V_9 -> V_188 || ! V_9 -> V_207 ) &&
( ! V_9 -> V_233 ||
V_9 -> V_233 == F_99 ||
! V_9 -> V_265 ||
V_9 -> V_265 == F_125 ) ) {
F_200 ( 1 , L_59 ) ;
V_19 = - V_15 ;
goto V_411;
}
if ( ! V_9 -> V_233 )
V_9 -> V_233 = F_101 ;
if ( ! V_9 -> V_265 )
V_9 -> V_265 = F_127 ;
if ( ! V_9 -> V_185 )
V_9 -> V_185 = F_93 ;
if ( ! V_9 -> V_251 )
V_9 -> V_251 = F_122 ;
if ( ! V_9 -> V_50 )
V_9 -> V_50 = F_115 ;
if ( ! V_9 -> V_277 )
V_9 -> V_277 = F_118 ;
if ( V_2 -> V_46 >= V_9 -> V_146 ) {
if ( ! V_9 -> V_206 ) {
F_200 ( 1 , L_60 ) ;
V_19 = - V_15 ;
goto V_411;
}
break;
}
F_140 ( L_61 ,
V_9 -> V_146 , V_2 -> V_46 ) ;
V_9 -> V_62 = V_377 ;
V_9 -> V_387 = V_378 ;
case V_377 :
V_19 = F_198 ( V_2 ) ;
if ( V_19 ) {
V_19 = - V_15 ;
goto V_411;
}
break;
case V_417 :
F_140 ( L_62 ) ;
V_9 -> V_233 = F_92 ;
V_9 -> V_265 = F_121 ;
V_9 -> V_50 = F_114 ;
V_9 -> V_185 = F_92 ;
V_9 -> V_251 = F_121 ;
V_9 -> V_277 = F_117 ;
V_9 -> V_146 = V_2 -> V_46 ;
V_9 -> V_173 = 0 ;
V_9 -> V_206 = 0 ;
break;
default:
F_200 ( 1 , L_63 , V_9 -> V_62 ) ;
V_19 = - V_15 ;
goto V_411;
}
if ( ! V_9 -> V_248 )
V_9 -> V_248 = V_9 -> V_50 ;
if ( ! V_9 -> V_276 )
V_9 -> V_276 = V_9 -> V_277 ;
V_2 -> V_384 = V_9 -> V_206 ;
V_2 -> V_418 = V_9 -> V_146 ;
V_9 -> V_175 = V_2 -> V_46 / V_9 -> V_146 ;
if ( V_9 -> V_175 * V_9 -> V_146 != V_2 -> V_46 ) {
F_200 ( 1 , L_64 ) ;
V_19 = - V_15 ;
goto V_411;
}
V_9 -> V_13 = V_9 -> V_175 * V_9 -> V_173 ;
V_19 = F_207 ( V_2 ) ;
if ( V_19 < 0 )
V_19 = 0 ;
V_2 -> V_419 = V_19 ;
if ( ! F_203 ( V_2 ) )
F_140 ( L_65 ,
V_2 -> V_331 ) ;
if ( ! ( V_7 -> V_59 & V_263 ) && F_183 ( V_7 ) ) {
switch ( V_9 -> V_175 ) {
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
V_7 -> V_421 = V_2 -> V_46 >> V_2 -> V_420 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_229 = - 1 ;
switch ( V_9 -> V_62 ) {
case V_377 :
if ( V_7 -> V_47 > 9 )
V_7 -> V_59 |= V_422 ;
break;
default:
break;
}
V_2 -> type = F_183 ( V_7 ) ? V_423 : V_424 ;
V_2 -> V_425 = ( V_7 -> V_59 & V_426 ) ? V_427 :
V_428 ;
V_2 -> V_429 = F_139 ;
V_2 -> V_430 = NULL ;
V_2 -> V_431 = NULL ;
V_2 -> V_432 = F_113 ;
V_2 -> V_433 = F_136 ;
V_2 -> V_434 = F_135 ;
V_2 -> V_435 = F_120 ;
V_2 -> V_436 = F_137 ;
V_2 -> V_437 = F_142 ;
V_2 -> V_438 = NULL ;
V_2 -> V_439 = NULL ;
V_2 -> V_440 = F_150 ;
V_2 -> V_441 = F_151 ;
V_2 -> V_442 = F_152 ;
V_2 -> V_443 = F_42 ;
V_2 -> V_444 = F_143 ;
V_2 -> V_445 = F_144 ;
V_2 -> V_446 = F_145 ;
V_2 -> V_447 = V_2 -> V_46 ;
if ( ! V_2 -> V_448 )
V_2 -> V_448 = F_208 ( V_2 -> V_384 * 3 , 4 ) ;
if ( V_7 -> V_59 & V_449 )
return 0 ;
V_19 = V_7 -> V_302 ( V_2 ) ;
if ( V_19 )
goto V_411;
return 0 ;
V_411:
if ( V_408 ) {
F_83 ( V_408 -> V_230 ) ;
F_83 ( V_408 -> V_183 ) ;
F_83 ( V_408 -> V_181 ) ;
F_83 ( V_408 ) ;
}
V_409:
F_178 ( V_7 ) ;
return V_19 ;
}
int F_209 ( struct V_1 * V_2 , int V_389 )
{
int V_19 ;
V_19 = F_196 ( V_2 , V_389 , NULL ) ;
if ( ! V_19 )
V_19 = F_206 ( V_2 ) ;
return V_19 ;
}
void F_210 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 . V_62 == V_377 &&
V_7 -> V_9 . V_387 == V_380 )
F_211 ( (struct V_450 * ) V_7 -> V_9 . V_404 ) ;
F_82 ( V_7 ) ;
F_83 ( V_7 -> V_70 ) ;
if ( ! ( V_7 -> V_59 & V_410 ) && V_7 -> V_180 ) {
F_83 ( V_7 -> V_180 -> V_230 ) ;
F_83 ( V_7 -> V_180 -> V_183 ) ;
F_83 ( V_7 -> V_180 -> V_181 ) ;
F_83 ( V_7 -> V_180 ) ;
}
if ( V_7 -> V_451 && V_7 -> V_451 -> V_59
& V_452 )
F_83 ( V_7 -> V_451 ) ;
F_178 ( V_7 ) ;
}
void F_212 ( struct V_1 * V_2 )
{
F_213 ( V_2 ) ;
F_210 ( F_2 ( V_2 ) ) ;
}
