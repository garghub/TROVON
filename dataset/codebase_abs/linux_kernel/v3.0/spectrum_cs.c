static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 ;
T_1 V_6 ;
if ( ! F_2 ( V_2 ) )
return - V_7 ;
V_4 = F_3 ( V_2 , V_8 , & V_5 ) ;
if ( V_4 )
goto V_9;
V_4 = F_4 ( V_2 , V_8 ,
( V_5 | V_10 ) ) ;
if ( V_4 )
goto V_9;
F_5 ( 1000 ) ;
V_4 = F_3 ( V_2 , V_11 , & V_6 ) ;
if ( V_4 )
goto V_9;
V_6 = ( V_3 ? V_12 : V_13 ) | ( V_6 & V_14 ) ;
V_4 = F_4 ( V_2 , V_11 , V_6 ) ;
if ( V_4 )
goto V_9;
F_5 ( 1000 ) ;
V_4 = F_4 ( V_2 , V_8 ,
( V_5 & ~ V_10 ) ) ;
if ( V_4 )
goto V_9;
F_5 ( 1000 ) ;
return 0 ;
V_9:
return - V_7 ;
}
static int
F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int
F_7 ( struct V_15 * V_16 , int V_3 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
return F_1 ( V_2 , V_3 ) ;
}
static int
F_8 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = F_9 ( sizeof( * V_18 ) , & V_2 -> V_20 ,
F_6 ,
F_7 ) ;
if ( ! V_16 )
return - V_21 ;
V_18 = V_16 -> V_18 ;
V_18 -> V_19 = V_2 ;
V_2 -> V_16 = V_16 ;
return F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_12 ( V_16 ) ;
F_13 ( V_2 ) ;
F_14 ( V_16 ) ;
}
static int F_15 ( struct V_1 * V_19 ,
void * V_22 )
{
if ( V_19 -> V_23 == 0 )
return - V_24 ;
return F_16 ( V_19 ) ;
}
static int
F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 * V_25 = & V_16 -> V_25 ;
int V_4 ;
void T_3 * V_26 ;
V_2 -> V_27 |= V_28 | V_29 |
V_30 | V_31 ;
if ( V_32 )
V_2 -> V_27 &= ~ V_29 ;
V_4 = F_17 ( V_2 , F_15 , NULL ) ;
if ( V_4 ) {
if ( ! V_32 )
F_18 (KERN_ERR PFX L_1
L_2
L_3 ) ;
goto V_9;
}
V_26 = F_19 ( V_2 -> V_33 [ 0 ] -> V_34 ,
F_20 ( V_2 -> V_33 [ 0 ] ) ) ;
if ( ! V_26 )
goto V_9;
F_21 ( V_25 , V_26 , V_35 ) ;
V_25 -> V_36 = true ;
V_4 = F_22 ( V_2 , V_37 ) ;
if ( V_4 )
goto V_9;
V_4 = F_23 ( V_2 ) ;
if ( V_4 )
goto V_9;
if ( F_6 ( V_16 ) != 0 )
goto V_9;
if ( F_24 ( V_16 ) != 0 ) {
F_18 (KERN_ERR PFX L_4 ) ;
goto V_9;
}
if ( F_25 ( V_16 , V_2 -> V_33 [ 0 ] -> V_34 ,
V_2 -> V_38 , NULL ) != 0 ) {
F_18 (KERN_ERR PFX L_5 ) ;
goto V_9;
}
return 0 ;
V_9:
F_13 ( V_2 ) ;
return - V_7 ;
}
static void
F_13 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned long V_39 ;
V_16 -> V_25 . V_40 -> V_41 ( & V_16 -> V_42 , & V_39 ) ;
V_16 -> V_43 ++ ;
V_16 -> V_25 . V_40 -> V_44 ( & V_16 -> V_42 , & V_39 ) ;
F_26 ( V_2 ) ;
if ( V_16 -> V_25 . V_45 )
F_27 ( V_16 -> V_25 . V_45 ) ;
}
static int
F_28 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_46 = 0 ;
F_29 ( V_16 ) ;
return V_46 ;
}
static int
F_30 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_46 = F_31 ( V_16 ) ;
return V_46 ;
}
static int T_4
F_32 ( void )
{
return F_33 ( & V_47 ) ;
}
static void T_5
F_34 ( void )
{
F_35 ( & V_47 ) ;
}
