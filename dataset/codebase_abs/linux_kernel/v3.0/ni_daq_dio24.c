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
F_4 ( L_2 , V_2 -> V_21 ,
V_13 -> V_22 , V_7 ) ;
#ifdef F_2
if ( V_8 ) {
F_4 ( L_3 , V_8 ) ;
}
#endif
F_4 ( L_4 ) ;
if ( V_7 == 0 ) {
F_4 ( L_5 ) ;
return - V_20 ;
}
V_2 -> V_7 = V_7 ;
#ifdef F_2
V_2 -> V_8 = V_8 ;
#endif
V_2 -> V_23 = V_13 -> V_22 ;
if ( F_5 ( V_2 , 1 ) < 0 )
return - V_12 ;
V_6 = V_2 -> V_24 + 0 ;
F_6 ( V_2 , V_6 , NULL , V_2 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_4 ( L_6 , V_2 -> V_21 ) ;
if ( V_2 -> V_24 )
F_8 ( V_2 , V_2 -> V_24 + 0 ) ;
if ( V_13 -> V_14 != V_15 && V_2 -> V_7 )
F_9 ( V_2 -> V_7 , V_25 ) ;
if ( V_2 -> V_8 )
F_10 ( V_2 -> V_8 , V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_26 * V_27 ;
F_4 ( V_28 L_7 ) ;
F_12 ( & V_10 -> V_2 , L_8 ) ;
V_27 = F_13 ( sizeof( struct V_26 ) , V_29 ) ;
if ( ! V_27 )
return - V_12 ;
V_27 -> V_10 = V_10 ;
V_10 -> V_30 = V_27 ;
V_16 = V_10 ;
F_14 ( V_10 ) ;
return 0 ;
}
static void F_15 ( struct V_9 * V_10 )
{
F_4 ( V_28 L_9 ) ;
F_12 ( & V_10 -> V_2 , L_10 ) ;
( (struct V_26 * ) V_10 -> V_30 ) -> V_31 = 1 ;
F_16 ( V_10 ) ;
F_17 ( V_10 -> V_30 ) ;
}
static int F_18 ( struct V_9 * V_32 ,
void * V_33 )
{
if ( V_32 -> V_34 == 0 )
return - V_20 ;
return F_19 ( V_32 ) ;
}
static void F_14 ( struct V_9 * V_10 )
{
int V_35 ;
F_4 ( V_28 L_11 ) ;
F_12 ( & V_10 -> V_2 , L_12 ) ;
V_10 -> V_36 |= V_37 | V_38 |
V_39 ;
V_35 = F_20 ( V_10 , F_18 , NULL ) ;
if ( V_35 ) {
F_21 ( & V_10 -> V_2 , L_13 ) ;
goto V_40;
}
if ( ! V_10 -> V_8 )
goto V_40;
V_35 = F_22 ( V_10 ) ;
if ( V_35 )
goto V_40;
return;
V_40:
F_4 ( V_28 L_14 ) ;
F_16 ( V_10 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
F_12 ( & V_10 -> V_2 , L_15 ) ;
F_23 ( V_10 ) ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_30 ;
V_27 -> V_31 = 1 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_26 * V_27 = V_10 -> V_30 ;
V_27 -> V_31 = 0 ;
return 0 ;
}
static int T_1 F_26 ( void )
{
F_4 ( L_16 ) ;
F_27 ( & V_41 ) ;
return 0 ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_41 ) ;
}
int T_1 F_30 ( void )
{
int V_35 ;
V_35 = F_26 () ;
if ( V_35 < 0 )
return V_35 ;
return F_31 ( & V_42 ) ;
}
void T_2 F_32 ( void )
{
F_28 () ;
F_33 ( & V_42 ) ;
}
