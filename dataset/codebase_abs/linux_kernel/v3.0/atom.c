static void F_1 ( int V_1 )
{
while ( V_1 -- )
F_2 ( L_1 ) ;
}
static T_1 F_3 ( struct V_2 * V_3 , int V_4 ,
T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_3 -> V_9 -> V_10 -> V_11 ;
T_1 V_12 = 0xCDCDCDCD ;
while ( 1 )
switch ( F_4 ( V_4 ) ) {
case V_13 :
V_4 ++ ;
break;
case V_14 :
V_12 = V_3 -> V_9 -> V_15 ( V_3 -> V_9 , F_5 ( V_4 + 1 ) ) ;
V_4 += 3 ;
break;
case V_16 :
if ( V_8 -> V_17 == V_18 )
( void ) V_3 -> V_9 -> V_15 ( V_3 -> V_9 , F_5 ( V_4 + 1 ) ) ;
V_3 -> V_9 -> V_19 ( V_3 -> V_9 , F_5 ( V_4 + 1 ) , V_12 ) ;
V_4 += 3 ;
break;
case V_20 :
V_12 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 2 ) ) ;
V_4 += 3 ;
break;
case V_21 :
V_12 |=
( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) << F_4 ( V_4 +
2 ) ;
V_4 += 3 ;
break;
case V_22 :
V_12 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 3 ) ) ;
V_12 |=
( ( V_5 >> F_4 ( V_4 + 2 ) ) &
( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) ) << F_4 ( V_4 +
3 ) ;
V_4 += 4 ;
break;
case V_23 :
V_12 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 3 ) ) ;
V_12 |=
( ( V_6 >> F_4 ( V_4 + 2 ) ) &
( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) ) << F_4 ( V_4 +
3 ) ;
V_4 += 4 ;
break;
case V_24 :
V_12 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 3 ) ) ;
V_12 |=
( ( V_3 ->
V_25 >> F_4 ( V_4 + 2 ) ) & ( 0xFFFFFFFF >> ( 32 -
F_4
( V_4
+
1 ) ) ) )
<< F_4 ( V_4 + 3 ) ;
V_4 += 4 ;
break;
case V_26 :
return V_12 ;
default:
F_2 ( V_27 L_2 ) ;
return 0 ;
}
}
static T_1 F_6 ( T_2 * V_3 , T_3 V_28 ,
int * V_29 , T_1 * V_30 , int V_31 )
{
T_1 V_32 , V_33 = 0xCDCDCDCD , V_34 , V_35 ;
struct V_2 * V_36 = V_3 -> V_3 ;
V_35 = V_28 & 7 ;
V_34 = ( V_28 >> 3 ) & 7 ;
switch ( V_35 ) {
case V_37 :
V_32 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
if ( V_31 )
F_8 ( L_3 , V_32 ) ;
V_32 += V_36 -> V_38 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_33 = V_36 -> V_9 -> V_41 ( V_36 -> V_9 , V_32 ) ;
break;
case V_42 :
F_2 ( V_27
L_4 ) ;
return 0 ;
case V_43 :
F_2 ( V_27
L_5 ) ;
return 0 ;
default:
if ( ! ( V_36 -> V_39 & 0x80 ) ) {
F_2 ( V_27 L_6 ) ;
return 0 ;
}
if ( ! V_36 -> V_44 [ V_36 -> V_39 & 0x7F ] ) {
F_2 ( V_27
L_7 ,
V_36 -> V_39 & 0x7F ) ;
return 0 ;
}
V_33 =
F_3 ( V_36 ,
V_36 -> V_44 [ V_36 -> V_39 & 0x7F ] ,
V_32 , 0 ) ;
}
break;
case V_45 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
V_33 = F_10 ( ( V_46 * ) & V_3 -> V_47 [ V_32 ] ) ;
if ( V_31 )
F_8 ( L_8 , V_32 , V_33 ) ;
break;
case V_48 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_9 , V_32 ) ;
switch ( V_32 ) {
case V_49 :
V_33 = V_36 -> V_50 [ 0 ] ;
break;
case V_51 :
V_33 = V_36 -> V_50 [ 1 ] ;
break;
case V_52 :
V_33 = V_36 -> V_53 ;
break;
case V_54 :
V_33 = V_36 -> V_55 ;
break;
case V_56 :
V_33 = 1 << V_36 -> V_55 ;
break;
case V_57 :
V_33 = ~ ( 1 << V_36 -> V_55 ) ;
break;
case V_58 :
V_33 = V_36 -> V_59 ;
break;
case V_60 :
V_33 = V_36 -> V_25 ;
break;
case V_61 :
V_33 = V_36 -> V_38 ;
break;
default:
V_33 = V_3 -> V_62 [ V_32 ] ;
}
break;
case V_63 :
V_32 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
if ( V_31 ) {
if ( V_36 -> V_53 )
F_8 ( L_10 , V_32 , V_36 -> V_53 ) ;
else
F_8 ( L_11 , V_32 ) ;
}
V_33 = F_11 ( V_32 + V_36 -> V_53 ) ;
break;
case V_64 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
V_33 = V_36 -> V_65 [ ( ( V_36 -> V_59 + V_32 ) / 4 ) ] ;
if ( V_31 )
F_8 ( L_12 , V_32 ) ;
break;
case V_66 :
switch ( V_34 ) {
case V_67 :
V_33 = F_11 ( * V_29 ) ;
( * V_29 ) += 4 ;
if ( V_31 )
F_8 ( L_13 , V_33 ) ;
return V_33 ;
case V_68 :
case V_69 :
case V_70 :
V_33 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
if ( V_31 )
F_8 ( L_14 , V_33 ) ;
return V_33 ;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_33 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_15 , V_33 ) ;
return V_33 ;
}
return 0 ;
case V_75 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_16 , V_32 ) ;
V_33 = V_36 -> V_9 -> V_76 ( V_36 -> V_9 , V_32 ) ;
break;
case V_77 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_17 , V_32 ) ;
V_33 = V_36 -> V_9 -> V_78 ( V_36 -> V_9 , V_32 ) ;
break;
}
if ( V_30 )
* V_30 = V_33 ;
V_33 &= V_79 [ V_34 ] ;
V_33 >>= V_80 [ V_34 ] ;
if ( V_31 )
switch ( V_34 ) {
case V_67 :
F_8 ( L_18 , V_33 ) ;
break;
case V_68 :
F_8 ( L_19 , V_33 ) ;
break;
case V_69 :
F_8 ( L_20 , V_33 ) ;
break;
case V_70 :
F_8 ( L_21 , V_33 ) ;
break;
case V_71 :
F_8 ( L_22 , V_33 ) ;
break;
case V_72 :
F_8 ( L_23 , V_33 ) ;
break;
case V_73 :
F_8 ( L_24 , V_33 ) ;
break;
case V_74 :
F_8 ( L_25 , V_33 ) ;
break;
}
return V_33 ;
}
static void F_12 ( T_2 * V_3 , T_3 V_28 , int * V_29 )
{
T_1 V_34 = ( V_28 >> 3 ) & 7 , V_35 = V_28 & 7 ;
switch ( V_35 ) {
case V_37 :
case V_63 :
( * V_29 ) += 2 ;
break;
case V_75 :
case V_77 :
case V_45 :
case V_48 :
case V_64 :
( * V_29 ) ++ ;
break;
case V_66 :
switch ( V_34 ) {
case V_67 :
( * V_29 ) += 4 ;
return;
case V_68 :
case V_69 :
case V_70 :
( * V_29 ) += 2 ;
return;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
( * V_29 ) ++ ;
return;
}
return;
}
}
static T_1 F_13 ( T_2 * V_3 , T_3 V_28 , int * V_29 )
{
return F_6 ( V_3 , V_28 , V_29 , NULL , 1 ) ;
}
static T_1 F_14 ( T_2 * V_3 , T_3 V_34 , int * V_29 )
{
T_1 V_33 = 0xCDCDCDCD ;
switch ( V_34 ) {
case V_67 :
V_33 = F_11 ( * V_29 ) ;
( * V_29 ) += 4 ;
break;
case V_68 :
case V_69 :
case V_70 :
V_33 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_33 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
break;
}
return V_33 ;
}
static T_1 F_15 ( T_2 * V_3 , int V_35 , T_3 V_28 ,
int * V_29 , T_1 * V_30 , int V_31 )
{
return F_6 ( V_3 ,
V_35 | V_81 [ ( V_28 >> 3 ) &
7 ] [ ( V_28 >> 6 ) & 3 ] << 3 ,
V_29 , V_30 , V_31 ) ;
}
static void F_16 ( T_2 * V_3 , int V_35 , T_3 V_28 , int * V_29 )
{
F_12 ( V_3 ,
V_35 | V_81 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) &
3 ] << 3 , V_29 ) ;
}
static void F_17 ( T_2 * V_3 , int V_35 , T_3 V_28 ,
int * V_29 , T_1 V_33 , T_1 V_30 )
{
T_1 V_34 =
V_81 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) & 3 ] , V_82 =
V_33 , V_32 ;
struct V_2 * V_36 = V_3 -> V_3 ;
V_82 &= V_79 [ V_34 ] >> V_80 [ V_34 ] ;
V_33 <<= V_80 [ V_34 ] ;
V_33 &= V_79 [ V_34 ] ;
V_30 &= ~ V_79 [ V_34 ] ;
V_33 |= V_30 ;
switch ( V_35 ) {
case V_37 :
V_32 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
F_8 ( L_3 , V_32 ) ;
V_32 += V_36 -> V_38 ;
switch ( V_36 -> V_39 ) {
case V_40 :
if ( V_32 == 0 )
V_36 -> V_9 -> V_83 ( V_36 -> V_9 , V_32 ,
V_33 << 2 ) ;
else
V_36 -> V_9 -> V_83 ( V_36 -> V_9 , V_32 , V_33 ) ;
break;
case V_42 :
F_2 ( V_27
L_4 ) ;
return;
case V_43 :
F_2 ( V_27
L_5 ) ;
return;
default:
if ( ! ( V_36 -> V_39 & 0x80 ) ) {
F_2 ( V_27 L_6 ) ;
return;
}
if ( ! V_36 -> V_44 [ V_36 -> V_39 & 0xFF ] ) {
F_2 ( V_27
L_26 ,
V_36 -> V_39 & 0x7F ) ;
return;
}
F_3 ( V_36 , V_36 -> V_44 [ V_36 -> V_39 & 0xFF ] ,
V_32 , V_33 ) ;
}
break;
case V_45 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_8 ( L_27 , V_32 ) ;
V_3 -> V_47 [ V_32 ] = F_18 ( V_33 ) ;
break;
case V_48 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_8 ( L_9 , V_32 ) ;
switch ( V_32 ) {
case V_49 :
V_36 -> V_50 [ 0 ] = V_33 ;
break;
case V_51 :
V_36 -> V_50 [ 1 ] = V_33 ;
break;
case V_52 :
V_36 -> V_53 = V_33 ;
break;
case V_54 :
V_36 -> V_55 = V_33 ;
break;
case V_56 :
case V_57 :
break;
case V_58 :
V_36 -> V_59 = V_33 ;
break;
case V_60 :
V_36 -> V_25 = V_33 ;
break;
case V_61 :
V_36 -> V_38 = V_33 ;
break;
default:
V_3 -> V_62 [ V_32 ] = V_33 ;
}
break;
case V_64 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
V_36 -> V_65 [ ( ( V_36 -> V_59 + V_32 ) / 4 ) ] = V_33 ;
F_8 ( L_12 , V_32 ) ;
break;
case V_75 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_8 ( L_16 , V_32 ) ;
V_36 -> V_9 -> V_84 ( V_36 -> V_9 , V_32 , V_33 ) ;
break;
case V_77 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_8 ( L_17 , V_32 ) ;
V_36 -> V_9 -> V_85 ( V_36 -> V_9 , V_32 , V_33 ) ;
return;
}
switch ( V_34 ) {
case V_67 :
F_8 ( L_28 , V_82 ) ;
break;
case V_68 :
F_8 ( L_29 , V_82 ) ;
break;
case V_69 :
F_8 ( L_30 , V_82 ) ;
break;
case V_70 :
F_8 ( L_31 , V_82 ) ;
break;
case V_71 :
F_8 ( L_32 , V_82 ) ;
break;
case V_72 :
F_8 ( L_33 , V_82 ) ;
break;
case V_73 :
F_8 ( L_34 , V_82 ) ;
break;
case V_74 :
F_8 ( L_35 , V_82 ) ;
break;
}
}
static void F_19 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 , V_30 ;
int V_88 = * V_29 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_86 += V_87 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_21 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 , V_30 ;
int V_88 = * V_29 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_86 &= V_87 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_22 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( L_38 ) ;
}
static void F_23 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_32 = F_9 ( ( * V_29 ) ++ ) ;
int V_89 = 0 ;
if ( V_32 < V_90 )
F_20 ( L_39 , V_32 , V_91 [ V_32 ] ) ;
else
F_20 ( L_40 , V_32 ) ;
if ( F_7 ( V_3 -> V_3 -> V_92 + 4 + 2 * V_32 ) )
V_89 = F_24 ( V_3 -> V_3 , V_32 , V_3 -> V_47 + V_3 -> V_93 ) ;
if ( V_89 ) {
V_3 -> abort = true ;
}
}
static void F_25 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_30 ;
int V_88 = * V_29 ;
V_28 &= 0x38 ;
V_28 |= V_94 [ V_28 >> 3 ] << 6 ;
F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 0 ) ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , 0 , V_30 ) ;
}
static void F_26 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 ;
F_20 ( L_41 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_20 ( L_42 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_3 -> V_3 -> V_95 = ( V_86 == V_87 ) ;
V_3 -> V_3 -> V_96 = ( V_86 > V_87 ) ;
F_20 ( L_43 , V_3 -> V_3 -> V_95 ? L_44 : L_45 ,
V_3 -> V_3 -> V_96 ? L_46 : L_47 ) ;
}
static void F_27 ( T_2 * V_3 , int * V_29 , int V_35 )
{
unsigned V_97 = F_9 ( ( * V_29 ) ++ ) ;
F_20 ( L_48 , V_97 ) ;
if ( V_35 == V_98 )
F_28 ( V_97 ) ;
else
F_29 ( V_97 ) ;
}
static void F_30 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 ;
F_20 ( L_41 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_20 ( L_42 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
if ( V_87 != 0 ) {
V_3 -> V_3 -> V_50 [ 0 ] = V_86 / V_87 ;
V_3 -> V_3 -> V_50 [ 1 ] = V_86 % V_87 ;
} else {
V_3 -> V_3 -> V_50 [ 0 ] = 0 ;
V_3 -> V_3 -> V_50 [ 1 ] = 0 ;
}
}
static void F_31 ( T_2 * V_3 , int * V_29 , int V_35 )
{
}
static void F_32 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_99 = 0 , V_100 = F_7 ( * V_29 ) ;
unsigned long V_101 ;
( * V_29 ) += 2 ;
switch ( V_35 ) {
case V_102 :
V_99 = V_3 -> V_3 -> V_96 ;
break;
case V_103 :
V_99 = V_3 -> V_3 -> V_96 || V_3 -> V_3 -> V_95 ;
break;
case V_104 :
V_99 = 1 ;
break;
case V_105 :
V_99 = ! ( V_3 -> V_3 -> V_96 || V_3 -> V_3 -> V_95 ) ;
break;
case V_106 :
V_99 = ! V_3 -> V_3 -> V_96 ;
break;
case V_107 :
V_99 = V_3 -> V_3 -> V_95 ;
break;
case V_108 :
V_99 = ! V_3 -> V_3 -> V_95 ;
break;
}
if ( V_35 != V_104 )
F_20 ( L_49 , V_99 ? L_50 : L_51 ) ;
F_20 ( L_52 , V_100 ) ;
if ( V_99 ) {
if ( V_3 -> V_109 == ( V_3 -> V_110 + V_100 ) ) {
V_101 = V_111 ;
if ( F_33 ( V_101 , V_3 -> V_112 ) ) {
V_101 -= V_3 -> V_112 ;
if ( ( F_34 ( V_101 ) > 5000 ) ) {
F_35 ( L_53 ) ;
V_3 -> abort = true ;
}
} else {
V_3 -> V_112 = V_111 ;
}
} else {
V_3 -> V_109 = V_3 -> V_110 + V_100 ;
V_3 -> V_112 = V_111 ;
}
* V_29 = V_3 -> V_110 + V_100 ;
}
}
static void F_36 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_113 , V_87 , V_30 ;
int V_88 = * V_29 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_113 = F_14 ( V_3 , ( ( V_28 >> 3 ) & 7 ) , V_29 ) ;
F_20 ( L_54 , V_113 ) ;
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_86 &= V_113 ;
V_86 |= V_87 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_37 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_30 ;
int V_88 = * V_29 ;
if ( ( ( V_28 >> 3 ) & 7 ) != V_67 )
F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 0 ) ;
else {
F_16 ( V_3 , V_35 , V_28 , V_29 ) ;
V_30 = 0xCDCDCDCD ;
}
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_87 , V_30 ) ;
}
static void F_38 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 ;
F_20 ( L_41 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_20 ( L_42 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_3 -> V_3 -> V_50 [ 0 ] = V_86 * V_87 ;
}
static void F_39 ( T_2 * V_3 , int * V_29 , int V_35 )
{
}
static void F_40 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 , V_30 ;
int V_88 = * V_29 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_86 |= V_87 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_41 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_33 = F_9 ( ( * V_29 ) ++ ) ;
F_20 ( L_55 , V_33 ) ;
}
static void F_42 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_56 ) ;
}
static void F_43 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_56 ) ;
}
static void F_44 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_56 ) ;
}
static void F_45 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_20 ( L_57 , V_32 ) ;
if ( ! V_32 )
V_3 -> V_3 -> V_53 = 0 ;
else if ( V_32 == 255 )
V_3 -> V_3 -> V_53 = V_3 -> V_110 ;
else
V_3 -> V_3 -> V_53 = F_7 ( V_3 -> V_3 -> V_114 + 4 + 2 * V_32 ) ;
F_20 ( L_58 , V_3 -> V_3 -> V_53 ) ;
}
static void F_46 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
F_20 ( L_59 ) ;
V_3 -> V_3 -> V_59 = F_13 ( V_3 , V_28 , V_29 ) ;
}
static void F_47 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_115 ;
switch ( V_35 ) {
case V_116 :
V_115 = F_7 ( * V_29 ) ;
if ( V_115 < V_117 )
F_20 ( L_60 , V_115 , V_118 [ V_115 ] ) ;
else
F_20 ( L_61 , V_115 ) ;
if ( ! V_115 )
V_3 -> V_3 -> V_39 = V_40 ;
else
V_3 -> V_3 -> V_39 = V_119 | V_115 ;
( * V_29 ) += 2 ;
break;
case V_120 :
V_3 -> V_3 -> V_39 = V_42 ;
( * V_29 ) ++ ;
break;
case V_121 :
V_3 -> V_3 -> V_39 = V_43 ;
( * V_29 ) ++ ;
break;
}
}
static void F_48 ( T_2 * V_3 , int * V_29 , int V_35 )
{
V_3 -> V_3 -> V_38 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
F_20 ( L_58 , V_3 -> V_3 -> V_38 ) ;
}
static void F_49 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_86 ;
int V_88 = * V_29 ;
V_28 &= 0x38 ;
V_28 |= V_94 [ V_28 >> 3 ] << 6 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_55 = F_14 ( V_3 , V_71 , V_29 ) ;
F_20 ( L_62 , V_55 ) ;
V_86 <<= V_55 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_50 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_86 ;
int V_88 = * V_29 ;
V_28 &= 0x38 ;
V_28 |= V_94 [ V_28 >> 3 ] << 6 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_55 = F_14 ( V_3 , V_71 , V_29 ) ;
F_20 ( L_62 , V_55 ) ;
V_86 >>= V_55 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_51 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_86 ;
int V_88 = * V_29 ;
T_1 V_122 = V_81 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) & 3 ] ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_86 = V_30 ;
V_55 = F_13 ( V_3 , V_28 , V_29 ) ;
F_20 ( L_62 , V_55 ) ;
V_86 <<= V_55 ;
V_86 &= V_79 [ V_122 ] ;
V_86 >>= V_80 [ V_122 ] ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_52 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_86 ;
int V_88 = * V_29 ;
T_1 V_122 = V_81 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) & 3 ] ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_86 = V_30 ;
V_55 = F_13 ( V_3 , V_28 , V_29 ) ;
F_20 ( L_62 , V_55 ) ;
V_86 >>= V_55 ;
V_86 &= V_79 [ V_122 ] ;
V_86 >>= V_80 [ V_122 ] ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_53 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 , V_30 ;
int V_88 = * V_29 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_86 -= V_87 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_54 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_33 , V_100 ;
F_20 ( L_63 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
while ( F_7 ( * V_29 ) != V_123 )
if ( F_9 ( * V_29 ) == V_124 ) {
( * V_29 ) ++ ;
F_20 ( L_64 ) ;
V_33 =
F_13 ( V_3 , ( V_28 & 0x38 ) | V_66 ,
V_29 ) ;
V_100 = F_7 ( * V_29 ) ;
if ( V_33 == V_87 ) {
F_20 ( L_65 , V_100 ) ;
* V_29 = V_3 -> V_110 + V_100 ;
return;
}
( * V_29 ) += 2 ;
} else {
F_2 ( V_27 L_66 ) ;
return;
}
( * V_29 ) += 2 ;
}
static void F_55 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 ;
F_20 ( L_41 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_20 ( L_42 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_3 -> V_3 -> V_95 = ( ( V_86 & V_87 ) == 0 ) ;
F_20 ( L_67 , V_3 -> V_3 -> V_95 ? L_44 : L_45 ) ;
}
static void F_56 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_86 , V_87 , V_30 ;
int V_88 = * V_29 ;
F_20 ( L_36 ) ;
V_86 = F_15 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_20 ( L_37 ) ;
V_87 = F_13 ( V_3 , V_28 , V_29 ) ;
V_86 ^= V_87 ;
F_20 ( L_36 ) ;
F_17 ( V_3 , V_35 , V_28 , & V_88 , V_86 , V_30 ) ;
}
static void F_57 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_56 ) ;
}
static int F_24 ( struct V_2 * V_3 , int V_5 , T_1 * V_125 )
{
int V_4 = F_5 ( V_3 -> V_92 + 4 + 2 * V_5 ) ;
int V_126 , V_62 , V_47 , V_29 ;
unsigned char V_127 ;
T_2 V_128 ;
int V_129 = 0 ;
if ( ! V_4 )
return - V_130 ;
V_126 = F_5 ( V_4 + V_131 ) ;
V_62 = F_4 ( V_4 + V_132 ) ;
V_47 = F_4 ( V_4 + V_133 ) & V_134 ;
V_29 = V_4 + V_135 ;
F_20 ( L_68 , V_4 , V_126 , V_62 , V_47 ) ;
V_128 . V_3 = V_3 ;
V_128 . V_93 = V_47 / 4 ;
V_128 . V_110 = V_4 ;
V_128 . V_47 = V_125 ;
V_128 . abort = false ;
V_128 . V_109 = 0 ;
if ( V_62 )
V_128 . V_62 = F_58 ( 4 * V_62 , V_136 ) ;
else
V_128 . V_62 = NULL ;
V_137 ++ ;
while ( 1 ) {
V_127 = F_4 ( V_29 ++ ) ;
if ( V_127 < V_138 )
F_20 ( L_69 , V_139 [ V_127 ] , V_29 - 1 ) ;
else
F_20 ( L_70 , V_127 , V_29 - 1 ) ;
if ( V_128 . abort ) {
F_35 ( L_71 ,
V_4 , V_126 , V_62 , V_47 , V_29 - 1 ) ;
V_129 = - V_130 ;
goto free;
}
if ( V_127 < V_140 && V_127 > 0 )
V_141 [ V_127 ] . F_59 ( & V_128 , & V_29 ,
V_141 [ V_127 ] . V_35 ) ;
else
break;
if ( V_127 == V_142 )
break;
}
V_137 -- ;
F_20 ( L_72 ) ;
free:
if ( V_62 )
F_60 ( V_128 . V_62 ) ;
return V_129 ;
}
int F_61 ( struct V_2 * V_3 , int V_5 , T_1 * V_125 )
{
int V_89 ;
F_62 ( & V_3 -> V_143 ) ;
V_3 -> V_38 = 0 ;
V_3 -> V_59 = 0 ;
V_3 -> V_39 = V_40 ;
V_89 = F_24 ( V_3 , V_5 , V_125 ) ;
F_63 ( & V_3 -> V_143 ) ;
return V_89 ;
}
static void F_64 ( struct V_2 * V_3 , int V_4 )
{
V_3 -> V_44 = F_58 ( 2 * 256 , V_136 ) ;
while ( F_4 ( V_4 ) == V_144 ) {
V_3 -> V_44 [ F_4 ( V_4 + 1 ) ] = V_4 + 2 ;
V_4 += 2 ;
while ( F_4 ( V_4 ) != V_26 )
V_4 += V_145 [ F_4 ( V_4 ) ] ;
V_4 += 3 ;
}
}
struct V_2 * F_65 ( struct V_146 * V_9 , void * V_147 )
{
int V_4 ;
struct V_2 * V_3 =
F_58 ( sizeof( struct V_2 ) , V_136 ) ;
char * V_148 ;
char V_149 [ 512 ] ;
int V_150 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_147 = V_147 ;
if ( F_5 ( 0 ) != V_151 ) {
F_2 ( V_27 L_73 ) ;
F_60 ( V_3 ) ;
return NULL ;
}
if ( strncmp
( F_66 ( V_152 ) , V_153 ,
strlen ( V_153 ) ) ) {
F_2 ( V_27 L_74 ) ;
F_60 ( V_3 ) ;
return NULL ;
}
V_4 = F_5 ( V_154 ) ;
if ( strncmp
( F_66 ( V_4 + V_155 ) , V_156 ,
strlen ( V_156 ) ) ) {
F_2 ( V_27 L_75 ) ;
F_60 ( V_3 ) ;
return NULL ;
}
V_3 -> V_92 = F_5 ( V_4 + V_157 ) ;
V_3 -> V_114 = F_5 ( V_4 + V_158 ) ;
F_64 ( V_3 , F_5 ( V_3 -> V_114 + V_159 ) + 4 ) ;
V_148 = F_66 ( F_5 ( V_4 + V_160 ) ) ;
while ( * V_148 && ( ( * V_148 == '\n' ) || ( * V_148 == '\r' ) ) )
V_148 ++ ;
for ( V_150 = 0 ; V_150 < 511 ; V_150 ++ ) {
V_149 [ V_150 ] = V_148 [ V_150 ] ;
if ( V_149 [ V_150 ] < '.' || V_149 [ V_150 ] > 'z' ) {
V_149 [ V_150 ] = 0 ;
break;
}
}
F_2 ( V_27 L_76 , V_149 ) ;
return V_3 ;
}
int F_67 ( struct V_2 * V_3 )
{
int V_161 = F_5 ( V_3 -> V_114 + V_162 ) ;
T_1 V_47 [ 16 ] ;
memset ( V_47 , 0 , 64 ) ;
V_47 [ 0 ] = F_18 ( F_68 ( V_161 + V_163 ) ) ;
V_47 [ 1 ] = F_18 ( F_68 ( V_161 + V_164 ) ) ;
if ( ! V_47 [ 0 ] || ! V_47 [ 1 ] )
return 1 ;
if ( ! F_5 ( V_3 -> V_92 + 4 + 2 * V_165 ) )
return 1 ;
return F_61 ( V_3 , V_165 , V_47 ) ;
}
void F_69 ( struct V_2 * V_3 )
{
if ( V_3 -> V_44 )
F_60 ( V_3 -> V_44 ) ;
F_60 ( V_3 ) ;
}
bool F_70 ( struct V_2 * V_3 , int V_5 ,
T_4 * V_166 , T_3 * V_167 , T_3 * V_168 ,
T_4 * V_169 )
{
int V_170 = V_5 * 2 + 4 ;
int V_32 = F_5 ( V_3 -> V_114 + V_170 ) ;
T_5 * V_171 = ( T_5 * ) ( V_3 -> V_147 + V_3 -> V_114 + 4 ) ;
if ( ! V_171 [ V_5 ] )
return false ;
if ( V_166 )
* V_166 = F_5 ( V_32 ) ;
if ( V_167 )
* V_167 = F_4 ( V_32 + 2 ) ;
if ( V_168 )
* V_168 = F_4 ( V_32 + 3 ) ;
* V_169 = V_32 ;
return true ;
}
bool F_71 ( struct V_2 * V_3 , int V_5 , T_3 * V_167 ,
T_3 * V_168 )
{
int V_170 = V_5 * 2 + 4 ;
int V_32 = F_5 ( V_3 -> V_92 + V_170 ) ;
T_5 * V_172 = ( T_5 * ) ( V_3 -> V_147 + V_3 -> V_92 + 4 ) ;
if ( ! V_172 [ V_5 ] )
return false ;
if ( V_167 )
* V_167 = F_4 ( V_32 + 2 ) ;
if ( V_168 )
* V_168 = F_4 ( V_32 + 3 ) ;
return true ;
}
int F_72 ( struct V_2 * V_3 )
{
int V_5 = F_73 ( V_173 , V_174 ) ;
T_4 V_175 ;
int V_176 = 0 ;
struct V_177 * V_178 ;
if ( F_70 ( V_3 , V_5 , NULL , NULL , NULL , & V_175 ) ) {
V_178 = (struct V_177 * ) ( V_3 -> V_147 + V_175 ) ;
F_74 ( L_77 ,
V_178 -> V_179 [ 0 ] . V_180 ,
V_178 -> V_179 [ 0 ] . V_181 ) ;
V_176 = V_178 -> V_179 [ 0 ] . V_181 * 1024 ;
}
if ( V_176 == 0 )
V_176 = 20 * 1024 ;
V_3 -> V_65 = F_58 ( V_176 , V_136 ) ;
if ( ! V_3 -> V_65 )
return - V_182 ;
return 0 ;
}
