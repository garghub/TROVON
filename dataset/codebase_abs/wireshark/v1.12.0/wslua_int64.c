static T_1 F_1 ( T_2 * V_1 , int V_2 )
{
T_3 * V_3 = NULL ;
( void ) V_3 ;
switch ( F_2 ( V_1 , V_2 ) )
{
case V_4 :
return F_3 ( V_1 , V_2 ) ;
case V_5 :
return F_4 ( F_5 ( V_1 , V_2 ) , & V_3 , 10 ) ;
case V_6 :
if ( F_6 ( V_1 , V_2 ) ) {
return ( V_7 ) F_7 ( V_1 , V_2 ) ;
}
default:
return F_8 ( V_1 , V_2 ) ;
}
}
void F_9 ( T_2 * V_1 , T_4 * V_8 , T_5 V_9 , T_6 V_10 ) {
T_1 V_11 = F_8 ( V_1 , V_9 ) ;
T_7 V_12 [ sizeof( T_1 ) ] ;
if ( V_10 ) {
T_8 V_2 ;
for ( V_2 = 0 ; V_2 < sizeof( T_1 ) ; V_2 ++ ) {
V_12 [ V_2 ] = ( V_11 & 0xff ) ;
V_11 >>= 8 ;
}
}
else {
T_5 V_2 ;
for ( V_2 = sizeof( T_1 ) - 1 ; V_2 >= 0 ; V_2 -- ) {
V_12 [ V_2 ] = ( V_11 & 0xff ) ;
V_11 >>= 8 ;
}
}
F_10 ( V_8 , ( char * ) V_12 , sizeof( T_1 ) ) ;
}
T_9 F_11 ( T_2 * V_1 ) {
#define F_12 2
T_4 V_8 ;
T_6 V_10 = ( V_13 == V_14 ) ? TRUE : FALSE ;
if ( F_13 ( V_1 ) >= F_12 ) {
if ( F_2 ( V_1 , F_12 ) == V_15 )
V_10 = F_14 ( V_1 , F_12 ) ;
}
F_15 ( V_1 , & V_8 ) ;
F_9 ( V_1 , & V_8 , 1 , V_10 ) ;
F_16 ( & V_8 ) ;
F_17 ( 1 ) ;
}
int F_18 ( T_2 * V_1 , const T_3 * V_12 , T_6 V_10 ) {
T_1 V_11 = 0 ;
T_5 V_2 ;
if ( V_10 ) {
for ( V_2 = sizeof( T_1 ) - 1 ; V_2 >= 0 ; V_2 -- ) {
V_11 <<= 8 ;
V_11 |= ( T_1 ) ( V_16 ) V_12 [ V_2 ] ;
}
}
else {
for ( V_2 = 0 ; V_2 < ( T_5 ) sizeof( T_1 ) ; V_2 ++ ) {
V_11 <<= 8 ;
V_11 |= ( T_1 ) ( V_16 ) V_12 [ V_2 ] ;
}
}
F_19 ( V_1 , V_11 ) ;
return 1 ;
}
T_10 F_20 ( T_2 * V_1 ) {
#define F_21 1
#define F_22 2
T_6 V_10 = ( V_13 == V_14 ) ? TRUE : FALSE ;
T_11 V_17 = 0 ;
const T_3 * V_18 = F_23 ( V_1 , F_21 , & V_17 ) ;
if ( F_13 ( V_1 ) >= F_22 ) {
if ( F_2 ( V_1 , F_22 ) == V_15 )
V_10 = F_14 ( V_1 , F_22 ) ;
}
if ( V_17 == sizeof( T_1 ) ) {
F_18 ( V_1 , V_18 , V_10 ) ;
} else {
F_24 ( V_1 ) ;
}
F_17 ( 1 ) ;
}
T_10 F_25 ( T_2 * V_1 ) {
#define F_26 1
#define F_27 2
T_1 V_11 = 0 ;
if ( F_13 ( V_1 ) >= 1 ) {
switch( F_2 ( V_1 , F_26 ) ) {
case V_4 :
V_11 = F_28 ( V_1 , F_26 ) ;
if ( F_13 ( V_1 ) == 2 &&
F_2 ( V_1 , F_27 ) == V_4 ) {
T_1 V_19 = F_28 ( V_1 , F_27 ) ;
V_11 &= F_29 ( 0x00000000FFFFFFFF ) ;
V_19 <<= 32 ; V_19 &= F_29 ( 0xFFFFFFFF00000000 ) ;
V_11 += V_19 ;
}
break;
case V_5 :
case V_6 :
V_11 = F_1 ( V_1 , F_26 ) ;
break;
default:
F_30 ( F_25 , V_20 , L_1 ) ;
break;
}
}
F_19 ( V_1 , V_11 ) ;
F_17 ( 1 ) ;
}
T_12 F_31 ( T_2 * V_1 ) {
F_32 ( V_1 , 1 ) ;
F_17 ( F_25 ( V_1 ) ) ;
}
T_10 F_33 ( T_2 * V_1 ) {
F_19 ( V_1 , V_21 ) ;
F_17 ( 1 ) ;
}
T_10 F_34 ( T_2 * V_1 ) {
F_19 ( V_1 , V_22 ) ;
F_17 ( 1 ) ;
}
T_9 F_35 ( T_2 * V_1 ) {
F_36 ( V_1 , ( V_23 ) ( F_8 ( V_1 , 1 ) ) ) ;
F_17 ( 1 ) ;
}
T_10 F_37 ( T_2 * V_1 ) {
#define F_38 1
T_13 V_24 = 0 ;
T_11 V_17 = 0 ;
const T_3 * V_18 = F_23 ( V_1 , F_38 , & V_17 ) ;
if ( V_18 && V_17 > 0 ) {
sscanf ( V_18 , L_2 V_25 L_3 , & V_24 ) ;
}
F_19 ( V_1 , ( T_1 ) V_24 ) ;
F_17 ( 1 ) ;
}
T_9 F_39 ( T_2 * V_1 ) {
#define F_40 2
T_1 V_8 = F_1 ( V_1 , 1 ) ;
T_5 V_26 = F_41 ( V_1 , F_40 , 16 ) ;
const T_3 * V_27 = L_4 ;
T_3 V_28 [ 16 ] ;
T_5 V_2 ;
if ( V_26 < 0 ) { V_26 = - V_26 ; V_27 = L_5 ; }
if ( V_26 > 16 ) V_26 = 16 ;
for ( V_2 = V_26 - 1 ; V_2 >= 0 ; -- V_2 ) { V_28 [ V_2 ] = V_27 [ V_8 & 15 ] ; V_8 >>= 4 ; }
F_42 ( V_1 , V_28 , ( T_11 ) V_26 ) ;
F_17 ( 1 ) ;
}
T_9 F_43 ( T_2 * V_1 ) {
T_1 V_29 = F_1 ( V_1 , 1 ) ;
T_1 V_8 = V_29 ;
V_23 V_26 = 0 ;
if ( V_8 < 0 ) V_8 = - V_8 ;
V_8 &= F_29 ( 0x7FFFFFFF00000000 ) ;
V_8 >>= 32 ;
V_26 = ( V_23 ) ( V_30 ) ( V_8 & F_29 ( 0x00000000FFFFFFFFF ) ) ;
if ( V_29 < 0 ) V_26 = - V_26 ;
F_36 ( V_1 , V_26 ) ;
F_17 ( 1 ) ;
}
T_9 F_44 ( T_2 * V_1 ) {
T_1 V_8 = F_1 ( V_1 , 1 ) ;
if ( V_8 < 0 ) V_8 = - V_8 ;
F_36 ( V_1 , ( V_30 ) ( V_8 & F_29 ( 0x00000000FFFFFFFFF ) ) ) ;
F_17 ( 1 ) ;
}
T_12 F_45 ( T_2 * V_1 ) {
T_1 V_29 = F_1 ( V_1 , 1 ) ;
T_3 V_18 [ V_31 ] ;
if ( F_46 ( V_18 , V_31 , L_2 V_25 L_6 , V_29 ) < 0 ) {
return F_47 ( V_1 , L_7 ) ;
}
F_48 ( V_1 , V_18 ) ;
F_17 ( 1 ) ;
}
T_12 F_49 ( T_2 * V_1 ) {
F_19 ( V_1 , - ( F_1 ( V_1 , 1 ) ) ) ;
F_17 ( 1 ) ;
}
T_12 F_50 ( T_2 * V_1 ) {
F_51 ( V_7 , + ) ;
}
T_12 F_52 ( T_2 * V_1 ) {
F_51 ( V_7 , - ) ;
}
T_12 F_53 ( T_2 * V_1 ) {
F_51 ( V_7 , * ) ;
}
T_12 F_54 ( T_2 * V_1 ) {
V_7 V_32 = F_1 ( V_1 , 1 ) ;
V_7 V_33 = F_1 ( V_1 , 2 ) ;
if ( V_33 == 0 ) {
return F_47 ( V_1 , L_8 ) ;
}
F_19 ( V_1 , V_32 / V_33 ) ;
F_17 ( 1 ) ;
}
T_12 F_55 ( T_2 * V_1 ) {
V_7 V_32 = F_1 ( V_1 , 1 ) ;
V_7 V_33 = F_1 ( V_1 , 2 ) ;
if ( V_33 == 0 ) {
return F_47 ( V_1 , L_9 ) ;
}
F_19 ( V_1 , V_32 % V_33 ) ;
F_17 ( 1 ) ;
}
T_12 F_56 ( T_2 * V_1 ) {
T_1 V_32 = F_1 ( V_1 , 1 ) ;
T_1 V_33 = F_1 ( V_1 , 2 ) ;
T_1 V_24 ;
if ( V_32 == 2 ) {
V_24 = ( V_33 >= 8 * ( T_1 ) sizeof( T_1 ) ) ? 0 : ( ( T_1 ) 1 << V_33 ) ;
}
else {
for ( V_24 = 1 ; V_33 > 0 ; V_33 >>= 1 ) {
if ( V_33 & 1 ) V_24 *= V_32 ;
V_32 *= V_32 ;
}
}
F_19 ( V_1 , V_24 ) ;
F_17 ( 1 ) ;
}
T_12 F_57 ( T_2 * V_1 ) {
F_58 ( V_7 , == ) ;
}
T_12 F_59 ( T_2 * V_1 ) {
F_58 ( V_7 , < ) ;
}
T_12 F_60 ( T_2 * V_1 ) {
F_58 ( V_7 , <= ) ;
}
T_9 F_61 ( T_2 * V_1 ) {
F_19 ( V_1 , ~ ( F_1 ( V_1 , 1 ) ) ) ;
F_17 ( 1 ) ;
}
T_9 F_62 ( T_2 * V_1 ) {
F_63 ( V_7 , &= ) ;
F_17 ( 1 ) ;
}
T_9 F_64 ( T_2 * V_1 ) {
F_63 ( V_7 , |= ) ;
F_17 ( 1 ) ;
}
T_9 F_65 ( T_2 * V_1 ) {
F_63 ( V_7 , ^= ) ;
F_17 ( 1 ) ;
}
T_9 F_66 ( T_2 * V_1 ) {
#define F_67 2
T_13 V_8 = ( T_13 ) F_1 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_67 ) ;
F_19 ( V_1 , ( T_1 ) ( V_8 << V_26 ) ) ;
F_17 ( 1 ) ;
}
T_9 F_69 ( T_2 * V_1 ) {
#define F_70 2
T_13 V_8 = ( T_13 ) F_1 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_70 ) ;
F_19 ( V_1 , ( T_1 ) ( V_8 >> V_26 ) ) ;
F_17 ( 1 ) ;
}
T_9 F_71 ( T_2 * V_1 ) {
#define F_72 2
T_1 V_8 = F_1 ( V_1 , 1 ) ;
T_14 V_26 = F_73 ( V_1 , F_72 ) ;
F_19 ( V_1 , ( V_8 >> V_26 ) ) ;
F_17 ( 1 ) ;
}
T_9 F_74 ( T_2 * V_1 ) {
#define F_75 2
T_13 V_8 = ( T_13 ) F_1 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_75 ) ;
F_19 ( V_1 , ( T_1 ) ( ( V_8 << V_26 ) | ( V_8 >> ( 64 - V_26 ) ) ) ) ;
F_17 ( 1 ) ;
}
T_9 F_76 ( T_2 * V_1 ) {
#define F_77 2
T_13 V_8 = ( T_13 ) F_1 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_77 ) ;
F_19 ( V_1 , ( T_1 ) ( ( V_8 << ( 64 - V_26 ) ) | ( V_8 >> V_26 ) ) ) ;
F_17 ( 1 ) ;
}
T_9 F_78 ( T_2 * V_1 ) {
T_13 V_8 = ( T_13 ) F_1 ( V_1 , 1 ) ;
T_13 V_24 = 0 ;
T_11 V_2 ;
for ( V_2 = 0 ; V_2 < sizeof( T_1 ) ; V_2 ++ ) {
V_24 <<= 8 ;
V_24 |= ( V_8 & F_29 ( 0x00000000000000FF ) ) ;
V_8 >>= 8 ;
}
F_19 ( V_1 , ( T_1 ) V_24 ) ;
F_17 ( 1 ) ;
}
static int F_79 ( T_2 * V_1 V_34 ) {
return 0 ;
}
T_15 int F_80 ( T_2 * V_1 ) {
F_81 ( V_7 ) ;
return 0 ;
}
static T_13 F_82 ( T_2 * V_1 , int V_2 )
{
T_3 * V_3 = NULL ;
( void ) V_3 ;
switch ( F_2 ( V_1 , V_2 ) )
{
case V_4 :
return F_83 ( V_1 , V_2 ) ;
case V_5 :
return F_84 ( F_5 ( V_1 , V_2 ) , & V_3 , 10 ) ;
case V_6 :
if ( F_85 ( V_1 , V_2 ) ) {
return ( V_35 ) F_86 ( V_1 , V_2 ) ;
}
default:
return F_87 ( V_1 , V_2 ) ;
}
}
void F_88 ( T_2 * V_1 , T_4 * V_8 , T_5 V_9 , T_6 V_10 ) {
T_13 V_11 = F_87 ( V_1 , V_9 ) ;
T_7 V_12 [ sizeof( T_13 ) ] ;
if ( V_10 ) {
T_8 V_2 ;
for ( V_2 = 0 ; V_2 < sizeof( T_13 ) ; V_2 ++ ) {
V_12 [ V_2 ] = ( V_11 & 0xff ) ;
V_11 >>= 8 ;
}
}
else {
T_5 V_2 ;
for ( V_2 = sizeof( T_13 ) - 1 ; V_2 >= 0 ; V_2 -- ) {
V_12 [ V_2 ] = ( V_11 & 0xff ) ;
V_11 >>= 8 ;
}
}
F_10 ( V_8 , ( char * ) V_12 , sizeof( T_13 ) ) ;
}
T_9 F_89 ( T_2 * V_1 ) {
#define F_90 2
T_4 V_8 ;
T_6 V_10 = ( V_13 == V_14 ) ? TRUE : FALSE ;
if ( F_13 ( V_1 ) >= 2 ) {
if ( F_2 ( V_1 , 2 ) == V_15 )
V_10 = F_14 ( V_1 , 2 ) ;
}
F_15 ( V_1 , & V_8 ) ;
F_88 ( V_1 , & V_8 , 1 , V_10 ) ;
F_16 ( & V_8 ) ;
F_17 ( 1 ) ;
}
int F_91 ( T_2 * V_1 , const T_3 * V_12 , T_6 V_10 ) {
T_13 V_11 = 0 ;
T_5 V_2 ;
if ( V_10 ) {
for ( V_2 = sizeof( T_13 ) - 1 ; V_2 >= 0 ; V_2 -- ) {
V_11 <<= 8 ;
V_11 |= ( T_13 ) ( V_16 ) V_12 [ V_2 ] ;
}
}
else {
for ( V_2 = 0 ; V_2 < ( T_5 ) sizeof( T_13 ) ; V_2 ++ ) {
V_11 <<= 8 ;
V_11 |= ( T_13 ) ( V_16 ) V_12 [ V_2 ] ;
}
}
F_92 ( V_1 , V_11 ) ;
return 1 ;
}
T_10 F_93 ( T_2 * V_1 ) {
#define F_94 1
#define F_95 2
T_6 V_10 = ( V_13 == V_14 ) ? TRUE : FALSE ;
T_11 V_17 = 0 ;
const T_3 * V_18 = F_23 ( V_1 , F_94 , & V_17 ) ;
if ( F_13 ( V_1 ) >= F_95 ) {
if ( F_2 ( V_1 , F_95 ) == V_15 )
V_10 = F_14 ( V_1 , F_95 ) ;
}
if ( V_17 == sizeof( T_13 ) ) {
F_91 ( V_1 , V_18 , V_10 ) ;
} else {
F_24 ( V_1 ) ;
}
F_17 ( 1 ) ;
}
T_10 F_96 ( T_2 * V_1 ) {
#define F_97 1
#define F_98 2
T_13 V_11 = 0 ;
if ( F_13 ( V_1 ) >= 1 ) {
switch( F_2 ( V_1 , F_97 ) ) {
case V_4 :
V_11 = F_99 ( V_1 , F_97 ) ;
if ( F_13 ( V_1 ) == 2 &&
F_2 ( V_1 , F_98 ) == V_4 ) {
T_13 V_19 = F_99 ( V_1 , F_98 ) ;
V_11 &= F_29 ( 0x00000000FFFFFFFF ) ;
V_19 <<= 32 ; V_19 &= F_29 ( 0xFFFFFFFF00000000 ) ;
V_11 += V_19 ;
}
break;
case V_5 :
case V_6 :
V_11 = F_82 ( V_1 , F_97 ) ;
break;
default:
F_30 ( F_96 , V_20 , L_1 ) ;
break;
}
}
F_92 ( V_1 , V_11 ) ;
F_17 ( 1 ) ;
}
T_12 F_100 ( T_2 * V_1 ) {
F_32 ( V_1 , 1 ) ;
F_17 ( F_96 ( V_1 ) ) ;
}
T_10 F_101 ( T_2 * V_1 ) {
F_92 ( V_1 , V_36 ) ;
F_17 ( 1 ) ;
}
T_10 F_102 ( T_2 * V_1 ) {
F_92 ( V_1 , 0 ) ;
F_17 ( 1 ) ;
}
T_9 F_103 ( T_2 * V_1 ) {
F_36 ( V_1 , ( V_23 ) ( F_87 ( V_1 , 1 ) ) ) ;
F_17 ( 1 ) ;
}
T_12 F_104 ( T_2 * V_1 ) {
T_13 V_29 = F_82 ( V_1 , 1 ) ;
T_3 V_18 [ V_31 ] ;
if ( F_46 ( V_18 , V_31 , L_2 V_25 L_10 , ( T_13 ) V_29 ) < 0 ) {
return F_47 ( V_1 , L_11 ) ;
}
F_48 ( V_1 , V_18 ) ;
F_17 ( 1 ) ;
}
T_10 F_105 ( T_2 * V_1 ) {
#define F_106 1
T_13 V_24 = 0 ;
T_11 V_17 = 0 ;
const T_3 * V_18 = F_23 ( V_1 , F_106 , & V_17 ) ;
if ( V_18 && V_17 > 0 ) {
sscanf ( V_18 , L_2 V_25 L_3 , & V_24 ) ;
}
F_92 ( V_1 , V_24 ) ;
F_17 ( 1 ) ;
}
T_9 F_107 ( T_2 * V_1 ) {
#define F_108 2
T_13 V_8 = F_82 ( V_1 , 1 ) ;
T_5 V_26 = F_41 ( V_1 , F_108 , 16 ) ;
const T_3 * V_27 = L_4 ;
T_3 V_28 [ 16 ] ;
T_5 V_2 ;
if ( V_26 < 0 ) { V_26 = - V_26 ; V_27 = L_5 ; }
if ( V_26 > 16 ) V_26 = 16 ;
for ( V_2 = V_26 - 1 ; V_2 >= 0 ; -- V_2 ) { V_28 [ V_2 ] = V_27 [ V_8 & 15 ] ; V_8 >>= 4 ; }
F_42 ( V_1 , V_28 , ( T_11 ) V_26 ) ;
F_17 ( 1 ) ;
}
T_9 F_109 ( T_2 * V_1 ) {
T_13 V_29 = F_82 ( V_1 , 1 ) ;
T_13 V_8 = V_29 ;
V_23 V_26 = 0 ;
V_8 &= F_29 ( 0xFFFFFFFF00000000 ) ;
V_8 >>= 32 ;
V_26 = ( V_23 ) ( V_30 ) ( V_8 & F_29 ( 0x00000000FFFFFFFFF ) ) ;
F_36 ( V_1 , V_26 ) ;
F_17 ( 1 ) ;
}
T_9 F_110 ( T_2 * V_1 ) {
T_13 V_8 = F_82 ( V_1 , 1 ) ;
F_36 ( V_1 , ( V_30 ) ( V_8 & F_29 ( 0x00000000FFFFFFFFF ) ) ) ;
F_17 ( 1 ) ;
}
T_12 F_111 ( T_2 * V_1 ) {
F_92 ( V_1 , F_82 ( V_1 , 1 ) ) ;
F_17 ( 1 ) ;
}
T_12 F_112 ( T_2 * V_1 ) {
F_51 ( V_35 , + ) ;
}
T_12 F_113 ( T_2 * V_1 ) {
F_51 ( V_35 , - ) ;
}
T_12 F_114 ( T_2 * V_1 ) {
F_51 ( V_35 , * ) ;
}
T_12 F_115 ( T_2 * V_1 ) {
V_35 V_32 = F_82 ( V_1 , 1 ) ;
V_35 V_33 = F_82 ( V_1 , 2 ) ;
if ( V_33 == 0 ) {
return F_47 ( V_1 , L_12 ) ;
}
F_92 ( V_1 , V_32 / V_33 ) ;
F_17 ( 1 ) ;
}
T_12 F_116 ( T_2 * V_1 ) {
V_35 V_32 = F_82 ( V_1 , 1 ) ;
V_35 V_33 = F_82 ( V_1 , 2 ) ;
if ( V_33 == 0 ) {
return F_47 ( V_1 , L_13 ) ;
}
F_92 ( V_1 , V_32 % V_33 ) ;
F_17 ( 1 ) ;
}
T_12 F_117 ( T_2 * V_1 ) {
T_13 V_32 = F_82 ( V_1 , 1 ) ;
T_13 V_33 = F_82 ( V_1 , 2 ) ;
T_13 V_24 ;
if ( V_32 == 2 ) {
V_24 = ( V_33 >= 8 * ( T_13 ) sizeof( T_13 ) ) ? 0 : ( ( T_13 ) 1 << V_33 ) ;
}
else {
for ( V_24 = 1 ; V_33 > 0 ; V_33 >>= 1 ) {
if ( V_33 & 1 ) V_24 *= V_32 ;
V_32 *= V_32 ;
}
}
F_92 ( V_1 , V_24 ) ;
F_17 ( 1 ) ;
}
T_12 F_118 ( T_2 * V_1 ) {
F_58 ( V_35 , == ) ;
}
T_12 F_119 ( T_2 * V_1 ) {
F_58 ( V_35 , < ) ;
}
T_12 F_120 ( T_2 * V_1 ) {
F_58 ( V_35 , <= ) ;
}
T_9 F_121 ( T_2 * V_1 ) {
F_92 ( V_1 , ~ ( F_82 ( V_1 , 1 ) ) ) ;
F_17 ( 1 ) ;
}
T_9 F_122 ( T_2 * V_1 ) {
F_63 ( V_35 , &= ) ;
F_17 ( 1 ) ;
}
T_9 F_123 ( T_2 * V_1 ) {
F_63 ( V_35 , |= ) ;
F_17 ( 1 ) ;
}
T_9 F_124 ( T_2 * V_1 ) {
F_63 ( V_35 , ^= ) ;
F_17 ( 1 ) ;
}
T_9 F_125 ( T_2 * V_1 ) {
#define F_126 2
T_13 V_8 = F_82 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_126 ) ;
F_92 ( V_1 , ( V_8 << V_26 ) ) ;
F_17 ( 1 ) ;
}
T_9 F_127 ( T_2 * V_1 ) {
#define F_128 2
T_13 V_8 = F_82 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_128 ) ;
F_92 ( V_1 , ( V_8 >> V_26 ) ) ;
F_17 ( 1 ) ;
}
T_9 F_129 ( T_2 * V_1 ) {
#define F_130 2
T_13 V_8 = F_82 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_130 ) ;
F_92 ( V_1 , ( V_8 >> V_26 ) ) ;
F_17 ( 1 ) ;
}
T_9 F_131 ( T_2 * V_1 ) {
#define F_132 2
T_13 V_8 = F_82 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_132 ) ;
F_92 ( V_1 , ( ( V_8 << V_26 ) | ( V_8 >> ( 64 - V_26 ) ) ) ) ;
F_17 ( 1 ) ;
}
T_9 F_133 ( T_2 * V_1 ) {
#define F_134 2
T_13 V_8 = F_82 ( V_1 , 1 ) ;
V_30 V_26 = F_68 ( V_1 , F_134 ) ;
F_92 ( V_1 , ( ( V_8 << ( 64 - V_26 ) ) | ( V_8 >> V_26 ) ) ) ;
F_17 ( 1 ) ;
}
T_9 F_135 ( T_2 * V_1 ) {
T_13 V_8 = F_82 ( V_1 , 1 ) ;
T_13 V_24 = 0 ;
T_11 V_2 ;
for ( V_2 = 0 ; V_2 < sizeof( T_13 ) ; V_2 ++ ) {
V_24 <<= 8 ;
V_24 |= ( V_8 & F_29 ( 0x00000000000000FF ) ) ;
V_8 >>= 8 ;
}
F_92 ( V_1 , V_24 ) ;
F_17 ( 1 ) ;
}
static int F_136 ( T_2 * V_1 V_34 ) {
return 0 ;
}
T_15 int F_137 ( T_2 * V_1 ) {
F_81 ( V_35 ) ;
return 0 ;
}
