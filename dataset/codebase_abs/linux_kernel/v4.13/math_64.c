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
int F_3 ( struct V_1 * V_2 , struct V_19 * V_20 , bool V_21 )
{
unsigned long V_22 = V_2 -> V_17 ;
unsigned long V_23 = V_2 -> V_23 ;
T_2 V_24 = 0 ;
int type = 0 ;
#define TYPE ( T_3 , T_4 , T_5 , T_6 , T_7 , T_8 , T_9 ) type = (au << 2) | (a << 0) | (bu << 5) | (b << 3) | (ru << 8) | (r << 6) | (ftt << 9)
int V_25 ;
static T_1 V_26 [ 2 ] = { 0L , 0L } ;
int V_27 ;
V_28 ;
F_4 ( V_29 ) ; F_4 ( V_30 ) ; F_4 ( V_31 ) ;
F_5 ( V_32 ) ; F_5 ( V_33 ) ; F_5 ( V_34 ) ;
F_6 ( V_35 ) ; F_6 ( V_36 ) ; F_6 ( V_37 ) ;
int V_38 ;
long V_39 , V_5 ;
if ( V_23 & V_40 )
F_7 ( L_1 , V_2 ) ;
F_8 ( V_41 , 1 , V_2 , 0 ) ;
if ( F_9 ( V_42 ) )
V_22 = ( T_2 ) V_22 ;
if ( F_10 ( V_24 , ( T_2 V_43 * ) V_22 ) != - V_44 ) {
if ( ( V_24 & 0xc1f80000 ) == 0x81a00000 ) {
switch ( ( V_24 >> 5 ) & 0x1ff ) {
case V_45 :
case V_46 :
case V_47 : TYPE ( 3 , 3 , 0 , 3 , 0 , 0 , 0 ) ; break;
case V_48 : TYPE ( 3 , 3 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_49 :
case V_50 :
case V_51 :
case V_52 : TYPE ( 3 , 3 , 1 , 3 , 1 , 3 , 1 ) ; break;
case V_53 : TYPE ( 3 , 3 , 1 , 2 , 1 , 2 , 1 ) ; break;
case V_54 : TYPE ( 3 , 2 , 0 , 3 , 1 , 0 , 0 ) ; break;
case V_55 : TYPE ( 3 , 3 , 1 , 2 , 0 , 0 , 0 ) ; break;
case V_56 : TYPE ( 3 , 1 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_57 : TYPE ( 3 , 2 , 1 , 3 , 1 , 0 , 0 ) ; break;
case V_58 : TYPE ( 3 , 3 , 1 , 1 , 0 , 0 , 0 ) ; break;
case V_59 : TYPE ( 3 , 3 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_60 : TYPE ( 3 , 3 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_61 : TYPE ( 3 , 1 , 0 , 3 , 1 , 0 , 0 ) ; break;
case V_62 : {
unsigned long V_63 = F_2 () -> V_5 [ 0 ] ;
V_63 = ( V_63 >> 14 ) & 0x7 ;
TYPE ( V_63 , 1 , 1 , 1 , 1 , 0 , 0 ) ;
break;
}
case V_64 : {
unsigned long V_63 = F_2 () -> V_5 [ 0 ] ;
V_63 = ( V_63 >> 14 ) & 0x7 ;
TYPE ( V_63 , 2 , 1 , 2 , 1 , 0 , 0 ) ;
break;
}
case V_65 :
case V_66 :
case V_67 :
case V_68 : TYPE ( 2 , 2 , 1 , 2 , 1 , 2 , 1 ) ; break;
case V_69 :
case V_70 :
case V_71 :
case V_72 : TYPE ( 2 , 1 , 1 , 1 , 1 , 1 , 1 ) ; break;
case V_73 : TYPE ( 2 , 2 , 1 , 1 , 1 , 1 , 1 ) ; break;
case V_74 : TYPE ( 2 , 2 , 0 , 1 , 1 , 0 , 0 ) ; break;
case V_75 : TYPE ( 2 , 2 , 0 , 2 , 1 , 0 , 0 ) ; break;
case V_76 : TYPE ( 2 , 1 , 1 , 2 , 1 , 0 , 0 ) ; break;
case V_77 : TYPE ( 2 , 2 , 1 , 1 , 1 , 0 , 0 ) ; break;
case V_78 : TYPE ( 2 , 1 , 0 , 1 , 1 , 0 , 0 ) ; break;
case V_79 : TYPE ( 2 , 1 , 0 , 2 , 1 , 0 , 0 ) ; break;
case V_80 : TYPE ( 2 , 1 , 1 , 2 , 0 , 0 , 0 ) ; break;
case V_81 : TYPE ( 2 , 2 , 1 , 2 , 0 , 0 , 0 ) ; break;
#if 0
case FITOS: TYPE(2,1,1,1,0,0,0); break;
#endif
case V_82 : TYPE ( 2 , 2 , 1 , 1 , 0 , 0 , 0 ) ; break;
}
}
else if ( ( V_24 & 0xc1f80000 ) == 0x81a80000 ) {
V_38 = 2 ;
switch ( ( V_24 >> 5 ) & 0x1ff ) {
case V_83 : TYPE ( 3 , 0 , 0 , 3 , 1 , 3 , 1 ) ; break;
case V_84 : TYPE ( 3 , 0 , 0 , 3 , 1 , 3 , 1 ) ; break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
if ( ! ( ( V_24 >> 11 ) & 3 ) )
V_39 = F_2 () -> V_5 [ 0 ] >> 10 ;
else
V_39 = F_2 () -> V_5 [ 0 ] >> ( 30 + ( ( V_24 >> 10 ) & 0x6 ) ) ;
V_39 &= 3 ;
V_38 = 0 ;
switch ( ( V_24 >> 14 ) & 0x7 ) {
case 1 : if ( V_39 ) V_38 = 1 ; break;
case 2 : if ( V_39 == 1 || V_39 == 2 ) V_38 = 1 ; break;
case 3 : if ( V_39 & 1 ) V_38 = 1 ; break;
case 4 : if ( V_39 == 1 ) V_38 = 1 ; break;
case 5 : if ( V_39 & 2 ) V_38 = 1 ; break;
case 6 : if ( V_39 == 2 ) V_38 = 1 ; break;
case 7 : if ( V_39 == 3 ) V_38 = 1 ; break;
}
if ( ( V_24 >> 14 ) & 8 )
V_38 ^= 1 ;
break;
case V_89 :
case V_90 :
V_39 = V_2 -> V_23 >> 32 ;
if ( ( V_24 >> 5 ) & 0x80 )
V_39 >>= 4 ;
V_39 &= 0xf ;
V_38 = 0 ;
V_25 = ( ( V_39 >> 2 ) ^ V_39 ) & 2 ;
switch ( ( V_24 >> 14 ) & 0x7 ) {
case 1 : if ( V_39 & 4 ) V_38 = 1 ; break;
case 2 : if ( ( V_39 & 4 ) || V_25 ) V_38 = 1 ; break;
case 3 : if ( V_25 ) V_38 = 1 ; break;
case 4 : if ( V_39 & 5 ) V_38 = 1 ; break;
case 5 : if ( V_39 & 1 ) V_38 = 1 ; break;
case 6 : if ( V_39 & 8 ) V_38 = 1 ; break;
case 7 : if ( V_39 & 2 ) V_38 = 1 ; break;
}
if ( ( V_24 >> 14 ) & 8 )
V_38 ^= 1 ;
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
V_25 = ( V_24 >> 14 ) & 0x1f ;
if ( ! V_25 )
V_39 = 0 ;
else if ( V_25 < 16 )
V_39 = V_2 -> V_97 [ V_25 ] ;
else if ( ! F_11 ( V_2 -> V_97 [ V_98 ] ) ) {
struct V_99 V_43 * V_100 ;
F_12 () ;
V_100 = (struct V_99 V_43 * ) ( ( unsigned long ) ( ( T_2 ) V_2 -> V_97 [ V_98 ] ) ) ;
F_10 ( V_39 , & V_100 -> V_101 [ V_25 - 16 ] ) ;
} else {
struct V_102 V_43 * V_103 ;
F_12 () ;
V_103 = (struct V_102 V_43 * ) ( V_2 -> V_97 [ V_98 ] + V_104 ) ;
F_10 ( V_39 , & V_103 -> V_101 [ V_25 - 16 ] ) ;
}
V_38 = 0 ;
switch ( ( V_24 >> 10 ) & 3 ) {
case 1 : if ( ! V_39 ) V_38 = 1 ; break;
case 2 : if ( V_39 <= 0 ) V_38 = 1 ; break;
case 3 : if ( V_39 < 0 ) V_38 = 1 ; break;
}
if ( ( V_24 >> 10 ) & 4 )
V_38 ^= 1 ;
break;
}
if ( V_38 == 0 ) {
F_2 () -> V_5 [ 0 ] &= ~ ( V_14 ) ;
V_2 -> V_17 = V_2 -> V_18 ;
V_2 -> V_18 += 4 ;
return 1 ;
} else if ( V_38 == 1 ) {
V_24 = ( V_24 & 0x3e00001f ) | 0x81a00060 ;
TYPE ( 3 , 3 , 0 , 3 , 0 , 0 , 0 ) ;
}
}
}
if ( type ) {
T_10 V_105 = NULL , V_106 = NULL , V_107 = NULL ;
if ( ! V_21 ) {
int T_3 = ( F_2 () -> V_5 [ 0 ] >> 14 ) & 0x7 ;
if ( T_3 != ( type >> 9 ) )
goto V_108;
}
F_2 () -> V_5 [ 0 ] &= ~ 0x1c000 ;
V_25 = ( ( V_24 >> 14 ) & 0x1f ) ;
switch ( type & 0x3 ) {
case 3 : if ( V_25 & 2 ) {
F_2 () -> V_5 [ 0 ] |= ( 6 << 14 ) ;
goto V_108;
}
case 2 : V_25 = ( ( V_25 & 1 ) << 5 ) | ( V_25 & 0x1e ) ;
case 1 : V_105 = ( T_10 ) & V_20 -> V_2 [ V_25 ] ;
V_27 = ( V_25 < 32 ) ? V_109 : V_110 ;
if ( ! ( F_2 () -> V_111 [ 0 ] & V_27 ) )
V_105 = ( T_10 ) & V_26 ;
break;
}
switch ( type & 0x7 ) {
case 7 : F_13 ( V_35 , V_105 ) ; break;
case 6 : F_14 ( V_32 , V_105 ) ; break;
case 5 : F_15 ( V_29 , V_105 ) ; break;
}
V_25 = ( V_24 & 0x1f ) ;
switch ( ( type >> 3 ) & 0x3 ) {
case 3 : if ( V_25 & 2 ) {
F_2 () -> V_5 [ 0 ] |= ( 6 << 14 ) ;
goto V_108;
}
case 2 : V_25 = ( ( V_25 & 1 ) << 5 ) | ( V_25 & 0x1e ) ;
case 1 : V_106 = ( T_10 ) & V_20 -> V_2 [ V_25 ] ;
V_27 = ( V_25 < 32 ) ? V_109 : V_110 ;
if ( ! ( F_2 () -> V_111 [ 0 ] & V_27 ) )
V_106 = ( T_10 ) & V_26 ;
break;
}
switch ( ( type >> 3 ) & 0x7 ) {
case 7 : F_13 ( V_36 , V_106 ) ; break;
case 6 : F_14 ( V_33 , V_106 ) ; break;
case 5 : F_15 ( V_30 , V_106 ) ; break;
}
V_25 = ( ( V_24 >> 25 ) & 0x1f ) ;
switch ( ( type >> 6 ) & 0x3 ) {
case 3 : if ( V_25 & 2 ) {
F_2 () -> V_5 [ 0 ] |= ( 6 << 14 ) ;
goto V_108;
}
case 2 : V_25 = ( ( V_25 & 1 ) << 5 ) | ( V_25 & 0x1e ) ;
case 1 : V_107 = ( T_10 ) & V_20 -> V_2 [ V_25 ] ;
V_27 = ( V_25 < 32 ) ? V_109 : V_110 ;
if ( ! ( F_2 () -> V_111 [ 0 ] & V_112 ) ) {
F_2 () -> V_111 [ 0 ] = V_112 ;
F_2 () -> V_113 [ 0 ] = 0 ;
}
if ( ! ( F_2 () -> V_111 [ 0 ] & V_27 ) ) {
if ( V_25 < 32 )
memset ( V_20 -> V_2 , 0 , 32 * sizeof( T_2 ) ) ;
else
memset ( V_20 -> V_2 + 32 , 0 , 32 * sizeof( T_2 ) ) ;
}
F_2 () -> V_111 [ 0 ] |= V_27 ;
break;
}
switch ( ( V_24 >> 5 ) & 0x1ff ) {
case V_69 : F_16 ( V_31 , V_29 , V_30 ) ; break;
case V_65 : F_17 ( V_34 , V_32 , V_33 ) ; break;
case V_49 : F_18 ( V_37 , V_35 , V_36 ) ; break;
case V_70 : F_19 ( V_31 , V_29 , V_30 ) ; break;
case V_66 : F_20 ( V_34 , V_32 , V_33 ) ; break;
case V_50 : F_21 ( V_37 , V_35 , V_36 ) ; break;
case V_71 : F_22 ( V_31 , V_29 , V_30 ) ; break;
case V_73 : F_23 ( V_114 , V_115 , 1 , 1 , V_32 , V_29 ) ;
F_23 ( V_114 , V_115 , 1 , 1 , V_33 , V_30 ) ;
case V_67 : F_24 ( V_34 , V_32 , V_33 ) ; break;
case V_53 : F_23 ( V_116 , V_114 , 2 , 1 , V_35 , V_32 ) ;
F_23 ( V_116 , V_114 , 2 , 1 , V_36 , V_33 ) ;
case V_51 : F_25 ( V_37 , V_35 , V_36 ) ; break;
case V_72 : F_26 ( V_31 , V_29 , V_30 ) ; break;
case V_68 : F_27 ( V_34 , V_32 , V_33 ) ; break;
case V_52 : F_28 ( V_37 , V_35 , V_36 ) ; break;
case V_62 : F_29 ( V_31 , V_30 ) ; break;
case V_64 : F_30 ( V_34 , V_33 ) ; break;
case V_48 : F_31 ( V_37 , V_36 ) ; break;
case V_45 : V_107 -> V_117 [ 0 ] = V_106 -> V_117 [ 0 ] ; V_107 -> V_117 [ 1 ] = V_106 -> V_117 [ 1 ] ; break;
case V_47 : V_107 -> V_117 [ 0 ] = V_106 -> V_117 [ 0 ] & 0x7fffffffffffffffUL ; V_107 -> V_117 [ 1 ] = V_106 -> V_117 [ 1 ] ; break;
case V_46 : V_107 -> V_117 [ 0 ] = V_106 -> V_117 [ 0 ] ^ 0x8000000000000000UL ; V_107 -> V_117 [ 1 ] = V_106 -> V_117 [ 1 ] ; break;
case V_78 : F_32 ( V_38 , V_30 , 32 , 1 ) ; break;
case V_79 : F_33 ( V_38 , V_33 , 32 , 1 ) ; break;
case V_61 : F_34 ( V_38 , V_36 , 32 , 1 ) ; break;
case V_74 : F_32 ( V_39 , V_30 , 64 , 1 ) ; break;
case V_75 : F_33 ( V_39 , V_33 , 64 , 1 ) ; break;
case V_54 : F_34 ( V_39 , V_36 , 64 , 1 ) ; break;
case V_58 : V_38 = V_106 -> V_118 ; F_35 ( V_37 , V_38 , 32 , int ) ; break;
case V_55 : V_39 = V_106 -> V_119 ; F_35 ( V_37 , V_39 , 64 , long ) ; break;
case V_80 : V_39 = V_106 -> V_119 ; F_36 ( V_31 , V_39 , 64 , long ) ; break;
case V_81 : V_39 = V_106 -> V_119 ; F_37 ( V_34 , V_39 , 64 , long ) ; break;
#if 0
case FITOS: IR = rs2->s; FP_FROM_INT_S (SR, IR, 32, int); break;
#endif
case V_82 : V_38 = V_106 -> V_118 ; F_37 ( V_34 , V_38 , 32 , int ) ; break;
case V_77 : F_23 ( V_114 , V_115 , 1 , 1 , V_34 , V_30 ) ; break;
case V_59 : F_23 ( V_116 , V_115 , 2 , 1 , V_37 , V_30 ) ; break;
case V_60 : F_23 ( V_116 , V_114 , 2 , 1 , V_37 , V_33 ) ; break;
case V_76 : F_23 ( V_115 , V_114 , 1 , 1 , V_31 , V_33 ) ; break;
case V_56 : F_23 ( V_115 , V_116 , 1 , 2 , V_31 , V_36 ) ; break;
case V_57 : F_23 ( V_114 , V_116 , 1 , 2 , V_34 , V_36 ) ; break;
case V_83 :
case V_84 :
F_38 ( V_39 , V_36 , V_35 , 3 ) ;
if ( V_39 == 3 &&
( ( ( V_24 >> 5 ) & 0x1ff ) == V_84 ||
F_39 ( V_35 ) ||
F_39 ( V_36 ) ) )
F_40 ( V_9 ) ;
}
if ( ! V_120 ) {
switch ( ( type >> 6 ) & 0x7 ) {
case 0 : V_5 = F_2 () -> V_5 [ 0 ] ;
if ( V_39 == - 1 ) V_39 = 2 ;
switch ( V_25 & 3 ) {
case 0 : V_5 &= ~ 0xc00 ; V_5 |= ( V_39 << 10 ) ; break;
case 1 : V_5 &= ~ 0x300000000UL ; V_5 |= ( V_39 << 32 ) ; break;
case 2 : V_5 &= ~ 0xc00000000UL ; V_5 |= ( V_39 << 34 ) ; break;
case 3 : V_5 &= ~ 0x3000000000UL ; V_5 |= ( V_39 << 36 ) ; break;
}
F_2 () -> V_5 [ 0 ] = V_5 ;
break;
case 1 : V_107 -> V_118 = V_38 ; break;
case 2 : V_107 -> V_119 = V_39 ; break;
case 5 : F_41 ( V_107 , V_31 ) ; break;
case 6 : F_42 ( V_107 , V_34 ) ; break;
case 7 : F_43 ( V_107 , V_37 ) ; break;
}
}
if( V_121 != 0 )
return F_1 ( V_2 , V_121 ) ;
F_2 () -> V_5 [ 0 ] &= ~ ( V_14 ) ;
V_2 -> V_17 = V_2 -> V_18 ;
V_2 -> V_18 += 4 ;
return 1 ;
}
V_108: return 0 ;
}
