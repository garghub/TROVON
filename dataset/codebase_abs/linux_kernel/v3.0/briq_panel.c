static void F_1 ( void )
{
int V_1 ;
F_2 ( 0x02 , V_2 ) ;
for ( V_1 = 0 ; V_1 < 20 ; V_1 ++ )
F_2 ( V_3 [ V_1 ] , V_2 + 1 ) ;
F_2 ( 0xc0 , V_2 ) ;
for ( V_1 = 20 ; V_1 < 40 ; V_1 ++ )
F_2 ( V_3 [ V_1 ] , V_2 + 1 ) ;
}
static void F_3 ( char V_4 )
{
if ( V_4 == 'R' )
V_5 = 0x01 ;
else if ( V_4 == 'G' )
V_5 = 0x02 ;
else if ( V_4 == 'Y' )
V_5 = 0x03 ;
else if ( V_4 == 'X' )
V_5 = 0x00 ;
F_2 ( V_5 , V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
F_5 () ;
if ( V_11 ) {
F_6 () ;
return - V_12 ;
}
V_11 = 1 ;
F_6 () ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
if ( ! V_11 )
return - V_13 ;
V_11 = 0 ;
return 0 ;
}
static T_1 F_8 ( struct V_9 * V_9 , char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
unsigned short V_17 ;
unsigned char V_18 ;
if ( ! V_11 )
return - V_13 ;
V_17 = ( F_9 ( V_6 ) & 0x000c ) | ( V_19 & 0x0003 ) ;
F_3 ( ' ' ) ;
if ( ( ! ( V_19 & 0x0004 ) ) && ( V_17 & 0x0004 ) ) {
V_18 = ' ' ;
V_19 = V_17 ;
if ( F_10 ( V_14 , & V_18 , 1 ) )
return - V_20 ;
return 1 ;
}
else if ( ( ! ( V_19 & 0x0008 ) ) && ( V_17 & 0x0008 ) ) {
V_18 = '\r' ;
V_19 = V_17 ;
if ( F_10 ( V_14 , & V_18 , 1 ) )
return - V_20 ;
return 1 ;
} else {
V_19 = V_17 ;
return 0 ;
}
}
static void F_11 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 20 ; V_1 ++ ) {
V_3 [ V_1 ] = V_3 [ V_1 + 20 ] ;
V_3 [ V_1 + 20 ] = ' ' ;
}
V_21 = 20 ;
}
static T_1 F_12 ( struct V_9 * V_9 , const char T_2 * V_14 , T_3 V_22 ,
T_4 * V_16 )
{
T_3 V_23 = V_22 ;
int V_1 , V_24 = 0 ;
if ( ! V_11 )
return - V_12 ;
for (; ; ) {
char V_17 ;
if ( ! V_23 )
break;
if ( F_13 ( V_17 , V_14 ) )
return - V_20 ;
if ( V_24 ) {
F_3 ( V_17 ) ;
V_24 = 0 ;
} else if ( V_17 == 27 ) {
V_24 = 1 ;
} else if ( V_17 == 12 ) {
for ( V_1 = 0 ; V_1 < 40 ; V_1 ++ )
V_3 [ V_1 ] = ' ' ;
V_21 = 0 ;
} else if ( V_17 == 10 ) {
if ( V_21 < 20 )
V_21 = 20 ;
else if ( V_21 < 40 )
V_21 = 40 ;
else if ( V_21 < 60 )
V_21 = 60 ;
if ( V_21 > 59 )
F_11 () ;
} else {
if ( V_21 > 39 )
F_11 () ;
V_3 [ V_21 ++ ] = V_17 ;
}
V_23 -- ;
V_14 ++ ;
}
F_1 () ;
return V_22 ;
}
static int T_5 F_14 ( void )
{
struct V_25 * V_26 = F_15 ( L_1 ) ;
const char * V_27 ;
int V_1 ;
V_27 = F_16 ( V_26 , L_2 , NULL ) ;
if ( ! V_27 || strncmp ( V_27 , L_3 , 18 ) != 0 ) {
F_17 ( V_26 ) ;
return - V_13 ;
}
F_17 ( V_26 ) ;
F_18 ( V_28
L_4 ,
V_29 ) ;
if ( ! F_19 ( V_2 , 4 , L_5 ) )
return - V_12 ;
if ( ! F_19 ( V_6 , 2 , L_5 ) ) {
F_20 ( V_2 , 4 ) ;
return - V_12 ;
}
V_19 = F_9 ( V_6 ) & 0x000c ;
if ( F_21 ( & V_30 ) < 0 ) {
F_20 ( V_2 , 4 ) ;
F_20 ( V_6 , 2 ) ;
return - V_12 ;
}
F_2 ( 0x38 , V_2 ) ;
F_2 ( 0x01 , V_2 ) ;
F_2 ( 0x0c , V_2 ) ;
F_2 ( 0x06 , V_2 ) ;
for ( V_1 = 0 ; V_1 < 40 ; V_1 ++ )
V_3 [ V_1 ] = ' ' ;
#ifndef F_22
V_3 [ 0 ] = 'L' ;
V_3 [ 1 ] = 'o' ;
V_3 [ 2 ] = 'a' ;
V_3 [ 3 ] = 'd' ;
V_3 [ 4 ] = 'i' ;
V_3 [ 5 ] = 'n' ;
V_3 [ 6 ] = 'g' ;
V_3 [ 7 ] = ' ' ;
V_3 [ 8 ] = '.' ;
V_3 [ 9 ] = '.' ;
V_3 [ 10 ] = '.' ;
#endif
F_1 () ;
return 0 ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_30 ) ;
F_20 ( V_2 , 4 ) ;
F_20 ( V_6 , 2 ) ;
}
