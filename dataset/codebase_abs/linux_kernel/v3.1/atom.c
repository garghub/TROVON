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
if ( ( V_36 -> V_59 + ( V_32 * 4 ) ) > V_36 -> V_65 ) {
F_12 ( L_12 ,
V_36 -> V_59 + ( V_32 * 4 ) , V_36 -> V_65 ) ;
V_33 = 0 ;
} else
V_33 = V_36 -> V_66 [ ( V_36 -> V_59 / 4 ) + V_32 ] ;
if ( V_31 )
F_8 ( L_13 , V_32 ) ;
break;
case V_67 :
switch ( V_34 ) {
case V_68 :
V_33 = F_11 ( * V_29 ) ;
( * V_29 ) += 4 ;
if ( V_31 )
F_8 ( L_14 , V_33 ) ;
return V_33 ;
case V_69 :
case V_70 :
case V_71 :
V_33 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
if ( V_31 )
F_8 ( L_15 , V_33 ) ;
return V_33 ;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_33 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_16 , V_33 ) ;
return V_33 ;
}
return 0 ;
case V_76 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_17 , V_32 ) ;
V_33 = V_36 -> V_9 -> V_77 ( V_36 -> V_9 , V_32 ) ;
break;
case V_78 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
if ( V_31 )
F_8 ( L_18 , V_32 ) ;
V_33 = V_36 -> V_9 -> V_79 ( V_36 -> V_9 , V_32 ) ;
break;
}
if ( V_30 )
* V_30 = V_33 ;
V_33 &= V_80 [ V_34 ] ;
V_33 >>= V_81 [ V_34 ] ;
if ( V_31 )
switch ( V_34 ) {
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
case V_75 :
F_8 ( L_26 , V_33 ) ;
break;
}
return V_33 ;
}
static void F_13 ( T_2 * V_3 , T_3 V_28 , int * V_29 )
{
T_1 V_34 = ( V_28 >> 3 ) & 7 , V_35 = V_28 & 7 ;
switch ( V_35 ) {
case V_37 :
case V_63 :
( * V_29 ) += 2 ;
break;
case V_76 :
case V_78 :
case V_45 :
case V_48 :
case V_64 :
( * V_29 ) ++ ;
break;
case V_67 :
switch ( V_34 ) {
case V_68 :
( * V_29 ) += 4 ;
return;
case V_69 :
case V_70 :
case V_71 :
( * V_29 ) += 2 ;
return;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
( * V_29 ) ++ ;
return;
}
return;
}
}
static T_1 F_14 ( T_2 * V_3 , T_3 V_28 , int * V_29 )
{
return F_6 ( V_3 , V_28 , V_29 , NULL , 1 ) ;
}
static T_1 F_15 ( T_2 * V_3 , T_3 V_34 , int * V_29 )
{
T_1 V_33 = 0xCDCDCDCD ;
switch ( V_34 ) {
case V_68 :
V_33 = F_11 ( * V_29 ) ;
( * V_29 ) += 4 ;
break;
case V_69 :
case V_70 :
case V_71 :
V_33 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_33 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
break;
}
return V_33 ;
}
static T_1 F_16 ( T_2 * V_3 , int V_35 , T_3 V_28 ,
int * V_29 , T_1 * V_30 , int V_31 )
{
return F_6 ( V_3 ,
V_35 | V_82 [ ( V_28 >> 3 ) &
7 ] [ ( V_28 >> 6 ) & 3 ] << 3 ,
V_29 , V_30 , V_31 ) ;
}
static void F_17 ( T_2 * V_3 , int V_35 , T_3 V_28 , int * V_29 )
{
F_13 ( V_3 ,
V_35 | V_82 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) &
3 ] << 3 , V_29 ) ;
}
static void F_18 ( T_2 * V_3 , int V_35 , T_3 V_28 ,
int * V_29 , T_1 V_33 , T_1 V_30 )
{
T_1 V_34 =
V_82 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) & 3 ] , V_83 =
V_33 , V_32 ;
struct V_2 * V_36 = V_3 -> V_3 ;
V_83 &= V_80 [ V_34 ] >> V_81 [ V_34 ] ;
V_33 <<= V_81 [ V_34 ] ;
V_33 &= V_80 [ V_34 ] ;
V_30 &= ~ V_80 [ V_34 ] ;
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
V_36 -> V_9 -> V_84 ( V_36 -> V_9 , V_32 ,
V_33 << 2 ) ;
else
V_36 -> V_9 -> V_84 ( V_36 -> V_9 , V_32 , V_33 ) ;
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
L_27 ,
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
F_8 ( L_28 , V_32 ) ;
V_3 -> V_47 [ V_32 ] = F_19 ( V_33 ) ;
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
if ( ( V_36 -> V_59 + ( V_32 * 4 ) ) > V_36 -> V_65 ) {
F_12 ( L_29 ,
V_36 -> V_59 + ( V_32 * 4 ) , V_36 -> V_65 ) ;
} else
V_36 -> V_66 [ ( V_36 -> V_59 / 4 ) + V_32 ] = V_33 ;
F_8 ( L_13 , V_32 ) ;
break;
case V_76 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_8 ( L_17 , V_32 ) ;
V_36 -> V_9 -> V_85 ( V_36 -> V_9 , V_32 , V_33 ) ;
break;
case V_78 :
V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_8 ( L_18 , V_32 ) ;
V_36 -> V_9 -> V_86 ( V_36 -> V_9 , V_32 , V_33 ) ;
return;
}
switch ( V_34 ) {
case V_68 :
F_8 ( L_30 , V_83 ) ;
break;
case V_69 :
F_8 ( L_31 , V_83 ) ;
break;
case V_70 :
F_8 ( L_32 , V_83 ) ;
break;
case V_71 :
F_8 ( L_33 , V_83 ) ;
break;
case V_72 :
F_8 ( L_34 , V_83 ) ;
break;
case V_73 :
F_8 ( L_35 , V_83 ) ;
break;
case V_74 :
F_8 ( L_36 , V_83 ) ;
break;
case V_75 :
F_8 ( L_37 , V_83 ) ;
break;
}
}
static void F_20 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 , V_30 ;
int V_89 = * V_29 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_87 += V_88 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_22 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 , V_30 ;
int V_89 = * V_29 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_87 &= V_88 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_23 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( L_40 ) ;
}
static void F_24 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_32 = F_9 ( ( * V_29 ) ++ ) ;
int V_90 = 0 ;
if ( V_32 < V_91 )
F_21 ( L_41 , V_32 , V_92 [ V_32 ] ) ;
else
F_21 ( L_42 , V_32 ) ;
if ( F_7 ( V_3 -> V_3 -> V_93 + 4 + 2 * V_32 ) )
V_90 = F_25 ( V_3 -> V_3 , V_32 , V_3 -> V_47 + V_3 -> V_94 ) ;
if ( V_90 ) {
V_3 -> abort = true ;
}
}
static void F_26 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_30 ;
int V_89 = * V_29 ;
V_28 &= 0x38 ;
V_28 |= V_95 [ V_28 >> 3 ] << 6 ;
F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 0 ) ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , 0 , V_30 ) ;
}
static void F_27 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 ;
F_21 ( L_43 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_3 -> V_3 -> V_96 = ( V_87 == V_88 ) ;
V_3 -> V_3 -> V_97 = ( V_87 > V_88 ) ;
F_21 ( L_45 , V_3 -> V_3 -> V_96 ? L_46 : L_47 ,
V_3 -> V_3 -> V_97 ? L_48 : L_49 ) ;
}
static void F_28 ( T_2 * V_3 , int * V_29 , int V_35 )
{
unsigned V_98 = F_9 ( ( * V_29 ) ++ ) ;
F_21 ( L_50 , V_98 ) ;
if ( V_35 == V_99 )
F_29 ( V_98 ) ;
else
F_30 ( V_98 ) ;
}
static void F_31 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 ;
F_21 ( L_43 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
if ( V_88 != 0 ) {
V_3 -> V_3 -> V_50 [ 0 ] = V_87 / V_88 ;
V_3 -> V_3 -> V_50 [ 1 ] = V_87 % V_88 ;
} else {
V_3 -> V_3 -> V_50 [ 0 ] = 0 ;
V_3 -> V_3 -> V_50 [ 1 ] = 0 ;
}
}
static void F_32 ( T_2 * V_3 , int * V_29 , int V_35 )
{
}
static void F_33 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_100 = 0 , V_101 = F_7 ( * V_29 ) ;
unsigned long V_102 ;
( * V_29 ) += 2 ;
switch ( V_35 ) {
case V_103 :
V_100 = V_3 -> V_3 -> V_97 ;
break;
case V_104 :
V_100 = V_3 -> V_3 -> V_97 || V_3 -> V_3 -> V_96 ;
break;
case V_105 :
V_100 = 1 ;
break;
case V_106 :
V_100 = ! ( V_3 -> V_3 -> V_97 || V_3 -> V_3 -> V_96 ) ;
break;
case V_107 :
V_100 = ! V_3 -> V_3 -> V_97 ;
break;
case V_108 :
V_100 = V_3 -> V_3 -> V_96 ;
break;
case V_109 :
V_100 = ! V_3 -> V_3 -> V_96 ;
break;
}
if ( V_35 != V_105 )
F_21 ( L_51 , V_100 ? L_52 : L_53 ) ;
F_21 ( L_54 , V_101 ) ;
if ( V_100 ) {
if ( V_3 -> V_110 == ( V_3 -> V_111 + V_101 ) ) {
V_102 = V_112 ;
if ( F_34 ( V_102 , V_3 -> V_113 ) ) {
V_102 -= V_3 -> V_113 ;
if ( ( F_35 ( V_102 ) > 5000 ) ) {
F_12 ( L_55 ) ;
V_3 -> abort = true ;
}
} else {
V_3 -> V_113 = V_112 ;
}
} else {
V_3 -> V_110 = V_3 -> V_111 + V_101 ;
V_3 -> V_113 = V_112 ;
}
* V_29 = V_3 -> V_111 + V_101 ;
}
}
static void F_36 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_114 , V_88 , V_30 ;
int V_89 = * V_29 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_114 = F_15 ( V_3 , ( ( V_28 >> 3 ) & 7 ) , V_29 ) ;
F_21 ( L_56 , V_114 ) ;
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_87 &= V_114 ;
V_87 |= V_88 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_37 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_88 , V_30 ;
int V_89 = * V_29 ;
if ( ( ( V_28 >> 3 ) & 7 ) != V_68 )
F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 0 ) ;
else {
F_17 ( V_3 , V_35 , V_28 , V_29 ) ;
V_30 = 0xCDCDCDCD ;
}
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_88 , V_30 ) ;
}
static void F_38 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 ;
F_21 ( L_43 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_3 -> V_3 -> V_50 [ 0 ] = V_87 * V_88 ;
}
static void F_39 ( T_2 * V_3 , int * V_29 , int V_35 )
{
}
static void F_40 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 , V_30 ;
int V_89 = * V_29 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_87 |= V_88 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_41 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_33 = F_9 ( ( * V_29 ) ++ ) ;
F_21 ( L_57 , V_33 ) ;
}
static void F_42 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_58 ) ;
}
static void F_43 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_58 ) ;
}
static void F_44 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_58 ) ;
}
static void F_45 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_32 = F_9 ( * V_29 ) ;
( * V_29 ) ++ ;
F_21 ( L_59 , V_32 ) ;
if ( ! V_32 )
V_3 -> V_3 -> V_53 = 0 ;
else if ( V_32 == 255 )
V_3 -> V_3 -> V_53 = V_3 -> V_111 ;
else
V_3 -> V_3 -> V_53 = F_7 ( V_3 -> V_3 -> V_115 + 4 + 2 * V_32 ) ;
F_21 ( L_60 , V_3 -> V_3 -> V_53 ) ;
}
static void F_46 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
F_21 ( L_61 ) ;
V_3 -> V_3 -> V_59 = F_14 ( V_3 , V_28 , V_29 ) ;
}
static void F_47 ( T_2 * V_3 , int * V_29 , int V_35 )
{
int V_116 ;
switch ( V_35 ) {
case V_117 :
V_116 = F_7 ( * V_29 ) ;
if ( V_116 < V_118 )
F_21 ( L_62 , V_116 , V_119 [ V_116 ] ) ;
else
F_21 ( L_63 , V_116 ) ;
if ( ! V_116 )
V_3 -> V_3 -> V_39 = V_40 ;
else
V_3 -> V_3 -> V_39 = V_120 | V_116 ;
( * V_29 ) += 2 ;
break;
case V_121 :
V_3 -> V_3 -> V_39 = V_42 ;
( * V_29 ) ++ ;
break;
case V_122 :
V_3 -> V_3 -> V_39 = V_43 ;
( * V_29 ) ++ ;
break;
}
}
static void F_48 ( T_2 * V_3 , int * V_29 , int V_35 )
{
V_3 -> V_3 -> V_38 = F_7 ( * V_29 ) ;
( * V_29 ) += 2 ;
F_21 ( L_60 , V_3 -> V_3 -> V_38 ) ;
}
static void F_49 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_87 ;
int V_89 = * V_29 ;
V_28 &= 0x38 ;
V_28 |= V_95 [ V_28 >> 3 ] << 6 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_55 = F_15 ( V_3 , V_72 , V_29 ) ;
F_21 ( L_64 , V_55 ) ;
V_87 <<= V_55 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_50 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_87 ;
int V_89 = * V_29 ;
V_28 &= 0x38 ;
V_28 |= V_95 [ V_28 >> 3 ] << 6 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_55 = F_15 ( V_3 , V_72 , V_29 ) ;
F_21 ( L_64 , V_55 ) ;
V_87 >>= V_55 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_51 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_87 ;
int V_89 = * V_29 ;
T_1 V_123 = V_82 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) & 3 ] ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_87 = V_30 ;
V_55 = F_14 ( V_3 , V_28 , V_29 ) ;
F_21 ( L_64 , V_55 ) ;
V_87 <<= V_55 ;
V_87 &= V_80 [ V_123 ] ;
V_87 >>= V_81 [ V_123 ] ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_52 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) , V_55 ;
T_1 V_30 , V_87 ;
int V_89 = * V_29 ;
T_1 V_123 = V_82 [ ( V_28 >> 3 ) & 7 ] [ ( V_28 >> 6 ) & 3 ] ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
V_87 = V_30 ;
V_55 = F_14 ( V_3 , V_28 , V_29 ) ;
F_21 ( L_64 , V_55 ) ;
V_87 >>= V_55 ;
V_87 &= V_80 [ V_123 ] ;
V_87 >>= V_81 [ V_123 ] ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_53 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 , V_30 ;
int V_89 = * V_29 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_87 -= V_88 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_54 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_88 , V_33 , V_101 ;
F_21 ( L_65 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
while ( F_7 ( * V_29 ) != V_124 )
if ( F_9 ( * V_29 ) == V_125 ) {
( * V_29 ) ++ ;
F_21 ( L_66 ) ;
V_33 =
F_14 ( V_3 , ( V_28 & 0x38 ) | V_67 ,
V_29 ) ;
V_101 = F_7 ( * V_29 ) ;
if ( V_33 == V_88 ) {
F_21 ( L_67 , V_101 ) ;
* V_29 = V_3 -> V_111 + V_101 ;
return;
}
( * V_29 ) += 2 ;
} else {
F_2 ( V_27 L_68 ) ;
return;
}
( * V_29 ) += 2 ;
}
static void F_55 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 ;
F_21 ( L_43 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_3 -> V_3 -> V_96 = ( ( V_87 & V_88 ) == 0 ) ;
F_21 ( L_69 , V_3 -> V_3 -> V_96 ? L_46 : L_47 ) ;
}
static void F_56 ( T_2 * V_3 , int * V_29 , int V_35 )
{
T_3 V_28 = F_9 ( ( * V_29 ) ++ ) ;
T_1 V_87 , V_88 , V_30 ;
int V_89 = * V_29 ;
F_21 ( L_38 ) ;
V_87 = F_16 ( V_3 , V_35 , V_28 , V_29 , & V_30 , 1 ) ;
F_21 ( L_39 ) ;
V_88 = F_14 ( V_3 , V_28 , V_29 ) ;
V_87 ^= V_88 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_35 , V_28 , & V_89 , V_87 , V_30 ) ;
}
static void F_57 ( T_2 * V_3 , int * V_29 , int V_35 )
{
F_2 ( V_27 L_58 ) ;
}
static int F_25 ( struct V_2 * V_3 , int V_5 , T_1 * V_126 )
{
int V_4 = F_5 ( V_3 -> V_93 + 4 + 2 * V_5 ) ;
int V_127 , V_62 , V_47 , V_29 ;
unsigned char V_128 ;
T_2 V_129 ;
int V_130 = 0 ;
if ( ! V_4 )
return - V_131 ;
V_127 = F_5 ( V_4 + V_132 ) ;
V_62 = F_4 ( V_4 + V_133 ) ;
V_47 = F_4 ( V_4 + V_134 ) & V_135 ;
V_29 = V_4 + V_136 ;
F_21 ( L_70 , V_4 , V_127 , V_62 , V_47 ) ;
V_129 . V_3 = V_3 ;
V_129 . V_94 = V_47 / 4 ;
V_129 . V_111 = V_4 ;
V_129 . V_47 = V_126 ;
V_129 . abort = false ;
V_129 . V_110 = 0 ;
if ( V_62 )
V_129 . V_62 = F_58 ( 4 * V_62 , V_137 ) ;
else
V_129 . V_62 = NULL ;
V_138 ++ ;
while ( 1 ) {
V_128 = F_4 ( V_29 ++ ) ;
if ( V_128 < V_139 )
F_21 ( L_71 , V_140 [ V_128 ] , V_29 - 1 ) ;
else
F_21 ( L_72 , V_128 , V_29 - 1 ) ;
if ( V_129 . abort ) {
F_12 ( L_73 ,
V_4 , V_127 , V_62 , V_47 , V_29 - 1 ) ;
V_130 = - V_131 ;
goto free;
}
if ( V_128 < V_141 && V_128 > 0 )
V_142 [ V_128 ] . F_59 ( & V_129 , & V_29 ,
V_142 [ V_128 ] . V_35 ) ;
else
break;
if ( V_128 == V_143 )
break;
}
V_138 -- ;
F_21 ( L_74 ) ;
free:
if ( V_62 )
F_60 ( V_129 . V_62 ) ;
return V_130 ;
}
int F_61 ( struct V_2 * V_3 , int V_5 , T_1 * V_126 )
{
int V_90 ;
F_62 ( & V_3 -> V_144 ) ;
V_3 -> V_38 = 0 ;
V_3 -> V_59 = 0 ;
V_3 -> V_39 = V_40 ;
V_90 = F_25 ( V_3 , V_5 , V_126 ) ;
F_63 ( & V_3 -> V_144 ) ;
return V_90 ;
}
static void F_64 ( struct V_2 * V_3 , int V_4 )
{
V_3 -> V_44 = F_58 ( 2 * 256 , V_137 ) ;
while ( F_4 ( V_4 ) == V_145 ) {
V_3 -> V_44 [ F_4 ( V_4 + 1 ) ] = V_4 + 2 ;
V_4 += 2 ;
while ( F_4 ( V_4 ) != V_26 )
V_4 += V_146 [ F_4 ( V_4 ) ] ;
V_4 += 3 ;
}
}
struct V_2 * F_65 ( struct V_147 * V_9 , void * V_148 )
{
int V_4 ;
struct V_2 * V_3 =
F_58 ( sizeof( struct V_2 ) , V_137 ) ;
char * V_149 ;
char V_150 [ 512 ] ;
int V_151 ;
if ( ! V_3 )
return NULL ;
V_3 -> V_9 = V_9 ;
V_3 -> V_148 = V_148 ;
if ( F_5 ( 0 ) != V_152 ) {
F_2 ( V_27 L_75 ) ;
F_60 ( V_3 ) ;
return NULL ;
}
if ( strncmp
( F_66 ( V_153 ) , V_154 ,
strlen ( V_154 ) ) ) {
F_2 ( V_27 L_76 ) ;
F_60 ( V_3 ) ;
return NULL ;
}
V_4 = F_5 ( V_155 ) ;
if ( strncmp
( F_66 ( V_4 + V_156 ) , V_157 ,
strlen ( V_157 ) ) ) {
F_2 ( V_27 L_77 ) ;
F_60 ( V_3 ) ;
return NULL ;
}
V_3 -> V_93 = F_5 ( V_4 + V_158 ) ;
V_3 -> V_115 = F_5 ( V_4 + V_159 ) ;
F_64 ( V_3 , F_5 ( V_3 -> V_115 + V_160 ) + 4 ) ;
V_149 = F_66 ( F_5 ( V_4 + V_161 ) ) ;
while ( * V_149 && ( ( * V_149 == '\n' ) || ( * V_149 == '\r' ) ) )
V_149 ++ ;
for ( V_151 = 0 ; V_151 < 511 ; V_151 ++ ) {
V_150 [ V_151 ] = V_149 [ V_151 ] ;
if ( V_150 [ V_151 ] < '.' || V_150 [ V_151 ] > 'z' ) {
V_150 [ V_151 ] = 0 ;
break;
}
}
F_2 ( V_27 L_78 , V_150 ) ;
return V_3 ;
}
int F_67 ( struct V_2 * V_3 )
{
int V_162 = F_5 ( V_3 -> V_115 + V_163 ) ;
T_1 V_47 [ 16 ] ;
memset ( V_47 , 0 , 64 ) ;
V_47 [ 0 ] = F_19 ( F_68 ( V_162 + V_164 ) ) ;
V_47 [ 1 ] = F_19 ( F_68 ( V_162 + V_165 ) ) ;
if ( ! V_47 [ 0 ] || ! V_47 [ 1 ] )
return 1 ;
if ( ! F_5 ( V_3 -> V_93 + 4 + 2 * V_166 ) )
return 1 ;
return F_61 ( V_3 , V_166 , V_47 ) ;
}
void F_69 ( struct V_2 * V_3 )
{
if ( V_3 -> V_44 )
F_60 ( V_3 -> V_44 ) ;
F_60 ( V_3 ) ;
}
bool F_70 ( struct V_2 * V_3 , int V_5 ,
T_4 * V_167 , T_3 * V_168 , T_3 * V_169 ,
T_4 * V_170 )
{
int V_171 = V_5 * 2 + 4 ;
int V_32 = F_5 ( V_3 -> V_115 + V_171 ) ;
T_5 * V_172 = ( T_5 * ) ( V_3 -> V_148 + V_3 -> V_115 + 4 ) ;
if ( ! V_172 [ V_5 ] )
return false ;
if ( V_167 )
* V_167 = F_5 ( V_32 ) ;
if ( V_168 )
* V_168 = F_4 ( V_32 + 2 ) ;
if ( V_169 )
* V_169 = F_4 ( V_32 + 3 ) ;
* V_170 = V_32 ;
return true ;
}
bool F_71 ( struct V_2 * V_3 , int V_5 , T_3 * V_168 ,
T_3 * V_169 )
{
int V_171 = V_5 * 2 + 4 ;
int V_32 = F_5 ( V_3 -> V_93 + V_171 ) ;
T_5 * V_173 = ( T_5 * ) ( V_3 -> V_148 + V_3 -> V_93 + 4 ) ;
if ( ! V_173 [ V_5 ] )
return false ;
if ( V_168 )
* V_168 = F_4 ( V_32 + 2 ) ;
if ( V_169 )
* V_169 = F_4 ( V_32 + 3 ) ;
return true ;
}
int F_72 ( struct V_2 * V_3 )
{
int V_5 = F_73 ( V_174 , V_175 ) ;
T_4 V_176 ;
int V_177 = 0 ;
struct V_178 * V_179 ;
if ( F_70 ( V_3 , V_5 , NULL , NULL , NULL , & V_176 ) ) {
V_179 = (struct V_178 * ) ( V_3 -> V_148 + V_176 ) ;
F_74 ( L_79 ,
V_179 -> V_180 [ 0 ] . V_181 ,
V_179 -> V_180 [ 0 ] . V_182 ) ;
V_177 = V_179 -> V_180 [ 0 ] . V_182 * 1024 ;
}
V_3 -> V_65 = 0 ;
if ( V_177 == 0 )
V_177 = 20 * 1024 ;
V_3 -> V_66 = F_58 ( V_177 , V_137 ) ;
if ( ! V_3 -> V_66 )
return - V_183 ;
V_3 -> V_65 = V_177 ;
return 0 ;
}
