void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = false ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = 0 ;
int V_8 ;
if ( V_6 != V_4 -> V_9 ) {
V_7 = F_4 ( V_2 , V_10 , V_6 ) ;
V_8 = F_5 ( V_2 , V_10 ) ;
if ( V_8 != V_6 )
V_7 = - V_11 ;
else
V_4 -> V_9 = V_6 ;
}
return V_7 ;
}
int F_6 ( struct V_1 * V_2 , int V_6 , T_1 V_12 )
{
int V_7 ;
if ( V_6 >= 0 ) {
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return F_7 ( V_2 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_6 , T_1 V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 -> V_16 ) {
V_15 = V_14 -> V_16 ( V_2 , V_6 , V_12 ) ;
if ( V_15 != - V_17 )
return V_15 ;
}
return F_6 ( V_2 , V_6 , V_12 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_18 , T_2 V_19 )
{
int V_7 ;
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_10 ( V_2 , V_18 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_6 , int V_18 ,
T_2 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 -> V_20 ) {
V_15 = V_14 -> V_20 ( V_2 , V_6 , V_18 , V_19 ) ;
if ( V_15 != - V_17 )
return V_15 ;
}
if ( V_18 >= V_21 )
return - V_22 ;
return F_9 ( V_2 , V_6 , V_18 , V_19 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_18 )
{
int V_7 ;
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_13 ( V_2 , V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 -> V_23 ) {
V_15 = V_14 -> V_23 ( V_2 , V_6 , V_18 ) ;
if ( V_15 != - V_17 )
return V_15 ;
}
if ( V_18 >= V_21 )
return - V_22 ;
return F_12 ( V_2 , V_6 , V_18 ) ;
}
int F_15 ( struct V_1 * V_2 , int V_6 , T_1 V_18 )
{
int V_7 ;
if ( V_6 >= 0 ) {
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return F_5 ( V_2 , V_18 ) ;
}
int F_16 ( struct V_1 * V_2 , int V_6 , T_1 V_18 , T_1 V_12 )
{
int V_7 ;
V_7 = F_3 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 , V_18 , V_12 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_6 , T_1 V_18 ,
T_1 V_24 , T_1 V_12 )
{
unsigned int V_25 ;
int V_7 ;
V_7 = F_15 ( V_2 , V_6 , V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
V_25 = ( V_7 & ~ V_24 ) | ( V_12 & V_24 ) ;
if ( V_25 != V_7 )
V_7 = F_16 ( V_2 , V_6 , V_18 , V_25 ) ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 -> V_26 ) {
V_15 = V_14 -> V_26 ( V_2 , V_6 , V_18 ) ;
if ( V_15 != - V_17 )
return V_15 ;
}
return F_15 ( V_2 , V_6 , V_18 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_6 )
{
F_8 ( V_2 , V_6 , V_27 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_14 -> V_29 ; V_28 ++ )
F_19 ( V_2 , V_28 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 , V_30 ;
V_15 = F_18 ( V_2 , - 1 , V_4 -> V_31 ) ;
if ( V_15 < 0 || ( V_15 & V_32 ) ) {
V_30 = F_18 ( V_2 , - 1 , V_33 ) ;
if ( V_30 < 0 || ( V_30 & V_34 ) )
return - V_11 ;
}
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 ,
int (* F_23)( struct V_1 * V_2 ,
int V_6 , int V_18 ) ,
int V_6 , int V_18 )
{
int V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_7 = F_23 ( V_2 , V_6 , V_18 ) ;
if ( V_7 >= 0 && ! ( V_4 -> V_35 & V_36 ) )
V_7 = F_21 ( V_2 ) ;
F_19 ( V_2 , - 1 ) ;
return V_7 >= 0 ;
}
bool F_24 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
return F_22 ( V_2 , F_18 , V_6 , V_18 ) ;
}
bool F_25 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
return F_22 ( V_2 , F_14 , V_6 , V_18 ) ;
}
const struct V_13 * F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_14 ;
}
static struct V_3 * F_27 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
struct V_40 * V_41 ;
F_29 ( & V_4 -> V_42 ) ;
if ( F_30 ( V_43 , V_4 -> V_44 + V_45 ) || ! V_4 -> V_5 ) {
int V_28 , V_46 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_29 ; V_28 ++ ) {
V_4 -> V_15 [ V_47 + V_28 ]
= F_18 ( V_2 , V_28 ,
V_4 -> V_31 ) ;
for ( V_46 = 0 ; V_46 < F_31 ( V_48 ) ; V_46 ++ ) {
struct V_49 * V_50 = & V_48 [ V_46 ] ;
if ( ! ( V_14 -> F_23 [ V_28 ] & V_50 -> F_23 ) )
continue;
V_4 -> V_15 [ V_50 -> V_51 + V_28 ]
= F_18 ( V_2 , V_28 ,
V_50 -> V_18 ) ;
}
}
if ( V_14 -> F_23 [ 0 ] & V_52 )
V_4 -> V_15 [ V_53 ]
= F_18 ( V_2 , 0 ,
V_54 ) ;
if ( V_14 -> F_23 [ 0 ] & V_55 )
V_4 -> V_15 [ V_56 ]
= F_18 ( V_2 , 0 ,
V_57 ) ;
for ( V_41 = V_4 -> V_58 ; V_41 ; V_41 = V_41 -> V_59 ) {
if ( ! V_4 -> V_5 || V_41 -> V_60 )
V_41 -> V_4
= F_14 ( V_2 ,
V_41 -> V_6 ,
V_41 -> V_18 ) ;
}
F_20 ( V_2 ) ;
V_4 -> V_44 = V_43 ;
V_4 -> V_5 = 1 ;
}
F_32 ( & V_4 -> V_42 ) ;
return V_4 ;
}
static long F_33 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
T_3 V_61 ;
T_4 V_62 ;
long V_63 ;
if ( V_41 -> V_64 == V_65 ) {
V_61 = V_4 -> V_61 [ V_41 -> V_6 ] ;
V_62 = ( T_2 ) V_41 -> V_4 ;
} else {
V_61 = ( ( T_3 ) V_41 -> V_4 ) >> 11 ;
V_62 = ( ( T_3 ) ( ( V_41 -> V_4 & 0x7ff ) << 5 ) ) >> 5 ;
}
V_63 = V_62 ;
if ( V_41 -> V_64 != V_66 )
V_63 = V_63 * 1000L ;
if ( V_41 -> V_64 == V_67 )
V_63 = V_63 * 1000L ;
if ( V_61 >= 0 )
V_63 <<= V_61 ;
else
V_63 >>= - V_61 ;
return V_63 ;
}
static long F_34 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
long V_63 = ( T_3 ) V_41 -> V_4 ;
long V_68 , V_69 , V_70 ;
V_68 = V_4 -> V_14 -> V_68 [ V_41 -> V_64 ] ;
V_69 = V_4 -> V_14 -> V_69 [ V_41 -> V_64 ] ;
V_70 = V_4 -> V_14 -> V_70 [ V_41 -> V_64 ] ;
if ( V_68 == 0 )
return 0 ;
V_70 = - V_70 ;
if ( V_41 -> V_64 != V_66 ) {
V_70 += 3 ;
V_69 *= 1000 ;
}
if ( V_41 -> V_64 == V_67 ) {
V_70 += 3 ;
V_69 *= 1000 ;
}
while ( V_70 > 0 ) {
V_63 *= 10 ;
V_70 -- ;
}
while ( V_70 < 0 ) {
V_63 = F_35 ( V_63 , 10 ) ;
V_70 ++ ;
}
return ( V_63 - V_69 ) / V_68 ;
}
static long F_36 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
long V_63 = V_41 -> V_4 ;
if ( V_63 < 0x02 || V_63 > 0xb2 )
return 0 ;
return F_35 ( 160000 - ( V_63 - 2 ) * 625 , 100 ) ;
}
static long F_37 ( struct V_3 * V_4 , struct V_40 * V_41 )
{
long V_63 ;
switch ( V_4 -> V_14 -> V_71 [ V_41 -> V_64 ] ) {
case V_72 :
V_63 = F_34 ( V_4 , V_41 ) ;
break;
case V_73 :
V_63 = F_36 ( V_4 , V_41 ) ;
break;
case V_74 :
default:
V_63 = F_33 ( V_4 , V_41 ) ;
break;
}
return V_63 ;
}
static T_2 F_38 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
T_3 V_61 = 0 , V_62 ;
bool V_75 = false ;
if ( V_63 == 0 )
return 0 ;
if ( V_41 -> V_64 == V_65 ) {
if ( V_63 < 0 )
return 0 ;
if ( V_4 -> V_61 [ V_41 -> V_6 ] < 0 )
V_63 <<= - V_4 -> V_61 [ V_41 -> V_6 ] ;
else
V_63 >>= V_4 -> V_61 [ V_41 -> V_6 ] ;
V_63 = F_35 ( V_63 , 1000 ) ;
return V_63 & 0xffff ;
}
if ( V_63 < 0 ) {
V_75 = true ;
V_63 = - V_63 ;
}
if ( V_41 -> V_64 == V_67 )
V_63 = F_35 ( V_63 , 1000L ) ;
if ( V_41 -> V_64 == V_66 )
V_63 = V_63 * 1000 ;
while ( V_63 >= V_76 && V_61 < 15 ) {
V_61 ++ ;
V_63 >>= 1 ;
}
while ( V_63 < V_77 && V_61 > - 15 ) {
V_61 -- ;
V_63 <<= 1 ;
}
V_62 = F_35 ( V_63 , 1000 ) ;
if ( V_62 > 0x3ff )
V_62 = 0x3ff ;
if ( V_75 )
V_62 = - V_62 ;
return ( V_62 & 0x7ff ) | ( ( V_61 << 11 ) & 0xf800 ) ;
}
static T_2 F_39 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
long V_68 , V_69 , V_70 ;
V_68 = V_4 -> V_14 -> V_68 [ V_41 -> V_64 ] ;
V_69 = V_4 -> V_14 -> V_69 [ V_41 -> V_64 ] ;
V_70 = V_4 -> V_14 -> V_70 [ V_41 -> V_64 ] ;
if ( V_41 -> V_64 == V_67 ) {
V_70 -= 3 ;
V_69 *= 1000 ;
}
if ( V_41 -> V_64 != V_66 ) {
V_70 -= 3 ;
V_69 *= 1000 ;
}
V_63 = V_63 * V_68 + V_69 ;
while ( V_70 > 0 ) {
V_63 *= 10 ;
V_70 -- ;
}
while ( V_70 < 0 ) {
V_63 = F_35 ( V_63 , 10 ) ;
V_70 ++ ;
}
return V_63 ;
}
static T_2 F_40 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
V_63 = F_41 ( V_63 , 500 , 1600 ) ;
return 2 + F_35 ( ( 1600 - V_63 ) * 100 , 625 ) ;
}
static T_2 F_42 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
T_2 V_78 ;
switch ( V_4 -> V_14 -> V_71 [ V_41 -> V_64 ] ) {
case V_72 :
V_78 = F_39 ( V_4 , V_41 , V_63 ) ;
break;
case V_73 :
V_78 = F_40 ( V_4 , V_41 , V_63 ) ;
break;
case V_74 :
default:
V_78 = F_38 ( V_4 , V_41 , V_63 ) ;
break;
}
return V_78 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_79 * V_69 ,
int V_80 )
{
struct V_40 * V_81 = V_69 -> V_81 ;
struct V_40 * V_82 = V_69 -> V_82 ;
T_2 V_18 = ( V_80 >> 8 ) & 0xffff ;
T_1 V_24 = V_80 & 0xff ;
int V_83 , V_15 ;
T_1 V_78 ;
V_15 = V_4 -> V_15 [ V_18 ] ;
if ( V_15 < 0 )
return V_15 ;
V_78 = V_15 & V_24 ;
if ( ! V_81 && ! V_82 ) {
V_83 = ! ! V_78 ;
} else if ( ! V_81 || ! V_82 ) {
F_44 ( 1 , L_1 , V_69 , V_81 , V_82 ) ;
return 0 ;
} else {
long V_84 , V_85 ;
if ( V_81 -> V_4 < 0 )
return V_81 -> V_4 ;
if ( V_82 -> V_4 < 0 )
return V_82 -> V_4 ;
V_84 = F_37 ( V_4 , V_81 ) ;
V_85 = F_37 ( V_4 , V_82 ) ;
V_83 = ! ! ( V_78 && V_84 >= V_85 ) ;
}
return V_83 ;
}
static T_5 F_45 ( struct V_37 * V_38 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_46 ( V_87 ) ;
struct V_79 * boolean = F_47 ( V_90 ) ;
struct V_3 * V_4 = F_27 ( V_38 ) ;
int V_63 ;
V_63 = F_43 ( V_4 , boolean , V_90 -> V_80 ) ;
if ( V_63 < 0 )
return V_63 ;
return snprintf ( V_88 , V_91 , L_2 , V_63 ) ;
}
static T_5 F_48 ( struct V_37 * V_38 ,
struct V_86 * V_92 , char * V_88 )
{
struct V_3 * V_4 = F_27 ( V_38 ) ;
struct V_40 * V_41 = F_49 ( V_92 ) ;
if ( V_41 -> V_4 < 0 )
return V_41 -> V_4 ;
return snprintf ( V_88 , V_91 , L_3 , F_37 ( V_4 , V_41 ) ) ;
}
static T_5 F_50 ( struct V_37 * V_38 ,
struct V_86 * V_92 ,
const char * V_88 , T_6 V_93 )
{
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_49 ( V_92 ) ;
T_5 V_7 = V_93 ;
long V_63 = 0 ;
int V_83 ;
T_2 V_78 ;
if ( F_51 ( V_88 , 10 , & V_63 ) < 0 )
return - V_94 ;
F_29 ( & V_4 -> V_42 ) ;
V_78 = F_42 ( V_4 , V_41 , V_63 ) ;
V_83 = F_11 ( V_2 , V_41 -> V_6 , V_41 -> V_18 , V_78 ) ;
if ( V_83 < 0 )
V_7 = V_83 ;
else
V_41 -> V_4 = V_78 ;
F_32 ( & V_4 -> V_42 ) ;
return V_7 ;
}
static T_5 F_52 ( struct V_37 * V_38 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_95 * V_96 = F_53 ( V_87 ) ;
return snprintf ( V_88 , V_91 , L_4 , V_96 -> V_96 ) ;
}
static int F_54 ( struct V_3 * V_4 , struct V_97 * V_90 )
{
if ( V_4 -> V_98 >= V_4 -> V_99 - 1 ) {
int V_100 = V_4 -> V_99 + V_101 ;
void * V_102 = F_55 ( V_4 -> V_103 . V_104 ,
V_100 * sizeof( void * ) ,
V_105 ) ;
if ( ! V_102 )
return - V_106 ;
V_4 -> V_103 . V_104 = V_102 ;
V_4 -> V_99 = V_100 ;
}
V_4 -> V_103 . V_104 [ V_4 -> V_98 ++ ] = V_90 ;
V_4 -> V_103 . V_104 [ V_4 -> V_98 ] = NULL ;
return 0 ;
}
static void F_56 ( struct V_86 * V_107 ,
const char * V_108 ,
T_7 V_109 ,
T_5 (* F_57)( struct V_37 * V_38 ,
struct V_86 * V_90 ,
char * V_88 ) ,
T_5 (* F_58)( struct V_37 * V_38 ,
struct V_86 * V_90 ,
const char * V_88 , T_6 V_93 ) )
{
F_59 ( & V_107 -> V_90 ) ;
V_107 -> V_90 . V_108 = V_108 ;
V_107 -> V_90 . V_109 = V_109 ;
V_107 -> F_57 = F_57 ;
V_107 -> F_58 = F_58 ;
}
static void F_60 ( struct V_89 * V_110 ,
const char * V_108 ,
T_7 V_109 ,
T_5 (* F_57)( struct V_37 * V_38 ,
struct V_86 * V_90 ,
char * V_88 ) ,
T_5 (* F_58)( struct V_37 * V_38 ,
struct V_86 * V_90 ,
const char * V_88 , T_6 V_93 ) ,
int V_111 )
{
F_56 ( & V_110 -> V_107 , V_108 , V_109 , F_57 , F_58 ) ;
V_110 -> V_80 = V_111 ;
}
static int F_61 ( struct V_3 * V_4 ,
const char * V_108 , const char * type , int V_112 ,
struct V_40 * V_81 ,
struct V_40 * V_82 ,
T_2 V_18 , T_1 V_24 )
{
struct V_79 * boolean ;
struct V_89 * V_110 ;
boolean = F_62 ( V_4 -> V_38 , sizeof( * boolean ) , V_105 ) ;
if ( ! boolean )
return - V_106 ;
V_110 = & boolean -> V_97 ;
snprintf ( boolean -> V_108 , sizeof( boolean -> V_108 ) , L_5 ,
V_108 , V_112 , type ) ;
boolean -> V_81 = V_81 ;
boolean -> V_82 = V_82 ;
F_60 ( V_110 , boolean -> V_108 , V_113 , F_45 , NULL ,
( V_18 << 8 ) | V_24 ) ;
return F_54 ( V_4 , & V_110 -> V_107 . V_90 ) ;
}
static struct V_40 * F_63 ( struct V_3 * V_4 ,
const char * V_108 , const char * type ,
int V_112 , int V_6 , int V_18 ,
enum V_114 V_64 ,
bool V_60 , bool V_115 )
{
struct V_40 * V_41 ;
struct V_86 * V_110 ;
V_41 = F_62 ( V_4 -> V_38 , sizeof( * V_41 ) , V_105 ) ;
if ( ! V_41 )
return NULL ;
V_110 = & V_41 -> V_97 ;
snprintf ( V_41 -> V_108 , sizeof( V_41 -> V_108 ) , L_5 ,
V_108 , V_112 , type ) ;
V_41 -> V_6 = V_6 ;
V_41 -> V_18 = V_18 ;
V_41 -> V_64 = V_64 ;
V_41 -> V_60 = V_60 ;
F_56 ( V_110 , V_41 -> V_108 ,
V_115 ? V_113 : V_113 | V_116 ,
F_48 , F_50 ) ;
if ( F_54 ( V_4 , & V_110 -> V_90 ) )
return NULL ;
V_41 -> V_59 = V_4 -> V_58 ;
V_4 -> V_58 = V_41 ;
return V_41 ;
}
static int F_64 ( struct V_3 * V_4 ,
const char * V_108 , int V_112 ,
const char * V_117 , int V_80 )
{
struct V_95 * V_96 ;
struct V_86 * V_110 ;
V_96 = F_62 ( V_4 -> V_38 , sizeof( * V_96 ) , V_105 ) ;
if ( ! V_96 )
return - V_106 ;
V_110 = & V_96 -> V_97 ;
snprintf ( V_96 -> V_108 , sizeof( V_96 -> V_108 ) , L_6 , V_108 , V_112 ) ;
if ( ! V_80 )
strncpy ( V_96 -> V_96 , V_117 , sizeof( V_96 -> V_96 ) - 1 ) ;
else
snprintf ( V_96 -> V_96 , sizeof( V_96 -> V_96 ) , L_7 , V_117 ,
V_80 ) ;
F_56 ( V_110 , V_96 -> V_108 , V_113 , F_52 , NULL ) ;
return F_54 ( V_4 , & V_110 -> V_90 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_108 , int V_80 , int V_6 ,
struct V_40 * V_51 ,
const struct V_118 * V_90 )
{
const struct V_119 * V_120 = V_90 -> V_121 ;
int V_122 = V_90 -> V_122 ;
int V_123 = 0 ;
int V_28 , V_83 ;
struct V_40 * V_124 ;
for ( V_28 = 0 ; V_28 < V_122 ; V_28 ++ ) {
if ( F_25 ( V_2 , V_6 , V_120 -> V_18 ) ) {
V_124 = F_63 ( V_4 , V_108 , V_120 -> V_90 , V_80 ,
V_6 , V_120 -> V_18 , V_90 -> V_64 ,
V_90 -> V_60 || V_120 -> V_60 ,
false ) ;
if ( ! V_124 )
return - V_106 ;
if ( V_120 -> V_125 && ( V_14 -> F_23 [ V_6 ] & V_90 -> V_126 ) ) {
V_83 = F_61 ( V_4 , V_108 ,
V_120 -> V_127 , V_80 ,
V_90 -> V_128 ? V_120 -> V_129 ? V_124 : V_51
: NULL ,
V_90 -> V_128 ? V_120 -> V_129 ? V_51 : V_124
: NULL ,
V_90 -> V_130 + V_6 , V_120 -> V_125 ) ;
if ( V_83 )
return V_83 ;
V_123 = 1 ;
}
}
V_120 ++ ;
}
return V_123 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_108 ,
int V_80 , int V_6 ,
const struct V_118 * V_90 )
{
struct V_40 * V_51 ;
int V_83 ;
if ( V_90 -> V_96 ) {
V_83 = F_64 ( V_4 , V_108 , V_80 , V_90 -> V_96 ,
V_90 -> V_131 ? V_6 + 1 : 0 ) ;
if ( V_83 )
return V_83 ;
}
V_51 = F_63 ( V_4 , V_108 , L_8 , V_80 , V_6 , V_90 -> V_18 ,
V_90 -> V_64 , true , true ) ;
if ( ! V_51 )
return - V_106 ;
if ( V_90 -> V_126 ) {
V_83 = F_65 ( V_2 , V_4 , V_14 , V_108 ,
V_80 , V_6 , V_51 , V_90 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( ! V_83 && V_90 -> V_132 &&
F_24 ( V_2 , V_6 ,
V_4 -> V_31 ) ) {
V_83 = F_61 ( V_4 , V_108 , L_9 , V_80 ,
NULL , NULL ,
V_47 + V_6 ,
V_90 -> V_132 ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_108 ,
const struct V_118 * V_104 ,
int V_133 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_80 , V_28 ;
int V_83 ;
V_80 = 1 ;
for ( V_28 = 0 ; V_28 < V_133 ; V_28 ++ ) {
int V_6 , V_29 ;
V_29 = V_104 -> V_131 ? V_14 -> V_29 : 1 ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
if ( ! ( V_14 -> F_23 [ V_6 ] & V_104 -> F_23 ) )
continue;
V_83 = F_66 ( V_2 , V_4 , V_14 ,
V_108 , V_80 , V_6 ,
V_104 ) ;
if ( V_83 )
return V_83 ;
V_80 ++ ;
}
V_104 ++ ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_80 = 1 ;
int V_6 ;
int V_83 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_29 ; V_6 ++ ) {
int V_134 ;
for ( V_134 = 0 ; V_134 < F_31 ( V_135 ) ; V_134 ++ ) {
int V_78 ;
if ( ! ( V_14 -> F_23 [ V_6 ] & V_136 [ V_134 ] ) )
break;
if ( ! F_25 ( V_2 , V_6 ,
V_135 [ V_134 ] ) )
break;
V_78 = F_18 ( V_2 , V_6 ,
V_137 [ V_134 ] ) ;
if ( V_78 < 0 ||
( ! ( V_78 & ( V_138 >> ( ( V_134 & 1 ) * 4 ) ) ) ) )
continue;
if ( F_63 ( V_4 , L_10 , L_8 , V_80 ,
V_6 , V_135 [ V_134 ] ,
V_66 , true , true ) == NULL )
return - V_106 ;
if ( ( V_14 -> F_23 [ V_6 ] & V_139 [ V_134 ] ) &&
F_24 ( V_2 ,
V_6 , V_140 [ V_134 ] ) ) {
int V_51 ;
if ( V_134 > 1 )
V_51 = V_141 + V_6 ;
else
V_51 = V_142 + V_6 ;
V_83 = F_61 ( V_4 , L_10 ,
L_9 , V_80 , NULL , NULL , V_51 ,
V_143 >> ( V_134 & 1 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_61 ( V_4 , L_10 ,
L_11 , V_80 , NULL , NULL , V_51 ,
V_144 >> ( V_134 & 1 ) ) ;
if ( V_83 )
return V_83 ;
}
V_80 ++ ;
}
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_83 ;
V_83 = F_67 ( V_2 , V_4 , L_12 , V_145 ,
F_31 ( V_145 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_67 ( V_2 , V_4 , L_13 , V_146 ,
F_31 ( V_146 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_67 ( V_2 , V_4 , L_14 , V_147 ,
F_31 ( V_147 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_67 ( V_2 , V_4 , L_15 , V_148 ,
F_31 ( V_148 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_68 ( V_2 , V_4 ) ;
return V_83 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_6 )
{
int V_149 = - 1 ;
if ( F_24 ( V_2 , V_6 , V_150 ) )
V_149 = F_18 ( V_2 , V_6 ,
V_150 ) ;
if ( V_149 >= 0 && V_149 != 0xff ) {
switch ( V_149 >> 5 ) {
case 0 :
if ( V_4 -> V_14 -> V_71 [ V_65 ] != V_74 )
return - V_151 ;
V_4 -> V_61 [ V_6 ] = ( ( V_152 ) ( V_149 << 3 ) ) >> 3 ;
break;
case 1 :
if ( V_4 -> V_14 -> V_71 [ V_65 ] != V_73 )
return - V_151 ;
break;
case 2 :
if ( V_4 -> V_14 -> V_71 [ V_65 ] != V_72 )
return - V_151 ;
break;
default:
return - V_151 ;
}
}
F_19 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
int V_6 , V_83 ;
V_4 -> V_31 = V_153 ;
V_83 = F_5 ( V_2 , V_153 ) ;
if ( V_83 < 0 || V_83 == 0xff ) {
V_4 -> V_31 = V_154 ;
V_83 = F_13 ( V_2 , V_154 ) ;
if ( V_83 < 0 || V_83 == 0xffff ) {
F_72 ( V_38 , L_16 ) ;
return - V_151 ;
}
}
F_20 ( V_2 ) ;
if ( V_14 -> V_155 ) {
V_83 = (* V_14 -> V_155 )( V_2 , V_14 ) ;
if ( V_83 < 0 ) {
F_72 ( V_38 , L_17 ) ;
return V_83 ;
}
}
if ( V_14 -> V_29 <= 0 || V_14 -> V_29 > V_156 ) {
F_72 ( V_38 , L_18 , V_14 -> V_29 ) ;
return - V_151 ;
}
for ( V_6 = 0 ; V_6 < V_14 -> V_29 ; V_6 ++ ) {
V_83 = F_70 ( V_2 , V_4 , V_6 ) ;
if ( V_83 < 0 ) {
F_72 ( V_38 , L_19 ) ;
return V_83 ;
}
}
return 0 ;
}
static int F_73 ( struct V_157 * V_158 )
{
struct V_37 * V_38 = F_74 ( V_158 ) ;
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
T_1 V_6 = F_75 ( V_158 ) ;
int V_83 ;
V_83 = F_15 ( V_2 , V_6 , V_159 ) ;
if ( V_83 < 0 )
return V_83 ;
return ! ! ( V_83 & V_160 ) ;
}
static int F_76 ( struct V_157 * V_158 , bool V_161 )
{
struct V_37 * V_38 = F_74 ( V_158 ) ;
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
T_1 V_6 = F_75 ( V_158 ) ;
return F_17 ( V_2 , V_6 , V_159 ,
V_160 ,
V_161 ? V_160 : 0 ) ;
}
static int F_77 ( struct V_157 * V_158 )
{
return F_76 ( V_158 , 1 ) ;
}
static int F_78 ( struct V_157 * V_158 )
{
return F_76 ( V_158 , 0 ) ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_37 * V_38 = V_4 -> V_38 ;
const struct V_13 * V_14 = V_4 -> V_14 ;
const struct V_162 * V_163 = F_80 ( V_38 ) ;
struct V_157 * V_158 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_164 ; V_28 ++ ) {
struct V_165 V_166 = { } ;
V_166 . V_38 = V_38 ;
V_166 . V_167 = V_4 ;
if ( V_163 && V_163 -> V_168 )
V_166 . V_169 = & V_163 -> V_168 [ V_28 ] ;
V_158 = F_81 ( V_38 , & V_14 -> V_170 [ V_28 ] ,
& V_166 ) ;
if ( F_82 ( V_158 ) ) {
F_72 ( V_38 , L_20 ,
V_14 -> V_170 [ V_28 ] . V_108 ) ;
return F_83 ( V_158 ) ;
}
}
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
return 0 ;
}
int F_84 ( struct V_1 * V_2 , const struct V_171 * V_172 ,
struct V_13 * V_14 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
const struct V_162 * V_163 = F_80 ( V_38 ) ;
struct V_3 * V_4 ;
int V_83 ;
if ( ! V_14 )
return - V_151 ;
if ( ! F_85 ( V_2 -> V_173 , V_174
| V_175
| V_176 ) )
return - V_151 ;
V_4 = F_62 ( V_38 , sizeof( * V_4 ) , V_105 ) ;
if ( ! V_4 )
return - V_106 ;
F_86 ( V_2 , V_4 ) ;
F_87 ( & V_4 -> V_42 ) ;
V_4 -> V_38 = V_38 ;
if ( V_163 )
V_4 -> V_35 = V_163 -> V_35 ;
V_4 -> V_14 = V_14 ;
V_83 = F_71 ( V_2 , V_4 , V_14 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_69 ( V_2 , V_4 ) ;
if ( V_83 )
goto V_177;
if ( ! V_4 -> V_98 ) {
F_72 ( V_38 , L_21 ) ;
V_83 = - V_151 ;
goto V_177;
}
V_4 -> V_178 [ 0 ] = & V_4 -> V_103 ;
V_4 -> V_179 = F_88 ( V_38 , V_2 -> V_108 ,
V_4 , V_4 -> V_178 ) ;
if ( F_82 ( V_4 -> V_179 ) ) {
V_83 = F_83 ( V_4 -> V_179 ) ;
F_72 ( V_38 , L_22 ) ;
goto V_177;
}
V_83 = F_79 ( V_4 ) ;
if ( V_83 )
goto V_180;
return 0 ;
V_180:
F_89 ( V_4 -> V_179 ) ;
V_177:
F_90 ( V_4 -> V_103 . V_104 ) ;
return V_83 ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_89 ( V_4 -> V_179 ) ;
F_90 ( V_4 -> V_103 . V_104 ) ;
return 0 ;
}
