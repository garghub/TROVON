static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 = 0 ;
#ifdef F_2
unsigned int V_10 = 0 ;
#endif
struct V_11 * V_12 ;
int V_13 ;
V_6 = F_3 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 )
return - V_15 ;
V_2 -> V_16 = V_6 ;
switch ( V_17 -> V_18 ) {
case V_19 :
V_12 = V_20 ;
if ( ! V_12 )
return - V_21 ;
V_9 = V_12 -> V_22 [ 0 ] -> V_23 ;
#ifdef F_2
V_10 = V_12 -> V_10 ;
#endif
break;
default:
F_4 ( L_1 ) ;
return - V_24 ;
break;
}
F_5 ( L_2 , V_2 -> V_25 ,
V_17 -> V_26 , V_9 ) ;
#ifdef F_2
if ( V_10 )
F_5 ( L_3 , V_10 ) ;
#endif
if ( V_9 == 0 ) {
F_4 ( L_4 ) ;
return - V_24 ;
}
V_2 -> V_9 = V_9 ;
#ifdef F_2
V_2 -> V_10 = V_10 ;
#endif
V_2 -> V_27 = V_17 -> V_26 ;
V_13 = F_6 ( V_2 , 1 ) ;
if ( V_13 )
return V_13 ;
V_8 = & V_2 -> V_28 [ 0 ] ;
F_7 ( V_2 , V_8 , NULL , V_2 -> V_9 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_28 ) {
V_8 = & V_2 -> V_28 [ 0 ] ;
F_9 ( V_2 , V_8 ) ;
}
if ( V_17 -> V_18 != V_19 && V_2 -> V_9 )
F_10 ( V_2 -> V_9 , V_29 ) ;
if ( V_2 -> V_10 )
F_11 ( V_2 -> V_10 , V_2 ) ;
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_30 * V_31 ;
F_13 ( & V_12 -> V_2 , L_5 ) ;
F_14 ( & V_12 -> V_2 , L_6 ) ;
V_31 = F_3 ( sizeof( struct V_30 ) , V_14 ) ;
if ( ! V_31 )
return - V_15 ;
V_31 -> V_12 = V_12 ;
V_12 -> V_32 = V_31 ;
V_20 = V_12 ;
F_15 ( V_12 ) ;
return 0 ;
}
static void F_16 ( struct V_11 * V_12 )
{
( (struct V_30 * ) V_12 -> V_32 ) -> V_33 = 1 ;
F_17 ( V_12 ) ;
F_18 ( V_12 -> V_32 ) ;
}
static int F_19 ( struct V_11 * V_34 ,
void * V_35 )
{
if ( V_34 -> V_36 == 0 )
return - V_24 ;
return F_20 ( V_34 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
int V_13 ;
F_13 ( & V_12 -> V_2 , L_7 ) ;
F_14 ( & V_12 -> V_2 , L_8 ) ;
V_12 -> V_37 |= V_38 | V_39 |
V_40 ;
V_13 = F_21 ( V_12 , F_19 , NULL ) ;
if ( V_13 ) {
F_22 ( & V_12 -> V_2 , L_9 ) ;
goto V_41;
}
if ( ! V_12 -> V_10 )
goto V_41;
V_13 = F_23 ( V_12 ) ;
if ( V_13 )
goto V_41;
return;
V_41:
F_13 ( & V_12 -> V_2 , L_10 ) ;
F_17 ( V_12 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_14 ( & V_12 -> V_2 , L_11 ) ;
F_24 ( V_12 ) ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_30 * V_31 = V_12 -> V_32 ;
V_31 -> V_33 = 1 ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 )
{
struct V_30 * V_31 = V_12 -> V_32 ;
V_31 -> V_33 = 0 ;
return 0 ;
}
static int T_1 F_27 ( void )
{
F_28 ( L_12 ) ;
F_29 ( & V_42 ) ;
return 0 ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_42 ) ;
}
int T_1 F_32 ( void )
{
int V_13 ;
V_13 = F_27 () ;
if ( V_13 < 0 )
return V_13 ;
return F_33 ( & V_43 ) ;
}
void T_2 F_34 ( void )
{
F_30 () ;
F_35 ( & V_43 ) ;
}
