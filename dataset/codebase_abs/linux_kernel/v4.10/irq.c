static inline void F_1 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + V_4 [ V_2 ] ) ;
}
static inline T_1 F_3 ( unsigned V_2 )
{
return F_4 ( V_3 + V_4 [ V_2 ] ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
F_1 ( F_6 ( V_6 -> V_7 ) , V_8 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
F_1 ( F_6 ( V_6 -> V_7 ) , V_9 ) ;
}
int F_8 ( void )
{
return V_10 ;
}
unsigned int F_9 ( void )
{
return V_11 ;
}
static void F_10 ( struct V_12 * V_13 )
{
T_1 V_14 = F_3 ( V_15 ) ;
if ( V_14 ) {
struct V_16 * V_17 = F_11 ( V_13 ) ;
F_12 ( F_13 ( V_17 , F_14 ( V_14 ) ) ) ;
} else {
F_15 () ;
}
}
T_2 void F_16 ( void )
{
unsigned long V_14 ;
V_14 = F_17 () & F_18 () & V_18 ;
if ( V_14 & V_19 )
F_19 ( V_20 ) ;
else if ( V_14 & V_21 )
F_19 ( V_22 ) ;
else if ( V_14 & V_23 )
F_19 ( V_24 ) ;
else if ( V_14 & V_25 )
F_19 ( V_26 ) ;
else if ( V_14 & V_27 )
F_19 ( V_28 ) ;
else
F_15 () ;
}
static int F_20 ( struct V_16 * V_6 , unsigned int V_29 , T_3 V_30 )
{
F_21 ( V_29 , & V_31 , V_32 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
struct V_36 V_37 ;
struct V_16 * V_17 ;
int V_29 ;
if ( ! F_23 ( V_34 , L_1 ,
V_4 , 6 ) )
F_24 ( L_2 ) ;
V_29 = F_25 ( V_34 , 0 ) ;
if ( ! V_29 )
F_26 ( L_3 ) ;
if ( F_27 ( V_34 , 0 , & V_37 ) )
F_26 ( L_4 ) ;
if ( F_28 ( V_37 . V_38 , F_29 ( & V_37 ) ,
V_37 . V_39 ) < 0 )
F_30 ( L_5 ) ;
V_3 = F_31 ( V_37 . V_38 ,
F_29 ( & V_37 ) ) ;
if ( ! V_3 )
F_26 ( L_6 ) ;
F_1 ( ~ 0 , V_9 ) ;
F_1 ( 0 , V_40 ) ;
V_17 = F_32 ( V_34 , V_41 ,
V_42 , 0 , & V_43 , NULL ) ;
if ( ! V_17 )
F_26 ( L_7 ) ;
F_1 ( V_44 , V_8 ) ;
F_33 ( V_29 , F_10 , V_17 ) ;
V_10 = F_34 ( V_17 , 9 ) ;
return 0 ;
}
void T_4 F_35 ( void )
{
F_36 ( V_45 ) ;
}
