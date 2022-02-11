static const char * F_1 ( T_1 V_1 , char * V_2 , T_2 V_3 , bool V_4 )
{
switch ( V_1 ) {
case V_5 :
return L_1 ;
case V_6 :
return L_2 ;
case V_7 :
return L_3 ;
case V_8 :
return L_4 ;
case V_9 :
return L_5 ;
case V_10 :
return L_6 ;
case V_11 :
return L_7 ;
case V_12 :
return L_8 ;
case F_2 ( 0 ) :
case F_2 ( 1 ) :
case F_2 ( 2 ) :
case F_2 ( 3 ) :
case F_2 ( 4 ) :
case F_2 ( 5 ) :
case F_2 ( 6 ) :
case F_2 ( 7 ) :
case F_2 ( 8 ) :
case F_2 ( 9 ) :
case F_2 ( 10 ) :
case F_2 ( 11 ) :
case F_2 ( 12 ) :
case F_2 ( 13 ) :
case F_2 ( 14 ) :
case F_2 ( 15 ) :
snprintf ( V_2 , V_3 , L_9 , ( V_1 - F_2 ( 0 ) ) >> 2 ) ;
break;
case F_3 ( 0 ) :
case F_3 ( 1 ) :
case F_3 ( 2 ) :
case F_3 ( 3 ) :
case F_3 ( 4 ) :
case F_3 ( 5 ) :
case F_3 ( 6 ) :
case F_3 ( 7 ) :
case F_3 ( 8 ) :
case F_3 ( 9 ) :
case F_3 ( 10 ) :
case F_3 ( 11 ) :
case F_3 ( 12 ) :
case F_3 ( 13 ) :
case F_3 ( 14 ) :
case F_3 ( 15 ) :
if ( V_4 )
snprintf ( V_2 , V_3 , L_9 ,
16u + ( ( V_1 - F_3 ( 0 ) ) >> 2 ) ) ;
else
snprintf ( V_2 , V_3 , L_10 ,
( V_1 - F_3 ( 0 ) ) >> 2 ) ;
break;
case V_13 :
return L_11 ;
default:
snprintf ( V_2 , V_3 , L_12 , V_1 ) ;
break;
}
return V_2 ;
}
static inline T_1 F_4 ( struct V_14 * V_15 , T_1 V_1 )
{
T_1 V_16 = F_5 ( V_15 -> V_17 + V_1 ) ;
#ifdef F_6
if ( V_15 -> V_18 & V_19 ) {
char V_2 [ 16 ] ;
F_7 ( V_15 -> V_20 , L_13 , V_16 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) , false ) ) ;
}
#endif
return V_16 ;
}
static inline void F_8 ( struct V_14 * V_15 ,
T_1 V_1 , T_1 V_16 )
{
#ifdef F_6
if ( V_15 -> V_18 & V_19 ) {
char V_2 [ 16 ] ;
F_7 ( V_15 -> V_20 , L_14 , V_16 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) , true ) ) ;
}
#endif
F_9 ( V_16 , V_15 -> V_17 + V_1 ) ;
}
static inline int F_10 ( struct V_14 * V_15 , int V_21 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
V_15 -> V_18 &= ~ ( V_24 | V_25 | V_26 |
V_27 | V_28 |
V_19 ) ;
F_11 ( V_15 -> V_29 ) ;
if ( ( V_15 -> V_30 || V_15 -> V_31 ) && V_23 -> V_32 . V_33 )
V_23 -> V_32 . V_33 ( & V_23 -> V_32 , V_21 ) ;
F_12 ( & V_15 -> V_34 ) ;
return V_21 ;
}
static T_2 F_13 ( struct V_35 * V_36 )
{
T_2 V_37 ;
while ( ( V_36 -> V_38 < V_36 -> V_39 ) && V_36 -> V_40 ) {
V_37 = F_14 ( V_36 -> V_41 -> V_42 - V_36 -> V_1 , V_36 -> V_40 ) ;
V_37 = F_14 ( V_37 , V_36 -> V_39 - V_36 -> V_38 ) ;
if ( V_37 <= 0 ) {
if ( ( V_36 -> V_41 -> V_42 == 0 ) && ! F_15 ( V_36 -> V_41 ) ) {
V_36 -> V_41 = F_16 ( V_36 -> V_41 ) ;
continue;
} else {
break;
}
}
F_17 ( V_36 -> V_43 + V_36 -> V_38 , V_36 -> V_41 ,
V_36 -> V_1 , V_37 , 0 ) ;
V_36 -> V_38 += V_37 ;
V_36 -> V_1 += V_37 ;
V_36 -> V_40 -= V_37 ;
if ( V_36 -> V_1 == V_36 -> V_41 -> V_42 ) {
V_36 -> V_41 = F_16 ( V_36 -> V_41 ) ;
if ( V_36 -> V_41 )
V_36 -> V_1 = 0 ;
else
V_36 -> V_40 = 0 ;
}
}
return 0 ;
}
static void F_18 ( struct V_35 * V_36 , int V_42 )
{
unsigned int V_44 , V_45 ;
T_3 V_46 [ 2 ] ;
T_3 V_47 [ 2 ] ;
V_47 [ 0 ] = V_36 -> V_48 [ 0 ] ;
V_47 [ 1 ] = V_36 -> V_48 [ 1 ] ;
V_47 [ 0 ] += V_36 -> V_38 ;
if ( V_47 [ 0 ] < V_36 -> V_38 )
V_47 [ 1 ] ++ ;
V_47 [ 0 ] += V_42 ;
if ( V_47 [ 0 ] < V_42 )
V_47 [ 1 ] ++ ;
V_46 [ 1 ] = F_19 ( V_47 [ 0 ] << 3 ) ;
V_46 [ 0 ] = F_19 ( V_47 [ 1 ] << 3 | V_47 [ 0 ] >> 61 ) ;
switch ( V_36 -> V_18 & V_49 ) {
case V_50 :
case V_51 :
V_44 = V_36 -> V_38 & 0x7f ;
V_45 = ( V_44 < 112 ) ? ( 112 - V_44 ) : ( ( 128 + 112 ) - V_44 ) ;
* ( V_36 -> V_43 + V_36 -> V_38 ) = 0x80 ;
memset ( V_36 -> V_43 + V_36 -> V_38 + 1 , 0 , V_45 - 1 ) ;
memcpy ( V_36 -> V_43 + V_36 -> V_38 + V_45 , V_46 , 16 ) ;
V_36 -> V_38 += V_45 + 16 ;
V_36 -> V_18 |= V_52 ;
break;
default:
V_44 = V_36 -> V_38 & 0x3f ;
V_45 = ( V_44 < 56 ) ? ( 56 - V_44 ) : ( ( 64 + 56 ) - V_44 ) ;
* ( V_36 -> V_43 + V_36 -> V_38 ) = 0x80 ;
memset ( V_36 -> V_43 + V_36 -> V_38 + 1 , 0 , V_45 - 1 ) ;
memcpy ( V_36 -> V_43 + V_36 -> V_38 + V_45 , & V_46 [ 1 ] , 8 ) ;
V_36 -> V_38 += V_45 + 8 ;
V_36 -> V_18 |= V_52 ;
break;
}
}
static struct V_14 * F_20 ( struct V_53 * V_54 )
{
struct V_14 * V_15 = NULL ;
struct V_14 * V_2 ;
F_21 ( & V_55 . V_56 ) ;
if ( ! V_54 -> V_15 ) {
F_22 (tmp, &atmel_sha.dev_list, list) {
V_15 = V_2 ;
break;
}
V_54 -> V_15 = V_15 ;
} else {
V_15 = V_54 -> V_15 ;
}
F_23 ( & V_55 . V_56 ) ;
return V_15 ;
}
static int F_24 ( struct V_22 * V_23 )
{
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_53 * V_54 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_14 * V_15 = F_20 ( V_54 ) ;
V_36 -> V_15 = V_15 ;
V_36 -> V_18 = 0 ;
F_28 ( V_15 -> V_20 , L_15 ,
F_29 ( V_58 ) ) ;
switch ( F_29 ( V_58 ) ) {
case V_59 :
V_36 -> V_18 |= V_60 ;
V_36 -> V_61 = V_62 ;
break;
case V_63 :
V_36 -> V_18 |= V_64 ;
V_36 -> V_61 = V_65 ;
break;
case V_66 :
V_36 -> V_18 |= V_67 ;
V_36 -> V_61 = V_68 ;
break;
case V_69 :
V_36 -> V_18 |= V_50 ;
V_36 -> V_61 = V_70 ;
break;
case V_71 :
V_36 -> V_18 |= V_51 ;
V_36 -> V_61 = V_72 ;
break;
default:
return - V_73 ;
break;
}
V_36 -> V_38 = 0 ;
V_36 -> V_48 [ 0 ] = 0 ;
V_36 -> V_48 [ 1 ] = 0 ;
V_36 -> V_39 = V_74 ;
return 0 ;
}
static void F_30 ( struct V_14 * V_15 , int V_75 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
T_1 V_76 = V_77 ;
unsigned int V_78 , V_79 = 0 ;
if ( F_31 ( V_75 ) ) {
if ( ! V_15 -> V_80 . V_81 )
F_8 ( V_15 , V_7 , V_82 ) ;
V_76 = V_83 ;
if ( V_15 -> V_80 . V_84 )
V_76 |= V_85 ;
} else {
F_8 ( V_15 , V_7 , V_86 ) ;
}
switch ( V_36 -> V_18 & V_49 ) {
case V_60 :
V_76 |= V_87 ;
V_79 = V_59 ;
break;
case V_64 :
V_76 |= V_88 ;
V_79 = V_66 ;
break;
case V_67 :
V_76 |= V_89 ;
V_79 = V_66 ;
break;
case V_50 :
V_76 |= V_90 ;
V_79 = V_71 ;
break;
case V_51 :
V_76 |= V_91 ;
V_79 = V_71 ;
break;
default:
break;
}
if ( ! ( V_36 -> V_48 [ 0 ] || V_36 -> V_48 [ 1 ] ) ) {
F_8 ( V_15 , V_5 , V_92 ) ;
} else if ( V_15 -> V_80 . V_93 && ( V_36 -> V_18 & V_94 ) ) {
const T_1 * V_95 = ( const T_1 * ) V_36 -> V_96 ;
V_36 -> V_18 &= ~ V_94 ;
F_8 ( V_15 , V_5 , V_97 ) ;
for ( V_78 = 0 ; V_78 < V_79 / sizeof( T_1 ) ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_95 [ V_78 ] ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
V_76 |= V_98 ;
}
F_8 ( V_15 , V_6 , V_76 ) ;
}
static inline int F_32 ( struct V_14 * V_15 ,
T_4 V_99 )
{
T_1 V_100 = F_4 ( V_15 , V_10 ) ;
if ( F_33 ( V_100 & V_86 ) )
return V_99 ( V_15 ) ;
V_15 -> V_99 = V_99 ;
F_8 ( V_15 , V_7 , V_86 ) ;
return - V_101 ;
}
static int F_34 ( struct V_14 * V_15 , const T_5 * V_102 ,
T_2 V_42 , int V_103 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
int V_37 , V_104 ;
const T_1 * V_43 = ( const T_1 * ) V_102 ;
F_28 ( V_15 -> V_20 , L_16 ,
V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] , V_42 , V_103 ) ;
F_30 ( V_15 , 0 ) ;
V_36 -> V_48 [ 0 ] += V_42 ;
if ( V_36 -> V_48 [ 0 ] < V_42 )
V_36 -> V_48 [ 1 ] ++ ;
if ( V_103 )
V_15 -> V_18 |= V_25 ;
V_104 = F_35 ( V_42 , sizeof( T_1 ) ) ;
V_15 -> V_18 |= V_26 ;
for ( V_37 = 0 ; V_37 < V_104 ; V_37 ++ )
F_8 ( V_15 , F_2 ( V_37 ) , V_43 [ V_37 ] ) ;
return - V_101 ;
}
static int F_36 ( struct V_14 * V_15 , T_6 V_105 ,
T_2 V_106 , T_6 V_107 , T_2 V_108 , int V_103 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
int V_104 ;
F_28 ( V_15 -> V_20 , L_17 ,
V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] , V_106 , V_103 ) ;
V_104 = F_35 ( V_106 , sizeof( T_1 ) ) ;
F_8 ( V_15 , V_109 , V_110 ) ;
F_8 ( V_15 , V_111 , V_105 ) ;
F_8 ( V_15 , V_112 , V_104 ) ;
V_104 = F_35 ( V_108 , sizeof( T_1 ) ) ;
F_8 ( V_15 , V_113 , V_107 ) ;
F_8 ( V_15 , V_114 , V_104 ) ;
F_30 ( V_15 , 1 ) ;
V_36 -> V_48 [ 0 ] += V_106 ;
if ( V_36 -> V_48 [ 0 ] < V_106 )
V_36 -> V_48 [ 1 ] ++ ;
if ( V_103 )
V_15 -> V_18 |= V_25 ;
V_15 -> V_18 |= V_115 ;
F_8 ( V_15 , V_109 , V_116 ) ;
return - V_101 ;
}
static void F_37 ( void * V_117 )
{
struct V_14 * V_15 = V_117 ;
V_15 -> V_30 = true ;
F_8 ( V_15 , V_7 , V_86 ) ;
}
static int F_38 ( struct V_14 * V_15 , T_6 V_105 ,
T_2 V_106 , T_6 V_107 , T_2 V_108 , int V_103 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
struct V_118 * V_119 ;
struct V_120 V_41 [ 2 ] ;
F_28 ( V_15 -> V_20 , L_18 ,
V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] , V_106 , V_103 ) ;
V_15 -> V_121 . V_122 . V_123 = 16 ;
V_15 -> V_121 . V_122 . V_124 = 16 ;
F_39 ( V_15 -> V_121 . V_125 , & V_15 -> V_121 . V_122 ) ;
if ( V_108 ) {
F_40 ( V_41 , 2 ) ;
F_41 ( & V_41 [ 0 ] ) = V_105 ;
F_42 ( & V_41 [ 0 ] ) = V_106 ;
F_41 ( & V_41 [ 1 ] ) = V_107 ;
F_42 ( & V_41 [ 1 ] ) = V_108 ;
V_119 = F_43 ( V_15 -> V_121 . V_125 , V_41 , 2 ,
V_126 , V_127 | V_128 ) ;
} else {
F_40 ( V_41 , 1 ) ;
F_41 ( & V_41 [ 0 ] ) = V_105 ;
F_42 ( & V_41 [ 0 ] ) = V_106 ;
V_119 = F_43 ( V_15 -> V_121 . V_125 , V_41 , 1 ,
V_126 , V_127 | V_128 ) ;
}
if ( ! V_119 )
return F_10 ( V_15 , - V_73 ) ;
V_119 -> V_129 = F_37 ;
V_119 -> V_130 = V_15 ;
F_30 ( V_15 , 1 ) ;
V_36 -> V_48 [ 0 ] += V_106 ;
if ( V_36 -> V_48 [ 0 ] < V_106 )
V_36 -> V_48 [ 1 ] ++ ;
if ( V_103 )
V_15 -> V_18 |= V_25 ;
V_15 -> V_18 |= V_115 ;
F_44 ( V_119 ) ;
F_45 ( V_15 -> V_121 . V_125 ) ;
return - V_101 ;
}
static int F_46 ( struct V_14 * V_15 , T_6 V_105 ,
T_2 V_106 , T_6 V_107 , T_2 V_108 , int V_103 )
{
if ( V_15 -> V_80 . V_81 )
return F_38 ( V_15 , V_105 , V_106 ,
V_107 , V_108 , V_103 ) ;
else
return F_36 ( V_15 , V_105 , V_106 ,
V_107 , V_108 , V_103 ) ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
int V_38 ;
F_13 ( V_36 ) ;
F_18 ( V_36 , 0 ) ;
V_38 = V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
return F_34 ( V_15 , V_36 -> V_43 , V_38 , 1 ) ;
}
static int F_48 ( struct V_14 * V_15 ,
struct V_35 * V_36 ,
T_2 V_42 , int V_103 )
{
V_36 -> V_131 = F_49 ( V_15 -> V_20 , V_36 -> V_43 ,
V_36 -> V_39 + V_36 -> V_61 , V_132 ) ;
if ( F_50 ( V_15 -> V_20 , V_36 -> V_131 ) ) {
F_51 ( V_15 -> V_20 , L_19 , V_36 -> V_39 +
V_36 -> V_61 ) ;
return F_10 ( V_15 , - V_73 ) ;
}
V_36 -> V_18 &= ~ V_133 ;
return F_46 ( V_15 , V_36 -> V_131 , V_42 , 0 , 0 , V_103 ) ;
}
static int F_52 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
unsigned int V_103 ;
T_2 V_37 ;
F_13 ( V_36 ) ;
V_103 = ( V_36 -> V_18 & V_134 ) && ! V_36 -> V_40 ;
F_28 ( V_15 -> V_20 , L_20 ,
V_36 -> V_38 , V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] , V_103 ) ;
if ( V_103 )
F_18 ( V_36 , 0 ) ;
if ( V_103 || ( V_36 -> V_38 == V_36 -> V_39 ) ) {
V_37 = V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
return F_48 ( V_15 , V_36 , V_37 , V_103 ) ;
}
return 0 ;
}
static int F_53 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
unsigned int V_42 , V_103 , V_135 ;
struct V_120 * V_41 ;
unsigned int V_37 ;
if ( ! V_36 -> V_40 )
return 0 ;
if ( V_36 -> V_38 || V_36 -> V_1 )
return F_52 ( V_15 ) ;
F_28 ( V_15 -> V_20 , L_21 ,
V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] , V_36 -> V_38 , V_36 -> V_40 ) ;
V_41 = V_36 -> V_41 ;
if ( ! F_54 ( V_41 -> V_1 , sizeof( T_1 ) ) )
return F_52 ( V_15 ) ;
if ( ! F_15 ( V_41 ) && ! F_54 ( V_41 -> V_42 , V_36 -> V_61 ) )
return F_52 ( V_15 ) ;
V_42 = F_14 ( V_36 -> V_40 , V_41 -> V_42 ) ;
if ( F_15 ( V_41 ) ) {
if ( ! ( V_36 -> V_18 & V_134 ) ) {
V_135 = V_42 & ( V_36 -> V_61 - 1 ) ;
V_42 -= V_135 ;
}
}
V_36 -> V_40 -= V_42 ;
V_36 -> V_1 = V_42 ;
V_103 = ( V_36 -> V_18 & V_134 ) && ! V_36 -> V_40 ;
if ( V_103 ) {
V_135 = V_42 & ( V_36 -> V_61 - 1 ) ;
V_42 -= V_135 ;
V_36 -> V_40 += V_135 ;
V_36 -> V_1 = V_42 ;
V_41 = V_36 -> V_41 ;
F_13 ( V_36 ) ;
F_18 ( V_36 , V_42 ) ;
V_36 -> V_131 = F_49 ( V_15 -> V_20 , V_36 -> V_43 ,
V_36 -> V_39 + V_36 -> V_61 , V_132 ) ;
if ( F_50 ( V_15 -> V_20 , V_36 -> V_131 ) ) {
F_51 ( V_15 -> V_20 , L_19 ,
V_36 -> V_39 + V_36 -> V_61 ) ;
return F_10 ( V_15 , - V_73 ) ;
}
if ( V_42 == 0 ) {
V_36 -> V_18 &= ~ V_133 ;
V_37 = V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
return F_46 ( V_15 , V_36 -> V_131 , V_37 , 0 ,
0 , V_103 ) ;
} else {
V_36 -> V_41 = V_41 ;
if ( ! F_55 ( V_15 -> V_20 , V_36 -> V_41 , 1 ,
V_132 ) ) {
F_51 ( V_15 -> V_20 , L_22 ) ;
return F_10 ( V_15 , - V_73 ) ;
}
V_36 -> V_18 |= V_133 ;
V_37 = V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
return F_46 ( V_15 , F_41 ( V_36 -> V_41 ) ,
V_42 , V_36 -> V_131 , V_37 , V_103 ) ;
}
}
if ( ! F_55 ( V_15 -> V_20 , V_36 -> V_41 , 1 , V_132 ) ) {
F_51 ( V_15 -> V_20 , L_22 ) ;
return F_10 ( V_15 , - V_73 ) ;
}
V_36 -> V_18 |= V_133 ;
return F_46 ( V_15 , F_41 ( V_36 -> V_41 ) , V_42 , 0 ,
0 , V_103 ) ;
}
static int F_56 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = F_27 ( V_15 -> V_23 ) ;
if ( V_36 -> V_18 & V_133 ) {
F_57 ( V_15 -> V_20 , V_36 -> V_41 , 1 , V_132 ) ;
if ( V_36 -> V_41 -> V_42 == V_36 -> V_1 ) {
V_36 -> V_41 = F_16 ( V_36 -> V_41 ) ;
if ( V_36 -> V_41 )
V_36 -> V_1 = 0 ;
}
if ( V_36 -> V_18 & V_52 ) {
F_58 ( V_15 -> V_20 , V_36 -> V_131 ,
V_36 -> V_39 + V_36 -> V_61 , V_132 ) ;
}
} else {
F_58 ( V_15 -> V_20 , V_36 -> V_131 , V_36 -> V_39 +
V_36 -> V_61 , V_132 ) ;
}
return 0 ;
}
static int F_59 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
int V_21 ;
F_28 ( V_15 -> V_20 , L_23 ,
V_36 -> V_40 , V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] ) ;
if ( V_36 -> V_18 & V_26 )
V_21 = F_47 ( V_15 ) ;
else
V_21 = F_53 ( V_15 ) ;
F_28 ( V_15 -> V_20 , L_24 ,
V_21 , V_36 -> V_48 [ 1 ] , V_36 -> V_48 [ 0 ] ) ;
return V_21 ;
}
static int F_60 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
int V_21 = 0 ;
int V_37 ;
if ( V_36 -> V_38 >= V_136 ) {
F_18 ( V_36 , 0 ) ;
V_37 = V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
V_21 = F_48 ( V_15 , V_36 , V_37 , 1 ) ;
}
else {
F_18 ( V_36 , 0 ) ;
V_37 = V_36 -> V_38 ;
V_36 -> V_38 = 0 ;
V_21 = F_34 ( V_15 , V_36 -> V_43 , V_37 , 1 ) ;
}
F_28 ( V_15 -> V_20 , L_25 , V_21 ) ;
return V_21 ;
}
static void F_61 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_1 * V_95 = ( T_1 * ) V_36 -> V_96 ;
unsigned int V_78 , V_79 ;
switch ( V_36 -> V_18 & V_49 ) {
case V_60 :
V_79 = V_59 ;
break;
case V_64 :
case V_67 :
V_79 = V_66 ;
break;
case V_50 :
case V_51 :
V_79 = V_71 ;
break;
default:
return;
}
for ( V_78 = 0 ; V_78 < V_79 / sizeof( T_1 ) ; ++ V_78 )
V_95 [ V_78 ] = F_4 ( V_36 -> V_15 , F_3 ( V_78 ) ) ;
V_36 -> V_18 |= V_94 ;
}
static void F_62 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
if ( ! V_23 -> V_137 )
return;
switch ( V_36 -> V_18 & V_49 ) {
default:
case V_60 :
memcpy ( V_23 -> V_137 , V_36 -> V_96 , V_59 ) ;
break;
case V_64 :
memcpy ( V_23 -> V_137 , V_36 -> V_96 , V_63 ) ;
break;
case V_67 :
memcpy ( V_23 -> V_137 , V_36 -> V_96 , V_66 ) ;
break;
case V_50 :
memcpy ( V_23 -> V_137 , V_36 -> V_96 , V_69 ) ;
break;
case V_51 :
memcpy ( V_23 -> V_137 , V_36 -> V_96 , V_71 ) ;
break;
}
}
static int F_63 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_14 * V_15 = V_36 -> V_15 ;
if ( V_36 -> V_48 [ 0 ] || V_36 -> V_48 [ 1 ] )
F_62 ( V_23 ) ;
F_28 ( V_15 -> V_20 , L_26 , V_36 -> V_48 [ 1 ] ,
V_36 -> V_48 [ 0 ] , V_36 -> V_38 ) ;
return 0 ;
}
static void F_64 ( struct V_22 * V_23 , int V_21 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_14 * V_15 = V_36 -> V_15 ;
if ( ! V_21 ) {
F_61 ( V_23 ) ;
if ( V_25 & V_15 -> V_18 )
V_21 = F_63 ( V_23 ) ;
} else {
V_36 -> V_18 |= V_138 ;
}
( void ) F_10 ( V_15 , V_21 ) ;
}
static int F_65 ( struct V_14 * V_15 )
{
int V_21 ;
V_21 = F_66 ( V_15 -> V_29 ) ;
if ( V_21 )
return V_21 ;
if ( ! ( V_139 & V_15 -> V_18 ) ) {
F_8 ( V_15 , V_5 , V_140 ) ;
V_15 -> V_18 |= V_139 ;
V_15 -> V_21 = 0 ;
}
return 0 ;
}
static inline unsigned int F_67 ( struct V_14 * V_15 )
{
return F_4 ( V_15 , V_13 ) & 0x00000fff ;
}
static void F_68 ( struct V_14 * V_15 )
{
F_65 ( V_15 ) ;
V_15 -> V_141 = F_67 ( V_15 ) ;
F_69 ( V_15 -> V_20 ,
L_27 , V_15 -> V_141 ) ;
F_11 ( V_15 -> V_29 ) ;
}
static int F_70 ( struct V_14 * V_15 ,
struct V_22 * V_23 )
{
struct V_142 * V_143 , * V_144 ;
struct V_53 * V_36 ;
unsigned long V_18 ;
bool V_145 ;
int V_21 = 0 , V_146 = 0 ;
F_71 ( & V_15 -> V_56 , V_18 ) ;
if ( V_23 )
V_146 = F_72 ( & V_15 -> V_147 , V_23 ) ;
if ( V_24 & V_15 -> V_18 ) {
F_73 ( & V_15 -> V_56 , V_18 ) ;
return V_146 ;
}
V_144 = F_74 ( & V_15 -> V_147 ) ;
V_143 = F_75 ( & V_15 -> V_147 ) ;
if ( V_143 )
V_15 -> V_18 |= V_24 ;
F_73 ( & V_15 -> V_56 , V_18 ) ;
if ( ! V_143 )
return V_146 ;
if ( V_144 )
V_144 -> V_33 ( V_144 , - V_101 ) ;
V_36 = F_76 ( V_143 -> V_58 ) ;
V_15 -> V_23 = F_77 ( V_143 ) ;
V_145 = ( V_15 -> V_23 != V_23 ) ;
V_15 -> V_30 = V_145 ;
V_15 -> V_31 = false ;
V_21 = V_36 -> V_148 ( V_15 ) ;
return ( V_145 ) ? V_146 : V_21 ;
}
static int F_78 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
int V_21 ;
F_28 ( V_15 -> V_20 , L_28 ,
V_36 -> V_149 , V_23 -> V_150 ) ;
V_21 = F_65 ( V_15 ) ;
if ( V_21 )
return F_10 ( V_15 , V_21 ) ;
V_15 -> V_99 = V_151 ;
if ( V_36 -> V_149 == V_152 ) {
V_21 = F_59 ( V_15 ) ;
if ( ! V_21 && ( V_36 -> V_18 & V_134 ) )
V_21 = F_60 ( V_15 ) ;
} else if ( V_36 -> V_149 == V_153 ) {
V_21 = F_60 ( V_15 ) ;
}
if ( ! V_21 )
F_64 ( V_23 , V_21 ) ;
F_28 ( V_15 -> V_20 , L_29 , V_21 ) ;
return V_21 ;
}
static int F_79 ( struct V_22 * V_23 , unsigned int V_149 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_53 * V_54 = F_76 ( V_23 -> V_32 . V_58 ) ;
struct V_14 * V_15 = V_54 -> V_15 ;
V_36 -> V_149 = V_149 ;
return F_70 ( V_15 , V_23 ) ;
}
static int F_80 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
if ( ! V_23 -> V_150 )
return 0 ;
V_36 -> V_40 = V_23 -> V_150 ;
V_36 -> V_41 = V_23 -> V_154 ;
V_36 -> V_1 = 0 ;
if ( V_36 -> V_18 & V_134 ) {
if ( V_36 -> V_38 + V_36 -> V_40 < V_136 )
V_36 -> V_18 |= V_26 ;
} else if ( V_36 -> V_38 + V_36 -> V_40 < V_36 -> V_39 ) {
F_13 ( V_36 ) ;
return 0 ;
}
return F_79 ( V_23 , V_152 ) ;
}
static int F_81 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
V_36 -> V_18 |= V_134 ;
if ( V_36 -> V_18 & V_138 )
return 0 ;
if ( V_36 -> V_18 & V_52 )
return F_63 ( V_23 ) ;
return F_79 ( V_23 , V_153 ) ;
}
static int F_82 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
int V_155 , V_156 ;
V_36 -> V_18 |= V_134 ;
V_155 = F_80 ( V_23 ) ;
if ( V_155 == - V_101 || V_155 == - V_157 )
return V_155 ;
V_156 = F_81 ( V_23 ) ;
return V_155 ? : V_156 ;
}
static int F_83 ( struct V_22 * V_23 )
{
return F_24 ( V_23 ) ? : F_82 ( V_23 ) ;
}
static int F_84 ( struct V_22 * V_23 , void * V_158 )
{
const struct V_35 * V_36 = F_27 ( V_23 ) ;
memcpy ( V_158 , V_36 , sizeof( * V_36 ) ) ;
return 0 ;
}
static int F_85 ( struct V_22 * V_23 , const void * V_159 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
memcpy ( V_36 , V_159 , sizeof( * V_36 ) ) ;
return 0 ;
}
static int F_86 ( struct V_160 * V_58 )
{
struct V_53 * V_36 = F_76 ( V_58 ) ;
F_87 ( F_88 ( V_58 ) ,
sizeof( struct V_35 ) ) ;
V_36 -> V_148 = F_78 ;
return 0 ;
}
static void F_89 ( unsigned long V_117 )
{
struct V_14 * V_15 = (struct V_14 * ) V_117 ;
F_70 ( V_15 , NULL ) ;
}
static int V_151 ( struct V_14 * V_15 )
{
int V_21 = 0 ;
if ( V_26 & V_15 -> V_18 ) {
if ( V_28 & V_15 -> V_18 ) {
V_15 -> V_18 &= ~ V_28 ;
goto V_161;
}
} else if ( V_27 & V_15 -> V_18 ) {
if ( V_115 & V_15 -> V_18 ) {
V_15 -> V_18 &= ~ V_115 ;
F_56 ( V_15 ) ;
if ( V_15 -> V_21 ) {
V_21 = V_15 -> V_21 ;
goto V_161;
}
}
if ( V_28 & V_15 -> V_18 ) {
V_15 -> V_18 &= ~ ( V_27 |
V_28 ) ;
V_21 = F_53 ( V_15 ) ;
if ( V_21 != - V_101 )
goto V_161;
}
}
return V_21 ;
V_161:
F_64 ( V_15 -> V_23 , V_21 ) ;
return V_21 ;
}
static void F_90 ( unsigned long V_117 )
{
struct V_14 * V_15 = (struct V_14 * ) V_117 ;
V_15 -> V_30 = true ;
( void ) V_15 -> V_99 ( V_15 ) ;
}
static T_7 F_91 ( int V_162 , void * V_163 )
{
struct V_14 * V_164 = V_163 ;
T_1 V_165 ;
V_165 = F_4 ( V_164 , V_10 ) ;
if ( V_165 & F_4 ( V_164 , V_9 ) ) {
F_8 ( V_164 , V_8 , V_165 ) ;
if ( V_24 & V_164 -> V_18 ) {
V_164 -> V_18 |= V_28 ;
if ( ! ( V_26 & V_164 -> V_18 ) )
V_164 -> V_18 |= V_27 ;
F_12 ( & V_164 -> V_166 ) ;
} else {
F_92 ( V_164 -> V_20 , L_30 ) ;
}
return V_167 ;
}
return V_168 ;
}
static bool F_93 ( struct V_14 * V_15 ,
struct V_120 * V_41 ,
T_2 V_169 )
{
struct V_170 * V_75 = & V_15 -> V_121 ;
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_171 = V_36 -> V_61 ;
int V_172 ;
for ( V_172 = 0 ; V_41 ; V_41 = F_16 ( V_41 ) , ++ V_172 ) {
if ( ! F_54 ( V_41 -> V_1 , sizeof( T_1 ) ) )
return false ;
if ( V_169 <= V_41 -> V_42 ) {
V_75 -> V_172 = V_172 + 1 ;
V_75 -> V_173 = V_41 -> V_42 ;
V_41 -> V_42 = F_94 ( V_169 , sizeof( T_1 ) ) ;
return true ;
}
if ( ! F_54 ( V_41 -> V_42 , V_171 ) )
return false ;
V_169 -= V_41 -> V_42 ;
}
return false ;
}
static void F_95 ( void * V_117 )
{
struct V_14 * V_15 = V_117 ;
struct V_170 * V_75 = & V_15 -> V_121 ;
struct V_120 * V_41 ;
int V_172 ;
F_96 ( V_75 -> V_125 ) ;
F_57 ( V_15 -> V_20 , V_75 -> V_41 , V_75 -> V_172 , V_132 ) ;
V_41 = V_75 -> V_41 ;
for ( V_172 = 0 ; V_172 < V_75 -> V_172 - 1 ; ++ V_172 )
V_41 = F_16 ( V_41 ) ;
V_41 -> V_42 = V_75 -> V_173 ;
V_15 -> V_30 = true ;
( void ) F_32 ( V_15 , V_15 -> V_99 ) ;
}
static int F_97 ( struct V_14 * V_15 ,
struct V_120 * V_154 ,
T_2 V_169 ,
T_4 V_99 )
{
struct V_170 * V_75 = & V_15 -> V_121 ;
struct V_174 * V_175 = & V_75 -> V_122 ;
struct V_176 * V_125 = V_75 -> V_125 ;
struct V_118 * V_177 ;
T_8 V_178 ;
unsigned int V_179 ;
int V_21 ;
V_15 -> V_99 = V_99 ;
V_75 -> V_41 = V_154 ;
V_179 = F_55 ( V_15 -> V_20 , V_75 -> V_41 , V_75 -> V_172 , V_132 ) ;
if ( ! V_179 ) {
V_21 = - V_180 ;
goto exit;
}
V_175 -> V_123 = 16 ;
V_175 -> V_124 = 16 ;
V_21 = F_39 ( V_125 , V_175 ) ;
if ( V_21 )
goto V_181;
V_177 = F_43 ( V_125 , V_75 -> V_41 , V_179 , V_126 ,
V_127 | V_128 ) ;
if ( ! V_177 ) {
V_21 = - V_180 ;
goto V_181;
}
V_177 -> V_129 = F_95 ;
V_177 -> V_130 = V_15 ;
V_178 = F_44 ( V_177 ) ;
V_21 = F_98 ( V_178 ) ;
if ( V_21 )
goto V_181;
F_45 ( V_125 ) ;
return - V_101 ;
V_181:
F_57 ( V_15 -> V_20 , V_75 -> V_41 , V_75 -> V_172 , V_132 ) ;
exit:
return F_10 ( V_15 , V_21 ) ;
}
static int F_99 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
const T_1 * V_182 = ( const T_1 * ) V_36 -> V_43 ;
T_2 V_78 , V_183 ;
T_1 V_100 , V_184 , V_185 ;
V_185 = ( V_36 -> V_18 & V_186 ) ? 0 : 1 ;
for (; ; ) {
V_183 = F_35 ( V_36 -> V_38 , sizeof( T_1 ) ) ;
for ( V_78 = 0 , V_184 = 0 ; V_78 < V_183 ; ++ V_78 , V_184 += V_185 )
F_8 ( V_15 , F_2 ( V_184 ) , V_182 [ V_78 ] ) ;
V_36 -> V_1 += V_36 -> V_38 ;
V_36 -> V_40 -= V_36 -> V_38 ;
if ( ! V_36 -> V_40 )
break;
V_36 -> V_38 = F_100 ( T_2 , V_36 -> V_61 , V_36 -> V_40 ) ;
F_17 ( V_36 -> V_43 , V_36 -> V_41 ,
V_36 -> V_1 , V_36 -> V_38 , 0 ) ;
V_100 = F_4 ( V_15 , V_10 ) ;
if ( ! ( V_100 & V_86 ) ) {
V_15 -> V_99 = F_99 ;
F_8 ( V_15 , V_7 , V_86 ) ;
return - V_101 ;
}
}
if ( F_33 ( ! ( V_36 -> V_18 & V_187 ) ) )
return V_15 -> V_188 ( V_15 ) ;
return F_32 ( V_15 , V_15 -> V_188 ) ;
}
static int F_101 ( struct V_14 * V_15 ,
struct V_120 * V_41 ,
unsigned int V_169 ,
bool V_189 ,
bool V_190 ,
T_4 V_99 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
if ( ! V_169 )
return V_99 ( V_15 ) ;
V_36 -> V_18 &= ~ ( V_186 | V_187 ) ;
if ( V_189 )
V_36 -> V_18 |= V_186 ;
if ( V_190 )
V_36 -> V_18 |= V_187 ;
V_36 -> V_41 = V_41 ;
V_36 -> V_40 = V_169 ;
V_36 -> V_1 = 0 ;
V_36 -> V_38 = F_100 ( T_2 , V_36 -> V_61 , V_36 -> V_40 ) ;
F_17 ( V_36 -> V_43 , V_36 -> V_41 ,
V_36 -> V_1 , V_36 -> V_38 , 0 ) ;
V_15 -> V_188 = V_99 ;
return F_99 ( V_15 ) ;
}
static int F_102 ( struct V_14 * V_15 ,
const void * V_117 , unsigned int V_191 ,
bool V_192 ,
T_4 V_99 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_1 V_193 = ( V_192 ) ? V_191 : 0 ;
T_1 V_194 = V_77 ;
if ( ! ( F_54 ( V_191 , V_36 -> V_61 ) || V_192 ) )
return F_10 ( V_15 , - V_73 ) ;
V_194 |= ( V_36 -> V_18 & V_49 ) ;
F_8 ( V_15 , V_6 , V_194 ) ;
F_8 ( V_15 , V_11 , V_193 ) ;
F_8 ( V_15 , V_12 , V_193 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
F_103 ( & V_15 -> V_2 , V_117 , V_191 ) ;
return F_101 ( V_15 , & V_15 -> V_2 , V_191 , false , true , V_99 ) ;
}
static inline void F_104 ( struct V_195 * V_196 )
{
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
}
static inline void F_105 ( struct V_195 * V_196 )
{
F_106 ( V_196 -> V_197 ) ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
}
static inline int F_107 ( struct V_195 * V_196 ,
const T_5 * V_198 ,
unsigned int V_199 )
{
F_105 ( V_196 ) ;
if ( V_199 > sizeof( V_196 -> V_43 ) ) {
V_196 -> V_197 = F_108 ( V_198 , V_199 , V_200 ) ;
if ( ! V_196 -> V_197 )
return - V_180 ;
} else {
memcpy ( V_196 -> V_43 , V_198 , V_199 ) ;
}
V_196 -> V_201 = true ;
V_196 -> V_199 = V_199 ;
return 0 ;
}
static inline bool F_109 ( const struct V_195 * V_196 ,
const T_5 * * V_198 ,
unsigned int * V_199 )
{
if ( ! V_196 -> V_201 )
return false ;
* V_199 = V_196 -> V_199 ;
* V_198 = ( V_196 -> V_197 ) ? V_196 -> V_197 : V_196 -> V_43 ;
return true ;
}
static int F_110 ( struct V_14 * V_15 ,
T_4 V_99 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
unsigned int V_199 ;
const T_5 * V_198 ;
T_2 V_171 ;
V_203 -> V_99 = V_99 ;
switch ( V_36 -> V_18 & V_49 ) {
case V_60 :
V_36 -> V_61 = V_62 ;
V_36 -> V_204 = V_59 ;
break;
case V_64 :
V_36 -> V_61 = V_65 ;
V_36 -> V_204 = V_66 ;
break;
case V_67 :
V_36 -> V_61 = V_68 ;
V_36 -> V_204 = V_66 ;
break;
case V_50 :
V_36 -> V_61 = V_70 ;
V_36 -> V_204 = V_71 ;
break;
case V_51 :
V_36 -> V_61 = V_72 ;
V_36 -> V_204 = V_71 ;
break;
default:
return F_10 ( V_15 , - V_73 ) ;
}
V_171 = V_36 -> V_61 ;
if ( F_31 ( ! F_109 ( & V_203 -> V_196 , & V_198 , & V_199 ) ) )
return V_99 ( V_15 ) ;
if ( F_33 ( V_199 > V_171 ) )
return F_111 ( V_15 , V_198 , V_199 ) ;
memcpy ( ( T_5 * ) V_203 -> V_205 , V_198 , V_199 ) ;
memset ( ( T_5 * ) V_203 -> V_205 + V_199 , 0 , V_171 - V_199 ) ;
return F_112 ( V_15 ) ;
}
static int F_111 ( struct V_14 * V_15 ,
const T_5 * V_198 , unsigned int V_199 )
{
return F_102 ( V_15 , V_198 , V_199 , true ,
V_206 ) ;
}
static int V_206 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_207 = F_29 ( V_58 ) ;
T_2 V_171 = V_36 -> V_61 ;
T_2 V_78 , V_183 = V_207 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
V_203 -> V_205 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
memset ( ( T_5 * ) V_203 -> V_205 + V_207 , 0 , V_171 - V_207 ) ;
return F_112 ( V_15 ) ;
}
static int F_112 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_171 = V_36 -> V_61 ;
T_2 V_78 , V_183 = V_171 / sizeof( T_1 ) ;
memcpy ( V_203 -> V_208 , V_203 -> V_205 , V_171 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 ) {
V_203 -> V_205 [ V_78 ] ^= 0x36363636 ;
V_203 -> V_208 [ V_78 ] ^= 0x5c5c5c5c ;
}
return F_102 ( V_15 , V_203 -> V_205 , V_171 , false ,
V_209 ) ;
}
static int V_209 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_171 = V_36 -> V_61 ;
T_2 V_210 = V_36 -> V_204 ;
T_2 V_78 , V_183 = V_210 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
V_203 -> V_205 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
return F_102 ( V_15 , V_203 -> V_208 , V_171 , false ,
V_211 ) ;
}
static int V_211 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_210 = V_36 -> V_204 ;
T_2 V_78 , V_183 = V_210 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
V_203 -> V_208 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
F_105 ( & V_203 -> V_196 ) ;
return V_203 -> V_99 ( V_15 ) ;
}
static int F_113 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
int V_21 ;
V_21 = F_65 ( V_15 ) ;
if ( V_21 )
return F_10 ( V_15 , V_21 ) ;
switch ( V_36 -> V_149 ) {
case V_212 :
V_21 = F_110 ( V_15 , V_213 ) ;
break;
case V_152 :
V_15 -> V_99 = V_151 ;
V_21 = F_59 ( V_15 ) ;
break;
case V_153 :
V_15 -> V_99 = V_214 ;
V_21 = F_60 ( V_15 ) ;
break;
case V_215 :
V_21 = F_110 ( V_15 , V_216 ) ;
break;
default:
return F_10 ( V_15 , - V_73 ) ;
}
return V_21 ;
}
static int F_114 ( struct V_57 * V_58 , const T_5 * V_198 ,
unsigned int V_199 )
{
struct V_202 * V_203 = F_26 ( V_58 ) ;
if ( F_107 ( & V_203 -> V_196 , V_198 , V_199 ) ) {
F_115 ( V_58 , V_217 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_116 ( struct V_22 * V_23 )
{
int V_21 ;
V_21 = F_24 ( V_23 ) ;
if ( V_21 )
return V_21 ;
return F_79 ( V_23 , V_212 ) ;
}
static int V_213 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
T_2 V_171 = V_36 -> V_61 ;
T_2 V_210 = V_36 -> V_204 ;
V_36 -> V_38 = 0 ;
V_36 -> V_48 [ 0 ] = V_171 ;
V_36 -> V_48 [ 1 ] = 0 ;
V_36 -> V_18 |= V_94 ;
memcpy ( V_36 -> V_96 , V_203 -> V_205 , V_210 ) ;
return F_10 ( V_15 , 0 ) ;
}
static int V_214 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
T_1 * V_96 = ( T_1 * ) V_36 -> V_96 ;
T_2 V_207 = F_29 ( V_58 ) ;
T_2 V_171 = V_36 -> V_61 ;
T_2 V_210 = V_36 -> V_204 ;
T_2 V_78 , V_183 ;
T_1 V_194 ;
V_183 = V_207 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
V_96 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
F_8 ( V_15 , V_5 , V_97 ) ;
V_183 = V_210 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_203 -> V_208 [ V_78 ] ) ;
V_194 = V_77 | V_98 ;
V_194 |= ( V_36 -> V_18 & V_49 ) ;
F_8 ( V_15 , V_6 , V_194 ) ;
F_8 ( V_15 , V_11 , V_171 + V_207 ) ;
F_8 ( V_15 , V_12 , V_207 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
F_103 ( & V_15 -> V_2 , V_96 , V_207 ) ;
return F_101 ( V_15 , & V_15 -> V_2 , V_207 , false , true ,
V_218 ) ;
}
static int V_218 ( struct V_14 * V_15 )
{
F_61 ( V_15 -> V_23 ) ;
F_62 ( V_15 -> V_23 ) ;
return F_10 ( V_15 , 0 ) ;
}
static int F_117 ( struct V_22 * V_23 )
{
int V_21 ;
V_21 = F_24 ( V_23 ) ;
if ( V_21 )
return V_21 ;
return F_79 ( V_23 , V_215 ) ;
}
static int V_216 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
T_2 V_210 = V_36 -> V_204 ;
T_2 V_78 , V_183 = V_210 / sizeof( T_1 ) ;
bool V_219 = false ;
T_1 V_194 ;
if ( ! V_23 -> V_150 )
return F_10 ( V_15 , - V_73 ) ;
if ( V_23 -> V_150 > V_136 &&
F_93 ( V_15 , V_23 -> V_154 , V_23 -> V_150 ) )
V_219 = true ;
F_8 ( V_15 , V_5 , V_97 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_203 -> V_205 [ V_78 ] ) ;
F_8 ( V_15 , V_5 , V_220 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_203 -> V_208 [ V_78 ] ) ;
V_194 = ( V_221 | V_85 ) ;
V_194 |= V_36 -> V_18 & V_49 ;
if ( V_219 )
V_194 |= V_222 ;
else
V_194 |= V_77 ;
F_8 ( V_15 , V_6 , V_194 ) ;
F_8 ( V_15 , V_11 , V_23 -> V_150 ) ;
F_8 ( V_15 , V_12 , V_23 -> V_150 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
if ( V_219 )
return F_97 ( V_15 , V_23 -> V_154 , V_23 -> V_150 ,
V_218 ) ;
return F_101 ( V_15 , V_23 -> V_154 , V_23 -> V_150 , false , true ,
V_218 ) ;
}
static int F_118 ( struct V_160 * V_58 )
{
struct V_202 * V_203 = F_76 ( V_58 ) ;
F_87 ( F_88 ( V_58 ) ,
sizeof( struct V_35 ) ) ;
V_203 -> V_32 . V_148 = F_113 ;
F_104 ( & V_203 -> V_196 ) ;
return 0 ;
}
static void F_119 ( struct V_160 * V_58 )
{
struct V_202 * V_203 = F_76 ( V_58 ) ;
F_105 ( & V_203 -> V_196 ) ;
}
static void F_120 ( struct V_142 * V_223 ,
int V_21 )
{
struct V_22 * V_23 = V_223 -> V_117 ;
struct V_224 * V_225 = F_27 ( V_23 ) ;
V_225 -> V_226 ( V_225 -> V_227 , V_21 , V_225 -> V_32 . V_15 -> V_30 ) ;
}
static int F_121 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_224 * V_225 = F_27 ( V_23 ) ;
int V_21 ;
V_15 -> V_31 = true ;
V_21 = F_65 ( V_15 ) ;
return V_225 -> V_226 ( V_225 -> V_227 , V_21 , V_15 -> V_30 ) ;
}
bool F_122 ( void )
{
struct V_53 V_228 ;
V_228 . V_15 = NULL ;
return ( F_20 ( & V_228 ) != NULL ) ;
}
unsigned int F_123 ( void )
{
return sizeof( struct V_224 ) ;
}
struct V_229 * F_124 ( unsigned long V_230 )
{
struct V_229 * V_231 ;
struct V_57 * V_58 ;
struct V_53 * V_54 ;
const char * V_232 ;
int V_21 = - V_73 ;
switch ( V_230 & V_233 ) {
case V_234 :
V_232 = L_31 ;
break;
case V_235 :
V_232 = L_32 ;
break;
case V_236 :
V_232 = L_33 ;
break;
case V_237 :
V_232 = L_34 ;
break;
case V_238 :
V_232 = L_35 ;
break;
default:
goto error;
}
V_58 = F_125 ( V_232 ,
V_239 ,
V_240 ) ;
if ( F_126 ( V_58 ) ) {
V_21 = F_127 ( V_58 ) ;
goto error;
}
V_54 = F_26 ( V_58 ) ;
V_54 -> V_148 = F_121 ;
V_54 -> V_18 = V_230 ;
V_231 = F_128 ( sizeof( * V_231 ) , V_200 ) ;
if ( ! V_231 ) {
V_21 = - V_180 ;
goto V_241;
}
V_231 -> V_58 = V_58 ;
return V_231 ;
V_241:
F_129 ( V_58 ) ;
error:
return F_130 ( V_21 ) ;
}
void F_131 ( struct V_229 * V_231 )
{
if ( V_231 )
F_129 ( V_231 -> V_58 ) ;
F_106 ( V_231 ) ;
}
int F_132 ( struct V_229 * V_231 ,
const T_5 * V_198 , unsigned int V_199 ,
T_1 * V_18 )
{
struct V_57 * V_58 = V_231 -> V_58 ;
int V_21 ;
F_133 ( V_58 , V_242 ) ;
F_115 ( V_58 , * V_18 & V_242 ) ;
V_21 = F_134 ( V_58 , V_198 , V_199 ) ;
* V_18 = F_135 ( V_58 ) ;
return V_21 ;
}
int F_136 ( struct V_22 * V_23 ,
struct V_229 * V_231 ,
T_9 V_226 ,
struct V_243 * V_227 )
{
struct V_224 * V_225 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_225 -> V_32 ;
struct V_57 * V_58 = V_231 -> V_58 ;
struct V_53 * V_54 = F_26 ( V_58 ) ;
struct V_14 * V_15 ;
memset ( V_225 , 0 , sizeof( * V_225 ) ) ;
V_15 = F_20 ( V_54 ) ;
if ( ! V_15 )
return V_226 ( V_227 , - V_244 , false ) ;
V_36 -> V_15 = V_15 ;
V_36 -> V_39 = V_74 ;
V_225 -> V_226 = V_226 ;
V_225 -> V_227 = V_227 ;
F_137 ( V_23 , V_58 ) ;
F_138 ( V_23 , 0 , F_120 , V_23 ) ;
return F_70 ( V_15 , V_23 ) ;
}
int F_139 ( struct V_22 * V_23 ,
struct V_120 * V_245 , unsigned int V_246 ,
unsigned int V_247 ,
T_9 V_226 ,
struct V_243 * V_227 )
{
struct V_224 * V_225 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_225 -> V_32 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
struct V_14 * V_15 = V_36 -> V_15 ;
if ( F_33 ( ! F_54 ( V_246 , sizeof( T_1 ) ) ) )
return F_10 ( V_15 , - V_73 ) ;
V_225 -> V_226 = V_226 ;
V_225 -> V_227 = V_227 ;
V_225 -> V_245 = V_245 ;
V_225 -> V_246 = V_246 ;
V_225 -> V_247 = V_247 ;
V_36 -> V_18 = V_203 -> V_32 . V_18 ;
return F_110 ( V_15 , V_248 ) ;
}
static int V_248 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_224 * V_225 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_225 -> V_32 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_202 * V_203 = F_26 ( V_58 ) ;
T_2 V_210 = V_36 -> V_204 ;
T_2 V_78 , V_183 = V_210 / sizeof( T_1 ) ;
T_1 V_194 , V_249 ;
F_8 ( V_15 , V_5 , V_97 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_203 -> V_205 [ V_78 ] ) ;
F_8 ( V_15 , V_5 , V_220 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_203 -> V_208 [ V_78 ] ) ;
V_194 = ( V_222 |
V_221 |
V_85 ) ;
V_194 |= V_36 -> V_18 & V_49 ;
F_8 ( V_15 , V_6 , V_194 ) ;
V_249 = V_225 -> V_246 + V_225 -> V_247 ;
F_8 ( V_15 , V_11 , V_249 ) ;
F_8 ( V_15 , V_12 , V_249 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
return F_101 ( V_15 , V_225 -> V_245 , V_225 -> V_246 ,
true , false ,
V_250 ) ;
}
static int V_250 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_224 * V_225 = F_27 ( V_23 ) ;
return V_225 -> V_226 ( V_225 -> V_227 , 0 , V_15 -> V_30 ) ;
}
int F_140 ( struct V_22 * V_23 ,
T_1 * V_96 , unsigned int V_251 ,
T_9 V_226 ,
struct V_243 * V_227 )
{
struct V_224 * V_225 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_225 -> V_32 ;
struct V_14 * V_15 = V_36 -> V_15 ;
switch ( V_36 -> V_18 & V_49 ) {
case V_60 :
V_225 -> V_251 = V_59 ;
break;
case V_64 :
V_225 -> V_251 = V_63 ;
break;
case V_67 :
V_225 -> V_251 = V_66 ;
break;
case V_50 :
V_225 -> V_251 = V_69 ;
break;
case V_51 :
V_225 -> V_251 = V_71 ;
break;
default:
return F_10 ( V_15 , - V_73 ) ;
}
if ( V_225 -> V_251 > V_251 )
V_225 -> V_251 = V_251 ;
V_225 -> V_226 = V_226 ;
V_225 -> V_227 = V_227 ;
V_225 -> V_96 = V_96 ;
return F_32 ( V_15 ,
V_252 ) ;
}
static int V_252 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_224 * V_225 = F_27 ( V_23 ) ;
T_2 V_78 , V_183 = V_225 -> V_251 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_183 ; ++ V_78 )
V_225 -> V_96 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
return F_10 ( V_15 , 0 ) ;
}
void F_141 ( struct V_22 * V_23 )
{
struct V_224 * V_225 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_225 -> V_32 ;
struct V_14 * V_15 = V_36 -> V_15 ;
V_15 -> V_30 = false ;
V_15 -> V_31 = false ;
( void ) F_10 ( V_15 , 0 ) ;
}
static void F_142 ( struct V_14 * V_15 )
{
int V_78 ;
if ( V_15 -> V_80 . V_253 )
for ( V_78 = 0 ; V_78 < F_143 ( V_254 ) ; V_78 ++ )
F_144 ( & V_254 [ V_78 ] ) ;
for ( V_78 = 0 ; V_78 < F_143 ( V_255 ) ; V_78 ++ )
F_144 ( & V_255 [ V_78 ] ) ;
if ( V_15 -> V_80 . V_256 )
F_144 ( & V_257 ) ;
if ( V_15 -> V_80 . V_258 ) {
for ( V_78 = 0 ; V_78 < F_143 ( V_259 ) ; V_78 ++ )
F_144 ( & V_259 [ V_78 ] ) ;
}
}
static int F_145 ( struct V_14 * V_15 )
{
int V_21 , V_78 , V_260 ;
for ( V_78 = 0 ; V_78 < F_143 ( V_255 ) ; V_78 ++ ) {
V_21 = F_146 ( & V_255 [ V_78 ] ) ;
if ( V_21 )
goto V_261;
}
if ( V_15 -> V_80 . V_256 ) {
V_21 = F_146 ( & V_257 ) ;
if ( V_21 )
goto V_262;
}
if ( V_15 -> V_80 . V_258 ) {
for ( V_78 = 0 ; V_78 < F_143 ( V_259 ) ; V_78 ++ ) {
V_21 = F_146 ( & V_259 [ V_78 ] ) ;
if ( V_21 )
goto V_263;
}
}
if ( V_15 -> V_80 . V_253 ) {
for ( V_78 = 0 ; V_78 < F_143 ( V_254 ) ; V_78 ++ ) {
V_21 = F_146 ( & V_254 [ V_78 ] ) ;
if ( V_21 )
goto V_264;
}
}
return 0 ;
V_264:
for ( V_260 = 0 ; V_260 < V_78 ; V_260 ++ )
F_144 ( & V_254 [ V_260 ] ) ;
V_78 = F_143 ( V_259 ) ;
V_263:
for ( V_260 = 0 ; V_260 < V_78 ; V_260 ++ )
F_144 ( & V_259 [ V_260 ] ) ;
F_144 ( & V_257 ) ;
V_262:
V_78 = F_143 ( V_255 ) ;
V_261:
for ( V_260 = 0 ; V_260 < V_78 ; V_260 ++ )
F_144 ( & V_255 [ V_260 ] ) ;
return V_21 ;
}
static bool F_147 ( struct V_176 * V_125 , void * V_265 )
{
struct V_266 * V_267 = V_265 ;
if ( V_267 && V_267 -> V_268 == V_125 -> V_269 -> V_20 ) {
V_125 -> V_270 = V_267 ;
return true ;
} else {
return false ;
}
}
static int F_148 ( struct V_14 * V_15 ,
struct V_271 * V_272 )
{
int V_21 = - V_180 ;
T_10 V_273 ;
F_149 ( V_273 ) ;
F_150 ( V_274 , V_273 ) ;
V_15 -> V_121 . V_125 = F_151 ( V_273 ,
F_147 , & V_272 -> V_275 -> V_276 , V_15 -> V_20 , L_36 ) ;
if ( ! V_15 -> V_121 . V_125 ) {
F_92 ( V_15 -> V_20 , L_37 ) ;
return V_21 ;
}
V_15 -> V_121 . V_122 . V_277 = V_126 ;
V_15 -> V_121 . V_122 . V_278 = V_15 -> V_279 +
F_2 ( 0 ) ;
V_15 -> V_121 . V_122 . V_123 = 1 ;
V_15 -> V_121 . V_122 . V_280 =
V_281 ;
V_15 -> V_121 . V_122 . V_124 = 1 ;
V_15 -> V_121 . V_122 . V_282 =
V_281 ;
V_15 -> V_121 . V_122 . V_283 = false ;
return 0 ;
}
static void F_152 ( struct V_14 * V_15 )
{
F_153 ( V_15 -> V_121 . V_125 ) ;
}
static void F_154 ( struct V_14 * V_15 )
{
V_15 -> V_80 . V_81 = 0 ;
V_15 -> V_80 . V_84 = 0 ;
V_15 -> V_80 . V_256 = 0 ;
V_15 -> V_80 . V_258 = 0 ;
V_15 -> V_80 . V_93 = 0 ;
V_15 -> V_80 . V_253 = 0 ;
switch ( V_15 -> V_141 & 0xff0 ) {
case 0x510 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_256 = 1 ;
V_15 -> V_80 . V_258 = 1 ;
V_15 -> V_80 . V_93 = 1 ;
V_15 -> V_80 . V_253 = 1 ;
break;
case 0x420 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_256 = 1 ;
V_15 -> V_80 . V_258 = 1 ;
V_15 -> V_80 . V_93 = 1 ;
break;
case 0x410 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_256 = 1 ;
V_15 -> V_80 . V_258 = 1 ;
break;
case 0x400 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_256 = 1 ;
break;
case 0x320 :
break;
default:
F_92 ( V_15 -> V_20 ,
L_38 ) ;
break;
}
}
static struct V_271 * F_155 ( struct V_284 * V_285 )
{
struct V_286 * V_287 = V_285 -> V_20 . V_288 ;
struct V_271 * V_272 ;
if ( ! V_287 ) {
F_51 ( & V_285 -> V_20 , L_39 ) ;
return F_130 ( - V_73 ) ;
}
V_272 = F_156 ( & V_285 -> V_20 , sizeof( * V_272 ) , V_200 ) ;
if ( ! V_272 ) {
F_51 ( & V_285 -> V_20 , L_40 ) ;
return F_130 ( - V_180 ) ;
}
V_272 -> V_275 = F_156 ( & V_285 -> V_20 ,
sizeof( * ( V_272 -> V_275 ) ) ,
V_200 ) ;
if ( ! V_272 -> V_275 ) {
F_51 ( & V_285 -> V_20 , L_41 ) ;
return F_130 ( - V_180 ) ;
}
return V_272 ;
}
static inline struct V_271 * F_155 ( struct V_284 * V_20 )
{
return F_130 ( - V_73 ) ;
}
static int F_157 ( struct V_284 * V_285 )
{
struct V_14 * V_164 ;
struct V_271 * V_272 ;
struct V_269 * V_20 = & V_285 -> V_20 ;
struct V_289 * V_290 ;
int V_21 ;
V_164 = F_156 ( & V_285 -> V_20 , sizeof( * V_164 ) , V_200 ) ;
if ( V_164 == NULL ) {
F_51 ( V_20 , L_42 ) ;
V_21 = - V_180 ;
goto V_291;
}
V_164 -> V_20 = V_20 ;
F_158 ( V_285 , V_164 ) ;
F_159 ( & V_164 -> V_292 ) ;
F_160 ( & V_164 -> V_56 ) ;
F_161 ( & V_164 -> V_166 , F_90 ,
( unsigned long ) V_164 ) ;
F_161 ( & V_164 -> V_34 , F_89 ,
( unsigned long ) V_164 ) ;
F_162 ( & V_164 -> V_147 , V_293 ) ;
V_164 -> V_162 = - 1 ;
V_290 = F_163 ( V_285 , V_294 , 0 ) ;
if ( ! V_290 ) {
F_51 ( V_20 , L_43 ) ;
V_21 = - V_244 ;
goto V_295;
}
V_164 -> V_279 = V_290 -> V_148 ;
V_164 -> V_162 = F_164 ( V_285 , 0 ) ;
if ( V_164 -> V_162 < 0 ) {
F_51 ( V_20 , L_44 ) ;
V_21 = V_164 -> V_162 ;
goto V_295;
}
V_21 = F_165 ( & V_285 -> V_20 , V_164 -> V_162 , F_91 ,
V_296 , L_45 , V_164 ) ;
if ( V_21 ) {
F_51 ( V_20 , L_46 ) ;
goto V_295;
}
V_164 -> V_29 = F_166 ( & V_285 -> V_20 , L_47 ) ;
if ( F_126 ( V_164 -> V_29 ) ) {
F_51 ( V_20 , L_48 ) ;
V_21 = F_127 ( V_164 -> V_29 ) ;
goto V_295;
}
V_164 -> V_17 = F_167 ( & V_285 -> V_20 , V_290 ) ;
if ( F_126 ( V_164 -> V_17 ) ) {
F_51 ( V_20 , L_49 ) ;
V_21 = F_127 ( V_164 -> V_17 ) ;
goto V_295;
}
V_21 = F_168 ( V_164 -> V_29 ) ;
if ( V_21 )
goto V_295;
F_68 ( V_164 ) ;
F_154 ( V_164 ) ;
if ( V_164 -> V_80 . V_81 ) {
V_272 = V_285 -> V_20 . V_297 ;
if ( ! V_272 ) {
V_272 = F_155 ( V_285 ) ;
if ( F_126 ( V_272 ) ) {
F_51 ( & V_285 -> V_20 , L_50 ) ;
V_21 = F_127 ( V_272 ) ;
goto V_298;
}
}
if ( ! V_272 -> V_275 ) {
V_21 = - V_299 ;
goto V_298;
}
V_21 = F_148 ( V_164 , V_272 ) ;
if ( V_21 )
goto V_300;
F_69 ( V_20 , L_51 ,
F_169 ( V_164 -> V_121 . V_125 ) ) ;
}
F_170 ( & V_55 . V_56 ) ;
F_171 ( & V_164 -> V_292 , & V_55 . V_301 ) ;
F_172 ( & V_55 . V_56 ) ;
V_21 = F_145 ( V_164 ) ;
if ( V_21 )
goto V_302;
F_69 ( V_20 , L_52 ,
V_164 -> V_80 . V_256 ? L_53 : L_54 ,
V_164 -> V_80 . V_258 ? L_55 : L_54 ) ;
return 0 ;
V_302:
F_170 ( & V_55 . V_56 ) ;
F_173 ( & V_164 -> V_292 ) ;
F_172 ( & V_55 . V_56 ) ;
if ( V_164 -> V_80 . V_81 )
F_152 ( V_164 ) ;
V_300:
V_298:
F_174 ( V_164 -> V_29 ) ;
V_295:
F_175 ( & V_164 -> V_34 ) ;
F_175 ( & V_164 -> V_166 ) ;
V_291:
F_51 ( V_20 , L_56 ) ;
return V_21 ;
}
static int F_176 ( struct V_284 * V_285 )
{
static struct V_14 * V_164 ;
V_164 = F_177 ( V_285 ) ;
if ( ! V_164 )
return - V_244 ;
F_170 ( & V_55 . V_56 ) ;
F_173 ( & V_164 -> V_292 ) ;
F_172 ( & V_55 . V_56 ) ;
F_142 ( V_164 ) ;
F_175 ( & V_164 -> V_34 ) ;
F_175 ( & V_164 -> V_166 ) ;
if ( V_164 -> V_80 . V_81 )
F_152 ( V_164 ) ;
F_174 ( V_164 -> V_29 ) ;
return 0 ;
}
