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
static int F_22 ( struct V_24 * V_25 ,
unsigned int V_26 ,
unsigned int V_27 )
{
unsigned int V_28 = 0 , V_29 ;
struct V_30 V_31 ;
int V_32 ;
if ( F_23 ( V_25 , & V_33 [ 0 ] ,
V_26 , V_27 , & V_28 ) )
return - V_11 ;
V_29 = F_24 ( V_25 -> V_34 , V_35 ) ;
V_31 . V_36 = F_19 ( V_29 ) ;
V_31 . V_37 = V_33 [ V_28 ] . V_38 ;
V_31 . V_23 = V_25 -> V_23 ;
F_4 ( L_10 , V_31 . V_36 , V_31 . V_37 ) ;
if ( V_31 . V_36 == V_31 . V_37 )
return 0 ;
F_25 (i, policy->cpus) {
V_31 . V_23 = V_32 ;
F_26 ( & V_31 , V_39 ) ;
}
F_20 ( V_29 , F_11 , & V_28 ,
true ) ;
F_25 (i, policy->cpus) {
V_31 . V_23 = V_32 ;
F_26 ( & V_31 , V_40 ) ;
}
return 0 ;
}
static int F_27 ( struct V_24 * V_25 )
{
return F_28 ( V_25 , & V_33 [ 0 ] ) ;
}
static void F_29 ( void * V_41 )
{
struct V_42 * V_42 = V_41 ;
V_42 -> V_43 =
F_30 ( V_9 ,
& V_33 [ V_44 ] . V_38 ,
& V_33 [ V_45 ] . V_38 ,
& V_42 -> V_25 -> V_46 . V_47 ,
& F_5 ) ;
}
static int F_31 ( struct V_24 * V_25 )
{
int V_48 ;
unsigned int V_29 , V_22 ;
struct V_42 V_49 ;
#ifdef F_32
F_33 ( V_25 -> V_34 , F_34 ( V_25 -> V_23 ) ) ;
#endif
V_29 = F_24 ( V_25 -> V_34 , V_35 ) ;
V_49 . V_25 = V_25 ;
F_20 ( V_29 , F_29 , & V_49 , 1 ) ;
if ( V_49 . V_43 )
return V_49 . V_43 ;
V_22 = F_19 ( V_29 ) ;
if ( ! V_22 )
return - V_50 ;
F_4 ( L_11 ,
( V_22 == V_33 [ V_44 ] . V_38 )
? L_12 : L_13 ,
( V_22 / 1000 ) ) ;
V_25 -> V_51 = V_22 ;
V_48 = F_35 ( V_25 , V_33 ) ;
if ( V_48 )
return V_48 ;
F_36 ( V_33 , V_25 -> V_23 ) ;
return 0 ;
}
static int F_37 ( struct V_24 * V_25 )
{
F_38 ( V_25 -> V_23 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
V_9 = F_40 () ;
if ( ! V_9 ) {
F_4 ( L_14
L_15 ) ;
return - V_2 ;
}
if ( ! F_15 () ) {
F_4 ( L_16
L_17 ) ;
return - V_2 ;
}
if ( F_12 () ) {
F_17 ( V_1 ) ;
return - V_11 ;
}
if ( F_1 () )
return - V_2 ;
return F_41 ( & V_52 ) ;
}
static void T_4 F_42 ( void )
{
F_17 ( V_1 ) ;
F_43 ( & V_52 ) ;
}
