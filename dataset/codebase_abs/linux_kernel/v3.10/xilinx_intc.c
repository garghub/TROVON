static void F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void * V_4 = F_3 ( V_2 ) ;
F_4 ( L_1 , V_3 ) ;
F_5 ( V_4 + V_5 , 1 << V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_6 )
{
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void * V_4 = F_3 ( V_2 ) ;
F_4 ( L_2 , V_3 ) ;
F_5 ( V_4 + V_7 , 1 << V_3 ) ;
F_5 ( V_4 + V_8 , 1 << V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void * V_4 = F_3 ( V_2 ) ;
F_4 ( L_2 , V_3 ) ;
F_5 ( V_4 + V_7 , 1 << V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void * V_4 = F_3 ( V_2 ) ;
F_4 ( L_3 , V_3 ) ;
F_5 ( V_4 + V_8 , 1 << V_3 ) ;
}
static int F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const T_1 * V_13 , unsigned int V_14 ,
T_2 * V_15 ,
unsigned int * V_16 )
{
if ( ( V_14 < 2 ) || ( V_13 [ 0 ] >= V_17 ) )
return - V_18 ;
V_19 [ V_13 [ 0 ] ] = V_20 [ V_13 [ 1 ] ] ;
* V_15 = V_13 [ 0 ] ;
* V_16 = V_20 [ V_13 [ 1 ] ] ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 , unsigned int V_21 ,
T_2 V_3 )
{
F_12 ( V_21 , V_10 -> V_22 ) ;
if ( V_19 [ V_3 ] == V_23 ||
V_19 [ V_3 ] == V_24 ) {
F_13 ( V_21 , & V_25 ,
V_26 ) ;
} else {
F_13 ( V_21 , & V_27 ,
V_28 ) ;
}
return 0 ;
}
struct V_9 * T_3
F_14 ( struct V_11 * V_29 )
{
struct V_9 * V_3 ;
void * V_4 ;
V_4 = F_15 ( V_29 , 0 ) ;
if ( ! V_4 ) {
F_16 ( L_4 ) ;
return NULL ;
}
F_5 ( V_4 + V_30 , 0 ) ;
F_5 ( V_4 + V_8 , ~ ( T_1 ) 0 ) ;
F_5 ( V_4 + V_31 , 0x3UL ) ;
V_3 = F_17 ( V_29 , V_17 , & V_32 ,
V_4 ) ;
if ( ! V_3 )
F_18 ( __FILE__ L_5 ) ;
return V_3 ;
}
int F_19 ( void )
{
void * V_4 = V_33 -> V_22 ;
F_4 ( L_6 ) ;
return F_20 ( V_33 , F_21 ( V_4 + V_34 ) ) ;
}
static void F_22 ( unsigned int V_3 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_23 ( V_36 ) ;
unsigned int V_39 = F_24 () ;
if ( V_39 )
F_25 ( V_39 ) ;
V_38 -> V_40 ( & V_36 -> V_1 ) ;
}
static void T_3 F_26 ( void )
{
struct V_11 * V_41 ;
int V_39 ;
V_41 = F_27 ( NULL , NULL , L_7 ) ;
if ( ! V_41 )
return;
V_39 = F_28 ( V_41 , 0 ) ;
if ( ! V_39 ) {
F_16 ( L_8 ) ;
goto V_42;
}
F_29 ( V_41 , 0 ) ;
F_30 ( V_39 , F_22 ) ;
F_31 ( 0xc0 , 0x4d0 ) ;
F_31 ( 0xc0 , 0x4d1 ) ;
V_42:
F_32 ( V_41 ) ;
}
static inline void F_26 ( void ) { return; }
void T_3 F_33 ( void )
{
struct V_11 * V_29 ;
F_34 (np, xilinx_intc_match) {
if ( ! F_35 ( V_29 , L_9 , NULL ) )
break;
}
F_36 ( ! V_29 ) ;
V_33 = F_14 ( V_29 ) ;
F_36 ( ! V_33 ) ;
F_37 ( V_33 ) ;
F_32 ( V_29 ) ;
F_26 () ;
}
