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
static int F_10 ( struct V_15 * V_16 ,
unsigned int V_17 ,
enum V_24 V_25 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
int V_19 ;
switch ( V_25 ) {
case V_26 :
if ( V_8 -> V_10 -> V_12 != V_13 ||
F_4 ( V_8 , V_17 ) )
return 0 ;
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_27 . V_28 . V_29 ,
F_8 ( V_17 ) , 0 ) ;
break;
case V_30 :
if ( V_8 -> V_10 -> V_12 != V_13 ||
F_4 ( V_8 , V_17 ) )
return - V_6 ;
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_27 . V_28 . V_29 ,
F_8 ( V_17 ) , F_8 ( V_17 ) ) ;
break;
default:
V_19 = - V_6 ;
break;
}
return V_19 ;
}
static int F_12 ( struct V_7 * V_8 , unsigned int V_17 ,
int V_18 )
{
return F_11 ( V_8 -> V_20 , V_8 -> V_10 -> V_23 ,
F_8 ( V_17 ) , V_18 ? F_8 ( V_17 ) : 0 ) ;
}
static int F_13 ( struct V_7 * V_8 ,
int V_18 )
{
return F_14 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_27 . V_28 . V_31 ,
( V_18 ? 0x1f : 0x10 ) ) ;
}
static void F_15 ( struct V_15 * V_16 , unsigned int V_17 ,
int V_18 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
if ( F_4 ( V_8 , V_17 ) )
F_13 ( V_8 , V_18 ) ;
else
F_12 ( V_8 , V_17 , V_18 ) ;
}
static void F_16 ( struct V_15 * V_16 ,
unsigned long * V_32 ,
unsigned long * V_33 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
F_11 ( V_8 -> V_20 , V_8 -> V_10 -> V_23 , * V_32 , * V_33 ) ;
}
static int F_17 ( struct V_15 * V_16 ,
unsigned int V_17 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
if ( F_4 ( V_8 , V_17 ) )
return - V_22 ;
return F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_21 ,
F_8 ( V_17 ) , F_8 ( V_17 ) ) ;
}
static int F_18 ( struct V_15 * V_16 ,
unsigned int V_17 , int V_18 )
{
struct V_7 * V_8 = F_6 ( V_16 ) ;
int V_19 ;
if ( F_4 ( V_8 , V_17 ) )
return F_13 ( V_8 , V_18 ) ;
V_19 = F_12 ( V_8 , V_17 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_21 ,
F_8 ( V_17 ) , 0 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_7 * V_8 =
F_6 ( F_20 ( V_35 ) ) ;
unsigned int V_36 = V_35 -> V_37 ;
V_8 -> V_38 . V_39 |= F_8 ( V_36 ) ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_7 * V_8 =
F_6 ( F_20 ( V_35 ) ) ;
unsigned int V_36 = V_35 -> V_37 ;
V_8 -> V_38 . V_39 &= ~ F_8 ( V_36 ) ;
}
static void F_22 ( struct V_7 * V_8 ,
unsigned int line , unsigned int V_40 )
{
const unsigned int V_36 = line * 2 ;
const unsigned int V_32 = ~ ( ( V_41 |
V_42 ) << V_36 ) ;
V_8 -> V_38 . V_40 &= V_32 ;
V_8 -> V_38 . V_40 |= V_40 << V_36 ;
}
static int F_23 ( struct V_34 * V_35 , unsigned int V_43 )
{
struct V_7 * V_8 =
F_6 ( F_20 ( V_35 ) ) ;
unsigned int V_36 , V_44 = 0 ;
if ( V_43 & ( V_45 | V_46 ) )
return - V_22 ;
V_36 = V_35 -> V_37 ;
if ( V_43 & V_47 )
V_44 |= V_41 ;
if ( V_43 & V_48 )
V_44 |= V_42 ;
F_22 ( V_8 , V_36 , V_44 ) ;
return 0 ;
}
static T_1 F_24 ( int V_38 , void * V_49 )
{
struct V_7 * V_8 = (struct V_7 * ) V_49 ;
unsigned long V_36 , V_50 ;
unsigned int V_44 ;
int V_51 ;
V_51 = F_7 ( V_8 -> V_20 , V_8 -> V_10 -> V_52 , & V_44 ) ;
if ( V_51 < 0 )
return V_53 ;
V_51 = F_14 ( V_8 -> V_20 , V_8 -> V_10 -> V_52 , V_44 ) ;
if ( V_51 < 0 )
return V_53 ;
V_50 = V_44 ;
F_25 (n, &status, pctl->data->ngpios)
F_26 ( F_27 ( V_8 -> V_54 . V_55 , V_36 ) ) ;
return V_56 ;
}
static void F_28 ( struct V_34 * V_35 )
{
struct V_7 * V_8 =
F_6 ( F_20 ( V_35 ) ) ;
F_29 ( & V_8 -> V_57 ) ;
}
static void F_30 ( struct V_34 * V_35 )
{
struct V_7 * V_8 =
F_6 ( F_20 ( V_35 ) ) ;
F_14 ( V_8 -> V_20 , V_8 -> V_10 -> V_58 , V_8 -> V_38 . V_39 ) ;
F_14 ( V_8 -> V_20 , V_8 -> V_10 -> V_59 , V_8 -> V_38 . V_40 ) ;
F_31 ( & V_8 -> V_57 ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned long * V_60 )
{
struct V_7 * V_8 = F_33 ( V_2 ) ;
unsigned int V_61 = F_34 ( * V_60 ) ;
int V_19 ;
T_2 V_62 ;
unsigned int V_10 ;
if ( F_4 ( V_8 , V_9 ) ) {
switch ( V_61 ) {
case V_63 :
case V_64 :
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_27 . V_28 . V_31 ,
& V_10 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_61 == V_63 )
V_62 = ( V_10 & 0x1f ) ? 1 : 0 ;
else {
if ( ( V_10 & 0x1f ) == 0x1f )
V_62 = 1 ;
else if ( ( V_10 & 0x1f ) == 0x10 )
V_62 = 0 ;
else
return - V_22 ;
}
break;
default:
return - V_6 ;
}
goto V_65;
}
switch ( V_61 ) {
case V_66 :
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_67 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_19 )
return - V_22 ;
V_62 = 1 ;
break;
case V_68 :
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_69 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_19 )
return - V_22 ;
V_62 = 1 ;
break;
case V_70 :
if ( V_8 -> V_10 -> V_12 != V_13 )
return - V_6 ;
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_27 . V_28 . V_29 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! V_10 )
return - V_22 ;
V_62 = 1 ;
break;
case V_63 :
if ( V_8 -> V_10 -> V_12 != V_13 )
V_62 = true ;
else {
V_19 = F_7 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_27 . V_28 . V_29 ,
& V_10 ) ;
V_10 &= F_8 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_10 )
return - V_22 ;
V_62 = 1 ;
}
break;
case V_64 :
V_19 = F_5 ( & V_8 -> V_54 , V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 )
return - V_22 ;
V_19 = F_9 ( & V_8 -> V_54 , V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
V_62 = V_19 ;
break;
default:
return - V_6 ;
}
V_65:
* V_60 = F_35 ( V_61 , V_62 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned long * V_71 , unsigned int V_72 )
{
struct V_7 * V_8 = F_33 ( V_2 ) ;
enum V_73 V_61 ;
T_2 V_62 ;
int V_74 ;
int V_19 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_61 = F_34 ( V_71 [ V_74 ] ) ;
V_62 = F_37 ( V_71 [ V_74 ] ) ;
if ( F_4 ( V_8 , V_9 ) ) {
if ( V_61 == V_64 ) {
V_19 = F_18 ( & V_8 -> V_54 ,
V_9 , V_62 ) ;
if ( V_19 < 0 )
return V_19 ;
continue;
} else
return - V_6 ;
}
switch ( V_61 ) {
case V_75 :
case V_76 :
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_67 ,
F_8 ( V_9 ) , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_69 ,
F_8 ( V_9 ) , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_68 :
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_69 ,
F_8 ( V_9 ) , F_8 ( V_9 ) ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_66 :
V_19 = F_11 ( V_8 -> V_20 ,
V_8 -> V_10 -> V_67 ,
F_8 ( V_9 ) , F_8 ( V_9 ) ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_70 :
V_19 = F_10 ( & V_8 -> V_54 ,
V_9 , V_30 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_63 :
V_19 = F_10 ( & V_8 -> V_54 ,
V_9 , V_26 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_64 :
V_19 = F_18 ( & V_8 -> V_54 ,
V_9 , V_62 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
default:
return - V_6 ;
}
}
return 0 ;
}
static int F_38 ( struct V_7 * V_8 )
{
int V_51 ;
V_51 = F_39 ( V_8 -> V_77 ,
V_8 -> V_10 -> V_27 . V_28 . V_78 ,
V_79 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_39 ( V_8 -> V_77 ,
V_8 -> V_10 -> V_27 . V_28 . V_78 ,
V_80 ) ;
return V_51 ;
}
static int F_40 ( struct V_7 * V_8 )
{
T_3 V_81 , V_18 ;
switch ( V_8 -> V_10 -> V_12 ) {
case V_13 :
V_81 = V_8 -> V_10 -> V_27 . V_28 . V_82 ;
V_18 = V_83 ;
break;
case V_84 :
V_81 = V_8 -> V_10 -> V_27 . V_85 . V_86 ;
V_18 = 0x00 ;
if ( ! V_81 )
return 0 ;
break;
case V_87 :
V_81 = V_8 -> V_10 -> V_27 . V_88 . V_86 ;
V_18 = 0x00 ;
break;
default:
F_41 ( 1 , L_2 , V_8 -> V_10 -> V_12 ) ;
return - V_22 ;
}
return F_14 ( V_8 -> V_20 , V_81 , V_18 ) ;
}
static int F_42 ( struct V_7 * V_8 )
{
const T_3 V_81 [] = {
[ V_13 ] = V_8 -> V_10 -> V_27 . V_28 . V_89 ,
[ V_84 ] = V_8 -> V_10 -> V_27 . V_85 . V_90 ,
[ V_87 ] = V_8 -> V_10 -> V_27 . V_88 . V_90 ,
} ;
int V_51 ;
if ( V_8 -> V_10 -> V_12 == V_13 &&
F_43 ( V_8 -> V_91 -> V_92 , L_3 ) ) {
V_51 = F_38 ( V_8 ) ;
if ( V_51 < 0 )
return V_51 ;
}
V_51 = F_40 ( V_8 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_14 ( V_8 -> V_20 , V_81 [ V_8 -> V_10 -> V_12 ] , 0 ) ;
}
static int F_44 ( struct V_7 * V_8 ,
unsigned int V_81 )
{
const struct V_93 * V_10 = V_8 -> V_10 ;
if ( V_81 == V_10 -> V_59 ) {
return 2 * V_10 -> V_94 ;
} else if ( ( V_10 -> V_12 == V_13 &&
( V_81 == V_10 -> V_27 . V_28 . V_82 ||
V_81 == V_10 -> V_27 . V_28 . V_31 ||
V_81 == V_10 -> V_27 . V_28 . V_78 ) )
||
( V_10 -> V_12 == V_87 &&
V_81 == V_10 -> V_27 . V_88 . V_86 )
||
( V_10 -> V_12 == V_84 &&
V_10 -> V_27 . V_85 . V_86 &&
V_81 == V_10 -> V_27 . V_85 . V_86 ) ) {
return 8 ;
} else {
return V_10 -> V_94 ;
}
}
static unsigned int F_45 ( struct V_7 * V_8 ,
unsigned int V_81 , unsigned int V_44 )
{
unsigned int V_95 , V_96 ;
const struct V_93 * V_10 = V_8 -> V_10 ;
if ( V_81 == V_10 -> V_59 &&
V_10 -> V_94 == 16 &&
( V_10 -> V_12 == V_87 ||
V_10 -> V_12 == V_84 ) ) {
V_95 = V_44 & 0x00ff0000 ;
V_96 = V_44 & 0x0000ff00 ;
V_44 &= 0xff0000ff ;
V_44 |= V_96 << 8 ;
V_44 |= V_95 >> 8 ;
}
return V_44 ;
}
static int F_46 ( void * V_97 , unsigned int V_81 ,
unsigned int * V_98 )
{
int V_19 , V_36 ;
struct V_7 * V_8 = V_97 ;
struct V_99 * V_100 = V_8 -> V_77 ;
const int V_101 = F_44 ( V_8 , V_81 ) ;
unsigned int V_102 , V_44 ;
for ( V_36 = V_101 , V_44 = 0 , V_102 = V_81 ; V_36 > 0 ; V_36 -= 8 , V_102 ++ ) {
V_44 <<= 8 ;
V_19 = F_47 ( V_100 , V_102 ) ;
if ( V_19 < 0 )
return V_19 ;
V_44 |= V_19 ;
}
* V_98 = F_45 ( V_8 , V_81 , V_44 ) ;
return 0 ;
}
static int F_48 ( void * V_97 , unsigned int V_81 ,
unsigned int V_44 )
{
int V_19 , V_36 ;
struct V_7 * V_8 = V_97 ;
struct V_99 * V_100 = V_8 -> V_77 ;
const int V_101 = F_44 ( V_8 , V_81 ) ;
V_44 = F_45 ( V_8 , V_81 , V_44 ) ;
V_36 = ( V_101 - 1 ) & ~ 7 ;
do {
const T_3 V_103 = ( V_44 >> V_36 ) & 0xff ;
V_19 = F_39 ( V_100 , V_81 , V_103 ) ;
if ( V_19 < 0 )
return V_19 ;
V_81 ++ ;
V_36 -= 8 ;
} while ( V_36 >= 0 );
return 0 ;
}
static bool F_49 ( struct V_104 * V_91 , unsigned int V_81 )
{
struct V_7 * V_8 = F_50 ( F_51 ( V_91 ) ) ;
return V_81 == V_8 -> V_10 -> V_52 || V_81 == V_8 -> V_10 -> V_23 ;
}
static int F_52 ( struct V_99 * V_77 ,
const struct V_105 * V_106 )
{
static const T_2 V_107 = V_108 |
V_109 ;
struct V_104 * V_91 = & V_77 -> V_91 ;
struct V_7 * V_8 ;
int V_19 ;
if ( ! F_53 ( V_77 -> V_110 , V_107 ) )
return - V_111 ;
V_8 = F_54 ( V_91 , sizeof( * V_8 ) , V_112 ) ;
if ( ! V_8 )
return - V_113 ;
F_55 ( V_77 , V_8 ) ;
V_8 -> V_91 = V_91 ;
V_8 -> V_77 = V_77 ;
if ( V_91 -> V_92 )
V_8 -> V_10 = F_56 ( V_91 ) ;
else
V_8 -> V_10 = (struct V_93 * ) V_106 -> V_114 ;
if ( ! V_8 -> V_10 )
return - V_22 ;
V_8 -> V_20 = F_57 ( V_91 , NULL , V_8 ,
& V_115 ) ;
if ( F_58 ( V_8 -> V_20 ) ) {
V_19 = F_59 ( V_8 -> V_20 ) ;
F_60 ( V_91 , L_4 ,
V_19 ) ;
return V_19 ;
}
F_61 ( & V_8 -> V_57 ) ;
V_19 = F_42 ( V_8 ) ;
if ( V_19 )
return V_19 ;
V_8 -> V_54 . V_116 = F_62 ( V_91 , V_77 -> V_14 , V_112 ) ;
V_8 -> V_54 . V_117 = - 1 ;
V_8 -> V_54 . V_118 = V_8 -> V_10 -> V_11 ;
V_8 -> V_54 . V_119 = F_5 ;
V_8 -> V_54 . V_120 = F_17 ;
V_8 -> V_54 . V_121 = F_18 ;
V_8 -> V_54 . V_122 = F_9 ;
V_8 -> V_54 . V_123 = F_15 ;
V_8 -> V_54 . V_124 = F_10 ;
V_8 -> V_54 . V_125 = V_91 ;
#ifdef F_63
V_8 -> V_54 . V_92 = V_91 -> V_92 ;
#endif
V_8 -> V_54 . V_126 = true ;
if ( V_8 -> V_10 -> V_12 != V_13 )
V_8 -> V_54 . V_127 = F_16 ;
V_19 = F_64 ( V_91 , & V_8 -> V_54 , V_8 ) ;
if ( V_19 )
return V_19 ;
if ( V_77 -> V_38 > 0 ) {
V_8 -> V_128 . V_14 = F_62 ( V_91 , V_77 -> V_14 ,
V_112 ) ;
V_8 -> V_128 . V_129 = F_19 ;
V_8 -> V_128 . V_130 = F_21 ;
V_8 -> V_128 . V_131 = F_23 ;
V_8 -> V_128 . V_132 = F_28 ;
V_8 -> V_128 . V_133 = F_30 ;
V_8 -> V_38 . V_39 = ~ 0 ;
V_8 -> V_38 . V_40 = 0 ;
V_19 = F_65 ( & V_8 -> V_54 ,
& V_8 -> V_128 , 0 ,
V_134 , V_135 ) ;
if ( V_19 ) {
F_60 ( V_91 , L_5 ) ;
return V_19 ;
}
V_19 = F_66 ( V_91 , V_77 -> V_38 , NULL ,
F_24 ,
V_136 | V_137 |
V_138 ,
V_8 -> V_128 . V_14 , V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
F_67 ( & V_8 -> V_54 ,
& V_8 -> V_128 ,
V_77 -> V_38 ) ;
}
V_8 -> V_139 . V_14 = L_6 ;
V_8 -> V_139 . V_140 = & V_141 ;
V_8 -> V_139 . V_142 = & V_143 ;
V_8 -> V_139 . V_4 = V_8 -> V_10 -> V_4 ;
V_8 -> V_139 . V_11 = V_8 -> V_10 -> V_11 ;
V_8 -> V_139 . V_144 = V_145 ;
V_8 -> V_2 = F_68 ( & V_8 -> V_139 , V_91 , V_8 ) ;
if ( F_58 ( V_8 -> V_2 ) ) {
F_60 ( V_91 , L_7 ) ;
return F_59 ( V_8 -> V_2 ) ;
}
return 0 ;
}
static int T_4 F_69 ( void )
{
return F_70 ( & V_146 ) ;
}
