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
if ( V_155 == - V_101 ||
( V_155 == - V_157 && ( F_83 ( V_23 ) &
V_158 ) ) )
return V_155 ;
V_156 = F_81 ( V_23 ) ;
return V_155 ? : V_156 ;
}
static int F_84 ( struct V_22 * V_23 )
{
return F_24 ( V_23 ) ? : F_82 ( V_23 ) ;
}
static int F_85 ( struct V_22 * V_23 , void * V_159 )
{
const struct V_35 * V_36 = F_27 ( V_23 ) ;
memcpy ( V_159 , V_36 , sizeof( * V_36 ) ) ;
return 0 ;
}
static int F_86 ( struct V_22 * V_23 , const void * V_160 )
{
struct V_35 * V_36 = F_27 ( V_23 ) ;
memcpy ( V_36 , V_160 , sizeof( * V_36 ) ) ;
return 0 ;
}
static int F_87 ( struct V_161 * V_58 )
{
struct V_53 * V_36 = F_76 ( V_58 ) ;
F_88 ( F_89 ( V_58 ) ,
sizeof( struct V_35 ) ) ;
V_36 -> V_148 = F_78 ;
return 0 ;
}
static void F_90 ( unsigned long V_117 )
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
goto V_162;
}
} else if ( V_27 & V_15 -> V_18 ) {
if ( V_115 & V_15 -> V_18 ) {
V_15 -> V_18 &= ~ V_115 ;
F_56 ( V_15 ) ;
if ( V_15 -> V_21 ) {
V_21 = V_15 -> V_21 ;
goto V_162;
}
}
if ( V_28 & V_15 -> V_18 ) {
V_15 -> V_18 &= ~ ( V_27 |
V_28 ) ;
V_21 = F_53 ( V_15 ) ;
if ( V_21 != - V_101 )
goto V_162;
}
}
return V_21 ;
V_162:
F_64 ( V_15 -> V_23 , V_21 ) ;
return V_21 ;
}
static void F_91 ( unsigned long V_117 )
{
struct V_14 * V_15 = (struct V_14 * ) V_117 ;
V_15 -> V_30 = true ;
( void ) V_15 -> V_99 ( V_15 ) ;
}
static T_7 F_92 ( int V_163 , void * V_164 )
{
struct V_14 * V_165 = V_164 ;
T_1 V_166 ;
V_166 = F_4 ( V_165 , V_10 ) ;
if ( V_166 & F_4 ( V_165 , V_9 ) ) {
F_8 ( V_165 , V_8 , V_166 ) ;
if ( V_24 & V_165 -> V_18 ) {
V_165 -> V_18 |= V_28 ;
if ( ! ( V_26 & V_165 -> V_18 ) )
V_165 -> V_18 |= V_27 ;
F_12 ( & V_165 -> V_167 ) ;
} else {
F_93 ( V_165 -> V_20 , L_30 ) ;
}
return V_168 ;
}
return V_169 ;
}
static bool F_94 ( struct V_14 * V_15 ,
struct V_120 * V_41 ,
T_2 V_170 )
{
struct V_171 * V_75 = & V_15 -> V_121 ;
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_172 = V_36 -> V_61 ;
int V_173 ;
for ( V_173 = 0 ; V_41 ; V_41 = F_16 ( V_41 ) , ++ V_173 ) {
if ( ! F_54 ( V_41 -> V_1 , sizeof( T_1 ) ) )
return false ;
if ( V_170 <= V_41 -> V_42 ) {
V_75 -> V_173 = V_173 + 1 ;
V_75 -> V_174 = V_41 -> V_42 ;
V_41 -> V_42 = F_95 ( V_170 , sizeof( T_1 ) ) ;
return true ;
}
if ( ! F_54 ( V_41 -> V_42 , V_172 ) )
return false ;
V_170 -= V_41 -> V_42 ;
}
return false ;
}
static void F_96 ( void * V_117 )
{
struct V_14 * V_15 = V_117 ;
struct V_171 * V_75 = & V_15 -> V_121 ;
struct V_120 * V_41 ;
int V_173 ;
F_97 ( V_75 -> V_125 ) ;
F_57 ( V_15 -> V_20 , V_75 -> V_41 , V_75 -> V_173 , V_132 ) ;
V_41 = V_75 -> V_41 ;
for ( V_173 = 0 ; V_173 < V_75 -> V_173 - 1 ; ++ V_173 )
V_41 = F_16 ( V_41 ) ;
V_41 -> V_42 = V_75 -> V_174 ;
V_15 -> V_30 = true ;
( void ) F_32 ( V_15 , V_15 -> V_99 ) ;
}
static int F_98 ( struct V_14 * V_15 ,
struct V_120 * V_154 ,
T_2 V_170 ,
T_4 V_99 )
{
struct V_171 * V_75 = & V_15 -> V_121 ;
struct V_175 * V_176 = & V_75 -> V_122 ;
struct V_177 * V_125 = V_75 -> V_125 ;
struct V_118 * V_178 ;
T_8 V_179 ;
unsigned int V_180 ;
int V_21 ;
V_15 -> V_99 = V_99 ;
V_75 -> V_41 = V_154 ;
V_180 = F_55 ( V_15 -> V_20 , V_75 -> V_41 , V_75 -> V_173 , V_132 ) ;
if ( ! V_180 ) {
V_21 = - V_181 ;
goto exit;
}
V_176 -> V_123 = 16 ;
V_176 -> V_124 = 16 ;
V_21 = F_39 ( V_125 , V_176 ) ;
if ( V_21 )
goto V_182;
V_178 = F_43 ( V_125 , V_75 -> V_41 , V_180 , V_126 ,
V_127 | V_128 ) ;
if ( ! V_178 ) {
V_21 = - V_181 ;
goto V_182;
}
V_178 -> V_129 = F_96 ;
V_178 -> V_130 = V_15 ;
V_179 = F_44 ( V_178 ) ;
V_21 = F_99 ( V_179 ) ;
if ( V_21 )
goto V_182;
F_45 ( V_125 ) ;
return - V_101 ;
V_182:
F_57 ( V_15 -> V_20 , V_75 -> V_41 , V_75 -> V_173 , V_132 ) ;
exit:
return F_10 ( V_15 , V_21 ) ;
}
static int F_100 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
const T_1 * V_183 = ( const T_1 * ) V_36 -> V_43 ;
T_2 V_78 , V_184 ;
T_1 V_100 , V_185 , V_186 ;
V_186 = ( V_36 -> V_18 & V_187 ) ? 0 : 1 ;
for (; ; ) {
V_184 = F_35 ( V_36 -> V_38 , sizeof( T_1 ) ) ;
for ( V_78 = 0 , V_185 = 0 ; V_78 < V_184 ; ++ V_78 , V_185 += V_186 )
F_8 ( V_15 , F_2 ( V_185 ) , V_183 [ V_78 ] ) ;
V_36 -> V_1 += V_36 -> V_38 ;
V_36 -> V_40 -= V_36 -> V_38 ;
if ( ! V_36 -> V_40 )
break;
V_36 -> V_38 = F_101 ( T_2 , V_36 -> V_61 , V_36 -> V_40 ) ;
F_17 ( V_36 -> V_43 , V_36 -> V_41 ,
V_36 -> V_1 , V_36 -> V_38 , 0 ) ;
V_100 = F_4 ( V_15 , V_10 ) ;
if ( ! ( V_100 & V_86 ) ) {
V_15 -> V_99 = F_100 ;
F_8 ( V_15 , V_7 , V_86 ) ;
return - V_101 ;
}
}
if ( F_33 ( ! ( V_36 -> V_18 & V_188 ) ) )
return V_15 -> V_189 ( V_15 ) ;
return F_32 ( V_15 , V_15 -> V_189 ) ;
}
static int F_102 ( struct V_14 * V_15 ,
struct V_120 * V_41 ,
unsigned int V_170 ,
bool V_190 ,
bool V_191 ,
T_4 V_99 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
if ( ! V_170 )
return V_99 ( V_15 ) ;
V_36 -> V_18 &= ~ ( V_187 | V_188 ) ;
if ( V_190 )
V_36 -> V_18 |= V_187 ;
if ( V_191 )
V_36 -> V_18 |= V_188 ;
V_36 -> V_41 = V_41 ;
V_36 -> V_40 = V_170 ;
V_36 -> V_1 = 0 ;
V_36 -> V_38 = F_101 ( T_2 , V_36 -> V_61 , V_36 -> V_40 ) ;
F_17 ( V_36 -> V_43 , V_36 -> V_41 ,
V_36 -> V_1 , V_36 -> V_38 , 0 ) ;
V_15 -> V_189 = V_99 ;
return F_100 ( V_15 ) ;
}
static int F_103 ( struct V_14 * V_15 ,
const void * V_117 , unsigned int V_192 ,
bool V_193 ,
T_4 V_99 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_1 V_194 = ( V_193 ) ? V_192 : 0 ;
T_1 V_195 = V_77 ;
if ( ! ( F_54 ( V_192 , V_36 -> V_61 ) || V_193 ) )
return F_10 ( V_15 , - V_73 ) ;
V_195 |= ( V_36 -> V_18 & V_49 ) ;
F_8 ( V_15 , V_6 , V_195 ) ;
F_8 ( V_15 , V_11 , V_194 ) ;
F_8 ( V_15 , V_12 , V_194 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
F_104 ( & V_15 -> V_2 , V_117 , V_192 ) ;
return F_102 ( V_15 , & V_15 -> V_2 , V_192 , false , true , V_99 ) ;
}
static inline void F_105 ( struct V_196 * V_197 )
{
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
}
static inline void F_106 ( struct V_196 * V_197 )
{
F_107 ( V_197 -> V_198 ) ;
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
}
static inline int F_108 ( struct V_196 * V_197 ,
const T_5 * V_199 ,
unsigned int V_200 )
{
F_106 ( V_197 ) ;
if ( V_200 > sizeof( V_197 -> V_43 ) ) {
V_197 -> V_198 = F_109 ( V_199 , V_200 , V_201 ) ;
if ( ! V_197 -> V_198 )
return - V_181 ;
} else {
memcpy ( V_197 -> V_43 , V_199 , V_200 ) ;
}
V_197 -> V_202 = true ;
V_197 -> V_200 = V_200 ;
return 0 ;
}
static inline bool F_110 ( const struct V_196 * V_197 ,
const T_5 * * V_199 ,
unsigned int * V_200 )
{
if ( ! V_197 -> V_202 )
return false ;
* V_200 = V_197 -> V_200 ;
* V_199 = ( V_197 -> V_198 ) ? V_197 -> V_198 : V_197 -> V_43 ;
return true ;
}
static int F_111 ( struct V_14 * V_15 ,
T_4 V_99 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
unsigned int V_200 ;
const T_5 * V_199 ;
T_2 V_172 ;
V_204 -> V_99 = V_99 ;
switch ( V_36 -> V_18 & V_49 ) {
case V_60 :
V_36 -> V_61 = V_62 ;
V_36 -> V_205 = V_59 ;
break;
case V_64 :
V_36 -> V_61 = V_65 ;
V_36 -> V_205 = V_66 ;
break;
case V_67 :
V_36 -> V_61 = V_68 ;
V_36 -> V_205 = V_66 ;
break;
case V_50 :
V_36 -> V_61 = V_70 ;
V_36 -> V_205 = V_71 ;
break;
case V_51 :
V_36 -> V_61 = V_72 ;
V_36 -> V_205 = V_71 ;
break;
default:
return F_10 ( V_15 , - V_73 ) ;
}
V_172 = V_36 -> V_61 ;
if ( F_31 ( ! F_110 ( & V_204 -> V_197 , & V_199 , & V_200 ) ) )
return V_99 ( V_15 ) ;
if ( F_33 ( V_200 > V_172 ) )
return F_112 ( V_15 , V_199 , V_200 ) ;
memcpy ( ( T_5 * ) V_204 -> V_206 , V_199 , V_200 ) ;
memset ( ( T_5 * ) V_204 -> V_206 + V_200 , 0 , V_172 - V_200 ) ;
return F_113 ( V_15 ) ;
}
static int F_112 ( struct V_14 * V_15 ,
const T_5 * V_199 , unsigned int V_200 )
{
return F_103 ( V_15 , V_199 , V_200 , true ,
V_207 ) ;
}
static int V_207 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_208 = F_29 ( V_58 ) ;
T_2 V_172 = V_36 -> V_61 ;
T_2 V_78 , V_184 = V_208 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
V_204 -> V_206 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
memset ( ( T_5 * ) V_204 -> V_206 + V_208 , 0 , V_172 - V_208 ) ;
return F_113 ( V_15 ) ;
}
static int F_113 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_172 = V_36 -> V_61 ;
T_2 V_78 , V_184 = V_172 / sizeof( T_1 ) ;
memcpy ( V_204 -> V_209 , V_204 -> V_206 , V_172 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 ) {
V_204 -> V_206 [ V_78 ] ^= 0x36363636 ;
V_204 -> V_209 [ V_78 ] ^= 0x5c5c5c5c ;
}
return F_103 ( V_15 , V_204 -> V_206 , V_172 , false ,
V_210 ) ;
}
static int V_210 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_172 = V_36 -> V_61 ;
T_2 V_211 = V_36 -> V_205 ;
T_2 V_78 , V_184 = V_211 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
V_204 -> V_206 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
return F_103 ( V_15 , V_204 -> V_209 , V_172 , false ,
V_212 ) ;
}
static int V_212 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
T_2 V_211 = V_36 -> V_205 ;
T_2 V_78 , V_184 = V_211 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
V_204 -> V_209 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
F_106 ( & V_204 -> V_197 ) ;
return V_204 -> V_99 ( V_15 ) ;
}
static int F_114 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
int V_21 ;
V_21 = F_65 ( V_15 ) ;
if ( V_21 )
return F_10 ( V_15 , V_21 ) ;
switch ( V_36 -> V_149 ) {
case V_213 :
V_21 = F_111 ( V_15 , V_214 ) ;
break;
case V_152 :
V_15 -> V_99 = V_151 ;
V_21 = F_59 ( V_15 ) ;
break;
case V_153 :
V_15 -> V_99 = V_215 ;
V_21 = F_60 ( V_15 ) ;
break;
case V_216 :
V_21 = F_111 ( V_15 , V_217 ) ;
break;
default:
return F_10 ( V_15 , - V_73 ) ;
}
return V_21 ;
}
static int F_115 ( struct V_57 * V_58 , const T_5 * V_199 ,
unsigned int V_200 )
{
struct V_203 * V_204 = F_26 ( V_58 ) ;
if ( F_108 ( & V_204 -> V_197 , V_199 , V_200 ) ) {
F_116 ( V_58 , V_218 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_117 ( struct V_22 * V_23 )
{
int V_21 ;
V_21 = F_24 ( V_23 ) ;
if ( V_21 )
return V_21 ;
return F_79 ( V_23 , V_213 ) ;
}
static int V_214 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
T_2 V_172 = V_36 -> V_61 ;
T_2 V_211 = V_36 -> V_205 ;
V_36 -> V_38 = 0 ;
V_36 -> V_48 [ 0 ] = V_172 ;
V_36 -> V_48 [ 1 ] = 0 ;
V_36 -> V_18 |= V_94 ;
memcpy ( V_36 -> V_96 , V_204 -> V_206 , V_211 ) ;
return F_10 ( V_15 , 0 ) ;
}
static int V_215 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
T_1 * V_96 = ( T_1 * ) V_36 -> V_96 ;
T_2 V_208 = F_29 ( V_58 ) ;
T_2 V_172 = V_36 -> V_61 ;
T_2 V_211 = V_36 -> V_205 ;
T_2 V_78 , V_184 ;
T_1 V_195 ;
V_184 = V_208 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
V_96 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
F_8 ( V_15 , V_5 , V_97 ) ;
V_184 = V_211 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_204 -> V_209 [ V_78 ] ) ;
V_195 = V_77 | V_98 ;
V_195 |= ( V_36 -> V_18 & V_49 ) ;
F_8 ( V_15 , V_6 , V_195 ) ;
F_8 ( V_15 , V_11 , V_172 + V_208 ) ;
F_8 ( V_15 , V_12 , V_208 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
F_104 ( & V_15 -> V_2 , V_96 , V_208 ) ;
return F_102 ( V_15 , & V_15 -> V_2 , V_208 , false , true ,
V_219 ) ;
}
static int V_219 ( struct V_14 * V_15 )
{
F_61 ( V_15 -> V_23 ) ;
F_62 ( V_15 -> V_23 ) ;
return F_10 ( V_15 , 0 ) ;
}
static int F_118 ( struct V_22 * V_23 )
{
int V_21 ;
V_21 = F_24 ( V_23 ) ;
if ( V_21 )
return V_21 ;
return F_79 ( V_23 , V_216 ) ;
}
static int V_217 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_35 * V_36 = F_27 ( V_23 ) ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
T_2 V_211 = V_36 -> V_205 ;
T_2 V_78 , V_184 = V_211 / sizeof( T_1 ) ;
bool V_220 = false ;
T_1 V_195 ;
if ( ! V_23 -> V_150 )
return F_10 ( V_15 , - V_73 ) ;
if ( V_23 -> V_150 > V_136 &&
F_94 ( V_15 , V_23 -> V_154 , V_23 -> V_150 ) )
V_220 = true ;
F_8 ( V_15 , V_5 , V_97 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_204 -> V_206 [ V_78 ] ) ;
F_8 ( V_15 , V_5 , V_221 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_204 -> V_209 [ V_78 ] ) ;
V_195 = ( V_222 | V_85 ) ;
V_195 |= V_36 -> V_18 & V_49 ;
if ( V_220 )
V_195 |= V_223 ;
else
V_195 |= V_77 ;
F_8 ( V_15 , V_6 , V_195 ) ;
F_8 ( V_15 , V_11 , V_23 -> V_150 ) ;
F_8 ( V_15 , V_12 , V_23 -> V_150 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
if ( V_220 )
return F_98 ( V_15 , V_23 -> V_154 , V_23 -> V_150 ,
V_219 ) ;
return F_102 ( V_15 , V_23 -> V_154 , V_23 -> V_150 , false , true ,
V_219 ) ;
}
static int F_119 ( struct V_161 * V_58 )
{
struct V_203 * V_204 = F_76 ( V_58 ) ;
F_88 ( F_89 ( V_58 ) ,
sizeof( struct V_35 ) ) ;
V_204 -> V_32 . V_148 = F_114 ;
F_105 ( & V_204 -> V_197 ) ;
return 0 ;
}
static void F_120 ( struct V_161 * V_58 )
{
struct V_203 * V_204 = F_76 ( V_58 ) ;
F_106 ( & V_204 -> V_197 ) ;
}
static void F_121 ( struct V_142 * V_224 ,
int V_21 )
{
struct V_22 * V_23 = V_224 -> V_117 ;
struct V_225 * V_226 = F_27 ( V_23 ) ;
V_226 -> V_227 ( V_226 -> V_228 , V_21 , V_226 -> V_32 . V_15 -> V_30 ) ;
}
static int F_122 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_225 * V_226 = F_27 ( V_23 ) ;
int V_21 ;
V_15 -> V_31 = true ;
V_21 = F_65 ( V_15 ) ;
return V_226 -> V_227 ( V_226 -> V_228 , V_21 , V_15 -> V_30 ) ;
}
bool F_123 ( void )
{
struct V_53 V_229 ;
V_229 . V_15 = NULL ;
return ( F_20 ( & V_229 ) != NULL ) ;
}
unsigned int F_124 ( void )
{
return sizeof( struct V_225 ) ;
}
struct V_230 * F_125 ( unsigned long V_231 )
{
struct V_230 * V_232 ;
struct V_57 * V_58 ;
struct V_53 * V_54 ;
const char * V_233 ;
int V_21 = - V_73 ;
switch ( V_231 & V_234 ) {
case V_235 :
V_233 = L_31 ;
break;
case V_236 :
V_233 = L_32 ;
break;
case V_237 :
V_233 = L_33 ;
break;
case V_238 :
V_233 = L_34 ;
break;
case V_239 :
V_233 = L_35 ;
break;
default:
goto error;
}
V_58 = F_126 ( V_233 ,
V_240 ,
V_241 ) ;
if ( F_127 ( V_58 ) ) {
V_21 = F_128 ( V_58 ) ;
goto error;
}
V_54 = F_26 ( V_58 ) ;
V_54 -> V_148 = F_122 ;
V_54 -> V_18 = V_231 ;
V_232 = F_129 ( sizeof( * V_232 ) , V_201 ) ;
if ( ! V_232 ) {
V_21 = - V_181 ;
goto V_242;
}
V_232 -> V_58 = V_58 ;
return V_232 ;
V_242:
F_130 ( V_58 ) ;
error:
return F_131 ( V_21 ) ;
}
void F_132 ( struct V_230 * V_232 )
{
if ( V_232 )
F_130 ( V_232 -> V_58 ) ;
F_107 ( V_232 ) ;
}
int F_133 ( struct V_230 * V_232 ,
const T_5 * V_199 , unsigned int V_200 ,
T_1 * V_18 )
{
struct V_57 * V_58 = V_232 -> V_58 ;
int V_21 ;
F_134 ( V_58 , V_243 ) ;
F_116 ( V_58 , * V_18 & V_243 ) ;
V_21 = F_135 ( V_58 , V_199 , V_200 ) ;
* V_18 = F_136 ( V_58 ) ;
return V_21 ;
}
int F_137 ( struct V_22 * V_23 ,
struct V_230 * V_232 ,
T_9 V_227 ,
struct V_244 * V_228 )
{
struct V_225 * V_226 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_226 -> V_32 ;
struct V_57 * V_58 = V_232 -> V_58 ;
struct V_53 * V_54 = F_26 ( V_58 ) ;
struct V_14 * V_15 ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
V_15 = F_20 ( V_54 ) ;
if ( ! V_15 )
return V_227 ( V_228 , - V_245 , false ) ;
V_36 -> V_15 = V_15 ;
V_36 -> V_39 = V_74 ;
V_226 -> V_227 = V_227 ;
V_226 -> V_228 = V_228 ;
F_138 ( V_23 , V_58 ) ;
F_139 ( V_23 , 0 , F_121 , V_23 ) ;
return F_70 ( V_15 , V_23 ) ;
}
int F_140 ( struct V_22 * V_23 ,
struct V_120 * V_246 , unsigned int V_247 ,
unsigned int V_248 ,
T_9 V_227 ,
struct V_244 * V_228 )
{
struct V_225 * V_226 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_226 -> V_32 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
struct V_14 * V_15 = V_36 -> V_15 ;
if ( F_33 ( ! F_54 ( V_247 , sizeof( T_1 ) ) ) )
return F_10 ( V_15 , - V_73 ) ;
V_226 -> V_227 = V_227 ;
V_226 -> V_228 = V_228 ;
V_226 -> V_246 = V_246 ;
V_226 -> V_247 = V_247 ;
V_226 -> V_248 = V_248 ;
V_36 -> V_18 = V_204 -> V_32 . V_18 ;
return F_111 ( V_15 , V_249 ) ;
}
static int V_249 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_225 * V_226 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_226 -> V_32 ;
struct V_57 * V_58 = F_25 ( V_23 ) ;
struct V_203 * V_204 = F_26 ( V_58 ) ;
T_2 V_211 = V_36 -> V_205 ;
T_2 V_78 , V_184 = V_211 / sizeof( T_1 ) ;
T_1 V_195 , V_250 ;
F_8 ( V_15 , V_5 , V_97 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_204 -> V_206 [ V_78 ] ) ;
F_8 ( V_15 , V_5 , V_221 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
F_8 ( V_15 , F_2 ( V_78 ) , V_204 -> V_209 [ V_78 ] ) ;
V_195 = ( V_223 |
V_222 |
V_85 ) ;
V_195 |= V_36 -> V_18 & V_49 ;
F_8 ( V_15 , V_6 , V_195 ) ;
V_250 = V_226 -> V_247 + V_226 -> V_248 ;
F_8 ( V_15 , V_11 , V_250 ) ;
F_8 ( V_15 , V_12 , V_250 ) ;
F_8 ( V_15 , V_5 , V_92 ) ;
return F_102 ( V_15 , V_226 -> V_246 , V_226 -> V_247 ,
true , false ,
V_251 ) ;
}
static int V_251 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_225 * V_226 = F_27 ( V_23 ) ;
return V_226 -> V_227 ( V_226 -> V_228 , 0 , V_15 -> V_30 ) ;
}
int F_141 ( struct V_22 * V_23 ,
T_1 * V_96 , unsigned int V_252 ,
T_9 V_227 ,
struct V_244 * V_228 )
{
struct V_225 * V_226 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_226 -> V_32 ;
struct V_14 * V_15 = V_36 -> V_15 ;
switch ( V_36 -> V_18 & V_49 ) {
case V_60 :
V_226 -> V_252 = V_59 ;
break;
case V_64 :
V_226 -> V_252 = V_63 ;
break;
case V_67 :
V_226 -> V_252 = V_66 ;
break;
case V_50 :
V_226 -> V_252 = V_69 ;
break;
case V_51 :
V_226 -> V_252 = V_71 ;
break;
default:
return F_10 ( V_15 , - V_73 ) ;
}
if ( V_226 -> V_252 > V_252 )
V_226 -> V_252 = V_252 ;
V_226 -> V_227 = V_227 ;
V_226 -> V_228 = V_228 ;
V_226 -> V_96 = V_96 ;
return F_32 ( V_15 ,
V_253 ) ;
}
static int V_253 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_23 ;
struct V_225 * V_226 = F_27 ( V_23 ) ;
T_2 V_78 , V_184 = V_226 -> V_252 / sizeof( T_1 ) ;
for ( V_78 = 0 ; V_78 < V_184 ; ++ V_78 )
V_226 -> V_96 [ V_78 ] = F_4 ( V_15 , F_3 ( V_78 ) ) ;
return F_10 ( V_15 , 0 ) ;
}
void F_142 ( struct V_22 * V_23 )
{
struct V_225 * V_226 = F_27 ( V_23 ) ;
struct V_35 * V_36 = & V_226 -> V_32 ;
struct V_14 * V_15 = V_36 -> V_15 ;
V_15 -> V_30 = false ;
V_15 -> V_31 = false ;
( void ) F_10 ( V_15 , 0 ) ;
}
static void F_143 ( struct V_14 * V_15 )
{
int V_78 ;
if ( V_15 -> V_80 . V_254 )
for ( V_78 = 0 ; V_78 < F_144 ( V_255 ) ; V_78 ++ )
F_145 ( & V_255 [ V_78 ] ) ;
for ( V_78 = 0 ; V_78 < F_144 ( V_256 ) ; V_78 ++ )
F_145 ( & V_256 [ V_78 ] ) ;
if ( V_15 -> V_80 . V_257 )
F_145 ( & V_258 ) ;
if ( V_15 -> V_80 . V_259 ) {
for ( V_78 = 0 ; V_78 < F_144 ( V_260 ) ; V_78 ++ )
F_145 ( & V_260 [ V_78 ] ) ;
}
}
static int F_146 ( struct V_14 * V_15 )
{
int V_21 , V_78 , V_261 ;
for ( V_78 = 0 ; V_78 < F_144 ( V_256 ) ; V_78 ++ ) {
V_21 = F_147 ( & V_256 [ V_78 ] ) ;
if ( V_21 )
goto V_262;
}
if ( V_15 -> V_80 . V_257 ) {
V_21 = F_147 ( & V_258 ) ;
if ( V_21 )
goto V_263;
}
if ( V_15 -> V_80 . V_259 ) {
for ( V_78 = 0 ; V_78 < F_144 ( V_260 ) ; V_78 ++ ) {
V_21 = F_147 ( & V_260 [ V_78 ] ) ;
if ( V_21 )
goto V_264;
}
}
if ( V_15 -> V_80 . V_254 ) {
for ( V_78 = 0 ; V_78 < F_144 ( V_255 ) ; V_78 ++ ) {
V_21 = F_147 ( & V_255 [ V_78 ] ) ;
if ( V_21 )
goto V_265;
}
}
return 0 ;
V_265:
for ( V_261 = 0 ; V_261 < V_78 ; V_261 ++ )
F_145 ( & V_255 [ V_261 ] ) ;
V_78 = F_144 ( V_260 ) ;
V_264:
for ( V_261 = 0 ; V_261 < V_78 ; V_261 ++ )
F_145 ( & V_260 [ V_261 ] ) ;
F_145 ( & V_258 ) ;
V_263:
V_78 = F_144 ( V_256 ) ;
V_262:
for ( V_261 = 0 ; V_261 < V_78 ; V_261 ++ )
F_145 ( & V_256 [ V_261 ] ) ;
return V_21 ;
}
static bool F_148 ( struct V_177 * V_125 , void * V_266 )
{
struct V_267 * V_268 = V_266 ;
if ( V_268 && V_268 -> V_269 == V_125 -> V_270 -> V_20 ) {
V_125 -> V_271 = V_268 ;
return true ;
} else {
return false ;
}
}
static int F_149 ( struct V_14 * V_15 ,
struct V_272 * V_273 )
{
int V_21 = - V_181 ;
T_10 V_274 ;
F_150 ( V_274 ) ;
F_151 ( V_275 , V_274 ) ;
V_15 -> V_121 . V_125 = F_152 ( V_274 ,
F_148 , & V_273 -> V_276 -> V_277 , V_15 -> V_20 , L_36 ) ;
if ( ! V_15 -> V_121 . V_125 ) {
F_93 ( V_15 -> V_20 , L_37 ) ;
return V_21 ;
}
V_15 -> V_121 . V_122 . V_278 = V_126 ;
V_15 -> V_121 . V_122 . V_279 = V_15 -> V_280 +
F_2 ( 0 ) ;
V_15 -> V_121 . V_122 . V_123 = 1 ;
V_15 -> V_121 . V_122 . V_281 =
V_282 ;
V_15 -> V_121 . V_122 . V_124 = 1 ;
V_15 -> V_121 . V_122 . V_283 =
V_282 ;
V_15 -> V_121 . V_122 . V_284 = false ;
return 0 ;
}
static void F_153 ( struct V_14 * V_15 )
{
F_154 ( V_15 -> V_121 . V_125 ) ;
}
static void F_155 ( struct V_14 * V_15 )
{
V_15 -> V_80 . V_81 = 0 ;
V_15 -> V_80 . V_84 = 0 ;
V_15 -> V_80 . V_257 = 0 ;
V_15 -> V_80 . V_259 = 0 ;
V_15 -> V_80 . V_93 = 0 ;
V_15 -> V_80 . V_254 = 0 ;
switch ( V_15 -> V_141 & 0xff0 ) {
case 0x510 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_257 = 1 ;
V_15 -> V_80 . V_259 = 1 ;
V_15 -> V_80 . V_93 = 1 ;
V_15 -> V_80 . V_254 = 1 ;
break;
case 0x420 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_257 = 1 ;
V_15 -> V_80 . V_259 = 1 ;
V_15 -> V_80 . V_93 = 1 ;
break;
case 0x410 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_257 = 1 ;
V_15 -> V_80 . V_259 = 1 ;
break;
case 0x400 :
V_15 -> V_80 . V_81 = 1 ;
V_15 -> V_80 . V_84 = 1 ;
V_15 -> V_80 . V_257 = 1 ;
break;
case 0x320 :
break;
default:
F_93 ( V_15 -> V_20 ,
L_38 ) ;
break;
}
}
static struct V_272 * F_156 ( struct V_285 * V_286 )
{
struct V_287 * V_288 = V_286 -> V_20 . V_289 ;
struct V_272 * V_273 ;
if ( ! V_288 ) {
F_51 ( & V_286 -> V_20 , L_39 ) ;
return F_131 ( - V_73 ) ;
}
V_273 = F_157 ( & V_286 -> V_20 , sizeof( * V_273 ) , V_201 ) ;
if ( ! V_273 ) {
F_51 ( & V_286 -> V_20 , L_40 ) ;
return F_131 ( - V_181 ) ;
}
V_273 -> V_276 = F_157 ( & V_286 -> V_20 ,
sizeof( * ( V_273 -> V_276 ) ) ,
V_201 ) ;
if ( ! V_273 -> V_276 ) {
F_51 ( & V_286 -> V_20 , L_41 ) ;
return F_131 ( - V_181 ) ;
}
return V_273 ;
}
static inline struct V_272 * F_156 ( struct V_285 * V_20 )
{
return F_131 ( - V_73 ) ;
}
static int F_158 ( struct V_285 * V_286 )
{
struct V_14 * V_165 ;
struct V_272 * V_273 ;
struct V_270 * V_20 = & V_286 -> V_20 ;
struct V_290 * V_291 ;
int V_21 ;
V_165 = F_157 ( & V_286 -> V_20 , sizeof( * V_165 ) , V_201 ) ;
if ( V_165 == NULL ) {
F_51 ( V_20 , L_42 ) ;
V_21 = - V_181 ;
goto V_292;
}
V_165 -> V_20 = V_20 ;
F_159 ( V_286 , V_165 ) ;
F_160 ( & V_165 -> V_293 ) ;
F_161 ( & V_165 -> V_56 ) ;
F_162 ( & V_165 -> V_167 , F_91 ,
( unsigned long ) V_165 ) ;
F_162 ( & V_165 -> V_34 , F_90 ,
( unsigned long ) V_165 ) ;
F_163 ( & V_165 -> V_147 , V_294 ) ;
V_165 -> V_163 = - 1 ;
V_291 = F_164 ( V_286 , V_295 , 0 ) ;
if ( ! V_291 ) {
F_51 ( V_20 , L_43 ) ;
V_21 = - V_245 ;
goto V_296;
}
V_165 -> V_280 = V_291 -> V_148 ;
V_165 -> V_163 = F_165 ( V_286 , 0 ) ;
if ( V_165 -> V_163 < 0 ) {
F_51 ( V_20 , L_44 ) ;
V_21 = V_165 -> V_163 ;
goto V_296;
}
V_21 = F_166 ( & V_286 -> V_20 , V_165 -> V_163 , F_92 ,
V_297 , L_45 , V_165 ) ;
if ( V_21 ) {
F_51 ( V_20 , L_46 ) ;
goto V_296;
}
V_165 -> V_29 = F_167 ( & V_286 -> V_20 , L_47 ) ;
if ( F_127 ( V_165 -> V_29 ) ) {
F_51 ( V_20 , L_48 ) ;
V_21 = F_128 ( V_165 -> V_29 ) ;
goto V_296;
}
V_165 -> V_17 = F_168 ( & V_286 -> V_20 , V_291 ) ;
if ( F_127 ( V_165 -> V_17 ) ) {
F_51 ( V_20 , L_49 ) ;
V_21 = F_128 ( V_165 -> V_17 ) ;
goto V_296;
}
V_21 = F_169 ( V_165 -> V_29 ) ;
if ( V_21 )
goto V_296;
F_68 ( V_165 ) ;
F_155 ( V_165 ) ;
if ( V_165 -> V_80 . V_81 ) {
V_273 = V_286 -> V_20 . V_298 ;
if ( ! V_273 ) {
V_273 = F_156 ( V_286 ) ;
if ( F_127 ( V_273 ) ) {
F_51 ( & V_286 -> V_20 , L_50 ) ;
V_21 = F_128 ( V_273 ) ;
goto V_299;
}
}
if ( ! V_273 -> V_276 ) {
V_21 = - V_300 ;
goto V_299;
}
V_21 = F_149 ( V_165 , V_273 ) ;
if ( V_21 )
goto V_301;
F_69 ( V_20 , L_51 ,
F_170 ( V_165 -> V_121 . V_125 ) ) ;
}
F_171 ( & V_55 . V_56 ) ;
F_172 ( & V_165 -> V_293 , & V_55 . V_302 ) ;
F_173 ( & V_55 . V_56 ) ;
V_21 = F_146 ( V_165 ) ;
if ( V_21 )
goto V_303;
F_69 ( V_20 , L_52 ,
V_165 -> V_80 . V_257 ? L_53 : L_54 ,
V_165 -> V_80 . V_259 ? L_55 : L_54 ) ;
return 0 ;
V_303:
F_171 ( & V_55 . V_56 ) ;
F_174 ( & V_165 -> V_293 ) ;
F_173 ( & V_55 . V_56 ) ;
if ( V_165 -> V_80 . V_81 )
F_153 ( V_165 ) ;
V_301:
V_299:
F_175 ( V_165 -> V_29 ) ;
V_296:
F_176 ( & V_165 -> V_34 ) ;
F_176 ( & V_165 -> V_167 ) ;
V_292:
F_51 ( V_20 , L_56 ) ;
return V_21 ;
}
static int F_177 ( struct V_285 * V_286 )
{
struct V_14 * V_165 ;
V_165 = F_178 ( V_286 ) ;
if ( ! V_165 )
return - V_245 ;
F_171 ( & V_55 . V_56 ) ;
F_174 ( & V_165 -> V_293 ) ;
F_173 ( & V_55 . V_56 ) ;
F_143 ( V_165 ) ;
F_176 ( & V_165 -> V_34 ) ;
F_176 ( & V_165 -> V_167 ) ;
if ( V_165 -> V_80 . V_81 )
F_153 ( V_165 ) ;
F_175 ( V_165 -> V_29 ) ;
return 0 ;
}
