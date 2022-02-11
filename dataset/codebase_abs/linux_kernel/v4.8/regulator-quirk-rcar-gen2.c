static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_10 + V_11 ) ;
F_3 ( V_6 , L_1 , V_12 , V_3 , V_9 ) ;
if ( V_9 & V_13 )
goto remove;
if ( V_3 != V_14 || V_6 -> type == & V_15 )
return 0 ;
V_8 = F_4 ( V_6 ) ;
F_3 ( V_6 , L_2 , V_8 -> V_16 ) ;
if ( ( V_8 -> V_17 == 0x58 && ! strcmp ( V_8 -> V_16 , L_3 ) ) ||
( V_8 -> V_17 == 0x68 && ! strcmp ( V_8 -> V_16 , L_4 ) ) ) {
int V_18 ;
F_5 ( & V_8 -> V_6 , L_5 ) ;
V_18 = F_6 ( V_8 -> V_19 , V_20 , F_7 ( V_20 ) ) ;
if ( V_18 != F_7 ( V_20 ) )
F_8 ( & V_8 -> V_6 , L_6 , V_18 ) ;
}
V_9 = F_2 ( V_10 + V_11 ) ;
if ( V_9 & V_13 )
goto remove;
return 0 ;
remove:
F_5 ( V_6 , L_7 ) ;
F_9 ( & V_21 , V_2 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
static int T_2 F_11 ( void )
{
T_1 V_9 ;
if ( ! F_12 ( L_8 ) &&
! F_12 ( L_9 ) &&
! F_12 ( L_10 ) )
return - V_22 ;
V_10 = F_13 ( V_23 , V_24 ) ;
if ( ! V_10 )
return - V_25 ;
V_9 = F_2 ( V_10 + V_11 ) ;
if ( V_9 & V_13 ) {
F_14 ( L_11 ,
V_12 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
F_15 ( L_12 ) ;
F_16 ( & V_21 , & V_26 ) ;
return 0 ;
}
