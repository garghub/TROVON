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
static int F_16 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 -> V_24 ) {
V_15 = V_14 -> V_24 ( V_2 , V_6 , V_18 ) ;
if ( V_15 != - V_17 )
return V_15 ;
}
return F_15 ( V_2 , V_6 , V_18 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_6 )
{
F_8 ( V_2 , V_6 , V_25 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_14 -> V_27 ; V_26 ++ )
F_17 ( V_2 , V_26 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 , V_28 ;
V_15 = F_16 ( V_2 , - 1 , V_4 -> V_29 ) ;
if ( V_15 < 0 || ( V_15 & V_30 ) ) {
V_28 = F_16 ( V_2 , - 1 , V_31 ) ;
if ( V_28 < 0 || ( V_28 & V_32 ) )
return - V_11 ;
}
return 0 ;
}
static bool F_20 ( struct V_1 * V_2 ,
int (* F_21)( struct V_1 * V_2 ,
int V_6 , int V_18 ) ,
int V_6 , int V_18 )
{
int V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_7 = F_21 ( V_2 , V_6 , V_18 ) ;
if ( V_7 >= 0 && ! ( V_4 -> V_33 & V_34 ) )
V_7 = F_19 ( V_2 ) ;
F_17 ( V_2 , - 1 ) ;
return V_7 >= 0 ;
}
bool F_22 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
return F_20 ( V_2 , F_16 , V_6 , V_18 ) ;
}
bool F_23 ( struct V_1 * V_2 , int V_6 , int V_18 )
{
return F_20 ( V_2 , F_14 , V_6 , V_18 ) ;
}
const struct V_13 * F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_14 ;
}
static struct V_3 * F_25 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_26 ( V_36 -> V_37 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
struct V_38 * V_39 ;
F_27 ( & V_4 -> V_40 ) ;
if ( F_28 ( V_41 , V_4 -> V_42 + V_43 ) || ! V_4 -> V_5 ) {
int V_26 , V_44 ;
for ( V_26 = 0 ; V_26 < V_14 -> V_27 ; V_26 ++ ) {
V_4 -> V_15 [ V_45 + V_26 ]
= F_16 ( V_2 , V_26 ,
V_4 -> V_29 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_46 ) ; V_44 ++ ) {
struct V_47 * V_48 = & V_46 [ V_44 ] ;
if ( ! ( V_14 -> F_21 [ V_26 ] & V_48 -> F_21 ) )
continue;
V_4 -> V_15 [ V_48 -> V_49 + V_26 ]
= F_16 ( V_2 , V_26 ,
V_48 -> V_18 ) ;
}
}
if ( V_14 -> F_21 [ 0 ] & V_50 )
V_4 -> V_15 [ V_51 ]
= F_16 ( V_2 , 0 ,
V_52 ) ;
if ( V_14 -> F_21 [ 0 ] & V_53 )
V_4 -> V_15 [ V_54 ]
= F_16 ( V_2 , 0 ,
V_55 ) ;
for ( V_39 = V_4 -> V_56 ; V_39 ; V_39 = V_39 -> V_57 ) {
if ( ! V_4 -> V_5 || V_39 -> V_58 )
V_39 -> V_4
= F_14 ( V_2 ,
V_39 -> V_6 ,
V_39 -> V_18 ) ;
}
F_18 ( V_2 ) ;
V_4 -> V_42 = V_41 ;
V_4 -> V_5 = 1 ;
}
F_30 ( & V_4 -> V_40 ) ;
return V_4 ;
}
static long F_31 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
T_3 V_59 ;
T_4 V_60 ;
long V_61 ;
if ( V_39 -> V_62 == V_63 ) {
V_59 = V_4 -> V_59 ;
V_60 = ( T_2 ) V_39 -> V_4 ;
} else {
V_59 = ( ( T_3 ) V_39 -> V_4 ) >> 11 ;
V_60 = ( ( T_3 ) ( ( V_39 -> V_4 & 0x7ff ) << 5 ) ) >> 5 ;
}
V_61 = V_60 ;
if ( V_39 -> V_62 != V_64 )
V_61 = V_61 * 1000L ;
if ( V_39 -> V_62 == V_65 )
V_61 = V_61 * 1000L ;
if ( V_59 >= 0 )
V_61 <<= V_59 ;
else
V_61 >>= - V_59 ;
return V_61 ;
}
static long F_32 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
long V_61 = ( T_3 ) V_39 -> V_4 ;
long V_66 , V_67 , V_68 ;
V_66 = V_4 -> V_14 -> V_66 [ V_39 -> V_62 ] ;
V_67 = V_4 -> V_14 -> V_67 [ V_39 -> V_62 ] ;
V_68 = V_4 -> V_14 -> V_68 [ V_39 -> V_62 ] ;
if ( V_66 == 0 )
return 0 ;
V_68 = - V_68 ;
if ( V_39 -> V_62 != V_64 ) {
V_68 += 3 ;
V_67 *= 1000 ;
}
if ( V_39 -> V_62 == V_65 ) {
V_68 += 3 ;
V_67 *= 1000 ;
}
while ( V_68 > 0 ) {
V_61 *= 10 ;
V_68 -- ;
}
while ( V_68 < 0 ) {
V_61 = F_33 ( V_61 , 10 ) ;
V_68 ++ ;
}
return ( V_61 - V_67 ) / V_66 ;
}
static long F_34 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
long V_61 = V_39 -> V_4 ;
if ( V_61 < 0x02 || V_61 > 0xb2 )
return 0 ;
return F_33 ( 160000 - ( V_61 - 2 ) * 625 , 100 ) ;
}
static long F_35 ( struct V_3 * V_4 , struct V_38 * V_39 )
{
long V_61 ;
switch ( V_4 -> V_14 -> V_69 [ V_39 -> V_62 ] ) {
case V_70 :
V_61 = F_32 ( V_4 , V_39 ) ;
break;
case V_71 :
V_61 = F_34 ( V_4 , V_39 ) ;
break;
case V_72 :
default:
V_61 = F_31 ( V_4 , V_39 ) ;
break;
}
return V_61 ;
}
static T_2 F_36 ( struct V_3 * V_4 ,
enum V_73 V_62 , long V_61 )
{
T_3 V_59 = 0 , V_60 ;
bool V_74 = false ;
if ( V_61 == 0 )
return 0 ;
if ( V_62 == V_63 ) {
if ( V_61 < 0 )
return 0 ;
if ( V_4 -> V_59 < 0 )
V_61 <<= - V_4 -> V_59 ;
else
V_61 >>= V_4 -> V_59 ;
V_61 = F_33 ( V_61 , 1000 ) ;
return V_61 & 0xffff ;
}
if ( V_61 < 0 ) {
V_74 = true ;
V_61 = - V_61 ;
}
if ( V_62 == V_65 )
V_61 = F_33 ( V_61 , 1000L ) ;
if ( V_62 == V_64 )
V_61 = V_61 * 1000 ;
while ( V_61 >= V_75 && V_59 < 15 ) {
V_59 ++ ;
V_61 >>= 1 ;
}
while ( V_61 < V_76 && V_59 > - 15 ) {
V_59 -- ;
V_61 <<= 1 ;
}
V_60 = F_33 ( V_61 , 1000 ) ;
if ( V_60 > 0x3ff )
V_60 = 0x3ff ;
if ( V_74 )
V_60 = - V_60 ;
return ( V_60 & 0x7ff ) | ( ( V_59 << 11 ) & 0xf800 ) ;
}
static T_2 F_37 ( struct V_3 * V_4 ,
enum V_73 V_62 , long V_61 )
{
long V_66 , V_67 , V_68 ;
V_66 = V_4 -> V_14 -> V_66 [ V_62 ] ;
V_67 = V_4 -> V_14 -> V_67 [ V_62 ] ;
V_68 = V_4 -> V_14 -> V_68 [ V_62 ] ;
if ( V_62 == V_65 ) {
V_68 -= 3 ;
V_67 *= 1000 ;
}
if ( V_62 != V_64 ) {
V_68 -= 3 ;
V_67 *= 1000 ;
}
V_61 = V_61 * V_66 + V_67 ;
while ( V_68 > 0 ) {
V_61 *= 10 ;
V_68 -- ;
}
while ( V_68 < 0 ) {
V_61 = F_33 ( V_61 , 10 ) ;
V_68 ++ ;
}
return V_61 ;
}
static T_2 F_38 ( struct V_3 * V_4 ,
enum V_73 V_62 , long V_61 )
{
V_61 = F_39 ( V_61 , 500 , 1600 ) ;
return 2 + F_33 ( ( 1600 - V_61 ) * 100 , 625 ) ;
}
static T_2 F_40 ( struct V_3 * V_4 ,
enum V_73 V_62 , long V_61 )
{
T_2 V_77 ;
switch ( V_4 -> V_14 -> V_69 [ V_62 ] ) {
case V_70 :
V_77 = F_37 ( V_4 , V_62 , V_61 ) ;
break;
case V_71 :
V_77 = F_38 ( V_4 , V_62 , V_61 ) ;
break;
case V_72 :
default:
V_77 = F_36 ( V_4 , V_62 , V_61 ) ;
break;
}
return V_77 ;
}
static int F_41 ( struct V_3 * V_4 , struct V_78 * V_67 ,
int V_79 )
{
struct V_38 * V_80 = V_67 -> V_80 ;
struct V_38 * V_81 = V_67 -> V_81 ;
T_2 V_18 = ( V_79 >> 8 ) & 0xffff ;
T_1 V_82 = V_79 & 0xff ;
int V_83 , V_15 ;
T_1 V_77 ;
V_15 = V_4 -> V_15 [ V_18 ] ;
if ( V_15 < 0 )
return V_15 ;
V_77 = V_15 & V_82 ;
if ( ! V_80 && ! V_81 ) {
V_83 = ! ! V_77 ;
} else if ( ! V_80 || ! V_81 ) {
F_42 ( 1 , L_1 , V_67 , V_80 , V_81 ) ;
return 0 ;
} else {
long V_84 , V_85 ;
if ( V_80 -> V_4 < 0 )
return V_80 -> V_4 ;
if ( V_81 -> V_4 < 0 )
return V_81 -> V_4 ;
V_84 = F_35 ( V_4 , V_80 ) ;
V_85 = F_35 ( V_4 , V_81 ) ;
V_83 = ! ! ( V_77 && V_84 >= V_85 ) ;
}
return V_83 ;
}
static T_5 F_43 ( struct V_35 * V_36 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_89 * V_90 = F_44 ( V_87 ) ;
struct V_78 * boolean = F_45 ( V_90 ) ;
struct V_3 * V_4 = F_25 ( V_36 ) ;
int V_61 ;
V_61 = F_41 ( V_4 , boolean , V_90 -> V_79 ) ;
if ( V_61 < 0 )
return V_61 ;
return snprintf ( V_88 , V_91 , L_2 , V_61 ) ;
}
static T_5 F_46 ( struct V_35 * V_36 ,
struct V_86 * V_92 , char * V_88 )
{
struct V_3 * V_4 = F_25 ( V_36 ) ;
struct V_38 * V_39 = F_47 ( V_92 ) ;
if ( V_39 -> V_4 < 0 )
return V_39 -> V_4 ;
return snprintf ( V_88 , V_91 , L_3 , F_35 ( V_4 , V_39 ) ) ;
}
static T_5 F_48 ( struct V_35 * V_36 ,
struct V_86 * V_92 ,
const char * V_88 , T_6 V_93 )
{
struct V_1 * V_2 = F_26 ( V_36 -> V_37 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_38 * V_39 = F_47 ( V_92 ) ;
T_5 V_7 = V_93 ;
long V_61 = 0 ;
int V_83 ;
T_2 V_77 ;
if ( F_49 ( V_88 , 10 , & V_61 ) < 0 )
return - V_94 ;
F_27 ( & V_4 -> V_40 ) ;
V_77 = F_40 ( V_4 , V_39 -> V_62 , V_61 ) ;
V_83 = F_11 ( V_2 , V_39 -> V_6 , V_39 -> V_18 , V_77 ) ;
if ( V_83 < 0 )
V_7 = V_83 ;
else
V_39 -> V_4 = V_77 ;
F_30 ( & V_4 -> V_40 ) ;
return V_7 ;
}
static T_5 F_50 ( struct V_35 * V_36 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_95 * V_96 = F_51 ( V_87 ) ;
return snprintf ( V_88 , V_91 , L_4 , V_96 -> V_96 ) ;
}
static int F_52 ( struct V_3 * V_4 , struct V_97 * V_90 )
{
if ( V_4 -> V_98 >= V_4 -> V_99 - 1 ) {
int V_100 = V_4 -> V_99 + V_101 ;
void * V_102 = F_53 ( V_4 -> V_103 . V_104 ,
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
static void F_54 ( struct V_86 * V_107 ,
const char * V_108 ,
T_7 V_109 ,
T_5 (* F_55)( struct V_35 * V_36 ,
struct V_86 * V_90 ,
char * V_88 ) ,
T_5 (* F_56)( struct V_35 * V_36 ,
struct V_86 * V_90 ,
const char * V_88 , T_6 V_93 ) )
{
F_57 ( & V_107 -> V_90 ) ;
V_107 -> V_90 . V_108 = V_108 ;
V_107 -> V_90 . V_109 = V_109 ;
V_107 -> F_55 = F_55 ;
V_107 -> F_56 = F_56 ;
}
static void F_58 ( struct V_89 * V_110 ,
const char * V_108 ,
T_7 V_109 ,
T_5 (* F_55)( struct V_35 * V_36 ,
struct V_86 * V_90 ,
char * V_88 ) ,
T_5 (* F_56)( struct V_35 * V_36 ,
struct V_86 * V_90 ,
const char * V_88 , T_6 V_93 ) ,
int V_111 )
{
F_54 ( & V_110 -> V_107 , V_108 , V_109 , F_55 , F_56 ) ;
V_110 -> V_79 = V_111 ;
}
static int F_59 ( struct V_3 * V_4 ,
const char * V_108 , const char * type , int V_112 ,
struct V_38 * V_80 ,
struct V_38 * V_81 ,
T_2 V_18 , T_1 V_82 )
{
struct V_78 * boolean ;
struct V_89 * V_110 ;
boolean = F_60 ( V_4 -> V_36 , sizeof( * boolean ) , V_105 ) ;
if ( ! boolean )
return - V_106 ;
V_110 = & boolean -> V_97 ;
snprintf ( boolean -> V_108 , sizeof( boolean -> V_108 ) , L_5 ,
V_108 , V_112 , type ) ;
boolean -> V_80 = V_80 ;
boolean -> V_81 = V_81 ;
F_58 ( V_110 , boolean -> V_108 , V_113 , F_43 , NULL ,
( V_18 << 8 ) | V_82 ) ;
return F_52 ( V_4 , & V_110 -> V_107 . V_90 ) ;
}
static struct V_38 * F_61 ( struct V_3 * V_4 ,
const char * V_108 , const char * type ,
int V_112 , int V_6 , int V_18 ,
enum V_73 V_62 ,
bool V_58 , bool V_114 )
{
struct V_38 * V_39 ;
struct V_86 * V_110 ;
V_39 = F_60 ( V_4 -> V_36 , sizeof( * V_39 ) , V_105 ) ;
if ( ! V_39 )
return NULL ;
V_110 = & V_39 -> V_97 ;
snprintf ( V_39 -> V_108 , sizeof( V_39 -> V_108 ) , L_5 ,
V_108 , V_112 , type ) ;
V_39 -> V_6 = V_6 ;
V_39 -> V_18 = V_18 ;
V_39 -> V_62 = V_62 ;
V_39 -> V_58 = V_58 ;
F_54 ( V_110 , V_39 -> V_108 ,
V_114 ? V_113 : V_113 | V_115 ,
F_46 , F_48 ) ;
if ( F_52 ( V_4 , & V_110 -> V_90 ) )
return NULL ;
V_39 -> V_57 = V_4 -> V_56 ;
V_4 -> V_56 = V_39 ;
return V_39 ;
}
static int F_62 ( struct V_3 * V_4 ,
const char * V_108 , int V_112 ,
const char * V_116 , int V_79 )
{
struct V_95 * V_96 ;
struct V_86 * V_110 ;
V_96 = F_60 ( V_4 -> V_36 , sizeof( * V_96 ) , V_105 ) ;
if ( ! V_96 )
return - V_106 ;
V_110 = & V_96 -> V_97 ;
snprintf ( V_96 -> V_108 , sizeof( V_96 -> V_108 ) , L_6 , V_108 , V_112 ) ;
if ( ! V_79 )
strncpy ( V_96 -> V_96 , V_116 , sizeof( V_96 -> V_96 ) - 1 ) ;
else
snprintf ( V_96 -> V_96 , sizeof( V_96 -> V_96 ) , L_7 , V_116 ,
V_79 ) ;
F_54 ( V_110 , V_96 -> V_108 , V_113 , F_50 , NULL ) ;
return F_52 ( V_4 , & V_110 -> V_90 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_108 , int V_79 , int V_6 ,
struct V_38 * V_49 ,
const struct V_117 * V_90 )
{
const struct V_118 * V_119 = V_90 -> V_120 ;
int V_121 = V_90 -> V_121 ;
int V_122 = 0 ;
int V_26 , V_83 ;
struct V_38 * V_123 ;
for ( V_26 = 0 ; V_26 < V_121 ; V_26 ++ ) {
if ( F_23 ( V_2 , V_6 , V_119 -> V_18 ) ) {
V_123 = F_61 ( V_4 , V_108 , V_119 -> V_90 , V_79 ,
V_6 , V_119 -> V_18 , V_90 -> V_62 ,
V_90 -> V_58 || V_119 -> V_58 ,
false ) ;
if ( ! V_123 )
return - V_106 ;
if ( V_119 -> V_124 && ( V_14 -> F_21 [ V_6 ] & V_90 -> V_125 ) ) {
V_83 = F_59 ( V_4 , V_108 ,
V_119 -> V_126 , V_79 ,
V_90 -> V_127 ? V_119 -> V_128 ? V_123 : V_49
: NULL ,
V_90 -> V_127 ? V_119 -> V_128 ? V_49 : V_123
: NULL ,
V_90 -> V_129 + V_6 , V_119 -> V_124 ) ;
if ( V_83 )
return V_83 ;
V_122 = 1 ;
}
}
V_119 ++ ;
}
return V_122 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_108 ,
int V_79 , int V_6 ,
const struct V_117 * V_90 )
{
struct V_38 * V_49 ;
int V_83 ;
if ( V_90 -> V_96 ) {
V_83 = F_62 ( V_4 , V_108 , V_79 , V_90 -> V_96 ,
V_90 -> V_130 ? V_6 + 1 : 0 ) ;
if ( V_83 )
return V_83 ;
}
V_49 = F_61 ( V_4 , V_108 , L_8 , V_79 , V_6 , V_90 -> V_18 ,
V_90 -> V_62 , true , true ) ;
if ( ! V_49 )
return - V_106 ;
if ( V_90 -> V_125 ) {
V_83 = F_63 ( V_2 , V_4 , V_14 , V_108 ,
V_79 , V_6 , V_49 , V_90 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( ! V_83 && V_90 -> V_131 &&
F_22 ( V_2 , V_6 ,
V_4 -> V_29 ) ) {
V_83 = F_59 ( V_4 , V_108 , L_9 , V_79 ,
NULL , NULL ,
V_45 + V_6 ,
V_90 -> V_131 ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_108 ,
const struct V_117 * V_104 ,
int V_132 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_79 , V_26 ;
int V_83 ;
V_79 = 1 ;
for ( V_26 = 0 ; V_26 < V_132 ; V_26 ++ ) {
int V_6 , V_27 ;
V_27 = V_104 -> V_130 ? V_14 -> V_27 : 1 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
if ( ! ( V_14 -> F_21 [ V_6 ] & V_104 -> F_21 ) )
continue;
V_83 = F_64 ( V_2 , V_4 , V_14 ,
V_108 , V_79 , V_6 ,
V_104 ) ;
if ( V_83 )
return V_83 ;
V_79 ++ ;
}
V_104 ++ ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_79 = 1 ;
int V_6 ;
int V_83 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_27 ; V_6 ++ ) {
int V_133 ;
for ( V_133 = 0 ; V_133 < F_29 ( V_134 ) ; V_133 ++ ) {
int V_77 ;
if ( ! ( V_14 -> F_21 [ V_6 ] & V_135 [ V_133 ] ) )
break;
if ( ! F_23 ( V_2 , V_6 ,
V_134 [ V_133 ] ) )
break;
V_77 = F_16 ( V_2 , V_6 ,
V_136 [ V_133 ] ) ;
if ( V_77 < 0 ||
( ! ( V_77 & ( V_137 >> ( ( V_133 & 1 ) * 4 ) ) ) ) )
continue;
if ( F_61 ( V_4 , L_10 , L_8 , V_79 ,
V_6 , V_134 [ V_133 ] ,
V_64 , true , true ) == NULL )
return - V_106 ;
if ( ( V_14 -> F_21 [ V_6 ] & V_138 [ V_133 ] ) &&
F_22 ( V_2 ,
V_6 , V_139 [ V_133 ] ) ) {
int V_49 ;
if ( V_133 > 1 )
V_49 = V_140 + V_6 ;
else
V_49 = V_141 + V_6 ;
V_83 = F_59 ( V_4 , L_10 ,
L_9 , V_79 , NULL , NULL , V_49 ,
V_142 >> ( V_133 & 1 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_59 ( V_4 , L_10 ,
L_11 , V_79 , NULL , NULL , V_49 ,
V_143 >> ( V_133 & 1 ) ) ;
if ( V_83 )
return V_83 ;
}
V_79 ++ ;
}
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_83 ;
V_83 = F_65 ( V_2 , V_4 , L_12 , V_144 ,
F_29 ( V_144 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_65 ( V_2 , V_4 , L_13 , V_145 ,
F_29 ( V_145 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_65 ( V_2 , V_4 , L_14 , V_146 ,
F_29 ( V_146 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_65 ( V_2 , V_4 , L_15 , V_147 ,
F_29 ( V_147 ) ) ;
if ( V_83 )
return V_83 ;
V_83 = F_66 ( V_2 , V_4 ) ;
return V_83 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_148 = - 1 ;
if ( F_22 ( V_2 , 0 , V_149 ) )
V_148 = F_16 ( V_2 , 0 , V_149 ) ;
if ( V_148 >= 0 && V_148 != 0xff ) {
switch ( V_148 >> 5 ) {
case 0 :
if ( V_4 -> V_14 -> V_69 [ V_63 ] != V_72 )
return - V_150 ;
V_4 -> V_59 = ( ( V_151 ) ( V_148 << 3 ) ) >> 3 ;
break;
case 1 :
if ( V_4 -> V_14 -> V_69 [ V_63 ] != V_71 )
return - V_150 ;
break;
case 2 :
if ( V_4 -> V_14 -> V_69 [ V_63 ] != V_70 )
return - V_150 ;
break;
default:
return - V_150 ;
}
}
F_17 ( V_2 , 0 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_35 * V_36 = & V_2 -> V_36 ;
int V_83 ;
V_4 -> V_29 = V_152 ;
V_83 = F_5 ( V_2 , V_152 ) ;
if ( V_83 < 0 || V_83 == 0xff ) {
V_4 -> V_29 = V_153 ;
V_83 = F_13 ( V_2 , V_153 ) ;
if ( V_83 < 0 || V_83 == 0xffff ) {
F_70 ( V_36 , L_16 ) ;
return - V_150 ;
}
}
F_18 ( V_2 ) ;
if ( V_14 -> V_154 ) {
V_83 = (* V_14 -> V_154 )( V_2 , V_14 ) ;
if ( V_83 < 0 ) {
F_70 ( V_36 , L_17 ) ;
return V_83 ;
}
}
if ( V_14 -> V_27 <= 0 || V_14 -> V_27 > V_155 ) {
F_70 ( V_36 , L_18 , V_14 -> V_27 ) ;
return - V_150 ;
}
V_83 = F_68 ( V_2 , V_4 ) ;
if ( V_83 < 0 ) {
F_70 ( V_36 , L_19 ) ;
return V_83 ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_2 , const struct V_156 * V_157 ,
struct V_13 * V_14 )
{
struct V_35 * V_36 = & V_2 -> V_36 ;
const struct V_158 * V_159 = F_72 ( V_36 ) ;
struct V_3 * V_4 ;
int V_83 ;
if ( ! V_14 )
return - V_150 ;
if ( ! F_73 ( V_2 -> V_160 , V_161
| V_162
| V_163 ) )
return - V_150 ;
V_4 = F_60 ( V_36 , sizeof( * V_4 ) , V_105 ) ;
if ( ! V_4 )
return - V_106 ;
F_74 ( V_2 , V_4 ) ;
F_75 ( & V_4 -> V_40 ) ;
V_4 -> V_36 = V_36 ;
if ( V_159 )
V_4 -> V_33 = V_159 -> V_33 ;
V_4 -> V_14 = V_14 ;
V_83 = F_69 ( V_2 , V_4 , V_14 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_67 ( V_2 , V_4 ) ;
if ( V_83 )
goto V_164;
if ( ! V_4 -> V_98 ) {
F_70 ( V_36 , L_20 ) ;
V_83 = - V_150 ;
goto V_164;
}
V_4 -> V_165 [ 0 ] = & V_4 -> V_103 ;
V_4 -> V_166 = F_76 ( V_36 , V_2 -> V_108 ,
V_4 , V_4 -> V_165 ) ;
if ( F_77 ( V_4 -> V_166 ) ) {
V_83 = F_78 ( V_4 -> V_166 ) ;
F_70 ( V_36 , L_21 ) ;
goto V_164;
}
return 0 ;
V_164:
F_79 ( V_4 -> V_103 . V_104 ) ;
return V_83 ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_81 ( V_4 -> V_166 ) ;
F_79 ( V_4 -> V_103 . V_104 ) ;
return 0 ;
}
