static inline int F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 & 0xFFFF ) ;
return 30 - V_2 ;
}
static inline int F_3 ( int V_1 , unsigned long V_3 )
{
if ( V_1 & V_4 )
return ! ! ( V_3 & V_5 ) ;
else
return ! ! ( V_3 & V_6 ) ;
}
T_1 static int F_4 ( unsigned int V_7 )
{
int V_8 ;
for ( V_8 = V_9 ; V_8 < V_10 ; V_8 ++ )
if ( ( V_11 [ V_7 ] [ V_8 ] . V_3 & V_12 ) == 0 )
return V_8 ;
V_8 = V_9 + V_13 [ V_7 ] ;
if ( V_8 >= V_10 ) {
V_8 -= V_10 - V_9 ;
V_13 [ V_7 ] -= V_10 - V_9 ;
}
V_13 [ V_7 ] ++ ;
return V_8 ;
}
T_1 static int F_5 ( unsigned int V_7 )
{
int V_8 ;
for ( V_8 = V_14 ; V_8 < V_10 ; V_8 ++ )
if ( ( V_15 [ V_7 ] [ V_8 ] . V_3 & V_12 ) == 0 )
return V_8 ;
V_8 = V_14 + V_16 [ V_7 ] ;
if ( V_8 >= V_10 ) {
V_8 -= V_10 - V_14 ;
V_16 [ V_7 ] -= V_10 - V_14 ;
}
V_16 [ V_7 ] ++ ;
return V_8 ;
}
T_1 static T_2 int F_6 ( unsigned int V_7 )
{
unsigned long V_17 = F_7 () ;
int V_1 = F_8 () ;
unsigned long * V_18 ;
int V_19 ;
unsigned long V_20 ;
V_21 [ V_7 ] ++ ;
V_20 = V_5 | V_12 | V_22 | V_23 ;
#ifdef F_9
if ( F_10 ( V_17 ) ) {
V_20 |= V_24 | V_25 ;
# ifdef F_11
V_20 |= V_26 | V_27 ;
# endif
}
#endif
if ( V_28 && V_17 >= V_29 && V_17 < V_29 + V_28 ) {
V_17 = V_29 ;
V_20 = V_30 ;
} else if ( V_17 >= V_31 ) {
if ( V_17 >= V_32 && V_17 < V_33 + V_34 ) {
#if F_12 ( V_35 ) && F_12 ( V_36 )
V_18 = V_37 [ V_7 ] ;
if ( V_18 ) {
int V_38 = ( V_17 - ( V_32 - V_39 ) ) >> V_40 ;
int V_19 = V_38 >> 5 ;
int V_41 = 1 << ( V_38 & 31 ) ;
if ( V_18 [ V_19 ] & V_41 )
V_20 |= V_42 ;
}
#endif
} else if ( V_17 >= V_43 && V_17 < V_43 + V_44
&& ( V_1 & ( V_45 | V_4 ) ) == V_4 ) {
V_17 &= ~ ( 1 * 1024 * 1024 - 1 ) ;
V_20 &= ~ V_23 ;
V_20 |= V_46 ;
} else
return V_47 ;
} else if ( V_17 >= V_39 ) {
V_20 |= V_42 | V_6 ;
if ( V_48 )
V_20 |= V_24 ;
} else {
V_18 = V_37 [ V_7 ] ;
if ( V_18 ) {
int V_38 = V_17 >> V_40 ;
int V_19 = V_38 >> 5 ;
int V_41 = 1 << ( V_38 & 31 ) ;
if ( V_18 [ V_19 ] & V_41 )
V_20 |= V_42 ;
V_18 += V_49 ;
if ( V_18 [ V_19 ] & V_41 )
V_20 |= V_6 ;
}
}
V_19 = F_5 ( V_7 ) ;
V_17 &= V_50 ;
V_15 [ V_7 ] [ V_19 ] . V_17 = V_17 ;
V_15 [ V_7 ] [ V_19 ] . V_3 = V_20 ;
F_13 () ;
F_14 ( V_51 + V_19 * 4 , V_20 ) ;
F_14 ( V_52 + V_19 * 4 , V_17 ) ;
F_15 () ;
return 0 ;
}
T_1 static T_2 int F_16 ( unsigned int V_7 )
{
unsigned long V_17 = F_17 () ;
int V_1 = F_18 () ;
int V_19 ;
unsigned long V_53 ;
V_54 [ V_7 ] ++ ;
if ( V_17 >= V_39 - V_55 && V_17 < V_39 )
return V_47 ;
if ( V_1 & V_4 )
V_56 [ V_7 ] ++ ;
for ( V_19 = V_9 ; V_19 < V_10 ; V_19 ++ ) {
if ( V_11 [ V_7 ] [ V_19 ] . V_3 & V_12 ) {
unsigned long V_57 = V_11 [ V_7 ] [ V_19 ] . V_17 ;
if ( V_57 <= V_17 && V_57 + V_58 > V_17 ) {
V_17 += V_58 ;
break;
}
}
}
V_53 = V_12 | V_59 | V_23 ;
#ifdef F_19
if ( V_17 < V_39 ||
( V_17 < V_31 && V_60 ) )
V_53 |= V_24 | V_25 ;
#endif
if ( V_28 && V_17 >= V_29 && V_17 < V_29 + V_28 ) {
V_17 = V_29 ;
V_53 = V_61 ;
} else if ( V_17 >= V_31 ) {
if ( V_17 >= V_32 && V_17 < V_33 + V_34 ) {
if ( ! ( V_1 & V_4 ) ) {
unsigned long * V_18 = V_37 [ V_7 ] ;
if ( V_18 ) {
int V_38 = ( V_17 - ( V_32 - V_39 ) ) >> V_40 ;
int V_19 = V_38 >> 5 ;
int V_41 = 1 << ( V_38 & 31 ) ;
V_18 += 2 * V_49 ;
if ( V_18 [ V_19 ] & V_41 )
V_53 |= V_42 ;
}
}
} else if ( V_17 >= V_43 && V_17 < V_43 + V_44
&& ( V_1 & V_4 ) ) {
V_17 &= ~ ( 1 * 1024 * 1024 - 1 ) ;
V_53 &= ~ V_23 ;
V_53 |= V_46 ;
} else
return V_47 ;
} else if ( V_17 >= V_39 ) {
V_53 |= V_42 ;
if ( V_60 )
V_53 |= V_24 ;
} else {
if ( ! ( V_1 & V_4 ) ) {
unsigned long * V_18 = V_37 [ V_7 ] ;
if ( V_18 ) {
int V_38 = V_17 >> V_40 ;
int V_19 = V_38 >> 5 ;
int V_41 = 1 << ( V_38 & 31 ) ;
V_18 += 2 * V_49 ;
if ( V_18 [ V_19 ] & V_41 )
V_53 |= V_42 ;
}
}
}
V_19 = F_4 ( V_7 ) ;
V_17 &= V_50 ;
V_11 [ V_7 ] [ V_19 ] . V_17 = V_17 ;
V_11 [ V_7 ] [ V_19 ] . V_3 = V_53 ;
F_20 () ;
F_14 ( V_62 + V_19 * 4 , V_53 ) ;
F_14 ( V_63 + V_19 * 4 , V_17 ) ;
F_21 () ;
return 0 ;
}
T_1 static T_2 int F_22 ( unsigned int V_7 )
{
int V_1 = F_8 () ;
V_64 [ V_7 ] ++ ;
if ( V_1 & V_45 ) {
int V_19 = F_1 ( V_1 ) ;
unsigned long V_3 = V_15 [ V_7 ] [ V_19 ] . V_3 ;
if ( ! ( V_3 & V_27 ) && ! ( V_3 & V_22 ) &&
F_3 ( V_1 , V_3 ) ) {
V_3 |= V_22 ;
V_15 [ V_7 ] [ V_19 ] . V_3 = V_3 ;
F_14 ( V_51 + V_19 * 4 , V_3 ) ;
return 0 ;
}
}
return V_47 ;
}
T_1 int F_23 ( int V_65 , struct V_66 * V_67 )
{
int V_68 = V_65 & 0x3f ;
unsigned int V_7 = F_24 () ;
switch ( V_68 ) {
case 0x23 :
return F_22 ( V_7 ) ;
case 0x2C :
return F_16 ( V_7 ) ;
case 0x26 :
return F_6 ( V_7 ) ;
default:
return 1 ;
}
}
void F_25 ( unsigned int V_7 )
{
int V_8 ;
unsigned long V_69 ;
V_70 [ V_7 ] ++ ;
V_69 = F_26 () ;
F_20 () ;
for ( V_8 = V_9 ; V_8 < V_10 ; V_8 ++ ) {
V_11 [ V_7 ] [ V_8 ] . V_3 = 0 ;
F_14 ( V_62 + V_8 * 4 , 0 ) ;
}
F_21 () ;
F_13 () ;
for ( V_8 = V_14 ; V_8 < V_10 ; V_8 ++ ) {
V_15 [ V_7 ] [ V_8 ] . V_3 = 0 ;
F_14 ( V_51 + V_8 * 4 , 0 ) ;
}
F_15 () ;
F_27 ( V_69 ) ;
}
void F_28 ( unsigned long * V_71 , unsigned int V_7 )
{
int V_8 ;
unsigned long V_17 = ( unsigned long ) V_71 ;
unsigned long V_20 ;
unsigned long V_69 ;
if ( ! V_71 ) {
V_37 [ V_7 ] = V_71 ;
return;
}
V_69 = F_26 () ;
V_37 [ V_7 ] = V_71 ;
if ( V_28 && V_17 >= V_29 && V_17 < V_29 + V_28 ) {
V_17 = V_29 ;
V_20 = V_30 ;
} else {
V_20 = V_5 | V_12 | V_22 | V_23 ;
#ifdef F_9
V_20 |= V_24 ;
# ifdef F_11
V_20 |= V_26 | V_27 ;
# endif
#endif
}
F_13 () ;
for ( V_8 = V_72 ; V_8 < V_14 ; V_8 ++ ) {
V_15 [ V_7 ] [ V_8 ] . V_17 = V_17 ;
V_15 [ V_7 ] [ V_8 ] . V_3 = V_20 ;
F_14 ( V_51 + V_8 * 4 , V_20 ) ;
F_14 ( V_52 + V_8 * 4 , V_17 ) ;
V_17 += V_58 ;
}
F_15 () ;
F_27 ( V_69 ) ;
}
