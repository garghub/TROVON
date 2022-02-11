static inline struct V_1 * F_1 ( void )
{
return V_2 -> V_3 . V_4 ;
}
static int F_2 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 () ;
unsigned long V_8 ;
V_6 -> V_9 . V_10 = F_3 ( V_7 -> V_11 ) ;
V_12 [ 0 ] . V_13 = F_3 ( V_7 -> V_14 ) ;
if ( F_4 ( V_7 -> V_14 , L_1 ) )
goto V_15;
if ( F_4 ( V_7 -> V_11 , L_2 ) )
goto V_16;
if ( F_4 ( V_7 -> V_17 , L_3 ) )
goto V_18;
F_5 ( V_8 ) ;
if ( F_6 ( V_7 -> V_17 , 0 ) ||
F_7 ( V_7 -> V_14 ) ||
F_7 ( V_7 -> V_11 ) ) {
F_8 ( V_8 ) ;
goto V_19;
}
F_8 ( V_8 ) ;
return F_9 ( V_6 , V_12 , F_10 ( V_12 ) ) ;
V_19:
F_11 ( V_7 -> V_17 ) ;
V_18:
F_11 ( V_7 -> V_11 ) ;
V_16:
F_11 ( V_7 -> V_14 ) ;
V_15:
F_12 ( & V_2 -> V_3 , L_4 ) ;
return - 1 ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 () ;
F_14 ( V_6 , V_12 , F_10 ( V_12 ) ) ;
F_11 ( V_7 -> V_17 ) ;
F_11 ( V_7 -> V_11 ) ;
F_11 ( V_7 -> V_14 ) ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_20 * V_21 )
{
struct V_1 * V_7 = F_1 () ;
V_21 -> V_22 = ! F_16 ( V_7 -> V_14 ) ;
V_21 -> V_23 = ! ! F_16 ( V_7 -> V_11 ) ;
V_21 -> V_24 = 1 ;
V_21 -> V_25 = 1 ;
V_21 -> V_26 = 0 ;
V_21 -> V_27 = 1 ;
V_21 -> V_28 = 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
const T_1 * V_21 )
{
struct V_1 * V_7 = F_1 () ;
V_7 -> V_29 ( V_21 -> V_8 & V_30 ) ;
switch ( V_21 -> V_31 ) {
case 0 :
F_18 ( V_7 -> V_17 , 0 ) ;
break;
case 33 :
F_18 ( V_7 -> V_17 , 1 ) ;
break;
default:
F_12 ( & V_2 -> V_3 , L_5 , V_21 -> V_31 ) ;
return - 1 ;
}
return 0 ;
}
static void F_19 ( struct V_5 * V_6 )
{
}
static void F_20 ( struct V_5 * V_6 )
{
}
static int F_21 ( struct V_32 * V_33 )
{
int V_34 ;
if ( V_2 )
return - V_35 ;
if ( ! V_33 -> V_3 . V_4 )
return - V_36 ;
V_37 = F_22 ( L_6 , - 1 ) ;
if ( ! V_37 )
return - V_38 ;
V_2 = V_33 ;
V_37 -> V_3 . V_39 = & V_33 -> V_3 ;
V_34 = F_23 ( V_37 ,
& V_40 ,
sizeof( V_40 ) ) ;
if ( ! V_34 )
V_34 = F_24 ( V_37 ) ;
if ( V_34 ) {
F_25 ( V_37 ) ;
V_2 = NULL ;
}
return V_34 ;
}
static int F_26 ( struct V_32 * V_33 )
{
F_27 ( V_37 ) ;
V_2 = NULL ;
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_41 ) ;
}
static void T_3 F_30 ( void )
{
return F_31 ( & V_41 ) ;
}
