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
if ( V_8 <= 0 )
break;
F_7 ( V_7 -> V_14 + V_7 -> V_9 , V_7 -> V_12 ,
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
static void F_9 ( struct V_6 * V_7 , int V_13 )
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
V_17 [ 1 ] = F_10 ( V_18 [ 0 ] << 3 ) ;
V_17 [ 0 ] = F_10 ( V_18 [ 1 ] << 3 | V_18 [ 0 ] >> 61 ) ;
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
static int F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_28 * V_29 = F_13 ( V_27 ) ;
struct V_6 * V_7 = F_14 ( V_25 ) ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_30 ;
F_15 ( & V_31 . V_32 ) ;
if ( ! V_29 -> V_2 ) {
F_16 (tmp, &atmel_sha.dev_list, list) {
V_2 = V_30 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_17 ( & V_31 . V_32 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_20 = 0 ;
F_18 ( V_2 -> V_33 , L_1 ,
F_19 ( V_27 ) ) ;
switch ( F_19 ( V_27 ) ) {
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
static void F_20 ( struct V_1 * V_2 , int V_50 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
T_1 V_51 = 0 , V_52 = V_53 ;
if ( F_21 ( V_50 ) ) {
if ( ! V_2 -> V_54 . V_55 )
F_3 ( V_2 , V_56 , V_57 ) ;
V_52 = V_58 ;
if ( V_2 -> V_54 . V_59 )
V_52 |= V_60 ;
} else {
F_3 ( V_2 , V_56 , V_61 ) ;
}
if ( V_7 -> V_20 & V_35 )
V_52 |= V_62 ;
else if ( V_7 -> V_20 & V_39 )
V_52 |= V_63 ;
else if ( V_7 -> V_20 & V_42 )
V_52 |= V_64 ;
else if ( V_7 -> V_20 & V_21 )
V_52 |= V_65 ;
else if ( V_7 -> V_20 & V_22 )
V_52 |= V_66 ;
if ( ! ( V_7 -> V_19 [ 0 ] || V_7 -> V_19 [ 1 ] ) )
V_51 = V_67 ;
F_3 ( V_2 , V_68 , V_51 ) ;
F_3 ( V_2 , V_69 , V_52 ) ;
}
static int F_22 ( struct V_1 * V_2 , const T_4 * V_70 ,
T_2 V_13 , int V_71 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
int V_8 , V_72 ;
const T_1 * V_14 = ( const T_1 * ) V_70 ;
F_18 ( V_2 -> V_33 , L_2 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_13 , V_71 ) ;
F_20 ( V_2 , 0 ) ;
V_7 -> V_19 [ 0 ] += V_13 ;
if ( V_7 -> V_19 [ 0 ] < V_13 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_71 )
V_2 -> V_20 |= V_73 ;
V_72 = F_23 ( V_13 , sizeof( T_1 ) ) ;
V_2 -> V_20 |= V_74 ;
for ( V_8 = 0 ; V_8 < V_72 ; V_8 ++ )
F_3 ( V_2 , F_24 ( V_8 ) , V_14 [ V_8 ] ) ;
return - V_75 ;
}
static int F_25 ( struct V_1 * V_2 , T_5 V_76 ,
T_2 V_77 , T_5 V_78 , T_2 V_79 , int V_71 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
int V_72 ;
F_18 ( V_2 -> V_33 , L_3 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_77 , V_71 ) ;
V_72 = F_23 ( V_77 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_80 , V_81 ) ;
F_3 ( V_2 , V_82 , V_76 ) ;
F_3 ( V_2 , V_83 , V_72 ) ;
V_72 = F_23 ( V_79 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_84 , V_78 ) ;
F_3 ( V_2 , V_85 , V_72 ) ;
F_20 ( V_2 , 1 ) ;
V_7 -> V_19 [ 0 ] += V_77 ;
if ( V_7 -> V_19 [ 0 ] < V_77 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_71 )
V_2 -> V_20 |= V_73 ;
V_2 -> V_20 |= V_86 ;
F_3 ( V_2 , V_80 , V_87 ) ;
return - V_75 ;
}
static void F_26 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
F_3 ( V_2 , V_56 , V_61 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_5 V_76 ,
T_2 V_77 , T_5 V_78 , T_2 V_79 , int V_71 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
struct V_89 * V_90 ;
struct V_91 V_12 [ 2 ] ;
F_18 ( V_2 -> V_33 , L_4 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_77 , V_71 ) ;
if ( V_7 -> V_20 & ( V_35 | V_39 |
V_42 ) ) {
V_2 -> V_92 . V_93 . V_94 = 16 ;
V_2 -> V_92 . V_93 . V_95 = 16 ;
} else {
V_2 -> V_92 . V_93 . V_94 = 32 ;
V_2 -> V_92 . V_93 . V_95 = 32 ;
}
F_28 ( V_2 -> V_92 . V_96 , & V_2 -> V_92 . V_93 ) ;
if ( V_79 ) {
F_29 ( V_12 , 2 ) ;
F_30 ( & V_12 [ 0 ] ) = V_76 ;
F_31 ( & V_12 [ 0 ] ) = V_77 ;
F_30 ( & V_12 [ 1 ] ) = V_78 ;
F_31 ( & V_12 [ 1 ] ) = V_79 ;
V_90 = F_32 ( V_2 -> V_92 . V_96 , V_12 , 2 ,
V_97 , V_98 | V_99 ) ;
} else {
F_29 ( V_12 , 1 ) ;
F_30 ( & V_12 [ 0 ] ) = V_76 ;
F_31 ( & V_12 [ 0 ] ) = V_77 ;
V_90 = F_32 ( V_2 -> V_92 . V_96 , V_12 , 1 ,
V_97 , V_98 | V_99 ) ;
}
if ( ! V_90 )
return - V_48 ;
V_90 -> V_100 = F_26 ;
V_90 -> V_101 = V_2 ;
F_20 ( V_2 , 1 ) ;
V_7 -> V_19 [ 0 ] += V_77 ;
if ( V_7 -> V_19 [ 0 ] < V_77 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_71 )
V_2 -> V_20 |= V_73 ;
V_2 -> V_20 |= V_86 ;
F_33 ( V_90 ) ;
F_34 ( V_2 -> V_92 . V_96 ) ;
return - V_75 ;
}
static int F_35 ( struct V_1 * V_2 , T_5 V_76 ,
T_2 V_77 , T_5 V_78 , T_2 V_79 , int V_71 )
{
if ( V_2 -> V_54 . V_55 )
return F_27 ( V_2 , V_76 , V_77 ,
V_78 , V_79 , V_71 ) ;
else
return F_25 ( V_2 , V_76 , V_77 ,
V_78 , V_79 , V_71 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
int V_9 ;
F_5 ( V_7 ) ;
F_9 ( V_7 , 0 ) ;
V_9 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_22 ( V_2 , V_7 -> V_14 , V_9 , 1 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_2 V_13 , int V_71 )
{
V_7 -> V_102 = F_38 ( V_2 -> V_33 , V_7 -> V_14 ,
V_7 -> V_10 + V_7 -> V_36 , V_103 ) ;
if ( F_39 ( V_2 -> V_33 , V_7 -> V_102 ) ) {
F_40 ( V_2 -> V_33 , L_5 , V_7 -> V_10 +
V_7 -> V_36 ) ;
return - V_48 ;
}
V_7 -> V_20 &= ~ V_104 ;
return F_35 ( V_2 , V_7 -> V_102 , V_13 , 0 , 0 , V_71 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
unsigned int V_71 ;
T_2 V_8 ;
F_5 ( V_7 ) ;
V_71 = ( V_7 -> V_20 & V_105 ) && ! V_7 -> V_11 ;
F_18 ( V_2 -> V_33 , L_6 ,
V_7 -> V_9 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_71 ) ;
if ( V_71 )
F_9 ( V_7 , 0 ) ;
if ( V_71 || ( V_7 -> V_9 == V_7 -> V_10 && V_7 -> V_11 ) ) {
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_37 ( V_2 , V_7 , V_8 , V_71 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
unsigned int V_13 , V_71 , V_106 ;
struct V_91 * V_12 ;
unsigned int V_8 ;
if ( ! V_7 -> V_11 )
return 0 ;
if ( V_7 -> V_9 || V_7 -> V_3 )
return F_41 ( V_2 ) ;
F_18 ( V_2 -> V_33 , L_7 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_7 -> V_9 , V_7 -> V_11 ) ;
V_12 = V_7 -> V_12 ;
if ( ! F_43 ( V_12 -> V_3 , sizeof( T_1 ) ) )
return F_41 ( V_2 ) ;
if ( ! F_44 ( V_12 ) && ! F_43 ( V_12 -> V_13 , V_7 -> V_36 ) )
return F_41 ( V_2 ) ;
V_13 = F_6 ( V_7 -> V_11 , V_12 -> V_13 ) ;
if ( F_44 ( V_12 ) ) {
if ( ! ( V_7 -> V_20 & V_105 ) ) {
V_106 = V_13 & ( V_7 -> V_36 - 1 ) ;
V_13 -= V_106 ;
}
}
V_7 -> V_11 -= V_13 ;
V_7 -> V_3 = V_13 ;
V_71 = ( V_7 -> V_20 & V_105 ) && ! V_7 -> V_11 ;
if ( V_71 ) {
V_106 = V_13 & ( V_7 -> V_36 - 1 ) ;
V_13 -= V_106 ;
V_7 -> V_11 += V_106 ;
V_7 -> V_3 = V_13 ;
V_12 = V_7 -> V_12 ;
F_5 ( V_7 ) ;
F_9 ( V_7 , V_13 ) ;
V_7 -> V_102 = F_38 ( V_2 -> V_33 , V_7 -> V_14 ,
V_7 -> V_10 + V_7 -> V_36 , V_103 ) ;
if ( F_39 ( V_2 -> V_33 , V_7 -> V_102 ) ) {
F_40 ( V_2 -> V_33 , L_5 ,
V_7 -> V_10 + V_7 -> V_36 ) ;
return - V_48 ;
}
if ( V_13 == 0 ) {
V_7 -> V_20 &= ~ V_104 ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_35 ( V_2 , V_7 -> V_102 , V_8 , 0 ,
0 , V_71 ) ;
} else {
V_7 -> V_12 = V_12 ;
if ( ! F_45 ( V_2 -> V_33 , V_7 -> V_12 , 1 ,
V_103 ) ) {
F_40 ( V_2 -> V_33 , L_8 ) ;
return - V_48 ;
}
V_7 -> V_20 |= V_104 ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_35 ( V_2 , F_30 ( V_7 -> V_12 ) ,
V_13 , V_7 -> V_102 , V_8 , V_71 ) ;
}
}
if ( ! F_45 ( V_2 -> V_33 , V_7 -> V_12 , 1 , V_103 ) ) {
F_40 ( V_2 -> V_33 , L_8 ) ;
return - V_48 ;
}
V_7 -> V_20 |= V_104 ;
return F_35 ( V_2 , F_30 ( V_7 -> V_12 ) , V_13 , 0 ,
0 , V_71 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_14 ( V_2 -> V_25 ) ;
if ( V_7 -> V_20 & V_104 ) {
F_47 ( V_2 -> V_33 , V_7 -> V_12 , 1 , V_103 ) ;
if ( V_7 -> V_12 -> V_13 == V_7 -> V_3 ) {
V_7 -> V_12 = F_8 ( V_7 -> V_12 ) ;
if ( V_7 -> V_12 )
V_7 -> V_3 = 0 ;
}
if ( V_7 -> V_20 & V_23 ) {
F_48 ( V_2 -> V_33 , V_7 -> V_102 ,
V_7 -> V_10 + V_7 -> V_36 , V_103 ) ;
}
} else {
F_48 ( V_2 -> V_33 , V_7 -> V_102 , V_7 -> V_10 +
V_7 -> V_36 , V_103 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_6 * V_7 = F_14 ( V_25 ) ;
int V_107 ;
F_18 ( V_2 -> V_33 , L_9 ,
V_7 -> V_11 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] ) ;
if ( V_7 -> V_20 & V_74 )
V_107 = F_36 ( V_2 ) ;
else
V_107 = F_42 ( V_2 ) ;
F_18 ( V_2 -> V_33 , L_10 ,
V_107 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] ) ;
return V_107 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_6 * V_7 = F_14 ( V_25 ) ;
int V_107 = 0 ;
int V_8 ;
if ( V_7 -> V_9 >= V_108 ) {
F_9 ( V_7 , 0 ) ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
V_107 = F_37 ( V_2 , V_7 , V_8 , 1 ) ;
}
else {
F_9 ( V_7 , 0 ) ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
V_107 = F_22 ( V_2 , V_7 -> V_14 , V_8 , 1 ) ;
}
F_18 ( V_2 -> V_33 , L_11 , V_107 ) ;
return V_107 ;
}
static void F_51 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
T_1 * V_109 = ( T_1 * ) V_7 -> V_110 ;
int V_111 ;
if ( V_7 -> V_20 & V_35 )
for ( V_111 = 0 ; V_111 < V_34 / sizeof( T_1 ) ; V_111 ++ )
V_109 [ V_111 ] = F_1 ( V_7 -> V_2 , F_52 ( V_111 ) ) ;
else if ( V_7 -> V_20 & V_39 )
for ( V_111 = 0 ; V_111 < V_38 / sizeof( T_1 ) ; V_111 ++ )
V_109 [ V_111 ] = F_1 ( V_7 -> V_2 , F_52 ( V_111 ) ) ;
else if ( V_7 -> V_20 & V_42 )
for ( V_111 = 0 ; V_111 < V_41 / sizeof( T_1 ) ; V_111 ++ )
V_109 [ V_111 ] = F_1 ( V_7 -> V_2 , F_52 ( V_111 ) ) ;
else if ( V_7 -> V_20 & V_21 )
for ( V_111 = 0 ; V_111 < V_44 / sizeof( T_1 ) ; V_111 ++ )
V_109 [ V_111 ] = F_1 ( V_7 -> V_2 , F_52 ( V_111 ) ) ;
else
for ( V_111 = 0 ; V_111 < V_46 / sizeof( T_1 ) ; V_111 ++ )
V_109 [ V_111 ] = F_1 ( V_7 -> V_2 , F_52 ( V_111 ) ) ;
}
static void F_53 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
if ( ! V_25 -> V_112 )
return;
if ( V_7 -> V_20 & V_35 )
memcpy ( V_25 -> V_112 , V_7 -> V_110 , V_34 ) ;
else if ( V_7 -> V_20 & V_39 )
memcpy ( V_25 -> V_112 , V_7 -> V_110 , V_38 ) ;
else if ( V_7 -> V_20 & V_42 )
memcpy ( V_25 -> V_112 , V_7 -> V_110 , V_41 ) ;
else if ( V_7 -> V_20 & V_21 )
memcpy ( V_25 -> V_112 , V_7 -> V_110 , V_44 ) ;
else
memcpy ( V_25 -> V_112 , V_7 -> V_110 , V_46 ) ;
}
static int F_54 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_107 = 0 ;
if ( V_7 -> V_19 [ 0 ] || V_7 -> V_19 [ 1 ] )
F_53 ( V_25 ) ;
F_18 ( V_2 -> V_33 , L_12 , V_7 -> V_19 [ 1 ] ,
V_7 -> V_19 [ 0 ] , V_7 -> V_9 ) ;
return V_107 ;
}
static void F_55 ( struct V_24 * V_25 , int V_107 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( ! V_107 ) {
F_51 ( V_25 ) ;
if ( V_73 & V_2 -> V_20 )
V_107 = F_54 ( V_25 ) ;
} else {
V_7 -> V_20 |= V_113 ;
}
V_2 -> V_20 &= ~ ( V_114 | V_73 | V_74 |
V_115 | V_116 ) ;
F_56 ( V_2 -> V_117 ) ;
if ( V_25 -> V_118 . V_119 )
V_25 -> V_118 . V_119 ( & V_25 -> V_118 , V_107 ) ;
F_57 ( & V_2 -> V_120 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 -> V_117 ) ;
if ( ! ( V_121 & V_2 -> V_20 ) ) {
F_3 ( V_2 , V_68 , V_122 ) ;
V_2 -> V_20 |= V_121 ;
V_2 -> V_107 = 0 ;
}
return 0 ;
}
static inline unsigned int F_60 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_123 ) & 0x00000fff ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
V_2 -> V_124 = F_60 ( V_2 ) ;
F_62 ( V_2 -> V_33 ,
L_13 , V_2 -> V_124 ) ;
F_56 ( V_2 -> V_117 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_125 * V_126 , * V_127 ;
struct V_6 * V_7 ;
unsigned long V_20 ;
int V_107 = 0 , V_128 = 0 ;
F_64 ( & V_2 -> V_32 , V_20 ) ;
if ( V_25 )
V_128 = F_65 ( & V_2 -> V_129 , V_25 ) ;
if ( V_114 & V_2 -> V_20 ) {
F_66 ( & V_2 -> V_32 , V_20 ) ;
return V_128 ;
}
V_127 = F_67 ( & V_2 -> V_129 ) ;
V_126 = F_68 ( & V_2 -> V_129 ) ;
if ( V_126 )
V_2 -> V_20 |= V_114 ;
F_66 ( & V_2 -> V_32 , V_20 ) ;
if ( ! V_126 )
return V_128 ;
if ( V_127 )
V_127 -> V_119 ( V_127 , - V_75 ) ;
V_25 = F_69 ( V_126 ) ;
V_2 -> V_25 = V_25 ;
V_7 = F_14 ( V_25 ) ;
F_18 ( V_2 -> V_33 , L_14 ,
V_7 -> V_130 , V_25 -> V_131 ) ;
V_107 = F_58 ( V_2 ) ;
if ( V_107 )
goto V_132;
if ( V_7 -> V_130 == V_133 ) {
V_107 = F_49 ( V_2 ) ;
if ( V_107 != - V_75 && ( V_7 -> V_20 & V_105 ) )
V_107 = F_50 ( V_2 ) ;
} else if ( V_7 -> V_130 == V_134 ) {
V_107 = F_50 ( V_2 ) ;
}
V_132:
if ( V_107 != - V_75 )
F_55 ( V_25 , V_107 ) ;
F_18 ( V_2 -> V_33 , L_15 , V_107 ) ;
return V_128 ;
}
static int F_70 ( struct V_24 * V_25 , unsigned int V_130 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
struct V_28 * V_29 = F_71 ( V_25 -> V_118 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
V_7 -> V_130 = V_130 ;
return F_63 ( V_2 , V_25 ) ;
}
static int F_72 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
if ( ! V_25 -> V_131 )
return 0 ;
V_7 -> V_11 = V_25 -> V_131 ;
V_7 -> V_12 = V_25 -> V_135 ;
V_7 -> V_3 = 0 ;
if ( V_7 -> V_20 & V_105 ) {
if ( V_7 -> V_9 + V_7 -> V_11 < V_108 )
V_7 -> V_20 |= V_74 ;
} else if ( V_7 -> V_9 + V_7 -> V_11 < V_7 -> V_10 ) {
F_5 ( V_7 ) ;
return 0 ;
}
return F_70 ( V_25 , V_133 ) ;
}
static int F_73 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
struct V_28 * V_29 = F_71 ( V_25 -> V_118 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
int V_107 = 0 ;
V_7 -> V_20 |= V_105 ;
if ( V_7 -> V_20 & V_113 )
return 0 ;
if ( V_7 -> V_9 ) {
return F_70 ( V_25 , V_134 ) ;
} else if ( ! ( V_7 -> V_20 & V_23 ) ) {
V_107 = F_58 ( V_2 ) ;
if ( V_107 )
goto V_132;
V_2 -> V_20 |= V_114 ;
V_107 = F_50 ( V_2 ) ;
} else {
return F_54 ( V_25 ) ;
}
V_132:
if ( V_107 != - V_75 )
F_55 ( V_25 , V_107 ) ;
return V_107 ;
}
static int F_74 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_14 ( V_25 ) ;
int V_132 , V_136 ;
V_7 -> V_20 |= V_105 ;
V_132 = F_72 ( V_25 ) ;
if ( V_132 == - V_75 || V_132 == - V_137 )
return V_132 ;
V_136 = F_73 ( V_25 ) ;
return V_132 ? : V_136 ;
}
static int F_75 ( struct V_24 * V_25 )
{
return F_11 ( V_25 ) ? : F_74 ( V_25 ) ;
}
static int F_76 ( struct V_138 * V_27 , const char * V_139 )
{
struct V_28 * V_29 = F_71 ( V_27 ) ;
const char * V_140 = F_77 ( V_27 ) ;
V_29 -> V_141 = F_78 ( V_140 , 0 ,
V_142 ) ;
if ( F_79 ( V_29 -> V_141 ) ) {
F_80 ( L_16 ,
V_140 ) ;
return F_81 ( V_29 -> V_141 ) ;
}
F_82 ( F_83 ( V_27 ) ,
sizeof( struct V_6 ) +
V_49 + V_47 ) ;
return 0 ;
}
static int F_84 ( struct V_138 * V_27 )
{
return F_76 ( V_27 , NULL ) ;
}
static void F_85 ( struct V_138 * V_27 )
{
struct V_28 * V_29 = F_71 ( V_27 ) ;
F_86 ( V_29 -> V_141 ) ;
V_29 -> V_141 = NULL ;
}
static void F_87 ( unsigned long V_88 )
{
struct V_1 * V_2 = (struct V_1 * ) V_88 ;
int V_107 = 0 ;
if ( ! ( V_114 & V_2 -> V_20 ) ) {
F_63 ( V_2 , NULL ) ;
return;
}
if ( V_74 & V_2 -> V_20 ) {
if ( V_116 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ V_116 ;
goto V_143;
}
} else if ( V_115 & V_2 -> V_20 ) {
if ( V_86 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ V_86 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_107 ) {
V_107 = V_2 -> V_107 ;
goto V_143;
}
}
if ( V_116 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ ( V_115 |
V_116 ) ;
V_107 = F_42 ( V_2 ) ;
if ( V_107 != - V_75 )
goto V_143;
}
}
return;
V_143:
F_55 ( V_2 -> V_25 , V_107 ) ;
}
static T_6 F_88 ( int V_144 , void * V_145 )
{
struct V_1 * V_146 = V_145 ;
T_1 V_147 ;
V_147 = F_1 ( V_146 , V_148 ) ;
if ( V_147 & F_1 ( V_146 , V_149 ) ) {
F_3 ( V_146 , V_150 , V_147 ) ;
if ( V_114 & V_146 -> V_20 ) {
V_146 -> V_20 |= V_116 ;
if ( ! ( V_74 & V_146 -> V_20 ) )
V_146 -> V_20 |= V_115 ;
F_57 ( & V_146 -> V_120 ) ;
} else {
F_89 ( V_146 -> V_33 , L_17 ) ;
}
return V_151 ;
}
return V_152 ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < F_91 ( V_153 ) ; V_111 ++ )
F_92 ( & V_153 [ V_111 ] ) ;
if ( V_2 -> V_54 . V_154 )
F_92 ( & V_155 ) ;
if ( V_2 -> V_54 . V_156 ) {
for ( V_111 = 0 ; V_111 < F_91 ( V_157 ) ; V_111 ++ )
F_92 ( & V_157 [ V_111 ] ) ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
int V_107 , V_111 , V_158 ;
for ( V_111 = 0 ; V_111 < F_91 ( V_153 ) ; V_111 ++ ) {
V_107 = F_94 ( & V_153 [ V_111 ] ) ;
if ( V_107 )
goto V_159;
}
if ( V_2 -> V_54 . V_154 ) {
V_107 = F_94 ( & V_155 ) ;
if ( V_107 )
goto V_160;
}
if ( V_2 -> V_54 . V_156 ) {
for ( V_111 = 0 ; V_111 < F_91 ( V_157 ) ; V_111 ++ ) {
V_107 = F_94 ( & V_157 [ V_111 ] ) ;
if ( V_107 )
goto V_161;
}
}
return 0 ;
V_161:
for ( V_158 = 0 ; V_158 < V_111 ; V_158 ++ )
F_92 ( & V_157 [ V_158 ] ) ;
F_92 ( & V_155 ) ;
V_160:
V_111 = F_91 ( V_153 ) ;
V_159:
for ( V_158 = 0 ; V_158 < V_111 ; V_158 ++ )
F_92 ( & V_153 [ V_158 ] ) ;
return V_107 ;
}
static bool F_95 ( struct V_162 * V_96 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
if ( V_165 && V_165 -> V_166 == V_96 -> V_167 -> V_33 ) {
V_96 -> V_168 = V_165 ;
return true ;
} else {
return false ;
}
}
static int F_96 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
int V_107 = - V_171 ;
T_7 V_172 ;
F_97 ( V_172 ) ;
F_98 ( V_173 , V_172 ) ;
V_2 -> V_92 . V_96 = F_99 ( V_172 ,
F_95 , & V_170 -> V_174 -> V_175 , V_2 -> V_33 , L_18 ) ;
if ( ! V_2 -> V_92 . V_96 ) {
F_89 ( V_2 -> V_33 , L_19 ) ;
return V_107 ;
}
V_2 -> V_92 . V_93 . V_176 = V_97 ;
V_2 -> V_92 . V_93 . V_177 = V_2 -> V_178 +
F_24 ( 0 ) ;
V_2 -> V_92 . V_93 . V_94 = 1 ;
V_2 -> V_92 . V_93 . V_179 =
V_180 ;
V_2 -> V_92 . V_93 . V_95 = 1 ;
V_2 -> V_92 . V_93 . V_181 =
V_180 ;
V_2 -> V_92 . V_93 . V_182 = false ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_101 ( V_2 -> V_92 . V_96 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_55 = 0 ;
V_2 -> V_54 . V_59 = 0 ;
V_2 -> V_54 . V_154 = 0 ;
V_2 -> V_54 . V_156 = 0 ;
switch ( V_2 -> V_124 & 0xff0 ) {
case 0x410 :
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_59 = 1 ;
V_2 -> V_54 . V_154 = 1 ;
V_2 -> V_54 . V_156 = 1 ;
break;
case 0x400 :
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_59 = 1 ;
V_2 -> V_54 . V_154 = 1 ;
break;
case 0x320 :
break;
default:
F_89 ( V_2 -> V_33 ,
L_20 ) ;
break;
}
}
static struct V_169 * F_103 ( struct V_183 * V_184 )
{
struct V_185 * V_186 = V_184 -> V_33 . V_187 ;
struct V_169 * V_170 ;
if ( ! V_186 ) {
F_40 ( & V_184 -> V_33 , L_21 ) ;
return F_104 ( - V_48 ) ;
}
V_170 = F_105 ( & V_184 -> V_33 , sizeof( * V_170 ) , V_188 ) ;
if ( ! V_170 ) {
F_40 ( & V_184 -> V_33 , L_22 ) ;
return F_104 ( - V_171 ) ;
}
V_170 -> V_174 = F_105 ( & V_184 -> V_33 ,
sizeof( * ( V_170 -> V_174 ) ) ,
V_188 ) ;
if ( ! V_170 -> V_174 ) {
F_40 ( & V_184 -> V_33 , L_23 ) ;
return F_104 ( - V_171 ) ;
}
return V_170 ;
}
static inline struct V_169 * F_103 ( struct V_183 * V_33 )
{
return F_104 ( - V_48 ) ;
}
static int F_106 ( struct V_183 * V_184 )
{
struct V_1 * V_146 ;
struct V_169 * V_170 ;
struct V_167 * V_33 = & V_184 -> V_33 ;
struct V_189 * V_190 ;
unsigned long V_191 ;
int V_107 ;
V_146 = F_105 ( & V_184 -> V_33 , sizeof( struct V_1 ) ,
V_188 ) ;
if ( V_146 == NULL ) {
F_40 ( V_33 , L_24 ) ;
V_107 = - V_171 ;
goto V_192;
}
V_146 -> V_33 = V_33 ;
F_107 ( V_184 , V_146 ) ;
F_108 ( & V_146 -> V_193 ) ;
F_109 ( & V_146 -> V_120 , F_87 ,
( unsigned long ) V_146 ) ;
F_110 ( & V_146 -> V_129 , V_194 ) ;
V_146 -> V_144 = - 1 ;
V_190 = F_111 ( V_184 , V_195 , 0 ) ;
if ( ! V_190 ) {
F_40 ( V_33 , L_25 ) ;
V_107 = - V_196 ;
goto V_197;
}
V_146 -> V_178 = V_190 -> V_198 ;
V_191 = F_112 ( V_190 ) ;
V_146 -> V_144 = F_113 ( V_184 , 0 ) ;
if ( V_146 -> V_144 < 0 ) {
F_40 ( V_33 , L_26 ) ;
V_107 = V_146 -> V_144 ;
goto V_197;
}
V_107 = F_114 ( V_146 -> V_144 , F_88 , V_199 , L_27 ,
V_146 ) ;
if ( V_107 ) {
F_40 ( V_33 , L_28 ) ;
goto V_197;
}
V_146 -> V_117 = F_115 ( & V_184 -> V_33 , L_29 ) ;
if ( F_79 ( V_146 -> V_117 ) ) {
F_40 ( V_33 , L_30 ) ;
V_107 = F_81 ( V_146 -> V_117 ) ;
goto V_200;
}
V_146 -> V_4 = F_116 ( V_146 -> V_178 , V_191 ) ;
if ( ! V_146 -> V_4 ) {
F_40 ( V_33 , L_31 ) ;
V_107 = - V_171 ;
goto V_201;
}
F_61 ( V_146 ) ;
F_102 ( V_146 ) ;
if ( V_146 -> V_54 . V_55 ) {
V_170 = V_184 -> V_33 . V_202 ;
if ( ! V_170 ) {
V_170 = F_103 ( V_184 ) ;
if ( F_79 ( V_170 ) ) {
F_40 ( & V_184 -> V_33 , L_32 ) ;
V_107 = F_81 ( V_170 ) ;
goto V_203;
}
}
if ( ! V_170 -> V_174 ) {
V_107 = - V_204 ;
goto V_203;
}
V_107 = F_96 ( V_146 , V_170 ) ;
if ( V_107 )
goto V_205;
F_62 ( V_33 , L_33 ,
F_117 ( V_146 -> V_92 . V_96 ) ) ;
}
F_118 ( & V_31 . V_32 ) ;
F_119 ( & V_146 -> V_193 , & V_31 . V_206 ) ;
F_120 ( & V_31 . V_32 ) ;
V_107 = F_93 ( V_146 ) ;
if ( V_107 )
goto V_207;
F_62 ( V_33 , L_34 ,
V_146 -> V_54 . V_154 ? L_35 : L_36 ,
V_146 -> V_54 . V_156 ? L_37 : L_36 ) ;
return 0 ;
V_207:
F_118 ( & V_31 . V_32 ) ;
F_121 ( & V_146 -> V_193 ) ;
F_120 ( & V_31 . V_32 ) ;
if ( V_146 -> V_54 . V_55 )
F_100 ( V_146 ) ;
V_205:
V_203:
F_122 ( V_146 -> V_4 ) ;
V_201:
F_123 ( V_146 -> V_117 ) ;
V_200:
F_124 ( V_146 -> V_144 , V_146 ) ;
V_197:
F_125 ( & V_146 -> V_120 ) ;
V_192:
F_40 ( V_33 , L_38 ) ;
return V_107 ;
}
static int F_126 ( struct V_183 * V_184 )
{
static struct V_1 * V_146 ;
V_146 = F_127 ( V_184 ) ;
if ( ! V_146 )
return - V_196 ;
F_118 ( & V_31 . V_32 ) ;
F_121 ( & V_146 -> V_193 ) ;
F_120 ( & V_31 . V_32 ) ;
F_90 ( V_146 ) ;
F_125 ( & V_146 -> V_120 ) ;
if ( V_146 -> V_54 . V_55 )
F_100 ( V_146 ) ;
F_122 ( V_146 -> V_4 ) ;
F_123 ( V_146 -> V_117 ) ;
if ( V_146 -> V_144 >= 0 )
F_124 ( V_146 -> V_144 , V_146 ) ;
return 0 ;
}
