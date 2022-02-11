static int F_1 ( void )
{
T_1 V_1 = V_2 ;
T_1 V_3 = V_4 ;
int V_5 ;
F_2 ( V_1 ) ;
V_5 = F_3 ( V_6 , L_1 ) ;
if ( V_5 ) {
F_4 ( L_2 , V_5 ) ;
return V_5 ;
}
F_5 ( V_6 , 0 ) ;
F_6 ( V_6 , 1 ) ;
F_7 ( 100 ) ;
F_8 ( V_6 ) ;
F_2 ( V_3 ) ;
V_5 = F_3 ( V_7 , L_3 ) ;
if ( V_5 ) {
F_4 ( L_4 , V_5 ) ;
return V_5 ;
}
F_5 ( V_7 , 1 ) ;
return 0 ;
}
static inline void F_9 ( void )
{
int V_5 ;
V_5 = F_10 ( V_8 ,
V_9 , L_5 ) ;
if ( V_5 ) {
F_11 ( V_10 L_6 , V_5 ) ;
return;
}
F_7 ( 2 ) ;
F_6 ( V_8 , 1 ) ;
}
static inline void F_12 ( void )
{
int V_5 ;
V_5 = F_10 ( V_11 ,
V_9 , L_7 ) ;
if ( V_5 ) {
F_11 ( V_10 L_8 , V_5 ) ;
return;
}
F_7 ( 1 ) ;
F_6 ( V_11 , 1 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
T_2 V_14 ;
void T_3 * V_15 ;
void T_3 * V_16 ;
V_15 = F_14 ( V_17 , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_16 = V_15 + V_20 ;
V_14 = F_15 ( V_16 + V_21 ) ;
V_14 &= ~ V_22 ;
V_14 |= V_23 ;
F_16 ( V_14 , V_16 + V_21 ) ;
F_17 ( V_15 ) ;
F_18 ( 10 ) ;
return F_19 ( 0 , V_24 ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
T_2 V_14 ;
void T_3 * V_15 ;
void T_3 * V_16 ;
V_15 = F_14 ( V_17 , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_16 = V_15 + V_20 ;
V_14 = F_15 ( V_16 + V_25 ) ;
F_16 ( V_14 | V_26 , V_16 + V_25 ) ;
F_17 ( V_15 ) ;
F_18 ( 10 ) ;
return F_19 ( 1 , V_27 |
V_28 ) ;
}
static int T_4 F_21 ( char * V_29 )
{
if ( ! strcmp ( V_29 , L_9 ) )
V_30 = 1 ;
else if ( ! strcmp ( V_29 , L_10 ) )
V_30 = 0 ;
else
F_22 ( L_11
L_12 ) ;
return 0 ;
}
static void T_4 F_23 ( void )
{
T_1 V_31 = V_32 ;
T_1 V_33 = V_34 |
F_24 ( V_35 | V_36 | V_37 ) ;
#if F_25 ( V_38 )
V_39 = V_40 ;
#endif
F_26 ( V_41 ,
F_27 ( V_41 ) ) ;
F_28 ( 0 , & V_42 ) ;
F_28 ( 1 , & V_42 ) ;
F_28 ( 2 , & V_42 ) ;
F_12 () ;
F_29 ( NULL ) ;
F_2 ( V_33 ) ;
F_30 ( & V_43 ) ;
F_31 ( 0 , & V_44 ) ;
F_31 ( 1 , & V_44 ) ;
F_32 ( & V_45 , & V_46 ) ;
if ( V_30 )
F_32 ( & V_47 , & V_48 ) ;
else {
F_13 ( NULL ) ;
F_32 ( & V_49 , & V_50 ) ;
}
F_1 () ;
F_32 ( & V_51 , & V_52 ) ;
F_2 ( V_31 ) ;
F_9 () ;
F_33 ( 0 , NULL ) ;
F_33 ( 1 , NULL ) ;
F_34 ( V_53 ,
F_27 ( V_53 ) ) ;
F_35 ( 0 , & V_54 ) ;
F_36 ( 0 , NULL ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
