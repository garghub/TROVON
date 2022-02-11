static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( F_2 ( ! V_1 ) )
goto error;
if ( F_2 ( F_3 ( V_3 ) ) )
goto error;
V_3 = F_4 ( V_3 , V_4 ) ;
if ( F_2 ( ! V_3 ) )
return;
F_5 ( V_3 , V_5 ) ;
F_6 ( V_3 , V_3 -> V_6 , V_5 ) ;
F_7 ( V_1 , V_3 , NULL ) ;
return;
error:
F_8 ( V_3 ) ;
}
static T_1 F_9 ( struct V_2 * * V_7 )
{
struct V_2 * V_3 = * V_7 ;
struct V_1 * V_1 ;
if ( F_2 ( V_3 -> V_8 == V_9 ) )
return V_10 ;
V_1 = F_10 ( V_3 -> V_11 ) ;
F_1 ( V_1 , V_3 ) ;
return V_12 ;
}
static struct V_13 * F_11 ( const struct V_14 * V_15 )
{
struct V_1 * V_16 ;
V_16 = F_12 ( V_15 , V_17 ) ;
F_13 ( ! V_16 ) ;
return F_14 ( V_16 ) -> V_11 ;
}
static struct V_1 * F_15 ( const struct V_18 * V_19 )
{
struct V_1 * V_1 ;
struct V_20 * V_20 ;
int V_21 ;
V_1 = F_16 ( sizeof( struct V_20 ) ,
& V_22 , V_19 ) ;
if ( F_17 ( V_1 ) ) {
V_21 = F_18 ( V_1 ) ;
goto error;
}
V_20 = F_14 ( V_1 ) ;
V_20 -> V_11 = F_19 ( F_20 ( V_1 -> V_15 ) , V_19 -> V_23 ) ;
if ( ! V_20 -> V_11 ) {
V_21 = - V_24 ;
goto V_25;
}
if ( V_20 -> V_11 -> V_26 & V_27 ||
V_20 -> V_11 -> type != V_28 ||
F_21 ( V_20 -> V_11 ) ) {
V_21 = - V_29 ;
goto V_30;
}
F_22 () ;
V_21 = F_23 ( V_20 -> V_11 ,
F_11 ( V_1 -> V_15 ) ) ;
if ( V_21 )
goto V_31;
V_21 = F_24 ( V_20 -> V_11 , F_9 ,
V_1 ) ;
if ( V_21 )
goto V_32;
F_25 ( V_20 -> V_11 , 1 ) ;
V_20 -> V_11 -> V_33 |= V_34 ;
F_26 () ;
return V_1 ;
V_32:
F_27 ( V_20 -> V_11 , F_11 ( V_1 -> V_15 ) ) ;
V_31:
F_26 () ;
V_30:
F_28 ( V_20 -> V_11 ) ;
V_25:
F_29 ( V_1 ) ;
error:
return F_30 ( V_21 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_20 * V_20 = F_32 ( V_36 ,
struct V_20 , V_36 ) ;
F_28 ( V_20 -> V_11 ) ;
F_29 ( F_33 ( V_20 ) ) ;
}
void F_34 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = F_14 ( V_1 ) ;
F_35 () ;
V_20 -> V_11 -> V_33 &= ~ V_34 ;
F_36 ( V_20 -> V_11 ) ;
F_27 ( V_20 -> V_11 ,
F_37 ( V_20 -> V_11 ) ) ;
F_25 ( V_20 -> V_11 , - 1 ) ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = F_14 ( V_1 ) ;
F_22 () ;
if ( V_20 -> V_11 -> V_33 & V_34 )
F_34 ( V_1 ) ;
F_26 () ;
F_39 ( & V_20 -> V_36 , F_31 ) ;
}
const char * F_40 ( const struct V_1 * V_1 )
{
const struct V_20 * V_20 = F_14 ( V_1 ) ;
return V_20 -> V_11 -> V_23 ;
}
static unsigned int F_41 ( const struct V_2 * V_3 )
{
unsigned int V_37 = V_3 -> V_38 - V_5 ;
if ( V_3 -> V_39 == F_42 ( V_40 ) )
V_37 -= V_41 ;
return V_37 ;
}
static int F_43 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_20 * V_20 = F_14 ( V_1 ) ;
int V_42 = V_20 -> V_11 -> V_42 ;
int V_38 ;
if ( F_2 ( F_41 ( V_3 ) > V_42 && ! F_44 ( V_3 ) ) ) {
F_45 ( L_1 ,
V_20 -> V_11 -> V_23 ,
F_41 ( V_3 ) , V_42 ) ;
goto V_43;
}
V_3 -> V_11 = V_20 -> V_11 ;
V_38 = V_3 -> V_38 ;
F_46 ( V_3 ) ;
return V_38 ;
V_43:
F_8 ( V_3 ) ;
return 0 ;
}
struct V_1 * F_10 ( struct V_13 * V_11 )
{
if ( F_47 ( V_11 -> V_33 & V_34 ) )
return (struct V_1 * )
F_48 ( V_11 -> V_44 ) ;
else
return NULL ;
}
int T_2 F_49 ( void )
{
return F_50 ( & V_22 ) ;
}
void F_51 ( void )
{
F_52 ( & V_22 ) ;
}
