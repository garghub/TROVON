void * F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
if ( ! V_3 )
return NULL ;
V_2 = F_2 ( V_3 , V_1 ) ;
if ( ! V_2 )
return NULL ;
return ( void * ) V_2 ;
}
void F_3 ( void * V_4 , T_1 V_1 )
{
F_4 ( V_3 , ( unsigned long ) V_4 , V_1 ) ;
}
static int T_2 F_5 ( T_3 type , T_3 V_5 , T_3 V_6 ,
T_4 * V_7 )
{
const int V_8 [ 16 ] = { 0 , - 1 , - 1 , 4 , 8 , 16 , 32 , 64 , 128 ,
256 , 512 , 1024 , - 1 , - 1 , - 1 , - 1 } ;
T_4 V_9 ;
int V_10 ;
if ( V_6 > 1 )
asm("mcr p15, 0, %0, c9, c2, 0"
:
: "r" (bank));
if ( ! type )
asm("mrc p15, 0, %0, c9, c1, 0"
: "=r" (tcm_region));
else
asm("mrc p15, 0, %0, c9, c1, 1"
: "=r" (tcm_region));
V_10 = V_8 [ ( V_9 >> 2 ) & 0x0f ] ;
if ( V_10 < 0 ) {
F_6 ( L_1 ,
type ? L_2 : L_3 , V_5 ) ;
return - V_11 ;
} else if ( V_10 > 32 ) {
F_6 ( L_4 ,
type ? L_2 : L_3 , V_5 ) ;
return - V_11 ;
} else {
F_7 ( L_5 ,
type ? L_2 : L_3 ,
V_5 ,
V_10 ,
( V_9 & 0xfffff000U ) ,
( V_9 & 1 ) ? L_6 : L_7 ) ;
}
V_9 = * V_7 | ( V_9 & 0x00000ffeU ) | 1 ;
if ( ! type )
asm("mcr p15, 0, %0, c9, c1, 0"
:
: "r" (tcm_region));
else
asm("mcr p15, 0, %0, c9, c1, 1"
:
: "r" (tcm_region));
* V_7 += ( V_10 << 10 ) ;
F_7 ( L_8 ,
type ? L_2 : L_3 ,
V_5 ,
V_10 ,
( V_9 & 0xfffff000U ) ) ;
return 0 ;
}
void T_2 F_8 ( void )
{
T_4 V_12 = F_9 () ;
T_3 V_13 = ( V_12 >> 16 ) & 0x03 ;
T_3 V_14 = ( V_12 & 0x03 ) ;
char * V_15 ;
char * V_16 ;
char * V_17 ;
int V_18 ;
int V_19 ;
if ( V_13 > 0 ) {
for ( V_19 = 0 ; V_19 < V_13 ; V_19 ++ ) {
V_18 = F_5 ( 0 , V_19 , V_13 , & V_20 ) ;
if ( V_18 )
return;
}
V_21 . V_16 = V_20 - 1 ;
F_10 ( & V_22 , & V_21 ) ;
V_23 [ 0 ] . V_24 = V_20 - V_25 ;
F_11 ( V_23 , 1 ) ;
V_15 = & V_26 ;
V_16 = & V_27 ;
V_17 = & V_28 ;
F_12 ( ( V_16 - V_15 ) > ( V_20 - V_25 ) ) ;
memcpy ( V_15 , V_17 , ( V_16 - V_15 ) ) ;
F_13 ( L_9 , V_15 , V_16 ) ;
}
if ( V_14 > 0 ) {
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ ) {
V_18 = F_5 ( 1 , V_19 , V_14 , & V_29 ) ;
if ( V_18 )
return;
}
V_30 . V_16 = V_29 - 1 ;
F_10 ( & V_22 , & V_30 ) ;
V_31 [ 0 ] . V_24 = V_29 - V_32 ;
F_11 ( V_31 , 1 ) ;
V_15 = & V_33 ;
V_16 = & V_34 ;
V_17 = & V_35 ;
F_12 ( ( V_16 - V_15 ) > ( V_29 - V_32 ) ) ;
memcpy ( V_15 , V_17 , ( V_16 - V_15 ) ) ;
F_13 ( L_10 , V_15 , V_16 ) ;
}
}
static int T_2 F_14 ( void )
{
T_4 V_12 = F_9 () ;
T_4 V_36 = ( T_4 ) & V_27 ;
T_4 V_37 = ( T_4 ) & V_34 ;
int V_18 ;
V_3 = F_15 ( 2 , - 1 ) ;
F_13 ( L_11 ) ;
if ( V_12 & ( 0x03 << 16 ) ) {
if ( V_36 < V_20 ) {
V_18 = F_16 ( V_3 , V_36 ,
V_20 - V_36 , - 1 ) ;
if ( V_18 ) {
F_6 ( L_12 \
L_13 ) ;
return V_18 ;
}
F_13 ( L_14 \
L_15 ,
V_20 - V_36 ,
V_36 ) ;
}
}
if ( V_12 & 0x03 ) {
if ( V_37 < V_29 ) {
V_18 = F_16 ( V_3 , V_37 ,
V_29 - V_37 , - 1 ) ;
if ( V_18 ) {
F_6 ( L_16 \
L_13 ) ;
return V_18 ;
}
F_13 ( L_17 \
L_15 ,
V_29 - V_37 ,
V_37 ) ;
}
}
return 0 ;
}
