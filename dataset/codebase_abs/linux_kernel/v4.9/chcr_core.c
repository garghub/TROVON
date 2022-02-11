int F_1 ( struct V_1 * * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( & V_6 , struct V_3 , V_7 ) ;
if ( ! V_4 ) {
F_4 ( & V_5 ) ;
return - V_8 ;
}
* V_2 = V_4 -> V_2 ;
F_4 ( & V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_9 ) ;
if ( ! V_2 )
return - V_8 ;
F_7 ( & V_2 -> V_10 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
F_8 ( & V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
F_11 ( & V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned char * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_1 V_17 = 0 ;
int V_18 = 0 ;
V_16 = (struct V_15 * ) V_12 ;
V_14 = (struct V_13 * ) ( V_19 ) F_13 (
V_16 -> V_20 [ 1 ] ) ;
V_17 =
F_14 ( * ( V_21 * ) ( ( unsigned char * ) & V_16 -> V_20 [ 0 ] + 4 ) ) ;
if ( V_17 ) {
if ( F_15 ( V_17 ) ||
F_16 ( V_17 ) )
V_18 = - V_22 ;
}
if ( V_14 ) {
if ( ! F_17 ( V_14 , V_12 , V_18 ) )
V_14 -> V_23 ( V_14 , V_18 ) ;
else
return - V_22 ;
} else {
F_18 ( L_1 ) ;
return - V_24 ;
}
return 0 ;
}
int F_19 ( struct V_25 * V_26 )
{
return F_20 ( V_26 -> V_2 , V_26 ) ;
}
static void * F_21 ( const struct V_27 * V_28 )
{
struct V_3 * V_4 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 ) {
V_4 = F_22 ( - V_29 ) ;
goto V_30;
}
V_4 -> V_31 = * V_28 ;
F_2 ( & V_5 ) ;
F_23 ( & V_4 -> V_7 , & V_6 ) ;
F_4 ( & V_5 ) ;
V_30:
return V_4 ;
}
int F_24 ( void * V_32 , const T_2 * V_33 ,
const struct V_34 * V_35 )
{
struct V_3 * V_4 = (struct V_3 * ) V_32 ;
struct V_1 * V_2 = V_4 -> V_2 ;
const struct V_36 * V_37 = (struct V_36
* ) V_33 ;
if ( V_37 -> V_38 . V_39 != V_40 ) {
F_18 ( L_2 ) ;
return 0 ;
}
if ( ! V_35 )
V_41 [ V_37 -> V_38 . V_39 ] ( V_2 , ( unsigned char * ) & V_33 [ 1 ] ) ;
else
V_41 [ V_37 -> V_38 . V_39 ] ( V_2 , V_35 -> V_42 ) ;
return 0 ;
}
static int F_25 ( void * V_32 , enum V_43 V_44 )
{
struct V_3 * V_4 = V_32 ;
int V_45 = 0 ;
switch ( V_44 ) {
case V_46 :
if ( ! V_4 -> V_2 ) {
V_45 = F_5 ( V_4 ) ;
if ( V_45 != 0 )
return V_45 ;
}
if ( F_26 ( & V_11 ) == 1 )
V_45 = F_27 () ;
break;
case V_47 :
if ( V_4 -> V_2 ) {
F_2 ( & V_5 ) ;
F_9 ( V_4 ) ;
F_4 ( & V_5 ) ;
}
if ( ! F_26 ( & V_11 ) )
F_28 () ;
break;
case V_48 :
case V_49 :
default:
break;
}
return V_45 ;
}
static int T_3 F_29 ( void )
{
if ( F_30 ( V_50 , & V_51 ) ) {
F_18 ( L_3 ) ;
return - 1 ;
}
return 0 ;
}
static void T_4 F_31 ( void )
{
struct V_3 * V_4 , * V_52 ;
if ( F_26 ( & V_11 ) )
F_28 () ;
F_2 ( & V_5 ) ;
F_32 (u_ctx, tmp, &uld_ctx_list, entry) {
if ( V_4 -> V_2 )
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
}
F_4 ( & V_5 ) ;
F_33 ( V_50 ) ;
}
