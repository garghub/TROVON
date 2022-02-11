static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 = 0 ;
#ifdef F_2
unsigned int V_8 = 0 ;
#endif
struct V_9 * V_10 ;
int V_11 ;
if ( F_3 ( V_2 , sizeof( struct V_12 ) ) < 0 )
return - V_13 ;
switch ( V_14 -> V_15 ) {
case V_16 :
V_10 = V_17 ;
if ( ! V_10 )
return - V_18 ;
V_7 = V_10 -> V_19 [ 0 ] -> V_20 ;
#ifdef F_2
V_8 = V_10 -> V_8 ;
#endif
break;
default:
F_4 ( L_1 ) ;
return - V_21 ;
break;
}
F_5 ( L_2 , V_2 -> V_22 ,
V_14 -> V_23 , V_7 ) ;
#ifdef F_2
if ( V_8 )
F_5 ( L_3 , V_8 ) ;
#endif
if ( V_7 == 0 ) {
F_4 ( L_4 ) ;
return - V_21 ;
}
V_2 -> V_7 = V_7 ;
#ifdef F_2
V_2 -> V_8 = V_8 ;
#endif
V_2 -> V_24 = V_14 -> V_23 ;
V_11 = F_6 ( V_2 , 1 ) ;
if ( V_11 )
return V_11 ;
V_6 = V_2 -> V_25 + 0 ;
F_7 ( V_2 , V_6 , NULL , V_2 -> V_7 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 )
F_9 ( V_2 , V_2 -> V_25 + 0 ) ;
if ( V_14 -> V_15 != V_16 && V_2 -> V_7 )
F_10 ( V_2 -> V_7 , V_26 ) ;
if ( V_2 -> V_8 )
F_11 ( V_2 -> V_8 , V_2 ) ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_27 * V_28 ;
F_13 ( V_29 L_5 ) ;
F_14 ( & V_10 -> V_2 , L_6 ) ;
V_28 = F_15 ( sizeof( struct V_27 ) , V_30 ) ;
if ( ! V_28 )
return - V_13 ;
V_28 -> V_10 = V_10 ;
V_10 -> V_31 = V_28 ;
V_17 = V_10 ;
F_16 ( V_10 ) ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 )
{
( (struct V_27 * ) V_10 -> V_31 ) -> V_32 = 1 ;
F_18 ( V_10 ) ;
F_19 ( V_10 -> V_31 ) ;
}
static int F_20 ( struct V_9 * V_33 ,
void * V_34 )
{
if ( V_33 -> V_35 == 0 )
return - V_21 ;
return F_21 ( V_33 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
int V_11 ;
F_13 ( V_29 L_7 ) ;
F_14 ( & V_10 -> V_2 , L_8 ) ;
V_10 -> V_36 |= V_37 | V_38 |
V_39 ;
V_11 = F_22 ( V_10 , F_20 , NULL ) ;
if ( V_11 ) {
F_23 ( & V_10 -> V_2 , L_9 ) ;
goto V_40;
}
if ( ! V_10 -> V_8 )
goto V_40;
V_11 = F_24 ( V_10 ) ;
if ( V_11 )
goto V_40;
return;
V_40:
F_13 ( V_29 L_10 ) ;
F_18 ( V_10 ) ;
}
static void F_18 ( struct V_9 * V_10 )
{
F_14 ( & V_10 -> V_2 , L_11 ) ;
F_25 ( V_10 ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
struct V_27 * V_28 = V_10 -> V_31 ;
V_28 -> V_32 = 1 ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_27 * V_28 = V_10 -> V_31 ;
V_28 -> V_32 = 0 ;
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
int V_11 ;
V_11 = F_28 () ;
if ( V_11 < 0 )
return V_11 ;
return F_33 ( & V_42 ) ;
}
void T_2 F_34 ( void )
{
F_30 () ;
F_35 ( & V_42 ) ;
}
