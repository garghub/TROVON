static inline void F_1 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline T_1 F_3 ( unsigned V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
F_1 ( F_6 ( V_5 -> V_6 ) , V_7 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_1 ( F_6 ( V_5 -> V_6 ) , V_8 ) ;
}
unsigned int T_2 F_8 ( void )
{
return V_9 ;
}
static void F_9 ( unsigned int V_10 , struct V_11 * V_12 )
{
T_1 V_13 = F_3 ( V_14 ) ;
if ( V_13 ) {
struct V_15 * V_16 = F_10 ( V_10 ) ;
F_11 ( F_12 ( V_16 , F_13 ( V_13 ) ) ) ;
} else {
F_14 () ;
}
}
T_3 void F_15 ( void )
{
unsigned long V_13 ;
V_13 = F_16 () & F_17 () & V_17 ;
if ( V_13 & V_18 )
F_18 ( V_19 ) ;
else if ( V_13 & V_20 )
F_18 ( V_21 ) ;
else if ( V_13 & V_22 )
F_18 ( V_23 ) ;
else if ( V_13 & V_24 )
F_18 ( V_25 ) ;
else
F_14 () ;
}
static int F_19 ( struct V_15 * V_5 , unsigned int V_10 , T_4 V_26 )
{
F_20 ( V_10 , & V_27 , V_28 ) ;
return 0 ;
}
static int T_5 F_21 ( struct V_29 * V_30 ,
struct V_29 * V_31 )
{
struct V_32 V_33 ;
struct V_15 * V_16 ;
int V_10 ;
V_10 = F_22 ( V_30 , 0 ) ;
if ( ! V_10 )
F_23 ( L_1 ) ;
if ( F_24 ( V_30 , 0 , & V_33 ) )
F_23 ( L_2 ) ;
if ( F_25 ( V_33 . V_34 , F_26 ( & V_33 ) ,
V_33 . V_35 ) < 0 )
F_27 ( L_3 ) ;
V_3 = F_28 ( V_33 . V_34 ,
F_26 ( & V_33 ) ) ;
if ( ! V_3 )
F_23 ( L_4 ) ;
F_1 ( ~ 0 , V_8 ) ;
F_1 ( 0 , V_36 ) ;
V_16 = F_29 ( V_30 , V_37 ,
V_38 , 0 , & V_39 , NULL ) ;
if ( ! V_16 )
F_23 ( L_5 ) ;
F_1 ( V_40 , V_7 ) ;
F_30 ( V_10 , F_9 ) ;
F_31 ( V_10 , V_16 ) ;
V_41 = F_32 ( V_16 , 9 ) ;
return 0 ;
}
void T_5 F_33 ( void )
{
F_34 ( V_42 ) ;
}
