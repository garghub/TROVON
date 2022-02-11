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
V_18 = V_35 [ V_7 ] ;
if ( V_18 ) {
int V_36 = ( V_17 - ( V_32 - V_37 ) ) >> V_38 ;
int V_19 = V_36 >> 5 ;
int V_39 = 1 << ( V_36 & 31 ) ;
if ( V_18 [ V_19 ] & V_39 )
V_20 |= V_40 ;
}
} else if ( V_17 >= V_41 && V_17 < V_41 + V_42
&& ( V_1 & ( V_43 | V_4 ) ) == V_4 ) {
V_17 &= ~ ( 1 * 1024 * 1024 - 1 ) ;
V_20 &= ~ V_23 ;
V_20 |= V_44 ;
} else
return V_45 ;
} else if ( V_17 >= V_37 ) {
V_20 |= V_40 | V_6 ;
if ( V_46 )
V_20 |= V_24 ;
} else {
V_18 = V_35 [ V_7 ] ;
if ( V_18 ) {
int V_36 = V_17 >> V_38 ;
int V_19 = V_36 >> 5 ;
int V_39 = 1 << ( V_36 & 31 ) ;
if ( V_18 [ V_19 ] & V_39 )
V_20 |= V_40 ;
V_18 += V_47 ;
if ( V_18 [ V_19 ] & V_39 )
V_20 |= V_6 ;
}
}
V_19 = F_5 ( V_7 ) ;
V_17 &= V_48 ;
V_15 [ V_7 ] [ V_19 ] . V_17 = V_17 ;
V_15 [ V_7 ] [ V_19 ] . V_3 = V_20 ;
F_12 () ;
F_13 ( V_49 + V_19 * 4 , V_20 ) ;
F_13 ( V_50 + V_19 * 4 , V_17 ) ;
F_14 () ;
return 0 ;
}
T_1 static T_2 int F_15 ( unsigned int V_7 )
{
unsigned long V_17 = F_16 () ;
int V_1 = F_17 () ;
int V_19 ;
unsigned long V_51 ;
V_52 [ V_7 ] ++ ;
if ( V_17 >= V_37 - V_53 && V_17 < V_37 )
return V_45 ;
if ( V_1 & V_4 )
V_54 [ V_7 ] ++ ;
for ( V_19 = V_9 ; V_19 < V_10 ; V_19 ++ ) {
if ( V_11 [ V_7 ] [ V_19 ] . V_3 & V_12 ) {
unsigned long V_55 = V_11 [ V_7 ] [ V_19 ] . V_17 ;
if ( V_55 <= V_17 && V_55 + V_56 > V_17 ) {
V_17 += V_56 ;
break;
}
}
}
V_51 = V_12 | V_57 | V_23 ;
#ifdef F_18
if ( V_17 < V_37 ||
( V_17 < V_31 && V_58 ) )
V_51 |= V_24 | V_25 ;
#endif
if ( V_28 && V_17 >= V_29 && V_17 < V_29 + V_28 ) {
V_17 = V_29 ;
V_51 = V_59 ;
} else if ( V_17 >= V_31 ) {
if ( V_17 >= V_32 && V_17 < V_33 + V_34 ) {
if ( ! ( V_1 & V_4 ) ) {
unsigned long * V_18 = V_35 [ V_7 ] ;
if ( V_18 ) {
int V_36 = ( V_17 - ( V_32 - V_37 ) ) >> V_38 ;
int V_19 = V_36 >> 5 ;
int V_39 = 1 << ( V_36 & 31 ) ;
V_18 += 2 * V_47 ;
if ( V_18 [ V_19 ] & V_39 )
V_51 |= V_40 ;
}
}
} else if ( V_17 >= V_41 && V_17 < V_41 + V_42
&& ( V_1 & V_4 ) ) {
V_17 &= ~ ( 1 * 1024 * 1024 - 1 ) ;
V_51 &= ~ V_23 ;
V_51 |= V_44 ;
} else
return V_45 ;
} else if ( V_17 >= V_37 ) {
V_51 |= V_40 ;
if ( V_58 )
V_51 |= V_24 ;
} else {
if ( ! ( V_1 & V_4 ) ) {
unsigned long * V_18 = V_35 [ V_7 ] ;
if ( V_18 ) {
int V_36 = V_17 >> V_38 ;
int V_19 = V_36 >> 5 ;
int V_39 = 1 << ( V_36 & 31 ) ;
V_18 += 2 * V_47 ;
if ( V_18 [ V_19 ] & V_39 )
V_51 |= V_40 ;
}
}
}
V_19 = F_4 ( V_7 ) ;
V_17 &= V_48 ;
V_11 [ V_7 ] [ V_19 ] . V_17 = V_17 ;
V_11 [ V_7 ] [ V_19 ] . V_3 = V_51 ;
F_19 () ;
F_13 ( V_60 + V_19 * 4 , V_51 ) ;
F_13 ( V_61 + V_19 * 4 , V_17 ) ;
F_20 () ;
return 0 ;
}
T_1 static T_2 int F_21 ( unsigned int V_7 )
{
int V_1 = F_8 () ;
V_62 [ V_7 ] ++ ;
if ( V_1 & V_43 ) {
int V_19 = F_1 ( V_1 ) ;
unsigned long V_3 = V_15 [ V_7 ] [ V_19 ] . V_3 ;
if ( ! ( V_3 & V_27 ) && ! ( V_3 & V_22 ) &&
F_3 ( V_1 , V_3 ) ) {
V_3 |= V_22 ;
V_15 [ V_7 ] [ V_19 ] . V_3 = V_3 ;
F_13 ( V_49 + V_19 * 4 , V_3 ) ;
return 0 ;
}
}
return V_45 ;
}
T_1 int F_22 ( int V_63 , struct V_64 * V_65 )
{
int V_66 = V_63 & 0x3f ;
unsigned int V_7 = F_23 () ;
switch ( V_66 ) {
case 0x23 :
return F_21 ( V_7 ) ;
case 0x2C :
return F_15 ( V_7 ) ;
case 0x26 :
return F_6 ( V_7 ) ;
default:
return 1 ;
}
}
void F_24 ( unsigned int V_7 )
{
int V_8 ;
unsigned long V_67 ;
V_68 [ V_7 ] ++ ;
V_67 = F_25 () ;
F_19 () ;
for ( V_8 = V_9 ; V_8 < V_10 ; V_8 ++ ) {
V_11 [ V_7 ] [ V_8 ] . V_3 = 0 ;
F_13 ( V_60 + V_8 * 4 , 0 ) ;
}
F_20 () ;
F_12 () ;
for ( V_8 = V_14 ; V_8 < V_10 ; V_8 ++ ) {
V_15 [ V_7 ] [ V_8 ] . V_3 = 0 ;
F_13 ( V_49 + V_8 * 4 , 0 ) ;
}
F_14 () ;
F_26 ( V_67 ) ;
}
void F_27 ( unsigned long * V_69 , unsigned int V_7 )
{
int V_8 ;
unsigned long V_17 = ( unsigned long ) V_69 ;
unsigned long V_20 ;
unsigned long V_67 ;
if ( ! V_69 ) {
V_35 [ V_7 ] = V_69 ;
return;
}
V_67 = F_25 () ;
V_35 [ V_7 ] = V_69 ;
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
F_12 () ;
for ( V_8 = V_70 ; V_8 < V_14 ; V_8 ++ ) {
V_15 [ V_7 ] [ V_8 ] . V_17 = V_17 ;
V_15 [ V_7 ] [ V_8 ] . V_3 = V_20 ;
F_13 ( V_49 + V_8 * 4 , V_20 ) ;
F_13 ( V_50 + V_8 * 4 , V_17 ) ;
V_17 += V_56 ;
}
F_14 () ;
F_26 ( V_67 ) ;
}
