static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 = 0 ;
#ifdef F_2
unsigned int V_8 = 0 ;
#endif
struct V_9 * V_10 ;
if ( F_3 ( V_2 , sizeof( struct V_11 ) ) < 0 )
return - V_12 ;
switch ( V_13 -> V_14 ) {
case V_15 :
V_10 = V_16 ;
if ( ! V_10 )
return - V_17 ;
V_7 = V_10 -> V_18 [ 0 ] -> V_19 ;
#ifdef F_2
V_8 = V_10 -> V_8 ;
#endif
break;
default:
F_4 ( L_1 ) ;
return - V_20 ;
break;
}
F_5 ( L_2 , V_2 -> V_21 ,
V_13 -> V_22 , V_7 ) ;
#ifdef F_2
if ( V_8 )
F_5 ( L_3 , V_8 ) ;
#endif
if ( V_7 == 0 ) {
F_4 ( L_4 ) ;
return - V_20 ;
}
V_2 -> V_7 = V_7 ;
#ifdef F_2
V_2 -> V_8 = V_8 ;
#endif
V_2 -> V_23 = V_13 -> V_22 ;
if ( F_6 ( V_2 , 1 ) < 0 )
return - V_12 ;
V_6 = V_2 -> V_24 + 0 ;
F_7 ( V_2 , V_6 , NULL , V_2 -> V_7 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 )
F_9 ( V_2 , V_2 -> V_24 + 0 ) ;
if ( V_13 -> V_14 != V_15 && V_2 -> V_7 )
F_10 ( V_2 -> V_7 , V_25 ) ;
if ( V_2 -> V_8 )
F_11 ( V_2 -> V_8 , V_2 ) ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_26 * V_27 ;
F_13 ( V_28 L_5 ) ;
F_14 ( & V_10 -> V_2 , L_6 ) ;
V_27 = F_15 ( sizeof( struct V_26 ) , V_29 ) ;
if ( ! V_27 )
return - V_12 ;
V_27 -> V_10 = V_10 ;
V_10 -> V_30 = V_27 ;
V_16 = V_10 ;
F_16 ( V_10 ) ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 )
{
( (struct V_26 * ) V_10 -> V_30 ) -> V_31 = 1 ;
F_18 ( V_10 ) ;
F_19 ( V_10 -> V_30 ) ;
}
static int F_20 ( struct V_9 * V_32 ,
void * V_33 )
{
if ( V_32 -> V_34 == 0 )
return - V_20 ;
return F_21 ( V_32 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
int V_35 ;
F_13 ( V_28 L_7 ) ;
F_14 ( & V_10 -> V_2 , L_8 ) ;
V_10 -> V_36 |= V_37 | V_38 |
V_39 ;
V_35 = F_22 ( V_10 , F_20 , NULL ) ;
if ( V_35 ) {
F_23 ( & V_10 -> V_2 , L_9 ) ;
goto V_40;
}
if ( ! V_10 -> V_8 )
goto V_40;
V_35 = F_24 ( V_10 ) ;
if ( V_35 )
goto V_40;
return;
V_40:
F_13 ( V_28 L_10 ) ;
F_18 ( V_10 ) ;
}
static void F_18 ( struct V_9 * V_10 )
{
F_14 ( & V_10 -> V_2 , L_11 ) ;
F_25 ( V_10 ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_30 ;
V_27 -> V_31 = 1 ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_30 ;
V_27 -> V_31 = 0 ;
return 0 ;
}
static int T_1 F_28 ( void )
{
F_13 ( L_12 ) ;
F_29 ( & V_41 ) ;
return 0 ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_41 ) ;
}
int T_1 F_32 ( void )
{
int V_35 ;
V_35 = F_28 () ;
if ( V_35 < 0 )
return V_35 ;
return F_33 ( & V_42 ) ;
}
void T_2 F_34 ( void )
{
F_30 () ;
F_35 ( & V_42 ) ;
}
