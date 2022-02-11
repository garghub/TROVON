static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
if ( V_6 -> V_4 != V_4 ) {
V_6 -> V_4 = V_4 ;
V_6 -> V_7 = true ;
F_3 ( & V_6 -> V_8 ) ;
}
}
static int F_4 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_5 * V_6 ;
V_6 = F_5 ( sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_6 -> V_2 . V_13 = V_6 -> V_14 . V_13 ;
V_6 -> V_2 . V_15 = F_1 ;
F_6 ( & V_6 -> V_16 ) ;
F_7 ( & V_6 -> V_8 ) ;
V_6 -> V_17 = V_18 ;
V_10 -> V_19 = V_6 ;
F_8 ( V_9 , V_10 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_10 * V_10 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_5 * V_6 = V_10 -> V_19 ;
const char * V_13 ;
int V_23 ;
if ( V_21 == 0 )
return 0 ;
V_23 = F_10 ( & V_6 -> V_16 ) ;
if ( V_23 )
return V_23 ;
if ( V_6 -> V_17 == V_24 ) {
V_23 = - V_25 ;
goto V_26;
}
if ( V_21 != sizeof( struct V_27 ) ) {
V_23 = - V_28 ;
goto V_26;
}
if ( F_11 ( & V_6 -> V_14 , V_20 ,
sizeof( struct V_27 ) ) ) {
V_23 = - V_29 ;
goto V_26;
}
V_13 = V_6 -> V_14 . V_13 ;
if ( ! V_13 [ 0 ] || ! strcmp ( V_13 , L_1 ) || ! strcmp ( V_13 , L_2 ) ||
strchr ( V_13 , '/' ) ) {
V_23 = - V_28 ;
goto V_26;
}
if ( V_6 -> V_14 . V_30 <= 0 ) {
V_23 = - V_28 ;
goto V_26;
}
V_6 -> V_2 . V_30 = V_6 -> V_14 . V_30 ;
V_23 = F_12 ( V_31 . V_32 ,
& V_6 -> V_2 ) ;
if ( V_23 < 0 )
goto V_26;
V_6 -> V_7 = true ;
V_6 -> V_17 = V_24 ;
V_23 = V_21 ;
V_26:
F_13 ( & V_6 -> V_16 ) ;
return V_23 ;
}
static T_1 F_14 ( struct V_10 * V_10 , char T_2 * V_20 , T_3 V_21 ,
T_4 * V_22 )
{
struct V_5 * V_6 = V_10 -> V_19 ;
T_1 V_33 ;
if ( V_21 < sizeof( V_6 -> V_4 ) )
return 0 ;
do {
V_33 = F_10 ( & V_6 -> V_16 ) ;
if ( V_33 )
return V_33 ;
if ( V_6 -> V_17 != V_24 ) {
V_33 = - V_34 ;
} else if ( ! V_6 -> V_7 && ( V_10 -> V_35 & V_36 ) ) {
V_33 = - V_37 ;
} else if ( V_6 -> V_7 ) {
V_33 = F_15 ( V_20 , & V_6 -> V_4 ,
sizeof( V_6 -> V_4 ) ) ;
V_6 -> V_7 = false ;
V_33 = sizeof( V_6 -> V_4 ) ;
}
F_13 ( & V_6 -> V_16 ) ;
if ( V_33 )
break;
if ( ! ( V_10 -> V_35 & V_36 ) )
V_33 = F_16 ( V_6 -> V_8 ,
V_6 -> V_7 ||
V_6 -> V_17 != V_24 ) ;
} while ( V_33 == 0 );
return V_33 ;
}
static unsigned int F_17 ( struct V_10 * V_10 , T_5 * V_38 )
{
struct V_5 * V_6 = V_10 -> V_19 ;
F_18 ( V_10 , & V_6 -> V_8 , V_38 ) ;
if ( V_6 -> V_7 )
return V_39 | V_40 ;
return 0 ;
}
static int F_19 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_19 ;
if ( V_6 -> V_17 == V_24 ) {
V_6 -> V_17 = V_18 ;
F_20 ( V_31 . V_32 ,
& V_6 -> V_2 ) ;
}
F_21 ( V_6 ) ;
return 0 ;
}
static int T_6 F_22 ( void )
{
return F_23 ( & V_31 ) ;
}
static void T_7 F_24 ( void )
{
F_25 ( & V_31 ) ;
}
