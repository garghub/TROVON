static int F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
int V_6 , V_7 ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
V_6 = ( F_2 ( V_4 + V_8 )
& V_9 ) ? 1 : 0 ;
if ( V_6 || ! V_3 )
break;
F_3 ( 10 ) ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_6 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
* V_6 = F_2 ( V_4 + V_10 ) ;
return 4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
T_2 V_11 ;
V_11 = V_12 | V_13 | V_14 ;
F_6 ( V_4 + V_8 , V_11 ) ;
F_6 ( V_4 + V_8 , V_11 & ~ V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
T_2 V_11 ;
V_11 = V_15 | V_16 ;
F_6 ( V_4 + V_8 ,
F_2 ( V_4 + V_8 ) & ~ V_11 ) ;
}
static int F_8 ( struct V_17 * V_18 )
{
void T_1 * V_4 ;
struct V_19 * V_20 ;
V_20 = F_9 ( V_18 , V_21 , 0 ) ;
V_4 = F_10 ( & V_18 -> V_22 , V_20 ) ;
if ( F_11 ( V_4 ) )
return F_12 ( V_4 ) ;
V_23 . V_5 = ( unsigned long ) V_4 ;
F_13 ( L_1 ) ;
return F_14 ( & V_18 -> V_22 , & V_23 ) ;
}
