static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
F_2 ( 0 , & V_4 -> V_9 ) ;
V_8 = F_3 ( V_6 -> V_10 ) ;
if ( V_8 )
return V_8 ;
F_4 ( 100 ) ;
F_5 ( 0 , & V_4 -> V_9 ) ;
return 0 ;
}
static int
F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_7 ( sizeof( * V_4 ) , & V_6 -> V_11 ,
F_1 , NULL ) ;
if ( ! V_2 )
return - V_12 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_7 = V_6 ;
V_6 -> V_2 = V_2 ;
return F_8 ( V_6 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_10 ( V_2 ) ;
F_11 ( V_6 ) ;
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_5 * V_7 , void * V_13 )
{
if ( V_7 -> V_14 == 0 )
return - V_15 ;
return F_14 ( V_7 ) ;
}
static int
F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 * V_16 = & V_2 -> V_16 ;
int V_17 ;
void T_2 * V_18 ;
V_6 -> V_19 |= V_20 | V_21 |
V_22 | V_23 ;
if ( V_24 )
V_6 -> V_19 &= ~ V_21 ;
V_17 = F_15 ( V_6 , F_13 , NULL ) ;
if ( V_17 ) {
if ( ! V_24 )
F_16 (KERN_ERR PFX L_1
L_2
L_3 ) ;
goto V_25;
}
V_18 = F_17 ( V_6 -> V_26 [ 0 ] -> V_27 ,
F_18 ( V_6 -> V_26 [ 0 ] ) ) ;
if ( ! V_18 )
goto V_25;
F_19 ( V_16 , V_18 , V_28 ) ;
V_17 = F_20 ( V_6 , V_29 ) ;
if ( V_17 )
goto V_25;
V_17 = F_21 ( V_6 ) ;
if ( V_17 )
goto V_25;
if ( F_22 ( V_2 ) != 0 ) {
F_16 (KERN_ERR PFX L_4 ) ;
goto V_25;
}
if ( F_23 ( V_2 , V_6 -> V_26 [ 0 ] -> V_27 ,
V_6 -> V_30 , NULL ) != 0 ) {
F_16 (KERN_ERR PFX L_5 ) ;
goto V_25;
}
return 0 ;
V_25:
F_11 ( V_6 ) ;
return - V_31 ;
}
static void
F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned long V_32 ;
V_2 -> V_16 . V_33 -> V_34 ( & V_2 -> V_35 , & V_32 ) ;
V_2 -> V_36 ++ ;
V_2 -> V_16 . V_33 -> V_37 ( & V_2 -> V_35 , & V_32 ) ;
F_24 ( V_6 ) ;
if ( V_2 -> V_16 . V_38 )
F_25 ( V_2 -> V_16 . V_38 ) ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_27 ( 0 , & V_4 -> V_9 ) )
F_28 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 = 0 ;
if ( ! F_27 ( 0 , & V_4 -> V_9 ) )
V_8 = F_30 ( V_2 ) ;
return V_8 ;
}
static int T_3
F_31 ( void )
{
return F_32 ( & V_39 ) ;
}
static void T_4
F_33 ( void )
{
F_34 ( & V_39 ) ;
}
