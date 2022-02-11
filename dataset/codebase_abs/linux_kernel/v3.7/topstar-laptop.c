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
union V_11 V_12 [ 1 ] = {
{ . type = V_13 }
} ;
struct V_14 V_15 = { 1 , & V_12 [ 0 ] } ;
V_12 [ 0 ] . integer . V_16 = V_9 ? 0x86 : 0x87 ;
V_10 = F_6 ( V_2 -> V_17 , L_2 , & V_15 , NULL ) ;
if ( F_7 ( V_10 ) ) {
F_8 ( L_3 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
int error ;
V_20 = F_10 () ;
if ( ! V_20 ) {
F_8 ( L_4 ) ;
return - V_21 ;
}
V_20 -> V_22 = L_5 ;
V_20 -> V_23 = L_6 ;
V_20 -> V_24 . V_25 = V_26 ;
error = F_11 ( V_20 , V_27 , NULL ) ;
if ( error ) {
F_8 ( L_7 ) ;
goto V_28;
}
error = F_12 ( V_20 ) ;
if ( error ) {
F_8 ( L_8 ) ;
goto V_29;
}
V_7 -> V_8 = V_20 ;
return 0 ;
V_29:
F_13 ( V_20 ) ;
V_28:
F_14 ( V_20 ) ;
return error ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_30 ;
V_30 = F_16 ( sizeof( struct V_6 ) , V_31 ) ;
if ( ! V_30 )
return - V_21 ;
strcpy ( F_17 ( V_2 ) , L_9 ) ;
strcpy ( F_18 ( V_2 ) , V_32 ) ;
if ( F_5 ( V_2 , true ) )
goto V_33;
if ( F_9 ( V_30 ) )
goto V_33;
V_2 -> V_34 = V_30 ;
return 0 ;
V_33:
F_19 ( V_30 ) ;
return - V_18 ;
}
static int F_20 ( struct V_1 * V_2 , int type )
{
struct V_6 * V_30 = F_2 ( V_2 ) ;
F_5 ( V_2 , false ) ;
F_13 ( V_30 -> V_8 ) ;
F_21 ( V_30 -> V_8 ) ;
F_19 ( V_30 ) ;
return 0 ;
}
