static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 = 0 ;
unsigned int V_6 = 0 ;
struct V_7 * V_8 ;
if ( F_2 ( V_2 , sizeof( struct V_9 ) ) < 0 )
return - V_10 ;
switch ( V_11 -> V_12 ) {
case V_13 :
V_8 = V_14 ;
if ( ! V_8 )
return - V_15 ;
V_5 = V_8 -> V_16 [ 0 ] -> V_17 ;
V_6 = V_8 -> V_6 ;
break;
default:
F_3 ( L_1 ) ;
return - V_18 ;
break;
}
return F_4 ( V_2 , V_5 , V_6 , 0 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
F_6 ( & V_8 -> V_2 , L_2 ) ;
V_20 = F_7 ( sizeof( struct V_19 ) , V_21 ) ;
if ( ! V_20 )
return - V_10 ;
V_20 -> V_8 = V_8 ;
V_8 -> V_22 = V_20 ;
V_14 = V_8 ;
F_8 ( V_8 ) ;
return 0 ;
}
static void F_9 ( struct V_7 * V_8 )
{
( (struct V_19 * ) V_8 -> V_22 ) -> V_23 = 1 ;
F_10 ( V_8 ) ;
F_11 ( V_8 -> V_22 ) ;
}
static int F_12 ( struct V_7 * V_24 ,
void * V_25 )
{
if ( V_24 -> V_26 == 0 )
return - V_18 ;
return F_13 ( V_24 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
int V_27 ;
F_6 ( & V_8 -> V_2 , L_3 ) ;
V_8 -> V_28 |= V_29 | V_30 |
V_31 | V_32 ;
V_27 = F_14 ( V_8 , F_12 , NULL ) ;
if ( V_27 ) {
F_15 ( & V_8 -> V_2 , L_4 ) ;
goto V_33;
}
if ( ! V_8 -> V_6 )
goto V_33;
V_27 = F_16 ( V_8 ) ;
if ( V_27 )
goto V_33;
return;
V_33:
F_10 ( V_8 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_2 , L_5 ) ;
F_17 ( V_8 ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = V_8 -> V_22 ;
V_20 -> V_23 = 1 ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = V_8 -> V_22 ;
V_20 -> V_23 = 0 ;
return 0 ;
}
static int T_1 F_20 ( void )
{
F_21 ( & V_34 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_34 ) ;
}
int T_1 F_24 ( void )
{
int V_27 ;
V_27 = F_20 () ;
if ( V_27 < 0 )
return V_27 ;
return F_25 ( & V_35 ) ;
}
void T_2 F_26 ( void )
{
F_22 () ;
F_27 ( & V_35 ) ;
}
