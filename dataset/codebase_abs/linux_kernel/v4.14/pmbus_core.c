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
V_15 = V_4 -> V_31 ( V_2 , - 1 ) ;
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
static bool F_24 ( struct V_1 * V_2 , int V_6 )
{
int V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = V_4 -> V_31 ( V_2 , V_6 ) ;
if ( V_15 >= 0 && ! ( V_4 -> V_35 & V_36 ) &&
( V_15 & V_32 ) ) {
V_15 = F_18 ( V_2 , - 1 , V_33 ) ;
if ( V_15 < 0 || ( V_15 & V_34 ) )
V_15 = - V_11 ;
}
F_19 ( V_2 , - 1 ) ;
return V_15 >= 0 ;
}
bool F_25 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
return F_22 ( V_2 , F_18 , V_6 , V_18 ) ;
}
bool F_26 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
return F_22 ( V_2 , F_14 , V_6 , V_18 ) ;
}
const struct V_13 * F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_14 ;
}
static struct V_3 * F_28 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_29 ( V_38 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
struct V_40 * V_41 ;
F_30 ( & V_4 -> V_42 ) ;
if ( F_31 ( V_43 , V_4 -> V_44 + V_45 ) || ! V_4 -> V_5 ) {
int V_28 , V_46 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_29 ; V_28 ++ ) {
V_4 -> V_15 [ V_47 + V_28 ]
= V_4 -> V_31 ( V_2 , V_28 ) ;
for ( V_46 = 0 ; V_46 < F_32 ( V_48 ) ; V_46 ++ ) {
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
F_33 ( & V_4 -> V_42 ) ;
return V_4 ;
}
static long F_34 ( struct V_3 * V_4 ,
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
static long F_35 ( struct V_3 * V_4 ,
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
V_63 = F_36 ( V_63 , 10 ) ;
V_70 ++ ;
}
return ( V_63 - V_69 ) / V_68 ;
}
static long F_37 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
long V_63 = V_41 -> V_4 ;
long V_7 = 0 ;
switch ( V_4 -> V_14 -> V_71 ) {
case V_72 :
if ( V_63 >= 0x02 && V_63 <= 0xb2 )
V_7 = F_36 ( 160000 - ( V_63 - 2 ) * 625 , 100 ) ;
break;
case V_73 :
if ( V_63 >= 0x01 )
V_7 = 250 + ( V_63 - 1 ) * 5 ;
break;
case V_74 :
if ( V_63 >= 0x01 )
V_7 = 500 + ( V_63 - 1 ) * 10 ;
break;
}
return V_7 ;
}
static long F_38 ( struct V_3 * V_4 , struct V_40 * V_41 )
{
long V_63 ;
switch ( V_4 -> V_14 -> V_75 [ V_41 -> V_64 ] ) {
case V_76 :
V_63 = F_35 ( V_4 , V_41 ) ;
break;
case V_77 :
V_63 = F_37 ( V_4 , V_41 ) ;
break;
case V_78 :
default:
V_63 = F_34 ( V_4 , V_41 ) ;
break;
}
return V_63 ;
}
static T_2 F_39 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
T_3 V_61 = 0 , V_62 ;
bool V_79 = false ;
if ( V_63 == 0 )
return 0 ;
if ( V_41 -> V_64 == V_65 ) {
if ( V_63 < 0 )
return 0 ;
if ( V_4 -> V_61 [ V_41 -> V_6 ] < 0 )
V_63 <<= - V_4 -> V_61 [ V_41 -> V_6 ] ;
else
V_63 >>= V_4 -> V_61 [ V_41 -> V_6 ] ;
V_63 = F_36 ( V_63 , 1000 ) ;
return V_63 & 0xffff ;
}
if ( V_63 < 0 ) {
V_79 = true ;
V_63 = - V_63 ;
}
if ( V_41 -> V_64 == V_67 )
V_63 = F_36 ( V_63 , 1000L ) ;
if ( V_41 -> V_64 == V_66 )
V_63 = V_63 * 1000 ;
while ( V_63 >= V_80 && V_61 < 15 ) {
V_61 ++ ;
V_63 >>= 1 ;
}
while ( V_63 < V_81 && V_61 > - 15 ) {
V_61 -- ;
V_63 <<= 1 ;
}
V_62 = F_36 ( V_63 , 1000 ) ;
if ( V_62 > 0x3ff )
V_62 = 0x3ff ;
if ( V_79 )
V_62 = - V_62 ;
return ( V_62 & 0x7ff ) | ( ( V_61 << 11 ) & 0xf800 ) ;
}
static T_2 F_40 ( struct V_3 * V_4 ,
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
V_63 = F_36 ( V_63 , 10 ) ;
V_70 ++ ;
}
return V_63 ;
}
static T_2 F_41 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
V_63 = F_42 ( V_63 , 500 , 1600 ) ;
return 2 + F_36 ( ( 1600 - V_63 ) * 100 , 625 ) ;
}
static T_2 F_43 ( struct V_3 * V_4 ,
struct V_40 * V_41 , long V_63 )
{
T_2 V_82 ;
switch ( V_4 -> V_14 -> V_75 [ V_41 -> V_64 ] ) {
case V_76 :
V_82 = F_40 ( V_4 , V_41 , V_63 ) ;
break;
case V_77 :
V_82 = F_41 ( V_4 , V_41 , V_63 ) ;
break;
case V_78 :
default:
V_82 = F_39 ( V_4 , V_41 , V_63 ) ;
break;
}
return V_82 ;
}
static int F_44 ( struct V_3 * V_4 , struct V_83 * V_69 ,
int V_84 )
{
struct V_40 * V_85 = V_69 -> V_85 ;
struct V_40 * V_86 = V_69 -> V_86 ;
T_2 V_18 = ( V_84 >> 16 ) & 0xffff ;
T_2 V_24 = V_84 & 0xffff ;
int V_87 , V_15 ;
T_2 V_82 ;
V_15 = V_4 -> V_15 [ V_18 ] ;
if ( V_15 < 0 )
return V_15 ;
V_82 = V_15 & V_24 ;
if ( ! V_85 && ! V_86 ) {
V_87 = ! ! V_82 ;
} else if ( ! V_85 || ! V_86 ) {
F_45 ( 1 , L_1 , V_69 , V_85 , V_86 ) ;
return 0 ;
} else {
long V_88 , V_89 ;
if ( V_85 -> V_4 < 0 )
return V_85 -> V_4 ;
if ( V_86 -> V_4 < 0 )
return V_86 -> V_4 ;
V_88 = F_38 ( V_4 , V_85 ) ;
V_89 = F_38 ( V_4 , V_86 ) ;
V_87 = ! ! ( V_82 && V_88 >= V_89 ) ;
}
return V_87 ;
}
static T_5 F_46 ( struct V_37 * V_38 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_93 * V_94 = F_47 ( V_91 ) ;
struct V_83 * boolean = F_48 ( V_94 ) ;
struct V_3 * V_4 = F_28 ( V_38 ) ;
int V_63 ;
V_63 = F_44 ( V_4 , boolean , V_94 -> V_84 ) ;
if ( V_63 < 0 )
return V_63 ;
return snprintf ( V_92 , V_95 , L_2 , V_63 ) ;
}
static T_5 F_49 ( struct V_37 * V_38 ,
struct V_90 * V_96 , char * V_92 )
{
struct V_3 * V_4 = F_28 ( V_38 ) ;
struct V_40 * V_41 = F_50 ( V_96 ) ;
if ( V_41 -> V_4 < 0 )
return V_41 -> V_4 ;
return snprintf ( V_92 , V_95 , L_3 , F_38 ( V_4 , V_41 ) ) ;
}
static T_5 F_51 ( struct V_37 * V_38 ,
struct V_90 * V_96 ,
const char * V_92 , T_6 V_97 )
{
struct V_1 * V_2 = F_29 ( V_38 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_50 ( V_96 ) ;
T_5 V_7 = V_97 ;
long V_63 = 0 ;
int V_87 ;
T_2 V_82 ;
if ( F_52 ( V_92 , 10 , & V_63 ) < 0 )
return - V_98 ;
F_30 ( & V_4 -> V_42 ) ;
V_82 = F_43 ( V_4 , V_41 , V_63 ) ;
V_87 = F_11 ( V_2 , V_41 -> V_6 , V_41 -> V_18 , V_82 ) ;
if ( V_87 < 0 )
V_7 = V_87 ;
else
V_41 -> V_4 = V_82 ;
F_33 ( & V_4 -> V_42 ) ;
return V_7 ;
}
static T_5 F_53 ( struct V_37 * V_38 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_99 * V_100 = F_54 ( V_91 ) ;
return snprintf ( V_92 , V_95 , L_4 , V_100 -> V_100 ) ;
}
static int F_55 ( struct V_3 * V_4 , struct V_101 * V_94 )
{
if ( V_4 -> V_102 >= V_4 -> V_103 - 1 ) {
int V_104 = V_4 -> V_103 + V_105 ;
void * V_106 = F_56 ( V_4 -> V_107 . V_108 ,
V_104 * sizeof( void * ) ,
V_109 ) ;
if ( ! V_106 )
return - V_110 ;
V_4 -> V_107 . V_108 = V_106 ;
V_4 -> V_103 = V_104 ;
}
V_4 -> V_107 . V_108 [ V_4 -> V_102 ++ ] = V_94 ;
V_4 -> V_107 . V_108 [ V_4 -> V_102 ] = NULL ;
return 0 ;
}
static void F_57 ( struct V_90 * V_111 ,
const char * V_112 ,
T_7 V_113 ,
T_5 (* F_58)( struct V_37 * V_38 ,
struct V_90 * V_94 ,
char * V_92 ) ,
T_5 (* F_59)( struct V_37 * V_38 ,
struct V_90 * V_94 ,
const char * V_92 , T_6 V_97 ) )
{
F_60 ( & V_111 -> V_94 ) ;
V_111 -> V_94 . V_112 = V_112 ;
V_111 -> V_94 . V_113 = V_113 ;
V_111 -> F_58 = F_58 ;
V_111 -> F_59 = F_59 ;
}
static void F_61 ( struct V_93 * V_114 ,
const char * V_112 ,
T_7 V_113 ,
T_5 (* F_58)( struct V_37 * V_38 ,
struct V_90 * V_94 ,
char * V_92 ) ,
T_5 (* F_59)( struct V_37 * V_38 ,
struct V_90 * V_94 ,
const char * V_92 , T_6 V_97 ) ,
int V_115 )
{
F_57 ( & V_114 -> V_111 , V_112 , V_113 , F_58 , F_59 ) ;
V_114 -> V_84 = V_115 ;
}
static int F_62 ( struct V_3 * V_4 ,
const char * V_112 , const char * type , int V_116 ,
struct V_40 * V_85 ,
struct V_40 * V_86 ,
T_2 V_18 , T_2 V_24 )
{
struct V_83 * boolean ;
struct V_93 * V_114 ;
boolean = F_63 ( V_4 -> V_38 , sizeof( * boolean ) , V_109 ) ;
if ( ! boolean )
return - V_110 ;
V_114 = & boolean -> V_101 ;
snprintf ( boolean -> V_112 , sizeof( boolean -> V_112 ) , L_5 ,
V_112 , V_116 , type ) ;
boolean -> V_85 = V_85 ;
boolean -> V_86 = V_86 ;
F_61 ( V_114 , boolean -> V_112 , V_117 , F_46 , NULL ,
( V_18 << 16 ) | V_24 ) ;
return F_55 ( V_4 , & V_114 -> V_111 . V_94 ) ;
}
static struct V_40 * F_64 ( struct V_3 * V_4 ,
const char * V_112 , const char * type ,
int V_116 , int V_6 , int V_18 ,
enum V_118 V_64 ,
bool V_60 , bool V_119 )
{
struct V_40 * V_41 ;
struct V_90 * V_114 ;
V_41 = F_63 ( V_4 -> V_38 , sizeof( * V_41 ) , V_109 ) ;
if ( ! V_41 )
return NULL ;
V_114 = & V_41 -> V_101 ;
snprintf ( V_41 -> V_112 , sizeof( V_41 -> V_112 ) , L_5 ,
V_112 , V_116 , type ) ;
V_41 -> V_6 = V_6 ;
V_41 -> V_18 = V_18 ;
V_41 -> V_64 = V_64 ;
V_41 -> V_60 = V_60 ;
F_57 ( V_114 , V_41 -> V_112 ,
V_119 ? V_117 : V_117 | V_120 ,
F_49 , F_51 ) ;
if ( F_55 ( V_4 , & V_114 -> V_94 ) )
return NULL ;
V_41 -> V_59 = V_4 -> V_58 ;
V_4 -> V_58 = V_41 ;
return V_41 ;
}
static int F_65 ( struct V_3 * V_4 ,
const char * V_112 , int V_116 ,
const char * V_121 , int V_84 )
{
struct V_99 * V_100 ;
struct V_90 * V_114 ;
V_100 = F_63 ( V_4 -> V_38 , sizeof( * V_100 ) , V_109 ) ;
if ( ! V_100 )
return - V_110 ;
V_114 = & V_100 -> V_101 ;
snprintf ( V_100 -> V_112 , sizeof( V_100 -> V_112 ) , L_6 , V_112 , V_116 ) ;
if ( ! V_84 )
strncpy ( V_100 -> V_100 , V_121 , sizeof( V_100 -> V_100 ) - 1 ) ;
else
snprintf ( V_100 -> V_100 , sizeof( V_100 -> V_100 ) , L_7 , V_121 ,
V_84 ) ;
F_57 ( V_114 , V_100 -> V_112 , V_117 , F_53 , NULL ) ;
return F_55 ( V_4 , & V_114 -> V_94 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_112 , int V_84 , int V_6 ,
struct V_40 * V_51 ,
const struct V_122 * V_94 )
{
const struct V_123 * V_124 = V_94 -> V_125 ;
int V_126 = V_94 -> V_126 ;
int V_127 = 0 ;
int V_28 , V_87 ;
struct V_40 * V_128 ;
for ( V_28 = 0 ; V_28 < V_126 ; V_28 ++ ) {
if ( F_26 ( V_2 , V_6 , V_124 -> V_18 ) ) {
V_128 = F_64 ( V_4 , V_112 , V_124 -> V_94 , V_84 ,
V_6 , V_124 -> V_18 , V_94 -> V_64 ,
V_94 -> V_60 || V_124 -> V_60 ,
false ) ;
if ( ! V_128 )
return - V_110 ;
if ( V_124 -> V_129 && ( V_14 -> F_23 [ V_6 ] & V_94 -> V_130 ) ) {
V_87 = F_62 ( V_4 , V_112 ,
V_124 -> V_131 , V_84 ,
V_94 -> V_132 ? V_124 -> V_133 ? V_128 : V_51
: NULL ,
V_94 -> V_132 ? V_124 -> V_133 ? V_51 : V_128
: NULL ,
V_94 -> V_134 + V_6 , V_124 -> V_129 ) ;
if ( V_87 )
return V_87 ;
V_127 = 1 ;
}
}
V_124 ++ ;
}
return V_127 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_112 ,
int V_84 , int V_6 ,
const struct V_122 * V_94 )
{
struct V_40 * V_51 ;
bool V_135 = ! ! ( V_94 -> V_136 & 0xff00 ) ;
int V_87 ;
if ( V_94 -> V_100 ) {
V_87 = F_65 ( V_4 , V_112 , V_84 , V_94 -> V_100 ,
V_94 -> V_137 ? V_6 + 1 : 0 ) ;
if ( V_87 )
return V_87 ;
}
V_51 = F_64 ( V_4 , V_112 , L_8 , V_84 , V_6 , V_94 -> V_18 ,
V_94 -> V_64 , true , true ) ;
if ( ! V_51 )
return - V_110 ;
if ( V_94 -> V_130 ) {
V_87 = F_66 ( V_2 , V_4 , V_14 , V_112 ,
V_84 , V_6 , V_51 , V_94 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( ! V_87 && V_94 -> V_136 &&
( ! V_135 || ( V_135 && V_4 -> V_138 ) ) &&
F_24 ( V_2 , V_6 ) ) {
V_87 = F_62 ( V_4 , V_112 , L_9 , V_84 ,
NULL , NULL ,
V_47 + V_6 ,
V_94 -> V_136 ) ;
if ( V_87 )
return V_87 ;
}
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_112 ,
const struct V_122 * V_108 ,
int V_139 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_84 , V_28 ;
int V_87 ;
V_84 = 1 ;
for ( V_28 = 0 ; V_28 < V_139 ; V_28 ++ ) {
int V_6 , V_29 ;
V_29 = V_108 -> V_137 ? V_14 -> V_29 : 1 ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
if ( ! ( V_14 -> F_23 [ V_6 ] & V_108 -> F_23 ) )
continue;
V_87 = F_67 ( V_2 , V_4 , V_14 ,
V_112 , V_84 , V_6 ,
V_108 ) ;
if ( V_87 )
return V_87 ;
V_84 ++ ;
}
V_108 ++ ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_84 = 1 ;
int V_6 ;
int V_87 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_29 ; V_6 ++ ) {
int V_140 ;
for ( V_140 = 0 ; V_140 < F_32 ( V_141 ) ; V_140 ++ ) {
int V_82 ;
if ( ! ( V_14 -> F_23 [ V_6 ] & V_142 [ V_140 ] ) )
break;
if ( ! F_26 ( V_2 , V_6 ,
V_141 [ V_140 ] ) )
break;
V_82 = F_18 ( V_2 , V_6 ,
V_143 [ V_140 ] ) ;
if ( V_82 < 0 ||
( ! ( V_82 & ( V_144 >> ( ( V_140 & 1 ) * 4 ) ) ) ) )
continue;
if ( F_64 ( V_4 , L_10 , L_8 , V_84 ,
V_6 , V_141 [ V_140 ] ,
V_66 , true , true ) == NULL )
return - V_110 ;
if ( ( V_14 -> F_23 [ V_6 ] & V_145 [ V_140 ] ) &&
F_25 ( V_2 ,
V_6 , V_146 [ V_140 ] ) ) {
int V_51 ;
if ( V_140 > 1 )
V_51 = V_147 + V_6 ;
else
V_51 = V_148 + V_6 ;
V_87 = F_62 ( V_4 , L_10 ,
L_9 , V_84 , NULL , NULL , V_51 ,
V_149 >> ( V_140 & 1 ) ) ;
if ( V_87 )
return V_87 ;
V_87 = F_62 ( V_4 , L_10 ,
L_11 , V_84 , NULL , NULL , V_51 ,
V_150 >> ( V_140 & 1 ) ) ;
if ( V_87 )
return V_87 ;
}
V_84 ++ ;
}
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_87 ;
V_87 = F_68 ( V_2 , V_4 , L_12 , V_151 ,
F_32 ( V_151 ) ) ;
if ( V_87 )
return V_87 ;
V_87 = F_68 ( V_2 , V_4 , L_13 , V_152 ,
F_32 ( V_152 ) ) ;
if ( V_87 )
return V_87 ;
V_87 = F_68 ( V_2 , V_4 , L_14 , V_153 ,
F_32 ( V_153 ) ) ;
if ( V_87 )
return V_87 ;
V_87 = F_68 ( V_2 , V_4 , L_15 , V_154 ,
F_32 ( V_154 ) ) ;
if ( V_87 )
return V_87 ;
V_87 = F_69 ( V_2 , V_4 ) ;
return V_87 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_6 )
{
int V_155 = - 1 ;
if ( F_25 ( V_2 , V_6 , V_156 ) )
V_155 = F_18 ( V_2 , V_6 ,
V_156 ) ;
if ( V_155 >= 0 && V_155 != 0xff ) {
switch ( V_155 >> 5 ) {
case 0 :
if ( V_4 -> V_14 -> V_75 [ V_65 ] != V_78 )
return - V_157 ;
V_4 -> V_61 [ V_6 ] = ( ( V_158 ) ( V_155 << 3 ) ) >> 3 ;
break;
case 1 :
if ( V_4 -> V_14 -> V_75 [ V_65 ] != V_77 )
return - V_157 ;
break;
case 2 :
if ( V_4 -> V_14 -> V_75 [ V_65 ] != V_76 )
return - V_157 ;
break;
default:
return - V_157 ;
}
}
F_19 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , int V_6 )
{
return F_18 ( V_2 , V_6 , V_159 ) ;
}
static int F_73 ( struct V_1 * V_2 , int V_6 )
{
return F_14 ( V_2 , V_6 , V_160 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
int V_6 , V_87 ;
V_4 -> V_31 = F_73 ;
V_87 = F_13 ( V_2 , V_160 ) ;
if ( V_87 < 0 || V_87 == 0xffff ) {
V_4 -> V_31 = F_72 ;
V_87 = F_5 ( V_2 , V_159 ) ;
if ( V_87 < 0 || V_87 == 0xff ) {
F_75 ( V_38 , L_16 ) ;
return - V_157 ;
}
} else {
V_4 -> V_138 = true ;
}
V_87 = F_5 ( V_2 , V_161 ) ;
if ( V_87 >= 0 && ( V_87 & V_162 ) )
V_2 -> V_35 |= V_163 ;
F_20 ( V_2 ) ;
if ( V_14 -> V_164 ) {
V_87 = (* V_14 -> V_164 )( V_2 , V_14 ) ;
if ( V_87 < 0 ) {
F_75 ( V_38 , L_17 ) ;
return V_87 ;
}
}
if ( V_14 -> V_29 <= 0 || V_14 -> V_29 > V_165 ) {
F_75 ( V_38 , L_18 , V_14 -> V_29 ) ;
return - V_157 ;
}
for ( V_6 = 0 ; V_6 < V_14 -> V_29 ; V_6 ++ ) {
V_87 = F_71 ( V_2 , V_4 , V_6 ) ;
if ( V_87 < 0 ) {
F_75 ( V_38 , L_19 ) ;
return V_87 ;
}
}
return 0 ;
}
static int F_76 ( struct V_166 * V_167 )
{
struct V_37 * V_38 = F_77 ( V_167 ) ;
struct V_1 * V_2 = F_29 ( V_38 -> V_39 ) ;
T_1 V_6 = F_78 ( V_167 ) ;
int V_87 ;
V_87 = F_15 ( V_2 , V_6 , V_168 ) ;
if ( V_87 < 0 )
return V_87 ;
return ! ! ( V_87 & V_169 ) ;
}
static int F_79 ( struct V_166 * V_167 , bool V_170 )
{
struct V_37 * V_38 = F_77 ( V_167 ) ;
struct V_1 * V_2 = F_29 ( V_38 -> V_39 ) ;
T_1 V_6 = F_78 ( V_167 ) ;
return F_17 ( V_2 , V_6 , V_168 ,
V_169 ,
V_170 ? V_169 : 0 ) ;
}
static int F_80 ( struct V_166 * V_167 )
{
return F_79 ( V_167 , 1 ) ;
}
static int F_81 ( struct V_166 * V_167 )
{
return F_79 ( V_167 , 0 ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_37 * V_38 = V_4 -> V_38 ;
const struct V_13 * V_14 = V_4 -> V_14 ;
const struct V_171 * V_172 = F_83 ( V_38 ) ;
struct V_166 * V_167 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_173 ; V_28 ++ ) {
struct V_174 V_175 = { } ;
V_175 . V_38 = V_38 ;
V_175 . V_176 = V_4 ;
if ( V_172 && V_172 -> V_177 )
V_175 . V_178 = & V_172 -> V_177 [ V_28 ] ;
V_167 = F_84 ( V_38 , & V_14 -> V_179 [ V_28 ] ,
& V_175 ) ;
if ( F_85 ( V_167 ) ) {
F_75 ( V_38 , L_20 ,
V_14 -> V_179 [ V_28 ] . V_112 ) ;
return F_86 ( V_167 ) ;
}
}
return 0 ;
}
static int F_82 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_87 ( void * V_4 , T_8 * V_63 )
{
int V_180 ;
struct V_181 * V_182 = V_4 ;
V_180 = F_18 ( V_182 -> V_2 , V_182 -> V_6 , V_182 -> V_18 ) ;
if ( V_180 < 0 )
return V_180 ;
* V_63 = V_180 ;
return 0 ;
}
static int F_88 ( void * V_4 , T_8 * V_63 )
{
int V_180 ;
struct V_181 * V_182 = V_4 ;
struct V_3 * V_172 = F_2 ( V_182 -> V_2 ) ;
V_180 = V_172 -> V_31 ( V_182 -> V_2 , V_182 -> V_6 ) ;
if ( V_180 < 0 )
return V_180 ;
* V_63 = V_180 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_28 , V_115 = 0 ;
char V_112 [ V_183 ] ;
struct V_181 * V_184 ;
if ( ! V_185 )
return - V_157 ;
V_4 -> V_186 = F_90 ( F_91 ( V_4 -> V_187 ) ,
V_185 ) ;
if ( F_92 ( V_4 -> V_186 ) ) {
V_4 -> V_186 = NULL ;
return - V_157 ;
}
V_184 = F_63 ( V_4 -> V_38 ,
sizeof( * V_184 ) * ( V_4 -> V_14 -> V_29 * 10 ) ,
V_109 ) ;
if ( ! V_184 )
return - V_110 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_14 -> V_29 ; ++ V_28 ) {
if ( ! V_28 || F_24 ( V_2 , V_28 ) ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
F_93 ( V_112 , V_183 , L_21 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_188 ) ;
}
if ( V_4 -> V_14 -> F_23 [ V_28 ] & V_189 ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_190 ;
F_93 ( V_112 , V_183 , L_22 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( V_4 -> V_14 -> F_23 [ V_28 ] & V_192 ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_193 ;
F_93 ( V_112 , V_183 , L_23 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( V_4 -> V_14 -> F_23 [ V_28 ] & V_52 ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_54 ;
F_93 ( V_112 , V_183 , L_24 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( V_4 -> V_14 -> F_23 [ V_28 ] & V_194 ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_195 ;
F_93 ( V_112 , V_183 , L_25 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( F_25 ( V_2 , V_28 , V_33 ) ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_33 ;
F_93 ( V_112 , V_183 , L_26 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( F_25 ( V_2 , V_28 , V_196 ) ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_196 ;
F_93 ( V_112 , V_183 , L_27 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( F_25 ( V_2 , V_28 ,
V_197 ) ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_197 ;
F_93 ( V_112 , V_183 , L_28 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( V_4 -> V_14 -> F_23 [ V_28 ] & V_198 ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_199 ;
F_93 ( V_112 , V_183 , L_29 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
if ( V_4 -> V_14 -> F_23 [ V_28 ] & V_200 ) {
V_184 [ V_115 ] . V_2 = V_2 ;
V_184 [ V_115 ] . V_6 = V_28 ;
V_184 [ V_115 ] . V_18 = V_201 ;
F_93 ( V_112 , V_183 , L_30 , V_28 ) ;
F_94 ( V_112 , 0444 , V_4 -> V_186 ,
& V_184 [ V_115 ++ ] ,
& V_191 ) ;
}
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
int F_95 ( struct V_1 * V_2 , const struct V_202 * V_203 ,
struct V_13 * V_14 )
{
struct V_37 * V_38 = & V_2 -> V_38 ;
const struct V_171 * V_172 = F_83 ( V_38 ) ;
struct V_3 * V_4 ;
int V_87 ;
if ( ! V_14 )
return - V_157 ;
if ( ! F_96 ( V_2 -> V_204 , V_205
| V_206
| V_207 ) )
return - V_157 ;
V_4 = F_63 ( V_38 , sizeof( * V_4 ) , V_109 ) ;
if ( ! V_4 )
return - V_110 ;
F_97 ( V_2 , V_4 ) ;
F_98 ( & V_4 -> V_42 ) ;
V_4 -> V_38 = V_38 ;
if ( V_172 )
V_4 -> V_35 = V_172 -> V_35 ;
V_4 -> V_14 = V_14 ;
V_87 = F_74 ( V_2 , V_4 , V_14 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_70 ( V_2 , V_4 ) ;
if ( V_87 )
goto V_208;
if ( ! V_4 -> V_102 ) {
F_75 ( V_38 , L_31 ) ;
V_87 = - V_157 ;
goto V_208;
}
V_4 -> V_209 [ 0 ] = & V_4 -> V_107 ;
V_4 -> V_187 = F_99 ( V_38 , V_2 -> V_112 ,
V_4 , V_4 -> V_209 ) ;
if ( F_85 ( V_4 -> V_187 ) ) {
V_87 = F_86 ( V_4 -> V_187 ) ;
F_75 ( V_38 , L_32 ) ;
goto V_208;
}
V_87 = F_82 ( V_4 ) ;
if ( V_87 )
goto V_210;
V_87 = F_89 ( V_2 , V_4 ) ;
if ( V_87 )
F_100 ( V_38 , L_33 ) ;
return 0 ;
V_210:
F_101 ( V_4 -> V_187 ) ;
V_208:
F_102 ( V_4 -> V_107 . V_108 ) ;
return V_87 ;
}
int F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_104 ( V_4 -> V_186 ) ;
F_101 ( V_4 -> V_187 ) ;
F_102 ( V_4 -> V_107 . V_108 ) ;
return 0 ;
}
static int T_9 F_105 ( void )
{
V_185 = F_90 ( L_34 , NULL ) ;
if ( F_85 ( V_185 ) )
V_185 = NULL ;
return 0 ;
}
static void T_10 F_106 ( void )
{
F_104 ( V_185 ) ;
}
