struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = NULL ;
F_2 ( & V_3 ) ;
if ( ! F_3 ( & V_4 ) ) {
V_2 = V_5 ;
if ( F_4 ( & V_5 -> V_6 , & V_4 ) )
V_5 = F_5 ( & V_4 ,
struct V_1 ,
V_6 ) ;
else
V_5 = F_6 ( V_5 , V_6 ) ;
}
F_7 ( & V_3 ) ;
return V_2 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_9 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
F_10 ( & V_8 -> V_11 ) ;
V_2 -> V_8 = V_8 ;
V_8 -> V_2 = V_2 ;
F_11 ( & V_12 ) ;
F_2 ( & V_3 ) ;
F_12 ( & V_2 -> V_6 , & V_4 ) ;
if ( ! V_5 )
V_5 = V_2 ;
F_7 ( & V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
if ( V_5 == V_2 ) {
if ( F_4 ( & V_5 -> V_6 , & V_4 ) )
V_5 = F_5 ( & V_4 ,
struct V_1 ,
V_6 ) ;
else
V_5 = F_6 ( V_5 , V_6 ) ;
}
F_14 ( & V_2 -> V_6 ) ;
if ( F_3 ( & V_4 ) )
V_5 = NULL ;
F_15 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
F_16 ( & V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
unsigned char * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
int V_19 = 0 ;
struct V_20 * V_21 = F_18 ( V_8 ) ;
V_17 = (struct V_16 * ) V_13 ;
V_15 = (struct V_14 * ) ( V_22 ) F_19 (
V_17 -> V_23 [ 1 ] ) ;
V_18 =
F_20 ( * ( V_24 * ) ( ( unsigned char * ) & V_17 -> V_23 [ 0 ] + 4 ) ) ;
if ( V_18 ) {
if ( F_21 ( V_18 ) ||
F_22 ( V_18 ) )
V_19 = - V_25 ;
F_11 ( & V_21 -> V_26 . error ) ;
}
if ( V_15 ) {
V_19 = F_23 ( V_15 , V_13 , V_19 ) ;
} else {
F_24 ( L_1 ) ;
return - V_27 ;
}
return 0 ;
}
int F_25 ( struct V_28 * V_29 )
{
return F_26 ( V_29 -> V_8 , V_29 ) ;
}
static void * F_27 ( const struct V_30 * V_31 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_9 ) ;
if ( ! V_2 ) {
V_2 = F_28 ( - V_32 ) ;
goto V_33;
}
if ( ! ( V_31 -> V_34 & V_35 ) ) {
V_2 = F_28 ( - V_32 ) ;
goto V_33;
}
V_2 -> V_36 = * V_31 ;
V_33:
return V_2 ;
}
int F_29 ( void * V_37 , const T_2 * V_38 ,
const struct V_39 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
struct V_7 * V_8 = V_2 -> V_8 ;
const struct V_16 * V_41 = (struct V_16 * ) V_38 ;
if ( V_41 -> V_42 != V_43 ) {
F_24 ( L_2 ) ;
return 0 ;
}
if ( ! V_40 )
V_44 [ V_41 -> V_42 ] ( V_8 , ( unsigned char * ) & V_38 [ 1 ] ) ;
else
V_44 [ V_41 -> V_42 ] ( V_8 , V_40 -> V_45 ) ;
return 0 ;
}
static int F_30 ( void * V_37 , enum V_46 V_47 )
{
struct V_1 * V_2 = V_37 ;
int V_48 = 0 ;
switch ( V_47 ) {
case V_49 :
if ( ! V_2 -> V_8 ) {
V_48 = F_8 ( V_2 ) ;
if ( V_48 != 0 )
return V_48 ;
}
if ( F_31 ( & V_12 ) == 1 )
V_48 = F_32 () ;
break;
case V_50 :
if ( V_2 -> V_8 ) {
F_2 ( & V_3 ) ;
F_13 ( V_2 ) ;
F_7 ( & V_3 ) ;
}
if ( ! F_31 ( & V_12 ) )
F_33 () ;
break;
case V_51 :
case V_52 :
default:
break;
}
return V_48 ;
}
static int T_3 F_34 ( void )
{
if ( F_35 ( V_53 , & V_54 ) )
F_24 ( L_3 ) ;
return 0 ;
}
static void T_4 F_36 ( void )
{
struct V_1 * V_2 , * V_55 ;
if ( F_31 ( & V_12 ) )
F_33 () ;
F_2 ( & V_3 ) ;
F_37 (u_ctx, tmp, &uld_ctx_list, entry) {
if ( V_2 -> V_8 )
F_13 ( V_2 ) ;
F_15 ( V_2 ) ;
}
F_7 ( & V_3 ) ;
F_38 ( V_53 ) ;
}
