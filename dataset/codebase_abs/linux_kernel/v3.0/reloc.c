T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 , int V_4 ,
int V_5 , unsigned V_6 )
{
register T_1 V_7 ;
register int V_8 , V_9 ;
register T_2 * V_10 = V_3 ;
V_4 -= 1 ;
if ( V_11 ) {
V_10 += ( V_4 + V_5 ) >> V_12 ;
V_9 = - 1 ;
} else
V_9 = 1 ;
V_7 = * V_10 >> V_5 ;
V_8 = V_13 - V_5 ;
while ( V_8 <= V_4 ) {
V_10 += V_9 ;
V_7 += ( T_1 ) * V_10 << V_8 ;
V_8 += V_13 ;
}
if ( V_6 == V_14 )
V_7 &= ( 2 << V_4 ) - 1 ;
else {
V_8 = sizeof( T_1 ) * V_15 - 1 - V_4 ;
V_7 = ( V_7 << V_8 ) >> V_8 ;
}
return V_7 ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_16 , T_2 * V_3 ,
int V_4 , int V_5 , unsigned V_6 )
{
register T_3 V_7 , V_17 ;
register int V_8 , V_9 ;
register T_2 * V_10 = V_3 ;
V_4 -= 1 ;
V_17 = ( 2UL << V_4 ) - 1 ;
V_7 = ( V_16 & V_17 ) ;
if ( V_11 ) {
V_10 += ( V_4 + V_5 ) >> V_12 ;
V_9 = - 1 ;
} else
V_9 = 1 ;
* V_10 = ( * V_10 & ~ ( V_17 << V_5 ) ) + ( V_7 << V_5 ) ;
V_8 = V_13 - V_5 ;
V_7 >>= V_8 ;
V_17 >>= V_8 ;
while ( V_17 ) {
V_10 += V_9 ;
* V_10 = ( * V_10 & ~ V_17 ) + V_7 ;
V_7 >>= V_13 ;
V_17 >>= V_13 ;
}
if ( V_6 ) {
unsigned V_18 = ( V_16 >> V_4 ) + ( V_6 & 0x1 ) ;
if ( V_18 > V_19 [ V_6 - 1 ] )
return 1 ;
}
return 0 ;
}
void F_3 ( struct V_1 * V_2 , T_2 * V_3 ,
struct V_20 * V_21 , bool * V_22 ,
bool V_23 )
{
T_1 V_16 , V_24 , V_25 = 0 ;
unsigned int V_4 = 0 ;
unsigned int V_5 = 0 ;
unsigned int V_26 = 0 ;
unsigned int V_27 = 0 ;
register int V_28 = 0 ;
T_1 * V_29 = NULL ;
int V_30 ;
struct V_31 * V_32 = NULL ;
#ifdef F_4
unsigned int V_33 = 0 ;
#endif
struct V_34 * V_35 = NULL ;
if ( V_23 == false )
V_35 = (struct V_34 * ) ( ( V_36 * ) V_3 -
sizeof( struct
V_34 ) ) ;
V_28 = F_5 ( V_21 -> TYPE ) ;
while ( V_37 [ V_28 ] != V_21 -> TYPE ) {
V_28 = F_6 ( V_38 [ V_28 ] ) ;
if ( V_28 < 0 ) {
#if V_39
switch ( V_21 -> TYPE ) {
case V_40 :
case V_41 :
case V_42 :
break;
default:
F_7 ( V_2 , L_1 ,
V_21 -> TYPE ) ;
}
#else
F_7 ( V_2 , L_1 , V_21 -> TYPE ) ;
#endif
return;
}
}
V_28 = F_8 ( V_38 [ V_28 ] ) ;
if ( ( V_28 < ( sizeof( V_43 ) / sizeof( V_44 ) ) )
&& ( V_28 < ( sizeof( V_45 ) / sizeof( V_44 ) ) ) && ( V_28 > 0 ) ) {
V_27 = V_43 [ V_28 ] ;
V_26 = V_45 [ V_28 ] ;
} else {
F_7 ( V_2 , L_2
L_3 ) ;
}
V_24 = V_21 -> V_46 ;
if ( F_9 ( V_26 ) ) {
if ( V_23 == false ) {
if ( ( V_47 ) V_21 -> V_48 < V_2 -> V_49 . V_50 ) {
V_32 = & V_2 -> V_51 [ V_21 -> V_48 ] ;
V_24 = ( F_9 ( V_26 ) == V_52 ) ?
V_32 -> V_53 : V_32 -> V_54 ;
}
else if ( V_21 -> V_48 == - 1 ) {
V_24 = ( F_9 ( V_26 ) == V_52 ) ?
V_2 -> V_55 :
V_2 -> V_56 -> V_57 ;
}
}
}
V_16 = 0 ;
V_30 = F_10 ( V_26 ) ;
if ( V_30 ) {
V_30 += V_2 -> V_58 - V_59 ;
if ( V_30 >= V_60 ) {
F_7 ( V_2 ,
L_4
V_61 , V_2 -> V_56 -> V_62 ,
V_21 -> V_63 + V_2 -> V_64 ) ;
return;
}
V_16 = V_2 -> V_65 [ V_2 -> V_58 ] ;
V_2 -> V_58 = V_30 ;
V_29 = & V_2 -> V_65 [ V_30 ] ;
}
if ( V_26 & V_66 ) {
V_4 = F_11 ( V_27 ) ;
if ( V_4 ) {
V_5 = F_12 ( V_27 ) ;
if ( V_11 )
V_21 -> V_63 += F_13 ( V_26 ) ;
} else {
V_4 = V_21 -> V_67 ;
V_5 = V_21 -> V_68 ;
if ( V_11 )
V_21 -> V_63 += ( V_21 -> V_69 - V_5 - V_4 )
>> V_70 ;
}
V_3 = ( T_2 * ) ( ( char * ) V_3 + F_14 ( V_21 -> V_63 ) ) ;
#if V_15 > V_71
if ( V_11 ) {
V_5 += - ( ( V_21 -> V_63 << V_70 ) +
V_5 + V_4 ) &
( V_15 - V_71 ) ;
} else {
V_5 += ( V_21 -> V_63 << V_70 ) &
( V_15 - 1 ) ;
}
#endif
#ifdef F_4
V_33 = F_4 ( V_26 ) ;
#endif
}
if ( V_26 & V_72 ) {
V_16 = F_1 ( V_2 , V_3 , V_4 , V_5 ,
F_15 ( V_26 ) ) ;
V_25 = V_16 ;
#ifdef F_4
V_16 <<= V_33 ;
#endif
}
switch ( F_16 ( V_27 ) ) {
case V_73 :
break;
case V_74 :
V_16 = V_24 ;
break;
case V_75 :
V_16 += V_24 ;
break;
case V_76 :
if ( V_21 -> V_48 == - 1 )
V_24 = 0 ;
V_16 += V_24 - V_2 -> V_55 ;
break;
case V_77 :
V_16 += V_21 -> V_78 + V_24 ;
break;
case V_79 :
V_16 = V_2 -> V_56 -> V_57 + V_24 ;
break;
case V_80 :
if ( V_29 != NULL )
V_16 += * V_29 ;
break;
case V_81 :
if ( V_29 != NULL )
V_16 = * V_29 - V_16 ;
break;
case V_82 :
V_16 = - V_16 ;
break;
case V_83 :
if ( V_29 != NULL )
V_16 *= * V_29 ;
break;
case V_84 :
if ( V_29 != NULL )
V_16 = * V_29 / V_16 ;
break;
case V_85 :
if ( V_29 != NULL )
V_16 = * V_29 % V_16 ;
break;
case V_86 :
if ( V_16 >= sizeof( T_1 ) * V_15 )
V_16 = 0 ;
else if ( V_29 != NULL )
V_16 = ( T_3 ) * V_29 >> V_16 ;
break;
case V_87 :
if ( V_16 >= sizeof( T_1 ) * V_15 )
V_16 = sizeof( T_1 ) * V_15 - 1 ;
else if ( V_29 != NULL )
V_16 = * V_29 >> V_16 ;
break;
case V_88 :
if ( V_16 >= sizeof( T_1 ) * V_15 )
V_16 = 0 ;
else if ( V_29 != NULL )
V_16 = * V_29 << V_16 ;
break;
case V_89 :
if ( V_29 != NULL )
V_16 &= * V_29 ;
break;
case V_90 :
if ( V_29 != NULL )
V_16 |= * V_29 ;
break;
case V_91 :
if ( V_29 != NULL )
V_16 ^= * V_29 ;
break;
case V_92 :
V_16 = ~ V_16 ;
break;
#if V_39
case V_93 :
if ( V_32 != NULL ) {
if ( V_21 -> V_48 >= 0 )
if ( V_32 -> V_94 > 0 )
V_24 = V_2 -> V_95
[ V_32 -> V_94 - 1 ] . V_57 ;
}
case V_96 :
if ( V_2 -> V_97 == 0 ) {
struct V_98 * V_99 ;
V_99 = V_2 -> V_100 -> V_101
( V_2 -> V_100 , V_102 ) ;
if ( V_99 )
V_2 -> V_97 = V_99 -> V_54 ;
else
F_7 ( V_2 ,
L_5
L_6 V_61 L_7
L_8 ,
V_2 -> V_56 -> V_62 ,
V_21 -> V_63 + V_2 -> V_64 ) ;
}
V_24 -= V_2 -> V_97 ;
case V_103 :
V_33 = V_104 [ V_16 & V_105 ] ;
V_5 += V_106 ;
V_4 -= V_106 ;
V_16 >>= V_106 ;
V_16 <<= V_33 ;
V_16 += V_24 ;
if ( ( ( 1 << V_33 ) - 1 ) & V_16 )
F_7 ( V_2 ,
L_9
V_61 , V_2 -> V_56 -> V_62 ,
V_21 -> V_63 + V_2 -> V_64 ) ;
break;
#endif
}
if ( V_26 & V_107 ) {
#ifdef F_4
V_16 >>= V_33 ;
#endif
if ( F_2 ( V_2 , V_16 , V_3 , V_4 , V_5 ,
F_15 ( V_26 ) ) ) {
if ( ( V_23 == false ) &&
( F_17 ( V_2 , V_21 ) == true ) ) {
F_2 ( V_2 , V_25 , V_3 , V_4 ,
V_5 , F_15 ( V_26 ) ) ;
if ( ! F_18 ( V_2 ,
( V_2 -> V_56 -
V_2 -> V_95 ) ,
V_2 -> V_64 ,
V_35 , V_21 ) ) {
F_7 ( V_2 ,
L_10
L_11
L_12 ) ;
F_7 ( V_2 ,
L_13 V_61
L_14
L_15 V_61 , V_16 ,
V_4 ,
V_2 -> V_56 -> V_62 ,
V_2 -> V_64 +
V_21 -> V_63 ) ;
} else
* V_22 = true ;
} else {
F_7 ( V_2 , L_16
V_61 L_17
L_18 V_61 , V_16 , V_4 ,
V_2 -> V_56 -> V_62 ,
V_2 -> V_64 + V_21 -> V_63 ) ;
}
}
} else if ( V_30 )
* V_29 = V_16 ;
}
