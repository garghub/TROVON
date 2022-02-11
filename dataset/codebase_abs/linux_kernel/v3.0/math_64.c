static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 () -> V_5 [ 0 ] ;
int V_6 ;
V_6 = ( V_4 & ( ( long ) V_3 << V_7 ) ) != 0UL ;
if( V_6 != 0 ) {
V_3 &= ( ( V_4 & V_8 ) >> V_7 ) ;
if( ( V_3 & ( V_3 - 1 ) ) != 0 ) {
if( V_3 & V_9 )
V_3 = V_9 ;
else if( V_3 & V_10 )
V_3 = V_10 ;
else if( V_3 & V_11 )
V_3 = V_11 ;
else if( V_3 & V_12 )
V_3 = V_12 ;
else if( V_3 & V_13 )
V_3 = V_13 ;
}
}
V_4 &= ~ ( V_14 ) ;
V_4 |= ( ( long ) V_3 << V_15 ) ;
if( V_6 == 0 )
V_4 |= ( ( long ) V_3 << V_16 ) ;
if( V_6 != 0 )
V_4 |= ( 1UL << 14 ) ;
F_2 () -> V_5 [ 0 ] = V_4 ;
if( V_6 == 0 ) {
V_2 -> V_17 = V_2 -> V_18 ;
V_2 -> V_18 += 4 ;
}
return ( V_6 ? 0 : 1 ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
unsigned long V_21 = V_2 -> V_17 ;
unsigned long V_22 = V_2 -> V_22 ;
T_2 V_23 = 0 ;
int type = 0 ;
#define TYPE ( T_3 , T_4 , T_5 , T_6 , T_7 , T_8 , T_9 ) type = (au << 2) | (a << 0) | (bu << 5) | (b << 3) | (ru << 8) | (r << 6) | (ftt << 9)
int V_24 ;
static T_1 V_25 [ 2 ] = { 0L , 0L } ;
int V_26 ;
V_27 ;
F_4 ( V_28 ) ; F_4 ( V_29 ) ; F_4 ( V_30 ) ;
F_5 ( V_31 ) ; F_5 ( V_32 ) ; F_5 ( V_33 ) ;
F_6 ( V_34 ) ; F_6 ( V_35 ) ; F_6 ( V_36 ) ;
int V_37 ;
long V_38 , V_5 ;
if ( V_22 & V_39 )
F_7 ( L_1 , V_2 ) ;
F_8 ( V_40 , 1 , 0 , V_2 , 0 ) ;
if ( F_9 ( V_41 ) )
V_21 = ( T_2 ) V_21 ;
if ( F_10 ( V_23 , ( T_2 V_42 * ) V_21 ) != - V_43 ) {
if ( ( V_23 & 0xc1f80000 ) == 0x81a00000 ) {
switch ( ( V_23 >> 5 ) & 0x1ff ) {
case V_44 :
case V_45 :
case V_46 : TYPE ( 3 , 3 , 0 , 3 , 0 , 0 , 0 ) ; break;
case V_47 : TYPE ( 3 , 3 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_48 :
case V_49 :
case V_50 :
case V_51 : TYPE ( 3 , 3 , 1 , 3 , 1 , 3 , 1 ) ; break;
case V_52 : TYPE ( 3 , 3 , 1 , 2 , 1 , 2 , 1 ) ; break;
case V_53 : TYPE ( 3 , 2 , 0 , 3 , 1 , 0 , 0 ) ; break;
case V_54 : TYPE ( 3 , 3 , 1 , 2 , 0 , 0 , 0 ) ; break;
case V_55 : TYPE ( 3 , 1 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_56 : TYPE ( 3 , 2 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_57 : TYPE ( 3 , 3 , 1 , 1 , 0 , 0 , 0 ) ; break;
case V_58 : TYPE ( 3 , 3 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_59 : TYPE ( 3 , 3 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_60 : TYPE ( 3 , 1 , 0 , 3 , 1 , 0 , 0 ) ; break;
case V_61 : {
unsigned long V_62 = F_2 () -> V_5 [ 0 ] ;
V_62 = ( V_62 >> 14 ) & 0xf ;
TYPE ( V_62 , 1 , 1 , 1 , 1 , 0 , 0 ) ;
break;
}
case V_63 : {
unsigned long V_62 = F_2 () -> V_5 [ 0 ] ;
V_62 = ( V_62 >> 14 ) & 0xf ;
TYPE ( V_62 , 2 , 1 , 2 , 1 , 0 , 0 ) ;
break;
}
case V_64 :
case V_65 :
case V_66 :
case V_67 : TYPE ( 2 , 2 , 1 , 2 , 1 , 2 , 1 ) ; break;
case V_68 :
case V_69 :
case V_70 :
case V_71 : TYPE ( 2 , 1 , 1 , 1 , 1 , 1 , 1 ) ; break;
case V_72 : TYPE ( 2 , 2 , 1 , 1 , 1 , 1 , 1 ) ; break;
case V_73 : TYPE ( 2 , 2 , 0 , 1 , 1 , 0 , 0 ) ; break;
case V_74 : TYPE ( 2 , 2 , 0 , 2 , 1 , 0 , 0 ) ; break;
case V_75 : TYPE ( 2 , 1 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_76 : TYPE ( 2 , 2 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_77 : TYPE ( 2 , 1 , 0 , 1 , 1 , 0 , 0 ) ; break;
case V_78 : TYPE ( 2 , 1 , 0 , 2 , 1 , 0 , 0 ) ; break;
case V_79 : TYPE ( 2 , 1 , 1 , 2 , 0 , 0 , 0 ) ; break;
case V_80 : TYPE ( 2 , 2 , 1 , 2 , 0 , 0 , 0 ) ; break;
#if 0
case FITOS: TYPE(2,1,1,1,0,0,0); break;
#endif
case V_81 : TYPE ( 2 , 2 , 1 , 1 , 0 , 0 , 0 ) ; break;
}
}
else if ( ( V_23 & 0xc1f80000 ) == 0x81a80000 ) {
V_37 = 2 ;
switch ( ( V_23 >> 5 ) & 0x1ff ) {
case V_82 : TYPE ( 3 , 0 , 0 , 3 , 1 , 3 , 1 ) ; break;
case V_83 : TYPE ( 3 , 0 , 0 , 3 , 1 , 3 , 1 ) ; break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
if ( ! ( ( V_23 >> 11 ) & 3 ) )
V_38 = F_2 () -> V_5 [ 0 ] >> 10 ;
else
V_38 = F_2 () -> V_5 [ 0 ] >> ( 30 + ( ( V_23 >> 10 ) & 0x6 ) ) ;
V_38 &= 3 ;
V_37 = 0 ;
switch ( ( V_23 >> 14 ) & 0x7 ) {
case 1 : if ( V_38 ) V_37 = 1 ; break;
case 2 : if ( V_38 == 1 || V_38 == 2 ) V_37 = 1 ; break;
case 3 : if ( V_38 & 1 ) V_37 = 1 ; break;
case 4 : if ( V_38 == 1 ) V_37 = 1 ; break;
case 5 : if ( V_38 & 2 ) V_37 = 1 ; break;
case 6 : if ( V_38 == 2 ) V_37 = 1 ; break;
case 7 : if ( V_38 == 3 ) V_37 = 1 ; break;
}
if ( ( V_23 >> 14 ) & 8 )
V_37 ^= 1 ;
break;
case V_88 :
case V_89 :
V_38 = V_2 -> V_22 >> 32 ;
if ( ( V_23 >> 5 ) & 0x80 )
V_38 >>= 4 ;
V_38 &= 0xf ;
V_37 = 0 ;
V_24 = ( ( V_38 >> 2 ) ^ V_38 ) & 2 ;
switch ( ( V_23 >> 14 ) & 0x7 ) {
case 1 : if ( V_38 & 4 ) V_37 = 1 ; break;
case 2 : if ( ( V_38 & 4 ) || V_24 ) V_37 = 1 ; break;
case 3 : if ( V_24 ) V_37 = 1 ; break;
case 4 : if ( V_38 & 5 ) V_37 = 1 ; break;
case 5 : if ( V_38 & 1 ) V_37 = 1 ; break;
case 6 : if ( V_38 & 8 ) V_37 = 1 ; break;
case 7 : if ( V_38 & 2 ) V_37 = 1 ; break;
}
if ( ( V_23 >> 14 ) & 8 )
V_37 ^= 1 ;
break;
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_24 = ( V_23 >> 14 ) & 0x1f ;
if ( ! V_24 )
V_38 = 0 ;
else if ( V_24 < 16 )
V_38 = V_2 -> V_96 [ V_24 ] ;
else if ( F_9 ( V_41 ) ) {
struct V_97 V_42 * V_98 ;
F_11 () ;
V_98 = (struct V_97 V_42 * ) ( ( unsigned long ) ( ( T_2 ) V_2 -> V_96 [ V_99 ] ) ) ;
F_10 ( V_38 , & V_98 -> V_100 [ V_24 - 16 ] ) ;
} else {
struct V_101 V_42 * V_102 ;
F_11 () ;
V_102 = (struct V_101 V_42 * ) ( V_2 -> V_96 [ V_99 ] + V_103 ) ;
F_10 ( V_38 , & V_102 -> V_100 [ V_24 - 16 ] ) ;
}
V_37 = 0 ;
switch ( ( V_23 >> 10 ) & 3 ) {
case 1 : if ( ! V_38 ) V_37 = 1 ; break;
case 2 : if ( V_38 <= 0 ) V_37 = 1 ; break;
case 3 : if ( V_38 < 0 ) V_37 = 1 ; break;
}
if ( ( V_23 >> 10 ) & 4 )
V_37 ^= 1 ;
break;
}
if ( V_37 == 0 ) {
F_2 () -> V_5 [ 0 ] &= ~ ( V_14 ) ;
V_2 -> V_17 = V_2 -> V_18 ;
V_2 -> V_18 += 4 ;
return 1 ;
} else if ( V_37 == 1 ) {
V_23 = ( V_23 & 0x3e00001f ) | 0x81a00060 ;
TYPE ( 3 , 3 , 0 , 3 , 0 , 0 , 0 ) ;
}
}
}
if ( type ) {
T_10 V_104 = NULL , V_105 = NULL , V_106 = NULL ;
V_24 = ( F_2 () -> V_5 [ 0 ] >> 14 ) & 0xf ;
if ( V_24 != ( type >> 9 ) )
goto V_107;
F_2 () -> V_5 [ 0 ] &= ~ 0x1c000 ;
V_24 = ( ( V_23 >> 14 ) & 0x1f ) ;
switch ( type & 0x3 ) {
case 3 : if ( V_24 & 2 ) {
F_2 () -> V_5 [ 0 ] |= ( 6 << 14 ) ;
goto V_107;
}
case 2 : V_24 = ( ( V_24 & 1 ) << 5 ) | ( V_24 & 0x1e ) ;
case 1 : V_104 = ( T_10 ) & V_20 -> V_2 [ V_24 ] ;
V_26 = ( V_24 < 32 ) ? V_108 : V_109 ;
if ( ! ( F_2 () -> V_110 [ 0 ] & V_26 ) )
V_104 = ( T_10 ) & V_25 ;
break;
}
switch ( type & 0x7 ) {
case 7 : F_12 ( V_34 , V_104 ) ; break;
case 6 : F_13 ( V_31 , V_104 ) ; break;
case 5 : F_14 ( V_28 , V_104 ) ; break;
}
V_24 = ( V_23 & 0x1f ) ;
switch ( ( type >> 3 ) & 0x3 ) {
case 3 : if ( V_24 & 2 ) {
F_2 () -> V_5 [ 0 ] |= ( 6 << 14 ) ;
goto V_107;
}
case 2 : V_24 = ( ( V_24 & 1 ) << 5 ) | ( V_24 & 0x1e ) ;
case 1 : V_105 = ( T_10 ) & V_20 -> V_2 [ V_24 ] ;
V_26 = ( V_24 < 32 ) ? V_108 : V_109 ;
if ( ! ( F_2 () -> V_110 [ 0 ] & V_26 ) )
V_105 = ( T_10 ) & V_25 ;
break;
}
switch ( ( type >> 3 ) & 0x7 ) {
case 7 : F_12 ( V_35 , V_105 ) ; break;
case 6 : F_13 ( V_32 , V_105 ) ; break;
case 5 : F_14 ( V_29 , V_105 ) ; break;
}
V_24 = ( ( V_23 >> 25 ) & 0x1f ) ;
switch ( ( type >> 6 ) & 0x3 ) {
case 3 : if ( V_24 & 2 ) {
F_2 () -> V_5 [ 0 ] |= ( 6 << 14 ) ;
goto V_107;
}
case 2 : V_24 = ( ( V_24 & 1 ) << 5 ) | ( V_24 & 0x1e ) ;
case 1 : V_106 = ( T_10 ) & V_20 -> V_2 [ V_24 ] ;
V_26 = ( V_24 < 32 ) ? V_108 : V_109 ;
if ( ! ( F_2 () -> V_110 [ 0 ] & V_111 ) ) {
F_2 () -> V_110 [ 0 ] = V_111 ;
F_2 () -> V_112 [ 0 ] = 0 ;
}
if ( ! ( F_2 () -> V_110 [ 0 ] & V_26 ) ) {
if ( V_24 < 32 )
memset ( V_20 -> V_2 , 0 , 32 * sizeof( T_2 ) ) ;
else
memset ( V_20 -> V_2 + 32 , 0 , 32 * sizeof( T_2 ) ) ;
}
F_2 () -> V_110 [ 0 ] |= V_26 ;
break;
}
switch ( ( V_23 >> 5 ) & 0x1ff ) {
case V_68 : F_15 ( V_30 , V_28 , V_29 ) ; break;
case V_64 : F_16 ( V_33 , V_31 , V_32 ) ; break;
case V_48 : F_17 ( V_36 , V_34 , V_35 ) ; break;
case V_69 : F_18 ( V_30 , V_28 , V_29 ) ; break;
case V_65 : F_19 ( V_33 , V_31 , V_32 ) ; break;
case V_49 : F_20 ( V_36 , V_34 , V_35 ) ; break;
case V_70 : F_21 ( V_30 , V_28 , V_29 ) ; break;
case V_72 : F_22 ( V_113 , V_114 , 1 , 1 , V_31 , V_28 ) ;
F_22 ( V_113 , V_114 , 1 , 1 , V_32 , V_29 ) ;
case V_66 : F_23 ( V_33 , V_31 , V_32 ) ; break;
case V_52 : F_22 ( V_115 , V_113 , 2 , 1 , V_34 , V_31 ) ;
F_22 ( V_115 , V_113 , 2 , 1 , V_35 , V_32 ) ;
case V_50 : F_24 ( V_36 , V_34 , V_35 ) ; break;
case V_71 : F_25 ( V_30 , V_28 , V_29 ) ; break;
case V_67 : F_26 ( V_33 , V_31 , V_32 ) ; break;
case V_51 : F_27 ( V_36 , V_34 , V_35 ) ; break;
case V_61 : F_28 ( V_30 , V_29 ) ; break;
case V_63 : F_29 ( V_33 , V_32 ) ; break;
case V_47 : F_30 ( V_36 , V_35 ) ; break;
case V_44 : V_106 -> V_116 [ 0 ] = V_105 -> V_116 [ 0 ] ; V_106 -> V_116 [ 1 ] = V_105 -> V_116 [ 1 ] ; break;
case V_46 : V_106 -> V_116 [ 0 ] = V_105 -> V_116 [ 0 ] & 0x7fffffffffffffffUL ; V_106 -> V_116 [ 1 ] = V_105 -> V_116 [ 1 ] ; break;
case V_45 : V_106 -> V_116 [ 0 ] = V_105 -> V_116 [ 0 ] ^ 0x8000000000000000UL ; V_106 -> V_116 [ 1 ] = V_105 -> V_116 [ 1 ] ; break;
case V_77 : F_31 ( V_37 , V_29 , 32 , 1 ) ; break;
case V_78 : F_32 ( V_37 , V_32 , 32 , 1 ) ; break;
case V_60 : F_33 ( V_37 , V_35 , 32 , 1 ) ; break;
case V_73 : F_31 ( V_38 , V_29 , 64 , 1 ) ; break;
case V_74 : F_32 ( V_38 , V_32 , 64 , 1 ) ; break;
case V_53 : F_33 ( V_38 , V_35 , 64 , 1 ) ; break;
case V_57 : V_37 = V_105 -> V_117 ; F_34 ( V_36 , V_37 , 32 , int ) ; break;
case V_54 : V_38 = V_105 -> V_118 ; F_34 ( V_36 , V_38 , 64 , long ) ; break;
case V_79 : V_38 = V_105 -> V_118 ; F_35 ( V_30 , V_38 , 64 , long ) ; break;
case V_80 : V_38 = V_105 -> V_118 ; F_36 ( V_33 , V_38 , 64 , long ) ; break;
#if 0
case FITOS: IR = rs2->s; FP_FROM_INT_S (SR, IR, 32, int); break;
#endif
case V_81 : V_37 = V_105 -> V_117 ; F_36 ( V_33 , V_37 , 32 , int ) ; break;
case V_76 : F_22 ( V_113 , V_114 , 1 , 1 , V_33 , V_29 ) ; break;
case V_58 : F_22 ( V_115 , V_114 , 2 , 1 , V_36 , V_29 ) ; break;
case V_59 : F_22 ( V_115 , V_113 , 2 , 1 , V_36 , V_32 ) ; break;
case V_75 : F_22 ( V_114 , V_113 , 1 , 1 , V_30 , V_32 ) ; break;
case V_55 : F_22 ( V_114 , V_115 , 1 , 2 , V_30 , V_35 ) ; break;
case V_56 : F_22 ( V_113 , V_115 , 1 , 2 , V_33 , V_35 ) ; break;
case V_82 :
case V_83 :
F_37 ( V_38 , V_35 , V_34 , 3 ) ;
if ( V_38 == 3 &&
( ( ( V_23 >> 5 ) & 0x1ff ) == V_83 ||
F_38 ( V_34 ) ||
F_38 ( V_35 ) ) )
F_39 ( V_9 ) ;
}
if ( ! V_119 ) {
switch ( ( type >> 6 ) & 0x7 ) {
case 0 : V_5 = F_2 () -> V_5 [ 0 ] ;
if ( V_38 == - 1 ) V_38 = 2 ;
switch ( V_24 & 3 ) {
case 0 : V_5 &= ~ 0xc00 ; V_5 |= ( V_38 << 10 ) ; break;
case 1 : V_5 &= ~ 0x300000000UL ; V_5 |= ( V_38 << 32 ) ; break;
case 2 : V_5 &= ~ 0xc00000000UL ; V_5 |= ( V_38 << 34 ) ; break;
case 3 : V_5 &= ~ 0x3000000000UL ; V_5 |= ( V_38 << 36 ) ; break;
}
F_2 () -> V_5 [ 0 ] = V_5 ;
break;
case 1 : V_106 -> V_117 = V_37 ; break;
case 2 : V_106 -> V_118 = V_38 ; break;
case 5 : F_40 ( V_106 , V_30 ) ; break;
case 6 : F_41 ( V_106 , V_33 ) ; break;
case 7 : F_42 ( V_106 , V_36 ) ; break;
}
}
if( V_120 != 0 )
return F_1 ( V_2 , V_120 ) ;
F_2 () -> V_5 [ 0 ] &= ~ ( V_14 ) ;
V_2 -> V_17 = V_2 -> V_18 ;
V_2 -> V_18 += 4 ;
return 1 ;
}
V_107: return 0 ;
}
