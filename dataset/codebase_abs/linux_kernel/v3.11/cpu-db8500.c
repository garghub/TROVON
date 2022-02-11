void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 () ;
F_2 ( V_2 , F_3 ( V_2 ) ) ;
if ( F_5 () )
F_2 ( V_3 , F_3 ( V_3 ) ) ;
else
F_2 ( V_4 , F_3 ( V_4 ) ) ;
}
static T_2 F_6 ( int V_5 , void * V_6 , T_3 V_7 )
{
T_2 V_8 = V_7 ( V_5 , V_6 ) ;
int V_9 = ! F_7 () ;
if ( V_8 == V_10 && F_8 ( V_9 ) )
F_9 ( V_5 , F_10 ( V_9 ) ) ;
return V_8 ;
}
static void T_1 F_11 ( struct V_11 * V_12 )
{
struct V_13 V_14 = {
. V_15 = true ,
} ;
F_12 ( V_12 , F_13 ( V_16 ) ,
V_17 , & V_14 ) ;
F_14 ( V_12 , L_1 , V_18 ) ;
}
static const char * F_15 ( void )
{
void T_4 * V_19 = F_16 ( V_20 ) ;
F_17 ( V_19 , 0x14 ) ;
return F_18 ( V_21 , L_2 ,
F_19 ( ( V_22 * ) V_19 + 0 ) ,
F_19 ( ( V_22 * ) V_19 + 1 ) , F_19 ( ( V_22 * ) V_19 + 2 ) ,
F_19 ( ( V_22 * ) V_19 + 3 ) , F_19 ( ( V_22 * ) V_19 + 4 ) ) ;
}
static struct V_11 * T_1 F_20 ( void )
{
const char * V_23 = F_15 () ;
return F_21 ( V_23 ) ;
}
struct V_11 * T_1 F_22 ( void )
{
struct V_11 * V_12 ;
int V_24 ;
V_12 = F_20 () ;
F_23 ( V_12 ) ;
F_11 ( V_12 ) ;
F_24 ( V_12 , V_25 , V_25 ) ;
for ( V_24 = 0 ; V_24 < F_3 ( V_26 ) ; V_24 ++ )
V_26 [ V_24 ] -> V_6 . V_12 = V_12 ;
F_25 ( V_26 , F_3 ( V_26 ) ) ;
return V_12 ;
}
static void T_1 F_26 ( void )
{
struct V_11 * V_12 = F_20 () ;
if ( F_27 ( L_3 ) )
F_28 () ;
else if ( F_27 ( L_4 ) ) {
F_29 () ;
} else if ( F_27 ( L_5 ) )
F_30 () ;
else if ( F_27 ( L_6 ) ) {}
if ( F_27 ( L_7 ) )
F_31 ( NULL , V_27 ,
V_28 , V_12 ) ;
else
F_31 ( NULL , V_27 ,
V_29 , V_12 ) ;
}
