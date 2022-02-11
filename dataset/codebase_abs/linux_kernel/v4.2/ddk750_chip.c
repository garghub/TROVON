T_1 F_1 ( void )
{
unsigned short V_1 ;
char V_2 ;
T_1 V_3 ;
V_1 = V_4 ;
V_2 = V_5 ;
if ( V_1 == 0x718 )
V_3 = V_6 ;
else if ( V_1 == 0x750 ) {
V_3 = V_7 ;
if ( V_2 == V_8 )
V_3 = V_9 ;
} else
V_3 = V_10 ;
return V_3 ;
}
inline unsigned int F_2 ( unsigned long V_11 )
{
unsigned long V_12 ;
unsigned long V_13 = 1 ;
for ( V_12 = 1 ; V_12 <= V_11 ; V_12 ++ )
V_13 *= 2 ;
return V_13 ;
}
inline unsigned int F_3 ( T_2 * V_14 )
{
return ( V_14 -> V_15 * V_14 -> V_16 / V_14 -> V_17 / F_2 ( V_14 -> V_18 ) / F_2 ( V_14 -> V_19 ) ) ;
}
unsigned int F_4 ( T_3 V_20 , T_2 * V_14 )
{
unsigned int V_21 = 0 ;
V_14 -> V_15 = V_22 ;
V_14 -> V_20 = V_20 ;
switch ( V_20 ) {
case V_23 :
V_21 = F_5 ( V_24 ) ;
break;
case V_25 :
V_21 = F_5 ( V_26 ) ;
break;
case V_27 :
V_21 = F_5 ( V_28 ) ;
break;
case V_29 :
V_21 = F_5 ( V_30 ) ;
break;
case V_31 :
V_21 = F_5 ( V_32 ) ;
break;
}
V_14 -> V_16 = F_6 ( V_21 , V_26 , V_16 ) ;
V_14 -> V_17 = F_6 ( V_21 , V_26 , V_17 ) ;
V_14 -> V_18 = F_6 ( V_21 , V_26 , V_18 ) ;
V_14 -> V_19 = F_6 ( V_21 , V_26 , V_19 ) ;
return F_3 ( V_14 ) ;
}
unsigned int F_7 ( void )
{
T_2 V_33 ;
#if 1
if ( F_1 () == V_9 )
return F_8 ( 130 ) ;
#endif
return F_4 ( V_23 , & V_33 ) ;
}
void F_9 ( unsigned int V_34 )
{
T_2 V_33 ;
unsigned int V_35 ;
#if 1
if ( F_1 () == V_9 )
return;
#endif
if ( V_34 ) {
V_33 . V_15 = V_22 ;
V_33 . V_20 = V_23 ;
V_35 = F_10 ( V_34 , & V_33 ) ;
F_11 ( V_24 , F_12 ( & V_33 ) ) ;
}
}
void F_13 ( unsigned int V_34 )
{
unsigned int V_36 , V_37 ;
#if 1
if ( F_1 () == V_9 )
return;
#endif
if ( V_34 ) {
if ( V_34 > F_8 ( 336 ) )
V_34 = F_8 ( 336 ) ;
V_37 = ( unsigned int ) F_14 ( F_7 () , V_34 ) ;
V_36 = F_5 ( V_38 ) ;
switch ( V_37 ) {
default:
case 1 :
V_36 = F_15 ( V_36 , V_38 , V_39 , V_40 ) ;
break;
case 2 :
V_36 = F_15 ( V_36 , V_38 , V_39 , V_41 ) ;
break;
case 3 :
V_36 = F_15 ( V_36 , V_38 , V_39 , V_42 ) ;
break;
case 4 :
V_36 = F_15 ( V_36 , V_38 , V_39 , V_43 ) ;
break;
}
F_16 ( V_36 ) ;
}
}
void F_17 ( unsigned int V_34 )
{
unsigned int V_36 , V_37 ;
#if 1
if ( F_1 () == V_9 )
return;
#endif
if ( V_34 ) {
if ( V_34 > F_8 ( 190 ) )
V_34 = F_8 ( 190 ) ;
V_37 = ( unsigned int ) F_14 ( F_7 () , V_34 ) ;
V_36 = F_5 ( V_38 ) ;
switch ( V_37 ) {
default:
case 3 :
V_36 = F_15 ( V_36 , V_38 , V_44 , V_42 ) ;
break;
case 4 :
V_36 = F_15 ( V_36 , V_38 , V_44 , V_43 ) ;
break;
case 6 :
V_36 = F_15 ( V_36 , V_38 , V_44 , V_45 ) ;
break;
case 8 :
V_36 = F_15 ( V_36 , V_38 , V_44 , V_46 ) ;
break;
}
F_16 ( V_36 ) ;
}
}
unsigned int F_18 ( void )
{
unsigned int V_47 ;
unsigned int V_48 ;
if ( F_1 () == V_9 )
return F_19 ( 64 ) ;
V_47 = F_5 ( V_49 ) ;
V_47 = F_15 ( V_47 , V_49 , V_50 , V_51 ) ;
F_11 ( V_49 , V_47 ) ;
V_47 = F_6 ( F_5 ( V_52 ) , V_52 , V_53 ) ;
switch ( V_47 ) {
case V_54 :
V_48 = F_19 ( 8 ) ; break;
case V_55 :
V_48 = F_19 ( 16 ) ; break;
case V_56 :
V_48 = F_19 ( 32 ) ; break;
case V_57 :
V_48 = F_19 ( 64 ) ; break;
default:
V_48 = 0 ;
break;
}
return V_48 ;
}
int F_20 ( T_4 * V_58 )
{
unsigned int V_36 ;
#if 0
if (getChipType() == SM718) {
ulReg = PEEK32(0x74);
POKE32(0x74, ulReg|0x80000000);
}
#endif
if ( V_58 -> V_59 != 0 )
V_58 -> V_59 = 0 ;
F_21 ( V_58 -> V_59 ) ;
V_36 = F_5 ( V_38 ) ;
V_36 = F_15 ( V_36 , V_38 , V_60 , V_51 ) ;
V_36 = F_15 ( V_36 , V_38 , V_61 , V_51 ) ;
F_16 ( V_36 ) ;
if ( F_1 () != V_9 ) {
V_36 = F_5 ( V_62 ) ;
V_36 = F_15 ( V_36 , V_62 , V_63 , V_64 ) ;
V_36 = F_15 ( V_36 , V_62 , V_65 , V_66 ) ;
F_11 ( V_62 , V_36 ) ;
} else {
#if F_22 ( V_67 ) || F_22 ( V_68 )
F_23 ( 0x88 , 0x3d4 ) ;
F_23 ( 0x06 , 0x3d5 ) ;
#endif
}
F_9 ( F_8 ( ( unsigned int ) V_58 -> V_69 ) ) ;
F_13 ( F_8 ( V_58 -> V_70 ) ) ;
F_17 ( F_8 ( V_58 -> V_71 ) ) ;
if ( V_58 -> V_72 == 1 ) {
V_36 = F_5 ( V_52 ) ;
V_36 = F_15 ( V_36 , V_52 , V_73 , V_74 ) ;
F_11 ( V_52 , V_36 ) ;
V_36 = F_15 ( V_36 , V_52 , V_73 , V_75 ) ;
F_11 ( V_52 , V_36 ) ;
}
if ( V_58 -> V_76 == 1 ) {
F_24 ( 0 ) ;
V_36 = F_5 ( V_77 ) ;
V_36 = F_15 ( V_36 , V_77 , V_78 , V_79 ) ;
F_11 ( V_77 , V_36 ) ;
V_36 = F_5 ( V_80 ) ;
V_36 = F_15 ( V_36 , V_80 , V_78 , V_79 ) ;
F_11 ( V_80 , V_36 ) ;
V_36 = F_5 ( V_81 ) ;
V_36 = F_15 ( V_36 , V_81 , V_78 , V_79 ) ;
F_11 ( V_81 , V_36 ) ;
#if 0
ulReg = PEEK32(PANEL_HWC_ADDRESS);
ulReg = FIELD_SET(ulReg, PANEL_HWC_ADDRESS, ENABLE, DISABLE);
POKE32(PANEL_HWC_ADDRESS, ulReg);
ulReg = PEEK32(CRT_HWC_ADDRESS);
ulReg = FIELD_SET(ulReg, CRT_HWC_ADDRESS, ENABLE, DISABLE);
POKE32(CRT_HWC_ADDRESS, ulReg);
ulReg = PEEK32(ZV0_CAPTURE_CTRL);
ulReg = FIELD_SET(ulReg, ZV0_CAPTURE_CTRL, CAP, DISABLE);
POKE32(ZV0_CAPTURE_CTRL, ulReg);
ulReg = PEEK32(ZV1_CAPTURE_CTRL);
ulReg = FIELD_SET(ulReg, ZV1_CAPTURE_CTRL, CAP, DISABLE);
POKE32(ZV1_CAPTURE_CTRL, ulReg);
enableZVPort(0);
ulReg = PEEK32(DMA_ABORT_INTERRUPT);
ulReg = FIELD_SET(ulReg, DMA_ABORT_INTERRUPT, ABORT_1, ABORT);
POKE32(DMA_ABORT_INTERRUPT, ulReg);
enableI2C(0);
#endif
V_36 = F_5 ( V_82 ) ;
V_36 = F_15 ( V_36 , V_82 , V_83 , ABORT ) ;
F_11 ( V_82 , V_36 ) ;
F_25 ( 0 ) ;
}
return 0 ;
}
unsigned int F_10 ( unsigned int V_84 , T_2 * V_33 )
{
static T_5 V_85 [] = {
{ 0 , 0 , 0 , 1 } ,
{ 1 , 0 , 1 , 2 } ,
{ 2 , 0 , 2 , 4 } ,
{ 3 , 0 , 3 , 8 } ,
{ 4 , 1 , 3 , 16 } ,
{ 5 , 2 , 3 , 32 } ,
{ 6 , 3 , 3 , 64 } ,
} ;
static T_5 V_86 [] = {
{ 0 , 0 , 0 , 1 } ,
{ 1 , 0 , 1 , 2 } ,
{ 2 , 0 , 2 , 4 } ,
{ 3 , 0 , 3 , 8 } ,
} ;
int V_17 , V_16 , V_87 , V_88 ;
int V_89 ;
int V_90 ;
unsigned int V_91 , V_92 , V_93 , V_94 ;
unsigned int V_95 , V_96 ;
unsigned int V_97 , V_98 ;
T_5 * V_99 ;
#if 1
if ( F_1 () == V_9 ) {
return V_84 ;
}
#endif
V_98 = 0 ;
V_90 = ~ 0 ;
V_96 = V_84 / 1000 ;
V_95 = V_33 -> V_15 / 1000 ;
if ( V_33 -> V_20 != V_23 ) {
V_99 = & V_85 [ 0 ] ;
V_89 = sizeof( V_85 ) / sizeof( V_85 [ 0 ] ) ;
} else {
V_99 = & V_86 [ 0 ] ;
V_89 = sizeof( V_86 ) / sizeof( V_86 [ 0 ] ) ;
}
for ( V_17 = 15 ; V_17 > 1 ; V_17 -- ) {
V_91 = V_17 * V_96 ;
V_92 = V_91 / V_95 ;
V_93 = V_91 % V_95 ;
V_94 = ( V_93 * 10000 / V_95 ) ;
for ( V_88 = V_89 - 1 ; V_88 >= 0 ; V_88 -- ) {
V_87 = V_99 [ V_88 ] . V_100 ;
V_16 = V_92 * V_87 ;
V_16 += V_94 * V_87 / 10000 ;
V_16 += ( V_94 * V_87 % 10000 ) > 5000 ? 1 : 0 ;
if ( V_16 < 256 && V_16 > 0 ) {
unsigned int V_101 ;
V_97 = V_33 -> V_15 * V_16 / V_17 / V_87 ;
V_101 = F_26 ( V_97 , V_84 ) ;
if ( V_101 < V_90 ) {
V_33 -> V_16 = V_16 ;
V_33 -> V_17 = V_17 ;
V_33 -> V_18 = V_99 [ V_88 ] . V_102 ;
V_33 -> V_19 = V_99 [ V_88 ] . V_103 ;
V_90 = V_101 ;
V_98 = V_97 ;
}
}
}
}
return V_98 ;
}
unsigned int F_27 (
unsigned int V_104 ,
T_2 * V_14
)
{
unsigned int V_16 , V_17 , V_18 , V_19 = 0 , V_101 , V_105 , V_106 , V_107 ;
unsigned int V_108 = 0xffffffff ;
unsigned int V_98 ;
V_14 -> V_16 = 0 ;
V_14 -> V_17 = 0 ;
V_14 -> V_18 = 0 ;
V_14 -> V_19 = 0 ;
V_14 -> V_15 /= 1000 ;
V_104 /= 1000 ;
#ifndef F_28
for ( V_19 = 0 ; V_19 <= 3 ; V_19 ++ )
#endif
{
#ifndef F_28
if ( ( V_19 > 0 ) && ( V_14 -> V_20 == V_23 ) )
break;
#endif
V_107 = F_2 ( V_19 ) ;
for ( V_18 = 0 ; V_18 <= 3 ; V_18 ++ ) {
V_106 = F_2 ( V_18 ) ;
#ifdef F_28
if ( V_106 > 4 )
V_107 = 4 ;
else
V_107 = V_106 ;
#endif
for ( V_17 = 2 ; V_17 <= 15 ; V_17 ++ ) {
V_16 = V_104 * V_17 * V_106 * 1000 / V_14 -> V_15 ;
V_16 = F_14 ( V_16 , 1000 ) ;
if ( V_16 < 256 ) {
V_105 = V_14 -> V_15 * V_16 / V_17 / V_106 / V_107 ;
V_101 = F_26 ( V_105 , V_104 ) ;
if ( V_101 < V_108 ) {
V_108 = V_101 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_17 = V_17 ;
V_14 -> V_18 = V_18 ;
#ifdef F_28
if ( V_18 > 2 )
V_19 = 2 ;
else
V_19 = V_18 ;
#endif
V_14 -> V_19 = V_19 ;
}
}
}
}
}
V_104 *= 1000 ;
V_14 -> V_15 = V_22 ;
V_98 = F_3 ( V_14 ) ;
return V_98 ;
}
unsigned int F_12 ( T_2 * V_14 )
{
unsigned int V_21 = 0 ;
V_21 =
F_15 ( 0 , V_26 , V_109 , V_110 )
| F_15 ( 0 , V_26 , V_111 , V_51 )
| F_15 ( 0 , V_26 , V_112 , V_113 )
#ifndef F_28
| F_29 ( 0 , V_26 , V_19 , V_14 -> V_19 )
#endif
| F_29 ( 0 , V_26 , V_18 , V_14 -> V_18 )
| F_29 ( 0 , V_26 , V_17 , V_14 -> V_17 )
| F_29 ( 0 , V_26 , V_16 , V_14 -> V_16 ) ;
return V_21 ;
}
