static void F_1 ( int V_1 )
{
while ( V_1 -- )
F_2 ( L_1 ) ;
}
static T_1 F_3 ( struct V_2 * V_3 , int V_4 ,
T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = 0xCDCDCDCD ;
while ( 1 )
switch ( F_4 ( V_4 ) ) {
case V_8 :
V_4 ++ ;
break;
case V_9 :
V_7 = V_3 -> V_10 -> V_11 ( V_3 -> V_10 , F_5 ( V_4 + 1 ) ) ;
V_4 += 3 ;
break;
case V_12 :
V_3 -> V_10 -> V_13 ( V_3 -> V_10 , F_5 ( V_4 + 1 ) , V_7 ) ;
V_4 += 3 ;
break;
case V_14 :
V_7 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 2 ) ) ;
V_4 += 3 ;
break;
case V_15 :
V_7 |=
( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) << F_4 ( V_4 +
2 ) ;
V_4 += 3 ;
break;
case V_16 :
V_7 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 3 ) ) ;
V_7 |=
( ( V_5 >> F_4 ( V_4 + 2 ) ) &
( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) ) << F_4 ( V_4 +
3 ) ;
V_4 += 4 ;
break;
case V_17 :
V_7 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 3 ) ) ;
V_7 |=
( ( V_6 >> F_4 ( V_4 + 2 ) ) &
( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) ) << F_4 ( V_4 +
3 ) ;
V_4 += 4 ;
break;
case V_18 :
V_7 &=
~ ( ( 0xFFFFFFFF >> ( 32 - F_4 ( V_4 + 1 ) ) ) <<
F_4 ( V_4 + 3 ) ) ;
V_7 |=
( ( V_3 ->
V_19 >> F_4 ( V_4 + 2 ) ) & ( 0xFFFFFFFF >> ( 32 -
F_4
( V_4
+
1 ) ) ) )
<< F_4 ( V_4 + 3 ) ;
V_4 += 4 ;
break;
case V_20 :
return V_7 ;
default:
F_2 ( V_21 L_2 ) ;
return 0 ;
}
}
static T_1 F_6 ( T_2 * V_3 , T_3 V_22 ,
int * V_23 , T_1 * V_24 , int V_25 )
{
T_1 V_26 , V_27 = 0xCDCDCDCD , V_28 , V_29 ;
struct V_2 * V_30 = V_3 -> V_3 ;
V_29 = V_22 & 7 ;
V_28 = ( V_22 >> 3 ) & 7 ;
switch ( V_29 ) {
case V_31 :
V_26 = F_7 ( * V_23 ) ;
( * V_23 ) += 2 ;
if ( V_25 )
F_8 ( L_3 , V_26 ) ;
V_26 += V_30 -> V_32 ;
switch ( V_30 -> V_33 ) {
case V_34 :
V_27 = V_30 -> V_10 -> V_35 ( V_30 -> V_10 , V_26 ) ;
break;
case V_36 :
F_2 ( V_21
L_4 ) ;
return 0 ;
case V_37 :
F_2 ( V_21
L_5 ) ;
return 0 ;
default:
if ( ! ( V_30 -> V_33 & 0x80 ) ) {
F_2 ( V_21 L_6 ) ;
return 0 ;
}
if ( ! V_30 -> V_38 [ V_30 -> V_33 & 0x7F ] ) {
F_2 ( V_21
L_7 ,
V_30 -> V_33 & 0x7F ) ;
return 0 ;
}
V_27 =
F_3 ( V_30 ,
V_30 -> V_38 [ V_30 -> V_33 & 0x7F ] ,
V_26 , 0 ) ;
}
break;
case V_39 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
V_27 = F_10 ( ( V_40 * ) & V_3 -> V_41 [ V_26 ] ) ;
if ( V_25 )
F_8 ( L_8 , V_26 , V_27 ) ;
break;
case V_42 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
if ( V_25 )
F_8 ( L_9 , V_26 ) ;
switch ( V_26 ) {
case V_43 :
V_27 = V_30 -> V_44 [ 0 ] ;
break;
case V_45 :
V_27 = V_30 -> V_44 [ 1 ] ;
break;
case V_46 :
V_27 = V_30 -> V_47 ;
break;
case V_48 :
V_27 = V_30 -> V_49 ;
break;
case V_50 :
V_27 = 1 << V_30 -> V_49 ;
break;
case V_51 :
V_27 = ~ ( 1 << V_30 -> V_49 ) ;
break;
case V_52 :
V_27 = V_30 -> V_53 ;
break;
case V_54 :
V_27 = V_30 -> V_19 ;
break;
case V_55 :
V_27 = V_30 -> V_32 ;
break;
default:
V_27 = V_3 -> V_56 [ V_26 ] ;
}
break;
case V_57 :
V_26 = F_7 ( * V_23 ) ;
( * V_23 ) += 2 ;
if ( V_25 ) {
if ( V_30 -> V_47 )
F_8 ( L_10 , V_26 , V_30 -> V_47 ) ;
else
F_8 ( L_11 , V_26 ) ;
}
V_27 = F_11 ( V_26 + V_30 -> V_47 ) ;
break;
case V_58 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
if ( ( V_30 -> V_53 + ( V_26 * 4 ) ) > V_30 -> V_59 ) {
F_12 ( L_12 ,
V_30 -> V_53 + ( V_26 * 4 ) , V_30 -> V_59 ) ;
V_27 = 0 ;
} else
V_27 = V_30 -> V_60 [ ( V_30 -> V_53 / 4 ) + V_26 ] ;
if ( V_25 )
F_8 ( L_13 , V_26 ) ;
break;
case V_61 :
switch ( V_28 ) {
case V_62 :
V_27 = F_11 ( * V_23 ) ;
( * V_23 ) += 4 ;
if ( V_25 )
F_8 ( L_14 , V_27 ) ;
return V_27 ;
case V_63 :
case V_64 :
case V_65 :
V_27 = F_7 ( * V_23 ) ;
( * V_23 ) += 2 ;
if ( V_25 )
F_8 ( L_15 , V_27 ) ;
return V_27 ;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_27 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
if ( V_25 )
F_8 ( L_16 , V_27 ) ;
return V_27 ;
}
return 0 ;
case V_70 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
if ( V_25 )
F_8 ( L_17 , V_26 ) ;
V_27 = V_30 -> V_10 -> V_71 ( V_30 -> V_10 , V_26 ) ;
break;
case V_72 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
if ( V_25 )
F_8 ( L_18 , V_26 ) ;
V_27 = V_30 -> V_10 -> V_73 ( V_30 -> V_10 , V_26 ) ;
break;
}
if ( V_24 )
* V_24 = V_27 ;
V_27 &= V_74 [ V_28 ] ;
V_27 >>= V_75 [ V_28 ] ;
if ( V_25 )
switch ( V_28 ) {
case V_62 :
F_8 ( L_19 , V_27 ) ;
break;
case V_63 :
F_8 ( L_20 , V_27 ) ;
break;
case V_64 :
F_8 ( L_21 , V_27 ) ;
break;
case V_65 :
F_8 ( L_22 , V_27 ) ;
break;
case V_66 :
F_8 ( L_23 , V_27 ) ;
break;
case V_67 :
F_8 ( L_24 , V_27 ) ;
break;
case V_68 :
F_8 ( L_25 , V_27 ) ;
break;
case V_69 :
F_8 ( L_26 , V_27 ) ;
break;
}
return V_27 ;
}
static void F_13 ( T_2 * V_3 , T_3 V_22 , int * V_23 )
{
T_1 V_28 = ( V_22 >> 3 ) & 7 , V_29 = V_22 & 7 ;
switch ( V_29 ) {
case V_31 :
case V_57 :
( * V_23 ) += 2 ;
break;
case V_70 :
case V_72 :
case V_39 :
case V_42 :
case V_58 :
( * V_23 ) ++ ;
break;
case V_61 :
switch ( V_28 ) {
case V_62 :
( * V_23 ) += 4 ;
return;
case V_63 :
case V_64 :
case V_65 :
( * V_23 ) += 2 ;
return;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
( * V_23 ) ++ ;
return;
}
return;
}
}
static T_1 F_14 ( T_2 * V_3 , T_3 V_22 , int * V_23 )
{
return F_6 ( V_3 , V_22 , V_23 , NULL , 1 ) ;
}
static T_1 F_15 ( T_2 * V_3 , T_3 V_28 , int * V_23 )
{
T_1 V_27 = 0xCDCDCDCD ;
switch ( V_28 ) {
case V_62 :
V_27 = F_11 ( * V_23 ) ;
( * V_23 ) += 4 ;
break;
case V_63 :
case V_64 :
case V_65 :
V_27 = F_7 ( * V_23 ) ;
( * V_23 ) += 2 ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_27 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
break;
}
return V_27 ;
}
static T_1 F_16 ( T_2 * V_3 , int V_29 , T_3 V_22 ,
int * V_23 , T_1 * V_24 , int V_25 )
{
return F_6 ( V_3 ,
V_29 | V_76 [ ( V_22 >> 3 ) &
7 ] [ ( V_22 >> 6 ) & 3 ] << 3 ,
V_23 , V_24 , V_25 ) ;
}
static void F_17 ( T_2 * V_3 , int V_29 , T_3 V_22 , int * V_23 )
{
F_13 ( V_3 ,
V_29 | V_76 [ ( V_22 >> 3 ) & 7 ] [ ( V_22 >> 6 ) &
3 ] << 3 , V_23 ) ;
}
static void F_18 ( T_2 * V_3 , int V_29 , T_3 V_22 ,
int * V_23 , T_1 V_27 , T_1 V_24 )
{
T_1 V_28 =
V_76 [ ( V_22 >> 3 ) & 7 ] [ ( V_22 >> 6 ) & 3 ] , V_77 =
V_27 , V_26 ;
struct V_2 * V_30 = V_3 -> V_3 ;
V_77 &= V_74 [ V_28 ] >> V_75 [ V_28 ] ;
V_27 <<= V_75 [ V_28 ] ;
V_27 &= V_74 [ V_28 ] ;
V_24 &= ~ V_74 [ V_28 ] ;
V_27 |= V_24 ;
switch ( V_29 ) {
case V_31 :
V_26 = F_7 ( * V_23 ) ;
( * V_23 ) += 2 ;
F_8 ( L_3 , V_26 ) ;
V_26 += V_30 -> V_32 ;
switch ( V_30 -> V_33 ) {
case V_34 :
if ( V_26 == 0 )
V_30 -> V_10 -> V_78 ( V_30 -> V_10 , V_26 ,
V_27 << 2 ) ;
else
V_30 -> V_10 -> V_78 ( V_30 -> V_10 , V_26 , V_27 ) ;
break;
case V_36 :
F_2 ( V_21
L_4 ) ;
return;
case V_37 :
F_2 ( V_21
L_5 ) ;
return;
default:
if ( ! ( V_30 -> V_33 & 0x80 ) ) {
F_2 ( V_21 L_6 ) ;
return;
}
if ( ! V_30 -> V_38 [ V_30 -> V_33 & 0xFF ] ) {
F_2 ( V_21
L_27 ,
V_30 -> V_33 & 0x7F ) ;
return;
}
F_3 ( V_30 , V_30 -> V_38 [ V_30 -> V_33 & 0xFF ] ,
V_26 , V_27 ) ;
}
break;
case V_39 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
F_8 ( L_28 , V_26 ) ;
V_3 -> V_41 [ V_26 ] = F_19 ( V_27 ) ;
break;
case V_42 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
F_8 ( L_9 , V_26 ) ;
switch ( V_26 ) {
case V_43 :
V_30 -> V_44 [ 0 ] = V_27 ;
break;
case V_45 :
V_30 -> V_44 [ 1 ] = V_27 ;
break;
case V_46 :
V_30 -> V_47 = V_27 ;
break;
case V_48 :
V_30 -> V_49 = V_27 ;
break;
case V_50 :
case V_51 :
break;
case V_52 :
V_30 -> V_53 = V_27 ;
break;
case V_54 :
V_30 -> V_19 = V_27 ;
break;
case V_55 :
V_30 -> V_32 = V_27 ;
break;
default:
V_3 -> V_56 [ V_26 ] = V_27 ;
}
break;
case V_58 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
if ( ( V_30 -> V_53 + ( V_26 * 4 ) ) > V_30 -> V_59 ) {
F_12 ( L_29 ,
V_30 -> V_53 + ( V_26 * 4 ) , V_30 -> V_59 ) ;
} else
V_30 -> V_60 [ ( V_30 -> V_53 / 4 ) + V_26 ] = V_27 ;
F_8 ( L_13 , V_26 ) ;
break;
case V_70 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
F_8 ( L_17 , V_26 ) ;
V_30 -> V_10 -> V_79 ( V_30 -> V_10 , V_26 , V_27 ) ;
break;
case V_72 :
V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
F_8 ( L_18 , V_26 ) ;
V_30 -> V_10 -> V_80 ( V_30 -> V_10 , V_26 , V_27 ) ;
return;
}
switch ( V_28 ) {
case V_62 :
F_8 ( L_30 , V_77 ) ;
break;
case V_63 :
F_8 ( L_31 , V_77 ) ;
break;
case V_64 :
F_8 ( L_32 , V_77 ) ;
break;
case V_65 :
F_8 ( L_33 , V_77 ) ;
break;
case V_66 :
F_8 ( L_34 , V_77 ) ;
break;
case V_67 :
F_8 ( L_35 , V_77 ) ;
break;
case V_68 :
F_8 ( L_36 , V_77 ) ;
break;
case V_69 :
F_8 ( L_37 , V_77 ) ;
break;
}
}
static void F_20 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 , V_24 ;
int V_83 = * V_23 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_81 += V_82 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_22 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 , V_24 ;
int V_83 = * V_23 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_81 &= V_82 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_23 ( T_2 * V_3 , int * V_23 , int V_29 )
{
F_2 ( L_40 ) ;
}
static void F_24 ( T_2 * V_3 , int * V_23 , int V_29 )
{
int V_26 = F_9 ( ( * V_23 ) ++ ) ;
int V_84 = 0 ;
if ( V_26 < V_85 )
F_21 ( L_41 , V_26 , V_86 [ V_26 ] ) ;
else
F_21 ( L_42 , V_26 ) ;
if ( F_7 ( V_3 -> V_3 -> V_87 + 4 + 2 * V_26 ) )
V_84 = F_25 ( V_3 -> V_3 , V_26 , V_3 -> V_41 + V_3 -> V_88 ) ;
if ( V_84 ) {
V_3 -> abort = true ;
}
}
static void F_26 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_24 ;
int V_83 = * V_23 ;
V_22 &= 0x38 ;
V_22 |= V_89 [ V_22 >> 3 ] << 6 ;
F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 0 ) ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , 0 , V_24 ) ;
}
static void F_27 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 ;
F_21 ( L_43 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_3 -> V_3 -> V_90 = ( V_81 == V_82 ) ;
V_3 -> V_3 -> V_91 = ( V_81 > V_82 ) ;
F_21 ( L_45 , V_3 -> V_3 -> V_90 ? L_46 : L_47 ,
V_3 -> V_3 -> V_91 ? L_48 : L_49 ) ;
}
static void F_28 ( T_2 * V_3 , int * V_23 , int V_29 )
{
unsigned V_92 = F_9 ( ( * V_23 ) ++ ) ;
F_21 ( L_50 , V_92 ) ;
if ( V_29 == V_93 )
F_29 ( V_92 ) ;
else if ( ! F_30 () )
F_31 ( V_92 ) ;
else
F_32 ( V_92 ) ;
}
static void F_33 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 ;
F_21 ( L_43 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
if ( V_82 != 0 ) {
V_3 -> V_3 -> V_44 [ 0 ] = V_81 / V_82 ;
V_3 -> V_3 -> V_44 [ 1 ] = V_81 % V_82 ;
} else {
V_3 -> V_3 -> V_44 [ 0 ] = 0 ;
V_3 -> V_3 -> V_44 [ 1 ] = 0 ;
}
}
static void F_34 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_4 V_94 ;
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 ;
F_21 ( L_43 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
if ( V_82 != 0 ) {
V_94 = V_81 ;
V_94 |= ( ( T_4 ) V_3 -> V_3 -> V_44 [ 1 ] ) << 32 ;
F_35 ( V_94 , V_82 ) ;
V_3 -> V_3 -> V_44 [ 0 ] = F_36 ( V_94 ) ;
V_3 -> V_3 -> V_44 [ 1 ] = F_37 ( V_94 ) ;
} else {
V_3 -> V_3 -> V_44 [ 0 ] = 0 ;
V_3 -> V_3 -> V_44 [ 1 ] = 0 ;
}
}
static void F_38 ( T_2 * V_3 , int * V_23 , int V_29 )
{
}
static void F_39 ( T_2 * V_3 , int * V_23 , int V_29 )
{
int V_95 = 0 , V_96 = F_7 ( * V_23 ) ;
unsigned long V_97 ;
( * V_23 ) += 2 ;
switch ( V_29 ) {
case V_98 :
V_95 = V_3 -> V_3 -> V_91 ;
break;
case V_99 :
V_95 = V_3 -> V_3 -> V_91 || V_3 -> V_3 -> V_90 ;
break;
case V_100 :
V_95 = 1 ;
break;
case V_101 :
V_95 = ! ( V_3 -> V_3 -> V_91 || V_3 -> V_3 -> V_90 ) ;
break;
case V_102 :
V_95 = ! V_3 -> V_3 -> V_91 ;
break;
case V_103 :
V_95 = V_3 -> V_3 -> V_90 ;
break;
case V_104 :
V_95 = ! V_3 -> V_3 -> V_90 ;
break;
}
if ( V_29 != V_100 )
F_21 ( L_51 , V_95 ? L_52 : L_53 ) ;
F_21 ( L_54 , V_96 ) ;
if ( V_95 ) {
if ( V_3 -> V_105 == ( V_3 -> V_106 + V_96 ) ) {
V_97 = V_107 ;
if ( F_40 ( V_97 , V_3 -> V_108 ) ) {
V_97 -= V_3 -> V_108 ;
if ( ( F_41 ( V_97 ) > 5000 ) ) {
F_12 ( L_55 ) ;
V_3 -> abort = true ;
}
} else {
V_3 -> V_108 = V_107 ;
}
} else {
V_3 -> V_105 = V_3 -> V_106 + V_96 ;
V_3 -> V_108 = V_107 ;
}
* V_23 = V_3 -> V_106 + V_96 ;
}
}
static void F_42 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_109 , V_82 , V_24 ;
int V_83 = * V_23 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
V_109 = F_15 ( V_3 , ( ( V_22 >> 3 ) & 7 ) , V_23 ) ;
F_21 ( L_56 , V_109 ) ;
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_81 &= V_109 ;
V_81 |= V_82 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_43 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_82 , V_24 ;
int V_83 = * V_23 ;
if ( ( ( V_22 >> 3 ) & 7 ) != V_62 )
F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 0 ) ;
else {
F_17 ( V_3 , V_29 , V_22 , V_23 ) ;
V_24 = 0xCDCDCDCD ;
}
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_82 , V_24 ) ;
}
static void F_44 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 ;
F_21 ( L_43 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_3 -> V_3 -> V_44 [ 0 ] = V_81 * V_82 ;
}
static void F_45 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_4 V_94 ;
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 ;
F_21 ( L_43 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_94 = ( T_4 ) V_81 * ( T_4 ) V_82 ;
V_3 -> V_3 -> V_44 [ 0 ] = F_36 ( V_94 ) ;
V_3 -> V_3 -> V_44 [ 1 ] = F_37 ( V_94 ) ;
}
static void F_46 ( T_2 * V_3 , int * V_23 , int V_29 )
{
}
static void F_47 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 , V_24 ;
int V_83 = * V_23 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_81 |= V_82 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_48 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_27 = F_9 ( ( * V_23 ) ++ ) ;
F_21 ( L_57 , V_27 ) ;
}
static void F_49 ( T_2 * V_3 , int * V_23 , int V_29 )
{
F_2 ( V_21 L_58 ) ;
}
static void F_50 ( T_2 * V_3 , int * V_23 , int V_29 )
{
F_2 ( V_21 L_58 ) ;
}
static void F_51 ( T_2 * V_3 , int * V_23 , int V_29 )
{
F_2 ( V_21 L_58 ) ;
}
static void F_52 ( T_2 * V_3 , int * V_23 , int V_29 )
{
int V_26 = F_9 ( * V_23 ) ;
( * V_23 ) ++ ;
F_21 ( L_59 , V_26 ) ;
if ( ! V_26 )
V_3 -> V_3 -> V_47 = 0 ;
else if ( V_26 == 255 )
V_3 -> V_3 -> V_47 = V_3 -> V_106 ;
else
V_3 -> V_3 -> V_47 = F_7 ( V_3 -> V_3 -> V_110 + 4 + 2 * V_26 ) ;
F_21 ( L_60 , V_3 -> V_3 -> V_47 ) ;
}
static void F_53 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
F_21 ( L_61 ) ;
V_3 -> V_3 -> V_53 = F_14 ( V_3 , V_22 , V_23 ) ;
}
static void F_54 ( T_2 * V_3 , int * V_23 , int V_29 )
{
int V_111 ;
switch ( V_29 ) {
case V_112 :
V_111 = F_7 ( * V_23 ) ;
if ( V_111 < V_113 )
F_21 ( L_62 , V_111 , V_114 [ V_111 ] ) ;
else
F_21 ( L_63 , V_111 ) ;
if ( ! V_111 )
V_3 -> V_3 -> V_33 = V_34 ;
else
V_3 -> V_3 -> V_33 = V_115 | V_111 ;
( * V_23 ) += 2 ;
break;
case V_116 :
V_3 -> V_3 -> V_33 = V_36 ;
( * V_23 ) ++ ;
break;
case V_117 :
V_3 -> V_3 -> V_33 = V_37 ;
( * V_23 ) ++ ;
break;
}
}
static void F_55 ( T_2 * V_3 , int * V_23 , int V_29 )
{
V_3 -> V_3 -> V_32 = F_7 ( * V_23 ) ;
( * V_23 ) += 2 ;
F_21 ( L_60 , V_3 -> V_3 -> V_32 ) ;
}
static void F_56 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) , V_49 ;
T_1 V_24 , V_81 ;
int V_83 = * V_23 ;
V_22 &= 0x38 ;
V_22 |= V_89 [ V_22 >> 3 ] << 6 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
V_49 = F_15 ( V_3 , V_66 , V_23 ) ;
F_21 ( L_64 , V_49 ) ;
V_81 <<= V_49 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_57 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) , V_49 ;
T_1 V_24 , V_81 ;
int V_83 = * V_23 ;
V_22 &= 0x38 ;
V_22 |= V_89 [ V_22 >> 3 ] << 6 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
V_49 = F_15 ( V_3 , V_66 , V_23 ) ;
F_21 ( L_64 , V_49 ) ;
V_81 >>= V_49 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_58 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) , V_49 ;
T_1 V_24 , V_81 ;
int V_83 = * V_23 ;
T_1 V_118 = V_76 [ ( V_22 >> 3 ) & 7 ] [ ( V_22 >> 6 ) & 3 ] ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
V_81 = V_24 ;
V_49 = F_14 ( V_3 , V_22 , V_23 ) ;
F_21 ( L_64 , V_49 ) ;
V_81 <<= V_49 ;
V_81 &= V_74 [ V_118 ] ;
V_81 >>= V_75 [ V_118 ] ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_59 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) , V_49 ;
T_1 V_24 , V_81 ;
int V_83 = * V_23 ;
T_1 V_118 = V_76 [ ( V_22 >> 3 ) & 7 ] [ ( V_22 >> 6 ) & 3 ] ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
V_81 = V_24 ;
V_49 = F_14 ( V_3 , V_22 , V_23 ) ;
F_21 ( L_64 , V_49 ) ;
V_81 >>= V_49 ;
V_81 &= V_74 [ V_118 ] ;
V_81 >>= V_75 [ V_118 ] ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_60 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 , V_24 ;
int V_83 = * V_23 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_81 -= V_82 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_61 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_82 , V_27 , V_96 ;
F_21 ( L_65 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
while ( F_7 ( * V_23 ) != V_119 )
if ( F_9 ( * V_23 ) == V_120 ) {
( * V_23 ) ++ ;
F_21 ( L_66 ) ;
V_27 =
F_14 ( V_3 , ( V_22 & 0x38 ) | V_61 ,
V_23 ) ;
V_96 = F_7 ( * V_23 ) ;
if ( V_27 == V_82 ) {
F_21 ( L_67 , V_96 ) ;
* V_23 = V_3 -> V_106 + V_96 ;
return;
}
( * V_23 ) += 2 ;
} else {
F_2 ( V_21 L_68 ) ;
return;
}
( * V_23 ) += 2 ;
}
static void F_62 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 ;
F_21 ( L_43 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , NULL , 1 ) ;
F_21 ( L_44 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_3 -> V_3 -> V_90 = ( ( V_81 & V_82 ) == 0 ) ;
F_21 ( L_69 , V_3 -> V_3 -> V_90 ? L_46 : L_47 ) ;
}
static void F_63 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_22 = F_9 ( ( * V_23 ) ++ ) ;
T_1 V_81 , V_82 , V_24 ;
int V_83 = * V_23 ;
F_21 ( L_38 ) ;
V_81 = F_16 ( V_3 , V_29 , V_22 , V_23 , & V_24 , 1 ) ;
F_21 ( L_39 ) ;
V_82 = F_14 ( V_3 , V_22 , V_23 ) ;
V_81 ^= V_82 ;
F_21 ( L_38 ) ;
F_18 ( V_3 , V_29 , V_22 , & V_83 , V_81 , V_24 ) ;
}
static void F_64 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_3 V_27 = F_9 ( ( * V_23 ) ++ ) ;
F_21 ( L_70 , V_27 ) ;
}
static void F_65 ( T_2 * V_3 , int * V_23 , int V_29 )
{
T_5 V_27 = F_7 ( * V_23 ) ;
( * V_23 ) += V_27 + 2 ;
F_21 ( L_71 , V_27 ) ;
}
static int F_25 ( struct V_2 * V_3 , int V_5 , T_1 * V_121 )
{
int V_4 = F_5 ( V_3 -> V_87 + 4 + 2 * V_5 ) ;
int V_122 , V_56 , V_41 , V_23 ;
unsigned char V_123 ;
T_2 V_124 ;
int V_125 = 0 ;
if ( ! V_4 )
return - V_126 ;
V_122 = F_5 ( V_4 + V_127 ) ;
V_56 = F_4 ( V_4 + V_128 ) ;
V_41 = F_4 ( V_4 + V_129 ) & V_130 ;
V_23 = V_4 + V_131 ;
F_21 ( L_72 , V_4 , V_122 , V_56 , V_41 ) ;
V_124 . V_3 = V_3 ;
V_124 . V_88 = V_41 / 4 ;
V_124 . V_106 = V_4 ;
V_124 . V_41 = V_121 ;
V_124 . abort = false ;
V_124 . V_105 = 0 ;
if ( V_56 )
V_124 . V_56 = F_66 ( 4 * V_56 , V_132 ) ;
else
V_124 . V_56 = NULL ;
V_133 ++ ;
while ( 1 ) {
V_123 = F_4 ( V_23 ++ ) ;
if ( V_123 < V_134 )
F_21 ( L_73 , V_135 [ V_123 ] , V_23 - 1 ) ;
else
F_21 ( L_74 , V_123 , V_23 - 1 ) ;
if ( V_124 . abort ) {
F_12 ( L_75 ,
V_4 , V_122 , V_56 , V_41 , V_23 - 1 ) ;
V_125 = - V_126 ;
goto free;
}
if ( V_123 < V_136 && V_123 > 0 )
V_137 [ V_123 ] . F_67 ( & V_124 , & V_23 ,
V_137 [ V_123 ] . V_29 ) ;
else
break;
if ( V_123 == V_138 )
break;
}
V_133 -- ;
F_21 ( L_76 ) ;
free:
if ( V_56 )
F_68 ( V_124 . V_56 ) ;
return V_125 ;
}
int F_69 ( struct V_2 * V_3 , int V_5 , T_1 * V_121 )
{
int V_84 ;
F_70 ( & V_3 -> V_139 ) ;
V_3 -> V_47 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_53 = 0 ;
V_3 -> V_33 = V_34 ;
V_3 -> V_44 [ 0 ] = 0 ;
V_3 -> V_44 [ 1 ] = 0 ;
V_84 = F_25 ( V_3 , V_5 , V_121 ) ;
F_71 ( & V_3 -> V_139 ) ;
return V_84 ;
}
static void F_72 ( struct V_2 * V_3 , int V_4 )
{
V_3 -> V_38 = F_66 ( 2 * 256 , V_132 ) ;
if ( ! V_3 -> V_38 )
return;
while ( F_4 ( V_4 ) == V_140 ) {
V_3 -> V_38 [ F_4 ( V_4 + 1 ) ] = V_4 + 2 ;
V_4 += 2 ;
while ( F_4 ( V_4 ) != V_20 )
V_4 += V_141 [ F_4 ( V_4 ) ] ;
V_4 += 3 ;
}
}
struct V_2 * F_73 ( struct V_142 * V_10 , void * V_143 )
{
int V_4 ;
struct V_2 * V_3 =
F_66 ( sizeof( struct V_2 ) , V_132 ) ;
char * V_144 ;
char V_145 [ 512 ] ;
int V_146 ;
if ( ! V_3 )
return NULL ;
V_3 -> V_10 = V_10 ;
V_3 -> V_143 = V_143 ;
if ( F_5 ( 0 ) != V_147 ) {
F_2 ( V_21 L_77 ) ;
F_68 ( V_3 ) ;
return NULL ;
}
if ( strncmp
( F_74 ( V_148 ) , V_149 ,
strlen ( V_149 ) ) ) {
F_2 ( V_21 L_78 ) ;
F_68 ( V_3 ) ;
return NULL ;
}
V_4 = F_5 ( V_150 ) ;
if ( strncmp
( F_74 ( V_4 + V_151 ) , V_152 ,
strlen ( V_152 ) ) ) {
F_2 ( V_21 L_79 ) ;
F_68 ( V_3 ) ;
return NULL ;
}
V_3 -> V_87 = F_5 ( V_4 + V_153 ) ;
V_3 -> V_110 = F_5 ( V_4 + V_154 ) ;
F_72 ( V_3 , F_5 ( V_3 -> V_110 + V_155 ) + 4 ) ;
if ( ! V_3 -> V_38 ) {
F_75 ( V_3 ) ;
return NULL ;
}
V_144 = F_74 ( F_5 ( V_4 + V_156 ) ) ;
while ( * V_144 && ( ( * V_144 == '\n' ) || ( * V_144 == '\r' ) ) )
V_144 ++ ;
for ( V_146 = 0 ; V_146 < 511 ; V_146 ++ ) {
V_145 [ V_146 ] = V_144 [ V_146 ] ;
if ( V_145 [ V_146 ] < '.' || V_145 [ V_146 ] > 'z' ) {
V_145 [ V_146 ] = 0 ;
break;
}
}
F_2 ( V_21 L_80 , V_145 ) ;
return V_3 ;
}
int F_76 ( struct V_2 * V_3 )
{
int V_157 = F_5 ( V_3 -> V_110 + V_158 ) ;
T_1 V_41 [ 16 ] ;
int V_125 ;
memset ( V_41 , 0 , 64 ) ;
V_41 [ 0 ] = F_19 ( F_77 ( V_157 + V_159 ) ) ;
V_41 [ 1 ] = F_19 ( F_77 ( V_157 + V_160 ) ) ;
if ( ! V_41 [ 0 ] || ! V_41 [ 1 ] )
return 1 ;
if ( ! F_5 ( V_3 -> V_87 + 4 + 2 * V_161 ) )
return 1 ;
V_125 = F_69 ( V_3 , V_161 , V_41 ) ;
if ( V_125 )
return V_125 ;
memset ( V_41 , 0 , 64 ) ;
return V_125 ;
}
void F_75 ( struct V_2 * V_3 )
{
F_68 ( V_3 -> V_38 ) ;
F_68 ( V_3 ) ;
}
bool F_78 ( struct V_2 * V_3 , int V_5 ,
T_5 * V_162 , T_3 * V_163 , T_3 * V_164 ,
T_5 * V_165 )
{
int V_166 = V_5 * 2 + 4 ;
int V_26 = F_5 ( V_3 -> V_110 + V_166 ) ;
T_6 * V_167 = ( T_6 * ) ( V_3 -> V_143 + V_3 -> V_110 + 4 ) ;
if ( ! V_167 [ V_5 ] )
return false ;
if ( V_162 )
* V_162 = F_5 ( V_26 ) ;
if ( V_163 )
* V_163 = F_4 ( V_26 + 2 ) ;
if ( V_164 )
* V_164 = F_4 ( V_26 + 3 ) ;
* V_165 = V_26 ;
return true ;
}
bool F_79 ( struct V_2 * V_3 , int V_5 , T_3 * V_163 ,
T_3 * V_164 )
{
int V_166 = V_5 * 2 + 4 ;
int V_26 = F_5 ( V_3 -> V_87 + V_166 ) ;
T_6 * V_168 = ( T_6 * ) ( V_3 -> V_143 + V_3 -> V_87 + 4 ) ;
if ( ! V_168 [ V_5 ] )
return false ;
if ( V_163 )
* V_163 = F_4 ( V_26 + 2 ) ;
if ( V_164 )
* V_164 = F_4 ( V_26 + 3 ) ;
return true ;
}
int F_80 ( struct V_2 * V_3 )
{
int V_5 = F_81 ( V_169 , V_170 ) ;
T_5 V_171 ;
int V_172 = 0 ;
struct V_173 * V_174 ;
if ( F_78 ( V_3 , V_5 , NULL , NULL , NULL , & V_171 ) ) {
V_174 = (struct V_173 * ) ( V_3 -> V_143 + V_171 ) ;
F_82 ( L_81 ,
F_83 ( V_174 -> V_175 [ 0 ] . V_176 ) ,
F_84 ( V_174 -> V_175 [ 0 ] . V_177 ) ) ;
V_172 = F_84 ( V_174 -> V_175 [ 0 ] . V_177 ) * 1024 ;
}
V_3 -> V_59 = 0 ;
if ( V_172 == 0 )
V_172 = 20 * 1024 ;
V_3 -> V_60 = F_66 ( V_172 , V_132 ) ;
if ( ! V_3 -> V_60 )
return - V_178 ;
V_3 -> V_59 = V_172 ;
return 0 ;
}
