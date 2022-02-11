static inline void F_1 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 &= ~ ( V_4 | V_5 ) ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static inline void F_4 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 |= ( V_6 << V_7 ) |
V_5 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static inline void F_5 ( void )
{
F_3 ( V_8 , V_2 + V_9 ) ;
}
static inline unsigned long F_6 ( void )
{
return F_2 ( V_2 + V_10 ) ;
}
static unsigned long F_7 ( void )
{
return F_6 () ;
}
static T_1 T_2 F_8 ( void )
{
return F_6 () ;
}
static int T_3 F_9 ( unsigned long V_11 )
{
V_12 . V_13 = & F_7 ;
V_12 . V_14 = V_11 ;
F_10 ( & V_12 ) ;
F_11 ( F_8 , 32 , V_11 ) ;
return F_12 ( V_2 + V_10 , L_1 ,
V_11 , 200 , 32 , V_15 ) ;
}
static int F_13 ( unsigned long V_16 ,
struct V_17 * V_18 )
{
unsigned long V_19 , V_20 ;
V_19 = F_6 () ;
V_19 += V_16 ;
F_3 ( V_19 , V_2 + V_21 ) ;
V_20 = F_6 () ;
return ( int ) ( ( V_19 - V_20 ) <= 0 ) ? - V_22 : 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
F_4 () ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
F_1 () ;
return 0 ;
}
static T_4 F_16 ( int V_23 , void * V_24 )
{
struct V_17 * V_18 = V_24 ;
F_5 () ;
V_18 -> V_25 ( V_18 ) ;
return V_26 ;
}
static int T_3 F_17 ( unsigned long V_11 , int V_23 )
{
int V_27 ;
V_27 = F_18 ( V_23 , F_16 , V_28 | V_29 ,
L_2 , & V_30 ) ;
V_30 . V_31 = F_19 ( 0 ) ;
V_30 . V_23 = V_23 ;
F_20 ( & V_30 ,
V_11 , 300 , 0xfffffffe ) ;
return V_27 ;
}
static int T_3 F_21 ( struct V_32 * V_33 )
{
struct V_34 * V_35 , * V_36 ;
int V_23 , V_27 ;
T_5 V_11 ;
V_2 = F_22 ( V_33 , 0 ) ;
if ( ! V_2 ) {
F_23 ( L_3 ) ;
return - V_37 ;
}
V_23 = F_24 ( V_33 , 0 ) ;
if ( ! V_23 ) {
F_23 ( L_4 ) ;
V_27 = - V_38 ;
goto V_39;
}
V_35 = F_25 ( V_33 , L_5 ) ;
V_36 = F_25 ( V_33 , L_6 ) ;
if ( F_26 ( V_35 ) || F_26 ( V_36 ) ) {
F_23 ( L_7 ) ;
V_27 = - V_40 ;
goto V_41;
}
V_27 = F_27 ( V_35 ) ;
if ( V_27 ) {
F_23 ( L_8 , V_27 ) ;
goto V_41;
}
V_27 = F_27 ( V_36 ) ;
if ( V_27 ) {
F_23 ( L_9 , V_27 ) ;
goto V_42;
}
F_3 ( 0 , V_2 + V_43 ) ;
F_3 ( 0 , V_2 + V_10 ) ;
F_3 ( 0 , V_2 + V_3 ) ;
F_3 ( V_44 | V_45 ,
V_2 + V_43 ) ;
F_3 ( 0xffffffff , V_2 + V_46 ) ;
V_11 = F_28 ( V_36 ) >> 3 ;
V_27 = F_9 ( V_11 ) ;
if ( V_27 )
goto V_42;
V_27 = F_17 ( V_11 , V_23 ) ;
if ( V_27 )
goto V_42;
return 0 ;
V_42:
F_29 ( V_35 ) ;
V_41:
F_30 ( V_36 ) ;
F_30 ( V_35 ) ;
V_39:
F_31 ( V_2 ) ;
return V_27 ;
}
