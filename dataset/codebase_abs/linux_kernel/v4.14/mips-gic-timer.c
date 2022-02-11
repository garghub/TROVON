static T_1 T_2 F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 ;
if ( V_4 )
return F_2 () ;
do {
V_1 = F_3 () ;
V_3 = F_4 () ;
V_2 = F_3 () ;
} while ( V_2 != V_1 );
return ( ( ( T_1 ) V_1 ) << 32 ) + V_3 ;
}
static int F_5 ( unsigned long V_5 , struct V_6 * V_7 )
{
unsigned long V_8 ;
T_1 V_9 ;
int V_10 ;
V_9 = F_1 () ;
V_9 += ( T_1 ) V_5 ;
F_6 ( V_8 ) ;
F_7 ( F_8 ( F_9 ( V_7 -> V_11 ) ) ) ;
F_10 ( V_9 ) ;
F_11 ( V_8 ) ;
V_10 = ( ( int ) ( F_1 () - V_9 ) >= 0 ) ? - V_12 : 0 ;
return V_10 ;
}
static T_3 F_12 ( int V_13 , void * V_14 )
{
struct V_6 * V_15 = V_14 ;
F_13 ( F_14 () ) ;
V_15 -> V_16 ( V_15 ) ;
return V_17 ;
}
static void F_15 ( unsigned int V_18 ,
struct V_6 * V_15 )
{
V_15 -> V_19 = L_1 ;
V_15 -> V_20 = V_21 |
V_22 ;
V_15 -> V_23 = 350 ;
V_15 -> V_13 = V_24 ;
V_15 -> V_11 = F_16 ( V_18 ) ;
V_15 -> V_25 = F_5 ;
F_17 ( V_15 , V_26 , 0x300 , 0x7fffffff ) ;
F_18 ( V_24 , V_27 ) ;
}
static void F_19 ( struct V_6 * V_15 )
{
F_20 ( V_24 ) ;
}
static void F_21 ( void * V_28 )
{
unsigned long V_29 = ( unsigned long ) V_28 ;
F_22 ( F_23 ( & V_30 ) , V_29 ) ;
}
static int F_24 ( unsigned int V_18 )
{
F_15 ( V_18 , F_23 ( & V_30 ) ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 , unsigned long V_33 ,
void * V_28 )
{
struct V_34 * V_35 = V_28 ;
if ( V_33 == V_36 )
F_26 ( F_21 , ( void * ) V_35 -> V_37 , 1 ) ;
return V_38 ;
}
static int F_27 ( unsigned int V_18 )
{
F_19 ( F_23 ( & V_30 ) ) ;
return 0 ;
}
static int F_28 ( void )
{
int V_39 ;
if ( ! V_26 )
return - V_40 ;
V_39 = F_29 ( V_24 , & V_41 ) ;
if ( V_39 < 0 ) {
F_30 ( L_2 ,
V_24 , V_39 ) ;
return V_39 ;
}
F_31 ( V_42 ,
L_3 ,
F_24 , F_27 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_43 * V_44 )
{
return F_1 () ;
}
static int T_4 F_33 ( void )
{
unsigned int V_45 ;
int V_39 ;
V_45 = F_34 () & V_46 ;
V_45 >>= F_35 ( V_46 ) ;
V_45 *= 4 ;
V_45 += 32 ;
V_47 . V_48 = F_36 ( V_45 ) ;
V_47 . V_23 = 200 + V_26 / 10000000 ;
V_39 = F_37 ( & V_47 , V_26 ) ;
if ( V_39 < 0 )
F_38 ( L_4 ) ;
return V_39 ;
}
static int T_4 F_39 ( struct V_49 * V_50 )
{
struct V_51 * V_51 ;
int V_39 ;
if ( ! F_40 () || ! V_50 -> V_52 ||
! F_41 ( V_50 -> V_52 , L_5 ) ) {
F_38 ( L_6 ) ;
return - V_40 ;
}
V_51 = F_42 ( V_50 , 0 ) ;
if ( ! F_43 ( V_51 ) ) {
V_39 = F_44 ( V_51 ) ;
if ( V_39 < 0 ) {
F_30 ( L_7 ) ;
F_45 ( V_51 ) ;
return V_39 ;
}
V_26 = F_46 ( V_51 ) ;
} else if ( F_47 ( V_50 , L_8 ,
& V_26 ) ) {
F_30 ( L_9 ) ;
return - V_53 ; ;
}
V_24 = F_48 ( V_50 , 0 ) ;
if ( ! V_24 ) {
F_30 ( L_10 ) ;
return - V_53 ; ;
}
V_39 = F_33 () ;
if ( V_39 )
return V_39 ;
V_39 = F_28 () ;
if ( ! V_39 && ! F_43 ( V_51 ) ) {
if ( F_49 ( V_51 , & V_54 ) < 0 )
F_38 ( L_11 ) ;
}
F_50 ( V_55 ) ;
return 0 ;
}
