static inline void F_1 ( int V_1 , int V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
F_2 () ;
F_3 ( V_5 + V_2 * 4 , V_3 ) ;
F_3 ( V_6 + V_2 * 4 , V_4 ) ;
F_4 () ;
#ifdef F_5
V_7 [ V_1 ] [ V_2 ] . V_4 = V_4 ;
V_7 [ V_1 ] [ V_2 ] . V_3 = V_3 ;
#endif
}
static inline void F_6 ( int V_1 , int V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
F_7 () ;
F_3 ( V_8 + V_2 * 4 , V_3 ) ;
F_3 ( V_9 + V_2 * 4 , V_4 ) ;
F_8 () ;
#ifdef F_5
V_10 [ V_1 ] [ V_2 ] . V_4 = V_4 ;
V_10 [ V_1 ] [ V_2 ] . V_3 = V_3 ;
#endif
}
static int F_9 ( int V_1 )
{
int V_11 = V_12 + V_13 [ V_1 ] ;
if ( V_11 >= V_14 ) {
V_11 -= V_14 - V_12 ;
V_13 [ V_1 ] -= V_14 - V_12 ;
}
V_13 [ V_1 ] ++ ;
return V_11 ;
}
static int F_10 ( int V_1 )
{
int V_11 = V_15 + V_16 [ V_1 ] ;
if ( V_11 >= V_14 ) {
V_11 -= V_14 - V_15 ;
V_16 [ V_1 ] -= V_14 - V_15 ;
}
V_16 [ V_1 ] ++ ;
return V_11 ;
}
T_1 static int F_11 ( int V_1 )
{
unsigned long V_4 = F_12 () ;
int V_17 = F_13 () ;
int V_2 ;
unsigned long V_18 , V_19 , V_20 , V_21 ;
V_22 [ V_1 ] ++ ;
if ( F_14 ( V_17 & V_23 ) )
V_24 [ V_1 ] ++ ;
V_19 = 0 ;
V_2 = 0 ;
do {
V_21 = V_25 [ V_2 ] . V_21 ;
if ( V_4 < V_21 )
break;
V_19 = V_21 ;
} while ( ++ V_2 < V_26 );
if ( F_14 ( V_2 == V_26 ) )
return V_27 ;
V_18 = V_25 [ V_2 ] . V_3 ;
if ( F_14 ( V_18 == 0 ) )
return V_27 ;
V_20 = V_4 & ~ ( V_28 - 1 ) ;
V_4 &= ~ ( V_29 - 1 ) ;
V_18 |= V_30 ;
if ( V_20 >= V_19 && ( V_20 + V_28 ) <= V_21 ) {
V_18 |= V_31 ;
V_4 = V_20 ;
}
V_2 = F_9 ( V_1 ) ;
F_6 ( V_1 , V_2 , V_18 , V_4 ) ;
return V_32 ;
}
T_1 static int F_15 ( int V_1 )
{
unsigned long V_4 = F_16 () ;
int V_17 = F_17 () ;
int V_2 ;
unsigned long V_33 , V_19 , V_20 , V_21 , V_34 , V_35 ;
V_36 [ V_1 ] ++ ;
if ( F_14 ( V_17 & V_23 ) )
V_37 [ V_1 ] ++ ;
V_19 = 0 ;
V_2 = 0 ;
do {
V_21 = V_38 [ V_2 ] . V_21 ;
if ( V_4 < V_21 )
break;
V_19 = V_21 ;
} while ( ++ V_2 < V_39 );
if ( F_14 ( V_2 == V_39 ) )
return V_27 ;
V_33 = V_38 [ V_2 ] . V_3 ;
if ( F_14 ( V_33 == 0 ) )
return V_27 ;
V_4 &= ~ ( V_29 - 1 ) ;
V_33 |= V_30 ;
#ifdef F_18
V_35 = F_18 ;
V_34 = V_40 ;
#else
V_35 = V_31 ;
V_34 = V_28 ;
#endif
V_41:
V_20 = V_4 & ~ ( V_34 - 1 ) ;
if ( V_20 >= V_19 && ( V_20 + V_34 ) <= V_21 ) {
V_33 |= V_35 ;
V_4 = V_20 ;
goto V_42;
} else {
if ( V_34 > V_28 ) {
V_35 = V_31 ;
V_34 = V_28 ;
goto V_41;
}
}
V_42:
#ifdef F_19
if ( ( V_4 >= V_43 )
&& ( V_4 < V_44 + V_45 ) )
V_33 |= V_46 ;
#endif
V_2 = F_10 ( V_1 ) ;
F_1 ( V_1 , V_2 , V_33 , V_4 ) ;
return V_32 ;
}
T_1 int F_20 ( int V_47 , struct V_48 * V_49 )
{
int V_50 = V_47 & 0x3f ;
unsigned int V_1 = F_21 () ;
switch ( V_50 ) {
case V_51 :
return F_11 ( V_1 ) ;
case V_52 :
return F_15 ( V_1 ) ;
default:
return V_53 ;
}
}
