static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_3 > 1 )
return - V_10 ;
if ( ! V_3 ) {
V_5 -> V_11 = 0 ;
if ( V_2 -> V_12 == 16 )
V_5 -> V_13 = 4 ;
else
V_5 -> V_13 = 3 ;
} else {
if ( V_2 -> V_12 == 8 )
return - V_10 ;
V_5 -> V_11 = 6 ;
V_5 -> V_13 = V_9 -> V_14 - 4 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 > 1 )
return - V_10 ;
if ( V_2 -> V_12 == 16 ) {
if ( V_3 )
return - V_10 ;
V_5 -> V_13 = 8 ;
V_5 -> V_11 = 8 ;
} else {
V_5 -> V_13 = 2 ;
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
V_5 -> V_13 = V_9 -> V_14 ;
V_5 -> V_11 = V_2 -> V_12 - V_5 -> V_13 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_3 )
return - V_10 ;
V_5 -> V_13 = V_2 -> V_12 - V_9 -> V_14 - 2 ;
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
switch ( V_2 -> V_12 ) {
case 64 :
V_5 -> V_11 = 40 ;
break;
case 128 :
V_5 -> V_11 = 80 ;
break;
default:
return - V_15 ;
}
V_5 -> V_13 = V_9 -> V_14 ;
if ( V_5 -> V_11 + V_5 -> V_13 > V_2 -> V_12 )
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
switch ( V_2 -> V_12 ) {
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
V_5 -> V_13 = V_16 - 2 ;
} else {
V_5 -> V_11 = V_16 + V_9 -> V_14 ;
V_5 -> V_13 = V_2 -> V_12 - V_5 -> V_11 ;
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
case V_93 :
if ( V_86 == - 1 && V_87 == - 1 )
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
if ( V_86 == - 1 && V_87 == - 1 )
return;
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
static int F_71 ( struct V_6 * V_7 , int V_29 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
const struct V_124 * V_125 ;
int V_19 ;
if ( ! V_7 -> V_126 )
return 0 ;
V_125 = F_73 () ;
V_19 = V_7 -> V_126 ( V_2 , V_29 , V_125 ) ;
if ( V_19 )
F_74 ( L_4 ) ;
return V_19 ;
}
static int F_75 ( struct V_6 * V_7 , int V_29 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_19 ;
if ( ! V_7 -> V_126 || ! V_7 -> V_106 )
return 0 ;
if ( V_7 -> V_127 &&
( F_76 ( V_7 -> V_128 . V_129 ) &
V_130 ) ) {
T_6 V_131 [ V_132 ] = {
V_7 -> V_133 ,
} ;
V_19 = V_7 -> V_134 ( V_2 , V_7 ,
V_135 ,
V_131 ) ;
if ( V_19 )
goto V_136;
}
V_19 = V_7 -> V_126 ( V_2 , V_29 , V_7 -> V_106 ) ;
V_136:
return V_19 ;
}
static int F_77 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_137 , V_62 , V_19 ;
if ( ! V_7 -> V_126 )
return 0 ;
V_137 = F_78 ( V_7 ) ;
if ( V_137 == V_138 ) {
if ( ! V_7 -> V_133 )
return 0 ;
V_137 = F_79 ( V_7 -> V_133 , 0 ) ;
}
V_7 -> V_106 = F_80 ( sizeof( * V_7 -> V_106 ) ,
V_139 ) ;
if ( ! V_7 -> V_106 )
return - V_140 ;
for ( V_62 = F_81 ( V_137 ) - 1 ; V_62 >= 0 ; V_62 -- ) {
V_19 = F_82 ( V_7 , V_7 -> V_106 ,
V_141 , V_62 ) ;
if ( V_19 )
continue;
V_19 = V_7 -> V_126 ( V_2 ,
V_142 ,
V_7 -> V_106 ) ;
if ( ! V_19 ) {
V_7 -> V_133 = V_62 ;
break;
}
}
return 0 ;
}
static void F_83 ( struct V_6 * V_7 )
{
F_84 ( V_7 -> V_106 ) ;
}
int F_85 ( struct V_6 * V_7 , int V_29 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_19 ;
V_19 = F_71 ( V_7 , V_29 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_143 ( V_2 , V_29 ) ;
V_7 -> V_74 ( V_2 , V_103 , - 1 , - 1 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
V_19 = F_75 ( V_7 , V_29 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_86 ( void * V_36 , int V_18 , int V_144 )
{
const unsigned char * V_145 = V_36 ;
int V_146 = 0 ;
int V_147 ;
for (; V_18 && ( ( V_148 ) V_145 ) % sizeof( long ) ;
V_18 -- , V_145 ++ ) {
V_147 = F_34 ( * V_145 ) ;
V_146 += V_149 - V_147 ;
if ( F_87 ( V_146 > V_144 ) )
return - V_150 ;
}
for (; V_18 >= sizeof( long ) ;
V_18 -= sizeof( long ) , V_145 += sizeof( long ) ) {
unsigned long V_151 = * ( ( unsigned long * ) V_145 ) ;
if ( V_151 == ~ 0UL )
continue;
V_147 = F_88 ( V_151 ) ;
V_146 += V_152 - V_147 ;
if ( F_87 ( V_146 > V_144 ) )
return - V_150 ;
}
for (; V_18 > 0 ; V_18 -- , V_145 ++ ) {
V_147 = F_34 ( * V_145 ) ;
V_146 += V_149 - V_147 ;
if ( F_87 ( V_146 > V_144 ) )
return - V_150 ;
}
return V_146 ;
}
int F_89 ( void * V_153 , int V_154 ,
void * V_9 , int V_155 ,
void * V_156 , int V_157 ,
int V_144 )
{
int V_158 = 0 , V_159 = 0 , V_160 = 0 ;
V_158 = F_86 ( V_153 , V_154 ,
V_144 ) ;
if ( V_158 < 0 )
return V_158 ;
V_144 -= V_158 ;
V_159 = F_86 ( V_9 , V_155 , V_144 ) ;
if ( V_159 < 0 )
return V_159 ;
V_144 -= V_159 ;
V_160 = F_86 ( V_156 , V_157 ,
V_144 ) ;
if ( V_160 < 0 )
return V_160 ;
if ( V_158 )
memset ( V_153 , 0xff , V_154 ) ;
if ( V_159 )
memset ( V_9 , 0xff , V_155 ) ;
if ( V_160 )
memset ( V_156 , 0xff , V_157 ) ;
return V_158 + V_159 + V_160 ;
}
int F_90 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_161 , int V_39 )
{
V_7 -> V_162 ( V_2 , V_36 , V_2 -> V_46 ) ;
if ( V_161 )
V_7 -> V_162 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_36 ,
int V_161 , int V_39 )
{
int V_163 = V_7 -> V_9 . V_164 ;
int V_165 = V_7 -> V_9 . V_166 ;
T_3 * V_167 = V_7 -> V_51 ;
int V_168 , V_164 ;
for ( V_168 = V_7 -> V_9 . V_168 ; V_168 > 0 ; V_168 -- ) {
V_7 -> V_162 ( V_2 , V_36 , V_163 ) ;
V_36 += V_163 ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_162 ( V_2 , V_167 , V_7 -> V_9 . V_169 ) ;
V_167 += V_7 -> V_9 . V_169 ;
}
V_7 -> V_162 ( V_2 , V_167 , V_165 ) ;
V_167 += V_165 ;
if ( V_7 -> V_9 . V_170 ) {
V_7 -> V_162 ( V_2 , V_167 , V_7 -> V_9 . V_170 ) ;
V_167 += V_7 -> V_9 . V_170 ;
}
}
V_164 = V_2 -> V_12 - ( V_167 - V_7 -> V_51 ) ;
if ( V_164 )
V_7 -> V_162 ( V_2 , V_167 , V_164 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_161 , int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 , V_19 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
T_3 * V_38 = V_36 ;
T_3 * V_172 = V_7 -> V_173 -> V_174 ;
T_3 * V_175 = V_7 -> V_173 -> V_176 ;
unsigned int V_177 = 0 ;
V_7 -> V_9 . V_178 ( V_2 , V_7 , V_36 , 1 , V_39 ) ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 )
V_7 -> V_9 . V_179 ( V_2 , V_38 , & V_172 [ V_56 ] ) ;
V_19 = F_93 ( V_2 , V_175 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_14 ) ;
if ( V_19 )
return V_19 ;
V_171 = V_7 -> V_9 . V_168 ;
V_38 = V_36 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
int V_180 ;
V_180 = V_7 -> V_9 . V_181 ( V_2 , V_38 , & V_175 [ V_56 ] , & V_172 [ V_56 ] ) ;
if ( V_180 < 0 ) {
V_2 -> V_71 . V_182 ++ ;
} else {
V_2 -> V_71 . V_183 += V_180 ;
V_177 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_177 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_184 , T_9 V_185 , T_3 * V_186 ,
int V_39 )
{
int V_187 , V_188 , V_189 , V_19 ;
T_3 * V_38 ;
int V_190 , V_56 , V_191 = 0 ;
int V_192 , V_193 , V_194 , V_195 ;
int V_196 = ( V_7 -> V_59 & V_60 ) ? 2 : 1 ;
int V_197 , V_3 = 0 ;
unsigned int V_177 = 0 ;
struct V_4 V_5 = { } ;
V_187 = V_184 / V_7 -> V_9 . V_164 ;
V_188 = ( V_184 + V_185 - 1 ) / V_7 -> V_9 . V_164 ;
V_189 = V_188 - V_187 + 1 ;
V_197 = V_187 * V_7 -> V_9 . V_166 ;
V_192 = V_189 * V_7 -> V_9 . V_164 ;
V_193 = V_189 * V_7 -> V_9 . V_166 ;
V_190 = V_187 * V_7 -> V_9 . V_164 ;
if ( V_190 != 0 )
V_7 -> V_74 ( V_2 , V_114 , V_190 , - 1 ) ;
V_38 = V_186 + V_190 ;
V_7 -> V_162 ( V_2 , V_38 , V_192 ) ;
for ( V_56 = 0 ; V_56 < V_193 ; V_56 += V_7 -> V_9 . V_166 , V_38 += V_7 -> V_9 . V_164 )
V_7 -> V_9 . V_179 ( V_2 , V_38 , & V_7 -> V_173 -> V_174 [ V_56 ] ) ;
V_19 = F_96 ( V_2 , V_197 , & V_3 , & V_5 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 . V_13 < V_193 )
V_191 = 1 ;
if ( V_191 ) {
V_7 -> V_74 ( V_2 , V_114 , V_2 -> V_46 , - 1 ) ;
V_7 -> V_162 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
} else {
V_195 = V_5 . V_11 & ~ ( V_196 - 1 ) ;
V_194 = V_193 ;
if ( V_5 . V_11 & ( V_196 - 1 ) )
V_194 ++ ;
if ( ( V_5 . V_11 + ( V_189 * V_7 -> V_9 . V_166 ) ) &
( V_196 - 1 ) )
V_194 ++ ;
V_7 -> V_74 ( V_2 , V_114 ,
V_2 -> V_46 + V_195 , - 1 ) ;
V_7 -> V_162 ( V_2 , & V_7 -> V_51 [ V_195 ] , V_194 ) ;
}
V_19 = F_93 ( V_2 , V_7 -> V_173 -> V_176 ,
V_7 -> V_51 , V_197 , V_193 ) ;
if ( V_19 )
return V_19 ;
V_38 = V_186 + V_190 ;
for ( V_56 = 0 ; V_56 < V_193 ; V_56 += V_7 -> V_9 . V_166 , V_38 += V_7 -> V_9 . V_164 ) {
int V_180 ;
V_180 = V_7 -> V_9 . V_181 ( V_2 , V_38 ,
& V_7 -> V_173 -> V_176 [ V_56 ] , & V_7 -> V_173 -> V_174 [ V_56 ] ) ;
if ( V_180 == - V_150 &&
( V_7 -> V_9 . V_59 & V_198 ) ) {
V_180 = F_89 ( V_38 , V_7 -> V_9 . V_164 ,
& V_7 -> V_173 -> V_176 [ V_56 ] ,
V_7 -> V_9 . V_166 ,
NULL , 0 ,
V_7 -> V_9 . V_199 ) ;
}
if ( V_180 < 0 ) {
V_2 -> V_71 . V_182 ++ ;
} else {
V_2 -> V_71 . V_183 += V_180 ;
V_177 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_177 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_161 , int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 , V_19 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
T_3 * V_38 = V_36 ;
T_3 * V_172 = V_7 -> V_173 -> V_174 ;
T_3 * V_175 = V_7 -> V_173 -> V_176 ;
unsigned int V_177 = 0 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
V_7 -> V_9 . V_200 ( V_2 , V_201 ) ;
V_7 -> V_162 ( V_2 , V_38 , V_163 ) ;
V_7 -> V_9 . V_179 ( V_2 , V_38 , & V_172 [ V_56 ] ) ;
}
V_7 -> V_162 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
V_19 = F_93 ( V_2 , V_175 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_14 ) ;
if ( V_19 )
return V_19 ;
V_171 = V_7 -> V_9 . V_168 ;
V_38 = V_36 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
int V_180 ;
V_180 = V_7 -> V_9 . V_181 ( V_2 , V_38 , & V_175 [ V_56 ] , & V_172 [ V_56 ] ) ;
if ( V_180 == - V_150 &&
( V_7 -> V_9 . V_59 & V_198 ) ) {
V_180 = F_89 ( V_38 , V_163 ,
& V_175 [ V_56 ] , V_165 ,
NULL , 0 ,
V_7 -> V_9 . V_199 ) ;
}
if ( V_180 < 0 ) {
V_2 -> V_71 . V_182 ++ ;
} else {
V_2 -> V_71 . V_183 += V_180 ;
V_177 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_177 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_3 * V_36 , int V_161 , int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 , V_19 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
T_3 * V_38 = V_36 ;
T_3 * V_175 = V_7 -> V_173 -> V_176 ;
T_3 * V_172 = V_7 -> V_173 -> V_174 ;
unsigned int V_177 = 0 ;
V_7 -> V_74 ( V_2 , V_92 , 0 , V_39 ) ;
V_7 -> V_162 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
V_7 -> V_74 ( V_2 , V_93 , 0 , V_39 ) ;
V_19 = F_93 ( V_2 , V_175 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_14 ) ;
if ( V_19 )
return V_19 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
int V_180 ;
V_7 -> V_9 . V_200 ( V_2 , V_201 ) ;
V_7 -> V_162 ( V_2 , V_38 , V_163 ) ;
V_7 -> V_9 . V_179 ( V_2 , V_38 , & V_172 [ V_56 ] ) ;
V_180 = V_7 -> V_9 . V_181 ( V_2 , V_38 , & V_175 [ V_56 ] , NULL ) ;
if ( V_180 == - V_150 &&
( V_7 -> V_9 . V_59 & V_198 ) ) {
V_180 = F_89 ( V_38 , V_163 ,
& V_175 [ V_56 ] , V_165 ,
NULL , 0 ,
V_7 -> V_9 . V_199 ) ;
}
if ( V_180 < 0 ) {
V_2 -> V_71 . V_182 ++ ;
} else {
V_2 -> V_71 . V_183 += V_180 ;
V_177 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
return V_177 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_36 , int V_161 , int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
int V_202 = V_165 + V_7 -> V_9 . V_169 + V_7 -> V_9 . V_170 ;
T_3 * V_38 = V_36 ;
T_3 * V_167 = V_7 -> V_51 ;
unsigned int V_177 = 0 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
int V_180 ;
V_7 -> V_9 . V_200 ( V_2 , V_201 ) ;
V_7 -> V_162 ( V_2 , V_38 , V_163 ) ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_162 ( V_2 , V_167 , V_7 -> V_9 . V_169 ) ;
V_167 += V_7 -> V_9 . V_169 ;
}
V_7 -> V_9 . V_200 ( V_2 , V_203 ) ;
V_7 -> V_162 ( V_2 , V_167 , V_165 ) ;
V_180 = V_7 -> V_9 . V_181 ( V_2 , V_38 , V_167 , NULL ) ;
V_167 += V_165 ;
if ( V_7 -> V_9 . V_170 ) {
V_7 -> V_162 ( V_2 , V_167 , V_7 -> V_9 . V_170 ) ;
V_167 += V_7 -> V_9 . V_170 ;
}
if ( V_180 == - V_150 &&
( V_7 -> V_9 . V_59 & V_198 ) ) {
V_180 = F_89 ( V_38 , V_7 -> V_9 . V_164 ,
V_167 - V_202 ,
V_202 ,
NULL , 0 ,
V_7 -> V_9 . V_199 ) ;
}
if ( V_180 < 0 ) {
V_2 -> V_71 . V_182 ++ ;
} else {
V_2 -> V_71 . V_183 += V_180 ;
V_177 = F_94 (unsigned int, max_bitflips, stat) ;
}
}
V_56 = V_2 -> V_12 - ( V_167 - V_7 -> V_51 ) ;
if ( V_56 )
V_7 -> V_162 ( V_2 , V_167 , V_56 ) ;
return V_177 ;
}
static T_3 * F_100 ( struct V_1 * V_2 , T_3 * V_167 ,
struct V_54 * V_55 , T_10 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 ;
switch ( V_55 -> V_62 ) {
case V_63 :
case V_204 :
memcpy ( V_167 , V_7 -> V_51 + V_55 -> V_58 , V_18 ) ;
return V_167 + V_18 ;
case V_205 :
V_19 = F_101 ( V_2 , V_167 , V_7 -> V_51 ,
V_55 -> V_58 , V_18 ) ;
F_102 ( V_19 ) ;
return V_167 + V_18 ;
default:
F_21 () ;
}
return NULL ;
}
static int F_103 ( struct V_1 * V_2 , int V_206 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( L_5 , V_206 ) ;
if ( V_206 >= V_7 -> V_207 )
return - V_15 ;
if ( ! V_7 -> V_208 )
return - V_209 ;
return V_7 -> V_208 ( V_2 , V_206 ) ;
}
static int F_104 ( struct V_1 * V_2 , T_1 V_210 ,
struct V_54 * V_55 )
{
int V_29 , V_39 , V_211 , V_212 , V_166 , V_213 , V_161 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 = 0 ;
T_9 V_185 = V_55 -> V_18 ;
T_9 V_214 = V_55 -> V_61 ;
T_9 V_215 = F_105 ( V_2 , V_55 ) ;
T_3 * V_186 , * V_167 , * V_36 ;
int V_216 ;
unsigned int V_177 = 0 ;
int V_206 = 0 ;
bool V_217 = false ;
V_29 = ( int ) ( V_210 >> V_7 -> V_218 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
V_211 = ( int ) ( V_210 >> V_7 -> V_47 ) ;
V_39 = V_211 & V_7 -> V_48 ;
V_212 = ( int ) ( V_210 & ( V_2 -> V_46 - 1 ) ) ;
V_36 = V_55 -> V_219 ;
V_167 = V_55 -> V_57 ;
V_161 = V_167 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_220 = V_2 -> V_71 . V_182 ;
V_166 = F_106 ( V_2 -> V_46 - V_212 , V_185 ) ;
V_213 = ( V_166 == V_2 -> V_46 ) ;
if ( ! V_213 )
V_216 = 1 ;
else if ( V_7 -> V_59 & V_221 )
V_216 = ! F_107 ( V_36 ) ||
! F_108 ( ( unsigned long ) V_36 ,
V_7 -> V_222 ) ;
else
V_216 = 0 ;
if ( V_211 != V_7 -> V_223 || V_167 ) {
V_186 = V_216 ? V_7 -> V_173 -> V_224 : V_36 ;
if ( V_216 && V_213 )
F_9 ( L_6 ,
V_21 , V_36 ) ;
V_225:
if ( F_109 ( & V_7 -> V_9 ) )
V_7 -> V_74 ( V_2 , V_93 , 0x00 , V_39 ) ;
if ( F_87 ( V_55 -> V_62 == V_204 ) )
V_19 = V_7 -> V_9 . V_178 ( V_2 , V_7 , V_186 ,
V_161 ,
V_39 ) ;
else if ( ! V_213 && F_110 ( V_7 ) &&
! V_167 )
V_19 = V_7 -> V_9 . V_226 ( V_2 , V_7 ,
V_212 , V_166 , V_186 ,
V_39 ) ;
else
V_19 = V_7 -> V_9 . V_227 ( V_2 , V_7 , V_186 ,
V_161 , V_39 ) ;
if ( V_19 < 0 ) {
if ( V_216 )
V_7 -> V_223 = - 1 ;
break;
}
if ( V_216 ) {
if ( ! F_110 ( V_7 ) && ! V_167 &&
! ( V_2 -> V_71 . V_182 - V_220 ) &&
( V_55 -> V_62 != V_204 ) ) {
V_7 -> V_223 = V_211 ;
V_7 -> V_228 = V_19 ;
} else {
V_7 -> V_223 = - 1 ;
}
memcpy ( V_36 , V_7 -> V_173 -> V_224 + V_212 , V_166 ) ;
}
if ( F_87 ( V_167 ) ) {
int V_229 = F_106 ( V_214 , V_215 ) ;
if ( V_229 ) {
V_167 = F_100 ( V_2 ,
V_167 , V_55 , V_229 ) ;
V_214 -= V_229 ;
}
}
if ( V_7 -> V_59 & V_230 ) {
if ( ! V_7 -> V_81 )
F_58 ( V_7 -> V_104 ) ;
else
F_49 ( V_2 ) ;
}
if ( V_2 -> V_71 . V_182 - V_220 ) {
if ( V_206 + 1 < V_7 -> V_207 ) {
V_206 ++ ;
V_19 = F_103 ( V_2 ,
V_206 ) ;
if ( V_19 < 0 )
break;
V_2 -> V_71 . V_182 = V_220 ;
goto V_225;
} else {
V_217 = true ;
}
}
V_36 += V_166 ;
V_177 = F_94 (unsigned int, max_bitflips, ret) ;
} else {
memcpy ( V_36 , V_7 -> V_173 -> V_224 + V_212 , V_166 ) ;
V_36 += V_166 ;
V_177 = F_94 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_185 -= V_166 ;
if ( V_206 ) {
V_19 = F_103 ( V_2 , 0 ) ;
if ( V_19 < 0 )
break;
V_206 = 0 ;
}
if ( ! V_185 )
break;
V_212 = 0 ;
V_211 ++ ;
V_39 = V_211 & V_7 -> V_48 ;
if ( ! V_39 ) {
V_29 ++ ;
V_7 -> V_143 ( V_2 , - 1 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
}
}
V_7 -> V_143 ( V_2 , - 1 ) ;
V_55 -> V_231 = V_55 -> V_18 - ( T_10 ) V_185 ;
if ( V_167 )
V_55 -> V_232 = V_55 -> V_61 - V_214 ;
if ( V_19 < 0 )
return V_19 ;
if ( V_217 )
return - V_150 ;
return V_177 ;
}
static int F_111 ( struct V_1 * V_2 , T_1 V_210 , T_10 V_18 ,
T_10 * V_231 , T_3 * V_36 )
{
struct V_54 V_55 ;
int V_19 ;
F_39 ( V_2 , V_233 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_18 = V_18 ;
V_55 . V_219 = V_36 ;
V_55 . V_62 = V_63 ;
V_19 = F_104 ( V_2 , V_210 , & V_55 ) ;
* V_231 = V_55 . V_231 ;
F_10 ( V_2 ) ;
return V_19 ;
}
int F_112 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_39 )
{
V_7 -> V_74 ( V_2 , V_92 , 0 , V_39 ) ;
V_7 -> V_162 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
return 0 ;
}
int F_113 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_39 )
{
int V_13 = V_2 -> V_12 ;
int V_234 = V_7 -> V_9 . V_166 + V_7 -> V_9 . V_169 + V_7 -> V_9 . V_170 ;
int V_163 = V_7 -> V_9 . V_164 ;
T_3 * V_186 = V_7 -> V_51 ;
int V_56 , V_229 , V_235 = 0 , V_236 ;
V_7 -> V_74 ( V_2 , V_93 , V_7 -> V_9 . V_164 , V_39 ) ;
for ( V_56 = 0 ; V_56 < V_7 -> V_9 . V_168 ; V_56 ++ ) {
if ( V_235 ) {
V_236 = V_163 + V_56 * ( V_163 + V_234 ) ;
if ( V_2 -> V_46 > 512 )
V_7 -> V_74 ( V_2 , V_114 , V_236 , - 1 ) ;
else
V_7 -> V_74 ( V_2 , V_93 , V_236 , V_39 ) ;
} else
V_235 = 1 ;
V_229 = F_114 ( int , V_13 , V_234 ) ;
V_7 -> V_162 ( V_2 , V_186 , V_229 ) ;
V_186 += V_229 ;
V_13 -= V_229 ;
}
if ( V_13 > 0 )
V_7 -> V_162 ( V_2 , V_186 , V_13 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_39 )
{
int V_123 = 0 ;
const T_3 * V_36 = V_7 -> V_51 ;
int V_13 = V_2 -> V_12 ;
V_7 -> V_74 ( V_2 , V_90 , V_2 -> V_46 , V_39 ) ;
V_7 -> V_34 ( V_2 , V_36 , V_13 ) ;
V_7 -> V_74 ( V_2 , V_98 , - 1 , - 1 ) ;
V_123 = V_7 -> V_237 ( V_2 , V_7 ) ;
return V_123 & V_238 ? - V_239 : 0 ;
}
int F_116 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_39 )
{
int V_234 = V_7 -> V_9 . V_166 + V_7 -> V_9 . V_169 + V_7 -> V_9 . V_170 ;
int V_163 = V_7 -> V_9 . V_164 , V_13 = V_2 -> V_12 ;
int V_56 , V_18 , V_236 , V_123 = 0 , V_240 = 0 , V_168 = V_7 -> V_9 . V_168 ;
const T_3 * V_186 = V_7 -> V_51 ;
if ( ! V_7 -> V_9 . V_169 && ! V_7 -> V_9 . V_170 ) {
V_236 = V_168 * ( V_163 + V_234 ) ;
V_168 = 0 ;
} else
V_236 = V_163 ;
V_7 -> V_74 ( V_2 , V_90 , V_236 , V_39 ) ;
for ( V_56 = 0 ; V_56 < V_168 ; V_56 ++ ) {
if ( V_240 ) {
if ( V_2 -> V_46 <= 512 ) {
T_9 V_241 = 0xFFFFFFFF ;
V_18 = V_163 ;
while ( V_18 > 0 ) {
int V_242 = F_114 ( int , V_18 , 4 ) ;
V_7 -> V_34 ( V_2 , ( T_3 * ) & V_241 ,
V_242 ) ;
V_18 -= V_242 ;
}
} else {
V_236 = V_163 + V_56 * ( V_163 + V_234 ) ;
V_7 -> V_74 ( V_2 , V_113 , V_236 , - 1 ) ;
}
} else
V_240 = 1 ;
V_18 = F_114 ( int , V_13 , V_234 ) ;
V_7 -> V_34 ( V_2 , V_186 , V_18 ) ;
V_186 += V_18 ;
V_13 -= V_18 ;
}
if ( V_13 > 0 )
V_7 -> V_34 ( V_2 , V_186 , V_13 ) ;
V_7 -> V_74 ( V_2 , V_98 , - 1 , - 1 ) ;
V_123 = V_7 -> V_237 ( V_2 , V_7 ) ;
return V_123 & V_238 ? - V_239 : 0 ;
}
static int F_117 ( struct V_1 * V_2 , T_1 V_210 ,
struct V_54 * V_55 )
{
int V_39 , V_211 , V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_243 V_244 ;
int V_185 = V_55 -> V_61 ;
int V_18 ;
T_3 * V_36 = V_55 -> V_57 ;
int V_19 = 0 ;
F_9 ( L_7 ,
V_21 , ( unsigned long long ) V_210 , V_185 ) ;
V_244 = V_2 -> V_71 ;
V_18 = F_105 ( V_2 , V_55 ) ;
if ( F_87 ( V_55 -> V_58 >= V_18 ) ) {
F_9 ( L_8 ,
V_21 ) ;
return - V_15 ;
}
if ( F_87 ( V_210 >= V_2 -> V_164 ||
V_55 -> V_58 + V_185 > ( ( V_2 -> V_164 >> V_7 -> V_47 ) -
( V_210 >> V_7 -> V_47 ) ) * V_18 ) ) {
F_9 ( L_9 ,
V_21 ) ;
return - V_15 ;
}
V_29 = ( int ) ( V_210 >> V_7 -> V_218 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
V_211 = ( int ) ( V_210 >> V_7 -> V_47 ) ;
V_39 = V_211 & V_7 -> V_48 ;
while ( 1 ) {
if ( V_55 -> V_62 == V_204 )
V_19 = V_7 -> V_9 . V_245 ( V_2 , V_7 , V_39 ) ;
else
V_19 = V_7 -> V_9 . V_50 ( V_2 , V_7 , V_39 ) ;
if ( V_19 < 0 )
break;
V_18 = F_106 ( V_18 , V_185 ) ;
V_36 = F_100 ( V_2 , V_36 , V_55 , V_18 ) ;
if ( V_7 -> V_59 & V_230 ) {
if ( ! V_7 -> V_81 )
F_58 ( V_7 -> V_104 ) ;
else
F_49 ( V_2 ) ;
}
V_185 -= V_18 ;
if ( ! V_185 )
break;
V_211 ++ ;
V_39 = V_211 & V_7 -> V_48 ;
if ( ! V_39 ) {
V_29 ++ ;
V_7 -> V_143 ( V_2 , - 1 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
}
}
V_7 -> V_143 ( V_2 , - 1 ) ;
V_55 -> V_232 = V_55 -> V_61 - V_185 ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_71 . V_182 - V_244 . V_182 )
return - V_150 ;
return V_2 -> V_71 . V_183 - V_244 . V_183 ? - V_246 : 0 ;
}
static int F_118 ( struct V_1 * V_2 , T_1 V_210 ,
struct V_54 * V_55 )
{
int V_19 ;
V_55 -> V_231 = 0 ;
if ( V_55 -> V_219 && ( V_210 + V_55 -> V_18 ) > V_2 -> V_164 ) {
F_9 ( L_9 ,
V_21 ) ;
return - V_15 ;
}
if ( V_55 -> V_62 != V_63 &&
V_55 -> V_62 != V_205 &&
V_55 -> V_62 != V_204 )
return - V_247 ;
F_39 ( V_2 , V_233 ) ;
if ( ! V_55 -> V_219 )
V_19 = F_117 ( V_2 , V_210 , V_55 ) ;
else
V_19 = F_104 ( V_2 , V_210 , V_55 ) ;
F_10 ( V_2 ) ;
return V_19 ;
}
int F_119 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_36 , int V_161 , int V_39 )
{
V_7 -> V_34 ( V_2 , V_36 , V_2 -> V_46 ) ;
if ( V_161 )
V_7 -> V_34 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_36 , int V_161 ,
int V_39 )
{
int V_163 = V_7 -> V_9 . V_164 ;
int V_165 = V_7 -> V_9 . V_166 ;
T_3 * V_167 = V_7 -> V_51 ;
int V_168 , V_164 ;
for ( V_168 = V_7 -> V_9 . V_168 ; V_168 > 0 ; V_168 -- ) {
V_7 -> V_34 ( V_2 , V_36 , V_163 ) ;
V_36 += V_163 ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_34 ( V_2 , V_167 , V_7 -> V_9 . V_169 ) ;
V_167 += V_7 -> V_9 . V_169 ;
}
V_7 -> V_34 ( V_2 , V_167 , V_165 ) ;
V_167 += V_165 ;
if ( V_7 -> V_9 . V_170 ) {
V_7 -> V_34 ( V_2 , V_167 , V_7 -> V_9 . V_170 ) ;
V_167 += V_7 -> V_9 . V_170 ;
}
}
V_164 = V_2 -> V_12 - ( V_167 - V_7 -> V_51 ) ;
if ( V_164 )
V_7 -> V_34 ( V_2 , V_167 , V_164 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_36 , int V_161 ,
int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 , V_19 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
T_3 * V_172 = V_7 -> V_173 -> V_174 ;
const T_3 * V_38 = V_36 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 )
V_7 -> V_9 . V_179 ( V_2 , V_38 , & V_172 [ V_56 ] ) ;
V_19 = F_122 ( V_2 , V_172 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_14 ) ;
if ( V_19 )
return V_19 ;
return V_7 -> V_9 . V_248 ( V_2 , V_7 , V_36 , 1 , V_39 ) ;
}
static int F_123 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_3 * V_36 , int V_161 ,
int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 , V_19 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
T_3 * V_172 = V_7 -> V_173 -> V_174 ;
const T_3 * V_38 = V_36 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
V_7 -> V_9 . V_200 ( V_2 , V_249 ) ;
V_7 -> V_34 ( V_2 , V_38 , V_163 ) ;
V_7 -> V_9 . V_179 ( V_2 , V_38 , & V_172 [ V_56 ] ) ;
}
V_19 = F_122 ( V_2 , V_172 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_14 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_34 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_9 V_11 ,
T_9 V_250 , const T_3 * V_36 ,
int V_161 , int V_39 )
{
T_3 * V_251 = V_7 -> V_51 ;
T_3 * V_172 = V_7 -> V_173 -> V_174 ;
int V_252 = V_7 -> V_9 . V_164 ;
int V_253 = V_7 -> V_9 . V_166 ;
int V_254 = V_7 -> V_9 . V_168 ;
T_9 V_187 = V_11 / V_252 ;
T_9 V_188 = ( V_11 + V_250 - 1 ) / V_252 ;
int V_255 = V_2 -> V_12 / V_254 ;
int V_256 , V_19 ;
for ( V_256 = 0 ; V_256 < V_254 ; V_256 ++ ) {
V_7 -> V_9 . V_200 ( V_2 , V_249 ) ;
V_7 -> V_34 ( V_2 , V_36 , V_252 ) ;
if ( ( V_256 < V_187 ) || ( V_256 > V_188 ) )
memset ( V_172 , 0xff , V_253 ) ;
else
V_7 -> V_9 . V_179 ( V_2 , V_36 , V_172 ) ;
if ( ! V_161 || ( V_256 < V_187 ) || ( V_256 > V_188 ) )
memset ( V_251 , 0xff , V_255 ) ;
V_36 += V_252 ;
V_172 += V_253 ;
V_251 += V_255 ;
}
V_172 = V_7 -> V_173 -> V_174 ;
V_19 = F_122 ( V_2 , V_172 , V_7 -> V_51 , 0 ,
V_7 -> V_9 . V_14 ) ;
if ( V_19 )
return V_19 ;
V_7 -> V_34 ( V_2 , V_7 -> V_51 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_3 * V_36 , int V_161 ,
int V_39 )
{
int V_56 , V_163 = V_7 -> V_9 . V_164 ;
int V_165 = V_7 -> V_9 . V_166 ;
int V_171 = V_7 -> V_9 . V_168 ;
const T_3 * V_38 = V_36 ;
T_3 * V_167 = V_7 -> V_51 ;
for ( V_56 = 0 ; V_171 ; V_171 -- , V_56 += V_165 , V_38 += V_163 ) {
V_7 -> V_9 . V_200 ( V_2 , V_249 ) ;
V_7 -> V_34 ( V_2 , V_38 , V_163 ) ;
if ( V_7 -> V_9 . V_169 ) {
V_7 -> V_34 ( V_2 , V_167 , V_7 -> V_9 . V_169 ) ;
V_167 += V_7 -> V_9 . V_169 ;
}
V_7 -> V_9 . V_179 ( V_2 , V_38 , V_167 ) ;
V_7 -> V_34 ( V_2 , V_167 , V_165 ) ;
V_167 += V_165 ;
if ( V_7 -> V_9 . V_170 ) {
V_7 -> V_34 ( V_2 , V_167 , V_7 -> V_9 . V_170 ) ;
V_167 += V_7 -> V_9 . V_170 ;
}
}
V_56 = V_2 -> V_12 - ( V_167 - V_7 -> V_51 ) ;
if ( V_56 )
V_7 -> V_34 ( V_2 , V_167 , V_56 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_9 V_11 , int V_250 , const T_3 * V_36 ,
int V_161 , int V_39 , int V_257 )
{
int V_123 , V_258 ;
if ( ! ( V_7 -> V_59 & V_259 ) &&
V_7 -> V_9 . V_260 )
V_258 = V_11 || ( V_250 < V_2 -> V_46 ) ;
else
V_258 = 0 ;
if ( F_109 ( & V_7 -> V_9 ) )
V_7 -> V_74 ( V_2 , V_90 , 0x00 , V_39 ) ;
if ( F_87 ( V_257 ) )
V_123 = V_7 -> V_9 . V_248 ( V_2 , V_7 , V_36 ,
V_161 , V_39 ) ;
else if ( V_258 )
V_123 = V_7 -> V_9 . V_260 ( V_2 , V_7 , V_11 , V_250 ,
V_36 , V_161 , V_39 ) ;
else
V_123 = V_7 -> V_9 . V_261 ( V_2 , V_7 , V_36 , V_161 ,
V_39 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( F_109 ( & V_7 -> V_9 ) ) {
V_7 -> V_74 ( V_2 , V_98 , - 1 , - 1 ) ;
V_123 = V_7 -> V_237 ( V_2 , V_7 ) ;
if ( V_123 & V_238 )
return - V_239 ;
}
return 0 ;
}
static T_3 * F_127 ( struct V_1 * V_2 , T_3 * V_167 , T_10 V_18 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 ;
memset ( V_7 -> V_51 , 0xff , V_2 -> V_12 ) ;
switch ( V_55 -> V_62 ) {
case V_63 :
case V_204 :
memcpy ( V_7 -> V_51 + V_55 -> V_58 , V_167 , V_18 ) ;
return V_167 + V_18 ;
case V_205 :
V_19 = F_128 ( V_2 , V_167 , V_7 -> V_51 ,
V_55 -> V_58 , V_18 ) ;
F_102 ( V_19 ) ;
return V_167 + V_18 ;
default:
F_21 () ;
}
return NULL ;
}
static int F_129 ( struct V_1 * V_2 , T_1 V_262 ,
struct V_54 * V_55 )
{
int V_29 , V_211 , V_39 , V_86 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_9 V_263 = V_55 -> V_18 ;
T_9 V_264 = V_55 -> V_61 ;
T_9 V_265 = F_105 ( V_2 , V_55 ) ;
T_3 * V_167 = V_55 -> V_57 ;
T_3 * V_36 = V_55 -> V_219 ;
int V_19 ;
int V_161 = V_167 ? 1 : 0 ;
V_55 -> V_231 = 0 ;
if ( ! V_263 )
return 0 ;
if ( F_130 ( V_262 ) || F_130 ( V_55 -> V_18 ) ) {
F_131 ( L_10 ,
V_21 ) ;
return - V_15 ;
}
V_86 = V_262 & ( V_2 -> V_46 - 1 ) ;
V_29 = ( int ) ( V_262 >> V_7 -> V_218 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
if ( F_41 ( V_2 ) ) {
V_19 = - V_239 ;
goto V_266;
}
V_211 = ( int ) ( V_262 >> V_7 -> V_47 ) ;
V_39 = V_211 & V_7 -> V_48 ;
if ( V_262 <= ( ( T_1 ) V_7 -> V_223 << V_7 -> V_47 ) &&
( ( T_1 ) V_7 -> V_223 << V_7 -> V_47 ) < ( V_262 + V_55 -> V_18 ) )
V_7 -> V_223 = - 1 ;
if ( V_167 && V_55 -> V_58 && ( V_55 -> V_58 + V_55 -> V_61 > V_265 ) ) {
V_19 = - V_15 ;
goto V_266;
}
while ( 1 ) {
int V_166 = V_2 -> V_46 ;
T_3 * V_267 = V_36 ;
int V_216 ;
int V_268 = ( V_86 || V_263 < V_2 -> V_46 ) ;
if ( V_268 )
V_216 = 1 ;
else if ( V_7 -> V_59 & V_221 )
V_216 = ! F_107 ( V_36 ) ||
! F_108 ( ( unsigned long ) V_36 ,
V_7 -> V_222 ) ;
else
V_216 = 0 ;
if ( V_216 ) {
F_9 ( L_11 ,
V_21 , V_36 ) ;
if ( V_268 )
V_166 = F_114 ( int , V_166 - V_86 , V_263 ) ;
V_7 -> V_223 = - 1 ;
memset ( V_7 -> V_173 -> V_224 , 0xff , V_2 -> V_46 ) ;
memcpy ( & V_7 -> V_173 -> V_224 [ V_86 ] , V_36 , V_166 ) ;
V_267 = V_7 -> V_173 -> V_224 ;
}
if ( F_87 ( V_167 ) ) {
T_10 V_18 = F_106 ( V_264 , V_265 ) ;
V_167 = F_127 ( V_2 , V_167 , V_18 , V_55 ) ;
V_264 -= V_18 ;
} else {
memset ( V_7 -> V_51 , 0xff , V_2 -> V_12 ) ;
}
V_19 = F_126 ( V_2 , V_7 , V_86 , V_166 , V_267 ,
V_161 , V_39 ,
( V_55 -> V_62 == V_204 ) ) ;
if ( V_19 )
break;
V_263 -= V_166 ;
if ( ! V_263 )
break;
V_86 = 0 ;
V_36 += V_166 ;
V_211 ++ ;
V_39 = V_211 & V_7 -> V_48 ;
if ( ! V_39 ) {
V_29 ++ ;
V_7 -> V_143 ( V_2 , - 1 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
}
}
V_55 -> V_231 = V_55 -> V_18 - V_263 ;
if ( F_87 ( V_167 ) )
V_55 -> V_232 = V_55 -> V_61 ;
V_266:
V_7 -> V_143 ( V_2 , - 1 ) ;
return V_19 ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_262 , T_10 V_18 ,
T_10 * V_231 , const T_3 * V_36 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_54 V_55 ;
int V_19 ;
F_68 ( V_2 , V_7 , 400 ) ;
F_62 ( V_7 , V_2 , V_68 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_18 = V_18 ;
V_55 . V_219 = ( T_3 * ) V_36 ;
V_55 . V_62 = V_63 ;
V_19 = F_129 ( V_2 , V_262 , & V_55 ) ;
* V_231 = V_55 . V_231 ;
return V_19 ;
}
static int F_133 ( struct V_1 * V_2 , T_1 V_262 , T_10 V_18 ,
T_10 * V_231 , const T_3 * V_36 )
{
struct V_54 V_55 ;
int V_19 ;
F_39 ( V_2 , V_68 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_18 = V_18 ;
V_55 . V_219 = ( T_3 * ) V_36 ;
V_55 . V_62 = V_63 ;
V_19 = F_129 ( V_2 , V_262 , & V_55 ) ;
* V_231 = V_55 . V_231 ;
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_262 ,
struct V_54 * V_55 )
{
int V_29 , V_39 , V_123 , V_18 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( L_12 ,
V_21 , ( unsigned int ) V_262 , ( int ) V_55 -> V_61 ) ;
V_18 = F_105 ( V_2 , V_55 ) ;
if ( ( V_55 -> V_58 + V_55 -> V_61 ) > V_18 ) {
F_9 ( L_13 ,
V_21 ) ;
return - V_15 ;
}
if ( F_87 ( V_55 -> V_58 >= V_18 ) ) {
F_9 ( L_14 ,
V_21 ) ;
return - V_15 ;
}
if ( F_87 ( V_262 >= V_2 -> V_164 ||
V_55 -> V_58 + V_55 -> V_61 >
( ( V_2 -> V_164 >> V_7 -> V_47 ) -
( V_262 >> V_7 -> V_47 ) ) * V_18 ) ) {
F_9 ( L_15 ,
V_21 ) ;
return - V_15 ;
}
V_29 = ( int ) ( V_262 >> V_7 -> V_218 ) ;
F_85 ( V_7 , V_29 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
V_39 = ( int ) ( V_262 >> V_7 -> V_47 ) ;
if ( F_41 ( V_2 ) ) {
V_7 -> V_143 ( V_2 , - 1 ) ;
return - V_269 ;
}
if ( V_39 == V_7 -> V_223 )
V_7 -> V_223 = - 1 ;
F_127 ( V_2 , V_55 -> V_57 , V_55 -> V_61 , V_55 ) ;
if ( V_55 -> V_62 == V_204 )
V_123 = V_7 -> V_9 . V_270 ( V_2 , V_7 , V_39 & V_7 -> V_48 ) ;
else
V_123 = V_7 -> V_9 . V_271 ( V_2 , V_7 , V_39 & V_7 -> V_48 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
if ( V_123 )
return V_123 ;
V_55 -> V_232 = V_55 -> V_61 ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , T_1 V_262 ,
struct V_54 * V_55 )
{
int V_19 = - V_247 ;
V_55 -> V_231 = 0 ;
if ( V_55 -> V_219 && ( V_262 + V_55 -> V_18 ) > V_2 -> V_164 ) {
F_9 ( L_15 ,
V_21 ) ;
return - V_15 ;
}
F_39 ( V_2 , V_68 ) ;
switch ( V_55 -> V_62 ) {
case V_63 :
case V_205 :
case V_204 :
break;
default:
goto V_272;
}
if ( ! V_55 -> V_219 )
V_19 = F_36 ( V_2 , V_262 , V_55 ) ;
else
V_19 = F_129 ( V_2 , V_262 , V_55 ) ;
V_272:
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_135 ( struct V_1 * V_2 , int V_39 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_74 ( V_2 , V_99 , - 1 , V_39 ) ;
V_7 -> V_74 ( V_2 , V_100 , - 1 , - 1 ) ;
return V_7 -> V_237 ( V_2 , V_7 ) ;
}
static int F_136 ( struct V_1 * V_2 , struct V_65 * V_273 )
{
return F_38 ( V_2 , V_273 , 0 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_65 * V_273 ,
int V_78 )
{
int V_39 , V_123 , V_274 , V_19 , V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_18 ;
F_9 ( L_16 ,
V_21 , ( unsigned long long ) V_273 -> V_67 ,
( unsigned long long ) V_273 -> V_18 ) ;
if ( F_8 ( V_2 , V_273 -> V_67 , V_273 -> V_18 ) )
return - V_15 ;
F_39 ( V_2 , V_275 ) ;
V_39 = ( int ) ( V_273 -> V_67 >> V_7 -> V_47 ) ;
V_29 = ( int ) ( V_273 -> V_67 >> V_7 -> V_218 ) ;
V_274 = 1 << ( V_7 -> V_20 - V_7 -> V_47 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
if ( F_41 ( V_2 ) ) {
F_9 ( L_17 ,
V_21 ) ;
V_273 -> V_25 = V_276 ;
goto V_277;
}
V_18 = V_273 -> V_18 ;
V_273 -> V_25 = V_278 ;
while ( V_18 ) {
if ( F_44 ( V_2 , ( ( T_1 ) V_39 ) <<
V_7 -> V_47 , V_78 ) ) {
F_137 ( L_18 ,
V_21 , V_39 ) ;
V_273 -> V_25 = V_276 ;
goto V_277;
}
if ( V_39 <= V_7 -> V_223 && V_7 -> V_223 <
( V_39 + V_274 ) )
V_7 -> V_223 = - 1 ;
V_123 = V_7 -> V_279 ( V_2 , V_39 & V_7 -> V_48 ) ;
if ( V_123 & V_238 ) {
F_9 ( L_19 ,
V_21 , V_39 ) ;
V_273 -> V_25 = V_276 ;
V_273 -> V_280 =
( ( T_1 ) V_39 << V_7 -> V_47 ) ;
goto V_277;
}
V_18 -= ( 1ULL << V_7 -> V_20 ) ;
V_39 += V_274 ;
if ( V_18 && ! ( V_39 & V_7 -> V_48 ) ) {
V_29 ++ ;
V_7 -> V_143 ( V_2 , - 1 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
}
}
V_273 -> V_25 = V_281 ;
V_277:
V_19 = V_273 -> V_25 == V_281 ? 0 : - V_239 ;
V_7 -> V_143 ( V_2 , - 1 ) ;
F_10 ( V_2 ) ;
if ( ! V_19 )
F_138 ( V_273 ) ;
return V_19 ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_9 ( L_20 , V_21 ) ;
F_39 ( V_2 , V_282 ) ;
F_10 ( V_2 ) ;
}
static int F_140 ( struct V_1 * V_2 , T_1 V_283 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_29 = ( int ) ( V_283 >> V_7 -> V_218 ) ;
int V_19 ;
F_39 ( V_2 , V_233 ) ;
V_7 -> V_143 ( V_2 , V_29 ) ;
V_19 = F_44 ( V_2 , V_283 , 0 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
F_10 ( V_2 ) ;
return V_19 ;
}
static int F_141 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_19 ;
V_19 = F_140 ( V_2 , V_17 ) ;
if ( V_19 ) {
if ( V_19 > 0 )
return 0 ;
return V_19 ;
}
return F_37 ( V_2 , V_17 ) ;
}
static int F_142 ( struct V_1 * V_2 , T_1 V_17 , T_10 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_11 V_284 ;
T_11 V_285 ;
T_11 V_286 ;
T_11 V_287 ;
if ( ! V_7 -> V_288 || ! V_7 -> V_289 )
return - V_247 ;
V_284 = F_143 ( V_17 , V_2 ) ;
V_285 = F_143 ( V_18 , V_2 ) + V_284 - 1 ;
V_286 = V_284 / V_7 -> V_289 ;
V_287 = V_285 / V_7 -> V_289 ;
return V_7 -> V_288 * ( V_287 - V_286 + 1 ) ;
}
static int F_144 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_290 )
{
int V_123 ;
int V_56 ;
if ( ! V_7 -> V_127 ||
! ( F_76 ( V_7 -> V_128 . V_129 )
& V_130 ) )
return - V_15 ;
V_7 -> V_74 ( V_2 , V_102 , V_67 , - 1 ) ;
for ( V_56 = 0 ; V_56 < V_132 ; ++ V_56 )
V_7 -> V_291 ( V_2 , V_290 [ V_56 ] ) ;
V_123 = V_7 -> V_237 ( V_2 , V_7 ) ;
if ( V_123 & V_238 )
return - V_239 ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_67 , T_3 * V_290 )
{
int V_56 ;
if ( ! V_7 -> V_127 ||
! ( F_76 ( V_7 -> V_128 . V_129 )
& V_130 ) )
return - V_15 ;
V_7 -> V_74 ( V_2 , V_292 , V_67 , - 1 ) ;
for ( V_56 = 0 ; V_56 < V_132 ; ++ V_56 )
* V_290 ++ = V_7 -> V_76 ( V_2 ) ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int V_67 ,
T_6 * V_290 )
{
return - V_247 ;
}
static int F_147 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_121 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_25 == V_121 )
F_10 ( V_2 ) ;
else
F_74 ( L_21 ,
V_21 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_121 ) ;
}
static void F_150 ( struct V_6 * V_7 )
{
unsigned int V_196 = V_7 -> V_59 & V_60 ;
if ( ! V_7 -> V_104 )
V_7 -> V_104 = 20 ;
if ( V_7 -> V_74 == NULL )
V_7 -> V_74 = F_56 ;
if ( V_7 -> V_237 == NULL )
V_7 -> V_237 = F_69 ;
if ( ! V_7 -> V_143 )
V_7 -> V_143 = F_20 ;
if ( ! V_7 -> V_134 )
V_7 -> V_134 = F_144 ;
if ( ! V_7 -> V_293 )
V_7 -> V_293 = F_145 ;
if ( ! V_7 -> V_76 || V_7 -> V_76 == F_14 )
V_7 -> V_76 = V_196 ? F_16 : F_14 ;
if ( ! V_7 -> V_294 )
V_7 -> V_294 = F_19 ;
if ( ! V_7 -> V_79 )
V_7 -> V_79 = F_32 ;
if ( ! V_7 -> V_69 )
V_7 -> V_69 = F_35 ;
if ( ! V_7 -> V_34 || V_7 -> V_34 == F_24 )
V_7 -> V_34 = V_196 ? F_28 : F_24 ;
if ( ! V_7 -> V_291 || V_7 -> V_291 == F_22 )
V_7 -> V_291 = V_196 ? F_23 : F_22 ;
if ( ! V_7 -> V_162 || V_7 -> V_162 == F_26 )
V_7 -> V_162 = V_196 ? F_30 : F_26 ;
if ( ! V_7 -> V_295 )
V_7 -> V_295 = V_296 ;
if ( ! V_7 -> V_22 ) {
V_7 -> V_22 = & V_7 -> V_297 ;
F_151 ( V_7 -> V_22 ) ;
}
if ( ! V_7 -> V_222 )
V_7 -> V_222 = 1 ;
}
static void F_152 ( T_3 * V_298 , T_10 V_18 )
{
T_12 V_56 ;
V_298 [ V_18 - 1 ] = 0 ;
for ( V_56 = 0 ; V_56 < V_18 - 1 ; V_56 ++ ) {
if ( V_298 [ V_56 ] < ' ' || V_298 [ V_56 ] > 127 )
V_298 [ V_56 ] = '?' ;
}
F_153 ( V_298 ) ;
}
static T_4 F_154 ( T_4 V_299 , T_6 const * V_38 , T_10 V_18 )
{
int V_56 ;
while ( V_18 -- ) {
V_299 ^= * V_38 ++ << 8 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
V_299 = ( V_299 << 1 ) ^ ( ( V_299 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_299 ;
}
static int F_155 ( struct V_6 * V_7 ,
struct V_300 * V_38 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_301 * V_302 ;
struct V_303 * V_298 ;
struct V_304 * V_9 ;
T_3 * V_305 ;
int V_19 = - V_15 ;
int V_18 ;
int V_56 ;
V_18 = F_76 ( V_38 -> V_306 ) * 16 ;
V_302 = F_156 ( V_18 , V_139 ) ;
if ( ! V_302 )
return - V_140 ;
V_7 -> V_74 ( V_2 , V_307 , 0 , - 1 ) ;
V_7 -> V_74 ( V_2 , V_114 ,
sizeof( * V_38 ) * V_38 -> V_308 , - 1 ) ;
V_7 -> V_162 ( V_2 , ( T_3 * ) V_302 , V_18 ) ;
if ( ( F_154 ( V_309 , ( ( T_3 * ) V_302 ) + 2 , V_18 - 2 )
!= F_76 ( V_302 -> V_299 ) ) ) {
F_9 ( L_22 ) ;
goto V_310;
}
if ( strncmp ( V_302 -> V_311 , L_23 , 4 ) ) {
F_9 ( L_24 ) ;
goto V_310;
}
V_305 = ( T_3 * ) ( V_302 + 1 ) ;
for ( V_56 = 0 ; V_56 < V_312 ; V_56 ++ ) {
V_298 = V_302 -> V_313 + V_56 ;
if ( V_298 -> type == V_314 )
break;
V_305 += V_298 -> V_13 * 16 ;
}
if ( V_56 == V_312 ) {
F_9 ( L_25 ) ;
goto V_310;
}
V_9 = (struct V_304 * ) V_305 ;
if ( ! V_9 -> V_315 ) {
F_9 ( L_26 ) ;
goto V_310;
}
V_7 -> V_316 = V_9 -> V_317 ;
V_7 -> V_318 = 1 << V_9 -> V_315 ;
V_19 = 0 ;
V_310:
F_84 ( V_302 ) ;
return V_19 ;
}
static int F_157 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_300 * V_38 = & V_7 -> V_128 ;
int V_56 , V_319 ;
int V_320 ;
V_7 -> V_74 ( V_2 , V_101 , 0x20 , - 1 ) ;
if ( V_7 -> V_76 ( V_2 ) != 'O' || V_7 -> V_76 ( V_2 ) != 'N' ||
V_7 -> V_76 ( V_2 ) != 'F' || V_7 -> V_76 ( V_2 ) != 'I' )
return 0 ;
V_7 -> V_74 ( V_2 , V_307 , 0 , - 1 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
for ( V_319 = 0 ; V_319 < sizeof( * V_38 ) ; V_319 ++ )
( ( T_3 * ) V_38 ) [ V_319 ] = V_7 -> V_76 ( V_2 ) ;
if ( F_154 ( V_309 , ( T_3 * ) V_38 , 254 ) ==
F_76 ( V_38 -> V_299 ) ) {
break;
}
}
if ( V_56 == 3 ) {
F_74 ( L_27 ) ;
return 0 ;
}
V_320 = F_76 ( V_38 -> V_321 ) ;
if ( V_320 & ( 1 << 5 ) )
V_7 -> V_127 = 23 ;
else if ( V_320 & ( 1 << 4 ) )
V_7 -> V_127 = 22 ;
else if ( V_320 & ( 1 << 3 ) )
V_7 -> V_127 = 21 ;
else if ( V_320 & ( 1 << 2 ) )
V_7 -> V_127 = 20 ;
else if ( V_320 & ( 1 << 1 ) )
V_7 -> V_127 = 10 ;
if ( ! V_7 -> V_127 ) {
F_158 ( L_28 , V_320 ) ;
return 0 ;
}
F_152 ( V_38 -> V_322 , sizeof( V_38 -> V_322 ) ) ;
F_152 ( V_38 -> V_323 , sizeof( V_38 -> V_323 ) ) ;
if ( ! V_2 -> V_324 )
V_2 -> V_324 = V_38 -> V_323 ;
V_2 -> V_46 = F_159 ( V_38 -> V_325 ) ;
V_2 -> V_45 = 1 << ( F_81 ( F_159 ( V_38 -> V_274 ) ) - 1 ) ;
V_2 -> V_45 *= V_2 -> V_46 ;
V_2 -> V_12 = F_76 ( V_38 -> V_326 ) ;
V_7 -> V_96 = 1 << ( F_81 ( F_159 ( V_38 -> V_327 ) ) - 1 ) ;
V_7 -> V_96 *= ( T_2 ) V_2 -> V_45 * V_38 -> V_328 ;
V_7 -> V_329 = V_38 -> V_329 ;
V_7 -> V_288 = F_76 ( V_38 -> V_330 ) ;
V_7 -> V_289 = F_159 ( V_38 -> V_327 ) ;
if ( F_160 ( V_7 ) & V_331 )
V_7 -> V_59 |= V_60 ;
if ( V_38 -> V_317 != 0xff ) {
V_7 -> V_316 = V_38 -> V_317 ;
V_7 -> V_318 = 512 ;
} else if ( V_7 -> V_127 >= 21 &&
( F_160 ( V_7 ) & V_332 ) ) {
if ( V_2 -> V_46 > 512 && V_7 -> V_74 == F_56 )
V_7 -> V_74 = F_61 ;
if ( F_155 ( V_7 , V_38 ) )
F_137 ( L_29 ) ;
} else {
F_137 ( L_30 ) ;
}
return 1 ;
}
static int F_161 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
struct V_333 * V_38 = & V_7 -> V_334 ;
struct V_335 * V_9 ;
int V_320 ;
int V_56 , V_319 ;
V_7 -> V_74 ( V_2 , V_101 , 0x40 , - 1 ) ;
if ( V_7 -> V_76 ( V_2 ) != 'J' || V_7 -> V_76 ( V_2 ) != 'E' ||
V_7 -> V_76 ( V_2 ) != 'D' || V_7 -> V_76 ( V_2 ) != 'E' ||
V_7 -> V_76 ( V_2 ) != 'C' )
return 0 ;
V_7 -> V_74 ( V_2 , V_307 , 0x40 , - 1 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
for ( V_319 = 0 ; V_319 < sizeof( * V_38 ) ; V_319 ++ )
( ( T_3 * ) V_38 ) [ V_319 ] = V_7 -> V_76 ( V_2 ) ;
if ( F_154 ( V_309 , ( T_3 * ) V_38 , 510 ) ==
F_76 ( V_38 -> V_299 ) )
break;
}
if ( V_56 == 3 ) {
F_74 ( L_31 ) ;
return 0 ;
}
V_320 = F_76 ( V_38 -> V_321 ) ;
if ( V_320 & ( 1 << 2 ) )
V_7 -> V_336 = 10 ;
else if ( V_320 & ( 1 << 1 ) )
V_7 -> V_336 = 1 ;
if ( ! V_7 -> V_336 ) {
F_158 ( L_32 , V_320 ) ;
return 0 ;
}
F_152 ( V_38 -> V_322 , sizeof( V_38 -> V_322 ) ) ;
F_152 ( V_38 -> V_323 , sizeof( V_38 -> V_323 ) ) ;
if ( ! V_2 -> V_324 )
V_2 -> V_324 = V_38 -> V_323 ;
V_2 -> V_46 = F_159 ( V_38 -> V_325 ) ;
V_2 -> V_45 = 1 << ( F_81 ( F_159 ( V_38 -> V_274 ) ) - 1 ) ;
V_2 -> V_45 *= V_2 -> V_46 ;
V_2 -> V_12 = F_76 ( V_38 -> V_326 ) ;
V_7 -> V_96 = 1 << ( F_81 ( F_159 ( V_38 -> V_327 ) ) - 1 ) ;
V_7 -> V_96 *= ( T_2 ) V_2 -> V_45 * V_38 -> V_328 ;
V_7 -> V_329 = V_38 -> V_329 ;
if ( F_162 ( V_7 ) & V_337 )
V_7 -> V_59 |= V_60 ;
V_9 = & V_38 -> V_338 [ 0 ] ;
if ( V_9 -> V_315 >= 9 ) {
V_7 -> V_316 = V_9 -> V_317 ;
V_7 -> V_318 = 1 << V_9 -> V_315 ;
} else {
F_137 ( L_26 ) ;
}
return 1 ;
}
static int F_163 ( T_6 * V_339 , int V_340 , int V_341 )
{
int V_56 , V_319 ;
for ( V_56 = 0 ; V_56 < V_341 ; V_56 ++ )
for ( V_319 = V_56 + V_341 ; V_319 < V_340 ; V_319 += V_341 )
if ( V_339 [ V_56 ] != V_339 [ V_319 ] )
return 0 ;
return 1 ;
}
static int F_164 ( T_6 * V_339 , int V_340 )
{
int V_342 , V_341 ;
for ( V_342 = V_340 - 1 ; V_342 >= 0 ; V_342 -- )
if ( V_339 [ V_342 ] )
break;
if ( V_342 < 0 )
return 0 ;
for ( V_341 = 1 ; V_341 < V_340 ; V_341 ++ )
if ( F_163 ( V_339 , V_340 , V_341 ) )
break;
if ( V_341 < V_340 )
return V_341 ;
if ( V_342 < V_340 - 1 )
return V_342 + 1 ;
return V_340 ;
}
static int F_165 ( T_6 V_343 )
{
int V_344 ;
V_344 = V_343 & V_345 ;
V_344 >>= V_346 ;
return V_344 + 1 ;
}
void F_166 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_347 ;
T_6 * V_339 = V_7 -> V_348 . V_153 ;
V_7 -> V_329 = F_165 ( V_339 [ 2 ] ) ;
V_347 = V_339 [ 3 ] ;
V_2 -> V_46 = 1024 << ( V_347 & 0x03 ) ;
V_347 >>= 2 ;
V_2 -> V_12 = ( 8 << ( V_347 & 0x01 ) ) * ( V_2 -> V_46 >> 9 ) ;
V_347 >>= 2 ;
V_2 -> V_45 = ( 64 * 1024 ) << ( V_347 & 0x03 ) ;
V_347 >>= 2 ;
if ( V_347 & 0x1 )
V_7 -> V_59 |= V_60 ;
}
static void F_167 ( struct V_6 * V_7 , struct V_349 * type )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
V_2 -> V_45 = type -> V_45 ;
V_2 -> V_46 = type -> V_350 ;
V_2 -> V_12 = V_2 -> V_46 / 32 ;
V_7 -> V_329 = 1 ;
}
static void F_168 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
if ( V_2 -> V_46 > 512 || ( V_7 -> V_59 & V_60 ) )
V_7 -> V_52 = V_351 ;
else
V_7 -> V_52 = V_352 ;
}
static inline bool F_169 ( struct V_349 * type )
{
return type -> V_353 ;
}
static bool F_170 ( struct V_6 * V_7 ,
struct V_349 * type )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
T_6 * V_339 = V_7 -> V_348 . V_153 ;
if ( ! strncmp ( type -> V_348 , V_339 , type -> V_353 ) ) {
V_2 -> V_46 = type -> V_350 ;
V_2 -> V_45 = type -> V_45 ;
V_2 -> V_12 = type -> V_12 ;
V_7 -> V_329 = F_165 ( V_339 [ 2 ] ) ;
V_7 -> V_96 = ( T_2 ) type -> V_96 << 20 ;
V_7 -> V_59 |= type -> V_59 ;
V_7 -> V_316 = F_171 ( type ) ;
V_7 -> V_318 = F_172 ( type ) ;
V_7 -> V_133 =
type -> V_133 ;
if ( ! V_2 -> V_324 )
V_2 -> V_324 = type -> V_324 ;
return true ;
}
return false ;
}
static void F_173 ( struct V_6 * V_7 )
{
if ( V_7 -> V_322 . V_354 && V_7 -> V_322 . V_354 -> V_55 &&
V_7 -> V_322 . V_354 -> V_55 -> V_355 ) {
V_7 -> V_329 = F_165 ( V_7 -> V_348 . V_153 [ 2 ] ) ;
V_7 -> V_322 . V_354 -> V_55 -> V_355 ( V_7 ) ;
} else {
F_166 ( V_7 ) ;
}
}
static int F_174 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_322 . V_354 || ! V_7 -> V_322 . V_354 -> V_55 ||
! V_7 -> V_322 . V_354 -> V_55 -> V_356 )
return 0 ;
return V_7 -> V_322 . V_354 -> V_55 -> V_356 ( V_7 ) ;
}
static void F_175 ( struct V_6 * V_7 )
{
if ( V_7 -> V_322 . V_354 && V_7 -> V_322 . V_354 -> V_55 &&
V_7 -> V_322 . V_354 -> V_55 -> V_357 )
V_7 -> V_322 . V_354 -> V_55 -> V_357 ( V_7 ) ;
}
static int F_176 ( struct V_6 * V_7 , struct V_349 * type )
{
const struct V_358 * V_322 ;
struct V_1 * V_2 = F_72 ( V_7 ) ;
int V_196 ;
int V_56 ;
T_6 * V_339 = V_7 -> V_348 . V_153 ;
T_6 V_359 , V_360 ;
F_85 ( V_7 , 0 ) ;
V_7 -> V_143 ( V_2 , 0 ) ;
V_7 -> V_74 ( V_2 , V_101 , 0x00 , - 1 ) ;
V_359 = V_7 -> V_76 ( V_2 ) ;
V_360 = V_7 -> V_76 ( V_2 ) ;
V_7 -> V_74 ( V_2 , V_101 , 0x00 , - 1 ) ;
for ( V_56 = 0 ; V_56 < F_177 ( V_7 -> V_348 . V_153 ) ; V_56 ++ )
V_339 [ V_56 ] = V_7 -> V_76 ( V_2 ) ;
if ( V_339 [ 0 ] != V_359 || V_339 [ 1 ] != V_360 ) {
F_158 ( L_33 ,
V_359 , V_360 , V_339 [ 0 ] , V_339 [ 1 ] ) ;
return - V_361 ;
}
V_7 -> V_348 . V_18 = F_164 ( V_339 , F_177 ( V_7 -> V_348 . V_153 ) ) ;
V_322 = F_178 ( V_359 ) ;
V_7 -> V_322 . V_354 = V_322 ;
if ( ! type )
type = V_362 ;
V_196 = V_7 -> V_59 & V_60 ;
V_7 -> V_59 &= ~ V_60 ;
for (; type -> V_324 != NULL ; type ++ ) {
if ( F_169 ( type ) ) {
if ( F_170 ( V_7 , type ) )
goto V_363;
} else if ( V_360 == type -> V_360 ) {
break;
}
}
V_7 -> V_127 = 0 ;
if ( ! type -> V_324 || ! type -> V_350 ) {
if ( F_157 ( V_7 ) )
goto V_363;
if ( F_161 ( V_7 ) )
goto V_363;
}
if ( ! type -> V_324 )
return - V_361 ;
if ( ! V_2 -> V_324 )
V_2 -> V_324 = type -> V_324 ;
V_7 -> V_96 = ( T_2 ) type -> V_96 << 20 ;
if ( ! type -> V_350 )
F_173 ( V_7 ) ;
else
F_167 ( V_7 , type ) ;
V_7 -> V_59 |= type -> V_59 ;
V_363:
if ( V_7 -> V_59 & V_364 ) {
F_70 ( V_196 & V_60 ) ;
F_150 ( V_7 ) ;
} else if ( V_196 != ( V_7 -> V_59 & V_60 ) ) {
F_158 ( L_34 ,
V_359 , V_360 ) ;
F_158 ( L_35 , F_179 ( V_322 ) ,
V_2 -> V_324 ) ;
F_137 ( L_36 , V_196 ? 16 : 8 ,
( V_7 -> V_59 & V_60 ) ? 16 : 8 ) ;
return - V_15 ;
}
F_168 ( V_7 ) ;
V_7 -> V_47 = F_180 ( V_2 -> V_46 ) - 1 ;
V_7 -> V_48 = ( V_7 -> V_96 >> V_7 -> V_47 ) - 1 ;
V_7 -> V_365 = V_7 -> V_20 =
F_180 ( V_2 -> V_45 ) - 1 ;
if ( V_7 -> V_96 & 0xffffffff )
V_7 -> V_218 = F_180 ( ( unsigned ) V_7 -> V_96 ) - 1 ;
else {
V_7 -> V_218 = F_180 ( ( unsigned ) ( V_7 -> V_96 >> 32 ) ) ;
V_7 -> V_218 += 32 - 1 ;
}
V_7 -> V_53 = 8 ;
V_7 -> V_279 = F_135 ;
if ( V_2 -> V_46 > 512 && V_7 -> V_74 == F_56 )
V_7 -> V_74 = F_61 ;
F_158 ( L_34 ,
V_359 , V_360 ) ;
if ( V_7 -> V_127 )
F_158 ( L_35 , F_179 ( V_322 ) ,
V_7 -> V_128 . V_323 ) ;
else if ( V_7 -> V_336 )
F_158 ( L_35 , F_179 ( V_322 ) ,
V_7 -> V_334 . V_323 ) ;
else
F_158 ( L_35 , F_179 ( V_322 ) ,
type -> V_324 ) ;
F_158 ( L_37 ,
( int ) ( V_7 -> V_96 >> 20 ) , F_181 ( V_7 ) ? L_38 : L_39 ,
V_2 -> V_45 >> 10 , V_2 -> V_46 , V_2 -> V_12 ) ;
return 0 ;
}
static int F_182 ( struct V_366 * V_367 )
{
const char * V_368 ;
int V_136 , V_56 ;
V_136 = F_183 ( V_367 , L_40 , & V_368 ) ;
if ( V_136 < 0 )
return V_136 ;
for ( V_56 = 0 ; V_56 < F_177 ( V_369 ) ; V_56 ++ )
if ( ! strcasecmp ( V_368 , V_369 [ V_56 ] ) )
return V_56 ;
if ( ! strcasecmp ( V_368 , L_41 ) )
return V_370 ;
return - V_361 ;
}
static int F_184 ( struct V_366 * V_367 )
{
const char * V_368 ;
int V_136 , V_56 ;
V_136 = F_183 ( V_367 , L_42 , & V_368 ) ;
if ( ! V_136 ) {
for ( V_56 = V_371 ; V_56 < F_177 ( V_372 ) ; V_56 ++ )
if ( ! strcasecmp ( V_368 , V_372 [ V_56 ] ) )
return V_56 ;
return - V_361 ;
}
V_136 = F_183 ( V_367 , L_40 , & V_368 ) ;
if ( V_136 < 0 )
return V_136 ;
if ( ! strcasecmp ( V_368 , L_43 ) )
return V_371 ;
else if ( ! strcasecmp ( V_368 , L_41 ) )
return V_373 ;
return - V_361 ;
}
static int F_185 ( struct V_366 * V_367 )
{
int V_19 ;
T_11 V_320 ;
V_19 = F_186 ( V_367 , L_44 , & V_320 ) ;
return V_19 ? V_19 : V_320 ;
}
static int F_187 ( struct V_366 * V_367 )
{
int V_19 ;
T_11 V_320 ;
V_19 = F_186 ( V_367 , L_45 , & V_320 ) ;
return V_19 ? V_19 : V_320 ;
}
static int F_188 ( struct V_366 * V_367 )
{
T_11 V_320 ;
if ( F_186 ( V_367 , L_46 , & V_320 ) )
return 8 ;
switch ( V_320 ) {
case 8 :
case 16 :
return V_320 ;
default:
return - V_239 ;
}
}
static bool F_189 ( struct V_366 * V_367 )
{
return F_190 ( V_367 , L_47 ) ;
}
static int F_191 ( struct V_6 * V_7 )
{
struct V_366 * V_374 = F_192 ( V_7 ) ;
int V_375 , V_376 , V_377 , V_378 ;
if ( ! V_374 )
return 0 ;
if ( F_188 ( V_374 ) == 16 )
V_7 -> V_59 |= V_60 ;
if ( F_189 ( V_374 ) )
V_7 -> V_43 |= V_379 ;
V_375 = F_182 ( V_374 ) ;
V_376 = F_184 ( V_374 ) ;
V_377 = F_187 ( V_374 ) ;
V_378 = F_185 ( V_374 ) ;
if ( V_375 >= 0 )
V_7 -> V_9 . V_62 = V_375 ;
if ( V_376 >= 0 )
V_7 -> V_9 . V_380 = V_376 ;
if ( V_377 >= 0 )
V_7 -> V_9 . V_199 = V_377 ;
if ( V_378 > 0 )
V_7 -> V_9 . V_164 = V_378 ;
if ( F_190 ( V_374 , L_48 ) )
V_7 -> V_9 . V_59 |= V_381 ;
return 0 ;
}
int F_193 ( struct V_1 * V_2 , int V_382 ,
struct V_349 * V_383 )
{
int V_56 , V_384 , V_385 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_19 ;
V_19 = F_191 ( V_7 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_2 -> V_324 && V_2 -> V_386 . V_387 )
V_2 -> V_324 = F_194 ( V_2 -> V_386 . V_387 ) ;
if ( ( ! V_7 -> V_74 || ! V_7 -> V_143 ) && ! V_7 -> V_30 ) {
F_74 ( L_49 ) ;
return - V_15 ;
}
F_150 ( V_7 ) ;
V_19 = F_176 ( V_7 , V_383 ) ;
if ( V_19 ) {
if ( ! ( V_7 -> V_59 & V_388 ) )
F_137 ( L_50 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
return V_19 ;
}
V_384 = V_7 -> V_348 . V_153 [ 0 ] ;
V_385 = V_7 -> V_348 . V_153 [ 1 ] ;
V_7 -> V_143 ( V_2 , - 1 ) ;
for ( V_56 = 1 ; V_56 < V_382 ; V_56 ++ ) {
F_85 ( V_7 , V_56 ) ;
V_7 -> V_143 ( V_2 , V_56 ) ;
V_7 -> V_74 ( V_2 , V_101 , 0x00 , - 1 ) ;
if ( V_384 != V_7 -> V_76 ( V_2 ) ||
V_385 != V_7 -> V_76 ( V_2 ) ) {
V_7 -> V_143 ( V_2 , - 1 ) ;
break;
}
V_7 -> V_143 ( V_2 , - 1 ) ;
}
if ( V_56 > 1 )
F_158 ( L_51 , V_56 ) ;
V_7 -> V_389 = V_56 ;
V_2 -> V_164 = V_56 * V_7 -> V_96 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_70 ( V_9 -> V_62 != V_370 ) )
return - V_15 ;
switch ( V_9 -> V_380 ) {
case V_371 :
V_9 -> V_179 = V_390 ;
V_9 -> V_181 = V_391 ;
V_9 -> V_227 = F_92 ;
V_9 -> V_226 = F_95 ;
V_9 -> V_261 = F_121 ;
V_9 -> V_178 = F_90 ;
V_9 -> V_248 = F_119 ;
V_9 -> V_50 = F_112 ;
V_9 -> V_271 = F_115 ;
if ( ! V_9 -> V_164 )
V_9 -> V_164 = 256 ;
V_9 -> V_166 = 3 ;
V_9 -> V_199 = 1 ;
return 0 ;
case V_373 :
if ( ! F_196 () ) {
F_197 ( 1 , L_52 ) ;
return - V_15 ;
}
V_9 -> V_179 = V_392 ;
V_9 -> V_181 = V_393 ;
V_9 -> V_227 = F_92 ;
V_9 -> V_226 = F_95 ;
V_9 -> V_261 = F_121 ;
V_9 -> V_178 = F_90 ;
V_9 -> V_248 = F_119 ;
V_9 -> V_50 = F_112 ;
V_9 -> V_271 = F_115 ;
if ( ! V_9 -> V_164 && ( V_2 -> V_12 >= 64 ) ) {
V_9 -> V_164 = 512 ;
V_9 -> V_199 = 4 ;
}
if ( ! V_2 -> V_394 ) {
if ( V_2 -> V_12 < 64 ) {
F_197 ( 1 , L_53 ) ;
return - V_15 ;
}
F_198 ( V_2 , & V_395 ) ;
}
if ( V_2 -> V_394 == & V_395 &&
V_9 -> V_59 & V_381 ) {
int V_168 , V_166 ;
V_9 -> V_164 = 1024 ;
V_168 = V_2 -> V_46 / V_9 -> V_164 ;
V_166 = ( V_2 -> V_12 - 2 ) / V_168 ;
V_9 -> V_199 = V_166 * 8 / F_81 ( 8 * V_9 -> V_164 ) ;
}
V_9 -> V_166 = 0 ;
V_9 -> V_396 = F_199 ( V_2 ) ;
if ( ! V_9 -> V_396 ) {
F_197 ( 1 , L_54 ) ;
return - V_15 ;
}
return 0 ;
default:
F_197 ( 1 , L_55 ) ;
return - V_15 ;
}
}
int F_200 ( struct V_6 * V_7 ,
const struct V_397 * V_398 , int V_399 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
const struct V_400 * V_401 ;
int V_402 = V_7 -> V_9 . V_164 ;
int V_403 = V_7 -> V_9 . V_199 ;
int V_404 , V_253 ;
int V_56 , V_319 ;
if ( F_70 ( V_399 < 0 ) )
return - V_15 ;
if ( ! V_402 || ! V_403 )
return - V_405 ;
V_404 = V_2 -> V_46 / V_402 ;
for ( V_56 = 0 ; V_56 < V_398 -> V_406 ; V_56 ++ ) {
V_401 = & V_398 -> V_407 [ V_56 ] ;
if ( V_401 -> V_408 != V_402 )
continue;
for ( V_319 = 0 ; V_319 < V_401 -> V_409 ; V_319 ++ ) {
if ( V_401 -> V_410 [ V_319 ] != V_403 )
continue;
V_253 = V_398 -> V_411 ( V_402 ,
V_403 ) ;
if ( F_201 ( V_253 < 0 ) )
return V_253 ;
if ( V_253 * V_404 > V_399 ) {
F_74 ( L_56 ,
V_402 , V_403 ) ;
return - V_412 ;
}
V_7 -> V_9 . V_166 = V_253 ;
return 0 ;
}
}
F_74 ( L_57 ,
V_402 , V_403 ) ;
return - V_247 ;
}
int F_202 ( struct V_6 * V_7 ,
const struct V_397 * V_398 , int V_399 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
const struct V_400 * V_401 ;
int V_413 = V_7 -> V_318 ;
int V_414 = V_7 -> V_316 ;
int V_415 , V_416 , V_199 , V_404 , V_253 , V_417 ;
int V_418 , V_419 , V_420 ;
int V_421 = V_422 ;
int V_56 , V_319 ;
if ( F_70 ( V_399 < 0 ) )
return - V_15 ;
if ( ! V_413 || ! V_414 )
return - V_247 ;
V_415 = V_2 -> V_46 / V_413 * V_414 ;
for ( V_56 = 0 ; V_56 < V_398 -> V_406 ; V_56 ++ ) {
V_401 = & V_398 -> V_407 [ V_56 ] ;
V_416 = V_401 -> V_408 ;
for ( V_319 = 0 ; V_319 < V_401 -> V_409 ; V_319 ++ ) {
V_199 = V_401 -> V_410 [ V_319 ] ;
if ( V_416 < V_413 && V_199 < V_414 )
continue;
if ( V_2 -> V_46 % V_416 )
continue;
V_404 = V_2 -> V_46 / V_416 ;
V_253 = V_398 -> V_411 ( V_416 , V_199 ) ;
if ( F_201 ( V_253 < 0 ) )
continue;
V_417 = V_253 * V_404 ;
if ( V_417 > V_399 ||
V_199 * V_404 < V_415 )
continue;
if ( V_417 < V_421 ) {
V_421 = V_417 ;
V_418 = V_416 ;
V_419 = V_199 ;
V_420 = V_253 ;
}
}
}
if ( V_421 == V_422 )
return - V_247 ;
V_7 -> V_9 . V_164 = V_418 ;
V_7 -> V_9 . V_199 = V_419 ;
V_7 -> V_9 . V_166 = V_420 ;
return 0 ;
}
int F_203 ( struct V_6 * V_7 ,
const struct V_397 * V_398 , int V_399 )
{
struct V_1 * V_2 = F_72 ( V_7 ) ;
const struct V_400 * V_401 ;
int V_416 , V_199 , V_404 , V_253 , V_423 ;
int V_424 = 0 ;
int V_418 = 0 ;
int V_419 , V_420 ;
int V_56 , V_319 ;
if ( F_70 ( V_399 < 0 ) )
return - V_15 ;
for ( V_56 = 0 ; V_56 < V_398 -> V_406 ; V_56 ++ ) {
V_401 = & V_398 -> V_407 [ V_56 ] ;
V_416 = V_401 -> V_408 ;
if ( V_7 -> V_9 . V_164 && V_416 != V_7 -> V_9 . V_164 )
continue;
for ( V_319 = 0 ; V_319 < V_401 -> V_409 ; V_319 ++ ) {
V_199 = V_401 -> V_410 [ V_319 ] ;
if ( V_2 -> V_46 % V_416 )
continue;
V_404 = V_2 -> V_46 / V_416 ;
V_253 = V_398 -> V_411 ( V_416 , V_199 ) ;
if ( F_201 ( V_253 < 0 ) )
continue;
if ( V_253 * V_404 > V_399 )
continue;
V_423 = V_199 * V_404 ;
if ( V_423 > V_424 ||
( V_423 == V_424 && V_416 > V_418 ) ) {
V_424 = V_423 ;
V_418 = V_416 ;
V_419 = V_199 ;
V_420 = V_253 ;
}
}
}
if ( ! V_424 )
return - V_247 ;
V_7 -> V_9 . V_164 = V_418 ;
V_7 -> V_9 . V_199 = V_419 ;
V_7 -> V_9 . V_166 = V_420 ;
return 0 ;
}
static bool F_204 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_423 , V_425 ;
if ( V_9 -> V_164 == 0 || V_7 -> V_318 == 0 )
return true ;
V_423 = ( V_2 -> V_46 * V_9 -> V_199 ) / V_9 -> V_164 ;
V_425 = ( V_2 -> V_46 * V_7 -> V_316 ) / V_7 -> V_318 ;
return V_423 >= V_425 && V_9 -> V_199 >= V_7 -> V_316 ;
}
static bool F_205 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( F_109 ( V_9 ) )
return false ;
return ( ! V_9 -> V_227 || ! V_9 -> V_261 ||
! V_9 -> V_178 || ! V_9 -> V_248 ||
( F_110 ( V_7 ) && ! V_9 -> V_226 ) ||
( F_206 ( V_7 ) && ! V_9 -> V_260 &&
V_9 -> V_200 && V_9 -> V_179 ) ) ;
}
int F_207 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_426 * V_427 = NULL ;
int V_19 , V_56 ;
if ( F_70 ( ( V_7 -> V_43 & V_64 ) &&
! ( V_7 -> V_43 & V_379 ) ) ) {
return - V_15 ;
}
if ( F_205 ( V_7 ) ) {
F_74 ( L_58 ) ;
return - V_15 ;
}
if ( ! ( V_7 -> V_59 & V_428 ) ) {
V_427 = F_80 ( sizeof( * V_427 ) , V_139 ) ;
if ( ! V_427 )
return - V_140 ;
V_427 -> V_174 = F_156 ( V_2 -> V_12 , V_139 ) ;
if ( ! V_427 -> V_174 ) {
V_19 = - V_140 ;
goto V_429;
}
V_427 -> V_176 = F_156 ( V_2 -> V_12 , V_139 ) ;
if ( ! V_427 -> V_176 ) {
V_19 = - V_140 ;
goto V_429;
}
V_427 -> V_224 = F_156 ( V_2 -> V_46 + V_2 -> V_12 ,
V_139 ) ;
if ( ! V_427 -> V_224 ) {
V_19 = - V_140 ;
goto V_429;
}
V_7 -> V_173 = V_427 ;
} else if ( ! V_7 -> V_173 ) {
return - V_140 ;
}
V_7 -> V_143 ( V_2 , 0 ) ;
V_19 = F_174 ( V_7 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
if ( V_19 )
goto V_429;
V_7 -> V_51 = V_7 -> V_173 -> V_224 + V_2 -> V_46 ;
if ( ! V_2 -> V_394 &&
! ( V_9 -> V_62 == V_370 && V_9 -> V_380 == V_373 ) ) {
switch ( V_2 -> V_12 ) {
case 8 :
case 16 :
F_198 ( V_2 , & V_430 ) ;
break;
case 64 :
case 128 :
F_198 ( V_2 , & V_431 ) ;
break;
default:
F_197 ( 1 , L_59 ,
V_2 -> V_12 ) ;
V_19 = - V_15 ;
goto V_432;
}
}
switch ( V_9 -> V_62 ) {
case V_433 :
if ( ! V_9 -> V_179 || ! V_9 -> V_181 || ! V_9 -> V_200 ) {
F_197 ( 1 , L_60 ) ;
V_19 = - V_15 ;
goto V_432;
}
if ( ! V_9 -> V_227 )
V_9 -> V_227 = F_98 ;
case V_434 :
if ( ! V_9 -> V_227 )
V_9 -> V_227 = F_97 ;
if ( ! V_9 -> V_261 )
V_9 -> V_261 = F_123 ;
if ( ! V_9 -> V_178 )
V_9 -> V_178 = F_90 ;
if ( ! V_9 -> V_248 )
V_9 -> V_248 = F_119 ;
if ( ! V_9 -> V_50 )
V_9 -> V_50 = F_112 ;
if ( ! V_9 -> V_271 )
V_9 -> V_271 = F_115 ;
if ( ! V_9 -> V_226 )
V_9 -> V_226 = F_95 ;
if ( ! V_9 -> V_260 && V_9 -> V_200 && V_9 -> V_179 )
V_9 -> V_260 = F_124 ;
case V_435 :
if ( ( ! V_9 -> V_179 || ! V_9 -> V_181 || ! V_9 -> V_200 ) &&
( ! V_9 -> V_227 ||
V_9 -> V_227 == F_97 ||
! V_9 -> V_261 ||
V_9 -> V_261 == F_123 ) ) {
F_197 ( 1 , L_60 ) ;
V_19 = - V_15 ;
goto V_432;
}
if ( ! V_9 -> V_227 )
V_9 -> V_227 = F_99 ;
if ( ! V_9 -> V_261 )
V_9 -> V_261 = F_125 ;
if ( ! V_9 -> V_178 )
V_9 -> V_178 = F_91 ;
if ( ! V_9 -> V_248 )
V_9 -> V_248 = F_120 ;
if ( ! V_9 -> V_50 )
V_9 -> V_50 = F_113 ;
if ( ! V_9 -> V_271 )
V_9 -> V_271 = F_116 ;
if ( V_2 -> V_46 >= V_9 -> V_164 ) {
if ( ! V_9 -> V_199 ) {
F_197 ( 1 , L_61 ) ;
V_19 = - V_15 ;
goto V_432;
}
break;
}
F_137 ( L_62 ,
V_9 -> V_164 , V_2 -> V_46 ) ;
V_9 -> V_62 = V_370 ;
V_9 -> V_380 = V_371 ;
case V_370 :
V_19 = F_195 ( V_2 ) ;
if ( V_19 ) {
V_19 = - V_15 ;
goto V_432;
}
break;
case V_436 :
if ( ! V_9 -> V_227 || ! V_9 -> V_261 ) {
F_197 ( 1 , L_63 ) ;
V_19 = - V_15 ;
goto V_432;
}
if ( ! V_9 -> V_50 )
V_9 -> V_50 = F_112 ;
if ( ! V_9 -> V_271 )
V_9 -> V_271 = F_115 ;
break;
case V_437 :
F_137 ( L_64 ) ;
V_9 -> V_227 = F_90 ;
V_9 -> V_261 = F_119 ;
V_9 -> V_50 = F_112 ;
V_9 -> V_178 = F_90 ;
V_9 -> V_248 = F_119 ;
V_9 -> V_271 = F_115 ;
V_9 -> V_164 = V_2 -> V_46 ;
V_9 -> V_166 = 0 ;
V_9 -> V_199 = 0 ;
break;
default:
F_197 ( 1 , L_65 , V_9 -> V_62 ) ;
V_19 = - V_15 ;
goto V_432;
}
if ( ! V_9 -> V_245 )
V_9 -> V_245 = V_9 -> V_50 ;
if ( ! V_9 -> V_270 )
V_9 -> V_270 = V_9 -> V_271 ;
V_2 -> V_377 = V_9 -> V_199 ;
V_2 -> V_438 = V_9 -> V_164 ;
V_9 -> V_168 = V_2 -> V_46 / V_9 -> V_164 ;
if ( V_9 -> V_168 * V_9 -> V_164 != V_2 -> V_46 ) {
F_197 ( 1 , L_66 ) ;
V_19 = - V_15 ;
goto V_432;
}
V_9 -> V_14 = V_9 -> V_168 * V_9 -> V_166 ;
if ( V_9 -> V_14 > V_2 -> V_12 ) {
F_197 ( 1 , L_67 ) ;
V_19 = - V_15 ;
goto V_432;
}
V_19 = F_208 ( V_2 ) ;
if ( V_19 < 0 )
V_19 = 0 ;
V_2 -> V_399 = V_19 ;
if ( ! F_204 ( V_2 ) )
F_137 ( L_68 ,
V_2 -> V_324 ) ;
if ( ! ( V_7 -> V_59 & V_259 ) && F_181 ( V_7 ) ) {
switch ( V_9 -> V_168 ) {
case 2 :
V_2 -> V_439 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_439 = 2 ;
break;
}
}
V_7 -> V_440 = V_2 -> V_46 >> V_2 -> V_439 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_223 = - 1 ;
switch ( V_9 -> V_62 ) {
case V_370 :
if ( V_7 -> V_47 > 9 )
V_7 -> V_59 |= V_441 ;
break;
default:
break;
}
V_2 -> type = F_181 ( V_7 ) ? V_442 : V_443 ;
V_2 -> V_444 = ( V_7 -> V_59 & V_445 ) ? V_446 :
V_447 ;
V_2 -> V_448 = F_136 ;
V_2 -> V_449 = NULL ;
V_2 -> V_450 = NULL ;
V_2 -> V_451 = F_111 ;
V_2 -> V_452 = F_133 ;
V_2 -> V_453 = F_132 ;
V_2 -> V_454 = F_118 ;
V_2 -> V_455 = F_134 ;
V_2 -> V_456 = F_139 ;
V_2 -> V_457 = NULL ;
V_2 -> V_458 = NULL ;
V_2 -> V_459 = F_147 ;
V_2 -> V_460 = F_148 ;
V_2 -> V_461 = F_149 ;
V_2 -> V_462 = F_42 ;
V_2 -> V_463 = F_140 ;
V_2 -> V_464 = F_141 ;
V_2 -> V_465 = F_142 ;
V_2 -> V_466 = V_2 -> V_46 ;
if ( ! V_2 -> V_467 )
V_2 -> V_467 = F_209 ( V_2 -> V_377 * 3 , 4 ) ;
V_19 = F_77 ( V_7 ) ;
if ( V_19 )
goto V_432;
for ( V_56 = 0 ; V_56 < V_7 -> V_389 ; V_56 ++ ) {
V_7 -> V_143 ( V_2 , V_56 ) ;
V_19 = F_75 ( V_7 , V_56 ) ;
V_7 -> V_143 ( V_2 , - 1 ) ;
if ( V_19 )
goto V_468;
}
if ( V_7 -> V_59 & V_469 )
return 0 ;
V_19 = V_7 -> V_295 ( V_2 ) ;
if ( V_19 )
goto V_468;
return 0 ;
V_468:
F_83 ( V_7 ) ;
V_432:
F_175 ( V_7 ) ;
V_429:
if ( V_427 ) {
F_84 ( V_427 -> V_224 ) ;
F_84 ( V_427 -> V_176 ) ;
F_84 ( V_427 -> V_174 ) ;
F_84 ( V_427 ) ;
}
return V_19 ;
}
int F_210 ( struct V_1 * V_2 , int V_382 )
{
int V_19 ;
V_19 = F_193 ( V_2 , V_382 , NULL ) ;
if ( ! V_19 )
V_19 = F_207 ( V_2 ) ;
return V_19 ;
}
void F_211 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 . V_62 == V_370 &&
V_7 -> V_9 . V_380 == V_373 )
F_212 ( (struct V_470 * ) V_7 -> V_9 . V_396 ) ;
F_83 ( V_7 ) ;
F_84 ( V_7 -> V_70 ) ;
if ( ! ( V_7 -> V_59 & V_428 ) && V_7 -> V_173 ) {
F_84 ( V_7 -> V_173 -> V_224 ) ;
F_84 ( V_7 -> V_173 -> V_176 ) ;
F_84 ( V_7 -> V_173 -> V_174 ) ;
F_84 ( V_7 -> V_173 ) ;
}
if ( V_7 -> V_471 && V_7 -> V_471 -> V_59
& V_472 )
F_84 ( V_7 -> V_471 ) ;
F_175 ( V_7 ) ;
}
void F_213 ( struct V_1 * V_2 )
{
F_214 ( V_2 ) ;
F_211 ( F_2 ( V_2 ) ) ;
}
