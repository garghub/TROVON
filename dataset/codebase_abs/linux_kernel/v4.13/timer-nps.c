static int T_1 F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 ,
struct V_4 * * V_4 )
{
int V_5 ;
* V_4 = F_2 ( V_2 , 0 ) ;
V_5 = F_3 ( * V_4 ) ;
if ( V_5 ) {
F_4 ( L_1 ) ;
return V_5 ;
}
V_5 = F_5 ( * V_4 ) ;
if ( V_5 ) {
F_4 ( L_2 ) ;
F_6 ( * V_4 ) ;
return V_5 ;
}
* V_3 = F_7 ( * V_4 ) ;
if ( ! ( * V_3 ) ) {
F_4 ( L_3 ) ;
F_8 ( * V_4 ) ;
F_6 ( * V_4 ) ;
return - V_6 ;
}
return 0 ;
}
static T_2 F_9 ( struct V_7 * V_8 )
{
int V_9 = F_10 () >> V_10 ;
return ( T_2 ) F_11 ( V_11 [ V_9 ] ) ;
}
static int T_1 F_12 ( struct V_1 * V_2 )
{
int V_5 , V_9 ;
struct V_4 * V_4 ;
unsigned long V_12 ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ )
V_11 [ V_9 ] =
F_13 ( ( V_9 << V_10 ) ,
V_14 , V_15 ) ;
V_5 = F_1 ( V_2 , & V_12 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_11 , L_4 ,
V_12 , 300 , 32 , F_9 ) ;
if ( V_5 ) {
F_4 ( L_5 ) ;
F_8 ( V_4 ) ;
}
return V_5 ;
}
static void F_15 ( void )
{
int V_16 ;
unsigned int V_17 , V_18 ;
F_16 ( & V_17 ) ;
V_18 = F_17 ( V_19 ) ;
V_16 = F_17 ( V_20 ) ;
V_18 &= ~ ( 1 << V_16 ) ;
F_18 ( V_19 , V_18 ) ;
if ( ! V_18 )
F_18 ( V_21 , V_22 ) ;
else
F_18 ( V_21 ,
V_23 | V_22 ) ;
F_19 ( V_17 ) ;
}
static void F_20 ( unsigned long V_24 )
{
int V_16 ;
unsigned int V_17 , V_18 ;
F_16 ( & V_17 ) ;
V_16 = F_17 ( V_20 ) ;
V_18 = F_17 ( V_19 ) ;
V_18 |= ( 1 << V_16 ) ;
F_18 ( V_19 , V_18 ) ;
F_18 ( V_25 , V_24 ) ;
F_18 ( V_26 , 0 ) ;
F_18 ( V_21 ,
V_23 | V_22 ) ;
F_19 ( V_17 ) ;
}
static int F_21 ( struct V_27 * V_28 )
{
F_15 () ;
F_22 ( V_29 ) ;
return 0 ;
}
static int F_23 ( unsigned long V_24 ,
struct V_27 * V_28 )
{
F_20 ( V_24 ) ;
F_24 ( V_29 , V_30 ) ;
return 0 ;
}
static T_3 F_25 ( int V_31 , void * V_32 )
{
struct V_27 * V_33 = V_32 ;
F_15 () ;
V_33 -> V_34 ( V_33 ) ;
return V_35 ;
}
static int F_26 ( unsigned int V_36 )
{
struct V_27 * V_33 = F_27 ( & V_37 ) ;
V_33 -> V_38 = F_28 ( F_29 () ) ;
F_30 ( V_33 , V_39 , 0 , V_40 ) ;
F_24 ( V_29 , V_30 ) ;
return 0 ;
}
static int F_31 ( unsigned int V_36 )
{
F_22 ( V_29 ) ;
return 0 ;
}
static int T_1 F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
int V_5 ;
V_29 = F_33 ( V_2 , 0 ) ;
if ( V_29 <= 0 ) {
F_4 ( L_6 ) ;
return - V_6 ;
}
V_5 = F_1 ( V_2 , & V_39 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_34 ( V_29 , F_25 ,
L_7 ,
& V_37 ) ;
if ( V_5 ) {
F_4 ( L_8 ) ;
F_8 ( V_4 ) ;
return V_5 ;
}
V_5 = F_35 ( V_41 ,
L_9 ,
F_26 ,
F_31 ) ;
if ( V_5 ) {
F_4 ( L_10 ) ;
F_8 ( V_4 ) ;
F_36 ( V_29 , & V_37 ) ;
return V_5 ;
}
return 0 ;
}
