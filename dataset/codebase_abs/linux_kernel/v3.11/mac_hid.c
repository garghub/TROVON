static int F_1 ( void )
{
static struct V_1 V_2 ;
static struct V_1 V_3 ;
int V_4 ;
V_5 = F_2 () ;
if ( ! V_5 )
return - V_6 ;
F_3 ( & V_5 -> V_7 ,
& V_2 ) ;
F_3 ( & V_5 -> V_8 ,
& V_3 ) ;
V_5 -> V_9 = L_1 ;
V_5 -> V_10 . V_11 = V_12 ;
V_5 -> V_10 . V_13 = 0x0001 ;
V_5 -> V_10 . V_14 = 0x0001 ;
V_5 -> V_10 . V_15 = 0x0100 ;
V_5 -> V_16 [ 0 ] = F_4 ( V_17 ) | F_4 ( V_18 ) ;
V_5 -> V_19 [ F_5 ( V_20 ) ] =
F_4 ( V_21 ) | F_4 ( V_22 ) | F_4 ( V_23 ) ;
V_5 -> V_24 [ 0 ] = F_4 ( V_25 ) | F_4 ( V_26 ) ;
V_4 = F_6 ( V_5 ) ;
if ( V_4 ) {
F_7 ( V_5 ) ;
V_5 = NULL ;
return V_4 ;
}
return 0 ;
}
static void F_8 ( void )
{
F_9 ( V_5 ) ;
V_5 = NULL ;
}
static bool F_10 ( struct V_27 * V_28 ,
unsigned int type , unsigned int V_29 ,
int V_30 )
{
unsigned int V_31 ;
if ( type != V_17 )
return false ;
if ( V_29 == V_32 )
V_31 = V_22 ;
else if ( V_29 == V_33 )
V_31 = V_23 ;
else
return false ;
F_11 ( V_5 , V_31 , V_30 ) ;
F_12 ( V_5 ) ;
return true ;
}
static int F_13 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const struct V_38 * V_10 )
{
struct V_27 * V_28 ;
int error ;
if ( V_37 == V_5 )
return - V_39 ;
V_28 = F_14 ( sizeof( struct V_27 ) , V_40 ) ;
if ( ! V_28 )
return - V_6 ;
V_28 -> V_37 = V_37 ;
V_28 -> V_35 = V_35 ;
V_28 -> V_9 = L_2 ;
error = F_15 ( V_28 ) ;
if ( error ) {
F_16 ( V_41
L_3
L_4 , error ) ;
goto V_42;
}
error = F_17 ( V_28 ) ;
if ( error ) {
F_16 ( V_41
L_5 ,
error ) ;
goto V_43;
}
return 0 ;
V_43:
F_18 ( V_28 ) ;
V_42:
F_19 ( V_28 ) ;
return error ;
}
static void F_20 ( struct V_27 * V_28 )
{
F_21 ( V_28 ) ;
F_18 ( V_28 ) ;
F_19 ( V_28 ) ;
}
static int F_22 ( void )
{
int V_4 ;
V_4 = F_1 () ;
if ( V_4 )
return V_4 ;
V_4 = F_23 ( & V_44 ) ;
if ( V_4 ) {
F_8 () ;
return V_4 ;
}
return 0 ;
}
static void F_24 ( void )
{
F_25 ( & V_44 ) ;
F_8 () ;
}
static int F_26 ( struct V_45 * V_46 , int V_47 ,
void T_1 * V_48 , T_2 * V_49 ,
T_3 * V_50 )
{
int * V_51 = V_46 -> V_52 ;
int V_53 = * V_51 ;
int V_54 ;
V_54 = F_27 ( & V_55 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_28 ( V_46 , V_47 , V_48 , V_49 , V_50 ) ;
if ( V_54 == 0 && V_47 && * V_51 != V_53 ) {
if ( * V_51 == 1 )
V_54 = F_22 () ;
else if ( * V_51 == 0 )
F_24 () ;
else
V_54 = - V_56 ;
}
if ( V_54 )
* V_51 = V_53 ;
F_29 ( & V_55 ) ;
return V_54 ;
}
static int T_4 F_30 ( void )
{
V_57 = F_31 ( V_58 ) ;
if ( ! V_57 )
return - V_6 ;
return 0 ;
}
static void T_5 F_32 ( void )
{
F_33 ( V_57 ) ;
if ( V_59 )
F_24 () ;
}
