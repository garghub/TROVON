static int F_1 ( void )
{
if ( ! V_1 )
return - V_2 ;
F_2 ( V_1 , 0x40 , & V_3 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_3 ( L_1 ) ;
return - V_2 ;
}
V_3 &= 0xFFFFFFFE ;
if ( ! V_3 ) {
F_3 ( L_1 ) ;
return - V_2 ;
}
F_4 ( L_2 , V_3 ) ;
return 0 ;
}
static void F_5 ( unsigned int V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
unsigned long V_7 ;
if ( V_4 > 0x1 )
return;
F_6 ( V_7 ) ;
V_6 = F_7 ( V_3 + 0x50 ) ;
F_4 ( L_3 , V_3 , V_6 ) ;
V_6 &= 0xFE ;
V_6 |= V_4 ;
F_4 ( L_4 , V_6 , V_3 ) ;
V_5 = F_7 ( V_3 + 0x20 ) ;
V_5 |= 0x01 ;
F_8 ( V_5 , ( V_3 + 0x20 ) ) ;
F_8 ( V_6 , ( V_3 + 0x50 ) ) ;
V_5 &= 0xfe ;
F_8 ( V_5 , ( V_3 + 0x20 ) ) ;
V_6 = F_7 ( V_3 + 0x50 ) ;
F_9 ( V_7 ) ;
F_4 ( L_3 , V_3 , V_6 ) ;
if ( V_4 == ( V_6 & 0x1 ) )
F_4 ( L_5 ,
F_10 ( V_8 ) / 1000 ) ;
else
F_3 ( L_6 ) ;
return;
}
static void F_11 ( void * V_9 )
{
F_5 ( * ( unsigned int * ) V_9 ) ;
}
static int F_12 ( void )
{
T_2 V_6 = 0 ;
if ( ! V_1 )
return - V_10 ;
F_13 ( V_1 , 0x00A0 , & V_6 ) ;
if ( ! ( V_6 & 0x08 ) ) {
V_6 |= 0x08 ;
F_4 ( L_7 ) ;
F_14 ( V_1 , 0x00A0 , V_6 ) ;
}
return 0 ;
}
static unsigned int F_15 ( void )
{
V_1 = F_16 ( V_11 ,
V_12 ,
V_13 , V_13 ,
NULL ) ;
if ( V_1 )
return 4 ;
V_1 = F_16 ( V_11 ,
V_14 ,
V_13 , V_13 ,
NULL ) ;
if ( V_1 )
return 3 ;
V_1 = F_16 ( V_11 ,
V_15 ,
V_13 , V_13 ,
NULL ) ;
if ( V_1 ) {
static struct V_16 * V_17 ;
V_17 = F_16 ( V_11 ,
V_18 ,
V_13 , V_13 ,
NULL ) ;
if ( ! V_17 )
return 2 ;
if ( V_17 -> V_19 < 5 ) {
F_4 ( L_8 ) ;
V_1 = NULL ;
F_17 ( V_17 ) ;
return 0 ;
}
F_17 ( V_17 ) ;
return 2 ;
}
return 0 ;
}
static void F_18 ( void * V_20 )
{
unsigned int * V_21 = V_20 ;
* V_21 = F_10 ( V_8 ) ;
}
static unsigned int F_19 ( unsigned int V_22 )
{
unsigned int V_21 ;
if ( F_20 ( V_22 , F_18 , & V_21 , 1 ) != 0 )
F_21 () ;
F_4 ( L_9 , V_21 ) ;
return V_21 ;
}
static int F_22 ( struct V_23 * V_24 , unsigned int V_25 )
{
unsigned int V_26 ;
V_26 = F_23 ( V_24 -> V_27 , V_28 ) ;
F_20 ( V_26 , F_11 , & V_25 ,
true ) ;
return 0 ;
}
static void F_24 ( void * V_29 )
{
struct V_30 * V_30 = V_29 ;
V_30 -> V_31 =
F_25 ( V_8 ,
& V_32 [ V_33 ] . V_34 ,
& V_32 [ V_35 ] . V_34 ,
& V_30 -> V_24 -> V_36 . V_37 ,
& F_5 ) ;
}
static int F_26 ( struct V_23 * V_24 )
{
unsigned int V_26 ;
struct V_30 V_38 ;
#ifdef F_27
F_28 ( V_24 -> V_27 , F_29 ( V_24 -> V_22 ) ) ;
#endif
V_26 = F_23 ( V_24 -> V_27 , V_28 ) ;
V_38 . V_24 = V_24 ;
F_20 ( V_26 , F_24 , & V_38 , 1 ) ;
if ( V_38 . V_31 )
return V_38 . V_31 ;
return F_30 ( V_24 , V_32 ) ;
}
static int T_3 F_31 ( void )
{
if ( ! F_32 ( V_39 ) )
return - V_2 ;
V_8 = F_33 () ;
if ( ! V_8 ) {
F_4 ( L_10
L_11 ) ;
return - V_2 ;
}
if ( ! F_15 () ) {
F_4 ( L_12
L_13 ) ;
return - V_2 ;
}
if ( F_12 () ) {
F_17 ( V_1 ) ;
return - V_10 ;
}
if ( F_1 () )
return - V_2 ;
return F_34 ( & V_40 ) ;
}
static void T_4 F_35 ( void )
{
F_17 ( V_1 ) ;
F_36 ( & V_40 ) ;
}
