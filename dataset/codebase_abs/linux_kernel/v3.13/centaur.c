static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = 1 ;
while ( V_2 <= V_1 )
V_2 <<= 1 ;
return V_2 >>= 1 ;
}
static void F_2 ( int V_3 , T_1 V_4 , T_1 V_5 , int V_6 )
{
T_1 V_7 , V_8 ;
V_8 = V_4 & ~ 0xFFF ;
V_7 = ~ ( V_5 - 1 ) ;
V_7 &= ~ 0xFFF ;
V_7 |= V_6 ;
F_3 ( V_3 + V_9 , V_7 , V_8 ) ;
F_4 ( V_3 , V_7 , V_8 ) ;
}
static T_1 F_5 ( void )
{
T_1 V_10 = 0xFFFFFFFFUL ;
T_1 V_11 = 0 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 . V_14 ; V_12 ++ ) {
unsigned long V_15 , V_16 ;
if ( V_13 . V_17 [ V_12 ] . V_18 > 0xFFFFFFFFUL )
continue;
if ( V_13 . V_17 [ V_12 ] . type == V_19 ) {
if ( V_13 . V_17 [ V_12 ] . V_18 >= 0x100000UL &&
V_13 . V_17 [ V_12 ] . V_18 < V_10 )
V_10 = V_13 . V_17 [ V_12 ] . V_18 ;
continue;
}
V_15 = V_13 . V_17 [ V_12 ] . V_18 ;
V_16 = V_13 . V_17 [ V_12 ] . V_18 + V_13 . V_17 [ V_12 ] . V_5 ;
if ( V_15 >= V_16 )
continue;
if ( V_16 > V_11 )
V_11 = V_16 ;
}
if ( V_11 > V_10 )
V_11 = V_10 ;
return V_11 ;
}
static int F_6 ( int V_20 , int V_6 )
{
T_1 V_21 = F_5 () ;
T_1 V_22 = F_1 ( V_21 ) ;
T_1 V_4 = V_22 ;
T_1 V_11 = V_22 ;
T_1 floor = 0 ;
int V_23 = 0 ;
while ( V_23 < V_20 ) {
T_1 V_24 = 0 ;
T_1 V_25 ;
T_1 V_26 ;
V_25 = F_1 ( V_21 - V_11 ) ;
V_26 = V_4 / 2 ;
if ( V_4 <= 1024 * 1024 )
V_26 = 0 ;
if ( floor == 0 )
V_24 = 512 * 1024 ;
else if ( floor == 512 * 1024 )
V_24 = 128 * 1024 ;
if ( V_24 > V_25 && V_24 > V_26 ) {
F_2 ( V_23 , floor , V_24 , V_6 ) ;
floor += V_24 ;
} else if ( V_25 > V_26 ) {
F_2 ( V_23 , V_11 , V_25 , V_6 ) ;
V_11 += V_25 ;
} else if ( V_26 > 0 ) {
V_4 -= V_26 ;
F_2 ( V_23 , V_4 , V_26 , V_6 ) ;
} else
break;
V_23 ++ ;
}
return V_23 ;
}
static void F_7 ( void )
{
int V_27 ;
int V_12 ;
V_27 = F_6 ( 6 , 31 ) ;
for ( V_12 = V_27 ; V_12 < 8 ; V_12 ++ )
F_3 ( V_9 + V_12 , 0 , 0 ) ;
}
static void F_8 ( void )
{
T_1 V_7 , V_8 ;
int V_27 ;
int V_12 ;
V_27 = F_6 ( 6 , 25 ) ;
F_9 ( V_28 , V_7 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ )
V_7 |= 1 << ( 9 + V_12 ) ;
F_3 ( V_28 , V_7 , V_8 ) ;
for ( V_12 = V_27 ; V_12 < 8 ; V_12 ++ )
F_3 ( V_9 + V_12 , 0 , 0 ) ;
}
static void F_10 ( void )
{
T_1 V_7 , V_8 ;
T_1 V_6 ;
F_9 ( V_28 , V_7 , V_8 ) ;
V_7 &= ~ 0x1C0 ;
V_6 = ( V_7 >> 17 ) & 7 ;
V_7 |= V_6 << 6 ;
F_3 ( V_28 , V_7 , V_8 ) ;
}
static void F_11 ( void )
{
T_1 V_7 , V_8 ;
F_9 ( V_28 , V_7 , V_8 ) ;
V_7 &= ~ 0x1C0 ;
F_3 ( V_28 , V_7 , V_8 ) ;
}
static void F_12 ( struct V_29 * V_30 )
{
T_1 V_7 , V_8 ;
if ( F_13 ( 0xC0000000 ) >= 0xC0000001 ) {
T_1 V_31 = F_14 ( 0xC0000001 ) ;
if ( ( V_31 & ( V_32 | V_33 ) ) == V_32 ) {
F_9 ( V_34 , V_7 , V_8 ) ;
V_7 |= V_35 ;
F_3 ( V_34 , V_7 , V_8 ) ;
F_15 ( V_36 L_1 ) ;
}
if ( ( V_31 & ( V_37 | V_38 ) ) == V_37 ) {
F_9 ( V_39 , V_7 , V_8 ) ;
V_7 |= V_40 ;
F_3 ( V_39 , V_7 , V_8 ) ;
F_15 ( V_36 L_2 ) ;
}
V_30 -> V_41 [ 5 ] = F_14 ( 0xC0000001 ) ;
}
#ifdef F_16
if ( V_30 -> V_42 >= 6 && V_30 -> V_42 <= 13 ) {
F_9 ( V_34 , V_7 , V_8 ) ;
V_7 |= ( 1 << 1 | 1 << 7 ) ;
F_3 ( V_34 , V_7 , V_8 ) ;
F_17 ( V_30 , V_43 ) ;
}
if ( V_30 -> V_42 >= 6 && V_30 -> V_42 < 9 )
F_17 ( V_30 , V_44 ) ;
#endif
if ( V_30 -> V_45 == 0x6 && V_30 -> V_42 >= 0xf ) {
V_30 -> V_46 = V_30 -> V_47 * 2 ;
F_17 ( V_30 , V_48 ) ;
}
F_18 ( V_30 ) ;
}
static void F_19 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_45 ) {
#ifdef F_16
case 5 :
F_17 ( V_30 , V_49 ) ;
break;
#endif
case 6 :
if ( V_30 -> V_42 >= 0xf )
F_17 ( V_30 , V_50 ) ;
break;
}
#ifdef F_20
F_17 ( V_30 , V_51 ) ;
#endif
}
static void F_21 ( struct V_29 * V_30 )
{
#ifdef F_16
char * V_52 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_7 , V_8 , V_55 ;
T_1 V_56 , V_57 , V_58 , V_59 ;
F_22 ( V_30 , 0 * 32 + 31 ) ;
#endif
F_19 ( V_30 ) ;
switch ( V_30 -> V_45 ) {
#ifdef F_16
case 5 :
switch ( V_30 -> V_42 ) {
case 4 :
V_52 = L_3 ;
V_53 = V_60 | V_61 | V_62 | V_63 | V_64 ;
V_54 = V_65 ;
F_15 ( V_66 L_4 ) ;
F_22 ( V_30 , V_67 ) ;
#ifdef F_23
F_7 () ;
F_3 ( V_28 , 0x01F0001F , 0 ) ;
#endif
break;
case 8 :
switch ( V_30 -> V_68 ) {
default:
V_52 = L_5 ;
break;
case 7 ... 9 :
V_52 = L_6 ;
break;
case 10 ... 15 :
V_52 = L_7 ;
break;
}
V_53 = V_60 | V_61 | V_69 | V_63 | V_70 | V_64 |
V_71 | V_72 ;
V_54 = V_65 ;
#ifdef F_23
F_10 () ;
F_8 () ;
F_9 ( V_28 , V_7 , V_8 ) ;
V_7 |= 31 ;
F_3 ( V_28 , V_7 , V_8 ) ;
F_11 () ;
#endif
break;
case 9 :
V_52 = L_8 ;
V_53 = V_60 | V_61 | V_69 | V_63 | V_70 | V_64 |
V_71 | V_72 ;
V_54 = V_65 ;
#ifdef F_23
F_10 () ;
F_8 () ;
F_9 ( V_28 , V_7 , V_8 ) ;
V_7 |= 31 ;
F_3 ( V_28 , V_7 , V_8 ) ;
F_11 () ;
#endif
break;
default:
V_52 = L_9 ;
}
F_9 ( V_73 , V_7 , V_8 ) ;
V_55 = ( V_7 | V_53 ) & ( ~ V_54 ) ;
if ( V_55 != V_7 ) {
F_15 ( V_36 L_10 ,
V_7 , V_55 ) ;
F_3 ( V_73 , V_55 , V_8 ) ;
} else {
F_15 ( V_36 L_11 , V_7 ) ;
}
F_17 ( V_30 , V_49 ) ;
F_17 ( V_30 , V_43 ) ;
if ( V_30 -> V_42 >= 8 )
F_17 ( V_30 , V_44 ) ;
if ( F_13 ( 0x80000000 ) >= 0x80000005 ) {
F_24 ( 0x80000005 , & V_56 , & V_57 , & V_58 , & V_59 ) ;
V_30 -> V_74 = ( V_58 >> 24 ) + ( V_59 >> 24 ) ;
}
sprintf ( V_30 -> V_75 , L_12 , V_52 ) ;
break;
#endif
case 6 :
F_12 ( V_30 ) ;
break;
}
#ifdef F_20
F_17 ( V_30 , V_76 ) ;
#endif
}
static unsigned int
F_25 ( struct V_29 * V_30 , unsigned int V_5 )
{
if ( ( V_30 -> V_45 == 6 ) && ( ( V_30 -> V_42 == 7 ) || ( V_30 -> V_42 == 8 ) ) )
V_5 >>= 8 ;
if ( ( V_30 -> V_45 == 6 ) && ( V_30 -> V_42 == 9 ) &&
( V_30 -> V_68 == 1 ) && ( V_5 == 65 ) )
V_5 -= 1 ;
return V_5 ;
}
