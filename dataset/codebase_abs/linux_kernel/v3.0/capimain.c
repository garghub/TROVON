static char * F_1 ( const char * V_1 )
{
char * V_2 ;
char * V_3 ;
if ( ( V_3 = strchr ( V_1 , ':' ) ) ) {
V_2 = V_3 + 2 ;
V_3 = strchr ( V_2 , '$' ) ;
* -- V_3 = 0 ;
} else
V_2 = L_1 ;
return V_2 ;
}
T_1 * F_2 ( unsigned long V_4 ,
void * * V_5 )
{
T_1 * V_6 = F_3 ( V_4 , V_7 ) ;
if ( V_6 ) {
* V_5 = F_4 ( V_6 , V_4 ) ;
}
return ( V_6 ) ;
}
void F_5 ( T_1 * V_6 )
{
F_6 ( V_6 ) ;
}
static int F_7 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = V_9 -> V_13 ;
T_2 * V_14 = ( T_2 * ) V_12 -> V_15 ;
F_8 ( V_9 , L_2 , V_12 -> V_16 ) ;
F_8 ( V_9 , L_3 , V_12 -> V_17 ) ;
F_8 ( V_9 , L_4 , V_14 -> V_18 ) ;
F_8 ( V_9 , L_5 , V_14 -> V_19 . V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_10 ( V_22 , F_7 , NULL ) ;
}
void F_11 ( struct V_11 * V_12 )
{
V_12 -> V_23 = V_24 ;
V_12 -> V_25 = NULL ;
V_12 -> V_26 = NULL ;
V_12 -> V_27 = & V_28 ;
V_12 -> V_29 = V_30 ;
}
static int T_3 F_12 ( void )
{
char V_31 [ 32 ] ;
int V_32 = 0 ;
sprintf ( V_33 , L_6 , V_34 , V_35 ,
V_36 ) ;
F_13 ( V_37 L_2 , V_38 ) ;
F_13 ( V_37 L_7 , V_24 , V_33 ) ;
strcpy ( V_31 , V_39 ) ;
F_13 ( L_8 , F_1 ( V_31 ) ,
V_40 , V_41 ) ;
if ( ! ( F_14 () ) ) {
F_13 ( V_42 L_9 ,
V_24 ) ;
V_32 = - V_43 ;
}
return V_32 ;
}
static void T_4 F_15 ( void )
{
F_16 () ;
F_13 ( V_37 L_10 , V_24 ) ;
}
