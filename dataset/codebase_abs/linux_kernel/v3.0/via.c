void T_1 F_1 ( void )
{
switch( V_1 -> V_2 ) {
case V_3 :
V_4 = ( void * ) V_5 ;
if ( V_1 -> V_6 == V_7 ) {
V_8 = NULL ;
V_9 = 0 ;
V_10 = 1 ;
} else {
V_8 = ( void * ) V_11 ;
V_9 = 1 ;
V_10 = 0 ;
}
if ( V_1 -> V_6 == V_12 ) {
V_13 = 0x00 ;
} else {
V_13 = 0x80 ;
}
V_14 = V_15 ;
V_16 = V_17 ;
V_18 = V_19 ;
V_20 = V_21 ;
break;
case V_22 :
case V_23 :
V_4 = ( void * ) V_5 ;
V_8 = ( void * ) V_24 ;
V_9 = 0 ;
V_10 = 0 ;
V_13 = 0x00 ;
V_14 = V_25 ;
V_16 = V_26 ;
V_18 = V_27 ;
V_20 = V_28 ;
break;
default:
F_2 ( L_1 ) ;
}
F_3 ( V_29 L_2 , V_4 ) ;
F_3 ( V_29 L_3 , V_8 ) ;
if ( V_9 ) {
F_3 ( L_4 ) ;
} else if ( V_10 ) {
F_3 ( L_5 ) ;
} else {
F_3 ( L_6 ) ;
}
#ifdef F_4
F_5 () ;
#endif
V_4 [ V_25 ] = 0x7F ;
V_4 [ V_26 ] = 0x7F ;
V_4 [ V_30 ] = 0 ;
V_4 [ V_31 ] = 0 ;
V_4 [ V_32 ] = 0 ;
V_4 [ V_33 ] = 0 ;
V_4 [ V_34 ] = 0 ;
V_4 [ V_35 ] = 0 ;
V_4 [ V_36 ] &= ~ 0xC0 ;
V_4 [ V_36 ] &= ~ 0x03 ;
if ( V_1 -> V_6 == V_37 ) {
V_4 [ V_38 ] |= 0x40 ;
V_4 [ V_28 ] |= 0x40 ;
}
V_4 [ V_38 ] |= ( V_39 | V_40 | V_41 ) ;
V_4 [ V_28 ] |= ( V_39 | V_40 ) ;
if ( V_10 )
return;
V_42 = 0 ;
if ( V_1 -> V_2 == V_22 )
switch ( V_1 -> V_6 ) {
case V_43 :
case V_44 :
break;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
break;
default:
V_42 = 1 ;
V_4 [ V_38 ] |= 0x40 ;
V_4 [ V_28 ] &= ~ 0x40 ;
break;
}
V_8 [ V_14 ] = 0x7F ;
V_8 [ V_16 ] = 0x7F | V_13 ;
if ( ! V_9 ) {
V_8 [ V_30 ] = 0 ;
V_8 [ V_31 ] = 0 ;
V_8 [ V_32 ] = 0 ;
V_8 [ V_33 ] = 0 ;
V_8 [ V_34 ] = 0 ;
V_8 [ V_35 ] = 0 ;
V_8 [ V_36 ] &= ~ 0xC0 ;
V_8 [ V_36 ] &= ~ 0x03 ;
}
if ( ! V_9 ) {
if ( V_1 -> V_57 == V_58 ) {
V_8 [ V_59 ] = 0x66 ;
} else {
V_8 [ V_59 ] = 0x22 ;
}
}
}
void T_1 F_6 ( T_2 V_60 )
{
V_4 [ V_36 ] |= 0x40 ;
V_4 [ V_30 ] = V_61 ;
V_4 [ V_31 ] = V_62 ;
V_4 [ V_32 ] = V_61 ;
V_4 [ V_33 ] = V_62 ;
if ( F_7 ( V_63 , V_60 , V_64 , L_7 , V_60 ) )
F_8 ( L_8 , L_7 ) ;
}
void T_1 F_9 ( void )
{
if ( V_42 ) {
if ( F_7 ( V_65 , V_66 ,
V_64 | V_67 , L_9 ,
( void * ) V_4 ) )
F_8 ( L_8 , L_9 ) ;
if ( F_7 ( V_68 , V_66 ,
V_64 | V_67 , L_10 ,
( void * ) V_4 ) )
F_8 ( L_8 , L_10 ) ;
} else {
if ( F_7 ( V_65 , V_66 ,
V_64 | V_67 , L_10 ,
( void * ) V_4 ) )
F_8 ( L_8 , L_10 ) ;
}
if ( F_7 ( V_69 , V_70 , V_64 | V_67 ,
L_11 , ( void * ) V_8 ) )
F_8 ( L_8 , L_11 ) ;
if ( F_7 ( V_71 , V_72 ,
V_64 | V_67 , L_12 , ( void * ) V_8 ) )
F_8 ( L_8 , L_12 ) ;
}
void F_5 ( void )
{
F_3 ( V_73 L_13 ,
( V_74 ) V_4 [ V_75 ] , ( V_74 ) V_4 [ V_38 ] , ( V_74 ) V_4 [ V_36 ] ) ;
F_3 ( V_73 L_14 ,
( V_74 ) V_4 [ V_59 ] , ( V_74 ) V_4 [ V_26 ] , ( V_74 ) V_4 [ V_25 ] ) ;
if ( V_10 ) {
F_3 ( V_73 L_15 ) ;
} else if ( V_9 ) {
F_3 ( V_73 L_16 ,
( V_74 ) V_8 [ V_17 ] , ( V_74 ) V_8 [ V_15 ] ) ;
F_3 ( V_73 L_17 ,
( V_74 ) V_8 [ V_19 ] , ( V_74 ) V_8 [ V_76 ] ) ;
} else {
F_3 ( V_73 L_18 ,
( V_74 ) V_8 [ V_75 ] , ( V_74 ) V_8 [ V_38 ] ,
( V_74 ) V_8 [ V_36 ] ) ;
F_3 ( V_73 L_14 ,
( V_74 ) V_8 [ V_59 ] ,
( V_74 ) V_8 [ V_26 ] , ( V_74 ) V_8 [ V_25 ] ) ;
}
}
unsigned long F_10 ( void )
{
unsigned long V_77 , V_78 = 0 ;
V_77 = V_4 [ V_32 ] | ( V_4 [ V_33 ] << 8 ) ;
if ( V_77 > V_79 - V_79 / 50 )
if ( V_4 [ V_26 ] & 0x40 ) V_78 = V_80 ;
V_77 = V_79 - V_77 ;
V_77 = V_77 * 10000L / V_79 ;
return V_77 + V_78 ;
}
void F_11 ( void )
{
V_8 [ V_20 ] &= ~ V_81 ;
V_8 [ V_20 ] |= V_81 ;
}
int F_12 ( void )
{
if ( ! V_8 ) {
F_3 ( V_82 L_19 ) ;
return 1 ;
}
return ( int ) V_8 [ V_20 ] & V_83 ;
}
void T_1 F_13 ( void )
{
if ( ( V_1 -> V_84 != V_85 ) &&
( V_1 -> V_84 != V_86 ) ) {
if ( ! V_9 )
V_8 [ V_38 ] |= 0x02 ;
V_8 [ V_20 ] |= 0x02 ;
}
switch ( V_1 -> V_2 ) {
case V_23 :
switch( V_1 -> V_6 ) {
case V_87 :
case V_88 :
case V_89 :
case V_37 :
V_8 [ V_75 ] &= 0xC0 ;
break;
default:
V_8 [ V_75 ] &= 0x80 ;
}
break;
case V_3 :
V_8 [ V_76 ] = 0x7F ;
break;
case V_22 :
if ( ( V_1 -> V_84 != V_85 ) &&
( V_1 -> V_84 != V_86 ) ) {
V_8 [ V_27 ] |= 0x7F ;
V_8 [ V_75 ] |= 0x7F ;
}
break;
}
}
T_3 V_66 ( int V_90 , void * V_91 )
{
int V_92 ;
unsigned char V_93 , V_94 ;
V_94 = V_4 [ V_26 ] & V_4 [ V_25 ] & 0x7F ;
if ( ! V_94 )
return V_95 ;
V_92 = V_96 ;
V_93 = 1 ;
do {
if ( V_94 & V_93 ) {
V_4 [ V_26 ] = V_93 ;
F_14 ( V_92 ) ;
}
++ V_92 ;
V_93 <<= 1 ;
} while ( V_94 >= V_93 );
return V_97 ;
}
T_3 V_70 ( int V_90 , void * V_91 )
{
int V_92 ;
unsigned char V_93 , V_94 ;
V_94 = V_8 [ V_16 ] & V_8 [ V_14 ] & 0x7F ;
if ( ! V_94 )
return V_95 ;
V_92 = V_98 ;
V_93 = 1 ;
do {
if ( V_94 & V_93 ) {
V_8 [ V_16 ] = V_93 | V_13 ;
F_14 ( V_92 ) ;
}
++ V_92 ;
V_93 <<= 1 ;
} while ( V_94 >= V_93 );
return V_97 ;
}
T_3 V_72 ( int V_90 , void * V_91 )
{
int V_99 ;
unsigned char V_100 , V_94 ;
V_94 = ~ V_8 [ V_18 ] & 0x7F ;
if ( V_9 )
V_94 &= V_8 [ V_76 ] ;
else
V_94 &= ~ V_8 [ V_75 ] ;
if ( ! V_94 )
return V_95 ;
do {
V_99 = V_101 ;
V_100 = 0x40 ;
do {
if ( V_94 & V_100 ) {
V_94 &= ~ V_100 ;
F_14 ( V_99 ) ;
}
-- V_99 ;
V_100 >>= 1 ;
} while ( V_94 );
V_8 [ V_16 ] = 0x02 | V_13 ;
V_94 = ~ V_8 [ V_18 ] & 0x7F ;
if ( V_9 )
V_94 &= V_8 [ V_76 ] ;
else
V_94 &= ~ V_8 [ V_75 ] ;
} while ( V_94 );
return V_97 ;
}
void F_15 ( int V_90 ) {
int V_102 = F_16 ( V_90 ) ;
int V_103 = F_17 ( V_90 ) ;
#ifdef F_18
F_3 ( V_73 L_20 , V_90 ) ;
#endif
if ( V_102 == 1 ) {
V_4 [ V_25 ] = F_19 ( V_103 ) ;
} else if ( V_102 == 2 ) {
if ( V_90 != V_71 || V_104 == 0 )
V_8 [ V_14 ] = F_19 ( V_103 ) ;
} else if ( V_102 == 7 ) {
switch ( V_1 -> V_2 ) {
case V_23 :
V_104 &= ~ ( 1 << V_103 ) ;
if ( ! V_104 )
V_8 [ V_14 ] = F_19 ( 1 ) ;
break;
case V_3 :
V_8 [ V_76 ] = F_19 ( V_103 ) ;
break;
case V_22 :
if ( ( V_1 -> V_84 != V_85 ) &&
( V_1 -> V_84 != V_86 ) )
V_8 [ V_75 ] &= ~ ( 1 << V_103 ) ;
break;
}
}
}
void F_20 ( int V_90 ) {
int V_102 = F_16 ( V_90 ) ;
int V_103 = F_17 ( V_90 ) ;
#ifdef F_18
F_3 ( V_73 L_21 , V_90 ) ;
#endif
if ( V_102 == 1 ) {
V_4 [ V_25 ] = F_21 ( V_103 ) ;
} else if ( V_102 == 2 ) {
V_8 [ V_14 ] = F_21 ( V_103 ) ;
} else if ( V_102 == 7 ) {
switch ( V_1 -> V_2 ) {
case V_23 :
V_104 |= 1 << V_103 ;
if ( V_104 )
V_8 [ V_14 ] = F_21 ( 1 ) ;
break;
case V_3 :
V_8 [ V_76 ] = F_21 ( V_103 ) ;
break;
case V_22 :
if ( ( V_1 -> V_84 != V_85 ) &&
( V_1 -> V_84 != V_86 ) )
V_8 [ V_75 ] |= 1 << V_103 ;
break;
}
}
}
void F_22 ( int V_90 ) {
int V_102 = F_16 ( V_90 ) ;
int V_103 = F_17 ( V_90 ) ;
int V_93 = 1 << V_103 ;
if ( V_102 == 1 ) {
V_4 [ V_26 ] = V_93 ;
} else if ( V_102 == 2 ) {
V_8 [ V_16 ] = V_93 | V_13 ;
} else if ( V_102 == 7 ) {
}
}
int F_23 ( int V_90 )
{
int V_102 = F_16 ( V_90 ) ;
int V_103 = F_17 ( V_90 ) ;
int V_93 = 1 << V_103 ;
if ( V_102 == 1 ) {
return V_4 [ V_26 ] & V_93 ;
} else if ( V_102 == 2 ) {
return V_8 [ V_16 ] & V_93 ;
} else if ( V_102 == 7 ) {
return ~ V_8 [ V_18 ] & V_93 ;
}
return 0 ;
}
void F_24 ( int V_105 )
{
if ( V_105 == 0 )
V_4 [ V_27 ] &= ~ V_106 ;
else
V_4 [ V_27 ] |= V_106 ;
}
