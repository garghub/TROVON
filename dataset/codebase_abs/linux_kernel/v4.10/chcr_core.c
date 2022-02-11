int F_1 ( struct V_1 * * V_2 )
{
struct V_3 * V_4 ;
int V_5 = - V_6 ;
F_2 ( & V_7 ) ;
F_3 (u_ctx, &uld_ctx_list, entry)
if ( V_4 && V_4 -> V_2 ) {
* V_2 = V_4 -> V_2 ;
V_5 = 0 ;
break;
}
F_4 ( & V_7 ) ;
return V_5 ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return - V_6 ;
F_7 ( & V_2 -> V_9 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_4 = V_4 ;
F_8 ( & V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
F_11 ( & V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned char * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
T_1 V_16 = 0 ;
int V_17 = 0 ;
V_15 = (struct V_14 * ) V_11 ;
V_13 = (struct V_12 * ) ( V_18 ) F_13 (
V_15 -> V_19 [ 1 ] ) ;
V_16 =
F_14 ( * ( V_20 * ) ( ( unsigned char * ) & V_15 -> V_19 [ 0 ] + 4 ) ) ;
if ( V_16 ) {
if ( F_15 ( V_16 ) ||
F_16 ( V_16 ) )
V_17 = - V_21 ;
}
if ( V_13 ) {
V_17 = F_17 ( V_13 , V_11 , V_17 ) ;
V_13 -> V_22 ( V_13 , V_17 ) ;
} else {
F_18 ( L_1 ) ;
return - V_23 ;
}
return 0 ;
}
int F_19 ( struct V_24 * V_25 )
{
return F_20 ( V_25 -> V_2 , V_25 ) ;
}
static void * F_21 ( const struct V_26 * V_27 )
{
struct V_3 * V_4 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_8 ) ;
if ( ! V_4 ) {
V_4 = F_22 ( - V_28 ) ;
goto V_29;
}
V_4 -> V_30 = * V_27 ;
F_2 ( & V_7 ) ;
F_23 ( & V_4 -> V_31 , & V_32 ) ;
F_4 ( & V_7 ) ;
V_29:
return V_4 ;
}
int F_24 ( void * V_33 , const T_2 * V_34 ,
const struct V_35 * V_36 )
{
struct V_3 * V_4 = (struct V_3 * ) V_33 ;
struct V_1 * V_2 = V_4 -> V_2 ;
const struct V_37 * V_38 = (struct V_37
* ) V_34 ;
if ( V_38 -> V_39 . V_40 != V_41 ) {
F_18 ( L_2 ) ;
return 0 ;
}
if ( ! V_36 )
V_42 [ V_38 -> V_39 . V_40 ] ( V_2 , ( unsigned char * ) & V_34 [ 1 ] ) ;
else
V_42 [ V_38 -> V_39 . V_40 ] ( V_2 , V_36 -> V_43 ) ;
return 0 ;
}
static int F_25 ( void * V_33 , enum V_44 V_45 )
{
struct V_3 * V_4 = V_33 ;
int V_5 = 0 ;
switch ( V_45 ) {
case V_46 :
if ( ! V_4 -> V_2 ) {
V_5 = F_5 ( V_4 ) ;
if ( V_5 != 0 )
return V_5 ;
}
if ( F_26 ( & V_10 ) == 1 )
V_5 = F_27 () ;
break;
case V_47 :
if ( V_4 -> V_2 ) {
F_2 ( & V_7 ) ;
F_9 ( V_4 ) ;
F_4 ( & V_7 ) ;
}
if ( ! F_26 ( & V_10 ) )
F_28 () ;
break;
case V_48 :
case V_49 :
default:
break;
}
return V_5 ;
}
static int T_3 F_29 ( void )
{
if ( F_30 ( V_50 , & V_51 ) )
F_18 ( L_3 ) ;
return 0 ;
}
static void T_4 F_31 ( void )
{
struct V_3 * V_4 , * V_52 ;
if ( F_26 ( & V_10 ) )
F_28 () ;
F_2 ( & V_7 ) ;
F_32 (u_ctx, tmp, &uld_ctx_list, entry) {
if ( V_4 -> V_2 )
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
}
F_4 ( & V_7 ) ;
F_33 ( V_50 ) ;
}
