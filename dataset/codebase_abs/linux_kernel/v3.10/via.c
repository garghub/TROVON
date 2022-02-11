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
if ( ( V_1 -> V_2 == V_22 ) &&
( V_1 -> V_42 != V_43 ) &&
( V_1 -> V_42 != V_44 ) &&
( V_1 -> V_6 != V_45 ) &&
( V_1 -> V_6 != V_46 ) ) {
V_47 = 1 ;
V_4 [ V_38 ] |= 0x40 ;
V_4 [ V_28 ] &= ~ 0x40 ;
} else {
V_47 = 0 ;
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
if ( V_9 )
return;
F_6 ( L_7 , V_8 [ V_48 ] ) ;
if ( V_1 -> V_2 == V_23 ) {
V_8 [ V_48 ] = 0x66 ;
} else {
V_8 [ V_48 ] = 0x22 ;
}
}
void T_1 F_7 ( T_2 V_49 )
{
V_4 [ V_36 ] |= 0x40 ;
V_4 [ V_30 ] = V_50 ;
V_4 [ V_31 ] = V_51 ;
V_4 [ V_32 ] = V_50 ;
V_4 [ V_33 ] = V_51 ;
if ( F_8 ( V_52 , V_49 , 0 , L_8 , V_49 ) )
F_9 ( L_9 , L_8 ) ;
}
void F_5 ( void )
{
F_3 ( V_53 L_10 ,
( V_54 ) V_4 [ V_55 ] , ( V_54 ) V_4 [ V_38 ] , ( V_54 ) V_4 [ V_36 ] ) ;
F_3 ( V_53 L_11 ,
( V_54 ) V_4 [ V_48 ] , ( V_54 ) V_4 [ V_26 ] , ( V_54 ) V_4 [ V_25 ] ) ;
if ( V_10 ) {
F_3 ( V_53 L_12 ) ;
} else if ( V_9 ) {
F_3 ( V_53 L_13 ,
( V_54 ) V_8 [ V_17 ] , ( V_54 ) V_8 [ V_15 ] ) ;
F_3 ( V_53 L_14 ,
( V_54 ) V_8 [ V_19 ] , ( V_54 ) V_8 [ V_56 ] ) ;
} else {
F_3 ( V_53 L_15 ,
( V_54 ) V_8 [ V_55 ] , ( V_54 ) V_8 [ V_38 ] ,
( V_54 ) V_8 [ V_36 ] ) ;
F_3 ( V_53 L_11 ,
( V_54 ) V_8 [ V_48 ] ,
( V_54 ) V_8 [ V_26 ] , ( V_54 ) V_8 [ V_25 ] ) ;
}
}
T_3 F_10 ( void )
{
unsigned long V_57 , V_58 = 0 ;
V_57 = V_4 [ V_32 ] | ( V_4 [ V_33 ] << 8 ) ;
if ( V_57 > V_59 - V_59 / 50 )
if ( V_4 [ V_26 ] & 0x40 ) V_58 = V_60 ;
V_57 = V_59 - V_57 ;
V_57 = V_57 * 10000L / V_59 ;
return ( V_57 + V_58 ) * 1000 ;
}
void F_11 ( void )
{
V_8 [ V_20 ] &= ~ V_61 ;
V_8 [ V_20 ] |= V_61 ;
}
int F_12 ( void )
{
if ( ! V_8 ) {
F_3 ( V_62 L_16 ) ;
return 1 ;
}
return ( int ) V_8 [ V_20 ] & V_63 ;
}
void T_1 F_13 ( void )
{
if ( ( V_1 -> V_42 != V_43 ) &&
( V_1 -> V_42 != V_44 ) ) {
if ( ! V_9 )
V_8 [ V_38 ] |= 0x02 ;
V_8 [ V_20 ] |= 0x02 ;
}
switch ( V_1 -> V_2 ) {
case V_23 :
case V_22 :
F_6 ( L_17 , V_8 [ V_55 ] ) ;
break;
case V_3 :
V_8 [ V_56 ] = 0x7F ;
break;
}
}
void F_14 ( int V_64 )
{
int V_65 = F_15 ( V_64 ) ;
switch ( V_1 -> V_2 ) {
case V_23 :
case V_22 :
if ( V_1 -> V_2 == V_23 ) {
V_8 [ V_55 ] &= 0xC0 | ~ ( 1 << V_65 ) ;
} else {
V_8 [ V_55 ] &= 0x80 | ~ ( 1 << V_65 ) ;
}
case V_3 :
F_16 ( V_64 ) ;
break;
}
}
void F_17 ( int V_64 )
{
switch ( V_1 -> V_2 ) {
case V_23 :
case V_22 :
F_16 ( V_64 ) ;
break;
case V_3 :
F_18 ( V_64 ) ;
break;
}
}
void F_19 ( unsigned int V_64 , struct V_66 * V_67 )
{
int V_68 ;
unsigned char V_69 , V_70 ;
V_70 = V_4 [ V_26 ] & V_4 [ V_25 ] & 0x7F ;
if ( ! V_70 )
return;
V_68 = V_71 ;
V_69 = 1 ;
do {
if ( V_70 & V_69 ) {
V_4 [ V_26 ] = V_69 ;
F_20 ( V_68 ) ;
}
++ V_68 ;
V_69 <<= 1 ;
} while ( V_70 >= V_69 );
}
static void F_21 ( unsigned int V_64 , struct V_66 * V_67 )
{
int V_68 ;
unsigned char V_69 , V_70 ;
V_70 = V_8 [ V_16 ] & V_8 [ V_14 ] & 0x7F ;
if ( ! V_70 )
return;
V_68 = V_72 ;
V_69 = 1 ;
do {
if ( V_70 & V_69 ) {
V_8 [ V_16 ] = V_69 | V_13 ;
F_20 ( V_68 ) ;
}
++ V_68 ;
V_69 <<= 1 ;
} while ( V_70 >= V_69 );
}
void F_22 ( unsigned int V_64 , struct V_66 * V_67 )
{
int V_73 ;
unsigned char V_74 , V_70 ;
V_70 = ~ V_8 [ V_18 ] & 0x7F ;
if ( V_9 )
V_70 &= V_8 [ V_56 ] ;
else
V_70 &= ~ V_8 [ V_55 ] ;
if ( ! V_70 )
return;
do {
V_73 = V_75 ;
V_74 = 0x40 ;
do {
if ( V_70 & V_74 ) {
V_70 &= ~ V_74 ;
F_20 ( V_73 ) ;
}
-- V_73 ;
V_74 >>= 1 ;
} while ( V_70 );
V_8 [ V_16 ] = 0x02 | V_13 ;
V_70 = ~ V_8 [ V_18 ] & 0x7F ;
if ( V_9 )
V_70 &= V_8 [ V_56 ] ;
else
V_70 &= ~ V_8 [ V_55 ] ;
} while ( V_70 );
}
void T_1 F_23 ( void )
{
if ( V_47 ) {
F_24 ( V_76 , F_19 ) ;
F_24 ( V_77 , F_19 ) ;
} else {
F_24 ( V_76 , F_19 ) ;
}
F_24 ( V_78 , F_21 ) ;
F_24 ( V_79 , F_22 ) ;
}
void F_16 ( int V_64 ) {
int V_80 = F_25 ( V_64 ) ;
int V_65 = F_15 ( V_64 ) ;
#ifdef F_26
F_3 ( V_53 L_18 , V_64 ) ;
#endif
if ( V_80 == 1 ) {
V_4 [ V_25 ] = F_27 ( V_65 ) ;
} else if ( V_80 == 2 ) {
if ( V_64 != V_79 || V_81 == 0 )
V_8 [ V_14 ] = F_27 ( V_65 ) ;
} else if ( V_80 == 7 ) {
switch ( V_1 -> V_2 ) {
case V_23 :
case V_22 :
V_81 &= ~ ( 1 << V_65 ) ;
if ( ! V_81 )
V_8 [ V_14 ] = F_27 ( 1 ) ;
break;
case V_3 :
V_8 [ V_56 ] = F_27 ( V_65 ) ;
break;
}
}
}
void F_18 ( int V_64 ) {
int V_80 = F_25 ( V_64 ) ;
int V_65 = F_15 ( V_64 ) ;
#ifdef F_26
F_3 ( V_53 L_19 , V_64 ) ;
#endif
if ( V_80 == 1 ) {
V_4 [ V_25 ] = F_28 ( V_65 ) ;
} else if ( V_80 == 2 ) {
V_8 [ V_14 ] = F_28 ( V_65 ) ;
} else if ( V_80 == 7 ) {
switch ( V_1 -> V_2 ) {
case V_23 :
case V_22 :
V_81 |= 1 << V_65 ;
if ( V_81 )
V_8 [ V_14 ] = F_28 ( 1 ) ;
break;
case V_3 :
V_8 [ V_56 ] = F_28 ( V_65 ) ;
break;
}
}
}
void F_29 ( int V_82 )
{
if ( V_82 == 0 )
V_4 [ V_27 ] &= ~ V_83 ;
else
V_4 [ V_27 ] |= V_83 ;
}
int F_30 ( void )
{
return V_8 [ V_16 ] & ( 1 << F_15 ( V_84 ) ) ;
}
