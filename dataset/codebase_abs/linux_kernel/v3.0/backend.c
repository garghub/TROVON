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
memset ( V_4 -> V_35 , 0 , V_36 * 4 ) ;
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
void * V_40 = F_14 ( V_4 -> V_27 ) ;
V_4 -> V_21 -> V_41 ( V_40 , V_42 ) ;
V_4 -> V_21 -> V_41 ( V_40 , V_43 ) ;
}
if ( V_16 )
V_4 -> V_21 -> V_44 ( V_4 ) ;
if ( V_17 ) {
F_15 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
}
return V_15 ;
}
static void F_16 ( struct V_1 * V_4 )
{
if ( V_4 -> V_21 -> V_45 )
V_4 -> V_21 -> V_45 () ;
if ( V_4 -> V_21 -> V_44 )
V_4 -> V_21 -> V_44 ( V_4 ) ;
F_15 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
if ( V_4 -> V_21 -> V_41 &&
V_4 -> V_21 -> V_22 ) {
void * V_40 = F_14 ( V_4 -> V_27 ) ;
V_4 -> V_21 -> V_41 ( V_40 , V_42 ) ;
V_4 -> V_21 -> V_41 ( V_40 , V_43 ) ;
}
}
struct V_1 * F_17 ( void )
{
struct V_1 * V_4 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return NULL ;
F_19 ( & V_4 -> V_5 , 0 ) ;
F_19 ( & V_4 -> V_47 , 0 ) ;
if ( F_20 ( & V_48 ) )
V_49 = V_4 ;
return V_4 ;
}
void F_21 ( struct V_1 * V_4 )
{
F_22 ( V_4 ) ;
if ( F_20 ( & V_48 ) )
V_49 = NULL ;
}
int F_23 ( struct V_1 * V_4 )
{
int error ;
if ( V_50 ) {
error = - V_51 ;
goto V_52;
}
if ( ! V_4 -> V_25 ) {
F_24 (KERN_DEBUG PFX L_6 ) ;
error = - V_32 ;
goto V_52;
}
if ( ! F_25 ( V_4 -> V_21 -> V_53 ) ) {
F_26 ( & V_4 -> V_25 -> V_25 , L_7 ) ;
error = - V_32 ;
goto V_52;
}
error = F_8 ( V_4 ) ;
if ( error ) {
F_26 ( & V_4 -> V_25 -> V_25 ,
L_8 ) ;
goto V_33;
}
if ( F_20 ( & V_48 ) ) {
error = F_27 () ;
if ( error ) {
F_26 ( & V_4 -> V_25 -> V_25 ,
L_9 ) ;
goto V_54;
}
F_26 ( & V_4 -> V_25 -> V_25 , L_10 ,
V_4 -> V_21 -> V_31 () , V_4 -> V_55 ) ;
}
F_28 ( & V_4 -> V_56 , & V_48 ) ;
return 0 ;
V_54:
F_16 ( V_4 ) ;
V_33:
F_29 ( V_4 -> V_21 -> V_53 ) ;
V_52:
F_21 ( V_4 ) ;
return error ;
}
void F_30 ( struct V_1 * V_4 )
{
F_16 ( V_4 ) ;
F_31 ( & V_4 -> V_56 ) ;
if ( F_20 ( & V_48 ) )
F_32 () ;
F_29 ( V_4 -> V_21 -> V_53 ) ;
}
static int T_1 F_33 ( void )
{
if ( ! V_50 )
F_24 ( V_57 L_11 ,
V_58 , V_59 ) ;
return 0 ;
}
static void T_2 F_34 ( void )
{
}
static T_1 int F_35 ( char * V_60 )
{
if ( ! strcmp ( V_60 , L_12 ) )
V_50 = 1 ;
if ( ! strcmp ( V_60 , L_13 ) )
V_61 = 1 ;
return 1 ;
}
