static void F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
void T_1 * V_4 , unsigned int V_5 , int V_6 )
{
unsigned long V_7 = ( unsigned long ) V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 <= 7 ; V_8 ++ ) {
V_2 -> V_9 [ V_8 ] = V_7 ;
V_7 += V_5 ;
}
V_2 -> V_10 . V_11 = ( unsigned long ) V_4 ;
V_2 -> V_6 = V_6 ;
}
static int F_2 ( struct V_12 * V_13 , const struct V_14 * V_15 )
{
void T_1 * V_3 ;
struct V_16 * V_17 ;
int V_18 ;
struct V_1 V_2 , * V_19 [] = { & V_2 } ;
V_18 = F_3 ( V_13 ) ;
if ( V_18 )
goto V_20;
V_3 = F_4 ( V_13 , V_21 , 0 , 0 ) ;
if ( ! V_3 ) {
V_18 = - V_22 ;
goto V_23;
}
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
F_1 ( & V_2 , V_3 , V_3 + 0x818 , 1 << 6 , V_13 -> V_6 ) ;
V_2 . V_24 = & V_13 -> V_24 ;
V_18 = F_5 ( & V_25 , V_19 , 1 , & V_17 ) ;
if ( V_18 )
goto V_23;
F_6 ( V_13 , V_17 ) ;
goto V_20;
V_23:
F_7 ( V_13 ) ;
V_20:
return V_18 ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_9 ( V_13 ) ;
F_6 ( V_13 , NULL ) ;
F_10 ( V_17 ) ;
F_7 ( V_13 ) ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_26 ) ;
}
static void T_3 F_13 ( void )
{
F_14 ( & V_26 ) ;
}
