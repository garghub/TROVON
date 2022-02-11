static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( F_3 ( ! V_3 ) )
goto error;
if ( F_3 ( F_4 ( V_2 ) ) )
goto error;
V_2 = F_5 ( V_2 , V_5 ) ;
if ( F_3 ( ! V_2 ) )
return;
if ( V_2 -> V_4 -> type == V_6 ) {
F_6 ( V_2 , V_7 ) ;
F_7 ( V_2 , V_2 -> V_8 , V_7 ) ;
}
F_8 ( V_3 , V_2 , F_9 ( V_2 ) ) ;
return;
error:
F_10 ( V_2 ) ;
}
static T_1 F_11 ( struct V_1 * * V_9 )
{
struct V_1 * V_2 = * V_9 ;
if ( F_3 ( V_2 -> V_10 == V_11 ) )
return V_12 ;
F_1 ( V_2 ) ;
return V_13 ;
}
static struct V_14 * F_12 ( const struct V_15 * V_16 )
{
struct V_3 * V_17 ;
V_17 = F_13 ( V_16 , V_18 ) ;
F_14 ( ! V_17 ) ;
return V_17 -> V_4 ;
}
struct V_3 * F_15 ( struct V_3 * V_3 , const char * V_19 )
{
int V_20 ;
V_3 -> V_4 = F_16 ( F_17 ( V_3 -> V_16 ) , V_19 ) ;
if ( ! V_3 -> V_4 ) {
V_20 = - V_21 ;
goto V_22;
}
if ( V_3 -> V_4 -> V_23 & V_24 ||
( V_3 -> V_4 -> type != V_6 &&
V_3 -> V_4 -> type != V_25 ) ||
F_18 ( V_3 -> V_4 ) ) {
V_20 = - V_26 ;
goto V_27;
}
F_19 () ;
V_20 = F_20 ( V_3 -> V_4 ,
F_12 ( V_3 -> V_16 ) , NULL , NULL ) ;
if ( V_20 )
goto V_28;
V_20 = F_21 ( V_3 -> V_4 , F_11 ,
V_3 ) ;
if ( V_20 )
goto V_29;
F_22 ( V_3 -> V_4 ) ;
F_23 ( V_3 -> V_4 , 1 ) ;
V_3 -> V_4 -> V_30 |= V_31 ;
F_24 () ;
return V_3 ;
V_29:
F_25 ( V_3 -> V_4 , F_12 ( V_3 -> V_16 ) ) ;
V_28:
F_24 () ;
V_27:
F_26 ( V_3 -> V_4 ) ;
V_22:
F_27 ( V_3 ) ;
return F_28 ( V_20 ) ;
}
static struct V_3 * F_29 ( const struct V_32 * V_33 )
{
struct V_3 * V_3 ;
V_3 = F_30 ( 0 , & V_34 , V_33 ) ;
if ( F_31 ( V_3 ) )
return V_3 ;
return F_15 ( V_3 , V_33 -> V_19 ) ;
}
static void F_32 ( struct V_35 * V_36 )
{
struct V_3 * V_3 = F_33 ( V_36 , struct V_3 , V_36 ) ;
if ( V_3 -> V_4 )
F_26 ( V_3 -> V_4 ) ;
F_27 ( V_3 ) ;
}
void F_34 ( struct V_3 * V_3 )
{
F_35 () ;
V_3 -> V_4 -> V_30 &= ~ V_31 ;
F_36 ( V_3 -> V_4 ) ;
F_25 ( V_3 -> V_4 ,
F_37 ( V_3 -> V_4 ) ) ;
F_23 ( V_3 -> V_4 , - 1 ) ;
}
static void F_38 ( struct V_3 * V_3 )
{
F_19 () ;
if ( V_3 -> V_4 -> V_30 & V_31 )
F_34 ( V_3 ) ;
F_24 () ;
F_39 ( & V_3 -> V_36 , F_32 ) ;
}
void F_40 ( struct V_3 * V_3 )
{
F_19 () ;
if ( V_3 -> V_4 -> V_30 & V_31 )
F_34 ( V_3 ) ;
if ( V_3 -> V_4 -> V_37 == V_38 )
F_41 ( V_3 -> V_4 ) ;
F_26 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
F_24 () ;
F_39 ( & V_3 -> V_36 , F_32 ) ;
}
struct V_3 * F_2 ( struct V_14 * V_4 )
{
if ( F_42 ( V_4 -> V_30 & V_31 ) )
return (struct V_3 * )
F_43 ( V_4 -> V_39 ) ;
else
return NULL ;
}
int T_2 F_44 ( void )
{
return F_45 ( & V_34 ) ;
}
void F_46 ( void )
{
F_47 ( & V_34 ) ;
}
