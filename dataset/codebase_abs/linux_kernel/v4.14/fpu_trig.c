static int F_1 ( T_1 * V_1 , int V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
unsigned long long V_5 ;
int V_6 = V_7 , V_8 = V_9 ;
int V_10 , V_11 = V_12 ;
if ( F_2 ( V_1 ) >= 63 ) {
V_9 |= V_13 ;
return - 1 ;
}
V_7 &= ~ V_14 ;
V_7 |= V_15 ;
F_3 ( V_1 ) ;
V_10 = F_4 ( V_1 , & V_16 , & V_3 , V_17 | V_15 | 0x3f ,
V_18 ) ;
F_5 ( & V_3 , V_10 ) ;
V_5 = F_6 ( & V_3 ) ;
if ( V_5 ) {
F_7 ( F_6 ( V_1 ) ,
& F_6 ( & V_3 ) ,
F_6 ( & V_16 ) ,
V_5 , F_2 ( V_1 ) - F_2 ( & V_16 ) ) ;
F_8 ( & V_3 , F_2 ( & V_16 ) ) ;
V_11 = F_9 ( & V_3 ) ;
F_10 ( & V_3 , V_11 ) ;
}
if ( ( V_2 && ! ( V_5 & 1 ) ) || ( ! V_2 && ( V_5 & 1 ) ) ) {
V_11 =
F_11 ( V_19 | V_20 | V_12 , ( int ) & V_16 ,
V_21 ) ;
#ifdef F_12
if ( ( F_2 ( V_1 ) <= F_2 ( & V_22 ) + 64 )
|| ( V_5 > 1 ) ) {
F_6 ( & V_3 ) = V_5 + 1 ;
F_8 ( & V_3 , 63 ) ;
F_9 ( & V_3 ) ;
V_4 =
F_13 ( & V_22 , & V_3 , & V_3 ,
V_21 , V_18 ,
F_2 ( & V_22 ) +
F_2 ( & V_3 ) ) ;
F_14 ( & V_3 , F_15 ( & V_22 ) ) ;
V_11 = F_16 ( & V_3 , V_4 , 0 , V_21 ) ;
if ( F_17 ( V_1 ) ) {
F_3 ( V_1 ) ;
V_5 ++ ;
}
}
#endif
}
#ifdef F_12
else {
if ( ( ( V_5 > 0 )
&& ( F_2 ( V_1 ) <= F_2 ( & V_22 ) + 64 ) )
|| ( V_5 > 1 ) ) {
F_6 ( & V_3 ) = V_5 ;
F_8 ( & V_3 , 63 ) ;
F_9 ( & V_3 ) ;
V_4 =
F_13 ( & V_22 , & V_3 , & V_3 ,
V_21 , V_18 ,
F_2 ( & V_22 ) +
F_2 ( & V_3 ) ) ;
F_14 ( & V_3 , F_15 ( & V_22 ) ) ;
V_11 = F_11 ( V_20 | ( V_4 & 0x0f ) , ( int ) & V_3 ,
V_21 ) ;
if ( ( F_2 ( V_1 ) == F_2 ( & V_16 ) ) &&
( ( V_1 -> V_23 > V_16 . V_23 )
|| ( ( V_1 -> V_23 == V_16 . V_23 )
&& ( V_1 -> V_24 > V_16 . V_24 ) ) ) ) {
V_11 =
F_11 ( V_19 | V_20 | V_12 ,
( int ) & V_16 , V_21 ) ;
V_5 ++ ;
}
}
}
#endif
F_18 ( V_11 ) ;
V_7 = V_6 ;
V_9 = V_8 & ~ V_13 ;
return ( V_5 & 3 ) | V_2 ;
}
static void F_19 ( long const * V_25 , int V_26 )
{
int V_10 ;
long V_27 = * V_25 ;
T_2 V_28 ;
T_1 * V_29 = & F_20 ( V_26 ) ;
if ( V_27 == 0 ) {
F_21 ( & V_30 , V_31 , V_26 ) ;
return;
}
if ( V_27 > 0 ) {
V_28 = V_18 ;
} else {
V_27 = - V_27 ;
V_28 = V_32 ;
}
V_29 -> V_23 = V_27 ;
V_29 -> V_24 = 0 ;
F_8 ( V_29 , 31 ) ;
V_10 = F_9 ( V_29 ) ;
F_22 ( V_26 , V_10 ) ;
F_14 ( V_29 , V_28 ) ;
return;
}
static void F_23 ( T_1 * V_1 , T_2 V_11 )
{
if ( V_11 == V_33 )
F_24 () ;
else if ( V_11 == V_34 )
F_25 ( V_1 ) ;
#ifdef F_26
else
F_27 ( V_35 | 0x0112 ) ;
#endif
}
static void F_28 ( T_1 * V_1 , T_2 V_11 )
{
int V_36 ;
switch ( V_11 ) {
case V_34 :
V_36 = ( F_2 ( V_1 ) == V_37 )
&& ( V_1 -> V_23 & 0x80000000 ) ;
if ( V_36 && ! ( V_1 -> V_23 & 0x40000000 ) ) {
F_27 ( V_38 ) ;
if ( V_7 & V_39 ) {
V_1 -> V_23 |= 0x40000000 ;
F_29 () ;
F_10 ( V_1 , V_40 ) ;
}
} else if ( V_36 ) {
F_29 () ;
F_10 ( V_1 , V_40 ) ;
} else {
F_27 ( V_38 ) ;
if ( V_7 & V_39 ) {
F_10 ( & V_41 , V_40 ) ;
F_29 () ;
F_10 ( & V_41 , V_40 ) ;
}
}
break;
#ifdef F_26
default:
F_27 ( V_35 | 0x0112 ) ;
#endif
}
}
static void F_30 ( T_1 * V_1 , T_2 V_10 )
{
T_1 V_42 ;
F_31 () ;
if ( V_10 == V_12 ) {
if ( F_2 ( V_1 ) < 0 ) {
V_43:
F_32 ( V_1 , & V_42 ) ;
F_33 ( F_15 ( V_1 ) , & V_42 , V_1 ) ;
}
F_34 () ;
return;
}
if ( V_10 == V_31 )
return;
if ( V_10 == V_40 )
V_10 = F_35 ( V_1 ) ;
switch ( V_10 ) {
case V_44 :
if ( F_36 () < 0 )
return;
goto V_43;
case V_45 :
if ( F_17 ( V_1 ) ) {
F_10 ( & V_46 , V_12 ) ;
F_37 ( V_1 ) ;
}
return;
default:
F_23 ( V_1 , V_10 ) ;
}
}
static void F_38 ( T_1 * V_1 , T_2 V_11 )
{
T_1 * V_47 ;
int V_5 ;
T_2 V_48 = F_15 ( V_1 ) ;
if ( V_11 == V_33 ) {
F_24 () ;
if ( V_7 & V_39 ) {
V_47 = & F_20 ( - 1 ) ;
F_29 () ;
F_24 () ;
}
return;
}
if ( V_49 ) {
F_39 () ;
return;
}
if ( V_11 == V_12 ) {
if ( F_2 ( V_1 ) > - 40 ) {
if ( ( V_5 = F_1 ( V_1 , 0 ) ) == - 1 ) {
return;
}
F_40 ( V_1 ) ;
F_14 ( V_1 , ( V_5 & 1 ) ^ ( V_48 != 0 ) ) ;
F_34 () ;
} else {
V_43:
F_32 ( V_1 , V_1 ) ;
V_11 =
F_41 ( V_1 , 1 , 0 , V_21 , V_48 ) ;
F_18 ( V_11 ) ;
}
F_29 () ;
F_10 ( & V_46 , V_12 ) ;
return;
}
if ( V_11 == V_31 ) {
F_29 () ;
F_10 ( & V_46 , V_12 ) ;
F_42 ( 0 ) ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_11 == V_44 ) {
if ( F_36 () < 0 )
return;
goto V_43;
}
if ( V_11 == V_45 ) {
if ( F_43 ( 0 ) >= 0 ) {
V_47 = & F_20 ( - 1 ) ;
F_29 () ;
F_43 ( 0 ) ;
}
return;
}
F_28 ( V_1 , V_11 ) ;
}
static void F_44 ( T_1 * V_1 , T_2 V_11 )
{
T_1 * V_47 ;
T_2 V_28 ;
register T_1 * V_50 = V_1 ;
if ( V_49 ) {
F_39 () ;
return;
}
F_31 () ;
if ( V_11 == V_12 ) {
long V_51 ;
F_29 () ;
V_28 = F_15 ( V_50 ) ;
F_45 ( V_50 , V_47 ) ;
F_8 ( V_47 , F_2 ( V_47 ) ) ;
V_43:
V_51 = F_46 ( V_47 ) ;
F_19 ( & V_51 , 1 ) ;
F_47 ( V_47 , 0 ) ;
F_14 ( V_47 , V_28 ) ;
F_18 ( V_12 ) ;
return;
} else if ( V_11 == V_31 ) {
V_28 = F_15 ( V_1 ) ;
if ( F_48 ( 0 , V_32 ) < 0 )
return;
F_29 () ;
F_10 ( & V_30 , V_31 ) ;
F_14 ( V_47 , V_28 ) ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_11 == V_44 ) {
if ( F_36 () < 0 )
return;
F_29 () ;
V_28 = F_15 ( V_50 ) ;
F_32 ( V_50 , V_47 ) ;
goto V_43;
} else if ( V_11 == V_45 ) {
V_28 = F_15 ( V_1 ) ;
F_3 ( V_1 ) ;
F_29 () ;
F_10 ( & V_52 , V_40 ) ;
F_14 ( V_47 , V_28 ) ;
return;
} else if ( V_11 == V_34 ) {
if ( F_25 ( V_1 ) < 0 )
return;
F_29 () ;
F_10 ( V_1 , V_40 ) ;
return;
} else if ( V_11 == V_33 ) {
if ( V_7 & V_38 ) {
F_24 () ;
F_29 () ;
F_24 () ;
} else
F_27 ( V_53 ) ;
}
#ifdef F_26
else
F_27 ( V_35 | 0x119 ) ;
#endif
}
static void F_49 ( void )
{
F_31 () ;
V_54 -- ;
}
static void F_50 ( void )
{
F_31 () ;
V_54 ++ ;
}
static void F_51 ( T_1 * V_1 , T_2 V_11 )
{
int V_55 ;
F_31 () ;
if ( V_11 == V_12 ) {
T_2 V_10 ;
if ( F_17 ( V_1 ) ) {
F_43 ( 0 ) ;
return;
}
V_55 = F_2 ( V_1 ) ;
V_43:
F_8 ( V_1 , ( V_55 & 1 ) ) ;
V_10 = F_52 ( V_1 , 0 , 0 , V_7 , V_18 ) ;
F_53 ( V_1 , V_55 >> 1 ) ;
F_18 ( V_10 ) ;
return;
}
if ( V_11 == V_31 )
return;
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_11 == V_45 ) {
if ( F_17 ( V_1 ) )
F_43 ( 0 ) ;
return;
} else if ( V_11 == V_44 ) {
if ( F_17 ( V_1 ) ) {
F_43 ( 0 ) ;
return;
}
if ( F_36 () < 0 )
return;
F_32 ( V_1 , V_1 ) ;
V_55 = F_46 ( V_1 ) ;
goto V_43;
}
F_23 ( V_1 , V_11 ) ;
}
static void F_54 ( T_1 * V_1 , T_2 V_11 )
{
int V_56 , V_10 ;
if ( V_11 == V_12 ) {
T_2 V_28 ;
V_43:
V_28 = F_15 ( V_1 ) ;
if ( F_2 ( V_1 ) > 63 )
return;
if ( V_11 == V_44 ) {
if ( F_36 () < 0 )
return;
}
if ( ( V_56 = F_5 ( V_1 , V_11 ) ) )
F_55 ( V_56 ) ;
F_8 ( V_1 , 63 ) ;
V_10 = F_9 ( V_1 ) ;
F_14 ( V_1 , V_28 ) ;
F_18 ( V_10 ) ;
return;
}
if ( V_11 == V_31 )
return;
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_11 == V_44 )
goto V_43;
else if ( V_11 == V_45 )
return;
else
F_23 ( V_1 , V_11 ) ;
}
static int F_56 ( T_1 * V_1 , T_2 V_10 )
{
T_2 V_48 = F_15 ( V_1 ) ;
if ( V_10 == V_12 ) {
int V_5 ;
if ( F_2 ( V_1 ) > - 40 ) {
if ( ( V_5 = F_1 ( V_1 , 0 ) ) == - 1 ) {
return 1 ;
}
F_57 ( V_1 ) ;
if ( V_5 & 2 )
F_58 ( V_1 ) ;
F_14 ( V_1 , F_15 ( V_1 ) ^ V_48 ) ;
F_34 () ;
return 0 ;
} else {
F_34 () ;
return 0 ;
}
}
if ( V_10 == V_31 ) {
F_42 ( 0 ) ;
return 0 ;
}
if ( V_10 == V_40 )
V_10 = F_35 ( V_1 ) ;
if ( V_10 == V_44 ) {
if ( F_36 () < 0 )
return 1 ;
F_32 ( V_1 , V_1 ) ;
V_10 = F_41 ( V_1 , 1 , 0 , V_21 , V_48 ) ;
F_18 ( V_10 ) ;
return 0 ;
} else if ( V_10 == V_45 ) {
F_43 ( 0 ) ;
return 1 ;
} else {
F_23 ( V_1 , V_10 ) ;
return 1 ;
}
}
static int F_59 ( T_1 * V_1 , T_2 V_10 )
{
T_2 V_57 ;
V_57 = F_15 ( V_1 ) ;
if ( V_10 == V_12 ) {
int V_5 ;
if ( F_2 ( V_1 ) > - 40 ) {
if ( ( F_2 ( V_1 ) < 0 )
|| ( ( F_2 ( V_1 ) == 0 )
&& ( F_6 ( V_1 ) <=
0xc90fdaa22168c234LL ) ) ) {
F_60 ( V_1 ) ;
F_61 () ;
return 0 ;
} else if ( ( V_5 = F_1 ( V_1 , V_58 ) ) != - 1 ) {
F_57 ( V_1 ) ;
if ( ( V_5 + 1 ) & 2 )
F_58 ( V_1 ) ;
F_61 () ;
return 0 ;
} else {
return 1 ;
}
} else {
V_43:
F_42 ( 0 ) ;
F_10 ( & V_46 , V_12 ) ;
#ifdef F_62
F_61 () ;
#else
F_34 () ;
#endif
return 0 ;
}
} else if ( V_10 == V_31 ) {
F_10 ( & V_46 , V_12 ) ;
F_42 ( 0 ) ;
return 0 ;
}
if ( V_10 == V_40 )
V_10 = F_35 ( V_1 ) ;
if ( V_10 == V_44 ) {
if ( F_36 () < 0 )
return 1 ;
goto V_43;
} else if ( V_10 == V_45 ) {
F_43 ( 0 ) ;
return 1 ;
} else {
F_23 ( V_1 , V_10 ) ;
return 1 ;
}
}
static void F_63 ( T_1 * V_1 , T_2 V_11 )
{
F_59 ( V_1 , V_11 ) ;
}
static void F_64 ( T_1 * V_1 , T_2 V_11 )
{
T_1 * V_47 ;
T_1 V_25 ;
T_2 V_10 ;
if ( V_11 == V_33 ) {
F_24 () ;
if ( V_7 & V_39 ) {
V_47 = & F_20 ( - 1 ) ;
F_29 () ;
F_24 () ;
}
return;
}
if ( V_49 ) {
F_39 () ;
return;
}
if ( V_11 == V_40 )
V_10 = F_35 ( V_1 ) ;
else
V_10 = V_11 ;
if ( V_10 == V_34 ) {
F_28 ( V_1 , V_34 ) ;
return;
} else if ( V_10 == V_45 ) {
if ( F_43 ( 0 ) >= 0 ) {
F_29 () ;
F_43 ( 0 ) ;
}
return;
}
F_45 ( V_1 , & V_25 ) ;
if ( ! F_56 ( V_1 , V_11 ) ) {
F_29 () ;
F_10 ( & V_25 , V_11 ) ;
F_59 ( & F_20 ( 0 ) , V_11 ) ;
} else {
F_10 ( & V_25 , V_11 ) ;
}
}
static void F_7 ( unsigned long long V_59 , unsigned long long * V_60 ,
unsigned long long V_61 , unsigned long long V_5 , int V_62 )
{
int V_63 ;
unsigned long long V_64 ;
V_64 = V_59 << V_62 ;
asm volatile ("mull %4; subl %%eax,%0; sbbl %%edx,%1":"=m"
(((unsigned *)&x)[0]), "=m"(((unsigned *)&x)[1]),
"=a"(dummy)
:"2"(((unsigned *)&st1)[0]), "m"(((unsigned *)&q)[0])
:"%dx");
asm volatile ("mull %3; subl %%eax,%0":"=m" (((unsigned *)&x)[1]),
"=a"(dummy)
:"1"(((unsigned *)&st1)[1]), "m"(((unsigned *)&q)[0])
:"%dx");
asm volatile ("mull %3; subl %%eax,%0":"=m" (((unsigned *)&x)[1]),
"=a"(dummy)
:"1"(((unsigned *)&st1)[0]), "m"(((unsigned *)&q)[1])
:"%dx");
* V_60 = V_64 ;
}
static void F_65 ( T_1 * V_1 , T_2 V_11 , int V_65 )
{
T_1 * V_50 = & F_20 ( 1 ) ;
T_2 V_66 = F_66 ( 1 ) ;
if ( ! ( ( V_11 ^ V_12 ) | ( V_66 ^ V_12 ) ) ) {
T_1 V_3 , V_59 , V_61 ;
T_2 V_57 , V_67 ;
T_2 V_4 ;
int V_10 ;
int V_6 ;
int V_68 ;
long long V_5 ;
unsigned short V_8 ;
int V_69 ;
V_70:
V_57 = F_32 ( V_1 , & V_59 ) ;
V_67 = F_32 ( V_50 , & V_61 ) ;
V_68 = F_46 ( & V_59 ) - F_46 ( & V_61 ) ;
V_6 = V_7 ;
V_69 = 0 ;
V_8 = V_9 ;
V_7 &= ~ V_14 ;
V_7 |= V_15 ;
if ( V_68 < 64 ) {
if ( V_68 > - 2 ) {
T_2 V_28 = V_57 ^ V_67 ;
V_10 = F_4 ( & V_59 , & V_61 , & V_3 ,
V_17 | V_15 | 0x3f ,
V_28 ) ;
F_14 ( & V_3 , V_28 ) ;
if ( F_2 ( & V_3 ) >= 0 ) {
F_5 ( & V_3 , V_10 ) ;
V_5 = F_6 ( & V_3 ) ;
F_7 ( F_6 ( & V_59 ) ,
& F_6 ( & V_3 ) ,
F_6 ( & V_61 ) ,
V_5 , V_68 ) ;
F_8 ( & V_3 , F_46 ( & V_61 ) ) ;
} else {
F_45 ( & V_59 , & V_3 ) ;
V_5 = 0 ;
}
if ( ( V_65 == V_71 )
&& ( V_3 . V_23 & 0xc0000000 ) ) {
unsigned long long V_64 ;
V_68 =
F_46 ( & V_61 ) - F_46 ( & V_3 ) ;
if ( V_68 <= 1 ) {
if ( V_68 == 0 )
V_64 = F_6 ( & V_61 ) -
F_6 ( & V_3 ) ;
else
V_64 = ( F_6 ( & V_61 )
<< 1 ) -
F_6 ( & V_3 ) ;
if ( ( V_64 < F_6 ( & V_3 ) ) ||
( ( V_64 == F_6 ( & V_3 ) )
&& ( V_5 & 1 ) ) ) {
V_57 = ! V_57 ;
F_6 ( & V_3 ) = V_64 ;
V_5 ++ ;
}
}
}
if ( V_5 & 4 )
V_69 |= V_72 ;
if ( V_5 & 2 )
V_69 |= V_73 ;
if ( V_5 & 1 )
V_69 |= V_74 ;
} else {
V_7 = V_6 ;
F_42 ( 0 ) ;
return;
}
} else {
int V_75 , V_76 ;
T_2 V_28 ;
F_45 ( & V_59 , & V_3 ) ;
V_4 = V_11 ;
V_76 = ( V_68 & 0x0000001f ) + 32 ;
F_8 ( & V_3 , V_76 ) ;
V_75 = F_46 ( & V_61 ) ;
F_8 ( & V_61 , 0 ) ;
V_68 -= V_76 ;
V_28 = F_15 ( & V_3 ) ^ V_67 ;
V_10 =
F_4 ( & V_3 , & V_61 , & V_3 ,
V_17 | V_15 | 0x3f , V_28 ) ;
F_14 ( & V_3 , V_28 ) ;
F_5 ( & V_3 , V_10 ) ;
F_7 ( F_6 ( & V_59 ) ,
& F_6 ( & V_3 ) ,
F_6 ( & V_61 ) ,
F_6 ( & V_3 ) , F_2 ( & V_3 )
) ;
F_8 ( & V_3 , V_75 + V_68 ) ;
if ( ! ( V_3 . V_23 | V_3 . V_24 ) ) {
V_7 = V_6 ;
V_9 = V_8 ;
F_10 ( & V_30 , V_31 ) ;
F_14 ( & V_59 , V_57 ) ;
#ifdef F_62
F_42 ( V_13 ) ;
#else
F_42 ( 0 ) ;
#endif
return;
}
V_69 = V_13 ;
}
V_7 = V_6 ;
V_9 = V_8 ;
V_10 = F_67 ( & V_3 ) ;
F_45 ( & V_3 , V_1 ) ;
if ( ( F_46 ( & V_3 ) <= V_77 ) && ( V_10 != V_31 )
&& ! ( V_7 & V_78 ) ) {
F_42 ( V_69 ) ;
V_10 = F_68 ( V_1 ) ;
F_14 ( V_1 , V_57 ) ;
F_18 ( V_10 ) ;
return;
} else if ( ( F_46 ( & V_3 ) > V_77 ) || ( V_10 == V_31 ) ) {
F_69 ( V_1 ) ;
F_14 ( V_1 , V_57 ) ;
} else {
V_10 =
F_41 ( V_1 , 0 , 0 , V_21 , V_57 ) ;
}
F_18 ( V_10 ) ;
F_42 ( V_69 ) ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_66 == V_40 )
V_66 = F_35 ( V_50 ) ;
if ( ( ( V_11 == V_12 ) && ( V_66 == V_44 ) )
|| ( ( V_11 == V_44 ) && ( V_66 == V_12 ) )
|| ( ( V_11 == V_44 ) && ( V_66 == V_44 ) ) ) {
if ( F_36 () < 0 )
return;
goto V_70;
} else if ( ( V_11 == V_33 ) || ( V_66 == V_33 ) ) {
F_24 () ;
return;
} else if ( V_11 == V_31 ) {
if ( V_66 == V_12 ) {
F_42 ( 0 ) ;
return;
} else if ( V_66 == V_44 ) {
if ( F_36 () < 0 )
return;
F_42 ( 0 ) ;
return;
} else if ( V_66 == V_31 ) {
F_43 ( 0 ) ;
return;
}
else if ( V_66 == V_45 ) {
F_42 ( 0 ) ;
return;
}
} else if ( ( V_11 == V_12 ) || ( V_11 == V_44 ) ) {
if ( V_66 == V_31 ) {
F_43 ( 0 ) ;
return;
} else if ( V_66 != V_34 ) {
if ( ( ( V_11 == V_44 )
|| ( V_66 == V_44 ) )
&& ( F_36 () < 0 ) )
return;
if ( V_66 == V_45 ) {
F_42 ( 0 ) ;
return;
}
}
} else if ( V_11 == V_45 ) {
if ( V_66 != V_34 ) {
F_43 ( 0 ) ;
return;
}
}
#ifdef F_26
if ( ( V_11 != V_34 ) && ( V_66 != V_34 ) )
F_27 ( V_35 | 0x118 ) ;
#endif
F_70 ( V_50 , V_66 , 0 , V_50 ) ;
}
static void F_71 ( T_1 * V_1 , T_2 V_11 )
{
T_1 * V_50 = & F_20 ( 1 ) , F_2 ;
T_2 V_66 = F_66 ( 1 ) ;
T_2 V_28 ;
int V_51 , V_10 ;
F_31 () ;
if ( ( V_11 == V_12 ) && ( V_66 == V_12 ) ) {
V_79:
if ( F_72 ( V_1 ) ) {
if ( V_11 == V_44 )
F_32 ( V_1 , V_1 ) ;
else
F_8 ( V_1 , F_2 ( V_1 ) ) ;
if ( ( V_1 -> V_23 == 0x80000000 )
&& ( V_1 -> V_24 == 0 ) ) {
T_2 V_80 ;
V_51 = F_46 ( V_1 ) ;
if ( V_51 >= 0 ) {
F_2 . V_23 = V_51 ;
V_80 = V_18 ;
} else {
F_2 . V_23 = - V_51 ;
V_80 = V_32 ;
}
F_2 . V_24 = 0 ;
F_8 ( & F_2 , 31 ) ;
V_10 = F_67 ( & F_2 ) ;
F_69 ( & F_2 ) ;
F_14 ( & F_2 , V_80 ) ;
V_10 =
F_73 ( & F_2 , V_10 , 1 , V_21 ) ;
if ( V_10 >= 0 )
F_22 ( 1 , V_10 ) ;
} else {
V_28 = F_15 ( V_50 ) ;
if ( V_66 == V_44 )
F_32 ( V_50 , V_50 ) ;
else
F_8 ( V_50 ,
F_2 ( V_50 ) ) ;
F_74 ( V_1 , V_50 , V_28 ) ;
}
} else {
if ( F_43 ( 1 ) < 0 )
return;
}
F_75 () ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_66 == V_40 )
V_66 = F_35 ( V_50 ) ;
if ( ( V_11 == V_33 ) || ( V_66 == V_33 ) ) {
F_76 ( 1 ) ;
return;
} else if ( ( V_11 <= V_44 ) && ( V_66 <= V_44 ) ) {
if ( V_11 == V_31 ) {
if ( V_66 == V_31 ) {
if ( F_43 ( 1 ) < 0 )
return;
} else {
T_2 V_28 ;
V_28 = F_15 ( V_50 ) ^ V_32 ;
if ( F_48 ( 1 , V_28 ) < 0 )
return;
F_14 ( V_50 , V_28 ) ;
}
} else if ( V_66 == V_31 ) {
V_28 = F_15 ( V_50 ) ;
if ( F_17 ( V_1 ) ) {
if ( F_43 ( 1 ) < 0 )
return;
} else if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
else {
if ( F_2 ( V_1 ) < 0 )
V_28 ^= V_32 ;
F_77 ( & V_30 , V_31 ) ;
F_14 ( V_50 , V_28 ) ;
}
} else {
if ( F_36 () < 0 )
return;
goto V_79;
}
} else if ( ( V_11 == V_34 ) || ( V_66 == V_34 ) ) {
if ( F_70 ( V_1 , V_11 , 1 , V_1 ) < 0 )
return;
}
else if ( V_11 == V_45 ) {
if ( ( F_17 ( V_1 ) ) || ( V_66 == V_31 ) ) {
if ( F_43 ( 1 ) < 0 )
return;
} else {
T_2 V_28 = F_15 ( V_50 ) ;
if ( ( V_66 == V_44 )
&& ( F_36 () < 0 ) )
return;
F_77 ( & V_52 , V_40 ) ;
F_14 ( V_50 , V_28 ) ;
}
}
else if ( ( ( V_11 == V_12 ) || ( V_11 == V_44 ) )
&& ( F_72 ( V_1 ) ) ) {
if ( F_2 ( V_1 ) >= 0 ) {
if ( ( F_2 ( V_1 ) == 0 ) &&
( V_1 -> V_23 == 0x80000000 ) &&
( V_1 -> V_24 == 0 ) ) {
if ( F_43 ( 1 ) < 0 )
return;
}
} else {
if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
F_58 ( V_50 ) ;
}
} else {
if ( V_11 == V_31 ) {
#ifndef F_62
V_28 = F_15 ( V_50 ) ;
if ( F_48 ( 1 , V_28 ) < 0 )
return;
#endif
F_58 ( V_50 ) ;
} else if ( F_43 ( 1 ) < 0 )
return;
}
F_75 () ;
}
static void F_78 ( T_1 * V_1 , T_2 V_11 )
{
T_1 * V_50 = & F_20 ( 1 ) ;
T_2 V_66 = F_66 ( 1 ) ;
int V_10 ;
F_31 () ;
if ( ! ( ( V_11 ^ V_12 ) | ( V_66 ^ V_12 ) ) ) {
V_81:
F_79 ( V_1 , V_11 , V_50 , V_66 ) ;
F_75 () ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_66 == V_40 )
V_66 = F_35 ( V_50 ) ;
if ( ( ( V_11 == V_12 ) && ( V_66 == V_44 ) )
|| ( ( V_11 == V_44 ) && ( V_66 == V_12 ) )
|| ( ( V_11 == V_44 ) && ( V_66 == V_44 ) ) ) {
if ( F_36 () < 0 )
return;
goto V_81;
} else if ( ( V_11 == V_33 ) || ( V_66 == V_33 ) ) {
F_76 ( 1 ) ;
return;
} else if ( ( V_11 == V_34 ) || ( V_66 == V_34 ) ) {
if ( F_70 ( V_1 , V_11 , 1 , V_1 ) >= 0 )
F_75 () ;
return;
} else if ( ( V_11 == V_45 ) || ( V_66 == V_45 ) ) {
T_2 V_28 = F_15 ( V_50 ) ;
if ( V_11 == V_45 ) {
if ( V_66 == V_45 ) {
if ( F_72 ( V_1 ) ) {
F_77 ( & V_82 , V_12 ) ;
} else {
F_3 ( V_50 ) ;
V_10 =
F_80 ( & V_82 , & V_16 ,
V_50 , V_21 ,
V_18 ,
F_2 ( & V_82 ) ,
F_2 ( & V_16 ) ) ;
if ( V_10 >= 0 )
F_22 ( 1 , V_10 ) ;
}
} else {
if ( ( V_66 == V_44 )
&& ( F_36 () < 0 ) )
return;
if ( F_72 ( V_1 ) ) {
F_77 ( & V_30 , V_31 ) ;
F_14 ( V_50 , V_28 ) ;
F_75 () ;
return;
} else {
F_77 ( & V_83 , V_12 ) ;
}
}
} else {
if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
F_77 ( & V_16 , V_12 ) ;
}
F_14 ( V_50 , V_28 ) ;
} else if ( V_66 == V_31 ) {
T_2 V_28 = F_15 ( V_50 ) ;
if ( ( V_11 == V_44 ) && ( F_36 () < 0 ) )
return;
if ( F_72 ( V_1 ) ) {
F_75 () ;
return;
}
F_77 ( & V_83 , V_12 ) ;
F_14 ( V_50 , V_28 ) ;
} else if ( V_11 == V_31 ) {
T_2 V_28 = F_15 ( V_50 ) ;
if ( ( V_66 == V_44 ) && ( F_36 () < 0 ) )
return;
F_77 ( & V_16 , V_12 ) ;
F_14 ( V_50 , V_28 ) ;
}
#ifdef F_26
else
F_27 ( V_35 | 0x125 ) ;
#endif
F_75 () ;
F_34 () ;
}
static void F_81 ( T_1 * V_1 , T_2 V_11 )
{
F_65 ( V_1 , V_11 , V_15 ) ;
}
static void F_82 ( T_1 * V_1 , T_2 V_11 )
{
F_65 ( V_1 , V_11 , V_71 ) ;
}
static void F_83 ( T_1 * V_1 , T_2 V_11 )
{
T_2 V_28 , V_84 ;
T_1 * V_50 = & F_20 ( 1 ) , V_42 , V_85 ;
T_2 V_66 = F_66 ( 1 ) ;
F_31 () ;
if ( ! ( ( V_11 ^ V_12 ) | ( V_66 ^ V_12 ) ) ) {
V_86:
V_28 = F_15 ( V_1 ) ;
V_84 = F_15 ( V_50 ) ;
F_32 ( V_1 , & V_42 ) ;
F_32 ( V_50 , & V_85 ) ;
if ( F_84 ( V_28 , V_84 , & V_42 , & V_85 , V_50 ) )
return;
F_75 () ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_66 == V_40 )
V_66 = F_35 ( V_50 ) ;
if ( ( ( V_11 == V_12 ) && ( V_66 == V_44 ) )
|| ( ( V_11 == V_44 ) && ( V_66 == V_12 ) )
|| ( ( V_11 == V_44 ) && ( V_66 == V_44 ) ) ) {
if ( F_36 () < 0 )
return;
goto V_86;
} else if ( ( V_11 == V_33 ) | ( V_66 == V_33 ) ) {
F_76 ( 1 ) ;
return;
} else if ( V_11 == V_31 ) {
switch ( V_66 ) {
case V_44 :
if ( F_36 () < 0 )
return;
case V_31 :
case V_12 :
F_14 ( V_1 , F_15 ( V_1 ) ^ F_15 ( V_50 ) ) ;
F_77 ( V_1 , V_11 ) ;
break;
case V_45 :
if ( F_43 ( 1 ) < 0 )
return;
break;
case V_34 :
if ( F_70 ( V_1 , V_11 , 1 , V_1 ) < 0 )
return;
break;
default:
#ifdef F_26
F_27 ( V_35 | 0x116 ) ;
return;
#endif
break;
}
} else if ( ( V_11 == V_12 ) || ( V_11 == V_44 ) ) {
switch ( V_66 ) {
case V_31 :
if ( F_17 ( V_1 ) ) {
if ( F_2 ( V_1 ) >= 0 ) {
#ifdef F_62
F_58 ( V_50 ) ;
#else
if ( F_43 ( 1 ) < 0 )
return;
#endif
} else if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
else
F_58 ( V_50 ) ;
} else if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
break;
case V_45 :
if ( F_17 ( V_1 ) ) {
if ( ( F_2 ( V_1 ) >= 0 ) &&
! ( ( V_1 -> V_23 == 0x80000000 ) &&
( V_1 -> V_24 == 0 ) ) ) {
#ifdef F_62
F_58 ( V_50 ) ;
#else
if ( F_43 ( 1 ) < 0 )
return;
#endif
} else if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
else
F_58 ( V_50 ) ;
} else if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
break;
case V_34 :
if ( F_70 ( V_1 , V_11 , 1 , V_1 ) < 0 )
return;
}
} else if ( V_11 == V_34 ) {
if ( F_70 ( V_1 , V_11 , 1 , V_1 ) < 0 )
return;
} else if ( V_11 == V_45 ) {
if ( V_66 == V_34 ) {
if ( F_70 ( V_1 , V_11 , 1 , V_1 ) < 0 )
return;
} else if ( F_17 ( V_1 ) ) {
#ifndef F_62
if ( F_43 ( 1 ) < 0 )
return;
#endif
if ( ( V_66 == V_44 )
&& ( F_36 () < 0 ) )
return;
#ifdef F_62
if ( F_43 ( 1 ) < 0 )
return;
#endif
} else if ( V_66 == V_31 ) {
if ( F_43 ( 1 ) < 0 )
return;
}
else if ( ( V_66 == V_44 ) && ( F_36 () < 0 ) )
return;
else {
T_2 V_28 = F_15 ( V_50 ) ;
F_77 ( & V_52 , V_40 ) ;
F_14 ( V_50 , V_28 ) ;
}
}
#ifdef F_26
else {
F_27 ( V_35 | 0x117 ) ;
return;
}
#endif
F_75 () ;
return;
}
static void F_85 ( T_1 * V_1 , T_2 V_11 )
{
T_1 * V_50 = & F_20 ( 1 ) ;
T_2 V_66 = F_66 ( 1 ) ;
int V_6 = V_7 ;
T_2 V_28 = F_15 ( V_1 ) ;
F_31 () ;
if ( ! ( ( V_11 ^ V_12 ) | ( V_66 ^ V_12 ) ) ) {
long V_87 ;
T_1 V_3 ;
F_8 ( V_1 , F_2 ( V_1 ) ) ;
V_88:
if ( F_2 ( V_50 ) > 30 ) {
if ( F_72 ( V_50 ) ) {
F_27 ( V_89 ) ;
F_10 ( & V_52 , V_40 ) ;
} else {
F_27 ( V_90 ) ;
F_10 ( & V_30 , V_31 ) ;
}
F_14 ( V_1 , V_28 ) ;
return;
}
V_7 &= ~ V_14 ;
V_7 |= V_15 ;
F_45 ( V_50 , & V_3 ) ;
F_5 ( & V_3 , V_66 ) ;
V_7 = V_6 ;
V_87 = F_17 ( V_50 ) ? - V_3 . V_24 : V_3 . V_24 ;
V_87 += F_46 ( V_1 ) ;
F_8 ( V_1 , V_87 ) ;
F_41 ( V_1 , 0 , 0 , V_7 , V_28 ) ;
return;
}
if ( V_11 == V_40 )
V_11 = F_35 ( V_1 ) ;
if ( V_66 == V_40 )
V_66 = F_35 ( V_50 ) ;
if ( ( V_11 == V_12 ) || ( V_11 == V_44 ) ) {
switch ( V_66 ) {
case V_12 :
if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
F_32 ( V_1 , V_1 ) ;
goto V_88;
case V_31 :
if ( V_11 == V_44 )
F_36 () ;
return;
case V_44 :
F_36 () ;
return;
case V_45 :
if ( ( V_11 == V_44 )
&& ( F_36 () < 0 ) )
return;
if ( F_72 ( V_50 ) )
F_10 ( & V_52 , V_40 ) ;
else
F_10 ( & V_30 , V_31 ) ;
F_14 ( V_1 , V_28 ) ;
return;
case V_34 :
F_70 ( V_50 , V_66 , 0 , V_1 ) ;
return;
}
} else if ( V_11 == V_31 ) {
switch ( V_66 ) {
case V_12 :
case V_31 :
return;
case V_44 :
F_36 () ;
return;
case V_45 :
if ( F_72 ( V_50 ) )
F_43 ( 0 ) ;
return;
case V_34 :
F_70 ( V_50 , V_66 , 0 , V_1 ) ;
return;
}
} else if ( V_11 == V_45 ) {
switch ( V_66 ) {
case V_12 :
case V_31 :
return;
case V_44 :
F_36 () ;
return;
case V_45 :
if ( F_17 ( V_50 ) )
F_43 ( 0 ) ;
return;
case V_34 :
F_70 ( V_50 , V_66 , 0 , V_1 ) ;
return;
}
} else if ( V_11 == V_34 ) {
if ( V_66 != V_33 ) {
F_70 ( V_50 , V_66 , 0 , V_1 ) ;
return;
}
}
#ifdef F_26
if ( ! ( ( V_11 == V_33 ) || ( V_66 == V_33 ) ) ) {
F_27 ( V_35 | 0x115 ) ;
return;
}
#endif
F_24 () ;
}
void F_86 ( void )
{
( V_91 [ V_92 ] ) ( & F_20 ( 0 ) , F_87 () ) ;
}
void F_88 ( void )
{
( V_93 [ V_92 ] ) ( & F_20 ( 0 ) , F_87 () ) ;
}
