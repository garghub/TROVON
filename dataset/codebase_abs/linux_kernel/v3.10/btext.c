static int T_1 F_1 ( T_2 V_1 )
{
unsigned int V_2 , V_3 , V_4 , V_5 ;
unsigned long V_6 = 0 ;
T_3 V_7 ;
if ( F_2 ( V_1 , L_1 , ( char * ) & V_2 , 4 ) < 0 )
return - V_8 ;
if ( F_2 ( V_1 , L_2 , ( char * ) & V_3 , 4 ) < 0 )
return - V_8 ;
if ( F_2 ( V_1 , L_3 , ( char * ) & V_4 , 4 ) < 0 )
return - V_8 ;
V_5 = V_2 * ( ( V_4 + 7 ) / 8 ) ;
if ( F_2 ( V_1 , L_4 , ( char * ) & V_7 , 4 ) >= 0 &&
V_7 != 0xffffffffu )
V_5 = V_7 ;
if ( V_5 == 1 )
V_5 = 0x1000 ;
if ( F_2 ( V_1 , L_5 , ( char * ) & V_7 , 4 ) >= 0 )
V_6 = V_7 ;
if ( V_6 == 0 )
return - V_8 ;
V_9 = 0 ;
V_10 = 0 ;
V_11 = V_2 / 8 ;
V_12 = V_3 / 16 ;
V_13 = ( unsigned char * ) V_6 ;
V_14 = V_5 ;
V_15 = V_4 == 15 ? 16 : V_4 ;
V_16 [ 0 ] = V_16 [ 1 ] = 0 ;
V_16 [ 2 ] = V_2 ;
V_16 [ 3 ] = V_3 ;
return 0 ;
}
static unsigned char * F_3 ( int V_17 , int V_18 )
{
unsigned char * V_19 = V_13 ;
V_19 += ( V_17 + V_16 [ 0 ] ) * ( V_15 >> 3 ) ;
V_19 += ( V_18 + V_16 [ 1 ] ) * V_14 ;
return V_19 ;
}
static void F_4 ( void )
{
unsigned int * V_19 = ( unsigned int * ) F_3 ( 0 , 0 ) ;
unsigned long V_2 = ( ( V_16 [ 2 ] - V_16 [ 0 ] ) *
( V_15 >> 3 ) ) >> 2 ;
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < ( V_16 [ 3 ] - V_16 [ 1 ] ) ; V_20 ++ )
{
unsigned int * V_22 = V_19 ;
for( V_21 = V_2 ; V_21 ; -- V_21 )
* ( V_22 ++ ) = 0 ;
V_19 += ( V_14 >> 2 ) ;
}
}
static void F_5 ( void )
{
unsigned int * V_23 = ( unsigned int * ) F_3 ( 0 , 16 ) ;
unsigned int * V_24 = ( unsigned int * ) F_3 ( 0 , 0 ) ;
unsigned long V_2 = ( ( V_16 [ 2 ] - V_16 [ 0 ] ) *
( V_15 >> 3 ) ) >> 2 ;
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < ( V_16 [ 3 ] - V_16 [ 1 ] - 16 ) ; V_20 ++ )
{
unsigned int * V_25 = V_23 ;
unsigned int * V_26 = V_24 ;
for( V_21 = V_2 ; V_21 ; -- V_21 )
* ( V_26 ++ ) = * ( V_25 ++ ) ;
V_23 += ( V_14 >> 2 ) ;
V_24 += ( V_14 >> 2 ) ;
}
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
{
unsigned int * V_26 = V_24 ;
for( V_21 = V_2 ; V_21 ; -- V_21 )
* ( V_26 ++ ) = 0 ;
V_24 += ( V_14 >> 2 ) ;
}
}
void F_6 ( char V_27 )
{
int V_28 = 0 ;
#ifdef F_7
int V_17 ;
#endif
switch ( V_27 ) {
case '\b' :
if ( V_9 > 0 )
-- V_9 ;
break;
case '\t' :
V_9 = ( V_9 & - 8 ) + 8 ;
break;
case '\r' :
V_9 = 0 ;
break;
case '\n' :
V_9 = 0 ;
V_10 ++ ;
V_28 = 1 ;
break;
default:
F_8 ( V_27 , V_9 ++ , V_10 ) ;
}
if ( V_9 >= V_11 ) {
V_9 = 0 ;
V_10 ++ ;
V_28 = 1 ;
}
#ifndef F_7
while ( V_10 >= V_12 ) {
F_5 () ;
V_10 -- ;
}
#else
if ( V_10 >= V_12 )
V_10 = 0 ;
if ( V_28 ) {
for ( V_17 = 0 ; V_17 < V_11 ; ++ V_17 )
F_8 ( ' ' , V_17 , V_10 ) ;
}
#endif
}
static void F_9 ( const char * V_27 , unsigned int V_29 )
{
while ( V_29 -- )
F_6 ( * V_27 ++ ) ;
}
static void F_8 ( unsigned char V_27 , long V_30 , long V_31 )
{
unsigned char * V_19 = F_3 ( V_30 << 3 , V_31 << 4 ) ;
unsigned char * V_32 = & V_33 [ ( ( unsigned int ) V_27 ) * 16 ] ;
int V_34 = V_14 ;
switch( V_15 ) {
case 24 :
case 32 :
F_10 ( V_32 , ( unsigned int * ) V_19 , V_34 ) ;
break;
case 15 :
case 16 :
F_11 ( V_32 , ( unsigned int * ) V_19 , V_34 ) ;
break;
case 8 :
F_12 ( V_32 , ( unsigned int * ) V_19 , V_34 ) ;
break;
}
}
static void F_10 ( unsigned char * V_32 , unsigned int * V_19 , int V_34 )
{
int V_35 , V_36 ;
int V_37 = 0xFFFFFFFFUL ;
int V_38 = 0x00000000UL ;
for ( V_35 = 0 ; V_35 < 16 ; ++ V_35 )
{
V_36 = * V_32 ++ ;
V_19 [ 0 ] = ( - ( V_36 >> 7 ) & V_37 ) ^ V_38 ;
V_19 [ 1 ] = ( - ( ( V_36 >> 6 ) & 1 ) & V_37 ) ^ V_38 ;
V_19 [ 2 ] = ( - ( ( V_36 >> 5 ) & 1 ) & V_37 ) ^ V_38 ;
V_19 [ 3 ] = ( - ( ( V_36 >> 4 ) & 1 ) & V_37 ) ^ V_38 ;
V_19 [ 4 ] = ( - ( ( V_36 >> 3 ) & 1 ) & V_37 ) ^ V_38 ;
V_19 [ 5 ] = ( - ( ( V_36 >> 2 ) & 1 ) & V_37 ) ^ V_38 ;
V_19 [ 6 ] = ( - ( ( V_36 >> 1 ) & 1 ) & V_37 ) ^ V_38 ;
V_19 [ 7 ] = ( - ( V_36 & 1 ) & V_37 ) ^ V_38 ;
V_19 = ( unsigned int * ) ( ( char * ) V_19 + V_34 ) ;
}
}
static void F_11 ( unsigned char * V_32 , unsigned int * V_19 , int V_34 )
{
int V_35 , V_36 ;
int V_37 = 0xFFFFFFFFUL ;
int V_38 = 0x00000000UL ;
unsigned int * V_39 = ( int * ) V_40 ;
for ( V_35 = 0 ; V_35 < 16 ; ++ V_35 )
{
V_36 = * V_32 ++ ;
V_19 [ 0 ] = ( V_39 [ V_36 >> 6 ] & V_37 ) ^ V_38 ;
V_19 [ 1 ] = ( V_39 [ ( V_36 >> 4 ) & 3 ] & V_37 ) ^ V_38 ;
V_19 [ 2 ] = ( V_39 [ ( V_36 >> 2 ) & 3 ] & V_37 ) ^ V_38 ;
V_19 [ 3 ] = ( V_39 [ V_36 & 3 ] & V_37 ) ^ V_38 ;
V_19 = ( unsigned int * ) ( ( char * ) V_19 + V_34 ) ;
}
}
static void F_12 ( unsigned char * V_32 , unsigned int * V_19 , int V_34 )
{
int V_35 , V_36 ;
int V_37 = 0x0F0F0F0FUL ;
int V_38 = 0x00000000UL ;
unsigned int * V_39 = ( int * ) V_41 ;
for ( V_35 = 0 ; V_35 < 16 ; ++ V_35 )
{
V_36 = * V_32 ++ ;
V_19 [ 0 ] = ( V_39 [ V_36 >> 4 ] & V_37 ) ^ V_38 ;
V_19 [ 1 ] = ( V_39 [ V_36 & 0xf ] & V_37 ) ^ V_38 ;
V_19 = ( unsigned int * ) ( ( char * ) V_19 + V_34 ) ;
}
}
static void F_13 ( struct V_42 * V_43 , const char * V_44 ,
unsigned int V_45 )
{
F_9 ( V_44 , V_45 ) ;
}
int T_1 F_14 ( void )
{
T_2 V_1 ;
char type [ 32 ] ;
int V_46 ;
V_1 = F_15 ( V_47 ) ;
if ( F_2 ( V_1 , L_6 , type , 32 ) < 0 )
return - V_48 ;
if ( strcmp ( type , L_7 ) )
return - V_48 ;
V_46 = F_1 ( V_1 ) ;
if ( ! V_46 ) {
F_4 () ;
F_16 ( & V_49 ) ;
}
return V_46 ;
}
