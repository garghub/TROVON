static T_1 bool F_1 ( void )
{
T_2 V_1 ;
V_1 = F_2 ( ( void * ) V_2 ) ;
return ( V_1 & V_3 ) == V_4 ;
}
static T_1 int F_3 ( void * V_5 )
{
int V_6 , V_7 ;
V_7 = F_4 ( V_5 , L_1 ) ;
if ( V_7 == - V_8 )
V_7 = F_4 ( V_5 , L_2 ) ;
if ( V_7 == - V_8 )
V_7 = F_5 ( V_5 , 0 , L_3 ) ;
if ( V_7 < 0 ) {
F_6 ( L_4 ,
V_7 ) ;
return V_7 ;
}
V_6 = F_7 ( V_5 , V_7 , L_5 , F_8 () ) ;
if ( V_6 ) {
F_6 ( L_6 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static T_1 int F_9 ( void * V_5 )
{
unsigned long V_9 , V_10 ;
T_3 V_11 [ 2 ] ;
int V_6 , V_12 ;
char * V_13 ;
V_13 = F_10 ( L_7 ) ;
if ( V_13 ) {
V_6 = F_11 ( V_13 , 0 , & V_9 ) ;
if ( V_6 ) {
F_6 ( L_8 ,
V_13 ) ;
return - V_14 ;
}
} else {
F_12 ( L_9 ) ;
V_9 = 32 << 20 ;
}
V_10 = V_9 ;
V_13 = strstr ( V_15 , L_10 ) ;
if ( V_13 )
V_10 = F_13 ( V_13 + strlen ( L_10 ) , NULL ) ;
V_9 = F_14 (unsigned long, phys_memsize, memsize) ;
V_12 = F_4 ( V_5 , L_11 ) ;
if ( V_12 == - V_8 )
V_12 = F_5 ( V_5 , 0 , L_12 ) ;
if ( V_12 < 0 ) {
F_6 ( L_13 , V_12 ) ;
return V_12 ;
}
V_6 = F_7 ( V_5 , V_12 , L_14 , L_12 ) ;
if ( V_6 ) {
F_6 ( L_15 , V_6 ) ;
return V_6 ;
}
V_11 [ 0 ] = 0 ;
V_11 [ 1 ] = F_15 ( V_9 ) ;
V_6 = F_16 ( V_5 , V_12 , L_16 , V_11 , sizeof( V_11 ) ) ;
if ( V_6 ) {
F_6 ( L_17 , V_6 ) ;
return V_6 ;
}
V_11 [ 0 ] = 0 ;
V_11 [ 1 ] = F_15 ( V_10 ) ;
V_6 = F_16 ( V_5 , V_12 , L_18 ,
V_11 , sizeof( V_11 ) ) ;
if ( V_6 ) {
F_6 ( L_19 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static T_1 int F_17 ( void * V_5 )
{
const unsigned int V_16 = 2 ;
const unsigned int V_17 = 4 ;
const unsigned int V_18 = 6 ;
int V_19 , V_20 , V_21 , V_22 , V_23 , V_6 ;
T_2 V_24 , V_25 ;
V_24 = F_2 ( ( T_2 * ) V_26 ) ;
if ( V_24 & V_27 )
return 0 ;
V_19 = F_18 ( V_5 , - 1 , L_20 ) ;
if ( V_19 < 0 ) {
F_6 ( L_21 , V_19 ) ;
return V_19 ;
}
V_6 = F_19 ( V_5 , V_19 ) ;
if ( V_6 ) {
F_6 ( L_22 ) ;
return V_6 ;
}
V_20 = F_18 ( V_5 , - 1 ,
L_23 ) ;
if ( V_20 < 0 ) {
F_6 ( L_24 , V_20 ) ;
return V_20 ;
}
V_25 = F_20 ( V_5 , V_20 ) ;
if ( ! V_25 ) {
F_6 ( L_25 ) ;
return - V_14 ;
}
V_6 = F_21 ( V_5 , 0 , L_26 , V_25 ) ;
if ( V_6 ) {
F_6 ( L_27 , V_6 ) ;
return V_6 ;
}
V_21 = F_18 ( V_5 , - 1 , L_28 ) ;
while ( V_21 >= 0 ) {
V_6 = F_21 ( V_5 , V_21 , L_29 ,
V_17 ) ;
if ( V_6 ) {
F_6 ( L_30 ,
V_6 ) ;
return V_6 ;
}
V_21 = F_18 ( V_5 , V_21 ,
L_28 ) ;
}
if ( V_21 != - V_8 ) {
F_6 ( L_31 , V_21 ) ;
return V_21 ;
}
V_22 = F_18 ( V_5 , - 1 , L_32 ) ;
if ( V_22 < 0 ) {
F_6 ( L_33 , V_22 ) ;
return V_22 ;
}
V_6 = F_21 ( V_5 , V_22 , L_29 , V_18 ) ;
if ( V_6 ) {
F_6 ( L_34 , V_6 ) ;
return V_6 ;
}
V_23 = F_18 ( V_5 , - 1 , L_35 ) ;
if ( V_23 < 0 ) {
F_6 ( L_36 , V_23 ) ;
return V_23 ;
}
V_6 = F_21 ( V_5 , V_23 , L_29 , V_16 ) ;
if ( V_6 ) {
F_6 ( L_37 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static T_1 int F_22 ( void * V_5 )
{
const char * V_28 , * V_29 ;
char V_30 [ 9 ] , V_31 [ 18 ] , V_32 ;
unsigned int V_33 , V_34 , V_35 ;
bool V_36 ;
int V_7 , V_6 ;
V_28 = F_10 ( L_38 ) ;
if ( ! V_28 || ! strcmp ( V_28 , L_39 ) ) {
V_33 = 0 ;
} else if ( ! strcmp ( V_28 , L_40 ) ) {
V_33 = 1 ;
} else {
F_12 ( L_41 ,
V_28 ) ;
V_33 = 0 ;
}
V_34 = V_35 = 0 ;
V_32 = 0 ;
V_36 = false ;
snprintf ( V_30 , sizeof( V_30 ) , L_42 , V_33 ) ;
V_29 = F_10 ( V_30 ) ;
if ( V_29 ) {
while ( V_29 [ 0 ] >= '0' && V_29 [ 0 ] <= '9' ) {
V_34 *= 10 ;
V_34 += V_29 [ 0 ] - '0' ;
V_29 ++ ;
}
if ( V_29 [ 0 ] == ',' )
V_29 ++ ;
if ( V_29 [ 0 ] )
V_32 = V_29 [ 0 ] ;
if ( V_29 [ 0 ] == ',' )
V_29 ++ ;
if ( V_29 [ 0 ] )
V_35 = V_29 [ 0 ] - '0' ;
if ( V_29 [ 0 ] == ',' )
V_29 ++ ;
if ( ! strcmp ( V_29 , L_43 ) )
V_36 = true ;
}
if ( ! V_34 )
V_34 = 38400 ;
if ( V_32 != 'e' && V_32 != 'n' && V_32 != 'o' )
V_32 = 'n' ;
if ( V_35 != 7 && V_35 != 8 )
V_35 = 8 ;
F_23 ( snprintf ( V_31 , sizeof( V_31 ) , L_44 ,
V_33 , V_34 , V_32 , V_35 ,
V_36 ? L_45 : L_46 ) >= sizeof( V_31 ) ) ;
V_7 = F_4 ( V_5 , L_1 ) ;
if ( V_7 == - V_8 )
V_7 = F_4 ( V_5 , L_2 ) ;
if ( V_7 == - V_8 )
V_7 = F_5 ( V_5 , 0 , L_3 ) ;
if ( V_7 < 0 ) {
F_6 ( L_4 ,
V_7 ) ;
return V_7 ;
}
V_6 = F_7 ( V_5 , V_7 , L_47 , V_31 ) ;
if ( V_6 ) {
F_6 ( L_48 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static T_1 const void * F_24 ( const void * V_5 ,
const void * V_37 )
{
static unsigned char V_38 [ 16 << 10 ] V_39 ;
int V_6 ;
if ( F_25 ( V_5 ) )
F_26 ( L_49 ) ;
F_27 ( F_28 ( V_5 , 0 , L_50 ) ) ;
F_29 () ;
V_6 = F_30 ( V_5 , V_38 , sizeof( V_38 ) ) ;
if ( V_6 )
F_26 ( L_51 , V_6 ) ;
V_6 = F_3 ( V_38 ) ;
if ( V_6 )
F_26 ( L_52 , V_6 ) ;
V_6 = F_9 ( V_38 ) ;
if ( V_6 )
F_26 ( L_52 , V_6 ) ;
V_6 = F_17 ( V_38 ) ;
if ( V_6 )
F_26 ( L_52 , V_6 ) ;
V_6 = F_22 ( V_38 ) ;
if ( V_6 )
F_26 ( L_52 , V_6 ) ;
V_6 = F_31 ( V_38 ) ;
if ( V_6 )
F_26 ( L_53 , V_6 ) ;
return V_38 ;
}
static T_1 unsigned int F_32 ( void )
{
void T_4 * V_40 = ( void T_4 * ) 0xbf000410 ;
unsigned int V_41 , V_42 , V_43 = 0 ;
unsigned long V_44 ;
F_33 ( V_44 ) ;
V_42 = F_34 ( V_40 ) & 0x2 ;
while ( ( F_34 ( V_40 ) & 0x2 ) == V_42 )
;
V_42 = V_42 ^ 0x2 ;
F_35 ( 0 ) ;
while ( V_43 < 100 ) {
while ( ( F_34 ( V_40 ) & 0x2 ) == V_42 )
;
V_42 = V_42 ^ 0x2 ;
V_43 ++ ;
}
V_41 = F_36 () ;
F_37 ( V_44 ) ;
return V_41 ;
}
