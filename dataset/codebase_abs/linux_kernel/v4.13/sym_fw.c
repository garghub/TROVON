static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_8 = (struct V_7 * ) V_4 -> V_8 ;
if ( ! ( V_4 -> V_9 & V_10 ) ) {
V_6 -> V_11 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_13 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_14 [ 0 ] = F_3 ( V_12 ) ;
}
#ifdef F_4
if ( ! V_15 )
V_6 -> V_16 [ 0 ] = F_3 ( V_12 ) ;
#endif
V_8 -> V_17 [ 0 ] = F_3 ( V_4 -> V_18 ) ;
V_8 -> V_19 [ 0 ] = F_3 ( V_4 -> V_20 ) ;
V_8 -> V_21 [ 0 ] = F_3 ( V_4 -> V_22 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
struct V_23 * V_23 = F_6 ( V_2 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_3 * V_4 = V_23 -> V_26 ;
struct V_27 * V_6 ;
struct V_28 * V_8 ;
V_6 = (struct V_27 * ) V_4 -> V_6 ;
V_8 = (struct V_28 * ) V_4 -> V_8 ;
if ( ! ( V_4 -> V_9 & V_10 ) ) {
V_6 -> V_11 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_13 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_14 [ 0 ] = F_3 ( V_12 ) ;
}
#if V_29 == 2
if ( ! F_7 ( V_4 ) ) {
V_6 -> V_30 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_30 [ 1 ] = 0 ;
V_6 -> V_30 [ 2 ] = F_3 ( V_12 ) ;
V_6 -> V_30 [ 3 ] = 0 ;
}
#endif
#ifdef F_4
if ( ! V_15 )
V_6 -> V_16 [ 0 ] = F_3 ( V_12 ) ;
#endif
V_8 -> V_17 [ 0 ] = F_3 ( V_4 -> V_18 ) ;
V_8 -> V_19 [ 0 ] = F_3 ( V_4 -> V_20 ) ;
V_8 -> V_21 [ 0 ] = F_3 ( V_4 -> V_22 ) ;
if ( ! ( V_4 -> V_9 & V_31 ) ) {
V_6 -> V_32 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_32 [ 1 ] = F_3 ( 0 ) ;
}
if ( ! ( V_25 -> V_33 == V_34 &&
V_25 -> V_35 < 0x1 &&
V_4 -> V_36 < 60000 ) ) {
V_6 -> V_37 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_37 [ 1 ] = F_3 ( 0 ) ;
}
if ( ! ( V_25 -> V_33 == V_38 ) ) {
V_6 -> V_39 [ 0 ] = F_3 ( V_12 ) ;
V_6 -> V_39 [ 1 ] = F_3 ( 0 ) ;
}
V_8 -> V_40 [ 0 ] =
F_3 ( V_4 -> V_41 +
F_8 ( struct V_27 , V_42 ) ) ;
V_8 -> V_43 [ 0 ] =
F_3 ( V_4 -> V_41 +
F_8 ( struct V_27 , V_44 ) ) ;
}
static void
F_9 ( T_1 * V_45 , T_1 * V_46 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
* V_45 ++ = V_49 ^ V_50 ;
* V_45 ++ = F_8 ( struct V_51 , V_52 [ V_47 ] ) ;
* V_46 ++ = V_49 ^ V_53 ;
* V_46 ++ = F_8 ( struct V_51 , V_52 [ V_47 ] ) ;
}
}
static void
F_10 ( struct V_3 * V_4 , struct V_54 * V_55 )
{
T_1 * V_56 ;
T_2 * V_57 ;
int V_47 ;
V_57 = ( T_2 * ) V_55 -> V_58 ;
V_56 = ( T_1 * ) & V_4 -> V_59 ;
for ( V_47 = 0 ; V_47 < sizeof( V_4 -> V_59 ) / sizeof( T_1 ) ; V_47 ++ )
V_56 [ V_47 ] = V_4 -> V_41 + V_57 [ V_47 ] ;
V_57 = ( T_2 * ) V_55 -> V_60 ;
V_56 = ( T_1 * ) & V_4 -> V_61 ;
for ( V_47 = 0 ; V_47 < sizeof( V_4 -> V_61 ) / sizeof( T_1 ) ; V_47 ++ )
V_56 [ V_47 ] = V_4 -> V_62 + V_57 [ V_47 ] ;
V_57 = ( T_2 * ) V_55 -> V_63 ;
V_56 = ( T_1 * ) & V_4 -> V_64 ;
for ( V_47 = 0 ; V_47 < sizeof( V_4 -> V_64 ) / sizeof( T_1 ) ; V_47 ++ )
V_56 [ V_47 ] = V_4 -> V_65 + V_57 [ V_47 ] ;
}
static void
F_11 ( struct V_3 * V_4 , struct V_54 * V_55 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_8 = (struct V_7 * ) V_4 -> V_8 ;
F_9 ( V_6 -> V_66 , V_6 -> V_67 ) ;
F_10 ( V_4 , V_55 ) ;
}
static void
F_12 ( struct V_3 * V_4 , struct V_54 * V_55 )
{
struct V_27 * V_6 ;
struct V_28 * V_8 ;
V_6 = (struct V_27 * ) V_4 -> V_6 ;
V_8 = (struct V_28 * ) V_4 -> V_8 ;
F_9 ( V_6 -> V_66 , V_6 -> V_67 ) ;
F_10 ( V_4 , V_55 ) ;
}
struct V_54 *
F_13 ( struct V_68 * V_69 )
{
if ( V_69 -> V_9 & V_70 )
return & V_71 ;
#if V_72
else if ( ! ( V_69 -> V_9 & ( V_73 | V_74 | V_75 ) ) )
return & V_76 ;
#endif
else
return NULL ;
}
void F_14 ( struct V_3 * V_4 , T_1 * V_14 , int V_77 )
{
T_1 V_78 , V_79 , V_80 , V_81 , V_82 ;
T_1 * V_83 , * V_84 ;
int V_85 ;
V_84 = V_14 ;
V_83 = V_14 + V_77 / 4 ;
while ( V_84 < V_83 ) {
V_78 = * V_84 ;
if ( V_78 == 0 ) {
printf ( L_1 ,
F_15 ( V_4 ) , ( int ) ( V_84 - V_14 ) ) ;
++ V_84 ;
continue;
} ;
if ( V_78 == V_86 ) {
* V_84 ++ = 0 ;
continue;
}
if ( V_87 & V_88 )
printf ( L_2 , ( int ) ( V_84 - V_14 ) ,
( unsigned ) V_78 ) ;
switch ( V_78 >> 28 ) {
case 0xf :
V_85 = 0 ;
break;
case 0xe :
V_85 = 1 ;
break;
case 0xc :
V_85 = 2 ;
V_81 = V_84 [ 1 ] ;
V_82 = V_84 [ 2 ] ;
if ( ( V_81 ^ V_82 ) & 3 ) {
printf ( L_3 ,
F_15 ( V_4 ) , ( int ) ( V_84 - V_14 ) ) ;
}
if ( ( V_78 & V_89 ) &&
! ( V_4 -> V_9 & V_73 ) ) {
V_78 = ( V_78 & ~ V_89 ) ;
}
break;
case 0x0 :
if ( ! ( V_4 -> V_9 & V_90 ) )
V_78 = ( V_78 | V_91 ) ;
V_85 = 1 ;
break;
case 0x1 :
if ( ! ( V_4 -> V_9 & V_90 ) )
V_78 = ( V_78 | V_91 ) ;
V_85 = 0 ;
break;
#ifdef F_16
case 0x2 :
V_78 &= ~ 0x20000000 ;
if ( ! ( V_4 -> V_9 & V_90 ) )
V_78 = ( V_78 & ~ V_92 ) ;
V_85 = 1 ;
break;
case 0x3 :
V_78 &= ~ 0x20000000 ;
if ( ! ( V_4 -> V_9 & V_90 ) )
V_78 = ( V_78 & ~ V_92 ) ;
V_85 = 0 ;
break;
#endif
case 0x8 :
if ( V_78 & 0x00800000 )
V_85 = 0 ;
else if ( ( V_78 & 0xf8400000 ) == 0x80400000 )
V_85 = 2 ;
else
V_85 = 1 ;
break;
case 0x4 :
case 0x5 :
case 0x6 :
case 0x7 :
V_85 = 1 ;
break;
default:
V_85 = 0 ;
break;
} ;
* V_84 ++ = F_3 ( V_78 ) ;
if ( ! V_85 ) {
* V_84 = F_3 ( * V_84 ) ;
++ V_84 ;
continue;
}
while ( V_85 -- ) {
V_80 = * V_84 ;
switch ( V_80 & V_93 ) {
case V_94 :
V_79 = ( V_80 & ~ V_93 ) + V_4 -> V_95 ;
break;
case V_96 :
V_79 = ( V_80 & ~ V_93 ) + V_4 -> V_41 ;
break;
case V_97 :
V_79 = ( V_80 & ~ V_93 ) + V_4 -> V_62 ;
break;
case V_98 :
V_79 = ( V_80 & ~ V_93 ) + V_4 -> V_99 ;
break;
case 0 :
if ( V_80 == 0 ) {
V_79 = V_80 ;
break;
}
default:
V_79 = 0 ;
F_17 ( L_4
L_5 , V_80 ) ;
break;
}
* V_84 ++ = F_3 ( V_79 ) ;
}
} ;
}
