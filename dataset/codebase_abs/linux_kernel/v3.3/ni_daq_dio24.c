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
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_25 , L_5 , V_2 -> V_21 ) ;
if ( V_2 -> V_24 )
F_10 ( V_2 , V_2 -> V_24 + 0 ) ;
if ( V_13 -> V_14 != V_15 && V_2 -> V_7 )
F_11 ( V_2 -> V_7 , V_26 ) ;
if ( V_2 -> V_8 )
F_12 ( V_2 -> V_8 , V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_27 * V_28 ;
F_14 ( V_29 L_6 ) ;
F_15 ( & V_10 -> V_2 , L_7 ) ;
V_28 = F_16 ( sizeof( struct V_27 ) , V_30 ) ;
if ( ! V_28 )
return - V_12 ;
V_28 -> V_10 = V_10 ;
V_10 -> V_31 = V_28 ;
V_16 = V_10 ;
F_17 ( V_10 ) ;
return 0 ;
}
static void F_18 ( struct V_9 * V_10 )
{
F_14 ( V_29 L_8 ) ;
F_15 ( & V_10 -> V_2 , L_9 ) ;
( (struct V_27 * ) V_10 -> V_31 ) -> V_32 = 1 ;
F_19 ( V_10 ) ;
F_20 ( V_10 -> V_31 ) ;
}
static int F_21 ( struct V_9 * V_33 ,
void * V_34 )
{
if ( V_33 -> V_35 == 0 )
return - V_20 ;
return F_22 ( V_33 ) ;
}
static void F_17 ( struct V_9 * V_10 )
{
int V_36 ;
F_14 ( V_29 L_10 ) ;
F_15 ( & V_10 -> V_2 , L_11 ) ;
V_10 -> V_37 |= V_38 | V_39 |
V_40 ;
V_36 = F_23 ( V_10 , F_21 , NULL ) ;
if ( V_36 ) {
F_24 ( & V_10 -> V_2 , L_12 ) ;
goto V_41;
}
if ( ! V_10 -> V_8 )
goto V_41;
V_36 = F_25 ( V_10 ) ;
if ( V_36 )
goto V_41;
return;
V_41:
F_14 ( V_29 L_13 ) ;
F_19 ( V_10 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
F_15 ( & V_10 -> V_2 , L_14 ) ;
F_26 ( V_10 ) ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_27 * V_28 = V_10 -> V_31 ;
V_28 -> V_32 = 1 ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_27 * V_28 = V_10 -> V_31 ;
V_28 -> V_32 = 0 ;
return 0 ;
}
static int T_1 F_29 ( void )
{
F_14 ( L_15 ) ;
F_30 ( & V_42 ) ;
return 0 ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_42 ) ;
}
int T_1 F_33 ( void )
{
int V_36 ;
V_36 = F_29 () ;
if ( V_36 < 0 )
return V_36 ;
return F_34 ( & V_43 ) ;
}
void T_2 F_35 ( void )
{
F_31 () ;
F_36 ( & V_43 ) ;
}
