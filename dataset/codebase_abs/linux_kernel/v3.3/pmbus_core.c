int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = 0 ;
int V_7 ;
if ( V_3 != V_5 -> V_8 ) {
V_6 = F_3 ( V_2 , V_9 , V_3 ) ;
V_7 = F_4 ( V_2 , V_9 ) ;
if ( V_7 != V_3 )
V_6 = - V_10 ;
else
V_5 -> V_8 = V_3 ;
}
return V_6 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_11 )
{
int V_6 ;
if ( V_3 >= 0 ) {
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return F_6 ( V_2 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_14 ;
if ( V_13 -> V_15 ) {
V_14 = V_13 -> V_15 ( V_2 , V_3 , V_11 ) ;
if ( V_14 != - V_16 )
return V_14 ;
}
return F_5 ( V_2 , V_3 , V_11 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_2 V_18 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_9 ( V_2 , V_17 , V_18 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_17 ,
T_2 V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_14 ;
if ( V_13 -> V_19 ) {
V_14 = V_13 -> V_19 ( V_2 , V_3 , V_17 , V_18 ) ;
if ( V_14 != - V_16 )
return V_14 ;
}
if ( V_17 >= V_20 )
return - V_21 ;
return F_8 ( V_2 , V_3 , V_17 , V_18 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_2 , V_17 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_14 ;
if ( V_13 -> V_22 ) {
V_14 = V_13 -> V_22 ( V_2 , V_3 , V_17 ) ;
if ( V_14 != - V_16 )
return V_14 ;
}
if ( V_17 >= V_20 )
return - V_21 ;
return F_11 ( V_2 , V_3 , V_17 ) ;
}
int F_14 ( struct V_1 * V_2 , int V_3 , T_1 V_17 )
{
int V_6 ;
if ( V_3 >= 0 ) {
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return F_4 ( V_2 , V_17 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_14 ;
if ( V_13 -> V_23 ) {
V_14 = V_13 -> V_23 ( V_2 , V_3 , V_17 ) ;
if ( V_14 != - V_16 )
return V_14 ;
}
return F_14 ( V_2 , V_3 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 )
{
F_7 ( V_2 , V_3 , V_24 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_13 -> V_26 ; V_25 ++ )
F_16 ( V_2 , V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_14 , V_27 ;
V_14 = F_15 ( V_2 , - 1 , V_28 ) ;
if ( V_14 < 0 || ( V_14 & V_29 ) ) {
V_27 = F_15 ( V_2 , - 1 , V_30 ) ;
if ( V_27 < 0 || ( V_27 & V_31 ) )
return - V_10 ;
}
return 0 ;
}
bool F_19 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
int V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_15 ( V_2 , V_3 , V_17 ) ;
if ( V_6 >= 0 && ! ( V_5 -> V_32 & V_33 ) )
V_6 = F_18 ( V_2 ) ;
F_16 ( V_2 , - 1 ) ;
return V_6 >= 0 ;
}
bool F_20 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
int V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_13 ( V_2 , V_3 , V_17 ) ;
if ( V_6 >= 0 && ! ( V_5 -> V_32 & V_33 ) )
V_6 = F_18 ( V_2 ) ;
F_16 ( V_2 , - 1 ) ;
return V_6 >= 0 ;
}
const struct V_12 * F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_13 ;
}
static struct V_4 * F_22 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_23 ( V_35 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_5 -> V_13 ;
F_24 ( & V_5 -> V_36 ) ;
if ( F_25 ( V_37 , V_5 -> V_38 + V_39 ) || ! V_5 -> V_40 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_13 -> V_26 ; V_25 ++ )
V_5 -> V_14 [ V_41 + V_25 ]
= F_15 ( V_2 , V_25 ,
V_28 ) ;
for ( V_25 = 0 ; V_25 < V_13 -> V_26 ; V_25 ++ ) {
if ( ! ( V_13 -> V_42 [ V_25 ] & V_43 ) )
continue;
V_5 -> V_14 [ V_44 + V_25 ]
= F_15 ( V_2 , V_25 , V_45 ) ;
}
for ( V_25 = 0 ; V_25 < V_13 -> V_26 ; V_25 ++ ) {
if ( ! ( V_13 -> V_42 [ V_25 ] & V_46 ) )
continue;
V_5 -> V_14 [ V_47 + V_25 ]
= F_15 ( V_2 , V_25 , V_48 ) ;
}
for ( V_25 = 0 ; V_25 < V_13 -> V_26 ; V_25 ++ ) {
if ( ! ( V_13 -> V_42 [ V_25 ] & V_49 ) )
continue;
V_5 -> V_14 [ V_50 + V_25 ]
= F_15 ( V_2 , V_25 ,
V_51 ) ;
}
for ( V_25 = 0 ; V_25 < V_13 -> V_26 ; V_25 ++ ) {
if ( ! ( V_13 -> V_42 [ V_25 ] & V_52 ) )
continue;
V_5 -> V_14 [ V_53 + V_25 ]
= F_15 ( V_2 , V_25 ,
V_54 ) ;
}
for ( V_25 = 0 ; V_25 < V_13 -> V_26 ; V_25 ++ ) {
if ( ! ( V_13 -> V_42 [ V_25 ] & V_55 ) )
continue;
V_5 -> V_14 [ V_56 + V_25 ]
= F_15 ( V_2 , V_25 ,
V_57 ) ;
}
if ( V_13 -> V_42 [ 0 ] & V_58 )
V_5 -> V_14 [ V_59 ]
= F_15 ( V_2 , 0 ,
V_60 ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_61 ; V_25 ++ ) {
struct V_62 * V_63 = & V_5 -> V_64 [ V_25 ] ;
if ( ! V_5 -> V_40 || V_63 -> V_65 )
V_63 -> V_5
= F_13 ( V_2 ,
V_63 -> V_3 ,
V_63 -> V_17 ) ;
}
F_17 ( V_2 ) ;
V_5 -> V_38 = V_37 ;
V_5 -> V_40 = 1 ;
}
F_26 ( & V_5 -> V_36 ) ;
return V_5 ;
}
static long F_27 ( struct V_4 * V_5 ,
struct V_62 * V_63 )
{
T_3 V_66 ;
T_4 V_67 ;
long V_68 ;
if ( V_63 -> V_69 == V_70 ) {
V_66 = V_5 -> V_66 ;
V_67 = ( T_2 ) V_63 -> V_5 ;
} else {
V_66 = ( ( T_3 ) V_63 -> V_5 ) >> 11 ;
V_67 = ( ( T_3 ) ( ( V_63 -> V_5 & 0x7ff ) << 5 ) ) >> 5 ;
}
V_68 = V_67 ;
if ( V_63 -> V_69 != V_71 )
V_68 = V_68 * 1000L ;
if ( V_63 -> V_69 == V_72 )
V_68 = V_68 * 1000L ;
if ( V_66 >= 0 )
V_68 <<= V_66 ;
else
V_68 >>= - V_66 ;
return V_68 ;
}
static long F_28 ( struct V_4 * V_5 ,
struct V_62 * V_63 )
{
long V_68 = ( T_3 ) V_63 -> V_5 ;
long V_73 , V_74 , V_75 ;
V_73 = V_5 -> V_13 -> V_73 [ V_63 -> V_69 ] ;
V_74 = V_5 -> V_13 -> V_74 [ V_63 -> V_69 ] ;
V_75 = V_5 -> V_13 -> V_75 [ V_63 -> V_69 ] ;
if ( V_73 == 0 )
return 0 ;
V_75 = - V_75 ;
if ( V_63 -> V_69 != V_71 ) {
V_75 += 3 ;
V_74 *= 1000 ;
}
if ( V_63 -> V_69 == V_72 ) {
V_75 += 3 ;
V_74 *= 1000 ;
}
while ( V_75 > 0 ) {
V_68 *= 10 ;
V_75 -- ;
}
while ( V_75 < 0 ) {
V_68 = F_29 ( V_68 , 10 ) ;
V_75 ++ ;
}
return ( V_68 - V_74 ) / V_73 ;
}
static long F_30 ( struct V_4 * V_5 ,
struct V_62 * V_63 )
{
long V_68 = V_63 -> V_5 ;
if ( V_68 < 0x02 || V_68 > 0xb2 )
return 0 ;
return F_29 ( 160000 - ( V_68 - 2 ) * 625 , 100 ) ;
}
static long F_31 ( struct V_4 * V_5 , struct V_62 * V_63 )
{
long V_68 ;
switch ( V_5 -> V_13 -> V_76 [ V_63 -> V_69 ] ) {
case V_77 :
V_68 = F_28 ( V_5 , V_63 ) ;
break;
case V_78 :
V_68 = F_30 ( V_5 , V_63 ) ;
break;
case V_79 :
default:
V_68 = F_27 ( V_5 , V_63 ) ;
break;
}
return V_68 ;
}
static T_2 F_32 ( struct V_4 * V_5 ,
enum V_80 V_69 , long V_68 )
{
T_3 V_66 = 0 , V_67 ;
bool V_81 = false ;
if ( V_68 == 0 )
return 0 ;
if ( V_69 == V_70 ) {
if ( V_68 < 0 )
return 0 ;
if ( V_5 -> V_66 < 0 )
V_68 <<= - V_5 -> V_66 ;
else
V_68 >>= V_5 -> V_66 ;
V_68 = F_29 ( V_68 , 1000 ) ;
return V_68 & 0xffff ;
}
if ( V_68 < 0 ) {
V_81 = true ;
V_68 = - V_68 ;
}
if ( V_69 == V_72 )
V_68 = F_29 ( V_68 , 1000L ) ;
if ( V_69 == V_71 )
V_68 = V_68 * 1000 ;
while ( V_68 >= V_82 && V_66 < 15 ) {
V_66 ++ ;
V_68 >>= 1 ;
}
while ( V_68 < V_83 && V_66 > - 15 ) {
V_66 -- ;
V_68 <<= 1 ;
}
V_67 = F_29 ( V_68 , 1000 ) ;
if ( V_67 > 0x3ff )
V_67 = 0x3ff ;
if ( V_81 )
V_67 = - V_67 ;
return ( V_67 & 0x7ff ) | ( ( V_66 << 11 ) & 0xf800 ) ;
}
static T_2 F_33 ( struct V_4 * V_5 ,
enum V_80 V_69 , long V_68 )
{
long V_73 , V_74 , V_75 ;
V_73 = V_5 -> V_13 -> V_73 [ V_69 ] ;
V_74 = V_5 -> V_13 -> V_74 [ V_69 ] ;
V_75 = V_5 -> V_13 -> V_75 [ V_69 ] ;
if ( V_69 == V_72 ) {
V_75 -= 3 ;
V_74 *= 1000 ;
}
if ( V_69 != V_71 ) {
V_75 -= 3 ;
V_74 *= 1000 ;
}
V_68 = V_68 * V_73 + V_74 ;
while ( V_75 > 0 ) {
V_68 *= 10 ;
V_75 -- ;
}
while ( V_75 < 0 ) {
V_68 = F_29 ( V_68 , 10 ) ;
V_75 ++ ;
}
return V_68 ;
}
static T_2 F_34 ( struct V_4 * V_5 ,
enum V_80 V_69 , long V_68 )
{
V_68 = F_35 ( V_68 , 500 , 1600 ) ;
return 2 + F_29 ( ( 1600 - V_68 ) * 100 , 625 ) ;
}
static T_2 F_36 ( struct V_4 * V_5 ,
enum V_80 V_69 , long V_68 )
{
T_2 V_84 ;
switch ( V_5 -> V_13 -> V_76 [ V_69 ] ) {
case V_77 :
V_84 = F_33 ( V_5 , V_69 , V_68 ) ;
break;
case V_78 :
V_84 = F_34 ( V_5 , V_69 , V_68 ) ;
break;
case V_79 :
default:
V_84 = F_32 ( V_5 , V_69 , V_68 ) ;
break;
}
return V_84 ;
}
static int F_37 ( struct V_4 * V_5 , int V_85 , int * V_68 )
{
T_1 V_86 = ( V_85 >> 24 ) & 0xff ;
T_1 V_87 = ( V_85 >> 16 ) & 0xff ;
T_1 V_17 = ( V_85 >> 8 ) & 0xff ;
T_1 V_88 = V_85 & 0xff ;
int V_14 ;
T_1 V_84 ;
V_14 = V_5 -> V_14 [ V_17 ] ;
if ( V_14 < 0 )
return V_14 ;
V_84 = V_14 & V_88 ;
if ( ! V_86 && ! V_87 )
* V_68 = ! ! V_84 ;
else {
long V_89 , V_90 ;
struct V_62 * V_91 , * V_92 ;
V_91 = & V_5 -> V_64 [ V_86 ] ;
if ( V_91 -> V_5 < 0 )
return V_91 -> V_5 ;
V_92 = & V_5 -> V_64 [ V_87 ] ;
if ( V_92 -> V_5 < 0 )
return V_92 -> V_5 ;
V_89 = F_31 ( V_5 , V_91 ) ;
V_90 = F_31 ( V_5 , V_92 ) ;
* V_68 = ! ! ( V_84 && V_89 >= V_90 ) ;
}
return 0 ;
}
static T_5 F_38 ( struct V_34 * V_35 ,
struct V_93 * V_94 , char * V_95 )
{
struct V_96 * V_97 = F_39 ( V_94 ) ;
struct V_4 * V_5 = F_22 ( V_35 ) ;
int V_68 ;
int V_98 ;
V_98 = F_37 ( V_5 , V_97 -> V_85 , & V_68 ) ;
if ( V_98 )
return V_98 ;
return snprintf ( V_95 , V_99 , L_1 , V_68 ) ;
}
static T_5 F_40 ( struct V_34 * V_35 ,
struct V_93 * V_94 , char * V_95 )
{
struct V_96 * V_97 = F_39 ( V_94 ) ;
struct V_4 * V_5 = F_22 ( V_35 ) ;
struct V_62 * V_63 ;
V_63 = & V_5 -> V_64 [ V_97 -> V_85 ] ;
if ( V_63 -> V_5 < 0 )
return V_63 -> V_5 ;
return snprintf ( V_95 , V_99 , L_2 , F_31 ( V_5 , V_63 ) ) ;
}
static T_5 F_41 ( struct V_34 * V_35 ,
struct V_93 * V_100 ,
const char * V_95 , T_6 V_101 )
{
struct V_96 * V_97 = F_39 ( V_100 ) ;
struct V_1 * V_2 = F_23 ( V_35 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_62 * V_63 = & V_5 -> V_64 [ V_97 -> V_85 ] ;
T_5 V_6 = V_101 ;
long V_68 = 0 ;
int V_102 ;
T_2 V_84 ;
if ( F_42 ( V_95 , 10 , & V_68 ) < 0 )
return - V_103 ;
F_24 ( & V_5 -> V_36 ) ;
V_84 = F_36 ( V_5 , V_63 -> V_69 , V_68 ) ;
V_102 = F_10 ( V_2 , V_63 -> V_3 , V_63 -> V_17 , V_84 ) ;
if ( V_102 < 0 )
V_6 = V_102 ;
else
V_5 -> V_64 [ V_97 -> V_85 ] . V_5 = V_84 ;
F_26 ( & V_5 -> V_36 ) ;
return V_6 ;
}
static T_5 F_43 ( struct V_34 * V_35 ,
struct V_93 * V_94 , char * V_95 )
{
struct V_1 * V_2 = F_23 ( V_35 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_96 * V_97 = F_39 ( V_94 ) ;
return snprintf ( V_95 , V_99 , L_3 ,
V_5 -> V_104 [ V_97 -> V_85 ] . V_105 ) ;
}
static void F_44 ( struct V_4 * V_5 ,
const char * V_106 , const char * type , int V_107 ,
int V_108 )
{
struct V_109 * boolean ;
F_45 ( V_5 -> V_110 >= V_5 -> V_111 ) ;
boolean = & V_5 -> V_112 [ V_5 -> V_110 ] ;
snprintf ( boolean -> V_106 , sizeof( boolean -> V_106 ) , L_4 ,
V_106 , V_107 , type ) ;
F_46 ( V_5 , boolean -> V_106 , boolean , V_108 ) ;
V_5 -> V_110 ++ ;
}
static void F_47 ( struct V_4 * V_5 ,
const char * V_106 , const char * type ,
int V_107 , int V_17 , int V_113 )
{
F_44 ( V_5 , V_106 , type , V_107 , ( V_17 << 8 ) | V_113 ) ;
}
static void F_48 ( struct V_4 * V_5 ,
const char * V_106 , const char * type ,
int V_107 , int V_114 , int V_115 , int V_17 , int V_88 )
{
F_44 ( V_5 , V_106 , type , V_107 ,
( V_114 << 24 ) | ( V_115 << 16 ) | ( V_17 << 8 ) | V_88 ) ;
}
static void F_49 ( struct V_4 * V_5 ,
const char * V_106 , const char * type , int V_107 ,
int V_3 , int V_17 , enum V_80 V_69 ,
bool V_65 , bool V_116 )
{
struct V_62 * V_63 ;
F_45 ( V_5 -> V_61 >= V_5 -> V_117 ) ;
V_63 = & V_5 -> V_64 [ V_5 -> V_61 ] ;
snprintf ( V_63 -> V_106 , sizeof( V_63 -> V_106 ) , L_4 ,
V_106 , V_107 , type ) ;
V_63 -> V_3 = V_3 ;
V_63 -> V_17 = V_17 ;
V_63 -> V_69 = V_69 ;
V_63 -> V_65 = V_65 ;
if ( V_116 )
F_46 ( V_5 , V_63 -> V_106 , V_63 ,
V_5 -> V_61 ) ;
else
F_50 ( V_5 , V_63 -> V_106 , V_63 ,
V_5 -> V_61 ) ;
V_5 -> V_61 ++ ;
}
static void F_51 ( struct V_4 * V_5 ,
const char * V_106 , int V_107 ,
const char * V_118 , int V_85 )
{
struct V_119 * V_105 ;
F_45 ( V_5 -> V_120 >= V_5 -> V_121 ) ;
V_105 = & V_5 -> V_104 [ V_5 -> V_120 ] ;
snprintf ( V_105 -> V_106 , sizeof( V_105 -> V_106 ) , L_5 , V_106 , V_107 ) ;
if ( ! V_85 )
strncpy ( V_105 -> V_105 , V_118 , sizeof( V_105 -> V_105 ) - 1 ) ;
else
snprintf ( V_105 -> V_105 , sizeof( V_105 -> V_105 ) , L_6 , V_118 ,
V_85 ) ;
F_46 ( V_5 , V_105 -> V_106 , V_105 , V_5 -> V_120 ) ;
V_5 -> V_120 ++ ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_3 , V_117 , V_111 , V_121 ;
V_117 = V_122 ;
V_111 = V_123 ;
V_121 = V_124 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_26 ; V_3 ++ ) {
if ( V_13 -> V_42 [ V_3 ] & V_125 ) {
V_117 += V_126 ;
V_111 += V_127 ;
V_121 ++ ;
}
if ( V_13 -> V_42 [ V_3 ] & V_128 ) {
V_117 += V_129 ;
V_111 += V_130 ;
V_121 ++ ;
}
if ( V_13 -> V_42 [ V_3 ] & V_131 ) {
V_117 += V_132 ;
V_111 += V_133 ;
V_121 ++ ;
}
if ( V_13 -> V_42 [ V_3 ] & V_134 ) {
V_117 += 2 * V_135 ;
V_111 += 2 * V_136 ;
}
if ( V_13 -> V_42 [ V_3 ] & V_137 ) {
V_117 += 2 * V_135 ;
V_111 += 2 * V_136 ;
}
if ( V_13 -> V_42 [ V_3 ] & V_138 ) {
V_117 += V_139 ;
V_111 += V_140 ;
}
if ( V_13 -> V_42 [ V_3 ] & V_141 ) {
V_117 += V_139 ;
V_111 += V_140 ;
}
if ( V_13 -> V_42 [ V_3 ] & V_142 ) {
V_117 += V_139 ;
V_111 += V_140 ;
}
}
V_5 -> V_117 = V_117 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_121 = V_121 ;
V_5 -> V_143 = V_117 + V_111 + V_121 ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_12 * V_13 ,
const char * V_106 , int V_85 , int V_3 ,
int V_144 ,
const struct V_145 * V_97 )
{
const struct V_146 * V_147 = V_97 -> V_148 ;
int V_149 = V_97 -> V_149 ;
bool V_150 = false ;
int V_25 , V_151 ;
for ( V_25 = 0 ; V_25 < V_149 ; V_25 ++ ) {
if ( F_20 ( V_2 , V_3 , V_147 -> V_17 ) ) {
V_151 = V_5 -> V_61 ;
F_49 ( V_5 , V_106 , V_147 -> V_97 , V_85 , V_3 ,
V_147 -> V_17 , V_97 -> V_69 ,
V_97 -> V_65 || V_147 -> V_65 ,
false ) ;
if ( V_147 -> V_152 && ( V_13 -> V_42 [ V_3 ] & V_97 -> V_153 ) ) {
if ( V_97 -> V_154 ) {
F_48 ( V_5 , V_106 ,
V_147 -> V_155 , V_85 ,
V_147 -> V_156 ? V_151 : V_144 ,
V_147 -> V_156 ? V_144 : V_151 ,
V_97 -> V_157 + V_3 , V_147 -> V_152 ) ;
} else {
F_47 ( V_5 , V_106 ,
V_147 -> V_155 , V_85 ,
V_97 -> V_157 + V_3 , V_147 -> V_152 ) ;
}
V_150 = true ;
}
}
V_147 ++ ;
}
return V_150 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_12 * V_13 ,
const char * V_106 ,
int V_85 , int V_3 ,
const struct V_145 * V_97 )
{
bool V_150 ;
int V_144 = V_5 -> V_61 ;
if ( V_97 -> V_105 )
F_51 ( V_5 , V_106 , V_85 , V_97 -> V_105 ,
V_97 -> V_158 ? V_3 + 1 : 0 ) ;
F_49 ( V_5 , V_106 , L_7 , V_85 , V_3 , V_97 -> V_17 ,
V_97 -> V_69 , true , true ) ;
if ( V_97 -> V_153 ) {
V_150 = F_53 ( V_2 , V_5 , V_13 , V_106 ,
V_85 , V_3 , V_144 , V_97 ) ;
if ( ! V_150 && V_97 -> V_159 &&
F_19 ( V_2 , V_3 , V_28 ) )
F_47 ( V_5 , V_106 , L_8 , V_85 ,
V_41 + V_3 ,
V_97 -> V_159 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const char * V_106 ,
const struct V_145 * V_160 ,
int V_161 )
{
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_85 , V_25 ;
V_85 = 1 ;
for ( V_25 = 0 ; V_25 < V_161 ; V_25 ++ ) {
int V_3 , V_26 ;
V_26 = V_160 -> V_158 ? V_13 -> V_26 : 1 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
if ( ! ( V_13 -> V_42 [ V_3 ] & V_160 -> V_42 ) )
continue;
F_54 ( V_2 , V_5 , V_13 , V_106 ,
V_85 , V_3 , V_160 ) ;
V_85 ++ ;
}
V_160 ++ ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_85 = 1 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_26 ; V_3 ++ ) {
int V_162 ;
for ( V_162 = 0 ; V_162 < F_57 ( V_163 ) ; V_162 ++ ) {
int V_84 ;
if ( ! ( V_13 -> V_42 [ V_3 ] & V_164 [ V_162 ] ) )
break;
if ( ! F_20 ( V_2 , V_3 ,
V_163 [ V_162 ] ) )
break;
V_84 = F_15 ( V_2 , V_3 ,
V_165 [ V_162 ] ) ;
if ( V_84 < 0 ||
( ! ( V_84 & ( V_166 >> ( ( V_162 & 1 ) * 4 ) ) ) ) )
continue;
F_49 ( V_5 , L_9 , L_7 , V_85 , V_3 ,
V_163 [ V_162 ] , V_71 , true ,
true ) ;
if ( ( V_13 -> V_42 [ V_3 ] & V_167 [ V_162 ] ) &&
F_19 ( V_2 ,
V_3 , V_168 [ V_162 ] ) ) {
int V_169 ;
if ( V_162 > 1 )
V_169 = V_56 + V_3 ;
else
V_169 = V_53 + V_3 ;
F_47 ( V_5 , L_9 , L_8 ,
V_85 , V_169 ,
V_170 >> ( V_162 & 1 ) ) ;
F_47 ( V_5 , L_9 , L_10 ,
V_85 , V_169 ,
V_171 >> ( V_162 & 1 ) ) ;
}
V_85 ++ ;
}
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_55 ( V_2 , V_5 , L_11 , V_172 ,
F_57 ( V_172 ) ) ;
F_55 ( V_2 , V_5 , L_12 , V_173 ,
F_57 ( V_173 ) ) ;
F_55 ( V_2 , V_5 , L_13 , V_174 ,
F_57 ( V_174 ) ) ;
F_55 ( V_2 , V_5 , L_14 , V_175 ,
F_57 ( V_175 ) ) ;
F_56 ( V_2 , V_5 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_176 = - 1 ;
if ( F_19 ( V_2 , 0 , V_177 ) )
V_176 = F_15 ( V_2 , 0 , V_177 ) ;
if ( V_176 >= 0 && V_176 != 0xff ) {
switch ( V_176 >> 5 ) {
case 0 :
if ( V_5 -> V_13 -> V_76 [ V_70 ] != V_79 )
return - V_178 ;
V_5 -> V_66 = ( ( V_179 ) ( V_176 << 3 ) ) >> 3 ;
break;
case 1 :
if ( V_5 -> V_13 -> V_76 [ V_70 ] != V_78 )
return - V_178 ;
break;
case 2 :
if ( V_5 -> V_13 -> V_76 [ V_70 ] != V_77 )
return - V_178 ;
break;
default:
return - V_178 ;
}
}
F_52 ( V_2 , V_5 ) ;
F_16 ( V_2 , 0 ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , const struct V_180 * V_181 ,
struct V_12 * V_13 )
{
const struct V_182 * V_183 = V_2 -> V_35 . V_184 ;
struct V_4 * V_5 ;
int V_102 ;
if ( ! V_13 ) {
F_61 ( & V_2 -> V_35 , L_15 ) ;
return - V_178 ;
}
if ( ! F_62 ( V_2 -> V_185 , V_186
| V_187
| V_188 ) )
return - V_178 ;
V_5 = F_63 ( sizeof( * V_5 ) , V_189 ) ;
if ( ! V_5 ) {
F_61 ( & V_2 -> V_35 , L_16 ) ;
return - V_190 ;
}
F_64 ( V_2 , V_5 ) ;
F_65 ( & V_5 -> V_36 ) ;
if ( F_4 ( V_2 , V_28 ) < 0 ) {
F_61 ( & V_2 -> V_35 , L_17 ) ;
V_102 = - V_178 ;
goto V_191;
}
if ( V_183 )
V_5 -> V_32 = V_183 -> V_32 ;
V_5 -> V_13 = V_13 ;
F_17 ( V_2 ) ;
if ( V_13 -> V_192 ) {
V_102 = (* V_13 -> V_192 )( V_2 , V_13 ) ;
if ( V_102 < 0 ) {
F_61 ( & V_2 -> V_35 , L_18 ) ;
goto V_191;
}
}
if ( V_13 -> V_26 <= 0 || V_13 -> V_26 > V_193 ) {
F_61 ( & V_2 -> V_35 , L_19 ,
V_13 -> V_26 ) ;
V_102 = - V_178 ;
goto V_191;
}
V_102 = F_59 ( V_2 , V_5 ) ;
if ( V_102 < 0 ) {
F_61 ( & V_2 -> V_35 , L_20 ) ;
goto V_191;
}
V_102 = - V_190 ;
V_5 -> V_64 = F_63 ( sizeof( struct V_62 ) * V_5 -> V_117 ,
V_189 ) ;
if ( ! V_5 -> V_64 ) {
F_61 ( & V_2 -> V_35 , L_21 ) ;
goto V_191;
}
V_5 -> V_112 = F_63 ( sizeof( struct V_109 )
* V_5 -> V_111 , V_189 ) ;
if ( ! V_5 -> V_112 ) {
F_61 ( & V_2 -> V_35 , L_22 ) ;
goto V_194;
}
V_5 -> V_104 = F_63 ( sizeof( struct V_119 ) * V_5 -> V_121 ,
V_189 ) ;
if ( ! V_5 -> V_104 ) {
F_61 ( & V_2 -> V_35 , L_23 ) ;
goto V_195;
}
V_5 -> V_196 = F_63 ( sizeof( struct V_197 * )
* V_5 -> V_143 , V_189 ) ;
if ( ! V_5 -> V_196 ) {
F_61 ( & V_2 -> V_35 , L_24 ) ;
goto V_198;
}
F_58 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_199 ) {
F_61 ( & V_2 -> V_35 , L_25 ) ;
V_102 = - V_178 ;
goto V_200;
}
V_5 -> V_201 . V_160 = V_5 -> V_196 ;
V_102 = F_66 ( & V_2 -> V_35 . V_202 , & V_5 -> V_201 ) ;
if ( V_102 ) {
F_61 ( & V_2 -> V_35 , L_26 ) ;
goto V_200;
}
V_5 -> V_203 = F_67 ( & V_2 -> V_35 ) ;
if ( F_68 ( V_5 -> V_203 ) ) {
V_102 = F_69 ( V_5 -> V_203 ) ;
F_61 ( & V_2 -> V_35 , L_27 ) ;
goto V_204;
}
return 0 ;
V_204:
F_70 ( & V_2 -> V_35 . V_202 , & V_5 -> V_201 ) ;
V_200:
F_71 ( V_5 -> V_196 ) ;
V_198:
F_71 ( V_5 -> V_104 ) ;
V_195:
F_71 ( V_5 -> V_112 ) ;
V_194:
F_71 ( V_5 -> V_64 ) ;
V_191:
F_71 ( V_5 ) ;
return V_102 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_73 ( V_5 -> V_203 ) ;
F_70 ( & V_2 -> V_35 . V_202 , & V_5 -> V_201 ) ;
F_71 ( V_5 -> V_196 ) ;
F_71 ( V_5 -> V_104 ) ;
F_71 ( V_5 -> V_112 ) ;
F_71 ( V_5 -> V_64 ) ;
F_71 ( V_5 ) ;
}
