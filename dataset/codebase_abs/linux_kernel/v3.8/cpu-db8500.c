void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 () ;
F_2 ( V_2 , F_3 ( V_2 ) ) ;
if ( F_5 () )
F_2 ( V_3 , F_3 ( V_3 ) ) ;
else
F_2 ( V_4 , F_3 ( V_4 ) ) ;
V_5 = F_6 ( V_6 ) ;
}
static T_2 F_7 ( int V_7 , void * V_8 , T_3 V_9 )
{
T_2 V_10 = V_9 ( V_7 , V_8 ) ;
int V_11 = ! F_8 () ;
if ( V_10 == V_12 && F_9 ( V_11 ) )
F_10 ( V_7 , F_11 ( V_11 ) ) ;
return V_10 ;
}
static void T_1 F_12 ( struct V_13 * V_14 )
{
struct V_15 V_16 = {
. V_17 = true ,
} ;
F_13 ( V_14 , F_14 ( V_18 ) ,
V_19 , & V_16 ) ;
F_15 ( V_14 , L_1 , V_6 ) ;
}
static const char * F_16 ( void )
{
void T_4 * V_20 = F_6 ( V_21 ) ;
F_17 ( V_20 , 0x14 ) ;
return F_18 ( V_22 , L_2 ,
F_19 ( ( V_23 * ) V_20 + 1 ) ,
F_19 ( ( V_23 * ) V_20 + 1 ) , F_19 ( ( V_23 * ) V_20 + 2 ) ,
F_19 ( ( V_23 * ) V_20 + 3 ) , F_19 ( ( V_23 * ) V_20 + 4 ) ) ;
}
static struct V_13 * T_1 F_20 ( void )
{
const char * V_24 = F_16 () ;
return F_21 ( V_24 ) ;
}
struct V_13 * T_1 F_22 ( struct V_25 * V_26 )
{
struct V_13 * V_14 ;
int V_27 ;
V_14 = F_20 () ;
F_23 ( V_14 ) ;
F_12 ( V_14 ) ;
F_24 ( V_14 , V_28 , V_29 ) ;
for ( V_27 = 0 ; V_27 < F_3 ( V_30 ) ; V_27 ++ )
V_30 [ V_27 ] -> V_8 . V_14 = V_14 ;
V_31 . V_8 . V_32 = V_26 ;
F_25 ( V_30 , F_3 ( V_30 ) ) ;
return V_14 ;
}
static struct V_13 * T_1 F_26 ( void )
{
struct V_13 * V_14 = F_20 () ;
F_24 ( V_14 , V_28 , V_29 ) ;
V_33 . V_8 . V_14 = V_14 ;
F_27 ( & V_33 ) ;
return V_14 ;
}
static void T_1 F_28 ( void )
{
struct V_13 * V_14 = NULL ;
if ( F_29 ( L_3 ) )
F_30 () ;
else if ( F_29 ( L_4 ) )
F_31 () ;
else if ( F_29 ( L_5 ) )
F_32 () ;
else if ( F_29 ( L_6 ) ) {}
V_14 = F_26 () ;
F_33 ( NULL , V_34 , V_35 , V_14 ) ;
}
