static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static const char * F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return NULL ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 ,
const unsigned int * * V_4 ,
unsigned int * V_5 )
{
return - V_6 ;
}
static bool F_4 ( struct V_7 * V_8 , unsigned int V_9 )
{
if ( V_9 >= V_8 -> V_10 -> V_11 )
return false ;
if ( V_8 -> V_10 -> V_12 != V_13 )
return false ;
return ! strcmp ( V_8 -> V_10 -> V_4 [ V_9 ] . V_14 , L_1 ) ;
}
static int F_5 ( struct V_15 * V_16 ,
unsigned int V_17 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
if ( F_4 ( V_8 , V_17 ) )
return false ;
V_19 = F_7 ( V_8 -> V_20 , V_8 -> V_10 -> V_21 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
return ! ! ( V_18 & F_8 ( V_17 ) ) ;
}
static int F_9 ( struct V_15 * V_16 , unsigned int V_17 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
if ( F_4 ( V_8 , V_17 ) )
return - V_22 ;
V_19 = F_7 ( V_8 -> V_20 , V_8 -> V_10 -> V_23 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
return ! ! ( V_18 & F_8 ( V_17 ) ) ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_17 ,
int V_18 )
{
return F_11 ( V_8 -> V_20 , V_8 -> V_10 -> V_23 ,
F_8 ( V_17 ) , V_18 ? F_8 ( V_17 ) : 0 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
int V_18 )
{
return F_13 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_24 . V_25 . V_26 ,
( V_18 ? 0x1f : 0x10 ) ) ;
}
static void F_14 ( struct V_15 * V_16 , unsigned int V_17 ,
int V_18 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
if ( F_4 ( V_8 , V_17 ) )
F_12 ( V_8 , V_18 ) ;
else
F_10 ( V_8 , V_17 , V_18 ) ;
}
static void F_15 ( struct V_15 * V_16 ,
unsigned long * V_27 ,
unsigned long * V_28 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
F_11 ( V_8 -> V_20 , V_8 -> V_10 -> V_23 , * V_27 , * V_28 ) ;
}
static int F_16 ( struct V_15 * V_16 ,
unsigned int V_17 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
if ( F_4 ( V_8 , V_17 ) )
return - V_22 ;
return F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_21 ,
F_8 ( V_17 ) , F_8 ( V_17 ) ) ;
}
static int F_17 ( struct V_15 * V_16 ,
unsigned int V_17 , int V_18 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
int V_19 ;
if ( F_4 ( V_8 , V_17 ) )
return F_12 ( V_8 , V_18 ) ;
V_19 = F_10 ( V_8 , V_17 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_21 ,
F_8 ( V_17 ) , 0 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_7 * V_8 =
F_6 ( F_19 ( V_30 ) ) ;
unsigned int V_31 = V_30 -> V_32 ;
V_8 -> V_33 . V_34 |= F_8 ( V_31 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_7 * V_8 =
F_6 ( F_19 ( V_30 ) ) ;
unsigned int V_31 = V_30 -> V_32 ;
V_8 -> V_33 . V_34 &= ~ F_8 ( V_31 ) ;
}
static void F_21 ( struct V_7 * V_8 ,
unsigned int line , unsigned int V_35 )
{
const unsigned int V_31 = line * 2 ;
const unsigned int V_27 = ~ ( ( V_36 |
V_37 ) << V_31 ) ;
V_8 -> V_33 . V_35 &= V_27 ;
V_8 -> V_33 . V_35 |= V_35 << V_31 ;
}
static int F_22 ( struct V_29 * V_30 , unsigned int V_38 )
{
struct V_7 * V_8 =
F_6 ( F_19 ( V_30 ) ) ;
unsigned int V_31 , V_39 = 0 ;
if ( V_38 & ( V_40 | V_41 ) )
return - V_22 ;
V_31 = V_30 -> V_32 ;
if ( V_38 & V_42 )
V_39 |= V_36 ;
if ( V_38 & V_43 )
V_39 |= V_37 ;
F_21 ( V_8 , V_31 , V_39 ) ;
return 0 ;
}
static T_1 F_23 ( int V_33 , void * V_44 )
{
struct V_7 * V_8 = (struct V_7 * ) V_44 ;
unsigned long V_31 , V_45 ;
unsigned int V_39 ;
int V_46 ;
V_46 = F_7 ( V_8 -> V_20 , V_8 -> V_10 -> V_47 , & V_39 ) ;
if ( V_46 < 0 )
return V_48 ;
V_46 = F_13 ( V_8 -> V_20 , V_8 -> V_10 -> V_47 , V_39 ) ;
if ( V_46 < 0 )
return V_48 ;
V_45 = V_39 ;
F_24 (n, &status, pctl->data->ngpios)
F_25 ( F_26 ( V_8 -> V_49 . V_50 , V_31 ) ) ;
return V_51 ;
}
static void F_27 ( struct V_29 * V_30 )
{
struct V_7 * V_8 =
F_6 ( F_19 ( V_30 ) ) ;
F_28 ( & V_8 -> V_52 ) ;
}
static void F_29 ( struct V_29 * V_30 )
{
struct V_7 * V_8 =
F_6 ( F_19 ( V_30 ) ) ;
F_13 ( V_8 -> V_20 , V_8 -> V_10 -> V_53 , V_8 -> V_33 . V_34 ) ;
F_13 ( V_8 -> V_20 , V_8 -> V_10 -> V_54 , V_8 -> V_33 . V_35 ) ;
F_30 ( & V_8 -> V_52 ) ;
}
static int F_31 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned long * V_55 )
{
struct V_7 * V_8 = F_32 ( V_2 ) ;
unsigned int V_56 = F_33 ( * V_55 ) ;
int V_19 ;
T_2 V_57 ;
unsigned int V_10 ;
if ( F_4 ( V_8 , V_9 ) ) {
switch ( V_56 ) {
case V_58 :
case V_59 :
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_24 . V_25 . V_26 ,
& V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_56 == V_58 )
V_57 = ( V_10 & 0x1f ) ? 1 : 0 ;
else {
if ( ( V_10 & 0x1f ) == 0x1f )
V_57 = 1 ;
else if ( ( V_10 & 0x1f ) == 0x10 )
V_57 = 0 ;
else
return - V_22 ;
}
break;
default:
return - V_6 ;
}
goto V_60;
}
switch ( V_56 ) {
case V_61 :
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_62 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_19 )
return - V_22 ;
V_57 = 1 ;
break;
case V_63 :
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_64 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_19 )
return - V_22 ;
V_57 = 1 ;
break;
case V_65 :
if ( V_8 -> V_10 -> V_12 != V_13 )
return - V_6 ;
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_24 . V_25 . V_66 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_10 )
return - V_22 ;
V_57 = 1 ;
break;
case V_58 :
if ( V_8 -> V_10 -> V_12 != V_13 )
V_57 = true ;
else {
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_24 . V_25 . V_66 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_10 )
return - V_22 ;
V_57 = 1 ;
}
break;
case V_59 :
V_19 = F_5 ( & V_8 -> V_49 , V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 )
return - V_22 ;
V_19 = F_9 ( & V_8 -> V_49 , V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
V_57 = V_19 ;
break;
default:
return - V_6 ;
}
V_60:
* V_55 = F_34 ( V_56 , V_57 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned long * V_67 , unsigned int V_68 )
{
struct V_7 * V_8 = F_32 ( V_2 ) ;
enum V_69 V_56 ;
T_2 V_57 ;
int V_70 ;
int V_19 ;
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ ) {
V_56 = F_33 ( V_67 [ V_70 ] ) ;
V_57 = F_36 ( V_67 [ V_70 ] ) ;
if ( F_4 ( V_8 , V_9 ) ) {
if ( V_56 == V_59 ) {
V_19 = F_17 ( & V_8 -> V_49 ,
V_9 , V_57 ) ;
if ( V_19 < 0 )
return V_19 ;
continue;
} else
return - V_6 ;
}
switch ( V_56 ) {
case V_71 :
case V_72 :
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_62 ,
F_8 ( V_9 ) , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_64 ,
F_8 ( V_9 ) , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_63 :
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_64 ,
F_8 ( V_9 ) , F_8 ( V_9 ) ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_61 :
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_62 ,
F_8 ( V_9 ) , F_8 ( V_9 ) ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_65 :
if ( V_8 -> V_10 -> V_12 != V_13 ||
F_4 ( V_8 , V_9 ) )
return - V_6 ;
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_24 . V_25 . V_66 ,
F_8 ( V_9 ) , F_8 ( V_9 ) ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_58 :
if ( V_8 -> V_10 -> V_12 != V_13 ||
F_4 ( V_8 , V_9 ) )
return 0 ;
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_24 . V_25 . V_66 ,
F_8 ( V_9 ) , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_59 :
V_19 = F_17 ( & V_8 -> V_49 ,
V_9 , V_57 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
default:
return - V_6 ;
}
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 )
{
int V_46 ;
V_46 = F_38 ( V_8 -> V_73 ,
V_8 -> V_10 -> V_24 . V_25 . V_74 ,
V_75 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_38 ( V_8 -> V_73 ,
V_8 -> V_10 -> V_24 . V_25 . V_74 ,
V_76 ) ;
return V_46 ;
}
static int F_39 ( struct V_7 * V_8 )
{
T_3 V_77 , V_18 ;
switch ( V_8 -> V_10 -> V_12 ) {
case V_13 :
V_77 = V_8 -> V_10 -> V_24 . V_25 . V_78 ;
V_18 = V_79 ;
break;
case V_80 :
V_77 = V_8 -> V_10 -> V_24 . V_81 . V_82 ;
V_18 = 0x00 ;
if ( ! V_77 )
return 0 ;
break;
case V_83 :
V_77 = V_8 -> V_10 -> V_24 . V_84 . V_82 ;
V_18 = 0x00 ;
break;
default:
F_40 ( 1 , L_2 , V_8 -> V_10 -> V_12 ) ;
return - V_22 ;
}
return F_13 ( V_8 -> V_20 , V_77 , V_18 ) ;
}
static int F_41 ( struct V_7 * V_8 )
{
const T_3 V_77 [] = {
[ V_13 ] = V_8 -> V_10 -> V_24 . V_25 . V_85 ,
[ V_80 ] = V_8 -> V_10 -> V_24 . V_81 . V_86 ,
[ V_83 ] = V_8 -> V_10 -> V_24 . V_84 . V_86 ,
} ;
int V_46 ;
if ( V_8 -> V_10 -> V_12 == V_13 &&
F_42 ( V_8 -> V_87 -> V_88 , L_3 ) ) {
V_46 = F_37 ( V_8 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_39 ( V_8 ) ;
if ( V_46 < 0 )
return V_46 ;
return F_13 ( V_8 -> V_20 , V_77 [ V_8 -> V_10 -> V_12 ] , 0 ) ;
}
static int F_43 ( struct V_7 * V_8 ,
unsigned int V_77 )
{
const struct V_89 * V_10 = V_8 -> V_10 ;
if ( V_77 == V_10 -> V_54 ) {
return 2 * V_10 -> V_90 ;
} else if ( ( V_10 -> V_12 == V_13 &&
( V_77 == V_10 -> V_24 . V_25 . V_78 ||
V_77 == V_10 -> V_24 . V_25 . V_26 ||
V_77 == V_10 -> V_24 . V_25 . V_74 ) )
||
( V_10 -> V_12 == V_83 &&
V_77 == V_10 -> V_24 . V_84 . V_82 )
||
( V_10 -> V_12 == V_80 &&
V_10 -> V_24 . V_81 . V_82 &&
V_77 == V_10 -> V_24 . V_81 . V_82 ) ) {
return 8 ;
} else {
return V_10 -> V_90 ;
}
}
static unsigned int F_44 ( struct V_7 * V_8 ,
unsigned int V_77 , unsigned int V_39 )
{
unsigned int V_91 , V_92 ;
const struct V_89 * V_10 = V_8 -> V_10 ;
if ( V_77 == V_10 -> V_54 &&
V_10 -> V_90 == 16 &&
( V_10 -> V_12 == V_83 ||
V_10 -> V_12 == V_80 ) ) {
V_91 = V_39 & 0x00ff0000 ;
V_92 = V_39 & 0x0000ff00 ;
V_39 &= 0xff0000ff ;
V_39 |= V_92 << 8 ;
V_39 |= V_91 >> 8 ;
}
return V_39 ;
}
static int F_45 ( void * V_93 , unsigned int V_77 ,
unsigned int * V_94 )
{
int V_19 , V_31 ;
struct V_7 * V_8 = V_93 ;
struct V_95 * V_96 = V_8 -> V_73 ;
const int V_97 = F_43 ( V_8 , V_77 ) ;
unsigned int V_98 , V_39 ;
for ( V_31 = V_97 , V_39 = 0 , V_98 = V_77 ; V_31 > 0 ; V_31 -= 8 , V_98 ++ ) {
V_39 <<= 8 ;
V_19 = F_46 ( V_96 , V_98 ) ;
if ( V_19 < 0 )
return V_19 ;
V_39 |= V_19 ;
}
* V_94 = F_44 ( V_8 , V_77 , V_39 ) ;
return 0 ;
}
static int F_47 ( void * V_93 , unsigned int V_77 ,
unsigned int V_39 )
{
int V_19 , V_31 ;
struct V_7 * V_8 = V_93 ;
struct V_95 * V_96 = V_8 -> V_73 ;
const int V_97 = F_43 ( V_8 , V_77 ) ;
V_39 = F_44 ( V_8 , V_77 , V_39 ) ;
V_31 = ( V_97 - 1 ) & ~ 7 ;
do {
const T_3 V_99 = ( V_39 >> V_31 ) & 0xff ;
V_19 = F_38 ( V_96 , V_77 , V_99 ) ;
if ( V_19 < 0 )
return V_19 ;
V_77 ++ ;
V_31 -= 8 ;
} while ( V_31 >= 0 );
return 0 ;
}
static bool F_48 ( struct V_100 * V_87 , unsigned int V_77 )
{
struct V_7 * V_8 = F_49 ( F_50 ( V_87 ) ) ;
return V_77 == V_8 -> V_10 -> V_47 || V_77 == V_8 -> V_10 -> V_23 ;
}
static int F_51 ( struct V_95 * V_73 ,
const struct V_101 * V_102 )
{
static const T_2 V_103 = V_104 |
V_105 ;
struct V_100 * V_87 = & V_73 -> V_87 ;
struct V_7 * V_8 ;
int V_19 ;
if ( ! F_52 ( V_73 -> V_106 , V_103 ) )
return - V_107 ;
V_8 = F_53 ( V_87 , sizeof( * V_8 ) , V_108 ) ;
if ( ! V_8 )
return - V_109 ;
F_54 ( V_73 , V_8 ) ;
V_8 -> V_87 = V_87 ;
V_8 -> V_73 = V_73 ;
if ( V_87 -> V_88 )
V_8 -> V_10 = F_55 ( V_87 ) ;
else
V_8 -> V_10 = (struct V_89 * ) V_102 -> V_110 ;
if ( ! V_8 -> V_10 )
return - V_22 ;
V_8 -> V_20 = F_56 ( V_87 , NULL , V_8 ,
& V_111 ) ;
if ( F_57 ( V_8 -> V_20 ) ) {
V_19 = F_58 ( V_8 -> V_20 ) ;
F_59 ( V_87 , L_4 ,
V_19 ) ;
return V_19 ;
}
F_60 ( & V_8 -> V_52 ) ;
V_19 = F_41 ( V_8 ) ;
if ( V_19 )
return V_19 ;
V_8 -> V_49 . V_112 = F_61 ( V_87 , V_73 -> V_14 , V_108 ) ;
V_8 -> V_49 . V_113 = - 1 ;
V_8 -> V_49 . V_114 = V_8 -> V_10 -> V_11 ;
V_8 -> V_49 . V_115 = F_5 ;
V_8 -> V_49 . V_116 = F_16 ;
V_8 -> V_49 . V_117 = F_17 ;
V_8 -> V_49 . V_118 = F_9 ;
V_8 -> V_49 . V_119 = F_14 ;
V_8 -> V_49 . V_120 = V_121 ;
V_8 -> V_49 . V_122 = V_87 ;
#ifdef F_62
V_8 -> V_49 . V_88 = V_87 -> V_88 ;
#endif
V_8 -> V_49 . V_123 = true ;
if ( V_8 -> V_10 -> V_12 != V_13 )
V_8 -> V_49 . V_124 = F_15 ;
V_19 = F_63 ( V_87 , & V_8 -> V_49 , V_8 ) ;
if ( V_19 )
return V_19 ;
if ( V_73 -> V_33 > 0 ) {
V_8 -> V_125 . V_14 = F_61 ( V_87 , V_73 -> V_14 ,
V_108 ) ;
V_8 -> V_125 . V_126 = F_18 ;
V_8 -> V_125 . V_127 = F_20 ;
V_8 -> V_125 . V_128 = F_22 ;
V_8 -> V_125 . V_129 = F_27 ;
V_8 -> V_125 . V_130 = F_29 ;
V_8 -> V_33 . V_34 = ~ 0 ;
V_8 -> V_33 . V_35 = 0 ;
V_19 = F_64 ( & V_8 -> V_49 ,
& V_8 -> V_125 , 0 ,
V_131 , V_132 ) ;
if ( V_19 ) {
F_59 ( V_87 , L_5 ) ;
return V_19 ;
}
V_19 = F_65 ( V_87 , V_73 -> V_33 , NULL ,
F_23 ,
V_133 | V_134 |
V_135 ,
V_8 -> V_125 . V_14 , V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
F_66 ( & V_8 -> V_49 ,
& V_8 -> V_125 ,
V_73 -> V_33 ) ;
}
V_8 -> V_136 . V_14 = L_6 ;
V_8 -> V_136 . V_137 = & V_138 ;
V_8 -> V_136 . V_139 = & V_140 ;
V_8 -> V_136 . V_4 = V_8 -> V_10 -> V_4 ;
V_8 -> V_136 . V_11 = V_8 -> V_10 -> V_11 ;
V_8 -> V_136 . V_141 = V_142 ;
V_8 -> V_2 = F_67 ( & V_8 -> V_136 , V_87 , V_8 ) ;
if ( F_57 ( V_8 -> V_2 ) ) {
F_59 ( V_87 , L_7 ) ;
return F_58 ( V_8 -> V_2 ) ;
}
return 0 ;
}
static int T_4 F_68 ( void )
{
return F_69 ( & V_143 ) ;
}
