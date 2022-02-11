T_1
F_1 ( unsigned int V_1 [] , unsigned int V_2 [] )
{
unsigned int V_3 , V_4 ;
int V_5 , V_6 = 1 ;
boolean V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
V_9 = ( V_1 [ 0 ] & 0xf8000000 ) ;
V_1 [ 0 ] &= 0x07ffffff ;
if ( ! F_2 () ) {
F_3 ( V_1 , V_8 , V_9 , V_2 ) ;
return F_4 ( V_11 , V_12 ) ;
}
for ( V_6 = 1 ; V_6 <= V_13 ; V_6 ++ ) {
V_3 = F_5 ( V_6 ) ;
V_10 = F_6 ( V_6 ) ;
if ( V_10 & V_14 ) {
F_7 () ;
F_8 ( V_6 ) ;
V_4 = F_9 ( V_3 , V_10 , 0 , V_1 ) ;
if ( V_4 ) {
F_10 () ;
F_11 ( V_4 , V_3 ,
V_1 [ V_6 ] ) ;
if ( V_4 == V_14 ) {
V_4 = V_10 ;
F_3 ( V_1 , V_8 , V_9 ,
V_2 ) ;
return F_4 ( V_11 , V_12 ) ;
}
V_10 = V_4 ;
}
if ( V_4 == V_15 )
break;
}
if ( V_10 & V_16 ) {
if ( F_12 () ) {
F_3 ( V_1 , V_8 , V_9 ,
V_2 ) ;
return F_4 ( V_17 , V_18 ) ;
} else {
V_5 = V_3 & V_19 ;
#ifndef F_13
if ( F_14 ( V_1 [ V_6 ] ) ) V_7 = TRUE ;
else V_7 = FALSE ;
#endif
switch ( F_15 () ) {
case V_20 :
if ( F_16 ( V_1 [ V_6 ] ) )
F_17 ( F_18 ( V_5 ) ) ;
F_19 ( & F_18 ( V_5 ) , & V_7 , F_20 () ) ;
break;
case V_21 :
if ( F_16 ( V_1 [ V_6 ] ) )
F_21 ( F_22 ( V_5 ) , F_23 ( V_5 ) ) ;
F_24 ( & F_22 ( V_5 ) , & F_23 ( V_5 ) ,
& V_7 , F_20 () ) ;
break;
}
if ( V_7 ) F_25 () ;
if ( V_7 && F_26 () ) {
F_27 ( V_1 [ V_6 ] ,
V_22 ) ;
F_28 ( V_1 [ V_6 ] , 0 ) ;
F_3 ( V_1 , V_8 , V_9 ,
V_2 ) ;
return F_4 ( V_17 , V_23 ) ;
}
else {
F_8 ( V_6 ) ;
if ( V_7 ) F_29 () ;
}
}
continue;
}
switch( F_6 ( V_6 ) ) {
case V_24 :
case V_24 | V_22 :
F_3 ( V_1 , V_8 , V_9 ,
V_2 ) ;
if ( F_30 () ) {
F_3 ( V_1 , V_8 , V_9 ,
V_2 ) ;
return F_4 ( V_17 , V_25 ) ;
} else {
V_5 = V_3 & V_19 ;
switch ( F_15 () ) {
case V_20 :
F_31 ( F_18 ( V_5 ) ) ;
break;
case V_21 :
F_32 ( F_22 ( V_5 ) , F_23 ( V_5 ) ) ;
break;
}
F_33 () ;
if ( F_26 () ) {
F_27 ( V_1 [ V_6 ] ,
V_22 ) ;
F_3 ( V_1 , V_8 , V_9 ,
V_2 ) ;
return F_4 ( V_17 , V_23 ) ;
}
else {
F_8 ( V_6 ) ;
F_29 () ;
}
}
break;
case V_26 :
case V_27 :
F_3 ( V_1 , V_8 , V_9 , V_2 ) ;
return F_4 ( V_17 , V_28 ) ;
case V_29 :
F_3 ( V_1 , V_8 , V_9 , V_2 ) ;
F_8 ( V_6 ) ;
return F_4 ( V_17 , V_30 ) ;
case V_22 :
F_3 ( V_1 , V_8 , V_9 , V_2 ) ;
return F_4 ( V_17 , V_23 ) ;
default:
F_3 ( V_1 , V_8 , V_9 , V_2 ) ;
F_34 ( L_1 , __FILE__ ,
__LINE__ , F_6 ( V_6 ) ) ;
return F_4 ( V_11 , V_12 ) ;
case V_15 :
F_8 ( V_6 ) ;
break;
}
}
F_7 () ;
F_3 ( V_1 , V_8 , V_9 , V_2 ) ;
return ( V_31 ) ;
}
