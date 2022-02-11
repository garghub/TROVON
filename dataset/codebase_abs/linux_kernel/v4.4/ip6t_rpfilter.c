static bool F_1 ( const struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
return V_3 & V_4 ;
}
static bool F_3 ( struct V_5 * V_5 , const struct V_6 * V_7 ,
const struct V_8 * V_9 , T_1 V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 = F_4 ( V_7 ) ;
bool V_15 = false ;
struct V_16 V_17 = {
. V_18 = V_19 ,
. V_20 = ( * ( V_21 * ) V_14 ) & V_22 ,
. V_23 = V_14 -> V_24 ,
. V_25 = V_14 -> V_26 ,
} ;
int V_27 ;
if ( F_1 ( & V_14 -> V_25 ) ) {
memcpy ( & V_17 . V_26 , & V_14 -> V_25 , sizeof( struct V_1 ) ) ;
V_27 = V_28 ;
} else {
V_27 = 0 ;
}
V_17 . V_29 = V_10 & V_30 ? V_7 -> V_31 : 0 ;
if ( ( V_10 & V_32 ) == 0 ) {
V_17 . V_33 = V_9 -> V_34 ;
V_27 |= V_35 ;
}
V_12 = ( void * ) F_5 ( V_5 , & V_17 , V_27 ) ;
if ( V_12 -> V_36 . error )
goto V_37;
if ( V_12 -> V_38 & ( V_39 | V_40 ) )
goto V_37;
if ( V_12 -> V_38 & V_41 ) {
V_15 = V_10 & V_42 ;
goto V_37;
}
if ( V_12 -> V_43 -> V_9 == V_9 || ( V_10 & V_32 ) )
V_15 = true ;
V_37:
F_6 ( V_12 ) ;
return V_15 ;
}
static bool F_7 ( const struct V_6 * V_7 )
{
const struct V_11 * V_12 = ( const void * ) F_8 ( V_7 ) ;
return V_12 && ( V_12 -> V_38 & V_41 ) ;
}
static bool F_9 ( const struct V_6 * V_7 , struct V_44 * V_45 )
{
const struct V_46 * V_47 = V_45 -> V_48 ;
int V_49 ;
struct V_13 * V_14 ;
bool V_50 = V_47 -> V_10 & V_51 ;
if ( F_7 ( V_7 ) )
return true ^ V_50 ;
V_14 = F_4 ( V_7 ) ;
V_49 = F_2 ( & V_14 -> V_26 ) ;
if ( F_10 ( V_49 == V_52 ) )
return true ^ V_50 ;
return F_3 ( V_45 -> V_5 , V_7 , V_45 -> V_53 , V_47 -> V_10 ) ^ V_50 ;
}
static int F_11 ( const struct V_54 * V_45 )
{
const struct V_46 * V_47 = V_45 -> V_48 ;
unsigned int V_55 = ~ V_56 ;
if ( V_47 -> V_10 & V_55 ) {
F_12 ( L_1 ) ;
return - V_57 ;
}
if ( strcmp ( V_45 -> V_58 , L_2 ) != 0 &&
strcmp ( V_45 -> V_58 , L_3 ) != 0 ) {
F_12 ( L_4
L_5 , V_45 -> V_58 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_59 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_59 ) ;
}
