static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = V_9 ;
V_5 = F_2 ( V_2 , sizeof( struct V_10 ) ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( L_1 , V_2 -> V_11 ) ;
if ( V_12 -> V_13 == V_14 ) {
if ( V_8 == NULL ) {
F_3 ( L_2 ) ;
return - V_15 ;
}
V_6 = V_8 -> V_16 [ 0 ] -> V_17 ;
} else {
F_3 ( L_3 ) ;
return - V_18 ;
}
F_3 ( L_4 ) ;
return F_4 ( V_2 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
F_6 ( & V_8 -> V_2 , L_5 ) ;
V_20 = F_7 ( sizeof( struct V_19 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_20 -> V_8 = V_8 ;
V_8 -> V_23 = V_20 ;
V_9 = V_8 ;
F_8 ( V_8 ) ;
return 0 ;
}
static void F_9 ( struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_2 , L_6 ) ;
( (struct V_19 * ) V_8 -> V_23 ) -> V_24 = 1 ;
F_10 ( V_8 ) ;
F_11 ( V_8 -> V_23 ) ;
}
static int F_12 ( struct V_7 * V_25 ,
void * V_26 )
{
if ( V_25 -> V_27 == 0 )
return - V_18 ;
return F_13 ( V_25 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
int V_5 ;
F_6 ( & V_8 -> V_2 , L_7 ) ;
V_8 -> V_28 |= V_29 | V_30 ;
V_5 = F_14 ( V_8 , F_12 , NULL ) ;
if ( V_5 ) {
F_15 ( & V_8 -> V_2 , L_8 ) ;
goto V_31;
}
if ( ! V_8 -> V_32 )
goto V_31;
V_5 = F_16 ( V_8 ) ;
if ( V_5 )
goto V_31;
return;
V_31:
F_10 ( V_8 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_2 , L_9 ) ;
F_17 ( V_8 ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = V_8 -> V_23 ;
V_20 -> V_24 = 1 ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = V_8 -> V_23 ;
V_20 -> V_24 = 0 ;
return 0 ;
}
static int T_1 F_20 ( void )
{
F_21 ( & V_33 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( L_10 ) ;
F_24 ( & V_33 ) ;
}
static int T_1 F_25 ( void )
{
int V_5 ;
V_5 = F_20 () ;
if ( V_5 < 0 )
return V_5 ;
return F_26 ( & V_34 ) ;
}
static void T_2 F_27 ( void )
{
F_22 () ;
F_28 ( & V_34 ) ;
}
