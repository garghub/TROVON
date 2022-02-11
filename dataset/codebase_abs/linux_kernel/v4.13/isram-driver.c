static void F_1 ( const void * V_1 , T_1 V_2 )
{
T_2 V_3 ;
unsigned long V_4 ;
if ( F_2 ( V_1 >= ( void * ) ( V_5 + V_6 ) ) )
return;
V_3 = F_3 ( V_1 ) | 2 ;
F_4 ( & V_7 , V_4 ) ;
F_5 ( V_2 & 0xFFFFFFFF ) ;
F_6 ( V_2 >> 32 ) ;
F_7 () ;
F_8 ( V_3 ) ;
F_7 () ;
F_8 ( 0 ) ;
F_7 () ;
F_9 ( & V_7 , V_4 ) ;
}
static T_1 F_10 ( const void * V_1 )
{
T_2 V_3 ;
unsigned long V_4 ;
T_1 V_8 ;
if ( F_2 ( V_1 > ( void * ) ( V_5 + V_6 ) ) )
return 0 ;
V_3 = F_3 ( V_1 ) | 0 ;
F_4 ( & V_7 , V_4 ) ;
F_7 () ;
F_8 ( V_3 ) ;
F_7 () ;
V_8 = F_11 () | ( ( T_1 ) F_12 () << 32 ) ;
F_8 ( 0 ) ;
F_7 () ;
F_9 ( & V_7 , V_4 ) ;
return V_8 ;
}
static bool F_13 ( const void * V_1 , T_3 V_9 )
{
if ( ( V_1 >= ( void * ) V_5 ) &&
( V_1 < ( void * ) ( V_5 + V_6 ) ) ) {
if ( F_2 ( ( V_1 + V_9 ) > ( void * ) ( V_5 + V_6 ) ) ) {
F_14 ( NULL , NULL ) ;
F_15 ( L_1 , V_1 , V_9 ) ;
}
return true ;
}
return false ;
}
void * F_16 ( void * V_10 , const void * V_11 , T_3 V_9 )
{
T_1 V_12 = 0 , V_13 = 0 ;
T_3 V_14 ;
bool V_15 , V_16 , V_17 , V_18 ;
unsigned char V_19 , * V_20 , * V_21 ;
V_20 = ( unsigned char * ) V_11 ;
V_21 = ( unsigned char * ) V_10 ;
V_15 = F_13 ( V_10 , V_9 ) ;
V_16 = F_13 ( V_11 , V_9 ) ;
V_17 = true ;
V_18 = true ;
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
if ( V_16 ) {
if ( V_17 ) {
V_12 = F_10 ( V_11 + V_14 ) ;
V_17 = false ;
}
if ( F_17 ( V_11 + V_14 ) )
V_17 = true ;
V_19 = ( unsigned char ) ( ( V_12 >> F_18 ( V_11 + V_14 ) ) & 0xff ) ;
} else {
V_19 = V_20 [ V_14 ] ;
}
if ( V_15 ) {
if ( V_18 ) {
V_13 = F_10 ( V_10 + V_14 ) ;
V_18 = false ;
}
V_13 &= ~ ( ( T_1 ) 0xff << F_18 ( V_10 + V_14 ) ) ;
V_13 |= ( ( T_1 ) V_19 << F_18 ( V_10 + V_14 ) ) ;
if ( F_17 ( V_10 + V_14 ) ) {
V_18 = true ;
F_1 ( V_10 + V_14 , V_13 ) ;
}
} else {
V_21 [ V_14 ] = V_19 ;
}
}
if ( V_15 && ! V_18 )
F_1 ( V_10 + V_14 , V_13 ) ;
return V_10 ;
}
static T_4 void F_19 ( unsigned char * V_22 , int V_23 )
{
while ( V_23 -- )
F_20 ( L_2 , * V_22 ++ ) ;
}
static T_4 int F_21 ( char * V_24 , void * V_25 )
{
int V_26 , V_8 = 0 ;
T_1 V_27 , V_28 ;
F_22 ( L_3 ) ;
for ( V_26 = 0 ; V_26 < V_29 ; ++ V_26 )
V_24 [ V_26 ] = V_26 % 255 ;
F_23 ( V_25 , V_24 , V_29 ) ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 += sizeof( T_1 ) ) {
V_27 = F_10 ( V_25 + V_26 ) ;
memcpy ( & V_28 , V_24 + V_26 , sizeof( V_28 ) ) ;
if ( V_27 != V_28 ) {
F_15 ( L_4 ,
V_25 + V_26 , V_27 , V_28 ) ;
++ V_8 ;
}
}
return V_8 ;
}
static T_4 int F_24 ( char * V_24 , void * V_25 )
{
int V_26 , V_8 = 0 ;
T_1 V_27 , V_28 ;
F_22 ( L_5 ) ;
memset ( V_24 , 0 , V_29 * 2 ) ;
F_23 ( V_25 , V_24 , V_29 ) ;
for ( V_26 = 0 ; V_26 < V_29 ; ++ V_26 )
V_24 [ V_26 ] = V_26 % 255 ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 += sizeof( T_1 ) ) {
memcpy ( & V_27 , V_24 + V_26 , sizeof( V_27 ) ) ;
F_1 ( V_25 + V_26 , V_27 ) ;
V_28 = F_10 ( V_25 + V_26 ) ;
if ( V_27 != V_28 ) {
F_15 ( L_6 ,
V_25 + V_26 , V_27 , V_28 ) ;
++ V_8 ;
}
}
F_23 ( V_24 + V_29 , V_25 , V_29 ) ;
if ( memcmp ( V_24 , V_24 + V_29 , V_29 ) ) {
F_15 ( L_7 ) ;
++ V_8 ;
}
return V_8 ;
}
static T_4 int
F_25 ( char V_30 , void * V_24 , void * V_25 , const char * V_31 ,
void * (* F_26)( void * , const void * , T_3 ) )
{
memset ( V_24 , V_30 , V_29 ) ;
F_26 ( V_25 , V_24 , V_29 ) ;
F_26 ( V_24 + V_29 , V_25 , V_29 ) ;
if ( memcmp ( V_24 , V_24 + V_29 , V_29 ) ) {
F_15 ( L_8 ,
V_31 , V_25 , V_24 , V_29 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static T_4 int F_27 ( char * V_24 , void * V_25 )
{
int V_26 , V_32 , V_33 , V_8 = 0 ;
F_22 ( L_9 ) ;
for ( V_26 = 0xf ; V_26 >= 0 ; -- V_26 )
V_8 += F_25 ( V_26 , V_24 , V_25 , F_16 ) ;
F_22 ( L_10 ) ;
for ( V_26 = 0 ; V_26 < V_29 ; ++ V_26 )
V_24 [ V_26 ] = V_26 % 255 ;
F_23 ( V_25 , V_24 , V_29 ) ;
V_33 = 0 ;
for ( V_26 = 0 ; V_26 < V_29 - 32 ; ++ V_26 ) {
unsigned char V_34 [ 32 ] ;
for ( V_32 = 1 ; V_32 <= 32 ; ++ V_32 ) {
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
F_16 ( V_34 , V_25 + V_26 , V_32 ) ;
if ( memcmp ( V_34 , V_24 + V_26 , V_32 ) ) {
F_15 ( L_11 , V_25 + 1 ) ;
F_19 ( V_34 , V_32 ) ;
F_20 ( L_12 ) ;
F_19 ( V_24 + V_26 , V_32 ) ;
F_20 ( L_13 ) ;
if ( ++ V_33 > 20 ) {
F_15 ( L_14 ) ;
V_26 = V_29 ;
break;
}
}
}
}
V_8 += V_33 ;
F_22 ( L_15 ) ;
memset ( V_24 + V_29 , 0 , V_29 ) ;
F_23 ( V_25 , V_24 + V_29 , V_29 ) ;
V_33 = 0 ;
for ( V_26 = 0 ; V_26 < V_29 - 32 ; ++ V_26 ) {
unsigned char V_34 [ 32 ] ;
for ( V_32 = 1 ; V_32 <= 32 ; ++ V_32 ) {
F_16 ( V_25 + V_26 , V_24 + V_26 , V_32 ) ;
F_23 ( V_34 , V_25 + V_26 , V_32 ) ;
if ( memcmp ( V_34 , V_24 + V_26 , V_32 ) ) {
F_15 ( L_11 , V_25 + V_26 ) ;
F_19 ( V_34 , V_32 ) ;
F_20 ( L_12 ) ;
F_19 ( V_24 + V_26 , V_32 ) ;
F_20 ( L_13 ) ;
if ( ++ V_33 > 20 ) {
F_15 ( L_14 ) ;
V_26 = V_29 ;
break;
}
}
}
}
V_8 += V_33 ;
return V_8 ;
}
static T_4 int F_28 ( void )
{
int V_8 ;
char * V_24 ;
void * V_25 ;
while ( V_29 ) {
V_29 >>= 1 ;
V_25 = F_29 ( V_29 ) ;
if ( V_25 )
break;
}
if ( ! V_25 ) {
F_30 ( L_16 ) ;
return 0 ;
}
F_22 ( L_17 ,
V_29 , V_25 , V_25 + V_29 ) ;
V_24 = F_31 ( V_29 * 2 , V_35 ) ;
if ( ! V_24 ) {
F_32 ( V_25 ) ;
F_30 ( L_18 ) ;
return 0 ;
}
V_8 = 1 ;
F_22 ( L_19 , V_24 ) ;
if ( F_25 ( 0xa , V_24 , V_25 , F_23 ) )
goto abort;
if ( F_25 ( 0x5 , V_24 , V_25 , F_23 ) )
goto abort;
V_8 = 0 ;
V_8 += F_21 ( V_24 , V_25 ) ;
V_8 += F_24 ( V_24 , V_25 ) ;
V_8 += F_27 ( V_24 , V_25 ) ;
abort:
F_32 ( V_25 ) ;
F_33 ( V_24 ) ;
if ( V_8 )
return - V_36 ;
F_22 ( L_20 ) ;
return 0 ;
}
static T_5 void F_34 ( void )
{
}
