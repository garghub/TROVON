static T_1 unsigned char * F_1 ( unsigned char * V_1 )
{
return V_1 + 0 ;
}
static T_1 unsigned char * F_2 ( int V_2 )
{
unsigned char V_3 [ 32 ] ;
int V_4 ;
for ( V_4 = 0 ; V_4 < sizeof( V_3 ) ; V_4 ++ ) {
V_3 [ V_4 ] = V_2 & 0xff ;
}
return F_1 ( V_3 ) ;
}
static T_1 void F_3 ( bool V_5 , bool V_6 )
{
unsigned long V_7 ;
unsigned char V_8 [ 32 ] ;
unsigned char * V_9 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < sizeof( V_8 ) ; V_4 ++ )
V_8 [ V_4 ] = V_10 [ V_4 % sizeof( V_10 ) ] ;
if ( V_6 ) {
V_9 = F_2 ( ( V_11 ) & V_9 ) ;
} else {
V_9 = F_4 ( V_12 ) + V_13 ;
V_9 -= sizeof( unsigned long ) ;
}
V_7 = F_5 ( NULL , 0 , V_14 ,
V_15 | V_16 | V_17 ,
V_18 | V_19 , 0 ) ;
if ( V_7 >= V_20 ) {
F_6 ( L_1 ) ;
return;
}
if ( V_5 ) {
F_7 ( L_2 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_8 ,
V_22 + sizeof( V_8 ) ) ) {
F_6 ( L_3 ) ;
goto V_23;
}
F_7 ( L_4 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_9 ,
V_22 + sizeof( V_8 ) ) ) {
F_6 ( L_5 ) ;
goto V_23;
}
} else {
if ( ! V_6 )
goto V_23;
F_7 ( L_6 ) ;
if ( F_9 ( V_8 , ( void V_21 * ) V_7 ,
V_22 + sizeof( V_8 ) ) ) {
F_6 ( L_7 ) ;
goto V_23;
}
F_7 ( L_8 ) ;
if ( F_9 ( V_9 , ( void V_21 * ) V_7 ,
V_22 + sizeof( V_8 ) ) ) {
F_6 ( L_9 ) ;
goto V_23;
}
}
V_23:
F_10 ( V_7 , V_14 ) ;
}
static void F_11 ( bool V_5 )
{
unsigned long V_7 ;
unsigned char * V_24 , * V_25 ;
T_2 V_26 = V_22 + 1024 ;
V_24 = F_12 ( V_26 , V_27 ) ;
V_25 = F_12 ( V_26 , V_27 ) ;
if ( ! V_24 || ! V_25 ) {
F_6 ( L_10 ) ;
goto V_28;
}
V_7 = F_5 ( NULL , 0 , V_14 ,
V_15 | V_16 | V_17 ,
V_18 | V_19 , 0 ) ;
if ( V_7 >= V_20 ) {
F_6 ( L_1 ) ;
goto V_28;
}
memset ( V_24 , 'A' , V_26 ) ;
memset ( V_25 , 'B' , V_26 ) ;
if ( V_5 ) {
F_7 ( L_11 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_24 , V_26 ) ) {
F_6 ( L_3 ) ;
goto V_23;
}
F_7 ( L_12 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_24 , 2 * V_26 ) ) {
F_6 ( L_5 ) ;
goto V_23;
}
} else {
F_7 ( L_13 ) ;
if ( F_9 ( V_24 , ( void V_21 * ) V_7 , V_26 ) ) {
F_6 ( L_7 ) ;
goto V_23;
}
F_7 ( L_14 ) ;
if ( F_9 ( V_24 , ( void V_21 * ) V_7 , 2 * V_26 ) ) {
F_6 ( L_9 ) ;
goto V_23;
}
}
V_23:
F_10 ( V_7 , V_14 ) ;
V_28:
F_13 ( V_24 ) ;
F_13 ( V_25 ) ;
}
static void F_14 ( bool V_5 )
{
unsigned long V_7 ;
unsigned char * V_29 = NULL ;
unsigned char * V_30 = NULL ;
if ( ! V_31 ) {
F_6 ( L_15 ) ;
return;
}
V_29 = F_12 ( V_32 , V_27 ) ;
V_30 = F_15 ( V_31 , V_27 ) ;
if ( ! V_29 || ! V_30 ) {
F_6 ( L_16 ) ;
goto V_33;
}
V_7 = F_5 ( NULL , 0 , V_14 ,
V_15 | V_16 | V_17 ,
V_18 | V_19 , 0 ) ;
if ( V_7 >= V_20 ) {
F_6 ( L_1 ) ;
goto V_33;
}
memset ( V_29 , 'A' , V_32 ) ;
memset ( V_30 , 'B' , V_32 ) ;
if ( V_5 ) {
F_7 ( L_17 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_29 ,
V_32 ) ) {
F_6 ( L_3 ) ;
goto V_23;
}
F_7 ( L_18 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_30 ,
V_32 ) ) {
F_6 ( L_5 ) ;
goto V_23;
}
} else {
F_7 ( L_19 ) ;
if ( F_9 ( V_29 , ( void V_21 * ) V_7 ,
V_32 ) ) {
F_6 ( L_7 ) ;
goto V_23;
}
F_7 ( L_20 ) ;
if ( F_9 ( V_30 , ( void V_21 * ) V_7 ,
V_32 ) ) {
F_6 ( L_9 ) ;
goto V_23;
}
}
V_23:
F_10 ( V_7 , V_14 ) ;
V_33:
if ( V_30 )
F_16 ( V_31 , V_30 ) ;
F_13 ( V_29 ) ;
}
void F_17 ( void )
{
F_11 ( true ) ;
}
void F_18 ( void )
{
F_11 ( false ) ;
}
void F_19 ( void )
{
F_14 ( true ) ;
}
void F_20 ( void )
{
F_14 ( false ) ;
}
void F_21 ( void )
{
F_3 ( true , true ) ;
}
void F_22 ( void )
{
F_3 ( false , true ) ;
}
void F_23 ( void )
{
F_3 ( true , false ) ;
}
void F_24 ( void )
{
unsigned long V_7 ;
V_7 = F_5 ( NULL , 0 , V_14 ,
V_15 | V_16 | V_17 ,
V_18 | V_19 , 0 ) ;
if ( V_7 >= V_20 ) {
F_6 ( L_1 ) ;
return;
}
F_7 ( L_21 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , V_10 ,
V_22 + sizeof( V_10 ) ) ) {
F_6 ( L_3 ) ;
goto V_23;
}
F_7 ( L_22 ) ;
if ( F_8 ( ( void V_21 * ) V_7 , F_5 ,
V_22 + V_14 ) ) {
F_6 ( L_5 ) ;
goto V_23;
}
V_23:
F_10 ( V_7 , V_14 ) ;
}
void T_3 F_25 ( void )
{
V_31 = F_26 ( L_23 , V_32 , 0 ,
0 , NULL ) ;
}
void T_4 F_27 ( void )
{
F_28 ( V_31 ) ;
}
