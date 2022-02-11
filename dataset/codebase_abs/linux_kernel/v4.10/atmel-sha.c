static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_2 F_5 ( struct V_6 * V_7 )
{
T_2 V_8 ;
while ( ( V_7 -> V_9 < V_7 -> V_10 ) && V_7 -> V_11 ) {
V_8 = F_6 ( V_7 -> V_12 -> V_13 - V_7 -> V_3 , V_7 -> V_11 ) ;
V_8 = F_6 ( V_8 , V_7 -> V_10 - V_7 -> V_9 ) ;
if ( V_8 <= 0 ) {
if ( ( V_7 -> V_12 -> V_13 == 0 ) && ! F_7 ( V_7 -> V_12 ) ) {
V_7 -> V_12 = F_8 ( V_7 -> V_12 ) ;
continue;
} else {
break;
}
}
F_9 ( V_7 -> V_14 + V_7 -> V_9 , V_7 -> V_12 ,
V_7 -> V_3 , V_8 , 0 ) ;
V_7 -> V_9 += V_8 ;
V_7 -> V_3 += V_8 ;
V_7 -> V_11 -= V_8 ;
if ( V_7 -> V_3 == V_7 -> V_12 -> V_13 ) {
V_7 -> V_12 = F_8 ( V_7 -> V_12 ) ;
if ( V_7 -> V_12 )
V_7 -> V_3 = 0 ;
else
V_7 -> V_11 = 0 ;
}
}
return 0 ;
}
static void F_10 ( struct V_6 * V_7 , int V_13 )
{
unsigned int V_15 , V_16 ;
T_3 V_17 [ 2 ] ;
T_3 V_18 [ 2 ] ;
V_18 [ 0 ] = V_7 -> V_19 [ 0 ] ;
V_18 [ 1 ] = V_7 -> V_19 [ 1 ] ;
V_18 [ 0 ] += V_7 -> V_9 ;
if ( V_18 [ 0 ] < V_7 -> V_9 )
V_18 [ 1 ] ++ ;
V_18 [ 0 ] += V_13 ;
if ( V_18 [ 0 ] < V_13 )
V_18 [ 1 ] ++ ;
V_17 [ 1 ] = F_11 ( V_18 [ 0 ] << 3 ) ;
V_17 [ 0 ] = F_11 ( V_18 [ 1 ] << 3 | V_18 [ 0 ] >> 61 ) ;
if ( V_7 -> V_20 & ( V_21 | V_22 ) ) {
V_15 = V_7 -> V_9 & 0x7f ;
V_16 = ( V_15 < 112 ) ? ( 112 - V_15 ) : ( ( 128 + 112 ) - V_15 ) ;
* ( V_7 -> V_14 + V_7 -> V_9 ) = 0x80 ;
memset ( V_7 -> V_14 + V_7 -> V_9 + 1 , 0 , V_16 - 1 ) ;
memcpy ( V_7 -> V_14 + V_7 -> V_9 + V_16 , V_17 , 16 ) ;
V_7 -> V_9 += V_16 + 16 ;
V_7 -> V_20 |= V_23 ;
} else {
V_15 = V_7 -> V_9 & 0x3f ;
V_16 = ( V_15 < 56 ) ? ( 56 - V_15 ) : ( ( 64 + 56 ) - V_15 ) ;
* ( V_7 -> V_14 + V_7 -> V_9 ) = 0x80 ;
memset ( V_7 -> V_14 + V_7 -> V_9 + 1 , 0 , V_16 - 1 ) ;
memcpy ( V_7 -> V_14 + V_7 -> V_9 + V_16 , & V_17 [ 1 ] , 8 ) ;
V_7 -> V_9 += V_16 + 8 ;
V_7 -> V_20 |= V_23 ;
}
}
static int F_12 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_6 * V_7 = F_15 ( V_25 ) ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_30 ;
F_16 ( & V_31 . V_32 ) ;
if ( ! V_29 -> V_2 ) {
F_17 (tmp, &atmel_sha.dev_list, list) {
V_2 = V_30 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_18 ( & V_31 . V_32 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_20 = 0 ;
F_19 ( V_2 -> V_33 , L_1 ,
F_20 ( V_27 ) ) ;
switch ( F_20 ( V_27 ) ) {
case V_34 :
V_7 -> V_20 |= V_35 ;
V_7 -> V_36 = V_37 ;
break;
case V_38 :
V_7 -> V_20 |= V_39 ;
V_7 -> V_36 = V_40 ;
break;
case V_41 :
V_7 -> V_20 |= V_42 ;
V_7 -> V_36 = V_43 ;
break;
case V_44 :
V_7 -> V_20 |= V_21 ;
V_7 -> V_36 = V_45 ;
break;
case V_46 :
V_7 -> V_20 |= V_22 ;
V_7 -> V_36 = V_47 ;
break;
default:
return - V_48 ;
break;
}
V_7 -> V_9 = 0 ;
V_7 -> V_19 [ 0 ] = 0 ;
V_7 -> V_19 [ 1 ] = 0 ;
V_7 -> V_10 = V_49 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_50 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
T_1 V_51 = V_52 ;
unsigned int V_53 , V_54 = 0 ;
if ( F_22 ( V_50 ) ) {
if ( ! V_2 -> V_55 . V_56 )
F_3 ( V_2 , V_57 , V_58 ) ;
V_51 = V_59 ;
if ( V_2 -> V_55 . V_60 )
V_51 |= V_61 ;
} else {
F_3 ( V_2 , V_57 , V_62 ) ;
}
switch ( V_7 -> V_20 & V_63 ) {
case V_35 :
V_51 |= V_64 ;
V_54 = V_34 ;
break;
case V_39 :
V_51 |= V_65 ;
V_54 = V_41 ;
break;
case V_42 :
V_51 |= V_66 ;
V_54 = V_41 ;
break;
case V_21 :
V_51 |= V_67 ;
V_54 = V_46 ;
break;
case V_22 :
V_51 |= V_68 ;
V_54 = V_46 ;
break;
default:
break;
}
if ( ! ( V_7 -> V_19 [ 0 ] || V_7 -> V_19 [ 1 ] ) ) {
F_3 ( V_2 , V_69 , V_70 ) ;
} else if ( V_2 -> V_55 . V_71 && ( V_7 -> V_20 & V_72 ) ) {
const T_1 * V_73 = ( const T_1 * ) V_7 -> V_74 ;
V_7 -> V_20 &= ~ V_72 ;
F_3 ( V_2 , V_69 , V_75 ) ;
for ( V_53 = 0 ; V_53 < V_54 / sizeof( T_1 ) ; ++ V_53 )
F_3 ( V_2 , F_23 ( V_53 ) , V_73 [ V_53 ] ) ;
F_3 ( V_2 , V_69 , V_70 ) ;
V_51 |= V_76 ;
}
F_3 ( V_2 , V_77 , V_51 ) ;
}
static int F_24 ( struct V_1 * V_2 , const T_4 * V_78 ,
T_2 V_13 , int V_79 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
int V_8 , V_80 ;
const T_1 * V_14 = ( const T_1 * ) V_78 ;
F_19 ( V_2 -> V_33 , L_2 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_13 , V_79 ) ;
F_21 ( V_2 , 0 ) ;
V_7 -> V_19 [ 0 ] += V_13 ;
if ( V_7 -> V_19 [ 0 ] < V_13 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_79 )
V_2 -> V_20 |= V_81 ;
V_80 = F_25 ( V_13 , sizeof( T_1 ) ) ;
V_2 -> V_20 |= V_82 ;
for ( V_8 = 0 ; V_8 < V_80 ; V_8 ++ )
F_3 ( V_2 , F_23 ( V_8 ) , V_14 [ V_8 ] ) ;
return - V_83 ;
}
static int F_26 ( struct V_1 * V_2 , T_5 V_84 ,
T_2 V_85 , T_5 V_86 , T_2 V_87 , int V_79 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
int V_80 ;
F_19 ( V_2 -> V_33 , L_3 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_85 , V_79 ) ;
V_80 = F_25 ( V_85 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_88 , V_89 ) ;
F_3 ( V_2 , V_90 , V_84 ) ;
F_3 ( V_2 , V_91 , V_80 ) ;
V_80 = F_25 ( V_87 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_92 , V_86 ) ;
F_3 ( V_2 , V_93 , V_80 ) ;
F_21 ( V_2 , 1 ) ;
V_7 -> V_19 [ 0 ] += V_85 ;
if ( V_7 -> V_19 [ 0 ] < V_85 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_79 )
V_2 -> V_20 |= V_81 ;
V_2 -> V_20 |= V_94 ;
F_3 ( V_2 , V_88 , V_95 ) ;
return - V_83 ;
}
static void F_27 ( void * V_96 )
{
struct V_1 * V_2 = V_96 ;
F_3 ( V_2 , V_57 , V_62 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_5 V_84 ,
T_2 V_85 , T_5 V_86 , T_2 V_87 , int V_79 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
struct V_97 * V_98 ;
struct V_99 V_12 [ 2 ] ;
F_19 ( V_2 -> V_33 , L_4 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_85 , V_79 ) ;
V_2 -> V_100 . V_101 . V_102 = 16 ;
V_2 -> V_100 . V_101 . V_103 = 16 ;
F_29 ( V_2 -> V_100 . V_104 , & V_2 -> V_100 . V_101 ) ;
if ( V_87 ) {
F_30 ( V_12 , 2 ) ;
F_31 ( & V_12 [ 0 ] ) = V_84 ;
F_32 ( & V_12 [ 0 ] ) = V_85 ;
F_31 ( & V_12 [ 1 ] ) = V_86 ;
F_32 ( & V_12 [ 1 ] ) = V_87 ;
V_98 = F_33 ( V_2 -> V_100 . V_104 , V_12 , 2 ,
V_105 , V_106 | V_107 ) ;
} else {
F_30 ( V_12 , 1 ) ;
F_31 ( & V_12 [ 0 ] ) = V_84 ;
F_32 ( & V_12 [ 0 ] ) = V_85 ;
V_98 = F_33 ( V_2 -> V_100 . V_104 , V_12 , 1 ,
V_105 , V_106 | V_107 ) ;
}
if ( ! V_98 )
return - V_48 ;
V_98 -> V_108 = F_27 ;
V_98 -> V_109 = V_2 ;
F_21 ( V_2 , 1 ) ;
V_7 -> V_19 [ 0 ] += V_85 ;
if ( V_7 -> V_19 [ 0 ] < V_85 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_79 )
V_2 -> V_20 |= V_81 ;
V_2 -> V_20 |= V_94 ;
F_34 ( V_98 ) ;
F_35 ( V_2 -> V_100 . V_104 ) ;
return - V_83 ;
}
static int F_36 ( struct V_1 * V_2 , T_5 V_84 ,
T_2 V_85 , T_5 V_86 , T_2 V_87 , int V_79 )
{
if ( V_2 -> V_55 . V_56 )
return F_28 ( V_2 , V_84 , V_85 ,
V_86 , V_87 , V_79 ) ;
else
return F_26 ( V_2 , V_84 , V_85 ,
V_86 , V_87 , V_79 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
int V_9 ;
F_5 ( V_7 ) ;
F_10 ( V_7 , 0 ) ;
V_9 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_24 ( V_2 , V_7 -> V_14 , V_9 , 1 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_2 V_13 , int V_79 )
{
V_7 -> V_110 = F_39 ( V_2 -> V_33 , V_7 -> V_14 ,
V_7 -> V_10 + V_7 -> V_36 , V_111 ) ;
if ( F_40 ( V_2 -> V_33 , V_7 -> V_110 ) ) {
F_41 ( V_2 -> V_33 , L_5 , V_7 -> V_10 +
V_7 -> V_36 ) ;
return - V_48 ;
}
V_7 -> V_20 &= ~ V_112 ;
return F_36 ( V_2 , V_7 -> V_110 , V_13 , 0 , 0 , V_79 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
unsigned int V_79 ;
T_2 V_8 ;
F_5 ( V_7 ) ;
V_79 = ( V_7 -> V_20 & V_113 ) && ! V_7 -> V_11 ;
F_19 ( V_2 -> V_33 , L_6 ,
V_7 -> V_9 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_79 ) ;
if ( V_79 )
F_10 ( V_7 , 0 ) ;
if ( V_79 || ( V_7 -> V_9 == V_7 -> V_10 ) ) {
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_38 ( V_2 , V_7 , V_8 , V_79 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
unsigned int V_13 , V_79 , V_114 ;
struct V_99 * V_12 ;
unsigned int V_8 ;
if ( ! V_7 -> V_11 )
return 0 ;
if ( V_7 -> V_9 || V_7 -> V_3 )
return F_42 ( V_2 ) ;
F_19 ( V_2 -> V_33 , L_7 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_7 -> V_9 , V_7 -> V_11 ) ;
V_12 = V_7 -> V_12 ;
if ( ! F_44 ( V_12 -> V_3 , sizeof( T_1 ) ) )
return F_42 ( V_2 ) ;
if ( ! F_7 ( V_12 ) && ! F_44 ( V_12 -> V_13 , V_7 -> V_36 ) )
return F_42 ( V_2 ) ;
V_13 = F_6 ( V_7 -> V_11 , V_12 -> V_13 ) ;
if ( F_7 ( V_12 ) ) {
if ( ! ( V_7 -> V_20 & V_113 ) ) {
V_114 = V_13 & ( V_7 -> V_36 - 1 ) ;
V_13 -= V_114 ;
}
}
V_7 -> V_11 -= V_13 ;
V_7 -> V_3 = V_13 ;
V_79 = ( V_7 -> V_20 & V_113 ) && ! V_7 -> V_11 ;
if ( V_79 ) {
V_114 = V_13 & ( V_7 -> V_36 - 1 ) ;
V_13 -= V_114 ;
V_7 -> V_11 += V_114 ;
V_7 -> V_3 = V_13 ;
V_12 = V_7 -> V_12 ;
F_5 ( V_7 ) ;
F_10 ( V_7 , V_13 ) ;
V_7 -> V_110 = F_39 ( V_2 -> V_33 , V_7 -> V_14 ,
V_7 -> V_10 + V_7 -> V_36 , V_111 ) ;
if ( F_40 ( V_2 -> V_33 , V_7 -> V_110 ) ) {
F_41 ( V_2 -> V_33 , L_5 ,
V_7 -> V_10 + V_7 -> V_36 ) ;
return - V_48 ;
}
if ( V_13 == 0 ) {
V_7 -> V_20 &= ~ V_112 ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_36 ( V_2 , V_7 -> V_110 , V_8 , 0 ,
0 , V_79 ) ;
} else {
V_7 -> V_12 = V_12 ;
if ( ! F_45 ( V_2 -> V_33 , V_7 -> V_12 , 1 ,
V_111 ) ) {
F_41 ( V_2 -> V_33 , L_8 ) ;
return - V_48 ;
}
V_7 -> V_20 |= V_112 ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_36 ( V_2 , F_31 ( V_7 -> V_12 ) ,
V_13 , V_7 -> V_110 , V_8 , V_79 ) ;
}
}
if ( ! F_45 ( V_2 -> V_33 , V_7 -> V_12 , 1 , V_111 ) ) {
F_41 ( V_2 -> V_33 , L_8 ) ;
return - V_48 ;
}
V_7 -> V_20 |= V_112 ;
return F_36 ( V_2 , F_31 ( V_7 -> V_12 ) , V_13 , 0 ,
0 , V_79 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
if ( V_7 -> V_20 & V_112 ) {
F_47 ( V_2 -> V_33 , V_7 -> V_12 , 1 , V_111 ) ;
if ( V_7 -> V_12 -> V_13 == V_7 -> V_3 ) {
V_7 -> V_12 = F_8 ( V_7 -> V_12 ) ;
if ( V_7 -> V_12 )
V_7 -> V_3 = 0 ;
}
if ( V_7 -> V_20 & V_23 ) {
F_48 ( V_2 -> V_33 , V_7 -> V_110 ,
V_7 -> V_10 + V_7 -> V_36 , V_111 ) ;
}
} else {
F_48 ( V_2 -> V_33 , V_7 -> V_110 , V_7 -> V_10 +
V_7 -> V_36 , V_111 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_6 * V_7 = F_15 ( V_25 ) ;
int V_115 ;
F_19 ( V_2 -> V_33 , L_9 ,
V_7 -> V_11 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] ) ;
if ( V_7 -> V_20 & V_82 )
V_115 = F_37 ( V_2 ) ;
else
V_115 = F_43 ( V_2 ) ;
F_19 ( V_2 -> V_33 , L_10 ,
V_115 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] ) ;
return V_115 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_6 * V_7 = F_15 ( V_25 ) ;
int V_115 = 0 ;
int V_8 ;
if ( V_7 -> V_9 >= V_116 ) {
F_10 ( V_7 , 0 ) ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
V_115 = F_38 ( V_2 , V_7 , V_8 , 1 ) ;
}
else {
F_10 ( V_7 , 0 ) ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
V_115 = F_24 ( V_2 , V_7 -> V_14 , V_8 , 1 ) ;
}
F_19 ( V_2 -> V_33 , L_11 , V_115 ) ;
return V_115 ;
}
static void F_51 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
T_1 * V_73 = ( T_1 * ) V_7 -> V_74 ;
unsigned int V_53 , V_54 ;
switch ( V_7 -> V_20 & V_63 ) {
case V_35 :
V_54 = V_34 ;
break;
case V_39 :
case V_42 :
V_54 = V_41 ;
break;
case V_21 :
case V_22 :
V_54 = V_46 ;
break;
default:
return;
}
for ( V_53 = 0 ; V_53 < V_54 / sizeof( T_1 ) ; ++ V_53 )
V_73 [ V_53 ] = F_1 ( V_7 -> V_2 , F_52 ( V_53 ) ) ;
V_7 -> V_20 |= V_72 ;
}
static void F_53 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
if ( ! V_25 -> V_117 )
return;
if ( V_7 -> V_20 & V_35 )
memcpy ( V_25 -> V_117 , V_7 -> V_74 , V_34 ) ;
else if ( V_7 -> V_20 & V_39 )
memcpy ( V_25 -> V_117 , V_7 -> V_74 , V_38 ) ;
else if ( V_7 -> V_20 & V_42 )
memcpy ( V_25 -> V_117 , V_7 -> V_74 , V_41 ) ;
else if ( V_7 -> V_20 & V_21 )
memcpy ( V_25 -> V_117 , V_7 -> V_74 , V_44 ) ;
else
memcpy ( V_25 -> V_117 , V_7 -> V_74 , V_46 ) ;
}
static int F_54 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_19 [ 0 ] || V_7 -> V_19 [ 1 ] )
F_53 ( V_25 ) ;
F_19 ( V_2 -> V_33 , L_12 , V_7 -> V_19 [ 1 ] ,
V_7 -> V_19 [ 0 ] , V_7 -> V_9 ) ;
return 0 ;
}
static void F_55 ( struct V_24 * V_25 , int V_115 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! V_115 ) {
F_51 ( V_25 ) ;
if ( V_81 & V_2 -> V_20 )
V_115 = F_54 ( V_25 ) ;
} else {
V_7 -> V_20 |= V_118 ;
}
V_2 -> V_20 &= ~ ( V_119 | V_81 | V_82 |
V_120 | V_121 ) ;
F_56 ( V_2 -> V_122 ) ;
if ( V_25 -> V_123 . V_124 )
V_25 -> V_123 . V_124 ( & V_25 -> V_123 , V_115 ) ;
F_57 ( & V_2 -> V_125 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_115 ;
V_115 = F_59 ( V_2 -> V_122 ) ;
if ( V_115 )
return V_115 ;
if ( ! ( V_126 & V_2 -> V_20 ) ) {
F_3 ( V_2 , V_69 , V_127 ) ;
V_2 -> V_20 |= V_126 ;
V_2 -> V_115 = 0 ;
}
return 0 ;
}
static inline unsigned int F_60 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_128 ) & 0x00000fff ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
V_2 -> V_129 = F_60 ( V_2 ) ;
F_62 ( V_2 -> V_33 ,
L_13 , V_2 -> V_129 ) ;
F_56 ( V_2 -> V_122 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_130 * V_131 , * V_132 ;
struct V_6 * V_7 ;
unsigned long V_20 ;
int V_115 = 0 , V_133 = 0 ;
F_64 ( & V_2 -> V_32 , V_20 ) ;
if ( V_25 )
V_133 = F_65 ( & V_2 -> V_134 , V_25 ) ;
if ( V_119 & V_2 -> V_20 ) {
F_66 ( & V_2 -> V_32 , V_20 ) ;
return V_133 ;
}
V_132 = F_67 ( & V_2 -> V_134 ) ;
V_131 = F_68 ( & V_2 -> V_134 ) ;
if ( V_131 )
V_2 -> V_20 |= V_119 ;
F_66 ( & V_2 -> V_32 , V_20 ) ;
if ( ! V_131 )
return V_133 ;
if ( V_132 )
V_132 -> V_124 ( V_132 , - V_83 ) ;
V_25 = F_69 ( V_131 ) ;
V_2 -> V_25 = V_25 ;
V_7 = F_15 ( V_25 ) ;
F_19 ( V_2 -> V_33 , L_14 ,
V_7 -> V_135 , V_25 -> V_136 ) ;
V_115 = F_58 ( V_2 ) ;
if ( V_115 )
goto V_137;
if ( V_7 -> V_135 == V_138 ) {
V_115 = F_49 ( V_2 ) ;
if ( V_115 != - V_83 && ( V_7 -> V_20 & V_113 ) )
V_115 = F_50 ( V_2 ) ;
} else if ( V_7 -> V_135 == V_139 ) {
V_115 = F_50 ( V_2 ) ;
}
V_137:
if ( V_115 != - V_83 )
F_55 ( V_25 , V_115 ) ;
F_19 ( V_2 -> V_33 , L_15 , V_115 ) ;
return V_133 ;
}
static int F_70 ( struct V_24 * V_25 , unsigned int V_135 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
struct V_28 * V_29 = F_71 ( V_25 -> V_123 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
V_7 -> V_135 = V_135 ;
return F_63 ( V_2 , V_25 ) ;
}
static int F_72 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
if ( ! V_25 -> V_136 )
return 0 ;
V_7 -> V_11 = V_25 -> V_136 ;
V_7 -> V_12 = V_25 -> V_140 ;
V_7 -> V_3 = 0 ;
if ( V_7 -> V_20 & V_113 ) {
if ( V_7 -> V_9 + V_7 -> V_11 < V_116 )
V_7 -> V_20 |= V_82 ;
} else if ( V_7 -> V_9 + V_7 -> V_11 < V_7 -> V_10 ) {
F_5 ( V_7 ) ;
return 0 ;
}
return F_70 ( V_25 , V_138 ) ;
}
static int F_73 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
V_7 -> V_20 |= V_113 ;
if ( V_7 -> V_20 & V_118 )
return 0 ;
if ( V_7 -> V_20 & V_23 )
return F_54 ( V_25 ) ;
return F_70 ( V_25 , V_139 ) ;
}
static int F_74 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
int V_137 , V_141 ;
V_7 -> V_20 |= V_113 ;
V_137 = F_72 ( V_25 ) ;
if ( V_137 == - V_83 || V_137 == - V_142 )
return V_137 ;
V_141 = F_73 ( V_25 ) ;
return V_137 ? : V_141 ;
}
static int F_75 ( struct V_24 * V_25 )
{
return F_12 ( V_25 ) ? : F_74 ( V_25 ) ;
}
static int F_76 ( struct V_24 * V_25 , void * V_143 )
{
const struct V_6 * V_7 = F_15 ( V_25 ) ;
memcpy ( V_143 , V_7 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_77 ( struct V_24 * V_25 , const void * V_144 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
memcpy ( V_7 , V_144 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_78 ( struct V_145 * V_27 )
{
F_79 ( F_80 ( V_27 ) ,
sizeof( struct V_6 ) ) ;
return 0 ;
}
static void F_81 ( unsigned long V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_96 ;
F_63 ( V_2 , NULL ) ;
}
static void F_82 ( unsigned long V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_96 ;
int V_115 = 0 ;
if ( V_82 & V_2 -> V_20 ) {
if ( V_121 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ V_121 ;
goto V_146;
}
} else if ( V_120 & V_2 -> V_20 ) {
if ( V_94 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ V_94 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_115 ) {
V_115 = V_2 -> V_115 ;
goto V_146;
}
}
if ( V_121 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ ( V_120 |
V_121 ) ;
V_115 = F_43 ( V_2 ) ;
if ( V_115 != - V_83 )
goto V_146;
}
}
return;
V_146:
F_55 ( V_2 -> V_25 , V_115 ) ;
}
static T_6 F_83 ( int V_147 , void * V_148 )
{
struct V_1 * V_149 = V_148 ;
T_1 V_150 ;
V_150 = F_1 ( V_149 , V_151 ) ;
if ( V_150 & F_1 ( V_149 , V_152 ) ) {
F_3 ( V_149 , V_153 , V_150 ) ;
if ( V_119 & V_149 -> V_20 ) {
V_149 -> V_20 |= V_121 ;
if ( ! ( V_82 & V_149 -> V_20 ) )
V_149 -> V_20 |= V_120 ;
F_57 ( & V_149 -> V_154 ) ;
} else {
F_84 ( V_149 -> V_33 , L_16 ) ;
}
return V_155 ;
}
return V_156 ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_86 ( V_157 ) ; V_53 ++ )
F_87 ( & V_157 [ V_53 ] ) ;
if ( V_2 -> V_55 . V_158 )
F_87 ( & V_159 ) ;
if ( V_2 -> V_55 . V_160 ) {
for ( V_53 = 0 ; V_53 < F_86 ( V_161 ) ; V_53 ++ )
F_87 ( & V_161 [ V_53 ] ) ;
}
}
static int F_88 ( struct V_1 * V_2 )
{
int V_115 , V_53 , V_162 ;
for ( V_53 = 0 ; V_53 < F_86 ( V_157 ) ; V_53 ++ ) {
V_115 = F_89 ( & V_157 [ V_53 ] ) ;
if ( V_115 )
goto V_163;
}
if ( V_2 -> V_55 . V_158 ) {
V_115 = F_89 ( & V_159 ) ;
if ( V_115 )
goto V_164;
}
if ( V_2 -> V_55 . V_160 ) {
for ( V_53 = 0 ; V_53 < F_86 ( V_161 ) ; V_53 ++ ) {
V_115 = F_89 ( & V_161 [ V_53 ] ) ;
if ( V_115 )
goto V_165;
}
}
return 0 ;
V_165:
for ( V_162 = 0 ; V_162 < V_53 ; V_162 ++ )
F_87 ( & V_161 [ V_162 ] ) ;
F_87 ( & V_159 ) ;
V_164:
V_53 = F_86 ( V_157 ) ;
V_163:
for ( V_162 = 0 ; V_162 < V_53 ; V_162 ++ )
F_87 ( & V_157 [ V_162 ] ) ;
return V_115 ;
}
static bool F_90 ( struct V_166 * V_104 , void * V_167 )
{
struct V_168 * V_169 = V_167 ;
if ( V_169 && V_169 -> V_170 == V_104 -> V_171 -> V_33 ) {
V_104 -> V_172 = V_169 ;
return true ;
} else {
return false ;
}
}
static int F_91 ( struct V_1 * V_2 ,
struct V_173 * V_174 )
{
int V_115 = - V_175 ;
T_7 V_176 ;
F_92 ( V_176 ) ;
F_93 ( V_177 , V_176 ) ;
V_2 -> V_100 . V_104 = F_94 ( V_176 ,
F_90 , & V_174 -> V_178 -> V_179 , V_2 -> V_33 , L_17 ) ;
if ( ! V_2 -> V_100 . V_104 ) {
F_84 ( V_2 -> V_33 , L_18 ) ;
return V_115 ;
}
V_2 -> V_100 . V_101 . V_180 = V_105 ;
V_2 -> V_100 . V_101 . V_181 = V_2 -> V_182 +
F_23 ( 0 ) ;
V_2 -> V_100 . V_101 . V_102 = 1 ;
V_2 -> V_100 . V_101 . V_183 =
V_184 ;
V_2 -> V_100 . V_101 . V_103 = 1 ;
V_2 -> V_100 . V_101 . V_185 =
V_184 ;
V_2 -> V_100 . V_101 . V_186 = false ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_96 ( V_2 -> V_100 . V_104 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
V_2 -> V_55 . V_56 = 0 ;
V_2 -> V_55 . V_60 = 0 ;
V_2 -> V_55 . V_158 = 0 ;
V_2 -> V_55 . V_160 = 0 ;
V_2 -> V_55 . V_71 = 0 ;
switch ( V_2 -> V_129 & 0xff0 ) {
case 0x510 :
V_2 -> V_55 . V_56 = 1 ;
V_2 -> V_55 . V_60 = 1 ;
V_2 -> V_55 . V_158 = 1 ;
V_2 -> V_55 . V_160 = 1 ;
V_2 -> V_55 . V_71 = 1 ;
break;
case 0x420 :
V_2 -> V_55 . V_56 = 1 ;
V_2 -> V_55 . V_60 = 1 ;
V_2 -> V_55 . V_158 = 1 ;
V_2 -> V_55 . V_160 = 1 ;
V_2 -> V_55 . V_71 = 1 ;
break;
case 0x410 :
V_2 -> V_55 . V_56 = 1 ;
V_2 -> V_55 . V_60 = 1 ;
V_2 -> V_55 . V_158 = 1 ;
V_2 -> V_55 . V_160 = 1 ;
break;
case 0x400 :
V_2 -> V_55 . V_56 = 1 ;
V_2 -> V_55 . V_60 = 1 ;
V_2 -> V_55 . V_158 = 1 ;
break;
case 0x320 :
break;
default:
F_84 ( V_2 -> V_33 ,
L_19 ) ;
break;
}
}
static struct V_173 * F_98 ( struct V_187 * V_188 )
{
struct V_189 * V_190 = V_188 -> V_33 . V_191 ;
struct V_173 * V_174 ;
if ( ! V_190 ) {
F_41 ( & V_188 -> V_33 , L_20 ) ;
return F_99 ( - V_48 ) ;
}
V_174 = F_100 ( & V_188 -> V_33 , sizeof( * V_174 ) , V_192 ) ;
if ( ! V_174 ) {
F_41 ( & V_188 -> V_33 , L_21 ) ;
return F_99 ( - V_175 ) ;
}
V_174 -> V_178 = F_100 ( & V_188 -> V_33 ,
sizeof( * ( V_174 -> V_178 ) ) ,
V_192 ) ;
if ( ! V_174 -> V_178 ) {
F_41 ( & V_188 -> V_33 , L_22 ) ;
return F_99 ( - V_175 ) ;
}
return V_174 ;
}
static inline struct V_173 * F_98 ( struct V_187 * V_33 )
{
return F_99 ( - V_48 ) ;
}
static int F_101 ( struct V_187 * V_188 )
{
struct V_1 * V_149 ;
struct V_173 * V_174 ;
struct V_171 * V_33 = & V_188 -> V_33 ;
struct V_193 * V_194 ;
int V_115 ;
V_149 = F_100 ( & V_188 -> V_33 , sizeof( * V_149 ) , V_192 ) ;
if ( V_149 == NULL ) {
F_41 ( V_33 , L_23 ) ;
V_115 = - V_175 ;
goto V_195;
}
V_149 -> V_33 = V_33 ;
F_102 ( V_188 , V_149 ) ;
F_103 ( & V_149 -> V_196 ) ;
F_104 ( & V_149 -> V_32 ) ;
F_105 ( & V_149 -> V_154 , F_82 ,
( unsigned long ) V_149 ) ;
F_105 ( & V_149 -> V_125 , F_81 ,
( unsigned long ) V_149 ) ;
F_106 ( & V_149 -> V_134 , V_197 ) ;
V_149 -> V_147 = - 1 ;
V_194 = F_107 ( V_188 , V_198 , 0 ) ;
if ( ! V_194 ) {
F_41 ( V_33 , L_24 ) ;
V_115 = - V_199 ;
goto V_200;
}
V_149 -> V_182 = V_194 -> V_201 ;
V_149 -> V_147 = F_108 ( V_188 , 0 ) ;
if ( V_149 -> V_147 < 0 ) {
F_41 ( V_33 , L_25 ) ;
V_115 = V_149 -> V_147 ;
goto V_200;
}
V_115 = F_109 ( & V_188 -> V_33 , V_149 -> V_147 , F_83 ,
V_202 , L_26 , V_149 ) ;
if ( V_115 ) {
F_41 ( V_33 , L_27 ) ;
goto V_200;
}
V_149 -> V_122 = F_110 ( & V_188 -> V_33 , L_28 ) ;
if ( F_111 ( V_149 -> V_122 ) ) {
F_41 ( V_33 , L_29 ) ;
V_115 = F_112 ( V_149 -> V_122 ) ;
goto V_200;
}
V_149 -> V_4 = F_113 ( & V_188 -> V_33 , V_194 ) ;
if ( F_111 ( V_149 -> V_4 ) ) {
F_41 ( V_33 , L_30 ) ;
V_115 = F_112 ( V_149 -> V_4 ) ;
goto V_200;
}
V_115 = F_114 ( V_149 -> V_122 ) ;
if ( V_115 )
goto V_200;
F_61 ( V_149 ) ;
F_97 ( V_149 ) ;
if ( V_149 -> V_55 . V_56 ) {
V_174 = V_188 -> V_33 . V_203 ;
if ( ! V_174 ) {
V_174 = F_98 ( V_188 ) ;
if ( F_111 ( V_174 ) ) {
F_41 ( & V_188 -> V_33 , L_31 ) ;
V_115 = F_112 ( V_174 ) ;
goto V_204;
}
}
if ( ! V_174 -> V_178 ) {
V_115 = - V_205 ;
goto V_204;
}
V_115 = F_91 ( V_149 , V_174 ) ;
if ( V_115 )
goto V_206;
F_62 ( V_33 , L_32 ,
F_115 ( V_149 -> V_100 . V_104 ) ) ;
}
F_116 ( & V_31 . V_32 ) ;
F_117 ( & V_149 -> V_196 , & V_31 . V_207 ) ;
F_118 ( & V_31 . V_32 ) ;
V_115 = F_88 ( V_149 ) ;
if ( V_115 )
goto V_208;
F_62 ( V_33 , L_33 ,
V_149 -> V_55 . V_158 ? L_34 : L_35 ,
V_149 -> V_55 . V_160 ? L_36 : L_35 ) ;
return 0 ;
V_208:
F_116 ( & V_31 . V_32 ) ;
F_119 ( & V_149 -> V_196 ) ;
F_118 ( & V_31 . V_32 ) ;
if ( V_149 -> V_55 . V_56 )
F_95 ( V_149 ) ;
V_206:
V_204:
F_120 ( V_149 -> V_122 ) ;
V_200:
F_121 ( & V_149 -> V_125 ) ;
F_121 ( & V_149 -> V_154 ) ;
V_195:
F_41 ( V_33 , L_37 ) ;
return V_115 ;
}
static int F_122 ( struct V_187 * V_188 )
{
static struct V_1 * V_149 ;
V_149 = F_123 ( V_188 ) ;
if ( ! V_149 )
return - V_199 ;
F_116 ( & V_31 . V_32 ) ;
F_119 ( & V_149 -> V_196 ) ;
F_118 ( & V_31 . V_32 ) ;
F_85 ( V_149 ) ;
F_121 ( & V_149 -> V_125 ) ;
F_121 ( & V_149 -> V_154 ) ;
if ( V_149 -> V_55 . V_56 )
F_95 ( V_149 ) ;
F_120 ( V_149 -> V_122 ) ;
return 0 ;
}
