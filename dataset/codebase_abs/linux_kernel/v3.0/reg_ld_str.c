static T_1 F_1 ( T_2 * V_1 , int exp , int V_2 )
{
T_1 V_3 ;
F_2 ( V_1 , exp ) ;
V_3 = F_3 ( V_1 ) ;
F_4 ( V_1 ) ;
if ( V_2 )
F_5 ( V_1 ) ;
return V_3 ;
}
int F_6 ( T_2 * V_4 )
{
int exp ;
exp = F_7 ( V_4 ) & 0x7fff ;
if ( exp == 0 ) {
if ( ! ( V_4 -> V_5 | V_4 -> V_6 ) ) {
return V_7 ;
}
return V_8 ;
}
if ( exp == 0x7fff ) {
return V_8 ;
}
if ( ! ( V_4 -> V_5 & 0x80000000 ) ) {
return V_8 ;
}
return V_9 ;
}
int F_8 ( long double T_3 * V_10 , int V_11 )
{
T_2 * V_12 = & F_9 ( V_11 ) ;
V_13 ;
F_10 ( V_14 , V_10 , 10 ) ;
F_11 ( V_12 , V_10 , 10 ) ;
V_15 ;
return F_6 ( V_12 ) ;
}
int F_12 ( double T_3 * V_16 , T_2 * V_17 )
{
int exp , V_3 , V_18 ;
unsigned V_19 , V_20 ;
V_13 ;
F_10 ( V_14 , V_16 , 8 ) ;
F_13 ( V_19 , 1 + ( unsigned long T_3 * ) V_16 ) ;
F_13 ( V_20 , ( unsigned long T_3 * ) V_16 ) ;
V_15 ;
V_18 = ( V_19 & 0x80000000 ) ? V_21 : V_22 ;
exp = ( ( V_19 & 0x7ff00000 ) >> 20 ) - V_23 + V_24 ;
V_19 &= 0xfffff ;
if ( exp > V_25 + V_24 ) {
if ( ( V_19 == 0 ) && ( V_20 == 0 ) ) {
V_17 -> V_5 = 0x80000000 ;
V_17 -> V_6 = 0x00000000 ;
exp = V_26 + V_24 ;
V_3 = V_8 ;
} else {
exp = V_27 + V_24 ;
V_17 -> V_5 = ( V_19 << 11 ) | 0x80000000 ;
V_17 -> V_5 |= V_20 >> 21 ;
V_17 -> V_6 = V_20 << 11 ;
V_3 = V_8 ;
}
} else if ( exp < V_28 + V_24 ) {
if ( ( V_19 == 0 ) && ( V_20 == 0 ) ) {
F_14 ( & V_29 , V_17 ) ;
exp = 0 ;
V_3 = V_7 ;
} else {
V_17 -> V_5 = V_19 << 11 ;
V_17 -> V_5 |= V_20 >> 21 ;
V_17 -> V_6 = V_20 << 11 ;
return F_1 ( V_17 , V_28 ,
V_18 )
| ( F_15 () < 0 ? V_30 : 0 ) ;
}
} else {
V_17 -> V_5 = ( V_19 << 11 ) | 0x80000000 ;
V_17 -> V_5 |= V_20 >> 21 ;
V_17 -> V_6 = V_20 << 11 ;
V_3 = V_9 ;
}
F_2 ( V_17 , exp | V_18 ) ;
return V_3 ;
}
int F_16 ( float T_3 * V_31 , T_2 * V_17 )
{
unsigned V_32 ;
int exp , V_3 , V_18 ;
V_13 ;
F_10 ( V_14 , V_31 , 4 ) ;
F_13 ( V_32 , ( unsigned long T_3 * ) V_31 ) ;
V_15 ;
V_18 = ( V_32 & 0x80000000 ) ? V_21 : V_22 ;
if ( ! ( V_32 & 0x7fffffff ) ) {
F_14 ( & V_29 , V_17 ) ;
F_17 ( V_17 , V_18 ) ;
return V_7 ;
}
exp = ( ( V_32 & 0x7f800000 ) >> 23 ) - V_33 + V_24 ;
V_32 = ( V_32 & 0x7fffff ) << 8 ;
if ( exp < V_34 + V_24 ) {
V_17 -> V_5 = V_32 ;
V_17 -> V_6 = 0 ;
return F_1 ( V_17 , V_34 , V_18 )
| ( F_15 () < 0 ? V_30 : 0 ) ;
} else if ( exp > V_35 + V_24 ) {
if ( V_32 == 0 ) {
V_17 -> V_5 = 0x80000000 ;
V_17 -> V_6 = 0x00000000 ;
exp = V_26 + V_24 ;
V_3 = V_8 ;
} else {
exp = V_27 + V_24 ;
V_17 -> V_5 = V_32 | 0x80000000 ;
V_17 -> V_6 = 0 ;
V_3 = V_8 ;
}
} else {
V_17 -> V_5 = V_32 | 0x80000000 ;
V_17 -> V_6 = 0 ;
V_3 = V_9 ;
}
F_2 ( V_17 , exp | V_18 ) ;
return V_3 ;
}
int F_18 ( long long T_3 * V_36 )
{
long long V_10 ;
int V_2 ;
T_2 * V_37 = & F_9 ( 0 ) ;
V_13 ;
F_10 ( V_14 , V_36 , 8 ) ;
if ( F_19 ( & V_10 , V_36 , 8 ) )
V_38 ;
V_15 ;
if ( V_10 == 0 ) {
F_14 ( & V_29 , V_37 ) ;
return V_7 ;
}
if ( V_10 > 0 )
V_2 = V_22 ;
else {
V_10 = - V_10 ;
V_2 = V_21 ;
}
F_20 ( V_37 ) = V_10 ;
return F_1 ( V_37 , 63 , V_2 ) ;
}
int F_21 ( long T_3 * V_36 , T_2 * V_17 )
{
long V_10 ;
int V_18 ;
V_13 ;
F_10 ( V_14 , V_36 , 4 ) ;
F_13 ( V_10 , V_36 ) ;
V_15 ;
if ( V_10 == 0 ) {
F_14 ( & V_29 , V_17 ) ;
return V_7 ;
}
if ( V_10 > 0 )
V_18 = V_22 ;
else {
V_10 = - V_10 ;
V_18 = V_21 ;
}
V_17 -> V_5 = V_10 ;
V_17 -> V_6 = 0 ;
return F_1 ( V_17 , 31 , V_18 ) ;
}
int F_22 ( short T_3 * V_36 , T_2 * V_17 )
{
int V_10 , V_18 ;
V_13 ;
F_10 ( V_14 , V_36 , 2 ) ;
F_13 ( V_10 , V_36 ) ;
V_15 ;
if ( V_10 == 0 ) {
F_14 ( & V_29 , V_17 ) ;
return V_7 ;
}
if ( V_10 > 0 )
V_18 = V_22 ;
else {
V_10 = - V_10 ;
V_18 = V_21 ;
}
V_17 -> V_5 = V_10 << 16 ;
V_17 -> V_6 = 0 ;
return F_1 ( V_17 , 15 , V_18 ) ;
}
int F_23 ( T_1 T_3 * V_10 )
{
T_2 * V_37 = & F_9 ( 0 ) ;
int V_39 ;
T_1 V_40 ;
long long V_41 = 0 ;
int V_2 ;
V_13 ;
F_10 ( V_14 , V_10 , 10 ) ;
V_15 ;
for ( V_39 = 8 ; V_39 >= 0 ; V_39 -- ) {
V_41 *= 10 ;
V_13 ;
F_13 ( V_40 , V_10 + V_39 ) ;
V_15 ;
V_41 += V_40 >> 4 ;
V_41 *= 10 ;
V_41 += V_40 & 0x0f ;
}
V_13 ;
F_13 ( V_2 , V_10 + 9 ) ;
V_2 = V_2 & 0x80 ? V_21 : V_22 ;
V_15 ;
if ( V_41 == 0 ) {
F_14 ( & V_29 , V_37 ) ;
F_17 ( V_37 , V_2 ) ;
return V_7 ;
} else {
F_20 ( V_37 ) = V_41 ;
return F_1 ( V_37 , 63 , V_2 ) ;
}
}
int F_24 ( T_2 * V_37 , T_1 V_42 ,
long double T_3 * V_43 )
{
if ( V_42 != V_44 ) {
V_13 ;
F_10 ( V_45 , V_43 , 10 ) ;
F_25 ( V_37 -> V_6 , ( unsigned long T_3 * ) V_43 ) ;
F_25 ( V_37 -> V_5 ,
( unsigned long T_3 * ) ( ( T_1 T_3 * ) V_43 + 4 ) ) ;
F_25 ( F_7 ( V_37 ) ,
( unsigned short T_3 * ) ( ( T_1 T_3 * ) V_43 +
8 ) ) ;
V_15 ;
return 1 ;
}
F_26 ( V_46 ) ;
if ( V_47 & V_48 ) {
V_13 ;
F_10 ( V_45 , V_43 , 10 ) ;
F_25 ( 0 , ( unsigned long T_3 * ) V_43 ) ;
F_25 ( 0xc0000000 , 1 + ( unsigned long T_3 * ) V_43 ) ;
F_25 ( 0xffff , 4 + ( short T_3 * ) V_43 ) ;
V_15 ;
return 1 ;
} else
return 0 ;
}
int F_27 ( T_2 * V_37 , T_1 V_42 , double T_3 * V_16 )
{
unsigned long V_41 [ 2 ] ;
unsigned long V_49 = 0 ;
int V_50 ;
int exp ;
T_2 V_51 ;
V_41 [ 0 ] = 0 ;
V_41 [ 1 ] = 0 ;
if ( V_42 == V_9 ) {
F_14 ( V_37 , & V_51 ) ;
exp = F_28 ( & V_51 ) ;
if ( exp < V_28 ) {
F_17 ( & V_51 , - V_28 + 52 ) ;
V_52:
if ( ( V_50 = F_29 ( & V_51 , V_42 ) ) ) {
#ifdef F_30
if ( !
( ( V_51 . V_5 == 0x00100000 ) && ( V_51 . V_6 == 0 )
&& ( V_37 -> V_6 & 0x000007ff ) ) )
#endif
{
F_26 ( V_53 ) ;
if ( ! ( V_47 & V_54 ) )
return 0 ;
}
F_26 ( V_50 ) ;
if ( ! ( V_47 & V_55 ) )
return 0 ;
}
V_41 [ 0 ] = V_51 . V_6 ;
V_41 [ 1 ] = V_51 . V_5 ;
} else {
if ( V_51 . V_6 & 0x000007ff ) {
V_50 = 1 ;
switch ( V_47 & V_56 ) {
case V_57 :
V_49 = ( ( V_51 . V_6 & 0x7ff ) > 0x400 ) |
( ( V_51 . V_6 & 0xc00 ) == 0xc00 ) ;
break;
case V_58 :
V_49 =
F_31 ( & V_51 ) ? 0 : V_51 .
V_6 & 0x7ff ;
break;
case V_59 :
V_49 =
F_31 ( & V_51 ) ? V_51 .
V_6 & 0x7ff : 0 ;
break;
case V_60 :
V_49 = 0 ;
break;
}
V_51 . V_6 &= 0xfffff800 ;
if ( V_49 ) {
if ( V_51 . V_6 >= 0xfffff800 ) {
if ( V_51 . V_5 == 0xffffffff ) {
V_51 . V_5 = 0x80000000 ;
exp ++ ;
if ( exp >= V_61 )
goto V_62;
} else {
V_51 . V_5 ++ ;
}
V_51 . V_6 = 0x00000000 ;
} else {
V_51 . V_6 += 0x00000800 ;
}
}
} else
V_50 = 0 ;
V_41 [ 0 ] = ( V_51 . V_6 >> 11 ) | ( V_51 . V_5 << 21 ) ;
V_41 [ 1 ] = ( ( V_51 . V_5 >> 11 ) & 0xfffff ) ;
if ( exp > V_25 ) {
V_62:
F_26 ( V_63 ) ;
if ( ! ( V_47 & V_64 ) )
return 0 ;
F_32 () ;
if ( ! ( V_47 & V_55 ) )
return 0 ;
V_41 [ 1 ] = 0x7ff00000 ;
} else {
if ( V_50 ) {
if ( V_49 )
F_32 () ;
else
F_33 () ;
}
V_41 [ 1 ] |= ( ( ( exp + V_23 ) & 0x7ff ) << 20 ) ;
}
}
} else if ( V_42 == V_7 ) {
} else if ( V_42 == V_8 ) {
V_42 = F_34 ( V_37 ) ;
if ( V_42 == V_65 ) {
#ifndef F_30
if ( V_47 & V_54 )
F_15 () ;
#endif
F_14 ( V_37 , & V_51 ) ;
goto V_52;
} else if ( V_42 == V_66 ) {
V_41 [ 1 ] = 0x7ff00000 ;
} else if ( V_42 == V_67 ) {
if ( ( F_28 ( V_37 ) == V_61 )
&& ( V_37 -> V_5 & 0x80000000 ) ) {
V_41 [ 0 ] =
( V_37 -> V_6 >> 11 ) | ( V_37 ->
V_5 << 21 ) ;
V_41 [ 1 ] = ( ( V_37 -> V_5 >> 11 ) & 0xfffff ) ;
if ( ! ( V_37 -> V_5 & 0x40000000 ) ) {
F_26 ( V_68 ) ;
if ( ! ( V_47 & V_48 ) )
return 0 ;
V_41 [ 1 ] |= ( 0x40000000 >> 11 ) ;
}
V_41 [ 1 ] |= 0x7ff00000 ;
} else {
F_26 ( V_68 ) ;
if ( ! ( V_47 & V_48 ) )
return 0 ;
V_41 [ 1 ] = 0xfff80000 ;
}
}
} else if ( V_42 == V_44 ) {
F_26 ( V_46 ) ;
if ( V_47 & V_48 ) {
V_13 ;
F_10 ( V_45 , V_16 , 8 ) ;
F_25 ( 0 , ( unsigned long T_3 * ) V_16 ) ;
F_25 ( 0xfff80000 ,
1 + ( unsigned long T_3 * ) V_16 ) ;
V_15 ;
return 1 ;
} else
return 0 ;
}
if ( F_35 ( V_37 ) )
V_41 [ 1 ] |= 0x80000000 ;
V_13 ;
F_10 ( V_45 , V_16 , 8 ) ;
F_25 ( V_41 [ 0 ] , ( unsigned long T_3 * ) V_16 ) ;
F_25 ( V_41 [ 1 ] , 1 + ( unsigned long T_3 * ) V_16 ) ;
V_15 ;
return 1 ;
}
int F_36 ( T_2 * V_37 , T_1 V_42 , float T_3 * V_31 )
{
long V_69 = 0 ;
unsigned long V_49 = 0 ;
int V_50 ;
int exp ;
T_2 V_51 ;
if ( V_42 == V_9 ) {
F_14 ( V_37 , & V_51 ) ;
exp = F_28 ( & V_51 ) ;
if ( exp < V_34 ) {
F_17 ( & V_51 , - V_34 + 23 ) ;
V_52:
if ( ( V_50 = F_29 ( & V_51 , V_42 ) ) ) {
#ifdef F_30
if ( ! ( ( V_51 . V_6 == 0x00800000 ) &&
( ( V_37 -> V_5 & 0x000000ff )
|| V_37 -> V_6 ) ) )
#endif
{
F_26 ( V_53 ) ;
if ( ! ( V_47 & V_54 ) )
return 0 ;
}
F_26 ( V_50 ) ;
if ( ! ( V_47 & V_55 ) )
return 0 ;
}
V_69 = V_51 . V_6 ;
} else {
if ( V_51 . V_6 | ( V_51 . V_5 & 0x000000ff ) ) {
unsigned long V_5 = V_51 . V_5 ;
unsigned long V_6 = V_51 . V_6 ;
V_50 = 1 ;
switch ( V_47 & V_56 ) {
case V_57 :
V_49 = ( ( V_5 & 0xff ) > 0x80 )
|| ( ( ( V_5 & 0xff ) == 0x80 ) && V_6 )
|| ( ( V_5 & 0x180 ) == 0x180 ) ;
break;
case V_58 :
V_49 = F_31 ( & V_51 )
? 0 : ( V_6 | ( V_5 & 0xff ) ) ;
break;
case V_59 :
V_49 = F_31 ( & V_51 )
? ( V_6 | ( V_5 & 0xff ) ) : 0 ;
break;
case V_60 :
V_49 = 0 ;
break;
}
V_51 . V_6 = 0 ;
if ( V_49 ) {
if ( V_5 >= 0xffffff00 ) {
V_51 . V_5 = 0x80000000 ;
exp ++ ;
if ( exp >= V_61 )
goto V_62;
} else {
V_51 . V_5 &= 0xffffff00 ;
V_51 . V_5 += 0x100 ;
}
} else {
V_51 . V_5 &= 0xffffff00 ;
}
} else
V_50 = 0 ;
V_69 = ( V_51 . V_5 >> 8 ) & 0x007fffff ;
if ( exp > V_35 ) {
V_62:
F_26 ( V_63 ) ;
if ( ! ( V_47 & V_64 ) )
return 0 ;
F_32 () ;
if ( ! ( V_47 & V_55 ) )
return 0 ;
V_69 = 0x7f800000 ;
} else {
if ( V_50 ) {
if ( V_49 )
F_32 () ;
else
F_33 () ;
}
V_69 |= ( ( exp + V_33 ) & 0xff ) << 23 ;
}
}
} else if ( V_42 == V_7 ) {
V_69 = 0 ;
} else if ( V_42 == V_8 ) {
V_42 = F_34 ( V_37 ) ;
if ( V_42 == V_65 ) {
F_14 ( V_37 , & V_51 ) ;
#ifndef F_30
if ( V_47 & V_54 )
F_15 () ;
#endif
goto V_52;
} else if ( V_42 == V_66 ) {
V_69 = 0x7f800000 ;
} else if ( V_42 == V_67 ) {
if ( ( F_28 ( V_37 ) == V_61 )
&& ( V_37 -> V_5 & 0x80000000 ) ) {
V_69 = V_37 -> V_5 >> 8 ;
if ( ! ( V_37 -> V_5 & 0x40000000 ) ) {
F_26 ( V_68 ) ;
if ( ! ( V_47 & V_48 ) )
return 0 ;
V_69 |= ( 0x40000000 >> 8 ) ;
}
V_69 |= 0x7f800000 ;
} else {
F_26 ( V_68 ) ;
if ( ! ( V_47 & V_48 ) )
return 0 ;
V_69 = 0xffc00000 ;
}
}
#ifdef F_37
else {
F_26 ( V_70 | 0x164 ) ;
return 0 ;
}
#endif
} else if ( V_42 == V_44 ) {
F_26 ( V_46 ) ;
if ( V_47 & V_68 ) {
V_13 ;
F_10 ( V_45 , V_31 , 4 ) ;
F_25 ( 0xffc00000 ,
( unsigned long T_3 * ) V_31 ) ;
V_15 ;
return 1 ;
} else
return 0 ;
}
#ifdef F_37
else {
F_26 ( V_70 | 0x163 ) ;
return 0 ;
}
#endif
if ( F_35 ( V_37 ) )
V_69 |= 0x80000000 ;
V_13 ;
F_10 ( V_45 , V_31 , 4 ) ;
F_25 ( V_69 , ( unsigned long T_3 * ) V_31 ) ;
V_15 ;
return 1 ;
}
int F_38 ( T_2 * V_37 , T_1 V_42 , long long T_3 * V_43 )
{
T_2 V_71 ;
long long V_72 ;
int V_50 ;
if ( V_42 == V_44 ) {
F_26 ( V_46 ) ;
goto V_73;
} else if ( V_42 == V_8 ) {
V_42 = F_34 ( V_37 ) ;
if ( ( V_42 == V_66 ) || ( V_42 == V_67 ) ) {
F_26 ( V_68 ) ;
goto V_73;
}
}
F_14 ( V_37 , & V_71 ) ;
V_50 = F_29 ( & V_71 , V_42 ) ;
( ( long * ) & V_72 ) [ 0 ] = V_71 . V_6 ;
( ( long * ) & V_72 ) [ 1 ] = V_71 . V_5 ;
if ( ( V_50 == 1 ) ||
( ( V_71 . V_5 & 0x80000000 ) &&
! ( ( V_71 . V_5 == 0x80000000 ) && ( V_71 . V_6 == 0 ) && F_39 ( & V_71 ) ) ) ) {
F_26 ( V_68 ) ;
V_73:
if ( V_47 & V_68 ) {
V_72 = 0x8000000000000000LL ;
} else
return 0 ;
} else {
if ( V_50 )
F_40 ( V_50 ) ;
if ( F_39 ( & V_71 ) )
V_72 = - V_72 ;
}
V_13 ;
F_10 ( V_45 , V_43 , 8 ) ;
if ( F_41 ( V_43 , & V_72 , 8 ) )
V_38 ;
V_15 ;
return 1 ;
}
int F_42 ( T_2 * V_37 , T_1 V_42 , long T_3 * V_43 )
{
T_2 V_71 ;
int V_50 ;
if ( V_42 == V_44 ) {
F_26 ( V_46 ) ;
goto V_73;
} else if ( V_42 == V_8 ) {
V_42 = F_34 ( V_37 ) ;
if ( ( V_42 == V_66 ) || ( V_42 == V_67 ) ) {
F_26 ( V_68 ) ;
goto V_73;
}
}
F_14 ( V_37 , & V_71 ) ;
V_50 = F_29 ( & V_71 , V_42 ) ;
if ( V_71 . V_5 ||
( ( V_71 . V_6 & 0x80000000 ) &&
! ( ( V_71 . V_6 == 0x80000000 ) && F_39 ( & V_71 ) ) ) ) {
F_26 ( V_68 ) ;
V_73:
if ( V_47 & V_68 ) {
V_71 . V_6 = 0x80000000 ;
} else
return 0 ;
} else {
if ( V_50 )
F_40 ( V_50 ) ;
if ( F_39 ( & V_71 ) )
V_71 . V_6 = - ( long ) V_71 . V_6 ;
}
V_13 ;
F_10 ( V_45 , V_43 , 4 ) ;
F_25 ( V_71 . V_6 , ( unsigned long T_3 * ) V_43 ) ;
V_15 ;
return 1 ;
}
int F_43 ( T_2 * V_37 , T_1 V_42 , short T_3 * V_43 )
{
T_2 V_71 ;
int V_50 ;
if ( V_42 == V_44 ) {
F_26 ( V_46 ) ;
goto V_73;
} else if ( V_42 == V_8 ) {
V_42 = F_34 ( V_37 ) ;
if ( ( V_42 == V_66 ) || ( V_42 == V_67 ) ) {
F_26 ( V_68 ) ;
goto V_73;
}
}
F_14 ( V_37 , & V_71 ) ;
V_50 = F_29 ( & V_71 , V_42 ) ;
if ( V_71 . V_5 ||
( ( V_71 . V_6 & 0xffff8000 ) &&
! ( ( V_71 . V_6 == 0x8000 ) && F_39 ( & V_71 ) ) ) ) {
F_26 ( V_68 ) ;
V_73:
if ( V_47 & V_68 ) {
V_71 . V_6 = 0x8000 ;
} else
return 0 ;
} else {
if ( V_50 )
F_40 ( V_50 ) ;
if ( F_39 ( & V_71 ) )
V_71 . V_6 = - V_71 . V_6 ;
}
V_13 ;
F_10 ( V_45 , V_43 , 2 ) ;
F_25 ( ( short ) V_71 . V_6 , V_43 ) ;
V_15 ;
return 1 ;
}
int F_44 ( T_2 * V_37 , T_1 V_42 , T_1 T_3 * V_43 )
{
T_2 V_71 ;
unsigned long long V_74 ;
T_1 V_75 ;
int V_76 , V_50 ;
T_1 V_2 = ( F_35 ( V_37 ) == V_77 ) ? 0x80 : 0 ;
if ( V_42 == V_44 ) {
F_26 ( V_46 ) ;
goto V_73;
} else if ( V_42 == V_8 ) {
V_42 = F_34 ( V_37 ) ;
if ( ( V_42 == V_66 ) || ( V_42 == V_67 ) ) {
F_26 ( V_68 ) ;
goto V_73;
}
}
F_14 ( V_37 , & V_71 ) ;
V_50 = F_29 ( & V_71 , V_42 ) ;
V_74 = F_20 ( & V_71 ) ;
if ( ( V_71 . V_5 > 0x0de0b6b3 ) ||
( ( V_71 . V_5 == 0x0de0b6b3 ) && ( V_71 . V_6 > 0xa763ffff ) ) ) {
F_26 ( V_68 ) ;
V_73:
if ( V_47 & V_48 ) {
V_13 ;
F_10 ( V_45 , V_43 , 10 ) ;
for ( V_76 = 0 ; V_76 < 7 ; V_76 ++ )
F_25 ( 0 , V_43 + V_76 ) ;
F_25 ( 0xc0 , V_43 + 7 ) ;
F_25 ( 0xff , V_43 + 8 ) ;
F_25 ( 0xff , V_43 + 9 ) ;
V_15 ;
return 1 ;
} else
return 0 ;
} else if ( V_50 ) {
F_40 ( V_50 ) ;
}
V_13 ;
F_10 ( V_45 , V_43 , 10 ) ;
V_15 ;
for ( V_76 = 0 ; V_76 < 9 ; V_76 ++ ) {
V_75 = F_45 ( & V_74 , 10 ) ;
V_75 |= ( F_45 ( & V_74 , 10 ) ) << 4 ;
V_13 ;
F_25 ( V_75 , V_43 + V_76 ) ;
V_15 ;
}
V_13 ;
F_25 ( V_2 , V_43 + 9 ) ;
V_15 ;
return 1 ;
}
int F_29 ( T_2 * V_1 , T_1 V_3 )
{
T_1 V_78 ;
unsigned V_79 ;
if ( V_3 == V_7 ) {
F_20 ( V_1 ) = 0 ;
return 0 ;
}
if ( F_28 ( V_1 ) > 63 ) {
V_1 -> V_6 = V_1 -> V_5 = ~ 0 ;
return 1 ;
}
V_79 = F_46 ( & V_1 -> V_6 , 63 - F_28 ( V_1 ) ) ;
V_78 = ! ( ~ ( V_1 -> V_5 ) | ~ ( V_1 -> V_6 ) ) ;
#define F_47 (eax & 0x80000000)
#define F_48 (eax)
#define F_49 ((eax & 0x80000001) == 0x80000001)
switch ( V_47 & V_56 ) {
case V_57 :
if ( F_49
|| ( F_47 && ( V_1 -> V_6 & 1 ) ) ) {
if ( V_78 )
return 1 ;
F_20 ( V_1 ) ++ ;
return V_80 ;
}
break;
case V_58 :
if ( F_48 && F_35 ( V_1 ) ) {
if ( V_78 )
return 1 ;
F_20 ( V_1 ) ++ ;
return V_80 ;
}
break;
case V_59 :
if ( F_48 && ! F_35 ( V_1 ) ) {
if ( V_78 )
return 1 ;
F_20 ( V_1 ) ++ ;
return V_80 ;
}
break;
case V_60 :
break;
}
return V_79 ? V_81 : 0 ;
}
T_1 T_3 * F_50 ( T_4 V_82 , T_1 T_3 * V_10 )
{
unsigned short V_83 = 0 ;
T_1 V_3 ;
int V_76 ;
if ( ( V_82 . V_84 == V_85 ) ||
( ( V_82 . V_84 == V_86 )
^ ( V_82 . V_87 . V_88 == V_89 ) ) ) {
V_13 ;
F_10 ( V_14 , V_10 , 0x0e ) ;
F_13 ( V_47 , ( unsigned short T_3 * ) V_10 ) ;
F_13 ( V_90 , ( unsigned short T_3 * ) ( V_10 + 2 ) ) ;
F_13 ( V_83 , ( unsigned short T_3 * ) ( V_10 + 4 ) ) ;
F_13 ( V_91 . V_92 ,
( unsigned short T_3 * ) ( V_10 + 6 ) ) ;
F_13 ( V_91 . V_93 ,
( unsigned short T_3 * ) ( V_10 + 8 ) ) ;
F_13 ( V_94 . V_92 ,
( unsigned short T_3 * ) ( V_10 + 0x0a ) ) ;
F_13 ( V_94 . V_93 ,
( unsigned short T_3 * ) ( V_10 + 0x0c ) ) ;
V_15 ;
V_10 += 0x0e ;
if ( V_82 . V_84 == V_85 ) {
V_91 . V_92
+= ( V_91 . V_93 & 0xf000 ) << 4 ;
V_94 . V_92 +=
( V_94 . V_93 & 0xf000 ) << 4 ;
}
} else {
V_13 ;
F_10 ( V_14 , V_10 , 0x1c ) ;
F_13 ( V_47 , ( unsigned short T_3 * ) V_10 ) ;
F_13 ( V_90 , ( unsigned short T_3 * ) ( V_10 + 4 ) ) ;
F_13 ( V_83 , ( unsigned short T_3 * ) ( V_10 + 8 ) ) ;
F_13 ( V_91 . V_92 ,
( unsigned long T_3 * ) ( V_10 + 0x0c ) ) ;
F_13 ( V_91 . V_93 ,
( unsigned short T_3 * ) ( V_10 + 0x10 ) ) ;
F_13 ( V_91 . V_95 ,
( unsigned short T_3 * ) ( V_10 + 0x12 ) ) ;
F_13 ( V_94 . V_92 ,
( unsigned long T_3 * ) ( V_10 + 0x14 ) ) ;
F_13 ( V_94 . V_93 ,
( unsigned long T_3 * ) ( V_10 + 0x18 ) ) ;
V_15 ;
V_10 += 0x1c ;
}
#ifdef F_30
V_47 &= ~ 0xe080 ;
#endif
V_96 = ( V_90 >> V_97 ) & 7 ;
if ( V_90 & ~ V_47 & V_98 )
V_90 |= ( V_99 | V_100 ) ;
else
V_90 &= ~ ( V_99 | V_100 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_3 = V_83 & 3 ;
V_83 >>= 2 ;
if ( V_3 == V_44 )
F_51 ( V_76 , V_44 ) ;
else if ( F_52 ( V_76 ) == V_44 ) {
if ( F_28 ( & F_53 ( V_76 ) ) == - V_24 ) {
if ( !
( F_53 ( V_76 ) . V_6 | F_53 ( V_76 ) .
V_5 ) )
F_51 ( V_76 , V_7 ) ;
else
F_51 ( V_76 , V_8 ) ;
} else if ( F_28 ( & F_53 ( V_76 ) ) ==
0x7fff - V_24 ) {
F_51 ( V_76 , V_8 ) ;
} else if ( F_53 ( V_76 ) . V_5 & 0x80000000 )
F_51 ( V_76 , V_9 ) ;
else
F_51 ( V_76 , V_8 ) ;
}
}
return V_10 ;
}
void F_54 ( T_4 V_82 , T_1 T_3 * V_101 )
{
int V_76 , V_102 ;
T_1 T_3 * V_10 = F_50 ( V_82 , V_101 ) ;
int V_92 = ( V_96 & 7 ) * 10 , V_103 = 80 - V_92 ;
V_13 ;
F_10 ( V_14 , V_10 , 80 ) ;
F_11 ( V_104 + V_92 , V_10 , V_103 ) ;
if ( V_92 )
F_11 ( V_104 , V_10 + V_103 , V_92 ) ;
V_15 ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_102 = ( V_76 + V_96 ) & 7 ;
if ( F_52 ( V_102 ) != V_44 )
F_51 ( V_102 , F_6 ( & F_9 ( V_76 ) ) ) ;
}
}
T_1 T_3 * F_55 ( T_4 V_82 , T_1 T_3 * V_43 )
{
if ( ( V_82 . V_84 == V_85 ) ||
( ( V_82 . V_84 == V_86 )
^ ( V_82 . V_87 . V_88 == V_89 ) ) ) {
V_13 ;
F_10 ( V_45 , V_43 , 14 ) ;
#ifdef F_30
F_25 ( V_47 & ~ 0xe080 , ( unsigned long T_3 * ) V_43 ) ;
#else
F_25 ( V_47 , ( unsigned short T_3 * ) V_43 ) ;
#endif
F_25 ( F_56 () , ( unsigned short T_3 * ) ( V_43 + 2 ) ) ;
F_25 ( V_105 , ( unsigned short T_3 * ) ( V_43 + 4 ) ) ;
F_25 ( V_91 . V_92 ,
( unsigned short T_3 * ) ( V_43 + 6 ) ) ;
F_25 ( V_94 . V_92 ,
( unsigned short T_3 * ) ( V_43 + 0x0a ) ) ;
if ( V_82 . V_84 == V_85 ) {
F_25 ( ( V_91 .
V_92 & 0xf0000 ) >> 4 ,
( unsigned short T_3 * ) ( V_43 + 8 ) ) ;
F_25 ( ( V_94 . V_92 & 0xf0000 ) >> 4 ,
( unsigned short T_3 * ) ( V_43 + 0x0c ) ) ;
} else {
F_25 ( V_91 . V_93 ,
( unsigned short T_3 * ) ( V_43 + 8 ) ) ;
F_25 ( V_94 . V_93 ,
( unsigned short T_3 * ) ( V_43 + 0x0c ) ) ;
}
V_15 ;
V_43 += 0x0e ;
} else {
V_13 ;
F_10 ( V_45 , V_43 , 7 * 4 ) ;
#ifdef F_30
V_47 &= ~ 0xe080 ;
V_47 |= 0xffff0040 ;
V_90 = F_56 () | 0xffff0000 ;
V_105 |= 0xffff0000 ;
V_106 -> V_107 . V_108 &= ~ 0xf8000000 ;
V_106 -> V_107 . V_109 |= 0xffff0000 ;
#endif
if ( F_57 ( V_43 , & V_47 , 7 * 4 ) )
V_38 ;
V_15 ;
V_43 += 0x1c ;
}
V_47 |= V_98 ;
V_90 &= ~ ( V_99 | V_100 ) ;
return V_43 ;
}
void F_58 ( T_4 V_82 , T_1 T_3 * V_101 )
{
T_1 T_3 * V_43 ;
int V_92 = ( V_96 & 7 ) * 10 , V_103 = 80 - V_92 ;
V_43 = F_55 ( V_82 , V_101 ) ;
V_13 ;
F_10 ( V_45 , V_43 , 80 ) ;
if ( F_57 ( V_43 , V_104 + V_92 , V_103 ) )
V_38 ;
if ( V_92 )
if ( F_57 ( V_43 + V_103 , V_104 , V_92 ) )
V_38 ;
V_15 ;
F_59 () ;
}
