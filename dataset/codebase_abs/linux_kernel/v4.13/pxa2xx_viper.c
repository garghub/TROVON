static inline struct V_1 * F_1 ( void )
{
return V_2 -> V_3 . V_4 ;
}
static int F_2 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 () ;
unsigned long V_8 ;
V_6 -> V_9 [ V_10 ] . V_11 = V_7 -> V_12 ;
V_6 -> V_9 [ V_10 ] . V_13 = L_1 ;
V_6 -> V_9 [ V_14 ] . V_11 = V_7 -> V_15 ;
V_6 -> V_9 [ V_14 ] . V_13 = L_2 ;
if ( F_3 ( V_7 -> V_16 , L_3 ) )
goto V_17;
F_4 ( V_8 ) ;
if ( F_5 ( V_7 -> V_16 , 0 ) ) {
F_6 ( V_8 ) ;
goto V_18;
}
F_6 ( V_8 ) ;
return 0 ;
V_18:
F_7 ( V_7 -> V_16 ) ;
V_17:
F_8 ( & V_2 -> V_3 , L_4 ) ;
return - 1 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 () ;
F_7 ( V_7 -> V_16 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_19 * V_20 )
{
V_20 -> V_21 = 1 ;
V_20 -> V_22 = 0 ;
}
static int F_11 ( struct V_5 * V_6 ,
const T_1 * V_20 )
{
struct V_1 * V_7 = F_1 () ;
V_7 -> V_23 ( V_20 -> V_8 & V_24 ) ;
switch ( V_20 -> V_25 ) {
case 0 :
F_12 ( V_7 -> V_16 , 0 ) ;
break;
case 33 :
F_12 ( V_7 -> V_16 , 1 ) ;
break;
default:
F_8 ( & V_2 -> V_3 , L_5 , V_20 -> V_25 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_26 * V_27 )
{
int V_28 ;
if ( V_2 )
return - V_29 ;
if ( ! V_27 -> V_3 . V_4 )
return - V_30 ;
V_31 = F_14 ( L_6 , - 1 ) ;
if ( ! V_31 )
return - V_32 ;
V_2 = V_27 ;
V_31 -> V_3 . V_33 = & V_27 -> V_3 ;
V_28 = F_15 ( V_31 ,
& V_34 ,
sizeof( V_34 ) ) ;
if ( ! V_28 )
V_28 = F_16 ( V_31 ) ;
if ( V_28 ) {
F_17 ( V_31 ) ;
V_2 = NULL ;
}
return V_28 ;
}
static int F_18 ( struct V_26 * V_27 )
{
F_19 ( V_31 ) ;
V_2 = NULL ;
return 0 ;
}
