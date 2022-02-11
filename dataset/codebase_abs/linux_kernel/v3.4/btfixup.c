static void T_1 F_1 ( unsigned int * V_1 , unsigned int V_2 , int V_3 , unsigned int V_4 )
{
if ( ! V_3 )
* V_1 = V_4 ;
else {
unsigned int * V_5 = ( unsigned int * ) V_2 ;
if ( * V_1 == 0x01000000 ) {
* V_5 = V_4 ;
} else if ( V_1 [ - 1 ] == * V_5 ) {
V_1 [ - 1 ] = V_4 ;
* V_5 = V_4 ;
} else {
F_2 ( V_6 , V_1 - 1 , V_1 [ - 1 ] , * V_1 , * V_5 , V_4 ) ;
F_3 () ;
}
}
}
static inline void F_1 ( unsigned int * V_1 , unsigned int V_2 , int V_3 , unsigned int V_4 )
{
* V_1 = V_4 ;
}
void T_1 F_4 ( void )
{
unsigned int * V_7 , * V_5 ;
int type , V_8 ;
unsigned V_9 ;
unsigned * V_1 ;
int V_3 = 0 ;
void (* F_5)( void );
if ( ! V_10 ) {
V_10 ++ ;
F_6 ( V_11 ) ;
if ( V_12 )
F_6 ( V_13 ) ;
else {
F_6 ( V_14 , V_15 ) ;
if ( V_16 == V_17 )
F_6 ( V_18 ) ;
else
F_6 ( V_19 ) ;
}
}
for ( V_7 = V_20 ; V_7 < V_21 ; ) {
V_8 = V_7 [ 2 ] ;
V_5 = V_7 + 3 ;
switch ( type = * ( unsigned char * ) V_7 ) {
case 'f' :
V_8 = V_7 [ 3 ] ;
V_5 = V_7 + 4 ;
if ( ( ( V_7 [ 0 ] & 1 ) || V_7 [ 1 ] )
&& ( ( V_7 [ 1 ] & 3 ) || ( unsigned * ) ( V_7 [ 1 ] ) < V_22 || ( unsigned * ) ( V_7 [ 1 ] ) >= V_23 ) ) {
F_2 ( V_24 , V_7 , V_7 [ 1 ] ) ;
F_3 () ;
}
break;
case 'b' :
if ( V_7 [ 1 ] < ( unsigned long ) V_25 || V_7 [ 1 ] >= ( unsigned long ) V_26 || ( V_7 [ 1 ] & 3 ) ) {
F_2 ( V_27 , V_7 , V_7 [ 1 ] ) ;
F_3 () ;
}
break;
case 's' :
if ( V_7 [ 1 ] + 0x1000 >= 0x2000 ) {
F_2 ( V_28 , V_7 , V_7 [ 1 ] ) ;
F_3 () ;
}
break;
case 'h' :
if ( V_7 [ 1 ] & 0x3ff ) {
F_2 ( V_29 , V_7 , V_7 [ 1 ] ) ;
F_3 () ;
}
break;
case 'a' :
if ( V_7 [ 1 ] + 0x1000 >= 0x2000 && ( V_7 [ 1 ] & 0x3ff ) ) {
F_2 ( V_30 , V_7 , V_7 [ 1 ] ) ;
F_3 () ;
}
break;
}
if ( V_7 [ 0 ] & 1 ) {
V_7 [ 0 ] &= ~ 1 ;
while ( V_8 ) {
V_3 = 0 ;
V_1 = ( unsigned * ) * V_5 ;
if ( V_1 < V_22 || V_1 >= V_23 ) {
F_2 ( V_31 , type , V_7 ) ;
F_3 () ;
}
V_9 = * V_1 ;
#ifdef F_7
if ( type != 'f' && V_5 [ 1 ] ) {
V_9 = * ( unsigned int * ) V_5 [ 1 ] ;
if ( ! V_9 || V_9 == 1 )
V_9 = * V_1 ;
else
V_3 = 1 ;
}
#endif
switch ( type ) {
case 'f' :
if ( V_1 >= V_32 && V_1 < V_33 ) {
* V_1 = V_7 [ 1 ] ;
break;
} else if ( ! V_5 [ 1 ] ) {
if ( ( V_9 & 0xc1c00000 ) == 0x01000000 ) {
* V_1 = ( V_9 & 0xffc00000 ) | ( V_7 [ 1 ] >> 10 ) ; break;
} else if ( ( V_9 & 0xc1f82000 ) == 0x80102000 ) {
* V_1 = ( V_9 & 0xffffe000 ) | ( V_7 [ 1 ] & 0x3ff ) ; break;
} else if ( ( V_9 & 0xc0000000 ) != 0x40000000 ) {
V_34:
F_2 ( V_35 , V_7 , V_1 , V_9 , V_1 [ 1 ] ) ;
F_3 () ;
}
} else if ( V_5 [ 1 ] != 1 )
V_1 [ 1 ] = V_5 [ 1 ] ;
if ( V_7 [ 2 ] == V_36 ) {
V_37:
* V_1 = 0x40000000 | ( ( V_7 [ 1 ] - ( unsigned ) V_1 ) >> 2 ) ;
V_5 [ 1 ] = 0 ;
break;
}
#ifndef F_8
goto V_37;
#else
if ( ! ( V_1 [ 1 ] & 0x80000000 ) ) {
if ( ( V_1 [ 1 ] & 0xc1c00000 ) != 0x01000000 )
goto V_34;
} else {
if ( ( V_1 [ 1 ] & 0x01800000 ) == 0x01800000 ) {
if ( ( V_1 [ 1 ] & 0x01f80000 ) == 0x01e80000 ) {
goto V_37;
}
goto V_34;
}
if ( ( V_1 [ 1 ] & 0xffffe003 ) == 0x9e03e000 ) {
int V_38 = ( V_1 [ 1 ] << 19 ) ;
V_38 = ( V_38 >> 21 ) + 2 ;
* V_1 = ( 0x10800000 ) + ( V_38 & 0x3fffff ) ;
V_5 [ 1 ] = V_1 [ 1 ] ;
V_1 [ 1 ] = V_7 [ 2 ] ;
break;
}
if ( ( V_1 [ 1 ] & 0x201f ) == 0x200f || ( V_1 [ 1 ] & 0x7c000 ) == 0x3c000 )
goto V_37;
if ( ( V_1 [ 1 ] & 0x3e000000 ) == 0x1e000000 )
goto V_37;
}
if ( V_7 [ 2 ] == V_39 ) {
* V_1 = 0x01000000 ;
V_5 [ 1 ] = 1 ;
break;
}
#ifndef F_7
goto V_37;
#else
if ( V_1 [ 1 ] == 0x01000000 ) {
V_5 [ 1 ] = V_1 [ 1 ] ;
* V_1 = V_7 [ 2 ] ;
break;
}
if ( ( V_1 [ 1 ] & 0xc0000000 ) != 0xc0000000 ) {
if ( ( V_1 [ 1 ] & 0x30000000 ) == 0x10000000 ) {
if ( ( V_1 [ 1 ] & 0x3e000000 ) == 0x1c000000 )
goto V_34;
if ( ( V_1 [ 1 ] & 0x3e000000 ) > 0x12000000 ||
( ( V_1 [ 1 ] & 0x3e000000 ) == 0x12000000 &&
V_7 [ 2 ] != V_40 && V_7 [ 2 ] != V_41 ) ||
( ( V_7 [ 2 ] & 0xffffe000 ) == F_9 ( 0 ) ) ) {
* V_1 = V_7 [ 2 ] ;
V_5 [ 1 ] = V_1 [ 1 ] ;
V_1 [ 1 ] = 0x01000000 ;
break;
}
if ( ( V_1 [ 1 ] & 0xf1ffffe0 ) == 0x90100000 ) {
if ( ( V_1 [ 1 ] & 0x3e000000 ) == 0x10000000 &&
( V_7 [ 2 ] & 0x7c000 ) == 0x20000 ) {
* V_1 = ( V_7 [ 2 ] & ~ 0x7c000 ) | ( ( V_1 [ 1 ] & 0x1f ) << 14 ) ;
V_5 [ 1 ] = V_1 [ 1 ] ;
V_1 [ 1 ] = 0x01000000 ;
break;
}
if ( ( V_1 [ 1 ] & 0x3e000000 ) == 0x12000000 &&
V_7 [ 2 ] == V_40 ) {
* V_1 = ( V_7 [ 2 ] & ~ 0x3e000000 ) | ( ( V_1 [ 1 ] & 0x1f ) << 25 ) ;
V_5 [ 1 ] = V_1 [ 1 ] ;
V_1 [ 1 ] = 0x01000000 ;
break;
}
}
}
}
* V_1 = V_1 [ 1 ] ;
V_5 [ 1 ] = V_1 [ 1 ] ;
V_1 [ 1 ] = V_7 [ 2 ] ;
break;
#endif
#endif
case 'b' :
if ( ( V_9 & 0xc1c00000 ) != 0x01000000 ) {
F_2 ( V_42 , V_7 , V_1 , V_9 ) ;
F_3 () ;
} else {
void (* F_10)( unsigned * );
F_10 = ( void ( * ) ( unsigned * ) ) V_7 [ 1 ] ;
F_10 ( V_1 ) ;
}
break;
case 's' :
if ( ( V_9 & 0xc1ffe000 ) != 0x80102000 ) {
F_2 ( V_43 , V_7 , V_1 , V_9 ) ;
F_3 () ;
}
F_1 ( V_1 , V_5 [ 1 ] , V_3 , ( V_9 & 0xffffe000 ) | ( V_7 [ 1 ] & 0x1fff ) ) ;
break;
case 'h' :
if ( ( V_9 & 0xc1c00000 ) != 0x01000000 ) {
F_2 ( V_44 , V_7 , V_1 , V_9 ) ;
F_3 () ;
}
F_1 ( V_1 , V_5 [ 1 ] , V_3 , ( V_9 & 0xffc00000 ) | ( V_7 [ 1 ] >> 10 ) ) ;
break;
case 'a' :
if ( ( V_9 & 0xc1c00000 ) != 0x01000000 &&
( V_9 & 0xc1ffe000 ) != 0x80102000 ) {
F_2 ( V_45 , V_7 , V_1 , V_9 ) ;
F_3 () ;
}
if ( V_7 [ 1 ] & 0x3ff )
F_1 ( V_1 , V_5 [ 1 ] , V_3 ,
( V_9 & 0x3e000000 ) | 0x80102000 | ( V_7 [ 1 ] & 0x1fff ) ) ;
else
F_1 ( V_1 , V_5 [ 1 ] , V_3 ,
( V_9 & 0x3e000000 ) | 0x01000000 | ( V_7 [ 1 ] >> 10 ) ) ;
break;
case 'i' :
if ( ( V_9 & 0xc1c00000 ) == 0x01000000 )
F_1 ( V_1 , V_5 [ 1 ] , V_3 , ( V_9 & 0xffc00000 ) | ( V_7 [ 1 ] >> 10 ) ) ;
else if ( ( V_9 & 0x80002000 ) == 0x80002000 )
F_1 ( V_1 , V_5 [ 1 ] , V_3 , ( V_9 & 0xffffe000 ) | ( V_7 [ 1 ] & 0x3ff ) ) ;
else {
F_2 ( V_46 , V_7 , V_1 , V_9 ) ;
F_3 () ;
}
break;
}
V_8 -= 2 ;
V_5 += 2 ;
}
} else
V_7 = V_5 + V_8 ;
}
#ifdef F_11
F_5 = ( void ( * ) ( void ) ) F_12 ( V_47 ) ;
#else
F_5 = ( void ( * ) ( void ) ) F_12 ( V_48 ) ;
#endif
if ( ! F_5 ) {
F_2 ( V_49 ) ;
F_3 () ;
}
(* F_5)() ;
}
