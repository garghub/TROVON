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
struct V_1 * V_2 = F_26 ( V_36 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = V_4 -> V_14 ;
struct V_37 * V_38 ;
F_27 ( & V_4 -> V_39 ) ;
if ( F_28 ( V_40 , V_4 -> V_41 + V_42 ) || ! V_4 -> V_5 ) {
int V_26 , V_43 ;
for ( V_26 = 0 ; V_26 < V_14 -> V_27 ; V_26 ++ ) {
V_4 -> V_15 [ V_44 + V_26 ]
= F_16 ( V_2 , V_26 ,
V_4 -> V_29 ) ;
for ( V_43 = 0 ; V_43 < F_29 ( V_45 ) ; V_43 ++ ) {
struct V_46 * V_47 = & V_45 [ V_43 ] ;
if ( ! ( V_14 -> F_21 [ V_26 ] & V_47 -> F_21 ) )
continue;
V_4 -> V_15 [ V_47 -> V_48 + V_26 ]
= F_16 ( V_2 , V_26 ,
V_47 -> V_18 ) ;
}
}
if ( V_14 -> F_21 [ 0 ] & V_49 )
V_4 -> V_15 [ V_50 ]
= F_16 ( V_2 , 0 ,
V_51 ) ;
if ( V_14 -> F_21 [ 0 ] & V_52 )
V_4 -> V_15 [ V_53 ]
= F_16 ( V_2 , 0 ,
V_54 ) ;
for ( V_38 = V_4 -> V_55 ; V_38 ; V_38 = V_38 -> V_56 ) {
if ( ! V_4 -> V_5 || V_38 -> V_57 )
V_38 -> V_4
= F_14 ( V_2 ,
V_38 -> V_6 ,
V_38 -> V_18 ) ;
}
F_18 ( V_2 ) ;
V_4 -> V_41 = V_40 ;
V_4 -> V_5 = 1 ;
}
F_30 ( & V_4 -> V_39 ) ;
return V_4 ;
}
static long F_31 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
T_3 V_58 ;
T_4 V_59 ;
long V_60 ;
if ( V_38 -> V_61 == V_62 ) {
V_58 = V_4 -> V_58 ;
V_59 = ( T_2 ) V_38 -> V_4 ;
} else {
V_58 = ( ( T_3 ) V_38 -> V_4 ) >> 11 ;
V_59 = ( ( T_3 ) ( ( V_38 -> V_4 & 0x7ff ) << 5 ) ) >> 5 ;
}
V_60 = V_59 ;
if ( V_38 -> V_61 != V_63 )
V_60 = V_60 * 1000L ;
if ( V_38 -> V_61 == V_64 )
V_60 = V_60 * 1000L ;
if ( V_58 >= 0 )
V_60 <<= V_58 ;
else
V_60 >>= - V_58 ;
return V_60 ;
}
static long F_32 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
long V_60 = ( T_3 ) V_38 -> V_4 ;
long V_65 , V_66 , V_67 ;
V_65 = V_4 -> V_14 -> V_65 [ V_38 -> V_61 ] ;
V_66 = V_4 -> V_14 -> V_66 [ V_38 -> V_61 ] ;
V_67 = V_4 -> V_14 -> V_67 [ V_38 -> V_61 ] ;
if ( V_65 == 0 )
return 0 ;
V_67 = - V_67 ;
if ( V_38 -> V_61 != V_63 ) {
V_67 += 3 ;
V_66 *= 1000 ;
}
if ( V_38 -> V_61 == V_64 ) {
V_67 += 3 ;
V_66 *= 1000 ;
}
while ( V_67 > 0 ) {
V_60 *= 10 ;
V_67 -- ;
}
while ( V_67 < 0 ) {
V_60 = F_33 ( V_60 , 10 ) ;
V_67 ++ ;
}
return ( V_60 - V_66 ) / V_65 ;
}
static long F_34 ( struct V_3 * V_4 ,
struct V_37 * V_38 )
{
long V_60 = V_38 -> V_4 ;
if ( V_60 < 0x02 || V_60 > 0xb2 )
return 0 ;
return F_33 ( 160000 - ( V_60 - 2 ) * 625 , 100 ) ;
}
static long F_35 ( struct V_3 * V_4 , struct V_37 * V_38 )
{
long V_60 ;
switch ( V_4 -> V_14 -> V_68 [ V_38 -> V_61 ] ) {
case V_69 :
V_60 = F_32 ( V_4 , V_38 ) ;
break;
case V_70 :
V_60 = F_34 ( V_4 , V_38 ) ;
break;
case V_71 :
default:
V_60 = F_31 ( V_4 , V_38 ) ;
break;
}
return V_60 ;
}
static T_2 F_36 ( struct V_3 * V_4 ,
enum V_72 V_61 , long V_60 )
{
T_3 V_58 = 0 , V_59 ;
bool V_73 = false ;
if ( V_60 == 0 )
return 0 ;
if ( V_61 == V_62 ) {
if ( V_60 < 0 )
return 0 ;
if ( V_4 -> V_58 < 0 )
V_60 <<= - V_4 -> V_58 ;
else
V_60 >>= V_4 -> V_58 ;
V_60 = F_33 ( V_60 , 1000 ) ;
return V_60 & 0xffff ;
}
if ( V_60 < 0 ) {
V_73 = true ;
V_60 = - V_60 ;
}
if ( V_61 == V_64 )
V_60 = F_33 ( V_60 , 1000L ) ;
if ( V_61 == V_63 )
V_60 = V_60 * 1000 ;
while ( V_60 >= V_74 && V_58 < 15 ) {
V_58 ++ ;
V_60 >>= 1 ;
}
while ( V_60 < V_75 && V_58 > - 15 ) {
V_58 -- ;
V_60 <<= 1 ;
}
V_59 = F_33 ( V_60 , 1000 ) ;
if ( V_59 > 0x3ff )
V_59 = 0x3ff ;
if ( V_73 )
V_59 = - V_59 ;
return ( V_59 & 0x7ff ) | ( ( V_58 << 11 ) & 0xf800 ) ;
}
static T_2 F_37 ( struct V_3 * V_4 ,
enum V_72 V_61 , long V_60 )
{
long V_65 , V_66 , V_67 ;
V_65 = V_4 -> V_14 -> V_65 [ V_61 ] ;
V_66 = V_4 -> V_14 -> V_66 [ V_61 ] ;
V_67 = V_4 -> V_14 -> V_67 [ V_61 ] ;
if ( V_61 == V_64 ) {
V_67 -= 3 ;
V_66 *= 1000 ;
}
if ( V_61 != V_63 ) {
V_67 -= 3 ;
V_66 *= 1000 ;
}
V_60 = V_60 * V_65 + V_66 ;
while ( V_67 > 0 ) {
V_60 *= 10 ;
V_67 -- ;
}
while ( V_67 < 0 ) {
V_60 = F_33 ( V_60 , 10 ) ;
V_67 ++ ;
}
return V_60 ;
}
static T_2 F_38 ( struct V_3 * V_4 ,
enum V_72 V_61 , long V_60 )
{
V_60 = F_39 ( V_60 , 500 , 1600 ) ;
return 2 + F_33 ( ( 1600 - V_60 ) * 100 , 625 ) ;
}
static T_2 F_40 ( struct V_3 * V_4 ,
enum V_72 V_61 , long V_60 )
{
T_2 V_76 ;
switch ( V_4 -> V_14 -> V_68 [ V_61 ] ) {
case V_69 :
V_76 = F_37 ( V_4 , V_61 , V_60 ) ;
break;
case V_70 :
V_76 = F_38 ( V_4 , V_61 , V_60 ) ;
break;
case V_71 :
default:
V_76 = F_36 ( V_4 , V_61 , V_60 ) ;
break;
}
return V_76 ;
}
static int F_41 ( struct V_3 * V_4 , struct V_77 * V_66 ,
int V_78 )
{
struct V_37 * V_79 = V_66 -> V_79 ;
struct V_37 * V_80 = V_66 -> V_80 ;
T_2 V_18 = ( V_78 >> 8 ) & 0xffff ;
T_1 V_81 = V_78 & 0xff ;
int V_82 , V_15 ;
T_1 V_76 ;
V_15 = V_4 -> V_15 [ V_18 ] ;
if ( V_15 < 0 )
return V_15 ;
V_76 = V_15 & V_81 ;
if ( ! V_79 && ! V_80 ) {
V_82 = ! ! V_76 ;
} else if ( ! V_79 || ! V_80 ) {
F_42 () ;
return 0 ;
} else {
long V_83 , V_84 ;
if ( V_79 -> V_4 < 0 )
return V_79 -> V_4 ;
if ( V_80 -> V_4 < 0 )
return V_80 -> V_4 ;
V_83 = F_35 ( V_4 , V_79 ) ;
V_84 = F_35 ( V_4 , V_80 ) ;
V_82 = ! ! ( V_76 && V_83 >= V_84 ) ;
}
return V_82 ;
}
static T_5 F_43 ( struct V_35 * V_36 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_88 * V_89 = F_44 ( V_86 ) ;
struct V_77 * boolean = F_45 ( V_89 ) ;
struct V_3 * V_4 = F_25 ( V_36 ) ;
int V_60 ;
V_60 = F_41 ( V_4 , boolean , V_89 -> V_78 ) ;
if ( V_60 < 0 )
return V_60 ;
return snprintf ( V_87 , V_90 , L_1 , V_60 ) ;
}
static T_5 F_46 ( struct V_35 * V_36 ,
struct V_85 * V_91 , char * V_87 )
{
struct V_3 * V_4 = F_25 ( V_36 ) ;
struct V_37 * V_38 = F_47 ( V_91 ) ;
if ( V_38 -> V_4 < 0 )
return V_38 -> V_4 ;
return snprintf ( V_87 , V_90 , L_2 , F_35 ( V_4 , V_38 ) ) ;
}
static T_5 F_48 ( struct V_35 * V_36 ,
struct V_85 * V_91 ,
const char * V_87 , T_6 V_92 )
{
struct V_1 * V_2 = F_26 ( V_36 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_37 * V_38 = F_47 ( V_91 ) ;
T_5 V_7 = V_92 ;
long V_60 = 0 ;
int V_82 ;
T_2 V_76 ;
if ( F_49 ( V_87 , 10 , & V_60 ) < 0 )
return - V_93 ;
F_27 ( & V_4 -> V_39 ) ;
V_76 = F_40 ( V_4 , V_38 -> V_61 , V_60 ) ;
V_82 = F_11 ( V_2 , V_38 -> V_6 , V_38 -> V_18 , V_76 ) ;
if ( V_82 < 0 )
V_7 = V_82 ;
else
V_38 -> V_4 = V_76 ;
F_30 ( & V_4 -> V_39 ) ;
return V_7 ;
}
static T_5 F_50 ( struct V_35 * V_36 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_94 * V_95 = F_51 ( V_86 ) ;
return snprintf ( V_87 , V_90 , L_3 , V_95 -> V_95 ) ;
}
static int F_52 ( struct V_3 * V_4 , struct V_96 * V_89 )
{
if ( V_4 -> V_97 >= V_4 -> V_98 - 1 ) {
int V_99 = V_4 -> V_98 + V_100 ;
void * V_101 = F_53 ( V_4 -> V_102 . V_103 ,
V_99 * sizeof( void * ) ,
V_104 ) ;
if ( ! V_101 )
return - V_105 ;
V_4 -> V_102 . V_103 = V_101 ;
V_4 -> V_98 = V_99 ;
}
V_4 -> V_102 . V_103 [ V_4 -> V_97 ++ ] = V_89 ;
V_4 -> V_102 . V_103 [ V_4 -> V_97 ] = NULL ;
return 0 ;
}
static void F_54 ( struct V_85 * V_106 ,
const char * V_107 ,
T_7 V_108 ,
T_5 (* F_55)( struct V_35 * V_36 ,
struct V_85 * V_89 ,
char * V_87 ) ,
T_5 (* F_56)( struct V_35 * V_36 ,
struct V_85 * V_89 ,
const char * V_87 , T_6 V_92 ) )
{
F_57 ( & V_106 -> V_89 ) ;
V_106 -> V_89 . V_107 = V_107 ;
V_106 -> V_89 . V_108 = V_108 ;
V_106 -> F_55 = F_55 ;
V_106 -> F_56 = F_56 ;
}
static void F_58 ( struct V_88 * V_109 ,
const char * V_107 ,
T_7 V_108 ,
T_5 (* F_55)( struct V_35 * V_36 ,
struct V_85 * V_89 ,
char * V_87 ) ,
T_5 (* F_56)( struct V_35 * V_36 ,
struct V_85 * V_89 ,
const char * V_87 , T_6 V_92 ) ,
int V_110 )
{
F_54 ( & V_109 -> V_106 , V_107 , V_108 , F_55 , F_56 ) ;
V_109 -> V_78 = V_110 ;
}
static int F_59 ( struct V_3 * V_4 ,
const char * V_107 , const char * type , int V_111 ,
struct V_37 * V_79 ,
struct V_37 * V_80 ,
T_2 V_18 , T_1 V_81 )
{
struct V_77 * boolean ;
struct V_88 * V_109 ;
boolean = F_60 ( V_4 -> V_36 , sizeof( * boolean ) , V_104 ) ;
if ( ! boolean )
return - V_105 ;
V_109 = & boolean -> V_96 ;
snprintf ( boolean -> V_107 , sizeof( boolean -> V_107 ) , L_4 ,
V_107 , V_111 , type ) ;
boolean -> V_79 = V_79 ;
boolean -> V_80 = V_80 ;
F_58 ( V_109 , boolean -> V_107 , V_112 , F_43 , NULL ,
( V_18 << 8 ) | V_81 ) ;
return F_52 ( V_4 , & V_109 -> V_106 . V_89 ) ;
}
static struct V_37 * F_61 ( struct V_3 * V_4 ,
const char * V_107 , const char * type ,
int V_111 , int V_6 , int V_18 ,
enum V_72 V_61 ,
bool V_57 , bool V_113 )
{
struct V_37 * V_38 ;
struct V_85 * V_109 ;
V_38 = F_60 ( V_4 -> V_36 , sizeof( * V_38 ) , V_104 ) ;
if ( ! V_38 )
return NULL ;
V_109 = & V_38 -> V_96 ;
snprintf ( V_38 -> V_107 , sizeof( V_38 -> V_107 ) , L_4 ,
V_107 , V_111 , type ) ;
V_38 -> V_6 = V_6 ;
V_38 -> V_18 = V_18 ;
V_38 -> V_61 = V_61 ;
V_38 -> V_57 = V_57 ;
F_54 ( V_109 , V_38 -> V_107 ,
V_113 ? V_112 : V_112 | V_114 ,
F_46 , F_48 ) ;
if ( F_52 ( V_4 , & V_109 -> V_89 ) )
return NULL ;
V_38 -> V_56 = V_4 -> V_55 ;
V_4 -> V_55 = V_38 ;
return V_38 ;
}
static int F_62 ( struct V_3 * V_4 ,
const char * V_107 , int V_111 ,
const char * V_115 , int V_78 )
{
struct V_94 * V_95 ;
struct V_85 * V_109 ;
V_95 = F_60 ( V_4 -> V_36 , sizeof( * V_95 ) , V_104 ) ;
if ( ! V_95 )
return - V_105 ;
V_109 = & V_95 -> V_96 ;
snprintf ( V_95 -> V_107 , sizeof( V_95 -> V_107 ) , L_5 , V_107 , V_111 ) ;
if ( ! V_78 )
strncpy ( V_95 -> V_95 , V_115 , sizeof( V_95 -> V_95 ) - 1 ) ;
else
snprintf ( V_95 -> V_95 , sizeof( V_95 -> V_95 ) , L_6 , V_115 ,
V_78 ) ;
F_54 ( V_109 , V_95 -> V_107 , V_112 , F_50 , NULL ) ;
return F_52 ( V_4 , & V_109 -> V_89 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_107 , int V_78 , int V_6 ,
struct V_37 * V_48 ,
const struct V_116 * V_89 )
{
const struct V_117 * V_118 = V_89 -> V_119 ;
int V_120 = V_89 -> V_120 ;
int V_121 = 0 ;
int V_26 , V_82 ;
struct V_37 * V_122 ;
for ( V_26 = 0 ; V_26 < V_120 ; V_26 ++ ) {
if ( F_23 ( V_2 , V_6 , V_118 -> V_18 ) ) {
V_122 = F_61 ( V_4 , V_107 , V_118 -> V_89 , V_78 ,
V_6 , V_118 -> V_18 , V_89 -> V_61 ,
V_89 -> V_57 || V_118 -> V_57 ,
false ) ;
if ( ! V_122 )
return - V_105 ;
if ( V_118 -> V_123 && ( V_14 -> F_21 [ V_6 ] & V_89 -> V_124 ) ) {
V_82 = F_59 ( V_4 , V_107 ,
V_118 -> V_125 , V_78 ,
V_89 -> V_126 ? V_118 -> V_127 ? V_122 : V_48
: NULL ,
V_89 -> V_126 ? V_118 -> V_127 ? V_48 : V_122
: NULL ,
V_89 -> V_128 + V_6 , V_118 -> V_123 ) ;
if ( V_82 )
return V_82 ;
V_121 = 1 ;
}
}
V_118 ++ ;
}
return V_121 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_13 * V_14 ,
const char * V_107 ,
int V_78 , int V_6 ,
const struct V_116 * V_89 )
{
struct V_37 * V_48 ;
int V_82 ;
if ( V_89 -> V_95 ) {
V_82 = F_62 ( V_4 , V_107 , V_78 , V_89 -> V_95 ,
V_89 -> V_129 ? V_6 + 1 : 0 ) ;
if ( V_82 )
return V_82 ;
}
V_48 = F_61 ( V_4 , V_107 , L_7 , V_78 , V_6 , V_89 -> V_18 ,
V_89 -> V_61 , true , true ) ;
if ( ! V_48 )
return - V_105 ;
if ( V_89 -> V_124 ) {
V_82 = F_63 ( V_2 , V_4 , V_14 , V_107 ,
V_78 , V_6 , V_48 , V_89 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( ! V_82 && V_89 -> V_130 &&
F_22 ( V_2 , V_6 ,
V_4 -> V_29 ) ) {
V_82 = F_59 ( V_4 , V_107 , L_8 , V_78 ,
NULL , NULL ,
V_44 + V_6 ,
V_89 -> V_130 ) ;
if ( V_82 )
return V_82 ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_107 ,
const struct V_116 * V_103 ,
int V_131 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_78 , V_26 ;
int V_82 ;
V_78 = 1 ;
for ( V_26 = 0 ; V_26 < V_131 ; V_26 ++ ) {
int V_6 , V_27 ;
V_27 = V_103 -> V_129 ? V_14 -> V_27 : 1 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
if ( ! ( V_14 -> F_21 [ V_6 ] & V_103 -> F_21 ) )
continue;
V_82 = F_64 ( V_2 , V_4 , V_14 ,
V_107 , V_78 , V_6 ,
V_103 ) ;
if ( V_82 )
return V_82 ;
V_78 ++ ;
}
V_103 ++ ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_13 * V_14 = V_4 -> V_14 ;
int V_78 = 1 ;
int V_6 ;
int V_82 ;
for ( V_6 = 0 ; V_6 < V_14 -> V_27 ; V_6 ++ ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < F_29 ( V_133 ) ; V_132 ++ ) {
int V_76 ;
if ( ! ( V_14 -> F_21 [ V_6 ] & V_134 [ V_132 ] ) )
break;
if ( ! F_23 ( V_2 , V_6 ,
V_133 [ V_132 ] ) )
break;
V_76 = F_16 ( V_2 , V_6 ,
V_135 [ V_132 ] ) ;
if ( V_76 < 0 ||
( ! ( V_76 & ( V_136 >> ( ( V_132 & 1 ) * 4 ) ) ) ) )
continue;
if ( F_61 ( V_4 , L_9 , L_7 , V_78 ,
V_6 , V_133 [ V_132 ] ,
V_63 , true , true ) == NULL )
return - V_105 ;
if ( ( V_14 -> F_21 [ V_6 ] & V_137 [ V_132 ] ) &&
F_22 ( V_2 ,
V_6 , V_138 [ V_132 ] ) ) {
int V_48 ;
if ( V_132 > 1 )
V_48 = V_139 + V_6 ;
else
V_48 = V_140 + V_6 ;
V_82 = F_59 ( V_4 , L_9 ,
L_8 , V_78 , NULL , NULL , V_48 ,
V_141 >> ( V_132 & 1 ) ) ;
if ( V_82 )
return V_82 ;
V_82 = F_59 ( V_4 , L_9 ,
L_10 , V_78 , NULL , NULL , V_48 ,
V_142 >> ( V_132 & 1 ) ) ;
if ( V_82 )
return V_82 ;
}
V_78 ++ ;
}
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_82 ;
V_82 = F_65 ( V_2 , V_4 , L_11 , V_143 ,
F_29 ( V_143 ) ) ;
if ( V_82 )
return V_82 ;
V_82 = F_65 ( V_2 , V_4 , L_12 , V_144 ,
F_29 ( V_144 ) ) ;
if ( V_82 )
return V_82 ;
V_82 = F_65 ( V_2 , V_4 , L_13 , V_145 ,
F_29 ( V_145 ) ) ;
if ( V_82 )
return V_82 ;
V_82 = F_65 ( V_2 , V_4 , L_14 , V_146 ,
F_29 ( V_146 ) ) ;
if ( V_82 )
return V_82 ;
V_82 = F_66 ( V_2 , V_4 ) ;
return V_82 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_147 = - 1 ;
if ( F_22 ( V_2 , 0 , V_148 ) )
V_147 = F_16 ( V_2 , 0 , V_148 ) ;
if ( V_147 >= 0 && V_147 != 0xff ) {
switch ( V_147 >> 5 ) {
case 0 :
if ( V_4 -> V_14 -> V_68 [ V_62 ] != V_71 )
return - V_149 ;
V_4 -> V_58 = ( ( V_150 ) ( V_147 << 3 ) ) >> 3 ;
break;
case 1 :
if ( V_4 -> V_14 -> V_68 [ V_62 ] != V_70 )
return - V_149 ;
break;
case 2 :
if ( V_4 -> V_14 -> V_68 [ V_62 ] != V_69 )
return - V_149 ;
break;
default:
return - V_149 ;
}
}
F_17 ( V_2 , 0 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 )
{
struct V_35 * V_36 = & V_2 -> V_36 ;
int V_82 ;
V_4 -> V_29 = V_151 ;
V_82 = F_5 ( V_2 , V_151 ) ;
if ( V_82 < 0 || V_82 == 0xff ) {
V_4 -> V_29 = V_152 ;
V_82 = F_13 ( V_2 , V_152 ) ;
if ( V_82 < 0 || V_82 == 0xffff ) {
F_70 ( V_36 , L_15 ) ;
return - V_149 ;
}
}
F_18 ( V_2 ) ;
if ( V_14 -> V_153 ) {
V_82 = (* V_14 -> V_153 )( V_2 , V_14 ) ;
if ( V_82 < 0 ) {
F_70 ( V_36 , L_16 ) ;
return V_82 ;
}
}
if ( V_14 -> V_27 <= 0 || V_14 -> V_27 > V_154 ) {
F_70 ( V_36 , L_17 , V_14 -> V_27 ) ;
return - V_149 ;
}
V_82 = F_68 ( V_2 , V_4 ) ;
if ( V_82 < 0 ) {
F_70 ( V_36 , L_18 ) ;
return V_82 ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_2 , const struct V_155 * V_156 ,
struct V_13 * V_14 )
{
struct V_35 * V_36 = & V_2 -> V_36 ;
const struct V_157 * V_158 = V_36 -> V_159 ;
struct V_3 * V_4 ;
int V_82 ;
if ( ! V_14 )
return - V_149 ;
if ( ! F_72 ( V_2 -> V_160 , V_161
| V_162
| V_163 ) )
return - V_149 ;
V_4 = F_60 ( V_36 , sizeof( * V_4 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
F_73 ( V_2 , V_4 ) ;
F_74 ( & V_4 -> V_39 ) ;
V_4 -> V_36 = V_36 ;
if ( V_158 )
V_4 -> V_33 = V_158 -> V_33 ;
V_4 -> V_14 = V_14 ;
V_82 = F_69 ( V_2 , V_4 , V_14 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 = F_67 ( V_2 , V_4 ) ;
if ( V_82 )
goto V_164;
if ( ! V_4 -> V_97 ) {
F_70 ( V_36 , L_19 ) ;
V_82 = - V_149 ;
goto V_164;
}
V_82 = F_75 ( & V_36 -> V_165 , & V_4 -> V_102 ) ;
if ( V_82 ) {
F_70 ( V_36 , L_20 ) ;
goto V_164;
}
V_4 -> V_166 = F_76 ( V_36 ) ;
if ( F_77 ( V_4 -> V_166 ) ) {
V_82 = F_78 ( V_4 -> V_166 ) ;
F_70 ( V_36 , L_21 ) ;
goto V_167;
}
return 0 ;
V_167:
F_79 ( & V_36 -> V_165 , & V_4 -> V_102 ) ;
V_164:
F_80 ( V_4 -> V_102 . V_103 ) ;
return V_82 ;
}
int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_82 ( V_4 -> V_166 ) ;
F_79 ( & V_2 -> V_36 . V_165 , & V_4 -> V_102 ) ;
F_80 ( V_4 -> V_102 . V_103 ) ;
return 0 ;
}
