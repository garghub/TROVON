static bool F_1 ( const struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
return V_3 & V_4 ;
}
static bool F_3 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 , T_1 V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = F_4 ( V_6 ) ;
bool V_14 = false ;
struct V_15 V_16 = {
. V_17 = V_18 ,
. V_19 = ( * ( V_20 * ) V_13 ) & V_21 ,
. V_22 = V_13 -> V_23 ,
. V_24 = V_13 -> V_25 ,
} ;
int V_26 ;
if ( F_1 ( & V_13 -> V_24 ) ) {
memcpy ( & V_16 . V_25 , & V_13 -> V_24 , sizeof( struct V_1 ) ) ;
V_26 = V_27 ;
} else {
V_26 = 0 ;
}
V_16 . V_28 = V_9 & V_29 ? V_6 -> V_30 : 0 ;
if ( ( V_9 & V_31 ) == 0 ) {
V_16 . V_32 = V_8 -> V_33 ;
V_26 |= V_34 ;
}
V_11 = ( void * ) F_5 ( F_6 ( V_8 ) , & V_16 , V_26 ) ;
if ( V_11 -> V_35 . error )
goto V_36;
if ( V_11 -> V_37 & ( V_38 | V_39 ) )
goto V_36;
if ( V_11 -> V_37 & V_40 ) {
V_14 = V_9 & V_41 ;
goto V_36;
}
if ( V_11 -> V_42 -> V_8 == V_8 || ( V_9 & V_31 ) )
V_14 = true ;
V_36:
F_7 ( V_11 ) ;
return V_14 ;
}
static bool F_8 ( const struct V_5 * V_6 )
{
const struct V_10 * V_11 = ( const void * ) F_9 ( V_6 ) ;
return V_11 && ( V_11 -> V_37 & V_40 ) ;
}
static bool F_10 ( const struct V_5 * V_6 , struct V_43 * V_44 )
{
const struct V_45 * V_46 = V_44 -> V_47 ;
int V_48 ;
struct V_12 * V_13 ;
bool V_49 = V_46 -> V_9 & V_50 ;
if ( F_8 ( V_6 ) )
return true ^ V_49 ;
V_13 = F_4 ( V_6 ) ;
V_48 = F_2 ( & V_13 -> V_25 ) ;
if ( F_11 ( V_48 == V_51 ) )
return true ^ V_49 ;
return F_3 ( V_6 , V_44 -> V_52 , V_46 -> V_9 ) ^ V_49 ;
}
static int F_12 ( const struct V_53 * V_44 )
{
const struct V_45 * V_46 = V_44 -> V_47 ;
unsigned int V_54 = ~ V_55 ;
if ( V_46 -> V_9 & V_54 ) {
F_13 ( L_1 ) ;
return - V_56 ;
}
if ( strcmp ( V_44 -> V_57 , L_2 ) != 0 &&
strcmp ( V_44 -> V_57 , L_3 ) != 0 ) {
F_13 ( L_4
L_5 , V_44 -> V_57 ) ;
return - V_56 ;
}
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_58 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_58 ) ;
}
