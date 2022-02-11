static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
static bool V_4 [ 2 ] ;
bool * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 == 0x83 || V_3 == 0x84 ) {
V_5 = & V_4 [ V_3 - 0x83 ] ;
if ( * V_5 ) {
* V_5 = false ;
return;
}
* V_5 = true ;
}
if ( ! F_3 ( V_7 -> V_8 , V_3 , 1 , true ) )
F_4 ( L_1 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_9 )
{
T_2 V_10 ;
V_10 = F_6 ( V_2 -> V_11 , L_2 ,
V_9 ? 0x86 : 0x87 ) ;
if ( F_7 ( V_10 ) ) {
F_8 ( L_3 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_13 * V_14 ;
int error ;
V_14 = F_10 () ;
if ( ! V_14 )
return - V_15 ;
V_14 -> V_16 = L_4 ;
V_14 -> V_17 = L_5 ;
V_14 -> V_18 . V_19 = V_20 ;
error = F_11 ( V_14 , V_21 , NULL ) ;
if ( error ) {
F_8 ( L_6 ) ;
goto V_22;
}
error = F_12 ( V_14 ) ;
if ( error ) {
F_8 ( L_7 ) ;
goto V_23;
}
V_7 -> V_8 = V_14 ;
return 0 ;
V_23:
F_13 ( V_14 ) ;
V_22:
F_14 ( V_14 ) ;
return error ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_24 ;
V_24 = F_16 ( sizeof( struct V_6 ) , V_25 ) ;
if ( ! V_24 )
return - V_15 ;
strcpy ( F_17 ( V_2 ) , L_8 ) ;
strcpy ( F_18 ( V_2 ) , V_26 ) ;
if ( F_5 ( V_2 , true ) )
goto V_27;
if ( F_9 ( V_24 ) )
goto V_27;
V_2 -> V_28 = V_24 ;
return 0 ;
V_27:
F_19 ( V_24 ) ;
return - V_12 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_24 = F_2 ( V_2 ) ;
F_5 ( V_2 , false ) ;
F_13 ( V_24 -> V_8 ) ;
F_21 ( V_24 -> V_8 ) ;
F_19 ( V_24 ) ;
return 0 ;
}
