static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_5 -> V_6 ;
struct V_1 * V_9 = (struct V_1 * ) V_8 -> V_6 ;
return V_9 ;
}
static int F_2 ( struct V_10 * V_11 , struct F_2 * V_12 )
{
struct V_13 V_14 ;
struct V_15 V_16 [ 4 ] ;
T_1 V_17 = 0xff ;
F_3 ( & V_14 ) ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] . V_18 = 1 ;
V_16 [ 0 ] . V_19 = & V_12 -> V_12 ;
F_4 ( & V_16 [ 0 ] , & V_14 ) ;
if ( V_12 -> V_20 ) {
V_16 [ 1 ] . V_18 = V_12 -> V_20 ;
V_16 [ 1 ] . V_19 = V_12 -> V_21 ;
F_4 ( & V_16 [ 1 ] , & V_14 ) ;
}
if ( V_12 -> V_22 ) {
V_16 [ 2 ] . V_18 = V_12 -> V_22 ;
V_16 [ 2 ] . V_19 = & V_17 ;
F_4 ( & V_16 [ 2 ] , & V_14 ) ;
}
if ( V_12 -> V_23 ) {
V_16 [ 3 ] . V_18 = V_12 -> V_23 ;
V_16 [ 3 ] . V_19 = V_12 -> V_19 ;
F_4 ( & V_16 [ 3 ] , & V_14 ) ;
}
if ( V_12 -> V_24 ) {
V_16 [ 3 ] . V_18 = V_12 -> V_24 ;
V_16 [ 3 ] . V_25 = V_12 -> V_25 ;
F_4 ( & V_16 [ 3 ] , & V_14 ) ;
}
return F_5 ( V_11 , & V_14 ) ;
}
static int F_6 ( struct V_10 * V_26 , T_1 * V_27 )
{
int V_28 ;
T_1 V_29 [ 3 ] ;
struct F_2 V_12 = { 0 } ;
V_12 . V_12 = V_30 ;
V_12 . V_24 = 3 ;
V_12 . V_25 = & V_29 [ 0 ] ;
V_28 = F_2 ( V_26 , & V_12 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_26 -> V_31 , L_1 , V_28 ) ;
return V_28 ;
}
V_27 [ 0 ] = V_29 [ 1 ] ;
V_27 [ 1 ] = V_29 [ 2 ] ;
return V_28 ;
}
static int F_8 ( struct V_10 * V_26 , T_2 * V_32 )
{
struct F_2 V_12 = { 0 } ;
int V_33 ;
V_12 . V_12 = V_34 ;
V_12 . V_20 = 1 ;
V_12 . V_21 [ 0 ] = V_35 ;
V_12 . V_24 = 1 ;
V_12 . V_25 = V_32 ;
V_33 = F_2 ( V_26 , & V_12 ) ;
if ( V_33 < 0 )
F_7 ( & V_26 -> V_31 , L_2 , V_33 ) ;
return V_33 ;
}
static int F_9 ( struct V_10 * V_26 )
{
unsigned long V_36 ;
int V_28 ;
T_1 V_37 = 0 ;
V_36 = V_38 + V_39 ;
do {
V_28 = F_8 ( V_26 , & V_37 ) ;
if ( V_28 < 0 )
return - 1 ;
else if ( ! ( V_37 & 0x1 ) )
break;
F_10 () ;
} while ( ! F_11 ( V_38 , V_36 ) );
if ( ( V_37 & 0x1 ) == 0 )
return 0 ;
return - 1 ;
}
static int F_12 ( struct V_10 * V_26 , T_1 * V_40 )
{
struct F_2 V_12 = { 0 } ;
int V_28 ;
V_12 . V_12 = V_34 ;
V_12 . V_20 = 1 ;
V_12 . V_21 [ 0 ] = V_41 ;
V_12 . V_24 = 1 ;
V_12 . V_25 = V_40 ;
V_28 = F_2 ( V_26 , & V_12 ) ;
if ( V_28 < 0 )
F_7 ( & V_26 -> V_31 , L_3 , V_28 ) ;
return V_28 ;
}
static int F_13 ( struct V_10 * V_26 , T_1 * V_40 )
{
int V_28 ;
struct F_2 V_12 = { 0 } ;
V_12 . V_12 = V_42 ,
V_12 . V_20 = 1 ,
V_12 . V_21 [ 0 ] = V_41 ,
V_12 . V_23 = 1 ,
V_12 . V_19 = V_40 ,
V_28 = F_2 ( V_26 , & V_12 ) ;
if ( V_28 < 0 )
F_7 ( & V_26 -> V_31 , L_4 , V_28 ) ;
return V_28 ;
}
static int F_14 ( struct V_10 * V_26 )
{
int V_28 ;
T_1 V_40 = 0 ;
V_28 = F_12 ( V_26 , & V_40 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_40 & V_43 ) == V_43 )
return 0 ;
V_40 |= V_43 ;
V_28 = F_13 ( V_26 , & V_40 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_12 ( V_26 , & V_40 ) ;
}
static int F_15 ( struct V_10 * V_26 )
{
int V_28 ;
T_1 V_40 = 0 ;
V_28 = F_12 ( V_26 , & V_40 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_40 & V_43 ) == V_43 ) {
V_40 &= ~ V_43 ;
V_28 = F_13 ( V_26 , & V_40 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_12 ( V_26 , & V_40 ) ;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_26 )
{
struct F_2 V_12 = { 0 } ;
V_12 . V_12 = V_44 ;
return F_2 ( V_26 , & V_12 ) ;
}
static int F_17 ( struct V_10 * V_26 , T_3 V_45 )
{
struct F_2 V_12 = { 0 } ;
T_3 V_46 ;
V_46 = V_45 ;
V_12 . V_12 = V_47 ;
V_12 . V_20 = 3 ;
V_12 . V_21 [ 1 ] = ( T_1 ) ( ( V_46 & 0xff00 ) >> 8 ) ;
V_12 . V_21 [ 2 ] = ( T_1 ) ( V_46 & 0x00ff ) ;
return F_2 ( V_26 , & V_12 ) ;
}
static int F_18 ( struct V_10 * V_26 , T_3 V_45 ,
T_3 V_48 , T_3 V_18 , T_1 * V_49 )
{
struct F_2 V_12 = { 0 } ;
T_3 V_50 ;
V_50 = V_48 ;
V_12 . V_12 = V_51 ;
V_12 . V_20 = 3 ;
V_12 . V_21 [ 0 ] = ( T_1 ) ( ( V_50 & 0xff00 ) >> 8 ) ;
V_12 . V_21 [ 0 ] |= ( T_1 ) ( ( ( V_45 >> 6 ) & 0x1 ) << 4 ) ;
V_12 . V_21 [ 1 ] = ( T_1 ) ( V_50 & 0x00ff ) ;
V_12 . V_21 [ 2 ] = ( T_1 ) ( 0xff ) ;
V_12 . V_22 = 0 ;
V_12 . V_24 = V_18 ;
V_12 . V_25 = V_49 ;
return F_2 ( V_26 , & V_12 ) ;
}
static int F_19 ( struct V_10 * V_26 , T_3 V_45 ,
T_3 V_52 , T_3 V_18 , T_1 * V_49 )
{
int V_33 ;
T_1 V_32 = 0 ;
#ifdef F_20
if ( V_53 ) {
if ( F_14 ( V_26 ) < 0 )
F_7 ( & V_26 -> V_31 , L_5 ) ;
}
#endif
V_33 = F_17 ( V_26 , V_45 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( F_9 ( V_26 ) )
F_7 ( & V_26 -> V_31 , L_6 ) ;
while ( 1 ) {
V_33 = F_8 ( V_26 , & V_32 ) ;
if ( V_33 < 0 ) {
F_7 ( & V_26 -> V_31 ,
L_7 , V_33 ) ;
return V_33 ;
}
if ( ( V_32 & V_54 ) == V_55 ) {
if ( ( V_32 & V_56 ) == V_57 ) {
F_7 ( & V_26 -> V_31 , L_8 ,
V_45 ) ;
return 0 ;
}
break;
}
}
V_33 = F_18 ( V_26 , V_45 , V_52 , V_18 , V_49 ) ;
if ( V_33 < 0 ) {
F_7 ( & V_26 -> V_31 , L_9 ) ;
return V_33 ;
}
#ifdef F_20
if ( V_53 ) {
V_33 = F_15 ( V_26 ) ;
if ( V_33 < 0 ) {
F_7 ( & V_26 -> V_31 , L_10 ) ;
return V_33 ;
}
V_53 = 0 ;
}
#endif
return V_33 ;
}
static int F_21 ( struct V_10 * V_26 ,
T_3 V_45 , T_3 V_48 , T_3 V_18 , T_1 * V_58 )
{
struct F_2 V_12 = { 0 } ;
T_3 V_50 ;
V_50 = V_48 ;
V_12 . V_12 = V_59 ;
V_12 . V_20 = 2 ;
V_12 . V_21 [ 0 ] = ( T_1 ) ( ( V_50 & 0xff00 ) >> 8 ) ;
V_12 . V_21 [ 0 ] |= ( T_1 ) ( ( ( V_45 >> 6 ) & 0x1 ) << 4 ) ;
V_12 . V_21 [ 1 ] = ( T_1 ) ( V_50 & 0x00ff ) ;
V_12 . V_23 = V_18 ;
V_12 . V_19 = V_58 ;
return F_2 ( V_26 , & V_12 ) ;
}
static int F_22 ( struct V_10 * V_26 , T_3 V_45 )
{
struct F_2 V_12 = { 0 } ;
T_3 V_46 ;
V_46 = V_45 ;
V_12 . V_12 = V_60 ;
V_12 . V_20 = 3 ;
V_12 . V_21 [ 1 ] = ( T_1 ) ( ( V_46 & 0xff00 ) >> 8 ) ;
V_12 . V_21 [ 2 ] = ( T_1 ) ( V_46 & 0x00ff ) ;
return F_2 ( V_26 , & V_12 ) ;
}
static int F_23 ( struct V_10 * V_26 ,
T_3 V_45 , T_3 V_52 , T_3 V_18 , T_1 * V_61 )
{
int V_28 ;
T_1 V_32 = 0 ;
T_2 * V_58 ;
#ifdef F_20
unsigned int V_62 , V_63 ;
V_53 = 0 ;
V_58 = F_24 ( & V_26 -> V_31 , V_64 , V_65 ) ;
F_19 ( V_26 , V_45 , 0 , V_64 , V_58 ) ;
for ( V_62 = V_52 , V_63 = 0 ; V_62 < V_18 ; V_62 ++ , V_63 ++ )
V_58 [ V_62 ] &= V_61 [ V_63 ] ;
if ( V_66 ) {
V_28 = F_14 ( V_26 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_26 -> V_31 , L_11 ) ;
return V_28 ;
}
}
#else
V_58 = V_61 ;
#endif
V_28 = F_16 ( V_26 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_26 -> V_31 , L_12 ) ;
return V_28 ;
}
if ( F_9 ( V_26 ) )
F_7 ( & V_26 -> V_31 , L_13 ) ;
V_28 = F_21 ( V_26 , V_45 ,
V_52 , V_18 , V_58 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_22 ( V_26 , V_45 ) ;
if ( V_28 < 0 )
return V_28 ;
while ( 1 ) {
V_28 = F_8 ( V_26 , & V_32 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_26 -> V_31 ,
L_14 ,
V_28 ) ;
return V_28 ;
}
if ( ( V_32 & V_54 ) == V_55 ) {
if ( ( V_32 & V_67 ) == V_68 ) {
F_7 ( & V_26 -> V_31 ,
L_15 , V_45 ) ;
return - 1 ;
}
break;
}
}
#ifdef F_20
if ( V_66 ) {
V_28 = F_15 ( V_26 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_26 -> V_31 , L_10 ) ;
return V_28 ;
}
V_66 = 0 ;
}
#endif
return 0 ;
}
static int F_25 ( struct V_10 * V_26 , T_3 V_69 )
{
struct F_2 V_12 = { 0 } ;
T_3 V_46 ;
V_46 = V_69 ;
V_12 . V_12 = V_70 ;
V_12 . V_20 = 3 ;
V_12 . V_21 [ 1 ] = ( T_1 ) ( ( V_46 & 0xff00 ) >> 8 ) ;
V_12 . V_21 [ 2 ] = ( T_1 ) ( V_46 & 0x00ff ) ;
return F_2 ( V_26 , & V_12 ) ;
}
static int F_26 ( struct V_10 * V_26 , T_3 V_69 )
{
int V_28 ;
T_1 V_32 = 0 ;
V_28 = F_16 ( V_26 ) ;
if ( F_9 ( V_26 ) )
F_7 ( & V_26 -> V_31 , L_13 ) ;
V_28 = F_25 ( V_26 , V_69 ) ;
while ( 1 ) {
V_28 = F_8 ( V_26 , & V_32 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_26 -> V_31 ,
L_14 ,
( int ) V_28 ) ;
return V_28 ;
}
if ( ( V_32 & V_54 ) == V_55 ) {
if ( ( V_32 & V_71 ) == V_72 ) {
F_7 ( & V_26 -> V_31 ,
L_16 , V_69 ) ;
return - 1 ;
}
break;
}
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_4 * V_5 , const T_2 * V_61 , int V_73 )
{
const T_2 * V_74 = V_61 ;
int V_75 = V_5 -> V_76 . V_77 ;
int V_78 = V_5 -> V_76 . V_79 ;
V_66 = 1 ;
V_5 -> V_80 ( V_3 , V_74 , V_75 * V_78 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_4 * V_5 ,
T_2 * V_61 , int V_73 , int V_81 )
{
int V_28 ;
T_1 V_32 ;
T_2 * V_74 = V_61 ;
int V_75 = V_5 -> V_76 . V_77 ;
int V_78 = V_5 -> V_76 . V_79 ;
struct V_7 * V_8 = (struct V_7 * ) V_5 -> V_6 ;
V_53 = 1 ;
V_5 -> V_82 ( V_3 , V_74 , V_75 * V_78 ) ;
if ( V_73 )
V_5 -> V_82 ( V_3 , V_5 -> V_83 , V_3 -> V_84 ) ;
while ( 1 ) {
V_28 = F_8 ( V_8 -> V_11 , & V_32 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_3 -> V_31 ,
L_14 ,
V_28 ) ;
return V_28 ;
}
if ( ( V_32 & V_54 ) == V_55 ) {
if ( ( V_32 & V_56 ) == V_57 ) {
F_29 ( L_17 ) ;
V_3 -> V_85 . V_86 ++ ;
} else if ( ( V_32 & V_56 ) ==
V_87 )
V_3 -> V_85 . V_88 ++ ;
break;
}
}
return 0 ;
}
static void F_30 ( struct V_2 * V_3 , int V_31 )
{
}
static T_2 F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_89 ;
V_89 = V_9 -> V_61 [ V_9 -> V_90 ] ;
V_9 -> V_90 ++ ;
return V_89 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_5 -> V_6 ;
unsigned long V_91 = V_38 ;
int V_28 , V_9 = V_5 -> V_9 ;
T_1 V_32 ;
if ( V_9 == V_92 )
V_91 += ( V_93 * 400 ) / 1000 ;
else
V_91 += ( V_93 * 20 ) / 1000 ;
while ( F_33 ( V_38 , V_91 ) ) {
V_28 = F_8 ( V_8 -> V_11 , & V_32 ) ;
if ( V_28 < 0 ) {
F_7 ( & V_3 -> V_31 ,
L_14 ,
V_28 ) ;
return V_28 ;
}
if ( ( V_32 & V_54 ) == V_55 )
return 0 ;
F_10 () ;
}
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , const T_2 * V_61 , int V_18 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
memcpy ( V_9 -> V_61 + V_9 -> V_90 , V_61 , V_18 ) ;
V_9 -> V_90 += V_18 ;
}
static void F_35 ( struct V_2 * V_3 , T_2 * V_61 , int V_18 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
memcpy ( V_61 , V_9 -> V_61 + V_9 -> V_90 , V_18 ) ;
V_9 -> V_90 += V_18 ;
}
static void F_36 ( struct V_10 * V_26 )
{
struct F_2 V_12 = { 0 } ;
V_12 . V_12 = V_94 ;
if ( F_2 ( V_26 , & V_12 ) < 0 )
F_29 ( L_18 ) ;
F_37 ( 1000 ) ;
if ( F_9 ( V_26 ) )
F_7 ( & V_26 -> V_31 , L_19 ) ;
}
static void F_38 ( struct V_2 * V_3 , unsigned int V_95 ,
int V_50 , int V_81 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_5 -> V_6 ;
struct V_1 * V_9 = (struct V_1 * ) V_8 -> V_6 ;
switch ( V_95 ) {
case V_96 :
case V_97 :
V_9 -> V_90 = 0 ;
F_19 ( V_8 -> V_11 , V_81 , 0x0 , 0x840 , V_9 -> V_61 ) ;
break;
case V_98 :
V_9 -> V_90 = 0 ;
F_19 ( V_8 -> V_11 , V_81 , 0x800 , 0x40 , V_9 -> V_61 ) ;
break;
case V_99 :
V_9 -> V_90 = V_50 ;
break;
case V_100 :
V_9 -> V_90 = 0 ;
F_6 ( V_8 -> V_11 , V_9 -> V_61 ) ;
break;
case V_101 :
V_9 -> V_90 = 0 ;
break;
case V_102 :
F_26 ( V_8 -> V_11 , V_81 ) ;
break;
case V_103 :
break;
case V_104 :
V_9 -> V_105 = V_50 ;
V_9 -> V_46 = V_81 ;
V_9 -> V_90 = 0 ;
break;
case V_106 :
F_23 ( V_8 -> V_11 , V_9 -> V_46 , V_9 -> V_105 ,
V_9 -> V_90 , V_9 -> V_61 ) ;
break;
case V_107 :
F_12 ( V_8 -> V_11 , V_9 -> V_61 ) ;
if ( ! ( V_9 -> V_61 [ 0 ] & 0x80 ) )
V_9 -> V_61 [ 0 ] = 0x80 ;
V_9 -> V_90 = 0 ;
break;
case V_108 :
if ( F_9 ( V_8 -> V_11 ) )
F_7 ( & V_8 -> V_11 -> V_31 , L_6 ) ;
F_37 ( 250 ) ;
F_36 ( V_8 -> V_11 ) ;
break;
default:
F_7 ( & V_3 -> V_31 , L_20 , V_95 ) ;
}
}
static int F_39 ( struct V_10 * V_26 , T_1 V_109 )
{
struct F_2 V_12 = { 0 } ;
int V_33 ;
T_1 V_40 = 0 ;
V_33 = F_12 ( V_26 , & V_40 ) ;
V_12 . V_12 = V_42 ;
V_12 . V_20 = 1 ;
V_12 . V_21 [ 0 ] = V_110 ;
V_12 . V_23 = 1 ;
V_12 . V_19 = & V_109 ;
V_33 = F_2 ( V_26 , & V_12 ) ;
if ( V_33 < 0 )
F_7 ( & V_26 -> V_31 , L_21 , V_33 ) ;
return V_33 ;
}
static int F_40 ( struct V_10 * V_26 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_111 V_112 ;
V_8 = F_24 ( & V_26 -> V_31 , sizeof( struct V_7 ) ,
V_65 ) ;
if ( ! V_8 )
return - V_113 ;
V_8 -> V_11 = V_26 ;
F_39 ( V_26 , V_114 ) ;
V_9 = F_24 ( & V_26 -> V_31 , sizeof( struct V_1 ) ,
V_65 ) ;
if ( ! V_9 )
return - V_113 ;
V_8 -> V_6 = V_9 ;
V_9 -> V_90 = 0 ;
V_9 -> V_61 = F_24 ( & V_26 -> V_31 , V_115 , V_65 ) ;
if ( ! V_9 -> V_61 )
return - V_113 ;
V_5 = F_24 ( & V_26 -> V_31 , sizeof( struct V_4 ) ,
V_65 ) ;
if ( ! V_5 )
return - V_113 ;
#ifdef F_20
V_5 -> V_76 . V_116 = V_117 ;
V_5 -> V_76 . V_77 = 0x200 ;
V_5 -> V_76 . V_118 = 0x6 ;
V_5 -> V_76 . V_79 = 0x4 ;
V_5 -> V_76 . V_119 = 1 ;
V_5 -> V_76 . V_120 = V_5 -> V_76 . V_79 * V_5 -> V_76 . V_118 ;
V_5 -> V_76 . V_121 = & V_122 ;
V_5 -> V_76 . V_123 = F_28 ;
V_5 -> V_76 . V_124 = F_27 ;
#else
V_5 -> V_76 . V_116 = V_125 ;
if ( F_15 ( V_26 ) < 0 )
F_29 ( L_22 , V_126 ) ;
#endif
V_5 -> V_6 = V_8 ;
V_5 -> V_82 = F_35 ;
V_5 -> V_80 = F_34 ;
V_5 -> V_127 = F_31 ;
V_5 -> V_128 = F_38 ;
V_5 -> V_129 = F_32 ;
V_5 -> V_130 |= V_131 ;
V_5 -> V_132 = F_30 ;
V_3 = F_24 ( & V_26 -> V_31 , sizeof( struct V_2 ) , V_65 ) ;
if ( ! V_3 )
return - V_113 ;
F_41 ( & V_26 -> V_31 , V_3 ) ;
V_3 -> V_6 = V_5 ;
V_3 -> V_133 = F_42 ( & V_26 -> V_31 ) ;
V_3 -> V_134 = V_135 ;
V_3 -> V_84 = 64 ;
if ( F_43 ( V_3 , 1 ) )
return - V_136 ;
V_112 . V_137 = V_26 -> V_31 . V_137 ;
return F_44 ( V_3 , NULL , & V_112 , NULL , 0 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
F_46 ( F_47 ( & V_11 -> V_31 ) ) ;
return 0 ;
}
