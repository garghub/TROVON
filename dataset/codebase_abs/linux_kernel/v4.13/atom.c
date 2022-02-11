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
F_6 ( L_2 ) ;
return 0 ;
}
}
static T_1 F_7 ( T_2 * V_3 , T_3 V_27 ,
int * V_28 , T_1 * V_29 , int V_30 )
{
T_1 V_31 , V_32 = 0xCDCDCDCD , V_33 , V_34 ;
struct V_2 * V_35 = V_3 -> V_3 ;
V_34 = V_27 & 7 ;
V_33 = ( V_27 >> 3 ) & 7 ;
switch ( V_34 ) {
case V_36 :
V_31 = F_8 ( * V_28 ) ;
( * V_28 ) += 2 ;
if ( V_30 )
F_9 ( L_3 , V_31 ) ;
V_31 += V_35 -> V_37 ;
switch ( V_35 -> V_38 ) {
case V_39 :
V_32 = V_35 -> V_9 -> V_40 ( V_35 -> V_9 , V_31 ) ;
break;
case V_41 :
F_6 ( L_4 ) ;
return 0 ;
case V_42 :
F_6 ( L_5 ) ;
return 0 ;
default:
if ( ! ( V_35 -> V_38 & 0x80 ) ) {
F_6 ( L_6 ) ;
return 0 ;
}
if ( ! V_35 -> V_43 [ V_35 -> V_38 & 0x7F ] ) {
F_6 ( L_7 ,
V_35 -> V_38 & 0x7F ) ;
return 0 ;
}
V_32 =
F_3 ( V_35 ,
V_35 -> V_43 [ V_35 -> V_38 & 0x7F ] ,
V_31 , 0 ) ;
}
break;
case V_44 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
V_32 = F_11 ( ( V_45 * ) & V_3 -> V_46 [ V_31 ] ) ;
if ( V_30 )
F_9 ( L_8 , V_31 , V_32 ) ;
break;
case V_47 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
if ( V_30 )
F_9 ( L_9 , V_31 ) ;
switch ( V_31 ) {
case V_48 :
V_32 = V_35 -> V_49 [ 0 ] ;
break;
case V_50 :
V_32 = V_35 -> V_49 [ 1 ] ;
break;
case V_51 :
V_32 = V_35 -> V_52 ;
break;
case V_53 :
V_32 = V_35 -> V_54 ;
break;
case V_55 :
V_32 = 1 << V_35 -> V_54 ;
break;
case V_56 :
V_32 = ~ ( 1 << V_35 -> V_54 ) ;
break;
case V_57 :
V_32 = V_35 -> V_58 ;
break;
case V_59 :
V_32 = V_35 -> V_25 ;
break;
case V_60 :
V_32 = V_35 -> V_37 ;
break;
default:
V_32 = V_3 -> V_61 [ V_31 ] ;
}
break;
case V_62 :
V_31 = F_8 ( * V_28 ) ;
( * V_28 ) += 2 ;
if ( V_30 ) {
if ( V_35 -> V_52 )
F_9 ( L_10 , V_31 , V_35 -> V_52 ) ;
else
F_9 ( L_11 , V_31 ) ;
}
V_32 = F_12 ( V_31 + V_35 -> V_52 ) ;
break;
case V_63 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
if ( ( V_35 -> V_58 + ( V_31 * 4 ) ) > V_35 -> V_64 ) {
F_13 ( L_12 ,
V_35 -> V_58 + ( V_31 * 4 ) , V_35 -> V_64 ) ;
V_32 = 0 ;
} else
V_32 = V_35 -> V_65 [ ( V_35 -> V_58 / 4 ) + V_31 ] ;
if ( V_30 )
F_9 ( L_13 , V_31 ) ;
break;
case V_66 :
switch ( V_33 ) {
case V_67 :
V_32 = F_12 ( * V_28 ) ;
( * V_28 ) += 4 ;
if ( V_30 )
F_9 ( L_14 , V_32 ) ;
return V_32 ;
case V_68 :
case V_69 :
case V_70 :
V_32 = F_8 ( * V_28 ) ;
( * V_28 ) += 2 ;
if ( V_30 )
F_9 ( L_15 , V_32 ) ;
return V_32 ;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_32 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
if ( V_30 )
F_9 ( L_16 , V_32 ) ;
return V_32 ;
}
return 0 ;
case V_75 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
if ( V_30 )
F_9 ( L_17 , V_31 ) ;
V_32 = V_35 -> V_9 -> V_76 ( V_35 -> V_9 , V_31 ) ;
break;
case V_77 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
if ( V_30 )
F_9 ( L_18 , V_31 ) ;
V_32 = V_35 -> V_9 -> V_78 ( V_35 -> V_9 , V_31 ) ;
break;
}
if ( V_29 )
* V_29 = V_32 ;
V_32 &= V_79 [ V_33 ] ;
V_32 >>= V_80 [ V_33 ] ;
if ( V_30 )
switch ( V_33 ) {
case V_67 :
F_9 ( L_19 , V_32 ) ;
break;
case V_68 :
F_9 ( L_20 , V_32 ) ;
break;
case V_69 :
F_9 ( L_21 , V_32 ) ;
break;
case V_70 :
F_9 ( L_22 , V_32 ) ;
break;
case V_71 :
F_9 ( L_23 , V_32 ) ;
break;
case V_72 :
F_9 ( L_24 , V_32 ) ;
break;
case V_73 :
F_9 ( L_25 , V_32 ) ;
break;
case V_74 :
F_9 ( L_26 , V_32 ) ;
break;
}
return V_32 ;
}
static void F_14 ( T_2 * V_3 , T_3 V_27 , int * V_28 )
{
T_1 V_33 = ( V_27 >> 3 ) & 7 , V_34 = V_27 & 7 ;
switch ( V_34 ) {
case V_36 :
case V_62 :
( * V_28 ) += 2 ;
break;
case V_75 :
case V_77 :
case V_44 :
case V_47 :
case V_63 :
( * V_28 ) ++ ;
break;
case V_66 :
switch ( V_33 ) {
case V_67 :
( * V_28 ) += 4 ;
return;
case V_68 :
case V_69 :
case V_70 :
( * V_28 ) += 2 ;
return;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
( * V_28 ) ++ ;
return;
}
return;
}
}
static T_1 F_15 ( T_2 * V_3 , T_3 V_27 , int * V_28 )
{
return F_7 ( V_3 , V_27 , V_28 , NULL , 1 ) ;
}
static T_1 F_16 ( T_2 * V_3 , T_3 V_33 , int * V_28 )
{
T_1 V_32 = 0xCDCDCDCD ;
switch ( V_33 ) {
case V_67 :
V_32 = F_12 ( * V_28 ) ;
( * V_28 ) += 4 ;
break;
case V_68 :
case V_69 :
case V_70 :
V_32 = F_8 ( * V_28 ) ;
( * V_28 ) += 2 ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_32 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
break;
}
return V_32 ;
}
static T_1 F_17 ( T_2 * V_3 , int V_34 , T_3 V_27 ,
int * V_28 , T_1 * V_29 , int V_30 )
{
return F_7 ( V_3 ,
V_34 | V_81 [ ( V_27 >> 3 ) &
7 ] [ ( V_27 >> 6 ) & 3 ] << 3 ,
V_28 , V_29 , V_30 ) ;
}
static void F_18 ( T_2 * V_3 , int V_34 , T_3 V_27 , int * V_28 )
{
F_14 ( V_3 ,
V_34 | V_81 [ ( V_27 >> 3 ) & 7 ] [ ( V_27 >> 6 ) &
3 ] << 3 , V_28 ) ;
}
static void F_19 ( T_2 * V_3 , int V_34 , T_3 V_27 ,
int * V_28 , T_1 V_32 , T_1 V_29 )
{
T_1 V_33 =
V_81 [ ( V_27 >> 3 ) & 7 ] [ ( V_27 >> 6 ) & 3 ] , V_82 =
V_32 , V_31 ;
struct V_2 * V_35 = V_3 -> V_3 ;
V_82 &= V_79 [ V_33 ] >> V_80 [ V_33 ] ;
V_32 <<= V_80 [ V_33 ] ;
V_32 &= V_79 [ V_33 ] ;
V_29 &= ~ V_79 [ V_33 ] ;
V_32 |= V_29 ;
switch ( V_34 ) {
case V_36 :
V_31 = F_8 ( * V_28 ) ;
( * V_28 ) += 2 ;
F_9 ( L_3 , V_31 ) ;
V_31 += V_35 -> V_37 ;
switch ( V_35 -> V_38 ) {
case V_39 :
if ( V_31 == 0 )
V_35 -> V_9 -> V_83 ( V_35 -> V_9 , V_31 ,
V_32 << 2 ) ;
else
V_35 -> V_9 -> V_83 ( V_35 -> V_9 , V_31 , V_32 ) ;
break;
case V_41 :
F_6 ( L_4 ) ;
return;
case V_42 :
F_6 ( L_5 ) ;
return;
default:
if ( ! ( V_35 -> V_38 & 0x80 ) ) {
F_6 ( L_6 ) ;
return;
}
if ( ! V_35 -> V_43 [ V_35 -> V_38 & 0xFF ] ) {
F_6 ( L_27 ,
V_35 -> V_38 & 0x7F ) ;
return;
}
F_3 ( V_35 , V_35 -> V_43 [ V_35 -> V_38 & 0xFF ] ,
V_31 , V_32 ) ;
}
break;
case V_44 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
F_9 ( L_28 , V_31 ) ;
V_3 -> V_46 [ V_31 ] = F_20 ( V_32 ) ;
break;
case V_47 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
F_9 ( L_9 , V_31 ) ;
switch ( V_31 ) {
case V_48 :
V_35 -> V_49 [ 0 ] = V_32 ;
break;
case V_50 :
V_35 -> V_49 [ 1 ] = V_32 ;
break;
case V_51 :
V_35 -> V_52 = V_32 ;
break;
case V_53 :
V_35 -> V_54 = V_32 ;
break;
case V_55 :
case V_56 :
break;
case V_57 :
V_35 -> V_58 = V_32 ;
break;
case V_59 :
V_35 -> V_25 = V_32 ;
break;
case V_60 :
V_35 -> V_37 = V_32 ;
break;
default:
V_3 -> V_61 [ V_31 ] = V_32 ;
}
break;
case V_63 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
if ( ( V_35 -> V_58 + ( V_31 * 4 ) ) > V_35 -> V_64 ) {
F_13 ( L_29 ,
V_35 -> V_58 + ( V_31 * 4 ) , V_35 -> V_64 ) ;
} else
V_35 -> V_65 [ ( V_35 -> V_58 / 4 ) + V_31 ] = V_32 ;
F_9 ( L_13 , V_31 ) ;
break;
case V_75 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
F_9 ( L_17 , V_31 ) ;
V_35 -> V_9 -> V_84 ( V_35 -> V_9 , V_31 , V_32 ) ;
break;
case V_77 :
V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
F_9 ( L_18 , V_31 ) ;
V_35 -> V_9 -> V_85 ( V_35 -> V_9 , V_31 , V_32 ) ;
return;
}
switch ( V_33 ) {
case V_67 :
F_9 ( L_30 , V_82 ) ;
break;
case V_68 :
F_9 ( L_31 , V_82 ) ;
break;
case V_69 :
F_9 ( L_32 , V_82 ) ;
break;
case V_70 :
F_9 ( L_33 , V_82 ) ;
break;
case V_71 :
F_9 ( L_34 , V_82 ) ;
break;
case V_72 :
F_9 ( L_35 , V_82 ) ;
break;
case V_73 :
F_9 ( L_36 , V_82 ) ;
break;
case V_74 :
F_9 ( L_37 , V_82 ) ;
break;
}
}
static void F_21 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 , V_29 ;
int V_88 = * V_28 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_86 += V_87 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_23 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 , V_29 ;
int V_88 = * V_28 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_86 &= V_87 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_24 ( T_2 * V_3 , int * V_28 , int V_34 )
{
F_2 ( L_40 ) ;
}
static void F_25 ( T_2 * V_3 , int * V_28 , int V_34 )
{
int V_31 = F_10 ( ( * V_28 ) ++ ) ;
int V_89 = 0 ;
if ( V_31 < V_90 )
F_22 ( L_41 , V_31 , V_91 [ V_31 ] ) ;
else
F_22 ( L_42 , V_31 ) ;
if ( F_8 ( V_3 -> V_3 -> V_92 + 4 + 2 * V_31 ) )
V_89 = F_26 ( V_3 -> V_3 , V_31 , V_3 -> V_46 + V_3 -> V_93 ) ;
if ( V_89 ) {
V_3 -> abort = true ;
}
}
static void F_27 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_29 ;
int V_88 = * V_28 ;
V_27 &= 0x38 ;
V_27 |= V_94 [ V_27 >> 3 ] << 6 ;
F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 0 ) ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , 0 , V_29 ) ;
}
static void F_28 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 ;
F_22 ( L_43 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , NULL , 1 ) ;
F_22 ( L_44 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_3 -> V_3 -> V_95 = ( V_86 == V_87 ) ;
V_3 -> V_3 -> V_96 = ( V_86 > V_87 ) ;
F_22 ( L_45 , V_3 -> V_3 -> V_95 ? L_46 : L_47 ,
V_3 -> V_3 -> V_96 ? L_48 : L_49 ) ;
}
static void F_29 ( T_2 * V_3 , int * V_28 , int V_34 )
{
unsigned V_97 = F_10 ( ( * V_28 ) ++ ) ;
F_22 ( L_50 , V_97 ) ;
if ( V_34 == V_98 )
F_30 ( V_97 ) ;
else if ( ! F_31 () )
F_32 ( V_97 ) ;
else
F_33 ( V_97 ) ;
}
static void F_34 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 ;
F_22 ( L_43 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , NULL , 1 ) ;
F_22 ( L_44 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
if ( V_87 != 0 ) {
V_3 -> V_3 -> V_49 [ 0 ] = V_86 / V_87 ;
V_3 -> V_3 -> V_49 [ 1 ] = V_86 % V_87 ;
} else {
V_3 -> V_3 -> V_49 [ 0 ] = 0 ;
V_3 -> V_3 -> V_49 [ 1 ] = 0 ;
}
}
static void F_35 ( T_2 * V_3 , int * V_28 , int V_34 )
{
}
static void F_36 ( T_2 * V_3 , int * V_28 , int V_34 )
{
int V_99 = 0 , V_100 = F_8 ( * V_28 ) ;
unsigned long V_101 ;
( * V_28 ) += 2 ;
switch ( V_34 ) {
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
if ( V_34 != V_104 )
F_22 ( L_51 , V_99 ? L_52 : L_53 ) ;
F_22 ( L_54 , V_100 ) ;
if ( V_99 ) {
if ( V_3 -> V_109 == ( V_3 -> V_110 + V_100 ) ) {
V_101 = V_111 ;
if ( F_37 ( V_101 , V_3 -> V_112 ) ) {
V_101 -= V_3 -> V_112 ;
if ( ( F_38 ( V_101 ) > 5000 ) ) {
F_13 ( L_55 ) ;
V_3 -> abort = true ;
}
} else {
V_3 -> V_112 = V_111 ;
}
} else {
V_3 -> V_109 = V_3 -> V_110 + V_100 ;
V_3 -> V_112 = V_111 ;
}
* V_28 = V_3 -> V_110 + V_100 ;
}
}
static void F_39 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_113 , V_87 , V_29 ;
int V_88 = * V_28 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
V_113 = F_16 ( V_3 , ( ( V_27 >> 3 ) & 7 ) , V_28 ) ;
F_22 ( L_56 , V_113 ) ;
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_86 &= V_113 ;
V_86 |= V_87 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_40 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_87 , V_29 ;
int V_88 = * V_28 ;
if ( ( ( V_27 >> 3 ) & 7 ) != V_67 )
F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 0 ) ;
else {
F_18 ( V_3 , V_34 , V_27 , V_28 ) ;
V_29 = 0xCDCDCDCD ;
}
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_87 , V_29 ) ;
}
static void F_41 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 ;
F_22 ( L_43 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , NULL , 1 ) ;
F_22 ( L_44 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_3 -> V_3 -> V_49 [ 0 ] = V_86 * V_87 ;
}
static void F_42 ( T_2 * V_3 , int * V_28 , int V_34 )
{
}
static void F_43 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 , V_29 ;
int V_88 = * V_28 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_86 |= V_87 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_44 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_32 = F_10 ( ( * V_28 ) ++ ) ;
F_22 ( L_57 , V_32 ) ;
}
static void F_45 ( T_2 * V_3 , int * V_28 , int V_34 )
{
F_6 ( L_58 ) ;
}
static void F_46 ( T_2 * V_3 , int * V_28 , int V_34 )
{
F_6 ( L_58 ) ;
}
static void F_47 ( T_2 * V_3 , int * V_28 , int V_34 )
{
F_6 ( L_58 ) ;
}
static void F_48 ( T_2 * V_3 , int * V_28 , int V_34 )
{
int V_31 = F_10 ( * V_28 ) ;
( * V_28 ) ++ ;
F_22 ( L_59 , V_31 ) ;
if ( ! V_31 )
V_3 -> V_3 -> V_52 = 0 ;
else if ( V_31 == 255 )
V_3 -> V_3 -> V_52 = V_3 -> V_110 ;
else
V_3 -> V_3 -> V_52 = F_8 ( V_3 -> V_3 -> V_114 + 4 + 2 * V_31 ) ;
F_22 ( L_60 , V_3 -> V_3 -> V_52 ) ;
}
static void F_49 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
F_22 ( L_61 ) ;
V_3 -> V_3 -> V_58 = F_15 ( V_3 , V_27 , V_28 ) ;
}
static void F_50 ( T_2 * V_3 , int * V_28 , int V_34 )
{
int V_115 ;
switch ( V_34 ) {
case V_116 :
V_115 = F_8 ( * V_28 ) ;
if ( V_115 < V_117 )
F_22 ( L_62 , V_115 , V_118 [ V_115 ] ) ;
else
F_22 ( L_63 , V_115 ) ;
if ( ! V_115 )
V_3 -> V_3 -> V_38 = V_39 ;
else
V_3 -> V_3 -> V_38 = V_119 | V_115 ;
( * V_28 ) += 2 ;
break;
case V_120 :
V_3 -> V_3 -> V_38 = V_41 ;
( * V_28 ) ++ ;
break;
case V_121 :
V_3 -> V_3 -> V_38 = V_42 ;
( * V_28 ) ++ ;
break;
}
}
static void F_51 ( T_2 * V_3 , int * V_28 , int V_34 )
{
V_3 -> V_3 -> V_37 = F_8 ( * V_28 ) ;
( * V_28 ) += 2 ;
F_22 ( L_60 , V_3 -> V_3 -> V_37 ) ;
}
static void F_52 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) , V_54 ;
T_1 V_29 , V_86 ;
int V_88 = * V_28 ;
V_27 &= 0x38 ;
V_27 |= V_94 [ V_27 >> 3 ] << 6 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
V_54 = F_16 ( V_3 , V_71 , V_28 ) ;
F_22 ( L_64 , V_54 ) ;
V_86 <<= V_54 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_53 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) , V_54 ;
T_1 V_29 , V_86 ;
int V_88 = * V_28 ;
V_27 &= 0x38 ;
V_27 |= V_94 [ V_27 >> 3 ] << 6 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
V_54 = F_16 ( V_3 , V_71 , V_28 ) ;
F_22 ( L_64 , V_54 ) ;
V_86 >>= V_54 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_54 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) , V_54 ;
T_1 V_29 , V_86 ;
int V_88 = * V_28 ;
T_1 V_122 = V_81 [ ( V_27 >> 3 ) & 7 ] [ ( V_27 >> 6 ) & 3 ] ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
V_86 = V_29 ;
V_54 = F_15 ( V_3 , V_27 , V_28 ) ;
F_22 ( L_64 , V_54 ) ;
V_86 <<= V_54 ;
V_86 &= V_79 [ V_122 ] ;
V_86 >>= V_80 [ V_122 ] ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_55 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) , V_54 ;
T_1 V_29 , V_86 ;
int V_88 = * V_28 ;
T_1 V_122 = V_81 [ ( V_27 >> 3 ) & 7 ] [ ( V_27 >> 6 ) & 3 ] ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
V_86 = V_29 ;
V_54 = F_15 ( V_3 , V_27 , V_28 ) ;
F_22 ( L_64 , V_54 ) ;
V_86 >>= V_54 ;
V_86 &= V_79 [ V_122 ] ;
V_86 >>= V_80 [ V_122 ] ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_56 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 , V_29 ;
int V_88 = * V_28 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_86 -= V_87 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_57 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_87 , V_32 , V_100 ;
F_22 ( L_65 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
while ( F_8 ( * V_28 ) != V_123 )
if ( F_10 ( * V_28 ) == V_124 ) {
( * V_28 ) ++ ;
F_22 ( L_66 ) ;
V_32 =
F_15 ( V_3 , ( V_27 & 0x38 ) | V_66 ,
V_28 ) ;
V_100 = F_8 ( * V_28 ) ;
if ( V_32 == V_87 ) {
F_22 ( L_67 , V_100 ) ;
* V_28 = V_3 -> V_110 + V_100 ;
return;
}
( * V_28 ) += 2 ;
} else {
F_6 ( L_68 ) ;
return;
}
( * V_28 ) += 2 ;
}
static void F_58 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 ;
F_22 ( L_43 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , NULL , 1 ) ;
F_22 ( L_44 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_3 -> V_3 -> V_95 = ( ( V_86 & V_87 ) == 0 ) ;
F_22 ( L_69 , V_3 -> V_3 -> V_95 ? L_46 : L_47 ) ;
}
static void F_59 ( T_2 * V_3 , int * V_28 , int V_34 )
{
T_3 V_27 = F_10 ( ( * V_28 ) ++ ) ;
T_1 V_86 , V_87 , V_29 ;
int V_88 = * V_28 ;
F_22 ( L_38 ) ;
V_86 = F_17 ( V_3 , V_34 , V_27 , V_28 , & V_29 , 1 ) ;
F_22 ( L_39 ) ;
V_87 = F_15 ( V_3 , V_27 , V_28 ) ;
V_86 ^= V_87 ;
F_22 ( L_38 ) ;
F_19 ( V_3 , V_34 , V_27 , & V_88 , V_86 , V_29 ) ;
}
static void F_60 ( T_2 * V_3 , int * V_28 , int V_34 )
{
F_6 ( L_58 ) ;
}
static int F_26 ( struct V_2 * V_3 , int V_5 , T_1 * V_125 )
{
int V_4 = F_5 ( V_3 -> V_92 + 4 + 2 * V_5 ) ;
int V_126 , V_61 , V_46 , V_28 ;
unsigned char V_127 ;
T_2 V_128 ;
int V_129 = 0 ;
if ( ! V_4 )
return - V_130 ;
V_126 = F_5 ( V_4 + V_131 ) ;
V_61 = F_4 ( V_4 + V_132 ) ;
V_46 = F_4 ( V_4 + V_133 ) & V_134 ;
V_28 = V_4 + V_135 ;
F_22 ( L_70 , V_4 , V_126 , V_61 , V_46 ) ;
V_128 . V_3 = V_3 ;
V_128 . V_93 = V_46 / 4 ;
V_128 . V_110 = V_4 ;
V_128 . V_46 = V_125 ;
V_128 . abort = false ;
V_128 . V_109 = 0 ;
if ( V_61 )
V_128 . V_61 = F_61 ( 4 * V_61 , V_136 ) ;
else
V_128 . V_61 = NULL ;
V_137 ++ ;
while ( 1 ) {
V_127 = F_4 ( V_28 ++ ) ;
if ( V_127 < V_138 )
F_22 ( L_71 , V_139 [ V_127 ] , V_28 - 1 ) ;
else
F_22 ( L_72 , V_127 , V_28 - 1 ) ;
if ( V_128 . abort ) {
F_13 ( L_73 ,
V_4 , V_126 , V_61 , V_46 , V_28 - 1 ) ;
V_129 = - V_130 ;
goto free;
}
if ( V_127 < V_140 && V_127 > 0 )
V_141 [ V_127 ] . F_62 ( & V_128 , & V_28 ,
V_141 [ V_127 ] . V_34 ) ;
else
break;
if ( V_127 == V_142 )
break;
}
V_137 -- ;
F_22 ( L_74 ) ;
free:
if ( V_61 )
F_63 ( V_128 . V_61 ) ;
return V_129 ;
}
int F_64 ( struct V_2 * V_3 , int V_5 , T_1 * V_125 )
{
int V_89 ;
F_65 ( & V_3 -> V_143 ) ;
V_3 -> V_52 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_58 = 0 ;
V_3 -> V_38 = V_39 ;
V_3 -> V_49 [ 0 ] = 0 ;
V_3 -> V_49 [ 1 ] = 0 ;
V_89 = F_26 ( V_3 , V_5 , V_125 ) ;
F_66 ( & V_3 -> V_143 ) ;
return V_89 ;
}
int F_67 ( struct V_2 * V_3 , int V_5 , T_1 * V_125 )
{
int V_89 ;
F_65 ( & V_3 -> V_144 ) ;
V_89 = F_64 ( V_3 , V_5 , V_125 ) ;
F_66 ( & V_3 -> V_144 ) ;
return V_89 ;
}
static void F_68 ( struct V_2 * V_3 , int V_4 )
{
V_3 -> V_43 = F_61 ( 2 * 256 , V_136 ) ;
if ( ! V_3 -> V_43 )
return;
while ( F_4 ( V_4 ) == V_145 ) {
V_3 -> V_43 [ F_4 ( V_4 + 1 ) ] = V_4 + 2 ;
V_4 += 2 ;
while ( F_4 ( V_4 ) != V_26 )
V_4 += V_146 [ F_4 ( V_4 ) ] ;
V_4 += 3 ;
}
}
struct V_2 * F_69 ( struct V_147 * V_9 , void * V_148 )
{
int V_4 ;
struct V_2 * V_3 =
F_61 ( sizeof( struct V_2 ) , V_136 ) ;
char * V_149 ;
char V_150 [ 512 ] ;
int V_151 ;
if ( ! V_3 )
return NULL ;
V_3 -> V_9 = V_9 ;
V_3 -> V_148 = V_148 ;
if ( F_5 ( 0 ) != V_152 ) {
F_6 ( L_75 ) ;
F_63 ( V_3 ) ;
return NULL ;
}
if ( strncmp
( F_70 ( V_153 ) , V_154 ,
strlen ( V_154 ) ) ) {
F_6 ( L_76 ) ;
F_63 ( V_3 ) ;
return NULL ;
}
V_4 = F_5 ( V_155 ) ;
if ( strncmp
( F_70 ( V_4 + V_156 ) , V_157 ,
strlen ( V_157 ) ) ) {
F_6 ( L_77 ) ;
F_63 ( V_3 ) ;
return NULL ;
}
V_3 -> V_92 = F_5 ( V_4 + V_158 ) ;
V_3 -> V_114 = F_5 ( V_4 + V_159 ) ;
F_68 ( V_3 , F_5 ( V_3 -> V_114 + V_160 ) + 4 ) ;
if ( ! V_3 -> V_43 ) {
F_71 ( V_3 ) ;
return NULL ;
}
V_149 = F_70 ( F_5 ( V_4 + V_161 ) ) ;
while ( * V_149 && ( ( * V_149 == '\n' ) || ( * V_149 == '\r' ) ) )
V_149 ++ ;
for ( V_151 = 0 ; V_151 < 511 ; V_151 ++ ) {
V_150 [ V_151 ] = V_149 [ V_151 ] ;
if ( V_150 [ V_151 ] < '.' || V_150 [ V_151 ] > 'z' ) {
V_150 [ V_151 ] = 0 ;
break;
}
}
F_6 ( L_78 , V_150 ) ;
return V_3 ;
}
int F_72 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 -> V_10 -> V_11 ;
int V_162 = F_5 ( V_3 -> V_114 + V_163 ) ;
T_1 V_46 [ 16 ] ;
int V_129 ;
memset ( V_46 , 0 , 64 ) ;
V_46 [ 0 ] = F_20 ( F_73 ( V_162 + V_164 ) ) ;
V_46 [ 1 ] = F_20 ( F_73 ( V_162 + V_165 ) ) ;
if ( ! V_46 [ 0 ] || ! V_46 [ 1 ] )
return 1 ;
if ( ! F_5 ( V_3 -> V_92 + 4 + 2 * V_166 ) )
return 1 ;
V_129 = F_67 ( V_3 , V_166 , V_46 ) ;
if ( V_129 )
return V_129 ;
memset ( V_46 , 0 , 64 ) ;
if ( V_8 -> V_17 < V_167 ) {
if ( F_5 ( V_3 -> V_92 + 4 + 2 * V_168 ) )
F_67 ( V_3 , V_168 , V_46 ) ;
}
return V_129 ;
}
void F_71 ( struct V_2 * V_3 )
{
F_63 ( V_3 -> V_43 ) ;
F_63 ( V_3 ) ;
}
bool F_74 ( struct V_2 * V_3 , int V_5 ,
T_4 * V_169 , T_3 * V_170 , T_3 * V_171 ,
T_4 * V_172 )
{
int V_173 = V_5 * 2 + 4 ;
int V_31 = F_5 ( V_3 -> V_114 + V_173 ) ;
T_5 * V_174 = ( T_5 * ) ( V_3 -> V_148 + V_3 -> V_114 + 4 ) ;
if ( ! V_174 [ V_5 ] )
return false ;
if ( V_169 )
* V_169 = F_5 ( V_31 ) ;
if ( V_170 )
* V_170 = F_4 ( V_31 + 2 ) ;
if ( V_171 )
* V_171 = F_4 ( V_31 + 3 ) ;
* V_172 = V_31 ;
return true ;
}
bool F_75 ( struct V_2 * V_3 , int V_5 , T_3 * V_170 ,
T_3 * V_171 )
{
int V_173 = V_5 * 2 + 4 ;
int V_31 = F_5 ( V_3 -> V_92 + V_173 ) ;
T_5 * V_175 = ( T_5 * ) ( V_3 -> V_148 + V_3 -> V_92 + 4 ) ;
if ( ! V_175 [ V_5 ] )
return false ;
if ( V_170 )
* V_170 = F_4 ( V_31 + 2 ) ;
if ( V_171 )
* V_171 = F_4 ( V_31 + 3 ) ;
return true ;
}
int F_76 ( struct V_2 * V_3 )
{
int V_5 = F_77 ( V_176 , V_177 ) ;
T_4 V_178 ;
int V_179 = 0 ;
struct V_180 * V_181 ;
if ( F_74 ( V_3 , V_5 , NULL , NULL , NULL , & V_178 ) ) {
V_181 = (struct V_180 * ) ( V_3 -> V_148 + V_178 ) ;
F_78 ( L_79 ,
F_79 ( V_181 -> V_182 [ 0 ] . V_183 ) ,
F_80 ( V_181 -> V_182 [ 0 ] . V_184 ) ) ;
V_179 = F_80 ( V_181 -> V_182 [ 0 ] . V_184 ) * 1024 ;
}
V_3 -> V_64 = 0 ;
if ( V_179 == 0 )
V_179 = 20 * 1024 ;
V_3 -> V_65 = F_61 ( V_179 , V_136 ) ;
if ( ! V_3 -> V_65 )
return - V_185 ;
V_3 -> V_64 = V_179 ;
return 0 ;
}
