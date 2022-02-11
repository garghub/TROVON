static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = V_9 ;
V_5 = F_2 ( V_2 , sizeof( struct V_10 ) ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( V_2 -> V_11 , L_1 , V_2 -> V_12 ) ;
if ( V_13 -> V_14 == V_15 ) {
if ( V_8 == NULL ) {
F_4 ( V_2 -> V_11 , L_2 ) ;
return - V_16 ;
}
V_6 = V_8 -> V_17 [ 0 ] -> V_18 ;
} else {
F_4 ( V_2 -> V_11 , L_3 ) ;
return - V_19 ;
}
return F_5 ( V_2 , V_6 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_20 * V_21 ;
F_7 ( & V_8 -> V_2 , L_4 ) ;
V_21 = F_8 ( sizeof( struct V_20 ) , V_22 ) ;
if ( ! V_21 )
return - V_23 ;
V_21 -> V_8 = V_8 ;
V_8 -> V_24 = V_21 ;
V_9 = V_8 ;
F_9 ( V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_7 ( & V_8 -> V_2 , L_5 ) ;
( (struct V_20 * ) V_8 -> V_24 ) -> V_25 = 1 ;
F_11 ( V_8 ) ;
F_12 ( V_8 -> V_24 ) ;
}
static int F_13 ( struct V_7 * V_26 ,
void * V_27 )
{
if ( V_26 -> V_28 == 0 )
return - V_19 ;
return F_14 ( V_26 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
int V_5 ;
F_7 ( & V_8 -> V_2 , L_6 ) ;
V_8 -> V_29 |= V_30 | V_31 ;
V_5 = F_15 ( V_8 , F_13 , NULL ) ;
if ( V_5 ) {
F_16 ( & V_8 -> V_2 , L_7 ) ;
goto V_32;
}
if ( ! V_8 -> V_33 )
goto V_32;
V_5 = F_17 ( V_8 ) ;
if ( V_5 )
goto V_32;
return;
V_32:
F_11 ( V_8 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
F_7 ( & V_8 -> V_2 , L_8 ) ;
F_18 ( V_8 ) ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_20 * V_21 = V_8 -> V_24 ;
V_21 -> V_25 = 1 ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_20 * V_21 = V_8 -> V_24 ;
V_21 -> V_25 = 0 ;
return 0 ;
}
static int T_1 F_21 ( void )
{
F_22 ( & V_34 ) ;
return 0 ;
}
static void T_2 F_23 ( void )
{
F_24 ( L_9 ) ;
F_25 ( & V_34 ) ;
}
static int T_1 F_26 ( void )
{
int V_5 ;
V_5 = F_21 () ;
if ( V_5 < 0 )
return V_5 ;
return F_27 ( & V_35 ) ;
}
static void T_2 F_28 ( void )
{
F_23 () ;
F_29 ( & V_35 ) ;
}
