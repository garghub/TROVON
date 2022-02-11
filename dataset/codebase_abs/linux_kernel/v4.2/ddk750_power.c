void F_1 ( T_1 V_1 )
{
unsigned int V_2 ;
if( F_2 () == V_3 ) {
V_2 = F_3 ( V_4 ) ;
F_4 ( V_4 , F_5 ( V_2 , V_4 , V_5 , V_1 ) ) ;
} else{
V_2 = F_3 ( V_6 ) ;
V_2 = F_5 ( V_2 , V_6 , V_5 , V_1 ) ;
F_4 ( V_6 , V_2 ) ;
}
}
unsigned int F_6 ( void )
{
if( F_2 () == V_3 )
return 0 ;
return ( F_7 ( F_3 ( V_7 ) , V_7 , V_8 ) ) ;
}
void F_8 ( unsigned int V_9 )
{
unsigned int V_10 = 0 ;
V_10 = F_3 ( V_7 ) ;
if( F_2 () == V_3 )
return;
switch ( V_9 )
{
case V_11 :
V_10 = F_9 ( V_10 , V_7 , V_8 , V_12 ) ;
break;
case V_13 :
V_10 = F_9 ( V_10 , V_7 , V_8 , V_14 ) ;
break;
case V_15 :
V_10 = F_9 ( V_10 , V_7 , V_8 , V_16 ) ;
break;
default:
break;
}
if ( V_9 == V_15 )
{
V_10 =
#ifdef F_10
F_9 ( V_10 , V_7 , 336CLK , V_17 ) |
#endif
F_9 ( V_10 , V_7 , V_18 , V_17 ) ;
}
else
{
V_10 =
#ifdef F_10
F_9 ( V_10 , V_7 , 336CLK , V_19 ) |
#endif
F_9 ( V_10 , V_7 , V_18 , V_19 ) ;
}
F_4 ( V_7 , V_10 ) ;
}
void F_11 ( unsigned int V_20 )
{
unsigned int V_21 ;
unsigned int V_22 ;
V_22 = F_6 () ;
switch ( V_22 )
{
case V_11 :
V_21 = V_23 ;
break;
case V_13 :
V_21 = V_24 ;
break;
default:
V_21 = V_23 ;
break;
}
F_4 ( V_21 , V_20 ) ;
}
void F_12 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
{
V_20 = F_9 ( V_20 , V_26 , V_27 , V_19 ) ;
V_20 = F_9 ( V_20 , V_26 , V_28 , V_19 ) ;
}
else
{
V_20 = F_9 ( V_20 , V_26 , V_27 , V_17 ) ;
V_20 = F_9 ( V_20 , V_26 , V_28 , V_17 ) ;
}
F_11 ( V_20 ) ;
}
void F_13 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
{
V_20 = F_9 ( V_20 , V_26 , V_29 , V_19 ) ;
#if 1
V_20 = F_9 ( V_20 , V_26 , V_30 , V_19 ) ;
#else
V_20 = F_9 ( V_20 , V_26 , V_31 , V_19 ) ;
#endif
}
else
{
V_20 = F_9 ( V_20 , V_26 , V_29 , V_17 ) ;
}
F_11 ( V_20 ) ;
}
void F_14 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
V_20 = F_9 ( V_20 , V_26 , V_32 , V_19 ) ;
else
V_20 = F_9 ( V_20 , V_26 , V_32 , V_17 ) ;
F_11 ( V_20 ) ;
}
void F_15 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
V_20 = F_9 ( V_20 , V_26 , V_33 , V_19 ) ;
else
V_20 = F_9 ( V_20 , V_26 , V_33 , V_17 ) ;
F_11 ( V_20 ) ;
}
void F_16 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
V_20 = F_9 ( V_20 , V_26 , V_30 , V_19 ) ;
else
V_20 = F_9 ( V_20 , V_26 , V_30 , V_17 ) ;
F_11 ( V_20 ) ;
}
void F_17 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
V_20 = F_9 ( V_20 , V_26 , V_34 , V_19 ) ;
else
V_20 = F_9 ( V_20 , V_26 , V_34 , V_17 ) ;
F_11 ( V_20 ) ;
}
void F_18 ( unsigned int V_25 )
{
T_2 V_20 ;
V_20 = F_3 ( V_26 ) ;
if ( V_25 )
V_20 = F_9 ( V_20 , V_26 , V_31 , V_19 ) ;
else
V_20 = F_9 ( V_20 , V_26 , V_31 , V_17 ) ;
F_11 ( V_20 ) ;
}
