static void T_1 F_1 ( void T_2 * V_1 , unsigned int V_2 )
{
if ( F_2 ( ! V_1 || V_2 == V_3 ) )
return;
F_3 ( 0 , V_1 + V_4 + V_5 ) ;
F_3 ( 0 , V_1 + V_6 + V_5 ) ;
F_4 ( V_1 + V_6 , L_1 ) ;
F_5 ( V_1 + V_4 , V_2 , L_2 ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( F_8 ( V_7 , V_8 ) ) ;
F_1 ( F_8 ( V_9 , V_8 ) , V_10 ) ;
}
static void T_1 F_9 ( void )
{
if ( V_11 -> V_12 )
V_11 -> V_12 () ;
F_10 ( F_11 () , 24000000 ) ;
}
static void T_1 F_12 ( void )
{
int V_13 ;
T_3 V_14 ;
V_11 = NULL ;
V_14 = F_13 ( V_15 )
& V_16 ;
for ( V_13 = 0 ; V_13 < F_14 ( V_17 ) && ! V_11 ; ++ V_13 )
if ( V_17 [ V_13 ] -> V_18 == V_14 )
V_11 = V_17 [ V_13 ] ;
if ( ! V_11 )
F_15 ( L_3
L_4 ,
V_14 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_19 , F_14 ( V_19 ) ) ;
F_18 ( F_8 ( V_20 , V_8 ) ) ;
F_12 () ;
V_11 -> V_21 () ;
}
static void T_1 F_19 ( void )
{
V_11 -> V_22 () ;
}
static void T_1 F_20 ( void )
{
int V_13 ;
F_21 ( 0 , V_23 ,
F_14 ( V_23 ) ) ;
F_22 ( & V_24 ) ;
F_22 ( & V_25 ) ;
F_22 ( & V_26 ) ;
F_22 ( & V_27 ) ;
F_22 ( & V_28 ) ;
F_22 ( & V_29 ) ;
F_22 ( & V_30 ) ;
F_22 ( & V_31 ) ;
F_22 ( & V_32 ) ;
F_22 ( & V_33 ) ;
F_22 ( & V_34 ) ;
for ( V_13 = 0 ; V_13 < F_14 ( V_35 ) ; V_13 ++ )
F_23 ( V_35 [ V_13 ] , & V_36 ) ;
V_37 = V_38 ;
V_11 -> V_39 () ;
}
static int T_1 F_24 ( unsigned long V_40 , const char * V_41 ,
int V_42 , void * V_43 )
{
const char * * V_44 = V_43 ;
if ( strcmp ( V_41 , L_5 ) != 0 )
return 0 ;
* V_44 = F_25 ( V_40 , L_6 , NULL ) ;
return 1 ;
}
void T_1 F_26 ( void )
{
const char * V_44 = NULL ;
F_27 ( F_24 , & V_44 ) ;
if ( V_44 && strcmp ( V_44 , L_7 ) == 0 )
F_17 ( & V_45 , 1 ) ;
else
F_17 ( V_19 , F_14 ( V_19 ) ) ;
#if F_28 ( V_46 )
F_29 () ;
#endif
}
void T_1 F_30 ( void )
{
T_3 V_47 ;
F_31 () ;
if ( F_32 ( V_48 , L_8 , & V_47 ) == 0 ) {
T_3 V_49 = F_33 ( V_15 ) ;
if ( F_2 ( V_47 != V_49 ) )
F_34 ( L_9
L_10 , V_47 , V_49 ) ;
}
}
static void T_1 F_35 ( void )
{
F_36 ( V_50 ) ;
}
static void T_1 F_37 ( void )
{
struct V_51 * V_40 = NULL ;
F_38 () ;
do {
V_40 = F_39 ( V_40 , NULL , L_11 ) ;
} while ( V_40 && F_40 ( V_40 ) != V_52 );
if ( V_40 ) {
F_41 ( L_12 ,
V_40 -> V_53 ) ;
F_1 ( F_42 ( V_40 , 0 ) ,
F_43 ( V_40 , 0 ) ) ;
}
if ( F_44 () != 0 )
F_45 () ;
if ( F_46 () != 0 )
F_10 ( F_11 () ,
24000000 ) ;
}
static void T_1 F_47 ( void )
{
F_48 ( 0x00400000 , 0xfe0fffff ) ;
F_49 ( NULL , V_54 , NULL , NULL ) ;
V_37 = V_38 ;
}
