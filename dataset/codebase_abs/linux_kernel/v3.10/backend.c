struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
return NULL ;
if ( F_3 ( & V_4 -> V_5 ) )
return NULL ;
F_4 ( & V_4 -> V_5 ) ;
return V_4 ;
}
void F_5 ( struct V_1 * V_4 )
{
if ( V_4 )
F_6 ( & V_4 -> V_5 ) ;
}
static int F_7 ( void )
{
long V_6 , V_7 , V_8 ;
#if V_9 < 20
V_6 = V_10 >> ( 20 - V_9 ) ;
#else
V_6 = V_10 << ( V_9 - 20 ) ;
#endif
V_7 = 1 ;
while ( ( V_6 > V_11 [ V_7 ] . V_12 ) && ( V_7 < 8 ) )
V_7 ++ ;
V_8 = V_11 [ V_7 - 1 ] . V_13 +
( ( V_6 - V_11 [ V_7 - 1 ] . V_12 ) *
( V_11 [ V_7 ] . V_13 - V_11 [ V_7 - 1 ] . V_13 ) ) /
( V_11 [ V_7 ] . V_12 - V_11 [ V_7 - 1 ] . V_12 ) ;
V_8 = V_8 << ( 20 - V_9 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_4 )
{
int V_14 , V_15 , V_16 = 0 , V_17 = 0 ;
V_4 -> V_18 = F_7 () ;
V_4 -> V_19 = & V_20 ;
if ( V_4 -> V_21 -> V_22 ) {
struct V_23 * V_23 = V_4 -> V_21 -> V_24 ( V_4 ) ;
if ( ! V_23 ) {
F_9 ( & V_4 -> V_25 -> V_25 ,
L_1 ) ;
return - V_26 ;
}
V_4 -> V_27 = V_23 ;
V_4 -> V_28 = F_10 ( V_23 ) ;
V_4 -> V_29 = V_4 -> V_21 -> V_30 ( V_4 ,
V_4 -> V_28 , 0 ) ;
}
V_14 = V_4 -> V_21 -> V_31 () ;
if ( V_14 == 0 ) {
F_9 ( & V_4 -> V_25 -> V_25 , L_2 ) ;
V_15 = - V_32 ;
goto V_33;
}
if ( V_4 -> V_21 -> V_34 ( V_4 ) ) {
F_9 ( & V_4 -> V_25 -> V_25 ,
L_3 ) ;
V_15 = - V_26 ;
goto V_33;
}
V_16 = 1 ;
V_4 -> V_35 = F_11 ( V_36 * 4 ) ;
if ( V_4 -> V_35 == NULL ) {
F_9 ( & V_4 -> V_25 -> V_25 ,
L_4 ) ;
V_15 = - V_26 ;
goto V_33;
}
V_17 = 1 ;
if ( V_4 -> V_21 -> V_37 () ) {
F_9 ( & V_4 -> V_25 -> V_25 , L_5 ) ;
V_15 = - V_32 ;
goto V_33;
}
F_12 ( & V_4 -> V_38 ) ;
F_13 ( & V_4 -> V_39 ) ;
return 0 ;
V_33:
if ( V_4 -> V_21 -> V_22 ) {
struct V_23 * V_23 = V_4 -> V_27 ;
V_4 -> V_21 -> V_40 ( V_23 , V_41 ) ;
V_4 -> V_21 -> V_40 ( V_23 , V_42 ) ;
}
if ( V_16 )
V_4 -> V_21 -> V_43 ( V_4 ) ;
if ( V_17 ) {
F_14 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
}
return V_15 ;
}
static void F_15 ( struct V_1 * V_4 )
{
if ( V_4 -> V_21 -> V_44 )
V_4 -> V_21 -> V_44 () ;
if ( V_4 -> V_21 -> V_43 )
V_4 -> V_21 -> V_43 ( V_4 ) ;
F_14 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
if ( V_4 -> V_21 -> V_40 &&
V_4 -> V_21 -> V_22 ) {
struct V_23 * V_23 = V_4 -> V_27 ;
V_4 -> V_21 -> V_40 ( V_23 , V_41 ) ;
V_4 -> V_21 -> V_40 ( V_23 , V_42 ) ;
}
}
struct V_1 * F_16 ( void )
{
struct V_1 * V_4 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return NULL ;
F_18 ( & V_4 -> V_5 , 0 ) ;
F_18 ( & V_4 -> V_46 , 0 ) ;
if ( F_19 ( & V_47 ) )
V_48 = V_4 ;
return V_4 ;
}
void F_20 ( struct V_1 * V_4 )
{
F_21 ( V_4 ) ;
if ( F_19 ( & V_47 ) )
V_48 = NULL ;
}
int F_22 ( struct V_1 * V_4 )
{
int error ;
if ( V_49 ) {
error = - V_50 ;
goto V_51;
}
if ( ! V_4 -> V_25 ) {
F_23 (KERN_DEBUG PFX L_6 ) ;
error = - V_32 ;
goto V_51;
}
if ( ! F_24 ( V_4 -> V_21 -> V_52 ) ) {
F_25 ( & V_4 -> V_25 -> V_25 , L_7 ) ;
error = - V_32 ;
goto V_51;
}
error = F_8 ( V_4 ) ;
if ( error ) {
F_25 ( & V_4 -> V_25 -> V_25 ,
L_8 ) ;
goto V_33;
}
if ( F_19 ( & V_47 ) ) {
error = F_26 () ;
if ( error ) {
F_25 ( & V_4 -> V_25 -> V_25 ,
L_9 ) ;
goto V_53;
}
F_25 ( & V_4 -> V_25 -> V_25 , L_10 ,
V_4 -> V_21 -> V_31 () , V_4 -> V_54 ) ;
}
F_27 ( & V_4 -> V_55 , & V_47 ) ;
return 0 ;
V_53:
F_15 ( V_4 ) ;
V_33:
F_28 ( V_4 -> V_21 -> V_52 ) ;
V_51:
F_20 ( V_4 ) ;
return error ;
}
void F_29 ( struct V_1 * V_4 )
{
F_15 ( V_4 ) ;
F_30 ( & V_4 -> V_55 ) ;
if ( F_19 ( & V_47 ) )
F_31 () ;
F_28 ( V_4 -> V_21 -> V_52 ) ;
}
static int T_1 F_32 ( void )
{
if ( ! V_49 )
F_23 ( V_56 L_11 ,
V_57 , V_58 ) ;
return 0 ;
}
static void T_2 F_33 ( void )
{
}
static T_1 int F_34 ( char * V_59 )
{
if ( ! strcmp ( V_59 , L_12 ) )
V_49 = 1 ;
if ( ! strcmp ( V_59 , L_13 ) )
V_60 = 1 ;
return 1 ;
}
