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
F_6 ( V_2 , V_6 ) ;
F_7 ( V_2 , V_2 -> V_7 , V_6 ) ;
F_8 ( V_3 , V_2 , F_9 ( V_2 ) ) ;
return;
error:
F_10 ( V_2 ) ;
}
static T_1 F_11 ( struct V_1 * * V_8 )
{
struct V_1 * V_2 = * V_8 ;
if ( F_3 ( V_2 -> V_9 == V_10 ) )
return V_11 ;
F_1 ( V_2 ) ;
return V_12 ;
}
static struct V_13 * F_12 ( const struct V_14 * V_15 )
{
struct V_3 * V_16 ;
V_16 = F_13 ( V_15 , V_17 ) ;
F_14 ( ! V_16 ) ;
return V_16 -> V_4 ;
}
struct V_3 * F_15 ( struct V_3 * V_3 , const char * V_18 )
{
int V_19 ;
V_3 -> V_4 = F_16 ( F_17 ( V_3 -> V_15 ) , V_18 ) ;
if ( ! V_3 -> V_4 ) {
V_19 = - V_20 ;
goto V_21;
}
if ( V_3 -> V_4 -> V_22 & V_23 ||
V_3 -> V_4 -> type != V_24 ||
F_18 ( V_3 -> V_4 ) ) {
V_19 = - V_25 ;
goto V_26;
}
F_19 () ;
V_19 = F_20 ( V_3 -> V_4 ,
F_12 ( V_3 -> V_15 ) , NULL , NULL ) ;
if ( V_19 )
goto V_27;
V_19 = F_21 ( V_3 -> V_4 , F_11 ,
V_3 ) ;
if ( V_19 )
goto V_28;
F_22 ( V_3 -> V_4 ) ;
F_23 ( V_3 -> V_4 , 1 ) ;
V_3 -> V_4 -> V_29 |= V_30 ;
F_24 () ;
return V_3 ;
V_28:
F_25 ( V_3 -> V_4 , F_12 ( V_3 -> V_15 ) ) ;
V_27:
F_24 () ;
V_26:
F_26 ( V_3 -> V_4 ) ;
V_21:
F_27 ( V_3 ) ;
return F_28 ( V_19 ) ;
}
static struct V_3 * F_29 ( const struct V_31 * V_32 )
{
struct V_3 * V_3 ;
V_3 = F_30 ( 0 , & V_33 , V_32 ) ;
if ( F_31 ( V_3 ) )
return V_3 ;
return F_15 ( V_3 , V_32 -> V_18 ) ;
}
static void F_32 ( struct V_34 * V_35 )
{
struct V_3 * V_3 = F_33 ( V_35 , struct V_3 , V_35 ) ;
if ( V_3 -> V_4 )
F_26 ( V_3 -> V_4 ) ;
F_27 ( V_3 ) ;
}
void F_34 ( struct V_3 * V_3 )
{
F_35 () ;
V_3 -> V_4 -> V_29 &= ~ V_30 ;
F_36 ( V_3 -> V_4 ) ;
F_25 ( V_3 -> V_4 ,
F_37 ( V_3 -> V_4 ) ) ;
F_23 ( V_3 -> V_4 , - 1 ) ;
}
static void F_38 ( struct V_3 * V_3 )
{
F_19 () ;
if ( V_3 -> V_4 -> V_29 & V_30 )
F_34 ( V_3 ) ;
F_24 () ;
F_39 ( & V_3 -> V_35 , F_32 ) ;
}
void F_40 ( struct V_3 * V_3 )
{
F_19 () ;
if ( V_3 -> V_4 -> V_29 & V_30 )
F_34 ( V_3 ) ;
if ( V_3 -> V_4 -> V_36 == V_37 )
F_41 ( V_3 -> V_4 ) ;
F_26 ( V_3 -> V_4 ) ;
V_3 -> V_4 = NULL ;
F_24 () ;
F_39 ( & V_3 -> V_35 , F_32 ) ;
}
struct V_3 * F_2 ( struct V_13 * V_4 )
{
if ( F_42 ( V_4 -> V_29 & V_30 ) )
return (struct V_3 * )
F_43 ( V_4 -> V_38 ) ;
else
return NULL ;
}
int T_2 F_44 ( void )
{
return F_45 ( & V_33 ) ;
}
void F_46 ( void )
{
F_47 ( & V_33 ) ;
}
