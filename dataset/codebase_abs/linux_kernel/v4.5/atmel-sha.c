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
T_1 V_51 = 0 , V_52 = V_53 ;
if ( F_22 ( V_50 ) ) {
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
static int F_23 ( struct V_1 * V_2 , const T_4 * V_70 ,
T_2 V_13 , int V_71 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
int V_8 , V_72 ;
const T_1 * V_14 = ( const T_1 * ) V_70 ;
F_19 ( V_2 -> V_33 , L_2 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_13 , V_71 ) ;
F_21 ( V_2 , 0 ) ;
V_7 -> V_19 [ 0 ] += V_13 ;
if ( V_7 -> V_19 [ 0 ] < V_13 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_71 )
V_2 -> V_20 |= V_73 ;
V_72 = F_24 ( V_13 , sizeof( T_1 ) ) ;
V_2 -> V_20 |= V_74 ;
for ( V_8 = 0 ; V_8 < V_72 ; V_8 ++ )
F_3 ( V_2 , F_25 ( V_8 ) , V_14 [ V_8 ] ) ;
return - V_75 ;
}
static int F_26 ( struct V_1 * V_2 , T_5 V_76 ,
T_2 V_77 , T_5 V_78 , T_2 V_79 , int V_71 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
int V_72 ;
F_19 ( V_2 -> V_33 , L_3 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_77 , V_71 ) ;
V_72 = F_24 ( V_77 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_80 , V_81 ) ;
F_3 ( V_2 , V_82 , V_76 ) ;
F_3 ( V_2 , V_83 , V_72 ) ;
V_72 = F_24 ( V_79 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_84 , V_78 ) ;
F_3 ( V_2 , V_85 , V_72 ) ;
F_21 ( V_2 , 1 ) ;
V_7 -> V_19 [ 0 ] += V_77 ;
if ( V_7 -> V_19 [ 0 ] < V_77 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_71 )
V_2 -> V_20 |= V_73 ;
V_2 -> V_20 |= V_86 ;
F_3 ( V_2 , V_80 , V_87 ) ;
return - V_75 ;
}
static void F_27 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
F_3 ( V_2 , V_56 , V_61 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_5 V_76 ,
T_2 V_77 , T_5 V_78 , T_2 V_79 , int V_71 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
struct V_89 * V_90 ;
struct V_91 V_12 [ 2 ] ;
F_19 ( V_2 -> V_33 , L_4 ,
V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_77 , V_71 ) ;
V_2 -> V_92 . V_93 . V_94 = 16 ;
V_2 -> V_92 . V_93 . V_95 = 16 ;
F_29 ( V_2 -> V_92 . V_96 , & V_2 -> V_92 . V_93 ) ;
if ( V_79 ) {
F_30 ( V_12 , 2 ) ;
F_31 ( & V_12 [ 0 ] ) = V_76 ;
F_32 ( & V_12 [ 0 ] ) = V_77 ;
F_31 ( & V_12 [ 1 ] ) = V_78 ;
F_32 ( & V_12 [ 1 ] ) = V_79 ;
V_90 = F_33 ( V_2 -> V_92 . V_96 , V_12 , 2 ,
V_97 , V_98 | V_99 ) ;
} else {
F_30 ( V_12 , 1 ) ;
F_31 ( & V_12 [ 0 ] ) = V_76 ;
F_32 ( & V_12 [ 0 ] ) = V_77 ;
V_90 = F_33 ( V_2 -> V_92 . V_96 , V_12 , 1 ,
V_97 , V_98 | V_99 ) ;
}
if ( ! V_90 )
return - V_48 ;
V_90 -> V_100 = F_27 ;
V_90 -> V_101 = V_2 ;
F_21 ( V_2 , 1 ) ;
V_7 -> V_19 [ 0 ] += V_77 ;
if ( V_7 -> V_19 [ 0 ] < V_77 )
V_7 -> V_19 [ 1 ] ++ ;
if ( V_71 )
V_2 -> V_20 |= V_73 ;
V_2 -> V_20 |= V_86 ;
F_34 ( V_90 ) ;
F_35 ( V_2 -> V_92 . V_96 ) ;
return - V_75 ;
}
static int F_36 ( struct V_1 * V_2 , T_5 V_76 ,
T_2 V_77 , T_5 V_78 , T_2 V_79 , int V_71 )
{
if ( V_2 -> V_54 . V_55 )
return F_28 ( V_2 , V_76 , V_77 ,
V_78 , V_79 , V_71 ) ;
else
return F_26 ( V_2 , V_76 , V_77 ,
V_78 , V_79 , V_71 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
int V_9 ;
F_5 ( V_7 ) ;
F_10 ( V_7 , 0 ) ;
V_9 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_23 ( V_2 , V_7 -> V_14 , V_9 , 1 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_2 V_13 , int V_71 )
{
V_7 -> V_102 = F_39 ( V_2 -> V_33 , V_7 -> V_14 ,
V_7 -> V_10 + V_7 -> V_36 , V_103 ) ;
if ( F_40 ( V_2 -> V_33 , V_7 -> V_102 ) ) {
F_41 ( V_2 -> V_33 , L_5 , V_7 -> V_10 +
V_7 -> V_36 ) ;
return - V_48 ;
}
V_7 -> V_20 &= ~ V_104 ;
return F_36 ( V_2 , V_7 -> V_102 , V_13 , 0 , 0 , V_71 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
unsigned int V_71 ;
T_2 V_8 ;
F_5 ( V_7 ) ;
V_71 = ( V_7 -> V_20 & V_105 ) && ! V_7 -> V_11 ;
F_19 ( V_2 -> V_33 , L_6 ,
V_7 -> V_9 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] , V_71 ) ;
if ( V_71 )
F_10 ( V_7 , 0 ) ;
if ( V_71 || ( V_7 -> V_9 == V_7 -> V_10 ) ) {
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_38 ( V_2 , V_7 , V_8 , V_71 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
unsigned int V_13 , V_71 , V_106 ;
struct V_91 * V_12 ;
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
F_10 ( V_7 , V_13 ) ;
V_7 -> V_102 = F_39 ( V_2 -> V_33 , V_7 -> V_14 ,
V_7 -> V_10 + V_7 -> V_36 , V_103 ) ;
if ( F_40 ( V_2 -> V_33 , V_7 -> V_102 ) ) {
F_41 ( V_2 -> V_33 , L_5 ,
V_7 -> V_10 + V_7 -> V_36 ) ;
return - V_48 ;
}
if ( V_13 == 0 ) {
V_7 -> V_20 &= ~ V_104 ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_36 ( V_2 , V_7 -> V_102 , V_8 , 0 ,
0 , V_71 ) ;
} else {
V_7 -> V_12 = V_12 ;
if ( ! F_45 ( V_2 -> V_33 , V_7 -> V_12 , 1 ,
V_103 ) ) {
F_41 ( V_2 -> V_33 , L_8 ) ;
return - V_48 ;
}
V_7 -> V_20 |= V_104 ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
return F_36 ( V_2 , F_31 ( V_7 -> V_12 ) ,
V_13 , V_7 -> V_102 , V_8 , V_71 ) ;
}
}
if ( ! F_45 ( V_2 -> V_33 , V_7 -> V_12 , 1 , V_103 ) ) {
F_41 ( V_2 -> V_33 , L_8 ) ;
return - V_48 ;
}
V_7 -> V_20 |= V_104 ;
return F_36 ( V_2 , F_31 ( V_7 -> V_12 ) , V_13 , 0 ,
0 , V_71 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_25 ) ;
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
struct V_6 * V_7 = F_15 ( V_25 ) ;
int V_107 ;
F_19 ( V_2 -> V_33 , L_9 ,
V_7 -> V_11 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] ) ;
if ( V_7 -> V_20 & V_74 )
V_107 = F_37 ( V_2 ) ;
else
V_107 = F_43 ( V_2 ) ;
F_19 ( V_2 -> V_33 , L_10 ,
V_107 , V_7 -> V_19 [ 1 ] , V_7 -> V_19 [ 0 ] ) ;
return V_107 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_6 * V_7 = F_15 ( V_25 ) ;
int V_107 = 0 ;
int V_8 ;
if ( V_7 -> V_9 >= V_108 ) {
F_10 ( V_7 , 0 ) ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
V_107 = F_38 ( V_2 , V_7 , V_8 , 1 ) ;
}
else {
F_10 ( V_7 , 0 ) ;
V_8 = V_7 -> V_9 ;
V_7 -> V_9 = 0 ;
V_107 = F_23 ( V_2 , V_7 -> V_14 , V_8 , 1 ) ;
}
F_19 ( V_2 -> V_33 , L_11 , V_107 ) ;
return V_107 ;
}
static void F_51 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
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
struct V_6 * V_7 = F_15 ( V_25 ) ;
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
struct V_6 * V_7 = F_15 ( V_25 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( V_7 -> V_19 [ 0 ] || V_7 -> V_19 [ 1 ] )
F_53 ( V_25 ) ;
F_19 ( V_2 -> V_33 , L_12 , V_7 -> V_19 [ 1 ] ,
V_7 -> V_19 [ 0 ] , V_7 -> V_9 ) ;
return 0 ;
}
static void F_55 ( struct V_24 * V_25 , int V_107 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
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
int V_107 ;
V_107 = F_59 ( V_2 -> V_117 ) ;
if ( V_107 )
return V_107 ;
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
V_7 = F_15 ( V_25 ) ;
F_19 ( V_2 -> V_33 , L_14 ,
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
F_19 ( V_2 -> V_33 , L_15 , V_107 ) ;
return V_128 ;
}
static int F_70 ( struct V_24 * V_25 , unsigned int V_130 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
struct V_28 * V_29 = F_71 ( V_25 -> V_118 . V_27 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
V_7 -> V_130 = V_130 ;
return F_63 ( V_2 , V_25 ) ;
}
static int F_72 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_15 ( V_25 ) ;
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
struct V_6 * V_7 = F_15 ( V_25 ) ;
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
struct V_6 * V_7 = F_15 ( V_25 ) ;
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
return F_12 ( V_25 ) ? : F_74 ( V_25 ) ;
}
static int F_76 ( struct V_138 * V_27 )
{
F_77 ( F_78 ( V_27 ) ,
sizeof( struct V_6 ) +
V_49 + V_47 ) ;
return 0 ;
}
static void F_79 ( unsigned long V_88 )
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
goto V_139;
}
} else if ( V_115 & V_2 -> V_20 ) {
if ( V_86 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ V_86 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_107 ) {
V_107 = V_2 -> V_107 ;
goto V_139;
}
}
if ( V_116 & V_2 -> V_20 ) {
V_2 -> V_20 &= ~ ( V_115 |
V_116 ) ;
V_107 = F_43 ( V_2 ) ;
if ( V_107 != - V_75 )
goto V_139;
}
}
return;
V_139:
F_55 ( V_2 -> V_25 , V_107 ) ;
}
static T_6 F_80 ( int V_140 , void * V_141 )
{
struct V_1 * V_142 = V_141 ;
T_1 V_143 ;
V_143 = F_1 ( V_142 , V_144 ) ;
if ( V_143 & F_1 ( V_142 , V_145 ) ) {
F_3 ( V_142 , V_146 , V_143 ) ;
if ( V_114 & V_142 -> V_20 ) {
V_142 -> V_20 |= V_116 ;
if ( ! ( V_74 & V_142 -> V_20 ) )
V_142 -> V_20 |= V_115 ;
F_57 ( & V_142 -> V_120 ) ;
} else {
F_81 ( V_142 -> V_33 , L_16 ) ;
}
return V_147 ;
}
return V_148 ;
}
static void F_82 ( struct V_1 * V_2 )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < F_83 ( V_149 ) ; V_111 ++ )
F_84 ( & V_149 [ V_111 ] ) ;
if ( V_2 -> V_54 . V_150 )
F_84 ( & V_151 ) ;
if ( V_2 -> V_54 . V_152 ) {
for ( V_111 = 0 ; V_111 < F_83 ( V_153 ) ; V_111 ++ )
F_84 ( & V_153 [ V_111 ] ) ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
int V_107 , V_111 , V_154 ;
for ( V_111 = 0 ; V_111 < F_83 ( V_149 ) ; V_111 ++ ) {
V_107 = F_86 ( & V_149 [ V_111 ] ) ;
if ( V_107 )
goto V_155;
}
if ( V_2 -> V_54 . V_150 ) {
V_107 = F_86 ( & V_151 ) ;
if ( V_107 )
goto V_156;
}
if ( V_2 -> V_54 . V_152 ) {
for ( V_111 = 0 ; V_111 < F_83 ( V_153 ) ; V_111 ++ ) {
V_107 = F_86 ( & V_153 [ V_111 ] ) ;
if ( V_107 )
goto V_157;
}
}
return 0 ;
V_157:
for ( V_154 = 0 ; V_154 < V_111 ; V_154 ++ )
F_84 ( & V_153 [ V_154 ] ) ;
F_84 ( & V_151 ) ;
V_156:
V_111 = F_83 ( V_149 ) ;
V_155:
for ( V_154 = 0 ; V_154 < V_111 ; V_154 ++ )
F_84 ( & V_149 [ V_154 ] ) ;
return V_107 ;
}
static bool F_87 ( struct V_158 * V_96 , void * V_159 )
{
struct V_160 * V_161 = V_159 ;
if ( V_161 && V_161 -> V_162 == V_96 -> V_163 -> V_33 ) {
V_96 -> V_164 = V_161 ;
return true ;
} else {
return false ;
}
}
static int F_88 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
int V_107 = - V_167 ;
T_7 V_168 ;
F_89 ( V_168 ) ;
F_90 ( V_169 , V_168 ) ;
V_2 -> V_92 . V_96 = F_91 ( V_168 ,
F_87 , & V_166 -> V_170 -> V_171 , V_2 -> V_33 , L_17 ) ;
if ( ! V_2 -> V_92 . V_96 ) {
F_81 ( V_2 -> V_33 , L_18 ) ;
return V_107 ;
}
V_2 -> V_92 . V_93 . V_172 = V_97 ;
V_2 -> V_92 . V_93 . V_173 = V_2 -> V_174 +
F_25 ( 0 ) ;
V_2 -> V_92 . V_93 . V_94 = 1 ;
V_2 -> V_92 . V_93 . V_175 =
V_176 ;
V_2 -> V_92 . V_93 . V_95 = 1 ;
V_2 -> V_92 . V_93 . V_177 =
V_176 ;
V_2 -> V_92 . V_93 . V_178 = false ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_93 ( V_2 -> V_92 . V_96 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
V_2 -> V_54 . V_55 = 0 ;
V_2 -> V_54 . V_59 = 0 ;
V_2 -> V_54 . V_150 = 0 ;
V_2 -> V_54 . V_152 = 0 ;
switch ( V_2 -> V_124 & 0xff0 ) {
case 0x420 :
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_59 = 1 ;
V_2 -> V_54 . V_150 = 1 ;
V_2 -> V_54 . V_152 = 1 ;
break;
case 0x410 :
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_59 = 1 ;
V_2 -> V_54 . V_150 = 1 ;
V_2 -> V_54 . V_152 = 1 ;
break;
case 0x400 :
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_59 = 1 ;
V_2 -> V_54 . V_150 = 1 ;
break;
case 0x320 :
break;
default:
F_81 ( V_2 -> V_33 ,
L_19 ) ;
break;
}
}
static struct V_165 * F_95 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = V_180 -> V_33 . V_183 ;
struct V_165 * V_166 ;
if ( ! V_182 ) {
F_41 ( & V_180 -> V_33 , L_20 ) ;
return F_96 ( - V_48 ) ;
}
V_166 = F_97 ( & V_180 -> V_33 , sizeof( * V_166 ) , V_184 ) ;
if ( ! V_166 ) {
F_41 ( & V_180 -> V_33 , L_21 ) ;
return F_96 ( - V_167 ) ;
}
V_166 -> V_170 = F_97 ( & V_180 -> V_33 ,
sizeof( * ( V_166 -> V_170 ) ) ,
V_184 ) ;
if ( ! V_166 -> V_170 ) {
F_41 ( & V_180 -> V_33 , L_22 ) ;
return F_96 ( - V_167 ) ;
}
return V_166 ;
}
static inline struct V_165 * F_95 ( struct V_179 * V_33 )
{
return F_96 ( - V_48 ) ;
}
static int F_98 ( struct V_179 * V_180 )
{
struct V_1 * V_142 ;
struct V_165 * V_166 ;
struct V_163 * V_33 = & V_180 -> V_33 ;
struct V_185 * V_186 ;
int V_107 ;
V_142 = F_97 ( & V_180 -> V_33 , sizeof( * V_142 ) , V_184 ) ;
if ( V_142 == NULL ) {
F_41 ( V_33 , L_23 ) ;
V_107 = - V_167 ;
goto V_187;
}
V_142 -> V_33 = V_33 ;
F_99 ( V_180 , V_142 ) ;
F_100 ( & V_142 -> V_188 ) ;
F_101 ( & V_142 -> V_32 ) ;
F_102 ( & V_142 -> V_120 , F_79 ,
( unsigned long ) V_142 ) ;
F_103 ( & V_142 -> V_129 , V_189 ) ;
V_142 -> V_140 = - 1 ;
V_186 = F_104 ( V_180 , V_190 , 0 ) ;
if ( ! V_186 ) {
F_41 ( V_33 , L_24 ) ;
V_107 = - V_191 ;
goto V_192;
}
V_142 -> V_174 = V_186 -> V_193 ;
V_142 -> V_140 = F_105 ( V_180 , 0 ) ;
if ( V_142 -> V_140 < 0 ) {
F_41 ( V_33 , L_25 ) ;
V_107 = V_142 -> V_140 ;
goto V_192;
}
V_107 = F_106 ( & V_180 -> V_33 , V_142 -> V_140 , F_80 ,
V_194 , L_26 , V_142 ) ;
if ( V_107 ) {
F_41 ( V_33 , L_27 ) ;
goto V_192;
}
V_142 -> V_117 = F_107 ( & V_180 -> V_33 , L_28 ) ;
if ( F_108 ( V_142 -> V_117 ) ) {
F_41 ( V_33 , L_29 ) ;
V_107 = F_109 ( V_142 -> V_117 ) ;
goto V_192;
}
V_142 -> V_4 = F_110 ( & V_180 -> V_33 , V_186 ) ;
if ( ! V_142 -> V_4 ) {
F_41 ( V_33 , L_30 ) ;
V_107 = - V_167 ;
goto V_192;
}
V_107 = F_111 ( V_142 -> V_117 ) ;
if ( V_107 )
goto V_192;
F_61 ( V_142 ) ;
F_94 ( V_142 ) ;
if ( V_142 -> V_54 . V_55 ) {
V_166 = V_180 -> V_33 . V_195 ;
if ( ! V_166 ) {
V_166 = F_95 ( V_180 ) ;
if ( F_108 ( V_166 ) ) {
F_41 ( & V_180 -> V_33 , L_31 ) ;
V_107 = F_109 ( V_166 ) ;
goto V_196;
}
}
if ( ! V_166 -> V_170 ) {
V_107 = - V_197 ;
goto V_196;
}
V_107 = F_88 ( V_142 , V_166 ) ;
if ( V_107 )
goto V_198;
F_62 ( V_33 , L_32 ,
F_112 ( V_142 -> V_92 . V_96 ) ) ;
}
F_113 ( & V_31 . V_32 ) ;
F_114 ( & V_142 -> V_188 , & V_31 . V_199 ) ;
F_115 ( & V_31 . V_32 ) ;
V_107 = F_85 ( V_142 ) ;
if ( V_107 )
goto V_200;
F_62 ( V_33 , L_33 ,
V_142 -> V_54 . V_150 ? L_34 : L_35 ,
V_142 -> V_54 . V_152 ? L_36 : L_35 ) ;
return 0 ;
V_200:
F_113 ( & V_31 . V_32 ) ;
F_116 ( & V_142 -> V_188 ) ;
F_115 ( & V_31 . V_32 ) ;
if ( V_142 -> V_54 . V_55 )
F_92 ( V_142 ) ;
V_198:
V_196:
F_117 ( V_142 -> V_117 ) ;
V_192:
F_118 ( & V_142 -> V_120 ) ;
V_187:
F_41 ( V_33 , L_37 ) ;
return V_107 ;
}
static int F_119 ( struct V_179 * V_180 )
{
static struct V_1 * V_142 ;
V_142 = F_120 ( V_180 ) ;
if ( ! V_142 )
return - V_191 ;
F_113 ( & V_31 . V_32 ) ;
F_116 ( & V_142 -> V_188 ) ;
F_115 ( & V_31 . V_32 ) ;
F_82 ( V_142 ) ;
F_118 ( & V_142 -> V_120 ) ;
if ( V_142 -> V_54 . V_55 )
F_92 ( V_142 ) ;
F_117 ( V_142 -> V_117 ) ;
return 0 ;
}
