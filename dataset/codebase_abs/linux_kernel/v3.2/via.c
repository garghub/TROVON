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
if ( F_7 ( V_63 , V_60 , 0 , L_7 , V_60 ) )
F_8 ( L_8 , L_7 ) ;
}
void F_5 ( void )
{
F_3 ( V_64 L_9 ,
( V_65 ) V_4 [ V_66 ] , ( V_65 ) V_4 [ V_38 ] , ( V_65 ) V_4 [ V_36 ] ) ;
F_3 ( V_64 L_10 ,
( V_65 ) V_4 [ V_59 ] , ( V_65 ) V_4 [ V_26 ] , ( V_65 ) V_4 [ V_25 ] ) ;
if ( V_10 ) {
F_3 ( V_64 L_11 ) ;
} else if ( V_9 ) {
F_3 ( V_64 L_12 ,
( V_65 ) V_8 [ V_17 ] , ( V_65 ) V_8 [ V_15 ] ) ;
F_3 ( V_64 L_13 ,
( V_65 ) V_8 [ V_19 ] , ( V_65 ) V_8 [ V_67 ] ) ;
} else {
F_3 ( V_64 L_14 ,
( V_65 ) V_8 [ V_66 ] , ( V_65 ) V_8 [ V_38 ] ,
( V_65 ) V_8 [ V_36 ] ) ;
F_3 ( V_64 L_10 ,
( V_65 ) V_8 [ V_59 ] ,
( V_65 ) V_8 [ V_26 ] , ( V_65 ) V_8 [ V_25 ] ) ;
}
}
unsigned long F_9 ( void )
{
unsigned long V_68 , V_69 = 0 ;
V_68 = V_4 [ V_32 ] | ( V_4 [ V_33 ] << 8 ) ;
if ( V_68 > V_70 - V_70 / 50 )
if ( V_4 [ V_26 ] & 0x40 ) V_69 = V_71 ;
V_68 = V_70 - V_68 ;
V_68 = V_68 * 10000L / V_70 ;
return V_68 + V_69 ;
}
void F_10 ( void )
{
V_8 [ V_20 ] &= ~ V_72 ;
V_8 [ V_20 ] |= V_72 ;
}
int F_11 ( void )
{
if ( ! V_8 ) {
F_3 ( V_73 L_15 ) ;
return 1 ;
}
return ( int ) V_8 [ V_20 ] & V_74 ;
}
void T_1 F_12 ( void )
{
if ( ( V_1 -> V_75 != V_76 ) &&
( V_1 -> V_75 != V_77 ) ) {
if ( ! V_9 )
V_8 [ V_38 ] |= 0x02 ;
V_8 [ V_20 ] |= 0x02 ;
}
switch ( V_1 -> V_2 ) {
case V_23 :
switch( V_1 -> V_6 ) {
case V_78 :
case V_79 :
case V_80 :
case V_37 :
V_8 [ V_66 ] &= 0xC0 ;
break;
default:
V_8 [ V_66 ] &= 0x80 ;
}
break;
case V_3 :
V_8 [ V_67 ] = 0x7F ;
break;
case V_22 :
if ( ( V_1 -> V_75 != V_76 ) &&
( V_1 -> V_75 != V_77 ) ) {
V_8 [ V_27 ] |= 0x7F ;
V_8 [ V_66 ] |= 0x7F ;
}
break;
}
}
void F_13 ( unsigned int V_81 , struct V_82 * V_83 )
{
int V_84 ;
unsigned char V_85 , V_86 ;
V_86 = V_4 [ V_26 ] & V_4 [ V_25 ] & 0x7F ;
if ( ! V_86 )
return;
V_84 = V_87 ;
V_85 = 1 ;
do {
if ( V_86 & V_85 ) {
V_4 [ V_26 ] = V_85 ;
F_14 ( V_84 ) ;
}
++ V_84 ;
V_85 <<= 1 ;
} while ( V_86 >= V_85 );
}
static void F_15 ( unsigned int V_81 , struct V_82 * V_83 )
{
int V_84 ;
unsigned char V_85 , V_86 ;
V_86 = V_8 [ V_16 ] & V_8 [ V_14 ] & 0x7F ;
if ( ! V_86 )
return;
V_84 = V_88 ;
V_85 = 1 ;
do {
if ( V_86 & V_85 ) {
V_8 [ V_16 ] = V_85 | V_13 ;
F_14 ( V_84 ) ;
}
++ V_84 ;
V_85 <<= 1 ;
} while ( V_86 >= V_85 );
}
void F_16 ( unsigned int V_81 , struct V_82 * V_83 )
{
int V_89 ;
unsigned char V_90 , V_86 ;
V_86 = ~ V_8 [ V_18 ] & 0x7F ;
if ( V_9 )
V_86 &= V_8 [ V_67 ] ;
else
V_86 &= ~ V_8 [ V_66 ] ;
if ( ! V_86 )
return;
do {
V_89 = V_91 ;
V_90 = 0x40 ;
do {
if ( V_86 & V_90 ) {
V_86 &= ~ V_90 ;
F_14 ( V_89 ) ;
}
-- V_89 ;
V_90 >>= 1 ;
} while ( V_86 );
V_8 [ V_16 ] = 0x02 | V_13 ;
V_86 = ~ V_8 [ V_18 ] & 0x7F ;
if ( V_9 )
V_86 &= V_8 [ V_67 ] ;
else
V_86 &= ~ V_8 [ V_66 ] ;
} while ( V_86 );
}
void T_1 F_17 ( void )
{
if ( V_42 ) {
F_18 ( V_92 , F_13 ) ;
F_18 ( V_93 , F_13 ) ;
} else {
F_18 ( V_92 , F_13 ) ;
}
F_18 ( V_94 , F_15 ) ;
F_18 ( V_95 , F_16 ) ;
}
void F_19 ( int V_81 ) {
int V_96 = F_20 ( V_81 ) ;
int V_97 = F_21 ( V_81 ) ;
#ifdef F_22
F_3 ( V_64 L_16 , V_81 ) ;
#endif
if ( V_96 == 1 ) {
V_4 [ V_25 ] = F_23 ( V_97 ) ;
} else if ( V_96 == 2 ) {
if ( V_81 != V_95 || V_98 == 0 )
V_8 [ V_14 ] = F_23 ( V_97 ) ;
} else if ( V_96 == 7 ) {
switch ( V_1 -> V_2 ) {
case V_23 :
V_98 &= ~ ( 1 << V_97 ) ;
if ( ! V_98 )
V_8 [ V_14 ] = F_23 ( 1 ) ;
break;
case V_3 :
V_8 [ V_67 ] = F_23 ( V_97 ) ;
break;
case V_22 :
if ( ( V_1 -> V_75 != V_76 ) &&
( V_1 -> V_75 != V_77 ) )
V_8 [ V_66 ] &= ~ ( 1 << V_97 ) ;
break;
}
}
}
void F_24 ( int V_81 ) {
int V_96 = F_20 ( V_81 ) ;
int V_97 = F_21 ( V_81 ) ;
#ifdef F_22
F_3 ( V_64 L_17 , V_81 ) ;
#endif
if ( V_96 == 1 ) {
V_4 [ V_25 ] = F_25 ( V_97 ) ;
} else if ( V_96 == 2 ) {
V_8 [ V_14 ] = F_25 ( V_97 ) ;
} else if ( V_96 == 7 ) {
switch ( V_1 -> V_2 ) {
case V_23 :
V_98 |= 1 << V_97 ;
if ( V_98 )
V_8 [ V_14 ] = F_25 ( 1 ) ;
break;
case V_3 :
V_8 [ V_67 ] = F_25 ( V_97 ) ;
break;
case V_22 :
if ( ( V_1 -> V_75 != V_76 ) &&
( V_1 -> V_75 != V_77 ) )
V_8 [ V_66 ] |= 1 << V_97 ;
break;
}
}
}
void F_26 ( int V_81 ) {
int V_96 = F_20 ( V_81 ) ;
int V_97 = F_21 ( V_81 ) ;
int V_85 = 1 << V_97 ;
if ( V_96 == 1 ) {
V_4 [ V_26 ] = V_85 ;
} else if ( V_96 == 2 ) {
V_8 [ V_16 ] = V_85 | V_13 ;
} else if ( V_96 == 7 ) {
}
}
int F_27 ( int V_81 )
{
int V_96 = F_20 ( V_81 ) ;
int V_97 = F_21 ( V_81 ) ;
int V_85 = 1 << V_97 ;
if ( V_96 == 1 ) {
return V_4 [ V_26 ] & V_85 ;
} else if ( V_96 == 2 ) {
return V_8 [ V_16 ] & V_85 ;
} else if ( V_96 == 7 ) {
return ~ V_8 [ V_18 ] & V_85 ;
}
return 0 ;
}
void F_28 ( int V_99 )
{
if ( V_99 == 0 )
V_4 [ V_27 ] &= ~ V_100 ;
else
V_4 [ V_27 ] |= V_100 ;
}
