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
long V_7 = 0 ;
switch ( V_4 -> V_14 -> V_71 ) {
case V_72 :
if ( V_63 >= 0x02 && V_63 <= 0xb2 )
V_7 = F_35 ( 160000 - ( V_63 - 2 ) * 625 , 100 ) ;
break;
case V_73 :
if ( V_63 >= 0x01 )
V_7 = 250 + ( V_63 - 1 ) * 5 ;
break;
}
return V_7 ;
}
static long F_37 ( struct V_3 * V_4 , struct V_40 * V_41 )
{
long V_63 ;
switch ( V_4 -> V_14 -> V_74 [ V_41 -> V_64 ] ) {
case V_75 :
V_63 = F_34 ( V_4 , V_41 ) ;
break;
case V_76 :
V_63 = F_36 ( V_4 , V_41 ) ;
break;
case V_77 :
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
bool V_78 = false ;
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
V_78 = true ;
V_63 = - V_63 ;
}
if ( V_41 -> V_64 == V_67 )
V_63 = F_35 ( V_63 , 1000L ) ;
if ( V_41 -> V_64 == V_66 )
V_63 = V_63 * 1000 ;
while ( V_63 >= V_79 && V_61 < 15 ) {
V_61 ++ ;
V_63 >>= 1 ;
}
while ( V_63 < V_80 && V_61 > - 15 ) {
V_61 -- ;
V_63 <<= 1 ;
}
V_62 = F_35 ( V_63 , 1000 ) ;
if ( V_62 > 0x3ff )
V_62 = 0x3ff ;
if ( V_78 )
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
T_2 V_81 ;
switch ( V_4 -> V_14 -> V_74 [ V_41 -> V_64 ] ) {
case V_75 :
V_81 = F_39 ( V_4 , V_41 , V_63 ) ;
break;
case V_76 :
V_81 = F_40 ( V_4 , V_41 , V_63 ) ;
break;
case V_77 :
default:
V_81 = F_38 ( V_4 , V_41 , V_63 ) ;
break;
}
return V_81 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_82 * V_69 ,
int V_83 )
{
struct V_40 * V_84 = V_69 -> V_84 ;
struct V_40 * V_85 = V_69 -> V_85 ;
T_2 V_18 = ( V_83 >> 8 ) & 0xffff ;
T_1 V_24 = V_83 & 0xff ;
int V_86 , V_15 ;
T_1 V_81 ;
V_15 = V_4 -> V_15 [ V_18 ] ;
if ( V_15 < 0 )
return V_15 ;
V_81 = V_15 & V_24 ;
if ( ! V_84 && ! V_85 ) {
V_86 = ! ! V_81 ;
} else if ( ! V_84 || ! V_85 ) {
F_44 ( 1 , L_1 , V_69 , V_84 , V_85 ) ;
return 0 ;
} else {
long V_87 , V_88 ;
if ( V_84 -> V_4 < 0 )
return V_84 -> V_4 ;
if ( V_85 -> V_4 < 0 )
return V_85 -> V_4 ;
V_87 = F_37 ( V_4 , V_84 ) ;
V_88 = F_37 ( V_4 , V_85 ) ;
V_86 = ! ! ( V_81 && V_87 >= V_88 ) ;
}
return V_86 ;
}
static T_5 F_45 ( struct V_37 * V_38 ,
struct V_89 * V_90 , char * V_91 )
{
struct V_92 * V_93 = F_46 ( V_90 ) ;
struct V_82 * boolean = F_47 ( V_93 ) ;
struct V_3 * V_4 = F_27 ( V_38 ) ;
int V_63 ;
V_63 = F_43 ( V_4 , boolean , V_93 -> V_83 ) ;
if ( V_63 < 0 )
return V_63 ;
return snprintf ( V_91 , V_94 , L_2 , V_63 ) ;
}
static T_5 F_48 ( struct V_37 * V_38 ,
struct V_89 * V_95 , char * V_91 )
{
struct V_3 * V_4 = F_27 ( V_38 ) ;
struct V_40 * V_41 = F_49 ( V_95 ) ;
if ( V_41 -> V_4 < 0 )
return V_41 -> V_4 ;
return snprintf ( V_91 , V_94 , L_3 , F_37 ( V_4 , V_41 ) ) ;
}
static T_5 F_50 ( struct V_37 * V_38 ,
struct V_89 * V_95 ,
const char * V_91 , T_6 V_96 )
{
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_49 ( V_95 ) ;
T_5 V_7 = V_96 ;
long V_63 = 0 ;
int V_86 ;
T_2 V_81 ;
if ( F_51 ( V_91 , 10 , & V_63 ) < 0 )
return - V_97 ;
F_29 ( & V_4 -> V_42 ) ;
V_81 = F_42 ( V_4 , V_41 , V_63 ) ;
V_86 = F_11 ( V_2 , V_41 -> V_6 , V_41 -> V_18 , V_81 ) ;
if ( V_86 < 0 )
V_7 = V_86 ;
else
V_41 -> V_4 = V_81 ;
F_32 ( & V_4 -> V_42 ) ;
return V_7 ;
}
static T_5 F_52 ( struct V_37 * V_38 ,
struct V_89 * V_90 , char * V_91 )
{
struct V_98 * V_99 = F_53 ( V_90 ) ;
return snprintf ( V_91 , V_94 , L_4 , V_99 -> V_99 ) ;
}
static int F_54 ( struct V_3 * V_4 , struct V_100 * V_93 )
{
if ( V_4 -> V_101 >= V_4 -> V_102 - 1 ) {
int V_103 = V_4 -> V_102 + V_104 ;
void * V_105 = F_55 ( V_4 -> V_106 . V_107 ,
V_103 * sizeof( void * ) ,
V_108 ) ;
if ( ! V_105 )
return - V_109 ;
V_4 -> V_106 . V_107 = V_105 ;
V_4 -> V_102 = V_103 ;
}
V_4 -> V_106 . V_107 [ V_4 -> V_101 ++ ] = V_93 ;
V_4 -> V_106 . V_107 [ V_4 -> V_101 ] = NULL ;
return 0 ;
}
static void F_56 ( struct V_89 * V_110 ,
const char * V_111 ,
T_7 V_112 ,
T_5 (* F_57)( struct V_37 * V_38 ,
struct V_89 * V_93 ,
char * V_91 ) ,
T_5 (* F_58)( struct V_37 * V_38 ,
struct V_89 * V_93 ,
const char * V_91 , T_6 V_96 ) )
{
F_59 ( & V_110 -> V_93 ) ;
V_110 -> V_93 . V_111 = V_111 ;
V_110 -> V_93 . V_112 = V_112 ;
V_110 -> F_57 = F_57 ;
V_110 -> F_58 = F_58 ;
}
static void F_60 ( struct V_92 * V_113 ,
const char * V_111 ,
T_7 V_112 ,
T_5 (* F_57)( struct V_37 * V_38 ,
struct V_89 * V_93 ,
char * V_91 ) ,
T_5 (* F_58)( struct V_37 * V_38 ,
struct V_89 * V_93 ,
const char * V_91 , T_6 V_96 ) ,
int V_114 )
{
F_56 ( & V_113 -> V_110 , V_111 , V_112 , F_57 , F_58 ) ;
V_113 -> V_83 = V_114 ;
}
static int F_61 ( struct V_3 * V_4 ,
const char * V_111 , const char * type , int V_115 ,
struct V_40 * V_84 ,
struct V_40 * V_85 ,
T_2 V_18 , T_1 V_24 )
{
struct V_82 * boolean ;
struct V_92 * V_113 ;
boolean = F_62 ( V_4 -> V_38 , sizeof( * boolean ) , V_108 ) ;
if ( ! boolean )
return - V_109 ;
V_113 = & boolean -> V_100 ;
snprintf ( boolean -> V_111 , sizeof( boolean -> V_111 ) , L_5 ,
V_111 , V_115 , type ) ;
boolean -> V_84 = V_84 ;
boolean -> V_85 = V_85 ;
F_60 ( V_113 , boolean -> V_111 , V_116 , F_45 , NULL ,
( V_18 << 8 ) | V_24 ) ;
return F_54 ( V_4 , & V_113 -> V_110 . V_93 ) ;
}
static struct V_40 * F_63 ( struct V_3 * V_4 ,
const char * V_111 , const char * type ,
int V_115 , int V_6 , int V_18 ,
enum V_117 V_64 ,
bool V_60 , bool V_118 )
{
struct V_40 * V_41 ;
struct V_89 * V_113 ;
V_41 = F_62 ( V_4 -> V_38 , sizeof( * V_41 ) , V_108 ) ;
if ( ! V_41 )
return NULL ;
V_113 = & V_41 -> V_100 ;
snprintf ( V_41 -> V_111 , sizeof( V_41 -> V_111 ) , L_5 ,
V_111 , V_115 , type ) ;
V_41 -> V_6 = V_6 ;
V_41 -> V_18 = V_18 ;
V_41 -> V_64 = V_64 ;
V_41 -> V_60 = V_60 ;
F_56 ( V_113 , V_41 -> V_111 ,
V_118 ? V_116 : V_116 | V_119 ,
F_48 , F_50 ) ;
if ( F_54 ( V_4 , & V_113 -> V_93 ) )
return NULL ;
V_41 -> V_59 = V_4 -> V_58 ;
V_4 -> V_58 = V_41 ;
return V_41 ;
}
static int F_64 ( struct V_3 * V_4 ,
const char * V_111 , int V_115 ,
const char * V_120 , int V_83 )
{
struct V_98 * V_99 ;
struct V_89 * V_113 ;
V_99 = F_62 ( V_4 -> V_38 , sizeof( * V_99 ) , V_108 ) ;
if ( ! V_99 )
return - V_109 ;
V_113 = & V_99 -> V_100 ;
snprintf ( V_99 -> V_111 , sizeof( V_99 -> V_111 ) , L_6 , V_111 , V_115 ) ;
if ( ! V_83 )
strncpy ( V_99 -> V_99 , V_120 , sizeof( V_99 -> V_99 ) - 1 ) ;
else
snprintf ( V_99 -> V_99 , sizeof( V_99 -> V_99 ) , L_7 , V_120 ,
V_83 ) ;
F_56 ( V_113 , V_99 -> V_111 , V_116 , F_52 , NULL ) ;
return F_54 ( V_4 , & V_113 -> V_93 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_111 , int V_83 , int V_6 ,
struct V_40 * V_51 ,
const struct V_121 * V_93 )
{
const struct V_122 * V_123 = V_93 -> V_124 ;
int V_125 = V_93 -> V_125 ;
int V_126 = 0 ;
int V_28 , V_86 ;
struct V_40 * V_127 ;
for ( V_28 = 0 ; V_28 < V_125 ; V_28 ++ ) {
if ( F_25 ( V_2 , V_6 , V_123 -> V_18 ) ) {
V_127 = F_63 ( V_4 , V_111 , V_123 -> V_93 , V_83 ,
V_6 , V_123 -> V_18 , V_93 -> V_64 ,
V_93 -> V_60 || V_123 -> V_60 ,
false ) ;
if ( ! V_127 )
return - V_109 ;
if ( V_123 -> V_128 && ( V_14 -> F_23 [ V_6 ] & V_93 -> V_129 ) ) {
V_86 = F_61 ( V_4 , V_111 ,
V_123 -> V_130 , V_83 ,
V_93 -> V_131 ? V_123 -> V_132 ? V_127 : V_51
: NULL ,
V_93 -> V_131 ? V_123 -> V_132 ? V_51 : V_127
: NULL ,
V_93 -> V_133 + V_6 , V_123 -> V_128 ) ;
if ( V_86 )
return V_86 ;
V_126 = 1 ;
}
}
V_123 ++ ;
}
return V_126 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_111 ,
int V_83 , int V_6 ,
const struct V_121 * V_93 )
{
struct V_40 * V_51 ;
int V_86 ;
if ( V_93 -> V_99 ) {
V_86 = F_64 ( V_4 , V_111 , V_83 , V_93 -> V_99 ,
V_93 -> V_134 ? V_6 + 1 : 0 ) ;
if ( V_86 )
return V_86 ;
}
V_51 = F_63 ( V_4 , V_111 , L_8 , V_83 , V_6 , V_93 -> V_18 ,
V_93 -> V_64 , true , true ) ;
if ( ! V_51 )
return - V_109 ;
if ( V_93 -> V_129 ) {
V_86 = F_65 ( V_2 , V_4 , V_14 , V_111 ,
V_83 , V_6 , V_51 , V_93 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( ! V_86 && V_93 -> V_135 &&
F_24 ( V_2 , V_6 ,
V_4 -> V_31 ) ) {
V_86 = F_61 ( V_4 , V_111 , L_9 , V_83 ,
NULL , NULL ,
V_47 + V_6 ,
V_93 -> V_135 ) ;
if ( V_86 )
return V_86 ;
}
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_111 ,
const struct V_121 * V_107 ,
int V_136 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_83 , V_28 ;
int V_86 ;
V_83 = 1 ;
for ( V_28 = 0 ; V_28 < V_136 ; V_28 ++ ) {
int V_6 , V_29 ;
V_29 = V_107 -> V_134 ? V_14 -> V_29 : 1 ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
if ( ! ( V_14 -> F_23 [ V_6 ] & V_107 -> F_23 ) )
continue;
V_86 = F_66 ( V_2 , V_4 , V_14 ,
V_111 , V_83 , V_6 ,
V_107 ) ;
if ( V_86 )
return V_86 ;
V_83 ++ ;
}
V_107 ++ ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_83 = 1 ;
int V_6 ;
int V_86 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_29 ; V_6 ++ ) {
int V_137 ;
for ( V_137 = 0 ; V_137 < F_31 ( V_138 ) ; V_137 ++ ) {
int V_81 ;
if ( ! ( V_14 -> F_23 [ V_6 ] & V_139 [ V_137 ] ) )
break;
if ( ! F_25 ( V_2 , V_6 ,
V_138 [ V_137 ] ) )
break;
V_81 = F_18 ( V_2 , V_6 ,
V_140 [ V_137 ] ) ;
if ( V_81 < 0 ||
( ! ( V_81 & ( V_141 >> ( ( V_137 & 1 ) * 4 ) ) ) ) )
continue;
if ( F_63 ( V_4 , L_10 , L_8 , V_83 ,
V_6 , V_138 [ V_137 ] ,
V_66 , true , true ) == NULL )
return - V_109 ;
if ( ( V_14 -> F_23 [ V_6 ] & V_142 [ V_137 ] ) &&
F_24 ( V_2 ,
V_6 , V_143 [ V_137 ] ) ) {
int V_51 ;
if ( V_137 > 1 )
V_51 = V_144 + V_6 ;
else
V_51 = V_145 + V_6 ;
V_86 = F_61 ( V_4 , L_10 ,
L_9 , V_83 , NULL , NULL , V_51 ,
V_146 >> ( V_137 & 1 ) ) ;
if ( V_86 )
return V_86 ;
V_86 = F_61 ( V_4 , L_10 ,
L_11 , V_83 , NULL , NULL , V_51 ,
V_147 >> ( V_137 & 1 ) ) ;
if ( V_86 )
return V_86 ;
}
V_83 ++ ;
}
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_67 ( V_2 , V_4 , L_12 , V_148 ,
F_31 ( V_148 ) ) ;
if ( V_86 )
return V_86 ;
V_86 = F_67 ( V_2 , V_4 , L_13 , V_149 ,
F_31 ( V_149 ) ) ;
if ( V_86 )
return V_86 ;
V_86 = F_67 ( V_2 , V_4 , L_14 , V_150 ,
F_31 ( V_150 ) ) ;
if ( V_86 )
return V_86 ;
V_86 = F_67 ( V_2 , V_4 , L_15 , V_151 ,
F_31 ( V_151 ) ) ;
if ( V_86 )
return V_86 ;
V_86 = F_68 ( V_2 , V_4 ) ;
return V_86 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_6 )
{
int V_152 = - 1 ;
if ( F_24 ( V_2 , V_6 , V_153 ) )
V_152 = F_18 ( V_2 , V_6 ,
V_153 ) ;
if ( V_152 >= 0 && V_152 != 0xff ) {
switch ( V_152 >> 5 ) {
case 0 :
if ( V_4 -> V_14 -> V_74 [ V_65 ] != V_77 )
return - V_154 ;
V_4 -> V_61 [ V_6 ] = ( ( V_155 ) ( V_152 << 3 ) ) >> 3 ;
break;
case 1 :
if ( V_4 -> V_14 -> V_74 [ V_65 ] != V_76 )
return - V_154 ;
break;
case 2 :
if ( V_4 -> V_14 -> V_74 [ V_65 ] != V_75 )
return - V_154 ;
break;
default:
return - V_154 ;
}
}
F_19 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
int V_6 , V_86 ;
V_4 -> V_31 = V_156 ;
V_86 = F_5 ( V_2 , V_156 ) ;
if ( V_86 < 0 || V_86 == 0xff ) {
V_4 -> V_31 = V_157 ;
V_86 = F_13 ( V_2 , V_157 ) ;
if ( V_86 < 0 || V_86 == 0xffff ) {
F_72 ( V_38 , L_16 ) ;
return - V_154 ;
}
}
V_86 = F_5 ( V_2 , V_158 ) ;
if ( V_86 >= 0 && ( V_86 & V_159 ) )
V_2 -> V_35 |= V_160 ;
F_20 ( V_2 ) ;
if ( V_14 -> V_161 ) {
V_86 = (* V_14 -> V_161 )( V_2 , V_14 ) ;
if ( V_86 < 0 ) {
F_72 ( V_38 , L_17 ) ;
return V_86 ;
}
}
if ( V_14 -> V_29 <= 0 || V_14 -> V_29 > V_162 ) {
F_72 ( V_38 , L_18 , V_14 -> V_29 ) ;
return - V_154 ;
}
for ( V_6 = 0 ; V_6 < V_14 -> V_29 ; V_6 ++ ) {
V_86 = F_70 ( V_2 , V_4 , V_6 ) ;
if ( V_86 < 0 ) {
F_72 ( V_38 , L_19 ) ;
return V_86 ;
}
}
return 0 ;
}
static int F_73 ( struct V_163 * V_164 )
{
struct V_37 * V_38 = F_74 ( V_164 ) ;
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
T_1 V_6 = F_75 ( V_164 ) ;
int V_86 ;
V_86 = F_15 ( V_2 , V_6 , V_165 ) ;
if ( V_86 < 0 )
return V_86 ;
return ! ! ( V_86 & V_166 ) ;
}
static int F_76 ( struct V_163 * V_164 , bool V_167 )
{
struct V_37 * V_38 = F_74 ( V_164 ) ;
struct V_1 * V_2 = F_28 ( V_38 -> V_39 ) ;
T_1 V_6 = F_75 ( V_164 ) ;
return F_17 ( V_2 , V_6 , V_165 ,
V_166 ,
V_167 ? V_166 : 0 ) ;
}
static int F_77 ( struct V_163 * V_164 )
{
return F_76 ( V_164 , 1 ) ;
}
static int F_78 ( struct V_163 * V_164 )
{
return F_76 ( V_164 , 0 ) ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_37 * V_38 = V_4 -> V_38 ;
const struct V_13 * V_14 = V_4 -> V_14 ;
const struct V_168 * V_169 = F_80 ( V_38 ) ;
struct V_163 * V_164 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_170 ; V_28 ++ ) {
struct V_171 V_172 = { } ;
V_172 . V_38 = V_38 ;
V_172 . V_173 = V_4 ;
if ( V_169 && V_169 -> V_174 )
V_172 . V_175 = & V_169 -> V_174 [ V_28 ] ;
V_164 = F_81 ( V_38 , & V_14 -> V_176 [ V_28 ] ,
& V_172 ) ;
if ( F_82 ( V_164 ) ) {
F_72 ( V_38 , L_20 ,
V_14 -> V_176 [ V_28 ] . V_111 ) ;
return F_83 ( V_164 ) ;
}
}
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
return 0 ;
}
int F_84 ( struct V_1 * V_2 , const struct V_177 * V_178 ,
struct V_13 * V_14 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
const struct V_168 * V_169 = F_80 ( V_38 ) ;
struct V_3 * V_4 ;
int V_86 ;
if ( ! V_14 )
return - V_154 ;
if ( ! F_85 ( V_2 -> V_179 , V_180
| V_181
| V_182 ) )
return - V_154 ;
V_4 = F_62 ( V_38 , sizeof( * V_4 ) , V_108 ) ;
if ( ! V_4 )
return - V_109 ;
F_86 ( V_2 , V_4 ) ;
F_87 ( & V_4 -> V_42 ) ;
V_4 -> V_38 = V_38 ;
if ( V_169 )
V_4 -> V_35 = V_169 -> V_35 ;
V_4 -> V_14 = V_14 ;
V_86 = F_71 ( V_2 , V_4 , V_14 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_69 ( V_2 , V_4 ) ;
if ( V_86 )
goto V_183;
if ( ! V_4 -> V_101 ) {
F_72 ( V_38 , L_21 ) ;
V_86 = - V_154 ;
goto V_183;
}
V_4 -> V_184 [ 0 ] = & V_4 -> V_106 ;
V_4 -> V_185 = F_88 ( V_38 , V_2 -> V_111 ,
V_4 , V_4 -> V_184 ) ;
if ( F_82 ( V_4 -> V_185 ) ) {
V_86 = F_83 ( V_4 -> V_185 ) ;
F_72 ( V_38 , L_22 ) ;
goto V_183;
}
V_86 = F_79 ( V_4 ) ;
if ( V_86 )
goto V_186;
return 0 ;
V_186:
F_89 ( V_4 -> V_185 ) ;
V_183:
F_90 ( V_4 -> V_106 . V_107 ) ;
return V_86 ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_89 ( V_4 -> V_185 ) ;
F_90 ( V_4 -> V_106 . V_107 ) ;
return 0 ;
}
