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
. V_17 = ( * ( V_18 * ) V_13 ) & V_19 ,
. V_20 = V_13 -> V_21 ,
. V_22 = V_13 -> V_23 ,
} ;
int V_24 ;
if ( F_1 ( & V_13 -> V_22 ) ) {
memcpy ( & V_16 . V_23 , & V_13 -> V_22 , sizeof( struct V_1 ) ) ;
V_24 = V_25 ;
} else {
V_24 = 0 ;
}
V_16 . V_26 = V_9 & V_27 ? V_6 -> V_28 : 0 ;
if ( ( V_9 & V_29 ) == 0 ) {
V_16 . V_30 = V_8 -> V_31 ;
V_24 |= V_32 ;
}
V_11 = ( void * ) F_5 ( F_6 ( V_8 ) , & V_16 , V_24 ) ;
if ( V_11 -> V_33 . error )
goto V_34;
if ( V_11 -> V_35 & ( V_36 | V_37 ) )
goto V_34;
if ( V_11 -> V_35 & V_38 ) {
V_14 = V_9 & V_39 ;
goto V_34;
}
if ( V_11 -> V_40 -> V_8 == V_8 || ( V_9 & V_29 ) )
V_14 = true ;
V_34:
F_7 ( V_11 ) ;
return V_14 ;
}
static bool F_8 ( const struct V_5 * V_6 , struct V_41 * V_42 )
{
const struct V_43 * V_44 = V_42 -> V_45 ;
int V_46 ;
struct V_12 * V_13 ;
bool V_47 = V_44 -> V_9 & V_48 ;
if ( V_42 -> V_49 -> V_9 & V_50 )
return true ^ V_47 ;
V_13 = F_4 ( V_6 ) ;
V_46 = F_2 ( & V_13 -> V_23 ) ;
if ( F_9 ( V_46 == V_51 ) )
return true ^ V_47 ;
return F_3 ( V_6 , V_42 -> V_49 , V_44 -> V_9 ) ^ V_47 ;
}
static int F_10 ( const struct V_52 * V_42 )
{
const struct V_43 * V_44 = V_42 -> V_45 ;
unsigned int V_53 = ~ V_54 ;
if ( V_44 -> V_9 & V_53 ) {
F_11 ( L_1 ) ;
return - V_55 ;
}
if ( strcmp ( V_42 -> V_56 , L_2 ) != 0 &&
strcmp ( V_42 -> V_56 , L_3 ) != 0 ) {
F_11 ( L_4
L_5 , V_42 -> V_56 ) ;
return - V_55 ;
}
return 0 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_57 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_57 ) ;
}
