static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_1 * V_8 = V_7 -> V_9 ;
return V_8 ;
}
static int F_4 ( struct V_2 * V_3 , int V_10 ,
struct V_11 * V_12 )
{
if ( V_10 > 3 )
return - V_13 ;
V_12 -> V_14 = ( V_10 * 16 ) + 1 ;
V_12 -> V_15 = 6 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , int V_10 ,
struct V_11 * V_12 )
{
if ( V_10 > 3 )
return - V_13 ;
V_12 -> V_14 = ( V_10 * 16 ) + 8 ;
V_12 -> V_15 = 8 ;
return 0 ;
}
static int F_6 ( struct V_16 * V_17 , struct F_6 * V_18 )
{
struct V_19 V_20 ;
struct V_21 V_22 [ 4 ] ;
T_1 V_23 = 0xff ;
F_7 ( & V_20 ) ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
V_22 [ 0 ] . V_24 = 1 ;
V_22 [ 0 ] . V_25 = & V_18 -> V_18 ;
F_8 ( & V_22 [ 0 ] , & V_20 ) ;
if ( V_18 -> V_26 ) {
V_22 [ 1 ] . V_24 = V_18 -> V_26 ;
V_22 [ 1 ] . V_25 = V_18 -> V_27 ;
F_8 ( & V_22 [ 1 ] , & V_20 ) ;
}
if ( V_18 -> V_28 ) {
V_22 [ 2 ] . V_24 = V_18 -> V_28 ;
V_22 [ 2 ] . V_25 = & V_23 ;
F_8 ( & V_22 [ 2 ] , & V_20 ) ;
}
if ( V_18 -> V_29 ) {
V_22 [ 3 ] . V_24 = V_18 -> V_29 ;
V_22 [ 3 ] . V_25 = V_18 -> V_25 ;
F_8 ( & V_22 [ 3 ] , & V_20 ) ;
}
if ( V_18 -> V_30 ) {
V_22 [ 3 ] . V_24 = V_18 -> V_30 ;
V_22 [ 3 ] . V_31 = V_18 -> V_31 ;
F_8 ( & V_22 [ 3 ] , & V_20 ) ;
}
return F_9 ( V_17 , & V_20 ) ;
}
static int F_10 ( struct V_16 * V_32 , T_1 * V_33 )
{
int V_34 ;
T_1 V_35 [ 3 ] ;
struct F_6 V_18 = { 0 } ;
V_18 . V_18 = V_36 ;
V_18 . V_30 = 3 ;
V_18 . V_31 = & V_35 [ 0 ] ;
V_34 = F_6 ( V_32 , & V_18 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 , L_1 , V_34 ) ;
return V_34 ;
}
V_33 [ 0 ] = V_35 [ 1 ] ;
V_33 [ 1 ] = V_35 [ 2 ] ;
return V_34 ;
}
static int F_12 ( struct V_16 * V_32 , T_1 * V_38 )
{
struct F_6 V_18 = { 0 } ;
int V_39 ;
V_18 . V_18 = V_40 ;
V_18 . V_26 = 1 ;
V_18 . V_27 [ 0 ] = V_41 ;
V_18 . V_30 = 1 ;
V_18 . V_31 = V_38 ;
V_39 = F_6 ( V_32 , & V_18 ) ;
if ( V_39 < 0 )
F_11 ( & V_32 -> V_37 , L_2 , V_39 ) ;
return V_39 ;
}
static int F_13 ( struct V_16 * V_32 )
{
unsigned long V_42 ;
int V_34 ;
T_1 V_43 = 0 ;
V_42 = V_44 + V_45 ;
do {
V_34 = F_12 ( V_32 , & V_43 ) ;
if ( V_34 < 0 )
return - 1 ;
if ( ! ( V_43 & 0x1 ) )
break;
F_14 () ;
} while ( ! F_15 ( V_44 , V_42 ) );
if ( ( V_43 & 0x1 ) == 0 )
return 0 ;
return - 1 ;
}
static int F_16 ( struct V_16 * V_32 , T_1 * V_46 )
{
struct F_6 V_18 = { 0 } ;
int V_34 ;
V_18 . V_18 = V_40 ;
V_18 . V_26 = 1 ;
V_18 . V_27 [ 0 ] = V_47 ;
V_18 . V_30 = 1 ;
V_18 . V_31 = V_46 ;
V_34 = F_6 ( V_32 , & V_18 ) ;
if ( V_34 < 0 )
F_11 ( & V_32 -> V_37 , L_3 , V_34 ) ;
return V_34 ;
}
static int F_17 ( struct V_16 * V_32 , T_1 * V_46 )
{
int V_34 ;
struct F_6 V_18 = { 0 } ;
V_18 . V_18 = V_48 ;
V_18 . V_26 = 1 ;
V_18 . V_27 [ 0 ] = V_47 ;
V_18 . V_29 = 1 ;
V_18 . V_25 = V_46 ;
V_34 = F_6 ( V_32 , & V_18 ) ;
if ( V_34 < 0 )
F_11 ( & V_32 -> V_37 , L_4 , V_34 ) ;
return V_34 ;
}
static int F_18 ( struct V_16 * V_32 )
{
int V_34 ;
T_1 V_46 = 0 ;
V_34 = F_16 ( V_32 , & V_46 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ( V_46 & V_49 ) == V_49 )
return 0 ;
V_46 |= V_49 ;
V_34 = F_17 ( V_32 , & V_46 ) ;
if ( V_34 < 0 )
return V_34 ;
return F_16 ( V_32 , & V_46 ) ;
}
static int F_19 ( struct V_16 * V_32 )
{
int V_34 ;
T_1 V_46 = 0 ;
V_34 = F_16 ( V_32 , & V_46 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ( V_46 & V_49 ) == V_49 ) {
V_46 &= ~ V_49 ;
V_34 = F_17 ( V_32 , & V_46 ) ;
if ( V_34 < 0 )
return V_34 ;
return F_16 ( V_32 , & V_46 ) ;
}
return 0 ;
}
static int F_20 ( struct V_16 * V_32 )
{
struct F_6 V_18 = { 0 } ;
V_18 . V_18 = V_50 ;
return F_6 ( V_32 , & V_18 ) ;
}
static int F_21 ( struct V_16 * V_32 , T_2 V_51 )
{
struct F_6 V_18 = { 0 } ;
T_2 V_52 ;
V_52 = V_51 ;
V_18 . V_18 = V_53 ;
V_18 . V_26 = 3 ;
V_18 . V_27 [ 1 ] = ( T_1 ) ( ( V_52 & 0xff00 ) >> 8 ) ;
V_18 . V_27 [ 2 ] = ( T_1 ) ( V_52 & 0x00ff ) ;
return F_6 ( V_32 , & V_18 ) ;
}
static int F_22 ( struct V_16 * V_32 , T_2 V_51 ,
T_2 V_54 , T_2 V_24 , T_1 * V_55 )
{
struct F_6 V_18 = { 0 } ;
T_2 V_56 ;
V_56 = V_54 ;
V_18 . V_18 = V_57 ;
V_18 . V_26 = 3 ;
V_18 . V_27 [ 0 ] = ( T_1 ) ( ( V_56 & 0xff00 ) >> 8 ) ;
V_18 . V_27 [ 0 ] |= ( T_1 ) ( ( ( V_51 >> 6 ) & 0x1 ) << 4 ) ;
V_18 . V_27 [ 1 ] = ( T_1 ) ( V_56 & 0x00ff ) ;
V_18 . V_27 [ 2 ] = ( T_1 ) ( 0xff ) ;
V_18 . V_28 = 0 ;
V_18 . V_30 = V_24 ;
V_18 . V_31 = V_55 ;
return F_6 ( V_32 , & V_18 ) ;
}
static int F_23 ( struct V_16 * V_32 , T_2 V_51 ,
T_2 V_14 , T_2 V_24 , T_1 * V_55 )
{
int V_39 ;
T_1 V_38 = 0 ;
#ifdef F_24
if ( V_58 ) {
if ( F_18 ( V_32 ) < 0 )
F_11 ( & V_32 -> V_37 , L_5 ) ;
}
#endif
V_39 = F_21 ( V_32 , V_51 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( F_13 ( V_32 ) )
F_11 ( & V_32 -> V_37 , L_6 ) ;
while ( 1 ) {
V_39 = F_12 ( V_32 , & V_38 ) ;
if ( V_39 < 0 ) {
F_11 ( & V_32 -> V_37 ,
L_7 , V_39 ) ;
return V_39 ;
}
if ( ( V_38 & V_59 ) == V_60 ) {
if ( ( V_38 & V_61 ) == V_62 ) {
F_11 ( & V_32 -> V_37 , L_8 ,
V_51 ) ;
return 0 ;
}
break;
}
}
V_39 = F_22 ( V_32 , V_51 , V_14 , V_24 , V_55 ) ;
if ( V_39 < 0 ) {
F_11 ( & V_32 -> V_37 , L_9 ) ;
return V_39 ;
}
#ifdef F_24
if ( V_58 ) {
V_39 = F_19 ( V_32 ) ;
if ( V_39 < 0 ) {
F_11 ( & V_32 -> V_37 , L_10 ) ;
return V_39 ;
}
V_58 = 0 ;
}
#endif
return V_39 ;
}
static int F_25 ( struct V_16 * V_32 ,
T_2 V_51 , T_2 V_54 ,
T_2 V_24 , T_1 * V_63 )
{
struct F_6 V_18 = { 0 } ;
T_2 V_56 ;
V_56 = V_54 ;
V_18 . V_18 = V_64 ;
V_18 . V_26 = 2 ;
V_18 . V_27 [ 0 ] = ( T_1 ) ( ( V_56 & 0xff00 ) >> 8 ) ;
V_18 . V_27 [ 0 ] |= ( T_1 ) ( ( ( V_51 >> 6 ) & 0x1 ) << 4 ) ;
V_18 . V_27 [ 1 ] = ( T_1 ) ( V_56 & 0x00ff ) ;
V_18 . V_29 = V_24 ;
V_18 . V_25 = V_63 ;
return F_6 ( V_32 , & V_18 ) ;
}
static int F_26 ( struct V_16 * V_32 , T_2 V_51 )
{
struct F_6 V_18 = { 0 } ;
T_2 V_52 ;
V_52 = V_51 ;
V_18 . V_18 = V_65 ;
V_18 . V_26 = 3 ;
V_18 . V_27 [ 1 ] = ( T_1 ) ( ( V_52 & 0xff00 ) >> 8 ) ;
V_18 . V_27 [ 2 ] = ( T_1 ) ( V_52 & 0x00ff ) ;
return F_6 ( V_32 , & V_18 ) ;
}
static int F_27 ( struct V_16 * V_32 ,
T_2 V_51 , T_2 V_14 , T_2 V_24 , T_1 * V_66 )
{
int V_34 ;
T_1 V_38 = 0 ;
T_1 * V_63 ;
#ifdef F_24
unsigned int V_67 , V_68 ;
V_63 = F_28 ( & V_32 -> V_37 , V_69 , V_70 ) ;
if ( ! V_63 )
return - V_71 ;
V_58 = 1 ;
V_34 = F_23 ( V_32 , V_51 , 0 , V_69 , V_63 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 , L_11 ) ;
return V_34 ;
}
for ( V_67 = V_14 , V_68 = 0 ; V_67 < V_24 ; V_67 ++ , V_68 ++ )
V_63 [ V_67 ] &= V_66 [ V_68 ] ;
if ( V_72 ) {
V_34 = F_18 ( V_32 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 , L_12 ) ;
return V_34 ;
}
}
#else
V_63 = V_66 ;
#endif
V_34 = F_20 ( V_32 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 , L_13 ) ;
return V_34 ;
}
if ( F_13 ( V_32 ) )
F_11 ( & V_32 -> V_37 , L_14 ) ;
V_34 = F_25 ( V_32 , V_51 ,
V_14 , V_24 , V_63 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_26 ( V_32 , V_51 ) ;
if ( V_34 < 0 )
return V_34 ;
while ( 1 ) {
V_34 = F_12 ( V_32 , & V_38 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 ,
L_15 , V_34 ) ;
return V_34 ;
}
if ( ( V_38 & V_59 ) == V_60 ) {
if ( ( V_38 & V_73 ) == V_74 ) {
F_11 ( & V_32 -> V_37 ,
L_16 , V_51 ) ;
return - 1 ;
}
break;
}
}
#ifdef F_24
if ( V_72 ) {
V_34 = F_19 ( V_32 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 , L_10 ) ;
return V_34 ;
}
V_72 = 0 ;
}
#endif
return 0 ;
}
static int F_29 ( struct V_16 * V_32 , T_2 V_75 )
{
struct F_6 V_18 = { 0 } ;
T_2 V_52 ;
V_52 = V_75 ;
V_18 . V_18 = V_76 ;
V_18 . V_26 = 3 ;
V_18 . V_27 [ 1 ] = ( T_1 ) ( ( V_52 & 0xff00 ) >> 8 ) ;
V_18 . V_27 [ 2 ] = ( T_1 ) ( V_52 & 0x00ff ) ;
return F_6 ( V_32 , & V_18 ) ;
}
static int F_30 ( struct V_16 * V_32 , T_2 V_75 )
{
int V_34 ;
T_1 V_38 = 0 ;
V_34 = F_20 ( V_32 ) ;
if ( F_13 ( V_32 ) )
F_11 ( & V_32 -> V_37 , L_14 ) ;
V_34 = F_29 ( V_32 , V_75 ) ;
while ( 1 ) {
V_34 = F_12 ( V_32 , & V_38 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_32 -> V_37 ,
L_15 , V_34 ) ;
return V_34 ;
}
if ( ( V_38 & V_59 ) == V_60 ) {
if ( ( V_38 & V_77 ) == V_78 ) {
F_11 ( & V_32 -> V_37 ,
L_17 , V_75 ) ;
return - 1 ;
}
break;
}
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const T_1 * V_66 , int V_79 ,
int V_80 )
{
const T_1 * V_81 = V_66 ;
int V_82 = V_5 -> V_83 . V_84 ;
int V_85 = V_5 -> V_83 . V_86 ;
V_72 = 1 ;
V_5 -> V_87 ( V_3 , V_81 , V_82 * V_85 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_4 * V_5 ,
T_1 * V_66 , int V_79 , int V_80 )
{
int V_34 ;
T_1 V_38 ;
T_1 * V_81 = V_66 ;
int V_82 = V_5 -> V_83 . V_84 ;
int V_85 = V_5 -> V_83 . V_86 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
V_58 = 1 ;
V_5 -> V_88 ( V_3 , V_81 , V_82 * V_85 ) ;
if ( V_79 )
V_5 -> V_88 ( V_3 , V_5 -> V_89 , V_3 -> V_90 ) ;
while ( 1 ) {
V_34 = F_12 ( V_7 -> V_17 , & V_38 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_3 -> V_37 ,
L_15 , V_34 ) ;
return V_34 ;
}
if ( ( V_38 & V_59 ) == V_60 ) {
if ( ( V_38 & V_61 ) == V_62 ) {
F_33 ( L_18 ) ;
V_3 -> V_91 . V_92 ++ ;
} else if ( ( V_38 & V_61 ) ==
V_93 )
V_3 -> V_91 . V_94 ++ ;
break;
}
}
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , int V_37 )
{
}
static T_1 F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_95 ;
V_95 = V_8 -> V_66 [ V_8 -> V_96 ] ;
V_8 -> V_96 ++ ;
return V_95 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned long V_97 = V_44 ;
int V_34 , V_8 = V_5 -> V_8 ;
T_1 V_38 ;
if ( V_8 == V_98 )
V_97 += ( V_99 * 400 ) / 1000 ;
else
V_97 += ( V_99 * 20 ) / 1000 ;
while ( F_37 ( V_44 , V_97 ) ) {
V_34 = F_12 ( V_7 -> V_17 , & V_38 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_3 -> V_37 ,
L_15 , V_34 ) ;
return V_34 ;
}
if ( ( V_38 & V_59 ) == V_60 )
return 0 ;
F_14 () ;
}
return 0 ;
}
static void F_38 ( struct V_2 * V_3 , const T_1 * V_66 , int V_24 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
memcpy ( V_8 -> V_66 + V_8 -> V_96 , V_66 , V_24 ) ;
V_8 -> V_96 += V_24 ;
}
static void F_39 ( struct V_2 * V_3 , T_1 * V_66 , int V_24 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
memcpy ( V_66 , V_8 -> V_66 + V_8 -> V_96 , V_24 ) ;
V_8 -> V_96 += V_24 ;
}
static void F_40 ( struct V_16 * V_32 )
{
struct F_6 V_18 = { 0 } ;
V_18 . V_18 = V_100 ;
if ( F_6 ( V_32 , & V_18 ) < 0 )
F_33 ( L_19 ) ;
F_41 ( 1000 , 2000 ) ;
if ( F_13 ( V_32 ) )
F_11 ( & V_32 -> V_37 , L_20 ) ;
}
static void F_42 ( struct V_2 * V_3 , unsigned int V_101 ,
int V_56 , int V_80 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_1 * V_8 = V_7 -> V_9 ;
switch ( V_101 ) {
case V_102 :
case V_103 :
V_8 -> V_96 = 0 ;
F_23 ( V_7 -> V_17 , V_80 , 0x0 , 0x840 , V_8 -> V_66 ) ;
break;
case V_104 :
V_8 -> V_96 = 0 ;
F_23 ( V_7 -> V_17 , V_80 , 0x800 , 0x40 , V_8 -> V_66 ) ;
break;
case V_105 :
V_8 -> V_96 = V_56 ;
break;
case V_106 :
V_8 -> V_96 = 0 ;
F_10 ( V_7 -> V_17 , V_8 -> V_66 ) ;
break;
case V_107 :
V_8 -> V_96 = 0 ;
break;
case V_108 :
F_30 ( V_7 -> V_17 , V_80 ) ;
break;
case V_109 :
break;
case V_110 :
V_8 -> V_111 = V_56 ;
V_8 -> V_52 = V_80 ;
V_8 -> V_96 = 0 ;
break;
case V_112 :
F_27 ( V_7 -> V_17 , V_8 -> V_52 , V_8 -> V_111 ,
V_8 -> V_96 , V_8 -> V_66 ) ;
break;
case V_113 :
F_16 ( V_7 -> V_17 , V_8 -> V_66 ) ;
if ( ! ( V_8 -> V_66 [ 0 ] & 0x80 ) )
V_8 -> V_66 [ 0 ] = 0x80 ;
V_8 -> V_96 = 0 ;
break;
case V_114 :
if ( F_13 ( V_7 -> V_17 ) )
F_11 ( & V_7 -> V_17 -> V_37 , L_6 ) ;
F_41 ( 250 , 1000 ) ;
F_40 ( V_7 -> V_17 ) ;
break;
default:
F_11 ( & V_3 -> V_37 , L_21 , V_101 ) ;
}
}
static int F_43 ( struct V_16 * V_32 , T_1 V_115 )
{
struct F_6 V_18 = { 0 } ;
int V_39 ;
T_1 V_46 = 0 ;
V_39 = F_16 ( V_32 , & V_46 ) ;
V_18 . V_18 = V_48 ;
V_18 . V_26 = 1 ;
V_18 . V_27 [ 0 ] = V_116 ;
V_18 . V_29 = 1 ;
V_18 . V_25 = & V_115 ;
V_39 = F_6 ( V_32 , & V_18 ) ;
if ( V_39 < 0 )
F_11 ( & V_32 -> V_37 , L_22 , V_39 ) ;
return V_39 ;
}
static int F_44 ( struct V_16 * V_32 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
V_7 = F_28 ( & V_32 -> V_37 , sizeof( struct V_6 ) ,
V_70 ) ;
if ( ! V_7 )
return - V_71 ;
V_7 -> V_17 = V_32 ;
F_43 ( V_32 , V_117 ) ;
V_8 = F_28 ( & V_32 -> V_37 , sizeof( struct V_1 ) ,
V_70 ) ;
if ( ! V_8 )
return - V_71 ;
V_7 -> V_9 = V_8 ;
V_8 -> V_96 = 0 ;
V_8 -> V_66 = F_28 ( & V_32 -> V_37 , V_118 , V_70 ) ;
if ( ! V_8 -> V_66 )
return - V_71 ;
V_5 = F_28 ( & V_32 -> V_37 , sizeof( struct V_4 ) ,
V_70 ) ;
if ( ! V_5 )
return - V_71 ;
#ifdef F_24
V_5 -> V_83 . V_119 = V_120 ;
V_5 -> V_83 . V_84 = 0x200 ;
V_5 -> V_83 . V_121 = 0x6 ;
V_5 -> V_83 . V_86 = 0x4 ;
V_5 -> V_83 . V_122 = 1 ;
V_5 -> V_83 . V_123 = V_5 -> V_83 . V_86 * V_5 -> V_83 . V_121 ;
V_5 -> V_83 . V_124 = F_32 ;
V_5 -> V_83 . V_125 = F_31 ;
#else
V_5 -> V_83 . V_119 = V_126 ;
V_5 -> V_83 . V_127 = V_128 ;
if ( F_19 ( V_32 ) < 0 )
F_45 ( & V_32 -> V_37 , L_23 ,
V_129 ) ;
#endif
F_46 ( V_5 , V_32 -> V_37 . V_130 ) ;
F_47 ( V_5 , V_7 ) ;
V_5 -> V_88 = F_39 ;
V_5 -> V_87 = F_38 ;
V_5 -> V_131 = F_35 ;
V_5 -> V_132 = F_42 ;
V_5 -> V_133 = F_36 ;
V_5 -> V_134 |= V_135 ;
V_5 -> V_136 = F_34 ;
V_5 -> V_137 = V_138 ;
V_5 -> V_139 = V_138 ;
V_3 = F_48 ( V_5 ) ;
F_49 ( & V_32 -> V_37 , V_3 ) ;
V_3 -> V_37 . V_140 = & V_32 -> V_37 ;
V_3 -> V_90 = 64 ;
#ifdef F_24
F_50 ( V_3 , & V_141 ) ;
#endif
if ( F_51 ( V_3 , 1 ) )
return - V_142 ;
return F_52 ( V_3 , NULL , 0 ) ;
}
static int F_53 ( struct V_16 * V_17 )
{
F_54 ( F_55 ( & V_17 -> V_37 ) ) ;
return 0 ;
}
