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
return - V_10 ;
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
if ( V_13 -> V_21 ) {
V_14 = V_13 -> V_21 ( V_2 , V_3 , V_17 ) ;
if ( V_14 != - V_16 )
return V_14 ;
}
if ( V_17 >= V_20 )
return - V_10 ;
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
if ( V_13 -> V_22 ) {
V_14 = V_13 -> V_22 ( V_2 , V_3 , V_17 ) ;
if ( V_14 != - V_16 )
return V_14 ;
}
return F_14 ( V_2 , V_3 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 )
{
F_7 ( V_2 , V_3 , V_23 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_5 -> V_13 -> V_25 ; V_24 ++ )
F_16 ( V_2 , V_24 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_14 , V_26 ;
V_14 = F_14 ( V_2 , - 1 , V_27 ) ;
if ( V_14 < 0 || ( V_14 & V_28 ) ) {
V_26 = F_14 ( V_2 , - 1 , V_29 ) ;
if ( V_26 < 0 || ( V_26 & V_30 ) )
return - V_10 ;
}
return 0 ;
}
bool F_19 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
int V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_15 ( V_2 , V_3 , V_17 ) ;
if ( V_6 >= 0 && ! ( V_5 -> V_31 & V_32 ) )
V_6 = F_18 ( V_2 ) ;
F_16 ( V_2 , - 1 ) ;
return V_6 >= 0 ;
}
bool F_20 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
int V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_13 ( V_2 , V_3 , V_17 ) ;
if ( V_6 >= 0 && ! ( V_5 -> V_31 & V_32 ) )
V_6 = F_18 ( V_2 ) ;
F_16 ( V_2 , - 1 ) ;
return V_6 >= 0 ;
}
const struct V_12 * F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_13 ;
}
static struct V_4 * F_22 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_12 * V_13 = V_5 -> V_13 ;
F_24 ( & V_5 -> V_35 ) ;
if ( F_25 ( V_36 , V_5 -> V_37 + V_38 ) || ! V_5 -> V_39 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_25 ; V_24 ++ )
V_5 -> V_14 [ V_40 + V_24 ]
= F_14 ( V_2 , V_24 ,
V_27 ) ;
for ( V_24 = 0 ; V_24 < V_13 -> V_25 ; V_24 ++ ) {
if ( ! ( V_13 -> V_41 [ V_24 ] & V_42 ) )
continue;
V_5 -> V_14 [ V_43 + V_24 ]
= F_15 ( V_2 , V_24 , V_44 ) ;
}
for ( V_24 = 0 ; V_24 < V_13 -> V_25 ; V_24 ++ ) {
if ( ! ( V_13 -> V_41 [ V_24 ] & V_45 ) )
continue;
V_5 -> V_14 [ V_46 + V_24 ]
= F_15 ( V_2 , V_24 , V_47 ) ;
}
for ( V_24 = 0 ; V_24 < V_13 -> V_25 ; V_24 ++ ) {
if ( ! ( V_13 -> V_41 [ V_24 ] & V_48 ) )
continue;
V_5 -> V_14 [ V_49 + V_24 ]
= F_15 ( V_2 , V_24 ,
V_50 ) ;
}
for ( V_24 = 0 ; V_24 < V_13 -> V_25 ; V_24 ++ ) {
if ( ! ( V_13 -> V_41 [ V_24 ] & V_51 ) )
continue;
V_5 -> V_14 [ V_52 + V_24 ]
= F_15 ( V_2 , V_24 ,
V_53 ) ;
}
for ( V_24 = 0 ; V_24 < V_13 -> V_25 ; V_24 ++ ) {
if ( ! ( V_13 -> V_41 [ V_24 ] & V_54 ) )
continue;
V_5 -> V_14 [ V_55 + V_24 ]
= F_15 ( V_2 , V_24 ,
V_56 ) ;
}
if ( V_13 -> V_41 [ 0 ] & V_57 )
V_5 -> V_14 [ V_58 ]
= F_15 ( V_2 , 0 ,
V_59 ) ;
for ( V_24 = 0 ; V_24 < V_5 -> V_60 ; V_24 ++ ) {
struct V_61 * V_62 = & V_5 -> V_63 [ V_24 ] ;
if ( ! V_5 -> V_39 || V_62 -> V_64 )
V_62 -> V_5
= F_13 ( V_2 ,
V_62 -> V_3 ,
V_62 -> V_17 ) ;
}
F_17 ( V_2 ) ;
V_5 -> V_37 = V_36 ;
V_5 -> V_39 = 1 ;
}
F_26 ( & V_5 -> V_35 ) ;
return V_5 ;
}
static long F_27 ( struct V_4 * V_5 ,
struct V_61 * V_62 )
{
T_3 V_65 ;
T_4 V_66 ;
long V_67 ;
if ( V_62 -> V_68 == V_69 ) {
V_65 = V_5 -> V_65 ;
V_66 = ( T_2 ) V_62 -> V_5 ;
} else {
V_65 = ( V_62 -> V_5 >> 11 ) & 0x001f ;
V_66 = V_62 -> V_5 & 0x07ff ;
if ( V_65 > 0x0f )
V_65 |= 0xffe0 ;
if ( V_66 > 0x03ff )
V_66 |= 0xfffff800 ;
}
V_67 = V_66 ;
if ( V_62 -> V_68 != V_70 )
V_67 = V_67 * 1000L ;
if ( V_62 -> V_68 == V_71 )
V_67 = V_67 * 1000L ;
if ( V_65 >= 0 )
V_67 <<= V_65 ;
else
V_67 >>= - V_65 ;
return V_67 ;
}
static long F_28 ( struct V_4 * V_5 ,
struct V_61 * V_62 )
{
long V_67 = ( T_3 ) V_62 -> V_5 ;
long V_72 , V_73 , V_74 ;
V_72 = V_5 -> V_13 -> V_72 [ V_62 -> V_68 ] ;
V_73 = V_5 -> V_13 -> V_73 [ V_62 -> V_68 ] ;
V_74 = V_5 -> V_13 -> V_74 [ V_62 -> V_68 ] ;
if ( V_72 == 0 )
return 0 ;
V_74 = - V_74 ;
if ( V_62 -> V_68 != V_70 ) {
V_74 += 3 ;
V_73 *= 1000 ;
}
if ( V_62 -> V_68 == V_71 ) {
V_74 += 3 ;
V_73 *= 1000 ;
}
while ( V_74 > 0 ) {
V_67 *= 10 ;
V_74 -- ;
}
while ( V_74 < 0 ) {
V_67 = F_29 ( V_67 , 10 ) ;
V_74 ++ ;
}
return ( V_67 - V_73 ) / V_72 ;
}
static long F_30 ( struct V_4 * V_5 ,
struct V_61 * V_62 )
{
long V_67 = V_62 -> V_5 ;
if ( V_67 < 0x02 || V_67 > 0xb2 )
return 0 ;
return F_29 ( 160000 - ( V_67 - 2 ) * 625 , 100 ) ;
}
static long F_31 ( struct V_4 * V_5 , struct V_61 * V_62 )
{
long V_67 ;
switch ( V_5 -> V_13 -> V_75 [ V_62 -> V_68 ] ) {
case V_76 :
V_67 = F_28 ( V_5 , V_62 ) ;
break;
case V_77 :
V_67 = F_30 ( V_5 , V_62 ) ;
break;
case V_78 :
default:
V_67 = F_27 ( V_5 , V_62 ) ;
break;
}
return V_67 ;
}
static T_2 F_32 ( struct V_4 * V_5 ,
enum V_79 V_68 , long V_67 )
{
T_3 V_65 = 0 , V_66 ;
bool V_80 = false ;
if ( V_67 == 0 )
return 0 ;
if ( V_68 == V_69 ) {
if ( V_67 < 0 )
return 0 ;
if ( V_5 -> V_65 < 0 )
V_67 <<= - V_5 -> V_65 ;
else
V_67 >>= V_5 -> V_65 ;
V_67 = F_29 ( V_67 , 1000 ) ;
return V_67 & 0xffff ;
}
if ( V_67 < 0 ) {
V_80 = true ;
V_67 = - V_67 ;
}
if ( V_68 == V_71 )
V_67 = F_29 ( V_67 , 1000L ) ;
if ( V_68 == V_70 )
V_67 = V_67 * 1000 ;
while ( V_67 >= V_81 && V_65 < 15 ) {
V_65 ++ ;
V_67 >>= 1 ;
}
while ( V_67 < V_82 && V_65 > - 15 ) {
V_65 -- ;
V_67 <<= 1 ;
}
V_66 = F_29 ( V_67 , 1000 ) ;
if ( V_66 > 0x3ff )
V_66 = 0x3ff ;
if ( V_80 )
V_66 = - V_66 ;
return ( V_66 & 0x7ff ) | ( ( V_65 << 11 ) & 0xf800 ) ;
}
static T_2 F_33 ( struct V_4 * V_5 ,
enum V_79 V_68 , long V_67 )
{
long V_72 , V_73 , V_74 ;
V_72 = V_5 -> V_13 -> V_72 [ V_68 ] ;
V_73 = V_5 -> V_13 -> V_73 [ V_68 ] ;
V_74 = V_5 -> V_13 -> V_74 [ V_68 ] ;
if ( V_68 == V_71 ) {
V_74 -= 3 ;
V_73 *= 1000 ;
}
if ( V_68 != V_70 ) {
V_74 -= 3 ;
V_73 *= 1000 ;
}
V_67 = V_67 * V_72 + V_73 ;
while ( V_74 > 0 ) {
V_67 *= 10 ;
V_74 -- ;
}
while ( V_74 < 0 ) {
V_67 = F_29 ( V_67 , 10 ) ;
V_74 ++ ;
}
return V_67 ;
}
static T_2 F_34 ( struct V_4 * V_5 ,
enum V_79 V_68 , long V_67 )
{
V_67 = F_35 ( V_67 , 500 , 1600 ) ;
return 2 + F_29 ( ( 1600 - V_67 ) * 100 , 625 ) ;
}
static T_2 F_36 ( struct V_4 * V_5 ,
enum V_79 V_68 , long V_67 )
{
T_2 V_83 ;
switch ( V_5 -> V_13 -> V_75 [ V_68 ] ) {
case V_76 :
V_83 = F_33 ( V_5 , V_68 , V_67 ) ;
break;
case V_77 :
V_83 = F_34 ( V_5 , V_68 , V_67 ) ;
break;
case V_78 :
default:
V_83 = F_32 ( V_5 , V_68 , V_67 ) ;
break;
}
return V_83 ;
}
static int F_37 ( struct V_4 * V_5 , int V_84 , int * V_67 )
{
T_1 V_85 = ( V_84 >> 24 ) & 0xff ;
T_1 V_86 = ( V_84 >> 16 ) & 0xff ;
T_1 V_17 = ( V_84 >> 8 ) & 0xff ;
T_1 V_87 = V_84 & 0xff ;
int V_14 ;
T_1 V_83 ;
V_14 = V_5 -> V_14 [ V_17 ] ;
if ( V_14 < 0 )
return V_14 ;
V_83 = V_14 & V_87 ;
if ( ! V_85 && ! V_86 )
* V_67 = ! ! V_83 ;
else {
long V_88 , V_89 ;
struct V_61 * V_90 , * V_91 ;
V_90 = & V_5 -> V_63 [ V_85 ] ;
if ( V_90 -> V_5 < 0 )
return V_90 -> V_5 ;
V_91 = & V_5 -> V_63 [ V_86 ] ;
if ( V_91 -> V_5 < 0 )
return V_91 -> V_5 ;
V_88 = F_31 ( V_5 , V_90 ) ;
V_89 = F_31 ( V_5 , V_91 ) ;
* V_67 = ! ! ( V_83 && V_88 >= V_89 ) ;
}
return 0 ;
}
static T_5 F_38 ( struct V_33 * V_34 ,
struct V_92 * V_93 , char * V_94 )
{
struct V_95 * V_96 = F_39 ( V_93 ) ;
struct V_4 * V_5 = F_22 ( V_34 ) ;
int V_67 ;
int V_97 ;
V_97 = F_37 ( V_5 , V_96 -> V_84 , & V_67 ) ;
if ( V_97 )
return V_97 ;
return snprintf ( V_94 , V_98 , L_1 , V_67 ) ;
}
static T_5 F_40 ( struct V_33 * V_34 ,
struct V_92 * V_93 , char * V_94 )
{
struct V_95 * V_96 = F_39 ( V_93 ) ;
struct V_4 * V_5 = F_22 ( V_34 ) ;
struct V_61 * V_62 ;
V_62 = & V_5 -> V_63 [ V_96 -> V_84 ] ;
if ( V_62 -> V_5 < 0 )
return V_62 -> V_5 ;
return snprintf ( V_94 , V_98 , L_2 , F_31 ( V_5 , V_62 ) ) ;
}
static T_5 F_41 ( struct V_33 * V_34 ,
struct V_92 * V_99 ,
const char * V_94 , T_6 V_100 )
{
struct V_95 * V_96 = F_39 ( V_99 ) ;
struct V_1 * V_2 = F_23 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_61 * V_62 = & V_5 -> V_63 [ V_96 -> V_84 ] ;
T_5 V_6 = V_100 ;
long V_67 = 0 ;
int V_101 ;
T_2 V_83 ;
if ( F_42 ( V_94 , 10 , & V_67 ) < 0 )
return - V_10 ;
F_24 ( & V_5 -> V_35 ) ;
V_83 = F_36 ( V_5 , V_62 -> V_68 , V_67 ) ;
V_101 = F_10 ( V_2 , V_62 -> V_3 , V_62 -> V_17 , V_83 ) ;
if ( V_101 < 0 )
V_6 = V_101 ;
else
V_5 -> V_63 [ V_96 -> V_84 ] . V_5 = V_83 ;
F_26 ( & V_5 -> V_35 ) ;
return V_6 ;
}
static T_5 F_43 ( struct V_33 * V_34 ,
struct V_92 * V_93 , char * V_94 )
{
struct V_1 * V_2 = F_23 ( V_34 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_95 * V_96 = F_39 ( V_93 ) ;
return snprintf ( V_94 , V_98 , L_3 ,
V_5 -> V_102 [ V_96 -> V_84 ] . V_103 ) ;
}
static void F_44 ( struct V_4 * V_5 ,
const char * V_104 , const char * type , int V_105 ,
int V_106 )
{
struct V_107 * boolean ;
F_45 ( V_5 -> V_108 >= V_5 -> V_109 ) ;
boolean = & V_5 -> V_110 [ V_5 -> V_108 ] ;
snprintf ( boolean -> V_104 , sizeof( boolean -> V_104 ) , L_4 ,
V_104 , V_105 , type ) ;
F_46 ( V_5 , boolean -> V_104 , boolean , V_106 ) ;
V_5 -> V_108 ++ ;
}
static void F_47 ( struct V_4 * V_5 ,
const char * V_104 , const char * type ,
int V_105 , int V_17 , int V_111 )
{
F_44 ( V_5 , V_104 , type , V_105 , ( V_17 << 8 ) | V_111 ) ;
}
static void F_48 ( struct V_4 * V_5 ,
const char * V_104 , const char * type ,
int V_105 , int V_112 , int V_113 , int V_17 , int V_87 )
{
F_44 ( V_5 , V_104 , type , V_105 ,
( V_112 << 24 ) | ( V_113 << 16 ) | ( V_17 << 8 ) | V_87 ) ;
}
static void F_49 ( struct V_4 * V_5 ,
const char * V_104 , const char * type , int V_105 ,
int V_3 , int V_17 , enum V_79 V_68 ,
bool V_64 , bool V_114 )
{
struct V_61 * V_62 ;
F_45 ( V_5 -> V_60 >= V_5 -> V_115 ) ;
V_62 = & V_5 -> V_63 [ V_5 -> V_60 ] ;
snprintf ( V_62 -> V_104 , sizeof( V_62 -> V_104 ) , L_4 ,
V_104 , V_105 , type ) ;
V_62 -> V_3 = V_3 ;
V_62 -> V_17 = V_17 ;
V_62 -> V_68 = V_68 ;
V_62 -> V_64 = V_64 ;
if ( V_114 )
F_46 ( V_5 , V_62 -> V_104 , V_62 ,
V_5 -> V_60 ) ;
else
F_50 ( V_5 , V_62 -> V_104 , V_62 ,
V_5 -> V_60 ) ;
V_5 -> V_60 ++ ;
}
static void F_51 ( struct V_4 * V_5 ,
const char * V_104 , int V_105 ,
const char * V_116 , int V_84 )
{
struct V_117 * V_103 ;
F_45 ( V_5 -> V_118 >= V_5 -> V_119 ) ;
V_103 = & V_5 -> V_102 [ V_5 -> V_118 ] ;
snprintf ( V_103 -> V_104 , sizeof( V_103 -> V_104 ) , L_5 , V_104 , V_105 ) ;
if ( ! V_84 )
strncpy ( V_103 -> V_103 , V_116 , sizeof( V_103 -> V_103 ) - 1 ) ;
else
snprintf ( V_103 -> V_103 , sizeof( V_103 -> V_103 ) , L_6 , V_116 ,
V_84 ) ;
F_46 ( V_5 , V_103 -> V_104 , V_103 , V_5 -> V_118 ) ;
V_5 -> V_118 ++ ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_3 , V_115 , V_109 , V_119 ;
V_115 = V_120 ;
V_109 = V_121 ;
V_119 = V_122 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_25 ; V_3 ++ ) {
if ( V_13 -> V_41 [ V_3 ] & V_123 ) {
V_115 += V_124 ;
V_109 += V_125 ;
V_119 ++ ;
}
if ( V_13 -> V_41 [ V_3 ] & V_126 ) {
V_115 += V_127 ;
V_109 += V_128 ;
V_119 ++ ;
}
if ( V_13 -> V_41 [ V_3 ] & V_129 ) {
V_115 += V_130 ;
V_109 += V_131 ;
V_119 ++ ;
}
if ( V_13 -> V_41 [ V_3 ] & V_132 ) {
V_115 += 2 * V_133 ;
V_109 += 2 * V_134 ;
}
if ( V_13 -> V_41 [ V_3 ] & V_135 ) {
V_115 += 2 * V_133 ;
V_109 += 2 * V_134 ;
}
if ( V_13 -> V_41 [ V_3 ] & V_136 ) {
V_115 += V_137 ;
V_109 += V_138 ;
}
if ( V_13 -> V_41 [ V_3 ] & V_139 ) {
V_115 += V_137 ;
V_109 += V_138 ;
}
if ( V_13 -> V_41 [ V_3 ] & V_140 ) {
V_115 += V_137 ;
V_109 += V_138 ;
}
}
V_5 -> V_115 = V_115 ;
V_5 -> V_109 = V_109 ;
V_5 -> V_119 = V_119 ;
V_5 -> V_141 = V_115 + V_109 + V_119 ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_12 * V_13 ,
const char * V_104 , int V_84 , int V_3 ,
int V_142 ,
const struct V_143 * V_96 )
{
const struct V_144 * V_145 = V_96 -> V_146 ;
int V_147 = V_96 -> V_147 ;
bool V_148 = false ;
int V_24 , V_149 ;
for ( V_24 = 0 ; V_24 < V_147 ; V_24 ++ ) {
if ( F_20 ( V_2 , V_3 , V_145 -> V_17 ) ) {
V_149 = V_5 -> V_60 ;
F_49 ( V_5 , V_104 , V_145 -> V_96 , V_84 , V_3 ,
V_145 -> V_17 , V_96 -> V_68 ,
V_96 -> V_64 || V_145 -> V_64 ,
false ) ;
if ( V_145 -> V_150 && ( V_13 -> V_41 [ V_3 ] & V_96 -> V_151 ) ) {
if ( V_96 -> V_152 ) {
F_48 ( V_5 , V_104 ,
V_145 -> V_153 , V_84 ,
V_145 -> V_154 ? V_149 : V_142 ,
V_145 -> V_154 ? V_142 : V_149 ,
V_96 -> V_155 + V_3 , V_145 -> V_150 ) ;
} else {
F_47 ( V_5 , V_104 ,
V_145 -> V_153 , V_84 ,
V_96 -> V_155 + V_3 , V_145 -> V_150 ) ;
}
V_148 = true ;
}
}
V_145 ++ ;
}
return V_148 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const struct V_12 * V_13 ,
const char * V_104 ,
int V_84 , int V_3 ,
const struct V_143 * V_96 )
{
bool V_148 ;
int V_142 = V_5 -> V_60 ;
if ( V_96 -> V_103 )
F_51 ( V_5 , V_104 , V_84 , V_96 -> V_103 ,
V_96 -> V_156 ? V_3 + 1 : 0 ) ;
F_49 ( V_5 , V_104 , L_7 , V_84 , V_3 , V_96 -> V_17 ,
V_96 -> V_68 , true , true ) ;
if ( V_96 -> V_151 ) {
V_148 = F_53 ( V_2 , V_5 , V_13 , V_104 ,
V_84 , V_3 , V_142 , V_96 ) ;
if ( ! V_148 && V_96 -> V_157 &&
F_19 ( V_2 , V_3 , V_27 ) )
F_47 ( V_5 , V_104 , L_8 , V_84 ,
V_40 + V_3 ,
V_96 -> V_157 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const char * V_104 ,
const struct V_143 * V_158 ,
int V_159 )
{
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_84 , V_24 ;
V_84 = 1 ;
for ( V_24 = 0 ; V_24 < V_159 ; V_24 ++ ) {
int V_3 , V_25 ;
V_25 = V_158 -> V_156 ? V_13 -> V_25 : 1 ;
for ( V_3 = 0 ; V_3 < V_25 ; V_3 ++ ) {
if ( ! ( V_13 -> V_41 [ V_3 ] & V_158 -> V_41 ) )
continue;
F_54 ( V_2 , V_5 , V_13 , V_104 ,
V_84 , V_3 , V_158 ) ;
V_84 ++ ;
}
V_158 ++ ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
const struct V_12 * V_13 = V_5 -> V_13 ;
int V_84 = 1 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_25 ; V_3 ++ ) {
int V_160 ;
for ( V_160 = 0 ; V_160 < F_57 ( V_161 ) ; V_160 ++ ) {
int V_83 ;
if ( ! ( V_13 -> V_41 [ V_3 ] & V_162 [ V_160 ] ) )
break;
if ( ! F_20 ( V_2 , V_3 ,
V_161 [ V_160 ] ) )
break;
V_83 = F_15 ( V_2 , V_3 ,
V_163 [ V_160 ] ) ;
if ( V_83 < 0 ||
( ! ( V_83 & ( V_164 >> ( ( V_160 & 1 ) * 4 ) ) ) ) )
continue;
F_49 ( V_5 , L_9 , L_7 , V_84 , V_3 ,
V_161 [ V_160 ] , V_70 , true ,
true ) ;
if ( ( V_13 -> V_41 [ V_3 ] & V_165 [ V_160 ] ) &&
F_19 ( V_2 ,
V_3 , V_166 [ V_160 ] ) ) {
int V_167 ;
if ( V_160 > 1 )
V_167 = V_55 + V_3 ;
else
V_167 = V_52 + V_3 ;
F_47 ( V_5 , L_9 , L_8 ,
V_84 , V_167 ,
V_168 >> ( V_160 & 1 ) ) ;
F_47 ( V_5 , L_9 , L_10 ,
V_84 , V_167 ,
V_169 >> ( V_160 & 1 ) ) ;
}
V_84 ++ ;
}
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_55 ( V_2 , V_5 , L_11 , V_170 ,
F_57 ( V_170 ) ) ;
F_55 ( V_2 , V_5 , L_12 , V_171 ,
F_57 ( V_171 ) ) ;
F_55 ( V_2 , V_5 , L_13 , V_172 ,
F_57 ( V_172 ) ) ;
F_55 ( V_2 , V_5 , L_14 , V_173 ,
F_57 ( V_173 ) ) ;
F_56 ( V_2 , V_5 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_174 = - 1 , V_65 ;
if ( F_19 ( V_2 , 0 , V_175 ) )
V_174 = F_14 ( V_2 , 0 , V_175 ) ;
if ( V_174 >= 0 && V_174 != 0xff ) {
switch ( V_174 >> 5 ) {
case 0 :
if ( V_5 -> V_13 -> V_75 [ V_69 ] != V_78 )
return - V_176 ;
V_65 = V_174 & 0x1f ;
if ( V_65 & 0x10 )
V_65 |= ~ 0x1f ;
V_5 -> V_65 = V_65 ;
break;
case 1 :
if ( V_5 -> V_13 -> V_75 [ V_69 ] != V_77 )
return - V_176 ;
break;
case 2 :
if ( V_5 -> V_13 -> V_75 [ V_69 ] != V_76 )
return - V_176 ;
break;
default:
return - V_176 ;
}
}
F_52 ( V_2 , V_5 ) ;
F_16 ( V_2 , 0 ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , const struct V_177 * V_178 ,
struct V_12 * V_13 )
{
const struct V_179 * V_180 = V_2 -> V_34 . V_181 ;
struct V_4 * V_5 ;
int V_101 ;
if ( ! V_13 ) {
F_61 ( & V_2 -> V_34 , L_15 ) ;
return - V_176 ;
}
if ( ! F_62 ( V_2 -> V_182 , V_183
| V_184
| V_185 ) )
return - V_176 ;
V_5 = F_63 ( sizeof( * V_5 ) , V_186 ) ;
if ( ! V_5 ) {
F_61 ( & V_2 -> V_34 , L_16 ) ;
return - V_187 ;
}
F_64 ( V_2 , V_5 ) ;
F_65 ( & V_5 -> V_35 ) ;
if ( F_4 ( V_2 , V_27 ) < 0 ) {
F_61 ( & V_2 -> V_34 , L_17 ) ;
V_101 = - V_176 ;
goto V_188;
}
if ( V_180 )
V_5 -> V_31 = V_180 -> V_31 ;
V_5 -> V_13 = V_13 ;
F_17 ( V_2 ) ;
if ( V_13 -> V_189 ) {
V_101 = (* V_13 -> V_189 )( V_2 , V_13 ) ;
if ( V_101 < 0 ) {
F_61 ( & V_2 -> V_34 , L_18 ) ;
goto V_188;
}
}
if ( V_13 -> V_25 <= 0 || V_13 -> V_25 > V_190 ) {
F_61 ( & V_2 -> V_34 , L_19 ,
V_13 -> V_25 ) ;
V_101 = - V_10 ;
goto V_188;
}
V_101 = F_59 ( V_2 , V_5 ) ;
if ( V_101 < 0 ) {
F_61 ( & V_2 -> V_34 , L_20 ) ;
goto V_188;
}
V_101 = - V_187 ;
V_5 -> V_63 = F_63 ( sizeof( struct V_61 ) * V_5 -> V_115 ,
V_186 ) ;
if ( ! V_5 -> V_63 ) {
F_61 ( & V_2 -> V_34 , L_21 ) ;
goto V_188;
}
V_5 -> V_110 = F_63 ( sizeof( struct V_107 )
* V_5 -> V_109 , V_186 ) ;
if ( ! V_5 -> V_110 ) {
F_61 ( & V_2 -> V_34 , L_22 ) ;
goto V_191;
}
V_5 -> V_102 = F_63 ( sizeof( struct V_117 ) * V_5 -> V_119 ,
V_186 ) ;
if ( ! V_5 -> V_102 ) {
F_61 ( & V_2 -> V_34 , L_23 ) ;
goto V_192;
}
V_5 -> V_193 = F_63 ( sizeof( struct V_194 * )
* V_5 -> V_141 , V_186 ) ;
if ( ! V_5 -> V_193 ) {
F_61 ( & V_2 -> V_34 , L_24 ) ;
goto V_195;
}
F_58 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_196 ) {
F_61 ( & V_2 -> V_34 , L_25 ) ;
V_101 = - V_176 ;
goto V_197;
}
V_5 -> V_198 . V_158 = V_5 -> V_193 ;
V_101 = F_66 ( & V_2 -> V_34 . V_199 , & V_5 -> V_198 ) ;
if ( V_101 ) {
F_61 ( & V_2 -> V_34 , L_26 ) ;
goto V_197;
}
V_5 -> V_200 = F_67 ( & V_2 -> V_34 ) ;
if ( F_68 ( V_5 -> V_200 ) ) {
V_101 = F_69 ( V_5 -> V_200 ) ;
F_61 ( & V_2 -> V_34 , L_27 ) ;
goto V_201;
}
return 0 ;
V_201:
F_70 ( & V_2 -> V_34 . V_199 , & V_5 -> V_198 ) ;
V_197:
F_71 ( V_5 -> V_193 ) ;
V_195:
F_71 ( V_5 -> V_102 ) ;
V_192:
F_71 ( V_5 -> V_110 ) ;
V_191:
F_71 ( V_5 -> V_63 ) ;
V_188:
F_71 ( V_5 ) ;
return V_101 ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_73 ( V_5 -> V_200 ) ;
F_70 ( & V_2 -> V_34 . V_199 , & V_5 -> V_198 ) ;
F_71 ( V_5 -> V_193 ) ;
F_71 ( V_5 -> V_102 ) ;
F_71 ( V_5 -> V_110 ) ;
F_71 ( V_5 -> V_63 ) ;
F_71 ( V_5 ) ;
return 0 ;
}
