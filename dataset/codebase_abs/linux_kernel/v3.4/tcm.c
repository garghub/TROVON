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
bool F_5 ( void )
{
return V_5 ;
}
bool F_6 ( void )
{
return V_6 ;
}
static int T_2 F_7 ( T_3 type , T_3 V_7 , T_3 V_8 ,
T_4 * V_9 )
{
const int V_10 [ 16 ] = { 0 , - 1 , - 1 , 4 , 8 , 16 , 32 , 64 , 128 ,
256 , 512 , 1024 , - 1 , - 1 , - 1 , - 1 } ;
T_4 V_11 ;
int V_12 ;
if ( V_8 > 1 )
asm("mcr p15, 0, %0, c9, c2, 0"
:
: "r" (bank));
if ( ! type )
asm("mrc p15, 0, %0, c9, c1, 0"
: "=r" (tcm_region));
else
asm("mrc p15, 0, %0, c9, c1, 1"
: "=r" (tcm_region));
V_12 = V_10 [ ( V_11 >> 2 ) & 0x0f ] ;
if ( V_12 < 0 ) {
F_8 ( L_1 ,
type ? L_2 : L_3 , V_7 ) ;
return - V_13 ;
} else if ( V_12 > 32 ) {
F_8 ( L_4 ,
type ? L_2 : L_3 , V_7 ) ;
return - V_13 ;
} else {
F_9 ( L_5 ,
type ? L_2 : L_3 ,
V_7 ,
V_12 ,
( V_11 & 0xfffff000U ) ,
( V_11 & 1 ) ? L_6 : L_7 ) ;
}
if ( V_12 == 0 )
return 0 ;
V_11 = * V_9 | ( V_11 & 0x00000ffeU ) | 1 ;
if ( ! type )
asm("mcr p15, 0, %0, c9, c1, 0"
:
: "r" (tcm_region));
else
asm("mcr p15, 0, %0, c9, c1, 1"
:
: "r" (tcm_region));
* V_9 += ( V_12 << 10 ) ;
F_9 ( L_8 ,
type ? L_2 : L_3 ,
V_7 ,
V_12 ,
( V_11 & 0xfffff000U ) ) ;
return 0 ;
}
void T_2 F_10 ( void )
{
T_4 V_14 ;
T_3 V_15 ;
T_3 V_16 ;
T_1 V_17 = & V_18 - & V_19 ;
T_1 V_20 = & V_21 - & V_22 ;
char * V_23 ;
char * V_24 ;
char * V_25 ;
int V_26 ;
int V_27 ;
if ( F_11 () < V_28 ) {
if ( V_17 || V_20 )
F_9 ( L_9
L_10
L_11 , V_17 , V_20 ) ;
return;
}
V_14 = F_12 () ;
V_15 = ( V_14 >> 16 ) & 0x03 ;
V_16 = ( V_14 & 0x03 ) ;
if ( V_15 > 2 )
V_15 = 0 ;
if ( V_16 > 2 )
V_16 = 0 ;
if ( V_15 > 0 ) {
for ( V_27 = 0 ; V_27 < V_15 ; V_27 ++ ) {
V_26 = F_7 ( 0 , V_27 , V_15 , & V_29 ) ;
if ( V_26 )
return;
}
if ( V_17 > ( V_29 - V_30 ) ) {
F_9 ( L_12
L_13 ,
V_17 , ( V_29 - V_30 ) ) ;
goto V_31;
}
V_32 . V_24 = V_29 - 1 ;
F_13 ( & V_33 , & V_32 ) ;
V_34 [ 0 ] . V_35 = V_29 - V_30 ;
F_14 ( V_34 , 1 ) ;
V_23 = & V_19 ;
V_24 = & V_18 ;
V_25 = & V_36 ;
memcpy ( V_23 , V_25 , V_17 ) ;
F_15 ( L_14 ,
V_23 , V_24 ) ;
V_5 = true ;
} else if ( V_17 ) {
F_9 ( L_15
L_16 , V_17 ) ;
}
V_31:
if ( V_16 > 0 ) {
for ( V_27 = 0 ; V_27 < V_16 ; V_27 ++ ) {
V_26 = F_7 ( 1 , V_27 , V_16 , & V_37 ) ;
if ( V_26 )
return;
}
if ( V_20 > ( V_37 - V_38 ) ) {
F_9 ( L_17
L_18 ,
V_20 , ( V_37 - V_38 ) ) ;
return;
}
V_39 . V_24 = V_37 - 1 ;
F_13 ( & V_33 , & V_39 ) ;
V_40 [ 0 ] . V_35 = V_37 - V_38 ;
F_14 ( V_40 , 1 ) ;
V_23 = & V_22 ;
V_24 = & V_21 ;
V_25 = & V_41 ;
memcpy ( V_23 , V_25 , V_20 ) ;
F_15 ( L_19 ,
V_23 , V_24 ) ;
V_6 = true ;
} else if ( V_20 ) {
F_9 ( L_20
L_21 , V_20 ) ;
}
}
static int T_2 F_16 ( void )
{
T_4 V_42 = ( T_4 ) & V_18 ;
T_4 V_43 = ( T_4 ) & V_21 ;
int V_26 ;
V_3 = F_17 ( 2 , - 1 ) ;
F_15 ( L_22 ) ;
if ( V_5 ) {
if ( V_42 < V_29 ) {
V_26 = F_18 ( V_3 , V_42 ,
V_29 - V_42 , - 1 ) ;
if ( V_26 ) {
F_8 ( L_23 \
L_24 ) ;
return V_26 ;
}
F_15 ( L_25 \
L_26 ,
V_29 - V_42 ,
V_42 ) ;
}
}
if ( V_6 ) {
if ( V_43 < V_37 ) {
V_26 = F_18 ( V_3 , V_43 ,
V_37 - V_43 , - 1 ) ;
if ( V_26 ) {
F_8 ( L_27 \
L_24 ) ;
return V_26 ;
}
F_15 ( L_28 \
L_26 ,
V_37 - V_43 ,
V_43 ) ;
}
}
return 0 ;
}
