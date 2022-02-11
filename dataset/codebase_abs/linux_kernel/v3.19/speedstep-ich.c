static int F_1 ( void )
{
if ( ! V_1 )
return - V_2 ;
F_2 ( V_1 , 0x40 , & V_3 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_3 ( V_4 L_1 ) ;
return - V_2 ;
}
V_3 &= 0xFFFFFFFE ;
if ( ! V_3 ) {
F_3 ( V_4 L_1 ) ;
return - V_2 ;
}
F_4 ( L_2 , V_3 ) ;
return 0 ;
}
static void F_5 ( unsigned int V_5 )
{
T_1 V_6 ;
T_1 V_7 ;
unsigned long V_8 ;
if ( V_5 > 0x1 )
return;
F_6 ( V_8 ) ;
V_7 = F_7 ( V_3 + 0x50 ) ;
F_4 ( L_3 , V_3 , V_7 ) ;
V_7 &= 0xFE ;
V_7 |= V_5 ;
F_4 ( L_4 , V_7 , V_3 ) ;
V_6 = F_7 ( V_3 + 0x20 ) ;
V_6 |= 0x01 ;
F_8 ( V_6 , ( V_3 + 0x20 ) ) ;
F_8 ( V_7 , ( V_3 + 0x50 ) ) ;
V_6 &= 0xfe ;
F_8 ( V_6 , ( V_3 + 0x20 ) ) ;
V_7 = F_7 ( V_3 + 0x50 ) ;
F_9 ( V_8 ) ;
F_4 ( L_3 , V_3 , V_7 ) ;
if ( V_5 == ( V_7 & 0x1 ) )
F_4 ( L_5 ,
F_10 ( V_9 ) / 1000 ) ;
else
F_3 ( V_4 L_6 ) ;
return;
}
static void F_11 ( void * V_10 )
{
F_5 ( * ( unsigned int * ) V_10 ) ;
}
static int F_12 ( void )
{
T_2 V_7 = 0 ;
if ( ! V_1 )
return - V_11 ;
F_13 ( V_1 , 0x00A0 , & V_7 ) ;
if ( ! ( V_7 & 0x08 ) ) {
V_7 |= 0x08 ;
F_4 ( L_7 ) ;
F_14 ( V_1 , 0x00A0 , V_7 ) ;
}
return 0 ;
}
static unsigned int F_15 ( void )
{
V_1 = F_16 ( V_12 ,
V_13 ,
V_14 , V_14 ,
NULL ) ;
if ( V_1 )
return 4 ;
V_1 = F_16 ( V_12 ,
V_15 ,
V_14 , V_14 ,
NULL ) ;
if ( V_1 )
return 3 ;
V_1 = F_16 ( V_12 ,
V_16 ,
V_14 , V_14 ,
NULL ) ;
if ( V_1 ) {
static struct V_17 * V_18 ;
V_18 = F_16 ( V_12 ,
V_19 ,
V_14 , V_14 ,
NULL ) ;
if ( ! V_18 )
return 2 ;
if ( V_18 -> V_20 < 5 ) {
F_4 ( L_8 ) ;
V_1 = NULL ;
F_17 ( V_18 ) ;
return 0 ;
}
F_17 ( V_18 ) ;
return 2 ;
}
return 0 ;
}
static void F_18 ( void * V_21 )
{
unsigned int * V_22 = V_21 ;
* V_22 = F_10 ( V_9 ) ;
}
static unsigned int F_19 ( unsigned int V_23 )
{
unsigned int V_22 ;
if ( F_20 ( V_23 , F_18 , & V_22 , 1 ) != 0 )
F_21 () ;
F_4 ( L_9 , V_22 ) ;
return V_22 ;
}
static int F_22 ( struct V_24 * V_25 , unsigned int V_26 )
{
unsigned int V_27 ;
V_27 = F_23 ( V_25 -> V_28 , V_29 ) ;
F_20 ( V_27 , F_11 , & V_26 ,
true ) ;
return 0 ;
}
static void F_24 ( void * V_30 )
{
struct V_31 * V_31 = V_30 ;
V_31 -> V_32 =
F_25 ( V_9 ,
& V_33 [ V_34 ] . V_35 ,
& V_33 [ V_36 ] . V_35 ,
& V_31 -> V_25 -> V_37 . V_38 ,
& F_5 ) ;
}
static int F_26 ( struct V_24 * V_25 )
{
unsigned int V_27 ;
struct V_31 V_39 ;
#ifdef F_27
F_28 ( V_25 -> V_28 , F_29 ( V_25 -> V_23 ) ) ;
#endif
V_27 = F_23 ( V_25 -> V_28 , V_29 ) ;
V_39 . V_25 = V_25 ;
F_20 ( V_27 , F_24 , & V_39 , 1 ) ;
if ( V_39 . V_32 )
return V_39 . V_32 ;
return F_30 ( V_25 , V_33 ) ;
}
static int T_3 F_31 ( void )
{
if ( ! F_32 ( V_40 ) )
return - V_2 ;
V_9 = F_33 () ;
if ( ! V_9 ) {
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
return - V_11 ;
}
if ( F_1 () )
return - V_2 ;
return F_34 ( & V_41 ) ;
}
static void T_4 F_35 ( void )
{
F_17 ( V_1 ) ;
F_36 ( & V_41 ) ;
}
