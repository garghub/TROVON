static void T_1 F_1 ( void T_2 * V_1 , unsigned int V_2 )
{
if ( F_2 ( ! V_1 || V_2 == V_3 ) )
return;
F_3 ( V_1 + V_4 , L_1 ) ;
F_4 ( V_1 + V_5 , V_2 , L_2 ) ;
}
static void T_1 F_5 ( void )
{
F_6 ( F_7 ( V_6 , V_7 ) ) ;
F_1 ( F_7 ( V_8 , V_7 ) , V_9 ) ;
}
static void T_1 F_8 ( void )
{
if ( V_10 -> V_11 )
V_10 -> V_11 () ;
F_9 ( F_10 () , 24000000 ) ;
}
static void T_1 F_11 ( void )
{
int V_12 ;
T_3 V_13 ;
V_10 = NULL ;
V_13 = F_12 ( V_14 )
& V_15 ;
for ( V_12 = 0 ; V_12 < F_13 ( V_16 ) && ! V_10 ; ++ V_12 )
if ( V_16 [ V_12 ] -> V_17 == V_13 )
V_10 = V_16 [ V_12 ] ;
if ( ! V_10 )
F_14 ( L_3
L_4 ,
V_13 ) ;
}
static void T_1 F_15 ( void )
{
F_16 ( V_18 , F_13 ( V_18 ) ) ;
F_17 ( F_7 ( V_19 , V_7 ) ) ;
F_11 () ;
V_10 -> V_20 () ;
}
static void T_1 F_18 ( void )
{
V_10 -> V_21 () ;
}
static void T_1 F_19 ( void )
{
int V_12 ;
F_20 ( 0 , V_22 ,
F_13 ( V_22 ) ) ;
F_21 ( & V_23 ) ;
F_21 ( & V_24 ) ;
F_21 ( & V_25 ) ;
F_21 ( & V_26 ) ;
F_21 ( & V_27 ) ;
F_21 ( & V_28 ) ;
F_21 ( & V_29 ) ;
F_21 ( & V_30 ) ;
F_21 ( & V_31 ) ;
F_21 ( & V_32 ) ;
F_21 ( & V_33 ) ;
for ( V_12 = 0 ; V_12 < F_13 ( V_34 ) ; V_12 ++ )
F_22 ( V_34 [ V_12 ] , & V_35 ) ;
V_10 -> V_36 () ;
}
static int T_1 F_23 ( unsigned long V_37 , const char * V_38 ,
int V_39 , void * V_40 )
{
const char * * V_41 = V_40 ;
if ( strcmp ( V_38 , L_5 ) != 0 )
return 0 ;
* V_41 = F_24 ( V_37 , L_6 , NULL ) ;
return 1 ;
}
void T_1 F_25 ( void )
{
const char * V_41 = NULL ;
F_26 ( F_23 , & V_41 ) ;
if ( V_41 && strcmp ( V_41 , L_7 ) == 0 )
F_16 ( & V_42 , 1 ) ;
else
F_16 ( V_18 , F_13 ( V_18 ) ) ;
#if F_27 ( V_43 )
F_28 () ;
#endif
}
void T_1 F_29 ( void )
{
T_3 V_44 ;
F_30 () ;
if ( F_31 ( V_45 , L_8 , & V_44 ) == 0 ) {
T_3 V_46 = F_32 ( V_14 ) ;
if ( F_2 ( V_44 != V_46 ) )
F_33 ( L_9
L_10 , V_44 , V_46 ) ;
}
F_9 ( F_10 () , 24000000 ) ;
}
static void T_1 F_34 ( void )
{
F_35 ( 0x00400000 , 0xfe0fffff ) ;
F_36 ( NULL , V_47 , NULL , NULL ) ;
}
