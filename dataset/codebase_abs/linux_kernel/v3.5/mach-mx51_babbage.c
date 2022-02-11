static int F_1 ( void )
{
T_1 V_1 = V_2 ;
int V_3 ;
F_2 ( V_1 ) ;
V_3 = F_3 ( V_4 ,
F_4 ( V_4 ) ) ;
if ( V_3 ) {
F_5 ( L_1 , V_3 ) ;
return V_3 ;
}
F_6 ( 100 ) ;
F_7 ( V_5 , 1 ) ;
F_7 ( V_6 , 1 ) ;
F_8 ( V_4 ,
F_4 ( V_4 ) ) ;
return 0 ;
}
static inline void F_9 ( void )
{
int V_3 ;
V_3 = F_10 ( V_7 ,
V_8 , L_2 ) ;
if ( V_3 ) {
F_11 ( V_9 L_3 , V_3 ) ;
return;
}
F_6 ( 2 ) ;
F_7 ( V_7 , 1 ) ;
}
static inline void F_12 ( void )
{
int V_3 ;
V_3 = F_10 ( V_10 ,
V_8 , L_4 ) ;
if ( V_3 ) {
F_11 ( V_9 L_5 , V_3 ) ;
return;
}
F_6 ( 1 ) ;
F_7 ( V_10 , 1 ) ;
}
static int F_13 ( struct V_11 * V_12 )
{
T_2 V_13 ;
void T_3 * V_14 ;
void T_3 * V_15 ;
V_14 = F_14 ( V_16 , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
V_15 = V_14 + V_19 ;
V_13 = F_15 ( V_15 + V_20 ) ;
V_13 &= ~ V_21 ;
V_13 |= V_22 ;
F_16 ( V_13 , V_15 + V_20 ) ;
F_17 ( V_14 ) ;
F_18 ( 10 ) ;
return F_19 ( 0 , V_23 ) ;
}
static int F_20 ( struct V_11 * V_12 )
{
T_2 V_13 ;
void T_3 * V_14 ;
void T_3 * V_15 ;
V_14 = F_14 ( V_16 , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
V_15 = V_14 + V_19 ;
V_13 = F_15 ( V_15 + V_24 ) ;
F_16 ( V_13 | V_25 , V_15 + V_24 ) ;
F_17 ( V_14 ) ;
F_18 ( 10 ) ;
return F_19 ( 1 , V_26 |
V_27 ) ;
}
static int T_4 F_21 ( char * V_28 )
{
if ( ! strcmp ( V_28 , L_6 ) )
V_29 = 1 ;
else if ( ! strcmp ( V_28 , L_7 ) )
V_29 = 0 ;
else
F_22 ( L_8
L_9 ) ;
return 0 ;
}
void T_4 F_23 ( void )
{
F_24 ( V_30 ,
F_4 ( V_30 ) ) ;
}
static void T_4 F_25 ( void )
{
T_1 V_31 = V_32 ;
T_1 V_33 = F_26 ( V_34 ,
V_35 | V_36 ) ;
F_27 () ;
#if F_28 ( V_37 )
V_38 = V_39 ;
#endif
F_23 () ;
F_29 ( 0 , & V_40 ) ;
F_29 ( 1 , NULL ) ;
F_29 ( 2 , & V_40 ) ;
F_12 () ;
F_30 ( NULL ) ;
F_2 ( V_33 ) ;
F_31 ( & V_41 ) ;
F_32 ( 0 , & V_42 ) ;
F_32 ( 1 , & V_42 ) ;
F_33 ( & V_43 ) ;
if ( V_29 )
F_34 ( & V_44 ) ;
else {
F_13 ( NULL ) ;
F_35 ( & V_45 ) ;
}
F_1 () ;
F_36 ( 1 , & V_46 ) ;
F_2 ( V_31 ) ;
F_9 () ;
F_37 ( 0 , & V_47 ) ;
F_37 ( 1 , & V_48 ) ;
F_38 ( V_49 ,
F_4 ( V_49 ) ) ;
F_39 ( 0 , & V_50 ) ;
F_40 ( 0 , NULL ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
