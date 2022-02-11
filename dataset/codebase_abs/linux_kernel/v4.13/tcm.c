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
static int T_2 F_10 ( struct V_14 * V_15 , unsigned int V_16 )
{
V_15 -> V_17 [ ( V_16 >> V_18 ) & V_19 ] = 0 ;
V_15 -> V_20 += 4 ;
return 0 ;
}
void T_2 F_11 ( void )
{
T_4 V_21 ;
T_3 V_22 ;
T_3 V_23 ;
T_1 V_24 = & V_25 - & V_26 ;
T_1 V_27 = & V_28 - & V_29 ;
char * V_30 ;
char * V_31 ;
char * V_32 ;
int V_33 ;
int V_34 ;
if ( F_12 () < V_35 ) {
if ( V_24 || V_27 )
F_9 ( L_9
L_10
L_11 , V_24 , V_27 ) ;
return;
}
V_21 = F_13 () ;
if ( V_21 & V_36 )
return;
V_22 = ( V_21 >> 16 ) & 0x03 ;
V_23 = ( V_21 & 0x03 ) ;
F_14 ( & V_37 ) ;
if ( V_22 > 2 )
V_22 = 0 ;
if ( V_23 > 2 )
V_23 = 0 ;
if ( V_22 > 0 ) {
for ( V_34 = 0 ; V_34 < V_22 ; V_34 ++ ) {
V_33 = F_7 ( 0 , V_34 , V_22 , & V_38 ) ;
if ( V_33 )
goto V_39;
}
if ( V_24 > ( V_38 - V_40 ) ) {
F_9 ( L_12
L_13 ,
V_24 , ( V_38 - V_40 ) ) ;
goto V_41;
}
if ( ! ( V_38 - V_40 ) )
goto V_41;
V_42 . V_31 = V_38 - 1 ;
F_15 ( & V_43 , & V_42 ) ;
V_44 [ 0 ] . V_45 = V_38 - V_40 ;
F_16 ( V_44 , 1 ) ;
V_30 = & V_26 ;
V_31 = & V_25 ;
V_32 = & V_46 ;
memcpy ( V_30 , V_32 , V_24 ) ;
F_17 ( L_14 ,
V_30 , V_31 ) ;
V_5 = true ;
} else if ( V_24 ) {
F_9 ( L_15
L_16 , V_24 ) ;
}
V_41:
if ( V_23 > 0 ) {
for ( V_34 = 0 ; V_34 < V_23 ; V_34 ++ ) {
V_33 = F_7 ( 1 , V_34 , V_23 , & V_47 ) ;
if ( V_33 )
goto V_39;
}
if ( V_27 > ( V_47 - V_48 ) ) {
F_9 ( L_17
L_18 ,
V_27 , ( V_47 - V_48 ) ) ;
goto V_39;
}
if ( ! ( V_47 - V_48 ) )
goto V_39;
V_49 . V_31 = V_47 - 1 ;
F_15 ( & V_43 , & V_49 ) ;
V_50 [ 0 ] . V_45 = V_47 - V_48 ;
F_16 ( V_50 , 1 ) ;
V_30 = & V_29 ;
V_31 = & V_28 ;
V_32 = & V_51 ;
memcpy ( V_30 , V_32 , V_27 ) ;
F_17 ( L_19 ,
V_30 , V_31 ) ;
V_6 = true ;
} else if ( V_27 ) {
F_9 ( L_20
L_21 , V_27 ) ;
}
V_39:
F_18 ( & V_37 ) ;
}
static int T_2 F_19 ( void )
{
T_4 V_52 = ( T_4 ) & V_25 ;
T_4 V_53 = ( T_4 ) & V_28 ;
int V_33 ;
V_3 = F_20 ( 2 , - 1 ) ;
F_17 ( L_22 ) ;
if ( V_5 ) {
if ( V_52 < V_38 ) {
V_33 = F_21 ( V_3 , V_52 ,
V_38 - V_52 , - 1 ) ;
if ( V_33 ) {
F_8 ( L_23 \
L_24 ) ;
return V_33 ;
}
F_17 ( L_25 \
L_26 ,
V_38 - V_52 ,
V_52 ) ;
}
}
if ( V_6 ) {
if ( V_53 < V_47 ) {
V_33 = F_21 ( V_3 , V_53 ,
V_47 - V_53 , - 1 ) ;
if ( V_33 ) {
F_8 ( L_27 \
L_24 ) ;
return V_33 ;
}
F_17 ( L_28 \
L_26 ,
V_47 - V_53 ,
V_53 ) ;
}
}
return 0 ;
}
