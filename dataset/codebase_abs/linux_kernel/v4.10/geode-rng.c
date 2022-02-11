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
struct V_10 * V_11 = NULL ;
const struct V_12 * V_13 ;
void T_2 * V_4 ;
unsigned long V_14 ;
F_6 (pdev) {
V_13 = F_7 ( V_15 , V_11 ) ;
if ( V_13 ) {
V_14 = F_8 ( V_11 , 0 ) ;
if ( V_14 == 0 )
return - V_16 ;
V_4 = F_9 ( & V_11 -> V_17 , V_14 , 0x58 ) ;
if ( ! V_4 )
return - V_18 ;
V_19 . V_5 = ( unsigned long ) V_4 ;
F_10 ( L_1 ) ;
return F_11 ( & V_11 -> V_17 , & V_19 ) ;
}
}
return - V_16 ;
}
static void T_4 F_12 ( void )
{
}
