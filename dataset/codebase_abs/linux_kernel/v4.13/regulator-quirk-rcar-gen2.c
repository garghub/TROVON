static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 ;
static bool V_9 ;
T_1 V_10 ;
if ( V_9 )
return 0 ;
V_10 = F_2 ( V_11 + V_12 ) ;
F_3 ( V_6 , L_1 , V_13 , V_3 , V_10 ) ;
if ( V_10 & V_14 )
goto remove;
if ( V_3 != V_15 || V_6 -> type == & V_16 )
return 0 ;
V_8 = F_4 ( V_6 ) ;
F_3 ( V_6 , L_2 , V_8 -> V_17 ) ;
if ( ( V_8 -> V_18 == 0x58 && ! strcmp ( V_8 -> V_17 , L_3 ) ) ||
( V_8 -> V_18 == 0x68 && ! strcmp ( V_8 -> V_17 , L_4 ) ) ) {
int V_19 ;
F_5 ( & V_8 -> V_6 , L_5 ) ;
V_19 = F_6 ( V_8 -> V_20 , V_21 , F_7 ( V_21 ) ) ;
if ( V_19 != F_7 ( V_21 ) )
F_8 ( & V_8 -> V_6 , L_6 , V_19 ) ;
}
V_10 = F_2 ( V_11 + V_12 ) ;
if ( V_10 & V_14 )
goto remove;
return 0 ;
remove:
F_5 ( V_6 , L_7 ) ;
V_9 = true ;
F_9 ( V_11 ) ;
return 0 ;
}
static int T_2 F_10 ( void )
{
T_1 V_10 ;
if ( ! F_11 ( L_8 ) &&
! F_11 ( L_9 ) &&
! F_11 ( L_10 ) )
return - V_22 ;
V_11 = F_12 ( V_23 , V_24 ) ;
if ( ! V_11 )
return - V_25 ;
V_10 = F_2 ( V_11 + V_12 ) ;
if ( V_10 & V_14 ) {
F_13 ( L_11 ,
V_13 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
F_14 ( L_12 ) ;
F_15 ( & V_26 , & V_27 ) ;
return 0 ;
}
