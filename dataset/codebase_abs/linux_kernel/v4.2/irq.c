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
static void F_10 ( unsigned int V_12 , struct V_13 * V_14 )
{
T_1 V_15 = F_3 ( V_16 ) ;
if ( V_15 ) {
struct V_17 * V_18 = F_11 ( V_14 ) ;
F_12 ( F_13 ( V_18 , F_14 ( V_15 ) ) ) ;
} else {
F_15 () ;
}
}
T_2 void F_16 ( void )
{
unsigned long V_15 ;
V_15 = F_17 () & F_18 () & V_19 ;
if ( V_15 & V_20 )
F_19 ( V_21 ) ;
else if ( V_15 & V_22 )
F_19 ( V_23 ) ;
else if ( V_15 & V_24 )
F_19 ( V_25 ) ;
else if ( V_15 & V_26 )
F_19 ( V_27 ) ;
else if ( V_15 & V_28 )
F_19 ( V_29 ) ;
else
F_15 () ;
}
static int F_20 ( struct V_17 * V_6 , unsigned int V_12 , T_3 V_30 )
{
F_21 ( V_12 , & V_31 , V_32 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
struct V_36 V_37 ;
struct V_17 * V_18 ;
int V_12 ;
if ( ! F_23 ( V_34 , L_1 ,
V_4 , 6 ) )
F_24 ( L_2 ) ;
V_12 = F_25 ( V_34 , 0 ) ;
if ( ! V_12 )
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
V_18 = F_32 ( V_34 , V_41 ,
V_42 , 0 , & V_43 , NULL ) ;
if ( ! V_18 )
F_26 ( L_7 ) ;
F_1 ( V_44 , V_8 ) ;
F_33 ( V_12 , F_10 , V_18 ) ;
V_10 = F_34 ( V_18 , 9 ) ;
return 0 ;
}
void T_4 F_35 ( void )
{
F_36 ( V_45 ) ;
}
