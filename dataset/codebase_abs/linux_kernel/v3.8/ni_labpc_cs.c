static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 = 0 ;
unsigned int V_8 = 0 ;
struct V_9 * V_10 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_2 -> V_13 = V_6 ;
switch ( V_14 -> V_15 ) {
case V_16 :
V_10 = V_17 ;
if ( ! V_10 )
return - V_18 ;
V_7 = V_10 -> V_19 [ 0 ] -> V_20 ;
V_8 = V_10 -> V_8 ;
break;
default:
F_3 ( L_1 ) ;
return - V_21 ;
break;
}
return F_4 ( V_2 , V_7 , V_8 , 0 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_22 * V_23 ;
F_6 ( & V_10 -> V_2 , L_2 ) ;
V_23 = F_2 ( sizeof( struct V_22 ) , V_11 ) ;
if ( ! V_23 )
return - V_12 ;
V_23 -> V_10 = V_10 ;
V_10 -> V_24 = V_23 ;
V_17 = V_10 ;
F_7 ( V_10 ) ;
return 0 ;
}
static void F_8 ( struct V_9 * V_10 )
{
( (struct V_22 * ) V_10 -> V_24 ) -> V_25 = 1 ;
F_9 ( V_10 ) ;
F_10 ( V_10 -> V_24 ) ;
}
static int F_11 ( struct V_9 * V_26 ,
void * V_27 )
{
if ( V_26 -> V_28 == 0 )
return - V_21 ;
return F_12 ( V_26 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
int V_29 ;
F_6 ( & V_10 -> V_2 , L_3 ) ;
V_10 -> V_30 |= V_31 | V_32 |
V_33 | V_34 ;
V_29 = F_13 ( V_10 , F_11 , NULL ) ;
if ( V_29 ) {
F_14 ( & V_10 -> V_2 , L_4 ) ;
goto V_35;
}
if ( ! V_10 -> V_8 )
goto V_35;
V_29 = F_15 ( V_10 ) ;
if ( V_29 )
goto V_35;
return;
V_35:
F_9 ( V_10 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
F_6 ( & V_10 -> V_2 , L_5 ) ;
F_16 ( V_10 ) ;
}
static int F_17 ( struct V_9 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_24 ;
V_23 -> V_25 = 1 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_24 ;
V_23 -> V_25 = 0 ;
return 0 ;
}
static int T_1 F_19 ( void )
{
F_20 ( & V_36 ) ;
return 0 ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_36 ) ;
}
static int T_1 F_23 ( void )
{
int V_29 ;
V_29 = F_19 () ;
if ( V_29 < 0 )
return V_29 ;
return F_24 ( & V_37 ) ;
}
static void T_2 F_25 ( void )
{
F_21 () ;
F_26 ( & V_37 ) ;
}
