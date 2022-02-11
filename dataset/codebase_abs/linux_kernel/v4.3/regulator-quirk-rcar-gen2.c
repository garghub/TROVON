static void F_1 ( struct V_1 * V_2 , const T_1 V_3 [] ,
unsigned int V_4 )
{
unsigned int V_5 ;
F_2 ( & V_2 -> V_6 , L_1 , V_2 -> V_7 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
int error = F_3 ( V_2 , V_3 [ V_5 ] , ~ 0 ) ;
if ( error ) {
F_4 ( & V_2 -> V_6 , L_2 , error ) ;
return;
}
}
}
static int F_5 ( struct V_8 * V_9 ,
unsigned long V_10 , void * V_11 )
{
struct V_12 * V_6 = V_11 ;
struct V_1 * V_2 ;
T_2 V_13 ;
V_13 = F_6 ( V_14 + V_15 ) ;
F_7 ( V_6 , L_3 , V_16 , V_10 , V_13 ) ;
if ( V_13 & V_17 )
goto remove;
if ( V_10 != V_18 || V_6 -> type == & V_19 )
return 0 ;
V_2 = F_8 ( V_6 ) ;
F_7 ( V_6 , L_4 , V_2 -> V_7 ) ;
if ( ( V_2 -> V_20 == 0x58 && ! strcmp ( V_2 -> V_7 , L_5 ) ) )
F_1 ( V_2 , V_21 ,
F_9 ( V_21 ) ) ;
else if ( V_2 -> V_20 == 0x68 && ! strcmp ( V_2 -> V_7 , L_6 ) )
F_1 ( V_2 , V_22 ,
F_9 ( V_22 ) ) ;
V_13 = F_6 ( V_14 + V_15 ) ;
if ( V_13 & V_17 )
goto remove;
return 0 ;
remove:
F_2 ( V_6 , L_7 ) ;
F_10 ( & V_23 , V_9 ) ;
F_11 ( V_14 ) ;
return 0 ;
}
static int T_3 F_12 ( void )
{
T_2 V_13 ;
if ( ! F_13 ( L_8 ) &&
! F_13 ( L_9 ) &&
! F_13 ( L_10 ) )
return - V_24 ;
V_14 = F_14 ( V_25 , V_26 ) ;
if ( ! V_14 )
return - V_27 ;
V_13 = F_6 ( V_14 + V_15 ) ;
if ( V_13 & V_17 ) {
F_15 ( L_11 ,
V_16 ) ;
F_11 ( V_14 ) ;
return 0 ;
}
F_16 ( L_12 ) ;
F_17 ( & V_23 , & V_28 ) ;
return 0 ;
}
