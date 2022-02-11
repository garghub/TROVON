int
F_1 (
T_1 * V_1 ,
unsigned int * V_2 ,
unsigned int * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 ;
register boolean V_8 = FALSE ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_9 ;
if ( V_7 > V_10 + 1 ) {
if ( F_3 ( V_5 ) ) {
V_6 = 0 ;
} else {
V_6 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_12 ) ;
}
if ( V_7 >= 0 ) {
if ( F_3 ( V_5 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_12 ) ;
}
F_6 ( V_5 ) ;
F_7 ( V_5 , V_7 , V_6 ) ;
if ( F_8 ( V_5 , V_7 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
V_6 ++ ;
break;
case V_14 :
break;
case V_15 :
if ( F_10 ( V_5 , V_7 ) &&
( F_11 ( V_5 , V_7 ) ||
( V_6 & 1 ) ) ) {
V_6 ++ ;
}
break;
}
}
} else {
V_6 = 0 ;
if ( F_12 ( V_5 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
if ( F_13 ( V_5 ) ) {
V_6 ++ ;
}
break;
case V_14 :
if ( F_3 ( V_5 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
break;
case V_15 :
if ( V_7 == - 1 &&
F_14 ( V_5 ) ) {
if ( F_3 ( V_5 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
else V_6 ++ ;
}
break;
}
}
}
* V_3 = V_6 ;
if ( V_8 ) {
if ( F_15 () ) return ( V_16 ) ;
else F_16 () ;
}
return ( V_12 ) ;
}
int
F_17 (
T_1 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 ;
register unsigned int V_5 , V_17 , V_18 ;
register boolean V_8 = FALSE ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_9 ;
if ( V_7 > V_19 + 1 ) {
if ( F_3 ( V_5 ) ) {
V_17 = V_18 = 0 ;
} else {
V_17 = V_18 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
F_18 ( V_17 , V_18 , V_3 ) ;
return ( V_12 ) ;
}
if ( V_7 >= 0 ) {
if ( F_3 ( V_5 ) ) {
V_17 = V_18 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
F_18 ( V_17 , V_18 , V_3 ) ;
return ( V_12 ) ;
}
F_6 ( V_5 ) ;
F_19 ( V_5 , V_7 , V_17 , V_18 ) ;
if ( F_8 ( V_5 , V_7 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
F_20 ( V_17 , V_18 ) ;
break;
case V_14 :
break;
case V_15 :
if ( F_10 ( V_5 , V_7 ) &&
( F_11 ( V_5 , V_7 ) ||
F_21 ( V_18 ) ) ) {
F_20 ( V_17 , V_18 ) ;
}
break;
}
}
} else {
F_22 ( V_17 , V_18 ) ;
if ( F_12 ( V_5 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
if ( F_13 ( V_5 ) ) {
F_20 ( V_17 , V_18 ) ;
}
break;
case V_14 :
if ( F_3 ( V_5 ) ) {
V_17 = V_18 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
break;
case V_15 :
if ( V_7 == - 1 &&
F_14 ( V_5 ) ) {
if ( F_3 ( V_5 ) ) {
V_17 = 0 ;
V_18 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
else F_20 ( V_17 , V_18 ) ;
}
}
}
}
F_18 ( V_17 , V_18 , V_3 ) ;
if ( V_8 ) {
if ( F_15 () ) return ( V_16 ) ;
else F_16 () ;
}
return ( V_12 ) ;
}
int
F_23 ( T_3 * V_1 , unsigned int * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
register unsigned int V_20 , V_21 , V_6 ;
register int V_7 ;
register boolean V_8 = FALSE ;
F_24 ( V_1 , V_20 , V_21 ) ;
V_7 = F_25 ( V_20 ) - V_22 ;
if ( V_7 > V_10 + 1 ) {
if ( F_26 ( V_20 ) ) {
V_6 = 0 ;
} else {
V_6 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_12 ) ;
}
if ( V_7 >= 0 ) {
if ( F_26 ( V_20 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_12 ) ;
}
F_27 ( V_20 ) ;
F_28 ( V_20 , V_21 , V_7 , V_6 ) ;
if ( F_29 ( V_20 , V_21 , V_7 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
V_6 ++ ;
break;
case V_14 :
break;
case V_15 :
if( F_30 ( V_20 , V_21 , V_7 ) &&
( F_31 ( V_20 , V_21 , V_7 ) ||
V_6 & 1 ) )
V_6 ++ ;
break;
}
if ( V_6 == 0 ) {
V_6 = 0xffffffff ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_12 ) ;
}
}
} else {
V_6 = 0 ;
if ( F_32 ( V_20 , V_21 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
if ( F_33 ( V_20 ) ) V_6 ++ ;
break;
case V_14 :
if ( F_26 ( V_20 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
break;
case V_15 :
if ( V_7 == - 1 &&
F_34 ( V_20 , V_21 ) )
if ( F_26 ( V_20 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
else V_6 ++ ;
}
}
}
* V_3 = V_6 ;
if ( V_8 ) {
if ( F_15 () ) return ( V_16 ) ;
else F_16 () ;
}
return ( V_12 ) ;
}
int
F_35 ( T_3 * V_1 , unsigned int * V_2 ,
T_2 * V_3 , unsigned int * V_4 )
{
register int V_7 ;
register unsigned int V_20 , V_21 , V_17 , V_18 ;
register boolean V_8 = FALSE ;
F_24 ( V_1 , V_20 , V_21 ) ;
V_7 = F_25 ( V_20 ) - V_22 ;
if ( V_7 > V_19 + 1 ) {
if ( F_26 ( V_20 ) ) {
V_17 = V_18 = 0 ;
} else {
V_17 = V_18 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
F_18 ( V_17 , V_18 , V_3 ) ;
return ( V_12 ) ;
}
if ( V_7 >= 0 ) {
if ( F_26 ( V_20 ) ) {
V_17 = V_18 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
F_18 ( V_17 , V_18 , V_3 ) ;
return ( V_12 ) ;
}
F_27 ( V_20 ) ;
F_36 ( V_20 , V_21 , V_7 , V_17 ,
V_18 ) ;
if ( F_29 ( V_20 , V_21 , V_7 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
F_20 ( V_17 , V_18 ) ;
break;
case V_14 :
break;
case V_15 :
if( F_30 ( V_20 , V_21 , V_7 ) )
if( F_31 ( V_20 , V_21 , V_7 ) ||
F_21 ( V_18 ) )
F_20 ( V_17 , V_18 ) ;
}
}
} else {
F_22 ( V_17 , V_18 ) ;
if ( F_32 ( V_20 , V_21 ) ) {
V_8 = TRUE ;
switch ( F_9 () ) {
case V_13 :
if ( F_33 ( V_20 ) ) {
F_20 ( V_17 , V_18 ) ;
}
break;
case V_14 :
if ( F_26 ( V_20 ) ) {
V_17 = V_18 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
break;
case V_15 :
if ( V_7 == - 1 &&
F_34 ( V_20 , V_21 ) )
if ( F_33 ( V_20 ) ) {
F_20 ( V_17 , V_18 ) ;
} else {
V_17 = 0 ;
V_18 = 0 ;
if ( F_4 () ) {
return ( V_11 ) ;
}
F_5 () ;
V_8 = FALSE ;
}
}
}
}
F_18 ( V_17 , V_18 , V_3 ) ;
if ( V_8 ) {
if ( F_15 () ) return ( V_16 ) ;
else F_16 () ;
}
return ( V_12 ) ;
}
