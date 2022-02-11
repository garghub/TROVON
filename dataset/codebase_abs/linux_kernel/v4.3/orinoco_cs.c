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
F_12 ( F_13 ( V_2 ) ) ;
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_5 * V_7 , void * V_13 )
{
if ( V_7 -> V_14 == 0 )
return - V_15 ;
return F_16 ( V_7 ) ;
}
static int
F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
int V_18 ;
void T_1 * V_19 ;
V_6 -> V_20 |= V_21 | V_22 |
V_23 | V_24 ;
if ( V_25 )
V_6 -> V_20 &= ~ V_22 ;
V_18 = F_17 ( V_6 , F_15 , NULL ) ;
if ( V_18 ) {
if ( ! V_25 )
F_18 (KERN_ERR PFX L_1
L_2
L_3 ) ;
goto V_26;
}
V_19 = F_19 ( V_6 -> V_27 [ 0 ] -> V_28 ,
F_20 ( V_6 -> V_27 [ 0 ] ) ) ;
if ( ! V_19 )
goto V_26;
F_21 ( V_17 , V_19 , V_29 ) ;
V_18 = F_22 ( V_6 , V_30 ) ;
if ( V_18 )
goto V_26;
V_18 = F_23 ( V_6 ) ;
if ( V_18 )
goto V_26;
if ( F_24 ( V_2 ) != 0 ) {
F_18 (KERN_ERR PFX L_4 ) ;
goto V_26;
}
if ( F_25 ( V_2 , V_6 -> V_27 [ 0 ] -> V_28 ,
V_6 -> V_31 , NULL ) != 0 ) {
F_18 (KERN_ERR PFX L_5 ) ;
goto V_26;
}
return 0 ;
V_26:
F_11 ( V_6 ) ;
return - V_32 ;
}
static void
F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned long V_33 ;
V_2 -> V_17 . V_34 -> V_35 ( & V_2 -> V_36 , & V_33 ) ;
V_2 -> V_37 ++ ;
V_2 -> V_17 . V_34 -> V_38 ( & V_2 -> V_36 , & V_33 ) ;
F_26 ( V_6 ) ;
if ( V_2 -> V_17 . V_39 )
F_27 ( V_2 -> V_17 . V_39 ) ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_29 ( 0 , & V_4 -> V_9 ) )
F_30 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 = 0 ;
if ( ! F_29 ( 0 , & V_4 -> V_9 ) )
V_8 = F_32 ( V_2 ) ;
return V_8 ;
}
