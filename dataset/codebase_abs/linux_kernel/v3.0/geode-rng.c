static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
void T_2 * V_4 = ( void T_2 * ) V_2 -> V_5 ;
* V_3 = F_2 ( V_4 + V_6 ) ;
return 4 ;
}
static int F_3 ( struct V_1 * V_2 , int V_7 )
{
void T_2 * V_4 = ( void T_2 * ) V_2 -> V_5 ;
int V_3 , V_8 ;
for ( V_8 = 0 ; V_8 < 20 ; V_8 ++ ) {
V_3 = ! ! ( F_2 ( V_4 + V_9 ) ) ;
if ( V_3 || ! V_7 )
break;
F_4 ( 10 ) ;
}
return V_3 ;
}
static int T_3 F_5 ( void )
{
int V_10 = - V_11 ;
struct V_12 * V_13 = NULL ;
const struct V_14 * V_15 ;
void T_2 * V_4 ;
unsigned long V_16 ;
F_6 (pdev) {
V_15 = F_7 ( V_17 , V_13 ) ;
if ( V_15 )
goto V_18;
}
goto V_19;
V_18:
V_16 = F_8 ( V_13 , 0 ) ;
if ( V_16 == 0 )
goto V_19;
V_10 = - V_20 ;
V_4 = F_9 ( V_16 , 0x58 ) ;
if ( ! V_4 )
goto V_19;
V_21 . V_5 = ( unsigned long ) V_4 ;
F_10 ( V_22 L_1 ) ;
V_10 = F_11 ( & V_21 ) ;
if ( V_10 ) {
F_10 (KERN_ERR PFX L_2 ,
err) ;
goto V_23;
}
V_19:
return V_10 ;
V_23:
F_12 ( V_4 ) ;
goto V_19;
}
static void T_4 F_13 ( void )
{
void T_2 * V_4 = ( void T_2 * ) V_21 . V_5 ;
F_14 ( & V_21 ) ;
F_12 ( V_4 ) ;
}
